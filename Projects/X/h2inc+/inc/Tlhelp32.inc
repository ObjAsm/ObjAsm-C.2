;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\tlhelp32.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:18

;\*****************************************************************************
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
    ;****** Shapshot function **********************************************
    CreateToolhelp32Snapshot proto WIN_STD_CALL_CONV :DWORD, :DWORD
    ; The th32ProcessID argument is only used if TH32CS_SNAPHEAPLIST or
    ; TH32CS_SNAPMODULE is specified. th32ProcessID == 0 means the current
    ; process.
    ; NOTE that all of the snapshots are global except for the heap and module
    ;      lists which are process specific. To enumerate the heap or module
    ;      state for all WIN32 processes call with TH32CS_SNAPALL and the
    ;      current process. Then for each process in the TH32CS_SNAPPROCESS
    ;      list that isn't the current process, do a call with just
    ;      TH32CS_SNAPHEAPLIST and/or TH32CS_SNAPMODULE.
    ; dwFlags
    TH32CS_SNAPHEAPLIST equ 00000001h
    TH32CS_SNAPPROCESS equ 00000002h
    TH32CS_SNAPTHREAD equ 00000004h
    TH32CS_SNAPMODULE equ 00000008h
    TH32CS_SNAPMODULE32 equ 00000010h
    TH32CS_SNAPALL equ <(TH32CS_SNAPHEAPLIST or TH32CS_SNAPPROCESS or TH32CS_SNAPTHREAD or TH32CS_SNAPMODULE)>
    TH32CS_INHERIT equ 80000000h
    ; Use CloseHandle to destroy the snapshot
    ;****** heap walking ***************************************************
    HEAPLIST32 struct
      dwSize XWORD ?
      th32ProcessID DWORD ?
      ; owning process
      th32HeapID XWORD ?
      ; heap (in owning process's context!)
      dwFlags DWORD ?
    HEAPLIST32 ends
    tagHEAPLIST32 typedef HEAPLIST32
    PHEAPLIST32 typedef ptr HEAPLIST32
    LPHEAPLIST32 typedef ptr HEAPLIST32
    ; dwFlags
    HF32_DEFAULT equ 1; process's default heap

    HF32_SHARED equ 2; is shared heap

    Heap32ListFirst proto WIN_STD_CALL_CONV :HANDLE, :LPHEAPLIST32
    Heap32ListNext proto WIN_STD_CALL_CONV :HANDLE, :LPHEAPLIST32
    HEAPENTRY32 struct
      dwSize XWORD ?
      hHandle HANDLE ?
      ; Handle of this heap block
      dwAddress XWORD ?
      ; Linear address of start of block
      dwBlockSize XWORD ?
      ; Size of block in bytes
      dwFlags DWORD ?
      dwLockCount DWORD ?
      dwResvd DWORD ?
      th32ProcessID DWORD ?
      ; owning process
      th32HeapID XWORD ?
      ; heap block is in
    HEAPENTRY32 ends
    tagHEAPENTRY32 typedef HEAPENTRY32
    PHEAPENTRY32 typedef ptr HEAPENTRY32
    LPHEAPENTRY32 typedef ptr HEAPENTRY32
    ; dwFlags
    LF32_FIXED equ 00000001h
    LF32_FREE equ 00000002h
    LF32_MOVEABLE equ 00000004h
    Heap32First proto WIN_STD_CALL_CONV :LPHEAPENTRY32, :DWORD, :ULONG_PTR
    Heap32Next proto WIN_STD_CALL_CONV :LPHEAPENTRY32
    Toolhelp32ReadProcessMemory proto WIN_STD_CALL_CONV :DWORD, :LPCVOID, :LPVOID, :SIZE_T, :ptr SIZE_T
    ;***** Process walking *************************************************
    PROCESSENTRY32W struct
      dwSize DWORD ?
      cntUsage DWORD ?
      th32ProcessID DWORD ?
      ; this process
      th32DefaultHeapID XWORD ?
      th32ModuleID DWORD ?
      ; associated exe
      cntThreads DWORD ?
      th32ParentProcessID DWORD ?
      ; this process's parent process
      pcPriClassBase SDWORD ?
      ; Base priority of process's threads
      dwFlags DWORD ?
      szExeFile WORD MAX_PATH dup (?)
      ; Path
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
      ; this process
      th32DefaultHeapID XWORD ?
      th32ModuleID DWORD ?
      ; associated exe
      cntThreads DWORD ?
      th32ParentProcessID DWORD ?
      ; this process's parent process
      pcPriClassBase SDWORD ?
      ; Base priority of process's threads
      dwFlags DWORD ?
      szExeFile SBYTE MAX_PATH dup (?)
      ; Path
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
    ; !UNICODE
    ;***** Thread walking **************************************************
    THREADENTRY32 struct
      dwSize DWORD ?
      cntUsage DWORD ?
      th32ThreadID DWORD ?
      ; this thread
      th32OwnerProcessID DWORD ?
      ; Process this thread is associated with
      tpBasePri SDWORD ?
      tpDeltaPri SDWORD ?
      dwFlags DWORD ?
    THREADENTRY32 ends
    tagTHREADENTRY32 typedef THREADENTRY32
    PTHREADENTRY32 typedef ptr THREADENTRY32
    LPTHREADENTRY32 typedef ptr THREADENTRY32
    Thread32First proto WIN_STD_CALL_CONV :HANDLE, :LPTHREADENTRY32
    Thread32Next proto WIN_STD_CALL_CONV :HANDLE, :LPTHREADENTRY32
    ;***** Module walking *************************************************
    MODULEENTRY32W struct
      dwSize DWORD ?
      th32ModuleID DWORD ?
      ; This module
      th32ProcessID DWORD ?
      ; owning process
      GlblcntUsage DWORD ?
      ; Global usage count on the module
      ProccntUsage DWORD ?
      ; Module usage count in th32ProcessID's context
      modBaseAddr POINTER ?
      ; Base address of module in th32ProcessID's context
      modBaseSize DWORD ?
      ; Size in bytes of module starting at modBaseAddr
      hModule HMODULE ?
      ; The hModule of this module in th32ProcessID's context
      szModule WORD MAX_MODULE_NAME32 + 1 dup (?)
      szExePath WORD MAX_PATH dup (?)
    MODULEENTRY32W ends
    tagMODULEENTRY32W typedef MODULEENTRY32W
    PMODULEENTRY32W typedef ptr MODULEENTRY32W
    LPMODULEENTRY32W typedef ptr MODULEENTRY32W
    Module32FirstW proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32W
    Module32NextW proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32W
    MODULEENTRY32 struct
      dwSize DWORD ?
      th32ModuleID DWORD ?
      ; This module
      th32ProcessID DWORD ?
      ; owning process
      GlblcntUsage DWORD ?
      ; Global usage count on the module
      ProccntUsage DWORD ?
      ; Module usage count in th32ProcessID's context
      modBaseAddr POINTER ?
      ; Base address of module in th32ProcessID's context
      modBaseSize DWORD ?
      ; Size in bytes of module starting at modBaseAddr
      hModule HMODULE ?
      ; The hModule of this module in th32ProcessID's context
      szModule SBYTE MAX_MODULE_NAME32 + 1 dup (?)
      szExePath SBYTE MAX_PATH dup (?)
    MODULEENTRY32 ends
    tagMODULEENTRY32 typedef MODULEENTRY32
    PMODULEENTRY32 typedef ptr MODULEENTRY32
    LPMODULEENTRY32 typedef ptr MODULEENTRY32
    ; NOTE CAREFULLY that the modBaseAddr and hModule fields are valid ONLY
    ; in th32ProcessID's process context.
    Module32First proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32
    Module32Next proto WIN_STD_CALL_CONV :HANDLE, :LPMODULEENTRY32
    ifdef UNICODE
      Module32First equ <Module32FirstW>
      Module32Next equ <Module32NextW>
      MODULEENTRY32 equ <MODULEENTRY32W>
      PMODULEENTRY32 equ <PMODULEENTRY32W>
      LPMODULEENTRY32 equ <LPMODULEENTRY32W>
    endif
    ; !UNICODE
    ifdef __cplusplus
      ;[...]
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; _INC_TOOLHELP32
