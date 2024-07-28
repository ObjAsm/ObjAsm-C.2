;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\math.h', last modified: 01/10/2012 07:50
;Creation parameters: 

ifndef _INC_MATH
  _INC_MATH equ <>
  include crtdefs.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef __assembler
    ifndef _EXCEPTION_DEFINED
      _exception struct
        type_ SDWORD ?
        name_ POINTER ?
        arg1 REAL8 ?
        arg2 REAL8 ?
        retval REAL8 ?
      _exception ends
      _EXCEPTION_DEFINED equ <>
    endif
    ifndef _COMPLEX_DEFINED
      _complex struct
        x REAL8 ?
      _complex ends
      if  not __STDC__ and  not Defined(__cplusplus)
        complex equ <_complex>
      endif
      _COMPLEX_DEFINED equ <>
    endif
  endif
  _DOMAIN equ 1
  _SING equ 2
  _OVERFLOW equ 3
  _UNDERFLOW equ 4
  _TLOSS equ 5
  _PLOSS equ 6
  EDOM equ 33
  ERANGE equ 34
  ifndef __assembler
    if  not Defined(_M_CEE_PURE)
      externdef _HUGE:REAL8
    else
      ;[...]
    endif
  endif
  HUGE_VAL equ <_HUGE>
  if  not Defined(__assembler)
    ifndef _CRT_ABS_DEFINED
      _CRT_ABS_DEFINED equ <>
      @DefProto DllImport, abs, c, _, <:SDWORD>
      labs proto c :SDWORD
      llabs proto c :SQWORD
    endif
