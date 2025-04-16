; ==================================================================================================
; Title:      I_OcxCont_ErrorInfo.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ErrorInfo Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IErrorInfo:GUID           ;1CF2B120-547D-101B-8E65-08002B2BD119

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_ErrorInfo
; Purpose:    The IErrorInfointerface provides detailed contextual error information.
;             Mandatory if container supports dual interfaces.

Object I_OcxCont_ErrorInfo,, IUnknown
  InterfaceMethod   GetGUID,            REFGUID
  InterfaceMethod   GetSource,          BSTR
  InterfaceMethod   GetDescription,     BSTR
  InterfaceMethod   GetHelpFile,        BSTR
  InterfaceMethod   GetHelpContext,     POINTER

  RedefineVariable  pIID,   offset IID_IErrorInfo
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_ErrorInfo implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_ErrorInfo.GetGUID
; Purpose:    Returns the globally unique identifier (GUID) of the interface that defined the error.
; Arguments:  Arg1: -> GUID, or GUID_NULL, if the error was defined by the operating system.
; Return:     eax = HRESULT.

Method I_OcxCont_ErrorInfo.GetGUID,, pGUID:REFGUID
  DbgText "I_OcxCont_ErrorInfo.GetGUID", "I_OcxCont_ErrorInfo"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_ErrorInfo.GetSource
; Purpose:    Returns the language-dependent programmatic ID (ProgID) for the class or application
;             that raised the error.
; Arguments:  Arg1: -> String containing a ProgID, in the form progname.objectname.
; Return:     eax = HRESULT.

Method I_OcxCont_ErrorInfo.GetSource,, pBstrSource:BSTR
  DbgText "I_OcxCont_ErrorInfo.GetSource", "I_OcxCont_ErrorInfo"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_ErrorInfo.GetDescription
; Purpose:    Returns a textual description of the error.
; Arguments:  Arg1: -> Brief string that describes the error.
; Return:     eax = HRESULT.

Method I_OcxCont_ErrorInfo.GetDescription,, pBstrDescription:BSTR
  DbgText "I_OcxCont_ErrorInfo.GetDescription", "I_OcxCont_ErrorInfo"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_ErrorInfo.GetHelpFile
; Purpose:    Returns the path of the Help file that describes the error.
; Arguments:  Arg1: -> String that contains the fully qualified path of the Help file.
; Return:     eax = HRESULT.

Method I_OcxCont_ErrorInfo.GetHelpFile,, pBstrHelpFile:BSTR
  DbgText "I_OcxCont_ErrorInfo.GetHelpFile", "I_OcxCont_ErrorInfo"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_ErrorInfo.GetHelpContext
; Purpose:    Returns the Help context identifier (ID) for the error.
; Arguments:  Arg1: -> Help context ID for the error.
; Return:     eax = HRESULT.

Method I_OcxCont_ErrorInfo.GetHelpContext,, pHelpContext:POINTER
  DbgText "I_OcxCont_ErrorInfo.GetHelpContext", "I_OcxCont_ErrorInfo"
  xor eax, eax                                          ;S_OK
MethodEnd

endif
