; ==================================================================================================
; Title:      SVC_Template_Main.inc
; Author:     G. Friedrich
; Notes:      See SVC_Template.asm
; ==================================================================================================


MAX_PIPE_INSTANCES equ 4
PIPE_BUFFER_SIZE   equ 512


; --------------------------------------------------------------------------------------------------
; Objects:    Derived Services
; Purpose:    Define two test services derived from the base Service object
;             - Setup pName, pDisp, and pDesc on Startup
;             - Handle concurrent client communication via asynchronous named pipes(Service1)
;             - Log activity for Service2
; Notes:      - Supports multiple concurrent clients using a single worker thread(Run)
;             - Each pipe instance uses OVERLAPPED structures for async I/O
;             - WaitForMultipleObjects monitors stop events and pipe connections
;             - DisconnectNamedPipe+ConnectNamedPipe allows pipe reuse

Object Service1,, Service                     ;Service1 derives from base Service
  StaticMethod    Startup                     ;Static initializer: pName, pDisp, pDesc, pPipeName
  RedefineMethod  Run                         ;Main worker thread: handles async pipe communication

  DefineVariable  pPipeName,  PSTRING,  NULL  ;Name of the pipe used for communication
ObjectEnd

Object Service2,, Service                     ;Service2 derives from base Service
  StaticMethod    Startup                     ;Static initializer: sets pName, pDisp, pDesc
  RedefineMethod  Run                         ;Main worker thread: logs messages
ObjectEnd


; ==================================================================================================
; Service1 Implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  ServiceSendUserNotification
; Purpose:    Display a message box to the active user session without waiting for an answer.
;             Intended for use by a service to notify the currently logged-on interactive user.
; Arguments:  Arg1: -> Message text.
;             Arg2: -> Title text.
; Return:     eax = 0 on failure.
; Notes:      This function uses WTSSendMessage to communicate from a service context to a
;             user session. The call is non-blocking and returns immediately.
; --------------------------------------------------------------------------------------------------

ServiceSendUserNotification proc uses xbx xdi, pText:PSTRING, pTitle:PSTRING
  local dSessionId:DWORD, dResponse:DWORD
  local dTextSize:DWORD, dTitleSize:DWORD

  ;Retrieve the session ID of the active console session
  ;This corresponds to the user currently logged on at the physical console
  invoke WTSGetActiveConsoleSessionId

  ;Validate the returned session ID
  ;A value of 0FFFFFFFFh indicates that no active session was found
  .if eax != 0FFFFFFFFh
    mov dSessionId, eax

    ;Determine the size of the message and title strings in bytes
    mov dTextSize,  $32($invoke(StrSize, pText))
    mov dTitleSize, $32($invoke(StrSize, pTitle))

    ;Send a message box to the specified user session
    invoke WTSSendMessage, \
           0, \                                         ;WTS_CURRENT_SERVER_HANDLE
           dSessionId, \                                ;Target session ID
           pTitle, \                                    ;Message box title
           dTitleSize, \                                ;Title length in bytes
           pText, \                                     ;Message text
           dTextSize, \                                 ;Text length in bytes
           MB_OK or MB_ICONINFORMATION, \               ;Message box style
           0, \                                         ;Timeout in seconds (non-blocking)
           addr dResponse, \                            ;Receives user response, if any
           FALSE                                        ;Do not wait for user input
  .endif

  ret                                                   ;Return to caller
ServiceSendUserNotification endp

; --------------------------------------------------------------------------------------------------
; Method:     Service1.Run
; Purpose:    Main worker thread of Service1
;             - Creates multiple asynchronous named pipes for concurrent clients
;             - Monitors pipe events and the service stop event
;             - Handles client commands(PING, STOP, QUERYSTATE) asynchronously
;             - Sends responses to clients and re-arms pipes for new connections
;             - Updates service status to the Service Control Manager(SCM)
; Arguments:  None.
; Return:     Nothing.

