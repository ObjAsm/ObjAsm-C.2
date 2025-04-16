; ==================================================================================================
; Title:      Ribbon.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Ribbon implementation.
; Links:      https://msdn.microsoft.com/en-us/library/windows/desktop/dd940488(v=vs.85).aspx
;             https://msdn.microsoft.com/en-us/library/windows/desktop/dd316921(v=vs.85).aspx
;             https://msdn.microsoft.com/en-us/library/windows/desktop/dd371681(v=vs.85).aspx
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IUIApplication:GUID
externdef IID_IUICommandHandler:GUID
externdef CLSID_UIRibbonFramework:GUID


Object UIApplication, , Component
  RedefineMethod    Init,                 POINTER, HWND, PSTRINGW
  VirtualMethod     Release

  DefineVariable    pUIRibbonFramework,   POINTER,  NULL
ObjectEnd

Object IUIApplication, , IUnknown
  InterfaceMethod   OnViewChanged,        DWORD, DWORD, POINTER, DWORD, DWORD
  InterfaceMethod   OnCreateUICommand,    DWORD, DWORD, POINTER
  InterfaceMethod   OnDestroyUICommand,   DWORD, DWORD, POINTER

  RedefineVariable  pIID,  offset IID_IUIApplication
ObjectEnd

Object UICommandHandler, , Component
  RedefineMethod    Init,                 POINTER, DWORD, DWORD

  DefineVariable    dCommandID,           DWORD,    0
  DefineVariable    dTypeID,              DWORD,    0
ObjectEnd

Object IUICommandHandler, , IUnknown
  InterfaceMethod   Execute,              DWORD, DWORD, REFPROPERTYKEY, LPVARIANT, POINTER
  InterfaceMethod   UpdateProperty,       DWORD, REFPROPERTYKEY, LPVARIANT, LPVARIANT

  RedefineVariable  pIID,  offset IID_IUICommandHandler
ObjectEnd


; ==================================================================================================
;    UIApplication implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     UIApplication.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner.
;             Arg2: Application window HANDLE.
;             Arg3: Ribbon resource WIDE name.
; Return:     eax: HRESULT.

Method UIApplication.Init, uses xbx xsi, pOwner:POINTER, hWnd:HWND, pRibbonResName:PSTRINGW
  SetObject xsi
  ACall xsi.Init, pOwner, NULL
  mov xbx, $New(IUIApplication)
  OCall [xsi].Interfaces::Collection.Insert, xbx
  OCall xbx::IUIApplication.Init, xsi

  invoke CoCreateInstance, offset CLSID_UIRibbonFramework, NULL, CLSCTX_INPROC_SERVER, \
                           offset IID_IUnknown, addr [xsi].pUIRibbonFramework
  .if SUCCEEDED(eax)
    ICall [xsi].pUIRibbonFramework::IUIFramework.Initialize, hWnd, xbx
    .if SUCCEEDED(eax)
      ICall [xsi].pUIRibbonFramework::IUIFramework.LoadUI, hInstance, pRibbonResName
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     UIApplication.Release
; Purpose:    Releases all framework interfaces.
; Arguments:  None.
; Return:     Nothing.
; Note:       Don't call Done directly. The Component destroys itself when RefCount = 0.
;             To initiate the shutdown process, call this method.

Method UIApplication.Release, uses xsi
  SetObject xsi
  .if [xsi].pUIRibbonFramework != NULL
    ICall [xsi].pUIRibbonFramework::IUIFramework.Destroy
    m2z [xsi].pUIRibbonFramework
  .endif
MethodEnd



; ==================================================================================================
;    IUIApplication implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IUIApplication.OnViewChanged
; Purpose:    Called when the state of a View changes.
; Arguments:  Arg1: dViewID. The ID for the View. Only a value of 0 is valid.
;             Arg2: dTypeID. The UI_VIEWTYPE hosted by the application.
;             Arg3: pView. -> IUnknown. A pointer to the View interface.
;             Arg3: dVerb. The UI_VIEWVERB (or action) performed by the View.
;             Arg4: dReasonCode. Not defined.
; Return:     eax = HRESULT.

