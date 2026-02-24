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
NCS_EVENT_INDEX_RUN     equ   0
NCS_EVENT_INDEX_STOP    equ   1


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
  invoke SetEvent, [xsi].WaitHandles[NCS_EVENT_INDEX_STOP*sizeof(HANDLE)]
  invoke WaitForSingleObject, [xsi].hWorker, 4000
  .if eax == WAIT_TIMEOUT
    invoke TerminateThread, [xsi].hWorker, INVALID_HANDLE_VALUE
  .endif
  invoke CloseHandle, [xsi].WaitHandles[NCS_EVENT_INDEX_RUN*sizeof(HANDLE)]
  invoke CloseHandle, [xsi].WaitHandles[NCS_EVENT_INDEX_STOP*sizeof(HANDLE)]

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSupervisor.Init
; Purpose:    Initialize this object.
; Arguments:  Arg1: -> NetComEngine.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComSupervisor.Init, uses xsi, pOwner:POINTER
  local dRetValue:DWORD

  SetObject xsi
  mov dRetValue, 0
  ACall xsi.Init, pOwner
  invoke CreateEvent, NULL, FALSE, FALSE, NULL          ;Auto-reset event
  mov [xsi].WaitHandles[NCS_EVENT_INDEX_RUN*sizeof(HANDLE)], xax
  invoke CreateEvent, NULL, FALSE, FALSE, NULL          ;Auto-reset event
  mov [xsi].WaitHandles[NCS_EVENT_INDEX_STOP*sizeof(HANDLE)], xax

  invoke CreateThread, 0, 16*1024, $MethodAddr(NetComSupervisor.WorkerJob), xsi, 0, NULL
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
; Method:     NetComSupervisor.WorkerJob
; Purpose:    This thread is responsible making all administrative work on the engine.
; Arguments:  None.
; Return:     Nothing.

Method NetComSupervisor.WorkerJob, uses xbx xdi xsi
  local dConnectionTime:DWORD, dConnectionTimeSize:DWORD
  local pConnection:$ObjPtr(NetComConnection), TimeNow:FILETIME, dDirection:DWORD

  SetObject xsi
  mov dConnectionTimeSize, sizeof dConnectionTime
  mov dDirection, FALSE

  .while TRUE
    invoke WaitForMultipleObjects, SUPERVISOR_WAITHANDLECOUNT, addr [xsi].WaitHandles, \
                                   FALSE, [xsi].dCycleTime
    .break .if eax == WAIT_OBJECT_0 + NCS_EVENT_INDEX_STOP

  @@Retry:
    mov xbx, [xsi].pOwner
    invoke EnterCriticalSection, addr [xbx].$Obj(NetComEngine).ConnectionPool.CritSect

    lea xdi, [xbx].$Obj(NetComEngine).ConnectionChain
    
    ;Traverse the list from alternating directions
    .if dDirection == TRUE
      mov xbx, [xdi].SDLL_SENTINEL.pFirstItem
      mov dDirection, FALSE
    .else
      mov xbx, [xdi].SDLL_SENTINEL.pLastItem
      mov dDirection, TRUE
    .endif

    .while xbx != xdi                                   ;Check for end of chain
      lea xbx, [xbx - offset $Obj(NetComConnection).ChainItem]    ;xbx -> NetComConnection instance
      mov pConnection, xbx

      .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_QUEUE_ACCEPT or NCC_ACCEPTED
        ;Skip acceptors
        .if [xsi].dTimeout != 0                         ;0 means no timeout
          invoke TryEnterCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
          .if eax == FALSE
            mov xcx, [xsi].pOwner
            invoke LeaveCriticalSection, addr [xcx].$Obj(NetComEngine).ConnectionPool.CritSect
            invoke Sleep, 10
            jmp @@Retry
          .endif
          .if ([xbx].$Obj(NetComConnection).LastTime.FILETIME.dwLowDateTime != 0 || \
               [xbx].$Obj(NetComConnection).LastTime.FILETIME.dwLowDateTime != 0)
            invoke GetSystemTimeAsFileTime, addr TimeNow
            mov eax, TimeNow.FILETIME.dwLowDateTime
            sub eax, [xbx].$Obj(NetComConnection).LastTime.FILETIME.dwLowDateTime
            mov edx, TimeNow.FILETIME.dwHighDateTime
            sbb edx, [xbx].$Obj(NetComConnection).LastTime.FILETIME.dwHighDateTime
            sub eax, [xsi].dTimeout
            sbb edx, 0
            .if SDWORD ptr edx >= 0
;              DbgWarning "Connection Timeout"
;              DbgConnection xbx, "Connection Timeout" 
              OCall xbx::NetComConnection.Disconnect, SD_SEND
              OCall xbx::NetComConnection.QueueDestroy
              OCall xbx::NetComConnection.Close, TRUE
            .endif
          .endif
          invoke LeaveCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
        .endif
      .endif

      ;If the connection is flagged for destruction, proceed ONLY if the
      ;connection has no pending IOJobs
      .ifBitSet [xbx].$Obj(NetComConnection).dFlags, NCC_QUEUE_DESTROY
        .if [xbx].$Obj(NetComConnection).dPendingIOJobs == 0
          invoke TryEnterCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
          .if eax == FALSE
            mov xcx, [xsi].pOwner
            invoke LeaveCriticalSection, addr [xcx].$Obj(NetComEngine).ConnectionPool.CritSect
            invoke Sleep, 10
            jmp @@Retry
          .endif
          OCall xbx::NetComConnection.FreeRessources    ;Socket is closed here
          invoke LeaveCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
          OCall xbx::NetComConnection.Done
          mov xcx, [xsi].pOwner
          mov xbx, POINTER ptr [xbx + offset $Obj(NetComConnection).ChainItem]  ;-> Next connection
          OCall [xcx].$Obj(NetComEngine).ConnectionPool::NetComConnectionPool.FreeItem, pConnection
          .continue
        .endif
      .endif
      
      mov xbx, POINTER ptr [xbx + offset $Obj(NetComConnection).ChainItem]
    .endw
    mov xbx, [xsi].pOwner
    invoke LeaveCriticalSection, addr [xbx].$Obj(NetComEngine).ConnectionPool.CritSect
  .endw
MethodEnd

endif
