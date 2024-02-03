; ==================================================================================================
; Title:      udword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, February 2024
;               - Wrong computation of total number of chars corrected.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableW:WORD

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  udword2decW
; Purpose:    Convert an unsigned DWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: DWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 22 BYTEs large to allocate the output string
;             (10 WIDE characters + ZTC = 22 BYTEs).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
udword2decW proc pBuffer:POINTER, dValue:DWORD
  mov eax, [esp + 8]                    ;eax -> dValue
  mov edx, 0D1B71759h                   ;= 2^45\10000    13 bit extra shift
  mov ecx, [esp + 4]                    ;ecx -> pBuffer
  push edi
  mov edi, eax                          ;save a copy of the number
  mul edx                               ;gives 6 high digits in edx
  push esi
  shr edx, 13                           ;correct for multiplier offset used to give better accuracy
  push ecx
  mov eax, 68DB9h                       ;=2^32\10000+1
  je @@10                               ;if zero then don’t need to process the top 6 digits
  imul esi, edx, 10000
  sub edi, esi
  mul edx
  mov esi, 100
  jnb @@09
  cmp edx, 9
  jbe @@08
  mov edx, DWORD ptr TwoDecDigitTableW[4*edx]
  mov [ecx], edx
  add ecx, 16
@@00:
  mul esi
@@01:
  mov edx, DWORD ptr TwoDecDigitTableW[4*edx]
  mov [ecx - 12], edx
@@02:
  mul esi
@@03:
  mov edx, DWORD ptr TwoDecDigitTableW[4*edx]
  mov [ecx - 8], edx
@@04:
  mov eax, 28F5C29h
  mul edi
@@05:
  mov edx, DWORD ptr TwoDecDigitTableW[4*edx]
  mov [ecx - 4], edx
@@06:
  mul esi
@@07:
  mov eax, DWORD ptr TwoDecDigitTableW[4*edx]
  mov [ecx], eax
  m2z WORD ptr [ecx + 4]
  pop edx
  pop esi
  sub ecx, edx
  pop edi
  lea eax, [ecx + 6]
  ret 8

@@08:
  add edx, 30h
  mov [ecx], edx
  add ecx, 14
  jnz @@00
@@09:
  mul esi
  jnb @F
  add ecx, 12
  cmp edx, 9
  ja @@01
  add edx, 30h
  sub ecx, 2
  mov [ecx - 10], edx
  jnz @@02
@@:
  mul esi
  jnb @@10
  add ecx, 8
  cmp edx, 9
  ja @@03
  add edx, 30h
  sub ecx, 2
  mov [ecx - 6], edx
  jnz @@04
@@10:
  mov eax, 28F5C29h
  mul edi
  mov esi, 100
  jnb @F
  add ecx, 4
  cmp edx, 9
  ja @@05
  add edx, 30h
  sub ecx, 2
  mov [ecx - 2], edx
  jnz @@06
@@:
  mul esi
  cmp edx, 9
  ja @@07
  lea eax, [edx + 30h]
  mov [ecx], eax                        ;ZTC included
  pop edx
  pop esi
  sub ecx, edx
  pop edi
  lea eax, [ecx + 4]
  ret 8
udword2decW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
