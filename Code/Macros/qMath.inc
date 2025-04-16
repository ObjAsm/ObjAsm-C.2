; ==================================================================================================
; Title:      qMath.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of quick mathematical operations.
; Links:      http://bmath.net/bmath/index.html
;             http://www.asmcommunity.net/board/index.php?topic=21430.15
;             http://www.masm32.com/board/index.php?topic=4765.0
;             http://www.groupsrv.com/computers/post-561737.html
;             http://en.wikipedia.org/wiki/Methods_of_computing_square_roots
; Note:       Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; Trigonometric approximation macros
; ----------------------------------
;
; All macros are designed to have a chance for reentrancy if you supply a local argument
; to store an intermediate result. If it is not supplied, a global variable is used!
;
; The trig macros use the bittian angle unit (2*PI = 1024 Bittians).
; The computation is based on Taylor series which has a fast convergence and a sin LUT.
;
; The speed factor using 3 terms is aprox. 7.0 times compared to fsin/fcos and
;  5.9 times for qSinCos compared to fSinCos. This values may change on different hardwares.
; The maximal error over the (0.0 .. 1024.0) input range is max(|Error|) < 5.0E-9.
;
; f(x+h) = f(x) + hf'(x)/1! + (h^2)f''(x)/2! + ...
;
; d(sin) = cos, and d(cos) = -sin
; sin(x+h) = sin(x) + h cos(x) - h^2 sin(x) / 2 + ...
;
; d(cos) = -sin, and d(sin) = cos
; cos(x+h) = cos(x) - h sin(x) - h^2 cos(x) / 2 + ...


; Square Root approximation macros
; --------------------------------
;
; The RcpSqrt macro uses Newton's approximation algo in combination with the Quake3 first guess.
; The speed factor using 3 iterations varies from 1.35 to 2.2 times depending on the hardware
; compared to 1/fsqrt.
; The number of Newton iteration defaults to 3 for a good approximation.


RAD2BIT equ <+1.62974661726100833e+0002>
BIT2RAD equ <+6.13592315154256500e-0003>
DEG2BIT equ <+2.84444444444444444e+0000>
BIT2DEG equ <+3.51562500000000000e-0001>

.data?                                ;10 kByte
BitSinTable   REAL8     256 dup (?)   ;1 quadrant
BitCosTable   REAL8    1024 dup (?)   ;4 quadrants

qMathAux      DWORD    ?

; --------------------------------------------------------------------------------------------------
; Macro:      qMathInit
; Purpose:    Initialize internal trigonometric tables.
; Arguments:  Arg1: temporary DWORD value.
; Return:     Nothing.

qMathInit macro Aux:=<qMathAux>
  ;Init sin/cos table
  xor eax, eax
  .while eax < 1280                   ;;5 quadrants
    mov Aux, eax
    fild Aux
    fmul $CReal8(%BIT2RAD)
    fsin
    fstp [BitSinTable + 8*eax]
    inc eax
  .endw
endm

; --------------------------------------------------------------------------------------------------
; Macro:      qSin
; Purpose:    Compute the sin of a bittian value.
; Arguments:  Arg1: Number of terms [1..3] used to compute the taylor series.
;             Arg2: Temporary DWORD value.
; Return:     sin value in st(0).

qSin macro Terms:=<3>, Aux:=<qMathAux>
  if Terms eq 1
    fistp Aux                         ;;Save the integer part of bitian in temporary storage
    mov eax, Aux
    and eax, 000003FFh                ;;Keep the last 10 bits
    fld [BitSinTable + 8*eax]
  else
    fist Aux                          ;;Save the integer part of bitian in temporary storage
    fisub Aux                         ;;tos contains fractional part of bitian
    mov eax, Aux
    fmul $CReal8(%BIT2RAD)            ;;Convert from bittians to radians for 2nd taylor series term
    and eax, 000003FFh                ;;Keep the last 10 bits
    if Terms eq 2
      fmul [BitCosTable + 8*eax]
      fadd [BitSinTable + 8*eax]
    else
      fld st(0)
      fmul [BitSinTable + 8*eax]
      fmul $CReal4(+0.5)              ;;Divide by 2 to complete 3rd term of taylor series
      fsub [BitCosTable + 8*eax]
      fmulp st(1), st(0)
      fld [BitSinTable + 8*eax]
      fsubrp st(1), st(0)
    endif
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      qCos
; Purpose:    Compute the cos of a bittian value.
; Arguments:  Arg1: Number of terms [1..3] used to compute the taylor series.
;             Arg2: Temporary DWORD value.
; Return:     cos value in st(0).

