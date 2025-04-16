; ==================================================================================================
; Title:      StrEndW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrEndW
; Purpose:    Get the address of the zero character that terminates the string.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrEndW proc pStringW:POINTER
  mov eax, DWORD ptr [esp + 4]                          ;eax -> pStringW
  mov edx, eax
  and eax, 0FFFFFFFCh                                   ;Remove the last 2 bits to align the addr
  sub edx, eax                                          ;edx = 0..3
  mov ecx, DWORD ptr [eax]
  jmp @@JmpTableW[4*edx]                                ;Jump forward to skip non string BYTEs

  align ALIGN_CODE
@@JmpTableW:
  dd offset @@0
  dd offset @@1
  dd offset @@2
  dd offset @@3

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
@2:
  add eax, 2
@0:
  ret 4

  align ALIGN_CODE
@@1:
  test ecx, 000FFFF00h
  jz @1
@@3:
  add eax, 4
  test ecx, 0FF000000h
  mov ecx, DWORD ptr [eax]                              ;Read one DWORD more, this is valid since
  jnz @@1                                               ; the last word starts at offset 3 and
  test ecx, 0000000FFh                                  ; needs at least 1 byte of the next DWORD!
  jnz @@1
  sub eax, 1
  ret 4

  align ALIGN_CODE
@1:
  add eax, 1
  ret 4
StrEndW endp

OPTION PROC:DEFAULT

end
