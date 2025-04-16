; ==================================================================================================
; Title:      IDual.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of COM Interface IDual.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  IDual
; Purpose: Implement a dual COM interface using VTable and IDispatch.

Object IDual, IDualID, IDispatch
  RedefineMethod    Init,                 POINTER, REFGUID
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     IDual.Init
; Purpose:    Initialize the IDual interface object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> TypeLib GUID.
; Return:     Nothing.

Method IDual.Init,, pOwner:POINTER, pTypeLibGUID:REFGUID
  DbgText "IDual.Init", "IDual"
  ACall Init, pOwner, pSelf, pTypeLibGUID
MethodEnd

endif
