; ==================================================================================================
; Title:      Random32_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


externdef dRandomSeed:DWORD

.data
  dRandomSeed  DWORD  0

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Random32
; Purpose:    Generate a random 32 bit number in a given range [0..Limit-1].
;             Park Miller random number algorithm. Written by Jaymeson Trudgen (NaN) and optimized
;             by Rickey Bowers Jr. (bitRAKE).
; Arguments:  Arg1: Range limit (max. = 07FFFFFFFh).
; Return:     eax = random number in the range [0..Limit-1].

.code
align ALIGN_CODE
Random32 proc dRangeLimit:DWORD
  local q:DWORD

  mov eax, dRandomSeed
  .if eax == 0
    rdtsc
    shr eax, 2
    add eax, 1
    mov dRandomSeed, eax
  .endif
  xor edx, edx
  mov q, 127773
  div q                                                 ;eax = floor(seed / q)
                                                        ;edx = remainder
  push xax
  mov eax, 16807
  mul edx                                               ;eax = mul of remainder * a
  pop xdx                                               ;edx = floor of seed / q

  push xax
  mov eax, 2836
  mul edx
  pop xdx                                               ;edx = mull of rem * a
                                                        ;eax = mull of seed / q * r
  sub edx, eax
  mov eax, edx
  mov dRandomSeed, edx                                  ;Save next seed
  xor edx, edx
  div dRangeLimit
  mov eax, edx
  ret
Random32 endp
