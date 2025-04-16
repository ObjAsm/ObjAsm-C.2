; ==================================================================================================
; Title:      TabCtrl.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of TabControl GDI control.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_TABCONTROL struc
  xCtlID        XWORD     ?   ;Contol ID
  dStyle        DWORD     ?   ;Style
  dExStyle      DWORD     ?   ;Extended style
  pTitle        PSTRING   ?   ;-> Window title
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?   ;X position
      sdPosY    SDWORD    ?   ;Y position
      dWidth    DWORD     ?   ;Width
      dHeight   DWORD     ?   ;Height
    ends
  ends
DEF_TABCONTROL ends
PDEF_TABCONTROL typedef ptr DEF_TABCONTROL

; --------------------------------------------------------------------------------------------------
; Object:     TabIptor
; Purpose:    TabIptor is a interceptor object used internally by the TabCtrl object.

Object TabIptor, , MsgInterceptor
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnNotify,           WM_NOTIFY
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     TabCtrl
; Purpose:    TabCtrl is a thin wrapper around the SysTabControl32 GDI control.

Object TabCtrl, TabCtrlID, WinControl   ;Class "SysTabControl32"
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, $ObjPtr(MaskedImageList), PDEF_TABCONTROL
  VirtualMethod     Insert,             DWORD, HWND, POINTER, DWORD
  VirtualMethod     SetPadding,         DWORD, DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  Embed    Iptor,  TabIptor
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szTabCtlIptor, "TabCtlIptor"

; ==================================================================================================
;    TabCtrl implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     TabCtrl.Done
; Purpose:    Finalize the TabCtrl object, freeing allocated memory.
; Arguments:  None.
; Return:     Nothing.

Method TabCtrl.Done, uses xsi
  SetObject xsi
  Unsubclass TabCtrl                                    ;Uses xsi
  OCall [xsi].Iptor::TabIptor.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TabCtrl.Init
; Purpose:    Initialize the TabCtrl object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> MaskedImageList object.
;             Arg4: -> DEF_TABCONTROL structure.
; Return:     Nothing.

Method TabCtrl.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, \
                                   pImageList:$ObjPtr(MaskedImageList), pDefStruc:PDEF_TABCONTROL
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_TABCONTROL
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("SysTabControl32"), [xbx].pTitle, \
                         [xbx].dStyle, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax

  .if pImageList != NULL
    mov xax, pImageList
    invoke SendMessage, [xsi].hWnd, TCM_SETIMAGELIST, 0, [xax].$Obj(MaskedImageList).hImageList
  .endif
  OCall [xsi].Iptor::TabIptor.Init, xsi, hParent, addr szTabCtlIptor
  invoke SendMessage, hParent, WM_GETFONT, 0, 0
  invoke SendMessage, [xsi].hWnd, WM_SETFONT, xax, TRUE
  Subclass TabCtrl                                      ;Uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TabCtrl.Insert
; Purpose:    Add a window to the TabControl.
; Arguments:  Arg1: Index into the TabControl.
;             Arg2: Inserted window handle.
;             Arg3: -> Tab-identifier string
;             Arg4: Index into associated ImageList.
; Return:     eax = Inserted Position index.

Method TabCtrl.Insert,, dIndex:DWORD, hWnd:HWND, pText:POINTER, dImageIndex:DWORD
  local TCI:TC_ITEM

  SetObject xcx
  mov TCI.mask_, TCIF_PARAM or TCIF_TEXT or TCIF_IMAGE
;  m2z TCI.lpReserved1
;  m2z TCI.lpReserved2
  m2m TCI.pszText, pText, xax
  m2m TCI.iImage, dImageIndex, edx
  m2m TCI.lParam, hWnd, xax
  invoke SendMessage, [xcx].hWnd, TCM_INSERTITEM, dIndex, addr TCI
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TabCtrl.SetPadding
; Purpose:    Set horizontal and vertical padding.
; Arguments:  Arg1: Horizontal padding in pixel.
;             Arg2: Vertical padding in pixel.
; Return:     Nothing.

Method TabCtrl.SetPadding,, dHorzPadding:DWORD, dVertPadding:DWORD
  SetObject xcx
  mov eax, dVertPadding
  shl eax, 16
  mov ax, WORD ptr dHorzPadding
  invoke SendMessage, [xcx].hWnd, TCM_SETPADDING , 0, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TabCtrl.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method TabCtrl.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  GetSubclassingInst TabCtrl, pSelf
  OCall xax::TabCtrl.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;    TabIptor implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     TabIptor.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = The return value is ignored except the notification message specify otherwise.

Method TabIptor.OnNotify, uses xbx xdi, wParam:WPARAM, lParam:LPARAM
  local TCI:TC_ITEM

  mov xbx, lParam
  .if [xbx].NMHDR.code == TCN_SELCHANGING               ;Hide current window
    mov TCI.mask_, TCIF_PARAM
    invoke SendMessage, [xbx].NMHDR.hwndFrom, TCM_GETCURSEL, 0, 0
    lea xdi, TCI
    invoke SendMessage, [xbx].NMHDR.hwndFrom, TCM_GETITEM, xax, xdi
    invoke ShowWindow, TCI.lParam, SW_HIDE
    xor eax, eax                                        ;Allow the selection to change   eax = FALSE
  .elseif [xbx].NMHDR.code == TCN_SELCHANGE             ;Show new window
    mov TCI.mask_, TCIF_PARAM
    invoke SendMessage, [xbx].NMHDR.hwndFrom, TCM_GETCURSEL, 0, 0
    lea xdi, TCI
    invoke SendMessage, [xbx].NMHDR.hwndFrom, TCM_GETITEM, xax, xdi
    invoke ShowWindow, TCI.lParam, SW_SHOWDEFAULT
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TabIptor.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method TabIptor.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "TabIptor"
  invoke GetProp, pSelf, offset szTabCtlIptor
  OCall xax::MsgInterceptor.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