;    acos proto c :REAL8
;    asin proto c :REAL8
;    atan proto c :REAL8
;    atan2 proto c :REAL8, :REAL8
;    ifndef _SIGN_DEFINED
;      @DefProto DllImport, _copysign, c,, <:REAL8, :REAL8>
;      @DefProto DllImport, _chgsign, c,, <:REAL8>
;      _SIGN_DEFINED equ <>
;    endif
;    cos proto c :REAL8
;    cosh proto c :REAL8
;    exp proto c :REAL8
;    fabs_ proto c :REAL8
;    fmod proto c :REAL8, :REAL8
;    log proto c :REAL8
;    log10 proto c :REAL8
;    pow proto c :REAL8, :REAL8
;    sin proto c :REAL8
;    sinh proto c :REAL8
;    tan proto c :REAL8
;    tanh proto c :REAL8
;    sqrt proto c :REAL8
;    ifndef _CRT_ATOF_DEFINED
;      _CRT_ATOF_DEFINED equ <>
;      @DefProto DllImport, atof, c,, <:ptr SBYTE>
;      @DefProto DllImport, _atof_l, c,, <:ptr SBYTE, :_locale_t>
;    endif
;    @DefProto DllImport, _cabs, c,, <:_complex>
;    @DefProto DllImport, ceil, c,, <:REAL8>
;    @DefProto DllImport, floor, c,, <:REAL8>
;    @DefProto DllImport, frexp, c,, <:REAL8, :ptr SDWORD>
;    @DefProto DllImport, _hypot, c,, <:REAL8, :REAL8>
;    @DefProto DllImport, _hypotf, c,, <:REAL4, :REAL4>
;    @DefProto DllImport, _j0, c,, <:REAL8>
;    @DefProto DllImport, _j1, c,, <:REAL8>
;    @DefProto DllImport, _jn, c,, <:SDWORD, :REAL8>
;    @DefProto DllImport, ldexp, c,, <:REAL8, :SDWORD>
;    ifndef _CRT_MATHERR_DEFINED
;      _CRT_MATHERR_DEFINED equ <>
;      if Defined(MRTDLL) or Defined(_M_CEE_PURE)
;        _matherr proto c :ptr _exception
;      else
;        _matherr proto c :ptr _exception
;      endif
;    endif
;    @DefProto DllImport, modf, c,, <:REAL8, :ptr REAL8>
;    @DefProto DllImport, _y0, c,, <:REAL8>
;    @DefProto DllImport, _y1, c,, <:REAL8>
;    @DefProto DllImport, _yn, c,, <:SDWORD, :REAL8>
;    if  not Defined(RC_INVOKED) and  not Defined(__midl)
;      hypot proto c :REAL8, :REAL8
;      hypotf proto c :REAL4, :REAL4
;    endif
    if Defined(_M_IX86)
      @DefProto DllImport, _set_SSE2_enable, c,, <:SDWORD>
    endif
    if Defined(_M_X64)
      @DefProto DllImport, acosf, c,, <:REAL4>
      @DefProto DllImport, asinf, c,, <:REAL4>
      @DefProto DllImport, atanf, c,, <:REAL4>
      @DefProto DllImport, atan2f, c,, <:REAL4, :REAL4>
      @DefProto DllImport, cosf, c,, <:REAL4>
      @DefProto DllImport, sinf, c,, <:REAL4>
      @DefProto DllImport, tanf, c,, <:REAL4>
      @DefProto DllImport, coshf, c,, <:REAL4>
      @DefProto DllImport, sinhf, c,, <:REAL4>
      @DefProto DllImport, tanhf, c,, <:REAL4>
      @DefProto DllImport, expf, c,, <:REAL4>
      @DefProto DllImport, logf, c,, <:REAL4>
      @DefProto DllImport, log10f, c,, <:REAL4>
      @DefProto DllImport, modff, c,, <:REAL4, :ptr REAL4>
      @DefProto DllImport, powf, c,, <:REAL4, :REAL4>
      @DefProto DllImport, sqrtf, c,, <:REAL4>
      @DefProto DllImport, ceilf, c,, <:REAL4>
      @DefProto DllImport, floorf, c,, <:REAL4>
      @DefProto DllImport, fmodf, c,, <:REAL4, :REAL4>
      @DefProto DllImport, _copysignf, c,, <:REAL4, :REAL4>
      @DefProto DllImport, _chgsignf, c,, <:REAL4>
      @DefProto DllImport, _logbf, c,, <:REAL4>
      @DefProto DllImport, _nextafterf, c,, <:REAL4, :REAL4>
      @DefProto DllImport, _finitef, c,, <:REAL4>
      @DefProto DllImport, _isnanf, c,, <:REAL4>
      @DefProto DllImport, _fpclassf, c,, <:REAL4>
    endif
    if Defined(_M_ARM)
      ;[...]
    endif
    ifndef __cplusplus
      acosl macro x
        exitm <(acos ((x)))>
      endm
      asinl macro x
        exitm <(asin ((x)))>
      endm
      atanl macro x
        exitm <(atan ((x)))>
      endm
      atan2l macro y, x
        exitm <(atan2 ((y), (x)))>
      endm
      ceill macro x
        exitm <(ceil ((x)))>
      endm
      cosl macro x
        exitm <(cos ((x)))>
      endm
      coshl macro x
        exitm <(cosh ((x)))>
      endm
      expl macro x
        exitm <(exp ((x)))>
      endm
      fabsl macro x
        exitm <(fabs ((x)))>
      endm
      floorl macro x
        exitm <(floor ((x)))>
      endm
      fmodl macro x, y
        exitm <(fmod ((x), (y)))>
      endm
      frexpl macro x, y
        exitm <(frexp ((x), (y)))>
      endm
      _hypotl macro x, y
        exitm <(_hypot ((x), (y)))>
      endm
      hypotl macro x, y
        exitm <(_hypot ((x), (y)))>
      endm
      ldexpl macro x, y
        exitm <(ldexp ((x), (y)))>
      endm
      logl macro x
        exitm <(log ((x)))>
      endm
      log10l macro x
        exitm <(log10 ((x)))>
      endm
      _matherrl equ <_matherr>
      modfl macro x, y
        exitm <(modf ((x), (y)))>
      endm
      powl macro x, y
        exitm <(pow ((x), (y)))>
      endm
      sinl macro x
        exitm <(sin ((x)))>
      endm
      sinhl macro x
        exitm <(sinh ((x)))>
      endm
      sqrtl macro x
        exitm <(sqrt ((x)))>
      endm
      tanl macro x
        exitm <(tan ((x)))>
      endm
      tanhl macro x
        exitm <(tanh ((x)))>
      endm
      _chgsignl macro x
        exitm <(_chgsign ((x)))>
      endm
      _copysignl macro x, y
        exitm <(_copysign ((x), (y)))>
      endm
      frexpf macro x, y
        exitm <(frexp ((x), (y)))>
      endm
      if  not Defined(_M_ARM)
        fabsf macro x
          exitm <(fabs ((x)))>
        endm
      endif
      ldexpf macro x, y
        exitm <(ldexp ((x), (y)))>
      endm
      if  not Defined(_M_X64) and  not Defined(_M_ARM)
        acosf macro x
          exitm <(acos ((x)))>
        endm
        asinf macro x
          exitm <(asin ((x)))>
        endm
        atanf macro x
          exitm <(atan ((x)))>
        endm
        atan2f macro y, x
          exitm <(atan2 ((y), (x)))>
        endm
        ceilf macro x
          exitm <(ceil ((x)))>
        endm
        cosf macro x
          exitm <(cos ((x)))>
        endm
        coshf macro x
          exitm <(cosh ((x)))>
        endm
        expf macro x
          exitm <(exp ((x)))>
        endm
        floorf macro x
          exitm <(floor ((x)))>
        endm
        fmodf macro x, y
          exitm <(fmod ((x), (y)))>
        endm
        logf macro x
          exitm <(log ((x)))>
        endm
        log10f macro x
          exitm <(log10 ((x)))>
        endm
        modff macro x, y
          exitm <(modf ((x), (y)))>
        endm
        powf macro x, y
          exitm <(pow ((x), (y)))>
        endm
        sinf macro x
          exitm <(sin ((x)))>
        endm
        sinhf macro x
          exitm <(sinh ((x)))>
        endm
        sqrtf macro x
          exitm <(sqrt ((x)))>
        endm
        tanf macro x
          exitm <(tan ((x)))>
        endm
        tanhf macro x
          exitm <(tanh ((x)))>
        endm
      endif
    else
      ;[...]
    endif
  endif
  if  not __STDC__
    DOMAIN equ <_DOMAIN>
    SING equ <_SING>
    OVERFLOW equ <_OVERFLOW>
    UNDERFLOW equ <_UNDERFLOW>
    TLOSS equ <_TLOSS>
    PLOSS equ <_PLOSS>
    matherr equ <_matherr>
    ifndef __assembler
      if  not Defined(_M_CEE_PURE)
        externdef HUGE_:REAL8
      else
        ;[...]
      endif
      @DefProto DllImport, cabs, c,, <:_complex>
      @DefProto DllImport, j0, c,, <:REAL8>
      @DefProto DllImport, j1, c,, <:REAL8>
      @DefProto DllImport, jn, c,, <:SDWORD, :REAL8>
      @DefProto DllImport, y0, c,, <:REAL8>
      @DefProto DllImport, y1, c,, <:REAL8>
      @DefProto DllImport, yn, c,, <:SDWORD, :REAL8>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
if Defined(_USE_MATH_DEFINES) and  not Defined(_MATH_DEFINES_DEFINED)
  _MATH_DEFINES_DEFINED equ <>
  M_E equ 2.71828182845904523536
  M_LOG2E equ 1.44269504088896340736
  M_LOG10E equ 0.434294481903251827651
  M_LN2 equ 0.693147180559945309417
  M_LN10 equ 2.30258509299404568402
  M_PI equ 3.14159265358979323846
  M_PI_2 equ 1.57079632679489661923
  M_PI_4 equ 0.785398163397448309616
  M_1_PI equ 0.318309886183790671538
  M_2_PI equ 0.636619772367581343076
  M_2_SQRTPI equ 1.12837916709551257390
  M_SQRT2 equ 1.41421356237309504880
  M_SQRT1_2 equ 0.707106781186547524401
endif

