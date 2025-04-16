; ==================================================================================================
; Title:      TrayIcon.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of TrayIcon controls based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


TiDef struc
  xCtlID  XWORD  ?  ;Contol ID
  dMsgID  DWORD  ?  ;CallBack message ID send to the parent window when a mouse event occurs.
TiDef ends

WM_SHELLNOTIFY    equ    WM_USER + 5

; --------------------------------------------------------------------------------------------------
; Object:  TrayIcon
; Purpose: Implement a thin wrapper around the TrayIcon GDI control.

Object TrayIcon, TrayIconID, WinControl
  VirtualMethod     Change,       HICON, PSTRING
  RedefineMethod    Done
  VirtualMethod     Hide
  RedefineMethod    Init,         POINTER, HWND, POINTER
  VirtualMethod     Show,         HICON, PSTRING

  DefineVariable    hParent,      HWND,       0
  DefineVariable    dCtlID,       DWORD,      0
  DefineVariable    dMsgID,       DWORD,      0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     TrayIcon.Change
; Purpose:    Update the TrayIcon with the new icon.
; Arguments:  Arg1: Icon HANDLE.
; Return:     Nothing.

Method TrayIcon.Change,, hIcon:HICON, pTip:PSTRING
  local Note:NOTIFYICONDATA

  SetObject xcx
  mov Note.cbSize, sizeof(NOTIFYICONDATA)
  m2m Note.hWnd, [xcx].hParent, xdx                     ;Notifications are send to this window
  m2m Note.uID, [xcx].dCtlID, eax                       ;ID of the TrayIcon
  m2m Note.uCallbackMessage, [xcx].dMsgID, edx
  m2m Note.hIcon, hIcon, xax
  mov Note.uFlags, NIF_ICON
  test [xcx].dMsgID, -1
  .if !ZERO?
    or Note.uFlags, NIF_MESSAGE
  .endif
  test pTip, -1
  .if !ZERO?
    or Note.uFlags, NIF_TIP
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      invoke StrCCopy, addr Note.szTip, pTip, 128
    else
      invoke StrCCopy, addr Note.szTip, pTip, 64
    endif
  .endif
  invoke Shell_NotifyIcon, NIM_MODIFY, addr Note
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TrayIcon.Done
; Purpose:    Finalize the TrayIcon object.
; Arguments:  None.
; Return:     Nothing.

Method TrayIcon.Done, uses xsi
  SetObject xsi
  OCall xsi.Hide
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TrayIcon.Hide
; Purpose:    Hide the TrayIcon.
; Arguments:  None.
; Return:     Nothing.

Method TrayIcon.Hide
  local Note:NOTIFYICONDATA

  SetObject xcx
  mov Note.cbSize, sizeof(NOTIFYICONDATA)
  m2m Note.hWnd, [xcx].hParent, xdx                     ;Notifications are send to this window
  m2m Note.uID, [xcx].dCtlID, edx
  invoke Shell_NotifyIcon, NIM_DELETE, addr Note
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TrayIcon.Init
; Purpose:    Initialize the TrayIcon object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> TiDef initialization structure.
; Return:     Nothing.

Method TrayIcon.Init,, pOwner:POINTER, hParent:HWND, pDef:POINTER
  SetObject xcx
  m2m [xcx].hParent, hParent, xdx
  mov xax, pDef
  mov xdx, [xax].TiDef.xCtlID
  mov [xcx].dCtlID, edx
  m2m [xcx].dMsgID, [xax].TiDef.dMsgID, edx
  ACall xcx.Init, pOwner, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TrayIcon.Show
; Purpose:    Display the TrayIcon.
; Arguments:  Arg1: Icon HANDLE.
;             Arg2: -> Tooltip text.
; Return:     Nothing.

Method TrayIcon.Show, , hIcon:HICON, pTip:PSTRING
  local Note:NOTIFYICONDATA

  SetObject xcx
  mov Note.cbSize, sizeof(NOTIFYICONDATA)
  m2m Note.hWnd, [xcx].hParent, xdx                     ;Notifications are send to this window
  m2m Note.uID, [xcx].dCtlID, edx                       ;ID of the TrayIcon
  m2m Note.hIcon, hIcon, xdx
  mov Note.uFlags, NIF_ICON
  .if [xcx].dMsgID != -1
    or Note.uFlags, NIF_MESSAGE
    m2m Note.uCallbackMessage, [xcx].dMsgID, edx
  .endif
  .if pTip != NULL
    or Note.uFlags, NIF_TIP
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      invoke StrCCopy, addr Note.szTip, pTip, 128
    else
      invoke StrCCopy, addr Note.szTip, pTip, 64
    endif
  .endif
  invoke Shell_NotifyIcon, NIM_ADD, addr Note
MethodEnd

endif
