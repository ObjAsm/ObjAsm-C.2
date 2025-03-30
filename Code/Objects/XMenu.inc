; ==================================================================================================
; Title:      XMenu.inc
; Author:     G. Friedrich.
; Version:    C.1.2
; Purpose:    ObjAsm support of extended menu objects.
; Links:      - http://www.microsoft.com/msj/0198/coolmenu.aspx
; Note:       Required files:
;              - Strings.inc
;              - DlgTmpl.inc
;              - DialogModalIndirect.inc
;             This object requires unique MenuItemIDs to work properly!
;             NEVER use a command ID = 0! (The OS has problems with the first MenuBar item).
;             Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, December 2020
;               - Minor changes to avaoid this probem http://masm32.com/board/index.php?topic=8928.0
;             Version C.1.2, November 2023
;               - Flashing test added to Done method.
; ==================================================================================================


MENU_TYPE_MAINBAR     equ    0
MENU_TYPE_NORMAL      equ    1
MENU_TYPE_SUBMENU     equ    2
MENU_TYPE_CHECK       equ    3
MENU_TYPE_RADIO       equ    4
MENU_TYPE_SEPARATOR   equ    5
MENU_TYPE_SIDEBAR     equ    6

NO_IMAGE              equ    -1

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XMdiMenu
; Purpose:    Implement the MDI menu items used by XMenu.
;             It is used to intercept some messages of the MDI client window to draw the child menu
;             items in the "Window" popup menu.

Object XMdiMenu, XMdiMenuID, MsgInterceptor
  RedefineMethod    Init,               POINTER, HWND, HMENU, PSTRING
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnMdiSetMenu,       WM_MDISETMENU

  DefineVariable    hWindowMenu,        HMENU,      0                 ;Window menu HANDLE
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XMenuSelectDlg
; Purpose:    Implement MDI selection modal dialog used by XMenu.

Object XMenuSelectDlg, XMenuSelectDlgID, DialogModalIndirect
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  DefineVariable    hListBox,           HWND,       0
  DefineVariable    hActiveWnd,         HWND,       0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XMenuItem
; Purpose:    Implement a menu item used internally by the XMenu object.

Object XMenuItem, XMenuItemID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HMENU, DWORD, DWORD, \
                                        PSTRING, PSTRING, PSTRING, DWORD

  DefineVariable    dID,                DWORD,      0                 ;Menu item ID
  DefineVariable    hMenu,              HMENU,      0                 ;Parent Menu handle
  DefineVariable    dType,              DWORD,      MENU_TYPE_NORMAL  ;Menu item type
  DefineVariable    dIconIndex,         DWORD,      NO_IMAGE          ;Icon index into parent's ImgList
  DefineVariable    pMenuStr,           PSTRING,    NULL              ;Menu item text without shortcut
  DefineVariable    pSCutStr,           PSTRING,    NULL              ;Shortcut text
  DefineVariable    pHelpStr,           PSTRING,    NULL              ;Menu item help text
  DefineVariable    dMaxTextWidth,      DWORD,      0                 ;Max text width of all items in curr. submenu
  DefineVariable    dMaxSCutWidth,      DWORD,      0                 ;Max SCut width of all items in curr. submenu
  DefineVariable    dHeight,            DWORD,      0                 ;Menu item height
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

MENU_CX_WIN             equ   13      ;Windows automatically adds this value to the width.
MENU_CX_GAP             equ   1       ;Number of pixels between icon/button and text.
MENU_BAR_LEFT_MARGIN    equ   1       ;Menubar item left margin to start with the text.
MENU_BAR_RIGHT_MARGIN   equ   1       ;Menubar item right margin after the text to the right border.
MENU_POPUP_LEFT_MARGIN  equ   2       ;Popup item left margin to start with the text.
MENU_POPUP_RIGHT_MARGIN equ   5       ;Popup item right margin after the text to the right border.
MENU_CX_SCUT            equ   20      ;Minimal number of pixels between text and shortcut.
MENU_CX_SEP_MARGIN      equ   1       ;Number of pixels between border and separator start.
MENU_SIDEBAR_WIDTH      equ   18      ;Sidebar width.
MENU_ICON_BORDER        equ   2       ;Number of pixels between border and icon.
MENU_CHAR_SIDEBAR       equ   "*"     ;Character that identifies a sidebar.
MENU_CHAR_LITERAL       equ   "|"     ;Literal marker character.
MENU_CHAR_RESOURCE      equ   "$"     ;Resource redirector character.
MENU_CHAR_RADIO         equ   "o"     ;Character that identifies a radiobutton.
MENU_CHAR_CHECK         equ   "#"     ;Character that identifies a checkbox.
MENU_CHAR_SHORTCUT      equ   "~"     ;Separates the shortcut from normal text. Windows uses char 08.
MENU_CHAR_SEPARATOR     equ   "-"     ;Character that identifies a separator line.
MENU_WINDOW_LIST        equ   50010   ;MDI menu separator text.
MENU_WINDOW_MORE        equ   50009   ;MDI menu item (...) that shows a dlgbox to select a child.

HelpCallbackPto typedef proto :POINTER, :PSTRING        ;pSelf, pHelpStr
PDRAWITEMSTRUCT typedef ptr DRAWITEMSTRUCT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XMenu
; Purpose:    Implement a menu object with extended drawing capabilities.
;             The default drawing is a icon followed by the menu text and an optional shortcut.
;             If needed, a different layout can be achieved redefining the following dynamic methods
;               - DrawMenuBarBkgnd
;               - DrawMenuBarIcon
;               - DrawMenuBarText
;               - DrawPopupBkgnd
;               - DrawPopupCheck
;               - DrawPopupIcon
;               - DrawPopupSeparator
;               - DrawPopupText
;             It is possible to change the language by calling the ChangeLanguage method.
;             This object uses a MaskedImageList that holds all displayed icons and a res. string
;             table. The menu item strings in this table should be organized in language groups, so
;             that adding an offset to a string ID, the corresponding string in another language can
;             be obtained.
;             The resource menu item should have the following syntax:
;
;             Icon Index Marker Text or String Index [ Marker Help text or String Index ]
;
;             The marker can be one of the following characters:
;               |    Literal marker character. The following text is treated in literal form.
;               $    Resource redirector character. The following text is treated as an index into
;                    the string resource.
;
; Example:
;
;    MDIMENUCHILD MENUEX DISCARDABLE
;    begin
;      POPUP "$00",          IDM_FILE,               MFT_STRING, MFS_ENABLED
;      begin
;        MENUITEM "03$01",   IDM_FILE_NEW,           MFT_STRING, MFS_ENABLED
;        MENUITEM "04$02",   IDM_FILE_CLOSE,         MFT_STRING, MFS_ENABLED
;        MENUITEM "-$03",    IDM_FILE_SEPARATOR_1,   MFT_STRING, MFS_ENABLED
;        MENUITEM "05$04",   IDM_FILE_EXIT,          MFT_STRING, MFS_ENABLED
;      end
;    end
;
;    STRINGTABLE
;    IDLANG_ENGLISH + 00, "&File|File commands"
;    IDLANG_ENGLISH + 01, "&New~Ctrl+N|Creates a new window"
;    IDLANG_ENGLISH + 02, "&Close~Ctrl+F4|Closes the active window"
;    IDLANG_ENGLISH + 03, "Application"
;    IDLANG_ENGLISH + 04, "E&xit...~Ctrl+X|Exits application"
;
;
;          If the resource string contains a literal marker, the following text is used to display
;          a help line, e.g.: in the Statusbar.
;          XMenu works internally with XMdiMenu and XMenuItem objects, both defined in XMenu.inc
;
; Note:
;     - This object needs UNIQUE menu item IDs to work properly. Even separators require unique IDs!
;     - The "~" character is used in a menu string to separate the text from the shortcut
;     - Some characters used in place of the Icon index cause special behaviours:
;         "-" displays a menu separator
;         "o" displays a radiobutton
;         "#" displays a checkbox
;         "*" displays a sidebar bitmap, whose resource ID is placed as the help text.

Object XMenu, XMenuID, MsgInterceptor
  VirtualMethod     ChangeLanguage,     HMENU, DWORD    ;Menu handle, new LangID
  VirtualMethod     Convert,            HMENU, DWORD    ;Menu handle, main menu flag
  RedefineMethod    Done
  DynamicMethod     DrawMenuBarBkgnd,   PDRAWITEMSTRUCT
  DynamicMethod     DrawMenuBarIcon,    PDRAWITEMSTRUCT
  DynamicMethod     DrawMenuBarText,    PDRAWITEMSTRUCT
  DynamicMethod     DrawPopupBkgnd,     PDRAWITEMSTRUCT
  DynamicMethod     DrawPopupCheck,     PDRAWITEMSTRUCT
  DynamicMethod     DrawPopupIcon,      PDRAWITEMSTRUCT
  DynamicMethod     DrawPopupRadio,     PDRAWITEMSTRUCT
  DynamicMethod     DrawPopupSeparator, PDRAWITEMSTRUCT
  DynamicMethod     DrawPopupText,      PDRAWITEMSTRUCT
  DynamicMethod     DrawSidebarBkgnd,   PDRAWITEMSTRUCT
  DynamicMethod     DrawSidebarText,    PDRAWITEMSTRUCT
  VirtualMethod     FlashMenuBar,       RGBQUAD, DWORD
  RedefineMethod    Init,               POINTER, HWND, HWND, HMENU, \
                                        $ObjPtr(MaskedImageList), POINTER, DWORD
  VirtualMethod     IsMenuBarSubMenu,   HMENU
  VirtualMethod     SendHelp,           PSTRING
  VirtualMethod     SetMenuBarBkColor,  RGBQUAD
  VirtualMethod     UpdateFonts
  VirtualMethod     WindowMenuCreate,   HMENU
  VirtualMethod     WindowMenuRemove,   HMENU
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnDrawItem,         WM_DRAWITEM
  VirtualEvent      OnInitMenuPopup,    WM_INITMENUPOPUP
  VirtualEvent      OnMeasureItem,      WM_MEASUREITEM
  VirtualEvent      OnMenuChar,         WM_MENUCHAR
  VirtualEvent      OnMenuSelect,       WM_MENUSELECT
  VirtualEvent      OnSettingChange,    WM_SETTINGCHANGE
  VirtualEvent      OnSysColorChange,   WM_SYSCOLORCHANGE

  DefineVariable    hMenu,              HMENU,      0
  DefineVariable    hMdiWindowMenu,     HMENU,      0
  DefineVariable    hMdiClientWnd,      HWND,       0
  DefineVariable    pHelpCallback,      POINTER,    NULL
  DefineVariable    hFontSep,           HFONT,      0
  DefineVariable    hFontTxtNorm,       HFONT,      0
  DefineVariable    hFontTxtBold,       HFONT,      0
  DefineVariable    MenuBarBkColor,     RGBQUAD,    {}
  DefineVariable    dLanguage,          DWORD,      0
  DefineVariable    ImageSize,          POINT,      {}
  DefineVariable    pImgList,           $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pXMdiMenu,          $ObjPtr(XMdiMenu),         NULL
  DefineVariable    dFlags,             DWORD,      0

  Embed     MenuItemColl,     Collection
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    XMenuItem implementation
; ==================================================================================================

