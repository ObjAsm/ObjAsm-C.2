; ==================================================================================================
; Title:      ADE_Application.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ChangeLanguage
; Purpose:    Switch the application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method Application.ChangeLanguage, uses xbx xdi xsi, dLangID:DWORD
  SetButtonText macro ButtonCommand:req, TextIndex:req
    mov eax, dLangID
    add eax, TextIndex
    invoke LoadString, hInstance, eax, xdi, lengthof cButtonText - 1
    invoke StrLScan, xdi, MENU_CHAR_LITERAL
    .if xax == NULL
      mov [xdi], xax
    .else
      add xax, sizeof CHR                               ;Skip MENULITERALCHAR character
      mov pPos, xax
      invoke StrSize, xax
      invoke MemShift, xdi, pPos, eax
    .endif
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETBUTTONINFO, ButtonCommand, addr tbbi
  endm

  local MenuInfo:MENUITEMINFO, tbbi:TBBUTTONINFO, cButtonText[256]:CHR, pPos:POINTER

  SetObject xsi
  m2m [xsi].dLangID, dLangID, eax                       ;Save setting

  ;Keep updated both menus!
  mov eax, dLangID
  cdiv LANGUAGE_STEP
  lea edi, [edx + IDM_LANGUAGE_ENGLISH]

  ;The IDM_LANGUAGE popup menu has to be found in the ChildMenu using GetMenuItemInfo since
  ;  it can have position 1 or 2 depending if a MDI child is maximized or not.
  mov MenuInfo.cbSize, sizeof MenuInfo
  mov MenuInfo.fMask, MIIM_SUBMENU
  invoke GetMenuItemInfo, [xsi].hMenuChild, IDM_LANGUAGE, FALSE, addr MenuInfo
  invoke CheckMenuRadioItem, MenuInfo.hSubMenu, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, \
                             edi, MF_BYCOMMAND

  ;IDM_LANGUAGE popup menu has only positon 1 in the InitMenu.
  invoke GetSubMenu, [xsi].hMenuInit, 1
  invoke CheckMenuRadioItem, xax, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, edi, MF_BYCOMMAND

  ;Language switch
  mov xbx, $invoke(GetMenu, [xsi].hWnd)                 ;Get the current menu
  OCall [xsi].Menu::XMenu.ChangeLanguage, xbx, dLangID  ;Active menu is converted

  ;Convert remaining main menu
  .if xbx == [xsi].hMenuInit
    OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuChild, TRUE
  .else
    OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuInit, TRUE
  .endif

  ;Set Toolbar button texts
  mov tbbi.TBBUTTONINFO.cbSize, sizeof TBBUTTONINFO
  mov tbbi.TBBUTTONINFO.dwMask, TBIF_TEXT
  lea xdi, cButtonText
  mov tbbi.TBBUTTONINFO.pszText, xdi
  mov tbbi.TBBUTTONINFO.cchText, lengthof cButtonText - 1

  lea xbx, [xsi].TbFile
  SetButtonText IDM_FILE_NEW,   01
  SetButtonText IDM_FILE_CLOSE, 02

  lea xbx, [xsi].TbWindow
  SetButtonText IDM_WINDOW_CASCADE,  31
  SetButtonText IDM_WINDOW_TILE_HOR, 32
  SetButtonText IDM_WINDOW_TILE_VER, 33
  SetButtonText IDM_WINDOW_ARRANGE,  34
  SetButtonText IDM_WINDOW_CLOSEALL, 35
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Deserialize
; Purpose:    Restore serialized members to its original values.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method Application.Deserialize, uses xsi, pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Deserialize, pDeserInfo
  OCall [xsi].pClientWnd::ChildWnd.Deserialize, pDeserInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the application object. Objects associated with window controls are
;             destroyed by Windows automatically when WM_DESTROY is send.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  ;Destroy resources
  OCall [xsi].EditorSharedResources::EditorSharedResources.Done
  OCall [xsi].CodeEditorResources::EditorResources.Done
  
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].RBar::Rebar.Done
  OCall [xsi].Status::Statusbar.Done
  OCall [xsi].TbFile::Toolbar.Done
  OCall [xsi].TbWindow::Toolbar.Done
  OCall [xsi].PropWnd::PropertiesWnd.Done
  OCall [xsi].ProjWnd::ProjectWnd.Done
  OCall [xsi].SplitterVert::Splitter.Done
  OCall [xsi].SplitterHorz::Splitter.Done
  OCall [xsi].Menu::XMenu.Done
  Destroy [xsi].pClientWnd
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Arg1: Enable TRUE/FALSE.
; Return:     Nothing.

