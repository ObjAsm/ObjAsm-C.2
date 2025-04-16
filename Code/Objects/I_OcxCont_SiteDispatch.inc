; ==================================================================================================
; Title:      I_OcxCont_SiteDispatch.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Dispatch Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_SiteDispatch
; Purpose:    If a control supports any ambient properties at all, it must at least respect the
;             values of the following ambient properties under the conditions stated in the
;             following table using the standard dispids.
;
;  Ambient Property  Dispid  Comment/Conditions for Use
;  LocaleID          -705    If Locale is significant to the control, e.g. for text output
;  UserMode          -709    If the control behaves differently in user (design) mode and run mode
;  UIDead            -710    If the ctrl reacts to UI events, it should honor this ambient property
;  ShowGrabHandles   -711    If the control support in-place resizing of itself
;  ShowHatching      -712    If the control support in-place activation and UI activation
;  DisplayAsDefault  -713    Only if the control is marked OLEMISC_ACTSLIKEBUTTON (which means that
;                            support for keyboard mnemonics is provided, thus IOleControl::
;                            GetControlInfo and IOleControl::OnMnemonic must be implemented).
; http://apuntes.danielcastelao.org/apuntes/software/programacion/VisualC/VC98/ATL/INCLUDE/
; ATLIFACE.IDL
;
; This is a PURE dispatch interface!!!!
; Since I have no dispatch information how to automatically coherce the arguments and ret value
; automatically, I do it in the methods itself.

Object I_OcxCont_SiteDispatch,, IDispatch
  IDispEvent  GetAmbientBackColor,        DISPID_AMBIENT_BACKCOLOR,           DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientBackColor,        DISPID_AMBIENT_BACKCOLOR,           DISPATCH_PROPERTYPUT
;  IDispEvent  AmbientDispayName           DISPID_AMBIENT_DISPLAYNAME,
  IDispEvent  GetAmbientFont,             DISPID_AMBIENT_FONT,                DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientFont,             DISPID_AMBIENT_FONT,                DISPATCH_PROPERTYPUT

  IDispEvent  GetAmbientForeColor,        DISPID_AMBIENT_FORECOLOR,           DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientForeColor,        DISPID_AMBIENT_FORECOLOR,           DISPATCH_PROPERTYPUT
  IDispEvent  GetAmbientLocaleID,         DISPID_AMBIENT_LOCALEID,            DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientLocaleID,         DISPID_AMBIENT_LOCALEID,            DISPATCH_PROPERTYPUT
  IDispEvent  GetAmbientMessageReflect,   DISPID_AMBIENT_MESSAGEREFLECT,      DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientMessageReflect,   DISPID_AMBIENT_MESSAGEREFLECT,      DISPATCH_PROPERTYPUT
;  IDispEvent  AmbientScaleUnits,          DISPID_AMBIENT_SCALEUNITS,
;  IDispEvent  AmbientTextAlign,           DISPID_AMBIENT_TEXTALIGN,
  IDispEvent  GetAmbientUserMode,         DISPID_AMBIENT_USERMODE,            DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientUserMode,         DISPID_AMBIENT_USERMODE,            DISPATCH_PROPERTYPUT
  IDispEvent  GetAmbientUIDead,           DISPID_AMBIENT_UIDEAD,              DISPATCH_PROPERTYGET
  IDispEvent  GetAmbientShowGrabhandles,  DISPID_AMBIENT_SHOWGRABHANDLES,     DISPATCH_PROPERTYGET
  IDispEvent  GetAmbientShowHatching,     DISPID_AMBIENT_SHOWHATCHING,        DISPATCH_PROPERTYGET
  IDispEvent  GetAmbientDisplayAsDefault, DISPID_AMBIENT_DISPLAYASDEFAULT,    DISPATCH_PROPERTYGET
  IDispEvent  PutAmbientDisplayAsDefault, DISPID_AMBIENT_DISPLAYASDEFAULT,    DISPATCH_PROPERTYPUT
