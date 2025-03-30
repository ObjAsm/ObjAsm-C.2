; ==================================================================================================
; Title:      ADE_Editor.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Editor implementation.
; ==================================================================================================


;Editor Instance Flags
EIF_NEW_FILE                equ   BIT00
EIF_DIRTY                   equ   BIT01
EIF_OVERWRITE_MODE          equ   BIT02
EIF_BLOCK_MODE              equ   BIT03
EIF_CARET_LOCKED            equ   BIT04


; ==================================================================================================
; Editor implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.ClpBrdDelete
; Purpose:    Clipboard delete opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.ClpBrdDelete, uses xbx xsi
  SetObject xsi
  invoke GetFocus                                       ;Get the Viewthat has the focus
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xax
      .if eax == ADE_EditorViewID
        OCall xbx::EditorView.ClpBrdDelete
        .if eax != FALSE
          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW   ;Redraw Views
          OCall xbx::EditorView.CaretSet
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.ClpBrdCopy
; Purpose:    Clipboard copy opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.ClpBrdCopy, uses xbx xsi
  SetObject xsi
  invoke GetFocus                                       ;Get the Viewthat has the focus
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xax
      .if eax == ADE_EditorViewID
        OCall xbx::EditorView.ClpBrdCopy
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.ClpBrdCut
; Purpose:    Clipboard cut opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.ClpBrdCut, uses xbx xsi
  SetObject xsi
  invoke GetFocus                                       ;Get the Viewthat has the focus
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xax
      .if eax == ADE_EditorViewID
        OCall xbx::EditorView.ClpBrdCut
        .if eax != FALSE
          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW   ;Redraw Views
          OCall xbx::EditorView.CaretSet
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.ClpBrdPaste
; Purpose:    Clipboard paste opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Link:       https://msdn.microsoft.com/en-us/library/windows/desktop/ms649016(v=vs.85).aspx#_win32_Copying_Information_to_the_Clipboard
; Note:       CF_TEXT = Each line ends with a carriage return/linefeed (CR-LF) combination. 
;             A null character signals the end of the data. Use this format for ANSI text.

Method Editor.ClpBrdPaste, uses xbx xsi
  SetObject xsi
  invoke GetFocus                                       ;Get the Viewthat has the focus
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xax
      .if eax == ADE_EditorViewID
        OCall xbx::EditorView.ClpBrdPaste
        .if eax != FALSE
          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW   ;Redraw Views
          OCall xbx::EditorView.CaretSet
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.ClpBrdSetBtns
; Purpose:    Set the cut, copy & paste clipboard buttons.
; Arguments:  None.
; Return:     Nothing.

Method Editor.ClpBrdSetBtns, uses xbx xdi xsi
  local hMenu:HMENU, dActivate:DWORD

  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(ClientWnd).pOwner
  mov hMenu, $invoke(GetMenu, [xdi].$Obj(Application).hWnd)   ;Get the current menu
  .if [xsi].SelectionRange.pBegSelInfo == NULL || [xsi].SelectionRange.pEndSelInfo == NULL
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_DELETE, FALSE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_GRAYED
    mov xbx, $ObjTmpl(Application).hMenuContextEditor
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_GRAYED
  .else
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_DELETE, TRUE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_ENABLED
    mov xbx, $ObjTmpl(Application).hMenuContextEditor
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_ENABLED
  .endif

  mov dActivate, TRUE
  .if !$invoke(IsClipboardFormatAvailable, CF_TEXT)
    dec dActivate
  .endif

  lea xbx, [xdi].$Obj(Application).TbEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, dActivate
  .if dActivate
    mov ebx, MF_BYCOMMAND or MF_ENABLED
  .else
    mov ebx, MF_BYCOMMAND or MF_GRAYED
  .endif
  invoke EnableMenuItem, hMenu, IDM_EDIT_PASTE, ebx
  invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_PASTE, ebx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Done
; Purpose:    Finalize the Editor object.
; Arguments:  None.
; Return:     Nothing.

Method Editor.Done, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  mov xbx, [xdi].$Obj(ClientWnd).pOwner

  OCall [xsi].Snapper::Magnetism.Done
  OCall [xsi].EditorDisplays::Collection.Done
  ACall xsi.Done

  ;Main menu update
  .if [xdi].$Obj(ClientWnd).dChildCount == 0              ;No more child windows ?
    OCall xbx::Application.ManageGuiCmds, 0
    invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    invoke DrawMenuBar, [xbx].$Obj(Application).hWnd      ;Redraw the new menu bar
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.FindFrom
; Purpose:    Searches a string from a starting location.
; Arguments:  Arg1: -> Search string.
;             Arg2: -> Start line number.
;             Arg3: -> Start char index.
;             Arg4: -> EditorView
; Return:     Nothing.

