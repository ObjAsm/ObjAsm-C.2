; ==================================================================================================
; Title:      IDocHostUIHandler.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of IDocHostUIHandler Interface.
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


sIID_IDocHostUIHandler equ <BD3F23C0-D43E-11CF-893B-00AA00BDCE1A>
externdef IID_IDocHostUIHandler:GUID

DOCHOST_E_UNKNOWN equ -1

DOCHOSTUIINFO struct
  cbSize        DWORD   ?
  dwFlags       DWORD   ?
  dwDoubleClick DWORD   ?
  pchHostCss    OLECHAR ?
  pchHostNS     OLECHAR ?
DOCHOSTUIINFO ends
PDOCHOSTUIINFO typedef ptr DOCHOSTUIINFO

;Definitions in mshtmhst.h

CONTEXT_MENU_DEFAULT        equ     0
CONTEXT_MENU_IMAGE          equ     1
CONTEXT_MENU_CONTROL        equ     2
CONTEXT_MENU_TABLE          equ     3
CONTEXT_MENU_TEXTSELECT     equ     4
CONTEXT_MENU_ANCHOR         equ     5
CONTEXT_MENU_UNKNOWN        equ     6
CONTEXT_MENU_VSCROLL        equ     10
CONTEXT_MENU_HSCROLL        equ     11

; --------------------------------------------------------------------------------------------------
; Object:  IDocHostUIHandler
; Purpose: Implements IDocHostUIHandler interface.

Object IDocHostUIHandler,, IUnknown
  InterfaceMethod   ShowContextMenu,      DWORD, POINTER, POINTER, POINTER,
  InterfaceMethod   GetHostInfo,          PDOCHOSTUIINFO
  InterfaceMethod   ShowUI,               DWORD, POINTER, POINTER, POINTER, POINTER
  InterfaceMethod   HideUI
  InterfaceMethod   UpdateUI
  InterfaceMethod   EnableModeless,       BOOL
  InterfaceMethod   OnDocWindowActivate,  BOOL
  InterfaceMethod   OnFrameWindowActivate,BOOL
  InterfaceMethod   ResizeBorder,         POINTER, POINTER, BOOL
  InterfaceMethod   TranslateAccelerator, POINTER, POINTER, DWORD
  InterfaceMethod   GetOptionKeyPath,     POINTER, DWORD
  InterfaceMethod   GetDropTarget,        POINTER, POINTER
  InterfaceMethod   GetExternal,          POINTER
  InterfaceMethod   TranslateUrl,         DWORD, POINTER, POINTER
  InterfaceMethod   FilterDataObject,     POINTER, POINTER

  RedefineVariable  pIID,             offset IID_IDocHostUIHandler
  DefineVariable    pHostDispatch,    POINTER,  NULL
  DefineVariable    dShowContextMenu, DWORD,    DOCHOST_E_UNKNOWN
  DefineVariable    dShowUI,          DWORD,    DOCHOST_E_UNKNOWN
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     IDocHostUIHandler implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.ShowContextMenu
; Purpose:    Enables MSHTML to display a shortcut menu.
; Arguments:  Arg1: [in] A DWORD that specifies the identifier of the shortcut menu to be displayed.
;                     CONTEXT_MENU_DEFAULT:    The default shortcut menu for a Web page.
;                     CONTEXT_MENU_IMAGE:      Shortcut menu for images.
;                     CONTEXT_MENU_CONTROL:    Shortcut menu for scrollbars and select elements.
;                     CONTEXT_MENU_TABLE:      Not used.
;                     CONTEXT_MENU_TEXTSELECT: Shortcut menu for selected text.
;                     CONTEXT_MENU_ANCHOR:     Shortcut menu for hyperlinks.
;                     CONTEXT_MENU_UNKNOWN:    Not used.
;                     CONTEXT_MENU_VSCROLL:    Shortcut menu for vertical scroll bar. 
;                     CONTEXT_MENU_HSCROLL:    Shortcut menu for horizontal scroll bar. 
;                     CONTEXT_MENU_MEDIA:      Windows Internet Explorer 9 and later. 
;                                              Shortcut menu for media element controls. 
;             Arg2: [in] -> POINT structure containing the screen coordinates for the menu.
;             Arg3: [in] -> IUnknown of an IOleCommandTarget interface used to query command status
;                   and execute commands on this object.
;             Arg4: [in] -> IDispatch interface of the object at the screen coordinates specified in
;                   ppt. This enables a host to pass particular objects, such as anchor tags and
;                   images, to provide more specific context.
; Return:     eax = HRESULT.
;             S_OK: Host displays its UI. MSHTML will not attempt to display its UI.
;             S_FALSE: Host did not display its UI. MSHTML will display its UI.
;             DOCHOST_E_UNKNOWN: Menu identifier is unknown. MSHTML might attempt an alternative
;                                identifier from a previous version

