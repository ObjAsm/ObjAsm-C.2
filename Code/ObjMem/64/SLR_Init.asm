; ==================================================================================================
; Title:      SLR_Init.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

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

% include &ObjMemPath&Common\SLR_Init_XP.inc

end