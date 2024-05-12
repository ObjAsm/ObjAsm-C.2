; ==================================================================================================
; Title:      h2inc+_RenderExternMember.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderExternMember
; Purpose:    Get an extern declaration.
; Arguments:  Arg1 -> First token.
;             xbx -> IncFile.
; Return:     xax -> Next token, NULL if failed.

RenderExternMember proc pToken:PTOKEN
  local dTypeCSpec:DWORD, bFunction:DWORD, bStatic:DWORD, bConst:DWORD
  local pType:PSTRINGA, pName:PSTRINGA, cTransBuffer[128]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderExternMember")
  mov pType, NULL
  mov pName, NULL
  mov bStatic, FALSE
  mov bFunction, FALSE
  mov bConst, FALSE

  mov xax, pToken                                       ;Use token passed in to this proc
  .while TRUE
    .break .if xax == NULL
    invoke SkipAnnotations, pToken
    test xax, xax
    jz @ErrorEoF

    .if $DoesStringMatchA?([xax], <typedef>)
      invoke RenderTypedef
      jmp @Exit
    .endif

    .if $DoesStringMatchA?([xax], <static>)
      mov bStatic, TRUE
      jmp @GetNextToken
    .endif

    .if $DoesStringMatchA?([xax], <const>)
      mov bConst, TRUE
      jmp @GetNextToken
    .endif

    invoke TranslateTypeQualifier, xax
    cmp CHRA ptr [xax], 0
    jz @GetNextToken

    .break .if CHRA ptr [xax] == '}' || CHRA ptr [xax] == ';'   ;Statement terminator

    mov pToken, xax

    invoke IsQualifier?, xax
    test eax, eax
    jnz @GetNextToken

    invoke IsMacro?, pToken
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pNewMacros::List.ItemAt, edx
      .else
        OCall pKnwMacros::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof(DWORD)]
      invoke RenderMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
      test eax, eax
      jnz @GetNextToken
    .endif

    mov xax, pToken
    .if CHRA ptr [xax] == '('
      invoke RenderPrototype, pName, NULL
      OCall xbx::IncFile.GetNextTokenC
      test xax, xax
      jz @ErrorEoF
      jmp @Exit
    .endif

    ;pToken may be a basic C type
    mov xax, pToken
    .if pType == NULL
      BasicTypeCScan
      mov pToken, xax
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if eax == 0
          lea xax, szUnkType
        .endif
        mov pType, xax
        mov xax, pToken                                 ;Process last gattered Token
        .continue
      .endif
    .endif

    mov xax, pToken
    .if $DoesStringMatchA?([xax], <"C">)
      jmp @GetNextToken                                 ;Ignore it
    .endif

    mov xax, pToken
    .if $DoesStringMatchA?([xax], <"C++">)
      jmp @GetNextToken                                 ;Ignore it
    .endif

    mov xax, pToken
    mov cl, CHRA ptr [xax]
    .if cl == '[' && pName != NULL                      ;"[]" should only come after a valid name
      .repeat                                           ;Ignore it
        OCall xbx::IncFile.GetNextTokenC
      .until xax == NULL || CHRA ptr [xax] == ';'
      .break
    .endif

    .if cl == "="
      .repeat
        OCall xbx::IncFile.GetNextTokenC
      .until xax == NULL || CHRA ptr [xax] == ';'
      .break
    .endif

    IsValidName? pToken
    .if eax != FALSE
      mov xax, pToken
      .if pType == NULL
        mov pType, xax
      .elseif pName == NULL
        mov pName, xax
      .else
        jmp @ErrorSyntax
      .endif
    .else
      jmp @ErrorSyntax
    .endif

@GetNextToken:
    OCall xbx::IncFile.GetNextTokenC
    mov pToken, xax
  .endw

  cmp pName, NULL
  jz @ErrorSyntax
  invoke TranslateReservedWord, pName, addr cTransBuffer
  OCall xbx::IncFile.StmWriteF, $OfsCStrA("externdef %hs:%hs"), xax, pType
  OCall xbx::IncFile.StmWriteEoL
  mov xax, pToken

@Exit:
  ret

@ErrorSyntax:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderExternMember")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderExternMember endp
