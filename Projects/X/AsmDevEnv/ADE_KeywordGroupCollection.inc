; ==================================================================================================
; Title:      ADE_KeywordGroupCollection.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm KeywordCollection object implementation.
; ==================================================================================================


; ==================================================================================================
; KeywordGroupCollection implementation
; ==================================================================================================

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     KeywordGroupCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  -> Item.
; Return:     Nothing.

Method KeywordGroupCollection.DestroyItem, uses xdi, pItem:POINTER
  mov xdi, pItem
  .if xdi != NULL
    invoke StrDispose, [xdi].KEYWORDGROUP.pDescription  ;Dispose description string
    invoke StrDispose, [xdi].KEYWORDGROUP.pKeyWords     ;Dispose keyword list 
    MemFree xdi                                         ;Free data
  .endif
MethodEnd