Method IDocHostUIHandler.ShowContextMenu,, dwID:DWORD, pPoint:POINTER, pcmdtReserved:POINTER, \
                                           pdispReserved:POINTER
  DbgText "IDocHostUIHandler.ShowContextMenu", "IDocHostUIHandler"
  SetObject xcx
  mov eax, [xcx].dShowContextMenu
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.GetHostInfo
; Purpose:    Gets the UI capabilities of the application that is hosting MSHTML.
; Arguments:  Arg1: [in, out] -> DOCHOSTUIINFO structure that receives the host's UI capabilities.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.GetHostInfo,, pInfo:PDOCHOSTUIINFO
  DbgText "IDocHostUIHandler.GetHostInfo", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.ShowUI
; Purpose:    Enables the host to replace MSHTML menus and toolbars.
; Arguments:  Arg1: [in] A DWORD that receives a DOCHOSTUITYPE value that indicates the type of UI.
;                     DOCHOSTUITYPE_BROWSE: value that indicates the user interface is for browsing.
;                     DOCHOSTUITYPE_AUTHOR: Value that indicates the user interface is for authoring.
;             Arg2: [in] -> IOleInPlaceActiveObject interface for the active object.
;             Arg3: [in] -> IOleCommandTarget interface for the object.
;             Arg4: [in] -> IOleInPlaceFrame interface for the object. Menus and toolbars must use
;                   this parameter.
;             Arg5: [in] -> IOleInPlaceUIWindow interface for the object. Toolbars must use
;                   this parameter.
; Return:     eax = HRESULT.
;             S_OK: Host displays its UI. MSHTML will not display its UI.
;             S_FALSE: Host did not display its UI. MSHTML will display its UI.
;             DOCHOST_E_UNKNOWN: Host did not recognize the UI identifier. MSHTML will either try
;               an alternative identifier for compatibility with a previous version,
;               or display its UI.

Method IDocHostUIHandler.ShowUI,, dwID:DWORD, pActiveObject:POINTER, pCommandTarget:POINTER, \
                                  pFrame:POINTER, pDoc:POINTER
  DbgText "IDocHostUIHandler.ShowUI", "IDocHostUIHandler"
  SetObject xcx
  mov eax, [xcx].dShowUI
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.HideUI
; Purpose:    Enables the host to remove its menus and toolbars.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.HideUI
  DbgText "IDocHostUIHandler.HideUI", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.UpdateUI
; Purpose:    Notifies the host that the command state has changed.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.UpdateUI
  DbgText "IDocHostUIHandler.UpdateUI", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.EnableModeless
; Purpose:    Called by the MSHTML implementation of IOleInPlaceActiveObject::EnableModeless.
;             Also called when MSHTML displays a modal UI.
; Arguments:  Arg1: [in] A BOOL that indicates if the host's modeless dialog boxes are enabled or
;                   disabled.
;                     TRUE:  Modeless dialog boxes are enabled.
;                     FALSE: Modeless dialog boxes are disabled.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.EnableModeless,, fEnable:BOOL
    DbgText "IDocHostUIHandler.EnableModeless", "IDocHostUIHandler"
    mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.OnDocWindowActivate
; Purpose:    Called by the MSHTML implementation of IOleInPlaceActiveObject::OnDocWindowActivate.
; Arguments:  Arg1: [in] A BOOL value that indicates the state of the document window.
;               TRUE:  The window is activated.
;               FALSE: The window is deactivated.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.OnDocWindowActivate,, fActivate:BOOL
  DbgText "IDocHostUIHandler.OnDocWindowActivate", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.OnFrameWindowActivate
; Purpose:    Called by the MSHTML implementation of IOleInPlaceActiveObject::OnFrameWindowActivate.
; Arguments:  Arg1: [in] A BOOL value that indicates the state of the container's top-level frame
;                   window.
;               TRUE:  The window is activated.
;               FALSE: The window is deactivated.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.OnFrameWindowActivate,, fActivate:BOOL
  DbgText "IDocHostUIHandler.OnFrameWindowActivate", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.ResizeBorder
