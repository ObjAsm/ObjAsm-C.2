; ==================================================================================================
; Title:      MdiApp.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Windows MDI application objects.
; Notes:      Version C.1.1, January 2020
;               - MdiApp.OnNCDestroy moved to WinApp.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef hInstance:HANDLE

IDM_FIRSTCHILD equ 50000                                ;Must be larger than any other menu ID


; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object MdiChildWnd, MdiChildWndID, Window               ;Child window of MdiApp.
  RedefineMethod    OnGetMinMaxInfo,WPARAM, LPARAM 
  RedefineMethod    OnSize,         WPARAM, LPARAM
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnNCDestroy,    WM_NCDESTROY
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object MdiClientWnd, MdiClientWndID, WinPrimer          ;Client window for MdiApp.
  VirtualMethod     Dispatch,       HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Init,           POINTER
  VirtualMethod     WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnNCDestroy,    WM_NCDESTROY

  DefineVariable    pPrevWndProc,   POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   MdiApp
; Purpose:  Implement a base object for Multiple Document Interface applications. It contains all
;           the needed support to build a running Windows application.
; Link:     http://win32assembly.online.fr/tut32.html
;           http://msdn.microsoft.com/en-us/library/ms644908(v=VS.85).aspx   MDI App definition
;           http://windowssdk.msdn.microsoft.com/en-us/library/ms632591.aspx
; Note:     Frame window handle is stored in hWnd.
;
;         —————————————————————————————————————————————————————————
;        | @ Application caption                            _ [] X |
;        |—————————————————————————————————————————————————————————|
;        | File  Edit  ...  ...  Window  Help                     <------ Frame Window
;        |—————————————————————————————————————————————————————————|      Main Menu
;        | ————————  ————————————————————————————————————————————— |
;        ||        ||                                             ||
;        || Other  ||   ——————————————————                        |<----- Client Window
;        || Frame  ||  | Child Title    X |—                      ||
;        || child  ||  |——————————————————| |—                    ||
;        || Window ||  |                  | | |—                  ||<---- Frame Window
;        ||        ||  |                  | | | |—                ||
;        ||        ||  |                  | | | | |               ||
;        ||        ||  |                  | | | | |               ||
;        ||        ||   ——————————————————  | | | |<-- MDI Child  ||
;        ||        ||     ——————————————————  | | |     Windows   ||
;        ||        ||       ——————————————————  | |               ||
;        ||        ||         ——————————————————  |               ||
;        ||        ||           ——————————————————                ||
;        ||        ||                                             ||
;        | ————————  ————————————————————————————————————————————— |
;        |—————————————————————————————————————————————————————————|
;        | Statusbar (Child window of Frame Window)                |
;         —————————————————————————————————————————————————————————
;

Object MdiApp, MdiAppID, WinApp
  RedefineMethod    Run
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  DefineVariable    pClientWnd,     $ObjPtr(MdiClientWnd),     NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    MdiApp implementation
; ==================================================================================================

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:     MdiApp.Done   - code sample-
;; Purpose:    Finalize the MDI application object.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method MdiApp.Done
;  SetObject xcx
;  Destroy [xcx].pClientWnd
;MethodEnd

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:     MdiApp.Init   - code sample-
;; Purpose:    Initialize the MDI application object.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method MdiApp.Init, uses xsi
;  local dWndWidth:DWORD, dWndHeight:DWORD, dWndPosX:DWORD, dWndPosY:DWORD
;
;  SetObject xsi
;  ACall xsi::MdiApp.Init
;  mov [xsi].pCommandLine, $invoke(GetCommandLine)
;
;  ;Create the MDI Frame window
;  mov dWndWidth, 600
;  mov dWndHeight, 450
;  mov dWndPosX, $invoke(CenterForm, dWndWidth, $invoke(GetSystemMetrics, SM_CXSCREEN))
;  mov dWndPosY, $invoke(CenterForm, dWndHeight, $invoke(GetSystemMetrics, SM_CYSCREEN))
;
;  invoke CreateWindowEx, WS_EX_OVERLAPPEDWINDOW or WS_EX_APPWINDOW, \
;                         offset cMdiApp, offset cAppTitle, WS_OVERLAPPEDWINDOW, \
;                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf
;  mov [xsi].pClientWnd, $New(MdiClientWnd)
;  OCall [xsi].pClientWnd::MdiClientWnd).Init, xsi
;  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
;  invoke UpdateWindow, [xsi].hWnd
;MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiApp.Run
; Purpose:    Launch the MDI application object starting the message loop.
; Arguments:  None.
; Return:     eax = Exit code passed to PostQuitMessage.
; Note:       xdi = Idle counter.

