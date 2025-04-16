; ==================================================================================================
; Title:      SkinnedDialogAbout.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of about dialog objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef szAboutText:CHR

; --------------------------------------------------------------------------------------------------
; Object:     SkinnedDialogAbout
; Purpose:    Implement a skinned about dialog using the ElasticSkin engine.

Object SkinnedDialogAbout, SkinnedDialogAboutID, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  VirtualMethod     DrawCaptionText
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM

  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnNcActivate,     WM_NCACTIVATE
  VirtualEvent      OnNcPaint,        WM_NCPAINT

  DefineVariable    dActiveCaption,   DWORD,      FALSE
  DefineVariable    hBkgndBrush,      HBRUSH,     0

  Embed    Skin,    ElasticSkin
ObjectEnd

IDC_DAB_ICON    equ     100
IDC_DAB_TEXT    equ     101
IDC_DAB_MAIL    equ     102
IDC_DAB_LINK    equ     103

; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.CtlsSet
; Purpose:    Set the controls of the About dialog.
; Arguments:  None.
; Return:     Nothing.

Method SkinnedDialogAbout.CtlsSet, uses xsi
  SetObject xsi
  invoke SetDlgItemText, [xsi].hWnd, IDC_DAB_TEXT, addr szAboutText    ;Set about text

  ;Set Hyperlink background color
;  invoke GetDlgItem, [xsi].hWnd, IDC_DAB_LINK
;  invoke SendMessage, xax, BM_SETCOLOR, HYPERLINK_BKGNDCOLOR, [xsi].Skin.SkinData.dClientBkgndColor

;  invoke GetDlgItem, [xsi].hWnd, IDC_DAB_MAIL
;  invoke SendMessage, xax, BM_SETCOLOR, HYPERLINK_BKGNDCOLOR, [xsi].Skin.SkinData.dClientBkgndColor
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.Done
; Purpose:    Finalize the SkinnedDialogAbout object
; Arguments:  None.
; Return:     Nothing.

Method SkinnedDialogAbout.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBkgndBrush
  OCall [xsi].Skin::ElasticSkin.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.DrawCaptionText
; Purpose:    Draw the application caption.
; Arguments:  None.
; Return:     Nothing.

Method SkinnedDialogAbout.DrawCaptionText, uses xsi
  local hDC:HDC, dPrvColor:DWORD, dPrvBkMode:DWORD
  local pCaptionText:POINTER, dTextLen:DWORD

  SetObject xsi
  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)

  mov dTextLen, $32($invoke(GetWindowTextLength, [xsi].hWnd))
  mov pCaptionText, $invoke(StrAlloc, eax)
  inc dTextLen                                          ;Include zero terminator
  invoke GetWindowText, [xsi].hWnd, xax, dTextLen
  mov dPrvBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  .if [xsi].dActiveCaption == 0
    mov ecx, COLOR_3DFACE
  .else
    mov ecx, COLOR_3DHILIGHT
  .endif
  invoke GetSysColor, ecx
  mov dPrvColor, $32($invoke(SetTextColor, hDC, eax))
  invoke DrawTextEx, hDC, pCaptionText, -1, addr [xsi].Skin.TitleRect, \
                     DT_CENTER or DT_VCENTER or DT_SINGLELINE or DT_END_ELLIPSIS, NULL
  invoke SetTextColor, hDC, dPrvColor
  invoke SetBkMode, hDC, dPrvBkMode
  invoke StrDispose, pCaptionText

  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Background brush handle.

Method SkinnedDialogAbout.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetBkMode, wParam, TRANSPARENT                 ;Set DC background to TRANSPARENT
  invoke CreateSolidBrush, [xsi].Skin.SkinData.dClientBkgndColor  ;Return background brush handle
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SkinnedDialogAbout.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  OCall [xsi].Skin::ElasticSkin.Init, xsi, [xsi].hWnd, $OfsCStr("DLGSKIN"), FALSE

  invoke CreateSolidBrush, [xsi].Skin.SkinData.dClientBkgndColor
  mov [xsi].hBkgndBrush, xax

  invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
  BitClr eax, (WS_BORDER or WS_DLGFRAME)                    ;Reset these bits
  invoke SetWindowLongPtr, [xsi].hWnd, GWL_STYLE, eax
  invoke SetWindowLongPtr, [xsi].hWnd, GWL_EXSTYLE, 0       ;Set GWL_EXSTYLE to zero

  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDCLOSE)
  OCall xsi.CtlsSet

;  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
;;   Check if the dialog will be fully visible
;    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
;  .endif
  invoke SetForegroundWindow, [xsi].hWnd
  xor eax, eax                                              ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.OnNcActivate
; Purpose:    Event procedure for WM_NCACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE => Windows will proceed with default processing.

Method SkinnedDialogAbout.OnNcActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  m2m [xsi].dActiveCaption, DWORD ptr wParam, xax
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_NCACTIVATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedDialogAbout.OnNcPaint
; Purpose:    Event procedure for WM_NCPAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SkinnedDialogAbout.OnNcPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_NCPAINT, wParam, lParam
MethodEnd

endif
