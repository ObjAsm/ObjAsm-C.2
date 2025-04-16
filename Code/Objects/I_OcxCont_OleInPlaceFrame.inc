; ==================================================================================================
; Title:      I_OcxCont_OleInPlaceFrame.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleInPlaceFrame Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IOleInPlaceFrame:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_OleInPlaceFrame
; Purpose:    Control the container's top-level frame window. This control involves allowing the
;             container to insert its menu group into the composite menu, install the composite menu
;             into the appropriate window frame, and remove the container's menu elements from the
;             composite menu. It sets and displays status text relevant to the in-place object. It
;             also enables or disables the frame's modeless dialog boxes, and translates accelerator
;             keystrokes intended for the container's frame.

Object I_OcxCont_OleInPlaceFrame,, I_OcxCont_OleWindow
  InterfaceMethod   GetBorder,                  POINTER
  InterfaceMethod   RequestBorderSpace,         LPBORDERWIDTHS
  InterfaceMethod   SetBorderSpace,             LPBORDERWIDTHS
  InterfaceMethod   SetActiveObject,            POINTER, POINTER
  InterfaceMethod   InsertMenus,                HANDLE, POINTER
  InterfaceMethod   SetMenu,                    HANDLE, HANDLE, HANDLE
  InterfaceMethod   RemoveMenus,                HANDLE
  InterfaceMethod   SetStatusText,              POINTER
  InterfaceMethod   EnableModeless,             BOOL
  InterfaceMethod   TranslateAccel,             POINTER, WORD

  RedefineVariable  pIID,   offset IID_IOleInPlaceFrame
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleInPlaceFrame implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.GetBorder
; Purpose:    Retrieve the outer rectange for toolbars and controls while the object is active in
;             place.
; Arguments:  Arg1: -> RECT structure where the outer rectangle is to be returned. The structure's
;                   coordinates are relative to the window being represented by the interface.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.GetBorder,, pBorderRect:POINTER
  DbgText "I_OcxCont_OleInPlaceFrame.GetBorder", "I_OcxCont_OleInPlaceFrame"

  .if pBorderRect != NULL
    SetOwner xcx, OcxClientSite
    mov xdx, pBorderRect
    CloneRect RECT ptr [xdx], [xcx].CtrlRect, xax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.RequestBorderSpace
; Purpose:    Determine whether there is space available for tools to be installed around the
;             object's window frame while the object is active in place.
; Arguments:  Arg1: -> BORDERWIDTHS structure containing the requested widths (in pixels) needed on
;             each side of the window for the tools.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.RequestBorderSpace,, pBorderWidths:LPBORDERWIDTHS
  DbgText "I_OcxCont_OleInPlaceFrame.RequestBorderSpace", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.SetBorderSpace
; Purpose:    Allocate space for the border requested in the call to
;             IOleInPlaceUIWindow::RequestBorderSpace.
; Arguments:  Arg1: -> BORDERWIDTHS structure containing the requested width of the tools, in pixels.
;                   It can be NULL, indicating the object does not need any space.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.SetBorderSpace,, pBorderWidths:LPBORDERWIDTHS
  DbgText "I_OcxCont_OleInPlaceFrame.SetBorderSpace", "I_OcxCont_OleInPlaceFrame"

  .if pBorderWidths != NULL
    SetOwner xcx, OcxClientSite
    mov xdx, pBorderWidths
    DbgDec [xdx].BORDERWIDTHS.left,, "I_OcxCont_OleInPlaceFrame"
    DbgDec [xdx].BORDERWIDTHS.top,, "I_OcxCont_OleInPlaceFrame"
    DbgDec [xdx].BORDERWIDTHS.right,, "I_OcxCont_OleInPlaceFrame"
    DbgDec [xdx].BORDERWIDTHS.bottom,, "I_OcxCont_OleInPlaceFrame"

    CloneRect [xcx].BorderSpace, RECT ptr [xdx], xax

    .if [xcx].pIOleInPlaceSite != NULL
      lea xdx, [xcx].CtrlRect
      ICall [xcx].pIOleInPlaceSite::IOleInPlaceSite.OnPosRectChange, xdx
    .endif
  .else
    DbgHex pBorderWidths,, "I_OcxCont_OleInPlaceFrame"
  .endif

  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.SetActiveObject
