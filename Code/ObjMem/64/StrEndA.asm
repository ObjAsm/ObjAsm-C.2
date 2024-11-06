; ==================================================================================================
; Title:      StrEndA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrEndA
; Purpose:    Get the address of the zero character that terminates the string.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrEndA proc pStringA:POINTER
  mov rax, rcx
  mov rdx, rax
  and rax, 0FFFFFFFFFFFFFFFCh                           ;Remove the last 2 bits to align the addr
  sub rdx, rax                                          ;edx = 0..3
  mov ecx, DWORD ptr [rax]
  lea r9, @@0
  lea r10, [r9 + 8*rdx]                                 ;code size (test + jz) = 8 BYTEs
  jmp r10                                               ;Jump forward to skip non string BYTEs

@@0:
  test ecx, 0000000FFh
  jz @0
@@1:
  test ecx, 00000FF00h
  jz @1
@@2:
  test ecx, 000FF0000h
  jz @2
@@3:
  test ecx, 0FF000000h
  jz @3
  add rax, 4
  mov ecx, DWORD ptr [rax]

  repeat 3
    test cl, cl
    jz @0
    test ch, ch
    jz @1
    test ecx, 000FF0000h
    jz @2
    test ecx, 0FF000000h
    jz @3
    add rax, 4
    mov ecx, DWORD ptr [rax]
  endm

  jmp @@0

@0:
  ret
@1:
  add rax, 1
  ret
@2:
  add rax, 2
  ret
@3:
  add rax, 3
  ret
StrEndA endp

OPTION PROC:DEFAULT

end
