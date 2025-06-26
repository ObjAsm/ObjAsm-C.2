; ==================================================================================================
; Title:      ADE_SimpleInputDlg.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Setup dialog implementation.
; ==================================================================================================


; ==================================================================================================
; SimpleInputDlg implementation
; ==================================================================================================

IDD_DLG_SIMPLEINPUT							equ 5000
IDC_STC_MESSAGE									equ 1001
IDC_EDT_INPUT										equ 1002
IDC_BTN_CANCEL									equ 2
IDC_BTN_OK											equ 1

.code
; --------------------------------------------------------------------------------------------------
; Method:     SimpleInputDialog.Done
; Purpose:    Finalize the SimpleInputDialog object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method SimpleInputDialog.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pMessage
  invoke StrDispose, [xsi].pCaption
  invoke StrDispose, [xsi].pResult
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleInputDialog.CtlsGet
; Purpose:    Get the controls of the dialog.
; Arguments:  None.
; Return:     Nothing.

Method SimpleInputDialog.CtlsGet, uses xbx xdi xsi
  local bBuffer[2048]:CHRA

  SetObject xsi
  invoke GetDlgItemTextA, [xsi].hWnd, IDC_EDT_INPUT, addr bBuffer, lengthof(bBuffer)
  mov [xsi].pResult, $invoke(StrNewA, addr bBuffer) 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleInputDialog.CtlsSet
; Purpose:    Set the controls of the dialog.
; Arguments:  None.
; Return:     eax = This procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method SimpleInputDialog.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  invoke SetDlgItemTextA, [xsi].hWnd, IDC_STC_MESSAGE, [xsi].pMessage
  invoke SetWindowTextA, [xsi].hWnd, [xsi].pCaption
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleInputDialog.Init
; Purpose:    Initialaize a SimpleInputDialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
;             Arg3: -> Message string.
;             Arg4: -> Caption string.
; Return:     Nothing.

.data
align ALIGN_DATA
SimpleInputDialogChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MINMAX or DLF_LIMIT_MIN or DLF_LIMIT_MAX_Y or DLF_ADD_GRIPPER}
DL_CHILD_INFO {{000, 000, 100, 000}}      ;Edit
DL_CHILD_INFO {{000, 000, 100, 000}}      ;Label
DL_CHILD_INFO {{100, 000, 000, 000}}      ;OK Button
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Cancel Button

Method SimpleInputDialog.Init, uses xsi, pOwner:POINTER, hParent:HWND, pMessage:PSTRINGA, pCaption:PSTRINGA
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_SIMPLEINPUT
  c2m [xsi].pDynamicLayout, offset SimpleInputDialogChildrenInfo, xcx
  m2m [xsi].pMessage, pMessage, xax
  m2m [xsi].pCaption, pCaption, xax
MethodEnd
