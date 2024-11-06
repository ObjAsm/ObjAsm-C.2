; ==================================================================================================
; Title:      ComEventsAdvice_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ComEventsAdvice
; Purpose:    Notificate the Event source that pISink will recieve Events.
; Arguments:  Arg1: -> Any Source Object Interface.
;             Arg2: -> Sink IUnknown Interface.
;             Arg3: -> IID of the outgoing interface whose connection point object is being
;                   requested (defined by the Source to communicate and implemented by the Sink).
;             Arg4: -> ConnectionPoint interface pointer.
;             Arg5: -> DWORD Cookie.
; Return:     eax = HRESULT.

.code
align ALIGN_CODE
ComEventsAdvice proc pISrcAny:POINTER, pISinkUnk:POINTER, pIID:POINTER, ppICP:POINTER, pCookie:POINTER
  local pICPC:POINTER

  ICall pISrcAny::IUnknown.QueryInterface, offset IID_IConnectionPointContainer, addr pICPC
  .if SUCCEEDED(eax)
    ICall pICPC::IConnectionPointContainer.FindConnectionPoint, pIID, ppICP
    .if SUCCEEDED(eax)
      mov xax, ppICP
      mov xcx, [xax]                                    ;xcx -> IPC
      ICall xcx::IConnectionPoint.Advise, pISinkUnk, pCookie
    .endif
    ICall pICPC::IConnectionPointContainer.Release
  .endif
  ret
ComEventsAdvice endp
