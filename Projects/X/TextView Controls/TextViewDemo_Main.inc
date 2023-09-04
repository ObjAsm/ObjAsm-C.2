; ==================================================================================================
; Title:      TextViewDemo_Main.inc
; Author:     G. Friedrich
; Version:    See TextViewDemo.asm
; Purpose:    ObjAsm TextView Demo Application with Controls.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "OAC_Application"


Object Application, MySdiAppID, SdiApp
  RedefineMethod    Init
  StaticMethod      Startup
  RedefineMethod    OnSize,           WPARAM, LPARAM
  RedefineMethod    OnGetMinMaxInfo,  WPARAM, LPARAM

  VirtualEvent      OnCommand,        WM_COMMAND
  VirtualEvent      OnClose,          WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnNotify,         WM_NOTIFY

  DefineVariable    pTextView,  $ObjPtr(TextView)

  DefineVariable    dRadioBtn1,       DWORD,    TRUE
  DefineVariable    dRadioBtn2,       DWORD,    FALSE
  DefineVariable    dCheckBox1,       DWORD,    FALSE
  DefineVariable    dCheckBox2,       DWORD,    FALSE
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

VIEW_CTRL_ID    equ   165874
WND_MAX_WIDTH   equ   1000
WND_MAX_HEIGHT  equ   600
WND_MIN_WIDTH   equ   400
WND_MIN_HEIGHT  equ   200

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
  mov dWndWidth, WND_MAX_WIDTH                          ;Default creation width
  mov dWndHeight, WND_MAX_HEIGHT                        ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, \
                         NULL, NULL, hInstance, pSelf
  invoke GetClientRect, [xsi].hWnd, addr CRect

  %invoke CreateWindowEx, 0, offset cTextViewClass&TARGET_STR_AFFIX, offset szMarkupText, \
                         WS_CHILD or WS_VISIBLE, \
                         CRect.left, CRect.top, CRect.right, CRect.bottom, \
                         [xsi].hWnd, VIEW_CTRL_ID, hInstance, 0
  .if xax != 0
    mov [xsi].pTextView, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
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
  invoke SetBkColor, wParam, $RGB(240,240,240)
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnGetMinMaxInfo
; Purpose:    Event procedure for WM_GETMINMAXINFO message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnGetMinMaxInfo,, wParam:WPARAM, lParam:LPARAM
  mov xcx, lParam
  mov [xcx].MINMAXINFO.ptMaxTrackSize.x, WND_MAX_WIDTH
  mov [xcx].MINMAXINFO.ptMinTrackSize.x, WND_MIN_WIDTH
  mov [xcx].MINMAXINFO.ptMaxTrackSize.y, WND_MAX_HEIGHT
  mov [xcx].MINMAXINFO.ptMinTrackSize.y, WND_MIN_HEIGHT
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

TVCHAR_RB_CHECKED   equ   025C9h
TVCHAR_RB_UNCHECKED equ   025CBh

;If you use symbol fonts, you habe to "and 0F000h" each character in order that DrawText can render
;the symbol properly. For unkown reasons, that API applies a mapping for this type of fonts from
;range 00020-000FFh to 0F020-0F0FFh.
;http://masm32.com/board/index.php?topic=8524.msg102726#msg102726
TVCHAR_CB_CHECKED   equ   0F052h
TVCHAR_CB_UNCHECKED equ   0F0A3h

CStrW TVRadioBtnChecked, TVCHAR_RB_CHECKED
CStrW TVRadioBtnUnChecked, TVCHAR_RB_UNCHECKED
CStrW TVCheckBoxChecked, TVCHAR_CB_CHECKED
CStrW TVCheckBoxUnChecked, TVCHAR_CB_UNCHECKED

SetRBTextFrom proc pVariable:POINTER, ppText:POINTER
  mov xbx, ppText
  mov xdi, pVariable
  invoke StrDispose, PSTRINGW ptr [xbx]
  .if DWORD ptr [xdi] == FALSE
    mov xcx, offset TVRadioBtnUnChecked
  .else
    mov xcx, offset TVRadioBtnChecked
  .endif
  mov PSTRINGW ptr [xbx], $invoke(StrNewW, xcx)
  ret
SetRBTextFrom endp

SetCBTextFrom proc pVariable:POINTER, ppText:POINTER
  mov xbx, ppText
  mov xdi, pVariable
  invoke StrDispose, PSTRINGW ptr [xbx]
  .if DWORD ptr [xdi] == FALSE
    mov xcx, offset TVCheckBoxUnChecked
  .else
    mov xcx, offset TVCheckBoxChecked
  .endif
  mov PSTRINGW ptr [xbx], $invoke(StrNewW, xcx)
  ret
SetCBTextFrom endp

Method Application.OnNotify, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local Img:$Obj(Image), DstRect:RECT

  SetObject xsi
  mov xax, wParam
  .if xax == VIEW_CTRL_ID
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_APP_MOUSEUP
      .if [xdi].TVNM_APP.dID == 0
        .if [xsi].dRadioBtn1 == FALSE
          mov [xsi].dRadioBtn1, TRUE
          mov [xsi].dRadioBtn2, FALSE
        .else
          mov [xsi].dRadioBtn1, FALSE
        .endif
        mov xbx, [xsi].pTextView
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == 1
        .if [xsi].dRadioBtn2 == FALSE
          mov [xsi].dRadioBtn2, TRUE
          mov [xsi].dRadioBtn1, FALSE
        .else
          mov [xsi].dRadioBtn2, FALSE
        .endif
        mov xbx, [xsi].pTextView
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == 2
        .if [xsi].dCheckBox1 == FALSE
          mov [xsi].dCheckBox1, TRUE
        .else
          mov [xsi].dCheckBox1, FALSE
        .endif
        mov xbx, [xsi].pTextView
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == 3
        .if [xsi].dCheckBox2 == FALSE
          mov [xsi].dCheckBox2, TRUE
        .else
          mov [xsi].dCheckBox2, FALSE
        .endif
        mov xbx, [xsi].pTextView
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == APP_VISIT
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("http:/www.google.com"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_CHECK
        invoke MessageBox, [xsi].hWnd, $OfsCStr("This is a notification message."), \
                                       $OfsCStr("Information"), \
                                       MB_ICONINFORMATION or MB_OK
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TIP
      .if [xdi].TVNM_TIP.dID == 0
        c2m [xdi].TVNM_TIP.pText, $OfsCStr("UpdateInfo"), xax
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TXT
      .if [xdi].TVNM_TXT.dID == 0
        invoke SetRBTextFrom, addr [xsi].dRadioBtn1, [xdi].TVNM_TXT.ppText
      .elseif [xdi].TVNM_TXT.dID == 1
        invoke SetRBTextFrom, addr [xsi].dRadioBtn2, [xdi].TVNM_TXT.ppText
      .elseif [xdi].TVNM_TXT.dID == 2
        invoke SetCBTextFrom, addr [xsi].dCheckBox1, [xdi].TVNM_TXT.ppText
      .elseif [xdi].TVNM_TXT.dID == 3
        invoke SetCBTextFrom, addr [xsi].dCheckBox2, [xdi].TVNM_TXT.ppText

      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  .if wParam != SIZE_MINIMIZED
    invoke GetClientRect, [xsi].hWnd, addr CRect
    mov xbx, [xsi].pTextView
    .if xbx != NULL
      invoke SetWindowPos, [xbx].$Obj(TextView).hWnd, HWND_BOTTOM, \
                           CRect.left, CRect.top, CRect.right, CRect.bottom, SWP_NOZORDER
    .endif
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
