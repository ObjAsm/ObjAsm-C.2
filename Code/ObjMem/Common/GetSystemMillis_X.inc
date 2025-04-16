; ==================================================================================================
; Title:      GetSystemMillis_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  GetSystemMillis
; Purpose:    Get system millisecond count.
; Arguments:  Arg1: -> Destination variable
; Return:     rax / edx::eax = millisecond count.

.code
align ALIGN_CODE
GetSystemMillis proc pDest:PDTL_MILLIS
  invoke GetTickCount64                                 ;In 32 bit, the 64 bit counter value
  mov xcx, pDest                                        ; is returned in edx::eax
  if TARGET_BITNESS eq 32
    mov [xcx].DTL_MILLIS.dLow, eax
    mov [xcx].DTL_MILLIS.dHigh, edx
  else
    mov DTL_MILLIS ptr [rcx], rax
  endif
  ret
GetSystemMillis endp
