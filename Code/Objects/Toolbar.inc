; ==================================================================================================
; Title:      Toolbar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support Toolbar controls based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_TOOLBAR struc
  xCtlID        XWORD     ?   ;Control ID
  dStyle        DWORD     ?   ;Style
  dExStyle      DWORD     ?   ;Extended style
  pTitle        PSTRING   ?   ;-> Window caption
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?   ;X position
      sdPosY    SDWORD    ?   ;Y position
      dWidth    DWORD     ?   ;Width
      dHeight   DWORD     ?   ;Height
    ends
  ends
  dCount        DWORD     ?   ;Button count
DEF_TOOLBAR ends
PDEF_TOOLBAR typedef ptr DEF_TOOLBAR

; --------------------------------------------------------------------------------------------------
; Object:     Toolbar
; Purpose:    Implement a thin wrapper around the ToolbarWindow32 GDI control.

Object Toolbar, ToolbarID, WinControl                             ;Class "ToolbarWindow32"
  RedefineMethod    Done
  VirtualMethod     BtnEnable,          DWORD, DWORD
  VirtualMethod     BtnHide,            DWORD, DWORD
  RedefineMethod    GetHeight
  RedefineMethod    GetWidth
  RedefineMethod    Init,               POINTER, HWND, PDEF_TOOLBAR, \
                                        $ObjPtr(MaskedImageList), \
                                        $ObjPtr(MaskedImageList), \
                                        $ObjPtr(MaskedImageList)
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.Done
; Purpose:    Finalize the Toolbar object.
; Arguments:  None.
; Return:     Nothing.

Method Toolbar.Done, uses xsi
  SetObject xsi
  Unsubclass Toolbar                                    ;Uses xsi
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.BtnEnable
; Purpose:    Set the enable state of a Toolbar button.
; Arguments:  Arg1: Button ID.
;             Arg2: Enable TRUE or FALSE.
; Return:     Nothing.

Method Toolbar.BtnEnable,, dBtnID:DWORD, dAction:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, TB_ENABLEBUTTON, dBtnID, dAction
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.BtnHide
; Purpose:    Set the hide state of a Toolbar button.
; Arguments:  Arg1: Button ID.
;             Arg2: Hide TRUE or FALSE.
; Return:     Nothing.

Method Toolbar.BtnHide,, dBtnID:DWORD, dAction:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, TB_HIDEBUTTON, dBtnID, dAction
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.GetHeight
; Purpose:    Return the height of the Toolbar.
; Arguments:  None.
; Return:     eax = Heigth in pixels.

Method Toolbar.GetHeight
  local TBSize:POINT

  SetObject xcx
  invoke SendMessage, [xcx].hWnd, TB_GETMAXSIZE, 0, addr TBSize
  mov eax, TBSize.y
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.GetWidth
; Purpose:    Return the total width of the Toolbar.
; Arguments:  None.
; Return:     eax = Width in pixels.

Method Toolbar.GetWidth
  local TBSize:POINT

  SetObject xcx
  invoke SendMessage, [xcx].hWnd, TB_GETMAXSIZE, 0, addr TBSize
  mov eax, TBSize.x
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.Init
; Purpose:    Initialize the Toolbar control.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_TOOLBAR structure.
;             Arg4: -> MaskedImageList object for normal icons.
;             Arg5: -> MaskedImageList object for hot icons.
;             Arg6: -> MaskedImageList object for disabled icons.
; Return:     Nothing.

Method Toolbar.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_TOOLBAR, \
                                   pIlNormal:$ObjPtr(MaskedImageList), \
                                   pIlHot:$ObjPtr(MaskedImageList), \
                                   pIlDisabled:$ObjPtr(MaskedImageList)
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_TOOLBAR
  invoke CreateWindowEx, 0, $OfsCStr("ToolbarWindow32"), [xbx].pTitle, [xbx].dStyle, \
                         [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, hParent, \
                         [xbx].xCtlID, hInstance, NULL
  ACall xsi.Init, pOwner, xax
  invoke SendMessage, [xsi].hWnd, TB_SETEXTENDEDSTYLE, 0, \
                      [xbx].dExStyle

  invoke SetWindowText, [xsi].hWnd, [xbx].pTitle
  .if pIlNormal != NULL
    mov xax, pIlNormal
    invoke SendMessage, [xsi].hWnd, TB_SETIMAGELIST, 0, \
                        [xax].$Obj(MaskedImageList).hImageList
  .endif
  .if pIlHot != NULL
    mov xax, pIlHot
    invoke SendMessage, [xsi].hWnd, TB_SETHOTIMAGELIST, 0, \
                        [xax].$Obj(MaskedImageList).hImageList
  .endif
  .if pIlDisabled != NULL
    mov xax, pIlDisabled
    invoke SendMessage, [xsi].hWnd, TB_SETDISABLEDIMAGELIST, 0, \
                        [xax].$Obj(MaskedImageList).hImageList
  .endif

  ;Add the toolbar buttons
  .if [xbx].dCount > 0
    invoke SendMessage, [xsi].hWnd, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0
    mov xax, xbx
    add xax, sizeof(DEF_TOOLBAR)                        ;xax -> buttons data
    invoke SendMessage, [xsi].hWnd, TB_ADDBUTTONS, [xbx].dCount, xax
    invoke SendMessage, [xsi].hWnd, TB_AUTOSIZE, 0, 0   ;Recalculate toolbar size
  .endif

  assume xbx:NOTHING

  Subclass Toolbar                                      ;Uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Toolbar.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method Toolbar.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "Toolbar"
  GetSubclassingInst Toolbar, pSelf
  OCall xax::Toolbar.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
