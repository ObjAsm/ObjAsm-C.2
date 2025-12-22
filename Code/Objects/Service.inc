; ==================================================================================================
; Title:      Service.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Service base object.
; Notes:      Version C.1.0, December 2025.
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; SERVICE_HOSTING_TYPE determines how this services is hosted:
;
;   SERVICE_WIN32_SHARE_PROCESS  - The services share a single process with other
;                                  services. Use this if you want multiple services
;                                  to run in one host process.
;
;   SERVICE_WIN32_OWN_PROCESS    - The services run in their own dedicated process.
;                                  Use this if you want each service isolated.
; --------------------------------------------------------------------------------------------------
SERVICE_HOSTING_TYPE equ SERVICE_WIN32_SHARE_PROCESS


; --------------------------------------------------------------------------------------------------
; Object:     Service
; Purpose:    A Windows service is a special type of application that runs in the background,
;             usually without a user interface, and starts automatically when Windows boots
;             (or on demand). It’s designed for long-running tasks like servers, schedulers,
;             updaters, and system monitoring.
;
;    Startup Sequence:
;
;    SCM
;     ¦
;     ¦  StartService
;     V
;    ServiceMainThunk (external bootstrap)
;     ¦
;     ¦  Init
;     V
;    RegisterServiceCtrlHandlerEx
;     ¦
;     ¦  CreateThread(Service.Run)
;     V
;    Service.Run (worker thread)
;
;
;    Control Flow (runtime):
;
;    SCM
;     ¦
;     ¦ Control Code
;     V
;    ServiceCtrlHandlerEx (thunk)
;     ¦
;     ¦ pSelf
;     V
;    Service.Dispatch
;     ¦
;     +- SERVICE_CONTROL_STOP ---------> OnStop
;     +- SERVICE_CONTROL_PAUSE --------> OnPause
;     +- SERVICE_CONTROL_CONTINUE -----> OnContinue
;     +- SERVICE_CONTROL_INTERROGATE --> OnInterrogate
;     +- SERVICE_CONTROL_SHUTDOWN -----> OnShutdown
;     +- SERVICE_CONTROL_PRESHUTDOWN --> OnPreshutdown
;
;
;    Shutdown Sequence:
;
;    OnStop / OnShutdown
;     ¦
;     ¦ SetEvent(hStopEvent)
;     V
;    Service.Run loop exits
;     ¦
;     ¦ Set SERVICE_STOPPED & Done cleanup
;     V
;    Thread returns


Object Service, ServiceID, Streamable                   ;Define Service object, derived from Streamable
  RedefineMethod    Done                                ;Override destructor
  RedefineMethod    Init,           DWORD, POINTER      ;Override initializer (argc, argv)
  VirtualMethod     Dispatch,       DWORD, DWORD, POINTER ;Dispatch SCM control codes
  VirtualMethod     Run                                 ;Main service execution thread
  VirtualMethod     OnContinue                          ;Handle continue command
  VirtualMethod     OnInterrogate                       ;Handle status query
  VirtualMethod     OnPause                             ;Handle pause command
  VirtualMethod     OnPreshutdown                       ;Handle pre-shutdown notification
  VirtualMethod     OnShutdown                          ;Handle system shutdown
  VirtualMethod     OnStop                              ;Handle stop request

  StaticMethod      Install                             ;Install service into SCM
  StaticMethod      Uninstall                           ;Remove service from SCM

  ;The following 3 strings are set by descendant static Startup method
  DefineVariable    pName,          PSTRING             ;Internal service name
  DefineVariable    pDisp,          PSTRING             ;Display name shown in SCM
  DefineVariable    pDesc,          PSTRING             ;Service description text

  DefineVariable    Status,         SERVICE_STATUS,   {} ;Current service status structure
  DefineVariable    hServiceStatus, SERVICE_STATUS_HANDLE,  ? ;SCM status handle
  DefineVariable    hStopEvent,     HANDLE,  ?          ;Manual-reset stop signal
  DefineVariable    hWorkerThread,  HANDLE,  ?          ;Worker thread handle
