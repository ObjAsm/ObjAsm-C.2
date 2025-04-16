; ==================================================================================================
; Title:      NetComFile.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Asynchronous file IO via NetCom's IOCP Engine.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Read/Write Completion Methods are Mutexed (ObjLock) within
;                 NetComEngine.WorkerThread
;               - This protects internal counters from being corrupted by simultaneous completions.
;               - IT DOES NOT GUARANTEE ORDER OF COMPLETION.
;               - However, we tagged each IOSockJob with a 64-bit Offset ("FilePosition") :)
;                 GUARANTEEING ORDER OF COMPLETION.
;               - Your NetComFileEvents eventsink object must implement its own FilePosition
;                 counter, and collect any IOJobs whose 64-bit Offset doesn't match the current
;                 FilePosition
;               - Collected Jobs will have to be dealt with in a delayed way.
;               - NOTE that EventSink notification calls are already within an ObjectLock!
;               - Your EventSink methods (and their counters and other data) are effectively
;                 threadsafe !
; ==================================================================================================



.code

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.BinRead
; Purpose:    Read some data from the file.
; Args:       Arg1: Bytes to read.
; Note:       Be sure to call SetFilePointer at least once prior to this call!
;             Notifications will be received the usual way.

Method NetComFile.BinRead, uses xbx xsi, dLength:DWORD
  SetObject xsi
  .while dLength != 0
    ;Allocate an IOSockJob
    mov xdx, [xsi].pOwner
    OCall [xdx].$Obj(NetComEngine).IOJobs::NetComIOSockJobPool.NewItem, xsi, OPERATION_FILE_READ
    .if xax != NULL
      ;Determine how much data to put into this IOSockJob
      mov xdx, xax
      mov ebx, [xcx].IO_FILEJOB.IO_Buf.dSize
      .if ebx > dLength
        mov ebx, dLength
      .endif
      mov [xdx].IO_FILEJOB.dBytesUsed, ebx
      sub dLength, ebx
      ;Copy the IO Offset into the Job
      m2m [xcx].IO_FILEJOB.Ovl.OffsetHigh, [xsi].qOffset.QUADWORD.HiDWord, eax
      m2m [xcx].IO_FILEJOB.Ovl.OffsetLow, [xsi].qOffset.QUADWORD.LoDWord, ecx
      ;Queue the Read request
      OCall xsi.DoRead, xdx
      ;Update the IO Offset
      qdadd [xsi].qOffset, ebx
    .endif
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.BinWrite
; Purpose:    Write some data to the file
; Args:       Arg1: -> User's data to be written.
;             Arg2: Bytes to write.
; Return:     Nothing.
; Note:       Be sure to call SetFilePointer at least once prior to this call!
;             Its safe to destroy the input buffer as soon as your call completes.
;             The data will be written to the file in the background.

Method NetComFile.BinWrite, uses xbx xdi xsi, pData:POINTER, dLength:DWORD
  SetObject xsi
  .while dLength != 0
    ;Allocate an IOSockJob
    mov xdx, [xsi].pOwner
    lea xbx, [xdx].$Obj(NetComEngine).IOJobs
    OCall xbx::NetComIOSockJobPool.NewItem, xsi, OPERATION_FILE_READ
    .if xax != NULL
      ;Determine how much data to put into this IOSockJob
      mov xbx, xax
      mov eax, [xbx].IO_FILEJOB.IO_Buf.dSize
      .if eax > dLength
        mov eax, dLength
      .endif
      mov [xbx].IO_FILEJOB.dBytesUsed, eax
      sub dLength, eax
      ;Copy the IO Offset into the Job
      mrm [xbx].IO_FILEJOB.Ovl.OffsetHigh, [xsi].qOffset.QUADWORD.HiDWord, eax
      mrm [xbx].IO_FILEJOB.Ovl.OffsetLow, [xsi].qOffset.QUADWORD.LoDWord, edi
      ;Copy (one buffer or less) bytes of data into the Job
      invoke MemClone, [xbx].IO_FILEJOB.IO_Buf.pBuffer, pData, eax
      add pData, edi
      ;Update the IO Offset
      qdadd [xsi].qOffset, edi

      ;Queue the Write request
      OCall xsi.DoWrite, xbx
    .endif
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.Done
; Purpose:    Notify application that the object is redundant & release resources.
; Arguments:  None.
; Return:     Nothing.

Method NetComFile.Done, uses xsi
  SetObject xsi
  DbgWarning "NetComFile.Done"
  mov xcx, [xsi].pEventSink
  .if xcx != NULL
    ;Warn the application that this NetComFile is about to be destroyed
    OCall xcx::NetComFileEvents.OnClose, xsi
    m2z [xsi].pEventSink
  .endif
  ACall Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.DoRead
