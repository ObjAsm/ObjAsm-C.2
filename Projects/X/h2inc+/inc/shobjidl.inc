;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shobjidl.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:24:30

;* verify that the <rpcndr.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
;* verify that the <rpcsal.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
  ;* __RPCNDR_H_VERSION__ *
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
  ;*COM_NO_WINDOWS_H*
endif
ifndef __shobjidl_h__
  __shobjidl_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if Defined(_CONTROL_FLOW_GUARD_XFG)
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  ;* Forward Declarations *
  ifndef __IQueryCodePage_FWD_DEFINED__
    __IQueryCodePage_FWD_DEFINED__ equ <>
    ;* __IQueryCodePage_FWD_DEFINED__ *
  endif
  ifndef __IFolderViewOptions_FWD_DEFINED__
    __IFolderViewOptions_FWD_DEFINED__ equ <>
    ;* __IFolderViewOptions_FWD_DEFINED__ *
  endif
  ifndef __IShellView3_FWD_DEFINED__
    __IShellView3_FWD_DEFINED__ equ <>
    ;* __IShellView3_FWD_DEFINED__ *
  endif
  ifndef __ISearchBoxInfo_FWD_DEFINED__
    __ISearchBoxInfo_FWD_DEFINED__ equ <>
    ;* __ISearchBoxInfo_FWD_DEFINED__ *
  endif
  ifndef __IVisualProperties_FWD_DEFINED__
    __IVisualProperties_FWD_DEFINED__ equ <>
    ;* __IVisualProperties_FWD_DEFINED__ *
  endif
  ifndef __ICommDlgBrowser3_FWD_DEFINED__
    __ICommDlgBrowser3_FWD_DEFINED__ equ <>
    ;* __ICommDlgBrowser3_FWD_DEFINED__ *
  endif
  ifndef __IUserAccountChangeCallback_FWD_DEFINED__
    __IUserAccountChangeCallback_FWD_DEFINED__ equ <>
    ;* __IUserAccountChangeCallback_FWD_DEFINED__ *
  endif
  ifndef __IStreamAsync_FWD_DEFINED__
    __IStreamAsync_FWD_DEFINED__ equ <>
    ;* __IStreamAsync_FWD_DEFINED__ *
  endif
  ifndef __IStreamUnbufferedInfo_FWD_DEFINED__
    __IStreamUnbufferedInfo_FWD_DEFINED__ equ <>
    ;* __IStreamUnbufferedInfo_FWD_DEFINED__ *
  endif
  ifndef __IDragSourceHelper2_FWD_DEFINED__
    __IDragSourceHelper2_FWD_DEFINED__ equ <>
    ;* __IDragSourceHelper2_FWD_DEFINED__ *
  endif
  ifndef __IHWEventHandler_FWD_DEFINED__
    __IHWEventHandler_FWD_DEFINED__ equ <>
    ;* __IHWEventHandler_FWD_DEFINED__ *
  endif
  ifndef __IHWEventHandler2_FWD_DEFINED__
    __IHWEventHandler2_FWD_DEFINED__ equ <>
    ;* __IHWEventHandler2_FWD_DEFINED__ *
  endif
  ifndef __IQueryCancelAutoPlay_FWD_DEFINED__
    __IQueryCancelAutoPlay_FWD_DEFINED__ equ <>
    ;* __IQueryCancelAutoPlay_FWD_DEFINED__ *
  endif
  ifndef __IDynamicHWHandler_FWD_DEFINED__
    __IDynamicHWHandler_FWD_DEFINED__ equ <>
    ;* __IDynamicHWHandler_FWD_DEFINED__ *
  endif
  ifndef __IUserNotificationCallback_FWD_DEFINED__
    __IUserNotificationCallback_FWD_DEFINED__ equ <>
    ;* __IUserNotificationCallback_FWD_DEFINED__ *
  endif
  ifndef __IUserNotification2_FWD_DEFINED__
    __IUserNotification2_FWD_DEFINED__ equ <>
    ;* __IUserNotification2_FWD_DEFINED__ *
  endif
  ifndef __IDeskBand2_FWD_DEFINED__
    __IDeskBand2_FWD_DEFINED__ equ <>
    ;* __IDeskBand2_FWD_DEFINED__ *
  endif
  ifndef __IStartMenuPinnedList_FWD_DEFINED__
    __IStartMenuPinnedList_FWD_DEFINED__ equ <>
    ;* __IStartMenuPinnedList_FWD_DEFINED__ *
  endif
  ifndef __ICDBurn_FWD_DEFINED__
    __ICDBurn_FWD_DEFINED__ equ <>
    ;* __ICDBurn_FWD_DEFINED__ *
  endif
  ifndef __IWizardSite_FWD_DEFINED__
    __IWizardSite_FWD_DEFINED__ equ <>
    ;* __IWizardSite_FWD_DEFINED__ *
  endif
  ifndef __IWizardExtension_FWD_DEFINED__
    __IWizardExtension_FWD_DEFINED__ equ <>
    ;* __IWizardExtension_FWD_DEFINED__ *
  endif
  ifndef __IWebWizardExtension_FWD_DEFINED__
    __IWebWizardExtension_FWD_DEFINED__ equ <>
    ;* __IWebWizardExtension_FWD_DEFINED__ *
  endif
  ifndef __IPublishingWizard_FWD_DEFINED__
    __IPublishingWizard_FWD_DEFINED__ equ <>
    ;* __IPublishingWizard_FWD_DEFINED__ *
  endif
  ifndef __IFolderViewHost_FWD_DEFINED__
    __IFolderViewHost_FWD_DEFINED__ equ <>
    ;* __IFolderViewHost_FWD_DEFINED__ *
  endif
  ifndef __IAccessibleObject_FWD_DEFINED__
    __IAccessibleObject_FWD_DEFINED__ equ <>
    ;* __IAccessibleObject_FWD_DEFINED__ *
  endif
  ifndef __IResultsFolder_FWD_DEFINED__
    __IResultsFolder_FWD_DEFINED__ equ <>
    ;* __IResultsFolder_FWD_DEFINED__ *
  endif
  ifndef __IAutoCompleteDropDown_FWD_DEFINED__
    __IAutoCompleteDropDown_FWD_DEFINED__ equ <>
    ;* __IAutoCompleteDropDown_FWD_DEFINED__ *
  endif
  ifndef __ICDBurnExt_FWD_DEFINED__
    __ICDBurnExt_FWD_DEFINED__ equ <>
    ;* __ICDBurnExt_FWD_DEFINED__ *
  endif
  ifndef __IEnumReadyCallback_FWD_DEFINED__
    __IEnumReadyCallback_FWD_DEFINED__ equ <>
    ;* __IEnumReadyCallback_FWD_DEFINED__ *
  endif
  ifndef __IEnumerableView_FWD_DEFINED__
    __IEnumerableView_FWD_DEFINED__ equ <>
    ;* __IEnumerableView_FWD_DEFINED__ *
  endif
  ifndef __IInsertItem_FWD_DEFINED__
    __IInsertItem_FWD_DEFINED__ equ <>
    ;* __IInsertItem_FWD_DEFINED__ *
  endif
  ifndef __IFolderBandPriv_FWD_DEFINED__
    __IFolderBandPriv_FWD_DEFINED__ equ <>
    ;* __IFolderBandPriv_FWD_DEFINED__ *
  endif
  ifndef __IImageRecompress_FWD_DEFINED__
    __IImageRecompress_FWD_DEFINED__ equ <>
    ;* __IImageRecompress_FWD_DEFINED__ *
  endif
  ifndef __IFileDialogControlEvents_FWD_DEFINED__
    __IFileDialogControlEvents_FWD_DEFINED__ equ <>
    ;* __IFileDialogControlEvents_FWD_DEFINED__ *
  endif
  ifndef __IFileDialog2_FWD_DEFINED__
    __IFileDialog2_FWD_DEFINED__ equ <>
    ;* __IFileDialog2_FWD_DEFINED__ *
  endif
  ifndef __IApplicationAssociationRegistrationUI_FWD_DEFINED__
    __IApplicationAssociationRegistrationUI_FWD_DEFINED__ equ <>
    ;* __IApplicationAssociationRegistrationUI_FWD_DEFINED__ *
  endif
  ifndef __IShellRunDll_FWD_DEFINED__
    __IShellRunDll_FWD_DEFINED__ equ <>
    ;* __IShellRunDll_FWD_DEFINED__ *
  endif
  ifndef __IPreviousVersionsInfo_FWD_DEFINED__
    __IPreviousVersionsInfo_FWD_DEFINED__ equ <>
    ;* __IPreviousVersionsInfo_FWD_DEFINED__ *
  endif
  ifndef __IUseToBrowseItem_FWD_DEFINED__
    __IUseToBrowseItem_FWD_DEFINED__ equ <>
    ;* __IUseToBrowseItem_FWD_DEFINED__ *
  endif
  ifndef __INameSpaceTreeControl2_FWD_DEFINED__
    __INameSpaceTreeControl2_FWD_DEFINED__ equ <>
    ;* __INameSpaceTreeControl2_FWD_DEFINED__ *
  endif
  ifndef __INameSpaceTreeControlEvents_FWD_DEFINED__
    __INameSpaceTreeControlEvents_FWD_DEFINED__ equ <>
    ;* __INameSpaceTreeControlEvents_FWD_DEFINED__ *
  endif
  ifndef __INameSpaceTreeControlDropHandler_FWD_DEFINED__
    __INameSpaceTreeControlDropHandler_FWD_DEFINED__ equ <>
    ;* __INameSpaceTreeControlDropHandler_FWD_DEFINED__ *
  endif
  ifndef __INameSpaceTreeAccessible_FWD_DEFINED__
    __INameSpaceTreeAccessible_FWD_DEFINED__ equ <>
    ;* __INameSpaceTreeAccessible_FWD_DEFINED__ *
  endif
  ifndef __INameSpaceTreeControlCustomDraw_FWD_DEFINED__
    __INameSpaceTreeControlCustomDraw_FWD_DEFINED__ equ <>
    ;* __INameSpaceTreeControlCustomDraw_FWD_DEFINED__ *
  endif
  ifndef __ITrayDeskBand_FWD_DEFINED__
    __ITrayDeskBand_FWD_DEFINED__ equ <>
    ;* __ITrayDeskBand_FWD_DEFINED__ *
  endif
  ifndef __IBandHost_FWD_DEFINED__
    __IBandHost_FWD_DEFINED__ equ <>
    ;* __IBandHost_FWD_DEFINED__ *
  endif
  ifndef __IMarkupCallback_FWD_DEFINED__
    __IMarkupCallback_FWD_DEFINED__ equ <>
    ;* __IMarkupCallback_FWD_DEFINED__ *
  endif
  ifndef __IControlMarkup_FWD_DEFINED__
    __IControlMarkup_FWD_DEFINED__ equ <>
    ;* __IControlMarkup_FWD_DEFINED__ *
  endif
  ifndef __IComputerInfoChangeNotify_FWD_DEFINED__
    __IComputerInfoChangeNotify_FWD_DEFINED__ equ <>
    ;* __IComputerInfoChangeNotify_FWD_DEFINED__ *
  endif
  ifndef __IDesktopGadget_FWD_DEFINED__
    __IDesktopGadget_FWD_DEFINED__ equ <>
    ;* __IDesktopGadget_FWD_DEFINED__ *
  endif
  ifndef __QueryCancelAutoPlay_FWD_DEFINED__
    __QueryCancelAutoPlay_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __QueryCancelAutoPlay_FWD_DEFINED__ *
  endif
  ifndef __TimeCategorizer_FWD_DEFINED__
    __TimeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __TimeCategorizer_FWD_DEFINED__ *
  endif
  ifndef __AlphabeticalCategorizer_FWD_DEFINED__
    __AlphabeticalCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __AlphabeticalCategorizer_FWD_DEFINED__ *
  endif
  ifndef __MergedCategorizer_FWD_DEFINED__
    __MergedCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __MergedCategorizer_FWD_DEFINED__ *
  endif
  ifndef __ImageProperties_FWD_DEFINED__
    __ImageProperties_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ImageProperties_FWD_DEFINED__ *
  endif
  ifndef __CDBurn_FWD_DEFINED__
    __CDBurn_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __CDBurn_FWD_DEFINED__ *
  endif
  ifndef __StartMenuPin_FWD_DEFINED__
    __StartMenuPin_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __StartMenuPin_FWD_DEFINED__ *
  endif
  ifndef __WebWizardHost_FWD_DEFINED__
    __WebWizardHost_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __WebWizardHost_FWD_DEFINED__ *
  endif
  ifndef __PublishDropTarget_FWD_DEFINED__
    __PublishDropTarget_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __PublishDropTarget_FWD_DEFINED__ *
  endif
  ifndef __PublishingWizard_FWD_DEFINED__
    __PublishingWizard_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __PublishingWizard_FWD_DEFINED__ *
  endif
  ifndef __InternetPrintOrdering_FWD_DEFINED__
    __InternetPrintOrdering_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __InternetPrintOrdering_FWD_DEFINED__ *
  endif
  ifndef __FolderViewHost_FWD_DEFINED__
    __FolderViewHost_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __FolderViewHost_FWD_DEFINED__ *
  endif
  ifndef __ExplorerBrowser_FWD_DEFINED__
    __ExplorerBrowser_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ExplorerBrowser_FWD_DEFINED__ *
  endif
  ifndef __ImageRecompress_FWD_DEFINED__
    __ImageRecompress_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ImageRecompress_FWD_DEFINED__ *
  endif
  ifndef __TrayBandSiteService_FWD_DEFINED__
    __TrayBandSiteService_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __TrayBandSiteService_FWD_DEFINED__ *
  endif
  ifndef __TrayDeskBand_FWD_DEFINED__
    __TrayDeskBand_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __TrayDeskBand_FWD_DEFINED__ *
  endif
  ifndef __AttachmentServices_FWD_DEFINED__
    __AttachmentServices_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __AttachmentServices_FWD_DEFINED__ *
  endif
  ifndef __DocPropShellExtension_FWD_DEFINED__
    __DocPropShellExtension_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __DocPropShellExtension_FWD_DEFINED__ *
  endif
  ifndef __FSCopyHandler_FWD_DEFINED__
    __FSCopyHandler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __FSCopyHandler_FWD_DEFINED__ *
  endif
  ifndef __PreviousVersions_FWD_DEFINED__
    __PreviousVersions_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __PreviousVersions_FWD_DEFINED__ *
  endif
  ifndef __NamespaceTreeControl_FWD_DEFINED__
    __NamespaceTreeControl_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __NamespaceTreeControl_FWD_DEFINED__ *
  endif
  ifndef __IENamespaceTreeControl_FWD_DEFINED__
    __IENamespaceTreeControl_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __IENamespaceTreeControl_FWD_DEFINED__ *
  endif
  ifndef __ApplicationAssociationRegistrationUI_FWD_DEFINED__
    __ApplicationAssociationRegistrationUI_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ApplicationAssociationRegistrationUI_FWD_DEFINED__ *
  endif
  ifndef __DesktopGadget_FWD_DEFINED__
    __DesktopGadget_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __DesktopGadget_FWD_DEFINED__ *
  endif
  ifndef __AccessibilityDockingService_FWD_DEFINED__
    __AccessibilityDockingService_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __AccessibilityDockingService_FWD_DEFINED__ *
  endif
  ifndef __ExecuteFolder_FWD_DEFINED__
    __ExecuteFolder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ExecuteFolder_FWD_DEFINED__ *
  endif
  ifndef __VirtualDesktopManager_FWD_DEFINED__
    __VirtualDesktopManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __VirtualDesktopManager_FWD_DEFINED__ *
  endif
  ifndef __StorageProviderBanners_FWD_DEFINED__
    __StorageProviderBanners_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __StorageProviderBanners_FWD_DEFINED__ *
  endif
  ifndef __IAccessibilityDockingServiceCallback_FWD_DEFINED__
    __IAccessibilityDockingServiceCallback_FWD_DEFINED__ equ <>
    ;* __IAccessibilityDockingServiceCallback_FWD_DEFINED__ *
  endif
  ifndef __IAccessibilityDockingService_FWD_DEFINED__
    __IAccessibilityDockingService_FWD_DEFINED__ equ <>
    ;* __IAccessibilityDockingService_FWD_DEFINED__ *
  endif
  ifndef __IStorageProviderBanners_FWD_DEFINED__
    __IStorageProviderBanners_FWD_DEFINED__ equ <>
    ;* __IStorageProviderBanners_FWD_DEFINED__ *
  endif
  ifndef __IStorageProviderCopyHook_FWD_DEFINED__
    __IStorageProviderCopyHook_FWD_DEFINED__ equ <>
    ;* __IStorageProviderCopyHook_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include objidl.inc
  include oleidl.inc
  include oaidl.inc
  include docobj.inc
  include shtypes.inc
  include comcat.inc
  include propidl.inc
  include prsht.inc
  include propsys.inc
  include ObjectArray.inc
  include shobjidl_core.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_shobjidl_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  if _MSC_VER ge 1200
    ;* padding added after data member *
    ifndef _MSC_EXTENSIONS
      ;* truncation of constant value *
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include sherrors.inc
    externdef __MIDL_itf_shobjidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IQueryCodePage_INTERFACE_DEFINED__
      __IQueryCodePage_INTERFACE_DEFINED__ equ <>
      ;* interface IQueryCodePage *
      ;* [local][unique][uuid][object] *
      externdef IID_IQueryCodePage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IQueryCodePageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IQueryCodePageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IQueryCodePage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IQueryCodePage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IQueryCodePage
          DECLSPEC_XFGVIRT(IQueryCodePage, GetCodePage)
          ;* [annotation][out] *
          STD_METHOD GetCodePage, :ptr IQueryCodePage, :ptr UINT
          DECLSPEC_XFGVIRT(IQueryCodePage, SetCodePage)
          ;* [annotation][in] *
          STD_METHOD SetCodePage, :ptr IQueryCodePage, :UINT
          ??Interface equ <>
          END_INTERFACE
        IQueryCodePageVtbl ends
        IQueryCodePage struct
          lpVtbl POINTER ?
        IQueryCodePage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IQueryCodePage_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0001 *
    ;* [local] *
    ;* [v1_enum] *
    SYNC_ENGINE_STATE_FLAGS typedef SDWORD
    SESF_NONE equ 0
    SESF_SERVICE_QUOTA_NEARING_LIMIT equ 1h
    SESF_SERVICE_QUOTA_EXCEEDED_LIMIT equ 2h
    SESF_AUTHENTICATION_ERROR equ 4h
    SESF_PAUSED_DUE_TO_METERED_NETWORK equ 8h
    SESF_PAUSED_DUE_TO_DISK_SPACE_FULL equ 10h
    SESF_PAUSED_DUE_TO_CLIENT_POLICY equ 20h
    SESF_PAUSED_DUE_TO_SERVICE_POLICY equ 40h
    SESF_SERVICE_UNAVAILABLE equ 80h
    SESF_PAUSED_DUE_TO_USER_REQUEST equ 100h
    SESF_ALL_FLAGS equ

    DEFINE_ENUM_FLAG_OPERATORS(SYNC_ENGINE_STATE_FLAGS)
    LPVIEWSETTINGS typedef ptr SBYTE
    externdef __MIDL_itf_shobjidl_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFolderViewOptions_INTERFACE_DEFINED__
      __IFolderViewOptions_INTERFACE_DEFINED__ equ <>
      ;* interface IFolderViewOptions *
      ;* [unique][object][uuid] *
      ;* [v1_enum] *
      FOLDERVIEWOPTIONS typedef SDWORD
      FVO_DEFAULT equ 0
      FVO_VISTALAYOUT equ 1h
      FVO_CUSTOMPOSITION equ 2h
      FVO_CUSTOMORDERING equ 4h
      FVO_SUPPORTHYPERLINKS equ 8h
      FVO_NOANIMATIONS equ 10h
      FVO_NOSCROLLTIPS equ 20h

      DEFINE_ENUM_FLAG_OPERATORS(FOLDERVIEWOPTIONS)
      externdef IID_IFolderViewOptions:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFolderViewOptionsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFolderViewOptionsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IFolderViewOptions, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFolderViewOptions
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFolderViewOptions
          DECLSPEC_XFGVIRT(IFolderViewOptions, SetFolderViewOptions)
          ;* [in] *
          STD_METHOD SetFolderViewOptions, :ptr IFolderViewOptions, :FOLDERVIEWOPTIONS, :FOLDERVIEWOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(IFolderViewOptions, GetFolderViewOptions)
          STD_METHOD GetFolderViewOptions, :ptr IFolderViewOptions, :ptr FOLDERVIEWOPTIONS
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IFolderViewOptionsVtbl ends
        IFolderViewOptions struct
          lpVtbl POINTER ?
        IFolderViewOptions ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IFolderViewOptions_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0002 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IShellView3_INTERFACE_DEFINED__
        __IShellView3_INTERFACE_DEFINED__ equ <>
        ;* interface IShellView3 *
        ;* [unique][object][uuid] *
        ;* [v1_enum] *
        _SV3CVW3_FLAGS typedef SDWORD
        SV3CVW3_DEFAULT equ 0
        SV3CVW3_NONINTERACTIVE equ 1h
        SV3CVW3_FORCEVIEWMODE equ 2h
        SV3CVW3_FORCEFOLDERFLAGS equ 4h

        SV3CVW3_FLAGS typedef DWORD
        externdef IID_IShellView3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellView3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellView3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellView3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellView3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellView3
            DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
            ;* [input_sync] *
            STD_METHOD GetWindow, :ptr IShellView3, :ptr HWND
            ;* [out] *
            DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
            STD_METHOD ContextSensitiveHelp, :ptr IShellView3, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView, TranslateAccelerator)
            STD_METHOD TranslateAccelerator, :ptr IShellView3, :ptr MSG
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView, EnableModeless)
            STD_METHOD EnableModeless, :ptr IShellView3, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView, UIActivate)
            STD_METHOD UIActivate, :ptr IShellView3, :UINT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView, Refresh)
            STD_METHOD Refresh, :ptr IShellView3
            DECLSPEC_XFGVIRT(IShellView, CreateViewWindow)
            ;* [unique][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateViewWindow, :ptr IShellView3, :ptr IShellView, :LPCFOLDERSETTINGS, :ptr IShellBrowser, :ptr RECT, :ptr HWND
            ;* [out] *
            DECLSPEC_XFGVIRT(IShellView, DestroyViewWindow)
            STD_METHOD DestroyViewWindow, :ptr IShellView3
            DECLSPEC_XFGVIRT(IShellView, GetCurrentInfo)
            STD_METHOD GetCurrentInfo, :ptr IShellView3, :LPFOLDERSETTINGS
            ;* [out] *
            DECLSPEC_XFGVIRT(IShellView, AddPropertySheetPages)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            STD_METHOD AddPropertySheetPages, :ptr IShellView3, :DWORD, :LPFNSVADDPROPSHEETPAGE, :LPARAM
            DECLSPEC_XFGVIRT(IShellView, SaveViewState)
            STD_METHOD SaveViewState, :ptr IShellView3
            DECLSPEC_XFGVIRT(IShellView, SelectItem)
            ;* [unique][in] *
            STD_METHOD SelectItem, :ptr IShellView3, :PCUITEMID_CHILD, :SVSIF
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView, GetItemObject)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetItemObject, :ptr IShellView3, :UINT, :REFIID, :ptr ptr
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IShellView2, GetView)
            ;* [out][in] *
            STD_METHOD GetView, :ptr IShellView3, :ptr SHELLVIEWID, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView2, CreateViewWindow2)
            STD_METHOD CreateViewWindow2, :ptr IShellView3, :LPSV2CVW2_PARAMS
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellView2, HandleRename)
            STD_METHOD HandleRename, :ptr IShellView3, :PCUITEMID_CHILD
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IShellView2, SelectAndPositionItem)
            ;* [unique][in] *
            ;* [in] *
            STD_METHOD SelectAndPositionItem, :ptr IShellView3, :PCUITEMID_CHILD, :UINT, :ptr POINT
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IShellView3, CreateViewWindow3)
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            STD_METHOD CreateViewWindow3, :ptr IShellView3, :ptr IShellBrowser, :ptr IShellView, :SV3CVW3_FLAGS, :FOLDERFLAGS, :FOLDERFLAGS, :FOLDERVIEWMODE, :ptr SHELLVIEWID, :ptr RECT, :ptr HWND
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IShellView3Vtbl ends
          IShellView3 struct
            lpVtbl POINTER ?
          IShellView3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellView3_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0003 *
      ;* [local] *
    endif
    ; NTDDI_VISTA
    if (NTDDI_VERSION ge NTDDI_WIN7)
      externdef __MIDL_itf_shobjidl_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISearchBoxInfo_INTERFACE_DEFINED__
        __ISearchBoxInfo_INTERFACE_DEFINED__ equ <>
        ;* interface ISearchBoxInfo *
        ;* [object][uuid] *
        externdef IID_ISearchBoxInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISearchBoxInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISearchBoxInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISearchBoxInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISearchBoxInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISearchBoxInfo
            DECLSPEC_XFGVIRT(ISearchBoxInfo, GetCondition)
            ;* [in] *
            STD_METHOD GetCondition, :ptr ISearchBoxInfo, :REFIID, :ptr ptr
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(ISearchBoxInfo, GetText)
            STD_METHOD GetText, :ptr ISearchBoxInfo, :ptr LPWSTR
            ;* [string][out] *
            ??Interface equ <>
            END_INTERFACE
          ISearchBoxInfoVtbl ends
          ISearchBoxInfo struct
            lpVtbl POINTER ?
          ISearchBoxInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISearchBoxInfo_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0004 *
      ;* [local] *
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN7)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IVisualProperties_INTERFACE_DEFINED__
        __IVisualProperties_INTERFACE_DEFINED__ equ <>
        ;* interface IVisualProperties *
        ;* [unique][object][uuid] *
        ;* [v1_enum] *
        VPWATERMARKFLAGS typedef SDWORD
        VPWF_DEFAULT equ 0
        VPWF_ALPHABLEND equ 1h

        DEFINE_ENUM_FLAG_OPERATORS(VPWATERMARKFLAGS)
        ;* [v1_enum] *
        VPCOLORFLAGS typedef SDWORD
        VPCF_TEXT equ 1
        VPCF_BACKGROUND equ 2
        VPCF_SORTCOLUMN equ 3
        VPCF_SUBTEXT equ 4
        VPCF_TEXTBACKGROUND equ 5

        externdef IID_IVisualProperties:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IVisualPropertiesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IVisualPropertiesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IVisualProperties, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IVisualProperties
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IVisualProperties
            DECLSPEC_XFGVIRT(IVisualProperties, SetWatermark)
            ;* [unique][in] *
            STD_METHOD SetWatermark, :ptr IVisualProperties, :HBITMAP, :VPWATERMARKFLAGS
            ;* [in] *
            DECLSPEC_XFGVIRT(IVisualProperties, SetColor)
            ;* [in] *
            STD_METHOD SetColor, :ptr IVisualProperties, :VPCOLORFLAGS, :COLORREF
            ;* [in] *
            DECLSPEC_XFGVIRT(IVisualProperties, GetColor)
            ;* [in] *
            STD_METHOD GetColor, :ptr IVisualProperties, :VPCOLORFLAGS, :ptr COLORREF
            ;* [out] *
            DECLSPEC_XFGVIRT(IVisualProperties, SetItemHeight)
            STD_METHOD SetItemHeight, :ptr IVisualProperties, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IVisualProperties, GetItemHeight)
            STD_METHOD GetItemHeight, :ptr IVisualProperties, :ptr SDWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IVisualProperties, SetFont)
            ;* [in] *
            STD_METHOD SetFont, :ptr IVisualProperties, :ptr LOGFONTW, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IVisualProperties, GetFont)
            STD_METHOD GetFont, :ptr IVisualProperties, :ptr LOGFONTW
            ;* [out] *
            DECLSPEC_XFGVIRT(IVisualProperties, SetTheme)
            ;* [string][unique][in] *
            STD_METHOD SetTheme, :ptr IVisualProperties, :LPCWSTR, :LPCWSTR
            ;* [string][unique][in] *
            ??Interface equ <>
            END_INTERFACE
          IVisualPropertiesVtbl ends
          IVisualProperties struct
            lpVtbl POINTER ?
          IVisualProperties ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IVisualProperties_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0005 *
      ;* [local] *
    endif
    ; _WIN32_IE_IE70
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICommDlgBrowser3_INTERFACE_DEFINED__
        __ICommDlgBrowser3_INTERFACE_DEFINED__ equ <>
        ;* interface ICommDlgBrowser3 *
        ;* [unique][object][uuid] *
        externdef IID_ICommDlgBrowser3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICommDlgBrowser3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICommDlgBrowser3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICommDlgBrowser3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICommDlgBrowser3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICommDlgBrowser3
            DECLSPEC_XFGVIRT(ICommDlgBrowser, OnDefaultCommand)
            STD_METHOD OnDefaultCommand, :ptr ICommDlgBrowser3, :ptr IShellView
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser, OnStateChange)
            ;* [in] *
            STD_METHOD OnStateChange, :ptr ICommDlgBrowser3, :ptr IShellView, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser, IncludeObject)
            ;* [unique][in] *
            STD_METHOD IncludeObject, :ptr ICommDlgBrowser3, :ptr IShellView, :PCUITEMID_CHILD
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser2, Notify)
            ;* [in] *
            STD_METHOD Notify, :ptr ICommDlgBrowser3, :ptr IShellView, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser2, GetDefaultMenuText)
            ;* [in] *
            ;* [size_is][string][out] *
            STD_METHOD GetDefaultMenuText, :ptr ICommDlgBrowser3, :ptr IShellView, :LPWSTR, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser2, GetViewFlags)
            STD_METHOD GetViewFlags, :ptr ICommDlgBrowser3, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser3, OnColumnClicked)
            ;* [in] *
            STD_METHOD OnColumnClicked, :ptr ICommDlgBrowser3, :ptr IShellView, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser3, GetCurrentFilter)
            ;* [size_is][string][out] *
            STD_METHOD GetCurrentFilter, :ptr ICommDlgBrowser3, :LPWSTR, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ICommDlgBrowser3, OnPreViewCreated)
            STD_METHOD OnPreViewCreated, :ptr ICommDlgBrowser3, :ptr IShellView
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ICommDlgBrowser3Vtbl ends
          ICommDlgBrowser3 struct
            lpVtbl POINTER ?
          ICommDlgBrowser3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ICommDlgBrowser3_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0006 *
      ;* [local] *
    endif
    ; (_WIN32_IE >= _WIN32_IE_IE70)
    externdef __MIDL_itf_shobjidl_0000_0006_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0006_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUserAccountChangeCallback_INTERFACE_DEFINED__
      __IUserAccountChangeCallback_INTERFACE_DEFINED__ equ <>
      ;* interface IUserAccountChangeCallback *
      ;* [version][uuid][object] *
      externdef IID_IUserAccountChangeCallback:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserAccountChangeCallbackVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserAccountChangeCallbackVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IUserAccountChangeCallback, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IUserAccountChangeCallback
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IUserAccountChangeCallback
          DECLSPEC_XFGVIRT(IUserAccountChangeCallback, OnPictureChange)
          STD_METHOD OnPictureChange, :ptr IUserAccountChangeCallback, :LPCWSTR
          ;* [string][in] *
          ??Interface equ <>
          END_INTERFACE
        IUserAccountChangeCallbackVtbl ends
        IUserAccountChangeCallback struct
          lpVtbl POINTER ?
        IUserAccountChangeCallback ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IUserAccountChangeCallback_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0007 *
    ;* [local] *
    ifdef MIDL_PASS
      ;[...]
    endif
    ; MIDL_PASS
    externdef __MIDL_itf_shobjidl_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IStreamAsync_INTERFACE_DEFINED__
      __IStreamAsync_INTERFACE_DEFINED__ equ <>
      ;* interface IStreamAsync *
      ;* [local][unique][uuid][object] *
      externdef IID_IStreamAsync:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStreamAsyncVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStreamAsyncVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IStreamAsync, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IStreamAsync
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IStreamAsync
          DECLSPEC_XFGVIRT(ISequentialStream, Read)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Read, :ptr IStreamAsync, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ISequentialStream, Write)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Write, :ptr IStreamAsync, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IStream, Seek)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation] *
          STD_METHOD Seek, :ptr IStreamAsync, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, SetSize)
          STD_METHOD SetSize, :ptr IStreamAsync, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, CopyTo)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD CopyTo, :ptr IStreamAsync, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, Commit)
          STD_METHOD Commit, :ptr IStreamAsync, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Revert)
          STD_METHOD Revert, :ptr IStreamAsync
          DECLSPEC_XFGVIRT(IStream, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr IStreamAsync, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr IStreamAsync, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr IStreamAsync, :ptr STATSTG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Clone)
          STD_METHOD Clone, :ptr IStreamAsync, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(IStreamAsync, ReadAsync)
          ;* [annotation][length_is][size_is][out] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][in] *
          STD_METHOD ReadAsync, :ptr IStreamAsync, :ptr, :DWORD, :LPDWORD, :LPOVERLAPPED
          DECLSPEC_XFGVIRT(IStreamAsync, WriteAsync)
          ;* [annotation][size_is][in] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][in] *
          STD_METHOD WriteAsync, :ptr IStreamAsync, :ptr, :DWORD, :LPDWORD, :LPOVERLAPPED
          DECLSPEC_XFGVIRT(IStreamAsync, OverlappedResult)
          ;* [annotation][in] *
          ;* [annotation][out] *
          ;* [annotation][in] *
          STD_METHOD OverlappedResult, :ptr IStreamAsync, :LPOVERLAPPED, :LPDWORD, :BOOL
          DECLSPEC_XFGVIRT(IStreamAsync, CancelIo)
          STD_METHOD CancelIo, :ptr IStreamAsync
          ??Interface equ <>
          END_INTERFACE
        IStreamAsyncVtbl ends
        IStreamAsync struct
          lpVtbl POINTER ?
        IStreamAsync ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IStreamAsync_INTERFACE_DEFINED__ *
    endif
    ifndef __IStreamUnbufferedInfo_INTERFACE_DEFINED__
      __IStreamUnbufferedInfo_INTERFACE_DEFINED__ equ <>
      ;* interface IStreamUnbufferedInfo *
      ;* [local][unique][uuid][object] *
      externdef IID_IStreamUnbufferedInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStreamUnbufferedInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStreamUnbufferedInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IStreamUnbufferedInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IStreamUnbufferedInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IStreamUnbufferedInfo
          DECLSPEC_XFGVIRT(IStreamUnbufferedInfo, GetSectorSize)
          ;* [annotation][out] *
          STD_METHOD GetSectorSize, :ptr IStreamUnbufferedInfo, :ptr ULONG
          ??Interface equ <>
          END_INTERFACE
        IStreamUnbufferedInfoVtbl ends
        IStreamUnbufferedInfo struct
          lpVtbl POINTER ?
        IStreamUnbufferedInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IStreamUnbufferedInfo_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0009 *
    ;* [local] *
    if (_WIN32_IE ge _WIN32_IE_IE70)
      @DefProto DllImport, SHRemovePersonalPropertyValues, WIN_STD_CALL_CONV,, <:ptr IShellItemArray>, 4
      @DefProto DllImport, SHAddDefaultPropertiesByExt, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr IPropertyStore>, 8
      @DefProto DllImport, SHCreateDefaultPropertiesOp, WIN_STD_CALL_CONV,, <:ptr IShellItem, :ptr ptr IFileOperation>, 8
      @DefProto DllImport, SHSetDefaultProperties, WIN_STD_CALL_CONV,, <:HWND, :ptr IShellItem, :DWORD, :ptr IFileOperationProgressSink>, 16
    endif
    ; (_WIN32_IE >= _WIN32_IE_IE70)
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        ;* [v1_enum] *
        DSH_FLAGS typedef SDWORD
        DSH_ALLOWDROPDESCRIPTIONTEXT equ 1h

        DEFINE_ENUM_FLAG_OPERATORS(DSH_FLAGS)
        externdef __MIDL_itf_shobjidl_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IDragSourceHelper2_INTERFACE_DEFINED__
          __IDragSourceHelper2_INTERFACE_DEFINED__ equ <>
          ;* interface IDragSourceHelper2 *
          ;* [object][unique][local][uuid] *
          externdef IID_IDragSourceHelper2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IDragSourceHelper2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IDragSourceHelper2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IDragSourceHelper2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IDragSourceHelper2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IDragSourceHelper2
              DECLSPEC_XFGVIRT(IDragSourceHelper, InitializeFromBitmap)
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD InitializeFromBitmap, :ptr IDragSourceHelper2, :LPSHDRAGIMAGE, :ptr IDataObject
              DECLSPEC_XFGVIRT(IDragSourceHelper, InitializeFromWindow)
              ;* [annotation][unique][in] *
              ;* [annotation][unique][in] *
              ;* [annotation][in] *
              STD_METHOD InitializeFromWindow, :ptr IDragSourceHelper2, :HWND, :ptr POINT, :ptr IDataObject
              DECLSPEC_XFGVIRT(IDragSourceHelper2, SetFlags)
              ;* [annotation][in] *
              STD_METHOD SetFlags, :ptr IDragSourceHelper2, :DWORD
              ??Interface equ <>
              END_INTERFACE
            IDragSourceHelper2Vtbl ends
            IDragSourceHelper2 struct
              lpVtbl POINTER ?
            IDragSourceHelper2 ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IDragSourceHelper2_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_shobjidl_0000_0010 *
        ;* [local] *
      endif
      ; NTDDI_VISTA
    endif
    ; NTDDI_WIN2K
    externdef __MIDL_itf_shobjidl_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IHWEventHandler_INTERFACE_DEFINED__
      __IHWEventHandler_INTERFACE_DEFINED__ equ <>
      ;* interface IHWEventHandler *
      ;* [unique][uuid][object] *
      externdef IID_IHWEventHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IHWEventHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IHWEventHandlerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IHWEventHandler, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IHWEventHandler
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IHWEventHandler
          DECLSPEC_XFGVIRT(IHWEventHandler, Initialize)
          STD_METHOD Initialize, :ptr IHWEventHandler, :LPCWSTR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(IHWEventHandler, HandleEvent)
          ;* [string][in] *
          ;* [string][in] *
          STD_METHOD HandleEvent, :ptr IHWEventHandler, :LPCWSTR, :LPCWSTR, :LPCWSTR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(IHWEventHandler, HandleEventWithContent)
          ;* [string][in] *
          ;* [string][in] *
          ;* [string][in] *
          ;* [string][in] *
          STD_METHOD HandleEventWithContent, :ptr IHWEventHandler, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr IDataObject
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IHWEventHandlerVtbl ends
        IHWEventHandler struct
          lpVtbl POINTER ?
        IHWEventHandler ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IHWEventHandler_INTERFACE_DEFINED__ *
    endif
    ifndef __IHWEventHandler2_INTERFACE_DEFINED__
      __IHWEventHandler2_INTERFACE_DEFINED__ equ <>
      ;* interface IHWEventHandler2 *
      ;* [unique][uuid][object] *
      externdef IID_IHWEventHandler2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IHWEventHandler2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IHWEventHandler2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IHWEventHandler2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IHWEventHandler2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IHWEventHandler2
          DECLSPEC_XFGVIRT(IHWEventHandler, Initialize)
          STD_METHOD Initialize, :ptr IHWEventHandler2, :LPCWSTR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(IHWEventHandler, HandleEvent)
          ;* [string][in] *
          ;* [string][in] *
          STD_METHOD HandleEvent, :ptr IHWEventHandler2, :LPCWSTR, :LPCWSTR, :LPCWSTR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(IHWEventHandler, HandleEventWithContent)
          ;* [string][in] *
          ;* [string][in] *
          ;* [string][in] *
          ;* [string][in] *
          STD_METHOD HandleEventWithContent, :ptr IHWEventHandler2, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr IDataObject
          ;* [in] *
          DECLSPEC_XFGVIRT(IHWEventHandler2, HandleEventWithHWND)
          ;* [string][in] *
          ;* [string][in] *
          ;* [string][in] *
          STD_METHOD HandleEventWithHWND, :ptr IHWEventHandler2, :LPCWSTR, :LPCWSTR, :LPCWSTR, :HWND
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IHWEventHandler2Vtbl ends
        IHWEventHandler2 struct
          lpVtbl POINTER ?
        IHWEventHandler2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IHWEventHandler2_INTERFACE_DEFINED__ *
    endif
    ifndef __IQueryCancelAutoPlay_INTERFACE_DEFINED__
      __IQueryCancelAutoPlay_INTERFACE_DEFINED__ equ <>
      ;* interface IQueryCancelAutoPlay *
      ;* [unique][uuid][object] *
      externdef IID_IQueryCancelAutoPlay:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IQueryCancelAutoPlayVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IQueryCancelAutoPlayVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IQueryCancelAutoPlay, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IQueryCancelAutoPlay
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IQueryCancelAutoPlay
          DECLSPEC_XFGVIRT(IQueryCancelAutoPlay, AllowAutoPlay)
          ;* [string][in] *
          ;* [in] *
          ;* [string][in] *
          STD_METHOD AllowAutoPlay, :ptr IQueryCancelAutoPlay, :LPCWSTR, :DWORD, :LPCWSTR, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IQueryCancelAutoPlayVtbl ends
        IQueryCancelAutoPlay struct
          lpVtbl POINTER ?
        IQueryCancelAutoPlay ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IQueryCancelAutoPlay_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0013 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDynamicHWHandler_INTERFACE_DEFINED__
        __IDynamicHWHandler_INTERFACE_DEFINED__ equ <>
        ;* interface IDynamicHWHandler *
        ;* [unique][uuid][object] *
        externdef IID_IDynamicHWHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDynamicHWHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDynamicHWHandlerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDynamicHWHandler, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDynamicHWHandler
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDynamicHWHandler
            DECLSPEC_XFGVIRT(IDynamicHWHandler, GetDynamicInfo)
            ;* [string][in] *
            ;* [in] *
            STD_METHOD GetDynamicInfo, :ptr IDynamicHWHandler, :LPCWSTR, :DWORD, :ptr LPWSTR
            ;* [string][out] *
            ??Interface equ <>
            END_INTERFACE
          IDynamicHWHandlerVtbl ends
          IDynamicHWHandler struct
            lpVtbl POINTER ?
          IDynamicHWHandler ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDynamicHWHandler_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0014 *
      ;* [local] *
    endif
    ; NTDDI_VISTA
    externdef __MIDL_itf_shobjidl_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUserNotificationCallback_INTERFACE_DEFINED__
      __IUserNotificationCallback_INTERFACE_DEFINED__ equ <>
      ;* interface IUserNotificationCallback *
      ;* [object][uuid] *
      externdef IID_IUserNotificationCallback:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserNotificationCallbackVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserNotificationCallbackVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IUserNotificationCallback, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IUserNotificationCallback
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IUserNotificationCallback
          DECLSPEC_XFGVIRT(IUserNotificationCallback, OnBalloonUserClick)
          STD_METHOD OnBalloonUserClick, :ptr IUserNotificationCallback, :ptr POINT
          ;* [in] *
          DECLSPEC_XFGVIRT(IUserNotificationCallback, OnLeftClick)
          STD_METHOD OnLeftClick, :ptr IUserNotificationCallback, :ptr POINT
          ;* [in] *
          DECLSPEC_XFGVIRT(IUserNotificationCallback, OnContextMenu)
          STD_METHOD OnContextMenu, :ptr IUserNotificationCallback, :ptr POINT
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IUserNotificationCallbackVtbl ends
        IUserNotificationCallback struct
          lpVtbl POINTER ?
        IUserNotificationCallback ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IUserNotificationCallback_INTERFACE_DEFINED__ *
    endif
    ifndef __IUserNotification2_INTERFACE_DEFINED__
      __IUserNotification2_INTERFACE_DEFINED__ equ <>
      ;* interface IUserNotification2 *
      ;* [unique][object][uuid] *
      externdef IID_IUserNotification2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserNotification2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserNotification2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IUserNotification2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IUserNotification2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IUserNotification2
          DECLSPEC_XFGVIRT(IUserNotification2, SetBalloonInfo)
          ;* [string][unique][in] *
          ;* [string][unique][in] *
          STD_METHOD SetBalloonInfo, :ptr IUserNotification2, :LPCWSTR, :LPCWSTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IUserNotification2, SetBalloonRetry)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetBalloonRetry, :ptr IUserNotification2, :DWORD, :DWORD, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(IUserNotification2, SetIconInfo)
          ;* [unique][in] *
          STD_METHOD SetIconInfo, :ptr IUserNotification2, :HICON, :LPCWSTR
          ;* [string][unique][in] *
          DECLSPEC_XFGVIRT(IUserNotification2, Show)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD Show, :ptr IUserNotification2, :ptr IQueryContinue, :DWORD, :ptr IUserNotificationCallback
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IUserNotification2, PlaySound)
          STD_METHOD PlaySound, :ptr IUserNotification2, :LPCWSTR
          ;* [string][in] *
          ??Interface equ <>
          END_INTERFACE
        IUserNotification2Vtbl ends
        IUserNotification2 struct
          lpVtbl POINTER ?
        IUserNotification2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IUserNotification2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0016 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0016_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0016_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDeskBand2_INTERFACE_DEFINED__
        __IDeskBand2_INTERFACE_DEFINED__ equ <>
        ;* interface IDeskBand2 *
        ;* [object][uuid] *
        externdef IID_IDeskBand2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDeskBand2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDeskBand2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDeskBand2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDeskBand2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDeskBand2
            DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
            ;* [input_sync] *
            STD_METHOD GetWindow, :ptr IDeskBand2, :ptr HWND
            ;* [out] *
            DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
            STD_METHOD ContextSensitiveHelp, :ptr IDeskBand2, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IDockingWindow, ShowDW)
            STD_METHOD ShowDW, :ptr IDeskBand2, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IDockingWindow, CloseDW)
            STD_METHOD CloseDW, :ptr IDeskBand2, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDockingWindow, ResizeBorderDW)
            ;* [unique][in] *
            ;* [unique][in] *
            STD_METHOD ResizeBorderDW, :ptr IDeskBand2, :LPCRECT, :ptr IUnknown, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IDeskBand, GetBandInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetBandInfo, :ptr IDeskBand2, :DWORD, :DWORD, :ptr DESKBANDINFO
            ;* [out][in] *
            DECLSPEC_XFGVIRT(IDeskBand2, CanRenderComposited)
            STD_METHOD CanRenderComposited, :ptr IDeskBand2, :ptr BOOL
            ;* [out] *
            DECLSPEC_XFGVIRT(IDeskBand2, SetCompositionState)
            STD_METHOD SetCompositionState, :ptr IDeskBand2, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IDeskBand2, GetCompositionState)
            STD_METHOD GetCompositionState, :ptr IDeskBand2, :ptr BOOL
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDeskBand2Vtbl ends
          IDeskBand2 struct
            lpVtbl POINTER ?
          IDeskBand2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDeskBand2_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0017 *
      ;* [local] *
    endif
    ; NTDDI_VISTA
    externdef __MIDL_itf_shobjidl_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IStartMenuPinnedList_INTERFACE_DEFINED__
      __IStartMenuPinnedList_INTERFACE_DEFINED__ equ <>
      ;* interface IStartMenuPinnedList *
      ;* [object][uuid] *
      externdef IID_IStartMenuPinnedList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStartMenuPinnedListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStartMenuPinnedListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IStartMenuPinnedList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IStartMenuPinnedList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IStartMenuPinnedList
          DECLSPEC_XFGVIRT(IStartMenuPinnedList, RemoveFromList)
          STD_METHOD RemoveFromList, :ptr IStartMenuPinnedList, :ptr IShellItem
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IStartMenuPinnedListVtbl ends
        IStartMenuPinnedList struct
          lpVtbl POINTER ?
        IStartMenuPinnedList ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IStartMenuPinnedList_INTERFACE_DEFINED__ *
    endif
    ifndef __ICDBurn_INTERFACE_DEFINED__
      __ICDBurn_INTERFACE_DEFINED__ equ <>
      ;* interface ICDBurn *
      ;* [unique][uuid][object] *
      externdef IID_ICDBurn:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICDBurnVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICDBurnVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICDBurn, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICDBurn
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICDBurn
          DECLSPEC_XFGVIRT(ICDBurn, GetRecorderDriveLetter)
          ;* [size_is][string][out] *
          STD_METHOD GetRecorderDriveLetter, :ptr ICDBurn, :LPWSTR, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICDBurn, Burn)
          STD_METHOD Burn, :ptr ICDBurn, :HWND
          ;* [in] *
          DECLSPEC_XFGVIRT(ICDBurn, HasRecordableDrive)
          STD_METHOD HasRecordableDrive, :ptr ICDBurn, :ptr BOOL
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ICDBurnVtbl ends
        ICDBurn struct
          lpVtbl POINTER ?
        ICDBurn ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ICDBurn_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0019 *
    ;* [local] *
    IDD_WIZEXTN_FIRST equ 5000h
    IDD_WIZEXTN_LAST equ 5100h
    externdef __MIDL_itf_shobjidl_0000_0019_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0019_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IWizardSite_INTERFACE_DEFINED__
      __IWizardSite_INTERFACE_DEFINED__ equ <>
      ;* interface IWizardSite *
      ;* [object][local][uuid] *
      externdef IID_IWizardSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IWizardSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IWizardSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IWizardSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IWizardSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IWizardSite
          DECLSPEC_XFGVIRT(IWizardSite, GetPreviousPage)
          ;* [annotation][out] *
          STD_METHOD GetPreviousPage, :ptr IWizardSite, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IWizardSite, GetNextPage)
          ;* [annotation][out] *
          STD_METHOD GetNextPage, :ptr IWizardSite, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IWizardSite, GetCancelledPage)
          ;* [annotation][out] *
          STD_METHOD GetCancelledPage, :ptr IWizardSite, :ptr HPROPSHEETPAGE
          ??Interface equ <>
          END_INTERFACE
        IWizardSiteVtbl ends
        IWizardSite struct
          lpVtbl POINTER ?
        IWizardSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IWizardSite_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0020 *
    ;* [local] *
    SID_WizardSite equ <IID_IWizardSite>
    externdef __MIDL_itf_shobjidl_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IWizardExtension_INTERFACE_DEFINED__
      __IWizardExtension_INTERFACE_DEFINED__ equ <>
      ;* interface IWizardExtension *
      ;* [object][local][uuid] *
      externdef IID_IWizardExtension:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IWizardExtensionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IWizardExtensionVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IWizardExtension, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IWizardExtension
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IWizardExtension
          DECLSPEC_XFGVIRT(IWizardExtension, AddPages)
          ;* [annotation][size_is][out] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD AddPages, :ptr IWizardExtension, :ptr HPROPSHEETPAGE, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(IWizardExtension, GetFirstPage)
          ;* [annotation][out] *
          STD_METHOD GetFirstPage, :ptr IWizardExtension, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IWizardExtension, GetLastPage)
          ;* [annotation][out] *
          STD_METHOD GetLastPage, :ptr IWizardExtension, :ptr HPROPSHEETPAGE
          ??Interface equ <>
          END_INTERFACE
        IWizardExtensionVtbl ends
        IWizardExtension struct
          lpVtbl POINTER ?
        IWizardExtension ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IWizardExtension_INTERFACE_DEFINED__ *
    endif
    ifndef __IWebWizardExtension_INTERFACE_DEFINED__
      __IWebWizardExtension_INTERFACE_DEFINED__ equ <>
      ;* interface IWebWizardExtension *
      ;* [object][unique][local][uuid] *
      externdef IID_IWebWizardExtension:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IWebWizardExtensionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IWebWizardExtensionVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IWebWizardExtension, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IWebWizardExtension
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IWebWizardExtension
          DECLSPEC_XFGVIRT(IWizardExtension, AddPages)
          ;* [annotation][size_is][out] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD AddPages, :ptr IWebWizardExtension, :ptr HPROPSHEETPAGE, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(IWizardExtension, GetFirstPage)
          ;* [annotation][out] *
          STD_METHOD GetFirstPage, :ptr IWebWizardExtension, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IWizardExtension, GetLastPage)
          ;* [annotation][out] *
          STD_METHOD GetLastPage, :ptr IWebWizardExtension, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IWebWizardExtension, SetInitialURL)
          ;* [annotation][string][in] *
          STD_METHOD SetInitialURL, :ptr IWebWizardExtension, :LPCWSTR
          DECLSPEC_XFGVIRT(IWebWizardExtension, SetErrorURL)
          ;* [annotation][string][in] *
          STD_METHOD SetErrorURL, :ptr IWebWizardExtension, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IWebWizardExtensionVtbl ends
        IWebWizardExtension struct
          lpVtbl POINTER ?
        IWebWizardExtension ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IWebWizardExtension_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0022 *
    ;* [local] *
    SID_WebWizardHost equ <IID_IWebWizardExtension>
    SHPWHF_NORECOMPRESS equ 00000001h; don't allow/prompt for recompress of streams

    SHPWHF_NONETPLACECREATE equ 00000002h; don't create a network place when transfer is complete

    SHPWHF_NOFILESELECTOR equ 00000004h; don't show the file selector

    SHPWHF_USEMRU equ 00000008h; For OPW.  Use the Most-Recently-Used Print Provider

    if (NTDDI_VERSION ge NTDDI_VISTA)
      SHPWHF_ANYLOCATION equ 00000100h; allow publishing to any location

    endif
    ; NTDDI_VISTA
    SHPWHF_VALIDATEVIAWEBFOLDERS equ 00010000h; enable web folders to validate network places (ANP support)

    externdef __MIDL_itf_shobjidl_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPublishingWizard_INTERFACE_DEFINED__
      __IPublishingWizard_INTERFACE_DEFINED__ equ <>
      ;* interface IPublishingWizard *
      ;* [object][unique][local][uuid] *
      externdef IID_IPublishingWizard:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPublishingWizardVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPublishingWizardVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPublishingWizard, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPublishingWizard
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPublishingWizard
          DECLSPEC_XFGVIRT(IWizardExtension, AddPages)
          ;* [annotation][size_is][out] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD AddPages, :ptr IPublishingWizard, :ptr HPROPSHEETPAGE, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(IWizardExtension, GetFirstPage)
          ;* [annotation][out] *
          STD_METHOD GetFirstPage, :ptr IPublishingWizard, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IWizardExtension, GetLastPage)
          ;* [annotation][out] *
          STD_METHOD GetLastPage, :ptr IPublishingWizard, :ptr HPROPSHEETPAGE
          DECLSPEC_XFGVIRT(IPublishingWizard, Initialize)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][string][in] *
          STD_METHOD Initialize, :ptr IPublishingWizard, :ptr IDataObject, :DWORD, :LPCWSTR
          DECLSPEC_XFGVIRT(IPublishingWizard, GetTransferManifest)
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD GetTransferManifest, :ptr IPublishingWizard, :ptr HRESULT, :ptr ptr IXMLDOMDocument
          ??Interface equ <>
          END_INTERFACE
        IPublishingWizardVtbl ends
        IPublishingWizard struct
          lpVtbl POINTER ?
        IPublishingWizard ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPublishingWizard_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0023 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFolderViewHost_INTERFACE_DEFINED__
        __IFolderViewHost_INTERFACE_DEFINED__ equ <>
        ;* interface IFolderViewHost *
        ;* [object][local][uuid] *
        externdef IID_IFolderViewHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFolderViewHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFolderViewHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IFolderViewHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFolderViewHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFolderViewHost
            DECLSPEC_XFGVIRT(IFolderViewHost, Initialize)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            STD_METHOD Initialize, :ptr IFolderViewHost, :HWND, :ptr IDataObject, :ptr RECT
            ??Interface equ <>
            END_INTERFACE
          IFolderViewHostVtbl ends
          IFolderViewHost struct
            lpVtbl POINTER ?
          IFolderViewHost ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IFolderViewHost_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0024 *
      ;* [local] *
      if (_WIN32_IE ge _WIN32_IE_IE70)
        externdef __MIDL_itf_shobjidl_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IAccessibleObject_INTERFACE_DEFINED__
          __IAccessibleObject_INTERFACE_DEFINED__ equ <>
          ;* interface IAccessibleObject *
          ;* [object][uuid] *
          externdef IID_IAccessibleObject:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IAccessibleObjectVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IAccessibleObjectVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IAccessibleObject, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IAccessibleObject
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IAccessibleObject
              DECLSPEC_XFGVIRT(IAccessibleObject, SetAccessibleName)
              STD_METHOD SetAccessibleName, :ptr IAccessibleObject, :LPCWSTR
              ;* [string][in] *
              ??Interface equ <>
              END_INTERFACE
            IAccessibleObjectVtbl ends
            IAccessibleObject struct
              lpVtbl POINTER ?
            IAccessibleObject ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IAccessibleObject_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_shobjidl_0000_0025 *
        ;* [local] *
      endif
      ; (_WIN32_IE >= _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IResultsFolder_INTERFACE_DEFINED__
        __IResultsFolder_INTERFACE_DEFINED__ equ <>
        ;* interface IResultsFolder *
        ;* [unique][uuid][object] *
        externdef IID_IResultsFolder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IResultsFolderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IResultsFolderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IResultsFolder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IResultsFolder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IResultsFolder
            DECLSPEC_XFGVIRT(IResultsFolder, AddItem)
            STD_METHOD AddItem, :ptr IResultsFolder, :ptr IShellItem
            ;* [in] *
            DECLSPEC_XFGVIRT(IResultsFolder, AddIDList)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD AddIDList, :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
            DECLSPEC_XFGVIRT(IResultsFolder, RemoveItem)
            STD_METHOD RemoveItem, :ptr IResultsFolder, :ptr IShellItem
            ;* [in] *
            DECLSPEC_XFGVIRT(IResultsFolder, RemoveIDList)
            STD_METHOD RemoveIDList, :ptr IResultsFolder, :PCIDLIST_ABSOLUTE
            ;* [in] *
            DECLSPEC_XFGVIRT(IResultsFolder, RemoveAll)
            STD_METHOD RemoveAll, :ptr IResultsFolder
            ??Interface equ <>
            END_INTERFACE
          IResultsFolderVtbl ends
          IResultsFolder struct
            lpVtbl POINTER ?
          IResultsFolder ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IResultsFolder_RemoteAddIDList_Proxy proto WIN_STD_CALL_CONV :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
        ;* [out] *
        IResultsFolder_RemoteAddIDList_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IResultsFolder_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0026 *
      ;* [local] *
      if (_WIN32_IE ge _WIN32_IE_IE70)
      endif
      ; (_WIN32_IE >= _WIN32_IE_IE70)
    endif
    ; NTDDI_WINXP || (_WIN32_IE >= _WIN32_IE_IE70)
    ACDD_VISIBLE equ 0001h
    externdef __MIDL_itf_shobjidl_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IAutoCompleteDropDown_INTERFACE_DEFINED__
      __IAutoCompleteDropDown_INTERFACE_DEFINED__ equ <>
      ;* interface IAutoCompleteDropDown *
      ;* [unique][object][uuid] *
      externdef IID_IAutoCompleteDropDown:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAutoCompleteDropDownVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAutoCompleteDropDownVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IAutoCompleteDropDown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IAutoCompleteDropDown
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IAutoCompleteDropDown
          DECLSPEC_XFGVIRT(IAutoCompleteDropDown, GetDropDownStatus)
          ;* [out] *
          STD_METHOD GetDropDownStatus, :ptr IAutoCompleteDropDown, :ptr DWORD, :ptr LPWSTR
          ;* [string][out] *
          DECLSPEC_XFGVIRT(IAutoCompleteDropDown, ResetEnumerator)
          STD_METHOD ResetEnumerator, :ptr IAutoCompleteDropDown
          ??Interface equ <>
          END_INTERFACE
        IAutoCompleteDropDownVtbl ends
        IAutoCompleteDropDown struct
          lpVtbl POINTER ?
        IAutoCompleteDropDown ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IAutoCompleteDropDown_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0027 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_WINXP)
      PROPSTR_EXTENSIONCOMPLETIONSTATE equ <L("ExtensionCompletionState")>
      tagCDBURNINGEXTENSIONRET typedef SDWORD
      CDBE_RET_DEFAULT equ 0
      CDBE_RET_DONTRUNOTHEREXTS equ 1h
      CDBE_RET_STOPWIZARD equ 2h

      SID_CDWizardHost equ <IID_ICDBurnExt>
      ;* [v1_enum] *
      _CDBE_ACTIONS typedef SDWORD
      CDBE_TYPE_MUSIC equ 1h
      CDBE_TYPE_DATA equ 2h
      CDBE_TYPE_ALL equ 0ffffffffh

      CDBE_ACTIONS typedef DWORD
      externdef __MIDL_itf_shobjidl_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICDBurnExt_INTERFACE_DEFINED__
        __ICDBurnExt_INTERFACE_DEFINED__ equ <>
        ;* interface ICDBurnExt *
        ;* [object][uuid] *
        externdef IID_ICDBurnExt:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICDBurnExtVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICDBurnExtVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICDBurnExt, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICDBurnExt
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICDBurnExt
            DECLSPEC_XFGVIRT(ICDBurnExt, GetSupportedActionTypes)
            STD_METHOD GetSupportedActionTypes, :ptr ICDBurnExt, :ptr CDBE_ACTIONS
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          ICDBurnExtVtbl ends
          ICDBurnExt struct
            lpVtbl POINTER ?
          ICDBurnExt ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ICDBurnExt_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0028 *
      ;* [local] *
    endif
    ; NTDDI_WINXP
    externdef __MIDL_itf_shobjidl_0000_0028_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0028_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumReadyCallback_INTERFACE_DEFINED__
      __IEnumReadyCallback_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumReadyCallback *
      ;* [local][unique][object][uuid] *
      externdef IID_IEnumReadyCallback:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumReadyCallbackVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumReadyCallbackVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumReadyCallback, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumReadyCallback
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumReadyCallback
          DECLSPEC_XFGVIRT(IEnumReadyCallback, EnumReady)
          STD_METHOD EnumReady, :ptr IEnumReadyCallback
          ??Interface equ <>
          END_INTERFACE
        IEnumReadyCallbackVtbl ends
        IEnumReadyCallback struct
          lpVtbl POINTER ?
        IEnumReadyCallback ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IEnumReadyCallback_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumerableView_INTERFACE_DEFINED__
      __IEnumerableView_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumerableView *
      ;* [object][local][uuid] *
      externdef IID_IEnumerableView:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumerableViewVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumerableViewVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumerableView, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumerableView
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumerableView
          DECLSPEC_XFGVIRT(IEnumerableView, SetEnumReadyCallback)
          ;* [annotation][in] *
          STD_METHOD SetEnumReadyCallback, :ptr IEnumerableView, :ptr IEnumReadyCallback
          DECLSPEC_XFGVIRT(IEnumerableView, CreateEnumIDListFromContents)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD CreateEnumIDListFromContents, :ptr IEnumerableView, :PCIDLIST_ABSOLUTE, :DWORD, :ptr ptr IEnumIDList
          ??Interface equ <>
          END_INTERFACE
        IEnumerableViewVtbl ends
        IEnumerableView struct
          lpVtbl POINTER ?
        IEnumerableView ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IEnumerableView_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0030 *
    ;* [local] *
    SID_EnumerableView equ <IID_IEnumerableView>
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInsertItem_INTERFACE_DEFINED__
        __IInsertItem_INTERFACE_DEFINED__ equ <>
        ;* interface IInsertItem *
        ;* [local][object][uuid] *
        externdef IID_IInsertItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInsertItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInsertItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInsertItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInsertItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInsertItem
            DECLSPEC_XFGVIRT(IInsertItem, InsertItem)
            ;* [annotation][in] *
            STD_METHOD InsertItem, :ptr IInsertItem, :PCUIDLIST_RELATIVE
            ??Interface equ <>
            END_INTERFACE
          IInsertItemVtbl ends
          IInsertItem struct
            lpVtbl POINTER ?
          IInsertItem ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IInsertItem_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0031 *
      ;* [local] *
      if (NTDDI_VERSION ge NTDDI_WINXP)
        externdef __MIDL_itf_shobjidl_0000_0031_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_0000_0031_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IFolderBandPriv_INTERFACE_DEFINED__
          __IFolderBandPriv_INTERFACE_DEFINED__ equ <>
          ;* interface IFolderBandPriv *
          ;* [unique][uuid][object] *
          externdef IID_IFolderBandPriv:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IFolderBandPrivVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IFolderBandPrivVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IFolderBandPriv, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IFolderBandPriv
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IFolderBandPriv
              DECLSPEC_XFGVIRT(IFolderBandPriv, SetCascade)
              STD_METHOD SetCascade, :ptr IFolderBandPriv, :BOOL
              ;* [in] *
              DECLSPEC_XFGVIRT(IFolderBandPriv, SetAccelerators)
              STD_METHOD SetAccelerators, :ptr IFolderBandPriv, :BOOL
              ;* [in] *
              DECLSPEC_XFGVIRT(IFolderBandPriv, SetNoIcons)
              STD_METHOD SetNoIcons, :ptr IFolderBandPriv, :BOOL
              ;* [in] *
              DECLSPEC_XFGVIRT(IFolderBandPriv, SetNoText)
              STD_METHOD SetNoText, :ptr IFolderBandPriv, :BOOL
              ;* [in] *
              ??Interface equ <>
              END_INTERFACE
            IFolderBandPrivVtbl ends
            IFolderBandPriv struct
              lpVtbl POINTER ?
            IFolderBandPriv ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IFolderBandPriv_INTERFACE_DEFINED__ *
        endif
        ifndef __IImageRecompress_INTERFACE_DEFINED__
          __IImageRecompress_INTERFACE_DEFINED__ equ <>
          ;* interface IImageRecompress *
          ;* [object][unique][uuid] *
          externdef IID_IImageRecompress:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IImageRecompressVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IImageRecompressVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IImageRecompress, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IImageRecompress
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IImageRecompress
              DECLSPEC_XFGVIRT(IImageRecompress, RecompressImage)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD RecompressImage, :ptr IImageRecompress, :ptr IShellItem, :SDWORD, :SDWORD, :SDWORD, :ptr IStorage, :ptr ptr IStream
              ;* [out] *
              ??Interface equ <>
              END_INTERFACE
            IImageRecompressVtbl ends
            IImageRecompress struct
              lpVtbl POINTER ?
            IImageRecompress ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IImageRecompress_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_shobjidl_0000_0033 *
        ;* [local] *
      endif
      ; NTDDI_WINXP
    endif
    ; NTDDI_WINXP) || (_WIN32_IE >= _WIN32_IE_IE70)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0033_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0033_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialogControlEvents_INTERFACE_DEFINED__
        __IFileDialogControlEvents_INTERFACE_DEFINED__ equ <>
        ;* interface IFileDialogControlEvents *
        ;* [unique][object][uuid] *
        externdef IID_IFileDialogControlEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogControlEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogControlEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IFileDialogControlEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileDialogControlEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileDialogControlEvents
            DECLSPEC_XFGVIRT(IFileDialogControlEvents, OnItemSelected)
            ;* [in] *
            ;* [in] *
            STD_METHOD OnItemSelected, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialogControlEvents, OnButtonClicked)
            ;* [in] *
            STD_METHOD OnButtonClicked, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialogControlEvents, OnCheckButtonToggled)
            ;* [in] *
            ;* [in] *
            STD_METHOD OnCheckButtonToggled, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialogControlEvents, OnControlActivating)
            ;* [in] *
            STD_METHOD OnControlActivating, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IFileDialogControlEventsVtbl ends
          IFileDialogControlEvents struct
            lpVtbl POINTER ?
          IFileDialogControlEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IFileDialogControlEvents_INTERFACE_DEFINED__ *
      endif
      ifndef __IFileDialog2_INTERFACE_DEFINED__
        __IFileDialog2_INTERFACE_DEFINED__ equ <>
        ;* interface IFileDialog2 *
        ;* [unique][object][uuid] *
        externdef IID_IFileDialog2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialog2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialog2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IFileDialog2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileDialog2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileDialog2
            DECLSPEC_XFGVIRT(IModalWindow, Show)
            ;* [local] *
            ;* [annotation][unique][in] *
            STD_METHOD Show, :ptr IFileDialog2, :HWND
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypes)
            ;* [in] *
            STD_METHOD SetFileTypes, :ptr IFileDialog2, :UINT, :ptr COMDLG_FILTERSPEC
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypeIndex)
            STD_METHOD SetFileTypeIndex, :ptr IFileDialog2, :UINT
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, GetFileTypeIndex)
            STD_METHOD GetFileTypeIndex, :ptr IFileDialog2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IFileDialog, Advise)
            ;* [in] *
            STD_METHOD Advise, :ptr IFileDialog2, :ptr IFileDialogEvents, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IFileDialog, Unadvise)
            STD_METHOD Unadvise, :ptr IFileDialog2, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetOptions)
            STD_METHOD SetOptions, :ptr IFileDialog2, :FILEOPENDIALOGOPTIONS
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, GetOptions)
            STD_METHOD GetOptions, :ptr IFileDialog2, :ptr FILEOPENDIALOGOPTIONS
            ;* [out] *
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultFolder)
            STD_METHOD SetDefaultFolder, :ptr IFileDialog2, :ptr IShellItem
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetFolder)
            STD_METHOD SetFolder, :ptr IFileDialog2, :ptr IShellItem
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, GetFolder)
            STD_METHOD GetFolder, :ptr IFileDialog2, :ptr ptr IShellItem
            ;* [out] *
            DECLSPEC_XFGVIRT(IFileDialog, GetCurrentSelection)
            STD_METHOD GetCurrentSelection, :ptr IFileDialog2, :ptr ptr IShellItem
            ;* [out] *
            DECLSPEC_XFGVIRT(IFileDialog, SetFileName)
            STD_METHOD SetFileName, :ptr IFileDialog2, :LPCWSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IFileDialog, GetFileName)
            STD_METHOD GetFileName, :ptr IFileDialog2, :ptr LPWSTR
            ;* [string][out] *
            DECLSPEC_XFGVIRT(IFileDialog, SetTitle)
            STD_METHOD SetTitle, :ptr IFileDialog2, :LPCWSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetOkButtonLabel)
            STD_METHOD SetOkButtonLabel, :ptr IFileDialog2, :LPCWSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetFileNameLabel)
            STD_METHOD SetFileNameLabel, :ptr IFileDialog2, :LPCWSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IFileDialog, GetResult)
            STD_METHOD GetResult, :ptr IFileDialog2, :ptr ptr IShellItem
            ;* [out] *
            DECLSPEC_XFGVIRT(IFileDialog, AddPlace)
            ;* [in] *
            STD_METHOD AddPlace, :ptr IFileDialog2, :ptr IShellItem, :FDAP
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultExtension)
            STD_METHOD SetDefaultExtension, :ptr IFileDialog2, :LPCWSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IFileDialog, Close)
            STD_METHOD Close, :ptr IFileDialog2, :HRESULT
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, SetClientGuid)
            STD_METHOD SetClientGuid, :ptr IFileDialog2, :REFGUID
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog, ClearClientData)
            STD_METHOD ClearClientData, :ptr IFileDialog2
            DECLSPEC_XFGVIRT(IFileDialog, SetFilter)
            STD_METHOD SetFilter, :ptr IFileDialog2, :ptr IShellItemFilter
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog2, SetCancelButtonLabel)
            STD_METHOD SetCancelButtonLabel, :ptr IFileDialog2, :LPCWSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IFileDialog2, SetNavigationRoot)
            STD_METHOD SetNavigationRoot, :ptr IFileDialog2, :ptr IShellItem
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IFileDialog2Vtbl ends
          IFileDialog2 struct
            lpVtbl POINTER ?
          IFileDialog2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IFileDialog2_INTERFACE_DEFINED__ *
      endif
      ifndef __IApplicationAssociationRegistrationUI_INTERFACE_DEFINED__
        __IApplicationAssociationRegistrationUI_INTERFACE_DEFINED__ equ <>
        ;* interface IApplicationAssociationRegistrationUI *
        ;* [unique][uuid][object] *
        externdef IID_IApplicationAssociationRegistrationUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationAssociationRegistrationUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationAssociationRegistrationUIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IApplicationAssociationRegistrationUI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationAssociationRegistrationUI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationAssociationRegistrationUI
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistrationUI, LaunchAdvancedAssociationUI)
            STD_METHOD LaunchAdvancedAssociationUI, :ptr IApplicationAssociationRegistrationUI, :LPCWSTR
            ;* [string][in] *
            ??Interface equ <>
            END_INTERFACE
          IApplicationAssociationRegistrationUIVtbl ends
          IApplicationAssociationRegistrationUI struct
            lpVtbl POINTER ?
          IApplicationAssociationRegistrationUI ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IApplicationAssociationRegistrationUI_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0036 *
      ;* [local] *
    endif
    ; NTDDI_VISTA
    externdef __MIDL_itf_shobjidl_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellRunDll_INTERFACE_DEFINED__
      __IShellRunDll_INTERFACE_DEFINED__ equ <>
      ;* interface IShellRunDll *
      ;* [local][ref][object][uuid] *
      externdef IID_IShellRunDll:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellRunDllVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellRunDllVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IShellRunDll, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellRunDll
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellRunDll
          DECLSPEC_XFGVIRT(IShellRunDll, Run)
          ;* [annotation][string][in] *
          STD_METHOD Run, :ptr IShellRunDll, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IShellRunDllVtbl ends
        IShellRunDll struct
          lpVtbl POINTER ?
        IShellRunDll ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IShellRunDll_INTERFACE_DEFINED__ *
    endif
    ifndef __IPreviousVersionsInfo_INTERFACE_DEFINED__
      __IPreviousVersionsInfo_INTERFACE_DEFINED__ equ <>
      ;* interface IPreviousVersionsInfo *
      ;* [local][unique][uuid][object] *
      externdef IID_IPreviousVersionsInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPreviousVersionsInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPreviousVersionsInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPreviousVersionsInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPreviousVersionsInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPreviousVersionsInfo
          DECLSPEC_XFGVIRT(IPreviousVersionsInfo, AreSnapshotsAvailable)
          ;* [annotation][string][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD AreSnapshotsAvailable, :ptr IPreviousVersionsInfo, :LPCWSTR, :BOOL, :ptr BOOL
          ??Interface equ <>
          END_INTERFACE
        IPreviousVersionsInfoVtbl ends
        IPreviousVersionsInfo struct
          lpVtbl POINTER ?
        IPreviousVersionsInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPreviousVersionsInfo_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0038 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IUseToBrowseItem_INTERFACE_DEFINED__
        __IUseToBrowseItem_INTERFACE_DEFINED__ equ <>
        ;* interface IUseToBrowseItem *
        ;* [unique][uuid][object] *
        externdef IID_IUseToBrowseItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUseToBrowseItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUseToBrowseItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IUseToBrowseItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUseToBrowseItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUseToBrowseItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IUseToBrowseItem, :ptr PIDLIST_ABSOLUTE
            ;* [out] *
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IUseToBrowseItem, :ptr ptr IShellItem
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IUseToBrowseItemVtbl ends
          IUseToBrowseItem struct
            lpVtbl POINTER ?
          IUseToBrowseItem ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IUseToBrowseItem_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0039 *
      ;* [local] *
    endif
    ; NTDDI_VISTA
    DEFINE_GUID SID_SCommandBarState, 0B99EAA5Ch, 3850h, 4400h, 0BCh, 33h, 2Ch, 0E5h, 34h, 04h, 8Bh, 0F8h
    externdef __MIDL_itf_shobjidl_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INameSpaceTreeControl2_INTERFACE_DEFINED__
      __INameSpaceTreeControl2_INTERFACE_DEFINED__ equ <>
      ;* interface INameSpaceTreeControl2 *
      ;* [uuid][object] *
      ;* [v1_enum] *
      NSTCSTYLE2 typedef SDWORD
      NSTCS2_DEFAULT equ 0
      NSTCS2_INTERRUPTNOTIFICATIONS equ 1h
      NSTCS2_SHOWNULLSPACEMENU equ 2h
      NSTCS2_DISPLAYPADDING equ 4h
      NSTCS2_DISPLAYPINNEDONLY equ 8h
      NTSCS2_NOSINGLETONAUTOEXPAND equ 10h
      NTSCS2_NEVERINSERTNONENUMERATED equ 20h

      DEFINE_ENUM_FLAG_OPERATORS(NSTCSTYLE2)
      externdef IID_INameSpaceTreeControl2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeControl2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeControl2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControl2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INameSpaceTreeControl2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INameSpaceTreeControl2
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, Initialize)
          ;* [in] *
          ;* [unique][in] *
          STD_METHOD Initialize, :ptr INameSpaceTreeControl2, :HWND, :ptr RECT, :NSTCSTYLE
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, TreeAdvise)
          ;* [in] *
          STD_METHOD TreeAdvise, :ptr INameSpaceTreeControl2, :ptr IUnknown, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, TreeUnadvise)
          STD_METHOD TreeUnadvise, :ptr INameSpaceTreeControl2, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, AppendRoot)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AppendRoot, :ptr INameSpaceTreeControl2, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, InsertRoot)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD InsertRoot, :ptr INameSpaceTreeControl2, :SDWORD, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, RemoveRoot)
          STD_METHOD RemoveRoot, :ptr INameSpaceTreeControl2, :ptr IShellItem
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, RemoveAllRoots)
          STD_METHOD RemoveAllRoots, :ptr INameSpaceTreeControl2
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetRootItems)
          STD_METHOD GetRootItems, :ptr INameSpaceTreeControl2, :ptr ptr IShellItemArray
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, SetItemState)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetItemState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetItemState)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetItemState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :NSTCITEMSTATE, :ptr NSTCITEMSTATE
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetSelectedItems)
          STD_METHOD GetSelectedItems, :ptr INameSpaceTreeControl2, :ptr ptr IShellItemArray
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetItemCustomState)
          ;* [in] *
          STD_METHOD GetItemCustomState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :ptr SDWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, SetItemCustomState)
          ;* [in] *
          STD_METHOD SetItemCustomState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :SDWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, EnsureItemVisible)
          STD_METHOD EnsureItemVisible, :ptr INameSpaceTreeControl2, :ptr IShellItem
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, SetTheme)
          STD_METHOD SetTheme, :ptr INameSpaceTreeControl2, :LPCWSTR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetNextItem)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD GetNextItem, :ptr INameSpaceTreeControl2, :ptr IShellItem, :NSTCGNI, :ptr ptr IShellItem
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, HitTest)
          ;* [in] *
          STD_METHOD HitTest, :ptr INameSpaceTreeControl2, :ptr POINT, :ptr ptr IShellItem
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetItemRect)
          ;* [in] *
          STD_METHOD GetItemRect, :ptr INameSpaceTreeControl2, :ptr IShellItem, :ptr RECT
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, CollapseAll)
          STD_METHOD CollapseAll, :ptr INameSpaceTreeControl2
          DECLSPEC_XFGVIRT(INameSpaceTreeControl2, SetControlStyle)
          ;* [in] *
          STD_METHOD SetControlStyle, :ptr INameSpaceTreeControl2, :NSTCSTYLE, :NSTCSTYLE
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl2, GetControlStyle)
          ;* [in] *
          STD_METHOD GetControlStyle, :ptr INameSpaceTreeControl2, :NSTCSTYLE, :ptr NSTCSTYLE
          ;* [out] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl2, SetControlStyle2)
          ;* [in] *
          STD_METHOD SetControlStyle2, :ptr INameSpaceTreeControl2, :NSTCSTYLE2, :NSTCSTYLE2
          ;* [in] *
          DECLSPEC_XFGVIRT(INameSpaceTreeControl2, GetControlStyle2)
          ;* [in] *
          STD_METHOD GetControlStyle2, :ptr INameSpaceTreeControl2, :NSTCSTYLE2, :ptr NSTCSTYLE2
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeControl2Vtbl ends
        INameSpaceTreeControl2 struct
          lpVtbl POINTER ?
        INameSpaceTreeControl2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __INameSpaceTreeControl2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0040 *
    ;* [local] *
    NSTCS2_ALLMASK equ <(NSTCS2_INTERRUPTNOTIFICATIONS or NSTCS2_SHOWNULLSPACEMENU or NSTCS2_DISPLAYPADDING)>
    ISLBUTTON macro x
      exitm <(NSTCECT_LBUTTON == ((x) and NSTCECT_BUTTON))>
    endm
    ISMBUTTON macro x
      exitm <(NSTCECT_MBUTTON == ((x) and NSTCECT_BUTTON))>
    endm
    ISRBUTTON macro x
      exitm <(NSTCECT_RBUTTON == ((x) and NSTCECT_BUTTON))>
    endm
    ISDBLCLICK macro x
      exitm <(NSTCECT_DBLCLICK == ((x) and NSTCECT_DBLCLICK))>
    endm
    externdef __MIDL_itf_shobjidl_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INameSpaceTreeControlEvents_INTERFACE_DEFINED__
      __INameSpaceTreeControlEvents_INTERFACE_DEFINED__ equ <>
      ;* interface INameSpaceTreeControlEvents *
      ;* [local][uuid][object] *
      ;* [v1_enum] *
      _NSTCEHITTEST typedef SDWORD
      NSTCEHT_NOWHERE equ 1h
      NSTCEHT_ONITEMICON equ 2h
      NSTCEHT_ONITEMLABEL equ 4h
      NSTCEHT_ONITEMINDENT equ 8h
      NSTCEHT_ONITEMBUTTON equ 10h
      NSTCEHT_ONITEMRIGHT equ 20h
      NSTCEHT_ONITEMSTATEICON equ 40h
      NSTCEHT_ONITEM equ 46h
      NSTCEHT_ONITEMTABBUTTON equ 1000h

      NSTCEHITTEST typedef DWORD
      ;* [v1_enum] *
      _NSTCECLICKTYPE typedef SDWORD
      NSTCECT_LBUTTON equ 1h
      NSTCECT_MBUTTON equ 2h
      NSTCECT_RBUTTON equ 3h
      NSTCECT_BUTTON equ 3h
      NSTCECT_DBLCLICK equ 4h

      NSTCECLICKTYPE typedef DWORD
      externdef IID_INameSpaceTreeControlEvents:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeControlEventsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeControlEventsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControlEvents, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INameSpaceTreeControlEvents
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INameSpaceTreeControlEvents
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnItemClick)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnItemClick, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :NSTCEHITTEST, :NSTCECLICKTYPE
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnPropertyItemCommit)
          ;* [annotation][in] *
          STD_METHOD OnPropertyItemCommit, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnItemStateChanging)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnItemStateChanging, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnItemStateChanged)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnItemStateChanged, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnSelectionChanged)
          ;* [annotation][in] *
          STD_METHOD OnSelectionChanged, :ptr INameSpaceTreeControlEvents, :ptr IShellItemArray
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnKeyboardInput)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnKeyboardInput, :ptr INameSpaceTreeControlEvents, :UINT, :WPARAM, :LPARAM
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnBeforeExpand)
          ;* [annotation][in] *
          STD_METHOD OnBeforeExpand, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnAfterExpand)
          ;* [annotation][in] *
          STD_METHOD OnAfterExpand, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnBeginLabelEdit)
          ;* [annotation][in] *
          STD_METHOD OnBeginLabelEdit, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnEndLabelEdit)
          ;* [annotation][in] *
          STD_METHOD OnEndLabelEdit, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnGetToolTip)
          ;* [annotation][in] *
          ;* [annotation][size_is][string][out] *
          ;* [annotation][in] *
          STD_METHOD OnGetToolTip, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :LPWSTR, :SDWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnBeforeItemDelete)
          ;* [annotation][in] *
          STD_METHOD OnBeforeItemDelete, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnItemAdded)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnItemAdded, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :BOOL
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnItemDeleted)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnItemDeleted, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :BOOL
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnBeforeContextMenu)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD OnBeforeContextMenu, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnAfterContextMenu)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD OnAfterContextMenu, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :ptr IContextMenu, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnBeforeStateImageChange)
          ;* [annotation][in] *
          STD_METHOD OnBeforeStateImageChange, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControlEvents, OnGetDefaultIconIndex)
          ;* [annotation][in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD OnGetDefaultIconIndex, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :ptr SDWORD, :ptr SDWORD
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeControlEventsVtbl ends
        INameSpaceTreeControlEvents struct
          lpVtbl POINTER ?
        INameSpaceTreeControlEvents ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __INameSpaceTreeControlEvents_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0041 *
    ;* [local] *
    NSTCDHPOS_ONTOP equ -1
    externdef __MIDL_itf_shobjidl_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INameSpaceTreeControlDropHandler_INTERFACE_DEFINED__
      __INameSpaceTreeControlDropHandler_INTERFACE_DEFINED__ equ <>
      ;* interface INameSpaceTreeControlDropHandler *
      ;* [local][uuid][object] *
      externdef IID_INameSpaceTreeControlDropHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeControlDropHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeControlDropHandlerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControlDropHandler, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INameSpaceTreeControlDropHandler
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INameSpaceTreeControlDropHandler
          DECLSPEC_XFGVIRT(INameSpaceTreeControlDropHandler, OnDragEnter)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          STD_METHOD OnDragEnter, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :BOOL, :DWORD, :ptr DWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControlDropHandler, OnDragOver)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          STD_METHOD OnDragOver, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :DWORD, :ptr DWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControlDropHandler, OnDragPosition)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnDragPosition, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :SDWORD, :SDWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControlDropHandler, OnDrop)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          STD_METHOD OnDrop, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :SDWORD, :DWORD, :ptr DWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControlDropHandler, OnDropPosition)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnDropPosition, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :SDWORD, :SDWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControlDropHandler, OnDragLeave)
          ;* [annotation][unique][in] *
          STD_METHOD OnDragLeave, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeControlDropHandlerVtbl ends
        INameSpaceTreeControlDropHandler struct
          lpVtbl POINTER ?
        INameSpaceTreeControlDropHandler ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __INameSpaceTreeControlDropHandler_INTERFACE_DEFINED__ *
    endif
    ifndef __INameSpaceTreeAccessible_INTERFACE_DEFINED__
      __INameSpaceTreeAccessible_INTERFACE_DEFINED__ equ <>
      ;* interface INameSpaceTreeAccessible *
      ;* [local][uuid][object] *
      externdef IID_INameSpaceTreeAccessible:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeAccessibleVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeAccessibleVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr INameSpaceTreeAccessible, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INameSpaceTreeAccessible
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INameSpaceTreeAccessible
          DECLSPEC_XFGVIRT(INameSpaceTreeAccessible, OnGetDefaultAccessibilityAction)
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD OnGetDefaultAccessibilityAction, :ptr INameSpaceTreeAccessible, :ptr IShellItem, :ptr BSTR
          DECLSPEC_XFGVIRT(INameSpaceTreeAccessible, OnDoDefaultAccessibilityAction)
          ;* [annotation][in] *
          STD_METHOD OnDoDefaultAccessibilityAction, :ptr INameSpaceTreeAccessible, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeAccessible, OnGetAccessibilityRole)
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD OnGetAccessibilityRole, :ptr INameSpaceTreeAccessible, :ptr IShellItem, :ptr VARIANT
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeAccessibleVtbl ends
        INameSpaceTreeAccessible struct
          lpVtbl POINTER ?
        INameSpaceTreeAccessible ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __INameSpaceTreeAccessible_INTERFACE_DEFINED__ *
    endif
    ifndef __INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED__
      __INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED__ equ <>
      ;* interface INameSpaceTreeControlCustomDraw *
      ;* [local][uuid][object] *
      NSTCCUSTOMDRAW struct
        psi POINTER ?
        uItemState DWORD ?
        nstcis NSTCITEMSTATE ?
        pszText =POINTER ?
        iImage SDWORD ?
        himl HIMAGELIST ?
        iLevel SDWORD ?
        iIndent SDWORD ?
      NSTCCUSTOMDRAW ends
      externdef IID_INameSpaceTreeControlCustomDraw:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeControlCustomDrawVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeControlCustomDrawVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControlCustomDraw, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INameSpaceTreeControlCustomDraw
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INameSpaceTreeControlCustomDraw
          DECLSPEC_XFGVIRT(INameSpaceTreeControlCustomDraw, PrePaint)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD PrePaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT, :ptr LRESULT
          DECLSPEC_XFGVIRT(INameSpaceTreeControlCustomDraw, PostPaint)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PostPaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT
          DECLSPEC_XFGVIRT(INameSpaceTreeControlCustomDraw, ItemPrePaint)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          ;* [annotation][out][in] *
          ;* [annotation][out] *
          STD_METHOD ItemPrePaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT, :ptr NSTCCUSTOMDRAW, :ptr COLORREF, :ptr COLORREF, :ptr LRESULT
          DECLSPEC_XFGVIRT(INameSpaceTreeControlCustomDraw, ItemPostPaint)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD ItemPostPaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT, :ptr NSTCCUSTOMDRAW
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeControlCustomDrawVtbl ends
        INameSpaceTreeControlCustomDraw struct
          lpVtbl POINTER ?
        INameSpaceTreeControlCustomDraw ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0044 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0044_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0044_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ITrayDeskBand_INTERFACE_DEFINED__
        __ITrayDeskBand_INTERFACE_DEFINED__ equ <>
        ;* interface ITrayDeskBand *
        ;* [unique][uuid][object] *
        externdef IID_ITrayDeskBand:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITrayDeskBandVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITrayDeskBandVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ITrayDeskBand, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ITrayDeskBand
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ITrayDeskBand
            DECLSPEC_XFGVIRT(ITrayDeskBand, ShowDeskBand)
            STD_METHOD ShowDeskBand, :ptr ITrayDeskBand, :REFCLSID
            ;* [in] *
            DECLSPEC_XFGVIRT(ITrayDeskBand, HideDeskBand)
            STD_METHOD HideDeskBand, :ptr ITrayDeskBand, :REFCLSID
            ;* [in] *
            DECLSPEC_XFGVIRT(ITrayDeskBand, IsDeskBandShown)
            STD_METHOD IsDeskBandShown, :ptr ITrayDeskBand, :REFCLSID
            ;* [in] *
            DECLSPEC_XFGVIRT(ITrayDeskBand, DeskBandRegistrationChanged)
            STD_METHOD DeskBandRegistrationChanged, :ptr ITrayDeskBand
            ??Interface equ <>
            END_INTERFACE
          ITrayDeskBandVtbl ends
          ITrayDeskBand struct
            lpVtbl POINTER ?
          ITrayDeskBand ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ITrayDeskBand_INTERFACE_DEFINED__ *
      endif
      ifndef __IBandHost_INTERFACE_DEFINED__
        __IBandHost_INTERFACE_DEFINED__ equ <>
        ;* interface IBandHost *
        ;* [unique][object][uuid] *
        externdef IID_IBandHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBandHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBandHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBandHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBandHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBandHost
            DECLSPEC_XFGVIRT(IBandHost, CreateBand)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateBand, :ptr IBandHost, :REFCLSID, :BOOL, :BOOL, :REFIID, :ptr ptr
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IBandHost, SetBandAvailability)
            ;* [in] *
            STD_METHOD SetBandAvailability, :ptr IBandHost, :REFCLSID, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IBandHost, DestroyBand)
            STD_METHOD DestroyBand, :ptr IBandHost, :REFCLSID
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IBandHostVtbl ends
          IBandHost struct
            lpVtbl POINTER ?
          IBandHost ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IBandHost_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0046 *
      ;* [local] *
      SID_SBandHost equ <IID_IBandHost>
    endif
    ; NTDDI_VISTA
    externdef __MIDL_itf_shobjidl_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IComputerInfoChangeNotify_INTERFACE_DEFINED__
      __IComputerInfoChangeNotify_INTERFACE_DEFINED__ equ <>
      ;* interface IComputerInfoChangeNotify *
      ;* [unique][uuid][object] *
      externdef IID_IComputerInfoChangeNotify:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IComputerInfoChangeNotifyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IComputerInfoChangeNotifyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IComputerInfoChangeNotify, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IComputerInfoChangeNotify
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IComputerInfoChangeNotify
          DECLSPEC_XFGVIRT(IComputerInfoChangeNotify, ComputerInfoChanged)
          STD_METHOD ComputerInfoChanged, :ptr IComputerInfoChangeNotify
          ??Interface equ <>
          END_INTERFACE
        IComputerInfoChangeNotifyVtbl ends
        IComputerInfoChangeNotify struct
          lpVtbl POINTER ?
        IComputerInfoChangeNotify ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IComputerInfoChangeNotify_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0049 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_WIN7)
    endif
    ; NTDDI_WIN7
    externdef __MIDL_itf_shobjidl_0000_0049_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0049_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDesktopGadget_INTERFACE_DEFINED__
      __IDesktopGadget_INTERFACE_DEFINED__ equ <>
      ;* interface IDesktopGadget *
      ;* [uuid][object] *
      externdef IID_IDesktopGadget:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDesktopGadgetVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDesktopGadgetVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDesktopGadget, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDesktopGadget
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDesktopGadget
          DECLSPEC_XFGVIRT(IDesktopGadget, RunGadget)
          STD_METHOD RunGadget, :ptr IDesktopGadget, :LPCWSTR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IDesktopGadgetVtbl ends
        IDesktopGadget struct
          lpVtbl POINTER ?
        IDesktopGadget ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDesktopGadget_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0050 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
    endif
    ; NTDDI_WINTHRESHOLD
    externdef __MIDL_itf_shobjidl_0000_0050_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0050_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ShellObjects_LIBRARY_DEFINED__
      __ShellObjects_LIBRARY_DEFINED__ equ <>
      ;* library ShellObjects *
      ;* [version][lcid][uuid] *
      SID_PublishingWizard equ <CLSID_PublishingWizard>
      externdef LIBID_ShellObjects:IID
      externdef CLSID_QueryCancelAutoPlay:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_TimeCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_AlphabeticalCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_MergedCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ImageProperties:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_CDBurn:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_StartMenuPin:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_WebWizardHost:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_PublishDropTarget:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_PublishingWizard:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_InternetPrintOrdering:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FolderViewHost:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ExplorerBrowser:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ImageRecompress:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_TrayBandSiteService:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_TrayDeskBand:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_AttachmentServices:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DocPropShellExtension:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FSCopyHandler:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_PreviousVersions:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_NamespaceTreeControl:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_IENamespaceTreeControl:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ApplicationAssociationRegistrationUI:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DesktopGadget:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_AccessibilityDockingService:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ExecuteFolder:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_VirtualDesktopManager:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_StorageProviderBanners:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ;* __ShellObjects_LIBRARY_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0051 *
    ;* [local] *
    if (NTDDI_VERSION ge NTDDI_WIN7)
      if (_WIN32_IE ge _WIN32_IE_IE70)
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        endif
        ; __cplusplus && !CINTERFACE
      endif
      ; _WIN32_IE >= _WIN32_IE_IE70
    endif
    ; NTDDI_WIN7
    if (NTDDI_VERSION ge NTDDI_WIN8)
      ;* [v1_enum] *
      UNDOCK_REASON typedef SDWORD
      UR_RESOLUTION_CHANGE equ 0
      UR_MONITOR_DISCONNECT equ 1

      externdef __MIDL_itf_shobjidl_0000_0051_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0051_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAccessibilityDockingServiceCallback_INTERFACE_DEFINED__
        __IAccessibilityDockingServiceCallback_INTERFACE_DEFINED__ equ <>
        ;* interface IAccessibilityDockingServiceCallback *
        ;* [uuid][object] *
        externdef IID_IAccessibilityDockingServiceCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAccessibilityDockingServiceCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAccessibilityDockingServiceCallbackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAccessibilityDockingServiceCallback, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAccessibilityDockingServiceCallback
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAccessibilityDockingServiceCallback
            DECLSPEC_XFGVIRT(IAccessibilityDockingServiceCallback, Undocked)
            STD_METHOD Undocked, :ptr IAccessibilityDockingServiceCallback, :UNDOCK_REASON
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IAccessibilityDockingServiceCallbackVtbl ends
          IAccessibilityDockingServiceCallback struct
            lpVtbl POINTER ?
          IAccessibilityDockingServiceCallback ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IAccessibilityDockingServiceCallback_INTERFACE_DEFINED__ *
      endif
      ifndef __IAccessibilityDockingService_INTERFACE_DEFINED__
        __IAccessibilityDockingService_INTERFACE_DEFINED__ equ <>
        ;* interface IAccessibilityDockingService *
        ;* [uuid][object] *
        externdef IID_IAccessibilityDockingService:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAccessibilityDockingServiceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAccessibilityDockingServiceVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAccessibilityDockingService, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAccessibilityDockingService
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAccessibilityDockingService
            DECLSPEC_XFGVIRT(IAccessibilityDockingService, GetAvailableSize)
            ;* [in] *
            ;* [out] *
            STD_METHOD GetAvailableSize, :ptr IAccessibilityDockingService, :HMONITOR, :ptr UINT, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IAccessibilityDockingService, DockWindow)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD DockWindow, :ptr IAccessibilityDockingService, :HWND, :HMONITOR, :UINT, :ptr IAccessibilityDockingServiceCallback
            ;* [in] *
            DECLSPEC_XFGVIRT(IAccessibilityDockingService, UndockWindow)
            STD_METHOD UndockWindow, :ptr IAccessibilityDockingService, :HWND
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IAccessibilityDockingServiceVtbl ends
          IAccessibilityDockingService struct
            lpVtbl POINTER ?
          IAccessibilityDockingService ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IAccessibilityDockingService_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0053 *
      ;* [local] *
    endif
    ; NTDDI_WIN8
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      externdef __MIDL_itf_shobjidl_0000_0053_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0053_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IStorageProviderBanners_INTERFACE_DEFINED__
        __IStorageProviderBanners_INTERFACE_DEFINED__ equ <>
        ;* interface IStorageProviderBanners *
        ;* [unique][uuid][object] *
        externdef IID_IStorageProviderBanners:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IStorageProviderBannersVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IStorageProviderBannersVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IStorageProviderBanners, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IStorageProviderBanners
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IStorageProviderBanners
            DECLSPEC_XFGVIRT(IStorageProviderBanners, SetBanner)
            ;* [in] *
            ;* [in] *
            STD_METHOD SetBanner, :ptr IStorageProviderBanners, :LPCWSTR, :LPCWSTR, :LPCWSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IStorageProviderBanners, ClearBanner)
            ;* [in] *
            STD_METHOD ClearBanner, :ptr IStorageProviderBanners, :LPCWSTR, :LPCWSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IStorageProviderBanners, ClearAllBanners)
            STD_METHOD ClearAllBanners, :ptr IStorageProviderBanners, :LPCWSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IStorageProviderBanners, GetBanner)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetBanner, :ptr IStorageProviderBanners, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IStorageProviderBannersVtbl ends
          IStorageProviderBanners struct
            lpVtbl POINTER ?
          IStorageProviderBanners ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IStorageProviderBanners_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_shobjidl_0000_0054 *
      ;* [local] *
    endif
    ; NTDDI_WIN10_RS4
    externdef __MIDL_itf_shobjidl_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IStorageProviderCopyHook_INTERFACE_DEFINED__
      __IStorageProviderCopyHook_INTERFACE_DEFINED__ equ <>
      ;* interface IStorageProviderCopyHook *
      ;* [uuid][object] *
      externdef IID_IStorageProviderCopyHook:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStorageProviderCopyHookVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStorageProviderCopyHookVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IStorageProviderCopyHook, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IStorageProviderCopyHook
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IStorageProviderCopyHook
          DECLSPEC_XFGVIRT(IStorageProviderCopyHook, CopyCallback)
          ;* [unique][in] *
          ;* [in] *
          ;* [in] *
          ;* [string][in] *
          ;* [in] *
          ;* [string][unique][in] *
          ;* [in] *
          STD_METHOD CopyCallback, :ptr IStorageProviderCopyHook, :HWND, :UINT, :UINT, :LPCWSTR, :DWORD, :LPCWSTR, :DWORD, :ptr UINT
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IStorageProviderCopyHookVtbl ends
        IStorageProviderCopyHook struct
          lpVtbl POINTER ?
        IStorageProviderCopyHook ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IStorageProviderCopyHook_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shobjidl_0000_0055 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_shobjidl_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shobjidl_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  HBITMAP_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HBITMAP
  HBITMAP_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HBITMAP
  HICON_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HICON
  HICON_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HICON
  HMONITOR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMONITOR
  HMONITOR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMONITOR
  HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  PCIDLIST_ABSOLUTE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCIDLIST_ABSOLUTE
  PITEMID_CHILD_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PITEMID_CHILD
  HBITMAP_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HBITMAP
  HBITMAP_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HBITMAP
  HICON_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HICON
  HICON_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HICON
  HMONITOR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMONITOR
  HMONITOR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMONITOR
  HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  PCIDLIST_ABSOLUTE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCIDLIST_ABSOLUTE
  PITEMID_CHILD_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PITEMID_CHILD
  ;* [local] *
  IResultsFolder_AddIDList_Proxy proto WIN_STD_CALL_CONV :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
  ;* [annotation][out] *
  ;* [call_as] *
  IResultsFolder_AddIDList_Stub proto WIN_STD_CALL_CONV :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
