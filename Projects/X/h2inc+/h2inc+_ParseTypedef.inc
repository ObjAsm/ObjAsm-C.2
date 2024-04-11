; ==================================================================================================
; Title:      h2inc+_ParseTypedef.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseTypedef
; Purpose:    Typedef analysis and translation. 
;             "typedef" occured in the header and triggered this proc.
; Arguments:  xbx -> IncFile.
;             xsi -> Tokens following the "typedef"
; Return:     Nothing.
; Syntax:     typedef <annotations><qualifiers> type <<far|near> *> newname<[]>;
;             typedef struct/union <macro> <tname> {} name;
;             typedef struct/union <macro> <tname> * name;
;             typedef <annotations><qualifiers> enum <tname> {<annotations>x<=a>,<annotations>y<=b>,...} name;
;             typedef <annotations><qualifiers> returntype (<qualifiers> *name)(<parameters>);
;             typedef <annotations><qualifiers> returntype name(<parameters>);

ParseTypedef proc
  local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA, pDup:PSTRINGA
  local dSquareBracketCount:DWORD, dPtrCount:DWORD, bValid:DWORD, dTypeCSpec:DWORD
  local szTmpType[256]:CHRA, szBuffer[256]:CHRA, cTransBuffer[128]:CHRA
  local InpStat:INP_STAT, pCurrToken:PTOKEN, dSize:DWORD, p1:POINTER, p2:POINTER

  DbgPrintF , "¦UD: ParseTypedef - begin", [xbx].$Obj(IncFile).dLineNumber
  mov pType, NULL

@GetNextToken:
  OCall xbx::IncFile.GetNextToken
