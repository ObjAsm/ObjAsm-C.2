; ==================================================================================================
; Title:    XCustomTreeView.inc
; Author:   G. Friedrich
; Version:  C.1.0
; Purpose:  ObjAsm support of Customized XTreeView and XTreeViewNode objects.
; Notes:    Version C.1.0, October 2017
;             - First release.
; ==================================================================================================


XTVNS_CHECKED       equ   BIT16         ;Check existing XTVNS_ states to avoid a collision!

;Hardcoded metrics
XTV_ICON_SIZE       equ   16
XTV_CHECK_SIZE      equ   13

XTVN_CUSTOM_DISP_INFO struc             ;Extend the XTVN_DISP_INFO structure
              XTVN_DISP_INFO    {}      ;Anonymous definition
  CheckRect   RECT              {}      ;New RECT structure for the check box
XTVN_CUSTOM_DISP_INFO ends
PXTVN_CUSTOM_DISP_INFO typedef ptr XTVN_CUSTOM_DISP_INFO

; --------------------------------------------------------------------------------------------------
; Object:  XCustomNode
; Purpose: Implement a customized XCustomNode object.

Object XCustomNode, 0, XTreeViewNode
  RedefineMethod    CanDragMe,          DWORD
  RedefineMethod    ContextPopup,       DWORD, DWORD
  RedefineMethod    MouseHit,           DWORD, PPOINT, PXTVN_CUSTOM_DISP_INFO, DWORD
  RedefineMethod    RenderContent,      PXTVN_CUSTOM_DISP_INFO
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:  XCustomTreeView
; Purpose: Implement a customized XCustomTreeView object.

Object XCustomTreeView, 0, XTreeView
  RedefineMethod    Drop,               $ObjPtr(XCustomNode), $ObjPtr(XCustomNode), DWORD
  RedefineMethod    OnCreate,           WPARAM, LPARAM                ;Create icon
  RedefineMethod    OnDestroy,          WPARAM, LPARAM                ;Destroy icon
  RedefineMethod    Startup                                           ;Register new wnd class
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM         ;Create new wnd class

  RedefineVariable  dDispInfoSize,      sizeof XTVN_CUSTOM_DISP_INFO  ;Size of the extended struc.
  DefineVariable    hIcon,              HICON,       0

  VirtualEvent      OnCommand,          WM_COMMAND
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;     XCustomNode
; ==================================================================================================

CStr szXCTV_Class, "XCustomTreeView"

;##\

; --------------------------------------------------------------------------------------------------
; Method:    XCustomNode.CanDragMe
; Purpose:   Indicate if a drag operation can be started.
; Arguments: Arg1: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:    eax = TRUE / FALSE.

Method XCustomNode.CanDragMe,, dKeyFlags:DWORD
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomNode.ContextPopup
; Purpose:   Display a context popup menu.
; Arguments: Arg1: X coord in screen coords.
;            Arg2: Y coord in screen coords.
; Return:    Nothing.

Method XCustomNode.ContextPopup, uses xbx xdi, dXPos:DWORD, dYPos:DWORD
  mov xbx, $invoke(LoadMenu, hInstance, $OfsCStr("MENU_CUSTOM_NODE"))
  invoke GetSubMenu, xax, 0
  SetObject xcx
  mov xdi, [xcx].pOwner
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, dXPos, dYPos, 0, [xdi].$Obj(XTreeView).hWnd, NULL
  invoke DestroyMenu, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomNode.MouseHit
; Purpose:   Check if the mouse has clicked a hotspot and perform an action.
; Arguments: Arg1: button that triggered this action.
;            Arg2: -> clicked point.
;            Arg3: -> XTVN_DISP_INFO.
;            Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:    eax = TRUE if and action was triggered, otherwise FALSE.

Method XCustomNode.MouseHit, uses xbx xdi xsi, dButton:DWORD, pPoint:PPOINT, \
                                               pDispInfo:PXTVN_CUSTOM_DISP_INFO, dKeyFlags:DWORD
