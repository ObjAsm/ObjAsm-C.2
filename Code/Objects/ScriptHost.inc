; ==================================================================================================
; Title:      ScriptHost.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of VB Script Host objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;GUIDs defined in the main module
externdef IID_IActiveScript:GUID
externdef IID_IActiveScriptParse:GUID
externdef IID_IActiveScriptSite:GUID
externdef IID_IActiveScriptSiteWindow:GUID

externdef CLSID_ProcessDebugManager:GUID
externdef IID_IProcessDebugManager:GUID
externdef IID_IActiveScriptSiteDebug:GUID


;Messages we use to communicate with the engine
SHM_EXECUTE           equ   WM_USER + 1
SHM_ADDCOMPONENT      equ   WM_USER + 2

SHM_ERROR             equ   WM_USER + 10
SHM_FINISHED          equ   WM_USER + 11
SHM_ENABLEMODELESS    equ   WM_USER + 12

WSF_DEBUG             equ   BIT00


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   ScriptHost
; Purpose:  Implement a host container object for MS-Script engine.
;
; Links:    http://msdn.microsoft.com/en-us/library/ms950396.aspx
;           http://www.microsoft.com/technet/scriptcenter/hubs/vista.mspx
;           http://www.codeproject.com/KB/COM/com_in_c6.aspx
;           http://www.codeguru.com/cpp/com-tech/activex/scripting/article.php/c2583
;           http://support.microsoft.com/kb/308364/en
;           http://www.microsoft.com/germany/technet/datenbank/articles/600491.mspx
;           http://support.microsoft.com/default.aspx?scid=KB;EN-US;Q216073&
; Notes:
;  - The script engine runs in its own thread which is started in the Init method. This enables to
;    use the script engine without freezing the GUI.
;  - The script engine thread has its own message queue and message pump (Run method).
;  - The communication is done using the PostThreadMessage API using the thread ID of the script
;    engine.
;  - The engine must be restarted in order to reset all internal settings.
;  - To interface the engine with application specific objects, the following steps must be followed:
;    1. Write the idl of the interfacing object.
;    2. Compile it with MIDL.exe to obtain the tlb file.
;    3. Add the tlb file to the project resource assigning it a resource ID, i.e.:
;
;           5   TypeLib    "MyInterface.tlb"
;
;    4. Add the object definition of your new interface, i.e.
;
;           Object IMyInterface,, IScriptInterface
;             InterfaceMethod   Clear
;             ...
;           ObjectEnd
;
;       and implement the new defined methods.
;    5. Bind your interface using the following code snipet:
;
;           mov xbx, $New(Component)
;           OCall xbx::Component.Init, addr [xsi].WSH, NULL
;           New IMyInterface
;           OCall [xbx].$Obj(Component).pInterfaces::Collection.Insert, xax
;           OCall xax::IMyInterface.Init, xbx, $OfsCStrW("5"), offset IID_IMyInterface
;           invoke PostThreadMessage, [xsi].WSH.dThreadID, \
;                                     SHM_ADDCOMPONENT, \
;                                     $OfsCStrW("MyInterface"), \
;                                     xbx
;
;       The created component will be managed automatically so you don't need to worry about it.
;    6. Add all GUID declarations of the used IIDs, CLSIDs and LIBIDs to your application.
;    7. Add the following includes to your application:
;
;            % include &COMPath&ActivScp.inc
;            % include &COMPath&ActivDbg.inc
;

Object ScriptHost, ScriptHostID, Streamable
  RedefineMethod    Init,                     POINTER, HWND, REFGUID, DWORD
  RedefineMethod    Done
  DynamicMethod     OnIdle,                   XWORD

  Private
    VirtualMethod   Run
    VirtualEvent    OnAddComponent,   SHM_ADDCOMPONENT
    VirtualEvent    OnExecute,        SHM_EXECUTE
  PrivateEnd

  DefineVariable    hWnd,                     HWND,       0         ;Reported window handle
  DefineVariable    dThreadID,                DWORD,      0
  DefineVariable    hThread,                  HANDLE,     0
  DefineVariable    pCLSID_Engine,            REFGUID,    NULL
  DefineVariable    dFlags,                   DWORD,      0

  DefineVariable    pIActiveScript,           POINTER,    NULL
  DefineVariable    pIActiveScriptParse,      POINTER,    NULL

  DefineVariable    pIActiveScriptSite,       POINTER,    NULL
  DefineVariable    pIActiveScriptSiteWindow, POINTER,    NULL

  DefineVariable    pIProcessDebugManager,    POINTER,    NULL
  DefineVariable    pIActiveScriptSiteDebug,  POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IActiveScriptSite
