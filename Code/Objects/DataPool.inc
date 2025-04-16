; ==================================================================================================
; Title:      DataPool.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of DataPool objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;This switch enables the XOR of the offsets in the free item list at a cost of a little performance.
;The XOR is performed with the dCookie random value.
DPL_SECURE = FALSE

DPL_CONTROLDATA struc
                  SDLL_ITEM   {}        ;Blob linkage
  dUsedItemCount  DWORD       ?         ;If zero, no item is in use and the blob can be deallocated
  dFirstFreeItem  DWORD       ?         ;Blob relative offset to the first free item.
DPL_CONTROLDATA ends                    ;  Zero if there is no free item.
P_DPL_CONTROLDATA typedef ptr DPL_CONTROLDATA

; --------------------------------------------------------------------------------------------------
; Object:     DataPool
; Purpose:    This memory manager is a page based memory pool. It handles memory fragments (Items)
;             of the same size (dItemSize). Due to the linkage of unused items, you can quickly get
;             a memory fragment. Free items are linked with offsets relative to the blob start
;             address to avoid the pointer translation when loading from a stream and to improve
;             data security. These values can be additionally XORed when the DPL_SECURE switch is
;             set to TRUE.
;
;             When the commited memory is completely consumend, a new blob is reserved and added
;             to an internal linked list (pFirstMember/pLastMember).
;
;             Each time a new item is requested, the internal linked list is always traversed from
;             the first to last blob to ensure a concentration of allocations on the first blobs,
;             giving a chance to the last blobs to become competely free to deallocate them.
;
;             The advantage of this scheme is the fast and flexible management of fixed sized
;             memory fragments, while the down side is that you should not free a fragment more
;             than once, If you do so, the internal lists become corrupt which leads to an
;             unexpected behaviour.
;
;
;  SDLL_SENTINEL             Blob #1                               Blob #k             SDLL_SENTINEL
;                      -=================-                   -=================-
; [].pFirstItem  ---> ||  pNextItem      || ----- ... ----> ||  pNextItem      || ---> [].pFirstItem
;                     ||-----------------||                 ||-----------------||
; [].pLastItem   <--- ||  pPrevItem      || <---- ... ----- ||  pPrevItem      || <--- [].pLastItem
;                     ||-----------------||                 ||-----------------||
;                     ||  dUsedItemCount ||                 ||  dUsedItemCount ||
;                     ||-----------------||                 ||-----------------||
;                -----||  dFirstFreeItem ||            -----||  dFirstFreeItem ||
;               |     ||-----------------||           |     ||-----------------||
;               |     || (Padding bytes) ||           |     || (Padding bytes) ||
;               |     ||=================||           |     ||=================||
;               |     ||  Item 1         ||           |     ||  Item j+1       ||
;               |     ||-----------------||           |     ||-----------------||
;               |     ||  Item 2         ||           '---->||////  Free 4 ////|| (Zero)
;               '---->||-----------------||                 ||-----------------||
;             --------||////  Free 1 ////||                 ||  Item n         ||    |
;            |        ||-----------------||                 ||-----------------|| <--' dUsedSize
;            |        ||  Item 4         ||                 ||                 ||
;            |   ---->||-----------------||                 ||                 ||
;            |  |     ||////  Free 2 ////|| (Zero)          ||                 ||
;            |  |     ||-----------------||                 ||                 ||
;            |  |     ||  ...            ||                 ||                 ||
;            |  |     ||-----------------||                 ||                 ||
;            |  |     ||  ...            ||                 ||                 ||
;            '--|---->||-----------------||                 ||                 ||
;               '-----||////  Free 3 ////||                 ||                 ||
;                     ||-----------------||                 ||                 ||
;                     ||  Item i         ||                 ||                 ||
;                     ||-----------------||                 ||                 ||
;                     ||  ...            ||                 ||                 ||
;                     ||-----------------||                 ||                 ||
;                     ||  ...            ||                 ||                 ||
;                     ||-----------------||                 ||                 ||
;                     ||  Item j         ||                 ||                 ||
;                     |'-----------------'|                 |'-----------------'|
;                     |                   |                 |                   |
;                     | (Wasted Commited  |                 | (Wasted Commited  |
;                     |       Memory)     |                 |       Memory)     |
;                     |                   |                 |                   |    |
;                     '-------------------'                 '-------------------' <--' dAllocSize
;
;
; Notes:     - DataPool and all descendants are thread safe using the ObjAsm multithreading support.

