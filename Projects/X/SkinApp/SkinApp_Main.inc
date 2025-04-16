; ==================================================================================================
; Title:      SkinApp_Main.asm
; Author:     G. Friedrich
; Version:    See SkinApp.asm
; Purpose:    ObjAsm Skined Application.
; ==================================================================================================


Object Application, ApplicationID, SdiApp               ;Single Document Interface App.
  RedefineMethod    Done
  VirtualMethod     DrawButtons
  VirtualMethod     DrawCaptionText
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnActivateApp,    WM_ACTIVATEAPP
  VirtualEvent      OnCommand,        WM_COMMAND
  VirtualEvent      OnClose,          WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCreate,         WM_CREATE
  VirtualEvent      OnEnable,         WM_ENABLE
  VirtualEvent      OnNcActivate,     WM_NCACTIVATE
  VirtualEvent      OnNcCreate,       WM_NCCREATE
  VirtualEvent      OnNcPaint,        WM_NCPAINT
  VirtualEvent      OnPaint,          WM_PAINT
  VirtualEvent      OnRButtonUp,      WM_RBUTTONUP

  DefineVariable    hContextMenu,     HMENU,      0
  DefineVariable    dActiveCaption,   DWORD,      FALSE

  Embed   Skin,           ElasticSkin
  Embed   IconImageList,  MaskedImageList
  Embed   BtnClose,       RgnButton
  Embed   BtnMaximize,    RgnButton
  Embed   BtnMinimize,    RgnButton
  Embed   Bug,            GifPlayer
  Embed   Menu,           XMenu
ObjectEnd


; ==================================================================================================
;    Application implementation
; ==================================================================================================

CLSSTYLE          equ   CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or \
                        CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

TBSTYLE           equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                        CCS_NORESIZE or CCS_NOPARENTALIGN or CCS_NODIVIDER or CCS_ADJUSTABLE or \
                        TBSTYLE_FLAT or TBSTYLE_LIST

IDC_BTNCLOSE      equ   8000
IDC_BTNMINIMIZE   equ   8001
IDC_BTNMAXIMIZE   equ   8002
IDC_BTNSTART      equ   8003
IDC_BTNSTOP       equ   8004

CStr szSkinApp, "OAC_SkinApp"

.const
RgnBtnClose     DEF_REGIONBUTTON {IDC_BTNCLOSE,    0, 0, 0, 0, $OfsTStr("BUTTON_SYSCLOSE")}
RgnBtnMinimize  DEF_REGIONBUTTON {IDC_BTNMINIMIZE, 0, 0, 0, 0, $OfsTStr("BUTTON_SYSMINIMIZE")}
RgnBtnMaximize  DEF_REGIONBUTTON {IDC_BTNMAXIMIZE, 0, 0, 0, 0, $OfsTStr("BUTTON_SYSMAXIMIZE")}


.code

; --------------------------------------------------------------------------------------------------
; Method:    Application.Done
; Purpose:   Finalize the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  invoke DestroyMenu, [xsi].hContextMenu
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].BtnClose::RgnButton.Done
  OCall [xsi].BtnMaximize::RgnButton.Done
  OCall [xsi].BtnMinimize::RgnButton.Done
  OCall [xsi].Bug::GifPlayer.Done
  OCall [xsi].Menu::XMenu.Done
  OCall [xsi].Skin::ElasticSkin.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.DrawButtons
; Purpose:   Draw the Close, Minimize and Maximize buttons.
; Arguments: None.
; Return:    Nothing.

Method Application.DrawButtons, uses xsi
  local Rct:RECT

  SetObject xsi

  invoke GetClientRect, [xsi].hWnd, addr Rct
  mov eax, Rct.right
  sub eax, 29
  invoke SetWindowPos, [xsi].BtnClose.hWnd,    HWND_TOP, eax,10, 0, 0, SWP_NOSIZE or SWP_NOCOPYBITS
  invoke SetWindowPos, [xsi].BtnMinimize.hWnd, HWND_TOP, 18, 10, 0, 0, SWP_NOSIZE or SWP_NOCOPYBITS
  invoke SetWindowPos, [xsi].BtnMaximize.hWnd, HWND_TOP, 38, 10, 0, 0, SWP_NOSIZE or SWP_NOCOPYBITS
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.DrawCaptionText
; Purpose:   Draw the application caption.
; Arguments: Active state.
; Return:    Nothing.

