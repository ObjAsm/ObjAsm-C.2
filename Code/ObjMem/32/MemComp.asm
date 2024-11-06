; ==================================================================================================
; Title:      MemComp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemComp
; Purpose:    Compare 2 memory blocks.
;             Both memory blocks must be at least as large as the maximal number of BYTEs to
;             compare, otherwise a fault may be triggered.
; Arguments:  Arg1: -> Memory block 1.
;             Arg2: -> Memory block 2.
;             Arg3: Maximal number of BYTEs to compare.
; Return:     If MemBlock1 != MemBlock2, then eax <> 0.
;             If MemBlock1 == MemBlock2, then eax = 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemComp proc pMemBlock1:POINTER, pMemBlock2:POINTER, dCount:DWORD
  push edi
  push esi
  xor eax, eax
  mov esi, [esp + 12]                                   ;esi -> MemBlock1
  mov edi, [esp + 16]                                   ;edi -> MemBlock2
  cmp esi, edi
  je @@3
  mov ecx, [esp + 20]                                   ;ecx = dCount
  test ecx, ecx
  jz @@3
  mov edx, ecx                                          ;edx = dCount
  shr ecx, 2
  jz @@1
@@0:
  mov eax, [esi]
  sub eax, [edi]
  jnz @@3
  add edi, 4
  add esi, 4
  dec ecx
  jnz @@0
@@1:
  test edx, 2
  jz @@2
  mov ax, [esi]
  sub ax, [edi]
  jnz @@3
  add edi, 2
  add esi, 2
@@2:
  test edx, 1
  jz @@3
  mov al, [esi]
  sub al, [edi]
@@3:
  pop esi
  pop edi
  ret 12
MemComp endp

OPTION PROC:DEFAULT

end
