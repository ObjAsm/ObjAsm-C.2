; ==================================================================================================
; Title:      QuadWord.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of QuadWord operations.
; Note:       See QuadWord definition in "Memory.inc" file.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    Macro definitions
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Quad
; Purpose:    Transform 2 DoubleWords into a QuadWord.
; Arguments:  Arg1: High order DoubleWord.
;             Arg2: Low order DoubleWord.
; Return:     QUADWORD in edx:eax.


$Quad macro dWrd1:req, dWrd2:req
  ifdifi <dWrd1>, <edx>
    mov edx, dWrd1
  endif
  ifdifi <dWrd2>, <eax>
    mov eax, dWrd2
  endif
  exitm <edx:eax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qmov
; Purpose:    Move a QUADWORD.
; Arguments:  Arg1: Destination QUADWORD.
;             Arg2: Source QUADWORD.

qmov macro qWrd1:req, qWrd2:req
  ifidni <qWrd1>, <edx:eax>
    mov eax, (QUADWORD ptr qWrd2).LoDWord
    mov edx, (QUADWORD ptr qWrd2).HiDWord
  elseifidni <qWrd2>, <edx:eax>
    mov (QUADWORD ptr qWrd1).LoDWord, eax
    mov (QUADWORD ptr qWrd1).HiDWord, edx
  else
    m2m (QUADWORD ptr qWrd1).LoDWord, (QUADWORD ptr qWrd2).LoDWord
    m2m (QUADWORD ptr qWrd1).HiDWord, (QUADWORD ptr qWrd2).HiDWord
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qdmov
; Purpose:    Move a DWORD to a QUADWORD.
; Arguments:  Arg1: Destination QUADWORD.
;             Arg2: Source dWord.

qdmov macro qWrd:req, dWrd:req
  ifidni <qWrd>, <edx:eax>
    mov eax, (QUADWORD ptr qWrd2).LoDWord
    mov edx, 0                                          ;;Don't change flags
  else
    if (opattr dWrd) and 00010000b                      ;;is a register?
      mov (QUADWORD ptr qWrd).LoDWord, dWrd
    else
      m2m (QUADWORD ptr qWrd).LoDWord, dWrd
    endif
    mov (QUADWORD ptr qWrd).HiDWord, 0
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qShiftL
; Purpose:    Shift a edx:eax left cx bits.
; Arguments:  Arg1: edx:eax = QWORD
;             Arg2: cx = bit shift count

qShiftL macro
  local Done

  shld edx, eax, cl                                     ;;First apply shift count.
  shl  eax, cl                                          ;;mod 32 to EDX:EAX
  test cx, 32                                           ;;Need to shift by another 32?
  jz   Done                                             ;;No, done.
  mov  edx, eax                                         ;;Left shift EDX:EAX
  xor  eax, eax                                         ;;by 32 bits
  Done:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:        qneg
; Purpose:      Negate edx:eax
; Arguments:    arg1: edx:eax = QWORD

qneg macro
  not edx
  neg eax
  sbb edx, -1                                           ;;Increment high word if low word was 0.
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qdadd
; Purpose:    Add a DoubleWord to a QUADWORD (qWrd = qWrd + dWrd).
; Arguments:  Arg1: Destination QUADWORD.
;             Arg2: Source DoubleWord.

qdadd macro qWrd:req, dWrd:req
  ifidni <qWrd>, <edx:eax>
    add eax, dWrd
    adc edx, 0
  else
    if (opattr (dWrd)) and 00010000b                    ;;is it a register?
      add (QUADWORD ptr qWrd).LoDWord, dWrd
      adc (QUADWORD ptr qWrd).HiDWord, 0
    else
      push ecx
      mov ecx, dWrd
      add (QUADWORD ptr qWrd).LoDWord, ecx
      adc (QUADWORD ptr qWrd).HiDWord, 0
      pop ecx
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qqadd
; Purpose:    Add 2 QuadWords (qWrd1 = qWrd1 + qWrd2).
; Arguments:  Arg1: Destination QUADWORD.
;             Arg2: Source QUADWORD.

qqadd macro qWrd1:req, qWrd2:req
  ifidni <qWrd1>, <edx:eax>
    add eax, (QUADWORD ptr qWrd2).LoDWord
    adc edx, (QUADWORD ptr qWrd2).HiDWord
  elseifidni <qWrd2>, <edx:eax>
    add (QUADWORD ptr qWrd1).LoDWord, eax
    adc (QUADWORD ptr qWrd1).HiDWord, edx
  else
    push eax
    push edx
    mov eax, (QUADWORD ptr qWrd2).LoDWord
    mov edx, (QUADWORD ptr qWrd2).HiDWord
    add (QUADWORD ptr qWrd1).LoDWord, eax
    adc (QUADWORD ptr qWrd1).HiDWord, edx
    pop edx
    pop eax
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qdsub
; Purpose:    Subtract a DoubleWord from a QUADWORD (qWrd = qWrd - dWrd).
; Arguments:  Arg1: Destination QUADWORD.
;             Arg2: Source DoubleWord.

