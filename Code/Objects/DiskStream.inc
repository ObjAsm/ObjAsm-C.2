; ==================================================================================================
; Title:      DiskStream.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of streaming objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DISKSTREAM_INIT struc
  pOwner          POINTER   ?
  pFileName       PSTRING   ?
  dAccessMode     DWORD     ?
  dShareMode      DWORD     ?
  pSecurityAttr   POINTER   ?
  dCreationFlags  DWORD     ?
  dAttr           DWORD     ?
  hTemp           HANDLE    ?
DISKSTREAM_INIT ends
PDISKSTREAM_INIT typedef ptr DISKSTREAM_INIT

; --------------------------------------------------------------------------------------------------
; Object:     DiskStream
; Purpose:    Implement a specialised Stream descendant that uses unbuffered file access.
;             The constructor lets you create or open a disk file by specifying its name.
;             Most applications will use the buffered version of DiskStream called
;             BufferedDiskStream. DiskStream overrides all the abstract methods defined by Stream.

Object DiskStream, DiskStreamID, Stream
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
  RedefineMethod      Done
  RedefineMethod      Flush
  RedefineMethod      GetPos                            ;Returns QWORD edx::eax
  RedefineMethod      GetSize                           ;Returns QWORD edx::eax
  RedefineMethod      Init,         POINTER, PSTRING, DWORD, DWORD, POINTER, DWORD, DWORD, HANDLE
  RedefineMethod      Seek,         SQWORD, DWORD       ;Position, Mode
  RedefineMethod      Truncate

  DefineVariable      hFile,        HANDLE,     INVALID_HANDLE_VALUE
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinRead
; Purpose:    Read a specified number of bytes from stream at the current position to a buffer and
;             advance the current position into the stream.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Number of bytes to read.
; Return:     eax = Bytes read.

Method DiskStream.BinRead, uses xsi, pBuffer:POINTER, dCount:DWORD
  local dBytesRead:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke ReadFile, [xsi].hFile, pBuffer, dCount, addr dBytesRead, NULL
    .if eax != FALSE
      mov eax, dBytesRead
    .else
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinRead8
; Purpose:    Read a byte from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     eax = Read BYTE value.
;             ecx = Bytes read.

Method DiskStream.BinRead8, uses xsi
  local dBytesRead:DWORD, bValue:BYTE

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke ReadFile, [xsi].hFile, addr bValue, sizeof(BYTE), addr dBytesRead, NULL
    .if eax != FALSE
      mov ecx, dBytesRead
      movzx eax, bValue
    .else
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor ecx, ecx
      xor eax, eax
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinRead16
; Purpose:    Read a word from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     eax = Read WORD value.
;             ecx = Bytes read.

Method DiskStream.BinRead16, uses xsi
  local dBytesRead:DWORD, wValue:WORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke ReadFile, [xsi].hFile, addr wValue, sizeof(WORD), addr dBytesRead, NULL
    .if eax != FALSE
      mov ecx, dBytesRead
      movzx eax, wValue
    .else
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor ecx, ecx
      xor eax, eax
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinRead32
; Purpose:    Read a DWORD from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     eax = Read DWORD value.
;             ecx = Bytes read.

Method DiskStream.BinRead32, uses xsi
  local dBytesRead:DWORD, dValue:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke ReadFile, [xsi].hFile, addr dValue, sizeof(DWORD), addr dBytesRead, NULL
    .if eax != FALSE
      mov ecx, dBytesRead
      mov eax, dValue
    .else
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor ecx, ecx
      xor eax, eax
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinRead64
; Purpose:    Read a QWORD from stream at the current position, returns it in the ecx register and
;             advance the current position into the stream.
; Arguments:  Nothing.
; Return:     rax or edx::eax = Read QWORD value.
;             ecx = Bytes read.

Method DiskStream.BinRead64, uses xsi
  local dBytesRead:DWORD, qValue:QWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke ReadFile, [xsi].hFile, addr qValue, sizeof(QWORD), addr dBytesRead, NULL
    .if eax != FALSE
      mov ecx, dBytesRead
      mov xax, XWORD ptr [qValue]
      if TARGET_BITNESS eq 32
        mov edx, DWORD ptr [qValue + sizeof(DWORD)]
      endif
    .else
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor ecx, ecx
      xor eax, eax
    .endif
  .else
    xor ecx, ecx
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinWrite
; Purpose:    Write a specified number of bytes from buffer onto the stream and advance the
;             current position into the stream.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Number of bytes to write.
; Return:     eax = Bytes written.

Method DiskStream.BinWrite, uses xsi, pBuffer:POINTER, dCount:DWORD
  local dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke WriteFile, [xsi].hFile, pBuffer, dCount, addr dBytesWritten, NULL
    .if eax != FALSE
      mov eax, dBytesWritten
    .else
      OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinWrite8
; Purpose:    Write a byte value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: Byte value.
; Return:     eax = Bytes written (= 1).

Method DiskStream.BinWrite8, uses xsi, bValue:BYTE
  local dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke WriteFile, [xsi].hFile, addr bValue, sizeof(BYTE), addr dBytesWritten, NULL
    .if eax != FALSE
      mov eax, dBytesWritten
    .else
      OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinWrite16
; Purpose:    Write a word value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: Word value.
; Return:     eax = Bytes written (= 2).

Method DiskStream.BinWrite16, uses xsi, wValue:WORD
  local dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke WriteFile, [xsi].hFile, addr wValue, sizeof(WORD), addr dBytesWritten, NULL
    .if eax != FALSE
      mov eax, dBytesWritten
    .else
      OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinWrite32
