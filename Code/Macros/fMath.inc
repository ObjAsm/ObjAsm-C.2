; ==================================================================================================
; Title:      fMath.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of floating point mathematical macros.
; Link:       http://www.rism.com/Trig/Trig02.htm
; Note:       Based on the work of Eóin O'Callaghan [Eóin] and bitRAKE.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================

; Remark: The IEEE format uses a bias for the exponent - 7Fh for REAL4 format.
;         This bias allows floating point numbers to be compared with integer compares!
;         An exponent of 7Fh is zero - note the one bit is implied - so the number is one (1).

;General purpose functions
;fildReg          Load a CPU register containing an integer onto the FPU stack.
;fistReg          Store the integer part of the FPU st(0) register to a CPU register.
;fistpReg         Store the integer part of the FPU st(0) register to a CPU register & pops it.
;fldReg           Load a CPU register containing a REAL4 onto the FPU stack.
;fstReg           Store the FPU st(0) register to a CPU register in REAL4 format.
;fstpReg          Store and pops the FPU st(0) register to a CPU register in REAL4 format.
;fSgn             Compute {if st0 < 0 => -1, if st0 = 0 => 0, if st0 > 0 => 1}.
;fCheckStatus     Check the status word of the FPU to detect fp computation errors.
;fGetFlags        Set EFlags with FPU status flags.
;fUnload          Unload several stack registers.
;fSetPrecision    Set the precision bits in the control register.
;MULTI_FPU        Condense FPU instructions onto one line.
;fMin             Return the smallest value of 2 floats.
;fMax             Return the largeest value of 2 floats.
;fAbsMin          Return the absolute smallest value of 2 floats.
;fAbsMax          Return the absolute largest value of 2 floats.

;Rounding functions
;fRnd             Round to an integer the content of st0.
;fRndUp           Round up to an integer the content of st0.
;fRndDn           Round down to an integer the content of st0.
;fInt             Compute the integer part of the content of st0.
;fFrac            Compute the fractional part of the content of st0.
;fRound           Round the content of st0 to x decimals.

;Power functions
;fExp2            Compute 2^x = 2^st0.
;fExpN            Compute e^x = e^st0.
;fPower           Compute x^y = st0^st(1).
;fLogN            Compute the neperian logarithm of st0.
;fExpT            Compute 10^x = 10^st0.
;fLogT            Compute the logarithm base 10 of st0.
;fLog             Compute Log(st0, st1) = Log2(st0)/Log2(st1).

;Trigonometric functions (Argument range |x| < 2^63 in radians)
;fFitTrigRange    Reduces the value in st0 to fit in the range of trig. functions: |x| < 2^63.
;fTan             Compute tan(st0).
;fSec             Compute 1 / cos(st0).
;fCsc             Compute 1 / sin(st0).
;fCot             Compute 1 / tan(st0).

;Inverse trigonometric functions (Argument range |x| <= 1, return value in radians)
;fArcSin          Compute arctan(st0 / sqrt((1 - st0)(1 + st0))).
;fArcCos          Compute arctan(sqrt((1 - st0)(1 + st0)) / st0).
;fArcTan          Compute arctan(st0).
;fArcSec          Compute arctan(sqrt((st0 - 1)(st0 + 1))).
;fArcCsc          Compute arctan(1 / sqrt((st0 - 1)(st0 + 1))).
;fArcCot          Compute arctan(1 / st0).

;Hyperbolic functions
;fSinh            Compute (exp(st0) - exp(-st0)) / 2.
;fCosh            Compute (exp(st0) + exp(-st0)) / 2.
;fTanh            Compute (exp(st0) - exp(-st0)) / (exp(st0) + exp(-st0)).
;fSech            Compute 2 / (exp(st0) + exp(-st0)).
;fCsch            Compute 2 / (exp(st0) - exp(-st0)).
;fCoth            Compute (exp(st0) + exp(-st0)) / (exp(st0) - exp(-st0)).

;Inverse Hyperbolic functions
;fArcSinh         Compute logN(st0 + Sqr(st0 * st0 + 1)).
;fArcCosh         Compute logN(st0 + Sqr(st0 * st0 - 1)).
;fArcTanh         Compute logN((1 + st0) / (1 - st0)) / 2.
;fArcSech         Compute logN((Sqr(-st0 * st0 + 1) + 1) / st0).
;fArcCsch         Compute logN((1 + sqrt(1 + st0*st0)) / st0).
;fArcCoth         Compute logN((st0 + 1) / (st0 - 1)) / 2.

;String representation
;fldStr           Load in st0 the pointed string representation of a floating point number.
;fstStr           Store in memory the string representation of the FP number in st0.

;Condition jumps
;fjg              Jump if Greater.
;fjl              Jump if Less.
;fje              Jump if Equal.
;fjne             Jump if Not Equal.
;fjge             Jump if Greater or Equal.
;fjle             Jump if Less or Equal.
;fjnc             Jump if Non-Comparable.

