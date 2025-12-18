; ==================================================================================================
; Title:      XPropertyTree.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm XPropertyTree object.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Due to timing problems (WM_PAINT) in the implementation if ComboBox, it is not 
;                 reused like other controls. Instead it is recreated each time it is needed.
; ==================================================================================================


XPT_ICON_SIZE                 equ   16
XPT_COLOR_RECT_SIZE           equ   12
XPT_MARGIN                    equ   03
XPT_FONT_SIZE_CAT             equ   10
XPT_FONT_SIZE_PROP            equ   10
XPT_COMBOBOX_SIZE             equ   500
XPT_CONTROL_ID_EDIT           equ   120
XPT_CONTROL_ID_BUTTON         equ   121
XPT_CONTROL_ID_COMBOBOX       equ   122

XPT_FLAGS                     equ   XTVF_SHOW_TOGGLER

XPT_VAR_TYPE_CUSTOM           equ   0             ;pOptions -> Validating procedure or NULL
XPT_VAR_TYPE_STRING           equ   1             ;pOptions = Max. string size including the ZTC
XPT_VAR_TYPE_INTEGER          equ   2             ;pOptions -> Validating procedure or NULL
XPT_VAR_TYPE_REAL4            equ   3             ;pOptions -> Validating procedure or NULL
XPT_VAR_TYPE_COLOR            equ   4             ;pOptions -> CHOOSECOLOR
XPT_VAR_TYPE_SYS_COLOR        equ   5             ;pOptions -> NULL
XPT_VAR_TYPE_FILE             equ   6             ;pOptions -> OPENFILENAME
XPT_VAR_TYPE_PATH             equ   7             ;pOptions -> BROWSEINFO
XPT_VAR_TYPE_LIST             equ   8             ;pOptions -> Double zero terminated string list

XPT_ValidateProc typedef proto :HWND              ;Edit control HANDLE


XPTN_DISP_INFO struc                              ;Extend the XTVN_DISP_INFO structure
              XTVN_DISP_INFO  {}                  ;Anonymous definition
  IconRect    RECT            {}                  ;RECT structure for the node icon
  CaptionRect RECT            {}                  ;RECT structure for the node caption
  ButtonRect  RECT            {}                  ;RECT struc for the control on the right side
XPTN_DISP_INFO ends                               ;   of the node
PXPTN_DISP_INFO typedef ptr XPTN_DISP_INFO

XPT_CTRLDEF struc
  xCtlID      XWORD           ?                   ;Contol ID
  dStyle      DWORD           ?                   ;Style
  dExStyle    DWORD           ?                   ;Extended style
  pTitle      PSTRING         ?                   ;-> Window caption
  sdPosX      SDWORD          ?                   ;X position
  sdPosY      SDWORD          ?                   ;Y position
  dWidth      DWORD           ?                   ;Width
  dHeight     DWORD           ?                   ;Height
XPT_CTRLDEF ends
PXPT_CTRLDEF typedef ptr XPT_CTRLDEF

Object XPT_Edit, XPT_EditID, WinControl
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PXPT_CTRLDEF
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnKeyDown,          WM_KEYDOWN
ObjectEnd

Object XPT_Button, XPT_ButtonID, WinControl
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PXPT_CTRLDEF
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnKeyDown,          WM_KEYDOWN
ObjectEnd

XPTCB_ESCAPING    equ   BIT00

Object XPT_ComboBox, XPT_ComboBoxID, WinControl
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PXPT_CTRLDEF
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnKeyDown,          WM_KEYDOWN

  DefineVariable    dState,             DWORD,        0
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  XPropertyTree
; Purpose: Implement a Customized XTreeView and XTreeViewNode to show and edit properties.
;
; Features:
; --------
; - Same as XTreeView.
; - Support for strings/32 bit integers/REAL4 floating point numbers/paths/files/colors and
;   customized input.
;
; Some rules:
; ----------
;  1. See XTreeView object rules (XTreeView.inc).
;  2. Each node (Category or Property) need to be created, initialized and finally inserted.
;       New XPT_PropertyNode, Init, pOwner, hIcon, "Description", dHeight, XTVNS_EXPANDED, \
;           pVariable, dNodeType, dOptions
;       OCall xbx::XPropertyTree.Insert, eax, pCategoryNode, XTVN_INSERT_AS_LAST_CHILD
;  3. Property nodes of type XPT_VAR_TYPE_CUSTOM passes an address to a customization procedure.
;  4. Property nodes of type XPT_VAR_TYPE_STRING passes the max string size including the
;     terminating zero.
;  5. Property nodes of type XPT_VAR_TYPE_INTEGER and XPT_VAR_TYPE_REAL4 passes an address
;     to a validating/range filter procedure.
;  6. Property nodes of type XPT_VAR_TYPE_COLOR passes a CHOOSECOLOR structure. Following
;     members must be initialized before call: hInstance, Flags, lCustData, lpfnHook,
;     lpTemplateName.
;  7. Property nodes of type XPT_VAR_TYPE_FILE passes a OPENFILENAME structure. Following
;     members must be initialized before call: hInstance, lpstrFilter, lpstrCustomFilter,
;     nMaxCustFilter, nFilterIndex, lpstrFile, nMaxFile, lpstrFileTitle, nMaxFileTitle,
;     lpstrInitialDir, lpstrTitle, Flags, lpstrDefExt.
;     ComDlg32 library must be loaded.
;  8. Property nodes of type XPT_VAR_TYPE_PATH passes a BROWSEINFO structure. Following
;     members must be initialized before call: pidlRoot, lpszTitle, ulFlags.
;     Ole32 library must be loaded.
;  9. Property nodes of type XPT_VAR_TYPE_LIST passes a doble zero terminating string
;     options list.
; 10. All other property nodes don't pass any argument.

Object XPropertyTree, XPropertyTreeID, XTreeView
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PDEF_XTV
  RedefineMethod    Draw
  RedefineMethod    OnCreate,           WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnKeyDown,          WPARAM, LPARAM
  RedefineMethod    OnMouseWheel,       WPARAM, LPARAM
  RedefineMethod    OnSize,             WPARAM, LPARAM
  RedefineMethod    OnVScroll,          WPARAM, LPARAM
  RedefineMethod    RenderBackground,   PRECT
  RedefineMethod    Startup                                           ;Register new wnd class
  RedefineMethod    ShowScrollbars
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM         ;Create new wnd class

  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnDrawItem,         WM_DRAWITEM
  VirtualEvent      OnMeasureItem,      WM_MEASUREITEM

  RedefineVariable  dDispInfoSize,      sizeof XPTN_DISP_INFO         ;Extended structure
  RedefineVariable  dFlags,             XPT_FLAGS
  RedefineVariable  dNodeIndent,        12                            ;Pixel
;  RedefineVariable  ColorBackground,                $RGB(128,128,128)
;  DefineVariable    ColorBackgroundDark,COLORREF,   $RGB(255,255,255)
  RedefineVariable  ColorBackground,                $RGB(245,245,245)
  DefineVariable    ColorBackgroundDark,COLORREF,   $RGB(220,220,220)
  DefineVariable    hPenAux,            HPEN,       0

  DefineVariable    pEdtCtrl,           $ObjPtr(XPT_Edit),      NULL  ;-> EDIT control object
  DefineVariable    pBtnCtrl,           $ObjPtr(XPT_Button),    NULL  ;-> BUTTON control object
  DefineVariable    pCBxCtrl,           $ObjPtr(XPT_ComboBox),  NULL  ;-> COMBOBOX control object
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  XPT_CategoryNode
; Purpose: Implement a grouping node of related properties.

Object XPT_CategoryNode, XPT_CategoryNodeID, XTreeViewNode
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HICON, PSTRING, DWORD, DWORD
  RedefineMethod    CanDragMe,          DWORD
  RedefineMethod    MouseHit,           DWORD, PPOINT, PXPTN_DISP_INFO, DWORD
  RedefineMethod    MouseHitDbl,        DWORD, PPOINT, PXPTN_DISP_INFO, DWORD
  RedefineMethod    Render,             PXPTN_DISP_INFO
  RedefineMethod    RenderContent,      PXPTN_DISP_INFO

  RedefineVariable  dState,             XTVNS_DISABLED                ;Default
  DefineVariable    hIcon,              HICON,       0
  DefineVariable    pCaption,           PSTRING,     NULL
  DefineVariable    hFont,              HFONT,       0
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  XPT_PropertyNode
; Purpose: Implement a property node.
;
; Node layout
; -----------
;                                           ContentRect(*)
;   -----------------------------------------------------------------
;  |       |      |      |     ------------------------------------- |
;  |       |      |      |    | ----------------------------------- ||
;  |       |      |      |    ||      |         |            ------ ||
;  |       |      |     [-]---|| Icon | Caption | Text(**)  |Button|||
;  |       |      |           ||      |         |            ------ ||
;  |       |      |   Toggler | ----------------------------------- ||
;  |       |      |    Rect    ------------------------------------- |
;   -----------------------------------------------------------------
;
; Note: (*) structures contained in XTVN_DISP_INFO
;       (**) Button is contained in Text
;

Object XPT_PropertyNode, XPT_PropertyNodeID, XTreeViewNode
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HICON, PSTRING, DWORD, DWORD, DWORD, POINTER, \
                                        DWORD, POINTER
  RedefineMethod    CanDragMe,          DWORD
  RedefineMethod    MouseHit,           DWORD, PPOINT, PXPTN_DISP_INFO, DWORD
  RedefineMethod    MouseHitDbl,        DWORD, PPOINT, PXPTN_DISP_INFO, DWORD
  RedefineMethod    Render,             PXPTN_DISP_INFO
  RedefineMethod    RenderContent,      PXPTN_DISP_INFO

  DefineVariable    hIcon,              HICON,        0
  DefineVariable    hFont,              HFONT,        0
  DefineVariable    dFontHeight,        DWORD,        0
  DefineVariable    dFontAveWidth,      DWORD,        0
  DefineVariable    pCaption,           PSTRING,      NULL
  DefineVariable    pVariable,          POINTER,      NULL
  DefineVariable    dVarType,           DWORD,        XPT_VAR_TYPE_CUSTOM    ;XPT_VAR_TYPE_...
  DefineVariable    pOptions,           POINTER,      NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

ExterndefMethod pepe::DisplayInfoColl.DestroyItem

.data
XPT_LogFontText LOGFONT <0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, \
                         OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, \
                         DEFAULT_PITCH or FF_DONTCARE, {"A","R","I","A","L",0}>

.const
String cClassNameXPT,     "XPropertyTree"
String cInvalidSelection, "Invalid selection"

XPT_SYS_COLOR_ENTRY struc sizeof(XWORD)
  dSystemIndex    DWORD       ?                         ;System color index
  pDescription    POINTER     ?                         ;-> System element that uses this color
XPT_SYS_COLOR_ENTRY ends

XPT_SYS_COLOR_TABLE_EN_BEG \
XPT_SYS_COLOR_ENTRY <00, $OfsTStr("Scrollbar")>
XPT_SYS_COLOR_ENTRY <01, $OfsTStr("Background / Desktop")>
XPT_SYS_COLOR_ENTRY <02, $OfsTStr("Active caption")>
XPT_SYS_COLOR_ENTRY <03, $OfsTStr("Inactive caption")>
XPT_SYS_COLOR_ENTRY <04, $OfsTStr("Menu")>
XPT_SYS_COLOR_ENTRY <05, $OfsTStr("Window")>
XPT_SYS_COLOR_ENTRY <06, $OfsTStr("Window frame")>
XPT_SYS_COLOR_ENTRY <07, $OfsTStr("Menu text")>
XPT_SYS_COLOR_ENTRY <08, $OfsTStr("Window text")>
XPT_SYS_COLOR_ENTRY <09, $OfsTStr("Caption text")>
XPT_SYS_COLOR_ENTRY <10, $OfsTStr("Active border")>
XPT_SYS_COLOR_ENTRY <11, $OfsTStr("Inactive border")>
XPT_SYS_COLOR_ENTRY <12, $OfsTStr("App workspace")>
XPT_SYS_COLOR_ENTRY <13, $OfsTStr("Highlight")>
XPT_SYS_COLOR_ENTRY <14, $OfsTStr("Highlight text")>
XPT_SYS_COLOR_ENTRY <15, $OfsTStr("Button face / 3D face")>
XPT_SYS_COLOR_ENTRY <16, $OfsTStr("Button shadow / 3D shadow")>
XPT_SYS_COLOR_ENTRY <17, $OfsTStr("Gray text")>
XPT_SYS_COLOR_ENTRY <18, $OfsTStr("Button text")>
XPT_SYS_COLOR_ENTRY <19, $OfsTStr("Inactive caption text")>
XPT_SYS_COLOR_ENTRY <20, $OfsTStr("3D highlight / Button highlight")>
XPT_SYS_COLOR_ENTRY <21, $OfsTStr("3D dark shadow")>
XPT_SYS_COLOR_ENTRY <22, $OfsTStr("3D light")>
XPT_SYS_COLOR_ENTRY <23, $OfsTStr("Info text")>
XPT_SYS_COLOR_ENTRY <24, $OfsTStr("Info background")>
;XPT_SYS_COLOR_ENTRY <25, NULL)>                        ;DOES NOT EXIST
XPT_SYS_COLOR_ENTRY <26, $OfsTStr("Hot light")>
XPT_SYS_COLOR_ENTRY <27, $OfsTStr("Gadient active caption")>
XPT_SYS_COLOR_ENTRY <28, $OfsTStr("Gadient inactive caption")>
XPT_SYS_COLOR_ENTRY <29, $OfsTStr("Menu highlight")>
XPT_SYS_COLOR_ENTRY <30, $OfsTStr("Menubar")>
XPT_SYS_COLOR_TABLE_EN_END label XWORD