qCos macro Terms:=<3>, Aux:=<qMathAux>
  if Terms eq 1
    fistp Aux                         ;;Save the integer part of bitian in temporary storage
    mov eax, Aux
    and eax, 000003FFh                ;;Keep the last 10 bits
    fld [BitCosTable + 8*eax]
  else
    fist Aux                          ;;Save the integer part of bitian in temporary storage
    fisub Aux                         ;;tos contains fractional part of bitian
    mov eax, Aux
    fmul $CReal8(%BIT2RAD)            ;;Convert from bittians to radians for 2nd taylor series term
    and eax, 000003FFh                ;;Keep the last 10 bits
    if Terms eq 2
      fmul [BitSinTable + 8*eax]
      fsubr [BitCosTable + 8*eax]
    else
      fld st(0)
      fmul [BitCosTable + 8*eax]
      fmul $CReal4(+0.5)              ;;Divide by 2 to complete 3rd term of taylor series
      fadd [BitSinTable + 8*eax]
      fmulp st(1), st(0)
      fld [BitCosTable + 8*eax]
      fsubrp st(1), st(0)
    endif
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      qSinCos
; Purpose:    Compute the sin and cos of a bittian value.
; Arguments:  Arg1: Number of terms [1..3] used to compute the taylor series.
;             Arg2: Temporary DWORD value.
; Return:     sin value in st(1).
;             cos value in st(0).

qSinCos macro Terms:=<3>, Aux:=<qMathAux>
  if Terms eq 1
    fistp Aux                         ;;Save the integer part of bitian in temporary storage
    mov eax, Aux
    and eax, 000003FFh                ;;Keep the last 10 bits
    fld [BitSinTable + 8*eax]
    fld [BitCosTable + 8*eax]
  else
    fist Aux                          ;;Save the integer part of bitian in temporary storage
    fisub Aux                         ;;tos contains fractional part of bitian
    mov eax, Aux
    fmul $CReal8(%BIT2RAD)            ;;Convert from bittians to radians for 2nd taylor series term
    and eax, 000003FFh                ;;Keep the last 10 bits
    fld st(0)
    if Terms eq 2
      fmul [BitCosTable + 8*eax]
      fadd [BitSinTable + 8*eax]
      fxch
      fmul [BitSinTable + 8*eax]
      fsubr [BitCosTable + 8*eax]
    else
      fmul [BitSinTable + 8*eax]
      fmul $CReal4(+0.5)              ;;Divide by 2 to complete 3rd term of taylor series
      fsub [BitCosTable + 8*eax]
      fmul st(0), st(1)
      fld [BitSinTable + 8*eax]
      fsubrp st(1), st(0)
      fxch
      fld st(0)
      fmul [BitCosTable + 8*eax]
      fmul $CReal4(+0.5)              ;;Divide by 2 to complete 3rd term of taylor series
      fadd [BitSinTable + 8*eax]
      fmulp st(1), st(0)
      fld [BitCosTable + 8*eax]
      fsubrp st(1), st(0)
    endif
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      qCosSin
; Purpose:    Compute the cos and sin of a bittian value.
; Arguments:  Arg1: Number of terms [1..3] used to compute the taylor series.
;             Arg2: Temporary DWORD value.
; Return:     cos value in st(1).
;             sin value in st(0).

