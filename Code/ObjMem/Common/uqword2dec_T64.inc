; ==================================================================================================
; Title:      uqword2dec_T64.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
;               - Character and bitness neutral code.
; links:      https://publik.tuwien.ac.at/files/publik_287602.pdf
;             https://calc.penjee.com/  128 hex calculator
;             https://de.wikipedia.org/wiki/Integer_(Datentyp)
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqword2decA / uqword2decW 
; Purpose:    Convert a unsigned QWORD into its decimal string representation.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.

OPTION PROC:NONE
align ALIGN_CODE
ProcName proc pBuffer:POINTER, qValue:QWORD    ;e.g. 1844'6744'0737'0955'1615
  ;rcx -> Buffer, rdx = QWORD
  %mov r10, offset TwoDecDigitTable&TARGET_STR_AFFIX
  mov rax, rdx                                  ;eax = sdValue
  mov rdx, 0DBE6FECEBDEDD5BFh                   ;2^97/10^10 + 1 => rdx = upper 10 dec digits
  mov r11, rcx
  mov r8, rax                                   ;Save a copy of the number
  mul rdx                                       ;rdx = upper 10 dec digits
  shr rdx, 33
  jz @@20                                       ;if zero then don’t process the top 10 dec digits
  mov rax, 02AF31DC462h                         ;2^64/10^8 + 1
  mov r9, 10000000000
  imul r9, rdx
  sub r8, r9                                    ;r8 = lower 10 dec digits
  mul rdx                                       ;rdx = higher 10 dec digits
  mov r9, 100
  jnc @@19                                      ;If rdx = 0 => CARRY = 0
  cmp rdx, 9
  jbe @@18
  mrm [rcx], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
  add rcx, 18*sizeof(CHR)
@@00:
  mul r9                                        ;rdx = 2 dec digits
@@01:
  mrm [rcx - 16*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@02:
  mul r9                                        ;x100
@@03:
  mrm [rcx - 14*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@04:
  mul r9                                        ;x100
@@05:
  mrm [rcx - 12*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@06:
  mul r9                                        ;x100
@@07:
  mrm [rcx - 10*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx

@@08:
  mov rax, 02AF31DC462h                         ;2^64/10^8 + 1
  mul r8
@@09:
  mrm [rcx - 8*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@10:
  mul r9                                        ;x100
@@11:
  mrm [rcx - 6*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@12:
  mul r9                                        ;x100
@@13:
  mrm [rcx - 4*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@14:
  mul r9                                        ;x100
@@15:
  mrm [rcx - 2*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@16:
  mul r9                                        ;x100
@@17:
  mrm [rcx], DCHR ptr [r10 + sizeof(DCHR)*rdx], rax
  m2z CHR ptr [rcx + 2*sizeof(CHR)]
  sub rcx, r11
  lea eax, [ecx + 3*sizeof(CHR)]                ;eax = number of BYTEs written incl. the ZTC
  ret


@@18:
  add $SubReg(rdx, sizeof(CHR)), '0'
  mov [rcx], $SubReg(rdx, sizeof(CHR))
  add rcx, 17*sizeof(CHR)
  jmp @@00
@@19:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 16*sizeof(CHR)
  cmp rdx, 9
  ja @@01                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 15*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@02
@@:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 14*sizeof(CHR)
  cmp rdx, 9
  ja @@03                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 13*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@04
@@:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 12*sizeof(CHR)
  cmp rdx, 9
  ja @@05                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 11*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@06
@@:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 10*sizeof(CHR)
  cmp rdx, 9
  ja @@07                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 09*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@08

@@20:
  mov r9, 100
@@:
  mov rax, 02AF31DC462h                         ;2^64/10^8 + 1
  mul r8
  jnc @F                                        ;rdx = 0
  add rcx, 8*sizeof(CHR)
  cmp rdx, 9
  ja @@09                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 07*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@10
@@:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 6*sizeof(CHR)
  cmp rdx, 9
  ja @@11                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 05*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@12
@@:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 4*sizeof(CHR)
  cmp rdx, 9
  ja @@13                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 03*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@14
@@:
  mul r9                                        ;x100
  jnc @F                                        ;rdx = 0
  add rcx, 2*sizeof(CHR)
  cmp rdx, 9
  ja @@15                                       ;=> 2 dec digits
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 01*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@16
@@:
  mul r9                                        ;x100
  cmp rdx, 9
  ja @@17                                       ;=> 2 dec digits
  lea eax, [edx + '0']
  mov [rcx], $SubReg(rax, sizeof(DCHR))         ;Write character and ZTC
  sub rcx, r11
  lea eax, [ecx + 2*sizeof(CHR)]                ;eax = number of BYTEs written incl. the ZTC
  ret
ProcName endp
OPTION PROC:DEFAULT
