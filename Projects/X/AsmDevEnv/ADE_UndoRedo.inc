; ==================================================================================================
; Title:      ADE_UndoRedo.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; Application implementation
; ==================================================================================================

AAT_DELETECHARS     equ   0
AAT_DELETELINE      equ   1
AAT_INSERTCHARS     equ   2
AAT_INSERTLINE      equ   3

ACTION struct
  dAction     DWORD           ?
  pEditorLine $ObjPtr(EditorLine) ?
  dPosIndex   DWORD           ?
  dChrCount   DWORD           ?
  pChars      PSTRING         ?
ACTION ends
PACTION typedef ptr ACTION

;; --------------------------------------------------------------------------------------------------
;; Method:     Application.Undo
;; Purpose:    Perform an Undo operation.
;; Arguments:  Arg1: .
;; Return:     Nothing.
;
;Method Application.Undo, uses xbx xdi xsi, dLangID:DWORD
;MethodEnd
;
