; ==================================================================================================
; Title:      Progressbar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Progressbar objects.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


DEF_PROGRESSBAR struc
  xCtlID        XWORD     ?   ;Control ID
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?   ;X position
      sdPosY    SDWORD    ?   ;Y position
      dWidth    DWORD     ?   ;Width
      dHeight   DWORD     ?   ;Height
    ends
  ends
  dRangeMin     DWORD     ?   ;Min range.
  dRangeMax     DWORD     ?   ;Max range.
  dStepWidth    DWORD     ?   ;Step width.
  dStyle        DWORD     ?   ;Control style.
  pTipText      PSTRING   ?   ;-> Tooltip string.
DEF_PROGRESSBAR ends
PDEF_PROGRESSBAR typedef ptr DEF_PROGRESSBAR

; --------------------------------------------------------------------------------------------------
; Object:     Progressbar
; Purpose:    Implement a thin object wrapper around of the msctls_progress32 GDI control.

Object Progressbar, ProgressbarID, WinControl                   ;Class "msctls_progress32"
  RedefineMethod    Done
  VirtualMethod     Increment,      DWORD
  RedefineMethod    Init,           POINTER, HWND, PDEF_PROGRESSBAR
  VirtualMethod     SetColorBack,   DWORD
  VirtualMethod     SetColorFore,   DWORD
  VirtualMethod     SetPos,         DWORD
  VirtualMethod     SetRange,       DWORD, DWORD
  VirtualMethod     SetStep,        DWORD
  VirtualMethod     Step
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.Done
; Purpose:    Finalize the progressbar object.
; Arguments:  None.
; Return:     Nothing.

Method Progressbar.Done, uses xsi
  SetObject xsi
  Unsubclass Progressbar                                ;Uses xsi
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.Increment
; Purpose:    Add increment to the actual position.
; Arguments:  Arg1: Increment value.
; Return:     Nothing.

Method Progressbar.Increment,, dIncrement:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_DELTAPOS, dIncrement, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.Init
; Purpose:    Initialize the Progressbar object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_PROGRESSBAR structure.
; Return:     Nothing.

Method Progressbar.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_PROGRESSBAR
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_PROGRESSBAR
  invoke CreateWindowEx, 0, $OfsCStr("msctls_progress32"), NULL, [xbx].dStyle, \
                         [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, NULL
  ACall xsi.Init, pOwner, xax
  Subclass Progressbar                      ;Uses esi
  OCall xsi.SetRange, [xbx].dRangeMin, [xbx].dRangeMax
  assume xbx:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.SetColorBack
; Purpose:    Set the background color.
; Arguments:  Arg1: RGB color value.
; Return:     Nothing.

Method Progressbar.SetColorBack,, dColor:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_SETBKCOLOR, 0, dColor
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.SetColorFore
; Purpose:    Set the foreground color.
; Arguments:  Arg1: RGB color value.
; Return:     Nothing.

Method Progressbar.SetColorFore,, dColor:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_SETBARCOLOR, 0, dColor
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.SetPos
; Purpose:    Set the current position of the progress bar.
; Arguments:  Arg1: Position within the imposted range.
; Return:     Nothing.

Method Progressbar.SetPos,, dPos:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_SETPOS, dPos, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.SetRange
; Purpose:    Set the minimum and maximum range values.
; Arguments:  Arg1: Minumum.
;             Arg2: Maximum.
; Return:     Nothing.

Method Progressbar.SetRange,, dMin:DWORD, dMax:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_SETRANGE32, dMin, dMax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.SetStep
; Purpose:    Set the increment value.
; Arguments:  Arg1: Step value.
; Return:     Nothing.

Method Progressbar.SetStep,, dStepWidth:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_SETSTEP, dStepWidth, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.Step
; Purpose:    Increment the progressbar a step width.
; Arguments:  None.
; Return:     Nothing.

Method Progressbar.Step
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, PBM_STEPIT, 0, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Progressbar.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     xax = This value is the result of the message processing and depends on the message ID.
; Notes:      Window handle passed in pSelf (hidden argument).

Method Progressbar.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  GetSubclassingInst Progressbar, pSelf
  OCall xax::Progressbar.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif