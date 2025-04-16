; ==================================================================================================
; Title:      I_OcxCont_OleDocumentSite.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of IOleDocumentSite Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IOleDocumentSite:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_OleDocumentSite
; Purpose:    Defines a mechanism for retrieving a service object; that is, an object that provides
;             custom support to other objects.

Object I_OcxCont_OleDocumentSite,, IUnknown
  VirtualMethod     ActivateMe,           POINTER

  RedefineVariable  pIID,   offset IID_IOleDocumentSite
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleDocumentSite implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleDocumentSite.ActivateMe
; Purpose:    Asks a document site to activate the document making the call as a document object
;             rather than an in-place-active object and, optionally, specifies which view of the
;             object document to activate.
; Arguments:  Arg1: -> IOleDocumentView to activate.
; Return:     eax = HRESULT.

Method I_OcxCont_OleDocumentSite.ActivateMe,, pViewToActivate:POINTER
  DbgText "I_OcxCont_OleDocumentSite.ActivateMe", "I_OcxCont_OleDocumentSite"
  mov eax, E_NOTIMPL
MethodEnd

endif
