; ==================================================================================================
; Title:      BStrECat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrECat
; Purpose:    Append a BSTR to another and return the address of the ending zero character.
;             BStrCat does not perform any length checking. The destination buffer must have room
;             for at least BStrLength(Destination) + BStrLength(Source) + 1 characters.
; Arguments:  Arg1: -> Destination BSTR.
;             Arg2: -> Source BSTR.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrECat proc pDstBStr:POINTER, pSrcBStr:POINTER
  invoke BStrCat, [esp + 8], [esp + 8]
  mov eax, [esp + 4]
  add eax, [eax - 4] 
  ret 8
BStrECat endp

OPTION PROC:DEFAULT

end
