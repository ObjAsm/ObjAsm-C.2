; ==================================================================================================
; Title:      Hex2dwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based con Hutch's code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

; --------------------------------------------------------------------------------------------------
; Procedure:  hex2dwordA
; Purpose:    Load an ANSI string hexadecimal representation of a DWORD.
; Arguments:  Arg1: -> ANSI hexadecimal string.
; Return:     eax = DWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
hex2dwordA proc pHexA:POINTER
  push esi

  mov esi, [esp + 8]

  movzx ecx, CHRA ptr [esi]
  mov ah, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRA ptr [esi + 1]
  add ah, h2dw_Tbl2[edx - 48]

  movzx ecx, CHRA ptr [esi + 2]
  mov al, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRA ptr [esi + 3]
  add al, h2dw_Tbl2[edx - 48]

  rol eax, 16

  movzx ecx, CHRA ptr [esi + 4]
  mov ah, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRA ptr [esi + 5]
  add ah, h2dw_Tbl2[edx - 48]

  movzx ecx, CHRA ptr [esi + 6]
  mov al, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRA ptr [esi + 7]
  add al, h2dw_Tbl2[edx - 48]

  pop esi

  ret 4
hex2dwordA endp

OPTION PROC:DEFAULT

end