Method Application.EnableActions, uses xsi, dAction:DWORD
  SetObject xsi
  OCall [xsi].TbFile::Toolbar.BtnEnable, IDM_FILE_CLOSE, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CASCADE,  dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_HOR, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_VER, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_ARRANGE,  dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSEALL, dAction
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xdi xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD, pSBHelp:POINTER
  local hDC:HDC

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)

  ;Rebar + Statusbar + ListView + TabControl + ComboBoxEx
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES or \
                             ICC_LISTVIEW_CLASSES or ICC_TAB_CLASSES or ICC_USEREX_CLASSES

  ;Load application & menu icons
  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CASCADE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_HOR")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_VER")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ARRANGE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CLOSEALL")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CONTEXT_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CONTEXT_LOAD")

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("MDIACCEL"))

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))

  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 3)

  ;Create the MDI Frame window
  mov dWndWidth, 1600
  mov dWndHeight, 800
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset szApplicationClassName, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, \
                         NULL, [xsi].hMenuInit, hInstance, pSelf

  ;Create and Initialize Client window
  mov [xsi].pClientWnd, $New(ClientWnd)
  OCall xax::ClientWnd.Init, xsi
  mov xax, [xsi].pClientWnd
  mov xdi, [xax].$Obj(ClientWnd).hWnd

  ;Create Editor (shared)Resources
  OCall [xsi].EditorSharedResources::EditorSharedResources.Init, xsi
  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)
  OCall [xsi].CodeEditorResources::EditorResources.Init, xsi, \
                                      $OfsCStr("ADE_MASM.ini"), addr cEditorCodePrefix, \
                                      hDC, addr [xsi].EditorSharedResources
  invoke ReleaseDC, [xsi].hWnd, hDC

  ;Create and initialize XMenu
  m2m pSBHelp, $MethodAddr(Application.StatusbarHelp), xax
  OCall [xsi].Menu::XMenu.Init, xsi, [xsi].hWnd, xdi, [xsi].hMenuChildWnd, \
                                addr [xsi].IconImageList, pSBHelp, IDLANG_ENGLISH

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Load
; Purpose:    Load and initialize the streamable instance from a stream object. Descendant objects
;             should redefine this method and load new members.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method Application.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
;  local WP:WINDOWPLACEMENT
;
;  SetObject xsi
;  invoke LockWindowUpdate, [xsi].hWnd
;
;  ;Load & restore MDI frame window data
;  ACall xsi.Load, pStream, pDeserInfo                 ;WinPrimer returns the previous hWnd
;  mov xcx, pDeserInfo
;  OCall [xcx].DESER_INFO.pDesLUT::DesLUT.Insert, xax, [xsi].hWnd
;  OCall pStream::Stream.BinRead32                     ;Read prev. dLanguage
;  .if eax != [xsi].dLangID
;    OCall xsi.ChangeLanguage, eax
;  .endif
;  OCall pStream::Stream.BinRead, addr WP, sizeof WP
;  invoke SetWindowPlacement, [xsi].hWnd, addr WP
;
;  ;Load vertical and horizontal Splitter objects
;  OCall [xsi].SplitterVert::Splitter.Load, pStream, pDeserInfo
;  OCall [xsi].SplitterHorz::Splitter.Load, pStream, pDeserInfo
;
;  ;Load MDI client window object & MDI child window objects
;  OCall pStream::Stream.GetPreAlloc, [xsi].pClientWnd, MyClientID, pDeserInfo
;
;  ;Reposition all windows
;  OCall xsi.OnSize, SIZE_RESTORED, 0
;
;  invoke LockWindowUpdate, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.LoadContext
; Purpose:    Load the complete application context from a disk stream.
; Arguments:  Arg1: -> File name.
; Return:     Nothing.

