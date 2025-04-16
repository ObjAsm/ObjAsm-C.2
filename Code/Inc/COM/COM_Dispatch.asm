; ==================================================================================================
; Title:      COM_Dispatch.asm
; Author:     G.Friedrich
; Version:    C.1.0
; Purpose:    COM dispatching helper procedures compatible with ObjAsm definitions.
; Notes:      Version C.1.0, October 2017
;               - First release. Source code hints taken from Japheth's DispHelp.inc.
; ==================================================================================================


LOCALE_SYSTEM_DEFAULT equ 800h

.code

; --------------------------------------------------------------------------------------------------
; Procedure:  ExecDispatch
; Purpose:    Perform a method call using the IDispatch interface. Variant arguments are
;             automatically created onto stack.
; Arguments:  Arg 1: -> Dispatch interface.
;             Arg 2: Method Dispatch ID.
;             Arg 3: Dispatch type (DISPATCH_METHOD, DISPATCH_PROPERTYGET, DISPATCH_PROPERTYPUT,
;                    DISPATCH_PROPERTYPUTREF).
;             Arg 4: Argument count.
;             Arg 5: Return Argument size in bytes.
;             Arg 6 - n: Argument types.
;             Arg n+1 - m: Argument values.
;             Arg m+1: -> Return Value.

if TARGET_BITNESS eq 64
  option stackbase:rbp
  ExecDispatch proc uses xdi xsi, pIDispatch:POINTER, dDispID:DWORD, wDispType:WORD, \
                                  dArgCount:DWORD, dRetType:DWORD, Args:VARARG
else
  ExecDispatch proc c uses xdi xsi, pIDispatch:POINTER, dDispID:DWORD, wDispType:WORD, \
                                    dArgCount:DWORD, dRetType:DWORD, Args:VARARG
endif
  local xSP:XWORD, dArgIndexError:DWORD
  local dPropPutID:DWORD, DispParams:DISPPARAMS

  mov xSP, xsp

  ;Setup the VARIANT argument array. The varints have to be arranged in REVERSE order!
  mov ecx, dArgCount
  mov DispParams.cArgs, ecx
  lea xsi, Args                                         ;xsi -> argument types
  lea xdx, [xsi + xcx*sizeof(DWORD)]                    ;All passed VT_xxx are DWORDs
  .while xcx != 0
    sub xsp, sizeof(VARIANT)
    lea xdi, [xsp + @WordSize]                          ;xdi -> Variant payload
    lodsd
    mov [xsp].VARIANT.vt, ax
    xchg xdx, xsi
    .if (eax & VT_BYREF)
      movsd
    .elseif (eax == VT_VARIANT)
      sub xdi, 8
      if TARGET_BITNESS eq 32
        movsd
        movsd
        movsd
        movsd
      else
        movsq
        movsq
      endif
    .elseif (eax == VT_R8 || eax == VT_DATE || eax == VT_CY)
      if TARGET_BITNESS eq 32
        movsd
        movsd
      else
        movsq
      endif
    .else
      movsd
    .endif
    xchg xsi, xdx
    dec ecx
  .endw
  mov xdi, xdx                                          ;xdi -> Return value
  mov DispParams.rgvarg, xsp

  ;Setup the VARIANT return value
  .if dRetType != -1
    sub xsp, sizeof(VARIANT)
    mov xsi, xsp                                        ;xsi -> return Variant
    mov [xsp].VARIANT.vt, VT_EMPTY
  .else
    xor esi, esi
  .endif

  ;Setup the DISPPARAMS structure
  .if ((wDispType == DISPATCH_PROPERTYPUT) || (wDispType == DISPATCH_PROPERTYPUTREF))
    mov dPropPutID, DISPID_PROPERTYPUT
    lea xax, dPropPutID
    mov DispParams.rgdispidNamedArgs, xax
    mov DispParams.cNamedArgs, 1
  .else
    m2z DispParams.cNamedArgs
  .endif

  ;Call the Dispatch.Invoke method

  ICall pIDispatch::IDispatch.Invoke, dDispID, addr IID_NULL, LOCALE_SYSTEM_DEFAULT, \
                                      wDispType, addr DispParams, xsi, NULL, addr dArgIndexError

  ;Copy the value of the returned Variant to the return Value
  .if (eax == S_OK && xsi)
    mov xdi, [xdi]                                      ;Get return argument pointer
    .if (dRetType == VT_VARIANT)
      if TARGET_BITNESS eq 32
        movsd
        movsd
        movsd
        movsd
      else
        movsq
        movsq
      endif
    .else
      add xsi, 8
      .if (dRetType == VT_R8 || dRetType == VT_DATE || dRetType == VT_CY)
        if TARGET_BITNESS eq 32
          movsd
          movsd
        else
          movsq
        endif
      .else
        movsd
      .endif
    .endif
  .endif

  mov xsp, xSP                                          ;Restore stack
  mov ecx, dArgIndexError                               ;eax = ICall result value, ecx = index error
  ret
ExecDispatch endp

if TARGET_BITNESS eq 64
  option stackbase:??StackBase
endif

; --------------------------------------------------------------------------------------------------
; Procedure:  CallDispatch
; Purpose:    Perform a method call using the IDispatch interface. Variant arguments are passed as
;             procedure arguments. The caller has to assembe the variants.
; Arguments:  Arg 1: -> Dispatch interface.
;             Ar2 2: Method Dispatch ID.
;             Arg 3: Dispatch type (DISPATCH_METHOD, DISPATCH_PROPERTYGET, DISPATCH_PROPERTYPUT,
;                    DISPATCH_PROPERTYPUTREF).
;             Arg 4: Number of arguments.
;             Arg 5: -> Variant arguments.
;             Arg 6: -> Return variant.

CallDispatch proc pIDispatch:POINTER, dDispID:DWORD, wDispType:WORD, dArgNum:DWORD, \
                  pVarArgs:POINTER, pVarRet:POINTER
  local dPropPutID:DWORD, DispParams:DISPPARAMS, dArgIndexError:DWORD

  ;Setup the DISPPARAMS structure
  m2m DispParams.cArgs, dArgNum, eax
  m2m DispParams.rgvarg, pVarArgs, xcx

  .if ((wDispType == DISPATCH_PROPERTYPUT) || (wDispType == DISPATCH_PROPERTYPUTREF))
    mov dPropPutID, DISPID_PROPERTYPUT
    lea xax, dPropPutID
    mov DispParams.rgdispidNamedArgs, xax
    mov DispParams.cNamedArgs, 1
  .else
    m2z DispParams.cNamedArgs
    m2z DispParams.rgdispidNamedArgs
  .endif

  ;Call the Dispatch.Invoke method    LOCALE_SYSTEM_DEFAULT = 800h
  ICall pIDispatch::IDispatch.Invoke, dDispID, addr IID_NULL, LOCALE_SYSTEM_DEFAULT, wDispType,\
                                      addr DispParams, pVarRet, NULL, addr dArgIndexError
  mov ecx, dArgIndexError                               ;eax = ICall result value, ecx = index error
  ret
CallDispatch endp
