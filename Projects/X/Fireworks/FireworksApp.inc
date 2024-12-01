; ==================================================================================================
; Title:   FireworksApp.inc
; Author:  G. Friedrich  @ July 2003
; Version: 1.0.0
; Purpose: Demonstration program 2 of ObjAsm32.
; ==================================================================================================


CLS_STYLE       equ   CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW
WND_STYLE       equ   WS_POPUPWINDOW or WS_CAPTION
WND_STYLE_EX    equ   0

DEFAULT_WIDTH   equ   682
DEFAULT_HEIGHT  equ   420

TIMERID         equ   125

CStr szFireworksApp, "FireworksApp"

Object FireworksApp, ApplicationID, SdiApp
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnClose,        WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnTimer,        WM_TIMER
  
  DefineVariable    dFlipFlop,      dword,      FALSE
  DefineVariable    hTimer,         Handle,     0

  Embed     Fwks,   Fireworks
ObjectEnd


.code
; ==================================================================================================
;    FireworksApp implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    FireworksApp.Init
; Purpose:   Initalizes the FireworksApp application object.
; Arguments: None.
; Return:    Nothing.

Method FireworksApp.Init, uses esi
    local CRect:RECT

    SetObject esi
    ACall esi.Init
    
    invoke CreateWindowEx, WND_STYLE_EX, offset szFireworksApp, offset szAppTitle, WND_STYLE, \
           CW_USEDEFAULT, CW_USEDEFAULT, DEFAULT_WIDTH, DEFAULT_HEIGHT, NULL, NULL, hInstance, esi
    invoke ShowWindow, [esi].hWnd, SW_SHOWNORMAL
    invoke UpdateWindow, [esi].hWnd

    invoke GetClientRect, [esi].hWnd, addr CRect
    GrowRect CRect, -10, -10
    OCall [esi].Fwks::Fireworks.Init, esi, [esi].hWnd, CRect

    mov [esi].hTimer, $invoke(SetTimer, [esi].hWnd, TIMERID, 1000, NULL)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    FireworksApp.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method FireworksApp.OnClose, uses esi, wParam:dword, lParam:dword
    SetObject esi
    invoke MessageBox, [esi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                       MB_YESNO or MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
    .else
      OCall [esi].Fwks::Fireworks.Done

      .if [esi].hTimer != 0
        invoke KillTimer, [esi].hWnd, TIMERID
      .endif

      invoke DefWindowProc, [esi].hWnd, WM_CLOSE, wParam, lParam
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    FireworksApp.OnTimer
; Purpose:   Event procedure for WM_TIMER message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method FireworksApp.OnTimer, uses edi esi, wParam:dword, lParam:dword
    local bBuffer[1024]:byte
    
    SetObject esi
    invoke StrLECopy, addr bBuffer, offset szAppTitle, sizeof bBuffer - 17  ;Size of additional text
    lea edi, [esi].Fwks
    invoke wsprintf, eax, $OfsCStr(", FPS = %u "), [edi].Fireworks.dFrameCount
    .if [esi].dFlipFlop == FALSE
      mov [esi].dFlipFlop, TRUE
      invoke StrCatChar, addr bBuffer, "*"
    .else
      and [esi].dFlipFlop, FALSE
    .endif
    invoke SetWindowText, [esi].hWnd, addr bBuffer
    and [edi].Fireworks.dFrameCount, 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    FireworksApp.Startup
; Purpose:   Registers the object class with the OS.
; Arguments: None.
; Return:    Nothing.

Method FireworksApp.Startup
    local WC:WNDCLASSEX

    mov WC.cbSize, sizeof WNDCLASSEX
    mov WC.style, CLS_STYLE
    m2m WC.lpfnWndProc, $MethodAddr(FireworksApp.WndProc), edx
    and WC.cbClsExtra, 0
    and WC.cbWndExtra, 0
    m2m WC.hInstance, hInstance, edx
    mov WC.hbrBackground, COLOR_APPWORKSPACE + 1
    and WC.lpszMenuName, NULL
    mov WC.lpszClassName, offset szFireworksApp
    mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_32"))
    mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
    and WC.hIconSm, 0

    invoke RegisterClassEx, addr WC
MethodEnd
MethodEnd
