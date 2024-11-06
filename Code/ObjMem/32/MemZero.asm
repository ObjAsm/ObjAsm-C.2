; ==================================================================================================
; Title:      MemZero.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
  xor eax, eax
  mov ecx, [esp + 8]                                    ;ecx = dCount
  mov edx, [esp + 4]                                    ;edx -> Memory block
  shr ecx, 2
  jz @@2
@@1:
  mov [edx], eax
  add edx, 4
  dec ecx
  jnz @@1
@@2:
  mov ecx, [esp + 8]                                    ;ecx = dCount
  test ecx, 2
  jz @@3
  mov [edx], ax
  add edx, 2
@@3:
  test ecx, 1
  jz @@4
  mov [edx], al
@@4:
  ret 8
MemZero endp

OPTION PROC:DEFAULT

end
