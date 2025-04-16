; ==================================================================================================
; Title:      DialogModelessIndirect.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of memory template modeless dialog objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DialogModelessIndirect
; Purpose:    This object provides the functionality of modeless dialogs created from templates.
;             It is prepared to work seamlessly with the ObjAsm application framework using one of
;             the descendant objects of WinApp, like DlgApp, SdiApp or MdiApp. The hActiveMlsDlg
;             member must be set to the current active modeless so that the application is able to
;             process the correct dialog messages.
; Notes:      These objects are destroyed by the OS when a WM_DESTROY is received.
;             They should NOT be destroyed directly by the user!

Object DialogModelessIndirect, DialogModelessIndirectID, DialogModeless
  RedefineMethod    Show
ObjectEnd


; ==================================================================================================

if IMPLEMENT

externdef hInstance:HANDLE

; --------------------------------------------------------------------------------------------------
; Method:     DialogModelessIndirect.Show
; Purpose:    Show a modeless dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogModelessIndirect.Show, uses xsi
    SetObject xsi
    mov xax, $MethodAddr(Dialog.DlgProc)
    invoke CreateDialogIndirectParam, hInstance, [xsi].pTemplate, [xsi].hParent, xax, xsi
    invoke ShowWindow, xax, SW_SHOW
MethodEnd

endif
