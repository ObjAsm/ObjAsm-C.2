; ==================================================================================================
; Title:      Stream.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support for streaming objects.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DesLUT
; Purpose:    Implements a deserialization lookup table.
; Notes:      - This object and all descendants are thread-safe using OA multithreading support.
;
; Example:
;
;   local MyVec:$Obj(Vector), MyDiskStream:$Obj(DiskStream)
;   local DLUT:$Obj(DesLUT), DeserInfo:DESER_INFO
;
;   ...
;
;   ; Storage
;   New MyDiskStream::DiskStream
;   OCall MyDiskStream::DiskStream.Init, NULL, $OfsCStr("MyStream.stm"), 0, 0, \
;                                       NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
;   OCall MyVec::Vector.Store, addr MyDiskStream
;   OCall MyDiskStream::DiskStream.Done
;
;   ...
;
;   ; Recovery
;   New DLUT::DesLUT
;   lea xcx, DLUT
;   mov DeserInfo.pDesLUT, xcx
;   OCall xcx::DesLUT.Init, NULL, 10, 10, 0FFFFFFFFh/sizeof(POINTER)
;
;   New MyDiskStream::DiskStream
;   OCall MyDiskStream::DiskStream.Init, NULL, $OfsCStr("MyStream.stm"), 0, 0, \
;                                       NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
;   OCall MyVec::Vector.Load, addr MyDiskStream, addr DeserInfo
;   OCall MyDiskStream::DiskStream.Done
;   OCall DLUT::DesLUT.Done


Object DesLUT, DesLUTID, Primer
  RedefineMethod    Done
  VirtualMethod     Find,           XWORD
  VirtualMethod     ForEach,        POINTER, XWORD, XWORD         ; -> Proc, 2 parameters
  RedefineMethod    Init,           POINTER, DWORD, DWORD, DWORD  ; -> Owner, Count, Increment, Limit
  VirtualMethod     Insert,         XWORD, XWORD
  Private
  StaticMethod      SetLimit,       DWORD                         ; Set new limit (private)

  DefineVariable    pItems,         POINTER,      NULL
  DefineVariable    dCount,         DWORD,        0
  DefineVariable    dLimit,         DWORD,        0
  DefineVariable    dDelta,         DWORD,        0
  DefineVariable    dMaxCapacity,   DWORD,        0
  DefineVariable    ObjLock,        OBJECT_LOCK,  {}              ; Locking structure for multithreaded access
ObjectEnd


; DESER_INFO structure may be extended by descendant objects to pass additional information
; needed during deserialization.

DESER_INFO struc
  pDesLUT $ObjPtr(DesLUT)  ?
DESER_INFO ends
PDESER_INFO typedef ptr DESER_INFO


DLT_ENTRY struc
  xOldItem   XWORD  ?
  xNewItem   XWORD  ?
DLT_ENTRY ends
PDLT_ENTRY typedef ptr DLT_ENTRY

DLT_MAX_CAPACITY  equ 0FFFFFFFFh / sizeof(DLT_ENTRY)
DLT_MEM_PAGE      equ PAGESIZE / sizeof(DLT_ENTRY)


; --------------------------------------------------------------------------------------------------
; Object:     Stream
; Purpose:    Stream is a base object providing polymorphic I/O to and from a storage device
;             with a maximum capacity of 2^64 bytes. 
;
;             Derived stream objects can implement specialized I/O by redefining:
;               - BinRead / BinWrite (raw byte I/O)
;               - GetPos / GetSize (positioning)
;               - Seek / Truncate  (navigation)
;
; Notes:      - Buffered stream implementations must also override the Flush method.

