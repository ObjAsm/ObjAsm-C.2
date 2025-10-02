; ==================================================================================================
; Title:      JsonDemo_Main.inc
; Author:     G. Friedrich
; Version:    See JsonDemo.asm
; Purpose:    ObjAsm JSON Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szJsonDemoApp, "OAC_JsonDemoApp"


Object Application, ApplicationID, SdiApp
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT
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

Method Application.Init, uses xbx xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local pPerson:PJSON_PROPERTY, pTools:PJSON_PROPERTY, pTool:PJSON_PROPERTY
  local DskStream:$Obj(DiskStream)
  local wBuffer[100]:CHRW

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szJsonDemoApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary

  New DskStream::DiskStream
  OCall DskStream::DiskStream.Init, xsi, $OfsCStr("Data.json"), GENERIC_READ or GENERIC_WRITE, \
                                    0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0

  DbgLine ;--------------------------------------------------------------------------------
  mov xbx, $New(Json)
  OCall xbx::Json.Init, xsi
  mov [xbx].$Obj(Json).RootProperty.dType, JSON_TYPE_OBJECT

  OCall xbx::Json.AddObject, addr [xbx].$Obj(Json).RootProperty, $OfsCStr("Person")
  mov pPerson, xax
    OCall xbx::Json.AddData, pPerson, $OfsCStr("Name"), JSON_TYPE_STRING, $OfsCStr("John")
    OCall xbx::Json.AddData, pPerson, $OfsCStr("Age"), JSON_TYPE_NUMBER, $OfsCStr("40")
    OCall xbx::Json.AddData, pPerson, $OfsCStr("City"), JSON_TYPE_STRING, $OfsCStr("Amsterdam")

    OCall xbx::Json.AddArray, pPerson, $OfsCStr("Tools")
    mov pTools, xax
      OCall xbx::Json.AddObject, pTools, NULL
      mov pTool, xax
      OCall xbx::Json.AddData, pTool, $OfsCStr("Name"), JSON_TYPE_STRING, $OfsCStr("Screwdriver")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Type"), JSON_TYPE_STRING, $OfsCStr("Torx")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Size"), JSON_TYPE_STRING, $OfsCStr("25")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Weight"), JSON_TYPE_STRING, $OfsCStr("100 gr")

      OCall xbx::Json.AddObject, pTools, NULL
      mov pTool, xax
      OCall xbx::Json.AddData, pTool, $OfsCStr("Name"), JSON_TYPE_STRING, $OfsCStr("Hammer")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Type"), JSON_TYPE_STRING, $OfsCStr("Flat")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Size"), JSON_TYPE_STRING, $OfsCStr("350")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Weight"), JSON_TYPE_STRING, $OfsCStr("500 gr")

      OCall xbx::Json.AddObject, pTools, NULL
      mov pTool, xax
      OCall xbx::Json.AddData, pTool, $OfsCStr("Name"), JSON_TYPE_STRING, $OfsCStr("Pliers")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Type"), JSON_TYPE_STRING, $OfsCStr("Combi")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Size"), JSON_TYPE_STRING, $OfsCStr("200")
      OCall xbx::Json.AddData, pTool, $OfsCStr("Weight"), JSON_TYPE_STRING, $OfsCStr("250 gr")

  OCall xbx::Json.GetProperty, pPerson, $OfsCStr("Age")
  DbgStr [xax].JSON_PROPERTY.pName
  DbgStr [xax].JSON_PROPERTY.pValue

  OCall xbx::Json.GetArrayItem, pPerson, 2
  DbgStr [xax].JSON_PROPERTY.pName
  DbgStr [xax].JSON_PROPERTY.pValue

  OCall xbx::Json.Write, addr DskStream, 0
  Destroy xbx
  OCall DskStream::DiskStream.Done


  DbgLine ;--------------------------------------------------------------------------------
  New DskStream::DiskStream
  OCall DskStream::DiskStream.Init, xsi, $OfsCStr("Data.json"), GENERIC_READ or GENERIC_WRITE, \
                                    0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  mov xbx, $New(Json)
  OCall xbx::Json.Init, xsi
  OCall xbx::Json.Read, addr DskStream, 0

  OCall xbx::Json.GetProperty, addr [xbx].$Obj(Json).RootProperty, $OfsCStr("Person")
  mov pPerson, xax

  OCall xbx::Json.GetProperty, pPerson, $OfsCStr("Age")
  DbgStr [xax].JSON_PROPERTY.pName
  DbgStr [xax].JSON_PROPERTY.pValue

  OCall xbx::Json.GetArrayItem, pPerson, 2
  DbgStr [xax].JSON_PROPERTY.pName
  DbgStr [xax].JSON_PROPERTY.pValue

  Destroy xbx
  OCall DskStream::DiskStream.Done
  
  DbgLine ;--------------------------------------------------------------------------------
  invoke JsonEscEncodeSize, $OfsCStrW("123§")
  DbgDec eax
  invoke JsonEscEncode, $OfsCStrW("123§"), addr wBuffer, sizeof(wBuffer)
  DbgStr wBuffer
  invoke JsonEscDecode, addr wBuffer, addr wBuffer, sizeof(wBuffer), 0
  DbgStr wBuffer

MethodEnd

; --------------------------------------------------------------------------------------------------
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
  c2m WC.lpszClassName, offset szJsonDemoApp, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