;CPU REAL4 comparison
;fcmp             Fast way to compare floats with sign using the CPU.
;fIsZero          Fast way to determine if a float is zero.
;fIsNegative      Fast way to determine if a float is negative.
;fIsPositive      Fast way to determine if a float is positive.

;Comparisons
;fIsLess          Compare 2 floats and set eax to TRUE if the 1st < 2nd.
;fIsLessOrEqual   Compare 2 floats and set eax to TRUE if the 1st <= 2nd.
;fIsGreater       Compare 2 floats and set eax to TRUE if the 1st > 2nd.
;IsGreaterOrEqual Compare 2 floats and set eax to TRUE if the 1st >= 2nd.
;fIsAbsLess       Compare 2 floats and set eax to TRUE if the |1st| < |2nd|.
;fIsAbsGreater    Compare 2 floats and set eax to TRUE if the |1st| > |2nd|.


fStatusWord record fIsBusy:1, fC3:1, fStackPtr:3, fC2:1, fC1:1, fC0:1, fExpt:1, fStackFault:1, \
                   fPrecision:1, fUnderflow:1, fOverflow:1, fZeroDiv:1, fDenorm:1, fInvOp:1

f_OK                equ   0
f_ERROR             equ   1
f_INFP              equ   2
f_INFN              equ   3
f_NAN               equ   4
f_DENOR             equ   5

f_NOR               equ   0
f_STD               equ   0
f_SCI               equ   BIT00
f_TRIM              equ   BIT01
f_ALIGN             equ   BIT02
f_PLUS              equ   BIT03

DEG2RAD equ <+1.7453292519943295769236907684890e-0002>
RAD2DEG equ <+5.7295779513082320876798154814105e+0001>
HALF_PI equ <+1.5707963267948966192313216916398e+0000>
PI      equ <+3.1415926535897932384626433832795e+0000>
TWO_PI  equ <+6.2831853071795864769252867665590e+0000>

R4_MAX  equ <+3.402823466e+38>                          ;07F7FFFFFh
R4_MIN  equ <-R4_MAX>                                   ;0FF7FFFFFh
R4_NAN  equ <07FF80000h>                                ;07FF80000h
R8_MAX  equ <+1.7976931348623158e+308>                  ;07FEFFFFFFFFFFFFFh
R8_MIN  equ <-R8_MAX>                                   ;0FFEFFFFFFFFFFFFFh
R8_NAN  equ <07FF8000000000000h>                        ;07FF8000000000000h
R10_MAX equ <+1.189731495357231765e+4932>               ;07FFEFFFFFFFFFFFFFFFFh
R10_MIN equ <-R10_MAX>                                  ;0FFFEFFFFFFFFFFFFFFFFh
r10_NAN equ <07FF80000000000000000h>                    ;07FF80000000000000000h

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fildReg
; Purpose:    Load a CPU register containing an integer onto the FPU stack.
; Arguments:  Arg1: Register name.
; Return:     Nothing.
; Note:       st7 must be empty.

fildReg macro RegName:req
  if (opattr RegName) and OAT_REGISTER                  ;;is RegName a register?
    ??RegSize = type(RegName)
    if ??RegSize eq @WordSize
      push RegName
      fild XWORD ptr [xsp]
    else
      sub xsp, @WordSize
      mov [xsp], RegName
      if ??RegSize eq 4
        fild DWORD ptr [xsp]
      elseif ??RegSize eq 2
        fild WORD ptr [xsp]
      elseif ??RegSize eq 1
        fild BYTE ptr [xsp]
      endif
    endif
    add xsp, @WordSize
  else
    .err <fildReg - argument is not a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fistReg
; Purpose:    Store the integer part of the FPU st(0) register to a CPU register.
; Arguments:  Arg1: Register name.
; Return:     Nothing.

fistReg macro RegName:req
  if (opattr RegName) and OAT_REGISTER    ;;is RegName a register?
    ??RegSize = type(RegName)
    sub xsp, @WordSize
    if ??RegSize eq @WordSize
      fist XWORD ptr [xsp]
      pop RegName
    else
      if ??RegSize eq 4
        fist DWORD ptr [xsp]
      elseif ??RegSize eq 2
        fist WORD ptr [xsp]
      elseif ??RegSize eq 1
        fist BYTE ptr [xsp]
      endif
      mov RegName, [xsp]
      add xsp, @WordSize
    endif
  else
    .err <fistReg - argument is not a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fistpReg
; Purpose:    Store the integer part of the FPU st(0) register to a CPU register & pops it.
; Arguments:  Arg1: Register name.
; Return:     Nothing.

fistpReg macro RegName:req
  if (opattr RegName) and OAT_REGISTER    ;;is RegName a register?
    ??RegSize = type(RegName)
    sub xsp, @WordSize
    if ??RegSize eq @WordSize
      fistp XWORD ptr [xsp]
      pop RegName
    else
      if ??RegSize eq 4
        fistp DWORD ptr [xsp]
      elseif ??RegSize eq 2
        fistp WORD ptr [xsp]
      elseif ??RegSize eq 1
        fistp BYTE ptr [xsp]
      endif
      mov RegName, [xsp]
      add xsp, @WordSize
    endif
  else
    .err <fistpReg - argument is not a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fldReg
