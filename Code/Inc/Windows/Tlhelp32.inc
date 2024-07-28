;Include file created by h2incX, Version B.01.01, 11/11/2018 12:39
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\Tlhelp32.h', last modified: 19/04/2018 09:45
;Creation parameters: 

ifndef _INC_TOOLHELP32
  _INC_TOOLHELP32 equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    MAX_MODULE_NAME32 equ 255
    CreateToolhelp32Snapshot proto WIN_STD_CALL_CONV :DWORD, :DWORD
    TH32CS_SNAPHEAPLIST equ 00000001h
    TH32CS_SNAPPROCESS equ 00000002h
    TH32CS_SNAPTHREAD equ 00000004h
    TH32CS_SNAPMODULE equ 00000008h
    TH32CS_SNAPMODULE32 equ 00000010h
    TH32CS_SNAPALL equ <(TH32CS_SNAPHEAPLIST or TH32CS_SNAPPROCESS or TH32CS_SNAPTHREAD or TH32CS_SNAPMODULE)>
    TH32CS_INHERIT equ 80000000h
    HEAPLIST32 struct
      dwSize SIZE_T ?
      th32ProcessID DWORD ?
      th32HeapID ULONG_PTR ?
      dwFlags DWORD ?
    HEAPLIST32 ends

    tagHEAPLIST32 typedef HEAPLIST32
    PHEAPLIST32 typedef ptr HEAPLIST32
    LPHEAPLIST32 typedef ptr HEAPLIST32
    HF32_DEFAULT equ 1
    HF32_SHARED equ 2
    Heap32ListFirst proto WIN_STD_CALL_CONV :HANDLE, :LPHEAPLIST32
    Heap32ListNext proto WIN_STD_CALL_CONV :HANDLE, :LPHEAPLIST32
    HEAPENTRY32 struct
      dwSize SIZE_T ?
      hHandle HANDLE ?
      dwAddress ULONG_PTR ?
      dwBlockSize SIZE_T ?
      dwFlags DWORD ?
      dwLockCount DWORD ?
      dwResvd DWORD ?
      th32ProcessID DWORD ?
      th32HeapID ULONG_PTR ?
    HEAPENTRY32 ends

    tagHEAPENTRY32 typedef HEAPENTRY32
    PHEAPENTRY32 typedef ptr HEAPENTRY32
    LPHEAPENTRY32 typedef ptr HEAPENTRY32
    LF32_FIXED equ 00000001h
    LF32_FREE equ 00000002h
    LF32_MOVEABLE equ 00000004h
    Heap32First proto WIN_STD_CALL_CONV :LPHEAPENTRY32, :DWORD, :ULONG_PTR
    Heap32Next proto WIN_STD_CALL_CONV :LPHEAPENTRY32
    Toolhelp32ReadProcessMemory proto WIN_STD_CALL_CONV :DWORD, :LPCVOID, :LPVOID, :SIZE_T, :ptr SIZE_T
    PROCESSENTRY32W struct
      dwSize DWORD ?
      cntUsage DWORD ?
      th32ProcessID DWORD ?
      th32DefaultHeapID ULONG_PTR ?
      th32ModuleID DWORD ?
      cntThreads DWORD ?
      th32ParentProcessID DWORD ?
      pcPriClassBase LONG ?
      dwFlags DWORD ?
      szExeFile WCHAR MAX_PATH dup (?)
    PROCESSENTRY32W ends

    tagPROCESSENTRY32W typedef PROCESSENTRY32W
    PPROCESSENTRY32W typedef ptr PROCESSENTRY32W
    LPPROCESSENTRY32W typedef ptr PROCESSENTRY32W
    Process32FirstW proto WIN_STD_CALL_CONV :HANDLE, :LPPROCESSENTRY32W
    Process32NextW proto WIN_STD_CALL_CONV :HANDLE, :LPPROCESSENTRY32W
    PROCESSENTRY32 struct
      dwSize DWORD ?
      cntUsage DWORD ?
      th32ProcessID DWORD ?
      th32DefaultHeapID ULONG_PTR ?
      th32ModuleID DWORD ?
      cntThreads DWORD ?
      th32ParentProcessID DWORD ?
      pcPriClassBase LONG ?
      dwFlags DWORD ?
      szExeFile CHAR MAX_PATH dup (?)
    PROCESSENTRY32 ends

    tagPROCESSENTRY32 typedef PROCESSENTRY32
    PPROCESSENTRY32 typedef ptr PROCESSENTRY32
    LPPROCESSENTRY32 typedef ptr PROCESSENTRY32
    Process32First proto WIN_STD_CALL_CONV :HANDLE, :LPPROCESSENTRY32
    Process32Next proto WIN_STD_CALL_CONV :HANDLE, :LPPROCESSENTRY32
    ifdef UNICODE
      Process32First equ <Process32FirstW>
      Process32Next equ <Process32NextW>
      PROCESSENTRY32 equ <PROCESSENTRY32W>
      PPROCESSENTRY32 equ <PPROCESSENTRY32W>
      LPPROCESSENTRY32 equ <LPPROCESSENTRY32W>
    endif
    THREADENTRY32 struct
      dwSize DWORD ?
      cntUsage DWORD ?
      th32ThreadID DWORD ?
      th32OwnerProcessID DWORD ?
      tpBasePri LONG ?
      tpDeltaPri LONG ?
      dwFlags DWORD ?
    THREADENTRY32 ends

    tagTHREADENTRY32 typedef THREADENTRY32
    PTHREADENTRY32 typedef ptr THREADENTRY32
    LPTHREADENTRY32 typedef ptr THREADENTRY32
    Thread32First proto WIN_STD_CALL_CONV :HANDLE, :LPTHREADENTRY32
    Thread32Next proto WIN_STD_CALL_CONV :HANDLE, :LPTHREADENTRY32
    MODULEENTRY32W struct
      dwSize DWORD ?
      th32ModuleID DWORD ?
      th32ProcessID DWORD ?
      GlblcntUsage DWORD ?
      ProccntUsage DWORD ?
      modBaseAddr POINTER ?
      modBaseSize DWORD ?
      hModule HMODULE ?
      szModule WCHAR MAX_MODULE_NAME32 + 1 dup (?)
      szExePath WCHAR MAX_PATH dup (?)
    MODULEENTRY32W ends

    tagMODULEENTRY32W typedef MODULEENTRY32W
    PMODULEENTRY32W typedef ptr MODULEENTRY32W
    LPMODULEENTRY32W typedef ptr MODULEENTRY32W
    Module32FirstW proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32W
    Module32NextW proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32W
    MODULEENTRY32 struct
      dwSize DWORD ?
      th32ModuleID DWORD ?
      th32ProcessID DWORD ?
      GlblcntUsage DWORD ?
      ProccntUsage DWORD ?
      modBaseAddr POINTER ?
      modBaseSize DWORD ?
      hModule HMODULE ?
      szModule SBYTE MAX_MODULE_NAME32 + 1 dup (?)
      szExePath SBYTE MAX_PATH dup (?)
    MODULEENTRY32 ends

    tagMODULEENTRY32 typedef MODULEENTRY32
    PMODULEENTRY32 typedef ptr MODULEENTRY32
    LPMODULEENTRY32 typedef ptr MODULEENTRY32
    Module32First proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32
    Module32Next proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32
    ifdef UNICODE
      Module32First equ <Module32FirstW>
      Module32Next equ <Module32NextW>
      MODULEENTRY32 equ <MODULEENTRY32W>
      PMODULEENTRY32 equ <PMODULEENTRY32W>
      LPMODULEENTRY32 equ <LPMODULEENTRY32W>
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif

