; ==================================================================================================
; Title:      BStrCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrECatChar
; Purpose:    Append a WIDE character to a BStr and return the address of the ZTC.
;             BStrECatChar does not perform any length checking. The destination buffer must have
;             enough room for at least BStrLength(Destination) + 1 + 1 characters.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> WIDE character.
; Return:     rax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrECatChar proc pDstBStr:POINTER, wChar:CHRW          ;rcx -> DstBStr, dx = wChar
  mov rax, [rcx - 4]                                    ;Get the length of DstBStr
  add rax, rcx
  add DWORD ptr [rcx - 4], 2                            ;Correct the length
  mov DWORD ptr [rax], edx                              ;Write character and ZTC
  add rax, 2                                            ;rax -> ZTC
  ret
BStrECatChar endp

OPTION PROC:DEFAULT

end
