; ==================================================================================================
; Title:      DialogPassword.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of password entry objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


IDC_DPW_GIF     equ     100
IDC_DPW_TEXT1   equ     101
IDC_DPW_EDIT    equ     102
IDC_DPW_TEXT2   equ     103

MAXPASSWORDSIZE equ     32

; --------------------------------------------------------------------------------------------------
; Object:  DialogPassword
; Purpose: Implement a modal dialog to enter an access password.

Object DialogPassword, DialogPasswordID, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HWND, PSTRING, PSTRING, DWORD
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  DefineVariable    pPassword,          PSTRING,    NULL
  DefineVariable    pTitle,             PSTRING,    NULL
  DefineVariable    dMaxTries,          DWORD,      1
  DefineVariable    dTryCount,          DWORD,      0
  DefineVariable    cResponse,          CHR,        MAXPASSWORDSIZE dup(0)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     DialogPassword.CtlsGet
; Purpose:    Read the typed password.
; Arguments:  None.
; Return:     Nothing.

Method DialogPassword.CtlsGet, uses xsi
  SetObject xsi
  invoke GetDlgItemText, [xsi].hWnd, IDC_DPW_EDIT, addr [xsi].cResponse, MAXPASSWORDSIZE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogPassword.CtlsSet
; Purpose:    Set the controls of the Password dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogPassword.CtlsSet, uses xsi
  SetObject xsi
  invoke SetWindowText, [xsi].hWnd, [xsi].pTitle
  invoke SetDlgItemText, [xsi].hWnd, IDC_DPW_EDIT, NULL

  .if [xsi].dTryCount == 0
    xor eax, eax
  .else
    mov ecx, [xsi].dTryCount
    inc ecx
    .if ecx == [xsi].dMaxTries
      mov xax, $OfsCStr("Attention:  Last try !!")
    .else
      mov xax, $OfsCStr("Attention:  Wrong password !!")
    .endif
  .endif
  invoke SetDlgItemText, [xsi].hWnd, IDC_DPW_TEXT2, xax
  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDC_DPW_EDIT)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogPassword.Init
; Purpose:    Initialize a Password dialog.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method DialogPassword.Init,, pOwner:POINTER, hParent:HWND, \
                             pTitle:PSTRING, pPassword:PSTRING, dMaxTries:DWORD
  SetObject xcx
  m2m [xcx].pTitle, pTitle, xax
  m2m [xcx].pPassword, pPassword, xdx
  m2m [xcx].dMaxTries, dMaxTries, xax
  ACall xcx.Init, pOwner, hParent, $OfsCStr("DIALOGPASSWORD")
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogPassword.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If an application processes this message, it should return zero.

Method DialogPassword.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == IDOK
    OCall xsi.CtlsGet
    inc [xsi].dTryCount
    invoke StrCComp, addr [xsi].cResponse, [xsi].pPassword, MAXPASSWORDSIZE
    .if eax != 0
      mov ecx, [xsi].dTryCount
      .if ecx == [xsi].dMaxTries
        OCall xsi.DestroyDialog, FALSE
      .else
        OCall xsi.CtlsSet
      .endif
    .else
      OCall xsi.DestroyDialog, TRUE
    .endif
  .elseif wParam == IDCANCEL
    OCall xsi.DestroyDialog, FALSE
  .endif
MethodEnd

endif