Method Editor.FindFrom, uses xbx xdi xsi, pSearchString:PSTRING, pLineNumber:POINTER, pCharIndex:POINTER
  local sdCaretVisLineOffset:SDWORD, dCurrLineNumber:DWORD, dTargLineNumber:DWORD
  local dRetVal:DWORD

  SetObject xsi
  mov dRetVal, FALSE
  OCall xsi.SelectionResetAll
  mov dCurrLineNumber, 1
  mov xax, pLineNumber
  mov ecx, DWORD ptr [xax]
  mov dTargLineNumber, ecx
  xor ebx, ebx
  mov xax, [xsi].TextLines.pFirstMember
  .if xax != NULL
    sub xax, offset $Obj(EditorTextLine).Link
    mov sdCaretVisLineOffset, 0
    ;Goto the starting line number
    .while ecx != dCurrLineNumber
      mov xax, [xax].$Obj(EditorTextLine).Link.pLinkFwrd
      .break .if xax == NULL
      sub xax, offset $Obj(EditorTextLine).Link
      inc sdCaretVisLineOffset
      inc dCurrLineNumber
    .endw
    .if xax != NULL
      mov xdx, pCharIndex
      mov edi, DWORD ptr [xdx]
      .if edi > [xax].$Obj(EditorTextLine).dLength
        mov edi, [xax].$Obj(EditorTextLine).dLength
      .endif
      .while TRUE
        mov xbx, xax
        mov xdx, [xbx].$Obj(EditorTextLine).pBuffer
        lea xcx, [xdx + sizeof(CHR)*xdi]
        invoke StrPos, xcx, pSearchString
        .break .if xax != NULL
        mov xax, [xbx].$Obj(EditorTextLine).Link.pLinkFwrd
        .break .if xax == NULL
        sub xax, offset $Obj(EditorTextLine).Link
        inc sdCaretVisLineOffset
        inc dCurrLineNumber
        xor edi, edi
      .endw
      .if xax != NULL
        mov [xsi].SelectionFst.LOCATION.pTextLine, xbx
        mov [xsi].SelectionLst.LOCATION.pTextLine, xbx
        mov edx, dCurrLineNumber
        mov [xsi].SelectionFst.LOCATION.dLineNumber, edx
        mov [xsi].SelectionLst.LOCATION.dLineNumber, edx
        sub xax, [xbx].$Obj(EditorTextLine).pBuffer
        shr eax, 1
        mov [xsi].SelectionFst.LOCATION.dCharIndex, eax
        mov [xsi].SelectionLst.LOCATION.dCharIndex, eax
        invoke StrLength, pSearchString
        add [xsi].SelectionLst.LOCATION.dCharIndex, eax
        OCall xsi.SelectionSet

        mov xax, [xsi].TextLines.pFirstMember
        sub xax, offset $Obj(EditorTextLine).Link
        mov xbx, [xsi].pFocusedView
        mov [xbx].$Obj(EditorView).p1stVisLine, xax
        mov [xbx].$Obj(EditorView).d1StVisLineCount, 0
        mov [xbx].$Obj(EditorView).d1stVisLineNum, 1
        OCall [xsi].pFocusedView::EditorView.ScrollVisPageDown, sdCaretVisLineOffset
        .ColForEach [xsi].EditorDisplays, ebx
          invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
        .ColNext
        mov dRetVal, TRUE
      .endif
      mov xax, pLineNumber
      m2m DWORD ptr [xax], dCurrLineNumber, edx
      mov xdx, pCharIndex
      mov eax, [xsi].SelectionLst.LOCATION.dCharIndex
      mov DWORD ptr [xdx], eax
    .endif    
  .endif
  mov eax, dRetVal
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.InformDeletionOf
; Purpose:    Inform all Views that a specific lines was deleted.
; Arguments:  Arg1: Line number of Arg1.
; Return:     Nothing.

Method Editor.InformDeletionOf, uses xbx xsi, dLineNumber:DWORD
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    OCall xax::EditorDisplay.InformDeletionOf, dLineNumber
  .ColNext
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.InformInsertionOf
; Purpose:    Inform all Views that a specific lines was inserted.
; Arguments:  Arg1: Line number of Arg1.
; Return:     Nothing.

Method Editor.InformInsertionOf, uses xbx xsi, dLineNumber:DWORD
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    OCall xax::EditorDisplay.InformInsertionOf, dLineNumber
  .ColNext
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Init
; Purpose:    Initialize the Editor object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> EditorResources.
;             Arg2: -> FileName string.
; Return:     Nothing.

Method Editor.Init, uses xbx xdi xsi, pOwner:POINTER, pResources:$ObjPtr(EditorResources), pFileName:PSTRING
  local ClientRect:RECT, cBuffer[MAX_PATH]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner                                ;hWnd is set in WndProc
  m2m [xsi].pResources, pResources, xax

  mov xdi, pOwner                                       ;xdi -> ClientWnd
  .if pFileName == NULL
    BitSet [xsi].dFlags, EIF_NEW_FILE or EIF_DIRTY
    ;Insert an empty line
    mov xbx, $New(EditorTextLine)
    lea xcx, [xsi].TextLines
    lea xdx, [xbx].$Obj(EditorTextLine).Link
    LDLL_InsertLast xcx, xdx, xax
    OCall xbx::EditorTextLine.Init, xsi
    mov [xsi].dMaxTextLineChrCount, 0
    inc [xsi].dVisTextLineCount

    inc [xdi].$Obj(ClientWnd).dUnnamedCount
    lea xbx, cBuffer
    WriteF xbx, "Unnamed ¦UD", [xdi].$Obj(ClientWnd).dUnnamedCount
    lea xcx, cBuffer
  .else
    OCall xsi.Open, pFileName
    mov xcx, pFileName
  .endif
  mov [xsi].pFullFileName, $invoke(StrNew, xcx)

  invoke CreateMDIWindow, offset szEditorClassName, [xsi].pFullFileName, 0, \
                          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(ClientWnd).hWnd, hInstance, pSelf
  .if xax != NULL
    .if [xdi].$Obj(ClientWnd).dChildCount == 1          ;First child window ?
      mov xbx, [xdi].$Obj(ClientWnd).pOwner             ;xbx -> Application
      invoke SendMessage, [xbx].$Obj(Application).hWnd, WM_CANCELMODE, 0, 0 ;Close any opened submenu
      invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(Application).hMenuChild, \
                          [xbx].$Obj(Application).hMenuChildWnd
      OCall xbx::Application.ManageGuiCmds, ADE_EditorID
      invoke DrawMenuBar, [xbx].$Obj(Application).hWnd  ;Redraw the new menu bar
      OCall xbx::Application.ManageGuiCmds, ADE_EditorID
    .endif

    OCall [xsi].EditorDisplays::Collection.Init, xsi, 2, 0, 2
    invoke GetClientRect, [xsi].hWnd, addr ClientRect

    ;Create a EditorDisplay instance
    New EditorDisplay
    .if xax != NULL
      mov xbx, xax
      OCall [xsi].EditorDisplays::Collection.Insert, xbx
      OCall xbx::EditorDisplay.Init, xsi, addr ClientRect, [xsi].pResources
    .endif

    ;Install Magnetism
    OCall [xsi].Snapper::Magnetism.Init, xsi, [xsi].hWnd, 10

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
    invoke SetFocus, [xbx].$Obj(EditorDisplay).View.hWnd
  .else
    DbgApiError
    invoke MessageBox, [xdi].$Obj(Application).hWnd, $OfsCStr("Window creation error"), \
                       offset szError, MB_OK or MB_ICONERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.LineNew
