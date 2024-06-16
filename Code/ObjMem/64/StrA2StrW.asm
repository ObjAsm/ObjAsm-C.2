; ==================================================================================================
; Title:      StrA2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrA2StrW
; Purpose:    Convert a ANSI string into a WIDE string.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: -> Source ANSI string.
; Return:     eax = Number of chars in string, not including the ZTC.

align ALIGN_CODE
StrA2StrW proc uses rdi rsi pDstStrW:POINTER, pSrcStrA:POINTER
  mov rdi, pDstStrW
  mov rsi, pSrcStrA
  invoke StrLengthA, rsi
  mov ecx, eax
  push rax
  add rsi, rax
  inc ecx
  shl rax, 1
  add rdi, rax
  xor eax, eax
  std
@@:
  lodsb
  stosw
  dec ecx
  jne @B
  cld
  pop rax
  ret
StrA2StrW endp

end
