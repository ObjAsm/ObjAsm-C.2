; ==================================================================================================
; Title:      HnsecsToDateTime_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  HnsecsToDateTime
; Purpose:    Convert hecto-nano-seconds into DTL_DATETIME information.
; Arguments:  Arg1: -> DTL_DATETIME
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE id succeeded, otherwise FALSE.

.code
align ALIGN_CODE
HnsecsToDateTime proc pDateTime:PDTL_DATETIME, pHnsecs:PDTL_HNSECS
  invoke FileTimeToSystemTime, pHnsecs, pDateTime
  mov xcx, pDateTime
  .if eax
    ;Move the first structure members
    mov eax, DWORD ptr [xcx].DTL_DATETIME.wCalID
    mov DWORD ptr [xcx].DTL_DATETIME.wYear, eax
    mov [xcx].DTL_DATETIME.wCalID, CAL_GREGORIAN
    mov eax, TRUE
  .else
    m2z DWORD ptr [xcx].DTL_DATETIME.wCalID
    m2z DWORD ptr [xcx].DTL_DATETIME.wMonth
    m2z DWORD ptr [xcx].DTL_DATETIME.wHour
    m2z DWORD ptr [xcx].DTL_DATETIME.wSecond            ;eax already zero here
  .endif
  ret
HnsecsToDateTime endp
