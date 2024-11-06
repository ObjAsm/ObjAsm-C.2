; ==================================================================================================
; Title:      DbgCloseDevice_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef hDbgDev:HANDLE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgCloseDevice
; Purpose:    Close the connection to the output device.
; Arguments:  None.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

.code
align ALIGN_CODE
DbgCloseDevice proc
  .if hDbgDev != 0
    invoke CloseHandle, hDbgDev
  .endif
  ret
DbgCloseDevice endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