Object Stream, StreamID, Primer
  VirtualAbstract     BinRead,      POINTER, DWORD      ; -> Buffer, Count
  VirtualAbstract     BinRead8
  VirtualAbstract     BinRead16
  VirtualAbstract     BinRead32
  VirtualAbstract     BinRead64
  VirtualAbstract     BinWrite,     POINTER, DWORD      ; -> Buffer, Count
  VirtualAbstract     BinWrite8,    BYTE
  VirtualAbstract     BinWrite16,   WORD
  VirtualAbstract     BinWrite32,   DWORD
  VirtualAbstract     BinWrite64,   QWORD
  VirtualMethod       CopyFrom,     POINTER, DWORD
  VirtualMethod       Get,          PDESER_INFO
  VirtualMethod       GetPreAlloc,  POINTER, DWORD, PDESER_INFO ; Address, TypeID, ...
  VirtualAbstract     GetPos
  VirtualAbstract     GetSize
  VirtualAbstract     Flush
  VirtualMethod       Put,          POINTER
  VirtualAbstract     Seek,         SQWORD, DWORD
  VirtualMethod       StrRead
  VirtualMethod       StrWriteA,    PSTRINGA
  VirtualMethod       StrWriteW,    PSTRINGW
  VirtualAbstract     Truncate
ObjectEnd


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  $ObjMtd(StrWrite) textequ $ObjMtd(StrWriteA)
else
  $ObjMtd(StrWrite) textequ $ObjMtd(StrWriteW)
endif

if TARGET_BITNESS eq 32
  $ObjMtd(BinReadX)  textequ $ObjMtd(BinRead32)
  $ObjMtd(BinWriteX) textequ $ObjMtd(BinWrite32)
else
  $ObjMtd(BinReadX)  textequ $ObjMtd(BinRead64)
  $ObjMtd(BinWriteX) textequ $ObjMtd(BinWrite64)
endif

$ObjMtd(StrReadA) textequ $ObjMtd(StrRead)
$ObjMtd(StrReadW) textequ $ObjMtd(StrRead)

STM_BEGIN   equ FILE_BEGIN
STM_CURRENT equ FILE_CURRENT
STM_END     equ FILE_END


; --------------------------------------------------------------------------------------------------
; Object:     Streamable
; Purpose:    Base class defining the protocol for objects that can be serialized into a Stream.
;
;             These four methods must be redefined by derived classes when custom behavior
;             is required:
;               - Serialize     Prepare object state for writing
;               - Store         Write state to a Stream
;               - Load          Read state from a Stream
;               - Deserialize   Restore object references and post-processing
;
;             Order of operations:
;               1. Serialize
;               2. Store
;               3. Load
;               4. Deserialize

Object Streamable, StreamableID, Primer
  VirtualMethod     Deserialize,  PDESER_INFO
  VirtualMethod     Load,         $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     Serialize
  VirtualMethod     Store,        $ObjPtr(Stream)
ObjectEnd


if IMPLEMENT

; ==================================================================================================
;  DesLUT implementation
; ==================================================================================================

PDesLUTProc typedef proto :POINTER, :POINTER, :QWORD, :QWORD

; --------------------------------------------------------------------------------------------------
; Method:     DesLUT.Done
; Purpose:    Deletes and releases all items in the collection.
; Arguments:  None.
; Return:     Nothing.

Method DesLUT.Done, uses xsi
  SetObject xsi
  .if [xsi].pItems != NULL
    MemFree [xsi].pItems
    m2z [xsi].dCount
    m2z [xsi].pItems
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DesLUT.Init
; Purpose:    Initializes the collection with:
;               - dLimit:       initial capacity
;               - dDelta:       growth step
;               - dMaxCapacity: maximum allowed size
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity.
;             Arg3: Growth step.
;             Arg4: Maximum capacity (use COL_MAX_CAPACITY for "no limit").
; Return:     eax = Error code.

