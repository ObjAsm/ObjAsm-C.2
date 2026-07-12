; ==================================================================================================
; Title:      BStrCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCatChar
; Purpose:    Append a character to the end of a BSTR.
; Arguments:  Arg1: Destination BSTR.
;             Arg2: WIDE character.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCatChar proc pDstBStr:POINTER, wChar:CHRW           ; rcx -> DstBStr, r8w = wChar
  mov eax, [rcx - 4]                                    ; Get the length of DstBStr
  add rax, rcx                                          ; rax = insertion pointer
  add DWORD ptr [rcx - 4], 2                            ; Increment size by 2
  movzx ecx, dx                                         ; Include the ZTC in the write operation
  mov [rax], ecx                                        ; Write character and ZTC
  ret
BStrCatChar endp

OPTION PROC:DEFAULT

end
