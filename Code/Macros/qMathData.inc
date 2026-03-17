; ==================================================================================================
; Title:      qMathData.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of quick mathematical operations.
; Note:       Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


.const
Deg2Rad           real8      1.74532925199432950e-0002
Rad2Deg           real8      5.72957795130823228e+0001
Rad2Bit           real8      1.62974661726100833e+0002
Bit2Rad           real8      6.13592315154256500e-0003
Deg2Bit           real8      2.84444444444444444e+0000
Bit2Deg           real8      3.51562500000000000e-0001
ZeroPointFive     real4      0.5
OnePointFive      real4      1.5

.data?                                        ;10 kByte
BitSinTable       real8       256 dup (?)     ;1 quadrant
BitCosTable       real8      1024 dup (?)     ;4 quadrants

qMathAux          dword      ?

