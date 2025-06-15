; ==================================================================================================
; Title:      ADE_ProjectManager_IDropTarget.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of project window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ==================================================================================================
; ProjectManager_IDropTarget implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     IDropTarget.DragEnter
; Purpose:    Indicate whether a drop can be accepted, and, if so, the effect of the drop.
; Arguments:  Arg1: -> IDataObject
;             Arg2: Key state MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON
;             Arg3: POINTL structure containing the current cursor coordinates in screen coordinates.
;             Arg4: -> DWORD Effect (DROPEFFECT_NONE, DROPEFFECT_COPY, DROPEFFECT_MOVE, DROPEFFECT_LINK)
; Return:     Operation result.

Method IDropTarget.DragEnter, uses xbx xsi, pIDataObject:POINTER, dKeyState:DWORD, Pt:POINTL, pEffect:POINTER
  local FormatEtc:FORMATETC, Medium:STGMEDIUM
  local dStrChars:DWORD, pFullFileName:PSTRING

  ANNOTATION use:Pt, dKeyState

;  DbgText "IDropTarget.DragEnter"
  SetObject xsi

  mov ebx, DROPEFFECT_NONE

  mov FormatEtc.cfFormat, CF_HDROP                      ;=> files
  mov FormatEtc.ptd, NULL
  mov FormatEtc.dwAspect, DVASPECT_CONTENT
  mov FormatEtc.lindex, -1
  mov FormatEtc.tymed, TYMED_HGLOBAL

  ICall pIDataObject::IDataObject.GetData, addr FormatEtc, addr Medium
  .if SUCCEEDED(eax)
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(Component).pOwner
    .ifBitSet [xcx].$Obj(ProjectManager).dFlags, PMF_EMPTY
      ;Get the first file
      invoke DragQueryFile, Medium.hGlobal, 0, NULL, 0  ;Get the number of Chars
      inc eax                                           ;Add the ZTC
      mov dStrChars, eax
      mov pFullFileName, $invoke(StrAlloc, dStrChars)   ;Allocate memory
      invoke DragQueryFile, Medium.hGlobal, 0, pFullFileName, dStrChars   ;Get the string
      invoke StrRScan, pFullFileName, "."
      .if xax != NULL
        DoesStringMatch? [xax], <.adep>
        .if ZERO?
          mov ebx, DROPEFFECT_MOVE
        .endif
      .endif
      invoke StrDispose, pFullFileName
    .else
      OCall xcx::ProjectManager.GroupsCollapse
      mov ebx, DROPEFFECT_LINK
    .endif
    invoke ReleaseStgMedium, addr Medium
  .endif
  mov xdx, pEffect
  mov DWORD ptr [xdx], ebx
  mov [xsi].dEffect, ebx
  mov eax, S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDropTarget.DragOver
; Purpose:    Provide target feedback to the user and communicates the drop's effect to the
;             DoDragDrop function so it can communicate the effect of the drop back to the source.
; Arguments:  Arg1: Key state MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON
;             Arg2: POINTL structure containing the current cursor coordinates in screen coordinates.
;             Arg3: -> DWORD Effect (DROPEFFECT_NONE, DROPEFFECT_COPY, DROPEFFECT_MOVE, DROPEFFECT_LINK)
; Return:     Operation result.

Method IDropTarget.DragOver, uses xbx xsi, dKeyState:DWORD, Pt:POINTL, pEffect:POINTER
  local tvht:TVHITTESTINFO, TestItem:TVITEM

  ANNOTATION use:dKeyState

