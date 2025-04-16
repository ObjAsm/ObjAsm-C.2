; ==================================================================================================
; Title:      DialogModalIndirect.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of memory template modal dialog objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DialogModal
; Purpose:    Implement a modal dialog from a template.
; Notes:      These objects are destroyed by the OS when a WM_DESTROY is received.
;             They should NOT be destroyed directly by the user!

Object DialogModalIndirect, DialogModalIndirectID, DialogModal
  RedefineMethod    Show
ObjectEnd


; ==================================================================================================

if IMPLEMENT

externdef hInstance:HANDLE

; --------------------------------------------------------------------------------------------------
; Method:     DialogModalIndirect.Show
; Purpose:    Show a modal dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogModalIndirect.Show, uses xsi
  SetObject xsi
  mov xax, $MethodAddr(Dialog.DlgProc)
  invoke DialogBoxIndirectParam, hInstance, [xsi].pTemplate, [xsi].hParent, xax, xsi
MethodEnd

endif
