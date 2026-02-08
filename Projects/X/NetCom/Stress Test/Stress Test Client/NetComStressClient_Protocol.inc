; ==================================================================================================
; Title:      NetComStressClient_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComStressClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


DEFAULT_SERVER_LISTENING_PORT equ $htons(25773)

Object NetComStressClientProtocol,, NetComProtocol
  RedefineMethod  Init,               POINTER                       ;-> Owner
  RedefineMethod  OnClosed,           $ObjPtr(NetComConnection)     ;-> NetComConnection
  RedefineMethod  OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD

  DefineVariable  ClientLocalAddr,    NETCOMADDR, {AF_INETX, 0} ;Setup Server IP + Port
  DefineVariable  ServerRemoteAddr,   NETCOMADDR, {AF_INETX, DEFAULT_SERVER_LISTENING_PORT}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComStressClientProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComStressClientProtocol.Init
; Purpose:    Initializes this object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method NetComStressClientProtocol.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  OCall [xsi].BlackList::NetComAddrCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComStressClientProtocol.OnClosed
; Purpose:    A client session has, for whatever reason, been terminated.
;             You can override this, perhaps to release extra per client/task resources.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComStressClientProtocol.OnClosed, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComStressClientProtocol.OnClose", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_CONNECT
  invoke EnableWindow, xax, TRUE
  invoke GetDlgItem, [xbx].$Obj(%APP_NAME).SndDlg.hWnd, IDC_BTN_DISCONNECT
  invoke EnableWindow, xax, FALSE
  ACall xsi.OnClosed, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComStressClientProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: Error code.
; Return:     eax = Command.

Method NetComStressClientProtocol.OnError, uses xbx xsi, pConnection:$ObjPtr(NetComConnection), \
                                      pIOSockJob:PIO_SOCKJOB, dError:DWORD
;  DbgHex pConnection, "NetComStressClientProtocol.OnError", "&PROTOCOL_WND_NAME"
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