XMENU_SELECTLISTBOX_ID  equ   100

XMF_FLASHING  equ   BIT00

.const
DIALOGEX XMENUSELECTION, 0, 0, 250, 250, 0, 2, \
              WS_CHILD or DS_MODALFRAME or DS_3DLOOK or DS_CENTER or DS_CENTERMOUSE or \
              WS_CAPTION or WS_SYSMENU or WS_POPUP or DS_SETFONT, 0, 0, \
              NULL, "Select a Window", "Segoe UI", 9

DEFPUSHBUTTON "OK", IDOK, 195,232,50,14, WS_TABSTOP
CONTROL       NULL, XMENU_SELECTLISTBOX_ID, "ListBox", \
              WS_TABSTOP or WS_VSCROLL or WS_HSCROLL or \
              LBS_NOTIFY or LBS_HASSTRINGS or LBS_SORT or LBS_NOINTEGRALHEIGHT, \
              2,2,246,226, WS_EX_STATICEDGE

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenuItem.Done
; Purpose:    Finalize XMenuItem object.
; Arguments:  None.
; Return:     Nothing.

Method XMenuItem.Done, uses xsi
  local MenuInfo:MENUITEMINFO

;  DbgText "XMenuItem.Done"
  SetObject xsi
  ;Brake menu link
  mov MenuInfo.cbSize, sizeof(MenuInfo)
  mov MenuInfo.fMask, MIIM_FTYPE
  invoke GetMenuItemInfo, [xsi].hMenu, [xsi].dID, MF_BYCOMMAND, addr MenuInfo
;  if DEBUGGING
;    .if eax == FALSE
;      DbgWarning "Error in XMenuItem.Done"
;      DbgStr [xsi].pMenuStr
;    .endif
;  endif

  .if eax != FALSE
    mov MenuInfo.fMask, MIIM_FTYPE or MIIM_DATA
    m2z MenuInfo.dwItemData                             ;Delete link to MenuItem
    BitClr MenuInfo.fType, (MFT_OWNERDRAW or MFT_MENUBARBREAK) ;Reset only these flags
    invoke SetMenuItemInfo, [xsi].hMenu, [xsi].dID, MF_BYCOMMAND, addr MenuInfo
  .endif

  ;Free item resources
  invoke StrDispose, [xsi].pMenuStr                     ;Dispose menu text
  invoke StrDispose, [xsi].pSCutStr                     ;Dispose shortcut text
  invoke StrDispose, [xsi].pHelpStr                     ;Dispose help text

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenuItem.Init
; Purpose:    Initialaize XMenu.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent menu handle.
;             Arg3: Control ID.
;             Arg4: Menuitem type.
;             Arg5: -> Menu text.
;             Arg6: -> Shortcut text.
;             Arg7: -> Help text.
;             Arg8: -> Source text.
;             Arg9: Image index into image list.
; Return:     Nothing.

Method XMenuItem.Init,, pOwner:POINTER, hMenu:HMENU, dID:DWORD, dType:DWORD, \
                        pMenuStr:PSTRING, pSCutStr:PSTRING, pHelpStr:PSTRING, \
                        dIconIndex:DWORD
;  DbgText "XMenuItem.Init"
  SetObject xcx
  m2m [xcx].hMenu, hMenu, xax                           ;Parent menu handle
  m2m [xcx].dID, dID, eax
  m2m [xcx].dType, dType, eax
  m2m [xcx].pMenuStr, pMenuStr, xax
  m2m [xcx].pSCutStr, pSCutStr, xax
  m2m [xcx].pHelpStr, pHelpStr, xax
  m2m [xcx].dIconIndex, dIconIndex, eax
  ACall xcx.Init, pOwner
MethodEnd



; ==================================================================================================
;    XMenu implementation
; ==================================================================================================

CStr szPropXMenu, "OAP_XMenu"                           ;Used for XMenu and XMdiMenu
if DEBUGGING
  CStr cResStrNotFound, "Resource string not found"
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.ChangeLanguage
; Purpose:    Setup XMenu for a new language.
; Arguments:  Arg1: Main menu handle.
;             Arg2: Language ID.
; Return:     Nothing.

Method XMenu.ChangeLanguage, uses xsi, hMenu:HMENU, dLanguage:DWORD
;  DbgText "XMenu.ChangeLanguage"
  SetObject xsi
  mov eax, dLanguage
  .if eax != [xsi].dLanguage
    mov [xsi].dLanguage, eax
    ;Restore original menu
    OCall [xsi].MenuItemColl::Collection.DisposeAll
    invoke SetMenu, [xsi].hWnd, [xsi].hMenu

    ;Convert main menu
    mrm [xsi].hMenu, hMenu, xax
    OCall xsi.Convert, xax, TRUE

    ;Convert Window menu
    .if [xsi].hMdiWindowMenu != 0
      OCall xsi.WindowMenuRemove, [xsi].hMdiWindowMenu
      OCall xsi.Convert, [xsi].hMdiWindowMenu, FALSE
    .endif
    invoke DrawMenuBar, [xsi].hWnd                      ;Redraw MenuBar
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.Convert
; Purpose:    Convert a menu to ownerdraw. For each menuitem a new XMenuItem is created and added to
;             an internal collection.
; Arguments:  Arg1: HANDLE of the menu to transform.
;             Arg2: MenuBar flag.
; Return:     Nothing.

Method XMenu.Convert, uses xbx xdi xsi, hMenu:HMENU, dIsMenuBar:DWORD
  local sdItemCount:SDWORD, sdItemIndex:SDWORD, MenuInfo:MENUITEMINFO, cBuffer[256]:CHR
  local dType:DWORD, dLiteral:DWORD, dIconIndex:DWORD, dResID:DWORD
  local pMenuStr:PSTRING, pSCutStr:PSTRING, pHelpStr:PSTRING
  local hDC:HDC, Rect:RECT, hPrevFont:HFONT, dMenubarBreak:DWORD
  local sdMaxRegTextWidth:SDWORD, sdMaxWndTextWidth:SDWORD, sdMaxSCutWidth:SDWORD
  local dTotalHeight:DWORD, dLineHeight:DWORD, pLiteral:POINTER, pChar:POINTER

