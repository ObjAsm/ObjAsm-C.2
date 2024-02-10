; ==================================================================================================
; Title:      SortedCollection.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of SortedCollection objects.
; Notes:      Version C.1.0, September 2017
;               - First release.
;             Version C.1.1, September 2020
;               - Sort bugs corrected: edi -> xdi, insert indirection.
;               - Sort method optimized: first item is skiped on first iteration.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     SortedCollection
; Purpose:    SortedCollection is a specialized Collection. It implements collections sorted by key
;             and by default without duplicates. Sorting is implied by a dynamic Compare
;             method which you override to provide your own definition of element ordering.
;             As new items are added, they are automatically inserted in the order specified by the
;             Compare method. Items can be located using the binary search method, Search.
;             The dynamic KeyOf method that returns a POINTER for Compare can also be overridden if
;             Compare needs additional information.
;
;             SortedCollection implements sorted collections both with or without duplicate keys.
;             The Duplicates field controls whether duplicates are allowed. It defaults to FALSE,
;             indicating that duplicate keys are not allowed, but after creating a sorted
;             collection, you can set Duplicates to TRUE to allow elements with duplicate keys in
;             the collection.
;
;             Compare is an abstract method that must be overridden in all descendant types.
;             Compare should compare the two key values, and return a result as follows:
;
;                    (-)  if Key1 < Key2
;                     0   if Key1 = Key2
;                    (+)  if Key1 > Key2
;
;             Key1 and Key2 are POINTER values, as extracted from their corresponding collection
;             items by the KeyOf method. The Search method implements a binary search through the
;             collection's items using Compare to compare the items.
;

Object SortedCollection, SortedCollectionID, Collection
  DynamicAbstract   Compare,      XWORD, XWORD          ;Key1, Key2
  RedefineMethod    Insert,       POINTER               ;-> Item
  DynamicMethod     KeyOf,        POINTER               ;-> Item
  RedefineMethod    Load,         $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     Search,       XWORD                 ;Key to search for
  VirtualMethod     Sort
  RedefineMethod    Store,        $ObjPtr(Stream)

  DefineVariable    dDuplicates,  DWORD,   FALSE        ;Don't allow duplicate items
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedCollection.Insert
; Purpose:    If the target item is not found in the sorted collection, it is inserted at the
;             correct index position. It calls Search to determine if the item exists, and if not,
;             where to insert it.
; Arguments:  Arg1: -> Item.
; Return:     xax -> Inserted item or NULL if the item was not inserted.

Method SortedCollection.Insert, uses xsi, pItem:POINTER
  SetObject xsi
  OCall xsi.KeyOf, pItem
  OCall xsi.Search, xax                                 ;eax = Found (TRUE/FALSE), ecx = Index
  .if eax != FALSE
    xor eax, eax                                        ;xax = NULL (exit value)
    cmp [xsi].dDuplicates, eax
    je @@EOM
  .endif
  mov edx, ecx
  OCall xsi.InsertAt, edx, pItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedCollection.KeyOf
; Purpose:    KeyOf is overridden in cases where the key of the item is not the item itself.
; Arguments:  Arg1: -> Item.
; Return:     eax = Given an item from the collection, KeyOf should return the corresponding key of
;                   the item. The default KeyOf simply returns Item.

Method SortedCollection.KeyOf,, pItem:POINTER
  mov xax, pItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedCollection.Load
; Purpose:    Load a sorted collection from the stream object by first calling
;             Collection.Load. It then reads the Duplicates field.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method SortedCollection.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  OCall pStream::Stream.BinRead32
  mov [xsi].dDuplicates, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedCollection.Search
; Purpose:    Search for an item by its key.
; Arguments:  Arg1: Item key to seach for.
; Return:     eax: TRUE if found, otherwise FALSE.
;             ecx: Index in the range [0..Count]. If the item is not found, ecx is set to the
;                  index where the item would be placed if inserted.

Method SortedCollection.Search, uses xbx xdi xsi r12 r13, xKey:XWORD
  LocReg dFound:r12d, dLowIndex:r13d

  SetObject xbx
  xor edi, edi                                          ;L = xdi = 0
  mov $LocReg(dLowIndex), edi
  mov esi, [xbx].dCount
  mov $LocReg(dFound), edi                              ;Found flag = FALSE
  dec xsi                                               ;H = xsi = Count - 1
@@0:
  mov edi, $LocReg(dLowIndex)
@@1:
  cmp edi, esi
  jg @@Exit                                             ;> signed compare
  add xdi, xsi
  shr xdi, 1                                            ;(L+H)/2
  mov xdx, [xbx].pItems
  OCall xbx.KeyOf, POINTER ptr [xdx + sizeof(POINTER)*xdi]
  OCall xbx.Compare, xax, xKey
  cmp eax, 0                                            ;Can NOT be replaced with "or eax, eax"
  jg @@2                                                ;> signed compare  (ZF=0 and SF=OF)
  jl @@3                                                ;                  (ZF=1)
  mov $LocReg(dFound), TRUE                             ;Found flag = TRUE
  cmp [xbx].dDuplicates, FALSE
  je @@Exit
@@2:
  lea esi, [edi - 1]                                    ;H = Index - 1
  jmp @@0
@@3:
  inc edi                                               ;L = Index + 1
  mov $LocReg(dLowIndex), edi
  jmp @@1

@@Exit:
  mov ecx, edi                                          ;Return insertion index in ecx
  mov eax, $LocReg(dFound)                              ;Return Found condition in eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedCollection.Store
; Purpose:    Store the sorted collection and all its items on the stream object by calling
;             Collection.Store to write the collection. It then writes the Duplicates
;             field to the stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method SortedCollection.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite32, [xsi].dDuplicates
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedCollection.Sort
; Purpose:    Resort the collection in place, i.e. if the compare method was changed.
; Arguments:  None.
; Return:     Nothing.

Method SortedCollection.Sort, uses xbx xdi xsi
  SetObject xsi
  mov ebx, [xsi].dCount
  xor eax, eax
  test ebx, ebx
  setnz al                                                ;If exists, skip first item
  mov [xsi].dCount, eax                                   ;Set list new initial count
  .if !ZERO?
    mov xdi, [xsi].pItems
    .while TRUE
      dec ebx
      .break .if ZERO?
      add xdi, sizeof(POINTER)                            ;Move to next item
      OCall xsi.Insert, POINTER ptr [xdi]                 ;Insert item from that position in the list
    .endw
  .endif
MethodEnd

endif
