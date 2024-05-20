;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\setupapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 12/02/2024 17:05:48

;--*
ifndef _INC_SETUPAPI
  _INC_SETUPAPI equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
      ;* nonstandard extension used : nameless struct/union *
    endif
    ; Define API decoration for direct importing of DLL references.
    if  not Defined(_SETUPAPI_)
      WINSETUPAPI equ <DECLSPEC_IMPORT>
    else
      WINSETUPAPI equ <>
    endif
    ; determine version of setupapi based on _WIN32_WINDOWS and _WIN32_WINNT
    ; NT4 version of setupapi   (_WIN32_WINNT_NT4) is earliest, and installed onto Win95 by IE.
    ; Win2k version of setupapi (_WIN32_WINNT_WIN2K) also shipped in WinME
    ; we'll use "0x0410" to indicate version of setupapi shipped with Win98
    ifndef _SETUPAPI_VER
      if Defined(_WIN32_WINNT) and ( not Defined(_WIN32_WINDOWS) or (_WIN32_WINNT lt _WIN32_WINDOWS))
        _SETUPAPI_VER equ <_WIN32_WINNT>; SetupAPI version follows Windows NT version

      elseif Defined(_WIN32_WINDOWS)
        if _WIN32_WINDOWS ge 0490h
          _SETUPAPI_VER equ <_WIN32_WINNT_WIN2K>; WinME uses same version of SetupAPI as Win2k

        elseif _WIN32_WINDOWS ge 0410h
          _SETUPAPI_VER equ 0410h; Indicates version of SetupAPI shipped with Win98

        else
          _SETUPAPI_VER equ <_WIN32_WINNT_NT4>; Earliest SetupAPI version

        endif
        ; _WIN32_WINDOWS
      else
      ; _WIN32_WINNT/_WIN32_WINDOWS
        _SETUPAPI_VER equ <_WIN32_WINNT_WINXP>
      endif
      ; _WIN32_WINNT/_WIN32_WINDOWS
    endif
    ; !_SETUPAPI_VER
    ifndef __LPGUID_DEFINED__
      __LPGUID_DEFINED__ equ <>
      LPGUID typedef ptr GUID
    endif
    ; Include spapidef.h for basic definitions and flags
    include spapidef.inc
    ; Include commctrl.h for our use of HIMAGELIST and wizard support.
    include commctrl.inc
    ; Include devpropdef.h for our use of DEVPROPERTYKEY and DEVPROPTYPE.
    include devpropdef.inc
    if Defined(_WIN64)
      include pshpack8.inc
      ; Assume 8-byte (64-bit) packing throughout
    else
      include pshpack1.inc
      ; Assume byte packing throughout (32-bit processor)
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ; Define maximum string length constants
    LINE_LEN equ 256; Windows 9x-compatible maximum for

    ; displayable strings coming from a
    ; device INF.
    MAX_INF_STRING_LENGTH equ 4096; Actual maximum size of an INF string

    ; (including string substitutions).
    MAX_INF_SECTION_NAME_LENGTH equ 255; For Windows 9x compatibility, INF

    ; section names should be constrained
    ; to 32 characters.
    MAX_TITLE_LEN equ 60
    MAX_INSTRUCTION_LEN equ 256
    MAX_LABEL_LEN equ 30
    MAX_SERVICE_NAME_LEN equ 256
    MAX_SUBTITLE_LEN equ 256
    ; Define maximum length of a machine name in the format expected by ConfigMgr32
    ; CM_Connect_Machine (i.e., "\\\\MachineName\0").
    SP_MAX_MACHINENAME_LENGTH equ (MAX_PATH + 3)
    ; Define type for reference to loaded inf file
    HINF typedef PVOID
    ; Inf context structure. Applications must not interpret or
    ; overwrite values in these structures.
    INFCONTEXT struct
      Inf POINTER ?
      CurrentInf POINTER ?
      Section DWORD ?
      Line DWORD ?
    INFCONTEXT ends
    _INFCONTEXT typedef INFCONTEXT
    PINFCONTEXT typedef ptr INFCONTEXT
    ; Inf file information structure.
    SP_INF_INFORMATION struct
      InfStyle DWORD ?
      InfCount DWORD ?
      VersionData BYTE ANYSIZE_ARRAY dup (?)
    SP_INF_INFORMATION ends
    _SP_INF_INFORMATION typedef SP_INF_INFORMATION
    PSP_INF_INFORMATION typedef ptr SP_INF_INFORMATION
    ; Define structure for passing alternate platform info into
    ; SetupSetFileQueueAlternatePlatform and SetupQueryInfOriginalFileInformation.
    SP_ALTPLATFORM_INFO_V3 struct
      cbSize DWORD ?
      ; platform to use (VER_PLATFORM_WIN32_WINDOWS or VER_PLATFORM_WIN32_NT)
      Platform DWORD ?
      ; major and minor version numbers to use
      MajorVersion DWORD ?
      MinorVersion DWORD ?
      ; processor architecture to use (PROCESSOR_ARCHITECTURE_INTEL,
      ; PROCESSOR_ARCHITECTURE_AMD64, PROCESSOR_ARCHITECTURE_IA64,
      ; or PROCESSOR_ARCHITECTURE_ARM).
      ProcessorArchitecture WORD ?
      union
        Reserved WORD ?
        ; for compatibility with V1 structure
        Flags WORD ?
        ; indicates validity of non V1 fields
      ends
      ; specify SP_ALTPLATFORM_FLAGS_VERSION_RANGE in Flags
      ; to use FirstValidatedMajorVersion and FirstValidatedMinorVersion
      ; Major and minor versions of the oldest previous OS for which this
      ; package's digital signature may be considered valid.  For example, say
      ; the alternate platform is VER_PLATFORM_WIN32_NT, version 5.1.  However,
      ; it is wished that driver packages signed with a 5.0 osattr also be
      ; considered valid.  In this case, you'd have a  MajorVersion/MinorVersion
      ; of 5.1, and a FirstValidatedMajorVersion/FirstValidatedMinorVersion of
      ; 5.0.  To validate packages signed for any previous OS release, specify
      ; 0 for these fields.  To only validate against the target alternate
      ; platform, specify the same values as those in the MajorVersion and
      ; MinorVersion fields.
      FirstValidatedMajorVersion DWORD ?
      FirstValidatedMinorVersion DWORD ?
      ; specify non-zero value (e.g. VER_NT_WORKSTATION) in ProductType to use
      ; field, and/or specify SP_ALTPLATFORM_FLAGS_SUITE_MASK in Flags to use
      ; SuiteMask field, which may be zero.
      ; Product type and suite mask of alternate platform.  Used to select
      ; matching decorated install sections within driver packages that target
      ; specific product variants of the OS.  For example, for only Server
      ; products with the Enterprise or Small Business suite classification,
      ; use ProductType VER_NT_SERVER with SuiteMask VER_SUITE_ENTERPRISE and
      ; VER_SUITE_SMALLBUSINESS.
      ProductType BYTE ?
      SuiteMask WORD ?
      ; Build number of alternate platform.  Used to select matching
      ; decorated install sections within driver packages that target a
      ; minimal build number with the specified OS
      ; MajorVersion/MinorVersion. If no specific minimal build number
      ; targeting is required, a value of zero should be specified. Note that
      ; this capability is only supported on certain builds of 10.0 and
      ; later.
      BuildNumber DWORD ?
    SP_ALTPLATFORM_INFO_V3 ends
    _SP_ALTPLATFORM_INFO_V3 typedef SP_ALTPLATFORM_INFO_V3
    PSP_ALTPLATFORM_INFO_V3 typedef ptr SP_ALTPLATFORM_INFO_V3
    SP_ALTPLATFORM_INFO_V2 struct
      cbSize DWORD ?
      Platform DWORD ?
      MajorVersion DWORD ?
      MinorVersion DWORD ?
      ProcessorArchitecture WORD ?
      union
        Reserved WORD ?
        Flags WORD ?
      ends
      FirstValidatedMajorVersion DWORD ?
      FirstValidatedMinorVersion DWORD ?
    SP_ALTPLATFORM_INFO_V2 ends
    _SP_ALTPLATFORM_INFO_V2 typedef SP_ALTPLATFORM_INFO_V2
    PSP_ALTPLATFORM_INFO_V2 typedef ptr SP_ALTPLATFORM_INFO_V2
    SP_ALTPLATFORM_INFO_V1 struct
      cbSize DWORD ?
      Platform DWORD ?
      MajorVersion DWORD ?
      MinorVersion DWORD ?
      ProcessorArchitecture WORD ?
      Reserved WORD ?
      ; must be zero.
    SP_ALTPLATFORM_INFO_V1 ends
    _SP_ALTPLATFORM_INFO_V1 typedef SP_ALTPLATFORM_INFO_V1
    PSP_ALTPLATFORM_INFO_V1 typedef ptr SP_ALTPLATFORM_INFO_V1
    if USE_SP_ALTPLATFORM_INFO_V1 or (_SETUPAPI_VER lt _WIN32_WINNT_WINXP)
      ; use version 1 altplatform info data structure
      SP_ALTPLATFORM_INFO typedef SP_ALTPLATFORM_INFO_V1
      PSP_ALTPLATFORM_INFO typedef PSP_ALTPLATFORM_INFO_V1
    elseif USE_SP_ALTPLATFORM_INFO_V3 and (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      ; use version 3 altplatform info data structure
      SP_ALTPLATFORM_INFO typedef SP_ALTPLATFORM_INFO_V3
      PSP_ALTPLATFORM_INFO typedef PSP_ALTPLATFORM_INFO_V3
    else
      ; use version 2 altplatform info data structure
      SP_ALTPLATFORM_INFO typedef SP_ALTPLATFORM_INFO_V2
      PSP_ALTPLATFORM_INFO typedef PSP_ALTPLATFORM_INFO_V2
    endif
    ; use default version of altplatform info data structure
    ; SP_ALTPLATFORM_INFO.Flags values
    if _WIN32_WINNT ge _WIN32_WINNT_WINXP
      SP_ALTPLATFORM_FLAGS_VERSION_RANGE equ (0001h); FirstValidatedMajor/MinorVersion

    endif
    if NTDDI_VERSION ge NTDDI_WIN10_RS1
      SP_ALTPLATFORM_FLAGS_SUITE_MASK equ (0002h); SuiteMask

    endif
    ; Define structure that is filled in by SetupQueryInfOriginalFileInformation
    ; to indicate the INF's original name and the original name of the (potentially
    ; platform-specific) catalog file specified by that INF.
    SP_ORIGINAL_FILE_INFO_A struct
      cbSize DWORD ?
      OriginalInfName SBYTE MAX_PATH dup (?)
      OriginalCatalogName SBYTE MAX_PATH dup (?)
    SP_ORIGINAL_FILE_INFO_A ends
    _SP_ORIGINAL_FILE_INFO_A typedef SP_ORIGINAL_FILE_INFO_A
    PSP_ORIGINAL_FILE_INFO_A typedef ptr SP_ORIGINAL_FILE_INFO_A
    SP_ORIGINAL_FILE_INFO_W struct
      cbSize DWORD ?
      OriginalInfName WORD MAX_PATH dup (?)
      OriginalCatalogName WORD MAX_PATH dup (?)
    SP_ORIGINAL_FILE_INFO_W ends
    _SP_ORIGINAL_FILE_INFO_W typedef SP_ORIGINAL_FILE_INFO_W
    PSP_ORIGINAL_FILE_INFO_W typedef ptr SP_ORIGINAL_FILE_INFO_W
    ifdef UNICODE
      SP_ORIGINAL_FILE_INFO typedef SP_ORIGINAL_FILE_INFO_W
      PSP_ORIGINAL_FILE_INFO typedef PSP_ORIGINAL_FILE_INFO_W
    else
      SP_ORIGINAL_FILE_INFO typedef SP_ORIGINAL_FILE_INFO_A
      PSP_ORIGINAL_FILE_INFO typedef PSP_ORIGINAL_FILE_INFO_A
    endif
    ; SP_INF_INFORMATION.InfStyle values
    INF_STYLE_NONE equ 00000000h; unrecognized or non-existent

    INF_STYLE_OLDNT equ 00000001h; winnt 3.x

    INF_STYLE_WIN4 equ 00000002h; Win95

    ; Additional InfStyle flags that may be specified when calling SetupOpenInfFile.
    INF_STYLE_CACHE_ENABLE equ 00000010h; always cache INF, even outside of %windir%\Inf

    INF_STYLE_CACHE_DISABLE equ 00000020h; delete cached INF information

    if _SETUPAPI_VER ge _WIN32_WINNT_WS03
      INF_STYLE_CACHE_IGNORE equ 00000040h; ignore any cached INF information

    endif
    ; Target directory specs.
    DIRID_ABSOLUTE equ -1; real 32-bit -1

    DIRID_ABSOLUTE_16BIT equ 0ffffh; 16-bit -1 for compat w/setupx

    DIRID_NULL equ 0
    DIRID_SRCPATH equ 1
    DIRID_WINDOWS equ 10
    DIRID_SYSTEM equ 11; system32

    DIRID_DRIVERS equ 12
    DIRID_IOSUBSYS equ <DIRID_DRIVERS>
    DIRID_DRIVER_STORE equ 13
    DIRID_INF equ 17
    DIRID_HELP equ 18
    DIRID_FONTS equ 20
    DIRID_VIEWERS equ 21
    DIRID_COLOR equ 23
    DIRID_APPS equ 24
    DIRID_SHARED equ 25
    DIRID_BOOT equ 30
    DIRID_SYSTEM16 equ 50
    DIRID_SPOOL equ 51
    DIRID_SPOOLDRIVERS equ 52
    DIRID_USERPROFILE equ 53
    DIRID_LOADER equ 54
    DIRID_PRINTPROCESSOR equ 55
    DIRID_DEFAULT equ <DIRID_SYSTEM>
    ; The following DIRIDs are for commonly-used shell "special folders".  The
    ; complete list of such folders is contained in shlobj.h.  In that headerfile,
    ; each folder is assigned a CSIDL_* value.  The DIRID values below are created
    ; by taking the CSIDL value in shlobj.h and OR'ing it with 0x4000.  Thus, if
    ; an INF needs to reference other special folders not defined below, it may
    ; generate one using the above mechanism, and setupapi will automatically deal
    ; with it and use the corresponding shell's path where appropriate.  (Remember
    ; that DIRIDs must be specified in decimal, not hex, in an INF when used for
    ; string substitution.)
    DIRID_COMMON_STARTMENU equ 16406; All Users\Start Menu

    DIRID_COMMON_PROGRAMS equ 16407; All Users\Start Menu\Programs

    DIRID_COMMON_STARTUP equ 16408; All Users\Start Menu\Programs\Startup

    DIRID_COMMON_DESKTOPDIRECTORY equ 16409; All Users\Desktop

    DIRID_COMMON_FAVORITES equ 16415; All Users\Favorites

    DIRID_COMMON_APPDATA equ 16419; All Users\Application Data

    DIRID_PROGRAM_FILES equ 16422; Program Files

    DIRID_SYSTEM_X86 equ 16425; system32 for WOW

    DIRID_PROGRAM_FILES_X86 equ 16426; Program Files for WOW

    DIRID_PROGRAM_FILES_COMMON equ 16427; Program Files\Common

    DIRID_PROGRAM_FILES_COMMONX86 equ 16428; x86 Program Files\Common for WOW

    DIRID_COMMON_TEMPLATES equ 16429; All Users\Templates

    DIRID_COMMON_DOCUMENTS equ 16430; All Users\Documents

    ; First user-definable dirid. See SetupSetDirectoryId().
    DIRID_USER equ 8000h
    ; Setup callback notification routine type
    TYPE_PSP_FILE_CALLBACK_A typedef proto WIN_STD_CALL_CONV :PVOID, :UINT, :UINT_PTR, :UINT_PTR
    PSP_FILE_CALLBACK_A typedef ptr TYPE_PSP_FILE_CALLBACK_A

    TYPE_PSP_FILE_CALLBACK_W typedef proto WIN_STD_CALL_CONV :PVOID, :UINT, :UINT_PTR, :UINT_PTR
    PSP_FILE_CALLBACK_W typedef ptr TYPE_PSP_FILE_CALLBACK_W

    ifdef UNICODE
      PSP_FILE_CALLBACK equ <PSP_FILE_CALLBACK_W>
    else
      PSP_FILE_CALLBACK equ <PSP_FILE_CALLBACK_A>
    endif
    ; Operation/queue start/end notification. These are ordinal values.
    SPFILENOTIFY_STARTQUEUE equ 00000001h
    SPFILENOTIFY_ENDQUEUE equ 00000002h
    SPFILENOTIFY_STARTSUBQUEUE equ 00000003h
    SPFILENOTIFY_ENDSUBQUEUE equ 00000004h
    SPFILENOTIFY_STARTDELETE equ 00000005h
    SPFILENOTIFY_ENDDELETE equ 00000006h
    SPFILENOTIFY_DELETEERROR equ 00000007h
    SPFILENOTIFY_STARTRENAME equ 00000008h
    SPFILENOTIFY_ENDRENAME equ 00000009h
    SPFILENOTIFY_RENAMEERROR equ 0000000ah
    SPFILENOTIFY_STARTCOPY equ 0000000bh
    SPFILENOTIFY_ENDCOPY equ 0000000ch
    SPFILENOTIFY_COPYERROR equ 0000000dh
    SPFILENOTIFY_NEEDMEDIA equ 0000000eh
    SPFILENOTIFY_QUEUESCAN equ 0000000fh
    ; These are used with SetupIterateCabinet().
    SPFILENOTIFY_CABINETINFO equ 00000010h
    SPFILENOTIFY_FILEINCABINET equ 00000011h
    SPFILENOTIFY_NEEDNEWCABINET equ 00000012h
    SPFILENOTIFY_FILEEXTRACTED equ 00000013h
    SPFILENOTIFY_FILEOPDELAYED equ 00000014h
    ; These are used for backup operations
    SPFILENOTIFY_STARTBACKUP equ 00000015h
    SPFILENOTIFY_BACKUPERROR equ 00000016h
    SPFILENOTIFY_ENDBACKUP equ 00000017h
    ; Extended notification for SetupScanFileQueue(Flags=SPQ_SCAN_USE_CALLBACKEX)
    SPFILENOTIFY_QUEUESCAN_EX equ 00000018h
    SPFILENOTIFY_STARTREGISTRATION equ 00000019h
    SPFILENOTIFY_ENDREGISTRATION equ 00000020h
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; Extended notification for SetupScanFileQueue(Flags=SPQ_SCAN_USE_CALLBACK_SIGNERINFO)
      SPFILENOTIFY_QUEUESCAN_SIGNERINFO equ 00000040h
    endif
    ; Copy notification. These are bit flags that may be combined.
    SPFILENOTIFY_LANGMISMATCH equ 00010000h
    SPFILENOTIFY_TARGETEXISTS equ 00020000h
    SPFILENOTIFY_TARGETNEWER equ 00040000h
    ; File operation codes and callback outcomes.
    FILEOP_COPY equ 0
    FILEOP_RENAME equ 1
    FILEOP_DELETE equ 2
    FILEOP_BACKUP equ 3
    FILEOP_ABORT equ 0
    FILEOP_DOIT equ 1
    FILEOP_SKIP equ 2
    FILEOP_RETRY equ <FILEOP_DOIT>
    FILEOP_NEWPATH equ 4
    ; Flags in inf copy sections
    COPYFLG_WARN_IF_SKIP equ 00000001h; warn if user tries to skip file

    COPYFLG_NOSKIP equ 00000002h; disallow skipping this file

    COPYFLG_NOVERSIONCHECK equ 00000004h; ignore versions and overwrite target

    COPYFLG_FORCE_FILE_IN_USE equ 00000008h; force file-in-use behavior

    COPYFLG_NO_OVERWRITE equ 00000010h; do not copy if file exists on target

    COPYFLG_NO_VERSION_DIALOG equ 00000020h; do not copy if target is newer

    COPYFLG_OVERWRITE_OLDER_ONLY equ 00000040h; leave target alone if version same as source

    COPYFLG_PROTECTED_WINDOWS_DRIVER_FILE equ 00000100h; a Windows driver file to be

    ; protected as other Windows system files
    COPYFLG_REPLACEONLY equ 00000400h; copy only if file exists on target

    COPYFLG_NODECOMP equ 00000800h; don't attempt to decompress file; copy as-is

    COPYFLG_REPLACE_BOOT_FILE equ 00001000h; file must be present upon reboot (i.e., it's

    ; needed by the loader); this flag implies a reboot
    COPYFLG_NOPRUNE equ 00002000h; never prune this file

    COPYFLG_IN_USE_TRY_RENAME equ 00004000h; If file in use, try to rename the target first

    ; Flags in inf delete sections
    ; New flags go in high word
    DELFLG_IN_USE equ 00000001h; queue in-use file for delete

    DELFLG_IN_USE1 equ 00010000h; high-word version of DELFLG_IN_USE

    ; Source and file paths. Used when notifying queue callback
    ; of SPFILENOTIFY_STARTxxx, SPFILENOTIFY_ENDxxx, and SPFILENOTIFY_xxxERROR.
    FILEPATHS_A struct
      Target PCSTR ?
      Source PCSTR ?
      ; not used for delete operations
      Win32Error DWORD ?
      Flags DWORD ?
      ; such as SP_COPY_NOSKIP for copy errors
    FILEPATHS_A ends
    _FILEPATHS_A typedef FILEPATHS_A
    PFILEPATHS_A typedef ptr FILEPATHS_A
    FILEPATHS_W struct
      Target PCWSTR ?
      Source PCWSTR ?
      ; not used for delete operations
      Win32Error DWORD ?
      Flags DWORD ?
      ; such as SP_COPY_NOSKIP for copy errors
    FILEPATHS_W ends
    _FILEPATHS_W typedef FILEPATHS_W
    PFILEPATHS_W typedef ptr FILEPATHS_W
    ifdef UNICODE
      FILEPATHS typedef FILEPATHS_W
      PFILEPATHS typedef PFILEPATHS_W
    else
      FILEPATHS typedef FILEPATHS_A
      PFILEPATHS typedef PFILEPATHS_A
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      FILEPATHS_SIGNERINFO_A struct
        Target PCSTR ?
        Source PCSTR ?
        ; not used for delete operations
        Win32Error DWORD ?
        Flags DWORD ?
        ; such as SP_COPY_NOSKIP for copy errors
        DigitalSigner PCSTR ?
        Version PCSTR ?
        CatalogFile PCSTR ?
      FILEPATHS_SIGNERINFO_A ends
      _FILEPATHS_SIGNERINFO_A typedef FILEPATHS_SIGNERINFO_A
      PFILEPATHS_SIGNERINFO_A typedef ptr FILEPATHS_SIGNERINFO_A
      FILEPATHS_SIGNERINFO_W struct
        Target PCWSTR ?
        Source PCWSTR ?
        ; not used for delete operations
        Win32Error DWORD ?
        Flags DWORD ?
        ; such as SP_COPY_NOSKIP for copy errors
        DigitalSigner PCWSTR ?
        Version PCWSTR ?
        CatalogFile PCWSTR ?
      FILEPATHS_SIGNERINFO_W ends
      _FILEPATHS_SIGNERINFO_W typedef FILEPATHS_SIGNERINFO_W
      PFILEPATHS_SIGNERINFO_W typedef ptr FILEPATHS_SIGNERINFO_W
      ifdef UNICODE
        FILEPATHS_SIGNERINFO typedef FILEPATHS_SIGNERINFO_W
        PFILEPATHS_SIGNERINFO typedef PFILEPATHS_SIGNERINFO_W
      else
        FILEPATHS_SIGNERINFO typedef FILEPATHS_SIGNERINFO_A
        PFILEPATHS_SIGNERINFO typedef PFILEPATHS_SIGNERINFO_A
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Structure used with SPFILENOTIFY_NEEDMEDIA
    SOURCE_MEDIA_A struct
      Reserved PCSTR ?
      Tagfile PCSTR ?
      ; may be NULL
      Description PCSTR ?
      ; Pathname part and filename part of source file
      ; that caused us to need the media.
      SourcePath PCSTR ?
      SourceFile PCSTR ?
      Flags DWORD ?
      ; subset of SP_COPY_xxx
    SOURCE_MEDIA_A ends
    _SOURCE_MEDIA_A typedef SOURCE_MEDIA_A
    PSOURCE_MEDIA_A typedef ptr SOURCE_MEDIA_A
    SOURCE_MEDIA_W struct
      Reserved PCWSTR ?
      Tagfile PCWSTR ?
      ; may be NULL
      Description PCWSTR ?
      ; Pathname part and filename part of source file
      ; that caused us to need the media.
      SourcePath PCWSTR ?
      SourceFile PCWSTR ?
      Flags DWORD ?
      ; subset of SP_COPY_xxx
    SOURCE_MEDIA_W ends
    _SOURCE_MEDIA_W typedef SOURCE_MEDIA_W
    PSOURCE_MEDIA_W typedef ptr SOURCE_MEDIA_W
    ifdef UNICODE
      SOURCE_MEDIA typedef SOURCE_MEDIA_W
      PSOURCE_MEDIA typedef PSOURCE_MEDIA_W
    else
      SOURCE_MEDIA typedef SOURCE_MEDIA_A
      PSOURCE_MEDIA typedef PSOURCE_MEDIA_A
    endif
    ; Structure used with SPFILENOTIFY_CABINETINFO and
    ; SPFILENOTIFY_NEEDNEWCABINET
    CABINET_INFO_A struct
      CabinetPath PCSTR ?
      CabinetFile PCSTR ?
      DiskName PCSTR ?
      SetId WORD ?
      CabinetNumber WORD ?
    CABINET_INFO_A ends
    _CABINET_INFO_A typedef CABINET_INFO_A
    PCABINET_INFO_A typedef ptr CABINET_INFO_A
    CABINET_INFO_W struct
      CabinetPath PCWSTR ?
      CabinetFile PCWSTR ?
      DiskName PCWSTR ?
      SetId WORD ?
      CabinetNumber WORD ?
    CABINET_INFO_W ends
    _CABINET_INFO_W typedef CABINET_INFO_W
    PCABINET_INFO_W typedef ptr CABINET_INFO_W
    ifdef UNICODE
      CABINET_INFO typedef CABINET_INFO_W
      PCABINET_INFO typedef PCABINET_INFO_W
    else
      CABINET_INFO typedef CABINET_INFO_A
      PCABINET_INFO typedef PCABINET_INFO_A
    endif
    ; Structure used with SPFILENOTIFY_FILEINCABINET
    FILE_IN_CABINET_INFO_A struct
      NameInCabinet PCSTR ?
      FileSize DWORD ?
      Win32Error DWORD ?
      DosDate WORD ?
      DosTime WORD ?
      DosAttribs WORD ?
      FullTargetName SBYTE MAX_PATH dup (?)
    FILE_IN_CABINET_INFO_A ends
    _FILE_IN_CABINET_INFO_A typedef FILE_IN_CABINET_INFO_A
    PFILE_IN_CABINET_INFO_A typedef ptr FILE_IN_CABINET_INFO_A
    FILE_IN_CABINET_INFO_W struct
      NameInCabinet PCWSTR ?
      FileSize DWORD ?
      Win32Error DWORD ?
      DosDate WORD ?
      DosTime WORD ?
      DosAttribs WORD ?
      FullTargetName WORD MAX_PATH dup (?)
    FILE_IN_CABINET_INFO_W ends
    _FILE_IN_CABINET_INFO_W typedef FILE_IN_CABINET_INFO_W
    PFILE_IN_CABINET_INFO_W typedef ptr FILE_IN_CABINET_INFO_W
    ifdef UNICODE
      FILE_IN_CABINET_INFO typedef FILE_IN_CABINET_INFO_W
      PFILE_IN_CABINET_INFO typedef PFILE_IN_CABINET_INFO_W
    else
      FILE_IN_CABINET_INFO typedef FILE_IN_CABINET_INFO_A
      PFILE_IN_CABINET_INFO typedef PFILE_IN_CABINET_INFO_A
    endif
    ; Structure used for SPFILENOTIFY_***REGISTRATION
    ; callback
    SP_REGISTER_CONTROL_STATUSA struct
      cbSize DWORD ?
      FileName PCSTR ?
      Win32Error DWORD ?
      FailureCode DWORD ?
    SP_REGISTER_CONTROL_STATUSA ends
    _SP_REGISTER_CONTROL_STATUSA typedef SP_REGISTER_CONTROL_STATUSA
    PSP_REGISTER_CONTROL_STATUSA typedef ptr SP_REGISTER_CONTROL_STATUSA
    SP_REGISTER_CONTROL_STATUSW struct
      cbSize DWORD ?
      FileName PCWSTR ?
      Win32Error DWORD ?
      FailureCode DWORD ?
    SP_REGISTER_CONTROL_STATUSW ends
    _SP_REGISTER_CONTROL_STATUSW typedef SP_REGISTER_CONTROL_STATUSW
    PSP_REGISTER_CONTROL_STATUSW typedef ptr SP_REGISTER_CONTROL_STATUSW
    ifdef UNICODE
      SP_REGISTER_CONTROL_STATUS typedef SP_REGISTER_CONTROL_STATUSW
      PSP_REGISTER_CONTROL_STATUS typedef PSP_REGISTER_CONTROL_STATUSW
    else
      SP_REGISTER_CONTROL_STATUS typedef SP_REGISTER_CONTROL_STATUSA
      PSP_REGISTER_CONTROL_STATUS typedef PSP_REGISTER_CONTROL_STATUSA
    endif
    ; valid values for SP_REGISTER_CONTROL_STATUS.FailureCode field
    SPREG_SUCCESS equ 00000000h
    SPREG_LOADLIBRARY equ 00000001h
    SPREG_GETPROCADDR equ 00000002h
    SPREG_REGSVR equ 00000003h
    SPREG_DLLINSTALL equ 00000004h
    SPREG_TIMEOUT equ 00000005h
    SPREG_UNKNOWN equ 0FFFFFFFFh
    ; Define type for setup file queue
    HSPFILEQ typedef PVOID
    ; Structure used with SetupQueueCopyIndirect
    SP_FILE_COPY_PARAMS_A struct
      cbSize DWORD ?
      QueueHandle HSPFILEQ ?
      SourceRootPath PCSTR ?
      SourcePath PCSTR ?
      SourceFilename PCSTR ?
      SourceDescription PCSTR ?
      SourceTagfile PCSTR ?
      TargetDirectory PCSTR ?
      TargetFilename PCSTR ?
      CopyStyle DWORD ?
      LayoutInf HINF ?
      SecurityDescriptor PCSTR ?
    SP_FILE_COPY_PARAMS_A ends
    _SP_FILE_COPY_PARAMS_A typedef SP_FILE_COPY_PARAMS_A
    PSP_FILE_COPY_PARAMS_A typedef ptr SP_FILE_COPY_PARAMS_A
    SP_FILE_COPY_PARAMS_W struct
      cbSize DWORD ?
      QueueHandle HSPFILEQ ?
      SourceRootPath PCWSTR ?
      SourcePath PCWSTR ?
      SourceFilename PCWSTR ?
      SourceDescription PCWSTR ?
      SourceTagfile PCWSTR ?
      TargetDirectory PCWSTR ?
      TargetFilename PCWSTR ?
      CopyStyle DWORD ?
      LayoutInf HINF ?
      SecurityDescriptor PCWSTR ?
    SP_FILE_COPY_PARAMS_W ends
    _SP_FILE_COPY_PARAMS_W typedef SP_FILE_COPY_PARAMS_W
    PSP_FILE_COPY_PARAMS_W typedef ptr SP_FILE_COPY_PARAMS_W
    ifdef UNICODE
      SP_FILE_COPY_PARAMS typedef SP_FILE_COPY_PARAMS_W
      PSP_FILE_COPY_PARAMS typedef PSP_FILE_COPY_PARAMS_W
    else
      SP_FILE_COPY_PARAMS typedef SP_FILE_COPY_PARAMS_A
      PSP_FILE_COPY_PARAMS typedef PSP_FILE_COPY_PARAMS_A
    endif
    ; Define type for setup disk space list
    HDSKSPC typedef PVOID
    ; Define type for reference to device information set
    HDEVINFO typedef PVOID
    ; Device information structure (references a device instance
    ; that is a member of a device information set)
    SP_DEVINFO_DATA struct
      cbSize DWORD ?
      ClassGuid GUID <>
      DevInst DWORD ?
      ; DEVINST handle
      Reserved XWORD ?
    SP_DEVINFO_DATA ends
    _SP_DEVINFO_DATA typedef SP_DEVINFO_DATA
    PSP_DEVINFO_DATA typedef ptr SP_DEVINFO_DATA
    ; Device interface information structure (references a device
    ; interface that is associated with the device information
    ; element that owns it).
    SP_DEVICE_INTERFACE_DATA struct
      cbSize DWORD ?
      InterfaceClassGuid GUID <>
      Flags DWORD ?
      Reserved XWORD ?
    SP_DEVICE_INTERFACE_DATA ends
    _SP_DEVICE_INTERFACE_DATA typedef SP_DEVICE_INTERFACE_DATA
    PSP_DEVICE_INTERFACE_DATA typedef ptr SP_DEVICE_INTERFACE_DATA
    ; Flags for SP_DEVICE_INTERFACE_DATA.Flags field.
    SPINT_ACTIVE equ 00000001h
    SPINT_DEFAULT equ 00000002h
    SPINT_REMOVED equ 00000004h
    ; Backward compatibility--do not use.
    SP_INTERFACE_DEVICE_DATA typedef SP_DEVICE_INTERFACE_DATA
    PSP_INTERFACE_DEVICE_DATA typedef PSP_DEVICE_INTERFACE_DATA
    SPID_ACTIVE equ <SPINT_ACTIVE>
    SPID_DEFAULT equ <SPINT_DEFAULT>
    SPID_REMOVED equ <SPINT_REMOVED>
    SP_DEVICE_INTERFACE_DETAIL_DATA_A struct
      cbSize DWORD ?
      DevicePath SBYTE ANYSIZE_ARRAY dup (?)
    SP_DEVICE_INTERFACE_DETAIL_DATA_A ends
    _SP_DEVICE_INTERFACE_DETAIL_DATA_A typedef SP_DEVICE_INTERFACE_DETAIL_DATA_A
    PSP_DEVICE_INTERFACE_DETAIL_DATA_A typedef ptr SP_DEVICE_INTERFACE_DETAIL_DATA_A
    SP_DEVICE_INTERFACE_DETAIL_DATA_W struct
      cbSize DWORD ?
      DevicePath WORD ANYSIZE_ARRAY dup (?)
    SP_DEVICE_INTERFACE_DETAIL_DATA_W ends
    _SP_DEVICE_INTERFACE_DETAIL_DATA_W typedef SP_DEVICE_INTERFACE_DETAIL_DATA_W
    PSP_DEVICE_INTERFACE_DETAIL_DATA_W typedef ptr SP_DEVICE_INTERFACE_DETAIL_DATA_W
    ifdef UNICODE
      SP_DEVICE_INTERFACE_DETAIL_DATA typedef SP_DEVICE_INTERFACE_DETAIL_DATA_W
      PSP_DEVICE_INTERFACE_DETAIL_DATA typedef PSP_DEVICE_INTERFACE_DETAIL_DATA_W
    else
      SP_DEVICE_INTERFACE_DETAIL_DATA typedef SP_DEVICE_INTERFACE_DETAIL_DATA_A
      PSP_DEVICE_INTERFACE_DETAIL_DATA typedef PSP_DEVICE_INTERFACE_DETAIL_DATA_A
    endif
    ; Backward compatibility--do not use.
    SP_INTERFACE_DEVICE_DETAIL_DATA_W typedef SP_DEVICE_INTERFACE_DETAIL_DATA_W
    PSP_INTERFACE_DEVICE_DETAIL_DATA_W typedef PSP_DEVICE_INTERFACE_DETAIL_DATA_W
    SP_INTERFACE_DEVICE_DETAIL_DATA_A typedef SP_DEVICE_INTERFACE_DETAIL_DATA_A
    PSP_INTERFACE_DEVICE_DETAIL_DATA_A typedef PSP_DEVICE_INTERFACE_DETAIL_DATA_A
    ifdef UNICODE
      SP_INTERFACE_DEVICE_DETAIL_DATA typedef SP_INTERFACE_DEVICE_DETAIL_DATA_W
      PSP_INTERFACE_DEVICE_DETAIL_DATA typedef PSP_INTERFACE_DEVICE_DETAIL_DATA_W
    else
      SP_INTERFACE_DEVICE_DETAIL_DATA typedef SP_INTERFACE_DEVICE_DETAIL_DATA_A
      PSP_INTERFACE_DEVICE_DETAIL_DATA typedef PSP_INTERFACE_DEVICE_DETAIL_DATA_A
    endif
    ; Structure for detailed information on a device information set (used for
    ; SetupDiGetDeviceInfoListDetail which supercedes the functionality of
    ; SetupDiGetDeviceInfoListClass).
    SP_DEVINFO_LIST_DETAIL_DATA_A struct
      cbSize DWORD ?
      ClassGuid GUID <>
      RemoteMachineHandle HANDLE ?
      RemoteMachineName SBYTE SP_MAX_MACHINENAME_LENGTH dup (?)
    SP_DEVINFO_LIST_DETAIL_DATA_A ends
    _SP_DEVINFO_LIST_DETAIL_DATA_A typedef SP_DEVINFO_LIST_DETAIL_DATA_A
    PSP_DEVINFO_LIST_DETAIL_DATA_A typedef ptr SP_DEVINFO_LIST_DETAIL_DATA_A
    SP_DEVINFO_LIST_DETAIL_DATA_W struct
      cbSize DWORD ?
      ClassGuid GUID <>
      RemoteMachineHandle HANDLE ?
      RemoteMachineName WORD SP_MAX_MACHINENAME_LENGTH dup (?)
    SP_DEVINFO_LIST_DETAIL_DATA_W ends
    _SP_DEVINFO_LIST_DETAIL_DATA_W typedef SP_DEVINFO_LIST_DETAIL_DATA_W
    PSP_DEVINFO_LIST_DETAIL_DATA_W typedef ptr SP_DEVINFO_LIST_DETAIL_DATA_W
    ifdef UNICODE
      SP_DEVINFO_LIST_DETAIL_DATA typedef SP_DEVINFO_LIST_DETAIL_DATA_W
      PSP_DEVINFO_LIST_DETAIL_DATA typedef PSP_DEVINFO_LIST_DETAIL_DATA_W
    else
      SP_DEVINFO_LIST_DETAIL_DATA typedef SP_DEVINFO_LIST_DETAIL_DATA_A
      PSP_DEVINFO_LIST_DETAIL_DATA typedef PSP_DEVINFO_LIST_DETAIL_DATA_A
    endif
    ; Class installer function codes
    DIF_SELECTDEVICE equ 00000001h
    DIF_INSTALLDEVICE equ 00000002h
    DIF_ASSIGNRESOURCES equ 00000003h
    DIF_PROPERTIES equ 00000004h
    DIF_REMOVE equ 00000005h
    DIF_FIRSTTIMESETUP equ 00000006h
    DIF_FOUNDDEVICE equ 00000007h
    DIF_SELECTCLASSDRIVERS equ 00000008h
    DIF_VALIDATECLASSDRIVERS equ 00000009h
    DIF_INSTALLCLASSDRIVERS equ 0000000Ah
    DIF_CALCDISKSPACE equ 0000000Bh
    DIF_DESTROYPRIVATEDATA equ 0000000Ch
    DIF_VALIDATEDRIVER equ 0000000Dh
    DIF_DETECT equ 0000000Fh
    DIF_INSTALLWIZARD equ 00000010h
    DIF_DESTROYWIZARDDATA equ 00000011h
    DIF_PROPERTYCHANGE equ 00000012h
    DIF_ENABLECLASS equ 00000013h
    DIF_DETECTVERIFY equ 00000014h
    DIF_INSTALLDEVICEFILES equ 00000015h
    DIF_UNREMOVE equ 00000016h
    DIF_SELECTBESTCOMPATDRV equ 00000017h
    DIF_ALLOW_INSTALL equ 00000018h
    DIF_REGISTERDEVICE equ 00000019h
    DIF_NEWDEVICEWIZARD_PRESELECT equ 0000001Ah
    DIF_NEWDEVICEWIZARD_SELECT equ 0000001Bh
    DIF_NEWDEVICEWIZARD_PREANALYZE equ 0000001Ch
    DIF_NEWDEVICEWIZARD_POSTANALYZE equ 0000001Dh
    DIF_NEWDEVICEWIZARD_FINISHINSTALL equ 0000001Eh
    DIF_UNUSED1 equ 0000001Fh
    DIF_INSTALLINTERFACES equ 00000020h
    DIF_DETECTCANCEL equ 00000021h
    DIF_REGISTER_COINSTALLERS equ 00000022h
    DIF_ADDPROPERTYPAGE_ADVANCED equ 00000023h
    DIF_ADDPROPERTYPAGE_BASIC equ 00000024h
    DIF_RESERVED1 equ 00000025h
    DIF_TROUBLESHOOTER equ 00000026h
    DIF_POWERMESSAGEWAKE equ 00000027h
    DIF_ADDREMOTEPROPERTYPAGE_ADVANCED equ 00000028h
    DIF_UPDATEDRIVER_UI equ 00000029h
    DIF_FINISHINSTALL_ACTION equ 0000002Ah
    DIF_RESERVED2 equ 00000030h
    ; Obsoleted DIF codes (do not use)
    DIF_MOVEDEVICE equ 0000000Eh
    DI_FUNCTION typedef UINT
    ; Function type for device installer
    ; Device installation parameters structure (associated with a
    ; particular device information element, or globally with a device
    ; information set)
    SP_DEVINSTALL_PARAMS_A struct
      cbSize DWORD ?
      Flags DWORD ?
      FlagsEx DWORD ?
      hwndParent HWND ?
      InstallMsgHandler PSP_FILE_CALLBACK ?
      InstallMsgHandlerContext POINTER ?
      FileQueue HSPFILEQ ?
      ClassInstallReserved XWORD ?
      Reserved DWORD ?
      DriverPath SBYTE MAX_PATH dup (?)
    SP_DEVINSTALL_PARAMS_A ends
    _SP_DEVINSTALL_PARAMS_A typedef SP_DEVINSTALL_PARAMS_A
    PSP_DEVINSTALL_PARAMS_A typedef ptr SP_DEVINSTALL_PARAMS_A
    SP_DEVINSTALL_PARAMS_W struct
      cbSize DWORD ?
      Flags DWORD ?
      FlagsEx DWORD ?
      hwndParent HWND ?
      InstallMsgHandler PSP_FILE_CALLBACK ?
      InstallMsgHandlerContext POINTER ?
      FileQueue HSPFILEQ ?
      ClassInstallReserved XWORD ?
      Reserved DWORD ?
      DriverPath WORD MAX_PATH dup (?)
    SP_DEVINSTALL_PARAMS_W ends
    _SP_DEVINSTALL_PARAMS_W typedef SP_DEVINSTALL_PARAMS_W
    PSP_DEVINSTALL_PARAMS_W typedef ptr SP_DEVINSTALL_PARAMS_W
    ifdef UNICODE
      SP_DEVINSTALL_PARAMS typedef SP_DEVINSTALL_PARAMS_W
      PSP_DEVINSTALL_PARAMS typedef PSP_DEVINSTALL_PARAMS_W
    else
      SP_DEVINSTALL_PARAMS typedef SP_DEVINSTALL_PARAMS_A
      PSP_DEVINSTALL_PARAMS typedef PSP_DEVINSTALL_PARAMS_A
    endif
    ; SP_DEVINSTALL_PARAMS.Flags values
    ; Flags for choosing a device
    DI_SHOWOEM equ 00000001h; support Other... button

    DI_SHOWCOMPAT equ 00000002h; show compatibility list

    DI_SHOWCLASS equ 00000004h; show class list

    DI_SHOWALL equ 00000007h; both class & compat list shown

    DI_NOVCP equ 00000008h; don't create a new copy queue--use

    ; caller-supplied FileQueue
    DI_DIDCOMPAT equ 00000010h; Searched for compatible devices

    DI_DIDCLASS equ 00000020h; Searched for class devices

    DI_AUTOASSIGNRES equ 00000040h; No UI for resources if possible

    ; flags returned by DiInstallDevice to indicate need to reboot/restart
    DI_NEEDRESTART equ 00000080h; Reboot required to take effect

    DI_NEEDREBOOT equ 00000100h; ""

    ; flags for device installation
    DI_NOBROWSE equ 00000200h; no Browse... in InsertDisk

    ; Flags set by DiBuildDriverInfoList
    DI_MULTMFGS equ 00000400h; Set if multiple manufacturers in

    ; class driver list
    ; Flag indicates that device is disabled
    DI_DISABLED equ 00000800h; Set if device disabled

    ; Flags for Device/Class Properties
    DI_GENERALPAGE_ADDED equ 00001000h
    DI_RESOURCEPAGE_ADDED equ 00002000h
    ; Flag to indicate the setting properties for this Device (or class) caused a change
    ; so the Dev Mgr UI probably needs to be updatd.
    DI_PROPERTIES_CHANGE equ 00004000h
    ; Flag to indicate that the sorting from the INF file should be used.
    DI_INF_IS_SORTED equ 00008000h
    ; Flag to indicate that only the the INF specified by SP_DEVINSTALL_PARAMS.DriverPath
    ; should be searched.
    DI_ENUMSINGLEINF equ 00010000h
    ; Flag that prevents ConfigMgr from removing/re-enumerating devices during device
    ; registration, installation, and deletion.
    DI_DONOTCALLCONFIGMG equ 00020000h
    ; The following flag can be used to install a device disabled
    DI_INSTALLDISABLED equ 00040000h
    ; Flag that causes SetupDiBuildDriverInfoList to build a device's compatible driver
    ; list from its existing class driver list, instead of the normal INF search.
    DI_COMPAT_FROM_CLASS equ 00080000h
    ; This flag is set if the Class Install params should be used.
    DI_CLASSINSTALLPARAMS equ 00100000h
    ; This flag is set if the caller of DiCallClassInstaller does NOT
    ; want the internal default action performed if the Class installer
    ; returns ERROR_DI_DO_DEFAULT.
    DI_NODI_DEFAULTACTION equ 00200000h
    ; The setupx flag, DI_NOSYNCPROCESSING (0x00400000L) is not support in the Setup APIs.
    ; flags for device installation
    DI_QUIETINSTALL equ 00800000h; don't confuse the user with

    ; questions or excess info
    DI_NOFILECOPY equ 01000000h; No file Copy necessary

    DI_FORCECOPY equ 02000000h; Force files to be copied from install path

    DI_DRIVERPAGE_ADDED equ 04000000h; Prop provider added Driver page.

    DI_USECI_SELECTSTRINGS equ 08000000h; Use Class Installer Provided strings in the Select Device Dlg

    DI_OVERRIDE_INFFLAGS equ 10000000h; Override INF flags

    DI_PROPS_NOCHANGEUSAGE equ 20000000h; No Enable/Disable in General Props

    DI_NOSELECTICONS equ 40000000h; No small icons in select device dialogs

    DI_NOWRITE_IDS equ 80000000h; Don't write HW & Compat IDs on install

    ; SP_DEVINSTALL_PARAMS.FlagsEx values
    DI_FLAGSEX_RESERVED2 equ 00000001h; DI_FLAGSEX_USEOLDINFSEARCH is obsolete

    DI_FLAGSEX_RESERVED3 equ 00000002h; DI_FLAGSEX_AUTOSELECTRANK0 is obsolete

    DI_FLAGSEX_CI_FAILED equ 00000004h; Failed to Load/Call class installer

    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      DI_FLAGSEX_FINISHINSTALL_ACTION equ 00000008h; Class/co-installer wants to get a DIF_FINISH_INSTALL action in client context.

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    DI_FLAGSEX_DIDINFOLIST equ 00000010h; Did the Class Info List

    DI_FLAGSEX_DIDCOMPATINFO equ 00000020h; Did the Compat Info List

    DI_FLAGSEX_FILTERCLASSES equ 00000040h
    DI_FLAGSEX_SETFAILEDINSTALL equ 00000080h
    DI_FLAGSEX_DEVICECHANGE equ 00000100h
    DI_FLAGSEX_ALWAYSWRITEIDS equ 00000200h
    DI_FLAGSEX_PROPCHANGE_PENDING equ 00000400h; One or more device property sheets have had changes made

    ; to them, and need to have a DIF_PROPERTYCHANGE occur.
    DI_FLAGSEX_ALLOWEXCLUDEDDRVS equ 00000800h
    DI_FLAGSEX_NOUIONQUERYREMOVE equ 00001000h
    DI_FLAGSEX_USECLASSFORCOMPAT equ 00002000h; Use the device's class when building compat drv list.

    ; (Ignored if DI_COMPAT_FROM_CLASS flag is specified.)
    DI_FLAGSEX_RESERVED4 equ 00004000h; DI_FLAGSEX_OLDINF_IN_CLASSLIST is obsolete

    DI_FLAGSEX_NO_DRVREG_MODIFY equ 00008000h; Don't run AddReg and DelReg for device's software (driver) key.

    DI_FLAGSEX_IN_SYSTEM_SETUP equ 00010000h; Installation is occurring during initial system setup.

    DI_FLAGSEX_INET_DRIVER equ 00020000h; Driver came from Windows Update

    DI_FLAGSEX_APPENDDRIVERLIST equ 00040000h; Cause SetupDiBuildDriverInfoList to append

    ; a new driver list to an existing list.
    DI_FLAGSEX_PREINSTALLBACKUP equ 00080000h; not used

    DI_FLAGSEX_BACKUPONREPLACE equ 00100000h; not used

    DI_FLAGSEX_DRIVERLIST_FROM_URL equ 00200000h; build driver list from INF(s) retrieved from URL specified

    ; in SP_DEVINSTALL_PARAMS.DriverPath (empty string means
    ; Windows Update website)
    DI_FLAGSEX_RESERVED1 equ 00400000h
    DI_FLAGSEX_EXCLUDE_OLD_INET_DRIVERS equ 00800000h; Don't include old Internet drivers when building

    ; a driver list.
    ; Ignored on Windows Vista and later.
    DI_FLAGSEX_POWERPAGE_ADDED equ 01000000h; class installer added their own power page

    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      DI_FLAGSEX_FILTERSIMILARDRIVERS equ 02000000h; only include similar drivers in class list

      DI_FLAGSEX_INSTALLEDDRIVER equ 04000000h; only add the installed driver to the class or compat

      ; driver list.  Used in calls to SetupDiBuildDriverInfoList
      DI_FLAGSEX_NO_CLASSLIST_NODE_MERGE equ 08000000h; Don't remove identical driver nodes from the class list

      DI_FLAGSEX_ALTPLATFORM_DRVSEARCH equ 10000000h; Build driver list based on alternate platform information

      ; specified in associated file queue
      DI_FLAGSEX_RESTART_DEVICE_ONLY equ 20000000h; only restart the device drivers are being installed on as

      ; opposed to restarting all devices using those drivers.
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      DI_FLAGSEX_RECURSIVESEARCH equ 40000000h; Tell SetupDiBuildDriverInfoList to do a recursive search

      DI_FLAGSEX_SEARCH_PUBLISHED_INFS equ 80000000h; Tell SetupDiBuildDriverInfoList to do a "published INF" search

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    ; Class installation parameters header.  This must be the first field of any
    ; class install parameter structure.  The InstallFunction field must be set to
    ; the function code corresponding to the structure, and the cbSize field must
    ; be set to the size of the header structure.  E.g.,
    ; SP_ENABLECLASS_PARAMS EnableClassParams;
    ; EnableClassParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
    ; EnableClassParams.ClassInstallHeader.InstallFunction = DIF_ENABLECLASS;
    SP_CLASSINSTALL_HEADER struct
      cbSize DWORD ?
      InstallFunction DI_FUNCTION ?
    SP_CLASSINSTALL_HEADER ends
    _SP_CLASSINSTALL_HEADER typedef SP_CLASSINSTALL_HEADER
    PSP_CLASSINSTALL_HEADER typedef ptr SP_CLASSINSTALL_HEADER
    ; Structure corresponding to a DIF_ENABLECLASS install function.
    SP_ENABLECLASS_PARAMS struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      ClassGuid GUID <>
      EnableMessage DWORD ?
    SP_ENABLECLASS_PARAMS ends
    _SP_ENABLECLASS_PARAMS typedef SP_ENABLECLASS_PARAMS
    PSP_ENABLECLASS_PARAMS typedef ptr SP_ENABLECLASS_PARAMS
    ENABLECLASS_QUERY equ 0
    ENABLECLASS_SUCCESS equ 1
    ENABLECLASS_FAILURE equ 2
    ; Values indicating a change in a device's state
    DICS_ENABLE equ 00000001h
    DICS_DISABLE equ 00000002h
    DICS_PROPCHANGE equ 00000003h
    DICS_START equ 00000004h
    DICS_STOP equ 00000005h
    ; Values specifying the scope of a device property change
    DICS_FLAG_GLOBAL equ 00000001h; make change in all hardware profiles

    DICS_FLAG_CONFIGSPECIFIC equ 00000002h; make change in specified profile only

    DICS_FLAG_CONFIGGENERAL equ 00000004h; 1 or more hardware profile-specific

    ; changes to follow.
    ; Structure corresponding to a DIF_PROPERTYCHANGE install function.
    SP_PROPCHANGE_PARAMS struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      StateChange DWORD ?
      Scope DWORD ?
      HwProfile DWORD ?
    SP_PROPCHANGE_PARAMS ends
    _SP_PROPCHANGE_PARAMS typedef SP_PROPCHANGE_PARAMS
    PSP_PROPCHANGE_PARAMS typedef ptr SP_PROPCHANGE_PARAMS
    ; Structure corresponding to a DIF_REMOVE install function.
    SP_REMOVEDEVICE_PARAMS struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      Scope DWORD ?
      HwProfile DWORD ?
    SP_REMOVEDEVICE_PARAMS ends
    _SP_REMOVEDEVICE_PARAMS typedef SP_REMOVEDEVICE_PARAMS
    PSP_REMOVEDEVICE_PARAMS typedef ptr SP_REMOVEDEVICE_PARAMS
    DI_REMOVEDEVICE_GLOBAL equ 00000001h
    DI_REMOVEDEVICE_CONFIGSPECIFIC equ 00000002h
    ; Structure corresponding to a DIF_UNREMOVE install function.
    SP_UNREMOVEDEVICE_PARAMS struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      Scope DWORD ?
      HwProfile DWORD ?
    SP_UNREMOVEDEVICE_PARAMS ends
    _SP_UNREMOVEDEVICE_PARAMS typedef SP_UNREMOVEDEVICE_PARAMS
    PSP_UNREMOVEDEVICE_PARAMS typedef ptr SP_UNREMOVEDEVICE_PARAMS
    DI_UNREMOVEDEVICE_CONFIGSPECIFIC equ 00000002h
    ; Structure corresponding to a DIF_SELECTDEVICE install function.
    SP_SELECTDEVICE_PARAMS_A struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      Title_ SBYTE MAX_TITLE_LEN dup (?)
      Instructions SBYTE MAX_INSTRUCTION_LEN dup (?)
      ListLabel SBYTE MAX_LABEL_LEN dup (?)
      SubTitle_ SBYTE MAX_SUBTITLE_LEN dup (?)
      Reserved BYTE 2 dup (?)
      ; DWORD size alignment
    SP_SELECTDEVICE_PARAMS_A ends
    _SP_SELECTDEVICE_PARAMS_A typedef SP_SELECTDEVICE_PARAMS_A
    PSP_SELECTDEVICE_PARAMS_A typedef ptr SP_SELECTDEVICE_PARAMS_A
    SP_SELECTDEVICE_PARAMS_W struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      Title_ WORD MAX_TITLE_LEN dup (?)
      Instructions WORD MAX_INSTRUCTION_LEN dup (?)
      ListLabel WORD MAX_LABEL_LEN dup (?)
      SubTitle_ WORD MAX_SUBTITLE_LEN dup (?)
    SP_SELECTDEVICE_PARAMS_W ends
    _SP_SELECTDEVICE_PARAMS_W typedef SP_SELECTDEVICE_PARAMS_W
    PSP_SELECTDEVICE_PARAMS_W typedef ptr SP_SELECTDEVICE_PARAMS_W
    ifdef UNICODE
      SP_SELECTDEVICE_PARAMS typedef SP_SELECTDEVICE_PARAMS_W
      PSP_SELECTDEVICE_PARAMS typedef PSP_SELECTDEVICE_PARAMS_W
    else
      SP_SELECTDEVICE_PARAMS typedef SP_SELECTDEVICE_PARAMS_A
      PSP_SELECTDEVICE_PARAMS typedef PSP_SELECTDEVICE_PARAMS_A
    endif
    ; Callback routine for giving progress notification during detection
    TYPE_PDETECT_PROGRESS_NOTIFY typedef proto WIN_STD_CALL_CONV :PVOID, :DWORD
    PDETECT_PROGRESS_NOTIFY typedef ptr TYPE_PDETECT_PROGRESS_NOTIFY

    ; where:
    ;     ProgressNotifyParam - value supplied by caller requesting detection.
    ;     DetectComplete - Percent completion, to be incremented by class
    ;                      installer, as it steps thru its detection.
    ; Return Value - If TRUE, then detection is cancelled.  Allows caller
    ;                requesting detection to stop detection asap.
    ; Structure corresponding to a DIF_DETECT install function.
    SP_DETECTDEVICE_PARAMS struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      DetectProgressNotify PDETECT_PROGRESS_NOTIFY ?
      ProgressNotifyParam POINTER ?
    SP_DETECTDEVICE_PARAMS ends
    _SP_DETECTDEVICE_PARAMS typedef SP_DETECTDEVICE_PARAMS
    PSP_DETECTDEVICE_PARAMS typedef ptr SP_DETECTDEVICE_PARAMS
    ; 'Add New Device' installation wizard structure (backward-compatibility
    ; only--respond to DIF_NEWDEVICEWIZARD_* requests instead).
    ; Structure corresponding to a DIF_INSTALLWIZARD install function.
    ; (NOTE: This structure is also applicable for DIF_DESTROYWIZARDDATA,
    ; but DIF_INSTALLWIZARD is the associated function code in the class
    ; installation parameter structure in both cases.)
    ; Define maximum number of dynamic wizard pages that can be added to
    ; hardware install wizard.
    MAX_INSTALLWIZARD_DYNAPAGES equ 20
    SP_INSTALLWIZARD_DATA struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      Flags DWORD ?
      DynamicPages HPROPSHEETPAGE MAX_INSTALLWIZARD_DYNAPAGES dup (?)
      NumDynamicPages DWORD ?
      DynamicPageFlags DWORD ?
      PrivateFlags DWORD ?
      PrivateData LPARAM ?
      hwndWizardDlg HWND ?
    SP_INSTALLWIZARD_DATA ends
    _SP_INSTALLWIZARD_DATA typedef SP_INSTALLWIZARD_DATA
    PSP_INSTALLWIZARD_DATA typedef ptr SP_INSTALLWIZARD_DATA
    ; SP_INSTALLWIZARD_DATA.Flags values
    NDW_INSTALLFLAG_DIDFACTDEFS equ 00000001h
    NDW_INSTALLFLAG_HARDWAREALLREADYIN equ 00000002h
    NDW_INSTALLFLAG_NEEDRESTART equ <DI_NEEDRESTART>
    NDW_INSTALLFLAG_NEEDREBOOT equ <DI_NEEDREBOOT>
    NDW_INSTALLFLAG_NEEDSHUTDOWN equ 00000200h
    NDW_INSTALLFLAG_EXPRESSINTRO equ 00000400h
    NDW_INSTALLFLAG_SKIPISDEVINSTALLED equ 00000800h
    NDW_INSTALLFLAG_NODETECTEDDEVS equ 00001000h
    NDW_INSTALLFLAG_INSTALLSPECIFIC equ 00002000h
    NDW_INSTALLFLAG_SKIPCLASSLIST equ 00004000h
    NDW_INSTALLFLAG_CI_PICKED_OEM equ 00008000h
    NDW_INSTALLFLAG_PCMCIAMODE equ 00010000h
    NDW_INSTALLFLAG_PCMCIADEVICE equ 00020000h
    NDW_INSTALLFLAG_USERCANCEL equ 00040000h
    NDW_INSTALLFLAG_KNOWNCLASS equ 00080000h
    ; SP_INSTALLWIZARD_DATA.DynamicPageFlags values
    ; This flag is set if a Class installer has added pages to the install wizard.
    DYNAWIZ_FLAG_PAGESADDED equ 00000001h
    ; Set this flag if you jump to the analyze page, and want it to
    ; handle conflicts for you.  NOTE.  You will not get control back
    ; in the event of a conflict if you set this flag.
    DYNAWIZ_FLAG_ANALYZE_HANDLECONFLICT equ 00000008h
    ; The following flags are not used by the Windows NT hardware wizard.
    DYNAWIZ_FLAG_INSTALLDET_NEXT equ 00000002h
    DYNAWIZ_FLAG_INSTALLDET_PREV equ 00000004h
    ; Reserve a range of wizard page resource IDs for internal use.  Some of
    ; these IDs are for use by class installers that respond to the obsolete
    ; DIF_INSTALLWIZARD/DIF_DESTROYWIZARDDATA messages.  These IDs are listed
    ; below.
    MIN_IDD_DYNAWIZ_RESOURCE_ID equ 10000
    MAX_IDD_DYNAWIZ_RESOURCE_ID equ 11000
    ; Define wizard page resource IDs to be used when adding custom pages to the
    ; hardware install wizard via DIF_INSTALLWIZARD.  Pages marked with
    ; (CLASS INSTALLER PROVIDED) _must_ be supplied by the class installer if it
    ; responds to the DIF_INSTALLWIZARD request.
    ; Resource ID for the first page that the install wizard will go to after
    ; adding the class installer pages.  (CLASS INSTALLER PROVIDED)
    IDD_DYNAWIZ_FIRSTPAGE equ 10000
    ; Resource ID for the page that the Select Device page will go back to.
    ; (CLASS INSTALLER PROVIDED)
    IDD_DYNAWIZ_SELECT_PREVPAGE equ 10001
    ; Resource ID for the page that the Select Device page will go forward to.
    ; (CLASS INSTALLER PROVIDED)
    IDD_DYNAWIZ_SELECT_NEXTPAGE equ 10002
    ; Resource ID for the page that the Analyze dialog should go back to
    ; This will only be used in the event that there is a problem, and the user
    ; selects Back from the analyze proc. (CLASS INSTALLER PROVIDED)
    IDD_DYNAWIZ_ANALYZE_PREVPAGE equ 10003
    ; Resource ID for the page that the Analyze dialog should go to if it
    ; continues from the analyze proc. (CLASS INSTALLER PROVIDED)
    IDD_DYNAWIZ_ANALYZE_NEXTPAGE equ 10004
    ; Resource ID of the hardware install wizard's select device page.
    ; This ID can be used to go directly to the hardware install wizard's select
    ; device page.  (This is the resource ID of the Select Device wizard page
    ; retrieved via SetupDiGetWizardPage when SPWPT_SELECTDEVICE is the requested
    ; PageType.)
    IDD_DYNAWIZ_SELECTDEV_PAGE equ 10009
    ; Resource ID of the hardware install wizard's device analysis page.
    ; This ID can be use to go directly to the hardware install wizard's analysis
    ; page.
    IDD_DYNAWIZ_ANALYZEDEV_PAGE equ 10010
    ; Resource ID of the hardware install wizard's install detected devices page.
    ; This ID can be use to go directly to the hardware install wizard's install
    ; detected devices page.
    IDD_DYNAWIZ_INSTALLDETECTEDDEVS_PAGE equ 10011
    ; Resource ID of the hardware install wizard's select class page.
    ; This ID can be use to go directly to the hardware install wizard's select
    ; class page.
    IDD_DYNAWIZ_SELECTCLASS_PAGE equ 10012
    ; The following class installer-provided wizard page resource IDs are not used
    ; by the Windows NT hardware wizard.
    IDD_DYNAWIZ_INSTALLDETECTED_PREVPAGE equ 10006
    IDD_DYNAWIZ_INSTALLDETECTED_NEXTPAGE equ 10007
    IDD_DYNAWIZ_INSTALLDETECTED_NODEVS equ 10008
    ; Structure corresponding to the following DIF_NEWDEVICEWIZARD_* install
    ; functions:
    ;     DIF_NEWDEVICEWIZARD_PRESELECT
    ;     DIF_NEWDEVICEWIZARD_SELECT
    ;     DIF_NEWDEVICEWIZARD_PREANALYZE
    ;     DIF_NEWDEVICEWIZARD_POSTANALYZE
    ;     DIF_NEWDEVICEWIZARD_FINISHINSTALL
    SP_NEWDEVICEWIZARD_DATA struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      Flags DWORD ?
      ; presently unused--must be zero.
      DynamicPages HPROPSHEETPAGE MAX_INSTALLWIZARD_DYNAPAGES dup (?)
      NumDynamicPages DWORD ?
      hwndWizardDlg HWND ?
    SP_NEWDEVICEWIZARD_DATA ends
    _SP_NEWDEVICEWIZARD_DATA typedef SP_NEWDEVICEWIZARD_DATA
    PSP_NEWDEVICEWIZARD_DATA typedef ptr SP_NEWDEVICEWIZARD_DATA
    ; The same structure is also used for retrieval of property pages via the
    ; following install functions:
    ;     DIF_ADDPROPERTYPAGE_ADVANCED
    ;     DIF_ADDPROPERTYPAGE_BASIC
    ;     DIF_ADDREMOTEPROPERTYPAGE_ADVANCED
    SP_ADDPROPERTYPAGE_DATA typedef SP_NEWDEVICEWIZARD_DATA
    PSP_ADDPROPERTYPAGE_DATA typedef PSP_NEWDEVICEWIZARD_DATA
    ; Structure corresponding to the DIF_TROUBLESHOOTER install function
    SP_TROUBLESHOOTER_PARAMS_A struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      ChmFile SBYTE MAX_PATH dup (?)
      HtmlTroubleShooter SBYTE MAX_PATH dup (?)
    SP_TROUBLESHOOTER_PARAMS_A ends
    _SP_TROUBLESHOOTER_PARAMS_A typedef SP_TROUBLESHOOTER_PARAMS_A
    PSP_TROUBLESHOOTER_PARAMS_A typedef ptr SP_TROUBLESHOOTER_PARAMS_A
    SP_TROUBLESHOOTER_PARAMS_W struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      ChmFile WORD MAX_PATH dup (?)
      HtmlTroubleShooter WORD MAX_PATH dup (?)
    SP_TROUBLESHOOTER_PARAMS_W ends
    _SP_TROUBLESHOOTER_PARAMS_W typedef SP_TROUBLESHOOTER_PARAMS_W
    PSP_TROUBLESHOOTER_PARAMS_W typedef ptr SP_TROUBLESHOOTER_PARAMS_W
    ifdef UNICODE
      SP_TROUBLESHOOTER_PARAMS typedef SP_TROUBLESHOOTER_PARAMS_W
      PSP_TROUBLESHOOTER_PARAMS typedef PSP_TROUBLESHOOTER_PARAMS_W
    else
      SP_TROUBLESHOOTER_PARAMS typedef SP_TROUBLESHOOTER_PARAMS_A
      PSP_TROUBLESHOOTER_PARAMS typedef PSP_TROUBLESHOOTER_PARAMS_A
    endif
    ; Structure corresponding to the DIF_POWERMESSAGEWAKE install function
    SP_POWERMESSAGEWAKE_PARAMS_A struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      PowerMessageWake SBYTE LINE_LEN * 2 dup (?)
    SP_POWERMESSAGEWAKE_PARAMS_A ends
    _SP_POWERMESSAGEWAKE_PARAMS_A typedef SP_POWERMESSAGEWAKE_PARAMS_A
    PSP_POWERMESSAGEWAKE_PARAMS_A typedef ptr SP_POWERMESSAGEWAKE_PARAMS_A
    SP_POWERMESSAGEWAKE_PARAMS_W struct
      ClassInstallHeader SP_CLASSINSTALL_HEADER <>
      PowerMessageWake WORD LINE_LEN * 2 dup (?)
    SP_POWERMESSAGEWAKE_PARAMS_W ends
    _SP_POWERMESSAGEWAKE_PARAMS_W typedef SP_POWERMESSAGEWAKE_PARAMS_W
    PSP_POWERMESSAGEWAKE_PARAMS_W typedef ptr SP_POWERMESSAGEWAKE_PARAMS_W
    ifdef UNICODE
      SP_POWERMESSAGEWAKE_PARAMS typedef SP_POWERMESSAGEWAKE_PARAMS_W
      PSP_POWERMESSAGEWAKE_PARAMS typedef PSP_POWERMESSAGEWAKE_PARAMS_W
    else
      SP_POWERMESSAGEWAKE_PARAMS typedef SP_POWERMESSAGEWAKE_PARAMS_A
      PSP_POWERMESSAGEWAKE_PARAMS typedef PSP_POWERMESSAGEWAKE_PARAMS_A
    endif
    ; Driver information structure (member of a driver info list that may be associated
    ; with a particular device instance, or (globally) with a device information set)
    SP_DRVINFO_DATA_V2_A struct
      cbSize DWORD ?
      DriverType DWORD ?
      Reserved XWORD ?
      Description SBYTE LINE_LEN dup (?)
      MfgName SBYTE LINE_LEN dup (?)
      ProviderName SBYTE LINE_LEN dup (?)
      DriverDate FILETIME <>
      DriverVersion QWORD ?
    SP_DRVINFO_DATA_V2_A ends
    _SP_DRVINFO_DATA_V2_A typedef SP_DRVINFO_DATA_V2_A
    PSP_DRVINFO_DATA_V2_A typedef ptr SP_DRVINFO_DATA_V2_A
    SP_DRVINFO_DATA_V2_W struct
      cbSize DWORD ?
      DriverType DWORD ?
      Reserved XWORD ?
      Description WORD LINE_LEN dup (?)
      MfgName WORD LINE_LEN dup (?)
      ProviderName WORD LINE_LEN dup (?)
      DriverDate FILETIME <>
      DriverVersion QWORD ?
    SP_DRVINFO_DATA_V2_W ends
    _SP_DRVINFO_DATA_V2_W typedef SP_DRVINFO_DATA_V2_W
    PSP_DRVINFO_DATA_V2_W typedef ptr SP_DRVINFO_DATA_V2_W
    ; Version 1 of the SP_DRVINFO_DATA structures, used only for compatibility
    ; with Windows NT 4.0/Windows 95/98 SETUPAPI.DLL
    SP_DRVINFO_DATA_V1_A struct
      cbSize DWORD ?
      DriverType DWORD ?
      Reserved XWORD ?
      Description SBYTE LINE_LEN dup (?)
      MfgName SBYTE LINE_LEN dup (?)
      ProviderName SBYTE LINE_LEN dup (?)
    SP_DRVINFO_DATA_V1_A ends
    _SP_DRVINFO_DATA_V1_A typedef SP_DRVINFO_DATA_V1_A
    PSP_DRVINFO_DATA_V1_A typedef ptr SP_DRVINFO_DATA_V1_A
    SP_DRVINFO_DATA_V1_W struct
      cbSize DWORD ?
      DriverType DWORD ?
      Reserved XWORD ?
      Description WORD LINE_LEN dup (?)
      MfgName WORD LINE_LEN dup (?)
      ProviderName WORD LINE_LEN dup (?)
    SP_DRVINFO_DATA_V1_W ends
    _SP_DRVINFO_DATA_V1_W typedef SP_DRVINFO_DATA_V1_W
    PSP_DRVINFO_DATA_V1_W typedef ptr SP_DRVINFO_DATA_V1_W
    ifdef UNICODE
      SP_DRVINFO_DATA_V1 typedef SP_DRVINFO_DATA_V1_W
      PSP_DRVINFO_DATA_V1 typedef PSP_DRVINFO_DATA_V1_W
      SP_DRVINFO_DATA_V2 typedef SP_DRVINFO_DATA_V2_W
      PSP_DRVINFO_DATA_V2 typedef PSP_DRVINFO_DATA_V2_W
    else
      SP_DRVINFO_DATA_V1 typedef SP_DRVINFO_DATA_V1_A
      PSP_DRVINFO_DATA_V1 typedef PSP_DRVINFO_DATA_V1_A
      SP_DRVINFO_DATA_V2 typedef SP_DRVINFO_DATA_V2_A
      PSP_DRVINFO_DATA_V2 typedef PSP_DRVINFO_DATA_V2_A
    endif
    if USE_SP_DRVINFO_DATA_V1 or (_SETUPAPI_VER lt _WIN32_WINNT_WIN2K)
      ; use version 1 driver info data structure
      SP_DRVINFO_DATA_A typedef SP_DRVINFO_DATA_V1_A
      PSP_DRVINFO_DATA_A typedef PSP_DRVINFO_DATA_V1_A
      SP_DRVINFO_DATA_W typedef SP_DRVINFO_DATA_V1_W
      PSP_DRVINFO_DATA_W typedef PSP_DRVINFO_DATA_V1_W
      SP_DRVINFO_DATA typedef SP_DRVINFO_DATA_V1
      PSP_DRVINFO_DATA typedef PSP_DRVINFO_DATA_V1
    else
    ; use version 2 driver info data structure
      SP_DRVINFO_DATA_A typedef SP_DRVINFO_DATA_V2_A
      PSP_DRVINFO_DATA_A typedef PSP_DRVINFO_DATA_V2_A
      SP_DRVINFO_DATA_W typedef SP_DRVINFO_DATA_V2_W
      PSP_DRVINFO_DATA_W typedef PSP_DRVINFO_DATA_V2_W
      SP_DRVINFO_DATA typedef SP_DRVINFO_DATA_V2
      PSP_DRVINFO_DATA typedef PSP_DRVINFO_DATA_V2
    endif
    ; use current version of driver info data structure
    ; Driver information details structure (provides detailed information about a
    ; particular driver information structure)
    SP_DRVINFO_DETAIL_DATA_A struct
      cbSize DWORD ?
      InfDate FILETIME <>
      CompatIDsOffset DWORD ?
      CompatIDsLength DWORD ?
      Reserved XWORD ?
      SectionName SBYTE LINE_LEN dup (?)
      InfFileName SBYTE MAX_PATH dup (?)
      DrvDescription SBYTE LINE_LEN dup (?)
      HardwareID SBYTE ANYSIZE_ARRAY dup (?)
    SP_DRVINFO_DETAIL_DATA_A ends
    _SP_DRVINFO_DETAIL_DATA_A typedef SP_DRVINFO_DETAIL_DATA_A
    PSP_DRVINFO_DETAIL_DATA_A typedef ptr SP_DRVINFO_DETAIL_DATA_A
    SP_DRVINFO_DETAIL_DATA_W struct
      cbSize DWORD ?
      InfDate FILETIME <>
      CompatIDsOffset DWORD ?
      CompatIDsLength DWORD ?
      Reserved XWORD ?
      SectionName WORD LINE_LEN dup (?)
      InfFileName WORD MAX_PATH dup (?)
      DrvDescription WORD LINE_LEN dup (?)
      HardwareID WORD ANYSIZE_ARRAY dup (?)
    SP_DRVINFO_DETAIL_DATA_W ends
    _SP_DRVINFO_DETAIL_DATA_W typedef SP_DRVINFO_DETAIL_DATA_W
    PSP_DRVINFO_DETAIL_DATA_W typedef ptr SP_DRVINFO_DETAIL_DATA_W
    ifdef UNICODE
      SP_DRVINFO_DETAIL_DATA typedef SP_DRVINFO_DETAIL_DATA_W
      PSP_DRVINFO_DETAIL_DATA typedef PSP_DRVINFO_DETAIL_DATA_W
    else
      SP_DRVINFO_DETAIL_DATA typedef SP_DRVINFO_DETAIL_DATA_A
      PSP_DRVINFO_DETAIL_DATA typedef PSP_DRVINFO_DETAIL_DATA_A
    endif
    ; Driver installation parameters (associated with a particular driver
    ; information element)
    SP_DRVINSTALL_PARAMS struct
      cbSize DWORD ?
      Rank DWORD ?
      Flags DWORD ?
      PrivateData XWORD ?
      Reserved DWORD ?
    SP_DRVINSTALL_PARAMS ends
    _SP_DRVINSTALL_PARAMS typedef SP_DRVINSTALL_PARAMS
    PSP_DRVINSTALL_PARAMS typedef ptr SP_DRVINSTALL_PARAMS
    ; SP_DRVINSTALL_PARAMS.Flags values
    DNF_DUPDESC equ 00000001h; Multiple providers have same desc

    DNF_OLDDRIVER equ 00000002h; Driver node specifies old/current driver

    DNF_EXCLUDEFROMLIST equ 00000004h; If set, this driver node will not be

    ; displayed in any driver select dialogs.
    DNF_NODRIVER equ 00000008h; if we want to install no driver

    ; (e.g no mouse drv)
    DNF_LEGACYINF equ 00000010h; Driver node came from an old-style INF (obsolete)

    DNF_CLASS_DRIVER equ 00000020h; Driver node represents a class driver

    DNF_COMPATIBLE_DRIVER equ 00000040h; Driver node represents a compatible driver

    DNF_INET_DRIVER equ 00000080h; Driver comes from an internet source

    DNF_UNUSED1 equ 00000100h
    DNF_UNUSED2 equ 00000200h
    DNF_OLD_INET_DRIVER equ 00000400h; Driver came from the Internet, but we don't currently

    ; have access to it's source files.  Never attempt to
    ; install a driver with this flag!
    ; Note used on Windows Vista and Later.
    DNF_BAD_DRIVER equ 00000800h; Driver node should not be used at all

    DNF_DUPPROVIDER equ 00001000h; Multiple drivers have the same provider and desc

    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      DNF_INF_IS_SIGNED equ 00002000h; If file is digitally signed

      DNF_OEM_F6_INF equ 00004000h; INF specified from F6 during textmode setup.

      DNF_DUPDRIVERVER equ 00008000h; Multipe drivers have the same desc, provider, and DriverVer values

      DNF_BASIC_DRIVER equ 00010000h; Driver provides basic functionality, but should

      ; not be chosen if other signed drivers exist.
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WS03
      DNF_AUTHENTICODE_SIGNED equ 00020000h; Inf file is signed by an Authenticode(tm) catalog.

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WS03
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      DNF_INSTALLEDDRIVER equ 00040000h; This driver node is currently installed on the device.

      DNF_ALWAYSEXCLUDEFROMLIST equ 00080000h; If set, this driver is not even displayed in

      ; alternative platform either.
      DNF_INBOX_DRIVER equ 00100000h; This driver node came from an INF that shipped with Windows.

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    if _SETUPAPI_VER ge _WIN32_WINNT_WIN7
      DNF_REQUESTADDITIONALSOFTWARE equ 00200000h; This driver is only part of a software solution needed

      ; by this device
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WIN7
    DNF_UNUSED_22 equ 00400000h
    DNF_UNUSED_23 equ 00800000h
    DNF_UNUSED_24 equ 01000000h
    DNF_UNUSED_25 equ 02000000h
    DNF_UNUSED_26 equ 04000000h
    DNF_UNUSED_27 equ 08000000h
    DNF_UNUSED_28 equ 10000000h
    DNF_UNUSED_29 equ 20000000h
    DNF_UNUSED_30 equ 40000000h
    DNF_UNUSED_31 equ 80000000h
    ; Rank values (the lower the Rank number, the better the Rank)
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      DRIVER_HARDWAREID_RANK equ 00000FFFh; Any rank less than or equal to

      ; this value is a gold
      ; HardwareID match
      DRIVER_HARDWAREID_MASK equ 80000FFFh; If you mask these bits off (AND)

      ; from the Rank and the result is 0
      ; then the Rank is a trusted HardwareID
      ; match
      DRIVER_UNTRUSTED_RANK equ 80000000h; Any rank with this bit set is an

      ; "untrusted" rank, meaning that
      ; the INF was unsigned.
      DRIVER_W9X_SUSPECT_RANK equ 0C0000000h; Any rank that is greater than

      ; or equal to this value, and lesser
      ; than or equal to 0xFFFF is suspected
      ; to be a Win9x-only driver, because
      ; (a) it isn't signed, and (b) there
      ; is no NT-specific decoration to
      ; explicitly indicate that the INF
      ; supports Windows NT/2000/XP
    else
      DRIVER_HARDWAREID_RANK equ 00000FFFh; Any rank less than or equal to

      ; this value is a trusted
      ; HardwareID match
      DRIVER_COMPATID_RANK equ 00003FFFh; Any rank less than or equal to

      ; this (and greater than
      ; DRIVER_HARDWAREID_RANK) is a
      ; trusted CompatibleID match
      DRIVER_UNTRUSTED_RANK equ 00008000h; Any rank with this bit set is an

      ; "untrusted" rank, meaning that
      ; the INF was unsigned.
      DRIVER_UNTRUSTED_HARDWAREID_RANK equ 00008FFFh; Any rank less than or equal to

      ; this value (and greater than
      ; or equal to DRIVER_UNTRUSTED_RANK)
      ; is an untrusted HardwareID match
      DRIVER_UNTRUSTED_COMPATID_RANK equ 0000BFFFh; Any rank less than or equal to

      ; this value (and greater than
      ; DRIVER_UNTRUSTED_HARDWAREID_RANK)
      ; is an untrusted CompatibleID match
      DRIVER_W9X_SUSPECT_RANK equ 0000C000h; Any rank that is greater than

      ; or equal to this value, and lesser
      ; than or equal to 0xFFFF is suspected
      ; to be a Win9x-only driver, because
      ; (a) it isn't signed, and (b) there
      ; is no NT-specific decoration to
      ; explicitly indicate that the INF
      ; supports Windows NT/2000/XP
      DRIVER_W9X_SUSPECT_HARDWAREID_RANK equ 0000CFFFh; Any rank less than or equal to this

      ; (and greater than or equal to
      ; DRIVER_W9X_SUSPECT_RANK) is a
      ; hardware ID match suspected of being
      ; only for Windows 9x platforms.
      DRIVER_W9X_SUSPECT_COMPATID_RANK equ 0000FFFFh; Any rank less than or equal to

      ; this (and greater than
      ; DRIVER_W9X_SUSPECT_HARDWAREID_RANK)
      ; is a compatible ID match suspected
      ; of being only for Windows 9x
      ; platforms.
    endif
    ; _SETUPAPI_VER < _WIN32_WINNT_LONGHORN
    ; Setup callback routine for comparing detection signatures
    TYPE_PSP_DETSIG_CMPPROC typedef proto WIN_STD_CALL_CONV :HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DEVINFO_DATA, :PVOID
    PSP_DETSIG_CMPPROC typedef ptr TYPE_PSP_DETSIG_CMPPROC

    ; Define context structure handed to co-installers
    COINSTALLER_CONTEXT_DATA struct
      PostProcessing DWORD ?
      InstallResult DWORD ?
      PrivateData POINTER ?
    COINSTALLER_CONTEXT_DATA ends
    _COINSTALLER_CONTEXT_DATA typedef COINSTALLER_CONTEXT_DATA
    PCOINSTALLER_CONTEXT_DATA typedef ptr COINSTALLER_CONTEXT_DATA
    ; Structure containing class image list information.
    SP_CLASSIMAGELIST_DATA struct
      cbSize DWORD ?
      ImageList HIMAGELIST ?
      Reserved XWORD ?
    SP_CLASSIMAGELIST_DATA ends
    _SP_CLASSIMAGELIST_DATA typedef SP_CLASSIMAGELIST_DATA
    PSP_CLASSIMAGELIST_DATA typedef ptr SP_CLASSIMAGELIST_DATA
    ; Structure to be passed as first parameter (LPVOID lpv) to ExtensionPropSheetPageProc
    ; entry point in setupapi.dll or to "EnumPropPages32" or "BasicProperties32" entry
    ; points provided by class/device property page providers.  Used to retrieve a handle
    ; (or, potentially, multiple handles) to property pages for a specified property page type.
    SP_PROPSHEETPAGE_REQUEST struct
      cbSize DWORD ?
      PageRequested DWORD ?
      DeviceInfoSet HDEVINFO ?
      DeviceInfoData PSP_DEVINFO_DATA ?
    SP_PROPSHEETPAGE_REQUEST ends
    _SP_PROPSHEETPAGE_REQUEST typedef SP_PROPSHEETPAGE_REQUEST
    PSP_PROPSHEETPAGE_REQUEST typedef ptr SP_PROPSHEETPAGE_REQUEST
    ; Property sheet codes used in SP_PROPSHEETPAGE_REQUEST.PageRequested
    SPPSR_SELECT_DEVICE_RESOURCES equ 1; supplied by setupapi.dll

    SPPSR_ENUM_BASIC_DEVICE_PROPERTIES equ 2; supplied by device's BasicProperties32 provider

    SPPSR_ENUM_ADV_DEVICE_PROPERTIES equ 3; supplied by class and/or device's EnumPropPages32 provider

    ; Structure used with SetupGetBackupInformation/SetupSetBackupInformation
    SP_BACKUP_QUEUE_PARAMS_V2_A struct
      cbSize DWORD ?
      ; size of structure
      FullInfPath SBYTE MAX_PATH dup (?)
      ; buffer to hold ANSI pathname of INF file
      FilenameOffset SDWORD ?
      ; offset in CHAR's of filename part (after '\')
      ReinstallInstance SBYTE MAX_PATH dup (?)
      ; Instance ID (if present)
    SP_BACKUP_QUEUE_PARAMS_V2_A ends
    _SP_BACKUP_QUEUE_PARAMS_V2_A typedef SP_BACKUP_QUEUE_PARAMS_V2_A
    PSP_BACKUP_QUEUE_PARAMS_V2_A typedef ptr SP_BACKUP_QUEUE_PARAMS_V2_A
    SP_BACKUP_QUEUE_PARAMS_V2_W struct
      cbSize DWORD ?
      ; size of structure
      FullInfPath WORD MAX_PATH dup (?)
      ; buffer to hold UNICODE pathname of INF file
      FilenameOffset SDWORD ?
      ; offset in WCHAR's of filename part (after '\')
      ReinstallInstance WORD MAX_PATH dup (?)
      ; Instance ID (if present)
    SP_BACKUP_QUEUE_PARAMS_V2_W ends
    _SP_BACKUP_QUEUE_PARAMS_V2_W typedef SP_BACKUP_QUEUE_PARAMS_V2_W
    PSP_BACKUP_QUEUE_PARAMS_V2_W typedef ptr SP_BACKUP_QUEUE_PARAMS_V2_W
    ; Version 1 of the SP_BACKUP_QUEUE_PARAMS structures, used only for compatibility
    ; with Windows 2000/Windows 95/98/ME SETUPAPI.DLL
    SP_BACKUP_QUEUE_PARAMS_V1_A struct
      cbSize DWORD ?
      ; size of structure
      FullInfPath SBYTE MAX_PATH dup (?)
      ; buffer to hold ANSI pathname of INF file
      FilenameOffset SDWORD ?
      ; offset in CHAR's of filename part (after '\')
    SP_BACKUP_QUEUE_PARAMS_V1_A ends
    _SP_BACKUP_QUEUE_PARAMS_V1_A typedef SP_BACKUP_QUEUE_PARAMS_V1_A
    PSP_BACKUP_QUEUE_PARAMS_V1_A typedef ptr SP_BACKUP_QUEUE_PARAMS_V1_A
    SP_BACKUP_QUEUE_PARAMS_V1_W struct
      cbSize DWORD ?
      ; size of structure
      FullInfPath WORD MAX_PATH dup (?)
      ; buffer to hold UNICODE pathname of INF file
      FilenameOffset SDWORD ?
      ; offset in WCHAR's of filename part (after '\')
    SP_BACKUP_QUEUE_PARAMS_V1_W ends
    _SP_BACKUP_QUEUE_PARAMS_V1_W typedef SP_BACKUP_QUEUE_PARAMS_V1_W
    PSP_BACKUP_QUEUE_PARAMS_V1_W typedef ptr SP_BACKUP_QUEUE_PARAMS_V1_W
    ifdef UNICODE
      SP_BACKUP_QUEUE_PARAMS_V1 typedef SP_BACKUP_QUEUE_PARAMS_V1_W
      PSP_BACKUP_QUEUE_PARAMS_V1 typedef PSP_BACKUP_QUEUE_PARAMS_V1_W
      SP_BACKUP_QUEUE_PARAMS_V2 typedef SP_BACKUP_QUEUE_PARAMS_V2_W
      PSP_BACKUP_QUEUE_PARAMS_V2 typedef PSP_BACKUP_QUEUE_PARAMS_V2_W
    else
      SP_BACKUP_QUEUE_PARAMS_V1 typedef SP_BACKUP_QUEUE_PARAMS_V1_A
      PSP_BACKUP_QUEUE_PARAMS_V1 typedef PSP_BACKUP_QUEUE_PARAMS_V1_A
      SP_BACKUP_QUEUE_PARAMS_V2 typedef SP_BACKUP_QUEUE_PARAMS_V2_A
      PSP_BACKUP_QUEUE_PARAMS_V2 typedef PSP_BACKUP_QUEUE_PARAMS_V2_A
    endif
    if USE_SP_BACKUP_QUEUE_PARAMS_V1 or (_SETUPAPI_VER lt _WIN32_WINNT_WINXP)
      ; use version 1 driver info data structure
      SP_BACKUP_QUEUE_PARAMS_A typedef SP_BACKUP_QUEUE_PARAMS_V1_A
      PSP_BACKUP_QUEUE_PARAMS_A typedef PSP_BACKUP_QUEUE_PARAMS_V1_A
      SP_BACKUP_QUEUE_PARAMS_W typedef SP_BACKUP_QUEUE_PARAMS_V1_W
      PSP_BACKUP_QUEUE_PARAMS_W typedef PSP_BACKUP_QUEUE_PARAMS_V1_W
      SP_BACKUP_QUEUE_PARAMS typedef SP_BACKUP_QUEUE_PARAMS_V1
      PSP_BACKUP_QUEUE_PARAMS typedef PSP_BACKUP_QUEUE_PARAMS_V1
    else
    ; use version 2 driver info data structure
      SP_BACKUP_QUEUE_PARAMS_A typedef SP_BACKUP_QUEUE_PARAMS_V2_A
      PSP_BACKUP_QUEUE_PARAMS_A typedef PSP_BACKUP_QUEUE_PARAMS_V2_A
      SP_BACKUP_QUEUE_PARAMS_W typedef SP_BACKUP_QUEUE_PARAMS_V2_W
      PSP_BACKUP_QUEUE_PARAMS_W typedef PSP_BACKUP_QUEUE_PARAMS_V2_W
      SP_BACKUP_QUEUE_PARAMS typedef SP_BACKUP_QUEUE_PARAMS_V2
      PSP_BACKUP_QUEUE_PARAMS typedef PSP_BACKUP_QUEUE_PARAMS_V2
    endif
    ; use current version of driver info data structure
    ifndef _SPAPI_ERRORS
      _SPAPI_ERRORS equ <>
      ; Setupapi-specific error codes
      ; Inf parse outcomes
      ERROR_EXPECTED_SECTION_NAME equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 0)
      ERROR_BAD_SECTION_NAME_LINE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 1)
      ERROR_SECTION_NAME_TOO_LONG equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 2)
      ERROR_GENERAL_SYNTAX equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 3)
      ; Inf runtime errors
      ERROR_WRONG_INF_STYLE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 100h)
      ERROR_SECTION_NOT_FOUND equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 101h)
      ERROR_LINE_NOT_FOUND equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 102h)
      ERROR_NO_BACKUP equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 103h)
      ; Device Installer/other errors
      ERROR_NO_ASSOCIATED_CLASS equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 200h)
      ERROR_CLASS_MISMATCH equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 201h)
      ERROR_DUPLICATE_FOUND equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 202h)
      ERROR_NO_DRIVER_SELECTED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 203h)
      ERROR_KEY_DOES_NOT_EXIST equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 204h)
      ERROR_INVALID_DEVINST_NAME equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 205h)
      ERROR_INVALID_CLASS equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 206h)
      ERROR_DEVINST_ALREADY_EXISTS equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 207h)
      ERROR_DEVINFO_NOT_REGISTERED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 208h)
      ERROR_INVALID_REG_PROPERTY equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 209h)
      ERROR_NO_INF equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 20Ah)
      ERROR_NO_SUCH_DEVINST equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 20Bh)
      ERROR_CANT_LOAD_CLASS_ICON equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 20Ch)
      ERROR_INVALID_CLASS_INSTALLER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 20Dh)
      ERROR_DI_DO_DEFAULT equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 20Eh)
      ERROR_DI_NOFILECOPY equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 20Fh)
      ERROR_INVALID_HWPROFILE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 210h)
      ERROR_NO_DEVICE_SELECTED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 211h)
      ERROR_DEVINFO_LIST_LOCKED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 212h)
      ERROR_DEVINFO_DATA_LOCKED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 213h)
      ERROR_DI_BAD_PATH equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 214h)
      ERROR_NO_CLASSINSTALL_PARAMS equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 215h)
      ERROR_FILEQUEUE_LOCKED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 216h)
      ERROR_BAD_SERVICE_INSTALLSECT equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 217h)
      ERROR_NO_CLASS_DRIVER_LIST equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 218h)
      ERROR_NO_ASSOCIATED_SERVICE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 219h)
      ERROR_NO_DEFAULT_DEVICE_INTERFACE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 21Ah)
      ERROR_DEVICE_INTERFACE_ACTIVE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 21Bh)
      ERROR_DEVICE_INTERFACE_REMOVED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 21Ch)
      ERROR_BAD_INTERFACE_INSTALLSECT equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 21Dh)
      ERROR_NO_SUCH_INTERFACE_CLASS equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 21Eh)
      ERROR_INVALID_REFERENCE_STRING equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 21Fh)
      ERROR_INVALID_MACHINENAME equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 220h)
      ERROR_REMOTE_COMM_FAILURE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 221h)
      ERROR_MACHINE_UNAVAILABLE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 222h)
      ERROR_NO_CONFIGMGR_SERVICES equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 223h)
      ERROR_INVALID_PROPPAGE_PROVIDER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 224h)
      ERROR_NO_SUCH_DEVICE_INTERFACE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 225h)
      ERROR_DI_POSTPROCESSING_REQUIRED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 226h)
      ERROR_INVALID_COINSTALLER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 227h)
      ERROR_NO_COMPAT_DRIVERS equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 228h)
      ERROR_NO_DEVICE_ICON equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 229h)
      ERROR_INVALID_INF_LOGCONFIG equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 22Ah)
      ERROR_DI_DONT_INSTALL equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 22Bh)
      ERROR_INVALID_FILTER_DRIVER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 22Ch)
      ERROR_NON_WINDOWS_NT_DRIVER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 22Dh)
      ERROR_NON_WINDOWS_DRIVER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 22Eh)
      ERROR_NO_CATALOG_FOR_OEM_INF equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 22Fh)
      ERROR_DEVINSTALL_QUEUE_NONNATIVE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 230h)
      ERROR_NOT_DISABLEABLE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 231h)
      ERROR_CANT_REMOVE_DEVINST equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 232h)
      ERROR_INVALID_TARGET equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 233h)
      ERROR_DRIVER_NONNATIVE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 234h)
      ERROR_IN_WOW64 equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 235h)
      ERROR_SET_SYSTEM_RESTORE_POINT equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 236h)
      ERROR_SCE_DISABLED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 238h)
      ERROR_UNKNOWN_EXCEPTION equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 239h)
      ERROR_PNP_REGISTRY_ERROR equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 23Ah)
      ERROR_REMOTE_REQUEST_UNSUPPORTED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 23Bh)
      ERROR_NOT_AN_INSTALLED_OEM_INF equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 23Ch)
      ERROR_INF_IN_USE_BY_DEVICES equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 23Dh)
      ERROR_DI_FUNCTION_OBSOLETE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 23Eh)
      ERROR_NO_AUTHENTICODE_CATALOG equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 23Fh)
      ERROR_AUTHENTICODE_DISALLOWED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 240h)
      ERROR_AUTHENTICODE_TRUSTED_PUBLISHER equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 241h)
      ERROR_AUTHENTICODE_TRUST_NOT_ESTABLISHED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 242h)
      ERROR_AUTHENTICODE_PUBLISHER_NOT_TRUSTED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 243h)
      ERROR_SIGNATURE_OSATTRIBUTE_MISMATCH equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 244h)
      ERROR_ONLY_VALIDATE_VIA_AUTHENTICODE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 245h)
      ERROR_DEVICE_INSTALLER_NOT_READY equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 246h)
      ERROR_DRIVER_STORE_ADD_FAILED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 247h)
      ERROR_DEVICE_INSTALL_BLOCKED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 248h)
      ERROR_DRIVER_INSTALL_BLOCKED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 249h)
      ERROR_WRONG_INF_TYPE equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 24Ah)
      ERROR_FILE_HASH_NOT_IN_CATALOG equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 24Bh)
      ERROR_DRIVER_STORE_DELETE_FAILED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 24Ch)
      ; Setupapi exception codes
      ERROR_UNRECOVERABLE_STACK_OVERFLOW equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 300h)
      EXCEPTION_SPAPI_UNRECOVERABLE_STACK_OVERFLOW equ <ERROR_UNRECOVERABLE_STACK_OVERFLOW>
      ; Backward compatibility--do not use.
      ERROR_NO_DEFAULT_INTERFACE_DEVICE equ <ERROR_NO_DEFAULT_DEVICE_INTERFACE>
      ERROR_INTERFACE_DEVICE_ACTIVE equ <ERROR_DEVICE_INTERFACE_ACTIVE>
      ERROR_INTERFACE_DEVICE_REMOVED equ <ERROR_DEVICE_INTERFACE_REMOVED>
      ERROR_NO_SUCH_INTERFACE_DEVICE equ <ERROR_NO_SUCH_DEVICE_INTERFACE>
      ; Win9x migration DLL error code
      ERROR_NOT_INSTALLED equ (APPLICATION_ERROR_MASK or ERROR_SEVERITY_ERROR or 1000h)
    endif
    ; _SPAPI_ERRORS
    @DefProto DllImport, SetupGetInfInformationA, WIN_STD_CALL_CONV,, <:LPCVOID, :DWORD, :PSP_INF_INFORMATION, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupGetInfInformationW, WIN_STD_CALL_CONV,, <:LPCVOID, :DWORD, :PSP_INF_INFORMATION, :DWORD, :PDWORD>, 20
    ; SearchControl flags for SetupGetInfInformation
    INFINFO_INF_SPEC_IS_HINF equ 1
    INFINFO_INF_NAME_IS_ABSOLUTE equ 2
    INFINFO_DEFAULT_SEARCH equ 3
    INFINFO_REVERSE_DEFAULT_SEARCH equ 4
    INFINFO_INF_PATH_LIST_SEARCH equ 5
    ifdef UNICODE
      SetupGetInfInformation equ <SetupGetInfInformationW>
    else
      SetupGetInfInformation equ <SetupGetInfInformationA>
    endif
    @DefProto DllImport, SetupQueryInfFileInformationA, WIN_STD_CALL_CONV,, <:PSP_INF_INFORMATION, :UINT, :PSTR, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupQueryInfFileInformationW, WIN_STD_CALL_CONV,, <:PSP_INF_INFORMATION, :UINT, :PWSTR, :DWORD, :PDWORD>, 20
    ifdef UNICODE
      SetupQueryInfFileInformation equ <SetupQueryInfFileInformationW>
    else
      SetupQueryInfFileInformation equ <SetupQueryInfFileInformationA>
    endif
    @DefProto DllImport, SetupQueryInfOriginalFileInformationA, WIN_STD_CALL_CONV,, <:PSP_INF_INFORMATION, :UINT, :PSP_ALTPLATFORM_INFO, :PSP_ORIGINAL_FILE_INFO_A>, 16
    @DefProto DllImport, SetupQueryInfOriginalFileInformationW, WIN_STD_CALL_CONV,, <:PSP_INF_INFORMATION, :UINT, :PSP_ALTPLATFORM_INFO, :PSP_ORIGINAL_FILE_INFO_W>, 16
    ifdef UNICODE
      SetupQueryInfOriginalFileInformation equ <SetupQueryInfOriginalFileInformationW>
    else
      SetupQueryInfOriginalFileInformation equ <SetupQueryInfOriginalFileInformationA>
    endif
    @DefProto DllImport, SetupQueryInfVersionInformationA, WIN_STD_CALL_CONV,, <:PSP_INF_INFORMATION, :UINT, :PCSTR, :PSTR, :DWORD, :PDWORD>, 24
    @DefProto DllImport, SetupQueryInfVersionInformationW, WIN_STD_CALL_CONV,, <:PSP_INF_INFORMATION, :UINT, :PCWSTR, :PWSTR, :DWORD, :PDWORD>, 24
    ifdef UNICODE
      SetupQueryInfVersionInformation equ <SetupQueryInfVersionInformationW>
    else
      SetupQueryInfVersionInformation equ <SetupQueryInfVersionInformationA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      @DefProto DllImport, SetupGetInfDriverStoreLocationA, WIN_STD_CALL_CONV,, <:PCSTR, :PSP_ALTPLATFORM_INFO, :PCSTR, :PSTR, :DWORD, :PDWORD>, 24
      @DefProto DllImport, SetupGetInfDriverStoreLocationW, WIN_STD_CALL_CONV,, <:PCWSTR, :PSP_ALTPLATFORM_INFO, :PCWSTR, :PWSTR, :DWORD, :PDWORD>, 24
      ifdef UNICODE
        SetupGetInfDriverStoreLocation equ <SetupGetInfDriverStoreLocationW>
      else
        SetupGetInfDriverStoreLocation equ <SetupGetInfDriverStoreLocationA>
      endif
      @DefProto DllImport, SetupGetInfPublishedNameA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :DWORD, :PDWORD>, 16
      @DefProto DllImport, SetupGetInfPublishedNameW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :DWORD, :PDWORD>, 16
      ifdef UNICODE
        SetupGetInfPublishedName equ <SetupGetInfPublishedNameW>
      else
        SetupGetInfPublishedName equ <SetupGetInfPublishedNameA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    @DefProto DllImport, SetupGetInfFileListA, WIN_STD_CALL_CONV,, <:PCSTR, :DWORD, :PSTR, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupGetInfFileListW, WIN_STD_CALL_CONV,, <:PCWSTR, :DWORD, :PWSTR, :DWORD, :PDWORD>, 20
    ifdef UNICODE
      SetupGetInfFileList equ <SetupGetInfFileListW>
    else
      SetupGetInfFileList equ <SetupGetInfFileListA>
    endif
    @DefProto DllImport, SetupOpenInfFileW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :DWORD, :PUINT>, 16
    @DefProto DllImport, SetupOpenInfFileA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :DWORD, :PUINT>, 16
    ifdef UNICODE
      SetupOpenInfFile equ <SetupOpenInfFileW>
    else
      SetupOpenInfFile equ <SetupOpenInfFileA>
    endif
    @DefProto DllImport, SetupOpenMasterInf, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetupOpenAppendInfFileW, WIN_STD_CALL_CONV,, <:PCWSTR, :HINF, :PUINT>, 12
    @DefProto DllImport, SetupOpenAppendInfFileA, WIN_STD_CALL_CONV,, <:PCSTR, :HINF, :PUINT>, 12
    ifdef UNICODE
      SetupOpenAppendInfFile equ <SetupOpenAppendInfFileW>
    else
      SetupOpenAppendInfFile equ <SetupOpenAppendInfFileA>
    endif
    @DefProto DllImport, SetupCloseInfFile, WIN_STD_CALL_CONV,, <:HINF>, 4
    @DefProto DllImport, SetupFindFirstLineA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :PCSTR, :PINFCONTEXT>, 16
    @DefProto DllImport, SetupFindFirstLineW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :PCWSTR, :PINFCONTEXT>, 16
    ifdef UNICODE
      SetupFindFirstLine equ <SetupFindFirstLineW>
    else
      SetupFindFirstLine equ <SetupFindFirstLineA>
    endif
    @DefProto DllImport, SetupFindNextLine, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :PINFCONTEXT>, 8
    @DefProto DllImport, SetupFindNextMatchLineA, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :PCSTR, :PINFCONTEXT>, 12
    @DefProto DllImport, SetupFindNextMatchLineW, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :PCWSTR, :PINFCONTEXT>, 12
    ifdef UNICODE
      SetupFindNextMatchLine equ <SetupFindNextMatchLineW>
    else
      SetupFindNextMatchLine equ <SetupFindNextMatchLineA>
    endif
    @DefProto DllImport, SetupGetLineByIndexA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :DWORD, :PINFCONTEXT>, 16
    @DefProto DllImport, SetupGetLineByIndexW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :DWORD, :PINFCONTEXT>, 16
    ifdef UNICODE
      SetupGetLineByIndex equ <SetupGetLineByIndexW>
    else
      SetupGetLineByIndex equ <SetupGetLineByIndexA>
    endif
    @DefProto DllImport, SetupGetLineCountA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR>, 8
    @DefProto DllImport, SetupGetLineCountW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR>, 8
    ifdef UNICODE
      SetupGetLineCount equ <SetupGetLineCountW>
    else
      SetupGetLineCount equ <SetupGetLineCountA>
    endif
    @DefProto DllImport, SetupGetLineTextA, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :HINF, :PCSTR, :PCSTR, :PSTR, :DWORD, :PDWORD>, 28
    @DefProto DllImport, SetupGetLineTextW, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :HINF, :PCWSTR, :PCWSTR, :PWSTR, :DWORD, :PDWORD>, 28
    ifdef UNICODE
      SetupGetLineText equ <SetupGetLineTextW>
    else
      SetupGetLineText equ <SetupGetLineTextA>
    endif
    @DefProto DllImport, SetupGetFieldCount, WIN_STD_CALL_CONV,, <:PINFCONTEXT>, 4
    @DefProto DllImport, SetupGetStringFieldA, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :DWORD, :PSTR, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupGetStringFieldW, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :DWORD, :PWSTR, :DWORD, :PDWORD>, 20
    ifdef UNICODE
      SetupGetStringField equ <SetupGetStringFieldW>
    else
      SetupGetStringField equ <SetupGetStringFieldA>
    endif
    @DefProto DllImport, SetupGetIntField, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :DWORD, :PINT>, 12
    @DefProto DllImport, SetupGetMultiSzFieldA, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :DWORD, :PSTR, :DWORD, :LPDWORD>, 20
    @DefProto DllImport, SetupGetMultiSzFieldW, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :DWORD, :PWSTR, :DWORD, :LPDWORD>, 20
    ifdef UNICODE
      SetupGetMultiSzField equ <SetupGetMultiSzFieldW>
    else
      SetupGetMultiSzField equ <SetupGetMultiSzFieldA>
    endif
    @DefProto DllImport, SetupGetBinaryField, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :DWORD, :PBYTE, :DWORD, :LPDWORD>, 20
    ; SetupGetFileCompressionInfo is depreciated
    ; use SetupGetFileCompressionInfoEx instead
    ; ActualSourceFileName returned by SetupGetFileCompressionInfo
    ; must be freed by the export setupapi!MyFree (NT4+ Win95+)
    ; or LocalFree (Win2k+)
    @DefProto DllImport, SetupGetFileCompressionInfoA, WIN_STD_CALL_CONV,, <:PCSTR, :ptr PSTR, :PDWORD, :PDWORD, :PUINT>, 20
    @DefProto DllImport, SetupGetFileCompressionInfoW, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PWSTR, :PDWORD, :PDWORD, :PUINT>, 20
    ifdef UNICODE
      SetupGetFileCompressionInfo equ <SetupGetFileCompressionInfoW>
    else
      SetupGetFileCompressionInfo equ <SetupGetFileCompressionInfoA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; SetupGetFileCompressionInfoEx is the preferred API over
      ; SetupGetFileCompressionInfo. It follows the normal
      ; conventions of returning BOOL and writing to user-supplied
      ; buffer.
      @DefProto DllImport, SetupGetFileCompressionInfoExA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :DWORD, :PDWORD, :PDWORD, :PDWORD, :PUINT>, 28
      @DefProto DllImport, SetupGetFileCompressionInfoExW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :DWORD, :PDWORD, :PDWORD, :PDWORD, :PUINT>, 28
      ifdef UNICODE
        SetupGetFileCompressionInfoEx equ <SetupGetFileCompressionInfoExW>
      else
        SetupGetFileCompressionInfoEx equ <SetupGetFileCompressionInfoExA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Compression types
    FILE_COMPRESSION_NONE equ 0
    FILE_COMPRESSION_WINLZA equ 1
    FILE_COMPRESSION_MSZIP equ 2
    FILE_COMPRESSION_NTCAB equ 3
    @DefProto DllImport, SetupDecompressOrCopyFileA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :PUINT>, 12
    @DefProto DllImport, SetupDecompressOrCopyFileW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :PUINT>, 12
    ifdef UNICODE
      SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileW>
    else
      SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileA>
    endif
    @DefProto DllImport, SetupGetSourceFileLocationA, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCSTR, :PUINT, :PSTR, :DWORD, :PDWORD>, 28
    @DefProto DllImport, SetupGetSourceFileLocationW, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCWSTR, :PUINT, :PWSTR, :DWORD, :PDWORD>, 28
    ifdef UNICODE
      SetupGetSourceFileLocation equ <SetupGetSourceFileLocationW>
    else
      SetupGetSourceFileLocation equ <SetupGetSourceFileLocationA>
    endif
    @DefProto DllImport, SetupGetSourceFileSizeA, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCSTR, :PCSTR, :PDWORD, :UINT>, 24
    @DefProto DllImport, SetupGetSourceFileSizeW, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCWSTR, :PCWSTR, :PDWORD, :UINT>, 24
    ifdef UNICODE
      SetupGetSourceFileSize equ <SetupGetSourceFileSizeW>
    else
      SetupGetSourceFileSize equ <SetupGetSourceFileSizeA>
    endif
    @DefProto DllImport, SetupGetTargetPathA, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCSTR, :PSTR, :DWORD, :PDWORD>, 24
    @DefProto DllImport, SetupGetTargetPathW, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCWSTR, :PWSTR, :DWORD, :PDWORD>, 24
    ifdef UNICODE
      SetupGetTargetPath equ <SetupGetTargetPathW>
    else
      SetupGetTargetPath equ <SetupGetTargetPathA>
    endif
    ; Define flags for SourceList APIs.
    SRCLIST_TEMPORARY equ 00000001h
    SRCLIST_NOBROWSE equ 00000002h
    SRCLIST_SYSTEM equ 00000010h
    SRCLIST_USER equ 00000020h
    SRCLIST_SYSIFADMIN equ 00000040h
    SRCLIST_SUBDIRS equ 00000100h
    SRCLIST_APPEND equ 00000200h
    SRCLIST_NOSTRIPPLATFORM equ 00000400h
    @DefProto DllImport, SetupSetSourceListA, WIN_STD_CALL_CONV,, <:DWORD, :ptr PCSTR, :UINT>, 12
    @DefProto DllImport, SetupSetSourceListW, WIN_STD_CALL_CONV,, <:DWORD, :ptr PCWSTR, :UINT>, 12
    ifdef UNICODE
      SetupSetSourceList equ <SetupSetSourceListW>
    else
      SetupSetSourceList equ <SetupSetSourceListA>
    endif
    @DefProto DllImport, SetupCancelTemporarySourceList, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetupAddToSourceListA, WIN_STD_CALL_CONV,, <:DWORD, :PCSTR>, 8
    @DefProto DllImport, SetupAddToSourceListW, WIN_STD_CALL_CONV,, <:DWORD, :PCWSTR>, 8
    ifdef UNICODE
      SetupAddToSourceList equ <SetupAddToSourceListW>
    else
      SetupAddToSourceList equ <SetupAddToSourceListA>
    endif
    @DefProto DllImport, SetupRemoveFromSourceListA, WIN_STD_CALL_CONV,, <:DWORD, :PCSTR>, 8
    @DefProto DllImport, SetupRemoveFromSourceListW, WIN_STD_CALL_CONV,, <:DWORD, :PCWSTR>, 8
    ifdef UNICODE
      SetupRemoveFromSourceList equ <SetupRemoveFromSourceListW>
    else
      SetupRemoveFromSourceList equ <SetupRemoveFromSourceListA>
    endif
    @DefProto DllImport, SetupQuerySourceListA, WIN_STD_CALL_CONV,, <:DWORD, :ptr ptr PCSTR, :PUINT>, 12
    @DefProto DllImport, SetupQuerySourceListW, WIN_STD_CALL_CONV,, <:DWORD, :ptr ptr PCWSTR, :PUINT>, 12
    ifdef UNICODE
      SetupQuerySourceList equ <SetupQuerySourceListW>
    else
      SetupQuerySourceList equ <SetupQuerySourceListA>
    endif
    @DefProto DllImport, SetupFreeSourceListA, WIN_STD_CALL_CONV,, <:ptr ptr PCSTR, :UINT>, 8
    @DefProto DllImport, SetupFreeSourceListW, WIN_STD_CALL_CONV,, <:ptr ptr PCWSTR, :UINT>, 8
    ifdef UNICODE
      SetupFreeSourceList equ <SetupFreeSourceListW>
    else
      SetupFreeSourceList equ <SetupFreeSourceListA>
    endif
    @DefProto DllImport, SetupPromptForDiskA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :DWORD, :PSTR, :DWORD, :PDWORD>, 40
    @DefProto DllImport, SetupPromptForDiskW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD, :PWSTR, :DWORD, :PDWORD>, 40
    ifdef UNICODE
      SetupPromptForDisk equ <SetupPromptForDiskW>
    else
      SetupPromptForDisk equ <SetupPromptForDiskA>
    endif
    @DefProto DllImport, SetupCopyErrorA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :UINT, :DWORD, :PSTR, :DWORD, :PDWORD>, 44
    @DefProto DllImport, SetupCopyErrorW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :UINT, :DWORD, :PWSTR, :DWORD, :PDWORD>, 44
    ifdef UNICODE
      SetupCopyError equ <SetupCopyErrorW>
    else
      SetupCopyError equ <SetupCopyErrorA>
    endif
    @DefProto DllImport, SetupRenameErrorA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :PCSTR, :PCSTR, :UINT, :DWORD>, 24
    @DefProto DllImport, SetupRenameErrorW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :PCWSTR, :PCWSTR, :UINT, :DWORD>, 24
    ifdef UNICODE
      SetupRenameError equ <SetupRenameErrorW>
    else
      SetupRenameError equ <SetupRenameErrorA>
    endif
    @DefProto DllImport, SetupDeleteErrorA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :PCSTR, :UINT, :DWORD>, 20
    @DefProto DllImport, SetupDeleteErrorW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :PCWSTR, :UINT, :DWORD>, 20
    ifdef UNICODE
      SetupDeleteError equ <SetupDeleteErrorW>
    else
      SetupDeleteError equ <SetupDeleteErrorA>
    endif
    @DefProto DllImport, SetupBackupErrorA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :PCSTR, :PCSTR, :UINT, :DWORD>, 24
    @DefProto DllImport, SetupBackupErrorW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :PCWSTR, :PCWSTR, :UINT, :DWORD>, 24
    ifdef UNICODE
      SetupBackupError equ <SetupBackupErrorW>
    else
      SetupBackupError equ <SetupBackupErrorA>
    endif
    ; Styles for SetupPromptForDisk, SetupCopyError,
    ; SetupRenameError, SetupDeleteError
    IDF_NOBROWSE equ 00000001h
    IDF_NOSKIP equ 00000002h
    IDF_NODETAILS equ 00000004h
    IDF_NOCOMPRESSED equ 00000008h
    IDF_CHECKFIRST equ 00000100h
    IDF_NOBEEP equ 00000200h
    IDF_NOFOREGROUND equ 00000400h
    IDF_WARNIFSKIP equ 00000800h
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      IDF_NOREMOVABLEMEDIAPROMPT equ 00001000h
      IDF_USEDISKNAMEASPROMPT equ 00002000h
      IDF_OEMDISK equ 80000000h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Return values for SetupPromptForDisk, SetupCopyError,
    ; SetupRenameError, SetupDeleteError, SetupBackupError
    DPROMPT_SUCCESS equ 0
    DPROMPT_CANCEL equ 1
    DPROMPT_SKIPFILE equ 2
    DPROMPT_BUFFERTOOSMALL equ 3
    DPROMPT_OUTOFMEMORY equ 4
    @DefProto DllImport, SetupSetDirectoryIdA, WIN_STD_CALL_CONV,, <:HINF, :DWORD, :PCSTR>, 12
    @DefProto DllImport, SetupSetDirectoryIdW, WIN_STD_CALL_CONV,, <:HINF, :DWORD, :PCWSTR>, 12
    ifdef UNICODE
      SetupSetDirectoryId equ <SetupSetDirectoryIdW>
    else
      SetupSetDirectoryId equ <SetupSetDirectoryIdA>
    endif
    @DefProto DllImport, SetupSetDirectoryIdExA, WIN_STD_CALL_CONV,, <:HINF, :DWORD, :PCSTR, :DWORD, :DWORD, :PVOID>, 24
    @DefProto DllImport, SetupSetDirectoryIdExW, WIN_STD_CALL_CONV,, <:HINF, :DWORD, :PCWSTR, :DWORD, :DWORD, :PVOID>, 24
    ifdef UNICODE
      SetupSetDirectoryIdEx equ <SetupSetDirectoryIdExW>
    else
      SetupSetDirectoryIdEx equ <SetupSetDirectoryIdExA>
    endif
    ; Flags for SetupSetDirectoryIdEx
    SETDIRID_NOT_FULL_PATH equ 00000001h
    @DefProto DllImport, SetupGetSourceInfoA, WIN_STD_CALL_CONV,, <:HINF, :UINT, :UINT, :PSTR, :DWORD, :PDWORD>, 24
    @DefProto DllImport, SetupGetSourceInfoW, WIN_STD_CALL_CONV,, <:HINF, :UINT, :UINT, :PWSTR, :DWORD, :PDWORD>, 24
    ifdef UNICODE
      SetupGetSourceInfo equ <SetupGetSourceInfoW>
    else
      SetupGetSourceInfo equ <SetupGetSourceInfoA>
    endif
    ; InfoDesired values for SetupGetSourceInfo
    SRCINFO_PATH equ 1
    SRCINFO_TAGFILE equ 2
    SRCINFO_DESCRIPTION equ 3
    SRCINFO_FLAGS equ 4
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; SRC_FLAGS allow special treatment of source
      ; lower 4 bits are reserved for OS use
      ; the flags may determine what other parameters exist
      SRCINFO_TAGFILE2 equ 5; alternate tagfile, when SRCINFO_TAGFILE is a cabfile

      SRC_FLAGS_CABFILE equ (0010h); if set, treat SRCINFO_TAGFILE as a cabfile and specify alternate tagfile

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    @DefProto DllImport, SetupInstallFileA, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCSTR, :PCSTR, :PCSTR, :DWORD, :PSP_FILE_CALLBACK_A, :PVOID>, 32
    @DefProto DllImport, SetupInstallFileW, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD, :PSP_FILE_CALLBACK_W, :PVOID>, 32
    ifdef UNICODE
      SetupInstallFile equ <SetupInstallFileW>
    else
      SetupInstallFile equ <SetupInstallFileA>
    endif
    @DefProto DllImport, SetupInstallFileExA, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCSTR, :PCSTR, :PCSTR, :DWORD, :PSP_FILE_CALLBACK_A, :PVOID, :PBOOL>, 36
    @DefProto DllImport, SetupInstallFileExW, WIN_STD_CALL_CONV,, <:HINF, :PINFCONTEXT, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD, :PSP_FILE_CALLBACK_W, :PVOID, :PBOOL>, 36
    ifdef UNICODE
      SetupInstallFileEx equ <SetupInstallFileExW>
    else
      SetupInstallFileEx equ <SetupInstallFileExA>
    endif
    ; CopyStyle values for copy and queue-related APIs
    SP_COPY_DELETESOURCE equ 0000001h; delete source file on successful copy

    SP_COPY_REPLACEONLY equ 0000002h; copy only if target file already present

    SP_COPY_NEWER equ 0000004h; copy only if source newer than or same as target

    SP_COPY_NEWER_OR_SAME equ <SP_COPY_NEWER>
    SP_COPY_NOOVERWRITE equ 0000008h; copy only if target doesn't exist

    SP_COPY_NODECOMP equ 0000010h; don't decompress source file while copying

    SP_COPY_LANGUAGEAWARE equ 0000020h; don't overwrite file of different language

    SP_COPY_SOURCE_ABSOLUTE equ 0000040h; SourceFile is a full source path

    SP_COPY_SOURCEPATH_ABSOLUTE equ 0000080h; SourcePathRoot is the full path

    SP_COPY_IN_USE_NEEDS_REBOOT equ 0000100h; System needs reboot if file in use

    SP_COPY_FORCE_IN_USE equ 0000200h; Force target-in-use behavior

    SP_COPY_NOSKIP equ 0000400h; Skip is disallowed for this file or section

    SP_FLAG_CABINETCONTINUATION equ 0000800h; Used with need media notification

    SP_COPY_FORCE_NOOVERWRITE equ 0001000h; like NOOVERWRITE but no callback nofitication

    SP_COPY_FORCE_NEWER equ 0002000h; like NEWER but no callback nofitication

    SP_COPY_WARNIFSKIP equ 0004000h; system critical file: warn if user tries to skip

    SP_COPY_NOBROWSE equ 0008000h; Browsing is disallowed for this file or section

    SP_COPY_NEWER_ONLY equ 0010000h; copy only if source file newer than target

    SP_COPY_RESERVED equ 0020000h; was: SP_COPY_SOURCE_SIS_MASTER (deprecated)

    SP_COPY_OEMINF_CATALOG_ONLY equ 0040000h; (SetupCopyOEMInf only) don't copy INF--just catalog

    SP_COPY_REPLACE_BOOT_FILE equ 0080000h; file must be present upon reboot (i.e., it's

    ; needed by the loader); this flag implies a reboot
    SP_COPY_NOPRUNE equ 0100000h; never prune this file

    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      SP_COPY_OEM_F6_INF equ 0200000h; Used when calling SetupCopyOemInf

    endif
    ;_SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      SP_COPY_ALREADYDECOMP equ 0400000h; similar to SP_COPY_NODECOMP

    endif
    ;_SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      SP_COPY_WINDOWS_SIGNED equ 1000000h; BuildLab or WinSE signed

      SP_COPY_PNPLOCKED equ 2000000h; Used with the signature flag

      SP_COPY_IN_USE_TRY_RENAME equ 4000000h; If file in use, try to rename the target first

      SP_COPY_INBOX_INF equ 8000000h; Referred by CopyFiles of inbox inf

    endif
    ;_SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    if _SETUPAPI_VER ge _WIN32_WINNT_WIN7
      SP_COPY_HARDLINK equ 10000000h; Copy using hardlink, if possible

    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; Flags passed to Backup notification
      SP_BACKUP_BACKUPPASS equ 00000001h; file backed up during backup pass

      SP_BACKUP_DEMANDPASS equ 00000002h; file backed up on demand

      SP_BACKUP_SPECIAL equ 00000004h; if set, special type of backup

      SP_BACKUP_BOOTFILE equ 00000008h; file marked with COPYFLG_REPLACE_BOOT_FILE

    endif
    ;_SETUPAPI_VER >= _WIN32_WINNT_WINXP
    @DefProto DllImport, SetupOpenFileQueue, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetupCloseFileQueue, WIN_STD_CALL_CONV,, <:HSPFILEQ>, 4
    @DefProto DllImport, SetupSetFileQueueAlternatePlatformA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PSP_ALTPLATFORM_INFO, :PCSTR>, 12
    @DefProto DllImport, SetupSetFileQueueAlternatePlatformW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PSP_ALTPLATFORM_INFO, :PCWSTR>, 12
    ifdef UNICODE
      SetupSetFileQueueAlternatePlatform equ <SetupSetFileQueueAlternatePlatformW>
    else
      SetupSetFileQueueAlternatePlatform equ <SetupSetFileQueueAlternatePlatformA>
    endif
    @DefProto DllImport, SetupSetPlatformPathOverrideA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
    @DefProto DllImport, SetupSetPlatformPathOverrideW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
    ifdef UNICODE
      SetupSetPlatformPathOverride equ <SetupSetPlatformPathOverrideW>
    else
      SetupSetPlatformPathOverride equ <SetupSetPlatformPathOverrideA>
    endif
    @DefProto DllImport, SetupQueueCopyA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :PCSTR, :DWORD>, 36
    @DefProto DllImport, SetupQueueCopyW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD>, 36
    ifdef UNICODE
      SetupQueueCopy equ <SetupQueueCopyW>
    else
      SetupQueueCopy equ <SetupQueueCopyA>
    endif
    @DefProto DllImport, SetupQueueCopyIndirectA, WIN_STD_CALL_CONV,, <:PSP_FILE_COPY_PARAMS_A>, 4
    @DefProto DllImport, SetupQueueCopyIndirectW, WIN_STD_CALL_CONV,, <:PSP_FILE_COPY_PARAMS_W>, 4
    ifdef UNICODE
      SetupQueueCopyIndirect equ <SetupQueueCopyIndirectW>
    else
      SetupQueueCopyIndirect equ <SetupQueueCopyIndirectA>
    endif
    @DefProto DllImport, SetupQueueDefaultCopyA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HINF, :PCSTR, :PCSTR, :PCSTR, :DWORD>, 24
    @DefProto DllImport, SetupQueueDefaultCopyW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HINF, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD>, 24
    ifdef UNICODE
      SetupQueueDefaultCopy equ <SetupQueueDefaultCopyW>
    else
      SetupQueueDefaultCopy equ <SetupQueueDefaultCopyA>
    endif
    @DefProto DllImport, SetupQueueCopySectionA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCSTR, :HINF, :HINF, :PCSTR, :DWORD>, 24
    @DefProto DllImport, SetupQueueCopySectionW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCWSTR, :HINF, :HINF, :PCWSTR, :DWORD>, 24
    ifdef UNICODE
      SetupQueueCopySection equ <SetupQueueCopySectionW>
    else
      SetupQueueCopySection equ <SetupQueueCopySectionA>
    endif
    @DefProto DllImport, SetupQueueDeleteA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCSTR, :PCSTR>, 12
    @DefProto DllImport, SetupQueueDeleteW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCWSTR, :PCWSTR>, 12
    ifdef UNICODE
      SetupQueueDelete equ <SetupQueueDeleteW>
    else
      SetupQueueDelete equ <SetupQueueDeleteA>
    endif
    @DefProto DllImport, SetupQueueDeleteSectionA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HINF, :HINF, :PCSTR>, 16
    @DefProto DllImport, SetupQueueDeleteSectionW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HINF, :HINF, :PCWSTR>, 16
    ifdef UNICODE
      SetupQueueDeleteSection equ <SetupQueueDeleteSectionW>
    else
      SetupQueueDeleteSection equ <SetupQueueDeleteSectionA>
    endif
    @DefProto DllImport, SetupQueueRenameA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCSTR, :PCSTR, :PCSTR, :PCSTR>, 20
    @DefProto DllImport, SetupQueueRenameW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR>, 20
    ifdef UNICODE
      SetupQueueRename equ <SetupQueueRenameW>
    else
      SetupQueueRename equ <SetupQueueRenameA>
    endif
    @DefProto DllImport, SetupQueueRenameSectionA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HINF, :HINF, :PCSTR>, 16
    @DefProto DllImport, SetupQueueRenameSectionW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HINF, :HINF, :PCWSTR>, 16
    ifdef UNICODE
      SetupQueueRenameSection equ <SetupQueueRenameSectionW>
    else
      SetupQueueRenameSection equ <SetupQueueRenameSectionA>
    endif
    @DefProto DllImport, SetupCommitFileQueueA, WIN_STD_CALL_CONV,, <:HWND, :HSPFILEQ, :PSP_FILE_CALLBACK_A, :PVOID>, 16
    @DefProto DllImport, SetupCommitFileQueueW, WIN_STD_CALL_CONV,, <:HWND, :HSPFILEQ, :PSP_FILE_CALLBACK_W, :PVOID>, 16
    ifdef UNICODE
      SetupCommitFileQueue equ <SetupCommitFileQueueW>
    else
      SetupCommitFileQueue equ <SetupCommitFileQueueA>
    endif
    @DefProto DllImport, SetupScanFileQueueA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :DWORD, :HWND, :PSP_FILE_CALLBACK_A, :PVOID, :PDWORD>, 24
    @DefProto DllImport, SetupScanFileQueueW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :DWORD, :HWND, :PSP_FILE_CALLBACK_W, :PVOID, :PDWORD>, 24
    ifdef UNICODE
      SetupScanFileQueue equ <SetupScanFileQueueW>
    else
      SetupScanFileQueue equ <SetupScanFileQueueA>
    endif
    ; Define flags for SetupScanFileQueue.
    SPQ_SCAN_FILE_PRESENCE equ 00000001h
    SPQ_SCAN_FILE_VALIDITY equ 00000002h
    SPQ_SCAN_USE_CALLBACK equ 00000004h
    SPQ_SCAN_USE_CALLBACKEX equ 00000008h
    SPQ_SCAN_INFORM_USER equ 00000010h
    SPQ_SCAN_PRUNE_COPY_QUEUE equ 00000020h
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      SPQ_SCAN_USE_CALLBACK_SIGNERINFO equ 00000040h
      SPQ_SCAN_PRUNE_DELREN equ 00000080h; remote Delete/Rename queue

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      SPQ_SCAN_FILE_PRESENCE_WITHOUT_SOURCE equ 00000100h
      SPQ_SCAN_FILE_COMPARISON equ 00000200h
      SPQ_SCAN_ACTIVATE_DRP equ 00000400h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    ; Define flags used with Param2 for SPFILENOTIFY_QUEUESCAN
    SPQ_DELAYED_COPY equ 00000001h; file was in use; registered for delayed copy

    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupGetFileQueueCount, WIN_STD_CALL_CONV,, <:HSPFILEQ, :UINT, :PUINT>, 12
      @DefProto DllImport, SetupGetFileQueueFlags, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PDWORD>, 8
      @DefProto DllImport, SetupSetFileQueueFlags, WIN_STD_CALL_CONV,, <:HSPFILEQ, :DWORD, :DWORD>, 12
      ; Flags/FlagMask for use with SetupSetFileQueueFlags and returned by SetupGetFileQueueFlags
      SPQ_FLAG_BACKUP_AWARE equ 00000001h; If set, SetupCommitFileQueue will

      ; issue backup notifications.
      SPQ_FLAG_ABORT_IF_UNSIGNED equ 00000002h; If set, SetupCommitFileQueue will

      ; fail with ERROR_SET_SYSTEM_RESTORE_POINT
      ; if the user elects to proceed with an
      ; unsigned queue committal.  This allows
      ; the caller to set a system restore point,
      ; then re-commit the file queue.
      SPQ_FLAG_FILES_MODIFIED equ 00000004h; If set, at least one file was

      ; replaced by a different version
      SPQ_FLAG_DO_SHUFFLEMOVE equ 00000008h; If set then always do a shuffle move. A shuffle

      ; move will first try to copy the source over the
      ; destination file, but if the destination file is
      ; in use it will rename the destination file to a
      ; temp name and queue the temp name for deletion.
      ; It will then be free to copy the source to the
      ; destination name.  It is considered an error if
      ; the destination file can't be renamed for some
      ; reason.
      SPQ_FLAG_VALID equ 0000000Fh; mask of valid flags (can be passed as FlagMask)

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Define OEM Source Type values for use in SetupCopyOEMInf.
    SPOST_NONE equ 0
    SPOST_PATH equ 1
    SPOST_URL equ 2
    SPOST_MAX equ 3
    @DefProto DllImport, SetupCopyOEMInfA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :DWORD, :DWORD, :PSTR, :DWORD, :PDWORD, :ptr PSTR>, 32
    @DefProto DllImport, SetupCopyOEMInfW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :DWORD, :DWORD, :PWSTR, :DWORD, :PDWORD, :ptr PWSTR>, 32
    ifdef UNICODE
      SetupCopyOEMInf equ <SetupCopyOEMInfW>
    else
      SetupCopyOEMInf equ <SetupCopyOEMInfA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; Flags used by SetupUninstallOEMInf
      SUOI_FORCEDELETE equ 00000001h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      SUOI_INTERNAL1 equ 00000002h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupUninstallOEMInfA, WIN_STD_CALL_CONV,, <:PCSTR, :DWORD, :PVOID>, 12
      @DefProto DllImport, SetupUninstallOEMInfW, WIN_STD_CALL_CONV,, <:PCWSTR, :DWORD, :PVOID>, 12
      ifdef UNICODE
        SetupUninstallOEMInf equ <SetupUninstallOEMInfW>
      else
        SetupUninstallOEMInf equ <SetupUninstallOEMInfA>
      endif
      @DefProto DllImport, SetupUninstallNewlyCopiedInfs, WIN_STD_CALL_CONV,, <:HSPFILEQ, :DWORD, :PVOID>, 12
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Disk space list APIs
    @DefProto DllImport, SetupCreateDiskSpaceListA, WIN_STD_CALL_CONV,, <:PVOID, :DWORD, :UINT>, 12
    @DefProto DllImport, SetupCreateDiskSpaceListW, WIN_STD_CALL_CONV,, <:PVOID, :DWORD, :UINT>, 12
    ifdef UNICODE
      SetupCreateDiskSpaceList equ <SetupCreateDiskSpaceListW>
    else
      SetupCreateDiskSpaceList equ <SetupCreateDiskSpaceListA>
    endif
    ; Flags for SetupCreateDiskSpaceList
    SPDSL_IGNORE_DISK equ 00000001h; ignore deletes and on-disk files in copies

    SPDSL_DISALLOW_NEGATIVE_ADJUST equ 00000002h
    @DefProto DllImport, SetupDuplicateDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :PVOID, :DWORD, :UINT>, 16
    @DefProto DllImport, SetupDuplicateDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :PVOID, :DWORD, :UINT>, 16
    ifdef UNICODE
      SetupDuplicateDiskSpaceList equ <SetupDuplicateDiskSpaceListW>
    else
      SetupDuplicateDiskSpaceList equ <SetupDuplicateDiskSpaceListA>
    endif
    @DefProto DllImport, SetupDestroyDiskSpaceList, WIN_STD_CALL_CONV,, <:HDSKSPC>, 4
    @DefProto DllImport, SetupQueryDrivesInDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :PSTR, :DWORD, :PDWORD>, 16
    @DefProto DllImport, SetupQueryDrivesInDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :PWSTR, :DWORD, :PDWORD>, 16
    ifdef UNICODE
      SetupQueryDrivesInDiskSpaceList equ <SetupQueryDrivesInDiskSpaceListW>
    else
      SetupQueryDrivesInDiskSpaceList equ <SetupQueryDrivesInDiskSpaceListA>
    endif
    @DefProto DllImport, SetupQuerySpaceRequiredOnDriveA, WIN_STD_CALL_CONV,, <:HDSKSPC, :PCSTR, :ptr LONGLONG, :PVOID, :UINT>, 20
    @DefProto DllImport, SetupQuerySpaceRequiredOnDriveW, WIN_STD_CALL_CONV,, <:HDSKSPC, :PCWSTR, :ptr LONGLONG, :PVOID, :UINT>, 20
    ifdef UNICODE
      SetupQuerySpaceRequiredOnDrive equ <SetupQuerySpaceRequiredOnDriveW>
    else
      SetupQuerySpaceRequiredOnDrive equ <SetupQuerySpaceRequiredOnDriveA>
    endif
    @DefProto DllImport, SetupAdjustDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :LPCSTR, :LONGLONG, :PVOID, :UINT>, 20
    @DefProto DllImport, SetupAdjustDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :LPCWSTR, :LONGLONG, :PVOID, :UINT>, 20
    ifdef UNICODE
      SetupAdjustDiskSpaceList equ <SetupAdjustDiskSpaceListW>
    else
      SetupAdjustDiskSpaceList equ <SetupAdjustDiskSpaceListA>
    endif
    @DefProto DllImport, SetupAddToDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :PCSTR, :LONGLONG, :UINT, :PVOID, :UINT>, 24
    @DefProto DllImport, SetupAddToDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :PCWSTR, :LONGLONG, :UINT, :PVOID, :UINT>, 24
    ifdef UNICODE
      SetupAddToDiskSpaceList equ <SetupAddToDiskSpaceListW>
    else
      SetupAddToDiskSpaceList equ <SetupAddToDiskSpaceListA>
    endif
    @DefProto DllImport, SetupAddSectionToDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCSTR, :UINT, :PVOID, :UINT>, 28
    @DefProto DllImport, SetupAddSectionToDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCWSTR, :UINT, :PVOID, :UINT>, 28
    ifdef UNICODE
      SetupAddSectionToDiskSpaceList equ <SetupAddSectionToDiskSpaceListW>
    else
      SetupAddSectionToDiskSpaceList equ <SetupAddSectionToDiskSpaceListA>
    endif
    @DefProto DllImport, SetupAddInstallSectionToDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCSTR, :PVOID, :UINT>, 24
    @DefProto DllImport, SetupAddInstallSectionToDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCWSTR, :PVOID, :UINT>, 24
    ifdef UNICODE
      SetupAddInstallSectionToDiskSpaceList equ <SetupAddInstallSectionToDiskSpaceListW>
    else
      SetupAddInstallSectionToDiskSpaceList equ <SetupAddInstallSectionToDiskSpaceListA>
    endif
    @DefProto DllImport, SetupRemoveFromDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :PCSTR, :UINT, :PVOID, :UINT>, 20
    @DefProto DllImport, SetupRemoveFromDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :PCWSTR, :UINT, :PVOID, :UINT>, 20
    ifdef UNICODE
      SetupRemoveFromDiskSpaceList equ <SetupRemoveFromDiskSpaceListW>
    else
      SetupRemoveFromDiskSpaceList equ <SetupRemoveFromDiskSpaceListA>
    endif
    @DefProto DllImport, SetupRemoveSectionFromDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCSTR, :UINT, :PVOID, :UINT>, 28
    @DefProto DllImport, SetupRemoveSectionFromDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCWSTR, :UINT, :PVOID, :UINT>, 28
    ifdef UNICODE
      SetupRemoveSectionFromDiskSpaceList equ <SetupRemoveSectionFromDiskSpaceListW>
    else
      SetupRemoveSectionFromDiskSpaceList equ <SetupRemoveSectionFromDiskSpaceListA>
    endif
    @DefProto DllImport, SetupRemoveInstallSectionFromDiskSpaceListA, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCSTR, :PVOID, :UINT>, 24
    @DefProto DllImport, SetupRemoveInstallSectionFromDiskSpaceListW, WIN_STD_CALL_CONV,, <:HDSKSPC, :HINF, :HINF, :PCWSTR, :PVOID, :UINT>, 24
    ifdef UNICODE
      SetupRemoveInstallSectionFromDiskSpaceList equ <SetupRemoveInstallSectionFromDiskSpaceListW>
    else
      SetupRemoveInstallSectionFromDiskSpaceList equ <SetupRemoveInstallSectionFromDiskSpaceListA>
    endif
    ; Cabinet APIs
    @DefProto DllImport, SetupIterateCabinetA, WIN_STD_CALL_CONV,, <:PCSTR, :DWORD, :PSP_FILE_CALLBACK_A, :PVOID>, 16
    @DefProto DllImport, SetupIterateCabinetW, WIN_STD_CALL_CONV,, <:PCWSTR, :DWORD, :PSP_FILE_CALLBACK_W, :PVOID>, 16
    ifdef UNICODE
      SetupIterateCabinet equ <SetupIterateCabinetW>
    else
      SetupIterateCabinet equ <SetupIterateCabinetA>
    endif
    @DefProto DllImport, SetupPromptReboot, WIN_STD_CALL_CONV,, <:HSPFILEQ, :HWND, :BOOL>, 12
    ; Define flags that are returned by SetupPromptReboot
    SPFILEQ_FILE_IN_USE equ 00000001h
    SPFILEQ_REBOOT_RECOMMENDED equ 00000002h
    SPFILEQ_REBOOT_IN_PROGRESS equ 00000004h
    @DefProto DllImport, SetupInitDefaultQueueCallback, WIN_STD_CALL_CONV,, <:HWND>, 4
    @DefProto DllImport, SetupInitDefaultQueueCallbackEx, WIN_STD_CALL_CONV,, <:HWND, :HWND, :UINT, :DWORD, :PVOID>, 20
    @DefProto DllImport, SetupTermDefaultQueueCallback, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, SetupDefaultQueueCallbackA, WIN_STD_CALL_CONV,, <:PVOID, :UINT, :UINT_PTR, :UINT_PTR>, 16
    @DefProto DllImport, SetupDefaultQueueCallbackW, WIN_STD_CALL_CONV,, <:PVOID, :UINT, :UINT_PTR, :UINT_PTR>, 16
    ifdef UNICODE
      SetupDefaultQueueCallback equ <SetupDefaultQueueCallbackW>
    else
      SetupDefaultQueueCallback equ <SetupDefaultQueueCallbackA>
    endif
    ; Flags for AddReg section lines in INF.  The corresponding value
    ; is <ValueType> in the AddReg line format given below:
    ; <RegRootString>,<SubKey>,<ValueName>,<ValueType>,<Value>...
    ; The low word contains basic flags concerning the general data type
    ; and AddReg action. The high word contains values that more specifically
    ; identify the data type of the registry value.  The high word is ignored
    ; by the 16-bit Windows 95 SETUPX APIs.
    ; If <ValueType> has FLG_ADDREG_DELREG_BIT set, it will be ignored by AddReg
    ; (not supported by SetupX).
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      FLG_ADDREG_DELREG_BIT equ (00008000h); if set, interpret as DELREG, see below

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    FLG_ADDREG_BINVALUETYPE equ (00000001h)
    FLG_ADDREG_NOCLOBBER equ (00000002h)
    FLG_ADDREG_DELVAL equ (00000004h)
    FLG_ADDREG_APPEND equ (00000008h); Currently supported only

    ; for REG_MULTI_SZ values.
    FLG_ADDREG_KEYONLY equ (00000010h); Just create the key, ignore value

    FLG_ADDREG_OVERWRITEONLY equ (00000020h); Set only if value already exists

    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      FLG_ADDREG_64BITKEY equ (00001000h); make this change in the 64 bit registry.

      FLG_ADDREG_KEYONLY_COMMON equ (00002000h); same as FLG_ADDREG_KEYONLY but also works for DELREG

      FLG_ADDREG_32BITKEY equ (00004000h); make this change in the 32 bit registry.

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; The INF may supply any arbitrary data type ordinal in the highword except
    ; for the following: REG_NONE, REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ.  If this
    ; technique is used, then the data is given in binary format, one byte per
    ; field.
    FLG_ADDREG_TYPE_MASK equ (0FFFF0000h or FLG_ADDREG_BINVALUETYPE)
    FLG_ADDREG_TYPE_SZ equ (00000000h)
    FLG_ADDREG_TYPE_MULTI_SZ equ (00010000h)
    FLG_ADDREG_TYPE_EXPAND_SZ equ (00020000h)
    FLG_ADDREG_TYPE_BINARY equ (00000000h or FLG_ADDREG_BINVALUETYPE)
    FLG_ADDREG_TYPE_DWORD equ (00010000h or FLG_ADDREG_BINVALUETYPE)
    FLG_ADDREG_TYPE_NONE equ (00020000h or FLG_ADDREG_BINVALUETYPE)
    if _SETUPAPI_VER ge _WIN32_WINNT_WIN10
      FLG_ADDREG_TYPE_QWORD equ (000B0000h or FLG_ADDREG_BINVALUETYPE)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WIN10
    ; Flags for DelReg section lines in INF.  The corresponding value
    ; is <Operation> in the extended DelReg line format given below:
    ; <RegRootString>,<SubKey>,<ValueName>,<Operation>[,...]
    ; In SetupX and some versions of SetupAPI, <Operation> will be ignored and <ValueName> will
    ; be deleted. Use with care.
    ; The bits determined by mask FLG_DELREG_TYPE_MASK indicates type of data expected.
    ; <Operation> must have FLG_ADDREG_DELREG_BIT set, otherwise it is ignored and specified
    ; value will be deleted (allowing an AddReg section to also be used as a DelReg section)
    ; if <Operation> is not specified, <ValueName> will be deleted (if specified) otherwise
    ; <SubKey> will be deleted.
    ; the compatability flag
    FLG_DELREG_VALUE equ (00000000h)
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      FLG_DELREG_TYPE_MASK equ <FLG_ADDREG_TYPE_MASK>; 0xFFFF0001

      FLG_DELREG_TYPE_SZ equ <FLG_ADDREG_TYPE_SZ>; 0x00000000

      FLG_DELREG_TYPE_MULTI_SZ equ <FLG_ADDREG_TYPE_MULTI_SZ>; 0x00010000

      FLG_DELREG_TYPE_EXPAND_SZ equ <FLG_ADDREG_TYPE_EXPAND_SZ>; 0x00020000

      FLG_DELREG_TYPE_BINARY equ <FLG_ADDREG_TYPE_BINARY>; 0x00000001

      FLG_DELREG_TYPE_DWORD equ <FLG_ADDREG_TYPE_DWORD>; 0x00010001

      FLG_DELREG_TYPE_NONE equ <FLG_ADDREG_TYPE_NONE>; 0x00020001

      FLG_DELREG_64BITKEY equ <FLG_ADDREG_64BITKEY>; 0x00001000

      FLG_DELREG_KEYONLY_COMMON equ <FLG_ADDREG_KEYONLY_COMMON>; 0x00002000

      FLG_DELREG_32BITKEY equ <FLG_ADDREG_32BITKEY>; 0x00004000

      ; <Operation> = FLG_DELREG_MULTI_SZ_DELSTRING
      ;               <RegRootString>,<SubKey>,<ValueName>,0x00018002,<String>
      ;               removes all entries matching <String> (case ignored) from multi-sz registry value
      FLG_DELREG_OPERATION_MASK equ (000000FEh)
      FLG_DELREG_MULTI_SZ_DELSTRING equ (FLG_DELREG_TYPE_MULTI_SZ or FLG_ADDREG_DELREG_BIT or 00000002h); 0x00018002

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WIN10
      FLG_DELREG_TYPE_QWORD equ <FLG_ADDREG_TYPE_QWORD>; 0x000B0001

    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WIN10
    ; Flags for BitReg section lines in INF.
    FLG_BITREG_CLEARBITS equ (00000000h)
    FLG_BITREG_SETBITS equ (00000001h)
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      FLG_BITREG_64BITKEY equ (00001000h)
      FLG_BITREG_32BITKEY equ (00004000h)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Flags for Ini2Reg section lines in INF.
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      FLG_INI2REG_64BITKEY equ (00001000h)
      FLG_INI2REG_32BITKEY equ (00004000h)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Flags for RegSvr section lines in INF
    FLG_REGSVR_DLLREGISTER equ (00000001h)
    FLG_REGSVR_DLLINSTALL equ (00000002h)
    ; Flags for RegSvr section lines in INF
    FLG_PROFITEM_CURRENTUSER equ (00000001h)
    FLG_PROFITEM_DELETE equ (00000002h)
    FLG_PROFITEM_GROUP equ (00000004h)
    FLG_PROFITEM_CSIDL equ (00000008h)
    ; Flags for AddProperty section lines in the INF
    FLG_ADDPROPERTY_NOCLOBBER equ (00000001h)
    FLG_ADDPROPERTY_OVERWRITEONLY equ (00000002h)
    FLG_ADDPROPERTY_APPEND equ (00000004h)
    FLG_ADDPROPERTY_OR equ (00000008h)
    FLG_ADDPROPERTY_AND equ (00000010h)
    ; Flags for DelProperty section lines in the INF
    FLG_DELPROPERTY_MULTI_SZ_DELSTRING equ (00000001h)
    @DefProto DllImport, SetupInstallFromInfSectionA, WIN_STD_CALL_CONV,, <:HWND, :HINF, :PCSTR, :UINT, :HKEY, :PCSTR, :UINT, :PSP_FILE_CALLBACK_A, :PVOID, :HDEVINFO, :PSP_DEVINFO_DATA>, 44
    @DefProto DllImport, SetupInstallFromInfSectionW, WIN_STD_CALL_CONV,, <:HWND, :HINF, :PCWSTR, :UINT, :HKEY, :PCWSTR, :UINT, :PSP_FILE_CALLBACK_W, :PVOID, :HDEVINFO, :PSP_DEVINFO_DATA>, 44
    ifdef UNICODE
      SetupInstallFromInfSection equ <SetupInstallFromInfSectionW>
    else
      SetupInstallFromInfSection equ <SetupInstallFromInfSectionA>
    endif
    ; Flags for SetupInstallFromInfSection
    SPINST_LOGCONFIG equ 00000001h
    SPINST_INIFILES equ 00000002h
    SPINST_REGISTRY equ 00000004h
    SPINST_INI2REG equ 00000008h
    SPINST_FILES equ 00000010h
    SPINST_BITREG equ 00000020h
    SPINST_REGSVR equ 00000040h
    SPINST_UNREGSVR equ 00000080h
    SPINST_PROFILEITEMS equ 00000100h
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      SPINST_COPYINF equ 00000200h
      if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
        SPINST_PROPERTIES equ 00000400h
        SPINST_ALL equ 000007ffh
      else
        SPINST_ALL equ 000003ffh
      endif
      ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    else
      SPINST_ALL equ 000001ffh
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    SPINST_SINGLESECTION equ 00010000h
    SPINST_LOGCONFIG_IS_FORCED equ 00020000h
    SPINST_LOGCONFIGS_ARE_OVERRIDES equ 00040000h
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      SPINST_REGISTERCALLBACKAWARE equ 00080000h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      SPINST_DEVICEINSTALL equ 00100000h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    @DefProto DllImport, SetupInstallFilesFromInfSectionA, WIN_STD_CALL_CONV,, <:HINF, :HINF, :HSPFILEQ, :PCSTR, :PCSTR, :UINT>, 24
    @DefProto DllImport, SetupInstallFilesFromInfSectionW, WIN_STD_CALL_CONV,, <:HINF, :HINF, :HSPFILEQ, :PCWSTR, :PCWSTR, :UINT>, 24
    ifdef UNICODE
      SetupInstallFilesFromInfSection equ <SetupInstallFilesFromInfSectionW>
    else
      SetupInstallFilesFromInfSection equ <SetupInstallFilesFromInfSectionA>
    endif
    ; Flags for SetupInstallServicesFromInfSection(Ex).  These flags are also used
    ; in the flags field of AddService or DelService lines in a device INF.  Some
    ; of these flags are not permitted in the non-Ex API.  These flags are marked
    ; as such below.
    ; (AddService) move service's tag to front of its group order list
    SPSVCINST_TAGTOFRONT equ (00000001h)
    ; (AddService) **Ex API only** mark this service as the function driver for the
    ; device being installed
    SPSVCINST_ASSOCSERVICE equ (00000002h)
    ; (DelService) delete the associated event log entry for a service specified in
    ; a DelService entry
    SPSVCINST_DELETEEVENTLOGENTRY equ (00000004h)
    ; (AddService) don't overwrite display name if it already exists
    SPSVCINST_NOCLOBBER_DISPLAYNAME equ (00000008h)
    ; (AddService) don't overwrite start type value if service already exists
    SPSVCINST_NOCLOBBER_STARTTYPE equ (00000010h)
    ; (AddService) don't overwrite error control value if service already exists
    SPSVCINST_NOCLOBBER_ERRORCONTROL equ (00000020h)
    ; (AddService) don't overwrite load order group if it already exists
    SPSVCINST_NOCLOBBER_LOADORDERGROUP equ (00000040h)
    ; (AddService) don't overwrite dependencies list if it already exists
    SPSVCINST_NOCLOBBER_DEPENDENCIES equ (00000080h)
    ; (AddService) don't overwrite description if it already exists
    SPSVCINST_NOCLOBBER_DESCRIPTION equ (00000100h)
    ; (DelService) stop the associated service specified in
    ; a DelService entry before deleting the service
    SPSVCINST_STOPSERVICE equ (00000200h)
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; (AddService) force overwrite of security settings
      SPSVCINST_CLOBBER_SECURITY equ (00000400h)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      ; (Start Service) start a service manually after install
      SPSVCINST_STARTSERVICE equ (00000800h)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    if _SETUPAPI_VER ge _WIN32_WINNT_WIN7
      ; (AddService) don't overwrite required privileges list if it already exists
      SPSVCINST_NOCLOBBER_REQUIREDPRIVILEGES equ (00001000h)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WIN7
    if _SETUPAPI_VER ge _WIN32_WINNT_WIN10
      ; (AddService) don't overwrite triggers if they already exist
      SPSVCINST_NOCLOBBER_TRIGGERS equ (00002000h)
      ; (AddService) don't overwrite service SID type if it already exists
      SPSVCINST_NOCLOBBER_SERVICESIDTYPE equ (00004000h)
      ; (AddService) don't overwrite delayed auto start if it already exists
      SPSVCINST_NOCLOBBER_DELAYEDAUTOSTART equ (00008000h)
      ; (AddService) create service with a unique name
      SPSVCINST_UNIQUE_NAME equ (00010000h)
      ; (AddService) don't overwrite failure actions if they already exist
      SPSVCINST_NOCLOBBER_FAILUREACTIONS equ (00020000h)
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WIN10
    @DefProto DllImport, SetupInstallServicesFromInfSectionA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :DWORD>, 12
    @DefProto DllImport, SetupInstallServicesFromInfSectionW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :DWORD>, 12
    ifdef UNICODE
      SetupInstallServicesFromInfSection equ <SetupInstallServicesFromInfSectionW>
    else
      SetupInstallServicesFromInfSection equ <SetupInstallServicesFromInfSectionA>
    endif
    @DefProto DllImport, SetupInstallServicesFromInfSectionExA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :DWORD, :HDEVINFO, :PSP_DEVINFO_DATA, :PVOID, :PVOID>, 28
    @DefProto DllImport, SetupInstallServicesFromInfSectionExW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :DWORD, :HDEVINFO, :PSP_DEVINFO_DATA, :PVOID, :PVOID>, 28
    ifdef UNICODE
      SetupInstallServicesFromInfSectionEx equ <SetupInstallServicesFromInfSectionExW>
    else
      SetupInstallServicesFromInfSectionEx equ <SetupInstallServicesFromInfSectionExA>
    endif
    ; High level routine, usually used via rundll32.dll
    ; to perform right-click install action on INFs
    ; May be called directly:
    ; wsprintf(CmdLineBuffer,TEXT("DefaultInstall 132 %s"),InfPath);
    ; InstallHinfSection(NULL,NULL,CmdLineBuffer,0);
    InstallHinfSectionA proto WIN_STD_CALL_CONV :HWND, :HINSTANCE, :PCSTR, :INT_
    InstallHinfSectionW proto WIN_STD_CALL_CONV :HWND, :HINSTANCE, :PCWSTR, :INT_
    ifdef UNICODE
      InstallHinfSection equ <InstallHinfSectionW>
    else
      InstallHinfSection equ <InstallHinfSectionA>
    endif
    ; Define handle type for Setup file log.
    HSPFILELOG typedef PVOID
    @DefProto DllImport, SetupInitializeFileLogA, WIN_STD_CALL_CONV,, <:PCSTR, :DWORD>, 8
    @DefProto DllImport, SetupInitializeFileLogW, WIN_STD_CALL_CONV,, <:PCWSTR, :DWORD>, 8
    ifdef UNICODE
      SetupInitializeFileLog equ <SetupInitializeFileLogW>
    else
      SetupInitializeFileLog equ <SetupInitializeFileLogA>
    endif
    ; Flags for SetupInitializeFileLog
    SPFILELOG_SYSTEMLOG equ 00000001h; use system log -- must be Administrator

    SPFILELOG_FORCENEW equ 00000002h; not valid with SPFILELOG_SYSTEMLOG

    SPFILELOG_QUERYONLY equ 00000004h; allows non-administrators to read system log

    @DefProto DllImport, SetupTerminateFileLog, WIN_STD_CALL_CONV,, <:HSPFILELOG>, 4
    @DefProto DllImport, SetupLogFileA, WIN_STD_CALL_CONV,, <:HSPFILELOG, :PCSTR, :PCSTR, :PCSTR, :DWORD, :PCSTR, :PCSTR, :PCSTR, :DWORD>, 36
    @DefProto DllImport, SetupLogFileW, WIN_STD_CALL_CONV,, <:HSPFILELOG, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD, :PCWSTR, :PCWSTR, :PCWSTR, :DWORD>, 36
    ifdef UNICODE
      SetupLogFile equ <SetupLogFileW>
    else
      SetupLogFile equ <SetupLogFileA>
    endif
    ; Flags for SetupLogFile
    SPFILELOG_OEMFILE equ 00000001h
    @DefProto DllImport, SetupRemoveFileLogEntryA, WIN_STD_CALL_CONV,, <:HSPFILELOG, :PCSTR, :PCSTR>, 12
    @DefProto DllImport, SetupRemoveFileLogEntryW, WIN_STD_CALL_CONV,, <:HSPFILELOG, :PCWSTR, :PCWSTR>, 12
    ifdef UNICODE
      SetupRemoveFileLogEntry equ <SetupRemoveFileLogEntryW>
    else
      SetupRemoveFileLogEntry equ <SetupRemoveFileLogEntryA>
    endif
    ; Items retrievable from SetupQueryFileLog()
    SetupFileLogInfo typedef SDWORD
    SetupFileLogSourceFilename equ 0
    SetupFileLogChecksum equ 1
    SetupFileLogDiskTagfile equ 2
    SetupFileLogDiskDescription equ 3
    SetupFileLogOtherInfo equ 4
    SetupFileLogMax equ 5

    @DefProto DllImport, SetupQueryFileLogA, WIN_STD_CALL_CONV,, <:HSPFILELOG, :PCSTR, :PCSTR, :SetupFileLogInfo, :PSTR, :DWORD, :PDWORD>, 28
    @DefProto DllImport, SetupQueryFileLogW, WIN_STD_CALL_CONV,, <:HSPFILELOG, :PCWSTR, :PCWSTR, :SetupFileLogInfo, :PWSTR, :DWORD, :PDWORD>, 28
    ifdef UNICODE
      SetupQueryFileLog equ <SetupQueryFileLogW>
    else
      SetupQueryFileLog equ <SetupQueryFileLogA>
    endif
    ; Text logging APIs
    LogSeverity equ <DWORD>
    LogSevInformation equ 00000000h
    LogSevWarning equ 00000001h
    LogSevError equ 00000002h
    LogSevFatalError equ 00000003h
    LogSevMaximum equ 00000004h
    @DefProto DllImport, SetupOpenLog, WIN_STD_CALL_CONV,, <:BOOL>, 4
    @DefProto DllImport, SetupLogErrorA, WIN_STD_CALL_CONV,, <:LPCSTR, :LogSeverity>, 8
    @DefProto DllImport, SetupLogErrorW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LogSeverity>, 8
    ifdef UNICODE
      SetupLogError equ <SetupLogErrorW>
    else
      SetupLogError equ <SetupLogErrorA>
    endif
    @DefProto DllImport, SetupCloseLog, WIN_STD_CALL_CONV,, <>, 0
    ; Text log for INF debugging
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      @DefProto DllImport, SetupGetThreadLogToken, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SetupSetThreadLogToken, WIN_STD_CALL_CONV,, <:SP_LOG_TOKEN>, 4
      @DefProto DllImport, SetupWriteTextLog, WIN_STD_CALL_CONV,, <:SP_LOG_TOKEN, :DWORD, :DWORD, :PCSTR, :vararg>, 20
      @DefProto DllImport, SetupWriteTextLogError, WIN_STD_CALL_CONV,, <:SP_LOG_TOKEN, :DWORD, :DWORD, :DWORD, :PCSTR, :vararg>, 24
      @DefProto DllImport, SetupWriteTextLogInfLine, WIN_STD_CALL_CONV,, <:SP_LOG_TOKEN, :DWORD, :HINF, :PINFCONTEXT>, 16
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    ; Backup Information API's
    @DefProto DllImport, SetupGetBackupInformationA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PSP_BACKUP_QUEUE_PARAMS_A>, 8
    @DefProto DllImport, SetupGetBackupInformationW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PSP_BACKUP_QUEUE_PARAMS_W>, 8
    ifdef UNICODE
      SetupGetBackupInformation equ <SetupGetBackupInformationW>
    else
      SetupGetBackupInformation equ <SetupGetBackupInformationA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupPrepareQueueForRestoreA, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCSTR, :DWORD>, 12
      @DefProto DllImport, SetupPrepareQueueForRestoreW, WIN_STD_CALL_CONV,, <:HSPFILEQ, :PCWSTR, :DWORD>, 12
      ifdef UNICODE
        SetupPrepareQueueForRestore equ <SetupPrepareQueueForRestoreW>
      else
        SetupPrepareQueueForRestore equ <SetupPrepareQueueForRestoreA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; Control forcing of Non-Interactive Mode
      ; Overriden if SetupAPI is run in non-interactive window session
      @DefProto DllImport, SetupSetNonInteractiveMode, WIN_STD_CALL_CONV,, <:BOOL>, 4
      @DefProto DllImport, SetupGetNonInteractiveMode, WIN_STD_CALL_CONV,, <>, 0
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Device Installer APIs
    @DefProto DllImport, SetupDiCreateDeviceInfoList, WIN_STD_CALL_CONV,, <:ptr GUID, :HWND>, 8
    @DefProto DllImport, SetupDiCreateDeviceInfoListExA, WIN_STD_CALL_CONV,, <:ptr GUID, :HWND, :PCSTR, :PVOID>, 16
    @DefProto DllImport, SetupDiCreateDeviceInfoListExW, WIN_STD_CALL_CONV,, <:ptr GUID, :HWND, :PCWSTR, :PVOID>, 16
    ifdef UNICODE
      SetupDiCreateDeviceInfoListEx equ <SetupDiCreateDeviceInfoListExW>
    else
      SetupDiCreateDeviceInfoListEx equ <SetupDiCreateDeviceInfoListExA>
    endif
    @DefProto DllImport, SetupDiGetDeviceInfoListClass, WIN_STD_CALL_CONV,, <:HDEVINFO, :LPGUID>, 8
    @DefProto DllImport, SetupDiGetDeviceInfoListDetailA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_LIST_DETAIL_DATA_A>, 8
    @DefProto DllImport, SetupDiGetDeviceInfoListDetailW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_LIST_DETAIL_DATA_W>, 8
    ifdef UNICODE
      SetupDiGetDeviceInfoListDetail equ <SetupDiGetDeviceInfoListDetailW>
    else
      SetupDiGetDeviceInfoListDetail equ <SetupDiGetDeviceInfoListDetailA>
    endif
    ; Flags for SetupDiCreateDeviceInfo
    DICD_GENERATE_ID equ 00000001h
    DICD_INHERIT_CLASSDRVS equ 00000002h
    @DefProto DllImport, SetupDiCreateDeviceInfoA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PCSTR, :ptr GUID, :PCSTR, :HWND, :DWORD, :PSP_DEVINFO_DATA>, 28
    @DefProto DllImport, SetupDiCreateDeviceInfoW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PCWSTR, :ptr GUID, :PCWSTR, :HWND, :DWORD, :PSP_DEVINFO_DATA>, 28
    ifdef UNICODE
      SetupDiCreateDeviceInfo equ <SetupDiCreateDeviceInfoW>
    else
      SetupDiCreateDeviceInfo equ <SetupDiCreateDeviceInfoA>
    endif
    ; Flags for SetupDiOpenDeviceInfo
    DIOD_INHERIT_CLASSDRVS equ 00000002h
    DIOD_CANCEL_REMOVE equ 00000004h
    @DefProto DllImport, SetupDiOpenDeviceInfoA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PCSTR, :HWND, :DWORD, :PSP_DEVINFO_DATA>, 20
    @DefProto DllImport, SetupDiOpenDeviceInfoW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PCWSTR, :HWND, :DWORD, :PSP_DEVINFO_DATA>, 20
    ifdef UNICODE
      SetupDiOpenDeviceInfo equ <SetupDiOpenDeviceInfoW>
    else
      SetupDiOpenDeviceInfo equ <SetupDiOpenDeviceInfoA>
    endif
    @DefProto DllImport, SetupDiGetDeviceInstanceIdA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSTR, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupDiGetDeviceInstanceIdW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PWSTR, :DWORD, :PDWORD>, 20
    ifdef UNICODE
      SetupDiGetDeviceInstanceId equ <SetupDiGetDeviceInstanceIdW>
    else
      SetupDiGetDeviceInstanceId equ <SetupDiGetDeviceInstanceIdA>
    endif
    @DefProto DllImport, SetupDiDeleteDeviceInfo, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    @DefProto DllImport, SetupDiEnumDeviceInfo, WIN_STD_CALL_CONV,, <:HDEVINFO, :DWORD, :PSP_DEVINFO_DATA>, 12
    @DefProto DllImport, SetupDiDestroyDeviceInfoList, WIN_STD_CALL_CONV,, <:HDEVINFO>, 4
    @DefProto DllImport, SetupDiEnumDeviceInterfaces, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :ptr GUID, :DWORD, :PSP_DEVICE_INTERFACE_DATA>, 20
    ; Backward compatibility--do not use
    SetupDiEnumInterfaceDevice equ <SetupDiEnumDeviceInterfaces>
    @DefProto DllImport, SetupDiCreateDeviceInterfaceA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :ptr GUID, :PCSTR, :DWORD, :PSP_DEVICE_INTERFACE_DATA>, 24
    @DefProto DllImport, SetupDiCreateDeviceInterfaceW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :ptr GUID, :PCWSTR, :DWORD, :PSP_DEVICE_INTERFACE_DATA>, 24
    ifdef UNICODE
      SetupDiCreateDeviceInterface equ <SetupDiCreateDeviceInterfaceW>
    else
      SetupDiCreateDeviceInterface equ <SetupDiCreateDeviceInterfaceA>
    endif
    ; Backward compatibility--do not use.
    SetupDiCreateInterfaceDeviceW equ <SetupDiCreateDeviceInterfaceW>
    SetupDiCreateInterfaceDeviceA equ <SetupDiCreateDeviceInterfaceA>
    ifdef UNICODE
      SetupDiCreateInterfaceDevice equ <SetupDiCreateDeviceInterfaceW>
    else
      SetupDiCreateInterfaceDevice equ <SetupDiCreateDeviceInterfaceA>
    endif
    ; Flags for SetupDiOpenDeviceInterface
    DIODI_NO_ADD equ 00000001h
    @DefProto DllImport, SetupDiOpenDeviceInterfaceA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PCSTR, :DWORD, :PSP_DEVICE_INTERFACE_DATA>, 16
    @DefProto DllImport, SetupDiOpenDeviceInterfaceW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PCWSTR, :DWORD, :PSP_DEVICE_INTERFACE_DATA>, 16
    ifdef UNICODE
      SetupDiOpenDeviceInterface equ <SetupDiOpenDeviceInterfaceW>
    else
      SetupDiOpenDeviceInterface equ <SetupDiOpenDeviceInterfaceA>
    endif
    ; Backward compatibility--do not use
    SetupDiOpenInterfaceDeviceW equ <SetupDiOpenDeviceInterfaceW>
    SetupDiOpenInterfaceDeviceA equ <SetupDiOpenDeviceInterfaceA>
    ifdef UNICODE
      SetupDiOpenInterfaceDevice equ <SetupDiOpenDeviceInterfaceW>
    else
      SetupDiOpenInterfaceDevice equ <SetupDiOpenDeviceInterfaceA>
    endif
    @DefProto DllImport, SetupDiGetDeviceInterfaceAlias, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :ptr GUID, :PSP_DEVICE_INTERFACE_DATA>, 16
    ; Backward compatibility--do not use.
    SetupDiGetInterfaceDeviceAlias equ <SetupDiGetDeviceInterfaceAlias>
    @DefProto DllImport, SetupDiDeleteDeviceInterfaceData, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA>, 8
    ; Backward compatibility--do not use.
    SetupDiDeleteInterfaceDeviceData equ <SetupDiDeleteDeviceInterfaceData>
    @DefProto DllImport, SetupDiRemoveDeviceInterface, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA>, 8
    ; Backward compatibility--do not use.
    SetupDiRemoveInterfaceDevice equ <SetupDiRemoveDeviceInterface>
    @DefProto DllImport, SetupDiGetDeviceInterfaceDetailA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :PSP_DEVICE_INTERFACE_DETAIL_DATA_A, :DWORD, :PDWORD, :PSP_DEVINFO_DATA>, 24
    @DefProto DllImport, SetupDiGetDeviceInterfaceDetailW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :PSP_DEVICE_INTERFACE_DETAIL_DATA_W, :DWORD, :PDWORD, :PSP_DEVINFO_DATA>, 24
    ifdef UNICODE
      SetupDiGetDeviceInterfaceDetail equ <SetupDiGetDeviceInterfaceDetailW>
    else
      SetupDiGetDeviceInterfaceDetail equ <SetupDiGetDeviceInterfaceDetailA>
    endif
    ; Backward compatibility--do not use.
    SetupDiGetInterfaceDeviceDetailW equ <SetupDiGetDeviceInterfaceDetailW>
    SetupDiGetInterfaceDeviceDetailA equ <SetupDiGetDeviceInterfaceDetailA>
    ifdef UNICODE
      SetupDiGetInterfaceDeviceDetail equ <SetupDiGetDeviceInterfaceDetailW>
    else
      SetupDiGetInterfaceDeviceDetail equ <SetupDiGetDeviceInterfaceDetailA>
    endif
    ; Default install handler for DIF_INSTALLINTERFACES.
    @DefProto DllImport, SetupDiInstallDeviceInterfaces, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Backward compatibility--do not use.
    SetupDiInstallInterfaceDevices equ <SetupDiInstallDeviceInterfaces>
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupDiSetDeviceInterfaceDefault, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :DWORD, :PVOID>, 16
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    ; Default install handler for DIF_REGISTERDEVICE
    ; Flags for SetupDiRegisterDeviceInfo
    SPRDI_FIND_DUPS equ 00000001h
    @DefProto DllImport, SetupDiRegisterDeviceInfo, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :PSP_DETSIG_CMPPROC, :PVOID, :PSP_DEVINFO_DATA>, 24
    ; Ordinal values distinguishing between class drivers and
    ; device drivers.
    ; (Passed in 'DriverType' parameter of driver information list APIs)
    SPDIT_NODRIVER equ 00000000h
    SPDIT_CLASSDRIVER equ 00000001h
    SPDIT_COMPATDRIVER equ 00000002h
    @DefProto DllImport, SetupDiBuildDriverInfoList, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD>, 12
    @DefProto DllImport, SetupDiCancelDriverInfoSearch, WIN_STD_CALL_CONV,, <:HDEVINFO>, 4
    @DefProto DllImport, SetupDiEnumDriverInfoA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :DWORD, :PSP_DRVINFO_DATA_A>, 20
    @DefProto DllImport, SetupDiEnumDriverInfoW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :DWORD, :PSP_DRVINFO_DATA_W>, 20
    ifdef UNICODE
      SetupDiEnumDriverInfo equ <SetupDiEnumDriverInfoW>
    else
      SetupDiEnumDriverInfo equ <SetupDiEnumDriverInfoA>
    endif
    @DefProto DllImport, SetupDiGetSelectedDriverA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_A>, 12
    @DefProto DllImport, SetupDiGetSelectedDriverW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_W>, 12
    ifdef UNICODE
      SetupDiGetSelectedDriver equ <SetupDiGetSelectedDriverW>
    else
      SetupDiGetSelectedDriver equ <SetupDiGetSelectedDriverA>
    endif
    @DefProto DllImport, SetupDiSetSelectedDriverA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_A>, 12
    @DefProto DllImport, SetupDiSetSelectedDriverW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_W>, 12
    ifdef UNICODE
      SetupDiSetSelectedDriver equ <SetupDiSetSelectedDriverW>
    else
      SetupDiSetSelectedDriver equ <SetupDiSetSelectedDriverA>
    endif
    @DefProto DllImport, SetupDiGetDriverInfoDetailA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_A, :PSP_DRVINFO_DETAIL_DATA_A, :DWORD, :PDWORD>, 24
    @DefProto DllImport, SetupDiGetDriverInfoDetailW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_W, :PSP_DRVINFO_DETAIL_DATA_W, :DWORD, :PDWORD>, 24
    ifdef UNICODE
      SetupDiGetDriverInfoDetail equ <SetupDiGetDriverInfoDetailW>
    else
      SetupDiGetDriverInfoDetail equ <SetupDiGetDriverInfoDetailA>
    endif
    @DefProto DllImport, SetupDiDestroyDriverInfoList, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD>, 12
    ; Flags controlling what is included in the device information set built
    ; by SetupDiGetClassDevs
    DIGCF_DEFAULT equ 00000001h; only valid with DIGCF_DEVICEINTERFACE

    DIGCF_PRESENT equ 00000002h
    DIGCF_ALLCLASSES equ 00000004h
    DIGCF_PROFILE equ 00000008h
    DIGCF_DEVICEINTERFACE equ 00000010h
    ; Backward compatibility--do not use.
    DIGCF_INTERFACEDEVICE equ <DIGCF_DEVICEINTERFACE>
    @DefProto DllImport, SetupDiGetClassDevsA, WIN_STD_CALL_CONV,, <:ptr GUID, :PCSTR, :HWND, :DWORD>, 16
    @DefProto DllImport, SetupDiGetClassDevsW, WIN_STD_CALL_CONV,, <:ptr GUID, :PCWSTR, :HWND, :DWORD>, 16
    ifdef UNICODE
      SetupDiGetClassDevs equ <SetupDiGetClassDevsW>
    else
      SetupDiGetClassDevs equ <SetupDiGetClassDevsA>
    endif
    @DefProto DllImport, SetupDiGetClassDevsExA, WIN_STD_CALL_CONV,, <:ptr GUID, :PCSTR, :HWND, :DWORD, :HDEVINFO, :PCSTR, :PVOID>, 28
    @DefProto DllImport, SetupDiGetClassDevsExW, WIN_STD_CALL_CONV,, <:ptr GUID, :PCWSTR, :HWND, :DWORD, :HDEVINFO, :PCWSTR, :PVOID>, 28
    ifdef UNICODE
      SetupDiGetClassDevsEx equ <SetupDiGetClassDevsExW>
    else
      SetupDiGetClassDevsEx equ <SetupDiGetClassDevsExA>
    endif
    @DefProto DllImport, SetupDiGetINFClassA, WIN_STD_CALL_CONV,, <:PCSTR, :LPGUID, :PSTR, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupDiGetINFClassW, WIN_STD_CALL_CONV,, <:PCWSTR, :LPGUID, :PWSTR, :DWORD, :PDWORD>, 20
    ifdef UNICODE
      SetupDiGetINFClass equ <SetupDiGetINFClassW>
    else
      SetupDiGetINFClass equ <SetupDiGetINFClassA>
    endif
    ; Flags controlling exclusion from the class information list built
    ; by SetupDiBuildClassInfoList(Ex)
    DIBCI_NOINSTALLCLASS equ 00000001h
    DIBCI_NODISPLAYCLASS equ 00000002h
    @DefProto DllImport, SetupDiBuildClassInfoList, WIN_STD_CALL_CONV,, <:DWORD, :LPGUID, :DWORD, :PDWORD>, 16
    @DefProto DllImport, SetupDiBuildClassInfoListExA, WIN_STD_CALL_CONV,, <:DWORD, :LPGUID, :DWORD, :PDWORD, :PCSTR, :PVOID>, 24
    @DefProto DllImport, SetupDiBuildClassInfoListExW, WIN_STD_CALL_CONV,, <:DWORD, :LPGUID, :DWORD, :PDWORD, :PCWSTR, :PVOID>, 24
    ifdef UNICODE
      SetupDiBuildClassInfoListEx equ <SetupDiBuildClassInfoListExW>
    else
      SetupDiBuildClassInfoListEx equ <SetupDiBuildClassInfoListExA>
    endif
    @DefProto DllImport, SetupDiGetClassDescriptionA, WIN_STD_CALL_CONV,, <:ptr GUID, :PSTR, :DWORD, :PDWORD>, 16
    @DefProto DllImport, SetupDiGetClassDescriptionW, WIN_STD_CALL_CONV,, <:ptr GUID, :PWSTR, :DWORD, :PDWORD>, 16
    ifdef UNICODE
      SetupDiGetClassDescription equ <SetupDiGetClassDescriptionW>
    else
      SetupDiGetClassDescription equ <SetupDiGetClassDescriptionA>
    endif
    @DefProto DllImport, SetupDiGetClassDescriptionExA, WIN_STD_CALL_CONV,, <:ptr GUID, :PSTR, :DWORD, :PDWORD, :PCSTR, :PVOID>, 24
    @DefProto DllImport, SetupDiGetClassDescriptionExW, WIN_STD_CALL_CONV,, <:ptr GUID, :PWSTR, :DWORD, :PDWORD, :PCWSTR, :PVOID>, 24
    ifdef UNICODE
      SetupDiGetClassDescriptionEx equ <SetupDiGetClassDescriptionExW>
    else
      SetupDiGetClassDescriptionEx equ <SetupDiGetClassDescriptionExA>
    endif
    @DefProto DllImport, SetupDiCallClassInstaller, WIN_STD_CALL_CONV,, <:DI_FUNCTION, :HDEVINFO, :PSP_DEVINFO_DATA>, 12
    ; Default install handler for DIF_SELECTDEVICE
    @DefProto DllImport, SetupDiSelectDevice, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Default install handler for DIF_SELECTBESTCOMPATDRV
    @DefProto DllImport, SetupDiSelectBestCompatDrv, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Default install handler for DIF_INSTALLDEVICE
    @DefProto DllImport, SetupDiInstallDevice, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Default install handler for DIF_INSTALLDEVICEFILES
    @DefProto DllImport, SetupDiInstallDriverFiles, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Default install handler for DIF_REGISTER_COINSTALLERS
    @DefProto DllImport, SetupDiRegisterCoDeviceInstallers, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Default install handler for DIF_REMOVE
    @DefProto DllImport, SetupDiRemoveDevice, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    ; Default install handler for DIF_UNREMOVE
    @DefProto DllImport, SetupDiUnremoveDevice, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    if _SETUPAPI_VER ge _WIN32_WINNT_WS03
      @DefProto DllImport, SetupDiRestartDevices, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WS03
    ; Default install handler for DIF_PROPERTYCHANGE
    @DefProto DllImport, SetupDiChangeState, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    @DefProto DllImport, SetupDiInstallClassA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :DWORD, :HSPFILEQ>, 16
    @DefProto DllImport, SetupDiInstallClassW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :DWORD, :HSPFILEQ>, 16
    ifdef UNICODE
      SetupDiInstallClass equ <SetupDiInstallClassW>
    else
      SetupDiInstallClass equ <SetupDiInstallClassA>
    endif
    @DefProto DllImport, SetupDiInstallClassExA, WIN_STD_CALL_CONV,, <:HWND, :PCSTR, :DWORD, :HSPFILEQ, :ptr GUID, :PVOID, :PVOID>, 28
    @DefProto DllImport, SetupDiInstallClassExW, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :DWORD, :HSPFILEQ, :ptr GUID, :PVOID, :PVOID>, 28
    ifdef UNICODE
      SetupDiInstallClassEx equ <SetupDiInstallClassExW>
    else
      SetupDiInstallClassEx equ <SetupDiInstallClassExA>
    endif
    @DefProto DllImport, SetupDiOpenClassRegKey, WIN_STD_CALL_CONV,, <:ptr GUID, :REGSAM>, 8
    ; Flags for SetupDiOpenClassRegKeyEx
    DIOCR_INSTALLER equ 00000001h; class installer registry branch

    DIOCR_INTERFACE equ 00000002h; interface class registry branch

    @DefProto DllImport, SetupDiOpenClassRegKeyExA, WIN_STD_CALL_CONV,, <:ptr GUID, :REGSAM, :DWORD, :PCSTR, :PVOID>, 20
    @DefProto DllImport, SetupDiOpenClassRegKeyExW, WIN_STD_CALL_CONV,, <:ptr GUID, :REGSAM, :DWORD, :PCWSTR, :PVOID>, 20
    ifdef UNICODE
      SetupDiOpenClassRegKeyEx equ <SetupDiOpenClassRegKeyExW>
    else
      SetupDiOpenClassRegKeyEx equ <SetupDiOpenClassRegKeyExA>
    endif
    @DefProto DllImport, SetupDiCreateDeviceInterfaceRegKeyA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :DWORD, :REGSAM, :HINF, :PCSTR>, 24
    @DefProto DllImport, SetupDiCreateDeviceInterfaceRegKeyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :DWORD, :REGSAM, :HINF, :PCWSTR>, 24
    ifdef UNICODE
      SetupDiCreateDeviceInterfaceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyW>
    else
      SetupDiCreateDeviceInterfaceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyA>
    endif
    ; Backward compatibility--do not use.
    SetupDiCreateInterfaceDeviceRegKeyW equ <SetupDiCreateDeviceInterfaceRegKeyW>
    SetupDiCreateInterfaceDeviceRegKeyA equ <SetupDiCreateDeviceInterfaceRegKeyA>
    ifdef UNICODE
      SetupDiCreateInterfaceDeviceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyW>
    else
      SetupDiCreateInterfaceDeviceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyA>
    endif
    @DefProto DllImport, SetupDiOpenDeviceInterfaceRegKey, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :DWORD, :REGSAM>, 16
    ; Backward compatibility--do not use.
    SetupDiOpenInterfaceDeviceRegKey equ <SetupDiOpenDeviceInterfaceRegKey>
    @DefProto DllImport, SetupDiDeleteDeviceInterfaceRegKey, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :DWORD>, 12
    ; Backward compatibility--do not use.
    SetupDiDeleteInterfaceDeviceRegKey equ <SetupDiDeleteDeviceInterfaceRegKey>
    ; KeyType values for SetupDiCreateDevRegKey, SetupDiOpenDevRegKey, and
    ; SetupDiDeleteDevRegKey.
    DIREG_DEV equ 00000001h; Open/Create/Delete device key

    DIREG_DRV equ 00000002h; Open/Create/Delete driver key

    DIREG_BOTH equ 00000004h; Delete both driver and Device key

    @DefProto DllImport, SetupDiCreateDevRegKeyA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :DWORD, :DWORD, :HINF, :PCSTR>, 28
    @DefProto DllImport, SetupDiCreateDevRegKeyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :DWORD, :DWORD, :HINF, :PCWSTR>, 28
    ifdef UNICODE
      SetupDiCreateDevRegKey equ <SetupDiCreateDevRegKeyW>
    else
      SetupDiCreateDevRegKey equ <SetupDiCreateDevRegKeyA>
    endif
    @DefProto DllImport, SetupDiOpenDevRegKey, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :DWORD, :DWORD, :REGSAM>, 24
    @DefProto DllImport, SetupDiDeleteDevRegKey, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :DWORD, :DWORD>, 20
    @DefProto DllImport, SetupDiGetHwProfileList, WIN_STD_CALL_CONV,, <:PDWORD, :DWORD, :PDWORD, :PDWORD>, 16
    @DefProto DllImport, SetupDiGetHwProfileListExA, WIN_STD_CALL_CONV,, <:PDWORD, :DWORD, :PDWORD, :PDWORD, :PCSTR, :PVOID>, 24
    @DefProto DllImport, SetupDiGetHwProfileListExW, WIN_STD_CALL_CONV,, <:PDWORD, :DWORD, :PDWORD, :PDWORD, :PCWSTR, :PVOID>, 24
    ifdef UNICODE
      SetupDiGetHwProfileListEx equ <SetupDiGetHwProfileListExW>
    else
      SetupDiGetHwProfileListEx equ <SetupDiGetHwProfileListExA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      @DefProto DllImport, SetupDiGetDevicePropertyKeys, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :ptr DEVPROPKEY, :DWORD, :PDWORD, :DWORD>, 24
      @DefProto DllImport, SetupDiGetDevicePropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :ptr DEVPROPKEY, :ptr DEVPROPTYPE, :PBYTE, :DWORD, :PDWORD, :DWORD>, 32
      ifdef UNICODE
        SetupDiGetDeviceProperty equ <SetupDiGetDevicePropertyW>
      endif
      @DefProto DllImport, SetupDiSetDevicePropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :ptr DEVPROPKEY, :DEVPROPTYPE, :PBYTE, :DWORD, :DWORD>, 28
      ifdef UNICODE
        SetupDiSetDeviceProperty equ <SetupDiSetDevicePropertyW>
      endif
      @DefProto DllImport, SetupDiGetDeviceInterfacePropertyKeys, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :ptr DEVPROPKEY, :DWORD, :PDWORD, :DWORD>, 24
      @DefProto DllImport, SetupDiGetDeviceInterfacePropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :ptr DEVPROPKEY, :ptr DEVPROPTYPE, :PBYTE, :DWORD, :PDWORD, :DWORD>, 32
      ifdef UNICODE
        SetupDiGetDeviceInterfaceProperty equ <SetupDiGetDeviceInterfacePropertyW>
      endif
      @DefProto DllImport, SetupDiSetDeviceInterfacePropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVICE_INTERFACE_DATA, :ptr DEVPROPKEY, :DEVPROPTYPE, :PBYTE, :DWORD, :DWORD>, 28
      ifdef UNICODE
        SetupDiSetDeviceInterfaceProperty equ <SetupDiSetDeviceInterfacePropertyW>
      endif
      ; Flags for SetupDiGetClassPropertyKeys, SetupDiGetClassProperty, and
      ; SetupDiSetClassProperty.
      DICLASSPROP_INSTALLER equ 00000001h; device setup class property

      DICLASSPROP_INTERFACE equ 00000002h; device interface class property

      @DefProto DllImport, SetupDiGetClassPropertyKeys, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr DEVPROPKEY, :DWORD, :PDWORD, :DWORD>, 20
      @DefProto DllImport, SetupDiGetClassPropertyKeysExW, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr DEVPROPKEY, :DWORD, :PDWORD, :DWORD, :PCWSTR, :PVOID>, 28
      ifdef UNICODE
        SetupDiGetClassPropertyKeysEx equ <SetupDiGetClassPropertyKeysExW>
      endif
      @DefProto DllImport, SetupDiGetClassPropertyW, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr DEVPROPKEY, :ptr DEVPROPTYPE, :PBYTE, :DWORD, :PDWORD, :DWORD>, 28
      ifdef UNICODE
        SetupDiGetClassProperty equ <SetupDiGetClassPropertyW>
      endif
      @DefProto DllImport, SetupDiGetClassPropertyExW, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr DEVPROPKEY, :ptr DEVPROPTYPE, :PBYTE, :DWORD, :PDWORD, :DWORD, :PCWSTR, :PVOID>, 36
      ifdef UNICODE
        SetupDiGetClassPropertyEx equ <SetupDiGetClassPropertyExW>
      endif
      @DefProto DllImport, SetupDiSetClassPropertyW, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr DEVPROPKEY, :DEVPROPTYPE, :PBYTE, :DWORD, :DWORD>, 24
      ifdef UNICODE
        SetupDiSetClassProperty equ <SetupDiSetClassPropertyW>
      endif
      @DefProto DllImport, SetupDiSetClassPropertyExW, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr DEVPROPKEY, :DEVPROPTYPE, :PBYTE, :DWORD, :DWORD, :PCWSTR, :PVOID>, 32
      ifdef UNICODE
        SetupDiSetClassPropertyEx equ <SetupDiSetClassPropertyExW>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    ; Device registry property codes
    ; (Codes marked as read-only (R) may only be used for
    ; SetupDiGetDeviceRegistryProperty)
    ; These values should cover the same set of registry properties
    ; as defined by the CM_DRP codes in cfgmgr32.h.
    ; Note that SPDRP codes are zero based while CM_DRP codes are one based!
    SPDRP_DEVICEDESC equ (00000000h); DeviceDesc (R/W)

    SPDRP_HARDWAREID equ (00000001h); HardwareID (R/W)

    SPDRP_COMPATIBLEIDS equ (00000002h); CompatibleIDs (R/W)

    SPDRP_UNUSED0 equ (00000003h); unused

    SPDRP_SERVICE equ (00000004h); Service (R/W)

    SPDRP_UNUSED1 equ (00000005h); unused

    SPDRP_UNUSED2 equ (00000006h); unused

    SPDRP_CLASS equ (00000007h); Class (R--tied to ClassGUID)

    SPDRP_CLASSGUID equ (00000008h); ClassGUID (R/W)

    SPDRP_DRIVER equ (00000009h); Driver (R/W)

    SPDRP_CONFIGFLAGS equ (0000000Ah); ConfigFlags (R/W)

    SPDRP_MFG equ (0000000Bh); Mfg (R/W)

    SPDRP_FRIENDLYNAME equ (0000000Ch); FriendlyName (R/W)

    SPDRP_LOCATION_INFORMATION equ (0000000Dh); LocationInformation (R/W)

    SPDRP_PHYSICAL_DEVICE_OBJECT_NAME equ (0000000Eh); PhysicalDeviceObjectName (R)

    SPDRP_CAPABILITIES equ (0000000Fh); Capabilities (R)

    SPDRP_UI_NUMBER equ (00000010h); UiNumber (R)

    SPDRP_UPPERFILTERS equ (00000011h); UpperFilters (R/W)

    SPDRP_LOWERFILTERS equ (00000012h); LowerFilters (R/W)

    SPDRP_BUSTYPEGUID equ (00000013h); BusTypeGUID (R)

    SPDRP_LEGACYBUSTYPE equ (00000014h); LegacyBusType (R)

    SPDRP_BUSNUMBER equ (00000015h); BusNumber (R)

    SPDRP_ENUMERATOR_NAME equ (00000016h); Enumerator Name (R)

    SPDRP_SECURITY equ (00000017h); Security (R/W, binary form)

    SPDRP_SECURITY_SDS equ (00000018h); Security (W, SDS form)

    SPDRP_DEVTYPE equ (00000019h); Device Type (R/W)

    SPDRP_EXCLUSIVE equ (0000001Ah); Device is exclusive-access (R/W)

    SPDRP_CHARACTERISTICS equ (0000001Bh); Device Characteristics (R/W)

    SPDRP_ADDRESS equ (0000001Ch); Device Address (R)

    SPDRP_UI_NUMBER_DESC_FORMAT equ (0000001Dh); UiNumberDescFormat (R/W)

    SPDRP_DEVICE_POWER_DATA equ (0000001Eh); Device Power Data (R)

    SPDRP_REMOVAL_POLICY equ (0000001Fh); Removal Policy (R)

    SPDRP_REMOVAL_POLICY_HW_DEFAULT equ (00000020h); Hardware Removal Policy (R)

    SPDRP_REMOVAL_POLICY_OVERRIDE equ (00000021h); Removal Policy Override (RW)

    SPDRP_INSTALL_STATE equ (00000022h); Device Install State (R)

    SPDRP_LOCATION_PATHS equ (00000023h); Device Location Paths (R)

    SPDRP_BASE_CONTAINERID equ (00000024h); Base ContainerID (R)

    SPDRP_MAXIMUM_PROPERTY equ (00000025h); Upper bound on ordinals

    ; Class registry property codes
    ; (Codes marked as read-only (R) may only be used for
    ; SetupDiGetClassRegistryProperty)
    ; These values should cover the same set of registry properties
    ; as defined by the CM_CRP codes in cfgmgr32.h.
    ; they should also have a 1:1 correspondence with Device registers, where applicable
    ; but no overlap otherwise
    SPCRP_UPPERFILTERS equ (00000011h); UpperFilters (R/W)

    SPCRP_LOWERFILTERS equ (00000012h); LowerFilters (R/W)

    SPCRP_SECURITY equ (00000017h); Security (R/W, binary form)

    SPCRP_SECURITY_SDS equ (00000018h); Security (W, SDS form)

    SPCRP_DEVTYPE equ (00000019h); Device Type (R/W)

    SPCRP_EXCLUSIVE equ (0000001Ah); Device is exclusive-access (R/W)

    SPCRP_CHARACTERISTICS equ (0000001Bh); Device Characteristics (R/W)

    SPCRP_MAXIMUM_PROPERTY equ (0000001Ch); Upper bound on ordinals

    @DefProto DllImport, SetupDiGetDeviceRegistryPropertyA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :PDWORD, :PBYTE, :DWORD, :PDWORD>, 28
    @DefProto DllImport, SetupDiGetDeviceRegistryPropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :PDWORD, :PBYTE, :DWORD, :PDWORD>, 28
    ifdef UNICODE
      SetupDiGetDeviceRegistryProperty equ <SetupDiGetDeviceRegistryPropertyW>
    else
      SetupDiGetDeviceRegistryProperty equ <SetupDiGetDeviceRegistryPropertyA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupDiGetClassRegistryPropertyA, WIN_STD_CALL_CONV,, <:ptr GUID, :DWORD, :PDWORD, :PBYTE, :DWORD, :PDWORD, :PCSTR, :PVOID>, 32
      @DefProto DllImport, SetupDiGetClassRegistryPropertyW, WIN_STD_CALL_CONV,, <:ptr GUID, :DWORD, :PDWORD, :PBYTE, :DWORD, :PDWORD, :PCWSTR, :PVOID>, 32
      ifdef UNICODE
        SetupDiGetClassRegistryProperty equ <SetupDiGetClassRegistryPropertyW>
      else
        SetupDiGetClassRegistryProperty equ <SetupDiGetClassRegistryPropertyA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    @DefProto DllImport, SetupDiSetDeviceRegistryPropertyA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :ptr BYTE, :DWORD>, 20
    @DefProto DllImport, SetupDiSetDeviceRegistryPropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :DWORD, :ptr BYTE, :DWORD>, 20
    ifdef UNICODE
      SetupDiSetDeviceRegistryProperty equ <SetupDiSetDeviceRegistryPropertyW>
    else
      SetupDiSetDeviceRegistryProperty equ <SetupDiSetDeviceRegistryPropertyA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupDiSetClassRegistryPropertyA, WIN_STD_CALL_CONV,, <:ptr GUID, :DWORD, :ptr BYTE, :DWORD, :PCSTR, :PVOID>, 24
      @DefProto DllImport, SetupDiSetClassRegistryPropertyW, WIN_STD_CALL_CONV,, <:ptr GUID, :DWORD, :ptr BYTE, :DWORD, :PCWSTR, :PVOID>, 24
      ifdef UNICODE
        SetupDiSetClassRegistryProperty equ <SetupDiSetClassRegistryPropertyW>
      else
        SetupDiSetClassRegistryProperty equ <SetupDiSetClassRegistryPropertyA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    @DefProto DllImport, SetupDiGetDeviceInstallParamsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DEVINSTALL_PARAMS_A>, 12
    @DefProto DllImport, SetupDiGetDeviceInstallParamsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DEVINSTALL_PARAMS_W>, 12
    ifdef UNICODE
      SetupDiGetDeviceInstallParams equ <SetupDiGetDeviceInstallParamsW>
    else
      SetupDiGetDeviceInstallParams equ <SetupDiGetDeviceInstallParamsA>
    endif
    @DefProto DllImport, SetupDiGetClassInstallParamsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_CLASSINSTALL_HEADER, :DWORD, :PDWORD>, 20
    @DefProto DllImport, SetupDiGetClassInstallParamsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_CLASSINSTALL_HEADER, :DWORD, :PDWORD>, 20
    ifdef UNICODE
      SetupDiGetClassInstallParams equ <SetupDiGetClassInstallParamsW>
    else
      SetupDiGetClassInstallParams equ <SetupDiGetClassInstallParamsA>
    endif
    @DefProto DllImport, SetupDiSetDeviceInstallParamsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DEVINSTALL_PARAMS_A>, 12
    @DefProto DllImport, SetupDiSetDeviceInstallParamsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DEVINSTALL_PARAMS_W>, 12
    ifdef UNICODE
      SetupDiSetDeviceInstallParams equ <SetupDiSetDeviceInstallParamsW>
    else
      SetupDiSetDeviceInstallParams equ <SetupDiSetDeviceInstallParamsA>
    endif
    @DefProto DllImport, SetupDiSetClassInstallParamsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_CLASSINSTALL_HEADER, :DWORD>, 16
    @DefProto DllImport, SetupDiSetClassInstallParamsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_CLASSINSTALL_HEADER, :DWORD>, 16
    ifdef UNICODE
      SetupDiSetClassInstallParams equ <SetupDiSetClassInstallParamsW>
    else
      SetupDiSetClassInstallParams equ <SetupDiSetClassInstallParamsA>
    endif
    @DefProto DllImport, SetupDiGetDriverInstallParamsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_A, :PSP_DRVINSTALL_PARAMS>, 16
    @DefProto DllImport, SetupDiGetDriverInstallParamsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_W, :PSP_DRVINSTALL_PARAMS>, 16
    ifdef UNICODE
      SetupDiGetDriverInstallParams equ <SetupDiGetDriverInstallParamsW>
    else
      SetupDiGetDriverInstallParams equ <SetupDiGetDriverInstallParamsA>
    endif
    @DefProto DllImport, SetupDiSetDriverInstallParamsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_A, :PSP_DRVINSTALL_PARAMS>, 16
    @DefProto DllImport, SetupDiSetDriverInstallParamsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_DRVINFO_DATA_W, :PSP_DRVINSTALL_PARAMS>, 16
    ifdef UNICODE
      SetupDiSetDriverInstallParams equ <SetupDiSetDriverInstallParamsW>
    else
      SetupDiSetDriverInstallParams equ <SetupDiSetDriverInstallParamsA>
    endif
    @DefProto DllImport, SetupDiLoadClassIcon, WIN_STD_CALL_CONV,, <:ptr GUID, :ptr HICON, :PINT>, 12
    if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
      @DefProto DllImport, SetupDiLoadDeviceIcon, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :UINT, :UINT, :DWORD, :ptr HICON>, 24
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
    ; Flags controlling the drawing of mini-icons
    DMI_MASK equ 00000001h
    DMI_BKCOLOR equ 00000002h
    DMI_USERECT equ 00000004h
    @DefProto DllImport, SetupDiDrawMiniIcon, WIN_STD_CALL_CONV,, <:HDC, :RECT, :INT_, :DWORD>, 16
    @DefProto DllImport, SetupDiGetClassBitmapIndex, WIN_STD_CALL_CONV,, <:ptr GUID, :PINT>, 8
    @DefProto DllImport, SetupDiGetClassImageList, WIN_STD_CALL_CONV,, <:PSP_CLASSIMAGELIST_DATA>, 4
    @DefProto DllImport, SetupDiGetClassImageListExA, WIN_STD_CALL_CONV,, <:PSP_CLASSIMAGELIST_DATA, :PCSTR, :PVOID>, 12
    @DefProto DllImport, SetupDiGetClassImageListExW, WIN_STD_CALL_CONV,, <:PSP_CLASSIMAGELIST_DATA, :PCWSTR, :PVOID>, 12
    ifdef UNICODE
      SetupDiGetClassImageListEx equ <SetupDiGetClassImageListExW>
    else
      SetupDiGetClassImageListEx equ <SetupDiGetClassImageListExA>
    endif
    @DefProto DllImport, SetupDiGetClassImageIndex, WIN_STD_CALL_CONV,, <:PSP_CLASSIMAGELIST_DATA, :ptr GUID, :PINT>, 12
    @DefProto DllImport, SetupDiDestroyClassImageList, WIN_STD_CALL_CONV,, <:PSP_CLASSIMAGELIST_DATA>, 4
    ; PropertySheetType values for the SetupDiGetClassDevPropertySheets API
    DIGCDP_FLAG_BASIC equ 00000001h
    DIGCDP_FLAG_ADVANCED equ 00000002h
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      DIGCDP_FLAG_REMOTE_BASIC equ 00000003h; not presently implemented

      DIGCDP_FLAG_REMOTE_ADVANCED equ 00000004h
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    @DefProto DllImport, SetupDiGetClassDevPropertySheetsA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :LPPROPSHEETHEADERA, :DWORD, :PDWORD, :DWORD>, 24
    @DefProto DllImport, SetupDiGetClassDevPropertySheetsW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :LPPROPSHEETHEADERW, :DWORD, :PDWORD, :DWORD>, 24
    ifdef UNICODE
      SetupDiGetClassDevPropertySheets equ <SetupDiGetClassDevPropertySheetsW>
    else
      SetupDiGetClassDevPropertySheets equ <SetupDiGetClassDevPropertySheetsA>
    endif
    ; Define ICON IDs publicly exposed from setupapi.
    IDI_RESOURCEFIRST equ 159
    IDI_RESOURCE equ 159
    IDI_RESOURCELAST equ 161
    IDI_RESOURCEOVERLAYFIRST equ 161
    IDI_RESOURCEOVERLAYLAST equ 161
    IDI_CONFLICT equ 161
    IDI_CLASSICON_OVERLAYFIRST equ 500
    IDI_CLASSICON_OVERLAYLAST equ 502
    IDI_PROBLEM_OVL equ 500
    IDI_DISABLED_OVL equ 501
    IDI_FORCED_OVL equ 502
    @DefProto DllImport, SetupDiAskForOEMDisk, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    @DefProto DllImport, SetupDiSelectOEMDrv, WIN_STD_CALL_CONV,, <:HWND, :HDEVINFO, :PSP_DEVINFO_DATA>, 12
    @DefProto DllImport, SetupDiClassNameFromGuidA, WIN_STD_CALL_CONV,, <:ptr GUID, :PSTR, :DWORD, :PDWORD>, 16
    @DefProto DllImport, SetupDiClassNameFromGuidW, WIN_STD_CALL_CONV,, <:ptr GUID, :PWSTR, :DWORD, :PDWORD>, 16
    ifdef UNICODE
      SetupDiClassNameFromGuid equ <SetupDiClassNameFromGuidW>
    else
      SetupDiClassNameFromGuid equ <SetupDiClassNameFromGuidA>
    endif
    @DefProto DllImport, SetupDiClassNameFromGuidExA, WIN_STD_CALL_CONV,, <:ptr GUID, :PSTR, :DWORD, :PDWORD, :PCSTR, :PVOID>, 24
    @DefProto DllImport, SetupDiClassNameFromGuidExW, WIN_STD_CALL_CONV,, <:ptr GUID, :PWSTR, :DWORD, :PDWORD, :PCWSTR, :PVOID>, 24
    ifdef UNICODE
      SetupDiClassNameFromGuidEx equ <SetupDiClassNameFromGuidExW>
    else
      SetupDiClassNameFromGuidEx equ <SetupDiClassNameFromGuidExA>
    endif
    @DefProto DllImport, SetupDiClassGuidsFromNameA, WIN_STD_CALL_CONV,, <:PCSTR, :LPGUID, :DWORD, :PDWORD>, 16
    @DefProto DllImport, SetupDiClassGuidsFromNameW, WIN_STD_CALL_CONV,, <:PCWSTR, :LPGUID, :DWORD, :PDWORD>, 16
    ifdef UNICODE
      SetupDiClassGuidsFromName equ <SetupDiClassGuidsFromNameW>
    else
      SetupDiClassGuidsFromName equ <SetupDiClassGuidsFromNameA>
    endif
    @DefProto DllImport, SetupDiClassGuidsFromNameExA, WIN_STD_CALL_CONV,, <:PCSTR, :LPGUID, :DWORD, :PDWORD, :PCSTR, :PVOID>, 24
    @DefProto DllImport, SetupDiClassGuidsFromNameExW, WIN_STD_CALL_CONV,, <:PCWSTR, :LPGUID, :DWORD, :PDWORD, :PCWSTR, :PVOID>, 24
    ifdef UNICODE
      SetupDiClassGuidsFromNameEx equ <SetupDiClassGuidsFromNameExW>
    else
      SetupDiClassGuidsFromNameEx equ <SetupDiClassGuidsFromNameExA>
    endif
    @DefProto DllImport, SetupDiGetHwProfileFriendlyNameA, WIN_STD_CALL_CONV,, <:DWORD, :PSTR, :DWORD, :PDWORD>, 16
    @DefProto DllImport, SetupDiGetHwProfileFriendlyNameW, WIN_STD_CALL_CONV,, <:DWORD, :PWSTR, :DWORD, :PDWORD>, 16
    ifdef UNICODE
      SetupDiGetHwProfileFriendlyName equ <SetupDiGetHwProfileFriendlyNameW>
    else
      SetupDiGetHwProfileFriendlyName equ <SetupDiGetHwProfileFriendlyNameA>
    endif
    @DefProto DllImport, SetupDiGetHwProfileFriendlyNameExA, WIN_STD_CALL_CONV,, <:DWORD, :PSTR, :DWORD, :PDWORD, :PCSTR, :PVOID>, 24
    @DefProto DllImport, SetupDiGetHwProfileFriendlyNameExW, WIN_STD_CALL_CONV,, <:DWORD, :PWSTR, :DWORD, :PDWORD, :PCWSTR, :PVOID>, 24
    ifdef UNICODE
      SetupDiGetHwProfileFriendlyNameEx equ <SetupDiGetHwProfileFriendlyNameExW>
    else
      SetupDiGetHwProfileFriendlyNameEx equ <SetupDiGetHwProfileFriendlyNameExA>
    endif
    ; PageType values for SetupDiGetWizardPage API
    SPWPT_SELECTDEVICE equ 00000001h
    ; Flags for SetupDiGetWizardPage API
    SPWP_USE_DEVINFO_DATA equ 00000001h
    @DefProto DllImport, SetupDiGetWizardPage, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PSP_INSTALLWIZARD_DATA, :DWORD, :DWORD>, 20
    @DefProto DllImport, SetupDiGetSelectedDevice, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    @DefProto DllImport, SetupDiSetSelectedDevice, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA>, 8
    if _SETUPAPI_VER ge _WIN32_WINNT_WS03
      @DefProto DllImport, SetupDiGetActualModelsSectionA, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :PSP_ALTPLATFORM_INFO, :PSTR, :DWORD, :PDWORD, :PVOID>, 24
      @DefProto DllImport, SetupDiGetActualModelsSectionW, WIN_STD_CALL_CONV,, <:PINFCONTEXT, :PSP_ALTPLATFORM_INFO, :PWSTR, :DWORD, :PDWORD, :PVOID>, 24
      ifdef UNICODE
        SetupDiGetActualModelsSection equ <SetupDiGetActualModelsSectionW>
      else
        SetupDiGetActualModelsSection equ <SetupDiGetActualModelsSectionA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WS03
    @DefProto DllImport, SetupDiGetActualSectionToInstallA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :PSTR, :DWORD, :PDWORD, :ptr PSTR>, 24
    @DefProto DllImport, SetupDiGetActualSectionToInstallW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :PWSTR, :DWORD, :PDWORD, :ptr PWSTR>, 24
    ifdef UNICODE
      SetupDiGetActualSectionToInstall equ <SetupDiGetActualSectionToInstallW>
    else
      SetupDiGetActualSectionToInstall equ <SetupDiGetActualSectionToInstallA>
    endif
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      @DefProto DllImport, SetupDiGetActualSectionToInstallExA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :PSP_ALTPLATFORM_INFO, :PSTR, :DWORD, :PDWORD, :ptr PSTR, :PVOID>, 32
      @DefProto DllImport, SetupDiGetActualSectionToInstallExW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :PSP_ALTPLATFORM_INFO, :PWSTR, :DWORD, :PDWORD, :ptr PWSTR, :PVOID>, 32
      ifdef UNICODE
        SetupDiGetActualSectionToInstallEx equ <SetupDiGetActualSectionToInstallExW>
      else
        SetupDiGetActualSectionToInstallEx equ <SetupDiGetActualSectionToInstallExA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; SetupEnumInfSections is for low-level parsing of an INF
      @DefProto DllImport, SetupEnumInfSectionsA, WIN_STD_CALL_CONV,, <:HINF, :UINT, :PSTR, :UINT, :ptr UINT>, 20
      @DefProto DllImport, SetupEnumInfSectionsW, WIN_STD_CALL_CONV,, <:HINF, :UINT, :PWSTR, :UINT, :ptr UINT>, 20
      ifdef UNICODE
        SetupEnumInfSections equ <SetupEnumInfSectionsW>
      else
        SetupEnumInfSections equ <SetupEnumInfSectionsA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      SP_INF_SIGNER_INFO_V1_A struct
        cbSize DWORD ?
        CatalogFile SBYTE MAX_PATH dup (?)
        DigitalSigner SBYTE MAX_PATH dup (?)
        DigitalSignerVersion SBYTE MAX_PATH dup (?)
      SP_INF_SIGNER_INFO_V1_A ends
      _SP_INF_SIGNER_INFO_V1_A typedef SP_INF_SIGNER_INFO_V1_A
      PSP_INF_SIGNER_INFO_V1_A typedef ptr SP_INF_SIGNER_INFO_V1_A
      SP_INF_SIGNER_INFO_V1_W struct
        cbSize DWORD ?
        CatalogFile WORD MAX_PATH dup (?)
        DigitalSigner WORD MAX_PATH dup (?)
        DigitalSignerVersion WORD MAX_PATH dup (?)
      SP_INF_SIGNER_INFO_V1_W ends
      _SP_INF_SIGNER_INFO_V1_W typedef SP_INF_SIGNER_INFO_V1_W
      PSP_INF_SIGNER_INFO_V1_W typedef ptr SP_INF_SIGNER_INFO_V1_W
      ifdef UNICODE
        SP_INF_SIGNER_INFO_V1 typedef SP_INF_SIGNER_INFO_V1_W
        PSP_INF_SIGNER_INFO_V1 typedef PSP_INF_SIGNER_INFO_V1_W
      else
        SP_INF_SIGNER_INFO_V1 typedef SP_INF_SIGNER_INFO_V1_A
        PSP_INF_SIGNER_INFO_V1 typedef PSP_INF_SIGNER_INFO_V1_A
      endif
      if _SETUPAPI_VER ge _WIN32_WINNT_LONGHORN
        SP_INF_SIGNER_INFO_V2_A struct
          cbSize DWORD ?
          CatalogFile SBYTE MAX_PATH dup (?)
          DigitalSigner SBYTE MAX_PATH dup (?)
          DigitalSignerVersion SBYTE MAX_PATH dup (?)
          SignerScore DWORD ?
        SP_INF_SIGNER_INFO_V2_A ends
        _SP_INF_SIGNER_INFO_V2_A typedef SP_INF_SIGNER_INFO_V2_A
        PSP_INF_SIGNER_INFO_V2_A typedef ptr SP_INF_SIGNER_INFO_V2_A
        SP_INF_SIGNER_INFO_V2_W struct
          cbSize DWORD ?
          CatalogFile WORD MAX_PATH dup (?)
          DigitalSigner WORD MAX_PATH dup (?)
          DigitalSignerVersion WORD MAX_PATH dup (?)
          SignerScore DWORD ?
        SP_INF_SIGNER_INFO_V2_W ends
        _SP_INF_SIGNER_INFO_V2_W typedef SP_INF_SIGNER_INFO_V2_W
        PSP_INF_SIGNER_INFO_V2_W typedef ptr SP_INF_SIGNER_INFO_V2_W
        ifdef UNICODE
          SP_INF_SIGNER_INFO_V2 typedef SP_INF_SIGNER_INFO_V2_W
          PSP_INF_SIGNER_INFO_V2 typedef PSP_INF_SIGNER_INFO_V2_W
        else
          SP_INF_SIGNER_INFO_V2 typedef SP_INF_SIGNER_INFO_V2_A
          PSP_INF_SIGNER_INFO_V2 typedef PSP_INF_SIGNER_INFO_V2_A
        endif
        ; Driver signer scores (high order bit of the signing byte means unsigned)
        SIGNERSCORE_UNKNOWN equ 0FF000000h
        SIGNERSCORE_W9X_SUSPECT equ 0C0000000h
        SIGNERSCORE_UNSIGNED equ 80000000h
        SIGNERSCORE_AUTHENTICODE equ 0F000000h
        SIGNERSCORE_WHQL equ 0D000005h; base WHQL.

        SIGNERSCORE_UNCLASSIFIED equ 0D000004h; UNCLASSIFIED == INBOX == STANDARD == PREMIUM when the SIGNERSCORE_MASK

        SIGNERSCORE_INBOX equ 0D000003h; filter is applied.

        SIGNERSCORE_LOGO_STANDARD equ 0D000002h
        SIGNERSCORE_LOGO_PREMIUM equ 0D000001h
        SIGNERSCORE_MASK equ 0FF000000h; Mask out all but the upper BYTE which contains the ranking signer information

        SIGNERSCORE_SIGNED_MASK equ 0F0000000h; Mask out only the upper nibble, which tells us if the package is signed or not.

      endif
      ; _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
      if USE_SP_INF_SIGNER_INFO_V1 or (_SETUPAPI_VER lt _WIN32_WINNT_LONGHORN)
        ; use version 1 signer info structure
        SP_INF_SIGNER_INFO_A typedef SP_INF_SIGNER_INFO_V1_A
        PSP_INF_SIGNER_INFO_A typedef PSP_INF_SIGNER_INFO_V1_A
        SP_INF_SIGNER_INFO_W typedef SP_INF_SIGNER_INFO_V1_W
        PSP_INF_SIGNER_INFO_W typedef PSP_INF_SIGNER_INFO_V1_W
        SP_INF_SIGNER_INFO typedef SP_INF_SIGNER_INFO_V1
        PSP_INF_SIGNER_INFO typedef PSP_INF_SIGNER_INFO_V1
      else
      ; use version 2 signer info structure
        SP_INF_SIGNER_INFO_A typedef SP_INF_SIGNER_INFO_V2_A
        PSP_INF_SIGNER_INFO_A typedef PSP_INF_SIGNER_INFO_V2_A
        SP_INF_SIGNER_INFO_W typedef SP_INF_SIGNER_INFO_V2_W
        PSP_INF_SIGNER_INFO_W typedef PSP_INF_SIGNER_INFO_V2_W
        SP_INF_SIGNER_INFO typedef SP_INF_SIGNER_INFO_V2
        PSP_INF_SIGNER_INFO typedef PSP_INF_SIGNER_INFO_V2
      endif
      ; use current version of signer info structure
      @DefProto DllImport, SetupVerifyInfFileA, WIN_STD_CALL_CONV,, <:PCSTR, :PSP_ALTPLATFORM_INFO, :PSP_INF_SIGNER_INFO_A>, 12
      @DefProto DllImport, SetupVerifyInfFileW, WIN_STD_CALL_CONV,, <:PCWSTR, :PSP_ALTPLATFORM_INFO, :PSP_INF_SIGNER_INFO_W>, 12
      ifdef UNICODE
        SetupVerifyInfFile equ <SetupVerifyInfFileW>
      else
        SetupVerifyInfFile equ <SetupVerifyInfFileA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WINXP
      ; Flags for use by SetupDiGetCustomDeviceProperty
      DICUSTOMDEVPROP_MERGE_MULTISZ equ 00000001h
      @DefProto DllImport, SetupDiGetCustomDevicePropertyA, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PCSTR, :DWORD, :PDWORD, :PBYTE, :DWORD, :PDWORD>, 32
      @DefProto DllImport, SetupDiGetCustomDevicePropertyW, WIN_STD_CALL_CONV,, <:HDEVINFO, :PSP_DEVINFO_DATA, :PCWSTR, :DWORD, :PDWORD, :PBYTE, :DWORD, :PDWORD>, 32
      ifdef UNICODE
        SetupDiGetCustomDeviceProperty equ <SetupDiGetCustomDevicePropertyW>
      else
        SetupDiGetCustomDeviceProperty equ <SetupDiGetCustomDevicePropertyA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WINXP
    if _SETUPAPI_VER ge _WIN32_WINNT_WS03
      ; To configure WMI security for downlevel platforms where the [DDInstall.WMI]
      ; section isn't natively supported by setupapi, a redistributable co-installer
      ; is supplied in the DDK for use on those platforms.
      ; Flags for use by SetupConfigureWmiFromInfSection
      SCWMI_CLOBBER_SECURITY equ 00000001h
      @DefProto DllImport, SetupConfigureWmiFromInfSectionA, WIN_STD_CALL_CONV,, <:HINF, :PCSTR, :DWORD>, 12
      @DefProto DllImport, SetupConfigureWmiFromInfSectionW, WIN_STD_CALL_CONV,, <:HINF, :PCWSTR, :DWORD>, 12
      ifdef UNICODE
        SetupConfigureWmiFromInfSection equ <SetupConfigureWmiFromInfSectionW>
      else
        SetupConfigureWmiFromInfSection equ <SetupConfigureWmiFromInfSectionA>
      endif
    endif
    ; _SETUPAPI_VER >= _WIN32_WINNT_WS03
    ifdef __cplusplus
      ;[...]
    endif
    include poppack.inc
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; _INC_SETUPAPI
