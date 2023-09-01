; ==================================================================================================
; Title:      DebugCenter_ChildTxt.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter text MDI child window.
; ==================================================================================================


EDTSTYLE    equ     WS_CHILD or WS_VISIBLE or WS_TABSTOP or \
                    WS_VSCROLL or WS_HSCROLL or ES_AUTOVSCROLL or ES_AUTOHSCROLL or \
                    ES_MULTILINE or ES_WANTRETURN or ES_NOHIDESEL

RICHEDITID  equ     250

CStr szDbgMdiChildTxtClass, "OAC_DbgMdiChildTxt"                ;Debug Center Child Textoutput
CStr szPropREdtIptor,       "OAP_REdtIptor"

CALC_KEY_TIMEOUT  equ   1000


; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object REdtIptor, REDT_IPTOR_ID, MsgInterceptor
  VirtualMethod     OpenSciCalc
  VirtualMethod     SendToCalc
  RedefineMethod    WndProc,          DWORD, WPARAM, LPARAM

  VirtualEvent      OnDropFiles,      WM_DROPFILES
  VirtualEvent      OnNotify,         WM_NOTIFY
  VirtualEvent      OnRButtonDown,    WM_RBUTTONDOWN
  VirtualEvent      OnRButtonUp,      WM_RBUTTONUP

  DefineVariable    hCalcWnd,         HWND,       0             ;Calculator window handle
  DefineVariable    hCalcEditWnd,     HWND,       0             ;Calculator Edit window handle
  DefineVariable    hCalcPrc,         HANDLE,     0             ;Calculator process handle
  DefineVariable    pFindDialog,      $ObjPtr(DialogFindText), NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DbgMdiChildTxt, DBG_MDI_CHILD_TXT_ID, DbgMdiChild
  RedefineMethod    ClpBrdClear
  RedefineMethod    ClpBrdCopy
  RedefineMethod    ClpBrdCut
  RedefineMethod    ClpBrdPaste
  RedefineMethod    ClpBrdSetBtns
  RedefineMethod    Erase
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, PSTRINGW, HFONT, DWORD
  RedefineMethod    OnMdiActivate,    WPARAM, LPARAM
  RedefineMethod    OnSize,           WPARAM, LPARAM
  RedefineMethod    Open,             PSTRING
  RedefineMethod    Print
  RedefineMethod    SaveAs,           PSTRING, PSTRING          ;-> Filter, -> Def. extension
  RedefineMethod    SaveTo,           PSTRING
  VirtualMethod     SelectAll
  StaticMethod      Startup
  RedefineMethod    ZoomIn
  RedefineMethod    ZoomOut

  VirtualEvent      OnCreate,         WM_CREATE
  VirtualEvent      OnNotify,         WM_NOTIFY

  DefineVariable    hEdit,            HWND,               0
  DefineVariable    pEdtIptor,        $ObjPtr(REdtIptor), NULL
ObjectEnd


; ==================================================================================================
;    DbgMdiChildTxt implementation
; ==================================================================================================

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ClpBrdClear
; Purpose:    Delete the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ClpBrdClear, uses xsi
  local dNumerator:DWORD, dDenominator:DWORD

  SetObject xsi
  ;Remember the current RichEdit zoom factor
  invoke SendMessage, [xsi].hEdit, EM_GETZOOM, addr dNumerator, addr dDenominator
  .if eax != FALSE
    mov [xsi].dZoomFactor, $32($invoke(MulDiv, dNumerator, ZOOM_BASE, dDenominator))
  .endif
  invoke SendMessage, [xsi].hEdit, WM_CLEAR, 0, 0
  ACall ClpBrdClear
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ClpBrdCopy
; Purpose:    Copy the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ClpBrdCopy
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_COPY, 0, 0
  ACall ClpBrdCopy
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ClpBrdCut
; Purpose:    Cut the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ClpBrdCut
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_CUT, 0, 0
  ACall ClpBrdCut
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ClpBrdPaste
; Purpose:    Paste the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ClpBrdPaste
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_PASTE, 0, 0
  ACall ClpBrdPaste
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ClpBrdSetBtns
; Purpose:    Set the cut, copy & paste clipboard buttons.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ClpBrdSetBtns, uses xbx xdi xsi
  local dBegPos:DWORD, dEndPos:DWORD, hMenu:HMENU, dActivate:DWORD

  SetObject xsi
  invoke SendMessage, [xsi].hEdit, EM_GETSEL, addr dBegPos, addr dEndPos
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(DbgMdiClient).pOwner
  mov hMenu, $invoke(GetMenu, [xdi].$Obj(DebugCenter).hWnd)           ;Get the current menu
  mov eax, dEndPos
  .if eax == dBegPos
    mov xbx, [xdi].$Obj(DebugCenter).pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
    mov xbx, $ObjTmpl(DebugCenter).hMenuContext
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
  .else
    mov xbx, [xdi].$Obj(DebugCenter).pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, TRUE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_ENABLED
    mov xbx, $ObjTmpl(DebugCenter).hMenuContext
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_ENABLED
  .endif

  mov dActivate, TRUE
  .if !$invoke(IsClipboardFormatAvailable, CF_TEXT)
    dec dActivate
  .endif

  mov xbx, [xdi].$Obj(DebugCenter).pToolbarEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, dActivate
  .if dActivate
    mov edi, MF_BYCOMMAND or MF_ENABLED
  .else
    mov edi, MF_BYCOMMAND or MF_GRAYED
  .endif
  invoke EnableMenuItem, hMenu, IDM_EDIT_PASTE, edi
  invoke EnableMenuItem, $ObjTmpl(DebugCenter).hMenuContext, IDM_EDIT_PASTE, edi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.Done