; Purpose:    Create a new EditorTextLine.
; Arguments:  Arg1: Character buffer size not including the ZTC.
; Return:     xax -> EditorTextLine or NULL if failed.

Method Editor.LineNew, uses xbx xsi, dCharCapacity:DWORD
  SetObject xsi
  New EditorTextLine
  .if xax != NULL
    mov xbx, xax
    lea xcx, [xsi].TextLines
    lea xdx, [xbx].$Obj(EditorTextLine).Link
    LDLL_InsertLast xcx, xdx, xax
    OCall xbx::EditorTextLine.Init, xsi
    OCall xbx::EditorTextLine.BufferResize, dCharCapacity
    .if xax == NULL
      Destroy xbx
      xor eax, eax
    .else
      mov xax, xbx
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Load
; Purpose:    Load and initialize the streamable instance from a stream object. Descendant objects
;             should redefine this method and load new members.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method Editor.Load, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local pCaption:PSTRING, WP:WINDOWPLACEMENT

  SetObject xsi
  mov xbx, pDeserInfo
  ACall xsi.Load, pStream, pDeserInfo                 ;WinPrimer returns the previous hWnd
  mov xdi, xax

  mov pCaption, $OCall(pStream::Stream.StrRead)
  OCall xsi.Init, [xsi].pOwner, NULL, pCaption
  invoke StrDispose, pCaption
  OCall [xbx].DESER_INFO.pDesLUT::DesLUT.Insert, xdi, [xsi].hWnd
  OCall pStream::Stream.BinRead, addr WP, sizeof WP
  invoke SetWindowPlacement, [xsi].hWnd, addr WP
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Editor.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cCaption[512]:CHR, cText[1024]:CHR

  ANNOTATION use:wParam lParam

  SetObject xsi
;  DbgText "Editor.OnClose"
  invoke GetKeyState, VK_CONTROL
  and ax, BIT15
  .if ZERO?                          ;If CTRL pressed => close without asking
    .ifBitSet [xsi].dFlags, EIF_DIRTY
;      mov edx, [xsi].dLanguage
;      add edx, 100
;      invoke LoadString, hInstance, edx, addr cCaption, lengthof cCaption
;      mov edx, [xsi].dLanguage
;      add edx, 101
;      invoke LoadString, hInstance, edx, addr cText, lengthof cText
      invoke StrCopy, addr cText, $OfsCStr("Are you sure ?")
      invoke StrCopy, addr cCaption, $OfsCStr("Editor close")

      ;MessageBox customization
      invoke SetWindowsHookEx, WH_CBT, offset CBTProc, hInstance, $32($invoke(GetCurrentThreadId))
      mov hCBTProc, xax
      invoke MessageBox, [xsi].hWnd, addr cText, addr cCaption, MB_YESNO + MB_ICONQUESTION
      .if eax == IDNO
        xor eax, eax
        ExitMethod
      .endif
    .endif
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.OnEnterSizeMove
; Purpose:    Event procedure for WM_ENTERSIZEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Editor.OnEnterSizeMove, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "Editor.OnEnterSizeMove"
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    OCall [xax].$Obj(EditorDisplay).View::EditorView.CaretHide
  .ColNext
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.OnExitSizeMove
; Purpose:    Event procedure for WM_EXITSIZEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Editor.OnExitSizeMove, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "Editor.OnExitSizeMove"
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    OCall [xax].$Obj(EditorDisplay).View::EditorView.CaretShow
  .ColNext
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.OnSetFocus
; Purpose:    Event procedure for WM_SETFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Editor.OnSetFocus,, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "Editor.OnSetFocus"
  SetObject xcx
  mov xax, [xcx].pFocusedView
  .if xax != NULL
    invoke SetFocus, [xax].$Obj(EditorView).hWnd
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method Editor.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ClientSize:POINT

  ANNOTATION use:wParam lParam

