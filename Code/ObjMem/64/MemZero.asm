; ==================================================================================================
; Title:      MemZero.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemZero
; Purpose:    Fill a memory block with zeros. A bit faster than MemFillB.
;             The memory buffer must be at least as large as number of BYTEs to zero, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Memory buffer.
;             Arg2: Number of BYTEs to zero.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemZero proc pMem:POINTER, dCount:DWORD
  ;rcx -> Memory block, edx = dCount
  xor eax, eax
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
MemZero endp

OPTION PROC:DEFAULT

end
