; ==================================================================================================
; Title:      WebCam_Main.inc
; Author:     G. Friedrich
; Version:    See WebCam_Main.asm
; Purpose:    ObjAsm WebCam Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szAppClassName, "OAC_WebCamApp"                    ;Creates szAppClassName string in .const

ERROR_BASE = BIT29 + 1000
AddErrMsg WEBCAM_NO_DEVICE_FOUND, "No WebCam found"

TARGET_SIZE_X   equ   320
TARGET_SIZE_Y   equ   240


Object WebCamApp, MySdiAppID, SdiApp                    ;Single Document Interface App.
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnCreate,   WM_CREATE
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

  DefineVariable    hWebCamWnd,     HWND,   0
  DefineVariable    dCaptureIndex,  DWORD,  0

ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    WebCamApp implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WebCamApp.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method WebCamApp.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD

  SetObject xsi
  ACall xsi.Init
  invoke CenterForm, TARGET_SIZE_X, $32($invoke(GetSystemMetrics, SM_CXSCREEN))
  mov dWndPosX, eax
  invoke CenterForm, TARGET_SIZE_Y, $32($invoke(GetSystemMetrics, SM_CYSCREEN))
  mov dWndPosY, eax

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szAppClassName, offset szAppTitle, \
                         WS_OVERLAPPED or WS_MINIMIZEBOX or WS_SYSMENU, \
                         dWndPosX, dWndPosY, TARGET_SIZE_X, TARGET_SIZE_Y, \
                         NULL, NULL, hInstance, pSelf

  invoke SetClientSize, [xsi].hWnd, TARGET_SIZE_X, TARGET_SIZE_Y

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WebCamApp.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method WebCamApp.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout)
  local CapDrvCaps:CAPDRIVERCAPS, CaptureParms:CAPTUREPARMS, hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_WEBCAM_CONNECT
    ;Disconnect the webcam
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DRIVER_CONNECT, [xsi].dCaptureIndex, 0

  .elseif ax == IDM_WEBCAM_DISCONNECT
    ;Disconnect the webcam
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DRIVER_DISCONNECT, 0, 0

  .elseif ax == IDM_WEBCAM_CAPTURE_BMP
    ;Copy the current webcam frame to a DIB file named "CapturedImage.bmp".
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_FILE_SAVEDIB, 0, $OfsCStr("CapturedImage.bmp")

  .elseif ax == IDM_WEBCAM_CAPTURE_AVI
    ;Tell our capture window what AVI filename we want our stream saved as.
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, $OfsCStr("WebCamVideo.avi")
    ;Retrieve the current settings of the streaming webcam capture parameters.
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_GET_SEQUENCE_SETUP, sizeof CaptureParms, addr CaptureParms
    ;Setting fCaptureAudio to FALSE turns audio off and makes a smaller file.
    ;But I wanted to save audio as well as video so I set fCaptureAudio to TRUE.
    mov CaptureParms.fCaptureAudio, TRUE
    ;Set fLimitEnabled to TRUE then place 10 into wTimeLimit for a 10 second recording.
    ;If you panic and decide you want to abort recording press your keyboard [Esc] key.
    mov CaptureParms.fLimitEnabled, TRUE
    mov CaptureParms.wTimeLimit, 10
    ;Set the modified webcam capture parameters we will use for our streaming capture.
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_SET_SEQUENCE_SETUP, sizeof CaptureParms, addr CaptureParms
    ;Begin streaming our video and audio capture to the pre-set AVI filename.
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_SEQUENCE, 0, 0

  .elseif ax == IDM_WEBCAM_DLG_FORMAT
    ;Open up the webcam video format settings dialog.
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DRIVER_GET_CAPS, sizeof CapDrvCaps, addr CapDrvCaps
    .if CapDrvCaps.fHasDlgVideoFormat
      invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0
    .endif

  .elseif ax == IDM_WEBCAM_DLG_SOURCE
    ;Open up the webcam video source settings dialog.
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DRIVER_GET_CAPS, sizeof CapDrvCaps, ADDR CapDrvCaps
    .if CapDrvCaps.fHasDlgVideoSource != FALSE
      invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0
    .endif


  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WebCamApp.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method WebCamApp.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  invoke capCreateCaptureWindow, $OfsCStr("WebCamOut"), WS_VISIBLE or WS_CHILD or WS_BORDER,
                                 0, 0, TARGET_SIZE_X, TARGET_SIZE_Y,
                                 [xsi].hWnd, 0
  .if xax != 0
    mov [xsi].hWebCamWnd, xax
    invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DRIVER_CONNECT, [xsi].dCaptureIndex, 0
    .if eax == FALSE
      OCall xsi.ErrorReport, NULL, WEBCAM_NO_DEVICE_FOUND
      invoke MessageBox, [xsi].hWnd, $OfsCStr("No WebCam found"), \
                         $OfsCStr("Error"), MB_ICONEXCLAMATION or MB_OK
      .else
        invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_SET_SCALE, TRUE, 0
        invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_SET_PREVIEW, TRUE, 0
        invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_SET_PREVIEWRATE, 10, 0
      .endif
    .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WebCamApp.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method WebCamApp.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    .if [xsi].hWebCamWnd != 0
      invoke SendMessage, [xsi].hWebCamWnd, WM_CAP_DRIVER_DISCONNECT, 0, 0
    .endif
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WebCamApp.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method WebCamApp.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WebCamApp.Startup
; Purpose:    Register the WebCamApp window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method WebCamApp.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(SdiApp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szAppClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