ObjectEnd                                               ;End Service object definition


; ==================================================================================================
;    Logging helper procs
; ==================================================================================================

.data
hServiceLogFile    HANDLE  0
ServiceLogCritSect CRITICAL_SECTION  {}

.code                                                   ;Begin executable code
; --------------------------------------------------------------------------------------------------
; Procedure:  CloseServiceLogFile
; Purpose:    Close Log-File.
; Arguments:  None.
; Return:     Nothing.

align ALIGN_CODE
CloseServiceLogFile proc
  ;Delete the critical section used for thread-safe logging
  invoke DeleteCriticalSection, addr ServiceLogCritSect

  ;Close the log file handle if it's open
  mov xax, hServiceLogFile                              ;Load current file handle
  .if xax != 0
    invoke CloseHandle, xax                             ;Close the file handle
    mov hServiceLogFile, 0                              ;Reset handle to 0
  .endif
  ret
CloseServiceLogFile endp

; --------------------------------------------------------------------------------------------------
; Procedure:  OpenServiceLogFile
; Purpose:    Open Log-File for writing (multi-writer safe).
; Arguments:  Arg1: -> File name.
; Return:     xax = File HANDLE or 0 if failed.

align ALIGN_CODE
OpenServiceLogFile proc uses xbx pLogFileName:PSTRING
  .if hServiceLogFile == 0
    ;Open the file in append mode, allowing multiple processes to write simultaneously
    invoke CreateFile, pLogFileName, GENERIC_WRITE, FILE_SHARE_READ or FILE_SHARE_WRITE, \
                       0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0  ;Create or open file
    .if xax != 0
      mov hServiceLogFile, xax                          ;Save the handle globally
      ;Move file pointer to the end so writes will append
      invoke SetFilePointer, hServiceLogFile, 0, 0, FILE_END
  
      ;Initialize critical section for thread-safe writes
      invoke InitializeCriticalSection, addr ServiceLogCritSect
      mov xax, hServiceLogFile                          ;Return file handle in xax
    .endif
  .else
    xor eax, eax
  .endif
  ret
OpenServiceLogFile endp

; --------------------------------------------------------------------------------------------------
; Procedure:  LogServiceMessage
; Purpose:    Thread-safe log write.
; Arguments:  Arg1: -> Message (ANSI).
; Return:     Nothing.

align ALIGN_CODE
LogServiceMessage proc, pMessage:PSTRINGA
  .if hServiceLogFile != 0
    invoke EnterCriticalSection, addr ServiceLogCritSect  ;Lock critical section
    invoke StrLengthA, pMessage                           ;Get message length
    invoke WriteFile, hServiceLogFile, pMessage, eax, NULL, 0  ;Write message to file
    invoke WriteFile, hServiceLogFile, addr bCRLF, 2, NULL, 0  ;Add CRLF to line end
    invoke LeaveCriticalSection, addr ServiceLogCritSect  ;Unlock critical section
  .endif
  ret
LogServiceMessage endp


; ==================================================================================================
;    Service implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  ServiceCtrlHandlerEx
; Purpose:    Callback from SCM when a control command is dispatched.
; Arguments:  Arg1: SCM control command.
;             Arg2: Event type.
;             Arg3: -> Data.
;             Arg4: Custom value (Object instance pointer).
; Return:     Nothing.

;Note: Once the service is running, SCM sends commands to the service using this thunk.
ServiceCtrlHandlerEx proc dControl:DWORD, dEventType:DWORD, pEventData:POINTER, pSelf:POINTER
                                                        ;SCM callback entry point
  DbgText "ServiceCtrlHandler"                          ;Debug trace
  OCall pSelf::Service.Dispatch, dControl, dEventType, pEventData   ;Forward to object dispatcher
  ret                                                   ;Return to SCM; no return value expected
ServiceCtrlHandlerEx endp

