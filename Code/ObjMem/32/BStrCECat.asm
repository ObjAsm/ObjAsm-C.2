; ==================================================================================================
; Title:      BStrCECat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCECat
; Purpose:    Concatenate 2 BSTRs with length limitation and return the ending zero character
;             address. The destination string buffer should have at least enough room for the
;             maximum number of characters + 1.
; Arguments:  Arg1: -> Destination BSTR.
;             Arg2: -> Source BSTR.
;             Arg3: Maximal number of charachters the destination string can hold excluding the ZTC.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCECat proc pDstBStr:POINTER, pSrcBStr:POINTER, dMaxChars:DWORD
  invoke BStrCCat, [esp + 12], [esp + 12], [esp + 12]
  mov ecx, [esp + 4]
  mov eax, [ecx - 4]
  add eax, ecx
  ret 12
BStrCECat endp

OPTION PROC:DEFAULT

end
