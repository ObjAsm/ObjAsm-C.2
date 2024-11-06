; ==================================================================================================
; Title:      XML.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DOM-XML Test.
; Notes:      Version C.1.0, November 2024
;               - First release.
;               - This is a port from sources of Veria Kalantary - Ideas of East Company
;                 http://www.IdeasofEast.com; http://www.ioe.co.ir
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND);, ResGuard)  ;Load OOP files and OS related objects

% include &MacPath&BStrings.inc                         ;BSTR support
% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\Ole2.inc
% include &IncPath&Windows\commctrl.inc
% include &IncPath&Windows\sGUID.inc
include XML_Helper.inc                                  ;XML definitions

% includelib &LibPath&Windows\oleaut32.lib
% includelib &LibPath&Windows\ole32.lib
% includelib &LibPath&Windows\comctl32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib

.code
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
include XmlDocument.inc                                 ;XML objects

.const                                                  ;Global GUIDs
DefGUID CLSID_DOMDocument, %sCLSID_DOMDocument
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IXMLDOMNode, %sIID_IXMLDOMNode
DefGUID IID_IXMLDOMDocument, %sIID_IXMLDOMDocument
DefGUID IID_IXMLDOMElement, %sIID_IXMLDOMElement

.code
include XML_Globals.inc                                 ;Application globals
include XML_Main.inc                                    ;Application object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearAll
  ResGuard_Start
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application
  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp
end