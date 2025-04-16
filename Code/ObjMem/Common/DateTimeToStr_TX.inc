; ==================================================================================================
; Title:      DateTimeToStr_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  DateTimeToStrA / DateTimeToStrW
; Purpose:    Convert a PDTL_DATE and DTL_TIME to a formated string representation.
; Arguments:  Arg1: -> Destination Buffer
;             Arg2: Date Format flags
;             Arg3: -> DTL_DATE
;             Arg4: Time Format flags
;             Arg5: -> DTL_TIME
; Return:     eax = Number of bytes copied, including the ZTC.

.code
align ALIGN_CODE
ProcName proc uses xbx pDest:PSTRING, dDateFormat:DWORD, pDate:PDTL_DATE, \
                                      dTimeFormat:DWORD, pTime:PDTL_TIME
  invoke DateToStr, pDest, dDateFormat, pDate
  mov ebx, eax                                          ;Including the ZTC
  add xax, pDest
  mov CHR ptr [xax - sizeof(CHR)], " "
  invoke TimeToStr, xax, dTimeFormat, pTime
  add eax, ebx
  ret
ProcName endp
