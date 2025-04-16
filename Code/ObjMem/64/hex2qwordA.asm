; ==================================================================================================
; Title:      Hex2qwordA.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

; --------------------------------------------------------------------------------------------------
; Procedure:  hex2qwordA
; Purpose:    Load an ANSI string hexadecimal representation of a QWORD.
; Arguments:  Arg1: -> ANSI hexadecimal string with 16 characters.
; Return:     rax = QWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
hex2qwordA proc pHexA:POINTER
  movzx edx, CHRA ptr [rcx]
  lea r8, h2dw_Tbl1
  lea r9, h2dw_Tbl2
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 01]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 02]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 03]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 04]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 05]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 06]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 07]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 08]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 09]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 10]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 11]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 12]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 13]
  add al, [r9 + rdx - 48]
  shl rax, 8

  movzx edx, CHRA ptr [rcx + 14]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 15]
  add al, [r9 + rdx - 48]

  ret
hex2qwordA endp

OPTION PROC:DEFAULT

end
