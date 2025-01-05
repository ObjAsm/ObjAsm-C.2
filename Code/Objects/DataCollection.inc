; ==================================================================================================
; Title:      DataCollection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm implementation of DataCollection objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DataCollection
; Purpose:    DataCollection is a descendant of Collection. It implements a collection of data
;             structures instead of objects. To achieve this behaviour, the dynamic method
;             DestroyItem redefined.
; Notes:      - Since this object inherits from Streamable, it is able to store and recall its data
;               members to any type of Stream descendant object.
;             - This object and all descendants are thread safe using the ObjAsm multithreading
;               support.

Object DataCollection, DataCollectionID, Collection
  RedefineMethod    DeserializeItem,POINTER, PDESER_INFO
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    PutItem,        $ObjPtr(Stream), POINTER
  RedefineMethod    SerializeItem,  POINTER
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataCollection.DeserializeItem
; Purpose:    Convert a serialized data item back.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method DataCollection.DeserializeItem,, pItem:POINTER, pDeserInfo:PDESER_INFO
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  -> Item.
; Return:     Nothing.

Method DataCollection.DestroyItem,, pItem:POINTER
  .if pItem != NULL
    MemFree pItem                                       ;Free data from process heap
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataCollection.GetItem
; Purpose:    Load an item from a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     xax -> New loaded data.

Method DataCollection.GetItem, uses xbx, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  OCall pStream::Stream.BinRead, addr dSize, sizeof(dSize)
  MemAlloc dSize
  mov xbx, xax
  .if xax != NULL
    OCall pStream::Stream.BinRead, xax, dSize
  .else
    OCall ErrorReport, NULL, COL_OUT_OF_MEMORY
  .endif
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataCollection.PutItem
; Purpose:    Store an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item. This argument should never be NULL.
; Return:     Nothing.

Method DataCollection.PutItem,, pStream:$ObjPtr(Stream), pItem:POINTER
  local dSize:DWORD

  invoke HeapSize, hProcessHeap, 0, pItem           ;Return in xax
  mov dSize, eax
  OCall pStream::Stream.BinWrite, addr dSize, sizeof(dSize)
  OCall pStream::Stream.BinWrite, pItem, dSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataCollection.SerializeItem
; Purpose:    Serialize a data item.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method DataCollection.SerializeItem,, pItem:POINTER
MethodEnd

endif