Method DesLUT.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dMaxCapacity:DWORD
  ACall Init, pOwner
  SetObject xcx
  xor eax, eax
  mov [xcx].pItems, xax
  mov [xcx].dCount, eax
  mov [xcx].dLimit, eax
  mov [xcx].dErrorCode, OBJ_OK
  m2m [xcx].dDelta, dDelta, edx

  .if eax != dMaxCapacity
    mov edx, dMaxCapacity
  .else
    mov edx, DLT_MAX_CAPACITY
  .endif
  mov [xcx].dMaxCapacity, edx

  mov eax, dLimit
  .if eax <= [xcx].dMaxCapacity
    OCall xcx.SetLimit, eax
    .if eax != OBJ_OK
      OCall ErrorReport, NULL, eax
    .else
      OCall Insert, NULL, NULL      ; register NULL mapping
    .endif
  .else
    OCall xcx.ErrorReport, NULL, DLT_SETUP_ERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DesLUT.Find
; Purpose:    Searches for an old item value.
; Arguments:  Arg1: Old item to search for.
; Return:     eax = Status code.
;             xcx = New item associated with the old one.

Method DesLUT.Find,, xSearchItem:XWORD
  SetObject xcx
  mov xax, [xcx].pItems
  mov edx, [xcx].dCount
  ReleaseObject xcx
  shl xdx, $Log2(sizeof(DLT_ENTRY))
  lea xcx, [xax + xdx]
  mov xdx, xSearchItem
  .while xax < xcx
    .if [xax].DLT_ENTRY.xOldItem == xdx
      mov xcx, [xax].DLT_ENTRY.xNewItem
      xor eax, eax    ; OBJ_OK
      ExitMethod
    .endif
    add xax, sizeof(DLT_ENTRY)
  .endw
  OCall pSelf::DesLUT.ErrorReport, NULL, DLT_ITEM_NOT_FOUND
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DesLUT.ForEach
; Purpose:    Calls the procedure pProc for each item in the lookup table.
; Arguments:  Arg1: -> Callback procedure.
;             Arg2, Arg3: optional parameters.
; Return:     Nothing.
; Note:       Items must not be deleted during iteration.

Method DesLUT.ForEach, uses xbx xdi xsi, pProc:POINTER, Arg1:XWORD, Arg2:XWORD
  SetObject xsi
  mov ebx, [xsi].$Obj(DesLUT).dCount
  mov xdi, [xsi].$Obj(DesLUT).pItems
  ReleaseObject xsi
  shl xbx, $Log2(sizeof(DLT_ENTRY))
  add xbx, xdi
  .while xdi < xbx
    invoke PDesLUTProc ptr pProc, xsi, xdi, Arg1, Arg2
    add xdi, sizeof(DLT_ENTRY)
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DesLUT.Insert
; Purpose:    Inserts a new mapping into the lookup table.
; Arguments:  Arg1: Old item.
;             Arg2: New item.
; Return:     xax -> new item.

Method DesLUT.Insert, uses xsi, xOldItem:XWORD, xNewItem:XWORD
  SetObject xsi
  mov edx, [xsi].dCount
  cmp edx, [xsi].dLimit
  ht
  jne @F
  add edx, [xsi].dDelta
  OCall xsi.SetLimit, edx
  .if eax == 0
    mov edx, [xsi].dCount
@@:
    inc [xsi].dCount
    mov xax, [xsi].pItems
    shl xdx, $Log2(sizeof(DLT_ENTRY))
    lea xcx, [xax + xdx]
    m2m [xcx].DLT_ENTRY.xOldItem, xOldItem, xdx
    m2m [xcx].DLT_ENTRY.xNewItem, xNewItem, xax
  .else
    OCall xsi.ErrorReport, NULL, eax
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DesLUT.SetLimit
; Purpose:    Sets the collection limit, allocating or resizing memory as needed.
; Arguments:  Arg1: New limit.
; Return:     eax = Error code.