Method Service1.Run, uses xbx xdi xsi
  local dCommand:DWORD, dSize:DWORD, WaitHandleArray[2]:HANDLE      
  local pSecDesc:PSECURITY_DESCRIPTOR, SecAttr:SECURITY_ATTRIBUTES ;Security descriptor for pipes
  local PipeHandleArray[MAX_PIPE_INSTANCES]:HANDLE      ;Array of pipe handles
  local EventHandleArray[1 + MAX_PIPE_INSTANCES]:HANDLE ;Array of events(pipes+stop)
  local OverlappedArray[MAX_PIPE_INSTANCES]:OVERLAPPED  ;OVERLAPPED structs for async I/O
  local OverlappedPtrArray[MAX_PIPE_INSTANCES]:POINTER  ;Pointers to OVERLAPPED structs

  DbgText "Service1.Run"                                ;Debug trace
  SetObject xsi                                         ;Set the object context

  ;Convert SDDL string to security descriptor for pipe access
  invoke ConvertStringSecurityDescriptorToSecurityDescriptor, addr cSDDL, SDDL_REVISION_1, \
                                                              addr pSecDesc, 0
  mov SecAttr.nLength, sizeof SecAttr                   ;Set size of SECURITY_ATTRIBUTES
  m2m SecAttr.lpSecurityDescriptor, pSecDesc, xax       ;Assign security descriptor
  mov SecAttr.bInheritHandle, FALSE                     ;Pipe handles are not inheritable

  xor ebx, ebx                                          ;Initialize pipe instance counter
  xor edi, edi                                          ;Initialize OVERLAPPED structure offset

  ;Loop: create MAX_PIPE_INSTANCES named pipes
  .while ebx < MAX_PIPE_INSTANCES
    invoke CreateNamedPipe, [xsi].pPipeName, \
                            PIPE_ACCESS_DUPLEX or FILE_FLAG_OVERLAPPED, \
                            PIPE_TYPE_MESSAGE or PIPE_READMODE_MESSAGE, \
                            MAX_PIPE_INSTANCES, PIPE_BUFFER_SIZE, PIPE_BUFFER_SIZE, \
                            0, addr SecAttr
    mov PipeHandleArray[xbx*sizeof(HANDLE)], xax        ;Save pipe handle

    invoke CreateEvent, NULL, TRUE, FALSE, NULL         ;Create manual-reset event
    mov EventHandleArray[xbx*sizeof(HANDLE)], xax       ;Save event handle

    ;Initialize OVERLAPPED structure for async I/O
    lea xdx, OverlappedArray[xdi]
    mov [xdx].OVERLAPPED.Internal, 0
    mov [xdx].OVERLAPPED.InternalHigh, 0
    mov [xdx].OVERLAPPED.Offset_, 0
    mov [xdx].OVERLAPPED.OffsetHigh, 0
    mov [xdx].OVERLAPPED.hEvent, xax
    mov OverlappedPtrArray[xbx*sizeof(POINTER)], xdx    ;Save pointer to overlapped structure
    add edi, sizeof(OVERLAPPED)                         ;Move to next OVERLAPPED structure

    ;Attempt to connect named pipe asynchronously
    invoke ConnectNamedPipe, PipeHandleArray[xbx*sizeof(HANDLE)], xdx
    .if eax == FALSE
      invoke GetLastError
      .if eax != ERROR_IO_PENDING                       ;Normal async connect pending => continue
        .if eax == ERROR_PIPE_CONNECTED
          ;Client already connected — treat as if connection succeeded
          ;Optionally, signal the event manually to start read immediately
          invoke SetEvent, EventHandleArray[xbx*sizeof(HANDLE)]
        .else
          ;If another error, close pipe and event
          invoke CloseHandle, PipeHandleArray[xbx*sizeof(HANDLE)]
          invoke CloseHandle, EventHandleArray[xbx*sizeof(HANDLE)]
        .endif
      .endif
    .endif

    inc ebx                                             ;Next pipe instance
  .endw

  invoke LocalFree, pSecDesc                            ;Free security descriptor
  
  ;Add stop event as the last event in array
  m2m EventHandleArray[xbx*sizeof(HANDLE)], [xsi].hStopEvent, xax

  ;Set service status: running and accepting stop/shutdown
  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_SHUTDOWN
  mov [xsi].Status.dwCurrentState, SERVICE_RUNNING
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status

  ;Main loop: wait for stop event or pipe activity
  .while TRUE
    invoke WaitForMultipleObjects, MAX_PIPE_INSTANCES + 1, addr EventHandleArray, FALSE, INFINITE
    .break .if eax == WAIT_FAILED                       ;Exit on wait failure

    lea ebx, [eax - WAIT_OBJECT_0]                     ;Compute event index
    .break .if ebx == MAX_PIPE_INSTANCES                ;Stop event triggered

    ;Complete async pipe connection
    invoke GetOverlappedResult, PipeHandleArray[xbx*sizeof(HANDLE)], \
                                OverlappedPtrArray[xbx*sizeof(POINTER)], addr dSize, FALSE

    ;Reset OVERLAPPED for async read
    mov xdi, OverlappedPtrArray[xbx*sizeof(POINTER)]
    mov [xdi].OVERLAPPED.Internal, 0
    mov [xdi].OVERLAPPED.InternalHigh, 0
    mov [xdi].OVERLAPPED.Offset_, 0
    mov [xdi].OVERLAPPED.OffsetHigh, 0
    mrm [xdi].OVERLAPPED.hEvent, EventHandleArray[xbx*sizeof(HANDLE)], xcx
    invoke ResetEvent, xcx

    ;Start async read from pipe
    invoke ReadFile, PipeHandleArray[xbx*sizeof(HANDLE)], addr dCommand, sizeof DWORD, NULL, xdi
    .if eax == FALSE
      invoke GetLastError
      cmp eax, ERROR_IO_PENDING
      jnz PipeReset

      ;Wait for either stop event or read completion
      m2m WaitHandleArray[0], [xsi].hStopEvent, xax
      m2m WaitHandleArray[sizeof(HANDLE)], EventHandleArray[xbx*sizeof(HANDLE)], xax
      invoke WaitForMultipleObjects, 2, addr WaitHandleArray, FALSE, INFINITE
      .break .if eax == WAIT_FAILED
      .break .if eax == WAIT_OBJECT_0                   ;Stop event triggered

      invoke GetOverlappedResult, PipeHandleArray[xbx*sizeof(HANDLE)], \
                                  OverlappedPtrArray[xbx*sizeof(POINTER)], addr dSize, FALSE
      test eax, eax
      jz PipeReset                                      ;Restart pipe on failure
      cmp dSize, sizeof DWORD
      jne PipeReset                                     ;Restart pipe on misformed message
    .endif

    ;Process command received via pipe
    .if dCommand == CMD_PING
      mov dCommand, 100                                 ;PING response
    .elseif dCommand == CMD_STOP
      invoke SetEvent, [xsi].hStopEvent                 ;Signal stop
      mov dCommand, 200                                 ;STOP response
    .elseif dCommand == CMD_QUERYSTATE
      m2m dCommand, [xsi].Status.dwCurrentState, eax    ;Return current state
    .elseif dCommand == CMD_NOTIFICATION
      invoke ServiceSendUserNotification, $OfsCStr("Service recieved a CMD_NOTIFICATION"), \
                                          $OfsCStr("ObjAsm Service - 1")
      mov dCommand, 400                                 ;PING response
    .else
      mov dCommand, 0
    .endif

    ;Reset OVERLAPPED for async write
    mov xdi, OverlappedPtrArray[xbx*sizeof(POINTER)]
    mov [xdi].OVERLAPPED.Internal, 0
    mov [xdi].OVERLAPPED.InternalHigh, 0
    mov [xdi].OVERLAPPED.Offset_, 0
    mov [xdi].OVERLAPPED.OffsetHigh, 0
    mrm [xdi].OVERLAPPED.hEvent, EventHandleArray[xbx*sizeof(HANDLE)], xcx
    invoke ResetEvent, xcx

    ;Write response asynchronously
    invoke WriteFile, PipeHandleArray[xbx*sizeof(HANDLE)], addr dCommand, sizeof DWORD, NULL, xdi
    .if eax == FALSE
      invoke GetLastError
      cmp eax, ERROR_IO_PENDING
      jnz PipeReset

      invoke WaitForMultipleObjects, 2, addr WaitHandleArray, FALSE, INFINITE
      .break .if eax == WAIT_FAILED
      .break .if eax == WAIT_OBJECT_0                   ;Stop event triggered
    .endif

  PipeReset:
    invoke CancelIoEx, PipeHandleArray[xbx*sizeof(HANDLE)], NULL
    invoke DisconnectNamedPipe, PipeHandleArray[xbx*sizeof(HANDLE)] ;Disconnect client
    invoke ResetEvent, EventHandleArray[xbx*sizeof(HANDLE)]         ;Reset pipe event

    ;Re-arm async ConnectNamedPipe for next client
    mov xdx, OverlappedPtrArray[xbx*sizeof(POINTER)]
    mov [xdx].OVERLAPPED.Internal, 0
    mov [xdx].OVERLAPPED.InternalHigh, 0
    mov [xdx].OVERLAPPED.Offset_, 0
    mov [xdx].OVERLAPPED.OffsetHigh, 0
    m2m [xdx].OVERLAPPED.hEvent, EventHandleArray[xbx*sizeof(HANDLE)], xax

    ;Attempt to connect named pipe asynchronously
    invoke ConnectNamedPipe, PipeHandleArray[xbx*sizeof(HANDLE)], xdx
    .if eax == FALSE
      invoke GetLastError
      .if eax != ERROR_IO_PENDING
        .if eax == ERROR_PIPE_CONNECTED
          ;Client already connected — signal the event to handle immediately
          invoke SetEvent, EventHandleArray[xbx*sizeof(HANDLE)]
        .else
          ;Unexpected error — close pipe and event to avoid leaks
          invoke CloseHandle, PipeHandleArray[xbx*sizeof(HANDLE)]
          invoke CloseHandle, EventHandleArray[xbx*sizeof(HANDLE)]
        .endif
      .endif
    .endif
  .endw

  ;Loop: close all handles
  xor ebx, ebx
  .while ebx < MAX_PIPE_INSTANCES
    invoke CloseHandle, PipeHandleArray[xbx*sizeof(HANDLE)]   ;Close pipe
    invoke CloseHandle, EventHandleArray[xbx*sizeof(HANDLE)]  ;Close Event
    inc ebx
  .endw

  OCall xsi.Done                                        ;Signal service completion

  ;Set service status to stopped
  mov [xsi].Status.dwControlsAccepted, 0
  mov [xsi].Status.dwCurrentState, SERVICE_STOPPED
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status
  DbgText "Service1.Run Exit"                           ;Debug trace
