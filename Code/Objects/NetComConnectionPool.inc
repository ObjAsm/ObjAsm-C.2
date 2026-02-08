; ==================================================================================================
; Title:      NetComConnectionPool.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComConnectionPool objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComConnectionPool implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnectionPool.Done
; Purpose:    Finalize the NetComConnectionPool object.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnectionPool.Done, uses xsi
;  DbgHex pConnection, "NetComConnectionPool.Done"
  SetObject xsi
  ACall xsi.Done
  invoke DeleteCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnectionPool.FreeItem
; Purpose:    Release the memory used by the NetComConnection object.
; Arguments:  Arg1: -> NetComConnection to release.
; Return:     Nothing.

Method NetComConnectionPool.FreeItem, uses xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComConnectionPool.FreeItem"
  SetObject xsi
  mov xax, pConnection
  invoke EnterCriticalSection, addr [xsi].CritSect
;  DbgHex pConnection, "NetComConnectionPool.FreeItem", "NetComConnectionPool"
  dec [xsi].dCount
  mov xax, pConnection
  lea xdx, [xax].$Obj(NetComConnection).ChainItem
  SDLL_Remove xdx, xax, xcx                             ;Remove connection from the chain
  ACall xsi.FreeItem, pConnection                       ;Toss it into the DataPool
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnectionPool.Init
; Purpose:    Initialize the NetComConnectionPool object.
; Arguments:  Arg1: -> Owner.
;             Arg2: Desired maximal capacity.
;             Arg3: -> NetComIOSockJobPool.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnectionPool.Init, uses xsi, pOwner:POINTER, dMaxClients:DWORD, pIOSockJobPool:POINTER
  SetObject xsi
  m2m [xsi].pIOSockJobPool, pIOSockJobPool, xax
  invoke InitializeCriticalSection, addr [xsi].CritSect
  ACall xsi.Init, pOwner, sizeof($Obj(NetComConnection)), dMaxClients, 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnectionPool.NewItem
; Purpose:    Create a new NetComConnection.
; Arguments:  None.
; Return:     xax -> NetComConnection or NULL if failed.

Method NetComConnectionPool.NewItem, uses xbx xsi
  SetObject xsi
  invoke EnterCriticalSection, addr [xsi].CritSect
  ACall xsi.NewItem                                     ;Get a new connection from the pool
  .if xax != NULL
    inc [xsi].dCount
    mov xbx, xax
    New xbx::NetComConnection
    lea xax, [xbx].$Obj(NetComConnection).ChainItem
    mov xdx, [xsi].pOwner
    lea xcx, [xdx].$Obj(NetComEngine).ConnectionChain   ;Get the address of the connection chain
    SDLL_InsertFirst xcx, xax, xdx                      ;Insert this connection in the chain
    invoke LeaveCriticalSection, addr [xsi].CritSect
    mov xax, xbx
  .else
    OCall xsi.ErrorReport, NULL, NCCP_OUT_OF_MEMORY
    invoke LeaveCriticalSection, addr [xsi].CritSect
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnectionPool.Reset
; Purpose:    Restores initial state, releasing the complete allocated memory.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnectionPool.Reset, uses xsi
  SetObject xsi
  invoke EnterCriticalSection, addr [xsi].CritSect
  ACall xsi.Reset
  mov [xsi].dCount, 0
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

endif
