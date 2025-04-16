; ==================================================================================================
; Title:      NetComClient_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


Object NetComClientProtocol,, NetComProtocol
  RedefineMethod  Init,               POINTER, PSTRING              ;-> Owner, -> Service name
  RedefineMethod  OnClose,            $ObjPtr(NetComConnection)     ;-> NetComConnection
  RedefineMethod  OnConnect,          $ObjPtr(NetComConnection)     ;-> NetComConnection
  RedefineMethod  OnDisconnect,       $ObjPtr(NetComConnection)     ;-> NetComConnection
  RedefineMethod  OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD
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
;             Arg2: -> Service name or Port number as a string.
; Return:     Nothing.

Method NetComClientProtocol.Init, uses xsi, pOwner:POINTER, pServiceName:PSTRING
  SetObject xsi
  ACall xsi.Init, pOwner, pServiceName
  OCall [xsi].BlackList::NetComAddrCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnClose
; Purpose:    A client session has, for whatever reason, been terminated.
;             You can override this, perhaps to release extra per client/task resources.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComClientProtocol.OnClose, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComClientProtocol.OnClose", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_CONNECT
  invoke EnableWindow, xax, TRUE
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_DISCONNECT
  invoke EnableWindow, xax, FALSE
  ACall xsi.OnClose, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnConnect
; Purpose:    An outbound connection attempt has completed. When you override this method in a
;             derived object, you should check the value of dError parameter to determine whether
;             the connection succeeded, and possibly queue the first send operation.
;             dError will contain NULL for success, or it will contain a socket error code.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComClientProtocol.OnConnect, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComClientProtocol.OnConnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  mov [xbx].$Obj(%APP_NAME).SndDlg.dFlags, 0
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_CONNECT
  invoke EnableWindow, xax, FALSE
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_DISCONNECT
  invoke EnableWindow, xax, TRUE
  ACall xsi.OnConnect, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClientProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = Command.

Method NetComClientProtocol.OnDisconnect, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComClientProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  mov [xbx].$Obj(%APP_NAME).SndDlg.dFlags, 0
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_CONNECT
  invoke EnableWindow, xax, TRUE
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_DISCONNECT
  invoke EnableWindow, xax, FALSE
  ACall xsi.OnDisconnect, pConnection
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
  DbgHex pConnection, "NetComClientProtocol.OnError", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  mov [xbx].$Obj(%APP_NAME).SndDlg.dFlags, 0
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_CONNECT
  invoke EnableWindow, xax, TRUE
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_DISCONNECT
  invoke EnableWindow, xax, FALSE
  ACall xsi.OnError, pConnection, pIOSockJob, dError
MethodEnd

endif