;  DbgText "IDropTarget.DragOver"
  SetObject xsi

  mov xax, [xsi].pOwner
  mov xcx, [xax].$Obj(Component).pOwner
  .ifBitSet [xcx].$Obj(ProjectManager).dFlags, PMF_EMPTY
    mov ebx, [xsi].dEffect

  .else
    invoke ScreenToClient, [xsi].hTreeView, addr Pt
    ;Find out if the pointer is on the item. If it is, highlight the item as a drop target.
    s2s POINT ptr tvht.pt, POINT ptr Pt.x, xax, xdx
    invoke SendMessage, [xsi].hTreeView, TVM_HITTEST, 0, addr tvht
    .if xax != 0
      mov TestItem.hItem, xax
      mov TestItem.mask_, TVIF_HANDLE or TVIF_PARAM
      invoke SendMessage, [xsi].hTreeView, TVM_GETITEM, 0, addr TestItem

      mov xax, TestItem.lParam
      .if [xax].PROJECTITEM.dType == PIT_PROJECT
        mov ebx, DROPEFFECT_NONE
        xor eax, eax
      .else
        mov ebx, [xsi].dEffect
        mov xax, TestItem.hItem
      .endif
    .else
      mov ebx, DROPEFFECT_NONE
      xor eax, eax
    .endif
    invoke SendMessage, [xsi].hTreeView, TVM_SELECTITEM, TVGN_DROPHILITE, xax
  .endif

  mov xcx, pEffect
  mov DWORD ptr [xcx], ebx

  mov eax, S_OK
MethodEnd
; --------------------------------------------------------------------------------------------------
; Method:     IDropTarget.DragLeave
; Purpose:    Remove target feedback and releases the data object.
; Arguments:  None.
; Return:     Operation result.

Method IDropTarget.DragLeave, uses xsi
;  DbgText "IDropTarget.DragLeave"
  SetObject xsi
  ;Restore the previous expansion state of all groups
  mov xax, [xsi].pOwner
  mov xcx, [xax].$Obj(Component).pOwner
  .ifBitClr [xcx].$Obj(ProjectManager).dFlags, PMF_EMPTY
    OCall xcx::ProjectManager.GroupsExpandRestore, 0
  .endif
  mov [xsi].dEffect, DROPEFFECT_NONE
  mov eax, S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDropTarget.Drop
; Purpose:    Incorporate the source data into the target window, removes target feedback, and
;             releases the data object.
; Arguments:  Arg1: -> IDataObject
;             Arg2: Key state MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, MK_RBUTTON
;             Arg3: POINTL structure containing the current cursor coordinates in screen coordinates.
;             Arg4: -> DWORD Effect (DROPEFFECT_NONE, DROPEFFECT_COPY, DROPEFFECT_MOVE, DROPEFFECT_LINK)
; Return:     Operation result.

Method IDropTarget.Drop, uses xbx xdi xsi, pIDataObject:POINTER, dKeyState:DWORD, Pt:POINTL, pEffect:POINTER
  local FormatEtc:FORMATETC, Medium:STGMEDIUM
  local pFullFileName:PSTRING, pRelFileName:PSTRING, pEnvVarFileName:PSTRING
  local dStrChars:DWORD, cBuffer[1024]:CHR, pFilePart:POINTER, dEffect:DWORD, pGroupName:PSTRING
  local hItem:HTREEITEM, hDropOnItem:HTREEITEM, DropOnItem:TVITEM, tvht:TVHITTESTINFO, TVIS:TV_INSERTSTRUCT

  ANNOTATION use:dKeyState

