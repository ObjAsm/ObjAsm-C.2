;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\intsafe.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 21/02/2024 18:13:36

ifndef _INTSAFE_H_INCLUDED_
  _INTSAFE_H_INCLUDED_ equ <>
  include winapifamily.inc
  if (_MSC_VER gt 1000)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    include specstrings.inc
    if _MSC_VER ge 1200
    endif
    if  not Defined(_W64)
      if  not Defined(__midl) and (Defined(_X86_) or Defined(_M_IX86) or Defined(_ARM_) or Defined(_M_ARM)) and (_MSC_VER ge 1300)
        _W64 equ <__w64>
      else
        _W64 equ <>
      endif
    endif
    CHAR typedef SBYTE
    INT8 typedef SBYTE
    UCHAR typedef BYTE
    UINT8 typedef BYTE
    SHORT_ typedef SWORD
    INT16 typedef SWORD
    USHORT typedef WORD
    UINT16 typedef WORD
    INT_ typedef SDWORD
    INT32 typedef SDWORD
    UINT typedef DWORD
    UINT32 typedef DWORD
    LONG typedef SDWORD
    ULONG typedef DWORD
    LONGLONG typedef SQWORD
    LONG64 typedef SQWORD
    INT64 typedef SQWORD
    ULONGLONG typedef QWORD
    DWORDLONG typedef QWORD
    ULONG64 typedef QWORD
    DWORD64 typedef QWORD
    UINT64 typedef QWORD
    if (__midl gt 501)
      INT_PTR typedef __int3264
      UINT_PTR typedef DWORD
      LONG_PTR typedef __int3264
      ULONG_PTR typedef DWORD
    else
      ifdef _WIN64
        INT_PTR typedef SQWORD
        UINT_PTR typedef QWORD
        LONG_PTR typedef SQWORD
        ULONG_PTR typedef QWORD
      else
        INT_PTR typedef _W64
        UINT_PTR typedef _W64
        LONG_PTR typedef _W64
        ULONG_PTR typedef _W64
      endif
    endif
    ifdef _WIN64
      ptrdiff_t typedef SQWORD
      size_t typedef QWORD
    else
      ptrdiff_t typedef _W64
      size_t typedef _W64
    endif
    DWORD_PTR typedef ULONG_PTR
    SSIZE_T typedef LONG_PTR
    SIZE_T typedef ULONG_PTR
    if  not Defined(_M_CEE) and ((Defined(_AMD64_) and  not Defined(_ARM64EC_)) or (Defined(_IA64_) and (_MSC_VER ge 1400)))
      _USE_INTRINSIC_MULTIPLY128 equ <>
    endif
    if Defined(_USE_INTRINSIC_MULTIPLY128)
      ifdef __cplusplus
        ;[...]
      endif
      if  not Defined(_ARM64EC_)
        UnsignedMultiply128 equ <_umul128>
      else
        _umul128 equ <Multiply128>
      endif
      UnsignedMultiply128 proto WIN_STD_CALL_CONV :ULONGLONG, :ULONGLONG, :ptr ULONGLONG
      if  not Defined(_ARM64EC_)
      endif
      ifdef __cplusplus
        ;[...]
      endif
    endif
    HRESULT typedef SDWORD
    SUCCEEDED macro hr
      exitm <(((hr)) >= 0)>
    endm
    FAILED macro hr
      exitm <(((hr)) < 0)>
    endm
    S_OK equ (0)
    INTSAFE_E_ARITHMETIC_OVERFLOW equ (80070216h)
    ifndef SORTPP_PASS
      C_ASSERT macro e
        exitm <typedef char __C_ASSERT__ [ (e) ?1 : - 1 ]>
      endm
    else
      ;[...]
    endif
    ifndef UInt32x32To64
      if Defined(MIDL_PASS) or Defined(RC_INVOKED) or Defined(_M_CEE_PURE) or Defined(_68K_) or Defined(_MPPC_) or Defined(_M_IA64) or Defined(_M_AMD64) or Defined(_M_ARM) or Defined(_M_ARM64) or Defined(_M_HYBRID_X86_ARM64)
        UInt32x32To64 macro a, b
          exitm <((((a))) * (((b))))>
        endm
      elseif Defined(_M_IX86)
        UInt32x32To64 macro a, b
          exitm <(((((a))) * ((b))))>
        endm
      else
        .err <Must define a target architecture.>
      endif
    endif
    INT8_MIN equ (- 127 - 1)
    SHORT_MIN equ (- 32768)
    INT16_MIN equ (- 32767 - 1)
    ifndef INT_MIN
      INT_MIN equ (- 2147483647 - 1)
    endif
    INT32_MIN equ (- 2147483647 - 1)
    ifndef LONG_MIN
      LONG_MIN equ (- 2147483647 - 1)
    endif
    LONGLONG_MIN equ (- 9223372036854775807 - 1)
    LONG64_MIN equ (- 9223372036854775807 - 1)
    INT64_MIN equ (- 9223372036854775807 - 1)
    INT128_MIN equ (- 170141183460469231731687303715884105727 - 1)
    ifdef _WIN64
      INT_PTR_MIN equ (- 9223372036854775807 - 1)
      LONG_PTR_MIN equ (- 9223372036854775807 - 1)
      PTRDIFF_T_MIN equ (- 9223372036854775807 - 1)
      SSIZE_T_MIN equ (- 9223372036854775807 - 1)
    else
      INT_PTR_MIN equ (- 2147483647 - 1)
      LONG_PTR_MIN equ (- 2147483647 - 1)
      PTRDIFF_T_MIN equ (- 2147483647 - 1)
      SSIZE_T_MIN equ (- 2147483647 - 1)
    endif
    INT8_MAX equ 127
    UINT8_MAX equ 0ffh
    BYTE_MAX equ 0ffh
    SHORT_MAX equ 32767
    INT16_MAX equ 32767
    USHORT_MAX equ 0ffffh
    UINT16_MAX equ 0ffffh
    WORD_MAX equ 0ffffh
    ifndef INT_MAX
      INT_MAX equ 2147483647
    endif
    INT32_MAX equ 2147483647
    ifndef UINT_MAX
      UINT_MAX equ 0ffffffffh
    endif
    UINT32_MAX equ 0ffffffffh
    ifndef LONG_MAX
      LONG_MAX equ 2147483647
    endif
    ifndef ULONG_MAX
      ULONG_MAX equ 0ffffffffh
    endif
    DWORD_MAX equ 0ffffffffh
    LONGLONG_MAX equ 9223372036854775807
    LONG64_MAX equ 9223372036854775807
    INT64_MAX equ 9223372036854775807
    ULONGLONG_MAX equ 0ffffffffffffffffh
    DWORDLONG_MAX equ 0ffffffffffffffffh
    ULONG64_MAX equ 0ffffffffffffffffh
    DWORD64_MAX equ 0ffffffffffffffffh
    UINT64_MAX equ 0ffffffffffffffffh
    INT128_MAX equ 170141183460469231731687303715884105727
    UINT128_MAX equ 0ffffffffffffffffffffffffffffffffh
    ifdef _WIN64
      INT_PTR_MAX equ 9223372036854775807
      UINT_PTR_MAX equ 0ffffffffffffffffh
      LONG_PTR_MAX equ 9223372036854775807
      ULONG_PTR_MAX equ 0ffffffffffffffffh
      DWORD_PTR_MAX equ 0ffffffffffffffffh
      PTRDIFF_T_MAX equ 9223372036854775807
      SIZE_T_MAX equ 0ffffffffffffffffh
      SSIZE_T_MAX equ 9223372036854775807
      _SIZE_T_MAX equ 0ffffffffffffffffh
    else
      INT_PTR_MAX equ 2147483647
      UINT_PTR_MAX equ 0ffffffffh
      LONG_PTR_MAX equ 2147483647
      ULONG_PTR_MAX equ 0ffffffffh
      DWORD_PTR_MAX equ 0ffffffffh
      PTRDIFF_T_MAX equ 2147483647
      SIZE_T_MAX equ 0ffffffffh
      SSIZE_T_MAX equ 2147483647
      _SIZE_T_MAX equ 0ffffffffh
    endif
    INT8_ERROR equ (- 1i8)
    UINT8_ERROR equ 0ffh
    BYTE_ERROR equ 0ffh
    SHORT_ERROR equ (- 1)
    INT16_ERROR equ (- 1)
    USHORT_ERROR equ 0ffffh
    UINT16_ERROR equ 0ffffh
    WORD_ERROR equ 0ffffh
    INT_ERROR equ (- 1)
    INT32_ERROR equ (- 1)
    UINT_ERROR equ 0ffffffffh
    UINT32_ERROR equ 0ffffffffh
    LONG_ERROR equ (- 1)
    ULONG_ERROR equ 0ffffffffh
    DWORD_ERROR equ 0ffffffffh
    LONGLONG_ERROR equ (- 1)
    LONG64_ERROR equ (- 1)
    INT64_ERROR equ (- 1)
    ULONGLONG_ERROR equ 0ffffffffffffffffh
    DWORDLONG_ERROR equ 0ffffffffffffffffh
    ULONG64_ERROR equ 0ffffffffffffffffh
    UINT64_ERROR equ 0ffffffffffffffffh
    ifdef _WIN64
      INT_PTR_ERROR equ (- 1)
      UINT_PTR_ERROR equ 0ffffffffffffffffh
      LONG_PTR_ERROR equ (- 1)
      ULONG_PTR_ERROR equ 0ffffffffffffffffh
      DWORD_PTR_ERROR equ 0ffffffffffffffffh
      PTRDIFF_T_ERROR equ (- 1)
      SIZE_T_ERROR equ 0ffffffffffffffffh
      SSIZE_T_ERROR equ (- 1)
      _SIZE_T_ERROR equ 0ffffffffffffffffh
    else
      INT_PTR_ERROR equ (- 1)
      UINT_PTR_ERROR equ 0ffffffffh
      LONG_PTR_ERROR equ (- 1)
      ULONG_PTR_ERROR equ 0ffffffffh
      DWORD_PTR_ERROR equ 0ffffffffh
      PTRDIFF_T_ERROR equ (- 1)
      SIZE_T_ERROR equ 0ffffffffh
      SSIZE_T_ERROR equ (- 1)
      _SIZE_T_ERROR equ 0ffffffffh
    endif
    Int8ToUChar proto WIN_STD_CALL_CONV :INT8, :ptr UCHAR
    Int8ToUInt8 proto WIN_STD_CALL_CONV :INT8, :ptr UINT8
    Int8ToByte equ <Int8ToUInt8>
    Int8ToUShort proto WIN_STD_CALL_CONV :INT8, :ptr USHORT
    Int8ToUInt16 equ <Int8ToUShort>
    Int8ToWord equ <Int8ToUShort>
    Int8ToUInt proto WIN_STD_CALL_CONV :INT8, :ptr UINT
    Int8ToUInt32 equ <Int8ToUInt>
    Int8ToUIntPtr proto WIN_STD_CALL_CONV :INT8, :ptr UINT_PTR
    Int8ToULong proto WIN_STD_CALL_CONV :INT8, :ptr ULONG
    Int8ToULongPtr proto WIN_STD_CALL_CONV :INT8, :ptr ULONG_PTR
    Int8ToDWord equ <Int8ToULong>
    Int8ToDWordPtr equ <Int8ToULongPtr>
    Int8ToULongLong proto WIN_STD_CALL_CONV :INT8, :ptr ULONGLONG
    Int8ToDWordLong equ <Int8ToULongLong>
    Int8ToULong64 equ <Int8ToULongLong>
    Int8ToDWord64 equ <Int8ToULongLong>
    Int8ToUInt64 equ <Int8ToULongLong>
    Int8ToSizeT equ <Int8ToUIntPtr>
    Int8ToSIZET equ <Int8ToULongPtr>
    UInt8ToInt8 proto WIN_STD_CALL_CONV :UINT8, :ptr INT8
    UInt8ToChar proto WIN_STD_CALL_CONV :UINT8, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    ByteToInt8 proto WIN_STD_CALL_CONV :BYTE, :ptr INT8
    ByteToChar proto WIN_STD_CALL_CONV :BYTE, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    ShortToInt8 proto WIN_STD_CALL_CONV :SHORT_, :ptr INT8
    ShortToUChar proto WIN_STD_CALL_CONV :SHORT_, :ptr UCHAR
    ShortToChar proto WIN_STD_CALL_CONV :SHORT_, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    ShortToUInt8 proto WIN_STD_CALL_CONV :SHORT_, :ptr UINT8
    ShortToByte equ <ShortToUInt8>
    ShortToUShort proto WIN_STD_CALL_CONV :SHORT_, :ptr USHORT
    ShortToUInt16 equ <ShortToUShort>
    ShortToWord equ <ShortToUShort>
    ShortToUInt proto WIN_STD_CALL_CONV :SHORT_, :ptr UINT
    ShortToUInt32 equ <ShortToUInt>
    ShortToUIntPtr proto WIN_STD_CALL_CONV :SHORT_, :ptr UINT_PTR
    ShortToULong proto WIN_STD_CALL_CONV :SHORT_, :ptr ULONG
    ShortToULongPtr proto WIN_STD_CALL_CONV :SHORT_, :ptr ULONG_PTR
    ShortToDWord equ <ShortToULong>
    ShortToDWordPtr proto WIN_STD_CALL_CONV :SHORT_, :ptr DWORD_PTR
    ShortToULongLong proto WIN_STD_CALL_CONV :SHORT_, :ptr ULONGLONG
    ShortToDWordLong equ <ShortToULongLong>
    ShortToULong64 equ <ShortToULongLong>
    ShortToDWord64 equ <ShortToULongLong>
    ShortToUInt64 equ <ShortToULongLong>
    ShortToSizeT equ <ShortToUIntPtr>
    ShortToSIZET equ <ShortToULongPtr>
    Int16ToChar equ <ShortToChar>
    Int16ToInt8 equ <ShortToInt8>
    Int16ToUChar equ <ShortToUChar>
    Int16ToUInt8 equ <ShortToUInt8>
    Int16ToByte equ <ShortToUInt8>
    Int16ToUShort equ <ShortToUShort>
    Int16ToUInt16 equ <ShortToUShort>
    Int16ToWord equ <ShortToUShort>
    Int16ToUInt equ <ShortToUInt>
    Int16ToUInt32 equ <ShortToUInt>
    Int16ToUIntPtr equ <ShortToUIntPtr>
    Int16ToULong equ <ShortToULong>
    Int16ToULongPtr equ <ShortToULongPtr>
    Int16ToDWord equ <ShortToULong>
    Int16ToDWordPtr equ <ShortToULongPtr>
    Int16ToULongLong equ <ShortToULongLong>
    Int16ToDWordLong equ <ShortToULongLong>
    Int16ToULong64 equ <ShortToULongLong>
    Int16ToDWord64 equ <ShortToULongLong>
    Int16ToUInt64 equ <ShortToULongLong>
    Int16ToSizeT equ <ShortToUIntPtr>
    Int16ToSIZET equ <ShortToULongPtr>
    UShortToInt8 proto WIN_STD_CALL_CONV :USHORT, :ptr INT8
    UShortToUChar proto WIN_STD_CALL_CONV :USHORT, :ptr UCHAR
    UShortToChar proto WIN_STD_CALL_CONV :USHORT, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    UShortToUInt8 proto WIN_STD_CALL_CONV :USHORT, :ptr UINT8
    UShortToByte equ <UShortToUInt8>
    UShortToShort proto WIN_STD_CALL_CONV :USHORT, :ptr SHORT_
    UShortToInt16 equ <UShortToShort>
    UInt16ToChar equ <UShortToChar>
    UInt16ToInt8 equ <UShortToInt8>
    UInt16ToUChar equ <UShortToUChar>
    UInt16ToUInt8 equ <UShortToUInt8>
    UInt16ToByte equ <UShortToUInt8>
    UInt16ToShort equ <UShortToShort>
    UInt16ToInt16 equ <UShortToShort>
    WordToInt8 equ <UShortToInt8>
    WordToChar equ <UShortToChar>
    WordToUChar equ <UShortToUChar>
    WordToUInt8 equ <UShortToUInt8>
    WordToByte equ <UShortToUInt8>
    WordToShort equ <UShortToShort>
    WordToInt16 equ <UShortToShort>
    IntToInt8 proto WIN_STD_CALL_CONV :INT_, :ptr INT8
    IntToUChar proto WIN_STD_CALL_CONV :INT_, :ptr UCHAR
    IntToChar proto WIN_STD_CALL_CONV :INT_, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    IntToByte equ <IntToUInt8>
    IntToUInt8 proto WIN_STD_CALL_CONV :INT_, :ptr UINT8
    IntToShort proto WIN_STD_CALL_CONV :INT_, :ptr SHORT_
    IntToInt16 equ <IntToShort>
    IntToUShort proto WIN_STD_CALL_CONV :INT_, :ptr USHORT
    IntToUInt16 equ <IntToUShort>
    IntToWord equ <IntToUShort>
    IntToUInt proto WIN_STD_CALL_CONV :INT_, :ptr UINT
    ifdef _WIN64
      IntToUIntPtr equ <IntToULongLong>
    else
      IntToUIntPtr equ <IntToUInt>
    endif
    IntToULong proto WIN_STD_CALL_CONV :INT_, :ptr ULONG
    ifdef _WIN64
      IntToULongPtr equ <IntToULongLong>
    else
      IntToULongPtr equ <IntToULong>
    endif
    IntToDWord equ <IntToULong>
    IntToDWordPtr equ <IntToULongPtr>
    IntToULongLong proto WIN_STD_CALL_CONV :INT_, :ptr ULONGLONG
    IntToDWordLong equ <IntToULongLong>
    IntToULong64 equ <IntToULongLong>
    IntToDWord64 equ <IntToULongLong>
    IntToUInt64 equ <IntToULongLong>
    IntToSizeT equ <IntToUIntPtr>
    IntToSIZET equ <IntToULongPtr>
    Int32ToChar equ <IntToChar>
    Int32ToInt8 equ <IntToInt8>
    Int32ToUChar equ <IntToUChar>
    Int32ToByte equ <IntToUInt8>
    Int32ToUInt8 equ <IntToUInt8>
    Int32ToShort equ <IntToShort>
    Int32ToInt16 equ <IntToShort>
    Int32ToUShort equ <IntToUShort>
    Int32ToUInt16 equ <IntToUShort>
    Int32ToWord equ <IntToUShort>
    Int32ToUInt equ <IntToUInt>
    Int32ToUInt32 equ <IntToUInt>
    Int32ToUIntPtr equ <IntToUIntPtr>
    Int32ToULong equ <IntToULong>
    Int32ToULongPtr equ <IntToULongPtr>
    Int32ToDWord equ <IntToULong>
    Int32ToDWordPtr equ <IntToULongPtr>
    Int32ToULongLong equ <IntToULongLong>
    Int32ToDWordLong equ <IntToULongLong>
    Int32ToULong64 equ <IntToULongLong>
    Int32ToDWord64 equ <IntToULongLong>
    Int32ToUInt64 equ <IntToULongLong>
    Int32ToSizeT equ <IntToUIntPtr>
    Int32ToSIZET equ <IntToULongPtr>
    IntPtrToInt8 proto WIN_STD_CALL_CONV :INT_PTR, :ptr INT8
    IntPtrToUChar proto WIN_STD_CALL_CONV :INT_PTR, :ptr UCHAR
    IntPtrToChar proto WIN_STD_CALL_CONV :INT_PTR, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    IntPtrToUInt8 proto WIN_STD_CALL_CONV :INT_PTR, :ptr UINT8
    IntPtrToByte equ <IntPtrToUInt8>
    IntPtrToShort proto WIN_STD_CALL_CONV :INT_PTR, :ptr SHORT_
    IntPtrToInt16 equ <IntPtrToShort>
    IntPtrToUShort proto WIN_STD_CALL_CONV :INT_PTR, :ptr USHORT
    IntPtrToUInt16 equ <IntPtrToUShort>
    IntPtrToWord equ <IntPtrToUShort>
    ifdef _WIN64
      IntPtrToInt equ <LongLongToInt>
    else
      IntPtrToInt proto WIN_STD_CALL_CONV :INT_PTR, :ptr INT_
    endif
    IntPtrToInt32 equ <IntPtrToInt>
    ifdef _WIN64
      IntPtrToUInt equ <LongLongToUInt>
    else
      IntPtrToUInt proto WIN_STD_CALL_CONV :INT_PTR, :ptr UINT
    endif
    IntPtrToUInt32 equ <IntPtrToUInt>
    ifdef _WIN64
      IntPtrToUIntPtr equ <LongLongToULongLong>
    else
      IntPtrToUIntPtr proto WIN_STD_CALL_CONV :INT_PTR, :ptr UINT_PTR
    endif
    ifdef _WIN64
      IntPtrToLong equ <LongLongToLong>
    else
      IntPtrToLong proto WIN_STD_CALL_CONV :INT_PTR, :ptr LONG
    endif
    IntPtrToLongPtr proto WIN_STD_CALL_CONV :INT_PTR, :ptr LONG_PTR
    ifdef _WIN64
      IntPtrToULong equ <LongLongToULong>
    else
      IntPtrToULong proto WIN_STD_CALL_CONV :INT_PTR, :ptr ULONG
    endif
    ifdef _WIN64
      IntPtrToULongPtr equ <LongLongToULongLong>
    else
      IntPtrToULongPtr proto WIN_STD_CALL_CONV :INT_PTR, :ptr ULONG_PTR
    endif
    IntPtrToDWord equ <IntPtrToULong>
    IntPtrToDWordPtr equ <IntPtrToULongPtr>
    ifdef _WIN64
      IntPtrToULongLong equ <LongLongToULongLong>
    else
      IntPtrToULongLong proto WIN_STD_CALL_CONV :INT_PTR, :ptr ULONGLONG
    endif
    IntPtrToDWordLong equ <IntPtrToULongLong>
    IntPtrToULong64 equ <IntPtrToULongLong>
    IntPtrToDWord64 equ <IntPtrToULongLong>
    IntPtrToUInt64 equ <IntPtrToULongLong>
    IntPtrToSizeT equ <IntPtrToUIntPtr>
    IntPtrToSIZET equ <IntPtrToULongPtr>
    UIntToInt8 proto WIN_STD_CALL_CONV :UINT, :ptr INT8
    UIntToUChar proto WIN_STD_CALL_CONV :UINT, :ptr UCHAR
    UIntToChar proto WIN_STD_CALL_CONV :UINT, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    UIntToUInt8 proto WIN_STD_CALL_CONV :UINT, :ptr UINT8
    UIntToByte equ <UIntToUInt8>
    UIntToShort proto WIN_STD_CALL_CONV :UINT, :ptr SHORT_
    UIntToInt16 equ <UIntToShort>
    UIntToUShort proto WIN_STD_CALL_CONV :UINT, :ptr USHORT
    UIntToUInt16 equ <UIntToUShort>
    UIntToWord equ <UIntToUShort>
    UIntToInt proto WIN_STD_CALL_CONV :UINT, :ptr INT_
    UIntToInt32 equ <UIntToInt>
    ifdef _WIN64
      UIntToIntPtr proto WIN_STD_CALL_CONV :UINT, :ptr INT_PTR
    else
      UIntToIntPtr equ <UIntToInt>
    endif
    UIntToLong proto WIN_STD_CALL_CONV :UINT, :ptr LONG
    ifdef _WIN64
      UIntToLongPtr proto WIN_STD_CALL_CONV :UINT, :ptr LONG_PTR
    else
      UIntToLongPtr equ <UIntToLong>
    endif
    UIntToPtrdiffT equ <UIntToIntPtr>
    UIntToSSIZET equ <UIntToLongPtr>
    UInt32ToChar equ <UIntToChar>
    UInt32ToInt8 equ <UIntToInt8>
    UInt32ToUChar equ <UIntToUChar>
    UInt32ToUInt8 equ <UIntToUInt8>
    UInt32ToByte equ <UInt32ToUInt8>
    UInt32ToShort equ <UIntToShort>
    UInt32ToInt16 equ <UIntToShort>
    UInt32ToUShort equ <UIntToUShort>
    UInt32ToUInt16 equ <UIntToUShort>
    UInt32ToWord equ <UIntToUShort>
    UInt32ToInt equ <UIntToInt>
    UInt32ToIntPtr equ <UIntToIntPtr>
    UInt32ToInt32 equ <UIntToInt>
    UInt32ToLong equ <UIntToLong>
    UInt32ToLongPtr equ <UIntToLongPtr>
    UInt32ToPtrdiffT equ <UIntToPtrdiffT>
    UInt32ToSSIZET equ <UIntToSSIZET>
    UIntPtrToInt8 proto WIN_STD_CALL_CONV :UINT_PTR, :ptr INT8
    UIntPtrToUChar proto WIN_STD_CALL_CONV :UINT_PTR, :ptr UCHAR
    UIntPtrToChar proto WIN_STD_CALL_CONV :UINT_PTR, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    UIntPtrToUInt8 proto WIN_STD_CALL_CONV :UINT_PTR, :ptr UINT8
    UIntPtrToByte equ <UIntPtrToUInt8>
    UIntPtrToShort proto WIN_STD_CALL_CONV :UINT_PTR, :ptr SHORT_
    UIntPtrToInt16 proto WIN_STD_CALL_CONV :UINT_PTR, :ptr INT16
    UIntPtrToUShort proto WIN_STD_CALL_CONV :UINT_PTR, :ptr USHORT
    UIntPtrToUInt16 proto WIN_STD_CALL_CONV :UINT_PTR, :ptr UINT16
    UIntPtrToWord equ <UIntPtrToUShort>
    UIntPtrToInt proto WIN_STD_CALL_CONV :UINT_PTR, :ptr INT_
    UIntPtrToInt32 equ <UIntPtrToInt>
    UIntPtrToIntPtr proto WIN_STD_CALL_CONV :UINT_PTR, :ptr INT_PTR
    ifdef _WIN64
      UIntPtrToUInt equ <ULongLongToUInt>
    else
      UIntPtrToUInt proto WIN_STD_CALL_CONV :UINT_PTR, :ptr UINT
    endif
    UIntPtrToUInt32 equ <UIntPtrToUInt>
    UIntPtrToLong proto WIN_STD_CALL_CONV :UINT_PTR, :ptr LONG
    UIntPtrToLongPtr proto WIN_STD_CALL_CONV :UINT_PTR, :ptr LONG_PTR
    ifdef _WIN64
      UIntPtrToULong equ <ULongLongToULong>
    else
      UIntPtrToULong proto WIN_STD_CALL_CONV :UINT_PTR, :ptr ULONG
    endif
    UIntPtrToDWord equ <UIntPtrToULong>
    ifdef _WIN64
      UIntPtrToLongLong equ <ULongLongToLongLong>
    else
      UIntPtrToLongLong proto WIN_STD_CALL_CONV :UINT_PTR, :ptr LONGLONG
    endif
    UIntPtrToLong64 equ <UIntPtrToLongLong>
    UIntPtrToInt64 equ <UIntPtrToLongLong>
    UIntPtrToPtrdiffT equ <UIntPtrToIntPtr>
    UIntPtrToSSIZET equ <UIntPtrToLongPtr>
    LongToInt8 proto WIN_STD_CALL_CONV :LONG, :ptr INT8
    LongToUChar proto WIN_STD_CALL_CONV :LONG, :ptr UCHAR
    LongToChar proto WIN_STD_CALL_CONV :LONG, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    LongToUInt8 proto WIN_STD_CALL_CONV :LONG, :ptr UINT8
    LongToByte equ <LongToUInt8>
    LongToShort proto WIN_STD_CALL_CONV :LONG, :ptr SHORT_
    LongToInt16 equ <LongToShort>
    LongToUShort proto WIN_STD_CALL_CONV :LONG, :ptr USHORT
    LongToUInt16 equ <LongToUShort>
    LongToWord equ <LongToUShort>
    LongToInt proto WIN_STD_CALL_CONV :LONG, :ptr INT_
    LongToInt32 equ <LongToInt>
    ifdef _WIN64
      LongToIntPtr proto WIN_STD_CALL_CONV :LONG, :ptr INT_PTR
    else
      LongToIntPtr equ <LongToInt>
    endif
    LongToUInt proto WIN_STD_CALL_CONV :LONG, :ptr UINT
    LongToUInt32 equ <LongToUInt>
    ifdef _WIN64
      LongToUIntPtr proto WIN_STD_CALL_CONV :LONG, :ptr UINT_PTR
    else
      LongToUIntPtr equ <LongToUInt>
    endif
    LongToULong proto WIN_STD_CALL_CONV :LONG, :ptr ULONG
    ifdef _WIN64
      LongToULongPtr proto WIN_STD_CALL_CONV :LONG, :ptr ULONG_PTR
    else
      LongToULongPtr equ <LongToULong>
    endif
    LongToDWord equ <LongToULong>
    LongToDWordPtr equ <LongToULongPtr>
    LongToULongLong proto WIN_STD_CALL_CONV :LONG, :ptr ULONGLONG
    LongToDWordLong equ <LongToULongLong>
    LongToULong64 equ <LongToULongLong>
    LongToDWord64 equ <LongToULongLong>
    LongToUInt64 equ <LongToULongLong>
    LongToPtrdiffT equ <LongToIntPtr>
    LongToSizeT equ <LongToUIntPtr>
    LongToSIZET equ <LongToULongPtr>
    LongPtrToInt8 proto WIN_STD_CALL_CONV :LONG_PTR, :ptr INT8
    LongPtrToUChar proto WIN_STD_CALL_CONV :LONG_PTR, :ptr UCHAR
    LongPtrToChar proto WIN_STD_CALL_CONV :LONG_PTR, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    LongPtrToUInt8 proto WIN_STD_CALL_CONV :LONG_PTR, :ptr UINT8
    LongPtrToByte equ <LongPtrToUInt8>
    LongPtrToShort proto WIN_STD_CALL_CONV :LONG_PTR, :ptr SHORT_
    LongPtrToInt16 equ <LongPtrToShort>
    LongPtrToUShort proto WIN_STD_CALL_CONV :LONG_PTR, :ptr USHORT
    LongPtrToUInt16 equ <LongPtrToUShort>
    LongPtrToWord equ <LongPtrToUShort>
    ifdef _WIN64
      LongPtrToInt equ <LongLongToInt>
    else
      LongPtrToInt proto WIN_STD_CALL_CONV :LONG_PTR, :ptr INT_
    endif
    LongPtrToInt32 equ <LongPtrToInt>
    LongPtrToIntPtr proto WIN_STD_CALL_CONV :LONG_PTR, :ptr INT_PTR
    ifdef _WIN64
      LongPtrToUInt equ <LongLongToUInt>
    else
      LongPtrToUInt proto WIN_STD_CALL_CONV :LONG_PTR, :ptr UINT
    endif
    LongPtrToUInt32 equ <LongPtrToUInt>
    LongPtrToUIntPtr proto WIN_STD_CALL_CONV :LONG_PTR, :ptr UINT_PTR
    ifdef _WIN64
      LongPtrToLong equ <LongLongToLong>
    else
      LongPtrToLong proto WIN_STD_CALL_CONV :LONG_PTR, :ptr LONG
    endif
    ifdef _WIN64
      LongPtrToULong equ <LongLongToULong>
    else
      LongPtrToULong proto WIN_STD_CALL_CONV :LONG_PTR, :ptr ULONG
    endif
    LongPtrToULongPtr proto WIN_STD_CALL_CONV :LONG_PTR, :ptr ULONG_PTR
    LongPtrToDWord equ <LongPtrToULong>
    LongPtrToDWordPtr equ <LongPtrToULongPtr>
    LongPtrToULongLong proto WIN_STD_CALL_CONV :LONG_PTR, :ptr ULONGLONG
    LongPtrToDWordLong equ <LongPtrToULongLong>
    LongPtrToULong64 equ <LongPtrToULongLong>
    LongPtrToDWord64 equ <LongPtrToULongLong>
    LongPtrToUInt64 equ <LongPtrToULongLong>
    LongPtrToSizeT equ <LongPtrToUIntPtr>
    LongPtrToSIZET equ <LongPtrToULongPtr>
    ULongToInt8 proto WIN_STD_CALL_CONV :ULONG, :ptr INT8
    ULongToUChar proto WIN_STD_CALL_CONV :ULONG, :ptr UCHAR
    ULongToChar proto WIN_STD_CALL_CONV :ULONG, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    ULongToUInt8 proto WIN_STD_CALL_CONV :ULONG, :ptr UINT8
    ULongToByte equ <ULongToUInt8>
    ULongToShort proto WIN_STD_CALL_CONV :ULONG, :ptr SHORT_
    ULongToInt16 equ <ULongToShort>
    ULongToUShort proto WIN_STD_CALL_CONV :ULONG, :ptr USHORT
    ULongToUInt16 equ <ULongToUShort>
    ULongToWord equ <ULongToUShort>
    ULongToInt proto WIN_STD_CALL_CONV :ULONG, :ptr INT_
    ULongToInt32 equ <ULongToInt>
    ifdef _WIN64
      ULongToIntPtr proto WIN_STD_CALL_CONV :ULONG, :ptr INT_PTR
    else
      ULongToIntPtr equ <ULongToInt>
    endif
    ULongToUInt proto WIN_STD_CALL_CONV :ULONG, :ptr UINT
    ULongToUInt32 equ <ULongToUInt>
    ifdef _WIN64
      ULongToUIntPtr proto WIN_STD_CALL_CONV :ULONG, :ptr UINT_PTR
    else
      ULongToUIntPtr equ <ULongToUInt>
    endif
    ULongToLong proto WIN_STD_CALL_CONV :ULONG, :ptr LONG
    ifdef _WIN64
      ULongToLongPtr proto WIN_STD_CALL_CONV :ULONG, :ptr LONG_PTR
    else
      ULongToLongPtr equ <ULongToLong>
    endif
    ULongToPtrdiffT equ <ULongToIntPtr>
    ULongToSSIZET equ <ULongToLongPtr>
    ULongPtrToInt8 proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr INT8
    ULongPtrToUChar proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr UCHAR
    ULongPtrToChar proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    ULongPtrToUInt8 proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr UINT8
    ULongPtrToByte equ <ULongPtrToUInt8>
    ULongPtrToShort proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr SHORT_
    ULongPtrToInt16 equ <ULongPtrToShort>
    ULongPtrToUShort proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr USHORT
    ULongPtrToUInt16 equ <ULongPtrToUShort>
    ULongPtrToWord equ <ULongPtrToUShort>
    ULongPtrToInt proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr INT_
    ULongPtrToInt32 equ <ULongPtrToInt>
    ULongPtrToIntPtr proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr INT_PTR
    ifdef _WIN64
      ULongPtrToUInt equ <ULongLongToUInt>
    else
      ULongPtrToUInt proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr UINT
    endif
    ULongPtrToUInt32 equ <ULongPtrToUInt>
    ULongPtrToUIntPtr proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr UINT_PTR
    ULongPtrToLong proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr LONG
    ULongPtrToLongPtr proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr LONG_PTR
    ifdef _WIN64
      ULongPtrToULong equ <ULongLongToULong>
    else
      ULongPtrToULong proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr ULONG
    endif
    ULongPtrToDWord equ <ULongPtrToULong>
    ifdef _WIN64
      ULongPtrToLongLong equ <ULongLongToLongLong>
    else
      ULongPtrToLongLong proto WIN_STD_CALL_CONV :ULONG_PTR, :ptr LONGLONG
    endif
    ULongPtrToLong64 equ <ULongPtrToLongLong>
    ULongPtrToInt64 equ <ULongPtrToLongLong>
    ULongPtrToPtrdiffT equ <ULongPtrToIntPtr>
    ULongPtrToSSIZET equ <ULongPtrToLongPtr>
    DWordToInt8 equ <ULongToInt8>
    DWordToChar equ <ULongToChar>
    DWordToUChar equ <ULongToUChar>
    DWordToUInt8 equ <ULongToUInt8>
    DWordToByte equ <ULongToUInt8>
    DWordToShort equ <ULongToShort>
    DWordToInt16 equ <ULongToShort>
    DWordToUShort equ <ULongToUShort>
    DWordToUInt16 equ <ULongToUShort>
    DWordToWord equ <ULongToUShort>
    DWordToInt equ <ULongToInt>
    DWordToInt32 equ <ULongToInt>
    DWordToIntPtr equ <ULongToIntPtr>
    DWordToUInt equ <ULongToUInt>
    DWordToUInt32 equ <ULongToUInt>
    DWordToUIntPtr equ <ULongToUIntPtr>
    DWordToLong equ <ULongToLong>
    DWordToLongPtr equ <ULongToLongPtr>
    DWordToPtrdiffT equ <ULongToIntPtr>
    DWordToSSIZET equ <ULongToLongPtr>
    DWordPtrToInt8 equ <ULongPtrToInt8>
    DWordPtrToUChar equ <ULongPtrToUChar>
    DWordPtrToChar equ <ULongPtrToChar>
    DWordPtrToUInt8 equ <ULongPtrToUInt8>
    DWordPtrToByte equ <ULongPtrToUInt8>
    DWordPtrToShort equ <ULongPtrToShort>
    DWordPtrToInt16 equ <ULongPtrToShort>
    DWordPtrToUShort equ <ULongPtrToUShort>
    DWordPtrToUInt16 equ <ULongPtrToUShort>
    DWordPtrToWord equ <ULongPtrToUShort>
    DWordPtrToInt equ <ULongPtrToInt>
    DWordPtrToInt32 equ <ULongPtrToInt>
    DWordPtrToIntPtr equ <ULongPtrToIntPtr>
    DWordPtrToUInt equ <ULongPtrToUInt>
    DWordPtrToUInt32 equ <ULongPtrToUInt>
    DWordPtrToUIntPtr equ <ULongPtrToUIntPtr>
    DWordPtrToLong equ <ULongPtrToLong>
    DWordPtrToLongPtr equ <ULongPtrToLongPtr>
    DWordPtrToULong equ <ULongPtrToULong>
    DWordPtrToDWord equ <ULongPtrToULong>
    DWordPtrToLongLong equ <ULongPtrToLongLong>
    DWordPtrToLong64 equ <ULongPtrToLongLong>
    DWordPtrToInt64 equ <ULongPtrToLongLong>
    DWordPtrToPtrdiffT equ <ULongPtrToIntPtr>
    DWordPtrToSSIZET equ <ULongPtrToLongPtr>
    LongLongToInt8 proto WIN_STD_CALL_CONV :LONGLONG, :ptr INT8
    LongLongToUChar proto WIN_STD_CALL_CONV :LONGLONG, :ptr UCHAR
    LongLongToChar proto WIN_STD_CALL_CONV :LONGLONG, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    LongLongToUInt8 proto WIN_STD_CALL_CONV :LONGLONG, :ptr UINT8
    LongLongToByte equ <LongLongToUInt8>
    LongLongToShort proto WIN_STD_CALL_CONV :LONGLONG, :ptr SHORT_
    LongLongToInt16 equ <LongLongToShort>
    LongLongToUShort proto WIN_STD_CALL_CONV :LONGLONG, :ptr USHORT
    LongLongToUInt16 equ <LongLongToUShort>
    LongLongToWord equ <LongLongToUShort>
    LongLongToInt proto WIN_STD_CALL_CONV :LONGLONG, :ptr INT_
    LongLongToInt32 equ <LongLongToInt>
    ifdef _WIN64
      LongLongToIntPtr proto WIN_STD_CALL_CONV :LONGLONG, :ptr INT_PTR
    else
      LongLongToIntPtr equ <LongLongToInt>
    endif
    LongLongToUInt proto WIN_STD_CALL_CONV :LONGLONG, :ptr UINT
    LongLongToUInt32 equ <LongLongToUInt>
    ifdef _WIN64
      LongLongToUIntPtr equ <LongLongToULongLong>
    else
      LongLongToUIntPtr equ <LongLongToUInt>
    endif
    LongLongToLong proto WIN_STD_CALL_CONV :LONGLONG, :ptr LONG
    ifdef _WIN64
      LongLongToLongPtr proto WIN_STD_CALL_CONV :LONGLONG, :ptr LONG_PTR
    else
      LongLongToLongPtr equ <LongLongToLong>
    endif
    LongLongToULong proto WIN_STD_CALL_CONV :LONGLONG, :ptr ULONG
    ifdef _WIN64
      LongLongToULongPtr equ <LongLongToULongLong>
    else
      LongLongToULongPtr equ <LongLongToULong>
    endif
    LongLongToDWord equ <LongLongToULong>
    LongLongToDWordPtr equ <LongLongToULongPtr>
    LongLongToULongLong proto WIN_STD_CALL_CONV :LONGLONG, :ptr ULONGLONG
    LongLongToDWordLong equ <LongLongToULongLong>
    LongLongToULong64 equ <LongLongToULongLong>
    LongLongToDWord64 equ <LongLongToULongLong>
    LongLongToUInt64 equ <LongLongToULongLong>
    LongLongToPtrdiffT equ <LongLongToIntPtr>
    LongLongToSizeT equ <LongLongToUIntPtr>
    LongLongToSSIZET equ <LongLongToLongPtr>
    LongLongToSIZET equ <LongLongToULongPtr>
    Long64ToChar equ <LongLongToChar>
    Long64ToInt8 equ <LongLongToInt8>
    Long64ToUChar equ <LongLongToUChar>
    Long64ToUInt8 equ <LongLongToUInt8>
    Long64ToByte equ <LongLongToUInt8>
    Long64ToShort equ <LongLongToShort>
    Long64ToInt16 equ <LongLongToShort>
    Long64ToUShort equ <LongLongToUShort>
    Long64ToUInt16 equ <LongLongToUShort>
    Long64ToWord equ <LongLongToUShort>
    Long64ToInt equ <LongLongToInt>
    Long64ToInt32 equ <LongLongToInt>
    Long64ToIntPtr equ <LongLongToIntPtr>
    Long64ToUInt equ <LongLongToUInt>
    Long64ToUInt32 equ <LongLongToUInt>
    Long64ToUIntPtr equ <LongLongToUIntPtr>
    Long64ToLong equ <LongLongToLong>
    Long64ToLongPtr equ <LongLongToLongPtr>
    Long64ToULong equ <LongLongToULong>
    Long64ToULongPtr equ <LongLongToULongPtr>
    Long64ToDWord equ <LongLongToULong>
    Long64ToDWordPtr equ <LongLongToULongPtr>
    Long64ToULongLong equ <LongLongToULongLong>
    Long64ToPtrdiffT equ <LongLongToIntPtr>
    Long64ToSizeT equ <LongLongToUIntPtr>
    Long64ToSSIZET equ <LongLongToLongPtr>
    Long64ToSIZET equ <LongLongToULongPtr>
    Int64ToChar equ <LongLongToChar>
    Int64ToInt8 equ <LongLongToInt8>
    Int64ToUChar equ <LongLongToUChar>
    Int64ToUInt8 equ <LongLongToUInt8>
    Int64ToByte equ <LongLongToUInt8>
    Int64ToShort equ <LongLongToShort>
    Int64ToInt16 equ <LongLongToShort>
    Int64ToUShort equ <LongLongToUShort>
    Int64ToUInt16 equ <LongLongToUShort>
    Int64ToWord equ <LongLongToUShort>
    Int64ToInt equ <LongLongToInt>
    Int64ToInt32 equ <LongLongToInt>
    Int64ToIntPtr equ <LongLongToIntPtr>
    Int64ToUInt equ <LongLongToUInt>
    Int64ToUInt32 equ <LongLongToUInt>
    Int64ToUIntPtr equ <LongLongToUIntPtr>
    Int64ToLong equ <LongLongToLong>
    Int64ToLongPtr equ <LongLongToLongPtr>
    Int64ToULong equ <LongLongToULong>
    Int64ToULongPtr equ <LongLongToULongPtr>
    Int64ToDWord equ <LongLongToULong>
    Int64ToDWordPtr equ <LongLongToULongPtr>
    Int64ToULongLong equ <LongLongToULongLong>
    Int64ToDWordLong equ <LongLongToULongLong>
    Int64ToULong64 equ <LongLongToULongLong>
    Int64ToDWord64 equ <LongLongToULongLong>
    Int64ToUInt64 equ <LongLongToULongLong>
    Int64ToPtrdiffT equ <LongLongToIntPtr>
    Int64ToSizeT equ <LongLongToUIntPtr>
    Int64ToSSIZET equ <LongLongToLongPtr>
    Int64ToSIZET equ <LongLongToULongPtr>
    ULongLongToInt8 proto WIN_STD_CALL_CONV :ULONGLONG, :ptr INT8
    ULongLongToUChar proto WIN_STD_CALL_CONV :ULONGLONG, :ptr UCHAR
    ULongLongToChar proto WIN_STD_CALL_CONV :ULONGLONG, :ptr CHAR
    ifdef _CHAR_UNSIGNED
    else
    endif
    ULongLongToUInt8 proto WIN_STD_CALL_CONV :ULONGLONG, :ptr UINT8
    ULongLongToByte equ <ULongLongToUInt8>
    ULongLongToShort proto WIN_STD_CALL_CONV :ULONGLONG, :ptr SHORT_
    ULongLongToInt16 equ <ULongLongToShort>
    ULongLongToUShort proto WIN_STD_CALL_CONV :ULONGLONG, :ptr USHORT
    ULongLongToUInt16 equ <ULongLongToUShort>
    ULongLongToWord equ <ULongLongToUShort>
    ULongLongToInt proto WIN_STD_CALL_CONV :ULONGLONG, :ptr INT_
    ULongLongToInt32 equ <ULongLongToInt>
    ifdef _WIN64
      ULongLongToIntPtr equ <ULongLongToLongLong>
    else
      ULongLongToIntPtr equ <ULongLongToInt>
    endif
    ULongLongToUInt proto WIN_STD_CALL_CONV :ULONGLONG, :ptr UINT
    ULongLongToUInt32 equ <ULongLongToUInt>
    ifdef _WIN64
      ULongLongToUIntPtr proto WIN_STD_CALL_CONV :ULONGLONG, :ptr UINT_PTR
    else
      ULongLongToUIntPtr equ <ULongLongToUInt>
    endif
    ULongLongToLong proto WIN_STD_CALL_CONV :ULONGLONG, :ptr LONG
    ULongLongToLongPtr proto WIN_STD_CALL_CONV :ULONGLONG, :ptr LONG_PTR
    ULongLongToULong proto WIN_STD_CALL_CONV :ULONGLONG, :ptr ULONG
    ifdef _WIN64
      ULongLongToULongPtr proto WIN_STD_CALL_CONV :ULONGLONG, :ptr ULONG_PTR
    else
      ULongLongToULongPtr equ <ULongLongToULong>
    endif
    ULongLongToDWord equ <ULongLongToULong>
    ULongLongToDWordPtr equ <ULongLongToULongPtr>
    ULongLongToLongLong proto WIN_STD_CALL_CONV :ULONGLONG, :ptr LONGLONG
    ULongLongToInt64 equ <ULongLongToLongLong>
    ULongLongToLong64 equ <ULongLongToLongLong>
    ULongLongToPtrdiffT equ <ULongLongToIntPtr>
    ULongLongToSizeT equ <ULongLongToUIntPtr>
    ULongLongToSSIZET equ <ULongLongToLongPtr>
    ULongLongToSIZET equ <ULongLongToULongPtr>
    DWordLongToChar equ <ULongLongToChar>
    DWordLongToInt8 equ <ULongLongToInt8>
    DWordLongToUChar equ <ULongLongToUChar>
    DWordLongToUInt8 equ <ULongLongToUInt8>
    DWordLongToByte equ <ULongLongToUInt8>
    DWordLongToShort equ <ULongLongToShort>
    DWordLongToInt16 equ <ULongLongToShort>
    DWordLongToUShort equ <ULongLongToUShort>
    DWordLongToUInt16 equ <ULongLongToUShort>
    DWordLongToWord equ <ULongLongToUShort>
    DWordLongToInt equ <ULongLongToInt>
    DWordLongToInt32 equ <ULongLongToInt>
    DWordLongToIntPtr equ <ULongLongToIntPtr>
    DWordLongToUInt equ <ULongLongToUInt>
    DWordLongToUInt32 equ <ULongLongToUInt>
    DWordLongToUIntPtr equ <ULongLongToUIntPtr>
    DWordLongToLong equ <ULongLongToLong>
    DWordLongToLongPtr equ <ULongLongToLongPtr>
    DWordLongToULong equ <ULongLongToULong>
    DWordLongToULongPtr equ <ULongLongToULongPtr>
    DWordLongToDWord equ <ULongLongToULong>
    DWordLongToDWordPtr equ <ULongLongToULongPtr>
    DWordLongToLongLong equ <ULongLongToLongLong>
    DWordLongToLong64 equ <ULongLongToLongLong>
    DWordLongToInt64 equ <ULongLongToLongLong>
    DWordLongToPtrdiffT equ <ULongLongToIntPtr>
    DWordLongToSizeT equ <ULongLongToUIntPtr>
    DWordLongToSSIZET equ <ULongLongToLongPtr>
    DWordLongToSIZET equ <ULongLongToULongPtr>
    ULong64ToChar equ <ULongLongToChar>
    ULong64ToInt8 equ <ULongLongToInt8>
    ULong64ToUChar equ <ULongLongToUChar>
    ULong64ToUInt8 equ <ULongLongToUInt8>
    ULong64ToByte equ <ULongLongToUInt8>
    ULong64ToShort equ <ULongLongToShort>
    ULong64ToInt16 equ <ULongLongToShort>
    ULong64ToUShort equ <ULongLongToUShort>
    ULong64ToUInt16 equ <ULongLongToUShort>
    ULong64ToWord equ <ULongLongToUShort>
    ULong64ToInt equ <ULongLongToInt>
    ULong64ToInt32 equ <ULongLongToInt>
    ULong64ToIntPtr equ <ULongLongToIntPtr>
    ULong64ToUInt equ <ULongLongToUInt>
    ULong64ToUInt32 equ <ULongLongToUInt>
    ULong64ToUIntPtr equ <ULongLongToUIntPtr>
    ULong64ToLong equ <ULongLongToLong>
    ULong64ToLongPtr equ <ULongLongToLongPtr>
    ULong64ToULong equ <ULongLongToULong>
    ULong64ToULongPtr equ <ULongLongToULongPtr>
    ULong64ToDWord equ <ULongLongToULong>
    ULong64ToDWordPtr equ <ULongLongToULongPtr>
    ULong64ToLongLong equ <ULongLongToLongLong>
    ULong64ToLong64 equ <ULongLongToLongLong>
    ULong64ToInt64 equ <ULongLongToLongLong>
    ULong64ToPtrdiffT equ <ULongLongToIntPtr>
    ULong64ToSizeT equ <ULongLongToUIntPtr>
    ULong64ToSSIZET equ <ULongLongToLongPtr>
    ULong64ToSIZET equ <ULongLongToULongPtr>
    DWord64ToChar equ <ULongLongToChar>
    DWord64ToInt8 equ <ULongLongToInt8>
    DWord64ToUChar equ <ULongLongToUChar>
    DWord64ToUInt8 equ <ULongLongToUInt8>
    DWord64ToByte equ <ULongLongToUInt8>
    DWord64ToShort equ <ULongLongToShort>
    DWord64ToInt16 equ <ULongLongToShort>
    DWord64ToUShort equ <ULongLongToUShort>
    DWord64ToUInt16 equ <ULongLongToUShort>
    DWord64ToWord equ <ULongLongToUShort>
    DWord64ToInt equ <ULongLongToInt>
    DWord64ToInt32 equ <ULongLongToInt>
    DWord64ToIntPtr equ <ULongLongToIntPtr>
    DWord64ToUInt equ <ULongLongToUInt>
    DWord64ToUInt32 equ <ULongLongToUInt>
    DWord64ToUIntPtr equ <ULongLongToUIntPtr>
    DWord64ToLong equ <ULongLongToLong>
    DWord64ToLongPtr equ <ULongLongToLongPtr>
    DWord64ToULong equ <ULongLongToULong>
    DWord64ToULongPtr equ <ULongLongToULongPtr>
    DWord64ToDWord equ <ULongLongToULong>
    DWord64ToDWordPtr equ <ULongLongToULongPtr>
    DWord64ToLongLong equ <ULongLongToLongLong>
    DWord64ToLong64 equ <ULongLongToLongLong>
    DWord64ToInt64 equ <ULongLongToLongLong>
    DWord64ToPtrdiffT equ <ULongLongToIntPtr>
    DWord64ToSizeT equ <ULongLongToUIntPtr>
    DWord64ToSSIZET equ <ULongLongToLongPtr>
    DWord64ToSIZET equ <ULongLongToULongPtr>
    UInt64ToChar equ <ULongLongToChar>
    UInt64ToInt8 equ <ULongLongToInt8>
    UInt64ToUChar equ <ULongLongToUChar>
    UInt64ToUInt8 equ <ULongLongToUInt8>
    UInt64ToByte equ <ULongLongToUInt8>
    UInt64ToShort equ <ULongLongToShort>
    UInt64ToInt16 equ <ULongLongToShort>
    UInt64ToUShort equ <ULongLongToUShort>
    UInt64ToUInt16 equ <ULongLongToUShort>
    UInt64ToWord equ <ULongLongToUShort>
    UInt64ToInt equ <ULongLongToInt>
    UInt64ToInt32 equ <ULongLongToInt>
    UInt64ToIntPtr equ <ULongLongToIntPtr>
    UInt64ToUInt equ <ULongLongToUInt>
    UInt64ToUInt32 equ <ULongLongToUInt>
    UInt64ToUIntPtr equ <ULongLongToUIntPtr>
    UInt64ToLong equ <ULongLongToLong>
    UInt64ToLongPtr equ <ULongLongToLongPtr>
    UInt64ToULong equ <ULongLongToULong>
    UInt64ToULongPtr equ <ULongLongToULongPtr>
    UInt64ToDWord equ <ULongLongToULong>
    UInt64ToDWordPtr equ <ULongLongToULongPtr>
    UInt64ToLongLong equ <ULongLongToLongLong>
    UInt64ToLong64 equ <ULongLongToLongLong>
    UInt64ToInt64 equ <ULongLongToLongLong>
    UInt64ToPtrdiffT equ <ULongLongToIntPtr>
    UInt64ToSizeT equ <ULongLongToUIntPtr>
    UInt64ToSSIZET equ <ULongLongToLongPtr>
    UInt64ToSIZET equ <ULongLongToULongPtr>
    PtrdiffTToChar equ <IntPtrToChar>
    PtrdiffTToInt8 equ <IntPtrToInt8>
    PtrdiffTToUChar equ <IntPtrToUChar>
    PtrdiffTToUInt8 equ <IntPtrToUInt8>
    PtrdiffTToByte equ <IntPtrToUInt8>
    PtrdiffTToShort equ <IntPtrToShort>
    PtrdiffTToInt16 equ <IntPtrToShort>
    PtrdiffTToUShort equ <IntPtrToUShort>
    PtrdiffTToUInt16 equ <IntPtrToUShort>
    PtrdiffTToWord equ <IntPtrToUShort>
    PtrdiffTToInt equ <IntPtrToInt>
    PtrdiffTToInt32 equ <IntPtrToInt>
    PtrdiffTToUInt equ <IntPtrToUInt>
    PtrdiffTToUInt32 equ <IntPtrToUInt>
    PtrdiffTToUIntPtr equ <IntPtrToUIntPtr>
    PtrdiffTToLong equ <IntPtrToLong>
    PtrdiffTToLongPtr equ <IntPtrToLongPtr>
    PtrdiffTToULong equ <IntPtrToULong>
    PtrdiffTToULongPtr equ <IntPtrToULongPtr>
    PtrdiffTToDWord equ <IntPtrToULong>
    PtrdiffTToDWordPtr equ <IntPtrToULongPtr>
    PtrdiffTToULongLong equ <IntPtrToULongLong>
    PtrdiffTToDWordLong equ <IntPtrToULongLong>
    PtrdiffTToULong64 equ <IntPtrToULongLong>
    PtrdiffTToDWord64 equ <IntPtrToULongLong>
    PtrdiffTToUInt64 equ <IntPtrToULongLong>
    PtrdiffTToSizeT equ <IntPtrToUIntPtr>
    PtrdiffTToSIZET equ <IntPtrToULongPtr>
    SizeTToInt8 equ <UIntPtrToInt8>
    SizeTToUChar equ <UIntPtrToUChar>
    SizeTToChar equ <UIntPtrToChar>
    SizeTToUInt8 equ <UIntPtrToUInt8>
    SizeTToByte equ <UIntPtrToUInt8>
    SizeTToShort equ <UIntPtrToShort>
    SizeTToInt16 equ <UIntPtrToShort>
    SizeTToUShort equ <UIntPtrToUShort>
    SizeTToUInt16 equ <UIntPtrToUShort>
    SizeTToWord equ <UIntPtrToUShort>
    SizeTToInt equ <UIntPtrToInt>
    SizeTToInt32 equ <UIntPtrToInt>
    SizeTToIntPtr equ <UIntPtrToIntPtr>
    SizeTToUInt equ <UIntPtrToUInt>
    SizeTToUInt32 equ <UIntPtrToUInt>
    SizeTToLong equ <UIntPtrToLong>
    SizeTToLongPtr equ <UIntPtrToLongPtr>
    SizeTToULong equ <UIntPtrToULong>
    SizeTToDWord equ <UIntPtrToULong>
    SizeTToLongLong equ <UIntPtrToLongLong>
    SizeTToLong64 equ <UIntPtrToLongLong>
    SizeTToInt64 equ <UIntPtrToLongLong>
    SizeTToPtrdiffT equ <UIntPtrToIntPtr>
    SizeTToSSIZET equ <UIntPtrToLongPtr>
    SSIZETToInt8 equ <LongPtrToInt8>
    SSIZETToUChar equ <LongPtrToUChar>
    SSIZETToChar equ <LongPtrToChar>
    SSIZETToUInt8 equ <LongPtrToUInt8>
    SSIZETToByte equ <LongPtrToUInt8>
    SSIZETToShort equ <LongPtrToShort>
    SSIZETToInt16 equ <LongPtrToShort>
    SSIZETToUShort equ <LongPtrToUShort>
    SSIZETToUInt16 equ <LongPtrToUShort>
    SSIZETToWord equ <LongPtrToUShort>
    SSIZETToInt equ <LongPtrToInt>
    SSIZETToInt32 equ <LongPtrToInt>
    SSIZETToIntPtr equ <LongPtrToIntPtr>
    SSIZETToUInt equ <LongPtrToUInt>
    SSIZETToUInt32 equ <LongPtrToUInt>
    SSIZETToUIntPtr equ <LongPtrToUIntPtr>
    SSIZETToLong equ <LongPtrToLong>
    SSIZETToULong equ <LongPtrToULong>
    SSIZETToULongPtr equ <LongPtrToULongPtr>
    SSIZETToDWord equ <LongPtrToULong>
    SSIZETToDWordPtr equ <LongPtrToULongPtr>
    SSIZETToULongLong equ <LongPtrToULongLong>
    SSIZETToDWordLong equ <LongPtrToULongLong>
    SSIZETToULong64 equ <LongPtrToULongLong>
    SSIZETToDWord64 equ <LongPtrToULongLong>
    SSIZETToUInt64 equ <LongPtrToULongLong>
    SSIZETToSizeT equ <LongPtrToUIntPtr>
    SSIZETToSIZET equ <LongPtrToULongPtr>
    SIZETToInt8 equ <ULongPtrToInt8>
    SIZETToUChar equ <ULongPtrToUChar>
    SIZETToChar equ <ULongPtrToChar>
    SIZETToUInt8 equ <ULongPtrToUInt8>
    SIZETToByte equ <ULongPtrToUInt8>
    SIZETToShort equ <ULongPtrToShort>
    SIZETToInt16 equ <ULongPtrToShort>
    SIZETToUShort equ <ULongPtrToUShort>
    SIZETToUInt16 equ <ULongPtrToUShort>
    SIZETToWord equ <ULongPtrToUShort>
    SIZETToInt equ <ULongPtrToInt>
    SIZETToInt32 equ <ULongPtrToInt>
    SIZETToIntPtr equ <ULongPtrToIntPtr>
    SIZETToUInt equ <ULongPtrToUInt>
    SIZETToUInt32 equ <ULongPtrToUInt>
    SIZETToUIntPtr equ <ULongPtrToUIntPtr>
    SIZETToLong equ <ULongPtrToLong>
    SIZETToLongPtr equ <ULongPtrToLongPtr>
    SIZETToULong equ <ULongPtrToULong>
    SIZETToDWord equ <ULongPtrToULong>
    SIZETToLongLong equ <ULongPtrToLongLong>
    SIZETToLong64 equ <ULongPtrToLongLong>
    SIZETToInt64 equ <ULongPtrToLongLong>
    SIZETToPtrdiffT equ <ULongPtrToIntPtr>
    SIZETToSSIZET equ <ULongPtrToLongPtr>
    UInt8Add proto WIN_STD_CALL_CONV :UINT8, :UINT8, :ptr UINT8
    UShortAdd proto WIN_STD_CALL_CONV :USHORT, :USHORT, :ptr USHORT
    UInt16Add equ <UShortAdd>
    WordAdd equ <UShortAdd>
    UIntAdd proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr UINT
    UInt32Add equ <UIntAdd>
    ifdef _WIN64
      UIntPtrAdd equ <ULongLongAdd>
    else
      UIntPtrAdd proto WIN_STD_CALL_CONV :UINT_PTR, :UINT_PTR, :ptr UINT_PTR
    endif
    ULongAdd proto WIN_STD_CALL_CONV :ULONG, :ULONG, :ptr ULONG
    ifdef _WIN64
      ULongPtrAdd equ <ULongLongAdd>
    else
      ULongPtrAdd proto WIN_STD_CALL_CONV :ULONG_PTR, :ULONG_PTR, :ptr ULONG_PTR
    endif
    DWordAdd equ <ULongAdd>
    ifdef _WIN64
      DWordPtrAdd equ <ULongLongAdd>
    else
      DWordPtrAdd proto WIN_STD_CALL_CONV :DWORD_PTR, :DWORD_PTR, :ptr DWORD_PTR
    endif
    SizeTAdd proto WIN_STD_CALL_CONV :size_t, :size_t, :ptr size_t
    ifdef _WIN64
      SIZETAdd equ <ULongLongAdd>
    else
      SIZETAdd proto WIN_STD_CALL_CONV :SIZE_T, :SIZE_T, :ptr SIZE_T
    endif
    ULongLongAdd proto WIN_STD_CALL_CONV :ULONGLONG, :ULONGLONG, :ptr ULONGLONG
    DWordLongAdd equ <ULongLongAdd>
    ULong64Add equ <ULongLongAdd>
    DWord64Add equ <ULongLongAdd>
    UInt64Add equ <ULongLongAdd>
    UInt8Sub proto WIN_STD_CALL_CONV :UINT8, :UINT8, :ptr UINT8
    UShortSub proto WIN_STD_CALL_CONV :USHORT, :USHORT, :ptr USHORT
    UInt16Sub equ <UShortSub>
    WordSub equ <UShortSub>
    UIntSub proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr UINT
    UInt32Sub equ <UIntSub>
    ifdef _WIN64
      UIntPtrSub equ <ULongLongSub>
    else
      UIntPtrSub proto WIN_STD_CALL_CONV :UINT_PTR, :UINT_PTR, :ptr UINT_PTR
    endif
    ULongSub proto WIN_STD_CALL_CONV :ULONG, :ULONG, :ptr ULONG
    ifdef _WIN64
      ULongPtrSub equ <ULongLongSub>
    else
      ULongPtrSub proto WIN_STD_CALL_CONV :ULONG_PTR, :ULONG_PTR, :ptr ULONG_PTR
    endif
    DWordSub equ <ULongSub>
    ifdef _WIN64
      DWordPtrSub equ <ULongLongSub>
    else
      DWordPtrSub proto WIN_STD_CALL_CONV :DWORD_PTR, :DWORD_PTR, :ptr DWORD_PTR
    endif
    SizeTSub proto WIN_STD_CALL_CONV :size_t, :size_t, :ptr size_t
    ifdef _WIN64
      SIZETSub equ <ULongLongSub>
    else
      SIZETSub proto WIN_STD_CALL_CONV :SIZE_T, :SIZE_T, :ptr SIZE_T
    endif
    ULongLongSub proto WIN_STD_CALL_CONV :ULONGLONG, :ULONGLONG, :ptr ULONGLONG
    DWordLongSub equ <ULongLongSub>
    ULong64Sub equ <ULongLongSub>
    DWord64Sub equ <ULongLongSub>
    UInt64Sub equ <ULongLongSub>
    UInt8Mult proto WIN_STD_CALL_CONV :UINT8, :UINT8, :ptr UINT8
    UShortMult proto WIN_STD_CALL_CONV :USHORT, :USHORT, :ptr USHORT
    UInt16Mult equ <UShortMult>
    WordMult equ <UShortMult>
    UIntMult proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr UINT
    UInt32Mult equ <UIntMult>
    ifdef _WIN64
      UIntPtrMult equ <ULongLongMult>
    else
      UIntPtrMult proto WIN_STD_CALL_CONV :UINT_PTR, :UINT_PTR, :ptr UINT_PTR
    endif
    ULongMult proto WIN_STD_CALL_CONV :ULONG, :ULONG, :ptr ULONG
    ifdef _WIN64
      ULongPtrMult equ <ULongLongMult>
    else
      ULongPtrMult proto WIN_STD_CALL_CONV :ULONG_PTR, :ULONG_PTR, :ptr ULONG_PTR
    endif
    DWordMult equ <ULongMult>
    ifdef _WIN64
      DWordPtrMult equ <ULongLongMult>
    else
      DWordPtrMult proto WIN_STD_CALL_CONV :DWORD_PTR, :DWORD_PTR, :ptr DWORD_PTR
    endif
    ifdef _WIN64
      SizeTMult equ <ULongLongMult>
    else
      SizeTMult proto WIN_STD_CALL_CONV :size_t, :size_t, :ptr size_t
    endif
    ifdef _WIN64
      SIZETMult equ <ULongLongMult>
    else
      SIZETMult proto WIN_STD_CALL_CONV :SIZE_T, :SIZE_T, :ptr SIZE_T
    endif
    ULongLongMult proto WIN_STD_CALL_CONV :ULONGLONG, :ULONGLONG, :ptr ULONGLONG
    if Defined(_USE_INTRINSIC_MULTIPLY128)
    else
    endif
    DWordLongMult equ <ULongLongMult>
    ULong64Mult equ <ULongLongMult>
    DWord64Mult equ <ULongLongMult>
    UInt64Mult equ <ULongLongMult>
    if Defined(ENABLE_INTSAFE_SIGNED_FUNCTIONS)
      if Defined(_USE_INTRINSIC_MULTIPLY128)
        ifdef __cplusplus
          ;[...]
        endif
        if  not Defined(_ARM64EC_)
          Multiply128 equ <_mul128>
        else
          _mul128 equ <Multiply128>
        endif
        Multiply128 proto WIN_STD_CALL_CONV :LONG64, :LONG64, :ptr LONG64
        if  not Defined(_ARM64EC_)
        endif
        ifdef __cplusplus
          ;[...]
        endif
      endif
      Int8Add proto WIN_STD_CALL_CONV :INT8, :INT8, :ptr INT8
      ShortAdd proto WIN_STD_CALL_CONV :SHORT_, :SHORT_, :ptr SHORT_
      Int16Add equ <ShortAdd>
      IntAdd proto WIN_STD_CALL_CONV :INT_, :INT_, :ptr INT_
      Int32Add equ <IntAdd>
      ifdef _WIN64
        IntPtrAdd equ <LongLongAdd>
      else
        IntPtrAdd proto WIN_STD_CALL_CONV :INT_PTR, :INT_PTR, :ptr INT_PTR
      endif
      LongAdd proto WIN_STD_CALL_CONV :LONG, :LONG, :ptr LONG
      Long32Add equ <IntAdd>
      ifdef _WIN64
        LongPtrAdd equ <LongLongAdd>
      else
        LongPtrAdd proto WIN_STD_CALL_CONV :LONG_PTR, :LONG_PTR, :ptr LONG_PTR
      endif
      LongLongAdd proto WIN_STD_CALL_CONV :LONGLONG, :LONGLONG, :ptr LONGLONG
      Long64Add equ <LongLongAdd>
      Int64Add equ <LongLongAdd>
      ifdef _WIN64
        PtrdiffTAdd equ <LongLongAdd>
      else
        PtrdiffTAdd proto WIN_STD_CALL_CONV :ptrdiff_t, :ptrdiff_t, :ptr ptrdiff_t
      endif
      ifdef _WIN64
        SSIZETAdd equ <LongLongAdd>
      else
        SSIZETAdd proto WIN_STD_CALL_CONV :SSIZE_T, :SSIZE_T, :ptr SSIZE_T
      endif
      Int8Sub proto WIN_STD_CALL_CONV :INT8, :INT8, :ptr INT8
      ShortSub proto WIN_STD_CALL_CONV :SHORT_, :SHORT_, :ptr SHORT_
      Int16Sub equ <ShortSub>
      IntSub proto WIN_STD_CALL_CONV :INT_, :INT_, :ptr INT_
      Int32Sub equ <IntSub>
      ifdef _WIN64
        IntPtrSub equ <LongLongSub>
      else
        IntPtrSub proto WIN_STD_CALL_CONV :INT_PTR, :INT_PTR, :ptr INT_PTR
      endif
      LongSub proto WIN_STD_CALL_CONV :LONG, :LONG, :ptr LONG
      Long32Sub equ <IntSub>
      ifdef _WIN64
        LongPtrSub equ <LongLongSub>
      else
        LongPtrSub proto WIN_STD_CALL_CONV :LONG_PTR, :LONG_PTR, :ptr LONG_PTR
      endif
      LongLongSub proto WIN_STD_CALL_CONV :LONGLONG, :LONGLONG, :ptr LONGLONG
      Long64Sub equ <LongLongSub>
      Int64Sub equ <LongLongSub>
      ifdef _WIN64
        PtrdiffTSub equ <LongLongSub>
      else
        PtrdiffTSub proto WIN_STD_CALL_CONV :ptrdiff_t, :ptrdiff_t, :ptr ptrdiff_t
      endif
      ifdef _WIN64
        SSIZETSub equ <LongLongSub>
      else
        SSIZETSub proto WIN_STD_CALL_CONV :SSIZE_T, :SSIZE_T, :ptr SSIZE_T
      endif
      Int8Mult proto WIN_STD_CALL_CONV :INT8, :INT8, :ptr INT8
      ShortMult proto WIN_STD_CALL_CONV :SHORT_, :SHORT_, :ptr SHORT_
      Int16Mult equ <ShortMult>
      IntMult proto WIN_STD_CALL_CONV :INT_, :INT_, :ptr INT_
      Int32Mult equ <IntMult>
      ifdef _WIN64
        IntPtrMult equ <LongLongMult>
      else
        IntPtrMult proto WIN_STD_CALL_CONV :INT_PTR, :INT_PTR, :ptr INT_PTR
      endif
      LongMult proto WIN_STD_CALL_CONV :LONG, :LONG, :ptr LONG
      Long32Mult equ <IntMult>
      ifdef _WIN64
        LongPtrMult equ <LongLongMult>
      else
        LongPtrMult proto WIN_STD_CALL_CONV :LONG_PTR, :LONG_PTR, :ptr LONG_PTR
      endif
      LongLongMult proto WIN_STD_CALL_CONV :LONGLONG, :LONGLONG, :ptr LONGLONG
      if Defined(_USE_INTRINSIC_MULTIPLY128)
      else
      endif
      Long64Mult equ <LongLongMult>
      Int64Mult equ <LongLongMult>
      ifdef _WIN64
        PtrdiffTMult equ <LongLongMult>
      else
        PtrdiffTMult proto WIN_STD_CALL_CONV :ptrdiff_t, :ptrdiff_t, :ptr ptrdiff_t
      endif
      ifdef _WIN64
        SSIZETMult equ <LongLongMult>
      else
        SSIZETMult proto WIN_STD_CALL_CONV :SSIZE_T, :SSIZE_T, :ptr SSIZE_T
      endif
    endif
    ifndef LOWORD
      LOWORD macro l
        exitm <((((l)) and 0ffffh))>
      endm
    endif
    ifndef HIWORD
      HIWORD macro l
        exitm <(((((l)) shr 16) and 0ffffh))>
      endm
    endif
    ifndef LODWORD
      LODWORD macro _qw
        exitm <((_qw))>
      endm
    endif
    ifndef HIDWORD
      HIDWORD macro _qw
        exitm <((((_qw) shr 32) and 0ffffffffh))>
      endm
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif
