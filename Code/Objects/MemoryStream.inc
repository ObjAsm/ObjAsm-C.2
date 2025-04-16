; ==================================================================================================
; Title:      MemoryStream.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of memory streaming objects.
; Notes:      Version C.1.2, december 2020
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     MemoryStream
; Purpose:    Implements an "in memory" stream. 4GB max capacity.

Object MemoryStream, MemoryStreamID, Stream
  RedefineMethod      BinRead,      POINTER, DWORD      ;-> Buffer, Count
  RedefineMethod      BinRead8
  RedefineMethod      BinRead16
  RedefineMethod      BinRead32
  RedefineMethod      BinRead64
  RedefineMethod      BinWrite,     POINTER, DWORD      ;-> Buffer, Count
  RedefineMethod      BinWrite8,    BYTE
  RedefineMethod      BinWrite16,   WORD
  RedefineMethod      BinWrite32,   DWORD
  RedefineMethod      BinWrite64,   QWORD
  VirtualMethod       BufferLoad,   POINTER, DWORD      ;-> Buffer, Size
  VirtualMethod       BufferSave,   POINTER             ;-> Buffer
  RedefineMethod      Done
  VirtualMethod       FileLoad,     PSTRING             ;-> FileName
  VirtualMethod       FileSave,     PSTRING             ;-> FileName
  RedefineMethod      GetPos                            ;Returns QWORD edx::eax
  RedefineMethod      GetSize                           ;Returns QWORD edx::eax
  RedefineMethod      Init,         POINTER, DWORD, DWORD, DWORD  ;-> Owner, Capacity, Incr., Max.
  RedefineMethod      Seek,         SQWORD, DWORD       ;Position
  StaticMethod        SetCapacity,  DWORD
  RedefineMethod      Truncate
                      
  DefineVariable      pBuffer,      POINTER,      NULL  ;-> Storage buffer
  DefineVariable      dCurrSize,    DWORD,        0     ;Storage current size
  DefineVariable      dPosition,    DWORD,        0     ;Current position into storage
  DefineVariable      dLimit,       DWORD,        0     ;Current storage capacity
  DefineVariable      dDelta,       DWORD,        0     ;Storage capacity increment
  DefineVariable      dMaxSize,     DWORD,        0     ;Maximal storage capacity
  DefineVariable      ObjLock,      OBJECT_LOCK,  {}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinRead
; Purpose:    Reads a number of bytes from stream at the current position to a buffer.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Number of bytes to read.
; Return:     eax = Bytes read.

Method MemoryStream.BinRead, uses xsi, pBuffer:POINTER, dCount:DWORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov eax, [xsi].dPosition
    mov ecx, [xsi].dCurrSize
    sub ecx, eax
    .if ecx < dCount
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
    .else
      add xax, [xsi].pBuffer
      invoke MemClone, pBuffer, xax, dCount
      mov eax, dCount                               ;Set return value
      add [xsi].dPosition, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinRead8
; Purpose:    Read a byte from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     eax = Read BYTE value.
;             ecx = Bytes read.

Method MemoryStream.BinRead8, uses xsi
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    mov edx, [xsi].dPosition
    mov eax, [xsi].dCurrSize
    sub eax, edx
    mov ecx, sizeof(BYTE)
    .if eax < ecx
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
      xor ecx, ecx
    .else
      add xdx, [xsi].pBuffer
      movzx eax, BYTE ptr [xdx]
      add [xsi].dPosition, ecx
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinRead16
; Purpose:    Read a word from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     eax = Read WORD value.
;             ecx = Bytes read.

Method MemoryStream.BinRead16, uses xsi
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    mov edx, [xsi].dPosition
    mov eax, [xsi].dCurrSize
    sub eax, edx
    mov ecx, sizeof(WORD)
    .if eax < ecx
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
      xor ecx, ecx
    .else
      add xdx, [xsi].pBuffer
      movzx eax, WORD ptr [xdx]
      add [xsi].dPosition, ecx
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinRead32
; Purpose:    Read a DWORD from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     eax = Read DWORD value.
;             ecx = Bytes read.

Method MemoryStream.BinRead32, uses xsi
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    mov edx, [xsi].dPosition
    mov eax, [xsi].dCurrSize
    sub eax, edx
    mov ecx, sizeof(DWORD)
    .if eax < ecx
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
      xor ecx, ecx
    .else
      add xdx, [xsi].pBuffer
      mov eax, DWORD ptr [xdx]
      add [xsi].dPosition, ecx
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinRead64
; Purpose:    Read a QWORD from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     rax or edx::eax = Read QWORD value.
;             ecx = Bytes read.