;  DbgText "XMenu.Convert"
  SetObject xsi
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontTxtNorm)
  invoke GetMenuItemCount, hMenu                        ;If hMenu = NULL => returns -1
  mov sdItemCount, eax
  mov MenuInfo.cbSize, sizeof(MenuInfo)
  xor ebx, ebx
  dec ebx
  mov sdMaxRegTextWidth, ebx                            ;Set to -1
  mov sdMaxWndTextWidth, ebx                            ;Set to -1
  mov sdMaxSCutWidth, ebx                               ;Set to -1
  inc ebx
  mov dTotalHeight, ebx                                 ;Set total height to zero
  mov dMenubarBreak, ebx                                ;Reset counter
  mov sdItemIndex, ebx

  .while TRUE
    mov eax, sdItemIndex
    .break .if eax >= sdItemCount
    lea xdi, MenuInfo
    mov MenuInfo.dwTypeData, $addr(cBuffer)             ;Set -> cBuffer
    mov MenuInfo.fMask, MIIM_FTYPE or MIIM_STRING or MIIM_ID or MIIM_SUBMENU or MIIM_DATA or MIIM_BITMAP
    mov MenuInfo.cch, lengthof cBuffer                  ;Set length of cBuffer in each loop!
    invoke GetMenuItemInfo, hMenu, sdItemIndex, MF_BYPOSITION, xdi
    .if MenuInfo.cch != 0                               ;Skip items that can't be converted
      .if MenuInfo.dwItemData == NULL                   ;Check if menuitem wasn't prev. converted
        ;Determine position of first separator character
        invoke StrLScan, addr cBuffer, MENU_CHAR_LITERAL   ;Literal indicator char
        mov pLiteral, xax
        invoke StrLScan, addr cBuffer, MENU_CHAR_RESOURCE  ;Resource redirector char
        .if xax == NULL
          m2m pChar, pLiteral, xdx
        .else
          .if pLiteral != NULL
            mov pChar, $uMin(xax, pLiteral)
          .else
            mov pChar, xax
          .endif
        .endif

        mov dLiteral, TRUE
        .if pChar != NULL
          mov xax, pChar
          .if CHR ptr [xax] == MENU_CHAR_RESOURCE
            m2z dLiteral
          .endif
          m2z CHR ptr [xax]
        .endif

        ;Identify item type
        .if dIsMenuBar != FALSE
          mov dType, MENU_TYPE_MAINBAR
        .elseif MenuInfo.hSubMenu != 0
          mov dType, MENU_TYPE_SUBMENU
        .else
          .if pChar == NULL
             mov dType, MENU_TYPE_NORMAL
          .else
            lea xbx, cBuffer
            invoke StrLTrim, xbx, xbx
            mov $SubReg(xax, sizeof(CHR)), [xbx]
            .if $SubReg(xax, sizeof(CHR)) == MENU_CHAR_CHECK
              mov dType, MENU_TYPE_CHECK
            .elseif $SubReg(xax, sizeof(CHR)) == MENU_CHAR_RADIO
              mov dType, MENU_TYPE_RADIO
            .elseif $SubReg(xax, sizeof(CHR)) == MENU_CHAR_SEPARATOR
              mov dType, MENU_TYPE_SEPARATOR
            .elseif $SubReg(xax, sizeof(CHR)) == MENU_CHAR_SIDEBAR
              mov dType, MENU_TYPE_SIDEBAR
              inc dMenubarBreak
            .else
              mov dType, MENU_TYPE_NORMAL
            .endif
          .endif
        .endif

        ;Extract icon index
        mov dIconIndex, NO_IMAGE
        .if (pChar != NULL) && ((dType == MENU_TYPE_MAINBAR) || \
            (dType == MENU_TYPE_NORMAL) || (dType == MENU_TYPE_SUBMENU))
          .if $invoke(StrLength, addr cBuffer) != 0
            invoke dec2dword, addr cBuffer
            mov dIconIndex, eax
          .endif
        .endif

        ;Get menu text & help
        .if pChar == NULL
          mov pChar, $addr(cBuffer)
        .else
          add pChar, sizeof(CHR)
        .endif

        .if dLiteral == FALSE
          invoke dec2dword, pChar
          add eax, [xsi].dLanguage
          mov dResID, eax
          mov pChar, $addr(cBuffer)
          invoke LoadString, hInstance, dResID, pChar, lengthof(cBuffer) - 1
          if DEBUGGING
          .if eax == 0
            invoke StrCopy, pChar, offset cResStrNotFound
          .endif
          endif
        .endif

        ;Get help string or help resource ID
        invoke StrLScan, pChar, MENU_CHAR_RESOURCE      ;Resource redirector char
        .if xax == NULL
          invoke StrLScan, pChar, MENU_CHAR_LITERAL     ;Literal indicator char
          .if xax == NULL
            m2z pHelpStr
          .else
            m2z CHR ptr [xax]                           ;Set ZTC for menu text
            add xax, sizeof(CHR)
            mov pHelpStr, $invoke(StrNew, xax)
            m2z dResID
          .endif
        .else
          m2z CHR ptr [xax]                             ;Set ZTC
          add xax, sizeof(CHR)
          invoke dec2dword, xax
          add eax, [xsi].dLanguage
          mov dResID, eax
        .endif

        ;Get menu text & shortcut
        invoke StrLScan, pChar, MENU_CHAR_SHORTCUT
        .if xax == NULL
          m2z pSCutStr
        .else
          m2z CHR ptr [xax]                             ;Set ZTC
          add xax, sizeof(CHR)
          mov pSCutStr, $invoke(StrNew, xax)
        .endif
        mov pMenuStr, $invoke(StrNew, pChar)

        ;Get help from resource ID
        .if dResID != 0
          invoke LoadString, hInstance, dResID, addr cBuffer, lengthof(cBuffer) - 1
          .if eax == 0
            if DEBUGGING
              invoke StrNew, offset cResStrNotFound
            else
              xor eax, eax
            endif
          .else
            invoke StrNew, addr cBuffer
          .endif
          mov pHelpStr, xax
        .endif

        ;Create XMenuItem & initialize it
        New XMenuItem
        .if xax != NULL
          mov MenuInfo.dwItemData, xax                  ;Store XMenuItem POINTER here
          OCall [xsi].MenuItemColl::Collection.Insert, xax
          OCall xax::XMenuItem.Init, xsi, hMenu, MenuInfo.wID, dType, \
                                          pMenuStr, pSCutStr, pHelpStr, dIconIndex

          ;Modify menu
          BitSet MenuInfo.fType, MFT_OWNERDRAW          ;Set always the OwnerDraw flag
          .if dMenubarBreak == 1
            inc dMenubarBreak
          .elseif dMenubarBreak == 2                    ;if dMenubarBreak > 2 also ignored
            BitSet MenuInfo.fType, MFT_MENUBARBREAK     ;Set Menubar break flag
            inc dMenubarBreak
          .endif
          ;Set MIIM_BITMAP to retrigger WM_MEASUREITEM messages
          mov MenuInfo.fMask, MIIM_FTYPE or MIIM_DATA or MIIM_BITMAP
          invoke SetMenuItemInfo, hMenu, sdItemIndex, MF_BYPOSITION, xdi  ;Store new menu info
        .endif
      .endif

      ;Calculate MenuItem metrics of all items in a menu
      ;Calculate height
      invoke GetSystemMetrics, SM_CYMENU
      inc eax
      mov ecx, [xsi].ImageSize.y
      add ecx, 2*MENU_ICON_BORDER
      .if ecx > eax
        mov eax, ecx
      .endif
      mov dLineHeight, eax

      ;Calculate width
      xor eax, eax
      mov xbx, MenuInfo.dwItemData                      ;Restore XMenuItem
      mov Rect.left, eax
      mov Rect.top, eax
      mov Rect.right, eax
      mov Rect.bottom, eax

      mov eax, [xbx].$Obj(XMenuItem).dType
      .if eax == MENU_TYPE_MAINBAR
        invoke SelectObject, hDC, [xsi].hFontTxtNorm
        invoke DrawText, hDC, [xbx].$Obj(XMenuItem).pMenuStr, -1, \
                         addr Rect, DT_CALCRECT or DT_SINGLELINE
        m2m [xbx].$Obj(XMenuItem).dMaxTextWidth, Rect.right, eax
        m2z [xbx].$Obj(XMenuItem).dMaxSCutWidth
        m2m [xbx].$Obj(XMenuItem).dHeight, Rect.bottom, eax

      .elseif eax == MENU_TYPE_SEPARATOR
        .if [xbx].$Obj(XMenuItem).pMenuStr != NULL
          invoke SelectObject, hDC, [xsi].hFontSep
          invoke DrawText, hDC, [xbx].$Obj(XMenuItem).pMenuStr, -1, \
                           addr Rect, DT_CALCRECT or DT_SINGLELINE
          mov eax, Rect.right
          .if SDWORD ptr eax > sdMaxRegTextWidth
            mov sdMaxRegTextWidth, eax
          .endif
        .else
          invoke DrawText, hDC, $OfsCStr("I"), 1, addr Rect, DT_CALCRECT or DT_SINGLELINE
        .endif

        mov eax, dLineHeight
        mov [xbx].$Obj(XMenuItem).dHeight, eax
        add dTotalHeight, eax

      .elseif eax == MENU_TYPE_SIDEBAR
        ;No action

      .else
        .ifBitSet MenuInfo.fState, MFS_DEFAULT
          mov xax, [xsi].hFontTxtBold
        .else
          mov xax, [xsi].hFontTxtNorm
        .endif
        invoke SelectObject, hDC, xax
        .if [xbx].$Obj(XMenuItem).pMenuStr == NULL
          xor eax, eax
        .else
          invoke DrawText, hDC, [xbx].$Obj(XMenuItem).pMenuStr, -1, \
                           addr Rect, DT_CALCRECT or DT_LEFT or DT_SINGLELINE
          mov [xbx].$Obj(XMenuItem).dHeight, eax
          mov eax, Rect.right
        .endif

        mov ecx, [xbx].$Obj(XMenuItem).dID
        .if ecx < 50000 || ecx > 50009
          .if SDWORD ptr eax > sdMaxRegTextWidth
            mov sdMaxRegTextWidth, eax                  ;Store max regular text width
          .endif
        .else
          .if SDWORD ptr eax > sdMaxWndTextWidth
            mov sdMaxWndTextWidth, eax                  ;Store max window text width
          .endif
        .endif

        mov xax, [xbx].$Obj(XMenuItem).pSCutStr
        .if xax == NULL
          xor eax, eax
        .else
          invoke DrawText, hDC, [xbx].$Obj(XMenuItem).pSCutStr, -1, \
                           addr Rect, DT_CALCRECT or DT_RIGHT or DT_SINGLELINE
          mov eax, Rect.right
        .endif
        .if eax > sdMaxSCutWidth
          mov sdMaxSCutWidth, eax                       ;Store max ShortCut width
        .endif
        mov eax, dLineHeight
        mov [xbx].$Obj(XMenuItem).dHeight, eax
        add dTotalHeight, eax
      .endif
    .endif
    inc sdItemIndex
  .endw

  ;Store MenuItem metrics on all XMenuItems except MenuBar items
  .if dIsMenuBar == FALSE
    xor ebx, ebx
    .while ebx < sdItemCount
      mov MenuInfo.fMask, MIIM_DATA
      invoke GetMenuItemInfo, hMenu, ebx, MF_BYPOSITION, addr MenuInfo
      mov xax, MenuInfo.dwItemData
      .if xax != NULL
        mov ecx, [xax].$Obj(XMenuItem).dType
        .if ecx == MENU_TYPE_SIDEBAR
          m2m [xax].$Obj(XMenuItem).dHeight, dTotalHeight, ecx
        .else
          ;Popup item
          .if [xax].$Obj(XMenuItem).dID < 50000 || [xax].$Obj(XMenuItem).dID > 50009
            ;Regular popup item
            .if sdMaxRegTextWidth > 0
              mov ecx, sdMaxWndTextWidth
              .if sdMaxSCutWidth > 0
                sub ecx, sdMaxSCutWidth
                sub ecx, MENU_CX_SCUT
              .endif
              .if ecx < sdMaxRegTextWidth
                mov ecx, sdMaxRegTextWidth
              .endif
            .else
              xor ecx, ecx
            .endif
            mov [xax].$Obj(XMenuItem).dMaxTextWidth, ecx
            .if sdMaxSCutWidth > 0
              mov ecx, sdMaxSCutWidth
            .else
              xor ecx, ecx
            .endif
            mov [xax].$Obj(XMenuItem).dMaxSCutWidth, ecx
          .else
            ;Window popup item
            .if sdMaxWndTextWidth > 0
              mov ecx, sdMaxWndTextWidth
            .else
              xor ecx, ecx
            .endif
            mov [xax].$Obj(XMenuItem).dMaxTextWidth, ecx
            mov [xax].$Obj(XMenuItem).dMaxSCutWidth, 0
          .endif
;          DbgStr [xax].$Obj(XMenuItem).pMenuStr,,"2"
;          DbgDec [xax].$Obj(XMenuItem).dMaxTextWidth,,"2"
        .endif
      .endif
      inc ebx
    .endw
  .endif

  invoke SelectObject, hDC, hPrevFont
  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.Done
; Purpose:    Finalize XMenu object.
; Arguments:  None.
; Return:     Nothing.

Method XMenu.Done, uses xsi
;  DbgText "XMenu.Done"
  SetObject xsi
  .while ([xsi].dFlags & XMF_FLASHING)
    invoke Sleep, 250
  .endw

  invoke DeleteObject, [xsi].hFontSep
  invoke DeleteObject, [xsi].hFontTxtNorm
  invoke DeleteObject, [xsi].hFontTxtBold
  Destroy [xsi].pXMdiMenu                               ;Safe Kill
  OCall [xsi].MenuItemColl::Collection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawMenuBarBkgnd
; Purpose:    Draw a MenuBar menu background.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.
; Note:       The ODS_HOTLIGHT is not used on Win98, so no HotTracking is possible!

Method XMenu.DrawMenuBarBkgnd, uses xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, hBrush:HBRUSH

