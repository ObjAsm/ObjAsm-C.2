; ==================================================================================================
; Title:      h2inc+_RenderContainerMember.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================

;Example 1:
;struct Point{
;  int x;
;  int y;
;};
;
;Example 2:
;typedef struct Point{
;  int x;
;  int y;
;} Point;

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  WriteContainerMember
; Purpose:    Write member to the output stream.
; Arguments:  Arg1: -> Member name.
;             Arg2: -> Member type.
;             Arg3: -> List with collected DUP info.
;             Arg4: Number of indirections.
; Return:     Nothing.

WriteContainerMember proc pName:PTOKEN, pType:PTOKEN, pDupList:POINTER, dPtrCount:DWORD
  local cTransBuffer[128]:CHRA

  .if pName != NULL
    ;Write regular struct/union member --------------------------------------------------
    .if dPtrCount != 0
      c2m pType, $OfsCStrA("POINTER"), xax
    .else
      .if pType == NULL
        IsStructure? pName
        .if eax != FALSE
          xor eax, eax
          xchg xax, pName
          mov pType, xax
        .endif
      .endif
    .endif

    ;Write member name or skip if it is annonymous -------------------------------------
    .if pName != NULL
      invoke TranslateReservedWord, pName, addr cTransBuffer
      OCall xbx::IncFile.StmWrite, xax
    .endif

    ;Write member type and initializer -------------------------------------------------
    .if pType != NULL
      OCall xbx::IncFile.StmWriteChar, SPC
      invoke TranslateReservedWord, pType, addr cTransBuffer
      OCall xbx::IncFile.StmWrite, xax
      .if pDupList != NULL
        OCall xbx::IncFile.StmWriteChar, SPC
        invoke WriteStackList, pDupList
        OCall xbx::IncFile.StmWrite, $OfsCStrA($Esc(" dup \{"))
      .else
        OCall xbx::IncFile.StmWriteChar, SPC
      .endif

      IsStructure? pType
      .if eax != FALSE
        OCall xbx::IncFile.StmWrite, $OfsCStrA("<>")
      .else
        OCall xbx::IncFile.StmWriteChar, "?"
      .endif

      .if pDupList != NULL
        OCall xbx::IncFile.StmWriteChar, ')'
      .endif

      OCall xbx::IncFile.StmWriteEoL

    .endif
    OCall xbx::IncFile.StmWriteComment

  .endif
  ret
WriteContainerMember endp

; --------------------------------------------------------------------------------------------------
; Procedure:  RenderContainerMember
; Purpose:    Get a struct or union declaration of a single member.
; Arguments:  Arg1: -> First token after 'union {' or 'struct {'.
;             Arg2: -> Struct or union name. Can be NULL.
;             xbx -> IncFile.
; Return:     xax -> Last processed token, usually ';' or NULL if failed.
; Link:       https://en.cppreference.com/w/c/language/bit_field

RenderContainerMember proc uses xdi pToken:PTOKEN, pContainerName:PSTRINGA
  local dTypeCSpec:DWORD, dPtrCount:DWORD, InpStat:INP_STAT
  local pType:PSTRINGA, pName:PSTRINGA, pDupList:POINTER, pEndToken:PSTRINGA
  local cSuffix[UDWORD2DEC_MAX_CHARS + 20]:CHRA, dSquareBracketCount:DWORD

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderContainerMember")
  ;Initialize ---------------------------------------------------------------------------
  m2m [xbx].$Obj(IncFile).pContainerName, pContainerName, xcx
  mov pEndToken, NULL
  mov pName, NULL
  mov pType, NULL
  mov pDupList, NULL
  mov dPtrCount, 0

  mov xax, pToken                                       ;Use token passed to this proc
  .while TRUE
    test xax, xax
    jz @ErrorEoF
    invoke SkipAnnotations, xax
    test xax, xax
    jz @ErrorEoF
    .break .if CHRA ptr [xax] == ';'                    ;End of declaration reached
    mov pToken, xax
    .if CHRA ptr [xax] == '}'
      mov pEndToken, xax
      jmp @Exit
    .endif

    .if $DoesStringMatchA?([xax], <struct>)             ;New structure inside this container?
      OCall xbx::IncFile.InputStatusSave, addr InpStat
      inc [xbx].$Obj(IncFile).bSkipLinePP
      OCall xbx::IncFile.GetNextTokenC
      .if xax == NULL
        dec [xbx].$Obj(IncFile).bSkipLinePP
        jmp @ErrorEoF
      .endif
      .if CHRA ptr [xax] == '{'
        dec [xbx].$Obj(IncFile).bSkipLinePP
        OCall xbx::IncFile.InputStatusLoad, addr InpStat
        jmp @StrucName
      .else
        OCall xbx::IncFile.GetNextTokenC
        .if xax == NULL
          dec [xbx].$Obj(IncFile).bSkipLinePP
          jmp @ErrorEoF
        .endif
        .if CHRA ptr [xax] == '{'
          dec [xbx].$Obj(IncFile).bSkipLinePP
          OCall xbx::IncFile.InputStatusLoad, addr InpStat
          OCall xbx::IncFile.GetNextTokenC              ;Consume tagName
          test xax, xax
          jz @ErrorEoF
          jmp @StrucName
        .endif
      .endif
      dec [xbx].$Obj(IncFile).bSkipLinePP
      OCall xbx::IncFile.InputStatusLoad, addr InpStat
      mov xax, pToken
      jmp @GetNextToken

