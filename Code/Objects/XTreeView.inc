; ==================================================================================================
; Title:      XTreeView.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of XTreeView objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;XTreeView states
XTVS_DISABLED                 equ   BIT00         ;Must be the first one
XTVS_VISIBLE                  equ   BIT01         ;Visibility flag
XTVS_FOCUSED                  equ   BIT02         ;The control has the input focus
XTVS_LOCKED                   equ   BIT03         ;No visual update
XTVS_DRAGGINGSTARTED          equ   BIT04         ;A drag operation has been stared
XTVS_DRAGGING                 equ   BIT05         ;A drag operation is beeing performed
XTVS_DRAGGINGABORTED          equ   BIT06         ;Drag operation was aborted but LMB is still down


;XTreeView flags
XTVF_RESOURCE                 equ   BIT01         ;Control was loaded from a resource
XTVF_SHOW_LINES               equ   BIT02
XTVF_SHOW_TOGGLER             equ   BIT03
XTVF_COLLAPSE_ON_DRAG         equ   BIT04
XTVF_EXPAND_PARENT_ON_DROP    equ   BIT05
XTVF_KEEP_COLLAPSED_ON_DRAG   equ   BIT06
XTVF_DISABLE_DEL_KEY          equ   BIT07
XTVF_USE_USER_BKGND_COLOR     equ   BIT08


XTV_FLAGS                     equ   XTVF_SHOW_LINES or XTVF_SHOW_TOGGLER or \
                                    XTVF_EXPAND_PARENT_ON_DROP or \
                                    XTVF_COLLAPSE_ON_DRAG or XTVF_KEEP_COLLAPSED_ON_DRAG

;XTreeViewNode states
XTVNS_DISABLED                equ   BIT00         ;Must be the first one
XTVNS_EXPANDED                equ   BIT01
XTVNS_HOTTRACK                equ   BIT02
XTVNS_FOCUSED                 equ   BIT03         ;A node has the input focus

XTVNS_SEL_PATH                equ   BIT08         ;Used to mark the path to the selected node
XTVNS_VIS_PATH                equ   BIT09         ;Used to mark the path to the first visible node


;Hardcoded metrics
XTV_SCROLL_ACTIVATION         equ   15
XTV_TOGGLER_SIZE              equ   9


;Insertion modes
XTVN_INSERT_NOT_ALLOWED       equ   0
XTVN_INSERT_AS_FIRST_CHILD    equ   1
XTVN_INSERT_AS_LAST_CHILD     equ   2
XTVN_INSERT_AS_PREV_SIBLING   equ   3
XTVN_INSERT_AS_NEXT_SIBLING   equ   4


DEF_XTV struc
  xCtlID        XWORD     ?         ;Contol ID
  dStyle        DWORD     ?         ;Style
  dExStyle      DWORD     ?         ;Extended style
  pTitle        PSTRING   ?         ;-> Control caption
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?         ;X position
      sdPosY    SDWORD    ?         ;Y position
      dWidth    DWORD     ?         ;Width
      dHeight   DWORD     ?         ;Height
    ends
  ends
DEF_XTV ends
PDEF_XTV typedef ptr DEF_XTV

XTVN_DISP_INFO struc
  pNode         POINTER   ?         ;-> node
  sdNodeTop     SDWORD    ?         ;Coord in hMemDC when drawn
  sdNodeBot     SDWORD    ?         ;Coord in hMemDC when drawn
  TogglerRect   RECT      {}        ;Coords in hMemDC when drawn
  ContentRect   RECT      {}        ;Coords in hMemDC when drawn
  TextRect      RECT      {}        ;Coords in hMemDC when drawn
XTVN_DISP_INFO ends
PXTVN_DISP_INFO typedef ptr XTVN_DISP_INFO

; --------------------------------------------------------------------------------------------------
; Object:     XTreeViewNode
; Purpose:    Implement node of the XTreeView.
;
; Node layout:
; ----------・;
;
;  |<------ Node indent ----->|<----- Node width ----->|
;  |                          |                        |
;  |                          |                        |
;
;
;   --------------------------------------------------------------     ----------・sdNodeTop
;  |       |      |      |     ------------------------           |     /|\
;  |       |      |      |    |  Con-   ------------   |          |      |
;  |       |      |     [-]---|  tent  |  TextRect  |  |          |      Node height
;  |       |      |   Toggler |  Rect   ------------   |          |      |
;  |       |      |    Rect    ------------------------           |     \|/
;  |       |      |             |     ----------------------      |    ----------  sdNodeBot
;  |       |      |             |    |                      |     |     /|\
;  |       |      |             |----|      First Child     |     |      |
;  |       |      |             |    |                      |     |      |
;  |       |      |             |     ----------------------      |      |
;  |       |      |             |     --------------------------  |      |
;  |       |      |             |    |                          | |      |
;  |       |      |            [+]---|      Next Child          | |      Branch height
;  |       |      |             |    |                          | |      |
;  |       |      |             |     --------------------------  |      |
;  |       |      |             |     ----------------------      |      |
;  |       |      |             |    |                      |     |      |
;  |       |      |              ----|      Last Child      |     |      |
;  |       |      |                  |                      |     |      |
;  |       |      |                   ----------------------      |     \|/
;   --------------------------------------------------------------     ----・;
;
;  |                                 |                          | |
;  |                                 |                          | |
;  |                                 |<----- Branch width ----->| |
;  |                                                              |
;  |<--------------------------- View width --------------------->|
;
;
;
;  Notes: - The ToggerRect vertical position is aligned with the ContentRect.
;         - The space between the parent vertical lines is defined by dNodeIndent.
;         - To add new node RECTs, XTVN_DISP_INFO must be expanded. In this case, the
;           new structure size must be updated using the dDispInfoSize data member.
;         - Branch metrics are computed in the current expansion state of child nodes.
;         - The client area is the draw rectangle without the scrollbars.
;         - The draw area is the window client area including the scrollbars.

Object XTreeViewNode, XTreeViewNodeID, Streamable
  VirtualMethod     CanDragMe,          DWORD
  VirtualMethod     CanDropHere,        $ObjPtr(XTreeViewNode), DWORD, DWORD
  VirtualMethod     ContextPopup,       DWORD, DWORD
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, DWORD, DWORD, DWORD
  VirtualMethod     MouseHit,           DWORD, PPOINT, PXTVN_DISP_INFO, DWORD
  VirtualMethod     MouseHitDbl,        DWORD, PPOINT, PXTVN_DISP_INFO, DWORD
  VirtualMethod     Render,             PXTVN_DISP_INFO
  VirtualMethod     RenderContent,      PXTVN_DISP_INFO
  VirtualMethod     RenderText,         PXTVN_DISP_INFO, PSTRING
  VirtualMethod     RenderTreeStruc,    PXTVN_DISP_INFO
  VirtualMethod     Toggle

  DefineVariable    pParent,            $ObjPtr(XTreeViewNode),  NULL  ;-> Parent node
  DefineVariable    pNextSibling,       $ObjPtr(XTreeViewNode),  NULL  ;-> Next sibling node
  DefineVariable    pPrevSibling,       $ObjPtr(XTreeViewNode),  NULL  ;-> Previous sibling node
  DefineVariable    dState,             DWORD,        0
  DefineVariable    dHeight,            DWORD,        0
  DefineVariable    dWidth,             DWORD,        0

  DefineVariable    pFirstChild,        $ObjPtr(XTreeViewNode),  NULL  ;-> First child node
  DefineVariable    pLastChild,         $ObjPtr(XTreeViewNode),  NULL  ;-> Last child node
  DefineVariable    dBranchHeight,      DWORD,        0
  DefineVariable    dBranchWidth,       DWORD,        0
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     XTreeView
; Purpose:    Implement the XTreeView.
;
; Features:
; --------
; Smooth scrolling.
; Customized drawing.
; Each node can have different heights.
; Fast drawing. Only nodes in view are drawn.
; Streaming is possible.
; No flicker due to backbuffering.
; High degree of customization due to inheritance.
; Full key navigation implemented.
; Mouse wheel support for both scrollbars. The Shift key is used to scroll horizontally.
; Drag and drop is preformed with one of the mouse buttons.
;   The other button remains free to expand or collapse branches.
; Autoscrolling if we are in the "scroll activation area".
; Multiple node insertion modes implemented.
; Flexible intelligent cursor management.
;
; Some rules:
; ----------
; 1. The owner of all nodes is the XTreeView object.
; 2. The parent of a node is its hirarchical parent node in the tree.
; 3. Root nodes have NULL as parent.
; 4. Branch width and height are fields that contain the dims of a branch considdering the expanded
;    state of their childs. A node may have different values in the dHeight and dBranchHeight field.
;    You have to take the correct one depending on the node expansion state.
; 5. Non visible nodes should have dHeigt = dWidth = 0.
; 6. To use double clicks, enable CS_DBLCLKS in the class definition in the Startup StaticMethod of
;    the derived object.
;
; XTreeView public methods:
; ------------------------
; Init / Done
; Insert / Remove / Dispose
; Select / Draw

Object XTreeView, XTreeViewID, WinPrimer
  VirtualMethod     CanDropHere,        $ObjPtr(XTreeViewNode), DWORD, DWORD
  VirtualMethod     CreateBackBuffer
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  VirtualMethod     Dispose,            $ObjPtr(XTreeViewNode)
  RedefineMethod    Done
  VirtualMethod     Draw
  VirtualMethod     Drop,               $ObjPtr(XTreeViewNode), $ObjPtr(XTreeViewNode), DWORD
  VirtualMethod     Find1stVisibleNode, DWORD
  VirtualMethod     GetDispInfo,        $ObjPtr(XTreeViewNode)
  VirtualMethod     GetMetrics
  RedefineMethod    Init,               POINTER, HWND, PDEF_XTV
  VirtualMethod     InitRes,            HWND
  VirtualMethod     Insert,             $ObjPtr(XTreeViewNode), $ObjPtr(XTreeViewNode), DWORD
  VirtualMethod     MoveInViewBottom,   $ObjPtr(XTreeViewNode)
  VirtualMethod     MoveInViewTop,      $ObjPtr(XTreeViewNode)
  VirtualMethod     OnButtonDblClk,     DWORD, WPARAM, LPARAM
  VirtualMethod     OnButtonDown,       DWORD, WPARAM, LPARAM
  VirtualMethod     OnButtonUp,         DWORD, WPARAM, LPARAM
  RedefineMethod    OnSettingChange,    WPARAM, LPARAM
  RedefineMethod    OnSysColorChange,   WPARAM, LPARAM
  VirtualMethod     Remove,             $ObjPtr(XTreeViewNode)
  VirtualMethod     RenderBackground,   PRECT
  VirtualMethod     Reset
  VirtualMethod     Select,             $ObjPtr(XTreeViewNode)
  VirtualMethod     Set1stVisibleNode,  $ObjPtr(XTreeViewNode)
  VirtualMethod     SetDragCursor,      DWORD, DWORD
  VirtualMethod     ShowScrollbars
  StaticMethod      Startup
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnKeyDown,          WM_KEYDOWN
  VirtualEvent      OnKeyUp,            WM_KEYUP
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL
  VirtualEvent      OnNcHitTest,        WM_NCHITTEST
  VirtualEvent      OnLButtonDblClk,    WM_LBUTTONDBLCLK
  VirtualEvent      OnLButtonDown,      WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,        WM_LBUTTONUP
  VirtualEvent      OnMButtonDblClk,    WM_MBUTTONDBLCLK
  VirtualEvent      OnMButtonDown,      WM_MBUTTONDOWN
  VirtualEvent      OnMButtonUp,        WM_MBUTTONUP
  VirtualEvent      OnRButtonDblClk,    WM_RBUTTONDBLCLK
  VirtualEvent      OnRButtonDown,      WM_RBUTTONDOWN
  VirtualEvent      OnRButtonUp,        WM_RBUTTONUP
  VirtualEvent      OnPaint,            WM_PAINT
  VirtualEvent      OnPrintClient,      WM_PRINTCLIENT
  VirtualEvent      OnSize,             WM_SIZE
  VirtualEvent      OnHScroll,          WM_HSCROLL
  VirtualEvent      OnVScroll,          WM_VSCROLL
  VirtualEvent      OnKillFocus,        WM_KILLFOCUS
  VirtualEvent      OnSetFocus,         WM_SETFOCUS
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnSetFont,          WM_SETFONT
  VirtualEvent      OnGetFont,          WM_GETFONT
  VirtualEvent      OnEnable,           WM_ENABLE
  VirtualEvent      OnNcDestroy,        WM_NCDESTROY
  VirtualEvent      OnGetDlgCode,       WM_GETDLGCODE
  VirtualEvent      OnSetRedraw,        WM_SETREDRAW

  DefineVariable    dState,             DWORD,              XTVS_VISIBLE
  DefineVariable    dFlags,             DWORD,              XTV_FLAGS
  DefineVariable    pFirstVisibleNode,  $ObjPtr(XTreeViewNode),  NULL
  DefineVariable    pSelectedNode,      $ObjPtr(XTreeViewNode),  NULL
  DefineVariable    dFirstOffset,       DWORD,              0
  DefineVariable    ClientSize,         POINT,              {0,0}   ;Area without both scrollbars
  DefineVariable    DrawSize,           POINT,              {0,0}   ;Area including both scrollbars
  DefineVariable    ScrollbarMetric,    POINT,              {0,0}   ;Width and height of scrollbars
  DefineVariable    ClientOffset,       POINT,              {2,2}
  DefineVariable    TotalSize,          POINT,              {0,0}
  DefineVariable    TotalOffset,        POINT,              {0,0}
  DefineVariable    dTogglerSize,       DWORD,              XTV_TOGGLER_SIZE
  DefineVariable    dNodeIndent,        DWORD,              20      ;Fix size
  DefineVariable    hMemDC,             HDC,                0       ;Back DC
  DefineVariable    hBmpPrv,            HBITMAP,            0
  DefineVariable    hBackBuffer,        HBITMAP,            0
  DefineVariable    dColorLine,         DWORD,              $RGB(192,192,192)
  DefineVariable    dColorToggler,      DWORD,              $RGB(0,0,0)
  DefineVariable    dColorBackground,   DWORD,              $RGB(255,255,255)
  DefineVariable    hFontText,          HFONT,              0
  DefineVariable    hPenLine,           HPEN,               0
  DefineVariable    hPenToggler,        HPEN,               0
  DefineVariable    ArrowScrollValue,   POINT,              {1,1}
  DefineVariable    pFirstChild,        $ObjPtr(XTreeViewNode),  NULL    ;-> First child node
  DefineVariable    pLastChild,         $ObjPtr(XTreeViewNode),  NULL    ;-> Last child node
  DefineVariable    pHotTrackedNode,    $ObjPtr(XTreeViewNode),  NULL    ;-> Last hot tracked node
  DefineVariable    dDispInfoSize,      DWORD,              sizeof XTVN_DISP_INFO
  DefineVariable    hCursorArrow,       HCURSOR,            0       ;Arrow
  DefineVariable    hCursorNo,          HCURSOR,            0       ;Slashed circle
  DefineVariable    hCursorNode,        HCURSOR,            0       ;Arrow with rectangle
  DefineVariable    hCursorFirst,       HCURSOR,            0
  DefineVariable    hCursorLast,        HCURSOR,            0
  DefineVariable    hCursorPrev,        HCURSOR,            0
  DefineVariable    hCursorNext,        HCURSOR,            0
  DefineVariable    dScrollActivation,  DWORD,              XTV_SCROLL_ACTIVATION
  DefineVariable    dDragMouseButton,   DWORD,              0
;  DefineVariable    LogFontText,        LOGFONT,            {0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, \
;                                                            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, \
;                                                            DEFAULT_PITCH or FF_DONTCARE, {"A","R","I","A","L",0}}

  Embed   DispInfoColl,   XWCollection   ;XTVN_DISP_INFO structure collection of nodes in view
  Embed   DispInfoPool,   DataPool       ;Storage for the XTVN_DISP_INFO structures

ObjectEnd



; ==================================================================================================
;     Macros
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macro:      XTV_BrowseBack
; Purpose:    Browse the TreeView back like pressing the up key.
; Arguments:  Arg1: -> starting node. Must be a register!
; Return:     pNode -> previous node or NULL.
; Note:       No other registers are used.

XTV_BrowseBack macro pNode:req
  .if [pNode].$Obj(XTreeViewNode).pPrevSibling == NULL
    mov pNode, [pNode].$Obj(XTreeViewNode).pParent
  .else
    mov pNode, [pNode].$Obj(XTreeViewNode).pPrevSibling
    .while XTV_IsExpanded(pNode)
      mov pNode, [pNode].$Obj(XTreeViewNode).pLastChild
    .endw
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_BrowseFrwd
; Purpose:    Browse the TreeView forward like pressing the down key.
; Arguments:  Arg1: -> starting node. Must be a register!
; Return:     pNode -> next node or NULL.
; Note:       No other registers are used.

XTV_BrowseFrwd macro pNode:req
  .if XTV_IsExpanded(pNode)
    mov pNode, [pNode].$Obj(XTreeViewNode).pFirstChild
  .else
    .repeat
      .if [pNode].$Obj(XTreeViewNode).pNextSibling == NULL
        mov pNode, [pNode].$Obj(XTreeViewNode).pParent
      .else
        mov pNode, [pNode].$Obj(XTreeViewNode).pNextSibling
        .break
      .endif
    .until pNode == NULL
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_SimulateMouseMove
; Purpose:    Simulate a mouse movement.
; Arguments:  Arg1: initial value for the return value.
;             Arg2: List of keys to be tested for.

