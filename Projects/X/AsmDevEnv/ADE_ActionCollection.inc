; ==================================================================================================
; Title:      ADE_ActionCollection.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm ActionCollection object implementation.
; ==================================================================================================


; ==================================================================================================
; ActionCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ActionCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  -> Item (ACTION).
; Return:     Nothing.

Method ActionCollection.DestroyItem, uses xdi xsi, pItem:PACTION
  SetObject xsi
  mov xdi, pItem
  .if xdi != NULL
    .if [xdi].ACTION.dAction == AAT_DELETELINE
      ;Check first if the ACTION was undone. That means the the EditorLine was in control
      ;of the editor and has not to be disposed here.
      OCall xsi.IndexOf, pItem
      .if eax < [xsi].dActionIndex
        Destroy [xdi].ACTION.pEditorLine::EditorLine.Done
      .endif
    .endif
    .if [xdi].ACTION.dAction == AAT_DELETECHARS || [xdi].ACTION.dAction == AAT_INSERTCHARS 
      invoke StrDispose, [xdi].ACTION.pChars
    .endif
    MemFree xdi                                         ;Free data
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ActionCollection.GetUndoAction
; Purpose:    Get the last undo ACTION.
; Arguments:  Arg1: ActionGroup.
; Return:     xax -> ACTION or NULL if failed.

Method ActionCollection.GetUndoAction, uses xsi, dActionGroup:DWORD
  SetObject xsi
  mov eax, [xsi].dActionIndex
  .if eax != 0
    dec eax
    OCall xsi.ItemAt, eax
    mov ecx, dActionGroup 
    .if ecx == 0
      dec [xsi].dActionIndex
    .else
      .if [xax].ACTION.dGroup == ecx
        dec [xsi].dActionIndex
      .else
        xor eax, eax
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ActionCollection.GetRedoAction
; Purpose:    Get the last redo ACTION.
; Arguments:  Arg1: ActionGroup.
; Return:     xax -> ACTION or NULL if failed.

Method ActionCollection.GetRedoAction, uses xsi, dActionGroup:DWORD
  SetObject xsi
  mov eax, [xsi].dActionIndex
  .if eax != [xsi].dCount
    OCall xsi.ItemAt, eax
    mov ecx, dActionGroup 
    .if ecx == 0
      inc [xsi].dActionIndex
    .else
      .if [xax].ACTION.dGroup == ecx
        inc [xsi].dActionIndex
      .else
        xor eax, eax
      .endif
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ActionCollection.GetNewActionGroup
; Purpose:    Get a new ActionGroup ID.
; Arguments:  None.
; Return:     eax = ActionGroup ID.

Method ActionCollection.GetNewActionGroup
  SetObject xcx
  mov eax, [xcx].dActionGroup
  inc eax
  mov [xcx].dActionGroup, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ActionCollection.Insert
; Purpose:    Insert item at the end of the collection.
; Arguments:  Arg1: -> New item. This argument should never be NULL.
; Return:     xax -> Inserted item or NULL if failed.

Method ActionCollection.Insert, uses xbx xdi xsi, pItem:PACTION

  mov xax, pItem
  DbgDec [xax].ACTION.dGroup

  SetObject xsi
  mov ebx, [xsi].dCount
  .if ebx > [xsi].dActionIndex
    ;Dispose all now invalid redo actions 
    .while TRUE
      dec ebx
      OCall xsi.DisposeAt, ebx
      .break .if ebx == [xsi].dActionIndex
    .endw
  .endif

  mov eax, [xsi].dCount
  .if eax != 0
    dec eax
    OCall xsi.ItemAt, eax
    mov xcx, pItem
    .if [xax].ACTION.dAction == AAT_INSERTCHARS && [xcx].ACTION.dAction == AAT_INSERTCHARS
      mov xdx, [xax].ACTION.pEditorLine
      .if xdx == [xcx].ACTION.pEditorLine
        mov edx, [xax].ACTION.dPosIndex
        add edx, [xax].ACTION.dChrCount
        .if edx == [xcx].ACTION.dPosIndex
          mov xbx, xax
          mov edx, [xcx].ACTION.dChrCount
          add [xbx].ACTION.dChrCount, edx
          mov xdi, $invoke(StrAlloc, [xbx].ACTION.dChrCount)
          invoke StrECopy, xdi, [xbx].ACTION.pChars
          mov xdx, pItem
          invoke StrCopy, xax, [xdx].ACTION.pChars
          invoke StrDispose, [xbx].ACTION.pChars
          mov [xbx].ACTION.pChars, xdi
          mov xdx, pItem
          invoke StrDispose, [xdx].ACTION.pChars
          MemFree pItem
          ExitMethod
        .endif
      .endif
    .endif
  .endif
  ACall xsi::DataCollection.Insert, pItem
  inc [xsi].dActionIndex
MethodEnd
