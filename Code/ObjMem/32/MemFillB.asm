; ==================================================================================================
; Title:      MemFillB.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
  mov al, [esp + 12]                                    ;al = FillByte
  shl eax, 8                                            ;ah = FillByte
  mov al, [esp + 12]                                    ;al = FillByte
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
MemFillB endp

OPTION PROC:DEFAULT

; Old Procedure Version 1.0.1
;MemFillB proc uses edi pMem:POINTER, dCount:DWORD, bFillByte:BYTE
;    mov al, bFillByte
;    shl eax, 8
;    mov al, bFillByte
;    push ax
;    shl eax, 16
;    pop ax
;    mov edi, pMem
;    mov ecx, dCount
;    shr ecx, 2
;    rep stosd
;    mov ecx, dCount
;    and ecx, 3
;    rep stosb
;    ret
;MemFillB endp

end
