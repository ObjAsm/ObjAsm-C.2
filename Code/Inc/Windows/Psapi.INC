;--- include file created by h2incx v0.99.21 (copyright 2005-2009 japheth)
;--- source file: D:\MS SDK 200108\Include\Psapi.h, last modified: 5/30/2001 19:20
;--- cmdline used for creation: -d3 Psapi.h

ifndef _PSAPI_H_
_PSAPI_H_	EQU	<>
if _MSC_VER gt 1000
;#pragma once 
endif 
ifdef __cplusplus
;extern "C"
;{
endif
@DefProto WINAPI, EnumProcesses, stdcall, , <:ptr DWORD, :DWORD, :ptr DWORD>, 12
@DefProto WINAPI, EnumProcessModules, stdcall, , <:HANDLE, :ptr HMODULE, :DWORD, :LPDWORD>, 16
@DefProto WINAPI, GetModuleBaseNameA, stdcall, , <:HANDLE, :HMODULE, :LPSTR, :DWORD>, 16
@DefProto WINAPI, GetModuleBaseNameW, stdcall, , <:HANDLE, :HMODULE, :LPWSTR, :DWORD>, 16
ifdef UNICODE
GetModuleBaseName	EQU	<GetModuleBaseNameW>
else 
GetModuleBaseName	EQU	<GetModuleBaseNameA>
endif 
@DefProto WINAPI, GetModuleFileNameExA, stdcall, , <:HANDLE, :HMODULE, :LPSTR, :DWORD>, 16
@DefProto WINAPI, GetModuleFileNameExW, stdcall, , <:HANDLE, :HMODULE, :LPWSTR, :DWORD>, 16
ifdef UNICODE
GetModuleFileNameEx	EQU	<GetModuleFileNameExW>
else 
GetModuleFileNameEx	EQU	<GetModuleFileNameExA>
endif 
MODULEINFO	struct 
lpBaseOfDll	LPVOID	?
SizeOfImage	DWORD	?
EntryPoint	LPVOID	?
MODULEINFO	ends

LPMODULEINFO typedef ptr MODULEINFO

@DefProto WINAPI, GetModuleInformation, stdcall, , <:HANDLE, :HMODULE, :LPMODULEINFO, :DWORD>, 16
@DefProto WINAPI, EmptyWorkingSet, stdcall, , <:HANDLE>, 4
@DefProto WINAPI, QueryWorkingSet, stdcall, , <:HANDLE, :PVOID, :DWORD>, 12
@DefProto WINAPI, InitializeProcessForWsWatch, stdcall, , <:HANDLE>, 4
PSAPI_WS_WATCH_INFORMATION	struct 
FaultingPc	LPVOID	?
FaultingVa	LPVOID	?
PSAPI_WS_WATCH_INFORMATION	ends

PPSAPI_WS_WATCH_INFORMATION typedef ptr PSAPI_WS_WATCH_INFORMATION

@DefProto WINAPI, GetWsChanges, stdcall, , <:HANDLE, :PPSAPI_WS_WATCH_INFORMATION, :DWORD>, 12
@DefProto WINAPI, GetMappedFileNameW, stdcall, , <:HANDLE, :LPVOID, :LPWSTR, :DWORD>, 16
@DefProto WINAPI, GetMappedFileNameA, stdcall, , <:HANDLE, :LPVOID, :LPSTR, :DWORD>, 16
ifdef UNICODE
GetMappedFileName	EQU	<GetMappedFileNameW>
else 
GetMappedFileName	EQU	<GetMappedFileNameA>
endif 
@DefProto WINAPI, EnumDeviceDrivers, stdcall, , <:ptr LPVOID, :DWORD, :LPDWORD>, 12
@DefProto WINAPI, GetDeviceDriverBaseNameA, stdcall, , <:LPVOID, :LPSTR, :DWORD>, 12
@DefProto WINAPI, GetDeviceDriverBaseNameW, stdcall, , <:LPVOID, :LPWSTR, :DWORD>, 12
ifdef UNICODE
GetDeviceDriverBaseName	EQU	<GetDeviceDriverBaseNameW>
else 
GetDeviceDriverBaseName	EQU	<GetDeviceDriverBaseNameA>
endif 
@DefProto WINAPI, GetDeviceDriverFileNameA, stdcall, , <:LPVOID, :LPSTR, :DWORD>, 12
@DefProto WINAPI, GetDeviceDriverFileNameW, stdcall, , <:LPVOID, :LPWSTR, :DWORD>, 12
ifdef UNICODE
GetDeviceDriverFileName	EQU	<GetDeviceDriverFileNameW>
else 
GetDeviceDriverFileName	EQU	<GetDeviceDriverFileNameA>
endif 
PROCESS_MEMORY_COUNTERS	struct 
cb	DWORD	?
PageFaultCount	DWORD	?
PeakWorkingSetSize	SIZE_T	?
WorkingSetSize	SIZE_T	?
QuotaPeakPagedPoolUsage	SIZE_T	?
QuotaPagedPoolUsage	SIZE_T	?
QuotaPeakNonPagedPoolUsage	SIZE_T	?
QuotaNonPagedPoolUsage	SIZE_T	?
PagefileUsage	SIZE_T	?
PeakPagefileUsage	SIZE_T	?
PROCESS_MEMORY_COUNTERS	ends

PPROCESS_MEMORY_COUNTERS typedef ptr PROCESS_MEMORY_COUNTERS
@DefProto WINAPI, GetProcessMemoryInfo, stdcall, , <:HANDLE, :PPROCESS_MEMORY_COUNTERS, :DWORD>, 12
PERFORMACE_INFORMATION	struct 
cb	DWORD	?
CommitTotal	SIZE_T	?
CommitLimit	SIZE_T	?
CommitPeak	SIZE_T	?
PhysicalTotal	SIZE_T	?
PhysicalAvailable	SIZE_T	?
SystemCache	SIZE_T	?
KernelTotal	SIZE_T	?
KernelPaged	SIZE_T	?
KernelNonpaged	SIZE_T	?
PageSize	SIZE_T	?
HandleCount	DWORD	?
ProcessCount	DWORD	?
ThreadCount	DWORD	?
PERFORMACE_INFORMATION	ends

PPERFORMACE_INFORMATION typedef ptr PERFORMACE_INFORMATION

@DefProto WINAPI, GetPerformanceInfo, stdcall, , <:PPERFORMACE_INFORMATION, :DWORD>, 8
ENUM_PAGE_FILE_INFORMATION	struct 
cb	DWORD	?
Reserved	DWORD	?
TotalSize	SIZE_T	?
TotalInUse	SIZE_T	?
PeakUsage	SIZE_T	?
ENUM_PAGE_FILE_INFORMATION	ends

PENUM_PAGE_FILE_INFORMATION typedef ptr ENUM_PAGE_FILE_INFORMATION

proto_PENUM_PAGE_FILE_CALLBACKW typedef proto  :LPVOID,:PENUM_PAGE_FILE_INFORMATION,:LPWSTR
PENUM_PAGE_FILE_CALLBACKW typedef ptr proto_PENUM_PAGE_FILE_CALLBACKW
proto_PENUM_PAGE_FILE_CALLBACKA typedef proto  :LPVOID,:PENUM_PAGE_FILE_INFORMATION,:LPSTR
PENUM_PAGE_FILE_CALLBACKA typedef ptr proto_PENUM_PAGE_FILE_CALLBACKA
@DefProto WINAPI, EnumPageFilesW, stdcall, , <:PENUM_PAGE_FILE_CALLBACKW, :LPVOID>, 8
@DefProto WINAPI, EnumPageFilesA, stdcall, , <:PENUM_PAGE_FILE_CALLBACKA, :LPVOID>, 8
ifdef UNICODE
PENUM_PAGE_FILE_CALLBACK	EQU	<PENUM_PAGE_FILE_CALLBACKW>
EnumPageFiles	EQU	<EnumPageFilesW>
else 
PENUM_PAGE_FILE_CALLBACK	EQU	<PENUM_PAGE_FILE_CALLBACKA>
EnumPageFiles	EQU	<EnumPageFilesA>
endif 
@DefProto WINAPI, GetProcessImageFileNameA, stdcall, , <:HANDLE, :LPSTR, :DWORD>, 12
@DefProto WINAPI, GetProcessImageFileNameW, stdcall, , <:HANDLE, :LPWSTR, :DWORD>, 12
ifdef UNICODE
GetProcessImageFileName	EQU	<GetProcessImageFileNameW>
else 
GetProcessImageFileName	EQU	<GetProcessImageFileNameA>
endif 
ifdef __cplusplus
;}
endif 
endif 

;--- errors: 0
;--- end of file ---
