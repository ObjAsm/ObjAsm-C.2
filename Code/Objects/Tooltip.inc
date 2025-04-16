; ==================================================================================================
; Title:      Tooltip.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support Tooltip GDI control.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Make sure you always add the correct manifest in the resource section.
; ==================================================================================================


TTF_TRACK        equ    0020h
TTF_ABSOLUTE     equ    0080h
TTF_TRANSPARENT  equ    0100h

; --------------------------------------------------------------------------------------------------
; Object:     Tooltip
; Purpose:    Implement a thin wrapper around the Tooltips_class32 GDI control.
; Notes:      Due to some undocumented issues, the tooltip class (Tooltips_Class32) does not always
;             call WM_DESTROY since it doesn't register itself as a child window to its parent.
;             To avoid memory leakages, call "DestroyWindow" when you are done with this control.

Object Tooltip, TooltipID, WinControl                           ;Class "Tooltips_class32"
  VirtualMethod     AddRectTip,         PRECT, DWORD, PSTRING   ;-> RECT, ID, -> Text
  VirtualMethod     AddWndTip,          HWND, PSTRING           ;hWnd, -> Text
  VirtualMethod     DelRectTip,         DWORD                   ;ID
  VirtualMethod     DelWndTip,          HWND
  RedefineMethod    Done
  VirtualMethod     Enable,             DWORD                   ;TRUE / FALSE
  RedefineMethod    Init,               POINTER, HWND           ;-> Owner, hParent
  VirtualMethod     SetDelayTime,       DWORD, DWORD            ;Type, Time
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

.code
; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.AddRectTip
; Purpose:    Register a RECT structure with a Tooltip control.
; Arguments:  Arg1: -> RECT structure to be added.
;             Arg2: ID to identify the registerd tip.
;             Arg3: -> Tooltip text.
; Return:     eax = TRUE if successfully added or FALSE otherwise.

Method Tooltip.AddRectTip, uses xsi, pRect:PRECT, dID:DWORD, pText:PSTRING
  local TInfo:TOOLINFO

  SetObject xsi
  mov TInfo.cbSize, sizeof(TOOLINFO)
  mov TInfo.uFlags, TTF_SUBCLASS
  mov TInfo.hwnd, $invoke(GetParent, [xsi].hWnd)
  mov eax, dID
  mov TInfo.uId, xax
  invoke MemClone, addr TInfo.rect, pRect, sizeof(RECT)
  m2m TInfo.lpszText, pText, xax
  invoke SendMessage, [xsi].hWnd, TTM_ADDTOOL, 0, addr TInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.AddWndTip
; Purpose:    Register a window with a Tooltip control.
; Arguments:  Arg1: Handle of the window to be added.
;             Arg2: -> Tooltip text.
; Return:     eax = TRUE if successfully added or FALSE otherwise.

Method Tooltip.AddWndTip, uses xsi, hWnd:HWND, pText:PSTRING
  local TInfo:TOOLINFO

  SetObject xsi
  mov TInfo.cbSize, sizeof(TOOLINFO)
  mov TInfo.uFlags, TTF_SUBCLASS or TTF_IDISHWND
  mov TInfo.hwnd, $invoke(GetParent, [xsi].hWnd)        ;Window that will recieve TTN_GETDISPINFO
  m2m TInfo.uId, hWnd, xax
  m2m TInfo.lpszText, pText, xax
  invoke SendMessage, [xsi].hWnd, TTM_ADDTOOL, 0, addr TInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.DelRectTip
; Purpose:    Unregister a RECT structure from a Tooltip control.
; Arguments:  Arg1: ID to identify the registerd tip.
; Return:     Nothing.

Method Tooltip.DelRectTip, uses xsi, dID:DWORD
  local TInfo:TOOLINFO

  SetObject xsi
  mov TInfo.cbSize, sizeof(TOOLINFO)
  m2z TInfo.uFlags
  mov TInfo.hwnd, $invoke(GetParent, [xsi].hWnd)
  mov eax, dID
  mov TInfo.uId, xax
  invoke SendMessage, [xsi].hWnd, TTM_DELTOOL, 0, addr TInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.DelWndTip
; Purpose:    Unregister a window from a Tooltip control.
; Arguments:  Arg1: HANDLE of the window to be unregistered.
; Return:     Nothing.

Method Tooltip.DelWndTip, uses xsi, hWnd:HWND
  local TInfo:TOOLINFO

  SetObject xsi
  mov TInfo.cbSize, sizeof(TOOLINFO)
  mov TInfo.uFlags, TTF_IDISHWND
  mov TInfo.hwnd, $invoke(GetParent, [xsi].hWnd)
  m2m TInfo.uId, hWnd, xax
  invoke SendMessage, [xsi].hWnd, TTM_DELTOOL, 0, addr TInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.Done
; Purpose:    Finalize the Tooltip object.
; Arguments:  None.
; Return:     Nothing.

Method Tooltip.Done, uses xsi
  SetObject xsi
  Unsubclass Tooltip                                    ;Uses xsi
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.Enable
; Purpose:    Enable or disable the Tooltip control.
; Arguments:  Arg1: TRUE = Enable / FALSE = Disable.
; Return:     Nothing.

Method Tooltip.Enable,, dAction:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, TTM_ACTIVATE, dAction, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.Init
; Purpose:    Initialize the Tooltip object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method Tooltip.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  invoke CreateWindowEx, WS_EX_TOPMOST or WS_EX_TOOLWINDOW, $OfsCStr("tooltips_class32"), \
                         NULL, WS_POPUP or TTS_NOPREFIX or TTS_ALWAYSTIP, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, NULL, hInstance, NULL
  ACall xsi.Init, pOwner, xax
  invoke SetWindowPos, [xsi].hWnd, HWND_TOPMOST, 0, 0, 0, 0, \        ;Must be defined as Topmost
                       SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE     ;  See the API reference
  Subclass Tooltip                                      ;Uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.SetDelayTime
; Purpose:    Set the delay times of a Tooltip control.
; Arguments:  Arg1: Flag indicating the type of delay time:
;                   TTDT_AUTOMATIC, TTDT_AUTOPOP, TTDT_INITIAL, TTDT_RESHOW.
;             Arg2: Duration in miliseconds.
; Return:     Nothing.

Method Tooltip.SetDelayTime,, dType:DWORD, dTime:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, TTM_SETDELAYTIME, dType, dTime
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tooltip.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = Result of the message processing and depends on the message.
; Note:       Window handle is passed in pSelf.

Method Tooltip.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg, , "Tooltip Messages"
  GetSubclassingInst Tooltip, pSelf
  OCall xax::Tooltip.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