; Purpose:    Finalize the DbgMdiChildTxt object.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pEdtIptor
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.Erase
; Purpose:    Erase the content of the window.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.Erase, uses xsi
  SetObject xsi
  invoke SendMessage, [xsi].hEdit, EM_SETSEL, 0, -1
  OCall xsi.ClpBrdClear
  DbgHex [xsi].dZoomFactor
  invoke SendMessage, [xsi].hEdit, EM_SETZOOM, [xsi].dZoomFactor, TXT_ZOOM_BASE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgMdiChildTxt_WordBreak_Callback
; Purpose:    Callback proc to to break a line of text.
; Arguments:  Arg1: -> Wide character Buffer.
;             Arg2: Current character index.
;             Arg3: Number of BYTEs in the buffer.
;             Arg4: Action to be taken [WB_LEFT..WB_RIGHTBREAK].
; Return:     Nothing.
; Link:       https://docs.microsoft.com/en-us/windows/win32/controls/use-word-and-line-break-information
; Notes:      The char buffer passed to this callback has a very limitid size (usually 20 BYTE).
;             The content of the buffer are always WIDE charaters.
;             It is possible that the callback will be called many times until the goal is achieved.
;             This happens, for example, if an index = 0 is returned, which means that the word break
;             is not found.
;             Thanks to this behavior and the lack of an lParam to store additional information,
;             the implementation has to work on its own, which is somewhat difficult to code.
;             From my observations, only WB_MOVEWORDLEFT and WB_MOVEWORDRIGHT are used.