XTV_SimulateMouseMove macro InitialValue:req, Args:vararg
  ifidn <InitialValue>, <0>
    xor ebx, ebx
  else
    mov ebx, MK_&InitialValue&
  endif
  for Arg, <Args>
    .if $invoke(GetAsyncKeyState, VK_&Arg&) != 0
      or ebx, MK_&Arg&
    .endif
  endm
  invoke GetCursorPos, addr CursorPos
  invoke ScreenToClient, [xsi].hWnd, addr CursorPos
  mov eax, CursorPos.y
  shl eax, 16
  mov ecx, CursorPos.x
  mov ax, cx
  OCall xsi.OnMouseMove, xbx, xax
  xor eax, eax                                          ;;Method return value
  ExitMethod                                            ;;Exit the metod here
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_GetBottomViewNode
; Purpose:    Return the node at the bottom of the view. If we don't reach the bottom of the view,
;             it returns NULL in the return register and in the optional register the last node.
; Arguments:  Arg1: XTreeView regiter pointer.
;             Arg2: return register.
;             Arg3: auxiliar register. Will be trashed.
;             Arg4: (optional) Last node.
; Return:     return register -> bottom node or NULL.

XTV_GetBottomViewNode macro pXTVReg:req, RetReg:req, AuxReg32:req, LastNode:=<>
  mov RetReg, [pXTVReg].pFirstVisibleNode
  mov AuxReg32, [RetReg].$Obj(XTreeViewNode).dHeight
  sub AuxReg32, [pXTVReg].dFirstOffset
  .while AuxReg32 <= [pXTVReg].ClientSize.y
    ifdef LastNode
      mov LastNode, RetReg
    endif
    XTV_BrowseFrwd RetReg
    .break .if RetReg == NULL
    add AuxReg32, [RetReg].$Obj(XTreeViewNode).dHeight
  .endw
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_GetBranchMaxWidth
; Purpose:    Return the width of a tree branch
; Arguments:  Arg1: first node in branch.
;             Arg2: -> XTreeView.
; Return:     ebx = width.

XTV_GetBranchMaxWidth macro pStartNode:req, pXTV:req    ;;-> first node in branch,-> XTreeView
  mov xax, pStartNode
  xor ebx, ebx                                          ;;ebx = max width
  .while xax != NULL
    ;Calc the max width
    mov ecx, [xax].$Obj(XTreeViewNode).dWidth
    uMaxi ebx, ecx, edx                                 ;;Trash ecx and edx
    .if XTV_IsExpanded(xax)
      mov ecx, [xax].$Obj(XTreeViewNode).dBranchWidth
      if (opattr pXTV) and OAT_REGISTER                 ;;Is pXTV a register?
        add ecx, [pXTV].dNodeIndent
      else
        mov xdx, pXTV
        add ecx, [xdx].$Obj(XTreeView).dNodeIndent
      endif
      uMaxi ebx, ecx, edx                               ;;Trash ecx and edx
    .endif
    mov xax, [xax].$Obj(XTreeViewNode).pNextSibling
  .endw
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_IsCollapsed
; Purpose:    Expression to check if a node is collapsed.
; Arguments:  Arg1: -> Node. Must be a register!
; Return:     Expression to be used in an .if directive.

