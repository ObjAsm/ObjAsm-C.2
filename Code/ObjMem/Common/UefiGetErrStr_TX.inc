; ==================================================================================================
; Title:      UefiGetErrStr_TX.inc
; Author:     G. Friedrich / HSE
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


% include &ObjMemPath&Common\\UefiErrTable_T.inc

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UefiGetErrStrA / UefiGetErrStrW 
; Purpose:    Return description string from a COM error code.
; Arguments:  Arg1: COM error code.
; Return:     xax -> Error string.

.code
align ALIGN_CODE
ProcName proc xErrCode:XWORD
  ?mov ecx, xErrCode
  mov xdx, offset UefiErrTable
  mov xax, not(1 shl (8*@WordSize - 1))
  and xcx, xax
  .if xcx > UefiErrTableCount
    mov xax, $OfsCStr("Unknown error")
  .else 
    mov xax, POINTER ptr [xdx + sizeof(POINTER)*xcx]
  .endif
  ret
ProcName endp
