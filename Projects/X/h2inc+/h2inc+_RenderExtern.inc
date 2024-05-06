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
; Return:     Nothing.

RenderExtern proc
  local pToken:PTOKEN

  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
    .break .if ZERO? || CHRA ptr [xax] == ";"           ;Statement terminator
    mov pToken, xax
    .if DWORD ptr [xax] == ',"C"' && DCHRA ptr [xax + sizeof(DWORD)] == "0"
      OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C", 22h)   ;"   C linkage
      OCall xbx::IncFile.StmWriteEoL
      mov [xbx].$Obj(IncFile).bExternC, TRUE
      .break
    .elseif DWORD ptr [xax] == '++C"' && DWORD ptr [xax + 4] == '0,"'
      OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C++", 22h) ;"   C++ linkage
      OCall xbx::IncFile.StmWriteEoL
      .break
    .endif
    OCall xbx::IncFile.StmWrite, $OfsCStrA("externdef ")
    .if [xbx].$Obj(IncFile).bExternC != FALSE
      OCall xbx::IncFile.StmWrite, $OfsCStrA("c ")
    .endif
    invoke RenderExternMember, pToken
    .break
  .endw

  ret

@Error:
  DbgErrorF , "¦SU(¦UD): RenderExtern - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
RenderExtern endp