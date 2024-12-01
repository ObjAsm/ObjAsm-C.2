; ==================================================================================================
; Title:      CompressedRes_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Compressed Resources.
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"                       ;Creates szApplication string in .const

Object Application, ApplicationID, SdiApp
  RedefineMethod    Done
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,    WM_COMMAND
  VirtualEvent      OnClose,      WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnMouseWheel, WM_MOUSEWHEEL
  VirtualEvent      OnPaint,      WM_PAINT

  DefineVariable    hIcon256,      HICON,    0
  DefineVariable    hIcon128,      HICON,    0
  DefineVariable    hIcon96,       HICON,    0
  DefineVariable    hIcon64,       HICON,    0
  DefineVariable    hIcon48,       HICON,    0
  DefineVariable    hIcon32,       HICON,    0
  DefineVariable    hIcon24,       HICON,    0
  DefineVariable    hIcon16,       HICON,    0

  DefineVariable    dCursorSizeIndex,   DWORD,   0
  DefineVariable    dCursorSize,   DWORD,   32

ObjectEnd                                               ;Ends object definition

ICON_SIZE equ 0

.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Application destructor.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  invoke DestroyIcon, [xsi].hIcon256
  invoke DestroyIcon, [xsi].hIcon128
  invoke DestroyIcon, [xsi].hIcon96
  invoke DestroyIcon, [xsi].hIcon64
  invoke DestroyIcon, [xsi].hIcon48
  invoke DestroyIcon, [xsi].hIcon32
  invoke DestroyIcon, [xsi].hIcon24
  invoke DestroyIcon, [xsi].hIcon16
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
;  local hFileSrc:HANDLE, hFileDst:HANDLE, dSrcDataSize:DWORD, pSrcDataBuffer:POINTER, pDstDataBuffer:POINTER, dDstDataSize:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 575                                    ;Default creation width
  mov dWndHeight, 338                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  mov [xsi].hIcon256, $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"), 256, 256)
  mov [xsi].hIcon128, $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"), 128, 128)
  mov [xsi].hIcon96,  $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"),  96,  96)
  mov [xsi].hIcon64,  $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"),  64,  64)
  mov [xsi].hIcon48,  $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"),  48,  48)
  mov [xsi].hIcon32,  $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"),  32,  32)
  mov [xsi].hIcon24,  $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"),  24,  24)
  mov [xsi].hIcon16,  $invoke(CreateIconFromCompressedFileInRes, hInstance, $OfsCStr("ICON_LZMS"),  16,  16)

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
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
; Method:     Application.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT, PntS:POINTS

  SetObject xsi
  mov xcx, wParam
  sar ecx, 16
  .if SDWORD ptr ecx > 0
    .if [xsi].dCursorSize < 512
      inc [xsi].dCursorSize
    .endif
  .else
    .if [xsi].dCursorSize > 16
      dec [xsi].dCursorSize
    .endif
  .endif
  mov eax, [xsi].dCursorSize
  invoke CreateCursorFromCompressedFileInRes, hInstance, $OfsCStr("CUR_PERSON_LZMS"), eax, eax
  invoke SetClassLongPtr, [xsi].hWnd, GCLP_HCURSOR, xax
  invoke DestroyCursor, xax

  ;Show the new cursor shape
  invoke GetCursorPos, addr Pnt
  invoke SetCursorPos, Pnt.x, Pnt.y

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

  PositionX = 20
  PositionY = 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon256, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionX = PositionX + 256 + 30
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon128, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionY = PositionY + 128 + 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon96, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionX = PositionX + 128 + 30
  PositionY = 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon64, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionY = PositionY + 64 + 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon48, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionY = PositionY + 48 + 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon32, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionY = PositionY + 32 + 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon24, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL
  PositionY = PositionY + 24 + 10
  invoke DrawIconEx, hDC, PositionX, PositionY, [xsi].hIcon16, ICON_SIZE, ICON_SIZE, 0, 0, DI_NORMAL

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
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke CreateBitmapFromCompressedFileInRes, hInstance, $OfsCStr("BMP_BACKGROUND_HUFF")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  invoke CreateCursorFromCompressedFileInRes, hInstance, $OfsCStr("CUR_PERSON_LZMS"), 32, 32
  mov WC.hCursor, xax

  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
