; ==================================================================================================
; Title:      ADE_ProjectWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of project window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


IDB_PROJ_OPEN     equ   0
IDB_PROJ_SAVE     equ   1
IDB_PROJ_CLOSE    equ   2

IDM_PROJ_OPEN     equ   200
IDM_PROJ_SAVE     equ   201
IDM_PROJ_CLOSE    equ   202


PROJTVSTYLE   equ   TVS_HASBUTTONS or TVS_HASLINES or TVS_LINESATROOT or TVS_EDITLABELS or TVS_SHOWSELALWAYS or TVS_TRACKSELECT

PROJTBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT

CStr szProjectWnd, "ProjectWnd"

.const
ProjTreeView DEF_TREEVIEW {100, PROJTVSTYLE, 0, NULL, {<0,0,0,0>}}

ProjToolbar DEF_TOOLBAR {101, PROJTBSTYLE, 0, NULL, {<0,0,0,0>}, 3}
  TBBUTTON {IDB_PROJ_OPEN,  IDM_PROJ_OPEN,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_PROJ_SAVE,  IDM_PROJ_SAVE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_PROJ_CLOSE, IDM_PROJ_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON}


.code
; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.ConfigLoad
; Purpose:    Open the project configuration.
; Arguments:  Arg1: -> Ini-File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.ConfigLoad, uses xbx xdi xsi, pIniFileName:PSTRING
  local dIconIndex:DWORD, dIniFilePresent:DWORD, hProjRootNode:HTREEITEM
  local cIniFileName[1024]:CHR, cItemName[20]:CHR, cItemBuffer[4096]:CHR, TVI:TV_INSERTSTRUCT

  SetObject xsi
  invoke GetFullPathName, pIniFileName, lengthof cIniFileName - 1, addr cIniFileName, NULL
  invoke FileExist, addr cIniFileName
  mov dIniFilePresent, eax
  .if eax == FALSE
    invoke MsgBox, 0, addr cWarnNoProj, addr cWarning, MB_OK or MB_ICONWARNING
  .endif

  ;Load version and analyse
  invoke GetPrivateProfileString, addr cIniSectIdentification, addr cVersion, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cIniFileName
  .if dIniFilePresent != FALSE
    ;Check Version
    invoke GetVersionFromString, addr cItemBuffer
    .if eax != [xsi].dReqMainVersion || ecx < [xsi].dMinSubVersion
      invoke MsgBox, 0, addr cWarnOldProj, addr cWarning, MB_OK or MB_ICONWARNING
    .endif
  .endif

  ;Load "project" root item
  invoke GetPrivateProfileString, addr cIniSectIdentification, $OfsCStr("Name"), $OfsCStr("Solution"), \
                      addr cItemBuffer, lengthof cItemBuffer, addr cIniFileName

  OCall xsi.ProjItemInsert, 0, TVI_ROOT, addr cItemBuffer, NULL, PIF_ROOT, 3, 4, 0
  mov hProjRootNode, xax

  ;Load "Folder" child items
  mov xdi, xax
  xor ebx, ebx
  .while TRUE
    inc ebx
    lea xdi, cItemName
    WriteF xdi, "¦UD", ebx
    invoke GetPrivateProfileString, $OfsCStr("Folders"), addr cItemName, NULL, \
                        addr cItemBuffer, lengthof cItemBuffer, addr cIniFileName
    .break .if eax == 0
    OCall xsi.ProjItemInsert, hProjRootNode, TVI_LAST, addr cItemBuffer, NULL, PIF_FOLDER, 3, 4, 0
  .endw

  ;Load "File" items
  xor ebx, ebx
  .while TRUE
    inc ebx
    lea xdi, cItemName
    WriteF xdi, "¦UD", ebx
    invoke GetPrivateProfileString, $OfsCStr("Files"), addr cItemName, NULL, \
                                    addr cItemBuffer, lengthof cItemBuffer, addr cIniFileName
    .break .if eax == 0
    invoke GetFileFromString, addr cItemBuffer          ;xax -> PROJECTITEM, edx = folder index
    .if xax != NULL
      mov xdi, xax
      OCall xsi.GetFolderByIndex, edx                   ;xax = HTREEITEM
      mov TVI.hParent, xax
      mov TVI.hInsertAfter, TVI_SORT
      mov TVI.item.mask_, TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
      m2m TVI.item.pszText, [xdi].PROJECTITEM.pDisplayName, xdx
      mov TVI.item.iImage, 5
      .if [xdi].PROJECTITEM.dFlags == PIF_CMD
        mov TVI.item.iImage, 6
      .endif
      m2m TVI.item.iSelectedImage, TVI.item.iImage, eax
      mov TVI.item.lParam, xdi
      invoke SendMessage, [xsi].TView.hWnd, TVM_INSERTITEM, 0, addr TVI
    .endif
  .endw

  ;Expand all items
  invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, hProjRootNode
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CHILD, hProjRootNode
  mov xbx, xax
  .While xbx != 0
    invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, xbx
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, xbx, 0
    mov xbx, xax
  .endw

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.ConfigSave
; Purpose:    Save the project configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.ConfigSave, uses xsi
  SetObject xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.Done
