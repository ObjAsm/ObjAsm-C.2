; ==================================================================================================
; Title:      TextViewDemo_Main.inc
; Author:     G. Friedrich
; Version:    See TextViewDemo.asm
; Purpose:    ObjAsm TextView Demo Application.
; ==================================================================================================


CStr szApplication, "OAC_Application"


Object Application, ApplicationID, SdiApp
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,        WM_COMMAND
  VirtualEvent      OnClose,          WM_CLOSE, WM_QUERYENDSESSION
;  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnNotify,         WM_NOTIFY

  DefineVariable    pTextView,  $ObjPtr(TextView)
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

VIEW_CTRL_ID  equ 165874

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local CRect:RECT

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 480                                    ;Default creation width
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
    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL        ;Show the window
    invoke UpdateWindow, [xsi].hWnd                     ;Update if necessary
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
; Method:     Application.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method Application.OnNotify, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local Img:$Obj(Image), DstRect:RECT

  SetObject xsi
  mov xax, wParam
  .if xax == VIEW_CTRL_ID
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_APP_MOUSEUP
      .if [xdi].TVNM_APP.dID == APP_VISIT
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("http:/objasm.x10host.com/index.htm"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_EMAIL
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("mailto:objasm@gmx.net"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_CHECK
        invoke MessageBox, [xsi].hWnd, $OfsCStr("No update available."), \
                                       $OfsCStr("Information"), \
                                       MB_ICONINFORMATION or MB_OK
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TIP
      .if [xdi].TVNM_TIP.dID == INFO_BUILD
        c2m [xdi].TVNM_TIP.pText, offset szBuildInfo, xax

      .elseif [xdi].TVNM_TIP.dID == INFO_UPDATE
        c2m [xdi].TVNM_TIP.pText, offset szUpdateInfo, xax
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_DRAW
      .if [xdi].TVNM_DRAW.dID == 0
        New Img::Image
        OCall Img::Image.Init, xsi
        OCall Img::Image.LoadFromRes, $OfsCStr("OA")
        mov DstRect.left, 15                            ;X-Coord. inside draw area, padding excl.
        mov DstRect.top, 15                             ;Y-Coord. inside draw area, padding excl.
        mov DstRect.right, 100                          ;Width
        mov DstRect.bottom, 100                         ;Height
        OCall Img::Image.AlphaDraw, [xdi].TVNM_DRAW.hDC, 255, addr DstRect
        OCall Img::Image.Done
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
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
