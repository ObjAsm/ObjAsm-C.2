;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\oleauto.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 12/02/2024 17:05:56

include winapifamily.inc
if _MSC_VER ge 1200
endif
if  not Defined(_OLEAUTO_H_)
  _OLEAUTO_H_ equ <>
  if _MSC_VER gt 1000
  endif
  ifndef RC_INVOKED
    include pshpack8.inc
  endif
  ifdef _OLEAUT32_
    WINOLEAUTAPI equ <STDAPI>
    WINOLEAUTAPI_ macro type_
      exitm <STDAPI_(type_)>
    endm
  else
    WINOLEAUTAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
    WINOLEAUTAPI_ macro type_
      exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
    endm
  endif
  externdef IID_StdOle:IID
  STDOLE_MAJORVERNUM equ 1h
  STDOLE_MINORVERNUM equ 0h
  STDOLE_LCID equ 0000h
  STDOLE2_MAJORVERNUM equ 2h
  STDOLE2_MINORVERNUM equ 0h
  STDOLE2_LCID equ 0000h
  ifndef _LCID_DEFINED
    LCID typedef DWORD
    _LCID_DEFINED equ <>
  endif
  ifndef BEGIN_INTERFACE
    BEGIN_INTERFACE equ <>
    END_INTERFACE equ <>
  endif
  include oaidl.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SysAllocString, WIN_STD_CALL_CONV,, <:ptr OLECHAR>, 4
    @DefProto DllImport, SysReAllocString, WIN_STD_CALL_CONV,, <:ptr BSTR, :ptr OLECHAR>, 8
    @DefProto DllImport, SysAllocStringLen, WIN_STD_CALL_CONV,, <:ptr OLECHAR, :UINT>, 8
    @DefProto DllImport, SysReAllocStringLen, WIN_STD_CALL_CONV,, <:ptr BSTR, :ptr OLECHAR, :DWORD>, 12
    @DefProto DllImport, SysAddRefString, WIN_STD_CALL_CONV,, <:BSTR>, 4
    @DefProto DllImport, SysReleaseString, WIN_STD_CALL_CONV,, <:BSTR>, 4
    @DefProto DllImport, SysFreeString, WIN_STD_CALL_CONV,, <:BSTR>, 4
    @DefProto DllImport, SysStringLen, WIN_STD_CALL_CONV,, <:BSTR>, 4
    if (Defined(_WIN32) or Defined(_WIN64))
      @DefProto DllImport, SysStringByteLen, WIN_STD_CALL_CONV,, <:BSTR>, 4
      @DefProto DllImport, SysAllocStringByteLen, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DosDateTimeToVariantTime, WIN_STD_CALL_CONV,, <:USHORT, :USHORT, :ptr DOUBLE>, 12
    @DefProto DllImport, VariantTimeToDosDateTime, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr USHORT, :ptr USHORT>, 12
  endif
  if (Defined(_WIN32) or Defined(_WIN64))
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, SystemTimeToVariantTime, WIN_STD_CALL_CONV,, <:LPSYSTEMTIME, :ptr DOUBLE>, 8
      @DefProto DllImport, VariantTimeToSystemTime, WIN_STD_CALL_CONV,, <:DOUBLE, :LPSYSTEMTIME>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SafeArrayAllocDescriptor, WIN_STD_CALL_CONV,, <:UINT, :ptr ptr SAFEARRAY>, 8
    @DefProto DllImport, SafeArrayAllocDescriptorEx, WIN_STD_CALL_CONV,, <:VARTYPE, :UINT, :ptr ptr SAFEARRAY>, 12
    @DefProto DllImport, SafeArrayAllocData, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayCreate, WIN_STD_CALL_CONV,, <:VARTYPE, :UINT, :ptr SAFEARRAYBOUND>, 12
    @DefProto DllImport, SafeArrayCreateEx, WIN_STD_CALL_CONV,, <:VARTYPE, :UINT, :ptr SAFEARRAYBOUND, :PVOID>, 16
    @DefProto DllImport, SafeArrayCopyData, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr SAFEARRAY>, 8
    @DefProto DllImport, SafeArrayReleaseDescriptor, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayDestroyDescriptor, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayReleaseData, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, SafeArrayDestroyData, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayAddRef, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr PVOID>, 8
    @DefProto DllImport, SafeArrayDestroy, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayRedim, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr SAFEARRAYBOUND>, 8
    @DefProto DllImport, SafeArrayGetDim, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayGetElemsize, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayGetUBound, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :UINT, :ptr LONG>, 12
    @DefProto DllImport, SafeArrayGetLBound, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :UINT, :ptr LONG>, 12
    @DefProto DllImport, SafeArrayLock, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayUnlock, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayAccessData, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr ptr>, 8
    @DefProto DllImport, SafeArrayUnaccessData, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY>, 4
    @DefProto DllImport, SafeArrayGetElement, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr LONG, :ptr>, 12
    @DefProto DllImport, SafeArrayPutElement, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr LONG, :ptr>, 12
    @DefProto DllImport, SafeArrayCopy, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr ptr SAFEARRAY>, 8
    @DefProto DllImport, SafeArrayPtrOfIndex, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr LONG, :ptr ptr>, 12
    @DefProto DllImport, SafeArraySetRecordInfo, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr IRecordInfo>, 8
    @DefProto DllImport, SafeArrayGetRecordInfo, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr ptr IRecordInfo>, 8
    @DefProto DllImport, SafeArraySetIID, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :REFGUID>, 8
    @DefProto DllImport, SafeArrayGetIID, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr GUID>, 8
    @DefProto DllImport, SafeArrayGetVartype, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr VARTYPE>, 8
    @DefProto DllImport, SafeArrayCreateVector, WIN_STD_CALL_CONV,, <:VARTYPE, :LONG, :ULONG>, 12
    @DefProto DllImport, SafeArrayCreateVectorEx, WIN_STD_CALL_CONV,, <:VARTYPE, :LONG, :ULONG, :PVOID>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VariantInit, WIN_STD_CALL_CONV,, <:ptr VARIANTARG>, 4
    @DefProto DllImport, VariantClear, WIN_STD_CALL_CONV,, <:ptr VARIANTARG>, 4
    @DefProto DllImport, VariantCopy, WIN_STD_CALL_CONV,, <:ptr VARIANTARG, :ptr VARIANTARG>, 8
    @DefProto DllImport, VariantCopyInd, WIN_STD_CALL_CONV,, <:ptr VARIANT, :ptr VARIANTARG>, 8
    @DefProto DllImport, VariantChangeType, WIN_STD_CALL_CONV,, <:ptr VARIANTARG, :ptr VARIANTARG, :USHORT, :VARTYPE>, 16
    @DefProto DllImport, VariantChangeTypeEx, WIN_STD_CALL_CONV,, <:ptr VARIANTARG, :ptr VARIANTARG, :LCID, :USHORT, :VARTYPE>, 20
  endif
  VARIANT_NOVALUEPROP equ 01h
  VARIANT_ALPHABOOL equ 02h
  VARIANT_NOUSEROVERRIDE equ 04h
  VARIANT_CALENDAR_HIJRI equ 08h
  VARIANT_LOCALBOOL equ 10h
  VARIANT_CALENDAR_THAI equ 20h
  VARIANT_CALENDAR_GREGORIAN equ 40h
  VARIANT_USE_NLS equ 80h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VectorFromBstr, WIN_STD_CALL_CONV,, <:BSTR, :ptr ptr SAFEARRAY>, 8
    @DefProto DllImport, BstrFromVector, WIN_STD_CALL_CONV,, <:ptr SAFEARRAY, :ptr BSTR>, 8
  endif
  VAR_TIMEVALUEONLY equ (00000001h)
  VAR_DATEVALUEONLY equ (00000002h)
  VAR_VALIDDATE equ (00000004h)
  VAR_CALENDAR_HIJRI equ (00000008h)
  VAR_LOCALBOOL equ (00000010h)
  VAR_FORMAT_NOSUBSTITUTE equ (00000020h)
  VAR_FOURDIGITYEARS equ (00000040h)
  ifndef LOCALE_USE_NLS
    LOCALE_USE_NLS equ 10000000h
  endif
  VAR_CALENDAR_THAI equ (00000080h)
  VAR_CALENDAR_GREGORIAN equ (00000100h)
  VTDATEGRE_MAX equ 2958465
  VTDATEGRE_MIN equ -657434
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarUI1FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr BYTE>, 16
    @DefProto DllImport, VarUI1FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr BYTE>, 12
    @DefProto DllImport, VarUI1FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr BYTE>, 8
    @DefProto DllImport, VarUI1FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr BYTE>, 8
    @DefProto DllImport, VarI2FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr SHORT_>, 16
    @DefProto DllImport, VarI2FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr SHORT_>, 12
    @DefProto DllImport, VarI2FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr SHORT_>, 8
    @DefProto DllImport, VarI2FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr SHORT_>, 8
    @DefProto DllImport, VarI4FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr LONG>, 16
    @DefProto DllImport, VarI4FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr LONG>, 12
    @DefProto DllImport, VarI4FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr LONG>, 8
    @DefProto DllImport, VarI8FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr LONG64>, 16
    @DefProto DllImport, VarI8FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr LONG64>, 12
    @DefProto DllImport, VarI8FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr LONG64>, 8
    @DefProto DllImport, VarI8FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr LONG64>, 8
    @DefProto DllImport, VarR4FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr FLOAT>, 16
    @DefProto DllImport, VarR4FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr FLOAT>, 12
    @DefProto DllImport, VarR4FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr FLOAT>, 8
    @DefProto DllImport, VarR4FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr FLOAT>, 8
    @DefProto DllImport, VarR8FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr DOUBLE>, 16
    @DefProto DllImport, VarR8FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr DOUBLE>, 12
    @DefProto DllImport, VarR8FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr DOUBLE>, 8
    @DefProto DllImport, VarR8FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr DOUBLE>, 8
    @DefProto DllImport, VarDateFromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromCy, WIN_STD_CALL_CONV,, <:CY, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr DATE>, 16
    @DefProto DllImport, VarDateFromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr DATE>, 12
    @DefProto DllImport, VarDateFromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr DATE>, 8
    @DefProto DllImport, VarDateFromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr DATE>, 8
    @DefProto DllImport, VarCyFromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr CY>, 8
    @DefProto DllImport, VarCyFromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr CY>, 8
    @DefProto DllImport, VarCyFromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr CY>, 8
    @DefProto DllImport, VarCyFromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr CY>, 8
    @DefProto DllImport, VarCyFromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr CY>, 8
    @DefProto DllImport, VarCyFromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr CY>, 8
    @DefProto DllImport, VarCyFromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr CY>, 8
    @DefProto DllImport, VarCyFromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr CY>, 16
    @DefProto DllImport, VarCyFromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr CY>, 12
    @DefProto DllImport, VarCyFromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr CY>, 8
    @DefProto DllImport, VarCyFromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr CY>, 8
    @DefProto DllImport, VarCyFromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr CY>, 8
    @DefProto DllImport, VarCyFromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr CY>, 8
    @DefProto DllImport, VarCyFromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr CY>, 8
    @DefProto DllImport, VarCyFromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr CY>, 8
    @DefProto DllImport, VarBstrFromUI1, WIN_STD_CALL_CONV,, <:BYTE, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromI2, WIN_STD_CALL_CONV,, <:SHORT_, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromI4, WIN_STD_CALL_CONV,, <:LONG, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromI8, WIN_STD_CALL_CONV,, <:LONG64, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromR4, WIN_STD_CALL_CONV,, <:FLOAT, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromCy, WIN_STD_CALL_CONV,, <:CY, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromDate, WIN_STD_CALL_CONV,, <:DATE, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromI1, WIN_STD_CALL_CONV,, <:CHAR, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromUI2, WIN_STD_CALL_CONV,, <:USHORT, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromUI4, WIN_STD_CALL_CONV,, <:ULONG, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBstrFromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :LCID, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarBoolFromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromCy, WIN_STD_CALL_CONV,, <:CY, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr VARIANT_BOOL>, 16
    @DefProto DllImport, VarBoolFromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr VARIANT_BOOL>, 12
    @DefProto DllImport, VarBoolFromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarBoolFromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr VARIANT_BOOL>, 8
    @DefProto DllImport, VarI1FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr CHAR>, 16
    @DefProto DllImport, VarI1FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr CHAR>, 12
    @DefProto DllImport, VarI1FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr CHAR>, 8
    @DefProto DllImport, VarI1FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr CHAR>, 8
    @DefProto DllImport, VarUI2FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr USHORT>, 16
    @DefProto DllImport, VarUI2FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr USHORT>, 12
    @DefProto DllImport, VarUI2FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr USHORT>, 8
    @DefProto DllImport, VarUI2FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr USHORT>, 8
    @DefProto DllImport, VarUI4FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr ULONG>, 16
    @DefProto DllImport, VarUI4FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr ULONG>, 12
    @DefProto DllImport, VarUI4FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr ULONG>, 8
    @DefProto DllImport, VarUI4FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr ULONG>, 8
    @DefProto DllImport, VarUI8FromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr ULONG64>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, VarUI8FromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr ULONG64>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarUI8FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromCy, WIN_STD_CALL_CONV,, <:CY, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr ULONG64>, 16
    @DefProto DllImport, VarUI8FromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr ULONG64>, 12
    @DefProto DllImport, VarUI8FromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr ULONG64>, 8
    @DefProto DllImport, VarUI8FromDec, WIN_STD_CALL_CONV,, <:ptr DECIMAL, :ptr ULONG64>, 8
    @DefProto DllImport, VarDecFromUI1, WIN_STD_CALL_CONV,, <:BYTE, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromI2, WIN_STD_CALL_CONV,, <:SHORT_, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromI4, WIN_STD_CALL_CONV,, <:LONG, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromR4, WIN_STD_CALL_CONV,, <:FLOAT, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromR8, WIN_STD_CALL_CONV,, <:DOUBLE, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromDate, WIN_STD_CALL_CONV,, <:DATE, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromCy, WIN_STD_CALL_CONV,, <:CY, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr DECIMAL>, 16
    @DefProto DllImport, VarDecFromDisp, WIN_STD_CALL_CONV,, <:ptr IDispatch, :LCID, :ptr DECIMAL>, 12
    @DefProto DllImport, VarDecFromBool, WIN_STD_CALL_CONV,, <:VARIANT_BOOL, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromI1, WIN_STD_CALL_CONV,, <:CHAR, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromUI2, WIN_STD_CALL_CONV,, <:USHORT, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromUI4, WIN_STD_CALL_CONV,, <:ULONG, :ptr DECIMAL>, 8
    @DefProto DllImport, VarDecFromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr DECIMAL>, 8
  endif
  VarUI4FromUI4 macro in_, pOut
    exitm <(* (pOut) = (in_))>
  endm
  VarI4FromI4 macro in_, pOut
    exitm <(* (pOut) = (in_))>
  endm
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarI4FromI8, WIN_STD_CALL_CONV,, <:LONG64, :ptr LONG>, 8
    @DefProto DllImport, VarI4FromUI8, WIN_STD_CALL_CONV,, <:ULONG64, :ptr LONG>, 8
  endif
  VarUI8FromUI8 macro in_, pOut
    exitm <(* (pOut) = (in_))>
  endm
  VarI8FromI8 macro in_, pOut
    exitm <(* (pOut) = (in_))>
  endm
  VarUI1FromInt equ <VarUI1FromI4>
  VarUI1FromUint equ <VarUI1FromUI4>
  VarI2FromInt equ <VarI2FromI4>
  VarI2FromUint equ <VarI2FromUI4>
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    VarI4FromInt equ <VarI4FromI4>
  endif
  VarI4FromUint equ <VarI4FromUI4>
  VarI8FromUint equ <VarI8FromUI4>
  VarR4FromInt equ <VarR4FromI4>
  VarR4FromUint equ <VarR4FromUI4>
  VarR8FromInt equ <VarR8FromI4>
  VarR8FromUint equ <VarR8FromUI4>
  VarDateFromInt equ <VarDateFromI4>
  VarDateFromUint equ <VarDateFromUI4>
  VarCyFromInt equ <VarCyFromI4>
  VarCyFromUint equ <VarCyFromUI4>
  VarBstrFromInt equ <VarBstrFromI4>
  VarBstrFromUint equ <VarBstrFromUI4>
  VarBoolFromInt equ <VarBoolFromI4>
  VarBoolFromUint equ <VarBoolFromUI4>
  VarI1FromInt equ <VarI1FromI4>
  VarI1FromUint equ <VarI1FromUI4>
  VarUI2FromInt equ <VarUI2FromI4>
  VarUI2FromUint equ <VarUI2FromUI4>
  VarUI4FromInt equ <VarUI4FromI4>
  VarUI4FromUint equ <VarUI4FromUI4>
  VarDecFromInt equ <VarDecFromI4>
  VarDecFromUint equ <VarDecFromUI4>
  VarIntFromUI1 equ <VarI4FromUI1>
  VarIntFromI2 equ <VarI4FromI2>
  VarIntFromI4 equ <VarI4FromI4>
  VarIntFromI8 equ <VarI4FromI8>
  VarIntFromR4 equ <VarI4FromR4>
  VarIntFromR8 equ <VarI4FromR8>
  VarIntFromDate equ <VarI4FromDate>
  VarIntFromCy equ <VarI4FromCy>
  VarIntFromStr equ <VarI4FromStr>
  VarIntFromDisp equ <VarI4FromDisp>
  VarIntFromBool equ <VarI4FromBool>
  VarIntFromI1 equ <VarI4FromI1>
  VarIntFromUI2 equ <VarI4FromUI2>
  VarIntFromUI4 equ <VarI4FromUI4>
  VarIntFromUI8 equ <VarI4FromUI8>
  VarIntFromDec equ <VarI4FromDec>
  VarIntFromUint equ <VarI4FromUI4>
  VarUintFromUI1 equ <VarUI4FromUI1>
  VarUintFromI2 equ <VarUI4FromI2>
  VarUintFromI4 equ <VarUI4FromI4>
  VarUintFromI8 equ <VarUI4FromI8>
  VarUintFromR4 equ <VarUI4FromR4>
  VarUintFromR8 equ <VarUI4FromR8>
  VarUintFromDate equ <VarUI4FromDate>
  VarUintFromCy equ <VarUI4FromCy>
  VarUintFromStr equ <VarUI4FromStr>
  VarUintFromDisp equ <VarUI4FromDisp>
  VarUintFromBool equ <VarUI4FromBool>
  VarUintFromI1 equ <VarUI4FromI1>
  VarUintFromUI2 equ <VarUI4FromUI2>
  VarUintFromUI4 equ <VarUI4FromUI4>
  VarUintFromUI8 equ <VarUI4FromUI8>
  VarUintFromDec equ <VarUI4FromDec>
  VarUintFromInt equ <VarUI4FromI4>
  NUMPARSE struct
    cDig INT_ ?
    dwInFlags ULONG ?
    dwOutFlags ULONG ?
    cchUsed INT_ ?
    nBaseShift INT_ ?
    nPwr10 INT_ ?
  NUMPARSE ends
  NUMPRS_LEADING_WHITE equ 0001h
  NUMPRS_TRAILING_WHITE equ 0002h
  NUMPRS_LEADING_PLUS equ 0004h
  NUMPRS_TRAILING_PLUS equ 0008h
  NUMPRS_LEADING_MINUS equ 0010h
  NUMPRS_TRAILING_MINUS equ 0020h
  NUMPRS_HEX_OCT equ 0040h
  NUMPRS_PARENS equ 0080h
  NUMPRS_DECIMAL equ 0100h
  NUMPRS_THOUSANDS equ 0200h
  NUMPRS_CURRENCY equ 0400h
  NUMPRS_EXPONENT equ 0800h
  NUMPRS_USE_ALL equ 1000h
  NUMPRS_STD equ 1FFFh
  NUMPRS_NEG equ 10000h
  NUMPRS_INEXACT equ 20000h
  VTBIT_I1 equ (1 shl VT_I1)
  VTBIT_UI1 equ (1 shl VT_UI1)
  VTBIT_I2 equ (1 shl VT_I2)
  VTBIT_UI2 equ (1 shl VT_UI2)
  VTBIT_I4 equ (1 shl VT_I4)
  VTBIT_UI4 equ (1 shl VT_UI4)
  VTBIT_I8 equ (1 shl VT_I8)
  VTBIT_UI8 equ (1 shl VT_UI8)
  VTBIT_R4 equ (1 shl VT_R4)
  VTBIT_R8 equ (1 shl VT_R8)
  VTBIT_CY equ (1 shl VT_CY)
  VTBIT_DECIMAL equ (1 shl VT_DECIMAL)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarParseNumFromStr, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LCID, :ULONG, :ptr NUMPARSE, :ptr BYTE>, 20
    @DefProto DllImport, VarNumFromParseNum, WIN_STD_CALL_CONV,, <:ptr NUMPARSE, :ptr BYTE, :ULONG, :ptr VARIANT>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarAdd, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarAnd, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarCat, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarDiv, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarEqv, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarIdiv, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarImp, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarMod, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarMul, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarOr, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarPow, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarSub, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarXor, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LPVARIANT>, 12
    @DefProto DllImport, VarAbs, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT>, 8
    @DefProto DllImport, VarFix, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT>, 8
    @DefProto DllImport, VarInt, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT>, 8
    @DefProto DllImport, VarNeg, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT>, 8
    @DefProto DllImport, VarNot, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT>, 8
    @DefProto DllImport, VarRound, WIN_STD_CALL_CONV,, <:LPVARIANT, :SDWORD, :LPVARIANT>, 12
    @DefProto DllImport, VarCmp, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPVARIANT, :LCID, :ULONG>, 16
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarDecAdd, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL, :LPDECIMAL>, 12
    @DefProto DllImport, VarDecDiv, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL, :LPDECIMAL>, 12
    @DefProto DllImport, VarDecMul, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL, :LPDECIMAL>, 12
    @DefProto DllImport, VarDecSub, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL, :LPDECIMAL>, 12
    @DefProto DllImport, VarDecAbs, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL>, 8
    @DefProto DllImport, VarDecFix, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL>, 8
    @DefProto DllImport, VarDecInt, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL>, 8
    @DefProto DllImport, VarDecNeg, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL>, 8
    @DefProto DllImport, VarDecRound, WIN_STD_CALL_CONV,, <:LPDECIMAL, :SDWORD, :LPDECIMAL>, 12
    @DefProto DllImport, VarDecCmp, WIN_STD_CALL_CONV,, <:LPDECIMAL, :LPDECIMAL>, 8
    @DefProto DllImport, VarDecCmpR8, WIN_STD_CALL_CONV,, <:LPDECIMAL, :REAL8>, 8
    @DefProto DllImport, VarCyAdd, WIN_STD_CALL_CONV,, <:CY, :CY, :LPCY>, 12
    @DefProto DllImport, VarCyMul, WIN_STD_CALL_CONV,, <:CY, :CY, :LPCY>, 12
    @DefProto DllImport, VarCyMulI4, WIN_STD_CALL_CONV,, <:CY, :LONG, :LPCY>, 12
    @DefProto DllImport, VarCyMulI8, WIN_STD_CALL_CONV,, <:CY, :LONG64, :LPCY>, 12
    @DefProto DllImport, VarCySub, WIN_STD_CALL_CONV,, <:CY, :CY, :LPCY>, 12
    @DefProto DllImport, VarCyAbs, WIN_STD_CALL_CONV,, <:CY, :LPCY>, 8
    @DefProto DllImport, VarCyFix, WIN_STD_CALL_CONV,, <:CY, :LPCY>, 8
    @DefProto DllImport, VarCyInt, WIN_STD_CALL_CONV,, <:CY, :LPCY>, 8
    @DefProto DllImport, VarCyNeg, WIN_STD_CALL_CONV,, <:CY, :LPCY>, 8
    @DefProto DllImport, VarCyRound, WIN_STD_CALL_CONV,, <:CY, :SDWORD, :LPCY>, 12
    @DefProto DllImport, VarCyCmp, WIN_STD_CALL_CONV,, <:CY, :CY>, 8
    @DefProto DllImport, VarCyCmpR8, WIN_STD_CALL_CONV,, <:CY, :REAL8>, 8
    @DefProto DllImport, VarBstrCat, WIN_STD_CALL_CONV,, <:BSTR, :BSTR, :LPBSTR>, 12
    @DefProto DllImport, VarBstrCmp, WIN_STD_CALL_CONV,, <:BSTR, :BSTR, :LCID, :ULONG>, 16
    @DefProto DllImport, VarR8Pow, WIN_STD_CALL_CONV,, <:REAL8, :REAL8, :ptr REAL8>, 12
    @DefProto DllImport, VarR4CmpR8, WIN_STD_CALL_CONV,, <:REAL4, :REAL8>, 8
    @DefProto DllImport, VarR8Round, WIN_STD_CALL_CONV,, <:REAL8, :SDWORD, :ptr REAL8>, 12
  endif
  VARCMP_LT equ 0
  VARCMP_EQ equ 1
  VARCMP_GT equ 2
  VARCMP_NULL equ 3
  VT_HARDTYPE equ <VT_RESERVED>
  UDATE struct
    st_ SYSTEMTIME <>
    wDayOfYear USHORT ?
  UDATE ends
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarDateFromUdate, WIN_STD_CALL_CONV,, <:ptr UDATE, :ULONG, :ptr DATE>, 12
    @DefProto DllImport, VarDateFromUdateEx, WIN_STD_CALL_CONV,, <:ptr UDATE, :LCID, :ULONG, :ptr DATE>, 16
    @DefProto DllImport, VarUdateFromDate, WIN_STD_CALL_CONV,, <:DATE, :ULONG, :ptr UDATE>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetAltMonthNames, WIN_STD_CALL_CONV,, <:LCID, :ptr ptr LPOLESTR>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VarFormat, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPOLESTR, :SDWORD, :SDWORD, :ULONG, :ptr BSTR>, 24
    @DefProto DllImport, VarFormatDateTime, WIN_STD_CALL_CONV,, <:LPVARIANT, :SDWORD, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarFormatNumber, WIN_STD_CALL_CONV,, <:LPVARIANT, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ULONG, :ptr BSTR>, 28
    @DefProto DllImport, VarFormatPercent, WIN_STD_CALL_CONV,, <:LPVARIANT, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ULONG, :ptr BSTR>, 28
    @DefProto DllImport, VarFormatCurrency, WIN_STD_CALL_CONV,, <:LPVARIANT, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ULONG, :ptr BSTR>, 28
    @DefProto DllImport, VarWeekdayName, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :ULONG, :ptr BSTR>, 20
    @DefProto DllImport, VarMonthName, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :ULONG, :ptr BSTR>, 16
    @DefProto DllImport, VarFormatFromTokens, WIN_STD_CALL_CONV,, <:LPVARIANT, :LPOLESTR, :LPBYTE, :ULONG, :ptr BSTR, :LCID>, 24
    @DefProto DllImport, VarTokenizeFormatString, WIN_STD_CALL_CONV,, <:LPOLESTR, :LPBYTE, :SDWORD, :SDWORD, :SDWORD, :LCID, :ptr SDWORD>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    LPTYPELIB typedef ptr ITypeLib
    DISPID typedef LONG
    MEMBERID typedef DISPID
    MEMBERID_NIL equ <DISPID_UNKNOWN>
    ID_DEFAULTINST equ -2
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    DISPATCH_METHOD equ 1h
    DISPATCH_PROPERTYGET equ 2h
    DISPATCH_PROPERTYPUT equ 4h
    DISPATCH_PROPERTYPUTREF equ 8h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    LPTYPEINFO typedef ptr ITypeInfo
    LPTYPECOMP typedef ptr ITypeComp
    LPCREATETYPELIB typedef ptr ICreateTypeLib
    LPCREATETYPEINFO typedef ptr ICreateTypeInfo
    if (Defined(_WIN32) or Defined(_WIN64))
      @DefProto DllImport, LHashValOfNameSysA, WIN_STD_CALL_CONV,, <:SYSKIND, :LCID, :LPCSTR>, 12
    endif
    @DefProto DllImport, LHashValOfNameSys, WIN_STD_CALL_CONV,, <:SYSKIND, :LCID, :ptr OLECHAR>, 12
    LHashValOfName macro lcid, szName
      exitm <LHashValOfNameSys (SYS_WIN32, lcid, szName)>
    endm
    WHashValOfLHashVal macro lhashval
      exitm <((0000ffffh and (lhashval)))>
    endm
    IsHashValCompatible macro lhashval1, lhashval2
      exitm <(((00ff0000h and (lhashval1)) == (00ff0000h and (lhashval2))))>
    endm
    @DefProto DllImport, LoadTypeLib, WIN_STD_CALL_CONV,, <:LPCOLESTR, :ptr ptr ITypeLib>, 8
    REGKIND typedef SDWORD
    REGKIND_DEFAULT equ 0
    REGKIND_REGISTER equ 1
    REGKIND_NONE equ 2
    tagREGKIND typedef REGKIND

    LOAD_TLB_AS_32BIT equ 20h
    LOAD_TLB_AS_64BIT equ 40h
    MASK_TO_RESET_TLB_BITS equ <not (LOAD_TLB_AS_32BIT or LOAD_TLB_AS_64BIT)>
    @DefProto DllImport, LoadTypeLibEx, WIN_STD_CALL_CONV,, <:LPCOLESTR, :REGKIND, :ptr ptr ITypeLib>, 12
    @DefProto DllImport, LoadRegTypeLib, WIN_STD_CALL_CONV,, <:REFGUID, :WORD, :WORD, :LCID, :ptr ptr ITypeLib>, 20
    @DefProto DllImport, QueryPathOfRegTypeLib, WIN_STD_CALL_CONV,, <:REFGUID, :USHORT, :USHORT, :LCID, :LPBSTR>, 20
    @DefProto DllImport, RegisterTypeLib, WIN_STD_CALL_CONV,, <:ptr ITypeLib, :LPCOLESTR, :LPCOLESTR>, 12
    @DefProto DllImport, UnRegisterTypeLib, WIN_STD_CALL_CONV,, <:REFGUID, :WORD, :WORD, :LCID, :SYSKIND>, 20
    @DefProto DllImport, RegisterTypeLibForUser, WIN_STD_CALL_CONV,, <:ptr ITypeLib, :ptr OLECHAR, :ptr OLECHAR>, 12
    @DefProto DllImport, UnRegisterTypeLibForUser, WIN_STD_CALL_CONV,, <:REFGUID, :WORD, :WORD, :LCID, :SYSKIND>, 20
    @DefProto DllImport, CreateTypeLib, WIN_STD_CALL_CONV,, <:SYSKIND, :LPCOLESTR, :ptr ptr ICreateTypeLib>, 12
    @DefProto DllImport, CreateTypeLib2, WIN_STD_CALL_CONV,, <:SYSKIND, :LPCOLESTR, :ptr ptr ICreateTypeLib2>, 12
    LPDISPATCH typedef ptr IDispatch
    PARAMDATA struct
      szName POINTER ?
      vt VARTYPE ?
    PARAMDATA ends
    tagPARAMDATA typedef PARAMDATA
    LPPARAMDATA typedef ptr PARAMDATA
    METHODDATA struct
      szName POINTER ?
      ppdata POINTER ?
      dispid DISPID ?
      iMeth UINT ?
      cc CALLCONV ?
      cArgs UINT ?
      wFlags WORD ?
      vtReturn VARTYPE ?
    METHODDATA ends
    tagMETHODDATA typedef METHODDATA
    LPMETHODDATA typedef ptr METHODDATA
    INTERFACEDATA struct
      pmethdata POINTER ?
      cMembers UINT ?
    INTERFACEDATA ends
    tagINTERFACEDATA typedef INTERFACEDATA
    LPINTERFACEDATA typedef ptr INTERFACEDATA
    @DefProto DllImport, DispGetParam, WIN_STD_CALL_CONV,, <:ptr DISPPARAMS, :UINT, :VARTYPE, :ptr VARIANT, :ptr UINT>, 20
    @DefProto DllImport, DispGetIDsOfNames, WIN_STD_CALL_CONV,, <:ptr ITypeInfo, :ptr LPOLESTR, :UINT, :ptr DISPID>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DispInvoke, WIN_STD_CALL_CONV,, <:ptr, :ptr ITypeInfo, :DISPID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT>, 32
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CreateDispTypeInfo, WIN_STD_CALL_CONV,, <:ptr INTERFACEDATA, :LCID, :ptr ptr ITypeInfo>, 12
    @DefProto DllImport, CreateStdDispatch, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr, :ptr ITypeInfo, :ptr ptr IUnknown>, 16
    @DefProto DllImport, DispCallFunc, WIN_STD_CALL_CONV,, <:ptr, :ULONG_PTR, :CALLCONV, :VARTYPE, :UINT, :ptr VARTYPE, :ptr ptr VARIANTARG, :ptr VARIANT>, 32
    ACTIVEOBJECT_STRONG equ 0h
    ACTIVEOBJECT_WEAK equ 1h
    @DefProto DllImport, RegisterActiveObject, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFCLSID, :DWORD, :ptr DWORD>, 16
    @DefProto DllImport, RevokeActiveObject, WIN_STD_CALL_CONV,, <:DWORD, :ptr>, 8
    @DefProto DllImport, GetActiveObject, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr, :ptr ptr IUnknown>, 12
    @DefProto DllImport, SetErrorInfo, WIN_STD_CALL_CONV,, <:ULONG, :ptr IErrorInfo>, 8
    @DefProto DllImport, GetErrorInfo, WIN_STD_CALL_CONV,, <:ULONG, :ptr ptr IErrorInfo>, 8
    @DefProto DllImport, CreateErrorInfo, WIN_STD_CALL_CONV,, <:ptr ptr ICreateErrorInfo>, 4
    @DefProto DllImport, GetRecordInfoFromTypeInfo, WIN_STD_CALL_CONV,, <:ptr ITypeInfo, :ptr ptr IRecordInfo>, 8
    @DefProto DllImport, GetRecordInfoFromGuids, WIN_STD_CALL_CONV,, <:REFGUID, :ULONG, :ULONG, :LCID, :REFGUID, :ptr ptr IRecordInfo>, 24
    @DefProto DllImport, OaBuildVersion, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, ClearCustData, WIN_STD_CALL_CONV,, <:LPCUSTDATA>, 4
    if (NTDDI_VERSION ge NTDDI_VISTASP1)
      @DefProto DllImport, OaEnablePerUserTLibRegistration, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if (__STDC__ and  not Defined(_FORCENAMELESSUNION)) or Defined(NONAMELESSUNION) or ( not Defined(_MSC_EXTENSIONS) and  not Defined(_FORCENAMELESSUNION))
    V_UNION macro X, Y
      exitm <((X) - n1.n2.n3.Y)>
    endm
    V_VT macro X
      exitm <((X) - n1.n2.vt)>
    endm
    V_RECORDINFO macro X
      exitm <((X) - n1.n2.n3.brecVal.pRecInfo)>
    endm
    V_RECORD macro X
      exitm <((X) - n1.n2.n3.brecVal.pvRecord)>
    endm
    V_DECIMAL macro X
      exitm <((X) - n1.decVal)>
    endm
  else
    V_UNION macro X, Y
      exitm <((X) - Y)>
    endm
    V_VT macro X
      exitm <((X) - vt)>
    endm
    V_RECORDINFO macro X
      exitm <((X) - pRecInfo)>
    endm
    V_RECORD macro X
      exitm <((X) - pvRecord)>
    endm
    V_DECIMAL macro X
      exitm <((X) - decVal)>
    endm
  endif
  V_ISBYREF macro X
    exitm <(V_VT(X) and VT_BYREF)>
  endm
  V_ISARRAY macro X
    exitm <(V_VT(X) and VT_ARRAY)>
  endm
  V_ISVECTOR macro X
    exitm <(V_VT(X) and VT_VECTOR)>
  endm
  V_NONE macro X
    exitm <V_I2(X)>
  endm
  V_UI1 macro X
    exitm <V_UNION(X, bVal)>
  endm
  V_UI1REF macro X
    exitm <V_UNION(X, pbVal)>
  endm
  V_I2 macro X
    exitm <V_UNION(X, iVal)>
  endm
  V_I2REF macro X
    exitm <V_UNION(X, piVal)>
  endm
  V_I4 macro X
    exitm <V_UNION(X, lVal)>
  endm
  V_I4REF macro X
    exitm <V_UNION(X, plVal)>
  endm
  V_I8 macro X
    exitm <V_UNION(X, llVal)>
  endm
  V_I8REF macro X
    exitm <V_UNION(X, pllVal)>
  endm
  V_R4 macro X
    exitm <V_UNION(X, fltVal)>
  endm
  V_R4REF macro X
    exitm <V_UNION(X, pfltVal)>
  endm
  V_R8 macro X
    exitm <V_UNION(X, dblVal)>
  endm
  V_R8REF macro X
    exitm <V_UNION(X, pdblVal)>
  endm
  V_I1 macro X
    exitm <V_UNION(X, cVal)>
  endm
  V_I1REF macro X
    exitm <V_UNION(X, pcVal)>
  endm
  V_UI2 macro X
    exitm <V_UNION(X, uiVal)>
  endm
  V_UI2REF macro X
    exitm <V_UNION(X, puiVal)>
  endm
  V_UI4 macro X
    exitm <V_UNION(X, ulVal)>
  endm
  V_UI4REF macro X
    exitm <V_UNION(X, pulVal)>
  endm
  V_UI8 macro X
    exitm <V_UNION(X, ullVal)>
  endm
  V_UI8REF macro X
    exitm <V_UNION(X, pullVal)>
  endm
  V_INT macro X
    exitm <V_UNION(X, intVal)>
  endm
  V_INTREF macro X
    exitm <V_UNION(X, pintVal)>
  endm
  V_UINT macro X
    exitm <V_UNION(X, uintVal)>
  endm
  V_UINTREF macro X
    exitm <V_UNION(X, puintVal)>
  endm
  ifdef _WIN64
    V_INT_PTR macro X
      exitm <V_UNION(X, llVal)>
    endm
    V_UINT_PTR macro X
      exitm <V_UNION(X, ullVal)>
    endm
    V_INT_PTRREF macro X
      exitm <V_UNION(X, pllVal)>
    endm
    V_UINT_PTRREF macro X
      exitm <V_UNION(X, pullVal)>
    endm
  else
    V_INT_PTR macro X
      exitm <V_UNION(X, lVal)>
    endm
    V_UINT_PTR macro X
      exitm <V_UNION(X, ulVal)>
    endm
    V_INT_PTRREF macro X
      exitm <V_UNION(X, plVal)>
    endm
    V_UINT_PTRREF macro X
      exitm <V_UNION(X, pulVal)>
    endm
  endif
  V_CY macro X
    exitm <V_UNION(X, cyVal)>
  endm
  V_CYREF macro X
    exitm <V_UNION(X, pcyVal)>
  endm
  V_DATE macro X
    exitm <V_UNION(X, date)>
  endm
  V_DATEREF macro X
    exitm <V_UNION(X, pdate)>
  endm
  V_BSTR macro X
    exitm <V_UNION(X, bstrVal)>
  endm
  V_BSTRREF macro X
    exitm <V_UNION(X, pbstrVal)>
  endm
  V_DISPATCH macro X
    exitm <V_UNION(X, pdispVal)>
  endm
  V_DISPATCHREF macro X
    exitm <V_UNION(X, ppdispVal)>
  endm
  V_ERROR macro X
    exitm <V_UNION(X, scode)>
  endm
  V_ERRORREF macro X
    exitm <V_UNION(X, pscode)>
  endm
  V_BOOL macro X
    exitm <V_UNION(X, boolVal)>
  endm
  V_BOOLREF macro X
    exitm <V_UNION(X, pboolVal)>
  endm
  V_UNKNOWN macro X
    exitm <V_UNION(X, punkVal)>
  endm
  V_UNKNOWNREF macro X
    exitm <V_UNION(X, ppunkVal)>
  endm
  V_VARIANTREF macro X
    exitm <V_UNION(X, pvarVal)>
  endm
  V_ARRAY macro X
    exitm <V_UNION(X, parray)>
  endm
  V_ARRAYREF macro X
    exitm <V_UNION(X, pparray)>
  endm
  V_BYREF macro X
    exitm <V_UNION(X, byref)>
  endm
  V_DECIMALREF macro X
    exitm <V_UNION(X, pdecVal)>
  endm
  ifndef RC_INVOKED
    include poppack.inc
  endif
endif
if _MSC_VER ge 1200
endif
