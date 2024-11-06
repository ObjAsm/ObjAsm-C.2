; ==================================================================================================
; Title:      MemFillB.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemFillB
; Purpose:    Fill a memory block with a given byte value.
;             Destination buffer must be at least as large as number of BYTEs to fill, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination memory block.
;             Arg2: Memory block size in BYTEs.
;             Arg3: Byte value to fill.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemFillB proc pMem:POINTER, dCount:DWORD, bFillByte:BYTE
  ;rcx -> Memory block, edx = dCount; r8b = fill BYTE
  mov al, r8b
  xor r9, r9
  mov ah, al
  mov r9w, ax
  shl eax, 16
  mov ax, r9w
  mov r9d, eax
  shl rax, 32
  or rax, r9

  mov r9d, edx
  shr rdx, 3
  jz @@2
@@1:
  mov [rcx], rax
  add rcx, 8
  dec rdx
  jnz @@1
@@2:
  test r9d, 4
  jz @F
  mov [rcx], eax
  add rcx, 4
@@:
  test r9d, 2
  jz @F
  mov [rcx], ax
  add rcx, 2
@@:
  test r9d, 1
  jz @F
  mov [rcx], al
@@:
  ret
MemFillB endp

OPTION PROC:DEFAULT

end