Object DataPool, DataPoolID, Streamable
  RedefineMethod  Done
  VirtualMethod   FreeItem,         POINTER
  RedefineMethod  Init,             POINTER, DWORD, DWORD, DWORD
  RedefineMethod  Load,             $ObjPtr(Stream), POINTER  ;-> Stream, -> new owner
  VirtualMethod   LoadBlobs,        $ObjPtr(Stream)           ;-> Stream
  DynamicMethod   LoadItem,         $ObjPtr(Stream), POINTER  ;-> Stream, -> Item
  VirtualMethod   NewItem
  VirtualMethod   Reset
  RedefineMethod  Store,            $ObjPtr(Stream)           ;-> Stream
  DynamicMethod   StoreItem,        $ObjPtr(Stream), POINTER  ;-> Stream, -> Item

  DefineVariable  Blobs,            SDLL_SENTINEL,  {}
  DefineVariable  dItemSize,        DWORD,    0       ;Item size in bytes
  DefineVariable  dControlDataSize, DWORD,    0       ;ControlData size (incl. padding) in bytes
  DefineVariable  dAllocSize,       DWORD,    0       ;Includes Control Data size
  DefineVariable  dUsedSize,        DWORD,    0       ;Size of used blob memory (incl. ControlData)
  DefineVariable  dCompSize,        DWORD,    0       ;Precomputed "comparison size"
  DefineVariable  ObjLock,          OBJECT_LOCK,    {}
  if DPL_SECURE ne FALSE
    DefineVariable  dCookie,        DWORD,    0
  endif
ObjectEnd


; ==================================================================================================


if IMPLEMENT

; ==================================================================================================
;    DataPool implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.Done
; Purpose:    Finalize the DataPool object, releasing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method DataPool.Done, uses xbx xdi xsi
  local pNextItem:POINTER

  SetObject xsi

  ;Reset linked list but first get xbx -> pFirstItem
  lea xdi, [xsi].Blobs
  mov xbx, [xsi].Blobs.pFirstItem
  SDLL_Init xdi

  ;Free all allocated memory in the linked list
  .while xbx != xdi
    m2m pNextItem, [xbx].DPL_CONTROLDATA.pNextItem, xax   ;Compute this before the page is freed
    invoke VirtualFree, xbx, 0, MEM_RELEASE
    mov xbx, pNextItem
  .endw

  ;Call ancestor Done method
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.FreeItem
; Purpose:    Free a memory block.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method DataPool.FreeItem, uses xbx xdi xsi, pItem:POINTER
  SetObject xsi

  ;Search the matching blob, where pItem is in
  lea xdi, [xsi].Blobs
  mov xbx, [xsi].Blobs.pFirstItem
  .while xbx != xdi
    mov xax, pItem
    mov ecx, [xsi].dControlDataSize
    sub xax, xcx                                        ;Shift the POINTER
    mov ecx, [xsi].dCompSize
    add xcx, xbx
    IsInRange? xax, xbx, xcx, xdx
    jz @F                                               ;ZERO? => Found
    mov xbx, [xbx].DPL_CONTROLDATA.pNextItem
  .endw
  OCall xsi.ErrorReport, NULL, DPL_WRONG_ITEM_POINTER
  ret

@@:                                                     ;xbx -> DPL_CONTROLDATA
  ;Updated the free item linked list
  mov xdx, pItem
  m2m DWORD ptr [xdx], [xbx].DPL_CONTROLDATA.dFirstFreeItem, eax
  sub xdx, xbx
  if DPL_SECURE ne FALSE
    xor edx, [xsi].dCookie
  endif
  mov [xbx].DPL_CONTROLDATA.dFirstFreeItem, edx
  dec [xbx].DPL_CONTROLDATA.dUsedItemCount

  ;Check if the blob is completely empty
  .if ZERO?
;    DbgWarning "Freeing empty blob..."
    ;Correct the dUsedSize member if necessary
    .if xbx == [xsi].Blobs.pLastItem
      m2m [xsi].dUsedSize, [xsi].dAllocSize, eax
    .endif
    ;Remove the blob from the linked list and deallocate it
    SDLL_Remove xbx, xdx, xax
    invoke VirtualFree, xbx, 0, MEM_RELEASE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.Init