;  DbgText "XCustomNode.MouseHit"
  .if pDispInfo != NULL
    SetObject xsi
    ACall xsi.MouseHit, dButton, pPoint, pDispInfo, dKeyFlags
    .if eax == FALSE
      .if [xsi].pFirstChild == NULL     ;Check if this is a terminal node
        SetObject xbx, XCustomTreeView, [xsi].pOwner

        ;Check for text hit
        mov xdx, pPoint
        mov eax, [xdx].POINT.x
        mov ecx, [xdx].POINT.y
        mov xdx, pDispInfo
        assume xdx:PXTVN_CUSTOM_DISP_INFO
        .if XTV_IsPointInRect(eax, ecx, [xdx].CheckRect)
;          DbgText "Hit on checkbox"
          mov eax, DFCS_BUTTONCHECK
          .ifBitSet [xsi].dState, XTVNS_CHECKED
            BitClr [xsi].dState, XTVNS_CHECKED
          .else
            BitSet [xsi].dState, XTVNS_CHECKED
            or eax, DFCS_CHECKED
          .endif

          ;Render the checkbox
          lea xdi, [xdx].CheckRect
          invoke DrawFrameControl, [xbx].hMemDC, xdi , DFC_BUTTON, eax
          invoke InvalidateRect, [xbx].hWnd, xdi, TRUE
          mov eax, TRUE
        .else
          xor eax, eax
        .endif
        assume xdx:NOTHING
      .else
        xor eax, eax
      .endif
    .else
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomNode.RenderContent
; Purpose:   Draw the content (icon + text) of the node.
; Arguments: Arg1: -> XTVN_CUSTOM_DISP_INFO
; Return:    Nothing.
; Note:      This method must update the coords of all Rect structures in the Content and must
;            invalidate the modified region.

Method XCustomNode.RenderContent, uses xbx xdi xsi, pDispInfo:PXTVN_CUSTOM_DISP_INFO
  local dPrevColor:DWORD, dPrevBkColor:DWORD, dPrevBkMode:DWORD, InvRect:RECT, hFontPrev:HFONT
  local cBuffer[1024]:CHR, pChar:PCHR

