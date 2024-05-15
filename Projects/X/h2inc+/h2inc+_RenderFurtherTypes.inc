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
; Arguments:  Arg1 -> Type.
;             Arg2 -> Tag.
;             Arg3 -> Token
;             xbx -> IncFile.
; Return:     xax -> Next Token or NULL if failed.

RenderFurtherTypes proc uses xdi pType:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
  local dPtrCount:DWORD, pName:PSTRINGA, pCurrToken:PTOKEN, cTransBuffer[128]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderFurtherTypes")
  mov dPtrCount, 0
  mov pName, NULL
  .while TRUE
    mov xax, pToken
    .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == ';'    ;Statement terminator
      .if pName != NULL
        mov pCurrToken, xax
        mov xdi, pType
        .if xdi == NULL
          mov xdi, pTag
          .if xdi == NULL
            jmp @Exit
          .endif
        .endif
        ;Comment out forward declarations
        .if dPtrCount == 0
          invoke StrCompA, pName, xdi
          .if eax == 0
            OCall xbx::IncFile.StmWriteChar, ';'
          .endif
        .endif
        invoke TranslateReservedWord, pName, addr cTransBuffer
        mov pName, xax
        .if dPtrCount == 0
          IsStructure? xdi                              ;If the type is a structure,
          .if eax != FALSE                              ;  then the new type is it too
            IsStructure? pName                          ;Check if it already exist
            .if eax == FALSE
              DbgStrA pName, "RenderFurther"
              DbgStrW [xbx].$Obj(IncFile).pHeaderFileName
              DbgDec [xbx].$Obj(IncFile).dLineNumber
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
        mov xax, pCurrToken
      .endif
      .break .if CHRA ptr [xax] == ';'                ;Statement terminator
      mov pName, NULL
      mov dPtrCount, 0
    .elseif CHRA ptr [xax] == '*'
      inc dPtrCount
    .else
      invoke TranslateTypeQualifier, pToken
      .if CHRA ptr [xax] != 0
        mov pName, xax
      .endif
    .endif
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax
  .endw
  .if pName != NULL
    OCall xbx::IncFile.StmWriteEoL
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov xax, pToken
  ret

@ErrorSyntax:
  inc [xbx].$Obj(IncFile).dErrorCount
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
