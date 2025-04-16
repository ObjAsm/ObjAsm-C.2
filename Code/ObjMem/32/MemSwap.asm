; ==================================================================================================
; Title:      MemSwap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
  push edi
  push esi
  mov esi, [esp + 12]                                   ;esi -> Mem1
  mov edi, [esp + 16]                                   ;edi -> pMem2
  mov ecx, [esp + 20]                                   ;ecx = dCount
  shr ecx, 2
  test ecx, ecx
  jmp @@02
@@01:
  mov eax, DWORD ptr [esi]
  mov edx, DWORD ptr [edi]
  mov DWORD ptr [esi], edx
  mov DWORD ptr [edi], eax
  add esi, 4
  add edi, 4
  dec ecx
@@02:
  jne @@01
  mov ecx, dCount
  and ecx, 3
  jmp @@04
@@03:
  mov al, BYTE ptr [esi]
  mov dl, BYTE ptr [edi]
  mov BYTE ptr [esi], dl
  mov BYTE ptr [edi], al
  inc esi
  inc edi
  dec ecx
@@04:
  jne @@03
  pop esi
  pop edi
  ret 12
MemSwap endp

OPTION PROC:DEFAULT

end
