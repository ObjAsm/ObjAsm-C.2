; ==================================================================================================
; Title:      h2inc+_RenderTypedef.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderTypedef
; Purpose:    Typedef analysis and translation.
;             "typedef" occured in the header and triggered this proc.
; Arguments:  xbx -> IncFile.
; Return:     xax -> Last token or NULL if failed.
; Syntax:
;   typedef <annotations><qualifiers> type <<far|near> *> newname<[]>;
;   typedef struct/union <macro> <tname> {} name;
;   typedef struct/union <macro> <tname> * name;
;   typedef <annotations><qualifiers> enum <tname> {<annotations>x<=a>,<annotations>y<=b>,...} name;
;   typedef <annotations><qualifiers> returntype (<qualifiers> *name)(<parameters>);
;   typedef <annotations><qualifiers> returntype name(<parameters>);

RenderTypedef proc
  local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA, pDup:PSTRINGA
  local dSquareBracketCount:DWORD, dPtrCount:DWORD, bValid:DWORD, dTypeCSpec:DWORD
  local cBuffer[256]:CHRA, cTransBuffer[128]:CHRA
  local pCurrToken:PTOKEN, dSize:DWORD, p1:POINTER, p2:POINTER
  local InpStat:INP_STAT, PrevOutStat:STMOUT_STAT

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderTypedef")
  mov pType, NULL

@GetNextToken:
  OCall xbx::IncFile.GetNextTokenC

@ProcessToken:
  .if xax != NULL
    invoke SkipAnnotations, xax
    .if xax != NULL
      invoke TranslateToken, xax
      .if edx == FALSE
        invoke TranslateTypeQualifier, xax
        cmp CHRA ptr [xax], 0
        jz @GetNextToken
      .endif
    .endif
  .endif
  mov pToken, xax
  test xax, xax
  jz @ErrorEoF

  cmp CHRA ptr [xax], ';'                               ;Statement terminator?
  jz @ErrorSyntax                                       ; Yes => error

  .if CHRA ptr [xax] == '['
    OCall xbx::IncFile.InputStatusSave, addr InpStat
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL
      .if $DoesStringMatchA?([xax], <public>)
        OCall xbx::IncFile.GetNextTokenC
        .if xax != NULL && CHRA ptr [xax] == ']'
          jmp @GetNextToken                             ;Sure????
        .endif
      .endif
    .endif
    OCall xbx::IncFile.InputStatusLoad, addr InpStat
  .endif

  ;syntax: "typedef <macro()> xxx"
  invoke IsMacro?, pToken                               ;Check if it is an already known macro
  .if eax != 0                                          ;0, 1, ...
    mov edx, ecx
    .if eax == 1
      OCall pNewMacros::List.ItemAt, edx
    .else
      OCall pKnwMacros::List.ItemAt, edx
    .endif
    mov edx, [xax - sizeof(DWORD)]                      ;Get offset to Macro-Attr
    invoke RenderMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
    test eax, eax                                       ;FALSE if it was not a macro
    jnz @GetNextToken
  .endif

  ;Syntax: "typedef union|struct"?
  mov xax, pToken
  .if !$DoesStringMatchA?([xax], <struct>)
    DoesStringMatchA? [xax], <union>
    jnz @F
  .endif
  invoke IsFunctionPtr?, xax                            ;Check if it is a function definition
  .if eax == FALSE                                      ; specifying a struct as return type
    StmOutSave PrevOutStat                              ;Save output stream status
    invoke RenderContainer, pToken, FALSE
    .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONTAINERS
      StmOutLoad PrevOutStat                            ;Restore initial output stream status
      mov CHRA ptr [xax], 0
    .endif
  .else
    StmOutSave PrevOutStat                              ;Save output stream status
    invoke RenderTypedefFuncPtr, NULL
    .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_TYPEDEFS
      StmOutLoad PrevOutStat                            ;Restore initial output stream status
      mov CHRA ptr [xax], 0
    .endif
  .endif
  test xax, xax
  jz @ErrorEoF
  jmp @Exit

@@:
  ;Syntax: "typedef enum"?
  .if !$DoesStringMatchA?([xax], <enum>)
    DoesStringMatchA? [xax], <ENUM>
    jnz @F
  .endif
  StmOutSave PrevOutStat                                ;Save output stream status
  invoke RenderTypedefEnum, TRUE
  .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
    StmOutLoad PrevOutStat                              ;Restore initial output stream status
    mov CHRA ptr [xax], 0
  .endif
  jmp @Exit