; Purpose: Implement a IActiveScriptSite COM interface.

Object IActiveScriptSite, IActiveScriptSiteID, IUnknown
  ;Don't change the order of the interface methods!
  InterfaceMethod   GetLCID,                  POINTER
  InterfaceMethod   GetItemInfo,              POINTER, DWORD, POINTER, POINTER
  InterfaceMethod   GetDocVersionString,      POINTER
  InterfaceMethod   OnScriptTerminate,        POINTER, POINTER
  InterfaceMethod   OnStateChange,            DWORD
  InterfaceMethod   OnScriptError,            POINTER
  InterfaceMethod   OnEnterScript
  InterfaceMethod   OnLeaveScript

  RedefineMethod    Done
  RedefineMethod    Init,                     POINTER

  RedefineVariable  pIID,       offset IID_IActiveScriptSite

  Embed     Components,     DataCollection
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IActiveScriptSiteWindow
; Purpose: Implement a IActiveScriptSiteWindow COM interface.

Object IActiveScriptSiteWindow, IActiveScriptSiteWindowID, IUnknown
  ;Don't change the order of the interface methods!
  InterfaceMethod   GetWindow,                POINTER
  InterfaceMethod   EnableModeless,           DWORD

  RedefineVariable  pIID,       offset IID_IActiveScriptSiteWindow
  DefineVariable    hWnd,       HANDLE,   0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IActiveScriptSiteDebug
; Purpose: Implement a IActiveScriptSiteDebug COM interface.

Object IActiveScriptSiteDebug, IActiveScriptSiteDebugID, IUnknown
  ;Don't change the order of the interface methods!
  InterfaceMethod   GetDocumentContextFromPosition, DWORD, DWORD, DWORD, POINTER
  InterfaceMethod   GetApplication,           POINTER
  InterfaceMethod   GetRootApplicationNode,   POINTER
  InterfaceMethod   OnScriptErrorDebug,       POINTER, POINTER, POINTER

  RedefineVariable  pIID,       offset IID_IActiveScriptSiteDebug

  DefineVariable    pIDebugApplication,       POINTER,    NULL
  DefineVariable    pIDebugDocHelper,         POINTER,    NULL
  DefineVariable    pIDebugDocumentContext,   POINTER,    NULL
  DefineVariable    pSourceContext,           POINTER,    NULL
  DefineVariable    dCookie,                  DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IScriptInterface
; Purpose: Implement a IScriptInterface COM interface.

Object IScriptInterface, IScriptInterfaceID, IDispatch
  RedefineMethod    Init,                     POINTER, PSTRINGW, REFGUID
ObjectEnd


; ==================================================================================================

if IMPLEMENT

SCRIPTSIDE_ITEMINFO struc
  pName         PSTRINGW    ?
  pComponent    POINTER     ?
  pIUnknown     POINTER     ?
SCRIPTSIDE_ITEMINFO ends
PSCRIPTSIDE_ITEMINFO typedef ptr SCRIPTSIDE_ITEMINFO

; ==================================================================================================
;    IActiveScriptSite Implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ComponentCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method ComponentCollection.DestroyItem,, pItem:POINTER
  ?mov xdx, pItem
  .if xdx != NULL
    ;Note: we destroy the component since it is possible that the debugger still holds some
    ;      interface pointers without releasing them! This way we clean up all memory resources.
    mov xcx, [xdx].SCRIPTSIDE_ITEMINFO.pComponent
    Destroy xcx::Component.Done
    MemFree pItem                                     ;Frees SCRIPTSIDE_ITEMINFO from heap
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.Done
; Purpose:    Finalize the IActiveScriptSite object.
; Arguments:  None.
; Return:     Nothing.

Method IActiveScriptSite.Done, uses xsi
  DbgText "IActiveScriptSite.Done"
  SetObject xsi
  OCall [xsi].Components::DataCollection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.Init
; Purpose:    Set the owning object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method IActiveScriptSite.Init, uses xsi, pOwner:POINTER
  DbgText "IActiveScriptSite.Init"
  SetObject xsi
  ACall xsi.Init, pOwner
  lea xcx, [xsi].Components
  Override xcx::DataCollection.DestroyItem, ComponentCollection.DestroyItem
  OCall [xsi].Components::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.GetLCID
