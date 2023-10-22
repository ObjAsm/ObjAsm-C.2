; ==================================================================================================
; Title:      TVector.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of TVector object templates.
; Notes:      Version C.1.0, September 2021
;               - First release.
;             Version C.1.1, October 2023
;               - .VecForEach, .VecForEachRev and .VecNext macros added.
; ==================================================================================================


% PVecProc typedef proto :TVEC_DATA_TYPE, :XWORD, :XWORD

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     TVector
; Purpose:    TVector is a template for a BYTE, WORD, DWORD or QWORD data item container.
;             The data size is defined at compile time using e.g. TVEC_DATA_TYPE typedef DWORD.
;             This implementation does support all Collection like features but not xItem
;             serialization and destruction, since they are not needed for data items.
; Note:       A QWORD Vector is only supported if TARGET_BITNESS eq 64.

%Object TVectorName, TVectorID, Streamable
  VirtualMethod     Delete,         TVEC_DATA_TYPE        ;xItem
  VirtualMethod     DeleteAt,       DWORD                 ;Index in range [0..Count-1]
  VirtualMethod     DeleteAll
  RedefineMethod    Done
  VirtualMethod     FirstThat,      POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualMethod     FirstThatNot,   POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualMethod     ForEach,        POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter
  VirtualMethod     ForEachRev,     POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter, reverse order
  VirtualMethod     IndexOf,        TVEC_DATA_TYPE        ;xItem
  RedefineMethod    Init,           POINTER, DWORD, DWORD, DWORD ;-> Owner, Count, Delta, Max Capa.
  VirtualMethod     Insert,         TVEC_DATA_TYPE        ;xItem
  VirtualMethod     InsertAt,       DWORD, TVEC_DATA_TYPE ;Index, xItem
  VirtualMethod     ItemAt,         DWORD                 ;Index in range [0..Count-1]
  VirtualMethod     LastThat,       POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualMethod     LastThatNot,    POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     PutAt,          DWORD, TVEC_DATA_TYPE ;Index, xItem
  RedefineMethod    Store,          $ObjPtr(Stream)       ;-> Stream
  Private
  VirtualMethod     SetLimit,       DWORD                 ;Set new limit (private method)

  DefineVariable    pItems,         POINTER,      NULL
  DefineVariable    dCount,         DWORD,        0
  DefineVariable    dLimit,         DWORD,        0
  DefineVariable    dDelta,         DWORD,        0
  DefineVariable    dMaxCapacity,   DWORD,        0
  DefineVariable    ObjLock,        OBJECT_LOCK,  {}    ;Locking structure for multithreaded access
ObjectEnd


; ==================================================================================================

??VecForEach_ID = 0

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .VecForEach
; Purpose:    Loop through all items of the TVector.
; Arguments:  Arg1: TVector.
;             Arg2: Optional 32 bit index variable/register. Can not be eax!
; Return:     Nothing.
; Note:       On each loop $SubReg(xax) = TVector item.
; Example:    .VecForEach MyVector
;               DbgDec xax
;             .VecNext

.VecForEach macro Coll:req, Index
  ??VecForEach_ID = ??VecForEach_ID + 1
  @CatStr(<??VecForEach_ItemReg_>, %??VecForEach_ID) textequ <ItemReg>
  @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID) textequ GetMemBSS(4)
  ifb <Index>
    @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID) textequ GetMemBSS(4)
  else
    @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID) textequ <Index>
  endif
  @CatStr(<??VecForEach_Step_>, %??VecForEach_ID) equ +1 
  xor eax, eax
  mov @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID), eax
  .while eax != Coll.$Obj(Collection).dCount
    lea xax, [sizeof(TVEC_DATA_TYPE)*xax]
    add xax, Coll.$Obj(Collection).pItems
    mov $SubReg(xax, sizeof(TVEC_DATA_TYPE)), TVEC_DATA_TYPE ptr [xax]
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .VecForEach
; Purpose:    Loop through all items of the TVector in reverse order.
; Arguments:  Arg1: TVector.
;             Arg2: Optional 32 bit index variable/register. Can not be eax!
; Return:     Nothing.
; Note:       On each loop $SubReg(xax) = TVector item.

