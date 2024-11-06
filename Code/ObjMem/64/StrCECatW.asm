; ==================================================================================================
; Title:      StrCECatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCECatW
; Purpose:    Concatenate 2 WIDE strings with length limitation and return the ZTC address. 
;             The destination string buffer should have at least enough room for the maximum
;             number of characters + 1.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrCECatW proc pDstStrW:POINTER, pSrcStrW:POINTER, dMaxChars:DWORD
  invoke StrEndW, rcx                                   ;pDstStrW
  mov r8d, dMaxChars
  shl r8, 1
  add r8, pDstStrW
  sub r8, rax
  jbe @F                                                ;Destination is too small!
  shr r8d, 1
  invoke StrCECopyW, rax, pSrcStrW, r8d
@@:
  ret
StrCECatW endp

end
