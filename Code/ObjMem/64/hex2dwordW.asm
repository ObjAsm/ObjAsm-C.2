; ==================================================================================================
; Title:      hex2dwordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based con Hutch's code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

; --------------------------------------------------------------------------------------------------
; Procedure:  hex2dwordW
; Purpose:    Load a WIDE string hexadecimal representation of a DWORD.
; Arguments:  Arg1: -> WIDE hex string with 8 characters.
; Return:     eax = DWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
hex2dwordW proc pHexW:POINTER
  movzx edx, CHRW ptr [rcx]
  lea r8, h2dw_Tbl1
  lea r9, h2dw_Tbl2
  mov al, [r8 + rdx - 48]
  movzx edx, CHRW ptr [rcx + 2]
  add al, [r9 + rdx - 48]
  shl eax, 8

  movzx edx, CHRW ptr [rcx + 4]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRW ptr [rcx + 6]
  add al, [r9 + rdx - 48]
  shl eax, 8

  movzx edx, CHRW ptr [rcx + 8]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRW ptr [rcx + 10]
  add al, [r9 + rdx - 48]
  shl eax, 8

  movzx edx, CHRW ptr [rcx + 12]
  mov al, [r8 + rdx - 48]
  movzx edx, CHRW ptr [rcx + 14]
  add al, [r9 + rdx - 48]

  ret
hex2dwordW endp

OPTION PROC:DEFAULT

end
