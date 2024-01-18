; ==================================================================================================
; Title:      MemFillW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemFillW
; Purpose:    Fill a memory block with a given word value.
;             Destination buffer must be at least as large as number of BYTEs to fill, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination memory block.
;             Arg2: Memory block size in BYTEs.
;             Arg3: Word value to fill with.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
MemFillW proc pMem:POINTER, dCount:DWORD, wFillText:WORD
  mov ax, [esp + 12]                                    ;ax = FillText
  mov cx, ax
  shl eax, 16
  mov ax, cx

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
  ret 12
MemFillW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
