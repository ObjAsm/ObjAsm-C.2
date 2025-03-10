;Include file created by h2incX, Version C.01.00, 05/02/2023 08:00
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um\sqltypes.h', last modified: 13/10/2022 20:10
;Creation parameters: 

if Defined(_MSC_VER) and (_MSC_VER gt 1000)
endif
ifndef __SQLTYPES
  __SQLTYPES equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef ODBCVER
      ODBCVER equ 0380h
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef EXPORT_
      EXPORT_ equ <>
    endif
    ifdef WIN32
      SQL_API equ <__stdcall>
    else
      SQL_API equ <>
    endif
    ifndef RC_INVOKED
      SQLCHAR typedef BYTE
      if (ODBCVER ge 0300h)
        SQLSCHAR typedef SBYTE
        SQLDATE typedef BYTE
        SQLDECIMAL typedef BYTE
        SQLDOUBLE typedef REAL8
        SQLFLOAT typedef REAL8
      endif
      SQLINTEGER typedef SDWORD
      SQLUINTEGER typedef DWORD
      ifdef _WIN64
        SQLLEN typedef INT64
        SQLULEN typedef UINT64
        SQLSETPOSIROW typedef UINT64
      else
        SQLLEN equ <SQLINTEGER>
        SQLULEN equ <SQLUINTEGER>
        SQLSETPOSIROW equ <SQLUSMALLINT>
      endif
      ifdef WIN32
        SQLROWCOUNT typedef SQLULEN
        SQLROWSETSIZE typedef SQLULEN
        SQLTRANSID typedef SQLULEN
        SQLROWOFFSET typedef SQLLEN
      endif
      if (ODBCVER ge 0300h)
        SQLNUMERIC typedef BYTE
      endif
      SQLPOINTER typedef ptr
      if (ODBCVER ge 0300h)
        SQLREAL typedef REAL4
      endif
      SQLSMALLINT typedef SWORD
      SQLUSMALLINT typedef WORD
      if (ODBCVER ge 0300h)
        SQLTIME typedef BYTE
        SQLTIMESTAMP typedef BYTE
        SQLVARCHAR typedef BYTE
      endif
      SQLRETURN typedef SQLSMALLINT
      if (ODBCVER ge 0300h)
        if Defined(WIN32) or Defined(_WIN64)
          SQLHANDLE typedef ptr
        else
          SQLHANDLE typedef SQLINTEGER
        endif
        SQLHENV typedef SQLHANDLE
        SQLHDBC typedef SQLHANDLE
        SQLHSTMT typedef SQLHANDLE
        SQLHDESC typedef SQLHANDLE
      else
        if Defined(WIN32) or Defined(_WIN64)
          SQLHENV typedef ptr
          SQLHDBC typedef ptr
          SQLHSTMT typedef ptr
        else
          SQLHENV typedef SQLINTEGER
          SQLHDBC typedef SQLINTEGER
          SQLHSTMT typedef SQLINTEGER
        endif
      endif
      UCHAR typedef BYTE
      SCHAR typedef SBYTE
      SQLSCHAR typedef SCHAR
      UDWORD typedef DWORD
      UWORD typedef WORD
      ifndef _WIN64
        SQLUINTEGER typedef UDWORD
      endif
      SLONG typedef SDWORD
      SSHORT typedef SWORD
      ULONG typedef DWORD
      USHORT typedef WORD
      SDOUBLE typedef REAL8
      LDOUBLE typedef REAL8
      SFLOAT typedef REAL4
      PTR_ typedef ptr
      HENV typedef ptr
      HDBC typedef ptr
      HSTMT typedef ptr
      RETCODE typedef SWORD
      if Defined(WIN32) or Defined(OS2)
        SQLHWND typedef HWND
      elseif Defined(UNIX)
        SQLHWND typedef Widget
      else
        SQLHWND typedef SQLPOINTER
      endif
      ifndef __SQLDATE
        __SQLDATE equ <>
        DATE_STRUCT struct
          year SQLSMALLINT ?
          month SQLUSMALLINT ?
          day SQLUSMALLINT ?
        DATE_STRUCT ends
        tagDATE_STRUCT typedef DATE_STRUCT
        if (ODBCVER ge 0300h)
          SQL_DATE_STRUCT typedef DATE_STRUCT
        endif
        TIME_STRUCT struct
          hour SQLUSMALLINT ?
          minute SQLUSMALLINT ?
          second SQLUSMALLINT ?
        TIME_STRUCT ends
        tagTIME_STRUCT typedef TIME_STRUCT
        if (ODBCVER ge 0300h)
          SQL_TIME_STRUCT typedef TIME_STRUCT
        endif
        TIMESTAMP_STRUCT struct
          year SQLSMALLINT ?
          month SQLUSMALLINT ?
          day SQLUSMALLINT ?
          hour SQLUSMALLINT ?
          minute SQLUSMALLINT ?
          second SQLUSMALLINT ?
          fraction SQLUINTEGER ?
        TIMESTAMP_STRUCT ends
        tagTIMESTAMP_STRUCT typedef TIMESTAMP_STRUCT
        if (ODBCVER ge 0300h)
          SQL_TIMESTAMP_STRUCT typedef TIMESTAMP_STRUCT
        endif
        if (ODBCVER ge 0300h)
          SQLINTERVAL typedef SDWORD
          SQL_IS_YEAR equ 1
          SQL_IS_MONTH equ 2
          SQL_IS_DAY equ 3
          SQL_IS_HOUR equ 4
          SQL_IS_MINUTE equ 5
          SQL_IS_SECOND equ 6
          SQL_IS_YEAR_TO_MONTH equ 7
          SQL_IS_DAY_TO_HOUR equ 8
          SQL_IS_DAY_TO_MINUTE equ 9
          SQL_IS_DAY_TO_SECOND equ 10
          SQL_IS_HOUR_TO_MINUTE equ 11
          SQL_IS_HOUR_TO_SECOND equ 12
          SQL_IS_MINUTE_TO_SECOND equ 13
          
        endif
        if (ODBCVER ge 0300h)
          SQL_YEAR_MONTH_STRUCT struct
            year SQLUINTEGER ?
            month SQLUINTEGER ?
          SQL_YEAR_MONTH_STRUCT ends
          tagSQL_YEAR_MONTH typedef SQL_YEAR_MONTH_STRUCT
          SQL_DAY_SECOND_STRUCT struct
            day SQLUINTEGER ?
            hour SQLUINTEGER ?
            minute SQLUINTEGER ?
            second SQLUINTEGER ?
            fraction SQLUINTEGER ?
          SQL_DAY_SECOND_STRUCT ends
          tagSQL_DAY_SECOND typedef SQL_DAY_SECOND_STRUCT
          SQL_INTERVAL_STRUCT struct
            interval_type SQLINTERVAL ?
            interval_sign SQLSMALLINT ?
            union intval
              year_month SQL_YEAR_MONTH_STRUCT <>
              day_second SQL_DAY_SECOND_STRUCT <>
            ends
          SQL_INTERVAL_STRUCT ends
          tagSQL_INTERVAL_STRUCT typedef SQL_INTERVAL_STRUCT
        endif
      endif
      if (ODBCVER ge 0300h)
