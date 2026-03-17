; ==================================================================================================
; Title:      WordHost.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Word Host Application.
; Notes:      Version 1.0.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, WIDE_STRING;, DEBUG(WND)           ;Load OOP files and OS related objects

% include &MacPath&BStrings.inc                         ;BSTR support
% include &COMPath&COM.inc                              ;COM basic support
% include &COMPath&COM_Dispatch.inc                     ;Dispatch definitions and macros
% include &COMPath&OAIDL.inc
% include &IncPath&Windows\Ole2.inc
% include &IncPath&Windows\sGUID.inc

% includelib &LibPath&Windows\ole32.lib
% includelib &LibPath&Windows\OleAut32.lib

.code
% include &COMPath&COM_Dispatch.asm                     ;Dispatch procedures

MsoScreenSize typedef SDWORD
MsoEncoding typedef SDWORD

MakeObjects Primer, WordHost

.const                                                  ;Global GUIDs
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown

CBStr SourceFile, "&OA_PATH&Projects\X\Office\WordHost\hello.doc"
CBStr NewFile,    "&OA_PATH&Projects\X\Office\WordHost\MyDocument.doc"


.data
pMyDocument   POINTER   NULL

.code
start proc
  ;***** ObjAsm initialization ***** 
  SysInit
  ;***** OLE / COM initialization *****
  invoke CoInitialize, 0

  OCall $ObjTmpl(WordHost)::WordHost.Init, NULL
  OCall $ObjTmpl(WordHost)::WordHost.SetVisible, TRUE
  OCall $ObjTmpl(WordHost)::WordHost.Open, offset SourceFile, FALSE, TRUE
  .if xax != NULL
    mov pMyDocument, xax
    OCall $ObjTmpl(WordHost)::WordHost.SaveAs, pMyDocument, offset NewFile, wdFormatDocument
    OCall $ObjTmpl(WordHost)::WordHost.Close, pMyDocument
    invoke MessageBox, 0, $OfsCStr("Work done."), $OfsCStr("Notification"), MB_OK
  .else
    invoke MessageBox, 0, $OfsCStr($Esc("Something went wrong\:")), offset szError, MB_OK
  .endif
  OCall $ObjTmpl(WordHost)::WordHost.Quit
  OCall $ObjTmpl(WordHost)::WordHost.Done

  ;***** OLE / COM cleanup *****
  invoke CoUninitialize
  ;***** ObjAsm cleanup *****
  SysDone
  invoke ExitProcess, 0
start endp

end start