Method Application.LoadContext, uses xbx xdi xsi, pStreamName:PSTRING
;  local DskStm:$Obj(DiskStream), DLTbl:$Obj(DesLUT), DeserInfo:DESER_INFO
;
;  SetObject xsi
;  mov xcx, [xsi].pClientWnd
;  invoke EnumChildWindows, [xcx].$Obj(ClientWnd).hWnd, offset CloseEnumProc, 0
;
;  mov xdi, $New(DskStm::DiskStream)
;  OCall xdi::DiskStream.Init, xsi, pStreamName, 0, 0, NULL, 0, 0, 0
;  mov xbx, $New(DLTbl::DesLUT)
;  OCall xbx::DesLUT.Init, xsi, DLT_MEM_PAGE, DLT_MEM_PAGE, DLT_MAX_CAPACITY
;
;  ;Prepare DESER_INFO structure
;  mov DeserInfo.pDesLUT, xbx
;
;  OCall xdi::Stream.GetPreAlloc, xsi, DemoApp10ID, addr DeserInfo
;  OCall xsi.Deserialize, addr DeserInfo
;  OCall xbx::DesLUT.Done
;  OCall xdi::Stream.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CBTProc
; Purpose:    Customization procedure using SetWindowsHookEx.
; Arguments:  Arg1: Hook code.
;             Arg2: Depends on hook code. For HCBT_ACTIVATE, wParam = hWnd.
;             Arg3: Depends on hook code. For HCBT_ACTIVATE, lParam -> CBTACTIVATESTRUCT.
; Return:     eax = Zero if handled.

CBTProc proc uses xbx dCode:DWORD, wParam:WPARAM, lParam:LPARAM
  local cText[16]:CHR

  .if dCode == HCBT_ACTIVATE
    lea xbx, cText

;    mov edx, $ObjTmpl(Application).dLanguage
;    add edx, 102
;    invoke LoadString, hInstance, edx, xbx, lengthof cText
    invoke StrCopy, xbx, $OfsCStr("Yes")
    invoke GetDlgItem, wParam, IDYES
    invoke SetWindowText, xax, xbx

;    mov edx, $ObjTmpl(Application).dLanguage
;    add edx, 103
;    invoke LoadString, hInstance, edx, xbx, lengthof cText
    invoke StrCopy, xbx, $OfsCStr("No")
    invoke GetDlgItem, wParam, IDNO
    invoke SetWindowText, xax, xbx

    invoke UnhookWindowsHookEx, hCBTProc

    xor eax, eax
  .else
    invoke CallNextHookEx, hCBTProc, dCode, wParam, lParam
  .endif
  ret
CBTProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE and WM_QUERYENDSESSION message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

AskDirtyEditor proc uses xbx xdi hWnd:HWND, lParam:XWORD
  local cCaption[512]:CHR, cText[1024]:CHR

  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xbx, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID
      .ifBitSet [xbx].$Obj(Editor).dFlags, EIF_DIRTY
        ;MessageBox customization
        invoke SetWindowsHookEx, WH_CBT, offset CBTProc, hInstance, $32($invoke(GetCurrentThreadId))
        mov hCBTProc, xax
        lea xdi, cText
        .ifBitSet [xbx].$Obj(Editor).dFlags, EIF_NEW_FILE
          WriteF xdi, "Save \´¦SU\´ changes?", [xbx].$Obj(Editor).pFullFileName
        .else
          WriteF xdi, "Save editor changes to\n¦SU ?", [xbx].$Obj(Editor).pFullFileName
        .endif 
        invoke MessageBox, hWnd, addr cText, $OfsCStr("Editor close"), MB_YESNOCANCEL or MB_ICONQUESTION
        .if eax == IDNO
          mov eax, TRUE                                 ;Continue enumeration
          ret
        .elseif eax == IDYES
          .ifBitSet [xbx].$Obj(Editor).dFlags, EIF_NEW_FILE
            OCall xbx::Editor.SaveAs
          .else
            OCall xbx::Editor.Save
          .endif
          mov eax, TRUE                                 ;Continue enumeration
          ret
        .else
          mov xcx, lParam
          mov DWORD ptr [xcx], TRUE
          mov eax, FALSE                                ;Break enumeration
          ret
        .endif
      .endif
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
AskDirtyEditor endp

