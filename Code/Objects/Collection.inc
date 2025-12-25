; ==================================================================================================
; Title:      Collection.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of Collection objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, September 2023
;               - Mem-Leak in Load method corrected.
;             Version C.1.2, October 2023
;               - .ColForEach, .ColForEachRev and .ColNext macros added.
;               - Removed "private" from SetLimit.
; ==================================================================================================


COL_MAX_CAPACITY  equ 0FFFFFFFFh/sizeof(POINTER)

PColProc  typedef proto :POINTER, :XWORD, :XWORD        ;If required, return value stored in eax

; --------------------------------------------------------------------------------------------------
; Object:     Collection
; Purpose:    Implement a collection of objects called items.
;             The concept of a Collection is more general than the traditional array or list. A
;             Collection object can size itself dynamically at run time and is the base object for
;             many other specialized objects, such as SortedCollections, StrCollections,
;             DataCollections, etc. In addition to methods for adding and deleting items, the
;             Collection object offers several iteration methods that call a procedure for each
;             item in the collection.
; Notes:      - Since this object inherits from Streamable, it is able to store and recall its items
;               to any type of Stream descendant object.
;             - This object and all descendants are thread safe using the OA multithreading support.
;             - NULL items are not supported.

Object Collection, CollectionID, Streamable
  VirtualMethod     Delete,         POINTER             ;-> Item
  VirtualMethod     DeleteAt,       DWORD               ;Index in range [0..Count-1]
  VirtualMethod     DeleteAll
  RedefineMethod    Deserialize,    PDESER_INFO
  DynamicMethod     DeserializeItem,POINTER, PDESER_INFO
  DynamicMethod     DestroyItem,    POINTER             ;Override for data structures
  VirtualMethod     Dispose,        POINTER             ;-> Item
  VirtualMethod     DisposeAll
  VirtualMethod     DisposeAt,      DWORD               ;Index in range [0..Count-1]
  RedefineMethod    Done
  VirtualMethod     FirstThat,      POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualMethod     FirstThatNot,   POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualMethod     ForEach,        POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter
  VirtualMethod     ForEachRev,     POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter, reverse order
  DynamicMethod     GetItem,        $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     IndexOf,        POINTER             ;-> Item
  RedefineMethod    Init,           POINTER, DWORD, DWORD, DWORD ;-> Owner, Count, Incr., Max Capa.
  VirtualMethod     Insert,         POINTER             ;-> Item
  VirtualMethod     InsertAt,       DWORD, POINTER      ;Index, -> Item
  VirtualMethod     ItemAt,         DWORD               ;Index in range [0..Count-1]
  VirtualMethod     LastThat,       POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualMethod     LastThatNot,    POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     PutAt,          DWORD, POINTER      ;Index, -> Item
  DynamicMethod     PutItem,        $ObjPtr(Stream), POINTER ;-> Stream, -> Item
  RedefineMethod    Serialize
  DynamicMethod     SerializeItem,  POINTER
  VirtualMethod     SetLimit,       DWORD               ;Set new limit
  RedefineMethod    Store,          $ObjPtr(Stream)     ;-> Stream

  DefineVariable    pItems,         POINTER,      NULL
  DefineVariable    dCount,         DWORD,        0     ;Current used capacity
  DefineVariable    dLimit,         DWORD,        0     ;Current capacity
  DefineVariable    dDelta,         DWORD,        0     ;Capacity increment (used by SetLimit)
  DefineVariable    dMaxCapacity,   DWORD,        0
  DefineVariable    ObjLock,        OBJECT_LOCK,  {}    ;Locking structure for multithreaded access
ObjectEnd


; ==================================================================================================

??ColForEach_ID = 0

; --------------------------------------------------------------------------------------------------
; Macro:      .ColForEach
; Purpose:    Loop through all items of the collection.
; Arguments:  Arg1: Collection. 
;             Arg2: Optional 32 bit index variable/register. Can not be eax!
; Return:     Nothing.
; Note:       - On each loop xax -> collection item.
;             - If Arg1 is a POINTER, load it in a non used register and pass [reg] as argument.
;             - break and .continue can be used.
; Example 1:  .ColForEach MyColl
;               DbgHex [xax].$Obj(Primer).pOwner
;             .ColNext
; Example 2:  mov xbx, pColl
;             .ColForEach [xbx]
;               DbgHex [xax].$Obj(Primer).pOwner
;             .ColNext

