; ==================================================================================================
; Title:      GUI_Template_Main.inc
; Author:     G. Friedrich
; Purpose:    ObjAsm OpenAI Application.
; Notes:      See OpenAIApp.asm
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"                       ;Creates szApplication string in .const

Object Application, ApplicationID, DlgApp               ;Dialog App.
  RedefineMethod    CtlsGet
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,    WM_COMMAND
  VirtualEvent      OnClose,      WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnSysCommand, WM_SYSCOMMAND

  DefineVariable    pPrompt,      PSTRING

  Embed   AI,       OpenAI
  Embed   Throbber, MovingThrobber

ObjectEnd                                               ;Ends object definition


; ==================================================================================================
;    Application implementation
; ==================================================================================================

;Prompt: Write a one-sentence bedtime story about a unicorn.

THROBBER_SIZE equ 96

.const
szEmpty CHR 0

.data
MthbDefStruc DEF_MTHROBBER {{100, WS_VISIBLE or WS_CHILD, 0, NULL, 0, 0, 15, TBR_IMAGE_PNG}, \
                            offset ThrobberList, ThrobberCount}
.code
; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsGet
; Purpose:    Retrieve the prompt and store it.
; Arguments:  None.
; Return:     Nothing.

Method Application.CtlsGet, uses xbx xdi xsi
  SetObject xsi
  invoke StrDispose, [xsi].pPrompt
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_EDT_PROMPT)
  mov edi, $32($invoke(GetWindowTextLength, xbx))
  mov [xsi].pPrompt, $invoke(StrAlloc, edi)
  invoke GetWindowText, xbx, xax, edi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pPrompt
  OCall [xsi].Throbber::MovingThrobber.Done
  OCall [xsi].AI::OpenAI.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

.data
align ALIGN_DATA
DlgMainInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MIN or DLF_LIMIT_MIN or DLF_ADD_GRIPPER, {}, {800, 600}}
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Prompt Label
DL_CHILD_INFO {{000, 000, 100, 050}}      ;Prompt Edit
DL_CHILD_INFO {{100, 050, 000, 000}}      ;Send button
DL_CHILD_INFO {{000, 050, 000, 000}}      ;Answer Label
DL_CHILD_INFO {{000, 050, 100, 050}}      ;Answer Edit
DL_CHILD_INFO {{100, 100, 000, 000}}      ;Exit button

Method Application.Init, uses xsi
  SetObject xsi
  ACall xsi.Init
  c2m [xsi].pDynamicLayout, offset DlgMainInfo, xcx
  invoke CreateDialogParam, hInstance, IDD_DLG_APPLICATION, 0, $MethodAddr(DlgApp.WndProc), xsi
  invoke LoadIcon, hInstance, offset szIcoName
  invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_BIG, xax         ;Set icon
  invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_SMALL, xax       ;Set icon

  OCall [xsi].Throbber::MovingThrobber.Init, xsi, [xsi].hWnd, addr MthbDefStruc
  OCall [xsi].AI::OpenAI.Init, xsi, $OfsCStr("gpt-5")
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, WRect:RECT

  SetObject xsi
  mov xax, wParam
  .if ax == IDC_BTN_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == IDC_BTN_SEND
    ;Get the prompt and reset the Answer Edit control
    OCall xsi.CtlsGet                                   ;Set [xsi].pPrompt
    invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_ANSWER, addr szEmpty
    invoke UpdateWindow, [xsi].hWnd

    ;Calc throbber placement and move it to the center of the application dialog
    invoke GetWindowRect, [xsi].hWnd, addr WRect
    mov edx, WRect.right
    sub edx, WRect.left
    sub edx, THROBBER_SIZE
    shr edx, 1
    mov eax, WRect.bottom
    sub eax, WRect.top
    sub eax, THROBBER_SIZE
    shr eax, 1
    invoke MoveWindow, [xsi].Throbber.hWnd, edx, eax, THROBBER_SIZE, THROBBER_SIZE, FALSE

    ;Show the throbber
    OCall [xsi].Throbber::MovingThrobber.Start

    ;Send the prompt to the AI
    ;DbgStr [xsi].pPrompt
    if 1
    OCall [xsi].AI::OpenAI.SendPrompt, [xsi].pPrompt
    mov xdi, $OCall([xsi].AI::OpenAI.GetResponse)       ;xdi -> Answer
    .if xdi == NULL
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Ups, something went wrong."), \
                         $OfsCStr("Error"), MB_OK or MB_ICONERROR
    .endif
    else
    invoke Sleep, 2500
    xor edi, edi
    endif

    ;Hide the throbber and show the AI answer
    OCall [xsi].Throbber::MovingThrobber.Stop
    invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_ANSWER, xdi
    invoke StrDispose, xdi

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
; Method:     Application.OnSysCommand
; Purpose:    Event procedure for WM_SYSCOMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSysCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Dlg:$Obj(DialogAbout)

  SetObject xsi
  mov xax, wParam
  and xax, 0FFF0h
  .if eax == SC_CONTEXTHELP
    invoke SetCursor, $invoke(LoadCursor, 0, IDC_ARROW)   ;Reset cursor
    New Dlg::DialogAbout
    invoke LoadIcon, hInstance, offset szIcoName
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
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
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