XTV_IsCollapsed macro pNode:req
  exitm <([pNode].$Obj(XTreeViewNode).pFirstChild !!= NULL) && \
         !!([pNode].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_IsExpanded
; Purpose:    Expression to check if a node is expanded.
; Arguments:  Arg1: -> Node. Must be a register!
; Return:     Expression to be used in an .if directive.

XTV_IsExpanded macro pNode:req
  exitm <([pNode].$Obj(XTreeViewNode).pFirstChild !!= NULL) && \
         ([pNode].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      XTV_IsPointInRect
; Purpose:    Expression to check if a point is contained in a rectangle.
; Arguments:  Arg1: X coord.
;             Arg2: Y coord.
;             Arg3: RECT struc.
; Return:     Expression to be used in an .if directive.

XTV_IsPointInRect macro XReg:req, YReg:req, Rct:req
  exitm <(SDWORD ptr YReg !>= Rct.top) && \             ;;Check first for y coords
         (SDWORD ptr YReg !< Rct.bottom) && \
         (SDWORD ptr XReg !>= Rct.left) && \            ;;and then for x coords
         (SDWORD ptr XReg !< Rct.right)>
endm


; ==================================================================================================

if IMPLEMENT

CStr cXTV_ClassName,   "XTreeView"
CStr cXTV_CursorArrow, "CURSOR_XTV_ARROW"
CStr cXTV_CursorNo,    "CURSOR_XTV_NO"
CStr cXTV_CursorNode,  "CURSOR_XTV_ARROWNODE"
CStr cXTV_CursorFirst, "CURSOR_XTV_ARROWFIRST"
CStr cXTV_CursorLast,  "CURSOR_XTV_ARROWLAST"
CStr cXTV_CursorPrev,  "CURSOR_XTV_ARROWPREV"
CStr cXTV_CursorNext,  "CURSOR_XTV_ARROWNEXT"

.data

XTV_LogFontText LOGFONT <0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, \
                         OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, \
                         DEFAULT_PITCH or FF_DONTCARE, {"A","R","I","A","L"}>

.code

; ==================================================================================================
;     DispInfoColl
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Method:     DisplayInfoColl.DestroyItem
; Purpose:    Auxiliary procedure. Don't call directly!
; Arguments:  -> Item.
; Return:     Nothing.

Method DisplayInfoColl.DestroyItem,, pItem:POINTER
  SetObject xcx
  mov xdx, [xcx].$Obj(XWCollection).pOwner
  OCall [xdx].$Obj(XTreeView).DispInfoPool::DataPool.FreeItem, pItem
MethodEnd

;##/


; ==================================================================================================
;     XTreeViewNode
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.CanDragMe
; Purpose:    Indicate if a drag operation can be started.
; Arguments:  Arg1: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = Always FALSE => no dragging allowed.

Method XTreeViewNode.CanDragMe,, dKeyFlags:DWORD
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.CanDropHere
; Purpose:    Inform how the node on arg1 can be inserted when dropped. Standard behaviour.
; Arguments:  Arg1: -> Node to be dropped.
;             Arg2: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
;             Arg3: Cursor position.
; Return:     eax =   0 : drop not allowed (XTVN_INSERT_NOT_ALLOWED).
;                     1 : drop as first child of reference node (XTVN_INSERT_AS_FIRST_CHILD).
;                     2 : drop as last child of reference node (XTVN_INSERT_AS_LAST_CHILD).
;                     3 : drop before reference sibling node (XTVN_INSERT_AS_PREV_SIBLING).
;                     4 : drop behind reference sibling node (XTVN_INSERT_AS_NEXT_SIBLING).

Method XTreeViewNode.CanDropHere, uses xsi, pNode:$ObjPtr(XTreeViewNode), dKeyFlags:DWORD, \
                                            dCursorPos:DWORD
  local CursorPos:POINT

  SetObject xsi
  ;Verify if this object isn't a child of pNode
  mov xcx, xsi
  .repeat
    mov xcx, [xcx].$Obj(XTreeViewNode).pParent
  .until (xcx == NULL) || (xcx == pNode)

  .if xcx == pNode
    mov eax, XTVN_INSERT_NOT_ALLOWED
  .else
    PntS2Pnt CursorPos, dCursorPos
    OCall [xsi].pOwner::XTreeView.GetDispInfo, xsi
    .if xax != NULL
      mov ecx, [xax].XTVN_DISP_INFO.sdNodeTop
      add ecx, [xax].XTVN_DISP_INFO.sdNodeBot
      shr ecx, 1
      mov xax, pNode
      .ifBitSet dKeyFlags, MK_CONTROL
        .if SDWORD ptr ecx > CursorPos.y
          .if xsi != [xax].$Obj(XTreeViewNode).pNextSibling
            mov eax, XTVN_INSERT_AS_PREV_SIBLING
          .elseif xsi != [xax].$Obj(XTreeViewNode).pPrevSibling
            mov eax, XTVN_INSERT_AS_NEXT_SIBLING
          .else
            mov eax, XTVN_INSERT_NOT_ALLOWED
          .endif
        .else
          .if xsi != [xax].$Obj(XTreeViewNode).pPrevSibling
            mov eax, XTVN_INSERT_AS_NEXT_SIBLING
          .elseif xsi != [xax].$Obj(XTreeViewNode).pNextSibling
            mov eax, XTVN_INSERT_AS_PREV_SIBLING
          .else
            mov eax, XTVN_INSERT_NOT_ALLOWED
          .endif
        .endif
      .else
        .if SDWORD ptr ecx > CursorPos.y
          .if xax != [xsi].pFirstChild
            mov eax, XTVN_INSERT_AS_FIRST_CHILD
          .elseif xax != [xsi].pLastChild
            mov eax, XTVN_INSERT_AS_LAST_CHILD
          .else
            mov eax, XTVN_INSERT_NOT_ALLOWED
          .endif
        .else
          .if [xsi].pLastChild == NULL
            mov eax, XTVN_INSERT_AS_FIRST_CHILD
          .elseif xax != [xsi].pLastChild
            mov eax, XTVN_INSERT_AS_LAST_CHILD
          .elseif xax != [xsi].pFirstChild
            mov eax, XTVN_INSERT_AS_FIRST_CHILD
          .else
            mov eax, XTVN_INSERT_NOT_ALLOWED
          .endif
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.ContextPopup
; Purpose:    Placeholder for a context popup menu.
; Arguments:  Arg1: X coord in screen coords.
;             Arg2: Y coord in screen coords.
; Return:     Nothing.

Method XTreeViewNode.ContextPopup,, dXPos:DWORD, dYPos:DWORD
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.Done
; Purpose:    Finalize the XTreeViewNode object and all childs in its branch.
; Arguments:  None.
; Return:     Nothing.

Method XTreeViewNode.Done, uses xbx xsi
;  DbgText "XTreeViewNode.Done"
  SetObject xsi
  ;Destroy all child nodes
  mov xax, [xsi].pFirstChild
  .while xax != NULL
    mov xbx, [xax].$Obj(XTreeViewNode).pNextSibling
    Kill xax
    mov xax, xbx
  .endw
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.Init
; Purpose:    Initialize a XTreeViewNode object.
; Arguments:  Arg1: -> Owner object, XTreeView.
;             Arg2: Node width.
;             Arg3: Node height.
;             Arg4: Node state (XTVNS_DISABLED, XTVNS_EXPANDED, etc.).
; Return:     Nothing.

Method XTreeViewNode.Init, uses xsi, pOwner:POINTER, dWidth:DWORD, dHeight:DWORD, dState:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].dWidth, dWidth, eax
  m2m [xsi].dHeight, dHeight, ecx
  m2m [xsi].dState, dState, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.MouseHit
; Purpose:    Check if the mouse has clicked a hotspot and perform an action.
; Arguments:  Arg1: button that triggered this action.
;             Arg2: -> clicked point.
;             Arg3: -> XTVN_DISP_INFO.
;             Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = TRUE if and action was triggered, otherwise FALSE.

Method XTreeViewNode.MouseHit, uses xbx xdi xsi, dButton:DWORD, pPoint:PPOINT, \
                                                 pDispInfo:PXTVN_DISP_INFO, dKeyFlags:DWORD
  local CRect:RECT, pSlectedDispInfo:PXTVN_DISP_INFO

;  DbgText "XTreeViewNode.MouseHit"
  .if pDispInfo != NULL
    SetObject xsi
    SetObject xbx, XTreeView, [xsi].pOwner

    ;Check for text hit
    mov xcx, pPoint
    mov xdx, pDispInfo
    assume xdx:PXTVN_DISP_INFO
    mov eax, [xcx].POINT.x
    mov ecx, [xcx].POINT.y
    .if XTV_IsPointInRect(eax, ecx, [xdx].TextRect) && !([xbx].dState & XTVS_DRAGGING)
;      DbgText "Hit on Text"
      .if xsi != [xbx].pSelectedNode
        OCall xbx::XTreeView.GetDispInfo, [xbx].pSelectedNode
        mov xdi, [xbx].pSelectedNode
        mov pSlectedDispInfo, xax
        OCall xbx::XTreeView.Select, xsi
        OCall xsi.RenderContent, pDispInfo
        mov xax, pSlectedDispInfo
        mov xcx, xdi
        .if xax != NULL
          OCall xcx::XTreeViewNode.RenderContent, xax
        .endif
      .endif

      .if !([xbx].dState & \
            (XTVS_DRAGGING or XTVS_DRAGGINGABORTED or XTVS_DRAGGINGSTARTED))
        .if $OCall(xsi.CanDragMe, dKeyFlags)
          BitSet [xbx].dState, XTVS_DRAGGINGSTARTED
          mov eax, dKeyFlags
          and eax, (MK_LBUTTON or MK_MBUTTON or MK_RBUTTON)
          mov [xbx].dDragMouseButton, eax
        .endif
      .endif
      OCall xbx.Draw
      mov eax, TRUE

    ;Check for toggler hit
    .elseif XTV_IsPointInRect(eax, ecx, [xdx].TogglerRect) && \
            !(([xbx].dFlags & XTVF_KEEP_COLLAPSED_ON_DRAG) && \
            (([xbx].dState & XTVS_DRAGGING) && (xsi == [xbx].pSelectedNode)))
;      DbgText "Hit on Toggler"
      OCall xsi::XTreeViewNode.Toggle

      .if XTV_IsExpanded(xsi)

        ;Correct the client area coords
        mov eax, [xbx].TotalSize.x
        .if eax > [xbx].ClientSize.x
          invoke ShowScrollBar, [xbx].hWnd, SB_HORZ, TRUE
          invoke GetClientRect, [xbx].hWnd, addr CRect
          m2m [xbx].ClientSize.x, CRect.right, eax
          m2m [xbx].ClientSize.y, CRect.bottom, ecx
        .endif

        ;Node is now expanded; maybe we have to reposition the tree
        OCall xbx::XTreeView.GetDispInfo, xsi
        mov eax, [xax].XTVN_DISP_INFO.sdNodeTop
        add eax, [xbx].TotalOffset.y

        mov edx, eax
        add edx, [xsi].dHeight
        add edx, [xsi].dBranchHeight
        sub edx, [xbx].ClientSize.y
        sub edx, [xbx].TotalOffset.y
        .if !SIGN?
          mov ecx, eax                                  ;The last branch node is off view
          sub ecx, [xbx].TotalOffset.y
          sub ecx, edx
          .if !SIGN?
            add eax, [xsi].dHeight
            add eax, [xsi].dBranchHeight
            sub eax, [xbx].ClientSize.y
          .endif
          OCall xbx::XTreeView.Find1stVisibleNode, eax
        .endif

      .else
        ;Node is now collapsed; we check if we have a hole at the bottom
        XTV_GetBottomViewNode xbx, xcx, eax, xdx
        .if xcx == NULL
          OCall xbx::XTreeView.MoveInViewBottom, xdx
        .endif
      .endif
      OCall xbx.Draw
      mov eax, TRUE

    .else
      xor eax, eax

    .endif
    assume xdx:NOTHING
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.MouseHitDbl
; Purpose:    Check if the mouse has double clicked a hotspot and perform an action.
; Arguments:  Arg1: Button that triggered this action.
;             Arg2: -> Clicked point.
;             Arg3: -> XTVN_DISP_INFO.
;             Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = TRUE if and action was triggered, otherwise FALSE.

Method XTreeViewNode.MouseHitDbl,, dButton:DWORD, pPoint:PPOINT, \
                                           pDispInfo:PXTVN_DISP_INFO, dKeyFlags:DWORD
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.Render
; Purpose:    Draw the complete node.
; Arguments:  Arg1: -> XTVN_DISP_INFO.
; Return:     Nothing.

Method XTreeViewNode.Render, uses xsi, pDispInfo:PXTVN_DISP_INFO
;  DbgText "XTreeViewNode.Render"
  SetObject xsi
  .if ([xsi].dHeight != 0) || ([xsi].dWidth != 0)     ;Don't draw nodes with height and width = 0
    mov xdx, [xsi].pOwner

    ;Calc the total indentation of this node
    mov xcx, [xsi].pParent
    mov eax, [xdx].$Obj(XTreeView).ClientOffset.x
    mov xdx, [xsi].pOwner
    sub eax, [xdx].$Obj(XTreeView).TotalOffset.x
    add eax, [xdx].$Obj(XTreeView).dNodeIndent

    .while xcx != NULL
      mov xcx, [xcx].$Obj(XTreeViewNode).pParent
      add eax, [xdx].$Obj(XTreeView).dNodeIndent
    .endw

    ;Fill XTVN_DISP_INFO.ContentRect info
    mov xcx, pDispInfo
    mov [xcx].XTVN_DISP_INFO.ContentRect.left, eax
    add eax, [xsi].dWidth
    mov [xcx].XTVN_DISP_INFO.ContentRect.right, eax
    m2m [xcx].XTVN_DISP_INFO.ContentRect.top, [xcx].XTVN_DISP_INFO.sdNodeTop, eax
    m2m [xcx].XTVN_DISP_INFO.ContentRect.bottom, [xcx].XTVN_DISP_INFO.sdNodeBot, edx

;    if DEBUGGING
;    .if SDWORD ptr [xcx].XTVN_DISP_INFO.ContentRect.bottom < 0
;      DbgWarning "Error while positioning the view"
;    .endif
;    endif

    ;Render the tree structure (lines and toggler)
    OCall xsi.RenderTreeStruc, pDispInfo

    ;Render the content of the node
    OCall xsi.RenderContent, pDispInfo

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.RenderContent
; Purpose:    Draw the content of the node.
; Arguments:  Arg1: -> XTVN_DISP_INFO structure. If NULL, no action is performed.
; Return:     Nothing.
; Note:       This method must update the coords of all RECT structures in the Content and must
;             invalidate the modified region.

Method XTreeViewNode.RenderContent, uses xbx xdi xsi, pDispInfo:PXTVN_DISP_INFO
    local InvRect:RECT, pPrevDC:POINTER

;    DbgText "XTreeViewNode.RenderContent"
    mov xdi, pDispInfo
    .if xdi != NULL
      SetObject xsi
      SetObject xbx, XTreeView, [xsi].pOwner
      assume xdi:PXTVN_DISP_INFO

      ;Get the drawing rect
      m2m InvRect.left, [xdi].ContentRect.left, eax
      m2m InvRect.top, [xdi].sdNodeTop, ecx
      m2m InvRect.right, [xbx].ClientSize.x, eax            ;Invalidate up to the end of the view
      m2m InvRect.bottom, [xdi].sdNodeBot, ecx

      ;Clear the background
      m2m [xdi].TextRect.left, [xdi].ContentRect.left, eax
      m2m [xdi].TextRect.right, [xdi].ContentRect.right, ecx
      m2m [xdi].TextRect.top, [xdi].ContentRect.top, eax
      m2m [xdi].TextRect.bottom, [xdi].ContentRect.bottom, ecx

      OCall xbx::XTreeView.RenderBackground, addr InvRect

      ;Draw a hatched rectangle to visualize the ContentRect
      .if xsi == [xbx].pSelectedNode
        invoke CreateHatchBrush, HS_DIAGCROSS, $RGB(0,0,255)
      .else
        invoke CreateHatchBrush, HS_BDIAGONAL, $RGB(0,0,0)
      .endif
      mov pPrevDC, $invoke(SelectObject, [xbx].hMemDC, xax)
      invoke Rectangle, [xbx].hMemDC, \
                        [xdi].ContentRect.left, [xdi].ContentRect.top, \
                        [xdi].ContentRect.right, [xdi].ContentRect.bottom
      invoke SelectObject, [xbx].hMemDC, pPrevDC
      invoke DeleteObject, xax

      ;Invalidate the new drawn rect
      invoke InvalidateRect, [xbx].hWnd, addr InvRect, FALSE
      assume xdi:NOTHING
    .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.RenderText
; Purpose:    Draw the text content of the node.
; Arguments:  Arg1: -> XTVN_DISP_INFO. If NULL, no action is performed.
;             Arg2: -> Text.
; Return:     Nothing.
; Note:       This method centers the TextRect verticaly to ContentRect.
;             The TextRect horizontal position is not changed.

Method XTreeViewNode.RenderText, uses xbx xdi xsi, pDispInfo:PXTVN_DISP_INFO, pText:PSTRING
;  DbgText "XTreeViewNode.RenderText"
  mov xbx, pDispInfo
  .if xbx != NULL
    SetObject xsi
    SetObject xdi, XTreeView, [xsi].pOwner
    ReleaseObject xsi
    assume xbx:PXTVN_DISP_INFO
    m2z [xbx].TextRect.top

    invoke DrawText, [xdi].hMemDC, pText , -1, addr [xbx].TextRect, \
                 DT_SINGLELINE or DT_LEFT or DT_CALCRECT

    mov ecx, [xbx].ContentRect.bottom
    sub ecx, [xbx].ContentRect.top
    sub ecx, eax                                        ;eax = text height
    shr ecx, 1
    add ecx, [xbx].ContentRect.top
    mov [xbx].TextRect.top, ecx
    add ecx, eax
    mov [xbx].TextRect.bottom, ecx
    mov esi, [xbx].TextRect.right                       ;Save right coord

    ;Set max right size to draw the elipsis
    m2m [xbx].TextRect.right, [xdi].ClientSize.x, eax
    invoke DrawText, [xdi].hMemDC, pText , -1, addr [xbx].TextRect, \
                     DT_SINGLELINE or DT_LEFT or DT_VCENTER or DT_END_ELLIPSIS

    mov [xbx].TextRect.right, esi                       ;Restore right coord
    assume xbx:NOTHING
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.RenderTreeStruc
; Purpose:    Draw the connection lines and toggler boxes ([+] or [-]).
; Arguments:  Arg1: -> XTVN_DISP_INFO. If NULL, no action is performed.
; Return:     Nothing.
; Note:       This method updates the coords of the TogglerRect structure.

Method XTreeViewNode.RenderTreeStruc, uses xbx xdi xsi, pDispInfo:PXTVN_DISP_INFO
  local Center:POINT, hPenPrev:HPEN, InvRect:RECT

  mov xbx, pDispInfo
  .if xbx != NULL
    SetObject xsi
    SetObject xdi, XTreeView, [xsi].pOwner
    assume xbx:PXTVN_DISP_INFO

    ;Get the drawing rect
    m2z InvRect.left
    m2m InvRect.top, [xbx].sdNodeTop, eax
    m2m InvRect.right, [xbx].ContentRect.left, ecx
    m2m InvRect.bottom, [xbx].sdNodeBot, eax

    ;Clear background
    OCall xdi::XTreeView.RenderBackground, addr InvRect

    ;Calc the center of the toggler box. It is vertically aligned with the ContentRect
    mov eax, [xbx].ContentRect.bottom
    sub eax, [xbx].ContentRect.top
    shr eax, 1
    add eax, [xbx].ContentRect.top
    mov Center.y, eax
    mov ecx, [xbx].ContentRect.left
    mov edx, [xdi].dNodeIndent
    shr edx, 1
    sbb ecx, edx
    mov Center.x, ecx

    .if ([xsi].pFirstChild == NULL) || !([xdi].dFlags & XTVF_SHOW_TOGGLER)  ;No child nodes?
      .ifBitSet [xdi].dFlags, XTVF_SHOW_LINES
        ;Check if the node is the top parent node
        mov hPenPrev, $invoke(SelectObject, [xdi].hMemDC, [xdi].hPenLine)
        .if [xsi].pParent == NULL && [xsi].pPrevSibling == NULL
          mov eax, Center.y
        .else
          mov eax, [xbx].sdNodeTop
        .endif
        ;Draw the connection lines
        invoke MoveToEx, [xdi].hMemDC, Center.x, eax, NULL
        .if [xsi].pNextSibling == NULL                ;Is it an ending node?
          ;Last node
          invoke LineTo, [xdi].hMemDC, Center.x, Center.y
        .else
          ;Any other node
          invoke LineTo, [xdi].hMemDC, Center.x, [xbx].sdNodeBot
          invoke MoveToEx, [xdi].hMemDC, Center.x, Center.y, NULL
        .endif
        invoke LineTo, [xdi].hMemDC, [xbx].ContentRect.left, Center.y
        invoke MemZero, addr [xbx].TogglerRect, sizeof RECT
        invoke SelectObject, [xdi].hMemDC, hPenPrev
      .endif
    .else
      ;Calc the rect of the toggler
      mov ecx, [xbx].ContentRect.left
      mov eax, [xdi].dTogglerSize
      add eax, [xdi].dNodeIndent
      shr eax, 1
      sub ecx, eax
      mov [xbx].TogglerRect.left, ecx
      add ecx, [xdi].dTogglerSize
      mov [xbx].TogglerRect.right, ecx

      mov eax, [xbx].ContentRect.bottom
      sub eax, [xbx].ContentRect.top
      sub eax, [xdi].dTogglerSize
      shr eax, 1
      mov ecx, [xbx].ContentRect.bottom
      sub ecx, eax
      mov [xbx].TogglerRect.bottom, ecx
      sub ecx, [xdi].dTogglerSize
      mov [xbx].TogglerRect.top, ecx

      ;Draw the toggler rectangle
      mov hPenPrev, $invoke(SelectObject, [xdi].hMemDC, [xdi].hPenToggler)
      invoke Rectangle, [xdi].hMemDC, \
                        [xbx].TogglerRect.left, [xbx].TogglerRect.top, \
                        [xbx].TogglerRect.right, [xbx].TogglerRect.bottom

      ;Draw the content of the toggler [+] or [-]
      mov eax, [xbx].TogglerRect.left
      add eax, 2
      ;Draw horizontal line of a minus sign
      invoke MoveToEx, [xdi].hMemDC, eax, Center.y, NULL
      mov eax, [xbx].TogglerRect.right
      sub eax, 2
      invoke LineTo, [xdi].hMemDC, eax, Center.y
      .ifBitClr [xsi].dState, XTVNS_EXPANDED
        ;Make a plus
        mov eax, [xbx].TogglerRect.top
        add eax, 2
        invoke MoveToEx, [xdi].hMemDC, Center.x, eax, NULL
        mov eax, [xbx].TogglerRect.bottom
        sub eax, 2
        invoke LineTo, [xdi].hMemDC, Center.x, eax
      .endif
      invoke SelectObject, [xdi].hMemDC, hPenPrev

      ;Draw the toggler connection lines
      .ifBitSet [xdi].dFlags, XTVF_SHOW_LINES
        mov hPenPrev, $invoke(SelectObject, [xdi].hMemDC, [xdi].hPenLine)
        ;Check if the node is the top parent node
        .if [xsi].pParent == NULL && [xsi].pPrevSibling == NULL
          mov eax, [xbx].TogglerRect.top
        .else
          mov eax, [xbx].sdNodeTop
        .endif
        invoke MoveToEx, [xdi].hMemDC, Center.x, eax, NULL
        invoke LineTo, [xdi].hMemDC, Center.x, [xbx].TogglerRect.top
        invoke MoveToEx, [xdi].hMemDC, [xbx].TogglerRect.right, Center.y, NULL
        invoke LineTo, [xdi].hMemDC, [xbx].ContentRect.left, Center.y
        .if [xsi].pNextSibling != NULL                ;Is it not an ending node?
          invoke MoveToEx, [xdi].hMemDC, Center.x, [xbx].TogglerRect.bottom, NULL
          invoke LineTo, [xdi].hMemDC, Center.x, [xbx].sdNodeBot
        .endif
        invoke SelectObject, [xdi].hMemDC, hPenPrev
      .endif
    .endif

    ;Draw vertical parent connection lines
    .ifBitSet [xdi].dFlags, XTVF_SHOW_LINES
      mov hPenPrev, $invoke(SelectObject, [xdi].hMemDC, [xdi].hPenLine)
      .while TRUE

        mov xsi, [xsi].pParent
        .break .if xsi == NULL
        mov eax, [xdi].dNodeIndent
        sub Center.x, eax
        .if [xsi].pNextSibling != NULL
          invoke MoveToEx, [xdi].hMemDC, Center.x, [xbx].sdNodeTop, NULL
          invoke LineTo, [xdi].hMemDC, Center.x, [xbx].sdNodeBot
        .endif
      .endw
      invoke SelectObject, [xdi].hMemDC, hPenPrev
    .endif

    ;Invalidate the redrawn rect
    invoke InvalidateRect, [xdi].hWnd, addr InvRect, FALSE

    assume xbx:NOTHING
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeViewNode.Toggle
; Purpose:    Expand or collapses this node.
; Arguments:  None.
; Return:     Nothing.

Method XTreeViewNode.Toggle, uses xbx xdi xsi
;  DbgText "XTreeViewNode.Toggle"
  SetObject xsi
  .ifBitSet [xsi].dState, XTVNS_EXPANDED
    ;Collapse the branch

    BitClr [xsi].dState, XTVNS_EXPANDED               ;Reverse it

    ;Manage node selection: if a leave is selected, select this node
    .ifBitSet [xsi].dState, XTVNS_SEL_PATH
      mov xax, [xsi].pOwner
      .ifBitClr [xax].$Obj(XTreeView).dState, XTVS_DRAGGING
        OCall [xsi].pOwner::XTreeView.Select, xsi
      .endif
    .endif

    ;Calc new branch values in the modified path
    mov xdi, [xsi].pParent
    .while (xdi != NULL) && ([xdi].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)

      mov eax, [xsi].dBranchHeight
      sub [xdi].$Obj(XTreeViewNode).dBranchHeight, eax

      XTV_GetBranchMaxWidth [xdi].$Obj(XTreeViewNode).pFirstChild, [xsi].pOwner
      mov [xdi].$Obj(XTreeViewNode).dBranchWidth, ebx

      mov xdi, [xdi].$Obj(XTreeViewNode).pParent            ;Move one level up
    .endw

    .if xdi == NULL                                   ;Did we reach the root node?
      mov eax, [xsi].dBranchHeight
      mov xdi, [xsi].pOwner
      sub [xdi].$Obj(XTreeView).TotalSize.y, eax

      XTV_GetBranchMaxWidth [xdi].$Obj(XTreeView).pFirstChild, [xsi].pOwner
      add ebx, [xdi].$Obj(XTreeView).dNodeIndent
      add ebx, [xdi].$Obj(XTreeView).ClientOffset.x
      mov [xdi].$Obj(XTreeView).TotalSize.x, ebx
    .endif

  .else
    ;Expand the branch
    BitSet [xsi].dState, XTVNS_EXPANDED               ;Reverse it

    ;Calc new sizes
    mov xdi, [xsi].pParent
    .while (xdi != NULL) && ([xdi].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)
      mov eax, [xsi].dBranchHeight
      add [xdi].$Obj(XTreeViewNode).dBranchHeight, eax

      XTV_GetBranchMaxWidth [xdi].$Obj(XTreeViewNode).pFirstChild, [xsi].pOwner
      mov [xdi].$Obj(XTreeViewNode).dBranchWidth, ebx

      mov xdi, [xdi].$Obj(XTreeViewNode).pParent
    .endw
    .if xdi == NULL                                   ;Did we reach the root node?
      mov eax, [xsi].dBranchHeight
      mov xdi, [xsi].pOwner
      add [xdi].$Obj(XTreeView).TotalSize.y, eax

      XTV_GetBranchMaxWidth [xdi].$Obj(XTreeView).pFirstChild, [xsi].pOwner
      add ebx, [xdi].$Obj(XTreeView).dNodeIndent
      add ebx, [xdi].$Obj(XTreeView).ClientOffset.x
      mov [xdi].$Obj(XTreeView).TotalSize.x, ebx
    .endif

  .endif
MethodEnd

;##/


; ==================================================================================================
;     XTreeView
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Procedure:  XTV_IsPointInContent
; Purpose:    Check if a point is contained in the ContentRect.
; Arguments:  Arg1: -> XTVN_DISP_INFO structure.
;             Arg2: X position in client coords.
;             Arg3: Y position in client coords.
; Return:     eax = TRUE / FALSE.

XTV_IsPointInContent proc pDispInfo:PXTVN_DISP_INFO, dPosX:DWORD, dPosY:DWORD
  mov xcx, pDispInfo
  assume xcx:PXTVN_DISP_INFO
  mov edx, dPosX
  xor eax, eax
  .if (SDWORD ptr edx >= [xcx].ContentRect.left) && (SDWORD ptr edx < [xcx].ContentRect.right)
    mov edx, dPosY
    .if (SDWORD ptr edx >= [xcx].ContentRect.top) && (SDWORD ptr edx < [xcx].ContentRect.bottom)
      inc eax
    .endif
  .endif
  assume xcx:NOTHING
  ret
XTV_IsPointInContent endp

; --------------------------------------------------------------------------------------------------
; Procedure:  XTV_IsPointInNode
; Purpose:    Check if a point is contained in the node band.
; Arguments:  Arg1: -> XTVN_DISP_INFO structure.
;             Arg2: Y position in client coords.
; Return:     eax = TRUE / FALSE.

XTV_IsPointInNode proc pDispInfo:PXTVN_DISP_INFO, dPosY:DWORD
  mov xcx, pDispInfo
  assume xcx:PXTVN_DISP_INFO
  mov edx, dPosY
  xor eax, eax
  .if (SDWORD ptr edx >= [xcx].sdNodeTop) && (SDWORD ptr edx < [xcx].sdNodeBot)
    inc eax
  .endif
  assume xcx:NOTHING
  ret
XTV_IsPointInNode endp

; --------------------------------------------------------------------------------------------------
; Procedure:  XTV_IsPointInText
; Purpose:    Check if a point is contained in the TextRect.
; Arguments:  Arg1: -> XTVN_DISP_INFO structure.
;             Arg2: X position in client coords.
;             Arg3: Y position in client coords.
; Return:     eax = TRUE / FALSE.

XTV_IsPointInText proc pDispInfo:PXTVN_DISP_INFO, dPosX:DWORD, dPosY:DWORD
  mov xcx, pDispInfo
  assume xcx:PXTVN_DISP_INFO
  mov edx, dPosX
  xor eax, eax
  .if (SDWORD ptr edx >= [xcx].TextRect.left) && (SDWORD ptr edx < [xcx].TextRect.right)
    mov edx, dPosY
    .if (SDWORD ptr edx >= [xcx].TextRect.top) && (SDWORD ptr edx < [xcx].TextRect.bottom)
      inc eax
    .endif
  .endif
  assume xcx:NOTHING
  ret
XTV_IsPointInText endp

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.CanDropHere
; Purpose:    Inform how the node on arg1 can be dropped. Std behaviour.
; Arguments:  Arg1: -> Node.
;             Arg2: Key flags.
;             Arg3: Cursor position.
; Return:     eax =  0 : drop not allowed (XTVN_INSERT_NOT_ALLOWED).
;                    1 : drop as first child of reference node (XTVN_INSERT_AS_FIRST_CHILD).
;                    2 : drop as last child of reference node (XTVN_INSERT_AS_LAST_CHILD).
;                    3 : drop before reference sibling node (XTVN_INSERT_AS_PREV_SIBLING).
;                    4 : drop behind reference sibling node (XTVN_INSERT_AS_NEXT_SIBLING).

Method XTreeView.CanDropHere,, pNode:$ObjPtr(XTreeViewNode), dKeyFlags:DWORD, dCursorPos:DWORD
  local CursorPos:POINT

  SetObject xcx
  PntS2Pnt CursorPos, dCursorPos
  mov edx, CursorPos.y
  mov eax, CursorPos.x
  ;Check if the cursor is inside the client rect
  .if (SDWORD ptr edx >= 0) && \                      ;Check first for y coords
      (SDWORD ptr edx < [xcx].ClientSize.y) && \
      (SDWORD ptr eax >= 0) && \                      ;and then for x coords
      (SDWORD ptr eax < [xcx].ClientSize.x)
    mov edx, [xcx].ClientSize.y
    shr edx, 1
    mov xax, pNode
    .if SDWORD ptr edx > CursorPos.y
      .if xax != [xcx].pFirstChild
        mov eax, XTVN_INSERT_AS_PREV_SIBLING
      .elseif xax != [xcx].pLastChild
        mov eax, XTVN_INSERT_AS_NEXT_SIBLING
      .else
        mov eax, XTVN_INSERT_NOT_ALLOWED
      .endif
    .else
      .if xax != [xcx].pLastChild
        mov eax, XTVN_INSERT_AS_NEXT_SIBLING
      .elseif xax != [xcx].pFirstChild
        mov eax, XTVN_INSERT_AS_PREV_SIBLING
      .else
        mov eax, XTVN_INSERT_NOT_ALLOWED
      .endif
    .endif
  .else
    mov eax, XTVN_INSERT_NOT_ALLOWED
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.CreateBackBuffer
; Purpose:    Create a backbuffer and recalculates the DrawSize structure members.
; Arguments:  None.
; Return:     Nothing.

Method XTreeView.CreateBackBuffer, uses xsi
  local hDC:HDC

  SetObject xsi

  s2s [xsi].DrawSize, [xsi].ClientSize, xax, xcx

  invoke IsScrollBarVisible, [xsi].hWnd, SB_HORZ
  .if eax != FALSE
    mov eax, [xsi].ScrollbarMetric.y
    add [xsi].DrawSize.y, eax
  .endif
  invoke IsScrollBarVisible, [xsi].hWnd, SB_VERT
  .if eax != FALSE
    mov eax, [xsi].ScrollbarMetric.x
    add [xsi].DrawSize.x, eax
  .endif

  mov hDC, $invoke(GetDC, [xsi].hWnd)

  .if [xsi].hBmpPrv != 0
    invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hBmpPrv)
    m2z [xsi].hBackBuffer
    m2z [xsi].hBmpPrv
  .endif
  invoke CreateCompatibleBitmap, hDC, [xsi].DrawSize.x, [xsi].DrawSize.y
  .if xax != 0
    mov [xsi].hBackBuffer, xax
    mov [xsi].hBmpPrv, $invoke(SelectObject, [xsi].hMemDC, [xsi].hBackBuffer)
  .endif

  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.