@StrucName:
      ;Name management
      mov xax, pContainerName
      .if xax != NULL                                   ;Unnamed struct or union
        .if !$DoesTextMatchA?([xax], <DUMMYSTRUCTNAME>) ;May have a number at the end
          mov xdi, $OfsCStrA("_STRUC")
          jmp @F
        .endif
        mov pContainerName, NULL
      .endif
      lea xdi, cSuffix
      WriteFA xdi, "ANONYMOUS_STRUC�UD", $ObjTmpl(Application).dStrucNameSuffix  ;Make unique
      lea xdi, cSuffix
@@:
      ;Translation
      invoke RenderContainer, offset(szStruct), TRUE
      test xax, xax                                     ;Set/Reset ZF
      jz @ErrorEoF
      mov pEndToken, xax
      jmp @Exit
    .endif

    .if $DoesStringMatchA?([xax], <union>)             ;New structure inside this container?
      OCall xbx::IncFile.InputStatusSave, addr InpStat
      inc [xbx].$Obj(IncFile).bSkipLinePP
      OCall xbx::IncFile.GetNextTokenC
      .if xax == NULL
        dec [xbx].$Obj(IncFile).bSkipLinePP
        jmp @ErrorEoF
      .endif
      .if CHRA ptr [xax] == '{'
        dec [xbx].$Obj(IncFile).bSkipLinePP
        OCall xbx::IncFile.InputStatusLoad, addr InpStat
        jmp @UnionName
      .else
        OCall xbx::IncFile.GetNextTokenC
        .if xax == NULL
          dec [xbx].$Obj(IncFile).bSkipLinePP
          jmp @ErrorEoF
        .endif
        .if CHRA ptr [xax] == '{'
          dec [xbx].$Obj(IncFile).bSkipLinePP
          OCall xbx::IncFile.InputStatusLoad, addr InpStat
          OCall xbx::IncFile.GetNextTokenC              ;Consume tagName
          test xax, xax
          jz @ErrorEoF
          jmp @UnionName
        .endif
      .endif
      dec [xbx].$Obj(IncFile).bSkipLinePP
      OCall xbx::IncFile.InputStatusLoad, addr InpStat
      mov xax, pToken
      jmp @GetNextToken

@UnionName:
      ;Name management
      mov xax, pContainerName
      .if xax != NULL                                   ;Unnamed struct or union
        .if !$DoesTextMatchA?([xax], <DUMMYUNIONNAME>)  ;May have a number at the end
          mov xdi, $OfsCStrA("_UNION")
          jmp @F
        .endif
        mov pContainerName, NULL
      .endif
      lea xdi, cSuffix
      WriteFA xdi, "ANONYMOUS_UNION�UD", $ObjTmpl(Application).dStrucNameSuffix  ;Make unique
      lea xdi, cSuffix
@@:
      ;Translation
      invoke RenderContainer, offset(szUnion), TRUE
      test xax, xax
      jz @ErrorEoF
      mov pEndToken, xax
      jmp @Exit
    .endif

    ;Skip the following keywords --------------------------------------------------------
    .if $DoesStringMatchA?([xax], <static>)
      jmp @GetNextToken
    .endif

    .if $DoesStringMatchA?([xax], <enum>)
      jmp @GetNextToken
    .endif

    .if $DoesStringMatchA?([xax], <const>)
      jmp @GetNextToken
    .endif

    .if $DoesStringMatchA?([xax], <friend>)
      jmp @GetNextToken
    .endif

    .if $DoesStringMatchA?([xax], <virtual>)
      jmp @GetNextToken
    .endif

    ;private, public or protected -------------------------------------------------------
    IsPublicPrivateProtected? xax                       ;Check for 'private', 'public', 'protected'
    .if eax != FALSE
      OCall xbx::IncFile.PeekNextTokenC
      .if xax != NULL && CHRA ptr [xax] == ':'
        OCall xbx::IncFile.GetNextTokenC                ;Consume it
        test xax, xax
        jz @ErrorEoF
        jmp @GetNextToken
      .endif
    .endif

    ;macro ------------------------------------------------------------------------------
    invoke IsMacro?, pToken                             ;Check in the macro lists
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pNewMacros::List.ItemAt, edx
      .else
        OCall pKnwMacros::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length
      invoke RenderMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
      test eax, eax
      jnz @GetNextToken
    .endif

    ;Equate containing items ------------------------------------------------------------
    invoke IsEquate?, pToken
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pNewEquates::List.ItemAt, edx
      .else
        OCall pKnwEquates::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length

      .ifBitSet DWORD ptr [xax + xdx], EQF_HAS_EOL      ;Force an EOL
        OCall xbx::IncFile.StmWrite, pToken
        OCall xbx::IncFile.StmWriteEoL
        jmp @GetNextToken
      .endif
    .endif

    ;Record -----------------------------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == ':'                           ;Record field detected
      ;Name management
      mov xax, pContainerName
      .if xax != NULL                                   ;Unnamed struct or union
        .if !$DoesTextMatchA?([xax], <DUMMYSTRUCTNAME>) ;May have a number at the end
          .if !$DoesTextMatchA?([xax], <DUMMYUNIONNAME>);May have a number at the end
            mov xdi, $OfsCStrA("_REC")
            jmp @F
          .endif
        .endif
        mov pContainerName, NULL
      .endif
      lea xdi, cSuffix
      WriteFA xdi, "ANONYMOUS_REC�UD", $ObjTmpl(Application).dRecordNameSuffix  ;Make unique
      inc $ObjTmpl(Application).dRecordNameSuffix
      lea xdi, cSuffix
