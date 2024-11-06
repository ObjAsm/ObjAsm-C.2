; ==================================================================================================
; Title:      SLR_Calc_AB_MSE_QW.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

SRC_TYPE textequ <QWORD>
ProcName textequ <SLR_Calc_AB_MSE_QW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SLR_Calc_AB_MSE_QW
; Purpose:    Calculate the Slope (A) and Intercept (B) values of the linear equation y = A*x + B
;             that minimize mean squared error (MSE) and the MSE value of a QWORD array.
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
;             MSE = (Y2 - 2*A*XY - 2*B*Y + A^2*X2 + 2*A*B*X)/N + B^2

% include &ObjMemPath&Common\SLR_Calc_AB_MSE_XP.inc

end