;  DbgText "XMenu.DrawMenuBarBkgnd"
  SetObject xsi
  mov xdi, pDIS
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem, xax, xcx
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_HOTLIGHT
    invoke GetSysColor, COLOR_HIGHLIGHT                 ;Don't use COLOR_MENUHILIGHT
    mov hBrush, $invoke(CreateSolidBrush, eax)
    invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
  .else
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
      invoke GetSysColor, COLOR_HIGHLIGHT               ;Don't use COLOR_MENUHILIGHT
    .else
      mov eax, [xsi].MenuBarBkColor
    .endif
    mov hBrush, $invoke(CreateSolidBrush, eax)
    invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
  .endif
  invoke DeleteObject, hBrush
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawMenuBarIcon
; Purpose:    Draw a MenuBar menu icon.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.
; Note:       Currently not used!

Method XMenu.DrawMenuBarIcon,, pDIS:PDRAWITEMSTRUCT
;  DbgText "XMenu.DrawMenuBarIcon"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawMenuBarText
; Purpose:    Draw a MenuBar menu text.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.
; Note:       Rect width for main menu items returned by the OS is calculated as follows:
;                  Width = Int((OnMeasureItem X-Size + 18)/8)*8

Method XMenu.DrawMenuBarText, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, hPrevFont:HFONT, dPrevBkMode:DWORD, dPrevColor:DWORD

;  DbgText "XMenu.DrawMenuBarText"
  SetObject xsi
  mov xdi, pDIS
  mov xbx, [xdi].DRAWITEMSTRUCT.itemData                ;xbx -> XMenuItem
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  add Rect.left, MENU_BAR_LEFT_MARGIN
  sub Rect.right, MENU_BAR_RIGHT_MARGIN
  mov hPrevFont, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, [xsi].hFontTxtNorm)
  invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, TRANSPARENT
  mov dPrevBkMode, eax
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_INACTIVE
    invoke GetSysColor, COLOR_BTNSHADOW
    invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax
    mov dPrevColor, eax
    mov xdx, [xbx].$Obj(XMenuItem).pMenuStr
    .if xdx != NULL
      invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, xdx, -1, \
                       addr Rect, DT_CENTER or DT_VCENTER or DT_SINGLELINE
    .endif
  .else
    .ifBitClr [xdi].DRAWITEMSTRUCT.itemState, ODS_GRAYED
      ;Item is enabled
      .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
        mov eax, COLOR_HIGHLIGHTTEXT
      .elseIfBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_HOTLIGHT
        mov eax, COLOR_HIGHLIGHTTEXT
      .else
        mov eax, COLOR_MENUTEXT
      .endif
      invoke GetSysColor, eax
      mov dPrevColor, $32($invoke(SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax))

      mov xdx, [xbx].$Obj(XMenuItem).pMenuStr
      .if xdx != NULL
        invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, xdx, -1, \
                         addr Rect, DT_CENTER or DT_VCENTER or DT_SINGLELINE
      .endif
    .else
      ;Item is disabled
      invoke GetSysColor, COLOR_GRAYTEXT
      mov dPrevColor, $32($invoke(SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax))
      mov xdx, [xbx].$Obj(XMenuItem).pMenuStr
      .if xdx != NULL
        invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, [xbx].$Obj(XMenuItem).pMenuStr, -1, \
                         addr Rect, DT_CENTER or DT_VCENTER or DT_SINGLELINE
      .endif
    .endif
  .endif
  invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, dPrevBkMode
  invoke SelectObject, [xdi].DRAWITEMSTRUCT.hDC, hPrevFont
  invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, dPrevColor
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawPopupBkgnd
; Purpose:    Draw a popup menu background.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawPopupBkgnd, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect: RECT, hBrush:HBRUSH

; local hPrevPen:HPEN, hPrevBrush:HBRUSH

;  SetObject xsi
;  mov xdi, pDIS
;  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
;  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
;    invoke CreatePen, PS_SOLID, 1, $RGB(255, 255, 255);COLOR_MENUHIGHLIGHT
;    mov hPrevPen, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, eax)
;    invoke CreateSolidBrush, $RGB(128, 62, 186)
;    mov hPrevBrush, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, eax)
;    invoke Rectangle, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, Rect.right, Rect.bottom
;    invoke DeleteObject, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, hPrevPen)
;    invoke DeleteObject, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, hPrevBrush)
;  .else
;    mov hBrush, $invoke(CreateSolidBrush, $invoke(GetSysColor, COLOR_MENU))
;    invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
;    invoke DeleteObject, hBrush
;  .endif

;  DbgText "XMenu.DrawPopupBkgnd"
  SetObject xsi
  mov xdi, pDIS
  ;Erase icon area background
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  mov ebx, Rect.right
  mov eax, Rect.left
  add eax, [xsi].ImageSize.x
  add eax, 2 * MENU_ICON_BORDER + MENU_CX_GAP
  mov Rect.right, eax
  invoke GetSysColor, COLOR_MENU
  mov hBrush, $invoke(CreateSolidBrush, eax)
  invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
  invoke DeleteObject, hBrush

  ;Erase text area background
  m2m Rect.left, Rect.right, eax
  mov Rect.right, ebx
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
    mov eax, COLOR_HIGHLIGHT                            ;Don't use COLOR_MENUHILIGHT
  .else
    mov eax, COLOR_MENU
  .endif
  invoke GetSysColor, eax
  mov hBrush, $invoke(CreateSolidBrush, eax)
  invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
  invoke DeleteObject, hBrush
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawPopupCheck
; Purpose:    Draw a popup menu CheckButton using system icon.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawPopupCheck, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, dChecked:DWORD
  local hBmpCheck:HBITMAP, hBmpRadioMask:HBITMAP
  local hMemDC:HDC, hPrevBmp:HBITMAP
  local BmpInfo:BITMAP, BmpSize:dword

;  DbgText "XMenu.DrawPopupCheck"
  SetObject xsi
  mov xdi, pDIS
  mov hBmpCheck, $invoke(LoadBitmap, 0, OBM_CHECKBOXES)
  mov hBmpRadioMask, $invoke(LoadBitmap, 0, OBM_BTNCORNERS)
  invoke GetObject, hBmpRadioMask, sizeof(BmpInfo), addr BmpInfo
  m2m BmpSize, BmpInfo.bmWidth, eax

  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_CHECKED
    mov dChecked, TRUE
  .else
    m2z dChecked
  .endif

  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  mov eax, Rect.bottom
  sub eax, Rect.top
  sub eax, BmpSize
  shr eax, 1
  add Rect.top, eax
  mov eax, [xsi].ImageSize.x
  ReleaseObject
  sub eax, BmpSize
  shr eax, 1
  add eax, MENU_ICON_BORDER
  add Rect.left, eax
  mov hMemDC, $invoke(CreateCompatibleDC, [xdi].DRAWITEMSTRUCT.hDC)
  mov hPrevBmp, $invoke(SelectObject, hMemDC, hBmpRadioMask)
  invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                 BmpSize, BmpSize, hMemDC, \
                 0, 0, MERGEPAINT

  invoke SelectObject, hMemDC, hBmpCheck
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_GRAYED
    ;Disabled
    mov edx, BmpSize
    .if dChecked == FALSE
      xor esi, esi
      lea ebx, [2*edx]
    .else
      lea esi, [2*edx]
      lea ebx, [esi + edx]
    .endif
    invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                   BmpSize, BmpSize, hMemDC, ebx, esi, SRCCOPY
  .else
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
      ;Selected
      .if dChecked == FALSE
        xor ebx, ebx
      .else
        mov ebx, BmpSize
      .endif
      invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                     BmpSize, BmpSize, hMemDC, ebx, 0, SRCCOPY
    .else
      .if dChecked == FALSE
        xor ebx, ebx
      .else
        mov ebx, BmpSize
      .endif
      invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                     BmpSize, BmpSize, hMemDC, ebx, 0, SRCCOPY
    .endif

  .endif
  invoke SelectObject, hMemDC, hPrevBmp
  invoke DeleteDC, hMemDC
  invoke DeleteObject, hBmpCheck
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawPopupIcon
; Purpose:    Draw a popup menu icon using XMenu ImageList.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawPopupIcon, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT

;  DbgText "XMenu.DrawPopupIcon"
  SetObject xsi
  mov xdi, pDIS
  mov xbx, [xdi].DRAWITEMSTRUCT.itemData
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  .if [xbx].$Obj(XMenuItem).dIconIndex != NO_IMAGE
    mov eax, Rect.bottom
    sub eax, Rect.top
    sub eax, [xsi].ImageSize.y
    shr eax, 1
    add Rect.top, eax
    mov eax, Rect.top
    add eax, [xsi].ImageSize.y
    mov Rect.bottom, eax
    add Rect.left, MENU_ICON_BORDER
    mov eax, Rect.left
    add eax, [xsi].ImageSize.x
    mov Rect.right, eax
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_GRAYED
      ;Disabled
      OCall [xsi].pImgList::MaskedImageList.DrawEmbossed, [xbx].$Obj(XMenuItem).dIconIndex, \
                                                          [xdi].DRAWITEMSTRUCT.hDC, \
                                                          Rect.left, Rect.top
    .else
      .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
        ;Selected => draw a frame arround the icon
        GrowRect Rect, MENU_ICON_BORDER
        invoke DrawEdge, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, BDR_RAISEDINNER, BF_RECT or BF_MIDDLE
        GrowRect Rect, -MENU_ICON_BORDER
      .endif
      OCall [xsi].pImgList::MaskedImageList.Draw, [xbx].$Obj(XMenuItem).dIconIndex, \
                                                  [xdi].DRAWITEMSTRUCT.hDC, \
                                                  Rect.left, Rect.top
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawPopupRadio
; Purpose:    Draw a popup menu radiobutton using system icon.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawPopupRadio, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, dChecked:DWORD
  local hBmpCheck:HBITMAP, hBmpRadioMask:HBITMAP
  local hMemDC:HDC, hPrevBmp:HBITMAP
  local BmpInfo:BITMAP, BmpSize:dword

