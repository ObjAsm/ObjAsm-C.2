; ==================================================================================================
; Title:      DialogAboutIndirect.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of about dialog objects.
; Notes:      Version C.1.1, August 2022
;               - High Contrast support added for the link controls. 
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DialogAboutIndirect
; Purpose:    Same functionality as DialogAbout, but using a memory template.
; Notes:      These object is destroyed by the OS when WM_DESTROY is received.
;             It should NOT be destroyed by the user!
;
; IMPORTANT!!!
;
; Don't forget to include the following lines before DialogAboutIndirect:
;
; --> LoadObjects Button, Hyperlink
;     LoadObjects Dialog, DialogModal, DialogModalIndirect, DialogAboutIndirect
;

Object DialogAboutIndirect, DialogAboutIndirectID, DialogModalIndirect
  RedefineMethod    CtlsSet
  RedefineMethod    Init,       POINTER, HWND, HICON, PSTRING

  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC

  DefineVariable    hIcon,      HICON,    0
  DefineVariable    pText,      POINTER,  NULL
ObjectEnd

IDC_DAB_ICON    equ     100
IDC_DAB_TEXT    equ     101
IDC_DAB_MAIL    equ     102
IDC_DAB_LINK    equ     103

; ==================================================================================================

if IMPLEMENT


; Memory template

.const
DIALOGEX DIALOGABOUTINDIRECT, 0,0, 200,108,0,5, \
            WS_CHILD or DS_MODALFRAME or DS_3DLOOK or DS_CENTER or DS_CENTERMOUSE or \
            WS_CAPTION or WS_SYSMENU or WS_POPUP or DS_SETFONT, WS_EX_LAYERED, \
            0, , "About", "Segoe UI", 9, 700, FALSE, ANSI_CHARSET

DEFPUSHBUTTON   "OK", IDOK, 136,80,50,16, WS_TABSTOP
CTEXT           NULL, IDC_DAB_TEXT, 46,10,140,55
ICON            "ICON_APP", IDC_DAB_ICON, 13,9,32,32
CONTROL         NULL, -1, "Static", SS_BLACKFRAME or SS_SUNKEN, 45,68,143,1
HYPERLINK       "ICON_MAIL|Send us an Email|mailto:objasm@gmx.net", \
                IDC_DAB_MAIL, 10,74,100,14, WS_TABSTOP
HYPERLINK       "ICON_LINK|Visit our Homepage|http://objasm.x10host.com", \
                IDC_DAB_LINK, 10,87,100,14, WS_TABSTOP

.code
; --------------------------------------------------------------------------------------------------
; Method:     DialogAboutIndirect.CtlsSet
; Purpose:    Setup the controls of the About dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogAboutIndirect.CtlsSet, uses xsi
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_DAB_ICON                   ;Get static icon window handle
  invoke SendMessage, xax, STM_SETICON, [xsi].hIcon, NULL       ;Set icon
  invoke SetDlgItemText, [xsi].hWnd, IDC_DAB_TEXT, [xsi].pText  ;Set static about text
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogAboutIndirect.Init
; Purpose:    Initialize the About dialog.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: Application icon HANDLE.
;             Arg2: -> About text.
; Return:     Nothing.

Method DialogAboutIndirect.Init,, pOwner:POINTER, hParent:HWND, hAppIcon:HICON, pAboutText:PSTRING
  SetObject xcx
  m2m [xcx].hIcon, hAppIcon, xax
  m2m [xcx].pText, pAboutText, xdx
  ACall xcx.Init, pOwner, hParent, offset DIALOGABOUTINDIRECT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogAboutIndirect.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = 0.

Method DialogAboutIndirect.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
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
    m2m [xax].$Obj(Hyperlink).dColor1, dColor1, ecx 
    m2m [xax].$Obj(Hyperlink).dColor2, dColor2, ecx 
  .endif
@@:
  xor eax, eax
MethodEnd

endif
