; ==================================================================================================
; Title:      Hex2dwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based con Hutch's code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  hex2dwordA
; Purpose:    Load an ANSI string hexadecimal representation of a DWORD.
; Arguments:  Arg1: -> ANSI hexadecimal string with 8 characters.
; Return:     eax = DWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
hex2dwordA proc pHexA:POINTER
  movzx edx, CHRA ptr [rcx]
  lea r8, h2dw_Tbl1
  lea r9, h2dw_Tbl2
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 1]
  add al, [r9 + rdx - 48]
  shl eax, 8

  movzx edx, CHRA ptr [rcx + 2]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 3]
  add al, [r9 + rdx - 48]
  shl eax, 8

  movzx edx, CHRA ptr [rcx + 4]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 5]
  add al, [r9 + rdx - 48]
  shl eax, 8

  movzx edx, CHRA ptr [rcx + 6]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRA ptr [rcx + 7]
  add al, [r9 + rdx - 48]

  ret
hex2dwordA endp

OPTION PROC:DEFAULT

end