;  DbgText "Editor.OnSize"
  SetObject xsi
  .if wParam != SIZE_MINIMIZED && lParam != 0         ;x = 0 & y = 0
    .if [xsi].EditorDisplays.dCount != 0
      PntS2Regs lParam
      mov ClientSize.x, eax
      mov ClientSize.y, ecx
      OCall [xsi].EditorDisplays::Collection.ItemAt, 0
      invoke MoveWindow, [xax].$Obj(EditorDisplay).hWnd, \
                         0, 0, ClientSize.x, ClientSize.y, FALSE
    .endif
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Open
; Purpose:    Open a code file.
; Arguments:  Arg1: -> FullFileName.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.Open, uses xbx xdi xsi, pFullFileName:PSTRING
  local hFile:HANDLE, dFileSize:DWORD, dBytesRead:DWORD, pFileBuffer:POINTER
  local dFileLineLength:DWORD, pFileLineBegin:POINTER

  SetObject xsi
  invoke LoadCursor, 0, IDC_WAIT
  invoke SetCursor, xax
  invoke CreateFile, pFullFileName, GENERIC_READ, FILE_SHARE_READ or FILE_SHARE_WRITE, NULL, \
                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    invoke GetFileSize, hFile, NULL
    inc eax                                             ;Add space for a ZTC
    mov dFileSize, eax
    MemAlloc xax
    .if xax != NULL
      mov pFileBuffer, xax
      invoke ReadFile, hFile, pFileBuffer, dFileSize, addr dBytesRead, NULL
      .if eax != FALSE
        mov xdi, pFileBuffer
        mov eax, dFileSize
        mov CHRA ptr [xax + xdi - sizeof(CHRA)], 0      ;Set ZTC

        .while TRUE
          ;Start searching for line ends
          mov eax, dFileSize
          sub xax, xdi
          add xax, pFileBuffer
          invoke StrLFScanA, xdi, eax
          .break .if xax == NULL
          mov pFileLineBegin, xdi
          .if xax > xdi && CHRA ptr [xax - sizeof(CHRA)] == CR
            mov CHRA ptr [xax - sizeof(CHRA)], 0        ;Set ZTC
            lea xdi, [xax + sizeof(CHRA)]               ;xdi -> next CHRA
            sub xax, pFileLineBegin
            sub eax, sizeof(CHRA)                       ;Subtract LF from Length
          .else
            mov CHRA ptr [xax], 0                       ;Set ZTC
            lea xdi, [xax + sizeof(CHRA)]               ;xdi -> next CHRA
            sub xax, pFileLineBegin
          .endif
          mov dFileLineLength, eax                      ;Pessimistic value since UTF-8 chars are larger

          OCall xsi.LineNew, dFileLineLength            ;Not including the ZTC.
          .if xax == NULL
            DbgText "Failed to allocate a new EditorTextLine"
            .break
          .else
            mov xbx, xax
            inc dFileLineLength                         ;Include ZTC
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
            invoke MultiByteToWideChar, CP_ACP, 0, pFileLineBegin, dFileLineLength, \
                                        [xbx].$Obj(EditorTextLine).pBuffer, dFileLineLength
  else
            invoke MemClone, [xbx].$Obj(EditorTextLine).pBuffer, pFileLineBegin, dFileLineLength
  endif
            dec eax                                     ;Discard the ZTC from returned char count
            mov [xbx].$Obj(EditorTextLine).dLength, eax
            .if eax > [xsi].dMaxTextLineChrCount        ;Keep the largest value
              mov [xsi].dMaxTextLineChrCount, eax
            .endif
            inc [xsi].dVisTextLineCount
          .endif
        .endw

      .endif
      MemFree pFileBuffer
    .else
      DbgText "Failed to allocate memory for file read operation"
    .endif
    invoke CloseHandle, hFile
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Print
; Purpose:    Output the editor content to the printer.
; Arguments:  None.
; Return:     Nothing.

Method Editor.Print, uses xbx xdi xsi
  local PrtDlg:PRINTDLG, DocInfo:DOCINFO, cMsg[1024]:CHR
  local LogFnt:LOGFONT, hFont:HFONT, hPrvFont:HFONT, dLineCount:DWORD
  local cPrtBuffer[256]:CHR, dPosY:DWORD, TM:TEXTMETRIC
  local LogPix:POINT, PageSize:POINT, PageOffset:POINT, PrintSize:POINT

  SetObject xsi

  mov PrtDlg.lStructSize, sizeof(PrtDlg)
  m2m PrtDlg.hwndOwner, [xsi].hWnd, xax
  mov xdx, [xsi].pOwner
  mov xbx, [xdx].$Obj(ClientWnd).pOwner
  m2m PrtDlg.hDevMode, [xbx].$Obj(Application).hDevMode, xdx
  m2z PrtDlg.hDevNames                                  ;[xcx].$Obj(Application).hDevNames
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
    m2m [xbx].$Obj(Application).hDevMode, PrtDlg.hDevMode, xax
    m2m [xbx].$Obj(Application).hDevNames, PrtDlg.hDevNames, xcx
    .ifBitSet $invoke(GetDeviceCaps, PrtDlg.hDC, RASTERCAPS), RC_BITBLT
      mov DocInfo.cbSize, sizeof(DocInfo)
;      m2m DocInfo.lpszDocName, offset szDebugCenter, xax
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
      invoke MulDiv, [xbx].$Obj(Application).PrintMargin.left, LogPix.x, 2540
      sub eax, PageOffset.x
      mov edi, eax
      invoke MulDiv, [xbx].$Obj(Application).PrintMargin.top, LogPix.y, 2540
      sub eax, PageOffset.y
      invoke SetViewportOrgEx, PrtDlg.hDC, edi, eax, NULL

      mov eax, [xbx].$Obj(Application).PrintMargin.left
      add eax, [xbx].$Obj(Application).PrintMargin.right
      invoke MulDiv, eax, LogPix.x, -2540
      add eax, PageSize.x
      mov PrintSize.x, eax
      mov eax, [xbx].$Obj(Application).PrintMargin.top
      add eax, [xbx].$Obj(Application).PrintMargin.bottom
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
;      FillString LogFnt.lfFaceName, <DBG_FONT_TEXT>
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

