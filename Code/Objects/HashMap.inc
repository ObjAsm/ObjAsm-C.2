; ==================================================================================================
; Title:      HashMap.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of HashMap objects.
; Notes:      Version C.1.0, January 2022
;             - First release.
; Links:      - http://libhashish.sourceforge.net/
;             - http://isthe.com/chongo/tech/comp/fnv/       in particular the FNV-1a algorithm
; ==================================================================================================


HMP_BUCKET_EMPTY      equ   0
HMP_BUCKET_TOMBSTONE  equ   -1

; --------------------------------------------------------------------------------------------------
; Object:     HashMap
; Purpose:    Base object for HashMap descendants.
;             This object implements an Unordered Associative Container.
; Note:       Items can only be accessed using the key values.
;             The Hash calculation and the collision handling is done in a descendant object.
;
;
;                              Buckets                               Items
;                             (POINTER)
;                           --------------                -----------------------------
;             pBuckets --> |  POINTER 1   | -----------> | Key | Value1 | Value2 | ... |
;                          |--------------|              |-----|--------|--------|-----|
;                          |    EMPTY     |       -----> | Key | Value1 | Value2 | ... |
;                          |--------------|      |       |-----|--------|--------|-----|
;                          |    EMPTY     |    --------> | Key | Value1 | Value2 | ... |
;                          |--------------|   |  |       |-----|--------|--------|-----|
;             Hash         |  POINTER 3   | --   |   --> | Key | Value1 | Value2 | ... |
;              AND ---     |--------------|      |  |     -----------------------------
;             Mask    |    |  TOMBSTONE   |      |  |
;            (index)  |    |--------------|      |  |
;                      --> |  POINTER 2   | -----   |
;                          |--------------|         |
;                          |  POINTER 4   | --------
;                          |--------------|
;                          |    EMPTY     |
;                           --------------
;

Object HashMap, HashMapID, Streamable
  VirtualAbstract   Delete,           POINTER
  VirtualMethod     DeleteAll
  DynamicMethod     DestroyItem,      POINTER
  VirtualMethod     Dispose,          POINTER
  VirtualMethod     DisposeAll
  RedefineMethod    Done
  VirtualAbstract   GetItemKey,       POINTER
  VirtualAbstract   Hash,             POINTER
  RedefineMethod    Init,             POINTER, DWORD
  VirtualMethod     Insert,           POINTER
  VirtualAbstract   OnCollision,      XWORD
  VirtualMethod     Resize,           DWORD                 ;Resize to new limit
  VirtualAbstract   Search,           POINTER

  DefineVariable    dBucketMaxCount,  DWORD,        0FFFFFFFFh
  DefineVariable    dBucketCount,     DWORD,        0
  DefineVariable    dBucketsUsed,     DWORD,        0
  DefineVariable    dTombstones,      DWORD,        0
  DefineVariable    dMask,            DWORD,        0
  DefineVariable    pBuckets,         POINTER,      NULL
  DefineVariable    dCollisionCount,  DWORD,        0       ;Hash performance indicator
  DefineVariable    ObjLock,          OBJECT_LOCK,  {}      ;Locking struc for multithreaded access

ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.DeleteAll
; Purpose:    Remove all item POINTERs, setting all Buckets to HMP_BUCKET_EMPTY.
;             No memory is freed!
; Arguments:  None.
; Return:     Nothing.

Method HashMap.DeleteAll
  SetObject xcx
  mov eax, [xcx].dBucketCount
  mov xdx, [xcx].pBuckets
  test eax, eax
  .while !ZERO?
    mov POINTER ptr [xdx], HMP_BUCKET_EMPTY
    add xdx, sizeof(POINTER)
    dec eax
  .endw
  m2z [xcx].dBucketsUsed
  m2z [xcx].dTombstones
  m2z [xcx].dCollisionCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    HashMap.DestroyItem
; Purpose:   Auxiliary procedure to dispose a item in the collection. Don't call directly!
; Arguments: Arg1: -> Item.
; Return:    Nothing.

Method HashMap.DestroyItem,, pItem:POINTER
  .if pItem != NULL
    MemFree pItem                                       ;Frees the Item from process heap
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.Dispose
; Purpose:    Dispose an item.
; Arguments:  Arg1: -> Key. This argument should never be NULL.
; Return:     Nothing.

Method HashMap.Dispose, uses xsi, pKey:POINTER
  ArgReg pKey:rdx

  SetObject xsi
  OCall xsi.Delete, $ArgReg(pKey)
  .if xax != NULL
    OCall xsi.DestroyItem, xax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.DisposeAll
; Purpose:    Dispose of all items in the collection.
; Arguments:  None.
; Return:     Nothing.

Method HashMap.DisposeAll, uses xbx xdi xsi
  SetObject xsi
  mov ebx, [xsi].dBucketCount
  mov xdi, [xsi].pBuckets
  test ebx, ebx
  .while !ZERO?
    mov xdx, POINTER ptr [xdi]
    .if xdx != NULL
      OCall xsi.DestroyItem, xdx
      mov POINTER ptr [xdi], HMP_BUCKET_EMPTY
    .endif
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
  m2z [xsi].dBucketsUsed
  m2z [xsi].dTombstones
  m2z [xsi].dCollisionCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.Done
; Purpose:    Destructor method.
; Arguments:  Nothing.
; Return:     None.

