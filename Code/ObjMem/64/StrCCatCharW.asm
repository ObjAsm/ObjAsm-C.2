; ==================================================================================================
; Title:      StrCCatCharW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCatCharW
; Purpose:    Append a character to the end of a WIDE string with length limitation.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> WIDE character.
;             Arg3: Maximal number of characters that fit into the destination buffer.
; Return:     Nothing.

.code
align ALIGN_CODE
StrCCatCharW proc pBuffer:POINTER, cChar:CHRW, dMaxChars:DWORD
  invoke StrEndW, rcx                                   ;pBuffer
  mov rcx, pBuffer
  mov edx, dMaxChars
  lea rcx, [rcx + sizeof(CHRW)*rdx]
  sub rcx, rax
  jbe @F
  movzx ecx, cChar                                      ;Write char and ZTC
  mov [rax], ecx
@@:
  ret
StrCCatCharW endp

end