Method DesLUT.SetLimit, uses xbx xdi xsi, dNewLimit:DWORD
  SetObject xsi
  mov ebx, dNewLimit
  mov eax, [xsi].dCount
  cmp eax, ebx
  ja @@1                   ; NewLimit < dCount not allowed
  mov eax, [xsi].dMaxCapacity
  cmp eax, ebx
  ht
  jae @@2
@@1:
  mov ebx, eax
@@2:
  mov ecx, [xsi].dLimit
  cmp ecx, ebx
  .if ZERO?
    xor eax, eax
  .else
    test ebx, ebx
    .if ZERO?
      MemFree [xsi].pItems, MEM_SAFE_FREE
      xor eax, eax
      mov [xsi].pItems, xax
      mov [xsi].dLimit, eax
    .else
      mov xax, xbx
      shl xax, $Log2(sizeof(DLT_ENTRY))
      mov xdi, [xsi].pItems
      test xdi, xdi
      .if ZERO?
        MemAlloc xax
      .else
        MemReAlloc xdi, xax
      .endif
      test xax, xax
      jz @@Error
      mov [xsi].pItems, xax
      mov [xsi].dLimit, ebx
      xor eax, eax
    .endif
  .endif
  ret

@@Error:
  mov eax, DLT_OUT_OF_MEMORY
MethodEnd


; ==================================================================================================
;  Stream implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Stream.CopyFrom
; Purpose:    Copies a specified number of bytes from another stream into this one.
;             Data is copied in chunks of up to 1024 bytes.
; Arguments:  Arg1: -> Stream object.
;             Arg2: Number of bytes to copy.
; Return:     eax = Number of bytes copied.

Method Stream.CopyFrom, uses xbx xdi xsi, pStream:POINTER, dCount:DWORD
  local bBuffer[1024]:BYTE

  mov ebx, dCount
  lea xsi, bBuffer
  test ebx, ebx
  .while !ZERO?
    .if ebx < sizeof(bBuffer)
      mov edi, ebx
    .else
      mov edi, sizeof(bBuffer)
    .endif
    OCall pStream::Stream.BinRead, xsi, edi
    OCall pSelf::Stream.BinWrite, xsi, edi
    sub ebx, edi
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Stream.Get
; Purpose:    Reads and instantiates a Streamable object previously stored with Put.
;             Reads the object type ID, constructs the instance, then calls Load.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     xax -> Newly created object or NULL.

Method Stream.Get, uses xbx xsi, pDeserInfo:PDESER_INFO
  SetObject xsi
  OCall xsi.BinRead32
  .if eax != 0
    invoke NewObjInst, eax
    .if xax != NULL
      mov xbx, xax
      OCall xax::Streamable.Load, xsi, pDeserInfo
      mov xax, xbx
    .else
      OCall xsi.ErrorReport, NULL, STM_OUT_OF_MEMORY
      xor eax, eax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, STM_REGISTRATION_ERROR
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Stream.GetPreAlloc
; Purpose:    Reads a Streamable object into a preallocated memory block.
; Arguments:  Arg1: Preallocated storage address.
;             Arg2: Expected Object Type ID (0 = any).
;             Arg3: -> DESER_INFO.
; Return:     eax = Error code.

Method Stream.GetPreAlloc, uses xsi, pObject:POINTER, TypeID:DWORD, pDeserInfo:PDESER_INFO
  SetObject xsi
  OCall xsi.BinRead32
  mov ecx, TypeID
  .if ecx == 0 || ecx == eax
    OCall pObject::Streamable.Load, xsi, pDeserInfo
  .else
    OCall xsi.ErrorReport, NULL, STM_INCORRECT_TYPE_ID
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Stream.Put
; Purpose:    Writes a Streamable object to the stream.
;             First writes the object type ID, then calls Store.
; Arguments:  Arg1: -> Streamable object.
; Return:     Nothing.