;  DbgText "XCustomNode.RenderContent"
  mov xdi, pDispInfo
  .if xdi != NULL
    SetObject xsi
    mov xbx, [xsi].pOwner
    assume xdi:ptr XTVN_CUSTOM_DISP_INFO, xbx:$ObjPtr(XCustomTreeView)
    m2m [xdi].TextRect.left, [xdi].ContentRect.left, eax
    m2m [xdi].TextRect.right, [xdi].ContentRect.right, ecx

    ;Get the drawing rect
    m2m InvRect.left, [xdi].ContentRect.left, eax
    m2m InvRect.top, [xdi].sdNodeTop, ecx
    m2m InvRect.right, [xbx].ClientSize.x, eax
    m2m InvRect.bottom, [xdi].sdNodeBot, ecx

    ;Clear the background
    OCall xbx::XTreeView.RenderBackground, addr InvRect

    ;Put an icon on nodes that have childs, else a checkbox
    .if [xsi].pFirstChild == NULL
      ;Calc CheckRect
      mov eax, [xdi].ContentRect.bottom
      sub eax, [xdi].ContentRect.top
      sub eax, XTV_CHECK_SIZE
      shr eax, 1
      mov ecx, [xdi].ContentRect.bottom
      sub ecx, eax
      mov [xdi].CheckRect.bottom, ecx                 ;CheckRect.bottom
      sub ecx, XTV_CHECK_SIZE
      mov [xdi].CheckRect.top, ecx                    ;CheckRect.top

      mov edx, [xdi].ContentRect.left
      add edx, 3
      mov [xdi].CheckRect.left, edx                   ;CheckRect.left
      add edx, XTV_CHECK_SIZE
      mov [xdi].CheckRect.right, edx                  ;CheckRect.right
      add edx, 3
      mov [xdi].TextRect.left, edx                    ;TextRect.left

      ;Set the control draw flags
      mov eax, DFCS_BUTTONCHECK
      .ifBitSet [xsi].dState, XTVNS_CHECKED
        or eax, DFCS_CHECKED
      .endif

      ;Render the checkbox
      invoke DrawFrameControl, [xbx].hMemDC, addr [xdi].CheckRect, DFC_BUTTON, eax

    .else
      ;Calc icon position
      mov eax, [xdi].ContentRect.bottom
      sub eax, [xdi].ContentRect.top
      sub eax, XTV_ICON_SIZE
      shr eax, 1
      mov ecx, [xdi].ContentRect.bottom
      sub ecx, eax
      sub ecx, XTV_ICON_SIZE
      mov [xdi].CheckRect.top, ecx                    ;ecx = Icon top

      mov edx, [xdi].ContentRect.left
      add edx, 3                                      ;edx = Icon left
      mov eax, edx
      add eax, 3
      add eax, XTV_ICON_SIZE
      mov [xdi].TextRect.left, eax                    ;TextRect.left

      ;Render the icon
      invoke DrawIconEx, [xbx].hMemDC, edx, [xdi].CheckRect.top, [xbx].hIcon, \
                         XTV_ICON_SIZE, XTV_ICON_SIZE, NULL, NULL, DI_NORMAL

    .endif

    ;Create a text
    mov pChar, $invoke(StrECopy, addr cBuffer, $OfsCStr(" Node @ "))
    if TARGET_BITNESS eq 32
      invoke dword2hex, eax, esi
      add pChar, 8*sizeof(CHR)
    else
      invoke qword2hex, xax, rsi
      add pChar, 16*sizeof(CHR)
    endif
    invoke StrECopy, pChar, $OfsCStr("h")

    ;Debugging strings
    ;invoke StrECopy, eax, $OfsCStr("  Node height=")
    ;invoke dword2dec, eax, [xsi].dHeight
    ;invoke StrECat, addr cBuffer, $OfsCStr(", Branch height=")
    ;invoke dword2dec, eax, [xsi].dBranchHeight
    ;invoke StrCat, addr cBuffer, $OfsCStr(".")

    ;Set text and background colors
    ;  Check if the whole XTV or the single node is disabled
    .if ([xbx].dState & XTVS_DISABLED) || ([xsi].dState & XTVNS_DISABLED)
      ;Disabled
      invoke GetSysColor, COLOR_GRAYTEXT
      mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
      mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, TRANSPARENT))
    .else
      ;Enabled
      .if xsi == [xbx].pSelectedNode
        .ifBitSet [xbx].dState, XTVS_FOCUSED
          .ifBitSet [xsi].dState, XTVNS_HOTTRACK      ;Check if the node is beeing hottracked
            mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, $RGB(255,255,0)))
          .else
            invoke GetSysColor, COLOR_HIGHLIGHTTEXT
            mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
          .endif
          invoke GetSysColor, COLOR_HIGHLIGHT
          mov dPrevBkColor, $32($invoke(SetBkColor, [xbx].hMemDC, eax))
          mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, OPAQUE))
        .else
          invoke GetSysColor, COLOR_WINDOWTEXT
          mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
          invoke GetSysColor, COLOR_BTNFACE
          mov dPrevBkColor, $32($invoke(SetBkColor, [xbx].hMemDC, eax))
          mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, OPAQUE))
        .endif
      .elseIfBitSet [xsi].dState, XTVNS_HOTTRACK      ;Check if the node is beeing hottracked
        invoke GetSysColor, COLOR_HOTLIGHT
        mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
        mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, TRANSPARENT))
      .else
        invoke GetSysColor, COLOR_WINDOWTEXT
        mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
        mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, TRANSPARENT))
      .endif
    .endif

    ;Set the font
    mov hFontPrev, $invoke(SelectObject, [xbx].hMemDC, [xbx].hFontText)

    ;Render the created text
    OCall xsi.RenderText, xdi, addr cBuffer

    ;Restore previous settings
    invoke SelectObject, [xbx].hMemDC, hFontPrev
    invoke SetBkMode, [xbx].hMemDC, dPrevBkMode
    invoke SetBkColor, [xbx].hMemDC, dPrevBkColor
    invoke SetTextColor, [xbx].hMemDC, dPrevColor

    ;Invalidate the new drawn rect
    invoke InvalidateRect, [xbx].hWnd, addr InvRect, FALSE
    assume xdi:NOTHING, xbx:NOTHING
  .endif
