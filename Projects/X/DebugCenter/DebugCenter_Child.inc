; ==================================================================================================
; Title:      DebugCenter_Child.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter MDI child ancestor.
; ==================================================================================================


Object DbgMdiChild, DBG_MDI_CHILD_ID, MdiChildWnd               ;MDI Child descendant.
  VirtualMethod     ClpBrdClear
  VirtualMethod     ClpBrdCopy
  VirtualMethod     ClpBrdCut
  VirtualMethod     ClpBrdPaste
  VirtualAbstract   ClpBrdSetBtns
  RedefineMethod    Done
  VirtualAbstract   Erase
  VirtualMethod     Open,             PSTRING                   ;-> Filename
  VirtualAbstract   Print
  VirtualMethod     Save
  VirtualMethod     SaveAs,           PSTRING, PSTRING          ;-> Filter, -> Def. extension
  VirtualMethod     SaveTo,           PSTRING                   ;-> FileName
  VirtualAbstract   UpdateStatusbar
  VirtualAbstract   ZoomIn
  VirtualAbstract   ZoomOut

  VirtualEvent      OnMdiActivate,    WM_MDIACTIVATE

  DefineVariable    dZoomFactor,      DWORD,              ZOOM_BASE
  DefineVariable    pFileName,        PSTRING,            NULL
  DefineVariable    pMagnetism,       $ObjPtr(Magnetism), NULL
ObjectEnd


.code
; ==================================================================================================
;    DbgMdiChild implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.ClpBrdClear
; Purpose:    Delete the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChild.ClpBrdClear
  OCall ClpBrdSetBtns
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.ClpBrdCopy
; Purpose:    Copy the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChild.ClpBrdCopy
  OCall ClpBrdSetBtns
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.ClpBrdCut
; Purpose:    Cut the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChild.ClpBrdCut
  OCall ClpBrdSetBtns
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.ClpBrdPaste
; Purpose:    Paste the clipboard content.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChild.ClpBrdPaste
  OCall ClpBrdSetBtns
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.Done
; Purpose:    Finalize the DbgMdiChild object.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChild.Done, uses xbx xsi
  SetObject xsi
  .if [xsi].pFileName != NULL
    invoke StrDispose, [xsi].pFileName
  .endif
  Destroy [xsi].pMagnetism

  ;Manage the main Menu
  mov xcx, [xsi].pOwner
  dec [xcx].$Obj(DbgMdiClient).dChildCount
  .if ZERO?                                             ;Last child ?
    mov xbx, [xcx].$Obj(DbgMdiClient).pOwner
    invoke SendMessage, [xcx].$Obj(DbgMdiClient).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    OCall xbx::Application.EnableActions, FALSE
    OCall xbx::Application.ManageOptions, 0
    invoke DrawMenuBar, [xbx].$Obj(MdiApp).hWnd         ;Redraw the new menu bar

    ;Clear Statusbar
    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, NULL, SBT_SUNKEN
    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 2, NULL, SBT_SUNKEN
  .endif

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.OnMdiActivate
; Purpose:    Event procedure for WM_MDIACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChild.OnMdiActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;Manage Menu, Statusbar and Toolbar options
  mov xax, lParam
  .if xax == [xsi].hWnd
    invoke GetObjectID, xsi
    mov xcx, [xsi].pOwner
    OCall [xcx].$Obj(DbgMdiClient).pOwner::Application.ManageOptions, eax
    OCall xsi.ClpBrdSetBtns
    OCall xsi.UpdateStatusbar
  .elseif xax == NULL                                   ;Last Child!
    mov xcx, [xsi].pOwner
    OCall [xcx].$Obj(DbgMdiClient).pOwner::Application.ManageOptions, eax
  .endif

  invoke DefMDIChildProc, [xsi].hWnd, WM_MDIACTIVATE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.Open
; Purpose:    Store the specified file name.
; Arguments:  Arg1: -> Filename.
; Return:     Nothing.

Method DbgMdiChild.Open, uses xsi, pFileName:PSTRING
  SetObject xsi
  .if [xsi].pFileName != NULL
    invoke StrDispose, [xsi].pFileName
  .endif
  mov [xsi].pFileName, $invoke(StrNew, pFileName)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.Save
; Purpose:    Save to file.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChild.Save
  SetObject xcx
  .if [xcx].pFileName != NULL
    OCall xcx.SaveTo, [xcx].pFileName
  .else
    OCall xcx.SaveAs, NULL, NULL
  .endif
  ACall Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.SaveAs
; Purpose:    Save the content to a selectable file.
; Arguments:  Arg1: -> Filter.
;             Arg2: -> Default extension.
; Return:     Nothing.

Method DbgMdiChild.SaveAs, uses xbx xsi, pFilter:PSTRING, pDefExt:PSTRING
  local OpenFileName:OPENFILENAME, cInitDir[MAX_PATH]:CHR, cFileName[MAX_PATH]:CHR, cResText[1024]:CHR

  SetObject xsi

  mov xax, [xsi].pOwner
  mov xbx, [xax].$Obj(DbgMdiClient).pOwner

  mov OpenFileName.lStructSize, sizeof(OPENFILENAME)
  m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
  m2m OpenFileName.hInstance, hInstance, xcx
  m2m OpenFileName.lpstrFilter, pFilter, xax
  m2z OpenFileName.lpstrCustomFilter
  m2z OpenFileName.nMaxCustFilter
  m2z OpenFileName.nFilterIndex
  lea xax, cFileName
  mov OpenFileName.lpstrFile, xax
  .if [xsi].pFileName == NULL
    m2z CHR ptr [xax]
  .else
    invoke StrCCopy, xax, [xsi].pFileName, lengthof cFileName
  .endif
  mov OpenFileName.nMaxFile, lengthof cFileName - 1
  m2z OpenFileName.lpstrFileTitle
  m2z OpenFileName.nMaxFileTitle
  lea xax, cInitDir
  m2z CHR ptr [xax]
  m2m OpenFileName.lpstrInitialDir, [xbx].$Obj(Application).pDirectory, xax
  mov edx, [xbx].$Obj(Application).dLanguage
  add edx, 171                                      ;"Save as"
  invoke LoadString, hInstance, edx, addr cResText, lengthof cResText
  lea xcx, cResText
  mov OpenFileName.lpstrTitle, xcx
  m2m OpenFileName.lpstrDefExt, pDefExt, xax
  mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or \
                          OFN_HIDEREADONLY or OFN_OVERWRITEPROMPT
  invoke GetSaveFileName, addr OpenFileName
  .if eax != 0
    invoke StrRScan, addr cFileName, "."
    .if eax == NULL
      invoke StrCCat, addr cFileName, offset szRtfExt, lengthof cFileName
    .endif

    OCall xsi.SaveTo, addr cFileName

    ;Remember this new path
    invoke StrRScan, addr cFileName, "\"
    .if xax != NULL
      m2z BYTE ptr [xax]
      invoke StrReplace, [xbx].$Obj(Application).pDirectory, addr cFileName
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChild.SaveTo
; Purpose:    Save the specified file.
; Arguments:  Arg1: -> File path and name.
; Return:     Nothing.

Method DbgMdiChild.SaveTo, uses xsi, pFileName:PSTRING
  SetObject xsi
  mov xax, [xsi].pFileName
  .if xax != pFileName
    .if xax != NULL
      invoke StrDispose, xax
    .endif
    mov [xsi].pFileName, $invoke(StrNew, pFileName)
    invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, pFileName
  .endif
MethodEnd
