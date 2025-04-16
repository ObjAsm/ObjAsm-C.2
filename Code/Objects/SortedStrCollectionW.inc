; ==================================================================================================
; Title:      SortedStrCollectionW.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedStrCollectionW objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     SortedStrCollectionW
; Purpose:    Implement a sorted WIDE string collection. It is descendant of SortedCollection
;             The Compare method is overridden to provide the conventional lexicographic ASCII
;             string ordering. You can override Compare to allow other orderings, such as those
;             for reverse ordering or non-English character sets.

Object SortedStrCollectionW, SortedStrCollectionWID, SortedCollection
  RedefineMethod    Compare,          PSTRINGW, PSTRINGW
  RedefineMethod    DeserializeItem,  PSTRINGW, PDESER_INFO
  RedefineMethod    DestroyItem,      PSTRINGW
  RedefineMethod    GetItem,          $ObjPtr(Stream)              ;-> Stream
  RedefineMethod    PutItem,          $ObjPtr(Stream), PSTRINGW    ;-> Stream, -> Item
  RedefineMethod    SerializeItem,    PSTRINGW
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionW.Compare
; Purpose:    Compare the WIDE strings Key1 and Key2.
; Arguments:  Arg1: -> First key.
;             Arg2: -> Second key.
; Return:     eax =   (-)  if Key1 < Key2
;                      0   if Key1 = Key2
;                     (+)  if Key1 > Key2

Method SortedStrCollectionW.Compare,, pKey1:PSTRINGW, pKey2:PSTRINGW
  invoke StrCompW, pKey1, pKey2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionW.DeserializeItem
; Purpose:    Convert a serialized string item back.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedStrCollectionW.DeserializeItem,, pItem:PSTRINGW, pDeserInfo:PDESER_INFO
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionW.DestroyItem
; Purpose:    Remove the WIDE string item from the sorted collection and disposes it.
; Arguments:  Arg1: -> Wide string.
; Return:     Nothing.

Method SortedStrCollectionW.DestroyItem,, pItem:PSTRINGW
  invoke StrDisposeW, pItem
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionW.GetItem
; Purpose:    Read a WIDE string from the stream by calling Stream.ReadStr.
; Arguments:  Arg1: -> Stream object.
; Return:     xax -> WIDE string.

Method SortedStrCollectionW.GetItem,, pStream:$ObjPtr(Stream)
  OCall pStream::Stream.StrRead
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionW.PutItem
; Purpose:    Write the WIDE string item on to the Stream by calling Stream.WriteStrW.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> WIDE string.
; Return:     Nothing.

Method SortedStrCollectionW.PutItem,, pStream:$ObjPtr(Stream), pString:PSTRINGW
  OCall pStream::Stream.StrWriteW, pString
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SortedStrCollectionW.SerializeItem
; Purpose:    Serialize a string item.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedStrCollectionW.SerializeItem,, pItem:PSTRINGW
MethodEnd

endif