Method Application.DrawCaptionText, uses xbx xsi
  local hDC:HDC, dPrvColor:DWORD, dPrvBkMode:DWORD, pCaptionText:PSTRING

  SetObject xsi
  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)

; Uncomment the following lines to visualize the title rect area.
;  mov xbx, $invoke(CreateSolidBrush, $RGB(126,134,127))
;  invoke FillRect, hDC, addr [xsi].Skin.TitleRect, xbx
;  invoke DeleteObject, xbx

  invoke GetWindowTextLength, [xsi].hWnd              ;Returns the character count without ZTC
  inc eax                                             ;Add place for the ZTC
  mov ebx, eax
  mov pCaptionText, $invoke(StrAlloc, eax)            ;Get some memory to get the caption
  invoke GetWindowText, [xsi].hWnd, xax, ebx
  mov dPrvBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  .if [xsi].dActiveCaption == 0
    mov ecx, COLOR_SCROLLBAR
  .else
    mov ecx, COLOR_3DHILIGHT
  .endif
  invoke GetSysColor, ecx
  mov dPrvColor, $32($invoke(SetTextColor, hDC, eax))
  invoke DrawTextEx, hDC, pCaptionText, -1, addr [xsi].Skin.TitleRect, \
                     DT_CENTER or DT_VCENTER or DT_SINGLELINE or DT_END_ELLIPSIS, NULL
  invoke SetTextColor, hDC, dPrvColor
  invoke SetBkMode, hDC, dPrvBkMode
  invoke StrDispose, pCaptionText                     ;Free the memory

  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.Init
; Purpose:   Initialize the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method Application.Init, uses xbx xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init

  invoke LoadCommonControls, ICC_BAR_CLASSES

  ;Load application & menu icons
  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")

  mov dWndWidth, 500
  mov dWndHeight, 350
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  mov [xsi].hContextMenu, $invoke(LoadMenu, hInstance, $OfsCStr("MENU_APP"))

  invoke CreateWindowEx, 0, \
                         offset szSkinApp, offset szAppTitle, WS_POPUP, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  ;Create XMenu
  OCall [xsi].Menu::XMenu.Init, xsi, [xsi].hWnd, 0, 0, xbx, NULL, 0
  OCall [xsi].Menu::XMenu.Convert, [xsi].hContextMenu, TRUE

  ;Initialize GifPlayer
  OCall [xsi].Bug::GifPlayer.Init, xsi, [xsi].hWnd, $OfsCStr("BUGGY"), 0, 0, 110, 80, 9000

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnActivateApp
; Purpose:   Event procedure for WM_ACTIVATEAPP message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnActivateApp, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  and eax, 01b
  mov [xsi].dActiveCaption, eax
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_ACTIVATEAPP, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local Dlg:$Obj(SkinnedMsgBox)

  SetObject xsi
  New Dlg::SkinnedMsgBox
  OCall Dlg::SkinnedMsgBox.Init, xsi, [xsi].hWnd, 50, 51, $OfsCStr("ALERT"), \
                                                          $OfsCStr("BUTTON_YES"), IDYES, \
                                                          $OfsCStr("BUTTON_NO"), IDNO
  OCall Dlg::SkinnedMsgBox.Show
  mov ebx, eax
  OCall Dlg::SkinnedMsgBox.Done
  mov eax, ebx
  .if eax == IDYES
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .else
    invoke SetForegroundWindow, [xsi].hWnd
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WP:WINDOWPLACEMENT, Dlg:$Obj(SkinnedDialogAbout)

  SetObject xsi
  mov xax, wParam
  .if (ax ==  IDM_EXIT) || (ax == IDC_BTNCLOSE)
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax
  .elseif ax == IDC_BTNMINIMIZE
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_MINIMIZE, NULL
    xor eax, eax
  .elseif ax == IDC_BTNMAXIMIZE
    mov WP.length_, sizeof WINDOWPLACEMENT
    invoke GetWindowPlacement, [xsi].hWnd, addr WP
    .if WP.showCmd == SW_SHOWMAXIMIZED
      mov eax, SC_RESTORE
    .else
      mov eax, SC_MAXIMIZE
    .endif
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, eax, NULL
    xor eax, eax
  .elseif ax == IDM_ABOUT
    New Dlg::SkinnedDialogAbout
    OCall Dlg::SkinnedDialogAbout.Init, xsi, [xsi].hWnd, $OfsCStr("SkinnedDialogAbout")
    OCall Dlg::SkinnedDialogAbout.Show
    OCall Dlg::SkinnedDialogAbout.Done
    invoke SetForegroundWindow, [xsi].hWnd
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnCreate
; Purpose:   Event procedure for WM_CREATE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall [xsi].BtnClose::RgnButton.Init, xsi, [xsi].hWnd, offset RgnBtnClose
  OCall [xsi].BtnMinimize::RgnButton.Init, xsi, [xsi].hWnd, offset RgnBtnMinimize
  OCall [xsi].BtnMaximize::RgnButton.Init, xsi, [xsi].hWnd, offset RgnBtnMaximize
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnEnable
; Purpose:   Event procedure for WM_ENABLE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnEnable, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  and eax, 01b
  mov [xsi].dActiveCaption, eax
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_ENABLE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnNcActivate
; Purpose:   Event procedure for WM_NCACTIVATE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = TRUE => Windows will proceed with default processing.

