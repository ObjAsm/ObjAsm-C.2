; ==================================================================================================
; Title:      IFileDialogApp_Main.inc
; Author:     G. Friedrich
; Version:    See IFileDialog.asm
; Purpose:    ObjAsm IFileDialog Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

CStr szIFileDialogApp, "OAC_Application"

Object Application, ApplicationID, SdiApp
  RedefineMethod    Init
  RedefineMethod    Done
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT
ObjectEnd


; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalizes the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 900                                    ;Default creation width
  mov dWndHeight, 600                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szIFileDialogApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
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

MultiFileSpec struc
  FS0 COMDLG_FILTERSPEC {}
  FS1 COMDLG_FILTERSPEC {}
  FS2 COMDLG_FILTERSPEC {}
  FS3 COMDLG_FILTERSPEC {}
MultiFileSpec ends

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local pIFODlg: POINTER, MFS:MultiFileSpec, pIFileDialog2:POINTER, cBuffer[MAX_PATH]:CHR
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pDisplayName:POINTER, hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_OPEN
    invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, \
                             offset IID_IFileOpenDialog, addr pIFODlg
    .if SUCCEEDED(eax)
      c2m MFS.FS0.pszName, $OfsCStrW("All"), xax
      c2m MFS.FS0.pszSpec, $OfsCStrW("*.*"), xcx
      c2m MFS.FS1.pszName, $OfsCStrW("Assembly"), xax
      c2m MFS.FS1.pszSpec, $OfsCStrW("*.asm"), xcx
      c2m MFS.FS2.pszName, $OfsCStrW("Include"), xax
      c2m MFS.FS2.pszSpec, $OfsCStrW("*.inc"), xcx
      c2m MFS.FS3.pszName, $OfsCStrW("Text"), xax
      c2m MFS.FS3.pszSpec, $OfsCStrW("*.txt"), xcx

      ICall pIFODlg::IFileOpenDialog.SetFileTypes, sizeof(MultiFileSpec)/sizeof(COMDLG_FILTERSPEC), \
                                                   addr MFS
      ICall pIFODlg::IFileOpenDialog.SetFileTypeIndex, 2
      ICall pIFODlg::IFileOpenDialog.SetOptions, FOS_ALLOWMULTISELECT
      ICall pIFODlg::IFileOpenDialog.SetTitle, $OfsCStrW("Select a file...")
      ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, $OfsCStrW("&Select")
      ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, $OfsCStrW("Selected file name: ")

      ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
      .if SUCCEEDED(eax)
        ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, $OfsCStrW("&Cancel")
        ICall pIFileDialog2::IFileDialog2.Release
      .endif

      ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
      .if SUCCEEDED(eax)
        ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
        ICall pISIArr::IShellItemArray.GetCount, addr dCount
        xor ebx, ebx
        .while ebx < dCount
          ICall pISIArr::IShellItemArray.GetItemAt, ebx, addr pIShellItem
          ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDisplayName
          DbgStr pDisplayName
          ICall pIShellItem::IShellItem.Release
          inc ebx
        .endw
        ICall pISIArr::IShellItemArray.Release
      .endif
      ICall pIFODlg::IFileOpenDialog.Release
    .endif
    xor eax, eax

  .elseif ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    mov xbx, $New(DialogAbout)
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall xbx::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall xbx::DialogAbout.Show
    OCall xbx::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL
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

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
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
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szIFileDialogApp, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
