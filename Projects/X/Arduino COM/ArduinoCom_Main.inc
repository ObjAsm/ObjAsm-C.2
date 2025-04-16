; ==================================================================================================
; Title:      ArduinoCom_Main.inc
; Author:     G. Friedrich
; Version:    See ArduinoCom.asm
; Purpose:    ObjAsm Arduino Communication program.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szArduinoApp, "OAC_ArduinoApp"                     ;Creates szArduinoApp string in .const


Object Application, ApplicationID, SdiApp
  RedefineMethod    Init             
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

  DefineVariable    hComPort,     HANDLE,         INVALID_HANDLE_VALUE
  DefineVariable    ComPortSetup, COMPORT_SETUP,  {{0}, \
                                                   9600, 8, 0, 0, COM_FLOWCTRL_NONE, \  ;8N1 default
                                                   {-1, 0, 0, 0, 0}}

ObjectEnd


.code

; ==================================================================================================
;    Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szArduinoApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf
  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("ACCEL_APP"))

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR
  local ComDCB:DCB                                      ;device-control block
  local AboutDlg:$Obj(DialogAbout), hIcon:HICON
  local ComPortSelDlg:$Obj(DialogComPortSelection)
  local dBytesWritten:DWORD, dBytesRead:DWORD

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_SELECTION

    New ComPortSelDlg::DialogComPortSelection
    OCall ComPortSelDlg::DialogComPortSelection.Init, xsi, [xsi].hWnd, addr [xsi].ComPortSetup
    OCall ComPortSelDlg::DialogComPortSelection.Show
    OCall ComPortSelDlg::DialogComPortSelection.Done
    xor eax, eax

  .elseif ax == IDM_CONNECT
    .if [xsi].hComPort != INVALID_HANDLE_VALUE
      invoke CloseHandle, [xsi].hComPort
      mov [xsi].hComPort, INVALID_HANDLE_VALUE
    .endif
    .if [xsi].ComPortSetup.cName != 0
      FillString cBuffer, <\.\>
      lea xcx, [cBuffer + 3*sizeof(CHR)]
      invoke StrCopy, xcx, addr [xsi].ComPortSetup.cName
      invoke CreateFile, addr cBuffer, GENERIC_READ or GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL
      mov [xsi].hComPort, xax
      .if xax != INVALID_HANDLE_VALUE
        invoke ClearCommError, xax, NULL, NULL
        mov ComDCB.DCBlength, sizeof(DCB)
        invoke GetCommState, [xsi].hComPort, addr ComDCB

        ;Overwrite with persistant settings
        m2m ComDCB.BaudRate, [xsi].ComPortSetup.dBaudRate, eax
        m2m ComDCB.ByteSize, [xsi].ComPortSetup.bByteSize, cl
        mrm ComDCB.Parity, [xsi].ComPortSetup.bParity, al
        .if al != 0
          BitSet ComDCB.fBits, MASK DCB??1_fParity
        .endif
        m2m ComDCB.StopBits, [xsi].ComPortSetup.bStopBits, cl

        mov eax, ComDCB.fBits
        BitClr eax, MASK DCB??1_fInX or MASK DCB??1_fOutX or \
                    MASK DCB??1_fRtsControl or MASK DCB??1_fOutxCtsFlow
        BitSet eax, MASK DCB??1_fBinary
        .if [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl == COM_FLOWCTRL_XON_XOFF
          BitSet eax, MASK DCB??1_fInX or MASK DCB??1_fOutX
        .elseif [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl == COM_FLOWCTRL_HARDWARE
          BitSet eax, MASK DCB??1_fOutxCtsFlow or 2000h   ;MASK DCB??1_fRtsControl high bit
        .endif
        mov ComDCB.fBits, eax

        invoke SetCommState, [xsi].hComPort, addr ComDCB
        invoke SetCommTimeouts, [xsi].hComPort, addr [xsi].ComPortSetup.ComTimeouts
        
      .else
        invoke MessageBox, [xsi].hWnd, $OfsCStr("COM connection failed."), $OfsCStr("Error"), \
                           MB_OK or MB_ICONERROR
      .endif
    .else
      invoke MessageBox, [xsi].hWnd, $OfsCStr("COM Port not defined."), $OfsCStr("Error"), \
                         MB_OK or MB_ICONERROR
    .endif
    xor eax, eax

  .elseif ax == IDM_DISCONNECT
    invoke CloseHandle, [xsi].hComPort
    mov [xsi].hComPort, INVALID_HANDLE_VALUE
    xor eax, eax

  .elseif ax == IDM_TRANSMIT
    invoke WriteFile, [xsi].hComPort, $OfsCStrA("PC is here"), 11, addr dBytesWritten, NULL
    xor eax, eax

  .elseif ax == IDM_RECIEVE
    invoke ReadFile, [xsi].hComPort, addr cBuffer, sizeof(cBuffer - 1), addr dBytesRead, NULL
    .if dBytesRead != 0
      lea xdx, cBuffer
      mov eax, dBytesRead
      mov CHRA ptr [xdx + xax], 0                       ;Set ZTC
      invoke MessageBoxA, [xsi].hWnd, xdx, $OfsCStrA("Recieved string"), \
                          MB_OK or MB_ICONINFORMATION
    .else 
      invoke MessageBox, [xsi].hWnd, $OfsCStr("No string recieved."), $OfsCStr("Error"), \
                         MB_OK or MB_ICONERROR
    .endif
    xor eax, eax

  .elseif ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New AboutDlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
    OCall AboutDlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall AboutDlg::DialogAbout.Show
    OCall AboutDlg::DialogAbout.Done
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szArduinoApp, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
