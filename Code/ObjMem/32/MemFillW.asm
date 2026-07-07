; ==================================================================================================
; Title:      MemFillW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
  mov ax, [esp + 12]                                    ;ax = FillText
  mov cx, ax
  shl eax, 16
  mov ax, cx

  mov ecx, [esp + 8]                                    ;ecx = dCount
  mov edx, [esp + 4]                                    ;edx -> Memory block
  shr ecx, 1
  jz @@1
@@:
  mov [edx], eax
  add edx, 4
  dec ecx
  jnz @B
@@1:
  test DWORD ptr [esp + 8], 1
  jz @F
  mov [edx], ax
@@:
  ret 12
MemFillW endp

OPTION PROC:DEFAULT

end
