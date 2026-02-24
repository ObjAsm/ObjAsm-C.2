; ==================================================================================================
; Title:      NetComIOJobPool.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComIOJobPool objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComIOJobPool implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOJobPool.Done
; Purpose:    Finalize the NetComIOJobPool object.
; Arguments:  None.
; Return:     Nothing.

Method NetComIOJobPool.Done, uses xsi
;  DbgText "NetComIOJobPool.Done"
  SetObject xsi
  ACall xsi.Done
  invoke DeleteCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOJobPool.FreeItem
; Purpose:    Release the memory used by the IOJOB.
; Arguments:  Arg1: -> IOJOB to release.
; Return:     Nothing.

Method NetComIOJobPool.FreeItem, uses xsi, pIOJob:PIOJOB
  SetObject xsi
;  DbgText "NetComIOJobPool.FreeItem"
  invoke EnterCriticalSection, addr [xsi].CritSect
  dec [xsi].dCount
  ACall xsi.FreeItem, pIOJob                        ;Return it to the DataPool
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOJobPool.Init
; Purpose:    Initialize the NetComIOJobPool object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial allocated NetComIOJobs.
;             Arg3: Buffer size of each NetComIOJob. Usually MSS_ETHERNET_IPVX (MTU - Header size).
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComIOJobPool.Init, uses xsi, pOwner:POINTER, dInitJobCount:DWORD, dBufferSize:DWORD
  SetObject xsi
  invoke InitializeCriticalSectionEx, addr [xsi].CritSect, 4000, 0

  mrm [xsi].dBufferSize, dBufferSize, eax
  add eax, sizeof(IOJOB)                           ;Add the header size to the payload size
  ACall xsi.Init, pOwner, eax, dInitJobCount, 1         ;We need an alignment of 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOJobPool.NewItem
; Purpose:    Allocate a new IOJOB from DataPool.
; Arguments:  Arg1: Operation type.
; Return:     xax -> New IOJOB or NULL if failed.

Method NetComIOJobPool.NewItem, uses xbx xsi, wOperation:WORD
  SetObject xsi
;  DbgText "NetComIOJobPool.NewItem"
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
; Method:     NetComIOJobPool.Reset
; Purpose:    Restores initial state, releasing the complete allocated memory.
; Arguments:  None.
; Return:     Nothing.

Method NetComIOJobPool.Reset, uses xsi
  SetObject xsi
  invoke EnterCriticalSection, addr [xsi].CritSect
  ACall xsi.Reset
  mov [xsi].dCount, 0
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOJobPool.ResetIOJob
; Purpose:    Reset an IOJOB.
; Arguments:  Arg1: -> IOJOB.
;             Arg2: Operation type.
; Return:     eax -> IOJOB.

Method NetComIOJobPool.ResetIOJob,, pIOJob:PIOJOB, wOperation:WORD
  SetObject xcx
  ?mov xdx, pIOJob
  mov xax, xdx
  add xdx, sizeof IOJOB
  mov [xax].IOJOB.WSABuf.buf, xdx
  m2m [xax].IOJOB.WSABuf.len, [xcx].dBufferSize, edx
  xor ecx, ecx
  m2m [xax].IOJOB.wOperation, wOperation, dx
  mov [xax].IOJOB.pNextItem, xcx
  mov [xax].IOJOB.pPrevItem, xcx
  mov [xax].IOJOB.dBytesConsumed, ecx
  mov [xax].IOJOB.wFlags, cx
  mov [xax].IOJOB.Ovl.Internal, xcx
  mov [xax].IOJOB.Ovl.InternalHigh, xcx
  mov [xax].IOJOB.Ovl.Offset_, ecx
  mov [xax].IOJOB.Ovl.OffsetHigh, ecx
  mov [xax].IOJOB.Ovl.hEvent, xcx
MethodEnd

endif
