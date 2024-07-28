;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\StdIO.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_STDIO
  _INC_STDIO equ <>
  include crtdefs.inc
  ifdef __cplusplus
    ;[...]
  endif
  BUFSIZ equ 512
  _NFILE equ <_NSTREAM_>
  _NSTREAM_ equ 512
  _IOB_ENTRIES equ 20
  EOF equ -1
  ifndef _FILE_DEFINED
    _iobuf struct
      _ptr POINTER ?
      _cnt SDWORD ?
      _base POINTER ?
      _flag SDWORD ?
      _file SDWORD ?
      _charbuf SDWORD ?
      _bufsiz SDWORD ?
      _tmpfname POINTER ?
    _iobuf ends
    FILE typedef _iobuf
    
    _FILE_DEFINED equ <>
  endif
  ifdef _POSIX_
    ;[...]
  else
    _P_tmpdir equ <"\">
    _wP_tmpdir equ <L("\")>
  endif
  L_tmpnam equ (sizeof(_P_tmpdir) + 12)
  if __STDC_WANT_SECURE_LIB__
    L_tmpnam_s equ (sizeof(_P_tmpdir) + 16)
  endif
  ifdef _POSIX_
    ;[...]
  endif
  SEEK_CUR equ 1
  SEEK_END equ 2
  SEEK_SET equ 0
  FILENAME_MAX equ 260
  FOPEN_MAX equ 20
  _SYS_OPEN equ 20
  TMP_MAX equ 32767
  if __STDC_WANT_SECURE_LIB__
    TMP_MAX_S equ <_TMP_MAX_S>
    _TMP_MAX_S equ 2147483647
  endif
  ifndef NULL
    ifdef __cplusplus
      ;[...]
    else
      NULL equ (0)
    endif
  endif
  ifndef _STDIO_DEFINED
    @DefProto DllImport, __iob_func, c,, <>
  endif
  ifndef _FPOS_T_DEFINED
    fpos_t typedef SQWORD
    _FPOS_T_DEFINED equ <>
  endif
  ifndef _STDSTREAM_DEFINED
    stdin equ (and __iob_func () [ 0 ])
    stdout equ (and __iob_func () [ 1 ])
    stderr equ (and __iob_func () [ 2 ])
    _STDSTREAM_DEFINED equ <>
  endif
  _IOREAD equ 0001h
  _IOWRT equ 0002h
  _IOFBF equ 0000h
  _IOLBF equ 0040h
  _IONBF equ 0004h
  _IOMYBUF equ 0008h
  _IOEOF equ 0010h
  _IOERR equ 0020h
  _IOSTRG equ 0040h
  _IORW equ 0080h
  ifdef _POSIX_
    ;[...]
  endif
  _TWO_DIGIT_EXPONENT equ 1h
  ifndef _STDIO_DEFINED
    @DefProto DllImport, _filbuf, c,, <:ptr FILE>
    @DefProto DllImport, _flsbuf, c,, <:SDWORD, :ptr FILE>
    ifdef _POSIX_
      ;[...]
    else
      @DefProto DllImport, _fsopen, c,, <:ptr SBYTE, :ptr SBYTE, :SDWORD>
    endif
    @DefProto DllImport, clearerr, c,, <:ptr FILE>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, clearerr_s, c,, <:ptr FILE>
    endif
    @DefProto DllImport, fclose, c,, <:ptr FILE>
    @DefProto DllImport, _fcloseall, c,, <>
    ifdef _POSIX_
      ;[...]
    else
      @DefProto DllImport, _fdopen, c,, <:SDWORD, :ptr SBYTE>
    endif
    @DefProto DllImport, feof, c,, <:ptr FILE>
    @DefProto DllImport, ferror, c,, <:ptr FILE>
    @DefProto DllImport, fflush, c,, <:ptr FILE>
    @DefProto DllImport, fgetc, c,, <:ptr FILE>
    @DefProto DllImport, _fgetchar, c,, <>
    @DefProto DllImport, fgetpos, c,, <:ptr FILE, :ptr fpos_t>
    @DefProto DllImport, fgets, c,, <:ptr SBYTE, :SDWORD, :ptr FILE>
    ifdef _POSIX_
      ;[...]
    else
      @DefProto DllImport, _fileno, c,, <:ptr FILE>
    endif
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _tempnam, c,, <:ptr SBYTE, :ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _flushall, c,, <>
    @DefProto DllImport, fopen, c,, <:ptr SBYTE, :ptr SBYTE>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, fopen_s, c,, <:ptr ptr FILE, :ptr SBYTE, :ptr SBYTE>
    endif
    @DefProto DllImport, fprintf, c,, <:ptr FILE, :ptr SBYTE, :vararg>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, fprintf_s, c,, <:ptr FILE, :ptr SBYTE, :vararg>
    endif
    @DefProto DllImport, fputc, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, _fputchar, c,, <:SDWORD>
    @DefProto DllImport, fputs, c,, <:ptr SBYTE, :ptr FILE>
    @DefProto DllImport, fread, c,, <:ptr, :size_t, :size_t, :ptr FILE>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, fread_s, c,, <:ptr, :size_t, :size_t, :size_t, :ptr FILE>
    endif
    @DefProto DllImport, freopen, c,, <:ptr SBYTE, :ptr SBYTE, :ptr FILE>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, freopen_s, c,, <:ptr ptr FILE, :ptr SBYTE, :ptr SBYTE, :ptr FILE>
    endif
    @DefProto DllImport, fscanf, c,, <:ptr FILE, :ptr SBYTE, :vararg>
    @DefProto DllImport, _fscanf_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :vararg>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, fscanf_s, c,, <:ptr FILE, :ptr SBYTE, :vararg>
    endif
    @DefProto DllImport, _fscanf_s_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, fsetpos, c,, <:ptr FILE, :ptr fpos_t>
    @DefProto DllImport, fseek, c,, <:ptr FILE, :SDWORD, :SDWORD>
    @DefProto DllImport, ftell, c,, <:ptr FILE>
    @DefProto DllImport, _fseeki64, c,, <:ptr FILE, :SQWORD, :SDWORD>
    @DefProto DllImport, _ftelli64, c,, <:ptr FILE>
    @DefProto DllImport, fwrite, c,, <:ptr, :size_t, :size_t, :ptr FILE>
    @DefProto DllImport, getc, c,, <:ptr FILE>
    @DefProto DllImport, getchar, c,, <>
    @DefProto DllImport, _getmaxstdio, c,, <>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, gets_s, c,, <:ptr SBYTE, :rsize_t>
    endif
    _getw proto c :ptr FILE
    ifndef _CRT_PERROR_DEFINED
      _CRT_PERROR_DEFINED equ <>
      @DefProto DllImport, perror, c,, <:ptr SBYTE>
    endif
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      @DefProto DllImport, _pclose, c,, <:ptr FILE>
      @DefProto DllImport, _popen, c,, <:ptr SBYTE, :ptr SBYTE>
    endif
    @DefProto DllImport, printf, c,, <:ptr SBYTE, :vararg>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, printf_s, c,, <:ptr SBYTE, :vararg>
    endif
    @DefProto DllImport, putc, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, putchar, c,, <:SDWORD>
    @DefProto DllImport, puts, c,, <:ptr SBYTE>
    @DefProto DllImport, _putw, c,, <:SDWORD, :ptr FILE>
    ifndef _CRT_DIRECTORY_DEFINED
      _CRT_DIRECTORY_DEFINED equ <>
      @DefProto DllImport, remove, c,, <:ptr SBYTE>
      @DefProto DllImport, rename, c,, <:ptr SBYTE, :ptr SBYTE>
      @DefProto DllImport, _unlink, c,, <:ptr SBYTE>
      if  not __STDC__
        @DefProto DllImport, unlink, c,, <:ptr SBYTE>
      endif
    endif
    @DefProto DllImport, rewind, c,, <:ptr FILE>
    @DefProto DllImport, _rmtmp, c,, <>
    @DefProto DllImport, scanf, c,, <:ptr SBYTE, :vararg>
    @DefProto DllImport, _scanf_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, scanf_s, c,, <:ptr SBYTE, :vararg>
    endif
    @DefProto DllImport, _scanf_s_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, setbuf, c,, <:ptr FILE, :ptr SBYTE>
    @DefProto DllImport, _setmaxstdio, c,, <:SDWORD>
    @DefProto DllImport, _set_output_format, c,, <:DWORD>
    @DefProto DllImport, _get_output_format, c,, <>
    @DefProto DllImport, setvbuf, c,, <:ptr FILE, :ptr SBYTE, :SDWORD, :size_t>
    @DefProto DllImport, _snprintf_s, c,, <:ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :vararg>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, sprintf_s, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :vararg>
    endif
    @DefProto DllImport, _scprintf, c,, <:ptr SBYTE, :vararg>
    @DefProto DllImport, sscanf, c,, <:ptr SBYTE, :ptr SBYTE, :vararg>
    @DefProto DllImport, _sscanf_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t, :vararg>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, sscanf_s, c,, <:ptr SBYTE, :ptr SBYTE, :vararg>
    endif
    @DefProto DllImport, _sscanf_s_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _snscanf, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :vararg>
    @DefProto DllImport, _snscanf_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _snscanf_s, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :vararg>
    @DefProto DllImport, _snscanf_s_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, tmpfile, c,, <>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, tmpfile_s, c,, <:ptr ptr FILE>
      @DefProto DllImport, tmpnam_s, c,, <:ptr SBYTE, :rsize_t>
    endif
    @DefProto DllImport, ungetc, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, vfprintf, c,, <:ptr FILE, :ptr SBYTE, :va_list>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, vfprintf_s, c,, <:ptr FILE, :ptr SBYTE, :va_list>
    endif
    @DefProto DllImport, vprintf, c,, <:ptr SBYTE, :va_list>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, vprintf_s, c,, <:ptr SBYTE, :va_list>
    endif
    @DefProto DllImport, vsnprintf, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :va_list>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, vsnprintf_s, c,, <:ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :va_list>
    endif
    @DefProto DllImport, _vsnprintf_s, c,, <:ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :va_list>
    if __STDC_WANT_SECURE_LIB__
      vsprintf_s proto c :ptr SBYTE, :size_t, :ptr SBYTE, :va_list
    endif
    @DefProto DllImport, _vscprintf, c,, <:ptr SBYTE, :va_list>
    @DefProto DllImport, _snprintf_c, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :vararg>
    @DefProto DllImport, _vsnprintf_c, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :va_list>
    @DefProto DllImport, _fprintf_p, c,, <:ptr FILE, :ptr SBYTE, :vararg>
    @DefProto DllImport, _printf_p, c,, <:ptr SBYTE, :vararg>
    @DefProto DllImport, _sprintf_p, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :vararg>
    @DefProto DllImport, _vfprintf_p, c,, <:ptr FILE, :ptr SBYTE, :va_list>
    @DefProto DllImport, _vprintf_p, c,, <:ptr SBYTE, :va_list>
    @DefProto DllImport, _vsprintf_p, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :va_list>
    @DefProto DllImport, _scprintf_p, c,, <:ptr SBYTE, :vararg>
    @DefProto DllImport, _vscprintf_p, c,, <:ptr SBYTE, :va_list>
    @DefProto DllImport, _set_printf_count_output, c,, <:SDWORD>
    @DefProto DllImport, _get_printf_count_output, c,, <>
    @DefProto DllImport, _printf_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _printf_p_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _printf_s_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _vprintf_l, c,, <:ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vprintf_p_l, c,, <:ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vprintf_s_l, c,, <:ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _fprintf_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _fprintf_p_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _fprintf_s_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _vfprintf_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vfprintf_p_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vfprintf_s_l, c,, <:ptr FILE, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _sprintf_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _sprintf_p_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _sprintf_s_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _vsprintf_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vsprintf_p_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vsprintf_s_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _scprintf_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _scprintf_p_l, c,, <:ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _vscprintf_l, c,, <:ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vscprintf_p_l, c,, <:ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _snprintf_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _snprintf_c_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _snprintf_s_l, c,, <:ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :_locale_t, :vararg>
    @DefProto DllImport, _vsnprintf_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vsnprintf_c_l, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :_locale_t, :va_list>
    @DefProto DllImport, _vsnprintf_s_l, c,, <:ptr SBYTE, :size_t, :size_t, :ptr SBYTE, :_locale_t, :va_list>
    ifndef _WSTDIO_DEFINED
      ifndef WEOF
        WEOF equ 0FFFFh
      endif
      ifdef _POSIX_
        ;[...]
      else
        @DefProto DllImport, _wfsopen, c,, <:ptr wchar_t, :ptr wchar_t, :SDWORD>
      endif
      @DefProto DllImport, fgetwc, c,, <:ptr FILE>
      @DefProto DllImport, _fgetwchar, c,, <>
      @DefProto DllImport, fputwc, c,, <:wchar_t, :ptr FILE>
      @DefProto DllImport, _fputwchar, c,, <:wchar_t>
      @DefProto DllImport, getwc, c,, <:ptr FILE>
      @DefProto DllImport, getwchar, c,, <>
      @DefProto DllImport, putwc, c,, <:wchar_t, :ptr FILE>
      @DefProto DllImport, putwchar, c,, <:wchar_t>
      @DefProto DllImport, ungetwc, c,, <:wint_t, :ptr FILE>
      @DefProto DllImport, fgetws, c,, <:ptr wchar_t, :SDWORD, :ptr FILE>
      @DefProto DllImport, fputws, c,, <:ptr wchar_t, :ptr FILE>
      @DefProto DllImport, _getws_s, c,, <:ptr wchar_t, :size_t>
      @DefProto DllImport, _putws, c,, <:ptr wchar_t>
      @DefProto DllImport, fwprintf, c,, <:ptr FILE, :ptr wchar_t, :vararg>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, fwprintf_s, c,, <:ptr FILE, :ptr wchar_t, :vararg>
      endif
      @DefProto DllImport, wprintf, c,, <:ptr wchar_t, :vararg>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, wprintf_s, c,, <:ptr wchar_t, :vararg>
      endif
      @DefProto DllImport, _scwprintf, c,, <:ptr wchar_t, :vararg>
      @DefProto DllImport, vfwprintf, c,, <:ptr FILE, :ptr wchar_t, :va_list>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, vfwprintf_s, c,, <:ptr FILE, :ptr wchar_t, :va_list>
      endif
      @DefProto DllImport, vwprintf, c,, <:ptr wchar_t, :va_list>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, vwprintf_s, c,, <:ptr wchar_t, :va_list>
      endif
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, swprintf_s, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :vararg>
      endif
      if __STDC_WANT_SECURE_LIB__
        vswprintf_s proto c :ptr wchar_t, :size_t, :ptr wchar_t, :va_list
      endif
      @DefProto DllImport, _swprintf_c, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :vararg>
      @DefProto DllImport, _vswprintf_c, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :va_list>
      @DefProto DllImport, _snwprintf_s, c,, <:ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :vararg>
      @DefProto DllImport, _vsnwprintf_s, c,, <:ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :va_list>
      @DefProto DllImport, _fwprintf_p, c,, <:ptr FILE, :ptr wchar_t, :vararg>
      @DefProto DllImport, _wprintf_p, c,, <:ptr wchar_t, :vararg>
      @DefProto DllImport, _vfwprintf_p, c,, <:ptr FILE, :ptr wchar_t, :va_list>
      @DefProto DllImport, _vwprintf_p, c,, <:ptr wchar_t, :va_list>
      @DefProto DllImport, _swprintf_p, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :vararg>
      @DefProto DllImport, _vswprintf_p, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :va_list>
      @DefProto DllImport, _scwprintf_p, c,, <:ptr wchar_t, :vararg>
      @DefProto DllImport, _vscwprintf_p, c,, <:ptr wchar_t, :va_list>
      @DefProto DllImport, _wprintf_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _wprintf_p_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _wprintf_s_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _vwprintf_l, c,, <:ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vwprintf_p_l, c,, <:ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vwprintf_s_l, c,, <:ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _fwprintf_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _fwprintf_p_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _fwprintf_s_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _vfwprintf_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vfwprintf_p_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vfwprintf_s_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _swprintf_c_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _swprintf_p_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _swprintf_s_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _vswprintf_c_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vswprintf_p_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vswprintf_s_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _scwprintf_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _scwprintf_p_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _vscwprintf_p_l, c,, <:ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _snwprintf_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _snwprintf_s_l, c,, <:ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _vsnwprintf_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, _vsnwprintf_s_l, c,, <:ptr wchar_t, :size_t, :size_t, :ptr wchar_t, :_locale_t, :va_list>
      ifndef _CRT_NON_CONFORMING_SWPRINTFS
        _SWPRINTFS_DEPRECATED equ <_CRT_DEPRECATE_TEXT ("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")>
      else
        _SWPRINTFS_DEPRECATED equ <>
      endif
      if  not Defined(RC_INVOKED) and  not Defined(__midl)
        ;include swprintf.inl
      endif
      ifdef _CRT_NON_CONFORMING_SWPRINTFS
        ifndef __cplusplus
          swprintf equ <_swprintf>
          vswprintf equ <_vswprintf>
          _swprintf_l equ <__swprintf_l>
          _vswprintf_l equ <__vswprintf_l>
        endif
      endif
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      @DefProto DllImport, _wtempnam, c,, <:ptr wchar_t, :ptr wchar_t>
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      @DefProto DllImport, _vscwprintf, c,, <:ptr wchar_t, :va_list>
      @DefProto DllImport, _vscwprintf_l, c,, <:ptr wchar_t, :_locale_t, :va_list>
      @DefProto DllImport, fwscanf, c,, <:ptr FILE, :ptr wchar_t, :vararg>
      @DefProto DllImport, _fwscanf_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :vararg>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, fwscanf_s, c,, <:ptr FILE, :ptr wchar_t, :vararg>
      endif
      @DefProto DllImport, _fwscanf_s_l, c,, <:ptr FILE, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, swscanf, c,, <:ptr wchar_t, :ptr wchar_t, :vararg>
      @DefProto DllImport, _swscanf_l, c,, <:ptr wchar_t, :ptr wchar_t, :_locale_t, :vararg>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, swscanf_s, c,, <:ptr wchar_t, :ptr wchar_t, :vararg>
      endif
      @DefProto DllImport, _swscanf_s_l, c,, <:ptr wchar_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _snwscanf, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :vararg>
      @DefProto DllImport, _snwscanf_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _snwscanf_s, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :vararg>
      @DefProto DllImport, _snwscanf_s_l, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, wscanf, c,, <:ptr wchar_t, :vararg>
      @DefProto DllImport, _wscanf_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      if __STDC_WANT_SECURE_LIB__
        @DefProto DllImport, wscanf_s, c,, <:ptr wchar_t, :vararg>
      endif
      @DefProto DllImport, _wscanf_s_l, c,, <:ptr wchar_t, :_locale_t, :vararg>
      @DefProto DllImport, _wfdopen, c,, <:SDWORD, :ptr wchar_t>
      @DefProto DllImport, _wfopen, c,, <:ptr wchar_t, :ptr wchar_t>
      @DefProto DllImport, _wfopen_s, c,, <:ptr ptr FILE, :ptr wchar_t, :ptr wchar_t>
      @DefProto DllImport, _wfreopen, c,, <:ptr wchar_t, :ptr wchar_t, :ptr FILE>
      @DefProto DllImport, _wfreopen_s, c,, <:ptr ptr FILE, :ptr wchar_t, :ptr wchar_t, :ptr FILE>
      ifndef _CRT_WPERROR_DEFINED
        _CRT_WPERROR_DEFINED equ <>
        @DefProto DllImport, _wperror, c,, <:ptr wchar_t>
      endif
      ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
        @DefProto DllImport, _wpopen, c,, <:ptr wchar_t, :ptr wchar_t>
      endif
      @DefProto DllImport, _wremove, c,, <:ptr wchar_t>
      @DefProto DllImport, _wtmpnam_s, c,, <:ptr wchar_t, :size_t>
      @DefProto DllImport, _fgetwc_nolock, c,, <:ptr FILE>
      @DefProto DllImport, _fputwc_nolock, c,, <:wchar_t, :ptr FILE>
      @DefProto DllImport, _ungetwc_nolock, c,, <:wint_t, :ptr FILE>
      if  not Defined(__cplusplus) or Defined(_M_CEE_PURE) or Defined(_CRT_GETPUTWCHAR_NOINLINE)
;        getwchar macro 
;          exitm <fgetwc(stdin)>
;        endm
;        putwchar macro _c
;          exitm <fputwc((_c), stdout)>
;        endm
      else
        ;[...]
      endif
;      getwc macro _stm
;        exitm <fgetwc(_stm)>
;      endm
;      putwc macro _c, _stm
;        exitm <fputwc(_c, _stm)>
;      endm
      _putwc_nolock macro _c, _stm
        exitm <_fputwc_nolock (_c, _stm)>
      endm
      _getwc_nolock macro _stm
        exitm <_fgetwc_nolock (_stm)>
      endm
      if Defined(_CRT_DISABLE_PERFCRIT_LOCKS) and  not Defined(_DLL)
        fgetwc macro _stm
          exitm <_getwc_nolock(_stm)>
        endm
        fputwc macro _c, _stm
          exitm <_putwc_nolock(_c, _stm)>
        endm
        ungetwc macro _c, _stm
          exitm <_ungetwc_nolock (_c, _stm)>
        endm
      endif
      _WSTDIO_DEFINED equ <>
    endif
    _STDIO_DEFINED equ <>
  endif
  if Defined(_CRT_DISABLE_PERFCRIT_LOCKS) and  not Defined(_DLL)
    feof macro _stream
      exitm <((_stream) - _flag and _IOEOF)>
    endm
    ferror macro _stream
      exitm <((_stream) - _flag and _IOERR)>
    endm
    _fileno macro _stream
      exitm <((_stream) - _file)>
    endm
    fgetc macro _stream
      exitm <(- (_stream) - _cnt >= 0 ? 0ffh and * (_stream) - _ptr + : _filbuf (_stream))>
    endm
    putc macro _c, _stream
      exitm <(- (_stream) - _cnt >= 0 ? 0ffh and (* (_stream) - _ptr + = (_c)) : _flsbuf ((_c), (_stream)))>
    endm
    getc macro _stream
      exitm <fgetc(_stream)>
    endm
    getchar macro 
      exitm <getc(stdin)>
    endm
    putchar macro _c
      exitm <putc((_c), stdout)>
    endm
  endif
  _fgetc_nolock macro _stream
    exitm <(- (_stream) - _cnt >= 0 ? 0ffh and * (_stream) - _ptr + : _filbuf (_stream))>
  endm
  _fputc_nolock macro _c, _stream
    exitm <(- (_stream) - _cnt >= 0 ? 0ffh and (* (_stream) - _ptr + = (_c)) : _flsbuf ((_c), (_stream)))>
  endm
  _getc_nolock macro _stream
    exitm <_fgetc_nolock(_stream)>
  endm
  _putc_nolock macro _c, _stream
    exitm <_fputc_nolock(_c, _stream)>
  endm
  _getchar_nolock macro 
    exitm <_getc_nolock(stdin)>
  endm
  _putchar_nolock macro _c
    exitm <_putc_nolock((_c), stdout)>
  endm
  _getwchar_nolock macro 
    exitm <_getwc_nolock(stdin)>
  endm
  _putwchar_nolock macro _c
    exitm <_putwc_nolock((_c), stdout)>
  endm
  @DefProto DllImport, _lock_file, c,, <:ptr FILE>
  @DefProto DllImport, _unlock_file, c,, <:ptr FILE>
  @DefProto DllImport, _fclose_nolock, c,, <:ptr FILE>
  @DefProto DllImport, _fflush_nolock, c,, <:ptr FILE>
  @DefProto DllImport, _fread_nolock, c,, <:ptr, :size_t, :size_t, :ptr FILE>
  @DefProto DllImport, _fread_nolock_s, c,, <:ptr, :size_t, :size_t, :size_t, :ptr FILE>
  @DefProto DllImport, _fseek_nolock, c,, <:ptr FILE, :SDWORD, :SDWORD>
  @DefProto DllImport, _ftell_nolock, c,, <:ptr FILE>
  @DefProto DllImport, _fseeki64_nolock, c,, <:ptr FILE, :SQWORD, :SDWORD>
  @DefProto DllImport, _ftelli64_nolock, c,, <:ptr FILE>
  @DefProto DllImport, _fwrite_nolock, c,, <:ptr, :size_t, :size_t, :ptr FILE>
  @DefProto DllImport, _ungetc_nolock, c,, <:SDWORD, :ptr FILE>
  if Defined(_CRT_DISABLE_PERFCRIT_LOCKS) and  not Defined(_DLL)
    fclose macro _stm
      exitm <_fclose_nolock (_stm)>
    endm
    fflush macro _stm
      exitm <_fflush_nolock (_stm)>
    endm
    fread macro _DstBuf, _ElementSize, _Count, _File
      exitm <_fread_nolock (_DstBuf, _ElementSize, _Count, _File)>
    endm
    fread_s macro _DstBuf, _DstSize, _ElementSize, _Count, _File
      exitm <_fread_nolock_s (_DstBuf, _DstSize, _ElementSize, _Count, _File)>
    endm
    fseek macro _stm, _offset, _origin
      exitm <_fseek_nolock (_stm, _offset, _origin)>
    endm
    ftell macro _stm
      exitm <_ftell_nolock (_stm)>
    endm
    _fseeki64 macro _stm, _offset, _origin
      exitm <_fseeki64_nolock (_stm, _offset, _origin)>
    endm
    _ftelli64 macro _stm
      exitm <_ftelli64_nolock (_stm)>
    endm
    fwrite macro _buf, _siz, _cnt, _stm
      exitm <_fwrite_nolock (_buf, _siz, _cnt, _stm)>
    endm
    ungetc macro _c, _stm
      exitm <_ungetc_nolock (_c, _stm)>
    endm
  endif
  if  not __STDC__ and  not Defined(_POSIX_)
    P_tmpdir equ <_P_tmpdir>
    SYS_OPEN equ <_SYS_OPEN>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, tempnam, c,, <:ptr SBYTE, :ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, fcloseall, c,, <>
    @DefProto DllImport, fdopen, c,, <:SDWORD, :ptr SBYTE>
    @DefProto DllImport, fgetchar, c,, <>
    @DefProto DllImport, fileno, c,, <:ptr FILE>
    @DefProto DllImport, flushall, c,, <>
    @DefProto DllImport, fputchar, c,, <:SDWORD>
    @DefProto DllImport, getw, c,, <:ptr FILE>
    @DefProto DllImport, putw, c,, <:SDWORD, :ptr FILE>
    @DefProto DllImport, rmtmp, c,, <>
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