; Purpose:    Load a CPU register containing a REAL4 onto the FPU stack.
; Arguments:  Arg1: Register name.
; Return:     Nothing.
; Note:       st7 must be empty.

fldReg macro RegName:req
  if (opattr RegName) and OAT_REGISTER                  ;;is RegName a register?
    ??RegSize = type(RegName)
    if ??RegSize eq @WordSize
      push RegName
      fld XWORD ptr [xsp]
    else
      sub xsp, @WordSize
      mov [xsp], RegName
      if ??RegSize eq 4
        fld DWORD ptr [xsp]
      elseif ??RegSize eq 2
        fld WORD ptr [xsp]
      elseif ??RegSize eq 1
        fld BYTE ptr [xsp]
      endif
    endif
    add xsp, @WordSize
  else
    .err <fldReg - argument is not a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fstReg
; Purpose:    Store the FPU st(0) register to a CPU register in REAL4 format.
; Arguments:  Arg1: Register name.
; Return:     Nothing.

fstReg macro RegName:req
  if (opattr RegName) and OAT_REGISTER                  ;;is RegName a register?
    ??RegSize = type(RegName)
    sub xsp, @WordSize
    if ??RegSize eq @WordSize
      fst XWORD ptr [xsp]
      pop RegName
    else
      if ??RegSize eq 4
        fst DWORD ptr [xsp]
      elseif ??RegSize eq 2
        fst WORD ptr [xsp]
      elseif ??RegSize eq 1
        fst BYTE ptr [xsp]
      endif
      mov RegName, [xsp]
      add xsp, @WordSize
    endif
  else
    .err <fstReg - argument is not a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fstpReg
; Purpose:    Store and pops the FPU st(0) register to a CPU register in REAL4 format.
; Arguments:  Arg1: Register name.
; Return:     Nothing.

fstpReg macro RegName:req
  if (opattr RegName) and OAT_REGISTER                  ;;is RegName a register?
    ??RegSize = type(RegName)
    sub xsp, @WordSize
    if ??RegSize eq @WordSize
      fstp XWORD ptr [xsp]
      pop RegName
    else
      if ??RegSize eq 4
        fstp DWORD ptr [xsp]
      elseif ??RegSize eq 2
        fstp WORD ptr [xsp]
      elseif ??RegSize eq 1
        fstp BYTE ptr [xsp]
      endif
      mov RegName, [xsp]
      add xsp, @WordSize
    endif
  else
    .err <fstpReg - argument is not a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fSgn
; Purpose:    Compute the signum function of the content os st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.
;             Requires .586 option for the fcomip instruction.
;             Uses rax register.

fSgn macro
  sub xsp, @WordSize                                    ;;Reserve stack place
  fldz                                                  ;;Load zero in st0
  xor eax, eax                                          ;;Load zero in xax
  fcomip st(0), st(1)                                   ;;Compare st0 and st1 and pop st0
  cmova eax, $CReal4(-1.0)                              ;;Move if above
  cmovb eax, $CReal4(+1.0)                              ;;Move if below
  fstp st(0)                                            ;;Pop st0 from stack
  mov [xsp], xax                                        ;;Load result in reserved room in stack
  fld XWORD ptr [xsp]                                   ;;Load result in st0 from stack
  add xsp, @WordSize                                    ;;Restore stack
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fCheckStatus
; Purpose:    Check the status word of the FPU to detect fp computation errors.
; Arguments:  Arg1: Status bit(s) to be checked.
; Return:     Nothing.
; Note:       The result affects the zero flag, that can be used to decide.

fCheckStatus macro StatusBits:req
  push xax                                              ;;Save xax
  fstsw ax                                              ;;Store status word
  test ax, StatusBits                                   ;;Test the requested StatusWord bit
  pop xax                                               ;;Restore xax without changing flags!
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fGetFlags
; Purpose:    Set EFlags with FPU StatusWord flags.
; Arguments:  None.
; Return:     Nothing.
; Note:       Uses ax.

fGetFlags macro

;               15                    8
;               +———————————————————————+
;       +—————— |  |C3|  |  |  |C2|C1|C0|   Coprocessor StatusWord register
;       |       +———————————————————————+
;       |
;       |         7                    0
;       |       +———————————————————————+
;       +—> ... |SF|ZF|??|AF|??|PF|01|CF|   Processor EFlags register
;               +———————————————————————+
;
;                           C3    C2    C0
;      If st(0) > source     0     0     0
;      If st(0) < source     0     0     1
;      If st(0) = source     1     0     0
;      If st(0) ? source     1     1     1
;                           ZF    PF    CF

  fnstsw ax                                             ;;Store status word
  sahf                                                  ;;Set EFlags
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fSetPrecision
; Purpose:    Set the precision bits in the control register.
; Arguments:  Arg1: Precision (REAL4, REAL8, REAL10).
; Return:     Nothing.
; Notes:      00 = 24 bits (REAL4)
;             01 = Not used
;             10 = 53 bits (REAL8)
;             11 = 64 bits (REAL10) (this is the initialized state)

