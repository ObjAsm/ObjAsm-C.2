; ==================================================================================================
; Title:      StrRightA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRightA
; Purpose:    Copy the right n characters from the source string into the destination buffer.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Character count.
; Return:     rax = Number of characters.

.code
align ALIGN_CODE
StrRightA proc uses rbx rdi rsi pDstStringA:POINTER, pSrcStringA:POINTER, dCharCount:DWORD
  mov rdi, rcx
  mov rsi, rdx
  mov rbx, r8
  invoke StrLengthA, rdx                                ;pSrcStringA
  mov rdx, rax
  cmp rax, rbx                                          ;qCharCount
  jbe @F                                                ;unsigned compare!
  mov rax, rbx                                          ;rax = qCharCount
@@:
  sub rdx, rax
  add rdx, rsi                                          ;pSrcStringA
  mov rbx, rax
  invoke MemShift, rdi, rdx, eax
  mov rax, rbx
  m2z CHRA ptr [rdi + rbx]                              ;Set ZTC
  ret
StrRightA endp

end