.code

; ==================================================================================================
;     XPT_CategoryNode
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.Done
; Purpose:    Finalize the XPT_CategoryNode object and all childs in its branch.
; Arguments:  None.
; Return:     Nothing.

Method XPT_CategoryNode.Done, uses xsi
  ;DbgText "XPT_CategoryNode.Done"
  SetObject xsi
  .if [xsi].hFont != 0
    invoke DeleteObject, [xsi].hFont
  .endif
  .if [xsi].hIcon != 0
    invoke DestroyIcon, [xsi].hIcon
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.Init
; Purpose:    Initialize a XPT_CategoryNode object.
; Arguments:  Arg1: -> Owner object, XTreeView.
;             Arg2: Icon HANDLE.
;             Arg2: -> Node Text. Must remain valid for the lifetime of the object instance.
;             Arg3: Node height.
;             Arg4: Node state (XTVNS_DISABLED, XTVNS_EXPANDED, etc.
; Return:     Nothing.

Method XPT_CategoryNode.Init, uses xdi xsi, pOwner:POINTER, hIcon:HICON, pCaption:PSTRING, \
                                            dHeight:DWORD, dState:DWORD
  local hDC:HDC

  SetObject xsi
  ACall xsi.Init, pOwner, 0, dHeight, dState
  m2m [xsi].hIcon, hIcon, xax
  m2m [xsi].pCaption, pCaption, xcx

  ;Create the text font
  mov xdi, [xsi].pOwner
  mov hDC, $invoke(GetDC, [xdi].$Obj(XPropertyTree).hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, XPT_FONT_SIZE_CAT, eax, -72
  mov XPT_LogFontText.lfHeight, eax
  mov XPT_LogFontText.lfWeight, FW_BOLD
  mov [xsi].hFont, $invoke(CreateFontIndirect, offset XPT_LogFontText)
  invoke ReleaseDC, [xdi].$Obj(XPropertyTree).hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.CanDragMe
; Purpose:    Indicate if a drag operation can be started.
; Arguments:  Arg1: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = Always FALSE => no dragging allowed.

Method XPT_CategoryNode.CanDragMe,, dKeyFlags:DWORD
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.MouseHit
; Purpose:    Check if the mouse has clicked a hotspot and perform an action.
; Arguments:  Arg1: button that triggered this action.
;             Arg2: -> clicked point.
;             Arg3: -> XPTN_DISP_INFO.
;             Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = TRUE if and action was triggered, otherwise FALSE.

Method XPT_CategoryNode.MouseHit, uses xbx xsi, dButton:DWORD, pPoint:PPOINT, \
                                                pDispInfo:PXPTN_DISP_INFO, dKeyFlags:DWORD
  local pSelNode:$ObjPtr(XPT_CategoryNode), pSelNodeDispInfo:PXPTN_DISP_INFO

  SetObject xsi
  SetObject xbx, XPropertyTree, [xsi].pOwner
  .if ([xbx].dState & XTVS_DISABLED) || ([xsi].dState & XTVNS_DISABLED)
    .if xsi != [xbx].pSelectedNode
      mrm pSelNode, [xbx].pSelectedNode, xax
      .if xax != NULL
        mov pSelNodeDispInfo, $OCall(xbx::XTreeView.GetDispInfo, xax)
      .endif
      OCall xbx::XTreeView.Select, xsi
      OCall xsi.RenderContent, pDispInfo
      .if pSelNode != NULL
        OCall pSelNode::XTreeViewNode.RenderContent, pSelNodeDispInfo
      .endif
    .endif
    xor eax, eax
  .else
    ACall xsi.MouseHit, dButton, pPoint, pDispInfo, dKeyFlags
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.MouseHitDbl
; Purpose:    Check if the mouse has double clicked a hotspot and perform an action. In this case,
;             the node is toggled.
; Arguments:  Arg1: Button that triggered this action.
;             Arg2: -> clicked point.
;             Arg3: -> XPTN_DISP_INFO.
;             Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = TRUE if and action was triggered, otherwise FALSE.

Method XPT_CategoryNode.MouseHitDbl, uses xbx xsi, dButton:DWORD, pPoint:PPOINT, \
                                                   pDispInfo:PXPTN_DISP_INFO, dKeyFlags:DWORD
  SetObject xsi
  SetObject xbx, XPropertyTree, [xsi].pOwner
  .if !(([xbx].dState & XTVS_DISABLED) || ([xsi].dState & XTVNS_DISABLED))
    OCall xsi.Toggle
    OCall xbx.Draw
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.Render
; Purpose:    Draw the complete node.
; Arguments:  Arg1: -> XPTN_DISP_INFO.
; Return:     Nothing.

Method XPT_CategoryNode.Render,, pDispInfo:PXPTN_DISP_INFO
  ;DbgText "XPT_CategoryNode.Render"
  SetObject xcx
  SetObject xax, XPropertyTree, [xcx].pOwner
  m2m [xcx].dWidth, [xax].ClientSize.x, edx
  ACall xcx.Render, pDispInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_CategoryNode.RenderContent
; Purpose:    Draws the content (icon + caption) of the node.
; Arguments:  Arg1: -> XPTN_DISP_INFO
; Return:     Nothing.
; Note:       This method must update the coords of all Rect structures in the Content and must
;             invalidate the modified region.

Method XPT_CategoryNode.RenderContent, uses xbx xdi xsi, pDispInfo:PXPTN_DISP_INFO
  local dPrevColor:DWORD, dPrevBkColor:DWORD, dPrevBkMode:DWORD, InvRect:RECT, hPrevFont:HFONT

  ;DbgText "XPT_CategoryNode.RenderContent"
  mov xdi, pDispInfo
  .if xdi != NULL
    SetObject xsi
    SetObject xbx, XPropertyTree, [xsi].pOwner
    assume xdi:PXPTN_DISP_INFO
    m2m [xdi].TextRect.left, [xdi].ContentRect.left, eax
    m2m [xdi].TextRect.right, [xdi].ContentRect.right, ecx

    ;Get the drawing rect
    CloneRect InvRect, [xdi].ContentRect

    ;Render the background
    OCall xbx::XPropertyTree.RenderBackground, addr InvRect

    ;Calc icon position
    mov ecx, [xdi].ContentRect.bottom
    sub ecx, [xdi].ContentRect.top
    sub ecx, XPT_ICON_SIZE
    shr ecx, 1
    mov eax, [xdi].ContentRect.bottom
    sub eax, ecx
    sub eax, XPT_ICON_SIZE
    mov [xdi].IconRect.top, eax                     ;ecx = Icon top

    mov edx, [xdi].ContentRect.left
    add edx, XPT_MARGIN                             ;edx = Icon left
    mov ecx, edx
    add ecx, XPT_MARGIN
    add ecx, XPT_ICON_SIZE
    mov [xdi].TextRect.left, ecx                    ;TextRect.left

    ;Render the icon
    invoke DrawIconEx, [xbx].hMemDC, edx, eax, [xsi].hIcon, \
                       XPT_ICON_SIZE, XPT_ICON_SIZE, NULL, NULL, DI_NORMAL

    ;Set text and background colors
    .if xsi == [xbx].pSelectedNode
      .if ([xbx].dState & XTVS_FOCUSED) || ([xsi].dState & XTVNS_FOCUSED)
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
      invoke GetSysColor, COLOR_HIGHLIGHT
      mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
      mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, TRANSPARENT))
    .else
      invoke GetSysColor, COLOR_WINDOWTEXT
      mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
      mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, TRANSPARENT))
    .endif

    ;Set the font
    mov hPrevFont, $invoke(SelectObject, [xbx].hMemDC, [xsi].hFont)

    ;Render the created text
    OCall xsi.RenderText, xdi, [xsi].pCaption

    ;Restore previous settings
    invoke SelectObject, [xbx].hMemDC, hPrevFont
    invoke SetBkMode, [xbx].hMemDC, dPrevBkMode
    invoke SetBkColor, [xbx].hMemDC, dPrevBkColor
    invoke SetTextColor, [xbx].hMemDC, dPrevColor

    ;Invalidate the new drawn rect
    invoke InvalidateRect, [xbx].hWnd, addr InvRect, FALSE
    assume xdi:NOTHING
  .endif
MethodEnd



; ==================================================================================================
;     XPT_PropertyNode
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.Done
; Purpose:    Finalize the XPT_PropertyNode object and all childs in its branch.
; Arguments:  None.
; Return:     Nothing.

Method XPT_PropertyNode.Done, uses xsi
  ;DbgText "XPT_PropertyNode.Done"
  SetObject xsi
  .if [xsi].hFont != 0
    invoke DeleteObject, [xsi].hFont
  .endif
  .if [xsi].hIcon != 0
    invoke DestroyIcon, [xsi].hIcon
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.Init
; Purpose:    Initialize a XPT_PropertyNode object.
; Arguments:  Arg1: -> Owner object, XTreeView.
;             Arg2: Icon HANDLE.
;             Arg2: -> Node Caption Text.
;             Arg3: Node height.
;             Arg4: Node Divider position.
;             Arg5: Node state (XTVNS_DISABLED, XTVNS_EXPANDED, etc.).
;             Arg6: -> Variable
;             Arg7: Variable type.
;             Arg8: -> Control option list.
; Return:     Nothing.

Method XPT_PropertyNode.Init, uses xdi xsi, pOwner:POINTER, hIcon:HICON, pCaption:PSTRING, \
                                            dHeight:DWORD, dDividerPos:DWORD, dState:DWORD, \
                                            pVariable:POINTER, dVarType:DWORD, pOptions:POINTER
  local hPrvFont:HFONT, TxtMtr:TEXTMETRIC

  SetObject xsi
  ACall xsi.Init, pOwner, dDividerPos, dHeight, dState
  m2m [xsi].hIcon, hIcon, xax
  m2m [xsi].pCaption, pCaption, xcx
  m2m [xsi].pVariable, pVariable, xax
  m2m [xsi].dVarType, dVarType, ecx
  m2m [xsi].pOptions, pOptions, xax

  ;Create the text font
  SetObject xdi, XPropertyTree, [xsi].pOwner
  invoke GetDeviceCaps, [xdi].hMemDC, LOGPIXELSY
  invoke MulDiv, XPT_FONT_SIZE_PROP, eax, -72
  mov XPT_LogFontText.lfHeight, eax
  mov XPT_LogFontText.lfWeight, FW_NORMAL
  mov [xsi].hFont, $invoke(CreateFontIndirect, offset XPT_LogFontText)

  ;Calculate font metrics
  mov hPrvFont, $invoke(SelectObject, [xdi].hMemDC, [xsi].hFont)
  invoke GetTextMetrics, [xdi].hMemDC, addr TxtMtr
  mov eax, TxtMtr.tmAscent
  add eax, TxtMtr.tmDescent
  mov [xsi].dFontHeight, eax
  m2m [xsi].dFontAveWidth, TxtMtr.tmAveCharWidth, ecx

  ;Housekeeing
  invoke SelectObject, [xdi].hMemDC, hPrvFont
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.CanDragMe
; Purpose:    Indicate if a drag operation can be started.
; Arguments:  Arg1: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = Always FALSE => no dragging allowed.

Method XPT_PropertyNode.CanDragMe,, dKeyFlags:DWORD
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.MouseHit
; Purpose:    Check if the mouse has clicked a hotspot and perform an action.
; Arguments:  Arg1: button that triggered this action.
;             Arg2: -> Clicked point.
;             Arg3: -> XPTN_DISP_INFO.
;             Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = TRUE if and action was triggered, otherwise FALSE.

Method XPT_PropertyNode.MouseHit, uses xbx xsi, dButton:DWORD, pPoint:PPOINT, \
                                                pDispInfo:PXPTN_DISP_INFO, dKeyFlags:DWORD
  local pSelNode:$ObjPtr(XPT_PropertyNode), pSelNodeDispInfo:PXPTN_DISP_INFO

;  DbgText "XPT_PropertyNode.MouseHit"
  .if pDispInfo != NULL
    SetObject xsi
    SetObject xbx, XPropertyTree, [xsi].pOwner
    .if xsi != [xbx].pSelectedNode
      mrm pSelNode, [xbx].pSelectedNode, xax            ;Get currently selected node
      .if xax != NULL
        mov pSelNodeDispInfo, $OCall(xbx::XTreeView.GetDispInfo, pSelNode)
      .endif
      OCall xbx::XTreeView.Select, xsi                  ;Select new node
      OCall xsi.RenderContent, pDispInfo
      .if pSelNode != NULL
        OCall pSelNode::XTreeViewNode.RenderContent, pSelNodeDispInfo
      .endif
    .endif
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.MouseHitDbl
; Purpose:    Check if the mouse has double clicked a hotspot and perform an action.
; Arguments:  Arg1: Button that triggered this action.
;             Arg2: -> Clicked point.
;             Arg3: -> XPTN_DISP_INFO.
;             Arg4: Key flags (MK_CONTROL, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON, MK_SHIFT).
; Return:     eax = TRUE if and action was triggered, otherwise FALSE.

Method XPT_PropertyNode.MouseHitDbl, uses xbx xdi xsi, dButton:DWORD, pPoint:PPOINT, \
                                                       pDispInfo:PXPTN_DISP_INFO, dKeyFlags:DWORD
  local cBuffer[20]:CHR, CtrlDef:XPT_CTRLDEF
  local pTableEnd:POINTER, hWnd:HWND

