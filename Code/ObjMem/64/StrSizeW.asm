; ==================================================================================================
; Title:      StrSizeW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrSizeW
; Purpose:    Determine the size of a WIDE string including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Size of the string in BYTEs.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrSizeW proc pStringW:POINTER
  mov rax, rcx
  mov rdx, rcx
  and rax, -8                     ;Remove the last 3 bits to align the addr, this avoids a GPF
  sub rdx, rax                    ;rdx = 0..7
  mov r9, [rax]
  mov r8, r9
  shr r9, 32
  lea r10, @@JmpTableW
  jmp POINTER ptr [r10 + sizeof(POINTER)*rdx]           ;Jump forward to skip non string BYTEs

align @WordSize
@@JmpTableW:
  POINTER offset @@0
  POINTER offset @@1
  POINTER offset @@2
  POINTER offset @@3
  POINTER offset @@4
  POINTER offset @@5
  POINTER offset @@6
  POINTER offset @@7

@@0:
  test r8d, 00000FFFFh
  jz @0
@@2:
  test r8d, 0FFFF0000h
  jz @2
@@4:
  test r9d, 00000FFFFh
  jz @4
@@6:
  test r9d, 0FFFF0000h
  jz @6
  add rax, @WordSize
  mov r9, [rax]
  mov r8, r9
  shr r9, 32
  jmp @@0

@@1:
  test r8d, 000FFFF00h
  jz @1
@@3:
  test r8d, 0FF000000h
  jnz @@5
  test r9d, 0000000FFh
  jz @3
@@5:
  test r9d, 000FFFF00h
  jz @5
@@7:
  add rax, @WordSize
  mov r10, [rax]
  mov r8, r10
  shr r10, 32
  test r9d, 0FF000000h
  mov r9, r10
  jnz @@1

  test r8d, 0000000FFh
  jnz @@1
  sub rax, rcx
  add rax, 1
  ret

@0:
  sub rax, rcx
  add rax, 2
  ret
@1:
  sub rax, rcx
  add eax, 3
  ret
@2:
  sub rax, rcx
  add rax, 4
  ret
@3:
  sub rax, rcx
  add rax, 5
  ret
@4:
  sub rax, rcx
  add eax, 6
  ret
@5:
  sub rax, rcx
  add rax, 7
  ret
@6:
  sub rax, rcx
  add rax, 8
  ret
StrSizeW endp

OPTION PROC:DEFAULT

end
