; ==================================================================================================
; Title:      SkinnedMsgBox.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of about dialog objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


IDC_SMB_TEXT    equ     100

; --------------------------------------------------------------------------------------------------
; Object:  SkinnedMsgBox
; Purpose: Implement a skinned MessageBox dialog using the ElasticSkin engine.

Object SkinnedMsgBox, SkinnedMsgBoxID, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  VirtualMethod     DrawCaptionText
  RedefineMethod    Init,             POINTER, HWND, DWORD, DWORD, POINTER, \
                                      POINTER, XWORD, POINTER, XWORD
  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM

  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnNcActivate,     WM_NCACTIVATE
  VirtualEvent      OnNcPaint,        WM_NCPAINT

  DefineVariable    pCaptionText,     POINTER,    NULL
  DefineVariable    pMessageText,     POINTER,    NULL
  DefineVariable    dActiveCaption,   DWORD,      FALSE
  DefineVariable    hBkgndBrush,      HBRUSH,     0
  DefineVariable    pBtn1ResName,     POINTER,    NULL
  DefineVariable    xBtn1ID,          XWORD,      0
  DefineVariable    pBtn2ResName,     POINTER,    NULL
  DefineVariable    xBtn2ID,          XWORD,      0
  DefineVariable    pGifResName,      POINTER,    NULL

  Embed     Skin,         ElasticSkin
  Embed     RgnBtn1,      RgnButton
  Embed     RgnBtn2,      RgnButton
  Embed     Player,       GifPlayer
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.CtlsSet
; Purpose:    Set the controls of the SkinnedMsgBox dialog.
; Arguments:  None.
; Return:     Nothing.

Method SkinnedMsgBox.CtlsSet, uses xsi
  SetObject xsi
  invoke SetDlgItemText, [xsi].hWnd, IDC_SMB_TEXT, [xsi].pMessageText
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.Done
; Purpose:    Finalize the SkinnedMsgBox object
; Arguments:  None.
; Return:     Nothing.

Method SkinnedMsgBox.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBkgndBrush
  invoke StrDispose, [xsi].pCaptionText
  invoke StrDispose, [xsi].pMessageText

  OCall [xsi].Player::GifPlayer.Done
  OCall [xsi].RgnBtn1::RgnButton.Done
  OCall [xsi].RgnBtn2::RgnButton.Done
  OCall [xsi].Skin::ElasticSkin.Done

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.DrawCaptionText
; Purpose:    Draw the caption.
; Arguments:  None.
; Return:     Nothing.

Method SkinnedMsgBox.DrawCaptionText, uses xsi
  local hDC:HDC, dPrvColor:DWORD, dPrvBkMode:DWORD

  SetObject xsi
  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)

  mov dPrvBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  .if [xsi].dActiveCaption == 0
    mov ecx, COLOR_3DFACE
  .else
    mov ecx, COLOR_3DHILIGHT
  .endif
  invoke GetSysColor, ecx
  mov dPrvColor, $32($invoke(SetTextColor, hDC, eax))
  invoke DrawTextEx, hDC, [xsi].pCaptionText, -1, addr [xsi].Skin.TitleRect, \
                     DT_CENTER or DT_VCENTER or DT_SINGLELINE or DT_END_ELLIPSIS, NULL
  invoke SetTextColor, hDC, dPrvColor
  invoke SetBkMode, hDC, dPrvBkMode

  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.Init
; Purpose:    Initialize the SkinnedMsgBox dialog.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: Caption resource ID.
;             Arg4: Message resource ID.
;             Arg5: -> GIF resource name.
;             Arg6: -> Button 1 resource name.
;             Arg7: Button 1 ID.
;             Arg8: -> Button 2 resource name.
;             Arg9: Button 2 ID.
; Return:     Nothing.