Method XTreeView.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "XTreeView Messages"
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Dispose
; Purpose:    Remove the node from the XTreeView and destroyes it with all its childs.
; Arguments:  Arg1: -> Node to dispose.
; Return:     Nothing.

Method XTreeView.Dispose, uses xsi, pNode:$ObjPtr(XTreeViewNode)
  SetObject xsi
  .if pNode != NULL
    OCall xsi::XTreeView.Remove, pNode
    Kill pNode
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Done
; Purpose:    Finalize the XTreeView object.
; Arguments:  None.
; Return:     Nothing.

Method XTreeView.Done, uses xbx xsi
;  DbgText "XTreeView.Done"
  SetObject xsi

  ;Destroy all root nodes; child nodes are automatically destroyed!
  mov xax, [xsi].pFirstChild
  .while xax != NULL
    mov xbx, [xax].$Obj(XTreeViewNode).pNextSibling
    Kill xax
    mov xax, xbx
  .endw

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Draw
; Purpose:    Render all nodes in view on the back buffer.
; Arguments:  None.
; Return:     Nothing.

Method XTreeView.Draw, uses xbx xdi xsi
  local ScrollInfo:SCROLLINFO, RemRect:RECT

;  DbgText "XTreeView.Draw"
  SetObject xsi
  .ifBitClr [xsi].dState, XTVS_LOCKED

    ;Some initialization
    OCall [xsi].DispInfoColl::XWCollection.DisposeAll  ;Release all XTVN_DISP_INFO structs

    OCall xsi.ShowScrollbars

    ;Manage the vertical scrollbar
    mov eax, [xsi].TotalSize.y
    .if eax > [xsi].ClientSize.y
      mov ScrollInfo.SCROLLINFO.cbSize, sizeof SCROLLINFO
      mov ScrollInfo.SCROLLINFO.fMask, SIF_POS or SIF_PAGE

      ;Scale the values to fit in a 16 bit range
      xor edx, edx
      mov eax, [xsi].TotalOffset.y
      mov ecx, 0FFFFh
      mul ecx
      div [xsi].TotalSize.y
      mov ScrollInfo.SCROLLINFO.nPos, eax

      mov eax, [xsi].ClientSize.y
      mov ecx, 0FFFFh
      mul ecx
      div [xsi].TotalSize.y
      .if eax == 0
        inc eax
      .endif
      mov ScrollInfo.SCROLLINFO.nPage, eax

      invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, TRUE
    .endif

    ;Manage the horizontal scrollbar
    mov eax, [xsi].TotalSize.x
    .if eax > [xsi].ClientSize.x
      mov ScrollInfo.SCROLLINFO.cbSize, sizeof SCROLLINFO
      mov ScrollInfo.SCROLLINFO.fMask, SIF_POS or SIF_PAGE

      ;Scale the values to fit in a 16 bit range
      xor edx, edx
      mov eax, [xsi].TotalOffset.x
      mov ecx, 0FFFFh
      mul ecx
      div [xsi].TotalSize.x
      mov ScrollInfo.SCROLLINFO.nPos, eax

      mov eax, [xsi].ClientSize.x
      mov ecx, 0FFFFh
      mul ecx
      div [xsi].TotalSize.x
      .if eax == 0
        inc eax
      .endif
      mov ScrollInfo.SCROLLINFO.nPage, eax

      invoke SetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo, TRUE
    .endif

    ;Draw all nodes in view
    .if [xsi].pFirstVisibleNode == NULL
      OCall xsi.Set1stVisibleNode, [xsi].pFirstChild
      m2z [xsi].TotalOffset.x
      m2z [xsi].TotalOffset.y
    .endif

    mov edi, [xsi].dFirstOffset
    neg edi
    mov xbx, [xsi].pFirstVisibleNode
    .if xbx != NULL
      .repeat
        OCall [xsi].DispInfoPool::DataPool.NewItem
        mov [xax].XTVN_DISP_INFO.pNode, xbx
        mov [xax].XTVN_DISP_INFO.sdNodeTop, edi
        add edi, [xbx].$Obj(XTreeViewNode).dHeight
        mov [xax].XTVN_DISP_INFO.sdNodeBot, edi
        OCall [xsi].DispInfoColl::XWCollection.Insert, xax
        OCall xbx::XTreeViewNode.Render, xax
        XTV_BrowseFrwd xbx
        .break .if xbx == NULL
      .until edi >= [xsi].ClientSize.y
    .endif

    ;Check if there is a gap between the last item and the clientRect bottom
    .if edi < [xsi].ClientSize.y
      ;Fill the bottom remaining background
      m2z RemRect.left
      mov RemRect.top, edi
      s2s POINT ptr RemRect.right, [xsi].ClientSize, xax, xcx
      lea xax, RemRect
      OCall xsi.RenderBackground, xax
    .endif

    invoke InvalidateRect, [xsi].hWnd, NULL, FALSE    ;Invalidate complete client area

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Drop
; Purpose:    Drop a node.
; Arguments:  Arg1: -> Node to drop.
;             Arg2: -> Reference node.
;             Arg3: How to insert when dropped:
;                     - XTVN_INSERT_AS_FIRST_CHILD
;                     - XTVN_INSERT_AS_LAST_CHILD
;                     - XTVN_INSERT_AS_PREV_SIBLING
;                     - XTVN_INSERT_AS_NEXT_SIBLING
; Return:     Nothing.

Method XTreeView.Drop, uses xsi, pNode:$ObjPtr(XTreeViewNode), pRefNode:$ObjPtr(XTreeViewNode), \
                                 dHowToInsert:DWORD
  SetObject xsi
  mov xax, pNode
  .if (xax != NULL) && (xax != pRefNode)

    OCall xsi.Remove, pNode
    OCall xsi.Insert, pNode, pRefNode, dHowToInsert

    .ifBitSet [xsi].dFlags, XTVF_EXPAND_PARENT_ON_DROP
      OCall xsi.Select, pNode
      mov xax, pRefNode
      .if (xax != NULL) && (XTV_IsCollapsed(xax))
        OCall xax::XTreeViewNode.Toggle
      .endif
    .else
      OCall xsi.Select, pRefNode
    .endif

    OCall xsi.GetDispInfo, pNode
    .if xax == NULL                                     ;Not in view
      OCall xsi.MoveInViewBottom, pNode
    .else
      mov edx, [xax].XTVN_DISP_INFO.sdNodeBot
      .if edx >= [xsi].ClientSize.y                     ;Only partially visible
        OCall xsi.MoveInViewBottom, pNode
      .endif
    .endif
    OCall xsi.Draw
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Find1stVisibleNode
; Purpose:    Search for the first visible node in view, starting from the current visible node.
; Arguments:  Arg1: New total offset.
; Return:     Nothing.
;
;                                                        |   ebx              |
;                                                        |                    |
;        |                                              \|/                   | Total Offset
;        |     ------------------------   ----------------・                  |
;        |    |                        |                /|\  First Offset     |
;       [-]---|   First Visible Node   |                 |                   \|/
;   ----------------------------------------------   ----------------------------
;  |           ------------------------           |     /|\
;  |            |     ----------------------      |      |
;  |            |    |                      |     |      |
;  |            |----|                      |     |      |
;  |            |    |                      |     |      |
;  |            |     ----------------------      |      |
;  |            |     --------------------------  |      |
;  |            |    |                          | |      |   Window height
;  |           [+]---|                          | |      |
;  |            |    |                          | |      |
;  |            |     --------------------------  |      |
;  |            |     ----------------------      |      |          The first Visible Node has
;  |            |    |                      |     |      |          at least one part shown in
;  |             ----|                      |     |      |          XTreeView window
;  |                 |                      |     |      |
;  |                  ----------------------      |     \|/
;   ----------------------------------------------    ------・

Method XTreeView.Find1stVisibleNode, uses xbx xsi, dNewTotalOffset:DWORD
  SetObject xsi
  mov eax, dNewTotalOffset
  mov xcx, [xsi].pFirstVisibleNode
  mov ebx, [xsi].TotalOffset.y
  sub ebx, [xsi].dFirstOffset                           ;Check for the top coord of the node

  .if eax < [xsi].TotalOffset.y
    ;We are going up
    .while ebx > dNewTotalOffset
      ;Go for next node
      .if [xcx].$Obj(XTreeViewNode).pPrevSibling != NULL
        mov xcx, [xcx].$Obj(XTreeViewNode).pPrevSibling
        @@:
        .if XTV_IsExpanded(xcx)
          sub ebx, [xcx].$Obj(XTreeViewNode).dBranchHeight
          .if ebx < dNewTotalOffset
            add ebx, [xcx].$Obj(XTreeViewNode).dBranchHeight
            mov xcx, [xcx].$Obj(XTreeViewNode).pLastChild
            jmp @B
          .endif
        .endif
        sub ebx, [xcx].$Obj(XTreeViewNode).dHeight
      .else
        ;Search the upper branch
        mov xax, xcx
        .while TRUE
          .if [xax].$Obj(XTreeViewNode).pParent == NULL
            jmp @@Found                                 ;Stop here
          .else
            mov xcx, [xax].$Obj(XTreeViewNode).pParent
            sub ebx, [xcx].$Obj(XTreeViewNode).dHeight
            .break
          .endif
        .endw
      .endif
    .endw

  .else
    ;We are going down
    add ebx, [xcx].$Obj(XTreeViewNode).dHeight          ;Check for the bottom coord of the node

    .while ebx < dNewTotalOffset
      .if XTV_IsExpanded(xcx)
        add ebx, [xcx].$Obj(XTreeViewNode).dBranchHeight
        .if ebx > dNewTotalOffset
          sub ebx, [xcx].$Obj(XTreeViewNode).dBranchHeight
          mov xcx, [xcx].$Obj(XTreeViewNode).pFirstChild
          add ebx, [xcx].$Obj(XTreeViewNode).dHeight
          .continue
        .endif
      .endif

      ;Go for next node
      .if [xcx].$Obj(XTreeViewNode).pNextSibling != NULL
        mov xcx, [xcx].$Obj(XTreeViewNode).pNextSibling
        add ebx, [xcx].$Obj(XTreeViewNode).dHeight
      .else
        ;Search the upper branch
        mov xax, xcx
        .while TRUE
          .if [xax].$Obj(XTreeViewNode).pParent == NULL
            jmp @F                                    ;Stop here
          .else
            mov xax, [xax].$Obj(XTreeViewNode).pParent
            .if [xax].$Obj(XTreeViewNode).pNextSibling != NULL
              mov xcx, [xax].$Obj(XTreeViewNode).pNextSibling
              add ebx, [xcx].$Obj(XTreeViewNode).dHeight
              .break
            .endif
          .endif
        .endw
      .endif
    .endw
@@:
    sub ebx, [xcx].$Obj(XTreeViewNode).dHeight
  .endif

@@Found:
  mov eax, dNewTotalOffset
  mov [xsi].TotalOffset.y, eax
  sub eax, ebx
  mov [xsi].dFirstOffset, eax
  mov xdx, xcx
  OCall xsi.Set1stVisibleNode, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  XTV_IsNodeInDispData
; Purpose:    XWCollection.FirstThat callback proc to check if a node is in the collection.
; Arguments:  Arg1: -> DispData
; Return:     xax -> Node.
;             ecx = TRUE if found, otherwise FALSE.

XTV_IsNodeInDispData proc pDispData:PXTVN_DISP_INFO, pNode:$ObjPtr(XTreeViewNode), pIndex:POINTER
  mov xax, pDispData
  mov xcx, pNode
  .if xcx == [xax].XTVN_DISP_INFO.pNode
    mov eax, TRUE
  .else
    mov xdx, pIndex
    inc DWORD ptr [xdx]
    xor eax, eax
  .endif
  ret
XTV_IsNodeInDispData endp

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.GetDispInfo
; Purpose:    Return the XTVN_DISP_INFO structure associated to a XTreeViewNode that is in view.
; Arguments:  Arg1: -> XTreeViewNode
; Return:     xax -> XTVN_DISP_INFO, NULL if not found.
;             ecx = index in DispInfoColl.

Method XTreeView.GetDispInfo,, pNode:$ObjPtr(XTreeViewNode)
  local dIndex:DWORD

  SetObject xcx

;  m2z dData
  OCall [xcx].DispInfoColl::XWCollection.FirstThat, \
                            offset XTV_IsNodeInDispData, pNode, addr dIndex
  .if xax == NULL
    mov ecx, -1
  .else
    mov ecx, dIndex
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.GetMetrics
; Purpose:    Load all parameters that defines the window appearance.
; Arguments:  None
; Return:     Nothing.

Method XTreeView.GetMetrics, uses xsi
;  DbgText "GetMetrics"
  SetObject xsi
  mov [xsi].ScrollbarMetric.x, $32($invoke(GetSystemMetrics, SM_CXVSCROLL))
  mov [xsi].ScrollbarMetric.y, $32($invoke(GetSystemMetrics, SM_CYHSCROLL))
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Init
; Purpose:    Initialize a XTreeView object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent handle.
;             Arg3: -> DEF_XTV structure.
; Return:     Nothing.

