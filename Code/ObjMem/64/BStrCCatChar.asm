; ==================================================================================================
; Title:      BStrCCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCCatChar
; Purpose:    Append a WIDE character to a BSTR with length limitation.
; Arguments:  Arg1: -> Destination BSTR.
;             Arg2: -> WIDE character.
;             Arg3: Maximal number of charachters the destination string can hold excluding the ZTC.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCCatChar proc pDstBStr:POINTER, wChar:CHRW, dMaxChars:DWORD   
  shl r8d, 1                                            ; r8 = dMaxChars in BYTEs
  mov r9d, DWORD ptr [rcx - 4]                          ; Get current BYTEs in BSTR
  .if r9d < r8d                                         ; Check max char count
    movzx eax, dx                                       ; Include the ZTC in the write operation
    add DWORD ptr [rcx - 4], 2                          ; Increment size
    mov DWORD ptr [rcx + r9], eax                       ; Write character and ZTC
  .endif
  ret
BStrCCatChar endp

OPTION PROC:DEFAULT

end