; --------------------------------------------------------------------------------------------------
; Method:     Service.Dispatch
; Purpose:    Dispatch commands send from SCM.
; Arguments:  Arg1: SCM control command.
;             Arg2: Event type.
;             Arg3: -> Data.
; Return:     eax = NO_ERROR or error code.

Method Service.Dispatch,, dControl:DWORD, dEventType:DWORD, pEventData:POINTER
  ANNOTATION use::pEventData

  DbgText "Service.Dispatch"                            ;Debug trace
  SetObject xcx                                         ;Load object pointer
  DbgDec dControl                                       ;Log control code
  DbgDec dEventType                                     ;Log event type
  mov eax, dControl                                     ;Select control code
  .if eax == SERVICE_CONTROL_CONTINUE    	              ;Resume request
    OCall xcx.OnContinue                                ;Resume service
  .elseif eax == SERVICE_CONTROL_INTERROGATE	          ;Status query
    OCall xcx.OnInterrogate                             ;Report status
  .elseif eax == SERVICE_CONTROL_PAUSE	                ;Pause request
    OCall xcx.OnPause                                   ;Pause service
  .elseif eax == SERVICE_CONTROL_PRESHUTDOWN            ;Pre-shutdown request
    OCall xcx.OnPreshutdown                             ;Early shutdown handling
  .elseif eax == SERVICE_CONTROL_SHUTDOWN	              ;Shutdown request
    OCall xcx.OnShutdown                                ;Immediate shutdown
  .elseif eax == SERVICE_CONTROL_STOP                   ;Stop request
    OCall xcx.OnStop                                    ;Terminate service
  .else
    mov eax, ERROR_CALL_NOT_IMPLEMENTED
  .endif
MethodEnd                                               ;End Dispatch

; --------------------------------------------------------------------------------------------------
; Method:     Service.Done
; Purpose:    Finalize the Service object.
; Arguments:  None.
; Return:     Nothing.

Method Service.Done, uses xsi
  DbgText "Service.Done"                                ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov xcx, [xsi].hStopEvent
  .if xcx != 0
    invoke CloseHandle, xcx                             ;Release stop event
  .endif
  ACall xsi.Done                                        ;Call base class destructor
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.Init
; Purpose:    Initialize the Service object.
; Arguments:  Arg1: Number of arguments.
;             Arg2: -> Argument array. First element is the service name.
; Return:     eax = 0 if failed.

Method Service.Init, uses xsi, dArgC:DWORD, pArgV:POINTER
  ANNOTATION use:dArgC, pArgV

  DbgText "Service.Init"                                ;Debug trace
  SetObject xsi                                         ;Load object pointer
  ;Register the Control Handler
  invoke RegisterServiceCtrlHandlerEx, [xsi].pName, offset ServiceCtrlHandlerEx, xsi
                                                        ;Register SCM callback
  .if xax != 0
    mov [xsi].hServiceStatus, xax                       ;Store SCM status handle

    invoke MemZero, addr [xsi].Status, sizeof SERVICE_STATUS    ;Clear SERVICE_STATUS
    mov [xsi].Status.dwServiceType, SERVICE_HOSTING_TYPE

    mov [xsi].Status.dwCurrentState, SERVICE_START_PENDING    ;Report startup pending
    invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM

    ;Create manual-reset stop event
    mov [xsi].hStopEvent, $invoke(CreateEvent, 0, TRUE, FALSE, 0)

    ;Create suspended worker thread
    invoke CreateThread, NULL, 0, $MethodAddr(xsi::Service.Run), xsi, CREATE_SUSPENDED, NULL
    mov [xsi].hWorkerThread, xax                        ;Store thread handle
    invoke ResumeThread, [xsi].hWorkerThread            ;Start service execution
    mov eax, 1                                          ;Success
  .else
    DbgApiError                                         ;Debug failure
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.OnContinue
; Purpose:    Resume service execution.
; Arguments:  None.
; Return:     eax = NO_ERROR or error code.