;      mov dLineCount, $32($invoke(SendMessage, [xsi].hEdit, EM_GETLINECOUNT, 0, 0))
;      lea xdi, cPrtBuffer
;      xor ebx, ebx
;      .while ebx < dLineCount
;        invoke MemZero, xdi, sizeof(cPrtBuffer)
;        mov WORD ptr [xdi], lengthof cPrtBuffer - 1     ;Let room for the terminating zero
;        invoke SendMessage, [xsi].hEdit, EM_GETLINE, xbx, xdi
;        invoke StrLength, xdi
;        invoke TextOut, PrtDlg.hDC, 0, dPosY, xdi, eax
;        inc xbx                                         ;Increment line count
;        mov eax, TM.tmHeight
;        add dPosY, eax
;        add eax, dPosY                                  ;Check if line upper point is under the
;        .if eax > PrintSize.y                           ;  Print lower limit
;          m2z dPosY
;          invoke EndPage, PrtDlg.hDC
;          invoke StartPage, PrtDlg.hDC
;        .endif
;      .endw
;
;      invoke SelectObject, PrtDlg.hDC, hPrvFont
;      invoke DeleteObject, hFont
;
;      invoke EndPage, PrtDlg.hDC
;      invoke EndDoc, PrtDlg.hDC
;      invoke DeleteDC, PrtDlg.hDC
    .else
;      mov edx, $ObjTmpl(Application).dLanguage
;      add edx, 124
;      invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
;      invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, \
;                         MB_OK or MB_ICONERROR
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Save
; Purpose:    Save the editor content to a file.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.Save, uses xbx xsi
  local hFile:HANDLE, pMemBuffer:POINTER, dMemBufferSize:DWORD, dBytesWritten:DWORD, dResult:DWORD

  SetObject xsi
  .ifBitSet [xsi].dFlags, EIF_DIRTY
    mov dResult, FALSE
    .if [xsi].pFullFileName != NULL
      invoke CreateFile, [xsi].pFullFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, \
                         CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
      .if xax != INVALID_HANDLE_VALUE
        mov hFile, xax
        mov eax, [xsi].dMaxTextLineChrCount
        add eax, 2
        shl eax, 2                                        ;Max UTF-8 expansion (x4)
        mov dMemBufferSize, eax
        MemAlloc eax
        .if xax != NULL
          mov pMemBuffer, xax
          mov xbx, [xsi].TextLines.pFirstMember
      
          ;Start looping
          .while xbx != NULL
            lea xbx, [xbx - offset $Obj(EditorTextLine).Link]
            .ifBitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_DIRTY_LINE_PREV
              BitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_SAVED_LINE_PREV
            .endif
            .ifBitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_DIRTY_LINE_CURR
              BitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_SAVED_LINE_CURR
            .endif
            .ifBitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_DIRTY_LINE_NEXT
              BitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_SAVED_LINE_NEXT
            .endif
            xor eax, eax
            .if [xbx].$Obj(EditorTextLine).pBuffer != NULL
              invoke WideCharToMultiByte, CP_ACP, 0, [xbx].$Obj(EditorTextLine).pBuffer, \
                                          [xbx].$Obj(EditorTextLine).dLength, \
                                          pMemBuffer, dMemBufferSize, NULL, NULL
            .endif
            mov xcx, pMemBuffer
            mov DCHRA ptr [xcx + xax], LF*256 + CR      ;Add CRLF to the end   
            add eax, 2                                  ;Add these 2 characters
            invoke WriteFile, hFile, pMemBuffer, eax, addr dBytesWritten, NULL
            mov xbx, [xbx].$Obj(EditorTextLine).Link.pLinkFwrd  ;Move to next EditorTextLine.Link
          .endw
          BitClr [xsi].dFlags, EIF_NEW_FILE or EIF_DIRTY
          mov dResult, TRUE
          MemFree pMemBuffer
        .endif
        invoke CloseHandle, hFile
      .endif
    .endif
  
    .if dResult != FALSE
      ;Update all Views of this editor
      .ColForEach [xsi].EditorDisplays, ebx
        invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
      .ColNext
    .endif
  .else
    mov dResult, TRUE
  .endif
  mov eax, dResult
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SaveAs
; Purpose:    Save the editor content to a file.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SaveAs, uses xsi
  local dResult:DWORD, pIFileDialog2:POINTER
  local pIFSDlg:POINTER, pIShellItem:POINTER, pDisplayName:PSTRINGW

  SetObject xsi
  mov dResult, FALSE
  invoke CoCreateInstance, offset CLSID_FileSaveDialog, NULL, CLSCTX_ALL, \
                           offset IID_IFileSaveDialog, addr pIFSDlg
  .if SUCCEEDED(eax)
    ICall pIFSDlg::IFileSaveDialog.SetFileTypes, MultiFileSpecCount, addr MultiFileSpec
    ICall pIFSDlg::IFileSaveDialog.SetFileTypeIndex, 2
;    ICall pIFSDlg::IFileSaveDialog.SetOptions, FOS_ALLOWMULTISELECT
    ICall pIFSDlg::IFileSaveDialog.SetTitle, $OfsCStrW("Save a file as...")
    ICall pIFSDlg::IFileSaveDialog.SetOkButtonLabel, $OfsCStrW("&Save")
