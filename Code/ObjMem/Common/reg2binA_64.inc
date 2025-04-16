; ==================================================================================================
; Title:      reg2binA_64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


$$Reg textequ $SubReg(rdx, sizeof(VALUE_TYPE))

Set8BinCharsA macro Index
  mov rax, "00000000"
  mov r8, 1

  rcl $$Reg, 1                                          ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc rax                                               ;Set "1"
@@:
  repeat 7
    shl r8, 8                                           ;Set increment for next char
    rcl $$Reg, 1                                        ;Set bit in carry flag
    jnc @F                                              ;Test carry flag
    add rax, r8                                         ;Set "1"
@@:
  endm
  mov [rcx + 8*sizeof(CHRA)*Index], rax                 ;Write result
endm

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  byte2binA, word2binA, dword2binA, qword2binA
; Purpose:    Convert a BYTE, WORD, DWORD or QWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
ProcName proc pBuffer:POINTER, Value:VALUE_TYPE
  ??CHARS = type(VALUE_TYPE)*8
  ??COUNT = 0
  repeat ??CHARS/8
    Set8BinCharsA ??COUNT
    ??COUNT = ??COUNT + 1
  endm
  m2z CHRA ptr [rcx + sizeof(CHRA)*??CHARS]             ;Write ZTC
  ret
ProcName endp

OPTION PROC:DEFAULT