@@:
      ;Translation
      invoke RenderBitField, pContainerName, pType, pName, xdi
      test xax, xax
      jz @ErrorEoF
      mov pEndToken, xax
      jmp @Exit
    .endif

    ;Function or FunctionPtr ------------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == '('
      invoke IsFunctionPtr?, xax
      .if eax != FALSE
        invoke RenderTypedefFuncPtr, NULL
        test xax, xax
        jz @ErrorEoF
        .continue
      .else
        invoke IsFunction?
        .if eax != FALSE
          mov xax, pName
          test xax, xax
          cmovz xax, pType
          invoke RenderTypedefFunction, xax             ;No return value
          .continue
        .endif
      .endif
    .endif

    ;Array ------------------------------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == '['                           ;Array => DUP
      .if pType != NULL || pName != NULL                ;Only of we have a Type & a Name
        mov pDupList, $Create@Stacklist()
        mov dSquareBracketCount, 1
        .while TRUE
          OCall xbx::IncFile.GetNextTokenC
          test xax, xax
          jz @ErrorEoF
          .if CHRA ptr [xax] == ';'                     ;Statement terminator
            .break .if dSquareBracketCount == 0
            jmp @ErrorSyntax
          .endif
          .if CHRA ptr [xax] == ']'
            dec dSquareBracketCount
            .continue
          .endif
          .if CHRA ptr [xax] == '['
            inc dSquareBracketCount
            mov xax, $OfsCStrA("*")
          .endif
          Add@Stacklist pDupList, xax, xdx
        .endw
        .continue
      .endif
    .endif

    ;Pointer ----------------------------------------------------------------------------
    mov xax, pToken
    mov cl, [xax]
    .if cl == '*' || cl == '&'
      inc dPtrCount
      jmp @GetNextToken
    .endif

    invoke TranslateTypeQualifier, pToken
    cmp CHRA ptr [xax], 0
    jz @GetNextToken
    mov pToken, xax

    ;Token may be a basic C type --------------------------------------------------------
    .if pType == NULL
      BasicTypeCScan                                    ;Sets dTypeCSpec
      mov pToken, xax                                   ;Last gattered token
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if xax == NULL                                 ;If conversion failed
          lea xax, szUnkType
        .endif
        mov pType, xax
        mov xax, pToken
        .continue                                       ;Process the last gattered Token
      .endif
    .endif

    ;Multiple definition ---------------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == ','
      invoke WriteContainerMember, pName, pType, pDupList, dPtrCount
      mov pName, NULL
      jmp @GetNextToken
    .endif

    IsValidName? pToken
    .if eax != FALSE
      mov xax, pToken
      .if pType == NULL                                 ;First get a type
        .if $ObjTmpl(Application).Options.bUntypedParams
          invoke TranslateType, xax
        .endif
        mov pType, xax
      .elseif pName == NULL                             ;Then get a name
        mov pName, xax
      .else
        jmp @ErrorSyntax
      .endif
    .else
      jmp @ErrorSyntax
    .endif

@GetNextToken:
    OCall xbx::IncFile.GetNextTokenC
  .endw
  mov pEndToken, xax
  invoke WriteContainerMember, pName, pType, pDupList, dPtrCount

  ;Exit ---------------------------------------------------------------------------------

@Exit:
  Destroy@Stacklist pDupList
  mov xax, pEndToken
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderContainerMember - '%hs': unexpected Item '%hs'"), pContainerName, pToken
  OCall xbx::IncFile.StmWriteError
  Destroy@Stacklist pDupList
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  Destroy@Stacklist pDupList
  xor eax, eax
  ret
RenderContainerMember endp