fSetPrecision macro Precision:req
  sub xsp, @WordSize                                    ;;Reserve stack place
  fstcw WORD ptr [xsp]                                  ;;Store FPU control word
  ifidni <Precision>, <REAL4>                           ;;Set precision bits
    BitClr WORD ptr [xsp], BIT09 or BIT08
  elseifidni <Precision>, <REAL8>
    BitClr WORD ptr [xsp], BIT08
    BitSet WORD ptr [xsp], BIT09
  else
    BitSet WORD ptr [xsp], BIT09 or BIT08
  endif
  fldcw WORD ptr [xsp]                                  ;;Restore FPU control word
  add xsp, @WordSize                                    ;;Restore stack
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fMin
; Purpose:    Compare two floats, returns the smaller value on the FPU.
; Arguments:  Arg1: first value.
;             Arg2: Second value.
; Return:     Smallest value in st(0).
; Note:       Uses ax.
;             st7 must be empty.

fMin macro val1:req, val2:req
  local @@1, @@2

  fld val1
  fcomp val2
  fjge @@1
  fld val1
  jmp @@2
@@1:
  fld val2
@@2:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fMax
; Purpose:    Compare two floats, returns the larger on the FPU stack.
; Arguments:  Arg1: first value.
;             Arg2: Second value.
; Return:     Largest value in st(0).
; Note:       Uses ax.
;             st7 must be empty.

fMax macro val1:req, val2:req
  local @@1, @@2

  fld val1
  fcomp val2                                            ;;pop st(0)
  fjle @@1                                              ;;uses ax
  fld val1
  jmp @@2
@@1:
  fld val2
@@2:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fAbsMin
; Purpose:    Compare two floats, returns the absolute smaller value on the FPU stack.
; Arguments:  Arg1: first value.
;             Arg2: Second value.
; Return:     Smallest absolute value in st(0).
; Note:       Uses ax.
;             st6 and st7 must be empty.

fAbsMin macro val1:req, val2:req
  local @@1, @@2

  fld val1
  fabs
  fld val2
  fabs
  fcompp
  fjle @@1
  fld val1
  jmp @@2
@@1:
  fld val2
@@2:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fAbsMax
; Purpose:    Compare two floats, returns the absolute larger value on the FPU.
; Arguments:  Arg1: first value.
;             Arg2: Second value.
; Return:     Largest absolute value in st(0).
; Note:       Uses ax.
;             st6 and st7 must be empty.

fAbsMax macro val1:req, val2:req
  local @@1, @@2

  fld val1
  fabs
  fld val2
  fabs
  fcompp
  fjge @@1
  fld val1
  jmp @@2
@@1:
  fld val2
@@2:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fRnd
; Purpose:    Round the content of st0.
; Arguments:  None.
; Return:     Nothing.

fRnd macro
  sub xsp, @WordSize                                    ;;Reserve stack place
  fstcw WORD ptr [xsp]                                  ;;Store FPU control word
  push XWORD ptr [xsp]                                  ;;Duplicate value
  BitClr WORD ptr [xsp], (BIT10 or BIT11)               ;;Modify the control word to return
                                                        ;;rnd(x) Round to nearest, or to even if equidistant
  fldcw WORD ptr [xsp]                                  ;;Restore modified FPU control word
  frndint                                               ;;Round
  fldcw WORD ptr[xsp + @WordSize]                       ;;Restore previous FPU control word
  add xsp, 2*@WordSize                                  ;;Restore stack.
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fRndUp
; Purpose:    Round up the content of st0.
; Arguments:  None.
; Return:     Nothing.

fRndUp macro
  sub xsp, @WordSize                                    ;;Reserve stack place
  fstcw WORD ptr [xsp]                                  ;;Store FPU control word
  push XWORD ptr [xsp]                                  ;;Duplicate value
  BitClr WORD ptr [xsp], BIT10                          ;;Modify the control word to
  BitSet WORD ptr [xsp], BIT11                          ;;  round to +inf
  fldcw WORD ptr [xsp]                                  ;;Restore modified FPU control word
  frndint                                               ;;Round up
  fldcw WORD ptr[xsp + @WordSize]                       ;;Restore previous FPU control word
  add xsp, 2*@WordSize                                  ;;Restore stack.
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fRndDn
; Purpose:    Round down the content of st0.
; Arguments:  None.
; Return:     Nothing.

fRndDn macro
  sub xsp, @WordSize                                    ;;Reserve stack place for one word
  fstcw WORD ptr [xsp]                                  ;;Store FPU control word
  push XWORD ptr [xsp]                                  ;;Duplicate value
  BitSet WORD ptr [xsp], BIT10                          ;;Modify the control word to
  BitClr WORD ptr [xsp], BIT11                          ;;  round to -inf
  fldcw WORD ptr [xsp]                                  ;;Restore modified FPU control word
  frndint                                               ;;Round down
  fldcw WORD ptr[xsp + @WordSize]                       ;;Restore previous FPU control word
  add xsp, 2*@WordSize                                  ;;Restore stack.
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fInt
; Purpose:    Calculate the integer part of the content of st0.
; Arguments:  None.
; Return:     Nothing.

