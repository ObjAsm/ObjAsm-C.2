; ==================================================================================================
; Title:      qword2binW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop


Set2BinCharsW macro Index
  mov eax, 00300030h
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc eax                                               ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00010000h                                    ;Set "1"
@@:
  mov [ecx + 2*sizeof(CHRW)*Index], eax
endm

; --------------------------------------------------------------------------------------------------
; Procedure:  qword2binW
; Purpose:    Convert a QWORD to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.
; Notes:      To allocate the output string, the destination buffer must be at least 130 BYTEs large.
;             (64 character WORDs + ZTC = 130 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
qword2binW proc pBuffer:POINTER, qValue:QWORD
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov edx, [esp + 12]                                   ;edx = (QuadWord ptr qValue).HiDWord
  Set2BinCharsW 00
  Set2BinCharsW 01
  Set2BinCharsW 02
  Set2BinCharsW 03
  Set2BinCharsW 04
  Set2BinCharsW 05
  Set2BinCharsW 06
  Set2BinCharsW 07
  Set2BinCharsW 08
  Set2BinCharsW 09
  Set2BinCharsW 10
  Set2BinCharsW 11
  Set2BinCharsW 12
  Set2BinCharsW 13
  Set2BinCharsW 14
  Set2BinCharsW 15
  mov edx, [esp + 8]                                    ;edx = (QuadWord ptr qValue).LoDWord
  Set2BinCharsW 16
  Set2BinCharsW 17
  Set2BinCharsW 18
  Set2BinCharsW 19
  Set2BinCharsW 20
  Set2BinCharsW 21
  Set2BinCharsW 22
  Set2BinCharsW 23
  Set2BinCharsW 24
  Set2BinCharsW 25
  Set2BinCharsW 26
  Set2BinCharsW 27
  Set2BinCharsW 28
  Set2BinCharsW 29
  Set2BinCharsW 30
  Set2BinCharsW 31
  m2z BYTE ptr [ecx + sizeof(CHRW)*64]                  ;Set ZTC
  ret 12
qword2binW endp

OPTION PROC:DEFAULT

end
