; ==================================================================================================
; Title:      SortedDataCollection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of sorted data collections.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     SortedDataCollection
; Purpose:    SortedDataCollection is a descendant of SortedCollection. It implements a
;             collection of sorted data structures instead of objects.

Object SortedDataCollection, SortedDataCollectionID, SortedCollection
  RedefineMethod    DeserializeItem,  POINTER, PDESER_INFO
  RedefineMethod    DestroyItem,      POINTER
  RedefineMethod    GetItem,          $ObjPtr(Stream)
  RedefineMethod    PutItem,          $ObjPtr(Stream), POINTER
  RedefineMethod    SerializeItem,    POINTER
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SortedDataCollection.DeserializeItem
; Purpose:    Convert a serialized data item back.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedDataCollection.DeserializeItem,, pItem:POINTER, pDeserInfo:PDESER_INFO
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedDataCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method SortedDataCollection.DestroyItem,, pItem:POINTER
  .if pItem != NULL
    MemFree pItem                                       ;Remove the data from Heap
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedDataCollection.GetItem
; Purpose:    Load an item from a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     xax -> new loaded data or NULL if failed.

Method SortedDataCollection.GetItem, uses xbx xdi, pStream:$ObjPtr(Stream)
  OCall pStream::Stream.BinRead32
  mov ebx, eax
  MemAlloc ebx
  mov xdi, xax
  .if xax != NULL
    OCall pStream::Stream.BinRead, xax, ebx
  .else
    OCall ErrorReport, NULL, COL_OUT_OF_MEMORY
  .endif
  mov xax, xdi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedDataCollection.PutItem
; Purpose:    Store an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Item.
; Return:     Nothing.

Method SortedDataCollection.PutItem,, pStream:$ObjPtr(Stream), pItem:POINTER
  local dSize:DWORD

  invoke HeapSize, hProcessHeap, 0, pItem
  mov dSize, eax
  OCall pStream::Stream.BinWrite, addr dSize, sizeof(DWORD)
  OCall pStream::Stream.BinWrite, pItem, dSize
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedDataCollection.SerializeItem
; Purpose:    Serialize a data item.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedDataCollection.SerializeItem,, pItem:POINTER
MethodEnd

endif
