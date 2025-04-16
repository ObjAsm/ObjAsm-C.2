; ==================================================================================================
; Title:      SortedStrCollectionA.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedStrCollectionA objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     SortedStrCollectionA
; Purpose:    Implement a sorted ANSI string collection. It is descendant of SortedCollection
;             The Compare method is overridden to provide the conventional lexicographic ASCII
;             string ordering. You can override Compare to allow other orderings, such as those
;             for reverse ordering or non-English character sets.

Object SortedStrCollectionA, SortedStrCollectionAID, SortedCollection
  RedefineMethod    Compare,        PSTRINGA, PSTRINGA
  RedefineMethod    DeserializeItem,PSTRINGA, PDESER_INFO
  RedefineMethod    DestroyItem,    PSTRINGA
  RedefineMethod    GetItem,        $ObjPtr(Stream)              ;-> Stream
  RedefineMethod    PutItem,        $ObjPtr(Stream), PSTRINGA    ;-> Stream, -> Item
  RedefineMethod    SerializeItem,  PSTRINGA
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionA.Compare
; Purpose:    Compare the ANSI strings Key1 and Key2.
; Arguments:  Arg1: -> First string.
;             Arg2: -> Second string.
; Return:     eax =   (-)  if Key1 < Key2
;                      0   if Key1 = Key2
;                     (+)  if Key1 > Key2

Method SortedStrCollectionA.Compare,, pKey1:PSTRINGA, pKey2:PSTRINGA
  invoke StrCompA, pKey1, pKey2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionA.DeserializeItem
; Purpose:    Convert a serialized string item back.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedStrCollectionA.DeserializeItem,, pItem:PSTRINGA, pDeserInfo:PDESER_INFO
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionA.DestroyItem
; Purpose:    Remove the ANSI string item from the sorted collection and disposes it.
; Arguments:  Arg1: -> ANSI string.
; Return:     Nothing.

Method SortedStrCollectionA.DestroyItem,, pItem:PSTRINGA
  invoke StrDisposeA, pItem
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionA.GetItem
; Purpose:    Read a string from the stream by calling Stream.ReadStr.
; Arguments:  Arg1: -> Stream object.
; Return:     xax -> ANSI String.

Method SortedStrCollectionA.GetItem,, pStream:$ObjPtr(Stream)
  OCall pStream::Stream.StrRead
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionA.PutItem
; Purpose:    Write the ANSI string item on to the stream by calling Stream.WriteStr.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> ANSI String.
; Return:     Nothing.

Method SortedStrCollectionA.PutItem,, pStream:$ObjPtr(Stream), pString:PSTRINGA
  OCall pStream::Stream.StrWriteA, pString
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionA.SerializeItem
; Purpose:    Serialize a string item.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedStrCollectionA.SerializeItem,, pItem:PSTRINGA
MethodEnd

endif
