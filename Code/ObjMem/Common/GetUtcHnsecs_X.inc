; ==================================================================================================
; Title:      GetUtcHnsecs_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  GetUtcHnsecs
; Purpose:    Get the UTC hecto-nano-seconds count.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     Nothing, always succeed.

.code
align ALIGN_CODE
GetUtcHnsecs proc pDest:PDTL_HNSECS
  invoke GetSystemTimeAsFileTime, pDest                 ;Fast
GetUtcHnsecs endp
