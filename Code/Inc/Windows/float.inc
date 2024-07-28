;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\float.h', last modified: 01/10/2012 07:50
;Creation parameters: 

ifndef _INC_FLOAT
  _INC_FLOAT equ <>
  include crtdefs.inc
  include crtwrn.inc
  ifndef _CRT_MANAGED_FP_DEPRECATE
    ifdef _CRT_MANAGED_FP_NO_DEPRECATE
      _CRT_MANAGED_FP_DEPRECATE equ <>
    else
      if Defined(_M_CEE)
        ;[...]
      else
        _CRT_MANAGED_FP_DEPRECATE equ <>
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  DBL_DIG equ 15
  DBL_EPSILON equ 2.2204460492503131E-016
  DBL_MANT_DIG equ 53
  DBL_MAX equ 1.7976931348623158E+308
  DBL_MAX_10_EXP equ 308
  DBL_MAX_EXP equ 1024
  DBL_MIN equ 2.2250738585072014E-308
  DBL_MIN_10_EXP equ -307
  DBL_MIN_EXP equ -1021
  _DBL_RADIX equ 2
  _DBL_ROUNDS equ 1
  FLT_DIG equ 6
  FLT_EPSILON equ 1.192092896E-07
  FLT_GUARD equ 0
  FLT_MANT_DIG equ 24
  FLT_MAX equ 3.402823466E+38
  FLT_MAX_10_EXP equ 38
  FLT_MAX_EXP equ 128
  FLT_MIN equ 1.175494351E-38
  FLT_MIN_10_EXP equ -37
  FLT_MIN_EXP equ -125
  FLT_NORMALIZE equ 0
  FLT_RADIX equ 2
  FLT_ROUNDS equ 1
  LDBL_DIG equ <DBL_DIG>
  LDBL_EPSILON equ <DBL_EPSILON>
  LDBL_MANT_DIG equ <DBL_MANT_DIG>
  LDBL_MAX equ <DBL_MAX>
  LDBL_MAX_10_EXP equ <DBL_MAX_10_EXP>
  LDBL_MAX_EXP equ <DBL_MAX_EXP>
  LDBL_MIN equ <DBL_MIN>
  LDBL_MIN_10_EXP equ <DBL_MIN_10_EXP>
  LDBL_MIN_EXP equ <DBL_MIN_EXP>
  _LDBL_RADIX equ <DBL_RADIX>
  _LDBL_ROUNDS equ <DBL_ROUNDS>
;  @DefProto DllImport, _clearfp, c,, <>
;  @DefProto DllImport, _controlfp, c,, <:DWORD, :DWORD>
  @DefProto DllImport, _set_controlfp, c,, <:DWORD, :DWORD>
  @DefProto DllImport, _controlfp_s, c,, <:ptr DWORD, :DWORD, :DWORD>
;  @DefProto DllImport, _statusfp, c,, <>
;  @DefProto DllImport, _fpreset, c,, <>
  if Defined(_M_IX86)
    @DefProto DllImport, _statusfp2, c,, <:ptr DWORD, :ptr DWORD>
  endif
  _clear87 equ <_clearfp>
  _status87 equ <_statusfp>
  _SW_INEXACT equ 00000001h
  _SW_UNDERFLOW equ 00000002h
  _SW_OVERFLOW equ 00000004h
  _SW_ZERODIVIDE equ 00000008h
  _SW_INVALID equ 00000010h
  _SW_DENORMAL equ 00080000h
  _EM_AMBIGUIOUS equ 80000000h
  _EM_AMBIGUOUS equ 80000000h
  _MCW_EM equ 0008001fh
  _EM_INEXACT equ 00000001h
  _EM_UNDERFLOW equ 00000002h
  _EM_OVERFLOW equ 00000004h
  _EM_ZERODIVIDE equ 00000008h
  _EM_INVALID equ 00000010h
  _EM_DENORMAL equ 00080000h
  _MCW_RC equ 00000300h
  _RC_NEAR equ 00000000h
  _RC_DOWN equ 00000100h
  _RC_UP equ 00000200h
  _RC_CHOP equ 00000300h
  _MCW_PC equ 00030000h
  _PC_64 equ 00000000h
  _PC_53 equ 00010000h
  _PC_24 equ 00020000h
  _MCW_IC equ 00040000h
  _IC_AFFINE equ 00040000h
  _IC_PROJECTIVE equ 00000000h
  _MCW_DN equ 03000000h
  _DN_SAVE equ 00000000h
  _DN_FLUSH equ 01000000h
  _DN_FLUSH_OPERANDS_SAVE_RESULTS equ 02000000h
  _DN_SAVE_OPERANDS_FLUSH_RESULTS equ 03000000h
  if Defined(_M_IX86)
    _CW_DEFAULT equ <(_RC_NEAR + _PC_53 + _EM_INVALID + _EM_ZERODIVIDE + _EM_OVERFLOW + _EM_UNDERFLOW + _EM_INEXACT + _EM_DENORMAL)>
  elseif Defined(_M_X64) or Defined(_M_ARM)
    _CW_DEFAULT equ <(_RC_NEAR + _EM_INVALID + _EM_ZERODIVIDE + _EM_OVERFLOW + _EM_UNDERFLOW + _EM_INEXACT + _EM_DENORMAL)>
  endif
;  @DefProto DllImport, _control87, c,, <:DWORD, :DWORD>
  if Defined(_M_IX86)
    @DefProto DllImport, __control87_2, c,, <:DWORD, :DWORD, :ptr DWORD, :ptr DWORD>
  endif
