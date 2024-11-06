; ==================================================================================================
; Title:      GetPrevInstance_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetPrevInstance
; Purpose:    Return a HANDLE to a previously running instance of an application.
; Arguments:  Arg1: -> Application name.
;             Arg2: -> Class name.
; Return:     rax = Window HANDLE of the application instance or zero if failed.

.code
align ALIGN_CODE
ProcName proc uses xdi pStrID:POINTER, pClassName:POINTER
  invoke CreateSemaphore, 0, 0, 1, pStrID
  mov xdi, xax                                          ;xdi = Semaphore HANDLE
  invoke GetLastError
  cmp eax, ERROR_ALREADY_EXISTS
  je @@1
  cmp eax, ERROR_SUCCESS
  jne @@2                                               ;Find another instance
  xor eax, eax
  jmp @@Exit
@@1:
  invoke CloseHandle, xdi                               ;Close the Semaphore HANDLE
@@2:
  invoke FindWindow, pClassName, NULL                  ;Try to find another instance
  test xax, xax                                         ;already running
  jz @@Exit                                             ;return 0 to exit
  invoke GetLastActivePopup, xax                        ;xax = hWnd
@@Exit:
  ret
ProcName endp