??ColForEach_ID = 0
.ColForEach macro Coll:req, Index
  ??ColForEach_ID = ??ColForEach_ID + 1
% echo @CatStr(%??ColForEach_ID)
  ifb <Index>
    @CatStr(<??ColForEach_Index_>, %??ColForEach_ID) textequ GetMemBSS(4)
  else
    @CatStr(<??ColForEach_Index_>, %??ColForEach_ID) textequ <Index>
  endif
  @CatStr(<??ColForEach_Step_>, %??ColForEach_ID) = 1

  if (opattr Index) and OAT_REGISTER
    if @InStr(1, %RAX_SUBREGS, $Upper(&Index)) ne 0
      .err <.ColForEachRev: invalid index register>
    endif
    xor Index, Index
    .while Index != ($Obj(Collection) ptr Coll).dCount
      lea eax, [sizeof(POINTER)*Index]
      add xax, ($Obj(Collection) ptr Coll).pItems
      mov xax, POINTER ptr [xax]
  else
    xor eax, eax
    mov @CatStr(<??ColForEach_Index_>, %??ColForEach_ID), eax
%   .while eax != ($Obj(Collection) ptr Coll).dCount
      lea eax, [sizeof(POINTER)*eax]
%     add xax, ($Obj(Collection) ptr Coll).pItems
      mov xax, POINTER ptr [xax]
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .ColForEachRev
; Purpose:    Loop through all items of the collection in reverse order.
; Arguments:  Arg1: Collection.
;             Arg2: Optional 32 bit index variable/register. Can not be eax!
; Return:     Nothing.
; Note:       On each loop xax -> collection item.

.ColForEachRev macro Coll:req, Index
  ??ColForEach_ID = ??ColForEach_ID + 1
  ifb <Index>
    @CatStr(<??ColForEach_Index_>, %??ColForEach_ID) textequ GetMemBSS(4)
  else
    @CatStr(<??ColForEach_Index_>, %??ColForEach_ID) textequ <Index>
  endif
  @CatStr(<??ColForEach_Step_>, %??ColForEach_ID) = 1

  if (opattr Index) and OAT_REGISTER
    if @InStr(1, %RAX_SUBREGS, $Upper(&Index)) ne 0
      .err <.ColForEachRev: invalid index register>
    endif
    mov Index, ($Obj(Collection) ptr Coll).dCount
    dec Index
    .while !SIGN?
      lea eax, [sizeof(POINTER)*Index]
      add xax, ($Obj(Collection) ptr Coll).pItems
      mov xax, POINTER ptr [xax]
  else
    mov eax, ($Obj(Collection) ptr Coll).dCount
    dec eax
    mov @CatStr(<??ColForEach_Index_>, %??ColForEach_ID), eax
    .while !SIGN?
      lea eax, [sizeof(POINTER)*eax]
      add xax, ($Obj(Collection) ptr Coll).pItems
      mov xax, POINTER ptr [xax]
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .ColNext
; Purpose:    Move to the next collection item.
; Arguments:  None
; Return:     Nothing.

.ColNext macro
    if @CatStr(<??ColForEach_Step_>, %??ColForEach_ID) eq +1
      inc @CatStr(<??ColForEach_Index_>, %??ColForEach_ID)
    else
      dec @CatStr(<??ColForEach_Index_>, %??ColForEach_ID)
    endif
    mov eax, @CatStr(<??ColForEach_Index_>, %??ColForEach_ID)
  .endw
  ??ColForEach_ID = ??ColForEach_ID - 1
endm


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Delete
; Purpose:    Delete an item POINTER from the collection.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
; Return:     xax -> Item or NULL if the item is not in the collection.

Method Collection.Delete, uses xsi, pItem:POINTER
  ArgReg pItem:rdx

  SetObject xsi
  OCall xsi.IndexOf, $ArgReg(pItem)
  OCall xsi.DeleteAt, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.DeleteAt
; Purpose:    Delete the POINTER to Item(Index) from the collection.
; Arguments:  Arg1: Index value.
; Return:     xax -> Deleted item or NULL if failed.