; Purpose:    Retrieve the locale identifier associated with the host's user interface.
; Arguments:  Arg1: -> LCID.
; Return:     eax = HRESULT.

Method IActiveScriptSite.GetLCID,, pLCID:POINTER
  DbgText "IActiveScriptSite.GetLCID"
  mov eax, E_NOTIMPL                  ;System-defined locale identifier should be used
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.GetItemInfo
; Purpose:    Allow the scripting engine to obtain information about an item added with the
;             IActiveScript::AddNamedItem method.
; Arguments:  Arg1: -> Item name.
;             Arg2: Return mask.
;             Arg3: -> Item -> its IUnknown interface.
;             Arg4: -> Item -> its ITypeInfo interface.
; Return:     eax = HRESULT.

MatchInterfaceName proc pItem:PSCRIPTSIDE_ITEMINFO, pName:PSTRINGW, xArg:XWORD
  mov xcx, pItem
  invoke StrICompW, [xcx].SCRIPTSIDE_ITEMINFO.pName, pName
  .if eax == 0
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
  ret
MatchInterfaceName endp

Method IActiveScriptSite.GetItemInfo, uses xsi, pItemName:POINTER, dReturnMask:DWORD, \
                                                ppIUnknown:POINTER, ppITypeInfo:POINTER
  DbgText "IActiveScriptSite.GetItemInfo"
  SetObject xsi
  DbgStrW pItemName
  OCall [xsi].Components::DataCollection.FirstThat, offset MatchInterfaceName, pItemName, NULL
  .if xax != NULL
    ;Does the engine want a pointer to our Interface object returned?
    .ifBitSet dReturnMask, SCRIPTINFO_IUNKNOWN
      ;Give the engine a pointer to our IUnknown object.
      ;Engine will call its QueryInterface to search for an IDispatch Interface.
      DbgText "SCRIPTINFO_IUNKNOWN"
      OCall [xax].SCRIPTSIDE_ITEMINFO.pComponent::Component.GetInterface, \
                                                            offset IID_IUnknown, ppIUnknown
      xor eax, eax                                      ;S_OK

    ;Does the engine want the ITypeInfo for our IScriptOutput object returned?
    .elseIfBitSet dReturnMask, SCRIPTINFO_ITYPEINFO
      ;Make sure we have an ITypeInfo for our IApp object.
      ;The script engine needs to figure out what args are passed to our IScriptOutput's
      ;extra functions, and what those functions return. And for that, it needs IScriptOutput's
      ;ITypeInfo).
      ;The engine will call its AddRef function, and later Release it when done.
      DbgText "SCRIPTINFO_ITYPEINFO"
      mov eax, E_NOTIMPL

    .else
      DbgWarning "Unknown return mask"
      mov eax, E_NOTIMPL

    .endif
  .else
    mov eax, TYPE_E_ELEMENTNOTFOUND
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.GetDocVersionString
; Purpose:    Retrieve a host-defined string that uniquely identifies the current document version
;             from the host's point of view.
; Arguments:  Arg1: -> POINTER Version string (BSTR).
; Return:     eax = HRESULT.

Method IActiveScriptSite.GetDocVersionString,, ppVersionString:POINTER
  DbgText "IActiveScriptSite.GetDocVersionString"
  mov eax, E_NOTIMPL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.OnScriptTerminate
; Purpose:    Called when the script has completed execution.
; Arguments:  Arg1: -> Script result or NULL.
;             Arg2: -> Exception Info
; Return:     eax = HRESULT.

Method IActiveScriptSite.OnScriptTerminate,, pScriptResult:POINTER, pExceptionInfo:POINTER
  DbgText "IActiveScriptSite.OnScriptTerminate"
  xor eax, eax                                          ;S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.OnStateChange
; Purpose:    Inform the host that the scripting engine has changed states.
; Arguments:  Arg1: Script State.
; Return:     eax = HRESULT.

Method IActiveScriptSite.OnStateChange,, dScriptState:DWORD
  DbgText "IActiveScriptSite.OnStateChange"
  DbgHex dScriptState
  xor eax, eax                                          ;S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.OnScriptError
; Purpose:    Inform the host that an execution error occurred while the engine was
;             running the script.
; Arguments:  Arg1: -> IActiveScriptError interface.
; Return:     eax = HRESULT.

