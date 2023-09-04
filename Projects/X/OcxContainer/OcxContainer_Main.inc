; ==================================================================================================
; Title:      OcxContainer_Main.inc
; Author:     G. Friedrich
; Version:    See OcxContainer.asm
; Purpose:    ObjAsm OCX Control Container.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szOcxContainerDemoApp, "OAC_OcxContainerDemo"


Object OcxContainerDemo, MySdiAppID, SdiApp
  StaticMethod      CreateCtrl
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    OnSize,       WPARAM, LPARAM
  StaticMethod      Startup

  DynamicEvent      OnCommand,    WM_COMMAND
  VirtualEvent      OnClose,      WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,      WM_PAINT

  DefineVariable    pContainer,       POINTER,    NULL
  DefineVariable    pOcxClientSite,   POINTER,    NULL
  DefineVariable    pIControl,        POINTER,    NULL
  
;  DefineVariable    pOcxClientSite2,  POINTER,    NULL
ObjectEnd


.code

if IMPLEMENT

; ==================================================================================================
;    OcxContainerDemo implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method OcxContainerDemo.Done, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pIControl
  .if xbx != NULL
    ICall xbx::IShockwaveFlash.Stop
    ICall xbx::IShockwaveFlash.Release
  .endif
  Destroy [xsi].pContainer
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.Init
; Purpose:    Initializesthe SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method OcxContainerDemo.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  
  mov dWndWidth, 840                                    ;Default creation width
  mov dWndHeight, 390                                   ;Default creation height
  invoke GetSystemMetrics, SM_CXSCREEN
  invoke CenterForm, dWndWidth, eax
  mov dWndPosX, eax
  invoke GetSystemMetrics, SM_CYSCREEN
  invoke CenterForm, dWndHeight, eax
  mov dWndPosY, eax

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szOcxContainerDemoApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  mov [xsi].pContainer, $New(OcxContainer)
  OCall [xsi].pContainer::OcxContainer.Init, xsi, [xsi].hWnd
  mov [xsi].pOcxClientSite, $OCall(xsi.CreateCtrl)

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.CreateCtrl
; Purpose:    Create a control and customizes it.
; Arguments:  None.
; Return:     eax -> OcxClientSite or NULL if failed.

Method OcxContainerDemo.CreateCtrl, uses xbx xsi
  local pClientSite:POINTER, cBuffer[MAX_PATH]:CHRW

  SetObject xsi
  OCall [xsi].pContainer::OcxContainer.CreateClientSite
  .if xax != NULL
    mov pClientSite, xax
    OCall [xsi].pContainer::OcxContainer.CreateControl, offset CLSID_Control, \
                                                        CLSCTX_INPROC_SERVER, xax
    .if eax == OBJ_OK
      lea xax, [xsi].pIControl
      mov xcx, pClientSite
      ICall [xcx].$Obj(OcxClientSite).pIUnknown::IUnknown.QueryInterface, \
                                                                    offset IID_IShockwaveFlash, xax
      .if SUCCEEDED(eax)
        lea xbx, cBuffer
        invoke GetModuleFileNameW, 0, xbx, lengthof cBuffer
        invoke StrRScanW, xbx, "\"
        FillStringW CHRW ptr [xax + sizeof CHRW], <Test.swf>
        ICall [xsi].pIControl::IShockwaveFlash.LoadMovie, 0, xbx
        ICall [xsi].pIControl::IShockwaveFlash.Play
      .endif
      mov xax, pClientSite
    .else
      DbgWarning "Failed to create the control"
      xor eax, eax
    .endif
  .else
    DbgWarning "Failed to allocate the ClientSite"
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OcxContainerDemo.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OcxContainerDemo.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OcxContainerDemo.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OcxContainerDemo.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Rect:RECT

  .if (wParam == SIZE_RESTORED || wParam == SIZE_MAXIMIZED)
    SetObject xsi
    .if [xsi].pOcxClientSite != NULL
      mov xcx, [xsi].pOcxClientSite
      .if [xcx].$Obj(OcxClientSite).pIOleInPlaceSite != NULL
        ;Put the client size in Rect
        m2z Rect.left
        m2z Rect.top
        lea xdx, Rect.right
        PntS2Pnt [xdx].POINT, lParam
        ;Set rect as clip area for this control
        CloneRect [xcx].$Obj(OcxClientSite).ClipRect, Rect, xax, xdx
        ;Calc and set the new control position
;        shr Rect.RECT.right, 1
        GrowRect Rect, -12
        ICall [xcx].$Obj(OcxClientSite).pIOleInPlaceSite::IOleInPlaceSite.OnPosRectChange, addr Rect
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainerDemo.Startup
; Purpose:    Register the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method OcxContainerDemo.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(OcxContainerDemo.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_ACTIVECAPTION + 1
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szOcxContainerDemoApp, xcx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

endif
