; ==================================================================================================
; Title:      sdword2decA.asm
; Author:     G. Friedrich
; Version:    C.2.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Based on Lingo's optimization of Paul Dixon's algorithm.
;             Version C.2.1, January 2023
;               - ZTC bug corrected.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef TwoDecDigitTableA:BYTE

; --------------------------------------------------------------------------------------------------
; Procedure:  sdword2decA
; Purpose:    Convert a signed DWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: SDWORD value.
; Return:     eax = Number of BYTEs copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 12 BYTEs large to allocate the output string
;             (Sign + 10 ANSI characters + ZTC = 12 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
sdword2decA proc pBuffer:POINTER, sdValue:SDWORD
  mov eax, [esp + 8]                    ;eax = sdValue
  mov edx, 0D1B71759h                   ;= 2^45\10000    13 bit extra shift
  mov ecx, [esp + 4]                    ;ecx -> pBuffer
  test eax, eax
  push ecx
  jge @F
  mov BYTE ptr [ecx], '-'
  add ecx, 1
  neg eax
@@:
  push edi
  mov edi, eax                          ;save a copy of the number
  mul edx                               ;gives 6 high digits in edx
  push esi
  shr edx, 13                           ;correct for multiplier offset used to give better accuracy
  mov eax, 68DB9h                       ;=2^32\10000+1
  je @@10                               ;if zero then don’t need to process the top 6 digits
  imul esi, edx, 10000
  sub edi, esi
  mul edx
  mov esi, 100
  jnb @@09
  cmp edx, 9
  jbe @@08
  mov dx, WORD ptr TwoDecDigitTableA[2*edx]
  mov [ecx], dx
  add ecx, 8
@@00:
  mul esi
@@01:
  mov dx, WORD ptr TwoDecDigitTableA[2*edx]
  mov [ecx - 6], dx
@@02:
  mul esi
@@03:
  mov dx, WORD ptr TwoDecDigitTableA[2*edx]
  mov [ecx - 4], dx
@@04:
  mov eax, 28F5C29h
  mul edi
@@05:
  mov dx, WORD ptr TwoDecDigitTableA[2*edx]
  mov [ecx - 2], dx
@@06:
  mul esi
@@07:
  mov ax, WORD ptr TwoDecDigitTableA[2*edx]
  mov [ecx], ax
  m2z BYTE ptr [ecx + 2]
  pop esi
  pop edi
  pop edx
  sub ecx, edx
  lea eax, [ecx + 3]
  ret 8

@@08:
  add edx, 30h
  mov [ecx], dx
  add ecx, 7
  jnz @@00
@@09:
  mul esi
  jnb @F
  add ecx, 6
  cmp edx, 9
  ja @@01
  add edx, 30h
  sub ecx, 1
  mov [ecx - 5], dx
  jnz @@02
@@:
  mul esi
  jnb @@10
  add ecx, 4
  cmp edx, 9
  ja @@03
  add edx, 30h
  sub ecx, 1
  mov [ecx - 3], dx
  jnz @@04
@@10:
  mov eax, 28F5C29h
  mul edi
  mov esi, 100
  jnb @F
  add ecx, 2
  cmp edx, 9
  ja @@05
  add edx, 30h
  sub ecx, 1
  mov [ecx - 1], dx
  jnz @@06
@@:
  mul esi
  cmp edx, 9
  ja @@07
  lea eax, [edx + 30h]
  mov [ecx], ax
  pop esi
  pop edi
  pop edx
  sub ecx, edx
  lea eax, [ecx + 2]
  ret 8
sdword2decA endp

OPTION PROC:DEFAULT

end
