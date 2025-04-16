; ==================================================================================================
; Title:      CalcVarianceDW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

SRC_TYPE equ <DWORD>
ProcName textequ <CalcVarianceDW>

; --------------------------------------------------------------------------------------------------
; Procedure:  CalcVarianceDW
; Purpose:    Calculate the MSE of an array of DWORDs.
; Arguments:  Arg1: -> Array of DWORDs.
;             Arg2: QWORD Array count.
;             Arg3: -> Variance.
; Return:     eax = TRUE is succeeded, otherwise FALSE.
; Links:      https://www.mun.ca/biology/scarr/Simplified_calculation_of_variance.html#:~:text=A%20more%20straightforward%20calculation%20recognizes,i2%20)%20%2F%20n%20%2D%202
;             https://www.mun.ca/biology/scarr/Mean_&_Variance.html#:~:text=easily%20calculated%20as
; Formulas:   Var = Y2/N-(Y/N)^2  or  (Y2*N-Y^2)/N^2
;             where Y: Sum(y), Y2: Sum(y^2), N:Population count = Array size.

% include &ObjMemPath&Common\CalcVariance_XP.inc

end