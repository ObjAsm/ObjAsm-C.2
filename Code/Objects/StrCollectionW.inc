; ==================================================================================================
; Title:      StrCollectionW.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of StrCollectionW objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     StrCollectionW
; Purpose:    Implement an ANSI string collection.

Object StrCollectionW, StrCollectionWID, Collection
  RedefineMethod    DeserializeItem,  PSTRINGW, PDESER_INFO
  RedefineMethod    DestroyItem,      PSTRINGW
  RedefineMethod    GetItem,          $ObjPtr(Stream)              ;-> Stream
  RedefineMethod    PutItem,          $ObjPtr(Stream), PSTRINGW    ;-> Stream, -> Item
  RedefineMethod    SerializeItem,    PSTRINGW
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionW.DeserializeItem
; Purpose:    Convert a serialized string item back.
; Arguments:  Arg1: -> Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method StrCollectionW.DeserializeItem,, pItem:PSTRINGW, pDeserInfo:PDESER_INFO
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionW.DestroyItem
; Purpose:    Remove the WIDE string item from the collection and disposes it.
; Arguments:  Arg1: -> WIDE string.
; Return:     Nothing.

Method StrCollectionW.DestroyItem,, pItem:PSTRINGW
  invoke StrDisposeW, pItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionW.GetItem
; Purpose:    Read a WIDE string from the stream by calling Stream.ReadStr.
; Arguments:  Arg1: -> Stream object.
; Return:     xax -> WIDE string.

Method StrCollectionW.GetItem,, pStream:$ObjPtr(Stream)
  OCall pStream::Stream.StrReadW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StrCollectionW.PutItem
; Purpose:    Write the WIDE string item on to the Stream by calling Stream.WriteStrW.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> WIDE string.
; Return:     Nothing.

Method StrCollectionW.PutItem,, pStream:$ObjPtr(Stream), pString:PSTRINGW
  OCall pStream::Stream.StrWriteW, pString
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    StrCollectionW.SerializeItem
; Purpose:   Serialize a string item.
; Arguments: Arg1: -> Item.
;            Arg2: -> DESER_INFO.
; Return:    Nothing.

Method StrCollectionW.SerializeItem,, pItem:PSTRINGW
MethodEnd

endif
