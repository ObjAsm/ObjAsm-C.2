; ==================================================================================================
; Title:      ITaskbarApp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm ITaskbar Demo.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\shObjIDL.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include ITaskbarApp_Globals.inc                         ;Application globals
include ITaskbarApp_Main.inc                            ;Application object


.const                                                  ;GUID global constants
DefGUID IID_ITaskbarList4, <c43dc798-95d1-4bea-9030-bb99e2983a1a>
DefGUID CLSID_TaskbarList, <56fdf344-fd6d-11d0-958a-006097c9a090>

.data?
ThumbButtonArray THUMBBUTTON 4 dup(<>)

.code
TaskBarAnimation proc uses xbx xdi xsi hWnd:HWND
  local pTBL:POINTER, hIcon:HICON, wBuffer[256]:CHRW

  ;ThumbButtons setup
  lea xbx, ThumbButtonArray
  invoke LoadIcon, hInstance, $OfsCStr("RED_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 1
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Red action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  add xbx, sizeof(THUMBBUTTON)
  invoke LoadIcon, hInstance, $OfsCStr("GREEN_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 2
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Green action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  add xbx, sizeof(THUMBBUTTON)
  invoke LoadIcon, hInstance, $OfsCStr("YELLOW_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 3
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Yellow action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  add xbx, sizeof(THUMBBUTTON)
  invoke LoadIcon, hInstance, $OfsCStr("BLUE_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 4
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Blue action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  ;Initialize COM library
  invoke CoInitializeEx, NULL, COINIT_APARTMENTTHREADED
  invoke CoCreateInstance, offset CLSID_TaskbarList, NULL,
                           CLSCTX_INPROC_SERVER, offset IID_ITaskbarList4, addr pTBL
  .if SUCCEEDED(eax)                                    ;If creation was successful
    ;Initialize and setup
    ICall pTBL::ITaskbarList4.HrInit
    ICall pTBL::ITaskbarList4.AddTab, hWnd
    ICall pTBL::ITaskbarList4.ActivateTab, hWnd

    ;Add a customized Thumbnail Tooltip
    lea xdi, wBuffer
    invoke GetCurrentProcessId
    FillStringW wBuffer, <ITaskbarApp - ProcessID: >
    invoke udword2decW, addr [wBuffer + $$Size - 2], eax
    ICall pTBL::ITaskbarList4.SetThumbnailTooltip, hWnd, addr wBuffer

    ;Add the 4 Thumbbar buttons
    ICall pTBL::ITaskbarList4.ThumbBarAddButtons, hWnd, 4, offset ThumbButtonArray

    ;Control the progress animation
    .for(xbx = 0: ebx != 50: ebx ++)
      lea eax, [2*ebx]
      ICall pTBL::ITaskbarList4.SetProgressValue, hWnd, eax, 100
      invoke Sleep, 50
    .endfor
    ICall pTBL::ITaskbarList4.SetProgressState, hWnd, TBPF_NOPROGRESS
    invoke Sleep, 200

    ;Control the red dot animation in the lower right corner of the Taskbar Tab
    invoke LoadIcon, hInstance, $OfsCStr("RED_DOT_SM_LR")
    mov hIcon, xax
    .for(xbx = 0: ebx != 5: ebx ++)
      ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, hIcon, $OfsCStrW("Attention")
      invoke Sleep, 500
      ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, 0, NULL
      invoke Sleep, 500
    .endfor
    invoke DestroyIcon, hIcon

    ;Control the final stage of the animation - green dot
    invoke LoadIcon, hInstance, $OfsCStr("GREEN_DOT_SM_LR")
    mov hIcon, xax
    ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, hIcon, NULL
    invoke Sleep, 2500
    ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, 0, NULL
    invoke Sleep, 500
    invoke DestroyIcon, hIcon
    invoke Sleep, 1000

    ICall pTBL::ITaskbarList4.Release

  .endif
  invoke CoUninitialize
  ret
TaskBarAnimation endp


start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application

  ;Start Taskbar animation in a new thread,
  ;otherwise the GUI will freeze in the meantime.
  invoke CreateThread, NULL, 0, addr TaskBarAnimation, $ObjTmpl(Application).hWnd, 0, NULL

  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