Method Stream.Put,, pStreamable:POINTER
  .if pStreamable == NULL
    OCall ErrorReport, NULL, STM_INVALID_OBJECT
  .else
    invoke GetObjectID, pStreamable
    .if eax == 0
      OCall ErrorReport, NULL, STM_REGISTRATION_ERROR
    .else
      OCall BinWrite32, eax
      OCall pStreamable::Streamable.Store, pSelf
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Stream.StrRead
; Purpose:    Reads a zero-terminated string from the stream and allocates it on the heap.
; Arguments:  None.
; Return:     xax -> Allocated string or NULL.

Method Stream.StrRead, uses xbx xsi
  SetObject xsi
  OCall xsi.BinRead32
  .if eax != 0
    mov ebx, eax
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      invoke GlobalAlloc, 0, eax
    elseif TARGET_PLATFORM eq PLATFORM_UEFI
      MemAlloc eax
    endif
    .if xax != NULL
      mov xdx, xax
      xchg xbx, xax
      OCall xsi.BinRead, xdx, eax
      mov xax, xbx
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Stream.StrWriteA
; Purpose:    Writes a zero-terminated ANSI string to the stream.
; Arguments:  Arg1: -> ANSI string.
; Return:     Nothing.

Method Stream.StrWriteA, uses xdi xsi, pStr:PSTRINGA
  SetObject xsi
  .if pStr == NULL
    OCall xsi.BinWrite32, 0
  .else
    invoke StrSizeA, pStr
    mov edi, eax
    OCall xsi.BinWrite32, eax
    OCall xsi.BinWrite, pStr, edi
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Stream.StrWriteW
; Purpose:    Writes a zero-terminated WIDE string to the stream.
; Arguments:  Arg1: -> WIDE string.
; Return:     Nothing.

Method Stream.StrWriteW, uses xdi xsi, pStr:PSTRINGW
  SetObject xsi
  .if pStr == NULL
    OCall xsi.BinWrite32, 0
  .else
    invoke StrSizeW, pStr
    mov edi, eax
    OCall xsi.BinWrite32, eax
    OCall xsi.BinWrite, pStr, edi
  .endif
MethodEnd


; ==================================================================================================
;  Streamable implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Streamable.Deserialize
; Purpose:    Restores serialized references using the lookup table.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method Streamable.Deserialize, uses xsi, pDeserInfo:PDESER_INFO
  SetObject xsi
  mov xdx, pDeserInfo
  .if $OCall([xdx].DESER_INFO.pDesLUT::DesLUT.Find, [xsi].pErrorCaller) == OBJ_OK
    mov [xsi].pErrorCaller, xcx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Streamable.Load
; Purpose:    Loads and initializes the instance from a Stream.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     eax = Status code.

Method Streamable.Load, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  mov xdi, pStream
  mov xbx, pDeserInfo
  OCall xdi::Stream.BinReadX                           ; Old pSelf
  OCall [xbx].DESER_INFO.pDesLUT::DesLUT.Insert, xax, xsi

  OCall xdi::Stream.BinReadX                           ; Old pOwner
  .if $OCall([xbx].DESER_INFO.pDesLUT::DesLUT.Find, xax) == OBJ_OK
    mov [xsi].pOwner, xcx
    OCall xdi::Stream.BinRead32
    mov [xsi].dErrorCode, eax

    mov [xsi].pErrorCaller, $OCall(xdi::Stream.BinReadX)
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Streamable.Serialize
; Purpose:    Assigns a unique ID and serializes members that need special handling.
; Arguments:  None.
; Return:     Nothing.

Method Streamable.Serialize
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Streamable.Store
; Purpose:    Stores the Streamable instance into a Stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Streamable.Store, uses xdi xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  mov xdi, pStream
  OCall xdi::Stream.BinWriteX, xsi
  OCall xdi::Stream.BinWriteX, [xsi].pOwner
  OCall xdi::Stream.BinWrite32, [xsi].dErrorCode
  OCall xdi::Stream.BinWriteX, [xsi].pErrorCaller
MethodEnd

endif