fInt macro
  sub xsp, @WordSize                                    ;;Reserve stack place for one word
  fstcw WORD ptr [xsp]                                  ;;Store FPU control word
  push XWORD ptr [xsp]                                  ;;Duplicate value
  BitSet WORD ptr [xsp], (BIT10 or BIT11)               ;;Modify the control word, int(x) = Truncate (toward 0)
  fldcw WORD ptr [xsp]                                  ;;Restore modified FPU control word
  frndint                                               ;;Round down
  fldcw WORD ptr[xsp + @WordSize]                       ;;Restore previous FPU control word
  add xsp, 2*@WordSize                                  ;;Restore stack. Don't use pop xax. We'll not destroy it.
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fFrac
; Purpose:    Calculate the fractional part of the content of st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fFrac macro
  fld st(0)                                             ;;Duplicate st0
  fInt                                                  ;;Compute int(st0)
  fsubp st(1), st(0)                                    ;;Frac(x) = x - Int(x)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fRound
; Purpose:    Round the content of st0 to x decimals.
; Arguments:  Arg1: Decimals.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fRound macro Decimals:=<0>
  push XWORD ptr Decimals                               ;;Store number of decimals
  fild XWORD ptr [xsp]                                  ;;Load Decimals
  add xsp, @WordSize                                    ;;Restore stack
  fExpT                                                 ;;Compute 10^x
  frndint                                               ;;Round to an integer
  fxch                                                  ;;Swap st0 and st1
  fmul st(0), st(1)                                     ;;Compute Number * 10^Decimals
  fRnd                                                  ;;Compute fRnd
  fdivrp st(1), st(0)                                   ;;Compute Number / 10^Decimals
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fExp2
; Purpose:    Compute 2^x = 2^st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fExp2 macro                     ;;st0      st1      st2
  fld st(0)                     ;;x        x        ?         Duplicate st0
  frndint                       ;;int(x)   x        ?         Round to integer
  fsub st(1), st(0)             ;;int(x)   frac(x)  ?         Compute fractional part of x
  fld1                          ;;1        int(x)   frac(x)   Load 1
  fscale                        ;;2^int(x) int(x)   frac(x)   Scale 1 by int(x)
  fxch                          ;;int(x)   2^int(x) frac(x)   Exchange st0 and st1
  fstp st(0)                    ;;2^int(x) frac(x)  ?         Eliminate st0 and pop
  fxch                          ;;frac(x)  2^int(x) ?         Exchange st0 and st1
  f2xm1                         ;;2^frac-1 2^int(x) ?         Compute 2xm1
  fld1                          ;;1        2^frac-1 2^int(x)  Load 1
  faddp st(1), st(0)            ;;2^frac   2^int(x) ?         Add st0 and st1 and pop
  fmulp st(1), st(0)            ;;2^x      ?        ?         Multiplay st1 by st0 and pop
endm

fExp2_ macro                    ;;st0      st1      st2
  fld st(0)                     ;;x        x        ?         Duplicate st0
  frndint                       ;;int(x)   x        ?         Round to integer
  fsub st(1), st(0)             ;;int(x)   frac(x)  ?         Compute fractional part of x
  fxch                          ;;int(x)   2^int(x) frac(x)   Exchange st0 and st1
  f2xm1                         ;;2^frac-1 2^int(x) ?         Compute 2xm1
  fld1                          ;;1        int(x)   frac(x)   Load 1
  fadd
  fscale                        ;;2^int(x) int(x)   frac(x)   Scale 1 by int(x)
  fstp st(1)                    ;;2^int(x) frac(x)  ?         Eliminate st0 and pop
endm
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fExpN
; Purpose:    Compute st(0) = e^st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fExpN macro
  fldl2e                                                ;;Put Log2(e) onto the stack
  fmulp st(1), st(0)                                    ;;Compute x*Log2(e).
  fExp2                                                 ;;Compute 2^(x*Log2(e)) = e^x
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fLogN
; Purpose:    Calculate the neperian logarithm of st0 and store it in st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fLogN macro
  fldln2                                                ;;Put LogN(2) onto the stack
  fxch                                                  ;;Swap st0 and st1
  fyl2x                                                 ;;Compute LogN(2)*Log2(st0)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fExpT
; Purpose:    Compute st0 = 10^st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fExpT macro
  fldl2t                                                ;;Push Log2(10) onto the FPU stack
  fmulp st(1),st(0)                                     ;;Compute x*Log2(10)
  fExp2                                                 ;;Compute 2^(x*Log2(10)) = 10^x
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fLogT
; Purpose:    Calculate the logarithm base 10 of st0 and sotres it in st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fLogT macro
  fldlg2                                                ;;Put Log10(2) onto the stack
  fxch                                                  ;;Swap st0 and st1
  fyl2x                                                 ;;Compute Log10(2)*Log2(st0)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fPower
