; ==================================================================================================
; Title:      SLR_Calc_AB_MSE_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, July 2022
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SLR_Calc_AB_MSE_DW / SLR_Calc_AB_MSE_QW / SLR_Calc_AB_MSE_R4 / SLR_Calc_AB_MSE_R8
; Purpose:    Calculate the Slope (A) and Intercept (B) values of the linear equation y = A*x + B
;             that minimize mean squared error (MSE) and the MSE value.
; Arguments:  Arg1: -> SLR_DATA structure.
; Return:     eax = TRUE is succeeded, otherwise FALSE.
; Links:      https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
;             https://mathschallenge.net/library/number/sum_of_squares
;             https://www.freecodecamp.org/news/machine-learning-mean-squared-error-regression-line-c7dde9a26b93/
; Note:       Since X ranges from [0..N-1], the known formulas have to be adjusted accordingly by
;             replacing N with N-1.
;             If an FPU exception occurs, the results are NaN.
;             This procedure requires 8 free FPU registers.
; Formulas:   A = (XY*N-X*Y)/Q
;             B = (Y-A*X)/N
;             MSE = (Y2 - 2*A*XY - 2*B*Y + A^2*X2 + 2*A*B*X)/N + B^2

ProcName proc pSlrData:PSLR_DATA
  ?mov ecx, pSlrData
  .if xcx != NULL
    mov xdx, [xcx].SLR_DATA.pData
    .if xdx != NULL
      mov xax, [xcx].SLR_DATA.xCount
      fldz                          ;   Y2
      test xax, xax
      fldz                          ;   Y    ,   Y2
      fldz                          ;   XY   ,   Y    ,   Y2
      fld1                          ;   1    ,   XY   ,   Y    ,   Y2
      fldz                          ;   x    ,   1    ,   XY   ,   Y    ,   Y2
      .while !ZERO?
        ifidn @SubStr(%SRC_TYPE, 1, 1), <R>
          fld SRC_TYPE ptr [xdx]    ;   y    ,   1    ,   x    ,   XY   ,   Y    ,   Y2               Load FP value
        else
          fild SRC_TYPE ptr [xdx]   ;   y    ,   1    ,   x    ,   XY   ,   Y    ,   Y2               Load Integer value
        endif
        fadd st(4), st(0)           ;   y    ,   x    ,   1    ,   XY   ,   Y    ,   Y2               Cummulate y on Y
        fld st(0)                   ;   y    ,   y    ,   x    ,   1    ,   XY   ,   Y    ,   Y2
        fmul st(0), st(0)           ;   y2   ,   y    ,   x    ,   1    ,   XY   ,   Y    ,   Y2
        faddp st(6), st(0)          ;   y    ,   x    ,   XY   ,   Y    ,   Y2   ,   1                Cummulate y2 on Y2
        fmul st(0), st(1)           ;  x*y   ,   x    ,   1    ,   XY   ,   Y    ,   Y2
        add xdx, sizeof QWORD
        faddp st(3), st(0)          ;   x    ,   1    ,   XY   ,   Y    ,   Y2                        Cummulate x*y on XY
        dec xax
        fadd st(0), st(1)           ;  x+1   ,   1    ,   XY   ,   Y    ,   Y2                        Increment x by 1
      .endw
      fstp st(1)                    ;  x+1   ,   XY   ,   Y    ,   Y2

      ;At this point we have        ;   N    ,   XY   ,   Y    ,   Y2                                 st(0) = N
      fld st(0)                     ;   N    ,   N    ,   XY   ,   Y    ,   Y2
      fmul st(0), st(2)             ;  N*XY  ,   N    ,   XY   ,   Y    ,   Y2
      fld [xcx].SLR_DATA.r8X        ;   X    ,  N*XY  ,   N    ,   XY   ,   Y    ,   Y2
      fld st(0)                     ;   X    ,   X    ,  N*XY  ,   N    ,   XY   ,   Y    ,   Y2
      fmul st(0), st(5)             ;  X*Y   ,   X    ,  N*XY  ,   N    ,   XY   ,   Y    ,   Y2
      fsubp st(2), st(0)            ;   X    ,N*XY-X*Y,   N    ,   XY   ,   Y    ,   Y2
      fld [xcx].SLR_DATA.r8Q        ;   Q    ,   X    ,N*XY-X*Y,   N    ,   XY   ,   Y    ,   Y2
      fdivp st(2), st(0)            ;   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fld st(0)                     ;   X    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fmul st(0), st(2)             ;  X*A   ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fsubr st(0), st(5)            ; Y-X*A  ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fdiv st(0), st(3)             ;   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2

      ;Check for FPU exceptions
      fstsw ax
      .ifAnyBitSet ax, MASK(fOverflow or fZeroDiv or fDenorm or fInvOp)
        fclex
        fUnload 7
        jmp @Error
      .endif
      fst [xcx].SLR_DATA.r8Intercept

      ;MSE = (Y2 - 2*A*XY - 2*B*Y + A^2*X2 + 2*A*B*X)/N + B^2
      fld st(0)                     ;   B    ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fmul st(0), st(6)             ;  B*Y   ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fadd st(0), st(0)             ; 2*B*Y  ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,   Y2
      fsubp st(7), st(0)            ;   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y
      fld st(2)                     ;   A    ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y
      fmul st(0), st(5)             ;  A*XY  ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y
      fadd st(0), st(0)             ; 2*A*XY ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y
      fsubp st(7), st(0)            ;   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY
      fld [xcx].SLR_DATA.r8X2       ;   X2   ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY
      fmul st(0), st(3)             ;  X2*A  ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY
      fmul st(0), st(3)             ; X2*A^2 ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY
      faddp st(7), st(0)            ;   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2
      fld st(1)                     ;   X    ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2
      fmul st(0), st(3)             ;  X*A   ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2
      fmul st(0), st(1)             ; X*A*B  ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2
      fadd st(0), st(0)             ;2*X*A*B ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2
      faddp st(7), st(0)            ;   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2+2*X*A*B
      fld st(3)                     ;   N    ,   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,Y2-2*B*Y-2*A*XY+x2*A^2+2*X*A*B
      fdivp st(7), st(0)            ;   B    ,   X    ,   A    ,   N    ,   XY   ,   Y    ,(Y2-2*B*Y-2*A*XY+x2*A^2+2*X*A*B)/N
      fmul st(0), st(0)             ;  B^2   ,   X    ,   A    ,   N    ,   XY   ,   Y    ,(Y2-2*B*Y-2*A*XY+x2*A^2+2*X*A*B)/N
      faddp st(6), st(0)            ;   X    ,   A    ,   N    ,   XY   ,   Y    ,(Y2-2*B*Y-2*A*XY+x2*A^2+2*X*A*B)/N+B^2
      fUnload                       ;   A    ,   N    ,   XY   ,   Y    ,(Y2-2*B*Y-2*A*XY+x2*A^2+2*X*A*B)/N+B^2
      fstp [xcx].SLR_DATA.r8Slope
      fUnload 3                     ;  MSE

      ;Check for FPU exceptions again
      fstsw ax
      .ifAllBitsClr ax, MASK(fOverflow or fZeroDiv or fDenorm or fInvOp)
        fstp [xcx].SLR_DATA.r8MSE
        mov eax, TRUE
        ret
      .endif
      fclex
      fUnload
    .endif

@Error:
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
