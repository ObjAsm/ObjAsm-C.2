; ==================================================================================================
; Title:      TreeView.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support TreeView controls based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_TREEVIEW struc
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
DEF_TREEVIEW ends
PDEF_TREEVIEW typedef ptr DEF_TREEVIEW

; --------------------------------------------------------------------------------------------------
; Object:     TreeView
; Purpose:    Implement a thin wrapper around the SysTreeView32 GDI control.

Object TreeView, TreeViewID, WinControl                           ;Class "SysTreeView32"
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, $ObjPtr(MaskedImageList), PDEF_TREEVIEW
  VirtualMethod     NodeDelete,         HANDLE
  VirtualMethod     NodeInsert,         HANDLE, HANDLE, PSTRING, DWORD, DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     TreeView.Done
; Purpose:    Finalize the TreeView object.
; Arguments:  None.
; Return:     Nothing.

Method TreeView.Done, uses xsi
  SetObject xsi
  Unsubclass TreeView                                   ;Uses xsi
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TreeView.Init
; Purpose:    Initialize the TreeView control.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> MaskedImageList object.
;             Arg4: -> DEF_TREEVIEW structure.
; Return:     Nothing.

Method TreeView.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, \
                                    pImgList:$ObjPtr(MaskedImageList), pDefStruc:PDEF_TREEVIEW
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_TREEVIEW
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  invoke CreateWindowEx, [xbx].DEF_TREEVIEW.dExStyle, $OfsCStr("SysTreeView32"), \
                         [xbx].pTitle, eax, \
                         [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, NULL
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  mov xbx, pImgList
  invoke SendMessage, [xsi].hWnd, TVM_SETIMAGELIST, 0, [xbx].$Obj(MaskedImageList).hImageList
  Subclass TreeView                                     ;Uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TreeView.NodeDelete
; Purpose:    Delete a node from the TreeView object.
; Arguments:  Arg1: Parent node handle.
;             Arg2: Handle of the node to delete.
; Return:     xax = Node handle.

Method TreeView.NodeDelete,, hNode:HANDLE
    SetObject xcx
    invoke SendMessage, [xcx].hWnd, TVM_DELETEITEM, 0, hNode
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TreeView.NodeInsert
; Purpose:    Insert a new node in the TreeView object.
; Arguments:  Arg1: Parent node handle.
;             Arg2: Handle of the node, after the new node is inserted.
;             Arg3: Node text pointer.
;             Arg4: Normal icon index.
;             Arg5: Selected icon index.
; Return:     xax = Node handle.

Method TreeView.NodeInsert,, hNodeParent:HANDLE, hNodeAfter:HANDLE, pText:PSTRING, \
                             dImgNorIndex:DWORD, dImgSelIndex:DWORD
  local TVI:TV_INSERTSTRUCT

  SetObject xcx
  m2m TVI.hParent, hNodeParent, xax
  m2m TVI.hInsertAfter, hNodeAfter, xdx
  mov TVI.item.mask_, TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE
  m2m TVI.item.pszText, pText, xax
  m2m TVI.item.iImage, dImgNorIndex, edx
  m2m TVI.item.iSelectedImage, dImgSelIndex, eax
  invoke SendMessage, [xcx].hWnd, TVM_INSERTITEM, 0, addr TVI
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TreeView.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window HANDLE is passed in pSelf (hidden parameter).

Method TreeView.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  GetSubclassingInst TreeView, pSelf
  OCall xax::TreeView.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