.const
RE_WordBreakLUT label CHRA                              ;Word break character lookup table
  ;     NUL  SOH  STX  ETX  EDT  ENQ  ACK  BEL  BS   TAB  LF   VF   FF   CR   SO   SI
  CHRA 000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,001h,000h,000h
  ;     DLE  DC1  DC2  DC3  DC4  NAK  SYN  ETB  CAN  BM   SUB  ESC  FS   GS   RS   US
  CHRA 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  ;     SPC   !    "    #    $    %    &    '    (    )    *    +    ,    -    .    /
  CHRA 001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,000h,001h  ;#, $
  ;      0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
  CHRA 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,001h,001h  ;0..9, ?
  ;      @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
  CHRA 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h  ;@, A..O
  ;      P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]    ^    _
  CHRA 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,000h  ;P..Z, _
  ;      `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
  CHRA 001h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h  ;a..o
  ;      p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~
  CHRA 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,000h  ;p..z

.code
DbgMdiChildTxt_WordBreak_Callback proc uses xbx xsi pCharBuffer:POINTER, \
                                           dCharIndex:DWORD, dByteCount:DWORD, dCode:DWORD
  .if dCode == WB_LEFT                                  ;0
    xor eax, eax
  .elseif dCode == WB_RIGHT                             ;1
    xor eax, eax
  .elseif dCode == WB_ISDELIMITER                       ;2
    xor eax, eax
  .elseif dCode == WB_CLASSIFY                          ;3
    xor eax, eax
  .elseif dCode == WB_MOVEWORDLEFT                      ;4 = WB_MOVEWORDPREV
    mov eax, dCharIndex
    mov xsi, pCharBuffer
    dec eax
    mov xbx, offset RE_WordBreakLUT

    ;If we start with a non-break char
    movzx xdx, CHRW ptr [xsi + sizeof(CHRW)*xax]
    .if ((xdx >= 128) || ((xdx < 128) && (CHRA ptr [xbx + xdx] == 0)))
      ;Search first break char
      .while eax != 0
        movzx xdx, CHRW ptr [xsi + sizeof(CHRW)*xax]
        .if ((xdx < 128) && (CHRA ptr [xbx + xdx] == 1))
          inc eax
          .break
        .endif
        dec eax
      .endw
    .else
      ;Search first non-break char
      .while eax != 0
        movzx xdx, CHRW ptr [xsi + sizeof(CHRW)*xax]
        .if ((xdx >= 128) || ((xdx < 128) && (CHRA ptr [xbx + xdx] == 0)))
          inc eax
          .break
        .endif
        dec eax
      .endw
    .endif

  .elseif dCode == WB_MOVEWORDRIGHT                     ;5 = WB_MOVEWORDNEXT
    mov eax, dCharIndex
    mov xsi, pCharBuffer
    mov ecx, dByteCount
    mov xbx, offset RE_WordBreakLUT
    shr ecx, 1                                          ;ecx = # of chars

    ;If we start with a non-break char
    movzx xdx, CHRW ptr [xsi + sizeof(CHRW)*xax]
    .if ((xdx >= 128) || ((xdx < 128) && (CHRA ptr [xbx + xdx] == 0)))
    ;Search first break char
      .while eax != ecx
        movzx xdx, CHRW ptr [xsi + sizeof(CHRW)*xax]
        .break .if ((xdx < 128) && (CHRA ptr [xbx + xdx] == 1))
        inc eax
      .endw
    .else
      ;Search first non-break char
      .while eax != ecx
        movzx xdx, CHRW ptr [xsi + sizeof(CHRW)*xax]
        .break .if ((xdx >= 128) || ((xdx < 128) && (CHRA ptr [xbx + xdx] == 0)))
        inc eax
      .endw
    .endif
  .elseif dCode == WB_LEFTBREAK                         ;6 = WB_PREVBREAK
    xor eax, eax
  .elseif dCode == WB_RIGHTBREAK                        ;7 = WB_NEXTBREAK
    xor eax, eax
  .else
    xor eax, eax
  .endif
  ret
DbgMdiChildTxt_WordBreak_Callback endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.Init
; Purpose:    Initialize the DbgMdiChildTxt object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Title string.
;             Arg3: Font HANDLE to use.
;             Arg4: Background RGB color value.
; Return:     Nothing.

Method DbgMdiChildTxt.Init, uses xbx xdi xsi, pOwner:POINTER, pTitle:PSTRINGW, hFont:HFONT, dBackColor:DWORD
  local cMsg[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc

  mov xdi, pOwner
  invoke CreateMDIWindow, offset szDbgMdiChildTxtClass, pTitle, 0, \
                          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(DbgMdiClient).hWnd, hInstance, pSelf
  .if xax != 0
    invoke SendMessage, [xsi].hEdit, EM_SETBKGNDCOLOR, 0, dBackColor
    invoke SendMessage, [xsi].hEdit, WM_SETFONT, hFont, FALSE

    ;Set our new WordBreak procedure
    invoke SendMessage, [xsi].hEdit, EM_SETWORDBREAKPROC, 0, offset DbgMdiChildTxt_WordBreak_Callback

    ;Manage the main Menu
    inc [xdi].$Obj(DbgMdiClient).dChildCount
    mov xbx, [xdi].$Obj(DbgMdiClient).pOwner
    .if [xdi].$Obj(DbgMdiClient).dChildCount == 1       ;First child window ?
      invoke SendMessage, [xbx].$Obj(DebugCenter).hWnd, WM_CANCELMODE, 0, 0 ;Close any opened submenu
      invoke SendMessage, [xdi].$Obj(DbgMdiClient).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(DebugCenter).hMenuChild, [xbx].$Obj(DebugCenter).hMenuChildWnd
      OCall xbx::DebugCenter.EnableActions, TRUE
      invoke DrawMenuBar, [xbx].$Obj(DebugCenter).hWnd  ;Redraw the new menu bar
      OCall xbx::DebugCenter.ManageOptions, DBG_MDI_CHILD_TXT_ID
    .endif

    ;Install Magnetism
    mov [xsi].pMagnetism, $New(Magnetism)
    OCall [xsi].pMagnetism::Magnetism.Init, xsi, [xsi].hWnd, 10

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  .else
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 125
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xbx].$Obj(DebugCenter).hWnd, addr cMsg, offset szError, \
                       MB_OK or MB_ICONERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

ES_EX_ZOOMABLE equ 0010h

Method DbgMdiChildTxt.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_CLIENTEDGE or WS_EX_ACCEPTFILES or ES_EX_ZOOMABLE, \
                         offset szRichEdit20, NULL, EDTSTYLE, \
                         0, 0, 10, 10, [xsi].hWnd, RICHEDITID, hInstance, NULL
  mov [xsi].hEdit, xax
  invoke SendMessage, [xsi].hEdit, EM_SETEVENTMASK, 0, ENM_SELCHANGE
  invoke SendMessage, [xsi].hEdit, EM_SETZOOM, $ObjTmpl(DebugCenter).dTxtZoomFactor, ZOOM_BASE

  mov [xsi].pEdtIptor, $New(REdtIptor)
  OCall xax::REdtIptor.Init, xsi, [xsi].hEdit, offset szPropREdtIptor
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.OnMdiActivate
; Purpose:    Event procedure for WM_MDIACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildTxt.OnMdiActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local pChild:POINTER

  ;Close Find text dialog if switched to another child
  SetObject xsi
  .if wParam != 0
    mov pChild, $invoke(SendMessage, wParam, WM_GETOBJECTINSTANCE, 0, 0)
    invoke GetObjectID, xax
    .if eax == DBG_MDI_CHILD_TXT_ID
      mov xcx, pChild
      mov xax, [xcx].$Obj(DbgMdiChildTxt).pEdtIptor
      .if [xax].$Obj(REdtIptor).pFindDialog != NULL
        mov xcx, [xax].$Obj(REdtIptor).pFindDialog
        invoke SendMessage, [xcx].$Obj(DialogFindText).hWnd, WM_CLOSE, 0, 0
      .endif
    .endif
  .endif

  ACall xsi.OnMdiActivate, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildTxt.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, lParam
  .if [xax].NMHDR.code == EN_SELCHANGE
    mov xdx, [xax].NMHDR.idFrom
    .if xdx == RICHEDITID
      mov xcx, [xsi].pOwner
      invoke SendMessage, [xcx].$Obj(DbgMdiClient).hWnd, WM_MDIGETACTIVE, 0, 0
      .if xax == [xsi].hWnd
        OCall xsi.ClpBrdSetBtns
        xor eax, eax
        ExitMethod
      .endif
    .endif
  .endif
  mov eax, 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DbgMdiChildTxt.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  .if wParam != SIZE_MINIMIZED
    invoke GetClientRect, [xsi].hWnd, addr CRect
    invoke MoveWindow, [xsi].hEdit, 0, 0, CRect.right, CRect.bottom, TRUE
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.Open
; Purpose:    Load the content of a txt file.
; Arguments:  Arg1: -> File Name.
; Return:     Nothing.

REOpenText proc pStream:$ObjPtr(Stream), pBuffer:POINTER, dNumBytes:DWORD, pBytesTransferred:POINTER
  OCall pStream::DiskStream.BinRead, pBuffer, dNumBytes
  mov xcx, pBytesTransferred
  mov [xcx], eax
  xor eax, eax
  ret
REOpenText endp

Method DbgMdiChildTxt.Open, uses xsi, pFileName:PSTRING
  local pStream:$ObjPtr(Stream), EdtStrm:EDITSTREAM, cMsg[1024]:CHR

  SetObject xsi
  mov pStream, $New(DiskStream)
  OCall pStream::DiskStream.Init, xsi, pFileName, 0, 0, NULL, 0, 0, 0
  m2m EdtStrm.dwCookie, pStream, xax
  m2z EdtStrm.dwError
  c2m EdtStrm.pfnCallback, offset REOpenText, xax
  invoke SendMessage, [xsi].hEdit, EM_STREAMIN, SF_RTF, addr EdtStrm
  .if EdtStrm.dwError != 0
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 121
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, \
                       MB_OK or MB_ICONERROR
  .endif
  Destroy pStream
  ACall xsi.Open, pFileName                             ;Remenber this file name
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.Print
; Purpose:    Print the content of a TxtChild.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.Print, uses xbx xdi xsi
  local PrtDlg:PRINTDLG, DocInfo:DOCINFO, cMsg[1024]:CHR
  local LogFnt:LOGFONT, hFont:HFONT, hPrvFont:HFONT, dLineCount:DWORD
  local cPrtBuffer[256]:CHR, dPosY:DWORD, TM:TEXTMETRIC
  local LogPix:POINT, PageSize:POINT, PageOffset:POINT, PrintSize:POINT

  SetObject xsi

  mov PrtDlg.lStructSize, sizeof(PrtDlg)
  m2m PrtDlg.hwndOwner, [xsi].hWnd, xax
  mov xdx, [xsi].pOwner
  mov xbx, [xdx].$Obj(DbgMdiClient).pOwner
  m2m PrtDlg.hDevMode, [xbx].$Obj(DebugCenter).hDevMode, xdx
  m2z PrtDlg.hDevNames                                  ;[xcx].$Obj(DebugCenter).hDevNames
  m2z PrtDlg.hDC
  mov PrtDlg.Flags, PD_NOSELECTION or PD_RETURNDC
  m2z PrtDlg.nFromPage
  m2z PrtDlg.nToPage
  m2z PrtDlg.nMinPage
  m2z PrtDlg.nMaxPage
  mov PrtDlg.nCopies, 1
  m2m PrtDlg.hInstance, hInstance, xdx
  m2z PrtDlg.lCustData
  m2z PrtDlg.lpfnPrintHook
  m2z PrtDlg.lpfnSetupHook
  m2z PrtDlg.lpPrintTemplateName
  m2z PrtDlg.lpSetupTemplateName
  m2z PrtDlg.hPrintTemplate
  m2z PrtDlg.hSetupTemplate

  .if $invoke(PrintDlg, addr PrtDlg)
    m2m [xbx].$Obj(DebugCenter).hDevMode, PrtDlg.hDevMode, xax
    m2m [xbx].$Obj(DebugCenter).hDevNames, PrtDlg.hDevNames, xcx
    .ifBitSet $invoke(GetDeviceCaps, PrtDlg.hDC, RASTERCAPS), RC_BITBLT
      mov DocInfo.cbSize, sizeof(DocInfo)
      m2m DocInfo.lpszDocName, offset szDebugCenter, xax
      m2z DocInfo.lpszOutput
      m2z DocInfo.lpszDatatype
      m2z DocInfo.fwType

      mov PageSize.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALWIDTH))
      mov PageSize.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALHEIGHT))
      mov PageOffset.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALOFFSETX))
      mov PageOffset.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALOFFSETY))
      mov LogPix.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, LOGPIXELSX))
      mov LogPix.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, LOGPIXELSY))

      ;Set paper margins using the Viewport
      invoke SetMapMode, PrtDlg.hDC, MM_ISOTROPIC
      invoke MulDiv, [xbx].$Obj(DebugCenter).PrintMargin.left, LogPix.x, 2540
      sub eax, PageOffset.x
      mov edi, eax
      invoke MulDiv, [xbx].$Obj(DebugCenter).PrintMargin.top, LogPix.y, 2540
      sub eax, PageOffset.y
      invoke SetViewportOrgEx, PrtDlg.hDC, edi, eax, NULL

      mov eax, [xbx].$Obj(DebugCenter).PrintMargin.left
      add eax, [xbx].$Obj(DebugCenter).PrintMargin.right
      invoke MulDiv, eax, LogPix.x, -2540
      add eax, PageSize.x
      mov PrintSize.x, eax
      mov eax, [xbx].$Obj(DebugCenter).PrintMargin.top
      add eax, [xbx].$Obj(DebugCenter).PrintMargin.bottom
      invoke MulDiv, eax, LogPix.y, -2540
      add eax, PageSize.y
      mov PrintSize.y, eax
      invoke SetWindowExtEx, PrtDlg.hDC, PrintSize.x, PrintSize.y, NULL
      invoke SetViewportExtEx, PrtDlg.hDC, PrintSize.x, PrintSize.y, NULL
      invoke CreateRectRgn, 0, 0, PrintSize.x, PrintSize.y
      mov xbx, xax
      invoke SelectClipRgn, PrtDlg.hDC, xbx
      invoke DeleteObject, xbx

      ;Set DC font
      FillString LogFnt.lfFaceName, <DBG_FONT_TEXT>
      invoke GetDeviceCaps, PrtDlg.hDC, LOGPIXELSY
      invoke MulDiv, 10, eax, -72
      mov LogFnt.lfHeight, eax
      m2z LogFnt.lfWidth
      m2z LogFnt.lfEscapement
      m2z LogFnt.lfOrientation
      mov LogFnt.lfWeight, FW_DONTCARE
      m2z LogFnt.lfItalic
      m2z LogFnt.lfUnderline
      m2z LogFnt.lfStrikeOut
      mov LogFnt.lfCharSet, DEFAULT_CHARSET
      mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
      mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
      mov LogFnt.lfQuality, CLEARTYPE_QUALITY
      mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
      mov hFont, $invoke(CreateFontIndirect, addr LogFnt)

      ;Start printing
      invoke StartDoc, PrtDlg.hDC, addr DocInfo
      invoke StartPage, PrtDlg.hDC
      mov hPrvFont, $invoke(SelectObject, PrtDlg.hDC, hFont)

      invoke GetTextMetrics, PrtDlg.hDC, addr TM
      m2m dPosY, TM.tmHeight, edx

      mov dLineCount, $32($invoke(SendMessage, [xsi].hEdit, EM_GETLINECOUNT, 0, 0))
      lea xdi, cPrtBuffer
      xor ebx, ebx
      .while ebx < dLineCount
        invoke MemZero, xdi, sizeof(cPrtBuffer)
        mov WORD ptr [xdi], lengthof cPrtBuffer - 1     ;Let room for the terminating zero
        invoke SendMessage, [xsi].hEdit, EM_GETLINE, xbx, xdi
        invoke StrLength, xdi
        invoke TextOut, PrtDlg.hDC, 0, dPosY, xdi, eax
        inc xbx                                         ;Increment line count
        mov eax, TM.tmHeight
        add dPosY, eax
        add eax, dPosY                                  ;Check if line upper point is under the
        .if eax > PrintSize.y                           ;  Print lower limit
          m2z dPosY
          invoke EndPage, PrtDlg.hDC
          invoke StartPage, PrtDlg.hDC
        .endif
      .endw

      invoke SelectObject, PrtDlg.hDC, hPrvFont
      invoke DeleteObject, hFont

      invoke EndPage, PrtDlg.hDC
      invoke EndDoc, PrtDlg.hDC
      invoke DeleteDC, PrtDlg.hDC
    .else
      mov edx, $ObjTmpl(DebugCenter).dLanguage
      add edx, 124
      invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
      invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, \
                         MB_OK or MB_ICONERROR
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.SaveAs
; Purpose:    Save the content of the RichEdit control to a specified file.
; Arguments:  Arg1: Dummy value 1.
;             Arg2: Dummy value 2.
; Return:     Nothing.

Method DbgMdiChildTxt.SaveAs,, pDummy1:PSTRING, pDummy2:PSTRING
  ACall SaveAs, offset szRtfFilter, offset szRtfExt
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.SaveTo
; Purpose:    Save the content of the RichEdit control to a specified file.
; Arguments:  Arg1: -> File path and name.
; Return:     Nothing.

RESaveText proc pStream:$ObjPtr(Stream), pBuffer:POINTER, dNumBytes:DWORD, pBytesTransferred:POINTER
  OCall pStream::DiskStream.BinWrite, pBuffer, dNumBytes
  mov xcx, pBytesTransferred
  mov [xcx], eax
  xor eax, eax
  ret
RESaveText endp

Method DbgMdiChildTxt.SaveTo, uses xsi, pFileName:PSTRING
  local pStream:$ObjPtr(Stream), EdtStrm:EDITSTREAM, cMsg[1024]:CHR

  SetObject xsi
  mov pStream, $New(DiskStream)
  OCall pStream::DiskStream.Init, xsi, pFileName, 0, 0, NULL, 0, 0, 0
  m2m EdtStrm.dwCookie, pStream, xax
  m2z EdtStrm.dwError
  m2m EdtStrm.pfnCallback, offset RESaveText, xax
  invoke SendMessage, [xsi].hEdit, EM_STREAMOUT, SF_RTF, addr EdtStrm
  .if EdtStrm.dwError != 0
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 122
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, \
                       MB_OK or MB_ICONERROR
  .endif
  Destroy pStream
  ACall xsi.SaveTo, pFileName                           ;Save FileName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.SelectAll
; Purpose:    Select the complete text in the RichEdit control.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.SelectAll
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, EM_SETSEL, 0, -1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(DbgMdiChildTxt.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szDbgMdiChildTxtClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD_TXT"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ZoomIn
; Purpose:    Increase the output size.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ZoomIn, uses xsi
  local dNumerator:DWORD, dDenominator:DWORD, dZoomFactor:DWORD

  SetObject xsi
  invoke SendMessage, [xsi].hEdit, EM_GETZOOM, addr dNumerator, addr dDenominator
  .if eax != FALSE
    mov dZoomFactor, $32($invoke(MulDiv, dNumerator, ZOOM_BASE, dDenominator))
    .if dZoomFactor <= (ZOOM_MAX - ZOOM_STEP)
      add dZoomFactor, ZOOM_STEP
    .else
      mov dZoomFactor, ZOOM_MAX
    .endif
    invoke SendMessage, [xsi].hEdit, EM_SETZOOM, dZoomFactor, ZOOM_BASE
    .if eax != FALSE
      m2m [xsi].dZoomFactor, dZoomFactor, eax
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildTxt.ZoomOut
; Purpose:    Decrease the output size.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildTxt.ZoomOut, uses xsi
  local dNumerator:DWORD, dDenominator:DWORD, dZoomFactor:DWORD

  SetObject xsi
  invoke SendMessage, [xsi].hEdit, EM_GETZOOM, addr dNumerator, addr dDenominator
  .if eax != FALSE
    mov dZoomFactor, $32($invoke(MulDiv, dNumerator, ZOOM_BASE, dDenominator))
    .if dZoomFactor >= (ZOOM_MIN + ZOOM_STEP)
      sub dZoomFactor, ZOOM_STEP
    .else
      mov dZoomFactor, ZOOM_MIN
    .endif
    invoke SendMessage, [xsi].hEdit, EM_SETZOOM, dZoomFactor, ZOOM_BASE
    .if eax != FALSE
      m2m [xsi].dZoomFactor, dZoomFactor, eax
    .endif
  .endif
MethodEnd


; ==================================================================================================
;    REdtIptor implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window handle is passed in pSelf.
; Return:     eax = Result of the message processing and depends on the message.

Method REdtIptor.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg
  invoke GetProp, pSelf, offset szPropREdtIptor
  OCall xax::REdtIptor.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.OnDropFiles
; Purpose:    Event procedure for WM_DROPFILES message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method REdtIptor.OnDropFiles, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cMsg[1024]:CHR

  SetObject xsi
  .if $invoke(DragQueryFile, wParam, -1, NULL, 0) > 1
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 120
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, $ObjTmpl(DebugCenter).hWnd, addr cMsg, offset szDebugCenter, \
                       MB_OK or MB_ICONEXCLAMATION
  .endif
  invoke DragQueryFile, wParam, 0, NULL, 0
  inc eax                                             ;Include ZTC
  mov ebx, eax
  xor edi, edi
  MemAlloc eax
  .if xax != NULL
    mov xdi, xax
    invoke DragQueryFile, wParam, 0, xdi, ebx
    invoke StrRScan, xdi, "."
    .if xax != NULL
      invoke StrIComp, xax, offset szRtfExt
      .if eax == 0
        OCall [xsi].pOwner::DbgMdiChildTxt.Open, xdi
        jmp @@Exit
      .endif
    .endif
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 121
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xsi].hWnd, addr cMsg, \
                       offset szDebugCenter, MB_OK or MB_ICONERROR
  .else
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 126
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xsi].hWnd, addr cMsg, \
                       offset szDebugCenter, MB_OK or MB_ICONERROR
  .endif

@@Exit:
  .if xdi != NULL
    MemFree xdi
  .endif
  invoke DragFinish, wParam
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method REdtIptor.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, lParam
  .if [xax].NMHDR.code == DLGDESTROYED
    mov xdx, [xax].NMHDR.idFrom
    .if xdx == [xsi].pFindDialog
      Destroy [xsi].pFindDialog
      xor eax, eax
      mov [xsi].pFindDialog, xax                        ;Mark as destroyed
      DbgText "FindDialog destroyed"
      ExitMethod
    .endif
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.OnRButtonDown
; Purpose:    Event procedure for WM_RBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method REdtIptor.OnRButtonDown,, wParam:WPARAM, lParam:LPARAM
  SetObject xdx
  mov xax, [xdx].pOwner                                 ;xax -> DbgMdiChildTxt
  mov xcx, [xax].$Obj(DbgMdiChildTxt).pOwner            ;xcx -> DbgMdiClient
  invoke SendMessage, [xcx].$Obj(DbgMdiClient).hWnd, WM_MDIACTIVATE, \
                      [xax].$Obj(DbgMdiChildTxt).hWnd, 0
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.OnRButtonUp
; Purpose:    Event procedure for WM_RBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method REdtIptor.OnRButtonUp,, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  invoke GetCursorPos, addr Pnt
  invoke GetSubMenu, $ObjTmpl(DebugCenter).hMenuContext, 0
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, Pnt.x, Pnt.y, 0, $ObjTmpl(DebugCenter).hWnd, NULL
  invoke PostMessage, $ObjTmpl(DebugCenter).hWnd, WM_NULL, 0, 0
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.OpenSciCalc
; Purpose:    Open the "calculator.exe".
; Arguments:  None.
; Return:     eax = TRUE if successful, otherwise FALSE.

GetCalcWndHandle proc hWnd:HWND, pSelf:$ObjPtr(REdtIptor)
  local cBuffer[MAX_PATH]:CHR

  invoke GetClassName, hWnd, addr cBuffer, lengthof cBuffer
  .if $invoke(StrComp, offset szCalcClass, addr cBuffer) == 0
    SetObject xcx, REdtIptor, pSelf
    m2m [xcx].hCalcWnd, hWnd, xax                       ;Store the window handle
    ReleaseObject
    xor eax, eax                                        ;Stop enumeration
  .else
    xor eax, eax
    inc eax                                             ;Get next window handle
  .endif
  ret
GetCalcWndHandle endp

GetCalcEditWndHandle proc hWnd:HWND, pSelf:$ObjPtr(REdtIptor)
  local cBuffer[MAX_PATH]:CHR

  invoke GetClassName, hWnd, addr cBuffer, lengthof cBuffer
  .if $invoke(StrComp, offset szEditClass, addr cBuffer) == 0
    SetObject xcx, REdtIptor, pSelf
    m2m [xcx].hCalcEditWnd, hWnd, xax                   ;Store the window handle
    ReleaseObject
    xor eax, eax                                        ;Stop enumeration
  .else
    xor eax, eax
    inc eax                                             ;Get next window handle
  .endif
  ret
GetCalcEditWndHandle endp

Method REdtIptor.OpenSciCalc, uses xbx xsi
  local cBuffer[MAX_PATH]:CHR, pIDL:$ObjPtr(IDL)
  local PInfo:PROCESS_INFORMATION, SInfo:STARTUPINFO
  local cMessage[MAX_PATH]:CHR, pIniFile:$ObjPtr(IniFile)

  SetObject xsi
  invoke IsWindow, [xsi].hCalcWnd                       ;Is it a valid window handle?
  .if eax == FALSE
    lea xbx, cBuffer
    New IDL
    .if xax != NULL
      mov pIDL, xax
      OCall xax::IDL.Init, xsi
      OCall pIDL::IDL.SetSpecialFolder, CSIDL_WINDOWS
      OCall pIDL::IDL.GetPath, xbx
      Destroy pIDL
      ;Open Win.ini
      invoke StrCCat, xbx, $OfsCStr("\Win.ini"), lengthof cBuffer - 1
      New IniFile
      .if xax != NULL
        mov pIniFile, xax
        OCall xax::IniFile.Init, xsi, xbx
        ;Switch to Sci mode
        OCall pIniFile::IniFile.SetDWord, $OfsCStr("SciCalc"), $OfsCStr("layout"), 0
        Destroy pIniFile
      .endif
    .endif

    New IDL
    .if xax != NULL
      mov pIDL, xax
      OCall xax::IDL.Init, xsi
      OCall pIDL::IDL.SetSpecialFolder, CSIDL_SYSTEM
      OCall pIDL::IDL.GetPath, xbx
      Destroy pIDL
      invoke StrCCat, xbx, offset szCalcPath, lengthof cBuffer - 1
    .endif

    xor ecx, ecx
    mov SInfo.cb, sizeof(SInfo)
    mov SInfo.lpDesktop, xcx
    mov SInfo.lpTitle, xcx
    mov SInfo.dwFlags, ecx
    mov SInfo.cbReserved2, cx
    mov SInfo.lpReserved2, xcx
    invoke CreateProcess, xbx, 0, 0, 0, TRUE, 0, 0, 0, addr SInfo, addr PInfo
    .if eax == FALSE || PInfo.hProcess == 0           ;Faild
      invoke StrCopy, addr cMessage, $OfsCStr("Can't start '")
      invoke StrCCat, addr cMessage, xbx, lengthof cMessage - 1
      invoke StrCCat, addr cMessage, $OfsCStr($Esc("' \:")), sizeof(cMessage) - 1
      invoke MessageBox, [xsi].hWnd, addr cMessage, offset szError, MB_OK or MB_ICONERROR
      xor eax, eax
      mov [xsi].hCalcWnd, xax
      mov [xsi].hCalcPrc, xax
    .else
      invoke WaitForInputIdle, PInfo.PROCESS_INFORMATION.hProcess, 5000
      .if eax == 0
        m2m [xsi].hCalcPrc, PInfo.PROCESS_INFORMATION.hProcess, xax   ;Store the window handle
        invoke EnumThreadWindows, PInfo.PROCESS_INFORMATION.dwThreadId, offset GetCalcWndHandle, xsi
        invoke EnumWindows, offset GetCalcEditWndHandle, xsi
        mov eax, TRUE                                 ;Return value
      .elseif eax == WAIT_TIMEOUT
        invoke StrCopy, addr cMessage, $OfsCStr("Waiting for '")
        invoke StrCCat, addr cMessage, xbx, lengthof cMessage - 1
        invoke StrCCat, addr cMessage, $OfsCStr($Esc("' timeout \:")), lengthof cMessage - 1
        invoke MessageBox, [xsi].hWnd, addr cMessage, offset szError, MB_OK or MB_ICONERROR
        xor eax, eax
        mov [xsi].hCalcWnd, xax
        mov [xsi].hCalcEditWnd, xax
        mov [xsi].hCalcPrc, xax
      .else
        invoke StrCopy, addr cMessage, $OfsCStr("'")
        invoke StrCCat, addr cMessage, xbx, lengthof cMessage - 1
        invoke StrCCat, addr cMessage, $OfsCStr($Esc("' didn't start correctly \:")), \
                        lengthof cMessage - 1
        invoke MessageBox, [xsi].hWnd, addr cMessage, offset szError, MB_OK or MB_ICONERROR
        xor eax, eax
        mov [xsi].hCalcWnd, xax
        mov [xsi].hCalcEditWnd, xax
        mov [xsi].hCalcPrc, xax
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     REdtIptor.SendToCalc
; Purpose:    Send the selected text to the Calc.exe application.
; Arguments:  None.
; Return:     Nothing.

SendChar macro Char:req
  .if $invoke(WaitForInputIdle, [xsi].hCalcPrc, CALC_KEY_TIMEOUT) != 0
    jmp @@Exit
  .endif
  invoke PostMessage, [xsi].hCalcWnd, WM_KEYDOWN, Char, 00000000000000000000000000000001b
  invoke Sleep, 10
  .if $invoke(WaitForInputIdle, [xsi].hCalcPrc, CALC_KEY_TIMEOUT) != 0
    jmp @@Exit
  .endif
  invoke PostMessage, [xsi].hCalcWnd, WM_KEYUP, Char, 11000000000000000000000000000001b
  invoke Sleep, 10
endm

Method REdtIptor.SendToCalc, uses xbx xdi xsi
  local dSelBeg:DWORD, dSelEnd:DWORD, dCharCount:DWORD, pBuffer:POINTER, dFlags:DWORD

  SetObject xsi
  .if $OCall(xsi.OpenSciCalc) != FALSE                  ;Open a Calc.exe instance in Sci mode
    mov xcx, [xsi].pOwner                               ;  to receive keyboard strokes
    mov xdi, [xcx].$Obj(DbgMdiChildTxt).hEdit
    invoke CallWindowProc, [xsi].pPrevWndProc, xdi, EM_GETSEL, addr dSelBeg, addr dSelEnd
    mov eax, dSelEnd
    sub eax, dSelBeg
    mov dCharCount, eax
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      add eax, eax
    endif
    mov ebx, eax
    add eax, sizeof(CHR)
    mov pBuffer, $MemAlloc(eax)
    invoke CallWindowProc, [xsi].pPrevWndProc, xdi, EM_GETSELTEXT, 0, pBuffer

    ;To avoid a text copy operation when the focus get back to DebugCenter
    ;we deselect the text that was just copied.

    if TARGET_BITNESS eq 32
      invoke CallWindowProc, [xsi].pPrevWndProc, edi, EM_SETSEL, dSelBeg, dSelBeg
    else
      mov eax, dSelBeg
      invoke CallWindowProc, [xsi].pPrevWndProc, xdi, EM_SETSEL, rax, rax
    endif
    invoke SetForegroundWindow, [xsi].hCalcWnd

    add xbx, pBuffer                                    ;xbx -> end of string
    sub xbx, sizeof(CHR)                                ;Skip ZTC and get the last character
    .while xbx >= pBuffer
      .if CHR ptr [xbx] == " "
        sub xbx, sizeof(CHR)
      .elseif CHR ptr [xbx] == "h"
        SendChar VK_F5                                  ;Switch calculator to hexadecimal
        SendChar VK_F12                                 ;Switch calculator to QWORD
        .break
      .elseif CHR ptr [xbx] == "y"
        SendChar VK_F8                                  ;Switch calculator to binary
        SendChar VK_F12                                 ;Switch calculator to QWORD
        .break
      .else
        SendChar VK_F6                                  ;Switch calculator to decimal
        .break
      .endif
    .endw

    xor eax, eax
    mov dFlags, eax                                     ;1 if 1st char different from "0"
    mov xdi, pBuffer
    .while dCharCount > 0
      movzx xbx, CHR ptr [xdi]                          ;xdi -> char buffer
      add xdi, sizeof(CHR)
      .if dFlags == 0                                   ;Don't send unnecessary "0" chars
        .if bl != "0"
          inc dFlags
        .endif
      .endif
      .if dFlags != 0
        .if bl == "."
          SendChar 00BEh
        .elseif (bl >= "0") && (bl <= "9")
          SendChar ebx
        .elseif (bl >= "A") && (bl <= "F")
          SendChar ebx
        .elseif (bl >= "a") && (bl <= "f")
          sub xbx, 20h
          SendChar ebx
        .endif
      .endif
      dec dCharCount
    .endw

    .if dFlags == 0                                     ;if nothing was sent
      SendChar "0"                                      ;  send a "0"
    .endif

@@Exit:
    MemFree pBuffer
  .endif
MethodEnd
