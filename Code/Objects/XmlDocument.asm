; ==================================================================================================
; Title:      XmlDocument.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for XmlDocument object.
; Notes:      Version C.1.0, November 2024
;             - First release.
; ==================================================================================================


% include Objects.cop

externdef CLSID_DOMDocument:GUID
externdef CLSID_DOMDocument:GUID
externdef IID_NULL:GUID
externdef IID_IXMLDOMNode:GUID
externdef IID_IXMLDOMDocument:GUID
externdef IID_IXMLDOMElement:GUID

% include &MacPath&BStrings.inc                         ;BSTR support
% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\Ole2.inc
% include &IncPath&Windows\commctrl.inc
% include &IncPath&Windows\sGUID.inc
% include &IncPath&ObjAsm\XmlHelper.inc                 ;XML definitions

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer

;Add here the file that defines the object(s) to be included in the library
MakeObjects XmlDocument

end