@ProcessToken:
  .if !ZERO?
    invoke SkipAnnotations, xax
    .if !ZERO?
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
  jz @Error

  cmp CHRA ptr [xax], ";"                             ;Statement terminator?
  jz @Error                                           ; Yes => error

  .if CHRA ptr [xax] == "["
    DbgPrintF , "¦UD: ParseTypedef - \´[\´ found", [xbx].$Obj(IncFile).dLineNumber
    OCall xbx::IncFile.SaveInputStatus, addr InpStat
    OCall xbx::IncFile.GetNextToken
    .if !ZERO?
      .if $DoesStringMatchA?([xax], <public>)
        OCall xbx::IncFile.GetNextToken
        .if !ZERO? && CHRA ptr [xax] == "]"
          DbgPrintF , "¦UD: ParseTypedef - \´]\´ found", [xbx].$Obj(IncFile).dLineNumber
          jmp @GetNextToken                                ;Sure????
        .endif
      .endif
    .endif
    OCall xbx::IncFile.LoadInputStatus, addr InpStat
  .endif

  ;syntax: "typedef <macro()> xxx"
  invoke IsMacro?, pToken                             ;Check if it is an already known macro
  .if eax != 0                                        ;0, 1, ...
    DbgPrintF , "¦UD: ParseTypedef - macro invocation ¦SA", [xbx].$Obj(IncFile).dLineNumber, pToken
    mov edx, ecx
    .if eax == 1
      OCall pMacros::List.ItemAt, edx
    .else
      OCall pKnownMacros::List.ItemAt, edx
    .endif
    mov edx, [xax - sizeof DWORD]                       ;Get offset to Macro-Attr
    invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
    test xax, xax                                       ;FALSE if it was not a macro
    jnz @GetNextToken
  .endif

  ;Syntax: "typedef union|struct"?
  invoke IsUnionStructClass?, pToken
  .if eax != 0
    DbgPrintF , "¦UD: ParseTypedef - ¦SA found", [xbx].$Obj(IncFile).dLineNumber, pToken
    invoke ParseTypedefContainer, pToken, edx
    xor eax, eax
    jmp @Exit
  .endif

  ;Syntax: "typedef enum"?
  mov xax, pToken
  .if $DoesStringMatchA?([xax], <enum>)
    DbgPrintF , "¦UD: ParseTypedef - \´enum\´ found", [xbx].$Obj(IncFile).dLineNumber
    invoke ParseTypedefEnum, TRUE
    xor eax, eax
    jmp @Exit
  .endif

  .if pType == NULL
    ;pToken may be a basic C type
    mov xax, pToken
    BasicTypeCScan
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
    .else
      lea xdx, szBuffer
      mov pType, $invoke(TranslateReservedWord, xax, xdx)
      jmp @GetNextToken
    .endif
  .endif

  ;Get the new Name and write all to the output stream
  mov xax, pToken
  mov dSquareBracketCount, 0
  mov dPtrCount, 0
  mov pName, NULL
  mov pDup, NULL
  .while TRUE
    .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ";"
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
          .if edx != 0 && $ObjTmpl(Application).Options.dWarningLevel > 0
            OCall xbx::IncFile.ShowWarning, WARNING_MINOR, $OfsCStrA("reserved word %s used as typedef"), pName
          .endif
          m2m pName, pCurrToken, xdx                    ;Assign translated name
        .endif
        DbgPrintF , "¦UD: ParseTypedef - new typedef ¦SA = ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName, pType

        .if bValid != FALSE
          .if dPtrCount == 0
            IsStructure? pType                          ;If the type is a structure, 
            .if eax != FALSE                            ;  then the new type is it too
              IsStructure? pName                        ;Check if it already exist
              .if eax == FALSE
                invoke StrSizeA, pName
                invoke InsertStrg, pStructs, pName, eax
              .endif
            .endif
          .endif

          ;If there is an array index, create a 'struct' instead of a 'typedef'!
          .if pDup != NULL && dPtrCount == 0
            OCall xbx::IncFile.StmWrite, pName
            OCall xbx::IncFile.StmWrite, $OfsCStrA(" struct")
            OCall xbx::IncFile.StmWriteEOL
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
            OCall xbx::IncFile.StmWriteEOL
            dec [xbx].$Obj(IncFile).dIndentation
            OCall xbx::IncFile.StmWrite, pName
            OCall xbx::IncFile.StmWrite, $OfsCStrA(" ends")
            OCall xbx::IncFile.StmWriteEOL

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
            OCall xbx::IncFile.StmWriteEOL

            invoke StrSizeA, pName
            invoke InsertStrg, pTypedefs, pName, eax
          .endif
        .endif
      .endif

      mov dPtrCount, 0
      mov pName, NULL
      mov xax, pToken
      .break .if CHRA ptr [xax] == ";"                  ;Statement terminator? => exit
    .endif

    .if CHRA ptr [xax] == "("
      invoke IsFunctionPtr?
      .if eax != FALSE
        invoke ParseTypedefFunctionPtr, NULL
      .else
        invoke IsFunction?
        .if eax != FALSE
          mov xax, pName
          test xax, xax
          cmovz xax, pType
          invoke ParseTypedefFunction, xax, FALSE, NULL
        .endif
      .endif
      mov pName, NULL
      test xax, xax
      jnz @Exit

    .elseif CHRA ptr [xax] == "*" && dSquareBracketCount == 0
      inc dPtrCount

    .elseif CHRA ptr [xax] == "["
      DbgPrintF , "¦UD: ParseTypedef - \´[\´ found", [xbx].$Obj(IncFile).dLineNumber
      inc dSquareBracketCount

    .elseif CHRA ptr [xax] == "]"
      DbgPrintF , "¦UD: ParseTypedef - \´]\´ found", [xbx].$Obj(IncFile).dLineNumber
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
          mov CHRA ptr [xcx], "*"
          inc xcx
          invoke StrCopyA, xcx, pCurrToken
          mov xbx, p1
          mov xax, pCurrToken
        .else
          invoke StrNewA, xax
          mov pDup, xax
        .endif
        DbgPrintF , "¦UD: ParseTypedef - array size ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xax
      .else
        mov pToken, xax
        IsName? xax
        .if eax != FALSE
          mov xax, pToken
          mov pName, xax
        .endif
      .endif
    .endif

    OCall xbx::IncFile.GetNextToken
    jz @Error
    invoke SkipAnnotations, xax
    jz @Error                                           ;No more tokens? => error
    mov pToken, xax
  .endw

@Exit:
  ret

@Error:
  .if xax != NULL
    OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected item %s in typedef [¦UD]"), pToken, eax
  .endif
  DbgErrorF , "¦SU(¦UD): ParseTypedef - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
ParseTypedef endp