.VecForEachRev macro Coll:req, Index
  ??VecForEach_ID = ??VecForEach_ID + 1
  @CatStr(<??VecForEach_ItemReg_>, %??VecForEach_ID) textequ <ItemReg>
  ifb <Index>
    @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID) textequ GetMemBSS(4)
  else
    @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID) textequ <Index>
  endif
  @CatStr(<??VecForEach_Step_>, %??VecForEach_ID) equ -1 
  mov eax, Coll.$Obj(Collection).dCount
  mov @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID), eax
  .while eax != 0
    lea xax, [sizeof(TVEC_DATA_TYPE)*xax - sizeof(TVEC_DATA_TYPE)]
    add xax, Coll.$Obj(Collection).pItems
    mov $SubReg(xax, sizeof(TVEC_DATA_TYPE)), TVEC_DATA_TYPE ptr [xax]
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .VecNext
; Purpose:    Move to the next TVector item.
; Arguments:  None
; Return:     Nothing.

.VecNext macro
    if @CatStr(<??VecForEach_Step_>, %??VecForEach_ID) eq +1
      inc @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID)
    else
      dec @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID)
    endif
    mov eax, @CatStr(<??VecForEach_Counter_>, %??VecForEach_ID)
  .endw
  ??VecForEach_ID = ??VecForEach_ID - 1
endm


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.Delete
; Purpose:    Delete an xItem from the Vector.
; Arguments:  Arg1: xItem.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

%Method TVectorName.Delete, uses xsi, xItem:TVEC_DATA_TYPE
  ArgReg xItem:$SubReg(rdx, type(TVEC_DATA_TYPE))

  SetObject xsi
  OCall xsi.IndexOf, $ArgReg(xItem)
  OCall xsi.DeleteAt, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.DeleteAt
; Purpose:    Delete the xItem(Index) from the Vector.
; Arguments:  Arg1: Index value.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

%Method TVectorName.DeleteAt, uses xdi xsi, dIndex:DWORD
  ArgReg dIndex:edx

  SetObject xdi
  mov ecx, [xdi].dCount
  .if $ArgReg(dIndex) < ecx
    dec ecx
    mov eax, $ArgReg(dIndex)
    mov [xdi].dCount, ecx
    sub ecx, eax
    .if !ZERO?
      mov xsi, [xdi].pItems
      lea xdi, [xsi + sizeof(TVEC_DATA_TYPE)*xax]
      shl ecx, $Log2(sizeof(TVEC_DATA_TYPE))            ;ecx = byte count
      lea xsi, [xdi + sizeof(TVEC_DATA_TYPE)]
      mov eax, ecx
      if TARGET_BITNESS eq 64
        shr ecx, $Log2(sizeof(QWORD))
        rep movsq
        if type(TVEC_DATA_TYPE) lt type(QWORD)
          test eax, BIT02
          jz @F
          movsd
        endif
      else
        shr ecx, $Log2(sizeof(DWORD))
        rep movsd
      endif

      if type(TVEC_DATA_TYPE) lt type(DWORD)
      @@:
        test eax, BIT01
        jz @F
        movsw
        if type(TVEC_DATA_TYPE) lt type(WORD)
        @@:
          test eax, BIT00
          jz @F
          movsb
        endif
      endif
      @@:
    .endif
    mov eax, TRUE
  .else
    OCall xdi.ErrorReport, NULL, COL_INDEX_ERROR
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.DeleteAll
; Purpose:    Delete all xItems.
; Arguments:  None.
; Return:     Nothing.

%Method TVectorName.DeleteAll
  SetObject xcx
% m2z [xcx].$Obj(TVectorName).dCount
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.Done
; Purpose:    Delete and disposes of all the xItems in the Vector.
; Arguments:  None.
; Return:     Nothing.

%Method TVectorName.Done, uses xsi
  SetObject xsi
  .if [xsi].pItems != NULL
    OCall xsi.DeleteAll
    MemFree [xsi].pItems
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.FirstThat
; Purpose:    Search the first xItem that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> xItem or NULL if not found.
; Note:       The coding praxis has shown, that max 2 args must be passed to the callee.

