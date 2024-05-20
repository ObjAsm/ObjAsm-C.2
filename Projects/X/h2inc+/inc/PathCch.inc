;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\pathcch.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:46

;********************************************************************************
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
  ; This option allows applications to gain access to long paths. It has two
  ; different behaviors. For process configured to enable long paths it will allow
  ; the returned path to be longer than the max path limit that is normally imposed.
  ; For process that are not this option will convert long paths into the extended
  ; length DOS device form (with \\?\ prefix) when the path is longer than the limit.
  ; This form is not length limited by the Win32 file system API on all versions of Windows.
  ; This second behavior is the same behavior for OSes that don't have the long path feature.
  ; This can not be specified with PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH.
  PATHCCH_ALLOW_LONG_PATHS equ 01h
  ; Can only be used when PATHCCH_ALLOW_LONG_PATHS is specified. This
  ; Forces the API to treat the caller as long path enabled, independent of the
  ; process's long name enabled state. Cannot be used with PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS.
  PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS equ 02h
  ; Can only be used when PATHCCH_ALLOW_LONG_PATHS is specified. This
  ; Forces the API to treat the caller as long path disabled, independent of the
  ; process's long name enabled state. Cannot be used with PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS.
  PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS equ 04h
  ; Disable the normalization of path segments that includes removing trailing dots and spaces.
  ; This enables access to paths that win32 path normalization will block.
  PATHCCH_DO_NOT_NORMALIZE_SEGMENTS equ 08h
  ; Convert the input path into the extended length DOS device path form (with the \\?\ prefix)
  ; if not already in that form. This enables access to paths that are otherwise not addressable
  ; due to Win32 normalization rules (that can strip trailing dots and spaces) and path
  ; length limitations. This option implies the same behavior of PATHCCH_DO_NOT_NORMALIZE_SEGMENTS.
  ; This can not be specified with PATHCCH_ALLOW_LONG_PATHS.
  PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH equ 10h
  ; When combining or normalizing a path ensure there is a trailing backslash.
  PATHCCH_ENSURE_TRAILING_SLASH equ 020h
  ; Convert forward slashes to back slashes and collapse multiple slashes.
  ; This is needed to to support sub-path or identity comparisons.
  PATHCCH_CANONICALIZE_SLASHES equ 040h

  DEFINE_ENUM_FLAG_OPERATORS(PATHCCH_OPTIONS)
  VOLUME_PREFIX equ <L("\\?\Volume")>
  VOLUME_PREFIX_LEN equ (ARRAYSIZE(VOLUME_PREFIX) - 1)
  ; max # of characters we support using the "\\?\" syntax
  ; (0x7FFF + 1 for NULL terminator)
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
  ;* PATHCCH_OPTIONS *
  @DefProto DllImport, PathCchCanonicalizeEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :ULONG>, 16
  @DefProto DllImport, PathCchCanonicalize, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR>, 12
  ;* PATHCCH_OPTIONS *
  @DefProto DllImport, PathCchCombineEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :PCWSTR, :ULONG>, 20
  @DefProto DllImport, PathCchCombine, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :PCWSTR>, 16
  ;* PATHCCH_OPTIONS *
  @DefProto DllImport, PathCchAppendEx, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR, :ULONG>, 16
  @DefProto DllImport, PathCchAppend, WIN_STD_CALL_CONV,, <:PWSTR, :size_t, :PCWSTR>, 12
  @DefProto DllImport, PathCchStripPrefix, WIN_STD_CALL_CONV,, <:PWSTR, :size_t>, 8
  ;* PATHCCH_OPTIONS *
  @DefProto DllImport, PathAllocCombine, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :ULONG, :ptr PWSTR>, 16
  ;* PATHCCH_OPTIONS *
  @DefProto DllImport, PathAllocCanonicalize, WIN_STD_CALL_CONV,, <:PCWSTR, :ULONG, :ptr PWSTR>, 12
  ifndef PATHCCH_NO_DEPRECATE
    ; Deprecate the old path functions that do not take a buffer size (and assume MAX_PATH) to generate compile time errors.
    ; #define PATHCCH_NO_DEPRECATE before including this file to disable these deprecations.
    ifdef DEPRECATE_SUPPORTED
    endif
    ; !DEPRECATE_SUPPORTED
  endif
  ; !PATHCCH_NO_DEPRECATE
endif
; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
ifdef __cplusplus
  ;[...]
endif
ifdef __cplusplus
  ;[...]
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
endif
