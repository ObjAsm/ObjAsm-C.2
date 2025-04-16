; ==================================================================================================
; Title:      Dialog.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Dialog objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Set the focus on a Dialog (Don't use SetFocus => WM_NEXTDLGCTL):
;                 https://devblogs.microsoft.com/oldnewthing/20040802-00/?p=38283
; ==================================================================================================


LMA_COLORKEY    equ   1
LMA_ALPHA       equ   2

; --------------------------------------------------------------------------------------------------
; Object:     Dialog
; Purpose:    This object provides all the functionality needed to create, show and destroy a
;             windows dialog. This class is the base for derived classes like DialogModal and
;             DialogModeless.

Object Dialog, DialogID, Window                              ;Class name "#32770"
  VirtualMethod     CtlsGet
  VirtualMethod     CtlsInvalidate,     DWORD, DWORD
  VirtualMethod     CtlsLock,           DWORD, DWORD, DWORD
  VirtualMethod     CtlsSet
  VirtualMethod     DestroyDialog,      XWORD
  VirtualMethod     DlgProc,            DWORD, WPARAM, LPARAM
  RedefineMethod    Init,               POINTER, HWND, POINTER
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualAbstract   Show
  VirtualMethod     ShowAt,             SDWORD, SDWORD

  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnInitDialog,       WM_INITDIALOG

  DefineVariable    hParent,            HWND,       0
  DefineVariable    pTemplate,          POINTER,    NULL
  DefineVariable    StartPos,           POINT,      {-1, -1}    ;Use Windows defaults
ObjectEnd


; ==================================================================================================

if IMPLEMENT

LIMIT_DATA struct
  dLowerLimit   DWORD   ?
  dUpperLimit   DWORD   ?
  dData         DWORD   ?
LIMIT_DATA ends

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

DlgChildInvalidate proc hWnd:HWND, pData:POINTER
  ?mov xcx, hWnd
  invoke GetDlgCtrlID, xcx                              ;hWnd
  mov xcx, pData
  .if $IsInRange?(eax, [xcx].LIMIT_DATA.dLowerLimit, [xcx].LIMIT_DATA.dUpperLimit, edx)
    invoke InvalidateRect, hWnd, NULL, FALSE
  .endif
  mov eax, TRUE                                         ;Continue enumerating
  ret
DlgChildInvalidate endp

DlgChildLock proc hWnd:HWND, pData:POINTER
  ?mov xcx, hWnd
  invoke GetDlgCtrlID, xcx                              ;hWnd
  mov xcx, pData
  .if $IsInRange?(eax, [xcx].LIMIT_DATA.dLowerLimit, [xcx].LIMIT_DATA.dUpperLimit, edx)
    mov eax, [xcx].LIMIT_DATA.dData
    invoke SendMessage, hWnd, WM_SETREDRAW, eax, 0
  .endif
  mov eax, TRUE                                         ;Continue enumerating
  ret
DlgChildLock endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.CtlsGet
; Purpose:    Do nothing at this stage. It has to be redefined to provide proper functionality.
; Arguments:  None.
; Return:     Nothing.

Method Dialog.CtlsGet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.CtlsInvalidate
; Purpose:    Invalidate a range of controls.
; Arguments:  Arg1: Low control ID limit.
;             Arg2: High control ID limit.
; Return:     Nothing.

Method Dialog.CtlsInvalidate,, dLowID:DWORD, dHighID:DWORD
  local Limits:LIMIT_DATA

  SetObject xcx
  m2m Limits.dLowerLimit, dLowID, eax
  m2m Limits.dUpperLimit, dHighID, edx
  invoke EnumChildWindows, [xcx].hWnd, offset(DlgChildInvalidate), addr Limits
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.CtlsLock
; Purpose:    Lock or unlock the redrawing of a range of controls.
; Arguments:  Arg1: TRUE = controls locked => no redrawing, FALSE = unlocked => redrawing enabled.
;             Arg2: Low control ID limit.
;             Arg3: High control ID limit.
; Return:     Nothing.

Method Dialog.CtlsLock,, dLock:DWORD, dLowID:DWORD, dHighID:DWORD
  local Limits:LIMIT_DATA

  SetObject xcx
  xor dLock, TRUE                                     ;dLock ;Swap TRUE and FALSE
  m2m Limits.dLowerLimit, dLowID, eax
  m2m Limits.dUpperLimit, dHighID, edx
  m2m Limits.dData, dLock, eax
  invoke EnumChildWindows, [xcx].hWnd, offset(DlgChildLock), addr Limits
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.CtlsSet
; Purpose:    Do nothing at this stage. It has to be redefined to provide proper functionality.
; Arguments:  None.
; Return:     Nothing.

Method Dialog.CtlsSet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.DestroyDialog
; Purpose:    Destroy a dialog.
; Arguments:  Arg1: Windows return value.
; Return:     Nothing.

Method Dialog.DestroyDialog,, xArg:XWORD
  SetObject xcx
  invoke WndFadeOut, [xcx].hWnd, 255, 0, 15, 20         ;FadeOut only if WS_EX_LAYERED was set
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.DlgProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = is the result of the message processing and depends on the message.
; Note:       Window HANDLE passed in pSelf (hidden parameter).

Method Dialog.DlgProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "Dialog.DlgProc"
  .if uMsg == WM_INITDIALOG
    mov xsi, lParam                                     ;lParam -> object instance
    test xsi, xsi
    jz @@EOM
    mrm [xsi].$Obj(Dialog).hWnd, pSelf, xcx             ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, DWLP_USER, xsi
  .else
    invoke GetWindowLongPtr, pSelf, DWLP_USER           ;If DWLP_USER wasn't set, it returns NULL
    test xax, xax
    jz @@EOM                                            ;NULL => not handled!
    mov xsi, xax                                        ;xsi -> object instance
  .endif
  DispatchEvent                                         ;xsi -> object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.Init
; Purpose:    Initialize the Dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Template name or Resource ID.
; Return:     Nothing.

Method Dialog.Init,, pOwner:POINTER, hParent:HWND, pTemplate:POINTER
  SetObject xcx
  m2m [xcx].hParent, hParent, xax
  m2m [xcx].pTemplate, pTemplate, xdx
  ACall xcx.Init, pOwner, 0                             ;hWnd is not known at this moment
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If an application processes this message, it should return zero.

Method Dialog.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                        ;Return zero
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                        ;Return zero
  .else
    xor eax, eax
    inc eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Dialog.OnDestroy,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SetWindowLongPtr, [xcx].hWnd, DWLP_USER, NULL
  xor eax, eax                                          ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

Method Dialog.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "Dialog.OnInitDialog"
  SetObject xsi
  OCall xsi.InitWindow

  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
    ;Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDOK
  .if xax != 0
    invoke SendMessage, [xsi].hWnd, WM_NEXTDLGCTL, xax, TRUE
  .endif

  OCall xsi.CtlsSet

  invoke SetForegroundWindow, [xsi].hWnd

  invoke WndFadeIn, [xsi].hWnd, 0, 255, 15, 20          ;FadeIn only works if WS_EX_LAYERED is set

  xor eax, eax                                          ;Return FALSE to prevent Windows from
MethodEnd                                               ;  setting the default keyboard focus.

; --------------------------------------------------------------------------------------------------
; Method:     Dialog.ShowAt
; Purpose:    Show a dialog at a specified position.
; Arguments:  Arg1: X position from screen top border.
;             Arg2: Y position from screen left border.
; Return:     Nothing.

Method Dialog.ShowAt,, sdXPos:SDWORD, sdYPos:SDWORD
  SetObject xcx
  m2m [xcx].StartPos.x, sdXPos, eax
  m2m [xcx].StartPos.y, sdYPos, edx
  .if [xcx].hWnd
    invoke SetWindowPos, [xcx].hWnd, HWND_TOP, sdXPos, sdYPos, 0, 0, SWP_NOSIZE
  .else
    OCall xcx.Show
  .endif
MethodEnd

endif
