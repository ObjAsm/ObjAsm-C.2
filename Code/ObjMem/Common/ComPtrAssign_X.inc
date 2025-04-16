; ==================================================================================================
; Title:      ComPtrAssign_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  ComPtrAssign
; Purpose:    First increments the reference count of the new interface and then releases any
;             existing interface pointer.
; Arguments:  Arg1: -> Old Interface pointer.
;             Arg2: New Interface pointer.

.code
align ALIGN_CODE
ComPtrAssign proc ppOldInterface:POINTER, pNewInterface:POINTER
  .if pNewInterface != NULL                             ;1st increment the reference count to avoid
    ICall pNewInterface::IUnknown.AddRef                ;  disposing of the COM object
  .endif
  mov xcx, ppOldInterface
  mov xax, [xcx]
  m2m [xcx], pNewInterface, xdx                         ;Store new interface pointer
  .if xax != NULL
    ICall xax::IUnknown.Release                         ;Release old interface
  .endif
  ret
ComPtrAssign endp
