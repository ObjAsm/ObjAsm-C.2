; ==================================================================================================
; Title:      NetComIOMsgPool.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComIOMsgPool objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComIOMsgPool implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOMsgPool.FreeItem
; Purpose:    Release memory of a specified IOMsg.
; Arguments:  Arg1: -> IOMsg.
; Return:     Nothing.

Method NetComIOMsgPool.FreeItem, uses xsi, pIOMsg:PIO_MSG
  SetObject xsi
  LockObjectAccess [xsi].$Obj(NetComIOMsgPool)
  dec [xsi].dCount
  ACall xsi.FreeItem, pIOMsg                            ;Return it to the DataPool
  UnlockObjectAccess [xsi].$Obj(NetComIOMsgPool)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOMsgPool.Init
; Purpose:    Initialize the NetComIOMsgPool object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial allocated NetComIOMsgs.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComIOMsgPool.Init,, pOwner:POINTER, dInitMsgCount:DWORD
  SetObject xcx
  ACall xcx.Init, pOwner, sizeof IO_MSG, dInitMsgCount, @WordSize   ;We need an alignment of @WordSize
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOMsgPool.NewItem
; Purpose:    Allocate a new IOMsg from DataPool.
; Arguments:  Arg1: -> Owner object (NetComConnection).
;             Arg2: Message type.
; Return:     xax -> new IOJob or NULL if failed.

Method NetComIOMsgPool.NewItem, uses xsi, pOwner:POINTER, sdMessage:SDWORD
  SetObject xsi
  LockObjectAccess [xsi].$Obj(NetComIOMsgPool)
  ACall xsi.NewItem
  .if xax != NULL
    inc [xsi].dCount
    UnlockObjectAccess [xsi].$Obj(NetComIOMsgPool)      ;xax is not changed
    OCall xsi.ResetIOMsg, xax, pOwner, sdMessage
  .else
    UnlockObjectAccess [xsi].$Obj(NetComIOMsgPool)
    OCall xsi.ErrorReport, NULL, NCMP_OUT_OF_MEMORY
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComIOMsgPool.ResetIOMsg
; Purpose:    Reset an IOJob.
; Arguments:  Arg1: -> IOMsg.
;             Arg2: -> Owner object (NetComConnection).
;             Arg3: Message type.
; Return:     xax -> IOMsg.

Method NetComIOMsgPool.ResetIOMsg,, pIOMsg:PIO_MSG, pOwner:POINTER, sdMessage:SDWORD
  SetObject xcx
  mov xax, pIOMsg
  m2m [xax].IO_MSG.pOwner, pOwner, xdx
  m2m [xax].IO_MSG.sdOperation, sdMessage, ecx
  m2z [xax].IO_MSG.dBytesUsed
  m2z [xax].IO_MSG.dFlags
  m2z [xax].IO_MSG.Ovl.Internal
  m2z [xax].IO_MSG.Ovl.InternalHigh
  m2z [xax].IO_MSG.Ovl.Offset_
  m2z [xax].IO_MSG.Ovl.OffsetHigh
  m2z [xax].IO_MSG.Ovl.hEvent
MethodEnd

endif
