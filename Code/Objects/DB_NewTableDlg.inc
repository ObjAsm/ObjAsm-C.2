; ==================================================================================================
; Title:      DB_NewTableDlg.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database Index dialog.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------

Object DB_NewTableDlg,, DialogModal
  VirtualMethod     CtlsEnable
  RedefineMethod    Init,             POINTER, HWND, PSTRING

  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM

  DefineVariable    hEdtFileName,     HANDLE,   0
  DefineVariable    hBtnOK,           HANDLE,   0
  DefineVariable    pFileName,        PSTRING,  NULL
ObjectEnd


.code

; ==================================================================================================
;    DB_NewTableDlg implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DB_NewTableDlg.CtlsEnable
; Purpose:    Enables the controls if the input is valid.
; Arguments:  None.
; Return:     eax = TRUE if the input values are valid, otherwise FALSE.

Method DB_NewTableDlg.CtlsEnable, uses xsi
  SetObject xsi
  invoke SendMessage, [xsi].hEdtFileName, WM_GETTEXTLENGTH, 0, 0
  .if eax != 0
    invoke EnableWindow, [xsi].hBtnOK, TRUE
    mov eax, TRUE
    ExitMethod
  .endif
  invoke EnableWindow, [xsi].hBtnOK, FALSE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_NewTableDlg.Init
; Purpose:    Initialize the DB_NewTableDlg object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> File Name buffer.
; Return:     Nothing.

Method DB_NewTableDlg.Init,, pOwner:POINTER, hParent:HWND, pFileName:PSTRING
  SetObject xcx
  m2m [xcx].pFileName, pFileName, xax 
  ACall xcx.Init, pOwner, hParent, IDD_NEW_TABLE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_NewTableDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_NewTableDlg.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if eax == IDC_NEWTABLE_EDT_FILE_NAME or EN_CHANGE shl 16
    OCall xsi.CtlsEnable
    xor eax, eax

  .elseif eax == IDOK
    invoke SendMessage, [xsi].hEdtFileName, WM_GETTEXT, \
                        LOCAL_BUFFER_SIZE/sizeof(CHR), [xsi].pFileName
    OCall xsi.DestroyDialog, wParam
    xor eax, eax

  .elseif ax == IDCANCEL 
    OCall xsi.DestroyDialog, wParam
    xor eax, eax

  .else
    mov eax, 1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_NewTableDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE.

Method DB_NewTableDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_NewTableDlg.OnInitDialog"
  SetObject xsi
  ACall xsi.OnInitDialog, wParam, lParam

  ;Get Control handles
  mov [xsi].hEdtFileName, $invoke(GetDlgItem, [xsi].hWnd, IDC_NEWTABLE_EDT_FILE_NAME)
  mov [xsi].hBtnOK,       $invoke(GetDlgItem, [xsi].hWnd, IDC_NEWTABLE_BTN_OK)

  OCall xsi.CtlsEnable

  mov eax, TRUE                                         ;Let Windows set the default keyboard focus
MethodEnd