Method Collection.DeleteAt, uses xdi xsi, dIndex:DWORD
  ArgReg dIndex:edx

  SetObject xdi
  mov ecx, [xdi].dCount
  .if $ArgReg(dIndex) < ecx
    dec ecx
    mov [xdi].dCount, ecx
    mov xdi, [xdi].pItems
    mov eax, $ArgReg(dIndex)
    lea xdi, [xdi + sizeof(POINTER)*xax]
    sub ecx, eax
    mov xax, POINTER ptr [xdi]                          ;xax -> Deleted item (return value)
    jz @@EOM
    lea xsi, [xdi + sizeof(POINTER)]
    if TARGET_BITNESS eq 32
      rep movsd
    else
      rep movsq
    endif
  .else
    OCall xdi.ErrorReport, NULL, COL_INDEX_ERROR
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.DeleteAll
; Purpose:    Remove all item POINTERs.
; Arguments:  None.
; Return:     Nothing.

Method Collection.DeleteAll
  SetObject xcx
  m2z [xcx].dCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Deserialize
; Purpose:    Restore serialized members.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method Collection.Deserialize, uses xbx xdi xsi, pDeserInfo:PDESER_INFO
  ArgReg pDeserInfo:rdx

;  DbgText "Collection.Deserialize"
  SetObject xsi
  ACall xsi.Deserialize, $ArgReg(pDeserInfo)
  mov ebx, [xsi].dCount
  mov xdi, [xsi].pItems
  test ebx, ebx
  .while !ZERO?
    OCall xsi.DeserializeItem, POINTER ptr [xdi], pDeserInfo
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.DeserializeItem
; Purpose:    Convert a serialized item back.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method Collection.DeserializeItem,, pItem:POINTER, pDeserInfo:PDESER_INFO
  ArgReg pItem:rcx, pDeserInfo:r8

  ??mov rcx, rdx
  OCall $ArgReg(pItem)::Streamable.Deserialize, $ArgReg(pDeserInfo)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Collection.DestroyItem
; Purpose:   Auxiliary procedure to dispose a item in the collection. Don't call directly!
; Arguments: Arg1: -> Item. This argument should never be NULL.
; Return:    Nothing.

Method Collection.DestroyItem,, pItem:POINTER
  ArgReg pItem:rdx

  Destroy $ArgReg(pItem)                                ;Calls the universal destructor
MethodEnd                                               ; and frees the object

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Dispose
; Purpose:    Dispose an item.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
; Return:     Nothing.

Method Collection.Dispose, uses xsi, pItem:POINTER
  ArgReg pItem:rdx

  SetObject xsi
  OCall xsi.Delete, $ArgReg(pItem)
  OCall xsi.DestroyItem, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.DisposeAll
; Purpose:    Dispose of all items in the collection.
; Arguments:  None.
; Return:     Nothing.

Method Collection.DisposeAll, uses xbx xdi xsi
  SetObject xsi
  mov ebx, [xsi].dCount
  mov xdi, [xsi].pItems
  test ebx, ebx
  .while !ZERO?
    OCall xsi.DestroyItem, POINTER ptr [xdi]
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
  m2z [xsi].dCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.DisposeAt
; Purpose:    Delete the POINTER to item(index) from the collection and then the item itself.
; Arguments:  Arg1: Index value.
; Return:     Nothing.

Method Collection.DisposeAt, uses xsi, dIndex:DWORD
  ArgReg dIndex:edx

  SetObject xsi
  OCall xsi.DeleteAt, $ArgReg(dIndex)
  OCall xsi.DestroyItem, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Done
; Purpose:    Delete and disposes of all the items in the collection.
; Arguments:  None.
; Return:     Nothing.

Method Collection.Done, uses xsi
  SetObject xsi
  .if [xsi].pItems != NULL
    OCall xsi.DisposeAll
    MemFree [xsi].pItems
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.FirstThat
; Purpose:    Search the first item that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.
; Note:       The coding praxis has shown, that max 2 args must be passed to the callee.

Method Collection.FirstThat, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov ebx, [xcx].dCount
  mov xsi, [xcx].pItems
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PColProc ptr xdi, POINTER ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jnz @F
    add xsi, sizeof(POINTER)                            ;xsi -> Next item in the collection
    dec ebx
  .endw
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, [xsi]                                        ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.FirstThatNot
; Purpose:    Search the first item that returns FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.

Method Collection.FirstThatNot, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov ebx, [xcx].dCount
  mov xsi, [xcx].pItems
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PColProc ptr xdi, POINTER ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jz @F
    add xsi, sizeof(POINTER)                            ;xsi -> Next item in the collection
    dec ebx
  .endw
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, [xsi]                                        ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.ForEach
; Purpose:    Call Action for each item in the collection.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the callee.
; Return:     Nothing.
; Note:       While the loop is running, no item should be deleted!