;  IDispEvent  AmbientSupportMnemonics,    DISPID_AMBIENT_SUPPORTSMNEMONICS,
;  IDispEvent  AmbientAutoclip,            DISPID_AMBIENT_AUTOCLIP,
;  IDispEvent  AmbientAppearance,          DISPID_AMBIENT_APPEARANCE,
;  IDispEvent  AmbientCodepage,            DISPID_AMBIENT_CODEPAGE,
;  IDispEvent  Ambientpalette,             DISPID_AMBIENT_PALETTE,
;  IDispEvent  AmbientCharset,             DISPID_AMBIENT_CHARSET,
;  IDispEvent  AmbientTransferPriority,    DISPID_AMBIENT_TRANSFERPRIORITY,
  IDispEvent  GetAmbientRightToLeft,      DISPID_AMBIENT_RIGHTTOLEFT,         DISPATCH_PROPERTYGET
  IDispEvent  GetAmbientTopToBottom,      DISPID_AMBIENT_TOPTOBOTTOM,         DISPATCH_PROPERTYGET

  InterfaceMethod   GetAmbientBackColor,        ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientBackColor,        ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientFont,             ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientFont,             ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientForeColor,        ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientForeColor,        ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientLocaleID,         ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientLocaleID,         ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientMessageReflect,   ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientMessageReflect,   ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientUserMode,         ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientUserMode,         ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientUIDead,           ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientShowGrabhandles,  ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientShowHatching,     ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientDisplayAsDefault, ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   PutAmbientDisplayAsDefault, ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientRightToLeft,      ptr DISPPARAMS, LPVARIANT
  InterfaceMethod   GetAmbientTopToBottom,      ptr DISPPARAMS, LPVARIANT
ObjectEnd



if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_SiteDispatch implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Macro:      GetOcxContainer
; Purpose:    Helper macro.
; Arguments:  none.
; Return:     xcx -> OcxClientSite.

GetOcxContainer macro
  mov xcx, pSelf
  mov xdx, [xcx].$Obj(I_OcxCont_SiteDispatch).pOwner  ;xdx -> OcxClientSite
  mov xcx, [xdx].$Obj(OcxClientSite).pOwner           ;xcx -> OcxContainer
endm

; --------------------------------------------------------------------------------------------------
; Macro:      GetOcxInputParam
; Purpose:    Helper macro.
; Arguments:  none.
; Return:     xdx -> VARIANT input paramter.

GetOcxInputParam macro
  mov xax, pParams
  mov xdx, [xax].DISPPARAMS.rgvarg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      GetOcxRetValue
; Purpose:    Helper macro.
; Arguments:  VARIANT value type.
; Return:     xdx -> Return VARIANT.

GetOcxRetValue macro ValueType:req
  mov xdx, pRetVal
  mov [xdx].VARIANT.vt, ValueType
endm

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientBackColor
; Purpose:    Return the ambient background color to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientBackColor,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientBackColor", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_I4                                ;xdx -> VARIANT
    m2m [xdx].VARIANT.lVal, [xcx].$Obj(OcxContainer).dOleBackColor, xax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientBackColor
; Purpose:    Set the ambient background color on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientBackColor,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientBackColor", "I_OcxCont_SiteDispatch"
  .if pParams != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    m2m [xcx].$Obj(OcxContainer).dOleBackColor, [xdx].VARIANT.lVal, xax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientFont
; Purpose:    Return the ambient font to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientFont,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientFont", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    .if [xcx].$Obj(OcxContainer).pIFontDisp != NULL
      GetOcxRetValue VT_FONT                            ;xdx -> VARIANT
      mrm [xdx].VARIANT.pdispVal, [xcx].$Obj(OcxContainer).pIFontDisp, xax
      ICall xax::IUnknown.AddRef
      xor eax, eax                                      ;S_OK
    .else
      mov eax, E_NOINTERFACE
    .endif
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientFont
; Purpose:    Set the ambient font on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientFont,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientFont", "I_OcxCont_SiteDispatch"
  .if pParams != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    m2m [xcx].$Obj(OcxContainer).pIFontDisp, [xdx].VARIANT.lVal, xax
    SAFE_RELEASE xdx
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientForeColor
; Purpose:    Return the ambient foreground color to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientForeColor,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientForeColor", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_I4                                ;xdx -> VARIANT
    m2m [xdx].VARIANT.lVal, [xcx].$Obj(OcxContainer).dOleForeColor, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientForeColor
; Purpose:    Set the ambient foreground color on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientForeColor,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientForeColor", "I_OcxCont_SiteDispatch"
  .if pParams != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    m2m [xcx].$Obj(OcxContainer).dOleForeColor, [xdx].VARIANT.lVal, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientLocaleID
; Purpose:    Return the ambient Local ID to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientLocaleID,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientLocaleID", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_I4                                ;xdx -> VARIANT
    m2m [xdx].VARIANT.lVal, [xcx].$Obj(OcxContainer).dUserLocaleID, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientLocaleID
; Purpose:    Set the ambient Local ID on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientLocaleID,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientLocaleID", "I_OcxCont_SiteDispatch"
  .if pParams != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    m2m [xcx].$Obj(OcxContainer).dUserLocaleID, [xdx].VARIANT.lVal, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientMessageReflect
