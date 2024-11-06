; ==================================================================================================
; Title:      StrEndW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrEndW
; Purpose:    Get the address of the zero character that terminates the string.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrEndW proc pStringW:POINTER
  mov rax, rcx                                          ;rax -> pStringW
  mov rdx, rax
  and rax, 0FFFFFFFFFFFFFFFCh                           ;Remove the last 2 bits to align the addr
  sub rdx, rax                                          ;rdx = 0..3
  mov ecx, DWORD ptr [rax]
  lea r8, @@JmpTableW
  jmp POINTER ptr [r8 + sizeof(POINTER)*rdx]            ;Jump forward to skip non string BYTEs

align @WordSize
@@JmpTableW:
  POINTER offset @@0
  POINTER offset @@1
  POINTER offset @@2
  POINTER offset @@3

@@0:
  test ecx, 00000FFFFh
  jz @0
@@2:
  test ecx, 0FFFF0000h
  jz @2
  add rax, 4
  mov ecx, DWORD ptr [rax]
  jmp @@0
@2:
  add rax, 2
@0:
  ret
@@1:
  test ecx, 000FFFF00h
  jz @1
@@3:
  add rax, 4
  test ecx, 0FF000000h
  mov ecx, DWORD ptr [rax]                              ;Read one DWORD more, this is valid since
  jnz @@1                                               ; the last word starts at offset 3 and
  test ecx, 0000000FFh                                  ; needs at least 1 byte of the next DWORD!
  jnz @@1
  sub rax, 1
  ret
@1:
  add rax, 1
  ret
StrEndW endp

OPTION PROC:DEFAULT

end
