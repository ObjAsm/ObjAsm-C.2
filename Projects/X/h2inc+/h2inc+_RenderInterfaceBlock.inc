; ==================================================================================================
; Title:      h2inc+_RenderInterfaceBlock.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderInterfaceBlock
; Purpose:    Translate all members of a block (structure, union, enum).
; Arguments:  Arg1 -> Name.
;             xax -> '{'
;             xbx -> IncFile.
; Return:     xax -> Last token or NULL if failed.
; Link:       https://devblogs.microsoft.com/oldnewthing/20200909-00/?p=104198

RenderInterfaceBlock proc pName:PSTRINGA
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderInterfaceBlock")
  mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
  .repeat
    invoke RenderTypedefFuncPtr, NULL
    test xax, xax
    jz @ErrorEoF
    invoke RenderContainerMember, xax, pName
    .break .if xax == NULL
    cmp CHRA ptr [xax], ';'
    jnz @ErrorSyntax
    OCall xbx::IncFile.PeekNextTokenC
    .break .if xax == NULL
    .if CHRA ptr [xax] == '}'
      OCall xbx::IncFile.GetNextTokenC               ;Consume it
      test xax, xax
      jz @ErrorEoF
      .break
    .endif
  .until FALSE

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  ret

@ErrorSyntax:
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderInterfaceBlock")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderInterfaceBlock endp