; Purpose:    Return the ambient MessageReflect flag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientMessageReflect,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientMessageReflect", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_BOOL                              ;xdx -> VARIANT
    xor eax, eax
    .if [xcx].$Obj(OcxContainer).dMessageReflect != 0
      dec eax
    .endif
    mov [xdx].VARIANT.boolVal, ax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientMessageReflect
; Purpose:    Set the ambient MessageReflect flag on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientMessageReflect,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientMessageReflect", "I_OcxCont_SiteDispatch"
  .if pParams != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    .if [xdx].VARIANT.lVal == 0
      mov [xcx].$Obj(OcxContainer).dMessageReflect, FALSE
    .else
      mov [xcx].$Obj(OcxContainer).dMessageReflect, TRUE
    .endif
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientUserMode
; Purpose:    Return the ambient user mode to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientUserMode,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientUserMode", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_BOOL                              ;xdx -> VARIANT
    xor eax, eax
    .if [xcx].$Obj(OcxContainer).dUserMode != 0
      dec eax
    .endif
    mov [xdx].VARIANT.boolVal, ax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientUserMode
; Purpose:    Set the ambient user mode on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientUserMode,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientUserMode", "I_OcxCont_SiteDispatch"
  .if pParams != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    .if [xdx].VARIANT.lVal == 0
      mov [xcx].$Obj(OcxContainer).dUserMode, FALSE
    .else
      mov [xcx].$Obj(OcxContainer).dUserMode, TRUE
    .endif
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientUIDead
; Purpose:    Return the ambient UIDead flag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientUIDead,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientBackColor", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_I4                                ;xdx -> VARIANT
    m2m [xdx].VARIANT.lVal, [xcx].$Obj(OcxContainer).dUIDead, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientShowGrabhandles
; Purpose:    Return the ambient ShowGrabhandlesflag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientShowGrabhandles,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientShowGrabhandles", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    mov [xdx].VARIANT.vt, VT_BOOL
    xor eax, eax
    .if [xcx].$Obj(OcxContainer).dShowGrabhandles != 0
      dec eax
    .endif
    mov [xdx].VARIANT.boolVal, ax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientShowHatching
; Purpose:    Return the ambient ShowHatching flag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientShowHatching,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientShowHatching", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_BOOL                              ;xdx -> VARIANT
    xor eax, eax
    .if [xcx].$Obj(OcxContainer).dShowHatching != 0
      dec eax
    .endif
    mov [xdx].VARIANT.boolVal, ax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientDisplayAsDefault
; Purpose:    Return the ambient DisplayAsDefault flag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientDisplayAsDefault,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientDisplayAsDefault", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_BOOL                              ;xdx -> VARIANT
    xor eax, eax
    .if [xcx].$Obj(OcxContainer).dDisplayAsDefault != 0
      dec eax
    .endif
    mov [xdx].VARIANT.boolVal, ax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.PutAmbientDisplayAsDefault
; Purpose:    Set the ambient DisplayAsDefault flag on the container site.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.PutAmbientDisplayAsDefault,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.PutAmbientDisplayAsDefault", "I_OcxCont_SiteDispatch"
  .if pParams != 0
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxInputParam                                    ;xdx -> VARIANT
    .if [xdx].VARIANT.lVal == 0
      mov [xcx].$Obj(OcxContainer).dDisplayAsDefault, FALSE
    .else
      mov [xcx].$Obj(OcxContainer).dDisplayAsDefault, TRUE
    .endif
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientRightToLeft
; Purpose:    Return the ambient RightToLeft flag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientRightToLeft,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientBackColor", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_I4                                ;xdx -> VARIANT
    m2m [xdx].VARIANT.lVal, [xcx].$Obj(OcxContainer).dRightToLeft, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SiteDispatch.GetAmbientTopToBottom
; Purpose:    Return the ambient TopToBottom flag to the control.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT.

Method I_OcxCont_SiteDispatch.GetAmbientTopToBottom,, pParams:ptr DISPPARAMS, pRetVal:LPVARIANT
  DbgText "I_OcxCont_SiteDispatch.GetAmbientBackColor", "I_OcxCont_SiteDispatch"
  .if pRetVal != NULL
    GetOcxContainer                                     ;xcx -> OcxContainer
    GetOcxRetValue VT_I4                                ;xdx -> VARIANT
    m2m [xdx].VARIANT.lVal, [xcx].$Obj(OcxContainer).dTopToBottom, eax
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

endif
