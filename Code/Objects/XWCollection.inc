; ==================================================================================================
; Title:      XWCollection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of XWCollection objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Can only be used with MakeObjects. There is no precompiled object.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XWCollection
; Purpose:    Implement collection of unique XWORDs instead of objects.

Object XWCollection, XWCollectionID, Collection
  RedefineMethod    DeserializeItem,  XWORD, PDESER_INFO
  RedefineMethod    DestroyItem,      XWORD
  RedefineMethod    Insert,           XWORD
  RedefineMethod    Load,             $ObjPtr(Stream), POINTER     ;-> Stream, pOwner
  RedefineMethod    Store,            $ObjPtr(Stream)              ;-> Stream
  RedefineMethod    SerializeItem,    XWORD

  DefineVariable    dDuplicates,  DWORD,    FALSE
ObjectEnd

; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XWCollection.DeserializeItem
; Purpose:    Convert a serialized DWORD back.
; Arguments:  Arg1: Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method XWCollection.DeserializeItem,, xItem:XWORD, pDeserInfo:PDESER_INFO
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XWCollection.DestroyItem
; Purpose:    Auxiliary procedure. Don't call directly!
; Arguments:  Arg1: Item.
; Return:     Nothing.

Method XWCollection.DestroyItem,, xItem:XWORD
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XWCollection.Insert
; Purpose:    Insert item at the end of the XWCollection.
; Arguments:  New XWORD.
; Return:     xax -> Inserted item.

Method XWCollection.Insert, uses xbx xsi, xItem:XWORD
  SetObject xsi
  .if [xsi].dDuplicates == FALSE
    mov xbx, xItem
    OCall xsi.IndexOf, xbx
    .if eax == -1
      ACall xsi.Insert, xbx
    .else
      mov xax, xbx
    .endif
  .else
    ACall xsi.Insert, xdx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XWCollection.Load
; Purpose:    Load and initializes the XWCollection from a stream object.
;             It bypasses the GetItem method
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Owner object.
; Return:     Nothing.

Method XWCollection.Load, uses xsi, pStream:$ObjPtr(Stream), pOwner:POINTER
  local dCount:DWORD, dLimit:DWORD

  SetObject xsi
  mrm [xsi].pOwner, pOwner, xax
  mov dCount, $32($OCall(pStream::Stream.BinRead32))
  mov dLimit, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDelta, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dMaxCapacity, $32($OCall(pStream::Stream.BinRead32))

  xor eax, eax
  mov [xsi].pItems, xax
  mov [xsi].dCount, eax
  mov [xsi].dLimit, eax
  OCall xsi.SetLimit, dLimit
  mrm [xsi].dCount, dCount, eax
  shl eax, $Log2(sizeof(XWORD))
  OCall pStream::Stream.BinRead, [xsi].pItems, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XWCollection.Store
; Purpose:    Store the XWCollection in a stream object bypassing the PutItem method.
; Arguments:  -> Stream object.
; Return:     Nothing.

Method XWCollection.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall xsi::Streamable.Store, pStream
  OCall pStream::Stream.BinWrite32, [xsi].dCount
  OCall pStream::Stream.BinWrite32, [xsi].dLimit
  OCall pStream::Stream.BinWrite32, [xsi].dDelta
  OCall pStream::Stream.BinWrite32, [xsi].dMaxCapacity
  mov eax, [xsi].dCount
  shl eax, $Log2(sizeof(XWORD))
  OCall pStream::Stream.BinWrite, [xsi].pItems, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XWCollection.SerializeItem
; Purpose:    Serialize a DWORD item.
; Arguments:  Arg1: Item.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method XWCollection.SerializeItem,, xItem:XWORD
MethodEnd

endif
