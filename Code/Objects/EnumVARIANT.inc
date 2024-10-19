; =================================================================================================
; Title:      EnumVARIANT.inc
; Author:     Kai Liebenau.
; Purpose:    EnumVARIANT object.
; Version:    Version C.1.1, April 2007
;               - First release.
; =================================================================================================


externdef IID_IEnumVARIANT:GUID      ;{00020404-0000-0000-C000-000000000046}

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     IEnumVARIANT
; Purpose:    Implements a COM IEnumVARIANT interface object.

Object IEnumVARIANT, IEnumVARIANTID, IUnknown
  InterfaceMethod    Next,          DWORD, POINTER, POINTER
  InterfaceMethod    Skip,          DWORD
  InterfaceMethod    Reset
  InterfaceMethod    Clone,         POINTER

  RedefineVariable  pIID,           offset IID_IEnumVARIANT
  ;_NewEnum -> ID(FFFFFFFCh)
  ;dMethodID = FFFFFFFCh, Invoke Method [IDispatch.inc, 152]
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     EnumVARIANT
; Purpose:    Implements a COM EnumVARIANT object.

Object EnumVARIANT, EnumVARIANTID, Component
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, DWORD

  DefineVariable    dCurrentIndex,  DWORD,    0
  DefineVariable    dMaxIndex,      DWORD,    0
  DefineVariable    pEnumOwner,     POINTER,  NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumVARIANT.Done
; Purpose:    Finalizes the EnumVARIANT object.
; Arguments:  None.
; Return:     Nothing.

Method EnumVARIANT.Done
  SetObject xcx
  DbgHex xcx, "EnumVARIANT::Done"
  ACall xcx.Done
  DbgLine
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumVARIANT.Init
; Purpose:    Initializes the EnumVARIANT object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Maximal Index value.
; Return:     Nothing.

Method EnumVARIANT.Init, uses xsi, pOwner:POINTER, dMaxIndex:DWORD
  SetObject xsi
  DbgHex xsi, "EnumVARIANT::Init"
  ACall xsi.Init, pOwner, NULL                        ;No aggregation

  m2m [xsi].dMaxIndex, dMaxIndex, eax
  m2m [xsi].pEnumOwner, pOwner, eax

  DbgLine
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumVARIANT.Next
; Purpose:    Enumerates the next requested VARIANTs, returning them along with the
;             actual number of enumerated elements in pFetched. 
; Arguments:  Arg1: Number of VARIANTs being requested.
;             Arg2: -> Buffer to hold the VARIANTs.
;             Arg3: -> Number of VARIANTSs actually supplied. Caller can pass in NULL if Arg1 is one.
; Return:     eax = HRESULT.

Method IEnumVARIANT.Next,,dCount:DWORD, pBuffer:POINTER, pFetched:POINTER
  DbgText "IEnumVARIANT::Next"
  mov eax, E_NOTIMPL
  DbgLine
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumVARIANT.Skip
; Purpose:    Increments the internal counter.
; Arguments:  Arg1: Increment value.
; Return:     eax = HRESULT.

Method IEnumVARIANT.Skip,, dIncrement:DWORD
  SetOwner xcx , EnumVARIANT
  DbgHex xcx, "IEnumVARIANT::Skip"
  
  mov eax, [xcx].dCurrentIndex
  add eax, dIncrement                                   ;Increment
  
  .if eax > [xcx].dMaxIndex 
    m2m [xcx].dCurrentIndex, [xcx].dMaxIndex, edx
    mov eax, S_FALSE
  .else
    mov [xcx].dCurrentIndex, eax
    xor eax, eax                                        ;Return S_OK
  .endif
  DbgLine
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumVARIANT.Reset
; Purpose:    Resets the internal counter.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IEnumVARIANT.Reset
  SetOwner xcx, EnumVARIANT
  DbgHex xcx, "IEnumVARIANT::Reset"
  xor eax, eax                                          ;Return S_OK
  mov [xcx].dCurrentIndex, eax                          ;Reset
  DbgLine
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumVARIANT.Clone
; Purpose:    Makes an exact duplicate of EnumVARIANT with all it's internal values.
; Arguments:  Arg1: -> IEnumVARIANT interface of the new object.
; Return:     eax = HRESULT.

Method IEnumVARIANT.Clone,, pEnumVARIANT:POINTER
  SetObject xcx
  DbgHex xcx, "IEnumVARIANT::Clone"
  mov eax, E_NOTIMPL
  DbgLine
MethodEnd

endif