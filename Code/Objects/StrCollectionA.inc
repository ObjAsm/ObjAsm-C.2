; ==================================================================================================
; Title:      StrCollectionA.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of StrCollectionA objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     StrCollectionA
; Purpose:    Implement an ANSI string collection.

Object StrCollectionA, StrCollectionAID, Collection
  RedefineMethod    DeserializeItem,  PSTRINGA, PDESER_INFO
  RedefineMethod    DestroyItem,      PSTRINGA
  RedefineMethod    GetItem,          $ObjPtr(Stream)              ;-> Stream
  RedefineMethod    PutItem,          $ObjPtr(Stream), PSTRINGA    ;-> Stream, -> Item
  RedefineMethod    SerializeItem,    PSTRINGA
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionA.DeserializeItem
; Purpose:    Convert a serialized string item back.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method StrCollectionA.DeserializeItem,, pItem:PSTRINGA, pDeserInfo:PDESER_INFO
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionA.DestroyItem
; Purpose:    Remove the ANSI string item from the collection and disposes it.
; Arguments:  Arg1: -> ANSI string.
; Return:     Nothing.

Method StrCollectionA.DestroyItem,, pItem:PSTRINGA
  invoke StrDisposeA, pItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionA.GetItem
; Purpose:    Read a ANSI string from the stream by calling Stream.ReadStr.
; Arguments:  Arg1: -> Stream object.
; Return:     Xax -> ANSI string.

Method StrCollectionA.GetItem,, pStream:$ObjPtr(Stream)
  OCall pStream::Stream.StrReadA
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionA.PutItem
; Purpose:    Write the ANSI string item on to the stream by calling Stream.WriteStrA.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> ANSI string.
; Return:     Nothing.

Method StrCollectionA.PutItem,, pStream:$ObjPtr(Stream), pString:PSTRINGA
  OCall pStream::Stream.StrWriteA, pString
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    StrCollectionA.SerializeItem
; Purpose:   Serialize a string item.
; Arguments: Arg1: -> Item.
;            Arg2: -> DESER_INFO.
; Return:    Nothing.

Method StrCollectionA.SerializeItem,, pItem:PSTRINGA
MethodEnd

endif
