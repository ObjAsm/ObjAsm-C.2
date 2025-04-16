; ==================================================================================================
; Title:      SLR_Calc_AB_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  SLR_Calc_AB_DW / SLR_Calc_AB_QW / SLR_Calc_AB_R4 / SLR_Calc_AB_R8
; Purpose:    Calculate the Slope (A) and Intercept (B) values of the linear equation y = A*x + B
;             that minimize mean squared error (MSE).
; Arguments:  Arg1: -> SLR_DATA structure.
; Return:     eax = TRUE is succeeded, otherwise FALSE.
; Links:      https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
;             https://mathschallenge.net/library/number/sum_of_squares
;             https://www.freecodecamp.org/news/machine-learning-mean-squared-error-regression-line-c7dde9a26b93/
; Note:       Since X ranges from [0..N-1], the known formulas have to be adjusted accordingly by
;             replacing N with N-1.
;             If an FPU exception occurs, the results are NaN.
; Formulas:   A = (XY*N-X*Y)/Q
;             B = (Y-A*X)/N

.code
align ALIGN_CODE
ProcName proc pSlrData:PSLR_DATA
  ?mov ecx, pSlrData
  .if xcx != NULL
    mov xdx, [xcx].SLR_DATA.pData
    .if xdx != NULL
      fldz                          ;   Y
      mov xax, [xcx].SLR_DATA.xCount
      fldz                          ;   XY   ,   Y
      test xax, xax
      fld1                          ;   1    ,   XY   ,   Y
      fldz                          ;   x    ,   1    ,   XY   ,   Y
      .while !ZERO?
        ifidn @SubStr(%SRC_TYPE, 1, 1), <R>
          fld SRC_TYPE ptr [xdx]    ;   y    ,   x    ,   1    ,   XY   ,   Y     Load FP value
        else
          fild SRC_TYPE ptr [xdx]   ;   y    ,   x    ,   1    ,   XY   ,   Y     Load Integer value
        endif
        fadd st(4), st(0)           ;   y    ,   x    ,   1    ,   XY   ,   Y     Cummulate y on Y
        fmul st(0), st(1)           ;  x*y   ,   x    ,   1    ,   XY   ,   Y
        add xdx, sizeof QWORD
        faddp st(3), st(0)          ;   x    ,   1    ,   XY   ,   Y              Cummulate x*y on XY
        dec xax
        fadd st(0), st(1)           ;  x+1   ,   1    ,   XY   ,   Y              Increment x by 1
      .endw
      fstp st(1)

      ;At this point we have        ;   N    ,   XY   ,   Y                       st(0) = N
      fmul st(1), st(0)             ;   N    ,  N*XY  ,   Y
      fld [xcx].SLR_DATA.r8X        ;   X    ,   N    ,  N*XY  ,   Y
      fld st(0)                     ;   X    ,   X    ,   N    ,  N*XY  ,   Y
      fmul st(0), st(4)             ;  X*Y   ,   X    ,   N    ,  N*XY  ,   Y
      fsubp st(3), st(0)            ;   X    ;   N    ,N*XY-X*Y,   Y
      fld [xcx].SLR_DATA.r8Q        ;   Q    ,   X    ,   N    ,XY-X*Y/N,   Y
      fdivp st(3), st(0)            ;   X    ,   N    ,   A    ,   Y
      fmul st(0), st(2)             ;  A*X   ,   N    ,   A    ,   Y
      fsubp st(3), st(0)            ;   N    ,   A    , Y-A*X
      fdivp st(2), st(0)            ;   A    ,   B

      ;Check for FPU exceptions
      fstsw ax
      .ifAllBitsClr ax, MASK(fOverflow or fZeroDiv or fDenorm or fInvOp)
        fstp [xcx].SLR_DATA.r8Slope
        fstp [xcx].SLR_DATA.r8Intercept
        if TARGET_BITNESS eq 32
          mov DWORD ptr [xcx].SLR_DATA.r8MSE, 0
          mov DWORD ptr [xcx + sizeof DWORD].SLR_DATA.r8MSE, R4_NAN
        else
          m2m [rcx].SLR_DATA.r8MSE, R8_NAN, rax
        endif
        mov eax, TRUE
        ret
      .endif
      fclex
      fUnload 2
    .endif
    if TARGET_BITNESS eq 32
      mov edx, R4_NAN
      mov DWORD ptr [ecx].SLR_DATA.r8Slope, 0           ;Fill upper part of REAL8 with 0
      mov DWORD ptr [ecx + sizeof DWORD].SLR_DATA.r8Slope, edx
      mov DWORD ptr [ecx].SLR_DATA.r8Intercept, 0       ;Fill upper part of REAL8 with 0
      mov DWORD ptr [ecx + sizeof DWORD].SLR_DATA.r8Intercept, edx
      mov DWORD ptr [ecx].SLR_DATA.r8MSE, 0             ;Fill upper part of REAL8 with 0
      mov DWORD ptr [ecx + sizeof DWORD].SLR_DATA.r8MSE, edx
    else
      mov rdx, R8_NAN
      mov [rcx].SLR_DATA.r8Slope, rdx
      mov [rcx].SLR_DATA.r8Intercept, rdx
      mov [rcx].SLR_DATA.r8MSE, rdx
    endif
  .endif
  xor eax, eax
  ret
ProcName endp