; Purpose:    Initialize the DataPool object. No allocation is done at this moment!
; Arguments:  Arg1: -> Owner object.
;             Arg2: Item size.
;             Arg3: Desired minimal capacity (# of items).
;             Arg4: Item memory alignment (1, 2, 4, 8, 16, etc.).
; Return:     Nothing.

Method DataPool.Init, uses xsi, pOwner:POINTER, dItemSize:DWORD, dCapacity:DWORD, dAlignment:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  lea xax, [xsi].Blobs
  SDLL_Init xax

  ;In case of an incorrect input, compute the correct alignment as
  ;Next Largest Power of 2 from (dAlignment - 1)
  mov ecx, dAlignment
  dec ecx
  NLPo2 ecx, edx                                        ;ecx = corrected alignment value

  ;Compute the ControlData size for proper alignment
  xor edx, edx
  mov eax, sizeof(DPL_CONTROLDATA)
  div ecx                                               ;ecx = dAlignment
  .if edx != 0
    inc eax
    xor edx, edx
  .endif
  mul ecx
  mov [xsi].dControlDataSize, eax

  ;Item size must be >= sizeof(DWORD)
  mov eax, dItemSize
  .if eax < sizeof(DWORD)
    mov eax, sizeof(DWORD)
  .endif

  ;Compute the Item size for correct alignment
  xor edx, edx
  div ecx                                               ;ecx = dAlignment
  .if edx != 0
    inc eax
    xor edx, edx
  .endif
  mul ecx
  mov [xsi].dItemSize, eax

  ;Compute the Allocation Size as a multiple of PAGESIZE including the Control Data size.
  xor edx, edx
  mul dCapacity
  add eax, [xsi].dControlDataSize
  add eax, PAGESIZE - 1
  and eax, not PAGESIZE - 1
  ;The maximal allocation size should not exceed the range of a DWORD = offsets of free items.
  mov [xsi].dAllocSize, eax

  ;Compute Comparison size = Effective Capacity Size - ItemSize
  xor edx, edx
  sub eax, [xsi].dControlDataSize
  div [xsi].dItemSize
  xor edx, edx
  mul [xsi].dItemSize
  add eax, [xsi].dControlDataSize
  sub eax, [xsi].dItemSize
  mov [xsi].dCompSize, eax

  if DPL_SECURE ne FALSE
    ;Take a random cookie value
    mov [xsi].dCookie, $32($invoke(Random32, 0FFFFFFFFh))
  endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.Load
; Purpose:    Load object data from a stream.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Owner object.
; Return:     eax = Error code.

Method DataPool.Load, uses xsi, pStream:$ObjPtr(Stream), pOwner:POINTER
  SetObject xsi

  ;Start reading object variables
  m2m [xsi].pOwner, pOwner, eax

  mov [xsi].dErrorCode,       $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dItemSize,        $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dControlDataSize, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dAllocSize,       $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dUsedSize,        $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dCompSize,        $32($OCall(pStream::Stream.BinRead32))
  if DPL_SECURE ne FALSE
    mov [xsi].dCookie,        $32($OCall(pStream::Stream.BinRead32))
  endif

  OCall xsi.LoadBlobs, pStream
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.LoadBlobs
; Purpose:    Load blob data data from a stream.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Owner object.
; Return:     eax = Error code.

Method DataPool.LoadBlobs, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local pSentinel:POINTER, dBlobEnd:DWORD, dBlobCount:DWORD

  SetObject xsi

  ;Read blob information
  lea edi, [xsi].Blobs
  mov pSentinel, xdi
  SDLL_Init xdi                                         ;Reset the list
  OCall pStream::Stream.BinRead32                       ;Read blob count
  mov dBlobCount, eax

  ;Calc the end of data in the blob
  .if dBlobCount == 1
    mov edx, [xsi].dUsedSize
  .else
    mov edx, [xsi].dAllocSize
  .endif
  mov dBlobEnd, edx

  .while dBlobCount != 0
    ;Allocate a blob
    invoke VirtualAlloc, NULL, [xsi].dAllocSize, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, DPL_STREAM_ALLOC_ERROR
      ExitMethod
    .else
      ;Insert blob
      mov xbx, xax
      SDLL_Append xdi, xbx, xdx                         ;Put the new blob at the end of the SDLL

      ;Restore blob control data
      OCall pStream::Stream.BinRead32
      mov [xbx].DPL_CONTROLDATA.dUsedItemCount, eax
      OCall pStream::Stream.BinRead32
      mov [xbx].DPL_CONTROLDATA.dFirstFreeItem, eax

      mov edi, [xsi].dControlDataSize
      .while edi < dBlobEnd
        OCall pStream::Stream.BinRead32                 ;Read marker
        .if eax == 0                                    ;Free?
          mov [xbx + xdi], $OCall(pStream::Stream.BinRead32)  ;Read next free item offset
        .else
          OCall xsi.LoadItem, pStream, addr [xbx + xdi]
        .endif
        add edi, [xsi].dItemSize
      .endw
    .endif
    dec dBlobCount
  .endw
  xor eax, eax                                          ;OBJ_OK = return success code
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.LoadItem
; Purpose:    Load an Item from a stream.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Item memory block.
; Return:     eax = OBJ_OK or an error code if failed.

Method DataPool.LoadItem,, pStream:$ObjPtr(Stream), pItem:POINTER
  SetObject xax
  OCall pStream::Stream.BinRead, pItem, [xax].dItemSize
  mov xdx, pStream
  mov eax, [xdx].$Obj(Stream).dErrorCode
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.NewItem
; Purpose:    Return a pointer to a free memory item.
; Arguments:  None.
; Return:     xax -> Item or NULL if failed.

Method DataPool.NewItem, uses xbx xsi
  SetObject xsi

  lea xbx, [xsi].Blobs
  mov xcx, [xsi].Blobs.pFirstItem
  .if xcx != xbx
    .repeat
      .if [xcx].DPL_CONTROLDATA.dFirstFreeItem != 0     ;Check if we have a free item here
;        DbgText "Reusing an old item"
        mov eax, [xcx].DPL_CONTROLDATA.dFirstFreeItem   ;Get it (eax = item offset)
        if DPL_SECURE ne FALSE
          xor eax, [xsi].dCookie
        endif
        add xax, xcx                                    ;Prepare return value
        mov edx, [xax]                                  ;Update linked list, xax + xcx -> item
        mov [xcx].DPL_CONTROLDATA.dFirstFreeItem, edx   ;Next free item offset
        inc [xcx].DPL_CONTROLDATA.dUsedItemCount        ;Increment used item counter
        ret                                             ;ready!
      .endif

      mov xdx, xcx                                      ;xdx -> last non NULL blob
      mov xcx, [xcx].DPL_CONTROLDATA.pNextItem          ;Move to next blob
    .until xcx == xbx                                   ;Last blob reached

    mov eax, [xsi].dUsedSize
    mov ecx, eax
    add ecx, [xsi].dItemSize
    .if ecx <= [xsi].dAllocSize                         ;Have we enough commited memory?
;      DbgText "Taking from commited memory"
      mov [xsi].dUsedSize, ecx
      add xax, xdx
      inc [xdx].DPL_CONTROLDATA.dUsedItemCount
      ret
    .endif
  .endif

;  DbgWarning "Allocating new blob"
  invoke VirtualAlloc, NULL, [xsi].dAllocSize, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
  .if xax != NULL
    ;Put the new blob at the end of the linked list
    lea xcx, [xsi].Blobs
    SDLL_Append xcx, xax, xdx

    ;Compute internal data...
    mov [xax].DPL_CONTROLDATA.dUsedItemCount, 1
    mov ecx, [xsi].dControlDataSize
    add xax, xcx
    add ecx, [xsi].dItemSize
    mov [xsi].dUsedSize, ecx
  .else
    OCall xsi.ErrorReport, NULL, DPL_OUT_OF_MEMORY
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.Reset
; Purpose:    Restore initial state, releasing the complete allocated memory.
; Arguments:  None.
; Return:     Nothing.

Method DataPool.Reset, uses xbx xdi xsi
  SetObject xcx
  lea xdi, [xcx].Blobs
  mov xbx, [xcx].Blobs.pFirstItem
  .while xbx != xdi
    mov xsi, [xbx].DPL_CONTROLDATA.pNextItem
    invoke VirtualFree, xbx, 0, MEM_RELEASE
    mov xbx, xsi
  .endw
  SDLL_Init xdi                                         ;Reset the list
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.Store
; Purpose:    Store object data in a stream.
; Arguments:  Arg1: -> Stream object.
; Return:     eax = OBJ_OK if succeeded, otherwise an error code.

Method DataPool.Store, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dBlobEnd:DWORD, pMap:POINTER, dBlobCount:DWORD, dErr:DWORD

  SetObject xsi
  MemAlloc [xsi].dAllocSize
  .if xax != NULL
    mov pMap, xax

    ;Start writing object variables
    OCall pStream::Stream.BinWrite32, [xsi].dErrorCode
    OCall pStream::Stream.BinWrite32, [xsi].dItemSize
    OCall pStream::Stream.BinWrite32, [xsi].dControlDataSize
    OCall pStream::Stream.BinWrite32, [xsi].dAllocSize
    OCall pStream::Stream.BinWrite32, [xsi].dUsedSize
    OCall pStream::Stream.BinWrite32, [xsi].dCompSize
    if DPL_SECURE ne FALSE
      OCall pStream::Stream.BinWrite32, [xsi].dCookie
    endif

    ;Count the number of allocated blobs
    lea xax, [xsi].Blobs
    mov xcx, xax
    xor edx, edx
    .repeat
      mov xcx, [xcx].SDLL_ITEM.pNextItem
      .break .if xcx == xax
      inc edx
    .until FALSE
    mov dBlobCount, edx

    OCall pStream::Stream.BinWrite32, edx               ;Write down the number of allocated blobs

    mov xbx, [xsi].Blobs.pFirstItem

    .while dBlobCount != 0
      ;Create a map for this blob and fill it with "1" to signal an free item
      invoke MemZero, pMap, [xsi].dAllocSize
      mov xdi, pMap
      mov ecx, [xbx].DPL_CONTROLDATA.dFirstFreeItem
      .while ecx != 0
        mov DWORD ptr [xdi + xcx], 1                    ;Set free marker into the map
        mov ecx, [xbx + xcx]                            ;Next free item
      .endw

      ;Calc the end of data in the blob
      .if dBlobCount == 1
        mov edx, [xsi].dUsedSize
      .else
        mov edx, [xsi].dAllocSize
      .endif
      mov dBlobEnd, edx

      ;Write down the control blob data
      OCall pStream::Stream.BinWrite32, [xbx].DPL_CONTROLDATA.dUsedItemCount
      OCall pStream::Stream.BinWrite32, [xbx].DPL_CONTROLDATA.dFirstFreeItem

      ;Write down the blob payload
      mov edi, [xsi].dControlDataSize
      .while edi < dBlobEnd
        mov xax, pMap
        .if DWORD ptr [xax + xdi] == 1                  ;Free item
          OCall pStream::Stream.BinWrite32, 0           ;Set free item marker
          OCall pStream::Stream.BinWrite32, DWORD ptr [xbx + xdi]   ;Write next free offset
        .else
          OCall pStream::Stream.BinWrite32, 1           ;Set used item marker
          OCall xsi.StoreItem, pStream, addr [xbx + xdi]
          .if eax != OBJ_OK
            mov dErr, eax
            MemFree pMap
            OCall xsi.ErrorReport, NULL, dErr
            ExitMethod
          .endif
        .endif
        add edi, [xsi].dItemSize
      .endw

      mov xax, pStream
      .break .if [xax].$Obj(Stream).dErrorCode != OBJ_OK

      mov xbx, [xbx].DPL_CONTROLDATA.pNextItem          ;Move to next blob
      dec dBlobCount
    .endw

    MemFree pMap
    mov xcx, pStream
    mov eax, [xcx].$Obj(Stream).dErrorCode
  .else
    OCall xsi.ErrorReport, NULL, DPL_OUT_OF_MEMORY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DataPool.StoreItem
; Purpose:    Store item data in a stream.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Item.
; Return:     eax = OBJ_OK or an error code if failed.

Method DataPool.StoreItem,, pStream:$ObjPtr(Stream), pItem:POINTER
  SetObject xax
  OCall pStream::Stream.BinWrite, pItem, [xax].dItemSize
  mov xdx, pStream
  mov eax, [xdx].$Obj(Stream).dErrorCode
MethodEnd

endif