Method MemoryStream.BinRead64, uses xsi
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    mov edx, [xsi].dPosition
    mov eax, [xsi].dCurrSize
    sub eax, edx
    mov ecx, sizeof(QWORD)
    .if eax < ecx
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
      xor ecx, ecx
    .else
      add xdx, [xsi].pBuffer
      mov xax, XWORD ptr [xdx]
      if TARGET_BITNESS eq 32
        mov edx, DWORD ptr [xdx + sizeof(DWORD)]
      endif
      add [xsi].dPosition, ecx
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinWrite
; Purpose:    Write should write Count bytes from Buffer onto the stream and advance the
;             current position of the stream by Count bytes.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Number of bytes to write.
; Return:     eax = Bytes written.

Method MemoryStream.BinWrite, uses xsi, pBuffer:POINTER, dCount:DWORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov ecx, [xsi].dPosition
    add ecx, dCount
    mov eax, [xsi].dLimit
    .if eax < ecx
      align ALIGN_CODE
      .repeat
        add eax, [xsi].dDelta
      .until eax >= ecx
      .if eax <= [xsi].dMaxSize
        OCall xsi.SetCapacity, eax
        ExitMethod .if eax == 0
      .else
        OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
        ExitMethod
      .endif
    .endif
    mov eax, [xsi].dPosition
    add xax, [xsi].pBuffer
    invoke MemClone, xax, pBuffer, dCount
    mov eax, dCount                               ;Set return value
    add [xsi].dPosition, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinWrite8
; Purpose:    Write a byte value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: Byte value.
; Return:     eax = Bytes written (= 1).

Method MemoryStream.BinWrite8, uses xsi, bValue:BYTE
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov eax, sizeof(BYTE)
    mov ecx, [xsi].dPosition
    add ecx, eax
    mov edx, [xsi].dLimit
    .if edx < ecx
      align ALIGN_CODE
      .repeat
        add edx, [xsi].dDelta
      .until edx >= ecx
      .if edx <= [xsi].dMaxSize
        OCall xsi.SetCapacity, edx                ;Zero if failed
        ExitMethod .if eax == 0
      .else
        OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
        ExitMethod
      .endif
      mov eax, sizeof(BYTE)                       ;Set return value
    .endif
    mov edx, [xsi].dPosition
    add xdx, [xsi].pBuffer
    mov cl, bValue
    mov [xdx], cl
    add [xsi].dPosition, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinWrite16
; Purpose:    Write a word value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: Word value.
; Return:     eax = Bytes written (= 2).

Method MemoryStream.BinWrite16, uses xsi, wValue:WORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov eax, sizeof(WORD)
    mov ecx, [xsi].dPosition
    add ecx, eax
    mov edx, [xsi].dLimit
    .if edx < ecx
      align ALIGN_CODE
      .repeat
        add edx, [xsi].dDelta
      .until edx >= ecx
      .if edx <= [xsi].dMaxSize
        OCall xsi.SetCapacity, edx                ;Zero if failed
        ExitMethod .if eax == 0
      .else
        OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
        ExitMethod
      .endif
      mov eax, sizeof(WORD)                       ;Set return value
    .endif
    mov edx, [xsi].dPosition
    add xdx, [xsi].pBuffer
    mov cx, wValue
    mov [xdx], cx
    add [xsi].dPosition, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinWrite32
; Purpose:    Write a DWORD value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: DWORD value.
; Return:     eax = Bytes written (= 4).

Method MemoryStream.BinWrite32, uses xsi, dValue:DWORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov eax, sizeof(DWORD)
    mov ecx, [xsi].dPosition
    add ecx, eax
    mov edx, [xsi].dLimit
    .if edx < ecx
      align ALIGN_CODE
      .repeat
        add edx, [xsi].dDelta
      .until edx >= ecx
      .if edx <= [xsi].dMaxSize
        OCall xsi.SetCapacity, edx                ;Zero if failed
        ExitMethod .if eax == 0
      .else
        OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
        ExitMethod
      .endif
      mov eax, sizeof(DWORD)                      ;Set return value
    .endif
    mov edx, [xsi].dPosition
    add xdx, [xsi].pBuffer
    mov ecx, dValue
    mov [xdx], ecx
    add [xsi].dPosition, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BinWrite64
; Purpose:    Write a QWORD value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: QWORD value.
; Return:     eax = Bytes written (= 8).