; Purpose:    Compute st0 = st0^st1 (x^y).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fPower macro
  fld1                                                  ;;Put 1 onto the stack
  fxch                                                  ;;Swap st0 and st1
  fyl2x                                                 ;;Compute 1*Log2(x)
  fmulp st(1), st(0)                                    ;;Compute y*Log2(x)
  fExp2                                                 ;;Comput2 2^(x*Log2(y)) = x^y
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fLog
; Purpose:    Calculate the logarithm base st1 of st0 and store the result in st0.
; Arguments:  None.
; Return:     Nothing.
; Note:       st6 and st7 must be empty.
;             Log[st1](st0) = Log2(st0) / Log2(st1).

fLog macro
  fld1                                                  ;;Load 1
  fxch                                                  ;;Exchange with argument
  fyl2x                                                 ;;st1 = 1 * Log2(st0) and pop stack
  fxch                                                  ;;Exchange Log2(st0) with base
  fld1                                                  ;;Load 1
  fxch                                                  ;;Exchange 1 with base
  fyl2x                                                 ;;st1 = 1 * Log2(st0) and pop stack
  fdivp st(1), st(0)                                    ;;Log2(st0) / log2(st1)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fFitTrigRange
; Purpose:    Reduce the value in st0 to fit in the range of trig. functions: |x| < 2^63.
; Arguments:  st0.
; Return:     Nothing.
; Note:       st6 and st7 must be empty.
;             The result of fprem1 depends on the state of the FPU rounding bits.

fFitTrigRange macro
  local @@1

  fldpi                                                 ;;Load Pi
  fadd st(0), st(0)                                     ;;Double it
  fxch                                                  ;;Exchange argument and 2*Pi
