; ==================================================================================================
; Title:      InProcServer.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of COM In Process Server objects.
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  InProcServer
; Purpose: Implement a "in process" COM server.

Object InProcServer, InProcServerID, Component
  RedefineMethod    Done
  RedefineMethod    Init,          POINTER, POINTER     ;-> Owner, -> pUnkOuter
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     InProcServer.Done
; Purpose:    Finalize the InProcServer COM object.
; Arguments:  None.
; Return:     Nothing.

Method InProcServer.Done
  DbgText "InProcServer.Done"
  dec dDllRefCount
  DbgDec dDllRefCount
  SetObject xcx
  ACall xcx::InProcServer.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InProcServer.Init
; Purpose:    Initialize the InProcServer COM object.
; Arguments:  Arg1: -> Owner object (InProcServer).
; Return:     Nothing.

Method InProcServer.Init,, pOwner:POINTER, pUnkOuter:POINTER
  DbgText "InProcServer.Init"
  SetObject xcx
  ACall xcx.Init, pOwner, pUnkOuter                     ;Forwarding to Container
  inc dDllRefCount
  DbgDec dDllRefCount
MethodEnd

endif
