;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\shobjidl.h', last modified: 19/04/2018 21:54
;Creation parameters: 

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
endif
ifndef __shobjidl_h__
  __shobjidl_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IQueryCodePage_FWD_DEFINED__
    __IQueryCodePage_FWD_DEFINED__ equ <>
    ;IQueryCodePage typedef IQueryCodePage
    
  endif
  ifndef __IFolderViewOptions_FWD_DEFINED__
    __IFolderViewOptions_FWD_DEFINED__ equ <>
    ;IFolderViewOptions typedef IFolderViewOptions
    
  endif
  ifndef __IShellView3_FWD_DEFINED__
    __IShellView3_FWD_DEFINED__ equ <>
    ;IShellView3 typedef IShellView3
    
  endif
  ifndef __ISearchBoxInfo_FWD_DEFINED__
    __ISearchBoxInfo_FWD_DEFINED__ equ <>
    ;ISearchBoxInfo typedef ISearchBoxInfo
    
  endif
  ifndef __IVisualProperties_FWD_DEFINED__
    __IVisualProperties_FWD_DEFINED__ equ <>
    ;IVisualProperties typedef IVisualProperties
    
  endif
  ifndef __ICommDlgBrowser3_FWD_DEFINED__
    __ICommDlgBrowser3_FWD_DEFINED__ equ <>
    ;ICommDlgBrowser3 typedef ICommDlgBrowser3
    
  endif
  ifndef __IUserAccountChangeCallback_FWD_DEFINED__
    __IUserAccountChangeCallback_FWD_DEFINED__ equ <>
    ;IUserAccountChangeCallback typedef IUserAccountChangeCallback
    
  endif
  ifndef __IStreamAsync_FWD_DEFINED__
    __IStreamAsync_FWD_DEFINED__ equ <>
    ;IStreamAsync typedef IStreamAsync
    
  endif
  ifndef __IStreamUnbufferedInfo_FWD_DEFINED__
    __IStreamUnbufferedInfo_FWD_DEFINED__ equ <>
    ;IStreamUnbufferedInfo typedef IStreamUnbufferedInfo
    
  endif
  ifndef __IDragSourceHelper2_FWD_DEFINED__
    __IDragSourceHelper2_FWD_DEFINED__ equ <>
    ;IDragSourceHelper2 typedef IDragSourceHelper2
    
  endif
  ifndef __IHWEventHandler_FWD_DEFINED__
    __IHWEventHandler_FWD_DEFINED__ equ <>
    ;IHWEventHandler typedef IHWEventHandler
    
  endif
  ifndef __IHWEventHandler2_FWD_DEFINED__
    __IHWEventHandler2_FWD_DEFINED__ equ <>
    ;IHWEventHandler2 typedef IHWEventHandler2
    
  endif
  ifndef __IQueryCancelAutoPlay_FWD_DEFINED__
    __IQueryCancelAutoPlay_FWD_DEFINED__ equ <>
    ;IQueryCancelAutoPlay typedef IQueryCancelAutoPlay
    
  endif
  ifndef __IDynamicHWHandler_FWD_DEFINED__
    __IDynamicHWHandler_FWD_DEFINED__ equ <>
    ;IDynamicHWHandler typedef IDynamicHWHandler
    
  endif
  ifndef __IUserNotificationCallback_FWD_DEFINED__
    __IUserNotificationCallback_FWD_DEFINED__ equ <>
    ;IUserNotificationCallback typedef IUserNotificationCallback
    
  endif
  ifndef __IUserNotification2_FWD_DEFINED__
    __IUserNotification2_FWD_DEFINED__ equ <>
    ;IUserNotification2 typedef IUserNotification2
    
  endif
  ifndef __IDeskBand2_FWD_DEFINED__
    __IDeskBand2_FWD_DEFINED__ equ <>
    ;IDeskBand2 typedef IDeskBand2
    
  endif
  ifndef __IStartMenuPinnedList_FWD_DEFINED__
    __IStartMenuPinnedList_FWD_DEFINED__ equ <>
    ;IStartMenuPinnedList typedef IStartMenuPinnedList
    
  endif
  ifndef __ICDBurn_FWD_DEFINED__
    __ICDBurn_FWD_DEFINED__ equ <>
    ;ICDBurn typedef ICDBurn
    
  endif
  ifndef __IWizardSite_FWD_DEFINED__
    __IWizardSite_FWD_DEFINED__ equ <>
    ;IWizardSite typedef IWizardSite
    
  endif
  ifndef __IWizardExtension_FWD_DEFINED__
    __IWizardExtension_FWD_DEFINED__ equ <>
    ;IWizardExtension typedef IWizardExtension
    
  endif
  ifndef __IWebWizardExtension_FWD_DEFINED__
    __IWebWizardExtension_FWD_DEFINED__ equ <>
    ;IWebWizardExtension typedef IWebWizardExtension
    
  endif
  ifndef __IPublishingWizard_FWD_DEFINED__
    __IPublishingWizard_FWD_DEFINED__ equ <>
    ;IPublishingWizard typedef IPublishingWizard
    
  endif
  ifndef __IFolderViewHost_FWD_DEFINED__
    __IFolderViewHost_FWD_DEFINED__ equ <>
    ;IFolderViewHost typedef IFolderViewHost
    
  endif
  ifndef __IAccessibleObject_FWD_DEFINED__
    __IAccessibleObject_FWD_DEFINED__ equ <>
    ;IAccessibleObject typedef IAccessibleObject
    
  endif
  ifndef __IResultsFolder_FWD_DEFINED__
    __IResultsFolder_FWD_DEFINED__ equ <>
    ;IResultsFolder typedef IResultsFolder
    
  endif
  ifndef __IAutoCompleteDropDown_FWD_DEFINED__
    __IAutoCompleteDropDown_FWD_DEFINED__ equ <>
    ;IAutoCompleteDropDown typedef IAutoCompleteDropDown
    
  endif
  ifndef __ICDBurnExt_FWD_DEFINED__
    __ICDBurnExt_FWD_DEFINED__ equ <>
    ;ICDBurnExt typedef ICDBurnExt
    
  endif
  ifndef __IEnumReadyCallback_FWD_DEFINED__
    __IEnumReadyCallback_FWD_DEFINED__ equ <>
    ;IEnumReadyCallback typedef IEnumReadyCallback
    
  endif
  ifndef __IEnumerableView_FWD_DEFINED__
    __IEnumerableView_FWD_DEFINED__ equ <>
    ;IEnumerableView typedef IEnumerableView
    
  endif
  ifndef __IInsertItem_FWD_DEFINED__
    __IInsertItem_FWD_DEFINED__ equ <>
    ;IInsertItem typedef IInsertItem
    
  endif
  ifndef __IFolderBandPriv_FWD_DEFINED__
    __IFolderBandPriv_FWD_DEFINED__ equ <>
    ;IFolderBandPriv typedef IFolderBandPriv
    
  endif
  ifndef __IImageRecompress_FWD_DEFINED__
    __IImageRecompress_FWD_DEFINED__ equ <>
    ;IImageRecompress typedef IImageRecompress
    
  endif
  ifndef __IFileDialogControlEvents_FWD_DEFINED__
    __IFileDialogControlEvents_FWD_DEFINED__ equ <>
    ;IFileDialogControlEvents typedef IFileDialogControlEvents
    
  endif
  ifndef __IFileDialog2_FWD_DEFINED__
    __IFileDialog2_FWD_DEFINED__ equ <>
    ;IFileDialog2 typedef IFileDialog2
    
  endif
  ifndef __IApplicationAssociationRegistrationUI_FWD_DEFINED__
    __IApplicationAssociationRegistrationUI_FWD_DEFINED__ equ <>
    ;IApplicationAssociationRegistrationUI typedef IApplicationAssociationRegistrationUI
    
  endif
  ifndef __IShellRunDll_FWD_DEFINED__
    __IShellRunDll_FWD_DEFINED__ equ <>
    ;IShellRunDll typedef IShellRunDll
    
  endif
  ifndef __IPreviousVersionsInfo_FWD_DEFINED__
    __IPreviousVersionsInfo_FWD_DEFINED__ equ <>
    ;IPreviousVersionsInfo typedef IPreviousVersionsInfo
    
  endif
  ifndef __IUseToBrowseItem_FWD_DEFINED__
    __IUseToBrowseItem_FWD_DEFINED__ equ <>
    ;IUseToBrowseItem typedef IUseToBrowseItem
    
  endif
  ifndef __INameSpaceTreeControl2_FWD_DEFINED__
    __INameSpaceTreeControl2_FWD_DEFINED__ equ <>
    ;INameSpaceTreeControl2 typedef INameSpaceTreeControl2
    
  endif
  ifndef __INameSpaceTreeControlEvents_FWD_DEFINED__
    __INameSpaceTreeControlEvents_FWD_DEFINED__ equ <>
    ;INameSpaceTreeControlEvents typedef INameSpaceTreeControlEvents
    
  endif
  ifndef __INameSpaceTreeControlDropHandler_FWD_DEFINED__
    __INameSpaceTreeControlDropHandler_FWD_DEFINED__ equ <>
    ;INameSpaceTreeControlDropHandler typedef INameSpaceTreeControlDropHandler
    
  endif
  ifndef __INameSpaceTreeAccessible_FWD_DEFINED__
    __INameSpaceTreeAccessible_FWD_DEFINED__ equ <>
    ;INameSpaceTreeAccessible typedef INameSpaceTreeAccessible
    
  endif
  ifndef __INameSpaceTreeControlCustomDraw_FWD_DEFINED__
    __INameSpaceTreeControlCustomDraw_FWD_DEFINED__ equ <>
    ;INameSpaceTreeControlCustomDraw typedef INameSpaceTreeControlCustomDraw
    
  endif
  ifndef __ITrayDeskBand_FWD_DEFINED__
    __ITrayDeskBand_FWD_DEFINED__ equ <>
    ;ITrayDeskBand typedef ITrayDeskBand
    
  endif
  ifndef __IBandHost_FWD_DEFINED__
    __IBandHost_FWD_DEFINED__ equ <>
    ;IBandHost typedef IBandHost
    
  endif
  ifndef __IMarkupCallback_FWD_DEFINED__
    __IMarkupCallback_FWD_DEFINED__ equ <>
    ;IMarkupCallback typedef IMarkupCallback
    
  endif
  ifndef __IControlMarkup_FWD_DEFINED__
    __IControlMarkup_FWD_DEFINED__ equ <>
    ;IControlMarkup typedef IControlMarkup
    
  endif
  ifndef __IInitializeNetworkFolder_FWD_DEFINED__
    __IInitializeNetworkFolder_FWD_DEFINED__ equ <>
    ;IInitializeNetworkFolder typedef IInitializeNetworkFolder
    
  endif
  ifndef __IComputerInfoChangeNotify_FWD_DEFINED__
    __IComputerInfoChangeNotify_FWD_DEFINED__ equ <>
    ;IComputerInfoChangeNotify typedef IComputerInfoChangeNotify
    
  endif
  ifndef __IDesktopGadget_FWD_DEFINED__
    __IDesktopGadget_FWD_DEFINED__ equ <>
    ;IDesktopGadget typedef IDesktopGadget
    
  endif
  ifndef __IVirtualDesktopManager_FWD_DEFINED__
    __IVirtualDesktopManager_FWD_DEFINED__ equ <>
    ;IVirtualDesktopManager typedef IVirtualDesktopManager
    
  endif
  ifndef __QueryCancelAutoPlay_FWD_DEFINED__
    __QueryCancelAutoPlay_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;QueryCancelAutoPlay typedef QueryCancelAutoPlay
      
    endif
  endif
  ifndef __TimeCategorizer_FWD_DEFINED__
    __TimeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;TimeCategorizer typedef TimeCategorizer
      
    endif
  endif
  ifndef __AlphabeticalCategorizer_FWD_DEFINED__
    __AlphabeticalCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;AlphabeticalCategorizer typedef AlphabeticalCategorizer
      
    endif
  endif
  ifndef __MergedCategorizer_FWD_DEFINED__
    __MergedCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;MergedCategorizer typedef MergedCategorizer
      
    endif
  endif
  ifndef __ImageProperties_FWD_DEFINED__
    __ImageProperties_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ImageProperties typedef ImageProperties
      
    endif
  endif
  ifndef __CDBurn_FWD_DEFINED__
    __CDBurn_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;CDBurn typedef CDBurn
      
    endif
  endif
  ifndef __StartMenuPin_FWD_DEFINED__
    __StartMenuPin_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;StartMenuPin typedef StartMenuPin
      
    endif
  endif
  ifndef __WebWizardHost_FWD_DEFINED__
    __WebWizardHost_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;WebWizardHost typedef WebWizardHost
      
    endif
  endif
  ifndef __PublishDropTarget_FWD_DEFINED__
    __PublishDropTarget_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;PublishDropTarget typedef PublishDropTarget
      
    endif
  endif
  ifndef __PublishingWizard_FWD_DEFINED__
    __PublishingWizard_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;PublishingWizard typedef PublishingWizard
      
    endif
  endif
  ifndef __InternetPrintOrdering_FWD_DEFINED__
    __InternetPrintOrdering_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;InternetPrintOrdering typedef InternetPrintOrdering
      
    endif
  endif
  ifndef __FolderViewHost_FWD_DEFINED__
    __FolderViewHost_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FolderViewHost typedef FolderViewHost
      
    endif
  endif
  ifndef __ExplorerBrowser_FWD_DEFINED__
    __ExplorerBrowser_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ExplorerBrowser typedef ExplorerBrowser
      
    endif
  endif
  ifndef __ImageRecompress_FWD_DEFINED__
    __ImageRecompress_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ImageRecompress typedef ImageRecompress
      
    endif
  endif
  ifndef __TrayBandSiteService_FWD_DEFINED__
    __TrayBandSiteService_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;TrayBandSiteService typedef TrayBandSiteService
      
    endif
  endif
  ifndef __TrayDeskBand_FWD_DEFINED__
    __TrayDeskBand_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;TrayDeskBand typedef TrayDeskBand
      
    endif
  endif
  ifndef __AttachmentServices_FWD_DEFINED__
    __AttachmentServices_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;AttachmentServices typedef AttachmentServices
      
    endif
  endif
  ifndef __DocPropShellExtension_FWD_DEFINED__
    __DocPropShellExtension_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DocPropShellExtension typedef DocPropShellExtension
      
    endif
  endif
  ifndef __FSCopyHandler_FWD_DEFINED__
    __FSCopyHandler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FSCopyHandler typedef FSCopyHandler
      
    endif
  endif
  ifndef __PreviousVersions_FWD_DEFINED__
    __PreviousVersions_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;PreviousVersions typedef PreviousVersions
      
    endif
  endif
  ifndef __NamespaceTreeControl_FWD_DEFINED__
    __NamespaceTreeControl_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;NamespaceTreeControl typedef NamespaceTreeControl
      
    endif
  endif
  ifndef __IENamespaceTreeControl_FWD_DEFINED__
    __IENamespaceTreeControl_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;IENamespaceTreeControl typedef IENamespaceTreeControl
      
    endif
  endif
  ifndef __ApplicationAssociationRegistrationUI_FWD_DEFINED__
    __ApplicationAssociationRegistrationUI_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ApplicationAssociationRegistrationUI typedef ApplicationAssociationRegistrationUI
      
    endif
  endif
  ifndef __DesktopGadget_FWD_DEFINED__
    __DesktopGadget_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DesktopGadget typedef DesktopGadget
      
    endif
  endif
  ifndef __AccessibilityDockingService_FWD_DEFINED__
    __AccessibilityDockingService_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;AccessibilityDockingService typedef AccessibilityDockingService
      
    endif
  endif
  ifndef __ExecuteFolder_FWD_DEFINED__
    __ExecuteFolder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ExecuteFolder typedef ExecuteFolder
      
    endif
  endif
  ifndef __VirtualDesktopManager_FWD_DEFINED__
    __VirtualDesktopManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;VirtualDesktopManager typedef VirtualDesktopManager
      
    endif
  endif
  ifndef __StorageProviderBanners_FWD_DEFINED__
    __StorageProviderBanners_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;StorageProviderBanners typedef StorageProviderBanners
      
    endif
  endif
  ifndef __IAccessibilityDockingServiceCallback_FWD_DEFINED__
    __IAccessibilityDockingServiceCallback_FWD_DEFINED__ equ <>
    ;IAccessibilityDockingServiceCallback typedef IAccessibilityDockingServiceCallback
    
  endif
  ifndef __IAccessibilityDockingService_FWD_DEFINED__
    __IAccessibilityDockingService_FWD_DEFINED__ equ <>
    ;IAccessibilityDockingService typedef IAccessibilityDockingService
    
  endif
  ifndef __IBannerNotificationHandler_FWD_DEFINED__
    __IBannerNotificationHandler_FWD_DEFINED__ equ <>
    ;IBannerNotificationHandler typedef IBannerNotificationHandler
    
  endif
  ifndef __IStorageProviderBanners_FWD_DEFINED__
    __IStorageProviderBanners_FWD_DEFINED__ equ <>
    ;IStorageProviderBanners typedef IStorageProviderBanners
    
  endif
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
  include winapifamily.inc
  if _MSC_VER ge 1200
    ifndef _MSC_EXTENSIONS
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include sherrors.inc
    externdef __MIDL_itf_shobjidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IQueryCodePage_INTERFACE_DEFINED__
      __IQueryCodePage_INTERFACE_DEFINED__ equ <>
      externdef IID_IQueryCodePage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IQueryCodePageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IQueryCodePageVtbl>
          STD_METHOD QueryInterface, :ptr IQueryCodePage, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IQueryCodePage
          STD_METHOD Release, :ptr IQueryCodePage
          STD_METHOD GetCodePage, :ptr IQueryCodePage, :ptr UINT
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
      endif
    endif
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
          STD_METHOD QueryInterface, :ptr IFolderViewOptions, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFolderViewOptions
          STD_METHOD Release, :ptr IFolderViewOptions
          STD_METHOD SetFolderViewOptions, :ptr IFolderViewOptions, :FOLDERVIEWOPTIONS, :FOLDERVIEWOPTIONS
          STD_METHOD GetFolderViewOptions, :ptr IFolderViewOptions, :ptr FOLDERVIEWOPTIONS
          ??Interface equ <>
          END_INTERFACE
        IFolderViewOptionsVtbl ends

        IFolderViewOptions struct
          lpVtbl POINTER ?
        IFolderViewOptions ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IShellView3_INTERFACE_DEFINED__
        __IShellView3_INTERFACE_DEFINED__ equ <>
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
            STD_METHOD QueryInterface, :ptr IShellView3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellView3
            STD_METHOD Release, :ptr IShellView3
            STD_METHOD GetWindow, :ptr IShellView3, :ptr HWND
            STD_METHOD ContextSensitiveHelp, :ptr IShellView3, :BOOL
            STD_METHOD TranslateAccelerator, :ptr IShellView3, :ptr MSG
            STD_METHOD EnableModeless, :ptr IShellView3, :BOOL
            STD_METHOD UIActivate, :ptr IShellView3, :UINT
            STD_METHOD Refresh, :ptr IShellView3
            STD_METHOD CreateViewWindow, :ptr IShellView3, :ptr IShellView, :LPCFOLDERSETTINGS, :ptr IShellBrowser, :ptr RECT, :ptr HWND
            STD_METHOD DestroyViewWindow, :ptr IShellView3
            STD_METHOD GetCurrentInfo, :ptr IShellView3, :LPFOLDERSETTINGS
            STD_METHOD AddPropertySheetPages, :ptr IShellView3, :DWORD, :LPFNSVADDPROPSHEETPAGE, :LPARAM
            STD_METHOD SaveViewState, :ptr IShellView3
            STD_METHOD SelectItem, :ptr IShellView3, :PCUITEMID_CHILD, :SVSIF
            STD_METHOD GetItemObject, :ptr IShellView3, :UINT, :REFIID, :ptr ptr
            STD_METHOD GetView, :ptr IShellView3, :ptr SHELLVIEWID, :ULONG
            STD_METHOD CreateViewWindow2, :ptr IShellView3, :LPSV2CVW2_PARAMS
            STD_METHOD HandleRename, :ptr IShellView3, :PCUITEMID_CHILD
            STD_METHOD SelectAndPositionItem, :ptr IShellView3, :PCUITEMID_CHILD, :UINT, :ptr POINT
            STD_METHOD CreateViewWindow3, :ptr IShellView3, :ptr IShellBrowser, :ptr IShellView, :SV3CVW3_FLAGS, :FOLDERFLAGS, :FOLDERFLAGS, :FOLDERVIEWMODE, :ptr SHELLVIEWID, :ptr RECT, :ptr HWND
            ??Interface equ <>
            END_INTERFACE
          IShellView3Vtbl ends

          IShellView3 struct
            lpVtbl POINTER ?
          IShellView3 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      externdef __MIDL_itf_shobjidl_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISearchBoxInfo_INTERFACE_DEFINED__
        __ISearchBoxInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_ISearchBoxInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISearchBoxInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISearchBoxInfoVtbl>
            STD_METHOD QueryInterface, :ptr ISearchBoxInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISearchBoxInfo
            STD_METHOD Release, :ptr ISearchBoxInfo
            STD_METHOD GetCondition, :ptr ISearchBoxInfo, :REFIID, :ptr ptr
            STD_METHOD GetText, :ptr ISearchBoxInfo, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          ISearchBoxInfoVtbl ends

          ISearchBoxInfo struct
            lpVtbl POINTER ?
          ISearchBoxInfo ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IVisualProperties_INTERFACE_DEFINED__
        __IVisualProperties_INTERFACE_DEFINED__ equ <>
        VPWATERMARKFLAGS typedef SDWORD
        VPWF_DEFAULT equ 0
        VPWF_ALPHABLEND equ 1h
        
        DEFINE_ENUM_FLAG_OPERATORS(VPWATERMARKFLAGS)
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
            STD_METHOD QueryInterface, :ptr IVisualProperties, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IVisualProperties
            STD_METHOD Release, :ptr IVisualProperties
            STD_METHOD SetWatermark, :ptr IVisualProperties, :HBITMAP, :VPWATERMARKFLAGS
            STD_METHOD SetColor, :ptr IVisualProperties, :VPCOLORFLAGS, :COLORREF
            STD_METHOD GetColor, :ptr IVisualProperties, :VPCOLORFLAGS, :ptr COLORREF
            STD_METHOD SetItemHeight, :ptr IVisualProperties, :SDWORD
            STD_METHOD GetItemHeight, :ptr IVisualProperties, :ptr SDWORD
            STD_METHOD SetFont, :ptr IVisualProperties, :ptr LOGFONTW, :BOOL
            STD_METHOD GetFont, :ptr IVisualProperties, :ptr LOGFONTW
            STD_METHOD SetTheme, :ptr IVisualProperties, :LPCWSTR, :LPCWSTR
            ??Interface equ <>
            END_INTERFACE
          IVisualPropertiesVtbl ends

          IVisualProperties struct
            lpVtbl POINTER ?
          IVisualProperties ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICommDlgBrowser3_INTERFACE_DEFINED__
        __ICommDlgBrowser3_INTERFACE_DEFINED__ equ <>
        externdef IID_ICommDlgBrowser3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICommDlgBrowser3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICommDlgBrowser3Vtbl>
            STD_METHOD QueryInterface, :ptr ICommDlgBrowser3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICommDlgBrowser3
            STD_METHOD Release, :ptr ICommDlgBrowser3
            STD_METHOD OnDefaultCommand, :ptr ICommDlgBrowser3, :ptr IShellView
            STD_METHOD OnStateChange, :ptr ICommDlgBrowser3, :ptr IShellView, :ULONG
            STD_METHOD IncludeObject, :ptr ICommDlgBrowser3, :ptr IShellView, :PCUITEMID_CHILD
            STD_METHOD Notify, :ptr ICommDlgBrowser3, :ptr IShellView, :DWORD
            STD_METHOD GetDefaultMenuText, :ptr ICommDlgBrowser3, :ptr IShellView, :LPWSTR, :SDWORD
            STD_METHOD GetViewFlags, :ptr ICommDlgBrowser3, :ptr DWORD
            STD_METHOD OnColumnClicked, :ptr ICommDlgBrowser3, :ptr IShellView, :SDWORD
            STD_METHOD GetCurrentFilter, :ptr ICommDlgBrowser3, :LPWSTR, :SDWORD
            STD_METHOD OnPreViewCreated, :ptr ICommDlgBrowser3, :ptr IShellView
            ??Interface equ <>
            END_INTERFACE
          ICommDlgBrowser3Vtbl ends

          ICommDlgBrowser3 struct
            lpVtbl POINTER ?
          ICommDlgBrowser3 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0006_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0006_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUserAccountChangeCallback_INTERFACE_DEFINED__
      __IUserAccountChangeCallback_INTERFACE_DEFINED__ equ <>
      externdef IID_IUserAccountChangeCallback:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserAccountChangeCallbackVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserAccountChangeCallbackVtbl>
          STD_METHOD QueryInterface, :ptr IUserAccountChangeCallback, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IUserAccountChangeCallback
          STD_METHOD Release, :ptr IUserAccountChangeCallback
          STD_METHOD OnPictureChange, :ptr IUserAccountChangeCallback, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IUserAccountChangeCallbackVtbl ends

        IUserAccountChangeCallback struct
          lpVtbl POINTER ?
        IUserAccountChangeCallback ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifdef MIDL_PASS
      ;[...]
    endif
    externdef __MIDL_itf_shobjidl_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IStreamAsync_INTERFACE_DEFINED__
      __IStreamAsync_INTERFACE_DEFINED__ equ <>
      externdef IID_IStreamAsync:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStreamAsyncVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStreamAsyncVtbl>
          STD_METHOD QueryInterface, :ptr IStreamAsync, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IStreamAsync
          STD_METHOD Release, :ptr IStreamAsync
          STD_METHOD Read, :ptr IStreamAsync, :ptr, :ULONG, :ptr ULONG
          STD_METHOD Write, :ptr IStreamAsync, :ptr, :ULONG, :ptr ULONG
          STD_METHOD Seek, :ptr IStreamAsync, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          STD_METHOD SetSize, :ptr IStreamAsync, :ULARGE_INTEGER
          STD_METHOD CopyTo, :ptr IStreamAsync, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          STD_METHOD Commit, :ptr IStreamAsync, :DWORD
          STD_METHOD Revert, :ptr IStreamAsync
          STD_METHOD LockRegion, :ptr IStreamAsync, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          STD_METHOD UnlockRegion, :ptr IStreamAsync, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          STD_METHOD Stat, :ptr IStreamAsync, :ptr STATSTG, :DWORD
          STD_METHOD Clone, :ptr IStreamAsync, :ptr ptr IStream
          STD_METHOD ReadAsync, :ptr IStreamAsync, :ptr, :DWORD, :LPDWORD, :LPOVERLAPPED
          STD_METHOD WriteAsync, :ptr IStreamAsync, :ptr, :DWORD, :LPDWORD, :LPOVERLAPPED
          STD_METHOD OverlappedResult, :ptr IStreamAsync, :LPOVERLAPPED, :LPDWORD, :BOOL
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
      endif
    endif
    ifndef __IStreamUnbufferedInfo_INTERFACE_DEFINED__
      __IStreamUnbufferedInfo_INTERFACE_DEFINED__ equ <>
      externdef IID_IStreamUnbufferedInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStreamUnbufferedInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStreamUnbufferedInfoVtbl>
          STD_METHOD QueryInterface, :ptr IStreamUnbufferedInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IStreamUnbufferedInfo
          STD_METHOD Release, :ptr IStreamUnbufferedInfo
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
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      @DefProto DllImport, SHRemovePersonalPropertyValues, WIN_STD_CALL_CONV,, <:ptr IShellItemArray>, 4
      @DefProto DllImport, SHAddDefaultPropertiesByExt, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr IPropertyStore>, 8
      @DefProto DllImport, SHCreateDefaultPropertiesOp, WIN_STD_CALL_CONV,, <:ptr IShellItem, :ptr ptr IFileOperation>, 8
      @DefProto DllImport, SHSetDefaultProperties, WIN_STD_CALL_CONV,, <:HWND, :ptr IShellItem, :DWORD, :ptr IFileOperationProgressSink>, 16
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        DSH_FLAGS typedef SDWORD
        DSH_ALLOWDROPDESCRIPTIONTEXT equ 1h
        
        DEFINE_ENUM_FLAG_OPERATORS(DSH_FLAGS)
        externdef __MIDL_itf_shobjidl_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IDragSourceHelper2_INTERFACE_DEFINED__
          __IDragSourceHelper2_INTERFACE_DEFINED__ equ <>
          externdef IID_IDragSourceHelper2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IDragSourceHelper2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IDragSourceHelper2Vtbl>
              STD_METHOD QueryInterface, :ptr IDragSourceHelper2, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IDragSourceHelper2
              STD_METHOD Release, :ptr IDragSourceHelper2
              STD_METHOD InitializeFromBitmap, :ptr IDragSourceHelper2, :LPSHDRAGIMAGE, :ptr IDataObject
              STD_METHOD InitializeFromWindow, :ptr IDragSourceHelper2, :HWND, :ptr POINT, :ptr IDataObject
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
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IHWEventHandler_INTERFACE_DEFINED__
      __IHWEventHandler_INTERFACE_DEFINED__ equ <>
      externdef IID_IHWEventHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IHWEventHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IHWEventHandlerVtbl>
          STD_METHOD QueryInterface, :ptr IHWEventHandler, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IHWEventHandler
          STD_METHOD Release, :ptr IHWEventHandler
          STD_METHOD Initialize, :ptr IHWEventHandler, :LPCWSTR
          STD_METHOD HandleEvent, :ptr IHWEventHandler, :LPCWSTR, :LPCWSTR, :LPCWSTR
          STD_METHOD HandleEventWithContent, :ptr IHWEventHandler, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr IDataObject
          ??Interface equ <>
          END_INTERFACE
        IHWEventHandlerVtbl ends

        IHWEventHandler struct
          lpVtbl POINTER ?
        IHWEventHandler ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IHWEventHandler2_INTERFACE_DEFINED__
      __IHWEventHandler2_INTERFACE_DEFINED__ equ <>
      externdef IID_IHWEventHandler2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IHWEventHandler2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IHWEventHandler2Vtbl>
          STD_METHOD QueryInterface, :ptr IHWEventHandler2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IHWEventHandler2
          STD_METHOD Release, :ptr IHWEventHandler2
          STD_METHOD Initialize, :ptr IHWEventHandler2, :LPCWSTR
          STD_METHOD HandleEvent, :ptr IHWEventHandler2, :LPCWSTR, :LPCWSTR, :LPCWSTR
          STD_METHOD HandleEventWithContent, :ptr IHWEventHandler2, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr IDataObject
          STD_METHOD HandleEventWithHWND, :ptr IHWEventHandler2, :LPCWSTR, :LPCWSTR, :LPCWSTR, :HWND
          ??Interface equ <>
          END_INTERFACE
        IHWEventHandler2Vtbl ends

        IHWEventHandler2 struct
          lpVtbl POINTER ?
        IHWEventHandler2 ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IQueryCancelAutoPlay_INTERFACE_DEFINED__
      __IQueryCancelAutoPlay_INTERFACE_DEFINED__ equ <>
      externdef IID_IQueryCancelAutoPlay:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IQueryCancelAutoPlayVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IQueryCancelAutoPlayVtbl>
          STD_METHOD QueryInterface, :ptr IQueryCancelAutoPlay, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IQueryCancelAutoPlay
          STD_METHOD Release, :ptr IQueryCancelAutoPlay
          STD_METHOD AllowAutoPlay, :ptr IQueryCancelAutoPlay, :LPCWSTR, :DWORD, :LPCWSTR, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IQueryCancelAutoPlayVtbl ends

        IQueryCancelAutoPlay struct
          lpVtbl POINTER ?
        IQueryCancelAutoPlay ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDynamicHWHandler_INTERFACE_DEFINED__
        __IDynamicHWHandler_INTERFACE_DEFINED__ equ <>
        externdef IID_IDynamicHWHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDynamicHWHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDynamicHWHandlerVtbl>
            STD_METHOD QueryInterface, :ptr IDynamicHWHandler, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDynamicHWHandler
            STD_METHOD Release, :ptr IDynamicHWHandler
            STD_METHOD GetDynamicInfo, :ptr IDynamicHWHandler, :LPCWSTR, :DWORD, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IDynamicHWHandlerVtbl ends

          IDynamicHWHandler struct
            lpVtbl POINTER ?
          IDynamicHWHandler ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUserNotificationCallback_INTERFACE_DEFINED__
      __IUserNotificationCallback_INTERFACE_DEFINED__ equ <>
      externdef IID_IUserNotificationCallback:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserNotificationCallbackVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserNotificationCallbackVtbl>
          STD_METHOD QueryInterface, :ptr IUserNotificationCallback, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IUserNotificationCallback
          STD_METHOD Release, :ptr IUserNotificationCallback
          STD_METHOD OnBalloonUserClick, :ptr IUserNotificationCallback, :ptr POINT
          STD_METHOD OnLeftClick, :ptr IUserNotificationCallback, :ptr POINT
          STD_METHOD OnContextMenu, :ptr IUserNotificationCallback, :ptr POINT
          ??Interface equ <>
          END_INTERFACE
        IUserNotificationCallbackVtbl ends

        IUserNotificationCallback struct
          lpVtbl POINTER ?
        IUserNotificationCallback ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IUserNotification2_INTERFACE_DEFINED__
      __IUserNotification2_INTERFACE_DEFINED__ equ <>
      externdef IID_IUserNotification2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserNotification2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserNotification2Vtbl>
          STD_METHOD QueryInterface, :ptr IUserNotification2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IUserNotification2
          STD_METHOD Release, :ptr IUserNotification2
          STD_METHOD SetBalloonInfo, :ptr IUserNotification2, :LPCWSTR, :LPCWSTR, :DWORD
          STD_METHOD SetBalloonRetry, :ptr IUserNotification2, :DWORD, :DWORD, :UINT
          STD_METHOD SetIconInfo, :ptr IUserNotification2, :HICON, :LPCWSTR
          STD_METHOD Show, :ptr IUserNotification2, :ptr IQueryContinue, :DWORD, :ptr IUserNotificationCallback
          STD_METHOD PlaySound, :ptr IUserNotification2, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IUserNotification2Vtbl ends

        IUserNotification2 struct
          lpVtbl POINTER ?
        IUserNotification2 ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0016_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0016_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDeskBand2_INTERFACE_DEFINED__
        __IDeskBand2_INTERFACE_DEFINED__ equ <>
        externdef IID_IDeskBand2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDeskBand2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDeskBand2Vtbl>
            STD_METHOD QueryInterface, :ptr IDeskBand2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDeskBand2
            STD_METHOD Release, :ptr IDeskBand2
            STD_METHOD GetWindow, :ptr IDeskBand2, :ptr HWND
            STD_METHOD ContextSensitiveHelp, :ptr IDeskBand2, :BOOL
            STD_METHOD ShowDW, :ptr IDeskBand2, :BOOL
            STD_METHOD CloseDW, :ptr IDeskBand2, :DWORD
            STD_METHOD ResizeBorderDW, :ptr IDeskBand2, :LPCRECT, :ptr IUnknown, :BOOL
            STD_METHOD GetBandInfo, :ptr IDeskBand2, :DWORD, :DWORD, :ptr DESKBANDINFO
            STD_METHOD CanRenderComposited, :ptr IDeskBand2, :ptr BOOL
            STD_METHOD SetCompositionState, :ptr IDeskBand2, :BOOL
            STD_METHOD GetCompositionState, :ptr IDeskBand2, :ptr BOOL
            ??Interface equ <>
            END_INTERFACE
          IDeskBand2Vtbl ends

          IDeskBand2 struct
            lpVtbl POINTER ?
          IDeskBand2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IStartMenuPinnedList_INTERFACE_DEFINED__
      __IStartMenuPinnedList_INTERFACE_DEFINED__ equ <>
      externdef IID_IStartMenuPinnedList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStartMenuPinnedListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStartMenuPinnedListVtbl>
          STD_METHOD QueryInterface, :ptr IStartMenuPinnedList, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IStartMenuPinnedList
          STD_METHOD Release, :ptr IStartMenuPinnedList
          STD_METHOD RemoveFromList, :ptr IStartMenuPinnedList, :ptr IShellItem
          ??Interface equ <>
          END_INTERFACE
        IStartMenuPinnedListVtbl ends

        IStartMenuPinnedList struct
          lpVtbl POINTER ?
        IStartMenuPinnedList ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICDBurn_INTERFACE_DEFINED__
      __ICDBurn_INTERFACE_DEFINED__ equ <>
      externdef IID_ICDBurn:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICDBurnVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICDBurnVtbl>
          STD_METHOD QueryInterface, :ptr ICDBurn, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICDBurn
          STD_METHOD Release, :ptr ICDBurn
          STD_METHOD GetRecorderDriveLetter, :ptr ICDBurn, :LPWSTR, :UINT
          STD_METHOD Burn, :ptr ICDBurn, :HWND
          STD_METHOD HasRecordableDrive, :ptr ICDBurn, :ptr BOOL
          ??Interface equ <>
          END_INTERFACE
        ICDBurnVtbl ends

        ICDBurn struct
          lpVtbl POINTER ?
        ICDBurn ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    IDD_WIZEXTN_FIRST equ 5000h
    IDD_WIZEXTN_LAST equ 5100h
    externdef __MIDL_itf_shobjidl_0000_0019_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0019_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IWizardSite_INTERFACE_DEFINED__
      __IWizardSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IWizardSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IWizardSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IWizardSiteVtbl>
          STD_METHOD QueryInterface, :ptr IWizardSite, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IWizardSite
          STD_METHOD Release, :ptr IWizardSite
          STD_METHOD GetPreviousPage, :ptr IWizardSite, :ptr HPROPSHEETPAGE
          STD_METHOD GetNextPage, :ptr IWizardSite, :ptr HPROPSHEETPAGE
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
      endif
    endif
    SID_WizardSite equ <IID_IWizardSite>
    externdef __MIDL_itf_shobjidl_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IWizardExtension_INTERFACE_DEFINED__
      __IWizardExtension_INTERFACE_DEFINED__ equ <>
      externdef IID_IWizardExtension:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IWizardExtensionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IWizardExtensionVtbl>
          STD_METHOD QueryInterface, :ptr IWizardExtension, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IWizardExtension
          STD_METHOD Release, :ptr IWizardExtension
          STD_METHOD AddPages, :ptr IWizardExtension, :ptr HPROPSHEETPAGE, :UINT, :ptr UINT
          STD_METHOD GetFirstPage, :ptr IWizardExtension, :ptr HPROPSHEETPAGE
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
      endif
    endif
    ifndef __IWebWizardExtension_INTERFACE_DEFINED__
      __IWebWizardExtension_INTERFACE_DEFINED__ equ <>
      externdef IID_IWebWizardExtension:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IWebWizardExtensionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IWebWizardExtensionVtbl>
          STD_METHOD QueryInterface, :ptr IWebWizardExtension, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IWebWizardExtension
          STD_METHOD Release, :ptr IWebWizardExtension
          STD_METHOD AddPages, :ptr IWebWizardExtension, :ptr HPROPSHEETPAGE, :UINT, :ptr UINT
          STD_METHOD GetFirstPage, :ptr IWebWizardExtension, :ptr HPROPSHEETPAGE
          STD_METHOD GetLastPage, :ptr IWebWizardExtension, :ptr HPROPSHEETPAGE
          STD_METHOD SetInitialURL, :ptr IWebWizardExtension, :LPCWSTR
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
      endif
    endif
    SID_WebWizardHost equ <IID_IWebWizardExtension>
    SHPWHF_NORECOMPRESS equ 00000001h
    SHPWHF_NONETPLACECREATE equ 00000002h
    SHPWHF_NOFILESELECTOR equ 00000004h
    SHPWHF_USEMRU equ 00000008h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SHPWHF_ANYLOCATION equ 00000100h
    endif
    SHPWHF_VALIDATEVIAWEBFOLDERS equ 00010000h
    externdef __MIDL_itf_shobjidl_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPublishingWizard_INTERFACE_DEFINED__
      __IPublishingWizard_INTERFACE_DEFINED__ equ <>
      externdef IID_IPublishingWizard:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPublishingWizardVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPublishingWizardVtbl>
          STD_METHOD QueryInterface, :ptr IPublishingWizard, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPublishingWizard
          STD_METHOD Release, :ptr IPublishingWizard
          STD_METHOD AddPages, :ptr IPublishingWizard, :ptr HPROPSHEETPAGE, :UINT, :ptr UINT
          STD_METHOD GetFirstPage, :ptr IPublishingWizard, :ptr HPROPSHEETPAGE
          STD_METHOD GetLastPage, :ptr IPublishingWizard, :ptr HPROPSHEETPAGE
          STD_METHOD Initialize, :ptr IPublishingWizard, :ptr IDataObject, :DWORD, :LPCWSTR
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
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFolderViewHost_INTERFACE_DEFINED__
        __IFolderViewHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IFolderViewHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFolderViewHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFolderViewHostVtbl>
            STD_METHOD QueryInterface, :ptr IFolderViewHost, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFolderViewHost
            STD_METHOD Release, :ptr IFolderViewHost
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
        endif
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        externdef __MIDL_itf_shobjidl_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IAccessibleObject_INTERFACE_DEFINED__
          __IAccessibleObject_INTERFACE_DEFINED__ equ <>
          externdef IID_IAccessibleObject:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IAccessibleObjectVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IAccessibleObjectVtbl>
              STD_METHOD QueryInterface, :ptr IAccessibleObject, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IAccessibleObject
              STD_METHOD Release, :ptr IAccessibleObject
              STD_METHOD SetAccessibleName, :ptr IAccessibleObject, :LPCWSTR
              ??Interface equ <>
              END_INTERFACE
            IAccessibleObjectVtbl ends

            IAccessibleObject struct
              lpVtbl POINTER ?
            IAccessibleObject ends

            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      externdef __MIDL_itf_shobjidl_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IResultsFolder_INTERFACE_DEFINED__
        __IResultsFolder_INTERFACE_DEFINED__ equ <>
        externdef IID_IResultsFolder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IResultsFolderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IResultsFolderVtbl>
            STD_METHOD QueryInterface, :ptr IResultsFolder, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IResultsFolder
            STD_METHOD Release, :ptr IResultsFolder
            STD_METHOD AddItem, :ptr IResultsFolder, :ptr IShellItem
            STD_METHOD AddIDList, :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
            STD_METHOD RemoveItem, :ptr IResultsFolder, :ptr IShellItem
            STD_METHOD RemoveIDList, :ptr IResultsFolder, :PCIDLIST_ABSOLUTE
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
        endif
        IResultsFolder_RemoteAddIDList_Proxy proto WIN_STD_CALL_CONV :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
        IResultsFolder_RemoteAddIDList_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
      endif
    endif
    ACDD_VISIBLE equ 0001h
    externdef __MIDL_itf_shobjidl_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IAutoCompleteDropDown_INTERFACE_DEFINED__
      __IAutoCompleteDropDown_INTERFACE_DEFINED__ equ <>
      externdef IID_IAutoCompleteDropDown:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAutoCompleteDropDownVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAutoCompleteDropDownVtbl>
          STD_METHOD QueryInterface, :ptr IAutoCompleteDropDown, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IAutoCompleteDropDown
          STD_METHOD Release, :ptr IAutoCompleteDropDown
          STD_METHOD GetDropDownStatus, :ptr IAutoCompleteDropDown, :ptr DWORD, :ptr LPWSTR
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
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      PROPSTR_EXTENSIONCOMPLETIONSTATE equ <L("ExtensionCompletionState")>
      tagCDBURNINGEXTENSIONRET typedef SDWORD
      CDBE_RET_DEFAULT equ 0
      CDBE_RET_DONTRUNOTHEREXTS equ 1h
      CDBE_RET_STOPWIZARD equ 2h
      
      SID_CDWizardHost equ <IID_ICDBurnExt>
      _CDBE_ACTIONS typedef SDWORD
      CDBE_TYPE_MUSIC equ 1h
      CDBE_TYPE_DATA equ 2h
      CDBE_TYPE_ALL equ 0ffffffffh
      
      CDBE_ACTIONS typedef DWORD
      externdef __MIDL_itf_shobjidl_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICDBurnExt_INTERFACE_DEFINED__
        __ICDBurnExt_INTERFACE_DEFINED__ equ <>
        externdef IID_ICDBurnExt:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICDBurnExtVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICDBurnExtVtbl>
            STD_METHOD QueryInterface, :ptr ICDBurnExt, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICDBurnExt
            STD_METHOD Release, :ptr ICDBurnExt
            STD_METHOD GetSupportedActionTypes, :ptr ICDBurnExt, :ptr CDBE_ACTIONS
            ??Interface equ <>
            END_INTERFACE
          ICDBurnExtVtbl ends

          ICDBurnExt struct
            lpVtbl POINTER ?
          ICDBurnExt ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0028_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0028_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumReadyCallback_INTERFACE_DEFINED__
      __IEnumReadyCallback_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumReadyCallback:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumReadyCallbackVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumReadyCallbackVtbl>
          STD_METHOD QueryInterface, :ptr IEnumReadyCallback, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumReadyCallback
          STD_METHOD Release, :ptr IEnumReadyCallback
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
      endif
    endif
    ifndef __IEnumerableView_INTERFACE_DEFINED__
      __IEnumerableView_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumerableView:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumerableViewVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumerableViewVtbl>
          STD_METHOD QueryInterface, :ptr IEnumerableView, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumerableView
          STD_METHOD Release, :ptr IEnumerableView
          STD_METHOD SetEnumReadyCallback, :ptr IEnumerableView, :ptr IEnumReadyCallback
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
      endif
    endif
    SID_EnumerableView equ <IID_IEnumerableView>
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInsertItem_INTERFACE_DEFINED__
        __IInsertItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IInsertItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInsertItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInsertItemVtbl>
            STD_METHOD QueryInterface, :ptr IInsertItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IInsertItem
            STD_METHOD Release, :ptr IInsertItem
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
        endif
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        externdef __MIDL_itf_shobjidl_0000_0031_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_0000_0031_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IFolderBandPriv_INTERFACE_DEFINED__
          __IFolderBandPriv_INTERFACE_DEFINED__ equ <>
          externdef IID_IFolderBandPriv:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IFolderBandPrivVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IFolderBandPrivVtbl>
              STD_METHOD QueryInterface, :ptr IFolderBandPriv, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IFolderBandPriv
              STD_METHOD Release, :ptr IFolderBandPriv
              STD_METHOD SetCascade, :ptr IFolderBandPriv, :BOOL
              STD_METHOD SetAccelerators, :ptr IFolderBandPriv, :BOOL
              STD_METHOD SetNoIcons, :ptr IFolderBandPriv, :BOOL
              STD_METHOD SetNoText, :ptr IFolderBandPriv, :BOOL
              ??Interface equ <>
              END_INTERFACE
            IFolderBandPrivVtbl ends

            IFolderBandPriv struct
              lpVtbl POINTER ?
            IFolderBandPriv ends

            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        ifndef __IImageRecompress_INTERFACE_DEFINED__
          __IImageRecompress_INTERFACE_DEFINED__ equ <>
          externdef IID_IImageRecompress:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IImageRecompressVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IImageRecompressVtbl>
              STD_METHOD QueryInterface, :ptr IImageRecompress, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IImageRecompress
              STD_METHOD Release, :ptr IImageRecompress
              STD_METHOD RecompressImage, :ptr IImageRecompress, :ptr IShellItem, :SDWORD, :SDWORD, :SDWORD, :ptr IStorage, :ptr ptr IStream
              ??Interface equ <>
              END_INTERFACE
            IImageRecompressVtbl ends

            IImageRecompress struct
              lpVtbl POINTER ?
            IImageRecompress ends

            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0033_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0033_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialogControlEvents_INTERFACE_DEFINED__
        __IFileDialogControlEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileDialogControlEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogControlEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogControlEventsVtbl>
            STD_METHOD QueryInterface, :ptr IFileDialogControlEvents, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileDialogControlEvents
            STD_METHOD Release, :ptr IFileDialogControlEvents
            STD_METHOD OnItemSelected, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD, :DWORD
            STD_METHOD OnButtonClicked, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD
            STD_METHOD OnCheckButtonToggled, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD, :BOOL
            STD_METHOD OnControlActivating, :ptr IFileDialogControlEvents, :ptr IFileDialogCustomize, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IFileDialogControlEventsVtbl ends

          IFileDialogControlEvents struct
            lpVtbl POINTER ?
          IFileDialogControlEvents ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IFileDialog2_INTERFACE_DEFINED__
        __IFileDialog2_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileDialog2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialog2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialog2Vtbl>
            STD_METHOD QueryInterface, :ptr IFileDialog2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileDialog2
            STD_METHOD Release, :ptr IFileDialog2
            STD_METHOD Show, :ptr IFileDialog2, :HWND
            STD_METHOD SetFileTypes, :ptr IFileDialog2, :UINT, :ptr COMDLG_FILTERSPEC
            STD_METHOD SetFileTypeIndex, :ptr IFileDialog2, :UINT
            STD_METHOD GetFileTypeIndex, :ptr IFileDialog2, :ptr UINT
            STD_METHOD Advise, :ptr IFileDialog2, :ptr IFileDialogEvents, :ptr DWORD
            STD_METHOD Unadvise, :ptr IFileDialog2, :DWORD
            STD_METHOD SetOptions, :ptr IFileDialog2, :FILEOPENDIALOGOPTIONS
            STD_METHOD GetOptions, :ptr IFileDialog2, :ptr FILEOPENDIALOGOPTIONS
            STD_METHOD SetDefaultFolder, :ptr IFileDialog2, :ptr IShellItem
            STD_METHOD SetFolder, :ptr IFileDialog2, :ptr IShellItem
            STD_METHOD GetFolder, :ptr IFileDialog2, :ptr ptr IShellItem
            STD_METHOD GetCurrentSelection, :ptr IFileDialog2, :ptr ptr IShellItem
            STD_METHOD SetFileName, :ptr IFileDialog2, :LPCWSTR
            STD_METHOD GetFileName, :ptr IFileDialog2, :ptr LPWSTR
            STD_METHOD SetTitle, :ptr IFileDialog2, :LPCWSTR
            STD_METHOD SetOkButtonLabel, :ptr IFileDialog2, :LPCWSTR
            STD_METHOD SetFileNameLabel, :ptr IFileDialog2, :LPCWSTR
            STD_METHOD GetResult, :ptr IFileDialog2, :ptr ptr IShellItem
            STD_METHOD AddPlace, :ptr IFileDialog2, :ptr IShellItem, :FDAP
            STD_METHOD SetDefaultExtension, :ptr IFileDialog2, :LPCWSTR
            STD_METHOD Close, :ptr IFileDialog2, :HRESULT
            STD_METHOD SetClientGuid, :ptr IFileDialog2, :REFGUID
            STD_METHOD ClearClientData, :ptr IFileDialog2
            STD_METHOD SetFilter, :ptr IFileDialog2, :ptr IShellItemFilter
            STD_METHOD SetCancelButtonLabel, :ptr IFileDialog2, :LPCWSTR
            STD_METHOD SetNavigationRoot, :ptr IFileDialog2, :ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IFileDialog2Vtbl ends

          IFileDialog2 struct
            lpVtbl POINTER ?
          IFileDialog2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IApplicationAssociationRegistrationUI_INTERFACE_DEFINED__
        __IApplicationAssociationRegistrationUI_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationAssociationRegistrationUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationAssociationRegistrationUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationAssociationRegistrationUIVtbl>
            STD_METHOD QueryInterface, :ptr IApplicationAssociationRegistrationUI, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IApplicationAssociationRegistrationUI
            STD_METHOD Release, :ptr IApplicationAssociationRegistrationUI
            STD_METHOD LaunchAdvancedAssociationUI, :ptr IApplicationAssociationRegistrationUI, :LPCWSTR
            ??Interface equ <>
            END_INTERFACE
          IApplicationAssociationRegistrationUIVtbl ends

          IApplicationAssociationRegistrationUI struct
            lpVtbl POINTER ?
          IApplicationAssociationRegistrationUI ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellRunDll_INTERFACE_DEFINED__
      __IShellRunDll_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellRunDll:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellRunDllVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellRunDllVtbl>
          STD_METHOD QueryInterface, :ptr IShellRunDll, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellRunDll
          STD_METHOD Release, :ptr IShellRunDll
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
      endif
    endif
    ifndef __IPreviousVersionsInfo_INTERFACE_DEFINED__
      __IPreviousVersionsInfo_INTERFACE_DEFINED__ equ <>
      externdef IID_IPreviousVersionsInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPreviousVersionsInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPreviousVersionsInfoVtbl>
          STD_METHOD QueryInterface, :ptr IPreviousVersionsInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPreviousVersionsInfo
          STD_METHOD Release, :ptr IPreviousVersionsInfo
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
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IUseToBrowseItem_INTERFACE_DEFINED__
        __IUseToBrowseItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IUseToBrowseItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUseToBrowseItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUseToBrowseItemVtbl>
            STD_METHOD QueryInterface, :ptr IUseToBrowseItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IUseToBrowseItem
            STD_METHOD Release, :ptr IUseToBrowseItem
            STD_METHOD GetItemIDList, :ptr IUseToBrowseItem, :ptr PIDLIST_ABSOLUTE
            STD_METHOD GetItem, :ptr IUseToBrowseItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IUseToBrowseItemVtbl ends

          IUseToBrowseItem struct
            lpVtbl POINTER ?
          IUseToBrowseItem ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    DEFINE_GUID SID_SCommandBarState, 0B99EAA5Ch, 3850h, 4400h, 0BCh, 33h, 2Ch, 0E5h, 34h, 04h, 8Bh, 0F8h
    externdef __MIDL_itf_shobjidl_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INameSpaceTreeControl2_INTERFACE_DEFINED__
      __INameSpaceTreeControl2_INTERFACE_DEFINED__ equ <>
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
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControl2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INameSpaceTreeControl2
          STD_METHOD Release, :ptr INameSpaceTreeControl2
          STD_METHOD Initialize, :ptr INameSpaceTreeControl2, :HWND, :ptr RECT, :NSTCSTYLE
          STD_METHOD TreeAdvise, :ptr INameSpaceTreeControl2, :ptr IUnknown, :ptr DWORD
          STD_METHOD TreeUnadvise, :ptr INameSpaceTreeControl2, :DWORD
          STD_METHOD AppendRoot, :ptr INameSpaceTreeControl2, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          STD_METHOD InsertRoot, :ptr INameSpaceTreeControl2, :SDWORD, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          STD_METHOD RemoveRoot, :ptr INameSpaceTreeControl2, :ptr IShellItem
          STD_METHOD RemoveAllRoots, :ptr INameSpaceTreeControl2
          STD_METHOD GetRootItems, :ptr INameSpaceTreeControl2, :ptr ptr IShellItemArray
          STD_METHOD SetItemState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          STD_METHOD GetItemState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :NSTCITEMSTATE, :ptr NSTCITEMSTATE
          STD_METHOD GetSelectedItems, :ptr INameSpaceTreeControl2, :ptr ptr IShellItemArray
          STD_METHOD GetItemCustomState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :ptr SDWORD
          STD_METHOD SetItemCustomState, :ptr INameSpaceTreeControl2, :ptr IShellItem, :SDWORD
          STD_METHOD EnsureItemVisible, :ptr INameSpaceTreeControl2, :ptr IShellItem
          STD_METHOD SetTheme, :ptr INameSpaceTreeControl2, :LPCWSTR
          STD_METHOD GetNextItem, :ptr INameSpaceTreeControl2, :ptr IShellItem, :NSTCGNI, :ptr ptr IShellItem
          STD_METHOD HitTest, :ptr INameSpaceTreeControl2, :ptr POINT, :ptr ptr IShellItem
          STD_METHOD GetItemRect, :ptr INameSpaceTreeControl2, :ptr IShellItem, :ptr RECT
          STD_METHOD CollapseAll, :ptr INameSpaceTreeControl2
          STD_METHOD SetControlStyle, :ptr INameSpaceTreeControl2, :NSTCSTYLE, :NSTCSTYLE
          STD_METHOD GetControlStyle, :ptr INameSpaceTreeControl2, :NSTCSTYLE, :ptr NSTCSTYLE
          STD_METHOD SetControlStyle2, :ptr INameSpaceTreeControl2, :NSTCSTYLE2, :NSTCSTYLE2
          STD_METHOD GetControlStyle2, :ptr INameSpaceTreeControl2, :NSTCSTYLE2, :ptr NSTCSTYLE2
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeControl2Vtbl ends

        INameSpaceTreeControl2 struct
          lpVtbl POINTER ?
        INameSpaceTreeControl2 ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
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
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControlEvents, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INameSpaceTreeControlEvents
          STD_METHOD Release, :ptr INameSpaceTreeControlEvents
          STD_METHOD OnItemClick, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :NSTCEHITTEST, :NSTCECLICKTYPE
          STD_METHOD OnPropertyItemCommit, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          STD_METHOD OnItemStateChanging, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          STD_METHOD OnItemStateChanged, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          STD_METHOD OnSelectionChanged, :ptr INameSpaceTreeControlEvents, :ptr IShellItemArray
          STD_METHOD OnKeyboardInput, :ptr INameSpaceTreeControlEvents, :UINT, :WPARAM, :LPARAM
          STD_METHOD OnBeforeExpand, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          STD_METHOD OnAfterExpand, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          STD_METHOD OnBeginLabelEdit, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          STD_METHOD OnEndLabelEdit, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          STD_METHOD OnGetToolTip, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :LPWSTR, :SDWORD
          STD_METHOD OnBeforeItemDelete, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
          STD_METHOD OnItemAdded, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :BOOL
          STD_METHOD OnItemDeleted, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :BOOL
          STD_METHOD OnBeforeContextMenu, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :REFIID, :ptr ptr
          STD_METHOD OnAfterContextMenu, :ptr INameSpaceTreeControlEvents, :ptr IShellItem, :ptr IContextMenu, :REFIID, :ptr ptr
          STD_METHOD OnBeforeStateImageChange, :ptr INameSpaceTreeControlEvents, :ptr IShellItem
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
      endif
    endif
    NSTCDHPOS_ONTOP equ -1
    externdef __MIDL_itf_shobjidl_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INameSpaceTreeControlDropHandler_INTERFACE_DEFINED__
      __INameSpaceTreeControlDropHandler_INTERFACE_DEFINED__ equ <>
      externdef IID_INameSpaceTreeControlDropHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeControlDropHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeControlDropHandlerVtbl>
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControlDropHandler, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INameSpaceTreeControlDropHandler
          STD_METHOD Release, :ptr INameSpaceTreeControlDropHandler
          STD_METHOD OnDragEnter, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :BOOL, :DWORD, :ptr DWORD
          STD_METHOD OnDragOver, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :DWORD, :ptr DWORD
          STD_METHOD OnDragPosition, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :SDWORD, :SDWORD
          STD_METHOD OnDrop, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :SDWORD, :DWORD, :ptr DWORD
          STD_METHOD OnDropPosition, :ptr INameSpaceTreeControlDropHandler, :ptr IShellItem, :ptr IShellItemArray, :SDWORD, :SDWORD
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
      endif
    endif
    ifndef __INameSpaceTreeAccessible_INTERFACE_DEFINED__
      __INameSpaceTreeAccessible_INTERFACE_DEFINED__ equ <>
      externdef IID_INameSpaceTreeAccessible:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeAccessibleVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeAccessibleVtbl>
          STD_METHOD QueryInterface, :ptr INameSpaceTreeAccessible, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INameSpaceTreeAccessible
          STD_METHOD Release, :ptr INameSpaceTreeAccessible
          STD_METHOD OnGetDefaultAccessibilityAction, :ptr INameSpaceTreeAccessible, :ptr IShellItem, :ptr BSTR
          STD_METHOD OnDoDefaultAccessibilityAction, :ptr INameSpaceTreeAccessible, :ptr IShellItem
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
      endif
    endif
    ifndef __INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED__
      __INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED__ equ <>
      NSTCCUSTOMDRAW struct
        psi POINTER ?
        uItemState UINT ?
        nstcis NSTCITEMSTATE ?
        pszText LPCWSTR ?
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
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControlCustomDraw, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INameSpaceTreeControlCustomDraw
          STD_METHOD Release, :ptr INameSpaceTreeControlCustomDraw
          STD_METHOD PrePaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT, :ptr LRESULT
          STD_METHOD PostPaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT
          STD_METHOD ItemPrePaint, :ptr INameSpaceTreeControlCustomDraw, :HDC, :ptr RECT, :ptr NSTCCUSTOMDRAW, :ptr COLORREF, :ptr COLORREF, :ptr LRESULT
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
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_0000_0044_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0044_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ITrayDeskBand_INTERFACE_DEFINED__
        __ITrayDeskBand_INTERFACE_DEFINED__ equ <>
        externdef IID_ITrayDeskBand:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITrayDeskBandVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITrayDeskBandVtbl>
            STD_METHOD QueryInterface, :ptr ITrayDeskBand, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ITrayDeskBand
            STD_METHOD Release, :ptr ITrayDeskBand
            STD_METHOD ShowDeskBand, :ptr ITrayDeskBand, :REFCLSID
            STD_METHOD HideDeskBand, :ptr ITrayDeskBand, :REFCLSID
            STD_METHOD IsDeskBandShown, :ptr ITrayDeskBand, :REFCLSID
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
        endif
      endif
      ifndef __IBandHost_INTERFACE_DEFINED__
        __IBandHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IBandHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBandHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBandHostVtbl>
            STD_METHOD QueryInterface, :ptr IBandHost, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IBandHost
            STD_METHOD Release, :ptr IBandHost
            STD_METHOD CreateBand, :ptr IBandHost, :REFCLSID, :BOOL, :BOOL, :REFIID, :ptr ptr
            STD_METHOD SetBandAvailability, :ptr IBandHost, :REFCLSID, :BOOL
            STD_METHOD DestroyBand, :ptr IBandHost, :REFCLSID
            ??Interface equ <>
            END_INTERFACE
          IBandHostVtbl ends

          IBandHost struct
            lpVtbl POINTER ?
          IBandHost ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_SBandHost equ <IID_IBandHost>
    endif
    externdef __MIDL_itf_shobjidl_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IInitializeNetworkFolder_INTERFACE_DEFINED__
      __IInitializeNetworkFolder_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeNetworkFolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeNetworkFolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeNetworkFolderVtbl>
          STD_METHOD QueryInterface, :ptr IInitializeNetworkFolder, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInitializeNetworkFolder
          STD_METHOD Release, :ptr IInitializeNetworkFolder
          STD_METHOD Initialize, :ptr IInitializeNetworkFolder, :PCIDLIST_ABSOLUTE, :PCIDLIST_ABSOLUTE, :UINT, :LPCWSTR, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IInitializeNetworkFolderVtbl ends

        IInitializeNetworkFolder struct
          lpVtbl POINTER ?
        IInitializeNetworkFolder ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IComputerInfoChangeNotify_INTERFACE_DEFINED__
      __IComputerInfoChangeNotify_INTERFACE_DEFINED__ equ <>
      externdef IID_IComputerInfoChangeNotify:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IComputerInfoChangeNotifyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IComputerInfoChangeNotifyVtbl>
          STD_METHOD QueryInterface, :ptr IComputerInfoChangeNotify, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IComputerInfoChangeNotify
          STD_METHOD Release, :ptr IComputerInfoChangeNotify
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
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
    endif
    externdef __MIDL_itf_shobjidl_0000_0050_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0050_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDesktopGadget_INTERFACE_DEFINED__
      __IDesktopGadget_INTERFACE_DEFINED__ equ <>
      externdef IID_IDesktopGadget:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDesktopGadgetVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDesktopGadgetVtbl>
          STD_METHOD QueryInterface, :ptr IDesktopGadget, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDesktopGadget
          STD_METHOD Release, :ptr IDesktopGadget
          STD_METHOD RunGadget, :ptr IDesktopGadget, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IDesktopGadgetVtbl ends

        IDesktopGadget struct
          lpVtbl POINTER ?
        IDesktopGadget ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
      externdef __MIDL_itf_shobjidl_0000_0051_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0051_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IVirtualDesktopManager_INTERFACE_DEFINED__
        __IVirtualDesktopManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IVirtualDesktopManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IVirtualDesktopManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IVirtualDesktopManagerVtbl>
            STD_METHOD QueryInterface, :ptr IVirtualDesktopManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IVirtualDesktopManager
            STD_METHOD Release, :ptr IVirtualDesktopManager
            STD_METHOD IsWindowOnCurrentVirtualDesktop, :ptr IVirtualDesktopManager, :HWND, :ptr BOOL
            STD_METHOD GetWindowDesktopId, :ptr IVirtualDesktopManager, :HWND, :ptr GUID
            STD_METHOD MoveWindowToDesktop, :ptr IVirtualDesktopManager, :HWND, :REFGUID
            ??Interface equ <>
            END_INTERFACE
          IVirtualDesktopManagerVtbl ends

          IVirtualDesktopManager struct
            lpVtbl POINTER ?
          IVirtualDesktopManager ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ShellObjects_LIBRARY_DEFINED__
      __ShellObjects_LIBRARY_DEFINED__ equ <>
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
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      if (_WIN32_IE ge _WIN32_IE_IE70)
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      UNDOCK_REASON typedef SDWORD
      UR_RESOLUTION_CHANGE equ 0
      UR_MONITOR_DISCONNECT equ 1
      
      externdef __MIDL_itf_shobjidl_0000_0053_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0053_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAccessibilityDockingServiceCallback_INTERFACE_DEFINED__
        __IAccessibilityDockingServiceCallback_INTERFACE_DEFINED__ equ <>
        externdef IID_IAccessibilityDockingServiceCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAccessibilityDockingServiceCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAccessibilityDockingServiceCallbackVtbl>
            STD_METHOD QueryInterface, :ptr IAccessibilityDockingServiceCallback, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAccessibilityDockingServiceCallback
            STD_METHOD Release, :ptr IAccessibilityDockingServiceCallback
            STD_METHOD Undocked, :ptr IAccessibilityDockingServiceCallback, :UNDOCK_REASON
            ??Interface equ <>
            END_INTERFACE
          IAccessibilityDockingServiceCallbackVtbl ends

          IAccessibilityDockingServiceCallback struct
            lpVtbl POINTER ?
          IAccessibilityDockingServiceCallback ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAccessibilityDockingService_INTERFACE_DEFINED__
        __IAccessibilityDockingService_INTERFACE_DEFINED__ equ <>
        externdef IID_IAccessibilityDockingService:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAccessibilityDockingServiceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAccessibilityDockingServiceVtbl>
            STD_METHOD QueryInterface, :ptr IAccessibilityDockingService, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAccessibilityDockingService
            STD_METHOD Release, :ptr IAccessibilityDockingService
            STD_METHOD GetAvailableSize, :ptr IAccessibilityDockingService, :HMONITOR, :ptr UINT, :ptr UINT
            STD_METHOD DockWindow, :ptr IAccessibilityDockingService, :HWND, :HMONITOR, :UINT, :ptr IAccessibilityDockingServiceCallback
            STD_METHOD UndockWindow, :ptr IAccessibilityDockingService, :HWND
            ??Interface equ <>
            END_INTERFACE
          IAccessibilityDockingServiceVtbl ends

          IAccessibilityDockingService struct
            lpVtbl POINTER ?
          IAccessibilityDockingService ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      externdef __MIDL_itf_shobjidl_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBannerNotificationHandler_INTERFACE_DEFINED__
        __IBannerNotificationHandler_INTERFACE_DEFINED__ equ <>
        BANNER_NOTIFICATION_EVENT typedef SDWORD
        BNE_Rendered equ 0
        BNE_Hovered equ
        BNE_Closed equ
        BNE_Dismissed equ
        BNE_Button1Clicked equ
        BNE_Button2Clicked equ
        
        BANNER_NOTIFICATION struct
          event_ BANNER_NOTIFICATION_EVENT ?
          providerIdentity LPCWSTR ?
          contentId LPCWSTR ?
        BANNER_NOTIFICATION ends

        externdef IID_IBannerNotificationHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBannerNotificationHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBannerNotificationHandlerVtbl>
            STD_METHOD QueryInterface, :ptr IBannerNotificationHandler, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IBannerNotificationHandler
            STD_METHOD Release, :ptr IBannerNotificationHandler
            STD_METHOD OnBannerEvent, :ptr IBannerNotificationHandler, :ptr BANNER_NOTIFICATION
            ??Interface equ <>
            END_INTERFACE
          IBannerNotificationHandlerVtbl ends

          IBannerNotificationHandler struct
            lpVtbl POINTER ?
          IBannerNotificationHandler ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IStorageProviderBanners_INTERFACE_DEFINED__
        __IStorageProviderBanners_INTERFACE_DEFINED__ equ <>
        externdef IID_IStorageProviderBanners:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IStorageProviderBannersVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IStorageProviderBannersVtbl>
            STD_METHOD QueryInterface, :ptr IStorageProviderBanners, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IStorageProviderBanners
            STD_METHOD Release, :ptr IStorageProviderBanners
            STD_METHOD SetBanner, :ptr IStorageProviderBanners, :LPCWSTR, :LPCWSTR, :LPCWSTR
            STD_METHOD ClearBanner, :ptr IStorageProviderBanners, :LPCWSTR, :LPCWSTR
            STD_METHOD ClearAllBanners, :ptr IStorageProviderBanners, :LPCWSTR
            STD_METHOD GetBanner, :ptr IStorageProviderBanners, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IStorageProviderBannersVtbl ends

          IStorageProviderBanners struct
            lpVtbl POINTER ?
          IStorageProviderBanners ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_shobjidl_0000_0057_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shobjidl_0000_0057_v0_0_s_ifspec:RPC_IF_HANDLE
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
  IResultsFolder_AddIDList_Proxy proto WIN_STD_CALL_CONV :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
  IResultsFolder_AddIDList_Stub proto WIN_STD_CALL_CONV :ptr IResultsFolder, :PCIDLIST_ABSOLUTE, :ptr PITEMID_CHILD
  ifdef __cplusplus
    ;[...]
  endif
endif

