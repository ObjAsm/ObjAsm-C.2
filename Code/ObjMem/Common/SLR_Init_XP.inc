; ==================================================================================================
; Title:      SLR_Init_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, July 2022
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SLR_Init
; Purpose:    Calculate in advance the invariant coefficients of a Simple Linear Regression (X, X2, Q)
; Arguments:  Arg1: -> SLR_DATA structure
; Return:     eax = TRUE is succeeded, otherwise FALSE.
; Links:      https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
;             https://mathschallenge.net/library/number/sum_of_squares
;             https://www.freecodecamp.org/news/machine-learning-mean-squared-error-regression-line-c7dde9a26b93/
; Note:       Since X ranges from [0..N-1], the known formulas have to be adjusted accordingly by
;             replacing N with N-1.
; Formulas:   X = N*(N-1)/2
;             X2 = X*(2*N - 1)/3
;             Q = N^2*(N^2-1)/12

align ALIGN_CODE
SLR_Init proc pSlrData:PSLR_DATA
  ?mov ecx, pSlrData
  xor eax, eax
  .if xcx != NULL
    .if [xcx].SLR_DATA.pData != NULL && [xcx].SLR_DATA.xCount != 0
      fild [xcx].SLR_DATA.xCount    ;   N
      fld st(0)                     ;   N    ,   N
      fmul st(1), st(0)             ;   N    ,  N^2
      fld st(1)                     ;  N^2   ,   N    ,  N^2
      fsub st(0), st(1)             ; N^2-N  ,   N    ,  N^2
      fld1                          ;   1    , N^2-N  ,   N   ,   N^2
      fld1                          ;   1    ,   1    , N^2-N  ,   N   ,   N^2
      faddp st(1), st(0)            ;   2    , N^2-N  ,   N    ,  N^2
      fdiv st(1), st(0)             ;   2    ,   X    ,   N    ,  N^2
      fld1                          ;   1    ,   2    ,   X    ,   N    ,  N^2
      fadd st(0), st(1)             ;   3    ,   2    ,   X    ,   N    ,  N^2
      fld st(3)                     ;   N    ,   3    ,   2    ,   X    ,   N    ,  N^2
      fadd st(0), st(0)             ;  2*N   ,   3    ,   2    ,   X    ,   N    ,  N^2
      fld1                          ;   1    ,  2*N   ,   3    ,   2    ,   X    ,   N    ,  N^2
      fsubp st(1), st(0)            ; 2*N-1  ,   3    ,   2    ,   X    ,   N    ,  N^2
      fmul st(0), st(3)             ;(2*N-1)X,   3    ,   2    ,   X    ,   N    ,  N^2
      fdiv st(0), st(1)             ;  X2    ,   3    ,   2    ,   X    ,   N    ,  N^2
      fstp [xcx].SLR_DATA.r8X2      ;   3    ,   2    ,   X    ,   N    ,  N^2
      fmulp st(1), st(0)            ;   6    ,   X    ,   N    ,  N^2
      fadd st(0), st(0)             ;  12    ,   X    ,   N    ,  N^2
      fld st(3)                     ;  N^2   ,  12    ,   X    ,   N    ,  N^2
      fld1                          ;   1    ,  N^2   ,  12    ,   X    ,   N    ,  N^2
      fsubp st(1), st(0)            ; N^2-1  ,  12    ,   X    ,   N    ,  N^2
      fmulp st(4), st(0)            ;  12    ,   X    ,   N    ,N^2*(N^2-1)
      fdivp st(3), st(0)            ;   X    ,   N    ,   Q
      fstp [xcx].SLR_DATA.r8X       ;   N    ,   Q
      fstp st(0)                    ;   Q
      fstp [xcx].SLR_DATA.r8Q

      ;Set initial values
      if TARGET_BITNESS eq 32
        mov edx, R4_NAN
        mov DWORD ptr [ecx].SLR_DATA.r8Slope, 0
        mov DWORD ptr [ecx + sizeof DWORD].SLR_DATA.r8Slope, edx
        mov DWORD ptr [ecx].SLR_DATA.r8Intercept, 0
        mov DWORD ptr [ecx + sizeof DWORD].SLR_DATA.r8Intercept, edx
        mov DWORD ptr [ecx].SLR_DATA.r8MSE, 0
        mov DWORD ptr [ecx + sizeof DWORD].SLR_DATA.r8MSE, edx
      else
        mov rdx, R8_NAN
        mov [rcx].SLR_DATA.r8Slope, rdx
        mov [rcx].SLR_DATA.r8Intercept, rdx
        mov [rcx].SLR_DATA.r8MSE, rdx
      endif
  
      mov eax, TRUE
    .endif
  .endif
  ret
SLR_Init endp
