; ==================================================================================================
; Title:      IcmpDstDialog.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm support of DstDlg objects.
; Notes:      Version C.2.0, December 2022
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DstDialog
; Purpose:    Modal Destination input dialog.

Object DstDialog, 0, DialogModal
  RedefineMethod    Init,         POINTER, HWND, POINTER, POINTER
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet

  DefineVariable    ppDestStr,    POINTER,    NULL    ;Application Storage
  DefineVariable    pDestType,    POINTER,    NULL    ;Application Storage
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     DstDialog.CtlsGet
; Purpose:    Do nothing at this stage. It has to be redefined to provide proper functionality.
; Arguments:  None.
; Return:     Nothing.

Method DstDialog.CtlsGet, uses xbx xsi
  local bBuffer[1024]:CHRA

  SetObject xsi
  invoke GetDlgItemTextA, [xsi].hWnd, IDC_EDT_DESTINATION, addr bBuffer, lengthof(bBuffer)
  .if eax != 0
    mov xbx, [xsi].ppDestStr
    invoke StrDisposeA, PSTRINGA ptr [xbx]
    invoke StrNew, addr bBuffer
    mov PSTRINGA ptr [xbx], xax
  .endif
  mov xbx, [xsi].pDestType
  mov DWORD ptr [xbx], DSTTYPE_NONE
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_IPV4
  .if eax == BST_CHECKED
    mov DWORD ptr [xbx], DSTTYPE_IPV4
  .else
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_IPV6
    .if eax == BST_CHECKED
      mov DWORD ptr [xbx], DSTTYPE_IPV6
    .else
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_URL
      .if eax == BST_CHECKED
        mov DWORD ptr [xbx], DSTTYPE_URL
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DstDialog.CtlsSet
; Purpose:    Do nothing at this stage. It has to be redefined to provide proper functionality.
; Arguments:  None.
; Return:     Nothing.

Method DstDialog.CtlsSet, uses xsi
  SetObject xsi
  mov xax, [xsi].ppDestStr
  invoke SetDlgItemTextA, [xsi].hWnd, IDC_EDT_DESTINATION, PSTRINGA ptr [xax]
  mov xax, [xsi].pDestType
  mov ecx, DWORD ptr [xax] 
  .if ecx != DSTTYPE_NONE
    mov eax, IDC_RBN_IPV4
    lea eax, [eax + ecx - 1] 
    invoke CheckRadioButton, [xsi].hWnd, IDC_RBN_IPV4, IDC_RBN_URL, eax
  .endif 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DstDialog.Init
; Purpose:    Initialize the Dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> pDestination ANSI string.
;             Arg4: -> dDestination type.
; Return:     Nothing.

Method DstDialog.Init, uses xsi, pOwner:POINTER, hParent:HWND, ppDestStr:POINTER, pDestType:POINTER
  SetObject xsi
  m2m [xsi].hParent, hParent, xax
  m2m [xsi].ppDestStr, ppDestStr, xcx
  m2m [xsi].pDestType, pDestType, xdx
  ACall xsi.Init, pOwner, hParent, IDD_DLG_DESTINATION
MethodEnd

endif
