; ==================================================================================================
; Title:      hex2dwordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based con Hutch's code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  hex2dwordW
; Purpose:    Load a WIDE string hexadecimal representation of a DWORD.
; Arguments:  Arg1: -> WIDE hex string.
; Return:     eax = DWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
hex2dwordW proc pHexW:POINTER
  push esi

  mov esi, [esp + 8]

  movzx ecx, CHRW ptr [esi]
  mov ah, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRW ptr [esi + 2]
  add ah, h2dw_Tbl2[edx - 48]

  movzx ecx, CHRW ptr [esi + 4]
  mov al, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRW ptr [esi + 6]
  add al, h2dw_Tbl2[edx - 48]

  rol eax, 16

  movzx ecx, CHRW ptr [esi + 8]
  mov ah, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRW ptr [esi + 10]
  add ah, h2dw_Tbl2[edx - 48]

  movzx ecx, CHRW ptr [esi + 12]
  mov al, h2dw_Tbl1[ecx - 48]
  movzx edx, CHRW ptr [esi + 14]
  add al, h2dw_Tbl2[edx - 48]

  pop esi

  ret 4
hex2dwordW endp

OPTION PROC:DEFAULT

end
