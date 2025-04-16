; ==================================================================================================
; Title:      DialogComPortSelection.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm ComPort Selection Dialog.
; Notes:      Version C.1.1, October 2020
;               - First release.
; ==================================================================================================


IDD_DLG_COMPORT_SELECTION equ   5000
IDC_STC_PORT_NAME         equ   1001
IDC_CBO_PORT_NAME         equ   1002
IDC_BTN_SETUP             equ   1003
IDC_STC_LINE              equ   1004
IDC_BTN_OK                equ   IDOK
IDC_BTN_CANCEL            equ   IDCANCEL

COM_FLOWCTRL_NONE         equ   0
COM_FLOWCTRL_XON_XOFF     equ   1
COM_FLOWCTRL_HARDWARE     equ   2

COMPORT_SETUP struct
  cName         CHR       COMPORT_NAME_LEN DUP(?)
  dBaudRate     DWORD     0
  bByteSize     BYTE      0
  bParity       BYTE      0
  bStopBits     BYTE      0
  bFlowControl  BYTE      0
  ComTimeouts   COMMTIMEOUTS  {}                ;Usually {-1, 0, 0, 0, 0}
COMPORT_SETUP ends
PCOMPORT_SETUP typedef ptr COMPORT_SETUP


; --------------------------------------------------------------------------------------------------
; Object:     DialogComPortSelection
; Purpose:    Custom Setup dialog.

Object DialogComPortSelection, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, PCOMPORT_SETUP
  RedefineMethod    OnCommand,      WPARAM, LPARAM

  DefineVariable    pComPortSetup,  PCOMPORT_SETUP, NULL
  DefineVariable    ComPortSetup,   COMPORT_SETUP,  {}
  DefineVariable    pNames,         PCOMPORT_INFO,  NULL
  DefineVariable    dNameCount,     DWORD,          0
ObjectEnd



; ==================================================================================================
;    DialogComPortSelection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DialogComPortSelection.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method DialogComPortSelection.CtlsGet, uses xsi
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_PORT_NAME
  invoke SendMessage, xax, CB_GETCURSEL, 0, 0
  .if eax != CB_ERR
    mov ecx, sizeof(COMPORT_INFO)
    mul ecx
    add xax, [xsi].pNames
    lea xcx, [xsi].ComPortSetup.cName
    invoke StrCCopy, xcx, xax, COMPORT_NAME_LEN - 1
  .else
    mov CHR ptr [xsi].ComPortSetup.cName, 0
  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComPortSelection.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method DialogComPortSelection.CtlsSet, uses xbx xdi xsi
  local cBuffer[1000]:CHR, pNames:PCOMPORT_INFO, hCombo:HWND, dIndex:DWORD, dSelIndex:DWORD

  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_PORT_NAME
  mov hCombo, xax
  invoke SendMessage, hCombo, CB_SETCUEBANNER, 0, $OfsCStr("Click here to select a COM Port")
  mov dSelIndex, CB_ERR
  mov ebx, [xsi].dNameCount
  mov xdi, [xsi].pNames
  test ebx, ebx
  .while !ZERO?
    invoke StrECopy, addr cBuffer, addr [xdi].COMPORT_INFO.cName
    invoke StrECopy, xax, $OfsCStr(" - ")
    invoke StrECopy, xax, [xdi].COMPORT_INFO.pFriendlyName
    invoke SendMessage, hCombo, CB_ADDSTRING, 0, addr cBuffer
    mov dIndex, eax
    invoke StrIComp, addr [xdi].COMPORT_INFO.cName, addr [xsi].ComPortSetup.cName
    .if eax == 0
      m2m dSelIndex, dIndex, ecx
    .endif
    add xdi, sizeof(COMPORT_INFO)
    dec ebx
  .endw

  .if dSelIndex != CB_ERR
    invoke GetDlgItem, [xsi].hWnd, IDC_BTN_SETUP
    invoke EnableWindow, xax, TRUE
  .endif

  invoke SendMessage, hCombo, CB_SETCURSEL, dSelIndex, 0

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComPortSelection.Done
; Purpose:    Finalize the DialogComPortSelection object.
; Arguments:  None.
; Return:     Nothing.

Method DialogComPortSelection.Done, uses xsi
  SetObject xsi
  invoke FreeComPortNames, [xsi].pNames
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComPortSelection.Init
; Purpose:    Initialaize a DialogComPortSelection object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
;             Arg3: -> COMPORT_SETUP.
; Return:     Nothing.

