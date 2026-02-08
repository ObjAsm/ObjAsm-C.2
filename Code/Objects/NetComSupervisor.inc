; ==================================================================================================
; Title:      NetComSupervisor.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComSupervisor objects.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

;NetComSupervisor 
NCS_EVENT_INDEX_TIMER   equ   0
NCS_EVENT_INDEX_RUN     equ   1
NCS_EVENT_INDEX_STOP    equ   2


; ==================================================================================================
;    NetComSupervisor implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComSupervisor.Done
; Purpose:    Finalize this object.
; Arguments:  None.
; Return:     Nothing.

Method NetComSupervisor.Done, uses xsi
  SetObject xsi
  invoke SetEvent, [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_STOP*sizeof(HANDLE)]
  invoke WaitForSingleObject, [xsi].hWorker, 4000
  .if eax == WAIT_TIMEOUT
    invoke TerminateThread, [xsi].hWorker, INVALID_HANDLE_VALUE
  .endif
  invoke CloseHandle, [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_TIMER*sizeof(HANDLE)]
  invoke CloseHandle, [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_RUN*sizeof(HANDLE)]
  invoke CloseHandle, [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_STOP*sizeof(HANDLE)]
  
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSupervisor.Init
; Purpose:    Initialize this object.
; Arguments:  Arg1: -> NetComEngine.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComSupervisor.Init, uses xsi, pOwner:POINTER
  local dRetValue:DWORD, DueTime

  SetObject xsi
  mov dRetValue, 0
  ACall xsi.Init, pOwner
  invoke CreateWaitableTimer, NULL, FALSE, NULL         ;Manual-reset = FALSE
  mov [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_TIMER*sizeof(HANDLE)], xax
  invoke SetWaitableTimer, xax, NULL, 500, NULL, NULL, FALSE

  invoke CreateEvent, NULL, FALSE, FALSE, NULL          ;Auto-reset event
  mov [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_RUN*sizeof(HANDLE)], xax
  invoke CreateEvent, NULL, FALSE, FALSE, NULL          ;Auto-reset event
  mov [xsi].WorkerWaitHandles[NCS_EVENT_INDEX_STOP*sizeof(HANDLE)], xax
  
  invoke CreateThread, 0, 16*1024, $MethodAddr(NetComSupervisor.Worker), xsi, 0, NULL
  .if xax == 0
    mov dRetValue, $32($invoke(GetLastError))
    OCall xsi.ErrorReport, NULL, NCE_THREAD_CREATION_FAILED
    DbgSockError "NetComSupervisor.Init - Failed to create supervisor thread", dRetValue
    ExitMethod
  .endif
  mov [xsi].hWorker, xax
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSupervisor.Worker
; Purpose:    This thread is responsible making all administrative work on the engine.
; Arguments:  None.
; Return:     Nothing.

Method NetComSupervisor.Worker, uses xbx xdi xsi
  local dConnectionTime:DWORD, dConnectionTimeSize:DWORD, SW:$Obj(StopWatch)
  local dLastBytesIn:DWORD, dLastBytesOut:DWORD, dBytesIn:DWORD, dBytesOut:DWORD, dElapsedTime:DWORD
  local pConnection:$ObjPtr(NetComConnection)

