; ==================================================================================================
; Title:      ADE_Application.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
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

  ANNOTATION use:pPos

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
  SetButtonText IDM_FILE_NEW,         01
  SetButtonText IDM_FILE_OPEN,        02
  SetButtonText IDM_FILE_SAVE,        03
  SetButtonText IDM_FILE_SAVEAS,      04
  SetButtonText IDM_FILE_SAVEALL,     05
  SetButtonText IDM_FILE_CLOSE,       06
  SetButtonText IDM_FILE_CLOSEALL,    07
  SetButtonText IDM_FILE_PRINT,       11
  SetButtonText IDM_FILE_PIN,         03

  lea xbx, [xsi].TbEdit
  SetButtonText IDM_EDIT_CUT,         21
  SetButtonText IDM_EDIT_COPY,        22
  SetButtonText IDM_EDIT_PASTE,       23
  SetButtonText IDM_EDIT_DELETE,      24
  SetButtonText IDM_EDIT_FIND,        26

  lea xbx, [xsi].TbWindow
  SetButtonText IDM_WINDOW_CASCADE,   51
  SetButtonText IDM_WINDOW_TILE_HOR,  52
  SetButtonText IDM_WINDOW_TILE_VER,  53
  SetButtonText IDM_WINDOW_ARRANGE,   54
  SetButtonText IDM_WINDOW_ZOOMIN,    57
  SetButtonText IDM_WINDOW_ZOOMOUT,   58

  mov xdx, [xsi].pClientWnd
  mov xcx, [xdx].$Obj(ClientWnd).hWnd
  invoke SendMessage, xcx, WM_MDIGETACTIVE, 0, 0
  .if xax
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    OCall xax::ChildWnd.UpdateStatusbar
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ConfigLoad
; Purpose:    Load the application configuration.
; Arguments:  Arg1: -> Ini-File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Application.ConfigLoad, uses xbx xdi xsi, pIniFileName:PSTRING
  local DrawAttr:DRAW_ATTR, FontDef:FONT_DEF, dIniFilePresent:DWORD
  local pDescription:PSTRING, dIndex:DWORD, pGroup:PKEYWORDGROUP
  local pLastChar:PCHR, dLength:DWORD, dFlags:DWORD, hDC:HDC
  local cFullFileName[1024]:CHR, cSectionName[50]:CHR, cItemName[20]:CHR, cItemBuffer[4096]:CHR

  SetObject xsi
  invoke GetFullPathName, pIniFileName, lengthof cFullFileName - 1, addr cFullFileName, NULL
  invoke FileExist, addr cFullFileName
  mov dIniFilePresent, eax
  .if eax == FALSE
    invoke MsgBox, 0, addr cWarnNoConf, addr cWarning, MB_OK or MB_ICONWARNING
  .endif

  invoke GetPrivateProfileString, addr cIniSectIdentification, addr cVersion, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
  .if dIniFilePresent != FALSE
    ;Check Version
    invoke GetVersionFromString, addr cItemBuffer
    .if eax != [xsi].dReqMainVersion || ecx < [xsi].dMinSubVersion
      invoke MsgBox, 0, addr cWarnOldConf, addr cWarning, MB_OK or MB_ICONWARNING
    .endif
  .endif

  ;Load GUI language
  invoke GetPrivateProfileString, addr cIniSectGUI, addr cLanguage, $OfsCStr("EN"), \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
  DoesStringMatch? cItemBuffer, <EN>
  .if ZERO?
    mov [xsi].dLangID, IDLANG_ENGLISH
  .else
    DoesStringMatch? cItemBuffer, <DE>
    .if ZERO?
      mov [xsi].dLangID, IDLANG_GERMAN
    .else
      DoesStringMatch? cItemBuffer, <IT>
      .if ZERO?
        mov [xsi].dLangID, IDLANG_ITALIAN
      .else
        DoesStringMatch? cItemBuffer, <RU>
        .if ZERO?
          mov [xsi].dLangID, IDLANG_RUSSIAN
        .else
          DoesStringMatch? cItemBuffer, <ES>
          .if ZERO?
            mov [xsi].dLangID, IDLANG_SPANISH
          .endif
        .endif
      .endif
    .endif
  .endif

  ;Load default editor type for the new button
  invoke GetPrivateProfileString, addr cIniSectGUI, $OfsCStr("NewDefault"), $OfsCStr("ASM"), \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
  DoesStringMatch? cItemBuffer, <RES>
  .if ZERO?
    mov [xsi].dNewDefault, ECT_RES
  .else
    DoesStringMatch? cItemBuffer, <TXT>
    .if ZERO?
      mov [xsi].dNewDefault, ECT_TXT
    .else
      mov [xsi].dNewDefault, ECT_ASM
    .endif
  .endif

  ;Load file types
  mov dIndex, 0
  .while TRUE
    inc dIndex
    lea xdi, cItemName
    WriteF xdi, "FT¦UD", dIndex
    invoke GetPrivateProfileString, $OfsCStr("File Types"), addr cItemName, NULL, \
                                    addr cItemBuffer, lengthof cItemBuffer, addr cFullFileName
    .break .if eax == 0
    invoke StrLScan, addr cItemBuffer, ','
    xor edi, edi
    .if xax != NULL
      lea xdi, [xax + sizeof(CHR)]
      m2z CHR ptr [xax]
    .endif
    .if xdi != NULL
      invoke StrLScan, xdi, ','
      xor ebx, ebx
      .if xax != NULL
        lea xbx, [xax + sizeof(CHR)]
        m2z CHR ptr [xax]
      .endif
      .if xbx != NULL
        DoesStringMatch? [xdi], <ASM>
        .if ZERO?
          mov edi, ECT_ASM
        .else
          DoesStringMatch? [xdi], <RES>
          .if ZERO?
            mov edi, ECT_RES
          .else
            mov edi, ECT_TXT
          .endif
        .endif

        DoesStringMatch? [xbx], <ANSI>
        .if ZERO?
          mov ebx, EFF_ANSI
        .else
          DoesStringMatch? [xbx], <UTF8>
          .if ZERO?
            mov ebx, EFF_UTF8
          .else
            DoesStringMatch? [xbx], <UTF8BOM>
            .if ZERO?
              mov ebx, EFF_UTF8BOM
            .else
              DoesStringMatch? [xbx], <UTF16BOM>
              .if ZERO?
                mov ebx, EFF_UTF16BOM
              .else
                mov ebx, EFF_UNKNOWN
              .endif
            .endif
          .endif
        .endif

        OCall [xsi].FileTypes::FileTypeCollection.Insert, addr cItemBuffer, edi, ebx

      .endif
    .endif
  .endw

  ;Load Editor resources
  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)
  OCall [xsi].AsmEditorResources::EditorResources.ConfigLoad, addr cFullFileName, $OfsCStr("ASM"), hDC
  OCall [xsi].ResEditorResources::EditorResources.ConfigLoad, addr cFullFileName, $OfsCStr("RES"), hDC
  OCall [xsi].TxtEditorResources::EditorResources.ConfigLoad, addr cFullFileName, $OfsCStr("TXT"), hDC
  invoke ReleaseDC, [xsi].hWnd, hDC

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ConfigSave
; Purpose:    Save the application configuration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Application.ConfigSave
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
  .if [xsi].hDevMode != 0
    invoke GlobalFree, [xsi].hDevMode
  .endif
  .if [xsi].hDevNames != 0
    invoke GlobalFree, [xsi].hDevNames
  .endif

  ;Destroy resources
  OCall [xsi].SharedResources::EditorSharedResources.Done
  OCall [xsi].AsmEditorResources::EditorResources.Done
  OCall [xsi].ResEditorResources::EditorResources.Done
  OCall [xsi].TxtEditorResources::EditorResources.Done

  OCall [xsi].FileTypes::FileTypeCollection.Done

  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].RBar::Rebar.Done
  OCall [xsi].SBar::Statusbar.Done
  OCall [xsi].TbFile::Toolbar.Done
  OCall [xsi].TbWindow::Toolbar.Done
  OCall [xsi].PropWnd::PropertiesWnd.Done
  OCall [xsi].ProjWnd::ProjectWnd.ConfigSave
  OCall [xsi].ProjWnd::ProjectWnd.Done
  OCall [xsi].SplitterVert::Splitter.Done
  OCall [xsi].SplitterHorz::Splitter.Done
  OCall [xsi].Menu::XMenu.Done

  OCall [xsi].FindDlg::DialogModeless.Done

  invoke StrDispose, [xsi].pProjFileName

  Destroy [xsi].pClientWnd
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xdi xsi
;  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD, pSBHelp:POINTER
;  local hDC:HDC, WndRect:RECT, WndPos:POINT, WndSize:POINT
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
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")               ;00
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD")         ;01

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")          ;02
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_OPEN")         ;03
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SAVE")         ;04
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SAVEAS")       ;05
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SAVEALL")      ;06
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CLOSE")        ;07
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CLOSEALL")     ;08
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PAGESETUP")    ;09
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PRINTERSETUP") ;10
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PRINT")        ;11
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PIN")          ;12
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")        ;13
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")         ;14

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_CUT")          ;15
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_COPY")         ;16
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_PASTE")        ;17
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_CLEAR")        ;18
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_FIND")         ;19

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CASCADE")    ;20
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_HOR")   ;21
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_VER")   ;22
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ARRANGE")    ;23
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_NEXT")       ;24
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_PREV")       ;25
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ZOOMIN")     ;26
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ZOOMOUT")    ;27

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")         ;28
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")        ;29

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_UNDO")         ;30
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_REDO")         ;31

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_INDENT")       ;32
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_UNINDENT")     ;33

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_COMMENT")      ;34
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_UNCOMMENT")    ;35

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CONTEXT_SAVE")      ;36
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CONTEXT_LOAD")      ;37

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("HOTKEYS"))

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))
  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 3)
  mov [xsi].hMenuContextEditor, $invoke(LoadMenu, hInstance, $OfsCStr("CONTEXTMENU_EDITOR"))

