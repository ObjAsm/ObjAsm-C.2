;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ctype.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_CTYPE
  _INC_CTYPE equ <>
  include crtdefs.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef WEOF
    WEOF equ 0FFFFh
  endif
  ifndef _CRT_CTYPEDATA_DEFINED
    _CRT_CTYPEDATA_DEFINED equ <>
    ifndef _CTYPE_DISABLE_MACROS
      ;[...]
    endif
  endif
  ifndef _CRT_WCTYPEDATA_DEFINED
    _CRT_WCTYPEDATA_DEFINED equ <>
    ifndef _CTYPE_DISABLE_MACROS
      ;[...]
    endif
  endif
  ifndef _CTYPE_DISABLE_MACROS
    ;[...]
  endif
  _UPPER equ 1h
  _LOWER equ 2h
  _DIGIT equ 4h
  _SPACE equ 8h
  _PUNCT equ 10h
  _CONTROL equ 20h
  _BLANK equ 40h
  _HEX equ 80h
  _LEADBYTE equ 8000h
  _ALPHA equ (0100h or _UPPER or _LOWER)
  ifndef _CTYPE_DEFINED
    @DefProto DllImport, _isctype, c,, <:SDWORD, :SDWORD>
    @DefProto DllImport, _isctype_l, c,, <:SDWORD, :SDWORD, :_locale_t>
    @DefProto DllImport, isalpha, c,, <:SDWORD>
    @DefProto DllImport, _isalpha_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isupper, c,, <:SDWORD>
    @DefProto DllImport, _isupper_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, islower, c,, <:SDWORD>
    @DefProto DllImport, _islower_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isdigit, c,, <:SDWORD>
    @DefProto DllImport, _isdigit_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isxdigit, c,, <:SDWORD>
    @DefProto DllImport, _isxdigit_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isspace, c,, <:SDWORD>
    @DefProto DllImport, _isspace_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, ispunct, c,, <:SDWORD>
    @DefProto DllImport, _ispunct_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isalnum, c,, <:SDWORD>
    @DefProto DllImport, _isalnum_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isprint, c,, <:SDWORD>
    @DefProto DllImport, _isprint_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, isgraph, c,, <:SDWORD>
    @DefProto DllImport, _isgraph_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, iscntrl, c,, <:SDWORD>
    @DefProto DllImport, _iscntrl_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, toupper, c,, <:SDWORD>
    @DefProto DllImport, tolower, c,, <:SDWORD>
    @DefProto DllImport, _tolower, c,, <:SDWORD>
    @DefProto DllImport, _tolower_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, _toupper, c,, <:SDWORD>
    @DefProto DllImport, _toupper_l, c,, <:SDWORD, :_locale_t>
    @DefProto DllImport, __isascii, c,, <:SDWORD>
    @DefProto DllImport, __toascii, c,, <:SDWORD>
    @DefProto DllImport, __iscsymf, c,, <:SDWORD>
    @DefProto DllImport, __iscsym, c,, <:SDWORD>
    _CTYPE_DEFINED equ <>
  endif
  ifndef _WCTYPE_DEFINED
    @DefProto DllImport, iswalpha, c,, <:wint_t>
    @DefProto DllImport, _iswalpha_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswupper, c,, <:wint_t>
    @DefProto DllImport, _iswupper_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswlower, c,, <:wint_t>
    @DefProto DllImport, _iswlower_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswdigit, c,, <:wint_t>
    @DefProto DllImport, _iswdigit_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswxdigit, c,, <:wint_t>
    @DefProto DllImport, _iswxdigit_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswspace, c,, <:wint_t>
    @DefProto DllImport, _iswspace_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswpunct, c,, <:wint_t>
    @DefProto DllImport, _iswpunct_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswalnum, c,, <:wint_t>
    @DefProto DllImport, _iswalnum_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswprint, c,, <:wint_t>
    @DefProto DllImport, _iswprint_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswgraph, c,, <:wint_t>
    @DefProto DllImport, _iswgraph_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswcntrl, c,, <:wint_t>
    @DefProto DllImport, _iswcntrl_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswascii, c,, <:wint_t>
    @DefProto DllImport, towupper, c,, <:wint_t>
    @DefProto DllImport, _towupper_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, towlower, c,, <:wint_t>
    @DefProto DllImport, _towlower_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, iswctype, c,, <:wint_t, :wctype_t>
    @DefProto DllImport, _iswctype_l, c,, <:wint_t, :wctype_t, :_locale_t>
    @DefProto DllImport, __iswcsymf, c,, <:wint_t>
    @DefProto DllImport, _iswcsymf_l, c,, <:wint_t, :_locale_t>
    @DefProto DllImport, __iswcsym, c,, <:wint_t>
    @DefProto DllImport, _iswcsym_l, c,, <:wint_t, :_locale_t>
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      @DefProto DllImport, isleadbyte, c,, <:SDWORD>
      @DefProto DllImport, _isleadbyte_l, c,, <:SDWORD, :_locale_t>
      @DefProto DllImport, is_wctype, c,, <:wint_t, :wctype_t>
    endif
    _WCTYPE_DEFINED equ <>
  endif
  ifndef _CTYPE_DISABLE_MACROS
    ;[...]
endif
if  not __STDC__
  ifndef _CTYPE_DEFINED
    @DefProto DllImport, isascii, c,, <:SDWORD>
    @DefProto DllImport, toascii, c,, <:SDWORD>
    @DefProto DllImport, iscsymf, c,, <:SDWORD>
    @DefProto DllImport, iscsym, c,, <:SDWORD>
  else
    isascii equ <__isascii>
    toascii equ <__toascii>
    iscsymf equ <__iscsymf>
    iscsym equ <__iscsym>
  endif
endif
ifdef __cplusplus
  ;[...]
endif
endif