;  DbgText "XMenu.DrawPopupRadio"
  SetObject xsi
  mov xdi, pDIS
  mov hBmpCheck, $invoke(LoadBitmap, 0, OBM_CHECKBOXES)
  mov hBmpRadioMask, $invoke(LoadBitmap, 0, OBM_BTNCORNERS)
  invoke GetObject, hBmpRadioMask, sizeof(BmpInfo), addr BmpInfo
  m2m BmpSize, BmpInfo.bmWidth, eax

  ;DbgBmp hBmpCheck, "hBmpCheck"
  ;DbgBmp hBmpRadioMask, "hBmpRadioMask"
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_CHECKED
    mov dChecked, TRUE
  .else
    m2z dChecked
  .endif

  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  mov eax, Rect.bottom
  sub eax, Rect.top
  sub eax, BmpSize
  shr eax, 1
  add Rect.top, eax

  mov eax, [xsi].ImageSize.x
  ReleaseObject
  sub eax, BmpSize
  shr eax, 1
  add eax, MENU_ICON_BORDER
  add Rect.left, eax
  mov hMemDC, $invoke(CreateCompatibleDC, [xdi].DRAWITEMSTRUCT.hDC)
  mov hPrevBmp, $invoke(SelectObject, hMemDC, hBmpRadioMask)
  invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                 BmpSize, BmpSize, hMemDC, \
                 0, 0, MERGEPAINT
  invoke SelectObject, hMemDC, hBmpCheck
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_GRAYED
    ;Disabled
    mov ecx, BmpSize
    .if dChecked == FALSE
      lea esi, [2*ecx]
    .else
      lea esi, [2*ecx + ecx]
    .endif
    mov ebx, ecx
    invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                   BmpSize, BmpSize, hMemDC, esi, ebx, SRCAND
    add ebx, ebx
    invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                   BmpSize, BmpSize, hMemDC, BmpSize, ebx, SRCPAINT
  .else
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
      ;Selected
      .if dChecked == FALSE
        xor esi, esi
      .else
        mov esi, BmpSize
      .endif
      invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                     BmpSize, BmpSize, hMemDC, esi, BmpSize, SRCAND
    .else
      .if dChecked == FALSE
        xor esi, esi
      .else
        mov esi, BmpSize
      .endif
      invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, Rect.left, Rect.top, \
                     BmpSize, BmpSize, hMemDC, esi, BmpSize, SRCAND
    .endif
  .endif
  invoke SelectObject, hMemDC, hPrevBmp
  invoke DeleteDC, hMemDC
  invoke DeleteObject, hBmpCheck
  invoke DeleteObject, hBmpRadioMask
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawPopupSeparator
; Purpose:    Draw a popup menu separator line.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawPopupSeparator, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, cTextBuffer[256]:CHR, pText:PSTRING
  local hPrevFont:HFONT, dPrevBkMode:DWORD, dPrevColor:DWORD

;  DbgText "XMenu.DrawPopupSeparator"
  SetObject xsi
  mov xdi, pDIS
  mov xbx, [xdi].DRAWITEMSTRUCT.itemData
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem

  ;Draw line
  CloneRect Rect, [xdi].DRAWITEMSTRUCT. rcItem
  add Rect.left, MENU_CX_SEP_MARGIN
  sub Rect.right, MENU_CX_SEP_MARGIN
  mov eax, Rect.bottom
  sub eax, Rect.top
  shr eax, 1
  dec eax
  add Rect.top, eax
  invoke DrawEdge, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, EDGE_ETCHED, BF_TOP

  ;Draw Text
  mov xax, [xbx].$Obj(XMenuItem).pMenuStr
  .if (xax != NULL) && (CHR ptr [xax] != 0)             ;Make sure that the string is not empty
    lea xcx, cTextBuffer
    mov pText, xcx
    mov CHR ptr [xcx], " "
    add xcx, sizeof(CHR)
    invoke StrECopy, xcx, [xbx].$Obj(XMenuItem).pMenuStr
    mov DCHR ptr [xax], " "                             ;Add space and ZTC
    mov hPrevFont, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, [xsi].hFontSep)
    invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, OPAQUE
    mov dPrevBkMode, eax
    invoke GetSysColor, COLOR_BTNHILIGHT
    invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax
    mov dPrevColor, eax
    CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
    invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, pText, -1, \
                     addr Rect, DT_CENTER or DT_SINGLELINE or DT_VCENTER

    invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, TRANSPARENT
    invoke GetSysColor, COLOR_BTNSHADOW
    invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax
    dec Rect.top
    dec Rect.bottom
    dec Rect.left
    dec Rect.right
    invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, pText, -1, \
                     addr Rect, DT_CENTER or DT_SINGLELINE or DT_VCENTER

    invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, dPrevColor
    invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, dPrevBkMode
    invoke SelectObject, [xdi].DRAWITEMSTRUCT.hDC, hPrevFont
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawPopupText
; Purpose:    Draw a popup menu text.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawPopupText, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, hPrevFont:HFONT, dPrevBkMode:DWORD, dPrevColor:DWORD

;  DbgText "XMenu.DrawPopupText"
  SetObject xsi
  mov xdi, pDIS
  mov xbx, [xdi].DRAWITEMSTRUCT.itemData
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  mov eax, Rect.left
  add eax, [xsi].ImageSize.x
  add eax, 2*MENU_ICON_BORDER + MENU_CX_GAP + MENU_POPUP_LEFT_MARGIN
  mov Rect.left, eax

  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_DEFAULT
    mov xax, [xsi].hFontTxtBold
  .else
    mov xax, [xsi].hFontTxtNorm
  .endif
  mov hPrevFont, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, xax)
  invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, TRANSPARENT   ;Switch to OPAQUE to show the RECTs
  mov dPrevBkMode, eax
  .ifBitClr [xdi].DRAWITEMSTRUCT.itemState, ODS_GRAYED
    ;Item is enabled
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
      mov eax, COLOR_HIGHLIGHTTEXT
    .else
      mov eax, COLOR_MENUTEXT
    .endif
    invoke GetSysColor, eax
    invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax
    mov dPrevColor, eax

    .if [xbx].$Obj(XMenuItem).pMenuStr != NULL
      ;Menu text
      invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, [xbx].$Obj(XMenuItem).pMenuStr, -1, \
                       addr Rect, DT_LEFT or DT_VCENTER or DT_SINGLELINE
    .endif
    .if [xbx].$Obj(XMenuItem).pSCutStr != NULL
      ;Menu ShortCut
      mov eax, [xbx].$Obj(XMenuItem).dMaxTextWidth
      add Rect.left, eax
      sub Rect.right, MENU_POPUP_RIGHT_MARGIN
      invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, [xbx].$Obj(XMenuItem).pSCutStr, -1, \
                       addr Rect, DT_RIGHT or DT_VCENTER or DT_SINGLELINE
    .endif
  .else
    ;Item is disabled
    invoke GetSysColor, COLOR_GRAYTEXT
    mov dPrevColor, $32($invoke(SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax))
    .if [xbx].$Obj(XMenuItem).pMenuStr != NULL
      ;Menu text
      invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, [xbx].$Obj(XMenuItem).pMenuStr, -1, \
                       addr Rect, DT_LEFT or DT_VCENTER or DT_SINGLELINE
    .endif
    .if [xbx].$Obj(XMenuItem).pSCutStr != NULL
      ;Menu ShortCut
      mov eax, [xbx].$Obj(XMenuItem).dMaxTextWidth
      add Rect.left, eax
      add Rect.left, MENU_CX_SCUT
      sub Rect.right, MENU_POPUP_RIGHT_MARGIN

      invoke GetSysColor, COLOR_GRAYTEXT
      invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax
      invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, [xbx].$Obj(XMenuItem).pSCutStr, -1, \
                       addr Rect, DT_RIGHT or DT_VCENTER or DT_SINGLELINE

    .endif
  .endif
  invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, dPrevBkMode
  invoke SelectObject, [xdi].DRAWITEMSTRUCT.hDC, hPrevFont
  invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, dPrevColor
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawSidebarBkgnd
; Purpose:    Draw a Sidebar background.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawSidebarBkgnd, uses xbx xdi xsi, pDIS:PDRAWITEMSTRUCT
  local hMemDC:HDC, hMemPrvBmp:HBITMAP, hBmp:HBITMAP, BmpInfo:BITMAP

;  DbgText "XMenu.DrawSidebarBkgnd"
  SetObject xsi
  mov xdi, pDIS
  mov xbx, [xdi].DRAWITEMSTRUCT.itemData
  .if [xbx].$Obj(XMenuItem).pHelpStr != NULL
    mov hMemDC, $invoke(CreateCompatibleDC, [xdi].DRAWITEMSTRUCT.hDC)
    mov xax, [xbx].$Obj(XMenuItem).pHelpStr
    mov hBmp, $invoke(LoadBitmap, hInstance, [xbx].$Obj(XMenuItem).pHelpStr)
    ASSERT xax, "XMenu.DrawSidebarBkgnd failed to load bitmap"
    mov hMemPrvBmp, $invoke(SelectObject, hMemDC, hBmp)
    invoke GetObject, hBmp, sizeof(BmpInfo), addr BmpInfo
    mov eax, [xdi].DRAWITEMSTRUCT.rcItem.top
    add eax, [xbx].$Obj(XMenuItem).dHeight
    sub eax, BmpInfo.bmHeight
    mov ebx, eax
    invoke BitBlt, [xdi].DRAWITEMSTRUCT.hDC, \
             [xdi].DRAWITEMSTRUCT.rcItem.left, eax, MENU_SIDEBAR_WIDTH, BmpInfo.bmHeight, \
             hMemDC, 0, 0, SRCCOPY
    invoke StretchBlt, [xdi].DRAWITEMSTRUCT.hDC, \
             [xdi].DRAWITEMSTRUCT.rcItem.left, [xdi].DRAWITEMSTRUCT.rcItem.top, \
             MENU_SIDEBAR_WIDTH, ebx,
             hMemDC, 0, 0, MENU_SIDEBAR_WIDTH, 1, SRCCOPY
    invoke DeleteObject, $invoke(SelectObject, hMemDC, hMemPrvBmp)
    invoke DeleteDC, hMemDC
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.DrawSidebarText
; Purpose:    Draw a Sidebar text.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.

Method XMenu.DrawSidebarText,, pDIS:PDRAWITEMSTRUCT
;  DbgText "XMenu.DrawSidebarText"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.FlashMenuBar
; Purpose:    Async flash the MenuBar to capture the users attention.
; Arguments:  Arg1: Flash color.
;             Arg2: Number of repetitions
; Return:     Nothing.

FMB_Params struc
  pXMenu        POINTER   ?
  BkColor1      RGBQUAD   {}
  BkColor2      RGBQUAD   {}
  dRepetitions  DWORD     ?
FMB_Params ends