;  ;Create the MDI Frame window in the center of the monitor
;  mov WndSize.x, 1600
;  mov WndSize.y, 800
;  invoke CenterWindowOnPrimaryDisplay, addr WndPos, addr WndSize
;
;  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
;                         offset szApplicationClassName, offset szAppTitle, \
;                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
;                         WndPos.x, WndPos.y, WndSize.x, WndSize.y, \
;                         NULL, [xsi].hMenuInit, hInstance, pSelf

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset szApplicationClassName, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,\
                         NULL, [xsi].hMenuInit, hInstance, pSelf

  ;Create and Initialize Client window
  mov [xsi].pClientWnd, $New(ClientWnd)
  OCall xax::ClientWnd.Init, xsi
  mov xax, [xsi].pClientWnd
  mov xdi, [xax].$Obj(ClientWnd).hWnd

  OCall [xsi].FileTypes::FileTypeCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY

  ;Create Editor (shared)Resources
  OCall [xsi].SharedResources::EditorSharedResources.Init, xsi
  OCall [xsi].AsmEditorResources::EditorResources.Init, xsi, addr [xsi].SharedResources
  OCall [xsi].ResEditorResources::EditorResources.Init, xsi, addr [xsi].SharedResources
  OCall [xsi].TxtEditorResources::EditorResources.Init, xsi, addr [xsi].SharedResources

  OCall xsi.ConfigLoad, $OfsCStr("ADE.ini")

  ;Create and initialize XMenu
  mov xbx, $MethodAddr(Application.StatusbarHelp)
  OCall [xsi].Menu::XMenu.Init, xsi, [xsi].hWnd, xdi, [xsi].hMenuChildWnd, \
                                addr [xsi].IconImageList, xbx, IDLANG_ENGLISH

  OCall xsi.ChangeLanguage, [xsi].dLangID

  OCall [xsi].FindDlg::FindDialog.Init, xsi
  OCall [xsi].FindDlg::FindDialog.Show
  invoke ShowWindow, [xsi].FindDlg.hWnd, SW_HIDE

  lea xbx, [xsi].TbEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_DELETE, FALSE

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
; Method:     Application.ManageGuiCmds
; Purpose:    Enable/Disable menu items and toolbar buttons.
; Arguments:  Arg1: Active focused window handle.
; Return:     Nothing.