MethodEnd


;##/

; ==================================================================================================
;     XCustomTreeView
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Method:    XCustomTreeView.Drop
; Purpose:   Drop a node.
; Arguments: Arg1: -> Node to drop.
;            Arg2: -> Reference node.
;            Arg3: how to drop.
; Return:    Nothing.

Method XCustomTreeView.Drop,, pNode:$ObjPtr(XCustomNode), pRefNode:$ObjPtr(XCustomNode), \
                              dHowToDrop:DWORD
;  uses xbx!                              
;  local cBuffer[MAX_PATH]:CHR
;
;  lea xbx, cBuffer
;  invoke GetEnvironmentVariable, $OfsCStr("OBJASM_PATH"), xbx, lengthof cBuffer
;  invoke StrCCat, xbx, $OfsCStr("\Resources\WAV\Bleep.wav"), lengthof cBuffer
;  invoke PlaySound, xbx, NULL, SND_FILENAME or SND_ASYNC
  ACall Drop, pNode, pRefNode, dHowToDrop
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomTreeView.OnCommand
; Purpose:   Event handler for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = WM_COMMAND return value.

Method XCustomTreeView.OnCommand,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xax, [xcx].pOwner
  invoke SendMessage, [xax].$Obj(WinApp).hWnd, WM_COMMAND, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomTreeView.OnCreate
; Purpose:   Event handler for WM_CREATE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero to continue creation of the window, else -1.

Method XCustomTreeView.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XCustomTreeView.OnCreate"
  SetObject xsi
  ACall xsi.OnCreate, wParam, lParam
  invoke LoadIcon, hInstance, $OfsCStr("ICON_APP")
  mov [xsi].hIcon, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomTreeView.OnDestroy
; Purpose:   Event handler for WM_DESTROY message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero.

Method XCustomTreeView.OnDestroy,, wParam:WPARAM, lParam:LPARAM
;  DbgText "XCustomTreeView.OnDestroy"
  SetObject xcx
  invoke DestroyIcon, [xcx].hIcon
  ACall OnDestroy, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomTreeView.WindowProc
; Purpose:   Processing of window messages.
; Arguments: Arg1: Message identifier.
;            Arg2: First message parameter.
;            Arg3: Second message parameter.
; Return:    eax = This value is the result of the message processing and depends on the message ID.
;            Window handle is passed in pSelf (hidden parameter).

Method XCustomTreeView.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "XCustomTreeView"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance

      mov xsi, $New(XCustomTreeView)
      OCall xsi::XCustomTreeView.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(XCustomTreeView).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::XCustomTreeView.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA         ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                       ;GetWindowLong returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::XCustomTreeView.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XCustomTreeView.Startup
; Purpose:   Register the XCustomTreeView window class with the operating system.
; Arguments: None.
; Return:    Nothing.

Method XCustomTreeView.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_PARENTDC or CS_BYTEALIGNWINDOW or \
                CS_BYTEALIGNCLIENT; or CS_DBLCLKS
  m2m WC.lpfnWndProc, $MethodAddr(XCustomTreeView.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szXCTV_Class, xax
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_ARROW"))
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

;##/

endif
