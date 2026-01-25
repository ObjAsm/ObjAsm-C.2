; ==================================================================================================
; Title:      NetComClient_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


Object NetComClientProtocol,, NetComProtocol
  RedefineMethod  Init,               POINTER                           ;-> Owner object
  RedefineMethod  OnClosed,           $ObjPtr(NetComConnection)         ;-> NetComConnection
  RedefineMethod  OnConnected,        $ObjPtr(NetComConnection)         ;-> NetComConnection
  RedefineMethod  OnDisconnected,     $ObjPtr(NetComConnection), DWORD  ;-> NetComConnection
  RedefineMethod  OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD

  DefineVariable  ClientLocalAddr,    NETCOMADDR, {AF_INETX, 0} ;Setup Server IP + Port
  DefineVariable  ServerRemoteAddr,   NETCOMADDR, {AF_INETX, DEFAULT_SERVER_LISTENING_PORT}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComClientProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.Init
; Purpose:    Initializes this object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method NetComClientProtocol.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  OCall [xsi].BlackList::NetComAddrCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnClosed
; Purpose:    A client session has, for whatever reason, been terminated.
;             You can override this, perhaps to release extra per client/task resources.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComClientProtocol.OnClosed, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComClientProtocol.OnClose", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComClient).SndDlg::SendDlg.CtlsEnable, TRUE
  ACall xsi.OnClosed, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnConnected
; Purpose:    An outbound connection attempt has completed. When you override this method in a
;             derived object, you should check the value of dError parameter to determine whether
;             the connection succeeded, and possibly queue the first send operation.
;             dError will contain NULL for success, or it will contain a socket error code.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComClientProtocol.OnConnected, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComClientProtocol.OnConnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComClient).SndDlg::SendDlg.CtlsEnable, FALSE
  ACall xsi.OnConnected, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnDisconnected
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
; Return:     Nothing.

Method NetComClientProtocol.OnDisconnected, uses xbx xsi, pConnection:$ObjPtr(NetComConnection), dDirection:DWORD
;  DbgHex pConnection, "NetComClientProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComClient).SndDlg::SendDlg.CtlsEnable, TRUE
  ACall xsi.OnDisconnected, pConnection, dDirection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: Error code.
; Return:     eax = Command.

Method NetComClientProtocol.OnError, uses xbx xsi, pConnection:$ObjPtr(NetComConnection), \
                                                   pIOSockJob:PIO_SOCKJOB, dError:DWORD
;  DbgHex pConnection, "NetComClientProtocol.OnError", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  OCall [xbx].$Obj(NetComClient).SndDlg::SendDlg.CtlsEnable, TRUE
  OCall [xbx].$Obj(NetComClient).SndDlg.ActiveConns::Collection.Delete, pConnection 
  ACall xsi.OnError, pConnection, pIOSockJob, dError
MethodEnd

endif