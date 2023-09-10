; ==================================================================================================
; Title:      ML_GUI_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Multilanguage GUI.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"                       ;Creates szApplication string in .const


Object Application, MySdiAppID, SdiApp                  ;Single Document Interface App.
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnDestroy,  WM_DESTROY
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

TranslateSubMenu proc uses xbx hMenu:HMENU, pWTT:$ObjPtr(WebTextTranslator)
  local MII:MENUITEMINFO, cMenuText[100]:CHR

  xor ebx, ebx
  .repeat
    mov MII.cbSize, sizeof MII
    mov MII.fMask, MIIM_TYPE or MIIM_SUBMENU
    lea xcx, cMenuText
    mov MII.dwTypeData, xcx
    mov MII.cch, lengthof(cMenuText)
    invoke GetMenuItemInfo, hMenu, ebx, TRUE, addr MII
    .if eax == 0
      inc eax
      .break
    .endif
    .if MII.hSubMenu != 0
      DoesStringMatch? cMenuText, <Languages>
      .if !ZERO?
        invoke TranslateSubMenu, MII.hSubMenu, pWTT
        .break .if eax == 0
      .endif
    .endif
    OCall pWTT::WebTextTranslator.Translate, addr cMenuText, $OfsCStr("Menu")
    .if xax == NULL
      .break
    .endif
    mov MII.fMask, MIIM_STRING
    mov MII.dwTypeData, xax
    invoke SetMenuItemInfo, hMenu, ebx, TRUE, addr MII
    inc ebx
  .until FALSE
  ret
TranslateSubMenu endp

TranslateMenu proc hMenu:HMENU, pDstLanguageCode:PSTRING, hParent:HWND
  local WTT:$Obj(WebTextTranslator), dMajorVersion:dWORD
  local MTR:$Obj(MovingThrobber), DefStruc:DEF_MTHROBBER, DST:$Obj(DiskStream)
  local CRect:RECT
  
  PNG_SIZE = 96

  New WTT::WebTextTranslator
  invoke GetWinVersion, addr dMajorVersion, NULL, NULL
  .if dMajorVersion >= 8
    invoke GetClientRect, hParent, addr CRect
    mov eax, CRect.right
    mov ecx, CRect.bottom
    sub eax, PNG_SIZE
    sub ecx, PNG_SIZE
    shr eax, 1
    shr ecx, 1
    mov DefStruc.sdPosX, eax
    mov DefStruc.sdPosY, ecx
    
    mov DefStruc.xCtlID, 123
    mov DefStruc.dStyle, WS_VISIBLE or WS_CHILD
    mov DefStruc.dExStyle, WS_EX_LAYERED
    mov DefStruc.pTitle, NULL
    mov DefStruc.dInterval, 15
    c2m DefStruc.pResList, offset SpinnerList0, xax
    mov DefStruc.dResListCount, SpinnerCount0
    mov DefStruc.dImageType, TBR_IMAGE_PNG

    New MTR::MovingThrobber
    OCall MTR::MovingThrobber.Init, NULL, hParent, addr DefStruc
    OCall MTR::MovingThrobber.Start
  .endif
  OCall WTT::WebTextTranslator.Init, NULL, pDstLanguageCode, offset szSrcLanguageCode
  invoke TranslateSubMenu, hMenu, addr WTT

  ;Save Trnslation to file stream
  New DST::DiskStream
  OCall DST::DiskStream.Init, NULL, offset szTranslationFile, 0, 0, NULL, 0, 0, 0
  OCall WTT::WebTextTranslator.Store, addr DST
  OCall DST::DiskStream.Done
  OCall WTT::WebTextTranslator.Done

  .if dMajorVersion >= 8
    OCall MTR::MovingThrobber.Stop
    .while MTR.dStatus != TBR_STATUS_STOPPED
      invoke Sleep, 30
    .endw
    OCall MTR::MovingThrobber.Done
  .endif
  ret
TranslateMenu endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD, hMenu:HMENU
  local DST:$Obj(DiskStream), DLUT:$Obj(DesLUT), DSI:DESER_INFO, WTT:$Obj(WebTextTranslator)

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  mov hMenu, $invoke(LoadMenu, hInstance, $OfsCStr("MENU_APP"))
  invoke FileExist, offset szTranslationFile
  .if eax != FALSE
    New DLUT::DesLUT
    New WTT::WebTextTranslator
    New DST::DiskStream
    OCall DLUT::DesLUT.Init, NULL, 1000, 1000, COL_MAX_CAPACITY
    lea xax, DLUT
    mov DSI.pDesLUT, xax
    OCall DST::DiskStream.Init, NULL, offset szTranslationFile, 0, 0, NULL, 0, 0, 0
    OCall WTT::WebTextTranslator.Init, NULL, offset szSrcLanguageCode, offset szSrcLanguageCode
    OCall WTT::WebTextTranslator.Load, addr DST, addr DSI
    invoke TranslateSubMenu, hMenu, addr WTT
    OCall DLUT::DesLUT.Done
    OCall DST::DiskStream.Done
    OCall WTT::WebTextTranslator.Done
  .endif
  invoke SetMenu, [xsi].hWnd, hMenu
  invoke DrawMenuBar, [xsi].hWnd

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

AddLanguage macro LangCmd, Code
  .elseif ax == LangCmd
    invoke LoadMenu, hInstance, $OfsCStr("MENU_APP")
    mov xbx, xax
    invoke TranslateMenu, xbx, @CatStr(<$OfsCStr(">Code<")>), [xsi].hWnd
    .if eax != FALSE
      invoke GetMenu, [xsi].hWnd
      invoke DestroyMenu, xax
      invoke SetMenu, [xsi].hWnd, xbx
      invoke DrawMenuBar, [xsi].hWnd
    .else
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Translation failed"), $OfsCStr("Error"), MB_OK or MB_ICONERROR
    .endif
endm

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_LANG_ENGLISH
    invoke GetMenu, [xsi].hWnd
    invoke DestroyMenu, xax
    invoke LoadMenu, hInstance, $OfsCStr("MENU_APP")
    invoke SetMenu, [xsi].hWnd, xax
    invoke DrawMenuBar, [xsi].hWnd
    invoke FileExist, offset szTranslationFile
    .if eax != FALSE
      invoke DeleteFile, offset szTranslationFile
    .endif

  AddLanguage IDM_LANG_BOSNIAN, <bs>
  AddLanguage IDM_LANG_CHINESE, <zh-CN>
  AddLanguage IDM_LANG_CZECH, <cs>
  AddLanguage IDM_LANG_GERMAN, <de>
  AddLanguage IDM_LANG_FRENCH, <fr>
  AddLanguage IDM_LANG_GREEK, <el>
  AddLanguage IDM_LANG_POLNISH, <po>
  AddLanguage IDM_LANG_SPANISH, <es>
  AddLanguage IDM_LANG_RUSSIAN, <ru>

  .elseif ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_APPABOUT
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
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetMenu, [xsi].hWnd
  invoke DestroyMenu, xax
  xor eax, eax
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
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  mov WC.lpszMenuName, NULL;$OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
