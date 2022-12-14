;Include file created by h2incX, Version C.01.00, 21/05/2019 11:44
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\PathCch.h', last modified: 22/10/2018 21:35
;Creation parameters: 

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
  
  DEFINE_ENUM_FLAG_OPERATORS(PATHCCH_OPTIONS)
  VOLUME_PREFIX equ <L("\\?\Volume")>
  VOLUME_PREFIX_LEN equ (ARRAYSIZE(VOLUME_PREFIX) - 1)
  PATHCCH_MAX_CCH equ 8000h
  @DefProto DllImport, PathIsUNCEx, WIN_STD_CALL_CONV,,  <:PCWSTR, :ptr PCWSTR>, 8
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
 