; Purpose:    Called by the MSHTML implementation of IOleInPlaceActiveObject::ResizeBorder.
; Arguments:  Arg1: [in] A constant pointer to a RECT for the new outer rectangle of the border.
;             Arg2: [in] -> IOleInPlaceUIWindow interface for the frame or document
;                   window whose border is to be changed.
;             Arg3: [in] A BOOL that is TRUE if the frame window is calling
;                   IDocHostUIHandler::ResizeBorder, or FALSE otherwise.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.ResizeBorder,, prcBorder:POINTER, pUIWindow:POINTER, fFrameWindow:BOOL
  DbgText "IDocHostUIHandler.ResizeBorder", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler._TranslateAccelerator
; Purpose:    Called by MSHTML when IOleInPlaceActiveObject::TranslateAccelerator or
;             IOleControlSite::TranslateAccelerator is called.
; Arguments:  Arg1: [in] -> MSG structure that specifies the message to be translated.
;             Arg2: [in] -> a GUID for the command group identifier.
;             Arg3: [in] A DWORD that specifies a command identifier.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.TranslateAccelerator,, lpMsg:POINTER, pguidCmdGroup:POINTER, nCmdID:DWORD
  DbgText "IDocHostUIHandler.TranslateAccelerator", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.GetOptionKeyPath
; Purpose:    Gets a registry subkey path that overrides the default Internet Explorer registry
;             settings.
; Arguments:  Arg1: [out] A pointer to an LPOLESTR that receives the registry subkey string where
;                   the host stores its registry settings.
;             Arg2: [in] Reserved. Must be set to NULL.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.GetOptionKeyPath,, pchKey:POINTER, dReserved:DWORD
  DbgText "IDocHostUIHandler.GetOptionKeyPath", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.GetDropTarget
; Purpose:    Enables the host to supply an alternative IDropTarget interface.
; Arguments:  Arg1: [in] -> IDropTarget interface for the current drop target object supplied
;                   by MSHTML.
;             Arg2: [out] -> variable that receives an IDropTarget interface pointer for the
;                   alternative drop target object supplied by the host.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.GetDropTarget,, pDropTarget:POINTER, ppDropTarget:POINTER
  DbgText "IDocHostUIHandler.GetDropTarget", "IDocHostUIHandler"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.GetExternal
; Purpose:    Gets the host's IDispatch interface.
; Arguments:  Arg1: [out] -> a variable that receives an IDispatch interface pointer for
;                   the host application.
; Return:     eax = HRESULT.

Method IDocHostUIHandler.GetExternal, uses xsi, ppIDispatch:POINTER
  DbgText "IDocHostUIHandler.GetExternal", "IDocHostUIHandler"
  SetObject xsi
  .if [xsi].pHostDispatch != NULL
    ICall [xsi].pHostDispatch::IUnknown.AddRef
    mov xdx, ppIDispatch
    m2m POINTER ptr [xdx], [xsi].pHostDispatch, ecx
    mov eax, S_OK
  .else
    mov xdx, ppIDispatch
    and POINTER ptr [xdx], NULL
    mov eax, S_FALSE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.TranslateUrl
; Purpose:    Enables the host to modify the URL to be loaded.
; Arguments:  Arg1: [in] Reserved. Must be set to NULL.
;             Arg2: [in] -> OLECHAR that specifies the current URL for navigation.
;             Arg3: [out] -> variable that receives an OLECHAR pointer containing the new URL.
; Return:     eax = HRESULT.
;             Returns S_OK if the URL was translated, or S_FALSE if the URL was not translated.
; Note:       The host allocates the buffer ppchURLOut by using CoTaskMemAlloc.

Method IDocHostUIHandler.TranslateUrl,, dwTranslate:DWORD, pchURLIn:POINTER, ppchURLOut:POINTER
  DbgText "IDocHostUIHandler.TranslateUrl", "IDocHostUIHandler"
  .if ppchURLOut != NULL
    mov xcx, ppchURLOut
    and POINTER ptr [xcx], NULL
  .endif
  mov eax, S_FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDocHostUIHandler.FilterDataObject
; Purpose:    Enables the host to replace the MSHTML data object.
; Arguments:  Arg1: [in] -> IDataObject interface supplied by MSHTML.
;             Arg2: [out] -> variable that receives an IDataObject interface pointer
;                   supplied by the host.
; Return:     eax = HRESULT.
;             Returns S_OK if the data object is replaced, or S_FALSE if it is not replaced.

Method IDocHostUIHandler.FilterDataObject,, pDO:POINTER, ppDORet:POINTER
  DbgText "IDocHostUIHandler.FilterDataObject", "IDocHostUIHandler"
  mov eax, S_FALSE
MethodEnd

endif