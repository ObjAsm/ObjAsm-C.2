;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\heapapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
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
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    HEAP_SUMMARY struct
      cb DWORD ?
      cbAllocated SIZE_T ?
      cbCommitted SIZE_T ?
      cbReserved SIZE_T ?
      cbMaxReserve SIZE_T ?
    HEAP_SUMMARY ends

    _HEAP_SUMMARY typedef HEAP_SUMMARY
    PHEAP_SUMMARY typedef ptr HEAP_SUMMARY
    
    LPHEAP_SUMMARY typedef PHEAP_SUMMARY
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, HeapValidate, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPCVOID>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    HeapSummary proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPHEAP_SUMMARY
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetProcessHeaps, WIN_STD_CALL_CONV,, <:DWORD, :PHANDLE>, 8
    @DefProto DllImport, HeapLock, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, HeapUnlock, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, HeapWalk, WIN_STD_CALL_CONV,, <:HANDLE, :LPPROCESS_HEAP_ENTRY>, 8
    @DefProto DllImport, HeapQueryInformation, WIN_STD_CALL_CONV,, <:HANDLE, :HEAP_INFORMATION_CLASS, :PVOID, :SIZE_T, :PSIZE_T>, 20
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