Method XTreeView.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_XTV
;  DbgText "XTreeView.Init"
  SetObject xsi

  OCall xsi.GetMetrics
  mov xbx, pDefStruc
  assume xbx:PDEF_XTV
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE or WS_TABSTOP
  invoke CreateWindowEx, [xbx].dExStyle, offset cXTV_ClassName, [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING

  ACall xsi.Init, pOwner, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.InitRes
; Purpose:    Initialize the XTreeViewNode object from a resource.
; Arguments:  Arg1: Window HANDLE.
; Return:     Nothing.

Method XTreeView.InitRes, uses xsi, hWnd:HWND
  SetObject xsi
  BitSet [xsi].dFlags, XTVF_RESOURCE
  mrm [xsi].hWnd, hWnd, xax
  ACall xsi.Init, NULL, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Insert
; Purpose:    Insert a new node.
; Arguments:  Arg1: -> Node to insert.
;             Arg2: -> Reference node. NULL is considdered as the root.
;             Arg3: Insertion mode. See "XTreeViewNode.CanDropHere" method for valid values.
; Return:     xax -> Inserted node.

Method XTreeView.Insert, uses xbx xdi xsi, pNode:$ObjPtr(XTreeViewNode), pRefNode:$ObjPtr(XTreeViewNode), \
                                           dHowToInsert:DWORD
  SetObject xsi
  mov xax, pNode
  .if xax != NULL

    ;Set the correct parent node
    .if (dHowToInsert == XTVN_INSERT_AS_FIRST_CHILD) || \
        (dHowToInsert == XTVN_INSERT_AS_LAST_CHILD)
      m2m [xax].$Obj(XTreeViewNode).pParent, pRefNode, xdx
    .elseif (dHowToInsert == XTVN_INSERT_AS_PREV_SIBLING) || \
            (dHowToInsert == XTVN_INSERT_AS_NEXT_SIBLING)
      mov xcx, pRefNode
      .if xcx != NULL
        mov xcx, [xcx].$Obj(XTreeViewNode).pParent
      .endif
      mov [xax].$Obj(XTreeViewNode).pParent, xcx
    .else
      OCall xsi.ErrorReport, NULL, XTV_UNKNOWN_INSERTION_MODE
      xor eax, eax
      ExitMethod
    .endif

    ;Adjust tree metrics
    mov xax, pNode
    mov edx, [xax].$Obj(XTreeViewNode).dHeight
    mov ebx, [xax].$Obj(XTreeViewNode).dWidth
    .if XTV_IsExpanded(xax)
      add edx, [xax].$Obj(XTreeViewNode).dBranchHeight          ;Cummulate heights
      mov ecx, [xax].$Obj(XTreeViewNode).dBranchWidth
      add ecx, [xsi].dNodeIndent
      uMaxi ebx, ecx, eax                                  ;Trash ecx and eax, ebx = max width
      mov xax, pNode
    .endif
    mov xcx, [xax].$Obj(XTreeViewNode).pParent
    .if (xcx != NULL) && ([xcx].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)
      .repeat
        add [xcx].$Obj(XTreeViewNode).dBranchHeight, edx        ;Cummulate heights
        mov edi, edx
        mov edx, ebx
        uMaxi [xcx].$Obj(XTreeViewNode).dBranchWidth, edx, eax   ;Trash edx and eax
        mov edx, [xcx].$Obj(XTreeViewNode).dWidth
        add ebx, [xsi].dNodeIndent
        uMaxi ebx, edx, eax                                ;Trash edx and eax
        mov edx, edi
        mov xcx, [xcx].$Obj(XTreeViewNode).pParent              ;Move to parent node
      .until (xcx == NULL) || !([xcx].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)
      .if xcx == NULL                                     ;Did we reach the root node?
        add [xsi].TotalSize.y, edx
        add ebx, [xsi].dNodeIndent
        add ebx, [xsi].ClientOffset.x
        uMaxi [xsi].TotalSize.x, ebx, eax                  ;Trash ebx and eax
      .endif
    .else
      .if xcx != NULL
        add [xcx].$Obj(XTreeViewNode).dBranchHeight, edx
        add ebx, [xsi].dNodeIndent
        uMaxi [xcx].$Obj(XTreeViewNode).dBranchWidth, ebx, eax   ;Trash ebx and eax
      .else
        add [xsi].TotalSize.y, edx
        add ebx, [xsi].dNodeIndent
        add ebx, [xsi].ClientOffset.x
        uMaxi [xsi].TotalSize.x, ebx, eax                  ;Trash ebx and eax
      .endif
    .endif

    ;Insert the node
    .if dHowToInsert == XTVN_INSERT_AS_FIRST_CHILD
      mov xax, pNode
      m2z [xax].$Obj(XTreeViewNode).pPrevSibling
      .if [xax].$Obj(XTreeViewNode).pParent == NULL
        mov xdx, [xsi].$Obj(XTreeView).pFirstChild
        mov [xsi].$Obj(XTreeView).pFirstChild, xax
        mov [xax].$Obj(XTreeViewNode).pNextSibling, xdx
        .if xdx == NULL
          mov [xsi].$Obj(XTreeView).pLastChild, xax
        .else
          mov [xdx].$Obj(XTreeViewNode).pPrevSibling, xax
        .endif
      .else
        mov xcx, [xax].$Obj(XTreeViewNode).pParent
        mov xdx, [xcx].$Obj(XTreeViewNode).pFirstChild
        mov [xcx].$Obj(XTreeViewNode).pFirstChild, xax
        mov [xax].$Obj(XTreeViewNode).pNextSibling, xdx
        .if xdx == NULL
          mov [xcx].$Obj(XTreeViewNode).pLastChild, xax
        .else
          mov [xdx].$Obj(XTreeViewNode).pPrevSibling, xax
        .endif
      .endif

    .elseif dHowToInsert == XTVN_INSERT_AS_LAST_CHILD
      mov xax, pNode
      m2z [xax].$Obj(XTreeViewNode).pNextSibling
      .if [xax].$Obj(XTreeViewNode).pParent == NULL
        mov xdx, [xsi].$Obj(XTreeView).pLastChild
        mov [xax].$Obj(XTreeViewNode).pPrevSibling, xdx
        mov [xsi].$Obj(XTreeView).pLastChild, xax
        .if xdx == NULL
          mov [xsi].$Obj(XTreeView).pFirstChild, xax
        .else
          mov [xdx].$Obj(XTreeViewNode).pNextSibling, xax
        .endif
      .else
        mov xcx, [xax].$Obj(XTreeViewNode).pParent
        mov xdx, [xcx].$Obj(XTreeViewNode).pLastChild
        mov [xcx].$Obj(XTreeViewNode).pLastChild, xax
        mov [xax].$Obj(XTreeViewNode).pPrevSibling, xdx
        .if xdx == NULL
          mov [xcx].$Obj(XTreeViewNode).pFirstChild, xax
        .else
          mov [xdx].$Obj(XTreeViewNode).pNextSibling, xax
        .endif
      .endif

    .elseif dHowToInsert == XTVN_INSERT_AS_PREV_SIBLING
      mov xax, pNode
      .if [xax].$Obj(XTreeViewNode).pParent == NULL
        mov xdx, pRefNode
        .if xdx == NULL
          mov xdx, [xsi].pFirstChild
          mov [xsi].$Obj(XTreeView).pFirstChild, xax
          mov [xax].$Obj(XTreeViewNode).pNextSibling, xdx
          m2z [xax].$Obj(XTreeViewNode).pPrevSibling
          .if xdx == NULL
            mov [xsi].$Obj(XTreeView).pLastChild, xax
          .else
            mov [xdx].$Obj(XTreeViewNode).pPrevSibling, xax
          .endif
        .else
          mov xcx, [xdx].$Obj(XTreeViewNode).pPrevSibling
          mov [xax].$Obj(XTreeViewNode).pNextSibling, xdx
          mov [xax].$Obj(XTreeViewNode).pPrevSibling, xcx
          mov [xdx].$Obj(XTreeViewNode).pPrevSibling, xax
          .if xcx == NULL
            mov [xsi].pFirstChild, xax
          .else
            mov [xcx].$Obj(XTreeViewNode).pNextSibling, xax
          .endif
        .endif
      .else
        mov xdx, pRefNode
        mov xcx, [xdx].$Obj(XTreeViewNode).pPrevSibling
        mov [xax].$Obj(XTreeViewNode).pNextSibling, xdx
        mov [xdx].$Obj(XTreeViewNode).pPrevSibling, xax
        mov [xax].$Obj(XTreeViewNode).pPrevSibling, xcx
        .if xcx == NULL
          mov xcx, [xdx].$Obj(XTreeViewNode).pParent
          mov [xcx].$Obj(XTreeViewNode).pFirstChild, xax
        .else
          mov [xcx].$Obj(XTreeViewNode).pNextSibling, xax
        .endif
      .endif

    .elseif dHowToInsert == XTVN_INSERT_AS_NEXT_SIBLING
      mov xax, pNode
      .if [xax].$Obj(XTreeViewNode).pParent == NULL
        mov xdx, pRefNode
        .if xdx == NULL
          mov xdx, [xsi].pLastChild
          mov [xsi].$Obj(XTreeView).pLastChild, xax
          mov [xax].$Obj(XTreeViewNode).pPrevSibling, xdx
          m2z [xax].$Obj(XTreeViewNode).pNextSibling
          .if xdx == NULL
            mov [xsi].$Obj(XTreeView).pFirstChild, xax
          .else
            mov [xdx].$Obj(XTreeViewNode).pNextSibling, xax
          .endif
        .else
          mov xcx, [xdx].$Obj(XTreeViewNode).pNextSibling
          mov [xax].$Obj(XTreeViewNode).pPrevSibling, xdx
          mov [xax].$Obj(XTreeViewNode).pNextSibling, xcx
          mov [xdx].$Obj(XTreeViewNode).pNextSibling, xax
          .if xcx == NULL
            mov [xsi].pLastChild, xax
          .else
            mov [xcx].$Obj(XTreeViewNode).pPrevSibling, xax
          .endif
        .endif
      .else
        mov xdx, pRefNode
        mov xcx, [xdx].$Obj(XTreeViewNode).pNextSibling
        mov [xdx].$Obj(XTreeViewNode).pNextSibling, xax
        mov [xax].$Obj(XTreeViewNode).pNextSibling, xcx
        mov [xax].$Obj(XTreeViewNode).pPrevSibling, xdx
        .if xcx == NULL
          mov xcx, [xdx].$Obj(XTreeViewNode).pParent
          mov [xcx].$Obj(XTreeViewNode).pLastChild, xax
        .else
          mov [xcx].$Obj(XTreeViewNode).pPrevSibling, xax
        .endif
      .endif
    .endif

  .else
    OCall xsi.ErrorReport, NULL, XTV_INVALID_POINTER
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.MoveInViewBottom
; Purpose:    Bring the specified node to the bottom of the current view.
; Arguments:  Arg1: -> Node to be moved.
; Return:     Nothing.
; Notes:      - no visual update is performed!

Method XTreeView.MoveInViewBottom, uses xbx xdi xsi, pNode:$ObjPtr(XTreeViewNode)
  SetObject xsi

  .if pNode != NULL
    ;Reset hottrack flag
    mov xax, [xsi].pHotTrackedNode
    .if xax != NULL
      BitClr [xax].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
    .endif

    mov xcx, pNode
    mov ebx, [xcx].$Obj(XTreeViewNode).dHeight

    .while ebx < [xsi].ClientSize.y
      XTV_BrowseBack xcx
      .break .if xcx == NULL
      add ebx, [xcx].$Obj(XTreeViewNode).dHeight
    .endw

    .if xcx == NULL
      mov [xsi].TotalOffset.y, ecx
      mov [xsi].dFirstOffset, ecx
      OCall xsi.Set1stVisibleNode, [xsi].pFirstChild
    .else
      sub ebx, [xsi].ClientSize.y
      mov [xsi].dFirstOffset, ebx
      mov xdi, xcx
      OCall xsi.Set1stVisibleNode, xdi
      mov xcx, xdi
      .while TRUE
        .if [xcx].$Obj(XTreeViewNode).pPrevSibling != NULL
          mov xcx, [xcx].$Obj(XTreeViewNode).pPrevSibling
          .if XTV_IsExpanded(xcx)
            add ebx, [xcx].$Obj(XTreeViewNode).dBranchHeight
          .endif
          add ebx, [xcx].$Obj(XTreeViewNode).dHeight
        .else
          mov xcx, [xcx].$Obj(XTreeViewNode).pParent
          .break .if xcx == NULL
          add ebx, [xcx].$Obj(XTreeViewNode).dHeight
        .endif
      .endw
      mov [xsi].TotalOffset.y, ebx
    .endif

    invoke InvalidateRect, [xsi].hWnd, NULL, FALSE
  .else
    OCall xsi.ErrorReport, NULL, XTV_INVALID_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.MoveInViewTop
; Purpose:    Bring the specified node on the top of the current view.
; Arguments:  Arg1: -> Node.
; Return:     Nothing.
; Notes:      - no visual update is performed!

Method XTreeView.MoveInViewTop, uses xsi, pNode:$ObjPtr(XTreeViewNode)
  SetObject xsi

  .if pNode != NULL
    ;Reset hottrack flag
    mov xax, [xsi].pHotTrackedNode
    .if xax != NULL
      BitClr [xax].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
    .endif

    xor edx, edx
    mov xcx, pNode

    .while TRUE
      .if [xcx].$Obj(XTreeViewNode).pPrevSibling != NULL
        mov xcx, [xcx].$Obj(XTreeViewNode).pPrevSibling
        .if XTV_IsExpanded(xcx)
          add edx, [xcx].$Obj(XTreeViewNode).dBranchHeight
        .endif
        add edx, [xcx].$Obj(XTreeViewNode).dHeight
      .else
        mov xcx, [xcx].$Obj(XTreeViewNode).pParent
        .break .if xcx == NULL
        add edx, [xcx].$Obj(XTreeViewNode).dHeight
      .endif
    .endw

    mov [xsi].TotalOffset.y, edx
    OCall xsi.Set1stVisibleNode, pNode
    m2z [xsi].dFirstOffset

    invoke InvalidateRect, [xsi].hWnd, NULL, FALSE

  .else
    OCall xsi.ErrorReport, NULL, XTV_INVALID_POINTER

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnButtonDblClk
; Purpose:    Handler of mouse double clicks.
; Arguments:  Arg1: Button that triggered this method.
;             Arg2: First message parameter. Key flags.
;             Arg3: Second message parameter. Cursor position.
; Return:     Nothing.

Method XTreeView.OnButtonDblClk, uses xsi, dButton:DWORD, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT

;  DbgText "XTreeView.OnButtonDblClk"
  SetObject xsi
  PntS2Pnt CursorPos, lParam
  OCall [xsi].DispInfoColl::XWCollection.FirstThat, addr XTV_IsPointInNode, CursorPos.y, NULL
  ReleaseObject
  .if xax != NULL
    lea xsi, CursorPos
    OCall [xax].XTVN_DISP_INFO.pNode::XTreeViewNode.MouseHitDbl, dButton, xsi, xax, DWORD ptr wParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnButtonDown
; Purpose:    Handler of mouse button down.
; Arguments:  Arg1: Button that triggered this method.
;             Arg2: First message parameter. Key flags.
;             Arg3: Second message parameter. Cursor position.
; Return:     Nothing.

Method XTreeView.OnButtonDown, uses xsi, dButton:DWORD, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT

  SetObject xsi
  invoke SetFocus, [xsi].hWnd

  PntS2Pnt CursorPos, lParam
  OCall [xsi].DispInfoColl::XWCollection.FirstThat, addr XTV_IsPointInNode, CursorPos.y, NULL
  ReleaseObject
  .if xax != NULL
    lea xsi, CursorPos
    mov xcx, [xax].XTVN_DISP_INFO.pNode
    OCall xcx::XTreeViewNode.MouseHit, dButton, xsi, xax, DWORD ptr wParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnButtonUp
; Purpose:    Handler of mouse button up.
; Arguments:  Arg1: Button that triggered this method.
;             Arg2: First message parameter. Key flags.
;             Arg3: Second message parameter. Cursor position.
; Return:     Nothing.

Method XTreeView.OnButtonUp, uses xsi, dButton:DWORD, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  BitClr [xsi].dState, XTVS_DRAGGINGSTARTED
  mov eax, [xsi].dDragMouseButton
  .if (eax == dButton) && ([xsi].dState & XTVS_DRAGGING)
    invoke ReleaseCapture
    BitClr [xsi].dState, XTVS_DRAGGING
    invoke SetCursor, [xsi].hCursorArrow

    ;Remove the selected node and reinsert it using the hottracked node as insertion reference
    .if [xsi].pHotTrackedNode == NULL
      OCall xsi.CanDropHere, [xsi].pSelectedNode, DWORD ptr wParam, DWORD ptr lParam
    .else
      OCall [xsi].pHotTrackedNode::XTreeViewNode.CanDropHere, [xsi].pSelectedNode, DWORD ptr wParam, DWORD ptr lParam
    .endif
    .if eax != 0
      OCall xsi.Drop, [xsi].pSelectedNode, [xsi].pHotTrackedNode, eax
    .endif

  .elseIfBitSet [xsi].dState, XTVS_DRAGGINGABORTED
    BitClr [xsi].dState, XTVS_DRAGGINGABORTED

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnCreate
; Purpose:    Event handler for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method XTreeView.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, ScrollInfo:SCROLLINFO

;  DbgText "XTreeView.OnCreate"
  SetObject xsi

  ;Some initialization
  .if $invoke(FindResource, hInstance, offset cXTV_CursorArrow, RT_GROUP_CURSOR)
    mov [xsi].hCursorArrow, $invoke(LoadCursor, hInstance, offset cXTV_CursorArrow)
  .endif
  .if $invoke(FindResource, hInstance, offset cXTV_CursorNo, RT_GROUP_CURSOR)
    mov [xsi].hCursorNo,    $invoke(LoadCursor, hInstance, offset cXTV_CursorNo)
  .endif
  .if $invoke(FindResource, hInstance, offset cXTV_CursorNode, RT_GROUP_CURSOR)
    mov [xsi].hCursorNode,  $invoke(LoadCursor, hInstance, offset cXTV_CursorNode)
  .endif
  .if $invoke(FindResource, hInstance, offset cXTV_CursorFirst, RT_GROUP_CURSOR)
    mov [xsi].hCursorFirst, $invoke(LoadCursor, hInstance, offset cXTV_CursorFirst)
  .endif
  .if $invoke(FindResource, hInstance, offset cXTV_CursorLast, RT_GROUP_CURSOR)
    mov [xsi].hCursorLast,  $invoke(LoadCursor, hInstance, offset cXTV_CursorLast)
  .endif
  .if $invoke(FindResource, hInstance, offset cXTV_CursorPrev, RT_GROUP_CURSOR)
    mov [xsi].hCursorPrev,  $invoke(LoadCursor, hInstance, offset cXTV_CursorPrev)
  .endif
  .if $invoke(FindResource, hInstance, offset cXTV_CursorNext, RT_GROUP_CURSOR)
    mov [xsi].hCursorNext,  $invoke(LoadCursor, hInstance, offset cXTV_CursorNext)
  .endif
  OCall [xsi].DispInfoColl::XWCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY
  OCall [xsi].DispInfoPool::DataPool.Init, xsi, [xsi].dDispInfoSize, 1000, 4
  lea xcx, [xsi].DispInfoColl
  Override xcx::XWCollection.DestroyItem, DisplayInfoColl.DestroyItem

  ;Create the text font
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 10, eax, -72
  mov XTV_LogFontText.lfHeight, eax
  mov [xsi].hFontText, $invoke(CreateFontIndirect, offset XTV_LogFontText)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke ReleaseDC, [xsi].hWnd, hDC

  ;Create pens to draw
  mov [xsi].hPenLine, $invoke(CreatePen, PS_SOLID, 0, [xsi].dColorLine)
  mov [xsi].hPenToggler, $invoke(CreatePen, PS_SOLID, 0, [xsi].dColorToggler)

  ;Set scrollbar infos
  mov ScrollInfo.cbSize, sizeof SCROLLINFO
  mov ScrollInfo.fMask, SIF_RANGE
  m2z ScrollInfo.nMin
  mov ScrollInfo.nMax, 0FFFFh       ;16 bit max value passed in WM_HSCROLL/WM_VSCROLL
  invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, FALSE
  invoke SetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo, FALSE

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnEnable
; Purpose:    Event handler for WM_ENABLE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnEnable, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnEnable"
  SetObject xsi
  mov xax, wParam
  mov edx, [xsi].dState
  and xdx, XTVS_DISABLED
  xor xdx, xax
  .if ZERO?                                             ;Has the enable status changed?
    .if eax != FALSE
      BitClr [xsi].dState, XTVS_DISABLED
    .else
      BitSet [xsi].dState, XTVS_DISABLED
    .endif
    invoke InvalidateRect, [xsi].hWnd, NULL, FALSE      ;Invalidate complete client area
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnDestroy
; Purpose:    Event handler for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnDestroy"
  SetObject xsi

  OCall [xsi].DispInfoColl::XWCollection.Done
  OCall [xsi].DispInfoPool::DataPool.Done

  invoke DeleteObject, [xsi].hPenLine
  invoke DeleteObject, [xsi].hPenToggler
  invoke DeleteObject, [xsi].hFontText

  .if [xsi].hCursorArrow
    invoke DestroyCursor, [xsi].hCursorArrow
  .endif
  .if [xsi].hCursorNo
    invoke DestroyCursor, [xsi].hCursorNo
  .endif
  .if [xsi].hCursorNode
    invoke DestroyCursor, [xsi].hCursorNode
  .endif
  .if [xsi].hCursorFirst
    invoke DestroyCursor, [xsi].hCursorFirst
  .endif
  .if [xsi].hCursorLast
    invoke DestroyCursor, [xsi].hCursorLast
  .endif
  .if [xsi].hCursorPrev
    invoke DestroyCursor, [xsi].hCursorPrev
  .endif
  .if [xsi].hCursorNext
    invoke DestroyCursor, [xsi].hCursorNext
  .endif

  .if [xsi].hBackBuffer != 0
    invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hBmpPrv)
  .endif
  invoke DeleteDC, [xsi].hMemDC

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnGetDlgCode
; Purpose:    Event handler for WM_GETDLGCODE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax =  indicates which type of input the control processes.

