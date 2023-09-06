; ==================================================================================================
; Title:      Stream.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of streaming objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DesLUT
; Purpose:    Implement a deserialization lookup table.
; Notes:      - This object and all descendants are thread safe using the OA multithreading support.

Object DesLUT, DesLUTID, Primer
  RedefineMethod    Done
  VirtualMethod     Find,           XWORD
  VirtualMethod     ForEach,        POINTER, XWORD, XWORD         ;-> Proc, 2 x Parameter
  RedefineMethod    Init,           POINTER, DWORD, DWORD, DWORD  ;-> Owner, Count, Increment, Limit
  VirtualMethod     Insert,         XWORD, XWORD
  Private
  StaticMethod      SetLimit,       DWORD               ;Set new limit (private method)

  DefineVariable    pItems,         POINTER,      NULL
  DefineVariable    dCount,         DWORD,        0
  DefineVariable    dLimit,         DWORD,        0
  DefineVariable    dDelta,         DWORD,        0
  DefineVariable    dMaxCapacity,   DWORD,        0
  DefineVariable    ObjLock,        OBJECT_LOCK,  {}    ;Locking structure for multithreaded access
ObjectEnd

; DESER_INFO structure can be extended by descendant objects to pass additional information
; for the deserialization process.

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


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Stream
; Purpose:    Stream is a base object providing polymorphic I/O to and from a storage device with
;             a maximum capacity of 2^64 bytes. You can create your own derived stream objects by
;             overriding the following methods: BinRead, BinWrite, GetPos, GetSize, Seek and
;             Truncate.
; Notes:      - For buffered derived streams, you must also override the Flush method.

Object Stream, StreamID, Primer
  VirtualAbstract     BinRead,      POINTER, DWORD      ;-> Buffer, Count
  VirtualAbstract     BinRead8
  VirtualAbstract     BinRead16
  VirtualAbstract     BinRead32
  VirtualAbstract     BinRead64
  VirtualAbstract     BinWrite,     POINTER, DWORD      ;-> Buffer, Count
  VirtualAbstract     BinWrite8,    BYTE
  VirtualAbstract     BinWrite16,   WORD
  VirtualAbstract     BinWrite32,   DWORD
  VirtualAbstract     BinWrite64,   QWORD
  VirtualMethod       CopyFrom,     POINTER, DWORD
  VirtualMethod       Get,          PDESER_INFO
  VirtualMethod       GetPreAlloc,  POINTER, DWORD, PDESER_INFO ;Address, Obj. type ID, ...
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
  $ObjMthd(StrWrite) textequ $ObjMthd(StrWriteA)
else
  $ObjMthd(StrWrite) textequ $ObjMthd(StrWriteW)
endif

if TARGET_BITNESS eq 32
  $ObjMthd(BinReadX)  textequ $ObjMthd(BinRead32)
  $ObjMthd(BinWriteX) textequ $ObjMthd(BinWrite32)
else
  $ObjMthd(BinReadX)  textequ $ObjMthd(BinRead64)
  $ObjMthd(BinWriteX) textequ $ObjMthd(BinWrite64)
endif

$ObjMthd(StrReadA) textequ $ObjMthd(StrRead)
$ObjMthd(StrReadW) textequ $ObjMthd(StrRead)

STM_BEGIN   equ FILE_BEGIN
STM_CURRENT equ FILE_CURRENT
STM_END     equ FILE_END


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Streamable
; Purpose:    Streamable is a base object with 4 methods that need a redefinition to extend their
;             functionality in descendant objects. This approach is useful to provide polymorphic
;             access to these methods called from stream objects via the Put or Get methods.
;             Serialize and Deserialize methods implement the way object members are serialized to
;             and deserialized from a stream.
;             The call sequence should be
;
;               1. Serialize (convert data)
;               2. Store (write data to a Stream)
;                  ...
;               3. Load (read data from Stream)
;               4. Deserialize (convert data back)

Object Streamable, StreamableID, Primer
  VirtualMethod     Deserialize,  PDESER_INFO
  VirtualMethod     Load,         $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     Serialize
  VirtualMethod     Store,        $ObjPtr(Stream)
ObjectEnd


if IMPLEMENT

; ==================================================================================================
;  DesLUT
; ==================================================================================================

