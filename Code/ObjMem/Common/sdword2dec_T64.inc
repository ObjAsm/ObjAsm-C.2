; ==================================================================================================
; Title:      sdword2dec_T64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2022
;               - First release.
;               - Character and bitness neutral code.
; links:      https://publik.tuwien.ac.at/files/publik_287602.pdf
;             https://calc.penjee.com/  128 hex calculator
;             https://de.wikipedia.org/wiki/Integer_(Datentyp)
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  sdword2decT
; Purpose:    Convert a signed DWORD to its decimal string representation.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: SDWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
ProcName proc pBuffer:POINTER, sdValue:SDWORD
;
  ;rcx -> Buffer, edx = SDWORD
  %mov r10, offset TwoDecDigitTable&TARGET_STR_AFFIX
  mov eax, edx                                  ;eax = sdValue
  mov edx, 0D1B71759h                           ;= 2^45/10000 + 1 and 13 bit shift
  mov r11, rcx
  test eax, eax
  jge @F
  mov CHR ptr [rcx], '-'
  add rcx, sizeof(CHR)
  neg eax
@@:
  mov r8d, eax                                  ;Save a copy of the number
  mul edx                                       ;Gives 6 high digits in edx
  shr edx, 13                                   ;Correct for multiplier offset used to give better accuracy
  jz @@10                                       ;If zero then don’t need to process the upper 6 dec digits
  mov eax, 68DB9h                               ;2^32/10000 + 1

  imul r9d, edx, 10000
  sub r8d, r9d                                  ;r8d = lower 4 dec digits
  mul edx                                       ;edx = upper dec digits
  mov r9d, 100
  jnb @@09
  cmp edx, 9
  jbe @@08
  mrm [rcx], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
  add rcx, 8*sizeof(CHR)
@@00:
  mul r9d                                       ;x100
@@01:
  mrm [rcx - 6*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@02:
  mul r9d                                       ;x100
@@03:
  mrm [rcx - 4*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx

@@04:
  mov eax, 28F5C29h                             ;2^32/100 + 1
  mul r8d
@@05:
  mrm [rcx - 2*sizeof(CHR)], DCHR ptr [r10 + sizeof(DCHR)*rdx], rdx
@@06:
  mul r9d                                       ;x100
@@07:
  mrm [rcx], DCHR ptr [r10 + sizeof(DCHR)*rdx], rax
  m2z CHR ptr [rcx + 2*sizeof(CHR)]
  sub rcx, r11
  lea eax, [ecx + 3*sizeof(CHR)]                ;eax = number of BYTEs written incl. the ZTC
  ret


@@08:
  add edx, '0'
  mov [rcx], $SubReg(rdx, sizeof(CHR))
  add rcx, 7*sizeof(CHR)
  jmp @@00
@@09:
  mul r9d                                       ;x100
  jnb @F
  add rcx, 6*sizeof(CHR)
  cmp edx, 9
  ja @@01
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 5*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@02
@@:
  mul r9d                                       ;x100
  jnb @F
  add rcx, 4*sizeof(CHR)
  cmp edx, 9
  ja @@03
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 3*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@04

@@10:
  mov r9d, 100
@@:
  mov eax, 28F5C29h                             ;2^32/100 + 1
  mul r8d
  jnb @F
  add rcx, 2*sizeof(CHR)
  cmp edx, 9
  ja @@05
  add edx, '0'
  sub rcx, 1*sizeof(CHR)
  mov [rcx - 1*sizeof(CHR)], $SubReg(rdx, sizeof(CHR))
  jmp @@06
@@:
  mul r9d                                       ;x100
  cmp edx, 9
  ja @@07                                       ;=> 2 Digits
  lea rax, [rdx + '0']
  mov [rcx], $SubReg(rax, sizeof(DCHR))         ;Write character and ZTC
  sub rcx, r11
  lea eax, [ecx + 2*sizeof(CHR)]                ;eax = number of BYTEs written incl. the ZTC
  ret
ProcName endp
OPTION PROC:DEFAULT