;    ICall pIFSDlg::IFileSaveDialog.SetFileNameLabel, $OfsCStrW("Selected file(s): ")

    ICall pIFSDlg::IFileSaveDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
    .if SUCCEEDED(eax)
      ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, $OfsCStrW("&Cancel")
      ICall pIFileDialog2::IFileDialog2.Release
    .endif

    ICall pIFSDlg::IFileSaveDialog.Show, [xsi].hWnd
    .if SUCCEEDED(eax)
      ICall pIFSDlg::IFileSaveDialog.GetResult, addr pIShellItem
      ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDisplayName
      invoke StrReplaceW, addr [xsi].pFullFileName, pDisplayName
      invoke CoTaskMemFree, pDisplayName
      BitSet [xsi].dFlags, EIF_DIRTY                    ;Force save operation
      OCall xsi.Save
      .if eax != FALSE
        mov dResult, TRUE
        invoke SetWindowTextW, [xsi].hWnd, [xsi].pFullFileName
      .endif
      ICall pIShellItem::IShellItem.Release
    .endif
    ICall pIFSDlg::IFileSaveDialog.Release
  .endif
  mov eax, dResult
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SelectAll
; Purpose:    Select all lines.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectAll, uses xsi
;  DbgText "Editor.SelectAll"
  SetObject xsi
  xor eax, eax
  .ifBitClr [xsi].dFlags, EIF_BLOCK_MODE
    mov xcx, [xsi].TextLines.pFirstMember
    .if xcx != NULL
      lea xdx, [xcx - offset $Obj(EditorTextLine).Link]
      mov [xsi].SelectionFst.pTextLine, xdx
      mov [xsi].SelectionFst.dCharIndex, 0
      mov [xsi].SelectionFst.dLineNumber, 1

      mov xcx, [xsi].TextLines.pLastMember
      lea xdx, [xcx - offset $Obj(EditorTextLine).Link]
      mov [xsi].SelectionLst.pTextLine, xdx
      mov eax, [xdx].$Obj(EditorTextLine).dLength
      mov [xsi].SelectionLst.dCharIndex, eax
      mov [xsi].SelectionLst.dLineNumber, 2

      OCall xsi.SelectionSet
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      mov eax, TRUE
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SelectionDelete
; Purpose:    Delete selection from all lines.
; Arguments:  None.
; Return:     Nothing.

Method Editor.SelectionDelete, uses xbx xdi xsi
  local dDoMerge:DWORD, pNextMember:POINTER, dLineNumber:DWORD
  
  SetObject xsi
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov xbx, [xax].LOCATION.pTextLine
    mov xdi, [xcx].LOCATION.pTextLine
    mov edx, [xax].LOCATION.dLineNumber
    mov dLineNumber, edx

    ;Check if the first and last lines need to be merged after deletion
    mov dDoMerge, FALSE
    .ifBitClr [xcx].$Obj(Editor).dFlags, EIF_BLOCK_MODE
      .if xbx != xdi
        .if [xax].LOCATION.dCharIndex > 0
          .ifBitClr [xdi].$Obj(EditorTextLine).dFlags, TLF_EOL_MARKED
            mov dDoMerge, TRUE
          .endif
        .endif
      .endif
    .endif
  
    ;Do deleting
    .while xbx != NULL
      mov edx, [xbx].$Obj(EditorTextLine).Selection.dBegIndex
      mov eax, [xbx].$Obj(EditorTextLine).Selection.dEndIndex
      sub eax, edx                                      ;Calc how many chars to delete
      .ifBitClr [xsi].dFlags, EIF_BLOCK_MODE
        .ifBitSet [xbx].$Obj(EditorTextLine).dFlags, TLF_EOL_MARKED
          .if eax == [xbx].$Obj(EditorTextLine).dLength
            ;Delete the line completely
            m2m pNextMember, [xbx].$Obj(EditorTextLine).Link.pLinkFwrd, xax  ;Goto next member
            OCall xbx::EditorTextLine.LineDelete, dLineNumber          ;§§ move into he Undo buffer
            jmp @F                                      ;Don't inc LineNumber
          .endif
        .endif
      .endif
      OCall xbx::EditorTextLine.CharDelete, edx, eax
      OCall xbx::EditorTextLine.SelectionReset
      m2m pNextMember, [xbx].$Obj(EditorTextLine).Link.pLinkFwrd, xax  ;Goto next member
      inc dLineNumber
  @@:
      .break .if xbx == xdi
      mov xbx, pNextMember
      sub xbx, offset $Obj(EditorTextLine).Link
    .endw
    
    ;Merge first and last lines if necessary
    .if dDoMerge != FALSE
      mov xbx, [xsi].SelectionRange.pBegSelInfo
      OCall [xbx].LOCATION.pTextLine::EditorTextLine.LineJoinNext, [xbx].LOCATION.dLineNumber
    .endif

    ;Cleanup
    OCall xsi.SelectionResetAll
    mov [xsi].dSelectionVisLineCnt, 0
  .endif
  
  OCall xsi.ClpBrdSetBtns
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SelectionResetAll
; Purpose:    Reset selection from all EditorTextLines.
; Arguments:  None.
; Return:     eax = TRUE if the change has a visual impact, otherwise FALSE.

Method Editor.SelectionResetAll, uses xbx xsi
;  DbgText "Editor.SelectionReset"
  SetObject xsi
  OCall xsi.SelectionResetLines
  mov ebx, eax
  mov [xsi].SelectionRange.pBegSelInfo, NULL
  mov [xsi].SelectionRange.pEndSelInfo, NULL
  mov [xsi].SelectionFst.pTextLine, NULL
  mov [xsi].SelectionFst.dCharIndex, 0
  mov [xsi].SelectionFst.dLineNumber, 0
  mov [xsi].SelectionLst.pTextLine, NULL
  mov [xsi].SelectionLst.dCharIndex, 0
  mov [xsi].SelectionLst.dLineNumber, 0
  mov [xsi].dSelectionVisLineCnt, 0

  OCall xsi.ClpBrdSetBtns
  mov eax, ebx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SelectionResetLines
; Purpose:    Reset selection from all EditorTextLines.
; Arguments:  None.
; Return:     eax = TRUE if the change has a visual impact, otherwise FALSE.

Method Editor.SelectionResetLines, uses xbx xdi xsi
  local dNeedRedrawing:DWORD

