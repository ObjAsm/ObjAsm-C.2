; ==================================================================================================
; Title:      DLApp_Main.inc
; Author:     G. Friedrich
; Version:    See DLApp.asm
; Purpose:    ObjAsm Dynamic Window Layout Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szDLApp, "OAC_DynLayoutApplication"                ;Creates szDLApp string in .const


Object DLApp, MySdiAppID, SdiApp                        ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    DLApp implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DLApp.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method DLApp.Done, uses xsi
  SetObject xsi
  invoke DestroyAcceleratorTable, [xsi].hAccelerators
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DLApp.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

.data
align ALIGN_DATA
AppChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LIMIT_MIN or DLF_ADD_GRIPPER, {300,200}, {}}
DL_CHILD_INFO {{100, 100, 000, 000}}

WATERMERK_WIDTH   equ 180
WATERMERK_HEIGHT  equ 045

.code

Method DLApp.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD, CRect:RECT

  SetObject xsi
  ACall xsi.Init

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("ACCEL_APP"))

  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szDLApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf
  invoke GetClientRect, [xsi].hWnd, addr CRect
  sub CRect.right, WATERMERK_WIDTH
  sub CRect.bottom, WATERMERK_HEIGHT
  invoke CreateWindowEx, 0, \
                         $OfsCStr("Static"), $OfsCStr("  The ObjAsm Company  "), \
                         WS_VISIBLE or WS_CHILD or SS_CENTER or SS_CENTERIMAGE, \
                         CRect.right, CRect.bottom, WATERMERK_WIDTH, WATERMERK_HEIGHT, \
                         [xsi].hWnd, 10, hInstance, 0

  c2m [xsi].pDynamicLayout, offset AppChildrenInfo, xcx
  OCall xsi.InitWindow

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DLApp.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

.data
align ALIGN_DATA
DlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MIN or DLF_LIMIT_MINMAX or DLF_ADD_GRIPPER, {}, {600, 400}}
DL_CHILD_INFO {{100, 100, 000, 000}}      ;Ok button
DL_CHILD_INFO {{000, 000, 100, 100}}      ;Group
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button 1
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button 1
DL_CHILD_INFO {{000, 000, 100, 100}}      ;Edit control
DL_CHILD_INFO {{100, 100, 000, 000}}      ;Cancel button

.code
Method DLApp.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), DLW:$Obj(DialogModal), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_DIALOG
    New DLW::DialogModal
    OCall DLW::DialogModal.Init, xsi, [xsi].hWnd, 1000
    c2m DLW.pDynamicLayout, offset DlgChildrenInfo, xcx
    OCall DLW::DialogModal.Show
    OCall DLW::DialogModal.Done
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
; Method:     DLApp.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DLApp.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     DLApp.Startup
; Purpose:    Register the DLApp window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method DLApp.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(SdiApp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szDLApp, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