qCosSin macro Terms:=<3>, Aux:=<qMathAux>
  if Terms eq 1
    fistp Aux                         ;;Save the integer part of bitian in temporary storage
    mov eax, Aux
    and eax, 000003FFh                ;;Keep the last 10 bits
    fld [BitCosTable + 8*eax]
    fld [BitSinTable + 8*eax]
  else
    fist Aux                          ;;Save the integer part of bitian in temporary storage
    fisub Aux                         ;;tos contains fractional part of bitian
    mov eax, Aux
    fmul $CReal8(%BIT2RAD)            ;;Convert from bittians to radians for 2nd taylor series term
    and eax, 000003FFh                ;;Keep the last 10 bits
    fld st(0)
    if Terms eq 2
      fmul [BitSinTable + 8*eax]
      fsubr [BitCosTable + 8*eax]
      fxch
      fmul [BitCosTable + 8*eax]
      fadd [BitSinTable + 8*eax]
    else
      fmul [BitCosTable + 8*eax]
      fmul $CReal4(+0.5)              ;;Divide by 2 to complete 3rd term of taylor series
      fadd [BitSinTable + 8*eax]
      fmul st(0), st(1)
      fld [BitCosTable + 8*eax]
      fsubrp st(1), st(0)
      fxch
      fld st(0)
      fmul [BitSinTable + 8*eax]
      fmul $CReal4(+0.5)              ;;Divide by 2 to complete 3rd term of taylor series
      fsub [BitCosTable + 8*eax]
      fmulp st(1), st(0)
      fld [BitSinTable + 8*eax]
      fsubrp st(1), st(0)
    endif
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      qRcpSqrt
; Purpose:    Compute the reciprocal sqrt of st(0) value.
; Arguments:  Arg1: Number of iterations [0..3]. -1 means using the fpu equivalent instructions.
;             Arg2: temporary DWORD value.
; Return:     1/sqrt in st(0).

qRcpSqrt macro Iterations:=<3>, Aux:=<qMathAux>   ;2.2 times faster than 1/fsqrt(x)
  if Iterations eq -1
    fsqrt
    fld1
    fdivrp st(1), st(0)
  else
    ;Compute guess
    fst Aux
    fmul $CReal4(+0.5)                ;;0.5*x
    mov eax, Aux
    sar eax, 1
    mov ecx, 5F3759DFh
    sub ecx, eax
    mov Aux, ecx                      ;;i = 0x5f3759df - (i>>1)
    fld Aux                           ;;i                   0.5*x

    ;Compute N-1 approximations
    if Iterations gt 1
      repeat Iterations-1
        fld st(0)                     ;;i                   i           0.5*x
        fmul st(0), st(0)             ;;i*i                 i           0.5*x
        fmul st(0), st(2)             ;;0.5*x*i*i           i           0.5*x
        fsubr $CReal4(+1.5)           ;;1.5-0.5*x*i*i       i           0.5*x
        fmulp st(1), st(0)            ;;i*(1.5-0.5*x*i*i)   0.5*x
      endm
    endif

    ;Compute Nth approximation
    fxch st(1)                        ;;0.5*x               i
    fld st(1)                         ;;i                   0.5*x       i
    fmul st(0), st(0)                 ;;i*i                 0.5*x       i
    fmulp st(1), st(0)                ;;0.5*x*i*i           i
    fsubr $CReal4(+1.5)               ;;1.5-0.5*x*i*i
    fmulp st(1), st(0)                ;;i*(1.5-0.5*x*i*i)
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      qSqrt
; Purpose:    Compute the sqrt of st(0) value.
; Arguments:  Arg1: Number of iterations [0..3]. -1 means using the fpu equivalent instructions.
;             Arg2: temporary DWORD value.
; Return:     1/sqrt in st(0).

qSqrt macro Iterations:=<3>, Aux:=<qMathAux>    ;;Nothing better atm :(
  if Iterations eq -1
    fsqrt
  else
    fld st(0)                         ;;sqrt(x) = x * 1/sqrt(x)
    qRcpSqrt Iterations, Aux
    fmulp st(1), st(0)
  endif
endm