@@1:
  fprem1                                                ;;Reduce the exponent of st(0) by no more
  fnstsw ax                                             ;;   than 63 in one execution
  sahf                                                  ;;Check FPU flags
  jp @@1                                                ;;C2 flag in the FPU set => reduce again
  fstp st(1)                                            ;;Pop 2*Pi from stack
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fTan
; Purpose:    Calculate st0 = tan(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fTan macro
  fptan
  fstp st(0)                                            ;;Pop st(0) from stack
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fSec
; Purpose:    Calculate st0 = Sec(st0).
; Arguments:  None.
; Return:     Nothing.

fSec macro
  fcos
  fdivr $CReal4(+1.0)                                   ;;Computes 1 / cos(x)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fCsc
; Purpose:    Calculate st0 = Csc(st0).
; Arguments:  None.
; Return:     Nothing.

fCsc macro
  fsin
  fdivr $CReal4(+1.0)                                   ;;Computes 1 / sin(x)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fCot
; Purpose:    Calculate st0 = Cot(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fCot macro
  fptan
  fdivrp st(1), st(0)                                   ;;Computes 1 / tan(x)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcSin
; Purpose:    Calculate st0 = ArcSin(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcSin macro
  fld st(0)
  fmul st(0), st(0)
  fsubr $CReal4(+1.0)
  fsqrt
  fpatan
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcCos
; Purpose:    Calculate st0 = ArcCos(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcCos macro
  fld st(0)
  fmul st(0), st(0)
  fsubr $CReal4(+1.0)
  fsqrt
  fxch
  fpatan
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcTan
; Purpose:    Calculate st0 = ArcTan(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcTan macro
  fld1
  fpatan
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcSec
; Purpose:    Calculate st0 = ArcSec(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcSec macro
  fmul st(0), st(0)
  fsub $CReal4(+1.0)
  fsqrt
  fld1
  fpatan
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcCsc
; Purpose:    Calculate st0 = ArcCsc(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcCsc macro
  fmul st(0), st(0)
  fsub $CReal4(+1.0)
  fsqrt
  fld1
  fdivr st(1), st(0)
  fpatan
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcCot
; Purpose:    Calculate st0 = ArcCot(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcCot macro
  fdivr $CReal4(+1.0)
  fld1
  fpatan
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fSinh
; Purpose:    Calculate st0 = Sinh(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fSinh macro
  fExpN
  fld st(0)
  fdivr $CReal4(+1.0)
  fsub
  fmul $CReal4(+0.5)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fCosh
; Purpose:    Calculate st0 = Cosh(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fCosh macro
  fExpN
  fld st(0)
  fdivr $CReal4(+1.0)
  fadd
  fmul $CReal4(+0.5)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fTanh
; Purpose:    Calculate st0 = Tanh(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fTanh macro
  fExpN
  fmul st(0), st(0)
  fld st(0)
  fadd $CReal4(+1.0)
  fxch
  fsub $CReal4(+1.0)
  fdivr
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fSech
; Purpose:    Calculate st0 = Sech(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fSech macro
  fExpN
  fld st(0)
  fdivr $CReal4(+1.0)
  fadd
  fdivr $CReal4(+2.0)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fCsch
; Purpose:    Calculate st0 = Csch(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fCsch macro
  fExpN
  fld st(0)
  fdivr $CReal4(+1.0)
  fsub
  fdivr $CReal4(+2.0)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fCoth
; Purpose:    Calculate st0 = Coth(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st5, st6 and st7 must be empty.

fCoth macro
  fExpN
  fmul st(0), st(0)
  fld st(0)
  fadd $CReal4(+1.0)
  fxch
  fsub $CReal4(+1.0)
  fdiv
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcSinh
; Purpose:    Calculate st0 = ArcSinh(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcSinh macro
  fld st(0)
  fmul st(0), st(0)
  fadd $CReal4(+1.0)
  fsqrt
  fadd
  fLogN
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcCosh
; Purpose:    Calculate st0 = ArcCosh(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcCosh macro
  fld st(0)
  fmul st(0), st(0)
  fsub $CReal4(+1.0)
  fsqrt
  fadd
  fLogN
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcTanh
; Purpose:    Calculate st0 = ArcTanh(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcTanh macro
  fadd $CReal4(+1.0)
  fld st(0)
  fsubr $CReal4(+2.0)
  fdiv
  fLogN
  fmul $CReal4(+0.5)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcSech
; Purpose:    Calculate st0 = ArcSech(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcSech macro
  fld st(0)
  fmul st(0), st(0)
  fsubr $CReal4(+1.0)
  fsqrt
  fadd $CReal4(+1.0)
  fdivr
  fLogN
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcCsch
; Purpose:    Calculate st0 = ArcCsch(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcCsch macro
  fld st(0)
  fmul st(0), st(0)
  fadd $CReal4(+1.0)
  fsqrt
  fadd $CReal4(+1.0)
  fdivr
  fLogN
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fArcCoth
; Purpose:    Calculate st0 = ArcCoth(st0).
; Arguments:  None.
; Return:     Nothing.
; Note:       st7 must be empty.

fArcCoth macro
  fadd $CReal4(+1.0)
  fld st(0)
  fsub $CReal4(+2.0)
  fdiv
  fLogN
  fmul $CReal4(+0.5)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fUnload
; Purpose:    Unload several stack registers
; Arguments:  Number of FPU registers.
; Return:     Nothing.

fUnload macro NoRegs:=<1>
  repeat NoRegs
    fstp st(0)
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fstStrA
; Purpose:    Create a string representation of the content of the st0 FPU register.
; Arguments:  Arg1: -> destionation buffer (at best 20 bytes + padding bytes).
;             Arg2: Number of padding bytes.
;             Arg3: Number of decimal places.
;             Arg4: Format flag (f_NOR or f_SCI)
; Return:     Operation code.
; Note:       st4, st5, st6 and st7 must be empty.
;             Destination buffer should have at least 20 bytes (add padding bytes)!

fstStr macro pDest:req, dPadding:=<0>, dDecimals:=<5>, dFlags:=<f_SCI>
  invoke St0ToStr, pDest, dPadding, dDecimals, dFlags
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fLdStrA
; Purpose:    Load a string representation of a floating point number into
;             the st0 FPU register.
; Arguments:  Arg1: -> string.
; Return:     Operation code.
; Note:       st4, st5, st6 and st7 must be empty.

fldStr macro pSource:req
  invoke StrToSt0, pSource
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fjg
; Purpose:    Jump to label if the result of the previous fcom instruction indicates greater.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fjg macro DestinationLabel:req
  fGetFlags
  ja DestinationLabel                                   ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fjl
; Purpose:    Jump to label if the result of the previous fcom instruction indicates less.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fjl macro DestinationLabel:req
  fGetFlags
  jb DestinationLabel                                   ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fje
; Purpose:    Jump to label if the result of the previous fcom instruction indicates equal.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fje macro DestinationLabel:req
  fGetFlags
  je DestinationLabel                                   ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fjne
; Purpose:    Jump to label if the result of the previous fcom instruction indicates not equal.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fjne macro DestinationLabel:req
  fGetFlags
  jne DestinationLabel                                  ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fjge
; Purpose:    Jump to label if the result of the previous fcom instruction indicates greater
;             or equal.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fjge macro DestinationLabel:req
  fGetFlags
  jae DestinationLabel                                  ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fjle
; Purpose:    Jump to label if the result of the previous fcom instruction indicates less
;             or equal.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fjle macro DestinationLabel:req
  fGetFlags
  jbe DestinationLabel                                  ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fjnc
; Purpose:    Jump to label if the result of the previous fcom instruction indicates that the
;             arguments are non-comparable.
; Arguments:  Arg1: Destination label.
; Return:     Nothing.

fjnc macro DestinationLabel:req
  fGetFlags
  jp DestinationLabel                                   ;;Conditional jump
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      fcmp
; Purpose:    Fast way to compare REAL4 floats with sign using the CPU.
; Arguments:  Arg1: first comparand.
;             Arg2: Second comparand.
; Return:     Modified flags.
; Note:       This macro distinguishes between -0.0 and +0.0!

fcmp macro var1:req, var2:req
  ??Reg3 textequ <>
  if (opattr var1) and OAT_REGISTER                     ;;Is var1 a register?
    ??Reg1 textequ <var1>
    if (opattr var2) and OAT_REGISTER                   ;;Is var2 a register?
      ??Reg2 textequ <var2>
    else
      ifdifi ??Reg1, <eax>
        ??Reg2 textequ <eax>
      elseifdifi ??Reg1, <ecx>
        ??Reg2 textequ <ecx>
      elseifdifi ??Reg1, <edx>
        ??Reg2 textequ <edx>
      endif
      mov ??Reg2, var2
    endif
  else
    if (opattr var2) and OAT_REGISTER                   ;;Is var2 a register?
      ??Reg2 textequ <var2>
      ifdifi ??Reg2, <eax>
        ??Reg1 textequ <eax>
      elseifdifi ??Reg2, <ecx>
        ??Reg1 textequ <ecx>
      elseifdifi ??Reg2, <edx>
        ??Reg1 textequ <edx>
      endif
      mov ??Reg1, var1
    else
      ??Reg1 textequ <eax>
      ??Reg2 textequ <ecx>
      mov ??Reg1, var1
      mov ??Reg2, var2
    endif
  endif

  ifdifi ??Reg1, <eax>
    ifdifi ??Reg2, <eax>
      ??Reg3 textequ <eax>
    endif
  endif

  ifb ??Reg3
    ifdifi ??Reg1, <ecx>
      ifdifi ??Reg2, <ecx>
        ??Reg3 textequ <ecx>
      endif
    endif
  endif

  ifb ??Reg3
    ifdifi ??Reg1, <edx>
      ifdifi ??Reg2, <edx>
        ??Reg3 textequ <edx>
      endif
    endif
  endif

  mov ??Reg3, ??Reg1
  and ??Reg3, ??Reg2
  sar ??Reg3, 31
  xor ??Reg1, ??Reg3
  xor ??Reg2, ??Reg3
  cmp ??Reg1, ??Reg2
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     fMod
;; Purpose:   Calculate "arg1 mod arg2" (arg1 % arg2).

fMod macro val1:req, val2:req
  fld val2
  fld val1
  fprem
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsPositive
;; Purpose:   If val > 0 => TRUE, else => FALSE.

fIsPositive macro val:req
  xor eax, eax                                          ;;FALSE
  test val, BIT31
  setz al
endm

$fIsPositive macro val:req
  fIsPositive val
  exitm <rax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsNegative
;; Purpose:   If val < 0 => TRUE, else => FALSE.

fIsNegative macro val:req
  xor eax, eax                                          ;;FALSE
  test val, BIT31
  setnz al
endm

$fIsNegative macro val:req
  fIsNegative val
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsZero
;; Purpose:   If val = (+/-)0 => TRUE, else => FALSE.

fIsZero macro val:req
  xor eax, eax                                          ;;FALSE
  test val, 7FFFFFFFh
  setz al
endm

$fIsZero macro val:req
  fIsZero val
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsLess
;; Purpose:   Alternative to fMin. Is float A less than float B, returns eax = TRUE/FALSE.

fIsLess macro val1:req, val2:req
  fld val1
  xor eax, eax
  fld val2
  fcomip st(0), st(1)
  fstp st(0)
  seta al
endm

$fIsLess macro val1:req, val2:req
  fIsLess val1, val2
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsLessOrEqual
;; Purpose:   If A <= B then return TRUE, else return FALSE.

fIsLessOrEqual macro val1:req, val2:req
  fld val1
  xor eax, eax
  fld val2
  fcomip st(0), st(1)
  fstp st(0)
  seta al
endm

$fIsLessOrEqual macro val1:req, val2:req
  fIsLessOrEqual val1, val2
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsGreater
;; Purpose:   Alternative to fMin. Is float A greater than float B, returns eax = TRUE/FALSE.

fIsGreater macro val1:req, val2:req
  fld val1
  xor eax, eax
  fld val2
  fcomip st(0), st(1)
  fstp st(0)
  setb al
endm

$fIsGreater macro val1:req, val2:req
  fIsGreater val1, val2
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsGreaterOrEqual
;; Purpose:   If A >= B then return TRUE, else return FALSE.

fIsGreaterOrEqual macro val1:req, val2:req
  fld val1
  xor eax, eax
  fld val2
  fcomip st(0), st(1)
  fstp st(0)
  setbe al
endm

$fIsGreaterOrEqual macro val1:req, val2:req
  fIsGreaterOrEqual val1, val2
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsAbsLess
;; Purpose:   If |A| < |B| then return TRUE, else return FALSE.

fIsAbsLess macro val1:req, val2:req
  fld val1
  fabs
  xor eax, eax
  fld val2
  fabs
  fcomip st(0), st(1)
  fstp st(0)
  seta al
endm

$fIsAbsLess macro val1:req, val2:req
  fIsAbsLess val1, val2
  exitm <xax>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     ($)fIsAbsGreater
;; Purpose:   If |A| > |B| then return TRUE, else return FALSE.

fIsAbsGreater macro val1:req, val2:req
  fld val1
  fabs
  xor eax, eax
  fld val2
  fabs
  fcomip st(0), st(1)
  fstp st(0)
  setb al
endm

$fIsAbsGreater macro val1:req, val2:req
  fIsAbsGreater val1, val2
  exitm <xax>
endm