; Purpose:    Write a DWORD value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: DWORD value.
; Return:     eax = Bytes written (= 4).

Method DiskStream.BinWrite32, uses xsi, dValue:DWORD
  local dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke WriteFile, [xsi].hFile, addr dValue, sizeof(DWORD), addr dBytesWritten, NULL
    .if eax != FALSE
      mov eax, dBytesWritten
    .else
      OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.BinWrite64
; Purpose:    Write a QWORD value onto the stream and advance the current position into the stream.
; Arguments:  Arg1: QWORD value.
; Return:     eax = Bytes written (= 8).

Method DiskStream.BinWrite64, uses xsi, qValue:QWORD
  local dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke WriteFile, [xsi].hFile, addr qValue, sizeof(QWORD), addr dBytesWritten, NULL
    .if eax != FALSE
      mov eax, dBytesWritten
    .else
      OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.Done
; Purpose:    Finalize of DiskStream object.
; Arguments:  None.
; Return:     Nothing.

Method DiskStream.Done, uses xsi
  SetObject xsi
  .if [xsi].hFile != INVALID_HANDLE_VALUE
    invoke CloseHandle, [xsi].hFile
    mov [xsi].hFile, INVALID_HANDLE_VALUE
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.Flush
; Purpose:    Do nothing.
; Arguments:  None.
; Return:     Nothing.

Method DiskStream.Flush
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.GetPos
; Purpose:    Return the current position of the file POINTER into the stream.
; Arguments:  None.
; Return:     rax or edx::eax = Current position into stream or -1 if failed.

Method DiskStream.GetPos
  local qCurPos:QWORD

  SetObject xcx
  mov xax, -1                                           ;Error return value
  .if [xcx].dErrorCode == OBJ_OK
    invoke SetFilePointerEx, [xcx].hFile, 0, addr qCurPos, FILE_CURRENT ;Returns file POINTER pos.
    mov xax, XWORD ptr [qCurPos]
    if TARGET_BITNESS eq 32
      mov edx, DWORD ptr [qCurPos + sizeof(DWORD)]
    endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.GetSize
; Purpose:    Return the current file size of the stream.
; Arguments:  None.
; Return:     rax or edx::eax = Size of stream or -1 if failed.

Method DiskStream.GetSize
  local qFileSize:QWORD

  SetObject xcx
  mov xax, -1                                           ;Error return value
  if TARGET_BITNESS eq 32
    mov edx, -1                                         ;Error return value
  endif
  .if [xcx].dErrorCode == OBJ_OK
    invoke GetFileSizeEx, [xcx].hFile, addr qFileSize   ;Returns current File Size
    mov xax, XWORD ptr [qFileSize]
    if TARGET_BITNESS eq 32
      mov edx, DWORD ptr [qFileSize + sizeof(DWORD)]
    endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.Init
; Purpose:    Initialize DiskStream object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> File name string.
;             Arg3 Access mode (0, GENERIC_READ, GENERIC_WRITE).
;             Arg4 Share mode (0, FILE_SHARE_DELETE, FILE_SHARE_READ, FILE_SHARE_WRITE).
;             Arg5: -> Security Attributes (SECURITY_ATTRIBUTES struc)
;             Arg6: Creation flags (CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, etc.)
;             Arg7: Attributes (FILE_ATTRIBUTE_ARCHIVE, FILE_ATTRIBUTE_NORMAL, etc.)
;             Arg8: Template file HANDLE.
; Return:     Nothing.

Method DiskStream.Init, uses xsi, pOwner:POINTER, pFileName:PSTRING, dAccessMode:DWORD, \
                                  dShareMode:DWORD, pSecurityAttr:POINTER, dCreationFlags:DWORD, \
                                  dAttr:DWORD, hTemp:HANDLE
  SetObject xsi

  ACall xsi.Init, pOwner

  .if dAttr == 0
    mov dAttr, FILE_ATTRIBUTE_NORMAL                    ;Default file attribute
  .endif

  .if dCreationFlags == 0
    mov dCreationFlags, OPEN_ALWAYS                     ;Default file creation
  .endif

  .if dShareMode == 0
    mov dShareMode, FILE_SHARE_READ or FILE_SHARE_WRITE ;Default file share mode
  .endif

  .if dAccessMode == 0
    mov dAccessMode, GENERIC_READ or GENERIC_WRITE      ;Default file access mode
  .endif

  invoke CreateFile, pFileName, dAccessMode, dShareMode, pSecurityAttr, dCreationFlags, dAttr, hTemp
  mov [xsi].hFile, xax

  .if xax == INVALID_HANDLE_VALUE
    OCall xsi.ErrorReport, NULL, STM_OPEN_ERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.Seek
; Purpose:    Move file POINTER to a new position.
; Arguments:  Arg1: New 64 bit position.
;             Arg2: Seek mode parameter [STM_BEGIN, STM_CURRENT, STM_END]
; Return:     Nothing.
; Note:       In 32 bit mode, use the following syntax
;             OCall xdi::DiskStream.Seek, QWORD ptr 0, STM_BEGIN

Method DiskStream.Seek,, sqPosition:SQWORD, dSeekMode:DWORD
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    invoke SetFilePointerEx, [xcx].hFile, sqPosition, NULL, dSeekMode
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DiskStream.Truncate
; Purpose:    Truncate the stream at the current position.
; Arguments:  None.
; Return:     Nothing.

Method DiskStream.Truncate
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    invoke SetEndOfFile, [xcx].hFile
  .endif
MethodEnd

endif