Method Application.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD, dCancel:DWORD
  local cCaption[512]:CHR, cText[1024]:CHR

  ANNOTATION use:wParam lParam

  SetObject xsi
  mov dMsg, eax                                         ;Save windows message passed in eax
  invoke GetKeyState, VK_CONTROL
  mov xbx, [xsi].pClientWnd
  and ax, BIT15
  .if ZERO? || dMsg != WM_CLOSE                         ;If CTRL pressed => close without asking
    mov dCancel, FALSE
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset AskDirtyEditor, addr dCancel
    .if dCancel != FALSE
      ExitMethod
    .endif
  .endif
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, dMsg, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

SaveEditor proc uses xbx hWnd:HWND, lParam:XWORD
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xbx, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID
      .ifBitSet [xbx].$Obj(Editor).dFlags, EIF_NEW_FILE
        OCall xbx::Editor.SaveAs
      .else
        OCall xbx::Editor.Save
      .endif
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
SaveEditor endp

Method Application.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, AboutDlg:$Obj(DialogAbout), SetupDlg:$Obj(SetupDlg)
  local pIFODlg:POINTER, pIFileDialog2:POINTER, cBuffer[MAX_PATH]:CHR
  local pIFSDlg:POINTER
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pDisplayName:POINTER, hIcon:HICON

  ANNOTATION use:wParam lParam

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd
  .if ax == IDM_FILE_NEW                                ;Create a child window
    New Editor
    .if xax != NULL
      OCall xax::Editor.Init, [xsi].pClientWnd, addr [xsi].CodeEditorResources, NULL
    .endif
    xor eax, eax

  .elseif ax == IDM_BREAK
    int 3
    xor eax, eax
  
  .elseif ax == IDM_FILE_OPEN                           ;Open a file
    invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_ALL, \
                             offset IID_IFileOpenDialog, addr pIFODlg
    .if SUCCEEDED(eax)
      ICall pIFODlg::IFileOpenDialog.SetFileTypes, MultiFileSpecCount, addr MultiFileSpec
      ICall pIFODlg::IFileOpenDialog.SetFileTypeIndex, 2
      ICall pIFODlg::IFileOpenDialog.SetOptions, FOS_ALLOWMULTISELECT
      ICall pIFODlg::IFileOpenDialog.SetTitle, $OfsCStrW("Open a file...")
      ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, $OfsCStrW("&Open")
      ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, $OfsCStrW("Selected file(s): ")

      ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
      .if SUCCEEDED(eax)
        ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, $OfsCStrW("&Cancel")
        ICall pIFileDialog2::IFileDialog2.Release
      .endif

      ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
      .if SUCCEEDED(eax)
        ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
        ICall pISIArr::IShellItemArray.GetCount, addr dCount
        xor ebx, ebx
        .while ebx < dCount
          ICall pISIArr::IShellItemArray.GetItemAt, ebx, addr pIShellItem
          ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDisplayName
          mov xdi, $New(Editor)
          OCall xdi::Editor.Init, [xsi].pClientWnd, addr [xsi].CodeEditorResources, pDisplayName
          ICall pIShellItem::IShellItem.Release
          inc ebx
        .endw
        ICall pISIArr::IShellItemArray.Release
      .endif
      ICall pIFODlg::IFileOpenDialog.Release
    .endif
    xor eax, eax

  
