; ==================================================================================================
; Title:      bin2reg_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2byteA / bin2byteW up to bin2qwordA / bin2qwordW
; Purpose:    Conversion of an input string that contains a binary number in the form of a
;             sequence of "0" and "1" into a BYTE, WORD, DWORD or QWORD.
; Arguments:  Arg1: -> Input string.
; Return:     al, ax, eax, rax = Number.

NextChar macro
  movzx edx, CHR ptr [xcx]
  add xcx, sizeof(CHR)
  sub edx, "0"
  cmp edx, 1                                            ;If less (0), carry is set
  ja @F                                                 ;ZTC hit => exit
  rcl eax, 1
endm

OPTION PROC:NONE
align ALIGN_CODE
ProcName proc pString:POINTER
  ?mov ecx, [esp + 4]                                   ;xcx -> Buffer
  xor eax, eax
  not eax
  repeat BIT_COUNT
    NextChar
  endm
@@:
  not eax
  ret
ProcName endp
OPTION PROC:DEFAULT
