; ==================================================================================================
; Title:      FireworksApp_Main.inc
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Fireworks.
; Version:    See FireworksApp.asm
;             - First release.
; ==================================================================================================


CLS_STYLE       equ   CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW
WND_STYLE       equ   WS_POPUPWINDOW or WS_CAPTION
WND_STYLE_EX    equ   0

DEFAULT_WIDTH   equ   682
DEFAULT_HEIGHT  equ   420

TIMERID         equ   125

CStr szFireworksApp, "Application"

Object Application, ApplicationID, SdiApp
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnClose,        WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnTimer,        WM_TIMER

  DefineVariable    dFlipFlop,      DWORD,      FALSE
  DefineVariable    hTimer,         HANDLE,     0

  Embed     Fwks,   Fireworks
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the Application application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local CRect:RECT

  SetObject xsi
  ACall xsi.Init

  invoke CreateWindowEx, WND_STYLE_EX, offset szFireworksApp, offset szAppTitle, WND_STYLE, \
         CW_USEDEFAULT, CW_USEDEFAULT, DEFAULT_WIDTH, DEFAULT_HEIGHT, NULL, NULL, hInstance, pSelf
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd

  invoke GetClientRect, [xsi].hWnd, addr CRect
  GrowRect CRect, -10, -10
  OCall [xsi].Fwks::Fireworks.Init, xsi, [xsi].hWnd, addr CRect

  mov [xsi].hTimer, $invoke(SetTimer, [xsi].hWnd, TIMERID, 1000, NULL)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    OCall [xsi].Fwks::Fireworks.Done

    .if [xsi].hTimer != 0
      invoke KillTimer, [xsi].hWnd, TIMERID
    .endif

    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnTimer
; Purpose:    Event procedure for WM_TIMER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnTimer, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  lea xdi, cBuffer
  %WriteF xdi, "&APP_TITLE, FPS = ¦UD ", [xsi].Fwks.dFrameCount
  .if [xsi].dFlipFlop == FALSE
    FillString [xdi], <*>
  .endif
  xor [xsi].dFlipFlop, TRUE                             ;Toggle dFlipFlop 
  invoke SetWindowText, [xsi].hWnd, addr cBuffer
  m2z [xsi].Fwks.dFrameCount
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLS_STYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, COLOR_APPWORKSPACE + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szFireworksApp, xdx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