;  DbgText "IDropTarget.Drop"
  SetObject xsi
  mov dEffect, DROPEFFECT_NONE

  mov FormatEtc.cfFormat, CF_HDROP                      ;=> files
  mov FormatEtc.ptd, NULL
  mov FormatEtc.dwAspect, DVASPECT_CONTENT
  mov FormatEtc.lindex, -1
  mov FormatEtc.tymed, TYMED_HGLOBAL
  ICall pIDataObject::IDataObject.GetData, addr FormatEtc, addr Medium
  .if SUCCEEDED(eax)
    ;http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/shell/
    ;  programmersguide/shell_basics/shell_basics_programming/transferring/datascenarios.asp

    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(Component).pOwner
    .ifBitSet [xcx].$Obj(ProjectManager).dFlags, PMF_EMPTY
      ;Get the first file
      invoke DragQueryFile, Medium.hGlobal, 0, NULL, 0  ;Get the number of Chars
      inc eax                                           ;Add the ZTC
      mov dStrChars, eax
      mov pFullFileName, $invoke(StrAlloc, dStrChars)   ;Allocate memory
      invoke DragQueryFile, Medium.hGlobal, 0, pFullFileName, dStrChars   ;Get the string
      invoke StrRScan, pFullFileName, "."
      .if xax != NULL
        DoesStringMatch? [xax], <.adep>
        .if ZERO?
          mov xax, [xsi].pOwner
          OCall [xax].$Obj(Component).pOwner::ProjectManager.ProjectLoadFrom, pFullFileName
          mov dEffect, DROPEFFECT_LINK
        .endif
      .endif
      invoke StrDispose, pFullFileName

    .else
      invoke SendMessage, [xsi].hTreeView, TVM_SELECTITEM, TVGN_DROPHILITE, 0   ;Reset DropLite
      invoke ScreenToClient, [xsi].hTreeView, addr Pt
      ;Find out if the pointer is on the item. If it is, highlight the item as a drop target.
      s2s POINT ptr tvht.pt, POINT ptr Pt, xax, xdx
      invoke SendMessage, [xsi].hTreeView, TVM_HITTEST, 0, addr tvht
      .if xax != 0
        mov hDropOnItem, xax
        mov DropOnItem.hItem, xax
        mov DropOnItem.mask_, TVIF_HANDLE or TVIF_PARAM
        invoke SendMessage, [xsi].hTreeView, TVM_GETITEM, 0, addr DropOnItem
        mov xax, DropOnItem.lParam
        .if [xax].PROJECTITEM.dType != PIT_PROJECT                      ;No drop on the root item
          ;Make sure we drop on a "Group" item
          .if [xax].PROJECTITEM.dType == PIT_FILE
            invoke SendMessage, [xsi].hTreeView, TVM_GETNEXTITEM, TVGN_PARENT, hDropOnItem
            mov hDropOnItem, xax
          .endif

          ;Get the files and insert them in the TreeView
          mov ebx, $32($invoke(DragQueryFile, Medium.hGlobal, -1, NULL, 0))   ;Get the dropped files count
          .while ebx != 0
            dec ebx
            invoke DragQueryFile, Medium.hGlobal, ebx, NULL, 0        ;Get the number of Chars
            inc eax                                                   ;Add the ZTC
            mov dStrChars, eax
            mov pFullFileName, $invoke(StrAlloc, dStrChars)           ;Allocate memory
            mov pRelFileName, $invoke(StrAlloc, dStrChars)            ;Allocate memory
            invoke DragQueryFile, Medium.hGlobal, ebx, pFullFileName, dStrChars   ;Get the string
            mov xcx, [xsi].pOwner
            mov xdi, [xcx].$Obj(Component).pOwner
            invoke PathRelativePathTo, pRelFileName, [xdi].$Obj(ProjectManager).pProjDirPath, \
                                       FILE_ATTRIBUTE_DIRECTORY, pFullFileName, FILE_ATTRIBUTE_NORMAL
            mov pEnvVarFileName, $invoke(PathSegmentsToEnvVars, pFullFileName)
            ;Check if the absolute or relative file path is already contained in the project
            OCall xdi::ProjectManager.IsFileAlreadyPresent, pFullFileName
            .if xax == 0
              mov xdx, pRelFileName
              .if CHR ptr [xdx] != 0
                OCall xdi::ProjectManager.IsFileAlreadyPresent, xdx
                cmp xax, 0
                jnz @F
              .endif
              mov xdx, pEnvVarFileName
              .if CHR ptr [xdx] != 0
                OCall xdi::ProjectManager.IsFileAlreadyPresent, xdx
              .endif
            .endif
          @@:
            .if xax == 0
              ;Not present => insert
              mov xdi, $MemAlloc(sizeof(PROJECTITEM))
              mov [xdi].PROJECTITEM.hEditor, 0
              mov [xdi].PROJECTITEM.dType, PIT_FILE

              ;File name priority:
              ;  1. Relative file names that start with ".\"
              ;  2. EnvVar replaced file names
              ;  3. Full file names
              mov xcx, pRelFileName
              .if CHR ptr [xcx] != 0
                invoke StrStartsWith, pRelFileName, $OfsCStr(".\")
                .if eax != FALSE
                  mov xcx, pRelFileName
                  jmp @F
                .endif
              .endif
              mov xcx, pEnvVarFileName
              .if CHR ptr [xcx] == 0
                mov xcx, pFullFileName
              .endif
            @@:
              invoke StrNew, xcx
              mov [xdi].PROJECTITEM.pFileName, xax
              invoke GetFullPathName, pFullFileName, lengthof cBuffer, addr cBuffer, addr pFilePart
              invoke StrNew, pFilePart
              mov [xdi].PROJECTITEM.pDispName, xax

              m2m TVIS.hParent, hDropOnItem, eax
              mov TVIS.hInsertAfter, TVI_SORT
              mov TVIS.item.mask_, TVIF_HANDLE or TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
              invoke StrLength, [xdi].PROJECTITEM.pDispName
              mov TVIS.item.cchTextMax, eax
              m2m TVIS.item.pszText, [xdi].PROJECTITEM.pDispName, xcx
              mov TVIS.item.iImage, ICON_INDEX_FILE
              mov TVIS.item.iSelectedImage, ICON_INDEX_FILE
              mov TVIS.item.lParam, xdi
              invoke SendMessage, [xsi].hTreeView, TVM_INSERTITEM, 0, addr TVIS  ;Returns inserted item
              mov hItem, xax

              ;Restore the previous expansion state of all groups and show the inserted item
              mov xcx, [xsi].pOwner
              OCall [xcx].$Obj(Component).pOwner::ProjectManager.GroupsExpandRestore, hItem

              invoke SendMessage, [xsi].hTreeView, TVM_SELECTITEM, TVGN_CARET, hItem
              invoke SetFocus, [xsi].hTreeView

              mov xax, [xsi].pOwner
              mov xcx, [xax].$Obj(Component).pOwner
              BitSet [xcx].$Obj(ProjectManager).dFlags, PMF_DIRTY
            .else
              ;Already present => warning
              mov hItem, xax                              ;hItem = found item
              invoke SendMessage, [xsi].hTreeView, TVM_GETNEXTITEM, TVGN_PARENT, hItem
              mov DropOnItem.hItem, xax
              mov DropOnItem.mask_, TVIF_HANDLE or TVIF_PARAM
              invoke SendMessage, [xsi].hTreeView, TVM_GETITEM, 0, addr DropOnItem
              mov xax, DropOnItem.lParam
              mov xcx, [xax].PROJECTITEM.pDispName
              mov pGroupName, xcx
              lea xdi, cBuffer
              WriteF xdi, "The file \`¦SU\` is already present in the group \`¦ST\`\:", pFullFileName, pGroupName
              mov xdx, [xsi].pOwner
              mov xdi, [xdx].$Obj(Component).pOwner
              OCall xdi::ProjectManager.GroupsExpandRestore, hItem
              invoke SendMessage, [xsi].hTreeView, TVM_SELECTITEM, TVGN_CARET, hItem
              invoke MessageBox, [xdi].$Obj(ProjectManager).hWnd, addr cBuffer, \
                                 $OfsCStr("Waring"), MB_OKCANCEL or MB_ICONWARNING
              .break .if eax == IDCANCEL
            .endif
            invoke StrDispose, pFullFileName
            invoke StrDispose, pRelFileName
            invoke StrDispose, pEnvVarFileName
          .endw
          invoke SetFocus, [xsi].hTreeView
          mov dEffect, DROPEFFECT_LINK
        .endif
      .endif
    .endif
    invoke ReleaseStgMedium, addr Medium
  .endif
  mrm [xsi].dEffect, dEffect, edx
  mov xcx, pEffect
  mov DWORD ptr [xcx], edx
  mov eax, S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDropTarget.Init
; Purpose:    Initialize the IDropTarget object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: TreeView window HANDLE.
; Return:     Nothing.

Method IDropTarget.Init, uses xsi, pOwner:POINTER, hTreeView:HWND
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].hTreeView, hTreeView, xax
MethodEnd
