; ==================================================================================================
; Title:      ADE_FileTypeCollection.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm FileTypeCollection object implementation.
; ==================================================================================================


; ==================================================================================================
; FileTypeCollection implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:    FileTypeCollection.Compare
; Purpose:   Compare the WIDE strings Key1 and Key2.
; Arguments: Arg1: -> First key.
;            Arg2: -> Second key.
; Return:    eax =   (-)  if Key1 < Key2
;                     0   if Key1 = Key2
;                    (+)  if Key1 > Key2

Method FileTypeCollection.Compare,, pCollKey:PSTRINGW, pTestKey:PSTRINGW
  invoke StrICompW, pCollKey, pTestKey
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FileTypeCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  -> Item.
; Return:     Nothing.

Method FileTypeCollection.DestroyItem, uses xdi, pItem:PFILETYPEINFOEX
  mov xdi, pItem
  .if xdi != NULL
    invoke StrDispose, [xdi].FILETYPEINFOEX.pExtension  ;Dispose file extension string
    MemFree xdi                                         ;Free data
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FileTypeCollection.GetFileTypeInfo
; Purpose:    Return the stored file tyoe information for a given FileName, based on its extension.
; Arguments:  Arg1: -> FileName
; Return:     xax -> FILETYPEINFOEX or NULL if not available.

Method FileTypeCollection.GetFileTypeInfo, uses xbx xsi, pFileName:PSTRINGW
  local dPerceivedType:DWORD, dFlag:DWORD

  SetObject xsi
  invoke StrRScanW, pFileName, '.'
  .if xax != NULL
    mov xbx, xax
    lea xdx, [xax + sizeof(CHRW)]
    OCall xsi::FileTypeCollection.Search, xdx
    .if eax != FALSE
      mov edx, ecx
      OCall xsi::FileTypeCollection.ItemAt, edx
    .else
      invoke AssocGetPerceivedType, xbx, addr dPerceivedType, addr dFlag, NULL
      .if eax == S_OK
        .if dPerceivedType == PERCEIVED_TYPE_TEXT
          lea xax, [xsi].PerceivedTextType
        .else
          xor eax, eax
        .endif
      .else
        xor eax, eax
      .endif
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FileTypeCollection.Insert
; Purpose:    If the target item is not found in the sorted collection, it is inserted at the
;             correct index position. Calls Search to determine if the item exists, and if not,
;             where to insert it.
; Arguments:  Arg1: -> File extension string.
;             Arg2: Content type (FCT_XXXX).
;             Arg3: File format (EFF_XXXX).
; Return:     xax -> Inserted item or NULL if the item was not inserted.

Method FileTypeCollection.Insert, uses xbx xdi xsi, pExtension:PSTRING, dContentType:DWORD, dFileFormat:DWORD
  SetObject xsi
  MemAlloc sizeof(FILETYPEINFOEX)
  .if xax != NULL
    mov xbx, xax
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    invoke StrLengthA, pExtension
    lea edi, [eax*sizeof(CHRW)]
    invoke StrAllocW, eax
    mov [xbx].FILETYPEINFOEX.pExtension, xax
    invoke MultiByteToWideChar, CP_ACP, 0, pExtension, -1, xax, edi
  else
    invoke StrNewW, pExtension
    mov [xbx].FILETYPEINFOEX.pExtension, xax
  endif
    m2m [xbx].FILETYPEINFOEX.dFileFormat, dFileFormat, ecx
    m2m [xbx].FILETYPEINFOEX.dContentType, dContentType, edx
    OCall xsi.KeyOf, xbx
    OCall xsi.Search, xax                                 ;Ret: eax = Found (TRUE/FALSE), ecx = Idx
    .if eax == FALSE                                      ;Found?
      mov edx, ecx
      OCall xsi.InsertAt, edx, xbx
    .else
      DbgText "--- Duplicate Keyword ---"
      DbgStrW [xbx].FILETYPEINFOEX.pExtension
      DbgDec [xbx].FILETYPEINFOEX.dFileFormat
      invoke StrDispose, [xbx].FILETYPEINFOEX.pExtension
      MemFree xbx
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FileTypeCollection.KeyOf
; Purpose:    KeyOf is overridden in cases where the key of the item is not the item itself.
; Arguments:  Arg1: -> Item.
; Return:     eax = Given an item from the collection, KeyOf should return the corresponding key of
;                   the item. The default KeyOf simply returns Item.

Method FileTypeCollection.KeyOf,, pItem:PFILETYPEINFOEX
  mov xcx, pItem
  mov xax, [xcx].FILETYPEINFOEX.pExtension
MethodEnd


