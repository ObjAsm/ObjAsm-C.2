;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winspool.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:13:16

ifndef _WINSPOOL_
  _WINSPOOL_ equ <>
  include winapifamily.inc
  ifdef _WINUSER_
    include prsht.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    PRINTER_INFO_1A struct
      Flags DWORD ?
      pDescription LPSTR ?
      pName LPSTR ?
      pComment LPSTR ?
    PRINTER_INFO_1A ends
    _PRINTER_INFO_1A typedef PRINTER_INFO_1A
    PPRINTER_INFO_1A typedef ptr PRINTER_INFO_1A
    LPPRINTER_INFO_1A typedef ptr PRINTER_INFO_1A
    PRINTER_INFO_1W struct
      Flags DWORD ?
      pDescription LPWSTR ?
      pName LPWSTR ?
      pComment LPWSTR ?
    PRINTER_INFO_1W ends
    _PRINTER_INFO_1W typedef PRINTER_INFO_1W
    PPRINTER_INFO_1W typedef ptr PRINTER_INFO_1W
    LPPRINTER_INFO_1W typedef ptr PRINTER_INFO_1W
    ifdef UNICODE
      PRINTER_INFO_1 typedef PRINTER_INFO_1W
      PPRINTER_INFO_1 typedef PPRINTER_INFO_1W
      LPPRINTER_INFO_1 typedef LPPRINTER_INFO_1W
    else
      PRINTER_INFO_1 typedef PRINTER_INFO_1A
      PPRINTER_INFO_1 typedef PPRINTER_INFO_1A
      LPPRINTER_INFO_1 typedef LPPRINTER_INFO_1A
    endif
    PRINTER_INFO_2A struct
      pServerName LPSTR ?
      pPrinterName LPSTR ?
      pShareName LPSTR ?
      pPortName LPSTR ?
      pDriverName LPSTR ?
      pComment LPSTR ?
      pLocation LPSTR ?
      pDevMode LPDEVMODEA ?
      pSepFile LPSTR ?
      pPrintProcessor LPSTR ?
      pDatatype LPSTR ?
      pParameters LPSTR ?
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
      Attributes DWORD ?
      Priority DWORD ?
      DefaultPriority DWORD ?
      StartTime DWORD ?
      UntilTime DWORD ?
      Status DWORD ?
      cJobs DWORD ?
      AveragePPM DWORD ?
    PRINTER_INFO_2A ends
    _PRINTER_INFO_2A typedef PRINTER_INFO_2A
    PPRINTER_INFO_2A typedef ptr PRINTER_INFO_2A
    LPPRINTER_INFO_2A typedef ptr PRINTER_INFO_2A
    PRINTER_INFO_2W struct
      pServerName LPWSTR ?
      pPrinterName LPWSTR ?
      pShareName LPWSTR ?
      pPortName LPWSTR ?
      pDriverName LPWSTR ?
      pComment LPWSTR ?
      pLocation LPWSTR ?
      pDevMode LPDEVMODEW ?
      pSepFile LPWSTR ?
      pPrintProcessor LPWSTR ?
      pDatatype LPWSTR ?
      pParameters LPWSTR ?
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
      Attributes DWORD ?
      Priority DWORD ?
      DefaultPriority DWORD ?
      StartTime DWORD ?
      UntilTime DWORD ?
      Status DWORD ?
      cJobs DWORD ?
      AveragePPM DWORD ?
    PRINTER_INFO_2W ends
    _PRINTER_INFO_2W typedef PRINTER_INFO_2W
    PPRINTER_INFO_2W typedef ptr PRINTER_INFO_2W
    LPPRINTER_INFO_2W typedef ptr PRINTER_INFO_2W
    ifdef UNICODE
      PRINTER_INFO_2 typedef PRINTER_INFO_2W
      PPRINTER_INFO_2 typedef PPRINTER_INFO_2W
      LPPRINTER_INFO_2 typedef LPPRINTER_INFO_2W
    else
      PRINTER_INFO_2 typedef PRINTER_INFO_2A
      PPRINTER_INFO_2 typedef PPRINTER_INFO_2A
      LPPRINTER_INFO_2 typedef LPPRINTER_INFO_2A
    endif
    PRINTER_INFO_3 struct
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
    PRINTER_INFO_3 ends
    _PRINTER_INFO_3 typedef PRINTER_INFO_3
    PPRINTER_INFO_3 typedef ptr PRINTER_INFO_3
    LPPRINTER_INFO_3 typedef ptr PRINTER_INFO_3
    PRINTER_INFO_4A struct
      pPrinterName LPSTR ?
      pServerName LPSTR ?
      Attributes DWORD ?
    PRINTER_INFO_4A ends
    _PRINTER_INFO_4A typedef PRINTER_INFO_4A
    PPRINTER_INFO_4A typedef ptr PRINTER_INFO_4A
    LPPRINTER_INFO_4A typedef ptr PRINTER_INFO_4A
    PRINTER_INFO_4W struct
      pPrinterName LPWSTR ?
      pServerName LPWSTR ?
      Attributes DWORD ?
    PRINTER_INFO_4W ends
    _PRINTER_INFO_4W typedef PRINTER_INFO_4W
    PPRINTER_INFO_4W typedef ptr PRINTER_INFO_4W
    LPPRINTER_INFO_4W typedef ptr PRINTER_INFO_4W
    ifdef UNICODE
      PRINTER_INFO_4 typedef PRINTER_INFO_4W
      PPRINTER_INFO_4 typedef PPRINTER_INFO_4W
      LPPRINTER_INFO_4 typedef LPPRINTER_INFO_4W
    else
      PRINTER_INFO_4 typedef PRINTER_INFO_4A
      PPRINTER_INFO_4 typedef PPRINTER_INFO_4A
      LPPRINTER_INFO_4 typedef LPPRINTER_INFO_4A
    endif
    PRINTER_INFO_5A struct
      pPrinterName LPSTR ?
      pPortName LPSTR ?
      Attributes DWORD ?
      DeviceNotSelectedTimeout DWORD ?
      TransmissionRetryTimeout DWORD ?
    PRINTER_INFO_5A ends
    _PRINTER_INFO_5A typedef PRINTER_INFO_5A
    PPRINTER_INFO_5A typedef ptr PRINTER_INFO_5A
    LPPRINTER_INFO_5A typedef ptr PRINTER_INFO_5A
    PRINTER_INFO_5W struct
      pPrinterName LPWSTR ?
      pPortName LPWSTR ?
      Attributes DWORD ?
      DeviceNotSelectedTimeout DWORD ?
      TransmissionRetryTimeout DWORD ?
    PRINTER_INFO_5W ends
    _PRINTER_INFO_5W typedef PRINTER_INFO_5W
    PPRINTER_INFO_5W typedef ptr PRINTER_INFO_5W
    LPPRINTER_INFO_5W typedef ptr PRINTER_INFO_5W
    ifdef UNICODE
      PRINTER_INFO_5 typedef PRINTER_INFO_5W
      PPRINTER_INFO_5 typedef PPRINTER_INFO_5W
      LPPRINTER_INFO_5 typedef LPPRINTER_INFO_5W
    else
      PRINTER_INFO_5 typedef PRINTER_INFO_5A
      PPRINTER_INFO_5 typedef PPRINTER_INFO_5A
      LPPRINTER_INFO_5 typedef LPPRINTER_INFO_5A
    endif
    PRINTER_INFO_6 struct
      dwStatus DWORD ?
    PRINTER_INFO_6 ends
    _PRINTER_INFO_6 typedef PRINTER_INFO_6
    PPRINTER_INFO_6 typedef ptr PRINTER_INFO_6
    LPPRINTER_INFO_6 typedef ptr PRINTER_INFO_6
    PRINTER_INFO_7A struct
      pszObjectGUID LPSTR ?
      dwAction DWORD ?
    PRINTER_INFO_7A ends
    _PRINTER_INFO_7A typedef PRINTER_INFO_7A
    PPRINTER_INFO_7A typedef ptr PRINTER_INFO_7A
    LPPRINTER_INFO_7A typedef ptr PRINTER_INFO_7A
    PRINTER_INFO_7W struct
      pszObjectGUID LPWSTR ?
      dwAction DWORD ?
    PRINTER_INFO_7W ends
    _PRINTER_INFO_7W typedef PRINTER_INFO_7W
    PPRINTER_INFO_7W typedef ptr PRINTER_INFO_7W
    LPPRINTER_INFO_7W typedef ptr PRINTER_INFO_7W
    ifdef UNICODE
      PRINTER_INFO_7 typedef PRINTER_INFO_7W
      PPRINTER_INFO_7 typedef PPRINTER_INFO_7W
      LPPRINTER_INFO_7 typedef LPPRINTER_INFO_7W
    else
      PRINTER_INFO_7 typedef PRINTER_INFO_7A
      PPRINTER_INFO_7 typedef PPRINTER_INFO_7A
      LPPRINTER_INFO_7 typedef LPPRINTER_INFO_7A
    endif
    DSPRINT_PUBLISH equ 00000001h
    DSPRINT_UPDATE equ 00000002h
    DSPRINT_UNPUBLISH equ 00000004h
    DSPRINT_REPUBLISH equ 00000008h
    DSPRINT_PENDING equ 80000000h
    PRINTER_INFO_8A struct
      pDevMode LPDEVMODEA ?
    PRINTER_INFO_8A ends
    _PRINTER_INFO_8A typedef PRINTER_INFO_8A
    PPRINTER_INFO_8A typedef ptr PRINTER_INFO_8A
    LPPRINTER_INFO_8A typedef ptr PRINTER_INFO_8A
    PRINTER_INFO_8W struct
      pDevMode LPDEVMODEW ?
    PRINTER_INFO_8W ends
    _PRINTER_INFO_8W typedef PRINTER_INFO_8W
    PPRINTER_INFO_8W typedef ptr PRINTER_INFO_8W
    LPPRINTER_INFO_8W typedef ptr PRINTER_INFO_8W
    ifdef UNICODE
      PRINTER_INFO_8 typedef PRINTER_INFO_8W
      PPRINTER_INFO_8 typedef PPRINTER_INFO_8W
      LPPRINTER_INFO_8 typedef LPPRINTER_INFO_8W
    else
      PRINTER_INFO_8 typedef PRINTER_INFO_8A
      PPRINTER_INFO_8 typedef PPRINTER_INFO_8A
      LPPRINTER_INFO_8 typedef LPPRINTER_INFO_8A
    endif
    PRINTER_INFO_9A struct
      pDevMode LPDEVMODEA ?
    PRINTER_INFO_9A ends
    _PRINTER_INFO_9A typedef PRINTER_INFO_9A
    PPRINTER_INFO_9A typedef ptr PRINTER_INFO_9A
    LPPRINTER_INFO_9A typedef ptr PRINTER_INFO_9A
    PRINTER_INFO_9W struct
      pDevMode LPDEVMODEW ?
    PRINTER_INFO_9W ends
    _PRINTER_INFO_9W typedef PRINTER_INFO_9W
    PPRINTER_INFO_9W typedef ptr PRINTER_INFO_9W
    LPPRINTER_INFO_9W typedef ptr PRINTER_INFO_9W
    ifdef UNICODE
      PRINTER_INFO_9 typedef PRINTER_INFO_9W
      PPRINTER_INFO_9 typedef PPRINTER_INFO_9W
      LPPRINTER_INFO_9 typedef LPPRINTER_INFO_9W
    else
      PRINTER_INFO_9 typedef PRINTER_INFO_9A
      PPRINTER_INFO_9 typedef PPRINTER_INFO_9A
      LPPRINTER_INFO_9 typedef LPPRINTER_INFO_9A
    endif
    PRINTER_CONTROL_PAUSE equ 1
    PRINTER_CONTROL_RESUME equ 2
    PRINTER_CONTROL_PURGE equ 3
    PRINTER_CONTROL_SET_STATUS equ 4
    PRINTER_STATUS_PAUSED equ 00000001h
    PRINTER_STATUS_ERROR equ 00000002h
    PRINTER_STATUS_PENDING_DELETION equ 00000004h
    PRINTER_STATUS_PAPER_JAM equ 00000008h
    PRINTER_STATUS_PAPER_OUT equ 00000010h
    PRINTER_STATUS_MANUAL_FEED equ 00000020h
    PRINTER_STATUS_PAPER_PROBLEM equ 00000040h
    PRINTER_STATUS_OFFLINE equ 00000080h
    PRINTER_STATUS_IO_ACTIVE equ 00000100h
    PRINTER_STATUS_BUSY equ 00000200h
    PRINTER_STATUS_PRINTING equ 00000400h
    PRINTER_STATUS_OUTPUT_BIN_FULL equ 00000800h
    PRINTER_STATUS_NOT_AVAILABLE equ 00001000h
    PRINTER_STATUS_WAITING equ 00002000h
    PRINTER_STATUS_PROCESSING equ 00004000h
    PRINTER_STATUS_INITIALIZING equ 00008000h
    PRINTER_STATUS_WARMING_UP equ 00010000h
    PRINTER_STATUS_TONER_LOW equ 00020000h
    PRINTER_STATUS_NO_TONER equ 00040000h
    PRINTER_STATUS_PAGE_PUNT equ 00080000h
    PRINTER_STATUS_USER_INTERVENTION equ 00100000h
    PRINTER_STATUS_OUT_OF_MEMORY equ 00200000h
    PRINTER_STATUS_DOOR_OPEN equ 00400000h
    PRINTER_STATUS_SERVER_UNKNOWN equ 00800000h
    PRINTER_STATUS_POWER_SAVE equ 01000000h
    PRINTER_STATUS_SERVER_OFFLINE equ 02000000h
    PRINTER_STATUS_DRIVER_UPDATE_NEEDED equ 04000000h
    PRINTER_ATTRIBUTE_QUEUED equ 00000001h
    PRINTER_ATTRIBUTE_DIRECT equ 00000002h
    PRINTER_ATTRIBUTE_DEFAULT equ 00000004h
    PRINTER_ATTRIBUTE_SHARED equ 00000008h
    PRINTER_ATTRIBUTE_NETWORK equ 00000010h
    PRINTER_ATTRIBUTE_HIDDEN equ 00000020h
    PRINTER_ATTRIBUTE_LOCAL equ 00000040h
    PRINTER_ATTRIBUTE_ENABLE_DEVQ equ 00000080h
    PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS equ 00000100h
    PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST equ 00000200h
    PRINTER_ATTRIBUTE_WORK_OFFLINE equ 00000400h
    PRINTER_ATTRIBUTE_ENABLE_BIDI equ 00000800h
    PRINTER_ATTRIBUTE_RAW_ONLY equ 00001000h
    PRINTER_ATTRIBUTE_PUBLISHED equ 00002000h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      PRINTER_ATTRIBUTE_FAX equ 00004000h
    endif
    if ((NTDDI_VERSION ge NTDDI_WS03) or ((OSVER(NTDDI_VERSION) eq NTDDI_WIN2K) and (SPVER(NTDDI_VERSION) ge 4)))
      PRINTER_ATTRIBUTE_TS equ 00008000h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PRINTER_ATTRIBUTE_PUSHED_USER equ 00020000h
      PRINTER_ATTRIBUTE_PUSHED_MACHINE equ 00040000h
      PRINTER_ATTRIBUTE_MACHINE equ 00080000h
      PRINTER_ATTRIBUTE_FRIENDLY_NAME equ 00100000h
      PRINTER_ATTRIBUTE_TS_GENERIC_DRIVER equ 00200000h
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      PRINTER_ATTRIBUTE_PER_USER equ 00400000h
      PRINTER_ATTRIBUTE_ENTERPRISE_CLOUD equ 00800000h
    endif
    NO_PRIORITY equ 0
    MAX_PRIORITY equ 99
    MIN_PRIORITY equ 1
    DEF_PRIORITY equ 1
    JOB_INFO_1A struct
      JobId DWORD ?
      pPrinterName LPSTR ?
      pMachineName LPSTR ?
      pUserName LPSTR ?
      pDocument LPSTR ?
      pDatatype LPSTR ?
      pStatus LPSTR ?
      Status DWORD ?
      Priority DWORD ?
      Position DWORD ?
      TotalPages DWORD ?
      PagesPrinted DWORD ?
      Submitted SYSTEMTIME <>
    JOB_INFO_1A ends
    _JOB_INFO_1A typedef JOB_INFO_1A
    PJOB_INFO_1A typedef ptr JOB_INFO_1A
    LPJOB_INFO_1A typedef ptr JOB_INFO_1A
    JOB_INFO_1W struct
      JobId DWORD ?
      pPrinterName LPWSTR ?
      pMachineName LPWSTR ?
      pUserName LPWSTR ?
      pDocument LPWSTR ?
      pDatatype LPWSTR ?
      pStatus LPWSTR ?
      Status DWORD ?
      Priority DWORD ?
      Position DWORD ?
      TotalPages DWORD ?
      PagesPrinted DWORD ?
      Submitted SYSTEMTIME <>
    JOB_INFO_1W ends
    _JOB_INFO_1W typedef JOB_INFO_1W
    PJOB_INFO_1W typedef ptr JOB_INFO_1W
    LPJOB_INFO_1W typedef ptr JOB_INFO_1W
    ifdef UNICODE
      JOB_INFO_1 typedef JOB_INFO_1W
      PJOB_INFO_1 typedef PJOB_INFO_1W
      LPJOB_INFO_1 typedef LPJOB_INFO_1W
    else
      JOB_INFO_1 typedef JOB_INFO_1A
      PJOB_INFO_1 typedef PJOB_INFO_1A
      LPJOB_INFO_1 typedef LPJOB_INFO_1A
    endif
    JOB_INFO_2A struct
      JobId DWORD ?
      pPrinterName LPSTR ?
      pMachineName LPSTR ?
      pUserName LPSTR ?
      pDocument LPSTR ?
      pNotifyName LPSTR ?
      pDatatype LPSTR ?
      pPrintProcessor LPSTR ?
      pParameters LPSTR ?
      pDriverName LPSTR ?
      pDevMode LPDEVMODEA ?
      pStatus LPSTR ?
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
      Status DWORD ?
      Priority DWORD ?
      Position DWORD ?
      StartTime DWORD ?
      UntilTime DWORD ?
      TotalPages DWORD ?
      Size_ DWORD ?
      Submitted SYSTEMTIME <>
      Time DWORD ?
      PagesPrinted DWORD ?
    JOB_INFO_2A ends
    _JOB_INFO_2A typedef JOB_INFO_2A
    PJOB_INFO_2A typedef ptr JOB_INFO_2A
    LPJOB_INFO_2A typedef ptr JOB_INFO_2A
    JOB_INFO_2W struct
      JobId DWORD ?
      pPrinterName LPWSTR ?
      pMachineName LPWSTR ?
      pUserName LPWSTR ?
      pDocument LPWSTR ?
      pNotifyName LPWSTR ?
      pDatatype LPWSTR ?
      pPrintProcessor LPWSTR ?
      pParameters LPWSTR ?
      pDriverName LPWSTR ?
      pDevMode LPDEVMODEW ?
      pStatus LPWSTR ?
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
      Status DWORD ?
      Priority DWORD ?
      Position DWORD ?
      StartTime DWORD ?
      UntilTime DWORD ?
      TotalPages DWORD ?
      Size_ DWORD ?
      Submitted SYSTEMTIME <>
      Time DWORD ?
      PagesPrinted DWORD ?
    JOB_INFO_2W ends
    _JOB_INFO_2W typedef JOB_INFO_2W
    PJOB_INFO_2W typedef ptr JOB_INFO_2W
    LPJOB_INFO_2W typedef ptr JOB_INFO_2W
    ifdef UNICODE
      JOB_INFO_2 typedef JOB_INFO_2W
      PJOB_INFO_2 typedef PJOB_INFO_2W
      LPJOB_INFO_2 typedef LPJOB_INFO_2W
    else
      JOB_INFO_2 typedef JOB_INFO_2A
      PJOB_INFO_2 typedef PJOB_INFO_2A
      LPJOB_INFO_2 typedef LPJOB_INFO_2A
    endif
    JOB_INFO_3 struct
      JobId DWORD ?
      NextJobId DWORD ?
      Reserved DWORD ?
    JOB_INFO_3 ends
    _JOB_INFO_3 typedef JOB_INFO_3
    PJOB_INFO_3 typedef ptr JOB_INFO_3
    LPJOB_INFO_3 typedef ptr JOB_INFO_3
    JOB_INFO_4A struct
      JobId DWORD ?
      pPrinterName LPSTR ?
      pMachineName LPSTR ?
      pUserName LPSTR ?
      pDocument LPSTR ?
      pNotifyName LPSTR ?
      pDatatype LPSTR ?
      pPrintProcessor LPSTR ?
      pParameters LPSTR ?
      pDriverName LPSTR ?
      pDevMode LPDEVMODEA ?
      pStatus LPSTR ?
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
      Status DWORD ?
      Priority DWORD ?
      Position DWORD ?
      StartTime DWORD ?
      UntilTime DWORD ?
      TotalPages DWORD ?
      Size_ DWORD ?
      Submitted SYSTEMTIME <>
      Time DWORD ?
      PagesPrinted DWORD ?
      SizeHigh LONG ?
    JOB_INFO_4A ends
    _JOB_INFO_4A typedef JOB_INFO_4A
    PJOB_INFO_4A typedef ptr JOB_INFO_4A
    LPJOB_INFO_4A typedef ptr JOB_INFO_4A
    JOB_INFO_4W struct
      JobId DWORD ?
      pPrinterName LPWSTR ?
      pMachineName LPWSTR ?
      pUserName LPWSTR ?
      pDocument LPWSTR ?
      pNotifyName LPWSTR ?
      pDatatype LPWSTR ?
      pPrintProcessor LPWSTR ?
      pParameters LPWSTR ?
      pDriverName LPWSTR ?
      pDevMode LPDEVMODEW ?
      pStatus LPWSTR ?
      pSecurityDescriptor PSECURITY_DESCRIPTOR ?
      Status DWORD ?
      Priority DWORD ?
      Position DWORD ?
      StartTime DWORD ?
      UntilTime DWORD ?
      TotalPages DWORD ?
      Size_ DWORD ?
      Submitted SYSTEMTIME <>
      Time DWORD ?
      PagesPrinted DWORD ?
      SizeHigh LONG ?
    JOB_INFO_4W ends
    _JOB_INFO_4W typedef JOB_INFO_4W
    PJOB_INFO_4W typedef ptr JOB_INFO_4W
    LPJOB_INFO_4W typedef ptr JOB_INFO_4W
    ifdef UNICODE
      JOB_INFO_4 typedef JOB_INFO_4W
      PJOB_INFO_4 typedef PJOB_INFO_4W
      LPJOB_INFO_4 typedef LPJOB_INFO_4W
    else
      JOB_INFO_4 typedef JOB_INFO_4A
      PJOB_INFO_4 typedef PJOB_INFO_4A
      LPJOB_INFO_4 typedef LPJOB_INFO_4A
    endif
    JOB_CONTROL_PAUSE equ 1
    JOB_CONTROL_RESUME equ 2
    JOB_CONTROL_CANCEL equ 3
    JOB_CONTROL_RESTART equ 4
    JOB_CONTROL_DELETE equ 5
    JOB_CONTROL_SENT_TO_PRINTER equ 6
    JOB_CONTROL_LAST_PAGE_EJECTED equ 7
    if (NTDDI_VERSION ge NTDDI_VISTA)
      JOB_CONTROL_RETAIN equ 8
      JOB_CONTROL_RELEASE equ 9
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10)
      JOB_CONTROL_SEND_TOAST equ 10
    endif
    JOB_STATUS_PAUSED equ 00000001h
    JOB_STATUS_ERROR equ 00000002h
    JOB_STATUS_DELETING equ 00000004h
    JOB_STATUS_SPOOLING equ 00000008h
    JOB_STATUS_PRINTING equ 00000010h
    JOB_STATUS_OFFLINE equ 00000020h
    JOB_STATUS_PAPEROUT equ 00000040h
    JOB_STATUS_PRINTED equ 00000080h
    JOB_STATUS_DELETED equ 00000100h
    JOB_STATUS_BLOCKED_DEVQ equ 00000200h
    JOB_STATUS_USER_INTERVENTION equ 00000400h
    JOB_STATUS_RESTART equ 00000800h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      JOB_STATUS_COMPLETE equ 00001000h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      JOB_STATUS_RETAINED equ 00002000h
      JOB_STATUS_RENDERING_LOCALLY equ 00004000h
    endif
    JOB_POSITION_UNSPECIFIED equ 0
    ADDJOB_INFO_1A struct
      Path LPSTR ?
      JobId DWORD ?
    ADDJOB_INFO_1A ends
    _ADDJOB_INFO_1A typedef ADDJOB_INFO_1A
    PADDJOB_INFO_1A typedef ptr ADDJOB_INFO_1A
    LPADDJOB_INFO_1A typedef ptr ADDJOB_INFO_1A
    ADDJOB_INFO_1W struct
      Path LPWSTR ?
      JobId DWORD ?
    ADDJOB_INFO_1W ends
    _ADDJOB_INFO_1W typedef ADDJOB_INFO_1W
    PADDJOB_INFO_1W typedef ptr ADDJOB_INFO_1W
    LPADDJOB_INFO_1W typedef ptr ADDJOB_INFO_1W
    ifdef UNICODE
      ADDJOB_INFO_1 typedef ADDJOB_INFO_1W
      PADDJOB_INFO_1 typedef PADDJOB_INFO_1W
      LPADDJOB_INFO_1 typedef LPADDJOB_INFO_1W
    else
      ADDJOB_INFO_1 typedef ADDJOB_INFO_1A
      PADDJOB_INFO_1 typedef PADDJOB_INFO_1A
      LPADDJOB_INFO_1 typedef LPADDJOB_INFO_1A
    endif
    DRIVER_INFO_1A struct
      pName LPSTR ?
    DRIVER_INFO_1A ends
    _DRIVER_INFO_1A typedef DRIVER_INFO_1A
    PDRIVER_INFO_1A typedef ptr DRIVER_INFO_1A
    LPDRIVER_INFO_1A typedef ptr DRIVER_INFO_1A
    DRIVER_INFO_1W struct
      pName LPWSTR ?
    DRIVER_INFO_1W ends
    _DRIVER_INFO_1W typedef DRIVER_INFO_1W
    PDRIVER_INFO_1W typedef ptr DRIVER_INFO_1W
    LPDRIVER_INFO_1W typedef ptr DRIVER_INFO_1W
    ifdef UNICODE
      DRIVER_INFO_1 typedef DRIVER_INFO_1W
      PDRIVER_INFO_1 typedef PDRIVER_INFO_1W
      LPDRIVER_INFO_1 typedef LPDRIVER_INFO_1W
    else
      DRIVER_INFO_1 typedef DRIVER_INFO_1A
      PDRIVER_INFO_1 typedef PDRIVER_INFO_1A
      LPDRIVER_INFO_1 typedef LPDRIVER_INFO_1A
    endif
    DRIVER_INFO_2A struct
      cVersion DWORD ?
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDriverPath LPSTR ?
      pDataFile LPSTR ?
      pConfigFile LPSTR ?
    DRIVER_INFO_2A ends
    _DRIVER_INFO_2A typedef DRIVER_INFO_2A
    PDRIVER_INFO_2A typedef ptr DRIVER_INFO_2A
    LPDRIVER_INFO_2A typedef ptr DRIVER_INFO_2A
    DRIVER_INFO_2W struct
      cVersion DWORD ?
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDriverPath LPWSTR ?
      pDataFile LPWSTR ?
      pConfigFile LPWSTR ?
    DRIVER_INFO_2W ends
    _DRIVER_INFO_2W typedef DRIVER_INFO_2W
    PDRIVER_INFO_2W typedef ptr DRIVER_INFO_2W
    LPDRIVER_INFO_2W typedef ptr DRIVER_INFO_2W
    ifdef UNICODE
      DRIVER_INFO_2 typedef DRIVER_INFO_2W
      PDRIVER_INFO_2 typedef PDRIVER_INFO_2W
      LPDRIVER_INFO_2 typedef LPDRIVER_INFO_2W
    else
      DRIVER_INFO_2 typedef DRIVER_INFO_2A
      PDRIVER_INFO_2 typedef PDRIVER_INFO_2A
      LPDRIVER_INFO_2 typedef LPDRIVER_INFO_2A
    endif
    DRIVER_INFO_3A struct
      cVersion DWORD ?
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDriverPath LPSTR ?
      pDataFile LPSTR ?
      pConfigFile LPSTR ?
      pHelpFile LPSTR ?
      pDependentFiles LPSTR ?
      pMonitorName LPSTR ?
      pDefaultDataType LPSTR ?
    DRIVER_INFO_3A ends
    _DRIVER_INFO_3A typedef DRIVER_INFO_3A
    PDRIVER_INFO_3A typedef ptr DRIVER_INFO_3A
    LPDRIVER_INFO_3A typedef ptr DRIVER_INFO_3A
    DRIVER_INFO_3W struct
      cVersion DWORD ?
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDriverPath LPWSTR ?
      pDataFile LPWSTR ?
      pConfigFile LPWSTR ?
      pHelpFile LPWSTR ?
      pDependentFiles LPWSTR ?
      pMonitorName LPWSTR ?
      pDefaultDataType LPWSTR ?
    DRIVER_INFO_3W ends
    _DRIVER_INFO_3W typedef DRIVER_INFO_3W
    PDRIVER_INFO_3W typedef ptr DRIVER_INFO_3W
    LPDRIVER_INFO_3W typedef ptr DRIVER_INFO_3W
    ifdef UNICODE
      DRIVER_INFO_3 typedef DRIVER_INFO_3W
      PDRIVER_INFO_3 typedef PDRIVER_INFO_3W
      LPDRIVER_INFO_3 typedef LPDRIVER_INFO_3W
    else
      DRIVER_INFO_3 typedef DRIVER_INFO_3A
      PDRIVER_INFO_3 typedef PDRIVER_INFO_3A
      LPDRIVER_INFO_3 typedef LPDRIVER_INFO_3A
    endif
    DRIVER_INFO_4A struct
      cVersion DWORD ?
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDriverPath LPSTR ?
      pDataFile LPSTR ?
      pConfigFile LPSTR ?
      pHelpFile LPSTR ?
      pDependentFiles LPSTR ?
      pMonitorName LPSTR ?
      pDefaultDataType LPSTR ?
      pszzPreviousNames LPSTR ?
    DRIVER_INFO_4A ends
    _DRIVER_INFO_4A typedef DRIVER_INFO_4A
    PDRIVER_INFO_4A typedef ptr DRIVER_INFO_4A
    LPDRIVER_INFO_4A typedef ptr DRIVER_INFO_4A
    DRIVER_INFO_4W struct
      cVersion DWORD ?
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDriverPath LPWSTR ?
      pDataFile LPWSTR ?
      pConfigFile LPWSTR ?
      pHelpFile LPWSTR ?
      pDependentFiles LPWSTR ?
      pMonitorName LPWSTR ?
      pDefaultDataType LPWSTR ?
      pszzPreviousNames LPWSTR ?
    DRIVER_INFO_4W ends
    _DRIVER_INFO_4W typedef DRIVER_INFO_4W
    PDRIVER_INFO_4W typedef ptr DRIVER_INFO_4W
    LPDRIVER_INFO_4W typedef ptr DRIVER_INFO_4W
    ifdef UNICODE
      DRIVER_INFO_4 typedef DRIVER_INFO_4W
      PDRIVER_INFO_4 typedef PDRIVER_INFO_4W
      LPDRIVER_INFO_4 typedef LPDRIVER_INFO_4W
    else
      DRIVER_INFO_4 typedef DRIVER_INFO_4A
      PDRIVER_INFO_4 typedef PDRIVER_INFO_4A
      LPDRIVER_INFO_4 typedef LPDRIVER_INFO_4A
    endif
    DRIVER_INFO_5A struct
      cVersion DWORD ?
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDriverPath LPSTR ?
      pDataFile LPSTR ?
      pConfigFile LPSTR ?
      dwDriverAttributes DWORD ?
      dwConfigVersion DWORD ?
      dwDriverVersion DWORD ?
    DRIVER_INFO_5A ends
    _DRIVER_INFO_5A typedef DRIVER_INFO_5A
    PDRIVER_INFO_5A typedef ptr DRIVER_INFO_5A
    LPDRIVER_INFO_5A typedef ptr DRIVER_INFO_5A
    DRIVER_INFO_5W struct
      cVersion DWORD ?
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDriverPath LPWSTR ?
      pDataFile LPWSTR ?
      pConfigFile LPWSTR ?
      dwDriverAttributes DWORD ?
      dwConfigVersion DWORD ?
      dwDriverVersion DWORD ?
    DRIVER_INFO_5W ends
    _DRIVER_INFO_5W typedef DRIVER_INFO_5W
    PDRIVER_INFO_5W typedef ptr DRIVER_INFO_5W
    LPDRIVER_INFO_5W typedef ptr DRIVER_INFO_5W
    ifdef UNICODE
      DRIVER_INFO_5 typedef DRIVER_INFO_5W
      PDRIVER_INFO_5 typedef PDRIVER_INFO_5W
      LPDRIVER_INFO_5 typedef LPDRIVER_INFO_5W
    else
      DRIVER_INFO_5 typedef DRIVER_INFO_5A
      PDRIVER_INFO_5 typedef PDRIVER_INFO_5A
      LPDRIVER_INFO_5 typedef LPDRIVER_INFO_5A
    endif
    DRIVER_INFO_6A struct
      cVersion DWORD ?
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDriverPath LPSTR ?
      pDataFile LPSTR ?
      pConfigFile LPSTR ?
      pHelpFile LPSTR ?
      pDependentFiles LPSTR ?
      pMonitorName LPSTR ?
      pDefaultDataType LPSTR ?
      pszzPreviousNames LPSTR ?
      ftDriverDate FILETIME <>
      dwlDriverVersion DWORDLONG ?
      pszMfgName LPSTR ?
      pszOEMUrl LPSTR ?
      pszHardwareID LPSTR ?
      pszProvider LPSTR ?
    DRIVER_INFO_6A ends
    _DRIVER_INFO_6A typedef DRIVER_INFO_6A
    PDRIVER_INFO_6A typedef ptr DRIVER_INFO_6A
    LPDRIVER_INFO_6A typedef ptr DRIVER_INFO_6A
    DRIVER_INFO_6W struct
      cVersion DWORD ?
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDriverPath LPWSTR ?
      pDataFile LPWSTR ?
      pConfigFile LPWSTR ?
      pHelpFile LPWSTR ?
      pDependentFiles LPWSTR ?
      pMonitorName LPWSTR ?
      pDefaultDataType LPWSTR ?
      pszzPreviousNames LPWSTR ?
      ftDriverDate FILETIME <>
      dwlDriverVersion DWORDLONG ?
      pszMfgName LPWSTR ?
      pszOEMUrl LPWSTR ?
      pszHardwareID LPWSTR ?
      pszProvider LPWSTR ?
    DRIVER_INFO_6W ends
    _DRIVER_INFO_6W typedef DRIVER_INFO_6W
    PDRIVER_INFO_6W typedef ptr DRIVER_INFO_6W
    LPDRIVER_INFO_6W typedef ptr DRIVER_INFO_6W
    ifdef UNICODE
      DRIVER_INFO_6 typedef DRIVER_INFO_6W
      PDRIVER_INFO_6 typedef PDRIVER_INFO_6W
      LPDRIVER_INFO_6 typedef LPDRIVER_INFO_6W
    else
      DRIVER_INFO_6 typedef DRIVER_INFO_6A
      PDRIVER_INFO_6 typedef PDRIVER_INFO_6A
      LPDRIVER_INFO_6 typedef LPDRIVER_INFO_6A
    endif
    PRINTER_DRIVER_PACKAGE_AWARE equ 00000001h
    PRINTER_DRIVER_XPS equ 00000002h
    PRINTER_DRIVER_SANDBOX_ENABLED equ 00000004h
    PRINTER_DRIVER_CLASS equ 00000008h
    PRINTER_DRIVER_DERIVED equ 00000010h
    PRINTER_DRIVER_NOT_SHAREABLE equ 00000020h
    PRINTER_DRIVER_CATEGORY_FAX equ 00000040h
    PRINTER_DRIVER_CATEGORY_FILE equ 00000080h
    PRINTER_DRIVER_CATEGORY_VIRTUAL equ 00000100h
    PRINTER_DRIVER_CATEGORY_SERVICE equ 00000200h
    PRINTER_DRIVER_SOFT_RESET_REQUIRED equ 00000400h
    PRINTER_DRIVER_SANDBOX_DISABLED equ 00000800h
    PRINTER_DRIVER_CATEGORY_3D equ 00001000h
    PRINTER_DRIVER_CATEGORY_CLOUD equ 00002000h
    DRIVER_INFO_8A struct
      cVersion DWORD ?
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDriverPath LPSTR ?
      pDataFile LPSTR ?
      pConfigFile LPSTR ?
      pHelpFile LPSTR ?
      pDependentFiles LPSTR ?
      pMonitorName LPSTR ?
      pDefaultDataType LPSTR ?
      pszzPreviousNames LPSTR ?
      ftDriverDate FILETIME <>
      dwlDriverVersion DWORDLONG ?
      pszMfgName LPSTR ?
      pszOEMUrl LPSTR ?
      pszHardwareID LPSTR ?
      pszProvider LPSTR ?
      pszPrintProcessor LPSTR ?
      pszVendorSetup LPSTR ?
      pszzColorProfiles LPSTR ?
      pszInfPath LPSTR ?
      dwPrinterDriverAttributes DWORD ?
      pszzCoreDriverDependencies LPSTR ?
      ftMinInboxDriverVerDate FILETIME <>
      dwlMinInboxDriverVerVersion DWORDLONG ?
    DRIVER_INFO_8A ends
    _DRIVER_INFO_8A typedef DRIVER_INFO_8A
    PDRIVER_INFO_8A typedef ptr DRIVER_INFO_8A
    LPDRIVER_INFO_8A typedef ptr DRIVER_INFO_8A
    DRIVER_INFO_8W struct
      cVersion DWORD ?
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDriverPath LPWSTR ?
      pDataFile LPWSTR ?
      pConfigFile LPWSTR ?
      pHelpFile LPWSTR ?
      pDependentFiles LPWSTR ?
      pMonitorName LPWSTR ?
      pDefaultDataType LPWSTR ?
      pszzPreviousNames LPWSTR ?
      ftDriverDate FILETIME <>
      dwlDriverVersion DWORDLONG ?
      pszMfgName LPWSTR ?
      pszOEMUrl LPWSTR ?
      pszHardwareID LPWSTR ?
      pszProvider LPWSTR ?
      pszPrintProcessor LPWSTR ?
      pszVendorSetup LPWSTR ?
      pszzColorProfiles LPWSTR ?
      pszInfPath LPWSTR ?
      dwPrinterDriverAttributes DWORD ?
      pszzCoreDriverDependencies LPWSTR ?
      ftMinInboxDriverVerDate FILETIME <>
      dwlMinInboxDriverVerVersion DWORDLONG ?
    DRIVER_INFO_8W ends
    _DRIVER_INFO_8W typedef DRIVER_INFO_8W
    PDRIVER_INFO_8W typedef ptr DRIVER_INFO_8W
    LPDRIVER_INFO_8W typedef ptr DRIVER_INFO_8W
    ifdef UNICODE
      DRIVER_INFO_8 typedef DRIVER_INFO_8W
      PDRIVER_INFO_8 typedef PDRIVER_INFO_8W
      LPDRIVER_INFO_8 typedef LPDRIVER_INFO_8W
    else
      DRIVER_INFO_8 typedef DRIVER_INFO_8A
      PDRIVER_INFO_8 typedef PDRIVER_INFO_8A
      LPDRIVER_INFO_8 typedef LPDRIVER_INFO_8A
    endif
    DRIVER_KERNELMODE equ 00000001h
    DRIVER_USERMODE equ 00000002h
    DPD_DELETE_UNUSED_FILES equ 00000001h
    DPD_DELETE_SPECIFIC_VERSION equ 00000002h
    DPD_DELETE_ALL_FILES equ 00000004h
    APD_STRICT_UPGRADE equ 00000001h
    APD_STRICT_DOWNGRADE equ 00000002h
    APD_COPY_ALL_FILES equ 00000004h
    APD_COPY_NEW_FILES equ 00000008h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      APD_COPY_FROM_DIRECTORY equ 00000010h
    endif
    DOC_INFO_1A struct
      pDocName LPSTR ?
      pOutputFile LPSTR ?
      pDatatype LPSTR ?
    DOC_INFO_1A ends
    _DOC_INFO_1A typedef DOC_INFO_1A
    PDOC_INFO_1A typedef ptr DOC_INFO_1A
    LPDOC_INFO_1A typedef ptr DOC_INFO_1A
    DOC_INFO_1W struct
      pDocName LPWSTR ?
      pOutputFile LPWSTR ?
      pDatatype LPWSTR ?
    DOC_INFO_1W ends
    _DOC_INFO_1W typedef DOC_INFO_1W
    PDOC_INFO_1W typedef ptr DOC_INFO_1W
    LPDOC_INFO_1W typedef ptr DOC_INFO_1W
    ifdef UNICODE
      DOC_INFO_1 typedef DOC_INFO_1W
      PDOC_INFO_1 typedef PDOC_INFO_1W
      LPDOC_INFO_1 typedef LPDOC_INFO_1W
    else
      DOC_INFO_1 typedef DOC_INFO_1A
      PDOC_INFO_1 typedef PDOC_INFO_1A
      LPDOC_INFO_1 typedef LPDOC_INFO_1A
    endif
    FORM_INFO_1A struct
      Flags DWORD ?
      pName LPSTR ?
      Size_ SIZEL <>
      ImageableArea RECTL <>
    FORM_INFO_1A ends
    _FORM_INFO_1A typedef FORM_INFO_1A
    PFORM_INFO_1A typedef ptr FORM_INFO_1A
    LPFORM_INFO_1A typedef ptr FORM_INFO_1A
    FORM_INFO_1W struct
      Flags DWORD ?
      pName LPWSTR ?
      Size_ SIZEL <>
      ImageableArea RECTL <>
    FORM_INFO_1W ends
    _FORM_INFO_1W typedef FORM_INFO_1W
    PFORM_INFO_1W typedef ptr FORM_INFO_1W
    LPFORM_INFO_1W typedef ptr FORM_INFO_1W
    ifdef UNICODE
      FORM_INFO_1 typedef FORM_INFO_1W
      PFORM_INFO_1 typedef PFORM_INFO_1W
      LPFORM_INFO_1 typedef LPFORM_INFO_1W
    else
      FORM_INFO_1 typedef FORM_INFO_1A
      PFORM_INFO_1 typedef PFORM_INFO_1A
      LPFORM_INFO_1 typedef LPFORM_INFO_1A
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      STRING_NONE equ 00000001h
      STRING_MUIDLL equ 00000002h
      STRING_LANGPAIR equ 00000004h
      MAX_FORM_KEYWORD_LENGTH equ 63 + 1
      FORM_INFO_2A struct
        Flags DWORD ?
        pName LPCSTR ?
        Size_ SIZEL <>
        ImageableArea RECTL <>
        pKeyword LPCSTR ?
        StringType DWORD ?
        pMuiDll LPCSTR ?
        dwResourceId DWORD ?
        pDisplayName LPCSTR ?
        wLangId LANGID ?
      FORM_INFO_2A ends
      _FORM_INFO_2A typedef FORM_INFO_2A
      PFORM_INFO_2A typedef ptr FORM_INFO_2A
      LPFORM_INFO_2A typedef ptr FORM_INFO_2A
      FORM_INFO_2W struct
        Flags DWORD ?
        pName LPCWSTR ?
        Size_ SIZEL <>
        ImageableArea RECTL <>
        pKeyword LPCSTR ?
        StringType DWORD ?
        pMuiDll LPCWSTR ?
        dwResourceId DWORD ?
        pDisplayName LPCWSTR ?
        wLangId LANGID ?
      FORM_INFO_2W ends
      _FORM_INFO_2W typedef FORM_INFO_2W
      PFORM_INFO_2W typedef ptr FORM_INFO_2W
      LPFORM_INFO_2W typedef ptr FORM_INFO_2W
      ifdef UNICODE
        FORM_INFO_2 typedef FORM_INFO_2W
        PFORM_INFO_2 typedef PFORM_INFO_2W
        LPFORM_INFO_2 typedef LPFORM_INFO_2W
      else
        FORM_INFO_2 typedef FORM_INFO_2A
        PFORM_INFO_2 typedef PFORM_INFO_2A
        LPFORM_INFO_2 typedef LPFORM_INFO_2A
      endif
    endif
    DOC_INFO_2A struct
      pDocName LPSTR ?
      pOutputFile LPSTR ?
      pDatatype LPSTR ?
      dwMode DWORD ?
      JobId DWORD ?
    DOC_INFO_2A ends
    _DOC_INFO_2A typedef DOC_INFO_2A
    PDOC_INFO_2A typedef ptr DOC_INFO_2A
    LPDOC_INFO_2A typedef ptr DOC_INFO_2A
    DOC_INFO_2W struct
      pDocName LPWSTR ?
      pOutputFile LPWSTR ?
      pDatatype LPWSTR ?
      dwMode DWORD ?
      JobId DWORD ?
    DOC_INFO_2W ends
    _DOC_INFO_2W typedef DOC_INFO_2W
    PDOC_INFO_2W typedef ptr DOC_INFO_2W
    LPDOC_INFO_2W typedef ptr DOC_INFO_2W
    ifdef UNICODE
      DOC_INFO_2 typedef DOC_INFO_2W
      PDOC_INFO_2 typedef PDOC_INFO_2W
      LPDOC_INFO_2 typedef LPDOC_INFO_2W
    else
      DOC_INFO_2 typedef DOC_INFO_2A
      PDOC_INFO_2 typedef PDOC_INFO_2A
      LPDOC_INFO_2 typedef LPDOC_INFO_2A
    endif
    DI_CHANNEL equ 1
    DI_READ_SPOOL_JOB equ 3
    DOC_INFO_3A struct
      pDocName LPSTR ?
      pOutputFile LPSTR ?
      pDatatype LPSTR ?
      dwFlags DWORD ?
    DOC_INFO_3A ends
    _DOC_INFO_3A typedef DOC_INFO_3A
    PDOC_INFO_3A typedef ptr DOC_INFO_3A
    LPDOC_INFO_3A typedef ptr DOC_INFO_3A
    DOC_INFO_3W struct
      pDocName LPWSTR ?
      pOutputFile LPWSTR ?
      pDatatype LPWSTR ?
      dwFlags DWORD ?
    DOC_INFO_3W ends
    _DOC_INFO_3W typedef DOC_INFO_3W
    PDOC_INFO_3W typedef ptr DOC_INFO_3W
    LPDOC_INFO_3W typedef ptr DOC_INFO_3W
    ifdef UNICODE
      DOC_INFO_3 typedef DOC_INFO_3W
      PDOC_INFO_3 typedef PDOC_INFO_3W
      LPDOC_INFO_3 typedef LPDOC_INFO_3W
    else
      DOC_INFO_3 typedef DOC_INFO_3A
      PDOC_INFO_3 typedef PDOC_INFO_3A
      LPDOC_INFO_3 typedef LPDOC_INFO_3A
    endif
    DI_MEMORYMAP_WRITE equ 00000001h
    FORM_USER equ 00000000h
    FORM_BUILTIN equ 00000001h
    FORM_PRINTER equ 00000002h
    PRINTPROCESSOR_INFO_1A struct
      pName LPSTR ?
    PRINTPROCESSOR_INFO_1A ends
    _PRINTPROCESSOR_INFO_1A typedef PRINTPROCESSOR_INFO_1A
    PPRINTPROCESSOR_INFO_1A typedef ptr PRINTPROCESSOR_INFO_1A
    LPPRINTPROCESSOR_INFO_1A typedef ptr PRINTPROCESSOR_INFO_1A
    PRINTPROCESSOR_INFO_1W struct
      pName LPWSTR ?
    PRINTPROCESSOR_INFO_1W ends
    _PRINTPROCESSOR_INFO_1W typedef PRINTPROCESSOR_INFO_1W
    PPRINTPROCESSOR_INFO_1W typedef ptr PRINTPROCESSOR_INFO_1W
    LPPRINTPROCESSOR_INFO_1W typedef ptr PRINTPROCESSOR_INFO_1W
    ifdef UNICODE
      PRINTPROCESSOR_INFO_1 typedef PRINTPROCESSOR_INFO_1W
      PPRINTPROCESSOR_INFO_1 typedef PPRINTPROCESSOR_INFO_1W
      LPPRINTPROCESSOR_INFO_1 typedef LPPRINTPROCESSOR_INFO_1W
    else
      PRINTPROCESSOR_INFO_1 typedef PRINTPROCESSOR_INFO_1A
      PPRINTPROCESSOR_INFO_1 typedef PPRINTPROCESSOR_INFO_1A
      LPPRINTPROCESSOR_INFO_1 typedef LPPRINTPROCESSOR_INFO_1A
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      PRINTPROCESSOR_CAPS_1 struct
        dwLevel DWORD ?
        dwNupOptions DWORD ?
        dwPageOrderFlags DWORD ?
        dwNumberOfCopies DWORD ?
      PRINTPROCESSOR_CAPS_1 ends
      _PRINTPROCESSOR_CAPS_1 typedef PRINTPROCESSOR_CAPS_1
      PPRINTPROCESSOR_CAPS_1 typedef ptr PRINTPROCESSOR_CAPS_1
      NORMAL_PRINT equ (00000000h)
      REVERSE_PRINT equ (00000001h)
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PRINTPROCESSOR_CAPS_2 struct
        dwLevel DWORD ?
        dwNupOptions DWORD ?
        dwPageOrderFlags DWORD ?
        dwNumberOfCopies DWORD ?
        dwDuplexHandlingCaps DWORD ?
        dwNupDirectionCaps DWORD ?
        dwNupBorderCaps DWORD ?
        dwBookletHandlingCaps DWORD ?
        dwScalingCaps DWORD ?
      PRINTPROCESSOR_CAPS_2 ends
      _PRINTPROCESSOR_CAPS_2 typedef PRINTPROCESSOR_CAPS_2
      PPRINTPROCESSOR_CAPS_2 typedef ptr PRINTPROCESSOR_CAPS_2
      PPCAPS_RIGHT_THEN_DOWN equ (00000001h)
      PPCAPS_DOWN_THEN_RIGHT equ (00000001h shl 1)
      PPCAPS_LEFT_THEN_DOWN equ (00000001h shl 2)
      PPCAPS_DOWN_THEN_LEFT equ (00000001h shl 3)
      PPCAPS_BORDER_PRINT equ (00000001h)
      PPCAPS_BOOKLET_EDGE equ (00000001h)
      PPCAPS_REVERSE_PAGES_FOR_REVERSE_DUPLEX equ (00000001h)
      PPCAPS_DONT_SEND_EXTRA_PAGES_FOR_DUPLEX equ (00000001h shl 1)
      PPCAPS_SQUARE_SCALING equ (00000001h)
    endif
    PORT_INFO_1A struct
      pName LPSTR ?
    PORT_INFO_1A ends
    _PORT_INFO_1A typedef PORT_INFO_1A
    PPORT_INFO_1A typedef ptr PORT_INFO_1A
    LPPORT_INFO_1A typedef ptr PORT_INFO_1A
    PORT_INFO_1W struct
      pName LPWSTR ?
    PORT_INFO_1W ends
    _PORT_INFO_1W typedef PORT_INFO_1W
    PPORT_INFO_1W typedef ptr PORT_INFO_1W
    LPPORT_INFO_1W typedef ptr PORT_INFO_1W
    ifdef UNICODE
      PORT_INFO_1 typedef PORT_INFO_1W
      PPORT_INFO_1 typedef PPORT_INFO_1W
      LPPORT_INFO_1 typedef LPPORT_INFO_1W
    else
      PORT_INFO_1 typedef PORT_INFO_1A
      PPORT_INFO_1 typedef PPORT_INFO_1A
      LPPORT_INFO_1 typedef LPPORT_INFO_1A
    endif
    PORT_INFO_2A struct
      pPortName LPSTR ?
      pMonitorName LPSTR ?
      pDescription LPSTR ?
      fPortType DWORD ?
      Reserved DWORD ?
    PORT_INFO_2A ends
    _PORT_INFO_2A typedef PORT_INFO_2A
    PPORT_INFO_2A typedef ptr PORT_INFO_2A
    LPPORT_INFO_2A typedef ptr PORT_INFO_2A
    PORT_INFO_2W struct
      pPortName LPWSTR ?
      pMonitorName LPWSTR ?
      pDescription LPWSTR ?
      fPortType DWORD ?
      Reserved DWORD ?
    PORT_INFO_2W ends
    _PORT_INFO_2W typedef PORT_INFO_2W
    PPORT_INFO_2W typedef ptr PORT_INFO_2W
    LPPORT_INFO_2W typedef ptr PORT_INFO_2W
    ifdef UNICODE
      PORT_INFO_2 typedef PORT_INFO_2W
      PPORT_INFO_2 typedef PPORT_INFO_2W
      LPPORT_INFO_2 typedef LPPORT_INFO_2W
    else
      PORT_INFO_2 typedef PORT_INFO_2A
      PPORT_INFO_2 typedef PPORT_INFO_2A
      LPPORT_INFO_2 typedef LPPORT_INFO_2A
    endif
    PORT_TYPE_WRITE equ 0001h
    PORT_TYPE_READ equ 0002h
    PORT_TYPE_REDIRECTED equ 0004h
    PORT_TYPE_NET_ATTACHED equ 0008h
    PORT_INFO_3A struct
      dwStatus DWORD ?
      pszStatus LPSTR ?
      dwSeverity DWORD ?
    PORT_INFO_3A ends
    _PORT_INFO_3A typedef PORT_INFO_3A
    PPORT_INFO_3A typedef ptr PORT_INFO_3A
    LPPORT_INFO_3A typedef ptr PORT_INFO_3A
    PORT_INFO_3W struct
      dwStatus DWORD ?
      pszStatus LPWSTR ?
      dwSeverity DWORD ?
    PORT_INFO_3W ends
    _PORT_INFO_3W typedef PORT_INFO_3W
    PPORT_INFO_3W typedef ptr PORT_INFO_3W
    LPPORT_INFO_3W typedef ptr PORT_INFO_3W
    ifdef UNICODE
      PORT_INFO_3 typedef PORT_INFO_3W
      PPORT_INFO_3 typedef PPORT_INFO_3W
      LPPORT_INFO_3 typedef LPPORT_INFO_3W
    else
      PORT_INFO_3 typedef PORT_INFO_3A
      PPORT_INFO_3 typedef PPORT_INFO_3A
      LPPORT_INFO_3 typedef LPPORT_INFO_3A
    endif
    PORT_STATUS_TYPE_ERROR equ 1
    PORT_STATUS_TYPE_WARNING equ 2
    PORT_STATUS_TYPE_INFO equ 3
    PORT_STATUS_OFFLINE equ 1
    PORT_STATUS_PAPER_JAM equ 2
    PORT_STATUS_PAPER_OUT equ 3
    PORT_STATUS_OUTPUT_BIN_FULL equ 4
    PORT_STATUS_PAPER_PROBLEM equ 5
    PORT_STATUS_NO_TONER equ 6
    PORT_STATUS_DOOR_OPEN equ 7
    PORT_STATUS_USER_INTERVENTION equ 8
    PORT_STATUS_OUT_OF_MEMORY equ 9
    PORT_STATUS_TONER_LOW equ 10
    PORT_STATUS_WARMING_UP equ 11
    PORT_STATUS_POWER_SAVE equ 12
    MONITOR_INFO_1A struct
      pName LPSTR ?
    MONITOR_INFO_1A ends
    _MONITOR_INFO_1A typedef MONITOR_INFO_1A
    PMONITOR_INFO_1A typedef ptr MONITOR_INFO_1A
    LPMONITOR_INFO_1A typedef ptr MONITOR_INFO_1A
    MONITOR_INFO_1W struct
      pName LPWSTR ?
    MONITOR_INFO_1W ends
    _MONITOR_INFO_1W typedef MONITOR_INFO_1W
    PMONITOR_INFO_1W typedef ptr MONITOR_INFO_1W
    LPMONITOR_INFO_1W typedef ptr MONITOR_INFO_1W
    ifdef UNICODE
      MONITOR_INFO_1 typedef MONITOR_INFO_1W
      PMONITOR_INFO_1 typedef PMONITOR_INFO_1W
      LPMONITOR_INFO_1 typedef LPMONITOR_INFO_1W
    else
      MONITOR_INFO_1 typedef MONITOR_INFO_1A
      PMONITOR_INFO_1 typedef PMONITOR_INFO_1A
      LPMONITOR_INFO_1 typedef LPMONITOR_INFO_1A
    endif
    MONITOR_INFO_2A struct
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDLLName LPSTR ?
    MONITOR_INFO_2A ends
    _MONITOR_INFO_2A typedef MONITOR_INFO_2A
    PMONITOR_INFO_2A typedef ptr MONITOR_INFO_2A
    LPMONITOR_INFO_2A typedef ptr MONITOR_INFO_2A
    MONITOR_INFO_2W struct
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDLLName LPWSTR ?
    MONITOR_INFO_2W ends
    _MONITOR_INFO_2W typedef MONITOR_INFO_2W
    PMONITOR_INFO_2W typedef ptr MONITOR_INFO_2W
    LPMONITOR_INFO_2W typedef ptr MONITOR_INFO_2W
    ifdef UNICODE
      MONITOR_INFO_2 typedef MONITOR_INFO_2W
      PMONITOR_INFO_2 typedef PMONITOR_INFO_2W
      LPMONITOR_INFO_2 typedef LPMONITOR_INFO_2W
    else
      MONITOR_INFO_2 typedef MONITOR_INFO_2A
      PMONITOR_INFO_2 typedef PMONITOR_INFO_2A
      LPMONITOR_INFO_2 typedef LPMONITOR_INFO_2A
    endif
    DATATYPES_INFO_1A struct
      pName LPSTR ?
    DATATYPES_INFO_1A ends
    _DATATYPES_INFO_1A typedef DATATYPES_INFO_1A
    PDATATYPES_INFO_1A typedef ptr DATATYPES_INFO_1A
    LPDATATYPES_INFO_1A typedef ptr DATATYPES_INFO_1A
    DATATYPES_INFO_1W struct
      pName LPWSTR ?
    DATATYPES_INFO_1W ends
    _DATATYPES_INFO_1W typedef DATATYPES_INFO_1W
    PDATATYPES_INFO_1W typedef ptr DATATYPES_INFO_1W
    LPDATATYPES_INFO_1W typedef ptr DATATYPES_INFO_1W
    ifdef UNICODE
      DATATYPES_INFO_1 typedef DATATYPES_INFO_1W
      PDATATYPES_INFO_1 typedef PDATATYPES_INFO_1W
      LPDATATYPES_INFO_1 typedef LPDATATYPES_INFO_1W
    else
      DATATYPES_INFO_1 typedef DATATYPES_INFO_1A
      PDATATYPES_INFO_1 typedef PDATATYPES_INFO_1A
      LPDATATYPES_INFO_1 typedef LPDATATYPES_INFO_1A
    endif
    PRINTER_DEFAULTSA struct
      pDatatype LPSTR ?
      pDevMode LPDEVMODEA ?
      DesiredAccess ACCESS_MASK ?
    PRINTER_DEFAULTSA ends
    _PRINTER_DEFAULTSA typedef PRINTER_DEFAULTSA
    PPRINTER_DEFAULTSA typedef ptr PRINTER_DEFAULTSA
    LPPRINTER_DEFAULTSA typedef ptr PRINTER_DEFAULTSA
    PRINTER_DEFAULTSW struct
      pDatatype LPWSTR ?
      pDevMode LPDEVMODEW ?
      DesiredAccess ACCESS_MASK ?
    PRINTER_DEFAULTSW ends
    _PRINTER_DEFAULTSW typedef PRINTER_DEFAULTSW
    PPRINTER_DEFAULTSW typedef ptr PRINTER_DEFAULTSW
    LPPRINTER_DEFAULTSW typedef ptr PRINTER_DEFAULTSW
    ifdef UNICODE
      PRINTER_DEFAULTS typedef PRINTER_DEFAULTSW
      PPRINTER_DEFAULTS typedef PPRINTER_DEFAULTSW
      LPPRINTER_DEFAULTS typedef LPPRINTER_DEFAULTSW
    else
      PRINTER_DEFAULTS typedef PRINTER_DEFAULTSA
      PPRINTER_DEFAULTS typedef PPRINTER_DEFAULTSA
      LPPRINTER_DEFAULTS typedef LPPRINTER_DEFAULTSA
    endif
    PRINTER_ENUM_VALUESA struct
      pValueName LPSTR ?
      cbValueName DWORD ?
      dwType DWORD ?
      pData LPBYTE ?
      cbData DWORD ?
    PRINTER_ENUM_VALUESA ends
    _PRINTER_ENUM_VALUESA typedef PRINTER_ENUM_VALUESA
    PPRINTER_ENUM_VALUESA typedef ptr PRINTER_ENUM_VALUESA
    LPPRINTER_ENUM_VALUESA typedef ptr PRINTER_ENUM_VALUESA
    PRINTER_ENUM_VALUESW struct
      pValueName LPWSTR ?
      cbValueName DWORD ?
      dwType DWORD ?
      pData LPBYTE ?
      cbData DWORD ?
    PRINTER_ENUM_VALUESW ends
    _PRINTER_ENUM_VALUESW typedef PRINTER_ENUM_VALUESW
    PPRINTER_ENUM_VALUESW typedef ptr PRINTER_ENUM_VALUESW
    LPPRINTER_ENUM_VALUESW typedef ptr PRINTER_ENUM_VALUESW
    ifdef UNICODE
      PRINTER_ENUM_VALUES typedef PRINTER_ENUM_VALUESW
      PPRINTER_ENUM_VALUES typedef PPRINTER_ENUM_VALUESW
      LPPRINTER_ENUM_VALUES typedef LPPRINTER_ENUM_VALUESW
    else
      PRINTER_ENUM_VALUES typedef PRINTER_ENUM_VALUESA
      PPRINTER_ENUM_VALUES typedef PPRINTER_ENUM_VALUESA
      LPPRINTER_ENUM_VALUES typedef LPPRINTER_ENUM_VALUESA
    endif
    EnumPrintersA proto WIN_STD_CALL_CONV :DWORD, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumPrintersW proto WIN_STD_CALL_CONV :DWORD, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumPrinters equ <EnumPrintersW>
    else
      EnumPrinters equ <EnumPrintersA>
    endif
    PRINTER_ENUM_DEFAULT equ 00000001h
    PRINTER_ENUM_LOCAL equ 00000002h
    PRINTER_ENUM_CONNECTIONS equ 00000004h
    PRINTER_ENUM_FAVORITE equ 00000004h
    PRINTER_ENUM_NAME equ 00000008h
    PRINTER_ENUM_REMOTE equ 00000010h
    PRINTER_ENUM_SHARED equ 00000020h
    PRINTER_ENUM_NETWORK equ 00000040h
    PRINTER_ENUM_EXPAND equ 00004000h
    PRINTER_ENUM_CONTAINER equ 00008000h
    PRINTER_ENUM_ICONMASK equ 00ff0000h
    PRINTER_ENUM_ICON1 equ 00010000h
    PRINTER_ENUM_ICON2 equ 00020000h
    PRINTER_ENUM_ICON3 equ 00040000h
    PRINTER_ENUM_ICON4 equ 00080000h
    PRINTER_ENUM_ICON5 equ 00100000h
    PRINTER_ENUM_ICON6 equ 00200000h
    PRINTER_ENUM_ICON7 equ 00400000h
    PRINTER_ENUM_ICON8 equ 00800000h
    PRINTER_ENUM_HIDE equ 01000000h
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      PRINTER_ENUM_CATEGORY_ALL equ 02000000h
      PRINTER_ENUM_CATEGORY_3D equ 04000000h
    endif
    SPOOL_FILE_PERSISTENT equ 00000001h
    SPOOL_FILE_TEMPORARY equ 00000002h
    GetSpoolFileHandle proto WIN_STD_CALL_CONV :HANDLE
    CommitSpoolData proto WIN_STD_CALL_CONV :HANDLE, :HANDLE, :DWORD
    CloseSpoolFileHandle proto WIN_STD_CALL_CONV :HANDLE, :HANDLE
    OpenPrinterA proto WIN_STD_CALL_CONV :LPSTR, :LPHANDLE, :LPPRINTER_DEFAULTSA
    OpenPrinterW proto WIN_STD_CALL_CONV :LPWSTR, :LPHANDLE, :LPPRINTER_DEFAULTSW
    ifdef UNICODE
      OpenPrinter equ <OpenPrinterW>
    else
      OpenPrinter equ <OpenPrinterA>
    endif
    ResetPrinterA proto WIN_STD_CALL_CONV :HANDLE, :LPPRINTER_DEFAULTSA
    ResetPrinterW proto WIN_STD_CALL_CONV :HANDLE, :LPPRINTER_DEFAULTSW
    ifdef UNICODE
      ResetPrinter equ <ResetPrinterW>
    else
      ResetPrinter equ <ResetPrinterA>
    endif
    SetJobA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :LPBYTE, :DWORD
    SetJobW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :LPBYTE, :DWORD
    ifdef UNICODE
      SetJob equ <SetJobW>
    else
      SetJob equ <SetJobA>
    endif
    GetJobA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    GetJobW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetJob equ <GetJobW>
    else
      GetJob equ <GetJobA>
    endif
    EnumJobsA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumJobsW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumJobs equ <EnumJobsW>
    else
      EnumJobs equ <EnumJobsA>
    endif
    AddPrinterA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :LPBYTE
    AddPrinterW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPBYTE
    ifdef UNICODE
      AddPrinter equ <AddPrinterW>
    else
      AddPrinter equ <AddPrinterA>
    endif
    DeletePrinter proto WIN_STD_CALL_CONV :HANDLE
    SetPrinterA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD
    SetPrinterW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD
    ifdef UNICODE
      SetPrinter equ <SetPrinterW>
    else
      SetPrinter equ <SetPrinterA>
    endif
    GetPrinterA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    GetPrinterW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetPrinter equ <GetPrinterW>
    else
      GetPrinter equ <GetPrinterA>
    endif
    AddPrinterDriverA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :LPBYTE
    AddPrinterDriverW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPBYTE
    ifdef UNICODE
      AddPrinterDriver equ <AddPrinterDriverW>
    else
      AddPrinterDriver equ <AddPrinterDriverA>
    endif
    AddPrinterDriverExA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :PBYTE, :DWORD
    AddPrinterDriverExW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :PBYTE, :DWORD
    ifdef UNICODE
      AddPrinterDriverEx equ <AddPrinterDriverExW>
    else
      AddPrinterDriverEx equ <AddPrinterDriverExA>
    endif
    EnumPrinterDriversA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumPrinterDriversW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumPrinterDrivers equ <EnumPrinterDriversW>
    else
      EnumPrinterDrivers equ <EnumPrinterDriversA>
    endif
    GetPrinterDriverA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    GetPrinterDriverW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetPrinterDriver equ <GetPrinterDriverW>
    else
      GetPrinterDriver equ <GetPrinterDriverA>
    endif
    GetPrinterDriverDirectoryA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    GetPrinterDriverDirectoryW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryW>
    else
      GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryA>
    endif
    DeletePrinterDriverA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :LPSTR
    DeletePrinterDriverW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :LPWSTR
    ifdef UNICODE
      DeletePrinterDriver equ <DeletePrinterDriverW>
    else
      DeletePrinterDriver equ <DeletePrinterDriverA>
    endif
    DeletePrinterDriverExA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :LPSTR, :DWORD, :DWORD
    DeletePrinterDriverExW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :LPWSTR, :DWORD, :DWORD
    ifdef UNICODE
      DeletePrinterDriverEx equ <DeletePrinterDriverExW>
    else
      DeletePrinterDriverEx equ <DeletePrinterDriverExA>
    endif
    AddPrintProcessorA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :LPSTR, :LPSTR
    AddPrintProcessorW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :LPWSTR, :LPWSTR
    ifdef UNICODE
      AddPrintProcessor equ <AddPrintProcessorW>
    else
      AddPrintProcessor equ <AddPrintProcessorA>
    endif
    EnumPrintProcessorsA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumPrintProcessorsW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumPrintProcessors equ <EnumPrintProcessorsW>
    else
      EnumPrintProcessors equ <EnumPrintProcessorsA>
    endif
    GetPrintProcessorDirectoryA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    GetPrintProcessorDirectoryW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryW>
    else
      GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryA>
    endif
    EnumPrintProcessorDatatypesA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumPrintProcessorDatatypesW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesW>
    else
      EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesA>
    endif
    DeletePrintProcessorA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :LPSTR
    DeletePrintProcessorW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :LPWSTR
    ifdef UNICODE
      DeletePrintProcessor equ <DeletePrintProcessorW>
    else
      DeletePrintProcessor equ <DeletePrintProcessorA>
    endif
    StartDocPrinterA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE
    StartDocPrinterW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE
    ifdef UNICODE
      StartDocPrinter equ <StartDocPrinterW>
    else
      StartDocPrinter equ <StartDocPrinterA>
    endif
    StartPagePrinter proto WIN_STD_CALL_CONV :HANDLE
    WritePrinter proto WIN_STD_CALL_CONV :HANDLE, :LPVOID, :DWORD, :LPDWORD
    FlushPrinter proto WIN_STD_CALL_CONV :HANDLE, :LPVOID, :DWORD, :LPDWORD, :DWORD
    EndPagePrinter proto WIN_STD_CALL_CONV :HANDLE
    AbortPrinter proto WIN_STD_CALL_CONV :HANDLE
    ReadPrinter proto WIN_STD_CALL_CONV :HANDLE, :LPVOID, :DWORD, :LPDWORD
    EndDocPrinter proto WIN_STD_CALL_CONV :HANDLE
    AddJobA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    AddJobW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      AddJob equ <AddJobW>
    else
      AddJob equ <AddJobA>
    endif
    ScheduleJob proto WIN_STD_CALL_CONV :HANDLE, :DWORD
    PrinterProperties proto WIN_STD_CALL_CONV :HWND, :HANDLE
    DocumentPropertiesA proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPSTR, :PDEVMODEA, :PDEVMODEA, :DWORD
    DocumentPropertiesW proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPWSTR, :PDEVMODEW, :PDEVMODEW, :DWORD
    ifdef UNICODE
      DocumentProperties equ <DocumentPropertiesW>
    else
      DocumentProperties equ <DocumentPropertiesA>
    endif
    AdvancedDocumentPropertiesA proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPSTR, :PDEVMODEA, :PDEVMODEA
    AdvancedDocumentPropertiesW proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPWSTR, :PDEVMODEW, :PDEVMODEW
    ifdef UNICODE
      AdvancedDocumentProperties equ <AdvancedDocumentPropertiesW>
    else
      AdvancedDocumentProperties equ <AdvancedDocumentPropertiesA>
    endif
    if (NTDDI_VERSION ge NTDDI_WINXPSP1)
      ExtDeviceMode proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPDEVMODEA, :LPSTR, :LPSTR, :LPDEVMODEA, :LPSTR, :DWORD
    endif
    GetPrinterDataA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR, :LPDWORD, :LPBYTE, :DWORD, :LPDWORD
    GetPrinterDataW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR, :LPDWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetPrinterData equ <GetPrinterDataW>
    else
      GetPrinterData equ <GetPrinterDataA>
    endif
    GetPrinterDataExA proto WIN_STD_CALL_CONV :HANDLE, :LPCSTR, :LPCSTR, :LPDWORD, :LPBYTE, :DWORD, :LPDWORD
    GetPrinterDataExW proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR, :LPCWSTR, :LPDWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetPrinterDataEx equ <GetPrinterDataExW>
    else
      GetPrinterDataEx equ <GetPrinterDataExA>
    endif
    EnumPrinterDataA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPSTR, :DWORD, :LPDWORD, :LPDWORD, :LPBYTE, :DWORD, :LPDWORD
    EnumPrinterDataW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPWSTR, :DWORD, :LPDWORD, :LPDWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      EnumPrinterData equ <EnumPrinterDataW>
    else
      EnumPrinterData equ <EnumPrinterDataA>
    endif
    EnumPrinterDataExA proto WIN_STD_CALL_CONV :HANDLE, :LPCSTR, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumPrinterDataExW proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumPrinterDataEx equ <EnumPrinterDataExW>
    else
      EnumPrinterDataEx equ <EnumPrinterDataExA>
    endif
    EnumPrinterKeyA proto WIN_STD_CALL_CONV :HANDLE, :LPCSTR, :LPSTR, :DWORD, :LPDWORD
    EnumPrinterKeyW proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR, :LPWSTR, :DWORD, :LPDWORD
    ifdef UNICODE
      EnumPrinterKey equ <EnumPrinterKeyW>
    else
      EnumPrinterKey equ <EnumPrinterKeyA>
    endif
    SetPrinterDataA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR, :DWORD, :LPBYTE, :DWORD
    SetPrinterDataW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR, :DWORD, :LPBYTE, :DWORD
    ifdef UNICODE
      SetPrinterData equ <SetPrinterDataW>
    else
      SetPrinterData equ <SetPrinterDataA>
    endif
    SetPrinterDataExA proto WIN_STD_CALL_CONV :HANDLE, :LPCSTR, :LPCSTR, :DWORD, :LPBYTE, :DWORD
    SetPrinterDataExW proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR, :LPCWSTR, :DWORD, :LPBYTE, :DWORD
    ifdef UNICODE
      SetPrinterDataEx equ <SetPrinterDataExW>
    else
      SetPrinterDataEx equ <SetPrinterDataExA>
    endif
    DeletePrinterDataA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR
    DeletePrinterDataW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR
    ifdef UNICODE
      DeletePrinterData equ <DeletePrinterDataW>
    else
      DeletePrinterData equ <DeletePrinterDataA>
    endif
    DeletePrinterDataExA proto WIN_STD_CALL_CONV :HANDLE, :LPCSTR, :LPCSTR
    DeletePrinterDataExW proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      DeletePrinterDataEx equ <DeletePrinterDataExW>
    else
      DeletePrinterDataEx equ <DeletePrinterDataExA>
    endif
    DeletePrinterKeyA proto WIN_STD_CALL_CONV :HANDLE, :LPCSTR
    DeletePrinterKeyW proto WIN_STD_CALL_CONV :HANDLE, :LPCWSTR
    ifdef UNICODE
      DeletePrinterKey equ <DeletePrinterKeyW>
    else
      DeletePrinterKey equ <DeletePrinterKeyA>
    endif
    PRINTER_NOTIFY_TYPE equ 00h
    JOB_NOTIFY_TYPE equ 01h
    SERVER_NOTIFY_TYPE equ 02h
    PRINTER_NOTIFY_FIELD_SERVER_NAME equ 00h
    PRINTER_NOTIFY_FIELD_PRINTER_NAME equ 01h
    PRINTER_NOTIFY_FIELD_SHARE_NAME equ 02h
    PRINTER_NOTIFY_FIELD_PORT_NAME equ 03h
    PRINTER_NOTIFY_FIELD_DRIVER_NAME equ 04h
    PRINTER_NOTIFY_FIELD_COMMENT equ 05h
    PRINTER_NOTIFY_FIELD_LOCATION equ 06h
    PRINTER_NOTIFY_FIELD_DEVMODE equ 07h
    PRINTER_NOTIFY_FIELD_SEPFILE equ 08h
    PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR equ 09h
    PRINTER_NOTIFY_FIELD_PARAMETERS equ 0Ah
    PRINTER_NOTIFY_FIELD_DATATYPE equ 0Bh
    PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR equ 0Ch
    PRINTER_NOTIFY_FIELD_ATTRIBUTES equ 0Dh
    PRINTER_NOTIFY_FIELD_PRIORITY equ 0Eh
    PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY equ 0Fh
    PRINTER_NOTIFY_FIELD_START_TIME equ 10h
    PRINTER_NOTIFY_FIELD_UNTIL_TIME equ 11h
    PRINTER_NOTIFY_FIELD_STATUS equ 12h
    PRINTER_NOTIFY_FIELD_STATUS_STRING equ 13h
    PRINTER_NOTIFY_FIELD_CJOBS equ 14h
    PRINTER_NOTIFY_FIELD_AVERAGE_PPM equ 15h
    PRINTER_NOTIFY_FIELD_TOTAL_PAGES equ 16h
    PRINTER_NOTIFY_FIELD_PAGES_PRINTED equ 17h
    PRINTER_NOTIFY_FIELD_TOTAL_BYTES equ 18h
    PRINTER_NOTIFY_FIELD_BYTES_PRINTED equ 19h
    PRINTER_NOTIFY_FIELD_OBJECT_GUID equ 1Ah
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PRINTER_NOTIFY_FIELD_FRIENDLY_NAME equ 1Bh
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      PRINTER_NOTIFY_FIELD_BRANCH_OFFICE_PRINTING equ 1Ch
    endif
    JOB_NOTIFY_FIELD_PRINTER_NAME equ 00h
    JOB_NOTIFY_FIELD_MACHINE_NAME equ 01h
    JOB_NOTIFY_FIELD_PORT_NAME equ 02h
    JOB_NOTIFY_FIELD_USER_NAME equ 03h
    JOB_NOTIFY_FIELD_NOTIFY_NAME equ 04h
    JOB_NOTIFY_FIELD_DATATYPE equ 05h
    JOB_NOTIFY_FIELD_PRINT_PROCESSOR equ 06h
    JOB_NOTIFY_FIELD_PARAMETERS equ 07h
    JOB_NOTIFY_FIELD_DRIVER_NAME equ 08h
    JOB_NOTIFY_FIELD_DEVMODE equ 09h
    JOB_NOTIFY_FIELD_STATUS equ 0Ah
    JOB_NOTIFY_FIELD_STATUS_STRING equ 0Bh
    JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR equ 0Ch
    JOB_NOTIFY_FIELD_DOCUMENT equ 0Dh
    JOB_NOTIFY_FIELD_PRIORITY equ 0Eh
    JOB_NOTIFY_FIELD_POSITION equ 0Fh
    JOB_NOTIFY_FIELD_SUBMITTED equ 10h
    JOB_NOTIFY_FIELD_START_TIME equ 11h
    JOB_NOTIFY_FIELD_UNTIL_TIME equ 12h
    JOB_NOTIFY_FIELD_TIME equ 13h
    JOB_NOTIFY_FIELD_TOTAL_PAGES equ 14h
    JOB_NOTIFY_FIELD_PAGES_PRINTED equ 15h
    JOB_NOTIFY_FIELD_TOTAL_BYTES equ 16h
    JOB_NOTIFY_FIELD_BYTES_PRINTED equ 17h
    JOB_NOTIFY_FIELD_REMOTE_JOB_ID equ 18h
    if (NTDDI_VERSION ge NTDDI_WIN7)
      SERVER_NOTIFY_FIELD_PRINT_DRIVER_ISOLATION_GROUP equ 00h
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      PRINTER_NOTIFY_CATEGORY_ALL equ 001000h
      PRINTER_NOTIFY_CATEGORY_3D equ 002000h
    endif
    PRINTER_NOTIFY_OPTIONS_TYPE struct
      Type_ WORD ?
      Reserved0 WORD ?
      Reserved1 DWORD ?
      Reserved2 DWORD ?
      Count DWORD ?
      pFields PWORD ?
    PRINTER_NOTIFY_OPTIONS_TYPE ends
    _PRINTER_NOTIFY_OPTIONS_TYPE typedef PRINTER_NOTIFY_OPTIONS_TYPE
    PPRINTER_NOTIFY_OPTIONS_TYPE typedef ptr PRINTER_NOTIFY_OPTIONS_TYPE
    LPPRINTER_NOTIFY_OPTIONS_TYPE typedef ptr PRINTER_NOTIFY_OPTIONS_TYPE
    PRINTER_NOTIFY_OPTIONS_REFRESH equ 01h
    PRINTER_NOTIFY_OPTIONS struct
      Version DWORD ?
      Flags DWORD ?
      Count DWORD ?
      pTypes PPRINTER_NOTIFY_OPTIONS_TYPE ?
    PRINTER_NOTIFY_OPTIONS ends
    _PRINTER_NOTIFY_OPTIONS typedef PRINTER_NOTIFY_OPTIONS
    PPRINTER_NOTIFY_OPTIONS typedef ptr PRINTER_NOTIFY_OPTIONS
    LPPRINTER_NOTIFY_OPTIONS typedef ptr PRINTER_NOTIFY_OPTIONS
    PRINTER_NOTIFY_INFO_DISCARDED equ 01h
    PRINTER_NOTIFY_INFO_DATA struct
      Type_ WORD ?
      Field WORD ?
      Reserved DWORD ?
      Id DWORD ?
      union NotifyData
        adwData DWORD 2 dup (?)
        struct Data
          cbBuf DWORD ?
          pBuf LPVOID ?
        ends
      ends
    PRINTER_NOTIFY_INFO_DATA ends
    _PRINTER_NOTIFY_INFO_DATA typedef PRINTER_NOTIFY_INFO_DATA
    PPRINTER_NOTIFY_INFO_DATA typedef ptr PRINTER_NOTIFY_INFO_DATA
    LPPRINTER_NOTIFY_INFO_DATA typedef ptr PRINTER_NOTIFY_INFO_DATA
    PRINTER_NOTIFY_INFO struct
      Version DWORD ?
      Flags DWORD ?
      Count DWORD ?
      aData PRINTER_NOTIFY_INFO_DATA 1 dup (<>)
    PRINTER_NOTIFY_INFO ends
    _PRINTER_NOTIFY_INFO typedef PRINTER_NOTIFY_INFO
    PPRINTER_NOTIFY_INFO typedef ptr PRINTER_NOTIFY_INFO
    LPPRINTER_NOTIFY_INFO typedef ptr PRINTER_NOTIFY_INFO
    if (NTDDI_VERSION ge NTDDI_WINXP)
      BINARY_CONTAINER struct
        cbBuf DWORD ?
        pData LPBYTE ?
      BINARY_CONTAINER ends
      _BINARY_CONTAINER typedef BINARY_CONTAINER
      PBINARY_CONTAINER typedef ptr BINARY_CONTAINER
      BIDI_DATA struct
        dwBidiType DWORD ?
        union u
          bData BOOL ?
          iData LONG ?
          sData LPWSTR ?
          fData FLOAT ?
          biData BINARY_CONTAINER <>
        ends
      BIDI_DATA ends
      _BIDI_DATA typedef BIDI_DATA
      PBIDI_DATA typedef ptr BIDI_DATA
      LPBIDI_DATA typedef ptr BIDI_DATA
      BIDI_REQUEST_DATA struct
        dwReqNumber DWORD ?
        pSchema LPWSTR ?
        data BIDI_DATA <>
      BIDI_REQUEST_DATA ends
      _BIDI_REQUEST_DATA typedef BIDI_REQUEST_DATA
      PBIDI_REQUEST_DATA typedef ptr BIDI_REQUEST_DATA
      LPBIDI_REQUEST_DATA typedef ptr BIDI_REQUEST_DATA
      BIDI_REQUEST_CONTAINER struct
        Version DWORD ?
        Flags DWORD ?
        Count DWORD ?
        aData BIDI_REQUEST_DATA 1 dup (<>)
      BIDI_REQUEST_CONTAINER ends
      _BIDI_REQUEST_CONTAINER typedef BIDI_REQUEST_CONTAINER
      PBIDI_REQUEST_CONTAINER typedef ptr BIDI_REQUEST_CONTAINER
      LPBIDI_REQUEST_CONTAINER typedef ptr BIDI_REQUEST_CONTAINER
      BIDI_RESPONSE_DATA struct
        dwResult DWORD ?
        dwReqNumber DWORD ?
        pSchema LPWSTR ?
        data BIDI_DATA <>
      BIDI_RESPONSE_DATA ends
      _BIDI_RESPONSE_DATA typedef BIDI_RESPONSE_DATA
      PBIDI_RESPONSE_DATA typedef ptr BIDI_RESPONSE_DATA
      LPBIDI_RESPONSE_DATA typedef ptr BIDI_RESPONSE_DATA
      BIDI_RESPONSE_CONTAINER struct
        Version DWORD ?
        Flags DWORD ?
        Count DWORD ?
        aData BIDI_RESPONSE_DATA 1 dup (<>)
      BIDI_RESPONSE_CONTAINER ends
      _BIDI_RESPONSE_CONTAINER typedef BIDI_RESPONSE_CONTAINER
      PBIDI_RESPONSE_CONTAINER typedef ptr BIDI_RESPONSE_CONTAINER
      LPBIDI_RESPONSE_CONTAINER typedef ptr BIDI_RESPONSE_CONTAINER
      BIDI_ACTION_ENUM_SCHEMA equ <L("EnumSchema")>
      BIDI_ACTION_GET equ <L("Get")>
      BIDI_ACTION_SET equ <L("Set")>
      BIDI_ACTION_GET_ALL equ <L("GetAll")>
      BIDI_ACTION_GET_WITH_ARGUMENT equ <L("GetWithArgument")>
      BIDI_TYPE typedef SDWORD
      BIDI_NULL equ 0
      BIDI_INT equ 1
      BIDI_FLOAT equ 2
      BIDI_BOOL equ 3
      BIDI_STRING equ 4
      BIDI_TEXT equ 5
      BIDI_ENUM equ 6
      BIDI_BLOB equ 7

      BIDI_ACCESS_ADMINISTRATOR equ 1h
      BIDI_ACCESS_USER equ 2h
      ERROR_BIDI_STATUS_OK equ 0
      ERROR_BIDI_NOT_SUPPORTED equ <ERROR_NOT_SUPPORTED>
      ERROR_BIDI_ERROR_BASE equ 13000
      ERROR_BIDI_STATUS_WARNING equ (ERROR_BIDI_ERROR_BASE + 1)
      ERROR_BIDI_SCHEMA_READ_ONLY equ (ERROR_BIDI_ERROR_BASE + 2)
      ERROR_BIDI_SERVER_OFFLINE equ (ERROR_BIDI_ERROR_BASE + 3)
      ERROR_BIDI_DEVICE_OFFLINE equ (ERROR_BIDI_ERROR_BASE + 4)
      ERROR_BIDI_SCHEMA_NOT_SUPPORTED equ (ERROR_BIDI_ERROR_BASE + 5)
      ERROR_BIDI_SET_DIFFERENT_TYPE equ (ERROR_BIDI_ERROR_BASE + 6)
      ERROR_BIDI_SET_MULTIPLE_SCHEMAPATH equ (ERROR_BIDI_ERROR_BASE + 7)
      ERROR_BIDI_SET_INVALID_SCHEMAPATH equ (ERROR_BIDI_ERROR_BASE + 8)
      ERROR_BIDI_SET_UNKNOWN_FAILURE equ (ERROR_BIDI_ERROR_BASE + 9)
      ERROR_BIDI_SCHEMA_WRITE_ONLY equ (ERROR_BIDI_ERROR_BASE + 10)
      ERROR_BIDI_GET_REQUIRES_ARGUMENT equ (ERROR_BIDI_ERROR_BASE + 11)
      ERROR_BIDI_GET_ARGUMENT_NOT_SUPPORTED equ (ERROR_BIDI_ERROR_BASE + 12)
      ERROR_BIDI_GET_MISSING_ARGUMENT equ (ERROR_BIDI_ERROR_BASE + 13)
      ERROR_BIDI_DEVICE_CONFIG_UNCHANGED equ (ERROR_BIDI_ERROR_BASE + 14)
      ERROR_BIDI_NO_LOCALIZED_RESOURCES equ (ERROR_BIDI_ERROR_BASE + 15)
      ERROR_BIDI_NO_BIDI_SCHEMA_EXTENSIONS equ (ERROR_BIDI_ERROR_BASE + 16)
      ERROR_BIDI_UNSUPPORTED_CLIENT_LANGUAGE equ (ERROR_BIDI_ERROR_BASE + 17)
      ERROR_BIDI_UNSUPPORTED_RESOURCE_FORMAT equ (ERROR_BIDI_ERROR_BASE + 18)
    endif
    WaitForPrinterChange proto WIN_STD_CALL_CONV :HANDLE, :DWORD
    FindFirstPrinterChangeNotification proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :PVOID
    FindNextPrinterChangeNotification proto WIN_STD_CALL_CONV :HANDLE, :PDWORD, :LPVOID, :ptr LPVOID
    FreePrinterNotifyInfo proto WIN_STD_CALL_CONV :PPRINTER_NOTIFY_INFO
    FindClosePrinterChangeNotification proto WIN_STD_CALL_CONV :HANDLE
    PRINTER_CHANGE_ADD_PRINTER equ 00000001h
    PRINTER_CHANGE_SET_PRINTER equ 00000002h
    PRINTER_CHANGE_DELETE_PRINTER equ 00000004h
    PRINTER_CHANGE_FAILED_CONNECTION_PRINTER equ 00000008h
    PRINTER_CHANGE_PRINTER equ 000000FFh
    PRINTER_CHANGE_ADD_JOB equ 00000100h
    PRINTER_CHANGE_SET_JOB equ 00000200h
    PRINTER_CHANGE_DELETE_JOB equ 00000400h
    PRINTER_CHANGE_WRITE_JOB equ 00000800h
    PRINTER_CHANGE_JOB equ 0000FF00h
    PRINTER_CHANGE_ADD_FORM equ 00010000h
    PRINTER_CHANGE_SET_FORM equ 00020000h
    PRINTER_CHANGE_DELETE_FORM equ 00040000h
    PRINTER_CHANGE_FORM equ 00070000h
    PRINTER_CHANGE_ADD_PORT equ 00100000h
    PRINTER_CHANGE_CONFIGURE_PORT equ 00200000h
    PRINTER_CHANGE_DELETE_PORT equ 00400000h
    PRINTER_CHANGE_PORT equ 00700000h
    PRINTER_CHANGE_ADD_PRINT_PROCESSOR equ 01000000h
    PRINTER_CHANGE_DELETE_PRINT_PROCESSOR equ 04000000h
    PRINTER_CHANGE_PRINT_PROCESSOR equ 07000000h
    if (NTDDI_VERSION ge NTDDI_WIN7)
      PRINTER_CHANGE_SERVER equ 08000000h
    endif
    PRINTER_CHANGE_ADD_PRINTER_DRIVER equ 10000000h
    PRINTER_CHANGE_SET_PRINTER_DRIVER equ 20000000h
    PRINTER_CHANGE_DELETE_PRINTER_DRIVER equ 40000000h
    PRINTER_CHANGE_PRINTER_DRIVER equ 70000000h
    PRINTER_CHANGE_TIMEOUT equ 80000000h
    if (NTDDI_VERSION ge NTDDI_WIN7)
      PRINTER_CHANGE_ALL equ 7F77FFFFh
    else
      PRINTER_CHANGE_ALL equ 7777FFFFh
    endif
    PrinterMessageBoxA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :HWND, :LPSTR, :LPSTR, :DWORD
    PrinterMessageBoxW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :HWND, :LPWSTR, :LPWSTR, :DWORD
    ifdef UNICODE
      PrinterMessageBox equ <PrinterMessageBoxW>
    else
      PrinterMessageBox equ <PrinterMessageBoxA>
    endif
    PRINTER_ERROR_INFORMATION equ 80000000h
    PRINTER_ERROR_WARNING equ 40000000h
    PRINTER_ERROR_SEVERE equ 20000000h
    PRINTER_ERROR_OUTOFPAPER equ 00000001h
    PRINTER_ERROR_JAM equ 00000002h
    PRINTER_ERROR_OUTOFTONER equ 00000004h
    ClosePrinter proto WIN_STD_CALL_CONV :HANDLE
    AddFormA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE
    AddFormW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE
    ifdef UNICODE
      AddForm equ <AddFormW>
    else
      AddForm equ <AddFormA>
    endif
    DeleteFormA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR
    DeleteFormW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR
    ifdef UNICODE
      DeleteForm equ <DeleteFormW>
    else
      DeleteForm equ <DeleteFormA>
    endif
    GetFormA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    GetFormW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
    ifdef UNICODE
      GetForm equ <GetFormW>
    else
      GetForm equ <GetFormA>
    endif
    SetFormA proto WIN_STD_CALL_CONV :HANDLE, :LPSTR, :DWORD, :LPBYTE
    SetFormW proto WIN_STD_CALL_CONV :HANDLE, :LPWSTR, :DWORD, :LPBYTE
    ifdef UNICODE
      SetForm equ <SetFormW>
    else
      SetForm equ <SetFormA>
    endif
    EnumFormsA proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumFormsW proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumForms equ <EnumFormsW>
    else
      EnumForms equ <EnumFormsA>
    endif
    EnumMonitorsA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumMonitorsW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumMonitors equ <EnumMonitorsW>
    else
      EnumMonitors equ <EnumMonitorsA>
    endif
    AddMonitorA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :LPBYTE
    AddMonitorW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPBYTE
    ifdef UNICODE
      AddMonitor equ <AddMonitorW>
    else
      AddMonitor equ <AddMonitorA>
    endif
    DeleteMonitorA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :LPSTR
    DeleteMonitorW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :LPWSTR
    ifdef UNICODE
      DeleteMonitor equ <DeleteMonitorW>
    else
      DeleteMonitor equ <DeleteMonitorA>
    endif
    EnumPortsA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    EnumPortsW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD, :LPDWORD
    ifdef UNICODE
      EnumPorts equ <EnumPortsW>
    else
      EnumPorts equ <EnumPortsA>
    endif
    AddPortA proto WIN_STD_CALL_CONV :LPSTR, :HWND, :LPSTR
    AddPortW proto WIN_STD_CALL_CONV :LPWSTR, :HWND, :LPWSTR
    ifdef UNICODE
      AddPort equ <AddPortW>
    else
      AddPort equ <AddPortA>
    endif
    ConfigurePortA proto WIN_STD_CALL_CONV :LPSTR, :HWND, :LPSTR
    ConfigurePortW proto WIN_STD_CALL_CONV :LPWSTR, :HWND, :LPWSTR
    ifdef UNICODE
      ConfigurePort equ <ConfigurePortW>
    else
      ConfigurePort equ <ConfigurePortA>
    endif
    DeletePortA proto WIN_STD_CALL_CONV :LPSTR, :HWND, :LPSTR
    DeletePortW proto WIN_STD_CALL_CONV :LPWSTR, :HWND, :LPWSTR
    ifdef UNICODE
      DeletePort equ <DeletePortW>
    else
      DeletePort equ <DeletePortA>
    endif
    XcvDataW proto WIN_STD_CALL_CONV :HANDLE, :PCWSTR, :PBYTE, :DWORD, :PBYTE, :DWORD, :PDWORD, :PDWORD
    XcvData equ <XcvDataW>
    GetDefaultPrinterA proto WIN_STD_CALL_CONV :LPSTR, :LPDWORD
    GetDefaultPrinterW proto WIN_STD_CALL_CONV :LPWSTR, :LPDWORD
    ifdef UNICODE
      GetDefaultPrinter equ <GetDefaultPrinterW>
    else
      GetDefaultPrinter equ <GetDefaultPrinterA>
    endif
    SetDefaultPrinterA proto WIN_STD_CALL_CONV :LPCSTR
    SetDefaultPrinterW proto WIN_STD_CALL_CONV :LPCWSTR
    ifdef UNICODE
      SetDefaultPrinter equ <SetDefaultPrinterW>
    else
      SetDefaultPrinter equ <SetDefaultPrinterA>
    endif
    SetPortA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :DWORD, :LPBYTE
    SetPortW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :DWORD, :LPBYTE
    ifdef UNICODE
      SetPort equ <SetPortW>
    else
      SetPort equ <SetPortA>
    endif
    AddPrinterConnectionA proto WIN_STD_CALL_CONV :LPSTR
    AddPrinterConnectionW proto WIN_STD_CALL_CONV :LPWSTR
    ifdef UNICODE
      AddPrinterConnection equ <AddPrinterConnectionW>
    else
      AddPrinterConnection equ <AddPrinterConnectionA>
    endif
    DeletePrinterConnectionA proto WIN_STD_CALL_CONV :LPSTR
    DeletePrinterConnectionW proto WIN_STD_CALL_CONV :LPWSTR
    ifdef UNICODE
      DeletePrinterConnection equ <DeletePrinterConnectionW>
    else
      DeletePrinterConnection equ <DeletePrinterConnectionA>
    endif
    ConnectToPrinterDlg proto WIN_STD_CALL_CONV :HWND, :DWORD
    PROVIDOR_INFO_1A struct
      pName LPSTR ?
      pEnvironment LPSTR ?
      pDLLName LPSTR ?
    PROVIDOR_INFO_1A ends
    _PROVIDOR_INFO_1A typedef PROVIDOR_INFO_1A
    PPROVIDOR_INFO_1A typedef ptr PROVIDOR_INFO_1A
    LPPROVIDOR_INFO_1A typedef ptr PROVIDOR_INFO_1A
    PROVIDOR_INFO_1W struct
      pName LPWSTR ?
      pEnvironment LPWSTR ?
      pDLLName LPWSTR ?
    PROVIDOR_INFO_1W ends
    _PROVIDOR_INFO_1W typedef PROVIDOR_INFO_1W
    PPROVIDOR_INFO_1W typedef ptr PROVIDOR_INFO_1W
    LPPROVIDOR_INFO_1W typedef ptr PROVIDOR_INFO_1W
    ifdef UNICODE
      PROVIDOR_INFO_1 typedef PROVIDOR_INFO_1W
      PPROVIDOR_INFO_1 typedef PPROVIDOR_INFO_1W
      LPPROVIDOR_INFO_1 typedef LPPROVIDOR_INFO_1W
    else
      PROVIDOR_INFO_1 typedef PROVIDOR_INFO_1A
      PPROVIDOR_INFO_1 typedef PPROVIDOR_INFO_1A
      LPPROVIDOR_INFO_1 typedef LPPROVIDOR_INFO_1A
    endif
    PROVIDOR_INFO_2A struct
      pOrder LPSTR ?
    PROVIDOR_INFO_2A ends
    _PROVIDOR_INFO_2A typedef PROVIDOR_INFO_2A
    PPROVIDOR_INFO_2A typedef ptr PROVIDOR_INFO_2A
    LPPROVIDOR_INFO_2A typedef ptr PROVIDOR_INFO_2A
    PROVIDOR_INFO_2W struct
      pOrder LPWSTR ?
    PROVIDOR_INFO_2W ends
    _PROVIDOR_INFO_2W typedef PROVIDOR_INFO_2W
    PPROVIDOR_INFO_2W typedef ptr PROVIDOR_INFO_2W
    LPPROVIDOR_INFO_2W typedef ptr PROVIDOR_INFO_2W
    ifdef UNICODE
      PROVIDOR_INFO_2 typedef PROVIDOR_INFO_2W
      PPROVIDOR_INFO_2 typedef PPROVIDOR_INFO_2W
      LPPROVIDOR_INFO_2 typedef LPPROVIDOR_INFO_2W
    else
      PROVIDOR_INFO_2 typedef PROVIDOR_INFO_2A
      PPROVIDOR_INFO_2 typedef PPROVIDOR_INFO_2A
      LPPROVIDOR_INFO_2 typedef LPPROVIDOR_INFO_2A
    endif
    AddPrintProvidorA proto WIN_STD_CALL_CONV :LPSTR, :DWORD, :LPBYTE
    AddPrintProvidorW proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPBYTE
    ifdef UNICODE
      AddPrintProvidor equ <AddPrintProvidorW>
    else
      AddPrintProvidor equ <AddPrintProvidorA>
    endif
    DeletePrintProvidorA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :LPSTR
    DeletePrintProvidorW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR, :LPWSTR
    ifdef UNICODE
      DeletePrintProvidor equ <DeletePrintProvidorW>
    else
      DeletePrintProvidor equ <DeletePrintProvidorA>
    endif
    if (NTDDI_VERSION ge NTDDI_WINXPSP2)
      IsValidDevmodeA proto WIN_STD_CALL_CONV :PDEVMODEA, :size_t
      IsValidDevmodeW proto WIN_STD_CALL_CONV :PDEVMODEW, :size_t
      ifdef UNICODE
        IsValidDevmode equ <IsValidDevmodeW>
      else
        IsValidDevmode equ <IsValidDevmodeA>
      endif
    endif
    SPLREG_DEFAULT_SPOOL_DIRECTORY equ <TEXT("DefaultSpoolDirectory")>
    SPLREG_PORT_THREAD_PRIORITY_DEFAULT equ <TEXT("PortThreadPriorityDefault")>
    SPLREG_PORT_THREAD_PRIORITY equ <TEXT("PortThreadPriority")>
    SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT equ <TEXT("SchedulerThreadPriorityDefault")>
    SPLREG_SCHEDULER_THREAD_PRIORITY equ <TEXT("SchedulerThreadPriority")>
    SPLREG_BEEP_ENABLED equ <TEXT("BeepEnabled")>
    SPLREG_NET_POPUP equ <TEXT("NetPopup")>
    SPLREG_RETRY_POPUP equ <TEXT("RetryPopup")>
    SPLREG_NET_POPUP_TO_COMPUTER equ <TEXT("NetPopupToComputer")>
    SPLREG_EVENT_LOG equ <TEXT("EventLog")>
    SPLREG_MAJOR_VERSION equ <TEXT("MajorVersion")>
    SPLREG_MINOR_VERSION equ <TEXT("MinorVersion")>
    SPLREG_ARCHITECTURE equ <TEXT("Architecture")>
    if (NTDDI_VERSION ge NTDDI_WINXP)
      SPLREG_OS_VERSION equ <TEXT("OSVersion")>
    endif
    SPLREG_OS_VERSIONEX equ <TEXT("OSVersionEx")>
    SPLREG_DS_PRESENT equ <TEXT("DsPresent")>
    SPLREG_DS_PRESENT_FOR_USER equ <TEXT("DsPresentForUser")>
    SPLREG_REMOTE_FAX equ <TEXT("RemoteFax")>
    SPLREG_RESTART_JOB_ON_POOL_ERROR equ <TEXT("RestartJobOnPoolError")>
    SPLREG_RESTART_JOB_ON_POOL_ENABLED equ <TEXT("RestartJobOnPoolEnabled")>
    SPLREG_DNS_MACHINE_NAME equ <TEXT("DNSMachineName")>
    if ((OSVER(NTDDI_VERSION) eq NTDDI_WINXP) and (SPVER(NTDDI_VERSION) ge 2) or (NTDDI_VERSION ge NTDDI_WS03SP1))
      SPLREG_ALLOW_USER_MANAGEFORMS equ <TEXT("AllowUserManageForms")>
    endif
    if (NTDDI_VERSION ge NTDDI_WS03)
      SPLREG_WEBSHAREMGMT equ <TEXT("WebShareMgmt")>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      SPLREG_PRINT_DRIVER_ISOLATION_GROUPS_SEPARATOR equ <L'\\'>
      SPLREG_PRINT_DRIVER_ISOLATION_GROUPS equ <TEXT("PrintDriverIsolationGroups")>
      SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE equ <TEXT("PrintDriverIsolationTimeBeforeRecycle")>
      SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE equ <TEXT("PrintDriverIsolationMaxobjsBeforeRecycle")>
      SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT equ <TEXT("PrintDriverIsolationIdleTimeout")>
      SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY equ <TEXT("PrintDriverIsolationExecutionPolicy")>
      SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY equ <TEXT("PrintDriverIsolationOverrideCompat")>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      SPLREG_PRINT_QUEUE_V4_DRIVER_DIRECTORY equ <TEXT("PrintQueueV4DriverDirectory")>
    endif
    SERVER_ACCESS_ADMINISTER equ 00000001h
    SERVER_ACCESS_ENUMERATE equ 00000002h
    PRINTER_ACCESS_ADMINISTER equ 00000004h
    PRINTER_ACCESS_USE equ 00000008h
    JOB_ACCESS_ADMINISTER equ 00000010h
    if ((NTDDI_VERSION ge NTDDI_WINXPSP1) or ((OSVER(NTDDI_VERSION) eq NTDDI_WIN2K) and (SPVER(NTDDI_VERSION) ge 3)))
      JOB_ACCESS_READ equ 00000020h
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      PRINTER_ACCESS_MANAGE_LIMITED equ 00000040h
    endif
    SERVER_ALL_ACCESS equ <(STANDARD_RIGHTS_REQUIRED or SERVER_ACCESS_ADMINISTER or SERVER_ACCESS_ENUMERATE)>
    SERVER_READ equ <(STANDARD_RIGHTS_READ or SERVER_ACCESS_ENUMERATE)>
    SERVER_WRITE equ <(STANDARD_RIGHTS_WRITE or SERVER_ACCESS_ADMINISTER or SERVER_ACCESS_ENUMERATE)>
    SERVER_EXECUTE equ <(STANDARD_RIGHTS_EXECUTE or SERVER_ACCESS_ENUMERATE)>
    PRINTER_ALL_ACCESS equ <(STANDARD_RIGHTS_REQUIRED or PRINTER_ACCESS_ADMINISTER or PRINTER_ACCESS_USE)>
    PRINTER_READ equ <(STANDARD_RIGHTS_READ or PRINTER_ACCESS_USE)>
    PRINTER_WRITE equ <(STANDARD_RIGHTS_WRITE or PRINTER_ACCESS_USE)>
    PRINTER_EXECUTE equ <(STANDARD_RIGHTS_EXECUTE or PRINTER_ACCESS_USE)>
    if ((NTDDI_VERSION ge NTDDI_WINXPSP1) or ((OSVER(NTDDI_VERSION) eq NTDDI_WIN2K) and (SPVER(NTDDI_VERSION) ge 3)))
      JOB_ALL_ACCESS equ <(STANDARD_RIGHTS_REQUIRED or JOB_ACCESS_ADMINISTER or JOB_ACCESS_READ)>
    else
      JOB_ALL_ACCESS equ <(STANDARD_RIGHTS_REQUIRED or JOB_ACCESS_ADMINISTER)>
    endif
    if ((NTDDI_VERSION ge NTDDI_WINXPSP1) or ((OSVER(NTDDI_VERSION) eq NTDDI_WIN2K) and (SPVER(NTDDI_VERSION) ge 3)))
      JOB_READ equ <(STANDARD_RIGHTS_READ or JOB_ACCESS_READ)>
    else
      JOB_READ equ <(STANDARD_RIGHTS_READ or JOB_ACCESS_ADMINISTER)>
    endif
    JOB_WRITE equ <(STANDARD_RIGHTS_WRITE or JOB_ACCESS_ADMINISTER)>
    JOB_EXECUTE equ <(STANDARD_RIGHTS_EXECUTE or JOB_ACCESS_ADMINISTER)>
    SPLDS_SPOOLER_KEY equ <TEXT("DsSpooler")>
    SPLDS_DRIVER_KEY equ <TEXT("DsDriver")>
    SPLDS_USER_KEY equ <TEXT("DsUser")>
    SPLDS_ASSET_NUMBER equ <TEXT("assetNumber")>
    SPLDS_BYTES_PER_MINUTE equ <TEXT("bytesPerMinute")>
    SPLDS_DESCRIPTION equ <TEXT("description")>
    SPLDS_DRIVER_NAME equ <TEXT("driverName")>
    SPLDS_DRIVER_VERSION equ <TEXT("driverVersion")>
    SPLDS_LOCATION equ <TEXT("location")>
    SPLDS_PORT_NAME equ <TEXT("portName")>
    SPLDS_PRINT_ATTRIBUTES equ <TEXT("printAttributes")>
    SPLDS_PRINT_BIN_NAMES equ <TEXT("printBinNames")>
    SPLDS_PRINT_COLLATE equ <TEXT("printCollate")>
    SPLDS_PRINT_COLOR equ <TEXT("printColor")>
    SPLDS_PRINT_DUPLEX_SUPPORTED equ <TEXT("printDuplexSupported")>
    SPLDS_PRINT_END_TIME equ <TEXT("printEndTime")>
    SPLDS_PRINTER_CLASS equ <TEXT("printQueue")>
    SPLDS_PRINTER_NAME equ <TEXT("printerName")>
    SPLDS_PRINT_KEEP_PRINTED_JOBS equ <TEXT("printKeepPrintedJobs")>
    SPLDS_PRINT_LANGUAGE equ <TEXT("printLanguage")>
    SPLDS_PRINT_MAC_ADDRESS equ <TEXT("printMACAddress")>
    SPLDS_PRINT_MAX_X_EXTENT equ <TEXT("printMaxXExtent")>
    SPLDS_PRINT_MAX_Y_EXTENT equ <TEXT("printMaxYExtent")>
    SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED equ <TEXT("printMaxResolutionSupported")>
    SPLDS_PRINT_MEDIA_READY equ <TEXT("printMediaReady")>
    SPLDS_PRINT_MEDIA_SUPPORTED equ <TEXT("printMediaSupported")>
    SPLDS_PRINT_MEMORY equ <TEXT("printMemory")>
    SPLDS_PRINT_MIN_X_EXTENT equ <TEXT("printMinXExtent")>
    SPLDS_PRINT_MIN_Y_EXTENT equ <TEXT("printMinYExtent")>
    SPLDS_PRINT_NETWORK_ADDRESS equ <TEXT("printNetworkAddress")>
    SPLDS_PRINT_NOTIFY equ <TEXT("printNotify")>
    SPLDS_PRINT_NUMBER_UP equ <TEXT("printNumberUp")>
    SPLDS_PRINT_ORIENTATIONS_SUPPORTED equ <TEXT("printOrientationsSupported")>
    SPLDS_PRINT_OWNER equ <TEXT("printOwner")>
    SPLDS_PRINT_PAGES_PER_MINUTE equ <TEXT("printPagesPerMinute")>
    SPLDS_PRINT_RATE equ <TEXT("printRate")>
    SPLDS_PRINT_RATE_UNIT equ <TEXT("printRateUnit")>
    SPLDS_PRINT_SEPARATOR_FILE equ <TEXT("printSeparatorFile")>
    SPLDS_PRINT_SHARE_NAME equ <TEXT("printShareName")>
    SPLDS_PRINT_SPOOLING equ <TEXT("printSpooling")>
    SPLDS_PRINT_STAPLING_SUPPORTED equ <TEXT("printStaplingSupported")>
    SPLDS_PRINT_START_TIME equ <TEXT("printStartTime")>
    SPLDS_PRINT_STATUS equ <TEXT("printStatus")>
    SPLDS_PRIORITY equ <TEXT("priority")>
    SPLDS_SERVER_NAME equ <TEXT("serverName")>
    SPLDS_SHORT_SERVER_NAME equ <TEXT("shortServerName")>
    SPLDS_UNC_NAME equ <TEXT("uNCName")>
    SPLDS_URL equ <TEXT("url")>
    SPLDS_FLAGS equ <TEXT("flags")>
    SPLDS_VERSION_NUMBER equ <TEXT("versionNumber")>
    SPLDS_PRINTER_NAME_ALIASES equ <TEXT("printerNameAliases")>
    SPLDS_PRINTER_LOCATIONS equ <TEXT("printerLocations")>
    SPLDS_PRINTER_MODEL equ <TEXT("printerModel")>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      PRINTER_OPTION_FLAGS typedef SDWORD
      PRINTER_OPTION_NO_CACHE equ 1 shl 0
      PRINTER_OPTION_CACHE equ 1 shl 1
      PRINTER_OPTION_CLIENT_CHANGE equ 1 shl 2
      PRINTER_OPTION_NO_CLIENT_DATA equ 1 shl 3
      _PRINTER_OPTION_FLAGS typedef PRINTER_OPTION_FLAGS

      PRINTER_OPTIONSA struct
        cbSize UINT ?
        dwFlags DWORD ?
      PRINTER_OPTIONSA ends
      _PRINTER_OPTIONSA typedef PRINTER_OPTIONSA
      PPRINTER_OPTIONSA typedef ptr PRINTER_OPTIONSA
      LPPRINTER_OPTIONSA typedef ptr PRINTER_OPTIONSA
      PRINTER_OPTIONSW struct
        cbSize UINT ?
        dwFlags DWORD ?
      PRINTER_OPTIONSW ends
      _PRINTER_OPTIONSW typedef PRINTER_OPTIONSW
      PPRINTER_OPTIONSW typedef ptr PRINTER_OPTIONSW
      LPPRINTER_OPTIONSW typedef ptr PRINTER_OPTIONSW
      ifdef UNICODE
        PRINTER_OPTIONS typedef PRINTER_OPTIONSW
        PPRINTER_OPTIONS typedef PPRINTER_OPTIONSW
        LPPRINTER_OPTIONS typedef LPPRINTER_OPTIONSW
      else
        PRINTER_OPTIONS typedef PRINTER_OPTIONSA
        PPRINTER_OPTIONS typedef PPRINTER_OPTIONSA
        LPPRINTER_OPTIONS typedef LPPRINTER_OPTIONSA
      endif
      OpenPrinter2A proto WIN_STD_CALL_CONV :LPCSTR, :LPHANDLE, :PPRINTER_DEFAULTSA, :PPRINTER_OPTIONSA
      OpenPrinter2W proto WIN_STD_CALL_CONV :LPCWSTR, :LPHANDLE, :PPRINTER_DEFAULTSW, :PPRINTER_OPTIONSW
      ifdef UNICODE
        OpenPrinter2 equ <OpenPrinter2W>
      else
        OpenPrinter2 equ <OpenPrinter2A>
      endif
      PRINTER_CONNECTION_MISMATCH equ 00000020h
      PRINTER_CONNECTION_NO_UI equ 00000040h
      PRINTER_CONNECTION_INFO_1A struct
        dwFlags DWORD ?
        pszDriverName LPSTR ?
      PRINTER_CONNECTION_INFO_1A ends
      _PRINTER_CONNECTION_INFO_1A typedef PRINTER_CONNECTION_INFO_1A
      PPRINTER_CONNECTION_INFO_1A typedef ptr PRINTER_CONNECTION_INFO_1A
      PRINTER_CONNECTION_INFO_1W struct
        dwFlags DWORD ?
        pszDriverName LPWSTR ?
      PRINTER_CONNECTION_INFO_1W ends
      _PRINTER_CONNECTION_INFO_1W typedef PRINTER_CONNECTION_INFO_1W
      PPRINTER_CONNECTION_INFO_1W typedef ptr PRINTER_CONNECTION_INFO_1W
      ifdef UNICODE
        PRINTER_CONNECTION_INFO_1 typedef PRINTER_CONNECTION_INFO_1W
        PPRINTER_CONNECTION_INFO_1 typedef PPRINTER_CONNECTION_INFO_1W
      else
        PRINTER_CONNECTION_INFO_1 typedef PRINTER_CONNECTION_INFO_1A
        PPRINTER_CONNECTION_INFO_1 typedef PPRINTER_CONNECTION_INFO_1A
      endif
      AddPrinterConnection2A proto WIN_STD_CALL_CONV :HWND, :LPCSTR, :DWORD, :PVOID
      AddPrinterConnection2W proto WIN_STD_CALL_CONV :HWND, :LPCWSTR, :DWORD, :PVOID
      ifdef UNICODE
        AddPrinterConnection2 equ <AddPrinterConnection2W>
      else
        AddPrinterConnection2 equ <AddPrinterConnection2A>
      endif
      IPDFP_COPY_ALL_FILES equ 00000001h
      InstallPrinterDriverFromPackageA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR, :DWORD
      InstallPrinterDriverFromPackageW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD
      ifdef UNICODE
        InstallPrinterDriverFromPackage equ <InstallPrinterDriverFromPackageW>
      else
        InstallPrinterDriverFromPackage equ <InstallPrinterDriverFromPackageA>
      endif
      UPDP_SILENT_UPLOAD equ 00000001h
      UPDP_UPLOAD_ALWAYS equ 00000002h
      UPDP_CHECK_DRIVERSTORE equ 00000004h
      UploadPrinterDriverPackageA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :DWORD, :HWND, :LPSTR, :PULONG
      UploadPrinterDriverPackageW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :HWND, :LPWSTR, :PULONG
      ifdef UNICODE
        UploadPrinterDriverPackage equ <UploadPrinterDriverPackageW>
      else
        UploadPrinterDriverPackage equ <UploadPrinterDriverPackageA>
      endif
      CORE_PRINTER_DRIVERA struct
        CoreDriverGUID GUID <>
        ftDriverDate FILETIME <>
        dwlDriverVersion DWORDLONG ?
        szPackageID CHAR MAX_PATH dup (?)
      CORE_PRINTER_DRIVERA ends
      _CORE_PRINTER_DRIVERA typedef CORE_PRINTER_DRIVERA
      PCORE_PRINTER_DRIVERA typedef ptr CORE_PRINTER_DRIVERA
      CORE_PRINTER_DRIVERW struct
        CoreDriverGUID GUID <>
        ftDriverDate FILETIME <>
        dwlDriverVersion DWORDLONG ?
        szPackageID WCHAR MAX_PATH dup (?)
      CORE_PRINTER_DRIVERW ends
      _CORE_PRINTER_DRIVERW typedef CORE_PRINTER_DRIVERW
      PCORE_PRINTER_DRIVERW typedef ptr CORE_PRINTER_DRIVERW
      ifdef UNICODE
        CORE_PRINTER_DRIVER typedef CORE_PRINTER_DRIVERW
        PCORE_PRINTER_DRIVER typedef PCORE_PRINTER_DRIVERW
      else
        CORE_PRINTER_DRIVER typedef CORE_PRINTER_DRIVERA
        PCORE_PRINTER_DRIVER typedef PCORE_PRINTER_DRIVERA
      endif
      GetCorePrinterDriversA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :DWORD, :PCORE_PRINTER_DRIVERA
      GetCorePrinterDriversW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :PCORE_PRINTER_DRIVERW
      ifdef UNICODE
        GetCorePrinterDrivers equ <GetCorePrinterDriversW>
      else
        GetCorePrinterDrivers equ <GetCorePrinterDriversA>
      endif
      CorePrinterDriverInstalledA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :GUID, :FILETIME, :DWORDLONG, :ptr BOOL
      CorePrinterDriverInstalledW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :GUID, :FILETIME, :DWORDLONG, :ptr BOOL
      ifdef UNICODE
        CorePrinterDriverInstalled equ <CorePrinterDriverInstalledW>
      else
        CorePrinterDriverInstalled equ <CorePrinterDriverInstalledA>
      endif
      GetPrinterDriverPackagePathA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :DWORD, :LPDWORD
      GetPrinterDriverPackagePathW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :DWORD, :LPDWORD
      ifdef UNICODE
        GetPrinterDriverPackagePath equ <GetPrinterDriverPackagePathW>
      else
        GetPrinterDriverPackagePath equ <GetPrinterDriverPackagePathA>
      endif
      DeletePrinterDriverPackageA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR
      DeletePrinterDriverPackageW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR
      ifdef UNICODE
        DeletePrinterDriverPackage equ <DeletePrinterDriverPackageW>
      else
        DeletePrinterDriverPackage equ <DeletePrinterDriverPackageA>
      endif
      EPrintPropertyType typedef SDWORD
      kPropertyTypeString equ 1
      kPropertyTypeInt32 equ 2
      kPropertyTypeInt64 equ 3
      kPropertyTypeByte equ 4
      kPropertyTypeTime equ 5
      kPropertyTypeDevMode equ 6
      kPropertyTypeSD equ 7
      kPropertyTypeNotificationReply equ 8
      kPropertyTypeNotificationOptions equ 9
      kPropertyTypeBuffer equ 10

      EPrintXPSJobProgress typedef SDWORD
      kAddingDocumentSequence equ 0
      kDocumentSequenceAdded equ 1
      kAddingFixedDocument equ 2
      kFixedDocumentAdded equ 3
      kAddingFixedPage equ 4
      kFixedPageAdded equ 5
      kResourceAdded equ 6
      kFontAdded equ 7
      kImageAdded equ 8
      kXpsDocumentCommitted equ 9

      EPrintXPSJobOperation typedef SDWORD
      kJobProduction equ 1
      kJobConsumption equ 2

      PrintPropertyValue struct
        ePropertyType EPrintPropertyType ?
        union value
          propertyByte BYTE ?
          propertyString PWSTR ?
          propertyInt32 LONG ?
          propertyInt64 LONGLONG ?
          struct propertyBlob
            cbBuf DWORD ?
            pBuf LPVOID ?
          ends
        ends
      PrintPropertyValue ends
      PrintNamedProperty struct
        propertyName POINTER ?
        propertyValue PrintPropertyValue <>
      PrintNamedProperty ends
      PrintPropertiesCollection struct
        numberOfProperties ULONG ?
        propertiesCollection POINTER ?
      PrintPropertiesCollection ends
      ReportJobProcessingProgress proto WIN_STD_CALL_CONV :HANDLE, :ULONG, :EPrintXPSJobOperation, :EPrintXPSJobProgress
      GetPrinterDriver2A proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
      GetPrinterDriver2W proto WIN_STD_CALL_CONV :HWND, :HANDLE, :LPWSTR, :DWORD, :LPBYTE, :DWORD, :LPDWORD
      ifdef UNICODE
        GetPrinterDriver2 equ <GetPrinterDriver2W>
      else
        GetPrinterDriver2 equ <GetPrinterDriver2A>
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      PRINT_EXECUTION_CONTEXT typedef SDWORD
      PRINT_EXECUTION_CONTEXT_APPLICATION equ 0
      PRINT_EXECUTION_CONTEXT_SPOOLER_SERVICE equ 1
      PRINT_EXECUTION_CONTEXT_SPOOLER_ISOLATION_HOST equ 2
      PRINT_EXECUTION_CONTEXT_FILTER_PIPELINE equ 3
      PRINT_EXECUTION_CONTEXT_WOW64 equ 4

      PRINT_EXECUTION_DATA struct
        context PRINT_EXECUTION_CONTEXT ?
        clientAppPID DWORD ?
      PRINT_EXECUTION_DATA ends
      GetPrintExecutionData proto WIN_STD_CALL_CONV :ptr PRINT_EXECUTION_DATA
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      GetJobNamedPropertyValue proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :PCWSTR, :ptr PrintPropertyValue
      FreePrintPropertyValue proto WIN_STD_CALL_CONV :ptr PrintPropertyValue
      FreePrintNamedPropertyArray proto WIN_STD_CALL_CONV :DWORD, :ptr ptr PrintNamedProperty
      SetJobNamedProperty proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :ptr PrintNamedProperty
      DeleteJobNamedProperty proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :PCWSTR
      EnumJobNamedProperties proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :ptr DWORD, :ptr ptr PrintNamedProperty
      GetPrintOutputInfo proto WIN_STD_CALL_CONV :HWND, :PCWSTR, :ptr HANDLE, :ptr PWSTR
      MS_PRINT_JOB_OUTPUT_FILE equ <L("MsPrintJobOutputFile")>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
    endif
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
