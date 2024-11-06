; ==================================================================================================
; Title:      hex2qwordW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  hex2qwordW
; Purpose:    Load a WIDE string hexadecimal representation of a QWORD.
; Arguments:  Arg1: -> WIDE hexadecimal string with 16 characters.
; Return:     rax = QWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
hex2qwordW proc pHexW:POINTER
  movzx edx, CHRA ptr [rcx]
  lea r8, h2dw_Tbl1
  lea r9, h2dw_Tbl2
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 02]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 04]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 06]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 08]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 10]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 12]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 14]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 16]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 18]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 20]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 22]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 24]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 26]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 28]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 30]
  add al, [r9 + rdx - 48]

  ret
hex2qwordW endp

OPTION PROC:DEFAULT

end
