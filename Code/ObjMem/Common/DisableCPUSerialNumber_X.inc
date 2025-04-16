; ==================================================================================================
; Title:      DisableCPUSerialNumber_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  DisableCPUSerialNumber
; Purpose:    Disable the reading of the CPU serial number.
; Arguments:  None.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
DisableCPUSerialNumber proc
  mov ecx, 119h
  rdmsr
  and eax, 0FFDFFFFFh
  wrmsr
  ret
DisableCPUSerialNumber endp

OPTION PROC:DEFAULT
