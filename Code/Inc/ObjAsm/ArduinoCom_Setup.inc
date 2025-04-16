; ==================================================================================================
; Title:      ArduinoCom_Setup.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Arduino Communication demonstration program.
; Notes:      Version C.1.0, October 2020
;               - First release.
; ==================================================================================================


; ==================================================================================================
;    DialogComSetup implementation
; ==================================================================================================

BAUDRATE_ENTRY struct
  ID    DWORD   ?
  pStr  PSTRING ?
BAUDRATE_ENTRY ends

.const
BAUDRATE_TABLE label POINTER
  BAUDRATE_ENTRY<CBR_110,    $OfsTStr("110")   >
  BAUDRATE_ENTRY<CBR_300,    $OfsTStr("300")   >
  BAUDRATE_ENTRY<CBR_600,    $OfsTStr("600")   >
  BAUDRATE_ENTRY<CBR_1200,   $OfsTStr("1200")  >
  BAUDRATE_ENTRY<CBR_2400,   $OfsTStr("2400")  >
  BAUDRATE_ENTRY<CBR_4800,   $OfsTStr("4800")  >
  BAUDRATE_ENTRY<CBR_9600,   $OfsTStr("9600")  >
  BAUDRATE_ENTRY<CBR_14400,  $OfsTStr("14400") >
  BAUDRATE_ENTRY<CBR_19200,  $OfsTStr("19200") >
  BAUDRATE_ENTRY<CBR_38400,  $OfsTStr("38400") >
  BAUDRATE_ENTRY<CBR_57600,  $OfsTStr("57600") >
  BAUDRATE_ENTRY<CBR_115200, $OfsTStr("115200")>
  BAUDRATE_ENTRY<CBR_128000, $OfsTStr("128000")>
  BAUDRATE_ENTRY<CBR_256000, $OfsTStr("256000")>
  
  BAUDRATE_ENTRY_COUNT = ($ - BAUDRATE_TABLE)/sizeof(BAUDRATE_ENTRY)

.code
; --------------------------------------------------------------------------------------------------
; Method:     DialogComSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method DialogComSetup.CtlsGet, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pComSetup
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_PORT_NAME
  invoke SendMessage, xax, CB_GETCURSEL, 0, 0
  .if eax != CB_ERR
    mov ecx, sizeof(COMPORT_INFO)
    mul ecx
    add xax, [xsi].pNames
    mov xdx, PSTRING ptr [xax]
    invoke StrCopy, addr [xbx].COMPORT_SETUP.cName, xdx 
  .endif
  
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_BAUDRATE
  invoke SendMessage, xax, CB_GETCURSEL, 0, 0
  .if eax != CB_ERR
    mov ecx, sizeof(BAUDRATE_ENTRY)
    mul ecx
    mov xdx, offset BAUDRATE_TABLE
    add xax, xdx
    mov ecx, [xax].BAUDRATE_ENTRY.ID 
    mov [xbx].COMPORT_SETUP.ComDevice.BaudRate, ecx 
  .endif

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method DialogComSetup.CtlsSet, uses xbx xdi xsi
  local cBuffer[1000]:CHR, pNames:PCOMPORT_INFO, hCombo:HWND

  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_PORT_NAME
  mov hCombo, xax
  mov xdi, [xsi].pNames
  mov ebx, [xsi].dNameCount
  test esi, esi
  .while !ZERO?
    invoke StrECopy, addr cBuffer, [xdi].COMPORT_INFO.pName
    invoke StrECopy, xax, $OfsCStr(" - ")
    invoke StrECopy, xax, [xdi].COMPORT_INFO.pFriendlyName
    invoke SendMessage, hCombo, CB_ADDSTRING, 0, addr cBuffer
    add xdi, sizeof(COMPORT_INFO)
    dec ebx
  .endw
  
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_BAUDRATE
  mov hCombo, xax
  mov ebx, BAUDRATE_ENTRY_COUNT
  mov xdi, offset BAUDRATE_TABLE
  .while !ZERO?
    invoke SendMessage, hCombo, CB_ADDSTRING, 0, [xdi].BAUDRATE_ENTRY.pStr
    add xdi, sizeof(BAUDRATE_ENTRY)
    dec ebx
  .endw

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComSetup.Done
; Purpose:    Finalize the DialogComSetup object.
; Arguments:  None.
; Return:     Nothing.

Method DialogComSetup.Done, uses xsi
  SetObject xsi
  invoke FreeComPortNames, [xsi].pNames
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComSetup.Init
; Purpose:    Initialaize a DialogComSetup object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

Method DialogComSetup.Init, uses xsi, pOwner:POINTER, hParent:HWND, pComSetup:PCOMPORT_SETUP
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_COM_SETUP
  m2m [xsi].pComSetup, pComSetup, xax
  invoke GetComPortNames
  mov [xsi].pNames, xax
  mov [xsi].dNameCount, ecx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComSetup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogComSetup.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xdi, [xsi].pOwner
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    mov xcx, [xsi].pOwner
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .endif
MethodEnd
