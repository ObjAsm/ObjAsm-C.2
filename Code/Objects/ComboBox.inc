; ==================================================================================================
; Title:      ComboBox.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support for ComboBox objects based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_COMBOBOX struc
  xCtlID        XWORD     ?         ;Contol ID
  dStyle        DWORD     ?         ;Style
  dExStyle      DWORD     ?         ;Extended style
  pTitle        PSTRING   ?         ;-> Window title
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?         ;X position
      sdPosY    SDWORD    ?         ;Y position
      dWidth    DWORD     ?         ;Width
      dHeight   DWORD     ?         ;Height
    ends
  ends
DEF_COMBOBOX ends
PDEF_COMBOBOX typedef ptr DEF_COMBOBOX


; --------------------------------------------------------------------------------------------------
; Object:     ComboBox
; Purpose:    Implement a thin wrapper around the ComboBox GDI object.

Object ComboBox, ComboBoxID, WinControl                 ;Class "ComboBox"
  RedefineMethod    Done
  RedefineMethod    Init,         POINTER, HWND, PDEF_COMBOBOX
  RedefineMethod    WndProc,      DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     ComboBox.Done
; Purpose:    Finalize the ComboBox object.
; Arguments:  None.
; Return:     Nothing.

Method ComboBox.Done, uses xsi
  SetObject xsi
  Unsubclass ComboBox                                   ;Uses xsi
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ComboBox.Init
; Purpose:    Initialize the ComboBox object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_COMBOBOX initialization structure.
; Return:     Nothing.

Method ComboBox.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_COMBOBOX
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_COMBOBOX
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("ComboBox"), [xbx].pTitle, eax, \
                         [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  Subclass ComboBox                             ;Uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ComboBox.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window HANDLE is passed in pSelf (hidden argument).

Method ComboBox.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  GetSubclassingInst ComboBox, pSelf
  OCall xax::ComboBox.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
