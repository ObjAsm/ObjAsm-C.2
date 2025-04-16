; ==================================================================================================
; Title:      MemSwap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  MemSwap
; Purpose:    Exchange the memory content from a memory buffer to another.
;             They must NOT overlap.
;             Both buffers must be at least as large as number of BYTEs to exchange, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Memory buffer 1.
;             Arg2: -> Memory buffer 2.
;             Arg3: Number of BYTEs to exchange.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemSwap proc pMem1:POINTER, pMem2:POINTER, dCount:DWORD
  mov r10, rdx
  mov r9d, r8d
  shr r8d, 3
  jz @@2
@@1:
  mov rax, [rcx]
  mov rdx, [r10]
  mov [rcx], rdx
  mov [r10], rax
  add rcx, 8
  add r10, 8
  dec r8d
  jnz @@1
@@2:
  test r9d, 4
  jz @F
  mov eax, [rcx]
  mov edx, [r10]
  mov [rcx], edx
  mov [r10], eax
  add rcx, 4
  add r10, 4
@@:
  test r9d, 2
  jz @F
  mov ax, [rcx]
  mov dx, [r10]
  mov [rcx], dx
  mov [r10], ax
  add rcx, 2
  add r10, 2
@@:
  test r9d, 1
  jz @F
  mov al, [rcx]
  mov dl, [r10]
  mov [rcx], dl
  mov [r10], al
@@:
  ret
MemSwap endp

OPTION PROC:DEFAULT

end