;;    mov edx, [xsi].dLanguage
;;    add edx, 170                                      ;"Open file"
;;    invoke LoadString, hInstance, edx, addr cResText, lengthof cResText
;;    lea xcx, cResText
;;    mov OpenFileName.lpstrTitle, xcx

  .elseif ax == IDM_FILE_SAVE_ALL
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset SaveEditor, 0
    xor eax, eax

  .elseif ax == IDM_FILE_SAVE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xax
      .if eax == ADE_EditorID
        .ifBitSet [xbx].$Obj(Editor).dFlags, EIF_NEW_FILE
          OCall xbx::Editor.SaveAs
        .else
          OCall xbx::Editor.Save
        .endif
      .endif
    .endif
    xor eax, eax

  .elseif ax == IDM_FILE_SAVE_AS
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xax
      .if eax == ADE_EditorID
        OCall xbx::Editor.SaveAs
      .endif
    .endif
    xor eax, eax

  .elseif (ax == IDM_FILE_CLOSE) || (ax == SC_CLOSE)    ;Close the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == SC_RESTORE                              ;Restore the active window
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIRESTORE, xax, 0
    xor eax, eax

  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  .elseif ax == SC_MAXIMIZE                             ;Maximize the active window
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIMAXIMIZE, xax, 0
    xor eax, eax

  .elseif ax == IDM_FILE_SETUP
    New SetupDlg::SetupDlg
    OCall SetupDlg::SetupDlg.Init, xsi, [xsi].hWnd
    OCall SetupDlg::SetupDlg.Show
    OCall SetupDlg::SetupDlg.Done
    xor eax, eax

  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  ;Messages for language selection
  .elseif (ax >= IDM_LANGUAGE_ENGLISH) && (ax <= IDM_LANGUAGE_SPANISH)
    ;Calculate IDLANG_XXX
    sub eax, IDM_LANGUAGE_ENGLISH
    mov ecx, LANGUAGE_STEP
    mul ecx
    OCall xsi.ChangeLanguage, eax
    xor eax, eax

  ;Messages for arranging child windows
  .elseif ax == IDM_WINDOW_TILE_HOR
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_TILE_VER
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_CASCADE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDICASCADE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_ARRANGE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIICONARRANGE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_CLOSEALL                     ;Attempt to close all windows
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset CloseEnumProc, 0
    xor eax, eax

  ;Messages for help menu
  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New AboutDlg::DialogAbout
    OCall AboutDlg::DialogAbout.Init, xsi, [xsi].hWnd
    OCall AboutDlg::DialogAbout.Show
    OCall AboutDlg::DialogAbout.Done
    xor eax, eax

  ;Serialization messages
  .elseif ax == IDM_FILE_SAVE_CTX
    OCall xsi.SaveContext, $OfsCStr("ACE.ctx")
    xor eax, eax

  .elseif ax == IDM_FILE_LOAD_CTX
    OCall xsi.LoadContext, $OfsCStr("ACE.ctx")
    xor eax, eax

  ;Pass to active child
  .else
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi

  ;Initialize project window
  OCall [xsi].ProjWnd::ProjectWnd.Init, xsi, [xsi].hWnd

  ;Initialize properties window
  OCall [xsi].PropWnd::PropertiesWnd.Init, xsi, [xsi].hWnd

  ;Initialize splitters
  OCall [xsi].SplitterVert::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_VERTICAL, 200, 30, 50
  OCall [xsi].SplitterHorz::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_HORIZONTAL, 200, 55, 75

  ;Initialize statusbar
  OCall [xsi].Status::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  ;Create rebar, toolbars
  OCall [xsi].RBar::Rebar.Init, xsi, [xsi].hWnd

  OCall [xsi].TbWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbWindow::Toolbar.GetHeight))
  OCall [xsi].TbWindow::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbWindow.hWnd, eax, ebx

  OCall [xsi].TbFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbFile::Toolbar.GetHeight))
  OCall [xsi].TbFile::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbFile.hWnd, eax, ebx

  ;Disable toolbar buttons
  OCall xsi.EnableActions, FALSE

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  .if [xsi].hMenuInit
    invoke DestroyMenu, [xsi].hMenuInit
  .endif
  .if [xsi].hMenuChild
    invoke DestroyMenu, [xsi].hMenuChild
  .endif
  .if [xsi].hAccelerators
    invoke DestroyAcceleratorTable, [xsi].hAccelerators
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method Application.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  mov eax, -1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dWidth:DWORD, dTop:DWORD
  local CtRect:RECT, SbRect:RECT, RbRect:RECT
  local ProjWndRect:RECT, PropWndRect:RECT, SpVerRect:RECT, SpHorRect:RECT

  ANNOTATION use:wParam lParam

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr CtRect
    m2m dHeight, CtRect.bottom, eax
    m2m dWidth, CtRect.right, ecx

    ;Place rebar
    invoke GetWindowRect, [xsi].RBar.hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xsi].RBar.hWnd, 0, 0, dWidth, eax, FALSE

    ;Place statusbar
    invoke GetWindowRect, [xsi].Status.hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xsi].Status.hWnd, 0, dHeight, dWidth, eax, FALSE
    mov ecx, dTop
    sub dHeight, ecx

    ;Place vertical splitter
    invoke GetWindowRect, [xsi].SplitterVert.hWnd, addr SpVerRect
    invoke ScreenToClient, [xsi].hWnd, addr SpVerRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpVerRect.right
    mov eax, SpVerRect.right
    sub eax, SpVerRect.left
    invoke MoveWindow, [xsi].SplitterVert.hWnd, SpVerRect.left, dTop, eax, dHeight, FALSE

    ;Place horizontal splitter
    invoke GetWindowRect, [xsi].SplitterHorz.hWnd, addr SpHorRect
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.right
    mov eax, SpHorRect.bottom
    sub eax, SpHorRect.top
    invoke MoveWindow, [xsi].SplitterHorz.hWnd, 0, SpHorRect.top, SpVerRect.left, eax, FALSE

    ;Place project window
    invoke GetWindowRect, [xsi].ProjWnd.hWnd, addr ProjWndRect
    invoke ScreenToClient, [xsi].hWnd, addr ProjWndRect.left
    invoke ScreenToClient, [xsi].hWnd, addr ProjWndRect.right
    mov eax, SpHorRect.top
    sub eax, dTop
    invoke MoveWindow, [xsi].ProjWnd.hWnd, 0, dTop, SpVerRect.left, eax, FALSE

    ;Place properties window
    invoke GetWindowRect, [xsi].PropWnd.hWnd, addr PropWndRect
    invoke ScreenToClient, [xsi].hWnd, addr PropWndRect.left
    invoke ScreenToClient, [xsi].hWnd, addr PropWndRect.right
    mov eax, dHeight
    add eax, dTop
    sub eax, SpHorRect.bottom
    invoke MoveWindow, [xsi].PropWnd.hWnd, 0, SpHorRect.bottom, SpVerRect.left, eax, FALSE

    ;Place client window
    mov xcx, [xsi].pClientWnd
    .if xcx != NULL
      mov eax, CtRect.right
      sub eax, SpVerRect.right
      invoke MoveWindow, [xcx].$Obj(ClientWnd).hWnd, SpVerRect.right, dTop, eax, dHeight, FALSE
    .endif

    ;Redraw all child windows
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                         RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
    xor eax, eax                                      ;Return zero
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CloseEnumProc (Callback)
; Purpose:    Close all open child windows.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed to the enumeration procedure.
; Return:     eax = TRUE.

