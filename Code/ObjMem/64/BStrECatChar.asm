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
; Procedure:  BStrECatChar
; Purpose:    Append a WIDE character to a BSTR and return the address of the ZTC.
;             BStrECatChar does not perform any length checking. The destination buffer must have
;             enough room for at least BStrLength(Destination) + 1 + 1 characters.
; Arguments:  Arg1: -> Destination BSTR buffer.
;             Arg2: -> WIDE character.
; Return:     rax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrECatChar proc pDstBStr:POINTER, wChar:CHRW          ; rcx -> DstBStr, dx = wChar
  mov eax, [rcx - 4]                                    ; Get the length of DstBStr
  add rax, rcx                                          ; Get pointer to end of string
  add DWORD ptr [rcx - 4], 2                            ; Increment the length
  movzx ecx, dx                                         ; Include the ZTC in the operation
  mov [rax], ecx                                        ; Write character and ZTC
  add rax, 2                                            ; Return rax -> ZTC
  ret
BStrECatChar endp

OPTION PROC:DEFAULT

end
