;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\pshpack1.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 16/12/2023 11:01:36

if  not (Defined(lint) or Defined(RC_INVOKED))
  if (_MSC_VER ge 800 and  not Defined(_M_I86)) or Defined(_PUSHPOP_SUPPORTED)
    if  not (Defined(MIDL_PASS)) or Defined(__midl)
    else
      ;[...]
    endif
  else
  endif
endif
