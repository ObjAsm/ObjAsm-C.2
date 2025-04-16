; ==================================================================================================
; Title:      OAE_FindInfoDlg.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    FindInfoDlg implementation for OA_ObjExplorer.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     FindInfoDlg.CtlsSet
; Purpose:    Sets the controls of the dialog.
; Arguments:  None.
; Return:     eax = TRUE to direct Windows to set the keyboard focus. Otherwise FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method FindInfoDlg.CtlsSet, uses xbx xdi xsi
  local cBuffer[1024]:CHR

  SetObject xsi

  ;Set caption and control strings
  mov ebx, $ObjTmpl(Application).dLanguage
  lea xdi, cBuffer

  lea edx, [ebx + IDS_FIND_CAPTION]
  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
  invoke SetWindowText, [xsi].hWnd, xdi

  invoke CheckRadioButton, [xsi].hWnd, IDC_FIND_RBN_OBJ, IDC_FIND_RBN_INT, IDC_FIND_RBN_OBJ

  SetCtrlText IDC_FIND_BTN_SEARCH,  IDS_FIND_SEARCH
  SetCtrlText IDC_FIND_RBN_OBJ,     IDS_FIND_OBJ
  SetCtrlText IDC_FIND_RBN_INT,     IDS_FIND_INT
  SetCtrlText IDC_FIND_STC_HELP,    IDS_FIND_HELP

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:   	FindInfoDlg.Init
; Purpose:  	Initializes a modeless dialog object.
; Arguments:	Arg1: -> Owner object.
;           	Arg2: Parent window handle.
; Return:   	Nothing.

Method FindInfoDlg.Init, uses xsi, pOwner:POINTER, hParent:HANDLE
  SetObject xsi
  lea xax, $ObjTmpl(Application).hActiveMlsDlg
  mov [xsi].pActiveDlgHandle, xax
  ACall xsi.Init, pOwner, hParent, IDD_FIND_DLG
  ;We create here the Modeless Dialog but without showing it. WS_VISIBLE must not be set!
  invoke CreateDialogParam, hInstance, [xsi].pTemplate, [xsi].hParent, \
                            $MethodAddr(FindInfoDlg.DlgProc), xsi   ;lParam passed WM_INITDIALOG
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindInfoDlg.OnActivate
; Purpose:    Event procedure for WM_ACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if processed.

Method FindInfoDlg.OnActivate,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xdx, [xcx].pActiveDlgHandle
  .if xdx != NULL
    mov xax, wParam
    .if ax == WA_INACTIVE
      ;Restore old handle
      m2m HWND ptr [xdx], [xcx].hPrvActiveDlg, xax
    .else
      ;Save the current HANDLE and set our dialog to process its messages
      m2m [xcx].hPrvActiveDlg, HANDLE ptr [xdx], xax
      m2m HWND ptr [xdx], [xcx].hWnd, xax
    .endif
  .endif
  invoke DefWindowProc, [xcx].hWnd, WM_ACTIVATE, wParam, lParam    ;Perform default processing
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindInfoDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method FindInfoDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
    ;Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif

  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDC_FIND_EDIT)
  OCall xsi.CtlsSet

  invoke SetForegroundWindow, [xsi].hWnd
  xor eax, eax                                 ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  InfoMatch
; Purpose:    Used to filter out non matching strings from the ListBox content.
; Arguments:  Arg1: -> INFORMATION.
;             Arg2: -> Filter string.
;             Arg3: ListBox handle.
; Return:     Nothing.

InfoMatch proc pItem:PINFORMATION, pFilter:PSTRING, hListBox:HANDLE
  mov xcx, pItem
  invoke StrIFilter, [xcx].INFORMATION.pName, pFilter
  .if eax != FALSE
    mov xax, pItem
    invoke SendMessage, hListBox, LB_ADDSTRING, 0, [xax].INFORMATION.pName
  .endif
  ret
InfoMatch endp

; --------------------------------------------------------------------------------------------------
; Method:     FindInfoDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindInfoDlg.OnCommand, uses xdi xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  mov xax, wParam
  .if (ax == IDC_FIND_BTN_SEARCH) || (ax == IDOK) || \
      (ax == IDC_FIND_RBN_OBJ) || (ax == IDC_FIND_RBN_INT)
    lea xdi, cBuffer
    invoke GetDlgItem, [xsi].hWnd, IDC_FIND_EDIT
    invoke GetWindowText, xax, xdi, lengthof(cBuffer) - 1
    invoke StrLRTrim, xdi, xdi
    mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FIND_LISTBOX)
    invoke LockWindowUpdate, xbx
    invoke SendMessage, xbx, LB_RESETCONTENT, 0, 0
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_FIND_RBN_OBJ
    mov xcx, $ObjTmpl(Application).pObjDB
    .if eax != FALSE
      OCall [xcx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, offset InfoMatch, xdi, xbx
    .else
      OCall [xcx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, offset InfoMatch, xdi, xbx
    .endif
    invoke LockWindowUpdate, 0
    xor eax, eax

  .elseif ax == IDCANCEL
    invoke ShowWindow, [xsi].hWnd, SW_HIDE
    xor eax, eax

  .elseif ax == IDC_FIND_RBN_OBJ

  .else
    shr eax, 16
    .if ax == LBN_DBLCLK
      mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FIND_LISTBOX)
      invoke SendMessage, xbx, LB_GETCURSEL, 0, 0
      lea xdi, cBuffer
      invoke SendMessage, xbx, LB_GETTEXT, eax, xdi
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_FIND_RBN_OBJ
      .if eax != FALSE
        OCall $ObjTmpl(Application)::Application.Navigate, xdi, INFO_TYPE_OBJECT
      .else
        OCall $ObjTmpl(Application)::Application.Navigate, xdi, INFO_TYPE_INTERFACE
      .endif
      xor eax, eax
    .else
      xor eax, eax
      inc eax
    .endif

  .endif
MethodEnd