CheckEditorDirty proc uses xdi hWnd:HWND, lParam:XWORD
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xdi, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID
      .ifBitSet [xdi].$Obj(Editor).dFlags, EIF_DIRTY
        mov xcx, lParam
        mov DWORD ptr [xcx], TRUE
        xor eax, eax
        ret
      .endif
    .endif
  .endif
  mov eax, TRUE
  ret
CheckEditorDirty endp

Method Application.ManageGuiCmds, uses xbx xdi xsi, hActiveWnd:HWND
  local dApplDirty:DWORD, dEditorDirty:DWORD

  SetObject xsi
  invoke SendMessage, hActiveWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xdi, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID ;----------------------------------------------
      lea xbx, [xsi].TbFile
      xor eax, eax
      test [xdi].$Obj(Editor).dFlags, EIF_DIRTY
      setnz al
      mov dEditorDirty, eax
      mov dApplDirty, eax
      .if ZERO?
        mov xcx, [xsi].pClientWnd
        invoke EnumChildWindows, [xcx].$Obj(ClientWnd).hWnd, addr CheckEditorDirty, addr dApplDirty
      .endif

      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVE, dEditorDirty
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEAS, dEditorDirty
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEALL, dApplDirty
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSE, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSEALL, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_PRINT, TRUE

      lea xbx, [xsi].TbEdit
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_FIND, TRUE

      lea xbx, [xsi].TbWindow
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_CASCADE, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_TILE_HOR, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_TILE_VER, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ARRANGE, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMIN, TRUE
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMOUT, TRUE

      mov xbx, $invoke(GetMenu, [xsi].hWnd)               ;Get the current menu
      .if dEditorDirty == FALSE
        mov edi, MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
      .else
        mov edi, MF_BYCOMMAND or MF_ENABLED
      .endif
      invoke EnableMenuItem, xbx, IDM_FILE_SAVE,          edi
      invoke EnableMenuItem, xbx, IDM_FILE_SAVEAS,        edi
      .if dApplDirty == FALSE
        mov edi, MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
      .else
        mov edi, MF_BYCOMMAND or MF_ENABLED
      .endif
      invoke EnableMenuItem, xbx, IDM_FILE_SAVEALL,       edi
      invoke EnableMenuItem, xbx, IDM_FILE_CLOSE,         MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_FILE_CLOSEALL,      MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_FILE_PAGESETUP,     MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_FILE_PRINTERSETUP,  MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_FILE_PRINT,         MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_EDIT_SELECTALL,     MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_EDIT_FIND,          MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_WINDOW_ZOOMIN,      MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_WINDOW_ZOOMOUT,     MF_BYCOMMAND or MF_ENABLED

      mov xbx, [xsi].hMenuContextEditor
      invoke EnableMenuItem, xbx, IDM_EDIT_SELECTALL,     MF_BYCOMMAND or MF_ENABLED
      invoke EnableMenuItem, xbx, IDM_EDIT_FIND,          MF_BYCOMMAND or MF_ENABLED
      ExitMethod
    .endif
  .endif

  lea xbx, [xsi].TbFile
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVE, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEAS, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEALL, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSE, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSEALL, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_PRINT, FALSE

  lea xbx, [xsi].TbEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_FIND, FALSE

  lea xbx, [xsi].TbWindow
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_CASCADE, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_TILE_HOR, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_TILE_VER, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ARRANGE, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMIN, FALSE
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMOUT, FALSE

  mov xbx, $invoke(GetMenu, [xsi].hWnd)               ;Get the current menu
  invoke EnableMenuItem, xbx, IDM_FILE_SAVE,          MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_FILE_SAVEAS,        MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_FILE_SAVEALL,       MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_FILE_CLOSE,         MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_FILE_CLOSEALL,      MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_FILE_PAGESETUP,     MF_BYCOMMAND or MF_ENABLED
  invoke EnableMenuItem, xbx, IDM_FILE_PRINTERSETUP,  MF_BYCOMMAND or MF_ENABLED
  invoke EnableMenuItem, xbx, IDM_FILE_PRINT,         MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_EDIT_SELECTALL,     MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_EDIT_FIND,          MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_WINDOW_ZOOMIN,      MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  invoke EnableMenuItem, xbx, IDM_WINDOW_ZOOMOUT,     MF_BYCOMMAND or MF_DISABLED or MF_GRAYED

  mov xbx, [xsi].hMenuContextEditor
  invoke EnableMenuItem, xbx, IDM_EDIT_SELECTALL,     MF_BYCOMMAND or MF_DISABLED
  invoke EnableMenuItem, xbx, IDM_EDIT_FIND,          MF_BYCOMMAND or MF_DISABLED
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE and WM_QUERYENDSESSION message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

