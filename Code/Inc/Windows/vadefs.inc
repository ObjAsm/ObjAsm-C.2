;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\vadefs.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_VADEFS
  _INC_VADEFS equ <>
  if  not Defined(_WIN32)
    ;[...]
  endif
  _CRT_PACKING equ 8
  ifdef __cplusplus
    ;[...]
  endif
  if  not Defined(_W64)
    if  not Defined(__midl) and (Defined(_X86_) or Defined(_M_IX86))
      _W64 equ <__w64>
    else
      _W64 equ <>
    endif
  endif
  ifndef _UINTPTR_T_DEFINED
    ifdef _WIN64
      uintptr_t typedef QWORD
    else
      uintptr_t typedef _W64
    endif
    _UINTPTR_T_DEFINED equ <>
  endif
  ifndef _VA_LIST_DEFINED
    ifdef _M_CEE_PURE
      ;[...]
    else
      va_list typedef ptr SBYTE
    endif
    _VA_LIST_DEFINED equ <>
  endif
  ifdef __cplusplus
    ;[...]
  else
    _ADDRESSOF macro v
      exitm <(and (v))>
    endm
  endif
  if Defined(_M_ARM) and  not Defined(_M_CEE_PURE)
    ;[...]
  else
    _SLOTSIZEOF macro t
      exitm <(sizeof(t))>
    endm
    _APALIGN macro t, ap
      exitm <(__alignof(t))>
    endm
  endif
  if Defined(_M_CEE_PURE) or (Defined(_M_CEE) and  not Defined(_M_ARM))
    ;[...]
  elseif Defined(_M_IX86)
    _INTSIZEOF macro n
      exitm <((sizeof(n) + sizeof(int) - 1) and not (sizeof(int) - 1))>
    endm
    _crt_va_start macro ap, v
      exitm <(ap = (va_list) _ADDRESSOF(v) + _INTSIZEOF(v))>
    endm
    _crt_va_arg macro ap, t
      exitm <(* (t *) ((ap + _INTSIZEOF(t)) - _INTSIZEOF(t)))>
    endm
    _crt_va_end macro ap
      exitm <(ap = (va_list) 0)>
    endm
  elseif Defined(_M_ARM)
    ;[...]
  elseif Defined(_M_X64)
    __va_start proto c :ptr va_list, :vararg
    _crt_va_start macro ap, x
      exitm <(__va_start (and ap, x))>
    endm
    _crt_va_arg macro ap, t
      exitm <((sizeof(t) > sizeof(__int64) or (sizeof(t) and (sizeof(t) - 1)) != 0) ? * * (t * *) ((ap + sizeof(__int64)) - sizeof(__int64)) : * (t *) ((ap + sizeof(__int64)) - sizeof(__int64)))>
    endm
    _crt_va_end macro ap
      exitm <(ap = (va_list) 0)>
    endm
  else
    _INTSIZEOF macro n
      exitm <((sizeof(n) + sizeof(int) - 1) and not (sizeof(int) - 1))>
    endm
    _crt_va_start macro ap, v
      exitm <(ap = (va_list) _ADDRESSOF(v) + _INTSIZEOF(v))>
    endm
    _crt_va_arg macro ap, t
      exitm <(* (t *) ((ap + _INTSIZEOF(t)) - _INTSIZEOF(t)))>
    endm
    _crt_va_end macro ap
      exitm <(ap = (va_list) 0)>
    endm
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