%Method TVectorName.FirstThat, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov ebx, [xcx].dCount
  mov xsi, [xcx].pItems
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
%   invoke PVecProc ptr xdi, TVEC_DATA_TYPE ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jnz @F
    add xsi, sizeof(TVEC_DATA_TYPE)                     ;xsi -> Next xItem in the Vector
    dec ebx
  .endw
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, xsi                                          ;xax -> xItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.FirstThatNot
; Purpose:    Search the first xItem that returns FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> xItem or NULL if not found.

%Method TVectorName.FirstThatNot, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov ebx, [xcx].dCount
  mov xsi, [xcx].pItems
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
%   invoke PVecProc ptr xdi, TVEC_DATA_TYPE ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jz @F
    add xsi, sizeof(TVEC_DATA_TYPE)                     ;xsi -> Next xItem in the Vector
    dec ebx
  .endw
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, xsi                                          ;xax -> xItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.ForEach
; Purpose:    Call Action for each xItem in the Vector.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the callee.
; Return:     Nothing.
; Note:       While the loop is running, no xItem must be deleted!

%Method TVectorName.ForEach, uses xbx xdi xsi, pActionProc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pActionProc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pActionProc)
  mov ebx, [xcx].dCount
  mov xsi, [xcx].pItems
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
%   invoke PVecProc ptr xdi, TVEC_DATA_TYPE ptr [xsi], xArg1, xArg2
    add xsi, sizeof(TVEC_DATA_TYPE)                     ;xsi -> Next xItem in the Vector
    dec ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.ForEachRev
; Purpose:    Call Action for each xItem in the Vector in reverse order.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the callee.
; Return:     Nothing.
; Note:       While the loop is running, no xItem must be deleted!

%Method TVectorName.ForEachRev, uses xbx xdi xsi, pActionProc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pActionProc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pActionProc)
  mov xax, [xcx].pItems
  mov ebx, [xcx].dCount
  lea xsi, [xax + sizeof(TVEC_DATA_TYPE)*xbx - sizeof(TVEC_DATA_TYPE)]  ;xsi -> Last xItem in the Vector
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
%   invoke PVecProc ptr xdi, TVEC_DATA_TYPE ptr [xsi], xArg1, xArg2
    sub xsi, sizeof(TVEC_DATA_TYPE)                            ;xsi -> Next xItem in the Vector
    dec ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.IndexOf
; Purpose:    Return the index of an xItem in the Vector in the range [0..Count-1].
; Arguments:  Arg1: xItem.
; Return:     eax = Index. If the xItem wasn't found, the return value is -1!

%Method TVectorName.IndexOf, uses xdi, xItem:TVEC_DATA_TYPE
  SetObject xdx
  mov ecx, [xdx].dCount
  jecxz @F
  mov xdi, [xdx].pItems
  mov $SubReg(xax, type(TVEC_DATA_TYPE)), xItem
  if type(TVEC_DATA_TYPE) eq 1
    repne scasb
  elseif type(TVEC_DATA_TYPE) eq 2
    repne scasw
  elseif type(TVEC_DATA_TYPE) eq 4
    repne scasd
  elseif type(TVEC_DATA_TYPE) eq 8
    repne scasq
  else
    echo TVEC_DATA_TYPE not supported
  endif
  jne @F
  mov eax, [xdx].dCount
  sub eax, ecx
  dec eax
  ret
@@:
  mov eax, -1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.Init
