; ==================================================================================================
; Title:      PixelmapApp_Main.inc
; Author:     G. Friedrich
; Version:    See PixelmapApp.asm
; Purpose:    ObjAsm Pixelmap Application.
; ==================================================================================================


CLSSTYLE    equ  CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW
APPSTYLE    equ  WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_MINIMIZEBOX
APPEXSTYLE  equ  WS_EX_LEFT or WS_EX_APPWINDOW

CStr szPixelmapApp, "OAC_PixelmapApp"                   ;Creates szPixelmapApp string in .const

Object Application, ApplicationID, SdiApp                  ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,    WM_COMMAND
  VirtualEvent      OnClose,      WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnMouseMove,  WM_MOUSEMOVE
  VirtualEvent      OnPaint,      WM_PAINT

  Embed     Pxm1,  Pixelmap
  Embed     Pxm2,  Pixelmap
  Embed     Pxm3,  Pixelmap

  DefineVariable  dReduction,     DWORD,    0
ObjectEnd

.const
ConvFilter  REAL4    -1.000 , +1.000, -1.000 , +1.000, +1.500, +1.000, -1.000 , +1.000, -1.000

.code

; ==================================================================================================
;    Some demonstration procedures
; ==================================================================================================


WULine proc uses xbx pPXM:POINTER, r4Xi:REAL4, r4Yi:REAL4, r4Xd:REAL4, r4Yd:REAL4, \
                     dPoints:DWORD, dColor:DWORD
  mov ebx, dPoints
  test ebx, ebx
  .while !ZERO?
    OCall pPXM::Pixelmap.BlendVirtualPixel, r4Xi, r4Yi, dColor
    fld r4Xi
    fadd r4Xd
    fstp r4Xi
    fld r4Yi
    fadd r4Yd
    fstp r4Yi
    dec ebx
  .endw
  ret
WULine endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

WUCircle proc uses xbx pPXM:POINTER, r4Xc:REAL4, r4Yc:REAL4, r4R:REAL4, dColor:DWORD, dPoints:DWORD
  local r4X:REAL4, r4Y:REAL4, r4Inc:REAL4

  fld1
  fld r4R
  fdivp st(1), st(0)
  fstp r4Inc
  fldz
  mov ebx, dPoints
  test ebx, ebx
  .while !ZERO?
    fld st(0)
    fsincos
    fmul r4R
    fadd r4Xc
    fstp r4X
    fmul r4R
    fadd r4Yc
    fstp r4Y
    OCall pPXM::Pixelmap.BlendVirtualPixel, r4X, r4Y, dColor
    fadd r4Inc
    dec ebx
  .endw

  fUnload
  ret
WUCircle endp


; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.Done
; Purpose:   Release resources & finalize the application object.
; Arguments: None.
; Return:    Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].Pxm1::Pixelmap.Done
  OCall [xsi].Pxm2::Pixelmap.Done
  OCall [xsi].Pxm3::Pixelmap.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.Init
; Purpose:   Initialize the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local CRct:RECT, DRect:RECT

  SetObject xsi
  ACall xsi.Init

  m2z CRct.left
  m2z CRct.top
  mov CRct.right, 800
  mov CRct.bottom, 540
  invoke AdjustWindowRectEx, addr CRct, APPSTYLE, TRUE, APPEXSTYLE
  m2m dWndWidth, CRct.right, eax
  m2m dWndHeight, CRct.bottom, ecx
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, APPEXSTYLE, \
                         offset szPixelmapApp, offset szAppTitle, APPSTYLE, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL        ;Show the window

;  ;Drawing here
  OCall [xsi].Pxm1::Pixelmap.Init, xsi, 800, 540
  OCall [xsi].Pxm1::Pixelmap.FillBkGnd, $RGB(0,0,0,0)

  OCall [xsi].Pxm2::Pixelmap.Init, xsi, 300, 300
  OCall [xsi].Pxm2::Pixelmap.FillBkGnd, $RGB(0,0,0,255)

;  OCall [xsi].Pxm2::Pixelmap.Brightness, 50
  mov DRect.left, 0
  mov DRect.top, 0
  mov DRect.right, 300
  mov DRect.bottom, 300
  OCall [xsi].Pxm2::Pixelmap.FillRectChannel, addr DRect, PXM_CHANNEL_ALPHA, 255
;
  OCall [xsi].Pxm3::Pixelmap.Init, xsi, 800,540

  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(50.0), $RGB(255,0,0,255), 315
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(60.0), $RGB(255,0,0,128), 377
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(70.0), $RGB(255,0,0,64), 440
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(80.0), $RGB(255,0,0,32), 503
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(90.0), $RGB(255,0,0,16), 566
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(100.0), $RGB(255,0,0,8), 628
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(110.0), $RGB(255,0,0,4), 691
  invoke WUCircle, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(150.0), $CReal4(120.0), $RGB(255,0,0,2), 754
  
  invoke WULine, addr [xsi].Pxm2, $CReal4(10.0), $CReal4(150.0), $CReal4(1.0), $CReal4(0.0), 280, $RGB(255,0,0,128)
  invoke WULine, addr [xsi].Pxm2, $CReal4(150.0), $CReal4(10.0), $CReal4(0.0), $CReal4(1.0), 280, $RGB(255,0,0,128)
  
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    mov xbx, $New(Dlg::DialogAbout)
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall xbx::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall xbx::DialogAbout.Show
    OCall xbx::DialogAbout.Done
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
; Method:    Application.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), \
                     $OfsCStr("Application exit"), MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.OnMouseMove
; Purpose:   Event procedure for WM_MOUSEMOVE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Rct:RECT, Pt:POINT
  
  SetObject xsi
  m2z Rct.left
  m2z Rct.top
  m2m Rct.right, [xsi].Pxm2.dWidth, eax
  m2m Rct.bottom, [xsi].Pxm2.dHeight, ecx
  invoke MemClone, [xsi].Pxm3.pPixels, [xsi].Pxm1.pPixels, \
                   [xsi].Pxm1.BmpInfo.bmiHeader.biSizeImage
  mov xax, lParam
  xor ecx, ecx
  mov cx, ax
  shr eax, 16
  
  ;Center the Pixelmap on mouse cursor
  sub eax, 150
  sub ecx, 150
  
  mov Pt.x, ecx
  mov Pt.y, eax
  
  OCall [xsi].Pxm3::Pixelmap.AlphaBlend, addr [xsi].Pxm2, addr Rct, Pt
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_UPDATENOW or RDW_INVALIDATE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.OnPaint
; Purpose:   Event procedure for WM_PAINT message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, CRect:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr CRect
  invoke BitBlt, hDC, CRect.left, CRect.top, CRect.right, CRect.bottom, \
                 [xsi].Pxm3.hDC, 0, 0, SRCCOPY
  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.Startup
; Purpose:   Register the object class with the OS.
; Arguments: None.
; Return:    Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szPixelmapApp, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
