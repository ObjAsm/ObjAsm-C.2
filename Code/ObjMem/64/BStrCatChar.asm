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
; Procedure:  BStrCatChar
; Purpose:    Append a character to the end of a BStr.
; Arguments:  Arg1: Destrination BStr.
;             Arg2: WIDE character.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCatChar proc pDstBStr:POINTER, wChar:CHRW           ;rcx -> DstBStr, r8w = wChar
  mov eax, [rcx - 4]                                    ;Get the length of DstBStr
  add rax, rcx
  add DWORD ptr [rcx - 4], 2                            ;Increment length by 2
  mov DWORD ptr [rax], edx                              ;Write character and ZTC
  ret
BStrCatChar endp

OPTION PROC:DEFAULT

end
