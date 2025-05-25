; ==================================================================================================
; Title:      ADE_EditorView_1.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


;EditorView flags
EVF_CARET_CREATED           equ   BIT00
EVF_CARET_VISIBLE           equ   BIT01
EVF_LBUTTON_DOWN_SELBAR     equ   BIT02
EVF_LBUTTON_DOWN_TEXTBOX    equ   BIT03


; ==================================================================================================
; EditorView implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretAdjustHorz
; Purpose:    Correct caret horizontal position, e.g. after a vertical move.
; Arguments:  Arg1: EditorLine index.
; Return:     Nothing.

Method EditorView.CaretAdjustHorz, uses xbx xsi, dEditorLineIndex:DWORD
;  DbgText "EditorView.CaretAdjustHorz"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xdx -> Editor
  mov edx, dEditorLineIndex
  .if edx < [xbx].$Obj(Editor).Lines.dCount
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
    .if [xsi].dLockedCharIndex == -1
      mrm [xsi].dLockedCharIndex, [xsi].CaretLocation.dCharIndex, ecx
    .else
      mov ecx, [xsi].dLockedCharIndex
    .endif

    .ifBitSet [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
      mov [xsi].CaretLocation.dCharIndex, ecx
    .else
      mov eax, [xax].$Obj(EditorLine).dLength
      cmp eax, ecx
      cmova eax, ecx
      mov [xsi].CaretLocation.dCharIndex, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretDestroy
; Purpose:    Hide the caret.
; Arguments:  None.
; Return:     Non zero if succeeded, 0 if failed.

Method EditorView.CaretDestroy, uses xsi
;  DbgText "EditorView.CaretDestroy"
  SetObject xsi
  xor eax, eax
  .ifBitSet [xsi].dFlags, EVF_CARET_CREATED
;    DbgText "Destroy"
    invoke DestroyCaret
    BitClr [xsi].dFlags, EVF_CARET_CREATED or EVF_CARET_VISIBLE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretHide
; Purpose:    Removes the caret from screen.
; Arguments:  None.
; Return:     Non zero if succeeded, 0 if failed.

Method EditorView.CaretHide, uses xsi
;  DbgText "EditorView.CaretHide"
  SetObject xsi
  xor eax, eax
  .ifBitSet [xsi].dFlags, EVF_CARET_CREATED
    .ifBitSet [xsi].dFlags, EVF_CARET_VISIBLE
;      DbgText "Hide"
      invoke HideCaret, [xsi].hWnd
      BitClr [xsi].dFlags, EVF_CARET_VISIBLE
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretMoveDown
; Purpose:    Move the caret one line down.
; Arguments:  Arg1: Number of visible lines.
; Return:     eax != 0 if redrawing is needed, otherwise 0.

Method EditorView.CaretMoveDown, uses xbx xdi xsi, dVisLineCount:DWORD
  local dNeedRedrawing:DWORD, dCurLineIndex:DWORD

;  DbgText "EditorView.CaretMoveDown"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  mov dNeedRedrawing, 0
  mov edi, dVisLineCount
  test edi, edi
  .while !ZERO?
    m2m dCurLineIndex, [xsi].CaretLocation.dLineIndex, eax
    MoveToNextVisEditorLine xbx, dCurLineIndex
    .break .if xax == NULL
    m2m [xsi].CaretLocation.dLineIndex, dCurLineIndex, eax
    OCall xsi.CaretVertIndex
    .if eax == -1                                       ;End of View
      OCall xsi.ScrollVisLineDown
      add dNeedRedrawing, eax
    .endif
    dec edi
  .endw
  OCall xsi.CaretAdjustHorz, [xsi].CaretLocation.dLineIndex
  OCall xsi.CaretSet
  mov eax, dNeedRedrawing
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretMoveUp
; Purpose:    Move the caret one line up.
; Arguments:  Arg1: Number of visible lines.
; Return:     eax != 0 if redrawing is needed, otherwise 0.
; Note:       The first line is always visible.

Method EditorView.CaretMoveUp, uses xbx xdi xsi, dVisLineCount:DWORD
  local dNeedRedrawing:DWORD, dCurLineIndex:DWORD

;  DbgText "EditorView.CaretMoveUp"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  mov dNeedRedrawing, 0
  mov edi, dVisLineCount
  test edi, edi
  .while !ZERO?
    mov eax, [xsi].FirstVisChar.dLineIndex
    .if eax == [xsi].CaretLocation.dLineIndex           ;Top off view
      OCall xsi.ScrollVisLineUp
      add dNeedRedrawing, eax
      sub [xsi].CaretLocation.dLineIndex, eax
    .else
      m2m dCurLineIndex, [xsi].CaretLocation.dLineIndex, eax
      MoveToPrevVisEditorLine xbx, dCurLineIndex
      .break .if xax == NULL
      m2m [xsi].CaretLocation.dLineIndex, dCurLineIndex, eax
    .endif
    dec edi
  .endw
  OCall xsi.CaretAdjustHorz, [xsi].CaretLocation.dLineIndex
  OCall xsi.CaretSet
  mov eax, dNeedRedrawing
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretMoveWordBeg
; Purpose:    Move the caret to the word begin.
; Arguments:  None.
; Return:     eax = 1 if the View must be updated, otherwise 0.

Method EditorView.CaretMoveWordBeg, uses xbx xdi xsi
  local dNeedRedrawing:DWORD

;  DbgText "EditorView.CaretMoveWordBeg"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov xcx, [xsi].pEditor
  mov edx, [xsi].CaretLocation.dLineIndex
  .if edx < [xcx].$Obj(Editor).Lines.dCount
    OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, edx
    mov edi, [xsi].CaretLocation.dCharIndex
    xor edx, edx                                          ;Reset word begin flag

    .while TRUE
      .if edi == 0
        ;We need to go to the previous line
        mov xbx, xax
        OCall xsi.CaretMoveUp, 1
        add dNeedRedrawing, eax
        mov xcx, [xsi].pEditor
        mov edx, [xsi].CaretLocation.dLineIndex
        .if edx < [xcx].$Obj(Editor).Lines.dCount
          OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, edx
          .if xax != xbx
            mov edi, [xax].$Obj(EditorLine).dLength
          .endif
        .endif
        .break
      .endif

      ;Detect previous word begin
      mov xbx, [xax].$Obj(EditorLine).pBuffer
      movzx ecx, CHR ptr [xbx + sizeof(CHR)*xdi - sizeof(CHR)]
      GetCharType ecx, ebx
      .ifAnyBitSet ebx, CHR_BLANK or CHR_QUOTE or CHR_OPERATOR
        .if edx != 0
          .break
        .endif
      .else
        inc edx
      .endif
      dec edi
      .break .if ZERO? && edx != 0
    .endw

    mov [xsi].CaretLocation.dCharIndex, edi
    OCall xsi.CaretSet
  .endif

  xor eax, eax
  cmp dNeedRedrawing, 0
  setnz al
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretMoveWordEnd
; Purpose:    Move the caret to the next word end.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.CaretMoveWordEnd, uses xbx xdi xsi
  local dNeedRedrawing:DWORD

;  DbgText "EditorView.CaretMoveWordEnd"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov xcx, [xsi].pEditor
  mov edx, [xsi].CaretLocation.dLineIndex
  .if edx < [xcx].$Obj(Editor).Lines.dCount
    OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, edx
    mov edi, [xsi].CaretLocation.dCharIndex
    xor edx, edx                                          ;Reset flag
    .if edi == [xax].$Obj(EditorLine).dLength
      mov xbx, xax
      OCall xsi.CaretMoveDown, 1
      add dNeedRedrawing, eax
      mov xcx, [xsi].pEditor
      mov edx, [xsi].CaretLocation.dLineIndex
      .if edx < [xcx].$Obj(Editor).Lines.dCount
        OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, edx
        .if xax != xbx
          xor edi, edi
          jmp @F
        .endif
      .endif
      jmp @@Exit
    .endif

@@:
    .while TRUE
      .break .if edi == [xax].$Obj(EditorLine).dLength

      ;Detect next word end
      mov xbx, [xax].$Obj(EditorLine).pBuffer
      movzx ecx, CHR ptr [xbx + sizeof(CHR)*xdi]
      GetCharType ecx, ebx
      .ifAnyBitSet ebx, CHR_BLANK or CHR_QUOTE or CHR_OPERATOR
        .break .if edx != 0
      .else
        inc edx
      .endif
      inc edi
    .endw

    mov [xsi].CaretLocation.dCharIndex, edi
    OCall xsi.CaretSet
  .endif

@@Exit:
  xor eax, eax
  cmp dNeedRedrawing, 0
  setnz al
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretNew
; Purpose:    Create a new caret. Doesn't destroy the previous caret!
; Arguments:  None.
; Return:     Non zero if succeeded, 0 if failed.

Method EditorView.CaretNew, uses xbx xsi
;  DbgText "EditorView.CaretNew"
  SetObject xsi
  xor eax, eax
  .ifBitClr [xsi].dFlags, EVF_CARET_CREATED
    mov xax, [xsi].pEditor
    mov xdx, [xsi].pResources
    .ifBitSet [xax].$Obj(Editor).dFlags, EDF_BLOCK_MODE
      m2z [xdx].$Obj(EditorResources).CaretBmpOffset.x        ;BLK mode (wide |)
      m2z [xdx].$Obj(EditorResources).CaretBmpOffset.y
      mov eax, 4
      mov ebx, [xdx].$Obj(EditorResources).EditorTextRegular.FontMetric.y
    .else
      .ifBitSet [xax].$Obj(Editor).dFlags, EDF_OVERWRITE_MODE
        m2z [xdx].$Obj(EditorResources).CaretBmpOffset.x      ;OVR mode(_)
        mov eax, [xdx].$Obj(EditorResources).EditorTextRegular.FontMetric.y
        sub eax, 2
        mov [xdx].$Obj(EditorResources).CaretBmpOffset.y, eax
        mov eax, [xdx].$Obj(EditorResources).EditorTextRegular.FontMetric.x
        mov ebx, 2
      .else
        m2z [xdx].$Obj(EditorResources).CaretBmpOffset.x      ;INS mode (|)
        m2z [xdx].$Obj(EditorResources).CaretBmpOffset.y
        mov eax, 2
        mov ebx, [xdx].$Obj(EditorResources).EditorTextRegular.FontMetric.y
      .endif
    .endif
    invoke CreateCaret, [xsi].hWnd, 0, eax, ebx
    BitSet [xsi].dFlags, EVF_CARET_CREATED
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretLocationSave
; Purpose:    Save the caret LOCATION.
; Arguments:  Arg1: -> LOCATION storage.
; Return:     Nothing.

Method EditorView.CaretLocationSave,, pStorageLocation:PLOCATION, pSrcLoc:PLOCATION
;;  DbgText "EditorView.CaretLocationSave"
  SetObject xcx
  mov xdx, pSrcLoc
  .if xdx == NULL
    mov eax, [xcx].CaretLocation.dCharIndex
    mov ecx, [xcx].CaretLocation.dLineIndex
  .else
    mov eax, [xdx].LOCATION.dCharIndex
    mov ecx, [xdx].LOCATION.dLineIndex
  .endif
  mov xdx, pStorageLocation
  mov [xdx].LOCATION.dCharIndex, eax
  mov [xdx].LOCATION.dLineIndex, ecx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretLocationLoad
; Purpose:    Load the caret LOCATION stored using CaretLocationSave.
; Arguments:  Arg1: -> Stored LOCATION.
; Return:     Nothing.

Method EditorView.CaretLocationLoad,, pRefLoc:PLOCATION
;  DbgText "EditorView.CaretLocationLoad"
  SetObject xcx
  mov xdx, pRefLoc
  m2m [xcx].CaretLocation.dCharIndex, [xdx].LOCATION.dCharIndex, eax
  m2m [xcx].CaretLocation.dLineIndex, [xdx].LOCATION.dLineIndex, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretSet
; Purpose:    Set the caret at the position defined by LOCATION.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Note:       The caret is only displayed if it is in the TextRect.

Method EditorView.CaretSet, uses xdi xsi
  local CaretPosition:POINT, dRetValue:DWORD

;  DbgText "EditorView.CaretSet"
  SetObject xsi
  mov xdi, [xsi].pResources
  mov xbx, [xsi].pEditor
  mov dRetValue, FALSE
  ;Calc caret horiontal position
  mov eax, [xsi].CaretLocation.dCharIndex
  sub eax, [xsi].FirstVisChar.dCharIndex
  .if SIGN? || eax > [xsi].dCharMaxPartVis              ;Off view horizontally?
    invoke SetCaretPos, -10, -10                        ;Park the caret
  .else
    mul [xdi].$Obj(EditorResources).EditorTextRegular.FontMetric.x  ;Convert to pixels
    add eax, [xsi].TextRect.left                        ;Offset by Selectionbar width
    mov CaretPosition.x, eax                            ;Store it

    ;Calc caret vertical position using the CaretLocation.dLineIndex
    OCall xsi.CaretVertIndex
    .if eax == -1                                       ;Off view vertically?
      invoke SetCaretPos, -10, -10                      ;Park the caret
    .else
      mul [xdi].$Obj(EditorResources).dLineHeight
      add eax, [xsi].TextRect.top
      mov CaretPosition.y, eax

      ;Add offset to the caret position
      mov ecx, CaretPosition.x
      mov edx, CaretPosition.y
      add ecx, [xdi].$Obj(EditorResources).CaretBmpOffset.x
      add edx, [xdi].$Obj(EditorResources).CaretBmpOffset.y
      invoke SetCaretPos, ecx, edx
      mov dRetValue, TRUE
    .endif
  .endif
@@:
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretShow
; Purpose:    Show the caret.
; Arguments:  None.
; Return:     Non zero if succeeded, 0 if failed.

Method EditorView.CaretShow, uses xsi
;  DbgText "EditorView.CaretShow"
  SetObject xsi
  xor eax, eax
  .ifBitSet [xsi].dFlags, EVF_CARET_CREATED
    .ifBitClr [xsi].dFlags, EVF_CARET_VISIBLE
;      DbgText "Show"
      invoke ShowCaret, [xsi].hWnd
      BitSet [xsi].dFlags, EVF_CARET_VISIBLE
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.CaretVertIndex
; Purpose:    Calculate the caret view vertical index.
; Arguments:  None.
; Return:     eax = Vertical index or -1 if the caret is off view or last line was reached.

Method EditorView.CaretVertIndex, uses xbx xdi xsi
  local dCurVisLineIndex:DWORD, dCurLineIndex:DWORD

;  DbgText "EditorView.CaretVertIndex"
  SetObject xsi
  mov xbx, [xsi].pEditor

  mov eax, [xsi].CaretLocation.dLineIndex
  cmp eax, [xsi].FirstVisChar.dLineIndex
  jb @F                                                 ;Off view (top)
  mov dCurVisLineIndex, 0
  m2m dCurLineIndex, [xsi].FirstVisChar.dLineIndex, edx
  .while TRUE
    mov ecx, [xsi].dLineMaxFullVis
    cmp ecx, dCurVisLineIndex
    jle @F                                              ;Off view (bottom, full line) signed!
    .while TRUE
      mov edx, dCurLineIndex
      cmp edx, [xbx].$Obj(Editor).Lines.dCount
      jae @F                                            ;Last line reached
      OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
      inc dCurLineIndex
      .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
        inc dCurVisLineIndex
        .break
      .endif
    .endw
    mov edx, dCurLineIndex
    dec edx
    .break .if edx == [xsi].CaretLocation.dLineIndex
  .endw
  mov eax, dCurVisLineIndex
  dec eax
  ret
@@:
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ClpBrdDelete
; Purpose:    Clipboard delete opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method EditorView.ClpBrdDelete, uses xbx xsi
  local RefLoc:LOCATION, dActionGroup:DWORD

;  DbgText "EditorView.ClpBrdDelete"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
      [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
    mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
    OCall xbx::Editor.CreateSelAction, dActionGroup
    OCall xsi.CaretLocationSave, addr RefLoc, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    OCall xbx::Editor.SelectionDelete, dActionGroup     ;Do deletion
    OCall xsi.CaretLocationLoad, addr RefLoc            ;Restore caret info
    OCall xsi.CaretShow                                 ;Show again after a selection
  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ClpBrdCopy
; Purpose:    Clipboard copy operation.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method EditorView.ClpBrdCopy, uses xbx xdi xsi
  local dRetValue:DWORD, hBuffer:HANDLE, pGlobalMem:POINTER, dBufferSize:DWORD
  local dLastLineIndex:DWORD, dHasLineEnd:DWORD

;  DbgText "EditorView.ClpBrdCopy"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  mov dRetValue, FALSE
  invoke OpenClipboard, [xsi].hWnd
  .if eax != 0
    ;Allocate memory to copy the the content passed to the clipboard
    ;Calc the required size
    mov xcx, [xbx].$Obj(Editor).SelectionRange.pEndSelInfo
    m2m dLastLineIndex, [xcx].LOCATION.dLineIndex, edx
    mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    mov edi, [xcx].LOCATION.dLineIndex                  ;edi = current line index
    mov dBufferSize, 0
    .repeat
      .break .if edi >= [xbx].$Obj(Editor).Lines.dCount
      OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi
      mov edx, [xax].$Obj(EditorLine).Selection.dEndIndex
      .if edx == -1
        mov edx, [xax].$Obj(EditorLine).dLength
        add edx, 2                                      ;CRLF
      .endif
      sub edx, [xax].$Obj(EditorLine).Selection.dBegIndex
      add dBufferSize, edx
      inc edi
    .until edi > dLastLineIndex
    inc dBufferSize                                     ;Ending ZTC
  if sizeof(CHR) eq 2
    shl dBufferSize, 1
  endif

    ;Allocate memory that can be used by the clipboard
    invoke GlobalAlloc, GMEM_MOVEABLE, dBufferSize
    .if xax != NULL
      mov hBuffer, xax
      invoke GlobalLock, xax
      mov pGlobalMem, xax
      mov xsi, xax

      mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
      mov edi, [xcx].LOCATION.dLineIndex

      ;Do the copy job
      .repeat
        .break .if edi >= [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi
        mov dHasLineEnd, FALSE
        .if [xax].$Obj(EditorLine).Selection.dEndIndex == -1
          mov dHasLineEnd, TRUE
        .endif
        mov xcx, [xax].$Obj(EditorLine).pBuffer
        mov edx, [xax].$Obj(EditorLine).Selection.dBegIndex
        .if [xax].$Obj(EditorLine).Selection.dEndIndex == -1
          mov eax, [xax].$Obj(EditorLine).dLength
        .else
          mov eax, [xax].$Obj(EditorLine).Selection.dEndIndex
        .endif
        sub eax, edx
  if sizeof(CHR) eq 2
        shl edx, 1
        shl eax, 1
  endif
        add xdx, xcx
        invoke MemClone, xsi, xdx, eax
        add xsi, xax
        .if dHasLineEnd
          invoke MemClone, xsi, addr cCRLF, 2*sizeof(CHR)
          add xsi, 2*sizeof(CHR)
        .endif
        inc edi
      .until edi > dLastLineIndex
      mov CHR ptr [xsi], 0

      invoke GlobalUnlock, pGlobalMem
      invoke SetClipboardData, CF_UNICODETEXT, hBuffer
      .if xax != 0
        mov dRetValue, TRUE
      .endif
    .endif
    invoke CloseClipboard
  .endif
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ClpBrdCut
; Purpose:    Clipboard cut opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method EditorView.ClpBrdCut, uses xsi
;  DbgText "EditorView.ClpBrdCut"
  SetObject xsi
  OCall xsi.ClpBrdCopy
  .if eax != FALSE
    OCall xsi.ClpBrdDelete
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ClpBrdPaste
; Purpose:    Clipboard paste opration.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Link:       https://msdn.microsoft.com/en-us/library/windows/desktop/ms649016(v=vs.85).aspx#_win32_Copying_Information_to_the_Clipboard
; Note:       CF_TEXT = Each line ends with a EOL marker.
;             This marker varies depending on the source of the text. It can be a CR, LF or CRLF.
;             A copy operation from a Chrome-Webpase contains e.g. only LF.
;             A null character signals the end of the data.

Method EditorView.ClpBrdPaste, uses xbx xdi xsi
  local pEditorLine:$ObjPtr(EditorLine), dRetValue:DWORD, RefLoc:LOCATION, dInsLineCount:DWORD
  local pGlobalMem:POINTER, dCharIndex:DWORD, dLineIndex:DWORD, dBreakChar:DWORD, dActionGroup:DWORD

;  DbgText "EditorView.ClpBrdPaste"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  mov dRetValue, FALSE
  mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
  OCall xbx::Editor.CreateSelAction, dActionGroup

  .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
      [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
    OCall xsi.CaretLocationSave, addr RefLoc, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    OCall xbx::Editor.SelectionDelete, dActionGroup     ;Do deletion
    OCall xsi.CaretLocationLoad, addr RefLoc            ;Restore caret info
    OCall xsi.CaretShow                                 ;Show again after a selection
  .endif
  invoke IsClipboardFormatAvailable, CF_TEXT + (CF_UNICODETEXT - CF_TEXT)*(sizeof(CHR) - sizeof(CHRA))
  .if eax != FALSE
    invoke OpenClipboard, [xsi].hWnd
    .if eax != 0
      invoke GetClipboardData, CF_TEXT + (CF_UNICODETEXT - CF_TEXT)*(sizeof(CHR) - sizeof(CHRA))
      .if xax != NULL
        invoke GlobalLock, xax
        .if xax != NULL
          mov pGlobalMem, xax
          OCall xsi.ScrollCaretInViewTop
          .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
            ;INS/OVR mode
            ;Paste complete lines
            mov xdi, pGlobalMem
            m2m dCharIndex, [xsi].CaretLocation.dCharIndex, ecx
            mrm dLineIndex, [xsi].CaretLocation.dLineIndex, edx
            .if edx < [xbx].$Obj(Editor).Lines.dCount
              OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
              mov pEditorLine, xax
              mov dInsLineCount, 0
              xor ebx, ebx                                ;ebx = char counter
              .repeat
                movzx edx, CHR ptr [xdi + sizeof(CHR)*xbx];Read buffer character
                .break .if edx == 0                       ;ZTC = End of buffer?
                .if edx != CR && edx != LF                ;EOL (CR/LF/CRLF) reached?
                  inc ebx                                 ;No
                .else
                  mov dBreakChar, edx
                  OCall pEditorLine::EditorLine.CharInsert, dCharIndex, ebx, xdi, dLineIndex, dActionGroup
                  mov edx, dCharIndex
                  add edx, ebx
                  OCall pEditorLine::EditorLine.LineBreak, edx, dLineIndex, dActionGroup
                  mov pEditorLine, xax                    ;xax -> new splitted off line

                  ;Move to next line in the clipboard buffer
                  lea xdi, [xdi + sizeof(CHR)*xbx + sizeof(CHR)]  ;Next char
                  .if dBreakChar == CR && CHR ptr [xdi] == LF
                    add xdi, sizeof CHR                   ;CRLF case
                  .endif

                  ;Increment other counters
                  inc dInsLineCount
                  inc dLineIndex
                  mov dCharIndex, 0
                  xor ebx, ebx
                .endif
              .until FALSE

              ;Paste the rest
              .if ebx != 0
                OCall pEditorLine::EditorLine.CharInsert, dCharIndex, ebx, xdi, dLineIndex, dActionGroup
                add dCharIndex, ebx
              .endif

              ;Manage the caret
              m2m [xsi].CaretLocation.dCharIndex, dCharIndex, edx
              m2m [xsi].CaretLocation.dLineIndex, dLineIndex, edx
              mov edx, dInsLineCount
              OCall xsi.CaretSet

              ;Scroll the view to show the last inserted line
              OCall xsi.ScrollCaretInViewBottom
            .endif

          .else
            ;BLK mode insertion
            ;Insert complete lines
            mov xdi, xax
            xor ebx, ebx                                ;ebx = char counter
            m2m dCharIndex, [xsi].CaretLocation.dCharIndex, ecx
            m2m dLineIndex, [xsi].CaretLocation.dLineIndex, edx
            mov dInsLineCount, 0
            .repeat
              movzx edx, CHR ptr [xdi + sizeof(CHR)*xbx];Read buffer character
              .break .if edx == 0                       ;ZTC = End of buffer?
              .if edx != CR && edx != LF                ;EOL (CR/LF/CRLF) reached?
                inc ebx                                 ;No
              .else
                mov dBreakChar, edx
                mov eax, dLineIndex
                .if eax == [xbx].$Obj(Editor).Lines.dCount
                  inc dInsLineCount
                  mov edx, dCharIndex
                  add edx, ebx
                  mov xax, [xsi].pEditor
                  OCall xax::Editor.LineNew, edx, dActionGroup
                  .if xax == NULL
                    ret
                  .endif
                  mov pEditorLine, xax
                  OCall pEditorLine::EditorLine.SpaceFill, dCharIndex, dLineIndex, dActionGroup
                  OCall pEditorLine::EditorLine.CharInsert, dCharIndex, ebx, xdi, dLineIndex, dActionGroup
                .else
                  mov xax, [xsi].pEditor
                  mov edx, dLineIndex
                  .if edx < [xax].$Obj(Editor).Lines.dCount
                    OCall [xax].$Obj(Editor).Lines::Collection.ItemAt, edx
                    mov pEditorLine, xax
                    OCall pEditorLine::EditorLine.CharInsert, dCharIndex, ebx, xdi, dLineIndex, dActionGroup
                  .endif
                .endif

                ;Move to next line link
                mov xax, [xsi].pEditor
                MoveToNextEditorLine xax, dLineIndex

                ;Move to next line in the clipboard buffer
                lea xdi, [xdi + sizeof(CHR)*xbx + sizeof(CHR)]  ;Next char
                .if dBreakChar == CR && CHR ptr [xdi] == LF
                  add xdi, sizeof CHR                   ;CRLF case
                .endif

                xor ebx, ebx
              .endif
            .until FALSE

          .endif

          invoke GlobalUnlock, pGlobalMem
          mov dRetValue, TRUE
        .endif
      .endif
      invoke CloseClipboard
    .endif
  .endif
  mov dRetValue, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ClientPos2TextIndex
; Purpose:    Convert view client coords to char and line indices.
; Arguments:  Arg1: -> Out POINT struct to store the indices. (0,0) is the upper left view corner.
;             Arg2: -> In POINT struct containing the the coordinates in client space.
; Return:     Nothing.
; Note:       There are no restrictions about the indices.
;             Indices can be negative if the client coords are outside the TextRect.

Method EditorView.ClientPos2TextIndex, uses xbx xdi xsi, pIndex:PPOINT, pClientPos:PPOINT
;  DbgText "EditorView.ClientPos2TextIndex"
  SetObject xsi
  mov xdi, pClientPos
  mov xbx, [xsi].pResources

  ;Calc vertical index
  xor edx, edx
  mov eax, [xdi].POINT.y
  sub eax, [xsi].TextRect.top
  .if SIGN?
    dec edx                                             ;Adjust edx if eax is negative
  .endif                                                ;sbb can not be used when eax is negative
  idiv [xbx].$Obj(EditorResources).dLineHeight
  ;Store result
  mov xdx, pIndex
  mov [xdx].POINT.y, eax

  ;Calc horizontal index
  xor edx, edx
  mov eax, [xdi].POINT.x
  sub eax, [xsi].TextRect.left
  .if SIGN?
    dec edx                                             ;Adjust edx if eax is negative
  .endif                                                ;sbb can not be used when eax is negative
  idiv [xbx].$Obj(EditorResources).EditorTextRegular.FontMetric.x
  ;In insert mode, if the remainder is > than 0.5*font width then jump to the right
  mov xcx, [xsi].pOwner
  mov xcx, [xcx].$Obj(EditorDisplay).pOwner
  .ifBitClr [xcx].$Obj(Editor).dFlags, EDF_OVERWRITE_MODE
    sal edx, 1
    .if SDWORD ptr edx > [xbx].$Obj(EditorResources).EditorTextRegular.FontMetric.x
      inc eax
    .endif
  .endif
  ;Store result
  mov xdx, pIndex
  mov [xdx].POINT.x, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.DrawEditorLines
; Purpose:    Draw all EditorLines in the View.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.DrawEditorLines, uses xbx xdi xsi
  local CodeLineRect:RECT, hBrush:HBRUSH, dCommentExitChar:DWORD, dCurrLineIndex:DWORD

;  DbgText "EditorView.OnPaint"
  SetObject xsi
  mov xdi, [xsi].pResources

  ;Loop setup
  mrm CodeLineRect.top, [xsi].TextRect.top, eax
  add eax, [xdi].$Obj(EditorResources).dLineHeight
  mov CodeLineRect.bottom, eax
  m2m CodeLineRect.left, [xsi].TextRect.left, edx
  m2m CodeLineRect.right, [xsi].TextRect.right, edx
  mov dCommentExitChar, 0                               ;Multiline comment exit char

  ;Start looping
  mov xbx, [xsi].pEditor
  mrm dCurrLineIndex, [xsi].FirstVisChar.dLineIndex, edx
  .if edx < [xbx].$Obj(Editor).Lines.dCount
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
    .repeat
      mov xcx, xax
      OCall xcx::EditorLine.Draw, xsi, addr CodeLineRect, dCommentExitChar
      mov dCommentExitChar, eax

      ;Search for the next visible EditorLine
      .repeat
        inc dCurrLineIndex
        mov eax, [xbx].$Obj(Editor).Lines.dCount
        .if dCurrLineIndex == eax                       ;No more EditorLines
          mov eax, [xsi].TextRect.bottom
          .if CodeLineRect.top < eax
            mov CodeLineRect.bottom, eax
            mov ecx, [xdi].$Obj(EditorResources).dLineHeight
            add CodeLineRect.top, ecx
            invoke FillRect, [xsi].hViewDC, addr CodeLineRect, [xdi].$Obj(EditorResources).EditorBG.hBrush
          .endif
          ExitMethod
        .endif
        mov edx, dCurrLineIndex
        .break .if edx >= [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
        test [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
      .until ZERO?
      mov ecx, [xdi].$Obj(EditorResources).dLineHeight
      add CodeLineRect.top, ecx
      add CodeLineRect.bottom, ecx
      mov edx, [xsi].TextRect.bottom
    .until CodeLineRect.top > edx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.DrawSelectionBar
; Purpose:    Draw the complete Selctionbar.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.DrawSelectionBar, uses xbx xdi xsi
  local cLineMunberBuffer[SDWORD2DEC_MAX_CHARS]:CHR, hBrush:HBRUSH
  local LineNumberRect:RECT, dLineHeight:DWORD
  local PrevLineIndicatorRect:RECT, CurrLineIndicatorRect:RECT, NextLineIndicatorRect:RECT
  local LineFoldingRect:RECT, FoldHeadRect:RECT, dFoldHeadSize:DWORD
  local SignalRect:RECT
  local hPrvPen:HPEN, hPrvBrush:HBRUSH

;  DbgText "EditorView.DrawSelectionBar"
  SetObject xsi
  mov xdi, [xsi].pResources
  mrm dLineHeight, [xdi].$Obj(EditorResources).dLineHeight, eax
  sub eax, LINEINDICATOR_SPACE_TOP
  sub eax, LINEINDICATOR_SPACE_BOTTOM
  mov dFoldHeadSize, eax

  ;Draw selection bar background
  invoke FillRect, [xsi].hViewDC, addr [xsi].SelBarRect, \
                   [xdi].$Obj(EditorResources).SelBarTextRegular.Background.hBrush

  ;Draw line numbers and indicators
  ;Loop setup
  mov edx, [xsi].SelBarRect.left
  mov LineNumberRect.left, edx
  add edx, [xsi].SelBarRect.right
  mov PrevLineIndicatorRect.right, edx
  mov CurrLineIndicatorRect.right, edx
  mov NextLineIndicatorRect.right, edx
  sub edx, [xdi].$Obj(EditorResources).dLineIndicatorWidth
  mov PrevLineIndicatorRect.left, edx
  mov CurrLineIndicatorRect.left, edx
  mov NextLineIndicatorRect.left, edx
  mov LineFoldingRect.right, edx
  sub edx, LINEINDICATOR_SPACE_LEFT
  mov FoldHeadRect.right, edx
  sub edx, [xdi].$Obj(EditorResources).dLineFoldingWidth
  mov LineFoldingRect.left, edx
  mov LineNumberRect.right, edx

  mov ecx, [xsi].SelBarRect.top
  mov LineNumberRect.top, ecx
  mov LineFoldingRect.top, ecx
  mov PrevLineIndicatorRect.top, ecx
  add ecx, LINEINDICATOR_SPACE_TOP
  mov FoldHeadRect.top, ecx
  mov CurrLineIndicatorRect.top, ecx
  mov PrevLineIndicatorRect.bottom, ecx

  mov edx, dLineHeight
  mov LineNumberRect.bottom, edx
  mov LineFoldingRect.bottom, edx
  mov NextLineIndicatorRect.bottom, edx
  sub edx, LINEINDICATOR_SPACE_BOTTOM
  mov NextLineIndicatorRect.top, edx
  mov CurrLineIndicatorRect.bottom, edx

  mov ecx, dFoldHeadSize
  mov edx, FoldHeadRect.right
  sub edx, ecx
  mov FoldHeadRect.left, edx
  mov edx, FoldHeadRect.top
  add edx, ecx
  mov FoldHeadRect.bottom, edx

  invoke SetTextColor, [xsi].hViewDC, [xdi].$Obj(EditorResources).SelBarTextRegular.ForeColor
  invoke SelectObject, [xsi].hViewDC, [xdi].$Obj(EditorResources).SelBarTextRegular.hFont
  m2m hBrush, [xdi].$Obj(EditorResources).SelBarTextRegular.Background.hBrush, xax

  mov xcx, [xsi].pEditor
  mov edx, [xsi].FirstVisChar.dLineIndex
  mov ebx, edx
  .if edx >= [xcx].$Obj(Editor).Lines.dCount
    ExitMethod
  .endif
  OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, edx
  mov xdi, xax                                          ;xdi -> Current EditorLine

  ;Start looping
  .while TRUE
    mov eax, LineNumberRect.top
    mov eax, LineNumberRect.top
    .break .if eax > [xsi].SelBarRect.bottom

    ;Draw line number
    lea edx, [ebx + 1]                                  ;edx = Line Number
    sub edx, [xsi].sdLineNumberOffset                   ;Relative zero
    invoke sdword2dec, addr cLineMunberBuffer, edx
    invoke FillRect, [xsi].hViewDC, addr LineNumberRect, hBrush
    invoke DrawText, [xsi].hViewDC, addr cLineMunberBuffer, -1, addr LineNumberRect, \
                     DT_SINGLELINE or DT_VCENTER or DT_RIGHT

    ;Draw prev line indicator
    mov xcx, [xsi].pResources
    .ifBitSet [xdi].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_PREV
      mov xax, [xcx].$Obj(EditorResources).hBrushLineIndGreen
    .elseIfBitSet [xdi].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_PREV
      mov xax, [xcx].$Obj(EditorResources).hBrushLineIndYellow
    .else
      mov xax, hBrush
    .endif
    lea xdx, PrevLineIndicatorRect
    invoke FillRect, [xsi].hViewDC, xdx, xax

    ;Draw curr line indicator
    mov xcx, [xsi].pResources
    .ifBitSet [xdi].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_CURR
      mov xax, [xcx].$Obj(EditorResources).hBrushLineIndGreen
    .elseIfBitSet [xdi].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_CURR
      mov xax, [xcx].$Obj(EditorResources).hBrushLineIndYellow
    .else
      mov xax, hBrush
    .endif
    lea xdx, CurrLineIndicatorRect
    invoke FillRect, [xsi].hViewDC, xdx, xax

    ;Draw next line indicator
    mov xcx, [xsi].pResources
    .ifBitSet [xdi].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_NEXT
      mov xax, [xcx].$Obj(EditorResources).hBrushLineIndGreen
    .elseIfBitSet [xdi].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_NEXT
      mov xax, [xcx].$Obj(EditorResources).hBrushLineIndYellow
    .else
      mov xax, hBrush
    .endif
    invoke FillRect, [xsi].hViewDC, addr NextLineIndicatorRect, xax

    ;Draw FoldHead
    .ifBitSet [xdi].$Obj(EditorLine).dFlags, ELF_FOLD_HEAD_EXPAND or ELF_FOLD_HEAD_COLLAPSE
      invoke GetStockObject, BLACK_PEN
      mov hPrvPen, $invoke(SelectObject, [xsi].hViewDC, xax)
      invoke GetStockObject, WHITE_BRUSH
      mov hPrvBrush, $invoke(SelectObject, [xsi].hViewDC, xax)
      invoke Rectangle, [xsi].hViewDC, FoldHeadRect.left, FoldHeadRect.top, FoldHeadRect.right, FoldHeadRect.bottom
      mov eax, dFoldHeadSize
      shr eax, 1
      add eax, FoldHeadRect.top
      mov edx, FoldHeadRect.left
      add edx, 2
      invoke MoveToEx, [xsi].hViewDC, edx, eax, NULL
      mov eax, dFoldHeadSize
      shr eax, 1
      add eax, FoldHeadRect.top
      mov edx, FoldHeadRect.right
      sub edx, 2
      invoke LineTo, [xsi].hViewDC, edx, eax
      .ifBitSet [xdi].$Obj(EditorLine).dFlags, ELF_FOLD_HEAD_EXPAND
        mov edx, dFoldHeadSize
        shr edx, 1
        add edx, FoldHeadRect.left
        mov eax, FoldHeadRect.top
        add eax, 2
        invoke MoveToEx, [xsi].hViewDC, edx, eax, NULL
        mov edx, dFoldHeadSize
        shr edx, 1
        add edx, FoldHeadRect.left
        mov eax, FoldHeadRect.bottom
        sub eax, 2
        invoke LineTo, [xsi].hViewDC, edx, eax
      .endif
      invoke SelectObject, [xsi].hViewDC, hPrvBrush
      invoke SelectObject, [xsi].hViewDC, hPrvPen
    .endif

    mov xdi, [xsi].pEditor
    MoveToNextVisEditorLine xdi, ebx
    .break .if xax == NULL
    mov xdi, xax                                          ;xdi -> Current EditorLine

    ;Update all RECTs
    mov eax, dLineHeight
    add LineNumberRect.top, eax
    add LineNumberRect.bottom, eax
    add LineFoldingRect.top, eax
    add LineFoldingRect.bottom, eax
    add FoldHeadRect.top, eax
    add FoldHeadRect.bottom, eax
    add PrevLineIndicatorRect.top, eax
    add PrevLineIndicatorRect.bottom, eax
    add CurrLineIndicatorRect.top, eax
    add CurrLineIndicatorRect.bottom, eax
    add NextLineIndicatorRect.top, eax
    add NextLineIndicatorRect.bottom, eax
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.Done
; Purpose:    Finalize the EditorView object.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.Done, uses xsi
  SetObject xsi
;  DbgText "EditorView.Done"
  invoke SelectObject, [xsi].hViewDC, [xsi].hPrvViewBmp ;xax = hViewBmp
  invoke DeleteObject, xax                              ;Delete memory bitmap
  invoke DeleteDC, [xsi].hViewDC                        ;Delete memory DC
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.GetCodeData
; Purpose:    Gatter EditorLine code information.
; Arguments:  Arg1: 1st visible line index.
; Return:     Nothing.

Method EditorView.GetCodeData, uses xbx xdi xsi, dFirstVisLineIndex:DWORD
  local dFirstVisLineCount:DWORD, dTotalVisLineCount:DWORD

;  DbgText "EditorView.GetCodeData"
  SetObject xsi
  mov xbx, [xsi].pEditor

  ;Reset counters
  xor edx, edx                                          ;LineNumber
  mov dTotalVisLineCount, edx
  mov dFirstVisLineCount, edx

  .ColForEach [xbx].$Obj(Editor).Lines, edi
    .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
      inc dTotalVisLineCount
      .if edi < dFirstVisLineIndex
        inc dFirstVisLineCount
      .endif
    .endif
  .ColNext

  ;Store results
  m2m [xbx].$Obj(Editor).dVisLineCount, dTotalVisLineCount, ecx
  m2m [xsi].dFirstVisLineCount, dFirstVisLineCount, ecx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.GoToLineIndex
; Purpose:    Move Line into view.
; Arguments:  Arg1: LineIndex.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

;Method EditorView.GoToLineIndex, uses xbx xdi xsi, dLineIndex:DWORD
;  local RetValue:DWORD, dLineOffset:DWORD, dPrvLineIndex:DWORD, dPrvdFirstVisLineCount:DWORD
;
;;  DbgText "EditorView.GoToLineIndex"
;  SetObject xsi
;  mov RetValue, FALSE
;  mov xbx, [xsi].pEditor
;  
;  mov edx, dLineIndex
;  .if edx < [xbx].$Obj(Editor).Lines.dCount
;    mov eax, [xbx].$Obj(Editor).dLineMaxFullVis
;    shr eax, 2
;    mov dLineOffset, eax
;    
;    m2m dPrvLineIndex, [xsi].FirstVisChar.dLineIndex, eax
;    m2m dPrvdFirstVisLineCount, [xsi].dFirstVisLineCount, eax
;    
;    mov [xsi].FirstVisChar.dLineIndex, edx
;    mov [xsi].FirstVisChar.dCharIndex, 0
;
;    mov RetValue, TRUE
;  .endif
;  mov eax, RetValue
;MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.Init
; Purpose:    Initialize the EditorView object.
; Arguments:  Arg1: -> Owner object (EditorDisplay).
;             Arg2: -> RECT.
;             Arg3: -> EditorResources.
; Return:     eax = hWnd or 0 if failed.

Method EditorView.Init, uses xbx xdi xsi, pOwner:POINTER, pRect:PRECT, pResources:$ObjPtr(EditorResources)
;  DbgText "EditorView.Init"
  SetObject xsi
  mov xdx, pOwner
  mov xax, [xdx].$Obj(EditorDisplay).pOwner
  mov [xsi].pEditor, xax                                ;Save this POINTER for quick access
  ACall xsi.Init, xdx, 0
  mrm [xsi].pResources, pResources, xax

  ;Calculate the line height
  mov ecx, [xax].$Obj(EditorResources).dCodeLineSpace
  add ecx, [xax].$Obj(EditorResources).EditorTextRegular.FontMetric.y
  mov [xax].$Obj(EditorResources).dLineHeight, ecx

  ;Set 1st visible line and gatter code information
  mov [xsi].FirstVisChar.dLineIndex, 0
  OCall xsi.GetCodeData, [xsi].FirstVisChar.dLineIndex  ;Get code initial data

  ;Create the EditorView window
  mov xbx, pRect
  mov xdi, pOwner
  invoke CreateWindowEx, 0, offset szEditorViewClassName, NULL, WS_CHILD, \
                         [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right, [xbx].RECT.bottom, \
                         [xdi].$Obj(EditorDisplay).hWnd, 0, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue the window creation process and -1 to stop it.

Method EditorView.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnCreate"
  SetObject xsi
  mov xbx, $invoke(GetDC, [xsi].hWnd)
  mov [xsi].hViewDC, $invoke(CreateCompatibleDC, xbx)
  invoke SetBkMode, [xsi].hViewDC, TRANSPARENT
  invoke CreateCompatibleBitmap, xbx, 1, 1
  mov [xsi].hViewBmp, xax
  mov [xsi].hPrvViewBmp, $invoke(SelectObject, [xsi].hViewDC, [xsi].hViewBmp)
  invoke ReleaseDC, [xsi].hWnd, xbx

  ;Set Caret on first line
  mov [xsi].CaretLocation.dCharIndex, 0
  mov [xsi].CaretLocation.dLineIndex, 0

  ;Start selection here too (in case we start a selection change right after the initialization)
  mov xdx, [xsi].pEditor
  mov [xdx].$Obj(Editor).SelectionFst.dCharIndex, 0
  mov [xdx].$Obj(Editor).SelectionFst.dLineIndex, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnGesture
; Purpose:    Event procedure for WM_GESTURE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter. lParam = info HANDLE identifying the gesture command
; Return:     eax = Zero if handled.
; Link:       https://docs.microsoft.com/en-us/windows/win32/wintouch/improving-the-single-finger-panning-experience

Method EditorView.OnGesture, uses xsi, wParam:WPARAM, lParam:LPARAM
  local GestInfo:GESTUREINFO, bHandled:BOOL, dNeedRedrawing:DWORD
  local dControlKeyPressed:DWORD

  ;DbgText "ChartWnd.OnGesture"
  SetObject xsi
  mov dNeedRedrawing, FALSE
  mov bHandled, FALSE
  mov dControlKeyPressed, 0

  ;Get status of modifier keys
  invoke GetKeyState, VK_CONTROL
  .ifBitSet eax, BIT07
    mov dControlKeyPressed, TRUE
  .endif

  ;Populate and retrieve the extra message info.
  invoke MemZero, addr GestInfo, sizeof GestInfo
  mov GestInfo.cbSize, sizeof GestInfo
  invoke GetGestureInfo, lParam, addr GestInfo

  .if eax != FALSE
    ;Now interpret the gesture
    .if GestInfo.dwID == GID_ZOOM
      .ifBitSet GestInfo.dwFlags, GF_BEGIN
        mov eax, DWORD ptr GestInfo.ullArguments
        mov [xsi].dGestureZoomFirst, eax
        mov [xsi].dGestureZoomLast, eax
        mov xcx, [xsi].pResources
        m2m [xcx].$Obj(EditorResources).dInitZoomFactor, [xcx].$Obj(EditorResources).dZoomFactor, edx
      .else
        mov ecx, DWORD ptr GestInfo.ullArguments
        .if ecx != [xsi].dGestureZoomLast             ;Take an action if the value has changed
          mov [xsi].dGestureZoomLast, ecx             ;Remember the last value
          mov eax, ecx
          sub eax, [xsi].dGestureZoomFirst            ;Calc the difference
          sal eax, 1                                  ;Scale it by x2
          mov xcx, [xsi].pResources
          add eax, [xcx].$Obj(EditorResources).dInitZoomFactor  ;Add the opeation initial value
          OCall xcx::EditorResources.Zoom, eax
          .if eax != FALSE
            mov xax, [xsi].pOwner
            mov xcx, [xax].$Obj(EditorDisplay).pOwner
            OCall [xcx].$Obj(Editor).pOwner::ClientWnd.UpdateEditors
            inc dNeedRedrawing
          .endif
        .endif
      .endif

      .if dNeedRedrawing
        invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
      .endif
      mov bHandled, TRUE

    .elseif GestInfo.dwID == GID_PAN
      ;Code for panning goes here
      .ifBitSet GestInfo.dwFlags, GF_BEGIN
        movsx eax, GestInfo.ptsLocation.x
        movsx ecx, GestInfo.ptsLocation.y
        mov [xsi].GesturePanPos.x, eax
        mov [xsi].GesturePanPos.y, ecx

      .else
        .if dControlKeyPressed
          mov xax, [xsi].pOwner
          mov edx, [xax].$Obj(EditorDisplay).ScrollPage.x
        .else
          mov edx, 1
        .endif
        movsx ecx, GestInfo.ptsLocation.x
        mov eax, ecx
        sub eax, [xsi].GesturePanPos.x
        mov [xsi].GesturePanPos.x, ecx
        .if SIGN?
          OCall xsi.ScrollPageRight, edx
          add dNeedRedrawing, eax
        .elseif !ZERO?
          OCall xsi.ScrollPageLeft, edx
          add dNeedRedrawing, eax
        .endif

        .if dControlKeyPressed
          mov xax, [xsi].pOwner
          mov edx, [xax].$Obj(EditorDisplay).ScrollPage.y
        .else
          mov edx, 1
        .endif
        movsx ecx, GestInfo.ptsLocation.y
        mov eax, ecx
        sub eax, [xsi].GesturePanPos.y
        mov [xsi].GesturePanPos.y, ecx
        .if SIGN?
          OCall xsi.ScrollVisPageDown, edx
          .if eax != 0
            inc dNeedRedrawing
          .endif
        .elseif !ZERO?
          OCall xsi.ScrollVisPageUp, edx
          .if eax != 0
            inc dNeedRedrawing
          .endif
        .endif

        .if dNeedRedrawing
          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
          OCall xsi.CaretSet
        .endif

      .endif
      mov bHandled, TRUE

      invoke CloseGestureInfoHandle, lParam             ;Close the gesture handle
    .endif
  .endif

  .if bHandled
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnKillFocus
; Purpose:    Event procedure for WM_KILLFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnKillFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnKillFocus"
  SetObject xsi
  ;Ucomment for Release Version
  OCall xsi.CaretHide
  OCall xsi.CaretDestroy
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnLButtonDblClk
; Purpose:    Event procedure for WM_LBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnLButtonDblClk, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dSelBeg:DWORD, dSelEnd:DWORD, dNeedRedrawing:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnLButtonDblClk"
  SetObject xsi
  mov [xsi].dLockedCharIndex, -1
  mov dNeedRedrawing, 0
  mov xdi, [xsi].pEditor
  mov edx, [xsi].CaretLocation.dLineIndex
  .if edx < [xdi].$Obj(Editor).Lines.dCount
    OCall [xdi].$Obj(Editor).Lines::Collection.ItemAt, edx
    mov xbx, xax
    ;Search for the end of a word
    mov edx, [xsi].CaretLocation.dCharIndex
    .while TRUE
      mov xcx, [xbx].$Obj(EditorLine).pBuffer
      movzx eax, CHR ptr [xcx + sizeof(CHR)*xdx]
      .break .if eax == 0
      GetCharType eax, ecx
      .if !(ecx & CHR_WORD)
        .break
      .endif
      inc edx
    .endw
    mov dSelEnd, edx

    ;Search beginning of word
    mov edx, [xsi].CaretLocation.dCharIndex
    .while edx > 0
      mov xcx, [xbx].$Obj(EditorLine).pBuffer
      movzx eax, CHR ptr [xcx + sizeof(CHR)*xdx - sizeof(CHR)]
      .if eax == '.'
        .break
      .else
        GetCharType eax, ecx
        .if !(ecx & CHR_WORD)
          .break
        .endif
      .endif
      dec edx
    .endw
    mov dSelBeg, edx

    .if edx != dSelEnd
      OCall xdi::Editor.SelectionResetLines
      m2m [xdi].$Obj(Editor).SelectionFst.dCharIndex, dSelBeg, eax
      mrm [xdi].$Obj(Editor).SelectionLst.dCharIndex, dSelEnd, eax
      mov [xsi].CaretLocation.dCharIndex, eax             ;Move caret to the selection end

      mov eax, [xsi].CaretLocation.dLineIndex
      mov [xdi].$Obj(Editor).SelectionFst.dLineIndex, eax
      mov [xdi].$Obj(Editor).SelectionLst.dLineIndex, eax

      OCall xdi::Editor.SelectionSet
      add dNeedRedrawing, eax
      BitSet [xdi].$Obj(Editor).dFlags, EDF_CARET_LOCKED
    .endif

    .if dNeedRedrawing != 0
      invoke RedrawWindow, [xsi].hWnd, addr [xsi].TextRect, 0, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnLButtonDown, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT, Index:POINT, dCurLineIndex:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnLButtonDown"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor

  invoke SetFocus, [xsi].hWnd
  OCall xbx::Editor.HilitedWordReset

  PntS2Pnt CursorPos, lParam
  OCall xsi.ClientPos2TextIndex, addr Index, addr CursorPos
  invoke IsPntInRect, addr CursorPos, addr [xsi].TextRect   ;Clicked into TextRect?
  .if eax != FALSE
    ;Left-Clicked in TextRect
    BitClr [xsi].dFlags, EVF_LBUTTON_DOWN_SELBAR        ;Clear flag
    BitSet [xsi].dFlags, EVF_LBUTTON_DOWN_TEXTBOX       ;Set flag
    OCall xbx::Editor.SelectionResetLines               ;Clear previous selection

    ;Compute Cursor Index.x and Index.y
    OCall xsi.VertIndex2EditorLine, Index.y
    mov dCurLineIndex, edx
    .if xax == NULL
      ;Limit the y position to the last visible EditorLine
      mov xax, xcx                                      ;xax -> Last visible EditorLine
      sub edx, [xsi].FirstVisChar.dLineIndex            ;edx = Last visible LineIndex
      mov Index.y, edx
    .endif

    ;In INS/OVR mode, limit the x position to the text length
    .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
      mov edx, [xax].$Obj(EditorLine).dLength
      sub edx, [xsi].FirstVisChar.dCharIndex            ;edx can be negative!
      mov ecx, Index.x
      cmp ecx, edx
      cmovg ecx, edx
      mov Index.x, ecx
    .endif
    mov xdi, xax

    ;At this point xdi -> current EditorLine and Index.x & Index.y are set
    mov edx, [xsi].FirstVisChar.dCharIndex
    add edx, Index.x
    mov [xsi].CaretLocation.dCharIndex, edx

    mov eax, dCurLineIndex
    mov [xsi].CaretLocation.dLineIndex, eax

    .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
      .if SDWORD ptr Index.x < 0
        OCall xsi.ScrollCaretInViewLeft
      .endif
    .endif

    invoke GetKeyState, VK_SHIFT
    .ifBitClr eax, BIT07
      ;<SHIFT> NOT pressed
      invoke SetCapture, [xsi].hWnd
      mov [xsi].dLockedCharIndex, -1                    ;Reset persistant x caret position

      ;Store clicked point information
      s2s [xbx].$Obj(Editor).SelectionFst, [xsi].CaretLocation, xax, xdx
      OCall xbx::Editor.SelectionResetInfo

    .else
      ;<SHIFT> pressed
      ;Store caret information
      s2s [xbx].$Obj(Editor).SelectionLst, [xsi].CaretLocation, xax, xdx
      OCall xbx::Editor.SelectionSet
    .endif
    invoke RedrawWindow, [xsi].hWnd, addr [xsi].TextRect, 0, RDW_UPDATENOW or RDW_INVALIDATE
    OCall xsi.CaretSet
    OCall xsi.CaretShow

  .else
    ;Clicked into SelBarRect
    BitSet [xsi].dFlags, EVF_LBUTTON_DOWN_SELBAR        ;Set flag
    BitClr [xsi].dFlags, EVF_LBUTTON_DOWN_TEXTBOX       ;Clear flag

    invoke SetCapture, [xsi].hWnd                       ;Clicked in the RectRect
    mov [xsi].dLockedCharIndex, -1                      ;Reset persistant x caret position

    OCall xbx::Editor.SelectionResetLines               ;Reset selection
    invoke GetKeyState, VK_SHIFT
    .ifBitClr eax, BIT07
      ;<SHIFT> NOT pressed
      ;Make a full line selection
      OCall xsi.VertIndex2EditorLine, Index.y 
      mov [xbx].$Obj(Editor).SelectionFst.dLineIndex, edx
      mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, edx
      mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, 0
      mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, -1
      OCall xbx::Editor.SelectionSet
    .else
      ;>SHIFT> pressed
      OCall xsi.VertIndex2EditorLine, Index.y 
      .if [xbx].$Obj(Editor).SelectionFst.dLineIndex < edx
        ;After first selection
        mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, edx
      .else
        ;Before first selection
        mov [xbx].$Obj(Editor).SelectionFst.dLineIndex, edx
        mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, 0
      .endif
      mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, -1
      OCall xbx::Editor.SelectionSet
    .endif

    invoke RedrawWindow, [xsi].hWnd, addr [xsi].TextRect, 0, RDW_UPDATENOW or RDW_INVALIDATE
  .endif

@@Exit:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method EditorView.OnLButtonUp, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnLButtonUp"
  SetObject xsi
  BitClr [xsi].dFlags, EVF_LBUTTON_DOWN_SELBAR
  BitClr [xsi].dFlags, EVF_LBUTTON_DOWN_TEXTBOX
  invoke ReleaseCapture
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.
; Note:       WM_MOUSEMOVE and WM_LBUTTONUP are fired when the Editor is maximized with the mouse.

DoCursorPositionDelay macro Axis:req, Border:req
  ;Calculate the repost delay as e.g.:
  ; Delay = (40 - (CursorY - TextRect.bottom))^2/4 taking care to avoid negative numbers
  invoke GetWindowRect, [xsi].hWnd, addr WndRect
  invoke GetCursorPos, addr CursorPos2
  mov xcx, [xsi].pResources
  xor edx, edx
  ifidn <Border>, <top>
    mov eax, WndRect.top
    sub eax, CursorPos2.&Axis
  elseifidn <Border>, <bottom>
    mov eax, CursorPos2.&Axis
    sub eax, WndRect.bottom
    add eax, [xcx].$Obj(EditorResources).ScrollBarMetric.&Axis
  elseifidn <Border>, <left>
    mov eax, WndRect.left
    add eax, [xsi].TextRect.left
    sub eax, CursorPos2.&Axis
  elseifidn <Border>, <right>
    mov eax, CursorPos2.&Axis
    sub eax, WndRect.right
    add eax, [xcx].$Obj(EditorResources).ScrollBarMetric.&Axis
  endif
  cmp eax, edx
  cmovs eax, edx
  mov ecx, 40
  sub ecx, eax
  cmp ecx, edx
  cmovs ecx, edx
  mov eax, ecx
  mul ecx
  shr eax, 2
  add eax, 50
  invoke Sleep, eax
endm

SynthesizeMouseMove macro
  .ifBitSet [xsi].dFlags, EVF_LBUTTON_DOWN              ;Send only if the LBUTTON is down
    mov eax, WndRect.left
    sub CursorPos2.x, eax
    mov eax, WndRect.top
    sub CursorPos2.y, eax
    mov eax, CursorPos2.x
    mov lParam.POINTS.x, ax
    mov eax, CursorPos2.y
    mov lParam.POINTS.y, ax
    invoke PostMessage, [xsi].hWnd, WM_MOUSEMOVE, wParam, lParam
  .endif
;  .ifBitSet [xsi].dFlags, EVF_LBUTTON_DOWN              ;Send only if the LBUTTON is down
;    mov Input.INPUT.type_, INPUT_MOUSE
;    mov Input.INPUT.mi.dx_, 0
;    mov Input.INPUT.mi.dy, 1
;    mov Input.INPUT.mi.mouseData, 0
;    mov Input.INPUT.mi.dwFlags, MOUSEEVENTF_MOVE or MOUSEEVENTF_LEFTDOWN
;    mov Input.INPUT.mi.time, 0
;    mov Input.INPUT.mi.dwExtraInfo, NULL
;    invoke SendInput, 1, addr Input, sizeof Input
;    DbgDec eax, "SendInput"
;  .endif

endm

Method EditorView.OnMouseMove, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos1:POINT, CursorPos2:POINT, WndRect:RECT, Index:POINT
  local dNeedRedrawing:DWORD, dCurLineIndex:DWORD

  ANNOTATION use:CursorPos2 WndRect wParam lParam

;  DbgText "EditorView.OnMouseMove"
  SetObject xsi
  mov xbx, [xsi].pEditor
  mov dNeedRedrawing, 0
  PntS2Pnt CursorPos1, lParam
  OCall xsi.ClientPos2TextIndex, addr Index, addr CursorPos1  ;Indices can be negative!

  .ifBitSet [xsi].dFlags, EVF_LBUTTON_DOWN_TEXTBOX
    ;Moving in TextRect
    .ifBitSet wParam, MK_LBUTTON
      OCall xsi.VertIndex2EditorLine, Index.y
      mov dCurLineIndex, edx
      .if xax != NULL
        mov xdi, xax
        .if Index.x < 0
          mov Index.x, 0                                ;Avoid a negative index
        .endif
        OCall xbx::Editor.SelectionResetLines
        ;In INS/OVR mode, limit the x position to the text length
        .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
          mov edx, [xdi].$Obj(EditorLine).dLength
          sub edx, [xsi].FirstVisChar.dCharIndex        ;edx can be negative!
          mov ecx, Index.x
          cmp ecx, edx
          cmovg ecx, edx
          mov Index.x, ecx
        .endif

        mov edx, Index.x
        add edx, [xsi].FirstVisChar.dCharIndex
        mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, edx
        m2m [xbx].$Obj(Editor).SelectionLst.dLineIndex, dCurLineIndex, edx
        OCall xbx::Editor.SelectionSet
        add dNeedRedrawing, eax

        xor eax, eax
        ;Scroll the view horizontally to see the caret
        mov ecx, CursorPos1.x
        .if SDWORD ptr ecx >= [xsi].TextRect.right
          OCall xsi.ScrollLineRight
          .if eax != 0
            inc dNeedRedrawing
  ;            DoCursorPositionDelay x, right
  ;            SynthesizeMouseMove
          .endif
        .elseif SDWORD ptr ecx < [xsi].TextRect.left
          OCall xsi.ScrollLineLeft
          .if eax != 0
            inc dNeedRedrawing
  ;            DoCursorPositionDelay x, left
  ;            SynthesizeMouseMove
          .endif
        .endif

        ;Scroll vertically to show the caret
        mov ecx, CursorPos1.y
        .if SDWORD ptr ecx >= [xsi].TextRect.bottom
          OCall xsi.ScrollVisLineDown
          .if eax != 0
            inc dNeedRedrawing
  ;            DoCursorPositionDelay y, bottom
  ;            SynthesizeMouseMove
          .endif
        .elseif SDWORD ptr ecx < [xsi].TextRect.top
          OCall xsi.ScrollVisLineUp
          .if eax != 0
            inc dNeedRedrawing
  ;            DoCursorPositionDelay y, top
  ;            SynthesizeMouseMove
          .endif
        .endif
      .endif
    .endif

  .elseIfBitSet [xsi].dFlags, EVF_LBUTTON_DOWN_SELBAR
    ;Moving in SelBox
    .ifBitSet wParam, MK_LBUTTON
      OCall xsi.VertIndex2EditorLine, Index.y
      .if xax != NULL
        mov edi, edx                                    ;edi = EditorLine index
        OCall xbx::Editor.SelectionResetLines           ;Reset previous selected lines
        mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, edi
        mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, -1
        OCall xbx::Editor.SelectionSet
        add dNeedRedrawing, eax
      .endif
    .endif
  .endif

  ;Update
  .if dNeedRedrawing != 0
    invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if the message is processed.
; Note:       Precision scrolling (multiples of 120) can be implemented here

Method EditorView.OnMouseWheel, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dNeedRedrawing:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnMouseWheel"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov xax, wParam
  shr eax, 16
  movsx ecx, ax
  mov xax, [xsi].pResources
  .ifBitSet [xax].$Obj(EditorResources).dFlags, ERF_REVERSE_MOUSE_WHEEL_VERT
    neg ecx
  .endif

  .ifBitSet wParam, MK_SHIFT
    ;Horizontal scroll
    mov edx, [xsi].FirstVisChar.dCharIndex
    .ifBitSet wParam, MK_CONTROL
      ;Page scroll
      mov xax, [xsi].pOwner
      .if SDWORD ptr ecx > 0
        sub edx, [xax].$Obj(EditorDisplay).ScrollPage.x
      .else
        add edx, [xax].$Obj(EditorDisplay).ScrollPage.x
      .endif
    .else
      ;Regular scroll = 120 px
      .if SDWORD ptr ecx > 0
        dec edx
      .else
        inc edx
      .endif
    .endif

    mov xcx, [xsi].pOwner
    mov xax, [xcx].$Obj(EditorDisplay).pOwner
    mov ecx, [xax].$Obj(Editor).dMaxLineCharCount
    dec ecx
    .if SDWORD ptr edx > ecx
      mov edx, ecx
    .endif
    .if SDWORD ptr edx < 0
      xor edx, edx
    .endif

    .if edx != [xsi].FirstVisChar.dCharIndex
      mov [xsi].FirstVisChar.dCharIndex, edx
      inc dNeedRedrawing
    .endif

  .else
    ;Vertical scroll
    .ifBitSet wParam, MK_CONTROL
      ;Page scroll
      mov xax, [xsi].pOwner
      .if SDWORD ptr ecx > 0
        OCall xsi.ScrollVisPageUp, [xax].$Obj(EditorDisplay).ScrollPage.y    ;Goto previous page with saturation
        add dNeedRedrawing, eax
      .else
        OCall xsi.ScrollVisPageDown, [xax].$Obj(EditorDisplay).ScrollPage.y  ;Goto next page with saturation
        add dNeedRedrawing, eax
      .endif
    .else
      ;Regular scroll = 1 Line
      .if SDWORD ptr ecx > 0
        OCall xsi.ScrollVisLineUp                ;Goto previous visible line with saturation
        .if eax != 0
          inc dNeedRedrawing
        .endif
      .else
        OCall xsi.ScrollVisLineDown              ;Goto next visible line with saturation
        .if eax != 0
          inc dNeedRedrawing
        .endif
      .endif
    .endif
  .endif

  .if dNeedRedrawing != 0
    mov xbx, [xsi].pOwner
    OCall xbx::EditorDisplay.SetGuiLayout
    invoke RedrawWindow, [xbx].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif

  ;Set the caret only if this is the active MDI child
  mov xbx, [xsi].pEditor
  mov xcx, [xbx].$Obj(Editor).pOwner
  invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
  .if xax == [xbx].$Obj(Editor).hWnd
    OCall xsi.CaretSet
  .endif
    
  mov eax, 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnMouseHWheel
; Purpose:    Event procedure for WM_MOUSEHWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method EditorView.OnMouseHWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dNeedRedrawing:DWORD, CtrlKeyState:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnMouseHWheel"
  SetObject xsi
  mov dNeedRedrawing, 0
  ;Contrary to the documentation, the LOWWORD bits are always zero.
  ;To get the state of the CTRL key, we need to use the GetKeyState API.
  invoke GetKeyState, VK_CONTROL
  mov CtrlKeyState, eax

  mov xax, wParam
  shr eax, 16                                         ;Get high word
  movsx ecx, ax
  mov xax, [xsi].pResources
  .ifBitClr [xax].$Obj(EditorResources).dFlags, ERF_REVERSE_MOUSE_WHEEL_HORZ
    neg ecx                                           ;This is to recreate the standard behaviour
  .endif

  mov edx, [xsi].FirstVisChar.dCharIndex
  .ifBitSet CtrlKeyState, BIT15                       ;CTRL Key is pressed
    ;Page scroll
    mov xax, [xsi].pOwner
    .if SDWORD ptr ecx < 0
      OCall xsi.ScrollPageLeft, [xax].$Obj(EditorDisplay).ScrollPage.x
      add dNeedRedrawing, eax
    .else
      OCall xsi.ScrollPageRight, [xax].$Obj(EditorDisplay).ScrollPage.x
      add dNeedRedrawing, eax
    .endif
  .else
    ;Regular scroll = 120 px
    .if SDWORD ptr ecx < 0
      OCall xsi.ScrollLineLeft
      add dNeedRedrawing, eax
    .else
      OCall xsi.ScrollLineRight
      add dNeedRedrawing, eax
    .endif
  .endif

  .if dNeedRedrawing != 0
    mov xax, [xsi].pOwner
    invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif

  ;Set the caret only if this is the active MDI child
  mov xbx, [xsi].pEditor
  mov xcx, [xbx].$Obj(Editor).pOwner
  invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
  .if xax == [xbx].$Obj(Editor).hWnd
    OCall xsi.CaretSet
  .endif

  mov eax, 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnPaint"
  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)     ;Hides the caret automatically

  OCall xsi.DrawEditorLines
  ;The selection bar must be drawn AFTER the EditorLines to avoid clipping of the TextRect
  OCall xsi.DrawSelectionBar

  ;Copy bitmap to screen
  invoke BitBlt, hDC, [xsi].SelBarRect.left, [xsi].TextRect.top, \
                      [xsi].TextRect.right, [xsi].TextRect.bottom, [xsi].hViewDC, 0, 0, SRCCOPY

  invoke EndPaint, [xsi].hWnd, addr PS                  ;Restores the caret if it was previously
  xor eax, eax                                          ;   hidden by BeginPaint
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnRButtonDown
; Purpose:    Event procedure for WM_RBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnRButtonDown, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT, Index:POINT, dCurVisIndex:DWORD, dLastVisLineIndex:DWORD, VisLineCounter

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnRButtonDown"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  PntS2Pnt CursorPos, lParam
  invoke IsPntInRect, addr CursorPos, addr [xsi].SelBarRect  ;Clicked into SelBarRect?
  .if eax != FALSE
    ;Toggle relative line numbering
    .if [xsi].sdLineNumberOffset == 0
      OCall xsi.ClientPos2TextIndex, addr Index, addr CursorPos
      m2m dCurVisIndex, [xsi].FirstVisChar.dLineIndex, ecx
      MoveToNextVisEditorPage xbx, dCurVisIndex, Index.y,, dLastVisLineIndex
      mov edx, dCurVisIndex
      inc edx
      mov [xsi].sdLineNumberOffset, edx
    .else
      mov [xsi].sdLineNumberOffset, 0
    .endif
    OCall [xsi].pOwner::EditorDisplay.SetGuiLayout      ;LineNumbers length may have changed
    mov xax, [xsi].pOwner
    invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_UPDATENOW or RDW_INVALIDATE
  .else
    ;Debug helper
    invoke GetKeyState, VK_CONTROL
    .ifBitClr eax, BIT07
      ;<CONTROL> NOT pressed
      OCall xsi.ClientPos2TextIndex, addr Index, addr CursorPos
      m2m dCurVisIndex, [xsi].FirstVisChar.dLineIndex, ecx
      MoveToNextVisEditorPage xbx, dCurVisIndex, Index.y,, dLastVisLineIndex
      DbgEditorLine xax,, "EditorLine"
    .else
      ;<CONTROL> pressed
      OCall xsi.ClientPos2TextIndex, addr Index, addr CursorPos
      m2m dCurVisIndex, [xsi].FirstVisChar.dLineIndex, ecx
      MoveToNextVisEditorPage xbx, dCurVisIndex, Index.y,, dLastVisLineIndex
      BitSet [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
      mov xax, [xsi].pOwner
      invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnSetCursor
; Purpose:    Event procedure for WM_SETCURSOR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE => further processing is halted.

Method EditorView.OnSetCursor, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPosition:POINT

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnSetCursor"
  and lParam, 0FFFF0000h
  .if lParam != 0
    SetObject xsi
    mov xbx, [xsi].pResources
    invoke GetCursorPos, addr CursorPosition
    invoke ScreenToClient, [xsi].hWnd, addr CursorPosition
    invoke IsPntInRect, addr CursorPosition, addr [xsi].TextRect
    .if eax != FALSE
      invoke SetCursor, [xbx].$Obj(EditorResources).hCursorIBeam
    .else
      invoke IsPntInRect, addr CursorPosition, addr [xsi].SelBarRect
      .if eax != FALSE
        invoke SetCursor, [xbx].$Obj(EditorResources).hCursorSelect
      .else
        invoke SetCursor, [xbx].$Obj(EditorResources).hCursorArrow
      .endif
    .endif
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnSetFocus
; Purpose:    Event procedure for WM_SETFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnSetFocus, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnSetFocus"
  SetObject xsi
  mov xbx, [xsi].pEditor
  mov [xbx].$Obj(Editor).pFocusedView, xsi
  OCall xsi.CaretNew
  OCall xsi.CaretSet
  .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
      [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
    OCall xsi.CaretHide
  .else
    OCall xsi.CaretShow
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method EditorView.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnSize"
  SetObject xsi
  .if wParam != SIZE_MINIMIZED && lParam != 0           ;x = 0 & y = 0
    OCall xsi.SetGuiLayout
    OCall xsi.CaretSet
    xor eax, eax
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollCaretInViewBottom
; Purpose:    Adjust FirstVisChar.dCharIndex so that the caret becomes visible.
; Arguments:  None.
; Return:     eax = Number of scrolled visible lines.

Method EditorView.ScrollCaretInViewBottom, uses xsi
;  DbgText "EditorView.ScrollCaretInViewBottom
  SetObject xsi
  mov edx, [xsi].CaretLocation.dLineIndex
  mov ecx, [xsi].FirstVisChar.dLineIndex
  add ecx, [xsi].dLineMaxFullVis
  dec ecx                                               ;Convert to index (base 0)
  xor eax, eax                                          ;Return FALSE
  .if edx > ecx
    sub edx, ecx
    OCall xsi.ScrollVisPageDown, edx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollCaretInViewLeft
; Purpose:    Adjust FirstVisChar.dCharIndex so that the caret becomes visible.
; Arguments:  None.
; Return:     eax = 1 if the View must be updated, otherwise 0.

Method EditorView.ScrollCaretInViewLeft, uses xsi
;  DbgText "EditorView.ScrollCaretInViewLeft
  SetObject xsi
  mov ecx, [xsi].CaretLocation.dCharIndex
  mov edx, [xsi].FirstVisChar.dCharIndex
  xor eax, eax                                          ;Return FALSE
  .if ecx < edx
    sub edx, ecx
    OCall xsi.ScrollPageLeft, edx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollCaretInViewRight
; Purpose:    Adjust FirstVisChar.dCharIndex so that the caret becomes visible.
; Arguments:  None.
; Return:     eax = 1 if the View must be updated, otherwise 0.

Method EditorView.ScrollCaretInViewRight, uses xsi
;  DbgText "EditorView.ScrollCaretInViewRight"
  SetObject xsi
  mov edx, [xsi].CaretLocation.dCharIndex
  sub edx, [xsi].FirstVisChar.dCharIndex
  mov ecx, [xsi].dCharMaxFullVis
  xor eax, eax                                          ;Return FALSE
  .if edx >= ecx
    sub edx, ecx
    OCall xsi.ScrollPageRight, edx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollCaretInViewTop
; Purpose:    Adjust FirstVisChar.dCharIndex so that the caret becomes visible.
; Arguments:  None.
; Return:     eax = Number of scrolled visible lines.

Method EditorView.ScrollCaretInViewTop, uses xsi
;  DbgText "EditorView.ScrollCaretInViewTop
  SetObject xsi
  mov ecx, [xsi].CaretLocation.dLineIndex
  mov edx, [xsi].FirstVisChar.dLineIndex
  xor eax, eax                                          ;Return FALSE
  .if ecx < edx
    sub edx, ecx
    OCall xsi.ScrollVisPageUp, edx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollVisLineDown
; Purpose:    Scroll one line down with saturation.
; Arguments:  None.
; Return:     eax = Number of scrolled lines.

Method EditorView.ScrollVisLineDown, uses xbx xdi xsi
;  DbgText "EditorView.ScrollVisLineDown"
  SetObject xsi
  mov xbx, [xsi].pEditor
  mov edi, [xsi].FirstVisChar.dLineIndex

  .While TRUE
    inc edi
    .if edi == [xbx].$Obj(Editor).Lines.dCount
      dec edi
      .break
    .endif
    .break .if edi >= [xbx].$Obj(Editor).Lines.dCount
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi
    .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
      .break
    .endif
  .endw

  .if edi != [xsi].FirstVisChar.dLineIndex
    mov ebx, edi
    sub ebx, [xsi].FirstVisChar.dLineIndex
    mov [xsi].FirstVisChar.dLineIndex, edi
    inc [xsi].dFirstVisLineCount
    OCall xsi.SetGuiLayout
    mov xax, [xsi].pOwner
    invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarVert.hWnd, SB_CTL, [xsi].dFirstVisLineCount, TRUE
    mov eax, ebx
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollLineLeft
; Purpose:    Scroll one line left with saturation.
; Arguments:  None.
; Return:     eax = 1 if the View must be updated, otherwise 0.

Method EditorView.ScrollLineLeft, uses xsi
;  DbgText "EditorView.ScrollLineLeft"
  SetObject xsi
  xor eax, eax                                          ;Set return value to FALSE
  .if [xsi].FirstVisChar.dCharIndex != 0
    dec [xsi].FirstVisChar.dCharIndex
    mov xax, [xsi].pOwner
    invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarHorz.hWnd, SB_CTL, [xsi].FirstVisChar.dCharIndex, TRUE
    mov eax, 1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollLineRight
; Purpose:    Scroll one line right with saturation.
; Arguments:  None.
; Return:     eax = 1 if the View must be updated, otherwise 0.

Method EditorView.ScrollLineRight, uses xsi
  SetObject xsi
  mov xdx, [xsi].pEditor

  xor eax, eax                                          ;Set return value to FALSE
  mov edx, [xdx].$Obj(Editor).dMaxLineCharCount
  sub edx, 1                                            ;Let last char visible
  .if SDWORD ptr edx > [xsi].FirstVisChar.dCharIndex
    inc [xsi].FirstVisChar.dCharIndex
    mov xcx, [xsi].pOwner
    invoke SetScrollPos, [xcx].$Obj(EditorDisplay).ScrollBarHorz.hWnd, SB_CTL, [xsi].FirstVisChar.dCharIndex, TRUE
    mov eax, 1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollVisLineUp
; Purpose:    Scroll one line up with saturation.
; Arguments:  None.
; Return:     eax = Number of scrolled lines.

Method EditorView.ScrollVisLineUp, uses xbx xdi xsi
;  DbgText "EditorView.ScrollVisLineUp"
  SetObject xsi
  mov xbx, [xsi].pEditor
  mov edi, [xsi].FirstVisChar.dLineIndex

  .While TRUE
    dec edi
    .if SIGN?
      inc edi
      .break
    .endif
    .break .if edi >= [xbx].$Obj(Editor).Lines.dCount
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi
    .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
      .break
    .endif
  .endw

  .if edi != [xsi].FirstVisChar.dLineIndex
    mov ebx, [xsi].FirstVisChar.dLineIndex
    sub ebx, edi
    mov [xsi].FirstVisChar.dLineIndex, edi
    dec [xsi].dFirstVisLineCount
    OCall xsi.SetGuiLayout
    mov xax, [xsi].pOwner
    invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarVert.hWnd, SB_CTL, [xsi].dFirstVisLineCount, TRUE
    mov eax, ebx
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollPageLeft
; Purpose:    Scroll one page left with saturation.
; Arguments:  Arg1: Number of lines in a page. If -1 is passed, it scrolls to the leftmost position.
; Return:     eax = 1 if the View must be updated, otherwise 0.
;             ecx = Index delta.

Method EditorView.ScrollPageLeft, uses xbx xsi, dPageSize:DWORD
;  DbgText "EditorView.ScrollPageLeft"
  xor eax, eax
  xor ecx, ecx
  ?mov edx, dPageSize
  .if edx != 0
    SetObject xsi
    mov eax, [xsi].FirstVisChar.dCharIndex
    .if eax != 0
      .if edx != -1
        sub eax, edx
        .if SDWORD ptr eax < 0
          xor eax, eax
        .endif
      .else
        xor eax, eax
      .endif
      mov ebx, [xsi].FirstVisChar.dCharIndex
      sub ebx, eax
      mov [xsi].FirstVisChar.dCharIndex, eax
      mov xax, [xsi].pOwner
      invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarHorz.hWnd, SB_CTL, [xsi].FirstVisChar.dCharIndex, TRUE
      mov ecx, ebx
      mov eax, 1
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollPageRight
; Purpose:    Scroll one page right with saturation.
; Arguments:  Arg1: Number of lines in a page.
; Return:     eax = 1 if the View must be updated, otherwise 0.
;             ecx = Index delta (signed).

Method EditorView.ScrollPageRight, uses xbx xsi, dPageSize:DWORD
;  DbgText "EditorView.ScrollPageRight"
  xor eax, eax
  xor ecx, ecx
  ?mov edx, dPageSize
  .if edx != 0
    SetObject xsi
    mov xbx, [xsi].pEditor
    .if edx != -1
      mov eax, [xsi].FirstVisChar.dCharIndex
      add eax, edx
      .if SDWORD ptr eax > [xbx].$Obj(Editor).dMaxLineCharCount
        mov eax, [xbx].$Obj(Editor).dMaxLineCharCount
      .endif
    .else
      mov eax, [xbx].$Obj(Editor).dMaxLineCharCount
    .endif
    mov ebx, [xsi].FirstVisChar.dCharIndex
    sub ebx, eax
    mov [xsi].FirstVisChar.dCharIndex, eax
    mov xax, [xsi].pOwner
    invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarHorz.hWnd, SB_CTL, [xsi].FirstVisChar.dCharIndex, TRUE
    mov ecx, ebx
    mov eax, 1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollVisPageDown
; Purpose:    Scroll one page down with saturation.
; Arguments:  Arg1: Number of lines in a page.
; Return:     eax = Number of scrolled visible lines.

Method EditorView.ScrollVisPageDown, uses xbx xsi, dPageSize:DWORD
  local dVisLineCount:DWORD, dLastVisLine:DWORD

;  DbgText "EditorView.ScrollVisPageDown"
  SetObject xsi
  mov xbx, [xsi].pEditor
  mov dVisLineCount, 0
  MoveToNextVisEditorPage xbx, [xsi].FirstVisChar.dLineIndex, dPageSize, dVisLineCount, dLastVisLine
  .if dVisLineCount
    mov eax, dVisLineCount
    add [xsi].dFirstVisLineCount, eax
    OCall xsi.SetGuiLayout
    mov xax, [xsi].pOwner
    invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarVert.hWnd, SB_CTL, [xsi].dFirstVisLineCount, TRUE
  .endif
  mov eax, dVisLineCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.ScrollVisPageUp
; Purpose:    Scroll one page up with saturation.
; Arguments:  Arg1: Number of lines in a page.
; Return:     eax = Number of scrolled visible lines.

Method EditorView.ScrollVisPageUp, uses xbx xsi, dPageSize:DWORD
  local dVisLineCount:DWORD, dLastVisLine:DWORD

;  DbgText "EditorView.ScrollVisPageUp"
  SetObject xsi
  mov xbx, [xsi].pEditor
  mov dVisLineCount, 0
  MoveToPrevVisEditorPage xbx, [xsi].FirstVisChar.dLineIndex, dPageSize, dVisLineCount, dLastVisLine
  .if dVisLineCount
    mov eax, dVisLineCount
    sub [xsi].dFirstVisLineCount, eax
    OCall xsi.SetGuiLayout
    mov xax, [xsi].pOwner
    invoke SetScrollPos, [xax].$Obj(EditorDisplay).ScrollBarVert.hWnd, SB_CTL, [xsi].dFirstVisLineCount, TRUE
  .endif
  mov eax, dVisLineCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.SelectBeginAtCaretLocation
; Purpose:    Set selection begin at caret location.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.SelectBeginAtCaretLocation, uses xbx xsi
;  DbgText "EditorView.SelectSetBegin"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xbx, [xcx].$Obj(EditorDisplay).pOwner
  OCall xbx::Editor.SelectionResetLines

  ;Store clicked point information
  mov eax, [xsi].CaretLocation.dLineIndex
  mov [xbx].$Obj(Editor).SelectionFst.dLineIndex, eax
  mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, eax

  mov eax, [xsi].CaretLocation.dCharIndex
  mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, eax
  mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.SelectUpToCaretLocation
; Purpose:    Select text up to the current CaretLocation.
; Arguments:  None.
; Return:     eax = Number of selected lines.

Method EditorView.SelectUpToCaretLocation, uses xbx xsi
;  DbgText "EditorView.SelectUpToCaretLocation"
  SetObject xsi
  mov xbx, [xsi].pEditor
  OCall xbx::Editor.SelectionResetLines
  s2s [xbx].$Obj(Editor).SelectionLst, [xsi].CaretLocation, xax, xcx
  OCall xbx::Editor.SelectionSet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.SetGuiLayout
; Purpose:    Define the position an size of all GUI elements in the EditorView.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.SetGuiLayout, uses xbx xdi xsi
  local ClientRect:RECT, dLineNumWidth:DWORD, dLastVisLineIndex:DWORD, dLineHeight:DWORD

;  DbgText "EditorView.SetGuiLayout"
  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr ClientRect

  ;Define the coords of the main RECTs
  mov ecx, ClientRect.bottom
  mov [xsi].SelBarRect.bottom, ecx
  mov [xsi].TextRect.bottom, ecx

  mov eax, ClientRect.right
  mov [xsi].TextRect.right, eax
  m2z [xsi].SelBarRect.left
  m2z [xsi].TextRect.top

  ;Calc the SelBar width
  mov xax, [xsi].pResources
  mov edi, [xax].$Obj(EditorResources).dLineHeight
  mov dLineHeight, edi
  add edi, [xsi].TextRect.top
  ;Get the number of digits of first visible line number
  xor ecx, ecx
  mov eax, [xsi].FirstVisChar.dLineIndex
  sub eax, [xsi].sdLineNumberOffset
  .if SIGN?
    neg eax
    inc ecx                                           ;Add space for a sign character
  .endif
  .while eax != 0
    cdiv 10                                           ;Quotient in edx
    inc ecx
    mov eax, edx
  .endw
  mov dLineNumWidth, ecx

  ;Get the number of digits of last visible line number (ebx)
  mrm dLastVisLineIndex, [xsi].FirstVisChar.dLineIndex, ebx
  .while TRUE
    inc ebx
    mov xcx, [xsi].pEditor
    .if ebx == [xcx].$Obj(Editor).Lines.dCount
      mov ebx, dLastVisLineIndex
      .break
    .endif
    .break .if ebx >= [xcx].$Obj(Editor).Lines.dCount
    OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, ebx
    .ifBitClr [xax].$Obj(EditorLine).dFlags, ELF_HIDDEN
      add edi, dLineHeight
      .break .if edi >= [xsi].TextRect.bottom
    .endif
  .endw

  xor ecx, ecx
  mov eax, ebx
  sub eax, [xsi].sdLineNumberOffset
  .if SIGN?
    neg eax
    inc ecx                                           ;Add space for a sign character
  .endif
  .while eax != 0
    cdiv 10                                           ;Quotient in edx
    inc ecx
    mov eax, edx
  .endw
  .if ecx < dLineNumWidth
    mov ecx, dLineNumWidth
  .endif

  inc ecx                                             ;Add left side spacing = 1 char
  mov xdi, [xsi].pResources
  ;Get the width in pixels
  mov eax, [xdi].$Obj(EditorResources).SelBarTextRegular.FontMetric.x
  mul ecx
  ;Add dLineFoldingWidth and dLineIndicatorWidth
  add eax, [xdi].$Obj(EditorResources).dLineFoldingWidth
  add eax, [xdi].$Obj(EditorResources).dLineIndicatorWidth
  ;Set min width
  .if eax < [xdi].$Obj(EditorResources).dSelBarWidthMin
    mov eax, [xdi].$Obj(EditorResources).dSelBarWidthMin
  .endif
  mov [xsi].dSelBarWidth, eax                           ;Store result

  mov [xsi].SelBarRect.right, eax
  mov [xsi].TextRect.left, eax

  .if SDWORD ptr ClientRect.right > 0 && SDWORD ptr ClientRect.bottom > 0
    ;Create a new bitmap for EditorLines
    invoke CreateCompatibleBitmap, [xsi].hViewDC, ClientRect.right, ClientRect.bottom
    mov [xsi].hViewBmp, xax
    invoke SelectObject, [xsi].hViewDC, xax             ;Use it in the memory DC
    invoke DeleteObject, xax                            ;Discard the old bitmap

    ;Calc the max caret indices
    xor edx, edx
    mov eax, [xsi].TextRect.right
    sub eax, [xsi].TextRect.left
    div [xdi].$Obj(EditorResources).EditorTextRegular.FontMetric.x  ;eax = max horizontal index
    mov [xsi].dCharMaxFullVis, eax
    .if edx != 0
      inc eax
    .endif
    mov [xsi].dCharMaxPartVis, eax

    xor edx, edx
    mov eax, [xsi].TextRect.bottom
    sub eax, [xsi].TextRect.top
    div [xdi].$Obj(EditorResources).dLineHeight
    mov [xsi].dLineMaxFullVis, eax
    .if edx != 0
      inc eax
    .endif
    mov [xsi].dLineMaxPartVis, eax
  .else
    mov [xsi].dCharMaxFullVis, 0
    mov [xsi].dLineMaxFullVis, 0
    mov [xsi].dCharMaxPartVis, 0
    mov [xsi].dLineMaxPartVis, 0
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.Startup
; Purpose:    Register the EditorView object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_DBLCLKS
  m2m WC.lpfnWndProc, $MethodAddr(EditorView.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, edx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  m2m WC.lpszClassName, offset szEditorViewClassName, xdx
  m2z WC.hIcon
  m2z WC.hCursor
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.VertIndex2EditorLine
; Purpose:    Get the EditorLine object from vertical index.
; Arguments:  Arg1: Vertical index.
; Return:     xax -> EditorLine or NULL if failed.
;             xcx -> Last valid EditorLine.
;             edx = Last valid EditorLineIndex.

Method EditorView.VertIndex2EditorLine, uses xbx xdi xsi, dVertIndex:DWORD
  local dLastIndex:DWORD, pLastEditorLine:$ObjPtr(EditorLine)

  SetObject xsi
  mov edi, [xsi].FirstVisChar.dLineIndex
  mov xbx, [xsi].pEditor
  OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi
  cmp dVertIndex, 0
  .while TRUE
    mov pLastEditorLine, xax                            ;Save last visible EditorLine
    mov dLastIndex, edi                                 ;Save last visible EditorLine index
    .break .if ZERO?
    MoveToNextVisEditorLine xbx, edi                    ;On exit, edi containes the new index
    .break .if xax == NULL
    dec dVertIndex
  .endw
  mov xcx, pLastEditorLine
  mov edx, dLastIndex
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.UpdateStatusPanel
; Purpose:    Update the status panel reflecting the most recent changes.
; Arguments:  None.
; Return:     Nothing.

Method EditorView.UpdateStatusPanel, uses xsi
  SetOwner xsi, EditorDisplay
  OCall xsi.DrawStatusPanel
  invoke RedrawWindow, [xsi].hWnd, addr [xsi].StatusPanelRect, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method EditorView.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
    ANNOTATION use:wParam

;  DbgMessage uMsg, "EditorView.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mrm [xsi].$Obj(Window).hWnd, pSelf, xcx             ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax                                       ;  it returns NULL
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd
