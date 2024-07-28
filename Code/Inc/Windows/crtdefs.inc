;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\crtdefs.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _CRTIMP
  ifdef _DLL
    _CRTIMP equ <__declspec(dllimport)>
  else
    _CRTIMP equ <>
  endif
endif
ifndef _INC_CRTDEFS
  _INC_CRTDEFS equ <>
  if Defined(__midl)
    ;[...]
  endif
  if  not Defined(_WIN32)
    ;[...]
  endif
  include sal.inc
  _CRT_PACKING equ 8
  include vadefs.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef _CRT_STRINGIZE
    __CRT_STRINGIZE macro _Value
      exitm <# _Value>
    endm
    _CRT_STRINGIZE macro _Value
      exitm <__CRT_STRINGIZE(_Value)>
    endm
  endif
  ifndef _CRT_WIDE
    __CRT_WIDE macro _String
      exitm <L ## _String>
    endm
    _CRT_WIDE macro _String
      exitm <__CRT_WIDE(_String)>
    endm
  endif
  ifndef _CRT_APPEND
    __CRT_APPEND macro _Value1, _Value2
      exitm <_Value1 ## _Value2>
    endm
    _CRT_APPEND macro _Value1, _Value2
      exitm <__CRT_APPEND(_Value1, _Value2)>
    endm
  endif
  if  not Defined(_W64)
    if  not Defined(__midl) and (Defined(_X86_) or Defined(_M_IX86))
      _W64 equ <__w64>
    else
      _W64 equ <>
    endif
  endif
  ifndef _CRTIMP2
    if Defined(_DLL) and  not Defined(_STATIC_CPPLIB)
      _CRTIMP2 equ <__declspec(dllimport)>
    else
      _CRTIMP2 equ <>
    endif
  endif
  ifndef _CRTIMP_ALTERNATIVE
    ifdef _DLL
      ifdef _CRT_ALTERNATIVE_INLINES
        _CRTIMP_ALTERNATIVE equ <>
      else
        _CRTIMP_ALTERNATIVE equ <_CRTIMP>
        _CRT_ALTERNATIVE_IMPORTED equ <>
      endif
    else
      _CRTIMP_ALTERNATIVE equ <>
    endif
  endif
  ifndef _MRTIMP
    _MRTIMP equ <__declspec(dllimport)>
  endif
  ifndef _MRTIMP2
    if Defined(_DLL) and  not Defined(_STATIC_CPPLIB)
      _MRTIMP2 equ <__declspec(dllimport)>
    else
      _MRTIMP2 equ <>
    endif
  endif
  ifndef _MCRTIMP
    ifdef _DLL
      _MCRTIMP equ <__declspec(dllimport)>
    else
      _MCRTIMP equ <>
    endif
  endif
  ifndef __CLR_OR_THIS_CALL
    if Defined(MRTDLL) or Defined(_M_CEE_PURE)
      __CLR_OR_THIS_CALL equ <__clrcall>
    else
      __CLR_OR_THIS_CALL equ <>
    endif
  endif
  ifndef __CLRCALL_OR_CDECL
    if Defined(MRTDLL) or Defined(_M_CEE_PURE)
      __CLRCALL_OR_CDECL equ <__clrcall>
    else
      __CLRCALL_OR_CDECL equ <__cdecl>
    endif
  endif
  ifndef _CRTIMP_PURE
    if Defined(_M_CEE_PURE) or Defined(_STATIC_CPPLIB)
      _CRTIMP_PURE equ <>
    else
      _CRTIMP_PURE equ <_CRTIMP>
    endif
  endif
  ifndef _PGLOBAL
    ifdef _M_CEE
      ;[...]
    else
      _PGLOBAL equ <>
    endif
  endif
  ifndef _AGLOBAL
    ifdef _M_CEE
      ;[...]
    else
      _AGLOBAL equ <>
    endif
  endif
  ifdef _M_CEE
    ;[...]
  endif
  __STDC_SECURE_LIB__ equ 200411
  __GOT_SECURE_LIB__ equ <__STDC_SECURE_LIB__>
  ifndef __STDC_WANT_SECURE_LIB__
    __STDC_WANT_SECURE_LIB__ equ 1
  endif
  if  not __STDC_WANT_SECURE_LIB__ and  not Defined(_CRT_SECURE_NO_WARNINGS)
    _CRT_SECURE_NO_WARNINGS equ <>
  endif
  _CRT_DEPRECATE_TEXT macro _Text
    exitm <__declspec(deprecated (_Text))>
  endm
  if Defined(_CRT_SECURE_NO_DEPRECATE) and  not Defined(_CRT_SECURE_NO_WARNINGS)
    _CRT_SECURE_NO_WARNINGS equ <>
  endif
  ifndef _CRT_INSECURE_DEPRECATE
    ifdef _CRT_SECURE_NO_WARNINGS
      _CRT_INSECURE_DEPRECATE macro _Replacement
        exitm <>
      endm
    else
      _CRT_INSECURE_DEPRECATE macro _Replacement
        exitm <_CRT_DEPRECATE_TEXT("This function or variable may be unsafe. Consider using " # _Replacement " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")>
      endm
    endif
  endif
  if Defined(_CRT_SECURE_DEPRECATE_MEMORY) and  not Defined(_CRT_SECURE_WARNINGS_MEMORY)
    _CRT_SECURE_WARNINGS_MEMORY equ <>
  endif
  ifndef _CRT_INSECURE_DEPRECATE_MEMORY
    if  not Defined(_CRT_SECURE_WARNINGS_MEMORY)
      _CRT_INSECURE_DEPRECATE_MEMORY macro _Replacement
        exitm <>
      endm
    else
      _CRT_INSECURE_DEPRECATE_MEMORY macro _Replacement
        exitm <_CRT_INSECURE_DEPRECATE(_Replacement)>
      endm
    endif
  endif
  if  not Defined(RC_INVOKED)
    if Defined(_CRT_SECURE_NO_DEPRECATE_GLOBALS) and  not Defined(_CRT_SECURE_NO_WARNINGS_GLOBALS)
      _CRT_SECURE_NO_WARNINGS_GLOBALS equ <>
    endif
  endif
  ifndef _CRT_INSECURE_DEPRECATE_GLOBALS
    if Defined(RC_INVOKED)
      ;[...]
    else
      if Defined(_CRT_SECURE_NO_WARNINGS_GLOBALS)
        _CRT_INSECURE_DEPRECATE_GLOBALS macro _Replacement
          exitm <>
        endm
      else
        _CRT_INSECURE_DEPRECATE_GLOBALS macro _Replacement
          exitm <_CRT_INSECURE_DEPRECATE(_Replacement)>
        endm
      endif
    endif
  endif
  if Defined(_CRT_MANAGED_HEAP_NO_DEPRECATE) and  not Defined(_CRT_MANAGED_HEAP_NO_WARNINGS)
    _CRT_MANAGED_HEAP_NO_WARNINGS equ <>
  endif
  ifndef _CRT_MANAGED_HEAP_DEPRECATE
    ifdef _CRT_MANAGED_HEAP_NO_WARNINGS
      _CRT_MANAGED_HEAP_DEPRECATE equ <>
    else
      if Defined(_M_CEE)
        ;[...]
      else
        _CRT_MANAGED_HEAP_DEPRECATE equ <>
      endif
    endif
  endif
  _SECURECRT_FILL_BUFFER_PATTERN equ 0FEh
  if Defined(_CRT_OBSOLETE_NO_DEPRECATE) and  not Defined(_CRT_OBSOLETE_NO_WARNINGS)
    _CRT_OBSOLETE_NO_WARNINGS equ <>
  endif
  ifndef _CRT_OBSOLETE
    ifdef _CRT_OBSOLETE_NO_WARNINGS
      _CRT_OBSOLETE macro _NewItem
        exitm <>
      endm
    else
      _CRT_OBSOLETE macro _NewItem
        exitm <_CRT_DEPRECATE_TEXT("This function or variable has been superceded by newer library or operating system functionality. Consider using " # _NewItem " instead. See online help for details.")>
      endm
    endif
  endif
  ifndef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    ifdef WINAPI_FAMILY
      include winapifamily.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        _CRT_USE_WINAPI_FAMILY_DESKTOP_APP equ <>
      else
        ifdef WINAPI_FAMILY_PHONE_APP
          if WINAPI_FAMILY eq WINAPI_FAMILY_PHONE_APP
            _CRT_USE_WINAPI_FAMILY_PHONE_APP equ <>
          endif
        endif
      endif
    else
      _CRT_USE_WINAPI_FAMILY_DESKTOP_APP equ <>
    endif
  endif
  ifndef _ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE
    _ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE equ 0
  endif
  ifndef _CRT_BUILD_DESKTOP_APP
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      _CRT_BUILD_DESKTOP_APP equ 1
    else
      _CRT_BUILD_DESKTOP_APP equ 0
    endif
  endif
  if Defined(_M_ARM)
    ;[...]
  endif
  ifndef _CRT_JIT_INTRINSIC
    if Defined(_M_CEE) and Defined(_M_X64)
      ;[...]
    else
      _CRT_JIT_INTRINSIC equ <>
    endif
  endif
  if  not Defined(RC_INVOKED)
    if  not Defined(_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES)
      _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES equ 0
    else
      if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
        .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
      endif
    endif
  endif
  if  not Defined(RC_INVOKED)
    if  not Defined(_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT)
      _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT equ 0
    else
      if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
        .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
      endif
    endif
  endif
  if  not Defined(RC_INVOKED)
    if  not Defined(_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES)
      if __STDC_WANT_SECURE_LIB__
        _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES equ 1
      else
        _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES equ 0
      endif
    else
      if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
        .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
      endif
    endif
  endif
  if  not Defined(RC_INVOKED)
    if  not Defined(_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY)
      _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY equ 0
    else
      if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
        .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
      endif
    endif
  endif
  if  not Defined(RC_INVOKED)
    if  not Defined(_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY)
      _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY equ 0
    else
      if  not __STDC_WANT_SECURE_LIB__ and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
        .err <Cannot use Secure CRT C ++ overloads when __STDC_WANT_SECURE_LIB__ is 0>
      endif
    endif
  endif
  if  not Defined(_CRT_SECURE_CPP_NOTHROW)
    _CRT_SECURE_CPP_NOTHROW equ <throw ()>
  endif
  if Defined(_CRT_NONSTDC_NO_DEPRECATE) and  not Defined(_CRT_NONSTDC_NO_WARNINGS)
    _CRT_NONSTDC_NO_WARNINGS equ <>
  endif
  if  not Defined(_CRT_NONSTDC_DEPRECATE)
    if Defined(_CRT_NONSTDC_NO_WARNINGS) or Defined(_POSIX_)
      _CRT_NONSTDC_DEPRECATE macro _NewName
        exitm <>
      endm
    else
      _CRT_NONSTDC_DEPRECATE macro _NewName
        exitm <_CRT_DEPRECATE_TEXT("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " # _NewName ". See online help for details.")>
      endm
    endif
  endif
  ifndef _SIZE_T_DEFINED
    ifdef _WIN64
      size_t typedef QWORD
    else
      size_t typedef _W64
    endif
    _SIZE_T_DEFINED equ <>
  endif
  if __STDC_WANT_SECURE_LIB__
    ifndef _RSIZE_T_DEFINED
      rsize_t typedef size_t
      _RSIZE_T_DEFINED equ <>
    endif
  endif
  ifndef _INTPTR_T_DEFINED
    ifdef _WIN64
      intptr_t typedef SQWORD
    else
      intptr_t typedef _W64
    endif
    _INTPTR_T_DEFINED equ <>
  endif
  ifndef _UINTPTR_T_DEFINED
    ifdef _WIN64
      uintptr_t typedef QWORD
    else
      uintptr_t typedef _W64
    endif
    _UINTPTR_T_DEFINED equ <>
  endif
  ifndef _PTRDIFF_T_DEFINED
    ifdef _WIN64
      ptrdiff_t typedef SQWORD
    else
      ptrdiff_t typedef _W64
    endif
    _PTRDIFF_T_DEFINED equ <>
  endif
  ifndef _WCHAR_T_DEFINED
    wchar_t typedef WORD
    _WCHAR_T_DEFINED equ <>
  endif
  ifndef _WCTYPE_T_DEFINED
    wint_t typedef WORD
    wctype_t typedef WORD
    _WCTYPE_T_DEFINED equ <>
  endif
  ifndef _VA_LIST_DEFINED
    ifdef _M_CEE_PURE
      ;[...]
    else
      va_list typedef ptr SBYTE
    endif
    _VA_LIST_DEFINED equ <>
  endif
  ifdef _USE_32BIT_TIME_T
    ifdef _WIN64
      .err <You cannot use 32 - bit time_t ( _USE_32BIT_TIME_T ) with _WIN64>
    endif
  endif
  ifndef _ERRNO_T_DEFINED
    _ERRNO_T_DEFINED equ <>
    errno_t typedef SDWORD
  endif
  ifndef _TIME32_T_DEFINED
    __time32_t typedef _W64
    _TIME32_T_DEFINED equ <>
  endif
  ifndef _TIME64_T_DEFINED
    __time64_t typedef SQWORD
    _TIME64_T_DEFINED equ <>
  endif
  ifndef _TIME_T_DEFINED
    ifdef _USE_32BIT_TIME_T
      time_t typedef __time32_t
    else
      time_t typedef __time64_t
    endif
    _TIME_T_DEFINED equ <>
  endif
  ifndef _CONST_RETURN
    ifdef __cplusplus
      ;[...]
    else
      _CONST_RETURN equ <>
    endif
  endif
  if Defined(_M_X64) or Defined(_M_ARM)
    _UNALIGNED equ <__unaligned>
  else
    _UNALIGNED equ <>
  endif
  if  not Defined(_CRT_ALIGN)
    if Defined(__midl)
      ;[...]
    else
      _CRT_ALIGN macro x
        exitm <__declspec(align(x))>
      endm
    endif
  endif
  ifndef _CRTNOALIAS
    _CRTNOALIAS equ <__declspec(noalias)>
  endif
  ifndef _CRTRESTRICT
    _CRTRESTRICT equ <__declspec(restrict)>
  endif
  if  not Defined(__CRTDECL)
    if Defined(_M_CEE_PURE)
      ;[...]
    else
      __CRTDECL equ <__cdecl>
    endif
  endif
  __STR2WSTR macro str_
    exitm <L ## str_>
  endm
  _STR2WSTR macro str_
    exitm <__STR2WSTR(str_)>
  endm
  __FILEW__ equ <_STR2WSTR(__FILE__)>
  __FUNCTIONW__ equ <_STR2WSTR(__FUNCTION__)>
  ifdef _DEBUG
    @DefProto DllImport, _invalid_parameter, c,, <:ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :DWORD, :uintptr_t>
  else
    @DefProto DllImport, _invalid_parameter_noinfo, c,, <>
    @DefProto DllImport, _invalid_parameter_noinfo_noreturn, c,, <>
  endif
  @DefProto DllImport, _invoke_watson, c,, <:ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :DWORD, :uintptr_t>
  ifdef _DEBUG
    ifndef _CRT_SECURE_INVALID_PARAMETER
      _CRT_SECURE_INVALID_PARAMETER macro expr
        exitm <:: _invalid_parameter (__STR2WSTR(# expr), __FUNCTIONW__, __FILEW__, __LINE__, 0)>
      endm
    endif
  else
    ifndef _CRT_SECURE_INVALID_PARAMETER
      _CRT_SECURE_INVALID_PARAMETER macro expr
        exitm <:: _invalid_parameter_noinfo_noreturn ()>
      endm
    endif
  endif
  _ARGMAX equ 100
  if  not Defined(_TRUNCATE)
    _TRUNCATE equ (- 1)
  endif
  if  not Defined(RC_INVOKED)
    if Defined(__cplusplus) and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
      ;[...]
    else
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0 macro _ReturnType, _FuncName, _DstType, _Dst
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4 macro _ReturnType, _FuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1 macro _ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2 macro _ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3 macro _ReturnType, _FuncName, _HType1, _HArg1, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0 macro _ReturnType, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _DstType, _Dst
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST macro _ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST macro _ReturnType, _FuncName, _VFuncName, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH macro _ReturnType, _FuncName, _DstType, _Src
        exitm <>
      endm
    endif
  endif
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _VFuncName, _VFuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _VFuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _DstType, _Dst, _TType1, _TArg1)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0 macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX(_ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _FuncName ## _s, _VFuncName, _VFuncName ## _s, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2)>
  endm
  __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE macro _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
    exitm <__DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX(_DeclSpec, _FuncName, _FuncName ## _s, _DstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3)>
  endm
  if  not Defined(RC_INVOKED)
    if Defined(__cplusplus) and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
      ;[...]
    else
      __RETURN_POLICY_SAME macro _FunctionCall
        exitm <>
      endm
      __RETURN_POLICY_DST macro _FunctionCall
        exitm <>
      endm
      __RETURN_POLICY_VOID macro _FunctionCall
        exitm <>
      endm
      __EMPTY_DECLSPEC equ <>
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_0_CGETS macro _ReturnType, _DeclSpec, _FuncName, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_4_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_1_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_2_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_1_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1,...) ; _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureVFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2,...) ; _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_3_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_0_GETS macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_4_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3, _TType4, _TArg4
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3, _TType4 _TArg4) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_1_1_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _SalAttributeDst _DstType * _Dst, _TType1 _TArg1) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_2_0_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _HType1, _HArg1, _HType2, _HArg2, _SalAttributeDst, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_HType1 _HArg1, _HType2 _HArg2, _SalAttributeDst _DstType * _Dst) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_1_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _SecureFuncName, _VFuncName, _SecureVFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1,...) ; _CRT_INSECURE_DEPRECATE(_SecureVFuncName) _DeclSpec _ReturnType __cdecl _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2,...) ; _CRT_INSECURE_DEPRECATE(_VFuncName ## _s) _DeclSpec _ReturnType __cdecl _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_ARGLIST_EX macro _ReturnType, _ReturnPolicy, _DeclSpec, _FuncName, _VFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_FuncName ## _s) _DeclSpec _ReturnType __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2,...) ; _CRT_INSECURE_DEPRECATE(_VFuncName ## _s) _DeclSpec _ReturnType __cdecl _VFuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, va_list _Args) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_2_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2) ;>
      endm
      __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE_EX macro _DeclSpec, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) _DeclSpec size_t __cdecl _FuncName (_SalAttributeDst _DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3) ;>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_FUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_0_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_1_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_2_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2
        exitm <>
      endm
      __DECLARE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <_CRT_INSECURE_DEPRECATE(_SecureFuncName) __inline _ReturnType __CRTDECL _FuncName (_DstType * _Dst, _TType1 _TArg1, _TType2 _TArg2, _TType3 _TArg3)>
      endm
      __DEFINE_CPP_OVERLOAD_INLINE_NFUNC_0_3_EX macro _ReturnType, _ReturnPolicy, _FuncName, _SecureFuncName, _SecureDstType, _SalAttributeDst, _DstType, _Dst, _TType1, _TArg1, _TType2, _TArg2, _TType3, _TArg3
        exitm <>
      endm
    endif
  endif
  pthreadlocinfo typedef POINTER;ptr threadlocaleinfostruct
  
  pthreadmbcinfo typedef ptr threadmbcinfostruct
  
  _locale_tstruct struct
    locinfo pthreadlocinfo ?
    mbcinfo pthreadmbcinfo ?
  _locale_tstruct ends
  localeinfo_struct typedef _locale_tstruct
  _locale_t typedef ptr _locale_tstruct
  
  ifndef _THREADLOCALEINFO
    locrefcount struct
      locale POINTER ?
      wlocale POINTER ?
      refcount POINTER ?
      wrefcount POINTER ?
    locrefcount ends
    localerefcount typedef locrefcount
    threadlocinfo struct
      refcount SDWORD ?
      lc_codepage DWORD ?
      lc_collate_cp DWORD ?
      lc_time_cp DWORD ?
      lc_category locrefcount 6 dup (<>)
      lc_clike SDWORD ?
      mb_cur_max SDWORD ?
      lconv_intl_refcount POINTER ?
      lconv_num_refcount POINTER ?
      lconv_mon_refcount POINTER ?
      lconv POINTER ?
      ctype1_refcount POINTER ?
      ctype1 POINTER ?
      pctype POINTER ?
      pclmap POINTER ?
      pcumap POINTER ?
      lc_time_curr POINTER ?
      locale_name POINTER 6 dup (?)
    threadlocinfo ends
    threadlocaleinfostruct typedef threadlocinfo
    _THREADLOCALEINFO equ <>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(_PREFAST_) and Defined(_CA_SHOULD_CHECK_RETURN)
    ;[...]
  else
    _Check_return_opt_ equ <>
  endif
  if Defined(_PREFAST_) and Defined(_CA_SHOULD_CHECK_RETURN_WER)
    ;[...]
  else
    _Check_return_wat_ equ <>
  endif
  if  not Defined(__midl) and  not Defined(MIDL_PASS) and Defined(_PREFAST_)
    ;[...]
  else
    __crt_typefix macro ctype
      exitm <>
    endm
  endif
  if (Defined(__midl))
    ;[...]
  endif
  ifndef _CRT_UNUSED
    _CRT_UNUSED macro x
      exitm <x>
    endm
  endif
endif