Method Service.OnContinue, uses xsi
  DbgText "Service.OnContinue"                          ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwCurrentState, SERVICE_CONTINUE_PENDING
                                                        ;Notify continue pending
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Update SCM
  invoke ResumeThread, [xsi].hWorkerThread              ;Resume worker thread
  mov [xsi].Status.dwCurrentState, SERVICE_RUNNING      ;Service running
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
  mov eax, NO_ERROR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.OnInterrogate
; Purpose:    Status query handler.
; Arguments:  None.
; Return:     eax = NO_ERROR or error code.

Method Service.OnInterrogate, uses xsi
  DbgText "Service.OnInterrogate"                       ;Debug trace
  SetObject xsi                                         ;Load object pointer
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Return current status
  mov eax, NO_ERROR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.OnPause
; Purpose:    Pause service execution.
; Arguments:  None.
; Return:     eax = NO_ERROR or error code.

Method Service.OnPause, uses xsi
  DbgText "Service.OnPause"                             ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwCurrentState, SERVICE_PAUSE_PENDING  ;Pause pending
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status
                                                        ;Notify SCM
  invoke SuspendThread, [xsi].hWorkerThread             ;Suspend worker thread
  mov [xsi].Status.dwCurrentState, SERVICE_PAUSED       ;Paused
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status
                                                        ;Notify SCM
  mov eax, NO_ERROR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.OnPreshutdown
; Purpose:    Pre-shutdown handler.
; Arguments:  None.
; Return:     eax = NO_ERROR or error code.

Method Service.OnPreshutdown, uses xsi
  DbgText "Service.OnPreshutdown"                       ;Debug trace
  SetObject xsi                                         ;Load object pointer

  ;Tell SCM we're stopping and may take time
  mov [xsi].Status.dwCurrentState, SERVICE_STOP_PENDING ;Stopping
  mov [xsi].Status.dwWaitHint, 30000                    ;30 seconds hint
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM

  ;Perform critical cleanup here...
  ;(flush logs, save state, notify peers)

  invoke SetEvent, [xsi].hStopEvent                     ;Signal service shutdown
  mov eax, NO_ERROR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.OnShutdown
; Purpose:    Shutdown handler.
; Arguments:  None.
; Return:     eax = NO_ERROR or error code.

Method Service.OnShutdown, uses xsi
  DbgText "Service.OnShutdown"                          ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwControlsAccepted, 0                ;Reject new controls
  mov [xsi].Status.dwCurrentState, SERVICE_STOP_PENDING ;Stopping
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
  invoke SetEvent, [xsi].hStopEvent                     ;Signal shutdown
  mov eax, NO_ERROR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.OnStop
; Purpose:    Stop handler.
; Arguments:  None.
; Return:     eax = NO_ERROR or error code.

Method Service.OnStop, uses xsi
  DbgText "Service.OnStop"                              ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov eax, [xsi].Status.dwCurrentState                  ;Check current state
  .if eax == SERVICE_RUNNING
    mov [xsi].Status.dwCurrentState, SERVICE_STOP_PENDING   ;Stopping
    mov [xsi].Status.dwWaitHint, 30000                  ;30 seconds hint
    invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
    invoke SetEvent, [xsi].hStopEvent                   ;Signal stop
  .elseif eax == SERVICE_PAUSED
    mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Limit accepted controls
    mov [xsi].Status.dwCurrentState, SERVICE_STOPPED    ;Stopped
    invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
  .endif
  mov eax, NO_ERROR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.Run
; Purpose:    Main worker thread.
; Arguments:  None.
; Return:     Nothing.

Method Service.Run, uses xsi
  DbgText "Service.Run"                                 ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_PAUSE_CONTINUE or \
                                       SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Declare accepted controls
  mov [xsi].Status.dwCurrentState, SERVICE_RUNNING      ;Service running
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status    ;Notify SCM
  .while TRUE
    invoke WaitForSingleObject, [xsi].hStopEvent, 1000  ;Poll stop event

    ; Do something ...

    .continue .if eax == WAIT_TIMEOUT                   ;Continue if timeout

    .break                                              ;Exit loop
  .endw

  OCall xsi.Done

  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Limit controls
  mov [xsi].Status.dwCurrentState, SERVICE_STOPPED      ;Stopped
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
MethodEnd


