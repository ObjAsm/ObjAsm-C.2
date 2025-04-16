; ==================================================================================================
; Title:      ComEventsUnadvice_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  ComEventsUnadvice
; Purpose:    Notificate the Event source that pISource will NOT recieve Events any more.
; Arguments:  Arg1: -> Previous ConnectionPoint interface.
;             Arg2: DWORD Cookie received from previous ComEventsAdvice call.
; Return:     eax = HRESULT.

.code
align ALIGN_CODE
ComEventsUnadvice proc pICP:POINTER, dPrvCookie:DWORD
  ICall pICP::IConnectionPoint.Unadvise, dPrvCookie
  .if SUCCEEDED(eax)
    ICall pICP::IConnectionPoint.Release
  .endif
  ret
ComEventsUnadvice endp
