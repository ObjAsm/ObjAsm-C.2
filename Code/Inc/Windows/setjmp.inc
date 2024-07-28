;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\setjmp.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_SETJMP
  _INC_SETJMP equ <>
  include crtdefs.inc
  if Defined(_M_CEE)
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(_M_IX86)
    ifndef _INC_SETJMPEX
      setjmp equ <_setjmp>
    endif
    _JBLEN equ 16
    _JBTYPE equ <int>
    _JUMP_BUFFER struct
      Ebp_ DWORD ?
      Ebx_ DWORD ?
      Edi_ DWORD ?
      Esi_ DWORD ?
      Esp_ DWORD ?
      Eip_ DWORD ?
      Registration DWORD ?
      TryLevel DWORD ?
      Cookie DWORD ?
      UnwindFunc DWORD ?
      UnwindData DWORD 6 dup (?)
    _JUMP_BUFFER ends

    __JUMP_BUFFER typedef _JUMP_BUFFER
  elseif Defined(_M_X64)
    SETJMP_FLOAT128 struct 16
      Part QWORD 2 dup (?)
    SETJMP_FLOAT128 ends

    _SETJMP_FLOAT128 typedef SETJMP_FLOAT128
    _JBLEN equ 16
    _JBTYPE typedef SETJMP_FLOAT128
    ifndef _INC_SETJMPEX
      setjmp equ <_setjmp>
    endif
    _JUMP_BUFFER struct
      Frame_ QWORD ?
      Rbx_ QWORD ?
      Rsp_ QWORD ?
      Rbp_ QWORD ?
      Rsi_ QWORD ?
      Rdi_ QWORD ?
      R12_ QWORD ?
      R13_ QWORD ?
      R14_ QWORD ?
      R15_ QWORD ?
      Rip_ QWORD ?
      MxCsr DWORD ?
      FpCsr WORD ?
      Spare WORD ?
      Xmm6_ SETJMP_FLOAT128 <>
      Xmm7_ SETJMP_FLOAT128 <>
      Xmm8_ SETJMP_FLOAT128 <>
      Xmm9_ SETJMP_FLOAT128 <>
      Xmm10_ SETJMP_FLOAT128 <>
      Xmm11_ SETJMP_FLOAT128 <>
      Xmm12_ SETJMP_FLOAT128 <>
      Xmm13_ SETJMP_FLOAT128 <>
      Xmm14_ SETJMP_FLOAT128 <>
      Xmm15_ SETJMP_FLOAT128 <>
    _JUMP_BUFFER ends

  elseif Defined(_M_ARM)
    ;[...]
  endif
  ifndef _JMP_BUF_DEFINED
    jmp_buf struct
      _JBTYPE _JBLEN dup (<>)
    jmp_buf ends
    _JMP_BUF_DEFINED equ <>
  endif
  setjmp proto c :jmp_buf
  ifdef __cplusplus
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  else
    @DefProto DllImport, longjmp, c,, <:jmp_buf, :SDWORD>
  endif
endif

