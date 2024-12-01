; ==================================================================================================
; Title:      NetComClient.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szNetComClient, "OAC_NetComClient"                 ;Creates szNetComClient string in .const

BUFFERSIZE  equ   2048

Object SendDlg,, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM
  RedefineMethod    OnCommand,      WPARAM, LPARAM

  DefineVariable    ServerAddr,     NETCOMADDR, {}
  DefineVariable    dRepetitions,   DWORD,      1
  DefineVariable    cText,          CHR,        BUFFERSIZE dup(0)
  DefineVariable    dConnections,   DWORD,      1

  Embed   Connections,    Collection                    ;For simplicity in place of the linked list
ObjectEnd


Object NetComClient, ApplicationID, SdiApp                 ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnTimer,    WM_TIMER

  Embed  Client,    NetComEngine
  Embed  SndDlg,    SendDlg
ObjectEnd


include NetComClient_Protocol.inc


.code

if IMPLEMENT

.data

bPayload db "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod ",
            "tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At ",
            "vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, ",
            "no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit ",
            "amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut ",
            "labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam ",
            "et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata ",
            "sanctus est Lorem ipsum dolor sit amet."
.code

; ==================================================================================================
;    NetComClient implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.Done
; Purpose:
; Arguments:  None.
; Return:

Method NetComClient.Done, uses xsi
  SetObject xsi
  invoke KillTimer, [xsi].hWnd, 123
  OCall [xsi].Client::NetComEngine.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.Init
; Purpose:    Initalizes the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local cCaption[512]:CHR, cAddrStr[100]:CHR, dLength:DWORD

  SetObject xsi
  ACall xsi.Init

  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  sub dWndPosX, 300
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szNetComClient, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary

  OCall [xsi].Client::NetComEngine.Init, xsi, 3, 5, 5, MSS_ETHERNET_IPVX
  OCall $ObjTmpl(NetComClientProtocol)::NetComClientProtocol.Init, xsi, $OfsCStr("25773")

  ;Set the transmitted text
  lea xdx, [xsi].SndDlg
  invoke MemClone, addr [xdx].$Obj(SendDlg).cText, offset bPayload, sizeof bPayload

  ;For this test, we set the Server address (Remote Host) to the Local Host address.
  invoke MemClone, addr [xsi].SndDlg.ServerAddr, addr [xsi].Client.LocalHostAddr, sizeof NETCOMADDR

  ;Set application caption
  mov dLength, lengthof(cAddrStr)
  lea xcx, [xsi].Client
  invoke GetNameInfo, addr [xcx].$Obj(NetComEngine).LocalHostAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST
  invoke StrECopy, addr cCaption, offset szAppTitle
  invoke StrECopy, xax, $OfsCStr(" - ")
  lea xdx, [xsi].Client
  invoke StrECopy, xax, [xdx].$Obj(NetComEngine).pLocalHostName
  invoke StrECopy, xax, $OfsCStr(" at ")
  lea xdx, cAddrStr
  invoke StrCopy, xax, xdx
  invoke SetWindowText, [xsi].hWnd, addr cCaption

  invoke SetTimer, [xsi].hWnd, 123, 100, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method NetComClient.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_SEND
    OCall [xsi].SndDlg::SendDlg.Init, xsi, [xsi].hWnd
    OCall [xsi].SndDlg::SendDlg.Show
    OCall [xsi].SndDlg::SendDlg.Done
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
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
; Method:     NetComClient.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method NetComClient.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     NetComClient.OnTimer
; Purpose:    Display status information on the window client area.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method NetComClient.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  mov xbx, $invoke(GetDC, [xsi].hWnd)
  invoke GetSysColor, COLOR_WINDOWTEXT
  invoke SetTextColor, xbx, eax
;  invoke SetBkMode, xbx, TRANSPARENT

  lea xdi, cBuffer

  XPOS = 20
  YPOS = -10

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Workers = %lu         "), [xsi].Client.dWorkerCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Listeners = %lu         "), [xsi].Client.Listeners.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Connections = %lu       "), [xsi].Client.Connections.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#IOJobs = %lu            "), [xsi].Client.IOJobs.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#In Bytes = %lu          "), [xsi].Client.dBytesIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#In Rate = %lu kbit/s           "), [xsi].Client.dRateIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Out Bytes = %lu          "), [xsi].Client.dBytesOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Out Rate = %lu kbit/s           "), [xsi].Client.dRateOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  invoke ReleaseDC, [xsi].hWnd, xbx
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.Startup
; Purpose:    Registers the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(NetComClient.WndProc), xax
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szNetComClient, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC
MethodEnd


; ==================================================================================================
;    SendDlg implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       SendDlg.CtlsGet
; Purpose:      Gets the controls in this dialog window.
; Arguments:    None.
; Return:       eax: TRUE if the dialog can be closed, otherwise FALSE.

