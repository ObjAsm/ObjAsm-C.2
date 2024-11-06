; ==================================================================================================
; Title:      IsWinNT_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsWinNT
; Purpose:    Detect if the OS is Windows NT based.
; Arguments:  None.
; Return:     eax = TRUE if OS is Windows NT based, otherwise FALSE.

.code
align ALIGN_CODE
IsWinNT proc
  local OSVI:OSVERSIONINFO
  
  mov OSVI.dwOSVersionInfoSize, sizeof(OSVERSIONINFO)
  invoke GetVersionEx, addr OSVI                        ;TRUE/FALSE
  xor eax, eax
  cmp OSVI.dwPlatformId, VER_PLATFORM_WIN32_NT
  sete al
  ret
IsWinNT endp

