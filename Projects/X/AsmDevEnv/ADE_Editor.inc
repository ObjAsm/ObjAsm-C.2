; ==================================================================================================
; Title:      ADE_Editor.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
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
    OCall xbx::Application.EnableActions, FALSE
    invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    invoke DrawMenuBar, [xbx].$Obj(Application).hWnd      ;Redraw the new menu bar
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.InformDeletionOf
; Purpose:    Inform all Views that a specific lines was deleted.
; Arguments:  Arg1: Line number of Arg1.
; Return:     Nothing.

Method Editor.InformDeletionOf, uses xbx xsi, dLineNumber:DWORD
  SetObject xsi
  .ColForEach [xsi].EditorDisplays, ebx
    .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
      dec [xsi].dVisTextLineCount
      dec [xsi].dTotalLineCount
    .endif
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
      OCall xbx::Application.EnableActions, TRUE
      invoke DrawMenuBar, [xbx].$Obj(Application).hWnd  ;Redraw the new menu bar
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
  DbgText "Editor.OnClose"
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
  invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
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
  invoke SetFocus, [xcx].hLastFocusedView
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

        ;Start searching for line ends
        .while TRUE
          invoke StrLScanA, xdi, LF
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
            invoke MultiByteToWideChar, CP_UTF8, 0, pFileLineBegin, dFileLineLength, \
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
            mov eax, [xbx].$Obj(EditorTextLine).dLength
            invoke WideCharToMultiByte, CP_UTF8, 0, [xbx].$Obj(EditorTextLine).pBuffer, \
                                        [xbx].$Obj(EditorTextLine).dLength, \
                                        pMemBuffer, dMemBufferSize, NULL, NULL
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

Method Editor.SaveAs, uses xbx xsi
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
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Editor.SelectionResetAll
; Purpose:    Reset selection from all EditorTextLines.
; Arguments:  None.
; Return:     eax = TRUE if the change has a visual impact, otherwise FALSE.

Method Editor.SelectionResetAll, uses xsi
;  DbgText "Editor.SelectionReset"
  SetObject xsi
  OCall xsi.SelectionResetLines
  mov [xsi].SelectionRange.pBegSelInfo, NULL
  mov [xsi].SelectionRange.pEndSelInfo, NULL
  mov [xsi].SelectionFst.pTextLine, NULL
  mov [xsi].SelectionFst.dCharIndex, 0
  mov [xsi].SelectionFst.dLineNumber, 0
  mov [xsi].SelectionLst.pTextLine, NULL
  mov [xsi].SelectionLst.dCharIndex, 0
  mov [xsi].SelectionLst.dLineNumber, 0
  mov [xsi].dSelectionVisLineCnt, 0
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

  .if [xsi].SelectionFst.pTextLine != NULL && [xsi].SelectionLst.pTextLine != NULL 
    lea xcx, [xsi].SelectionFst
    lea xdx, [xsi].SelectionLst
    mov [xsi].dSelectionVisLineCnt, 0
  
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
  
  ;      DbgEditor xsi,, "Editor"
        mov [xax].$Obj(EditorTextLine).Selection.dBegIndex, ecx   ;Set begin index of 1st line
        .while xax != xdi
  ;        DbgTextLine xax,, "TextLine"
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
  .else
    mov [xsi].dSelectionVisLineCnt, 0
  .endif
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
; Method:     Editor.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method Editor.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
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