; Purpose:    Perform call to initiate Overlapped FileRead request.
; Arguments:  Arg1: -> IO_FILEJOB.
; Return:     eax = TRUE/FALSE.
; Note:       Assumes the IOSockJob has been initialized with valid values.

Method NetComFile.DoRead, uses xbx xsi, pIOFileJob:PIO_FILEJOB
  ;Set the File Offset for this FileRead request
  SetObject xsi
  mov xbx, pIOFileJob
  .if [xbx].IO_FILEJOB.dBytesUsed != 0
;    DbgDec [xbx].IO_FILEJOB.dBytesUsed, "requesting read"

    ;Queue the Read request
    invoke ReadFile, [xsi].hFile, [xbx].IO_FILEJOB.IO_Buf.pBuffer, [xbx].IO_FILEJOB.dBytesUsed, \
                     addr [xbx].IO_FILEJOB.dBytesUsed, xbx
    .if eax != TRUE                                   ;Did read IO complete synchronously?
      invoke GetLastError                             ;No, check if it is a pending state
      .if eax != ERROR_IO_PENDING
        OCall xsi.OnError, pIOFileJob, eax
        xor eax, eax
      .endif
    .endif
  .else
    ;FileStream is exhausted - End Of File
    mov xdx, [xsi].pEventSink
    .if xdx != NULL
      OCall xdx::NetComFileEvents.OnEOF, xsi
    .endif
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.DoWrite
; Purpose:    Perform call to initiate Overlapped FileWrite request
; Arguments:  Arg1: -> IO_FILEJOB.
; Return:     eax = TRUE/FALSE.
; Note:       Assumes the IOSockJob has been initialized with valid values.

Method NetComFile.DoWrite, uses xbx xsi, pIOFileJob:PIO_FILEJOB
  SetObject xsi
  mov xbx, pIOFileJob
  .if [xbx].IO_FILEJOB.dBytesUsed != 0
    invoke WriteFile, [xsi].hFile, [xbx].IO_FILEJOB.IO_Buf.pBuffer, [xbx].IO_FILEJOB.dBytesUsed, \
                                   addr [xbx].IO_FILEJOB.dBytesUsed, xbx
    .if eax != TRUE                                   ;Did IO complete synchronously?
      invoke GetLastError                             ;No, check if it is a pending state
      .if eax != ERROR_IO_PENDING
        ;OCall xsi.OnError, pIOFileJob
        DbgDec eax, "Unhandled error in NetComFile.DoWrite"
        int 3
        xor eax, eax
      .endif
    .endif
  .else
    DbgWarning "NetComFile.DoWrite: dBytesUsed = 0"
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.GetProgress_Percentage
; Purpose:    Convert Progress QUADWORD into Percentage DWORD.
; Return:     eax = File transfer progress (integer percentage).

Method NetComFile.GetProgress_Percent, uses xbx xsi
  SetObject xsi
  mov eax, [xsi].qProgress.QUADWORD.LoDWord
  mov edx, [xsi].qProgress.QUADWORD.HiDWord
  mov ebx, 100
  qdmul
  mov ebx, [xsi].qFileSize.QUADWORD.LoDWord
  mov ecx, [xsi].qFileSize.QUADWORD.HiDWord
  qqdiv
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.Init
; Purpose:    Attempt to Open a File for Asynch IO
; Arguments:  Arg1: -> Owner Object.
;             Arg2: -> full pathname of file
;             Arg3: Any combination of FILE_SHARE_READ, FILE_SHARE_WRITE.
;             Arg4: Any combination of GENERIC_READ, GENERIC_WRITE.
;             Arg5: -> EventSink interface derived from NetComFileEvent.
; Return:     eax = 0 if succeeded otherwise an error code.
; Note:       Failure can be due to bad SHARE access, etc.

