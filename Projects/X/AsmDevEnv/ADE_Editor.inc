; ==================================================================================================
; Title:      ADE_Editor.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Editor implementation.
; ==================================================================================================


;Editor Flags
EDF_NEW_FILE                equ   BIT00
EDF_DIRTY                   equ   BIT01
EDF_OVERWRITE_MODE          equ   BIT02
EDF_BLOCK_MODE              equ   BIT03
EDF_CARET_LOCKED            equ   BIT04


; ==================================================================================================
; Editor implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     Editor.ClpBrdDelete
; Purpose:    Clipboard delete opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.ClpBrdDelete, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pFocusedView
  .if xbx != NULL
    OCall xbx::EditorView.ClpBrdDelete
    .if eax != FALSE
      invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW   ;Redraw Views
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.ClpBrdCopy
; Purpose:    Clipboard copy opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.ClpBrdCopy, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pFocusedView
  .if xbx != NULL
    OCall xbx::EditorView.ClpBrdCopy
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.ClpBrdCut
; Purpose:    Clipboard cut opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.ClpBrdCut, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pFocusedView
  .if xbx != NULL
    OCall xbx::EditorView.ClpBrdCut
    .if eax != FALSE
      invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW   ;Redraw Views
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.ClpBrdPaste
; Purpose:    Clipboard paste opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Link:       https://msdn.microsoft.com/en-us/library/windows/desktop/ms649016(v=vs.85).aspx#_win32_Copying_Information_to_the_Clipboard
; Note:       CF_TEXT = Each line ends with a carriage return/linefeed (CR-LF) combination.
;             A null character signals the end of the data. Use this format for ANSI text.

Method Editor.ClpBrdPaste, uses xbx xsi
  SetObject xsi
  mov xbx, [xsi].pFocusedView
  .if xbx != NULL
    OCall xbx::EditorView.ClpBrdPaste
    .if eax != FALSE
      invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW   ;Redraw Views
      OCall xbx::EditorView.CaretSet
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.CreateSelAction
; Purpose:    Create a new Selection ACTION.
; Arguments:  Arg1: Assocaiated action group.
; Return:     Nothing.
; Note:       Must be the first ACTION in the group. Since the ACTIONs are processed in reverse
;             order, the selection ACTION is the last processed.

Method Editor.CreateSelAction,, dActionGroup:DWORD

;  DbgText "Editor.CreateSelAction"
  MemAlloc sizeof(ACTION)
  .if xax != NULL
    SetObject xcx
    m2m [xax].ACTION.dGroup, dActionGroup, edx
    mov [xax].ACTION.dAction, AAT_SELECTION
    mov xdx, [xcx].SelectionRange.pBegSelInfo
    .if xdx != NULL
      s2s [xax].ACTION.SelBegLocation, LOCATION ptr [xdx], xdx, xmm0
    .else
      mov [xax].ACTION.SelBegLocation.dCharIndex, 0
      mov [xax].ACTION.SelBegLocation.dLineIndex, 0
    .endif
    mov xdx, [xcx].SelectionRange.pEndSelInfo
    .if xdx != NULL
      s2s [xax].ACTION.SelEndLocation, LOCATION ptr [xdx], xdx, xmm0
    .else
      mov [xax].ACTION.SelEndLocation.dCharIndex, 0
      mov [xax].ACTION.SelEndLocation.dLineIndex, 0
    .endif
    OCall [xcx].Actions::ActionCollection.Insert, xax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.Done
; Purpose:    Finalize the Editor object.
; Arguments:  None.
; Return:     Nothing.

Method Editor.Done, uses xbx xdi xsi
  SetObject xsi

;  DbgText "Editor.Done"
  ;Destroy all lines
  OCall [xsi].Lines::Collection.Done

  ;Free resources
  mov xdi, [xsi].pOwner
  mov xbx, [xdi].$Obj(ClientWnd).pOwner
  OCall [xsi].Actions::ActionCollection.Done
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

