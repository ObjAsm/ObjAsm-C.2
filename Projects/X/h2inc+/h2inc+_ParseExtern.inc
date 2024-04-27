; ==================================================================================================
; Title:      h2inc+_ParseExtern.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseExtern
; Purpose:    Parse extern.
; Arguments:  xbx -> IncFile.
; Return:     Nothing.

ParseExtern proc
  local pToken:PTOKEN

  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
    .break .if xax == NULL
    .break .if ZERO? || CHRA ptr [xax] == ";"           ;Statement terminator
    mov pToken, xax
    .if DWORD ptr [xax] == ',"C"' && DCHRA ptr [xax + sizeof(DWORD)] == "0"
      OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C", 22h)   ;"   C linkage
      OCall xbx::IncFile.StmWriteEOL
      mov [xbx].$Obj(IncFile).bExternC, TRUE
      .break
    .elseif DWORD ptr [xax] == '++C"' && DWORD ptr [xax + 4] == '0,"'
      OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C++", 22h) ;"   C++ linkage
      OCall xbx::IncFile.StmWriteEOL
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
  DbgErrorF , "¦SU(¦UD): ParseExtern - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
ParseExtern endp