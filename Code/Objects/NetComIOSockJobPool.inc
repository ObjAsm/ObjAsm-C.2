; ==================================================================================================
; Title:      NetComIOSockJobPool.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComIOSockJobPool objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComIOSockJobPool implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOSockJobPool.Done
; Purpose:    Finalize the NetComIOSockJobPool object.
; Arguments:  None.
; Return:     Nothing.

Method NetComIOSockJobPool.Done, uses xsi
;  DbgText "NetComIOSockJobPool.Done"
  SetObject xsi
  ACall xsi.Done
  invoke DeleteCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOSockJobPool.FreeItem
; Purpose:    Release the memory used by the IO_SOCKJOB.
; Arguments:  Arg1: -> IO_SOCKJOB to release.
; Return:     Nothing.

Method NetComIOSockJobPool.FreeItem, uses xsi, pIOSockJob:PIO_SOCKJOB
  SetObject xsi
;  DbgText "NetComIOSockJobPool.FreeItem"
  invoke EnterCriticalSection, addr [xsi].CritSect
  dec [xsi].dCount
  ACall xsi.FreeItem, pIOSockJob                        ;Return it to the DataPool
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOSockJobPool.Init
; Purpose:    Initialize the NetComIOSockJobPool object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial allocated NetComIOJobs.
;             Arg3: Buffer size of each NetComIOJob. Usually MSS_ETHERNET_IPVX (MTU - Header size).
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComIOSockJobPool.Init, uses xsi, pOwner:POINTER, dInitJobCount:DWORD, dBufferSize:DWORD
  SetObject xsi
  invoke InitializeCriticalSection, addr [xsi].CritSect
  
  mrm [xsi].dBufferSize, dBufferSize, eax
  add eax, sizeof(IO_SOCKJOB)                           ;Add the header size to the payload size
  ACall xsi.Init, pOwner, eax, dInitJobCount, 1         ;We need an alignment of 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOSockJobPool.NewItem
; Purpose:    Allocate a new IO_SOCKJOB from DataPool.
; Arguments:  Arg1: Operation type.
; Return:     xax -> New IO_SOCKJOB or NULL if failed.

Method NetComIOSockJobPool.NewItem, uses xbx xsi, wOperation:WORD
  SetObject xsi
;  DbgText "NetComIOSockJobPool.NewItem"
  invoke EnterCriticalSection, addr [xsi].CritSect
  ACall xsi.NewItem
  .if xax != NULL
    inc [xsi].dCount
    mov xbx, xax
    OCall xsi.ResetIOJob, xax, wOperation
    invoke LeaveCriticalSection, addr [xsi].CritSect
    mov xax, xbx
  .else
    invoke LeaveCriticalSection, addr [xsi].CritSect
    OCall xsi.ErrorReport, NULL, NCJP_OUT_OF_MEMORY
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOSockJobPool.Reset
; Purpose:    Restores initial state, releasing the complete allocated memory.
; Arguments:  None.
; Return:     Nothing.

Method NetComIOSockJobPool.Reset, uses xsi
  SetObject xsi
  invoke EnterCriticalSection, addr [xsi].CritSect
  ACall xsi.Reset
  mov [xsi].dCount, 0
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOSockJobPool.ResetIOJob
; Purpose:    Reset an IO_SOCKJOB.
; Arguments:  Arg1: -> IO_SOCKJOB.
;             Arg2: Operation type.
; Return:     eax -> IO_SOCKJOB.

Method NetComIOSockJobPool.ResetIOJob,, pIOSockJob:PIO_SOCKJOB, wOperation:WORD
  SetObject xcx
  ?mov xdx, pIOSockJob
  mov xax, xdx
  add xdx, sizeof IO_SOCKJOB
  mov [xax].IO_SOCKJOB.WSABuf.buf, xdx
  m2m [xax].IO_SOCKJOB.WSABuf.len, [xcx].dBufferSize, edx
  xor ecx, ecx
  m2m [xax].IO_SOCKJOB.wOperation, wOperation, dx
  mov [xax].IO_SOCKJOB.pNextItem, xcx
  mov [xax].IO_SOCKJOB.pPrevItem, xcx
  mov [xax].IO_SOCKJOB.dBytesConsumed, ecx
  mov [xax].IO_SOCKJOB.wFlags, cx
  mov [xax].IO_SOCKJOB.Ovl.Internal, xcx
  mov [xax].IO_SOCKJOB.Ovl.InternalHigh, xcx
  mov [xax].IO_SOCKJOB.Ovl.Offset_, ecx
  mov [xax].IO_SOCKJOB.Ovl.OffsetHigh, ecx
  mov [xax].IO_SOCKJOB.Ovl.hEvent, xcx
MethodEnd

endif