Method IUIApplication.OnViewChanged,, dViewID:DWORD, dTypeID:DWORD, pView:POINTER, dVerb:DWORD, \
                                      dReasonCode:DWORD
;  local pRibbon:POINTER, dRibbonHeight:DWORD
;
;  .if dTypeID == UI_VIEWTYPE_RIBBON
;    .if dVerb == UI_VIEWVERB_CREATE
;      DbgText "UI_VIEWVERB_CREATE"
;      mov eax, S_OK
;    .elseif dVerb == UI_VIEWVERB_SIZE
;      DbgText "UI_VIEWVERB_SIZE"
;      ICall pView::IUnknown.QueryInterface, offset IID_IUIRibbon, addr pRibbon
;      .if SUCCEEDED(eax)
;        ICall pRibbon::IUIRibbon.GetHeight, addr dRibbonHeight
;        DbgHex dRibbonHeight
;        ICall pRibbon::IUIRibbon.Release
;      .endif
;      mov eax, S_OK
;    .elseif dVerb == UI_VIEWVERB_DESTROY
;      DbgText "UI_VIEWVERB_DESTROY"
;      mov eax, S_OK
;    .else
;      mov eax, E_NOTIMPL
;    .endif
;  .else
;    mov eax, E_NOTIMPL
;  .endif
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUIApplication.OnCreateUICommand
; Purpose:    Called for each Command specified in the Ribbon framework markup to bind the Command
;             to an IUICommandHandler.
; Arguments:  Arg1: dCommandID. The ID for the Command, which is specified in the markup res. file.
;             Arg2: dTypeID. The Command type that is associated with a specific control.
;             Arg3: pCommandHandler. When this method returns, contains the address of a pointer
;                   to an IUICommandHandler object. This object is a host application Command
;                   handler that is bound to one or more Commands.
; Return:     eax = HRESULT.

Method IUIApplication.OnCreateUICommand, uses xbx xsi, dCommandID:DWORD, dTypeID:DWORD, \
                                                     pCommandHandler:POINTER
;  DbgWarning "IUICommandHandler created", "IUICommandHandler"
;  DbgHex dCommandID,, "IUICommandHandler"
;  DbgHex dTypeID,, "IUICommandHandler"
;  DbgLine "IUICommandHandler"
  SetObject xsi
  mov xbx, $New(UICommandHandler)
  mov xdx, [xsi].pOwner
  OCall xbx::UICommandHandler.Init, [xdx].$Obj(UIApplication).pOwner, dCommandID, dTypeID
  mov xcx, pCommandHandler
  mov [xcx], xax
  mov eax, S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUIApplication.OnDestroyUICommand
; Purpose:    Called for each Command specified in the Windows Ribbon framework markup when the
;             application window is destroyed.
; Arguments:  Arg1: The ID for the Command, which is specified in the markup resource file.
;             Arg2: Command type that is associated with a specific control.
;             Arg3: -> IUICommandHandler object. This value can be NULL.
; Return:     eax = HRESULT.

Method IUIApplication.OnDestroyUICommand,, dCommandID:DWORD, dTypeID:DWORD, pCommandHandler:POINTER
  mov eax, E_NOTIMPL
MethodEnd



; ==================================================================================================
;    UICommandHandler implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     UICommandHandler.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner.
;             Arg2: Command ID.
;             Arg3: Type ID.
; Return:     xax -> IUICommandHandler.

Method UICommandHandler.Init, uses xbx xsi, pOwner:POINTER, dCommandID:DWORD, dTypeID:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, NULL
  m2m [xsi].dCommandID, dCommandID, eax                 ;store dCommandID & dTypeID
  m2m [xsi].dTypeID, dTypeID, eax
  mov xbx, $New(IUICommandHandler)                      ;create IUICommandHandler interface
  OCall xbx::IUICommandHandler.Init, xsi
  OCall [xsi].Interfaces::Collection.Insert, xbx
  ICall xbx::IUICommandHandler.AddRef                   ;increment RefCount
  mov xax, xbx                                          ;return -> IUICommandHandler
MethodEnd