CStrW ErrorFormat, "%s", 13, "Line %u: %s", 13, "%s"

Method IActiveScriptSite.OnScriptError,, pIActiveScriptError:POINTER
  local dContextCookie:DWORD, dLineNumber:DWORD, dCharPosition:DWORD
  local pDesc:BSTR, ExceptionInfo:EXCEPINFO
  local wOutput[1024]:OLECHAR, pString:POINTER, dStrSize:DWORD

  DbgText "IActiveScriptSite.OnScriptError"

  ;Call GetSourcePosition to retrieve the line # where the error occurred in the script
  ICall pIActiveScriptError::IActiveScriptError.GetSourcePosition, \
                                              addr dContextCookie, \
                                              addr dLineNumber, \
                                              addr dCharPosition
  ;Call GetSourceLineText to retrieve the line in the script that has an error.
  m2z pDesc
  ICall pIActiveScriptError::IActiveScriptError.GetSourceLineText, addr pDesc
  ;Call GetExceptionInfo to fill in our EXCEPINFO struc with more information.
  invoke MemZero, addr ExceptionInfo, sizeof ExceptionInfo
  ICall pIActiveScriptError::IActiveScriptError.GetExceptionInfo, addr ExceptionInfo
  .if ExceptionInfo.scode != 80004005h
    ;Format the message we'll display to the user
    invoke wsprintfW, addr wOutput, $OfsCStrW($Esc("%s\nLine %u: %s\n%s")), \
                      ExceptionInfo.bstrSource, \
                      dLineNumber, ExceptionInfo.bstrDescription, pDesc

    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      ;Display the message
      invoke StrLengthW, addr wOutput
      inc eax                                           ;Add the ZTC
      mov dStrSize, eax
      MemAlloc eax
      .if xax != NULL
        mov pString, xax
        invoke WideCharToMultiByte, CP_ACP, 0, addr wOutput, dStrSize, pString, dStrSize, NULL, NULL
        mov xax, pSelf
        mov xcx, [xax].IActiveScriptSite.pOwner         ;Component
        mov xdx, [xcx].$Obj(Component).pOwner           ;ScriptHost
        invoke PostMessage, [xdx].$Obj(ScriptHost).hWnd, SHM_ERROR, pString, 0
        ;The callee must dispose the string, but if the last API fails, we should do it
        .if eax == FALSE
          MemFree pString
        .endif
      .endif
    else
      invoke StrNew, addr wOutput
      .if xax != NULL
        mov pString, xax
        mov xdx, pSelf
        mov xcx, [xdx].$Obj(IActiveScriptSite).pOwner   ;Component
        mov xdx, [xcx].$Obj(Component).pOwner           ;ScriptHost
        invoke PostMessage, [xdx].$Obj(ScriptHost).hWnd, SHM_ERROR, pString, 0
        ;The callee must dispose the string, but if the last API fails, we should do it
        .if eax == FALSE
          invoke StrDispose, pString
        .endif
      .endif
    endif
  .endif

  ;Free what we got from the IActiveScriptError functions
  invoke SysFreeString, ExceptionInfo.bstrSource
  invoke SysFreeString, ExceptionInfo.bstrDescription
  invoke SysFreeString, ExceptionInfo.bstrHelpFile
  invoke SysFreeString, pDesc
  xor eax, eax                                          ;S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.OnEnterScript
; Purpose:    Inform the host that the scripting engine has begun executing the script code.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IActiveScriptSite.OnEnterScript
  DbgText "IActiveScriptSite.OnEnterScript"
  xor eax, eax                                          ;S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSite.OnLeaveScript
; Purpose:    Inform the host that the scripting engine has returned from executing script code.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IActiveScriptSite.OnLeaveScript
  DbgText "IActiveScriptSite.OnLeaveScript"
  xor eax, eax                                          ;S_OK
MethodEnd


; ==================================================================================================
;    IActiveScriptSiteWindow Implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSiteWindow.EnableModeless
; Purpose:    Cause the host to enable or disable its main window as well as any modeless dialog
;             boxes.
; Arguments:  Arg1: Enable boolean.
; Return:     eax = HRESULT.