FlashMenuBar proc uses xbx xdi xsi, pFMBParam:ptr FMB_Params
  mov xsi, pFMBParam
  mov xdi, [xsi].FMB_Params.pXMenu
  mov ebx, [xsi].FMB_Params.dRepetitions
  test ebx, ebx
  .while !ZERO?
    OCall xdi::XMenu.SetMenuBarBkColor, [xsi].FMB_Params.BkColor1
    invoke DrawMenuBar, [xdi].$Obj(XMenu).hWnd
    invoke Sleep, 100
    OCall xdi::XMenu.SetMenuBarBkColor, [xsi].FMB_Params.BkColor2
    invoke DrawMenuBar, [xdi].$Obj(XMenu).hWnd
    invoke Sleep, 150
    dec ebx
  .endw
;  invoke DrawMenuBar, [xdi].$Obj(XMenu).hWnd            ;Final update
  MemFree xsi
  BitClr [xdi].$Obj(XMenu).dFlags, XMF_FLASHING
  ret
FlashMenuBar endp

Method XMenu.FlashMenuBar, uses xbx xsi, BkColor:RGBQUAD, dRepetitions:DWORD
;  DbgText "XMenu.FlashMenuBar"
  SetObject xsi
  .ifBitClr [xsi].dFlags, XMF_FLASHING                  ;Don't accept new commands while flashing
    BitSet [xsi].dFlags, XMF_FLASHING
    MemAlloc sizeof(FMB_Params)
    mov xbx, xax
    mov [xbx].FMB_Params.pXMenu, xsi
    m2m [xbx].FMB_Params.BkColor1, BkColor, eax
    m2m [xbx].FMB_Params.BkColor2, [xsi].MenuBarBkColor, ecx
    m2m [xbx].FMB_Params.dRepetitions, dRepetitions, eax
    invoke CreateThread, NULL, 4096, offset FlashMenuBar, xbx, 0, NULL
    invoke CloseHandle, xax                             ;Decrement Reference Count
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.Init
; Purpose:    Initialize XMenu object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Main Window HANDLE in a SDI application or the Frame Window in a MDI application.
;             Arg3: If exist, a HANDLE of its MDI Client Window (MdiApp), otherwise 0.
;             Arg4: If exist, a HANDLE of a "window" menu, otherwise 0.
;             Arg5: -> Imagelist object that contains the item icons.
;             Arg6: -> help callback procedure or NULL.
;             Arg7: Menu language identifier.
; Return:     Nothing.

Method XMenu.Init, uses xsi, pOwner:POINTER, hWnd:HWND, \
                           hMdiClientWnd:HWND, hMdiWindowMenu:HMENU, \
                           pImgList:$ObjPtr(MaskedImageList), \
                           pHelpCallback:POINTER, dLanguage:DWORD
;  DbgText "XMenu.Init"
  SetObject xsi
  ACall xsi.Init, pOwner, hWnd, offset szPropXMenu
  m2m [xsi].hMdiClientWnd, hMdiClientWnd, xax
  m2m [xsi].hMdiWindowMenu, hMdiWindowMenu, xax
  m2m [xsi].pImgList, pImgList, xax
  m2m [xsi].pHelpCallback, pHelpCallback, xax
  m2m [xsi].dLanguage, dLanguage, eax
  mov [xsi].hMenu, $invoke(GetMenu, [xsi].hWnd)         ;Get menu of the main Window

  ;If a Client window is present then create a XMdiMenu object
  .if hMdiClientWnd != NULL
    New XMdiMenu
    mov [xsi].pXMdiMenu, xax
    OCall [xsi].pXMdiMenu::XMdiMenu.Init, xsi, hMdiClientWnd, hMdiWindowMenu, offset szPropXMenu
  .endif

  ;Initialize variables and resources
  mov [xsi].MenuBarBkColor, $32($invoke(GetSysColor, COLOR_MENUBAR))  ;This is the default color
  OCall [xsi].MenuItemColl::Collection.Init, xsi, 16, 16, COL_MAX_CAPACITY
  OCall pImgList::MaskedImageList.GetSize, addr [xsi].ImageSize
  OCall xsi.UpdateFonts                                 ;Create fonts
  OCall xsi.Convert, [xsi].hMenu, TRUE                  ;Convert main menu
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.IsMenuBarSubMenu
; Purpose:    Determine if a specified menu handle corresponds to the main MenuBar.
; Arguments:  Arg1: SubMenu handle.
; Return:     eax = TRUE / FALSE.

Method XMenu.IsMenuBarSubMenu, uses xbx, hSubMenu:HMENU
  local hMainMenu:HMENU

  SetObject xcx
  m2m hMainMenu, [xcx].hMenu, xax
  xor ebx, ebx
  .repeat
    invoke GetSubMenu, hMainMenu, ebx
    inc ebx
  .until xax == hSubMenu || xax == 0
  .if eax != FALSE
    mov eax, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XMenu.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[256]:CHR, MenuInfo:MENUITEMINFO, hChildWnd:HWND, pMenuText:PSTRING
  local XMSD:$Obj(XMenuSelectDlg)

;  DbgText "XMenu.OnCommand"
  SetObject xsi
  mov xdi, $LoWord(wParam)
  .if ([xsi].hMdiClientWnd != 0) && ([xsi].hMdiWindowMenu != 0) && (edi >= 50000) && (edi <= 50008)
    mov MenuInfo.cbSize, sizeof(MenuInfo)               ;and exits in the While loop!
    mov MenuInfo.fMask, MIIM_DATA
    invoke GetMenuItemInfo, [xsi].hMdiWindowMenu, edi, MF_BYCOMMAND, addr MenuInfo
    mov xax, MenuInfo.dwItemData
    m2m pMenuText, [xax].$Obj(XMenuItem).pMenuStr, xcx
    add pMenuText, 3*sizeof(CHR)                        ;Skip accelerator string, ie: "&1 "

    invoke GetWindow, [xsi].hMdiClientWnd, GW_CHILD
    mov hChildWnd, $invoke(GetWindow, xax, GW_HWNDFIRST)
  @@0:
    invoke GetWindowText, hChildWnd, addr cBuffer, lengthof cBuffer
    invoke StrComp, addr cBuffer, pMenuText
    je @@1
    mov hChildWnd, $invoke(GetWindow, hChildWnd, GW_HWNDNEXT)
    jmp @@0
  @@1:
    invoke SendMessage, [xsi].hMdiClientWnd, WM_MDIACTIVATE, hChildWnd, 0

  .elseif ([xsi].hMdiClientWnd != 0) && ([xsi].hMdiWindowMenu != 0) && (edi == MENU_WINDOW_MORE)
    mov xdi, $New(XMSD::XMenuSelectDlg)
    OCall xdi::XMenuSelectDlg.Init, xsi, [xsi].hWnd, offset XMENUSELECTION
    OCall xdi::XMenuSelectDlg.Show
    OCall xdi::XMenuSelectDlg.Done

  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnDrawItem
; Purpose:    Event procedure for WM_DRAWITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns TRUE.

Method XMenu.OnDrawItem, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XMenu.OnDrawItem"
  SetObject xsi
  .if wParam == 0                                       ;Zero if message was sent by a menu
    mov xbx, lParam
    mov xdx, [xbx].DRAWITEMSTRUCT.itemData              ;-> XMenuItem
    mov edi, [xdx].$Obj(XMenuItem).dType
    .if edi == MENU_TYPE_MAINBAR
      .ifBitSet [xbx].DRAWITEMSTRUCT.itemState, ODS_HOTLIGHT
        OCall xsi.SendHelp, [xdx].$Obj(XMenuItem).pHelpStr
      .else
        .ifBitClr [xbx].DRAWITEMSTRUCT.itemState, ODS_HOTLIGHT or ODS_SELECTED
          OCall xsi.SendHelp, NULL
        .endif
      .endif
      OCall xsi.DrawMenuBarBkgnd, xbx
      OCall xsi.DrawMenuBarIcon, xbx
      OCall xsi.DrawMenuBarText, xbx
    .elseif edi == MENU_TYPE_NORMAL || edi == MENU_TYPE_SUBMENU
      OCall xsi.DrawPopupBkgnd, xbx
      OCall xsi.DrawPopupIcon, xbx
      OCall xsi.DrawPopupText, xbx
    .elseif edi == MENU_TYPE_SEPARATOR
      OCall xsi.DrawPopupSeparator, xbx
    .elseif edi == MENU_TYPE_SIDEBAR
      OCall xsi.DrawSidebarBkgnd, xbx
      OCall xsi.DrawSidebarText, xbx
    .elseif edi == MENU_TYPE_CHECK
      OCall xsi.DrawPopupBkgnd, xbx
      OCall xsi.DrawPopupCheck, xbx
      OCall xsi.DrawPopupText, xbx
    .elseif edi == MENU_TYPE_RADIO
      OCall xsi.DrawPopupBkgnd, xbx
      OCall xsi.DrawPopupRadio, xbx
      OCall xsi.DrawPopupText, xbx
    .else
      invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_DRAWITEM, wParam, xbx
    .endif
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_DRAWITEM, wParam, xbx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnInitMenuPopup
; Purpose:    Event procedure for WM_INITMENUPOPUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns zero.
; Note:       Since MS forgot to mark the MDI system menu of a maximized MDI child as system menu,
;             we write a workaround to fix it.

Method XMenu.OnInitMenuPopup, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dMdiMaxState:DWORD

;  DbgText "XMenu.OnInitMenuPopup"
  SetObject xsi
  mov xax, wParam
  .if xax == [xsi].hMdiWindowMenu
    OCall xsi.WindowMenuRemove, [xsi].hMdiWindowMenu
    ;Now the Child Window menu items are added to the MDI Window Menu set with the WM_MDISETMENU
    invoke SendMessage, [xsi].hMdiClientWnd, WM_MDIREFRESHMENU, wParam, lParam
    OCall xsi.WindowMenuCreate, [xsi].hMdiWindowMenu
  .endif
  .if lParam.DOUBLEWORD.HiWrd == FALSE                  ;Don't touch SysMenu
    .if $OCall(xsi.IsMenuBarSubMenu, wParam) != FALSE
      ;For maximized MDI childs... ignore this menu!
      .if (lParam.DOUBLEWORD.LoWrd == 0) && [xsi].hMdiClientWnd != 0
        invoke SendMessage, [xsi].hMdiClientWnd, WM_MDIGETACTIVE, 0, addr dMdiMaxState
        .if dMdiMaxState != FALSE
          jmp @F
        .endif
      .endif
    .endif
    OCall xsi.Convert, wParam, FALSE
  @@:
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_INITMENUPOPUP, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnMeasureItem
; Purpose:    Event procedure for WM_MEASUREITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns TRUE.