; --------------------------------------------------------------------------------------------------
; Method:     Editor.FindStr
; Purpose:    Search a string from a starting location to an ending location.
;             Select it and update the stating location for the next search.
; Arguments:  Arg1: -> Search string.
;             Arg2: -> Starting LOCATION.
;             Arg3: -> Ending LOCATION.
;             Arg4: -> FINDDLGCHOICES.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.FindStr, uses xbx xdi xsi, pSrchStr:PSTRING, pSrchBeg:PLOCATION, pSrchEnd:PLOCATION, \
                                         pChoices:PFINDDLGCHOICES
  local dRetVal:DWORD
  local dCurLineIndex:DWORD, dStartCharIndex:DWORD, dSrchLength:DWORD

  SetObject xsi
  mov dRetVal, FALSE
  OCall xsi.SelectionResetAll
  mov dSrchLength, $32($invoke(StrLength, pSrchStr))

  mov xdi, pChoices
  .if [xdi].FINDDLGCHOICES.dDirection == FDD_DOWN || [xdi].FINDDLGCHOICES.dDirection == FDD_ALL
    ;Direction: FDD_DOWN or FDD_ALL
    mov xbx, pSrchBeg
    mov edx, [xbx].LOCATION.dLineIndex
    .if edx >= [xsi].Lines.dCount
      jmp @@Exit
    .endif
    OCall [xsi].Lines::Collection.ItemAt, edx
    mov ecx, [xbx].LOCATION.dCharIndex
    mov edx, [xax].$Obj(EditorLine).dLength
    .if ecx > edx
      mov ecx, edx
    .endif
    mov dStartCharIndex, ecx
    m2m dCurLineIndex, [xbx].LOCATION.dLineIndex, edx

    ;Start searching line by line and break if a match is found
    .while TRUE
      ;Check if the current line is the last
      mov xbx, xax                                      ;xbx -> current EditorLine
      mov xax, pSrchEnd
      mov edx, [xax].LOCATION.dLineIndex
      .if edx != dCurLineIndex
        ;  |----|ABCDEFGHIJK|                           !Ending line => up to the last line char
        ;  0    A           dLength
        mov edx, [xbx].$Obj(EditorLine).dLength
      .else
        ;  |----|ABCDEF|----|                           Ending line => up to the last search char
        ;  0    A     End   dLength
        mov edx, [xax].LOCATION.dCharIndex              ;Last search character
      .endif
      sub edx, dStartCharIndex
      mov xcx, [xbx].$Obj(EditorLine).pBuffer
      mov eax, dStartCharIndex
      lea xcx, [xcx + sizeof(CHR)*xax]

      .ifBitSet [xdi].FINDDLGCHOICES.dOptions, FDO_MATCH_CASE
        invoke StrCCPos, xcx, edx, pSrchStr, dSrchLength
      .else
        invoke StrCCIPos, xcx, edx, pSrchStr, dSrchLength
      .endif

      .if xax != NULL
        .break .if !([xdi].FINDDLGCHOICES.dOptions & FDO_WHOLE_WORD)  ;Match found =>
                                                                      ;break if not whole Word
        ;FDO_WHOLE_WORD => Check the end
        mov ecx, dSrchLength
        movzx edx, CHR ptr [xax + xcx*sizeof(CHR)]
        GetCharType edx, ecx
        .if !(ecx & CHR_WORD)
          ;Check the begin
          .break .if xax == [xbx].$Obj(EditorLine).pBuffer  ;First char is at buffer begin
          movzx edx, CHR ptr [xax - sizeof(CHR)]
          GetCharType edx, ecx
          .break .if !(ecx & CHR_WORD)
        .endif
      .endif

      ;Check exit condition
      xor eax, eax
      mov xcx, pSrchEnd
      mov edx, [xcx].LOCATION.dLineIndex
      .break .if edx == dCurLineIndex                   ;Last line => break
      ;Move to next EditorLine
      inc dCurLineIndex
      mov edx, dCurLineIndex
      .break .if edx >= [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, edx

      mov dStartCharIndex, 0
    .endw

  .else
    ;Direction: FDD_UP
    mov xbx, pSrchBeg
    mov edx, [xbx].LOCATION.dLineIndex
    .if edx >= [xsi].Lines.dCount
      jmp @@Exit
    .endif
    OCall [xsi].Lines::Collection.ItemAt, edx
    mov ecx, [xbx].LOCATION.dCharIndex
    mov edx, [xax].$Obj(EditorLine).dLength
    .if ecx > edx
      mov ecx, edx
    .endif
    mov dStartCharIndex, ecx
    m2m dCurLineIndex, [xbx].LOCATION.dLineIndex, edx

    ;Start searching line by line and break if a match is found
    .while TRUE
      ;Check if the current line is the first
      mov xbx, xax                                      ;xbx -> current EditorLine
      mov xax, pSrchEnd
      mov edx, [xax].LOCATION.dLineIndex
      .if edx != dCurLineIndex
        ;  |ABCDEFGHIJK|----|                           !Begin line => up to the first line char
        ;  0           A    dLength
        mov edx, dStartCharIndex
        mov xcx, [xbx].$Obj(EditorLine).pBuffer
      .else
        ;  |----|ABCDEF|----|                           Begin line => up to the last search char
        ;  0   End     A    dLength
        mov edx, dStartCharIndex
        mov eax, [xax].LOCATION.dCharIndex              ;End
        sub edx, eax
        mov xcx, [xbx].$Obj(EditorLine).pBuffer
        lea xcx, [xcx + sizeof(CHR)*xax]
      .endif

      .ifBitSet [xdi].FINDDLGCHOICES.dOptions, FDO_MATCH_CASE
        invoke StrRCCPos, xcx, edx, pSrchStr, dSrchLength
      .else
        invoke StrRCCIPos, xcx, edx, pSrchStr, dSrchLength
      .endif

      .if xax != NULL
        .break .if [xdi].FINDDLGCHOICES.dOptions & FDO_WHOLE_WORD   ;Match found => break

        ;FDO_WHOLE_WORD => Check the end
        mov ecx, dSrchLength
        movzx edx, CHR ptr [xax + xcx*sizeof(CHR)]
        GetCharType edx, ecx
        .if !(ecx & CHR_WORD)
          ;Check the begin
          .break .if xax == [xbx].$Obj(EditorLine).pBuffer  ;First char is at buffer begin
          movzx edx, CHR ptr [xax - sizeof(CHR)]
          GetCharType edx, ecx
          .break .if !(ecx & CHR_WORD)
        .endif
      .endif

      ;Check exit condition
      xor eax, eax
      mov xcx, pSrchEnd
      mov edx, [xcx].LOCATION.dLineIndex
      .break .if edx == dCurLineIndex                   ;Last line => break
      ;Move to prev EditorLine
      dec dCurLineIndex
      mov edx, dCurLineIndex
      .break .if edx >= [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, edx

      m2m dStartCharIndex, [xax].$Obj(EditorLine).dLength, edx
    .endw
  .endif

  .if xax != NULL
    ;Select the match
    mov edx, dCurLineIndex
    mov [xsi].SelectionFst.LOCATION.dLineIndex, edx
    mov [xsi].SelectionLst.LOCATION.dLineIndex, edx
    sub xax, [xbx].$Obj(EditorLine).pBuffer
    shr eax, 1
    mov [xsi].SelectionFst.LOCATION.dCharIndex, eax
    add eax, dSrchLength
    mov [xsi].SelectionLst.LOCATION.dCharIndex, eax
    OCall xsi.SelectionSet

    ;Set the caret at the end of the selection
    mov xcx, [xsi].pFocusedView
    s2s [xcx].$Obj(EditorView).CaretLocation, [xsi].SelectionLst, xax, xax
    OCall xcx::EditorView.CaretSet

    ;Bring match in View
    mov xcx, [xsi].pFocusedView
    mov eax, [xcx].$Obj(EditorView).CaretLocation.dLineIndex
    .if eax < [xcx].$Obj(EditorView).FirstVisChar.dLineIndex
      OCall xcx::EditorView.ScrollCaretInViewTop
    .else
      OCall xcx::EditorView.ScrollCaretInViewBottom
    .endif

    ;Update start information for next search
    mov xax, pSrchBeg
    m2m [xax].LOCATION.dLineIndex, dCurLineIndex, edx
    .if [xdi].FINDDLGCHOICES.dDirection == FDD_DOWN || [xdi].FINDDLGCHOICES.dDirection == FDD_ALL
      mov ecx, [xsi].SelectionLst.dCharIndex
    .else
      mov ecx, [xsi].SelectionFst.dCharIndex
    .endif
    mov [xax].LOCATION.dCharIndex, ecx

    mov dRetVal, TRUE

  .endif

@@Exit:
  mov eax, dRetVal
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.HilitedWordReset
; Purpose:    Reset the Hilited Word.
; Arguments:  None.
; Return:     Nothing.

Method Editor.HilitedWordReset
  SetObject xcx
  mov [xcx].pHilitedWord, NULL
  mov [xcx].dHilitedLen, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.InformDeletionOf
; Purpose:    Inform all Views that a specific line was deleted.
; Arguments:  Arg1: Line index.
; Return:     Nothing.

Method Editor.InformDeletionOf, uses xbx xsi, dLineIndex:DWORD
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    OCall xax::EditorDisplay.InformDeletionOf, dLineIndex
  .ColNext
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.InformInsertionOf
; Purpose:    Inform all Views that a specific line was inserted.
; Arguments:  Arg1: Line index.
; Return:     Nothing.

Method Editor.InformInsertionOf, uses xbx xsi, dLineIndex:DWORD
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    OCall xax::EditorDisplay.InformInsertionOf, dLineIndex
  .ColNext
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.Init
; Purpose:    Initialize the Editor object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> EditorResources.
;             Arg2: -> WIDE FileName string.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Note:       This method creates a hidden MDI window that needs to be shown using ShowWindow.

Method Editor.Init, uses xbx xdi xsi, pOwner:POINTER, pResources:$ObjPtr(EditorResources), pFileName:PSTRINGW
  local cBuffer[MAX_PATH]:CHR, dStyle:DWORD

  SetObject xsi
  ACall xsi.Init, pOwner                                ;hWnd is set in WndProc
  m2m [xsi].pResources, pResources, xax
  OCall [xsi].Lines::Collection.Init, xsi, 100, 100, COL_MAX_CAPACITY

  mov xdi, pOwner                                       ;xdi -> ClientWnd
  .if pFileName == NULL
    BitSet [xsi].dFlags, EDF_NEW_FILE or EDF_DIRTY
    ;Insert an empty line
    OCall xsi.LineNew, 0, 0
    mov [xsi].dMaxLineCharCount, 0
    inc [xsi].dVisLineCount

    inc [xdi].$Obj(ClientWnd).dUnnamedCount
    lea xbx, cBuffer
    WriteFW xbx, "Unnamed ¦UD", [xdi].$Obj(ClientWnd).dUnnamedCount
    lea xcx, cBuffer
  .else
    OCall xsi.Open, pFileName
    .if eax == FALSE
      ExitMethod
    .endif
    mov xcx, pFileName
  .endif
  mov [xsi].pFullFileName, $invoke(StrNewW, xcx)
  
  ;Check if the avtive window is maximized
  mov xcx, pOwner                                       ;-> ClientWnd
  mov dStyle, 0
  invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
  .if xax != 0
    invoke IsZoomed, xax
    .if eax != FALSE
      mov dStyle, WS_MAXIMIZE
    .endif
  .endif

  invoke CreateMDIWindowW, offset szEditorClassName, [xsi].pFullFileName, dStyle, \
                           CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                           [xdi].$Obj(ClientWnd).hWnd, hInstance, pSelf
  .if xax != NULL
    invoke ShowWindow, [xsi].hWnd, SW_HIDE              ;Short flicker but acceptable
    .if [xdi].$Obj(ClientWnd).dChildCount == 1          ;First child window ?
      mov xbx, [xdi].$Obj(ClientWnd).pOwner             ;xbx -> Application
      invoke SendMessage, [xbx].$Obj(Application).hWnd, WM_CANCELMODE, 0, 0 ;Close any opened submenu
      invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(Application).hMenuChild, \
                          [xbx].$Obj(Application).hMenuChildWnd
      OCall xbx::Application.ManageGuiCmds, [xsi].hWnd
      invoke DrawMenuBar, [xbx].$Obj(Application).hWnd  ;Redraw the new menu bar
    .endif
    OCall xsi.ManageEditCmds

    OCall [xsi].EditorDisplays::Collection.ItemAt, 0
    invoke SetFocus, [xax].$Obj(EditorDisplay).View.hWnd
    mov eax, TRUE
  .else
    DbgApiError
    invoke MessageBox, [xdi].$Obj(Application).hWnd, $OfsCStr("Editor creation error."), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.InternetSearch
; Purpose:    Open Google web page for a search of the line selection. 
; Arguments:  None.
; Return:     Nothing.

Method Editor.InternetSearch, uses xbx xdi xsi
  local cSearchBuffer[4096]:CHR
  
  SetObject xsi
  mov xbx, [xsi].SelectionRange.pBegSelInfo
  mov xdx, [xsi].SelectionRange.pEndSelInfo
  .if xbx != NULL && xdx != NULL
    mov eax, [xbx].LOCATION.dLineIndex
    .if eax == [xdx].LOCATION.dLineIndex                ;Same line?
      .if eax < [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, eax
        mov xdi, [xax].$Obj(EditorLine).pBuffer
        mov ecx, [xbx].LOCATION.dCharIndex
        lea xdi, [xdi + xcx*sizeof(CHR)]
        mov xdx, [xsi].SelectionRange.pEndSelInfo
        mov eax, [xdx].LOCATION.dCharIndex
        sub eax, [xbx].LOCATION.dCharIndex
        FillString cSearchBuffer, <https://www.google.com/search?q=>
        invoke StrCCopy, addr [cSearchBuffer + sizeof(CHR)*??StrLen], xdi, eax 
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), addr cSearchBuffer, NULL, NULL, SW_SHOWNORMAL
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.LineNew
; Purpose:    Create a new EditorLine and adds it to the end.
; Arguments:  Arg1: Character buffer size not including the ZTC.
;             Arg2: ActionGroup. If 0, no ACTION will be logged.
; Return:     xax -> EditorLine or NULL if failed.

Method Editor.LineNew, uses xdi xsi, dCharCapacity:DWORD, dActionGroup:DWORD
  SetObject xsi
  New EditorLine
  .if xax != NULL
    mov xdi, xax
    OCall xdi::EditorLine.Init, xsi
    OCall xdi::EditorLine.BufferResize, dCharCapacity
    .if xax == NULL
      Destroy xdi
      xor eax, eax
    .else
      ;Keep track of the change
      .if dActionGroup != 0
        MemAlloc sizeof(ACTION)
        .if xax != NULL
          mov [xax].ACTION.dAction, AAT_INSERTLINE
          m2m [xax].ACTION.dGroup, dActionGroup, ecx
          mov [xax].ACTION.pEditorLine, xdi
          m2m [xax].ACTION.dLineIndex, [xsi].Lines.dCount, edx
          OCall [xsi].Actions::ActionCollection.Insert, xax
        .endif
      .endif
      OCall [xsi].Lines::Collection.Insert, xdi
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
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
  ACall xsi.Load, pStream, pDeserInfo                   ;WinPrimer returns the previous hWnd
  mov xdi, xax

  mov pCaption, $OCall(pStream::Stream.StrRead)
  OCall xsi.Init, [xsi].pOwner, NULL, pCaption
  invoke StrDispose, pCaption
  OCall [xbx].DESER_INFO.pDesLUT::DesLUT.Insert, xdi, [xsi].hWnd
  OCall pStream::Stream.BinRead, addr WP, sizeof WP
  invoke SetWindowPlacement, [xsi].hWnd, addr WP
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.ManageEditCmds
; Purpose:    Set the state of the Edit related buttons and menu items like the
;             cut, copy & paste clipboard buttons.
; Arguments:  None.
; Return:     Nothing.

Method Editor.ManageEditCmds, uses xbx xdi xsi
  local hCurrentMenu:HMENU, dActivate:DWORD

;  DbgText "Editor.ManageEditCmds"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(ClientWnd).pOwner
  mov hCurrentMenu, $invoke(GetMenu, [xdi].$Obj(Application).hWnd)   ;Get the current menu
  .if [xsi].SelectionRange.pBegSelInfo == NULL || [xsi].SelectionRange.pEndSelInfo == NULL
    ;No selection
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_DELETE, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_INDENT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_OUTDENT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COMMENT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_UNCOMMENT, FALSE
    mov xbx, hCurrentMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_INDENT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_OUTDENT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COMMENT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_UNCOMMENT, MF_BYCOMMAND or MF_GRAYED
    mov xbx, [xdi].$Obj(Application).hMenuContextEditor
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_INETSEARCH, MF_BYCOMMAND or MF_GRAYED
  .else
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_DELETE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_INDENT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_OUTDENT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COMMENT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_UNCOMMENT, TRUE
    mov xbx, hCurrentMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_INDENT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_OUTDENT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COMMENT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_UNCOMMENT, MF_BYCOMMAND or MF_ENABLED
    mov xbx, $ObjTmpl(Application).hMenuContextEditor
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_DELETE, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_INETSEARCH, MF_BYCOMMAND or MF_ENABLED
  .endif

  ;Paste command
  mov dActivate, FALSE
  .if $invoke(IsClipboardFormatAvailable, CF_TEXT)
    mov dActivate, TRUE
  .else
    .if $invoke(IsClipboardFormatAvailable, CF_UNICODETEXT)
      mov dActivate, TRUE
    .endif
  .endif

  lea xbx, [xdi].$Obj(Application).TbEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, dActivate
  .if dActivate
    mov ebx, MF_BYCOMMAND or MF_ENABLED
  .else
    mov ebx, MF_BYCOMMAND or MF_GRAYED
  .endif
  invoke EnableMenuItem, hCurrentMenu, IDM_EDIT_PASTE, ebx
  invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_PASTE, ebx

  .if [xsi].Actions.dActionIndex == 0
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_UNDO, FALSE
    invoke EnableMenuItem, hCurrentMenu, IDM_EDIT_UNDO, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_UNDO, MF_BYCOMMAND or MF_GRAYED
  .else
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_UNDO, TRUE
    invoke EnableMenuItem, hCurrentMenu, IDM_EDIT_UNDO, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_UNDO, MF_BYCOMMAND or MF_ENABLED
  .endif

  mov edx, [xsi].Actions.dActionIndex
  .if edx < [xsi].Actions.dCount
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_REDO, TRUE
    invoke EnableMenuItem, hCurrentMenu, IDM_EDIT_REDO, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_REDO, MF_BYCOMMAND or MF_ENABLED
  .else
    lea xbx, [xdi].$Obj(Application).TbEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_REDO, FALSE
    invoke EnableMenuItem, hCurrentMenu, IDM_EDIT_REDO, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_REDO, MF_BYCOMMAND or MF_GRAYED
  .endif

  lea xbx, [xdi].$Obj(Application).TbEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_FIND, TRUE
  invoke EnableMenuItem, hCurrentMenu, IDM_EDIT_FIND, MF_BYCOMMAND or MF_ENABLED
  invoke EnableMenuItem, [xdi].$Obj(Application).hMenuContextEditor, IDM_EDIT_FIND, MF_BYCOMMAND or MF_ENABLED

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Editor.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
;  DbgText "Editor.OnClose"
  OCall xsi.Save
  .if eax == IDCANCEL
    xor eax, eax
  .else
    invoke DefMDIChildProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.OnClose
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Editor.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local ClientRect:RECT

  ANNOTATION use:wParam lParam

  SetObject xsi
;  DbgText "Editor.OnCreate"

  OCall [xsi].EditorDisplays::Collection.Init, xsi, 2, 2, COL_MAX_CAPACITY
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

  OCall [xsi].Actions::ActionCollection.Init, xsi, 100, 100, COL_MAX_CAPACITY

  invoke DefWindowProc, [xsi].hWnd, WM_CREATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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
  .if wParam != SIZE_MINIMIZED && lParam != 0           ;x = 0 & y = 0
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

; --------------------------------------------------------------------------------------------------
; Method:     Editor.Open
; Purpose:    Open a code file.
; Arguments:  Arg1: -> FullFileName.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Note:       Statusbar is updated when the new child window is activated.

Method Editor.Open, uses xbx xdi xsi, pFullFileName:PSTRINGW
  local hFile:HANDLE, dFileSize:DWORD, dBytesRead:DWORD, pFileBuffer:POINTER, pDataBegin:POINTER
  local dFileLineLength:DWORD, pFileLineBegin:POINTER, dLineTermination:DWORD, dFileFormat:DWORD
  local dRetValue:DWORD, cMessage[2048]:CHR

  SetObject xsi
  mov dRetValue, FALSE
  mov xbx, [xsi].pResources
  m2m dLineTermination, [xbx].$Obj(EditorResources).dLineTermination, eax
  mov xax, [xsi].pOwner
  mov xdi, [xax].$Obj(ClientWnd).pOwner
  OCall [xdi].$Obj(Application).FileTypes::FileTypeCollection.GetFileTypeInfo, pFullFileName
  .if xax == NULL
    ExitMethod
  .endif
  m2m [xsi].FileTypeInfo.dContentType, [xax].FILETYPEINFO.dContentType, edx
  m2m [xsi].FileTypeInfo.dFileFormat, [xax].FILETYPEINFO.dFileFormat, ecx
  mov dFileFormat, ecx
  invoke LoadCursor, 0, IDC_WAIT
  invoke SetCursor, xax
  invoke CreateFileW, pFullFileName, GENERIC_READ, FILE_SHARE_READ or FILE_SHARE_WRITE, NULL, \
                      OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    invoke GetFileSize, hFile, NULL
    mov dFileSize, eax
    add eax, sizeof(CHRW)                               ;Add space for a (WIDE) ZTC
    MemAlloc xax
    .if xax != NULL
      mov pFileBuffer, xax
      invoke ReadFile, hFile, pFileBuffer, dFileSize, addr dBytesRead, NULL
      .if eax != FALSE
        mov xdi, pFileBuffer
        mov eax, dBytesRead
        mov CHRW ptr [xdi + xax], 0                     ;Set WIDE ZTC at the end of the read data

        ;Check the BOM if present
        mov pDataBegin, xdi
        ;Check if an UTF-8 BOM is present
        .if dBytesRead >= 3 && WORD ptr [xdi] == 0BBEFh && BYTE ptr [xdi + sizeof(WORD)] == 0BFh
          mov dFileFormat, EFF_UTF8BOM
          add xdi, 3*sizeof(BYTE)
          mov pDataBegin, xdi
          sub dBytesRead, 3*sizeof(BYTE)

        ;Check if an UTF-16 BOM is present
        .elseif dBytesRead >= 2 && WORD ptr [xdi] == 0FEFFh
          mov dFileFormat, EFF_UTF16BOM
          add xdi, sizeof(WORD)
          mov pDataBegin, xdi
          sub dBytesRead, sizeof(WORD)

        .else
          .if dFileFormat == EFF_UNKNOWN
            ;We don't know what it is => try to delegate it to the OS
            OCall xdi::Application.Execute, pFullFileName
            jmp @@Exit
          .elseif dFileFormat == EFF_UTF8BOM
            lea xbx, cMessage
            WriteF xbx, "Wrong or missing UTF-8 BOM in file\n\´¦SU\´ \:", pFullFileName
            invoke MessageBox, [xsi].hWnd, addr cMessage, addr cError, MB_OK or MB_ICONERROR
            jmp @@Exit
          .elseif dFileFormat == EFF_UTF16BOM
            lea xbx, cMessage
            WriteF xbx, "Wrong or missing UTF-16 BOM in file\n\´¦SU\´ \:", pFullFileName
            invoke MessageBox, [xsi].hWnd, addr cMessage, addr cError, MB_OK or MB_ICONERROR
            jmp @@Exit
          .endif
        .endif

        ;Average line length ~36 chars. Div by 32 gives us 10% reserve
        mov edx, dFileSize
        .if dFileFormat == EFF_UTF16BOM
          shr edx, 6                                    ;/64
        .else
          shr edx, 5                                    ;/32
        .endif
        OCall [xsi].Lines::Collection.SetLimit, edx     ;edx = Expected number of EditorLines

        .while TRUE
          ;Start searching for line ends
          ;Calc eax = scan remaining CHRs
          mov ebx, dBytesRead
          sub xbx, xdi
          add xbx, pDataBegin
          .break .if SIGN? || ZERO?                     ;All chars consumend

          .if dFileFormat == EFF_UTF16BOM
            shr ebx, 1
            .if dLineTermination == ELT_NULL
              invoke StrCScanCharW, xdi, ebx, 0         ;Search for NULL
            .elseif dLineTermination == ELT_LF
              invoke StrCScanCharW, xdi, ebx, LF        ;Search for LF
            .elseif dLineTermination == ELT_CR
              invoke StrCScanCharW, xdi, ebx, CR        ;Search for CR
            .else
              invoke StrCScanCharW, xdi, ebx, CR        ;Search for CR
              .if xax != NULL
                .if CHRW ptr [xax + sizeof(CHRW)] != LF ;Check if the next char is a LF
                  mov dLineTermination, ELT_CR          ;Assume ELT_CR
                .endif
              .else
                invoke StrCScanCharW, xdi, ebx, LF
                ;Search for LF
                .if xax != NULL
                  mov dLineTermination, ELT_LF          ;Assume ELT_LF
                .endif
              .endif
            .endif
          .else
            .if dLineTermination == ELT_NULL
              invoke StrScanCharA, xdi, ebx, 0          ;Search for NULL
            .elseif dLineTermination == ELT_LF
              invoke StrScanCharA, xdi, ebx, LF         ;Search for LF
            .elseif dLineTermination == ELT_CR
              invoke StrScanCharA, xdi, ebx, CR         ;Search for CR
            .else
              invoke StrScanCharA, xdi, ebx, CR         ;Search for CR
              .if xax != NULL
                .if CHRA ptr [xax + sizeof(CHRA)] != LF ;Check if the next char is a LF
                  mov dLineTermination, ELT_CR          ;Assume ELT_CR
                .endif
              .else
                invoke StrScanCharA, xdi, ebx, LF       ;Search for LF
                .if xax != NULL
                  mov dLineTermination, ELT_LF          ;Assume ELT_LF
                .endif
              .endif
            .endif
          .endif

          mov pFileLineBegin, xdi
          .if xax == NULL
            mov eax, dBytesRead
            add xax, pDataBegin                         ;Point to last char (Buffer ZTC)
          .endif

          .if dFileFormat == EFF_UTF16BOM
            .if dLineTermination == ELT_CRLF
              mov DCHRW ptr [xax], 0                    ;Set double ZTC @ CR
              lea xdi, [xax + 2*sizeof(CHRW)]           ;xdi -> Skip CRLF
            .else
              mov CHRW ptr [xax], 0                     ;Set ZTC
              lea xdi, [xax + sizeof(CHRW)]             ;xdi -> next CHRA
            .endif
            sub xax, pFileLineBegin
            shr eax, 1
          .else
            .if dLineTermination == ELT_CRLF
              mov DCHRA ptr [xax], 0                    ;Set double ZTC @ CR
              lea xdi, [xax + 2*sizeof(CHRA)]           ;xdi -> Skip LF
            .else
              mov CHRA ptr [xax], 0                     ;Set ZTC
              lea xdi, [xax + sizeof(CHRA)]             ;xdi -> next CHRA
            .endif
            sub xax, pFileLineBegin
          .endif
          mov dFileLineLength, eax                      ;Pessimistic value since UTF-8 chars are larger

          OCall xsi.LineNew, dFileLineLength, 0         ;Not including the ZTC.
          .if xax == NULL
            DbgText "Failed to allocate a new EditorLine"
            .break
          .else
            mov xbx, xax
            inc dFileLineLength                         ;Include ZTC in the FileBuffer
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
            .if dFileFormat == EFF_ANSI
              invoke MultiByteToWideChar, CP_ACP, 0, pFileLineBegin, dFileLineLength, \
                                          [xbx].$Obj(EditorLine).pBuffer, dFileLineLength
            .elseif dFileFormat == EFF_UTF16BOM
              mov eax, dFileLineLength
              add eax, eax
              invoke MemClone, [xbx].$Obj(EditorLine).pBuffer, pFileLineBegin, eax
              mov eax, dFileLineLength
            .else                                       ;Default UTF8
              invoke MultiByteToWideChar, CP_UTF8, 0, pFileLineBegin, dFileLineLength, \
                                          [xbx].$Obj(EditorLine).pBuffer, dFileLineLength
            .endif
  else
            .if dFileFormat == EFF_ANSI
              invoke MemClone, [xbx].$Obj(EditorLine).pBuffer, pFileLineBegin, dFileLineLength
              mov eax, dFileLineLength
            .elseif dFileFormat == EFF_UTF16BOM
              invoke WideCharToMultiByte, CP_ACP, 0, pFileLineBegin, dFileLineLength, \
                                          [xbx].$Obj(EditorLine).pBuffer, \
                                          [xbx].$Obj(EditorLine).dCharCapacity, NULL, NULL
            .else
              invoke MemClone, [xbx].$Obj(EditorLine).pBuffer, pFileLineBegin, dFileLineLength
              mov eax, dFileLineLength
            .endif
  endif
            dec eax                                     ;Discard the ZTC from returned char count
            mov [xbx].$Obj(EditorLine).dLength, eax
            .if eax > [xsi].dMaxLineCharCount           ;Keep the largest value
              mov [xsi].dMaxLineCharCount, eax
            .endif
            inc [xsi].dVisLineCount
          .endif
        .endw
        mov dRetValue, TRUE

      .endif
@@Exit:
      MemFree pFileBuffer
    .else
      DbgText "Failed to allocate memory for file read operation"
    .endif
    invoke CloseHandle, hFile
  .endif
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
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
;      m2m DocInfo.lpszDocName, offset ..., xax
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

; --------------------------------------------------------------------------------------------------
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

;    mov edx, $ObjTmpl(Application).dLanguage
;    add edx, 104
;    invoke LoadString, hInstance, edx, xbx, lengthof cText
    invoke StrCopy, xbx, $OfsCStr("Cancel")
    invoke GetDlgItem, wParam, IDCANCEL
    invoke SetWindowText, xax, xbx

    invoke UnhookWindowsHookEx, hCBTProc

    xor eax, eax
  .else
    invoke CallNextHookEx, hCBTProc, dCode, wParam, lParam
  .endif
  ret
CBTProc endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Redo
; Purpose:    Redo action.
; Arguments:  None.
; Return:     Nothing.

Method Editor.Redo, uses xbx xsi
  SetObject xsi
  OCall [xsi].Actions::ActionCollection.GetRedoAction, 0
  .if xax != NULL
    mov ebx, [xax].ACTION.dGroup
    .while TRUE
      OCall [xax].ACTION.pEditorLine::EditorLine.Redo, xax
      OCall [xsi].Actions::ActionCollection.GetRedoAction, ebx
      .break .if xax == NULL
    .endw

    OCall xsi.SelectionResetAll
    OCall xsi.ManageEditCmds
    mov xcx, [xsi].pFocusedView
    .if xcx != NULL
      OCall xcx::EditorView.CaretHide
    .endif
    invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.Save
; Purpose:    Save the editor content to a file.
; Arguments:  None.
; Return:     eax = IDYES, IDNO, IDCANCEL.

Method Editor.Save, uses xdi xsi
  local cText[1024]:CHR

  SetObject xsi
  .ifBitSet [xsi].dFlags, EDF_DIRTY
    ;MessageBox customization
    invoke SetWindowsHookEx, WH_CBT, offset CBTProc, hInstance, $32($invoke(GetCurrentThreadId))
    mov hCBTProc, xax
    lea xdi, cText
    .ifBitSet [xsi].dFlags, EDF_NEW_FILE
      WriteF xdi, "Save \´¦SU\´ changes to a file?", [xsi].pFullFileName
    .else
      WriteF xdi, "Save changes to\n\´¦SU\´?", [xsi].pFullFileName
    .endif
  @@:
    invoke MessageBox, [xsi].hWnd, addr cText, $OfsCStr("Editor"), MB_YESNOCANCEL or MB_ICONQUESTION
    .if eax == IDYES
      .ifBitSet [xsi].dFlags, EDF_NEW_FILE
        OCall xsi.SaveAs
        cmp eax, FALSE
        jz @B
      .else
        OCall xsi.SaveTo, [xsi].pFullFileName
      .endif
      mov eax, IDYES
    .endif
  .else
    mov eax, IDYES
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SaveAs
; Purpose:    Save the editor content to a file.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SaveAs, uses xbx xsi
  local dRetValue:DWORD, pIFileDialog2:POINTER
  local pIFSDlg:POINTER, pIShellItem:POINTER, pDisplayName:PSTRINGW
  local cMessage[2048]:CHR

  SetObject xsi
  mov dRetValue, FALSE
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
    .if SUCCEEDED(eax)                                  ;ERROR_CANCELLED (0x800704C7) if cancel button was pressed
      ICall pIFSDlg::IFileSaveDialog.GetResult, addr pIShellItem
      ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDisplayName
      mov xcx, [xsi].pOwner                             ;ClientWnd
      mov xax, [xcx].$Obj(ClientWnd).pOwner
      OCall [xax].$Obj(Application).FileTypes::FileTypeCollection.GetFileTypeInfo, pDisplayName
      .if xax == NULL
        lea xbx, cMessage
        WriteF xbx, "Unknown format for file\n\´¦SU\´ \:\n\nChoose a known file extension.", pDisplayName
        invoke MessageBox, [xsi].hWnd, addr cMessage, addr cError, MB_OK or MB_ICONERROR
      .else
        m2m [xsi].FileTypeInfo.dFileFormat, [xax].FILETYPEINFO.dFileFormat, ecx
        BitSet [xsi].dFlags, EDF_DIRTY                  ;Force save operation
        OCall xsi.SaveTo, pDisplayName
        .if eax != FALSE
          mov dRetValue, TRUE
          invoke SetWindowTextW, [xsi].hWnd, pDisplayName
          invoke StrReplaceW, addr [xsi].pFullFileName, pDisplayName
        .endif
      .endif
      invoke CoTaskMemFree, pDisplayName
      ICall pIShellItem::IShellItem.Release
    .endif
    ICall pIFSDlg::IFileSaveDialog.Release
  .endif
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SaveTo
; Purpose:    Save the editor content to a given FileName.
; Arguments:  Arg1: -> FullFileName.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SaveTo, uses xbx xdi xsi, pFullFileName:PSTRING
  local hFile:HANDLE, pMemBuffer:POINTER, dMemBufferSize:DWORD, dBytesWritten:DWORD, dRetValue:DWORD
  local bBOM[4]:BYTE

  SetObject xsi
  .ifBitSet [xsi].dFlags, EDF_DIRTY
    mov dRetValue, FALSE
    lea xdi, dBytesWritten
    .if pFullFileName != NULL
      invoke CreateFileW, pFullFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, \
                          CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
      .if xax != INVALID_HANDLE_VALUE
        mov hFile, xax

        ;Write the BOM if required
        .if [xsi].FileTypeInfo.dFileFormat == EFF_UTF8BOM
          mov DWORD ptr bBOM, 0BFBBEFh                  ;EF BB BF ...
          invoke WriteFile, hFile, addr bBOM, 3, xdi, NULL
        .elseif [xsi].FileTypeInfo.dFileFormat == EFF_UTF16BOM
          mov DWORD ptr bBOM, 0FEFFh                    ;FF FE ...
          invoke WriteFile, hFile, addr bBOM, 2, xdi, NULL
        .endif

        ;Allocate line conversion buffer
        mov eax, [xsi].dMaxLineCharCount
        shl eax, 2                                      ;Max UTF-8 expansion (x4)
        mov dMemBufferSize, eax
        MemAlloc eax
        .if xax != NULL
          mov pMemBuffer, xax

          ;Start looping
          .ColForEach [xsi].Lines
            mov xbx, xax
            .ifBitSet [xbx].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_PREV
              BitSet [xbx].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_PREV
            .endif
            .ifBitSet [xbx].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_CURR
              BitSet [xbx].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_CURR
            .endif
            .ifBitSet [xbx].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_NEXT
              BitSet [xbx].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_NEXT
            .endif

            ;Write the line content
            xor eax, eax
            .if [xbx].$Obj(EditorLine).pBuffer != NULL
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
              .if [xsi].FileTypeInfo.dFileFormat == EFF_ANSI
                invoke WideCharToMultiByte, CP_ACP, 0, [xbx].$Obj(EditorLine).pBuffer, \
                                            [xbx].$Obj(EditorLine).dLength, \
                                            pMemBuffer, dMemBufferSize, NULL, NULL
                invoke WriteFile, hFile, pMemBuffer, eax, xdi, NULL
              .elseif [xsi].FileTypeInfo.dFileFormat == EFF_UTF16BOM
                mov ecx, [xbx].$Obj(EditorLine).dLength
                lea eax, [ecx * sizeof(CHR)]
                invoke WriteFile, hFile, [xbx].$Obj(EditorLine).pBuffer, eax, xdi, NULL
              .else
                invoke WideCharToMultiByte, CP_UTF8, 0, [xbx].$Obj(EditorLine).pBuffer, \
                                            [xbx].$Obj(EditorLine).dLength, \
                                            pMemBuffer, dMemBufferSize, NULL, NULL
                invoke WriteFile, hFile, pMemBuffer, eax, xdi, NULL
              .endif
    else
              .if [xsi].dFileFormat == EFF_ANSI
                invoke WriteFile, hFile, [xbx].$Obj(EditorLine).pBuffer, [xbx].$Obj(EditorLine).dLength, \
                                  xdi, NULL
              .elseif [xsi].dFileFormat == EFF_UTF16BOM
                invoke MultiByteToWideChar, CP_ACP, 0, [xbx].$Obj(EditorLine).pBuffer, \
                                            [xbx].$Obj(EditorLine).dLength, \
                                            pMemBuffer, dMemBufferSize
                invoke WriteFile, hFile, pMemBuffer, eax, xdi, NULL
              .else
                invoke WriteFile, hFile, [xbx].$Obj(EditorLine).pBuffer, [xbx].$Obj(EditorLine).dLength, \
                                  xdi, NULL
              .endif
    endif
            .endif

            ;Write the line termination
            mov xcx, [xsi].pResources
            mov eax, [xcx].$Obj(EditorResources).dLineTermination
            mov xcx, pMemBuffer
            .if eax == ELT_LF
              .if [xsi].FileTypeInfo.dFileFormat == EFF_UTF16BOM
                mov xcx, pMemBuffer
                mov CHRW ptr [xcx], LF                  ;Add LF to the end
                invoke WriteFile, hFile, pMemBuffer, 2, xdi, NULL
              .else
                mov xcx, pMemBuffer
                mov CHRA ptr [xcx], LF                  ;Add LF to the end
                invoke WriteFile, hFile, pMemBuffer, 1, xdi, NULL
              .endif
            .elseif eax == ELT_NULL
              .if [xsi].FileTypeInfo.dFileFormat == EFF_UTF16BOM
                mov xcx, pMemBuffer
                mov DCHRW ptr [xcx], 0                  ;Add NULL to the end
                invoke WriteFile, hFile, pMemBuffer, 2, xdi, NULL
              .else
                mov xcx, pMemBuffer
                mov DCHRA ptr [xcx], 0                  ;Add NULL to the end
                invoke WriteFile, hFile, pMemBuffer, 1, xdi, NULL
              .endif
            .else
              .if [xsi].FileTypeInfo.dFileFormat == EFF_UTF16BOM
                mov xcx, pMemBuffer
                mov DCHRW ptr [xcx], LF*256*256 + CR    ;Add CRLF to the end
                invoke WriteFile, hFile, pMemBuffer, 4, xdi, NULL
              .else
                mov xcx, pMemBuffer
                mov DCHRA ptr [xcx], LF*256 + CR        ;Add CRLF to the end
                invoke WriteFile, hFile, pMemBuffer, 2, xdi, NULL
              .endif
            .endif

          .ColNext
          BitClr [xsi].dFlags, EDF_NEW_FILE or EDF_DIRTY
          mov dRetValue, TRUE
          MemFree pMemBuffer
        .endif
        invoke CloseHandle, hFile
      .endif
    .endif

    .if dRetValue != FALSE
      invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
    .endif
  .else
    mov dRetValue, TRUE
  .endif
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(ClientWnd).pOwner::Application.ManageGuiCmds, [xsi].hWnd
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectAll
; Purpose:    Select all lines.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectAll, uses xsi
;  DbgText "Editor.SelectAll"
  SetObject xsi
  xor eax, eax
  .ifBitClr [xsi].dFlags, EDF_BLOCK_MODE
    mov [xsi].SelectionFst.dCharIndex, 0
    mov [xsi].SelectionFst.dLineIndex, 0
    mov edx, [xsi].Lines.dCount
    dec edx
    mov [xsi].SelectionLst.dLineIndex, edx
    OCall [xsi].Lines::Collection.ItemAt, edx       ;Get the last line
    mov edx, [xax].$Obj(EditorLine).dLength
    mov [xsi].SelectionLst.dCharIndex, edx

    OCall xsi.SelectionSet
    .if eax != 0
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
    mov eax, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionComment
; Purpose:    Comment the selected Lines.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectionComment, uses xbx xdi xsi
  local dActionGroup:DWORD, pEditorLine:$ObjPtr(EditorLine)

;  DbgText "Editor.SelectionComment"
  SetObject xsi
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov ebx, [xax].LOCATION.dLineIndex                  ;Current index
    mov edi, [xcx].LOCATION.dLineIndex                  ;Last index
    mov pEditorLine, NULL

    ;Do the job
    mov dActionGroup, $32($OCall([xsi].Actions::ActionCollection.GetNewActionGroup))
    OCall xsi.CreateSelAction, dActionGroup
    .while TRUE
      .break .if ebx >= [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, ebx
      mov pEditorLine, xax
      OCall pEditorLine::EditorLine.CharInsert, 0, 1, $OfsCStr(";"), ebx, dActionGroup
      .break .if ebx == edi
      inc ebx
    .endw

    .if pEditorLine != NULL
      mov xcx, [xsi].SelectionRange.pBegSelInfo
      mov [xcx].LOCATION.dCharIndex, 0                  ;First char index
      mov xcx, [xsi].SelectionRange.pEndSelInfo
      mov [xcx].LOCATION.dCharIndex, -1                 ;Last char index
    .endif
    OCall xsi.SelectionSet
    OCall xsi.ManageEditCmds
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionDelete
; Purpose:    Delete selection from all lines.
; Arguments:  Arg1: ActionGroup. If 0, no ACTION will be logged.
; Return:     Nothing.

Method Editor.SelectionDelete, uses xbx xdi xsi, dActionGroup:DWORD
  local dDoMerge:DWORD, dCurrLineIndex:DWORD

  SetObject xsi
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov ebx, [xax].LOCATION.dLineIndex
    mov edi, [xcx].LOCATION.dLineIndex

    .ifBitClr [xcx].$Obj(Editor).dFlags, EDF_BLOCK_MODE

      ;Check if the first and last lines need to be merged after the deletion job
      mov dDoMerge, FALSE
      .if ebx != edi
        .if [xax].LOCATION.dCharIndex > 0               ;Not the first char selected
          .if edi < [xsi].Lines.dCount
            OCall [xsi].Lines::Collection.ItemAt, edi     ;Get last EditorLine
            mov xcx, [xsi].SelectionRange.pEndSelInfo
            mov edx, [xcx].LOCATION.dCharIndex
            .if edx != -1 ;Not all selected
              mov dDoMerge, TRUE                        ;Merge first and last lines
            .endif
          .endif
        .endif
      .endif

      ;Do the deletion job
      mov dCurrLineIndex, ebx
      .while dCurrLineIndex <= edi
        mov edx, dCurrLineIndex
        .break .if  edx >= [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, edx
        .if [xax].$Obj(EditorLine).Selection.dBegIndex == 0 && \
            [xax].$Obj(EditorLine).Selection.dEndIndex == -1
          ;Delete the line completely
          OCall xax::EditorLine.LineDelete, dCurrLineIndex, dActionGroup
          dec edi                                       ;Don't inc dCurrLineIndex
        .else
          mov xbx, xax
          mov eax, [xbx].$Obj(EditorLine).Selection.dEndIndex
          mov edx, [xbx].$Obj(EditorLine).Selection.dBegIndex
          .if eax == -1
            mov eax, [xbx].$Obj(EditorLine).dLength
          .endif
          sub eax, edx
          .if eax != 0
            OCall xbx::EditorLine.CharDelete, edx, eax, dCurrLineIndex, dActionGroup
            OCall xbx::EditorLine.SelectionReset
          .endif
          inc dCurrLineIndex
        .endif
      .endw

      ;Merge first and last lines if necessary
      .if dDoMerge != FALSE
        mov xbx, [xsi].SelectionRange.pBegSelInfo
        mov edx, [xbx].LOCATION.dLineIndex
        .if edx < [xsi].Lines.dCount
          OCall [xsi].Lines::Collection.ItemAt, edx
          OCall xax::EditorLine.LineJoinNext, [xbx].LOCATION.dLineIndex, dActionGroup
        .endif
      .endif

      .if [xsi].Lines.dCount == 0
        ;Insert a blank line
        OCall xsi.LineNew, 0, 0
        mov [xsi].dMaxLineCharCount, 0
        mov [xsi].dVisLineCount, 1
      .endif

    .else
      ;BLK mode

      ;Do the deletion job
      mov dCurrLineIndex, ebx
      .while dCurrLineIndex <= edi
        mov edx, dCurrLineIndex
        .break .if edx >= [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, edx
        mov xcx, xax
        mov eax, [xcx].$Obj(EditorLine).Selection.dEndIndex
        mov edx, [xcx].$Obj(EditorLine).Selection.dBegIndex
        .if eax > [xcx].$Obj(EditorLine).dLength
          mov eax, [xcx].$Obj(EditorLine).dLength
        .endif
        sub eax, edx
        .if eax != 0
          OCall xbx::EditorLine.CharDelete, edx, eax, dCurrLineIndex, dActionGroup
          OCall xbx::EditorLine.SelectionReset
        .endif
        inc dCurrLineIndex
      .endw

    .endif

    ;Cleanup
    OCall xsi.SelectionResetAll
    mov [xsi].dSelectionVisLineCnt, 0
  .endif

  OCall xsi.ManageEditCmds
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionIndent
; Purpose:    Indent the selected Lines.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectionIndent, uses xbx xdi xsi
  local dActionGroup:DWORD, pTabBuffer:POINTER, dTabWidth:DWORD, pEditorLine:$ObjPtr(EditorLine)

;  DbgText "Editor.SelectionIndent"
  SetObject xsi
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov ebx, [xax].LOCATION.dLineIndex                  ;Current index
    mov edi, [xcx].LOCATION.dLineIndex                  ;Last index

    ;Do the indentation job
    mov dActionGroup, $32($OCall([xsi].Actions::ActionCollection.GetNewActionGroup))
    OCall xsi.CreateSelAction, dActionGroup
    mov xax, [xsi].pResources
    mrm dTabWidth, [xax].$Obj(EditorResources).dTabWidth, edx
    invoke StrRepChr, ' ', edx
    .if xax != NULL
      mov pTabBuffer, xax
      .while TRUE
        .break .if ebx >= [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, ebx
        mov pEditorLine, xax
        OCall xax::EditorLine.CharInsert, 0, dTabWidth, pTabBuffer, edi, dActionGroup
        .break .if ebx == edi
        inc ebx
      .endw

      invoke StrDispose, pTabBuffer
      mov xax, pEditorLine
      .if xax != NULL
        mov xcx, [xsi].SelectionRange.pBegSelInfo
        mov [xcx].LOCATION.dCharIndex, 0                ;First char index
        mov xcx, [xsi].SelectionRange.pEndSelInfo
        mov [xcx].LOCATION.dCharIndex, -1               ;Last char index
      .endif
      OCall xsi.SelectionSet
      OCall xsi.ManageEditCmds
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      mov eax, TRUE
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionOutdent
; Purpose:    OutIndent the selected Lines.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectionOutdent, uses xbx xdi xsi
  local dActionGroup:DWORD, pTabBuffer:POINTER, dTabWidth:DWORD, pEditorLine:$ObjPtr(EditorLine)

;  DbgText "Editor.SelectionOutdent"
  SetObject xsi
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov ebx, [xax].LOCATION.dLineIndex                  ;Current index
    mov edi, [xcx].LOCATION.dLineIndex                  ;Last index

    ;Do the outdentation job
    mov dActionGroup, $32($OCall([xsi].Actions::ActionCollection.GetNewActionGroup))
    OCall xsi.CreateSelAction, dActionGroup
    mov xax, [xsi].pResources
    m2m dTabWidth, [xax].$Obj(EditorResources).dTabWidth, ecx
    invoke StrRepChr, ' ', dTabWidth
    .if xax != NULL
      mov pTabBuffer, xax

      ;Do the outdentation job
      .while TRUE
        .break .if ebx >= [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, ebx
        mov pEditorLine, xax
        invoke StrCComp, [xax].$Obj(EditorLine).pBuffer, pTabBuffer, dTabWidth
        .if eax == 0
          OCall pEditorLine::EditorLine.CharDelete, 0, dTabWidth, edi, dActionGroup
        .endif
        .break .if ebx == edi
        inc ebx
      .endw

      invoke StrDispose, pTabBuffer
      mov xax, pEditorLine
      .if xax != NULL
        mov xcx, [xsi].SelectionRange.pBegSelInfo
        mov [xcx].LOCATION.dCharIndex, 0                ;First char index
        mov xcx, [xsi].SelectionRange.pEndSelInfo
        mov [xcx].LOCATION.dCharIndex, -1               ;Last char index
      .endif
      OCall xsi.SelectionSet
      OCall xsi.ManageEditCmds
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      mov eax, TRUE
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionReplace
; Purpose:    Replace the selection with a new text.
; Arguments:  Arg1: -> New text.
;             Arg2: ActionGroup. If 0, no ACTION will be logged.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectionReplace, uses xbx xdi xsi, pReplString:PSTRING, dActionGroup:DWORD
  local dLineIndex:DWORD

;  DbgText "Editor.SelectionReplace"
  SetObject xsi

  mov xax, [xsi].SelectionRange.pBegSelInfo
  .if xax != NULL
    mov edi, [xax].LOCATION.dCharIndex
    mrm dLineIndex, [xax].LOCATION.dLineIndex, edx
    .if edx < [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, edx
      mov xbx, xax
      OCall xsi.SelectionDelete, dActionGroup
      invoke StrLength, pReplString
      OCall xbx::EditorLine.CharInsert, edi, eax, pReplString, dLineIndex, dActionGroup

      OCall xsi.HilitedWordReset
      OCall xsi.ManageEditCmds
      mov eax, TRUE
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionResetAll
; Purpose:    Reset selection from all EditorLines.
; Arguments:  None.
; Return:     eax = TRUE if the change has a visual impact, otherwise FALSE.

Method Editor.SelectionResetAll, uses xbx xsi
;  DbgText "Editor.SelectionResetAll"
  SetObject xsi
  OCall xsi.SelectionResetLines                         ;Reset all affected lines
  mov ebx, eax                                          ;Save return value
  OCall xsi.SelectionResetInfo                          ;Reset selection information
  OCall xsi.ManageEditCmds                              ;Switch button state
  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionResetInfo
; Purpose:    Reset selection information.
; Arguments:  None.
; Return:     Nothing.

Method Editor.SelectionResetInfo
;  DbgText "Editor.SelectionResetInfo"
  SetObject xcx
  mov [xcx].SelectionRange.pBegSelInfo, NULL
  mov [xcx].SelectionRange.pEndSelInfo, NULL
  mov [xcx].dSelectionVisLineCnt, 0
  OCall xcx.HilitedWordReset
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionResetLines
; Purpose:    Reset selection from all EditorLines.
; Arguments:  None.
; Return:     eax = TRUE if the change has a visual impact, otherwise FALSE.

Method Editor.SelectionResetLines, uses xbx xdi xsi
  local dNeedRedrawing:DWORD

;  DbgText "Editor.SelectionResetLines"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov ebx, [xax].LOCATION.dLineIndex
    mov edi, [xcx].LOCATION.dLineIndex
    .while ebx <= edi
      .break .if ebx >= [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, ebx
      OCall xax::EditorLine.SelectionReset
      add dNeedRedrawing, eax
      inc ebx
    .endw
  .endif
  OCall xsi.HilitedWordReset

  xor eax, eax
  cmp dNeedRedrawing, 0
  setnz al
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionSet
; Purpose:    Arrange the selection parameters and set the selection of affected EditorLines.
; Arguments:  None.
; Return:     eax = Number of selected visible lines.
; Note:       On exit, dSelectionVisLineCnt contains the number of selected visible lines.
;             On exit, the caret is hidden.

Method Editor.SelectionSet, uses xdi xbx xsi
  local dLastLineIndex:DWORD, dBegCharIndex:DWORD, dEndCharIndex:DWORD

  SetObject xsi
;  DbgText "Editor.SelectionSet"

  mov [xsi].dSelectionVisLineCnt, 0
  lea xcx, [xsi].SelectionFst
  lea xdx, [xsi].SelectionLst

  ;Arrange the selection by topology (Begin/End)
  mov eax, [xcx].LOCATION.dLineIndex
  .if eax == [xdx].LOCATION.dLineIndex                ;Same LineIndex?
    ;Same EditorLine
    mov eax, [xcx].LOCATION.dCharIndex
    .if eax == [xdx].LOCATION.dCharIndex              ;Same CharIndex?
      OCall xsi.SelectionResetInfo
      jmp @@Exit                                      ;Nothing selected => Exit
    .endif
    .if eax > [xdx].LOCATION.dCharIndex
      xchg xcx, xdx                                   ;Switch POINTERs
    .endif
  .elseif eax > [xdx].LOCATION.dLineIndex
    xchg xcx, xdx                                     ;Switch POINTERs
  .endif
  mov [xsi].SelectionRange.pBegSelInfo, xcx           ;Set selection begin
  mov [xsi].SelectionRange.pEndSelInfo, xdx           ;Set selection end

  ;Set selection indices on all target EditorLines
  .ifBitSet [xsi].dFlags, EDF_BLOCK_MODE
    ;BLK mode selection
    mov xax, [xsi].SelectionRange.pEndSelInfo
    mrm dLastLineIndex, [xax].LOCATION.dLineIndex, edx

    mov xax, [xsi].SelectionRange.pBegSelInfo
    mov ebx, [xax].LOCATION.dLineIndex

    mov xdx, [xsi].SelectionRange.pBegSelInfo
    mov ecx, [xdx].LOCATION.dCharIndex
    mov xdx, [xsi].SelectionRange.pEndSelInfo
    mov edx, [xdx].LOCATION.dCharIndex
    ;Make sure that ecx < edx
    .if ecx > edx
      xchg ecx, edx
    .endif
    mov dBegCharIndex, ecx
    mov dEndCharIndex, ecx

    ;Loop through target lines
    .while TRUE
      .break .if ebx >= [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, ebx
      .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
        inc [xsi].dSelectionVisLineCnt
      .endif

      ;Set Selection
      m2m [xax].$Obj(EditorLine).Selection.dBegIndex, dBegCharIndex, ecx
      m2m [xax].$Obj(EditorLine).Selection.dEndIndex, dEndCharIndex, ecx

      .break .if ebx == dLastLineIndex                ;Last selected line reached
      inc ebx
    .endw

  .else
    ;INS/OVR mode selection
    mov xcx, [xsi].SelectionRange.pBegSelInfo
    mov xdx, [xsi].SelectionRange.pEndSelInfo
    mov eax, [xcx].LOCATION.dLineIndex

    .if eax == [xdx].LOCATION.dLineIndex
      ;Same EditorLine
      .if eax < [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, eax
        .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
          inc [xsi].dSelectionVisLineCnt
        .endif

        mov xdx, [xsi].SelectionRange.pBegSelInfo       ;Set selection begin
        mov ecx, [xdx].LOCATION.dCharIndex
        mov [xax].$Obj(EditorLine).Selection.dBegIndex, ecx
        mov xdx, [xsi].SelectionRange.pEndSelInfo       ;Set selection end
        mov ecx, [xdx].LOCATION.dCharIndex
        mov [xax].$Obj(EditorLine).Selection.dEndIndex, ecx

        OCall xsi.HilitedWordReset                      ;Reset pHilitedWord & dHilitedLen
        mov xbx, [xax].$Obj(EditorLine).pBuffer
        ;Check before the selection beginning for !CHR_WORD
        mov edx, [xax].$Obj(EditorLine).Selection.dBegIndex
        cmp edx, 0
        lea xdi, [xbx + sizeof(CHR)*xdx]
        jz @F
        movzx ecx, CHR ptr [xdi - sizeof(CHR)]
        GetCharType ecx, edx
        .if !(edx & CHR_WORD)
      @@:
          ;Check after the selection ending for !CHR_WORD
          mov edx, [xax].$Obj(EditorLine).Selection.dEndIndex
          cmp edx, -1
          jz @F
          cmp edx, [xax].$Obj(EditorLine).dLength
          lea xbx, [xbx + sizeof(CHR)*xdx]
          jz @F
          movzx ecx, CHR ptr [xbx]
          GetCharType ecx, edx
          .if !(edx & CHR_WORD)
      @@:
            ;Set pHilitedWord & dHilitedLen
            mov [xsi].pHilitedWord, xdi
            sub xbx, xdi
          if TARGET_STR_TYPE eq STR_TYPE_WIDE
            shr ebx, 1
          endif
            mov [xsi].dHilitedLen, ebx

            ;Check the selection inside for all CHR_WORDs
            test ebx, ebx
            .while !ZERO?
              movzx ecx, CHR ptr [xdi]
              GetCharType ecx, edx
              .break .if !(edx & CHR_WORD)
              add xdi, sizeof CHR
              dec ebx
            .endw

            ;Reset pHilitedWord & dHilitedLen
            .if ebx != 0
              OCall xsi.HilitedWordReset
            .endif
          .endif
        .endif
      .endif
    .else
      ;Multiple lines.
      mov ebx, eax                                      ;Set start index
      mov edx, [xdx].LOCATION.dLineIndex
      mov dLastLineIndex, edx

      ;Set the first target Line
      .if eax < [xsi].Lines.dCount
        OCall [xsi].Lines::Collection.ItemAt, eax
        .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
          inc [xsi].dSelectionVisLineCnt
        .endif

        mov xcx, [xsi].SelectionRange.pBegSelInfo
        mov edx, [xcx].LOCATION.dCharIndex
        mov [xax].$Obj(EditorLine).Selection.dBegIndex, edx   ;Set begin index of 1st target line
        mov [xax].$Obj(EditorLine).Selection.dEndIndex, -1    ;Set end index of 1st target line

        ;Loop through the following target lines
        inc ebx
        .while ebx < dLastLineIndex
          OCall [xsi].Lines::Collection.ItemAt, ebx
          .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
            inc [xsi].dSelectionVisLineCnt
          .endif
          mov [xax].$Obj(EditorLine).Selection.dBegIndex, 0   ;Set begin index to zero
          mov [xax].$Obj(EditorLine).Selection.dEndIndex, -1
          inc ebx
        .endw
        ;Set the last target Line
        OCall [xsi].Lines::Collection.ItemAt, dLastLineIndex
        mov xcx, [xsi].SelectionRange.pEndSelInfo
        mov edx, [xcx].LOCATION.dCharIndex
        mov [xax].$Obj(EditorLine).Selection.dEndIndex, edx
        mov [xax].$Obj(EditorLine).Selection.dBegIndex, 0
      .endif
    .endif
  .endif

  OCall xsi.ManageEditCmds
  mov xcx, [xsi].pFocusedView
  .if xcx != NULL
    OCall xcx::EditorView.CaretHide
  .endif
@@Exit:
  mov eax, [xsi].dSelectionVisLineCnt
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.SelectionUncomment
; Purpose:    Uncomment the selected Lines.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Editor.SelectionUncomment, uses xbx xdi xsi
  local dActionGroup:DWORD, pEditorLine:$ObjPtr(EditorLine), dDeletedChars:DWORD

;  DbgText "Editor.SelectionUncomment"
  SetObject xsi
  mov xax, [xsi].SelectionRange.pBegSelInfo
  mov xcx, [xsi].SelectionRange.pEndSelInfo
  .if xax != NULL && xcx != NULL
    mov ebx, [xax].LOCATION.dLineIndex                  ;Current line index
    mov edi, [xcx].LOCATION.dLineIndex                  ;Last line index
    mov pEditorLine, NULL
    mov dDeletedChars, 0

    ;Do the job
    mov dActionGroup, $32($OCall([xsi].Actions::ActionCollection.GetNewActionGroup))
    OCall xsi.CreateSelAction, dActionGroup
    .while TRUE
      .break .if ebx >= [xsi].Lines.dCount
      OCall [xsi].Lines::Collection.ItemAt, ebx
      mov pEditorLine, xax
      mov xdx, [xax].$Obj(EditorLine).pBuffer
      .if [xax].$Obj(EditorLine).dLength != 0 && CHR ptr [xdx] == ";"
        OCall pEditorLine::EditorLine.CharDelete, 0, 1, ebx, dActionGroup
        add dDeletedChars, eax
      .endif
      .break .if ebx == edi
      inc ebx
    .endw

    .if pEditorLine != NULL && dDeletedChars != 0
      mov xcx, [xsi].SelectionRange.pBegSelInfo
      mov [xcx].LOCATION.dCharIndex, 0                  ;First char index
      mov xcx, [xsi].SelectionRange.pEndSelInfo
      mov [xcx].LOCATION.dCharIndex, -1                 ;Last char index
    .endif
    OCall xsi.SelectionSet
    OCall xsi.ManageEditCmds

    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.SetDirty
; Purpose:    Set the dirty flag.
; Arguments:  Arg1: TRUE to set the flag, otherwise FALSE.
; Return:     Nothing.

Method Editor.SetDirty, uses xsi, dAction:DWORD
  SetObject xsi
  .if dAction == FALSE
    BitClr [xsi].dFlags, EDF_DIRTY
  .else
    BitSet [xsi].dFlags, EDF_DIRTY
  .endif
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(ClientWnd).pOwner::Application.ManageGuiCmds, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
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

  invoke RegisterClassExW, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Undo
; Purpose:    Undo action.
; Arguments:  None.
; Return:     Nothing.

Method Editor.Undo, uses xbx xsi
  SetObject xsi
  OCall xsi.SelectionResetAll
  OCall [xsi].Actions::ActionCollection.GetUndoAction, 0  ;Get last ACTION in the collection
  mov ebx, [xax].ACTION.dGroup                          ;Remenber the group in ebx
  .while xax != NULL                                    ;xax -> ACTION; edx = [xax].ACTION.dAction
    mov edx, [xax].ACTION.dAction
    .if edx == AAT_SELECTION
      s2s [xsi].SelectionFst, [xax].ACTION.SelBegLocation, xcx, xdx
      s2s [xsi].SelectionLst, [xax].ACTION.SelEndLocation, xcx, xdx
      OCall xsi.SelectionSet                            ;SelectionSet hides the caret
    .else
      OCall [xax].ACTION.pEditorLine::EditorLine.Undo, xax
    .endif
    OCall [xsi].Actions::ActionCollection.GetUndoAction, ebx  ;Get next ACTION from same group
  .endw
  OCall xsi.ManageEditCmds
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Editor.UpdateStatusbar
; Purpose:    Draw new information on the Statusbar.
; Arguments:  None.
; Return:     Nothing.

Method Editor.UpdateStatusbar, uses xbx xdi xsi
  local cTextBuffer[1024]:CHR, wResText[1024]:CHRW
  local pContentType:PSTRING, pFileFormat:PSTRING, pLineTermination:PSTRING

;  DbgText "DbgMdiChildTxt.UpdateStatusbar"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xbx, [xcx].$Obj(ClientWnd).pOwner                 ;xbx -> Application

  lea xdi, cTextBuffer
  mov eax, [xsi].FileTypeInfo.dContentType
  .if eax == ECT_ASM
    c2m pContentType, $OfsCStr("MASM"), ecx
  .elseif eax == ECT_RES
    c2m pContentType, $OfsCStr("Resource"), ecx
  .else
    c2m pContentType, $OfsCStr("Text"), ecx
  .endif
  WriteF xdi, "¦SU", pContentType
  OCall [xbx].$Obj(Application).SBar::Statusbar.SetPartText, 3, addr cTextBuffer, SBT_SUNKEN

  lea xdi, cTextBuffer
  mov eax, [xsi].FileTypeInfo.dFileFormat
  .if eax == EFF_ANSI
    c2m pFileFormat, $OfsCStr("ANSI"), ecx
  .elseif eax == EFF_UTF8
    c2m pFileFormat, $OfsCStr("UTF-8"), ecx
  .elseif eax == EFF_UTF8BOM
    c2m pFileFormat, $OfsCStr("UTF-8 BOM"), ecx
  .elseif eax == EFF_UTF16BOM
    c2m pFileFormat, $OfsCStr("UTF-16 BOM"), ecx
  .else
    c2m pFileFormat, $OfsCStr("Unknown"), ecx
  .endif
  mov xcx, [xsi].pResources
  mov eax, [xcx].$Obj(EditorResources).dLineTermination
  .if eax == ELT_LF
    c2m pLineTermination, $OfsCStr("LF"), ecx
  .elseif eax == ELT_CR
    c2m pLineTermination, $OfsCStr("CR"), ecx
  .else
    c2m pLineTermination, $OfsCStr("CR+LF"), ecx
  .endif
  WriteF xdi, "¦SU  ¦SU", pFileFormat, pLineTermination
  OCall [xbx].$Obj(Application).SBar::Statusbar.SetPartText, 4, addr cTextBuffer, SBT_SUNKEN

;  .if dSelCount == 0
;    OCall [xbx].$Obj(Application).SBar::Statusbar.SetPartText, 2, NULL, SBT_SUNKEN
;  .else
;    lea xdi, cTextBuffer
;    mov edx, [xbx].$Obj(Application).dLangID
;    add edx, 142                                      ;"Selection"
;    invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;    WriteF xdi, "¦SU: ", addr wResText
;    mov edx, [xbx].$Obj(Application).dLangID
;    .if dSelCount == 1
;      add edx, 143                                    ;"character"
;      invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;      WriteF xdi, "1 ¦SU", addr wResText
;    .else
;      add edx, 144                                    ;"characters"
;      invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;      WriteF xdi, "¦UD ¦SU", dSelCount, addr wResText
;    .endif
;    WriteF xdi, ", "
;    mov edx, [xbx].$Obj(Application).dLangID
;    .if dLineCount == 1
;      add edx, 145                                    ;"line"
;      invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;      WriteF xdi, "1 ¦SU", addr wResText
;    .else
;      add edx, 146                                    ;"lines"
;      invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;      WriteF xdi, "¦UD ¦SU", dLineCount, addr wResText
;    .endif
;    OCall [xbx].$Obj(Application).SBar::Statusbar.SetPartText, 2, addr cTextBuffer, SBT_SUNKEN
;  .endif
;
;  lea xdi, cTextBuffer
;  invoke GetWindowText, [xsi].hWnd, xdi, lengthof(cTextBuffer)
;  lea xdi, [xdi + sizeof(CHR)*xax]
;  invoke SendMessage, [xsi].hEdit, EM_LINEINDEX, dLineNumberFirst, 0
;  mov dFirstLineCharIndex, eax
;  mov ecx, dFirstCharIndex
;  sub ecx, eax
;  mov dLineCharPos, ecx
;  mov edx, [xbx].$Obj(Application).dLanguage
;  add edx, 140                                        ;"Caret at line"
;  invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;  inc dLineNumberFirst                                ;First line index is 0 => 1
;  WriteF xdi, ": ¦SU ¦UD, ", addr wResText, dLineNumberFirst
;  mov edx, [xbx].$Obj(Application).dLanguage
;  add edx, 141                                        ;"position"
;  invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
;  mov eax, dFirstLineCharIndex
;  sub dFirstCharIndex, eax
;  WriteF xdi, "¦SU ¦UD", addr wResText, dFirstCharIndex
;  OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, addr cTextBuffer, SBT_SUNKEN
;  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
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
