;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winbase.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:13:42

include winapifamily.inc
ifndef _WINBASE_
  _WINBASE_ equ <>
  if Defined(_MSC_VER)
    if _MSC_VER gt 1000
    endif
    if _MSC_VER ge 1200
    endif
  endif
  ifdef _MAC
    ;[...]
  endif
  include apisetcconv.inc
  include minwinbase.inc
  include apiquery2.inc
  include processenv.inc
  include fileapifromapp.inc
  include debugapi.inc
  include utilapiset.inc
  include handleapi.inc
  include errhandlingapi.inc
  include fibersapi.inc
  include namedpipeapi.inc
  include profileapi.inc
  include heapapi.inc
  include ioapiset.inc
  include synchapi.inc
  include interlockedapi.inc
  include processthreadsapi.inc
  include sysinfoapi.inc
  include memoryapi.inc
  include enclaveapi.inc
  include threadpoollegacyapiset.inc
  include threadpoolapiset.inc
  include jobapi.inc
  include jobapi2.inc
  include wow64apiset.inc
  include libloaderapi.inc
  include securitybaseapi.inc
  include namespaceapi.inc
  include systemtopologyapi.inc
  include processtopologyapi.inc
  include securityappcontainer.inc
  include realtimeapiset.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    DefineHandleTable macro w
      exitm <((w), TRUE)>
    endm
    LimitEmsPages macro dw_
      exitm <>
    endm
    SetSwapAreaSize macro w
      exitm <(w)>
    endm
    LockSegment macro w
      exitm <GlobalFix ((w))>
    endm
    UnlockSegment macro w
      exitm <GlobalUnfix ((w))>
    endm
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    GetCurrentTime macro 
      exitm <GetTickCount ()>
    endm
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    Yield macro 
      exitm <>
    endm
    FILE_BEGIN equ 0
    FILE_CURRENT equ 1
    FILE_END equ 2
    WAIT_FAILED equ (0FFFFFFFFh)
    WAIT_OBJECT_0 equ ((STATUS_WAIT_0) + 0)
    WAIT_ABANDONED equ ((STATUS_ABANDONED_WAIT_0) + 0)
    WAIT_ABANDONED_0 equ ((STATUS_ABANDONED_WAIT_0) + 0)
    WAIT_IO_COMPLETION equ <STATUS_USER_APC>
    SecureZeroMemory equ <RtlSecureZeroMemory>
    CaptureStackBackTrace equ <RtlCaptureStackBackTrace>
    FILE_FLAG_WRITE_THROUGH equ 80000000h
    FILE_FLAG_OVERLAPPED equ 40000000h
    FILE_FLAG_NO_BUFFERING equ 20000000h
    FILE_FLAG_RANDOM_ACCESS equ 10000000h
    FILE_FLAG_SEQUENTIAL_SCAN equ 08000000h
    FILE_FLAG_DELETE_ON_CLOSE equ 04000000h
    FILE_FLAG_BACKUP_SEMANTICS equ 02000000h
    FILE_FLAG_POSIX_SEMANTICS equ 01000000h
    FILE_FLAG_SESSION_AWARE equ 00800000h
    FILE_FLAG_OPEN_REPARSE_POINT equ 00200000h
    FILE_FLAG_OPEN_NO_RECALL equ 00100000h
    FILE_FLAG_FIRST_PIPE_INSTANCE equ 00080000h
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      FILE_FLAG_OPEN_REQUIRING_OPLOCK equ 00040000h
      if Defined(NTDDI_WIN10_NI) and (NTDDI_VERSION ge NTDDI_WIN10_NI)
        FILE_FLAG_IGNORE_IMPERSONATED_DEVICEMAP equ 00020000h
      endif
    endif
    if Defined(NTDDI_WIN10_NI) and (NTDDI_VERSION ge NTDDI_WIN10_NI)
      FILE_WRITE_FLAGS typedef SDWORD
      FILE_WRITE_FLAGS_NONE equ 0
      FILE_WRITE_FLAGS_WRITE_THROUGH equ 000000001h

      DEFINE_ENUM_FLAG_OPERATORS(FILE_WRITE_FLAGS)
      FILE_FLUSH_MODE typedef SDWORD
      FILE_FLUSH_DEFAULT equ 0
      FILE_FLUSH_DATA equ 1
      FILE_FLUSH_MIN_METADATA equ 2
      FILE_FLUSH_NO_SYNC equ 3

    endif
    if (_WIN32_WINNT ge 0400h)
      PROGRESS_CONTINUE equ 0
      PROGRESS_CANCEL equ 1
      PROGRESS_STOP equ 2
      PROGRESS_QUIET equ 3
      CALLBACK_CHUNK_FINISHED equ 00000000h
      CALLBACK_STREAM_SWITCH equ 00000001h
      COPY_FILE_FAIL_IF_EXISTS equ 00000001h
      COPY_FILE_RESTARTABLE equ 00000002h
      COPY_FILE_OPEN_SOURCE_FOR_WRITE equ 00000004h
      COPY_FILE_ALLOW_DECRYPTED_DESTINATION equ 00000008h
      if (_WIN32_WINNT ge 0600h)
        COPY_FILE_COPY_SYMLINK equ 00000800h
        COPY_FILE_NO_BUFFERING equ 00001000h
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        COPY_FILE_REQUEST_SECURITY_PRIVILEGES equ 00002000h
        COPY_FILE_RESUME_FROM_PAUSE equ 00004000h
        COPY_FILE_NO_OFFLOAD equ 00040000h
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
        COPY_FILE_IGNORE_EDP_BLOCK equ 00400000h
        COPY_FILE_IGNORE_SOURCE_ENCRYPTION equ 00800000h
        COPY_FILE_DONT_REQUEST_DEST_WRITE_DAC equ 02000000h
        COPY_FILE_REQUEST_COMPRESSED_TRAFFIC equ 10000000h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_VB)
        COPY_FILE_OPEN_AND_COPY_REPARSE_POINT equ 00200000h
        COPY_FILE_DIRECTORY equ 00000080h
        COPY_FILE_SKIP_ALTERNATE_STREAMS equ 00008000h
        COPY_FILE_DISABLE_PRE_ALLOCATION equ 04000000h
        COPY_FILE_ENABLE_LOW_FREE_SPACE_MODE equ 08000000h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_NI)
        COPY_FILE_ENABLE_SPARSE_COPY equ 20000000h
      endif
    endif
    if (_WIN32_WINNT ge 0500h)
      REPLACEFILE_WRITE_THROUGH equ 00000001h
      REPLACEFILE_IGNORE_MERGE_ERRORS equ 00000002h
      if (_WIN32_WINNT ge 0600h)
        REPLACEFILE_IGNORE_ACL_ERRORS equ 00000004h
      endif
    endif
    PIPE_ACCESS_INBOUND equ 00000001h
    PIPE_ACCESS_OUTBOUND equ 00000002h
    PIPE_ACCESS_DUPLEX equ 00000003h
    PIPE_CLIENT_END equ 00000000h
    PIPE_SERVER_END equ 00000001h
    PIPE_WAIT equ 00000000h
    PIPE_NOWAIT equ 00000001h
    PIPE_READMODE_BYTE equ 00000000h
    PIPE_READMODE_MESSAGE equ 00000002h
    PIPE_TYPE_BYTE equ 00000000h
    PIPE_TYPE_MESSAGE equ 00000004h
    PIPE_ACCEPT_REMOTE_CLIENTS equ 00000000h
    PIPE_REJECT_REMOTE_CLIENTS equ 00000008h
    PIPE_UNLIMITED_INSTANCES equ 255
    SECURITY_ANONYMOUS equ (SecurityAnonymous shl 16)
    SECURITY_IDENTIFICATION equ (SecurityIdentification shl 16)
    SECURITY_IMPERSONATION equ (SecurityImpersonation shl 16)
    SECURITY_DELEGATION equ (SecurityDelegation shl 16)
    SECURITY_CONTEXT_TRACKING equ 00040000h
    SECURITY_EFFECTIVE_ONLY equ 00080000h
    SECURITY_SQOS_PRESENT equ 00100000h
    SECURITY_VALID_SQOS_FLAGS equ 001F0000h
    if (_WIN32_WINNT ge 0400h)
      TYPE_PFIBER_START_ROUTINE typedef proto WIN_STD_CALL_CONV :LPVOID
      PFIBER_START_ROUTINE typedef ptr TYPE_PFIBER_START_ROUTINE

      LPFIBER_START_ROUTINE typedef PFIBER_START_ROUTINE
      TYPE_PFIBER_CALLOUT_ROUTINE typedef proto WIN_STD_CALL_CONV :LPVOID
      PFIBER_CALLOUT_ROUTINE typedef ptr TYPE_PFIBER_CALLOUT_ROUTINE

    endif
    FAIL_FAST_GENERATE_EXCEPTION_ADDRESS equ 1h
    FAIL_FAST_NO_HARD_ERROR_DLG equ 2h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if Defined(_X86_)
      LPLDT_ENTRY typedef PLDT_ENTRY
    else
      LPLDT_ENTRY typedef LPVOID
    endif
    SP_SERIALCOMM equ (00000001h)
    PST_UNSPECIFIED equ (00000000h)
    PST_RS232 equ (00000001h)
    PST_PARALLELPORT equ (00000002h)
    PST_RS422 equ (00000003h)
    PST_RS423 equ (00000004h)
    PST_RS449 equ (00000005h)
    PST_MODEM equ (00000006h)
    PST_FAX equ (00000021h)
    PST_SCANNER equ (00000022h)
    PST_NETWORK_BRIDGE equ (00000100h)
    PST_LAT equ (00000101h)
    PST_TCPIP_TELNET equ (00000102h)
    PST_X25 equ (00000103h)
    PCF_DTRDSR equ (0001h)
    PCF_RTSCTS equ (0002h)
    PCF_RLSD equ (0004h)
    PCF_PARITY_CHECK equ (0008h)
    PCF_XONXOFF equ (0010h)
    PCF_SETXCHAR equ (0020h)
    PCF_TOTALTIMEOUTS equ (0040h)
    PCF_INTTIMEOUTS equ (0080h)
    PCF_SPECIALCHARS equ (0100h)
    PCF_16BITMODE equ (0200h)
    SP_PARITY equ (0001h)
    SP_BAUD equ (0002h)
    SP_DATABITS equ (0004h)
    SP_STOPBITS equ (0008h)
    SP_HANDSHAKING equ (0010h)
    SP_PARITY_CHECK equ (0020h)
    SP_RLSD equ (0040h)
    BAUD_075 equ (00000001h)
    BAUD_110 equ (00000002h)
    BAUD_134_5 equ (00000004h)
    BAUD_150 equ (00000008h)
    BAUD_300 equ (00000010h)
    BAUD_600 equ (00000020h)
    BAUD_1200 equ (00000040h)
    BAUD_1800 equ (00000080h)
    BAUD_2400 equ (00000100h)
    BAUD_4800 equ (00000200h)
    BAUD_7200 equ (00000400h)
    BAUD_9600 equ (00000800h)
    BAUD_14400 equ (00001000h)
    BAUD_19200 equ (00002000h)
    BAUD_38400 equ (00004000h)
    BAUD_56K equ (00008000h)
    BAUD_128K equ (00010000h)
    BAUD_115200 equ (00020000h)
    BAUD_57600 equ (00040000h)
    BAUD_USER equ (10000000h)
    DATABITS_5 equ (0001h)
    DATABITS_6 equ (0002h)
    DATABITS_7 equ (0004h)
    DATABITS_8 equ (0008h)
    DATABITS_16 equ (0010h)
    DATABITS_16X equ (0020h)
    STOPBITS_10 equ (0001h)
    STOPBITS_15 equ (0002h)
    STOPBITS_20 equ (0004h)
    PARITY_NONE equ (0100h)
    PARITY_ODD equ (0200h)
    PARITY_EVEN equ (0400h)
    PARITY_MARK equ (0800h)
    PARITY_SPACE equ (1000h)
    COMMPROP struct
      wPacketLength WORD ?
      wPacketVersion WORD ?
      dwServiceMask DWORD ?
      dwReserved1 DWORD ?
      dwMaxTxQueue DWORD ?
      dwMaxRxQueue DWORD ?
      dwMaxBaud DWORD ?
      dwProvSubType DWORD ?
      dwProvCapabilities DWORD ?
      dwSettableParams DWORD ?
      dwSettableBaud DWORD ?
      wSettableData WORD ?
      wSettableStopParity WORD ?
      dwCurrentTxQueue DWORD ?
      dwCurrentRxQueue DWORD ?
      dwProvSpec1 DWORD ?
      dwProvSpec2 DWORD ?
      wcProvChar WCHAR 1 dup (?)
    COMMPROP ends
    _COMMPROP typedef COMMPROP
    LPCOMMPROP typedef ptr COMMPROP
    COMMPROP_INITIALIZED equ (0E73CF52Eh)
    COMSTAT struct
      COMSTAT_REC record COMSTAT_REC_fReserved:25, COMSTAT_REC_fTxim:1, COMSTAT_REC_fEof:1, COMSTAT_REC_fXoffSent:1, COMSTAT_REC_fXoffHold:1, COMSTAT_REC_fRlsdHold:1, COMSTAT_REC_fDsrHold:1, COMSTAT_REC_fCtsHold:1
      COMSTAT_BITS COMSTAT_REC <>
      cbInQue DWORD ?
      cbOutQue DWORD ?
    COMSTAT ends
    _COMSTAT typedef COMSTAT
    LPCOMSTAT typedef ptr COMSTAT
    DTR_CONTROL_DISABLE equ 00h
    DTR_CONTROL_ENABLE equ 01h
    DTR_CONTROL_HANDSHAKE equ 02h
    RTS_CONTROL_DISABLE equ 00h
    RTS_CONTROL_ENABLE equ 01h
    RTS_CONTROL_HANDSHAKE equ 02h
    RTS_CONTROL_TOGGLE equ 03h
    DCB struct
      DCBlength DWORD ?
      BaudRate DWORD ?
      DCB_REC record DCB_REC_fDummy2:17, DCB_REC_fAbortOnError:1, DCB_REC_fRtsControl:2, DCB_REC_fNull:1, DCB_REC_fErrorChar:1, DCB_REC_fInX:1, DCB_REC_fOutX:1, DCB_REC_fTXContinueOnXoff:1, DCB_REC_fDsrSensitivity:1, DCB_REC_fDtrControl:2, DCB_REC_fOutxDsrFlow:1, DCB_REC_fOutxCtsFlow:1, DCB_REC_fParity:1, DCB_REC_fBinary:1
      DCB_BITS DCB_REC <>
      wReserved WORD ?
      XonLim WORD ?
      XoffLim WORD ?
      ByteSize BYTE ?
      Parity BYTE ?
      StopBits BYTE ?
      XonChar SBYTE ?
      XoffChar SBYTE ?
      ErrorChar SBYTE ?
      EofChar SBYTE ?
      EvtChar SBYTE ?
      wReserved1 WORD ?
    DCB ends
    _DCB typedef DCB
    LPDCB typedef ptr DCB
    COMMTIMEOUTS struct
      ReadIntervalTimeout DWORD ?
      ReadTotalTimeoutMultiplier DWORD ?
      ReadTotalTimeoutConstant DWORD ?
      WriteTotalTimeoutMultiplier DWORD ?
      WriteTotalTimeoutConstant DWORD ?
    COMMTIMEOUTS ends
    _COMMTIMEOUTS typedef COMMTIMEOUTS
    LPCOMMTIMEOUTS typedef ptr COMMTIMEOUTS
    COMMCONFIG struct
      dwSize DWORD ?
      wVersion WORD ?
      wReserved WORD ?
      dcb DCB <>
      dwProviderSubType DWORD ?
      dwProviderOffset DWORD ?
      dwProviderSize DWORD ?
      wcProviderData WCHAR 1 dup (?)
    COMMCONFIG ends
    _COMMCONFIG typedef COMMCONFIG
    LPCOMMCONFIG typedef ptr COMMCONFIG
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    FreeModule macro hLibModule
      exitm <FreeLibrary ((hLibModule))>
    endm
    MakeProcInstance macro lpProc, hInstance
      exitm <(lpProc)>
    endm
    FreeProcInstance macro lpProc
      exitm <(lpProc)>
    endm
    GMEM_FIXED equ 0000h
    GMEM_MOVEABLE equ 0002h
    GMEM_NOCOMPACT equ 0010h
    GMEM_NODISCARD equ 0020h
    GMEM_ZEROINIT equ 0040h
    GMEM_MODIFY equ 0080h
    GMEM_DISCARDABLE equ 0100h
    GMEM_NOT_BANKED equ 1000h
    GMEM_SHARE equ 2000h
    GMEM_DDESHARE equ 2000h
    GMEM_NOTIFY equ 4000h
    GMEM_LOWER equ <GMEM_NOT_BANKED>
    GMEM_VALID_FLAGS equ 7F72h
    GMEM_INVALID_HANDLE equ 8000h
    GHND equ <(GMEM_MOVEABLE or GMEM_ZEROINIT)>
    GPTR equ <(GMEM_FIXED or GMEM_ZEROINIT)>
    GlobalLRUNewest macro h
      exitm <((h))>
    endm
    GlobalLRUOldest macro h
      exitm <((h))>
    endm
    GlobalDiscard macro h
      exitm <GlobalReAlloc ((h), 0, GMEM_MOVEABLE)>
    endm
    GMEM_DISCARDED equ 4000h
    GMEM_LOCKCOUNT equ 00FFh
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    MEMORYSTATUS struct
      dwLength DWORD ?
      dwMemoryLoad DWORD ?
      dwTotalPhys SIZE_T ?
      dwAvailPhys SIZE_T ?
      dwTotalPageFile SIZE_T ?
      dwAvailPageFile SIZE_T ?
      dwTotalVirtual SIZE_T ?
      dwAvailVirtual SIZE_T ?
    MEMORYSTATUS ends
    _MEMORYSTATUS typedef MEMORYSTATUS
    LPMEMORYSTATUS typedef ptr MEMORYSTATUS
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    DEBUG_PROCESS equ 00000001h
    DEBUG_ONLY_THIS_PROCESS equ 00000002h
    CREATE_SUSPENDED equ 00000004h
    DETACHED_PROCESS equ 00000008h
    CREATE_NEW_CONSOLE equ 00000010h
    NORMAL_PRIORITY_CLASS equ 00000020h
    IDLE_PRIORITY_CLASS equ 00000040h
    HIGH_PRIORITY_CLASS equ 00000080h
    REALTIME_PRIORITY_CLASS equ 00000100h
    CREATE_NEW_PROCESS_GROUP equ 00000200h
    CREATE_UNICODE_ENVIRONMENT equ 00000400h
    CREATE_SEPARATE_WOW_VDM equ 00000800h
    CREATE_SHARED_WOW_VDM equ 00001000h
    CREATE_FORCEDOS equ 00002000h
    BELOW_NORMAL_PRIORITY_CLASS equ 00004000h
    ABOVE_NORMAL_PRIORITY_CLASS equ 00008000h
    INHERIT_PARENT_AFFINITY equ 00010000h
    INHERIT_CALLER_PRIORITY equ 00020000h
    CREATE_PROTECTED_PROCESS equ 00040000h
    EXTENDED_STARTUPINFO_PRESENT equ 00080000h
    PROCESS_MODE_BACKGROUND_BEGIN equ 00100000h
    PROCESS_MODE_BACKGROUND_END equ 00200000h
    CREATE_SECURE_PROCESS equ 00400000h
    CREATE_BREAKAWAY_FROM_JOB equ 01000000h
    CREATE_PRESERVE_CODE_AUTHZ_LEVEL equ 02000000h
    CREATE_DEFAULT_ERROR_MODE equ 04000000h
    CREATE_NO_WINDOW equ 08000000h
    PROFILE_USER equ 10000000h
    PROFILE_KERNEL equ 20000000h
    PROFILE_SERVER equ 40000000h
    CREATE_IGNORE_SYSTEM_DEFAULT equ 80000000h
    STACK_SIZE_PARAM_IS_A_RESERVATION equ 00010000h
    THREAD_PRIORITY_LOWEST equ <THREAD_BASE_PRIORITY_MIN>
    THREAD_PRIORITY_BELOW_NORMAL equ (THREAD_PRIORITY_LOWEST + 1)
    THREAD_PRIORITY_NORMAL equ 0
    THREAD_PRIORITY_HIGHEST equ <THREAD_BASE_PRIORITY_MAX>
    THREAD_PRIORITY_ABOVE_NORMAL equ (THREAD_PRIORITY_HIGHEST - 1)
    THREAD_PRIORITY_ERROR_RETURN equ <(MAXLONG)>
    THREAD_PRIORITY_TIME_CRITICAL equ <THREAD_BASE_PRIORITY_LOWRT>
    THREAD_PRIORITY_IDLE equ <THREAD_BASE_PRIORITY_IDLE>
    THREAD_MODE_BACKGROUND_BEGIN equ 00010000h
    THREAD_MODE_BACKGROUND_END equ 00020000h
    VOLUME_NAME_DOS equ 0h
    VOLUME_NAME_GUID equ 1h
    VOLUME_NAME_NT equ 2h
    VOLUME_NAME_NONE equ 4h
    FILE_NAME_NORMALIZED equ 0h
    FILE_NAME_OPENED equ 8h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    JIT_DEBUG_INFO struct
      dwSize DWORD ?
      dwProcessorArchitecture DWORD ?
      dwThreadID DWORD ?
      dwReserved0 DWORD ?
      lpExceptionAddress ULONG64 ?
      lpExceptionRecord ULONG64 ?
      lpContextRecord ULONG64 ?
    JIT_DEBUG_INFO ends
    _JIT_DEBUG_INFO typedef JIT_DEBUG_INFO
    LPJIT_DEBUG_INFO typedef ptr JIT_DEBUG_INFO
    JIT_DEBUG_INFO32 typedef JIT_DEBUG_INFO
    LPJIT_DEBUG_INFO32 typedef ptr JIT_DEBUG_INFO
    JIT_DEBUG_INFO64 typedef JIT_DEBUG_INFO
    LPJIT_DEBUG_INFO64 typedef ptr JIT_DEBUG_INFO
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if  not Defined(MIDL_PASS)
      LPEXCEPTION_RECORD typedef PEXCEPTION_RECORD
      LPEXCEPTION_POINTERS typedef PEXCEPTION_POINTERS
    endif
    DRIVE_UNKNOWN equ 0
    DRIVE_NO_ROOT_DIR equ 1
    DRIVE_REMOVABLE equ 2
    DRIVE_FIXED equ 3
    DRIVE_REMOTE equ 4
    DRIVE_CDROM equ 5
    DRIVE_RAMDISK equ 6
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifndef _MAC
      GetFreeSpace macro w
        exitm <(100000h)>
      endm
    else
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    FILE_TYPE_UNKNOWN equ 0000h
    FILE_TYPE_DISK equ 0001h
    FILE_TYPE_CHAR equ 0002h
    FILE_TYPE_PIPE equ 0003h
    FILE_TYPE_REMOTE equ 8000h
    STD_INPUT_HANDLE equ (- 10)
    STD_OUTPUT_HANDLE equ (- 11)
    STD_ERROR_HANDLE equ (- 12)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    NOPARITY equ 0
    ODDPARITY equ 1
    EVENPARITY equ 2
    MARKPARITY equ 3
    SPACEPARITY equ 4
    ONESTOPBIT equ 0
    ONE5STOPBITS equ 1
    TWOSTOPBITS equ 2
    IGNORE equ 0
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    INFINITE equ 0FFFFFFFFh
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    CBR_110 equ 110
    CBR_300 equ 300
    CBR_600 equ 600
    CBR_1200 equ 1200
    CBR_2400 equ 2400
    CBR_4800 equ 4800
    CBR_9600 equ 9600
    CBR_14400 equ 14400
    CBR_19200 equ 19200
    CBR_38400 equ 38400
    CBR_56000 equ 56000
    CBR_57600 equ 57600
    CBR_115200 equ 115200
    CBR_128000 equ 128000
    CBR_256000 equ 256000
    CE_RXOVER equ 0001h
    CE_OVERRUN equ 0002h
    CE_RXPARITY equ 0004h
    CE_FRAME equ 0008h
    CE_BREAK equ 0010h
    CE_TXFULL equ 0100h
    CE_PTO equ 0200h
    CE_IOE equ 0400h
    CE_DNS equ 0800h
    CE_OOP equ 1000h
    CE_MODE equ 8000h
    IE_BADID equ (- 1)
    IE_OPEN equ (- 2)
    IE_NOPEN equ (- 3)
    IE_MEMORY equ (- 4)
    IE_DEFAULT equ (- 5)
    IE_HARDWARE equ (- 10)
    IE_BYTESIZE equ (- 11)
    IE_BAUDRATE equ (- 12)
    EV_RXCHAR equ 0001h
    EV_RXFLAG equ 0002h
    EV_TXEMPTY equ 0004h
    EV_CTS equ 0008h
    EV_DSR equ 0010h
    EV_RLSD equ 0020h
    EV_BREAK equ 0040h
    EV_ERR equ 0080h
    EV_RING equ 0100h
    EV_PERR equ 0200h
    EV_RX80FULL equ 0400h
    EV_EVENT1 equ 0800h
    EV_EVENT2 equ 1000h
    SETXOFF equ 1
    SETXON equ 2
    SETRTS equ 3
    CLRRTS equ 4
    SETDTR equ 5
    CLRDTR equ 6
    RESETDEV equ 7
    SETBREAK equ 8
    CLRBREAK equ 9
    PURGE_TXABORT equ 0001h
    PURGE_RXABORT equ 0002h
    PURGE_TXCLEAR equ 0004h
    PURGE_RXCLEAR equ 0008h
    LPTx equ 80h
    MS_CTS_ON equ (0010h)
    MS_DSR_ON equ (0020h)
    MS_RING_ON equ (0040h)
    MS_RLSD_ON equ (0080h)
    S_QUEUEEMPTY equ 0
    S_THRESHOLD equ 1
    S_ALLTHRESHOLD equ 2
    S_NORMAL equ 0
    S_LEGATO equ 1
    S_STACCATO equ 2
    S_PERIOD512 equ 0
    S_PERIOD1024 equ 1
    S_PERIOD2048 equ 2
    S_PERIODVOICE equ 3
    S_WHITE512 equ 4
    S_WHITE1024 equ 5
    S_WHITE2048 equ 6
    S_WHITEVOICE equ 7
    S_SERDVNA equ (- 1)
    S_SEROFM equ (- 2)
    S_SERMACT equ (- 3)
    S_SERQFUL equ (- 4)
    S_SERBDNT equ (- 5)
    S_SERDLN equ (- 6)
    S_SERDCC equ (- 7)
    S_SERDTP equ (- 8)
    S_SERDVL equ (- 9)
    S_SERDMD equ (- 10)
    S_SERDSH equ (- 11)
    S_SERDPT equ (- 12)
    S_SERDFQ equ (- 13)
    S_SERDDR equ (- 14)
    S_SERDSR equ (- 15)
    S_SERDST equ (- 16)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    NMPWAIT_WAIT_FOREVER equ 0ffffffffh
    NMPWAIT_NOWAIT equ 00000001h
    NMPWAIT_USE_DEFAULT_WAIT equ 00000000h
    FS_CASE_IS_PRESERVED equ <FILE_CASE_PRESERVED_NAMES>
    FS_CASE_SENSITIVE equ <FILE_CASE_SENSITIVE_SEARCH>
    FS_UNICODE_STORED_ON_DISK equ <FILE_UNICODE_ON_DISK>
    FS_PERSISTENT_ACLS equ <FILE_PERSISTENT_ACLS>
    FS_VOL_IS_COMPRESSED equ <FILE_VOLUME_IS_COMPRESSED>
    FS_FILE_COMPRESSION equ <FILE_FILE_COMPRESSION>
    FS_FILE_ENCRYPTION equ <FILE_SUPPORTS_ENCRYPTION>
    OF_READ equ 00000000h
    OF_WRITE equ 00000001h
    OF_READWRITE equ 00000002h
    OF_SHARE_COMPAT equ 00000000h
    OF_SHARE_EXCLUSIVE equ 00000010h
    OF_SHARE_DENY_WRITE equ 00000020h
    OF_SHARE_DENY_READ equ 00000030h
    OF_SHARE_DENY_NONE equ 00000040h
    OF_PARSE equ 00000100h
    OF_DELETE equ 00000200h
    OF_VERIFY equ 00000400h
    OF_CANCEL equ 00000800h
    OF_CREATE equ 00001000h
    OF_PROMPT equ 00002000h
    OF_EXIST equ 00004000h
    OF_REOPEN equ 00008000h
    OFS_MAXPATHNAME equ 128
    OFSTRUCT struct
      cBytes BYTE ?
      fFixedDisk BYTE ?
      nErrCode WORD ?
      Reserved1 WORD ?
      Reserved2 WORD ?
      szPathName CHAR OFS_MAXPATHNAME dup (?)
    OFSTRUCT ends
    _OFSTRUCT typedef OFSTRUCT
    LPOFSTRUCT typedef ptr OFSTRUCT
    POFSTRUCT typedef ptr OFSTRUCT
    UnlockResource macro hResData
      exitm <((hResData), 0)>
    endm
    MAXINTATOM equ 0C000h
    MAKEINTATOM macro i
      exitm <(LPTSTR) (((i)))>
    endm
    INVALID_ATOM equ (0)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if  not Defined(_MAC)
      if Defined(_M_CEE_PURE)
        ;[...]
      else
      endif
    else
      ;[...]
    endif
    WinMain proto WIN_STD_CALL_CONV :HINSTANCE, :HINSTANCE, :LPSTR, :SDWORD
    if Defined(_M_CEE_PURE)
      ;[...]
    else
    endif
    wWinMain proto WIN_STD_CALL_CONV :HINSTANCE, :HINSTANCE, :LPWSTR, :SDWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GlobalAlloc, WIN_STD_CALL_CONV,, <:UINT, :SIZE_T>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GlobalReAlloc, WIN_STD_CALL_CONV,, <:HGLOBAL, :SIZE_T, :UINT>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GlobalSize, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalUnlock, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalLock, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, GlobalFlags, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalHandle, WIN_STD_CALL_CONV,, <:LPCVOID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GlobalFree, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, GlobalCompact, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, GlobalFix, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalUnfix, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalWire, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalUnWire, WIN_STD_CALL_CONV,, <:HGLOBAL>, 4
    @DefProto DllImport, GlobalMemoryStatus, WIN_STD_CALL_CONV,, <:LPMEMORYSTATUS>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, LocalAlloc, WIN_STD_CALL_CONV,, <:UINT, :SIZE_T>, 8
    @DefProto DllImport, LocalReAlloc, WIN_STD_CALL_CONV,, <:HLOCAL, :SIZE_T, :UINT>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, LocalLock, WIN_STD_CALL_CONV,, <:HLOCAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, LocalHandle, WIN_STD_CALL_CONV,, <:LPCVOID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, LocalUnlock, WIN_STD_CALL_CONV,, <:HLOCAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, LocalSize, WIN_STD_CALL_CONV,, <:HLOCAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, LocalFlags, WIN_STD_CALL_CONV,, <:HLOCAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, LocalFree, WIN_STD_CALL_CONV,, <:HLOCAL>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, LocalShrink, WIN_STD_CALL_CONV,, <:HLOCAL, :UINT>, 8
    @DefProto DllImport, LocalCompact, WIN_STD_CALL_CONV,, <:UINT>, 4
    SCS_32BIT_BINARY equ 0
    SCS_DOS_BINARY equ 1
    SCS_WOW_BINARY equ 2
    SCS_PIF_BINARY equ 3
    SCS_POSIX_BINARY equ 4
    SCS_OS216_BINARY equ 5
    SCS_64BIT_BINARY equ 6
    if Defined(_WIN64)
      SCS_THIS_PLATFORM_BINARY equ <SCS_64BIT_BINARY>
    else
      SCS_THIS_PLATFORM_BINARY equ <SCS_32BIT_BINARY>
    endif
    @DefProto DllImport, GetBinaryTypeA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDWORD>, 8
    @DefProto DllImport, GetBinaryTypeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDWORD>, 8
    ifdef UNICODE
      GetBinaryType equ <GetBinaryTypeW>
    else
      GetBinaryType equ <GetBinaryTypeA>
    endif
    @DefProto DllImport, GetShortPathNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    ifndef UNICODE
      GetShortPathName equ <GetShortPathNameA>
    endif
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, GetLongPathNameTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD, :HANDLE>, 16
      @DefProto DllImport, GetLongPathNameTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD, :HANDLE>, 16
      ifdef UNICODE
        GetLongPathNameTransacted equ <GetLongPathNameTransactedW>
      else
        GetLongPathNameTransacted equ <GetLongPathNameTransactedA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetProcessAffinityMask, WIN_STD_CALL_CONV,, <:HANDLE, :PDWORD_PTR, :PDWORD_PTR>, 12
    @DefProto DllImport, SetProcessAffinityMask, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD_PTR>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, GetProcessIoCounters, WIN_STD_CALL_CONV,, <:HANDLE, :PIO_COUNTERS>, 8
    @DefProto DllImport, FatalExit, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, SetEnvironmentStringsA, WIN_STD_CALL_CONV,, <:LPCH>, 4
    ifndef UNICODE
      SetEnvironmentStrings equ <SetEnvironmentStringsA>
    endif
  endif
  if (_WIN32_WINNT ge 0400h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      FIBER_FLAG_FLOAT_SWITCH equ 1h
      @DefProto DllImport, SwitchToFiber, WIN_STD_CALL_CONV,, <:LPVOID>, 4
      @DefProto DllImport, DeleteFiber, WIN_STD_CALL_CONV,, <:LPVOID>, 4
      if (_WIN32_WINNT ge 0501h)
        @DefProto DllImport, ConvertFiberToThread, WIN_STD_CALL_CONV,, <>, 0
      endif
      @DefProto DllImport, CreateFiberEx, WIN_STD_CALL_CONV,, <:SIZE_T, :SIZE_T, :DWORD, :LPFIBER_START_ROUTINE, :LPVOID>, 20
      @DefProto DllImport, ConvertThreadToFiberEx, WIN_STD_CALL_CONV,, <:LPVOID, :DWORD>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CreateFiber, WIN_STD_CALL_CONV,, <:SIZE_T, :LPFIBER_START_ROUTINE, :LPVOID>, 12
      @DefProto DllImport, ConvertThreadToFiber, WIN_STD_CALL_CONV,, <:LPVOID>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (_WIN32_WINNT ge 0601h) and  not Defined(MIDL_PASS)
        UMS_VERSION equ <RTL_UMS_VERSION>
        PUMS_CONTEXT typedef ptr
        PUMS_COMPLETION_LIST typedef ptr
        UMS_THREAD_INFO_CLASS typedef SDWORD
        UMS_SCHEDULER_REASON typedef SDWORD
        PUMS_SCHEDULER_ENTRY_POINT typedef PRTL_UMS_SCHEDULER_ENTRY_POINT
        UMS_SCHEDULER_STARTUP_INFO struct
          UmsVersion ULONG ?
          CompletionList PUMS_COMPLETION_LIST ?
          SchedulerProc PUMS_SCHEDULER_ENTRY_POINT ?
          SchedulerParam PVOID ?
        UMS_SCHEDULER_STARTUP_INFO ends
        _UMS_SCHEDULER_STARTUP_INFO typedef UMS_SCHEDULER_STARTUP_INFO
        PUMS_SCHEDULER_STARTUP_INFO typedef ptr UMS_SCHEDULER_STARTUP_INFO
        UMS_SYSTEM_THREAD_INFORMATION struct
          UmsVersion ULONG ?
          union
            struct
              ANONYMOUS_REC35 record ANONYMOUS_REC35_Filler:30, ANONYMOUS_REC35_IsUmsWorkerThread:1, ANONYMOUS_REC35_IsUmsSchedulerThread:1
              ANONYMOUS_REC35 <>
            ends
            ThreadUmsFlags ULONG ?
          ends
        UMS_SYSTEM_THREAD_INFORMATION ends
        _UMS_SYSTEM_THREAD_INFORMATION typedef UMS_SYSTEM_THREAD_INFORMATION
        PUMS_SYSTEM_THREAD_INFORMATION typedef ptr UMS_SYSTEM_THREAD_INFORMATION
        @DefProto DllImport, CreateUmsCompletionList, WIN_STD_CALL_CONV,, <:ptr PUMS_COMPLETION_LIST>, 4
        @DefProto DllImport, DequeueUmsCompletionListItems, WIN_STD_CALL_CONV,, <:PUMS_COMPLETION_LIST, :DWORD, :ptr PUMS_CONTEXT>, 12
        @DefProto DllImport, GetUmsCompletionListEvent, WIN_STD_CALL_CONV,, <:PUMS_COMPLETION_LIST, :PHANDLE>, 8
        @DefProto DllImport, ExecuteUmsThread, WIN_STD_CALL_CONV,, <:PUMS_CONTEXT>, 4
        @DefProto DllImport, UmsThreadYield, WIN_STD_CALL_CONV,, <:PVOID>, 4
        @DefProto DllImport, DeleteUmsCompletionList, WIN_STD_CALL_CONV,, <:PUMS_COMPLETION_LIST>, 4
        @DefProto DllImport, GetCurrentUmsThread, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, GetNextUmsListItem, WIN_STD_CALL_CONV,, <:PUMS_CONTEXT>, 4
        @DefProto DllImport, QueryUmsThreadInformation, WIN_STD_CALL_CONV,, <:PUMS_CONTEXT, :UMS_THREAD_INFO_CLASS, :PVOID, :ULONG, :PULONG>, 20
        @DefProto DllImport, SetUmsThreadInformation, WIN_STD_CALL_CONV,, <:PUMS_CONTEXT, :UMS_THREAD_INFO_CLASS, :PVOID, :ULONG>, 16
        @DefProto DllImport, DeleteUmsThreadContext, WIN_STD_CALL_CONV,, <:PUMS_CONTEXT>, 4
        @DefProto DllImport, CreateUmsThreadContext, WIN_STD_CALL_CONV,, <:ptr PUMS_CONTEXT>, 4
        @DefProto DllImport, EnterUmsSchedulingMode, WIN_STD_CALL_CONV,, <:PUMS_SCHEDULER_STARTUP_INFO>, 4
        @DefProto DllImport, GetUmsSystemThreadInformation, WIN_STD_CALL_CONV,, <:HANDLE, :PUMS_SYSTEM_THREAD_INFORMATION>, 8
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, SetThreadAffinityMask, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD_PTR>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      PROCESS_DEP_ENABLE equ 00000001h
      PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION equ 00000002h
      @DefProto DllImport, SetProcessDEPPolicy, WIN_STD_CALL_CONV,, <:DWORD>, 4
      @DefProto DllImport, GetProcessDEPPolicy, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :PBOOL>, 12
    endif
    @DefProto DllImport, RequestWakeupLatency, WIN_STD_CALL_CONV,, <:LATENCY_TIME>, 4
    @DefProto DllImport, IsSystemResumeAutomatic, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetThreadSelectorEntry, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPLDT_ENTRY>, 12
    @DefProto DllImport, SetThreadExecutionState, WIN_STD_CALL_CONV,, <:EXECUTION_STATE>, 4
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      POWER_REQUEST_CONTEXT typedef REASON_CONTEXT
      PPOWER_REQUEST_CONTEXT typedef ptr REASON_CONTEXT
      LPPOWER_REQUEST_CONTEXT typedef ptr REASON_CONTEXT
      @DefProto DllImport, PowerCreateRequest, WIN_STD_CALL_CONV,, <:PREASON_CONTEXT>, 4
      @DefProto DllImport, PowerSetRequest, WIN_STD_CALL_CONV,, <:HANDLE, :POWER_REQUEST_TYPE>, 8
      @DefProto DllImport, PowerClearRequest, WIN_STD_CALL_CONV,, <:HANDLE, :POWER_REQUEST_TYPE>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    ifdef _M_CEE_PURE
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    if  not Defined(RC_INVOKED)
      if Defined(WINBASE_DECLARE_RESTORE_LAST_ERROR)
        @DefProto DllImport, RestoreLastError, WIN_STD_CALL_CONV,, <:DWORD>, 4
        TYPE_PRESTORE_LAST_ERROR typedef proto WIN_STD_CALL_CONV :DWORD
        PRESTORE_LAST_ERROR typedef ptr TYPE_PRESTORE_LAST_ERROR

        RESTORE_LAST_ERROR_NAME_A equ <"RestoreLastError">
        RESTORE_LAST_ERROR_NAME_W equ <L("RestoreLastError")>
        RESTORE_LAST_ERROR_NAME equ <TEXT("RestoreLastError")>
      endif
    endif
    HasOverlappedIoCompleted macro lpOverlapped
      exitm <(((lpOverlapped) - Internal) != STATUS_PENDING)>
    endm
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      FILE_SKIP_COMPLETION_PORT_ON_SUCCESS equ 1h
      FILE_SKIP_SET_EVENT_ON_HANDLE equ 2h
      @DefProto DllImport, SetFileCompletionNotificationModes, WIN_STD_CALL_CONV,, <:HANDLE, :UCHAR>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SEM_FAILCRITICALERRORS equ 0001h
    SEM_NOGPFAULTERRORBOX equ 0002h
    SEM_NOALIGNMENTFAULTEXCEPT equ 0004h
    SEM_NOOPENFILEERRORBOX equ 8000h
    if  not Defined(MIDL_PASS)
      if (_WIN32_WINNT ge 0601h)
        @DefProto DllImport, Wow64GetThreadSelectorEntry, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :PWOW64_LDT_ENTRY>, 12
      endif
    endif
    @DefProto DllImport, DebugSetProcessKillOnExit, WIN_STD_CALL_CONV,, <:BOOL>, 4
    @DefProto DllImport, DebugBreakProcess, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0403h)
      CRITICAL_SECTION_NO_DEBUG_INFO equ <RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, PulseEvent, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, GlobalDeleteAtom, WIN_STD_CALL_CONV,, <:ATOM>, 4
    @DefProto DllImport, InitAtomTable, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, DeleteAtom, WIN_STD_CALL_CONV,, <:ATOM>, 4
    @DefProto DllImport, SetHandleCount, WIN_STD_CALL_CONV,, <:UINT>, 4
    @DefProto DllImport, RequestDeviceWakeup, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, CancelDeviceWakeupRequest, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, GetDevicePowerState, WIN_STD_CALL_CONV,, <:HANDLE, :ptr BOOL>, 8
    @DefProto DllImport, SetMessageWaitingIndicator, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG>, 8
    @DefProto DllImport, SetFileShortNameA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR>, 8
    @DefProto DllImport, SetFileShortNameW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR>, 8
    ifdef UNICODE
      SetFileShortName equ <SetFileShortNameW>
    else
      SetFileShortName equ <SetFileShortNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    HANDLE_FLAG_INHERIT equ 00000001h
    HANDLE_FLAG_PROTECT_FROM_CLOSE equ 00000002h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    HINSTANCE_ERROR equ 32
    @DefProto DllImport, LoadModule, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID>, 8
    @DefProto DllImport, WinExec, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP)
    @DefProto DllImport, ClearCommBreak, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ClearCommError, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPCOMSTAT>, 12
    @DefProto DllImport, SetupComm, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD>, 12
    @DefProto DllImport, EscapeCommFunction, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, GetCommConfig, WIN_STD_CALL_CONV,, <:HANDLE, :LPCOMMCONFIG, :LPDWORD>, 12
    @DefProto DllImport, GetCommMask, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, GetCommProperties, WIN_STD_CALL_CONV,, <:HANDLE, :LPCOMMPROP>, 8
    @DefProto DllImport, GetCommModemStatus, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, GetCommState, WIN_STD_CALL_CONV,, <:HANDLE, :LPDCB>, 8
    @DefProto DllImport, GetCommTimeouts, WIN_STD_CALL_CONV,, <:HANDLE, :LPCOMMTIMEOUTS>, 8
    @DefProto DllImport, PurgeComm, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, SetCommBreak, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetCommConfig, WIN_STD_CALL_CONV,, <:HANDLE, :LPCOMMCONFIG, :DWORD>, 12
    @DefProto DllImport, SetCommMask, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, SetCommState, WIN_STD_CALL_CONV,, <:HANDLE, :LPDCB>, 8
    @DefProto DllImport, SetCommTimeouts, WIN_STD_CALL_CONV,, <:HANDLE, :LPCOMMTIMEOUTS>, 8
    @DefProto DllImport, TransmitCommChar, WIN_STD_CALL_CONV,, <:HANDLE, :SBYTE>, 8
    @DefProto DllImport, WaitCommEvent, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPOVERLAPPED>, 12
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      @DefProto DllImport, OpenCommPort, WIN_STD_CALL_CONV,, <:ULONG, :DWORD, :DWORD>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      @DefProto DllImport, GetCommPorts, WIN_STD_CALL_CONV,, <:PULONG, :ULONG, :PULONG>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, SetTapePosition, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :DWORD, :BOOL>, 24
    @DefProto DllImport, GetTapePosition, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
    @DefProto DllImport, PrepareTape, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :BOOL>, 12
    @DefProto DllImport, EraseTape, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :BOOL>, 12
    @DefProto DllImport, CreateTapePartition, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD>, 16
    @DefProto DllImport, WriteTapemark, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :BOOL>, 16
    @DefProto DllImport, GetTapeStatus, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, GetTapeParameters, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPDWORD, :LPVOID>, 16
    GET_TAPE_MEDIA_INFORMATION equ 0
    GET_TAPE_DRIVE_INFORMATION equ 1
    @DefProto DllImport, SetTapeParameters, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPVOID>, 12
    SET_TAPE_MEDIA_INFORMATION equ 0
    SET_TAPE_DRIVE_INFORMATION equ 1
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, MulDiv, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    DEP_SYSTEM_POLICY_TYPE typedef SDWORD
    DEPPolicyAlwaysOff equ 0
    DEPPolicyAlwaysOn equ 1
    DEPPolicyOptIn equ 2
    DEPPolicyOptOut equ 3
    DEPTotalPolicyCount equ 4
    _DEP_SYSTEM_POLICY_TYPE typedef DEP_SYSTEM_POLICY_TYPE

    if (NTDDI_VERSION ge NTDDI_WINXPSP3)
      @DefProto DllImport, GetSystemDEPPolicy, WIN_STD_CALL_CONV,, <>, 0
    endif
    if _WIN32_WINNT ge 0501h
      @DefProto DllImport, GetSystemRegistryQuota, WIN_STD_CALL_CONV,, <:PDWORD, :PDWORD>, 8
    endif
    @DefProto DllImport, FileTimeToDosDateTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :LPWORD, :LPWORD>, 12
    @DefProto DllImport, DosDateTimeToFileTime, WIN_STD_CALL_CONV,, <:WORD, :WORD, :LPFILETIME>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    FORMAT_MESSAGE_ALLOCATE_BUFFER equ 00000100h
    if  not Defined(MIDL_PASS)
      @DefProto DllImport, FormatMessageA, WIN_STD_CALL_CONV,, <:DWORD, :LPCVOID, :DWORD, :DWORD, :LPSTR, :DWORD, :ptr va_list>, 28
      @DefProto DllImport, FormatMessageW, WIN_STD_CALL_CONV,, <:DWORD, :LPCVOID, :DWORD, :DWORD, :LPWSTR, :DWORD, :ptr va_list>, 28
      ifdef UNICODE
        FormatMessage equ <FormatMessageW>
      else
        FormatMessage equ <FormatMessageA>
      endif
      if Defined(_M_CEE)
        ;[...]
      endif
    endif
    FORMAT_MESSAGE_IGNORE_INSERTS equ 00000200h
    FORMAT_MESSAGE_FROM_STRING equ 00000400h
    FORMAT_MESSAGE_FROM_HMODULE equ 00000800h
    FORMAT_MESSAGE_FROM_SYSTEM equ 00001000h
    FORMAT_MESSAGE_ARGUMENT_ARRAY equ 00002000h
    FORMAT_MESSAGE_MAX_WIDTH_MASK equ 000000FFh
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, CreateMailslotA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES>, 16
    @DefProto DllImport, CreateMailslotW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES>, 16
    ifdef UNICODE
      CreateMailslot equ <CreateMailslotW>
    else
      CreateMailslot equ <CreateMailslotA>
    endif
    @DefProto DllImport, GetMailslotInfo, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
    @DefProto DllImport, SetMailslotInfo, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, EncryptFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, EncryptFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      EncryptFile equ <EncryptFileW>
    else
      EncryptFile equ <EncryptFileA>
    endif
    @DefProto DllImport, DecryptFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    @DefProto DllImport, DecryptFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      DecryptFile equ <DecryptFileW>
    else
      DecryptFile equ <DecryptFileA>
    endif
    FILE_ENCRYPTABLE equ 0
    FILE_IS_ENCRYPTED equ 1
    FILE_SYSTEM_ATTR equ 2
    FILE_ROOT_DIR equ 3
    FILE_SYSTEM_DIR equ 4
    FILE_UNKNOWN equ 5
    FILE_SYSTEM_NOT_SUPPORT equ 6
    FILE_USER_DISALLOWED equ 7
    FILE_READ_ONLY equ 8
    FILE_DIR_DISALLOWED equ 9
    @DefProto DllImport, FileEncryptionStatusA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDWORD>, 8
    @DefProto DllImport, FileEncryptionStatusW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDWORD>, 8
    ifdef UNICODE
      FileEncryptionStatus equ <FileEncryptionStatusW>
    else
      FileEncryptionStatus equ <FileEncryptionStatusA>
    endif
    EFS_USE_RECOVERY_KEYS equ (1h)
    TYPE_PFE_EXPORT_FUNC typedef proto WIN_STD_CALL_CONV :PBYTE, :PVOID, :ULONG
    PFE_EXPORT_FUNC typedef ptr TYPE_PFE_EXPORT_FUNC

    TYPE_PFE_IMPORT_FUNC typedef proto WIN_STD_CALL_CONV :PBYTE, :PVOID, :PULONG
    PFE_IMPORT_FUNC typedef ptr TYPE_PFE_IMPORT_FUNC

    CREATE_FOR_IMPORT equ (1)
    CREATE_FOR_DIR equ (2)
    OVERWRITE_HIDDEN equ (4)
    EFSRPC_SECURE_ONLY equ (8)
    EFS_DROP_ALTERNATE_STREAMS equ (10h)
    @DefProto DllImport, OpenEncryptedFileRawA, WIN_STD_CALL_CONV,, <:LPCSTR, :ULONG, :ptr PVOID>, 12
    @DefProto DllImport, OpenEncryptedFileRawW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ULONG, :ptr PVOID>, 12
    ifdef UNICODE
      OpenEncryptedFileRaw equ <OpenEncryptedFileRawW>
    else
      OpenEncryptedFileRaw equ <OpenEncryptedFileRawA>
    endif
    @DefProto DllImport, ReadEncryptedFileRaw, WIN_STD_CALL_CONV,, <:PFE_EXPORT_FUNC, :PVOID, :PVOID>, 12
    @DefProto DllImport, WriteEncryptedFileRaw, WIN_STD_CALL_CONV,, <:PFE_IMPORT_FUNC, :PVOID, :PVOID>, 12
    @DefProto DllImport, CloseEncryptedFileRaw, WIN_STD_CALL_CONV,, <:PVOID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, lstrcmpA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, lstrcmpW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      lstrcmp equ <lstrcmpW>
    else
      lstrcmp equ <lstrcmpA>
    endif
    @DefProto DllImport, lstrcmpiA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, lstrcmpiW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      lstrcmpi equ <lstrcmpiW>
    else
      lstrcmpi equ <lstrcmpiA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if Defined(DEPRECATE_SUPPORTED)
    endif
    @DefProto DllImport, lstrcpynA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR, :SDWORD>, 12
    @DefProto DllImport, lstrcpynW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR, :SDWORD>, 12
    ifdef UNICODE
      lstrcpyn equ <lstrcpynW>
    else
      lstrcpyn equ <lstrcpynA>
    endif
    @DefProto DllImport, lstrcpyA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
    @DefProto DllImport, lstrcpyW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      lstrcpy equ <lstrcpyW>
    else
      lstrcpy equ <lstrcpyA>
    endif
    @DefProto DllImport, lstrcatA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
    @DefProto DllImport, lstrcatW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      lstrcat equ <lstrcatW>
    else
      lstrcat equ <lstrcatA>
    endif
    if Defined(DEPRECATE_SUPPORTED)
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, lstrlenA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, lstrlenW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      lstrlen equ <lstrlenW>
    else
      lstrlen equ <lstrlenA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, OpenFile, WIN_STD_CALL_CONV,, <:LPCSTR, :LPOFSTRUCT, :UINT>, 12
    @DefProto DllImport, _lopen, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD>, 8
    @DefProto DllImport, _lcreat, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD>, 8
    @DefProto DllImport, _lread, WIN_STD_CALL_CONV,, <:HFILE, :LPVOID, :UINT>, 12
    @DefProto DllImport, _lwrite, WIN_STD_CALL_CONV,, <:HFILE, :LPCCH, :UINT>, 12
    @DefProto DllImport, _hread, WIN_STD_CALL_CONV,, <:HFILE, :LPVOID, :SDWORD>, 12
    @DefProto DllImport, _hwrite, WIN_STD_CALL_CONV,, <:HFILE, :LPCCH, :SDWORD>, 12
    @DefProto DllImport, _lclose, WIN_STD_CALL_CONV,, <:HFILE>, 4
    @DefProto DllImport, _llseek, WIN_STD_CALL_CONV,, <:HFILE, :LONG, :SDWORD>, 12
    @DefProto DllImport, IsTextUnicode, WIN_STD_CALL_CONV,, <:ptr VOID, :SDWORD, :LPINT>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0400h)
      @DefProto DllImport, SignalObjectAndWait, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :DWORD, :BOOL>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, BackupRead, WIN_STD_CALL_CONV,, <:HANDLE, :LPBYTE, :DWORD, :LPDWORD, :BOOL, :BOOL, :ptr LPVOID>, 28
    @DefProto DllImport, BackupSeek, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :LPDWORD, :LPDWORD, :ptr LPVOID>, 24
    @DefProto DllImport, BackupWrite, WIN_STD_CALL_CONV,, <:HANDLE, :LPBYTE, :DWORD, :LPDWORD, :BOOL, :BOOL, :ptr LPVOID>, 28
    WIN32_STREAM_ID struct
      dwStreamId DWORD ?
      dwStreamAttributes DWORD ?
      Size_ LARGE_INTEGER <>
      dwStreamNameSize DWORD ?
      cStreamName WCHAR ANYSIZE_ARRAY dup (?)
    WIN32_STREAM_ID ends
    _WIN32_STREAM_ID typedef WIN32_STREAM_ID
    LPWIN32_STREAM_ID typedef ptr WIN32_STREAM_ID
    BACKUP_INVALID equ 00000000h
    BACKUP_DATA equ 00000001h
    BACKUP_EA_DATA equ 00000002h
    BACKUP_SECURITY_DATA equ 00000003h
    BACKUP_ALTERNATE_DATA equ 00000004h
    BACKUP_LINK equ 00000005h
    BACKUP_PROPERTY_DATA equ 00000006h
    BACKUP_OBJECT_ID equ 00000007h
    BACKUP_REPARSE_DATA equ 00000008h
    BACKUP_SPARSE_BLOCK equ 00000009h
    BACKUP_TXFS_DATA equ 0000000ah
    BACKUP_GHOSTED_FILE_EXTENTS equ 0000000bh
    STREAM_NORMAL_ATTRIBUTE equ 00000000h
    STREAM_MODIFIED_WHEN_READ equ 00000001h
    STREAM_CONTAINS_SECURITY equ 00000002h
    STREAM_CONTAINS_PROPERTIES equ 00000004h
    STREAM_SPARSE_ATTRIBUTE equ 00000008h
    STREAM_CONTAINS_GHOSTED_FILE_EXTENTS equ 00000010h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    STARTF_USESHOWWINDOW equ 00000001h
    STARTF_USESIZE equ 00000002h
    STARTF_USEPOSITION equ 00000004h
    STARTF_USECOUNTCHARS equ 00000008h
    STARTF_USEFILLATTRIBUTE equ 00000010h
    STARTF_RUNFULLSCREEN equ 00000020h
    STARTF_FORCEONFEEDBACK equ 00000040h
    STARTF_FORCEOFFFEEDBACK equ 00000080h
    STARTF_USESTDHANDLES equ 00000100h
    if (WINVER ge 0400h)
      STARTF_USEHOTKEY equ 00000200h
      STARTF_TITLEISLINKNAME equ 00000800h
      STARTF_TITLEISAPPID equ 00001000h
      STARTF_PREVENTPINNING equ 00002000h
    endif
    if (WINVER ge 0600h)
      STARTF_UNTRUSTEDSOURCE equ 00008000h
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      STARTF_HOLOGRAPHIC equ 00040000h
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      STARTUPINFOEXA struct
        StartupInfo STARTUPINFOA <>
        lpAttributeList LPPROC_THREAD_ATTRIBUTE_LIST ?
      STARTUPINFOEXA ends
      _STARTUPINFOEXA typedef STARTUPINFOEXA
      LPSTARTUPINFOEXA typedef ptr STARTUPINFOEXA
      STARTUPINFOEXW struct
        StartupInfo STARTUPINFOW <>
        lpAttributeList LPPROC_THREAD_ATTRIBUTE_LIST ?
      STARTUPINFOEXW ends
      _STARTUPINFOEXW typedef STARTUPINFOEXW
      LPSTARTUPINFOEXW typedef ptr STARTUPINFOEXW
      ifdef UNICODE
        STARTUPINFOEX typedef STARTUPINFOEXW
        LPSTARTUPINFOEX typedef LPSTARTUPINFOEXW
      else
        STARTUPINFOEX typedef STARTUPINFOEXA
        LPSTARTUPINFOEX typedef LPSTARTUPINFOEXA
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SHUTDOWN_NORETRY equ 00000001h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, OpenMutexA, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCSTR>, 12
    ifndef UNICODE
      OpenMutex equ <OpenMutexA>
    endif
    @DefProto DllImport, CreateSemaphoreA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LONG, :LONG, :LPCSTR>, 16
    ifndef UNICODE
      CreateSemaphore equ <CreateSemaphoreA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, OpenSemaphoreA, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCSTR>, 12
    ifndef UNICODE
      OpenSemaphore equ <OpenSemaphoreA>
    endif
  endif
  if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CreateWaitableTimerA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :BOOL, :LPCSTR>, 12
      ifndef UNICODE
        CreateWaitableTimer equ <CreateWaitableTimerA>
      endif
      @DefProto DllImport, OpenWaitableTimerA, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCSTR>, 12
      ifndef UNICODE
        OpenWaitableTimer equ <OpenWaitableTimerA>
      endif
      if (_WIN32_WINNT ge 0600h)
        @DefProto DllImport, CreateSemaphoreExA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LONG, :LONG, :LPCSTR, :DWORD, :DWORD>, 24
        ifndef UNICODE
          CreateSemaphoreEx equ <CreateSemaphoreExA>
        endif
        @DefProto DllImport, CreateWaitableTimerExA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCSTR, :DWORD, :DWORD>, 16
        ifndef UNICODE
          CreateWaitableTimerEx equ <CreateWaitableTimerExA>
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateFileMappingA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :DWORD, :LPCSTR>, 24
    ifndef UNICODE
      CreateFileMapping equ <CreateFileMappingA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, CreateFileMappingNumaA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :DWORD, :LPCSTR, :DWORD>, 28
      ifndef UNICODE
        CreateFileMappingNuma equ <CreateFileMappingNumaA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, OpenFileMappingA, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCSTR>, 12
    ifndef UNICODE
      OpenFileMapping equ <OpenFileMappingA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetLogicalDriveStringsA, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR>, 8
    ifndef UNICODE
      GetLogicalDriveStrings equ <GetLogicalDriveStringsA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0602h)
      @DefProto DllImport, LoadPackagedLibrary, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    PROTECTION_LEVEL_WINTCB_LIGHT equ 00000000h
    PROTECTION_LEVEL_WINDOWS equ 00000001h
    PROTECTION_LEVEL_WINDOWS_LIGHT equ 00000002h
    PROTECTION_LEVEL_ANTIMALWARE_LIGHT equ 00000003h
    PROTECTION_LEVEL_LSA_LIGHT equ 00000004h
    PROTECTION_LEVEL_WINTCB equ 00000005h
    PROTECTION_LEVEL_CODEGEN_LIGHT equ 00000006h
    PROTECTION_LEVEL_AUTHENTICODE equ 00000007h
    PROTECTION_LEVEL_PPL_APP equ 00000008h
    PROTECTION_LEVEL_SAME equ 0FFFFFFFFh
    PROTECTION_LEVEL_NONE equ 0FFFFFFFEh
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      PROCESS_NAME_NATIVE equ 00000001h
      @DefProto DllImport, QueryFullProcessImageNameA, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPSTR, :PDWORD>, 16
      @DefProto DllImport, QueryFullProcessImageNameW, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPWSTR, :PDWORD>, 16
      ifdef UNICODE
        QueryFullProcessImageName equ <QueryFullProcessImageNameW>
      else
        QueryFullProcessImageName equ <QueryFullProcessImageNameA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      PROC_THREAD_ATTRIBUTE_NUMBER equ 0000FFFFh
      PROC_THREAD_ATTRIBUTE_THREAD equ 00010000h
      PROC_THREAD_ATTRIBUTE_INPUT equ 00020000h
      PROC_THREAD_ATTRIBUTE_ADDITIVE equ 00040000h
      ifndef _USE_FULL_PROC_THREAD_ATTRIBUTE
        PROC_THREAD_ATTRIBUTE_NUM typedef SDWORD
        ProcThreadAttributeParentProcess equ 0
        ProcThreadAttributeHandleList equ 2
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
          ProcThreadAttributeGroupAffinity equ 3
          ProcThreadAttributePreferredNode equ 4
          ProcThreadAttributeIdealProcessor equ 5
          ProcThreadAttributeUmsThread equ 6
          ProcThreadAttributeMitigationPolicy equ 7
        endif
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
          ProcThreadAttributeSecurityCapabilities equ 9
        endif
        ProcThreadAttributeProtectionLevel equ 11
        if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
        endif
        if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
          ProcThreadAttributeJobList equ 13
          ProcThreadAttributeChildProcessPolicy equ 14
          ProcThreadAttributeAllApplicationPackagesPolicy equ 15
          ProcThreadAttributeWin32kFilter equ 16
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
          ProcThreadAttributeSafeOpenPromptOriginClaim equ 17
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
          ProcThreadAttributeDesktopAppPolicy equ 18
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
          ProcThreadAttributePseudoConsole equ 22
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_MN)
          ProcThreadAttributeMitigationAuditPolicy equ 24
          ProcThreadAttributeMachineType equ 25
          ProcThreadAttributeComponentFilter equ 26
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_FE)
          ProcThreadAttributeEnableOptionalXStateFeatures equ 27
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_NI)
          ProcThreadAttributeTrustedApp equ 29
        endif
        _PROC_THREAD_ATTRIBUTE_NUM typedef PROC_THREAD_ATTRIBUTE_NUM

      endif
      ProcThreadAttributeValue macro Number, Thread, Input, Additive
        exitm <(((Number) and PROC_THREAD_ATTRIBUTE_NUMBER) or ((Thread != FALSE) ? PROC_THREAD_ATTRIBUTE_THREAD : 0) or ((Input != FALSE) ? PROC_THREAD_ATTRIBUTE_INPUT : 0) or ((Additive != FALSE) ? PROC_THREAD_ATTRIBUTE_ADDITIVE : 0))>
      endm
      PROC_THREAD_ATTRIBUTE_PARENT_PROCESS equ <ProcThreadAttributeValue(ProcThreadAttributeParentProcess, FALSE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_HANDLE_LIST equ <ProcThreadAttributeValue(ProcThreadAttributeHandleList, FALSE, TRUE, FALSE)>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY equ <ProcThreadAttributeValue(ProcThreadAttributeGroupAffinity, TRUE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_PREFERRED_NODE equ <ProcThreadAttributeValue(ProcThreadAttributePreferredNode, FALSE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR equ <ProcThreadAttributeValue(ProcThreadAttributeIdealProcessor, TRUE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_UMS_THREAD equ <ProcThreadAttributeValue(ProcThreadAttributeUmsThread, TRUE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY equ <ProcThreadAttributeValue(ProcThreadAttributeMitigationPolicy, FALSE, TRUE, FALSE)>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES equ <ProcThreadAttributeValue(ProcThreadAttributeSecurityCapabilities, FALSE, TRUE, FALSE)>
    endif
    PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL equ <ProcThreadAttributeValue(ProcThreadAttributeProtectionLevel, FALSE, TRUE, FALSE)>
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      PROC_THREAD_ATTRIBUTE_PSEUDOCONSOLE equ <ProcThreadAttributeValue(ProcThreadAttributePseudoConsole, FALSE, TRUE, FALSE)>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_MN)
      PROC_THREAD_ATTRIBUTE_MACHINE_TYPE equ <ProcThreadAttributeValue(ProcThreadAttributeMachineType, FALSE, TRUE, FALSE)>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      PROC_THREAD_ATTRIBUTE_ENABLE_OPTIONAL_XSTATE_FEATURES equ <ProcThreadAttributeValue(ProcThreadAttributeEnableOptionalXStateFeatures, TRUE, TRUE, FALSE)>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE equ 01h
      PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE equ 02h
      PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE equ 04h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK equ (00000003h shl 8)
      PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_DEFER equ (00000000h shl 8)
      PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON equ (00000001h shl 8)
      PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF equ (00000002h shl 8)
      PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS equ (00000003h shl 8)
      PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK equ (00000003h shl 12)
      PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_DEFER equ (00000000h shl 12)
      PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON equ (00000001h shl 12)
      PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF equ (00000002h shl 12)
      PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_RESERVED equ (00000003h shl 12)
      PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK equ (00000003h shl 16)
      PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_DEFER equ (00000000h shl 16)
      PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON equ (00000001h shl 16)
      PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF equ (00000002h shl 16)
      PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_RESERVED equ (00000003h shl 16)
      PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK equ (00000003h shl 20)
      PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_DEFER equ (00000000h shl 20)
      PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON equ (00000001h shl 20)
      PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF equ (00000002h shl 20)
      PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_RESERVED equ (00000003h shl 20)
      PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK equ (00000003h shl 24)
      PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_DEFER equ (00000000h shl 24)
      PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON equ (00000001h shl 24)
      PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF equ (00000002h shl 24)
      PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_RESERVED equ (00000003h shl 24)
      PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK equ (00000003h shl 28)
      PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_DEFER equ (00000000h shl 28)
      PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON equ (00000001h shl 28)
      PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF equ (00000002h shl 28)
      PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_RESERVED equ (00000003h shl 28)
      PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK equ (00000003h shl 32)
      PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_DEFER equ (00000000h shl 32)
      PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON equ (00000001h shl 32)
      PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF equ (00000002h shl 32)
      PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_RESERVED equ (00000003h shl 32)
      if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
        PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK equ (00000003h shl 36)
        PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER equ (00000000h shl 36)
        PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON equ (00000001h shl 36)
        PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF equ (00000002h shl 36)
        PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON_ALLOW_OPT_OUT equ (00000003h shl 36)
        PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_MASK equ (00000003h shl 40)
        PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_DEFER equ (00000000h shl 40)
        PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_ON equ (00000001h shl 40)
        PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_OFF equ (00000002h shl 40)
        PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_EXPORT_SUPPRESSION equ (00000003h shl 40)
        PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK equ (00000003h shl 44)
        PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER equ (00000000h shl 44)
        PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON equ (00000001h shl 44)
        PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF equ (00000002h shl 44)
        PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALLOW_STORE equ (00000003h shl 44)
        if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
          PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_MASK equ (00000003h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_DEFER equ (00000000h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_ALWAYS_ON equ (00000001h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_ALWAYS_OFF equ (00000002h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY_AUDIT_NONSYSTEM_FONTS equ (00000003h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_MASK equ (00000003h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_DEFER equ (00000000h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_ALWAYS_ON equ (00000001h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_ALWAYS_OFF equ (00000002h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_RESERVED equ (00000003h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_MASK equ (00000003h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_DEFER equ (00000000h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_ALWAYS_ON equ (00000001h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_ALWAYS_OFF equ (00000002h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_RESERVED equ (00000003h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_MASK equ (00000003h shl 60)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_DEFER equ (00000000h shl 60)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_ALWAYS_ON equ (00000001h shl 60)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_ALWAYS_OFF equ (00000002h shl 60)
          PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_RESERVED equ (00000003h shl 60)
          PROCESS_CREATION_MITIGATION_POLICY2_LOADER_INTEGRITY_CONTINUITY_MASK equ (00000003h shl 4)
          PROCESS_CREATION_MITIGATION_POLICY2_LOADER_INTEGRITY_CONTINUITY_DEFER equ (00000000h shl 4)
          PROCESS_CREATION_MITIGATION_POLICY2_LOADER_INTEGRITY_CONTINUITY_ALWAYS_ON equ (00000001h shl 4)
          PROCESS_CREATION_MITIGATION_POLICY2_LOADER_INTEGRITY_CONTINUITY_ALWAYS_OFF equ (00000002h shl 4)
          PROCESS_CREATION_MITIGATION_POLICY2_LOADER_INTEGRITY_CONTINUITY_AUDIT equ (00000003h shl 4)
          PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_MASK equ (00000003h shl 8)
          PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_DEFER equ (00000000h shl 8)
          PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_ALWAYS_ON equ (00000001h shl 8)
          PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_ALWAYS_OFF equ (00000002h shl 8)
          PROCESS_CREATION_MITIGATION_POLICY2_STRICT_CONTROL_FLOW_GUARD_RESERVED equ (00000003h shl 8)
          PROCESS_CREATION_MITIGATION_POLICY2_MODULE_TAMPERING_PROTECTION_MASK equ (00000003h shl 12)
          PROCESS_CREATION_MITIGATION_POLICY2_MODULE_TAMPERING_PROTECTION_DEFER equ (00000000h shl 12)
          PROCESS_CREATION_MITIGATION_POLICY2_MODULE_TAMPERING_PROTECTION_ALWAYS_ON equ (00000001h shl 12)
          PROCESS_CREATION_MITIGATION_POLICY2_MODULE_TAMPERING_PROTECTION_ALWAYS_OFF equ (00000002h shl 12)
          PROCESS_CREATION_MITIGATION_POLICY2_MODULE_TAMPERING_PROTECTION_NOINHERIT equ (00000003h shl 12)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_INDIRECT_BRANCH_PREDICTION_MASK equ (00000003h shl 16)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_INDIRECT_BRANCH_PREDICTION_DEFER equ (00000000h shl 16)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_INDIRECT_BRANCH_PREDICTION_ALWAYS_ON equ (00000001h shl 16)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_INDIRECT_BRANCH_PREDICTION_ALWAYS_OFF equ (00000002h shl 16)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_INDIRECT_BRANCH_PREDICTION_RESERVED equ (00000003h shl 16)
          PROCESS_CREATION_MITIGATION_POLICY2_ALLOW_DOWNGRADE_DYNAMIC_CODE_POLICY_MASK equ (00000003h shl 20)
          PROCESS_CREATION_MITIGATION_POLICY2_ALLOW_DOWNGRADE_DYNAMIC_CODE_POLICY_DEFER equ (00000000h shl 20)
          PROCESS_CREATION_MITIGATION_POLICY2_ALLOW_DOWNGRADE_DYNAMIC_CODE_POLICY_ALWAYS_ON equ (00000001h shl 20)
          PROCESS_CREATION_MITIGATION_POLICY2_ALLOW_DOWNGRADE_DYNAMIC_CODE_POLICY_ALWAYS_OFF equ (00000002h shl 20)
          PROCESS_CREATION_MITIGATION_POLICY2_ALLOW_DOWNGRADE_DYNAMIC_CODE_POLICY_RESERVED equ (00000003h shl 20)
          PROCESS_CREATION_MITIGATION_POLICY2_SPECULATIVE_STORE_BYPASS_DISABLE_MASK equ (00000003h shl 24)
          PROCESS_CREATION_MITIGATION_POLICY2_SPECULATIVE_STORE_BYPASS_DISABLE_DEFER equ (00000000h shl 24)
          PROCESS_CREATION_MITIGATION_POLICY2_SPECULATIVE_STORE_BYPASS_DISABLE_ALWAYS_ON equ (00000001h shl 24)
          PROCESS_CREATION_MITIGATION_POLICY2_SPECULATIVE_STORE_BYPASS_DISABLE_ALWAYS_OFF equ (00000002h shl 24)
          PROCESS_CREATION_MITIGATION_POLICY2_SPECULATIVE_STORE_BYPASS_DISABLE_RESERVED equ (00000003h shl 24)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_MASK equ (00000003h shl 28)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_DEFER equ (00000000h shl 28)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_ALWAYS_ON equ (00000001h shl 28)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_ALWAYS_OFF equ (00000002h shl 28)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_USER_SHADOW_STACKS_STRICT_MODE equ (00000003h shl 28)
          PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_MASK equ (00000003h shl 32)
          PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_DEFER equ (00000000h shl 32)
          PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_ALWAYS_ON equ (00000001h shl 32)
          PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_ALWAYS_OFF equ (00000002h shl 32)
          PROCESS_CREATION_MITIGATION_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_RELAXED_MODE equ (00000003h shl 32)
          PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_MASK equ (00000003h shl 36)
          PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_DEFER equ (00000000h shl 36)
          PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_ALWAYS_ON equ (00000001h shl 36)
          PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_ALWAYS_OFF equ (00000002h shl 36)
          PROCESS_CREATION_MITIGATION_POLICY2_BLOCK_NON_CET_BINARIES_NON_EHCONT equ (00000003h shl 36)
          PROCESS_CREATION_MITIGATION_POLICY2_XTENDED_CONTROL_FLOW_GUARD_MASK equ (00000003h shl 40)
          PROCESS_CREATION_MITIGATION_POLICY2_XTENDED_CONTROL_FLOW_GUARD_DEFER equ (00000000h shl 40)
          PROCESS_CREATION_MITIGATION_POLICY2_XTENDED_CONTROL_FLOW_GUARD_ALWAYS_ON equ (00000001h shl 40)
          PROCESS_CREATION_MITIGATION_POLICY2_XTENDED_CONTROL_FLOW_GUARD_ALWAYS_OFF equ (00000002h shl 40)
          PROCESS_CREATION_MITIGATION_POLICY2_XTENDED_CONTROL_FLOW_GUARD_RESERVED equ (00000003h shl 40)
          PROCESS_CREATION_MITIGATION_POLICY2_POINTER_AUTH_USER_IP_MASK equ (00000003h shl 44)
          PROCESS_CREATION_MITIGATION_POLICY2_POINTER_AUTH_USER_IP_DEFER equ (00000000h shl 44)
          PROCESS_CREATION_MITIGATION_POLICY2_POINTER_AUTH_USER_IP_ALWAYS_ON equ (00000001h shl 44)
          PROCESS_CREATION_MITIGATION_POLICY2_POINTER_AUTH_USER_IP_ALWAYS_OFF equ (00000002h shl 44)
          PROCESS_CREATION_MITIGATION_POLICY2_POINTER_AUTH_USER_IP_RESERVED equ (00000003h shl 44)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_MASK equ (00000003h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_DEFER equ (00000000h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_ALWAYS_ON equ (00000001h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_ALWAYS_OFF equ (00000002h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY2_CET_DYNAMIC_APIS_OUT_OF_PROC_ONLY_RESERVED equ (00000003h shl 48)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_CORE_SHARING_MASK equ (00000003h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_CORE_SHARING_DEFER equ (00000000h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_CORE_SHARING_ALWAYS_ON equ (00000001h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_CORE_SHARING_ALWAYS_OFF equ (00000002h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY2_RESTRICT_CORE_SHARING_RESERVED equ (00000003h shl 52)
          PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_MASK equ (00000003h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_DEFER equ (00000000h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_ALWAYS_ON equ (00000001h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_ALWAYS_OFF equ (00000002h shl 56)
          PROCESS_CREATION_MITIGATION_POLICY2_FSCTL_SYSTEM_CALL_DISABLE_RESERVED equ (00000003h shl 56)
        endif
      endif
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      PROC_THREAD_ATTRIBUTE_JOB_LIST equ <ProcThreadAttributeValue(ProcThreadAttributeJobList, FALSE, TRUE, FALSE)>
      PROCESS_CREATION_CHILD_PROCESS_RESTRICTED equ 01h
      PROCESS_CREATION_CHILD_PROCESS_OVERRIDE equ 02h
      PROCESS_CREATION_CHILD_PROCESS_RESTRICTED_UNLESS_SECURE equ 04h
      PROC_THREAD_ATTRIBUTE_CHILD_PROCESS_POLICY equ <ProcThreadAttributeValue(ProcThreadAttributeChildProcessPolicy, FALSE, TRUE, FALSE)>
      PROCESS_CREATION_ALL_APPLICATION_PACKAGES_OPT_OUT equ 01h
      PROC_THREAD_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY equ <ProcThreadAttributeValue(ProcThreadAttributeAllApplicationPackagesPolicy, FALSE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_WIN32K_FILTER equ <ProcThreadAttributeValue(ProcThreadAttributeWin32kFilter, FALSE, TRUE, FALSE)>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
      PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_ENABLE_PROCESS_TREE equ 01h
      PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_DISABLE_PROCESS_TREE equ 02h
      PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_OVERRIDE equ 04h
      PROC_THREAD_ATTRIBUTE_DESKTOP_APP_POLICY equ <ProcThreadAttributeValue(ProcThreadAttributeDesktopAppPolicy, FALSE, TRUE, FALSE)>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_MN)
      PROC_THREAD_ATTRIBUTE_MITIGATION_AUDIT_POLICY equ <ProcThreadAttributeValue(ProcThreadAttributeMitigationAuditPolicy, FALSE, TRUE, FALSE)>
      PROC_THREAD_ATTRIBUTE_COMPONENT_FILTER equ <ProcThreadAttributeValue(ProcThreadAttributeComponentFilter, FALSE, TRUE, FALSE)>
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_CET_USER_SHADOW_STACKS_MASK equ (00000003h shl 28)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_CET_USER_SHADOW_STACKS_DEFER equ (00000000h shl 28)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_CET_USER_SHADOW_STACKS_ALWAYS_ON equ (00000001h shl 28)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_CET_USER_SHADOW_STACKS_ALWAYS_OFF equ (00000002h shl 28)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_CET_USER_SHADOW_STACKS_RESERVED equ (00000003h shl 28)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_MASK equ (00000003h shl 32)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_DEFER equ (00000000h shl 32)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_ALWAYS_ON equ (00000001h shl 32)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_ALWAYS_OFF equ (00000002h shl 32)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_USER_CET_SET_CONTEXT_IP_VALIDATION_RESERVED equ (00000003h shl 32)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_BLOCK_NON_CET_BINARIES_MASK equ (00000003h shl 36)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_BLOCK_NON_CET_BINARIES_DEFER equ (00000000h shl 36)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_BLOCK_NON_CET_BINARIES_ALWAYS_ON equ (00000001h shl 36)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_BLOCK_NON_CET_BINARIES_ALWAYS_OFF equ (00000002h shl 36)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_BLOCK_NON_CET_BINARIES_RESERVED equ (00000003h shl 36)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_XTENDED_CONTROL_FLOW_GUARD_MASK equ (00000003h shl 40)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_XTENDED_CONTROL_FLOW_GUARD_DEFER equ (00000000h shl 40)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_XTENDED_CONTROL_FLOW_GUARD_ALWAYS_ON equ (00000001h shl 40)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_XTENDED_CONTROL_FLOW_GUARD_ALWAYS_OFF equ (00000002h shl 40)
      PROCESS_CREATION_MITIGATION_AUDIT_POLICY2_XTENDED_CONTROL_FLOW_GUARD_RESERVED equ (00000003h shl 40)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_NI)
      PROC_THREAD_ATTRIBUTE_TRUSTED_APP equ <ProcThreadAttributeValue(ProcThreadAttributeTrustedApp, FALSE, TRUE, FALSE)>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetStartupInfoA, WIN_STD_CALL_CONV,, <:LPSTARTUPINFOA>, 4
    ifndef UNICODE
      GetStartupInfo equ <GetStartupInfoA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if Defined(_M_CEE)
      ;[...]
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP)
    @DefProto DllImport, GetFirmwareEnvironmentVariableA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :PVOID, :DWORD>, 16
    @DefProto DllImport, GetFirmwareEnvironmentVariableW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :PVOID, :DWORD>, 16
    ifdef UNICODE
      GetFirmwareEnvironmentVariable equ <GetFirmwareEnvironmentVariableW>
    else
      GetFirmwareEnvironmentVariable equ <GetFirmwareEnvironmentVariableA>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, GetFirmwareEnvironmentVariableExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :PVOID, :DWORD, :PDWORD>, 20
      @DefProto DllImport, GetFirmwareEnvironmentVariableExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :PVOID, :DWORD, :PDWORD>, 20
      ifdef UNICODE
        GetFirmwareEnvironmentVariableEx equ <GetFirmwareEnvironmentVariableExW>
      else
        GetFirmwareEnvironmentVariableEx equ <GetFirmwareEnvironmentVariableExA>
      endif
    endif
    @DefProto DllImport, SetFirmwareEnvironmentVariableA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :PVOID, :DWORD>, 16
    @DefProto DllImport, SetFirmwareEnvironmentVariableW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :PVOID, :DWORD>, 16
    ifdef UNICODE
      SetFirmwareEnvironmentVariable equ <SetFirmwareEnvironmentVariableW>
    else
      SetFirmwareEnvironmentVariable equ <SetFirmwareEnvironmentVariableA>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, SetFirmwareEnvironmentVariableExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :PVOID, :DWORD, :DWORD>, 20
      @DefProto DllImport, SetFirmwareEnvironmentVariableExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :PVOID, :DWORD, :DWORD>, 20
      ifdef UNICODE
        SetFirmwareEnvironmentVariableEx equ <SetFirmwareEnvironmentVariableExW>
      else
        SetFirmwareEnvironmentVariableEx equ <SetFirmwareEnvironmentVariableExA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, GetFirmwareType, WIN_STD_CALL_CONV,, <:PFIRMWARE_TYPE>, 4
      @DefProto DllImport, IsNativeVhdBoot, WIN_STD_CALL_CONV,, <:PBOOL>, 4
    endif
    @DefProto DllImport, FindResourceA, WIN_STD_CALL_CONV,, <:HMODULE, :LPCSTR, :LPCSTR>, 12
    ifndef UNICODE
      FindResource equ <FindResourceA>
    endif
    @DefProto DllImport, FindResourceExA, WIN_STD_CALL_CONV,, <:HMODULE, :LPCSTR, :LPCSTR, :WORD>, 16
    ifndef UNICODE
      FindResourceEx equ <FindResourceExA>
    endif
    @DefProto DllImport, EnumResourceTypesA, WIN_STD_CALL_CONV,, <:HMODULE, :ENUMRESTYPEPROCA, :LONG_PTR>, 12
    @DefProto DllImport, EnumResourceTypesW, WIN_STD_CALL_CONV,, <:HMODULE, :ENUMRESTYPEPROCW, :LONG_PTR>, 12
    ifdef UNICODE
      EnumResourceTypes equ <EnumResourceTypesW>
    else
      EnumResourceTypes equ <EnumResourceTypesA>
    endif
    @DefProto DllImport, EnumResourceLanguagesA, WIN_STD_CALL_CONV,, <:HMODULE, :LPCSTR, :LPCSTR, :ENUMRESLANGPROCA, :LONG_PTR>, 20
    @DefProto DllImport, EnumResourceLanguagesW, WIN_STD_CALL_CONV,, <:HMODULE, :LPCWSTR, :LPCWSTR, :ENUMRESLANGPROCW, :LONG_PTR>, 20
    ifdef UNICODE
      EnumResourceLanguages equ <EnumResourceLanguagesW>
    else
      EnumResourceLanguages equ <EnumResourceLanguagesA>
    endif
    @DefProto DllImport, BeginUpdateResourceA, WIN_STD_CALL_CONV,, <:LPCSTR, :BOOL>, 8
    @DefProto DllImport, BeginUpdateResourceW, WIN_STD_CALL_CONV,, <:LPCWSTR, :BOOL>, 8
    ifdef UNICODE
      BeginUpdateResource equ <BeginUpdateResourceW>
    else
      BeginUpdateResource equ <BeginUpdateResourceA>
    endif
    @DefProto DllImport, UpdateResourceA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR, :LPCSTR, :WORD, :LPVOID, :DWORD>, 24
    @DefProto DllImport, UpdateResourceW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR, :LPCWSTR, :WORD, :LPVOID, :DWORD>, 24
    ifdef UNICODE
      UpdateResource equ <UpdateResourceW>
    else
      UpdateResource equ <UpdateResourceA>
    endif
    @DefProto DllImport, EndUpdateResourceA, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL>, 8
    @DefProto DllImport, EndUpdateResourceW, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL>, 8
    ifdef UNICODE
      EndUpdateResource equ <EndUpdateResourceW>
    else
      EndUpdateResource equ <EndUpdateResourceA>
    endif
    ATOM_FLAG_GLOBAL equ 2h
    @DefProto DllImport, GlobalAddAtomA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, GlobalAddAtomW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      GlobalAddAtom equ <GlobalAddAtomW>
    else
      GlobalAddAtom equ <GlobalAddAtomA>
    endif
    @DefProto DllImport, GlobalAddAtomExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    @DefProto DllImport, GlobalAddAtomExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      GlobalAddAtomEx equ <GlobalAddAtomExW>
    else
      GlobalAddAtomEx equ <GlobalAddAtomExA>
    endif
    @DefProto DllImport, GlobalFindAtomA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, GlobalFindAtomW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      GlobalFindAtom equ <GlobalFindAtomW>
    else
      GlobalFindAtom equ <GlobalFindAtomA>
    endif
    @DefProto DllImport, GlobalGetAtomNameA, WIN_STD_CALL_CONV,, <:ATOM, :LPSTR, :SDWORD>, 12
    @DefProto DllImport, GlobalGetAtomNameW, WIN_STD_CALL_CONV,, <:ATOM, :LPWSTR, :SDWORD>, 12
    ifdef UNICODE
      GlobalGetAtomName equ <GlobalGetAtomNameW>
    else
      GlobalGetAtomName equ <GlobalGetAtomNameA>
    endif
    @DefProto DllImport, AddAtomA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, AddAtomW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      AddAtom equ <AddAtomW>
    else
      AddAtom equ <AddAtomA>
    endif
    @DefProto DllImport, FindAtomA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, FindAtomW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      FindAtom equ <FindAtomW>
    else
      FindAtom equ <FindAtomA>
    endif
    @DefProto DllImport, GetAtomNameA, WIN_STD_CALL_CONV,, <:ATOM, :LPSTR, :SDWORD>, 12
    @DefProto DllImport, GetAtomNameW, WIN_STD_CALL_CONV,, <:ATOM, :LPWSTR, :SDWORD>, 12
    ifdef UNICODE
      GetAtomName equ <GetAtomNameW>
    else
      GetAtomName equ <GetAtomNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetProfileIntA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :INT_>, 12
    @DefProto DllImport, GetProfileIntW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :INT_>, 12
    ifdef UNICODE
      GetProfileInt equ <GetProfileIntW>
    else
      GetProfileInt equ <GetProfileIntA>
    endif
    @DefProto DllImport, GetProfileStringA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :DWORD>, 20
    @DefProto DllImport, GetProfileStringW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :DWORD>, 20
    ifdef UNICODE
      GetProfileString equ <GetProfileStringW>
    else
      GetProfileString equ <GetProfileStringA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, WriteProfileStringA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR>, 12
    @DefProto DllImport, WriteProfileStringW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR>, 12
    ifdef UNICODE
      WriteProfileString equ <WriteProfileStringW>
    else
      WriteProfileString equ <WriteProfileStringA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetProfileSectionA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    @DefProto DllImport, GetProfileSectionW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetProfileSection equ <GetProfileSectionW>
    else
      GetProfileSection equ <GetProfileSectionA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, WriteProfileSectionA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, WriteProfileSectionW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      WriteProfileSection equ <WriteProfileSectionW>
    else
      WriteProfileSection equ <WriteProfileSectionA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetPrivateProfileIntA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :INT_, :LPCSTR>, 16
    @DefProto DllImport, GetPrivateProfileIntW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :INT_, :LPCWSTR>, 16
    ifdef UNICODE
      GetPrivateProfileInt equ <GetPrivateProfileIntW>
    else
      GetPrivateProfileInt equ <GetPrivateProfileIntA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    @DefProto DllImport, GetPrivateProfileStringA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :DWORD, :LPCSTR>, 24
    @DefProto DllImport, GetPrivateProfileStringW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :DWORD, :LPCWSTR>, 24
    ifdef UNICODE
      GetPrivateProfileString equ <GetPrivateProfileStringW>
    else
      GetPrivateProfileString equ <GetPrivateProfileStringA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    @DefProto DllImport, WritePrivateProfileStringA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR>, 16
    @DefProto DllImport, WritePrivateProfileStringW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR>, 16
    ifdef UNICODE
      WritePrivateProfileString equ <WritePrivateProfileStringW>
    else
      WritePrivateProfileString equ <WritePrivateProfileStringA>
    endif
    @DefProto DllImport, GetPrivateProfileSectionA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD, :LPCSTR>, 16
    @DefProto DllImport, GetPrivateProfileSectionW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD, :LPCWSTR>, 16
    ifdef UNICODE
      GetPrivateProfileSection equ <GetPrivateProfileSectionW>
    else
      GetPrivateProfileSection equ <GetPrivateProfileSectionA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    @DefProto DllImport, WritePrivateProfileSectionA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR>, 12
    @DefProto DllImport, WritePrivateProfileSectionW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR>, 12
    ifdef UNICODE
      WritePrivateProfileSection equ <WritePrivateProfileSectionW>
    else
      WritePrivateProfileSection equ <WritePrivateProfileSectionA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, GetPrivateProfileSectionNamesA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD, :LPCSTR>, 12
    @DefProto DllImport, GetPrivateProfileSectionNamesW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD, :LPCWSTR>, 12
    ifdef UNICODE
      GetPrivateProfileSectionNames equ <GetPrivateProfileSectionNamesW>
    else
      GetPrivateProfileSectionNames equ <GetPrivateProfileSectionNamesA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    @DefProto DllImport, GetPrivateProfileStructA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPVOID, :UINT, :LPCSTR>, 20
    @DefProto DllImport, GetPrivateProfileStructW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPVOID, :UINT, :LPCWSTR>, 20
    ifdef UNICODE
      GetPrivateProfileStruct equ <GetPrivateProfileStructW>
    else
      GetPrivateProfileStruct equ <GetPrivateProfileStructA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    @DefProto DllImport, WritePrivateProfileStructA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPVOID, :UINT, :LPCSTR>, 20
    @DefProto DllImport, WritePrivateProfileStructW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPVOID, :UINT, :LPCWSTR>, 20
    ifdef UNICODE
      WritePrivateProfileStruct equ <WritePrivateProfileStructW>
    else
      WritePrivateProfileStruct equ <WritePrivateProfileStructA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    if  not Defined(RC_INVOKED)
      if _WIN32_WINNT ge 0501h or Defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)
        TYPE_PGET_SYSTEM_WOW64_DIRECTORY_A typedef proto WIN_STD_CALL_CONV :LPSTR, :UINT
        PGET_SYSTEM_WOW64_DIRECTORY_A typedef ptr TYPE_PGET_SYSTEM_WOW64_DIRECTORY_A

        TYPE_PGET_SYSTEM_WOW64_DIRECTORY_W typedef proto WIN_STD_CALL_CONV :LPWSTR, :UINT
        PGET_SYSTEM_WOW64_DIRECTORY_W typedef ptr TYPE_PGET_SYSTEM_WOW64_DIRECTORY_W

        GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A equ <"GetSystemWow64DirectoryA">
        GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W equ <L("GetSystemWow64DirectoryA")>
        GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T equ <TEXT("GetSystemWow64DirectoryA")>
        GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A equ <"GetSystemWow64DirectoryW">
        GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W equ <L("GetSystemWow64DirectoryW")>
        GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T equ <TEXT("GetSystemWow64DirectoryW")>
        ifdef UNICODE
          GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A equ <GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A>
          GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W equ <GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W>
          GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T equ <GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T>
        else
          GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A equ <GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A>
          GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W equ <GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W>
          GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T equ <GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T>
        endif
      endif
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    if _WIN32_WINNT ge 0502h
      @DefProto DllImport, SetDllDirectoryA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, SetDllDirectoryW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        SetDllDirectory equ <SetDllDirectoryW>
      else
        SetDllDirectory equ <SetDllDirectoryA>
      endif
    endif
    if _WIN32_WINNT ge 0502h
      @DefProto DllImport, GetDllDirectoryA, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR>, 8
      @DefProto DllImport, GetDllDirectoryW, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR>, 8
      ifdef UNICODE
        GetDllDirectory equ <GetDllDirectoryW>
      else
        GetDllDirectory equ <GetDllDirectoryA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE equ 1h
    BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE equ 10000h
    BASE_SEARCH_PATH_PERMANENT equ 8000h
    BASE_SEARCH_PATH_INVALID_FLAGS equ not 18001h
    @DefProto DllImport, SetSearchPathMode, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    if Defined(_M_CEE)
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateDirectoryExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSECURITY_ATTRIBUTES>, 12
    @DefProto DllImport, CreateDirectoryExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPSECURITY_ATTRIBUTES>, 12
    ifdef UNICODE
      CreateDirectoryEx equ <CreateDirectoryExW>
    else
      CreateDirectoryEx equ <CreateDirectoryExA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, CreateDirectoryTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSECURITY_ATTRIBUTES, :HANDLE>, 16
      @DefProto DllImport, CreateDirectoryTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPSECURITY_ATTRIBUTES, :HANDLE>, 16
      ifdef UNICODE
        CreateDirectoryTransacted equ <CreateDirectoryTransactedW>
      else
        CreateDirectoryTransacted equ <CreateDirectoryTransactedA>
      endif
      @DefProto DllImport, RemoveDirectoryTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :HANDLE>, 8
      @DefProto DllImport, RemoveDirectoryTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HANDLE>, 8
      ifdef UNICODE
        RemoveDirectoryTransacted equ <RemoveDirectoryTransactedW>
      else
        RemoveDirectoryTransacted equ <RemoveDirectoryTransactedA>
      endif
      @DefProto DllImport, GetFullPathNameTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :LPSTR, :ptr LPSTR, :HANDLE>, 20
      @DefProto DllImport, GetFullPathNameTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPWSTR, :ptr LPWSTR, :HANDLE>, 20
      ifdef UNICODE
        GetFullPathNameTransacted equ <GetFullPathNameTransactedW>
      else
        GetFullPathNameTransacted equ <GetFullPathNameTransactedA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    DDD_RAW_TARGET_PATH equ 00000001h
    DDD_REMOVE_DEFINITION equ 00000002h
    DDD_EXACT_MATCH_ON_REMOVE equ 00000004h
    DDD_NO_BROADCAST_SYSTEM equ 00000008h
    DDD_LUID_BROADCAST_DRIVE equ 00000010h
    @DefProto DllImport, DefineDosDeviceA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR>, 12
    ifndef UNICODE
      DefineDosDevice equ <DefineDosDeviceA>
    endif
    @DefProto DllImport, QueryDosDeviceA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    ifndef UNICODE
      QueryDosDevice equ <QueryDosDeviceA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    EXPAND_LOCAL_DRIVES equ <>
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, CreateFileTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :HANDLE, :HANDLE, :PUSHORT, :PVOID>, 40
      @DefProto DllImport, CreateFileTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :HANDLE, :HANDLE, :PUSHORT, :PVOID>, 40
      ifdef UNICODE
        CreateFileTransacted equ <CreateFileTransactedW>
      else
        CreateFileTransacted equ <CreateFileTransactedA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if _WIN32_WINNT ge 0502h
      @DefProto DllImport, ReOpenFile, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, SetFileAttributesTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :HANDLE>, 12
      @DefProto DllImport, SetFileAttributesTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :HANDLE>, 12
      ifdef UNICODE
        SetFileAttributesTransacted equ <SetFileAttributesTransactedW>
      else
        SetFileAttributesTransacted equ <SetFileAttributesTransactedA>
      endif
      @DefProto DllImport, GetFileAttributesTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :GET_FILEEX_INFO_LEVELS, :LPVOID, :HANDLE>, 16
      @DefProto DllImport, GetFileAttributesTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :GET_FILEEX_INFO_LEVELS, :LPVOID, :HANDLE>, 16
      ifdef UNICODE
        GetFileAttributesTransacted equ <GetFileAttributesTransactedW>
      else
        GetFileAttributesTransacted equ <GetFileAttributesTransactedA>
      endif
      @DefProto DllImport, GetCompressedFileSizeTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDWORD, :HANDLE>, 12
      @DefProto DllImport, GetCompressedFileSizeTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDWORD, :HANDLE>, 12
      ifdef UNICODE
        GetCompressedFileSizeTransacted equ <GetCompressedFileSizeTransactedW>
      else
        GetCompressedFileSizeTransacted equ <GetCompressedFileSizeTransactedA>
      endif
      @DefProto DllImport, DeleteFileTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :HANDLE>, 8
      @DefProto DllImport, DeleteFileTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HANDLE>, 8
      ifdef UNICODE
        DeleteFileTransacted equ <DeleteFileTransactedW>
      else
        DeleteFileTransacted equ <DeleteFileTransactedA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    if Defined(_M_CEE)
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0501h
      @DefProto DllImport, CheckNameLegalDOS8Dot3A, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD, :PBOOL, :PBOOL>, 20
      @DefProto DllImport, CheckNameLegalDOS8Dot3W, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSTR, :DWORD, :PBOOL, :PBOOL>, 20
      ifdef UNICODE
        CheckNameLegalDOS8Dot3 equ <CheckNameLegalDOS8Dot3W>
      else
        CheckNameLegalDOS8Dot3 equ <CheckNameLegalDOS8Dot3A>
      endif
    endif
  endif
  if (_WIN32_WINNT ge 0400h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, FindFirstFileTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :FINDEX_INFO_LEVELS, :LPVOID, :FINDEX_SEARCH_OPS, :LPVOID, :DWORD, :HANDLE>, 28
        @DefProto DllImport, FindFirstFileTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :FINDEX_INFO_LEVELS, :LPVOID, :FINDEX_SEARCH_OPS, :LPVOID, :DWORD, :HANDLE>, 28
        ifdef UNICODE
          FindFirstFileTransacted equ <FindFirstFileTransactedW>
        else
          FindFirstFileTransacted equ <FindFirstFileTransactedA>
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CopyFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :BOOL>, 12
    @DefProto DllImport, CopyFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :BOOL>, 12
    ifdef UNICODE
      CopyFile equ <CopyFileW>
    else
      CopyFile equ <CopyFileA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
  endif
  if (_WIN32_WINNT ge 0400h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      TYPE_LPPROGRESS_ROUTINE typedef proto WIN_STD_CALL_CONV :LARGE_INTEGER, :LARGE_INTEGER, :LARGE_INTEGER, :LARGE_INTEGER, :DWORD, :DWORD, :HANDLE, :HANDLE, :LPVOID
      LPPROGRESS_ROUTINE typedef ptr TYPE_LPPROGRESS_ROUTINE

      @DefProto DllImport, CopyFileExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPPROGRESS_ROUTINE, :LPVOID, :LPBOOL, :DWORD>, 24
      @DefProto DllImport, CopyFileExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPPROGRESS_ROUTINE, :LPVOID, :LPBOOL, :DWORD>, 24
      ifdef UNICODE
        CopyFileEx equ <CopyFileExW>
      else
        CopyFileEx equ <CopyFileExA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, CopyFileTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPPROGRESS_ROUTINE, :LPVOID, :LPBOOL, :DWORD, :HANDLE>, 28
        @DefProto DllImport, CopyFileTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPPROGRESS_ROUTINE, :LPVOID, :LPBOOL, :DWORD, :HANDLE>, 28
        ifdef UNICODE
          CopyFileTransacted equ <CopyFileTransactedW>
        else
          CopyFileTransacted equ <CopyFileTransactedA>
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if _WIN32_WINNT ge 0601h
        COPYFILE2_MESSAGE_TYPE typedef SDWORD
        COPYFILE2_CALLBACK_NONE equ 0
        COPYFILE2_CALLBACK_CHUNK_STARTED equ 1
        COPYFILE2_CALLBACK_CHUNK_FINISHED equ 2
        COPYFILE2_CALLBACK_STREAM_STARTED equ 3
        COPYFILE2_CALLBACK_STREAM_FINISHED equ 4
        COPYFILE2_CALLBACK_POLL_CONTINUE equ 5
        COPYFILE2_CALLBACK_ERROR equ 6
        COPYFILE2_CALLBACK_MAX equ 7
        _COPYFILE2_MESSAGE_TYPE typedef COPYFILE2_MESSAGE_TYPE

        COPYFILE2_MESSAGE_ACTION typedef SDWORD
        COPYFILE2_PROGRESS_CONTINUE equ 0
        COPYFILE2_PROGRESS_CANCEL equ 1
        COPYFILE2_PROGRESS_STOP equ 2
        COPYFILE2_PROGRESS_QUIET equ 3
        COPYFILE2_PROGRESS_PAUSE equ 4
        _COPYFILE2_MESSAGE_ACTION typedef COPYFILE2_MESSAGE_ACTION

        COPYFILE2_COPY_PHASE typedef SDWORD
        COPYFILE2_PHASE_NONE equ 0
        COPYFILE2_PHASE_PREPARE_SOURCE equ 1
        COPYFILE2_PHASE_PREPARE_DEST equ 2
        COPYFILE2_PHASE_READ_SOURCE equ 3
        COPYFILE2_PHASE_WRITE_DESTINATION equ 4
        COPYFILE2_PHASE_SERVER_COPY equ 5
        COPYFILE2_PHASE_NAMEGRAFT_COPY equ 6
        COPYFILE2_PHASE_MAX equ 7
        _COPYFILE2_COPY_PHASE typedef COPYFILE2_COPY_PHASE

        COPYFILE2_MESSAGE_COPY_OFFLOAD equ (00000001h)
        COPYFILE2_MESSAGE struct
          Type_ COPYFILE2_MESSAGE_TYPE ?
          dwPadding DWORD ?
          union Info
            struct ChunkStarted
              dwStreamNumber DWORD ?
              dwReserved DWORD ?
              hSourceFile HANDLE ?
              hDestinationFile HANDLE ?
              uliChunkNumber ULARGE_INTEGER <>
              uliChunkSize ULARGE_INTEGER <>
              uliStreamSize ULARGE_INTEGER <>
              uliTotalFileSize ULARGE_INTEGER <>
            ends
            struct ChunkFinished
              dwStreamNumber DWORD ?
              dwFlags DWORD ?
              hSourceFile HANDLE ?
              hDestinationFile HANDLE ?
              uliChunkNumber ULARGE_INTEGER <>
              uliChunkSize ULARGE_INTEGER <>
              uliStreamSize ULARGE_INTEGER <>
              uliStreamBytesTransferred ULARGE_INTEGER <>
              uliTotalFileSize ULARGE_INTEGER <>
              uliTotalBytesTransferred ULARGE_INTEGER <>
            ends
            struct StreamStarted
              dwStreamNumber DWORD ?
              dwReserved DWORD ?
              hSourceFile HANDLE ?
              hDestinationFile HANDLE ?
              uliStreamSize ULARGE_INTEGER <>
              uliTotalFileSize ULARGE_INTEGER <>
            ends
            struct StreamFinished
              dwStreamNumber DWORD ?
              dwReserved DWORD ?
              hSourceFile HANDLE ?
              hDestinationFile HANDLE ?
              uliStreamSize ULARGE_INTEGER <>
              uliStreamBytesTransferred ULARGE_INTEGER <>
              uliTotalFileSize ULARGE_INTEGER <>
              uliTotalBytesTransferred ULARGE_INTEGER <>
            ends
            struct PollContinue
              dwReserved DWORD ?
            ends
            struct Error_
              CopyPhase COPYFILE2_COPY_PHASE ?
              dwStreamNumber DWORD ?
              hrFailure HRESULT ?
              dwReserved DWORD ?
              uliChunkNumber ULARGE_INTEGER <>
              uliStreamSize ULARGE_INTEGER <>
              uliStreamBytesTransferred ULARGE_INTEGER <>
              uliTotalFileSize ULARGE_INTEGER <>
              uliTotalBytesTransferred ULARGE_INTEGER <>
            ends
          ends
        COPYFILE2_MESSAGE ends
        TYPE_PCOPYFILE2_PROGRESS_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr COPYFILE2_MESSAGE, :PVOID
        PCOPYFILE2_PROGRESS_ROUTINE typedef ptr TYPE_PCOPYFILE2_PROGRESS_ROUTINE

        COPYFILE2_EXTENDED_PARAMETERS struct
          dwSize DWORD ?
          dwCopyFlags DWORD ?
          pfCancel POINTER ?
          pProgressRoutine PCOPYFILE2_PROGRESS_ROUTINE ?
          pvCallbackContext PVOID ?
        COPYFILE2_EXTENDED_PARAMETERS ends
        if (NTDDI_VERSION ge NTDDI_WIN10_FE)
          COPYFILE2_IO_CYCLE_SIZE_MIN equ 4096
          COPYFILE2_IO_CYCLE_SIZE_MAX equ 40000000h
          COPYFILE2_IO_RATE_MIN equ 512
          COPYFILE2_EXTENDED_PARAMETERS_V2 struct
            dwSize DWORD ?
            dwCopyFlags DWORD ?
            pfCancel POINTER ?
            pProgressRoutine PCOPYFILE2_PROGRESS_ROUTINE ?
            pvCallbackContext PVOID ?
            dwCopyFlagsV2 DWORD ?
            ioDesiredSize ULONG ?
            ioDesiredRate ULONG ?
            reserved PVOID 8 dup (?)
          COPYFILE2_EXTENDED_PARAMETERS_V2 ends
          if (NTDDI_VERSION ge NTDDI_WIN10_NI)
            COPY_FILE2_V2_DONT_COPY_JUNCTIONS equ 00000001h
            COPY_FILE2_V2_VALID_FLAGS equ <(COPY_FILE2_V2_DONT_COPY_JUNCTIONS)>
          endif
        endif
        @DefProto DllImport, CopyFile2, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :ptr COPYFILE2_EXTENDED_PARAMETERS>, 12
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, MoveFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, MoveFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      MoveFile equ <MoveFileW>
    else
      MoveFile equ <MoveFileA>
    endif
    if Defined(_M_CEE)
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, MoveFileExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD>, 12
    @DefProto DllImport, MoveFileExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD>, 12
    ifdef UNICODE
      MoveFileEx equ <MoveFileExW>
    else
      MoveFileEx equ <MoveFileExA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, MoveFileWithProgressA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPPROGRESS_ROUTINE, :LPVOID, :DWORD>, 20
      @DefProto DllImport, MoveFileWithProgressW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPPROGRESS_ROUTINE, :LPVOID, :DWORD>, 20
      ifdef UNICODE
        MoveFileWithProgress equ <MoveFileWithProgressW>
      else
        MoveFileWithProgress equ <MoveFileWithProgressA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, MoveFileTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPPROGRESS_ROUTINE, :LPVOID, :DWORD, :HANDLE>, 24
      @DefProto DllImport, MoveFileTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPPROGRESS_ROUTINE, :LPVOID, :DWORD, :HANDLE>, 24
      ifdef UNICODE
        MoveFileTransacted equ <MoveFileTransactedW>
      else
        MoveFileTransacted equ <MoveFileTransactedA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    MOVEFILE_REPLACE_EXISTING equ 00000001h
    MOVEFILE_COPY_ALLOWED equ 00000002h
    MOVEFILE_DELAY_UNTIL_REBOOT equ 00000004h
    MOVEFILE_WRITE_THROUGH equ 00000008h
    if (_WIN32_WINNT ge 0500h)
      MOVEFILE_CREATE_HARDLINK equ 00000010h
      MOVEFILE_FAIL_IF_NOT_TRACKABLE equ 00000020h
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, ReplaceFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :DWORD, :LPVOID, :LPVOID>, 24
      @DefProto DllImport, ReplaceFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :LPVOID, :LPVOID>, 24
      ifdef UNICODE
        ReplaceFile equ <ReplaceFileW>
      else
        ReplaceFile equ <ReplaceFileA>
      endif
    endif
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, CreateHardLinkA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSECURITY_ATTRIBUTES>, 12
      @DefProto DllImport, CreateHardLinkW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPSECURITY_ATTRIBUTES>, 12
      ifdef UNICODE
        CreateHardLink equ <CreateHardLinkW>
      else
        CreateHardLink equ <CreateHardLinkA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, CreateHardLinkTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSECURITY_ATTRIBUTES, :HANDLE>, 16
      @DefProto DllImport, CreateHardLinkTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPSECURITY_ATTRIBUTES, :HANDLE>, 16
      ifdef UNICODE
        CreateHardLinkTransacted equ <CreateHardLinkTransactedW>
      else
        CreateHardLinkTransacted equ <CreateHardLinkTransactedA>
      endif
    endif
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, FindFirstStreamTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :STREAM_INFO_LEVELS, :LPVOID, :DWORD, :HANDLE>, 20
      @DefProto DllImport, FindFirstFileNameTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPDWORD, :PWSTR, :HANDLE>, 20
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateNamedPipeA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES>, 32
    ifndef UNICODE
      CreateNamedPipe equ <CreateNamedPipeA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetNamedPipeHandleStateA, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPSTR, :DWORD>, 28
    ifndef UNICODE
      GetNamedPipeHandleState equ <GetNamedPipeHandleStateA>
    endif
    @DefProto DllImport, CallNamedPipeA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :DWORD>, 28
    ifndef UNICODE
      CallNamedPipe equ <CallNamedPipeA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, WaitNamedPipeA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    ifndef UNICODE
      WaitNamedPipe equ <WaitNamedPipeA>
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, GetNamedPipeClientComputerNameA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSTR, :ULONG>, 12
      ifndef UNICODE
        GetNamedPipeClientComputerName equ <GetNamedPipeClientComputerNameA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetNamedPipeClientProcessId, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG>, 8
      @DefProto DllImport, GetNamedPipeClientSessionId, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG>, 8
      @DefProto DllImport, GetNamedPipeServerProcessId, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG>, 8
      @DefProto DllImport, GetNamedPipeServerSessionId, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, SetVolumeLabelA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, SetVolumeLabelW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      SetVolumeLabel equ <SetVolumeLabelW>
    else
      SetVolumeLabel equ <SetVolumeLabelA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetFileBandwidthReservation, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :BOOL, :LPDWORD, :LPDWORD>, 24
      @DefProto DllImport, GetFileBandwidthReservation, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPDWORD, :LPBOOL, :LPDWORD, :LPDWORD>, 24
    endif
    @DefProto DllImport, ClearEventLogA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR>, 8
    @DefProto DllImport, ClearEventLogW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR>, 8
    ifdef UNICODE
      ClearEventLog equ <ClearEventLogW>
    else
      ClearEventLog equ <ClearEventLogA>
    endif
    @DefProto DllImport, BackupEventLogA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR>, 8
    @DefProto DllImport, BackupEventLogW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR>, 8
    ifdef UNICODE
      BackupEventLog equ <BackupEventLogW>
    else
      BackupEventLog equ <BackupEventLogA>
    endif
    @DefProto DllImport, CloseEventLog, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, DeregisterEventSource, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, NotifyChangeEventLog, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
    @DefProto DllImport, GetNumberOfEventLogRecords, WIN_STD_CALL_CONV,, <:HANDLE, :PDWORD>, 8
    @DefProto DllImport, GetOldestEventLogRecord, WIN_STD_CALL_CONV,, <:HANDLE, :PDWORD>, 8
    @DefProto DllImport, OpenEventLogA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, OpenEventLogW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      OpenEventLog equ <OpenEventLogW>
    else
      OpenEventLog equ <OpenEventLogA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, RegisterEventSourceA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, RegisterEventSourceW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      RegisterEventSource equ <RegisterEventSourceW>
    else
      RegisterEventSource equ <RegisterEventSourceA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, OpenBackupEventLogA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, OpenBackupEventLogW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      OpenBackupEventLog equ <OpenBackupEventLogW>
    else
      OpenBackupEventLog equ <OpenBackupEventLogA>
    endif
    @DefProto DllImport, ReadEventLogA, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :ptr DWORD>, 28
    @DefProto DllImport, ReadEventLogW, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :ptr DWORD>, 28
    ifdef UNICODE
      ReadEventLog equ <ReadEventLogW>
    else
      ReadEventLog equ <ReadEventLogA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, ReportEventA, WIN_STD_CALL_CONV,, <:HANDLE, :WORD, :WORD, :DWORD, :PSID, :WORD, :DWORD, :ptr LPCSTR, :LPVOID>, 36
    @DefProto DllImport, ReportEventW, WIN_STD_CALL_CONV,, <:HANDLE, :WORD, :WORD, :DWORD, :PSID, :WORD, :DWORD, :ptr LPCWSTR, :LPVOID>, 36
    ifdef UNICODE
      ReportEvent equ <ReportEventW>
    else
      ReportEvent equ <ReportEventA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    EVENTLOG_FULL_INFO equ 0
    EVENTLOG_FULL_INFORMATION struct
      dwFull DWORD ?
    EVENTLOG_FULL_INFORMATION ends
    _EVENTLOG_FULL_INFORMATION typedef EVENTLOG_FULL_INFORMATION
    LPEVENTLOG_FULL_INFORMATION typedef ptr EVENTLOG_FULL_INFORMATION
    @DefProto DllImport, GetEventLogInformation, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPVOID, :DWORD, :LPDWORD>, 20
    if (_WIN32_WINNT ge 0602h)
      OPERATION_API_VERSION equ 1
      OPERATION_ID typedef ULONG
      OPERATION_START_PARAMETERS struct
        Version ULONG ?
        OperationId OPERATION_ID ?
        Flags ULONG ?
      OPERATION_START_PARAMETERS ends
      _OPERATION_START_PARAMETERS typedef OPERATION_START_PARAMETERS
      POPERATION_START_PARAMETERS typedef ptr OPERATION_START_PARAMETERS
      OPERATION_START_TRACE_CURRENT_THREAD equ 1h
      OPERATION_END_PARAMETERS struct
        Version ULONG ?
        OperationId OPERATION_ID ?
        Flags ULONG ?
      OPERATION_END_PARAMETERS ends
      _OPERATION_END_PARAMETERS typedef OPERATION_END_PARAMETERS
      POPERATION_END_PARAMETERS typedef ptr OPERATION_END_PARAMETERS
      OPERATION_END_DISCARD equ 1h
      @DefProto DllImport, OperationStart, WIN_STD_CALL_CONV,, <:ptr OPERATION_START_PARAMETERS>, 4
      @DefProto DllImport, OperationEnd, WIN_STD_CALL_CONV,, <:ptr OPERATION_END_PARAMETERS>, 4
    endif
    @DefProto DllImport, AccessCheckAndAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :LPSTR, :LPSTR, :PSECURITY_DESCRIPTOR, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPBOOL, :LPBOOL>, 44
    ifndef UNICODE
      AccessCheckAndAuditAlarm equ <AccessCheckAndAuditAlarmA>
    endif
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, AccessCheckByTypeAndAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :LPCSTR, :LPCSTR, :PSECURITY_DESCRIPTOR, :PSID, :DWORD, :AUDIT_EVENT_TYPE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPBOOL, :LPBOOL>, 64
      ifndef UNICODE
        AccessCheckByTypeAndAuditAlarm equ <AccessCheckByTypeAndAuditAlarmA>
      endif
      @DefProto DllImport, AccessCheckByTypeResultListAndAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :LPCSTR, :LPCSTR, :PSECURITY_DESCRIPTOR, :PSID, :DWORD, :AUDIT_EVENT_TYPE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPDWORD, :LPBOOL>, 64
      ifndef UNICODE
        AccessCheckByTypeResultListAndAuditAlarm equ <AccessCheckByTypeResultListAndAuditAlarmA>
      endif
      @DefProto DllImport, AccessCheckByTypeResultListAndAuditAlarmByHandleA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :HANDLE, :LPCSTR, :LPCSTR, :PSECURITY_DESCRIPTOR, :PSID, :DWORD, :AUDIT_EVENT_TYPE, :DWORD, :POBJECT_TYPE_LIST, :DWORD, :PGENERIC_MAPPING, :BOOL, :LPDWORD, :LPDWORD, :LPBOOL>, 68
      ifndef UNICODE
        AccessCheckByTypeResultListAndAuditAlarmByHandle equ <AccessCheckByTypeResultListAndAuditAlarmByHandleA>
      endif
    endif
    @DefProto DllImport, ObjectOpenAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :LPSTR, :LPSTR, :PSECURITY_DESCRIPTOR, :HANDLE, :DWORD, :DWORD, :PPRIVILEGE_SET, :BOOL, :BOOL, :LPBOOL>, 48
    ifndef UNICODE
      ObjectOpenAuditAlarm equ <ObjectOpenAuditAlarmA>
    endif
    @DefProto DllImport, ObjectPrivilegeAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :HANDLE, :DWORD, :PPRIVILEGE_SET, :BOOL>, 24
    ifndef UNICODE
      ObjectPrivilegeAuditAlarm equ <ObjectPrivilegeAuditAlarmA>
    endif
    @DefProto DllImport, ObjectCloseAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :BOOL>, 12
    ifndef UNICODE
      ObjectCloseAuditAlarm equ <ObjectCloseAuditAlarmA>
    endif
    @DefProto DllImport, ObjectDeleteAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPVOID, :BOOL>, 12
    ifndef UNICODE
      ObjectDeleteAuditAlarm equ <ObjectDeleteAuditAlarmA>
    endif
    @DefProto DllImport, PrivilegedServiceAuditAlarmA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :HANDLE, :PPRIVILEGE_SET, :BOOL>, 20
    ifndef UNICODE
      PrivilegedServiceAuditAlarm equ <PrivilegedServiceAuditAlarmA>
    endif
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, AddConditionalAce, WIN_STD_CALL_CONV,, <:PACL, :DWORD, :DWORD, :UCHAR, :DWORD, :PSID, :PWCHAR, :ptr DWORD>, 32
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetFileSecurityA, WIN_STD_CALL_CONV,, <:LPCSTR, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR>, 12
    ifndef UNICODE
      SetFileSecurity equ <SetFileSecurityA>
    endif
    @DefProto DllImport, GetFileSecurityA, WIN_STD_CALL_CONV,, <:LPCSTR, :SECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :DWORD, :LPDWORD>, 20
    ifndef UNICODE
      GetFileSecurity equ <GetFileSecurityA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0400h)
      @DefProto DllImport, ReadDirectoryChangesW, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :BOOL, :DWORD, :LPDWORD, :LPOVERLAPPED, :LPOVERLAPPED_COMPLETION_ROUTINE>, 32
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        @DefProto DllImport, ReadDirectoryChangesExW, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :BOOL, :DWORD, :LPDWORD, :LPOVERLAPPED, :LPOVERLAPPED_COMPLETION_ROUTINE, :READ_DIRECTORY_NOTIFY_INFORMATION_CLASS>, 36
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, MapViewOfFileExNuma, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :SIZE_T, :LPVOID, :DWORD>, 28
    endif
    @DefProto DllImport, IsBadReadPtr, WIN_STD_CALL_CONV,, <:ptr VOID, :UINT_PTR>, 8
    @DefProto DllImport, IsBadWritePtr, WIN_STD_CALL_CONV,, <:LPVOID, :UINT_PTR>, 8
    @DefProto DllImport, IsBadHugeReadPtr, WIN_STD_CALL_CONV,, <:ptr VOID, :UINT_PTR>, 8
    @DefProto DllImport, IsBadHugeWritePtr, WIN_STD_CALL_CONV,, <:LPVOID, :UINT_PTR>, 8
    @DefProto DllImport, IsBadCodePtr, WIN_STD_CALL_CONV,, <:FARPROC>, 4
    @DefProto DllImport, IsBadStringPtrA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT_PTR>, 8
    @DefProto DllImport, IsBadStringPtrW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT_PTR>, 8
    ifdef UNICODE
      IsBadStringPtr equ <IsBadStringPtrW>
    else
      IsBadStringPtr equ <IsBadStringPtrA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, LookupAccountSidA, WIN_STD_CALL_CONV,, <:LPCSTR, :PSID, :LPSTR, :LPDWORD, :LPSTR, :LPDWORD, :PSID_NAME_USE>, 28
    @DefProto DllImport, LookupAccountSidW, WIN_STD_CALL_CONV,, <:LPCWSTR, :PSID, :LPWSTR, :LPDWORD, :LPWSTR, :LPDWORD, :PSID_NAME_USE>, 28
    ifdef UNICODE
      LookupAccountSid equ <LookupAccountSidW>
    else
      LookupAccountSid equ <LookupAccountSidA>
    endif
    @DefProto DllImport, LookupAccountNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :PSID, :LPDWORD, :LPSTR, :LPDWORD, :PSID_NAME_USE>, 28
    @DefProto DllImport, LookupAccountNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :PSID, :LPDWORD, :LPWSTR, :LPDWORD, :PSID_NAME_USE>, 28
    ifdef UNICODE
      LookupAccountName equ <LookupAccountNameW>
    else
      LookupAccountName equ <LookupAccountNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, LookupAccountNameLocalA, WIN_STD_CALL_CONV,, <:LPCSTR, :PSID, :LPDWORD, :LPSTR, :LPDWORD, :PSID_NAME_USE>, 24
      @DefProto DllImport, LookupAccountNameLocalW, WIN_STD_CALL_CONV,, <:LPCWSTR, :PSID, :LPDWORD, :LPWSTR, :LPDWORD, :PSID_NAME_USE>, 24
      ifdef UNICODE
        LookupAccountNameLocal equ <LookupAccountNameLocalW>
      else
        LookupAccountNameLocal equ <LookupAccountNameLocalA>
      endif
      @DefProto DllImport, LookupAccountSidLocalA, WIN_STD_CALL_CONV,, <:PSID, :LPSTR, :LPDWORD, :LPSTR, :LPDWORD, :PSID_NAME_USE>, 24
      @DefProto DllImport, LookupAccountSidLocalW, WIN_STD_CALL_CONV,, <:PSID, :LPWSTR, :LPDWORD, :LPWSTR, :LPDWORD, :PSID_NAME_USE>, 24
      ifdef UNICODE
        LookupAccountSidLocal equ <LookupAccountSidLocalW>
      else
        LookupAccountSidLocal equ <LookupAccountSidLocalA>
      endif
    else
      LookupAccountNameLocalA macro n, s, cs_, d, cd, u
        exitm <LookupAccountNameA (NULL, n, s, cs_, d, cd, u)>
      endm
      LookupAccountNameLocalW macro n, s, cs_, d, cd, u
        exitm <LookupAccountNameW (NULL, n, s, cs_, d, cd, u)>
      endm
      ifdef UNICODE
        LookupAccountNameLocal equ <LookupAccountNameLocalW>
      else
        LookupAccountNameLocal equ <LookupAccountNameLocalA>
      endif
      LookupAccountSidLocalA macro s, n, cn, d, cd, u
        exitm <LookupAccountSidA (NULL, s, n, cn, d, cd, u)>
      endm
      LookupAccountSidLocalW macro s, n, cn, d, cd, u
        exitm <LookupAccountSidW (NULL, s, n, cn, d, cd, u)>
      endm
      ifdef UNICODE
        LookupAccountSidLocal equ <LookupAccountSidLocalW>
      else
        LookupAccountSidLocal equ <LookupAccountSidLocalA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, LookupPrivilegeValueA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :PLUID>, 12
    @DefProto DllImport, LookupPrivilegeValueW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :PLUID>, 12
    ifdef UNICODE
      LookupPrivilegeValue equ <LookupPrivilegeValueW>
    else
      LookupPrivilegeValue equ <LookupPrivilegeValueA>
    endif
    @DefProto DllImport, LookupPrivilegeNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :PLUID, :LPSTR, :LPDWORD>, 16
    @DefProto DllImport, LookupPrivilegeNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :PLUID, :LPWSTR, :LPDWORD>, 16
    ifdef UNICODE
      LookupPrivilegeName equ <LookupPrivilegeNameW>
    else
      LookupPrivilegeName equ <LookupPrivilegeNameA>
    endif
    @DefProto DllImport, LookupPrivilegeDisplayNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSTR, :LPDWORD, :LPDWORD>, 20
    @DefProto DllImport, LookupPrivilegeDisplayNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR, :LPDWORD, :LPDWORD>, 20
    ifdef UNICODE
      LookupPrivilegeDisplayName equ <LookupPrivilegeDisplayNameW>
    else
      LookupPrivilegeDisplayName equ <LookupPrivilegeDisplayNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, BuildCommDCBA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDCB>, 8
    @DefProto DllImport, BuildCommDCBW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDCB>, 8
    ifdef UNICODE
      BuildCommDCB equ <BuildCommDCBW>
    else
      BuildCommDCB equ <BuildCommDCBA>
    endif
    @DefProto DllImport, BuildCommDCBAndTimeoutsA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDCB, :LPCOMMTIMEOUTS>, 12
    @DefProto DllImport, BuildCommDCBAndTimeoutsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDCB, :LPCOMMTIMEOUTS>, 12
    ifdef UNICODE
      BuildCommDCBAndTimeouts equ <BuildCommDCBAndTimeoutsW>
    else
      BuildCommDCBAndTimeouts equ <BuildCommDCBAndTimeoutsA>
    endif
    @DefProto DllImport, CommConfigDialogA, WIN_STD_CALL_CONV,, <:LPCSTR, :HWND, :LPCOMMCONFIG>, 12
    @DefProto DllImport, CommConfigDialogW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HWND, :LPCOMMCONFIG>, 12
    ifdef UNICODE
      CommConfigDialog equ <CommConfigDialogW>
    else
      CommConfigDialog equ <CommConfigDialogA>
    endif
    @DefProto DllImport, GetDefaultCommConfigA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCOMMCONFIG, :LPDWORD>, 12
    @DefProto DllImport, GetDefaultCommConfigW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCOMMCONFIG, :LPDWORD>, 12
    ifdef UNICODE
      GetDefaultCommConfig equ <GetDefaultCommConfigW>
    else
      GetDefaultCommConfig equ <GetDefaultCommConfigA>
    endif
    @DefProto DllImport, SetDefaultCommConfigA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCOMMCONFIG, :DWORD>, 12
    @DefProto DllImport, SetDefaultCommConfigW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCOMMCONFIG, :DWORD>, 12
    ifdef UNICODE
      SetDefaultCommConfig equ <SetDefaultCommConfigW>
    else
      SetDefaultCommConfig equ <SetDefaultCommConfigA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef _MAC
      MAX_COMPUTERNAME_LENGTH equ 15
    else
      ;[...]
    endif
    @DefProto DllImport, GetComputerNameA, WIN_STD_CALL_CONV,, <:LPSTR, :LPDWORD>, 8
    @DefProto DllImport, GetComputerNameW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPDWORD>, 8
    ifdef UNICODE
      GetComputerName equ <GetComputerNameW>
    else
      GetComputerName equ <GetComputerNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, DnsHostnameToComputerNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :LPDWORD>, 12
      @DefProto DllImport, DnsHostnameToComputerNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :LPDWORD>, 12
      ifdef UNICODE
        DnsHostnameToComputerName equ <DnsHostnameToComputerNameW>
      else
        DnsHostnameToComputerName equ <DnsHostnameToComputerNameA>
      endif
    endif
    @DefProto DllImport, GetUserNameA, WIN_STD_CALL_CONV,, <:LPSTR, :LPDWORD>, 8
    @DefProto DllImport, GetUserNameW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPDWORD>, 8
    ifdef UNICODE
      GetUserName equ <GetUserNameW>
    else
      GetUserName equ <GetUserNameA>
    endif
    LOGON32_LOGON_INTERACTIVE equ 2
    LOGON32_LOGON_NETWORK equ 3
    LOGON32_LOGON_BATCH equ 4
    LOGON32_LOGON_SERVICE equ 5
    LOGON32_LOGON_UNLOCK equ 7
    if (_WIN32_WINNT ge 0500h)
      LOGON32_LOGON_NETWORK_CLEARTEXT equ 8
      LOGON32_LOGON_NEW_CREDENTIALS equ 9
    endif
    LOGON32_PROVIDER_DEFAULT equ 0
    LOGON32_PROVIDER_WINNT35 equ 1
    if (_WIN32_WINNT ge 0400h)
      LOGON32_PROVIDER_WINNT40 equ 2
    endif
    if (_WIN32_WINNT ge 0500h)
      LOGON32_PROVIDER_WINNT50 equ 3
    endif
    if (_WIN32_WINNT ge 0600h)
      LOGON32_PROVIDER_VIRTUAL equ 4
    endif
    @DefProto DllImport, LogonUserA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :DWORD, :DWORD, :PHANDLE>, 24
    @DefProto DllImport, LogonUserW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :PHANDLE>, 24
    ifdef UNICODE
      LogonUser equ <LogonUserW>
    else
      LogonUser equ <LogonUserA>
    endif
    @DefProto DllImport, LogonUserExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :DWORD, :DWORD, :PHANDLE, :ptr PSID, :ptr PVOID, :LPDWORD, :PQUOTA_LIMITS>, 40
    @DefProto DllImport, LogonUserExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :PHANDLE, :ptr PSID, :ptr PVOID, :LPDWORD, :PQUOTA_LIMITS>, 40
    ifdef UNICODE
      LogonUserEx equ <LogonUserExW>
    else
      LogonUserEx equ <LogonUserExA>
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0500h)
      LOGON_WITH_PROFILE equ 00000001h
      LOGON_NETCREDENTIALS_ONLY equ 00000002h
      LOGON_ZERO_PASSWORD_BUFFER equ 80000000h
      @DefProto DllImport, CreateProcessWithLogonW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :LPCWSTR, :LPWSTR, :DWORD, :LPVOID, :LPCWSTR, :LPSTARTUPINFOW, :LPPROCESS_INFORMATION>, 44
      @DefProto DllImport, CreateProcessWithTokenW, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPCWSTR, :LPWSTR, :DWORD, :LPVOID, :LPCWSTR, :LPSTARTUPINFOW, :LPPROCESS_INFORMATION>, 36
    endif
    @DefProto DllImport, IsTokenUntrusted, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, RegisterWaitForSingleObject, WIN_STD_CALL_CONV,, <:PHANDLE, :HANDLE, :WAITORTIMERCALLBACK, :PVOID, :ULONG, :ULONG>, 24
      @DefProto DllImport, UnregisterWait, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, BindIoCompletionCallback, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED_COMPLETION_ROUTINE, :ULONG>, 12
      @DefProto DllImport, SetTimerQueueTimer, WIN_STD_CALL_CONV,, <:HANDLE, :WAITORTIMERCALLBACK, :PVOID, :DWORD, :DWORD, :BOOL>, 24
      @DefProto DllImport, CancelTimerQueueTimer, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    if (_WIN32_WINNT ge 0500h)
      if (_WIN32_WINNT ge 0600h)
        if  not Defined(MIDL_PASS)
          InitializeThreadpoolEnvironment proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON
          SetThreadpoolCallbackPool proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON, :PTP_POOL
          SetThreadpoolCallbackCleanupGroup proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON, :PTP_CLEANUP_GROUP, :PTP_CLEANUP_GROUP_CANCEL_CALLBACK
          SetThreadpoolCallbackRunsLong proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON
          SetThreadpoolCallbackLibrary proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON, :PVOID
          if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
            SetThreadpoolCallbackPriority proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON, :TP_CALLBACK_PRIORITY
          endif
          DestroyThreadpoolEnvironment proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON
        endif
      endif
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if  not Defined(MIDL_PASS)
        SetThreadpoolCallbackPersistent proto WIN_STD_CALL_CONV :PTP_CALLBACK_ENVIRON
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CreatePrivateNamespaceA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPVOID, :LPCSTR>, 12
      ifndef UNICODE
        CreatePrivateNamespace equ <CreatePrivateNamespaceA>
      else
        CreatePrivateNamespace equ <CreatePrivateNamespaceW>
      endif
      @DefProto DllImport, OpenPrivateNamespaceA, WIN_STD_CALL_CONV,, <:LPVOID, :LPCSTR>, 8
      ifndef UNICODE
        OpenPrivateNamespace equ <OpenPrivateNamespaceA>
      else
        OpenPrivateNamespace equ <OpenPrivateNamespaceW>
      endif
      @DefProto DllImport, CreateBoundaryDescriptorA, WIN_STD_CALL_CONV,, <:LPCSTR, :ULONG>, 8
      ifndef UNICODE
        CreateBoundaryDescriptor equ <CreateBoundaryDescriptorA>
      else
        CreateBoundaryDescriptor equ <CreateBoundaryDescriptorW>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, AddIntegrityLabelToBoundaryDescriptor, WIN_STD_CALL_CONV,, <:ptr HANDLE, :PSID>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0400h)
      HW_PROFILE_GUIDLEN equ 39
      MAX_PROFILE_LEN equ 80
      DOCKINFO_UNDOCKED equ (1h)
      DOCKINFO_DOCKED equ (2h)
      DOCKINFO_USER_SUPPLIED equ (4h)
      DOCKINFO_USER_UNDOCKED equ <(DOCKINFO_USER_SUPPLIED or DOCKINFO_UNDOCKED)>
      DOCKINFO_USER_DOCKED equ <(DOCKINFO_USER_SUPPLIED or DOCKINFO_DOCKED)>
      HW_PROFILE_INFOA struct
        dwDockInfo DWORD ?
        szHwProfileGuid CHAR HW_PROFILE_GUIDLEN dup (?)
        szHwProfileName CHAR MAX_PROFILE_LEN dup (?)
      HW_PROFILE_INFOA ends
      tagHW_PROFILE_INFOA typedef HW_PROFILE_INFOA
      LPHW_PROFILE_INFOA typedef ptr HW_PROFILE_INFOA
      HW_PROFILE_INFOW struct
        dwDockInfo DWORD ?
        szHwProfileGuid WCHAR HW_PROFILE_GUIDLEN dup (?)
        szHwProfileName WCHAR MAX_PROFILE_LEN dup (?)
      HW_PROFILE_INFOW ends
      tagHW_PROFILE_INFOW typedef HW_PROFILE_INFOW
      LPHW_PROFILE_INFOW typedef ptr HW_PROFILE_INFOW
      ifdef UNICODE
        HW_PROFILE_INFO typedef HW_PROFILE_INFOW
        LPHW_PROFILE_INFO typedef LPHW_PROFILE_INFOW
      else
        HW_PROFILE_INFO typedef HW_PROFILE_INFOA
        LPHW_PROFILE_INFO typedef LPHW_PROFILE_INFOA
      endif
      @DefProto DllImport, GetCurrentHwProfileA, WIN_STD_CALL_CONV,, <:LPHW_PROFILE_INFOA>, 4
      @DefProto DllImport, GetCurrentHwProfileW, WIN_STD_CALL_CONV,, <:LPHW_PROFILE_INFOW>, 4
      ifdef UNICODE
        GetCurrentHwProfile equ <GetCurrentHwProfileW>
      else
        GetCurrentHwProfile equ <GetCurrentHwProfileA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, VerifyVersionInfoA, WIN_STD_CALL_CONV,, <:LPOSVERSIONINFOEXA, :DWORD, :DWORDLONG>, 12
    @DefProto DllImport, VerifyVersionInfoW, WIN_STD_CALL_CONV,, <:LPOSVERSIONINFOEXW, :DWORD, :DWORDLONG>, 12
    ifdef UNICODE
      VerifyVersionInfo equ <VerifyVersionInfoW>
    else
      VerifyVersionInfo equ <VerifyVersionInfoA>
    endif
  endif
  include winerror.inc
  include timezoneapi.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    TC_NORMAL equ 0
    TC_HARDERR equ 1
    TC_GP_TRAP equ 2
    TC_SIGNAL equ 3
    if (WINVER ge 0400h)
      @DefProto DllImport, SetSystemPowerState, WIN_STD_CALL_CONV,, <:BOOL, :BOOL>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
    if (WINVER ge 0400h)
      AC_LINE_OFFLINE equ 00h
      AC_LINE_ONLINE equ 01h
      AC_LINE_BACKUP_POWER equ 02h
      AC_LINE_UNKNOWN equ 0FFh
      BATTERY_FLAG_HIGH equ 01h
      BATTERY_FLAG_LOW equ 02h
      BATTERY_FLAG_CRITICAL equ 04h
      BATTERY_FLAG_CHARGING equ 08h
      BATTERY_FLAG_NO_BATTERY equ 80h
      BATTERY_FLAG_UNKNOWN equ 0FFh
      BATTERY_PERCENTAGE_UNKNOWN equ 0FFh
      SYSTEM_STATUS_FLAG_POWER_SAVING_ON equ 01h
      BATTERY_LIFE_UNKNOWN equ 0FFFFFFFFh
      SYSTEM_POWER_STATUS struct
        ACLineStatus BYTE ?
        BatteryFlag BYTE ?
        BatteryLifePercent BYTE ?
        SystemStatusFlag BYTE ?
        BatteryLifeTime DWORD ?
        BatteryFullLifeTime DWORD ?
      SYSTEM_POWER_STATUS ends
      _SYSTEM_POWER_STATUS typedef SYSTEM_POWER_STATUS
      LPSYSTEM_POWER_STATUS typedef ptr SYSTEM_POWER_STATUS
      @DefProto DllImport, GetSystemPowerStatus, WIN_STD_CALL_CONV,, <:LPSYSTEM_POWER_STATUS>, 4
    endif
  endif
  if (_WIN32_WINNT ge 0500h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, MapUserPhysicalPagesScatter, WIN_STD_CALL_CONV,, <:ptr PVOID, :ULONG_PTR, :PULONG_PTR>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, CreateJobObjectA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCSTR>, 8
      ifdef UNICODE
        CreateJobObject equ <CreateJobObjectW>
      else
        CreateJobObject equ <CreateJobObjectA>
      endif
      @DefProto DllImport, OpenJobObjectA, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCSTR>, 12
      ifdef UNICODE
        OpenJobObject equ <OpenJobObjectW>
      else
        OpenJobObject equ <OpenJobObjectA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, CreateJobSet, WIN_STD_CALL_CONV,, <:ULONG, :PJOB_SET_ARRAY, :ULONG>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, FindFirstVolumeA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      ifndef UNICODE
        FindFirstVolume equ <FindFirstVolumeA>
      endif
      @DefProto DllImport, FindNextVolumeA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSTR, :DWORD>, 12
      ifndef UNICODE
        FindNextVolume equ <FindNextVolumeA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, FindFirstVolumeMountPointA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
      @DefProto DllImport, FindFirstVolumeMountPointW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
      ifdef UNICODE
        FindFirstVolumeMountPoint equ <FindFirstVolumeMountPointW>
      else
        FindFirstVolumeMountPoint equ <FindFirstVolumeMountPointA>
      endif
      @DefProto DllImport, FindNextVolumeMountPointA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSTR, :DWORD>, 12
      @DefProto DllImport, FindNextVolumeMountPointW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :DWORD>, 12
      ifdef UNICODE
        FindNextVolumeMountPoint equ <FindNextVolumeMountPointW>
      else
        FindNextVolumeMountPoint equ <FindNextVolumeMountPointA>
      endif
      @DefProto DllImport, FindVolumeMountPointClose, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, SetVolumeMountPointA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
      @DefProto DllImport, SetVolumeMountPointW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
      ifdef UNICODE
        SetVolumeMountPoint equ <SetVolumeMountPointW>
      else
        SetVolumeMountPoint equ <SetVolumeMountPointA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, DeleteVolumeMountPointA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      ifndef UNICODE
        DeleteVolumeMountPoint equ <DeleteVolumeMountPointA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ifndef UNICODE
        GetVolumeNameForVolumeMountPoint equ <GetVolumeNameForVolumeMountPointA>
      endif
      @DefProto DllImport, GetVolumeNameForVolumeMountPointA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetVolumePathNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
      ifndef UNICODE
        GetVolumePathName equ <GetVolumePathNameA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, GetVolumePathNamesForVolumeNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCH, :DWORD, :PDWORD>, 16
      ifndef UNICODE
        GetVolumePathNamesForVolumeName equ <GetVolumePathNamesForVolumeNameA>
      endif
    endif
    if (_WIN32_WINNT ge 0500h) or (_WIN32_FUSION ge 0100h) or ISOLATION_AWARE_ENABLED
      ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID equ (00000001h)
      ACTCTX_FLAG_LANGID_VALID equ (00000002h)
      ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID equ (00000004h)
      ACTCTX_FLAG_RESOURCE_NAME_VALID equ (00000008h)
      ACTCTX_FLAG_SET_PROCESS_DEFAULT equ (00000010h)
      ACTCTX_FLAG_APPLICATION_NAME_VALID equ (00000020h)
      ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF equ (00000040h)
      ACTCTX_FLAG_HMODULE_VALID equ (00000080h)
      ACTCTXA struct
        cbSize ULONG ?
        dwFlags DWORD ?
        lpSource LPCSTR ?
        wProcessorArchitecture USHORT ?
        wLangId LANGID ?
        lpAssemblyDirectory LPCSTR ?
        lpResourceName LPCSTR ?
        lpApplicationName LPCSTR ?
        hModule HMODULE ?
      ACTCTXA ends
      tagACTCTXA typedef ACTCTXA
      PACTCTXA typedef ptr ACTCTXA
      ACTCTXW struct
        cbSize ULONG ?
        dwFlags DWORD ?
        lpSource LPCWSTR ?
        wProcessorArchitecture USHORT ?
        wLangId LANGID ?
        lpAssemblyDirectory LPCWSTR ?
        lpResourceName LPCWSTR ?
        lpApplicationName LPCWSTR ?
        hModule HMODULE ?
      ACTCTXW ends
      tagACTCTXW typedef ACTCTXW
      PACTCTXW typedef ptr ACTCTXW
      ifdef UNICODE
        ACTCTX typedef ACTCTXW
        PACTCTX typedef PACTCTXW
      else
        ACTCTX typedef ACTCTXA
        PACTCTX typedef PACTCTXA
      endif
      PCACTCTXA typedef ptr ACTCTXA
      PCACTCTXW typedef ptr ACTCTXW
      ifdef UNICODE
        PCACTCTX typedef PCACTCTXW
      else
        PCACTCTX typedef PCACTCTXA
      endif
      @DefProto DllImport, CreateActCtxA, WIN_STD_CALL_CONV,, <:PCACTCTXA>, 4
      @DefProto DllImport, CreateActCtxW, WIN_STD_CALL_CONV,, <:PCACTCTXW>, 4
      ifdef UNICODE
        CreateActCtx equ <CreateActCtxW>
      else
        CreateActCtx equ <CreateActCtxA>
      endif
      @DefProto DllImport, AddRefActCtx, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, ReleaseActCtx, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, ZombifyActCtx, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, ActivateActCtx, WIN_STD_CALL_CONV,, <:HANDLE, :ptr ULONG_PTR>, 8
      DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION equ (00000001h)
      @DefProto DllImport, DeactivateActCtx, WIN_STD_CALL_CONV,, <:DWORD, :ULONG_PTR>, 8
      @DefProto DllImport, GetCurrentActCtx, WIN_STD_CALL_CONV,, <:ptr HANDLE>, 4
      ACTCTX_SECTION_KEYED_DATA_2600 struct
        cbSize ULONG ?
        ulDataFormatVersion ULONG ?
        lpData PVOID ?
        ulLength ULONG ?
        lpSectionGlobalData PVOID ?
        ulSectionGlobalDataLength ULONG ?
        lpSectionBase PVOID ?
        ulSectionTotalLength ULONG ?
        hActCtx HANDLE ?
        ulAssemblyRosterIndex ULONG ?
      ACTCTX_SECTION_KEYED_DATA_2600 ends
      tagACTCTX_SECTION_KEYED_DATA_2600 typedef ACTCTX_SECTION_KEYED_DATA_2600
      PACTCTX_SECTION_KEYED_DATA_2600 typedef ptr ACTCTX_SECTION_KEYED_DATA_2600
      PCACTCTX_SECTION_KEYED_DATA_2600 typedef ptr ACTCTX_SECTION_KEYED_DATA_2600
      ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA struct
        lpInformation PVOID ?
        lpSectionBase PVOID ?
        ulSectionLength ULONG ?
        lpSectionGlobalDataBase PVOID ?
        ulSectionGlobalDataLength ULONG ?
      ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA ends
      tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA typedef ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA
      PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA typedef ptr ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA
      PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA typedef ptr ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA
      ACTCTX_SECTION_KEYED_DATA struct
        cbSize ULONG ?
        ulDataFormatVersion ULONG ?
        lpData PVOID ?
        ulLength ULONG ?
        lpSectionGlobalData PVOID ?
        ulSectionGlobalDataLength ULONG ?
        lpSectionBase PVOID ?
        ulSectionTotalLength ULONG ?
        hActCtx HANDLE ?
        ulAssemblyRosterIndex ULONG ?
        ulFlags ULONG ?
        AssemblyMetadata ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA <>
      ACTCTX_SECTION_KEYED_DATA ends
      tagACTCTX_SECTION_KEYED_DATA typedef ACTCTX_SECTION_KEYED_DATA
      PACTCTX_SECTION_KEYED_DATA typedef ptr ACTCTX_SECTION_KEYED_DATA
      PCACTCTX_SECTION_KEYED_DATA typedef ptr ACTCTX_SECTION_KEYED_DATA
      FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX equ (00000001h)
      FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS equ (00000002h)
      FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA equ (00000004h)
      @DefProto DllImport, FindActCtxSectionStringA, WIN_STD_CALL_CONV,, <:DWORD, :ptr GUID, :ULONG, :LPCSTR, :PACTCTX_SECTION_KEYED_DATA>, 20
      @DefProto DllImport, FindActCtxSectionStringW, WIN_STD_CALL_CONV,, <:DWORD, :ptr GUID, :ULONG, :LPCWSTR, :PACTCTX_SECTION_KEYED_DATA>, 20
      ifdef UNICODE
        FindActCtxSectionString equ <FindActCtxSectionStringW>
      else
        FindActCtxSectionString equ <FindActCtxSectionStringA>
      endif
      @DefProto DllImport, FindActCtxSectionGuid, WIN_STD_CALL_CONV,, <:DWORD, :ptr GUID, :ULONG, :ptr GUID, :PACTCTX_SECTION_KEYED_DATA>, 20
      if  not Defined(RC_INVOKED)
        if  not Defined(ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED)
          ACTIVATION_CONTEXT_BASIC_INFORMATION struct
            hActCtx HANDLE ?
            dwFlags DWORD ?
          ACTIVATION_CONTEXT_BASIC_INFORMATION ends
          _ACTIVATION_CONTEXT_BASIC_INFORMATION typedef ACTIVATION_CONTEXT_BASIC_INFORMATION
          PACTIVATION_CONTEXT_BASIC_INFORMATION typedef ptr ACTIVATION_CONTEXT_BASIC_INFORMATION
          PCACTIVATION_CONTEXT_BASIC_INFORMATION typedef ptr _ACTIVATION_CONTEXT_BASIC_INFORMATION
          ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED equ 1
        endif
      endif
      QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX equ (00000004h)
      QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE equ (00000008h)
      QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS equ (00000010h)
      QUERY_ACTCTX_FLAG_NO_ADDREF equ (80000000h)
      @DefProto DllImport, QueryActCtxW, WIN_STD_CALL_CONV,, <:DWORD, :HANDLE, :PVOID, :ULONG, :PVOID, :SIZE_T, :ptr SIZE_T>, 28
      TYPE_PQUERYACTCTXW_FUNC typedef proto WIN_STD_CALL_CONV :DWORD, :HANDLE, :PVOID, :ULONG, :PVOID, :SIZE_T, :ptr SIZE_T
      PQUERYACTCTXW_FUNC typedef ptr TYPE_PQUERYACTCTXW_FUNC

    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0501h
      @DefProto DllImport, WTSGetActiveConsoleSessionId, WIN_STD_CALL_CONV,, <>, 0
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      @DefProto DllImport, WTSGetServiceSessionId, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, WTSIsServerContainer, WIN_STD_CALL_CONV,, <>, 0
    endif
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetActiveProcessorGroupCount, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetMaximumProcessorGroupCount, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetActiveProcessorCount, WIN_STD_CALL_CONV,, <:WORD>, 4
      @DefProto DllImport, GetMaximumProcessorCount, WIN_STD_CALL_CONV,, <:WORD>, 4
    endif
    @DefProto DllImport, GetNumaProcessorNode, WIN_STD_CALL_CONV,, <:UCHAR, :PUCHAR>, 8
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaNodeNumberFromHandle, WIN_STD_CALL_CONV,, <:HANDLE, :PUSHORT>, 8
    endif
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaProcessorNodeEx, WIN_STD_CALL_CONV,, <:PPROCESSOR_NUMBER, :PUSHORT>, 8
    endif
    @DefProto DllImport, GetNumaNodeProcessorMask, WIN_STD_CALL_CONV,, <:UCHAR, :PULONGLONG>, 8
    @DefProto DllImport, GetNumaAvailableMemoryNode, WIN_STD_CALL_CONV,, <:UCHAR, :PULONGLONG>, 8
    if _WIN32_WINNT ge 0601h
      @DefProto DllImport, GetNumaAvailableMemoryNodeEx, WIN_STD_CALL_CONV,, <:USHORT, :PULONGLONG>, 8
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetNumaProximityNode, WIN_STD_CALL_CONV,, <:ULONG, :PUCHAR>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    TYPE_APPLICATION_RECOVERY_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID
    APPLICATION_RECOVERY_CALLBACK typedef ptr TYPE_APPLICATION_RECOVERY_CALLBACK

    RESTART_MAX_CMD_LINE equ 1024
    RESTART_NO_CRASH equ 1
    RESTART_NO_HANG equ 2
    RESTART_NO_PATCH equ 4
    RESTART_NO_REBOOT equ 8
    RECOVERY_DEFAULT_PING_INTERVAL equ 5000
    RECOVERY_MAX_PING_INTERVAL equ (5 * 60 * 1000)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, RegisterApplicationRecoveryCallback, WIN_STD_CALL_CONV,, <:APPLICATION_RECOVERY_CALLBACK, :PVOID, :DWORD, :DWORD>, 16
      @DefProto DllImport, UnregisterApplicationRecoveryCallback, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, RegisterApplicationRestart, WIN_STD_CALL_CONV,, <:PCWSTR, :DWORD>, 8
      @DefProto DllImport, UnregisterApplicationRestart, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetApplicationRecoveryCallback, WIN_STD_CALL_CONV,, <:HANDLE, :ptr APPLICATION_RECOVERY_CALLBACK, :ptr PVOID, :PDWORD, :PDWORD>, 20
      @DefProto DllImport, GetApplicationRestartSettings, WIN_STD_CALL_CONV,, <:HANDLE, :PWSTR, :PDWORD, :PDWORD>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, ApplicationRecoveryInProgress, WIN_STD_CALL_CONV,, <:PBOOL>, 4
      @DefProto DllImport, ApplicationRecoveryFinished, WIN_STD_CALL_CONV,, <:BOOL>, 4
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      FILE_BASIC_INFO struct
        CreationTime LARGE_INTEGER <>
        LastAccessTime LARGE_INTEGER <>
        LastWriteTime LARGE_INTEGER <>
        ChangeTime LARGE_INTEGER <>
        FileAttributes DWORD ?
      FILE_BASIC_INFO ends
      _FILE_BASIC_INFO typedef FILE_BASIC_INFO
      PFILE_BASIC_INFO typedef ptr FILE_BASIC_INFO
      FILE_STANDARD_INFO struct
        AllocationSize LARGE_INTEGER <>
        EndOfFile LARGE_INTEGER <>
        NumberOfLinks DWORD ?
        DeletePending BOOLEAN ?
        Directory BOOLEAN ?
      FILE_STANDARD_INFO ends
      _FILE_STANDARD_INFO typedef FILE_STANDARD_INFO
      PFILE_STANDARD_INFO typedef ptr FILE_STANDARD_INFO
      FILE_NAME_INFO struct
        FileNameLength DWORD ?
        FileName WCHAR 1 dup (?)
      FILE_NAME_INFO ends
      _FILE_NAME_INFO typedef FILE_NAME_INFO
      PFILE_NAME_INFO typedef ptr FILE_NAME_INFO
      FILE_CASE_SENSITIVE_INFO struct
        Flags ULONG ?
      FILE_CASE_SENSITIVE_INFO ends
      _FILE_CASE_SENSITIVE_INFO typedef FILE_CASE_SENSITIVE_INFO
      PFILE_CASE_SENSITIVE_INFO typedef ptr FILE_CASE_SENSITIVE_INFO
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
        FILE_RENAME_FLAG_REPLACE_IF_EXISTS equ 00000001h
        FILE_RENAME_FLAG_POSIX_SEMANTICS equ 00000002h
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS3)
        FILE_RENAME_FLAG_SUPPRESS_PIN_STATE_INHERITANCE equ 00000004h
      endif
      FILE_RENAME_INFO struct
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
          union
            ReplaceIfExists BOOLEAN ?
            Flags DWORD ?
          ends
        else
          ReplaceIfExists BOOLEAN ?
        endif
        RootDirectory HANDLE ?
        FileNameLength DWORD ?
        FileName WCHAR 1 dup (?)
      FILE_RENAME_INFO ends
      _FILE_RENAME_INFO typedef FILE_RENAME_INFO
      PFILE_RENAME_INFO typedef ptr FILE_RENAME_INFO
      FILE_ALLOCATION_INFO struct
        AllocationSize LARGE_INTEGER <>
      FILE_ALLOCATION_INFO ends
      _FILE_ALLOCATION_INFO typedef FILE_ALLOCATION_INFO
      PFILE_ALLOCATION_INFO typedef ptr FILE_ALLOCATION_INFO
      FILE_END_OF_FILE_INFO struct
        EndOfFile LARGE_INTEGER <>
      FILE_END_OF_FILE_INFO ends
      _FILE_END_OF_FILE_INFO typedef FILE_END_OF_FILE_INFO
      PFILE_END_OF_FILE_INFO typedef ptr FILE_END_OF_FILE_INFO
      FILE_STREAM_INFO struct
        NextEntryOffset DWORD ?
        StreamNameLength DWORD ?
        StreamSize LARGE_INTEGER <>
        StreamAllocationSize LARGE_INTEGER <>
        StreamName WCHAR 1 dup (?)
      FILE_STREAM_INFO ends
      _FILE_STREAM_INFO typedef FILE_STREAM_INFO
      PFILE_STREAM_INFO typedef ptr FILE_STREAM_INFO
      FILE_COMPRESSION_INFO struct
        CompressedFileSize LARGE_INTEGER <>
        CompressionFormat WORD ?
        CompressionUnitShift UCHAR ?
        ChunkShift UCHAR ?
        ClusterShift UCHAR ?
        Reserved UCHAR 3 dup (?)
      FILE_COMPRESSION_INFO ends
      _FILE_COMPRESSION_INFO typedef FILE_COMPRESSION_INFO
      PFILE_COMPRESSION_INFO typedef ptr FILE_COMPRESSION_INFO
      FILE_ATTRIBUTE_TAG_INFO struct
        FileAttributes DWORD ?
        ReparseTag DWORD ?
      FILE_ATTRIBUTE_TAG_INFO ends
      _FILE_ATTRIBUTE_TAG_INFO typedef FILE_ATTRIBUTE_TAG_INFO
      PFILE_ATTRIBUTE_TAG_INFO typedef ptr FILE_ATTRIBUTE_TAG_INFO
      FILE_DISPOSITION_INFO struct
        DeleteFile BOOLEAN ?
      FILE_DISPOSITION_INFO ends
      _FILE_DISPOSITION_INFO typedef FILE_DISPOSITION_INFO
      PFILE_DISPOSITION_INFO typedef ptr FILE_DISPOSITION_INFO
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
        FILE_DISPOSITION_FLAG_DO_NOT_DELETE equ 00000000h
        FILE_DISPOSITION_FLAG_DELETE equ 00000001h
        FILE_DISPOSITION_FLAG_POSIX_SEMANTICS equ 00000002h
        FILE_DISPOSITION_FLAG_FORCE_IMAGE_SECTION_CHECK equ 00000004h
        FILE_DISPOSITION_FLAG_ON_CLOSE equ 00000008h
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
          FILE_DISPOSITION_FLAG_IGNORE_READONLY_ATTRIBUTE equ 00000010h
        endif
        FILE_DISPOSITION_INFO_EX struct
          Flags DWORD ?
        FILE_DISPOSITION_INFO_EX ends
        _FILE_DISPOSITION_INFO_EX typedef FILE_DISPOSITION_INFO_EX
        PFILE_DISPOSITION_INFO_EX typedef ptr FILE_DISPOSITION_INFO_EX
      endif
      FILE_ID_BOTH_DIR_INFO struct
        NextEntryOffset DWORD ?
        FileIndex DWORD ?
        CreationTime LARGE_INTEGER <>
        LastAccessTime LARGE_INTEGER <>
        LastWriteTime LARGE_INTEGER <>
        ChangeTime LARGE_INTEGER <>
        EndOfFile LARGE_INTEGER <>
        AllocationSize LARGE_INTEGER <>
        FileAttributes DWORD ?
        FileNameLength DWORD ?
        EaSize DWORD ?
        ShortNameLength CCHAR ?
        ShortName WCHAR 12 dup (?)
        FileId LARGE_INTEGER <>
        FileName WCHAR 1 dup (?)
      FILE_ID_BOTH_DIR_INFO ends
      _FILE_ID_BOTH_DIR_INFO typedef FILE_ID_BOTH_DIR_INFO
      PFILE_ID_BOTH_DIR_INFO typedef ptr FILE_ID_BOTH_DIR_INFO
      FILE_FULL_DIR_INFO struct
        NextEntryOffset ULONG ?
        FileIndex ULONG ?
        CreationTime LARGE_INTEGER <>
        LastAccessTime LARGE_INTEGER <>
        LastWriteTime LARGE_INTEGER <>
        ChangeTime LARGE_INTEGER <>
        EndOfFile LARGE_INTEGER <>
        AllocationSize LARGE_INTEGER <>
        FileAttributes ULONG ?
        FileNameLength ULONG ?
        EaSize ULONG ?
        FileName WCHAR 1 dup (?)
      FILE_FULL_DIR_INFO ends
      _FILE_FULL_DIR_INFO typedef FILE_FULL_DIR_INFO
      PFILE_FULL_DIR_INFO typedef ptr FILE_FULL_DIR_INFO
      PRIORITY_HINT typedef SDWORD
      IoPriorityHintVeryLow equ 0
      IoPriorityHintLow equ 1
      IoPriorityHintNormal equ 2
      MaximumIoPriorityHintType equ 3
      _PRIORITY_HINT typedef PRIORITY_HINT

      FILE_IO_PRIORITY_HINT_INFO struct
        PriorityHint PRIORITY_HINT ?
      FILE_IO_PRIORITY_HINT_INFO ends
      _FILE_IO_PRIORITY_HINT_INFO typedef FILE_IO_PRIORITY_HINT_INFO
      PFILE_IO_PRIORITY_HINT_INFO typedef ptr FILE_IO_PRIORITY_HINT_INFO
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        FILE_ALIGNMENT_INFO struct
          AlignmentRequirement ULONG ?
        FILE_ALIGNMENT_INFO ends
        _FILE_ALIGNMENT_INFO typedef FILE_ALIGNMENT_INFO
        PFILE_ALIGNMENT_INFO typedef ptr FILE_ALIGNMENT_INFO
        STORAGE_INFO_FLAGS_ALIGNED_DEVICE equ 00000001h
        STORAGE_INFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE equ 00000002h
        STORAGE_INFO_OFFSET_UNKNOWN equ (0ffffffffh)
        FILE_STORAGE_INFO struct
          LogicalBytesPerSector ULONG ?
          PhysicalBytesPerSectorForAtomicity ULONG ?
          PhysicalBytesPerSectorForPerformance ULONG ?
          FileSystemEffectivePhysicalBytesPerSectorForAtomicity ULONG ?
          Flags ULONG ?
          ByteOffsetForSectorAlignment ULONG ?
          ByteOffsetForPartitionAlignment ULONG ?
        FILE_STORAGE_INFO ends
        _FILE_STORAGE_INFO typedef FILE_STORAGE_INFO
        PFILE_STORAGE_INFO typedef ptr FILE_STORAGE_INFO
        FILE_ID_INFO struct
          VolumeSerialNumber ULONGLONG ?
          FileId FILE_ID_128 <>
        FILE_ID_INFO ends
        _FILE_ID_INFO typedef FILE_ID_INFO
        PFILE_ID_INFO typedef ptr FILE_ID_INFO
        FILE_ID_EXTD_DIR_INFO struct
          NextEntryOffset ULONG ?
          FileIndex ULONG ?
          CreationTime LARGE_INTEGER <>
          LastAccessTime LARGE_INTEGER <>
          LastWriteTime LARGE_INTEGER <>
          ChangeTime LARGE_INTEGER <>
          EndOfFile LARGE_INTEGER <>
          AllocationSize LARGE_INTEGER <>
          FileAttributes ULONG ?
          FileNameLength ULONG ?
          EaSize ULONG ?
          ReparsePointTag ULONG ?
          FileId FILE_ID_128 <>
          FileName WCHAR 1 dup (?)
        FILE_ID_EXTD_DIR_INFO ends
        _FILE_ID_EXTD_DIR_INFO typedef FILE_ID_EXTD_DIR_INFO
        PFILE_ID_EXTD_DIR_INFO typedef ptr FILE_ID_EXTD_DIR_INFO
      endif
      REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK equ 00000001h
      REMOTE_PROTOCOL_INFO_FLAG_OFFLINE equ 00000002h
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE equ 00000004h
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        RPI_FLAG_SMB2_SHARECAP_TIMEWARP equ 00000002h
        RPI_FLAG_SMB2_SHARECAP_DFS equ 00000008h
        RPI_FLAG_SMB2_SHARECAP_CONTINUOUS_AVAILABILITY equ 00000010h
        RPI_FLAG_SMB2_SHARECAP_SCALEOUT equ 00000020h
        RPI_FLAG_SMB2_SHARECAP_CLUSTER equ 00000040h
      endif
      RPI_SMB2_SHAREFLAG_ENCRYPT_DATA equ 00000001h
      RPI_SMB2_SHAREFLAG_COMPRESS_DATA equ 00000002h
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        RPI_SMB2_FLAG_SERVERCAP_DFS equ 00000001h
        RPI_SMB2_FLAG_SERVERCAP_LEASING equ 00000002h
        RPI_SMB2_FLAG_SERVERCAP_LARGEMTU equ 00000004h
        RPI_SMB2_FLAG_SERVERCAP_MULTICHANNEL equ 00000008h
        RPI_SMB2_FLAG_SERVERCAP_PERSISTENT_HANDLES equ 00000010h
        RPI_SMB2_FLAG_SERVERCAP_DIRECTORY_LEASING equ 00000020h
      endif
      FILE_REMOTE_PROTOCOL_INFO struct
        StructureVersion USHORT ?
        StructureSize USHORT ?
        Protocol ULONG ?
        ProtocolMajorVersion USHORT ?
        ProtocolMinorVersion USHORT ?
        ProtocolRevision USHORT ?
        Reserved USHORT ?
        Flags ULONG ?
        struct GenericReserved
          Reserved ULONG 8 dup (?)
        ends
        if (_WIN32_WINNT lt _WIN32_WINNT_WIN8)
          struct ProtocolSpecificReserved
            Reserved ULONG 16 dup (?)
          ends
        endif
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
          union ProtocolSpecific
            struct Smb2
              struct Server
                Capabilities ULONG ?
              ends
              struct Share
                Capabilities ULONG ?
                if (NTDDI_VERSION ge NTDDI_WIN10_NI)
                  ShareFlags ULONG ?
                else
                  CachingFlags ULONG ?
                endif
              ends
            ends
            Reserved ULONG 16 dup (?)
          ends
        endif
      FILE_REMOTE_PROTOCOL_INFO ends
      _FILE_REMOTE_PROTOCOL_INFO typedef FILE_REMOTE_PROTOCOL_INFO
      PFILE_REMOTE_PROTOCOL_INFO typedef ptr FILE_REMOTE_PROTOCOL_INFO
      @DefProto DllImport, GetFileInformationByHandleEx, WIN_STD_CALL_CONV,, <:HANDLE, :FILE_INFO_BY_HANDLE_CLASS, :LPVOID, :DWORD>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      FILE_ID_TYPE typedef SDWORD
      FileIdType equ 0
      ObjectIdType equ 1
      ExtendedFileIdType equ 2
      MaximumFileIdType equ 3
      _FILE_ID_TYPE typedef FILE_ID_TYPE
      PFILE_ID_TYPE typedef ptr FILE_ID_TYPE
      FILE_ID_DESCRIPTOR struct
        dwSize DWORD ?
        Type_ FILE_ID_TYPE ?
        union
          FileId LARGE_INTEGER <>
          ObjectId GUID <>
          if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
            ExtendedFileId FILE_ID_128 <>
          endif
        ends
      FILE_ID_DESCRIPTOR ends
      LPFILE_ID_DESCRIPTOR typedef ptr FILE_ID_DESCRIPTOR
      @DefProto DllImport, OpenFileById, WIN_STD_CALL_CONV,, <:HANDLE, :LPFILE_ID_DESCRIPTOR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES, :DWORD>, 24
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      SYMBOLIC_LINK_FLAG_DIRECTORY equ (1h)
      SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE equ (2h)
      @DefProto DllImport, CreateSymbolicLinkA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD>, 12
      @DefProto DllImport, CreateSymbolicLinkW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD>, 12
      ifdef UNICODE
        CreateSymbolicLink equ <CreateSymbolicLinkW>
      else
        CreateSymbolicLink equ <CreateSymbolicLinkA>
      endif
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, QueryActCtxSettingsW, WIN_STD_CALL_CONV,, <:DWORD, :HANDLE, :PCWSTR, :PCWSTR, :PWSTR, :SIZE_T, :ptr SIZE_T>, 28
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, CreateSymbolicLinkTransactedA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD, :HANDLE>, 16
      @DefProto DllImport, CreateSymbolicLinkTransactedW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :HANDLE>, 16
      ifdef UNICODE
        CreateSymbolicLinkTransacted equ <CreateSymbolicLinkTransactedW>
      else
        CreateSymbolicLinkTransacted equ <CreateSymbolicLinkTransactedA>
      endif
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, ReplacePartitionUnit, WIN_STD_CALL_CONV,, <:PWSTR, :PWSTR, :ULONG>, 12
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, AddSecureMemoryCacheCallback, WIN_STD_CALL_CONV,, <:PSECURE_MEMORY_CACHE_CALLBACK>, 4
      @DefProto DllImport, RemoveSecureMemoryCacheCallback, WIN_STD_CALL_CONV,, <:PSECURE_MEMORY_CACHE_CALLBACK>, 4
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_WIN7SP1)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CopyContext, WIN_STD_CALL_CONV,, <:PCONTEXT, :DWORD, :PCONTEXT>, 12
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, InitializeContext, WIN_STD_CALL_CONV,, <:PVOID, :DWORD, :ptr PCONTEXT, :PDWORD>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
        @DefProto DllImport, InitializeContext2, WIN_STD_CALL_CONV,, <:PVOID, :DWORD, :ptr PCONTEXT, :PDWORD, :ULONG64>, 20
      endif
    endif
    if Defined(_AMD64_) or Defined(_X86_)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, GetEnabledXStateFeatures, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, GetXStateFeaturesMask, WIN_STD_CALL_CONV,, <:PCONTEXT, :PDWORD64>, 8
        @DefProto DllImport, LocateXStateFeature, WIN_STD_CALL_CONV,, <:PCONTEXT, :DWORD, :PDWORD>, 12
        @DefProto DllImport, SetXStateFeaturesMask, WIN_STD_CALL_CONV,, <:PCONTEXT, :DWORD64>, 8
        if (NTDDI_VERSION ge NTDDI_WIN10_FE)
          @DefProto DllImport, GetThreadEnabledXStateFeatures, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, EnableProcessOptionalXStateFeatures, WIN_STD_CALL_CONV,, <:DWORD64>, 4
        endif
      endif
    endif
  endif
  if (_WIN32_WINNT ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, EnableThreadProfiling, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD64, :ptr HANDLE>, 16
      @DefProto DllImport, DisableThreadProfiling, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, QueryThreadProfiling, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOLEAN>, 8
      @DefProto DllImport, ReadThreadProfilingData, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :PPERFORMANCE_DATA>, 12
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RaiseCustomSystemEventTrigger, WIN_STD_CALL_CONV,, <:PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG>, 4
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_MN)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    endif
  endif
  if  not Defined(RC_INVOKED)
    if Defined(ISOLATION_AWARE_ENABLED) and (ISOLATION_AWARE_ENABLED ne 0)
      ;[...]
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(_MSC_VER)
    if _MSC_VER ge 1200
    else
    endif
  endif
endif
if  not Defined(RC_INVOKED)
  if  not Defined(NOWINBASEINTERLOCK)
    if  not Defined(_NTOS_)
      if  not Defined(RC_INVOKED)
        if  not Defined(MICROSOFT_WINDOWS_WINBASE_INTERLOCKED_CPLUSPLUS_H_INCLUDED)
          ;[...]
        endif
      endif
    endif
  endif
endif
