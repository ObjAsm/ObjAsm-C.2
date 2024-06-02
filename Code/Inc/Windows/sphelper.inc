;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sphelper.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 12/02/2024 17:05:48

ifndef SPHelper_h
  SPHelper_h equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _INC_MALLOC
      include malloc.inc
    endif
    ifndef __sapi_h__
      include sapi.inc
    endif
    ifndef __sapiddk_h__
      include sapiddk.inc
    endif
    ifndef SPError_h
      include SPError.inc
    endif
    ifndef _INC_LIMITS
      include limits.inc
    endif
    ifndef _INC_MMSYSTEM
      include mmsystem.inc
    endif
    ifndef __comcat_h__
      include comcat.inc
    endif
    ifndef _INC_MMREG
      include mmreg.inc
    endif
    ifndef __ATLBASE_H__
      include atlbase.inc
    endif
    include wchar.inc
    include tchar.inc
    include strsafe.inc
    include intsafe.inc
    ifndef _PREFAST_
    endif
    ifndef REG_MUI_STRING_TRUNCATE
      REG_MUI_STRING_TRUNCATE equ 00000001h
    endif
    sp_countof macro x
      exitm <((sizeof(x) / sizeof(* (x))))>
    endm
    if Defined(_WIN32_WCE) and (_WIN32_WCE lt 600h)
    else
    endif
    if _SAPI_VER ge 053h
    endif
    if _SAPI_VER ge 053h
    else
    endif
    if _SAPI_VER ge 053h
    endif
    if _SAPI_VER ge 053h
    endif
    ifdef SP_SPPHRASESIZE_500
    else
    endif
  endif
endif