Method HashMap.Done, uses xsi
  SetObject xsi
  mov xax, [xsi].pBuckets
  .if xax != NULL
    MemFree xax
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.Init
; Purpose:    Initialize the HashMap object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial Bucket count. Internally it is enlarged to a power of 2.
; Return:     eax = Error code.

Method HashMap.Init, uses xsi, pOwner:POINTER, dBucketCount:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  mov eax, dBucketCount
  .if eax != 0
    dec eax
    NLPo2 eax                                             ;Calc next largest power of 2
    mov [xsi].dBucketCount, eax
    shl eax, $Log2(sizeof(POINTER))                       ;eax = Entries * sizeof(POINTER)
    MemAlloc eax, MEM_INIT_ZERO
    .if xax != NULL
      mov [xsi].pBuckets, xax
      mov ecx, [xsi].dBucketCount
      dec ecx
      mov [xsi].dMask, ecx
      xor eax, eax
    .else
      OCall xsi.ErrorReport, NULL, HMP_OUT_OF_MEMORY
    .endif
  .else
    OCall xsi.ErrorReport, NULL, HMP_INVALID_ARGUMENT
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.Insert
; Purpose:    Insert a new Item.
; Arguments:  Arg1: -> Item.
; Return:     xax = Hash or 0 if failed.

Method HashMap.Insert, uses xsi, pItem:POINTER
  ;DbgText "HashMap.Insert"
  SetObject xsi
  OCall xsi.GetItemKey, pItem
  OCall xsi.Hash, xax

  mov ecx, [xsi].dMask
  and xcx, xax                                          ;ecx is used as index into the bucket array

  mov xdx, [xsi].pBuckets
  lea xdx, [xdx + sizeof(POINTER)*xcx]
  mov xcx, POINTER ptr [xdx]
  .if xcx == HMP_BUCKET_EMPTY || xcx == HMP_BUCKET_TOMBSTONE
    m2m POINTER ptr [xdx], pItem, xcx
    inc [xsi].dBucketsUsed
  .else
    inc [xsi].dCollisionCount
    OCall xsi.OnCollision, xax                          ;On return eax = new index
    .if eax == -1
      OCall xsi.ErrorReport, NULL, HMP_MAP_FULL
      xor eax, eax
    .else
      mov xdx, [xsi].pBuckets
      mov xcx, pItem
      mov POINTER ptr [xdx + sizeof(POINTER)*xax], xcx  ;Insert
      inc [xsi].dBucketsUsed
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     HashMap.Resize
; Purpose:    Resize the HashMap, allocating the necessary memory on the heap to hold
;             the Buckets table and rehash all items
; Arguments:  Arg1: New size (Bucket Count). It must be a power of 2.
; Return:     eax = Error code.

Method HashMap.Resize, uses xbx xdi xsi, dNewSize:DWORD
  ArgReg dNewSize:edx

  DbgText "HashMap.Resize"
  SetObject xsi
  mov ebx, $ArgReg(dNewSize)
  dec ebx
  NLPo2 ebx                                             ;Calc next largest power of 2

  mov eax, [xsi].dBucketCount
  cmp eax, ebx                                          ;dNewSize

  ja @@1                                                ;NewSize can not be less than dBucketCount!
  mov eax, [xsi].dBucketMaxCount
  cmp eax, ebx                                          ;NewSize can not be > than dBucketMaxCount!
  jae @@2
@@1:
  mov ebx, eax                                          ;Limit the new collection size
@@2:
  mov ecx, [xsi].dBucketCount
  cmp ecx, ebx
  jne @@3                                               ;No change!
  xor eax, eax                                          ;eax = OBJ_OK
  ret

@@3:
  test ebx, ebx                                         ;dNewSize = 0 ?
  jne @@4
  MemFree [xsi].pBuckets, MEM_SAFE_FREE
  xor eax, eax                                          ;eax = OBJ_OK
  mov [xsi].pBuckets, xax                               ;NULL
  mov [xsi].dBucketCount, eax                           ;0
  mov [xsi].dMask, eax
  mov [xsi].dTombstones, eax
  mov [xsi].dBucketsUsed, eax
  mov [xsi].dCollisionCount, eax
  ret

@@4:
  mov xdi, [xsi].pBuckets                               ;xdi -> old POINTER table
  mov eax, ebx                                          ;ebx = new bucket count
  shl eax, $Log2(sizeof(POINTER))                       ;xdx*sizeof(POINTER)
  MemAlloc eax, MEM_INIT_ZERO
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pBuckets, xax
  mov [xsi].dBucketCount, ebx
  dec ebx
  mov [xsi].dMask, ebx
  m2z [xsi].dTombstones
  m2z [xsi].dCollisionCount
  mov ebx, [xsi].dBucketsUsed
  m2z [xsi].dBucketsUsed

  ReleaseObject
  mov xsi, xdi
  test ebx, ebx
  .while !ZERO?
    mov xdx, POINTER ptr [xdi]                          ;Load POINTER from old table
    .if xdx != HMP_BUCKET_EMPTY && xdx != HMP_BUCKET_TOMBSTONE
      OCall pSelf.Insert, xdx                           ;Insert it in the new table
      add xdi, sizeof(POINTER)                          ;Move to next bucket
      dec xbx
    .else
      add xdi, sizeof(POINTER)                          ;ZERO is never set
    .endif
  .endw
  MemFree xsi
  xor eax, eax
  ret

@@Error:
  mov eax, COL_OUT_OF_MEMORY                            ;Return value
MethodEnd

endif
