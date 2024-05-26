;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\stralign.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 16/12/2023 11:06:58

include winapifamily.inc
if  not Defined(__STRALIGN_H_) and  not Defined(MIDL_PASS)
  __STRALIGN_H_ equ <>
  ifndef _STRALIGN_USE_SECURE_CRT
    if Defined(__GOT_SECURE_LIB__) and __GOT_SECURE_LIB__ ge 200402
      _STRALIGN_USE_SECURE_CRT equ 1
    else
      _STRALIGN_USE_SECURE_CRT equ 0
    endif
  endif
  if  not Defined(_WINDOWS_INSECURE_DEPRECATE)
    if Defined(_WINDOWS_SECURE_NO_DEPRECATE) or  not _STRALIGN_USE_SECURE_CRT
      _WINDOWS_INSECURE_DEPRECATE equ <>
    else
      _WINDOWS_INSECURE_DEPRECATE equ <__declspec(deprecated)>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if Defined(_AMD64_) or Defined(_ARM_) or Defined(_ARM64_)
    endif
    if Defined(_X86_)
      WSTR_ALIGNED macro s
        exitm <TRUE>
      endm
      ua_CharUpperW equ <CharUpperW>
      ua_lstrcmpiW equ <lstrcmpiW>
      ua_lstrcmpW equ <lstrcmpW>
      ua_lstrlenW equ <lstrlenW>
      ua_wcschr equ <wcschr>
      ua_wcsicmp equ <wcsicmp>
      ua_wcslen equ <wcslen>
      ua_wcsrchr equ <wcsrchr>
      if _STRALIGN_USE_SECURE_CRT
        ua_wcscpy_s equ <wcscpy_s>
      endif
      ua_wcscpy proto WIN_STD_CALL_CONV :PUWSTR, :PCUWSTR
      ifdef _PREFAST_
        ;[...]
      endif
    else
      if Defined(_AMD64_) or Defined(_ARM_) or Defined(_ARM64_)
        WSTR_ALIGNED macro s
          exitm <TRUE>
        endm
      else
        WSTR_ALIGNED macro s
          exitm <(((s) and (sizeof(WCHAR) - 1)) == 0)>
        endm
      endif
      uaw_CharUpperW proto WIN_STD_CALL_CONV :LPUWSTR
      uaw_lstrcmpW proto WIN_STD_CALL_CONV :PCUWSTR, :PCUWSTR
      uaw_lstrcmpiW proto WIN_STD_CALL_CONV :PCUWSTR, :PCUWSTR
      uaw_lstrlenW proto WIN_STD_CALL_CONV :LPCUWSTR
      uaw_wcschr proto c :PCUWSTR, :WCHAR
      uaw_wcscpy proto c :PUWSTR, :PCUWSTR
      uaw_wcsicmp proto c :PCUWSTR, :PCUWSTR
      uaw_wcslen proto c :PCUWSTR
      uaw_wcsrchr proto c :PCUWSTR, :WCHAR
      if Defined(CharUpper)
        ua_CharUpperW proto WIN_STD_CALL_CONV :LPUWSTR
      endif
      if Defined(lstrcmp)
        ua_lstrcmpW proto WIN_STD_CALL_CONV :LPCUWSTR, :LPCUWSTR
      endif
      if Defined(lstrcmpi)
        ua_lstrcmpiW proto WIN_STD_CALL_CONV :LPCUWSTR, :LPCUWSTR
      endif
      if Defined(lstrlen)
        ua_lstrlenW proto WIN_STD_CALL_CONV :LPCUWSTR
      endif
      if Defined(_INC_STRING) or Defined(_INC_WCHAR)
        if Defined(_WConst_return)
          PUWSTR_C typedef ptr _WConst_return
        else
          PUWSTR_C typedef ptr WCHAR
        endif
        ua_wcschr proto WIN_STD_CALL_CONV :PCUWSTR, :WCHAR
        ua_wcsrchr proto WIN_STD_CALL_CONV :PCUWSTR, :WCHAR
        if Defined(__cplusplus) and Defined(_WConst_Return)
          ;[...]
        endif
        ua_wcscpy proto WIN_STD_CALL_CONV :PUWSTR, :PCUWSTR
        ifdef _PREFAST_
          ;[...]
        endif
        if _STRALIGN_USE_SECURE_CRT
          ua_wcscpy_s proto WIN_STD_CALL_CONV :PUWSTR, :size_t, :PCUWSTR
        endif
        ua_wcslen proto WIN_STD_CALL_CONV :PCUWSTR
      endif
      ua_wcsicmp proto WIN_STD_CALL_CONV :PCUWSTR, :PCUWSTR
    endif
    if  not Defined(__UA_WCSLEN)
      __UA_WCSLEN equ <ua_wcslen>
    endif
    __UA_WSTRSIZE macro s
      exitm <((__UA_WCSLEN (s) + 1) * sizeof(WCHAR))>
    endm
    __UA_STACKCOPY macro p, s
      exitm <memcpy_s (_alloca (s), s, p, s)>
    endm
    if Defined(_AMD64_) or Defined(_ARM_) or Defined(_ARM64_) or Defined(_X86_)
      WSTR_ALIGNED_STACK_COPY macro d, s
        exitm <(* (d) = (PCWSTR) (s))>
      endm
    else
      WSTR_ALIGNED_STACK_COPY macro d, s
        exitm <{ PCUWSTR __ua_src ; size_t __ua_size ; PWSTR __ua_dst ; __ua_src = (s) ; if (WSTR_ALIGNED(__ua_src)) { __ua_dst = (PWSTR) __ua_src ; } else { __ua_size = __UA_WSTRSIZE(__ua_src) ; __ua_dst = (PWSTR) _alloca (__ua_size) ; memcpy_s (__ua_dst, __ua_size, __ua_src, __ua_size) ; } * (d) = (PCWSTR) __ua_dst ; }>
      endm
    endif
    ASTR_ALIGNED_STACK_COPY macro d, s
      exitm <(* (d) = (PCSTR) (s))>
    endm
    if  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_X86_)
      __UA_STRUC_ALIGNED macro t, s
        exitm <(((s) and (TYPE_ALIGNMENT(t) - 1)) == 0)>
      endm
      STRUC_ALIGNED_STACK_COPY macro t, s
        exitm <__UA_STRUC_ALIGNED(t, s) ? ((t const *) (s)) : ((t const *) __UA_STACKCOPY((s), sizeof(t)))>
      endm
    else
      STRUC_ALIGNED_STACK_COPY macro t, s
        exitm <((CONST t *) (s))>
      endm
    endif
    if Defined(UNICODE)
      TSTR_ALIGNED_STACK_COPY macro d, s
        exitm <WSTR_ALIGNED_STACK_COPY(d, s)>
      endm
      TSTR_ALIGNED macro x
        exitm <WSTR_ALIGNED(x)>
      endm
      ua_CharUpper equ <ua_CharUpperW>
      ua_lstrcmp equ <ua_lstrcmpW>
      ua_lstrcmpi equ <ua_lstrcmpiW>
      ua_lstrlen equ <ua_lstrlenW>
      ua_tcscpy equ <ua_wcscpy>
      if _STRALIGN_USE_SECURE_CRT
        ua_tcscpy_s equ <ua_wcscpy_s>
      endif
    else
      TSTR_ALIGNED_STACK_COPY macro d, s
        exitm <ASTR_ALIGNED_STACK_COPY(d, s)>
      endm
      TSTR_ALIGNED macro x
        exitm <TRUE>
      endm
      ua_CharUpper equ <CharUpperA>
      ua_lstrcmp equ <lstrcmpA>
      ua_lstrcmpi equ <lstrcmpiA>
      ua_lstrlen equ <lstrlenA>
      ua_tcscpy equ <strcpy>
      if _STRALIGN_USE_SECURE_CRT
        ua_tcscpy_s equ <strcpy_s>
      endif
    endif
    if Defined(_AMD64_) or Defined(_ARM_) or Defined(_ARM64_)
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