Method Collection.ForEach, uses xbx xdi xsi, pActionProc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pActionProc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pActionProc)
  mov ebx, [xcx].dCount
  mov xsi, [xcx].pItems
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PColProc ptr xdi, POINTER ptr [xsi], xArg1, xArg2
    add xsi, sizeof(POINTER)                            ;xsi -> Next item in the collection
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.ForEachRev
; Purpose:    Call Action for each item in the collection in reverse order.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the callee.
; Return:     Nothing.
; Note:       While the loop is running, no item should be deleted!

Method Collection.ForEachRev, uses xbx xdi xsi, pActionProc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pActionProc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pActionProc)
  mov xax, [xcx].pItems
  mov ebx, [xcx].dCount
  lea xsi, [xax + sizeof(POINTER)*xbx - sizeof(POINTER)]  ;xsi -> Last item in the collection
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PColProc ptr xdi, POINTER ptr [xsi], xArg1, xArg2
    sub xsi, sizeof(POINTER)                            ;xsi -> Previous item in the collection
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.GetItem
; Purpose:    Load an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded object.

Method Collection.GetItem,, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  ArgReg pDeserInfo:rdx

  OCall pStream::Stream.Get, $ArgReg(pDeserInfo)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.IndexOf
; Purpose:    Return the index of an item in the collection in the range [0..Count-1].
; Arguments:  Arg1: -> Item. This argument should never be NULL.
; Return:     eax = Index. If the item wasn't found, the return value is -1!

Method Collection.IndexOf, uses xdi, pItem:POINTER
  SetObject xdx
  mov ecx, [xdx].dCount
  jecxz @F
  mov xdi, [xdx].pItems
  mov xax, pItem
  if TARGET_BITNESS eq 32
    repne scasd
  else
    repne scasq
  endif
  jne @F
  mov eax, [xdx].dCount
  sub eax, ecx
  dec eax
  ret
@@:
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Init
; Purpose:    Initialize the collection with a limit (dLimit), an increasing step (dDelta)
;             and a maximum size (dMaxCapacity).
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: Maximum capacity of the collection (#items).
;                   Use COL_MAX_CAPACITY to indicate no limit.
; Return:     eax = Error code.

Method Collection.Init, uses xsi, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dMaxCapacity:DWORD
  ArgReg pOwner:rdx

  SetObject xsi
  ACall xsi.Init, $ArgReg(pOwner)
  xor eax, eax
  mov [xsi].pItems, xax
  mov [xsi].dCount, eax
  mov [xsi].dLimit, eax
  mov [xsi].dErrorCode, OBJ_OK
  m2m [xsi].dDelta, dDelta, edx
  .if eax != dMaxCapacity
    mov edx, dMaxCapacity
  .else
    mov edx, COL_MAX_CAPACITY
  .endif
  mov [xsi].dMaxCapacity, edx
  mov eax, dLimit
  .if eax <= [xsi].dMaxCapacity
    OCall xsi.SetLimit, eax
    .if eax != OBJ_OK
      OCall xsi.ErrorReport, NULL, eax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, COL_SETUP_ERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Insert
; Purpose:    Insert item at the end of the collection.
; Arguments:  Arg1: -> New item. This argument should never be NULL.
; Return:     xax -> Inserted item or NULL if failed.

Method Collection.Insert, uses xsi, pItem:POINTER
  SetObject xsi
  mov edx, [xsi].dCount
  .if edx == [xsi].dLimit
    add edx, [xsi].dDelta
    OCall xsi.SetLimit, edx                             ;edx = new limit
    test eax, eax                                       ;Check for OBJ_OK
    jnz @F
    mov edx, [xsi].dCount
    cmp edx, [xsi].dLimit
    mov eax, COL_OVERFLOW
    jz @F
  .endif
  inc [xsi].dCount
  mov xcx, [xsi].pItems
  mrm [xcx + sizeof(POINTER)*xdx], pItem, xax           ;xax -> Item
  ret
@@:
  OCall xsi.ErrorReport, NULL, eax
  xor eax, eax                                          ;Return NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.InsertAt
; Purpose:    Insert an item at index position shifting the remaining items.
; Arguments:  Arg1: Index value [0..Count].
;             Arg2: -> New item. This argument should never be NULL.
; Return:     xax -> Inserted item or NULL if failed.

Method Collection.InsertAt, uses xdi xsi, dIndex:DWORD, pItem:POINTER
  SetObject xdi
  mov ecx, [xdi].dCount
  .if ecx == [xdi].dLimit
    mov esi, [xdi].dLimit                               ;Remember old limit
    mov edx, ecx
    add edx, [xdi].dDelta
    OCall xdi.SetLimit, edx
    cmp esi, [xdi].dLimit
    je @@1                                              ;No change => Overflow
    mov ecx, [xdi].dCount
  .endif

  .if dIndex <= ecx
    inc [xdi].dCount
    mov xdi, [xdi].pItems
    lea xdi, [xdi + sizeof(POINTER)*xcx]
    sub ecx, dIndex
    .if !ZERO?                                          ;Make room
      std                                               ;Decrease xdi & xsi
      lea xsi, [xdi - sizeof(POINTER)]
      if TARGET_BITNESS eq 32
        rep movsd
      else
        rep movsq
      endif
      cld                                               ;Restore direction flag
    .endif
    mov xax, pItem                                      ;xax -> Item
    mov [xdi], xax
    ret
  .endif
  mov eax, COL_INDEX_ERROR
  jmp @@2
@@1:
  mov eax, COL_OVERFLOW
@@2:
  OCall xdi.ErrorReport, NULL, eax
  xor eax, eax                                          ;Return NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.ItemAt
; Purpose:    Return a POINTER to an item(Index).
; Arguments:  Arg1: Index in range [0..Count-1].
; Return:     xax -> Item(Index). On error it returns NULL.

Method Collection.ItemAt,, dIndex:DWORD
  SetObject xcx
  ?mov edx, dIndex
  .if edx < [xcx].dCount
    mov xcx, [xcx].pItems
    mov xax, [xcx + sizeof(POINTER)*xdx]                ;xax -> Item
  .else
    OCall xcx.ErrorReport, NULL, COL_INDEX_ERROR
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.LastThat
; Purpose:    Search the last item that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static address) Function that evaluates to TRUE or FALSE (eax = return val).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.