;        if (_MSC_VER ge 900)
;          ODBCINT64 equ <
;        endif
;        ifdef ODBCINT64
;          SQWORD __int64 ODBCINT64 SQLBIGINT ;>
;          SQLUBIGINT typedef DWORD
;        endif
      endif
      if (ODBCVER ge 0300h)
        SQL_MAX_NUMERIC_LEN equ 16
        SQL_NUMERIC_STRUCT struct
          precision SQLCHAR ?
          scale SQLSCHAR ?
          sign SQLCHAR ?
          val SQLCHAR SQL_MAX_NUMERIC_LEN dup (?)
        SQL_NUMERIC_STRUCT ends
        tagSQL_NUMERIC_STRUCT typedef SQL_NUMERIC_STRUCT
      endif
      if (ODBCVER ge 0350h)
        ifdef GUID_DEFINED
          SQLGUID typedef GUID
        else
          SQLGUID struct
            Data1 DWORD ?
            Data2 WORD ?
            Data3 WORD ?
            Data4 BYTE 8 dup (?)
          SQLGUID ends
          tagSQLGUID typedef SQLGUID
        endif
      endif
      BOOKMARK typedef SQLULEN
      ifdef _WCHAR_T_DEFINED
        SQLWCHAR typedef wchar_t
      else
        SQLWCHAR typedef WORD
      endif
      ifdef UNICODE
        SQLTCHAR typedef SQLWCHAR
      else
        SQLTCHAR typedef SQLCHAR
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
 