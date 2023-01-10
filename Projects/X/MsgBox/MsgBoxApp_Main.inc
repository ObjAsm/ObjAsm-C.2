; ==================================================================================================
; Title:      MsgBoxApp_Main.inc
; Author:     G. Friedrich
; Version:    See ViewDemo.asm
; Purpose:    ObjAsm MsgBox Application.
; ==================================================================================================

;Problem: [xsi].DrawExtent.y is not set

CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "OAC_Application"

Object Application, MySdiAppID, SdiApp
  RedefineMethod    Init
  StaticMethod      Startup
  RedefineMethod    OnSize,       WPARAM, LPARAM

  VirtualEvent      OnCommand,        WM_COMMAND
  VirtualEvent      OnClose,          WM_CLOSE, WM_QUERYENDSESSION
;  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnHelp,           WM_HELP
  VirtualEvent      OnNotify,         WM_NOTIFY
  VirtualEvent      OnPaint,          WM_PAINT

  DefineVariable    pTextView,  $ObjPtr(TextView)
ObjectEnd

.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================



MB_BTN_MAX_COUNT  equ 4       ;Max number of buttons shown on the dialog

MB_ButtonInfo struc           ;Collected information of each button
  hWnd        HWND  ?
  Rect        RECT  {}
MB_ButtonInfo ends

MsgBoxInfo struc
  hHook       HANDLE    ?     ;System hook
  hDlg        HWND      ?     ;hDlg
  pCaption    PSTRING   ?     ;Dialog caption string
  pText       PSTRING   ?     ;Main text markup string
  dBandHeight DWORD     ?     ;Drawing help, height of grey band at the bottom of the dialog
  dBtnCount   DWORD     ?     ;Index into MsgBoxBtns
  dFlags      DWORD     ?
  Buttons     MB_ButtonInfo MB_BTN_MAX_COUNT DUP({?})       ;Button information
MsgBoxInfo ends


VIEW_CTRL_ID  equ 165874

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

CStr cErrMsg, "{PA20}", \
              "[FI55]",\
                "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                "[H+2]Critical system failure   - ERRID 521 -  [~]", \
                "[TIP0,F'Webdings',H+1]{#69}[~]{P}", \
                "[C#5F4FFF]", \
                  "[I]Read the instruction manual for more information  [~]", \
                  "[TIP1,F'Webdings',H+1]{#69}[~]", \
                "[~]", \
              "[~]"

CStr cAppMsg, "Application message"

CStr cHlpMsg, "{PA20}", \
              "[B,H+6,C#007F00]Chapter 2[~]{P}", \
              "[H+2]Critical system failure   - ERRID 521 -  [~]{P}", \
              "[U]Description:[~]{P}", \ 
              "[FI25]", \
                "The systen is unable to perform an operation due to low{B}", \
                "system resources. Try to free some memory closing parallel{B}", \
                "running applications or install more memory.", \
              "[~]"

CStr cAppHlp, "Application help"

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local CRect:RECT, cBuffer[100]:CHR

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 350                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height
  
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, \
                         WS_CAPTION or WS_SYSMENU or WS_MINIMIZEBOX, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, \
                         NULL, NULL, hInstance, pSelf
  invoke GetClientRect, [xsi].hWnd, addr CRect

  %invoke CreateWindowEx, 0, offset cTextViewClass&TARGET_STR_AFFIX, offset szMarkupText, \
                         WS_CHILD or WS_VISIBLE, \
                         CRect.left, CRect.top, CRect.right, CRect.bottom, \
                         [xsi].hWnd, VIEW_CTRL_ID, hInstance, 0
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    mov [xsi].pTextView, xax
  .endif

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
  
  invoke MsgBox, [xsi].hWnd, offset cErrMsg, offset cAppMsg, \
                 MB_ABORTRETRYIGNORE or MB_HELP or MB_ICONERROR

  invoke wsprintf, addr cBuffer, $OfsCStr("You pressed the button with an ID = %u"), eax
  invoke MessageBox, [xsi].hWnd, addr cBuffer, $OfsCStr("MsgBox return value"), MB_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout)

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    invoke LoadIcon, hInstance, offset szIcoName
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
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
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Zero brush HANDLE.

Method Application.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetBkColor, wParam, $RGB(140,140,255)
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnHelp
; Purpose:    Event procedure for WM_HELP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.


Method Application.OnHelp, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, lParam
  mov xcx, [xax].HELPINFO.hItemHandle
  invoke MsgBox, xcx, offset cHlpMsg, offset cAppHlp, MB_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method Application.OnNotify, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local Img:$Obj(Image), DstRect:RECT

  SetObject xsi
;  DbgText "Application.OnNotify"
  mov xax, wParam
  .if xax == 0FFFFh
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_TIP
      .if [xdi].TVNM_TIP.dID == 0
        c2m [xdi].TVNM_TIP.pText, $OfsCStr("ERRID 521", 13, \
                                           "The system is not able to perform this ", \
                                           "operation due to low system resources"), xax
      .elseif [xdi].TVNM_TIP.dID == 1
        c2m [xdi].TVNM_TIP.pText, $OfsCStr("Press the help button to open the", 13, \
                                           "instruction manual at chapter 2"), xax
      .endif
    .endif
  .elseif xax == VIEW_CTRL_ID
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_DRAW
      .if [xdi].TVNM_DRAW.dID == 1
        New Img::Image
        OCall Img::Image.Init, xsi
        OCall Img::Image.LoadFromRes, $OfsCStr("DISCOUNT")
        mov DstRect.left, 170
        mov DstRect.top, 150
        mov DstRect.right, 110
        mov DstRect.bottom, 96
        OCall Img::Image.AlphaDraw, [xdi].TVNM_DRAW.hDC, 255, addr DstRect
        OCall Img::Image.Done
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr CRect
  mov xcx, [xsi].pTextView
  .if xcx != NULL
    invoke SetWindowPos, [xcx].$Obj(TextView).hWnd, HWND_BOTTOM, \
                         CRect.left, CRect.top, CRect.right, CRect.bottom, SWP_NOZORDER
  .endif  
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(SdiApp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szApplication, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
