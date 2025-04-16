; ==================================================================================================
; Title:      OAE_InfoTree.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    InfoTree implementation for OA_ObjExplorer. 
; ==================================================================================================


XTV_ICON_SIZE       equ   16

XTVN_TREE_DISP_INFO struct              ;Extend the XTVN_DISP_INFO structure
              XTVN_DISP_INFO    {}      ;Anonymous definition
XTVN_TREE_DISP_INFO ends
PXTVN_TREE_DISP_INFO typedef ptr XTVN_TREE_DISP_INFO


Object InfoTree, 0, XTreeView
  VirtualMethod     FindNode,           PSTRINGA, DWORD
  RedefineMethod    Init,               POINTER, HANDLE, PDEF_XTV
  RedefineMethod    OnCreate,           WPARAM, LPARAM          ;Create icons
  RedefineMethod    OnDestroy,          WPARAM, LPARAM          ;Destroy icons
  RedefineMethod    OnLButtonDblClk,    WPARAM, LPARAM
  RedefineMethod    Startup                                     ;Register new Window Class
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  RedefineVariable  dFlags,             XTV_FLAGS or XTVF_DISABLE_DEL_KEY
  RedefineVariable  dDispInfoSize,      sizeof XTVN_TREE_DISP_INFO;Extended structure
  DefineVariable    hIconObjStd,        HANDLE,      0
  DefineVariable    hIconObjPrj,        HANDLE,      0
  DefineVariable    hIconIntStd,        HANDLE,      0
  DefineVariable    hIconIntPrj,        HANDLE,      0
  DefineVariable    hIconErr,           HANDLE,      0

  VirtualEvent      OnCommand,          WM_COMMAND
ObjectEnd


Object InfoNode, 0, XTreeViewNode
  RedefineMethod    CanDragMe,          DWORD
  VirtualMethod     FindNode,           PSTRINGA
  RedefineMethod    RenderContent,      PXTVN_TREE_DISP_INFO    ;Render check box

  DefineVariable    pInfo,              PINFORMATION,    NULL   ;-> INFORMATION
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;     InfoNode
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Method:     InfoNode.CanDragMe
; Purpose:    Indicates if a drag operation can be started.
; Arguments:  Arg1: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     TRUE / FALSE.

Method InfoNode.CanDragMe,, dKeyFlags:DWORD
  xor eax, eax                                          ;eax = FALSE  (disallow dragging)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoNode.FindNode
; Purpose:    Searches this node branch for the specified node name.
; Arguments:  Arg1: -> Node name.
; Return:     xax -> found node or NULL.

Method InfoNode.FindNode, uses xsi, pName:PSTRINGA
  SetObject xsi
  mov xcx, [xsi].pInfo
  .if $invoke(StrCompA, [xcx].INFORMATION.pName, pName) == 0
    mov xax, xsi
  .else
    mov xcx, [xsi].pFirstChild
    .if xcx != NULL
      OCall xcx::InfoNode.FindNode, pName
      test xax, xax
      jnz @@EOM
    .endif
    mov xcx, [xsi].pNextSibling
    .if xcx != NULL
      OCall xcx::InfoNode.FindNode, pName
    .else
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoNode.RenderContent
; Purpose:    Draws the content (icon + text) of the node.
; Arguments:  Arg1: -> XTVN_TREE_DISP_INFO
; Return:     Nothing.
; Note:       This method must update the coords of all Rect structures in the Content and must
;             invalidate the modified region.