Method MdiApp.Run, uses xbx xdi xsi
  local Msg:MSG

  SetObject xsi
  lea xbx, Msg
  xor edi, edi                                          ;Reset idle counter
  .if [xsi].hWnd != 0
    .repeat
      invoke PeekMessage, xbx, 0, 0, 0, PM_REMOVE
      .if eax == FALSE
        OCall xsi.OnIdle, xdi                           ;Pass idle count
        .if eax == 0
          invoke WaitMessage
        .else
          inc xdi
        .endif
      .else
        .break .if Msg.message == WM_QUIT
        .if [xsi].hActiveMlsDlg != 0
          .continue .if $invoke(IsDialogMessage, [xsi].hActiveMlsDlg, xbx) != NULL
        .endif
        invoke TranslateAccelerator, [xsi].hWnd, [xsi].hAccelerators, xbx
        mov xcx, [xsi].pClientWnd
        .if xcx != NULL
          mov xdi, xax
          invoke TranslateMDISysAccel, [xcx].$Obj(MdiClientWnd).hWnd, xbx
          mov xcx, xdi
        .endif
        test xax, xcx
        .if ZERO?                                       ;eax = ecx = FALSE / NULL
          invoke TranslateMessage, xbx
          invoke DispatchMessage, xbx
        .endif
        xor edi, edi                                    ;Reset idle counter
      .endif
    .until FALSE
    mov xax, Msg.wParam
  .else
    mov xax, -1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $PreLinesMdiFrameWndProc
; Purpose:    Pass an additional pre line to the DispatchEvent macro.

$PreLinesMdiFrameWndProc macro
  mov xax, [xsi].$Obj(MdiApp).pClientWnd                ;;These lines expand before @@DefProc label
  .if xax != NULL
    mov xdx, [xax].$Obj(WinPrimer).hWnd
  .else
    xor edx, edx
  .endif
  exitm <DefFrameProc, pSelf, xdx>                      ;;These are the first 3 args of DefFrameProc
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiApp.WndProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method MdiApp.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "MDI Frame Window"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    mrm [xsi].$Obj(MdiApp).hWnd, pSelf, xcx
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set, it returns NULL
    test xax, xax
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif

  ;The $PreLinesMdiFrameWndProc() macro expands before the @@DefProc label!
  DispatchEvent <$PreLinesMdiFrameWndProc()>            ;xsi -> Object Instance
MethodEnd


; ==================================================================================================
;    MdiClientWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiClientWnd.Dispatch
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.

Method MdiClientWnd.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  DispatchEvent <CallWindowProc, [xsi].pPrevWndProc, hWnd>  ;xsi -> Object Instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiClientWnd.Init
; Purpose:    Initialize the MdiClientWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method MdiClientWnd.Init, uses xbx xsi, pOwner:POINTER
  local ClientCreate:CLIENTCREATESTRUCT

  SetObject xsi
  mov xbx, pOwner
  mov ClientCreate.hWindowMenu, NULL
  mov ClientCreate.idFirstChild, IDM_FIRSTCHILD
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, $OfsCStr("MDICLIENT"), 0, \
                         WS_CHILD or WS_CLIPCHILDREN or WS_VISIBLE or WS_VSCROLL or WS_HSCROLL, \
                         0, 0, CW_USEDEFAULT, CW_USEDEFAULT, [xbx].$Obj(MdiApp).hWnd, NULL, \
                         hInstance, addr ClientCreate
  ACall xsi.Init, pOwner, xax
  Subclass MdiClientWnd                                 ;Uses xsi
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiClientWnd.OnNCDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MdiClientWnd.OnNCDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  Unsubclass MdiClientWnd                               ;Uses xsi
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiClientWnd.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window HANDLE is passed in pSelf.
; Return:     eax = Result of the message processing and depends on the message ID.

Method MdiClientWnd.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "MDI Client Window"
  GetSubclassingInst MdiClientWnd, pSelf
  OCall xax::MdiClientWnd.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;    MdiChildWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MdiChildWnd.OnGetMinMaxInfo
; Purpose:   Event procedure for WM_GETMINMAXINFO message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero.

Method MdiChildWnd.OnGetMinMaxInfo, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "MdiChildWnd.OnGetMinMaxInfo"
  SetObject xsi
  ACall xsi.OnGetMinMaxInfo, wParam, lParam
  invoke DefMDIChildProc, [xsi].hWnd, WM_GETMINMAXINFO, wParam, lParam 
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiChildWnd.OnNCDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MdiChildWnd.OnNCDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "MdiChildWnd.OnNCDestroy"
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, GWLP_USERDATA, NULL
  Destroy xsi                                           ;Self destruction!!!
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiChildWnd.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MdiChildWnd.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "MdiChildWnd.OnSize"
  SetObject xsi
  ACall xsi.OnSize, wParam, lParam
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam 
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MdiChildWnd.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window HANDLE is passed in pSelf (hidden parameter).

Method MdiChildWnd.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "MDI Child Window"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xcx, [xax].CREATESTRUCT.lpCreateParams
    mov xsi, [xcx].MDICREATESTRUCT.lParam
    mrm [xsi].$Obj(MdiChildWnd).hWnd, pSelf, xcx        ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax                                       ;  it returns NULL
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefMDIChildProc, pSelf>                ;xsi -> Object Instance
MethodEnd

endif