CloseEnumProc proc hWnd:HWND, lParam:LPARAM
  invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szApplicationClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method Application.StatusbarHelp,, pHelpStr:PSTRING
  SetObject xcx
  OCall [xcx].Status::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.SaveContext
; Purpose:    Store the complete application context in a disk stream.
; Arguments:  Arg1: -> File name.
; Return:     Nothing.

Method Application.SaveContext, uses xdi xsi, pStreamName:PSTRING
  local DskStm:$Obj(DiskStream)

  SetObject xsi
  lea xdi, DskStm
  New xdi::DiskStream
  OCall xdi::DiskStream.Init, xsi, pStreamName, 0, 0, NULL, 0, 0, 0
  OCall xsi.Serialize
  OCall xdi::Stream.Put, xsi
  OCall xdi::Stream.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Store
; Purpose:    Store the streamable instance in a stream object. Descendant objects should redefine
;             this method and store new members.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Application.Store, uses xsi, pStream:$ObjPtr(Stream)
  local WP:WINDOWPLACEMENT

  SetObject xsi

  ;Store MDI frame window data
  ACall xsi.Store, pStream                            ;Store pSelf ... hWnd
  OCall pStream::Stream.BinWrite32, [xsi].dLangID
  mov WP.length_, sizeof WP
  invoke GetWindowPlacement, [xsi].hWnd, addr WP
  OCall pStream::Stream.BinWrite, addr WP, sizeof WP

  ;Store vertical and horizontal Splitter objects
  OCall [xsi].SplitterVert::Splitter.Store, pStream
  OCall [xsi].SplitterHorz::Splitter.Store, pStream

  ;Store MDI client window object & MDI child window objects
  OCall pStream::Stream.Put, [xsi].pClientWnd
MethodEnd