Method SkinnedMsgBox.Init, uses xsi, pOwner:POINTER, hParent:HWND, \
                                     dTtlID:DWORD, dMsgID:DWORD, pGifName:POINTER, \
                                     pBtn1Name:POINTER, xBtn1ID:XWORD, \
                                     pBtn2Name:POINTER, xBtn2ID:XWORD
  local cBuffer[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner, hParent, $OfsCStr("SkinnedMsgBox")
  invoke LoadString, hInstance, dTtlID, addr cBuffer, lengthof cBuffer
  mov [xsi].pCaptionText, $invoke(StrNew, addr cBuffer)
  invoke LoadString, hInstance, dMsgID, addr cBuffer, lengthof cBuffer
  mov [xsi].pMessageText, $invoke(StrNew, addr cBuffer)

  m2m [xsi].pBtn1ResName, pBtn1Name, xax
  m2m [xsi].xBtn1ID, xBtn1ID, xcx
  m2m [xsi].pBtn2ResName, pBtn2Name, xax
  m2m [xsi].xBtn2ID, xBtn2ID, xcx

  m2m [xsi].pGifResName, pGifName, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method SkinnedMsgBox.OnCommand,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  OCall xcx.DestroyDialog, wParam                       ;wParam = ID of the control that
  xor eax, eax                                          ;  fired the command
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Background brush handle.

Method SkinnedMsgBox.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetBkMode, wParam, TRANSPARENT                 ;Set DC background to TRANSPARENT
  mov xax, [xsi].hBkgndBrush                            ;Return background brush HANDLE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SkinnedMsgBox.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local RgnButtonDef:DEF_REGIONBUTTON
  local BaseUnitX:DWORD, BaseUnitY:DWORD

  SetObject xsi
  OCall [xsi].Skin::ElasticSkin.Init, xsi, [xsi].hWnd, $OfsCStr("DLGSKIN"), FALSE
  invoke GetDialogBaseUnits
  mov ebx, eax
  and eax, 0FFFFh
  mov BaseUnitX, eax
  shr ebx, 16
  mov BaseUnitY, ebx

  invoke CreateSolidBrush, [xsi].Skin.SkinData.dClientBkgndColor
  mov [xsi].hBkgndBrush, xax

  invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
  BitClr eax, (WS_BORDER or WS_DLGFRAME)                ;Reset these bits
  invoke SetWindowLongPtr, [xsi].hWnd, GWL_STYLE, eax
  invoke SetWindowLongPtr, [xsi].hWnd, GWL_EXSTYLE, 0   ;Set GWL_EXSTYLE to zero

  m2m RgnButtonDef.xCtlID, [xsi].xBtn1ID, xax
  xor eax, eax
  mov RgnButtonDef.dStyle, eax
  mov RgnButtonDef.dExStyle, eax
  ;100% -> BaseUnitX = 08; BaseUnitY = 16
  ;125% -> BaseUnitX = 10; BaseUnitY = 20
  mov RgnButtonDef.sdPosX, $32($invoke(MulDiv, 40, BaseUnitX, 4))
  mov RgnButtonDef.sdPosY, $32($invoke(MulDiv, 70, BaseUnitY, 8))
  m2m RgnButtonDef.pResName, [xsi].pBtn1ResName, xax
  OCall [xsi].RgnBtn1::RgnButton.Init, xsi, [xsi].hWnd, addr RgnButtonDef

  m2m RgnButtonDef.xCtlID, [xsi].xBtn2ID, xax
;  xor eax, eax
;  mov RgnButtonDef.dStyle, eax
;  mov RgnButtonDef.dExStyle, eax
  mov RgnButtonDef.sdPosX, $32($invoke(MulDiv, 90, BaseUnitX, 4))
;  mov RgnButtonDef.sdPosY, $32($invoke(MulDiv, 64, BaseUnitY, 8))
  m2m RgnButtonDef.pResName, [xsi].pBtn2ResName, xax
  OCall [xsi].RgnBtn2::RgnButton.Init, xsi, [xsi].hWnd, addr RgnButtonDef

  OCall [xsi].Player::GifPlayer.Init, xsi, [xsi].hWnd, [xsi].pGifResName, 30,45,100,100,1000

  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDNO)        ;Set focus to <NO> button
  OCall xsi.CtlsSet
  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
;    Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif
  invoke SetForegroundWindow, [xsi].hWnd
  xor eax, eax                                          ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.OnNcActivate
; Purpose:    Event procedure for WM_NCACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE => Windows will proceed with default processing.

Method SkinnedMsgBox.OnNcActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  mov [xsi].dActiveCaption, eax
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_NCACTIVATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SkinnedMsgBox.OnNcPaint
; Purpose:    Event procedure for WM_NCPAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SkinnedMsgBox.OnNcPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall xsi.DrawCaptionText
  invoke DefWindowProc, [xsi].hWnd, WM_NCPAINT, wParam, lParam
MethodEnd

endif
