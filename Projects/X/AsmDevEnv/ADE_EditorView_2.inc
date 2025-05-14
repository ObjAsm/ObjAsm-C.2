; ==================================================================================================
; Title:      ADE_EditorView_2.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     EditorView.MoveCaretDown
; Purpose:    Move the caret one line down.
; Arguments:  Arg1: Number of lines
; Return:     eax = TRUE if redrawing is needed, otherwise FALSE.

Method EditorView.MoveCaretDown, uses xbx xdi xsi, dLineCount:DWORD
  local dNeedRedrawing:DWORD, dLastVisLineIndex:DWORD

;  DbgText "EditorView.MoveCaretDown"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  mov dNeedRedrawing, 0
  mov edi, dLineCount
  test edi, edi
  .while !ZERO?
    mov eax, [xsi].CaretViewLineIndex
    inc eax
    .if eax >= [xsi].dLineMaxFullVis                    ;End of View
      OCall xsi.ScrollVisLineDown
      add dNeedRedrawing, eax
      add [xsi].CaretLocation.dLineIndex, eax
    .else
      MoveToNextVisEditorLine xbx, [xsi].CaretLocation.dLineIndex, dLastVisLineIndex
      .if xax != NULL
        inc [xsi].CaretViewLineIndex
      .else
        m2m [xsi].CaretLocation.dLineIndex, dLastVisLineIndex, eax
      .endif
    .endif
    dec edi
  .endw
  OCall xsi.CaretAdjustHorz, [xsi].CaretLocation.dLineIndex
  OCall xsi.CaretSet
  mov eax, dNeedRedrawing
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.MoveCaretUp
; Purpose:    Move the caret one line up.
; Arguments:  Arg1: Number of lines
; Return:     eax = TRUE if redrawing is needed, otherwise FALSE.
; Note:       The first line is always visible.

Method EditorView.MoveCaretUp, uses xbx xdi xsi, dLineCount:DWORD
  local dNeedRedrawing:DWORD, dLastVisLineIndex:DWORD