Method IActiveScriptSiteWindow.EnableModeless,, dEnable:DWORD
  DbgText "IActiveScriptSiteWindow.EnableModeless"
  SetObject xcx
  mov eax, dEnable
  mov xdx, [xcx].pOwner
  mov xdx, [xdx].$Obj(Component).pOwner
  invoke PostThreadMessage, [xdx].$Obj(ScriptHost).dThreadID, SHM_ENABLEMODELESS, xax, 0
  xor eax, eax                                          ;S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSiteWindow.GetWindow
; Purpose:    Retrieve the window handle that can act as the owner of a pop-up window that the
;             scripting engine must display.
; Arguments:  Arg1: -> Window handle.
; Return:     eax = HRESULT.

Method IActiveScriptSiteWindow.GetWindow,, phWnd:POINTER
  DbgText "IActiveScriptSiteWindow.GetWindow"
  .if phWnd != NULL
    SetObject xcx
    mov xdx, [xcx].pOwner
    mov xax, [xdx].$Obj(Component).pOwner
    mov xdx, [xax].$Obj(ScriptHost).hWnd
    mov xax, phWnd
    mov [xax], xdx
    xor eax, eax                                        ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd


; ==================================================================================================
;    IActiveScriptSiteDebug Implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSiteDebug.GetDocumentContextFromPosition
; Purpose:    Used by the language engine to delegate IDebugCodeContext.GetSourceContext.
; Arguments:  Arg1: Source content as provided to ParseScriptText or AddScriptlet
;             Arg2: Character offset relative to start of script block or scriptlet.
;             Arg3: Number of characters in this context.
;             Arg4: The document context corresponding to this character-position range.
; Return:     eax = HRESULT.

Method IActiveScriptSiteDebug.GetDocumentContextFromPosition, uses xsi, dSourceContext:DWORD, \
                            dCharacterOffset:DWORD, dNumChars:DWORD, ppIDebugDocumentContext:POINTER
  local dStartPos:DWORD

  DbgText "IActiveScriptSiteDebug.GetDocumentContextFromPosition"
  SetObject xsi
  .if [xsi].pIDebugDocHelper != NULL
    ICall [xsi].pIDebugDocHelper::IDebugDocumentHelper.GetScriptBlockInfo, \
                                    dSourceContext, NULL, addr dStartPos, NULL
    mov edx, dStartPos
    add edx, dCharacterOffset
    ICall [xsi].pIDebugDocHelper::IDebugDocumentHelper.CreateDebugDocumentContext, \
                                    edx, dNumChars, ppIDebugDocumentContext
  .else
    mov eax, E_NOTIMPL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSiteDebug.GetApplication
; Purpose:    Return the debug application object associated with this script site.
; Arguments:  Arg1: -> Debug application object associated with the script site.
; Return:     eax = HRESULT.

Method IActiveScriptSiteDebug.GetApplication, uses xsi, ppIDebugApplication:POINTER
  DbgText "IActiveScriptSiteDebug.GetApplication"
  SetObject xsi
  .if ppIDebugApplication == NULL
    mov eax, E_POINTER
  .else
    .if [xsi].pIDebugApplication != NULL
      ICall [xsi].pIDebugApplication::IDebugApplication.AddRef
    .endif
    mov xcx, ppIDebugApplication
    m2m POINTER ptr [xcx], [xsi].pIDebugApplication, xdx
  .endif
  xor eax, eax                                          ;S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSiteDebug.GetRootApplicationNode
; Purpose:    Get the application node under which script documents should be added.
; Arguments:  Arg1: -> The debug application node that holds script documents. Can be NULL.
; Return:     eax = HRESULT.

Method IActiveScriptSiteDebug.GetRootApplicationNode,, ppRoot:POINTER
  DbgText "IActiveScriptSiteDebug.GetRootApplicationNode"
  SetObject xcx
  .if ppRoot == NULL
    mov eax, E_POINTER
  .else
    .if [xcx].pIDebugDocHelper != NULL
      ICall [xcx].pIDebugDocHelper::IDebugDocumentHelper.GetDebugApplicationNode, ppRoot
    .else
      mov eax, E_NOTIMPL
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IActiveScriptSiteDebug.OnScriptErrorDebug
; Purpose:    Allow a smart host to determine how to handle run-time errors.
; Arguments:  Arg1: The run-time error that occurred.
;             Arg2: Flag indicating whether to pass the error to the debugger to do JIT debugging.
;             Arg3: Flag indicating whether to call IActiveScriptSite::OnScriptError when the user
;                   decides to continue without debugging.
; Return:     eax = HRESULT.

