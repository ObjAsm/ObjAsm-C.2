; ==================================================================================================
; Title:      BStrSize.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrSize
; Purpose:    Determine the size of a BSTR including the zero terminating character + leading DWORD.
; Arguments:  Arg1: -> Source BSTR.
; Return:     eax = String size including the length field and zero terminator in BYTEs.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrSize proc pBStr:POINTER
  mov ecx, [esp + 4]                                    ; ecx -> BSTR
  mov eax, DWORD ptr [ecx - 4]                          ; Get the byte length DWORD
  add eax, sizeof(DWORD) + sizeof(CHRW)                 ; Add zero terminating char + leading DWORD
  ret 4
BStrSize endp

OPTION PROC:DEFAULT

end