;  @DefProto DllImport, __fpecode, c,, <>
  _fpecode equ <(* __fpecode ())>
  _SW_UNEMULATED equ 0040h
  _SW_SQRTNEG equ 0080h
  _SW_STACKOVERFLOW equ 0200h
  _SW_STACKUNDERFLOW equ 0400h
  _FPE_INVALID equ 81h
  _FPE_DENORMAL equ 82h
  _FPE_ZERODIVIDE equ 83h
  _FPE_OVERFLOW equ 84h
  _FPE_UNDERFLOW equ 85h
  _FPE_INEXACT equ 86h
  _FPE_UNEMULATED equ 87h
  _FPE_SQRTNEG equ 88h
  _FPE_STACKOVERFLOW equ 8ah
  _FPE_STACKUNDERFLOW equ 8bh
  _FPE_EXPLICITGEN equ 8ch
  _FPE_MULTIPLE_TRAPS equ 8dh
  _FPE_MULTIPLE_FAULTS equ 8eh
  ifndef _SIGN_DEFINED
;    @DefProto DllImport, _copysign, c,, <:REAL8, :REAL8>
;    @DefProto DllImport, _chgsign, c,, <:REAL8>
    _SIGN_DEFINED equ <>
  endif
;  @DefProto DllImport, _scalb, c,, <:REAL8, :SDWORD>
;  @DefProto DllImport, _logb, c,, <:REAL8>
;  @DefProto DllImport, _nextafter, c,, <:REAL8, :REAL8>
;  @DefProto DllImport, _finite, c,, <:REAL8>
;  @DefProto DllImport, _isnan, c,, <:REAL8>
;  @DefProto DllImport, _fpclass, c,, <:REAL8>
  ifdef _M_X64
    @DefProto DllImport, _scalbf, c,, <:REAL4, :SDWORD>
  endif
  _FPCLASS_SNAN equ 0001h
  _FPCLASS_QNAN equ 0002h
  _FPCLASS_NINF equ 0004h
  _FPCLASS_NN equ 0008h
  _FPCLASS_ND equ 0010h
  _FPCLASS_NZ equ 0020h
  _FPCLASS_PZ equ 0040h
  _FPCLASS_PD equ 0080h
  _FPCLASS_PN equ 0100h
  _FPCLASS_PINF equ 0200h
  if  not __STDC__
    clear87 equ <_clear87>
    status87 equ <_status87>
    control87 equ <_control87>
    @DefProto DllImport, fpreset, c,, <>
    DBL_RADIX equ <_DBL_RADIX>
    DBL_ROUNDS equ <_DBL_ROUNDS>
    LDBL_RADIX equ <_LDBL_RADIX>
    LDBL_ROUNDS equ <_LDBL_ROUNDS>
    EM_AMBIGUIOUS equ <_EM_AMBIGUOUS>
    EM_AMBIGUOUS equ <_EM_AMBIGUOUS>
    MCW_EM equ <_MCW_EM>
    EM_INVALID equ <_EM_INVALID>
    EM_DENORMAL equ <_EM_DENORMAL>
    EM_ZERODIVIDE equ <_EM_ZERODIVIDE>
    EM_OVERFLOW equ <_EM_OVERFLOW>
    EM_UNDERFLOW equ <_EM_UNDERFLOW>
    EM_INEXACT equ <_EM_INEXACT>
    MCW_IC equ <_MCW_IC>
    IC_AFFINE equ <_IC_AFFINE>
    IC_PROJECTIVE equ <_IC_PROJECTIVE>
    MCW_RC equ <_MCW_RC>
    RC_CHOP equ <_RC_CHOP>
    RC_UP equ <_RC_UP>
    RC_DOWN equ <_RC_DOWN>
    RC_NEAR equ <_RC_NEAR>
    MCW_PC equ <_MCW_PC>
    PC_24 equ <_PC_24>
    PC_53 equ <_PC_53>
    PC_64 equ <_PC_64>
    CW_DEFAULT equ <_CW_DEFAULT>
    SW_INVALID equ <_SW_INVALID>
    SW_DENORMAL equ <_SW_DENORMAL>
    SW_ZERODIVIDE equ <_SW_ZERODIVIDE>
    SW_OVERFLOW equ <_SW_OVERFLOW>
    SW_UNDERFLOW equ <_SW_UNDERFLOW>
    SW_INEXACT equ <_SW_INEXACT>
    SW_UNEMULATED equ <_SW_UNEMULATED>
    SW_SQRTNEG equ <_SW_SQRTNEG>
    SW_STACKOVERFLOW equ <_SW_STACKOVERFLOW>
    SW_STACKUNDERFLOW equ <_SW_STACKUNDERFLOW>
    FPE_INVALID equ <_FPE_INVALID>
    FPE_DENORMAL equ <_FPE_DENORMAL>
    FPE_ZERODIVIDE equ <_FPE_ZERODIVIDE>
    FPE_OVERFLOW equ <_FPE_OVERFLOW>
    FPE_UNDERFLOW equ <_FPE_UNDERFLOW>
    FPE_INEXACT equ <_FPE_INEXACT>
    FPE_UNEMULATED equ <_FPE_UNEMULATED>
    FPE_SQRTNEG equ <_FPE_SQRTNEG>
    FPE_STACKOVERFLOW equ <_FPE_STACKOVERFLOW>
    FPE_STACKUNDERFLOW equ <_FPE_STACKUNDERFLOW>
    FPE_EXPLICITGEN equ <_FPE_EXPLICITGEN>
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