Method XTreeView.OnGetDlgCode,, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnGetDlgCode"
  mov eax, DLGC_WANTARROWS or DLGC_WANTCHARS
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnGetFont
; Purpose:    Event handler for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = The font with which the control is currently drawing its text.

Method XTreeView.OnGetFont,, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnGetFont"
  SetObject xcx
  mov xax, [xcx].hFontText
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnHScroll
; Purpose:    Event handler for WM_HSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XTreeView.OnHScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .ifBitClr [xsi].dState, XTVS_LOCKED
    mov xax, wParam
    .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
      shr eax, 16                                       ;Get high part of eax
      mov ecx, [xsi].TotalSize.x
      mul ecx
      mov ecx, 0FFFFh
      div ecx
      mov ecx, [xsi].TotalSize.x
      sub ecx, [xsi].ClientSize.x
      .if eax > ecx
        mov eax, ecx
      .endif

    .elseif ax == SB_LINEUP
      mov edx, [xsi].ArrowScrollValue.x
      .if edx < [xsi].TotalOffset.x
        mov eax, [xsi].TotalOffset.x
        sub eax, edx
        inc [xsi].ArrowScrollValue.x
      .else
        xor eax, eax
      .endif

    .elseif ax == SB_LINEDOWN
      mov edx, [xsi].ArrowScrollValue.x
      mov eax, [xsi].TotalSize.x
      sub eax, [xsi].ClientSize.x
      mov ecx, eax
      sub ecx, edx
      .if SDWORD ptr ecx > [xsi].TotalOffset.x
        mov eax, [xsi].TotalOffset.x
        add eax, edx
        inc [xsi].ArrowScrollValue.x
      .endif

    .elseif ax == SB_PAGEUP
      mov edx, [xsi].ClientSize.x
      .if edx < [xsi].TotalOffset.x
        mov eax, [xsi].TotalOffset.x
        sub eax, edx
      .else
        xor eax, eax
      .endif

    .elseif ax == SB_PAGEDOWN
      mov edx, [xsi].ClientSize.x
      mov eax, [xsi].TotalSize.x
      sub eax, edx
      mov ecx, eax
      sub ecx, edx
      .if SDWORD ptr ecx > [xsi].TotalOffset.x
        mov eax, [xsi].TotalOffset.x
        add eax, edx
      .endif

    .else
      jmp @@Exit                                        ;Unrecognized message
    .endif
    mov [xsi].TotalOffset.x, eax

    OCall xsi.Draw
  .endif
@@Exit:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnKeyDown
; Purpose:    Event handler for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XTreeView.OnKeyDown, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT, CursorPos:POINT

  ANNOTATION use:CursorPos

  SetObject xsi
  .if [xsi].pSelectedNode != NULL
    mov xax, wParam

    .if eax == VK_UP
      ;Move to the above node
      mov xdx, [xsi].pSelectedNode
      mov xbx, xdx
      XTV_BrowseBack xdx
      cmp xdx, NULL
      jz @@Exit                                       ;Nothing to do, avoid flicker
      OCall xsi.Select, xdx
      OCall xsi.GetDispInfo, [xsi].pSelectedNode
      .if xcx == 0                                    ;First node in view
        m2z [xsi].dFirstOffset
        mov xax, [xsi].pFirstChild
        .if xax == [xsi].pSelectedNode
          m2z [xsi].TotalOffset.y
        .endif
      .elseif xax == NULL                             ;Not in view
        OCall xsi.MoveInViewTop, [xsi].pSelectedNode
      .else
        OCall [xsi].pSelectedNode::XTreeViewNode.RenderContent, xax
        OCall xsi.GetDispInfo, xbx
        OCall xbx::XTreeViewNode.RenderContent, xax
      .endif

    .elseif eax == VK_DOWN
      ;Move to the below node
      mov xdx, [xsi].pSelectedNode
      mov xbx, xdx
      XTV_BrowseFrwd xdx
      cmp xdx, NULL
      jz @@Exit                                       ;Nothing to do, avoid flicker
      OCall xsi.Select, xdx
      OCall xsi.GetDispInfo, [xsi].pSelectedNode
      mov edx, [xsi].DispInfoColl.dCount
      dec edx
      .if ecx >= edx                                  ;Is it the last node in view,
        OCall xsi.MoveInViewBottom, [xsi].pSelectedNode   ;  or is it not in view
      .else
        OCall [xsi].pSelectedNode::XTreeViewNode.RenderContent, xax
        OCall xsi.GetDispInfo, xbx
        OCall xbx::XTreeViewNode.RenderContent, xax
      .endif

    .elseif eax == VK_RIGHT
      ;First expand if collapsed and then move to the first child
      mov xbx, [xsi].pSelectedNode
      cmp [xbx].$Obj(XTreeViewNode).pFirstChild, NULL
      jz @@Exit                                       ;Nothing to do, avoid flicker
      .ifBitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_EXPANDED
        OCall xbx::XTreeViewNode.Toggle
      .else
        mov xbx, [xbx].$Obj(XTreeViewNode).pFirstChild
        OCall xsi.Select, xbx
      .endif

      ;Node is now expanded; maybe we have to reposition the tree
      OCall xsi.GetDispInfo, xbx
      mov eax, [xax].XTVN_DISP_INFO.sdNodeTop
      add eax, [xsi].TotalOffset.y                    ;eax = node offset
      mov edx, eax
      add edx, [xbx].$Obj(XTreeViewNode).dHeight
      add edx, [xbx].$Obj(XTreeViewNode).dBranchHeight
      sub edx, [xsi].ClientSize.y
      sub edx, [xsi].TotalOffset.y
      .if !SIGN?
        mov ecx, eax                                  ;The last branch node is off view
        sub ecx, [xsi].TotalOffset.y
        sub ecx, edx
        .if !SIGN?
          add eax, [xbx].$Obj(XTreeViewNode).dHeight
          add eax, [xbx].$Obj(XTreeViewNode).dBranchHeight
          sub eax, [xsi].ClientSize.y
        .endif
        OCall xsi.Find1stVisibleNode, eax
      .endif

    .elseif eax == VK_LEFT
      ;First collapse if expanded and then move to the parent
      mov xcx, [xsi].pSelectedNode
      .if XTV_IsExpanded(xcx)
        OCall xcx::XTreeViewNode.Toggle

        ;Correct the client area coords
        mov eax, [xsi].TotalSize.x
        .if eax > [xsi].ClientSize.x
          invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, TRUE
          invoke GetClientRect, [xsi].hWnd, addr CRect
          s2s [xsi].ClientSize, POINT ptr CRect.right, xax, xcx
        .endif

        XTV_GetBottomViewNode xsi, xcx, eax, xdx
        .if xcx == NULL
          OCall xsi.MoveInViewBottom, xdx
        .endif
      .else
        cmp [xcx].$Obj(XTreeViewNode).pParent, NULL
        jz @@Exit                                     ;Nothing to do, avoid flicker
        mov xdx, [xcx].$Obj(XTreeViewNode).pParent
        mov xdi, xdx
        OCall xsi.Select, xdx
        OCall xsi.GetDispInfo, xdi
        .if xcx == 0                                  ;First node in view
          m2z [xsi].dFirstOffset
        .elseif xax == NULL                           ;Not in view
          OCall xsi.MoveInViewTop, [xsi].pSelectedNode
        .endif
      .endif
      ;Check if the selected node is in view
      XTV_GetBottomViewNode xsi, xcx, eax, xdx
      .if xcx == NULL
        OCall xsi.MoveInViewBottom, xdx
      .endif

    .elseif eax == VK_PRIOR ;VK_PGUP
      mov xax, [xsi].pFirstChild
      cmp xax, [xsi].pSelectedNode
      je @@Exit                                       ;Nothing to do, avoid flicker

      ;Move the selected node on bottom of the view
      OCall xsi.MoveInViewBottom, [xsi].pSelectedNode

      ;Get the first completely visible node and select it
      mov xcx, [xsi].pSelectedNode
      mov edx, [xcx].$Obj(XTreeViewNode).dHeight
      .repeat
        mov xax, xcx
        XTV_BrowseBack xcx
        .break .if xcx == NULL
        add edx, [xcx].$Obj(XTreeViewNode).dHeight
      .until edx > [xsi].ClientSize.y

      ;Select it and adjust the view if it is the first node
      OCall xsi.Select, xax
      XTV_GetBottomViewNode xsi, xcx, edx, xax
      .if xcx == NULL
        OCall xsi.MoveInViewBottom, xax
      .else
        OCall xsi.MoveInViewTop, [xsi].pSelectedNode
      .endif

    .elseif eax == VK_NEXT ;VK_PGDN
      ;Check if the selected node is the last visible node
      mov xcx, [xsi].pLastChild
      .while TRUE
        .break .if XTV_IsCollapsed(xcx)
        mov xdx, [xcx].$Obj(XTreeViewNode).pLastChild
        .break .if xdx == NULL
        mov xcx, xdx
      .endw
      cmp xcx, [xsi].pSelectedNode
      je @@Exit                                       ;Nothing to do, avoid flicker

      ;Move the selected node on top of the view
      OCall xsi.MoveInViewTop, [xsi].pSelectedNode

      ;Get the last completely visible node and select it
      mov xcx, [xsi].pSelectedNode
      mov edx, [xcx].$Obj(XTreeViewNode).dHeight
      .repeat
        mov xax, xcx
        XTV_BrowseFrwd xcx
        .break .if xcx == NULL
        add edx, [xcx].$Obj(XTreeViewNode).dHeight
      .until edx > [xsi].ClientSize.y

      ;Select it and adjust the view if it is the last node
      mov xdi, xax
      mov xbx, xcx
      OCall xsi.Select, xax
      .if xbx == NULL
        OCall xsi.MoveInViewBottom, xdi
      .endif

    .elseif eax == VK_DELETE
      .ifBitClr [xsi].dFlags, XTVF_DISABLE_DEL_KEY
        OCall xsi.Remove, [xsi].pSelectedNode
        .if [xsi].pSelectedNode == NULL
          ;All nodes deleted
          xor eax, eax
          mov [xsi].TotalOffset.y, eax
          mov [xsi].TotalOffset.x, eax
          mov [xsi].dFirstOffset, eax
          OCall xsi.Set1stVisibleNode, xax
        .else
          .if xax == [xsi].pFirstVisibleNode            ;The deleted node was the first in view
            OCall xsi.MoveInViewTop, [xsi].pSelectedNode
          .else
            mov edx, [xsi].TotalSize.y
            sub edx, [xsi].ClientSize.y
            .if SDWORD ptr edx < [xsi].TotalOffset.y    ;Have we at hole on the bottom of the view?
              .if SDWORD ptr edx < 0
                xor edx, edx
              .endif
              OCall xsi.Find1stVisibleNode, edx

              ;Check if the selected node is in view; if not, bring it in top position
              mov xdx, [xsi].pSelectedNode
              mov xcx, [xsi].pFirstVisibleNode
              .while (xcx != NULL) && (xcx != xdx)
                XTV_BrowseFrwd xcx
              .endw
              .if xcx == NULL
                OCall xsi.MoveInViewTop, xdx
              .endif

            .endif
          .endif
        .endif
      .endif

    .elseif eax == VK_HOME
      ;Go to the first node in the tree
      mov xdx, [xsi].pFirstChild
      cmp xdx, [xsi].pSelectedNode
      je @@Exit                                       ;Nothing to do, avoid flicker
      mov xdi, xdx
      OCall xsi.Set1stVisibleNode, xdx
      OCall xsi.Select, xdi
      m2z [xsi].TotalOffset.y
      m2z [xsi].dFirstOffset

    .elseif eax == VK_END
      ;Go to the last node in the tree
      mov xcx, [xsi].pLastChild
      .while xcx != NULL
        .break .if XTV_IsCollapsed(xcx)
        mov xdx, xcx
        mov xcx, [xcx].$Obj(XTreeViewNode).pLastChild
      .endw
      .if xcx == NULL
        mov xcx, xdx
      .endif
      cmp xcx, [xsi].pSelectedNode
      je @@Exit                                       ;Nothing to do, avoid flicker
      mov xdi, xcx
      OCall xsi.Select, xdi
      OCall xsi.MoveInViewBottom, xdi

    .elseif eax == VK_ESCAPE
      BitClr [xsi].dState, XTVS_DRAGGINGSTARTED
      .ifBitSet [xsi].dState, XTVS_DRAGGING
        invoke ReleaseCapture
        BitClr [xsi].dState, XTVS_DRAGGING
        BitSet [xsi].dState, XTVS_DRAGGINGABORTED
        invoke SetCursor, [xsi].hCursorArrow
      .endif

    .elseif eax == VK_CONTROL
      XTV_SimulateMouseMove CONTROL, LBUTTON, MBUTTON, RBUTTON, SHIFT


    .elseif eax == VK_SHIFT
      XTV_SimulateMouseMove SHIFT, LBUTTON, MBUTTON, RBUTTON, CONTROL

    .else
      jmp @@Exit
    .endif

    OCall xsi.Draw
    xor eax, eax

  .else
