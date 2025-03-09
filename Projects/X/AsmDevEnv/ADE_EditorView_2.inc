; ==================================================================================================
; Title:      ADE_EditorView_2.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorView.MoveCaretDown
; Purpose:    Move the caret one line down.
; Arguments:  Arg1: Number of lines
; Return:     eax = TRUE if redrawing is needed, otherwise FALSE.

Method EditorView.MoveCaretDown, uses xbx xdi xsi, dLineCount:DWORD
  local dNeedRedrawing:DWORD

;  DbgText "EditorView.MoveCaretDown"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov edi, dLineCount
  test edi, edi
  .while !ZERO?
    mov xcx, [xsi].pOwner
    mov xbx, [xcx].$Obj(EditorDisplay).pOwner           ;xbx -> Editor
    mov xax, [xbx].$Obj(Editor).TextLines.pLastMember
    sub xax, offset $Obj(EditorTextLine).Link
    .if xax != [xsi].CaretLocation.pTextLine            ;End of file?
      inc [xsi].sdCaretVisLineOffset
    .else
      cmp [xsi].sdCaretVisLineOffset, 0
    .endif
  
    .if SIGN?                                           ;Top off view
      mov edx, [xsi].sdCaretVisLineOffset
      neg edx
      OCall xsi.ScrollVisPageUp, edx
      add dNeedRedrawing, eax
      mov [xsi].sdCaretVisLineOffset, 0
      mov xax, [xsi].p1stVisLine
      mov ecx, [xsi].d1stVisLineNum
    .else
      mov edx, [xsi].sdCaretVisLineOffset
      sub edx, [xsi].dLineMaxFullVis
      .if SDWORD ptr edx >= 0                           ;Bottom off view
        inc edx
        OCall xsi.ScrollVisPageDown, edx
        add dNeedRedrawing, eax
        mov xax, [xsi].p1stVisLine
        mov edx, [xsi].sdCaretVisLineOffset
        dec edx
      .else                                             ;In view
        mov edx, [xsi].sdCaretVisLineOffset
        mov xax, [xsi].p1stVisLine
      .endif
      GotoNextVisTextLine xax, edx, ecx, ebx
      mov [xsi].sdCaretVisLineOffset, ebx
      add ecx, [xsi].d1stVisLineNum
    .endif
    mov [xsi].CaretLocation.dLineNumber, ecx
    mov [xsi].CaretLocation.pTextLine, xax
    dec edi
  .endw
  OCall xsi.CaretAdjustHorz, xax
  OCall xsi.CaretSet
  mov eax, dNeedRedrawing
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorView.MoveCaretUp
; Purpose:    Move the caret one line up.
; Arguments:  Arg1: Number of lines
; Return:     eax = TRUE if redrawing is needed, otherwise FALSE.

Method EditorView.MoveCaretUp, uses xbx xdi xsi, dLineCount:DWORD
  local dNeedRedrawing:DWORD