@@:
  .if pType == NULL
    ;pToken may be a basic C type
    mov xax, pToken
    BasicTypeCScan                                      ;Set dTypeCSpec
    mov pToken, xax                                     ;Last gattered Token
    .if dTypeCSpec != 0
      invoke ConvBasicTypeC, dTypeCSpec
      .if xax == NULL                                   ;If conversion failed
        lea xax, szUnkType
      .endif
      mov pType, xax
      mov xax, pToken
      test xax, xax
      jmp @ProcessToken                                 ;Process the last gattered Token in eax
    .endif
    lea xdx, cBuffer
    mov pType, $invoke(TranslateReservedWord, xax, xdx)
    jmp @GetNextToken
  .endif

  ;Get the new Name and write all to the output stream
  mov xax, pToken
  mov dSquareBracketCount, 0
  mov dPtrCount, 0
  mov pName, NULL
  mov pDup, NULL
  .while TRUE
    .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == ';'
      .if pName != NULL
        mov bValid, TRUE

        ;Don't add "<newname> typedef <oldname>" entries if <newname> == <oldname>
        .if dPtrCount == 0
          invoke StrCompA, pName, pType
          .if eax == 0
            mov bValid, FALSE
          .endif
        .endif
        .if bValid != FALSE
          mov pCurrToken, $invoke(TranslateReservedWord, pName, addr cTransBuffer)
          mov pName, xax                                ;Assign translated name
        .endif

        .if bValid != FALSE
          .if dPtrCount == 0
            IsStructure? pType                          ;If the type is a structure,
            .if eax != FALSE                            ;  then the new type is it too
              IsStructure? pName                        ;Check if it already exist
              .if eax == FALSE
                invoke StrLengthA, pName
                invoke InsertStrg, pNewStructs, pName, eax
              .endif
            .endif
          .endif

          ;If there is an array index, create a 'struct' instead of a 'typedef'!
          .if pDup != NULL && dPtrCount == 0
            OCall xbx::IncFile.StmWrite, pName
            OCall xbx::IncFile.StmWrite, $OfsCStrA(" struct")
            OCall xbx::IncFile.StmWriteEoL
            inc [xbx].$Obj(IncFile).dIndentation
            OCall xbx::IncFile.StmWrite, pType
            OCall xbx::IncFile.StmWriteChar, SPC
            OCall xbx::IncFile.StmWrite, pDup
            IsStructure? pType                          ;Check if pType is already a known struct
            .if eax == FALSE
              OCall xbx::IncFile.StmWrite, $OfsCStrA(" dup (?)")
            .else
              OCall xbx::IncFile.StmWrite, $OfsCStrA(" dup (<>)")
            .endif
            OCall xbx::IncFile.StmWriteEoL
            dec [xbx].$Obj(IncFile).dIndentation
            OCall xbx::IncFile.StmWrite, pName
            OCall xbx::IncFile.StmWrite, $OfsCStrA(" ends")
            OCall xbx::IncFile.StmWriteEoL

          .else
            OCall xbx::IncFile.StmWrite, pName
            OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ")
            WritePtr
            mov xax, pType
            .if CHRA ptr [xax] == 0
              OCall xbx::IncFile.StmDeleteLastSpace
            .else
              OCall xbx::IncFile.StmWrite, pType
            .endif
            OCall xbx::IncFile.StmWriteEoL

            invoke StrLengthA, pName
            invoke InsertStrg, pNewTypedefs, pName, eax
          .endif
        .endif
      .endif

      mov dPtrCount, 0
      mov pName, NULL
      mov xax, pToken
      .break .if CHRA ptr [xax] == ';'                  ;Statement terminator? => exit
    .endif

    .if CHRA ptr [xax] == '('
      invoke IsFunctionPtr?, xax
      .if eax != FALSE
        invoke RenderTypedefFuncPtr, NULL
        test xax, xax
        jz @ErrorEoF
      .else
        invoke IsFunction?
        .if eax != FALSE
          mov xax, pName
          test xax, xax
          cmovz xax, pType
          invoke RenderTypedefFunction, xax             ;No return value
        .endif
      .endif
      mov pName, NULL
      test xax, xax
      jnz @Exit

    .elseif CHRA ptr [xax] == "*" && dSquareBracketCount == 0
      inc dPtrCount

    .elseif CHRA ptr [xax] == '['
      inc dSquareBracketCount

    .elseif CHRA ptr [xax] == ']'
      dec dSquareBracketCount

    .else
      .if dSquareBracketCount != 0
        .if pDup != 0
          mov pCurrToken, xax
          invoke StrSizeA, xax
          mov dSize, eax
          invoke StrSizeA, pDup
          add eax, dSize                                ;length1 + length2 + 2
          MemAlloc eax
          mov p1, xbx
          mov xbx, xax
          invoke StrECopyA, xbx, pDup
          mov p2, xax
          MemFree pDup
          mov pDup, xbx
          mov xcx, p2
          mov CHRA ptr [xcx], '*'
          inc xcx
          invoke StrCopyA, xcx, pCurrToken
          mov xbx, p1
          mov xax, pCurrToken
        .else
          invoke StrNewA, xax
          mov pDup, xax
        .endif
      .else
        mov pToken, xax
        IsValidName? xax
        .if eax != FALSE
          mov xax, pToken
          mov pName, xax
        .endif
      .endif
    .endif

    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    invoke SkipAnnotations, xax
    test xax, xax
    jz @ErrorEoF                                        ;No more tokens? => error
    mov pToken, xax
  .endw

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov xax, pToken
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderTypedef")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderTypedef endp