;  DbgText "XPT_PropertyNode.MouseHitDbl"
  c2m pTableEnd, offset XPT_SYS_COLOR_TABLE_EN_END, r10

  .if pDispInfo != NULL
    SetObject xsi
    .if dButton == MK_LBUTTON
      ;Enter edit mode
      SetObject xbx, XPropertyTree, [xsi].pOwner
      .if !(([xbx].dState & XTVS_DISABLED) || ([xsi].dState & XTVNS_DISABLED))
        mov xdx, pDispInfo
        assume xdx:PXPTN_DISP_INFO

        BitSet [xsi].dState, XTVNS_FOCUSED       ;Set it BEFORE a control is created!

        .if ([xsi].dVarType == XPT_VAR_TYPE_STRING) || ([xsi].dVarType == XPT_VAR_TYPE_CUSTOM)
          mov eax, [xsi].dFontHeight
          mov CtrlDef.dHeight, eax
          mov ecx, [xdx].TextRect.bottom
          sub ecx, [xdx].TextRect.top
          sub ecx, eax
          shr ecx, 1
          add ecx, [xdx].TextRect.top
          mov CtrlDef.sdPosY, ecx
          mov eax, [xdx].TextRect.right
          sub eax, [xdx].TextRect.left
          mov CtrlDef.dWidth, eax
          m2m CtrlDef.sdPosX, [xdx].TextRect.left, ecx
          m2m CtrlDef.pTitle, [xsi].pVariable, xax
          mov CtrlDef.dStyle, WS_CHILD or ES_AUTOHSCROLL
          m2z CtrlDef.dExStyle
          .if [xbx].pEdtCtrl == NULL
            mov CtrlDef.xCtlID, XPT_CONTROL_ID_EDIT
            mov [xbx].pEdtCtrl, $New(XPT_Edit)
            OCall [xbx].pEdtCtrl::XPT_Edit.Init, xsi, [xbx].hWnd, addr CtrlDef
            mov xax, [xbx].pEdtCtrl
            mov xbx, [xax].$Obj(WinControl).hWnd
          .else
            mov xax, [xbx].pEdtCtrl
            mov [xax].$Obj(WinControl).pOwner, xsi
            mov xbx, [xax].$Obj(WinControl).hWnd
            invoke SetWindowLongPtr, xbx, GWL_STYLE, CtrlDef.dStyle
            invoke SetWindowLongPtr, xbx, GWL_EXSTYLE, CtrlDef.dExStyle
            invoke SetWindowText, xbx, CtrlDef.pTitle
            invoke MoveWindow, xbx, CtrlDef.sdPosX, CtrlDef.sdPosY, \
                               CtrlDef.dWidth, CtrlDef.dHeight, TRUE
          .endif
          invoke SendMessage, xbx, WM_SETFONT, [xsi].hFont, FALSE
          invoke SendMessage, xbx, EM_SETMARGINS, EC_LEFTMARGIN, [xsi].dFontAveWidth
          invoke ReleaseCapture
          invoke ShowWindow, xbx, SW_SHOW
          invoke SetFocus, xbx

        .elseif [xsi].dVarType == XPT_VAR_TYPE_INTEGER
          mov eax, [xsi].dFontHeight
          mov CtrlDef.dHeight, eax
          mov ecx, [xdx].TextRect.bottom
          sub ecx, [xdx].TextRect.top
          sub ecx, eax
          shr ecx, 1
          add ecx, [xdx].TextRect.top
          mov CtrlDef.sdPosY, ecx
          mov eax, [xdx].TextRect.right
          sub eax, [xdx].TextRect.left
          mov CtrlDef.dWidth, eax
          m2m CtrlDef.sdPosX, [xdx].TextRect.left, ecx
          lea xcx, cBuffer
          mov CtrlDef.pTitle, xcx
          mov xax, [xsi].pVariable
          mov CtrlDef.dStyle, WS_CHILD or ES_AUTOHSCROLL OR ES_NUMBER
          m2z CtrlDef.dExStyle
          invoke dword2dec, xcx, DWORD ptr [xax]
          .if [xbx].pEdtCtrl == NULL
            mov CtrlDef.xCtlID, XPT_CONTROL_ID_EDIT
            mov [xbx].pEdtCtrl, $New(XPT_Edit)
            OCall [xbx].pEdtCtrl::XPT_Edit.Init, xsi, [xbx].hWnd, addr CtrlDef
            mov xax, [xbx].pEdtCtrl
            mov xbx, [xax].$Obj(WinControl).hWnd
          .else
            mov xax, [xbx].pEdtCtrl
            mov [xax].$Obj(WinControl).pOwner, xsi
            mov xbx, [xax].$Obj(WinControl).hWnd
            invoke SetWindowLongPtr, xbx, GWL_STYLE, CtrlDef.dStyle
            invoke SetWindowLongPtr, xbx, GWL_EXSTYLE, CtrlDef.dExStyle
            invoke SetWindowText, xbx, CtrlDef.pTitle
            invoke MoveWindow, xbx, CtrlDef.sdPosX, CtrlDef.sdPosY, \
                               CtrlDef.dWidth, CtrlDef.dHeight, TRUE
          .endif
          invoke SendMessage, xbx, WM_SETFONT, [xsi].hFont, FALSE
          invoke SendMessage, xbx, EM_SETMARGINS, EC_LEFTMARGIN, [xsi].dFontAveWidth
          invoke ReleaseCapture
          invoke ShowWindow, xbx, SW_SHOW
          invoke SetFocus, xbx

        .elseif [xsi].dVarType == XPT_VAR_TYPE_REAL4
          mov eax, [xsi].dFontHeight
          mov CtrlDef.dHeight, eax
          mov ecx, [xdx].TextRect.bottom
          sub ecx, [xdx].TextRect.top
          sub ecx, eax
          shr ecx, 1
          add ecx, [xdx].TextRect.top
          mov CtrlDef.sdPosY, ecx
          mov eax, [xdx].TextRect.right
          sub eax, [xdx].TextRect.left
          mov CtrlDef.dWidth, eax
          m2m CtrlDef.sdPosX, [xdx].TextRect.left, eax
          mov CtrlDef.dStyle, WS_CHILD or ES_AUTOHSCROLL
          m2z CtrlDef.dExStyle
          lea xcx, cBuffer
          mov CtrlDef.pTitle, xcx
          mov xax, [xsi].pVariable
          fld REAL4 ptr [xax]
          invoke St0ToStr, xcx, 0, 8, 0
          fstp st(0)
          .if [xbx].pEdtCtrl == NULL
            mov CtrlDef.xCtlID, XPT_CONTROL_ID_EDIT
            mov [xbx].pEdtCtrl, $New(XPT_Edit)
            OCall [xbx].pEdtCtrl::XPT_Edit.Init, xsi, [xbx].hWnd, addr CtrlDef
            mov xax, [xbx].pEdtCtrl
            mov xbx, [xax].$Obj(WinControl).hWnd
          .else
            mov xax, [xbx].pEdtCtrl
            mov [xax].$Obj(WinControl).pOwner, xsi
            mov xbx, [xax].$Obj(WinControl).hWnd
            invoke SetWindowLongPtr, xbx, GWL_STYLE, CtrlDef.dStyle
            invoke SetWindowLongPtr, xbx, GWL_EXSTYLE, CtrlDef.dExStyle
            invoke SetWindowText, xbx, CtrlDef.pTitle
            invoke MoveWindow, xbx, CtrlDef.sdPosX, CtrlDef.sdPosY, \
                               CtrlDef.dWidth, CtrlDef.dHeight, TRUE
          .endif
          invoke SendMessage, xbx, WM_SETFONT, [xsi].hFont, FALSE
          invoke SendMessage, xbx, EM_SETMARGINS, EC_LEFTMARGIN, [xsi].dFontAveWidth
          invoke ReleaseCapture
          invoke ShowWindow, xbx, SW_SHOW
          invoke SetFocus, xbx

        .elseif [xsi].dVarType == XPT_VAR_TYPE_COLOR
          mov eax, [xdx].ButtonRect.right
          sub eax, [xdx].ButtonRect.left
          mov CtrlDef.dWidth, eax
          mov ecx, [xdx].ButtonRect.bottom
          sub ecx, [xdx].ButtonRect.top
          mov CtrlDef.dHeight, ecx
          m2m CtrlDef.sdPosX, [xdx].ButtonRect.left, eax
          inc CtrlDef.sdPosX
          m2m CtrlDef.sdPosY, [xdx].ButtonRect.top, eax
          m2z CtrlDef.pTitle
          mov CtrlDef.dStyle, WS_CHILD or BS_NOTIFY or BS_OWNERDRAW
          m2z CtrlDef.dExStyle
          .if [xbx].pBtnCtrl == NULL
            mov CtrlDef.xCtlID, XPT_CONTROL_ID_BUTTON
            mov [xbx].pBtnCtrl, $New(XPT_Button)
            OCall [xbx].pBtnCtrl::XPT_Button.Init, xsi, [xbx].hWnd, addr CtrlDef
            mov xax, [xbx].pBtnCtrl
            mov xbx, [xax].$Obj(WinControl).hWnd
          .else
            mov xax, [xbx].pBtnCtrl
            mov [xax].$Obj(WinControl).pOwner, xsi
            mov xbx, [xax].$Obj(WinControl).hWnd
            invoke SetWindowLongPtr, xbx, GWL_STYLE, CtrlDef.dStyle
            invoke SetWindowLongPtr, xbx, GWL_EXSTYLE, CtrlDef.dExStyle
            invoke MoveWindow, xbx, CtrlDef.sdPosX, CtrlDef.sdPosY, \
                               CtrlDef.dWidth, CtrlDef.dHeight, TRUE
          .endif
          invoke SendMessage, xbx, WM_SETFONT, [xsi].hFont, FALSE
          invoke ReleaseCapture
          invoke ShowWindow, xbx, SW_SHOW
          invoke SetFocus, xbx

        .elseif ([xsi].dVarType == XPT_VAR_TYPE_FILE) || ([xsi].dVarType == XPT_VAR_TYPE_PATH)
          mov eax, [xdx].ButtonRect.right
          sub eax, [xdx].ButtonRect.left
          mov CtrlDef.dWidth, eax
          mov ecx, [xdx].ButtonRect.bottom
          sub ecx, [xdx].ButtonRect.top
          mov CtrlDef.dHeight, ecx
          m2m CtrlDef.sdPosX, [xdx].ButtonRect.left, eax
          inc CtrlDef.sdPosX
          m2m CtrlDef.sdPosY, [xdx].ButtonRect.top, eax
          m2z CtrlDef.pTitle
          mov CtrlDef.dStyle, WS_CHILD or BS_NOTIFY or BS_OWNERDRAW
          m2z CtrlDef.dExStyle
          .if [xbx].pBtnCtrl == NULL
            mov CtrlDef.xCtlID, XPT_CONTROL_ID_BUTTON
            mov [xbx].pBtnCtrl, $New(XPT_Button)
            OCall [xbx].pBtnCtrl::XPT_Button.Init, xsi, [xbx].hWnd, addr CtrlDef
            mov xax, [xbx].pBtnCtrl
            mov xbx, [xax].$Obj(WinControl).hWnd
          .else
            mov xax, [xbx].pBtnCtrl
            mov [xax].$Obj(WinControl).pOwner, xsi
            mov xbx, [xax].$Obj(WinControl).hWnd
            invoke SetWindowLongPtr, xbx, GWL_STYLE, CtrlDef.dStyle
            invoke SetWindowLongPtr, xbx, GWL_EXSTYLE, CtrlDef.dExStyle
            invoke MoveWindow, xbx, CtrlDef.sdPosX, CtrlDef.sdPosY, \
                               CtrlDef.dWidth, CtrlDef.dHeight, TRUE
          .endif
          invoke SendMessage, xbx, WM_SETFONT, [xsi].hFont, FALSE
          invoke ShowWindow, xbx, SW_SHOW

          SetObject xbx, XPropertyTree, [xsi].pOwner
          mov xdx, pDispInfo
          mov eax, [xdx].TextRect.right
          sub eax, [xdx].TextRect.left
          sub eax, [xdx].ButtonRect.right
          add eax, [xdx].ButtonRect.left
          mov CtrlDef.dWidth, eax
          mov eax, [xsi].dFontHeight
          mov CtrlDef.dHeight, eax
          mov ecx, [xdx].TextRect.bottom
          sub ecx, [xdx].TextRect.top
          sub ecx, eax
          shr ecx, 1
          add ecx, [xdx].TextRect.top
          mov CtrlDef.sdPosY, ecx
          m2m CtrlDef.sdPosX, [xdx].TextRect.left, ecx
          m2m CtrlDef.pTitle, [xsi].pVariable, xax
          mov CtrlDef.dStyle, WS_CHILD or ES_AUTOHSCROLL
          m2z CtrlDef.dExStyle
          .if [xbx].pEdtCtrl == NULL
            mov CtrlDef.xCtlID, XPT_CONTROL_ID_EDIT
            mov [xbx].pEdtCtrl, $New(XPT_Edit)
            OCall [xbx].pEdtCtrl::XPT_Edit.Init, xsi, [xbx].hWnd, addr CtrlDef
            mov xax, [xbx].pEdtCtrl
            mov xbx, [xax].$Obj(WinControl).hWnd
          .else
            mov xax, [xbx].pEdtCtrl
            mov [xax].$Obj(WinControl).pOwner, xsi
            mov xbx, [xax].$Obj(WinControl).hWnd
            invoke SetWindowLongPtr, xbx, GWL_STYLE, CtrlDef.dStyle
            invoke SetWindowLongPtr, xbx, GWL_EXSTYLE, CtrlDef.dExStyle
            invoke SetWindowText, xbx, CtrlDef.pTitle
            invoke MoveWindow, xbx, CtrlDef.sdPosX, CtrlDef.sdPosY, \
                               CtrlDef.dWidth, CtrlDef.dHeight, TRUE
          .endif
          invoke SendMessage, xbx, WM_SETFONT, [xsi].hFont, FALSE
          invoke SendMessage, xbx, EM_SETMARGINS, EC_LEFTMARGIN, [xsi].dFontAveWidth
          invoke ReleaseCapture
          invoke ShowWindow, xbx, SW_SHOW
          invoke SetFocus, xbx

        .elseif ([xsi].dVarType == XPT_VAR_TYPE_LIST)
          mov xdx, pDispInfo
          mov eax, [xdx].ButtonRect.right
          sub eax, [xdx].TextRect.left
          inc eax
          mov CtrlDef.dWidth, eax
          mov CtrlDef.dHeight, XPT_COMBOBOX_SIZE
          m2m CtrlDef.sdPosY, [xdx].TextRect.top, ecx
          m2m CtrlDef.sdPosX, [xdx].TextRect.left, eax
          .if [xbx].pCBxCtrl != NULL
            Destroy [xbx].pCBxCtrl
          .endif
          m2z CtrlDef.pTitle
          mov CtrlDef.dStyle, WS_CHILD or CBS_DROPDOWNLIST or WS_VSCROLL or CBS_OWNERDRAWFIXED
          m2z CtrlDef.dExStyle
          mov CtrlDef.xCtlID, XPT_CONTROL_ID_COMBOBOX
          mov [xbx].pCBxCtrl, $New(XPT_ComboBox)
          OCall [xbx].pCBxCtrl::XPT_ComboBox.Init, xsi, [xbx].hWnd, addr CtrlDef
          mov xax, [xbx].pCBxCtrl
          m2m hWnd, [xax].$Obj(WinControl).hWnd, xcx
          invoke SendMessage, hWnd, WM_SETFONT, [xsi].hFont, FALSE
          ;Set data
          mov xbx, [xsi].pOptions
          .if xbx != NULL
            .while (CHR ptr [xbx] != 0)
              invoke SendMessage, hWnd, CB_ADDSTRING, 0, xbx
              invoke StrSize, xbx
              add xbx, xax
            .endw
            m2z CtrlDef.pTitle
          .endif

          mov xax, [xsi].pVariable
          invoke SendMessage, hWnd, CB_SETCURSEL, DWORD ptr [xax], 0

          invoke ReleaseCapture
          invoke ShowWindow, hWnd, SW_SHOW
          invoke SetFocus, hWnd

        .elseif ([xsi].dVarType == XPT_VAR_TYPE_SYS_COLOR)
          mov xdx, pDispInfo
          mov eax, [xdx].ButtonRect.right
          sub eax, [xdx].TextRect.left
          inc eax
          mov CtrlDef.dWidth, eax
          mov CtrlDef.dHeight, XPT_COMBOBOX_SIZE
          m2m CtrlDef.sdPosY, [xdx].TextRect.top, ecx
          m2m CtrlDef.sdPosX, [xdx].TextRect.left, eax
          .if [xbx].pCBxCtrl != NULL
            Destroy [xbx].pCBxCtrl
          .endif
          m2z CtrlDef.pTitle
          mov CtrlDef.dStyle, WS_CHILD or CBS_DROPDOWNLIST or WS_VSCROLL or CBS_OWNERDRAWFIXED
          m2z CtrlDef.dExStyle
          mov CtrlDef.xCtlID, XPT_CONTROL_ID_COMBOBOX
          mov [xbx].pCBxCtrl, $New(XPT_ComboBox)
          OCall [xbx].pCBxCtrl::XPT_ComboBox.Init, xsi, [xbx].hWnd, addr CtrlDef
          mov xax, [xbx].pCBxCtrl
          m2m hWnd, [xax].$Obj(WinControl).hWnd, xcx
          invoke SendMessage, hWnd, WM_SETFONT, [xsi].hFont, FALSE
          ;Fill combobox data
          mov xdi, offset XPT_SYS_COLOR_TABLE_EN_BEG
          .while xdi < pTableEnd
            invoke SendMessage, hWnd, CB_ADDSTRING, 0, [xdi].XPT_SYS_COLOR_ENTRY.pDescription
            add xdi, sizeof XPT_SYS_COLOR_ENTRY
          .endw
          m2z CtrlDef.pTitle

          ;Find the index of the variable value in the lookup table
          mov xcx, [xsi].pVariable
          mov edx, DWORD ptr [xcx]
          mov xcx, offset XPT_SYS_COLOR_TABLE_EN_BEG
          xor eax, eax
          .while xcx < pTableEnd
            .break .if edx == [xcx].XPT_SYS_COLOR_ENTRY.dSystemIndex
            add xcx, sizeof XPT_SYS_COLOR_ENTRY
            inc xax
          .endw
          .if xcx == pTableEnd
            mov xax, -1
          .endif
          ;Set the found index
          invoke SendMessage, hWnd, CB_SETCURSEL, xax, 0

          invoke ReleaseCapture
          invoke ShowWindow, hWnd, SW_SHOW
          invoke SetFocus, hWnd

        .endif
      .endif
    .endif

    assume xdx:NOTHING
    mov eax, TRUE

  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.Render
