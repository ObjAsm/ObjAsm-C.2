; ==================================================================================================
; Title:      BStrLength.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrLength
; Purpose:    Determine the length of a BStr not including the ZTC.
; Arguments:  Arg1: -> Source BStr.
; Return:     rax = Length of the string in characters.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrLength proc pBStr:POINTER
  mov eax, DWORD ptr [rcx - 4]                          ;Get the byte length DWORD
  shr rax, 1                                            ;Character count
  ret
BStrLength endp

OPTION PROC:DEFAULT

end
