; ==================================================================================================
; Title:      DirectoryWatcher.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Windows directory watching objects.
; Notes:      Version C.1.0, February 2025
;               - First release.
;             Version C.1.1, February 2025
;               - Shutdown sequence corrected.
;               - ProcessChanges loop offset calculation corrected.
; ==================================================================================================


;DirectoryWatcher flags
;Bits 0..8 are reserved for FILE_NOTIFY_CHANGE_XXX flags
DWF_WATCH_CHANGE_FILE_NAME    equ   FILE_NOTIFY_CHANGE_FILE_NAME
DWF_WATCH_CHANGE_DIR_NAME     equ   FILE_NOTIFY_CHANGE_DIR_NAME
DWF_WATCH_CHANGE_FILE_ATTR    equ   FILE_NOTIFY_CHANGE_ATTRIBUTES
DWF_WATCH_CHANGE_FILE_SIZE    equ   FILE_NOTIFY_CHANGE_SIZE
DWF_WATCH_CHANGE_LAST_WRITE   equ   FILE_NOTIFY_CHANGE_LAST_WRITE
DWF_WATCH_CHANGE_LAST_ACCESS  equ   FILE_NOTIFY_CHANGE_LAST_ACCESS
DWF_WATCH_CHANGE_CREATION     equ   FILE_NOTIFY_CHANGE_CREATION
DWF_WATCH_CHANGE_SECURITY     equ   FILE_NOTIFY_CHANGE_SECURITY       ;00000100h
DWF_WATCH_SUBDIRECTORIES      equ   BIT09

;DirectoryWatcher errors
DWE_OUT_OF_MEMORY             equ   1
DWE_UNHANDLED_WAIT            equ   2
DWE_READDIRECTORYCHANGESW     equ   3

MIN_ACTION_CODE               equ   1
MAX_ACTION_CODE               equ   5

DIR_WATCHER_BUFFER_SIZE       equ   16384

DWCALLBACK typedef proto :LPARAM, :DWORD, :PSTRINGW

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DirectoryWatcher
; Purpose:    This object monitors the subscribed changes in a directory and optionally its
;             subdirectories. It uses the ReadDirectoryChangesW API to cache all changes for later
;             processing.
;             ReadDirectoryChangesW is prone to dropping changes if the information is not fetched
;             fast enough. This returned information is stored in a linked list by one thread
;             (hWatcherThread) and a second thread (hProcessThread) processes it by calling a
;             callback procedure defined at initialisation.
;             Synchronisation is implemented using events and SRWLock.

Object DirectoryWatcher, DirectoryWatcherID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, PSTRINGW, DWORD, ptr DWCALLBACK, LPARAM
  VirtualMethod     Run
  VirtualMethod     ProcessChanges

  DefineVariable    hDirectory,     HANDLE,       INVALID_HANDLE_VALUE
  DefineVariable    dWatchSubTree,  DWORD,        FALSE
  DefineVariable    dSubscription,  DWORD,        0
  DefineVariable    Overlapped,     OVERLAPPED,   {}
  DefineVariable    hWatcherThread, HANDLE,       0
  DefineVariable    WatchEvents,    HANDLE,       2 DUP(0)
  DefineVariable    hProcessThread, HANDLE,       0
  DefineVariable    ProcessEvents,  HANDLE,       2 DUP(0)
  DefineVariable    Linkage,        LDLL_CONTROL, {NULL, NULL}
  DefineVariable    SRWLock,        SRWLOCK,      {}
  DefineVariable    pCallBack,      POINTER,      NULL
  DefineVariable    lParam,         LPARAM,       0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    DirectoryWatcher implementation
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DirectoryWatcher.Done
; Purpose:    Finalize the DirectoryWatcher object.
; Arguments:  None.
; Return:     Nothing.

Method DirectoryWatcher.Done, uses xsi
  SetObject xsi
  invoke SetEvent, [xsi + sizeof HANDLE].WatchEvents          ;Trigger stop event
  invoke WaitForSingleObject, [xsi].hProcessThread, 3000      ;Wait until all has stopped

  invoke CloseHandle, [xsi].WatchEvents
  invoke CloseHandle, [xsi + sizeof HANDLE].WatchEvents
  invoke CloseHandle, [xsi].ProcessEvents
  invoke CloseHandle, [xsi + sizeof HANDLE].ProcessEvents

  invoke CloseHandle, [xsi].hProcessThread
  invoke CloseHandle, [xsi].hWatcherThread
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DirectoryWatcher.Init
; Purpose:    Initialize the DirectoryWatcher object.
; Arguments:  Arg1: -> Owner.
;             Arg2; -> WIDE directory name to watch.
;             Arg3: Subscription flags.
;             Arg4: Callback Procedure called on each change.
;             Arg5: Context parameter for the callback procedure.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method DirectoryWatcher.Init, uses xsi, pOwner:POINTER, pDirectoryNameW:PSTRINGW, dFlags:DWORD, \
                                        pCallBack:ptr DWCALLBACK, lParam:LPARAM
  local dRetValue:DWORD

  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].pCallBack, pCallBack, xax
  m2m [xsi].lParam, lParam, xax
  mov dRetValue, FALSE

  ;Create a handle for a directory to look for
  invoke CreateFileW, pDirectoryNameW, \
                      GENERIC_READ, FILE_SHARE_DELETE or FILE_SHARE_READ or FILE_SHARE_WRITE, \
                      NULL, OPEN_EXISTING, \
                      FILE_FLAG_BACKUP_SEMANTICS or FILE_FLAG_OVERLAPPED, NULL
  .if xax != INVALID_HANDLE_VALUE
    mov [xsi].hDirectory, xax
    invoke CreateEvent, NULL, TRUE , FALSE , NULL       ;Create a stop event: manual reset, not signaled
    .if xax != 0
      mov [xsi + sizeof(HANDLE)].WatchEvents, xax

      invoke CreateEvent, NULL, FALSE , FALSE , NULL    ;Create an event for Overlapped structure
      .if xax != 0
        mov [xsi].Overlapped.hEvent, xax
        mov [xsi].WatchEvents, xax

        invoke CreateEvent, NULL, FALSE , FALSE , NULL  ;Create an event for ProcessThread
        .if xax != NULL
          mov [xsi].ProcessEvents, xax

          xor eax, eax
          test dFlags, DWF_WATCH_SUBDIRECTORIES
          setz al
          mov [xsi].dWatchSubTree, eax

          mov eax, dFlags
          and eax, (FILE_NOTIFY_CHANGE_SECURITY shr 1) - 1
          mov [xsi].dSubscription, eax

          invoke InitializeSRWLock, addr [xsi].SRWLock

          mov xax, $MethodAddr(DirectoryWatcher.ProcessChanges)
          invoke CreateThread, NULL, 0, xax, xsi, CREATE_SUSPENDED, NULL
          mov [xsi].hProcessThread, xax
          invoke ResumeThread, xax

          mov xax, $MethodAddr(DirectoryWatcher.Run)
          invoke CreateThread, NULL, 0, xax , xsi, CREATE_SUSPENDED, NULL
          mov [xsi].hWatcherThread, xax
          mov [xsi + sizeof(HANDLE)].ProcessEvents, xax   ;Signals the exit of hWatcherThread
          invoke ResumeThread, xax

          mov dRetValue, TRUE
        .endif
      .endif
    .endif
  .endif
  mov eax, dRetValue
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DirectoryWatcher.ProcessChanges
; Purpose:    Process the detected directory changes.
; Arguments:  None.
; Return:     Nothing.

