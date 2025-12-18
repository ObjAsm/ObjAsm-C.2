; ==================================================================================================
; Title:      SVC_Template_Main.inc
; Author:     G. Friedrich
; Notes:      See SVC_Template.asm.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Objects:    Derived Services
; Purpose:    2 test services derived from Service.
;             They setup pName, pDisp and pDesc on Startup.

Object Service1,, Service                              ;Service1 derives from base Service
  StaticMethod      Startup                            ;Static initializer for service metadata
  RedefineMethod    Run                                ;Main service execution thread
ObjectEnd

Object Service2,, Service                              ;Service2 derives from base Service
  StaticMethod      Startup                            ;Static initializer for service metadata
  RedefineMethod    Run                                ;Main service execution thread
ObjectEnd


.code
; ==================================================================================================
;    Service1 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Service1.Run
; Purpose:    Main worker thread.
; Arguments:  None.
; Return:     Nothing.

Method Service1.Run, uses xbx xsi
  DbgText "Entering Service1.Run"                       ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_PAUSE_CONTINUE or \
                                       SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Declare accepted controls
  mov [xsi].Status.dwCurrentState, SERVICE_RUNNING      ;Service running
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status    ;Notify SCM
  .while TRUE
    invoke WaitForSingleObject, [xsi].hStopEvent, 1000  ;Poll stop event
    mov ebx, eax
    DbgDec eax, "WaitForSingleObject result from Service1.Run"   ;Debug wait result
    invoke LogServiceMessage, $OfsCStrA("Service1.Run was here...")
    .continue .if ebx == WAIT_TIMEOUT                   ;Continue if timeout

    mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Limit controls
    mov [xsi].Status.dwCurrentState, SERVICE_STOPPED    ;Stopped
    invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
    xor eax, eax                                        ;Return code 0
    .break                                              ;Exit loop
  .endw
  DbgText "Exiting Service1.Run"                         ;Debug trace
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service1.Startup
; Purpose:    Service Setup.
; Arguments:  None.
; Return:     Nothing.

Method Service1.Startup
  SetObject xcx                                        ;Load Service1 object pointer
  m2m [xcx].pName, offset cServiceName1, xax           ;Assign internal service name
  m2m [xcx].pDisp, offset cServiceDisp1, xdx           ;Assign display name
  m2m [xcx].pDesc, offset cServiceDesc1, xax           ;Assign description string
MethodEnd


; ==================================================================================================
;    Service2 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Service2.Run
; Purpose:    Main worker thread.
; Arguments:  None.
; Return:     Nothing.

Method Service2.Run, uses xbx xsi
  DbgText "Entering Service2.Run"                       ;Debug trace
  SetObject xsi                                         ;Load object pointer
  mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_PAUSE_CONTINUE or \
                                       SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Declare accepted controls
  mov [xsi].Status.dwCurrentState, SERVICE_RUNNING      ;Service running
  invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status    ;Notify SCM
  .while TRUE
    invoke WaitForSingleObject, [xsi].hStopEvent, 1000  ;Poll stop event
    mov ebx, eax
    DbgDec eax, "WaitForSingleObject result from Service2.Run"   ;Debug wait result
    invoke LogServiceMessage, $OfsCStrA("Service2.Run was here...")
    .continue .if ebx == WAIT_TIMEOUT                   ;Continue if timeout

    mov [xsi].Status.dwControlsAccepted, SERVICE_ACCEPT_PRESHUTDOWN or SERVICE_ACCEPT_SHUTDOWN
                                                        ;Limit controls
    mov [xsi].Status.dwCurrentState, SERVICE_STOPPED    ;Stopped
    invoke SetServiceStatus, [xsi].hServiceStatus, addr [xsi].Status  ;Notify SCM
    xor eax, eax                                        ;Return code 0
    .break                                              ;Exit loop
  .endw
  DbgText "Exiting Service2.Run"                        ;Debug trace
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Service2.Startup
; Purpose:    Service Setup.
; Arguments:  None.
; Return:     Nothing.

Method Service2.Startup
  SetObject xcx                                        ;Load Service2 object pointer
  m2m [xcx].pName, offset cServiceName2, xax           ;Assign internal service name
  m2m [xcx].pDisp, offset cServiceDisp2, xdx           ;Assign display name
  m2m [xcx].pDesc, offset cServiceDesc2, xax           ;Assign description string
MethodEnd