align ALIGN_CODE
CloseEditor proc uses xbx hWnd:HWND, lParam:XWORD
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xbx, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID
      OCall xbx::Editor.Save
      .if eax == IDCANCEL
        mov xcx, lParam
        .if xcx != NULL
          mov DWORD ptr [xcx], TRUE
        .endif
        mov eax, FALSE                                  ;Stop enumeration
        ret
      .endif
      invoke DestroyWindow, [xbx].$Obj(Editor).hWnd
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
CloseEditor endp

Method Application.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD, dCancel:DWORD

  ANNOTATION use:wParam lParam

  SetObject xsi
  mov dMsg, eax                                         ;Save windows message passed in eax
  mov dCancel, FALSE
  mov xbx, [xsi].pClientWnd
  invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset CloseEditor, addr dCancel
  .if dCancel != FALSE
    ExitMethod
  .endif
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, dMsg, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

align ALIGN_CODE
SaveEditor proc uses xbx hWnd:HWND, lParam:XWORD
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xbx, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID
      OCall xbx::Editor.Save
      .if eax == IDCANCEL
        mov eax, FALSE                                  ;Stop enumeration
        ret
      .endif
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
SaveEditor endp

Method Application.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, AboutDlg:$Obj(DialogAbout), SetupDlg:$Obj(SetupDialog)
  local pIFODlg:POINTER, pIFileDialog2:POINTER, cBuffer[MAX_PATH]:CHR
  local PageSetup:PAGESETUPDLG
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pDisplayName:POINTER

  ANNOTATION use:wParam lParam

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd
  .if ax == IDM_FILE_NEW                              ;Create a new default editor instance
    mov xdi, $New(Editor)
    .if xdi != NULL
      .if [xsi].dNewDefault == ECT_RES
        lea xbx, [xsi].ResEditorResources
      .elseif [xsi].dNewDefault == ECT_TXT
        lea xbx, [xsi].TxtEditorResources
      .else
        lea xbx, [xsi].AsmEditorResources
      .endif
      OCall xdi::Editor.Init, [xsi].pClientWnd, xbx, NULL
      .if eax == FALSE
        Kill xdi
      .endif
    .endif
    xor eax, eax
  .elseif ax == IDM_NEW_MASM                            ;Create a new MASM editor instance
    mov xdi, $New(Editor)
    .if xdi != NULL
      OCall xdi::Editor.Init, [xsi].pClientWnd, addr [xsi].AsmEditorResources, NULL
      .if eax == FALSE
        Kill xdi
      .endif
    .endif
    xor eax, eax
  .elseif ax == IDM_NEW_RESOURCE                        ;Create a new Resource editor instance
    mov xdi, $New(Editor)
    .if xdi != NULL
      OCall xdi::Editor.Init, [xsi].pClientWnd, addr [xsi].ResEditorResources, NULL
      .if eax == FALSE
        Kill xdi
      .endif
    .endif
    xor eax, eax
  .elseif ax == IDM_NEW_TEXT                            ;Create a new Text editor instance
    mov xdi, $New(Editor)
    .if xdi != NULL
      OCall xdi::Editor.Init, [xsi].pClientWnd, addr [xsi].TxtEditorResources, NULL
      .if eax == FALSE
        Kill xdi
      .endif
    .endif
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
          OCall [xsi].FileTypes::FileTypeCollection.GetContentType, pDisplayName
          .if eax == ECT_ASM
            lea xax, [xsi].AsmEditorResources
          .elseif eax == ECT_RES
            lea xax, [xsi].ResEditorResources
          .else
            lea xax, [xsi].TxtEditorResources
          .endif
          OCall xdi::Editor.Init, [xsi].pClientWnd, xax, pDisplayName
          .if eax == FALSE
            Kill xdi
          .endif
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
          OCall xbx::Editor.SaveTo, [xbx].$Obj(Editor).pFullFileName
        .endif
      .endif
    .endif
    xor eax, eax
  .elseif ax == IDM_FILE_SAVEAS
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
  .elseif ax == IDM_FILE_SAVEALL
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset SaveEditor, NULL
    xor eax, eax
  .elseif (ax == IDM_FILE_CLOSE) || (ax == SC_CLOSE)    ;Close the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0
    xor eax, eax
  .elseif ax == IDM_FILE_CLOSEALL                     ;Attempt to close all windows
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset CloseEnumProc, 0
    xor eax, eax
  .elseif ax == IDM_FILE_PAGESETUP
    mov PageSetup.lStructSize, sizeof(PageSetup)
    m2m PageSetup.hwndOwner, [xsi].hWnd, xax
    m2m PageSetup.hDevMode, [xsi].hDevMode, xcx
    m2m PageSetup.hDevNames, [xsi].hDevNames, xax
    mov PageSetup.Flags, PSD_INHUNDREDTHSOFMILLIMETERS or PSD_MARGINS or PSD_MINMARGINS
    m2z PageSetup.ptPaperSize.x
    m2z PageSetup.ptPaperSize.y
    m2z PageSetup.rtMinMargin.left
    m2z PageSetup.rtMinMargin.top
    m2z PageSetup.rtMinMargin.right
    m2z PageSetup.rtMinMargin.bottom
    s2s PageSetup.rtMargin, [xsi].PrintMargin, xax, xcx
    m2m PageSetup.hInstance, hInstance, xax
    m2z PageSetup.lCustData
    m2z PageSetup.lpfnPageSetupHook
    m2z PageSetup.lpfnPagePaintHook
    m2z PageSetup.lpPageSetupTemplateName
    m2z PageSetup.hPageSetupTemplate
    .if $invoke(PageSetupDlg, addr PageSetup)
      m2m [xsi].hDevMode, PageSetup.hDevMode, xax
      m2m [xsi].hDevNames, PageSetup.hDevNames, xcx
      s2s [xsi].PrintMargin, PageSetup.rtMargin, xax, xcx
    .endif
    xor eax, eax
  .elseif ax == IDM_FILE_PRINT
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::ChildWnd.Print                         ;Polymorphic call
    .endif
    xor eax, eax
  .elseif ax == IDM_FILE_PIN
    lea xdi, [xsi].TbFile
    invoke SendMessage, [xdi].$Obj(Toolbar).hWnd, TB_GETSTATE, IDM_FILE_PIN, 0
    .ifBitSet eax, TBSTATE_CHECKED
      BitClr eax, TBSTATE_CHECKED
      invoke SendMessage, [xdi].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
      invoke SetWindowPos, [xsi].hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
    .else
      BitSet eax, TBSTATE_CHECKED
      invoke SendMessage, [xdi].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
      invoke SetWindowPos, [xsi].hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
    .endif
    xor eax, eax
  .elseif ax == IDM_FILE_SETUP
    New SetupDlg::SetupDialog
    OCall SetupDlg::SetupDialog.Init, xsi, [xsi].hWnd
    OCall SetupDlg::SetupDialog.Show
    OCall SetupDlg::SetupDialog.Done
    xor eax, eax
  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax
  .elseif ax == IDM_FILE_BREAK
    int 3
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

  .elseif ax == IDM_EDIT_COPY
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::ChildWnd.ClpBrdCopy                 ;Polymorphic call
    .endif
    xor eax, eax
  .elseif ax == IDM_EDIT_CUT
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::ChildWnd.ClpBrdCut                  ;Polymorphic call
    .endif
    xor eax, eax
  .elseif ax == IDM_EDIT_PASTE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::ChildWnd.ClpBrdPaste                ;Polymorphic call
    .endif
    xor eax, eax
  .elseif ax == IDM_EDIT_DELETE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::ChildWnd.ClpBrdDelete                ;Polymorphic call
    .endif
    xor eax, eax
  .elseif ax == IDM_EDIT_SELECTALL
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
      mov xdi, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
      invoke GetObjectID, xdi
      .if eax == ADE_EditorID
        OCall xdi::Editor.SelectAll
        xor eax, eax
      .endif
    .endif
    xor eax, eax
  .elseif ax == IDM_EDIT_FIND
    invoke ShowWindow, [xsi].FindDlg.hWnd, SW_SHOW
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

  .elseif ax == IDM_WINDOW_ZOOMIN
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
     invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov xdi, xax
        invoke GetObjectID, xax
        .if eax == ADE_EditorID
          mov xdi, [xdi].$Obj(Editor).pResources
          invoke MulDiv, [xdi].$Obj(EditorResources).dZoomFactor, 11, 10
          OCall xdi::EditorResources.Zoom, eax
          .if eax != FALSE
            OCall xbx::ClientWnd.UpdateEditors
          .endif
        .endif
      .endif
    .endif
    xor eax, eax
  .elseif ax == IDM_WINDOW_ZOOMOUT
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov xdi, xax
        invoke GetObjectID, xax
        .if eax == ADE_EditorID
          mov xdi, [xdi].$Obj(Editor).pResources
          invoke MulDiv, [xdi].$Obj(EditorResources).dZoomFactor, 10, 11
          OCall xdi::EditorResources.Zoom, eax
          .if eax != FALSE
            OCall xbx::ClientWnd.UpdateEditors
          .endif
        .endif
      .endif
    .endif
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
  OCall [xsi].ProjWnd::ProjectWnd.ConfigLoad, $OfsCStr("MyProject.ini")

  ;Initialize properties window
  OCall [xsi].PropWnd::PropertiesWnd.Init, xsi, [xsi].hWnd

  ;Initialize splitters
  OCall [xsi].SplitterVert::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_VERTICAL, 200, 30, 50
  OCall [xsi].SplitterHorz::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_HORIZONTAL, 450, 55, 75

  ;Initialize statusbar
  OCall [xsi].SBar::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  ;Create rebar and toolbars
  OCall [xsi].RBar::Rebar.Init, xsi, [xsi].hWnd

  OCall [xsi].TbWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbWindow::Toolbar.GetHeight))
  OCall [xsi].TbWindow::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbWindow.hWnd, eax, ebx

  OCall [xsi].TbEdit::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarEdit, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbEdit::Toolbar.GetHeight))
  OCall [xsi].TbEdit::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbEdit.hWnd, eax, ebx

  OCall [xsi].TbFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbFile::Toolbar.GetHeight))
  OCall [xsi].TbFile::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbFile.hWnd, eax, ebx

  OCall xsi.ManageGuiCmds, 0                            ;Disable toolbar buttons

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
  .if [xsi].hMenuContextEditor
    invoke DestroyMenu, [xsi].hMenuContextEditor
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
; Method:     Application.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method Application.OnNotify, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local BtnRect:RECT, hFileMenu:HMENU, hDropDownMenu:HMENU, TPM:TPMPARAMS

  ANNOTATION use:wParam lParam