; Purpose:    Draw the complete node.
; Arguments:  Arg1: -> XPTN_DISP_INFO.
; Return:     Nothing.

Method XPT_PropertyNode.Render, uses xsi, pDispInfo:PXPTN_DISP_INFO
  ;DbgText "XPT_PropertyNode.Render"
  SetObject xsi
  .if ([xsi].dHeight != 0) || ([xsi].dWidth != 0)     ;Don't draw nodes with height and width = 0
    SetObject xdx, XPropertyTree, [xsi].pOwner

    ;Calc the total indentation of this node
    mov xcx, [xsi].pParent
    mov eax, [xdx].ClientOffset.x
    mov xdx, [xsi].pOwner
    sub eax, [xdx].TotalOffset.x
    add eax, [xdx].dNodeIndent
    .while xcx != NULL
      mov xcx, [xcx].$Obj(XTreeViewNode).pParent
      add eax, [xdx].dNodeIndent
    .endw                                             ;eax = total indentation

    ;Fill XTVN_DISP_INFO.ContentRect info
    mov xcx, pDispInfo
    mov [xcx].XTVN_DISP_INFO.ContentRect.left, eax
    m2m [xcx].XTVN_DISP_INFO.ContentRect.right, [xdx].ClientSize.x, eax
    m2m [xcx].XTVN_DISP_INFO.ContentRect.top, [xcx].XTVN_DISP_INFO.sdNodeTop, edx
    m2m [xcx].XTVN_DISP_INFO.ContentRect.bottom, [xcx].XTVN_DISP_INFO.sdNodeBot, eax

    if DEBUGGING
    .if SDWORD ptr [xcx].XTVN_DISP_INFO.ContentRect.bottom < 0
      DbgWarning "Error while positioning the view"
    .endif
    endif

    ;Render the tree structure (lines and toggler)
    OCall xsi.RenderTreeStruc, pDispInfo

    ;Render the content of the node
    OCall xsi.RenderContent, pDispInfo

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_PropertyNode.RenderContent
; Purpose:    Draw the content (icon + caption + text) of the node.
; Arguments:  Arg1: -> XPTN_DISP_INFO
; Return:     Nothing.
; Note:       This method must update the coords of all Rect structures in the Content and must
;             invalidate the modified region.

Method XPT_PropertyNode.RenderContent, uses xbx xdi xsi, pDispInfo:PXPTN_DISP_INFO
  local dPrevColor:DWORD, dPrevBkMode:DWORD, hPrevFont:HFONT
  local hPrevPen:HPEN, hBrush:HBRUSH, hPrevBrush:HBRUSH
  local cBuffer[MAX_PATH]:CHR, pText:PSTRING
  local RRect:RECT, OutputRect:RECT, AuxRect:RECT
  local dOptionIndex:DWORD, pOptionText:PSTRING
  local pTableEnd:POINTER

