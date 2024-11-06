; ==================================================================================================
; Title:      StrLengthW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLengthW
; Purpose:    Determine the length of a WIDE string not including the zero terminating character.
; Arguments:  Arg1: -> Wide string.
; Return:     eax = Length of the string in characters.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLengthW proc pStringW:POINTER
  mov eax, DWORD ptr [esp + 4]                          ;eax -> pStringW
  mov edx, eax
  and eax, 0FFFFFFFCh                                   ;Remove the last 2 bits to align the addr
  sub edx, eax                                          ;edx = 0..3
  mov ecx, DWORD ptr [eax]
  jmp @@JmpTableW[sizeof(POINTER)*edx]                  ;Jump forward to skip non string BYTEs

  align ALIGN_CODE
@@JmpTableW:
  POINTER offset @@0
  POINTER offset @@1
  POINTER offset @@2
  POINTER offset @@3

  align ALIGN_CODE
@@0:
  test ecx, 00000FFFFh
  jz @0
@@2:
  test ecx, 0FFFF0000h
  jz @2
  add eax, 4
  mov ecx, DWORD ptr [eax]
  jmp @@0

  align ALIGN_CODE
@@1:
  test ecx, 000FFFF00h
  jz @2
@@3:
  add eax, 4
  test ecx, 0FF000000h
  mov ecx, DWORD ptr [eax]
  jnz @@1
  test ecx, 0000000FFh
  jz @3

@2:
  add eax, 2
@0:
  sub eax, DWORD ptr [esp + 4]
  shr eax, 1
  ret 4

  align ALIGN_CODE
@3:
  sub eax, 1
  sub eax, DWORD ptr [esp + 4]
  shr eax, 1
  ret 4
StrLengthW endp

OPTION PROC:DEFAULT

end