;  DbgText "EditorView.MoveCaretUp"
  SetObject xsi
  mov dNeedRedrawing, 0
  mov edi, dLineCount
  test edi, edi
  .while !ZERO?
    mov xcx, [xsi].pOwner
    mov xbx, [xcx].$Obj(EditorDisplay).pOwner           ;xbx -> Editor
    mov xax, [xbx].$Obj(Editor).TextLines.pFirstMember
    sub xax, offset $Obj(EditorTextLine).Link
    .if xax != [xsi].CaretLocation.pTextLine            ;Begin of file?
      dec [xsi].sdCaretVisLineOffset
    .else
      cmp [xsi].sdCaretVisLineOffset, 0
    .endif
  
    .if SIGN?                                           ;Top off view
      mov edx, [xsi].sdCaretVisLineOffset
      neg edx
      OCall xsi.ScrollVisPageUp, edx
      add dNeedRedrawing, eax
      mov [xsi].sdCaretVisLineOffset, 0
      mov xax, [xsi].p1stVisLine
      mov ecx, [xsi].d1stVisLineNum
    .else
      mov edx, [xsi].sdCaretVisLineOffset
      sub edx, [xsi].dLineMaxFullVis
      .if SDWORD ptr edx > 0                            ;Bottom off view
        inc edx
        OCall xsi.ScrollVisPageDown, edx
        add dNeedRedrawing, eax
        mov xax, [xsi].p1stVisLine
        mov edx, [xsi].dLineMaxFullVis
        dec edx
      .else                                             ;In view
        mov edx, [xsi].sdCaretVisLineOffset
        mov xax, [xsi].p1stVisLine
        inc dNeedRedrawing                              ;This is a patch
      .endif
      GotoNextVisTextLine xax, edx, ecx, ebx
      mov [xsi].sdCaretVisLineOffset, ebx
      add ecx, [xsi].d1stVisLineNum
    .endif
    mov [xsi].CaretLocation.dLineNumber, ecx
    mov [xsi].CaretLocation.pTextLine, xax
    dec edi
  .endw
  OCall xsi.CaretAdjustHorz, xax
  OCall xsi.CaretSet

  mov eax, dNeedRedrawing
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorView.OnChar
; Purpose:    Event procedure for WM_CHAR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorView.OnChar, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dNeedRedrawing:DWORD, RefLoc:LOCATION

  ANNOTATION use:wParam lParam
  
;  DbgText "EditorView.OnChar"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xbx, [xcx].$Obj(EditorDisplay).pOwner
;  DbgHex wParam

  mov dNeedRedrawing, 0
  .if wParam >= ' '                                     ;Ignore control characters
    OCall xsi.CaretRefLocSave, addr RefLoc              ;Calculate a caret reference position before deletion
    OCall xbx::Editor.SelectionDelete                   ;Do deletion
    OCall xsi.CaretRefLocLoad, addr RefLoc              ;Restore caret info
    mov xax, [xsi].CaretLocation.pTextLine
    .if xax != NULL
      mov edx, [xsi].CaretLocation.dCharIndex
      .ifBitClr [xbx].$Obj(Editor).dFlags, EIF_OVERWRITE_MODE
        OCall xax::EditorTextLine.CharInsert, edx, 1, addr wParam
      .else
        .if [xax].$Obj(EditorTextLine).dLength == edx
          OCall xax::EditorTextLine.CharInsert, edx, 1, addr wParam
        .else
          OCall xax::EditorTextLine.CharReplace, edx, 1, addr wParam
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
  
    .if dNeedRedrawing != 0
      mov xax, [xsi].pOwner
      invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorView.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

IncFont macro DrawAttr
  .if &DrawAttr&.DRAW_ATTR.dPointSize < 80
    invoke DeleteDrawAttrFont, addr &DrawAttr
    inc &DrawAttr&.DRAW_ATTR.dPointSize
    invoke CreateDrawAttrFont, [xsi].hTextDC, addr &DrawAttr
  .endif
endm

DecFont macro DrawAttr
  .if &DrawAttr&.DRAW_ATTR.dPointSize > 1
    invoke DeleteDrawAttrFont, addr &DrawAttr
    dec &DrawAttr&.DRAW_ATTR.dPointSize
    invoke CreateDrawAttrFont, [xsi].hTextDC, addr &DrawAttr
  .endif
endm

Method EditorView.OnKeyDown, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dMenuKeyPressed:DWORD, dShiftKeyPressed:DWORD, dControlKeyPressed:DWORD
  local dLength:DWORD, dMaxIndex:DWORD, RefLoc:LOCATION
  local dNeedRedrawing:DWORD, dReturnValue:DWORD

  ANNOTATION use:wParam lParam