;  DbgText "EditorView.MoveCaretUp"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor
  mov dNeedRedrawing, 0
  mov edi, dLineCount
  test edi, edi
  .while !ZERO?
    .if [xsi].CaretViewLineIndex == 0                 ;Top off view
      OCall xsi.ScrollVisLineUp
      add dNeedRedrawing, eax
      sub [xsi].CaretLocation.dLineIndex, eax
    .else
      MoveToPrevVisEditorLine xbx, [xsi].CaretLocation.dLineIndex, dLastVisLineIndex
      .if xax != NULL
        dec [xsi].CaretViewLineIndex
      .else
        m2m [xsi].CaretLocation.dLineIndex, dLastVisLineIndex, eax
      .endif
    .endif
    dec edi
  .endw
  OCall xsi.CaretAdjustHorz, [xsi].CaretLocation.dLineIndex
  OCall xsi.CaretSet
  mov eax, dNeedRedrawing
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnChar
; Purpose:    Event procedure for WM_CHAR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnChar, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dNeedRedrawing:DWORD, RefLoc:LOCATION, dActionGroup:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnChar"
  SetObject xsi
  mov xbx, [xsi].pEditor                                ;xbx -> Editor

  mov dNeedRedrawing, 0
  .if wParam >= ' '                                     ;Ignore control characters
    mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
    OCall xbx::Editor.CreateSelAction, dActionGroup

    .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
        [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
      OCall xsi.CaretLocationSave, addr RefLoc, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
      OCall xbx::Editor.SelectionDelete, dActionGroup   ;Do deletion
      OCall xsi.CaretLocationLoad, addr RefLoc          ;Restore caret info
      OCall xsi.CaretShow                               ;Show again after a selection
    .endif
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
    .if xax != NULL
      mov xdi, xax
      mov edx, [xsi].CaretLocation.dCharIndex
      .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_OVERWRITE_MODE
        OCall xdi::EditorLine.CharInsert, edx, 1, addr wParam, [xsi].CaretLocation.dLineIndex, dActionGroup
      .else
        .if [xdi].$Obj(EditorLine).dLength == edx
          OCall xdi::EditorLine.CharInsert, edx, 1, addr wParam, [xsi].CaretLocation.dLineIndex, dActionGroup
        .else
          OCall xdi::EditorLine.CharReplace, edx, 1, addr wParam, [xsi].CaretLocation.dLineIndex, dActionGroup
        .endif
      .endif
      .if eax != 0
        inc [xsi].CaretLocation.dCharIndex
        OCall xsi.CaretSet
        OCall xsi.ScrollCaretInViewRight
        OCall xsi.SelectBeginAtCaretLocation
        inc dNeedRedrawing
      .endif
    .endif

    OCall xbx::Editor.ManageEditCmds
    .if dNeedRedrawing != 0
      mov xax, [xsi].pOwner
      invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorView.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

CreateExceptionHandler EditorView_OnKeyDown

Method EditorView.OnKeyDown, SEH_FRAME uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dMenuKeyPressed:DWORD, dShiftKeyPressed:DWORD, dControlKeyPressed:DWORD
  local dLength:DWORD, dMaxIndex:DWORD, RefLoc:LOCATION, dActionGroup:DWORD
  local dNeedRedrawing:DWORD, dReturnValue:DWORD, dPrevLineIndex:DWORD, dCurrLineIndex:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnKeyDown"
;  .try EditorView_OnKeyDown
  SetObject xsi
  mov xbx, [xsi].pEditor

  mov dMenuKeyPressed, 0
  mov dShiftKeyPressed, 0
  mov dControlKeyPressed, 0
  mov dNeedRedrawing, 0
  mov dReturnValue, 0

  ;Get status of modifier keys
  invoke GetKeyState, VK_MENU
  .ifBitSet eax, BIT07
    mov dMenuKeyPressed, TRUE
  .endif
  invoke GetKeyState, VK_CONTROL
  .ifBitSet eax, BIT07
    mov dControlKeyPressed, TRUE
  .endif
  invoke GetKeyState, VK_SHIFT
  .ifBitSet eax, BIT07
    mov dShiftKeyPressed, TRUE
  .endif

  .if wParam == VK_SCROLL ;<SCROLL LOCK>
    ;Do something special

  .elseif dControlKeyPressed != FALSE && wParam == 'C'
    OCall xsi.ClpBrdCopy

  .elseif dControlKeyPressed != FALSE && wParam == 'X'
    OCall xsi.CaretLocationSave, addr RefLoc, NULL       ;Calculate a caret reference position before deletion
    OCall xsi.ClpBrdCut
    .if eax != FALSE
      OCall xsi.CaretLocationLoad, addr RefLoc          ;Restore caret info
      inc dNeedRedrawing
      OCall xsi.CaretSet
    .endif

  .elseif dControlKeyPressed != FALSE && wParam == 'V'
    OCall xsi.CaretLocationSave, addr RefLoc, NULL       ;Calculate a caret reference position before deletion
    OCall xsi.ClpBrdPaste
    .if eax != FALSE
;      OCall xsi.CaretLocationLoad, addr RefLoc          ;Restore caret info
      inc dNeedRedrawing
      OCall xsi.CaretSet
    .endif

  .elseif dControlKeyPressed != FALSE && wParam == 'U'
;    OCall [xax].ACTION.pEditorLine::EditorLine.Undo, xax
    inc dNeedRedrawing

  .elseif wParam == VK_INSERT
    BitToggle [xbx].$Obj(Editor).dFlags, EDF_OVERWRITE_MODE
    OCall xsi.CaretDestroy
    OCall xsi.CaretNew
    OCall xsi.CaretSet
    OCall xsi.CaretShow
    OCall xsi.UpdateStatusPanel
    xor eax, eax
    jmp @@EOM

  .elseif wParam == VK_ESCAPE
    OCall xbx::Editor.SelectionResetAll
    add dNeedRedrawing, eax
    OCall xsi.CaretShow

  .elseif wParam == VK_UP
    OCall xsi.MoveCaretUp, 1
    mov dNeedRedrawing, eax

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
      OCall xsi.CaretShow
    .endif

  .elseif wParam == VK_DOWN
    OCall xsi.MoveCaretDown, 1
    mov dNeedRedrawing, eax

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
      OCall xsi.CaretShow
    .endif

  .elseif wParam == VK_LEFT
    .if dControlKeyPressed == FALSE
      ;<LEFT>
      .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
        .if [xsi].CaretLocation.dCharIndex != 0
          mov [xsi].dLockedCharIndex, -1
          dec [xsi].CaretLocation.dCharIndex
          OCall xsi.ScrollCaretInViewLeft
          add dNeedRedrawing, eax
          OCall xsi.CaretSet
          OCall xsi.CaretShow
        .else
          m2m dCurrLineIndex, [xsi].CaretLocation.dLineIndex, eax
          MoveToPrevVisEditorLine xbx, dCurrLineIndex
          .if xax != NULL
            mov xdi, xax
            OCall xsi.MoveCaretUp, 1
            add dNeedRedrawing, eax
            mov [xsi].dLockedCharIndex, -1
            m2m [xsi].CaretLocation.dCharIndex, [xdi].$Obj(EditorLine).dLength, edx
            OCall xsi.ScrollCaretInViewRight
            add dNeedRedrawing, eax
            OCall xsi.CaretSet
          .endif
        .endif
      .else
        .if [xsi].CaretLocation.dCharIndex != 0
          mov [xsi].dLockedCharIndex, -1
          dec [xsi].CaretLocation.dCharIndex
          OCall xsi.ScrollCaretInViewLeft
          add dNeedRedrawing, eax
          OCall xsi.CaretSet
        .endif
      .endif

      .if dShiftKeyPressed != FALSE
        OCall xsi.SelectUpToCaretLocation
        inc dNeedRedrawing
        OCall xsi.CaretSet
      .else
        OCall xsi.SelectBeginAtCaretLocation
        inc dNeedRedrawing
      .endif
    .else
      ;<CONTROL><LEFT>
      ;Jump to the end of the current word
      OCall xsi.CaretMoveWordBeg

      .if dShiftKeyPressed != FALSE
        OCall xsi.SelectUpToCaretLocation
        inc dNeedRedrawing
        OCall xsi.CaretSet
      .else
        OCall xsi.SelectBeginAtCaretLocation
        inc dNeedRedrawing
      .endif
    .endif

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_RIGHT
    .if dControlKeyPressed == FALSE
      ;<RIGHT>
      .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
        ;Regular mode (INS/OVR)
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
        .if xax != NULL
          mov ecx, [xax].$Obj(EditorLine).dLength
          .if [xsi].CaretLocation.LOCATION.dCharIndex < ecx
            mov [xsi].dLockedCharIndex, -1
            inc [xsi].CaretLocation.LOCATION.dCharIndex
            OCall xsi.ScrollCaretInViewRight
            add dNeedRedrawing, eax
            OCall xsi.CaretSet
            OCall xsi.CaretShow
          .else
            mov edx, [xbx].$Obj(Editor).Lines.dCount
            dec edx
            .if edx != [xsi].CaretLocation.dLineIndex
              OCall xsi.MoveCaretDown, 1
              add dNeedRedrawing, eax
              mov [xsi].dLockedCharIndex, -1
              mov [xsi].CaretLocation.dCharIndex, 0
              OCall xsi.ScrollCaretInViewLeft
              add dNeedRedrawing, eax
              OCall xsi.CaretSet
            .endif
          .endif
        .endif
      .else
        mov [xsi].dLockedCharIndex, -1
        inc [xsi].CaretLocation.dCharIndex
        OCall xsi.ScrollCaretInViewRight
        add dNeedRedrawing, eax
        OCall xsi.CaretSet
      .endif

      .if dShiftKeyPressed != FALSE
        OCall xsi.SelectUpToCaretLocation
        inc dNeedRedrawing
        OCall xsi.CaretSet
      .else
        OCall xsi.SelectBeginAtCaretLocation
        inc dNeedRedrawing
      .endif
    .else
      ;<CONTROL><RIGHT>
      OCall xsi.CaretMoveWordEnd

      .if dShiftKeyPressed != FALSE
        OCall xsi.SelectUpToCaretLocation
        inc dNeedRedrawing
        OCall xsi.CaretSet
      .else
        OCall xsi.SelectBeginAtCaretLocation
        inc dNeedRedrawing
      .endif
    .endif

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_NEXT
    mov xax, [xsi].pOwner
    OCall xsi.MoveCaretDown, [xax].$Obj(EditorDisplay).ScrollPage.y
    add dNeedRedrawing, eax

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_PRIOR
    mov xax, [xsi].pOwner
    OCall xsi.MoveCaretUp, [xax].$Obj(EditorDisplay).ScrollPage.y
    add dNeedRedrawing, eax

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_HOME
    .if dControlKeyPressed != FALSE
      OCall xsi.ScrollVisPageUp, -1                     ;Use saturation
      OCall xsi.ScrollPageLeft, -1                      ;Use saturation
      mov [xsi].CaretLocation.dCharIndex, 0
      mov [xsi].CaretLocation.dLineIndex, 0
      mov [xsi].CaretViewLineIndex, 0
      OCall xsi.CaretSet
      inc dNeedRedrawing
    .else
      OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
      .if xax != NULL
        ;Search the first non blank char from index 0 up to the current caret index
        ;Set loop limits
        mov xcx, [xax].$Obj(EditorLine).pBuffer
        m2m dLength, [xax].$Obj(EditorLine).dLength, edx
        mov edi, [xsi].CaretLocation.dCharIndex
        .if edi != 0
          mov dMaxIndex, edi
          ;Start looping
          xor edi, edi
          xor ebx, ebx                                  ;Search index = 0
          .while ebx < dLength && ebx < dMaxIndex
            movzx eax, CHR ptr [xcx + sizeof(CHR)*xbx]
            GetCharType eax, edx
            .ifBitSet edx, CHR_BLANK
              inc ebx
            .else
              mov edi, ebx
              .break
            .endif
          .endw
        .endif

        .if edi < [xsi].FirstVisChar.dCharIndex
          mov [xsi].FirstVisChar.dCharIndex, 0          ;Adjust FirstVisChar.dCharIndex
          inc dNeedRedrawing
        .endif
        mov [xsi].CaretLocation.dCharIndex, edi
      .endif
      OCall xsi.CaretSet
      OCall xsi.ScrollCaretInViewLeft

      .if dShiftKeyPressed != FALSE
        OCall xsi.SelectUpToCaretLocation
        inc dNeedRedrawing
      .else
        mov xcx, [xsi].pOwner
        OCall [xcx].$Obj(EditorDisplay).pOwner::Editor.SelectionResetAll
        add dNeedRedrawing, eax
        OCall xsi.SelectBeginAtCaretLocation
      .endif
    .endif

  .elseif wParam == VK_END
    .if dControlKeyPressed != FALSE
      OCall xsi.ScrollVisPageDown, -1                   ;Use saturation
      OCall xsi.ScrollPageLeft, -1                      ;Use saturation
      mov edx, [xbx].$Obj(Editor).Lines.dCount
      dec edx
      mov [xsi].CaretLocation.dLineIndex, edx
      OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
      .if xax != NULL
        m2m [xsi].CaretLocation.dCharIndex, [xax].$Obj(EditorLine).dLength, ecx
        mov [xsi].CaretViewLineIndex, 0
        OCall xsi.CaretSet
      .endif
      inc dNeedRedrawing
    .else
      ;Search the last char in line
      OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
      .if xax != NULL
        m2m [xsi].CaretLocation.dCharIndex, [xax].$Obj(EditorLine).dLength, edx
        OCall xsi.ScrollCaretInViewRight
        inc dNeedRedrawing
      .endif
      OCall xsi.CaretSet
      OCall xsi.ScrollCaretInViewRight
    .endif

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_DELETE
    mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
    OCall xbx::Editor.CreateSelAction, dActionGroup

    ;Check Selection
    mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    mov xdx, [xbx].$Obj(Editor).SelectionRange.pEndSelInfo
    .if xcx == NULL || xdx == NULL
      ;Nothing selected => delete char at caret position
      ;Check if caret is at the line end => join lines
      OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
      .if xax != NULL
        mov ecx, [xsi].CaretLocation.dCharIndex
        .if ecx == [xax].$Obj(EditorLine).dLength
          OCall xax::EditorLine.LineJoinNext, [xsi].CaretLocation.dLineIndex, dActionGroup
        .else
          mov edx, [xsi].CaretLocation.dLineIndex
          mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, ecx
          mov [xbx].$Obj(Editor).SelectionFst.dLineIndex, edx
          inc ecx
          mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, ecx
          mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, edx
          OCall xbx::Editor.SelectionSet
        .endif
      .endif
    .endif
    .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
        [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
      OCall xsi.CaretLocationSave, addr RefLoc, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
      OCall xbx::Editor.SelectionDelete, dActionGroup   ;Do deletion
      OCall xsi.CaretLocationLoad, addr RefLoc          ;Restore caret info
      OCall xsi.CaretShow                               ;Show again after a selection
    .endif

    OCall xsi.CaretSet                                  ;Set caret
    OCall xsi.SelectBeginAtCaretLocation                ;Set selection begin
    OCall xbx::Editor.ManageEditCmds
    inc dNeedRedrawing

  .elseif wParam == VK_BACK
    mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
    OCall xbx::Editor.CreateSelAction, dActionGroup

    ;Check Selection
    mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    mov xdx, [xbx].$Obj(Editor).SelectionRange.pEndSelInfo
    .if xcx == NULL || xdx == NULL
      ;Nothing selected => delete char before caret position
      ;Check if caret is at the line begin => join lines
      .if [xsi].CaretLocation.dCharIndex == 0
        m2m dPrevLineIndex, [xsi].CaretLocation.dLineIndex, eax
        MoveToPrevEditorLine xbx, [xsi].CaretLocation.dLineIndex  ;CaretLocation.dLineIndex is updated
        .if xax == NULL
          m2m [xsi].CaretLocation.dLineIndex, dPrevLineIndex, eax
        .else
          mov edi, [xax].$Obj(EditorLine).dLength
          ;Join the 2 lines
          OCall xax::EditorLine.LineJoinNext, [xsi].CaretLocation.dLineIndex, dActionGroup

          ;Move caret
          mov [xsi].CaretLocation.dCharIndex, edi
          dec [xsi].CaretViewLineIndex
        .endif
      .else
        mov edx, [xsi].CaretLocation.dLineIndex
        mov ecx, [xsi].CaretLocation.dCharIndex
        mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, ecx
        mov [xbx].$Obj(Editor).SelectionFst.dLineIndex, edx
        dec ecx
        mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, ecx
        mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, edx

        ;Do deletion
        OCall xbx::Editor.SelectionSet
        OCall xbx::Editor.SelectionDelete, dActionGroup ;Do deletion
        OCall xsi.CaretShow                             ;Show again after a selection

        ;Move caret
        dec [xsi].CaretLocation.dCharIndex
      .endif
    .else
      .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
          [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
        OCall xsi.CaretLocationSave, addr RefLoc, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
        OCall xbx::Editor.SelectionDelete, dActionGroup ;Do deletion
        OCall xsi.CaretLocationLoad, addr RefLoc        ;Restore caret info
        OCall xsi.CaretShow                             ;Show again after a selection
      .endif
    .endif

    OCall xsi.CaretSet                                  ;Set caret
    OCall xsi.SelectBeginAtCaretLocation                ;Set selection begin
    OCall xbx::Editor.ManageEditCmds
    inc dNeedRedrawing

  .elseif wParam == VK_TAB
;    .ifBitSet [???].$Obj(EditorResources).dFlags, ERF_TAB_TO_SPACE

    mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
    OCall xbx::Editor.CreateSelAction, dActionGroup
    .if [xbx].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \
        [xbx].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
      OCall xsi.CaretLocationSave, addr RefLoc, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
      OCall xbx::Editor.SelectionDelete, dActionGroup   ;Do deletion
      OCall xsi.CaretLocationLoad, addr RefLoc          ;Restore caret info
      OCall xsi.CaretShow                               ;Show again after a selection
    .endif
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
    .if xax != NULL
      mov edx, [xsi].CaretLocation.dCharIndex
      .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_OVERWRITE_MODE
        OCall xax::EditorLine.CharInsert, edx, 2, $OfsCStr("  "), [xsi].CaretLocation.dLineIndex, dActionGroup
      .else
        .if [xax].$Obj(EditorLine).dLength == edx
          OCall xax::EditorLine.CharInsert, edx, 2, $OfsCStr("  "), [xsi].CaretLocation.dLineIndex, dActionGroup
        .else
          OCall xax::EditorLine.CharReplace, edx, 2, $OfsCStr("  "), [xsi].CaretLocation.dLineIndex, dActionGroup
        .endif
      .endif
      .if eax != 0
        add [xsi].CaretLocation.dCharIndex, 2
        OCall xsi.CaretSet
        OCall xsi.ScrollCaretInViewRight
        OCall xsi.SelectBeginAtCaretLocation
        OCall xbx::Editor.ManageEditCmds
        inc dNeedRedrawing
      .endif
    .endif

  .elseif wParam == VK_RETURN
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, [xsi].CaretLocation.dLineIndex
    .if xax != NULL
      mov xdi, xax
      mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
      OCall xbx::Editor.CreateSelAction, dActionGroup
      OCall xdi::EditorLine.LineBreak, [xsi].CaretLocation.dCharIndex, [xsi].CaretLocation.dLineIndex, dActionGroup
      .if xax != NULL
        mov [xsi].CaretLocation.dCharIndex, 0
        inc [xsi].CaretLocation.dLineIndex
        inc [xsi].CaretViewLineIndex
        OCall xsi.CaretSet
        OCall xbx::Editor.ManageEditCmds
        inc dNeedRedrawing
      .endif
    .endif

  .elseif wParam == 'B' && dControlKeyPressed != FALSE
    ;Toggle Block Mode
;    OCall xsi.CaretHide
    OCall xbx::Editor.SelectionResetAll
    BitToggle [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
    .ifBitClr [xbx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
      OCall xsi.CaretAdjustHorz, [xsi].CaretLocation.dLineIndex
      mov [xsi].CaretLocation.dCharIndex, eax                               ;Caret is still hidden
    .endif
    OCall xsi.UpdateStatusPanel
    inc dNeedRedrawing

  .endif

  .if dNeedRedrawing != 0
    mov xax, [xsi].pOwner
    invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif
  mov eax, dReturnValue

;  .catch EditorView_OnKeyDown
;    DbgWarning "Exception in EditorView.OnChar"
;    invoke MessageBox, [xsi].hWnd, $OfsCStr("Exception in EditorView.OnChar"), addr cError, MB_OK or MB_ICONERROR
;  .endcatch EditorView_OnKeyDown
;if TARGET_BITNESS eq 64
;  .finally EditorView_OnKeyDown
;  .endfinally
;endif
MethodEnd

