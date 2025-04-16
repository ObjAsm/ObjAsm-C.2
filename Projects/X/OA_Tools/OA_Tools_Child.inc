; ==================================================================================================
; Title:      OA_Tools_Child.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



EDTSTYLE  equ   WS_CHILD or WS_VISIBLE or WS_BORDER or WS_TABSTOP or WS_VSCROLL or  \
                WS_HSCROLL or ES_MULTILINE or ES_AUTOVSCROLL or ES_AUTOHSCROLL or ES_WANTRETURN

; ==================================================================================================
;    EditIptor implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     EditIptor.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window handle is passed in pSelf.
; Return:     eax = Result of the message processing and depends on the message.

Method EditIptor.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg
  invoke GetProp, pSelf, offset szPropEditIptor
  OCall xax::EditIptor.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditIptor.OnRButtonDown
; Purpose:    Event procedure for WM_RBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method EditIptor.OnRButtonDown,, wParam:WPARAM, lParam:LPARAM
  SetObject xdx
  mov xax, [xdx].pOwner                                 ;xax -> OAT_Child
  mov xcx, [xax].$Obj(OAT_Child).pOwner                 ;xcx -> OAT_Client
  invoke SendMessage, [xcx].$Obj(OAT_Client).hWnd, WM_MDIACTIVATE, [xax].$Obj(OAT_Child).hWnd, 0
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditIptor.OnRButtonUp
; Purpose:    Event procedure for WM_RBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method EditIptor.OnRButtonUp,, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  invoke GetCursorPos, addr Pnt
  invoke GetSubMenu, $ObjTmpl(Application).hMenuChildContext, 0
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, Pnt.x, Pnt.y, 0, $ObjTmpl(Application).hWnd, NULL
  invoke PostMessage, $ObjTmpl(Application).hWnd, WM_NULL, 0, 0
  xor eax, eax
MethodEnd



; ==================================================================================================
;    OAT_Child implementation
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.AnalyseFile
; Purpose:    Gatter file information => line lengths.
; Arguments:  Arg1: -> FileName.
; Return:     Nothing.

Method OAT_Child.AnalyseFile, uses xdi xsi
  local qFileByteCount:QWORD, bChar:CHRA

  SetObject xsi
  New [xsi].LineLengths::DataCollection
  OCall [xsi].LineLengths::DataCollection.Init, xsi, 100, 100, COL_MAX_CAPACITY
  New [xsi].DskStream::DiskStream
  OCall [xsi].DskStream::DiskStream.Init, xsi, [xsi].pFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, 0

  .if [xsi].DskStream.dErrorCode == 0
    OCall [xsi].DskStream::DiskStream.GetSize
    if TARGET_BITNESS eq 32
      qmov qFileByteCount, edx::eax
    else
      mov qFileByteCount, rax
    endif
    xor edi, edi                                        ;Reset sentence length
    .repeat
      if TARGET_BITNESS eq 32
        mov eax, (QUADWORD ptr qFileByteCount).LoDWord
        or eax, (QUADWORD ptr qFileByteCount).HiDWord
      else
        mov rax, qFileByteCount
      endif
      .break .if xax == 0
      OCall [xsi].DskStream::Stream.BinRead, addr bChar, sizeof bChar

      .ifBitSet [xsi].dFlags, OATF_TEST_LF
        .if bChar == 10
          MemAlloc sizeof(DWORD)                        ;Sentence lenght
          mov [xax], edi
          OCall [xsi].LineLengths::DataCollection.Insert, xax
          xor edi, edi                                  ;Reset sentence length
        .else
          inc edi
        .endif

      .elseIfBitSet [xsi].dFlags, OATF_TEST_CR
        .if bChar == 13
          MemAlloc sizeof(DWORD)                        ;Sentence lenght
          mov [xax], edi
          OCall [xsi].LineLengths::DataCollection.Insert, xax
          xor edi, edi                                  ;Reset sentence length
        .else
          inc edi
        .endif

      .else                                             ;Default
        .if bChar == 13                                 ;Carrige Return  (Sequence ... 13,10)
          MemAlloc sizeof(DWORD)                        ;Sentence lenght
          mov [xax], edi
          OCall [xsi].LineLengths::DataCollection.Insert, xax
        .elseif bChar == 10
          xor edi, edi                                  ;Reset sentence length
        .else
          inc edi
        .endif
      .endif

      if TARGET_BITNESS eq 32
        sub (QUADWORD ptr qFileByteCount).LoDWord, 1    ;Decrement qFileByteCount
        sbb (QUADWORD ptr qFileByteCount).HiDWord, 0
      else
        dec qFileByteCount
      endif
    .until FALSE

    .if edi != 0                                        ;Last line doesn't end with CRLF
      MemAlloc sizeof(DWORD)                            ;Sentence lenght
      mov [xax], edi
      OCall [xsi].LineLengths::DataCollection.Insert, xax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ClpBrdClear
; Purpose:    Delete the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ClpBrdClear
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_CLEAR, 0, 0
  OCall ClpBrdSetBtns
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ClpBrdCopy
; Purpose:    Copy the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ClpBrdCopy
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_COPY, 0, 0
  OCall ClpBrdSetBtns
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ClpBrdCut
; Purpose:    Cut the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ClpBrdCut
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_CUT, 0, 0
  OCall ClpBrdSetBtns
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ClpBrdPaste
; Purpose:    Paste the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ClpBrdPaste
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, WM_PASTE, 0, 0
  OCall ClpBrdSetBtns
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ClpBrdSetBtns
; Purpose:    Set the cut, copy & paste clipboard buttons.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ClpBrdSetBtns, uses xbx xdi xsi
  local dBegPos:DWORD, dEndPos:DWORD, hMenu:HMENU, dActivate:DWORD

;  DbgText "OAT_Child.ClpBrdSetBtns"
  SetObject xsi
  invoke SendMessage, [xsi].hEdit, EM_GETSEL, addr dBegPos, addr dEndPos
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(OAT_Client).pOwner
  mov hMenu, $invoke(GetMenu, [xdi].$Obj(Application).hWnd)           ;Get the current menu
  mov eax, dEndPos
  .if eax == dBegPos
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT,    MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY,   MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_GRAYED
    mov xbx, $ObjTmpl(Application).hMenuChildContext
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT,    MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY,   MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_GRAYED
  .else
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, TRUE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT,    MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY,   MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_ENABLED
    mov xbx, $ObjTmpl(Application).hMenuChildContext
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT,    MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY,   MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_ENABLED
  .endif

  mov dActivate, TRUE
  .if !$invoke(IsClipboardFormatAvailable, CF_TEXT)
    dec dActivate
  .endif

  lea xbx, [xdi].$Obj(Application).TbEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, dActivate
  .if dActivate
    mov edi, MF_BYCOMMAND or MF_ENABLED
  .else
    mov edi, MF_BYCOMMAND or MF_GRAYED
  .endif
  invoke EnableMenuItem, hMenu, IDM_EDIT_PASTE, edi
  invoke EnableMenuItem, $ObjTmpl(Application).hMenuChildContext, IDM_EDIT_PASTE, edi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.Done
; Purpose:    Finalize the OAT_Child object.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.Done, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  mov xbx, [xdi].$Obj(OAT_Client).pOwner

  dec [xdi].$Obj(OAT_Client).dChildCount

  ;Main menu update
  .if ZERO?                                             ;No more child windows ?
    OCall xbx::Application.EnableActions, FALSE
    invoke SendMessage, [xdi].$Obj(OAT_Client).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    OCall xbx::Application.ChangeMnuLanguage, [xbx].$Obj(Application).dLanguage
    OCall xbx::Application.SetToolMenu
    invoke DrawMenuBar, [xbx].$Obj(Application).hWnd        ;Redraw the new menu bar
  .endif

  ;Release resources
  OCall [xsi].EdtIptor::EditIptor.Done
  OCall [xsi].DskStream::DiskStream.Done
  OCall [xsi].LineLengths::DataCollection.Done
  invoke StrDispose, [xsi].pFileName

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.Init
; Purpose:    Initialize the OAT_Child object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> File name.
;             Arg3: Flags.
; Return:     eax = TRUE if succseeded. otherwise FALSE.