;  DbgText "EditorView.OnKeyDown"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xbx, [xcx].$Obj(EditorDisplay).pOwner             ;xbx -> Editor

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
    mov xax, [xsi].pOwner
    OCall [xax].$Obj(EditorDisplay).pOwner::Editor.SelectionDelete
    .if eax != 0
      OCall xsi.CaretSet
    .endif

  .elseif dControlKeyPressed != FALSE && wParam == 'C'
    OCall xsi.ClipboardCopy

  .elseif dControlKeyPressed != FALSE && wParam == 'X'
    OCall xsi.CaretRefLocSave, addr RefLoc            ;Calculate a caret reference position before deletion
    OCall xsi.ClipboardCut
    .if eax != FALSE
      OCall xsi.CaretRefLocLoad, addr RefLoc          ;Restore caret info
      inc dNeedRedrawing
      OCall xsi.CaretSet
    .endif

  .elseif dControlKeyPressed != FALSE && wParam == 'V'
    OCall xsi.CaretRefLocSave, addr RefLoc            ;Calculate a caret reference position before deletion
    OCall xsi.ClipboardPaste
    .if eax != FALSE
      OCall xsi.CaretRefLocLoad, addr RefLoc          ;Restore caret info
      inc dNeedRedrawing
      OCall xsi.CaretSet
    .endif

  .elseif wParam == VK_INSERT
    BitToggle [xbx].$Obj(Editor).dFlags, EIF_OVERWRITE_MODE
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
    .endif

  .elseif wParam == VK_LEFT
    .if dControlKeyPressed == FALSE
      ;<LEFT>
      .ifBitClr [xbx].$Obj(Editor).dFlags, EIF_BLOCK_MODE
        .if [xsi].CaretLocation.dCharIndex != 0
          mov [xsi].dLockedVertIndex, -1
          dec [xsi].CaretLocation.dCharIndex
          OCall xsi.ScrollCaretInViewLeft
          add dNeedRedrawing, eax
          OCall xsi.CaretSet
        .else
          mov xax, [xbx].$Obj(Editor).TextLines.pFirstMember
          sub xax, offset $Obj(EditorTextLine).Link
          .if xax != [xsi].CaretLocation.pTextLine
            OCall xsi.MoveCaretUp, 1
            add dNeedRedrawing, eax
            mov [xsi].dLockedVertIndex, -1
            mov xax, [xsi].CaretLocation.pTextLine
            m2m [xsi].CaretLocation.dCharIndex, [xax].$Obj(EditorTextLine).dLength, edx
            OCall xsi.ScrollCaretInViewRight
            add dNeedRedrawing, eax
            OCall xsi.CaretSet
          .endif
        .endif
      .else
        .if [xsi].CaretLocation.dCharIndex != 0
          mov [xsi].dLockedVertIndex, -1
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
      mov xax, [xsi].CaretLocation.pTextLine
      .ifBitClr [xbx].$Obj(Editor).dFlags, EIF_BLOCK_MODE
        mov ecx, [xax].$Obj(EditorTextLine).dLength
        .if [xsi].CaretLocation.LOCATION.dCharIndex < ecx
          mov [xsi].dLockedVertIndex, -1
          inc [xsi].CaretLocation.LOCATION.dCharIndex
          OCall xsi.ScrollCaretInViewRight
          add dNeedRedrawing, eax
          OCall xsi.CaretSet
        .else
          BitSet [xax].$Obj(EditorTextLine).dFlags, TLF_EOL_MARKED   ;Mark previous line
          mov xax, [xbx].$Obj(Editor).TextLines.pLastMember
          sub xax, offset $Obj(EditorTextLine).Link
          .if xax != [xsi].CaretLocation.pTextLine
            OCall xsi.MoveCaretDown, 1
            add dNeedRedrawing, eax
            mov [xsi].dLockedVertIndex, -1
            mov [xsi].CaretLocation.dCharIndex, 0
            OCall xsi.ScrollCaretInViewLeft
            add dNeedRedrawing, eax
            OCall xsi.CaretSet
          .endif
        .endif
      .else
        mov [xsi].dLockedVertIndex, -1
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
    ;Search the first non blank char from index 0 up to the current caret index
    mov xax, [xsi].CaretLocation.pTextLine
    .if xax != NULL
      ;Set loop limits
      mov xcx, [xax].$Obj(EditorTextLine).pBuffer
      m2m dLength, [xax].$Obj(EditorTextLine).dLength, edx
      mov edi, [xsi].CaretLocation.dCharIndex
      .if edi != 0
        mov dMaxIndex, edi
        ;Start looping
        xor edi, edi
        xor ebx, ebx                                    ;Search index = 0
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

      .if edi < [xsi].d1stVisCharIndex
        mov [xsi].d1stVisCharIndex, 0                   ;Adjust d1stVisCharIndex 
        inc dNeedRedrawing
      .endif
      mov [xsi].CaretLocation.dCharIndex, edi
      OCall xsi.CaretSet
    .endif

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      mov xcx, [xsi].pOwner
      OCall [xcx].$Obj(EditorDisplay).pOwner::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_END
    ;Search the last char in line
    mov xax, [xsi].CaretLocation.pTextLine
    .if xax != NULL
      ;Is the horz index out of screen?
      mov edx, [xax].$Obj(EditorTextLine).dLength       ;Get last caret char index
      mov eax, [xsi].dCharMaxFullVis
      mov [xsi].CaretLocation.dCharIndex, edx           ;Store it
      mov ecx, edx                                      ;Calc view position
      sub ecx, [xsi].d1stVisCharIndex
      .if eax < ecx                                     ;Check if it is off view
        sub edx, eax
        mov [xsi].d1stVisCharIndex, edx                 ;Adjust d1stVisCharIndex 
        inc dNeedRedrawing
      .endif
    .endif
    OCall xsi.CaretSet

    .if dShiftKeyPressed != FALSE
      OCall xsi.SelectUpToCaretLocation
      inc dNeedRedrawing
    .else
      OCall xbx::Editor.SelectionResetAll
      add dNeedRedrawing, eax
      OCall xsi.SelectBeginAtCaretLocation
    .endif

  .elseif wParam == VK_DELETE
    ;Check Selection
    mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    mov xdx, [xbx].$Obj(Editor).SelectionRange.pEndSelInfo
    .if xcx == NULL || xdx == NULL
      ;Nothing selected => delete char at caret position
      ;Check if caret is at the line end => join lines
      mov xax, [xsi].CaretLocation.pTextLine
      mov xcx, [xax].$Obj(EditorTextLine).Link.pLinkFwrd
      .if xcx != NULL
        mov ecx, [xsi].CaretLocation.dCharIndex
        .if ecx == [xax].$Obj(EditorTextLine).dLength
          OCall xax::EditorTextLine.LineJoinNext, [xsi].CaretLocation.dLineNumber
        .else
          mov edx, [xsi].CaretLocation.dLineNumber
          mov [xbx].$Obj(Editor).SelectionFst.pTextLine, xax
          mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, ecx
          mov [xbx].$Obj(Editor).SelectionFst.dLineNumber, edx
          inc ecx
          mov [xbx].$Obj(Editor).SelectionLst.pTextLine, xax
          mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, ecx
          mov [xbx].$Obj(Editor).SelectionLst.dLineNumber, edx

          ;Do deletion; Caret does not move.
          OCall xbx::Editor.SelectionSet
          OCall xbx::Editor.SelectionDelete
        .endif
      .endif
    .else
      OCall xsi.CaretRefLocSave, addr RefLoc            ;Calculate a caret reference position before deletion
      OCall xbx::Editor.SelectionDelete                 ;Do deletion
      OCall xsi.CaretRefLocLoad, addr RefLoc            ;Restore caret info
    .endif

    OCall xsi.CaretSet                                  ;Set caret
    OCall xsi.SelectBeginAtCaretLocation                ;Set selection begin
    inc dNeedRedrawing

  .elseif wParam == VK_BACK
    ;Check Selection
    mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
    mov xdx, [xbx].$Obj(Editor).SelectionRange.pEndSelInfo
    .if xcx == NULL || xdx == NULL
      ;Nothing selected => delete char before caret position
      ;Check if caret is at the line begin => join lines
      mov xax, [xsi].CaretLocation.pTextLine
      mov ecx, [xsi].CaretLocation.dCharIndex
      .if ecx == 0
        mov xcx, [xax].$Obj(EditorTextLine).Link.pLinkBack
        .if xcx != NULL
          sub xcx, offset $Obj(EditorTextLine).Link
          mov edi, [xcx].$Obj(EditorTextLine).dLength
          ;Join the 2 lines
          OCall xax::EditorTextLine.LineJoinPrev, [xsi].CaretLocation.dLineNumber   ;Can't fail

          ;Move caret
          mov [xsi].CaretLocation.pTextLine, xcx          ;xcx retunred from LineJoinPrev
          dec [xsi].CaretLocation.dLineNumber
          mov [xsi].CaretLocation.dCharIndex, edi
          dec [xsi].sdCaretVisLineOffset
        .endif
      .else
        mov edx, [xsi].CaretLocation.dLineNumber
        mov [xbx].$Obj(Editor).SelectionFst.pTextLine, xax
        mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, ecx
        mov [xbx].$Obj(Editor).SelectionFst.dLineNumber, edx
        dec ecx
        mov [xbx].$Obj(Editor).SelectionLst.pTextLine, xax
        mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, ecx
        mov [xbx].$Obj(Editor).SelectionLst.dLineNumber, edx

        ;Do deletion
        OCall xbx::Editor.SelectionSet
        OCall xbx::Editor.SelectionDelete

        ;Move caret
        dec [xsi].CaretLocation.dCharIndex
      .endif
    .else
      OCall xsi.CaretRefLocSave, addr RefLoc            ;Calculate a caret reference position before deletion
      OCall xbx::Editor.SelectionDelete                 ;Do deletion
      OCall xsi.CaretRefLocLoad, addr RefLoc            ;Restore caret info
    .endif

    OCall xsi.CaretSet                                  ;Set caret
    OCall xsi.SelectBeginAtCaretLocation                ;Set selection begin
    inc dNeedRedrawing

  .elseif wParam == VK_TAB
