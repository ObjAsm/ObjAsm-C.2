; ==================================================================================================
; Title:      qword2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop


Set4BinCharsA macro Index
  mov eax, "0000"
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc eax                                               ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00000100h                                    ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00010000h                                    ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 01000000h                                    ;Set "1"
@@:
  mov [ecx + 4*sizeof(CHRA)*Index], eax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2binA
; Purpose:    Convert a QWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 65 BYTEs large.
;             (64 character BYTEs + ZTC = 65 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
qword2binA proc pBuffer:POINTER, qValue:QWORD
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov edx, [esp + 12]                                   ;edx = (QuadWord ptr qValue).HiDWord
  Set4BinCharsA 0
  Set4BinCharsA 1
  Set4BinCharsA 2
  Set4BinCharsA 3
  Set4BinCharsA 4
  Set4BinCharsA 5
  Set4BinCharsA 6
  Set4BinCharsA 7
  mov edx, [esp + 8]                                    ;edx = (QuadWord ptr qValue).LoDWord
  Set4BinCharsA 8
  Set4BinCharsA 9
  Set4BinCharsA 10
  Set4BinCharsA 11
  Set4BinCharsA 12
  Set4BinCharsA 13
  Set4BinCharsA 14
  Set4BinCharsA 15
  m2z BYTE ptr [ecx + sizeof(CHRA)*64]                  ;Set ZTC
  ret 12
qword2binA endp

OPTION PROC:DEFAULT

end