;  SetObject xsi
;  mov dConnectionTimeSize, sizeof dConnectionTime
;  New SW::StopWatch
;  OCall xax::StopWatch.Init, xsi
;  m2z DWORD ptr [SW.$Obj(StopWatch).r8Resolution]
;  mov DWORD ptr [SW.$Obj(StopWatch).r8Resolution + 4], 408F4000h    ;REAL8 = 1000.0
;  m2z dLastBytesIn
;  m2z dLastBytesOut
;
;  .repeat
;    OCall SW::StopWatch.Reset
;    OCall SW::StopWatch.Start
;
;      lea xdi, [xsi].ConnectionChain
;      mov xbx, [xdi].SDLL_SENTINEL.pFirstItem
;      .while xbx != xdi                                             ;Check for end of chain
;        lea xbx, [xbx - offset $Obj(NetComConnection).ChainItem]    ;xbx -> NetComConnection instance
;        mov pConnection, xbx
;
;        .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_CLOSED
;          ;Check all open connections for a possible attack
;          ;We want to check if a NetComConnection timeouts
;
;;          .if [xbx].$Obj(NetComConnection).dRcvLstElpsdTime != -1           ;Only established connections
;;            .if [xbx].$Obj(NetComConnection).ObjLock.dLockCount == 0    ;Skip locked connections
;;              .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_ABORT  ;Not processed before?
;;                invoke getsockopt, [xbx].$Obj(NetComConnection).hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
;;                                   addr dConnectionTime, addr dConnectionTimeSize
;;                DbgOnSockError "ERROR on getsockopt SO_CONNECT_TIME"
;;                mov eax, dConnectionTime
;;                sub eax, [xbx].$Obj(NetComConnection).dRcvLstElpsdTime
;;                mov xcx, [xbx].$Obj(NetComConnection).pProtocol
;;                mov edx, [xcx].$Obj(NetComProtocol).dTimeoutRcv
;;                .if edx != 0 && eax >= edx
;;                  OCall xcx::NetComProtocol.OnTimeouted, xbx
;;                  .if eax == PROT_CMD_CLOSE
;;                    OCall xbx::NetComConnection.QueueDestroy
;;                  .endif
;;                .endif
;;              .endif
;;            .endif
;;          .endif
;        .endif
;
;;        ;Check for disconnection or closure
;;        mov eax, [xbx].$Obj(NetComConnection).dFlags
;;        .ifBitClr eax, NCC_DESTROYED
;;          .ifBitSet eax, NCC_QUEUE_DESTROY
;;            and eax, NCC_DISCONNECTED
;;            .if eax == NCC_DISCONNECTED
;;              .if [xbx].$Obj(NetComConnection).dPendingIOJobs == 0
;;                OCall xbx::NetComConnection.Reset
;;              .endif
;;            .endif
;;          .endif
;;        .endif
;;
;;        mov eax, [xbx].$Obj(NetComConnection).dFlags
;;
;        ;Move to next Connection now, in case xbx is freed by the coming code
;        mov xbx, POINTER ptr [xbx + offset $Obj(NetComConnection).ChainItem]
;;
;;        .ifBitClr eax, NCC_FREED
;;          .ifBitSet eax, NCC_FREE_QUEUED
;;            .ifBitClr eax, NCC_DESTROYED
;;              and eax, NCC_DISCONNECTED
;;              .if eax == NCC_DISCONNECTED
;;                OCall pConnection::NetComConnection.Reset
;;              .endif
;;            .endif
;;            OCall xsi.FreeConnection, pConnection
;;          .endif
;;        .endif
;
;      .endw
;
;    invoke Sleep, 500
;
;    ;Compute input and output transfer rates
;    OCall SW::StopWatch.Stop
;    OCall SW::StopWatch.GetTime                                 ;edx should be always zero
;    mov dElapsedTime, eax
;
;    mrm dBytesIn, [xsi].dBytesIn, eax
;    sub eax, dLastBytesIn                                       ;Get net value
;    shl eax, 3                                                  ;Convert to bits
;    m2m dLastBytesIn, dBytesIn, edx                             ;Save value
;    xor edx, edx                                                ;Prep for div
;    div dElapsedTime
;    mov [xsi].dRateIn, eax
;
;    mrm dBytesOut, [xsi].dBytesOut, eax
;    sub eax, dLastBytesOut                                      ;Get net value
;    shl eax, 3                                                  ;Convert to bits
;    m2m dLastBytesOut, dBytesOut, edx                           ;Save value
;    xor edx, edx                                                ;Prep for div
;    div dElapsedTime
;    mov [xsi].dRateOut, eax
;
;  .until [xsi].Workers.dCount == 0
;
;  OCall SW::StopWatch.Done
MethodEnd



endif
