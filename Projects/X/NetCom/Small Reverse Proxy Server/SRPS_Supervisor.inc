; ==================================================================================================
; Title:      SRPS_Supervisor.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SRPS_Supervisor objects.
;             Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  NetComSrpsSupervisor
; Purpose: Controls overall status of the NetComEngine

Object NetComSrpsSupervisor,, NetComSupervisor
  RedefineMethod  WorkerJob
ObjectEnd


.code

if IMPLEMENT

; ==================================================================================================
;    NetComSrpsSupervisor implementation
; ==================================================================================================

; Method:     NetComSrpsSupervisor.WorkerJob
; Purpose:    This thread is responsible making all administrative work on the engine.
; Arguments:  None.
; Return:     Nothing.

Method NetComSrpsSupervisor.WorkerJob, uses xbx xdi xsi
  local dConnectionTime:DWORD, dConnectionTimeSize:DWORD, TimeNow:FILETIME
  local dDirection:DWORD

  SetObject xsi
  mov dConnectionTimeSize, sizeof dConnectionTime
  mov dDirection, TRUE

  .while TRUE
    invoke WaitForMultipleObjects, SUPERVISOR_WAITHANDLECOUNT, addr [xsi].WaitHandles, \
                                   FALSE, [xsi].dCycleTime
    .break .if eax == WAIT_OBJECT_0 + NCS_EVENT_INDEX_STOP

  @@Retry:
    mov xbx, [xsi].pOwner
    invoke EnterCriticalSection, addr [xbx].$Obj(NetComEngine).ConnectionPool.CritSect

    lea xdi, [xbx].$Obj(NetComEngine).ConnectionChain
    
    ;Traverse the list in alternating directions
    .if dDirection != FALSE
      mov xbx, [xdi].SDLL_SENTINEL.pFirstItem
      mov dDirection, FALSE
    .else
      mov xbx, [xdi].SDLL_SENTINEL.pLastItem
      mov dDirection, TRUE
    .endif

    .while TRUE
      mov xcx, [xsi].pOwner
      lea xdx, [xcx].$Obj(NetComEngine).ConnectionChain
      .break .if xbx == xdx                                     ;Check for end of chain

      lea xbx, [xbx - offset $Obj(NetComConnection).ChainItem]  ;xbx -> NetComConnection instance

      .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_QUEUE_ACCEPT or NCC_ACCEPTED
        ;Skip acceptors
        
        invoke TryEnterCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
        .if eax == FALSE
          mov xcx, [xsi].pOwner
          invoke LeaveCriticalSection, addr [xcx].$Obj(NetComEngine).ConnectionPool.CritSect
          invoke Sleep, 10
          jmp @@Retry
        .endif

        ;Handle connection timeout
        .if [xsi].dInactivityTimeout != 0                         ;0 means no timeout
          .if ([xbx].$Obj(NetComConnection).LastTime.FILETIME.dwLowDateTime != 0 || \
               [xbx].$Obj(NetComConnection).LastTime.FILETIME.dwLowDateTime != 0)
            invoke GetSystemTimeAsFileTime, addr TimeNow
            mov eax, TimeNow.FILETIME.dwLowDateTime
            sub eax, [xbx].$Obj(NetComConnection).LastTime.FILETIME.dwLowDateTime
            mov edx, TimeNow.FILETIME.dwHighDateTime
            sbb edx, [xbx].$Obj(NetComConnection).LastTime.FILETIME.dwHighDateTime
            sub eax, [xsi].dInactivityTimeout
            sbb edx, 0
            .if SDWORD ptr edx >= 0
;              DbgWarning "Connection Timeout"
;              DbgConnection xbx, "Connection Timeout" 
              OCall xbx::NetComConnection.Disconnect, SD_SEND
              OCall xbx::NetComConnection.QueueDestroy
              OCall xbx::NetComConnection.Close, TRUE
            .endif
          .endif
        .endif
        
        ;Handle backpressure regulating the receive activity
        mov xax, [xbx].$Obj(NetComConnection).pData
        .if xax != NULL
          mov xdi, [xax].SRPS_CONNECTION_DATA.pPeerConnection   ;xdi -> peer connection
          .if xdi != NULL
            invoke TryEnterCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect
            .if eax == FALSE
              mov xcx, [xsi].pOwner
              invoke LeaveCriticalSection, addr [xcx].$Obj(NetComEngine).ConnectionPool.CritSect
              invoke LeaveCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
              invoke Sleep, 10
              jmp @@Retry
            .endif
    
            mov eax, [xbx].$Obj(NetComConnection).dSndQueuedIOJobs
            .ifBitClr [xdi].$Obj(NetComConnection).dFlags, NCC_RCV_PAUSED
              .if eax >= [xbx].$Obj(NetComConnection).dSndHighWtrMrk
                ;Stop receiving
                BitSet [xdi].$Obj(NetComConnection).dFlags, NCC_RCV_PAUSED
                DbgText "NCC_RCV_PAUSED"
              .endif
            .else
              .if eax <= [xbx].$Obj(NetComConnection).dSndLowWtrMrk
                ;Reenable receive IOJobs
                BitClr [xdi].$Obj(NetComConnection).dFlags, NCC_RCV_PAUSED
                .if [xdi].$Obj(NetComConnection).dRcvQueuedIOJobs == 0
                  ;If nothing is queued, issue a receive IOJob
                  OCall xdi::NetComConnection.QueueReceive
                .endif
              .endif
            .endif
            invoke LeaveCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect
          .endif
        .endif
        invoke LeaveCriticalSection, addr [xbx].$Obj(NetComConnection).CritSect
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
          mov xdx, xbx
          
          ;Get next connection
          .if dDirection == FALSE                       ;Inverted logic, we switched the direction
            mov xbx, [xbx + offset $Obj(NetComConnection).ChainItem].SDLL_ITEM.pNextItem
          .else
            mov xbx, [xbx + offset $Obj(NetComConnection).ChainItem].SDLL_ITEM.pPrevItem
          .endif
          OCall [xcx].$Obj(NetComEngine).ConnectionPool::NetComConnectionPool.FreeItem, xdx
          .continue
        .endif
      .endif

    @@Next:      
      ;Get next connection
      .if dDirection == FALSE                           ;Inverted logic, we switched the direction
        mov xbx, [xbx + offset $Obj(NetComConnection).ChainItem].SDLL_ITEM.pNextItem
      .else
        mov xbx, [xbx + offset $Obj(NetComConnection).ChainItem].SDLL_ITEM.pPrevItem
      .endif
    .endw

    mov xcx, [xsi].pOwner
    invoke LeaveCriticalSection, addr [xcx].$Obj(NetComEngine).ConnectionPool.CritSect
  .endw
MethodEnd



endif