PDesLUTProc  typedef proto :POINTER, :POINTER, :QWORD, :QWORD


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DesLUT.Done
; Purpose:    Delete and dispose all items in the collection.
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DesLUT.Init
; Purpose:    Initialize the collection with a limit (dLimit), an increasing step (dDelta)
;             and a maximum size (dMaxCapacity).
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: Maximum capacity of the collection (#items).
;                   Use COL_MAX_CAPACITY to indicate no limit.
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
      OCall Insert, NULL, NULL                          ;Register the NULL POINTER
    .endif
  .else
    OCall xcx.ErrorReport, NULL, DLT_SETUP_ERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DesLUT.Find
; Purpose:    Searches for a XWORD value.
; Arguments:  Arg1: Old item to search for.
; Return:     eax = Status code.
;             xcx = New item that replaces to the old one.

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
      xor eax, eax                                      ;OBJ_OK
      ExitMethod
    .endif
    add xax, sizeof(DLT_ENTRY)
  .endw
  OCall pSelf::DesLUT.ErrorReport, NULL, DLT_ITEM_NOT_FOUND
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       DesLUT.ForEach
; Purpose:      Call "pProc" for each item in the DesLUT.
; Arguments:    Arg1: -> Processing procedure (static address).
;               Arg2-3: (Optional) Parameters to be used by the processing procedure.
; Return:       Nothing.
; Note:         While the loop is running, no item should be deleted!

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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DesLUT.Insert
; Purpose:    Insert item information in the lookup table. Only the owner of the item should insert
;             this information. Multiple entries containing the same info MUST be avoided. No
;             integrity check is performed.
; Arguments:  Arg1: -> Old item.
;             Arg2: -> New item.
; Return:     xax -> New Item.

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
    m2m [xcx].DLT_ENTRY.xNewItem, xNewItem, xax         ;xax -> Item (return value)
  .else
    OCall xsi.ErrorReport, NULL, eax
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DesLUT.SetLimit
; Purpose:    Set the collection limit, allocating the necessary memory on the heap to hold
;             the item POINTER table.
; Arguments:  Arg1: New limit.
; Return:     eax = Error code.

Method DesLUT.SetLimit, uses xbx xdi xsi, dNewLimit:DWORD
  SetObject xsi
  mov ebx, dNewLimit
  mov eax, [xsi].dCount
  cmp eax, ebx                                          ;dNewLimit
  ja @@1                                                ;NewLimit can not be less than dCount!
  mov eax, [xsi].dMaxCapacity
  cmp eax, ebx                                          ;NewLimit can not be > than dMaxCapacity!
  ht                                                    ;Hint taken
  jae @@2
  @@1:
  mov ebx, eax                                          ;Limit the new table size
  @@2:
  mov ecx, [xsi].dLimit
  cmp ecx, ebx
  .if ZERO?
    xor eax, eax                                        ;eax = OBJ_OK
  .else
    test ebx, ebx                                       ;dNewLimit = 0 ?
    .if ZERO?
      MemFree [xsi].pItems, MEM_SAFE_FREE
      xor eax, eax                                      ;eax = OBJ_OK
      mov [xsi].pItems, xax                             ;NULL
      mov [xsi].dLimit, eax                             ;0
    .else
      mov xax, xbx
      shl xax, $Log2(sizeof(DLT_ENTRY))                 ;xcx*sizeof(DLT_ENTRY)
      mov xdi, [xsi].pItems
      test xdi, xdi
      .if ZERO?
        MemAlloc xax
      .else
        MemReAlloc xdi, xax
      .endif
      test xax, xax                                     ;Function failed?
      jz @@Error
      mov [xsi].pItems, xax
      mov [xsi].dLimit, ebx                             ;dNewLimit
      xor eax, eax                                      ;eax = OBJ_OK (return value)
    .endif
  .endif
  ret

@@Error:
  mov eax, DLT_OUT_OF_MEMORY                            ;Return value
MethodEnd


; ==================================================================================================
;  Stream
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.CopyFrom
; Purpose:    Copy count bytes from the specified stream into the current stream and move the
;             current position by Count bytes. The operation is performed in data chuncks of max.
;             1024 bytes.
; Arguments:  Arg1: -> Stream object.
;             Arg2: Number of bytes to copy.
; Return:     eax = Number of copied bytes.

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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.Get
; Purpose:    Read a streamable object from the stream. The object must have been
;             previously written to the stream by Put.
;             - Get first reads an Object ID (32 bits) from the stream.
;             - Then it finds the corresponding Object type by comparing the IDs in the
;               Object Metadata chain, starting at ??1stOMD.
;             - It finally calls the Load method of that object type to create and restore
;               the object.
;             If the Object type ID read from the stream is zero, Get returns NULL.
;             If the Object type ID can not be found, Get calls ErrorReport and returns NULL.
; Arguments:  Arg1: -> DesLUT passed to the "Streamable.Load" method.
; Return:     xax -> New created object or NULL.

Method Stream.Get, uses xbx xsi, pDeserInfo:PDESER_INFO
  SetObject xsi
  OCall xsi.BinRead32                                   ;eax = Object type ID
  .if eax != 0
    invoke NewObjInst, eax                              ;Create a new object instance from ID
    .if xax != NULL
      mov xbx, xax
      OCall xax::Streamable.Load, xsi, pDeserInfo
      mov xax, xbx                                      ;xax -> Object instance
    .else
      OCall xsi.ErrorReport, NULL, STM_OUT_OF_MEMORY
      xor eax, eax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, STM_REGISTRATION_ERROR
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.GetPreAlloc
; Purpose:    Read a streamable object from the stream into a preallocated memory buffer.
; Arguments:  Arg1: Address where the object instance will be loaded.
;             Arg2: Expected object type ID. Zero means don't care.
;             Arg3: Parameter passed to the "Streamable.Load" method.
; Return:     eax = Error code.
; Note:       Useful for embedded or static objects.

Method Stream.GetPreAlloc, uses xsi, pObject:POINTER, TypeID:DWORD, pDeserInfo:PDESER_INFO
  SetObject xsi
  OCall xsi.BinRead32                                   ;eax = Object type ID from stream
  mov ecx, TypeID
  .if ecx == 0 || ecx == eax
    OCall pObject::Streamable.Load, xsi, pDeserInfo
  .else
    OCall xsi.ErrorReport, NULL, STM_INCORRECT_TYPE_ID
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.Put
; Purpose:    Put a streamable object in a stream. First writes the object type ID.
; Arguments:  Arg1: -> Streamable object.
; Return:     Nothing.

Method Stream.Put,, pStreamable:POINTER
  .if pStreamable == NULL
    OCall ErrorReport, NULL, STM_INVALID_OBJECT
  .else
    invoke GetObjectID, pStreamable                     ;eax = Object type ID
    .if eax == 0
      OCall ErrorReport, NULL, STM_REGISTRATION_ERROR
    .else
      OCall BinWrite32, eax
      OCall pStreamable::Streamable.Store, pSelf
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.StrRead
; Purpose:    Read a zero terminated string from the current position of the stream and allocate
;             it on the heap.
; Arguments:  None.
; Return:     xax -> Zero terminated string or NULL (ANSI or WIDE).

Method Stream.StrRead, uses xbx xsi
  SetObject xsi
  OCall xsi.BinRead32                                   ;Total string size, including ZTC
  .if eax != 0
    mov ebx, eax                                        ;Save string size in ebx
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      invoke GlobalAlloc, 0, eax                        ;Strings use global memory
    elseif TARGET_PLATFORM eq PLATFORM_UEFI
      MemAlloc eax
    endif
    .if xax != NULL
      mov xdx, xax
      xchg xbx, xax                                      ;xax -> allocated block
      OCall xsi.BinRead, xdx, eax                        ;Returns read bytes in eax
      mov xax, xbx
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.StrWriteA
; Purpose:    Write a zero terminated string to the stream at the current position.
; Arguments:  Arg1: -> Zero terminated ANSI string.
; Return:     Nothing.

Method Stream.StrWriteA, uses xdi xsi, pStr:PSTRINGA
  SetObject xsi
  .if pStr == NULL
    OCall xsi.BinWrite32, 0
  .else
    invoke StrSizeA, pStr                               ;StrSize includes the ZTC, allowing the
    mov edi, eax                                        ;differentiation between an empty and a
    OCall xsi.BinWrite32, eax                           ;NULL-String
    OCall xsi.BinWrite, pStr, edi
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Stream.StrWriteW
; Purpose:    Write a zero terminated string to the stream at the current position.
; Arguments:  Arg1: -> Zero terminated WIDE string.
; Return:     Nothing.

Method Stream.StrWriteW, uses xdi xsi, pStr:PSTRINGW
  SetObject xsi
  .if pStr == NULL
    OCall xsi.BinWrite32, 0
  .else
    invoke StrSizeW, pStr                               ;StrSize includes the ZTC, allowing the
    mov edi, eax                                        ;differentiation between an empty and a
    OCall xsi.BinWrite32, eax                           ;NULL-String
    OCall xsi.BinWrite, pStr, edi
  .endif
MethodEnd


; ==================================================================================================
;  Streamable
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Streamable.Deserialize
; Purpose:    Convert serialized members.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method Streamable.Deserialize, uses xsi, pDeserInfo:PDESER_INFO
  SetObject xsi
  mov xdx, pDeserInfo
  .if $OCall([xdx].DESER_INFO.pDesLUT::DesLUT.Find, [xsi].pErrorCaller) == OBJ_OK
    mov [xsi].pErrorCaller, xcx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Streamable.Load
; Purpose:    Load and initialize the streamable instance from a stream object. Descendant objects
;             must redefine this method to load new members.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     eax = Status code.

Method Streamable.Load, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  mov xdi, pStream
  mov xbx, pDeserInfo
  OCall xdi::Stream.BinReadX                           ;Old pSelf
  OCall [xbx].DESER_INFO.pDesLUT::DesLUT.Insert, xax, xsi

  OCall xdi::Stream.BinReadX                           ;Old pOwner
  .if $OCall([xbx].DESER_INFO.pDesLUT::DesLUT.Find, xax) == OBJ_OK
    mov [xsi].pOwner, xcx
    OCall xdi::Stream.BinRead32
    mov [xsi].dErrorCode, eax

    ;This POINTER must be deserialized, since the information may not be present at this moment
    mov [xsi].pErrorCaller, $OCall(xdi::Stream.BinReadX)
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Streamable.Serialize
; Purpose:    Get an unique identifier and store it in pSelf. In case of thread concurrency, an
;             atomic process warranties unique IDs. Descendant objects should redefine this method
;             and serialize all members that need special handling like pointers.
; Arguments:  None.
; Return:     Nothing.

Method Streamable.Serialize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Streamable.Store
; Purpose:    Store the streamable instance in a stream object. Descendant objects should redefine
;             this method and store new members.
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
