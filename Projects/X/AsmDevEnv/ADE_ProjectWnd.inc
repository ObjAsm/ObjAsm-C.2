; ==================================================================================================
; Title:      ADE_ProjectWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of project window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



PROJTVSTYLE   equ   TVS_HASBUTTONS or TVS_HASLINES or TVS_LINESATROOT or TVS_EDITLABELS or TVS_SHOWSELALWAYS or TVS_TRACKSELECT

PROJTBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT

CStr szProjectWnd, "ProjectWnd"

.const
ProjTreeView DEF_TREEVIEW {100, PROJTVSTYLE, 0, NULL, {<0,0,0,0>}}

;ProjToolbar DEF_TOOLBAR {101, PROJTBSTYLE, 0, NULL, {<0,0,0,0>}, 3}
;  TBBUTTON {IDB_PROJ_OPEN,  IDM_PROJ_OPEN,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
;  TBBUTTON {IDB_PROJ_SAVE,  IDM_PROJ_SAVE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
;  TBBUTTON {IDB_PROJ_CLOSE, IDM_PROJ_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON}

PWF_EMPTY     equ   BIT00
PWF_DIRTY     equ   BIT01


.code

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.ConfigLoadFrom
; Purpose:    Open the project configuration.
; Arguments:  Arg1: -> File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.ConfigLoadFrom, uses xbx xdi xsi, pConfigFileName:PSTRING
  local dConfigFilePresent:DWORD, hRootItem:HTREEITEM, dGroupExpand:DWORD
  local cConfigFileName[1024]:CHR, cItemName[20]:CHR, cItemBuffer[4096]:CHR, TVI:TV_INSERTSTRUCT

  SetObject xsi
  ;Reset complete TreeView
  invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, TVI_ROOT

  invoke GetFullPathName, pConfigFileName, lengthof cConfigFileName - 1, addr cConfigFileName, NULL
  invoke StrReplace, addr [xsi].pProjFileName, addr cConfigFileName
  invoke FileExist, addr cConfigFileName
  mov dConfigFilePresent, eax
  .if eax == FALSE
    invoke MsgBox, 0, addr cWarnNoProj, addr cWarning, MB_OK or MB_ICONWARNING
  .endif

  ;Load "version" and analyse
  invoke GetPrivateProfileString, addr cIdentification, addr cVersion, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
  .if dConfigFilePresent != FALSE
    ;Check Version
    invoke GetVersionFromString, addr cItemBuffer
    .if eax != [xsi].dReqMainVersion || ecx < [xsi].dMinSubVersion
      invoke MsgBox, 0, addr cWarnOldProj, addr cWarning, MB_OK or MB_ICONWARNING
    .endif
  .endif

  ;Load "Project" section
  invoke GetPrivateProfileString, addr cProject, addr cName, $OfsCStr("Solution"), \
                      addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
  invoke StrReplace, addr [xsi].pProjName, addr cItemBuffer
  invoke GetPrivateProfileString, addr cProject, addr cPath, $OfsCStr(".\"), \
                      addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
  invoke StrReplace, addr [xsi].pProjDirPath, addr cItemBuffer
  invoke GetPrivateProfileString, addr cProject, addr cDescription, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
  invoke StrReplace, addr [xsi].pProjDescription, addr cItemBuffer

  ;Load "project" root item
  OCall xsi.ProjItemInsert, 0, TVI_ROOT, [xsi].pProjName, NULL, PIF_PROJ, 3, 4, 0
  mov hRootItem, xax

  ;Load "Group" child items
  mov xdi, xax
  xor ebx, ebx
  .while TRUE
    inc ebx
    invoke dword2dec, addr cItemName, ebx
    invoke GetPrivateProfileString, addr cGroups, addr cItemName, NULL, \
                        addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
    .break .if eax == 0
    invoke StrLScan, addr cItemBuffer, ','
    .if xax != 0
      mov CHR ptr [xax], 0
    .endif
    OCall xsi.ProjItemInsert, hRootItem, TVI_LAST, addr cItemBuffer, NULL, PIF_GROUP, 3, 4, 0
  .endw

  ;Load "File" items
  xor ebx, ebx
  .while TRUE
    inc ebx
    lea xdi, cItemName
    WriteF xdi, "各D", ebx
    invoke GetPrivateProfileString, addr cFiles, addr cItemName, NULL, \
                                    addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
    .break .if eax == 0
    invoke GetFileFromString, addr cItemBuffer          ;xax -> PROJECTITEM, edx = folder index
    .if xax != NULL
      mov xdi, xax
      OCall xsi.GetGroupByIndex, edx                   ;xax = HTREEITEM
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

  ;Always expand the Root item
  invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, hRootItem

  ;Expand groups according to the configuration
  xor ebx, ebx
  .while TRUE
    inc ebx
    invoke dword2dec, addr cItemName, ebx
    invoke GetPrivateProfileString, addr cGroups, addr cItemName, NULL, \
                        addr cItemBuffer, lengthof cItemBuffer, addr cConfigFileName
    .break .if eax == 0
    mov dGroupExpand, FALSE
    invoke StrLScan, addr cItemBuffer, ','
    .if xax != 0
      mov CHR ptr [xax], 0
      invoke dec2dword, addr [xax + sizeof(CHR)]
      .if ecx == 0 && eax != 0
        mov dGroupExpand, TRUE
      .endif
    .endif
    OCall xsi.GetGroupByIndex, ebx                     ;xax = HTREEITEM
    .if dGroupExpand != FALSE
      invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, xax
    .endif
  .endw

  BitClr [xsi].dFlags, PWF_EMPTY or PWF_DIRTY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.ConfigSave
; Purpose:    Save the project configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.ConfigSave
;  DbgText "ProjectWnd.ConfigSave"
  SetObject xax
  OCall xax.ConfigSaveTo, [xax].pProjFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.ConfigSaveTo
; Purpose:    Save the project configuration.
; Arguments:  Arg1: -> File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

SaveGroups proc uses xbx xdi xsi hTreeView:HWND, hParent:HTREEITEM, pConfigFileName:PSTRING
  local Item:TVITEM, cItemName[1024]:CHR, cBuffer[1024]:CHR, dExpanded:DWORD

  xor edi, edi                                          ;edi = counter
  mov Item.mask_, TVIF_HANDLE or TVIF_STATE or TVIF_PARAM
  mov Item.stateMask, TVIS_EXPANDED
  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xbx, Item.lParam
      .if [xbx].PROJECTITEM.dFlags == PIF_GROUP
        mov dExpanded, 0
        .ifBitSet Item.state, TVIS_EXPANDED
          mov dExpanded, 1
        .endif
        inc edi
        invoke dword2dec, addr cItemName, edi
        lea xsi, cBuffer
        WriteF xsi, "吁T,各D", [xbx].PROJECTITEM.pDisplayName, dExpanded
;        DbgStr cItemName
;        DbgStr cBuffer
        invoke WritePrivateProfileString, addr cGroups, addr cItemName, addr cBuffer, pConfigFileName
        invoke WritePrivateProfileString, NULL, NULL, NULL, NULL    ;Flush
      .endif
      invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, Item.hItem
    .endif
  .endw
  ret
SaveGroups endp

SaveFilesInBranch proc uses xbx xdi xsi hTreeView:HWND, hParent:HTREEITEM, pGroupCounter:POINTER, pFileCounter:POINTER, pConfigFileName:PSTRING
  local Item:TVITEM, cItemName[1024]:CHR, cBuffer[1024]:CHR

  mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xbx, Item.lParam
      .if [xbx].PROJECTITEM.dFlags == PIF_GROUP
        mov xax, pGroupCounter
        inc DWORD ptr [xax]
        invoke SaveFilesInBranch, hTreeView, Item.hItem, pGroupCounter, pFileCounter, pConfigFileName
      .else
        mov xax, pFileCounter
        inc DWORD ptr [xax]
        invoke dword2dec, addr cItemName, DWORD ptr [xax]
        lea xdi, cBuffer
        mov xsi, pGroupCounter
        WriteF xdi, "各D,各D,吁T,吁T", DWORD ptr [xsi], [xbx].PROJECTITEM.dFlags, [xbx].PROJECTITEM.pDisplayName, [xbx].PROJECTITEM.pFullFileName
;        DbgStr cItemName
;        DbgStr cBuffer
        invoke WritePrivateProfileString, addr cFiles, addr cItemName, addr cBuffer, pConfigFileName
        invoke WritePrivateProfileString, NULL, NULL, NULL, NULL    ;Flush
      .endif
      invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, Item.hItem
    .endif
  .endw
  ret
SaveFilesInBranch endp

Method ProjectWnd.ConfigSaveTo, uses xsi, pConfigFileName:PSTRING
  local cConfigFileName[1024]:CHR, dGroupCounter:DWORD, dFileCounter:DWORD, hRoot:HTREEITEM

;  DbgText "ProjectWnd.ConfigSaveTo"
  SetObject xsi
  .ifBitSet [xsi].dFlags, PWF_DIRTY
    invoke GetFullPathName, pConfigFileName, lengthof cConfigFileName - 1, addr cConfigFileName, NULL

    ;Clear all sections in reverse order
    invoke WritePrivateProfileString, addr cFiles, NULL, NULL, addr cConfigFileName 
    invoke WritePrivateProfileString, addr cGroups, NULL, NULL, addr cConfigFileName
    invoke WritePrivateProfileString, addr cProject, NULL, NULL, addr cConfigFileName
    invoke WritePrivateProfileString, addr cIdentification, NULL, NULL, addr cConfigFileName

    ;Save "Identification" section
    invoke WritePrivateProfileString, addr cIdentification, addr cDescription, \
                        $OfsCStr("Assembler Development Environment - Project file"), \
                        addr cConfigFileName
    invoke WritePrivateProfileString, addr cIdentification, addr cVersion, \
                        $OfsCStr("1.0"), addr cConfigFileName

    ;Save "Project" section
    invoke WritePrivateProfileString, addr cProject, NULL, NULL, addr cConfigFileName  ;Clear all 
    invoke WritePrivateProfileString, addr cProject, addr cName, \
                        [xsi].pProjName, addr cConfigFileName
    invoke WritePrivateProfileString, addr cProject, addr cPath, \
                        [xsi].pProjDirPath, addr cConfigFileName
    invoke WritePrivateProfileString, addr cProject, addr cDescription, \
                        [xsi].pProjDescription, addr cConfigFileName

    ;Save "Groups" section
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
    mov hRoot, xax
    mov dGroupCounter, 0
    mov dFileCounter, 0
    invoke SaveGroups, [xsi].TView.hWnd, hRoot, addr cConfigFileName

    ;Save "Files" section
    invoke SaveFilesInBranch, [xsi].TView.hWnd, hRoot, addr dGroupCounter, addr dFileCounter, addr cConfigFileName
    
    invoke WritePrivateProfileString, NULL, NULL, NULL, NULL    ;Flush
  .endif

  BitClr [xsi].dFlags, PWF_DIRTY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.CreateNewProject
; Purpose:    Create a default project configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.CreateNewProject, uses xbx xdi xsi
  local hRootItem:HTREEITEM, cBuffer[1024]:CHR

;  DbgText "ProjectWnd.CreateNewProject"
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
  OCall xsi.ProjItemInsert, 0, TVI_ROOT, [xsi].pProjName, NULL, PIF_PROJ, 3, 4, 0
  mov hRootItem, xax

  ;Create the file name
  mov xax, [xsi].pProjFileName
  .if xax != NULL
    invoke StrLength, xax
  .endif
  .if xax == 0                                          ;No name defined
    lea xdi, cBuffer
    WriteF xdi, "吁T.adep", [xsi].pProjName
    mov [xsi].pProjFileName, $invoke(StrNew, addr cBuffer)
  .endif

  ;Create child items from Group "1".."n"
  mov xdi, xax
  xor ebx, ebx
  .while TRUE
    inc ebx
    .break .if ebx >= [xsi].DefaultGroups.dCount
    OCall [xsi].DefaultGroups::%StrCollection.ItemAt, ebx
    OCall xsi.ProjItemInsert, hRootItem, TVI_LAST, xax, NULL, PIF_GROUP, 3, 4, 0
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

  BitClr [xsi].dFlags, PWF_EMPTY or PWF_DIRTY
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
  OCall [xsi].DefaultGroups::%StrCollection.Done

  invoke StrDispose, [xsi].pProjName
  invoke StrDispose, [xsi].pProjFileName
  invoke StrDispose, [xsi].pProjDirPath
  invoke StrDispose, [xsi].pProjDescription

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.IsFileAlreadyPresent
; Purpose:    Check if the file is already present.
; Arguments:  Arg1: -> Full file name.
; Return:     eax: HTREEITEM if it is present, otherwise 0.

SearchInBranch proc hTreeView:HWND, hParent:HTREEITEM, pFullFileName:PSTRING
  local Item:TVITEM

  invoke SendMessage, hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hParent
  .while xax != 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, hTreeView, TVM_GETITEM, 0, addr Item
    .if eax != FALSE
      mov xax, Item.lParam
      .if [xax].PROJECTITEM.dFlags == PIF_GROUP
        invoke SearchInBranch, hTreeView, Item.hItem, pFullFileName
        .break .if xax != 0
      .else
        .if [xax].PROJECTITEM.dFlags == PIF_FILE
          invoke StrComp, [xax].PROJECTITEM.pFullFileName, pFullFileName
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

Method ProjectWnd.IsFileAlreadyPresent, uses xsi, pFullFileName:PSTRING
;  DbgText "ProjectWnd.IsFileAlreadyPresent"
  SetObject xsi
  invoke SendMessage, [xsi].TView.hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0
  invoke SearchInBranch, [xsi].TView.hWnd, xax, pFullFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.GetGroupByIndex
; Purpose:    Get the group HTREEITEM by its index.
; Arguments:  Arg1: Index (0 = root, 1 = first group, 2 = second group, ...).
; Return:     xax = HTREEITEM.

Method ProjectWnd.GetGroupByIndex, uses xbx xsi, dIndex:DWORD
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
  BitSet [xsi].dFlags, PWF_EMPTY
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL

  OCall [xsi].DefaultGroups::%StrCollection.Init, xsi, 10,10, COL_MAX_CAPACITY
  OCall [xsi].DragDrop::Component.Init, xsi, NULL       ;Init component
  mov xbx, $New(IDropTarget)             ;Create IDropTarget interface
  OCall [xsi].DragDrop.Interfaces::Collection.Insert, xax
  OCall xbx::IDropTarget.Init, addr [xsi].DragDrop, [xsi].TView.hWnd

  invoke RegisterDragDrop, [xsi].TView.hWnd, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.OnCreate
; Purpose:    Event procedure for WM_CONTEXTMENU message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectWnd.OnContextMenu, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local SceenPoint:POINT, tvht:TVHITTESTINFO, Item:TVITEM
  local hContextMenu:HMENU, hContextSubMenu:HMENU 

  ANNOTATION use:wParam
  
  SetObject xsi
  PntS2Pnt SceenPoint, lParam
  s2s tvht.pt, SceenPoint, xax, xdx
  invoke ScreenToClient, [xsi].TView.hWnd, addr tvht.pt
  ;Find out if the cursor is on an item
  invoke SendMessage, [xsi].TView.hWnd, TVM_HITTEST, 0, addr tvht
  .if xax != 0
    mov Item.hItem, xax
    mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
    invoke SendMessage, [xsi].TView.hWnd, TVM_SELECTITEM, TVGN_CARET, Item.hItem
    invoke SendMessage, [xsi].TView.hWnd, TVM_GETITEM, 0, addr Item
    mov xbx, Item.lParam
    mov hContextMenu, $invoke(LoadMenu, hInstance, $OfsCStr("CONTEXTMENU_PROJECT"))
    .if [xbx].PROJECTITEM.dFlags == PIF_GROUP
      mov edx, 1
    .elseif [xbx].PROJECTITEM.dFlags == PIF_FILE
      mov edx, 2
    .elseif [xbx].PROJECTITEM.dFlags == PIF_CMD
      mov edx, 3
    .else
      xor edx, edx
    .endif
    mov hContextSubMenu, $invoke(GetSubMenu, xax, edx)
    invoke TrackPopupMenuEx, hContextSubMenu, TPM_LEFTALIGN or TPM_TOPALIGN or TPM_NONOTIFY or TPM_RETURNCMD or TPM_RIGHTBUTTON, \
                             SceenPoint.x, SceenPoint.y, [xsi].hWnd, NULL
    invoke PostMessage, [xsi].hWnd, WM_NULL, 0, 0       ;Fix for shortcut menu not popping up right
    invoke DestroyMenu, hContextMenu
  .endif
  xor eax, eax
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

Method ProjectWnd.OnLButtonUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hDropDst:HTREEITEM, DragSrcItem:TVITEM, DropDstItem:TVITEM

  ANNOTATION use:wParam

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
      BitSet [xsi].dFlags, PWF_DIRTY
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

  ANNOTATION use:wParam

;  DbgText "ProjectWnd.OnMouseMove"
  SetObject xsi
  .if [xsi].dDragging != FALSE
    PntS2Pnt Pnt, lParam
    invoke ClientToScreen, [xsi].hWnd, addr Pnt
    invoke ScreenToClient, [xsi].TView.hWnd, addr Pnt
    invoke ImageList_DragMove, Pnt.x, Pnt.y
    ;Turn off the dragged image so the background can be refreshed.
    invoke ImageList_DragShowNolock, FALSE
    ;Find out if the cursor is on the item. If it is, highlight the item as a drop target.
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

Method ProjectWnd.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hImgList:HIMAGELIST, Item:TVITEM, pEditor:$ObjPtr(Editor)

;  DbgText "ProjectWnd.OnNotify"
  SetObject xsi
  mov xbx, lParam
;  DbgDec [xbx].NMHDR.code
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
            invoke ShellExecute, [xsi].hWnd, NULL, [xbx].PROJECTITEM.pCommand, NULL, NULL, SW_SHOW

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
          invoke SendMessage, [xsi].TView.hWnd, TVM_DELETEITEM, 0, xdi
          BitSet [xsi].dFlags, PWF_DIRTY
        .endif 
      .endif
    .endif

  .elseif [xbx].NMHDR.code == TVN_ITEMEXPANDED
    BitSet [xsi].dFlags, PWF_DIRTY

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

; --------------------------------------------------------------------------------------------------
; Method:     ProjectWnd.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method ProjectWnd.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam
  
;  DbgMessage uMsg, "ProjectWnd.WndProc"
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
