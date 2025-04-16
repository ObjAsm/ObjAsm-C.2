; ==================================================================================================
; Title:      StrEndA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrEndA
; Purpose:    Get the address of the zero character that terminates the string.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrEndA proc pStringA:POINTER
  mov eax, DWORD ptr [esp + 4]
  mov edx, eax
  and eax, 0FFFFFFFCh                                   ;Remove the last 2 bits to align the addr
  sub edx, eax                                          ;edx = 0..3
  mov ecx, DWORD ptr [eax]
  lea edx, [offset @@0 + 8*edx]                         ;Jump forward to skip non string BYTEs
  jmp edx

  align ALIGN_CODE
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
  add eax, 4
  mov ecx, DWORD ptr [eax]

  repeat 3
    test cl, cl
    jz @0
    test ch, ch
    jz @1
    test ecx, 000FF0000h
    jz @2
    test ecx, 0FF000000h
    jz @3
    add eax, 4
    mov ecx, DWORD ptr [eax]
  endm

  jmp @@0

@0:
  ret 4
@1:
  add eax, 1
  ret 4
@2:
  add eax, 2
  ret 4
@3:
  add eax, 3
  ret 4
StrEndA endp

OPTION PROC:DEFAULT

end
