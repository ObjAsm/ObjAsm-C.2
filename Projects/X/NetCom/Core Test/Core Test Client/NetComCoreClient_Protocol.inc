; ==================================================================================================
; Title:      NetComCoreClient_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComCoreClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


Object NetComCoreClientProtocol,, NetComProtocol
  RedefineMethod  Init,               POINTER                     ;-> Owner object (Application)
  RedefineMethod  OnClosed,           $ObjPtr(NetComConnection)
  RedefineMethod  OnConnected,        $ObjPtr(NetComConnection)
  RedefineMethod  OnDisconnected,     $ObjPtr(NetComConnection), DWORD, DWORD
  RedefineMethod  OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD

  DefineVariable  ClientLocalAddr,    NETCOMADDR, {AF_INETX, 0}   ;Setup Server IP + Port
  DefineVariable  ServerRemoteAddr,   NETCOMADDR, {AF_INETX, DEFAULT_SERVER_LISTENING_PORT}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComCoreClientProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClientProtocol.Init
; Purpose:    Initializes this object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method NetComCoreClientProtocol.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  OCall [xsi].BlackList::NetComAddrCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClientProtocol.OnClosed
; Purpose:    A client session has, for whatever reason, been terminated.
;             You can override this, perhaps to release extra per client/task resources.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComCoreClientProtocol.OnClosed, uses xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComCoreClientProtocol.OnClose", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComCoreClient).SndDlg::SendDlg.CtlsEnable, TRUE
  ACall xsi.OnClosed, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClientProtocol.OnConnected
; Purpose:    An outbound connection attempt has completed. When you override this method in a
;             derived object, you should check the value of dError parameter to determine whether
;             the connection succeeded, and possibly queue the first send operation.
;             dError will contain NULL for success, or it will contain a socket error code.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComCoreClientProtocol.OnConnected, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComCoreClientProtocol.OnConnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComCoreClient).SndDlg::SendDlg.CtlsEnable, FALSE
  ACall xsi.OnConnected, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClientProtocol.OnDisconnected
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
;             Arg3: Operation result.
; Return:     Nothing.

Method NetComCoreClientProtocol.OnDisconnected, uses xsi, pConnection:$ObjPtr(NetComConnection), \
                                                          dDirection:DWORD, dResult:DWORD
;  DbgHex pConnection, "NetComCoreClientProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComCoreClient).SndDlg::SendDlg.CtlsEnable, TRUE
  ACall xsi.OnDisconnected, pConnection, dDirection, dResult
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClientProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: Error code.
; Return:     eax = Command.

Method NetComCoreClientProtocol.OnError, uses xbx xsi, pConnection:$ObjPtr(NetComConnection), \
                                                   pIOSockJob:PIO_SOCKJOB, dError:DWORD
;  DbgHex pConnection, "NetComCoreClientProtocol.OnError", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  OCall [xbx].$Obj(NetComCoreClient).SndDlg::SendDlg.CtlsEnable, TRUE
;  OCall [xbx].$Obj(NetComCoreClient).SndDlg.ActiveConns::Collection.Delete, pConnection 
  ACall xsi.OnError, pConnection, pIOSockJob, dError
MethodEnd

endif