Method MemoryStream.BinWrite64, uses xsi, qValue:QWORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov eax, sizeof(QWORD)
    mov ecx, [xsi].dPosition
    add ecx, eax
    mov edx, [xsi].dLimit
    .if edx < ecx
      align ALIGN_CODE
      .repeat
        add edx, [xsi].dDelta
      .until edx >= ecx
      .if edx <= [xsi].dMaxSize
        OCall xsi.SetCapacity, edx                ;Zero if failed
        ExitMethod .if eax == 0
      .else
        OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
        ExitMethod
      .endif
      mov eax, sizeof(QWORD)                      ;Set return value
    .endif
    mov edx, [xsi].dPosition
    add xdx, [xsi].pBuffer
    mov xcx, XWORD ptr [qValue]
    mov [xdx], xcx
    if TARGET_BITNESS eq 32
      mov ecx, DWORD ptr [qValue + sizeof(DWORD)]
      mov [edx + sizeof(DWORD)], ecx
    endif
    add [xsi].dPosition, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BufferLoad
; Purpose:    Loads the stream content from a buffer.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Buffer size in bytes.
; Return:     Nothing.

Method MemoryStream.BufferLoad, uses xsi, pBuffer:POINTER, dSize:DWORD
  SetObject xsi
  mov eax, [xsi].dLimit
  .if eax < dSize
    align ALIGN_CODE
    .repeat
      add eax, [xsi].dDelta
    .until eax >= dSize
    .if eax > [xsi].dMaxSize
      OCall xsi.ErrorReport, NULL, STM_OVERFLOW
      ExitMethod
    .else
      and [xsi].dCurrSize, 0                      ;Forget old content!
      OCall xsi.SetCapacity, eax
      ExitMethod .if [xsi].dErrorCode !!= OBJ_OK
    .endif
  .endif
  invoke MemClone, [xsi].pBuffer, pBuffer, dSize
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.BufferSave
; Purpose:    Saves the stream content to a buffer.
; Arguments:  Arg1: -> Buffer.
; Return:     Nothing.

Method MemoryStream.BufferSave,, pBuffer:POINTER
  SetObject xax
  invoke MemClone, pBuffer, [xax].pBuffer, [xax].dCurrSize
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.Done
; Purpose:    Finalizes the object.
; Arguments:  None.
; Return:     Nothing.

Method MemoryStream.Done, uses xsi
  SetObject xsi
  .if [xsi].pBuffer != NULL
    MemFree [xsi].pBuffer
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.FileLoad
; Purpose:    Recovers the stream object from file.
; Arguments:  Arg1: -> ANSI string containing the file name.
; Return:     Nothing.

Method MemoryStream.FileLoad, uses xsi, pFileName:PSTRING
  local hFile:HANDLE, dBytesRead:DWORD, dNewLimit:DWORD

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_READ, 0, NULL, \
                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
  .if xax == INVALID_HANDLE_VALUE
    OCall xsi.ErrorReport, NULL, STM_FILE_NOT_FOUND
    ExitMethod
  .endif
  mov hFile, xax
  invoke ReadFile, hFile, addr [xsi].dErrorCode, sizeof $Obj(MemoryStream).dErrorCode, \
                   addr dBytesRead, NULL
  test eax, eax
  je @@Error
  invoke ReadFile, hFile, addr dNewLimit, sizeof $Obj(MemoryStream).dLimit, addr dBytesRead, NULL
  test eax, eax
  je @@Error
  mov eax, dNewLimit
  .if eax > [xsi].dMaxSize
    OCall xsi.ErrorReport, NULL, STM_OVERFLOW
    jmp @@Exit
  .endif
  and [xsi].dCurrSize, 0                          ;Forget old content!
  OCall xsi.SetCapacity, eax
  cmp [xsi].dErrorCode, OBJ_OK
  jne @@Error
  invoke ReadFile, hFile, addr [xsi].dCurrSize, sizeof $Obj(MemoryStream).dCurrSize, \
         addr dBytesRead, NULL
  test eax, eax
  je @@Error
  invoke ReadFile, hFile, addr [xsi].dPosition, sizeof $Obj(MemoryStream).dPosition, \
         addr dBytesRead, NULL
  test eax, eax
  je @@Error
  invoke ReadFile, hFile, [xsi].pBuffer, [xsi].dCurrSize, addr dBytesRead, NULL
  test eax, eax
  jne @@Exit
@@Error:
  OCall xsi.ErrorReport, NULL, STM_READ_ERROR
@@Exit:
  invoke CloseHandle, hFile
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.FileSave
; Purpose:    Stores the stream object to file.
; Arguments:  Arg1: -> ANSI string containing the file name.
; Return:     Nothing.

