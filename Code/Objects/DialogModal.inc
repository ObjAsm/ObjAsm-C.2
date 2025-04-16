; ==================================================================================================
; Title:      DialogModal.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of modal dialog objects.
; Notes:      This object is destroyed by the OS when WM_DESTROY is received.
;             It should NOT be destroyed by the user!
;             Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DialogModal
; Purpose:    This object is a descendant of Dialog and implements a modal dialog using the
;             DialogBoxParam and EndDialog APIs.

Object DialogModal, DialogModalID, Dialog
  RedefineMethod    DestroyDialog,      XWORD
  RedefineMethod    Show
ObjectEnd


; ==================================================================================================

if IMPLEMENT

externdef hInstance:HANDLE

; --------------------------------------------------------------------------------------------------
; Method:     DialogModal.DestroyDialog
; Purpose:    Destroy a modal dialog.
; Arguments:  Arg1: Windows return value.
; Return:     Nothing.

Method DialogModal.DestroyDialog, uses xsi, xArgument:XWORD
  SetObject xsi
  ACall xsi.DestroyDialog, xArgument
  invoke EndDialog, [xsi].hWnd, xArgument
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogModal.Show
; Purpose:    Show a modal dialog.
; Arguments:  None.
; Return:     Nothing.
; Note:       DialogBoxParam will not show the dialog unless you include the correct x64 manifest!
;             In particular set the correct "processorArchitecture".

Method DialogModal.Show, uses xsi
  SetObject xsi
  mov xax, $MethodAddr(DialogModal.DlgProc)
  invoke DialogBoxParam, hInstance, [xsi].pTemplate, [xsi].hParent, \
                         xax, xsi                       ;lParam in WM_INITDIALOG
  if DEBUGGING
    .if eax == -1
      DbgWarning "DialogModal.Show failed"
      DbgDec [xsi].pTemplate
      DbgApiError
    .endif
  endif
MethodEnd

endif