;    .ifBitSet [???].$Obj(EditorResources).dFlags, ERF_TAB_TO_SPACE

    OCall xsi.CaretRefLocSave, addr RefLoc              ;Calculate a caret reference position before deletion
    OCall xbx::Editor.SelectionDelete                   ;Do deletion
    OCall xsi.CaretRefLocLoad, addr RefLoc              ;Restore caret info
    mov xax, [xsi].CaretLocation.pTextLine
    .if xax != NULL
      mov edx, [xsi].CaretLocation.dCharIndex
      .ifBitClr [xbx].$Obj(Editor).dFlags, EIF_OVERWRITE_MODE
        OCall xax::EditorTextLine.CharInsert, edx, 2, $OfsCStr("  ")
      .else
        .if [xax].$Obj(EditorTextLine).dLength == edx
          OCall xax::EditorTextLine.CharInsert, edx, 2, $OfsCStr("  ")
        .else
          OCall xax::EditorTextLine.CharReplace, edx, 2, $OfsCStr("  ")
        .endif
      .endif
      .if eax != 0
        add [xsi].CaretLocation.dCharIndex, 2
        OCall xsi.CaretSet
        OCall xsi.ScrollCaretInViewRight
        OCall xsi.SelectBeginAtCaretLocation
        inc dNeedRedrawing
      .endif
    .endif

  .elseif wParam == VK_RETURN
    mov xax, [xsi].CaretLocation.pTextLine
    .if xax != NULL
      OCall xax::EditorTextLine.LineBreak, [xsi].CaretLocation.dCharIndex, [xsi].CaretLocation.dLineNumber
      .if xax != NULL
        mov [xsi].CaretLocation.pTextLine, xax
        mov [xsi].CaretLocation.dCharIndex, 0
        inc [xsi].sdCaretVisLineOffset
        OCall xsi.CaretSet
        inc dNeedRedrawing
      .endif
    .endif

  .elseif wParam == 'A' && dControlKeyPressed != FALSE
    .ifBitClr [xbx].$Obj(Editor).dFlags, EIF_BLOCK_MODE
      mov xcx, [xbx].$Obj(Editor).TextLines.pFirstMember
      .if xcx != NULL
        lea xdx, [xcx - offset $Obj(EditorTextLine).Link]
        mov [xbx].$Obj(Editor).SelectionFst.pTextLine, xdx
        mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, 0
        mov [xbx].$Obj(Editor).SelectionFst.dLineNumber, 1

        mov xcx, [xbx].$Obj(Editor).TextLines.pLastMember
        lea xdx, [xcx - offset $Obj(EditorTextLine).Link]
        mov [xbx].$Obj(Editor).SelectionLst.pTextLine, xdx
        mov eax, [xdx].$Obj(EditorTextLine).dLength
        mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, eax
        mov [xbx].$Obj(Editor).SelectionLst.dLineNumber, 2

        OCall xbx::Editor.SelectionSet
        inc dNeedRedrawing
      .endif
    .endif

  .elseif wParam == 'B' && dControlKeyPressed != FALSE
    ;Toggle Block Mode
