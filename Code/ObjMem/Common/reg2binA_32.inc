; ==================================================================================================
; Title:      reg2binA_32.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


$$Reg textequ $SubReg(edx, sizeof(VALUE_TYPE))

Set4BinCharsA macro Index
  mov eax, "0000"
  rcl $$Reg, 1                                          ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc eax                                               ;Set "1"
@@:
  rcl $$Reg, 1                                          ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00000100h                                    ;Set "1"
@@:
  rcl $$Reg, 1                                          ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00010000h                                    ;Set "1"
@@:
  rcl $$Reg, 1                                          ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 01000000h                                    ;Set "1"
@@:
  mov [ecx + 4*sizeof(CHRA)*Index], eax                 ;Write result
endm

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  byte2binA, word2binA, dword2binA
; Purpose:    Convert a BYTE, WORD or DWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.

OPTION PROC:NONE
align ALIGN_CODE
ProcName proc pBuffer:POINTER, Value:VALUE_TYPE
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov $$Reg, [esp + 8]                                  ;Value
  ??CHARS = type(VALUE_TYPE)*8
  ??COUNT = 0
  repeat ??CHARS/4
    Set4BinCharsA ??COUNT
    ??COUNT = ??COUNT + 1
  endm
  m2z CHRA ptr [ecx + sizeof(CHRA)*??CHARS]             ;Write ZTC
  ret 8
ProcName endp
OPTION PROC:DEFAULT