;  DbgText "Editor.SelectionResetLines"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov xax, [xsi].SelectionRange.pBegSelInfo
  .if xax != NULL
    mov xbx, [xax].LOCATION.pTextLine
    mov xax, [xsi].SelectionRange.pEndSelInfo
    mov xdi, [xax].LOCATION.pTextLine
  
    .while TRUE
      OCall xbx::EditorTextLine.SelectionReset
      add dNeedRedrawing, eax
      .break .if xbx == xdi
      mov xbx, [xbx].$Obj(EditorTextLine).Link.pLinkFwrd  ;Goto next line
      .break .if xbx == NULL                              ;Just in case
      sub xbx, offset $Obj(EditorTextLine).Link
    .endw
  .endif

  xor eax, eax
  cmp dNeedRedrawing, 0
  setnz al
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SelectionSet
; Purpose:    Arrange the selection parameters and set the selection of affected TextLines.
; Arguments:  None.
; Return:     Nothing.
; Note:       On exit, dSelectionVisLineCnt contains the number of selected visible lines.

Method Editor.SelectionSet, uses xdi xbx xsi
  SetObject xsi
;  DbgText "Editor.SelectionSet"

  mov [xsi].dSelectionVisLineCnt, 0
  .if [xsi].SelectionFst.pTextLine != NULL && [xsi].SelectionLst.pTextLine != NULL 
    lea xcx, [xsi].SelectionFst
    lea xdx, [xsi].SelectionLst
  
    ;Sanity check
    .if SDWORD ptr [xcx].LOCATION.dCharIndex < 0
      mov [xcx].LOCATION.dCharIndex, 0
    .endif
    .if SDWORD ptr [xdx].LOCATION.dCharIndex < 0
      mov [xdx].LOCATION.dCharIndex, 0
    .endif
  
    ;Arrange the selection by topology (Begin/End)
    mov eax, [xcx].LOCATION.dLineNumber
    .if eax == [xdx].LOCATION.dLineNumber
      mov eax, [xcx].LOCATION.dCharIndex
      .if eax == [xdx].LOCATION.dCharIndex
        mov [xsi].SelectionRange.pBegSelInfo, NULL        ;Reset selection begin
        mov [xsi].SelectionRange.pEndSelInfo, NULL        ;Reset selection end
        jmp @@Exit                                        ;Nothing selected => Exit
      .endif
      .if eax > [xdx].LOCATION.dCharIndex
        xchg xcx, xdx                                     ;Switch POINTERs
      .endif
    .elseif eax > [xdx].LOCATION.dLineNumber
      xchg xcx, xdx                                       ;Switch POINTERs
    .endif
    mov [xsi].SelectionRange.pBegSelInfo, xcx             ;Set selection begin
    mov [xsi].SelectionRange.pEndSelInfo, xdx             ;Set selection end
  
    ;Set selection indices on all affected TextLines
    .ifBitSet [xsi].dFlags, EIF_BLOCK_MODE
      ;Block mode selection
      mov xax, [xcx].LOCATION.pTextLine
      mov xdi, [xdx].LOCATION.pTextLine
      mov ecx, [xcx].LOCATION.dCharIndex
      mov edx, [xdx].LOCATION.dCharIndex
  
      ;Make sure that ecx < edx
      .if ecx > edx
        xchg ecx, edx
      .endif
  
      .while TRUE
        .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
          inc [xsi].dSelectionVisLineCnt
        .endif
        mov [xax].$Obj(EditorTextLine).Selection.dBegIndex, ecx
        mov [xax].$Obj(EditorTextLine).Selection.dEndIndex, edx
        .break .if xax == xdi                             ;Last selected line reached
        mov xax, [xax].$Obj(EditorTextLine).Link.pLinkFwrd
        .break .if xax == NULL
        sub xax, offset $Obj(EditorTextLine).Link
      .endw
    .else
      ;Insert/Overwrite mode selection
      mov xax, [xcx].LOCATION.pTextLine
      .if xax == [xdx].LOCATION.pTextLine
        .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
          inc [xsi].dSelectionVisLineCnt
        .endif
       ;Make sure that ecx < edx, but only on the same EditorTextLine!
        mov ecx, [xcx].LOCATION.dCharIndex
        mov edx, [xdx].LOCATION.dCharIndex
        mov edi, [xax].$Obj(EditorTextLine).dLength
        cmp edx, edi
        cmova edx, edi
        .if ecx > edx
          xchg ecx, edx
        .endif
        mov [xax].$Obj(EditorTextLine).Selection.dBegIndex, ecx
        mov [xax].$Obj(EditorTextLine).Selection.dEndIndex, edx
  
      .else
        ;Set the first line
        mov xax, [xcx].LOCATION.pTextLine
        mov xdi, [xdx].LOCATION.pTextLine
        mov ecx, [xcx].LOCATION.dCharIndex
        mov edx, [xdx].LOCATION.dCharIndex
        .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
          inc [xsi].dSelectionVisLineCnt
        .endif
  
        mov [xax].$Obj(EditorTextLine).Selection.dBegIndex, ecx   ;Set begin index of 1st line
        .while xax != xdi
          mov xcx, xax
          ;Move to the next line
          mov xax, [xax].$Obj(EditorTextLine).Link.pLinkFwrd
          sub xax, offset $Obj(EditorTextLine).Link
          .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
            inc [xsi].dSelectionVisLineCnt
          .endif
          BitSet [xcx].$Obj(EditorTextLine).dFlags, TLF_EOL_MARKED
          mov [xax].$Obj(EditorTextLine).Selection.dBegIndex, 0   ;Set begin index to zero
          m2m [xcx].$Obj(EditorTextLine).Selection.dEndIndex, [xcx].$Obj(EditorTextLine).dLength, ebx
        .endw
        mov edi, [xax].$Obj(EditorTextLine).dLength       ;Set end index of last line
        cmp edx, edi
        cmova edx, edi
        mov [xax].$Obj(EditorTextLine).Selection.dEndIndex, edx
      .endif
    .endif
  .endif

