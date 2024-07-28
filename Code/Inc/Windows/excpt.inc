;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\excpt.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_EXCPT
  _INC_EXCPT equ <>
  include crtdefs.inc
  ifdef __cplusplus
    ;[...]
  endif
  EXCEPTION_DISPOSITION typedef SDWORD
  ExceptionContinueExecution equ 0
  ExceptionContinueSearch equ 1
  ExceptionNestedException equ 2
  ExceptionCollidedUnwind equ 3
  _EXCEPTION_DISPOSITION typedef EXCEPTION_DISPOSITION
  
  ifdef _M_IX86
    _except_handler proto c :ptr _EXCEPTION_RECORD, :ptr, :ptr _CONTEXT, :ptr
  elseif Defined(_M_X64) or Defined(_M_ARM)
    ifndef _M_CEE_PURE
      @DefProto DllImport, __C_specific_handler, WIN_STD_CALL_CONV,, <:ptr _EXCEPTION_RECORD, :ptr, :ptr _CONTEXT, :ptr _DISPATCHER_CONTEXT>, 16
    endif
  endif
  GetExceptionCode equ <_exception_code>
  exception_code equ <_exception_code>
  GetExceptionInformation equ <(struct _EXCEPTION_POINTERS *) _exception_info>
  exception_info equ <(struct _EXCEPTION_POINTERS *) _exception_info>
  AbnormalTermination equ <_abnormal_termination>
  abnormal_termination equ <_abnormal_termination>
  _exception_code proto c
  _exception_info proto c
  _abnormal_termination proto c
  EXCEPTION_EXECUTE_HANDLER equ 1
  EXCEPTION_CONTINUE_SEARCH equ 0
  EXCEPTION_CONTINUE_EXECUTION equ -1
  ifdef __cplusplus
    ;[...]
  endif
endif

