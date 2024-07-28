;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\libloaderapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _APISETLIBLOADER_
  _APISETLIBLOADER_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    FIND_RESOURCE_DIRECTORY_TYPES equ 0100h
    FIND_RESOURCE_DIRECTORY_NAMES equ 0200h
    FIND_RESOURCE_DIRECTORY_LANGUAGES equ 0400h
    RESOURCE_ENUM_LN equ 0001h
    RESOURCE_ENUM_MUI equ 0002h
    RESOURCE_ENUM_MUI_SYSTEM equ 0004h
    RESOURCE_ENUM_VALIDATE equ 0008h
    RESOURCE_ENUM_MODULE_EXACT equ 0010h
    SUPPORT_LANG_NUMBER equ 32
    ENUMUILANG struct
      NumOfEnumUILang ULONG ?
      SizeOfEnumUIBuffer ULONG ?
      pEnumUIBuffer POINTER ?
    ENUMUILANG ends

    tagENUMUILANG typedef ENUMUILANG
    PENUMUILANG typedef ptr ENUMUILANG
    
    ifdef STRICT
      TYPE_ENUMRESLANGPROCA typedef proto WIN_STD_CALL_CONV :HMODULE, :LPCSTR, :LPCSTR, :WORD, :LONG_PTR
      ENUMRESLANGPROCA typedef ptr TYPE_ENUMRESLANGPROCA
      TYPE_ENUMRESLANGPROCW typedef proto WIN_STD_CALL_CONV :HMODULE, :LPCWSTR, :LPCWSTR, :WORD, :LONG_PTR
      ENUMRESLANGPROCW typedef ptr TYPE_ENUMRESLANGPROCW
      ifdef UNICODE
        ENUMRESLANGPROC equ <ENUMRESLANGPROCW>
      else
        ENUMRESLANGPROC equ <ENUMRESLANGPROCA>
      endif
      TYPE_ENUMRESNAMEPROCA typedef proto WIN_STD_CALL_CONV :HMODULE, :LPCSTR, :LPSTR, :LONG_PTR
      ENUMRESNAMEPROCA typedef ptr TYPE_ENUMRESNAMEPROCA
      TYPE_ENUMRESNAMEPROCW typedef proto WIN_STD_CALL_CONV :HMODULE, :LPCWSTR, :LPWSTR, :LONG_PTR
      ENUMRESNAMEPROCW typedef ptr TYPE_ENUMRESNAMEPROCW
      ifdef UNICODE
        ENUMRESNAMEPROC equ <ENUMRESNAMEPROCW>
      else
        ENUMRESNAMEPROC equ <ENUMRESNAMEPROCA>
      endif
      TYPE_ENUMRESTYPEPROCA typedef proto WIN_STD_CALL_CONV :HMODULE, :LPSTR, :LONG_PTR
      ENUMRESTYPEPROCA typedef ptr TYPE_ENUMRESTYPEPROCA
      TYPE_ENUMRESTYPEPROCW typedef proto WIN_STD_CALL_CONV :HMODULE, :LPWSTR, :LONG_PTR
      ENUMRESTYPEPROCW typedef ptr TYPE_ENUMRESTYPEPROCW
      ifdef UNICODE
        ENUMRESTYPEPROC equ <ENUMRESTYPEPROCW>
      else
        ENUMRESTYPEPROC equ <ENUMRESTYPEPROCA>
      endif
    else
      ENUMRESTYPEPROCA typedef FARPROC
      ENUMRESTYPEPROCW typedef FARPROC
      ifdef UNICODE
        ENUMRESTYPEPROC typedef ENUMRESTYPEPROCW
      else
        ENUMRESTYPEPROC typedef ENUMRESTYPEPROCA
      endif
      ENUMRESNAMEPROCA typedef FARPROC
      ENUMRESNAMEPROCW typedef FARPROC
      ifdef UNICODE
        ENUMRESNAMEPROC typedef ENUMRESNAMEPROCW
      else
        ENUMRESNAMEPROC typedef ENUMRESNAMEPROCA
      endif
      ENUMRESLANGPROCA typedef FARPROC
      ENUMRESLANGPROCW typedef FARPROC
      ifdef UNICODE
        ENUMRESLANGPROC typedef ENUMRESLANGPROCW
      else
        ENUMRESLANGPROC typedef ENUMRESLANGPROCA
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DisableThreadLibraryCalls, WIN_STD_CALL_CONV,, <:HMODULE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FindResourceExW, WIN_STD_CALL_CONV,, <:HMODULE, :LPCWSTR, :LPCWSTR, :WORD>, 16
    ifdef UNICODE
      FindResourceEx equ <FindResourceExW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      @DefProto DllImport, FindStringOrdinal, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :SDWORD, :LPCWSTR, :SDWORD, :BOOL>, 24
    endif
    @DefProto DllImport, FreeLibrary, WIN_STD_CALL_CONV,, <:HMODULE>, 4
    @DefProto DllImport, FreeLibraryAndExitThread, WIN_STD_CALL_CONV,, <:HMODULE, :DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FreeResource, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetModuleFileNameA, WIN_STD_CALL_CONV,, <:HMODULE, :LPSTR, :DWORD>, 12
    @DefProto DllImport, GetModuleFileNameW, WIN_STD_CALL_CONV,, <:HMODULE, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetModuleFileName equ <GetModuleFileNameW>
    else
      GetModuleFileName equ <GetModuleFileNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetModuleHandleA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, GetModuleHandleW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      GetModuleHandle equ <GetModuleHandleW>
    else
      GetModuleHandle equ <GetModuleHandleA>
    endif
    if  not Defined(RC_INVOKED)
      GET_MODULE_HANDLE_EX_FLAG_PIN equ 00000001h
      GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT equ 00000002h
      GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS equ 00000004h
      TYPE_PGET_MODULE_HANDLE_EXA typedef proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :ptr HMODULE
      PGET_MODULE_HANDLE_EXA typedef ptr TYPE_PGET_MODULE_HANDLE_EXA
      TYPE_PGET_MODULE_HANDLE_EXW typedef proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :ptr HMODULE
      PGET_MODULE_HANDLE_EXW typedef ptr TYPE_PGET_MODULE_HANDLE_EXW
      ifdef UNICODE
        PGET_MODULE_HANDLE_EX equ <PGET_MODULE_HANDLE_EXW>
      else
        PGET_MODULE_HANDLE_EX equ <PGET_MODULE_HANDLE_EXA>
      endif
      @DefProto DllImport, GetModuleHandleExA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :ptr HMODULE>, 12
      @DefProto DllImport, GetModuleHandleExW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :ptr HMODULE>, 12
      ifdef UNICODE
        GetModuleHandleEx equ <GetModuleHandleExW>
      else
        GetModuleHandleEx equ <GetModuleHandleExA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetProcAddress, WIN_STD_CALL_CONV,, <:HMODULE, :LPCSTR>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, LoadLibraryExA, WIN_STD_CALL_CONV,, <:LPCSTR, :HANDLE, :DWORD>, 12
    @DefProto DllImport, LoadLibraryExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HANDLE, :DWORD>, 12
    ifdef UNICODE
      LoadLibraryEx equ <LoadLibraryExW>
    else
      LoadLibraryEx equ <LoadLibraryExA>
    endif
    DONT_RESOLVE_DLL_REFERENCES equ 00000001h
    LOAD_LIBRARY_AS_DATAFILE equ 00000002h
    LOAD_WITH_ALTERED_SEARCH_PATH equ 00000008h
    LOAD_IGNORE_CODE_AUTHZ_LEVEL equ 00000010h
    LOAD_LIBRARY_AS_IMAGE_RESOURCE equ 00000020h
    LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE equ 00000040h
    LOAD_LIBRARY_REQUIRE_SIGNED_TARGET equ 00000080h
    LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR equ 00000100h
    LOAD_LIBRARY_SEARCH_APPLICATION_DIR equ 00000200h
    LOAD_LIBRARY_SEARCH_USER_DIRS equ 00000400h
    LOAD_LIBRARY_SEARCH_SYSTEM32 equ 00000800h
    LOAD_LIBRARY_SEARCH_DEFAULT_DIRS equ 00001000h
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      LOAD_LIBRARY_SAFE_CURRENT_DIRS equ 00002000h
      LOAD_LIBRARY_SEARCH_SYSTEM32_NO_FORWARDER equ 00004000h
    else
      LOAD_LIBRARY_SEARCH_SYSTEM32_NO_FORWARDER equ <LOAD_LIBRARY_SEARCH_SYSTEM32>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
      LOAD_LIBRARY_OS_INTEGRITY_CONTINUITY equ 00008000h
    endif
    @DefProto DllImport, LoadResource, WIN_STD_CALL_CONV,, <:HMODULE, :HRSRC>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, LoadStringA, WIN_STD_CALL_CONV,, <:HINSTANCE, :UINT, :LPSTR, :SDWORD>, 16
    @DefProto DllImport, LoadStringW, WIN_STD_CALL_CONV,, <:HINSTANCE, :UINT, :LPWSTR, :SDWORD>, 16
    ifdef UNICODE
      LoadString equ <LoadStringW>
    else
      LoadString equ <LoadStringA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, LockResource, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, SizeofResource, WIN_STD_CALL_CONV,, <:HMODULE, :HRSRC>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    DLL_DIRECTORY_COOKIE typedef PVOID
    PDLL_DIRECTORY_COOKIE typedef ptr PVOID
    @DefProto DllImport, AddDllDirectory, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
    @DefProto DllImport, RemoveDllDirectory, WIN_STD_CALL_CONV,, <:DLL_DIRECTORY_COOKIE>, 4
    @DefProto DllImport, SetDefaultDllDirectories, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      @DefProto DllImport, EnumResourceLanguagesExA, WIN_STD_CALL_CONV,, <:HMODULE, :LPCSTR, :LPCSTR, :ENUMRESLANGPROCA, :LONG_PTR, :DWORD, :LANGID>, 32
      @DefProto DllImport, EnumResourceLanguagesExW, WIN_STD_CALL_CONV,, <:HMODULE, :LPCWSTR, :LPCWSTR, :ENUMRESLANGPROCW, :LONG_PTR, :DWORD, :LANGID>, 32
      ifdef UNICODE
        EnumResourceLanguagesEx equ <EnumResourceLanguagesExW>
      else
        EnumResourceLanguagesEx equ <EnumResourceLanguagesExA>
      endif
      @DefProto DllImport, EnumResourceNamesExA, WIN_STD_CALL_CONV,, <:HMODULE, :LPCSTR, :ENUMRESNAMEPROCA, :LONG_PTR, :DWORD, :LANGID>, 28
      @DefProto DllImport, EnumResourceNamesExW, WIN_STD_CALL_CONV,, <:HMODULE, :LPCWSTR, :ENUMRESNAMEPROCW, :LONG_PTR, :DWORD, :LANGID>, 28
      ifdef UNICODE
        EnumResourceNamesEx equ <EnumResourceNamesExW>
      else
        EnumResourceNamesEx equ <EnumResourceNamesExA>
      endif
      @DefProto DllImport, EnumResourceTypesExA, WIN_STD_CALL_CONV,, <:HMODULE, :ENUMRESTYPEPROCA, :LONG_PTR, :DWORD, :LANGID>, 24
      @DefProto DllImport, EnumResourceTypesExW, WIN_STD_CALL_CONV,, <:HMODULE, :ENUMRESTYPEPROCW, :LONG_PTR, :DWORD, :LANGID>, 24
      ifdef UNICODE
        EnumResourceTypesEx equ <EnumResourceTypesExW>
      else
        EnumResourceTypesEx equ <EnumResourceTypesExA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FindResourceW, WIN_STD_CALL_CONV,, <:HMODULE, :LPCWSTR, :LPCWSTR>, 12
    ifdef UNICODE
      FindResource equ <FindResourceW>
    endif
    @DefProto DllImport, LoadLibraryA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, LoadLibraryW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      LoadLibrary equ <LoadLibraryW>
    else
      LoadLibrary equ <LoadLibraryA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, EnumResourceNamesW, WIN_STD_CALL_CONV,, <:HMODULE, :LPCWSTR, :ENUMRESNAMEPROCW, :LONG_PTR>, 20
    ifdef UNICODE
      EnumResourceNames equ <EnumResourceNamesW>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