Method Collection.LastThat, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov xax, [xcx].pItems
  mov ebx, [xcx].dCount
  lea xsi, [xax + sizeof(POINTER)*xbx - sizeof(POINTER)];xsi -> Last item in the collection
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PColProc ptr xdi, POINTER ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jnz @F
    sub xsi, sizeof(POINTER)                            ;xsi -> Previous item in the collection
    dec ebx
  .endw                                                 ;At the end of the loop, xax = 0
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, [xsi]                                        ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.LastThatNot
; Purpose:    Search the last item that returns FALSE in eax.
; Arguments:  Arg1: -> (static address) Function that evaluates to TRUE or FALSE (eax = return val).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.

Method Collection.LastThatNot, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov xax, [xcx].pItems
  mov ebx, [xcx].dCount
  lea xsi, [xax + sizeof(POINTER)*xbx - sizeof(POINTER)]  ;xsi -> Last item in the collection
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PColProc ptr xdi, POINTER ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jz @F
    sub xsi, sizeof(POINTER)                            ;xsi -> Previous item in the collection
    dec ebx
  .endw                                                 ;At the end of the loop, xax = 0
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, [xsi]                                        ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Load
; Purpose:    Load and initializes the collection from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method Collection.Load, uses xbx xdi xsi r12, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  ArgReg pStream:rdx, pDeserInfo:r8
  LocReg dLimit:r12d

  SetObject xsi
  ACall xsi.Load, $ArgReg(pStream), $ArgReg(pDeserInfo)
  OCall pStream::Stream.BinRead32
  mov edi, eax
  OCall pStream::Stream.BinRead32
  mov $LocReg(dLimit), eax

  OCall pStream::Stream.BinRead32
  mov [xsi].dDelta, eax
  OCall pStream::Stream.BinRead32
  mov [xsi].dMaxCapacity, eax

  xor eax, eax
  mov [xsi].dCount, eax
  mov [xsi].dLimit, eax
  OCall xsi.SetLimit, $LocReg(dLimit)
  test eax, eax                                         ;Test for OBJ_OK
  jne @@Error
  mov [xsi].dCount, edi
  xor ebx, ebx
  jmp @@1
@@Error:
  OCall xsi.ErrorReport, NULL, eax
  ret

@@0:
  OCall xsi.GetItem, pStream, pDeserInfo
  OCall xsi.PutAt, ebx, xax
  inc ebx
@@1:
  cmp ebx, edi
  jb @@0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.PutAt
; Purpose:    Overwrite an item POINTER at index position.
; Arguments:  Arg1: Index value.
;             Arg2: -> New item. This argument should never be NULL.
; Return:     xax -> Replaced item at index position or NULL if failed.