Method XMenu.OnMeasureItem, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XMenu.OnMeasureItem"
  SetObject xsi
  mov xbx, lParam
  .if [xbx].MEASUREITEMSTRUCT.CtlType == ODT_MENU
    mov xdi, [xbx].MEASUREITEMSTRUCT.itemData           ;Get -> XMenuItem
    .if xdi != NULL
      mov eax, [xdi].$Obj(XMenuItem).dType
      .if eax == MENU_TYPE_MAINBAR
        invoke GetSystemMetrics, SM_CYMENU
        inc eax
        mov [xbx].MEASUREITEMSTRUCT.itemHeight, eax
        mov edx, [xdi].$Obj(XMenuItem).dMaxTextWidth
        add edx, MENU_BAR_LEFT_MARGIN + MENU_BAR_RIGHT_MARGIN
        mov [xbx].MEASUREITEMSTRUCT.itemWidth, edx

      .elseif eax == MENU_TYPE_SEPARATOR
        m2m [xbx].MEASUREITEMSTRUCT.itemHeight, [xdi].$Obj(XMenuItem).dHeight, edx
        mov edx, [xdi].$Obj(XMenuItem).dMaxTextWidth
        sub edx, MENU_CX_WIN
        mov [xbx].MEASUREITEMSTRUCT.itemWidth, edx

      .elseif eax == MENU_TYPE_SIDEBAR
        invoke GetSystemMetrics, SM_CXMENUCHECK         ;size always added
        dec eax
        mov ecx, MENU_SIDEBAR_WIDTH + 1
        .if ecx >= eax
          sub ecx, eax
        .else
          xor ecx, ecx
        .endif
        mov [xbx].MEASUREITEMSTRUCT.itemWidth, ecx

      .else
        ;Regular item
        m2m [xbx].MEASUREITEMSTRUCT.itemHeight, [xdi].$Obj(XMenuItem).dHeight, edx

        mov eax, [xsi].ImageSize.x
        add eax, 2*MENU_ICON_BORDER + MENU_CX_GAP + MENU_POPUP_LEFT_MARGIN + MENU_POPUP_RIGHT_MARGIN
        add eax, [xdi].$Obj(XMenuItem).dMaxTextWidth
        .if [xdi].$Obj(XMenuItem).dMaxSCutWidth != 0
          add eax, [xdi].$Obj(XMenuItem).dMaxSCutWidth
          add eax, MENU_CX_SCUT
        .endif
        sub eax, MENU_CX_WIN
        mov [xbx].MEASUREITEMSTRUCT.itemWidth, eax
;        DbgStr [xdi].$Obj(XMenuItem).pMenuStr,, "WM_MEASUREITEM"
;        DbgDec [xbx].MEASUREITEMSTRUCT.itemWidth,, "WM_MEASUREITEM"
      .endif
    .endif
    mov eax, TRUE
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_MEASUREITEM, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnMenuChar
; Purpose:    Event procedure for WM_MENUCHAR message.
; Arguments:  Arg1: First message parameter. LOWORD(wParam) = ASCII char, HIWORD(wParam)= menu flag
;                   This parameter can be one of the following values:
;                     - MF_POPUP Pop-up menu
;                     - MF_SYSMENU System menu
;             Arg2: Second message parameter. Menu handle.
; Return:     eax = An application that processes this message should return one of the following
;             values in the high-order word of the return value:
;             value    Meaning
;             0 (MNC_IGNORE)  Informs Windows that it should discard the character the user pressed
;                             and create a short beep on the system speaker.
;             1 (MNC_CLOSE)   Informs Windows that it should close the active menu.
;             2 (MNC_EXECUTE) Informs Windows that the low-order word of the return value specifies
;                             the zero-based relative position of a menu item. This item is selected
;                             by Windows. The owner window receives a WM_COMMAND message.
;             3 (MNC_SELECT)  Informs the system that it should select the item specified in the
;                             low-order word of the return value.

Method XMenu.OnMenuChar, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local sdItemCount:SDWORD, MenuInfo:MENUITEMINFO

;  DbgText "XMenu.OnMenuChar"
  .ifBitClr wParam, MF_SYSMENU * 10000h                 ;Ignore SysMenu requests -> CallWindowProc
    SetObject xsi
    invoke GetMenuItemCount, lParam
    mov sdItemCount, eax
    mov MenuInfo.cbSize, sizeof(MenuInfo)
    xor ebx, ebx
    mov MenuInfo.fMask, MIIM_DATA or MIIM_ID
    .while ebx < sdItemCount
      invoke GetMenuItemInfo, lParam, ebx, MF_BYPOSITION, addr MenuInfo
      .if MenuInfo.wID != 0                             ;Skip Menuitems with ID = 0 (MDICHILD_SYSMENU)
        mov xdi, MenuInfo.dwItemData
        .if xdi != NULL                                 ;Just in case that MenuInfo.dwItemData = NULL
          mov xax, [xdi].$Obj(XMenuItem).pMenuStr
          .if xax != NULL
            invoke StrLScan, xax, "&"
            .if xax != NULL
              movzx ecx, CHR ptr [xax + sizeof(CHR)]
              .if (cx >= "a") && (cx <= "z")
                BitClr cx, BIT05                        ;Make uppercase
              .endif
              mov xax, wParam
              .if (ax >= "a") && (ax <= "z")
                BitClr ax, BIT05                        ;Make uppercase
              .endif
              .if ax == cx
                mov eax, ebx
                or eax, MNC_EXECUTE * 10000h
                ExitMethod
              .endif
            .endif
          .endif
        .endif
      .endif
      inc ebx
    .endw
    xor eax, eax                                        ;MNC_IGNORE
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_MENUCHAR, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnMenuSelect
; Purpose:    Event procedure for WM_MENUSELECT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns zero.

Method XMenu.OnMenuSelect, uses xsi, wParam:WPARAM, lParam:LPARAM
  local MenuInfo:MENUITEMINFO, dOnPos:DWORD

;  DbgText "XMenu.OnMenuSelect"
  SetObject xsi
  .ifBitSet wParam, MF_OWNERDRAW shl 16
    .if [xsi].pHelpCallback != NULL
      mov MenuInfo.cbSize, sizeof(MenuInfo)
      mov MenuInfo.fMask, MIIM_DATA
      xor edx, edx
      mov xcx, wParam
      mov dx, cx
      shr ecx, 16
      .ifBitSet ecx, MF_POPUP
        mov dOnPos, MF_BYPOSITION
      .else
        mov dOnPos, MF_BYCOMMAND
      .endif
      invoke GetMenuItemInfo, lParam, edx, dOnPos, addr MenuInfo
      .if eax != FALSE && MenuInfo.dwItemData != NULL
        mov xdx, MenuInfo.dwItemData
        OCall xsi.SendHelp, [xdx].$Obj(XMenuItem).pHelpStr
      .endif
    .endif
    xor eax, eax
  .else
    xor eax, eax
    inc eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnSettingChange
; Purpose:    Event procedure for WM_SETTINGCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, it returns zero.

Method XMenu.OnSettingChange, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XMenu.OnSettingChange"
  SetObject xsi
  .if wParam == SPI_SETNONCLIENTMETRICS
    OCall xsi.UpdateFonts
    OCall [xsi].MenuItemColl::Collection.DisposeAll     ;Remove all information
    OCall xsi.Convert, [xsi].hMenu, TRUE                ;Convert main menu
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_SETTINGCHANGE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.OnSysColorChange
; Purpose:    Event procedure for WM_SYSCOLORCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, it returns zero.
; Note:       If the background MenuBar color was changed, the system default is set again.

Method XMenu.OnSysColorChange, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "XMenu.OnSysColorChange"
  SetObject xsi
  ;Reload system color
  mov [xsi].MenuBarBkColor, $32($invoke(GetSysColor, COLOR_MENUBAR))  ;This is the default color
  OCall xsi.SetMenuBarBkColor, eax
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_SYSCOLORCHANGE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    XMenu.UpdateFonts
; Purpose:   Create or rebuilds the menu fonts.
; Arguments: Arg1: Main menu handle.
; Return:    Nothing.

Method XMenu.UpdateFonts, uses xsi
  local hDC:HDC, NCM:NONCLIENTMETRICS

  SetObject xsi
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  mov NCM.cbSize, sizeof(NONCLIENTMETRICS)
  invoke SystemParametersInfo, SPI_GETNONCLIENTMETRICS, NCM.cbSize, addr NCM, FALSE
  mov NCM.lfMenuFont.lfQuality, CLEARTYPE_QUALITY

  .if [xsi].hFontTxtNorm != 0
    invoke DeleteObject, [xsi].hFontTxtNorm
  .endif
  mov [xsi].hFontTxtNorm, $invoke(CreateFontIndirect, addr NCM.lfMenuFont)

  .if [xsi].hFontTxtBold != 0
    invoke DeleteObject, [xsi].hFontTxtBold
  .endif
  mov NCM.lfMenuFont.lfWeight, FW_BOLD
  mov [xsi].hFontTxtBold, $invoke(CreateFontIndirect, addr NCM.lfMenuFont)

  .if [xsi].hFontSep != 0
    invoke DeleteObject, [xsi].hFontSep
  .endif
  ;Don't shrink the font less than size 7
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 8, eax, -72
  mov NCM.lfMenuFont.lfWeight, FW_NORMAL
  mov ecx, NCM.lfMenuFont.lfHeight
  neg ecx
  lea ecx, [2*ecx + ecx]
  shr ecx, 2
  neg ecx
  .if sdword ptr eax < ecx
    mov ecx, eax
  .endif
  mov NCM.lfMenuFont.lfHeight, ecx
  mov [xsi].hFontSep, $invoke(CreateFontIndirect, addr NCM.lfMenuFont)

  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.SendHelp
; Purpose:    Invoke HelpCallback procedure.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method XMenu.SendHelp, uses xsi, pHelpStr:PSTRING
  SetObject xsi
  .if [xsi].pHelpCallback != NULL
    invoke HelpCallbackPto ptr [xsi].pHelpCallback, [xsi].pOwner, pHelpStr
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.SetMenuBarBkColor
; Purpose:    Set the drawing background color of the menubar.
; Arguments:  Arg1: RGBQUAD.
; Return:     Nothing.

Method XMenu.SetMenuBarBkColor, uses xsi, Color:RGBQUAD
  local MenuInfo:MENUINFO

  SetObject xsi
  m2m [xsi].MenuBarBkColor, Color, eax
  invoke CreateSolidBrush, eax
  mov MenuInfo.cbSize, sizeof(MenuInfo)
  mov MenuInfo.hbrBack, xax
  mov MenuInfo.fMask, MIM_BACKGROUND

  invoke GetMenu, [xsi].hWnd
  lea xdx, MenuInfo
  invoke SetMenuInfo, xax, xdx
  invoke DeleteObject, MenuInfo.hbrBack
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.WindowMenuCreate
; Purpose:    Convert a Window menu to ownerdraw.
; Arguments:  Arg1: Window menu handle.
; Return:     Nothing.

