; ==================================================================================================
; Title:      DataVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of DataVector object.
; Notes:      Version C.1.0, February 2024
;               - First release
; ==================================================================================================


PDataVecProc  typedef proto :POINTER, :XWORD, :XWORD      ;If required, return value stored in eax

; --------------------------------------------------------------------------------------------------
; Object:     DataVector
; Purpose:    DataVector is an container whose Item capacity ist larger than a XWORD.
;             Vectors with a smaller item size have dedicated objects that implement specific code
;             for that item size.
;             Since the data size can be different for each object instance, it it stored as a0
;             object variable.
;             The implementation supports all collection-like features, but not Item serialisation
;             and destruction, as these are not needed for data items.
;
; Example:    New DataVector
;             OCall xax::DataVector.Init, NULL, DataStrucSize, 10, 10, 0FFFFFFFFh/DataStrucSize

Object DataVector, DataVectorID, Vector
  RedefineMethod    Delete,         POINTER
  RedefineMethod    DeleteAt,       DWORD                 ;Index in range [0..Count-1]
  RedefineMethod    DeleteAll
  RedefineMethod    Done
  RedefineMethod    FirstThat,      POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    FirstThatNot,   POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    ForEach,        POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter
  RedefineMethod    ForEachRev,     POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter, reverse order
  RedefineMethod    IndexOf,        POINTER
  RedefineMethod    Init,           POINTER, DWORD, DWORD, DWORD, DWORD ;-> Owner, ItemSize, ...
  RedefineMethod    Insert,         POINTER               ;-> Item
  RedefineMethod    InsertAt,       DWORD, POINTER        ;Index, -> Item
  RedefineMethod    ItemAt,         DWORD                 ;Index in range [0..Count-1]
  RedefineMethod    LastThat,       POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    LastThatNot,    POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    PutAt,          DWORD, POINTER        ;Index, -> Item
  RedefineMethod    Store,          $ObjPtr(Stream)       ;-> Stream
  Private
  RedefineMethod    SetLimit,       DWORD                 ;Set new limit (private method)

  DefineVariable    dItemSize,      DWORD,        0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.Delete
; Purpose:    Delete an Item from the Vector.
; Arguments:  Arg1: -> Item.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method DataVector.Delete, uses xsi, pItem:POINTER
  ArgReg pItem:rdx

  SetObject xsi
  OCall xsi.IndexOf, $ArgReg(pItem)
  OCall xsi.DeleteAt, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.DeleteAt
; Purpose:    Delete the Item(Index) from the Vector.
; Arguments:  Arg1: Index value.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method DataVector.DeleteAt, uses xdi xsi, dIndex:DWORD
  ArgReg dIndex:edx

  SetObject xsi
  mov ecx, [xsi].dCount
  .if $ArgReg(dIndex) < ecx
    dec ecx
    mov eax, $ArgReg(dIndex)
    mov [xsi].dCount, ecx
    sub ecx, eax
    .if !ZERO?
      mov ecx, [xsi].dItemSize
      mul ecx
      mov edx, [xsi].dCount
      sub edx, dIndex
      add xax, [xsi].pItems
      mov xdi, xax
      lea xsi, [xax + xcx]
      mov eax, edx
      mul ecx
      mov ecx, eax
      if TARGET_BITNESS eq 64
        shr ecx, $Log2(sizeof(QWORD))
        rep movsq
        test eax, BIT02
        jz @F
        movsd
      else
        shr ecx, $Log2(sizeof(DWORD))
        rep movsd
      endif
    @@:
      test eax, BIT01
      jz @F
      movsw
    @@:
      test eax, BIT00
      jz @F
      movsb
    @@:
    .endif
    mov eax, TRUE
  .else
    OCall xsi.ErrorReport, NULL, VEC_INDEX_ERROR
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.DeleteAll
; Purpose:    Delete all Items.
; Arguments:  None.
; Return:     Nothing.

