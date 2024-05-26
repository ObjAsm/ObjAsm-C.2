;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\pathcch.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:46

include apiset.inc
include apisetcconv.inc
include minwindef.inc
include minwinbase.inc
ifdef __cplusplus
  ;[...]
endif
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
  PATHCCH_OPTIONS typedef SDWORD
  PATHCCH_NONE equ 0h
  PATHCCH_ALLOW_LONG_PATHS equ 01h
  PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS equ 02h
  PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS equ 04h
  PATHCCH_DO_NOT_NORMALIZE_SEGMENTS equ 08h
  PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH equ 10h
  PATHCCH_ENSURE_TRAILING_SLASH equ 020h
  PATHCCH_CANONICALIZE_SLASHES equ 040h

  DEFINE_ENUM_FLAG_OPERATORS(PATHCCH_OPTIONS)
  VOLUME_PREFIX equ <L("\\?\Volume")>
  VOLUME_PREFIX_LEN equ (ARRAYSIZE(VOLUME_PREFIX) - 1)
  PATHCCH_MAX_CCH equ 8000h
  @DefProto DllImport, PathIsUNCEx, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PCWSTR>, 8
  @DefProto DllImport, PathCchIsRoot, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
  @DefProto DllImport, PathCchAddBackslashEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :ptr PWSTR, :ptr size_t>, 16
  @DefProto DllImport, PathCchAddBackslash, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  @DefProto DllImport, PathCchRemoveBackslashEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :ptr PWSTR, :ptr size_t>, 16
  @DefProto DllImport, PathCchRemoveBackslash, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  @DefProto DllImport, PathCchSkipRoot, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PCWSTR>, 8
  @DefProto DllImport, PathCchStripToRoot, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  @DefProto DllImport, PathCchRemoveFileSpec, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  @DefProto DllImport, PathCchFindExtension, WIN_STD_CALL_CONV,, <:PCWSTR, :size_t, :ptr PCWSTR>, 12
  @DefProto DllImport, PathCchAddExtension, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR>, 12
  @DefProto DllImport, PathCchRenameExtension, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR>, 12
  @DefProto DllImport, PathCchRemoveExtension, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  @DefProto DllImport, PathCchCanonicalizeEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :ULONG>, 16
  @DefProto DllImport, PathCchCanonicalize, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR>, 12
  @DefProto DllImport, PathCchCombineEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :PCWSTR, :ULONG>, 20
  @DefProto DllImport, PathCchCombine, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :PCWSTR>, 16
  @DefProto DllImport, PathCchAppendEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :ULONG>, 16
  @DefProto DllImport, PathCchAppend, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR>, 12
  @DefProto DllImport, PathCchStripPrefix, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  @DefProto DllImport, PathAllocCombine, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :ULONG, :ptr PWSTR>, 16
  @DefProto DllImport, PathAllocCanonicalize, WIN_STD_CALL_CONV,, <:PCWSTR, :ULONG, :ptr PWSTR>, 12
  ifndef PATHCCH_NO_DEPRECATE
    ifdef DEPRECATE_SUPPORTED
    endif
  endif
endif
ifdef __cplusplus
  ;[...]
endif
ifdef __cplusplus
  ;[...]
endif