; ==================================================================================================
;    IUICommandHandler implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IUICommandHandler.Execute
; Purpose:    Responds to execute events on Commands bound to the Command handler.
; Arguments:  Arg1: dCommandID. The ID for the Command, which is specified in the markup res. file.
;             Arg2: dVerb. The UI_EXECUTIONVERB or action that is initiated by the user.
;             Arg3: pKey -> Property Key that has changed value. This parameter can be NULL.
;             Arg4: pCurValue -> VARIANT Property Key that has changed value. Can be  NULL.
;             Arg5: pCmdExecProp -> IUISimplePropertySet object that contains Command state
;                   properties and property values, such as screen coordinates and list item
;                   indices. This parameter can be NULL.
; Return:     eax = HRESULT.

Method IUICommandHandler.Execute, uses xsi, dCommandID:DWORD, dVerb:DWORD, pKey:REFPROPERTYKEY, \
                                            pCurValue:LPVARIANT, pCmdExecProp:POINTER
;  DbgText "IUICommandHandler.Execute", "IUICommandHandler"
;  DbgHex dCommandID,, "IUICommandHandler"
;  DbgHex dVerb,, "IUICommandHandler"
;  DbgHex pKey,, "IUICommandHandler"
;  mov xax, pKey
;  .if xax != NULL
;    DbgGUID [xax].PROPERTYKEY.FmtID,, "IUICommandHandler"
;    DbgHex [xax].PROPERTYKEY.PropID,, "IUICommandHandler"
;  .endif
;  DbgHex pCurValue,, "IUICommandHandler"
;  mov xax, pCurValue
;  .if xax != NULL
;    DbgHex VARTYPE ptr [xax].VARIANT.vt,, "IUICommandHandler"
;    DbgHex DWORD ptr [xax].VARIANT.lVal,, "IUICommandHandler"
;  .endif
;  DbgHex pCmdExecProp,, "IUICommandHandler"
;  DbgLine "IUICommandHandler"
  SetObject xsi
  mov xax, [xsi].pOwner                                 ;xax -> UICommandHandler
  mov xcx, [xax].$Obj(UICommandHandler).pOwner          ;xcx -> Windows Application
  invoke SendMessage, [xcx].$Obj(WinApp).hWnd, WM_COMMAND, dCommandID, 0
  mov eax, S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUICommandHandler.UpdateProperty
; Purpose:    Responds to property update requests from the Windows Ribbon framework.
; Arguments:  Arg1: dCommandID. The ID for the Command, which is specified in the markup res. file.
;             Arg2: pKey -> The Property Key to update.
;             Arg3: pCurValue -> VARIANT current value for key. This parameter can be NULL.
;             Arg4: pNewValue -> on method return, contains -> the new VARIANT value for key.
; Return:     eax = HRESULT.

Method IUICommandHandler.UpdateProperty,, dCommandID:DWORD, pKey:REFPROPERTYKEY, \
                                          pCurValue:LPVARIANT, pNewValue:LPVARIANT
;  DbgText "IUICommandHandler.UpdateProperty", "IUICommandHandler"
;  mov xax, pKey
;  .if xax != NULL
;    DbgGUID [xax].PROPERTYKEY.FmtID,, "IUICommandHandler"
;    DbgHex [xax].PROPERTYKEY.PropID,, "IUICommandHandler"
;  .endif
;  DbgHex pCurValue,, "IUICommandHandler"
;  mov xax, pCurValue
;  .if xax != NULL
;    DbgHex VARTYPE ptr [xax].VARIANT.vt,, "IUICommandHandler"
;    DbgHex DWORD ptr [xax].VARIANT.lVal,, "IUICommandHandler"
;  .endif
;  DbgHex pNewValue,, "IUICommandHandler"
;  mov xax, pNewValue
;  .if xax != NULL
;    DbgHex VARTYPE ptr [xax].VARIANT.vt,, "IUICommandHandler"
;    DbgHex DWORD ptr [xax].VARIANT.lVal,, "IUICommandHandler"
;  .endif
;  DbgLine "IUICommandHandler"
  mov eax, E_NOTIMPL
MethodEnd
