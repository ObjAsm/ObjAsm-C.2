; ==================================================================================================
; Title:      IsProcessElevated_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, April 2022.
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsProcessElevated
; Purpose:    Check if the current process has elevated privileges.
; Arguments:  Arg: Process HANDLE.
; Return:     eax = TRUE or FALSE.
; Example:    invoke GetCurrentProcess
;             invoke IsProcessElevated, xax

.code
align ALIGN_CODE
IsProcessElevated proc uses xbx, hProcess:HANDLE
  local hToken:HANDLE
  local Elevation:TOKEN_ELEVATION
  local cbSize:DWORD

  xor ebx, ebx                                          ;ebx: Result = FALSE
  mov hToken, xbx                                       ;hToken = 0, just in case
  invoke OpenProcessToken, hProcess, TOKEN_QUERY, addr hToken
  .if eax != 0
    mov cbSize, sizeof(Elevation)
    invoke GetTokenInformation, hToken, TokenElevation, addr Elevation, sizeof Elevation, addr cbSize
    .if eax != 0
      mov ebx, Elevation.TokenIsElevated
    .endif
    invoke CloseHandle, hToken
  .endif

  mov eax, ebx
  ret
IsProcessElevated endp
