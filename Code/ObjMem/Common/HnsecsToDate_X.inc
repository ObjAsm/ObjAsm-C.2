; ==================================================================================================
; Title:      HnsecsToDate_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  HnsecsToDate
; Purpose:    Convert hecto-nano-seconds into DTL_DATE information.
; Arguments:  Arg1: -> DTL_DATE
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE if succeeded, otherwise FALSE.

.code
align ALIGN_CODE
HnsecsToDate proc pDate:PDTL_DATE, pHnsecs:PDTL_HNSECS
  local SysTime:SYSTEMTIME

  invoke FileTimeToSystemTime, pHnsecs, addr SysTime
  mov xcx, pDate
  .if eax
    mov [xcx].DTL_DATE.wCalID, CAL_GREGORIAN
    m2m DWORD ptr [xcx].DTL_DATE.wYear, DWORD ptr SysTime.wYear, eax
    m2m [xcx].DTL_DATE.wDay, SysTime.wDay, cx
    mov eax, TRUE
  .else
    m2z DWORD ptr [xcx].DTL_DATE.wCalID
    m2z DWORD ptr [xcx].DTL_DATE.wMonth                 ;eax already zero here
  .endif
  ret
HnsecsToDate endp