Method OAT_Child.Init, uses xbx xdi xsi, pOwner:POINTER, pFileName:PSTRING, dFlags:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  mov [xsi].pFileName, $invoke(StrNew, pFileName)
  m2m [xsi].dFlags, dFlags, eax

  mov xdi, pOwner                                       ;xdi -> OAT_Client

  ;Create the Window
  invoke CreateMDIWindow, offset szOAT_Child, pFileName, 0, \
                          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(OAT_Client).hWnd, hInstance, pSelf
  .if xax != NULL
    mov xbx, [xdi].$Obj(OAT_Client).pOwner              ;xbx -> Application

    ;Copy color information
    invoke MemClone, addr [xsi].Color, addr [xbx].$Obj(Application).Setup.Color, sizeof ColorData

    .if [xdi].$Obj(OAT_Client).dChildCount == 1         ;First child window ?
      invoke SendMessage, [xdi].$Obj(OAT_Client).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(Application).hMenuChild, \
                          [xbx].$Obj(Application).hMenuChildWnd
      OCall xbx::Application.ChangeMnuLanguage, [xbx].$Obj(Application).dLanguage
      OCall xbx::Application.EnableActions, TRUE
      OCall xbx::Application.SetToolMenu
      invoke DrawMenuBar, [xbx].$Obj(Application).hWnd      ;Redraw the new menu bar
    .endif

    OCall xsi.AnalyseFile                               ;Gather file information

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL

    .if [xsi].DskStream.dErrorCode != OBJ_OK
      OCall xsi.WriteResStr, IDS_FILE_OPEN_ERROR, [xsi].Color.Failure, 0
      OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
      xor eax, eax
    .else
      mov eax, TRUE
    .endif

  .else
    invoke MessageBox, [xdi].$Obj(OAT_Client).hWnd, $OfsCStr("Window creation error"), \
                       offset szError, MB_OK or MB_ICONERROR
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method OAT_Child.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local LogFnt:LOGFONT, hDC:HDC

  SetObject xsi
  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_CLIENTEDGE or WS_EX_ACCEPTFILES, \
                         offset szRichEdit20, NULL, EDTSTYLE, \
                         0, 0, 10, 10, [xsi].hWnd, RICHEDITID, hInstance, NULL
  mov [xsi].hEdit, xax
  invoke SendMessage, [xsi].hEdit, EM_SETEVENTMASK, 0, ENM_SELCHANGE  ;Enable EN_SELCHANGE messages
  mov xcx, [xsi].pOwner                                 ;xcx -> OAT_Client
  mov xax, [xcx].$Obj(OAT_Client).pOwner                ;xax -> Application
  invoke SendMessage, [xsi].hEdit, EM_SETBKGNDCOLOR, 0, [xax].$Obj(Application).Setup.Color.Bkground

  New [xsi].EdtIptor::EditIptor
  OCall [xsi].EdtIptor::EditIptor.Init, xsi, [xsi].hEdit, offset szPropEditIptor

  mov xax, [xsi].pOwner                                 ;xax -> pClient
  mov xbx, [xax].$Obj(OAT_Client).pOwner                ;xbx -> Application
  m2m [xsi].dZoom, [xbx].$Obj(Application).Setup.dZoomfactor, eax
  invoke SendMessage, [xsi].hEdit, EM_SETZOOM, [xsi].dZoom, ZOOM_BASE

  invoke StrCCopy, addr LogFnt.lfFaceName, addr [xbx].$Obj(Application).Setup.cFontFaceName, LF_FACESIZE
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, [xbx].$Obj(Application).Setup.dFontSize, eax, -72
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
  mov LogFnt.lfQuality, DEFAULT_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xsi].hFont, $invoke(CreateFontIndirect, addr LogFnt)
  invoke ReleaseDC, [xsi].hWnd, hDC
  invoke SendMessage, [xsi].hEdit, WM_SETFONT, [xsi].hFont, FALSE

  mov xdx, [xsi].pOwner
  inc [xdx].$Obj(OAT_Client).dChildCount

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method OAT_Child.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_Child.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, lParam
  .if [xax].NMHDR.code == EN_SELCHANGE
    mov xdx, [xax].NMHDR.idFrom
    .if xdx == RICHEDITID
      mov xcx, [xsi].pOwner
      invoke SendMessage, [xcx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
      .if xax == [xsi].hWnd
        OCall xsi.ClpBrdSetBtns
        xor eax, eax
        ExitMethod
      .endif
    .endif
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_Child.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  PntS2Regs lParam, ebx                                 ;eax = width, ebx = height
  invoke MoveWindow, [xsi].hEdit, 0, 0, eax, ebx, TRUE

  ;Do default drawing: if maximized, menu and buttons are drawn correctly!
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.Run
; Purpose:    Perform all checks.
; Arguments:  None.
; Return:     eax = Number of findings. -1 means failure.

Method OAT_Child.Run, uses xbx xsi
  local cInfo[MAX_PATH]:CHRA

  SetObject xsi
  cmp [xsi].LineLengths.dCount, 0
  jz @@Error1

  lea xbx, cInfo
  invoke StrCCopy, xbx, $OfsCStrA("JOB: ["), lengthof cInfo

  .ifBitSet [xsi].dFlags, OATF_TEST_MX
    invoke StrCCatA, xbx, $OfsCStrA("Mixed mode, "), lengthof cInfo
  .elseIfBitSet [xsi].dFlags, OATF_TEST_32
    invoke StrCCatA, xbx, $OfsCStrA("32 bit mode, "), lengthof cInfo
  .elseIfBitSet [xsi].dFlags, OATF_TEST_64
    invoke StrCCatA, xbx, $OfsCStrA("64 bit mode, "), lengthof cInfo
  .endif

  .ifBitSet [xsi].dFlags, OATF_TEST_MTD
    invoke StrCECatA, xbx, $OfsCStrA("method "), lengthof cInfo
  .elseIfBitSet [xsi].dFlags, OATF_TEST_PRC
    invoke StrCECatA, xbx, $OfsCStrA("procedure "), lengthof cInfo
  .elseIfBitSet [xsi].dFlags, OATF_TEST_MAC
    invoke StrCECatA, xbx, $OfsCStrA("macro "), lengthof cInfo
  .endif

  .ifBitSet [xsi].dFlags, OATF_TEST_REG
    invoke StrCECatA, xbx, $OfsCStrA("register/"), lengthof cInfo
  .endif
  .ifBitSet [xsi].dFlags, OATF_TEST_ARG
    invoke StrCECatA, xbx, $OfsCStrA("argument/"), lengthof cInfo
  .endif
  .ifBitSet [xsi].dFlags, OATF_TEST_LOC
    invoke StrCECatA, xbx, $OfsCStrA("local/"), lengthof cInfo
  .endif
  m2z CHRA ptr [xax - sizeof CHRA]                      ;Cut the last character

  invoke StrCCatA, xbx, $OfsCStrA(" check]",13,10,13,10), lengthof cInfo
  OCall xsi.WriteA, addr cInfo, [xsi].Color.Notification, 0

  xor ebx, ebx                                          ;ebx = Findings counter
  ;Perform checks
  .ifBitSet [xsi].dFlags, OATF_TEST_MTD
    .ifBitSet [xsi].dFlags, OATF_TEST_ARG
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckMtdArg
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif
    .ifBitSet [xsi].dFlags, OATF_TEST_LOC
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckMtdLoc
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif
    .ifBitSet [xsi].dFlags, OATF_TEST_REG
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckMtdReg
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif

  .elseIfBitSet [xsi].dFlags, OATF_TEST_PRC
    .ifBitSet [xsi].dFlags, OATF_TEST_ARG
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckPrcArg
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif
    .ifBitSet [xsi].dFlags, OATF_TEST_LOC
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckPrcLoc
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif
    .ifBitSet [xsi].dFlags, OATF_TEST_REG
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckPrcReg
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif

  .elseIfBitSet [xsi].dFlags, OATF_TEST_MAC
    .ifBitSet [xsi].dFlags, OATF_TEST_ARG
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckMacArg
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif
    .ifBitSet [xsi].dFlags, OATF_TEST_LOC
      OCall [xsi].DskStream::DiskStream.Seek, QWORD ptr 0, STM_BEGIN
      OCall xsi.CheckMacLoc
      cmp eax, -1
      jz @@Error2
      add ebx, eax
    .endif
  .endif
  mov eax, ebx
  ExitMethod

@@Error1:
  OCall xsi.WriteResStr, IDS_FILE_EMPTY, [xsi].Color.Failure, CFE_BOLD
  OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
  mov eax, -1
  ExitMethod
@@Error2:
  OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
  OCall xsi.WriteResStr, IDS_INTERNAL_FAILURE, [xsi].Color.Failure, CFE_BOLD
  OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.SelectAll
; Purpose:    Select the complete text in the RichEdit control.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.SelectAll
  SetObject xcx
  invoke SendMessage, [xcx].hEdit, EM_SETSEL, 0, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(OAT_Child.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szOAT_Child, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_CHILD"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.WriteA
; Purpose:    Output a given string.
; Arguments:  Arg1: -> ANSI string.
;             Arg2: Text color.
;             Arg3: Text effect (CFE_BOLD, CFE_ITALIC, CFE_STRIKEOUT, CFE_UNDERLINE).
; Return:     Nothing.

Method OAT_Child.WriteA, uses xsi, pStrA:PSTRINGA, Color:COLORREF, dEffects:DWORD
  local CFD:CHARFORMAT

  SetObject xsi
  mov CFD.cbSize, sizeof(CFD)
  mov CFD.dwMask, CFM_COLOR or CFM_BOLD or CFM_ITALIC or CFM_STRIKEOUT or CFM_UNDERLINE
  m2m CFD.crTextColor, Color, eax
  m2m CFD.dwEffects, dEffects, ecx
  invoke SendMessageA, [xsi].hEdit, EM_SETCHARFORMAT, SCF_SELECTION, addr CFD
  invoke SendMessageA, [xsi].hEdit, EM_SETSEL, -1, -1
  invoke SendMessageA, [xsi].hEdit, EM_REPLACESEL, FALSE, pStrA
  invoke SendMessageA, [xsi].hEdit, EM_SCROLLCARET, 0, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.WriteW
; Purpose:    Output a given string.
; Arguments:  Arg1: -> WIDE string.
;             Arg2: Text color.
;             Arg3: Text effect (CFE_BOLD, CFE_ITALIC, CFE_STRIKEOUT, CFE_UNDERLINE).
; Return:     Nothing.

Method OAT_Child.WriteW, uses xsi, pStrW:PSTRINGW, Color:COLORREF, dEffects:DWORD
  local CFD:CHARFORMAT

  SetObject xsi
  mov CFD.cbSize, sizeof(CFD)
  mov CFD.dwMask, CFM_COLOR or CFM_BOLD or CFM_ITALIC or CFM_STRIKEOUT or CFM_UNDERLINE
  m2m CFD.crTextColor, Color, eax
  m2m CFD.dwEffects, dEffects, ecx
  invoke SendMessageW, [xsi].hEdit, EM_SETCHARFORMAT, SCF_SELECTION, addr CFD
  invoke SendMessageW, [xsi].hEdit, EM_SETSEL, -1, -1
  invoke SendMessageW, [xsi].hEdit, EM_REPLACESEL, FALSE, pStrW
  invoke SendMessageW, [xsi].hEdit, EM_SCROLLCARET, 0, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.WriteLineNumber
; Purpose:    Output Linenumber as a comment.
; Arguments:  Arg1: Line Number (0-Base).
; Return:     Nothing.

Method OAT_Child.WriteLineNumber, uses xbx xsi, dLineNumber:DWORD
  local cBuffer[1024]:CHRA

  SetObject xsi
  mov xcx, [xsi].pOwner                                 ;xcx -> OAT_Client
  mov xbx, [xcx].$Obj(OAT_Client).pOwner
  inc dLineNumber                                       ;First LineNumber = 1 (1-Base)
  invoke dword2decA, addr cBuffer, dLineNumber
  OCall xsi::OAT_Child.WriteA, $OfsCStrA(" ("), [xbx].$Obj(Application).Setup.Color.Information, 0
  OCall xsi::OAT_Child.WriteA, addr cBuffer, [xbx].$Obj(Application).Setup.Color.Information, 0
  OCall xsi::OAT_Child.WriteA, $OfsCStrA(")", 13, 10), [xbx].$Obj(Application).Setup.Color.Information, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.WriteResStr
; Purpose:    Output a given string from file resource.
; Arguments:  Arg1: Resource ID.
;             Arg2: Text color.
;             Arg3: Text effect (CFE_BOLD, CFE_ITALIC, CFE_STRIKEOUT, CFE_UNDERLINE).
; Return:     Nothing.

Method OAT_Child.WriteResStr, uses xsi, dResStrID:DWORD, Color:COLORREF, dEffects:DWORD
  local cBuffer[1024]:CHR

  SetObject xsi
  mov xax, [xsi].pOwner                                  ;xax -> OAT_Client
  mov xcx, [xax].$Obj(OAT_Client).pOwner                 ;xcx -> Application
  mov edx, [xcx].$Obj(Application).dLanguage
  add edx, dResStrID
  invoke LoadString, hInstance, edx, addr cBuffer, sizeof cBuffer
  .if eax != 0
    OCall xsi.WriteW, addr cBuffer, Color, dEffects
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ZoomIn
; Purpose:    Increse the output size.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ZoomIn, uses xsi
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
      m2m [xsi].dZoom, dZoomFactor, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Child.ZoomOut
; Purpose:    Decrese the output size.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Child.ZoomOut, uses xsi
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
      m2m [xsi].dZoom, dZoomFactor, eax
    .endif
  .endif
MethodEnd
