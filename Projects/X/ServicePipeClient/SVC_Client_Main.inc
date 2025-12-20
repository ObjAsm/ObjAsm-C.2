; ==================================================================================================
; Title:      SVC_Client_Main.inc
; Author:     G. Friedrich
; Notes:      See SVC_Client.asm
; ==================================================================================================


SVC_RESPONSE_MAX_SIZE equ 512                           ;Maximum size of the service response buffer

; --------------------------------------------------------------------------------------------------
; Object:     Application
; Purpose:    Main application dialog.
;             Handles user input, sends commands to the service, and displays responses.

Object Application, ApplicationID, DlgApp
  RedefineMethod    CtlsGet                             ;Read values from dialog controls
  RedefineMethod    CtlsSet                             ;Write values to dialog controls
  RedefineMethod    Init                                ;Application initialization

  VirtualEvent      OnCommand,          WM_COMMAND      ;Handle button clicks and commands
  
  DefineVariable    dSvcCommand,    DWORD,    0         ;Command ID sent to the service
  DefineVariable    bSvcResponse,   BYTE,     SVC_RESPONSE_MAX_SIZE dup(0)
                                                        ;Buffer for service response data
  DefineVariable    dSvcRespSize,   DWORD,    0         ;Number of bytes returned by the service
ObjectEnd


.code
; ==================================================================================================
;    SVC_Client implementation
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  SendPipeCommand
; Purpose:    Send a command to the service using a named pipe.
;             Writes the command ID and reads back the service response.
; Arguments:  Arg1: Command ID.
;             Arg2: Returned bytes.
;             Arg3: -> Response buffer.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

.code
SendPipeCommand proc dCommand:DWORD, dRetSize:DWORD, pRetBuffer:POINTER
  local hPipe:HANDLE, dBytesRW:DWORD                     ;Pipe handle and byte counter

  ;Open the named pipe exposed by the service
  invoke CreateFile, addr cPipeName, GENERIC_READ or GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hPipe, xax

    ;Send the command value to the service
    invoke WriteFile, hPipe, addr dCommand, sizeof dCommand, NULL, 0

    ;Read the response data from the service
    invoke ReadFile, hPipe, pRetBuffer, SVC_RESPONSE_MAX_SIZE, addr dRetSize, 0

    ;Close the pipe handle
    invoke CloseHandle, hPipe
  .endif

  mov eax, TRUE                                         ;Indicate success
  ret
SendPipeCommand endp

; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsGet
; Purpose:    Retrieve values from dialog controls.
;             Reads the command entered by the user.
; Arguments:  None.
; Return:     Nothing.

Method Application.CtlsGet, uses xsi
  local dSuccess:DWORD                                  ;Indicates successful numeric conversion

  SetObject xsi
  invoke GetDlgItemInt, [xsi].hWnd, IDC_EDT_CMD, addr dSuccess, FALSE
  .if dSuccess != FALSE
    mov [xsi].dSvcCommand, eax                          ;Store command value
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsSet
; Purpose:    Update dialog controls.
;             Displays the service response.
; Arguments:  None.
; Return:     Nothing.

Method Application.CtlsSet, uses xsi
  SetObject xsi
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_RESP, [xsi].bSvcResponse, FALSE
                                                        ;Show response in output control
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the application object.
;             Creates the main dialog and sets the window icon.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xsi
  SetObject xsi
  ACall xsi.Init                                        ;Call base initialization

  ;Create the main dialog window
  invoke CreateDialogParam, hInstance, IDD_DLG_MAIN, 0, $MethodAddr(DlgApp.WndProc), xsi

  ;Load and assign application icon
  mov xbx, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_SMALL, xbx
  invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_BIG, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
;             Handles button presses and dialog commands.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If an application processes this message, it should return zero.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam

  .if ax == IDC_BTN_SEND
    OCall xsi.CtlsGet                                   ;Retrieve command from input control
    invoke SendPipeCommand, [xsi].dSvcCommand, addr [xsi].dSvcRespSize, addr [xsi].bSvcResponse
                                                        ;Send command and receive response
    OCall xsi.CtlsSet                                   ;Update response display
    xor eax, eax                                        ;Return zero (message handled)

  .elseif ax == IDOK
    OCall xsi.CtlsGet
    invoke DestroyWindow, [xsi].hWnd                    ;Close dialog
    xor eax, eax                                        ;Return zero

  .elseif ax == IDCANCEL
    invoke DestroyWindow, [xsi].hWnd                    ;Cancel and close dialog
    xor eax, eax                                        ;Return zero

  .else
    xor eax, eax
    inc eax                                             ;Message not handled
  .endif
MethodEnd
