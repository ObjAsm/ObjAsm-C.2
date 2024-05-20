;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\heapapi.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:16

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _HEAPAPI_H_
  _HEAPAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  if _MSC_VER lt 1900
    DECLSPEC_ALLOCATOR equ <>
  else
    DECLSPEC_ALLOCATOR equ <__declspec(allocator)>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
    ; padding added after data member
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; typdefs
    HEAP_SUMMARY struct
      cb DWORD ?
      cbAllocated XWORD ?
      cbCommitted XWORD ?
      cbReserved XWORD ?
      cbMaxReserve XWORD ?
    HEAP_SUMMARY ends
    _HEAP_SUMMARY typedef HEAP_SUMMARY
    PHEAP_SUMMARY typedef ptr HEAP_SUMMARY
    LPHEAP_SUMMARY typedef PHEAP_SUMMARY
    ; Prototypes
    @DefProto DllImport, HeapCreate, WIN_STD_CALL_CONV,, <:DWORD, :SIZE_T, :SIZE_T>, 12
    @DefProto DllImport, HeapDestroy, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, HeapAlloc, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :SIZE_T>, 12
    @DefProto DllImport, HeapReAlloc, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPVOID, :SIZE_T>, 16
    @DefProto DllImport, HeapFree, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPVOID>, 12
    @DefProto DllImport, HeapSize, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPCVOID>, 12
    @DefProto DllImport, GetProcessHeap, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, HeapCompact, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, HeapSetInformation, WIN_STD_CALL_CONV,, <:HANDLE, :HEAP_INFORMATION_CLASS, :PVOID, :SIZE_T>, 16
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, HeapValidate, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPCVOID>, 12
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    HeapSummary proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPHEAP_SUMMARY
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetProcessHeaps, WIN_STD_CALL_CONV,, <:DWORD, :PHANDLE>, 8
    @DefProto DllImport, HeapLock, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, HeapUnlock, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, HeapWalk, WIN_STD_CALL_CONV,, <:HANDLE, :LPPROCESS_HEAP_ENTRY>, 8
    @DefProto DllImport, HeapQueryInformation, WIN_STD_CALL_CONV,, <:HANDLE, :HEAP_INFORMATION_CLASS, :PVOID, :SIZE_T, :PSIZE_T>, 20
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  ; HeapSummary() is in minwinbase.w within ;beg_internal tags. Has to stay there for downlevel reasons.
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _HEAPAPI_H_
