; ==================================================================================================
; Title:      NetComClient_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


DEFAULT_SERVER_LISTENING_PORT equ $htons(25773)

Object NetComClientProtocol,, NetComProtocol
  RedefineMethod  Init,               POINTER                       ;-> Owner
  RedefineMethod  OnClosed,           $ObjPtr(NetComConnection)     ;-> NetComConnection
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
  DbgHex pConnection, "NetComClientProtocol.OnClose", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_CONNECT
  invoke EnableWindow, xax, TRUE
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_DISCONNECT
  invoke EnableWindow, xax, FALSE
  ACall xsi.OnClosed, pConnection
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