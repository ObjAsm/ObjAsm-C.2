; ==================================================================================================
; Title:      StrRightW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRightW
; Purpose:    Copy the right n characters from the source string into the destination buffer.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Character count.
; Return:     rax = Number of characters.

.code
align ALIGN_CODE
StrRightW proc uses rbx rdi rsi pBuffer:POINTER, pSrcStringW:POINTER, dCharCount:DWORD
  mov rdi, rcx
  mov rsi, rdx
  mov rbx, r8
  invoke StrLengthW, rcx                                ;pSrcStringW
  mov rdx, rax
  cmp rax, rbx                                          ;qCharCount
  jbe @F                                                ;unsigned compare!
  mov rax, rbx                                          ;rax = qCharCount
@@:
  sub rdx, rax
  shl rdx, 1
  add rdx, rsi                                          ;pSrcStringW
  mov rbx, rax
  shl rax, 1
  invoke MemShift, rdi, rdx, eax                        ;pBuffer
  mov rax, rbx
  m2z CHRW ptr [rdi + 2*rbx]                            ;Set ZTC
  ret
StrRightW endp

end