Method MemoryStream.FileSave, uses xsi, pFileName:PSTRING
  local hFile:HANDLE, dBytesWritten:DWORD

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_WRITE, 0, NULL, \
                     CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
  mov hFile, xax
  invoke WriteFile, hFile, addr [xsi].dErrorCode, sizeof $Obj(MemoryStream).dErrorCode, \
                           addr dBytesWritten, NULL
  test eax, eax
  je @@Error
  invoke WriteFile, hFile, addr [xsi].dLimit, sizeof $Obj(MemoryStream).dLimit, \
                    addr dBytesWritten, NULL
  test eax, eax
  je @@Error
  invoke WriteFile, hFile, addr [xsi].dCurrSize, sizeof $Obj(MemoryStream).dCurrSize, \
                    addr dBytesWritten, NULL
  test eax, eax
  je @@Error
  invoke WriteFile, hFile, addr [xsi].dPosition, sizeof $Obj(MemoryStream).dPosition, \
                    addr dBytesWritten, NULL
  test eax, eax
  je @@Error
  invoke WriteFile, hFile, [xsi].pBuffer, [xsi].dCurrSize, addr dBytesWritten, NULL
  test eax, eax
  jne @@Exit
@@Error:
  OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
@@Exit:
  invoke CloseHandle, hFile
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.GetPos
; Purpose:    Returns the current position into the memory stream.
; Arguments:  None.
; Return:     edx::eax = Current position into stream.

Method MemoryStream.GetPos
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    mov eax, [xcx].dPosition
    xor edx, edx
  .else
    mov eax, -1
    mov edx, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.GetSize
; Purpose:    Returns the current file size of the stream.
; Arguments:  None.
; Return:     edx::eax = Size of Stream.

Method MemoryStream.GetSize
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    mov eax, [xcx].dCurrSize
    xor edx, edx
  .else
    mov eax, -1
    mov edx, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Buffer capacity in bytes.
;             Arg3: Buffer increment in bytes.
;             Arg4: Buffer maximal size in bytes.
; Return:     Nothing.

Method MemoryStream.Init, uses xsi, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dMaxSize:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].dDelta, dDelta, edx
  m2m [xsi].dMaxSize, dMaxSize, edx
  mov eax, dLimit
  .if eax <= dMaxSize
    OCall xsi.SetCapacity, eax
  .else
    OCall xsi.ErrorReport, NULL, STM_SETUP_ERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.Seek
; Purpose:    Seek sets the current position to NewPosition bytes from the start of the calling
;             stream. The start of a stream is position 0. HiPart of qNewPosition is ignored!
; Arguments:  Arg1: New position.
;             Arg2: Positioning beginning.
; Return:     Nothing.

Method MemoryStream.Seek,, sqNewPosition:SQWORD, dMode
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    mov edx, (QUADWORD ptr sqNewPosition).HiDWord
    .if edx != 0
      OCall xcx.ErrorReport, NULL, STM_SEEK_ERROR
    .else
      mov eax, (QUADWORD ptr sqNewPosition).LoDWord
      .if dMode == STM_BEGIN
        xor edx, edx
      .elseif dMode == STM_CURRENT
        mov edx, [xcx].dPosition
      .elseif dMode == STM_CURRENT
        mov edx, [xcx].dCurrSize
      .else
        OCall xcx.ErrorReport, NULL, STM_SEEK_ERROR
        ExitMethod
      .endif
      add edx, eax
      .if CARRY? || edx > [xcx].dCurrSize
        OCall xcx.ErrorReport, NULL, STM_SEEK_ERROR
      .else
        mov [xcx].dPosition, edx
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.SetCapacity
; Purpose:    Creates a new buffer with a size of NewCapacity bytes on the heap and copies the
;             old Buffer content to the new one.
; Arguments:  Arg1: New storage dLimit in bytes.
; Return:     eax = if succeeded, allocated dLimit, otherwise 0.

Method MemoryStream.SetCapacity, uses xsi, dNewLimit:DWORD
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    .if [xsi].pBuffer == NULL
      MemAlloc dNewLimit
    .else
      MemReAlloc [xsi].pBuffer, dNewLimit
    .endif
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, STM_OUT_OF_MEMORY
      xor eax, eax
    .else
      mov [xsi].pBuffer, xax
      m2m [xsi].dLimit, dNewLimit, eax                ;Set return value
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MemoryStream.Truncate
; Purpose:    Deletes all data on the calling stream from the current position to the end.
; Arguments:  None.
; Return:     Nothing.

Method MemoryStream.Truncate
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    m2m [xcx].dCurrSize, [xcx].dPosition, edx
  .endif
MethodEnd

endif