@@Exit:
    invoke DefWindowProc, [xsi].hWnd, WM_KEYDOWN, wParam, lParam

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnKeyUp
; Purpose:    Event handler for WM_KEYUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XTreeView.OnKeyUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT

  ANNOTATION use:CursorPos

  SetObject xsi
  .if [xsi].pSelectedNode != NULL
    mov xax, wParam

    .if eax == VK_CONTROL
      XTV_SimulateMouseMove 0, LBUTTON, MBUTTON, RBUTTON, SHIFT

    .elseif eax == VK_SHIFT
      XTV_SimulateMouseMove 0, LBUTTON, MBUTTON, RBUTTON, CONTROL

    .else
      jmp @@Exit
    .endif
    xor eax, eax

  .else
@@Exit:
    invoke DefWindowProc, [xsi].hWnd, WM_KEYUP, wParam, lParam

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnKillFocus
; Purpose:    Event handler for WM_KILLFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.
; Notes:      - Only affects the selected and hottracked nodes.
;               Redefine this method if other processing is required.

Method XTreeView.OnKillFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnKillFocus"
  SetObject xsi
  invoke ReleaseCapture
  BitClr [xsi].dState, (XTVS_FOCUSED or XTVS_DRAGGINGSTARTED)
  .ifBitSet [xsi].dState, XTVS_DRAGGING
    BitClr [xsi].dState, XTVS_DRAGGING
    BitSet [xsi].dState, XTVS_DRAGGINGABORTED
    invoke SetCursor, [xsi].hCursorArrow
  .endif

  .if [xsi].pSelectedNode != NULL
    OCall xsi.GetDispInfo, [xsi].pSelectedNode
    OCall [xsi].pSelectedNode::XTreeViewNode.RenderContent, xax
  .endif

  mov xax, [xsi].pHotTrackedNode
  .if xax != NULL
    BitClr [xax].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
    OCall xsi.GetDispInfo, xax
    OCall [xsi].pHotTrackedNode::XTreeViewNode.RenderContent, xax
  .endif

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnLButtonDblClk
; Purpose:    Event handler for WM_LBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnLButtonDblClk,, wParam:WPARAM, lParam:LPARAM
  OCall pSelf::XTreeView.OnButtonDblClk, MK_LBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnLButtonDown
; Purpose:    Event handler for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnLButtonDown,, wParam:WPARAM, lParam:LPARAM
  OCall pSelf::XTreeView.OnButtonDown, MK_LBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnLButtonUp
; Purpose:    Event handler for for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnLButtonUp,, wParam:WPARAM, lParam:LPARAM
  OCall pSelf::XTreeView.OnButtonUp, MK_LBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnMButtonDblClk
; Purpose:    Event handler for WM_MBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnMButtonDblClk,, wParam:WPARAM, lParam:LPARAM
  OCall pSelf::XTreeView.OnButtonDblClk, MK_MBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnMButtonDown
; Purpose:    Event handler for WM_MBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnMButtonDown,, wParam:WPARAM, lParam:LPARAM
  OCall pSelf::XTreeView.OnButtonDown, MK_MBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnMButtonUp
; Purpose:    Event handler for for WM_MBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnMButtonUp,, wParam:WPARAM, lParam:LPARAM
  OCall pSelf::XTreeView.OnButtonUp, MK_MBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  XTV_EmitMouseMoveMsg
; Purpose:    Emit a WM_MOUSEMOVE message.
; Arguments:  Arg1: Destrination hWnd.
;             Arg2: wParam = key flags.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

XTV_EmitMouseMoveMsg proc hWnd:HWND, wParam:WPARAM
  local CursorPos:POINT

  invoke GetCursorPos, addr CursorPos                   ;Get current (new) cursor position
  invoke ScreenToClient, hWnd, addr CursorPos
  mov eax, CursorPos.y
  shl eax, 16
  mov ax, WORD ptr CursorPos.x
  invoke PostMessage, hWnd, WM_MOUSEMOVE, wParam, eax   ;Retrigger WM_MOUSEMOVE
  ret
XTV_EmitMouseMoveMsg endp

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnMouseMove
; Purpose:    Event handler for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XTreeView.OnMouseMove, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT, CursorPos:POINT, pDispInfo:PXTVN_DISP_INFO

;  DbgText "XTreeView.OnMouseMove"
  SetObject xsi
  .if !([xsi].dState & XTVS_DISABLED) && ([xsi].dState & XTVS_FOCUSED)
    .ifBitSet [xsi].dState, XTVS_DRAGGING
      invoke SetCapture, [xsi].hWnd
    .endif
    PntS2Pnt CursorPos, lParam
    xor ebx, ebx
    invoke GetClientRect, [xsi].hWnd, addr CRect
    invoke IsPntInRect, addr CursorPos, addr CRect
    .if eax != FALSE
      OCall [xsi].DispInfoColl::XWCollection.FirstThat, addr XTV_IsPointInText, CursorPos.x, CursorPos.y
      .if xax != NULL
        mov xbx, [xax].XTVN_DISP_INFO.pNode
      .endif
      mov xax, wParam
      and eax, MK_LBUTTON or MK_MBUTTON or MK_RBUTTON
      .if (eax == [xsi].dDragMouseButton) && (xbx != [xsi].pSelectedNode) && \
          ([xsi].dState & XTVS_DRAGGINGSTARTED) && !([xsi].dState & XTVS_DRAGGING)
        BitClr [xsi].dState, XTVS_DRAGGINGSTARTED
        BitSet [xsi].dState, XTVS_DRAGGING
        invoke SetCursor, [xsi].hCursorNode
        mov xcx, [xsi].pSelectedNode
        .if (xcx != NULL) && XTV_IsExpanded(xcx) && ([xsi].dFlags & XTVF_COLLAPSE_ON_DRAG)
          OCall xcx::XTreeViewNode.Toggle
          XTV_GetBottomViewNode xsi, xdx, eax
          .if xdx == NULL
            OCall xsi.MoveInViewBottom, [xsi].pSelectedNode
          .endif
        .endif
        jmp @@Draw
      .endif

      ;Check if the user want to scroll
      .ifBitSet [xsi].dState, XTVS_DRAGGING
        mov eax, [xsi].dScrollActivation
        .if SDWORD ptr eax > CursorPos.y
          mov eax, [xsi].TotalOffset.y
          .if SDWORD ptr eax > 0
            dec eax
            OCall xsi.Find1stVisibleNode, eax
            invoke XTV_EmitMouseMoveMsg, [xsi].hWnd, wParam
          .endif
        .else
          mov eax, [xsi].ClientSize.y
          sub eax, [xsi].dScrollActivation
          .if SDWORD ptr eax <= CursorPos.y
            mov ecx, [xsi].TotalSize.y
            sub ecx, [xsi].ClientSize.y
            .if SDWORD ptr ecx > [xsi].TotalOffset.y
              mov eax, [xsi].TotalOffset.y
              inc eax
              OCall xsi.Find1stVisibleNode, eax
              invoke XTV_EmitMouseMoveMsg, [xsi].hWnd, wParam
            .endif
          .else
            mov eax, [xsi].dScrollActivation
            .if SDWORD ptr eax > CursorPos.x
              mov eax, [xsi].TotalOffset.x
              .if SDWORD ptr eax > 0
                dec [xsi].TotalOffset.x
                invoke XTV_EmitMouseMoveMsg, [xsi].hWnd, wParam
              .endif
            .else
              mov eax, [xsi].ClientSize.x
              sub eax, [xsi].dScrollActivation
              .if SDWORD ptr eax <= CursorPos.x
                mov ecx, [xsi].TotalSize.x
                sub ecx, [xsi].ClientSize.x
                .if SDWORD ptr ecx > [xsi].TotalOffset.x
                  inc [xsi].TotalOffset.x
                  invoke XTV_EmitMouseMoveMsg, [xsi].hWnd, wParam
                .endif
              .endif
            .endif
          .endif
        .endif
      .endif

      ;Hottrack management
      OCall [xsi].DispInfoColl::XWCollection.FirstThat, addr XTV_IsPointInContent, CursorPos.x, CursorPos.y
      .if xax != NULL
        mov pDispInfo, xax
        mov xbx, [xax].XTVN_DISP_INFO.pNode
        .if xbx != [xsi].pHotTrackedNode
          BitSet [xbx].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
          OCall xbx::XTreeViewNode.RenderContent, pDispInfo
          xchg xbx, [xsi].pHotTrackedNode
          .if xbx != NULL
            BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
            OCall xsi.GetDispInfo, xbx
            OCall xbx::XTreeViewNode.RenderContent, xax       ;Invalidates the content
          .endif
        .endif
      .else
        .if [xsi].pHotTrackedNode != NULL
          mov xbx, [xsi].pHotTrackedNode
          BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
          OCall xsi.GetDispInfo, xbx
          OCall xbx::XTreeViewNode.RenderContent, xax         ;Invalidates the content
          m2z [xsi].pHotTrackedNode
        .endif
      .endif

      .ifBitSet [xsi].dState, XTVS_DRAGGING
        OCall xsi.SetDragCursor, DWORD ptr wParam, DWORD ptr lParam
      .else
        invoke SetCursor, [xsi].hCursorArrow
      .endif
      jmp @@Exit

    .else
      .ifBitSet [xsi].dState, XTVS_DRAGGING
        invoke SetCursor, [xsi].hCursorNode           ;In case we have hCursorNo
      .else
        invoke ReleaseCapture
      .endif
      mov xbx, [xsi].pHotTrackedNode
      .if xbx != NULL
        BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
        OCall xsi.GetDispInfo, xbx
        OCall xbx::XTreeViewNode.RenderContent, xax
      .endif
      m2z [xsi].pHotTrackedNode
    .endif

@@Draw:
    OCall xsi.Draw
  .endif
@@Exit:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnMouseWheel
; Purpose:    Event handler for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.
; Notes:      1. if the <Control> key is pressed, the horizontal scrollbar is moved.
;             2. if the <Shift> key is pressed, the scrolling is acceleraed 4 times.

Method XTreeView.OnMouseWheel, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT

;  DbgText "XTreeView.OnMouseWheel"
  SetObject xsi
  .ifBitClr [xsi].dState, XTVS_LOCKED
    mov xax, wParam
    xor edx, edx
    sar eax, 16
    .if !ZERO?                                          ;Exit if no increment
      .if SIGN?                                         ;Is eax negative?
        dec edx                                         ;Sign extend edx for idiv
      .endif
      .ifBitSet WORD ptr [wParam], MK_SHIFT             ;Is <Shift> key pressed?
        mov ecx, 2                                      ;/120 * 15
      .else
        mov ecx, 8                                      ;/120 * 60
      .endif
      idiv ecx
      neg eax                                           ;Change sign to toggle scroll direction

      mov ecx, [xsi].TotalSize.x
      mov edx, [xsi].TotalSize.y
      .if (ecx > [xsi].ClientSize.x) && \
          ((WORD ptr [wParam] & MK_CONTROL) || (edx <= [xsi].ClientSize.y))
        mov ebx, ecx
        sub ecx, [xsi].ClientSize.x
        js @@Exit                                       ;Nothing to draw, avoid flicker
        add eax, [xsi].TotalOffset.x
        .if SIGN?                                       ;Is it negative?
          xor eax, eax                                  ;No negative values allowed!
        .else
          uMini eax, ecx, edx                           ;Limit to the upper value
        .endif
        mov ecx, ebx
        .if ecx != eax
          mov [xsi].TotalOffset.x, eax
        .else
          jmp @@Exit                                    ;Nothing to draw, avoid flicker
        .endif

      .else
        mov ebx, [xsi].TotalOffset.y
        sub edx, [xsi].ClientSize.y
        js @@Exit                                       ;Nothing to draw, avoid flicker
        add eax, [xsi].TotalOffset.y
        .if SIGN?
          xor eax, eax
        .else
          uMini eax, edx, ecx                           ;Limit to the upper value
        .endif

        OCall xsi.Find1stVisibleNode, eax
        mov eax, ebx
        .if eax == [xsi].TotalOffset.y
          jmp @@Exit                                    ;Nothing to draw, avoid flicker
        .endif
      .endif

      ;Manage the hottracked node
      mov xax, [xsi].pHotTrackedNode
      .if xax != NULL
        OCall xsi.GetDispInfo, xax
        .if xax != NULL
          mov xcx, [xax].XTVN_DISP_INFO.pNode
          BitClr [xcx].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
          m2z [xsi].pHotTrackedNode
          OCall xcx::XTreeViewNode.RenderContent, xax
        .endif
      .endif

      invoke GetCursorPos, addr CursorPos
      invoke ScreenToClient, [xsi].hWnd, addr CursorPos
      OCall [xsi].DispInfoColl::XWCollection.FirstThat, addr XTV_IsPointInContent, \
                                                        CursorPos.x, CursorPos.y
      .if xax != NULL
        mov xcx, [xax].XTVN_DISP_INFO.pNode
        BitSet [xcx].$Obj(XTreeViewNode).dState, XTVNS_HOTTRACK
        mov [xsi].pHotTrackedNode, xcx
        OCall xcx::XTreeViewNode.RenderContent, xax
      .else
        mov [xsi].pHotTrackedNode, xax
      .endif

      OCall xsi.Draw
    .endif
@@Exit:
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnNcDestroy
; Purpose:    Event handler for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnNcDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnNcDestroy"
  SetObject xsi
  .ifBitSet [xsi].dFlags, XTVF_RESOURCE
    invoke SetWindowLongPtr, [xsi].hWnd, GWLP_USERDATA, NULL
    Destroy xsi                                         ;Selfdestruction only if it was created
  .endif                                                ;  from a resource
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnNcHitTest
; Purpose:    Event handler for WM_NCHITTEST message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = DefWindowProc return value.

Method XTreeView.OnNcHitTest,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov [xcx].ArrowScrollValue.x, 1
  mov [xcx].ArrowScrollValue.y, 1
  invoke DefWindowProc, [xcx].hWnd, WM_NCHITTEST, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnPaint
; Purpose:    Event handler for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.
; NOte:       While processing this message, the schrollbars should not be changed. Otherwise a
;             WM_SIZE and a WM_PAINT are triggered, enterig in an endless loop.

Method XTreeView.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT

;  DbgText "XTreeView.OnPaint"
  SetObject xsi
  .ifBitSet [xsi].dState, XTVS_VISIBLE
    invoke GetUpdateRect, [xsi].hWnd, NULL, TRUE
    .if eax == 0                                        ;RedrawWindow with RDW_INTERNALPAINT flag
      OCall xsi.Draw                                    ;triggers a WM_PAINT without update rect
      invoke ValidateRect, [xsi].hWnd, NULL
    .else
      invoke BeginPaint, [xsi].hWnd, addr PS
      mov eax, PS.rcPaint.right
      sub eax, PS.rcPaint.left
      .if !ZERO?
        mov ebx, PS.rcPaint.bottom
        sub ebx, PS.rcPaint.top
        .if !ZERO?
          invoke BitBlt, PS.hdc, PS.rcPaint.left, PS.rcPaint.top, eax, ebx, \
                         [xsi].hMemDC, PS.rcPaint.left, PS.rcPaint.top, SRCCOPY
        .endif
      .endif
      invoke EndPaint, [xsi].hWnd, addr PS
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnPrintClient
; Purpose:    Event handler for WM_PRINTCLIENT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method XTreeView.OnPrintClient, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnPrintClient"
  SetObject xsi
  .ifBitSet lParam, PRF_CLIENT or PRF_CHECKVISIBLE
    .ifBitSet [xsi].dState, XTVS_VISIBLE
      invoke BitBlt, wParam, 0, 0, [xsi].ClientSize.x, [xsi].ClientSize.y, \
                     [xsi].hMemDC, 0, 0, SRCCOPY
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnRButtonDblClk
; Purpose:    Event handler for WM_RBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnRButtonDblClk,, wParam:WPARAM, lParam:LPARAM
  OCall xcx::XTreeView.OnButtonDblClk, MK_RBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnRButtonDown
; Purpose:    Event handler for WM_RBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnRButtonDown,, wParam:WPARAM, lParam:LPARAM
  OCall xcx::XTreeView.OnButtonDown, MK_RBUTTON, wParam, lParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnRButtonUp
