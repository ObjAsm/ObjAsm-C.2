; ==================================================================================================
; Title:      ADE_FileFormatCollection.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm FileFormatCollection object implementation.
; ==================================================================================================


; ==================================================================================================
; FileFormatCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    FileFormatCollection.Compare
; Purpose:   Compare the WIDE strings Key1 and Key2.
; Arguments: Arg1: -> First key.
;            Arg2: -> Second key.
; Return:    eax =   (-)  if Key1 < Key2
;                     0   if Key1 = Key2
;                    (+)  if Key1 > Key2

Method FileFormatCollection.Compare,, pCollKey:PSTRINGW, pTestKey:PSTRINGW
  invoke StrICompW, pCollKey, pTestKey
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FileFormatCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  -> Item.
; Return:     Nothing.

Method FileFormatCollection.DestroyItem, uses xdi, pItem:PFILEFORMAT
  mov xdi, pItem
  .if xdi != NULL
    invoke StrDispose, [xdi].FILEFORMAT.pExtension      ;Dispose file extension string
    MemFree xdi                                         ;Free data
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FileFormatCollection.GetFormat
; Purpose:    Return the stored file format for a FileName.
; Arguments:  Arg1: -> FileName
; Return:     eax: EFF_XXX.

Method FileFormatCollection.GetFormat, uses xsi, pFileName:PSTRINGW
  SetObject xsi
  invoke StrRScanW, pFileName, '.'
  .if xax != NULL
    lea xdx, [xax + sizeof(CHRW)]
    OCall xsi::FileFormatCollection.Search, xdx 
    .if xax != FALSE
      mov eax, ecx
      OCall xsi::FileFormatCollection.ItemAt, eax
      mov eax, [xax].FILEFORMAT.dFileFormat
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FileFormatCollection.Insert
; Purpose:    If the target item is not found in the sorted collection, it is inserted at the
;             correct index position. Calls Search to determine if the item exists, and if not,
;             where to insert it.
; Arguments:  Arg1: -> File extension string.
;             Arg2: Associated file format.
; Return:     xax -> Inserted item or NULL if the item was not inserted.

Method FileFormatCollection.Insert, uses xbx xdi xsi, pExtension:PSTRING, dFileFormat:DWORD
  SetObject xsi
  MemAlloc sizeof(FILEFORMAT)
  .if xax != NULL
    mov xbx, xax
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    invoke StrLengthA, pExtension
    lea edi, [eax*sizeof(CHRW)]
    invoke StrAllocW, eax
    mov [xbx].FILEFORMAT.pExtension, xax
    invoke MultiByteToWideChar, CP_ACP, 0, pExtension, -1, xax, edi
  else
    invoke StrNewW, pExtension
    mov [xbx].FILEFORMAT.pExtension, xax
  endif
    m2m [xbx].FILEFORMAT.dFileFormat, dFileFormat, ecx
    OCall xsi.KeyOf, xbx
    OCall xsi.Search, xax                                 ;Ret: eax = Found (TRUE/FALSE), ecx = Idx
    .if eax == FALSE                                      ;Found?
      mov edx, ecx
      OCall xsi.InsertAt, edx, xbx
    .else
      DbgText "--- Duplicate Keyword ---"
      DbgStrW [xbx].FILEFORMAT.pExtension
      DbgDec [xbx].FILEFORMAT.dFileFormat
      invoke StrDispose, [xbx].FILEFORMAT.pExtension
      MemFree xbx
      xor eax, eax
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FileFormatCollection.KeyOf
; Purpose:    KeyOf is overridden in cases where the key of the item is not the item itself.
; Arguments:  Arg1: -> Item.
; Return:     eax = Given an item from the collection, KeyOf should return the corresponding key of
;                   the item. The default KeyOf simply returns Item.

Method FileFormatCollection.KeyOf,, pItem:PFILEFORMAT
  mov xcx, pItem
  mov xax, [xcx].FILEFORMAT.pExtension
MethodEnd