;  DbgText "XPT_PropertyNode.RenderContent"

  c2m pTableEnd, offset XPT_SYS_COLOR_TABLE_EN_END, r10

  mov xdi, pDispInfo
  .if xdi != NULL
    SetObject xsi
    SetObject xbx, XPropertyTree, [xsi].pOwner
    assume xdi:PXPTN_DISP_INFO
    m2m [xdi].TextRect.left, [xdi].ContentRect.left, eax
    m2m [xdi].TextRect.right, [xdi].ContentRect.right, ecx

    ;Calc all rectangles
    mov eax, [xdi].ContentRect.bottom
    dec eax                                             ;Make room for the bottom separation line
    mov [xdi].CaptionRect.bottom, eax
    mov RRect.bottom, eax
    mov [xdi].TextRect.bottom, eax
    mov edx, [xdi].ContentRect.top
    mov RRect.top, edx
    mov [xdi].CaptionRect.top, edx
    mov [xdi].TextRect.top, edx
    sub eax, edx
    sub eax, XPT_ICON_SIZE
    shr eax, 1
    mov ecx, [xdi].CaptionRect.bottom
    sub ecx, eax
    mov [xdi].IconRect.bottom, ecx                      ;IconRect.bottom
    sub ecx, XPT_ICON_SIZE
    mov [xdi].IconRect.top, ecx                         ;IconRect.top

    mov edx, [xdi].ContentRect.left
    mov RRect.left, edx
    add edx, XPT_MARGIN
    mov [xdi].IconRect.left, edx                        ;IconRect.left
    mov eax, edx
    add eax, XPT_ICON_SIZE
    mov [xdi].IconRect.right, eax                       ;IconRect.right
    add eax, XPT_MARGIN
    mov [xdi].CaptionRect.left, eax                     ;CaptionRect.left
    mov RRect.right, eax
    add eax, [xsi].dWidth
    mov [xdi].CaptionRect.right, eax                    ;CaptionRect.right
    inc eax                                             ;Make room for the vertical separation line
    mov [xdi].TextRect.left, eax                        ;TextRect.left
    mov eax, [xbx].ClientSize.x
    mov [xdi].ButtonRect.right, eax                     ;ButtonRect.right
    .if (([xsi].dVarType == XPT_VAR_TYPE_SYS_COLOR) || \;In all these cases make room
         ([xsi].dVarType == XPT_VAR_TYPE_COLOR) || \    ;  for the button at the end
         ([xsi].dVarType == XPT_VAR_TYPE_FILE) || \     ;  of the text rect
         ([xsi].dVarType == XPT_VAR_TYPE_PATH) || \
         ([xsi].dVarType == XPT_VAR_TYPE_LIST)) && \
         ([xsi].dState & XTVNS_FOCUSED)                 ;and only if the node is focused!
      sub eax, [xdi].CaptionRect.bottom
      add eax, [xdi].CaptionRect.top
    .endif
    mov [xdi].TextRect.right, eax                       ;TextRect.right
    mov eax, [xbx].ClientSize.x
    sub eax, [xdi].CaptionRect.bottom
    add eax, [xdi].CaptionRect.top
    mov [xdi].ButtonRect.left, eax                      ;ButtonRect.left
    m2m [xdi].ButtonRect.bottom, [xdi].TextRect.bottom, eax ;ButtonRect.bottom
    m2m [xdi].ButtonRect.top, [xdi].TextRect.top, ecx       ;ButtonRect.top

    ;Fill the icon background
    mov hBrush, $invoke(CreateSolidBrush, [xbx].ColorBackground)
    invoke FillRect, [xbx].hMemDC, addr RRect, hBrush
    invoke DeleteObject, hBrush

    ;Render the icon
    invoke DrawIconEx, [xbx].hMemDC, [xdi].IconRect.left, [xdi].IconRect.top, [xsi].hIcon, \
                       XPT_ICON_SIZE, XPT_ICON_SIZE, NULL, NULL, DI_NORMAL

    .if xsi == [xbx].pSelectedNode
      .if ([xbx].dState & XTVS_FOCUSED) || ([xsi].dState & XTVNS_FOCUSED)
        .ifBitSet [xsi].dState, XTVNS_HOTTRACK          ;Check if the node is beeing hottracked
          mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, $RGB(255,255,0)))
        .else
          invoke GetSysColor, COLOR_HIGHLIGHTTEXT
          mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
        .endif
        invoke GetSysColor, COLOR_HIGHLIGHT
        mov hBrush, $invoke(CreateSolidBrush, eax)
      .else
        invoke GetSysColor, COLOR_WINDOWTEXT
        mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
        invoke GetSysColor, COLOR_BTNFACE
        mov hBrush, $invoke(CreateSolidBrush, eax)
      .endif
    .elseIfBitSet [xsi].dState, XTVNS_HOTTRACK          ;Check if the node is beeing hottracked
      invoke GetSysColor, COLOR_HIGHLIGHT
      mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
      mov hBrush, $invoke(CreateSolidBrush, [xbx].ColorBackground)
    .else
      invoke GetSysColor, COLOR_WINDOWTEXT
      mov dPrevColor, $32($invoke(SetTextColor, [xbx].hMemDC, eax))
      mov hBrush, $invoke(CreateSolidBrush, [xbx].ColorBackground)
    .endif

    ;Set the font
    mov hPrevFont, $invoke(SelectObject, [xbx].hMemDC, [xsi].hFont)

    ;Fill the property caption background
    mov dPrevBkMode, $32($invoke(SetBkMode, [xbx].hMemDC, TRANSPARENT))
    invoke FillRect, [xbx].hMemDC, addr [xdi].CaptionRect, hBrush
    invoke DeleteObject, hBrush

    ;Draw the property caption text
    mov eax, [xdi].CaptionRect.bottom
    sub eax, [xdi].CaptionRect.top
    sub eax, [xsi].dFontHeight
    shr eax, 1
    add eax, [xdi].CaptionRect.top
    mov OutputRect.top, eax
    add eax, [xsi].dFontHeight
    mov OutputRect.bottom, eax

    mov ecx, [xdi].CaptionRect.left
    add ecx, [xsi].dFontAveWidth
    mov OutputRect.left, ecx
    mov ecx, [xdi].CaptionRect.right
    sub ecx, [xsi].dFontAveWidth
    mov OutputRect.right, ecx

    invoke DrawText, [xbx].hMemDC, [xsi].pCaption , -1, addr OutputRect, \
                     DT_SINGLELINE or DT_LEFT or DT_END_ELLIPSIS

    ;Fill the property text background and button area
    .if (xsi == [xbx].pSelectedNode) && ([xsi].dState & XTVNS_FOCUSED) && \
        !(([xbx].dState & XTVS_DISABLED) || ([xsi].dState & XTVNS_DISABLED))
      invoke GetSysColor, COLOR_WINDOW
    .else
      mov eax, [xbx].ColorBackground
    .endif
    mov hBrush, $invoke(CreateSolidBrush, eax)
    invoke FillRect, [xbx].hMemDC, addr [xdi].TextRect, hBrush
    invoke DeleteObject, hBrush

    .if !([xsi].dState & XTVNS_FOCUSED) || ([xsi].dVarType == XPT_VAR_TYPE_COLOR)
      ;Draw a colored rect in case of XPT_VAR_TYPE_COLOR
      .if ([xsi].dVarType == XPT_VAR_TYPE_COLOR)
        mov xcx, [xsi].pVariable
        mov hBrush, $invoke(CreateSolidBrush, DWORD ptr [xcx])
        mov hPrevBrush, $invoke(SelectObject, [xbx].hMemDC, hBrush)
        mov ecx, [xdi].TextRect.left
        lea eax, [xcx + XPT_MARGIN]
        mov AuxRect.left, eax
        lea eax, [xcx + XPT_MARGIN + XPT_ICON_SIZE]
        mov AuxRect.right, eax
        invoke Rectangle, [xbx].hMemDC, \
                          AuxRect.left, [xdi].IconRect.top, \
                          AuxRect.right, [xdi].IconRect.bottom
        invoke SelectObject, [xbx].hMemDC, hPrevBrush
        invoke DeleteObject, hBrush

      ;Draw a colored rect in case of XPT_VAR_TYPE_SYS_COLOR
      .elseif ([xsi].dVarType == XPT_VAR_TYPE_SYS_COLOR)
        ;Draw a rectangle with the corresponding system color
        mov xcx, [xsi].pVariable
        mov hBrush, $invoke(GetSysColorBrush, DWORD ptr [xcx])  ;Don't delete this brush
        .if eax == 0
          mov hBrush, $invoke(GetStockObject, HOLLOW_BRUSH)
        .endif
        mov hPrevBrush, $invoke(SelectObject, [xbx].hMemDC, hBrush)
        mov ecx, [xdi].TextRect.left
        lea eax, [xcx + XPT_MARGIN]
        mov AuxRect.left, eax
        lea eax, [xcx + XPT_MARGIN + XPT_ICON_SIZE]
        mov AuxRect.right, eax
        invoke Rectangle, [xbx].hMemDC, \
                          AuxRect.left, [xdi].IconRect.top, \
                          AuxRect.right, [xdi].IconRect.bottom
        invoke SelectObject, [xbx].hMemDC, hPrevBrush

        ;In case the variable has an invalid system color index, then draw a cross inside the rect
        .if hBrush == 0
          mov ecx, [xdi].TextRect.left
          lea eax, [xcx + XPT_MARGIN]                       ;left
          lea edx, [xcx + XPT_MARGIN + XPT_ICON_SIZE - 1]   ;right
          mov ecx, [xdi].IconRect.bottom
          dec ecx
          mov AuxRect.left, eax
          mov AuxRect.top, ecx
          mov AuxRect.right, edx                        ;Auxiliary storage

          invoke MoveToEx, [xbx].hMemDC, AuxRect.left, [xdi].IconRect.top, NULL
          invoke LineTo, [xbx].hMemDC, AuxRect.right, AuxRect.top
          invoke MoveToEx, [xbx].hMemDC, edx, [xdi].IconRect.top, NULL
          invoke LineTo, [xbx].hMemDC, AuxRect.left, AuxRect.top
        .endif
      .endif

      ;Draw the text of the variable
      mov ecx, [xdi].TextRect.left
      add ecx, [xsi].dFontAveWidth
      mov OutputRect.left, ecx
      mov ecx, [xdi].ButtonRect.right
      sub ecx, [xsi].dFontAveWidth
      mov OutputRect.right, ecx

      .if ([xbx].dState & XTVS_DISABLED) || ([xsi].dState & XTVNS_DISABLED)
        mov ecx, COLOR_GRAYTEXT
      .else
        mov ecx, COLOR_WINDOWTEXT
      .endif
      invoke GetSysColor, ecx
      invoke SetTextColor, [xbx].hMemDC, eax

      ;Get the correct string
      .if ([xsi].dVarType == XPT_VAR_TYPE_STRING) || ([xsi].dVarType == XPT_VAR_TYPE_CUSTOM)
        m2m pText, [xsi].pVariable, xax
      .elseif [xsi].dVarType == XPT_VAR_TYPE_INTEGER
        lea xcx, cBuffer
        mov pText, xcx
        mov xax, [xsi].pVariable
        invoke dword2dec, xcx, DWORD ptr [xax]
      .elseif [xsi].dVarType == XPT_VAR_TYPE_REAL4
        lea xcx, cBuffer
        mov pText, xcx
        mov xax, [xsi].pVariable
        fld REAL4 ptr [xax]
        invoke St0ToStr, xcx, 0, 8, 0
        fstp st(0)

      .elseif [xsi].dVarType == XPT_VAR_TYPE_COLOR
        add OutputRect.left, 2*XPT_MARGIN + XPT_ICON_SIZE
        .ifBitSet [xsi].dState, XTVNS_FOCUSED
          mov ecx, [xdi].ButtonRect.right
          sub ecx, [xdi].ButtonRect.left
          sub OutputRect.right, ecx
        .endif
        lea xcx, cBuffer
        mov pText, xcx
        mov xax, [xsi].pVariable
        invoke dword2hex, xcx, DWORD ptr [xax]
      .elseif [xsi].dVarType == XPT_VAR_TYPE_FILE
        m2m pText, [xsi].pVariable, xdx
      .elseif [xsi].dVarType == XPT_VAR_TYPE_PATH
        m2m pText, [xsi].pVariable, xdx
      .elseif [xsi].dVarType == XPT_VAR_TYPE_LIST
        mov xdx, [xsi].pOptions                         ;xdx -> List of options
        xor eax, eax
        mov dOptionIndex, eax
        mov pText, xax
        .if xdx != NULL
          mov pOptionText, xdx
          .while (CHR ptr [xdx] != 0)
            mov xcx, [xsi].pVariable
            mov eax, dOptionIndex
            .break .if eax == DWORD ptr [xcx]
            ;Move to next string
            invoke StrSize, pOptionText
            add pOptionText, xax
            inc dOptionIndex
            mov xdx, pOptionText
          .endw
          .if (CHR ptr [xdx] == 0)
            invoke SetTextColor, [xbx].hMemDC, $RGB(255,0,0)
            m2m pText, offset cInvalidSelection, xdx
          .else
            mov pText, xdx
          .endif
        .endif

      .elseif [xsi].dVarType == XPT_VAR_TYPE_SYS_COLOR
        add OutputRect.left, 2*XPT_MARGIN + XPT_ICON_SIZE
        .ifBitSet [xsi].dState, XTVNS_FOCUSED           ;If it has the focus, then
          mov ecx, [xdi].ButtonRect.right               ;  make room for the button
          sub ecx, [xdi].ButtonRect.left
          sub OutputRect.right, ecx
        .endif

        mov xcx, [xsi].pVariable
        mov eax, DWORD ptr [xcx]
        mov xcx, offset XPT_SYS_COLOR_TABLE_EN_BEG
        .while xcx < pTableEnd
          .break .if eax == [xcx].XPT_SYS_COLOR_ENTRY.dSystemIndex
          add xcx, sizeof XPT_SYS_COLOR_ENTRY
        .endw
        .if xcx == pTableEnd
          invoke SetTextColor, [xbx].hMemDC, $RGB(255,0,0)
          m2m pText, offset cInvalidSelection, xax
        .else
          m2m pText, [xcx].XPT_SYS_COLOR_ENTRY.pDescription, xax
        .endif

      .else
        m2z pText
      .endif

      invoke DrawText, [xbx].hMemDC, pText , -1, addr OutputRect, \
                       DT_SINGLELINE or DT_LEFT or DT_END_ELLIPSIS

      ;Restore previous settings
      invoke SelectObject, [xbx].hMemDC, hPrevFont
      invoke SetBkMode, [xbx].hMemDC, dPrevBkMode
      invoke SetTextColor, [xbx].hMemDC, dPrevColor

      ;Render some separation lines
      mov hPrevPen, $invoke(SelectObject, [xbx].hMemDC, [xbx].hPenAux)
      mov eax, [xdi].ContentRect.bottom
      dec eax
      mov AuxRect.bottom, eax
      invoke MoveToEx, [xbx].hMemDC, [xdi].ContentRect.left, AuxRect.bottom, NULL
      invoke LineTo, [xbx].hMemDC, [xbx].ClientSize.x, AuxRect.bottom
      invoke MoveToEx, [xbx].hMemDC, [xdi].CaptionRect.right, AuxRect.bottom, NULL
      mov eax, [xdi].ContentRect.top
      dec eax
      invoke LineTo, [xbx].hMemDC, [xdi].CaptionRect.right, eax
      invoke SelectObject, [xbx].hMemDC, hPrevPen

;      ;Render a down pointing arrow if we have the combobox active
;      .if (([xsi].dVarType == XPT_VAR_TYPE_SYS_COLOR) || \
;           ([xsi].dVarType == XPT_VAR_TYPE_LIST)) && \
;          ([xsi].dState & XTVNS_FOCUSED)
;        mov ecx, [xdi].ButtonRect.left
;        sub ecx, [xdi].TextRect.left
;        add ecx, 4
;        mov OutputRect.left, ecx
;        mov ecx, [xdi].ButtonRect.right
;        sub ecx, [xdi].TextRect.left
;        sub ecx, 2
;        mov OutputRect.right, ecx
;        invoke DrawFrameControl, [xbx].hMemDC, addr OutputRect, DFC_BUTTON, DFCS_BUTTONPUSH or DFCS_TRANSPARENT
;      .endif
    .endif

    .ifBitSet [xsi].dState, XTVNS_FOCUSED
      ;Draw a separation line for the button
      mov eax, [xdi].ContentRect.bottom
      dec eax
      dec eax
      invoke MoveToEx, [xbx].hMemDC, [xdi].TextRect.right, eax, NULL
      mov eax, [xdi].ContentRect.top
      dec eax
      invoke LineTo, [xbx].hMemDC, [xdi].TextRect.right, eax
      invoke SelectObject, [xbx].hMemDC, $invoke(SelectObject, [xbx].hMemDC, [xbx].hPenAux)
    .endif

    ;Invalidate the new drawn rect
    invoke InvalidateRect, [xbx].hWnd, NULL, FALSE

    assume xdi:NOTHING
  .endif
MethodEnd



; ==================================================================================================
;     XPropertyTree
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.Done
; Purpose:    Finalize the XPropertyTree object.
; Arguments:  None.
; Return:     Nothing.

Method XPropertyTree.Done, uses xsi
  ;DbgText "XPropertyTree.Done"
  SetObject xsi
  Destroy [xsi].pEdtCtrl
  Destroy [xsi].pBtnCtrl
  Destroy [xsi].pCBxCtrl
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.Draw
; Purpose:    Render all nodes in view on the back buffer.
; Arguments:  None.
; Return:     Nothing.

Method XPropertyTree.Draw, uses xbx xdi xsi
  local ScrollInfo:SCROLLINFO, RemRect:RECT

  ;DbgText "XPropertyTree.Draw"
  SetObject xsi
  .ifBitClr [xsi].dState, XTVS_LOCKED

    ;Some initialization
    OCall [xsi].DispInfoColl::XWCollection.DisposeAll      ;Release all XTVN_DISP_INFO structs

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

    .if edi < [xsi].ClientSize.y
      ;Fill the bottom remaining background
      m2z RemRect.left
      mov RemRect.top, edi
      m2m RemRect.right, [xsi].ClientSize.x, ecx
      m2m RemRect.bottom, [xsi].ClientSize.y, edx
      lea xdi, RemRect
      OCall xsi.RenderBackground, xdi
      invoke InvalidateRect, [xsi].hWnd, xdi, FALSE
    .endif

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.Init
; Purpose:    Initialize a XTreeView object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_XTV structure.
; Return:     Nothing.

