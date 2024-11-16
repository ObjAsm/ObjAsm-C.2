; ==================================================================================================
; Title:      h2inc+_RenderFurtherTypes.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderFurtherTypes
; Purpose:    Check out if there come some pointer definitions behind.
; Arguments:  Arg1: -> Container Type.
;             Arg2: -> Container Tag.
;             Arg3: -> Last token
;             xbx -> IncFile.
; Return:     xax -> Next token or NULL if failed.

RenderFurtherTypes proc uses xdi pType:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
  local dPtrCount:DWORD, pName:PSTRINGA, pCurrToken:PTOKEN, cTransBuffer[128]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderFurtherTypes")
  mov dPtrCount, 0
  mov pName, NULL
  mov xax, pToken
  .while TRUE
    .if CHRA ptr [xax] == '['
      inc dPtrCount
      invoke SkipBraces, '[', ']'
      test xax, xax
      jz @ErrorEoF
      OCall xbx::IncFile.GetNextTokenC                  ;Get the next token
      test xax, xax
      jz @ErrorEoF
    .endif

    .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == ';'  ;Statement terminator
      .if pName != NULL
        mov xdi, pType
        .if xdi == NULL
          mov xdi, pTag
          .if xdi == NULL
            jmp @Exit
          .endif
        .endif

        mov pCurrToken, xax
        invoke StrCompA, pName, xdi
        .if eax != 0
          invoke TranslateReservedWord, pName, addr cTransBuffer
          mov pName, xax
          .if dPtrCount == 0
            IsStructure? xdi                              ;If the type is a structure,
            .if eax != FALSE                              ;  then the new type is it too
              IsStructure? pName                          ;Check if it already exist
              .if eax == FALSE
                invoke StrLengthA, pName
                invoke InsertStrg, pNewStructs, pName, eax
              .endif
            .endif
          .endif
          OCall xbx::IncFile.StmWrite, pName
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ")
          WritePtr
          OCall xbx::IncFile.StmWrite, xdi
          OCall xbx::IncFile.StmWriteEoL
        .endif
        mov xax, pCurrToken
      .endif
      .break .if CHRA ptr [xax] == ';'                  ;Statement terminator
      mov pName, NULL
      mov dPtrCount, 0
    .elseif CHRA ptr [xax] == '*'
      inc dPtrCount
    .else
      invoke TranslateTypeQualifier, xax
      .if CHRA ptr [xax] != 0
        mov pName, xax
      .endif
    .endif
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
  .endw

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov xax, pToken
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderFurtherTypes")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderFurtherTypes endp
