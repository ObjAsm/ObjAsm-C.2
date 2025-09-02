; ==================================================================================================
; Title:      ADE_KeywordGroupCollection.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm KeywordCollection object implementation.
; ==================================================================================================


; ==================================================================================================
; KeywordGroupCollection implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     KeywordGroupCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  -> Item.
; Return:     Nothing.

Method KeywordGroupCollection.DestroyItem, uses xdi, pItem:PKEYWORDGROUP
  mov xdi, pItem
  .if xdi != NULL
    invoke DeleteDrawAttrResources, xdi
    invoke StrDispose, [xdi].KEYWORDGROUP.pDescription  ;Dispose description string
    invoke StrDispose, [xdi].KEYWORDGROUP.pKeyWords     ;Dispose keyword list
    MemFree xdi                                         ;Free data
  .endif
MethodEnd