Method InfoNode.RenderContent, uses xbx xdi xsi, pDispInfo:PXTVN_TREE_DISP_INFO
  local dPrevColor:DWORD, dPrevBkColor:DWORD, dPrevBkMode:DWORD, InvRect:RECT, hFontPrev:HANDLE
  local dIconWidth:DWORD, dIconHeight:DWORD

  ;DbgText "InfoNode.RenderContent"
  mov xdi, pDispInfo
  .if xdi != NULL
    SetObject xsi
    mov xbx, [xsi].pOwner
    assume xdi:ptr XTVN_TREE_DISP_INFO, xbx:$ObjPtr(InfoTree)
    m2m [xdi].TextRect.left, [xdi].ContentRect.left, eax
    m2m [xdi].TextRect.right, [xdi].ContentRect.right, eax

    ;Get the drawing rect
    m2m InvRect.left, [xdi].ContentRect.left, eax
    m2m InvRect.top, [xdi].sdNodeTop, eax
    m2m InvRect.right, [xbx].ClientSize.x, eax
    m2m InvRect.bottom, [xdi].sdNodeBot, eax

    ;Clear the background
    OCall xbx::InfoTree.RenderBackground, addr InvRect

    ;Put an icon on nodes that have childs,
    ;Calc icon position
    mov eax, [xdi].ContentRect.bottom
    sub eax, [xdi].ContentRect.top
    sub eax, XTV_ICON_SIZE
    shr eax, 1
    mov ecx, [xdi].ContentRect.bottom
    sub ecx, eax
    sub ecx, XTV_ICON_SIZE                              ;ecx = Icon top

    mov edx, [xdi].ContentRect.left
    add edx, 3                                          ;edx = Icon left
    mov eax, edx
    add eax, 3
    add eax, XTV_ICON_SIZE
    mov [xdi].TextRect.left, eax                        ;TextRect.left
    mov dIconWidth, edx
    mov dIconHeight, ecx

    ;Render the icon
    mov xax, [xsi].pInfo
    .ifBitSet [xax].INFORMATION.dFlags, INF_INTERFACE
      .ifBitSet [xax].INTERFACEINFORMATION.dFlags, INF_PRJ
        mov xax, [xbx].hIconIntPrj
      .else
        mov xax, [xbx].hIconIntStd
      .endif
    .else
      .ifBitSet [xax].OBJECTINFORMATION.dFlags, INF_PRJ
        mov xax, [xbx].hIconObjPrj
      .else
        mov xax, [xbx].hIconObjStd
      .endif
    .endif
    invoke DrawIconEx, [xbx].hMemDC, dIconWidth, dIconHeight, xax, \
                       XTV_ICON_SIZE, XTV_ICON_SIZE, NULL, NULL, DI_NORMAL
    ;Render the overlay
    mov xax, [xsi].pInfo
    .ifBitSet [xax].INFORMATION.dFlags, INF_INVALID
      invoke DrawIconEx, [xbx].hMemDC, dIconWidth, dIconHeight, [xbx].hIconErr, \
                         XTV_ICON_SIZE, XTV_ICON_SIZE, NULL, NULL, DI_NORMAL
    .endif

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
          .ifBitSet [xsi].dState, XTVNS_HOTTRACK        ;Check if the node is beeing hottracked
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
      .elseIfBitSet [xsi].dState, XTVNS_HOTTRACK        ;Check if the node is beeing hottracked
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
    mov xax, [xsi].pInfo
    OCall xsi.RenderText, xdi, [xax].INFORMATION.pName

    ;Restore previous settings
    invoke SelectObject, [xbx].hMemDC, hFontPrev
    invoke SetBkMode, [xbx].hMemDC, dPrevBkMode
    invoke SetBkColor, [xbx].hMemDC, dPrevBkColor
    invoke SetTextColor, [xbx].hMemDC, dPrevColor

    ;Invalidate the new drawn rect
    invoke InvalidateRect, [xbx].hWnd, addr InvRect, FALSE
    assume edi:NOTHING, ebx:NOTHING
  .endif
MethodEnd


;##/

; ==================================================================================================
;     InfoTree
; ==================================================================================================

;##\

CStr cInfoTreeClass, "OAC_InfoTree"

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.Init
; Purpose:    Initializes a InfoTree object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method InfoTree.Init, uses xbx xsi, pOwner:POINTER, hParentWnd:HANDLE, pDefStruc:PDEF_XTV
  ;DbgText "XTreeView.Init"
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:ptr DEF_XTV
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE or WS_TABSTOP
  invoke CreateWindowEx, [xbx].dExStyle, offset cInfoTreeClass, [xbx].pTitle, \
         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
         hParentWnd, [xbx].xCtlID, hInstance, xsi
  assume xbx:NOTHING
  TCall xsi::WinPrimer.Init, pOwner, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.FindNode
