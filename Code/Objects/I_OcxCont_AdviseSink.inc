; ==================================================================================================
; Title:   	  I_OcxCont_AdviseSink.inc
; Author:  	  G. Friedrich
; Version: 	  C.1.0
; Purpose: 	  ObjAsm support of AdviseSink Interface for COM OcxContainer objects.
; Notes:   	  Version C.1.0, October 2017
;          	    - First release.
; ==================================================================================================


externdef IID_IAdviseSink:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_AdviseSink
; Purpose:    Enable containers and other objects to receive notifications of data changes, view
;             changes and compound-document changes occurring in objects of interest. Container
;             applications, for example, require such notifications to keep cached presentations of
;             their linked and embedded objects up-to-date. Calls to IAdviseSink methods are
;             asynchronous, so the call is sent and then the next instruction is executed without
;             waiting for the call's return.

Object I_OcxCont_AdviseSink,, IUnknown
  InterfaceMethod   OnDataChange,       POINTER, POINTER
  InterfaceMethod   OnViewChange,       DWORD, DWORD
  InterfaceMethod   OnRename,           POINTER
  InterfaceMethod   OnSave
  InterfaceMethod   OnClose

  RedefineVariable  pIID,   offset IID_IAdviseSink
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_AdviseSink implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_AdviseSink.OnDataChange
; Purpose:    Called by the server to notify a data object's currently registered advise sinks that
;             data in the object has changed.
; Arguments:  Arg1: -> FORMATETC structure, which describes the format, target device, rendering,
;                   and storage information of the calling data object.
;             Arg2: -> STGMEDIUM structure, which defines the storage medium (global memory, disk
;                   file, storage object, stream object, GDI object, or undefined) and ownership of
;                   that medium for the calling data object.
; Return:     Nothing.

Method I_OcxCont_AdviseSink.OnDataChange,, pFormatetc:POINTER, pStgmed:POINTER
    DbgText "I_OcxCont_AdviseSink.OnDataChange", "I_OcxCont_AdviseSink"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_AdviseSink.OnViewChange
; Purpose:    Notify an object's registered advise sinks that its view has changed.
; Arguments:  Arg1: The aspect, or view, of the object. Contains a value taken from the DVASPECT enum
;             Arg2: The portion of the view that has changed. Currently only -1 is valid.
; Return:     Nothing.

Method I_OcxCont_AdviseSink.OnViewChange,, dAspect:DWORD, dIndex:DWORD
    DbgText "I_OcxCont_AdviseSink.OnViewChange", "I_OcxCont_AdviseSink"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_AdviseSink.OnRename
; Purpose:    Called by the server to notify all registered advisory sinks that the object has
;             been renamed.
; Arguments:  Arg1: -> IMoniker interface on the new full moniker of the object.
; Return:     Nothing.

Method I_OcxCont_AdviseSink.OnRename,, pIMoniker:POINTER
    DbgText "I_OcxCont_AdviseSink.OnRename", "I_OcxCont_AdviseSink"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_AdviseSink.OnSave
; Purpose:    Called by the server to notify all registered advisory sinks that the object has
;             been saved.
; Arguments:  None.
; Return:     Nothing.

Method I_OcxCont_AdviseSink.OnSave
    DbgText "I_OcxCont_AdviseSink.OnSave", "I_OcxCont_AdviseSink"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_AdviseSink.OnClose
; Purpose:    Called by the server to notify all registered advisory sinks that the object has
;             changed from the running to the loaded state.
; Arguments:  None.
; Return:     Nothing.

Method I_OcxCont_AdviseSink.OnClose
    DbgText "I_OcxCont_AdviseSink.OnClose", "I_OcxCont_AdviseSink"
MethodEnd

endif