; ==================================================================================================
;    Service (un)installation procedures
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Service.Install
; Purpose:    Install the service.
; Return:     eax = 0 Success
;                   1 General failure
;                   2 Invalid arguments
;                   5 Access denied / insufficient privileges
;                   1073 Service already exists (often treated as success)
;                   1603 Fatal installer error (MSI standard)

Method Service.Install, uses xbx xdi xsi
  local dLastError:DWORD, cModulePath[MAX_PATH]:CHR, SvcDesc:SERVICE_DESCRIPTION

  DbgText "Service.Install"                             ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov dLastError, 0                                     ;Assume success

  invoke OpenSCManager, 0, 0, SC_MANAGER_CREATE_SERVICE ;Open SCM with create rights
  .if xax != 0
    mov xbx, xax                                        ;Save SCM handle

    invoke GetModuleFileName, 0, addr cModulePath, lengthof cModulePath   ;Get executable path

    ;Create service entry
    invoke CreateService, xbx, [xsi].pName, [xsi].pDisp, SERVICE_ALL_ACCESS, \
                          SERVICE_HOSTING_TYPE, SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL, \
                          addr cModulePath, NULL, NULL, NULL, NULL, NULL
    .if xax != 0
      mov xdi, xax                                      ;Service handle
      m2m SvcDesc.lpDescription, [xsi].pDesc, xcx       ;Set description pointer
      invoke ChangeServiceConfig2, xdi, SERVICE_CONFIG_DESCRIPTION, addr SvcDesc  ;Apply description
      invoke CloseServiceHandle, xdi                    ;Close service handle
    .else
      mov dLastError, $32($invoke(GetLastError))        ;Store error
    .endif
    invoke CloseServiceHandle, xbx                      ;Close SCM handle
  .else
    mov dLastError, $32($invoke(GetLastError))          ;Store error
  .endif

  mov eax, dLastError                                   ;Return error code
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service.Uninstall
; Purpose:    Uninstall the service.
; Arguments:  None.
; Return:     eax = 0 Success (service removed or already not installed)
;                   1 General failure
;                   2 Invalid arguments
;                   5 Access denied / insufficient privileges
;                   1060 Service does not exist (often treated as success)
; Link:       https://learn.microsoft.com/en-us/windows/win32/services/deleting-a-service

Method Service.Uninstall, uses xbx xdi xsi
  local dLastError:DWORD                               ;Last error storage

  DbgText "Service.Uninstall"                          ;Debug trace
  SetObject xsi                                        ;Load object pointer
  mov dLastError, 0                                    ;Assume success

  invoke OpenSCManager, 0, 0, SC_MANAGER_CONNECT       ;Open SCM
  .if xax != 0
    mov xbx, xax                                       ;Save SCM handle

    ;Open service
    invoke OpenService, xbx, [xsi].pName, DELETE or SERVICE_STOP

    .if xax != 0
      mov xdi, xax                                     ;Save service handle
      invoke ControlService, xdi, SERVICE_CONTROL_STOP, addr [xsi].Status   ;Attempt stop

      invoke DeleteService, xdi                        ;Delete service
      .if eax == 0
        mov dLastError, $32($invoke(GetLastError))     ;Store error
      .endif
      invoke CloseServiceHandle, xdi                   ;Close service handle
    .else
      mov dLastError, $32($invoke(GetLastError))       ;Store error
    .endif
    invoke CloseServiceHandle, xbx                     ;Close SCM handle
  .else
    mov dLastError, $32($invoke(GetLastError))         ;Store error
  .endif

  mov eax, dLastError                                  ;Return error code
MethodEnd
