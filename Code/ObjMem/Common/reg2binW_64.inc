; ==================================================================================================
; Title:      reg2binW_64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


$$Reg textequ $SubReg(rdx, sizeof(VALUE_TYPE))

Set4BinCharsW macro Index
  mov rax, 0030003000300030h
  mov r8, 1

  rcl $$Reg, 1                                          ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc rax                                               ;Set "1"
@@:
  repeat 3
    shl r8, 16                                          ;Set increment for next char
    rcl $$Reg, 1                                        ;Set bit in carry flag
    jnc @F                                              ;Test carry flag
    add rax, r8                                         ;Set "1"
@@:
  endm
  mov [rcx + 4*sizeof(CHRW)*Index], rax                 ;Write result
endm

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  byte2binW, word2binW, dword2binW, qword2binW
; Purpose:    Convert a BYTE, WORD, DWORD or QWORD to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Value.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
ProcName proc pBuffer:POINTER, Value:VALUE_TYPE
  ??CHARS = type(VALUE_TYPE)*8
  ??COUNT = 0
  repeat ??CHARS/4
    Set4BinCharsW ??COUNT
    ??COUNT = ??COUNT + 1
  endm
  m2z CHRW ptr [rcx + sizeof(CHRW)*??CHARS]             ;Write ZTC
  ret
ProcName endp

OPTION PROC:DEFAULT
