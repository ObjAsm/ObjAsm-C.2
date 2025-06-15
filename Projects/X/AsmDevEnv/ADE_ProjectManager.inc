; ==================================================================================================
; Title:      ADE_ProjectManager.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of project window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



PROJTVSTYLE   equ   TVS_HASBUTTONS or TVS_HASLINES or TVS_LINESATROOT or TVS_EDITLABELS or TVS_SHOWSELALWAYS or TVS_TRACKSELECT

PROJTBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT

CStr szProjectManager, "ProjectManager"

PMF_EMPTY     equ   BIT00
PMF_DIRTY     equ   BIT01

.const
ProjTreeView DEF_TREEVIEW {100, PROJTVSTYLE, TVS_EX_DOUBLEBUFFER, NULL, {<0,0,0,0>}}

;ProjToolbar DEF_TOOLBAR {101, PROJTBSTYLE, 0, NULL, {<0,0,0,0>}, 3}
;  TBBUTTON {IDB_PROJ_OPEN,  IDM_PROJ_OPEN,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
;  TBBUTTON {IDB_PROJ_SAVE,  IDM_PROJ_SAVE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
;  TBBUTTON {IDB_PROJ_CLOSE, IDM_PROJ_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON}


; ==================================================================================================
; ProjectManager implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.ConfigLoad
; Purpose:    Load the application configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectManager.ConfigLoad, uses xdi xsi,
  local dIndex:DWORD
  local cFullFileName[1024]:CHR, cItemName[20]:CHR, cItemBuffer[4096]:CHR

  SetObject xsi
  invoke GetFullPathName, addr szConfigurationFile, lengthof cFullFileName, addr cFullFileName, NULL

  ;Load project manager Treeview colors
  invoke GetPrivateProfileString, addr szGUI, addr szPrjMgrColors, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
  invoke GetColorFromString, addr cItemBuffer, DefaultProjFG
  mov xdi, xcx
  mov [xsi].ForeColor, eax
  .if xdi != NULL
    invoke GetColorFromString, addr [xdi + sizeof CHR], DefaultProjBG
    mov xdi, xcx
    mov [xsi].BackColor, eax
    .if xdi != NULL
      invoke GetColorFromString, addr [xdi + sizeof CHR], DefaultProjLN
      mov [xsi].LineColor, eax
    .endif
  .endif

  ;Load project manager initial width
  invoke GetPrivateProfileString, addr szGUI, addr szPrjMgrWidth, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
  invoke GetIntegerFromString, addr cItemBuffer, -1
  .if SDWORD ptr eax > 0
    mov [xsi].dInitialWidth, eax
  .endif


  ;Load default groups for a new project
  mov dIndex, 0
  .while TRUE
    lea xdi, cItemName
    WriteF xdi, "¦UD", dIndex
    invoke GetPrivateProfileString, addr szGroups, addr cItemName, NULL, \
                                    addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
    .break .if xax == NULL
    invoke StrNew, addr cItemBuffer
    OCall [xsi].DefaultGroups::%StrCollection.InsertAt, dIndex, xax
    inc dIndex
  .endw

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.Done
; Purpose:    Finalize the ProjectManager object and free allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method ProjectManager.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TBar::Toolbar.Done
  OCall [xsi].TView::TreeView.Done
  OCall [xsi].DefaultGroups::%StrCollection.Done

  invoke StrDispose, [xsi].pProjName
  invoke StrDispose, [xsi].pProjFileName
  invoke StrDispose, [xsi].pProjDirPath
  invoke StrDispose, [xsi].pProjDescription

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.IsFileAlreadyPresent
; Purpose:    Check whether the file already exists.
; Arguments:  Arg1: -> Full file name.
; Return:     xax: HTREEITEM if it is present, otherwise 0.

SearchInBranch proc hTreeView:HWND, hParent:HTREEITEM, pFullFileName:PSTRING
  local Item:TVITEM

  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xax, Item.lParam
      .if [xax].PROJECTITEM.dType == PIT_GROUP
        invoke SearchInBranch, hTreeView, Item.hItem, pFullFileName
        .break .if xax != 0
      .else
        .if [xax].PROJECTITEM.dType == PIT_FILE
          invoke StrComp, [xax].PROJECTITEM.pFileName, pFullFileName
          .if eax == 0
            mov xax, Item.hItem
            .break
          .endif
        .endif
      .endif
      invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, Item.hItem
    .endif
  .endw
  ret
SearchInBranch endp

Method ProjectManager.IsFileAlreadyPresent, uses xsi, pFullFileName:PSTRING
;  DbgText "ProjectManager.IsFileAlreadyPresent"
  SetObject xsi
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
  invoke SearchInBranch, [xsi].TView.hWnd, xax, pFullFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.GetGroupByIndex
; Purpose:    Retrieve the group HTREEITEM by its index.
; Arguments:  Arg1: Index (0 = root, 1 = first group, 2 = second group, ...).
; Return:     xax = HTREEITEM.

Method ProjectManager.GetGroupByIndex, uses xbx xsi, dIndex:DWORD
  SetObject xsi
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
  .if dIndex == 0
    ret
  .endif
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, xax
  mov ebx, dIndex
  dec ebx
  .While !ZERO?
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_NEXT, xax
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.GetNextFileItem
; Purpose:    Retrieve the next project file item from the TreeView.
; Arguments:  Arg1: Last HTREEITEM.
; Return:     xax = Next HTREEITEM corresponding to a file.
;             xcx -> PROJECTITEM if xax != 0.

;   Proj
;    |
;    +--Group
;    |    |
;    |    +--File 
;    |    +--Command 
;    |    +--Group             (this is not implemented in the ProjMgr yet)
;    |    |    |
;    |    |    '--File 
;    |    '--File 
;    '--Group
;         |
;         +--File 
;         +--File 
;         '--File
;     

Method ProjectManager.GetNextFileItem, uses xbx xsi, hLastItem:HTREEITEM
  local Item:TVITEM

  SetObject xsi
  
  ;Get the next leaf item
  mov xax, hLastItem
  .while TRUE
    .while TRUE
      @@:
      mov xbx, xax
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, xax
      cmp xax, 0
      jnz @B
      mov xax, xbx
      .break .if xax != hLastItem
  
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_NEXT, xbx
      .continue .if xax != 0
  
      @@:
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_PARENT, xbx
      .break .if xax == 0
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_NEXT, xax
      cmp xax, 0
      jz @B
    .endw

    .break .if xax == 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    mov xax, Item.hItem
    mov hLastItem, xax
    mov xcx, Item.lParam
    .break .if [xcx].PROJECTITEM.dType == PIT_FILE
  .endw
MethodEnd


; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.GroupsCollapse
; Purpose:    Collapse the TreeView so that only the groups are visible.
; Arguments:  None.
; Return:     Nothing.

Method ProjectManager.GroupsCollapse, uses xbx xdi xsi
  local Item:TVITEM

  SetObject xsi
  
  ;Store the first visible item in the root item 
  mov xdi, $invoke(SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0)
  mov Item.hItem, xax
  mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_FIRSTVISIBLE, 0
  mov xcx, Item.lParam
  mov [xcx].PROJECTITEM.hVisible, xax  
  
  ;Store expansion information amd collapse groups
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, xdi
  .while xax != 0
    mov xbx, xax
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_STATE or TVIF_PARAM
    mov Item.stateMask, TVIS_EXPANDED
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    mov xax, Item.lParam
    .ifBitSet Item.state, TVIS_EXPANDED
      BitSet [xax].PROJECTITEM.dFlags, PIF_EXPANDED
      invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_COLLAPSE, xbx
    .else
      BitClr [xax].PROJECTITEM.dFlags, PIF_EXPANDED
    .endif
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_NEXT, xbx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.GroupsExpandRestore
; Purpose:    Restore each group to its original state prior to invoking GroupsCollapse.
; Arguments:  Arg1: HTREEITEM of the item we want to show. If zero, the original item before the 
;             GroupsCollapse invocation is retored.
; Return:     Nothing.

Method ProjectManager.GroupsExpandRestore, uses xbx xsi, hFirstVisible:HTREEITEM
  local Item:TVITEM

  SetObject xsi
  ;Restore group expansion
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, xax
  .while xax != 0
    mov xbx, xax
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    mov xcx, Item.lParam
    .ifBitSet [xcx].PROJECTITEM.dFlags, PIF_EXPANDED
      invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, xbx
    .endif
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_NEXT, xbx
  .endw

  ;Restore first visible item
  mov xax, hFirstVisible 
  .if xax != 0
    ;Expand the parent
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_PARENT, hFirstVisible
    invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, xax
    ;Make it visible
    invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hFirstVisible
  .else
    mov Item.hItem, $invoke(SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0)
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    mov xax, Item.lParam
    invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, [xax].PROJECTITEM.hVisible
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.Init
; Purpose:    Initialize the ProjectManager object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method ProjectManager.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, offset szProjectManager, $OfsCStr("Project Manager"), \
                         WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, 0, hInstance, xsi
  BitSet [xsi].dFlags, PMF_EMPTY
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL

  OCall [xsi].DefaultGroups::%StrCollection.Init, xsi, 10,10, COL_MAX_CAPACITY
  OCall [xsi].DragDrop::Component.Init, xsi, NULL       ;Init component
  mov xbx, $New(IDropTarget)             ;Create IDropTarget interface
  OCall [xsi].DragDrop.Interfaces::Collection.Insert, xax
  OCall xbx::IDropTarget.Init, addr [xsi].DragDrop, [xsi].TView.hWnd

  invoke RegisterDragDrop, [xsi].TView.hWnd, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.OnCreate
; Purpose:    Event procedure for WM_CONTEXTMENU message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectManager.OnContextMenu, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local SceenPoint:POINT, tvht:TVHITTESTINFO, Item:TVITEM, hContextMenu:HMENU

  ANNOTATION use:wParam

  SetObject xsi
  PntS2Pnt SceenPoint, lParam
  mov xbx, [xsi].pOwner
  .ifBitSet [xsi].dFlags, PMF_EMPTY
    invoke GetMenu, [xbx].$Obj(Application).hWnd
    mov hContextMenu, $invoke(GetSubMenu, xax, 1)
    invoke TrackPopupMenuEx, hContextMenu, TPM_LEFTALIGN or TPM_TOPALIGN or TPM_RIGHTBUTTON, \
                             SceenPoint.x, SceenPoint.y, [xbx].$Obj(Application).hWnd, NULL
    invoke PostMessage, [xbx].$Obj(Application).hWnd, WM_NULL, 0, 0  ;Fix: menu not popping up right
  
  .else
    ;Find out if the cursor is on an item
    s2s tvht.pt, SceenPoint, xax, xdx
    invoke ScreenToClient, [xsi].TView.hWnd, addr tvht.pt
    invoke SendMessage, [xsi].TView.hWnd, TVM_HITTEST, 0, addr tvht
    .if xax != 0
      mov Item.hItem, xax
      mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
      invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_CARET, Item.hItem
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
      mov xdx, Item.lParam
      mov ecx, [xdx].PROJECTITEM.dType
      .if ecx == PIT_GROUP
        mov edx, 1
      .elseif ecx == PIT_FILE
        mov edx, 2
      .elseif ecx == PIT_COMMAND
        mov edx, 3
      .else
        xor edx, edx
      .endif
      mov hContextMenu, $invoke(GetSubMenu, [xbx].$Obj(Application).hMenuContextProject, edx)
      invoke TrackPopupMenuEx, hContextMenu, TPM_LEFTALIGN or TPM_TOPALIGN or TPM_RIGHTBUTTON, \
                               SceenPoint.x, SceenPoint.y, [xbx].$Obj(Application).hWnd, NULL
      invoke PostMessage, [xbx].$Obj(Application).hWnd, WM_NULL, 0, 0  ;Fix: menu not popping up right
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectManager.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 8
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FOLDER_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FOLDER_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CODE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CMD")

  lea xdi, [xsi].TView
  OCall xdi::TreeView.Init, xsi, [xsi].hWnd, xbx, offset ProjTreeView
  
  invoke SendMessage, [xsi].TView.hWnd, TVM_SETTEXTCOLOR, 0, [xsi].ForeColor
  invoke SendMessage, [xsi].TView.hWnd, TVM_SETBKCOLOR,   0, [xsi].BackColor
  invoke SendMessage, [xsi].TView.hWnd, TVM_SETLINECOLOR, 0, [xsi].LineColor

  invoke DefWindowProc, [xsi].hWnd, WM_CREATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ProjectManager.OnLButtonUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hDropOnItem:HTREEITEM, DropOnItem:TVITEM, DragSrcItem:TVITEM

  ANNOTATION use:wParam

;  DbgText "ProjectManager.OnLButtonUp"
  SetObject xsi
  .if [xsi].dDragging != FALSE
    ;Manage the "Drop" operation
    ;Get destination item.
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_DROPHILITE, 0
    .if xax != 0
      mov hDropOnItem, xax
      ;Make sure that the destination is a "Group" item
      mov DropOnItem.hItem, xax
      mov DropOnItem.mask_, TVIF_HANDLE or TVIF_PARAM
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr DropOnItem
      mov xbx, DropOnItem.lParam
      .if [xbx].PROJECTITEM.dType != PIT_PROJECT          ;Don't drop on the root
        .if [xbx].PROJECTITEM.dType != PIT_GROUP
          invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_PARENT, hDropOnItem
          mov hDropOnItem, xax
        .endif

        ;Insert the new item
        mov DragSrcItem.mask_, TVIF_HANDLE or TVIF_IMAGE or TVIF_PARAM
        m2m DragSrcItem.hItem, [xsi].hDragSrcItem, xax
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr DragSrcItem
        mov xbx, DragSrcItem.lParam
        OCall xsi.ProjItemInsert, hDropOnItem, TVI_SORT, \
                                  [xbx].PROJECTITEM.pDispName, [xbx].PROJECTITEM.pFileName, \
                                  [xbx].PROJECTITEM.dType, \
                                  DragSrcItem.iImage, \
                                  [xbx].PROJECTITEM.hEditor
        ;Set Cursor at new item
        invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_CARET, xax
        invoke SetFocus, [xsi].TView.hWnd

        ;Delete old item
        invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, [xsi].hDragSrcItem

        ;Expand parent
        invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, hDropOnItem

      .endif
      invoke ImageList_EndDrag
      invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_DROPHILITE, 0    ;Remove Hilite
      invoke ReleaseCapture
      invoke ShowCursor, TRUE
      mov [xsi].dDragging, FALSE
      BitSet [xsi].dFlags, PMF_DIRTY
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method ProjectManager.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT, tvht:TVHITTESTINFO

  ANNOTATION use:wParam

;  DbgText "ProjectManager.OnMouseMove"
  SetObject xsi
  .if [xsi].dDragging != FALSE
    invoke GetKeyState, VK_ESCAPE
    .ifBitSet eax, BIT07
      invoke ImageList_EndDrag
      invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_DROPHILITE, 0    ;Remove Hilite
      invoke ReleaseCapture
      invoke ShowCursor, TRUE
      mov [xsi].dDragging, FALSE
    .else
      PntS2Pnt Pnt, lParam
      invoke ClientToScreen, [xsi].hWnd, addr Pnt
      invoke ScreenToClient, [xsi].TView.hWnd, addr Pnt
      invoke ImageList_DragMove, Pnt.x, Pnt.y
      ;Turn the dragged image off so the background can be refreshed.
      invoke ImageList_DragShowNolock, FALSE
      ;Find out if the cursor is on the item. If it is, highlight the item as a drop target.
      s2s POINT ptr tvht.pt, POINT ptr Pnt.x, xax, xdx
      invoke SendMessage, [xsi].TView.hWnd, TVM_HITTEST, 0, addr tvht
      .if xax != 0
        invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_DROPHILITE, tvht.hItem  ;Draw
      .elseif tvht.flags == TVHT_ABOVE
        invoke SendMessage, [xsi].TView.hWnd, WM_VSCROLL, SB_LINEUP, 0
      .elseif tvht.flags == TVHT_BELOW
        invoke SendMessage, [xsi].TView.hWnd, WM_VSCROLL, SB_LINEDOWN, 0
      .elseif tvht.flags == TVHT_TOLEFT
        invoke SendMessage, [xsi].TView.hWnd, WM_HSCROLL, SB_LINELEFT, 0
      .elseif tvht.flags == TVHT_TORIGHT
        invoke SendMessage, [xsi].TView.hWnd, WM_HSCROLL, SB_LINERIGHT, 0
      .endif
      ;Turn the dragged image on again
      invoke ImageList_DragShowNolock, TRUE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.
; Link:       https://learn.microsoft.com/en-us/windows/win32/controls/drag-a-tree-view-item

Method ProjectManager.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hImgList:HIMAGELIST, Item:TVITEM, cBuffer[1024]:CHR

;  DbgText "ProjectManager.OnNotify"
  SetObject xsi
  mov xbx, lParam
  .if [xbx].NMHDR.code == TVN_BEGINDRAG
    m2m Item.hItem, [xbx].NMTREEVIEW.itemNew.hItem, xax
    mov Item.mask_, TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xcx, Item.lParam
      .if [xcx].PROJECTITEM.dType == PIT_FILE || [xcx].PROJECTITEM.dType == PIT_COMMAND
        ;Tell the tree-view control to create an image to use for dragging.
        mrm [xsi].hDragSrcItem, [xbx].NMTREEVIEW.itemNew.hItem, xax
        invoke SendMessage, [xsi].TView.hWnd, TVM_CREATEDRAGIMAGE, 0, xax
        mov hImgList, xax
        ;Start the drag operation.
        invoke ImageList_BeginDrag, hImgList, 0, 0, 0
        invoke ImageList_DragEnter, [xsi].TView.hWnd, [xbx].NMTREEVIEW.ptDrag.x, [xbx].NMTREEVIEW.ptDrag.y

        ;Hide the mouse pointer, and direct mouse input to the parent window.
        invoke ShowCursor, FALSE
        invoke SetCapture, [xsi].hWnd                   ;Send messages to ProjectManager
        mov [xsi].dDragging, TRUE
      .endif
    .endif

  .elseif [xbx].NMHDR.code == TVN_DELETEITEM
    mov xbx, [xbx].NMTREEVIEW.itemOld.lParam
    mov ecx, [xbx].PROJECTITEM.dType
    .if ecx == PIT_FILE || ecx == PIT_COMMAND 
      invoke StrDispose, [xbx].PROJECTITEM.pDispName
      invoke StrDispose, [xbx].PROJECTITEM.pFileName
    .endif
    MemFree xbx

  .elseif [xbx].NMHDR.code == NM_DBLCLK
    mov xax, [xsi].TView.hWnd
    .if [xbx].NMHDR.hwndFrom == xax
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0
      .if xax != 0
        mov Item.hItem, xax
        mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
        .if eax != FALSE
          mov xbx, Item.lParam
          .if [xbx].PROJECTITEM.dType == PIT_FILE
            mov xdi, [xsi].pOwner                         ;xdi -> Application
            .if [xbx].PROJECTITEM.hEditor != 0
              mov xax, [xdi].$Obj(Application).pClientWnd
              invoke SendMessage, [xax].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xbx].PROJECTITEM.hEditor, 0
              mov xax, [xdi].$Obj(Application).pClientWnd
              invoke SendMessage, [xax].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
              .if xax == [xbx].PROJECTITEM.hEditor
                ExitMethod
              .endif
            .endif
            OCall xdi::Application.LaunchEditor, [xbx].PROJECTITEM.pFileName, SW_SHOW

          .elseif [xbx].PROJECTITEM.dType == PIT_GROUP
            invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_TOGGLE, Item.hItem

          .elseif [xbx].PROJECTITEM.dType == PIT_COMMAND
            mov xcx, [xsi].pOwner
            invoke SendMessage, [xcx].$Obj(Application).hWnd, WM_COMMAND, IDM_PROJ_CMD_EXECUTE, 0

          .endif
        .endif
      .endif
    .endif

  .elseif [xbx].NMHDR.code == TVN_KEYDOWN
    mov xax, [xsi].TView.hWnd
    .if [xbx].NMHDR.hwndFrom == xax
      .if [xbx].NMTVKEYDOWN.wVKey == VK_DELETE
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0
        mov xdi, xax
        ;Never delete the root item
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
        .if xdi != xax
          mov Item.hItem, xdi
          mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
          invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
          mov xcx, Item.lParam
          .if [xcx].PROJECTITEM.dType == PIT_GROUP
            invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, xdi
            .if xax != 0
              lea xbx, cBuffer
              mov xax, Item.lParam
              WriteF xbx, "Are you sure that you want to delete the \´¦ST\´ group and all of its files?", [xax].PROJECTITEM.pDispName  
              invoke MessageBox, [xsi].hWnd, addr cBuffer, $OfsCStr("Warning"), MB_OKCANCEL or MB_ICONWARNING 
              .if eax == IDCANCEL
                xor eax, eax
                ExitMethod
              .endif
            .endif
          .endif
          invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, xdi
          BitSet [xsi].dFlags, PMF_DIRTY
          mov xbx, [xsi].pOwner
          mov xcx, [xbx].$Obj(Application).pClientWnd
          invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
          OCall xbx::Application.ManageGuiCmds, xax
        .endif
      .elseif [xbx].NMTVKEYDOWN.wVKey == VK_INSERT
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0
        mov Item.hItem, xax
        mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
        mov xcx, Item.lParam
        mov xax, [xsi].pOwner
        .if [xcx].PROJECTITEM.dType == PIT_PROJECT
          invoke SendMessage, [xax].$Obj(Application).hWnd, WM_COMMAND, IDM_PROJ_NEWGROUP, 0
        .elseif [xcx].PROJECTITEM.dType == PIT_GROUP
          invoke SendMessage, [xax].$Obj(Application).hWnd, WM_COMMAND, IDM_PROJ_GROUP_NEW, 0
        .endif
        BitSet [xsi].dFlags, PMF_DIRTY
        mov xbx, [xsi].pOwner
        mov xcx, [xbx].$Obj(Application).pClientWnd
        invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
        OCall xbx::Application.ManageGuiCmds, xax
      .endif
    .endif

  .elseif [xbx].NMHDR.code == TVN_ITEMEXPANDED
    ;Manage the Group icon
    .ifBitSet [xbx].NMTREEVIEW.action, TVE_EXPAND
      mov Item.iImage, ICON_INDEX_GROUP_OPEN
      mov Item.iSelectedImage, ICON_INDEX_GROUP_OPEN
    .else
      mov Item.iImage, ICON_INDEX_GROUP_CLOSE
      mov Item.iSelectedImage, ICON_INDEX_GROUP_CLOSE
    .endif
    m2m Item.hItem, [xbx].NMTREEVIEW.itemNew.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_IMAGE or TVIF_SELECTEDIMAGE
    invoke SendMessage, [xsi].TView.hWnd, TVM_SETITEM, 0, addr Item
  
    ;Manage the GUI commands
    BitSet [xsi].dFlags, PMF_DIRTY
    mov xbx, [xsi].pOwner
    mov xcx, [xbx].$Obj(Application).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    OCall xbx::Application.ManageGuiCmds, xax

  .elseif [xbx].NMHDR.code == TVN_BEGINLABELEDIT
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    mov xcx, Item.lParam
    .if [xcx].PROJECTITEM.dType == PIT_GROUP
      mov [xsi].hEdit, $invoke(SendMessage, [xsi].TView.hWnd, TVM_GETEDITCONTROL, 0, 0)
      xor eax, eax
    .else
      mov eax, TRUE                                     ;Cancel operation
    .endif

  .elseif [xbx].NMHDR.code == TVN_ENDLABELEDIT
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    invoke GetWindowText, [xsi].hEdit, addr cBuffer, lengthof(cBuffer)
    inc eax
    mov Item.TVITEM.cchTextMax, eax
    mov Item.mask_, TVIF_HANDLE or TVIF_TEXT
    mov xcx, Item.lParam
    invoke StrReplace, addr [xcx].PROJECTITEM.pDispName, addr cBuffer
    lea xdx, cBuffer
    mov Item.pszText, xdx
    invoke SendMessage, [xsi].TView.hWnd, TVM_SETITEM, 0, addr Item
    mov [xsi].hEdit, 0
    BitSet [xsi].dFlags, PMF_DIRTY
    mov xbx, [xsi].pOwner
    mov xcx, [xbx].$Obj(Application).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    OCall xbx::Application.ManageGuiCmds, xax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectManager.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, CtRect:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr CtRect

  mov ebx, CtRect.right
  sub ebx, CtRect.left
  mov eax, CtRect.bottom
  sub eax, CtRect.top
  sub eax, [xsi].dToolbarHeight                         ;Let space for buttons
  dec eax
  dec eax
  invoke MoveWindow, [xsi].TView.hWnd, CtRect.left, CtRect.top, ebx, eax, TRUE

  mov eax, CtRect.bottom
  sub eax, [xsi].dToolbarHeight
  inc CtRect.left
  dec eax
  invoke MoveWindow, [xsi].TBar.hWnd, CtRect.left, eax, ebx, [xsi].dToolbarHeight, TRUE

  invoke EndPaint, [xsi].hWnd, addr PS
  invoke DefWindowProc,[xsi].hWnd, WM_PAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.ProjectCreateNew
; Purpose:    Create a default project configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectManager.ProjectCreateNew, uses xbx xdi xsi
  local hRootItem:HTREEITEM, cBuffer[1024]:CHR

;  DbgText "ProjectManager.ProjectCreateNew"
  SetObject xsi
  ;Reset complete TreeView
  invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, TVI_ROOT

  mov xax, [xsi].pProjDirPath
  .if xax != NULL
    invoke StrLength, xax
  .endif
  .if xax == 0                                          ;No name defined
    mov [xsi].pProjDirPath, $invoke(StrNew, $OfsCStr(".\"))
  .endif

  ;Create "project" root item from Group "0"
  mov xax, [xsi].pProjName
  .if xax != NULL
    invoke StrLength, xax
  .endif
  .if xax == 0                                          ;No name defined
    .if [xsi].DefaultGroups.dCount != 0
      OCall [xsi].DefaultGroups::%StrCollection.ItemAt, 0
    .else
      mov xax, $OfsCStr("Solution")
    .endif
    mov [xsi].pProjName, $invoke(StrNew, xax)
  .endif
  OCall xsi.ProjItemInsert, 0, TVI_ROOT, [xsi].pProjName, NULL, PIT_PROJECT, ICON_INDEX_GROUP_CLOSE, 0
  mov hRootItem, xax

  ;Create the file name
  mov xax, [xsi].pProjFileName
  .if xax != NULL
    invoke StrLength, xax
  .endif
  .if xax == 0                                          ;No name defined
    lea xdi, cBuffer
    WriteF xdi, "¦ST.adep", [xsi].pProjName
    mov [xsi].pProjFileName, $invoke(StrNew, addr cBuffer)
  .endif

  ;Create child items from Group "1".."n"
  mov xdi, xax
  xor ebx, ebx
  .while TRUE
    inc ebx
    .break .if ebx >= [xsi].DefaultGroups.dCount
    OCall [xsi].DefaultGroups::%StrCollection.ItemAt, ebx
    OCall xsi.ProjItemInsert, hRootItem, TVI_LAST, xax, NULL, PIT_GROUP, ICON_INDEX_GROUP_CLOSE, 0
  .endw

  ;Expand all items
  invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, hRootItem
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, hRootItem
  mov xbx, xax
  .While xbx != 0
    invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, xbx
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, xbx, 0
    mov xbx, xax
  .endw

  BitClr [xsi].dFlags, PMF_EMPTY or PMF_DIRTY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.ProjectLoadFrom
; Purpose:    Load the project configuration.
; Arguments:  Arg1: -> File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectManager.ProjectLoadFrom, uses xbx xdi xsi, pConfigFileName:PSTRING
  local cConfigFileName[1024]:CHR, dConfigFilePresent:DWORD
  local hRootItem:HTREEITEM, TVI:TV_INSERTSTRUCT, dIndex:DWORD, dGroupExpand:DWORD
  local DskStream:$Obj(DiskStream), pParent:PJSON_PROPERTY, pChild:PJSON_PROPERTY, pGroups:PJSON_PROPERTY
  local pDispName:PSTRING, pFileName:PSTRING

  SetObject xsi
  ;Reset complete TreeView
  invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, TVI_ROOT

  invoke GetFullPathName, pConfigFileName, lengthof cConfigFileName - 1, addr cConfigFileName, NULL
  invoke StrReplace, addr [xsi].pProjFileName, addr cConfigFileName
  invoke FileExist, addr cConfigFileName
  mov dConfigFilePresent, eax
  .if eax == FALSE
    invoke MsgBox, 0, addr szWarnNoProj, addr szWarning, MB_OK or MB_ICONWARNING
    ExitMethod
  .endif
  New DskStream::DiskStream
  OCall DskStream::DiskStream.Init, xsi, addr cConfigFileName, GENERIC_READ, \
                                    0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  mov xbx, $New(Json)
  OCall xbx::Json.Init, xsi
  OCall xbx::Json.Read, addr DskStream


  OCall xbx::Json.GetProperty, addr [xbx].$Obj(Json).RootProperty, addr szIdentification
  cmp xax, NULL
  je @@Error
  mov pParent, xax
  OCall xbx::Json.GetProperty, pParent, addr szDescription
  cmp xax, NULL
  je @@Error
  invoke StrComp, [xax].JSON_PROPERTY.pValue, addr szDescADEP
  cmp eax, 0
  jne @@Error
  OCall xbx::Json.GetProperty, pParent, addr szVersion
  cmp xax, NULL
  je @@Error
  invoke GetVersionFromString, [xax].JSON_PROPERTY.pValue
  .if eax != [xsi].dReqMainVersion || ecx < [xsi].dMinSubVersion
;    invoke MsgBox, 0, addr szWarnOldProj, addr szWarning, MB_OK or MB_ICONWARNING
    jmp @@Error
  .endif


  OCall xbx::Json.GetProperty, addr [xbx].$Obj(Json).RootProperty, addr szProject
  cmp xax, NULL
  je @@Error
  mov pParent, xax
  OCall xbx::Json.GetProperty, pParent, addr szName
  .if xax == NULL
    lea xdx, szSolution
  .else
    mov xdx, [xax].JSON_PROPERTY.pValue
  .endif
  invoke StrReplace, addr [xsi].pProjName, xdx
  OCall xsi.ProjItemInsert, 0, TVI_ROOT, [xsi].pProjName, NULL, PIT_PROJECT, ICON_INDEX_GROUP_CLOSE, 0
  mov hRootItem, xax

  OCall xbx::Json.GetProperty, pParent, addr szPath
  .if xax == NULL
    lea xdx, szLocalPath
  .else
    mov xdx, [xax].JSON_PROPERTY.pValue
  .endif
  invoke StrReplace, addr [xsi].pProjDirPath, xdx
  OCall xbx::Json.GetProperty, pParent, addr szDescription
  .if xax == NULL
    mov xdx, NULL
  .else
    mov xdx, [xax].JSON_PROPERTY.pValue
  .endif
  invoke StrReplace, addr [xsi].pProjDescription, xdx


  OCall xbx::Json.GetProperty, addr [xbx].$Obj(Json).RootProperty, addr szGroups
  cmp xax, NULL
  je @F
  mov pGroups, xax
  mov dIndex, 0
  .while TRUE
    OCall xbx::Json.GetArrayItem, pGroups, dIndex
    .break .if xax == NULL
    OCall xbx::Json.GetProperty, xax, addr szName
    OCall xsi.ProjItemInsert, hRootItem, TVI_LAST, [xax].JSON_PROPERTY.pValue, NULL, PIT_GROUP, ICON_INDEX_GROUP_CLOSE, 0
    inc dIndex
  .endw

@@:
  OCall xbx::Json.GetProperty, addr [xbx].$Obj(Json).RootProperty, addr szFiles
  cmp xax, NULL
  je @F
  mov pParent, xax
  mov dIndex, 0
  .while TRUE
    OCall xbx::Json.GetArrayItem, pParent, dIndex
    .break .if xax == NULL
    mov pChild, xax
    MemAlloc sizeof(PROJECTITEM)                        ;xdi -> PROJECTITEM
    cmp xax, NULL
    je @@Error
    mov xdi, xax
    mov [xdi].PROJECTITEM.hEditor, 0
    OCall xbx::Json.GetProperty, pChild, addr szDispName
    invoke StrNew, [xax].JSON_PROPERTY.pValue
    mov [xdi].PROJECTITEM.pDispName, xax
    OCall xbx::Json.GetProperty, pChild, addr szFileName
    invoke StrNew, [xax].JSON_PROPERTY.pValue
    mov [xdi].PROJECTITEM.pFileName, xax
    OCall xbx::Json.GetProperty, pChild, addr szType
    invoke dec2dword, [xax].JSON_PROPERTY.pValue
    mov [xdi].PROJECTITEM.dType, eax
    OCall xbx::Json.GetProperty, pChild, addr szGroup
    invoke dec2dword, [xax].JSON_PROPERTY.pValue
    OCall xsi.GetGroupByIndex, eax                      ;xax = HTREEITEM
    mov TVI.hParent, xax
    mov TVI.hInsertAfter, TVI_SORT
    mov TVI.item.mask_, TVIF_HANDLE or TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
    invoke StrLength, [xdi].PROJECTITEM.pDispName
    mov TVI.item.cchTextMax, eax
    m2m TVI.item.pszText, [xdi].PROJECTITEM.pDispName, xdx
    mov TVI.item.iImage, ICON_INDEX_FILE
    mov TVI.item.iSelectedImage, ICON_INDEX_FILE
    .if [xdi].PROJECTITEM.dType == PIT_COMMAND
      mov TVI.item.iImage, ICON_INDEX_CMD
      mov TVI.item.iSelectedImage, ICON_INDEX_CMD
    .endif
    mov TVI.item.lParam, xdi
    invoke SendMessage, [xsi].TView.hWnd, TVM_INSERTITEM, 0, addr TVI

    inc dIndex
  .endw

@@:
  ;Always expand the Root item
  invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, hRootItem

  ;Expand groups according to the configuration
  mov dIndex, 0
  .while TRUE
    OCall xbx::Json.GetArrayItem, pGroups, dIndex
    .break .if xax == NULL
    OCall xbx::Json.GetProperty, xax, addr szExpanded
    invoke StrComp, [xax].JSON_PROPERTY.pValue, addr JSON_FALSE
    mov dGroupExpand, eax
    inc dIndex
    OCall xsi.GetGroupByIndex, dIndex                     ;xax = HTREEITEM
    .if dGroupExpand != FALSE
      invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, xax
    .endif
  .endw

  ;Always make the Root visible
  invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hRootItem

@@Error:
  Destroy xbx
  OCall DskStream::DiskStream.Done

  BitClr [xsi].dFlags, PMF_EMPTY or PMF_DIRTY
  mov xbx, [xsi].pOwner
  mov xcx, [xbx].$Obj(Application).pClientWnd
  invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
  OCall xbx::Application.ManageGuiCmds, xax
  
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.ProjectSave
; Purpose:    Save the project configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectManager.ProjectSave
;  DbgText "ProjectManager.ProjectSave"
  SetObject xax
  OCall xax.ProjectSaveTo, [xax].pProjFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.ProjectSaveTo
; Purpose:    Save the project configuration.
; Arguments:  Arg1: -> File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

SaveGroups proc uses xbx hTreeView:HWND, hParent:HTREEITEM, pJson:$ObjPtr(Json), pParent:PJSON_PROPERTY
  local Item:TVITEM, pExpanded:PSTRING, pChild:PJSON_PROPERTY

  mov Item.mask_, TVIF_HANDLE or TVIF_STATE or TVIF_PARAM
  mov Item.stateMask, TVIS_EXPANDED
  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    mov xbx, Item.lParam
    .if [xbx].PROJECTITEM.dType == PIT_GROUP
      lea xax, JSON_FALSE
      .ifBitSet Item.state, TVIS_EXPANDED
        lea xax, JSON_TRUE
      .endif
      mov pExpanded, xax
      mov pChild, $OCall(pJson::Json.AddObject, pParent, NULL)
      OCall pJson::Json.AddData, pChild, addr szName, JSON_TYPE_STRING, [xbx].PROJECTITEM.pDispName
      OCall pJson::Json.AddData, pChild, addr szExpanded, JSON_TYPE_BOOLEAN, pExpanded
    .endif
    invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, Item.hItem
  .endw
  ret
SaveGroups endp

SaveFilesInBranch proc uses xbx hTreeView:HWND, hParent:HTREEITEM, pJson:$ObjPtr(Json), pParent:PJSON_PROPERTY, pGroupCounter:POINTER
  local Item:TVITEM, cBuffer[1024]:CHR, pChild:PJSON_PROPERTY

  mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    mov xbx, Item.lParam
    .if [xbx].PROJECTITEM.dType == PIT_GROUP
      mov xax, pGroupCounter
      inc DWORD ptr [xax]
      invoke SaveFilesInBranch, hTreeView, Item.hItem, pJson, pParent, pGroupCounter
    .else
      mov pChild, $OCall(pJson::Json.AddObject, pParent, NULL)
      OCall pJson::Json.AddData, pChild, addr szDispName, JSON_TYPE_STRING, [xbx].PROJECTITEM.pDispName
      OCall pJson::Json.AddData, pChild, addr szFileName, JSON_TYPE_STRING, [xbx].PROJECTITEM.pFileName
      invoke dword2dec, addr cBuffer, [xbx].PROJECTITEM.dType
      OCall pJson::Json.AddData, pChild, addr szType, JSON_TYPE_NUMBER, addr cBuffer
      mov xax, pGroupCounter
      invoke dword2dec, addr cBuffer, DWORD ptr [xax]
      OCall pJson::Json.AddData, pChild, addr szGroup, JSON_TYPE_NUMBER, addr cBuffer
    .endif
    invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, Item.hItem
  .endw
  ret
SaveFilesInBranch endp

Method ProjectManager.ProjectSaveTo, uses xbx xsi, pConfigFileName:PSTRING
  local cConfigFileName[1024]:CHR, dGroupCounter:DWORD, hRoot:HTREEITEM
  local DskStream:$Obj(DiskStream), pParent:PJSON_PROPERTY

;  DbgText "ProjectManager.ProjectSaveTo"
  SetObject xsi
  .ifBitSet [xsi].dFlags, PMF_DIRTY
    invoke GetFullPathName, pConfigFileName, lengthof cConfigFileName - 1, addr cConfigFileName, NULL
    mov hRoot, $invoke(SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0)

    New DskStream::DiskStream
    OCall DskStream::DiskStream.Init, xsi, addr cConfigFileName, GENERIC_WRITE, \
                                      0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
    mov xbx, $New(Json)
    OCall xbx::Json.Init, xsi
    mov [xbx].$Obj(Json).RootProperty.dType, JSON_TYPE_OBJECT

    ;Save "Identification" data
    mov pParent, $OCall(xbx::Json.AddObject, addr [xbx].$Obj(Json).RootProperty, addr szIdentification)
    OCall xbx::Json.AddData, pParent, addr szDescription, JSON_TYPE_STRING, addr szDescADEP
    OCall xbx::Json.AddData, pParent, addr szVersion, JSON_TYPE_STRING, $OfsCStr("1.0")

    ;Save "Project" data
    mov pParent, $OCall(xbx::Json.AddObject, addr [xbx].$Obj(Json).RootProperty, addr szProject)
    OCall xbx::Json.AddData, pParent, addr szName, JSON_TYPE_STRING, [xsi].pProjName
    OCall xbx::Json.AddData, pParent, addr szPath, JSON_TYPE_STRING, [xsi].pProjDirPath
    OCall xbx::Json.AddData, pParent, addr szDescription, JSON_TYPE_STRING, [xsi].pProjDescription

    ;Save "Groups" data
    mov pParent, $OCall(xbx::Json.AddArray, addr [xbx].$Obj(Json).RootProperty, addr szGroups)
    invoke SaveGroups, [xsi].TView.hWnd, hRoot, xbx, pParent

    ;Save "Files" data
    mov pParent, $OCall(xbx::Json.AddArray, addr [xbx].$Obj(Json).RootProperty, addr szFiles)
    mov dGroupCounter, 0
    invoke SaveFilesInBranch, [xsi].TView.hWnd, hRoot, xbx, pParent, addr dGroupCounter

    OCall xbx::Json.Write, addr DskStream
    Destroy xbx
    OCall DskStream::DiskStream.Truncate
    OCall DskStream::DiskStream.Done
    BitClr [xsi].dFlags, PMF_DIRTY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.ProjItemInsert
; Purpose:    Insert a new PROJECTITEM in the TreeView.
; Arguments:  Arg1: Treeview parent node HANDLE.
;             Arg2: TreeView HANDLE of the node, after the new item is inserted.
;             Arg3: -> Display text.
;             Arg4: -> Full file name.
;             Arg5: Flags (PIF_XXX)
;             Arg6: Image icon index.
;             Arg8: Editor HWND.
; Return:     xax = HTREEITEM.

Method ProjectManager.ProjItemInsert, uses xbx xsi, hNodeParent:HANDLE, hNodeAfter:HANDLE, \
                                  pDispText:PSTRING, pFullFileName:PSTRING, dFlags:DWORD, \
                                  dImgIndex:DWORD, hEditor:HWND
  local TVI:TV_INSERTSTRUCT

;  DbgText "ProjectManager.ProjItemInsert"
  SetObject xsi
  MemAlloc sizeof(PROJECTITEM)
  mov TVI.item.lParam, xax
  .if xax != NULL
    mov xbx, xax
    invoke StrNew, pDispText
    mov [xbx].PROJECTITEM.pDispName, xax
    invoke StrNew, pFullFileName
    mov [xbx].PROJECTITEM.pFileName, xax
    m2m [xbx].PROJECTITEM.dType, dFlags, ecx
    m2m [xbx].PROJECTITEM.hEditor, hEditor, xdx

    m2m TVI.hParent, hNodeParent, xax
    m2m TVI.hInsertAfter, hNodeAfter, xdx
    mov TVI.item.mask_, TVIF_HANDLE or TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
    invoke StrLength, [xbx].PROJECTITEM.pDispName
    mov TVI.item.cchTextMax, eax
    m2m TVI.item.pszText, [xbx].PROJECTITEM.pDispName, xax
    mov edx, dImgIndex
    mov TVI.item.iImage, edx
    mov TVI.item.iSelectedImage, edx
    invoke SendMessage, [xsi].TView.hWnd, TVM_INSERTITEM, 0, addr TVI
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ProjectManager.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(ProjectManager.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_BTNFACE + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szProjectManager, xax
  m2z WC.hIcon
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectManager.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method ProjectManager.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam

  DbgMessage uMsg, "ProjectManager.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mrm [xsi].$Obj(Window).hWnd, pSelf, xcx             ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax                                       ;  it returns NULL
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd
