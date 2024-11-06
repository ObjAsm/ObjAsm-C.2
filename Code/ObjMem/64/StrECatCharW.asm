; ==================================================================================================
; Title:      StrECatCharW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrECatCharW
; Purpose:    Append a character to a WIDE string and return the address of the ending zero.
;             StrECatCharW does not perform any length checking. The destination buffer must have
;             enough room for at least StrLengthW(Destination) + 1 + 1 characters.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: -> WIDE character.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrECatCharW proc pBuffer:POINTER, cChar:CHRW
  invoke StrEndW, rcx                                   ;pBuffer
  movzx ecx, cChar
  mov DCHRW ptr [rax], ecx                              ;Writes cChar and ZTC
  add rax, sizeof(CHRW)
  ret
StrECatCharW endp

end