Method SendDlg.CtlsGet, uses xsi
  local cAddress[100]:CHR, cServiceName[100]:CHR, Hints:ADDRINFOT, pResult:PADDRINFOT

  SetObject xsi
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_ADDRESS, addr cAddress, lengthof cAddress
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, addr cServiceName, lengthof cServiceName
  mov Hints.ai_flags, AI_NUMERICHOST
  mov Hints.ai_family, AF_INETX
  mov Hints.ai_socktype, SOCK_STREAM
  mov Hints.ai_protocol, IPPROTO_TCP
  mov Hints.ai_addrlen, 0
  mov Hints.ai_canonname, NULL
  mov Hints.ai_addr, NULL
  mov Hints.ai_next, NULL
  invoke GetAddrInfo, addr cAddress, addr cServiceName, addr Hints, addr pResult
  mov xax, pResult
  invoke MemClone, addr [xsi].ServerAddr, [xax].ADDRINFOT.ai_addr, \
                   DWORD ptr [xax].ADDRINFOT.ai_addrlen
  invoke FreeAddrInfo, pResult
  invoke StrDispose, $ObjTmpl(NetComClientProtocol).pServiceName
  mov $ObjTmpl(NetComClientProtocol).pServiceName, $invoke(StrNew, addr cServiceName)
  mov [xsi].dConnections, $32($invoke(GetDlgItemInt, [xsi].hWnd, IDC_EDT_CONNECTIONS, NULL, FALSE))
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_DATA, addr [xsi].cText, BUFFERSIZE
  mov [xsi].dRepetitions, $32($invoke(GetDlgItemInt, [xsi].hWnd, IDC_EDT_REPETITIONS, NULL, FALSE))
  xor eax, eax
  inc eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.CtlsSet
; Purpose:    Sets the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method SendDlg.CtlsSet, uses xsi
  local cAddrStr[100]:CHR

  SetObject xsi
  invoke GetNameInfo, addr [xsi].ServerAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_ADDRESS, addr cAddrStr
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, $ObjTmpl(NetComClientProtocol).pServiceName
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_CONNECTIONS, [xsi].dConnections, FALSE
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_DATA, addr [xsi].cText
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_REPETITIONS, [xsi].dRepetitions, FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.Done
; Purpose:    Finalize the Dialog object.
; Arguments:  None.
; Return:     Nothing.

Method SendDlg.Done, uses xsi
  SetObject xsi
  OCall [xsi].Connections::Collection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.Init
; Purpose:    Initialize the Dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method SendDlg.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_SEND
  OCall [xsi].Connections::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero.

Method SendDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ACall xsi.OnInitDialog, wParam, lParam
  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

DisconnectAndFree proc uses xsi pConnection:$ObjPtr(NetComConnection), Unused1:XWORD, Unused2:XWORD
  OCall pConnection::NetComConnection.Disconnect, SD_SEND
  OCall pConnection::NetComConnection.QueueFree
  ret
DisconnectAndFree endp

Method SendDlg.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[BUFFERSIZE + 20]:CHR

  SetObject xsi
  mov xdi, [xsi].pOwner                                 ;xdi -> NetComClient
  LoWord wParam
  .if eax == IDC_BTN_CONNECT
    .if $OCall(xsi.CtlsGet) != FALSE
      mov ebx, [xsi].dConnections
      test ebx, ebx
      .while !ZERO?
        OCall [xdi].$Obj(NetComClient).Client::NetComEngine.ConnectTo, \
                                                          offset $ObjTmpl(NetComClientProtocol), \
                                                          addr [xsi].ServerAddr
        OCall [xsi].Connections::Collection.Insert, xax
        dec ebx
      .endw
    .endif
    xor eax, eax

  .elseif eax == IDC_BTN_SEND
    .if $OCall(xsi.CtlsGet) != FALSE
      xor ebx, ebx
      .while ebx < [xsi].dRepetitions
        invoke dword2dec, addr cBuffer, ebx
        invoke StrCat, addr cBuffer, $OfsCStr(" - ")
        invoke StrCat, addr cBuffer, addr [xsi].cText
        mov xdx, $MethodAddr(NetComConnection.QueueWrite)
        invoke StrLength, addr cBuffer
        inc eax                                         ;Include terminating zero!
        OCall [xsi].Connections::Collection.ForEach, xdx, addr cBuffer, xax
        inc ebx
      .endw
    .endif
    xor eax, eax

  .elseif eax == IDC_BTN_DISCONNECT
    OCall [xsi].Connections::Collection.ForEach, offset DisconnectAndFree, 0, 0
    OCall [xsi].Connections::Collection.DeleteAll
    xor eax, eax

  .elseif eax == IDCANCEL
    OCall [xsi].Connections::Collection.ForEach, offset DisconnectAndFree, 0, 0
    OCall [xsi].Connections::Collection.DeleteAll
    OCall xsi.DestroyDialog, wParam
    xor eax, eax

  .else
    xor eax, eax
    inc eax

  .endif
MethodEnd

endif