Method XPropertyTree.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_XTV
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_XTV
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE or WS_TABSTOP; or WS_CLIPCHILDREN or WS_CLIPSIBLINGS
  invoke CreateWindowEx, [xbx].dExStyle, offset cClassNameXPT, [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING
  TCall xsi::WinPrimer.Init, pOwner, [xsi].hWnd

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnCreate
; Purpose:    Event handler for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method XPropertyTree.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO, hDC:HDC

  ;DbgText "XPropertyTree.OnCreate"
  SetObject xsi

  ;Some initialization
  mov [xsi].hCursorArrow, $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_XTV_ARROW"))

  OCall [xsi].DispInfoColl::XWCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY
  OCall [xsi].DispInfoPool::DataPool.Init, xsi, [xsi].dDispInfoSize, 1000, 4
  lea xcx, [xsi].DispInfoColl
  Override xcx::XWCollection.DestroyItem, DisplayInfoColl.DestroyItem

  ;Create the memory DC
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke ReleaseDC, [xsi].hWnd, hDC

  ;Create pens to draw
  mov [xsi].hPenLine, $invoke(CreatePen, PS_SOLID, 0, [xsi].ColorLine)
  mov [xsi].hPenToggler, $invoke(CreatePen, PS_SOLID, 0, [xsi].ColorToggler)
  mov [xsi].hPenAux, $invoke(CreatePen, PS_SOLID, 0, [xsi].ColorBackgroundDark)

  ;Set scrollbar infos
  mov ScrollInfo.cbSize, sizeof SCROLLINFO
  mov ScrollInfo.fMask, SIF_RANGE
  m2z ScrollInfo.nMin
  mov ScrollInfo.nMax, 0FFFFh       ;16 bit max value passed in WM_VSCROLL
  invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, FALSE

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  XPT_BrowseFolderCallback
; Purpose:    Set the initial path for SHBrowseForFolder.
; Arguments:  Arg1: Window handle.
;             Arg2: Message [BFFM_INITIALIZED, BFFM_IUNKNOWN, BFFM_SELCHANGED, BFFM_VALIDATEFAILED].
;             Arg3: Message parameter [BFFM_INITIALIZED, BFFM_IUNKNOWN,
;                                      BFFM_SELCHANGED, BFFM_VALIDATEFAILED].
;             Arg4: lParam member of the BROWSEINFO => XPT_PropertyNode.pVariable

XPT_BrowseFolderCallback proc hWnd:HWND, Msg:DWORD, lParam:LPARAM, pData:POINTER
  .if Msg == BFFM_INITIALIZED
    invoke SendMessage, hWnd, BFFM_SETSELECTION, TRUE, pData
  .endif
  ret
XPT_BrowseFolderCallback endp

; --------------------------------------------------------------------------------------------------
; Method:    XPropertyTree.OnCommand
; Purpose:   Event handler for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method XPropertyTree.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pValidateProc:ptr XPT_ValidateProc

  SetObject xsi
  mov xbx, [xsi].pSelectedNode
  .if (xbx != NULL) && ([xbx].$Obj(XTreeViewNode).dState & XTVNS_FOCUSED)
    mov xax, wParam
    shr xax, 16

    .if ax == EN_KILLFOCUS                              ;Edit lost the focus
      mov xax, [xsi].pEdtCtrl
      .if xax != NULL
        mov xcx, [xax].$Obj(WinControl).hWnd
        .if xcx == lParam
          invoke GetFocus
          mov xcx, [xsi].pBtnCtrl
          .if (xcx == NULL) || (xax != [xcx].$Obj(WinControl).hWnd)
            mov xax, [xsi].pEdtCtrl
            invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            mov xax, [xsi].pBtnCtrl
            .if xax != NULL
              invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            .endif
            mov xax, [xsi].pCBxCtrl
            .if xax != NULL
              invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            .endif
            BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_FOCUSED
            OCall xsi.GetDispInfo, xbx
            OCall xbx::XPT_PropertyNode.RenderContent, xax
            xor eax, eax
            ExitMethod
          .endif
        .endif
      .endif

    .elseif ax == BN_KILLFOCUS                          ;Button lost the focus
      mov xax, [xsi].pBtnCtrl
      .if xax != NULL
        mov xcx, [xax].$Obj(WinControl).hWnd
        .if xcx == lParam
          invoke GetFocus
          mov xcx, [xsi].pEdtCtrl
          .if (xcx == NULL) || (xax != [xcx].$Obj(WinControl).hWnd)
            mov xax, [xsi].pEdtCtrl
            .if xax != NULL
              invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            .endif
            mov xax, [xsi].pBtnCtrl
            invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_FOCUSED
            OCall xsi.GetDispInfo, xbx
            OCall xbx::XPT_PropertyNode.RenderContent, xax
            xor eax, eax
            ExitMethod
          .endif
        .endif
      .endif

    .elseif ax == CBN_KILLFOCUS                         ;Combo lost the focus
      mov xax, [xsi].pCBxCtrl
      .if xax != NULL
        mov xcx, [xax].$Obj(WinControl).hWnd
        .if xcx == lParam
          invoke GetFocus
          mov xcx, [xsi].pEdtCtrl
          .if (xcx == NULL) || (xax != [xcx].$Obj(WinControl).hWnd)
            mov xax, [xsi].pEdtCtrl
            .if xax != NULL
              invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            .endif
            mov xax, [xsi].pCBxCtrl
            .if xax != NULL
              invoke ShowWindow, [xax].$Obj(WinControl).hWnd, SW_HIDE
            .endif
            BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_FOCUSED
            OCall xsi.GetDispInfo, xbx
            OCall xbx::XPT_PropertyNode.RenderContent, xax
            ;Retrieve the setting of the combobox
            mov xcx, [xsi].pCBxCtrl
            .ifBitClr [xcx].$Obj(XPT_ComboBox).dState, XPTCB_ESCAPING
              invoke SendMessage, lParam, CB_GETCURSEL, 0, 0
              .if eax != CB_ERR
                ;Set variable
                mov xcx, [xbx].$Obj(XPT_PropertyNode).pVariable
                .if [xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_SYS_COLOR
                  mov xdx, offset XPT_SYS_COLOR_TABLE_EN_BEG
                  shl xax, $Log2(sizeof(XPT_SYS_COLOR_ENTRY))
                  mov eax, [xdx + xax].XPT_SYS_COLOR_ENTRY.dSystemIndex ;Read the table index value  
                .endif
                mov [xcx], eax                          ;Store the index
              .endif
            .endif
            xor eax, eax
            ExitMethod
          .endif
        .endif
      .endif

    .elseif ax == BN_CLICKED
      mov xax, [xsi].pBtnCtrl
      .if xax != NULL
        mov xcx, [xax].$Obj(WinControl).hWnd
        .if xcx == lParam
          .if [xbx].$Obj(XPT_PropertyNode).pVariable != NULL
            mov xdi, [xbx].$Obj(XPT_PropertyNode).pOptions

            .if [xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_COLOR
              .if xdi != NULL
                mov [xdi].CHOOSECOLOR.lStructSize, sizeof CHOOSECOLOR
                m2m [xdi].CHOOSECOLOR.hwndOwner, [xsi].hWnd, xdx
                mov xcx, [xbx].$Obj(XPT_PropertyNode).pVariable
                m2m [xdi].CHOOSECOLOR.rgbResult, DWORD ptr [xcx], xdx
                invoke ChooseColor, xdi
                .if eax
                  mov xcx, [xbx].$Obj(XPT_PropertyNode).pVariable
                  m2m DWORD ptr [xcx], [xdi].CHOOSECOLOR.rgbResult, edx
                .endif
                OCall xsi.GetDispInfo, xbx
                OCall xbx::XPT_PropertyNode.RenderContent, xax
                xor eax, eax
                ExitMethod
              .endif

            .elseif [xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_FILE
              .if xdi != NULL
                mov [xdi].OPENFILENAME.lStructSize, sizeof OPENFILENAME
                m2m [xdi].OPENFILENAME.hwndOwner, [xsi].hWnd, xdx
                invoke GetOpenFileName, xdi
                .if eax == TRUE
                  invoke StrCopy, [xbx].$Obj(XPT_PropertyNode).pVariable, \
                                  [xdi].OPENFILENAME.lpstrFile
                  OCall xsi.GetDispInfo, xbx
                  OCall xbx::XPT_PropertyNode.RenderContent, xax
                  xor eax, eax
                  ExitMethod
                .endif
              .endif

            .elseif [xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_PATH
              .if xdi != NULL
                m2m [xdi].BROWSEINFO.hwndOwner, [xsi].hWnd, xdx
                mov [xdi].BROWSEINFO.pidlRoot, NULL
                mov [xdi].BROWSEINFO.pszDisplayName, NULL
                mov [xdi].BROWSEINFO.lpszTitle, NULL
                mov [xdi].BROWSEINFO.ulFlags, BIF_RETURNONLYFSDIRS or BIF_USENEWUI
                m2m [xdi].BROWSEINFO.lpfn, offset XPT_BrowseFolderCallback, xdx
                m2m [xdi].BROWSEINFO.lParam, [xbx].$Obj(XPT_PropertyNode).pVariable, xcx
                m2z [xdi].BROWSEINFO.iImage
                invoke SHBrowseForFolder, xdi
                .if xax != NULL
                  push xax
                  invoke SHGetPathFromIDList, xax, [xbx].$Obj(XPT_PropertyNode).pVariable
                  pop xcx
                  invoke CoTaskMemFree, xcx
                  BitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_FOCUSED
                  OCall xsi.GetDispInfo, xbx
                  OCall xbx::XPT_PropertyNode.RenderContent, xax
                  xor eax, eax
                  ExitMethod
                .endif
              .endif
            .endif
          .endif
        .endif
      .endif

    .elseif (ax == EN_UPDATE) && \                      ;Edit has changed its text
      (([xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_CUSTOM) || \
       ([xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_INTEGER) || \
       ([xbx].$Obj(XPT_PropertyNode).dVarType == XPT_VAR_TYPE_REAL4))
      mov xcx, [xbx].$Obj(XPT_PropertyNode).pOptions
      .if xcx != NULL
        mov xax, [xsi].pEdtCtrl
        .if xax != NULL
          ;Save this value and set pOptions to NULL to avoid an infinite loop when the
          ;called procedure modifies the edit control.
          m2m pValidateProc, [xbx].$Obj(XPT_PropertyNode).pOptions, xdx
          m2z [xbx].$Obj(XPT_PropertyNode).pOptions
          invoke XPT_ValidateProc ptr xdx, [xax].$Obj(WinControl).hWnd
          m2m [xbx].$Obj(XPT_PropertyNode).pOptions, pValidateProc, xcx     ;Restore the value
          xor eax, eax
          ExitMethod
        .endif
      .endif

    .else
      invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
    .endif
  .endif

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnDestroy
; Purpose:    Event handler for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XPropertyTree.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "XPropertyTree.OnDestroy"

  SetObject xsi

  OCall [xsi].DispInfoColl::XWCollection.Done
  OCall [xsi].DispInfoPool::DataPool.Done

  invoke DeleteObject, [xsi].hPenLine
  invoke DeleteObject, [xsi].hPenToggler
  invoke DeleteObject, [xsi].hPenAux

  invoke DestroyCursor, [xsi].hCursorArrow

  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hBmpPrv)
  invoke DeleteDC, [xsi].hMemDC

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnDrawItem
; Purpose:    Event handler for WM_DRAWITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE if handled otherwise FALSE.

Method XPropertyTree.OnDrawItem, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local OutputRect:RECT, TextRect:RECT, pDispInfo:PXPTN_DISP_INFO
  local hPrevFont:HFONT, dPrevBkMode:DWORD, hWnd:HWND, dPrevColor:DWORD
  local hPrevPen:HPEN, dLeft:DWORD, hPrevBrush:HBRUSH, hBrush:HBRUSH
  local RRect:RECT, hRegion:HANDLE, Rct:RECT, AuxRect:RECT
  local pTableEnd:POINTER

  ;DbgText "XPropertyTree.OnDrawItem"
  SetObject xsi
  mov xdi, lParam
  .if wParam == XPT_CONTROL_ID_COMBOBOX
    mov xcx, [xsi].pCBxCtrl
    m2m hWnd, [xcx].$Obj(WinControl).hWnd, xdx
    mov xbx, [xcx].$Obj(WinControl).pOwner              ;xbx -> XPT_PropertyNode
    mov pDispInfo, $OCall(xsi.GetDispInfo, xbx)
    assume xbx:ptr $Obj(XPT_PropertyNode), xdi:ptr DRAWITEMSTRUCT

    c2m pTableEnd, offset XPT_SYS_COLOR_TABLE_EN_END, r10

    .ifBitSet [xdi].itemState, ODS_COMBOBOXEDIT
      ;This is the edit control of the combobox
      mov edx, [xax].XPTN_DISP_INFO.TextRect.bottom
      sub edx, [xax].XPTN_DISP_INFO.TextRect.top
      mov OutputRect.bottom, edx
      mov ecx, [xax].XPTN_DISP_INFO.ContentRect.right
      sub ecx, [xax].XPTN_DISP_INFO.TextRect.left
      mov OutputRect.right, ecx
      xor eax, eax
      mov OutputRect.top, eax
      mov OutputRect.left, eax
      mov hRegion, $invoke(CreateRectRgn, 0, 0, OutputRect.right, OutputRect.bottom)
      invoke SelectClipRgn, [xdi].hDC, hRegion
      invoke DeleteObject, hRegion
      mov hBrush, $invoke(CreateSolidBrush, $32($invoke(GetSysColor, COLOR_WINDOW)))
      invoke FillRect, [xdi].hDC, addr OutputRect, hBrush
      invoke DeleteObject, hBrush                       ;Delete brush

      invoke GetSysColor, COLOR_WINDOWTEXT
      mov dPrevColor, $32($invoke(SetTextColor, [xdi].hDC, eax))
      mov hPrevFont, $invoke(SelectObject, [xdi].hDC, [xbx].hFont)
      mov dPrevBkMode, $32($invoke(SetBkMode, [xdi].hDC, TRANSPARENT))

      ;In case of XPT_VAR_TYPE_SYS_COLOR, draw a colored rectangle
      .if [xbx].dVarType == XPT_VAR_TYPE_SYS_COLOR
        .if [xdi].itemData != -1
          ;Find the matching color index
          mov xcx, offset XPT_SYS_COLOR_TABLE_EN_BEG
          mov xax, [xdi].itemData
          .while xcx < pTableEnd
            .break .if xax == [xcx].XPT_SYS_COLOR_ENTRY.pDescription   ;Compare pointers
            add xcx, sizeof XPT_SYS_COLOR_ENTRY
          .endw
          .if xcx < pTableEnd
            invoke GetSysColorBrush, [xcx].XPT_SYS_COLOR_ENTRY.dSystemIndex
          .else
            invoke GetStockObject, HOLLOW_BRUSH
          .endif
        .else
          invoke GetStockObject, HOLLOW_BRUSH
        .endif
        mov hPrevBrush, $invoke(SelectObject, [xdi].hDC, xax)

        ;Render a colored rectangle
        mov eax, OutputRect.bottom                      ;Create the stack for the Rectangle API
        mov ecx, eax
        sub eax, XPT_ICON_SIZE
        shr eax, 1
        sub ecx, eax
        mov AuxRect.bottom, ecx
        mov RRect.bottom, ecx
        mov eax, XPT_MARGIN + XPT_ICON_SIZE
        mov AuxRect.right, eax
        mov RRect.right, eax
        sub ecx, XPT_ICON_SIZE
        mov AuxRect.top, ecx
        mov RRect.top, ecx
        sub eax, XPT_ICON_SIZE
        mov AuxRect.left, eax
        mov RRect.left, eax
        invoke Rectangle, [xdi].hDC, AuxRect.left, AuxRect.top, AuxRect.right, AuxRect.bottom
        .if [xdi].itemData == -1
          ;If the index is invalid, then draw a cross
          mov eax, RRect.right
          mov ecx, RRect.bottom
          dec eax
          dec ecx
          mov AuxRect.left, eax
          mov AuxRect.top, ecx
          invoke MoveToEx, [xdi].hDC, RRect.left, RRect.top, NULL
          invoke LineTo, [xdi].hDC, AuxRect.left, AuxRect.top
          invoke MoveToEx, [xdi].hDC, AuxRect.left, RRect.top, NULL
          invoke LineTo, [xdi].hDC, RRect.left, AuxRect.top
        .endif
        invoke SelectObject, [xdi].hDC, hPrevBrush

        mov TextRect.left, XPT_ICON_SIZE + 2*XPT_MARGIN
      .else
        m2z TextRect.left
      .endif

      ;Draw the text
      mov eax, OutputRect.bottom
      sub eax, [xbx].dFontHeight
      shr eax, 1
      mov TextRect.top, eax
      add eax, [xbx].dFontHeight
      mov TextRect.bottom, eax

      mov ecx, [xbx].dFontAveWidth
      add TextRect.left, ecx
      mov ecx, OutputRect.right
      mov xax, pDispInfo
      sub ecx, [xax].XPTN_DISP_INFO.ButtonRect.right
      add ecx, [xax].XPTN_DISP_INFO.ButtonRect.left
      sub ecx, [xbx].dFontAveWidth
      mov TextRect.right, ecx

      .if [xdi].itemData == -1
        invoke SetTextColor, [xdi].hDC, $RGB(255,0,0)
        mov xdx, offset cInvalidSelection
      .else
        mov xdx, [xdi].itemData
      .endif

      invoke DrawText, [xdi].hDC, xdx, -1, addr TextRect, DT_SINGLELINE or DT_LEFT or DT_END_ELLIPSIS

      ;Restore previous settings
      invoke SelectObject, [xdi].hDC, hPrevFont
      invoke SetBkMode, [xdi].hDC, dPrevBkMode
      invoke SetTextColor, [xdi].hDC, dPrevColor

      ;Render a down pointing arrow
      mov hBrush, $invoke(CreateSolidBrush, $32($invoke(GetSysColor, COLOR_WINDOW)))
      mov xcx, pDispInfo
      mov edx, [xcx].XPTN_DISP_INFO.ButtonRect.bottom
      sub edx, [xcx].XPTN_DISP_INFO.ButtonRect.top
      mov RRect.bottom, edx
      mov edx, [xcx].XPTN_DISP_INFO.ButtonRect.right
      sub edx, [xcx].XPTN_DISP_INFO.TextRect.left
      mov RRect.right, edx
      mov edx, [xcx].XPTN_DISP_INFO.ButtonRect.left
      sub edx, [xcx].XPTN_DISP_INFO.TextRect.left
      mov RRect.left, edx
      m2z RRect.top
      invoke FillRect, [xdi].hDC, addr RRect, hBrush
      invoke DeleteObject, hBrush
      mov xax, pDispInfo
      mov ecx, [xax].XPTN_DISP_INFO.ButtonRect.left
      sub ecx, [xax].XPTN_DISP_INFO.TextRect.left
      add ecx, 4
      mov OutputRect.left, ecx
      mov ecx, [xax].XPTN_DISP_INFO.ButtonRect.right
      sub ecx, [xax].XPTN_DISP_INFO.TextRect.left
      sub ecx, 2
      mov OutputRect.right, ecx
      invoke DrawFrameControl, [xdi].hDC, addr OutputRect, DFC_MENU, 16 or DFCS_TRANSPARENT

      ;Draw a vertical separation line
      mov hPrevPen, $invoke(SelectObject, [xdi].hDC, [xsi].hPenAux)
      mov xcx, pDispInfo
      mov eax, [xcx].XPTN_DISP_INFO.ButtonRect.left
      sub eax, [xcx].XPTN_DISP_INFO.TextRect.left
      mov dLeft, eax
      mov eax, [xcx].XPTN_DISP_INFO.ContentRect.bottom
      sub eax, [xcx].XPTN_DISP_INFO.ContentRect.top
      dec eax
      invoke MoveToEx, [xdi].hDC, dLeft, eax, NULL
      invoke LineTo, [xdi].hDC, dLeft, -1
      invoke SelectObject, [xdi].hDC, hPrevPen

    .else
      ;These are the list box items
      .if [xdi].itemData != -1
        mov hPrevFont, $invoke(SelectObject, [xdi].hDC, [xbx].hFont)
        mov dPrevBkMode, $32($invoke(SetBkMode, [xdi].hDC, TRANSPARENT))
        .ifBitSet [xdi].itemState, ODS_SELECTED
          invoke GetSysColor, COLOR_HIGHLIGHTTEXT
          mov dPrevColor, $32($invoke(SetTextColor, [xdi].hDC, eax))
          invoke GetSysColor, COLOR_HIGHLIGHT
        .else
          invoke GetSysColor, COLOR_WINDOWTEXT
          mov dPrevColor, $32($invoke(SetTextColor, [xdi].hDC, eax))
          invoke GetSysColor, COLOR_WINDOW
        .endif
        mov hBrush, $invoke(CreateSolidBrush, eax)
        invoke FillRect, [xdi].hDC, addr [xdi].rcItem, xax
        invoke DeleteObject, hBrush

        .if [xbx].dVarType == XPT_VAR_TYPE_SYS_COLOR
          ;Find the matching color index
          mov xcx, offset XPT_SYS_COLOR_TABLE_EN_BEG
          mov xax, [xdi].itemData
          .while xcx < pTableEnd
            .break .if xax == [xcx].XPT_SYS_COLOR_ENTRY.pDescription   ;Compare pointers
            add xcx, sizeof XPT_SYS_COLOR_ENTRY
          .endw
          mov eax, [xcx].XPT_SYS_COLOR_ENTRY.dSystemIndex

          ;Render the rect
          invoke GetSysColorBrush, eax                  ;Don't delete this brush
          mov hPrevBrush, $invoke(SelectObject, [xdi].hDC, xax)
          mov eax, [xdi].rcItem.bottom
          sub eax, XPT_MARGIN
          mov Rct. bottom, eax
          mov eax, [xdi].rcItem.left
          add eax, XPT_MARGIN + XPT_COLOR_RECT_SIZE
          mov Rct.right, eax
          mov ecx, [xdi].rcItem.top
          add ecx, XPT_MARGIN
          mov Rct.top, ecx
          sub eax, XPT_COLOR_RECT_SIZE
          mov Rct.left, eax
          invoke Rectangle, [xdi].hDC, Rct.left, Rct.top, Rct.right, Rct.bottom
          invoke SelectObject, [xdi].hDC, hPrevBrush

          add [xdi].rcItem.left, XPT_COLOR_RECT_SIZE + 2*XPT_MARGIN

        .else
          mov eax, [xbx].dFontAveWidth
          add [xdi].rcItem.left, eax

        .endif

        invoke DrawText, [xdi].hDC, [xdi].itemData, -1, addr [xdi].rcItem, \
                     DT_SINGLELINE or DT_LEFT or DT_END_ELLIPSIS

        ;Restore previous settings
        invoke SelectObject, [xdi].hDC, hPrevFont
        invoke SetBkMode, [xdi].hDC, dPrevBkMode
        invoke SetTextColor, [xdi].hDC, dPrevColor
      .endif
    .endif
    assume xbx:NOTHING, xdi:NOTHING

  .elseif wParam == XPT_CONTROL_ID_BUTTON
    mov xcx, [xsi].pBtnCtrl
    m2m hWnd, [xcx].$Obj(WinControl).hWnd, xdx
    mov xbx, [xcx].$Obj(WinControl).pOwner              ;xbx -> XPT_PropertyNode
    mov pDispInfo, $OCall(xsi.GetDispInfo, xbx)
    assume xbx:ptr $Obj(XPT_PropertyNode), xdi:ptr DRAWITEMSTRUCT
    mov ecx, [xdi].itemState

    mov hPrevFont, $invoke(SelectObject, [xdi].hDC, [xbx].hFont)
    mov dPrevBkMode, $32($invoke(SetBkMode, [xdi].hDC, TRANSPARENT))
    mov dPrevColor, $32($invoke(SetTextColor, [xdi].hDC, $32($invoke(GetSysColor, COLOR_WINDOWTEXT))))
    mov hBrush, $invoke(CreateSolidBrush, $32($invoke(GetSysColor, COLOR_WINDOW)))
    invoke FillRect, [xdi].hDC, addr [xdi].rcItem, xax
    invoke DrawText, [xdi].hDC, $OfsCStr("..."), -1, addr [xdi].rcItem, \
                 DT_SINGLELINE or DT_CENTER or DT_VCENTER
    invoke DeleteObject, hBrush

    ;Restore previous settings
    invoke SelectObject, [xdi].hDC, hPrevFont
    invoke SetBkMode, [xdi].hDC, dPrevBkMode
    invoke SetTextColor, [xdi].hDC, dPrevColor

    assume xbx:NOTHING, xdi:NOTHING

  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnKeyDown
; Purpose:    Event handler for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XPropertyTree.OnKeyDown, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  .if [xsi].pSelectedNode != NULL
    mov xax, wParam

    .if eax == VK_UP
      ;Move to the above node
      mov xdx, [xsi].pSelectedNode
      mov xbx, xdx
      XTV_BrowseBack xdx
      test xdx, xdx
      jz @@Exit                                         ;Nothing to do, avoid flicker
      OCall xsi.Select, xdx
      OCall xsi.GetDispInfo, [xsi].pSelectedNode
      .if ecx == 0                                      ;First node in view
        m2z [xsi].dFirstOffset
        mov xax, [xsi].pFirstChild
        .if xax == [xsi].pSelectedNode
          m2z [xsi].TotalOffset.y
        .endif
        OCall xsi.Draw
      .elseif xax == NULL                               ;Not in view
        OCall xsi.MoveInViewTop, [xsi].pSelectedNode
        OCall xsi.Draw
      .else
        OCall [xsi].pSelectedNode::XTreeViewNode.RenderContent, xax
        OCall xsi.GetDispInfo, xbx
        OCall xbx::XTreeViewNode.RenderContent, xax
      .endif

    .elseif eax == VK_DOWN
      ;Move to the next lower node
      mov xdx, [xsi].pSelectedNode
      mov xbx, xdx
      XTV_BrowseFrwd xdx
      test xdx, xdx
      jz @@Exit                                         ;Nothing to do, avoid flicker
      OCall xsi.Select, xdx
      OCall xsi.GetDispInfo, [xsi].pSelectedNode
      mov edx, [xsi].DispInfoColl.dCount
      dec edx
      .if ecx >= edx                                    ;Is it the last node in view,
        OCall xsi.MoveInViewBottom, [xsi].pSelectedNode ;  or is it not in view
        OCall xsi.Draw
      .else
        OCall [xsi].pSelectedNode::XTreeViewNode.RenderContent, xax
        OCall xsi.GetDispInfo, xbx
        OCall xbx::XTreeViewNode.RenderContent, xax
      .endif

    .elseif eax == VK_RIGHT
      ;First expand if collapsed and then move to the first child
      mov xbx, [xsi].pSelectedNode
      cmp [xbx].$Obj(XTreeViewNode).pFirstChild, NULL
      jz @@Exit                                         ;Nothing to do, avoid flicker
      .ifBitClr [xbx].$Obj(XTreeViewNode).dState, XTVNS_EXPANDED
        OCall xbx::XTreeViewNode.Toggle
      .else
        mov xbx, [xbx].$Obj(XTreeViewNode).pFirstChild
        OCall xsi.Select, xbx
      .endif

      ;Node is now expanded; maybe we have to reposition the tree
      OCall xsi.GetDispInfo, xbx
      mov eax, [xax].XTVN_DISP_INFO.sdNodeTop
      add eax, [xsi].TotalOffset.y                      ;eax = node offset
      mov edx, eax
      add edx, [xbx].$Obj(XTreeViewNode).dHeight
      add edx, [xbx].$Obj(XTreeViewNode).dBranchHeight
      sub edx, [xsi].ClientSize.y
      sub edx, [xsi].TotalOffset.y
      .if !SIGN?
        mov ecx, eax                                    ;The last branch node is off view
        sub ecx, [xsi].TotalOffset.y
        sub ecx, edx
        .if !SIGN?
          add eax, [xbx].$Obj(XTreeViewNode).dHeight
          add eax, [xbx].$Obj(XTreeViewNode).dBranchHeight
          sub eax, [xsi].ClientSize.y
        .endif
        OCall xsi.Find1stVisibleNode, eax
      .endif
      OCall xsi.Draw

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
          m2m [xsi].ClientSize.x, CRect.right, ecx
          m2m [xsi].ClientSize.y, CRect.bottom, edx
        .endif

        XTV_GetBottomViewNode xsi, xcx, eax, xdx
        .if xcx == NULL
          OCall xsi.MoveInViewBottom, xdx
        .endif
      .else
        cmp [xcx].$Obj(XTreeViewNode).pParent, NULL
        jz @@Exit                                       ;Nothing to do, avoid flicker
        mov xdx, [xcx].$Obj(XTreeViewNode).pParent
        push xdx
        OCall xsi.Select, xdx
        pop xdx
        OCall xsi.GetDispInfo, xdx
        .if ecx == 0                                    ;First node in view
          m2z [xsi].dFirstOffset
        .elseif xax == NULL                             ;Not in view
          OCall xsi.MoveInViewTop, [xsi].pSelectedNode
        .endif
      .endif
      ;Check if the selected node is in view
      XTV_GetBottomViewNode xsi, xcx, eax, xdx
      .if xcx == NULL
        OCall xsi.MoveInViewBottom, xdx
      .endif
      OCall xsi.Draw

    .elseif eax == VK_PRIOR                             ;VK_PGUP
      mov xax, [xsi].pFirstChild
      cmp xax, [xsi].pSelectedNode
      je @@Exit                                         ;Nothing to do, avoid flicker

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
      OCall xsi.Draw

    .elseif eax == VK_NEXT                              ;VK_PGDN
      mov xax, [xsi].pLastChild
      cmp xax, [xsi].pSelectedNode
      je @@Exit                                         ;Nothing to do, avoid flicker

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
      push xax
      push xcx
      OCall xsi.Select, xax
      pop xcx
      pop xax
      .if xcx == NULL
        OCall xsi.MoveInViewBottom, xax
      .endif
      OCall xsi.Draw

    .elseif eax == VK_HOME
      ;Go to the first node in the tree
      mov xdx, [xsi].pFirstChild
      cmp xdx, [xsi].pSelectedNode
      je @@Exit                                         ;Nothing to do, avoid flicker
      mov xbx, xdx
      OCall xsi.Set1stVisibleNode, xdx
      OCall xsi.Select, xbx
      m2z [xsi].TotalOffset.y
      m2z [xsi].dFirstOffset
      OCall xsi.Draw

    .elseif eax == VK_END
      ;Go to the last node in the tree
      mov xdx, [xsi].pLastChild
      .while xdx != NULL
        .break .if XTV_IsCollapsed(xdx)
        mov xcx, xdx
        mov xdx, [xdx].$Obj(XTreeViewNode).pLastChild
      .endw
      .if xdx == NULL
        mov xdx, xcx
      .endif
      cmp xdx, [xsi].pSelectedNode
      je @@Exit                                         ;Nothing to do, avoid flicker
      mov xbx, xdx
      OCall xsi.Select, xdx
      OCall xsi.MoveInViewBottom, xbx
      OCall xsi.Draw

    .else
      jmp @@Exit
    .endif
    xor eax, eax

  .else
@@Exit:
    invoke DefWindowProc, [xsi].hWnd, WM_KEYDOWN, wParam, lParam

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnMeasureItem
; Purpose:    Event handler for WM_MEASUREITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns TRUE.

Method XPropertyTree.OnMeasureItem, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "XPropertyTree.OnMeasureItem"
  SetObject xsi
  mov xcx, [xsi].pCBxCtrl
  SetObject xbx, XPT_PropertyNode, [xcx].$Obj(WinControl).pOwner
  mov xcx, lParam
  .ifBitSet [xcx].MEASUREITEMSTRUCT.CtlType, ODT_COMBOBOX
    OCall xsi.GetDispInfo, xbx
    .if xax != NULL
      mov xcx, lParam
      mov edx, [xax].XPTN_DISP_INFO.TextRect.right
      sub edx, [xax].XPTN_DISP_INFO.TextRect.left
      mov [xcx].MEASUREITEMSTRUCT.itemWidth, edx
      .if [xcx].MEASUREITEMSTRUCT.itemID == -1          ;Edit control
        mov edx, [xax].XPTN_DISP_INFO.sdNodeBot
        sub edx, [xax].XPTN_DISP_INFO.sdNodeTop
        sub edx, 6 + 1
        mov [xcx].MEASUREITEMSTRUCT.itemHeight, edx
      .else
        mov [xcx].MEASUREITEMSTRUCT.itemHeight, 2*XPT_MARGIN + XPT_COLOR_RECT_SIZE
      .endif
    .endif
  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnMouseWheel
; Purpose:    Event handler for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.
; Note:       If the shift key is pressed, the horizontal scrollbar is moved.

Method XPropertyTree.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "XPropertyTree.OnMouseWheel"
  SetObject xsi
  mov xdx, [xsi].pSelectedNode
  .if (xdx != NULL) && ([xdx].$Obj(XTreeViewNode).dState & XTVNS_FOCUSED)
    invoke SetFocus, [xsi].hWnd
  .endif
  ACall xsi.OnMouseWheel, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnSize
; Purpose:    Event handler for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method XPropertyTree.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xdx, [xsi].pSelectedNode
  .if (xdx != NULL) && ([xdx].$Obj(XTreeViewNode).dState & XTVNS_FOCUSED)
    invoke SetFocus, [xsi].hWnd
  .endif
  ACall xsi.OnSize, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.OnVScroll
; Purpose:    Event handler for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XPropertyTree.OnVScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "XPropertyTree.OnVScroll"
  SetObject xsi
  mov xdx, [xsi].pSelectedNode
  .if (xdx != NULL) && ([xdx].$Obj(XTreeViewNode).dState & XTVNS_FOCUSED)
    invoke SetFocus, [xsi].hWnd
  .endif
  ACall xsi.OnVScroll, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.RenderBackground
; Purpose:    Draw the background of a specified rect.
; Arguments:  Arg1: -> RECT.
; Return:     Nothing.

Method XPropertyTree.RenderBackground, uses xsi, pRect:PRECT
  local hBrush:HBRUSH

  SetObject xsi
  mov hBrush, $invoke(CreateSolidBrush, [xsi].ColorBackgroundDark)
  invoke FillRect, [xsi].hMemDC, pRect, xax
  invoke DeleteObject, hBrush
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.ShowScrollbars
; Purpose:    Show or hide the scrollbars and update the ClientSize member.
; Arguments:  None.
; Return:     Nothing.

Method XPropertyTree.ShowScrollbars, uses xsi
  ;DbgText "ShowScrollbars"
  SetObject xsi
  xor eax, eax

  mov edx, [xsi].DrawSize.y
  sub edx, [xsi].TotalSize.y
  sets al
  mov edx, [xsi].DrawSize.x
  .if SIGN?
    sub edx, [xsi].ScrollbarMetric.x
  .endif
  mov [xsi].ClientSize.x, edx

  invoke ShowScrollBar, [xsi].hWnd, SB_VERT, eax        ;Switch vertical scrollbar
  invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, FALSE      ;Hide horizontal scrollbar
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPropertyTree.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the
;             message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method XPropertyTree.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "XPropertyTree Messages"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance

      mov xsi, $New(XPropertyTree)
      OCall xsi::XPropertyTree.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(XPropertyTree).hWnd, pSelf, xcx
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::XPropertyTree.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::XPropertyTree.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    XPropertyTree.Startup
; Purpose:   Register the XPropertyTree object with the OS.
; Arguments: None.
; Return:    Nothing.

Method XPropertyTree.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_PARENTDC or CS_BYTEALIGNWINDOW or \
                CS_BYTEALIGNCLIENT or CS_DBLCLKS
  m2m WC.lpfnWndProc, $MethodAddr(XPropertyTree.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset cClassNameXPT, r10
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_XTV_ARROW"))
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd



; ==================================================================================================
;     XPT_Edit
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     XPT_Edit.Done
; Purpose:    Finalize the XPT_Edit object.
; Arguments:  None.
; Return:     Nothing.

Method XPT_Edit.Done, uses xsi
  ;DbgText "XPT_Edit.Done"
  SetObject xsi
  Unsubclass XPT_Edit                                   ;uses xsi
  invoke DestroyWindow, [xsi].hWnd
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_Edit.Init
; Purpose:    Initialize the XPT_Edit object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Initialization structure.
; Return:     Nothing.

Method XPT_Edit.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PXPT_CTRLDEF
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PXPT_CTRLDEF
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("EDIT"), [xbx].pTitle, [xbx].dStyle, \
                     [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                     hParent, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  Subclass XPT_Edit                                     ;uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_Edit.OnKeyDown
; Purpose:    Event handler for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XPT_Edit.OnKeyDown, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[20]:CHR

  SetObject xsi
  mov xax, wParam
  .if eax == VK_ESCAPE
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(XPT_PropertyNode).pOwner
    invoke SetFocus, [xcx].$Obj(XPropertyTree).hWnd
    xor eax, eax

  .elseif eax == VK_RETURN
    SetObject xdi, XPT_PropertyNode, [xsi].pOwner
    .if [xdi].dVarType == XPT_VAR_TYPE_STRING
      invoke GetWindowText, [xsi].hWnd, [xdi].pVariable, DWORD ptr [xdi].pOptions
      mov xax, [xdi].pVariable

    .elseif [xdi].dVarType == XPT_VAR_TYPE_INTEGER
      invoke GetWindowText, [xsi].hWnd, addr cBuffer, lengthof cBuffer
      invoke StrToSt0, addr cBuffer
      .if eax == f_OK
        mov xax, [xdi].pVariable
        fistp DWORD ptr [xax]
      .endif

    .elseif [xdi].dVarType == XPT_VAR_TYPE_REAL4
      invoke GetWindowText, [xsi].hWnd, addr cBuffer, lengthof cBuffer
      invoke StrToSt0, addr cBuffer
      .if eax == f_OK
        mov xax, [xdi].pVariable
        fstp REAL4 ptr [xax]
      .endif

    .endif

    mov xcx, [xdi].pOwner
    invoke SetFocus, [xcx].$Obj(XPropertyTree).hWnd
    xor eax, eax

  .else

    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_KEYDOWN, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_Edit.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method XPT_Edit.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "XPT_Edit"
  GetSubclassingInst XPT_Edit, pSelf
  OCall xax::XPT_Edit.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;     XPT_Button
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     XPT_Button.Done
; Purpose:    Finalize the XPT_Button object.
; Arguments:  None.
; Return:     Nothing.

Method XPT_Button.Done, uses xsi
  ;DbgText "XPT_Button.Done"
  SetObject xsi
  Unsubclass XPT_Button                                 ;uses xsi
  invoke DestroyWindow, [xsi].hWnd
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_Button.Init
; Purpose:    Initialize the XPT_Button object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Initialization structure.
; Return:     Nothing.

Method XPT_Button.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PXPT_CTRLDEF
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PXPT_CTRLDEF
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("BUTTON"), [xbx].pTitle, [xbx].dStyle, \
                     [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                     hParent, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  Subclass XPT_Button                                   ;Needs xsi -> XPT_Button
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_Button.OnKeyDown
; Purpose:    Event handler for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XPT_Button.OnKeyDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if eax == VK_ESCAPE
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(XPT_PropertyNode).pOwner
    invoke SetFocus, [xcx].$Obj(XPropertyTree).hWnd
    xor eax, eax
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_KEYDOWN, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_Button.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message
;             ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method XPT_Button.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  GetSubclassingInst XPT_Button, pSelf
  OCall xax::XPT_Button.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;     XPT_ComboBox
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     XPT_ComboBox.Done
; Purpose:    Finalize the XPT_ComboBox object.
; Arguments:  None.
; Return:     Nothing.

Method XPT_ComboBox.Done, uses xsi
  ;DbgText "XPT_ComboBox.Done"
  SetObject xsi
  Unsubclass XPT_ComboBox                               ;uses xsi
  invoke DestroyWindow, [xsi].hWnd
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_ComboBox.Init
; Purpose:    Initialize the XPT_ComboBox object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Initialization structure.
; Return:     Nothing.

Method XPT_ComboBox.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PXPT_CTRLDEF
  SetObject xsi
  m2m [xsi].pOwner, pOwner, xdx                         ;Do this to get the owner in WM_MEASUREITEM
  mov xbx, pDefStruc
  assume xbx:PXPT_CTRLDEF
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("ComboBox"), [xbx].pTitle, [xbx].dStyle, \
                         [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  Subclass XPT_ComboBox                                 ;uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_ComboBox.OnKeyDown
; Purpose:    Event handler for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XPT_ComboBox.OnKeyDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if eax == VK_ESCAPE
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(XPT_PropertyNode).pOwner
    BitSet [xsi].dState, XPTCB_ESCAPING                 ;Set a flag
    invoke SetFocus, [xcx].$Obj(XPropertyTree).hWnd
    xor eax, eax
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_KEYDOWN, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     XPT_ComboBox.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message
;             ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method XPT_ComboBox.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg;,, "XPT_ComboBox Messages"
  GetSubclassingInst XPT_ComboBox, pSelf
  OCall xax::XPT_ComboBox.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