; Purpose:    Finalize the ProjectWnd object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method ProjectWnd.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TBar::Toolbar.Done
  OCall [xsi].TView::TreeView.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.IsFilePresent
; Purpose:    Check if the file is already present.
; Arguments:  Arg1: -> Full file name.
; Return:     eax: TRUE if it is present, otherwise FALSE.

SearchInBranch proc uses xbx xdi xsi hTreeView:HWND, hParent:HTREEITEM, pFullFileName:PSTRING
  local Item:TVITEM

  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xax, Item.lParam
      .if [xax].PROJECTITEM.dFlags == PIF_FOLDER
        invoke SearchInBranch, hTreeView, Item.hItem, pFullFileName
        .break .if eax != FALSE
      .else
        .if [xax].PROJECTITEM.dFlags == PIF_FILE
          invoke StrComp, [xax].PROJECTITEM.pFullFileName, pFullFileName
          .if eax == 0
            inc eax
            .break
          .endif
        .endif
        invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, Item.hItem
      .endif
    .endif
  .endw 
  ret
SearchInBranch endp


Method ProjectWnd.IsFilePresent, uses xsi, pFullFileName:PSTRING
  local Pnt:POINT, tvht:TVHITTESTINFO

;  DbgText "ProjectWnd.IsFilePresent"
  SetObject xsi
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
  invoke SearchInBranch, [xsi].TView.hWnd, xax, pFullFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.GetFolderByIndex
; Purpose:    Get the HTREEITEM by its index.
; Arguments:  Arg1: Index (0 = root folder, 1 = first folder, 2 = second folder, ...).
; Return:     xax = HTREEITEM.

Method ProjectWnd.GetFolderByIndex, uses xbx xsi, dIndex:DWORD
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
; Method:     ProjectWnd.Init
; Purpose:    Initialize the ProjectWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method ProjectWnd.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, offset szProjectWnd, $OfsCStr("Project Manager"), \
                         WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, 0, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL

  OCall [xsi].DragDrop::Component.Init, xsi, NULL       ;Init component
  mov xbx, $New(IDropTarget)             ;Create IDropTarget interface
  OCall [xsi].DragDrop.Interfaces::Collection.Insert, xax
  OCall xbx::IDropTarget.Init, addr [xsi].DragDrop, [xsi].TView.hWnd

  invoke RegisterDragDrop, [xsi].TView.hWnd, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectWnd.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
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

  invoke DefWindowProc, [xsi].hWnd, WM_CREATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ProjectWnd.OnLButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDropDst:HTREEITEM, DragSrcItem:TVITEM, DropDstItem:TVITEM

