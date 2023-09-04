; ==================================================================================================
; Title:      QR_Code_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm QR_Code.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"                       ;Creates szApplication string in .const


Object Application, MySdiAppID, SdiApp                  ;Single Document Interface App.
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

QrDraw proc uses xbx xdi xsi hDC:HDC, pQrCode:POINTER, sdX:SDWORD, sdY:SDWORD, dSize:DWORD, dBorder:DWORD
  local Rct:RECT, dQrSize:DWORD, hBlackBrush:HBRUSH

  mov esi, dSize
  invoke qrcodegen_getSize, pQrCode
  mov dQrSize, eax
  mov ecx, dBorder
  shl ecx, 1
  add eax, ecx
  xor edx, edx
  mul esi
  mrm Rct.left, sdX, edx
  add edx, eax
  mov Rct.right, edx
  mrm Rct.top, sdY, edx
  add edx, eax
  mov Rct.bottom, edx
  invoke GetStockObject, WHITE_BRUSH
  lea xdx, Rct
  invoke FillRect, hDC, xdx, xax

  invoke GetStockObject, BLACK_BRUSH
  mov hBlackBrush, xax
  xor edi, edi
  .while edi < dQrSize
    xor ebx, ebx
    .while ebx < dQrSize
      invoke qrcodegen_getModule, pQrCode, ebx, edi
      .if eax != 0
        mov eax, ebx
        add eax, dBorder
        xor edx, edx
        mul esi
        add eax, sdX
        mov Rct.left, eax
        add eax, esi
        mov Rct.right, eax

        mov eax, edi
        add eax, dBorder
        xor edx, edx
        mul esi
        add eax, sdY
        mov Rct.top, eax
        add eax, esi
        mov Rct.bottom, eax
        lea xdx, Rct
        invoke FillRect, hDC, xdx, hBlackBrush
      .endif
      inc ebx
    .endw
    inc edi
  .endw
  ret
QrDraw endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 235                                    ;Default creation width
  mov dWndHeight, 280                                   ;Default creation height
  
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

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
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT
  local QrCode[qrcodegen_BUFFER_LEN_MAX]:BYTE, tempBuffer[qrcodegen_BUFFER_LEN_MAX]:BYTE

  QR_BORDER = 4
  QR_OFFSET_X = 25
  QR_OFFSET_Y = 25
  QR_CELL_SIZE = 5

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke qrcodegen_encodeText, $OfsCStrA("Hello ObjAsm World", 21h), addr tempBuffer, addr QrCode, \
                               qrcodegen_Ecc_LOW, qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, \
                               qrcodegen_Mask_AUTO, TRUE
  .if eax != FALSE
    invoke QrDraw, hDC, addr QrCode, QR_OFFSET_X, QR_OFFSET_Y, QR_CELL_SIZE, QR_BORDER
  .endif
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
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