Method DataVector.DeleteAll
  SetObject xcx
  m2z [xcx].dCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.Done
; Purpose:    Delete and disposes of all the Items in the Vector.
; Arguments:  None.
; Return:     Nothing.

Method DataVector.Done, uses xsi
  SetObject xsi
  .if [xsi].pItems != NULL
    OCall xsi.DeleteAll
    MemFree [xsi].pItems
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.FirstThat
; Purpose:    Search the first Item that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.
; Note:       The coding praxis has shown, that max 2 args must be passed to the callee.

Method DataVector.FirstThat, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  SetObject xsi
  mov ebx, [xsi].dCount
  .if ebx != 0
    mov xdi, [xsi].pItems
    .repeat
      invoke PDataVecProc ptr pTestFunc, xdi, xArg1, xArg2
      test xax, xax                                     ;Check return value for TRUE
      jnz @F
      mov eax, [xsi].dItemSize
      add xdi, xax                                      ;xdi -> Next Item in the Vector
      dec ebx
    .until ZERO?
  .endif
  xor edi, edi                                          ;In case that dCount = 0
@@:
  mov xax, xdi                                          ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.FirstThatNot
; Purpose:    Search the first Item that returns FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.

Method DataVector.FirstThatNot, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  SetObject xsi
  mov ebx, [xsi].dCount
  .if ebx != 0
    mov xdi, [xsi].pItems
    .repeat
      invoke PDataVecProc ptr pTestFunc, xdi, xArg1, xArg2
      test xax, xax                                     ;Check return value for FALSE
      jz @F
      mov eax, [xsi].dItemSize
      add xdi, xax                                      ;xdi -> Next Item in the Vector
      dec ebx
    .until ZERO?
  .endif
  xor edi, edi                                          ;In case that dCount = 0
@@:
  mov xax, xdi                                          ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.ForEach
; Purpose:    Call Action for each Item in the Vector.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the callee.
; Return:     Nothing.
; Note:       While the loop is running, no Item must be deleted!

Method DataVector.ForEach, uses xbx xdi xsi, pActionProc:POINTER, xArg1:XWORD, xArg2:XWORD
  SetObject xsi
  mov ebx, [xsi].dCount
  mov xdi, [xsi].pItems
  test ebx, ebx
  .while !ZERO?
    invoke PDataVecProc ptr pActionProc, xdi, xArg1, xArg2
    mov eax, [xsi].dItemSize
    add xdi, xax                                        ;xdi -> Next Item in the Vector
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.ForEachRev
; Purpose:    Call Action for each Item in the Vector in reverse order.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the callee.
; Return:     Nothing.
; Note:       While the loop is running, no Item must be deleted!

Method DataVector.ForEachRev, uses xbx xdi xsi, pActionProc:POINTER, xArg1:XWORD, xArg2:XWORD
  SetObject xsi
  mov ebx, [xsi].dCount
  mov eax, [xsi].dItemSize
  mul ebx
  add xax, [xsi].pItems
  mov xdi, xax
  test ebx, ebx
  .while !ZERO?
    mov eax, [xsi].dItemSize
    sub xdi, xax                                        ;xdi -> Prev Item in the Vector
    invoke PDataVecProc ptr pActionProc, xdi, xArg1, xArg2
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.IndexOf
; Purpose:    Return the index of an Item in the Vector in the range [0..Count-1].
; Arguments:  Arg1: -> Item.
; Return:     eax = Index. If the xItem wasn't found, the return value is -1!

Method DataVector.IndexOf, uses xbx xdi xsi, pItem:POINTER
  SetObject xsi
  ?mov xdx, pItem
  mov xbx, [xsi].pItems
  mov ecx, [xsi].dItemSize
  mov edi, [xsi].dCount
  xor eax, eax
  .while eax != edi
    cmp xbx, xdx
    jz @@EOM
    add xbx, xcx                                      ;xbx -> Next Item in the Vector
    inc eax
  .endw