;  DbgText "ProjectWnd.OnLButtonUp"
  SetObject xsi
  .if [xsi].dDragging != FALSE
    ;Get destination item.
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_DROPHILITE, 0
    .if xax != 0
      mov hDropDst, xax
      mov DropDstItem.hItem, xax
      mov DropDstItem.mask_, TVIF_HANDLE or TVIF_PARAM
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr DropDstItem
      mov xbx, DropDstItem.lParam
      .if [xbx].PROJECTITEM.dFlags == PIF_FILE
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_PARENT, hDropDst
        mov hDropDst, xax
      .endif

      mov DragSrcItem.mask_, TVIF_HANDLE or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
      m2m DragSrcItem.hItem, [xsi].hDragSrcItem, xax
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr DragSrcItem
      mov xbx, DragSrcItem.lParam
      OCall xsi.ProjItemInsert, hDropDst, TVI_SORT, \
                                [xbx].PROJECTITEM.pDisplayName, [xbx].PROJECTITEM.pFullFileName, \
                                [xbx].PROJECTITEM.dFlags, \
                                DragSrcItem.iImage, DragSrcItem.iSelectedImage, \
                                [xbx].PROJECTITEM.hEditor  

      invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, [xsi].hDragSrcItem

      invoke ImageList_EndDrag
      invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_DROPHILITE, 0
      invoke ReleaseCapture
      invoke ShowCursor, TRUE
      mov [xsi].dDragging, FALSE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method ProjectWnd.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT, tvht:TVHITTESTINFO

;  DbgText "ProjectWnd.OnMouseMove"
  SetObject xsi
  .if [xsi].dDragging != FALSE
    PntS2Pnt Pnt, lParam
    invoke ClientToScreen, [xsi].hWnd, addr Pnt
    invoke ScreenToClient, [xsi].TView.hWnd, addr Pnt
    invoke ImageList_DragMove, Pnt.x, Pnt.y
    ;Turn off the dragged image so the background can be refreshed.
    invoke ImageList_DragShowNolock, FALSE
    ;Find out if the pointer is on the item. If it is, highlight the item as a drop target.
    s2s POINT ptr tvht.pt, POINT ptr Pnt.x, xax, xdx
    invoke SendMessage, [xsi].TView.hWnd, TVM_HITTEST, 0, addr tvht
    .if xax != 0
      invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_DROPHILITE, xax
      invoke ImageList_DragShowNolock, TRUE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectWnd.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     ProjectWnd.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.
; Link:       https://learn.microsoft.com/en-us/windows/win32/controls/drag-a-tree-view-item

Method ProjectWnd.OnNotify, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hImgList:HIMAGELIST, ItemRect:RECT, Item:TVITEM, pEditor:$ObjPtr(Editor)

