;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\basetsd.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:38

ifndef _BASETSD_H_
  _BASETSD_H_ equ <>
  if _MSC_VER ge 1200
  endif
  if  not Defined(_MAC) and (Defined(_M_MRX000) or Defined(_WIN64)) and (_MSC_VER ge 1100) and  not (Defined(MIDL_PASS) or Defined(RC_INVOKED))
    POINTER_64 equ <__ptr64>
    POINTER_64_INT typedef QWORD
    if Defined(_WIN64)
      POINTER_32 equ <__ptr32>
    else
      POINTER_32 equ <>
    endif
  else
    if Defined(_MAC) and Defined(_MAC_INT_64)
      ;[...]
    else
      if (_MSC_VER ge 1300) and  not (Defined(MIDL_PASS) or Defined(RC_INVOKED))
        POINTER_64 equ <__ptr64>
      else
        POINTER_64 equ <>
      endif
      POINTER_64_INT typedef DWORD
    endif
    POINTER_32 equ <>
  endif
  if Defined(_WIN64)
    FIRMWARE_PTR equ <>
  else
    FIRMWARE_PTR equ <POINTER_32>
  endif
  if (_MSC_FULL_VER ge 140041204) and  not Defined(MIDL_PASS) and  not Defined(RC_INVOKED)
    POINTER_SIGNED equ <__sptr>
    POINTER_UNSIGNED equ <__uptr>
  else
    POINTER_SIGNED equ <>
    POINTER_UNSIGNED equ <>
  endif
  SPOINTER_32 equ <POINTER_SIGNED POINTER_32>
  UPOINTER_32 equ <POINTER_UNSIGNED POINTER_32>
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  INT8 typedef SBYTE
  PINT8 typedef ptr SBYTE
  INT16 typedef SWORD
  PINT16 typedef ptr SWORD
  INT32 typedef SDWORD
  PINT32 typedef ptr SDWORD
  INT64 typedef SQWORD
  PINT64 typedef ptr SQWORD
  UINT8 typedef BYTE
  PUINT8 typedef ptr BYTE
  UINT16 typedef WORD
  PUINT16 typedef ptr WORD
  UINT32 typedef DWORD
  PUINT32 typedef ptr DWORD
  UINT64 typedef QWORD
  PUINT64 typedef ptr QWORD
  LONG32 typedef SDWORD
  PLONG32 typedef ptr SDWORD
  ULONG32 typedef DWORD
  PULONG32 typedef ptr DWORD
  DWORD32 typedef DWORD
  PDWORD32 typedef ptr DWORD
  if  not Defined(_W64)
    if  not Defined(__midl) and (Defined(_X86_) or Defined(_M_IX86) or Defined(_ARM_) or Defined(_M_ARM)) and _MSC_VER ge 1300
      _W64 equ <__w64>
    else
      _W64 equ <>
    endif
  endif
  if (Defined(__midl) and (501 lt __midl))
    ;[...]
  else
    if Defined(_WIN64)
      INT_PTR typedef SQWORD
      PINT_PTR typedef ptr SQWORD
      UINT_PTR typedef QWORD
      PUINT_PTR typedef ptr QWORD
      LONG_PTR typedef SQWORD
      PLONG_PTR typedef ptr SQWORD
      ULONG_PTR typedef QWORD
      PULONG_PTR typedef ptr QWORD
      __int3264 equ <__int64>
    else
      INT_PTR typedef _W64
      PINT_PTR typedef ptr _W64
      UINT_PTR typedef _W64
      PUINT_PTR typedef ptr _W64
      LONG_PTR typedef _W64
      PLONG_PTR typedef ptr _W64
      ULONG_PTR typedef _W64
      PULONG_PTR typedef ptr _W64
      __int3264 equ <__int32>
    endif
  endif
  ifndef __HANDLE64_DEFINED__
    __HANDLE64_DEFINED__ equ <>
    HANDLE64 typedef ptr
    PHANDLE64 typedef ptr HANDLE64
  endif
  ifdef _WIN64
    ADDRESS_TAG_BIT equ 40000000000h
    SHANDLE_PTR typedef SQWORD
    HANDLE_PTR typedef QWORD
    UHALF_PTR typedef DWORD
    PUHALF_PTR typedef ptr DWORD
    HALF_PTR typedef SDWORD
    PHALF_PTR typedef ptr SDWORD
    if  not Defined(__midl)
      HandleToULong proto WIN_STD_CALL_CONV :ptr
      HandleToLong proto WIN_STD_CALL_CONV :ptr
      ULongToHandle proto WIN_STD_CALL_CONV :DWORD
      LongToHandle proto WIN_STD_CALL_CONV :SDWORD
      PtrToUlong proto WIN_STD_CALL_CONV :ptr
      PtrToUint proto WIN_STD_CALL_CONV :ptr
      PtrToUshort proto WIN_STD_CALL_CONV :ptr
      PtrToLong proto WIN_STD_CALL_CONV :ptr
      PtrToInt proto WIN_STD_CALL_CONV :ptr
      PtrToShort proto WIN_STD_CALL_CONV :ptr
      IntToPtr proto WIN_STD_CALL_CONV :SDWORD
      UIntToPtr proto WIN_STD_CALL_CONV :DWORD
      LongToPtr proto WIN_STD_CALL_CONV :SDWORD
      ULongToPtr proto WIN_STD_CALL_CONV :DWORD
      PtrToPtr64 macro p
        exitm <((void * POINTER_64) p)>
      endm
      Ptr64ToPtr macro p
        exitm <(p)>
      endm
      HandleToHandle64 macro h
        exitm <(PtrToPtr64(h))>
      endm
      Handle64ToHandle macro h
        exitm <(Ptr64ToPtr(h))>
      endm
      Ptr32ToPtr proto WIN_STD_CALL_CONV :ptr
      Handle32ToHandle proto WIN_STD_CALL_CONV :ptr
      PtrToPtr32 proto WIN_STD_CALL_CONV :ptr
      HandleToHandle32 macro h
        exitm <(PtrToPtr32(h))>
      endm
    endif
  else
    ADDRESS_TAG_BIT equ 80000000h
    UHALF_PTR typedef WORD
    PUHALF_PTR typedef ptr WORD
    HALF_PTR typedef SWORD
    PHALF_PTR typedef ptr SWORD
    SHANDLE_PTR typedef _W64
    HANDLE_PTR typedef _W64
    HandleToULong macro h
      exitm <((h))>
    endm
    HandleToLong macro h
      exitm <((h))>
    endm
    ULongToHandle macro ul
      exitm <((ul))>
    endm
    LongToHandle macro h
      exitm <((h))>
    endm
    PtrToUlong macro p
      exitm <((p))>
    endm
    PtrToLong macro p
      exitm <((p))>
    endm
    PtrToUint macro p
      exitm <((p))>
    endm
    PtrToInt macro p
      exitm <((INT) (p))>
    endm
    PtrToUshort macro p
      exitm <((p))>
    endm
    PtrToShort macro p
      exitm <((p))>
    endm
    IntToPtr macro i
      exitm <((i))>
    endm
    UIntToPtr macro ui
      exitm <((ui))>
    endm
    LongToPtr macro l
      exitm <((l))>
    endm
    ULongToPtr macro ul
      exitm <((ul))>
    endm
    if  not Defined(__midl)
      PtrToPtr64 proto WIN_STD_CALL_CONV :ptr
      Ptr64ToPtr proto WIN_STD_CALL_CONV :ptr
      HandleToHandle64 proto WIN_STD_CALL_CONV :ptr
      Handle64ToHandle proto WIN_STD_CALL_CONV :HANDLE64
    endif
    Ptr32ToPtr macro p
      exitm <(p)>
    endm
    Handle32ToHandle macro h
      exitm <(Ptr32ToPtr(h))>
    endm
    PtrToPtr32 macro p
      exitm <((void * POINTER_32) p)>
    endm
    HandleToHandle32 macro h
      exitm <(PtrToPtr32(h))>
    endm
  endif
  HandleToUlong macro h
    exitm <HandleToULong(h)>
  endm
  UlongToHandle macro ul
    exitm <ULongToHandle(ul)>
  endm
  UlongToPtr macro ul
    exitm <ULongToPtr(ul)>
  endm
  UintToPtr macro ui
    exitm <UIntToPtr(ui)>
  endm
  MAXUINT_PTR equ (not (0))
  MAXINT_PTR equ ((MAXUINT_PTR shr 1))
  MININT_PTR equ <(not MAXINT_PTR)>
  MAXULONG_PTR equ (not (0))
  MAXLONG_PTR equ ((MAXULONG_PTR shr 1))
  MINLONG_PTR equ <(not MAXLONG_PTR)>
  MAXUHALF_PTR equ (not 0)
  MAXHALF_PTR equ ((MAXUHALF_PTR shr 1))
  MINHALF_PTR equ <(not MAXHALF_PTR)>
  SIZE_T typedef ULONG_PTR
  PSIZE_T typedef ptr ULONG_PTR
  SSIZE_T typedef LONG_PTR
  PSSIZE_T typedef ptr LONG_PTR
  if _WIN32_WINNT ge 0600h or (Defined(__cplusplus) and Defined(WINDOWS_ENABLE_CPLUSPLUS))
    MAXUINT8 equ (not (0))
    MAXINT8 equ ((MAXUINT8 shr 1))
    MININT8 equ <(not MAXINT8)>
    MAXUINT16 equ ((UINT16) not ((UINT16) 0))
    MAXINT16 equ ((INT16) (MAXUINT16 shr 1))
    MININT16 equ <((INT16) not MAXINT16)>
    MAXUINT32 equ (not (0))
    MAXINT32 equ ((MAXUINT32 shr 1))
    MININT32 equ <(not MAXINT32)>
    MAXUINT64 equ (not (0))
    MAXINT64 equ ((MAXUINT64 shr 1))
    MININT64 equ <(not MAXINT64)>
    MAXULONG32 equ (not (0))
    MAXLONG32 equ ((MAXULONG32 shr 1))
    MINLONG32 equ <(not MAXLONG32)>
    MAXULONG64 equ (not (0))
    MAXLONG64 equ ((MAXULONG64 shr 1))
    MINLONG64 equ <(not MAXLONG64)>
    MAXULONGLONG equ (not (0))
    MINLONGLONG equ <(not MAXLONGLONG)>
    MAXSIZE_T equ (not (0))
    MAXSSIZE_T equ ((SSIZE_T) (MAXSIZE_T shr 1))
    MINSSIZE_T equ <((SSIZE_T) not MAXSSIZE_T)>
    MAXUINT equ (not (0))
    MAXINT equ ((INT) (MAXUINT shr 1))
    MININT equ <((INT) not MAXINT)>
    MAXDWORD32 equ (not (0))
    MAXDWORD64 equ (not (0))
  endif
  DWORD_PTR typedef ULONG_PTR
  PDWORD_PTR typedef ptr ULONG_PTR
  LONG64 typedef SQWORD
  PLONG64 typedef ptr SQWORD
  ULONG64 typedef QWORD
  PULONG64 typedef ptr QWORD
  DWORD64 typedef QWORD
  PDWORD64 typedef ptr QWORD
  KAFFINITY typedef ULONG_PTR
  PKAFFINITY typedef ptr KAFFINITY
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
endif