@@Exit:
  OCall xsi.ClpBrdSetBtns
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorTextLine.SetDirty
; Purpose:    Set the dirty flag.
; Arguments:  Arg1: TRUE to set the flag, otherwise FALSE.
; Return:     Nothing.

Method Editor.SetDirty,, dAction:DWORD
  SetObject xcx
  .if dAction == FALSE
    BitClr [xcx].dFlags, EIF_DIRTY
  .else
    BitSet [xcx].dFlags, EIF_DIRTY
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Editor.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(Editor.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szEditorClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD"))
  m2z WC.hIconSm
  m2z WC.hCursor

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.Store
; Purpose:    Store the streamable instance in a stream object. Descendant objects should redefine
;             this method and store new members.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Editor.Store, uses xsi, pStream:$ObjPtr(Stream)
  local cBuffer[1024]:CHR, WP:WINDOWPLACEMENT

  SetObject xsi
  ACall xsi.Store, pStream                              ;Store pSelf, ..., hWnd
;  OCall pStream::Stream.BinWrite32, [xsi].dColorIndex
  invoke GetWindowText, [xsi].hWnd, addr cBuffer, lengthof cBuffer
  OCall pStream::Stream.StrWrite, addr cBuffer
  mov WP.length_, sizeof WP
  invoke GetWindowPlacement, [xsi].hWnd, addr WP
  OCall pStream::Stream.BinWrite, addr WP, sizeof WP
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.UpdateStatusbar
; Purpose:    Draw new information on the Statusbar.
; Arguments:  None.
; Return:     Nothing.

Method Editor.UpdateStatusbar, uses xbx xdi xsi
  local dFirstCharIndex:DWORD, dLastCharIndex:DWORD, dSelCount:DWORD
  local dLineNumberFirst:DWORD, dLineCharPos:DWORD, dFirstLineCharIndex:DWORD
  local dLineCount:DWORD, cTextBuffer[1024]:CHR, wResText[1024]:CHRW

;  DbgText "DbgMdiChildTxt.UpdateStatusbar"
  SetObject xsi
  mov xax, [xsi].pOwner
  invoke SendMessage, [xax].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
  .if xax == [xsi].hWnd                                 ;Only if this window is the active one
    mov xcx, [xsi].pOwner
    mov xbx, [xcx].$Obj(ClientWnd).pOwner               ;xbx -> Application

;    invoke SendMessage, [xsi].hEdit, EM_GETSEL, addr dFirstCharIndex, addr dLastCharIndex
;    mov eax, dLastCharIndex
;    sub eax, dFirstCharIndex
;    mov dSelCount, eax
;    invoke SendMessage, [xsi].hEdit, EM_LINEFROMCHAR, dFirstCharIndex, 0
;    mov dLineNumberFirst, eax
;    invoke SendMessage, [xsi].hEdit, EM_LINEFROMCHAR, dLastCharIndex, 0
;    sub eax, dLineNumberFirst
;    inc eax
;    mov dLineCount, eax

    .if dSelCount == 0
      OCall [xbx].$Obj(Application).SBar::Statusbar.SetPartText, 2, NULL, SBT_SUNKEN
    .else
      lea xdi, cTextBuffer
      mov edx, [xbx].$Obj(Application).dLangID
      add edx, 142                                      ;"Selection"
      invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
      WriteF xdi, "¦SU: ", addr wResText
      mov edx, [xbx].$Obj(Application).dLangID
      .if dSelCount == 1
        add edx, 143                                    ;"character"
        invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
        WriteF xdi, "1 ¦SU", addr wResText
      .else
        add edx, 144                                    ;"characters"
        invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
        WriteF xdi, "¦UD ¦SU", dSelCount, addr wResText
      .endif
      WriteF xdi, ", "
      mov edx, [xbx].$Obj(Application).dLangID
      .if dLineCount == 1
        add edx, 145                                    ;"line"
        invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
        WriteF xdi, "1 ¦SU", addr wResText
      .else
        add edx, 146                                    ;"lines"
        invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
        WriteF xdi, "¦UD ¦SU", dLineCount, addr wResText
      .endif
      OCall [xbx].$Obj(Application).SBar::Statusbar.SetPartText, 2, addr cTextBuffer, SBT_SUNKEN
    .endif

;    lea xdi, cTextBuffer
;    invoke GetWindowText, [xsi].hWnd, xdi, lengthof(cTextBuffer)
;    lea xdi, [xdi + sizeof(CHR)*xax]
;    invoke SendMessage, [xsi].hEdit, EM_LINEINDEX, dLineNumberFirst, 0
;    mov dFirstLineCharIndex, eax
;    mov ecx, dFirstCharIndex
;    sub ecx, eax
;    mov dLineCharPos, ecx
;    mov edx, [xbx].$Obj(Application).dLanguage
;    add edx, 140                                        ;"Caret at line"
;    invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;    inc dLineNumberFirst                                ;First line index is 0 => 1
;    WriteF xdi, ": ¦SU ¦UD, ", addr wResText, dLineNumberFirst
;    mov edx, [xbx].$Obj(Application).dLanguage
;    add edx, 141                                        ;"position"
;    invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;    mov eax, dFirstLineCharIndex
;    sub dFirstCharIndex, eax
;    WriteF xdi, "¦SU ¦UD", addr wResText, dFirstCharIndex
;    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, addr cTextBuffer, SBT_SUNKEN
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method Editor.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgMessage uMsg,, "Editor"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xcx, [xax].CREATESTRUCT.lpCreateParams
    mov xsi, [xcx].MDICREATESTRUCT.lParam
    mrm [xsi].$Obj(MdiChildWnd).hWnd, pSelf, xcx        ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax                                       ;  it returns NULL
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefMDIChildProc, pSelf>                ;xsi -> Object Instance
MethodEnd