Method XMenu.WindowMenuCreate, uses xbx xdi xsi, hMenu:HMENU
  local dFlag:DWORD, MenuInfo:MENUITEMINFO, cBuffer[256]:CHR, sdItemIndex:SDWORD

;  DbgText "XMenu.WindowMenuCreate"
  SetObject xsi
  invoke GetMenuItemCount, hMenu                        ;If hMenu = NULL => retuns -1
  .if eax != -1
    mov sdItemIndex, eax                                ;Save count in eax
    mov MenuInfo.cbSize, sizeof(MenuInfo)               ;and exits in the While loop!
    lea xdi, MenuInfo
    m2z dFlag                                           ;If TRUE => exit while loop
    lea xdi, MenuInfo
    .while (sdItemIndex > 0) && (dFlag == FALSE)
      dec sdItemIndex
      mov MenuInfo.dwTypeData, $addr(cBuffer)           ;Set -> cBuffer
      mov MenuInfo.fMask, MIIM_FTYPE or MIIM_STRING or MIIM_DATA or MIIM_ID
      mov MenuInfo.cch, lengthof cBuffer                ;Set size of cBuffer in each loop!
      invoke GetMenuItemInfo, hMenu, sdItemIndex, MF_BYPOSITION, xdi
      .if MenuInfo.dwItemData == NULL                   ;if not converted
        .ifBitSet MenuInfo.fType, MFT_SEPARATOR
          FillString cBuffer, <-|>                      ;Create a separator line
          mov ecx, [xsi].dLanguage
          add ecx, MENU_WINDOW_LIST
          lea xax, cBuffer
          add xax, 2*sizeof(CHR)
          mov edx, ecx
          invoke LoadString, hInstance, edx, xax, lengthof(cBuffer) - 3
          mov dFlag, TRUE
        .elseif MenuInfo.wID == MENU_WINDOW_MORE        ;More windows...
          mov edx, [xsi].dLanguage
          add edx, MENU_WINDOW_MORE
          invoke LoadString, hInstance, edx, addr cBuffer, lengthof(cBuffer) - 1
          .if eax != 0
            FillString cBuffer, <$50009>
          .else
            FillString cBuffer, <...>
          .endif
        .else
          lea xbx, cBuffer
          invoke StrSize, xbx
          mov xdx, xbx
          mov xcx, xdx
          add xcx, sizeof(DCHR)
          invoke MemShift, xcx, xdx, eax
          if TARGET_STR_TYPE eq STR_TYPE_ANSI
            mov ax, "|o"
          else
            mov eax, "|"*65536 + "o"
          endif
          mov [xbx], $SubReg(xax, sizeof(DCHR))
        .endif

        mov MenuInfo.fMask, MIIM_FTYPE or MIIM_STRING
        mov MenuInfo.fType, MFT_STRING                  ;Always MFT_STRING
        mov MenuInfo.dwTypeData, $addr(cBuffer)
        invoke StrLength, xax
        mov MenuInfo.cch, eax
        invoke SetMenuItemInfo, hMenu, sdItemIndex, MF_BYPOSITION, xdi ;Store new menu info
      .endif
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.WindowMenuRemove
; Purpose:    Remove all child window items from a Window menu.
; Arguments:  Arg1: Window menu handle.
; Return:     Nothing.

Method XMenu.WindowMenuRemove, uses xdi xsi, hMenu:HMENU
  local dDeleteNextItem:DWORD, MenuInfo:MENUITEMINFO, sdItemIndex:SDWORD

;  DbgText "XMenu.WindowMenuRemove"
  SetObject xsi
  invoke GetMenuItemCount, hMenu                        ;If hMenu = NULL => retuns -1
  .if eax != -1
    mov sdItemIndex, eax
    mov MenuInfo.cbSize, sizeof(MenuInfo)               ;and exits in the While loop!
    lea xdi, MenuInfo

    ;Remove all converted MenuItems in the ID range 50000..50009 in reverse order
    m2z dDeleteNextItem                                 ;If TRUE => remove next menu item
    .while (sdItemIndex > 0)
      dec sdItemIndex
      mov MenuInfo.fMask, MIIM_DATA or MIIM_ID
      invoke GetMenuItemInfo, hMenu, sdItemIndex, MF_BYPOSITION, xdi
      .if (dDeleteNextItem != FALSE) || (MenuInfo.wID >= 50000) && (MenuInfo.wID <= 50009)
        .if MenuInfo.dwItemData != NULL                 ;if converted
          OCall [xsi].MenuItemColl::Collection.Dispose, MenuInfo.dwItemData
        .endif
        .if MenuInfo.wID == 50000
          mov dDeleteNextItem, TRUE                     ;Remove next (Separator)
        .else
          m2z dDeleteNextItem
        .endif
        invoke RemoveMenu, hMenu, sdItemIndex, MF_BYPOSITION  ;Remove it
      .endif
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenu.WndProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window HANDLE passed in pSelf.
; Return:     eax = This value is the result of the message processing and depends on the message ID.

Method XMenu.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "XMenu"
  invoke GetProp, pSelf, offset szPropXMenu
;  ASSERT xax, "XMenu.WndProc failed to retrieve windows property"
  OCall xax::XMenu.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;    XMdiMenu implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMdiMenu.Init
; Purpose:    Initialaize XMdiMenu.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Client window HANDLE.
;             Arg3: Window popup menu HANDLE.
;             Arg4: -> Property name.
; Return:     Nothing.

Method XMdiMenu.Init,, pOwner:POINTER, hWnd:HWND, hWindowMenu:HMENU, pPropName:PSTRING
  SetObject xcx
  m2m [xcx].hWindowMenu, hWindowMenu, xax
  ACall xcx.Init, pOwner, hWnd, pPropName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMdiMenu.OnMdiSetMenu
; Purpose:    Event procedure for WM_MDISETMENU message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method XMdiMenu.OnMdiSetMenu, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam
    ;Free resources
    mov xdi, [xsi].pOwner
    OCall [xdi].$Obj(XMenu).MenuItemColl::Collection.DisposeAll

    ;Convert new main menu
    mrm [xdi].$Obj(XMenu).hMenu, wParam, xax
    OCall xdi::XMenu.Convert, xax, TRUE
  .endif

  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_MDISETMENU, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMdiMenu.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window HANDLE passed in pSelf.
; Return:     eax = This value is the result of the message processing and depends on the message ID.

Method XMdiMenu.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "XMdiMenu"
  invoke GetProp, pSelf, offset szPropXMenu
;  ASSERT xax, "XMdiMenu.WndProc failed to retrieve windows property"
  OCall xax::XMdiMenu.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;    XMenuSelectDlg implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenuSelectDlg.CtlsGet
; Purpose:    Set the items in the listview.
; Arguments:  None.
; Return:     Nothing.

Method XMenuSelectDlg.CtlsGet, uses xsi
  SetObject xsi
  invoke SendMessage, [xsi].hListBox, LB_GETCURSEL, 0, 0
  .if eax != LB_ERR
    invoke SendMessage, [xsi].hListBox, LB_GETITEMDATA, eax, 0
    .if eax != 0
      mov xdx, [xsi].pOwner
      invoke SendMessage, [xdx].$Obj(XMenu).hMdiClientWnd, WM_MDIACTIVATE, eax, 0
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SelectDlgEnumProc (Callback)
; Purpose:    Select dialog fill procedure.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed to the enumeration procedure.
; Return:     eax = TRUE to continue enumerating.

SelectDlgEnumProc proc uses xsi hWnd:HWND, pSelf:$ObjPtr(XMenuSelectDlg)
  local cBuffer[256]:CHR, dIndex:DWORD

  ANNOTATION use:pSelf

  SetObject xsi, XMenuSelectDlg
  invoke GetParent, hWnd
  mov xcx, [xsi].pOwner
  .if xax == [xcx].$Obj(XMenu).hMdiClientWnd
    invoke GetWindowText, hWnd, addr cBuffer, lengthof(cBuffer) - 1
    invoke SendMessage, [xsi].hListBox, LB_ADDSTRING, 0, addr cBuffer   ;Set child caption
    mov dIndex, eax
    invoke SendMessage, [xsi].hListBox, LB_SETITEMDATA, dIndex, hWnd    ;Remember hWnd
    mov xcx, hWnd
    .if xcx == [xsi].hActiveWnd
      invoke SendMessage, [xsi].hListBox, LB_SETCURSEL, dIndex, 0
    .endif
  .endif
  mov eax, TRUE                                         ;TRUE => next window
  ret
SelectDlgEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenuSelectDlg.CtlsSet
; Purpose:    Read the selected item in the Listview.
; Arguments:  None.
; Return:     Nothing.

Method XMenuSelectDlg.CtlsSet, uses xdi xsi
  local cBuffer[256]:CHR

  SetObject xsi
  mov [xsi].hListBox, $invoke(GetDlgItem, [xsi].hWnd, XMENU_SELECTLISTBOX_ID)
  mov xdi, [xsi].pOwner
  mov [xsi].hActiveWnd, $invoke(SendMessage, [xdi].$Obj(XMenu).hMdiClientWnd, WM_MDIGETACTIVE, 0, NULL)
  invoke EnumChildWindows, [xdi].$Obj(XMenu).hMdiClientWnd, offset SelectDlgEnumProc, xsi
  invoke SendMessage, [xsi].hListBox, LB_GETCURSEL, 0, 0
  invoke SendMessage, [xsi].hListBox, LB_SETTOPINDEX, eax, 0

  ;Set the dialog caption according to the language selection
  mov ecx, [xdi].$Obj(XMenu).dLanguage
  add ecx, MENU_WINDOW_MORE
  mov edx, ecx
  invoke LoadString, hInstance, edx, addr cBuffer, lengthof(cBuffer) - 1
  .if eax != 0
    invoke StrLScan, addr cBuffer, MENU_CHAR_LITERAL
    .if xax != NULL
      add xax, sizeof(CHR)
      invoke SetWindowText, [xsi].hWnd, xax
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XMenuSelectDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method XMenuSelectDlg.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  HiWord wParam
  .if ax == LBN_DBLCLK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, 0
  .else
    ACall xsi.OnCommand, wParam, lParam
  .endif
MethodEnd

endif
