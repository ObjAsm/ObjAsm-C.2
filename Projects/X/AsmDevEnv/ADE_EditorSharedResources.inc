; ==================================================================================================
; Title:      ACE_EditorSharedResources.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; EditorSharedResources implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorSharedResources.Done
; Purpose:    Finalize the EditorSharedResources object.
; Arguments:  None.
; Return:     Nothing.

Method EditorSharedResources.Done, uses xsi
  SetObject xsi

  ;Load cursors
  invoke DeleteObject, [xsi].hCursorSelect
  invoke DeleteObject, [xsi].hCursorHand

  ;Delete bitmaps
  invoke DeleteObject, [xsi].hBmpStatusIndRed
  invoke DeleteObject, [xsi].hBmpStatusIndYellow
  invoke DeleteObject, [xsi].hBmpStatusIndGreen

  ;Delete all brushes
  invoke DeleteObject, [xsi].hBrushLineIndRed
  invoke DeleteObject, [xsi].hBrushLineIndYellow
  invoke DeleteObject, [xsi].hBrushLineIndGreen

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorSharedResources.Init
; Purpose:    Initialize the EditorSharedResources object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method EditorSharedResources.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner

  ;Load cursors
  mov [xsi].hCursorArrow,   $invoke(LoadCursor, 0, IDC_ARROW)
  mov [xsi].hCursorIBeam,   $invoke(LoadCursor, 0, IDC_IBEAM)
  mov [xsi].hCursorSelect,  $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_SELECT"))
  mov [xsi].hCursorHand,    $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_HAND"))

  ;Load bitmaps
  mov [xsi].hBmpStatusIndRed,     $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_IND_RED"))
  mov [xsi].hBmpStatusIndYellow,  $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_IND_YELLOW"))
  mov [xsi].hBmpStatusIndGreen,   $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_IND_GREEN"))

  ;Create brushes
  mov [xsi].hBrushLineIndRed,   $invoke(CreateSolidBrush, $RGB(255,000,000))
  mov [xsi].hBrushLineIndYellow,$invoke(CreateSolidBrush, $RGB(255,255,000))
  mov [xsi].hBrushLineIndGreen, $invoke(CreateSolidBrush, $RGB(000,255,000))
MethodEnd
