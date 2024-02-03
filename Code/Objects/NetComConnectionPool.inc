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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComConnectionPool.FreeItem
; Purpose:    Finalize the NetComConnectionPool object.
; Arguments:  Arg1: -> NetComConnection to free.
; Return:     Nothing.

Method NetComConnectionPool.FreeItem, uses xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComConnectionPool.FreeItem"
  SetObject xsi
  LockObjectAccess [xsi].$Obj(NetComConnectionPool)
    dec [xsi].dCount
    mov xax, [xsi].pOwner
    mov xdx, pConnection
    lea xdx, [xdx].$Obj(NetComConnection).ChainItem
    SDLL_Remove xdx, xax                                ;Remove connection from the chain
    ACall xsi.FreeItem, pConnection                     ;Return it to the DataPool
  UnlockObjectAccess [xsi].$Obj(NetComConnectionPool)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComConnectionPool.Init
; Purpose:    Initialize the NetComConnectionPool object.
; Arguments:  Arg1: -> Owner.
;             Arg2: Desired maximal capacity.
;             Arg3: -> NetComIOSockJobPool.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnectionPool.Init,, pOwner:POINTER, dMaxClients:DWORD, pIOSockJobPool:POINTER
  SetObject xcx
  m2m [xcx].pIOSockJobPool, pIOSockJobPool, xax
  ACall xcx.Init, pOwner, sizeof $Obj(NetComConnection), dMaxClients, 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComConnectionPool.NewItem
; Purpose:    Create a new NetComConnection.
; Arguments:  None.
; Return:     xax -> NetComConnection or NULL if failed.

Method NetComConnectionPool.NewItem, uses xbx xsi
  SetObject xsi
  LockObjectAccess [xsi].$Obj(NetComConnectionPool)
  ACall xsi.NewItem                                     ;Get a new connection from the pool
  .if xax != NULL
    inc [xsi].dCount
    mov xbx, xax
    New xbx::NetComConnection
    lea xax, [xbx].$Obj(NetComConnection).ChainItem
    mov xdx, [xsi].pOwner
    lea xcx, [xdx].$Obj(NetComEngine).ConnectionChain   ;Get the address of the connection chain
    SDLL_InsertFirst xcx, xax, xdx                      ;Insert this connection in the chain
    UnlockObjectAccess [xsi].$Obj(NetComConnectionPool)
    mov xax, xbx
  .else
    UnlockObjectAccess [xsi].$Obj(NetComConnectionPool)
    OCall xsi.ErrorReport, NULL, NCCP_OUT_OF_MEMORY
    xor eax, eax
  .endif
MethodEnd

endif