Method IActiveScriptSiteDebug.OnScriptErrorDebug,, pIActiveScriptErrorDebug:POINTER, \
                 pEnterDebugger:POINTER, pCallOnScriptErrorWhenContinuing:POINTER
  DbgText "IActiveScriptSiteDebug.OnScriptErrorDebug"
  .if pEnterDebugger != NULL
    mov xcx, pEnterDebugger
    mov DWORD ptr [xcx], TRUE
  .endif

  .if pCallOnScriptErrorWhenContinuing != NULL
    mov xcx, pCallOnScriptErrorWhenContinuing
    mov DWORD ptr [xcx], TRUE
  .endif

  xor eax, eax                                          ;S_OK
MethodEnd


; ==================================================================================================
;    IScriptInterface implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IScriptInterface.Init
; Purpose:    Initialize the IScriptInterface interface object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> TypeLib resource index (UNICODE string). If NULL, /1 is taken.
;             Arg3: -> Interfeace GUID.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IScriptInterface.Init, uses xbx xsi, pOwner:POINTER, pResIndexStr:PSTRINGW, pIID:REFGUID
  local pITypeLib:POINTER, wFileName[2*MAX_PATH]:CHRW

  SetObject xsi
  m2m [xsi].pOwner, pOwner, xax
  mov [xsi].pDispInterface, xsi                         ;Use the same VTable to dispatch

  lea xbx, wFileName
  invoke GetModuleFileNameW, 0, xbx, MAX_PATH
  .if pResIndexStr != NULL
    invoke StrCatCharW, xbx, 5Ch
    invoke StrCCatW, xbx, pResIndexStr, sizeof wFileName/2
  .endif
  invoke LoadTypeLib, xbx, addr pITypeLib
  .if SUCCEEDED(eax)
    ICall pITypeLib::ITypeLib.GetTypeInfoOfGuid, pIID, addr [xsi].pITypeInfo
    ICall pITypeLib::ITypeLib.Release
    mov eax, TRUE
  .else
    DbgComError eax
    xor eax, eax
  .endif
MethodEnd


; ==================================================================================================
;    ScriptHost implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScriptHost.Done
; Purpose:    Finalize the Script engine object.
; Arguments:  None.
; Return:     Nothing.

Method ScriptHost.Done, uses xsi
  SetObject xsi
  .if [xsi].hThread != 0
    invoke SuspendThread, [xsi].hThread
    .if [xsi].pIActiveScript != NULL
      ICall [xsi].pIActiveScript::IActiveScript.InterruptScriptThread, SCRIPTTHREADID_ALL, 0, 0
    .endif
    invoke ResumeThread, [xsi].hThread
    invoke WaitForSingleObject, [xsi].hThread, 4000
    .if eax == WAIT_TIMEOUT
      DbgWarning "Script thead was forced to terminate; some resources were not released."
      invoke TerminateThread, [xsi].hThread, -1
    .endif
    invoke CloseHandle, [xsi].hThread
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScriptHost.Init
; Purpose:    Initialize the Script engine object. Now it is ready to recieve WM_xxx messages.
; Arguments:  Arg1: -> Owner Object.
;             Arg2: Window handle to report.
;             Arg3: -> CLSID of the script engine to use (i.e. offset CLSID_VBScript).
;             Arg4: Window handle to report.
; Return:     eax = TRUE is succeeded, otherwise FALSE.

Method ScriptHost.Init, uses xbx xsi, pOwner:POINTER, hWnd:HWND, pCLSID_Engine:REFGUID, dFlags:DWORD
  SetObject xsi
  m2m [xsi].dFlags, dFlags, eax
  m2m [xsi].hWnd, hWnd, xcx
  m2m [xsi].pCLSID_Engine, pCLSID_Engine, xax
  ACall xsi.Init, pOwner
  lea xbx, [xsi].dThreadID
  invoke CreateThread, NULL, 0, $MethodAddr(ScriptHost.Run), xsi, CREATE_SUSPENDED, xbx
  .if xax != 0
    mov [xsi].hThread, xax
    invoke ResumeThread, xax

    ;Loop until the thread is ready to recieve messages or fails to initialize
    .while TRUE
      mov eax, [xsi].dThreadID
      .break .if eax == 0                               ;Thread initialization failure
      invoke PostThreadMessage, eax, WM_NULL, 0, 0
      .break .if eax != FALSE
      invoke Sleep, 10
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScriptHost.Run
; Purpose:    Execute a specified script.
; Arguments:  None.
; Return:     Nothing.

