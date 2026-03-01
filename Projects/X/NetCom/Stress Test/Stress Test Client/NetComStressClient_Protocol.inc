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
  RedefineMethod  OnError,            $ObjPtr(NetComConnection), PIOJOB, DWORD

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

Method NetComStressClientProtocol.OnClosed, uses xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComStressClientProtocol.OnClose", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComStressClient).SndDlg::SendDlg.CtlsEnable, TRUE
  ACall xsi.OnClosed, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComStressClientProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: Error code.
; Return:     eax = Command (PROT_CMD_XXXX).

Method NetComStressClientProtocol.OnError, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection), \
                                                             pIOSockJob:PIOJOB, dError:DWORD
;  DbgHex pConnection, "NetComStressClientProtocol.OnError", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner
  .ifBitClr [xbx].$Obj(NetComStressClient).SndDlg.dFlags, SDF_ERROR
    BitSet [xbx].$Obj(NetComStressClient).SndDlg.dFlags, SDF_STOP or SDF_ERROR
    invoke WaitForSingleObject, [xbx].$Obj(NetComStressClient).SndDlg.hWorker, 4000   ;Stop sending
    OCall [xbx].$Obj(NetComStressClient).SndDlg.pConnection::NetComConnection.Disconnect, SD_SEND
    OCall [xbx].$Obj(NetComStressClient).SndDlg.pConnection::NetComConnection.QueueDestroy
    OCall [xbx].$Obj(NetComStressClient).SndDlg.pConnection::NetComConnection.Close, FALSE
    mov [xbx].$Obj(NetComStressClient).SndDlg.pConnection, NULL
    OCall [xbx].$Obj(NetComStressClient).SndDlg::SendDlg.CtlsEnable, TRUE     ;Enable controls
  .endif
  ;ACall xsi.OnError, pConnection, pIOSockJob, dError
  mov eax, PROT_CMD_NONE
MethodEnd

endif