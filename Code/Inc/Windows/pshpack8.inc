;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\pshpack8.h', last modified: 19/04/2018 10:43
;Creation parameters: 

if  not (Defined(lint) or Defined(RC_INVOKED))
  if (_MSC_VER ge 800 and  not Defined(_M_I86)) or Defined(_PUSHPOP_SUPPORTED)
    if  not (Defined(MIDL_PASS)) or Defined(__midl)
    else
      ;[...]
    endif
  else
  endif
endif

