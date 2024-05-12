; ==================================================================================================
; Title:      h2inc+_RenderExtern.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderExtern
; Purpose:    Parse extern.
; Arguments:  xbx -> IncFile.
; Return:     xax -> Last token or NULL if failed.

RenderExtern proc
  local pToken:PTOKEN

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderExtern")
  mov [xbx].$Obj(IncFile).dExternLinkage, ELT_UNDEF
  OCall xbx::IncFile.GetNextTokenC
  test xax, xax
  jz @ErrorEoF
  mov pToken, xax
  .if $DoesTextMatchA?([xax], <"C">)
;    OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C", 22h)   ;"   C linkage
;    OCall xbx::IncFile.StmWriteEoL
    mov [xbx].$Obj(IncFile).dExternLinkage, ELT_C
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax
  .elseif $DoesTextMatchA?([xax], <"C++">)
    OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C++", 22h) ;"   C++ linkage
    OCall xbx::IncFile.StmWriteEoL
    mov [xbx].$Obj(IncFile).dExternLinkage, ELT_CPP
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax
  .endif

  mov xax, pToken
  .if CHRA ptr [xax] == '{'
    invoke RenderBlock, NULL, RBT_EXTERN
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax
    OCall xbx::IncFile.StmWriteEoL
    mov xax, pToken
  .else
;    OCall xbx::IncFile.GetNextTokenC
;    test xax, xax
;    jz @ErrorEoF
    invoke RenderExternMember, xax
    test xax, xax
    jz @ErrorEoF
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  ret

@ErrorSyntax:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderExtern")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  xor eax, eax
  ret
RenderExtern endp