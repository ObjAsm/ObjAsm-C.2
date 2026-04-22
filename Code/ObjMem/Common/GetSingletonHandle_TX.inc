; ==================================================================================================
; Title:      GetSingletonHandle_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, April 2026.
;               - Initial release.
;               - Character and Bitness independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  GetSingletonHandle
; Purpose:    Attempts to acquire exclusive ownership for single-instance execution.
; Arguments:  Arg1: -> Pointer to a null-terminated identifying string.
; Return:     xax = Handle representing exclusive ownership if this is the first instance
;                   0 if another instance is already running
;                   INVALID_HANDLE_VALUE if the operation failed
; Notes:      - The returned handle represents the ownership lock and must remain open
;               for the entire lifetime of the application.
;             - The caller is responsible for releasing it using CloseHandle before exit.

.code
align ALIGN_CODE
ProcName proc uses xbx pUniqueString:POINTER
  ; Verify that this is the only running instance
  invoke CreateMutex, NULL, TRUE, pUniqueString
  .if xax == 0
    ;Couldn't create mutex (failure)
    mov xax, INVALID_HANDLE_VALUE
    ret
  .endif

  mov xbx, xax
  invoke GetLastError

  .if eax == ERROR_ALREADY_EXISTS
    ; Another instance is running
    invoke CloseHandle, xbx
    xor eax, eax
  .else
    ; This is the singleton instance
    mov xax, xbx
  .endif
  ret
ProcName endp