;  DbgText "Application.OnNotify"
  SetObject xsi
  mov xbx, lParam
  .if [xbx].NMHDR.code == TBN_DROPDOWN && [xbx].NMTOOLBAR.iItem == IDM_FILE_NEW
    ;Get the coordinates of the button.
    DbgDec [xbx].NMTOOLBAR.iItem
    invoke SendMessage, [xbx].NMHDR.hwndFrom, TB_GETRECT, [xbx].NMTOOLBAR.iItem, addr BtnRect

    ;Convert to screen coordinates.
    invoke MapWindowPoints, [xbx].NMHDR.hwndFrom, HWND_DESKTOP, addr BtnRect, 2

    ;Get the menu.
    mov hFileMenu, $invoke(GetSubMenu, [xsi].hMenuInit, 0)
    mov hDropDownMenu, $invoke(GetSubMenu, hFileMenu, 1)

    ;Set up the pop-up menu.
    ;In case the toolbar is too close to the bottom of the screen,
    ;set rcExclude equal to the button rectangle and the menu will appear above
    ;the button, and not below it.
    mov TPM.cbSize, sizeof(TPM)
    s2s TPM.rcExclude, BtnRect, xmm0, xmm1, xax, xcx

    ;Show the menu and wait for input.
    ;If the user selects an item, its WM_COMMAND is sent.
    invoke TrackPopupMenuEx, hDropDownMenu, TPM_LEFTALIGN or TPM_LEFTBUTTON or TPM_VERTICAL, \
                             BtnRect.left, BtnRect.bottom, [xsi].hWnd, addr TPM
  .endif
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
    invoke GetWindowRect, [xsi].SBar.hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xsi].SBar.hWnd, 0, dHeight, dWidth, eax, FALSE
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
  OCall [xcx].SBar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
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