; Purpose:    Provide a direct channel of communication between the object and each of the frame and
;             document windows.
; Arguments:  Arg1: -> IOleInPlaceActiveObject interface on the active in-place object.
;             Arg2: -> String containing a name that describes the object an embedding container can
;                   use in composing its window title. It can be NULL if the object does not require
;                   the container to change its window titles. Containers should ignore this
;                   parameter and always use their own name in the title bar.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.SetActiveObject,, pActiveObject:POINTER, pObjectName:POINTER
  DbgText "I_OcxCont_OleInPlaceFrame.SetActiveObject", "I_OcxCont_OleInPlaceFrame"
  DbgHex pActiveObject,, "I_OcxCont_OleInPlaceFrame"
  DbgStrW pObjectName,, "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.InsertMenus
; Purpose:    Enable the container to insert menu groups into the composite menu to be used during
;             the in-place session.
; Arguments:  Arg1: Empty menu HANDLE.
;             Arg2: -> OLEMENUGROUPWIDTHS array with six elements. The container fills in elements
;                   0, 2, and 4 to reflect the number of menu elements it provided in the File,
;                   View, and Window menu groups.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.InsertMenus,, hMenuShared:HANDLE, pMenuWidths:POINTER
  DbgText "I_OcxCont_OleInPlaceFrame.InsertMenus", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.SetMenu
; Purpose:    Add a composite menu to the window frame containing the object being activated
;             in place.
; Arguments:  Arg1: handle to the composite menu constructed by calls to
;                   IOleInPlaceFrame::InsertMenus and the InsertMenu function.
;             Arg2: handle to the menu descriptor returned by the OleCreateMenuDescriptor function.
;             Arg3: handle to a window owned by the object and to which menu messages, commands, and
;                   accelerators are to be sent.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.SetMenu,, hMenuShared:HANDLE, hOleMenu:HANDLE, \
                                           hEndActiveObject:HANDLE
  DbgText "I_OcxCont_OleInPlaceFrame.SetMenu", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.RemoveMenus
; Purpose:    Remove a container's menu elements from the composite menu.
; Arguments:  Arg1: handle to the in-place composite menu that was constructed by calls to
;                   IOleInPlaceFrame::InsertMenus and the InsertMenu function.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.RemoveMenus,, hMenuShared:HANDLE
  DbgText "I_OcxCont_OleInPlaceFrame.RemoveMenus", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.SetStatusText
; Purpose:    Set and displays status text about the in-place object in the container's frame
;             window status line.
; Arguments:  Arg1: The message to be displayed.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.SetStatusText,, pStatusText:POINTER
  DbgText "I_OcxCont_OleInPlaceFrame.SetStatusText", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.EnableModeless
; Purpose:    Enable or disable a frame's modeless dialog boxes.
; Arguments:  Arg1: Specifies whether the modeless dialog box windows are to be enabled (TRUE)
;                   or disabled (FALSE).
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.EnableModeless,, bEnable:BOOL
  DbgText "I_OcxCont_OleInPlaceFrame.EnableModeless", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceFrame.TranslateAccel
; Purpose:    Translate accelerator keystrokes intended for the container's frame while an object
;             is active in place.
; Arguments:  Arg1: -> MSG structure that contains the keystroke message.
;             Arg2: The command identifier value corresponding to the keystroke in the container-
;                   provided accelerator table. Containers should use this value instead of
;                   translating again.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceFrame.TranslateAccel,, pMsg:POINTER, wID:WORD
  DbgText "I_OcxCont_OleInPlaceFrame.TranslateAccel", "I_OcxCont_OleInPlaceFrame"
  xor eax, eax                                          ;S_OK
MethodEnd

endif