Method Application.OnNcActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  and eax, 01b
  mov [xsi].dActiveCaption, eax
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_NCACTIVATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnNcCreate
; Purpose:   Event procedure for WM_NCCREATE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.
; Important: Create the ElasticSkin object here to intercept messages as soon as possible.

Method Application.OnNcCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall [xsi].Skin::ElasticSkin.Init, xsi, [xsi].hWnd, $OfsCStr("WNDSKIN"), TRUE
  invoke DefWindowProc, [xsi].hWnd, WM_NCCREATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnNcPaint
; Purpose:   Event procedure for WM_NCPAINT message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnNcPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall xsi.DrawCaptionText
  OCall xsi.DrawButtons
  invoke DefWindowProc, [xsi].hWnd, WM_NCPAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnPaint
; Purpose:   Event procedure for WM_PAINT message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local Rct1:RECT, Rct2:RECT

  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr Rct1
  invoke GetClientRect, [xsi].Bug.hWnd, addr Rct2
  mov eax, Rct1.right
  sub eax, Rct2.right
  shr eax, 1
  mov ebx, Rct1.bottom
  sub ebx, Rct2.bottom
  shr ebx, 1
  add ebx, 10
  invoke SetWindowPos, [xsi].Bug.hWnd, HWND_TOP, eax, ebx, 0, 0, SWP_NOSIZE or SWP_NOCOPYBITS

  invoke DefWindowProc, [xsi].hWnd, WM_PAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.OnRButtonUp
; Purpose:   Event procedure for WM_RBUTTONUP message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method Application.OnRButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  mov xax, lParam                                       ;Convert clicked X position
  mov Pnt.y, eax
  and eax, 0FFFFh
  mov Pnt.x, eax
  shr Pnt.y, 16
  invoke ClientToScreen, [xsi].hWnd, addr Pnt           ;Convert clicked position to screen coords
  invoke GetSubMenu, [xsi].hContextMenu, 0              ;Get "Context" submenu
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, \          ;Show the popup menu
                         Pnt.x, Pnt.y, 0, [xsi].hWnd, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.Startup
; Purpose:   Register the object class with the OS.
; Arguments: None.
; Return:    Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, NULL
  mov WC.lpszMenuName, NULL
  c2m WC.lpszClassName, offset szSkinApp, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC
MethodEnd