MethodEnd

;---------------------------------------------------------------------------------------------------
; Method:     Service1.Startup
; Purpose:    Initialize Service1 metadata
; Arguments:  None
; Return:     Nothing

Method Service1.Startup
  SetObject xcx                                         ;Load Service1 object pointer
  m2m [xcx].pName, offset cServiceName1, xax            ;Assign internal service name
  m2m [xcx].pDisp, offset cServiceDisp1, xdx            ;Assign display name
  m2m [xcx].pDesc, offset cServiceDesc1, xax            ;Assign description string
  m2m [xcx].pPipeName, offset cPipeName1, xax           ;Assign pipe name string
MethodEnd


; ==================================================================================================
; Service2 Implementation
; ==================================================================================================

;---------------------------------------------------------------------------------------------------
; Method:     Service2.Run
; Purpose:    Main worker thread of Service2
;             - Logs activity periodically.
;             - Monitors stop event and exits when triggered.
; Arguments:  None.
; Return:     Nothing.

Method Service2.Run, uses xbx xsi
  DbgText "Service2.Run"                                ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_PAUSE_CONTINUE or \
                                       SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Declare accepted controls
  mov [xsi].Status.dwCurrentState, SERVICE_RUNNING      ;Service running
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status    ;Notify SCM

  .while TRUE
    invoke WaitForSingleObject, [xsi].hStopEvent, 1000  ;Poll stop event
    mov ebx, eax
    invoke LogServiceMessage, $OfsCStrA("Service2.Run was here...")  ;Log message
    .continue .if ebx == WAIT_TIMEOUT                   ;Continue if timeout
    .break                                              ;Exit loop
  .endw

  OCall xsi.Done                                        ;Signal service completion

  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Limit accepted controls
  mov [xsi].Status.dwCurrentState, SERVICE_STOPPED      ;Service stopped
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
  DbgText "Service2.Run Exit"                           ;Debug trace
MethodEnd

;---------------------------------------------------------------------------------------------------
; Method:     Service2.Startup
; Purpose:    Initialize Service2 metadata.
; Arguments:  None.
; Return:     Nothing.

Method Service2.Startup
  SetObject xcx                                         ;Load Service2 object pointer
  m2m [xcx].pName, offset cServiceName2, xax            ;Assign internal service name
  m2m [xcx].pDisp, offset cServiceDisp2, xdx            ;Assign display name
  m2m [xcx].pDesc, offset cServiceDesc2, xax            ;Assign description string
MethodEnd