@@:
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.Init
; Purpose:    Initialize the Vector with a limit (dLimit), an increasing step (dDelta)
;             and a maximum size (dMaxCapacity).
; Arguments:  Arg1: -> Owner object.
;             Arg2: Item size in BYTEs.
;             Arg3: Initial capacity of the Vector (# of xItems).
;             Arg4: Growing factor of the Vector (# of xItems).
;             Arg5: Maximum capacity of the Vector (# of xItems).
; Return:     eax = Error code.

Method DataVector.Init, uses xsi, pOwner:POINTER, dItemSize:DWORD, \
                                  dLimit:DWORD, dDelta:DWORD, dMaxCapacity:DWORD
  ArgReg pOwner:rdx

  SetObject xsi
  ACall xsi.Init, $ArgReg(pOwner)
  m2m [xsi].dItemSize, dItemSize, eax
  xor eax, eax
  mov [xsi].pItems, xax
  mov [xsi].dCount, eax
  mov [xsi].dLimit, eax
  mov [xsi].dErrorCode, OBJ_OK
  m2m [xsi].dDelta, dDelta, edx
  m2m [xsi].dMaxCapacity, dMaxCapacity, edx
  mov eax, dLimit
  .if eax <= edx
    OCall xsi.SetLimit, eax
    .if eax != OBJ_OK
      OCall xsi.ErrorReport, NULL, eax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, VEC_SETUP_ERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.Insert
; Purpose:    Insert xItem at the end of the Vector.
; Arguments:  Arg1: -> New Item.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method DataVector.Insert, uses xdi xsi, pItem:POINTER
  SetObject xsi
  mov edx, [xsi].dCount
  .if edx == [xsi].dLimit
    add edx, [xsi].dDelta
    OCall xsi.SetLimit, edx                             ;edx = new limit
    test eax, eax                                       ;Check for OBJ_OK
    jnz @@Error
    mov edx, [xsi].dCount
    cmp edx, [xsi].dLimit
    mov eax, VEC_OVERFLOW
    jz @@Error
  .endif
  inc [xsi].dCount

  mov eax, [xsi].dItemSize
  mov xdi, [xsi].pItems
  mov ecx, eax
  mul edx
  add xdi, xax
  mov xsi, pItem
  mov eax, ecx
  if TARGET_BITNESS eq 64
    shr ecx, $Log2(sizeof(QWORD))
    rep movsq
    test eax, BIT02
    jz @F
    movsd
  else
    shr ecx, $Log2(sizeof(DWORD))
    rep movsd
  endif
@@:
  test eax, BIT01
  jz @F
  movsw
@@:
  test eax, BIT00
  jz @F
  movsb
@@:
  mov eax, TRUE
  ret
@@Error:
  OCall xsi.ErrorReport, NULL, eax
  xor eax, eax                                          ;Return FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.InsertAt
; Purpose:    Insert an Item at index position shifting the remaining xItems.
; Arguments:  Arg1: Index value [0..Count].
;             Arg2: -> New Item.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method DataVector.InsertAt, uses xbx xdi xsi, dIndex:DWORD, pItem:POINTER
  SetObject xbx
  mov ecx, [xbx].dCount
  .if ecx == [xbx].dLimit
    mov esi, [xbx].dLimit                               ;Remember old limit
    mov edx, ecx
    add edx, [xbx].dDelta
    OCall xbx.SetLimit, edx
    cmp esi, [xbx].dLimit
    je @@1                                              ;No change => Overflow
    mov ecx, [xbx].dCount
  .endif

  mov eax, dIndex
  .if eax <= ecx                                        ;ecx = dCount
    inc [xbx].dCount
    .if eax != ecx
      mov eax, ecx
      mul [xbx].dItemSize
      mov esi, eax
      add xsi, [xbx].pItems

      mov eax, ecx
      sub eax, dIndex                                   ;ecx = # of Items to move
      mul [xbx].dItemSize
      mov ecx, eax

      mov edi, [xbx].dItemSize
      add xdi, xsi

      std
      if TARGET_BITNESS eq 64
        sub xdi, sizeof(QWORD)
        sub xsi, sizeof(QWORD)
        .ifAnyBitSet eax, 011111111111111111111111111111000y
          shr ecx, $Log2(sizeof(QWORD))
          rep movsq
        .endif

        add xdi, sizeof(DWORD)
        add xsi, sizeof(DWORD)
        .ifBitSet eax, BIT02
          movsd
        .endif
      else
        sub xdi, sizeof(DWORD)
        sub xsi, sizeof(DWORD)
        .ifAnyBitSet eax, 011111111111111111111111111111100y
          shr ecx, $Log2(sizeof(DWORD))
          rep movsd
        .endif
      endif
      add xdi, sizeof(WORD)
      add xsi, sizeof(WORD)
      .ifBitSet eax, BIT01
        movsw
      .endif
      add xdi, sizeof(BYTE)
      add xsi, sizeof(BYTE)
      .ifBitSet eax, BIT00
        movsb
      .endif
      cld
    .endif
    mov eax, dIndex
    mul [xbx].dItemSize
    add xax, [xbx].pItems
    mov xsi, pItem
    mov xdi, xax
    mov ecx, [xbx].dItemSize
    mov eax, ecx
    if TARGET_BITNESS eq 64
      shr ecx, $Log2(sizeof(QWORD))
      rep movsq
      test eax, BIT02
      jz @F
      movsd
    else
      shr ecx, $Log2(sizeof(DWORD))
      rep movsd
    endif
  @@:
    test eax, BIT01
    jz @F
    movsw
  @@:
    test eax, BIT00
    jz @F
    movsb
  @@:
    mov eax, TRUE
    ret
  .endif
  mov eax, VEC_INDEX_ERROR
  jmp @@2
@@1:
  mov eax, VEC_OVERFLOW
@@2:
  OCall xbx.ErrorReport, NULL, eax
  xor eax, eax                                          ;Return NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.ItemAt
; Purpose:    Return a POINTER to an Item(Index).
; Arguments:  Arg1: Index in range [0..Count-1].
; Return:     xax -> Item. On error it returns NULL.

Method DataVector.ItemAt,, dIndex:DWORD
  SetObject xcx
  ?mov edx, dIndex
  .if edx < [xcx].dCount
    mov eax, [xcx].dItemSize
    mul edx
    add xax, [xcx].pItems
  .else
    OCall xcx.ErrorReport, NULL, VEC_INDEX_ERROR
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.LastThat
; Purpose:    Search the last Item that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static address) Function that evaluates to TRUE or FALSE (eax = return val).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.

Method DataVector.LastThat, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov ebx, [xcx].dCount
  .if ebx != 0                                          ;Early exit
    mov edi, [xcx].dItemSize
    mov eax, edi
    mul ebx
    add xax, [xcx].pItems
    mov xsi, xax
    ReleaseObject
    test ebx, ebx
    .repeat
      sub xsi, xdi                                      ;xsi -> previous Item in the Vector
      invoke PDataVecProc ptr pTestFunc, xsi, xArg1, xArg2
      test xax, xax                                     ;Check return value for TRUE
      jnz @F
      dec ebx
    .until ZERO?                                        ;At the end of the loop, ebx = 0
  .endif
  xor esi, esi                                          ;In case that dCount = 0
@@:
  mov xax, xsi                                          ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.LastThatNot
; Purpose:    Search the last Item that returns FALSE in eax.
; Arguments:  Arg1: -> (static address) Function that evaluates to TRUE or FALSE (eax = return val).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> Item or NULL if not found.

Method DataVector.LastThatNot, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov ebx, [xcx].dCount
  .if ebx != 0                                          ;Early exit
    mov edi, [xcx].dItemSize
    mov eax, edi
    mul ebx
    add xax, [xcx].pItems
    mov xsi, xax
    ReleaseObject
    test ebx, ebx
    .repeat
      sub xsi, xdi                                      ;xsi -> previous Item in the Vector
      invoke PDataVecProc ptr pTestFunc, xsi, xArg1, xArg2
      test xax, xax                                     ;Check return value for FALSE
      jz @F
      dec ebx
    .until ZERO?                                        ;At the end of the loop, ebx = 0
  .endif
  xor esi, esi                                          ;In case that dCount = 0
@@:
  mov xax, xsi                                          ;xax -> Item
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.Load
; Purpose:    Load and initializes the Vector from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method DataVector.Load, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  ArgReg pStream:rdx, pDeserInfo:r8

  SetObject xsi
  ACall xsi.Load, $ArgReg(pStream), $ArgReg(pDeserInfo)
  .if [xsi].dErrorCode == OBJ_OK
    OCall pStream::Stream.BinRead32
    mov [xsi].dItemSize, eax
    mul [xsi].dCount
    OCall pStream::Stream.BinRead, [xsi].pItems, eax
  .endif
  ret
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.PutAt
; Purpose:    Overwrite an Item at index position.
; Arguments:  Arg1: Index value.
;             Arg2: -> New Item.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method DataVector.PutAt, uses xdi xsi, dIndex:DWORD, pItem:POINTER
  SetObject xsi
  ?mov edx, dIndex
  .if edx < [xsi].dCount
    mov eax, [xsi].dItemSize
    mov ecx, eax
    mul edx
    add xax, [xsi].pItems
    mov xdi, xax
    mov xsi, pItem
    mov eax, ecx

    if TARGET_BITNESS eq 64
      shr ecx, $Log2(sizeof(QWORD))
      rep movsq
      test eax, BIT02
      jz @F
      movsd
    else
      shr ecx, $Log2(sizeof(DWORD))
      rep movsd
    endif
  @@:
    test eax, BIT01
    jz @F
    movsw
  @@:
    test eax, BIT00
    jz @F
    movsb
  @@:

    mov eax, TRUE
  .else
    OCall xsi.ErrorReport, NULL, VEC_INDEX_ERROR
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.SetLimit
; Purpose:    Set the Vector limit, allocating the necessary memory on the process heap to hold
;             all Items.
; Arguments:  Arg1: New limit (Item count).
; Return:     eax = Error code.

Method DataVector.SetLimit, uses xbx xdi xsi, dNewLimit:DWORD
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
  mov ebx, eax                                          ;Limit the new Vector size
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
  mov eax, ebx
  mul [xsi].dItemSize
  mov xcx, [xsi].pItems
  test xcx, xcx
  jne @@5
  MemAlloc eax
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pItems, xax
  mov [xsi].dLimit, ebx                                 ;dNewLimit
  xor eax, eax                                          ;eax = OBJ_OK (return value)
  ret

@@5:
  mov xdi, xcx
  MemReAlloc xdi, eax
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pItems, xax
  mov [xsi].dLimit, ebx                                 ;dNewLimit
  xor eax, eax                                          ;eax = OBJ_OK (return value)
  ret

@@Error:
  mov eax, VEC_OUT_OF_MEMORY                            ;Return value
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataVector.Store
; Purpose:    Store the Vector in a Stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method DataVector.Store, uses xdi xsi, pStream:$ObjPtr(Stream)
  ArgReg pStream:rdx

  SetObject xsi
  mov xdi, $ArgReg(pStream)
  ACall xsi.Store, $ArgReg(pStream)
  OCall xdi::Stream.BinWrite32, [xsi].dItemSize
  mov eax, [xsi].dCount
  mul [xsi].dItemSize
  OCall xdi::Stream.BinWrite, [xsi].pItems, eax
MethodEnd

endif
