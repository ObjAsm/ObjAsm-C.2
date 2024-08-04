; ==================================================================================================
; Title:      GetSysHnsecs_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetSysHnsecs
; Purpose:    Get the hecto-nano-seconds count from system start.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     rax / edx::eax = hecto-nano-second count.

align ALIGN_CODE
GetSysHnsecs proc pDest:PDTL_HNSECS
  GetInterruptTicks
  .if pDest
    mov xcx, pDest
    if TARGET_BITNESS eq 32
      mov [ecx], eax
      mov [ecx + 4], edx
    else
      mov [rcx], rax
    endif
  .endif
  ret
GetSysHnsecs endp