; Purpose:    Event handler for WM_RBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnRButtonUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT

  SetObject xsi
  OCall xsi.OnButtonUp, MK_RBUTTON, wParam, lParam

  .ifBitClr [xsi].dState, XTVS_DRAGGING
    PntS2Pnt CursorPos, lParam
    OCall [xsi].DispInfoColl::XWCollection.FirstThat, addr XTV_IsPointInText, CursorPos.x, CursorPos.y
    .if xax != NULL
      mov xbx, xax
      invoke ClientToScreen, [xsi].hWnd, addr CursorPos
      OCall [xbx].XTVN_DISP_INFO.pNode::XTreeViewNode.ContextPopup, CursorPos.x, CursorPos.y
    .endif
  .endif

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnSetFocus
; Purpose:    Event handler for WM_SETFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnSetFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnSetFocus"
  SetObject xsi
  BitSet [xsi].dState, XTVS_FOCUSED
  .if [xsi].pSelectedNode != NULL
    OCall xsi.GetDispInfo, [xsi].pSelectedNode
    OCall [xsi].pSelectedNode::XTreeViewNode.RenderContent, xax
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnSetFont
; Purpose:    Event handler for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method XTreeView.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnSetFont"
  SetObject xsi
  .if [xsi].hFontText != 0
    invoke DeleteObject, [xsi].hFontText
    m2m [xsi].hFontText, wParam, xax
  .endif
  .if lParam != 0
    OCall xsi.Draw
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnSetRedraw
; Purpose:    Event handler for WM_SETREDRAW message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XTreeView.OnSetRedraw,, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnSetRedraw"
  SetObject xcx
  .if wParam == FALSE
    BitSet [xcx].dState, XTVS_LOCKED
  .else
    BitClr [xcx].dState, XTVS_LOCKED
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnSettingChange
; Purpose:    Event handler for WM_SETTINGCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Always zero (handled).

Method XTreeView.OnSettingChange, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnSettingChange"
  SetObject xsi
  ACall xsi.OnSettingChange, wParam, lParam             ;Forward WM_SETTINGCHANGE to child windows
  OCall xsi.GetMetrics
  OCall xsi.CreateBackBuffer
  OCall xsi.Draw
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnSize
; Purpose:    Event handler for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled, otherwise -1.

Method XTreeView.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnSize"
  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    PntS2Pnt [xsi].ClientSize, lParam
    OCall xsi.GetMetrics
    OCall xsi.CreateBackBuffer

    ;Check if TotalOffset.y has still a valid value
    mov eax, [xsi].TotalSize.y
    sub eax, [xsi].ClientSize.y
    .if SIGN?
      OCall xsi.Set1stVisibleNode, [xsi].pFirstChild    ;Move the first node on top of the view
      m2z [xsi].TotalOffset.y
      m2z [xsi].dFirstOffset
    .elseif eax < [xsi].TotalOffset.y
      OCall xsi.Find1stVisibleNode, eax                 ;Reposition the window content
    .endif

    ;Check if TotalOffset.x has still a valid value
    mov eax, [xsi].TotalSize.x
    sub eax, [xsi].ClientSize.x
    .if SIGN?
      m2z [xsi].TotalOffset.x
    .elseif eax < [xsi].TotalOffset.x
      mov [xsi].TotalOffset.x, eax                      ;Reposition the window content
    .endif

    invoke InvalidateRect, [xsi].hWnd, NULL, FALSE      ;Invalidate complete client area

    xor eax, eax
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnSysColorChange
; Purpose:    Event handler for WM_SYSCOLORCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.
; Note:       If the application has brushes using the existing system colors, it should delete
;             those brushes and recreate them using the new system colors.

Method XTreeView.OnSysColorChange, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnSysColorChange"
  SetObject xsi
  ACall xsi.OnSysColorChange, wParam, lParam            ;Inform child windows
  OCall xsi.Draw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.OnVScroll
; Purpose:    Event handler for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XTreeView.OnVScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XTreeView.OnVScroll"
  SetObject xsi
  .ifBitClr [xsi].dState, XTVS_LOCKED
    mov xax, wParam
    .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
      shr eax, 16                                       ;Get high part of eax
      mov ecx, [xsi].TotalSize.y
      mul ecx
      mov ecx, 0FFFFh
      div ecx
      mov ecx, [xsi].TotalSize.y
      sub ecx, [xsi].ClientSize.y
      .if eax > ecx
        mov eax, ecx
      .endif

    .elseif ax == SB_LINEUP
      mov edx, [xsi].ArrowScrollValue.y
      .if edx < [xsi].TotalOffset.y
        mov eax, [xsi].TotalOffset.y
        sub eax, edx
        inc [xsi].ArrowScrollValue.y
      .else
        xor eax, eax
      .endif

    .elseif ax == SB_LINEDOWN
      mov edx, [xsi].ArrowScrollValue.y
      mov eax, [xsi].TotalSize.y
      sub eax, [xsi].ClientSize.y
      mov ecx, eax
      sub ecx, edx
      .if SDWORD ptr ecx > [xsi].TotalOffset.y
        mov eax, [xsi].TotalOffset.y
        add eax, edx
        inc [xsi].ArrowScrollValue.y
      .endif

    .elseif ax == SB_PAGEUP
      mov edx, [xsi].ClientSize.y
      .if edx < [xsi].TotalOffset.y
        mov eax, [xsi].TotalOffset.y
        sub eax, edx
      .else
        xor eax, eax
      .endif

    .elseif ax == SB_PAGEDOWN
      mov edx, [xsi].ClientSize.y
      mov eax, [xsi].TotalSize.y
      sub eax, edx
      mov ecx, eax
      sub ecx, edx
      .if SDWORD ptr ecx > [xsi].TotalOffset.y
        mov eax, [xsi].TotalOffset.y
        add eax, edx
      .endif

    .else
      jmp @@Exit                                        ;Unrecognized message
    .endif

    OCall xsi.Find1stVisibleNode, eax
    OCall xsi.Draw
  .endif
@@Exit:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Remove
; Purpose:    Remove an inserted node from the XTreeiew.
; Arguments:  Arg1: -> to the node to remove.
; Return:     xax -> removed node.

Method XTreeView.Remove, uses xbx xdi xsi, pNode:$ObjPtr(XTreeViewNode)
  local dHeight:DWORD

  SetObject xsi
  .if pNode != NULL

    ;Manage the selected node if it is in the deleted branch
    mov xcx, pNode
    .ifBitSet [xcx].$Obj(XTreeViewNode).dState, XTVNS_SEL_PATH
      .if [xcx].$Obj(XTreeViewNode).pNextSibling != NULL
        mov xax, [xcx].$Obj(XTreeViewNode).pNextSibling
      .elseif [xcx].$Obj(XTreeViewNode).pPrevSibling != NULL
        mov xax, [xcx].$Obj(XTreeViewNode).pPrevSibling
      .else
        mov xax, [xcx].$Obj(XTreeViewNode).pParent
      .endif
      OCall xsi.Select, xax
    .endif

    ;Manage the first node in view
    mov xcx, pNode
    .ifBitSet [xcx].$Obj(XTreeViewNode).dState, XTVNS_VIS_PATH
      .if [xcx].$Obj(XTreeViewNode).pPrevSibling != NULL
        mov xax, [xcx].$Obj(XTreeViewNode).pPrevSibling
      .elseif [xcx].$Obj(XTreeViewNode).pParent != NULL
        mov xax, [xcx].$Obj(XTreeViewNode).pParent
      .else
        mov xax, [xcx].$Obj(XTreeViewNode).pNextSibling
      .endif
      OCall xsi.Set1stVisibleNode, xax
    .endif

    ;Remove the node
    mov xax, pNode
    .if [xax].$Obj(XTreeViewNode).pParent == NULL
      mov xdx, [xax].$Obj(XTreeViewNode).pPrevSibling
      mov xcx, [xax].$Obj(XTreeViewNode).pNextSibling
      .if xdx != NULL
        mov [xdx].$Obj(XTreeViewNode).pNextSibling, xcx
      .else
        mov [xsi].$Obj(XTreeView).pFirstChild, xcx
      .endif
      mov xdx, [xax].$Obj(XTreeViewNode).pPrevSibling
      .if xcx != NULL
        mov [xcx].$Obj(XTreeViewNode).pPrevSibling, xdx
      .else
        mov [xsi].$Obj(XTreeView).pLastChild, xdx
      .endif

    .else
      mov xcx, [xax].$Obj(XTreeViewNode).pParent
      mov xdx, [xax].$Obj(XTreeViewNode).pPrevSibling
      mov xbx, [xax].$Obj(XTreeViewNode).pNextSibling
      .if xdx != NULL
        mov [xdx].$Obj(XTreeViewNode).pNextSibling, xbx
      .else
        mov [xcx].$Obj(XTreeViewNode).pFirstChild, xbx
      .endif
      mov xdx, [xax].$Obj(XTreeViewNode).pPrevSibling
      .if xbx != NULL
        mov [xbx].$Obj(XTreeViewNode).pPrevSibling, xdx
      .else
        mov [xcx].$Obj(XTreeViewNode).pLastChild, xdx
      .endif

    .endif
    ;xax -> deleted node

    ;Calc new branch values in the modified path
    mov xdi, [xax].$Obj(XTreeViewNode).pParent
    mov ecx, [xax].$Obj(XTreeViewNode).dHeight
    .if XTV_IsExpanded(xax)
      add ecx, [xax].$Obj(XTreeViewNode).dBranchHeight
    .endif

    mov dHeight, ecx
    .while (xdi != NULL) && ([xdi].$Obj(XTreeViewNode).dState & XTVNS_EXPANDED)
      mov ecx, dHeight
      sub [xdi].$Obj(XTreeViewNode).dBranchHeight, ecx
      XTV_GetBranchMaxWidth [xdi].$Obj(XTreeViewNode).pFirstChild, xsi
      mov [xdi].$Obj(XTreeViewNode).dBranchWidth, ebx
      mov xdi, [xdi].$Obj(XTreeViewNode).pParent        ;Move one level up
    .endw

    .if xdi == NULL                                     ;Did we reach the root node?
      mov ecx, dHeight
      sub [xsi].TotalSize.y, ecx

      XTV_GetBranchMaxWidth [xsi].pFirstChild, xsi
      add ebx, [xsi].dNodeIndent
      add ebx, [xsi].ClientOffset.x
      mov [xsi].TotalSize.x, ebx
    .endif

    ;Check if the HotTracked Node was within the deleted branch
    mov xax, pNode                                      ;Return value
    mov xcx, [xsi].pHotTrackedNode
    .while xax != NULL && xax != xcx
      mov xax, [xax].$Obj(XTreeViewNode).pParent
    .endw
    .if xax != NULL
      m2z [xsi].pHotTrackedNode
    .endif

    mov xax, pNode                                      ;Return value

  .else
    OCall xsi.ErrorReport, NULL, XTV_INVALID_POINTER
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.RenderBackground
; Purpose:    Draw the background of a specified rect.
; Arguments:  Arg1: -> RECT to fill.
; Return:     Nothing.

Method XTreeView.RenderBackground, uses xbx xsi, pRect:PRECT
  SetObject xsi
  .ifBitSet [xsi].dFlags, XTVF_USE_USER_BKGND_COLOR
    mov eax, [xsi].dColorBackground
  .else
    invoke GetSysColor, COLOR_WINDOW
  .endif
  invoke CreateSolidBrush, eax
  mov xbx, xax
  invoke FillRect, [xsi].hMemDC, pRect, xax
  invoke DeleteObject, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Reset
; Purpose:    Remove the complete content of the tree.
; Arguments:  None.
; Return:     Nothing.

Method XTreeView.Reset, uses xsi
  SetObject xsi
  OCall [xsi].DispInfoColl::XWCollection.DeleteAll
  OCall [xsi].DispInfoPool::DataPool.Reset
  xor eax, eax
  mov [xsi].pFirstVisibleNode, xax
  mov [xsi].pSelectedNode, xax
  mov [xsi].dFirstOffset, eax
  mov [xsi].TotalSize.x, eax
  mov [xsi].TotalSize.y, eax
  mov [xsi].TotalOffset.x, eax
  mov [xsi].TotalOffset.y, eax
  mov [xsi].pFirstChild, xax
  mov [xsi].pLastChild, xax
  mov [xsi].pHotTrackedNode, xax
  OCall xsi.Draw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Select
; Purpose:    Select a new node.
; Arguments:  Arg1: -> Node to be selected. NULL is allowed.
; Return:     Nothing.

Method XTreeView.Select,, pNode:$ObjPtr(XTreeViewNode)
;  DbgText "XTreeView.Select"
  SetObject xax
  ?mov xdx, pNode
  mov xcx, [xax].pSelectedNode
  .if xcx != xdx
    mov [xax].pSelectedNode, xdx
    .while xcx != NULL
      BitClr [xcx].$Obj(XTreeViewNode).dState, XTVNS_SEL_PATH
      mov xcx, [xcx].$Obj(XTreeViewNode).pParent
    .endw
    .while xdx != NULL
      BitSet [xdx].$Obj(XTreeViewNode).dState, XTVNS_SEL_PATH
      mov xdx, [xdx].$Obj(XTreeViewNode).pParent
    .endw
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Set1stVisibleNode
; Purpose:    Set the first visible node and marks the path to it, resetting the prevoius.
;             NULL is allowed.
; Arguments:  Arg1: -> Node to be selected.
; Return:     Nothing.

Method XTreeView.Set1stVisibleNode,, pNode:$ObjPtr(XTreeViewNode)
  SetObject xax
  ?mov xdx, pNode
  mov xcx, [xax].pFirstVisibleNode
  mov [xax].pFirstVisibleNode, xdx
  .while xcx != NULL
    BitClr [xcx].$Obj(XTreeViewNode).dState, XTVNS_VIS_PATH
    mov xcx, [xcx].$Obj(XTreeViewNode).pParent
  .endw
  .while xdx != NULL
    BitSet [xdx].$Obj(XTreeViewNode).dState, XTVNS_VIS_PATH
    mov xdx, [xdx].$Obj(XTreeViewNode).pParent
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.SetDragCursor
; Purpose:    While dragging, set the cursor over a hottracked node.
; Arguments:  Arg1: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
;             Arg2: Cursor position.
; Return:     Nothing.

Method XTreeView.SetDragCursor, uses xsi, dKeyFlags:DWORD, CursorPos:DWORD
  SetObject xsi
  mov xcx, [xsi].pHotTrackedNode
  .if xcx == [xsi].pSelectedNode
    invoke SetCursor, [xsi].hCursorNo
  .else
    .if xcx != NULL
      OCall xcx::XTreeViewNode.CanDropHere, [xsi].pSelectedNode, dKeyFlags, CursorPos
    .else
      OCall xsi.CanDropHere, [xsi].pSelectedNode, dKeyFlags, CursorPos
    .endif
    .if eax == XTVN_INSERT_NOT_ALLOWED
      .if [xsi].pHotTrackedNode == NULL
        mov xdx, [xsi].hCursorNode
      .else
        mov xdx, [xsi].hCursorNo
      .endif
    .elseif eax == XTVN_INSERT_AS_FIRST_CHILD
      mov xdx, [xsi].hCursorFirst
    .elseif eax == XTVN_INSERT_AS_LAST_CHILD
      mov xdx, [xsi].hCursorLast
    .elseif eax == XTVN_INSERT_AS_PREV_SIBLING
      mov xdx, [xsi].hCursorPrev
    .elseif eax == XTVN_INSERT_AS_NEXT_SIBLING
      mov xdx, [xsi].hCursorNext
    .else
      mov xdx, [xsi].hCursorNode
    .endif
    invoke SetCursor, xdx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.ShowScrollbars
; Purpose:    Show or hide the scrollbars and update the ClientSize member.
; Arguments:  None.
; Return:     Nothing.

Method XTreeView.ShowScrollbars, uses xsi
  local dHorzShow:DWORD, dVertShow:DWORD

;  DbgText "ShowScrollbars"
  SetObject xsi
  xor ecx, ecx
  mov dHorzShow, ecx
  mov dVertShow, ecx

  mov eax, [xsi].DrawSize.y
  sub eax, [xsi].TotalSize.y
  sets BYTE ptr dVertShow
  mov eax, [xsi].DrawSize.x
  .if SIGN?
    sub eax, [xsi].ScrollbarMetric.x
  .endif
  mov [xsi].ClientSize.x, eax

  sub eax, [xsi].TotalSize.x
  sets BYTE ptr dHorzShow
  mov eax, [xsi].DrawSize.y
  .if SIGN?
    sub eax, [xsi].ScrollbarMetric.y
  .endif
  mov [xsi].ClientSize.y, eax

  .if dHorzShow != FALSE && dVertShow == FALSE
    sub eax, [xsi].TotalSize.y
    sets BYTE ptr dVertShow
    mov eax, [xsi].DrawSize.x
    .if SIGN?
      sub eax, [xsi].ScrollbarMetric.x
    .endif
    mov [xsi].ClientSize.x, eax
  .endif

  invoke ShowScrollBar, [xsi].hWnd, SB_VERT, dVertShow
  invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, dHorzShow
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.Startup
; Purpose:    Register the XTreeView window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method XTreeView.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_PARENTDC or CS_BYTEALIGNWINDOW or \
                CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(XTreeView.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset cXTV_ClassName, xax
  m2z WC.hIcon

  mov WC.hCursor, $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_ARROW"))
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XTreeView.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method XTreeView.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "XTreeView Messages"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(XTreeView)
      OCall xsi::XTreeView.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(XTreeView).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::XTreeView.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA     ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                   ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::XTreeView.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

;##/

endif
