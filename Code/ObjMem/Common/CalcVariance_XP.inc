; ==================================================================================================
; Title:      CalcVariance_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, July 2022
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CalcVarianceDW / CalcVarianceQW / CalcVarianceR4 / CalcVarianceR8
; Purpose:    Calculate the MSE of an array of QWORDs.
; Arguments:  Arg1: -> Array of SRC_TYPEs.
;             Arg2: XWORD Array count.
;             Arg3: -> REAL8 Variance.
; Return:     eax = TRUE is succeeded, otherwise FALSE.
; Links:      https://www.mun.ca/biology/scarr/Simplified_calculation_of_variance.html#:~:text=A%20more%20straightforward%20calculation%20recognizes,i2%20)%20%2F%20n%20%2D%202
;             https://www.mun.ca/biology/scarr/Mean_&_Variance.html#:~:text=easily%20calculated%20as
; Notes:      This procedure requires 4 free FPU registers.
; Formulas:   Var = Y2/N-(Y/N)^2  or  (Y2*N-Y^2)/N^2
;             where Y: Sum(y), Y2: Sum(y^2), N:Population count = Array size.

.code
align ALIGN_CODE
ProcName proc pArray:POINTER, xCount:XWORD, pVariance:POINTER
  ?mov ecx, pArray
  fild xCount                       ;   N
  fldz                              ;   Y    ,   N
  mov xax, xCount
  fldz                              ;   Y2   ,   Y    ,   N
  test xax, xax
  .while !ZERO?
    ifidn @SubStr(%SRC_TYPE, 1, 1), <R>
      fld SRC_TYPE ptr [xcx]        ;   y    ,   Y2   ,   Y    ,   N    Load FP value
    else
      fild SRC_TYPE ptr [xcx]       ;   y    ,   Y2   ,   Y    ,   N    Load Integer value
    endif
    fadd st(2), st(0)               ;   y    ,   Y2   ,   Y    ,   N    Cummulate y^2 on Y2
    add xcx, sizeof(SRC_TYPE)       ;                                   Goto next value
    fmul st(0), st(0)               ;  y^2   ,   Y2   ,   Y    ,   N    Square
    dec xax                         ;                                   Decrement counter
    faddp st(1), st(0)              ;   Y2   ,   Y    ,   N             Cummulate y on Y
  .endw
  fmul st(0), st(2)                 ;  Y2*N  ,   Y    ,   N
  fld st(1)                         ;   Y    ,  Y2*N  ,   Y    ,   N
  fmulp st(2), st(0)                ;  Y2*N  ,   Y^2  ,   N
  fsub st(0), st(1)                 ;Y2*N-Y^2;   Y^2  ,   N
  fld st(2)                         ;   N    ,Y2*N-Y^2,   Y    ,   N
  fmul st(0), st(0)                 ;  N^2   ,Y2*N-Y^2,   Y    ,   N
  fdivp st(1), st(0)                ;  Var   ,   Y    ,   N

  ;Check for FPU exceptions
  mov xdx, pVariance
  fstsw ax
  .ifAnyBitSet ax, MASK(fOverflow or fZeroDiv or fDenorm or fInvOp)
    fclex
    if TARGET_BITNESS eq 32
      mov DWORD ptr [edx], 0
      mov DWORD ptr [edx + sizeof DWORD], R4_NAN
      fUnload
    else
      m2m [rdx], R8_NAN, rax
    endif
    xor eax, eax
  .else
    fstp REAL8 ptr [xdx]
    mov eax, TRUE
  .endif
  fUnload 2
  ret
ProcName endp
