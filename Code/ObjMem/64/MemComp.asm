; ==================================================================================================
; Title:      MemComp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemComp
; Purpose:    Compare 2 memory blocks.
;             Both memory blocks must be at least as large as the maximal number of BYTEs to compare,
;             otherwise a fault may be triggered.
; Arguments:  Arg1: -> Memory block 1.
;             Arg2: -> Memory block 2.
;             Arg3: Maximal number of BYTEs to compare.
; Return:     If MemBlock1 != MemBlock2, then eax <> 0.
;             If MemBlock1 == MemBlock2, then eax = 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemComp proc pMemBlock1:POINTER, pMemBlock2:POINTER, dCount:DWORD
  xor eax, eax
  cmp rcx, rdx
  je @@4
  test r8d, r8d
  jz @@4
  mov r9d, r8d                                          ;r9d = r8d = dCount
  shr r8d, 3
  jz @@1
@@0:
  mov rax, [rcx]
  sub rax, [rdx]
  jnz @@5
  add rdx, 8
  add rcx, 8
  dec r8d
  jnz @@0
@@1:
  test r9d, 4
  jz @@2
  mov eax, [rcx]
  sub eax, [rdx]
  jnz @@4
  add rdx, 4
  add rcx, 4
@@2:
  test r9d, 2
  jz @@3
  mov ax, [rcx]
  sub ax, [rdx]
  jnz @@4
  add rdx, 2
  add rcx, 2
@@3:
  test r9d, 1
  jz @@4
  mov al, [rcx]
  sub al, [rdx]
@@4:
  ret
@@5:
  mov eax, -1                                           ;In case that the difference is in bits > 31
  ret
MemComp endp

OPTION PROC:DEFAULT

end
