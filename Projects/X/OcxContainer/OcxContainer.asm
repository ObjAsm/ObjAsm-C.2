; ==================================================================================================
; Title:      OcxContainer.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm OCX Control Container.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)           ;Load OOP files and OS related objects

include OcxContainer_Globals.inc                        ;Include application globals

% include &COMPath&COM.inc                              ;COM basic support
% include &COMPath&COM_Dispatch.inc                     ;Dispatch definitions and macros
% include &COMPath&COM_Dispatch.asm                     ;Dispatch procedures
% include &IncPath&Windows\OleCtl.inc
% include &IncPath&Windows\sGUID.inc
% include &IncPath&Windows\oaidl.inc
% include &IncPath&Windows\CommCtrl.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects COM_Primers, IDispatch
MakeObjects OcxContainer

.const                                                      ;Global GUIDs
;DefGUID CLSID_Control, <0A2B370C-BA0A-11D1-B137-0000F8753F5D>  ;Error = not found       OK
;DefGUID CLSID_Control, <3A2B370C-BA0A-11D1-B137-0000F8753F5D>  ;MSChart                 OK
;DefGUID CLSID_Control, <8BD21D40-EC42-11CE-9E0D-00AA006002F3>  ;Checkbox                OK
;DefGUID CLSID_Control, <8BD21D30-EC42-11CE-9E0D-00AA006002F3>  ;Combobox                OK
;DefGUID CLSID_Control, <DFD181E0-5E2F-11CE-A449-00AA004A803D>  ;ScrollBar               OK
;DefGUID CLSID_Control, <79176FB0-B7F2-11CE-97EF-00AA006D2776>  ;SpinButton              OK
;DefGUID CLSID_Control, <02A69B00-081B-101B-8933-08002B2F4F5A>  ;DBList Control V6       OK
;DefGUID CLSID_Control, <8BD21D60-EC42-11CE-9E0D-00AA006002F3>  ;ToggleButton            OK
;DefGUID CLSID_Control, <8856F961-340A-11D0-A96B-00C04FD705A2>  ;Microsoft Web Browser   OK
DefGUID CLSID_Control, <6BF52A52-394A-11D3-B153-00C04F79FAA6>  ;Windows Media Player    OK
;DefGUID CLSID_Control, <D27CDB6E-AE6D-11CF-96B8-444553540000>  ;Adobe Flash Player      OK
;DefGUID CLSID_Control, <ABD29A82-C4F4-11D8-9C47-BA3E642A547C>  ;OCX_LED      OK

DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID IID_IConnectionPointContainer, %sIID_IConnectionPointContainer
DefGUID IID_IConnectionPoint, %sIID_IConnectionPoint
DefGUID IID_IEnumConnections, %sIID_IEnumConnections
DefGUID IID_IEnumConnectionPoints, %sIID_IEnumConnectionPoints
DefGUID IID_IDispatch, %sIID_IDispatch
DefGUID IID_IOleObject, %sIID_IOleObject
DefGUID IID_IPersistStorage, %sIID_IPersistStorage
DefGUID IID_IAdviseSink, %sIID_IAdviseSink
DefGUID IID_IOleInPlaceObject, %sIID_IOleInPlaceObject
DefGUID IID_IOleWindow, %sIID_IOleWindow
DefGUID IID_IOleClientSite, %sIID_IOleClientSite
DefGUID IID_IOleInPlaceSite, %sIID_IOleInPlaceSite
DefGUID IID_IOleInPlaceSiteEx, %sIID_IOleInPlaceSiteEx
DefGUID IID_IOleInPlaceActiveObject, %sIID_IOleInPlaceActiveObject
DefGUID IID_IOleControlSite, %sIID_IOleControlSite
DefGUID IID_IOleControl, %sIID_IOleControl
DefGUID IID_IDataObject, %sIID_IDataObject
DefGUID IID_IViewObject2, %sIID_IViewObject2
DefGUID IID_IProvideClassInfo, %sIID_IProvideClassInfo
DefGUID IID_ISpecifyPropertyPages, %sIID_ISpecifyPropertyPages
DefGUID IID_IOleInPlaceFrame, %sIID_IOleInPlaceFrame
DefGUID IID_IOleContainer, %sIID_IOleContainer
DefGUID IID_ISimpleFrameSite, %sIID_ISimpleFrameSite
DefGUID IID_IPropertyNotifySink, %sIID_IPropertyNotifySink
DefGUID IID_IErrorInfo, %sIID_IErrorInfo
DefGUID IID_IClassFactory2, %sIID_IClassFactory2
DefGUID IID_IFontDisp, %sIID_IFontDisp
DefGUID IID_IServiceProvider, %sIID_IServiceProvider
DefGUID IID_IOleInPlaceSiteWindowless, %sIID_IOleInPlaceSiteWindowless
DefGUID IID_IOleDocumentSite, %sIID_IOleDocumentSite

include ShockwaveFlashObjects.inc

DefGUID IID_IShockwaveFlash, %sIID_IShockwaveFlash

;include SHDocVw.inc
;DefGUID IID_IWebBrowser, %sIID_IWebBrowser

.code

include OcxContainer_Main.inc

start proc
  SysInit
  invoke CoInitialize, 0
  invoke InitCommonControls

  DbgClearAll
  OCall $ObjTmpl(OcxContainerDemo)::OcxContainerDemo.Init
  OCall $ObjTmpl(OcxContainerDemo)::OcxContainerDemo.Run 
  OCall $ObjTmpl(OcxContainerDemo)::OcxContainerDemo.Done

  invoke CoUninitialize
  SysDone

  invoke ExitProcess, 0
start endp

end