qdsub macro qWrd:req, dWrd:req
  ifidni <qWrd>, <edx:eax>
    sub eax, dWrd
    sbb edx, 0
  else
    if (opattr dWrd) and 00010000b                      ;;is it a register?
      sub (QUADWORD ptr qWrd).LoDWord, dWrd
      sbb (QUADWORD ptr qWrd).HiDWord, 0
    else
      push ecx
      mov ecx, dWrd
      sub (QUADWORD ptr qWrd).LoDWord, ecx
      sbb (QUADWORD ptr qWrd).HiDWord, 0
      pop ecx
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qqsub
; Purpose:    Subtract 2 QuadWords (qWrd1 = qWrd1 - qWrd2).
; Arguments:  Arg1: Destination QUADWORD.
;             Arg2: Source QUADWORD.

qqsub macro qWrd1:req, qWrd2:req
  ifidni <qWrd1>, <edx:eax>
    sub eax, (QUADWORD ptr qWrd2).LoDWord
    sbb edx, (QUADWORD ptr qWrd2).HiDWord
  elseifidni <qWrd2>, <edx:eax>
    sub (QUADWORD ptr qWrd1).LoDWord, eax
    sbb (QUADWORD ptr qWrd1).HiDWord, edx
  else
    push eax
    push edx
    mov eax, (QUADWORD ptr qWrd2).LoDWord
    mov edx, (QUADWORD ptr qWrd2).HiDWord
    sub (QUADWORD ptr qWrd1).LoDWord, eax
    sbb (QUADWORD ptr qWrd1).HiDWord, edx
    pop edx
    pop eax
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qdmul
; Purpose:    Multiply a QUADWORD by a DoubleWord.
; Arguments:  ecx:edx:eax = edx:eax * ebx.

qdmul macro
  push eax
  mov eax, edx
  mul ebx
  mov ecx, edx
  pop edx
  xchg eax, edx
  push edx
  mul ebx
  pop ebx
  add edx, ebx
  adc ecx, 0
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qddiv
; Purpose:    Divide a QUADWORD by a DoubleWord. Uses ecx.
;             Output: edx:eax = quotient of division of dividend by divisor
;                          ebx = remainder of division of dividend by divisor
; Arguments:  edx:eax = dividend
;                  ebx = divisor

qddiv macro
  .if edx == 0                                          ;;only one division needed?
    div ebx                                             ;;yes, one division sufficient
    mov ebx, edx                                        ;;eax = quotient-lo, ebx = remainder
    xor edx, edx                                        ;;edx = quot.-hi(quotient in edx:eax)
  .else
    mov ecx, eax                                        ;;save dividend-lo in ecx
    mov eax, edx                                        ;;get dividend-hi
    xor edx, edx                                        ;;zero extend it into edx:eax
    div ebx                                             ;;quotient-hi in eax
    xchg eax, ecx                                       ;;ecx = quotient-hi, eax =dividend-lo
    div ebx                                             ;;eax = quotient-lo
    mov ebx, edx                                        ;;ebx = remainder
    mov edx, ecx                                        ;;edx = quot.-hi(quotient in edx:eax)
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      qqdiv
; Purpose:    Divide 2 unsigned QuadWords. Uses edi, esi.
;             Output:  edx:eax = quotient of division of dividend by divisor
;                      ecx:ebx = remainder of division of dividend by divisor
; Arguments:  edx:eax = dividend
;             ecx:ebx = divisor

qqdiv macro
  local @@Exit

  test ecx, ecx                                         ;;check if ecx is zero
  jnz @F
  qddiv                                                 ;;Perform qddiv
  xor ecx, ecx                                          ;;ecx = remainder-hi = zero
  jmp @@Exit
@@:
  push edx                                              ;;save
  push eax                                              ;; dividend
  mov esi, ebx                                          ;;divisor now in
  mov edi, ecx                                          ;; edi:ebx and ecx:esi
  shr edx, 1                                            ;;shift both
  rcr eax, 1                                            ;; divisor and
  ror edi, 1                                            ;;  and dividend
  rcr ebx, 1                                            ;;   right by 1 bit
  bsr ecx, ecx                                          ;;ecx = number of remaining shifts
  shrd ebx, edi, cl                                     ;;scale down divisor and
  shrd eax, edx, cl                                     ;;  dividend such that divisor
  shr edx, cl                                           ;;   less than 2^32 (i.e. fits in ebx)
  rol edi, 1                                            ;;restore original divisor (edi:esi)
  div ebx                                               ;;compute quotient
  pop ebx                                               ;;get dividend lo-word
  mov ecx, eax                                          ;;save quotient
  imul edi, eax                                         ;;quotient * divisor hi-word (low only)
  mul esi                                               ;;quotient * divisor lo-word
  add edx, edi                                          ;;edx:eax = quotient * divisor
  sub ebx, eax                                          ;;dividend-lo - (quot.*divisor)-lo
  mov eax, ecx                                          ;;get quotient
  pop ecx                                               ;;restore dividend hi-word
  sbb ecx, edx                                          ;;subtract divisor * quot. from dividend
  sbb edx, edx                                          ;;0 if remainder > 0, else FFFFFFFFh
  and esi, edx                                          ;;nothing to add
  and edi, edx                                          ;; back if remainder positive
  add ebx, esi                                          ;;correct remaider
  adc ecx, edi                                          ;; and quotient if
  add eax, edx                                          ;;  necessary
  xor edx, edx                                          ;;clear hi-word of quot (eax<=FFFFFFFFh)
@@Exit:

endm