Method NetComFile.Init, uses xsi, pOwner:POINTER, pstrPathName:POINTER, \
                                  dShareMode:DWORD, dAccessMode:DWORD, pEventSink:POINTER
  SetObject xsi
  m2m [xsi].pEventSink, pEventSink, xdx
  ;If the user requests Write access, we will use OPEN_ALWAYS
  ;This allows new files to be created.
  mov eax, dAccessMode
  and eax, GENERIC_WRITE
  .if eax != 0
    mov eax, OPEN_ALWAYS
  .else
    ;If user only wants READ access, the file should exist!
    mov eax, OPEN_EXISTING
  .endif
  ACall xsi.Init, pOwner, pstrPathName, dShareMode, dAccessMode, eax, FILE_FLAG_OVERLAPPED
  .if eax != STM_OPENERROR                            ;then eax = hFile, I think...
    invoke GetLastError
    .if eax == ERROR_ALREADY_EXISTS
      ;This isnt really an error
      DbgText "opened EXISTING file"
    .elseif eax != 0
      ;Return unhandled error
      DbgDec eax, "returning error code"
      ExitMethod
    .endif

    ;Bind the FileHandle to the IOCP
    mov xdx, pOwner
    invoke CreateIoCompletionPort, [xsi].hFile, [xdx].$Obj(NetComEngine).hIOCP, 0, 0
    .if eax == 0
      ;Possibly not an error if a given filehandle is already associated
      DbgWarning "NetComFile.Init Error - failed to bind FileHandle to IOCP"
      invoke GetLastError
      DbgDec eax, "Reason"
      .if eax == ERROR_INVALID_HANDLE
        DbgDec [xsi].hFile, "is an invalid handle, apparently..."
      .endif
      int 3
    .else
      ;Initialize FileSize
      invoke GetFileSize, [xsi].hFile, addr [xsi].qFileSize.QUADWORD.HiDWord
      mov [xsi].qFileSize.QUADWORD.LoDWord, eax
      OCall xsi.SetFilePointer, 0, 0
      ;Return success
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.OnRead
; Purpose:    Sink 'READ IO completion' events.
; Arguments:  Arg1: -> IO_FILEJOB.
; Return:     Nothing.

Method NetComFile.OnRead, uses xsi, pIOFileJob:PIO_FILEJOB
  local q:QUADWORD

  SetObject xsi
  ;A FileRead request has completed.

  ;Increment the progress counter
  mov xax, pIOFileJob
;  DbgDec [xsi].qProgress.QUADWORD.LoDWord
;  DbgDec [xax].IO_FILEJOB.dBytesUsed
  qdadd [xsi].qProgress, [xax].IO_FILEJOB.dBytesUsed

  ;Send Progress Notification
  .if [xsi].pEventSink != NULL
    OCall [xsi].pEventSink::NetComFileEvents.OnRead, pIOFileJob
  .endif

  ;Check for EOF
  qmov q, [xsi].qProgress
  qqsub q, [xsi].qFileSize
  .if q.LoDWord == 0 && q.HiDWord == 0
    OCall [xsi].pEventSink::NetComFileEvents.OnEOF, xsi
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.OnWrite
; Purpose:    Sink 'WRITE IO completion' events.
; Arguments:  Arg1: -> IO_FILEJOB.
; Return:     Nothing.

Method NetComFile.OnWrite,uses xsi, pIOFileJob:PIO_FILEJOB
  SetObject xsi

  ;Update FileSize - in case of access mid-file
  invoke GetFileSize, [xsi].hFile, addr [xsi].qFileSize.QUADWORD.HiDWord
  mov [xsi].qFileSize.QUADWORD.LoDWord, eax

  ;Increment the progress counter
  qdadd [xsi].qProgress, [eax].IO_FILEJOB.dBytesUsed

  ;Send Progress Notification
  .if [xsi].pEventSink != NULL
    OCall [xsi].pEventSink::NetComFileEvents.OnWrite, pIOFileJob
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.ReadFile
; Purpose:    Read the entire contents of the file.
; Arguments:  None.
; Note:       This method queues asynchronous requests for chunks of file, then returns immediately.
;             Event notifications will be sent to the User's EventSink (NetComFileEvent-derived).

Method NetComFile.ReadFile, uses xsi
  local qCount:QUADWORD

  SetObject xsi
  qmov qCount, [xsi].qFileSize
  .repeat
    .if qCount.HiDWord != 0
      ;The filesize is larger than 32 bits !!!
      ;Make the biggest READ call we possibly can with 32 bits
      OCall xsi.BinRead, -1
      qdsub qCount, -1
    .else
      .break .if qCount.LoDWord == 0
      ;The filesize is 32 bits
      ;Make a READ call for that amount
      OCall xsi.BinRead, [xsi].qFileSize.QUADWORD.LoDWord
      qdsub qCount, [xsi].qFileSize.QUADWORD.LoDWord
    .endif
  .until FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComFile.SetFilePointer
; Purpose:    Set the internal FilePointer offset (used when queuing IO requests).
; Arguments:  Arg1: File pointer (64 bit).
; Note:       With care, you can use this to random-access a file.

Method NetComFile.SetFilePointer,, qPosition:QWORD
  SetObject xcx
  m2m [xcx].qOffset.QUADWORD.HiDWord, qPosition.QUADWORD.HiDWord, eax
  m2m [xcx].qOffset.QUADWORD.LoDWord, qPosition.QUADWORD.LoDWord, edx
MethodEnd

endif
