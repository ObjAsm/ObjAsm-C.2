; ==================================================================================================
; Title:      SendChildrenMessage_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, January 2020.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


CHILD_MSG struc
  dMsgID  DWORD   ?
  wParam  WPARAM  ?
  lParam  LPARAM  ?
CHILD_MSG ends
PCHILD_MSG typedef ptr CHILD_MSG

; --------------------------------------------------------------------------------------------------
; Procedure:  SendChildMessage
; Purpose:    Callback procedure for EnumChildWindows that sends a message to a child window.
; Arguments:  Arg1: Child window HANDLE.
;             Arg2: -> CHILD_MSG structure.
; Return:     eax = always TRUE (continue the enumeration).

.code
align ALIGN_CODE
SendChildMessage proc hWnd:HWND, lParam:PCHILD_MSG
  mov xax, lParam
  invoke SendMessage, hWnd, [xax].CHILD_MSG.dMsgID, \
                      [xax].CHILD_MSG.wParam, [xax].CHILD_MSG.lParam
  mov eax, TRUE
  ret
SendChildMessage endp

; --------------------------------------------------------------------------------------------------
; Procedure:  SendChildrenMessage
; Purpose:    Send a message to all children of a parent window.
; Arguments:  Arg1: Parent window HANDLE. 
;             Arg2: Message ID
;             Arg3: wParam
;             Arg4: lParam.
; Return:     Nothing.

.code
align ALIGN_CODE
SendChildrenMessage proc hWnd:HWND, dMsgID:DWORD, wParam:WPARAM, lParam:LPARAM
  local ChildMsg:CHILD_MSG

  m2m ChildMsg.dMsgID, dMsgID, eax
  m2m ChildMsg.wParam, wParam, xcx
  m2m ChildMsg.lParam, lParam, xdx
  invoke EnumChildWindows, hWnd, offset(SendChildMessage), addr ChildMsg
  ret
SendChildrenMessage endp