Method DirectoryWatcher.ProcessChanges, uses xbx xdi xsi
  local pMemBlock:POINTER, cFileNameW[1024]:CHRW

  SetObject xsi
  lea xdi, [xsi].Linkage                                ;xdi -> LDLL_CONTROL structure
  .while TRUE
    invoke WaitForMultipleObjects, 2, addr [xsi].ProcessEvents, FALSE, INFINITE
    .if eax == WAIT_OBJECT_0
      .while TRUE
        invoke AcquireSRWLockShared, addr [xsi].SRWLock
        mov xbx, [xdi].LDLL_CONTROL.pFirstMember
        invoke ReleaseSRWLockShared, addr [xsi].SRWLock
        mov pMemBlock, xbx
        .break .if xbx == NULL
        add xbx, sizeof LDLL_MEMBER                     ;xbx -> FILE_NOTIFY_INFORMATION
        .while TRUE
          invoke MemClone, addr cFileNameW, addr [xbx].FILE_NOTIFY_INFORMATION.FileName, \
                           [xbx].FILE_NOTIFY_INFORMATION.FileNameLength  ;eax = # bytes copied
          m2z CHRW ptr cFileNameW[xax]

         ;Perform the callback passing the LPARAM as the first parameter (pSelf)
          .if xax != NULL
            invoke DWCALLBACK ptr [xsi].pCallBack, [xsi].lParam, \
                                                   [xbx].FILE_NOTIFY_INFORMATION.Action, \
                                                   addr cFileNameW
          .endif

          ;Move to next FILE_NOTIFY_INFORMATION
          mov ecx, [xbx].FILE_NOTIFY_INFORMATION.NextEntryOffset
          .break .if ecx == 0
          add xbx, xcx
        .endw

        invoke AcquireSRWLockExclusive, addr [xsi].SRWLock
        LDLL_RemoveFirst xdi, xax
        invoke ReleaseSRWLockExclusive, addr [xsi].SRWLock
        MemFree pMemBlock
      .endw

    .elseif eax == WAIT_OBJECT_0 + 1                    ;This is the hWatcherThread exit signal
      ;DbgText "Exit from DirectoryWatcher.ProcessChanges"
      .break

    .else
      ;DbgWarning "ERROR: unhandled Wait"
      OCall xsi.ErrorReport, NULL, DWE_UNHANDLED_WAIT
      .break

    .endif
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DirectoryWatcher.Run
; Purpose:    Start monitoring the directory for changes.
; Arguments:  None.
; Return:     Nothing.

Method DirectoryWatcher.Run, uses xsi
  local dBytesReturned:DWORD, pBuffer:POINTER, pStorage:POINTER

  SetObject xsi
  .while TRUE
    MemAlloc DIR_WATCHER_BUFFER_SIZE
    .if xax != NULL
      mov pBuffer, xax
      add xax, sizeof LDLL_MEMBER
      mov pStorage, xax
      invoke ReadDirectoryChangesW, [xsi].hDirectory, pStorage, DIR_WATCHER_BUFFER_SIZE, \
                                    [xsi].dWatchSubTree, [xsi].dSubscription, \
                                    addr dBytesReturned, addr [xsi].Overlapped, NULL
      .if eax != 0
        .while TRUE
          ;Wait for overlapped-function or the exit event
          invoke WaitForMultipleObjects, 2, addr [xsi].WatchEvents, FALSE, 3000
          .if eax == WAIT_OBJECT_0
            ;Add the new buffer to the linked list and resume the Process Thread
            invoke AcquireSRWLockExclusive, addr [xsi].SRWLock
            lea xcx, [xsi].Linkage
            mov xax, pBuffer
            LDLL_Append xcx, xax, xdx
            invoke ReleaseSRWLockExclusive, addr [xsi].SRWLock
            invoke SetEvent, [xsi].ProcessEvents          ;Start processing the changes
            .break                                        ;Restart again

          .elseif eax == WAIT_OBJECT_0 + 1                ;This is the stop event signal
            ;DbgText "Exit from DirectoryWatcher.Run"
            MemFree pBuffer
            ret

          .elseif eax == WAIT_TIMEOUT
            ;DbgText "No changes in the timeout period"

          .else
            ;DbgWarning "ERROR: unhandled Wait"
            OCall xsi.ErrorReport, NULL, DWE_UNHANDLED_WAIT
            MemFree pBuffer
            ret

          .endif
        .endw
      .else
        ;DbgApiError "ReadDirectoryChangesW FAILED"
        OCall xsi.ErrorReport, NULL, DWE_READDIRECTORYCHANGESW
        MemFree pBuffer
        ret

      .endif
    .else
      ;DbgWarning "ERROR: out of memory"
      OCall xsi.ErrorReport, NULL, DWE_OUT_OF_MEMORY
      ret

    .endif
  .endw
MethodEnd

endif
