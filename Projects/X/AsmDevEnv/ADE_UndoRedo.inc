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
AAT_DELETENEXTLINE  equ   1
AAT_INSERTCHARS     equ   2
AAT_INSERTNEXTLINE  equ   3

SEQUENCE struct
  dSequenceID   DWORD           ?
  SequenceLink  LDLL_MEMBER     {}
  pEditor       $ObjPtr(Editor) ?
  pEditorLine   $ObjPtr(EditorLine) ?
SEQUENCE ends
PSEQUENCE typedef ptr SEQUENCE

ACTION struct
  ActionLink    LDLL_MEMBER     {}
  dAction       DWORD           ?
  union
    struct
      dBegin    DWORD           ?
      dCount    DWORD           ?
      pChars    PSTRING         ?
    ends
    struct
      pLineBefore $ObjPtr(EditorLine) ?
      pLineAfter  $ObjPtr(EditorLine) ?
    ends
  ends
ACTION ends
PACTION typedef ptr ACTION


;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:     Application.Undo
;; Purpose:    Perform an Undo operation.
;; Arguments:  Arg1: .
;; Return:     Nothing.
;
;Method Application.Undo, uses xbx xdi xsi, dLangID:DWORD
;MethodEnd
;