Method ScriptHost.Run, uses xbx xdi xsi
  local Msg:MSG, xIdleCount:XWORD, pComponent:$ObjPtr(Component)

  SetObject xsi

  invoke CoInitializeEx, NULL, COINIT_MULTITHREADED     ;Initialize COM library

  mov xbx, $New(Component)
  mov pComponent, xbx
  OCall xbx::Component.Init, xsi, NULL
  mov [xsi].pIActiveScriptSite, $New(IActiveScriptSite)
  OCall [xbx].$Obj(Component).Interfaces::Collection.Insert, xax
  OCall xax::IActiveScriptSite.Init, xbx
  mov [xsi].pIActiveScriptSiteWindow, $New(IActiveScriptSiteWindow)
  OCall [xbx].$Obj(Component).Interfaces::Collection.Insert, xax
  OCall xax::IActiveScriptSiteWindow.Init, xbx

  m2z [xsi].pIActiveScriptSiteDebug
  .ifBitSet [xsi].dFlags, WSF_DEBUG
    invoke CoCreateInstance, offset CLSID_ProcessDebugManager, NULL, CLSCTX_INPROC_SERVER, \
                             offset IID_IProcessDebugManager, addr [xsi].pIProcessDebugManager

    .if SUCCEEDED(eax)
      mov xdi, $New(IActiveScriptSiteDebug)
      mov [xsi].pIActiveScriptSiteDebug, xax
      OCall xdi::IActiveScriptSiteDebug.Init, xbx
      OCall [xbx].$Obj(Component).Interfaces::Collection.Insert, xdi

      ICall [xsi].pIProcessDebugManager::IProcessDebugManager.CreateApplication, \
                                          addr [xdi].$Obj(IActiveScriptSiteDebug).pIDebugApplication
      ICall [xdi].$Obj(IActiveScriptSiteDebug).pIDebugApplication::IDebugApplication.SetName, \
                                          $OfsCStrW("Scripting Application")
      ICall [xsi].pIProcessDebugManager::IProcessDebugManager.AddApplication, \
                                          [xdi].$Obj(IActiveScriptSiteDebug).pIDebugApplication, \
                                          addr [xdi].$Obj(IActiveScriptSiteDebug).dCookie
      ICall [xsi].pIProcessDebugManager::IProcessDebugManager.CreateDebugDocumentHelper, \
                                          NULL, \
                                          addr [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper
      ICall [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper::IDebugDocumentHelper.Init, \
                                          [xdi].$Obj(IActiveScriptSiteDebug).pIDebugApplication, \
                                          $OfsCStrW("Doc Name"), \
                                          $OfsCStrW("Long Doc Name"), \
                                          TEXT_DOC_ATTR_READONLY
      ICall [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper::IDebugDocumentHelper.Attach, NULL
    .endif
  .endif

  invoke CoCreateInstance, [xsi].pCLSID_Engine, NULL, \ ;Create an instance of ActiveScript
              CLSCTX_ALL, offset IID_IActiveScript, \   ;  and get -> ActiveScript Interface
              addr [xsi].pIActiveScript                 ;  in pIActiveScript
  .if SUCCEEDED(eax)                                    ;If creation was successful
    ICall [xsi].pIActiveScript::IActiveScript.QueryInterface, \
          offset IID_IActiveScriptParse, addr [xsi].pIActiveScriptParse
    .if SUCCEEDED(eax)                                  ;If creation was successful
      ICall [xsi].pIActiveScriptParse::IActiveScriptParse.InitNew
      ICall [xsi].pIActiveScript::IActiveScript.SetScriptSite, [xsi].pIActiveScriptSite

      ;Thread message pump
      lea xbx, Msg
      m2z xIdleCount
      .if [xsi].hWnd != 0
        .repeat
          invoke PeekMessage, xbx, 0, 0, 0, PM_REMOVE
          .if eax == FALSE
            OCall xsi.OnIdle, xIdleCount
            .if eax == 0
              invoke WaitMessage
            .else
              inc xIdleCount
            .endif
          .else
            .break .if Msg.message == WM_QUIT
            m2z xIdleCount
            DispatchEvent , Msg.message, Msg.wParam, Msg.lParam
          .endif
        .until FALSE
        mov xax, Msg.wParam
      .else
        mov eax, -1
      .endif

      ICall [xsi].pIActiveScript::IActiveScript.Close
      RELEASE_AND_NULLIFY [xsi].pIActiveScriptParse
    .endif
    RELEASE_AND_NULLIFY [xsi].pIActiveScript
  .endif

  .if [xsi].pIActiveScriptSiteDebug != NULL
    mov xdi, [xsi].pIActiveScriptSiteDebug
    ICall [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper::IDebugDocumentHelper.Detach
    SAFE_RELEASE_AND_NULLIFY [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper
    ICall [xsi].pIProcessDebugManager::IProcessDebugManager.RemoveApplication, \
                                       [xdi].$Obj(IActiveScriptSiteDebug).dCookie
    SAFE_RELEASE_AND_NULLIFY [xdi].$Obj(IActiveScriptSiteDebug).pIDebugApplication
  .endif

  invoke CoUninitialize

  m2z [xsi].dThreadID                                   ;Mark as terminated
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScriptHost.OnAddComponent
; Purpose:    Add a new component to the script engine in response to a SHM_ADDCOMPONENT message.
; Arguments:  Arg1: -> Wide name of the object.
;             Arg2: -> Component.
; Return:     Nothing.

Method ScriptHost.OnAddComponent, uses xbx xsi, pName:PSTRINGW, pComponent:LPARAM
  SetObject xsi

  MemAlloc sizeof SCRIPTSIDE_ITEMINFO

  mov xcx, [xsi].pIActiveScriptSite
  OCall [xcx].$Obj(IActiveScriptSite).Components::DataCollection.Insert, xax

  m2m [xax].SCRIPTSIDE_ITEMINFO.pName, pName, xcx
  m2m [xax].SCRIPTSIDE_ITEMINFO.pComponent, pComponent, xdx

  ;We request an interface pointer to get control of the Component destruction
  lea xbx, [xax].SCRIPTSIDE_ITEMINFO.pIUnknown
  OCall pComponent::Component.GetInterface, offset IID_IUnknown, xbx

  ICall [xsi].pIActiveScript::IActiveScript.AddNamedItem, \
                                            pName, SCRIPTITEM_ISVISIBLE; or SCRIPTITEM_NOCODE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScriptHost.OnExecute
; Purpose:    Message Handler for SHM_EXECUTE.
; Arguments:  Arg1: -> WIDE string containing the script to execute.
;             Arg2: Nothing (unused).
; Return:     Nothing.

Method ScriptHost.OnExecute, uses xbx xdi xsi, pScript:PSTRINGW, lParam:LPARAM
  local ExcepInfo:EXCEPINFO

  DbgText "ScriptHost.OnExecute"
  SetObject xsi

  mov xdi, [xsi].pIActiveScriptSiteDebug
  .if xdi != NULL
    ICall [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper::IDebugDocumentHelper.AddDBCSText, \
                                                                                    pScript
    invoke StrLengthW, pScript
    lea xbx, [xdi].$Obj(IActiveScriptSiteDebug).pSourceContext
    ICall [xdi].$Obj(IActiveScriptSiteDebug).pIDebugDocHelper::IDebugDocumentHelper.DefineScriptBlock, \
                                    0, eax, [xsi].pIActiveScript, FALSE, xbx
  .endif

  ICall [xsi].pIActiveScript::IActiveScript.SetScriptState, SCRIPTSTATE_CONNECTED
  ;Script is loaded and connected for sinking events.

  ICall [xsi].pIActiveScriptParse::IActiveScriptParse.ParseScriptText, \
                                   pScript, NULL, NULL, NULL, 0, 0, 0, NULL, addr ExcepInfo
  .if FAILED(eax)
    DbgWarning "IActiveScriptParse.ParseScriptText returned an error"
    DbgComError eax
  .endif
  MemFree pScript

  invoke PostMessage, [xsi].hWnd, SHM_FINISHED, 0, 0    ;Inform we are ready
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScriptHost.OnIdle
; Purpose:    Procedure called when the ScriptHost is idle.
; Arguments:  Arg1: Number of times OnIdle was called since the last processed message.
; Return:     eax = Zero to stop getting more OnIdle calls.

Method ScriptHost.OnIdle,, xCount:XWORD
  xor eax, eax
MethodEnd

endif
