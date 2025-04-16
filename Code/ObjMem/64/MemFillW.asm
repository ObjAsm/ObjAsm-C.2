; ==================================================================================================
; Title:      MemFillW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  MemFillW
; Purpose:    Fill a memory block with a given word value.
;             Destination buffer must be at least as large as number of BYTEs to fill, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination memory block.
;             Arg2: Memory block size in BYTEs.
;             Arg3: Word value to fill with.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemFillW proc pMem:POINTER, dCount:DWORD, wFillText:WORD
  ;rcx -> Memory block, edx = dCount; r8w = fill WORD
  xor r9, r9
  mov ax, r8w
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
MemFillW endp

OPTION PROC:DEFAULT

end