;  DbgText "ProjectWnd.OnNotify"
  SetObject xsi
  mov xbx, lParam
  .if [xbx].NMHDR.code == TVN_BEGINDRAG
    m2m Item.hItem, [xbx].NMTREEVIEW.itemNew.hItem, xax
    mov Item.mask_, TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xcx, Item.lParam
      DbgStr [xcx].PROJECTITEM.pDisplayName
      .if [xcx].PROJECTITEM.dFlags == PIF_FILE
        ;Tell the tree-view control to create an image to use for dragging.
        mrm [xsi].hDragSrcItem, [xbx].NMTREEVIEW.itemNew.hItem, xax
        invoke SendMessage, [xsi].TView.hWnd, TVM_CREATEDRAGIMAGE, 0, xax
        mov hImgList, xax
        ;Start the drag operation.
        invoke ImageList_BeginDrag, hImgList, 0, 0, 0
        invoke ImageList_DragEnter, [xsi].TView.hWnd, [xbx].NMTREEVIEW.ptDrag.x, [xbx].NMTREEVIEW.ptDrag.y
    
        ;Hide the mouse pointer, and direct mouse input to the parent window.
        invoke ShowCursor, FALSE
        invoke GetParent, [xsi].TView.hWnd
        invoke SetCapture, xax
        mov [xsi].dDragging, TRUE
      .endif
    .endif

  .elseif [xbx].NMHDR.code == TVN_DELETEITEM
    mov xbx, [xbx].NMTREEVIEW.itemOld.lParam
    invoke StrDispose, [xbx].PROJECTITEM.pDisplayName
    invoke StrDispose, [xbx].PROJECTITEM.pFullFileName
    MemFree xbx

  .elseif [xbx].NMHDR.code == NM_DBLCLK
    mov xax, [xsi].TView.hWnd
    .if [xbx].NMHDR.hwndFrom == xax
      invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0
      .if xax != 0
        mov Item.hItem, xax
        mov Item.mask_, TVIF_PARAM
        invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
        .if eax != FALSE
          mov xbx, Item.lParam
          .if [xbx].PROJECTITEM.dFlags == PIF_FILE
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
            New Editor
            .if xax != NULL
              mov pEditor, xax
              OCall [xdi].$Obj(Application).FileTypes::FileTypeCollection.GetContentType, [xbx].PROJECTITEM.pFullFileName
              .if eax == ECT_ASM
                lea xax, [xdi].$Obj(Application).AsmEditorResources
              .elseif eax == ECT_RES
                lea xax, [xdi].$Obj(Application).ResEditorResources
              .else
                lea xax, [xdi].$Obj(Application).TxtEditorResources
              .endif
              OCall pEditor::Editor.Init, [xdi].$Obj(Application).pClientWnd, xax, [xbx].PROJECTITEM.pFullFileName
              .if eax == FALSE
                Destroy pEditor
              .else
                mov xax, pEditor
                mov xcx, [xax].$Obj(Editor).hWnd
                mov [xbx].PROJECTITEM.hEditor, xcx
                invoke ShowWindow, xcx, SW_SHOW
              .endif
            .endif

          .elseif [xbx].PROJECTITEM.dFlags == PIF_CMD

          .endif
        .endif
      .endif
    .endif

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.ProjItemInsert
; Purpose:    Insert a new PROJECTITEM in the TreeView.
; Arguments:  Arg1: Treeview parent node HANDLE.
;             Arg2: TreeView HANDLE of the node, after the new item is inserted.
;             Arg3: -> Display text.
;             Arg4: -> Full file name.
;             Arg5: Flags (PIF_XXX)
;             Arg6: Regular icon index.
;             Arg7: Selected icon index.
;             Arg8: Editor HWND.
; Return:     xax = HTREEITEM.

Method ProjectWnd.ProjItemInsert, uses xbx xsi, hNodeParent:HANDLE, hNodeAfter:HANDLE, \
                                  pDispText:PSTRING, pFullFileName:PSTRING, dFlags:DWORD, \
                                  dImgIndex:DWORD, dImgSelIndex:DWORD, hEditor:HWND
  local TVI:TV_INSERTSTRUCT

;  DbgText "ProjectWnd.ProjItemInsert"
  SetObject xsi
  MemAlloc sizeof(PROJECTITEM)
  mov TVI.item.lParam, xax
  .if xax != NULL
    mov xbx, xax
    invoke StrNew, pDispText
    mov [xbx].PROJECTITEM.pDisplayName, xax
    invoke StrNew, pFullFileName
    mov [xbx].PROJECTITEM.pFullFileName, xax
    m2m [xbx].PROJECTITEM.dFlags, dFlags, ecx
    m2m [xbx].PROJECTITEM.hEditor, hEditor, xdx

    m2m TVI.hParent, hNodeParent, xax
    m2m TVI.hInsertAfter, hNodeAfter, xdx
    mov TVI.item.mask_, TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
    m2m TVI.item.pszText, [xbx].PROJECTITEM.pDisplayName, xax
    m2m TVI.item.iImage, dImgIndex, edx
    m2m TVI.item.iSelectedImage, dImgSelIndex, eax
    invoke SendMessage, [xsi].TView.hWnd, TVM_INSERTITEM, 0, addr TVI
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ProjectWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(ProjectWnd.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_BTNFACE + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szProjectWnd, xax
  m2z WC.hIcon
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd
