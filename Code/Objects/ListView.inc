; ==================================================================================================
; Title:      ListView.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support ListView controls based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_LISTVIEW struc
  xCtlID        XWORD     ?   ;Contol ID
  dStyle        DWORD     ?   ;Style
  dExStyle      DWORD     ?   ;Extended style
  pTitle        PSTRING   ?   ;-> Window caption
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?   ;X position
      sdPosY    SDWORD    ?   ;Y position
      dWidth    DWORD     ?   ;Width
      dHeight   DWORD     ?   ;Height
    ends
  ends
  dColumnCount  DWORD     ?   ;Number of columns in the ListView control
DEF_LISTVIEW ends
PDEF_LISTVIEW typedef ptr DEF_LISTVIEW


LVHDRFONTBOLD         equ     BIT00
LVHDRFONTITALIC       equ     BIT01
LVHDRFONTUNDERLINE    equ     BIT02
LVHDRFONTSTRIKEOUT    equ     BIT03

; --------------------------------------------------------------------------------------------------
; Object:     ListView
; Purpose:    Implement a thin wrapper around the SysListView32 GDI control.

Object ListView, ListViewID, WinControl                           ;Class "SysListView32"
  VirtualMethod     CheckItem,          DWORD, DWORD
  RedefineMethod    Done
  VirtualMethod     HeaderSetFontStyle, DWORD
  VirtualMethod     HeaderSetFlatStyle, DWORD
  RedefineMethod    Init,               POINTER, HWND, PDEF_LISTVIEW
  VirtualMethod     IsItemChecked,      DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnNotify,           WM_NOTIFY

  DefineVariable    hHeaderFont,        HFONT,   0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     ListView.CheckItem
; Purpose:    Set the state of the items checkbox of the ListView control.
; Arguments:  Arg1: Item index.
;             Arg2: TRUE/FALSE.
; Return:     eax = TRUE if successful or FALSE otherwise.

Method ListView.CheckItem, uses xsi, dItemIndex:DWORD, dAction:DWORD
  local LVI:LV_ITEM

  SetObject xsi
  mov LVI.stateMask, LVIS_STATEIMAGEMASK
  .if dAction == FALSE
    BitSet LVI.state, BIT12
    BitClr LVI.state, BIT13 or BIT14 or BIT15
  .else
    BitSet LVI.state, BIT13
    BitClr LVI.state, BIT12 or BIT14 or BIT15
  .endif
  invoke SendMessage, [xsi].hWnd, LVM_SETITEMSTATE, dItemIndex, addr LVI
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.Done
; Purpose:    Finalize the ListView object.
; Arguments:  None.
; Return:     Nothing.

Method ListView.Done, uses xsi
  SetObject xsi
  Unsubclass ListView                                   ;Uses xsi
  .if [xsi].hHeaderFont != 0
    invoke DeleteObject, [xsi].hHeaderFont
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.HeaderSetFontStyle
; Purpose:    Set the font style of the header of the ListView control.
; Arguments:  Arg1: Font style flags.
; Return:     Nothing.

Method ListView.HeaderSetFontStyle, uses xsi, dFontStyle:DWORD
  local hHeader:HANDLE, hFont:HFONT, LogFont:LOGFONT

  SetObject xsi
  mov hHeader, $invoke(SendMessage, [xsi].hWnd, LVM_GETHEADER, 0, 0)
  .if [xsi].hHeaderFont == 0
    mov hFont, $invoke(SendMessage, hHeader, WM_GETFONT, 0, 0)
  .else
    m2m hFont, [xsi].hHeaderFont, xax
  .endif
  invoke GetObject, hFont, sizeof LogFont, addr LogFont
  .if xax != 0
    .ifBitSet dFontStyle, LVHDRFONTBOLD
      mov LogFont.lfWeight, FW_BOLD
    .else
      mov LogFont.lfWeight, FW_NORMAL
    .endif

    .ifBitSet dFontStyle, LVHDRFONTITALIC
      mov LogFont.lfItalic, TRUE
    .else
      m2z LogFont.lfItalic
    .endif

    .ifBitSet dFontStyle, LVHDRFONTUNDERLINE
      mov LogFont.lfUnderline, TRUE
    .else
      m2z LogFont.lfUnderline
    .endif

    .ifBitSet dFontStyle, LVHDRFONTSTRIKEOUT
      mov LogFont.lfStrikeOut, TRUE
    .else
      m2z LogFont.lfStrikeOut
    .endif

    .if [xsi].hHeaderFont != 0
      invoke DeleteObject, [xsi].hHeaderFont
    .endif

    mov [xsi].hHeaderFont, $invoke(CreateFontIndirect, addr LogFont)
    invoke SendMessage, hHeader, WM_SETFONT, [xsi].hHeaderFont, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.HeaderSetFlatStyle
; Purpose:    Set the flat style of the header of the ListView control.
; Arguments:  Arg1: TRUE/FALSE.
; Return:     Nothing.

Method ListView.HeaderSetFlatStyle,, dFlatStyle:DWORD
  local hHeader:HANDLE, dStyle:DWORD

  SetObject xcx
  mov hHeader, $invoke(SendMessage, [xcx].hWnd, LVM_GETHEADER, 0, 0)
  mov dStyle, $32($invoke(GetWindowLongPtr, hHeader, GWL_STYLE))
  .if dFlatStyle == FALSE
    BitSet dStyle, HDS_BUTTONS
  .else
    BitClr dStyle, HDS_BUTTONS
  .endif
  invoke SetWindowLongPtr, hHeader, GWL_STYLE, dStyle
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.Init
; Purpose:    Initialize the ListView control.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_LISTVIEW definition structure.
; Return:     Nothing.

Method ListView.Init, uses xbx xdi xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_LISTVIEW
  local dCount:DWORD

  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_LISTVIEW
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  invoke CreateWindowEx, 0, $OfsCStr("SysListView32"), [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, 0
  ACall xsi.Init, pOwner, xax
  invoke SendMessage, [xsi].hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, \
                      [xbx].dExStyle, [xbx].dExStyle
  m2z dCount
  mov edi, [xbx].dColumnCount
  assume xbx:NOTHING
  add xbx, sizeof DEF_LISTVIEW
  .while dCount < edi
    invoke SendMessage, [xsi].hWnd, LVM_INSERTCOLUMN, dCount, xbx
    add xbx, sizeof LV_COLUMN
    inc dCount
  .endw
  Subclass ListView                                     ;Uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.IsItemChecked
; Purpose:    Return the state of the items checkbox of the ListView control.
; Arguments:  Arg1: Item index.
; Return:     eax = TRUE/FALSE.

Method ListView.IsItemChecked,, dItemIndex:DWORD
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, LVM_GETITEMSTATE, dItemIndex, LVIS_STATEIMAGEMASK
  .ifBitSet eax, BIT13
    mov eax, TRUE
  .else
    xor eax, eax                                        ;eax = FALSE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = HDN_GETDISPINFO return vaue.

Method ListView.OnNotify, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "ListView.OnNotify"
  SetObject xsi
  mov xax, lParam
  .if [xax].NMHDR.code == HDN_GETDISPINFO
    ;Send this message to the LV parent
    ;Note: some versions of Common Controls doesn't forward the HDN_GETDISPINFO notification to
    ;      the parent window! Since version 6.0 there is not an issue.
    mov xbx, xax
    invoke GetParent, [xsi].hWnd
    invoke SendMessage, xax, WM_NOTIFY, wParam, lParam
    .if xbx != 0
      ;If we don't succeed to get the information, let the OS handle the situation.
      ;That means that Common Controls >= 6.0 sends an ANSI request HDN_GETDISPINFO.
      invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
    .endif
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ListView.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method ListView.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg, , "ListView Messages"
  GetSubclassingInst ListView, pSelf
  OCall xax::ListView.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