Method Collection.PutAt,, dIndex:DWORD, pItem:POINTER
  ArgReg pItem:r8

  SetObject xcx
  ?mov edx, dIndex
  .if edx < [xcx].dCount
    mov xax, [xcx].pItems
    lea xcx, [xax + sizeof(POINTER)*xdx]
    mov xax, [xcx]                                      ;xax -> Replaced item
    m2m [xcx], $ArgReg(pItem), xdx
  .else
    OCall xcx.ErrorReport, NULL, COL_INDEX_ERROR
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.PutItem
; Purpose:    Store an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item. This argument should never be NULL.
; Return:     Nothing.

Method Collection.PutItem,, pStream:$ObjPtr(Stream), pItem:POINTER
  ArgReg pStream:rcx, pItem:r8

  ??mov rcx, rdx
  OCall $ArgReg(pStream)::Stream.Put, $ArgReg(pItem)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Serialize
; Purpose:    Serialize members.
; Arguments:  None.
; Return:     Nothing.

Method Collection.Serialize, uses xbx xdi xsi
  SetObject xsi
  ACall xsi.Serialize
  mov ebx, [xsi].dCount
  mov xdi, [xsi].pItems
  test ebx, ebx
  .while !ZERO?
    OCall xsi.SerializeItem, POINTER ptr [xdi]
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.SerializeItem
; Purpose:    Serialize an item.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
; Return:     Nothing.

Method Collection.SerializeItem,, pItem:POINTER
  ArgReg pItem:rcx

  ??mov rcx, rdx
  OCall $ArgReg(pItem)::Streamable.Serialize
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.SetLimit
; Purpose:    Set the collection limit, allocating the necessary memory on the heap to hold
;             the item POINTER table.
; Arguments:  Arg1: New limit (count).
; Return:     eax = Error code.

Method Collection.SetLimit, uses xbx xdi xsi, dNewLimit:DWORD
  ArgReg dNewLimit:edx

  SetObject xsi
  mov ebx, $ArgReg(dNewLimit)
  mov eax, [xsi].dCount
  cmp eax, ebx                                          ;dNewLimit
  ja @@1                                                ;NewLimit can not be less than dCount!
  mov eax, [xsi].dMaxCapacity
  cmp eax, ebx                                          ;NewLimit can not be > than dMaxCapacity!
  jae @@2
@@1:
  mov ebx, eax                                          ;Limit the new collection size
@@2:
  mov ecx, [xsi].dLimit
  cmp ecx, ebx
  jne @@3
  xor eax, eax                                          ;eax = OBJ_OK
  ret

@@3:
  test ebx, ebx                                         ;dNewLimit = 0 ?
  jne @@4
  MemFree [xsi].pItems, MEM_SAFE_FREE
  xor eax, eax                                          ;eax = OBJ_OK
  mov [xsi].pItems, xax                                 ;NULL
  mov [xsi].dLimit, eax                                 ;0
  ret

@@4:
  mov edi, ebx
  shl edi, $Log2(sizeof(POINTER))                       ;xdx*sizeof(POINTER)
  mov xax, [xsi].pItems
  test xax, xax
  jne @@5
  MemAlloc edi
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pItems, xax
  mov [xsi].dLimit, ebx                                 ;dNewLimit
  xor eax, eax                                          ;eax = OBJ_OK (return value)
  ret

@@5:
  MemReAlloc xax, edi
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pItems, xax
  mov [xsi].dLimit, ebx                                 ;dNewLimit
  xor eax, eax                                          ;eax = OBJ_OK (return value)
  ret

@@Error:
  mov eax, COL_OUT_OF_MEMORY                            ;Return value
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Collection.Store
; Purpose:    Store the collection in a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Collection.Store, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  ArgReg pStream:rdx

  SetObject xsi
  mov xdi, $ArgReg(pStream)
  ACall xsi.Store, $ArgReg(pStream)
  OCall xdi::Stream.BinWrite32, [xsi].dCount
  OCall xdi::Stream.BinWrite32, [xsi].dLimit
  OCall xdi::Stream.BinWrite32, [xsi].dDelta
  OCall xdi::Stream.BinWrite32, [xsi].dMaxCapacity

  mov ebx, [xsi].dCount
  mov xdi, [xsi].pItems
  test ebx, ebx
  .while !ZERO?
    OCall xsi.PutItem, pStream, POINTER ptr [xdi]
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
MethodEnd

endif
