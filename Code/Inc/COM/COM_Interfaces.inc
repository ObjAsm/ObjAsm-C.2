; ==================================================================================================
; Title:      COM_Interfaces.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm common COM Interfaces.
; Notes:      Most of the interfaces can be found in the OBJIDL.H file.
;             Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


sGUID_NULL                      textequ   <00000000-0000-0000-0000-000000000000>

sIID_IDual                      textequ   <4BA83B54-AA33-11d8-9C44-B8C5AAA14D7C>
sIID_IMarshal                   textequ   <00000003-0000-0000-C000-000000000046>
sIID_IUnmarshal                 textequ   <0000001B-0000-0000-C000-000000000046>
sIID_IStdMarshalInfo            textequ   <00000018-0000-0000-C000-000000000046>
sIID_IExternalConnection        textequ   <00000019-0000-0000-C000-000000000046>
sIID_IProvideMultipleClassInfo  textequ   <A7ABA9C1-8983-11CF-8F20-00805F2CD064>


; ==================================================================================================
;    Interface definitions
; ==================================================================================================

;COM_INTERFACE_BEG IClassFactory, IUnknown, <00000001-0000-0000-C000-000000000046>
;  COM_MTD_STD   CreateInst,                   POINTER, POINTER, POINTER
;  COM_MTD_STD   LockServer,                   DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IClassFactory2, IClassFactory, <B196B28F-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   GetLicInfo,                   POINTER
;  COM_MTD_STD   RequestLicKey,                DWORD, POINTER
;  COM_MTD_STD   CreateInstanceLic,            POINTER, POINTER, POINTER, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ICreateTypeInfo, IUnknown, <00020405-0000-0000-C000-000000000046>
;  COM_MTD_STD   SetGuid,                      POINTER
;  COM_MTD_STD   SetTypeFlags,                 DWORD
;  COM_MTD_STD   SetDocString,                 POINTER
;  COM_MTD_STD   SetHelpContext,               DWORD
;  COM_MTD_STD   SetVersion,                   DWORD, DWORD
;  COM_MTD_STD   AddRefTypeInfo,               POINTER
;  COM_MTD_STD   AddFuncDesc,                  DWORD, POINTER
;  COM_MTD_STD   AddImplType,                  DWORD, DWORD
;  COM_MTD_STD   SetImplTypeFlags,             DWORD, SDWORD
;  COM_MTD_STD   SetAlignment,                 DWORD
;  COM_MTD_STD   SetSchema,                    POINTER
;  COM_MTD_STD   AddVarDesc,                   DWORD, POINTER
;  COM_MTD_STD   SetFuncAndParamNames,         DWORD, POINTER, DWORD
;  COM_MTD_STD   SetVarName,                   DWORD, POINTER
;  COM_MTD_STD   SetTypeDescAlias,             POINTER
;  COM_MTD_STD   DefineFuncAsDllEntry,         DWORD, POINTER
;  COM_MTD_STD   SetFuncDocString,             DWORD, POINTER
;  COM_MTD_STD   SetVarDocString,              DWORD, POINTER
;  COM_MTD_STD   SetFuncHelpContext,           DWORD, DWORD
;  COM_MTD_STD   SetVarHelpContext,            DWORD, DWORD
;  COM_MTD_STD   SetMops,                      DWORD, POINTER
;  COM_MTD_STD   SetTypeIdldesc,               POINTER
;  COM_MTD_STD   LayOut,
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ICreateTypeLib, IUnknown, <00020406-0000-0000-C000-000000000046>
;  COM_MTD_STD   CreateTypeInfo,               POINTER, POINTER
;  COM_MTD_STD   SetName,                      POINTER
;  COM_MTD_STD   SetVersion,                   DWORD, DWORD
;  COM_MTD_STD   SetGuid,                      POINTER
;  COM_MTD_STD   SetDocString,                 POINTER
;  COM_MTD_STD   SetHelpFileName,              POINTER
;  COM_MTD_STD   SetHelpContext,               DWORD
;  COM_MTD_STD   SetLcid,                      DWORD
;  COM_MTD_STD   SetLibFlags,                  DWORD
;  COM_MTD_STD   SaveAllChanges
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IDispatch, IUnknown, <00020400-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetTypeInfoCount,             POINTER
;  COM_MTD_STD   GetTypeInfo,                  DWORD, DWORD, POINTER
;  COM_MTD_STD   GetIDsOfNames,                POINTER, POINTER, DWORD, DWORD, POINTER
;  COM_MTD_STD   Invoke_,                      DWORD, POINTER, DWORD, WORD, POINTER, POINTER, POINTER, POINTER
;COM_INTERFACE_END
;
;;LPDISPATCH textequ <LPIDISPATCH>
;
;COM_INTERFACE_BEG ITypeInfo, IUnknown, <00020401-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetTypeAttr,                  POINTER
;  COM_MTD_STD   GetTypeComp,                  POINTER
;  COM_MTD_STD   GetFuncDesc,                  DWORD, POINTER
;  COM_MTD_STD   GetVarDesc,                   DWORD, POINTER
;  COM_MTD_STD   GetNames,                     DWORD, POINTER, DWORD, POINTER
;  COM_MTD_STD   GetRefTypeOfImplType,         DWORD, POINTER
;  COM_MTD_STD   GetImplTypeFlags,             DWORD, POINTER
;  COM_MTD_STD   GetIDsOfNames,                POINTER, DWORD, POINTER
;  COM_MTD_STD   TypeInfoInvoke,               POINTER, DWORD, WORD, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   GetDocumentation,             DWORD, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   GetDllEntry,                  DWORD, DWORD, POINTER, POINTER, POINTER
;  COM_MTD_STD   GetRefTypeInfo,               DWORD, POINTER
;  COM_MTD_STD   AddressOfMember,              DWORD, DWORD, POINTER
;  COM_MTD_STD   CreateInst,                   POINTER, POINTER, POINTER
;  COM_MTD_STD   GetMops,                      DWORD, POINTER
;  COM_MTD_STD   GetContainingTypeLib,         POINTER, POINTER
;  COM_MTD_STD   ReleaseTypeAttr,              POINTER
;  COM_MTD_STD   ReleaseFuncDesc,              POINTER
;  COM_MTD_STD   ReleaseVarDesc,               POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ITypeLib, IUnknown, <00020402-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetTypeInfoCount
;  COM_MTD_STD   GetTypeInfo,                  DWORD, POINTER
;  COM_MTD_STD   GetTypeInfoType,              DWORD, POINTER
;  COM_MTD_STD   GetTypeInfoOfGuid,            POINTER, POINTER
;  COM_MTD_STD   GetLibAttr,                   POINTER, POINTER
;  COM_MTD_STD   GetTypeComp,                  POINTER
;  COM_MTD_STD   GetDocumentation,             DWORD, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   IsName,                       POINTER, DWORD, POINTER, POINTER
;  COM_MTD_STD   FindName,                     POINTER, DWORD, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   LocalReleaseTLibAttr
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IEnumVARIANT, IUnknown, <00020404-0000-0000-C000-000000000046>
;  COM_MTD_STD   Next,                         DWORD, POINTER, POINTER
;  COM_MTD_STD   Skip,                         DWORD
;  COM_MTD_STD   Reset,
;  COM_MTD_STD   Clone,                        POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ISupportErrorInfo, IUnknown, <DF0B3D60-548F-101B-8E65-08002B2BD119>
;  COM_MTD_STD   InterfaceSupportsErrorInfo,   POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ICreateErrorInfo, IUnknown, <22F03340-547D-101B-8E65-08002B2BD119>
;  COM_MTD_STD   SetGUID,                      POINTER
;  COM_MTD_STD   SetSource,                    POINTER
;  COM_MTD_STD   SetDescription,               POINTER
;  COM_MTD_STD   SetHelpFile,                  POINTER
;  COM_MTD_STD   SetHelpContext,               DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IErrorInfo, IUnknown, <1CF2B120-547D-101B-8E65-08002B2BD119>
;  COM_MTD_STD   GetGUID,                      POINTER
;  COM_MTD_STD   GetSource,                    POINTER
;  COM_MTD_STD   GetDescription,               POINTER
;  COM_MTD_STD   GetHelpFile,                  POINTER
;  COM_MTD_STD   GetHelpContext,               POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IConnectionPointContainer, IUnknown, <B196B284-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   EnumConnectionPoints,         POINTER
;  COM_MTD_STD   FindConnectionPoint,          POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IEnumConnectionPoints, IUnknown, <B196B285-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   Next,                         DWORD, POINTER, POINTER
;  COM_MTD_STD   Skip,                         DWORD
;  COM_MTD_STD   Reset
;  COM_MTD_STD   Clone,                        POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IConnectionPoint, IUnknown, <B196B286-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   GetConnectionInterface,       POINTER
;  COM_MTD_STD   GetConnectionPointContainer,  POINTER
;  COM_MTD_STD   Advise,                       POINTER, POINTER
;  COM_MTD_STD   Unadvise,                     DWORD
;  COM_MTD_STD   EnumConnections,              POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IEnumConnections, IUnknown, <B196B287-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   Next,                         DWORD, POINTER, POINTER
;  COM_MTD_STD   Skip,                         DWORD
;  COM_MTD_STD   Reset
;  COM_MTD_STD   Clone,                        POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleObject, IUnknown, <00000112-0000-0000-C000-000000000046>
;  COM_MTD_STD   SetClientSite,                POINTER
;  COM_MTD_STD   GetClientSite,                POINTER
;  COM_MTD_STD   SetHostNames,                 POINTER, POINTER
;  COM_MTD_STD   Close,                        DWORD
;  COM_MTD_STD   SetMoniker,                   DWORD, POINTER
;  COM_MTD_STD   GetMoniker,                   DWORD, DWORD, POINTER
;  COM_MTD_STD   InitFromData,                 POINTER, POINTER, POINTER
;  COM_MTD_STD   GetClipboardData_,            DWORD, POINTER
;  COM_MTD_STD   DoVerb,                       DWORD, POINTER, POINTER, DWORD, HANDLE, POINTER
;  COM_MTD_STD   EnumVerbs,                    POINTER
;  COM_MTD_STD   Update
;  COM_MTD_STD   IsUpToDate
;  COM_MTD_STD   GetUserClassID,               POINTER
;  COM_MTD_STD   GetUserType,                  DWORD, POINTER
;  COM_MTD_STD   SetExtent,                    DWORD, POINTER
;  COM_MTD_STD   GetExtent,                    DWORD, POINTER
;  COM_MTD_STD   Advise,                       POINTER, POINTER
;  COM_MTD_STD   Unadvise,                     DWORD
;  COM_MTD_STD   EnumAdvise,                   POINTER
;  COM_MTD_STD   GetMiscStatus,                DWORD, POINTER
;  COM_MTD_STD   SetColorScheme,               POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleClientSite, IUnknown, <00000118-0000-0000-C000-000000000046>
;  COM_MTD_STD   SaveObject
;  COM_MTD_STD   GetMoniker,                   POINTER, POINTER, POINTER
;  COM_MTD_STD   GetContainer,                 POINTER
;  COM_MTD_STD   ShowObject
;  COM_MTD_STD   OnShowWindow,                 POINTER
;  COM_MTD_STD   RequestNewObjectLayout
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IAdviseSink, IUnknown, <0000010F-0000-0000-C000-000000000046>
;  COM_MTD_STD   OnDataChange,                 POINTER, POINTER
;  COM_MTD_STD   OnViewChange,                 DWORD, DWORD
;  COM_MTD_STD   OnRename,                     POINTER
;  COM_MTD_STD   OnSave
;  COM_MTD_STD   OnClose
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleAdviseHolder, IUnknown, <00000111-0000-0000-C000-000000000046>
;  COM_MTD_STD   Advise,                       POINTER, POINTER
;  COM_MTD_STD   Unadvise,                     POINTER
;  COM_MTD_STD   EnumAdvise,                   POINTER
;  COM_MTD_STD   SendOnRename,                 POINTER
;  COM_MTD_STD   SendOnSave
;  COM_MTD_STD   SendOnClose
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleControlSite, IUnknown, <B196B289-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   OnControlInfoChanged
;  COM_MTD_STD   LockInPlaceActive,            POINTER
;  COM_MTD_STD   GetExtendedControl,           POINTER
;  COM_MTD_STD   TransformCoords,              POINTER, POINTER, POINTER
;  COM_MTD_STD   TranslateAccel,               POINTER, POINTER
;  COM_MTD_STD   OnFocus,                      POINTER
;  COM_MTD_STD   ShowPropertyFrame
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleWindow, IUnknown, <00000114-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetWindow_,                   POINTER
;  COM_MTD_STD   ContextSensitiveHelp,         POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IProvideClassInfo, IUnknown, <B196B283-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   GetClassInfo_,                POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IProvideClassInfo2, IProvideClassInfo, <A6BC3AC0-DBAA-11CE-9DE3-00AA004BB851>
;  COM_MTD_STD   GetGUID,                      DWORD, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPersist, IUnknown, <0000010C-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetClassID,                   POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPersistStream, IPersist, <00000109-0000-0000-C000-000000000046>
;  COM_MTD_STD   IsDirty
;  COM_MTD_STD   Load,                         POINTER
;  COM_MTD_STD   Save,                         POINTER, POINTER
;  COM_MTD_STD   GetSizeMax,                   POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPersistStreamInit, IPersistStream, <7FD52380-4E07-101B-AE2D-08002B2EC713>
;  COM_MTD_STD   InitNew
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ISequentialStream, IUnknown, <0C733A30-2A1C-11CE-ADE5-00AA0044773D>
;  COM_MTD_STD   Read,                         POINTER, DWORD, POINTER
;  COM_MTD_STD   Write,                        POINTER, DWORD, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IStream, ISequentialStream, <0000000C-0000-0000-C000-000000000046>
;  COM_MTD_STD   Seek,                         SDWORD, DWORD, POINTER
;  COM_MTD_STD   SetSize,                      DWORD
;  COM_MTD_STD   CopyTo,                       POINTER, DWORD, POINTER, POINTER
;  COM_MTD_STD   Commit,                       DWORD
;  COM_MTD_STD   Revert
;  COM_MTD_STD   LockRegion,                   DWORD, DWORD, DWORD
;  COM_MTD_STD   UnlockRegion,                 DWORD, DWORD, DWORD
;  COM_MTD_STD   Stat,                         POINTER, DWORD
;  COM_MTD_STD   Clone,                        POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IViewObject, IUnknown, <0000010D-0000-0000-C000-000000000046>
;  COM_MTD_STD   Draw,                         POINTER, POINTER, POINTER, POINTER, POINTER, POINTER, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   GetColorSet,                  POINTER, POINTER, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   Freeze,                       POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   Unfreeze,                     POINTER
;  COM_MTD_STD   SetAdvise,                    POINTER, POINTER, POINTER
;  COM_MTD_STD   GetAdvise,                    POINTER, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IViewObject2, IViewObject, <00000127-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetExtent,                    DWORD, DWORD, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ISpecifyPropertyPages, IUnknown, <B196B28B-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   GetPages,                     POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPersistPropertyBag, IPersist, <37D84F60-42CB-11CE-8135-00AA004BB851>
;  COM_MTD_STD   InitNew
;  COM_MTD_STD   Load,                         POINTER, POINTER
;  COM_MTD_STD   Save,                         POINTER, POINTER, DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPropertyBag, IUnknown, <55272A00-42CB-11CE-8135-00AA004BB851>
;  COM_MTD_STD   Read,                         POINTER, POINTER, POINTER
;  COM_MTD_STD   Write,                        POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG ICategorizeProperties, IUnknown, <4D07FC10-F931-11CE-B001-00AA006884E5>
;  COM_MTD_STD   MapPropertyToCategory,        POINTER, POINTER
;  COM_MTD_STD   GetCategoryName,              POINTER, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IMalloc, IUnknown, <00000002-0000-0000-C000-000000000046>
;  COM_MTD_STD   Alloc_,                       DWORD
;  COM_MTD_STD   Realloc,                      POINTER, DWORD
;  COM_MTD_STD   Free_,                        POINTER
;  COM_MTD_STD   GetSize,                      POINTER
;  COM_MTD_STD   DidAlloc,                     POINTER
;  COM_MTD_STD   HeapMinimize
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IFont, IUnknown, <BEF6E002-A874-101A-8BBA-00AA00300CAB>
;  COM_MTD_STD   get_Name,                     POINTER
;  COM_MTD_STD   put_Name,                     POINTER
;  COM_MTD_STD   get_Size,                     POINTER
;  COM_MTD_STD   put_Size,                     QWORD
;  COM_MTD_STD   get_Bold,                     POINTER
;  COM_MTD_STD   put_Bold,                     DWORD
;  COM_MTD_STD   get_Italic,                   POINTER
;  COM_MTD_STD   put_Italic,                   DWORD
;  COM_MTD_STD   get_Underline,                POINTER
;  COM_MTD_STD   put_Underline,                DWORD
;  COM_MTD_STD   get_Strikethrough,            POINTER
;  COM_MTD_STD   put_Strikethrough,            DWORD
;  COM_MTD_STD   get_Weight,                   POINTER
;  COM_MTD_STD   put_Weight,                   DWORD
;  COM_MTD_STD   get_Charset,                  POINTER
;  COM_MTD_STD   put_Charset,                  DWORD
;  COM_MTD_STD   get_hFont,                    POINTER
;  COM_MTD_STD   Clone,                        POINTER
;  COM_MTD_STD   IsEqual,                      POINTER
;  COM_MTD_STD   SetRatio,                     DWORD, DWORD
;  COM_MTD_STD   QueryTextMetrics,             POINTER
;  COM_MTD_STD   AddRefHfont,                  HANDLE
;  COM_MTD_STD   ReleaseHfont,                 HANDLE
;  COM_MTD_STD   SetHdc,                       HANDLE
;COM_INTERFACE_END
;
;;COM_INTERFACE_BEG IShellFolder, IUnknown, <000214E6-0000-0000-C000-000000000046>
;;  COM_MTD_STD   ParseDisplayName,             HANDLE, POINTER, POINTER, POINTER, POINTER, POINTER
;;  COM_MTD_STD   EnumObjects,                  HANDLE, DWORD, POINTER
;;  COM_MTD_STD   BindToObject,                 POINTER, POINTER, POINTER, POINTER
;;  COM_MTD_STD   BindToStorage,                POINTER, POINTER, POINTER, POINTER
;;  COM_MTD_STD   CompareIDs,                   DWORD, POINTER, POINTER
;;  COM_MTD_STD   CreateViewObject,             HANDLE, POINTER, POINTER
;;  COM_MTD_STD   GetAttributesOf,              DWORD, POINTER, POINTER
;;  COM_MTD_STD   GetUIObjectOf,                HANDLE, DWORD, POINTER, POINTER, POINTER, POINTER
;;  COM_MTD_STD   GetDisplayNameOf,             POINTER, DWORD, POINTER
;;  COM_MTD_STD   SetNameOf,                    HANDLE, POINTER, POINTER, DWORD, POINTER
;;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IShellLink, IUnknown
;  COM_MTD_STD   GetPath,                      POINTER, DWORD, POINTER, DWORD
;  COM_MTD_STD   GetIDList,                    POINTER
;  COM_MTD_STD   SetIDList,                    POINTER
;  COM_MTD_STD   GetDescription,               POINTER, DWORD
;  COM_MTD_STD   SetDescription,               POINTER
;  COM_MTD_STD   GetWorkingDirectory,          POINTER, DWORD
;  COM_MTD_STD   SetWorkingDirectory,          POINTER
;  COM_MTD_STD   GetArguments,                 POINTER, DWORD
;  COM_MTD_STD   SetArguments,                 POINTER
;  COM_MTD_STD   GetHotkey,                    POINTER
;  COM_MTD_STD   SetHotkey,                    DWORD
;  COM_MTD_STD   GetShowCmd,                   POINTER
;  COM_MTD_STD   SetShowCmd,                   DWORD
;  COM_MTD_STD   GetIconLocation,              POINTER, DWORD, POINTER
;  COM_MTD_STD   SetIconLocation,              POINTER, DWORD
;  COM_MTD_STD   SetRelativePath,              POINTER, DWORD
;  COM_MTD_STD   Resolve,                      HANDLE, DWORD
;  COM_MTD_STD   SetPath,                      POINTER
;COM_INTERFACE_END
;
;sIID_IShellLinkA equ <000214EE-0000-0000-C000-000000000046>
;sIID_IShellLinkW equ <000214F9-0000-0000-C000-000000000046>
;IFDEF __UNICODE__
;  sIID_IShellLink equ   <sIID_IShellLinkW>
;ELSE
;  sIID_IShellLink equ   <sIID_IShellLinkA>
;ENDIF
;
;COM_INTERFACE_BEG IPersistFile, IPersist, <0000010B-0000-0000-C000-000000000046>
;  COM_MTD_STD   IsDirty
;  COM_MTD_STD   Load,                         POINTER, DWORD
;  COM_MTD_STD   Save,                         POINTER, POINTER
;  COM_MTD_STD   SaveCompleted,                POINTER
;  COM_MTD_STD   GetCurFile,                   POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IDropSource, IUnknown, <00000121-0000-0000-C000-000000000046>
;  COM_MTD_STD   QueryContinueDrag,            DWORD, DWORD
;  COM_MTD_STD   GiveFeedback,                 DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IDropTarget, IUnknown, <00000122-0000-0000-C000-000000000046>
;  COM_MTD_STD   DragEnter,                    POINTER, DWORD, POINTL, POINTER
;  COM_MTD_STD   DragOver,                     DWORD, POINTL, DWORD
;  COM_MTD_STD   DragLeave
;  COM_MTD_STD   Drop,                         POINTER, DWORD, POINTL, DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IDataObject, IUnknown, <0000010E-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetData,                      POINTER, POINTER
;  COM_MTD_STD   GetDataHere,                  POINTER, POINTER
;  COM_MTD_STD   QueryGetData,                 POINTER
;  COM_MTD_STD   GetCanonicalFormatEtc,        POINTER, POINTER
;  COM_MTD_STD   SetData,                      POINTER, POINTER, DWORD
;  COM_MTD_STD   EnumFormatEtc,                DWORD, POINTER
;  COM_MTD_STD   DAdvise,                      POINTER, DWORD, POINTER, POINTER
;  COM_MTD_STD   DUnadvise,                    DWORD
;  COM_MTD_STD   EnumDAdvise,                  POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPicture, IUnknown, <7BF80980-BF32-101A-8BBB-00AA00300CAB>
;  COM_MTD_STD   get_Handle,                   POINTER
;  COM_MTD_STD   get_hPal,                     POINTER
;  COM_MTD_STD   get_Type,                     POINTER
;  COM_MTD_STD   get_Width,                    POINTER
;  COM_MTD_STD   get_Height,                   POINTER
;  COM_MTD_STD   Render,                       HANDLE, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, POINTER
;  COM_MTD_STD   set_hPal,                     HANDLE
;  COM_MTD_STD   get_CurDC,                    POINTER
;  COM_MTD_STD   SelectPicture,                HANDLE, POINTER, POINTER
;  COM_MTD_STD   get_KeepOriginalFormat,       POINTER
;  COM_MTD_STD   put_KeepOriginalFormat,       DWORD
;  COM_MTD_STD   PictureChanged
;  COM_MTD_STD   SaveAsFile,                   POINTER, DWORD, POINTER
;  COM_MTD_STD   get_Attributes,               POINTER
;COM_INTERFACE_END
;
;sCLSID_TaskbarList textequ <56FDF344-FD6D-11D0-958A-006097C9A090>
;
;COM_INTERFACE_BEG ITaskbarList, IUnknown, <56FDF342-FD6D-11D0-958A-006097C9A090>
;  COM_MTD_STD   HrInit
;  COM_MTD_STD   AddTab,                       HANDLE
;  COM_MTD_STD   DeleteTab,                    HANDLE
;  COM_MTD_STD   ActivateTab,                  HANDLE
;  COM_MTD_STD   SetActiveAlt,                 HANDLE
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IBindStatusCallback, IUnknown, <79EAC9C1-BAF9-11CE-8C82-00AA004BA90B>
;  COM_MTD_STD   OnStartBinding,               DWORD, POINTER
;  COM_MTD_STD   GetPriority,                  POINTER
;  COM_MTD_STD   OnLowResource,                DWORD
;  COM_MTD_STD   OnProgress,                   DWORD, DWORD, DWORD, POINTER
;  COM_MTD_STD   OnStopBinding,                HRESULT, POINTER
;  COM_MTD_STD   GetBindInfo,                  POINTER, POINTER
;  COM_MTD_STD   OnDataAvailable,              DWORD, DWORD, POINTER, POINTER
;  COM_MTD_STD   OnObjectAvailable,            POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPropertyPage, IUnknown, <B196B28D-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   SetPageSite,                  POINTER
;  COM_MTD_STD   Activate,                     HANDLE, POINTER, BOOL
;  COM_MTD_STD   Deactivate
;  COM_MTD_STD   GetPageInfo,                  POINTER
;  COM_MTD_STD   SetObjects,                   DWORD, POINTER
;  COM_MTD_STD   Show,                         DWORD
;  COM_MTD_STD   Move,                         POINTER
;  COM_MTD_STD   IsPageDirty
;  COM_MTD_STD   Apply
;  COM_MTD_STD   Help,                         POINTER
;  COM_MTD_STD   TranslateAccel,               POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPropertyPage2, IPropertyPage, <01E44665-24AC-101B-84ED-08002B2EC713>
;  COM_MTD_STD   EditProperty,                 DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPropertyPageSite, IUnknown, <B196B28C-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   OnStatusChange,               DWORD
;  COM_MTD_STD   GetLocaleID,                  POINTER
;  COM_MTD_STD   GetPageContainer,             POINTER
;  COM_MTD_STD   TranslateAccel,               POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPropertyNotifySink, IUnknown, <9BFBBC02-EFF1-101A-84ED-00AA00341D07>
;  COM_MTD_STD   OnChanged,                    DWORD
;  COM_MTD_STD   OnRequestEdit,                DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPerPropertyBrowsing, IUnknown, <376BD3AA-3845-101B-84ED-08002B2EC713>
;  COM_MTD_STD   GetDisplayString,             DWORD, POINTER
;  COM_MTD_STD   MapPropertyToPage,            DWORD, POINTER
;  COM_MTD_STD   GetPredefinedStrings,         DWORD, POINTER, POINTER
;  COM_MTD_STD   GetPredefinedValue,           DWORD, DWORD, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IPersistStorage, IPersist, <0000010A-0000-0000-C000-000000000046>
;  COM_MTD_STD   IsDirty
;  COM_MTD_STD   InitNew,                      POINTER
;  COM_MTD_STD   Load,                         POINTER
;  COM_MTD_STD   Save,                         POINTER, DWORD
;  COM_MTD_STD   SaveCompleted,                POINTER
;  COM_MTD_STD   HandsOffStorage
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IQuickActivate, IUnknown, <CF51ED10-62FE-11CF-BF86-00A0C9034836>
;  COM_MTD_STD   QuickActivate,                POINTER, POINTER
;  COM_MTD_STD   SetContentExtent,             POINTER
;  COM_MTD_STD   GetContentExtent,             POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceObject, IOleWindow, <00000113-0000-0000-C000-000000000046>
;  COM_MTD_STD   InPlaceDeactivate
;  COM_MTD_STD   UIDeactivate
;  COM_MTD_STD   SetObjectRects,               POINTER, POINTER
;  COM_MTD_STD   ReactivateAndUndo
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceSite, IOleWindow, <00000119-0000-0000-C000-000000000046>
;  COM_MTD_STD   CanInPlaceActivate
;  COM_MTD_STD   OnInPlaceActivate
;  COM_MTD_STD   OnUIActivate
;  COM_MTD_STD   GetWindowContext,             POINTER, POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   Scroll,                       DWORD
;  COM_MTD_STD   OnUIDeactivate,               BOOL
;  COM_MTD_STD   OnInPlaceDeactivate
;  COM_MTD_STD   DiscardUndoState
;  COM_MTD_STD   DeactivateAndUndo
;  COM_MTD_STD   OnPosRectChange,              POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceSiteEx, IOleInPlaceSite, <9C2CAD80-3424-11CF-B670-00AA004CD6D8>
;  COM_MTD_STD   OnInPlaceActivateEx,          POINTER, DWORD
;  COM_MTD_STD   OnInPlaceDeactivateEx,        BOOL
;  COM_MTD_STD   RequestUIActivate
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceUIWindow, IOleWindow, <00000115-0000-0000-C000-000000000046>
;  COM_MTD_STD   GetBorder,                    POINTER
;  COM_MTD_STD   RequestBorderSpace,           POINTER
;  COM_MTD_STD   SetBorderSpace,               POINTER
;  COM_MTD_STD   SetActiveObject,              POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceFrame, IOleInPlaceUIWindow, <00000116-0000-0000-C000-000000000046>
;  COM_MTD_STD   InsertMenus,                  HANDLE, POINTER
;  COM_MTD_STD   SetMenu,                      HANDLE, HANDLE, HANDLE
;  COM_MTD_STD   RemoveMenus,                  HANDLE
;  COM_MTD_STD   SetStatusText,                POINTER
;  COM_MTD_STD   EnableModeless,               BOOL
;  COM_MTD_STD   TranslateAccel,               POINTER, WORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IParseDisplayName, IUnknown, <0000011A-0000-0000-C000-000000000046>
;  COM_MTD_STD   ParseDisplayName,             POINTER, POINTER, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleContainer, IParseDisplayName, <0000011B-0000-0000-C000-000000000046>
;  COM_MTD_STD   EnumObjects,                  DWORD, POINTER
;  COM_MTD_STD   LockContainer,                BOOL
;COM_INTERFACE_END
; 
;COM_INTERFACE_BEG ISimpleFrameSite, IUnknown, <742B0E01-14E6-101B-914E-00AA00300CAB>
;  COM_MTD_STD   PreMessageFilter,             HANDLE, DWORD, WPARAM, LPARAM, POINTER, POINTER
;  COM_MTD_STD   PostMessageFilter,            HANDLE, DWORD, WPARAM, LPARAM, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleControl, IUnknown, <B196B288-BAB4-101A-B69C-00AA00341D07>
;  COM_MTD_STD   GetControlInfo,               POINTER
;  COM_MTD_STD   OnMnemonic,                   POINTER
;  COM_MTD_STD   OnAmbientPropertyChange,      WORD
;  COM_MTD_STD   FreezeEvents,                 BOOL
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceActiveObject, IOleWindow, <00000117-0000-0000-C000-000000000046>
;  COM_MTD_STD   TranslateAccelerator,         POINTER
;  COM_MTD_STD   OnFrameWindowActivate,        BOOL
;  COM_MTD_STD   OnDocWindowActivate,          BOOL
;  COM_MTD_STD   ResizeBorder,                 POINTER, POINTER, BOOL
;  COM_MTD_STD   EnableModeless,               BOOL
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IServiceProvider, IUnknown, <6D5140C1-7436-11CE-8034-00AA006009FA>
;  COM_MTD_STD   QueryService,                 REFGUID, REFIID, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IStorage, IUnknown, <0000000B-0000-0000-C000-000000000046>
;  COM_MTD_STD   CreateStream,                 POINTER, DWORD, DWORD, DWORD, POINTER
;  COM_MTD_STD   OpenStream,                   POINTER, DWORD, DWORD, DWORD, POINTER
;  COM_MTD_STD   CreateStorage,                POINTER, DWORD, DWORD, DWORD, POINTER
;  COM_MTD_STD   OpenStorage,                  POINTER, POINTER, DWORD, DWORD, DWORD, POINTER
;  COM_MTD_STD   CopyTo,                       DWORD, POINTER, POINTER, POINTER
;  COM_MTD_STD   MoveElementTo,                POINTER, POINTER, POINTER, DWORD
;  COM_MTD_STD   Commit,                       DWORD
;  COM_MTD_STD   Revert
;  COM_MTD_STD   EnumElements,                 DWORD, POINTER, DWORD, POINTER
;  COM_MTD_STD   DestroyElement,               POINTER
;  COM_MTD_STD   RenameElement,                POINTER, POINTER
;  COM_MTD_STD   SetElementTimes,              POINTER, POINTER, POINTER, POINTER
;  COM_MTD_STD   SetClass,                     REFGUID
;  COM_MTD_STD   SetStateBits,                 DWORD, DWORD
;  COM_MTD_STD   Stat,                         POINTER, DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleInPlaceSiteWindowless, IOleInPlaceSiteEx, <922EADA0-3424-11CF-B670-00AA004CD6D8>
;  COM_MTD_STD   CanWindowlessActivate
;  COM_MTD_STD   GetCapture
;  COM_MTD_STD   SetCapture,                   BOOL
;  COM_MTD_STD   GetFocus
;  COM_MTD_STD   SetFocus,                     BOOL
;  COM_MTD_STD   GetDC,                        POINTER, DWORD, POINTER
;  COM_MTD_STD   ReleaseDC,                    HANDLE
;  COM_MTD_STD   InvalidateRect,               POINTER, BOOL
;  COM_MTD_STD   InvalidateRgn,                HANDLE, BOOL
;  COM_MTD_STD   ScrollRect,                   SDWORD, SDWORD, POINTER, POINTER
;  COM_MTD_STD   AdjustRect,                   POINTER
;  COM_MTD_STD   OnDefWindowMessage,           DWORD, WPARAM, LPARAM, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleCommandTarget, IUnknown, <B722BCCB-4E68-101B-A2BC-00AA00404770>
;  COM_MTD_STD   QueryStatus,                  POINTER, DWORD, POINTER, POINTER
;  COM_MTD_STD   Exec,                         POINTER, DWORD, DWORD, POINTER, POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleDocumentSite, IUnknown, <B722BCC7-4E68-101B-A2BC-00AA00404770>
;  COM_MTD_STD   ActivateMe,                   POINTER
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleDocument, IUnknown, <B722BCC5-4E68-101B-A2BC-00AA00404770>
;  COM_MTD_STD   CreateView,                   POINTER, POINTER, DWORD, POINTER
;  COM_MTD_STD   EnumViews,                    POINTER, POINTER
;  COM_MTD_STD   GetDocMiscStatus,             DWORD
;COM_INTERFACE_END
;
;COM_INTERFACE_BEG IOleDocumentView, IUnknown, <B722BCC6-4E68-101B-A2BC-00AA00404770>
;  COM_MTD_STD   ApplyViewState,               POINTER
;  COM_MTD_STD   Clone,                        POINTER, POINTER
;  COM_MTD_STD   CloseView,                    DWORD
;  COM_MTD_STD   GetDocument,                  POINTER
;  COM_MTD_STD   GetInPlaceSite,               POINTER
;  COM_MTD_STD   GetRect,                      POINTER
;  COM_MTD_STD   Open
;  COM_MTD_STD   SaveViewState,                POINTER
;  COM_MTD_STD   SetInPlaceSite,               POINTER
;  COM_MTD_STD   SetRect,                      POINTER
;  COM_MTD_STD   SetRectComplex,               POINTER, POINTER, POINTER, POINTER            
;  COM_MTD_STD   Show,                         BOOL
;  COM_MTD_STD   UIActivate,                   BOOL
;COM_INTERFACE_END