; Purpose:    Initialize the Vector with a limit (dLimit), an increasing step (dDelta)
;             and a maximum size (dMaxCapacity).
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the Vector (# of xItems).
;             Arg3: Growing factor of the Vector (# of xItems).
;             Arg4: Maximum capacity of the Vector (# of xItems).
;                   Use VEC??_MAX_CAPACITY to indicate no limit.
; Return:     eax = Error code.

%Method TVectorName.Init, uses xsi, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dMaxCapacity:DWORD
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
    mov edx, 0FFFFFFFFh/sizeof(TVEC_DATA_TYPE)
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.Insert
; Purpose:    Insert xItem at the end of the Vector.
; Arguments:  Arg1: New xItem.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

%Method TVectorName.Insert, uses xsi, xItem:TVEC_DATA_TYPE
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
  mrm [xcx + sizeof(TVEC_DATA_TYPE)*xdx], xItem, xax
  mov eax, TRUE
  ret
@@:
  OCall xsi.ErrorReport, NULL, eax
  xor eax, eax                                          ;Return FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.InsertAt
; Purpose:    Insert an xItem at index position shifting the remaining xItems.
; Arguments:  Arg1: Index value [0..Count].
;             Arg2: New xItem.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

%Method TVectorName.InsertAt, uses xdi xsi, dIndex:DWORD, xItem:TVEC_DATA_TYPE
  ArgReg xItem:$SubReg(r8, type(TVEC_DATA_TYPE))

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

  mov eax, dIndex
  .if eax <= ecx
    inc [xdi].dCount
    sub ecx, eax                                        ;ecx = # of xItems to move
    .if !ZERO?                                          ;Make room for new xItem
      std
      mov xsi, [xdi].pItems
      lea xdx, [xsi + xax*sizeof(TVEC_DATA_TYPE)]
      if type(TVEC_DATA_TYPE) gt type(BYTE)
        lea xax, [xcx*sizeof(TVEC_DATA_TYPE)]             ;xax = BYTE count
        mov xcx, xax
      else
        mov xax, xcx
      endif

      if TARGET_BITNESS eq 64
        lea xsi, [xdx + xax - sizeof(QWORD)]
        shr ecx, $Log2(sizeof(QWORD))
        lea xdi, [xsi + sizeof(TVEC_DATA_TYPE)]
        rep movsq
        if type(TVEC_DATA_TYPE) lt type(QWORD)
          add xdi, sizeof(DWORD)
          add xsi, sizeof(DWORD)
          .ifBitSet eax, BIT02
            movsd
          .endif
        endif
      else
        lea xsi, [xdx + xax - sizeof(DWORD)]
        shr ecx, $Log2(sizeof(DWORD))
        lea xdi, [xsi + sizeof(TVEC_DATA_TYPE)]
        rep movsd
      endif
      if type(TVEC_DATA_TYPE) lt type(DWORD)
        add xdi, sizeof(WORD)
        add xsi, sizeof(WORD)
        .ifBitSet eax, BIT01
          movsw
        .endif
        if type(TVEC_DATA_TYPE) lt type(WORD)
          add xdi, sizeof(BYTE)
          add xsi, sizeof(BYTE)
          .ifBitSet eax, BIT00
            movsb
          .endif
        endif
      endif
      cld

      m2m [xdx], $ArgReg(xItem), xax

    .endif
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.ItemAt
; Purpose:    Return a POINTER to an xItem(Index).
; Arguments:  Arg1: Index in range [0..Count-1].
; Return:     xax -> xItem. On error it returns NULL.

%Method TVectorName.ItemAt,, dIndex:DWORD
  SetObject xcx
  ?mov edx, dIndex
  .if edx < [xcx].dCount
    mov xcx, [xcx].pItems
    lea xax, [xcx + sizeof(TVEC_DATA_TYPE)*xdx]         ;xax -> xItem
  .else
    OCall xcx.ErrorReport, NULL, COL_INDEX_ERROR
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.LastThat
; Purpose:    Search the last xItem that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static address) Function that evaluates to TRUE or FALSE (eax = return val).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> xItem or NULL if not found.

%Method TVectorName.LastThat, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov xax, [xcx].pItems
  mov ebx, [xcx].dCount
  lea xsi, [xax + sizeof(TVEC_DATA_TYPE)*xbx - sizeof(TVEC_DATA_TYPE)];xsi -> Last xItem in the Vector
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
%   invoke PVecProc ptr xdi, TVEC_DATA_TYPE ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jnz @F
    sub xsi, sizeof(TVEC_DATA_TYPE)                     ;xsi -> previous xItem in the Vector
    dec ebx
  .endw                                                 ;At the end of the loop, xax = 0
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, xsi                                          ;xax -> xItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.LastThatNot
; Purpose:    Search the last xItem that returns FALSE in eax.
; Arguments:  Arg1: -> (static address) Function that evaluates to TRUE or FALSE (eax = return val).
;             Arg2-3: Parameters to be used by the callee.
; Return:     xax -> xItem or NULL if not found.

%Method TVectorName.LastThatNot, uses xbx xdi xsi, pTestFunc:POINTER, xArg1:XWORD, xArg2:XWORD
  ArgReg pTestFunc:rdx

  SetObject xcx
  mov xdi, $ArgReg(pTestFunc)
  mov xax, [xcx].pItems
  mov ebx, [xcx].dCount
  lea xsi, [xax + sizeof(TVEC_DATA_TYPE)*xbx - sizeof(TVEC_DATA_TYPE)]  ;xsi -> Last xItem in the Vector
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
%   invoke PVecProc ptr xdi, TVEC_DATA_TYPE ptr [xsi], xArg1, xArg2
    test xax, xax                                       ;Check return value for FALSE
    jz @F
    sub xsi, sizeof(TVEC_DATA_TYPE)                     ;xsi -> previous xItem in the Vector
    dec ebx
  .endw                                                 ;At the end of the loop, xax = 0
  xor eax, eax                                          ;In case that dCount = 0
  jmp @@EOM                                             ;Nothing found => return NULL
@@:
  mov xax, xsi                                          ;xax -> xItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.Load
; Purpose:    Load and initializes the Vector from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

%Method TVectorName.Load, uses xbx xdi xsi r12, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  ArgReg pStream:rdx, pDeserInfo:r8
  LocReg dLimit:r12d

  SetObject xsi
  ACall xsi.Load, $ArgReg(pStream), $ArgReg(pDeserInfo)
  OCall pStream::Stream.BinRead32                       ;Read count
  mov edi, eax                                          ;edi = Count
  OCall pStream::Stream.BinRead32                       ;Read dLimit
  mov $LocReg(dLimit), eax

  OCall pStream::Stream.BinRead32                       ;Read dDelta
  mov [xsi].dDelta, eax
  OCall pStream::Stream.BinRead32                       ;Read dMaxCapacity
  mov [xsi].dMaxCapacity, eax

  xor eax, eax
  mov [xsi].pItems, xax
  mov [xsi].dCount, eax
  mov [xsi].dLimit, eax
  OCall xsi.SetLimit, $LocReg(dLimit)
  test eax, eax                                         ;Test for OBJ_OK
  jne @@Error
  mov [xsi].dCount, edi
  OCall pStream::Stream.BinRead, [xsi].pItems, addr [sizeof(TVEC_DATA_TYPE)*edi]
  ret
@@Error:
  OCall xsi.ErrorReport, NULL, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.PutAt
; Purpose:    Overwrite an xItem at index position.
; Arguments:  Arg1: Index value.
;             Arg2: New xItem.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

%Method TVectorName.PutAt,, dIndex:DWORD, xItem:TVEC_DATA_TYPE
  ArgReg xItem:$SubReg(r8, type(TVEC_DATA_TYPE))

  SetObject xcx
  ?mov edx, dIndex
  .if edx < [xcx].dCount
    mov xcx, [xcx].pItems
    m2m [xcx + sizeof(TVEC_DATA_TYPE)*xdx], $ArgReg(xItem), xdx
    mov eax, TRUE
  .else
    OCall xcx.ErrorReport, NULL, COL_INDEX_ERROR
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.SetLimit
; Purpose:    Set the Vector limit, allocating the necessary memory on the process heap to hold
;             all xItems.
; Arguments:  Arg1: New limit (count).
; Return:     eax = Error code.

%Method TVectorName.SetLimit, uses xbx xdi xsi, dNewLimit:DWORD
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
  mov edi, ebx
  shl edi, $Log2(sizeof(TVEC_DATA_TYPE))                ;xdx*sizeof(TVEC_DATA_TYPE)
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TVectorName.Store
; Purpose:    Store the Vector in a Stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

%Method TVectorName.Store, uses  xdi xsi, pStream:$ObjPtr(Stream)
  ArgReg pStream:rdx

  SetObject xsi
  mov xdi, $ArgReg(pStream)
  ACall xsi.Store, $ArgReg(pStream)
  OCall xdi::Stream.BinWrite32, [xsi].dCount
  OCall xdi::Stream.BinWrite32, [xsi].dLimit
  OCall xdi::Stream.BinWrite32, [xsi].dDelta
  OCall xdi::Stream.BinWrite32, [xsi].dMaxCapacity

  mov eax, [xsi].dCount
  OCall xdi::Stream.BinWrite, [xsi].pItems, addr [sizeof(TVEC_DATA_TYPE)*eax]
MethodEnd

endif
