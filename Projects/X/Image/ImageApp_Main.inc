; ==================================================================================================
; Title:      ImageApp_Main.inc
; Author:     G. Friedrich
; Version:    See ImageApp.asm
; Purpose:    ObjAsm Image Application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

CStr szImagApp, "OAC_ImagApp"

WM_APPSTR equ 0C000h


Object Application, ApplicationID, SdiApp
  RedefineMethod    Done
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,    WM_COMMAND
  VirtualEvent      OnPaint,      WM_PAINT
  
  Embed   Img1,  Image
  Embed   Img2,  Image

ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].Img1::Image.Done
  OCall [xsi].Img2::Image.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height
  
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  OCall [xsi].Img1::Image.Init, xsi
  OCall [xsi].Img1::Image.LoadFromRes, $OfsCStr("IMG1")
  OCall [xsi].Img2::Image.Init, xsi
  OCall [xsi].Img2::Image.LoadFromRes, $OfsCStr("IMG2")

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szImagApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, DstRect:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr DstRect
  invoke DrawEdge, hDC, addr DstRect, EDGE_SUNKEN, BF_RECT
  
  mov eax, [xsi].Img1.ImgSize.x
  mov ecx, DstRect.right
  mov DstRect.right, eax
  shr eax, 1
  shr ecx, 1
  sub ecx, eax
  add ecx, 80
  mov DstRect.left, ecx

  mov eax, [xsi].Img1.ImgSize.y
  mov ecx, DstRect.bottom
  mov DstRect.bottom, eax
  shr eax, 1
  shr ecx, 1
  sub ecx, eax
  add ecx, 40
  mov DstRect.top, ecx
  
  OCall [xsi].Img1::Image.AlphaDraw, hDC, 255, addr DstRect

  invoke GetClientRect, [xsi].hWnd, addr DstRect
  mov DstRect.left, 50
  mov DstRect.top, 50
  mov eax, DstRect.right
  shr eax, 2
  mov DstRect.right, eax
  mov DstRect.bottom, eax
  
  OCall [xsi].Img2::Image.AlphaStretch, hDC, 255, addr DstRect, addr [xsi].Img2.ImgSize.Rect  

@@Exit:
  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szImagApp, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
