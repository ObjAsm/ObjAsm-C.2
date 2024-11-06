; ==================================================================================================
; Title:      MemClone.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemClone
; Purpose:    Copy a memory block from a source to a destination buffer.
;             Source and destination must NOT overlap.
;             Destination buffer must be at least as large as number of BYTEs to copy, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source buffer.
;             Arg3: Number of BYTEs to copy.
; Return:     eax = Number of copied BYTEs.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemClone proc pDstMem:POINTER, pSrcMem:POINTER, dCount:DWORD
  push rdi
  push rsi
  mov rdi, rcx                                          ;rdi -> DstMem
  mov rsi, rdx                                          ;rsi -> SrcMem
  mov eax, r8d                                          ;eax = dCount
  mov rcx, rax
  shr rcx, 3 
  rep movsq
  mov rcx, rax
  and rcx, 4
  shr rcx, 2 
  rep movsd
  mov rcx, rax
  and rcx, 2
  shr rcx, 1 
  rep movsw
  mov rcx, rax
  and rcx, 1
  rep movsb
  pop rsi
  pop rdi
  ret
MemClone endp

OPTION PROC:DEFAULT

end
