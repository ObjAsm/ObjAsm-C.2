; ==================================================================================================
; Title:      DialogAbout.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of about dialog objects.
; Notes:      Version C.1.1, August 2022
;               - High Contrast support added for the link controls.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DialogAbout
; Purpose:    Generic modal about dialog. It shows a single text on a static control.
;             This dialog uses the DIALOGABOUT resurce which must be located in application resource
;             file (*.rc). DialogAbout.rc may be included for this purpose.

Object DialogAbout, DialogAboutID, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    Init,       POINTER, HWND, HICON, PSTRING

  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC

  DefineVariable    hIcon,      HICON,      0
  DefineVariable    pText,      PSTRING,    NULL
ObjectEnd

IDC_DAB_ICON    equ     100
IDC_DAB_TEXT    equ     101
IDC_DAB_MAIL    equ     102
IDC_DAB_LINK    equ     103

; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:       DialogAbout.CtlsSet
; Purpose:      Setup the controls of the About dialog.
; Arguments:    None.
; Return:       Nothing.

Method DialogAbout.CtlsSet, uses xsi
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_DAB_ICON                   ;Get static icon window HANDLE
  invoke SendMessage, xax, STM_SETICON, [xsi].hIcon, NULL       ;Set icon
  invoke SetDlgItemText, [xsi].hWnd, IDC_DAB_TEXT, [xsi].pText  ;Set static about text
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:       DialogAbout.Init
; Purpose:      Initialize the about dialog using the "DIALOGABOUT" dialog resource.
; Arguments:    Arg1: -> Owner object.
;               Arg2: Parent window HANDLE.
;               Arg3: Icon HANDLE.
;               Arg4: -> About text.
; Return:       Nothing.

Method DialogAbout.Init,, pOwner:POINTER, hParent:HWND, hIcon:HICON, pText:PSTRING
  SetObject xcx
  m2m [xcx].hIcon, hIcon, xax
  m2m [xcx].pText, pText, xdx
  ACall xcx::DialogAbout.Init, pOwner, hParent, $OfsCStr("DIALOGABOUT")
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogAbout.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = 0.

Method DialogAbout.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  local HC:HIGHCONTRAST, dColor1:DWORD, dColor2:DWORD

  SetObject xsi
  mov xax, lParam
  invoke GetDlgItem, [xsi].hWnd, IDC_DAB_MAIL
  .if lParam != xax
    invoke GetDlgItem, [xsi].hWnd, IDC_DAB_LINK
    .if lParam != xax
      jmp @F
    .endif
  .endif

  mov HC.cbSize, sizeof HIGHCONTRAST
  invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, 0, addr HC, FALSE
  .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
    invoke GetSysColor, COLOR_HOTLIGHT
    mov dColor1, eax
    mov dColor2, eax
  .else
    mov dColor1, $RGB(000,000,255)
    mov dColor2, $RGB(128,000,128)
  .endif
  invoke SendMessage, lParam, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != 0
    mov ecx, dColor1
    mov edx, dColor2
    mov [xax].$Obj(Hyperlink).dColor1, ecx
    mov [xax].$Obj(Hyperlink).dColor2, edx
  .endif
@@:
  xor eax, eax
MethodEnd

endif