Method DialogComPortSelection.Init, uses xsi, pOwner:POINTER, hParent:HWND, \
                                              pComPortSetup:PCOMPORT_SETUP
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_COMPORT_SELECTION
  mrm [xsi].pComPortSetup, pComPortSetup, xax
  s2s [xsi].ComPortSetup, COMPORT_SETUP ptr [xax], xcx, xdx, xmm1, xmm2   ;Get persistant settings
  invoke GetComPortNames
  mov [xsi].pNames, xax
  mov [xsi].dNameCount, ecx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogComPortSelection.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogComPortSelection.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ComCfg:COMMCONFIG, hComPort:HANDLE

  SetObject xsi
  LoWord(wParam)
  .if ax == IDC_BTN_OK
    OCall xsi.CtlsGet
    mov xax, [xsi].pComPortSetup
    s2s COMPORT_SETUP ptr [xax], [xsi].ComPortSetup, xcx, xdx, xmm1, xmm2  ;Set persistant settings
    OCall xsi.DestroyDialog, wParam

  .elseif ax == IDC_BTN_CANCEL
    OCall xsi.DestroyDialog, wParam

  .elseif ax == IDC_CBO_PORT_NAME
    HiWord(wParam)
    .if ax == CBN_SELCHANGE
      invoke GetDlgItem, [xsi].hWnd, IDC_BTN_SETUP
      invoke EnableWindow, xax, TRUE
    .endif

  .elseif ax == IDC_BTN_SETUP
    HiWord(wParam)
    .if ax == BN_CLICKED
      OCall xsi.CtlsGet

      invoke CreateFile, addr [xsi].ComPortSetup.cName, 0, 0, NULL, OPEN_EXISTING, 0, NULL
      .if xax != INVALID_HANDLE_VALUE
        mov hComPort, xax
        mov ComCfg.dwSize, sizeof(COMMCONFIG)
        mov ComCfg.dcb.DCBlength, sizeof(DCB)
        invoke GetCommState, hComPort, addr ComCfg.dcb      ;Get all current settings
        invoke CloseHandle, hComPort
        mov ComCfg.wVersion, 1
        ;mov ComCfg.wReserved, 0
        mov ComCfg.dwProviderSubType, PST_RS232
        mov ComCfg.dwProviderOffset, 0
        mov ComCfg.dwProviderSize, 0
        mov ComCfg.wcProviderData, 0

        ;Overwrite with persistant settings
        m2m ComCfg.dcb.BaudRate, [xsi].ComPortSetup.dBaudRate, eax
        m2m ComCfg.dcb.ByteSize, [xsi].ComPortSetup.bByteSize, cl
        mrm ComCfg.dcb.Parity, [xsi].ComPortSetup.bParity, al
        .if al != 0
          BitSet ComCfg.dcb.fBits, MASK DCB??1_fParity
        .endif
        m2m ComCfg.dcb.StopBits, [xsi].ComPortSetup.bStopBits, cl

        mov eax, ComCfg.dcb.fBits
        BitClr eax, MASK DCB??1_fInX or MASK DCB??1_fOutX or \
                    MASK DCB??1_fRtsControl or MASK DCB??1_fOutxCtsFlow
        BitSet eax, MASK DCB??1_fBinary
        .if [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl == COM_FLOWCTRL_XON_XOFF
          BitSet eax, MASK DCB??1_fInX or MASK DCB??1_fOutX
        .elseif [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl == COM_FLOWCTRL_HARDWARE
          BitSet eax, MASK DCB??1_fOutxCtsFlow or 2000h   ;MASK DCB??1_fRtsControl high bit
        .endif
        mov ComCfg.dcb.fBits, eax

        ;Show Settings dialog
        invoke CommConfigDialog, addr [xsi].ComPortSetup.cName, [xsi].hWnd, addr ComCfg
        DbgApiError
        .if eax != 0
          ;If succeeded, set new settings in dialog temporary buffer
          m2m [xsi].ComPortSetup.dBaudRate, ComCfg.dcb.BaudRate, eax
          m2m [xsi].ComPortSetup.bByteSize, ComCfg.dcb.ByteSize, cl
          m2m [xsi].ComPortSetup.bParity, ComCfg.dcb.Parity, al
          m2m [xsi].ComPortSetup.bStopBits, ComCfg.dcb.StopBits, cl

          .ifAllBitsClr ComCfg.dcb.fBits, MASK DCB??1_fInX or MASK DCB??1_fOutX
            .ifAllBitsClr ComCfg.dcb.fBits, MASK DCB??1_fRtsControl or MASK DCB??1_fOutxCtsFlow
              mov [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl, COM_FLOWCTRL_NONE
            .else
              mov [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl, COM_FLOWCTRL_HARDWARE
            .endif
          .else
            mov [xsi].ComPortSetup.COMPORT_SETUP.bFlowControl, COM_FLOWCTRL_XON_XOFF
          .endif
        .endif
      .else
        DbgWarning "Cannot open this port"
      .endif
    .endif

  .endif
MethodEnd
