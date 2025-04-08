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
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Done
; Purpose:    Finalize the ProjectWnd object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method ProjectWnd.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TBar::Toolbar.Done
  OCall [xsi].TView::TreeView.Done
  OCall [xsi].TVHandles::%XWordVector.Done
  OCall [xsi].Files::DataCollection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Init
; Purpose:    Initialize the ProjectWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method ProjectWnd.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, offset szProjectWnd, $OfsCStr("Project Manager"), \
                         WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, 0, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Files.DestroyItem
; Purpose:    Auxiliar function to free FILE associated resources and the item itself.
; Arguments:  Arg1: .
; Return:     Nothing.

Method Files.DestroyItem, uses xbx, pItem:POINTER
  mov xbx, pItem
  .if xbx != NULL
    invoke StrDispose, [xbx].FILE.pDisplayName
    invoke StrDispose, [xbx].FILE.pFullFileName
    MemFree xbx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectWnd.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hRoot:HANDLE, hFolder1:HANDLE

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
  
  OCall [xsi].TVHandles::%XWordVector.Init, xsi, 10, 10, $Obj(%XWordVector)_MaxCapacity
  
  OCall [xsi].Files::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  Override [xsi].Files::DataCollection.DestroyItem, Files.DestroyItem

  invoke DefWindowProc, [xsi].hWnd, WM_CREATE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Open
; Purpose:    Open the project configuration file.
; Arguments:  Arg1: -> Ini-File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.Open, uses xbx xdi xsi, pIniFileName:PSTRING
  local pDescription:PSTRING, dIconIndex:DWORD, dIniFilePresent:DWORD, hProjNode:HANDLE
  local cFileName[1024]:CHR, cSectionName[50]:CHR, cItemName[20]:CHR, cDefaultName[20]:CHR, cItemBuffer[4096]:CHR

  SetObject xsi
  invoke GetFullPathName, pIniFileName, lengthof cFileName - 1, addr cFileName, NULL
  invoke FileExist, addr cFileName
  mov dIniFilePresent, eax
  .if eax == FALSE
    invoke MsgBox, 0, addr cWarnNoProj, addr cWarning, MB_OK or MB_ICONWARNING
  .endif

  ;Load version and analyse
  invoke GetPrivateProfileString, addr cIniSectIdentification, addr cVersion, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  .if dIniFilePresent != FALSE
    ;Check Version
    invoke GetVersionFromString, addr cItemBuffer
    .if eax != [xsi].dReqMainVersion || ecx < [xsi].dMinSubVersion
      invoke MsgBox, 0, addr cWarnOldProj, addr cWarning, MB_OK or MB_ICONWARNING
    .endif
  .endif

  ;Load "project" root item
  invoke GetPrivateProfileString, addr cIniSectIdentification, $OfsCStr("Name"), $OfsCStr("Solution"), \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName

  OCall [xsi].TView::TreeView.NodeInsert, TVI_ROOT, TVI_FIRST, addr cItemBuffer, 3, 4
  mov hProjNode, xax
  DbgHex xax
  OCall [xsi].TVHandles::%XWordVector.Insert, xax

  ;Load "folder" children items
  mov xdi, xax
  xor ebx, ebx
  .while TRUE
    inc ebx
    lea xdi, cItemName
    WriteF xdi, "¦UD", ebx
    lea xdi, cDefaultName
    WriteF xdi, "Folder ¦UD", ebx
    invoke GetPrivateProfileString, $OfsCStr("Folders"), addr cItemName, NULL, \
                        addr cItemBuffer, lengthof cItemBuffer, addr cFileName
    .break .if eax == 0
    OCall [xsi].TView::TreeView.NodeInsert, hProjNode, xdi, addr cItemBuffer, 3, 4
    mov xdi, xax
    OCall [xsi].TVHandles::%XWordVector.Insert, xax
  .endw
  
  ;Load "file" items
  xor ebx, ebx
  .while TRUE
    inc ebx
    lea xdi, cItemName
    WriteF xdi, "¦UD", ebx
    invoke GetPrivateProfileString, $OfsCStr("Files"), addr cItemName, NULL, \
                        addr cItemBuffer, lengthof cItemBuffer, addr cFileName
    .break .if eax == 0
    invoke GetFileFromString, addr cItemBuffer
    mov xdi, xax
    OCall [xsi].TVHandles::%XWordVector.ItemAt, edx
    mov dIconIndex, 5
    .ifBitSet [xdi].FILE.dFlags, FF_CMD
      mov dIconIndex, 6
    .endif
    OCall [xsi].TView::TreeView.NodeInsert, HANDLE ptr [xax], TVI_FIRST, [xdi].FILE.pDisplayName, dIconIndex, dIconIndex
  .endw
  
  ;Expand all items
  .VecForEach [xsi].TVHandles::%XWordVector, ebx
    invoke SendMessage, [xsi].TView.hWnd, TVM_EXPAND, TVE_EXPAND, HANDLE ptr [xax]
  .VecNext 
  
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Save
; Purpose:    Save the project configuration file.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method ProjectWnd.Save, uses xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