; Purpose:    Searches the tree for the specified node name.
; Arguments:  Arg1: -> Node name.
;             Arg2: Information type (INFO_TYPE_OBJECT or INFO_TYPE_INTERFACE).
; Return:     xax -> found node or NULL.

Method InfoTree.FindNode, uses xbx xsi, pName:PSTRINGA, dType:DWORD
  SetObject xsi
  mov xbx, [xsi].pFirstChild
  xor eax, eax
  .while xbx != NULL
    mov xcx, [xbx].$Obj(InfoNode).pInfo
    .if dType == INFO_TYPE_OBJECT
      .ifBitClr [xcx].INFORMATION.dFlags, INF_INTERFACE
        OCall xbx::InfoNode.FindNode, pName
        .break .if xax != NULL
      .endif
    .else
      .ifBitSet [xcx].INFORMATION.dFlags, INF_INTERFACE
        OCall xbx::InfoNode.FindNode, pName
        .break .if xax != NULL
      .endif
    .endif
    mov xbx, [xbx].$Obj(InfoNode).pNextSibling
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.OnCommand
; Purpose:    Event handler for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = WM_COMMAND return value.

Method InfoTree.OnCommand,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xax, [xcx].pOwner
  invoke SendMessage, [xax].$Obj(MdiApp).hWnd, WM_COMMAND, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.OnCreate
; Purpose:    Event handler for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method InfoTree.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov [xsi].hIconObjStd, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_OBJ_STD"))
  mov [xsi].hIconObjPrj, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_OBJ_PRJ"))
  mov [xsi].hIconIntStd, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_INT_STD"))
  mov [xsi].hIconIntPrj, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_INT_PRJ"))
  mov [xsi].hIconErr, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_OVR_ERROR"))
  ACall xsi.OnCreate, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.OnDestroy
; Purpose:    Event handler for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method InfoTree.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "InfoTree.OnDestroy"
  SetObject xsi
  invoke DestroyIcon, [xsi].hIconObjStd
  invoke DestroyIcon, [xsi].hIconObjPrj
  invoke DestroyIcon, [xsi].hIconIntStd
  invoke DestroyIcon, [xsi].hIconIntPrj
  invoke DestroyIcon, [xsi].hIconErr
  ACall xsi.OnDestroy, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.OnLButtonDblClk
; Purpose:    Event handler for WM_LBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method InfoTree.OnLButtonDblClk, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ACall xsi.OnLButtonDblClk, wParam, lParam

  ;Now we send a message to the Application to open a child window
  ; with the passed object information
  mov xcx, [xsi].pOwner
  mov xax, [xcx].$Obj(WinPrimer).pOwner
  mov xcx, [xsi].$Obj(InfoTree).pSelectedNode
  .if xcx != NULL
    mov xbx, [xcx].$Obj(InfoNode).pInfo
    .ifBitSet [xbx].INFORMATION.dFlags, INF_INTERFACE
      invoke SendMessage, [xax].$Obj(WinPrimer).hWnd, WM_COMMAND, IDM_OPEN_INT_PROP_WND, xbx
    .else
      invoke SendMessage, [xax].$Obj(WinPrimer).hWnd, WM_COMMAND, IDM_OPEN_OBJ_PROP_WND, xbx
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window HANDLE is passed in Self.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method InfoTree.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;if lpCreateParams is 0, then it is a resource call => create new object instance

      mov xsi, $New(InfoTree)
      OCall xsi::InfoTree.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(InfoTree).hWnd, pSelf, xcx
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::InfoTree.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWL_USERDATA wasn't set,
    .if eax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::InfoTree.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     InfoTree.Startup
; Purpose:    Registers the InfoTree object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method InfoTree.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_PARENTDC or CS_DBLCLKS
  m2m WC.lpfnWndProc, $MethodAddr(InfoTree.WndProc), xdx
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0
  mov WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cInfoTreeClass, xax
  mov WC.hIcon, 0
  mov WC.hCursor, $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_XTV_ARROW"))
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC
MethodEnd

;##/

endif