;    OCall xsi.CaretHide
    OCall xbx::Editor.SelectionResetAll
    BitToggle [xbx].$Obj(Editor).dFlags, EIF_BLOCK_MODE
    .ifBitClr [xbx].$Obj(Editor).dFlags, EIF_BLOCK_MODE
      OCall xsi.CaretAdjustHorz, [xsi].CaretLocation.pTextLine
      mov [xsi].CaretLocation.dCharIndex, eax                               ;Caret is still hidden
    .endif
    OCall xsi.UpdateStatusPanel
    inc dNeedRedrawing

  .elseif wParam == VK_ADD
    .if dControlKeyPressed != FALSE
      mov xdi, [xsi].pResources
      IncFont [xdi].$Obj(EditorResources).EditorTextRegular
      IncFont [xdi].$Obj(EditorResources).EditorTextSelect
      IncFont [xdi].$Obj(EditorResources).EditorTextHighlight
      IncFont [xdi].$Obj(EditorResources).EditorTextQuote
      IncFont [xdi].$Obj(EditorResources).EditorTextComment
      IncFont [xdi].$Obj(EditorResources).EditorTextNumber
      IncFont [xdi].$Obj(EditorResources).EditorTextOperator
      IncFont [xdi].$Obj(EditorResources).SelBarTextRegular
      IncFont [xdi].$Obj(EditorResources).SelBarTextSelect
      .ColForEach [xdi].$Obj(EditorResources).KeywordGroups
        lea xbx, [xax].KEYWORDGROUP
        IncFont [xbx]
      .ColNext

      mov eax, [xdi].$Obj(EditorResources).dCodeLineSpace
      add eax, [xdi].$Obj(EditorResources).EditorTextRegular.FontMetric.y
      mov [xsi].dTextLineHeight, eax
      OCall xsi.SetGuiLayout
      OCall xsi.CaretDestroy
      OCall xsi.CaretNew
      OCall xsi.CaretSet
      inc dNeedRedrawing
    .endif

  .elseif wParam == VK_SUBTRACT
    .if dControlKeyPressed != FALSE
      mov xdi, [xsi].pResources
      DecFont [xdi].$Obj(EditorResources).EditorTextRegular
      DecFont [xdi].$Obj(EditorResources).EditorTextSelect
      DecFont [xdi].$Obj(EditorResources).EditorTextHighlight
      DecFont [xdi].$Obj(EditorResources).EditorTextQuote
      DecFont [xdi].$Obj(EditorResources).EditorTextComment
      DecFont [xdi].$Obj(EditorResources).EditorTextNumber
      DecFont [xdi].$Obj(EditorResources).EditorTextOperator
      DecFont [xdi].$Obj(EditorResources).SelBarTextRegular
      DecFont [xdi].$Obj(EditorResources).SelBarTextSelect
      .ColForEach [xdi].$Obj(EditorResources).KeywordGroups
        lea xbx, [xax].KEYWORDGROUP
        DecFont [xbx]
      .ColNext

      mov eax, [xdi].$Obj(EditorResources).dCodeLineSpace
      add eax, [xdi].$Obj(EditorResources).EditorTextRegular.FontMetric.y
      mov [xsi].dTextLineHeight, eax
      OCall xsi.SetGuiLayout
      OCall xsi.CaretDestroy
      OCall xsi.CaretNew
      OCall xsi.CaretSet
      inc dNeedRedrawing
    .endif
  .endif

  .if dNeedRedrawing != 0
    mov xax, [xsi].pOwner
    invoke RedrawWindow, [xax].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif
  mov eax, dReturnValue
MethodEnd

