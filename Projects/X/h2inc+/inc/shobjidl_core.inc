;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shobjidl_core.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:22:54

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
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
ifndef __shobjidl_core_h__
  __shobjidl_core_h__ equ <>
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
  ifndef __IContextMenu_FWD_DEFINED__
    __IContextMenu_FWD_DEFINED__ equ <>
  endif
  ifndef __IContextMenu2_FWD_DEFINED__
    __IContextMenu2_FWD_DEFINED__ equ <>
  endif
  ifndef __IContextMenu3_FWD_DEFINED__
    __IContextMenu3_FWD_DEFINED__ equ <>
  endif
  ifndef __IExecuteCommand_FWD_DEFINED__
    __IExecuteCommand_FWD_DEFINED__ equ <>
  endif
  ifndef __IPersistFolder_FWD_DEFINED__
    __IPersistFolder_FWD_DEFINED__ equ <>
  endif
  ifndef __IRunnableTask_FWD_DEFINED__
    __IRunnableTask_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellTaskScheduler_FWD_DEFINED__
    __IShellTaskScheduler_FWD_DEFINED__ equ <>
  endif
  ifndef __IPersistFolder2_FWD_DEFINED__
    __IPersistFolder2_FWD_DEFINED__ equ <>
  endif
  ifndef __IPersistFolder3_FWD_DEFINED__
    __IPersistFolder3_FWD_DEFINED__ equ <>
  endif
  ifndef __IPersistIDList_FWD_DEFINED__
    __IPersistIDList_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumIDList_FWD_DEFINED__
    __IEnumIDList_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumFullIDList_FWD_DEFINED__
    __IEnumFullIDList_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileSyncMergeHandler_FWD_DEFINED__
    __IFileSyncMergeHandler_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithFolderEnumMode_FWD_DEFINED__
    __IObjectWithFolderEnumMode_FWD_DEFINED__ equ <>
  endif
  ifndef __IParseAndCreateItem_FWD_DEFINED__
    __IParseAndCreateItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellFolder_FWD_DEFINED__
    __IShellFolder_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumExtraSearch_FWD_DEFINED__
    __IEnumExtraSearch_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellFolder2_FWD_DEFINED__
    __IShellFolder2_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellView_FWD_DEFINED__
    __IShellView_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellView2_FWD_DEFINED__
    __IShellView2_FWD_DEFINED__ equ <>
  endif
  ifndef __IFolderView_FWD_DEFINED__
    __IFolderView_FWD_DEFINED__ equ <>
  endif
  ifndef __IFolderView2_FWD_DEFINED__
    __IFolderView2_FWD_DEFINED__ equ <>
  endif
  ifndef __IFolderViewSettings_FWD_DEFINED__
    __IFolderViewSettings_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeNetworkFolder_FWD_DEFINED__
    __IInitializeNetworkFolder_FWD_DEFINED__ equ <>
  endif
  ifndef __INetworkFolderInternal_FWD_DEFINED__
    __INetworkFolderInternal_FWD_DEFINED__ equ <>
  endif
  ifndef __IPreviewHandlerVisuals_FWD_DEFINED__
    __IPreviewHandlerVisuals_FWD_DEFINED__ equ <>
  endif
  ifndef __ICommDlgBrowser_FWD_DEFINED__
    __ICommDlgBrowser_FWD_DEFINED__ equ <>
  endif
  ifndef __ICommDlgBrowser2_FWD_DEFINED__
    __ICommDlgBrowser2_FWD_DEFINED__ equ <>
  endif
  ifndef __IColumnManager_FWD_DEFINED__
    __IColumnManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IFolderFilterSite_FWD_DEFINED__
    __IFolderFilterSite_FWD_DEFINED__ equ <>
  endif
  ifndef __IFolderFilter_FWD_DEFINED__
    __IFolderFilter_FWD_DEFINED__ equ <>
  endif
  ifndef __IInputObjectSite_FWD_DEFINED__
    __IInputObjectSite_FWD_DEFINED__ equ <>
  endif
  ifndef __IInputObject_FWD_DEFINED__
    __IInputObject_FWD_DEFINED__ equ <>
  endif
  ifndef __IInputObject2_FWD_DEFINED__
    __IInputObject2_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellIcon_FWD_DEFINED__
    __IShellIcon_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellBrowser_FWD_DEFINED__
    __IShellBrowser_FWD_DEFINED__ equ <>
  endif
  ifndef __IProfferService_FWD_DEFINED__
    __IProfferService_FWD_DEFINED__ equ <>
  endif
  ifndef __IGetServiceIds_FWD_DEFINED__
    __IGetServiceIds_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellItem_FWD_DEFINED__
    __IShellItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellItem2_FWD_DEFINED__
    __IShellItem2_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellItemImageFactory_FWD_DEFINED__
    __IShellItemImageFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumShellItems_FWD_DEFINED__
    __IEnumShellItems_FWD_DEFINED__ equ <>
  endif
  ifndef __ITransferAdviseSink_FWD_DEFINED__
    __ITransferAdviseSink_FWD_DEFINED__ equ <>
  endif
  ifndef __ITransferSource_FWD_DEFINED__
    __ITransferSource_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumResources_FWD_DEFINED__
    __IEnumResources_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellItemResources_FWD_DEFINED__
    __IShellItemResources_FWD_DEFINED__ equ <>
  endif
  ifndef __ITransferDestination_FWD_DEFINED__
    __ITransferDestination_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileOperationProgressSink_FWD_DEFINED__
    __IFileOperationProgressSink_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellItemArray_FWD_DEFINED__
    __IShellItemArray_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeWithItem_FWD_DEFINED__
    __IInitializeWithItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithSelection_FWD_DEFINED__
    __IObjectWithSelection_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithBackReferences_FWD_DEFINED__
    __IObjectWithBackReferences_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyUI_FWD_DEFINED__
    __IPropertyUI_FWD_DEFINED__ equ <>
  endif
  ifndef __ICategoryProvider_FWD_DEFINED__
    __ICategoryProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __ICategorizer_FWD_DEFINED__
    __ICategorizer_FWD_DEFINED__ equ <>
  endif
  ifndef __IDropTargetHelper_FWD_DEFINED__
    __IDropTargetHelper_FWD_DEFINED__ equ <>
  endif
  ifndef __IDragSourceHelper_FWD_DEFINED__
    __IDragSourceHelper_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellLinkA_FWD_DEFINED__
    __IShellLinkA_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellLinkW_FWD_DEFINED__
    __IShellLinkW_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellLinkDataList_FWD_DEFINED__
    __IShellLinkDataList_FWD_DEFINED__ equ <>
  endif
  ifndef __IResolveShellLink_FWD_DEFINED__
    __IResolveShellLink_FWD_DEFINED__ equ <>
  endif
  ifndef __IActionProgressDialog_FWD_DEFINED__
    __IActionProgressDialog_FWD_DEFINED__ equ <>
  endif
  ifndef __IActionProgress_FWD_DEFINED__
    __IActionProgress_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellExtInit_FWD_DEFINED__
    __IShellExtInit_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellPropSheetExt_FWD_DEFINED__
    __IShellPropSheetExt_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteComputer_FWD_DEFINED__
    __IRemoteComputer_FWD_DEFINED__ equ <>
  endif
  ifndef __IQueryContinue_FWD_DEFINED__
    __IQueryContinue_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithCancelEvent_FWD_DEFINED__
    __IObjectWithCancelEvent_FWD_DEFINED__ equ <>
  endif
  ifndef __IUserNotification_FWD_DEFINED__
    __IUserNotification_FWD_DEFINED__ equ <>
  endif
  ifndef __IItemNameLimits_FWD_DEFINED__
    __IItemNameLimits_FWD_DEFINED__ equ <>
  endif
  ifndef __ISearchFolderItemFactory_FWD_DEFINED__
    __ISearchFolderItemFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IExtractImage_FWD_DEFINED__
    __IExtractImage_FWD_DEFINED__ equ <>
  endif
  ifndef __IExtractImage2_FWD_DEFINED__
    __IExtractImage2_FWD_DEFINED__ equ <>
  endif
  ifndef __IThumbnailHandlerFactory_FWD_DEFINED__
    __IThumbnailHandlerFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IParentAndItem_FWD_DEFINED__
    __IParentAndItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IDockingWindow_FWD_DEFINED__
    __IDockingWindow_FWD_DEFINED__ equ <>
  endif
  ifndef __IDeskBand_FWD_DEFINED__
    __IDeskBand_FWD_DEFINED__ equ <>
  endif
  ifndef __IDeskBandInfo_FWD_DEFINED__
    __IDeskBandInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __ITaskbarList_FWD_DEFINED__
    __ITaskbarList_FWD_DEFINED__ equ <>
  endif
  ifndef __ITaskbarList2_FWD_DEFINED__
    __ITaskbarList2_FWD_DEFINED__ equ <>
  endif
  ifndef __ITaskbarList3_FWD_DEFINED__
    __ITaskbarList3_FWD_DEFINED__ equ <>
  endif
  ifndef __ITaskbarList4_FWD_DEFINED__
    __ITaskbarList4_FWD_DEFINED__ equ <>
  endif
  ifndef __IExplorerBrowserEvents_FWD_DEFINED__
    __IExplorerBrowserEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IExplorerBrowser_FWD_DEFINED__
    __IExplorerBrowser_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumObjects_FWD_DEFINED__
    __IEnumObjects_FWD_DEFINED__ equ <>
  endif
  ifndef __IOperationsProgressDialog_FWD_DEFINED__
    __IOperationsProgressDialog_FWD_DEFINED__ equ <>
  endif
  ifndef __IIOCancelInformation_FWD_DEFINED__
    __IIOCancelInformation_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileOperation_FWD_DEFINED__
    __IFileOperation_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileOperation2_FWD_DEFINED__
    __IFileOperation2_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectProvider_FWD_DEFINED__
    __IObjectProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __INamespaceWalkCB_FWD_DEFINED__
    __INamespaceWalkCB_FWD_DEFINED__ equ <>
  endif
  ifndef __INamespaceWalkCB2_FWD_DEFINED__
    __INamespaceWalkCB2_FWD_DEFINED__ equ <>
  endif
  ifndef __INamespaceWalk_FWD_DEFINED__
    __INamespaceWalk_FWD_DEFINED__ equ <>
  endif
  ifndef __IBandSite_FWD_DEFINED__
    __IBandSite_FWD_DEFINED__ equ <>
  endif
  ifndef __IModalWindow_FWD_DEFINED__
    __IModalWindow_FWD_DEFINED__ equ <>
  endif
  ifndef __IContextMenuSite_FWD_DEFINED__
    __IContextMenuSite_FWD_DEFINED__ equ <>
  endif
  ifndef __IMenuBand_FWD_DEFINED__
    __IMenuBand_FWD_DEFINED__ equ <>
  endif
  ifndef __IRegTreeItem_FWD_DEFINED__
    __IRegTreeItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IDeskBar_FWD_DEFINED__
    __IDeskBar_FWD_DEFINED__ equ <>
  endif
  ifndef __IMenuPopup_FWD_DEFINED__
    __IMenuPopup_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileIsInUse_FWD_DEFINED__
    __IFileIsInUse_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileDialogEvents_FWD_DEFINED__
    __IFileDialogEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileDialog_FWD_DEFINED__
    __IFileDialog_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileSaveDialog_FWD_DEFINED__
    __IFileSaveDialog_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileOpenDialog_FWD_DEFINED__
    __IFileOpenDialog_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileDialogCustomize_FWD_DEFINED__
    __IFileDialogCustomize_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationAssociationRegistration_FWD_DEFINED__
    __IApplicationAssociationRegistration_FWD_DEFINED__ equ <>
  endif
  ifndef __IDelegateFolder_FWD_DEFINED__
    __IDelegateFolder_FWD_DEFINED__ equ <>
  endif
  ifndef __IBrowserFrameOptions_FWD_DEFINED__
    __IBrowserFrameOptions_FWD_DEFINED__ equ <>
  endif
  ifndef __INewWindowManager_FWD_DEFINED__
    __INewWindowManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IAttachmentExecute_FWD_DEFINED__
    __IAttachmentExecute_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellMenuCallback_FWD_DEFINED__
    __IShellMenuCallback_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellMenu_FWD_DEFINED__
    __IShellMenu_FWD_DEFINED__ equ <>
  endif
  ifndef __IKnownFolder_FWD_DEFINED__
    __IKnownFolder_FWD_DEFINED__ equ <>
  endif
  ifndef __IKnownFolderManager_FWD_DEFINED__
    __IKnownFolderManager_FWD_DEFINED__ equ <>
  endif
  ifndef __ISharingConfigurationManager_FWD_DEFINED__
    __ISharingConfigurationManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IRelatedItem_FWD_DEFINED__
    __IRelatedItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IIdentityName_FWD_DEFINED__
    __IIdentityName_FWD_DEFINED__ equ <>
  endif
  ifndef __IDelegateItem_FWD_DEFINED__
    __IDelegateItem_FWD_DEFINED__ equ <>
  endif
  ifndef __ICurrentItem_FWD_DEFINED__
    __ICurrentItem_FWD_DEFINED__ equ <>
  endif
  ifndef __ITransferMediumItem_FWD_DEFINED__
    __ITransferMediumItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IDisplayItem_FWD_DEFINED__
    __IDisplayItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IViewStateIdentityItem_FWD_DEFINED__
    __IViewStateIdentityItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IPreviewItem_FWD_DEFINED__
    __IPreviewItem_FWD_DEFINED__ equ <>
  endif
  ifndef __IDestinationStreamFactory_FWD_DEFINED__
    __IDestinationStreamFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreateProcessInputs_FWD_DEFINED__
    __ICreateProcessInputs_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreatingProcess_FWD_DEFINED__
    __ICreatingProcess_FWD_DEFINED__ equ <>
  endif
  ifndef __ILaunchUIContext_FWD_DEFINED__
    __ILaunchUIContext_FWD_DEFINED__ equ <>
  endif
  ifndef __ILaunchUIContextProvider_FWD_DEFINED__
    __ILaunchUIContextProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __INewMenuClient_FWD_DEFINED__
    __INewMenuClient_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeWithBindCtx_FWD_DEFINED__
    __IInitializeWithBindCtx_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellItemFilter_FWD_DEFINED__
    __IShellItemFilter_FWD_DEFINED__ equ <>
  endif
  ifndef __INameSpaceTreeControl_FWD_DEFINED__
    __INameSpaceTreeControl_FWD_DEFINED__ equ <>
  endif
  ifndef __INameSpaceTreeControlFolderCapabilities_FWD_DEFINED__
    __INameSpaceTreeControlFolderCapabilities_FWD_DEFINED__ equ <>
  endif
  ifndef __IPreviewHandler_FWD_DEFINED__
    __IPreviewHandler_FWD_DEFINED__ equ <>
  endif
  ifndef __IPreviewHandlerFrame_FWD_DEFINED__
    __IPreviewHandlerFrame_FWD_DEFINED__ equ <>
  endif
  ifndef __IExplorerPaneVisibility_FWD_DEFINED__
    __IExplorerPaneVisibility_FWD_DEFINED__ equ <>
  endif
  ifndef __IContextMenuCB_FWD_DEFINED__
    __IContextMenuCB_FWD_DEFINED__ equ <>
  endif
  ifndef __IDefaultExtractIconInit_FWD_DEFINED__
    __IDefaultExtractIconInit_FWD_DEFINED__ equ <>
  endif
  ifndef __IExplorerCommand_FWD_DEFINED__
    __IExplorerCommand_FWD_DEFINED__ equ <>
  endif
  ifndef __IExplorerCommandState_FWD_DEFINED__
    __IExplorerCommandState_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeCommand_FWD_DEFINED__
    __IInitializeCommand_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumExplorerCommand_FWD_DEFINED__
    __IEnumExplorerCommand_FWD_DEFINED__ equ <>
  endif
  ifndef __IExplorerCommandProvider_FWD_DEFINED__
    __IExplorerCommandProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __IOpenControlPanel_FWD_DEFINED__
    __IOpenControlPanel_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileSystemBindData_FWD_DEFINED__
    __IFileSystemBindData_FWD_DEFINED__ equ <>
  endif
  ifndef __IFileSystemBindData2_FWD_DEFINED__
    __IFileSystemBindData2_FWD_DEFINED__ equ <>
  endif
  ifndef __ICustomDestinationList_FWD_DEFINED__
    __ICustomDestinationList_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDestinations_FWD_DEFINED__
    __IApplicationDestinations_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDocumentLists_FWD_DEFINED__
    __IApplicationDocumentLists_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithAppUserModelID_FWD_DEFINED__
    __IObjectWithAppUserModelID_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithProgID_FWD_DEFINED__
    __IObjectWithProgID_FWD_DEFINED__ equ <>
  endif
  ifndef __IUpdateIDList_FWD_DEFINED__
    __IUpdateIDList_FWD_DEFINED__ equ <>
  endif
  ifndef __IDesktopWallpaper_FWD_DEFINED__
    __IDesktopWallpaper_FWD_DEFINED__ equ <>
  endif
  ifndef __IHomeGroup_FWD_DEFINED__
    __IHomeGroup_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeWithPropertyStore_FWD_DEFINED__
    __IInitializeWithPropertyStore_FWD_DEFINED__ equ <>
  endif
  ifndef __IOpenSearchSource_FWD_DEFINED__
    __IOpenSearchSource_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellLibrary_FWD_DEFINED__
    __IShellLibrary_FWD_DEFINED__ equ <>
  endif
  ifndef __IDefaultFolderMenuInitialize_FWD_DEFINED__
    __IDefaultFolderMenuInitialize_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationActivationManager_FWD_DEFINED__
    __IApplicationActivationManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IVirtualDesktopManager_FWD_DEFINED__
    __IVirtualDesktopManager_FWD_DEFINED__ equ <>
  endif
  ifndef __DesktopWallpaper_FWD_DEFINED__
    __DesktopWallpaper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ShellDesktop_FWD_DEFINED__
    __ShellDesktop_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ShellFSFolder_FWD_DEFINED__
    __ShellFSFolder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __NetworkPlaces_FWD_DEFINED__
    __NetworkPlaces_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ShellLink_FWD_DEFINED__
    __ShellLink_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DriveSizeCategorizer_FWD_DEFINED__
    __DriveSizeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DriveTypeCategorizer_FWD_DEFINED__
    __DriveTypeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __FreeSpaceCategorizer_FWD_DEFINED__
    __FreeSpaceCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SizeCategorizer_FWD_DEFINED__
    __SizeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __PropertiesUI_FWD_DEFINED__
    __PropertiesUI_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __UserNotification_FWD_DEFINED__
    __UserNotification_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __TaskbarList_FWD_DEFINED__
    __TaskbarList_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ShellItem_FWD_DEFINED__
    __ShellItem_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __NamespaceWalker_FWD_DEFINED__
    __NamespaceWalker_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __FileOperation_FWD_DEFINED__
    __FileOperation_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __FileOpenDialog_FWD_DEFINED__
    __FileOpenDialog_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __FileSaveDialog_FWD_DEFINED__
    __FileSaveDialog_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __KnownFolderManager_FWD_DEFINED__
    __KnownFolderManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SharingConfigurationManager_FWD_DEFINED__
    __SharingConfigurationManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __NetworkConnections_FWD_DEFINED__
    __NetworkConnections_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ScheduledTasks_FWD_DEFINED__
    __ScheduledTasks_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ApplicationAssociationRegistration_FWD_DEFINED__
    __ApplicationAssociationRegistration_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SearchFolderItemFactory_FWD_DEFINED__
    __SearchFolderItemFactory_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __OpenControlPanel_FWD_DEFINED__
    __OpenControlPanel_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __MailRecipient_FWD_DEFINED__
    __MailRecipient_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __NetworkExplorerFolder_FWD_DEFINED__
    __NetworkExplorerFolder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DestinationList_FWD_DEFINED__
    __DestinationList_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ApplicationDestinations_FWD_DEFINED__
    __ApplicationDestinations_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ApplicationDocumentLists_FWD_DEFINED__
    __ApplicationDocumentLists_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __HomeGroup_FWD_DEFINED__
    __HomeGroup_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ShellLibrary_FWD_DEFINED__
    __ShellLibrary_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __AppStartupLink_FWD_DEFINED__
    __AppStartupLink_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __EnumerableObjectCollection_FWD_DEFINED__
    __EnumerableObjectCollection_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __FrameworkInputPane_FWD_DEFINED__
    __FrameworkInputPane_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DefFolderMenu_FWD_DEFINED__
    __DefFolderMenu_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __AppVisibility_FWD_DEFINED__
    __AppVisibility_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __AppShellVerbHandler_FWD_DEFINED__
    __AppShellVerbHandler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ExecuteUnknown_FWD_DEFINED__
    __ExecuteUnknown_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __PackageDebugSettings_FWD_DEFINED__
    __PackageDebugSettings_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SuspensionDependencyManager_FWD_DEFINED__
    __SuspensionDependencyManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ApplicationActivationManager_FWD_DEFINED__
    __ApplicationActivationManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __ApplicationDesignModeSettings_FWD_DEFINED__
    __ApplicationDesignModeSettings_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __IAssocHandlerInvoker_FWD_DEFINED__
    __IAssocHandlerInvoker_FWD_DEFINED__ equ <>
  endif
  ifndef __IAssocHandler_FWD_DEFINED__
    __IAssocHandler_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumAssocHandlers_FWD_DEFINED__
    __IEnumAssocHandlers_FWD_DEFINED__ equ <>
  endif
  ifndef __IDataObjectProvider_FWD_DEFINED__
    __IDataObjectProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __IDataTransferManagerInterop_FWD_DEFINED__
    __IDataTransferManagerInterop_FWD_DEFINED__ equ <>
  endif
  ifndef __IFrameworkInputPaneHandler_FWD_DEFINED__
    __IFrameworkInputPaneHandler_FWD_DEFINED__ equ <>
  endif
  ifndef __IFrameworkInputPane_FWD_DEFINED__
    __IFrameworkInputPane_FWD_DEFINED__ equ <>
  endif
  ifndef __IAppVisibilityEvents_FWD_DEFINED__
    __IAppVisibilityEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IAppVisibility_FWD_DEFINED__
    __IAppVisibility_FWD_DEFINED__ equ <>
  endif
  ifndef __IPackageExecutionStateChangeNotification_FWD_DEFINED__
    __IPackageExecutionStateChangeNotification_FWD_DEFINED__ equ <>
  endif
  ifndef __IPackageDebugSettings_FWD_DEFINED__
    __IPackageDebugSettings_FWD_DEFINED__ equ <>
  endif
  ifndef __IPackageDebugSettings2_FWD_DEFINED__
    __IPackageDebugSettings2_FWD_DEFINED__ equ <>
  endif
  ifndef __ISuspensionDependencyManager_FWD_DEFINED__
    __ISuspensionDependencyManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IExecuteCommandApplicationHostEnvironment_FWD_DEFINED__
    __IExecuteCommandApplicationHostEnvironment_FWD_DEFINED__ equ <>
  endif
  ifndef __IExecuteCommandHost_FWD_DEFINED__
    __IExecuteCommandHost_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDesignModeSettings_FWD_DEFINED__
    __IApplicationDesignModeSettings_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDesignModeSettings2_FWD_DEFINED__
    __IApplicationDesignModeSettings2_FWD_DEFINED__ equ <>
  endif
  ifndef __ILaunchTargetMonitor_FWD_DEFINED__
    __ILaunchTargetMonitor_FWD_DEFINED__ equ <>
  endif
  ifndef __ILaunchSourceViewSizePreference_FWD_DEFINED__
    __ILaunchSourceViewSizePreference_FWD_DEFINED__ equ <>
  endif
  ifndef __ILaunchTargetViewSizePreference_FWD_DEFINED__
    __ILaunchTargetViewSizePreference_FWD_DEFINED__ equ <>
  endif
  ifndef __ILaunchSourceAppUserModelId_FWD_DEFINED__
    __ILaunchSourceAppUserModelId_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeWithWindow_FWD_DEFINED__
    __IInitializeWithWindow_FWD_DEFINED__ equ <>
  endif
  ifndef __IHandlerInfo_FWD_DEFINED__
    __IHandlerInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IHandlerInfo2_FWD_DEFINED__
    __IHandlerInfo2_FWD_DEFINED__ equ <>
  endif
  ifndef __IHandlerActivationHost_FWD_DEFINED__
    __IHandlerActivationHost_FWD_DEFINED__ equ <>
  endif
  ifndef __IAppActivationUIInfo_FWD_DEFINED__
    __IAppActivationUIInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IContactManagerInterop_FWD_DEFINED__
    __IContactManagerInterop_FWD_DEFINED__ equ <>
  endif
  ifndef __IShellIconOverlayIdentifier_FWD_DEFINED__
    __IShellIconOverlayIdentifier_FWD_DEFINED__ equ <>
  endif
  ifndef __IBannerNotificationHandler_FWD_DEFINED__
    __IBannerNotificationHandler_FWD_DEFINED__ equ <>
  endif
  ifndef __ISortColumnArray_FWD_DEFINED__
    __ISortColumnArray_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyKeyStore_FWD_DEFINED__
    __IPropertyKeyStore_FWD_DEFINED__ equ <>
  endif
  include objidl.inc
  include shtypes.inc
  include servprov.inc
  include comcat.inc
  include propsys.inc
  include ObjectArray.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include sherrors.inc
    ifndef SHSTDAPI
      if Defined(_SHELL32_)
        SHSTDAPI equ <STDAPI>
        SHSTDAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      else
        SHSTDAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        SHSTDAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      endif
    endif
    CMF_NORMAL equ 00000000h
    CMF_DEFAULTONLY equ 00000001h
    CMF_VERBSONLY equ 00000002h
    CMF_EXPLORE equ 00000004h
    CMF_NOVERBS equ 00000008h
    CMF_CANRENAME equ 00000010h
    CMF_NODEFAULT equ 00000020h
    if (NTDDI_VERSION lt NTDDI_VISTA)
      CMF_INCLUDESTATIC equ 00000040h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CMF_ITEMMENU equ 00000080h
    endif
    CMF_EXTENDEDVERBS equ 00000100h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CMF_DISABLEDVERBS equ 00000200h
    endif
    CMF_ASYNCVERBSTATE equ 00000400h
    CMF_OPTIMIZEFORINVOKE equ 00000800h
    CMF_SYNCCASCADEMENU equ 00001000h
    CMF_DONOTPICKDEFAULT equ 00002000h
    CMF_RESERVED equ 0ffff0000h
    GCS_VERBA equ 00000000h
    GCS_HELPTEXTA equ 00000001h
    GCS_VALIDATEA equ 00000002h
    GCS_VERBW equ 00000004h
    GCS_HELPTEXTW equ 00000005h
    GCS_VALIDATEW equ 00000006h
    GCS_VERBICONW equ 00000014h
    GCS_UNICODE equ 00000004h
    ifdef UNICODE
      GCS_VERB equ <GCS_VERBW>
      GCS_HELPTEXT equ <GCS_HELPTEXTW>
      GCS_VALIDATE equ <GCS_VALIDATEW>
    else
      GCS_VERB equ <GCS_VERBA>
      GCS_HELPTEXT equ <GCS_HELPTEXTA>
      GCS_VALIDATE equ <GCS_VALIDATEA>
    endif
    CMDSTR_NEWFOLDERA equ <"NewFolder">
    CMDSTR_VIEWLISTA equ <"ViewList">
    CMDSTR_VIEWDETAILSA equ <"ViewDetails">
    CMDSTR_NEWFOLDERW equ <L("NewFolder")>
    CMDSTR_VIEWLISTW equ <L("ViewList")>
    CMDSTR_VIEWDETAILSW equ <L("ViewDetails")>
    ifdef UNICODE
      CMDSTR_NEWFOLDER equ <CMDSTR_NEWFOLDERW>
      CMDSTR_VIEWLIST equ <CMDSTR_VIEWLISTW>
      CMDSTR_VIEWDETAILS equ <CMDSTR_VIEWDETAILSW>
    else
      CMDSTR_NEWFOLDER equ <CMDSTR_NEWFOLDERA>
      CMDSTR_VIEWLIST equ <CMDSTR_VIEWLISTA>
      CMDSTR_VIEWDETAILS equ <CMDSTR_VIEWDETAILSA>
    endif
    CMIC_MASK_HOTKEY equ <SEE_MASK_HOTKEY>
    CMIC_MASK_ICON equ <SEE_MASK_ICON>
    CMIC_MASK_FLAG_NO_UI equ <SEE_MASK_FLAG_NO_UI>
    CMIC_MASK_UNICODE equ <SEE_MASK_UNICODE>
    CMIC_MASK_NO_CONSOLE equ <SEE_MASK_NO_CONSOLE>
    if (NTDDI_VERSION lt NTDDI_VISTA)
      CMIC_MASK_HASLINKNAME equ <SEE_MASK_HASLINKNAME>
      CMIC_MASK_HASTITLE equ <SEE_MASK_HASTITLE>
    endif
    CMIC_MASK_FLAG_SEP_VDM equ <SEE_MASK_FLAG_SEPVDM>
    CMIC_MASK_ASYNCOK equ <SEE_MASK_ASYNCOK>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      CMIC_MASK_NOASYNC equ <SEE_MASK_NOASYNC>
    endif
    CMIC_MASK_SHIFT_DOWN equ 10000000h
    CMIC_MASK_CONTROL_DOWN equ 40000000h
    CMIC_MASK_FLAG_LOG_USAGE equ <SEE_MASK_FLAG_LOG_USAGE>
    CMIC_MASK_NOZONECHECKS equ <SEE_MASK_NOZONECHECKS>
    CMIC_MASK_PTINVOKE equ 20000000h
    include pshpack8.inc
    if  not Defined(HMONITOR_DECLARED) and  not Defined(HMONITOR) and (WINVER lt 0500h)
      HMONITOR_DECLARED equ <>
      DECLARE_HANDLE HMONITOR
    endif
    CMINVOKECOMMANDINFO struct
      cbSize DWORD ?
      fMask DWORD ?
      hwnd HWND ?
      lpVerb LPCSTR ?
      lpParameters LPCSTR ?
      lpDirectory LPCSTR ?
      nShow SDWORD ?
      dwHotKey DWORD ?
      hIcon HANDLE ?
    CMINVOKECOMMANDINFO ends
    _CMINVOKECOMMANDINFO typedef CMINVOKECOMMANDINFO
    LPCMINVOKECOMMANDINFO typedef ptr CMINVOKECOMMANDINFO
    PCCMINVOKECOMMANDINFO typedef ptr CMINVOKECOMMANDINFO
    CMINVOKECOMMANDINFOEX struct
      cbSize DWORD ?
      fMask DWORD ?
      hwnd HWND ?
      lpVerb LPCSTR ?
      lpParameters LPCSTR ?
      lpDirectory LPCSTR ?
      nShow SDWORD ?
      dwHotKey DWORD ?
      hIcon HANDLE ?
      lpTitle LPCSTR ?
      lpVerbW LPCWSTR ?
      lpParametersW LPCWSTR ?
      lpDirectoryW LPCWSTR ?
      lpTitleW LPCWSTR ?
      ptInvoke POINT <>
    CMINVOKECOMMANDINFOEX ends
    _CMINVOKECOMMANDINFOEX typedef CMINVOKECOMMANDINFOEX
    LPCMINVOKECOMMANDINFOEX typedef ptr CMINVOKECOMMANDINFOEX
    PCCMINVOKECOMMANDINFOEX typedef ptr CMINVOKECOMMANDINFOEX
    CMINVOKECOMMANDINFOEX_REMOTE struct
      cbSize DWORD ?
      fMask DWORD ?
      hwnd HWND ?
      lpVerbString LPCSTR ?
      lpParameters LPCSTR ?
      lpDirectory LPCSTR ?
      nShow SDWORD ?
      dwHotKey DWORD ?
      lpTitle LPCSTR ?
      lpVerbWString LPCWSTR ?
      lpParametersW LPCWSTR ?
      lpDirectoryW LPCWSTR ?
      lpTitleW LPCWSTR ?
      ptInvoke POINT <>
      lpVerbInt UINT ?
      lpVerbWInt UINT ?
    CMINVOKECOMMANDINFOEX_REMOTE ends
    include poppack.inc
    externdef __MIDL_itf_shobjidl_core_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IContextMenu_INTERFACE_DEFINED__
      __IContextMenu_INTERFACE_DEFINED__ equ <>
      externdef IID_IContextMenu:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IContextMenuVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IContextMenuVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IContextMenu, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IContextMenu
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IContextMenu
          DECLSPEC_XFGVIRT(IContextMenu, QueryContextMenu)
          STD_METHOD QueryContextMenu, :ptr IContextMenu, :HMENU, :UINT, :UINT, :UINT, :UINT
          DECLSPEC_XFGVIRT(IContextMenu, InvokeCommand)
          STD_METHOD InvokeCommand, :ptr IContextMenu, :ptr CMINVOKECOMMANDINFO
          DECLSPEC_XFGVIRT(IContextMenu, GetCommandString)
          STD_METHOD GetCommandString, :ptr IContextMenu, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
          ??Interface equ <>
          END_INTERFACE
        IContextMenuVtbl ends
        IContextMenu struct
          lpVtbl POINTER ?
        IContextMenu ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IContextMenu_RemoteQueryContextMenu_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu, :HMENU, :UINT, :UINT, :UINT, :UINT, :ptr UINT, :ptr ptr HANDLE, :ptr ptr ULONG
      IContextMenu_RemoteQueryContextMenu_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      IContextMenu_RemoteInvokeCommand_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu, :ptr CMINVOKECOMMANDINFOEX_REMOTE
      IContextMenu_RemoteInvokeCommand_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      IContextMenu_RemoteGetCommandString_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
      IContextMenu_RemoteGetCommandString_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    LPCONTEXTMENU typedef ptr IContextMenu
    externdef __MIDL_itf_shobjidl_core_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IContextMenu2_INTERFACE_DEFINED__
      __IContextMenu2_INTERFACE_DEFINED__ equ <>
      externdef IID_IContextMenu2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IContextMenu2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IContextMenu2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IContextMenu2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IContextMenu2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IContextMenu2
          DECLSPEC_XFGVIRT(IContextMenu, QueryContextMenu)
          STD_METHOD QueryContextMenu, :ptr IContextMenu2, :HMENU, :UINT, :UINT, :UINT, :UINT
          DECLSPEC_XFGVIRT(IContextMenu, InvokeCommand)
          STD_METHOD InvokeCommand, :ptr IContextMenu2, :ptr CMINVOKECOMMANDINFO
          DECLSPEC_XFGVIRT(IContextMenu, GetCommandString)
          STD_METHOD GetCommandString, :ptr IContextMenu2, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
          DECLSPEC_XFGVIRT(IContextMenu2, HandleMenuMsg)
          STD_METHOD HandleMenuMsg, :ptr IContextMenu2, :UINT, :WPARAM, :LPARAM
          ??Interface equ <>
          END_INTERFACE
        IContextMenu2Vtbl ends
        IContextMenu2 struct
          lpVtbl POINTER ?
        IContextMenu2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IContextMenu2_RemoteHandleMenuMsg_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu2, :UINT, :WPARAM, :LPARAM
      IContextMenu2_RemoteHandleMenuMsg_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    LPCONTEXTMENU2 typedef ptr IContextMenu2
    externdef __MIDL_itf_shobjidl_core_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IContextMenu3_INTERFACE_DEFINED__
      __IContextMenu3_INTERFACE_DEFINED__ equ <>
      externdef IID_IContextMenu3:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IContextMenu3Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IContextMenu3Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IContextMenu3, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IContextMenu3
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IContextMenu3
          DECLSPEC_XFGVIRT(IContextMenu, QueryContextMenu)
          STD_METHOD QueryContextMenu, :ptr IContextMenu3, :HMENU, :UINT, :UINT, :UINT, :UINT
          DECLSPEC_XFGVIRT(IContextMenu, InvokeCommand)
          STD_METHOD InvokeCommand, :ptr IContextMenu3, :ptr CMINVOKECOMMANDINFO
          DECLSPEC_XFGVIRT(IContextMenu, GetCommandString)
          STD_METHOD GetCommandString, :ptr IContextMenu3, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
          DECLSPEC_XFGVIRT(IContextMenu2, HandleMenuMsg)
          STD_METHOD HandleMenuMsg, :ptr IContextMenu3, :UINT, :WPARAM, :LPARAM
          DECLSPEC_XFGVIRT(IContextMenu3, HandleMenuMsg2)
          STD_METHOD HandleMenuMsg2, :ptr IContextMenu3, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
          ??Interface equ <>
          END_INTERFACE
        IContextMenu3Vtbl ends
        IContextMenu3 struct
          lpVtbl POINTER ?
        IContextMenu3 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IContextMenu3_RemoteHandleMenuMsg2_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu3, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
      IContextMenu3_RemoteHandleMenuMsg2_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    LPCONTEXTMENU3 typedef ptr IContextMenu3
    externdef __MIDL_itf_shobjidl_core_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IExecuteCommand_INTERFACE_DEFINED__
      __IExecuteCommand_INTERFACE_DEFINED__ equ <>
      externdef IID_IExecuteCommand:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExecuteCommandVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExecuteCommandVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IExecuteCommand, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IExecuteCommand
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IExecuteCommand
          DECLSPEC_XFGVIRT(IExecuteCommand, SetKeyState)
          STD_METHOD SetKeyState, :ptr IExecuteCommand, :DWORD
          DECLSPEC_XFGVIRT(IExecuteCommand, SetParameters)
          STD_METHOD SetParameters, :ptr IExecuteCommand, :LPCWSTR
          DECLSPEC_XFGVIRT(IExecuteCommand, SetPosition)
          STD_METHOD SetPosition, :ptr IExecuteCommand, :POINT
          DECLSPEC_XFGVIRT(IExecuteCommand, SetShowWindow)
          STD_METHOD SetShowWindow, :ptr IExecuteCommand, :SDWORD
          DECLSPEC_XFGVIRT(IExecuteCommand, SetNoShowUI)
          STD_METHOD SetNoShowUI, :ptr IExecuteCommand, :BOOL
          DECLSPEC_XFGVIRT(IExecuteCommand, SetDirectory)
          STD_METHOD SetDirectory, :ptr IExecuteCommand, :LPCWSTR
          DECLSPEC_XFGVIRT(IExecuteCommand, Execute)
          STD_METHOD Execute, :ptr IExecuteCommand
          ??Interface equ <>
          END_INTERFACE
        IExecuteCommandVtbl ends
        IExecuteCommand struct
          lpVtbl POINTER ?
        IExecuteCommand ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPersistFolder_INTERFACE_DEFINED__
      __IPersistFolder_INTERFACE_DEFINED__ equ <>
      externdef IID_IPersistFolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistFolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistFolderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPersistFolder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistFolder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistFolder
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistFolder, :ptr CLSID
          DECLSPEC_XFGVIRT(IPersistFolder, Initialize)
          STD_METHOD Initialize, :ptr IPersistFolder, :PCIDLIST_ABSOLUTE
          ??Interface equ <>
          END_INTERFACE
        IPersistFolderVtbl ends
        IPersistFolder struct
          lpVtbl POINTER ?
        IPersistFolder ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPPERSISTFOLDER typedef ptr IPersistFolder
    IRTIR_TASK_NOT_RUNNING equ 0
    IRTIR_TASK_RUNNING equ 1
    IRTIR_TASK_SUSPENDED equ 2
    IRTIR_TASK_PENDING equ 3
    IRTIR_TASK_FINISHED equ 4
    externdef __MIDL_itf_shobjidl_core_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IRunnableTask_INTERFACE_DEFINED__
      __IRunnableTask_INTERFACE_DEFINED__ equ <>
      externdef IID_IRunnableTask:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRunnableTaskVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRunnableTaskVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IRunnableTask, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRunnableTask
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRunnableTask
          DECLSPEC_XFGVIRT(IRunnableTask, Run)
          STD_METHOD Run, :ptr IRunnableTask
          DECLSPEC_XFGVIRT(IRunnableTask, Kill)
          STD_METHOD Kill_, :ptr IRunnableTask, :BOOL
          DECLSPEC_XFGVIRT(IRunnableTask, Suspend)
          STD_METHOD Suspend, :ptr IRunnableTask
          DECLSPEC_XFGVIRT(IRunnableTask, Resume)
          STD_METHOD Resume, :ptr IRunnableTask
          DECLSPEC_XFGVIRT(IRunnableTask, IsRunning)
          STD_METHOD IsRunning, :ptr IRunnableTask
          ??Interface equ <>
          END_INTERFACE
        IRunnableTaskVtbl ends
        IRunnableTask struct
          lpVtbl POINTER ?
        IRunnableTask ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    TOID_NULL equ <GUID_NULL>
    ITSAT_DEFAULT_LPARAM equ (- 1)
    ITSAT_DEFAULT_PRIORITY equ 10000000h
    ITSAT_MAX_PRIORITY equ 7fffffffh
    ITSAT_MIN_PRIORITY equ 00000000h
    ITSSFLAG_COMPLETE_ON_DESTROY equ 0000h
    ITSSFLAG_KILL_ON_DESTROY equ 0001h
    ITSSFLAG_FLAGS_MASK equ 0003h
    ITSS_THREAD_DESTROY_DEFAULT_TIMEOUT equ (10 * 1000)
    ITSS_THREAD_TERMINATE_TIMEOUT equ <(INFINITE)>
    ITSS_THREAD_TIMEOUT_NO_CHANGE equ (INFINITE - 1)
    externdef __MIDL_itf_shobjidl_core_0000_0006_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0006_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellTaskScheduler_INTERFACE_DEFINED__
      __IShellTaskScheduler_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellTaskScheduler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellTaskSchedulerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellTaskSchedulerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellTaskScheduler, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellTaskScheduler
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellTaskScheduler
          DECLSPEC_XFGVIRT(IShellTaskScheduler, AddTask)
          STD_METHOD AddTask, :ptr IShellTaskScheduler, :ptr IRunnableTask, :REFTASKOWNERID, :DWORD_PTR, :DWORD
          DECLSPEC_XFGVIRT(IShellTaskScheduler, RemoveTasks)
          STD_METHOD RemoveTasks, :ptr IShellTaskScheduler, :REFTASKOWNERID, :DWORD_PTR, :BOOL
          DECLSPEC_XFGVIRT(IShellTaskScheduler, CountTasks)
          STD_METHOD CountTasks, :ptr IShellTaskScheduler, :REFTASKOWNERID
          DECLSPEC_XFGVIRT(IShellTaskScheduler, Status)
          STD_METHOD Status, :ptr IShellTaskScheduler, :DWORD, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IShellTaskSchedulerVtbl ends
        IShellTaskScheduler struct
          lpVtbl POINTER ?
        IShellTaskScheduler ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SID_ShellTaskScheduler equ <IID_IShellTaskScheduler>
    externdef __MIDL_itf_shobjidl_core_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPersistFolder2_INTERFACE_DEFINED__
      __IPersistFolder2_INTERFACE_DEFINED__ equ <>
      externdef IID_IPersistFolder2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistFolder2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistFolder2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPersistFolder2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistFolder2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistFolder2
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistFolder2, :ptr CLSID
          DECLSPEC_XFGVIRT(IPersistFolder, Initialize)
          STD_METHOD Initialize, :ptr IPersistFolder2, :PCIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IPersistFolder2, GetCurFolder)
          STD_METHOD GetCurFolder, :ptr IPersistFolder2, :ptr PIDLIST_ABSOLUTE
          ??Interface equ <>
          END_INTERFACE
        IPersistFolder2Vtbl ends
        IPersistFolder2 struct
          lpVtbl POINTER ?
        IPersistFolder2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    CSIDL_FLAG_PFTI_TRACKTARGET equ <CSIDL_FLAG_DONT_VERIFY>
    include pshpack8.inc
    PERSIST_FOLDER_TARGET_INFO struct
      pidlTargetFolder PIDLIST_ABSOLUTE ?
      szTargetParsingName WCHAR 260 dup (?)
      szNetworkProvider WCHAR 260 dup (?)
      dwAttributes DWORD ?
      csidl SDWORD ?
    PERSIST_FOLDER_TARGET_INFO ends
    _PERSIST_FOLDER_TARGET_INFO typedef PERSIST_FOLDER_TARGET_INFO
    include poppack.inc
    externdef __MIDL_itf_shobjidl_core_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPersistFolder3_INTERFACE_DEFINED__
      __IPersistFolder3_INTERFACE_DEFINED__ equ <>
      externdef IID_IPersistFolder3:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistFolder3Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistFolder3Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPersistFolder3, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistFolder3
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistFolder3
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistFolder3, :ptr CLSID
          DECLSPEC_XFGVIRT(IPersistFolder, Initialize)
          STD_METHOD Initialize, :ptr IPersistFolder3, :PCIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IPersistFolder2, GetCurFolder)
          STD_METHOD GetCurFolder, :ptr IPersistFolder3, :ptr PIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IPersistFolder3, InitializeEx)
          STD_METHOD InitializeEx, :ptr IPersistFolder3, :ptr IBindCtx, :PCIDLIST_ABSOLUTE, :ptr PERSIST_FOLDER_TARGET_INFO
          DECLSPEC_XFGVIRT(IPersistFolder3, GetFolderTargetInfo)
          STD_METHOD GetFolderTargetInfo, :ptr IPersistFolder3, :ptr PERSIST_FOLDER_TARGET_INFO
          ??Interface equ <>
          END_INTERFACE
        IPersistFolder3Vtbl ends
        IPersistFolder3 struct
          lpVtbl POINTER ?
        IPersistFolder3 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_core_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPersistIDList_INTERFACE_DEFINED__
        __IPersistIDList_INTERFACE_DEFINED__ equ <>
        externdef IID_IPersistIDList:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPersistIDListVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPersistIDListVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPersistIDList, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPersistIDList
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPersistIDList
            DECLSPEC_XFGVIRT(IPersist, GetClassID)
            STD_METHOD GetClassID, :ptr IPersistIDList, :ptr CLSID
            DECLSPEC_XFGVIRT(IPersistIDList, SetIDList)
            STD_METHOD SetIDList, :ptr IPersistIDList, :PCIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IPersistIDList, GetIDList)
            STD_METHOD GetIDList, :ptr IPersistIDList, :ptr PIDLIST_ABSOLUTE
            ??Interface equ <>
            END_INTERFACE
          IPersistIDListVtbl ends
          IPersistIDList struct
            lpVtbl POINTER ?
          IPersistIDList ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumIDList_INTERFACE_DEFINED__
      __IEnumIDList_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumIDList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumIDListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumIDListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IEnumIDList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumIDList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumIDList
          DECLSPEC_XFGVIRT(IEnumIDList, Next)
          STD_METHOD Next, :ptr IEnumIDList, :ULONG, :ptr PITEMID_CHILD, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumIDList, Skip)
          STD_METHOD Skip, :ptr IEnumIDList, :ULONG
          DECLSPEC_XFGVIRT(IEnumIDList, Reset)
          STD_METHOD Reset, :ptr IEnumIDList
          DECLSPEC_XFGVIRT(IEnumIDList, Clone)
          STD_METHOD Clone, :ptr IEnumIDList, :ptr ptr IEnumIDList
          ??Interface equ <>
          END_INTERFACE
        IEnumIDListVtbl ends
        IEnumIDList struct
          lpVtbl POINTER ?
        IEnumIDList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IEnumIDList_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumIDList, :ULONG, :ptr PITEMID_CHILD, :ptr ULONG
      IEnumIDList_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    LPENUMIDLIST typedef ptr IEnumIDList
    externdef __MIDL_itf_shobjidl_core_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumFullIDList_INTERFACE_DEFINED__
      __IEnumFullIDList_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumFullIDList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumFullIDListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumFullIDListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IEnumFullIDList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumFullIDList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumFullIDList
          DECLSPEC_XFGVIRT(IEnumFullIDList, Next)
          STD_METHOD Next, :ptr IEnumFullIDList, :ULONG, :ptr PIDLIST_ABSOLUTE, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumFullIDList, Skip)
          STD_METHOD Skip, :ptr IEnumFullIDList, :ULONG
          DECLSPEC_XFGVIRT(IEnumFullIDList, Reset)
          STD_METHOD Reset, :ptr IEnumFullIDList
          DECLSPEC_XFGVIRT(IEnumFullIDList, Clone)
          STD_METHOD Clone, :ptr IEnumFullIDList, :ptr ptr IEnumFullIDList
          ??Interface equ <>
          END_INTERFACE
        IEnumFullIDListVtbl ends
        IEnumFullIDList struct
          lpVtbl POINTER ?
        IEnumFullIDList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IEnumFullIDList_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumFullIDList, :ULONG, :ptr PIDLIST_ABSOLUTE, :ptr ULONG
      IEnumFullIDList_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    _SHGDNF typedef SDWORD
    SHGDN_NORMAL equ 0
    SHGDN_INFOLDER equ 1h
    SHGDN_FOREDITING equ 1000h
    SHGDN_FORADDRESSBAR equ 4000h
    SHGDN_FORPARSING equ 8000h

    SHGDNF typedef DWORD
    _SHCONTF typedef SDWORD
    SHCONTF_CHECKING_FOR_CHILDREN equ 10h
    SHCONTF_FOLDERS equ 20h
    SHCONTF_NONFOLDERS equ 40h
    SHCONTF_INCLUDEHIDDEN equ 80h
    SHCONTF_INIT_ON_FIRST_NEXT equ 100h
    SHCONTF_NETPRINTERSRCH equ 200h
    SHCONTF_SHAREABLE equ 400h
    SHCONTF_STORAGE equ 800h
    SHCONTF_NAVIGATION_ENUM equ 1000h
    SHCONTF_FASTITEMS equ 2000h
    SHCONTF_FLATLIST equ 4000h
    SHCONTF_ENABLE_ASYNC equ 8000h
    SHCONTF_INCLUDESUPERHIDDEN equ 10000h

    SHCONTF typedef DWORD
    SHCIDS_ALLFIELDS equ 80000000h
    SHCIDS_CANONICALONLY equ 10000000h
    SHCIDS_BITMASK equ 0FFFF0000h
    SHCIDS_COLUMNMASK equ 0000FFFFh
    SFGAO_CANCOPY equ <DROPEFFECT_COPY>
    SFGAO_CANMOVE equ <DROPEFFECT_MOVE>
    SFGAO_CANLINK equ <DROPEFFECT_LINK>
    SFGAO_STORAGE equ 00000008h
    SFGAO_CANRENAME equ 00000010h
    SFGAO_CANDELETE equ 00000020h
    SFGAO_HASPROPSHEET equ 00000040h
    SFGAO_DROPTARGET equ 00000100h
    SFGAO_CAPABILITYMASK equ 00000177h
    SFGAO_PLACEHOLDER equ 00000800h
    SFGAO_SYSTEM equ 00001000h
    SFGAO_ENCRYPTED equ 00002000h
    SFGAO_ISSLOW equ 00004000h
    SFGAO_GHOSTED equ 00008000h
    SFGAO_LINK equ 00010000h
    SFGAO_SHARE equ 00020000h
    SFGAO_READONLY equ 00040000h
    SFGAO_HIDDEN equ 00080000h
    SFGAO_DISPLAYATTRMASK equ 000FC000h
    SFGAO_FILESYSANCESTOR equ 10000000h
    SFGAO_FOLDER equ 20000000h
    SFGAO_FILESYSTEM equ 40000000h
    SFGAO_HASSUBFOLDER equ 80000000h
    SFGAO_CONTENTSMASK equ 80000000h
    SFGAO_VALIDATE equ 01000000h
    SFGAO_REMOVABLE equ 02000000h
    SFGAO_COMPRESSED equ 04000000h
    SFGAO_BROWSABLE equ 08000000h
    SFGAO_NONENUMERATED equ 00100000h
    SFGAO_NEWCONTENT equ 00200000h
    SFGAO_CANMONIKER equ 00400000h
    SFGAO_HASSTORAGE equ 00400000h
    SFGAO_STREAM equ 00400000h
    SFGAO_STORAGEANCESTOR equ 00800000h
    SFGAO_STORAGECAPMASK equ 70C50008h
    SFGAO_PKEYSFGAOMASK equ 81044000h
    SFGAOF typedef ULONG
    SYNC_TRANSFER_STATUS typedef SDWORD
    STS_NONE equ 0
    STS_NEEDSUPLOAD equ 1h
    STS_NEEDSDOWNLOAD equ 2h
    STS_TRANSFERRING equ 4h
    STS_PAUSED equ 8h
    STS_HASERROR equ 10h
    STS_FETCHING_METADATA equ 20h
    STS_USER_REQUESTED_REFRESH equ 40h
    STS_HASWARNING equ 80h
    STS_EXCLUDED equ 100h
    STS_INCOMPLETE equ 200h
    STS_PLACEHOLDER_IFEMPTY equ 400h

    DEFINE_ENUM_FLAG_OPERATORS(SYNC_TRANSFER_STATUS)
    STORAGE_PROVIDER_FILE_FLAGS typedef SDWORD
    SPFF_NONE equ 0
    SPFF_DOWNLOAD_BY_DEFAULT equ 1h
    SPFF_CREATED_ON_THIS_DEVICE equ 2h

    DEFINE_ENUM_FLAG_OPERATORS(STORAGE_PROVIDER_FILE_FLAGS)
    PLACEHOLDER_STATES typedef SDWORD
    PS_NONE equ 0
    PS_MARKED_FOR_OFFLINE_AVAILABILITY equ 1h
    PS_FULL_PRIMARY_STREAM_AVAILABLE equ 2h
    PS_CREATE_FILE_ACCESSIBLE equ 4h
    PS_CLOUDFILE_PLACEHOLDER equ 8h
    PS_DEFAULT equ
    PS_ALL equ

    DEFINE_ENUM_FLAG_OPERATORS(PLACEHOLDER_STATES)
    CONFLICT_RESOLUTION_CLSID_KEY equ <L("ConflictResolutionCLSID")>
    MERGE_UPDATE_STATUS typedef SDWORD
    MUS_COMPLETE equ 0
    MUS_USERINPUTNEEDED equ
    MUS_FAILED equ

    externdef __MIDL_itf_shobjidl_core_0000_0012_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0012_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFileSyncMergeHandler_INTERFACE_DEFINED__
      __IFileSyncMergeHandler_INTERFACE_DEFINED__ equ <>
      externdef IID_IFileSyncMergeHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFileSyncMergeHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFileSyncMergeHandlerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IFileSyncMergeHandler, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFileSyncMergeHandler
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFileSyncMergeHandler
          DECLSPEC_XFGVIRT(IFileSyncMergeHandler, Merge)
          STD_METHOD Merge, :ptr IFileSyncMergeHandler, :LPCWSTR, :LPCWSTR, :ptr MERGE_UPDATE_STATUS
          DECLSPEC_XFGVIRT(IFileSyncMergeHandler, ShowResolveConflictUIAsync)
          STD_METHOD ShowResolveConflictUIAsync, :ptr IFileSyncMergeHandler, :LPCWSTR, :HMONITOR
          ??Interface equ <>
          END_INTERFACE
        IFileSyncMergeHandlerVtbl ends
        IFileSyncMergeHandler struct
          lpVtbl POINTER ?
        IFileSyncMergeHandler ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    STR_BIND_FORCE_FOLDER_SHORTCUT_RESOLVE equ <L("Force Folder Shortcut Resolve")>
    STR_AVOID_DRIVE_RESTRICTION_POLICY equ <L("Avoid Drive Restriction Policy")>
    STR_AVOID_DRIVE_RESTRICTION_POLICY equ <L("Avoid Drive Restriction Policy")>
    STR_SKIP_BINDING_CLSID equ <L("Skip Binding CLSID")>
    STR_PARSE_PREFER_FOLDER_BROWSING equ <L("Parse Prefer Folder Browsing")>
    STR_DONT_PARSE_RELATIVE equ <L("Don't Parse Relative")>
    STR_PARSE_TRANSLATE_ALIASES equ <L("Parse Translate Aliases")>
    STR_PARSE_SKIP_NET_CACHE equ <L("Skip Net Resource Cache")>
    STR_PARSE_SHELL_PROTOCOL_TO_FILE_OBJECTS equ <L("Parse Shell Protocol To File Objects")>
    if (_WIN32_IE ge 0700h)
      STR_TRACK_CLSID equ <L("Track the CLSID")>
      STR_INTERNAL_NAVIGATE equ <L("Internal Navigation")>
      STR_PARSE_PROPERTYSTORE equ <L("DelegateNamedProperties")>
      STR_NO_VALIDATE_FILENAME_CHARS equ <L("NoValidateFilenameChars")>
      STR_BIND_DELEGATE_CREATE_OBJECT equ <L("Delegate Object Creation")>
      STR_PARSE_ALLOW_INTERNET_SHELL_FOLDERS equ <L("Allow binding to Internet shell folder handlers and negate STR_PARSE_PREFER_WEB_BROWSING")>
      STR_PARSE_PREFER_WEB_BROWSING equ <L("Do not bind to Internet shell folder handlers")>
      STR_PARSE_SHOW_NET_DIAGNOSTICS_UI equ <L("Show network diagnostics UI")>
      STR_PARSE_DONT_REQUIRE_VALIDATED_URLS equ <L("Do not require validated URLs")>
      STR_INTERNETFOLDER_PARSE_ONLY_URLMON_BINDABLE equ <L("Validate URL")>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      BIND_INTERRUPTABLE equ 0FFFFFFFFh
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      STR_BIND_FOLDERS_READ_ONLY equ <L("Folders As Read Only")>
      STR_BIND_FOLDER_ENUM_MODE equ <L("Folder Enum Mode")>
      FOLDER_ENUM_MODE typedef SDWORD
      FEM_VIEWRESULT equ 0
      FEM_NAVIGATION equ 1

      externdef __MIDL_itf_shobjidl_core_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IObjectWithFolderEnumMode_INTERFACE_DEFINED__
        __IObjectWithFolderEnumMode_INTERFACE_DEFINED__ equ <>
        externdef IID_IObjectWithFolderEnumMode:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IObjectWithFolderEnumModeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IObjectWithFolderEnumModeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IObjectWithFolderEnumMode, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IObjectWithFolderEnumMode
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IObjectWithFolderEnumMode
            DECLSPEC_XFGVIRT(IObjectWithFolderEnumMode, SetMode)
            STD_METHOD SetMode, :ptr IObjectWithFolderEnumMode, :FOLDER_ENUM_MODE
            DECLSPEC_XFGVIRT(IObjectWithFolderEnumMode, GetMode)
            STD_METHOD GetMode, :ptr IObjectWithFolderEnumMode, :ptr FOLDER_ENUM_MODE
            ??Interface equ <>
            END_INTERFACE
          IObjectWithFolderEnumModeVtbl ends
          IObjectWithFolderEnumMode struct
            lpVtbl POINTER ?
          IObjectWithFolderEnumMode ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      STR_PARSE_WITH_EXPLICIT_PROGID equ <L("ExplicitProgid")>
      STR_PARSE_WITH_EXPLICIT_ASSOCAPP equ <L("ExplicitAssociationApp")>
      STR_PARSE_EXPLICIT_ASSOCIATION_SUCCESSFUL equ <L("ExplicitAssociationSuccessful")>
      STR_PARSE_AND_CREATE_ITEM equ <L("ParseAndCreateItem")>
      STR_PROPERTYBAG_PARAM equ <L("SHBindCtxPropertyBag")>
      STR_ENUM_ITEMS_FLAGS equ <L("SHCONTF")>
      STR_STORAGEITEM_CREATION_FLAGS equ <L("SHGETSTORAGEITEM")>
      externdef __MIDL_itf_shobjidl_core_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IParseAndCreateItem_INTERFACE_DEFINED__
        __IParseAndCreateItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IParseAndCreateItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IParseAndCreateItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IParseAndCreateItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IParseAndCreateItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IParseAndCreateItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IParseAndCreateItem
            DECLSPEC_XFGVIRT(IParseAndCreateItem, SetItem)
            STD_METHOD SetItem, :ptr IParseAndCreateItem, :ptr IShellItem
            DECLSPEC_XFGVIRT(IParseAndCreateItem, GetItem)
            STD_METHOD GetItem, :ptr IParseAndCreateItem, :REFIID, :ptr ptr
            ??Interface equ <>
            END_INTERFACE
          IParseAndCreateItemVtbl ends
          IParseAndCreateItem struct
            lpVtbl POINTER ?
          IParseAndCreateItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      STR_ITEM_CACHE_CONTEXT equ <L("ItemCacheContext")>
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellFolder_INTERFACE_DEFINED__
      __IShellFolder_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellFolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellFolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellFolderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellFolder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellFolder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellFolder
          DECLSPEC_XFGVIRT(IShellFolder, ParseDisplayName)
          STD_METHOD ParseDisplayName, :ptr IShellFolder, :HWND, :ptr IBindCtx, :LPWSTR, :ptr ULONG, :ptr PIDLIST_RELATIVE, :ptr ULONG
          DECLSPEC_XFGVIRT(IShellFolder, EnumObjects)
          STD_METHOD EnumObjects, :ptr IShellFolder, :HWND, :SHCONTF, :ptr ptr IEnumIDList
          DECLSPEC_XFGVIRT(IShellFolder, BindToObject)
          STD_METHOD BindToObject, :ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, BindToStorage)
          STD_METHOD BindToStorage, :ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, CompareIDs)
          STD_METHOD CompareIDs, :ptr IShellFolder, :LPARAM, :PCUIDLIST_RELATIVE, :PCUIDLIST_RELATIVE
          DECLSPEC_XFGVIRT(IShellFolder, CreateViewObject)
          STD_METHOD CreateViewObject, :ptr IShellFolder, :HWND, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, GetAttributesOf)
          STD_METHOD GetAttributesOf, :ptr IShellFolder, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr SFGAOF
          DECLSPEC_XFGVIRT(IShellFolder, GetUIObjectOf)
          STD_METHOD GetUIObjectOf, :ptr IShellFolder, :HWND, :UINT, :PCUITEMID_CHILD_ARRAY, :REFIID, :ptr UINT, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, GetDisplayNameOf)
          STD_METHOD GetDisplayNameOf, :ptr IShellFolder, :PCUITEMID_CHILD, :SHGDNF, :ptr STRRET
          DECLSPEC_XFGVIRT(IShellFolder, SetNameOf)
          STD_METHOD SetNameOf, :ptr IShellFolder, :HWND, :PCUITEMID_CHILD, :LPCWSTR, :SHGDNF, :ptr PITEMID_CHILD
          ??Interface equ <>
          END_INTERFACE
        IShellFolderVtbl ends
        IShellFolder struct
          lpVtbl POINTER ?
        IShellFolder ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IShellFolder_RemoteSetNameOf_Proxy proto WIN_STD_CALL_CONV :ptr IShellFolder, :HWND, :PCUITEMID_CHILD, :LPCWSTR, :SHGDNF, :ptr PITEMID_CHILD
      IShellFolder_RemoteSetNameOf_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    LPSHELLFOLDER typedef ptr IShellFolder
    EXTRASEARCH struct
      guidSearch GUID <>
      wszFriendlyName WCHAR 80 dup (?)
      wszUrl WCHAR 2084 dup (?)
    EXTRASEARCH ends
    LPEXTRASEARCH typedef ptr EXTRASEARCH
    externdef __MIDL_itf_shobjidl_core_0000_0016_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0016_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumExtraSearch_INTERFACE_DEFINED__
      __IEnumExtraSearch_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumExtraSearch:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumExtraSearchVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumExtraSearchVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IEnumExtraSearch, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumExtraSearch
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumExtraSearch
          DECLSPEC_XFGVIRT(IEnumExtraSearch, Next)
          STD_METHOD Next, :ptr IEnumExtraSearch, :ULONG, :ptr EXTRASEARCH, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumExtraSearch, Skip)
          STD_METHOD Skip, :ptr IEnumExtraSearch, :ULONG
          DECLSPEC_XFGVIRT(IEnumExtraSearch, Reset)
          STD_METHOD Reset, :ptr IEnumExtraSearch
          DECLSPEC_XFGVIRT(IEnumExtraSearch, Clone)
          STD_METHOD Clone, :ptr IEnumExtraSearch, :ptr ptr IEnumExtraSearch
          ??Interface equ <>
          END_INTERFACE
        IEnumExtraSearchVtbl ends
        IEnumExtraSearch struct
          lpVtbl POINTER ?
        IEnumExtraSearch ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPENUMEXTRASEARCH typedef ptr IEnumExtraSearch
    externdef __MIDL_itf_shobjidl_core_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellFolder2_INTERFACE_DEFINED__
      __IShellFolder2_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellFolder2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellFolder2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellFolder2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellFolder2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellFolder2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellFolder2
          DECLSPEC_XFGVIRT(IShellFolder, ParseDisplayName)
          STD_METHOD ParseDisplayName, :ptr IShellFolder2, :HWND, :ptr IBindCtx, :LPWSTR, :ptr ULONG, :ptr PIDLIST_RELATIVE, :ptr ULONG
          DECLSPEC_XFGVIRT(IShellFolder, EnumObjects)
          STD_METHOD EnumObjects, :ptr IShellFolder2, :HWND, :SHCONTF, :ptr ptr IEnumIDList
          DECLSPEC_XFGVIRT(IShellFolder, BindToObject)
          STD_METHOD BindToObject, :ptr IShellFolder2, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, BindToStorage)
          STD_METHOD BindToStorage, :ptr IShellFolder2, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, CompareIDs)
          STD_METHOD CompareIDs, :ptr IShellFolder2, :LPARAM, :PCUIDLIST_RELATIVE, :PCUIDLIST_RELATIVE
          DECLSPEC_XFGVIRT(IShellFolder, CreateViewObject)
          STD_METHOD CreateViewObject, :ptr IShellFolder2, :HWND, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, GetAttributesOf)
          STD_METHOD GetAttributesOf, :ptr IShellFolder2, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr SFGAOF
          DECLSPEC_XFGVIRT(IShellFolder, GetUIObjectOf)
          STD_METHOD GetUIObjectOf, :ptr IShellFolder2, :HWND, :UINT, :PCUITEMID_CHILD_ARRAY, :REFIID, :ptr UINT, :ptr ptr
          DECLSPEC_XFGVIRT(IShellFolder, GetDisplayNameOf)
          STD_METHOD GetDisplayNameOf, :ptr IShellFolder2, :PCUITEMID_CHILD, :SHGDNF, :ptr STRRET
          DECLSPEC_XFGVIRT(IShellFolder, SetNameOf)
          STD_METHOD SetNameOf, :ptr IShellFolder2, :HWND, :PCUITEMID_CHILD, :LPCWSTR, :SHGDNF, :ptr PITEMID_CHILD
          DECLSPEC_XFGVIRT(IShellFolder2, GetDefaultSearchGUID)
          STD_METHOD GetDefaultSearchGUID, :ptr IShellFolder2, :ptr GUID
          DECLSPEC_XFGVIRT(IShellFolder2, EnumSearches)
          STD_METHOD EnumSearches, :ptr IShellFolder2, :ptr ptr IEnumExtraSearch
          DECLSPEC_XFGVIRT(IShellFolder2, GetDefaultColumn)
          STD_METHOD GetDefaultColumn, :ptr IShellFolder2, :DWORD, :ptr ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IShellFolder2, GetDefaultColumnState)
          STD_METHOD GetDefaultColumnState, :ptr IShellFolder2, :UINT, :ptr SHCOLSTATEF
          DECLSPEC_XFGVIRT(IShellFolder2, GetDetailsEx)
          STD_METHOD GetDetailsEx, :ptr IShellFolder2, :PCUITEMID_CHILD, :ptr SHCOLUMNID, :ptr VARIANT
          DECLSPEC_XFGVIRT(IShellFolder2, GetDetailsOf)
          STD_METHOD GetDetailsOf, :ptr IShellFolder2, :PCUITEMID_CHILD, :UINT, :ptr SHELLDETAILS
          DECLSPEC_XFGVIRT(IShellFolder2, MapColumnToSCID)
          STD_METHOD MapColumnToSCID, :ptr IShellFolder2, :UINT, :ptr SHCOLUMNID
          ??Interface equ <>
          END_INTERFACE
        IShellFolder2Vtbl ends
        IShellFolder2 struct
          lpVtbl POINTER ?
        IShellFolder2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    FOLDERFLAGS typedef SDWORD
    FWF_NONE equ 0
    FWF_AUTOARRANGE equ 1h
    FWF_ABBREVIATEDNAMES equ 2h
    FWF_SNAPTOGRID equ 4h
    FWF_OWNERDATA equ 8h
    FWF_BESTFITWINDOW equ 10h
    FWF_DESKTOP equ 20h
    FWF_SINGLESEL equ 40h
    FWF_NOSUBFOLDERS equ 80h
    FWF_TRANSPARENT equ 100h
    FWF_NOCLIENTEDGE equ 200h
    FWF_NOSCROLL equ 400h
    FWF_ALIGNLEFT equ 800h
    FWF_NOICONS equ 1000h
    FWF_SHOWSELALWAYS equ 2000h
    FWF_NOVISIBLE equ 4000h
    FWF_SINGLECLICKACTIVATE equ 8000h
    FWF_NOWEBVIEW equ 10000h
    FWF_HIDEFILENAMES equ 20000h
    FWF_CHECKSELECT equ 40000h
    FWF_NOENUMREFRESH equ 80000h
    FWF_NOGROUPING equ 100000h
    FWF_FULLROWSELECT equ 200000h
    FWF_NOFILTERS equ 400000h
    FWF_NOCOLUMNHEADER equ 800000h
    FWF_NOHEADERINALLVIEWS equ 1000000h
    FWF_EXTENDEDTILES equ 2000000h
    FWF_TRICHECKSELECT equ 4000000h
    FWF_AUTOCHECKSELECT equ 8000000h
    FWF_NOBROWSERVIEWSTATE equ 10000000h
    FWF_SUBSETGROUPS equ 20000000h
    FWF_USESEARCHFOLDER equ 40000000h
    FWF_ALLOWRTLREADING equ 80000000h

    DEFINE_ENUM_FLAG_OPERATORS(FOLDERFLAGS)
    FOLDERVIEWMODE typedef SDWORD
    FVM_AUTO equ -1
    FVM_FIRST equ 1
    FVM_ICON equ 1
    FVM_SMALLICON equ 2
    FVM_LIST equ 3
    FVM_DETAILS equ 4
    FVM_THUMBNAIL equ 5
    FVM_TILE equ 6
    FVM_THUMBSTRIP equ 7
    FVM_CONTENT equ 8
    FVM_LAST equ 8

    if (NTDDI_VERSION ge NTDDI_VISTA)
      FOLDERLOGICALVIEWMODE typedef SDWORD
      FLVM_UNSPECIFIED equ -1
      FLVM_FIRST equ 1
      FLVM_DETAILS equ 1
      FLVM_TILES equ 2
      FLVM_ICONS equ 3
      FLVM_LIST equ 4
      FLVM_CONTENT equ 5
      FLVM_LAST equ 5

    endif
    FOLDERSETTINGS struct
      ViewMode UINT ?
      fFlags UINT ?
    FOLDERSETTINGS ends
    LPFOLDERSETTINGS typedef ptr FOLDERSETTINGS
    LPCFOLDERSETTINGS typedef ptr FOLDERSETTINGS
    PFOLDERSETTINGS typedef ptr FOLDERSETTINGS
    _SVSIF typedef SDWORD
    SVSI_DESELECT equ 0
    SVSI_SELECT equ 1h
    SVSI_EDIT equ 3h
    SVSI_DESELECTOTHERS equ 4h
    SVSI_ENSUREVISIBLE equ 8h
    SVSI_FOCUSED equ 10h
    SVSI_TRANSLATEPT equ 20h
    SVSI_SELECTIONMARK equ 40h
    SVSI_POSITIONITEM equ 80h
    SVSI_CHECK equ 100h
    SVSI_CHECK2 equ 200h
    SVSI_KEYBOARDSELECT equ 401h
    SVSI_NOTAKEFOCUS equ 40000000h

    SVSI_NOSTATECHANGE equ (80000000h)
    SVSIF typedef UINT
    _SVGIO typedef SDWORD
    SVGIO_BACKGROUND equ 0
    SVGIO_SELECTION equ 1h
    SVGIO_ALLVIEW equ 2h
    SVGIO_CHECKED equ 3h
    SVGIO_TYPE_MASK equ 0fh
    SVGIO_FLAG_VIEWORDER equ 80000000h

    DEFINE_ENUM_FLAG_OPERATORS(_SVGIO)
    SVGIO typedef SDWORD
    SVUIA_STATUS typedef SDWORD
    SVUIA_DEACTIVATE equ 0
    SVUIA_ACTIVATE_NOFOCUS equ 1
    SVUIA_ACTIVATE_FOCUS equ 2
    SVUIA_INPLACEACTIVATE equ 3

    ifdef _FIX_ENABLEMODELESS_CONFLICT
      EnableModeless equ <EnableModelessSV>
    endif
    ifdef _NEVER_
      LPFNSVADDPROPSHEETPAGE typedef LPARAM
    else
      include prsht.inc
      LPFNSVADDPROPSHEETPAGE typedef LPFNADDPROPSHEETPAGE
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0018_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0018_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellView_INTERFACE_DEFINED__
      __IShellView_INTERFACE_DEFINED__ equ <>
      LPSHELLVIEW typedef ptr IShellView
      externdef IID_IShellView:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellViewVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellViewVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellView, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellView
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellView
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          STD_METHOD GetWindow, :ptr IShellView, :ptr HWND
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IShellView, :BOOL
          DECLSPEC_XFGVIRT(IShellView, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IShellView, :ptr MSG
          DECLSPEC_XFGVIRT(IShellView, EnableModeless)
          STD_METHOD EnableModeless, :ptr IShellView, :BOOL
          DECLSPEC_XFGVIRT(IShellView, UIActivate)
          STD_METHOD UIActivate, :ptr IShellView, :UINT
          DECLSPEC_XFGVIRT(IShellView, Refresh)
          STD_METHOD Refresh, :ptr IShellView
          DECLSPEC_XFGVIRT(IShellView, CreateViewWindow)
          STD_METHOD CreateViewWindow, :ptr IShellView, :ptr IShellView, :LPCFOLDERSETTINGS, :ptr IShellBrowser, :ptr RECT, :ptr HWND
          DECLSPEC_XFGVIRT(IShellView, DestroyViewWindow)
          STD_METHOD DestroyViewWindow, :ptr IShellView
          DECLSPEC_XFGVIRT(IShellView, GetCurrentInfo)
          STD_METHOD GetCurrentInfo, :ptr IShellView, :LPFOLDERSETTINGS
          DECLSPEC_XFGVIRT(IShellView, AddPropertySheetPages)
          STD_METHOD AddPropertySheetPages, :ptr IShellView, :DWORD, :LPFNSVADDPROPSHEETPAGE, :LPARAM
          DECLSPEC_XFGVIRT(IShellView, SaveViewState)
          STD_METHOD SaveViewState, :ptr IShellView
          DECLSPEC_XFGVIRT(IShellView, SelectItem)
          STD_METHOD SelectItem, :ptr IShellView, :PCUITEMID_CHILD, :SVSIF
          DECLSPEC_XFGVIRT(IShellView, GetItemObject)
          STD_METHOD GetItemObject, :ptr IShellView, :UINT, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IShellViewVtbl ends
        IShellView struct
          lpVtbl POINTER ?
        IShellView ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellView2_INTERFACE_DEFINED__
      __IShellView2_INTERFACE_DEFINED__ equ <>
      SHELLVIEWID typedef GUID
      SV2GV_CURRENTVIEW equ (- 1)
      SV2GV_DEFAULTVIEW equ (- 2)
      include pshpack8.inc
      SV2CVW2_PARAMS struct
        cbSize DWORD ?
        psvPrev POINTER ?
        pfs LPCFOLDERSETTINGS ?
        psbOwner POINTER ?
        prcView POINTER ?
        pvid POINTER ?
        hwndView HWND ?
      SV2CVW2_PARAMS ends
      _SV2CVW2_PARAMS typedef SV2CVW2_PARAMS
      LPSV2CVW2_PARAMS typedef ptr _SV2CVW2_PARAMS
      include poppack.inc
      externdef IID_IShellView2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellView2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellView2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellView2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellView2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellView2
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          STD_METHOD GetWindow, :ptr IShellView2, :ptr HWND
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IShellView2, :BOOL
          DECLSPEC_XFGVIRT(IShellView, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IShellView2, :ptr MSG
          DECLSPEC_XFGVIRT(IShellView, EnableModeless)
          STD_METHOD EnableModeless, :ptr IShellView2, :BOOL
          DECLSPEC_XFGVIRT(IShellView, UIActivate)
          STD_METHOD UIActivate, :ptr IShellView2, :UINT
          DECLSPEC_XFGVIRT(IShellView, Refresh)
          STD_METHOD Refresh, :ptr IShellView2
          DECLSPEC_XFGVIRT(IShellView, CreateViewWindow)
          STD_METHOD CreateViewWindow, :ptr IShellView2, :ptr IShellView, :LPCFOLDERSETTINGS, :ptr IShellBrowser, :ptr RECT, :ptr HWND
          DECLSPEC_XFGVIRT(IShellView, DestroyViewWindow)
          STD_METHOD DestroyViewWindow, :ptr IShellView2
          DECLSPEC_XFGVIRT(IShellView, GetCurrentInfo)
          STD_METHOD GetCurrentInfo, :ptr IShellView2, :LPFOLDERSETTINGS
          DECLSPEC_XFGVIRT(IShellView, AddPropertySheetPages)
          STD_METHOD AddPropertySheetPages, :ptr IShellView2, :DWORD, :LPFNSVADDPROPSHEETPAGE, :LPARAM
          DECLSPEC_XFGVIRT(IShellView, SaveViewState)
          STD_METHOD SaveViewState, :ptr IShellView2
          DECLSPEC_XFGVIRT(IShellView, SelectItem)
          STD_METHOD SelectItem, :ptr IShellView2, :PCUITEMID_CHILD, :SVSIF
          DECLSPEC_XFGVIRT(IShellView, GetItemObject)
          STD_METHOD GetItemObject, :ptr IShellView2, :UINT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellView2, GetView)
          STD_METHOD GetView, :ptr IShellView2, :ptr SHELLVIEWID, :ULONG
          DECLSPEC_XFGVIRT(IShellView2, CreateViewWindow2)
          STD_METHOD CreateViewWindow2, :ptr IShellView2, :LPSV2CVW2_PARAMS
          DECLSPEC_XFGVIRT(IShellView2, HandleRename)
          STD_METHOD HandleRename, :ptr IShellView2, :PCUITEMID_CHILD
          DECLSPEC_XFGVIRT(IShellView2, SelectAndPositionItem)
          STD_METHOD SelectAndPositionItem, :ptr IShellView2, :PCUITEMID_CHILD, :UINT, :ptr POINT
          ??Interface equ <>
          END_INTERFACE
        IShellView2Vtbl ends
        IShellView2 struct
          lpVtbl POINTER ?
        IShellView2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifdef _FIX_ENABLEMODELESS_CONFLICT
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFolderView_INTERFACE_DEFINED__
      __IFolderView_INTERFACE_DEFINED__ equ <>
      externdef IID_IFolderView:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFolderViewVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFolderViewVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IFolderView, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFolderView
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFolderView
          DECLSPEC_XFGVIRT(IFolderView, GetCurrentViewMode)
          STD_METHOD GetCurrentViewMode, :ptr IFolderView, :ptr UINT
          DECLSPEC_XFGVIRT(IFolderView, SetCurrentViewMode)
          STD_METHOD SetCurrentViewMode, :ptr IFolderView, :UINT
          DECLSPEC_XFGVIRT(IFolderView, GetFolder)
          STD_METHOD GetFolder, :ptr IFolderView, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IFolderView, Item)
          STD_METHOD Item, :ptr IFolderView, :SDWORD, :ptr PITEMID_CHILD
          DECLSPEC_XFGVIRT(IFolderView, ItemCount)
          STD_METHOD ItemCount, :ptr IFolderView, :UINT, :ptr SDWORD
          DECLSPEC_XFGVIRT(IFolderView, Items)
          STD_METHOD Items, :ptr IFolderView, :UINT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IFolderView, GetSelectionMarkedItem)
          STD_METHOD GetSelectionMarkedItem, :ptr IFolderView, :ptr SDWORD
          DECLSPEC_XFGVIRT(IFolderView, GetFocusedItem)
          STD_METHOD GetFocusedItem, :ptr IFolderView, :ptr SDWORD
          DECLSPEC_XFGVIRT(IFolderView, GetItemPosition)
          STD_METHOD GetItemPosition, :ptr IFolderView, :PCUITEMID_CHILD, :ptr POINT
          DECLSPEC_XFGVIRT(IFolderView, GetSpacing)
          STD_METHOD GetSpacing, :ptr IFolderView, :ptr POINT
          DECLSPEC_XFGVIRT(IFolderView, GetDefaultSpacing)
          STD_METHOD GetDefaultSpacing, :ptr IFolderView, :ptr POINT
          DECLSPEC_XFGVIRT(IFolderView, GetAutoArrange)
          STD_METHOD GetAutoArrange, :ptr IFolderView
          DECLSPEC_XFGVIRT(IFolderView, SelectItem)
          STD_METHOD SelectItem, :ptr IFolderView, :SDWORD, :DWORD
          DECLSPEC_XFGVIRT(IFolderView, SelectAndPositionItems)
          STD_METHOD SelectAndPositionItems, :ptr IFolderView, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr POINT, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IFolderViewVtbl ends
        IFolderView struct
          lpVtbl POINTER ?
        IFolderView ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SID_SFolderView equ <IID_IFolderView>
    if (NTDDI_VERSION ge NTDDI_VISTA) or (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef NO_SHOBJIDL_SORTDIRECTION
        tagSORTDIRECTION typedef SDWORD
        SORT_DESCENDING equ -1
        SORT_ASCENDING equ 1

      endif
      SORTDIRECTION typedef SDWORD
      SORTCOLUMN struct
        propkey PROPERTYKEY <>
        direction SORTDIRECTION ?
      SORTCOLUMN ends
      FVTEXTTYPE typedef SDWORD
      FVST_EMPTYTEXT equ 0

      DEPRECATED_HRESULT typedef HRESULT
      if Defined(__cplusplus)
        ;[...]
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0021_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0021_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFolderView2_INTERFACE_DEFINED__
        __IFolderView2_INTERFACE_DEFINED__ equ <>
        externdef IID_IFolderView2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFolderView2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFolderView2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFolderView2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFolderView2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFolderView2
            DECLSPEC_XFGVIRT(IFolderView, GetCurrentViewMode)
            STD_METHOD GetCurrentViewMode, :ptr IFolderView2, :ptr UINT
            DECLSPEC_XFGVIRT(IFolderView, SetCurrentViewMode)
            STD_METHOD SetCurrentViewMode, :ptr IFolderView2, :UINT
            DECLSPEC_XFGVIRT(IFolderView, GetFolder)
            STD_METHOD GetFolder, :ptr IFolderView2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IFolderView, Item)
            STD_METHOD Item, :ptr IFolderView2, :SDWORD, :ptr PITEMID_CHILD
            DECLSPEC_XFGVIRT(IFolderView, ItemCount)
            STD_METHOD ItemCount, :ptr IFolderView2, :UINT, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView, Items)
            STD_METHOD Items, :ptr IFolderView2, :UINT, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IFolderView, GetSelectionMarkedItem)
            STD_METHOD GetSelectionMarkedItem, :ptr IFolderView2, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView, GetFocusedItem)
            STD_METHOD GetFocusedItem, :ptr IFolderView2, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView, GetItemPosition)
            STD_METHOD GetItemPosition, :ptr IFolderView2, :PCUITEMID_CHILD, :ptr POINT
            DECLSPEC_XFGVIRT(IFolderView, GetSpacing)
            STD_METHOD GetSpacing, :ptr IFolderView2, :ptr POINT
            DECLSPEC_XFGVIRT(IFolderView, GetDefaultSpacing)
            STD_METHOD GetDefaultSpacing, :ptr IFolderView2, :ptr POINT
            DECLSPEC_XFGVIRT(IFolderView, GetAutoArrange)
            STD_METHOD GetAutoArrange, :ptr IFolderView2
            DECLSPEC_XFGVIRT(IFolderView, SelectItem)
            STD_METHOD SelectItem, :ptr IFolderView2, :SDWORD, :DWORD
            DECLSPEC_XFGVIRT(IFolderView, SelectAndPositionItems)
            STD_METHOD SelectAndPositionItems, :ptr IFolderView2, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr POINT, :DWORD
            DECLSPEC_XFGVIRT(IFolderView2, SetGroupBy)
            STD_METHOD SetGroupBy, :ptr IFolderView2, :REFPROPERTYKEY, :BOOL
            DECLSPEC_XFGVIRT(IFolderView2, GetGroupBy)
            STD_METHOD GetGroupBy, :ptr IFolderView2, :ptr PROPERTYKEY, :ptr BOOL
            DECLSPEC_XFGVIRT(IFolderView2, SetViewProperty)
            STD_METHOD SetViewProperty, :ptr IFolderView2, :PCUITEMID_CHILD, :REFPROPERTYKEY, :REFPROPVARIANT
            DECLSPEC_XFGVIRT(IFolderView2, GetViewProperty)
            STD_METHOD GetViewProperty, :ptr IFolderView2, :PCUITEMID_CHILD, :REFPROPERTYKEY, :ptr PROPVARIANT
            DECLSPEC_XFGVIRT(IFolderView2, SetTileViewProperties)
            STD_METHOD SetTileViewProperties, :ptr IFolderView2, :PCUITEMID_CHILD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFolderView2, SetExtendedTileViewProperties)
            STD_METHOD SetExtendedTileViewProperties, :ptr IFolderView2, :PCUITEMID_CHILD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFolderView2, SetText)
            STD_METHOD SetText, :ptr IFolderView2, :FVTEXTTYPE, :LPCWSTR
            DECLSPEC_XFGVIRT(IFolderView2, SetCurrentFolderFlags)
            STD_METHOD SetCurrentFolderFlags, :ptr IFolderView2, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetCurrentFolderFlags)
            STD_METHOD GetCurrentFolderFlags, :ptr IFolderView2, :ptr DWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetSortColumnCount)
            STD_METHOD GetSortColumnCount, :ptr IFolderView2, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, SetSortColumns)
            STD_METHOD SetSortColumns, :ptr IFolderView2, :ptr SORTCOLUMN, :SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetSortColumns)
            STD_METHOD GetSortColumns, :ptr IFolderView2, :ptr SORTCOLUMN, :SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetItem)
            STD_METHOD GetItem, :ptr IFolderView2, :SDWORD, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IFolderView2, GetVisibleItem)
            STD_METHOD GetVisibleItem, :ptr IFolderView2, :SDWORD, :BOOL, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetSelectedItem)
            STD_METHOD GetSelectedItem, :ptr IFolderView2, :SDWORD, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetSelection)
            STD_METHOD GetSelection, :ptr IFolderView2, :BOOL, :ptr ptr IShellItemArray
            DECLSPEC_XFGVIRT(IFolderView2, GetSelectionState)
            STD_METHOD GetSelectionState, :ptr IFolderView2, :PCUITEMID_CHILD, :ptr DWORD
            DECLSPEC_XFGVIRT(IFolderView2, InvokeVerbOnSelection)
            STD_METHOD InvokeVerbOnSelection, :ptr IFolderView2, :LPCSTR
            DECLSPEC_XFGVIRT(IFolderView2, SetViewModeAndIconSize)
            STD_METHOD SetViewModeAndIconSize, :ptr IFolderView2, :FOLDERVIEWMODE, :SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, GetViewModeAndIconSize)
            STD_METHOD GetViewModeAndIconSize, :ptr IFolderView2, :ptr FOLDERVIEWMODE, :ptr SDWORD
            DECLSPEC_XFGVIRT(IFolderView2, SetGroupSubsetCount)
            STD_METHOD SetGroupSubsetCount, :ptr IFolderView2, :UINT
            DECLSPEC_XFGVIRT(IFolderView2, GetGroupSubsetCount)
            STD_METHOD GetGroupSubsetCount, :ptr IFolderView2, :ptr UINT
            DECLSPEC_XFGVIRT(IFolderView2, SetRedraw)
            STD_METHOD SetRedraw, :ptr IFolderView2, :BOOL
            DECLSPEC_XFGVIRT(IFolderView2, IsMoveInSameFolder)
            STD_METHOD IsMoveInSameFolder, :ptr IFolderView2
            DECLSPEC_XFGVIRT(IFolderView2, DoRename)
            STD_METHOD DoRename, :ptr IFolderView2
            ??Interface equ <>
            END_INTERFACE
          IFolderView2Vtbl ends
          IFolderView2 struct
            lpVtbl POINTER ?
          IFolderView2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IFolderView2_RemoteGetGroupBy_Proxy proto WIN_STD_CALL_CONV :ptr IFolderView2, :ptr PROPERTYKEY, :ptr BOOL
        IFolderView2_RemoteGetGroupBy_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        externdef __MIDL_itf_shobjidl_core_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IFolderViewSettings_INTERFACE_DEFINED__
          __IFolderViewSettings_INTERFACE_DEFINED__ equ <>
          externdef IID_IFolderViewSettings:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IFolderViewSettingsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IFolderViewSettingsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IFolderViewSettings, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IFolderViewSettings
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IFolderViewSettings
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetColumnPropertyList)
              STD_METHOD GetColumnPropertyList, :ptr IFolderViewSettings, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetGroupByProperty)
              STD_METHOD GetGroupByProperty, :ptr IFolderViewSettings, :ptr PROPERTYKEY, :ptr BOOL
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetViewMode)
              STD_METHOD GetViewMode, :ptr IFolderViewSettings, :ptr FOLDERLOGICALVIEWMODE
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetIconSize)
              STD_METHOD GetIconSize, :ptr IFolderViewSettings, :ptr UINT
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetFolderFlags)
              STD_METHOD GetFolderFlags, :ptr IFolderViewSettings, :ptr FOLDERFLAGS, :ptr FOLDERFLAGS
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetSortColumns)
              STD_METHOD GetSortColumns, :ptr IFolderViewSettings, :ptr SORTCOLUMN, :UINT, :ptr UINT
              DECLSPEC_XFGVIRT(IFolderViewSettings, GetGroupSubsetCount)
              STD_METHOD GetGroupSubsetCount, :ptr IFolderViewSettings, :ptr UINT
              ??Interface equ <>
              END_INTERFACE
            IFolderViewSettingsVtbl ends
            IFolderViewSettings struct
              lpVtbl POINTER ?
            IFolderViewSettings ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        ifndef __IInitializeNetworkFolder_INTERFACE_DEFINED__
          __IInitializeNetworkFolder_INTERFACE_DEFINED__ equ <>
          externdef IID_IInitializeNetworkFolder:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInitializeNetworkFolderVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInitializeNetworkFolderVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInitializeNetworkFolder, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInitializeNetworkFolder
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInitializeNetworkFolder
              DECLSPEC_XFGVIRT(IInitializeNetworkFolder, Initialize)
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
        ifndef __INetworkFolderInternal_INTERFACE_DEFINED__
          __INetworkFolderInternal_INTERFACE_DEFINED__ equ <>
          externdef IID_INetworkFolderInternal:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            INetworkFolderInternalVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <INetworkFolderInternalVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr INetworkFolderInternal, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr INetworkFolderInternal
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr INetworkFolderInternal
              DECLSPEC_XFGVIRT(INetworkFolderInternal, GetResourceDisplayType)
              STD_METHOD GetResourceDisplayType, :ptr INetworkFolderInternal, :ptr UINT
              DECLSPEC_XFGVIRT(INetworkFolderInternal, GetIDList)
              STD_METHOD GetIDList, :ptr INetworkFolderInternal, :ptr PIDLIST_ABSOLUTE
              DECLSPEC_XFGVIRT(INetworkFolderInternal, GetProvider)
              STD_METHOD GetProvider, :ptr INetworkFolderInternal, :UINT, :PCUITEMID_CHILD_ARRAY, :UINT, :LPWSTR
              ??Interface equ <>
              END_INTERFACE
            INetworkFolderInternalVtbl ends
            INetworkFolderInternal struct
              lpVtbl POINTER ?
            INetworkFolderInternal ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_core_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPreviewHandlerVisuals_INTERFACE_DEFINED__
        __IPreviewHandlerVisuals_INTERFACE_DEFINED__ equ <>
        externdef IID_IPreviewHandlerVisuals:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPreviewHandlerVisualsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPreviewHandlerVisualsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPreviewHandlerVisuals, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPreviewHandlerVisuals
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPreviewHandlerVisuals
            DECLSPEC_XFGVIRT(IPreviewHandlerVisuals, SetBackgroundColor)
            STD_METHOD SetBackgroundColor, :ptr IPreviewHandlerVisuals, :COLORREF
            DECLSPEC_XFGVIRT(IPreviewHandlerVisuals, SetFont)
            STD_METHOD SetFont, :ptr IPreviewHandlerVisuals, :ptr LOGFONTW
            DECLSPEC_XFGVIRT(IPreviewHandlerVisuals, SetTextColor)
            STD_METHOD SetTextColor, :ptr IPreviewHandlerVisuals, :COLORREF
            ??Interface equ <>
            END_INTERFACE
          IPreviewHandlerVisualsVtbl ends
          IPreviewHandlerVisuals struct
            lpVtbl POINTER ?
          IPreviewHandlerVisuals ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    CDBOSC_SETFOCUS equ 00000000h
    CDBOSC_KILLFOCUS equ 00000001h
    CDBOSC_SELCHANGE equ 00000002h
    CDBOSC_RENAME equ 00000003h
    CDBOSC_STATECHANGE equ 00000004h
    externdef __MIDL_itf_shobjidl_core_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ICommDlgBrowser_INTERFACE_DEFINED__
      __ICommDlgBrowser_INTERFACE_DEFINED__ equ <>
      externdef IID_ICommDlgBrowser:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICommDlgBrowserVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICommDlgBrowserVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICommDlgBrowser, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICommDlgBrowser
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICommDlgBrowser
          DECLSPEC_XFGVIRT(ICommDlgBrowser, OnDefaultCommand)
          STD_METHOD OnDefaultCommand, :ptr ICommDlgBrowser, :ptr IShellView
          DECLSPEC_XFGVIRT(ICommDlgBrowser, OnStateChange)
          STD_METHOD OnStateChange, :ptr ICommDlgBrowser, :ptr IShellView, :ULONG
          DECLSPEC_XFGVIRT(ICommDlgBrowser, IncludeObject)
          STD_METHOD IncludeObject, :ptr ICommDlgBrowser, :ptr IShellView, :PCUITEMID_CHILD
          ??Interface equ <>
          END_INTERFACE
        ICommDlgBrowserVtbl ends
        ICommDlgBrowser struct
          lpVtbl POINTER ?
        ICommDlgBrowser ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPCOMMDLGBROWSER typedef ptr ICommDlgBrowser
    SID_SExplorerBrowserFrame equ <IID_ICommDlgBrowser>
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      CDB2N_CONTEXTMENU_DONE equ 00000001h
      CDB2N_CONTEXTMENU_START equ 00000002h
      CDB2GVF_SHOWALLFILES equ 00000001h
      if (NTDDI_VERSION ge NTDDI_VISTA)
        CDB2GVF_ISFILESAVE equ 00000002h
        CDB2GVF_ALLOWPREVIEWPANE equ 00000004h
        CDB2GVF_NOSELECTVERB equ 00000008h
        CDB2GVF_NOINCLUDEITEM equ 00000010h
        CDB2GVF_ISFOLDERPICKER equ 00000020h
        CDB2GVF_ADDSHIELD equ 00000040h
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICommDlgBrowser2_INTERFACE_DEFINED__
        __ICommDlgBrowser2_INTERFACE_DEFINED__ equ <>
        externdef IID_ICommDlgBrowser2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICommDlgBrowser2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICommDlgBrowser2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICommDlgBrowser2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICommDlgBrowser2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICommDlgBrowser2
            DECLSPEC_XFGVIRT(ICommDlgBrowser, OnDefaultCommand)
            STD_METHOD OnDefaultCommand, :ptr ICommDlgBrowser2, :ptr IShellView
            DECLSPEC_XFGVIRT(ICommDlgBrowser, OnStateChange)
            STD_METHOD OnStateChange, :ptr ICommDlgBrowser2, :ptr IShellView, :ULONG
            DECLSPEC_XFGVIRT(ICommDlgBrowser, IncludeObject)
            STD_METHOD IncludeObject, :ptr ICommDlgBrowser2, :ptr IShellView, :PCUITEMID_CHILD
            DECLSPEC_XFGVIRT(ICommDlgBrowser2, Notify)
            STD_METHOD Notify, :ptr ICommDlgBrowser2, :ptr IShellView, :DWORD
            DECLSPEC_XFGVIRT(ICommDlgBrowser2, GetDefaultMenuText)
            STD_METHOD GetDefaultMenuText, :ptr ICommDlgBrowser2, :ptr IShellView, :LPWSTR, :SDWORD
            DECLSPEC_XFGVIRT(ICommDlgBrowser2, GetViewFlags)
            STD_METHOD GetViewFlags, :ptr ICommDlgBrowser2, :ptr DWORD
            ??Interface equ <>
            END_INTERFACE
          ICommDlgBrowser2Vtbl ends
          ICommDlgBrowser2 struct
            lpVtbl POINTER ?
          ICommDlgBrowser2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      LPCOMMDLGBROWSER2 typedef ptr ICommDlgBrowser2
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      CM_MASK typedef SDWORD
      CM_MASK_WIDTH equ 1h
      CM_MASK_DEFAULTWIDTH equ 2h
      CM_MASK_IDEALWIDTH equ 4h
      CM_MASK_NAME equ 8h
      CM_MASK_STATE equ 10h

      DEFINE_ENUM_FLAG_OPERATORS(CM_MASK)
      CM_STATE typedef SDWORD
      CM_STATE_NONE equ 0
      CM_STATE_VISIBLE equ 1h
      CM_STATE_FIXEDWIDTH equ 2h
      CM_STATE_NOSORTBYFOLDERNESS equ 4h
      CM_STATE_ALWAYSVISIBLE equ 8h

      DEFINE_ENUM_FLAG_OPERATORS(CM_STATE)
      CM_ENUM_FLAGS typedef SDWORD
      CM_ENUM_ALL equ 1h
      CM_ENUM_VISIBLE equ 2h

      DEFINE_ENUM_FLAG_OPERATORS(CM_ENUM_FLAGS)
      CM_SET_WIDTH_VALUE typedef SDWORD
      CM_WIDTH_USEDEFAULT equ -1
      CM_WIDTH_AUTOSIZE equ -2

      CM_COLUMNINFO struct
        cbSize DWORD ?
        dwMask DWORD ?
        dwState DWORD ?
        uWidth UINT ?
        uDefaultWidth UINT ?
        uIdealWidth UINT ?
        wszName WCHAR 80 dup (?)
      CM_COLUMNINFO ends
      externdef __MIDL_itf_shobjidl_core_0000_0028_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0028_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IColumnManager_INTERFACE_DEFINED__
        __IColumnManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IColumnManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IColumnManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IColumnManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IColumnManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IColumnManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IColumnManager
            DECLSPEC_XFGVIRT(IColumnManager, SetColumnInfo)
            STD_METHOD SetColumnInfo, :ptr IColumnManager, :REFPROPERTYKEY, :ptr CM_COLUMNINFO
            DECLSPEC_XFGVIRT(IColumnManager, GetColumnInfo)
            STD_METHOD GetColumnInfo, :ptr IColumnManager, :REFPROPERTYKEY, :ptr CM_COLUMNINFO
            DECLSPEC_XFGVIRT(IColumnManager, GetColumnCount)
            STD_METHOD GetColumnCount, :ptr IColumnManager, :CM_ENUM_FLAGS, :ptr UINT
            DECLSPEC_XFGVIRT(IColumnManager, GetColumns)
            STD_METHOD GetColumns, :ptr IColumnManager, :CM_ENUM_FLAGS, :ptr PROPERTYKEY, :UINT
            DECLSPEC_XFGVIRT(IColumnManager, SetColumns)
            STD_METHOD SetColumns, :ptr IColumnManager, :ptr PROPERTYKEY, :UINT
            ??Interface equ <>
            END_INTERFACE
          IColumnManagerVtbl ends
          IColumnManager struct
            lpVtbl POINTER ?
          IColumnManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFolderFilterSite_INTERFACE_DEFINED__
      __IFolderFilterSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IFolderFilterSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFolderFilterSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFolderFilterSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IFolderFilterSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFolderFilterSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFolderFilterSite
          DECLSPEC_XFGVIRT(IFolderFilterSite, SetFilter)
          STD_METHOD SetFilter, :ptr IFolderFilterSite, :ptr IUnknown
          ??Interface equ <>
          END_INTERFACE
        IFolderFilterSiteVtbl ends
        IFolderFilterSite struct
          lpVtbl POINTER ?
        IFolderFilterSite ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IFolderFilter_INTERFACE_DEFINED__
      __IFolderFilter_INTERFACE_DEFINED__ equ <>
      externdef IID_IFolderFilter:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFolderFilterVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFolderFilterVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IFolderFilter, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFolderFilter
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFolderFilter
          DECLSPEC_XFGVIRT(IFolderFilter, ShouldShow)
          STD_METHOD ShouldShow, :ptr IFolderFilter, :ptr IShellFolder, :PCIDLIST_ABSOLUTE, :PCUITEMID_CHILD
          DECLSPEC_XFGVIRT(IFolderFilter, GetEnumFlags)
          STD_METHOD GetEnumFlags, :ptr IFolderFilter, :ptr IShellFolder, :PCIDLIST_ABSOLUTE, :ptr HWND, :ptr DWORD
          ??Interface equ <>
          END_INTERFACE
        IFolderFilterVtbl ends
        IFolderFilter struct
          lpVtbl POINTER ?
        IFolderFilter ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IInputObjectSite_INTERFACE_DEFINED__
      __IInputObjectSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IInputObjectSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInputObjectSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInputObjectSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInputObjectSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInputObjectSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInputObjectSite
          DECLSPEC_XFGVIRT(IInputObjectSite, OnFocusChangeIS)
          STD_METHOD OnFocusChangeIS, :ptr IInputObjectSite, :ptr IUnknown, :BOOL
          ??Interface equ <>
          END_INTERFACE
        IInputObjectSiteVtbl ends
        IInputObjectSite struct
          lpVtbl POINTER ?
        IInputObjectSite ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IInputObject_INTERFACE_DEFINED__
      __IInputObject_INTERFACE_DEFINED__ equ <>
      externdef IID_IInputObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInputObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInputObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInputObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInputObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInputObject
          DECLSPEC_XFGVIRT(IInputObject, UIActivateIO)
          STD_METHOD UIActivateIO, :ptr IInputObject, :BOOL, :ptr MSG
          DECLSPEC_XFGVIRT(IInputObject, HasFocusIO)
          STD_METHOD HasFocusIO, :ptr IInputObject
          DECLSPEC_XFGVIRT(IInputObject, TranslateAcceleratorIO)
          STD_METHOD TranslateAcceleratorIO, :ptr IInputObject, :ptr MSG
          ??Interface equ <>
          END_INTERFACE
        IInputObjectVtbl ends
        IInputObject struct
          lpVtbl POINTER ?
        IInputObject ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IInputObject2_INTERFACE_DEFINED__
      __IInputObject2_INTERFACE_DEFINED__ equ <>
      externdef IID_IInputObject2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInputObject2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInputObject2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInputObject2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInputObject2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInputObject2
          DECLSPEC_XFGVIRT(IInputObject, UIActivateIO)
          STD_METHOD UIActivateIO, :ptr IInputObject2, :BOOL, :ptr MSG
          DECLSPEC_XFGVIRT(IInputObject, HasFocusIO)
          STD_METHOD HasFocusIO, :ptr IInputObject2
          DECLSPEC_XFGVIRT(IInputObject, TranslateAcceleratorIO)
          STD_METHOD TranslateAcceleratorIO, :ptr IInputObject2, :ptr MSG
          DECLSPEC_XFGVIRT(IInputObject2, TranslateAcceleratorGlobal)
          STD_METHOD TranslateAcceleratorGlobal, :ptr IInputObject2, :ptr MSG
          ??Interface equ <>
          END_INTERFACE
        IInputObject2Vtbl ends
        IInputObject2 struct
          lpVtbl POINTER ?
        IInputObject2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellIcon_INTERFACE_DEFINED__
      __IShellIcon_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellIcon:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellIconVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellIconVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellIcon, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellIcon
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellIcon
          DECLSPEC_XFGVIRT(IShellIcon, GetIconOf)
          STD_METHOD GetIconOf, :ptr IShellIcon, :PCUITEMID_CHILD, :UINT, :ptr SDWORD
          ??Interface equ <>
          END_INTERFACE
        IShellIconVtbl ends
        IShellIcon struct
          lpVtbl POINTER ?
        IShellIcon ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SBSP_DEFBROWSER equ 0000h
    SBSP_SAMEBROWSER equ 0001h
    SBSP_NEWBROWSER equ 0002h
    SBSP_DEFMODE equ 0000h
    SBSP_OPENMODE equ 0010h
    SBSP_EXPLOREMODE equ 0020h
    SBSP_HELPMODE equ 0040h
    SBSP_NOTRANSFERHIST equ 0080h
    SBSP_ABSOLUTE equ 0000h
    SBSP_RELATIVE equ 1000h
    SBSP_PARENT equ 2000h
    SBSP_NAVIGATEBACK equ 4000h
    SBSP_NAVIGATEFORWARD equ 8000h
    SBSP_ALLOW_AUTONAVIGATE equ 00010000h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SBSP_KEEPSAMETEMPLATE equ 00020000h
      SBSP_KEEPWORDWHEELTEXT equ 00040000h
      SBSP_ACTIVATE_NOFOCUS equ 00080000h
      SBSP_CREATENOHISTORY equ 00100000h
      SBSP_PLAYNOSOUND equ 00200000h
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      SBSP_CALLERUNTRUSTED equ 00800000h
      SBSP_TRUSTFIRSTDOWNLOAD equ 01000000h
      SBSP_UNTRUSTEDFORDOWNLOAD equ 02000000h
    endif
    SBSP_NOAUTOSELECT equ 04000000h
    SBSP_WRITENOHISTORY equ 08000000h
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      SBSP_TRUSTEDFORACTIVEX equ 10000000h
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      SBSP_FEEDNAVIGATION equ 20000000h
    endif
    SBSP_REDIRECT equ 40000000h
    SBSP_INITIATEDBYHLINKFRAME equ 80000000h
    FCW_STATUS equ 0001h
    FCW_TOOLBAR equ 0002h
    FCW_TREE equ 0003h
    FCW_INTERNETBAR equ 0006h
    FCW_PROGRESS equ 0008h
    if (_WIN32_IE ge 0700h)
    endif
    FCT_MERGE equ 0001h
    FCT_CONFIGABLE equ 0002h
    FCT_ADDTOEND equ 0004h
    ifdef _NEVER_
      LPTBBUTTONSB typedef LPARAM
    else
      include commctrl.inc
      LPTBBUTTONSB typedef LPTBBUTTON
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0035_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0035_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellBrowser_INTERFACE_DEFINED__
      __IShellBrowser_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellBrowser:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellBrowserVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellBrowserVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellBrowser, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellBrowser
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellBrowser
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          STD_METHOD GetWindow, :ptr IShellBrowser, :ptr HWND
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IShellBrowser, :BOOL
          DECLSPEC_XFGVIRT(IShellBrowser, InsertMenusSB)
          STD_METHOD InsertMenusSB, :ptr IShellBrowser, :HMENU, :LPOLEMENUGROUPWIDTHS
          DECLSPEC_XFGVIRT(IShellBrowser, SetMenuSB)
          STD_METHOD SetMenuSB, :ptr IShellBrowser, :HMENU, :HOLEMENU, :HWND
          DECLSPEC_XFGVIRT(IShellBrowser, RemoveMenusSB)
          STD_METHOD RemoveMenusSB, :ptr IShellBrowser, :HMENU
          DECLSPEC_XFGVIRT(IShellBrowser, SetStatusTextSB)
          STD_METHOD SetStatusTextSB, :ptr IShellBrowser, :LPCWSTR
          DECLSPEC_XFGVIRT(IShellBrowser, EnableModelessSB)
          STD_METHOD EnableModelessSB, :ptr IShellBrowser, :BOOL
          DECLSPEC_XFGVIRT(IShellBrowser, TranslateAcceleratorSB)
          STD_METHOD TranslateAcceleratorSB, :ptr IShellBrowser, :ptr MSG, :WORD
          DECLSPEC_XFGVIRT(IShellBrowser, BrowseObject)
          STD_METHOD BrowseObject, :ptr IShellBrowser, :PCUIDLIST_RELATIVE, :UINT
          DECLSPEC_XFGVIRT(IShellBrowser, GetViewStateStream)
          STD_METHOD GetViewStateStream, :ptr IShellBrowser, :DWORD, :ptr ptr IStream
          DECLSPEC_XFGVIRT(IShellBrowser, GetControlWindow)
          STD_METHOD GetControlWindow, :ptr IShellBrowser, :UINT, :ptr HWND
          DECLSPEC_XFGVIRT(IShellBrowser, SendControlMsg)
          STD_METHOD SendControlMsg, :ptr IShellBrowser, :UINT, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
          DECLSPEC_XFGVIRT(IShellBrowser, QueryActiveShellView)
          STD_METHOD QueryActiveShellView, :ptr IShellBrowser, :ptr ptr IShellView
          DECLSPEC_XFGVIRT(IShellBrowser, OnViewWindowActive)
          STD_METHOD OnViewWindowActive, :ptr IShellBrowser, :ptr IShellView
          DECLSPEC_XFGVIRT(IShellBrowser, SetToolbarItems)
          STD_METHOD SetToolbarItems, :ptr IShellBrowser, :LPTBBUTTONSB, :UINT, :UINT
          ??Interface equ <>
          END_INTERFACE
        IShellBrowserVtbl ends
        IShellBrowser struct
          lpVtbl POINTER ?
        IShellBrowser ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPSHELLBROWSER typedef ptr IShellBrowser
    externdef __MIDL_itf_shobjidl_core_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IProfferService_INTERFACE_DEFINED__
      __IProfferService_INTERFACE_DEFINED__ equ <>
      externdef IID_IProfferService:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProfferServiceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProfferServiceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IProfferService, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProfferService
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProfferService
          DECLSPEC_XFGVIRT(IProfferService, ProfferService)
          STD_METHOD ProfferService, :ptr IProfferService, :REFGUID, :ptr IServiceProvider, :ptr DWORD
          DECLSPEC_XFGVIRT(IProfferService, RevokeService)
          STD_METHOD RevokeService, :ptr IProfferService, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IProfferServiceVtbl ends
        IProfferService struct
          lpVtbl POINTER ?
        IProfferService ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SID_SProfferService equ <IID_IProfferService>
    externdef __MIDL_itf_shobjidl_core_0000_0037_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0037_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IGetServiceIds_INTERFACE_DEFINED__
      __IGetServiceIds_INTERFACE_DEFINED__ equ <>
      externdef IID_IGetServiceIds:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IGetServiceIdsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IGetServiceIdsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IGetServiceIds, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IGetServiceIds
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IGetServiceIds
          DECLSPEC_XFGVIRT(IGetServiceIds, GetServiceIds)
          STD_METHOD GetServiceIds, :ptr IGetServiceIds, :ptr ULONG, :ptr ptr GUID
          ??Interface equ <>
          END_INTERFACE
        IGetServiceIdsVtbl ends
        IGetServiceIds struct
          lpVtbl POINTER ?
        IGetServiceIds ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    STR_DONT_RESOLVE_LINK equ <L("Don't Resolve Link")>
    STR_GET_ASYNC_HANDLER equ <L("GetAsyncHandler")>
    externdef __MIDL_itf_shobjidl_core_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellItem_INTERFACE_DEFINED__
      __IShellItem_INTERFACE_DEFINED__ equ <>
      SIGDN typedef SDWORD
      SIGDN_NORMALDISPLAY equ 0
      SIGDN_PARENTRELATIVEPARSING equ 80018001h
      SIGDN_DESKTOPABSOLUTEPARSING equ 80028000h
      SIGDN_PARENTRELATIVEEDITING equ 80031001h
      SIGDN_DESKTOPABSOLUTEEDITING equ 8004c000h
      SIGDN_FILESYSPATH equ 80058000h
      SIGDN_URL equ 80068000h
      SIGDN_PARENTRELATIVEFORADDRESSBAR equ 8007c001h
      SIGDN_PARENTRELATIVE equ 80080001h
      SIGDN_PARENTRELATIVEFORUI equ 80094001h
      _SIGDN typedef SIGDN

      _SICHINTF typedef SDWORD
      SICHINT_DISPLAY equ 0
      SICHINT_ALLFIELDS equ 80000000h
      SICHINT_CANONICAL equ 10000000h
      SICHINT_TEST_FILESYSPATH_IF_NOT_EQUAL equ 20000000h

      SICHINTF typedef DWORD
      externdef IID_IShellItem:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItemVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItemVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellItem, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellItem
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellItem
          DECLSPEC_XFGVIRT(IShellItem, BindToHandler)
          STD_METHOD BindToHandler, :ptr IShellItem, :ptr IBindCtx, :REFGUID, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItem, GetParent)
          STD_METHOD GetParent, :ptr IShellItem, :ptr ptr IShellItem
          DECLSPEC_XFGVIRT(IShellItem, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IShellItem, :SIGDN, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IShellItem, GetAttributes)
          STD_METHOD GetAttributes, :ptr IShellItem, :SFGAOF, :ptr SFGAOF
          DECLSPEC_XFGVIRT(IShellItem, Compare)
          STD_METHOD Compare, :ptr IShellItem, :ptr IShellItem, :SICHINTF, :ptr SDWORD
          ??Interface equ <>
          END_INTERFACE
        IShellItemVtbl ends
        IShellItem struct
          lpVtbl POINTER ?
        IShellItem ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    @DefProto DllImport, SHSimpleIDListFromPath, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
    if (_WIN32_IE ge _WIN32_IE_IE70)
      @DefProto DllImport, SHCreateItemFromIDList, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :REFIID, :ptr ptr>, 12
      @DefProto DllImport, SHCreateItemFromParsingName, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr IBindCtx, :REFIID, :ptr ptr>, 16
      @DefProto DllImport, SHCreateItemWithParent, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :ptr IShellFolder, :PCUITEMID_CHILD, :REFIID, :ptr ptr>, 20
      @DefProto DllImport, SHCreateItemFromRelativeName, WIN_STD_CALL_CONV,, <:ptr IShellItem, :PCWSTR, :ptr IBindCtx, :REFIID, :ptr ptr>, 20
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, SHCreateItemInKnownFolder, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :PCWSTR, :REFIID, :ptr ptr>, 20
      @DefProto DllImport, SHGetIDListFromObject, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr PIDLIST_ABSOLUTE>, 8
      @DefProto DllImport, SHGetItemFromObject, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFIID, :ptr ptr>, 12
      @DefProto DllImport, SHGetPropertyStoreFromIDList, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr>, 16
      @DefProto DllImport, SHGetPropertyStoreFromParsingName, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr IBindCtx, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr>, 20
      @DefProto DllImport, SHGetNameFromIDList, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :SIGDN, :ptr PWSTR>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      DATAOBJ_GET_ITEM_FLAGS typedef SDWORD
      DOGIF_DEFAULT equ 0
      DOGIF_TRAVERSE_LINK equ 1h
      DOGIF_NO_HDROP equ 2h
      DOGIF_NO_URL equ 4h
      DOGIF_ONLY_IF_ONE equ 8h

      DEFINE_ENUM_FLAG_OPERATORS(DATAOBJ_GET_ITEM_FLAGS)
      @DefProto DllImport, SHGetItemFromDataObject, WIN_STD_CALL_CONV,, <:ptr IDataObject, :DATAOBJ_GET_ITEM_FLAGS, :REFIID, :ptr ptr>, 16
    endif
    STR_GPS_HANDLERPROPERTIESONLY equ <L("GPS_HANDLERPROPERTIESONLY")>
    STR_GPS_FASTPROPERTIESONLY equ <L("GPS_FASTPROPERTIESONLY")>
    STR_GPS_OPENSLOWITEM equ <L("GPS_OPENSLOWITEM")>
    STR_GPS_DELAYCREATION equ <L("GPS_DELAYCREATION")>
    STR_GPS_BESTEFFORT equ <L("GPS_BESTEFFORT")>
    STR_GPS_NO_OPLOCK equ <L("GPS_NO_OPLOCK")>
    externdef __MIDL_itf_shobjidl_core_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellItem2_INTERFACE_DEFINED__
      __IShellItem2_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellItem2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItem2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItem2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellItem2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellItem2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellItem2
          DECLSPEC_XFGVIRT(IShellItem, BindToHandler)
          STD_METHOD BindToHandler, :ptr IShellItem2, :ptr IBindCtx, :REFGUID, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItem, GetParent)
          STD_METHOD GetParent, :ptr IShellItem2, :ptr ptr IShellItem
          DECLSPEC_XFGVIRT(IShellItem, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IShellItem2, :SIGDN, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IShellItem, GetAttributes)
          STD_METHOD GetAttributes, :ptr IShellItem2, :SFGAOF, :ptr SFGAOF
          DECLSPEC_XFGVIRT(IShellItem, Compare)
          STD_METHOD Compare, :ptr IShellItem2, :ptr IShellItem, :SICHINTF, :ptr SDWORD
          DECLSPEC_XFGVIRT(IShellItem2, GetPropertyStore)
          STD_METHOD GetPropertyStore, :ptr IShellItem2, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItem2, GetPropertyStoreWithCreateObject)
          STD_METHOD GetPropertyStoreWithCreateObject, :ptr IShellItem2, :GETPROPERTYSTOREFLAGS, :ptr IUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItem2, GetPropertyStoreForKeys)
          STD_METHOD GetPropertyStoreForKeys, :ptr IShellItem2, :ptr PROPERTYKEY, :UINT, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItem2, GetPropertyDescriptionList)
          STD_METHOD GetPropertyDescriptionList, :ptr IShellItem2, :REFPROPERTYKEY, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItem2, Update)
          STD_METHOD Update, :ptr IShellItem2, :ptr IBindCtx
          DECLSPEC_XFGVIRT(IShellItem2, GetProperty)
          STD_METHOD GetProperty, :ptr IShellItem2, :REFPROPERTYKEY, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IShellItem2, GetCLSID)
          STD_METHOD GetCLSID, :ptr IShellItem2, :REFPROPERTYKEY, :ptr CLSID
          DECLSPEC_XFGVIRT(IShellItem2, GetFileTime)
          STD_METHOD GetFileTime, :ptr IShellItem2, :REFPROPERTYKEY, :ptr FILETIME
          DECLSPEC_XFGVIRT(IShellItem2, GetInt32)
          STD_METHOD GetInt32, :ptr IShellItem2, :REFPROPERTYKEY, :ptr SDWORD
          DECLSPEC_XFGVIRT(IShellItem2, GetString)
          STD_METHOD GetString, :ptr IShellItem2, :REFPROPERTYKEY, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IShellItem2, GetUInt32)
          STD_METHOD GetUInt32, :ptr IShellItem2, :REFPROPERTYKEY, :ptr ULONG
          DECLSPEC_XFGVIRT(IShellItem2, GetUInt64)
          STD_METHOD GetUInt64, :ptr IShellItem2, :REFPROPERTYKEY, :ptr ULONGLONG
          DECLSPEC_XFGVIRT(IShellItem2, GetBool)
          STD_METHOD GetBool, :ptr IShellItem2, :REFPROPERTYKEY, :ptr BOOL
          ??Interface equ <>
          END_INTERFACE
        IShellItem2Vtbl ends
        IShellItem2 struct
          lpVtbl POINTER ?
        IShellItem2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    _SIIGBF typedef SDWORD
    SIIGBF_RESIZETOFIT equ 0
    SIIGBF_BIGGERSIZEOK equ 1h
    SIIGBF_MEMORYONLY equ 2h
    SIIGBF_ICONONLY equ 4h
    SIIGBF_THUMBNAILONLY equ 8h
    SIIGBF_INCACHEONLY equ 10h
    SIIGBF_CROPTOSQUARE equ 20h
    SIIGBF_WIDETHUMBNAILS equ 40h
    SIIGBF_ICONBACKGROUND equ 80h
    SIIGBF_SCALEUP equ 100h

    SIIGBF typedef SDWORD
    externdef __MIDL_itf_shobjidl_core_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellItemImageFactory_INTERFACE_DEFINED__
      __IShellItemImageFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellItemImageFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItemImageFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItemImageFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellItemImageFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellItemImageFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellItemImageFactory
          DECLSPEC_XFGVIRT(IShellItemImageFactory, GetImage)
          STD_METHOD GetImage, :ptr IShellItemImageFactory, :SIZE_, :SIIGBF, :ptr HBITMAP
          ??Interface equ <>
          END_INTERFACE
        IShellItemImageFactoryVtbl ends
        IShellItemImageFactory struct
          lpVtbl POINTER ?
        IShellItemImageFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      externdef __MIDL_itf_shobjidl_core_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumShellItems_INTERFACE_DEFINED__
        __IEnumShellItems_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumShellItems:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumShellItemsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumShellItemsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumShellItems, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumShellItems
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumShellItems
            DECLSPEC_XFGVIRT(IEnumShellItems, Next)
            STD_METHOD Next, :ptr IEnumShellItems, :ULONG, :ptr ptr IShellItem, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumShellItems, Skip)
            STD_METHOD Skip, :ptr IEnumShellItems, :ULONG
            DECLSPEC_XFGVIRT(IEnumShellItems, Reset)
            STD_METHOD Reset, :ptr IEnumShellItems
            DECLSPEC_XFGVIRT(IEnumShellItems, Clone)
            STD_METHOD Clone, :ptr IEnumShellItems, :ptr ptr IEnumShellItems
            ??Interface equ <>
            END_INTERFACE
          IEnumShellItemsVtbl ends
          IEnumShellItems struct
            lpVtbl POINTER ?
          IEnumShellItems ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumShellItems_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumShellItems, :ULONG, :ptr ptr IShellItem, :ptr ULONG
        IEnumShellItems_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      STGTRANSCONFIRMATION typedef GUID
      LPSTGTRANSCONFIRMATION typedef ptr GUID
      STGOP typedef SDWORD
      STGOP_MOVE equ 1
      STGOP_COPY equ 2
      STGOP_SYNC equ 3
      STGOP_REMOVE equ 5
      STGOP_RENAME equ 6
      STGOP_APPLYPROPERTIES equ 8
      STGOP_NEW equ 10

    endif
    _TRANSFER_SOURCE_FLAGS typedef SDWORD
    TSF_NORMAL equ 0
    TSF_FAIL_EXIST equ 0
    TSF_RENAME_EXIST equ 1h
    TSF_OVERWRITE_EXIST equ 2h
    TSF_ALLOW_DECRYPTION equ 4h
    TSF_NO_SECURITY equ 8h
    TSF_COPY_CREATION_TIME equ 10h
    TSF_COPY_WRITE_TIME equ 20h
    TSF_USE_FULL_ACCESS equ 40h
    TSF_DELETE_RECYCLE_IF_POSSIBLE equ 80h
    TSF_COPY_HARD_LINK equ 100h
    TSF_COPY_LOCALIZED_NAME equ 200h
    TSF_MOVE_AS_COPY_DELETE equ 400h
    TSF_SUSPEND_SHELLEVENTS equ 800h

    TRANSFER_SOURCE_FLAGS typedef DWORD
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_core_0000_0042_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0042_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ITransferAdviseSink_INTERFACE_DEFINED__
        __ITransferAdviseSink_INTERFACE_DEFINED__ equ <>
        _TRANSFER_ADVISE_STATE typedef SDWORD
        TS_NONE equ 0
        TS_PERFORMING equ 1h
        TS_PREPARING equ 2h
        TS_INDETERMINATE equ 4h

        TRANSFER_ADVISE_STATE typedef DWORD
        externdef IID_ITransferAdviseSink:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITransferAdviseSinkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITransferAdviseSinkVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ITransferAdviseSink, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ITransferAdviseSink
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ITransferAdviseSink
            DECLSPEC_XFGVIRT(ITransferAdviseSink, UpdateProgress)
            STD_METHOD UpdateProgress, :ptr ITransferAdviseSink, :ULONGLONG, :ULONGLONG, :SDWORD, :SDWORD, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(ITransferAdviseSink, UpdateTransferState)
            STD_METHOD UpdateTransferState, :ptr ITransferAdviseSink, :TRANSFER_ADVISE_STATE
            DECLSPEC_XFGVIRT(ITransferAdviseSink, ConfirmOverwrite)
            STD_METHOD ConfirmOverwrite, :ptr ITransferAdviseSink, :ptr IShellItem, :ptr IShellItem, :LPCWSTR
            DECLSPEC_XFGVIRT(ITransferAdviseSink, ConfirmEncryptionLoss)
            STD_METHOD ConfirmEncryptionLoss, :ptr ITransferAdviseSink, :ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferAdviseSink, FileFailure)
            STD_METHOD FileFailure, :ptr ITransferAdviseSink, :ptr IShellItem, :LPCWSTR, :HRESULT, :LPWSTR, :ULONG
            DECLSPEC_XFGVIRT(ITransferAdviseSink, SubStreamFailure)
            STD_METHOD SubStreamFailure, :ptr ITransferAdviseSink, :ptr IShellItem, :LPCWSTR, :HRESULT
            DECLSPEC_XFGVIRT(ITransferAdviseSink, PropertyFailure)
            STD_METHOD PropertyFailure, :ptr ITransferAdviseSink, :ptr IShellItem, :ptr PROPERTYKEY, :HRESULT
            ??Interface equ <>
            END_INTERFACE
          ITransferAdviseSinkVtbl ends
          ITransferAdviseSink struct
            lpVtbl POINTER ?
          ITransferAdviseSink ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0043_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0043_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ITransferSource_INTERFACE_DEFINED__
        __ITransferSource_INTERFACE_DEFINED__ equ <>
        externdef IID_ITransferSource:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITransferSourceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITransferSourceVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ITransferSource, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ITransferSource
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ITransferSource
            DECLSPEC_XFGVIRT(ITransferSource, Advise)
            STD_METHOD Advise, :ptr ITransferSource, :ptr ITransferAdviseSink, :ptr DWORD
            DECLSPEC_XFGVIRT(ITransferSource, Unadvise)
            STD_METHOD Unadvise, :ptr ITransferSource, :DWORD
            DECLSPEC_XFGVIRT(ITransferSource, SetProperties)
            STD_METHOD SetProperties, :ptr ITransferSource, :ptr IPropertyChangeArray
            DECLSPEC_XFGVIRT(ITransferSource, OpenItem)
            STD_METHOD OpenItem, :ptr ITransferSource, :ptr IShellItem, :TRANSFER_SOURCE_FLAGS, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(ITransferSource, MoveItem)
            STD_METHOD MoveItem, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferSource, RecycleItem)
            STD_METHOD RecycleItem, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferSource, RemoveItem)
            STD_METHOD RemoveItem, :ptr ITransferSource, :ptr IShellItem, :TRANSFER_SOURCE_FLAGS
            DECLSPEC_XFGVIRT(ITransferSource, RenameItem)
            STD_METHOD RenameItem, :ptr ITransferSource, :ptr IShellItem, :LPCWSTR, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferSource, LinkItem)
            STD_METHOD LinkItem, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferSource, ApplyPropertiesToItem)
            STD_METHOD ApplyPropertiesToItem, :ptr ITransferSource, :ptr IShellItem, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferSource, GetDefaultDestinationName)
            STD_METHOD GetDefaultDestinationName, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :ptr LPWSTR
            DECLSPEC_XFGVIRT(ITransferSource, EnterFolder)
            STD_METHOD EnterFolder, :ptr ITransferSource, :ptr IShellItem
            DECLSPEC_XFGVIRT(ITransferSource, LeaveFolder)
            STD_METHOD LeaveFolder, :ptr ITransferSource, :ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          ITransferSourceVtbl ends
          ITransferSource struct
            lpVtbl POINTER ?
          ITransferSource ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    SHELL_ITEM_RESOURCE struct
      guidType GUID <>
      szName WCHAR 260 dup (?)
    SHELL_ITEM_RESOURCE ends
    externdef __MIDL_itf_shobjidl_core_0000_0044_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0044_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumResources_INTERFACE_DEFINED__
      __IEnumResources_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumResources:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumResourcesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumResourcesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IEnumResources, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumResources
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumResources
          DECLSPEC_XFGVIRT(IEnumResources, Next)
          STD_METHOD Next, :ptr IEnumResources, :ULONG, :ptr SHELL_ITEM_RESOURCE, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumResources, Skip)
          STD_METHOD Skip, :ptr IEnumResources, :ULONG
          DECLSPEC_XFGVIRT(IEnumResources, Reset)
          STD_METHOD Reset, :ptr IEnumResources
          DECLSPEC_XFGVIRT(IEnumResources, Clone)
          STD_METHOD Clone, :ptr IEnumResources, :ptr ptr IEnumResources
          ??Interface equ <>
          END_INTERFACE
        IEnumResourcesVtbl ends
        IEnumResources struct
          lpVtbl POINTER ?
        IEnumResources ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellItemResources_INTERFACE_DEFINED__
      __IShellItemResources_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellItemResources:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItemResourcesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItemResourcesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellItemResources, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellItemResources
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellItemResources
          DECLSPEC_XFGVIRT(IShellItemResources, GetAttributes)
          STD_METHOD GetAttributes, :ptr IShellItemResources, :ptr DWORD
          DECLSPEC_XFGVIRT(IShellItemResources, GetSize)
          STD_METHOD GetSize, :ptr IShellItemResources, :ptr ULONGLONG
          DECLSPEC_XFGVIRT(IShellItemResources, GetTimes)
          STD_METHOD GetTimes, :ptr IShellItemResources, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
          DECLSPEC_XFGVIRT(IShellItemResources, SetTimes)
          STD_METHOD SetTimes, :ptr IShellItemResources, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
          DECLSPEC_XFGVIRT(IShellItemResources, GetResourceDescription)
          STD_METHOD GetResourceDescription, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IShellItemResources, EnumResources)
          STD_METHOD EnumResources, :ptr IShellItemResources, :ptr ptr IEnumResources
          DECLSPEC_XFGVIRT(IShellItemResources, SupportsResource)
          STD_METHOD SupportsResource, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE
          DECLSPEC_XFGVIRT(IShellItemResources, OpenResource)
          STD_METHOD OpenResource, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItemResources, CreateResource)
          STD_METHOD CreateResource, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItemResources, MarkForDelete)
          STD_METHOD MarkForDelete, :ptr IShellItemResources
          ??Interface equ <>
          END_INTERFACE
        IShellItemResourcesVtbl ends
        IShellItemResources struct
          lpVtbl POINTER ?
        IShellItemResources ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ITransferDestination_INTERFACE_DEFINED__
      __ITransferDestination_INTERFACE_DEFINED__ equ <>
      externdef IID_ITransferDestination:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITransferDestinationVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITransferDestinationVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITransferDestination, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITransferDestination
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITransferDestination
          DECLSPEC_XFGVIRT(ITransferDestination, Advise)
          STD_METHOD Advise, :ptr ITransferDestination, :ptr ITransferAdviseSink, :ptr DWORD
          DECLSPEC_XFGVIRT(ITransferDestination, Unadvise)
          STD_METHOD Unadvise, :ptr ITransferDestination, :DWORD
          DECLSPEC_XFGVIRT(ITransferDestination, CreateItem)
          STD_METHOD CreateItem, :ptr ITransferDestination, :LPCWSTR, :DWORD, :ULONGLONG, :TRANSFER_SOURCE_FLAGS, :REFIID, :ptr ptr, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        ITransferDestinationVtbl ends
        ITransferDestination struct
          lpVtbl POINTER ?
        ITransferDestination ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_core_0000_0047_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0047_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileOperationProgressSink_INTERFACE_DEFINED__
        __IFileOperationProgressSink_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileOperationProgressSink:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileOperationProgressSinkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileOperationProgressSinkVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileOperationProgressSink, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileOperationProgressSink
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileOperationProgressSink
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, StartOperations)
            STD_METHOD StartOperations, :ptr IFileOperationProgressSink
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, FinishOperations)
            STD_METHOD FinishOperations, :ptr IFileOperationProgressSink, :HRESULT
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PreRenameItem)
            STD_METHOD PreRenameItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PostRenameItem)
            STD_METHOD PostRenameItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR, :HRESULT, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PreMoveItem)
            STD_METHOD PreMoveItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PostMoveItem)
            STD_METHOD PostMoveItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :HRESULT, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PreCopyItem)
            STD_METHOD PreCopyItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PostCopyItem)
            STD_METHOD PostCopyItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :HRESULT, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PreDeleteItem)
            STD_METHOD PreDeleteItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PostDeleteItem)
            STD_METHOD PostDeleteItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :HRESULT, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PreNewItem)
            STD_METHOD PreNewItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PostNewItem)
            STD_METHOD PostNewItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR, :LPCWSTR, :DWORD, :HRESULT, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, UpdateProgress)
            STD_METHOD UpdateProgress, :ptr IFileOperationProgressSink, :UINT, :UINT
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, ResetTimer)
            STD_METHOD ResetTimer, :ptr IFileOperationProgressSink
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, PauseTimer)
            STD_METHOD PauseTimer, :ptr IFileOperationProgressSink
            DECLSPEC_XFGVIRT(IFileOperationProgressSink, ResumeTimer)
            STD_METHOD ResumeTimer, :ptr IFileOperationProgressSink
            ??Interface equ <>
            END_INTERFACE
          IFileOperationProgressSinkVtbl ends
          IFileOperationProgressSink struct
            lpVtbl POINTER ?
          IFileOperationProgressSink ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellItemArray_INTERFACE_DEFINED__
      __IShellItemArray_INTERFACE_DEFINED__ equ <>
      SIATTRIBFLAGS typedef SDWORD
      SIATTRIBFLAGS_AND equ 1h
      SIATTRIBFLAGS_OR equ 2h
      SIATTRIBFLAGS_APPCOMPAT equ 3h
      SIATTRIBFLAGS_MASK equ 3h
      SIATTRIBFLAGS_ALLITEMS equ 4000h

      DEFINE_ENUM_FLAG_OPERATORS(SIATTRIBFLAGS)
      externdef IID_IShellItemArray:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItemArrayVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItemArrayVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellItemArray, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellItemArray
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellItemArray
          DECLSPEC_XFGVIRT(IShellItemArray, BindToHandler)
          STD_METHOD BindToHandler, :ptr IShellItemArray, :ptr IBindCtx, :REFGUID, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItemArray, GetPropertyStore)
          STD_METHOD GetPropertyStore, :ptr IShellItemArray, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItemArray, GetPropertyDescriptionList)
          STD_METHOD GetPropertyDescriptionList, :ptr IShellItemArray, :REFPROPERTYKEY, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellItemArray, GetAttributes)
          STD_METHOD GetAttributes, :ptr IShellItemArray, :SIATTRIBFLAGS, :SFGAOF, :ptr SFGAOF
          DECLSPEC_XFGVIRT(IShellItemArray, GetCount)
          STD_METHOD GetCount, :ptr IShellItemArray, :ptr DWORD
          DECLSPEC_XFGVIRT(IShellItemArray, GetItemAt)
          STD_METHOD GetItemAt, :ptr IShellItemArray, :DWORD, :ptr ptr IShellItem
          DECLSPEC_XFGVIRT(IShellItemArray, EnumItems)
          STD_METHOD EnumItems, :ptr IShellItemArray, :ptr ptr IEnumShellItems
          ??Interface equ <>
          END_INTERFACE
        IShellItemArrayVtbl ends
        IShellItemArray struct
          lpVtbl POINTER ?
        IShellItemArray ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      @DefProto DllImport, SHCreateShellItemArray, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :ptr IShellFolder, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr ptr IShellItemArray>, 20
      @DefProto DllImport, SHCreateShellItemArrayFromDataObject, WIN_STD_CALL_CONV,, <:ptr IDataObject, :REFIID, :ptr ptr>, 12
      @DefProto DllImport, SHCreateShellItemArrayFromIDLists, WIN_STD_CALL_CONV,, <:UINT, :PCIDLIST_ABSOLUTE_ARRAY, :ptr ptr IShellItemArray>, 12
      @DefProto DllImport, SHCreateShellItemArrayFromShellItem, WIN_STD_CALL_CONV,, <:ptr IShellItem, :REFIID, :ptr ptr>, 12
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0049_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0049_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IInitializeWithItem_INTERFACE_DEFINED__
      __IInitializeWithItem_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeWithItem:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeWithItemVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeWithItemVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInitializeWithItem, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInitializeWithItem
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInitializeWithItem
          DECLSPEC_XFGVIRT(IInitializeWithItem, Initialize)
          STD_METHOD Initialize, :ptr IInitializeWithItem, :ptr IShellItem, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IInitializeWithItemVtbl ends
        IInitializeWithItem struct
          lpVtbl POINTER ?
        IInitializeWithItem ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IObjectWithSelection_INTERFACE_DEFINED__
      __IObjectWithSelection_INTERFACE_DEFINED__ equ <>
      externdef IID_IObjectWithSelection:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectWithSelectionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectWithSelectionVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IObjectWithSelection, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectWithSelection
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectWithSelection
          DECLSPEC_XFGVIRT(IObjectWithSelection, SetSelection)
          STD_METHOD SetSelection, :ptr IObjectWithSelection, :ptr IShellItemArray
          DECLSPEC_XFGVIRT(IObjectWithSelection, GetSelection)
          STD_METHOD GetSelection, :ptr IObjectWithSelection, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IObjectWithSelectionVtbl ends
        IObjectWithSelection struct
          lpVtbl POINTER ?
        IObjectWithSelection ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IObjectWithBackReferences_INTERFACE_DEFINED__
      __IObjectWithBackReferences_INTERFACE_DEFINED__ equ <>
      externdef IID_IObjectWithBackReferences:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectWithBackReferencesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectWithBackReferencesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IObjectWithBackReferences, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectWithBackReferences
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectWithBackReferences
          DECLSPEC_XFGVIRT(IObjectWithBackReferences, RemoveBackReferences)
          STD_METHOD RemoveBackReferences, :ptr IObjectWithBackReferences
          ??Interface equ <>
          END_INTERFACE
        IObjectWithBackReferencesVtbl ends
        IObjectWithBackReferences struct
          lpVtbl POINTER ?
        IObjectWithBackReferences ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    _PROPERTYUI_NAME_FLAGS typedef SDWORD
    PUIFNF_DEFAULT equ 0
    PUIFNF_MNEMONIC equ 1h

    PROPERTYUI_NAME_FLAGS typedef DWORD
    _PROPERTYUI_FLAGS typedef SDWORD
    PUIF_DEFAULT equ 0
    PUIF_RIGHTALIGN equ 1h
    PUIF_NOLABELININFOTIP equ 2h

    PROPERTYUI_FLAGS typedef DWORD
    _PROPERTYUI_FORMAT_FLAGS typedef SDWORD
    PUIFFDF_DEFAULT equ 0
    PUIFFDF_RIGHTTOLEFT equ 1h
    PUIFFDF_SHORTFORMAT equ 2h
    PUIFFDF_NOTIME equ 4h
    PUIFFDF_FRIENDLYDATE equ 8h

    PROPERTYUI_FORMAT_FLAGS typedef DWORD
    externdef __MIDL_itf_shobjidl_core_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertyUI_INTERFACE_DEFINED__
      __IPropertyUI_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyUI:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyUIVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyUIVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyUI, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyUI
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyUI
          DECLSPEC_XFGVIRT(IPropertyUI, ParsePropertyName)
          STD_METHOD ParsePropertyName, :ptr IPropertyUI, :LPCWSTR, :ptr FMTID, :ptr PROPID, :ptr ULONG
          DECLSPEC_XFGVIRT(IPropertyUI, GetCannonicalName)
          STD_METHOD GetCannonicalName, :ptr IPropertyUI, :REFFMTID, :PROPID, :LPWSTR, :DWORD
          DECLSPEC_XFGVIRT(IPropertyUI, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IPropertyUI, :REFFMTID, :PROPID, :PROPERTYUI_NAME_FLAGS, :LPWSTR, :DWORD
          DECLSPEC_XFGVIRT(IPropertyUI, GetPropertyDescription)
          STD_METHOD GetPropertyDescription, :ptr IPropertyUI, :REFFMTID, :PROPID, :LPWSTR, :DWORD
          DECLSPEC_XFGVIRT(IPropertyUI, GetDefaultWidth)
          STD_METHOD GetDefaultWidth, :ptr IPropertyUI, :REFFMTID, :PROPID, :ptr ULONG
          DECLSPEC_XFGVIRT(IPropertyUI, GetFlags)
          STD_METHOD GetFlags, :ptr IPropertyUI, :REFFMTID, :PROPID, :ptr PROPERTYUI_FLAGS
          DECLSPEC_XFGVIRT(IPropertyUI, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertyUI, :REFFMTID, :PROPID, :ptr PROPVARIANT, :PROPERTYUI_FORMAT_FLAGS, :LPWSTR, :DWORD
          DECLSPEC_XFGVIRT(IPropertyUI, GetHelpInfo)
          STD_METHOD GetHelpInfo, :ptr IPropertyUI, :REFFMTID, :PROPID, :LPWSTR, :DWORD, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IPropertyUIVtbl ends
        IPropertyUI struct
          lpVtbl POINTER ?
        IPropertyUI ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICategoryProvider_INTERFACE_DEFINED__
      __ICategoryProvider_INTERFACE_DEFINED__ equ <>
      externdef IID_ICategoryProvider:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICategoryProviderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICategoryProviderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICategoryProvider, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICategoryProvider
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICategoryProvider
          DECLSPEC_XFGVIRT(ICategoryProvider, CanCategorizeOnSCID)
          STD_METHOD CanCategorizeOnSCID, :ptr ICategoryProvider, :ptr SHCOLUMNID
          DECLSPEC_XFGVIRT(ICategoryProvider, GetDefaultCategory)
          STD_METHOD GetDefaultCategory, :ptr ICategoryProvider, :ptr GUID, :ptr SHCOLUMNID
          DECLSPEC_XFGVIRT(ICategoryProvider, GetCategoryForSCID)
          STD_METHOD GetCategoryForSCID, :ptr ICategoryProvider, :ptr SHCOLUMNID, :ptr GUID
          DECLSPEC_XFGVIRT(ICategoryProvider, EnumCategories)
          STD_METHOD EnumCategories, :ptr ICategoryProvider, :ptr ptr IEnumGUID
          DECLSPEC_XFGVIRT(ICategoryProvider, GetCategoryName)
          STD_METHOD GetCategoryName, :ptr ICategoryProvider, :ptr GUID, :LPWSTR, :UINT
          DECLSPEC_XFGVIRT(ICategoryProvider, CreateCategory)
          STD_METHOD CreateCategory, :ptr ICategoryProvider, :ptr GUID, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        ICategoryProviderVtbl ends
        ICategoryProvider struct
          lpVtbl POINTER ?
        ICategoryProvider ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    CATEGORYINFO_FLAGS typedef SDWORD
    CATINFO_NORMAL equ 0
    CATINFO_COLLAPSED equ 1h
    CATINFO_HIDDEN equ 2h
    CATINFO_EXPANDED equ 4h
    CATINFO_NOHEADER equ 8h
    CATINFO_NOTCOLLAPSIBLE equ 10h
    CATINFO_NOHEADERCOUNT equ 20h
    CATINFO_SUBSETTED equ 40h
    CATINFO_SEPARATE_IMAGES equ 80h
    CATINFO_SHOWEMPTY equ 100h

    DEFINE_ENUM_FLAG_OPERATORS(CATEGORYINFO_FLAGS)
    CATSORT_FLAGS typedef SDWORD
    CATSORT_DEFAULT equ 0
    CATSORT_NAME equ 1h

    DEFINE_ENUM_FLAG_OPERATORS(CATSORT_FLAGS)
    CATEGORY_INFO struct
      cif CATEGORYINFO_FLAGS ?
      wszName WCHAR 260 dup (?)
    CATEGORY_INFO ends
    externdef __MIDL_itf_shobjidl_core_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ICategorizer_INTERFACE_DEFINED__
      __ICategorizer_INTERFACE_DEFINED__ equ <>
      externdef IID_ICategorizer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICategorizerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICategorizerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICategorizer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICategorizer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICategorizer
          DECLSPEC_XFGVIRT(ICategorizer, GetDescription)
          STD_METHOD GetDescription, :ptr ICategorizer, :LPWSTR, :UINT
          DECLSPEC_XFGVIRT(ICategorizer, GetCategory)
          STD_METHOD GetCategory, :ptr ICategorizer, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr DWORD
          DECLSPEC_XFGVIRT(ICategorizer, GetCategoryInfo)
          STD_METHOD GetCategoryInfo, :ptr ICategorizer, :DWORD, :ptr CATEGORY_INFO
          DECLSPEC_XFGVIRT(ICategorizer, CompareCategory)
          STD_METHOD CompareCategory, :ptr ICategorizer, :CATSORT_FLAGS, :DWORD, :DWORD
          ??Interface equ <>
          END_INTERFACE
        ICategorizerVtbl ends
        ICategorizer struct
          lpVtbl POINTER ?
        ICategorizer ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      include pshpack8.inc
      SHDRAGIMAGE struct
        sizeDragImage SIZE_ ?
        ptOffset POINT <>
        hbmpDragImage HBITMAP ?
        crColorKey COLORREF ?
      SHDRAGIMAGE ends
      LPSHDRAGIMAGE typedef ptr SHDRAGIMAGE
      include poppack.inc
      DI_GETDRAGIMAGE equ <TEXT("ShellGetDragImage")>
      externdef __MIDL_itf_shobjidl_core_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDropTargetHelper_INTERFACE_DEFINED__
        __IDropTargetHelper_INTERFACE_DEFINED__ equ <>
        externdef IID_IDropTargetHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDropTargetHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDropTargetHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDropTargetHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDropTargetHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDropTargetHelper
            DECLSPEC_XFGVIRT(IDropTargetHelper, DragEnter)
            STD_METHOD DragEnter, :ptr IDropTargetHelper, :HWND, :ptr IDataObject, :ptr POINT, :DWORD
            DECLSPEC_XFGVIRT(IDropTargetHelper, DragLeave)
            STD_METHOD DragLeave, :ptr IDropTargetHelper
            DECLSPEC_XFGVIRT(IDropTargetHelper, DragOver)
            STD_METHOD DragOver, :ptr IDropTargetHelper, :ptr POINT, :DWORD
            DECLSPEC_XFGVIRT(IDropTargetHelper, Drop)
            STD_METHOD Drop, :ptr IDropTargetHelper, :ptr IDataObject, :ptr POINT, :DWORD
            DECLSPEC_XFGVIRT(IDropTargetHelper, Show)
            STD_METHOD Show, :ptr IDropTargetHelper, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IDropTargetHelperVtbl ends
          IDropTargetHelper struct
            lpVtbl POINTER ?
          IDropTargetHelper ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDragSourceHelper_INTERFACE_DEFINED__
        __IDragSourceHelper_INTERFACE_DEFINED__ equ <>
        externdef IID_IDragSourceHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDragSourceHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDragSourceHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDragSourceHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDragSourceHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDragSourceHelper
            DECLSPEC_XFGVIRT(IDragSourceHelper, InitializeFromBitmap)
            STD_METHOD InitializeFromBitmap, :ptr IDragSourceHelper, :LPSHDRAGIMAGE, :ptr IDataObject
            DECLSPEC_XFGVIRT(IDragSourceHelper, InitializeFromWindow)
            STD_METHOD InitializeFromWindow, :ptr IDragSourceHelper, :HWND, :ptr POINT, :ptr IDataObject
            ??Interface equ <>
            END_INTERFACE
          IDragSourceHelperVtbl ends
          IDragSourceHelper struct
            lpVtbl POINTER ?
          IDragSourceHelper ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifdef UNICODE
      IShellLink equ <IShellLinkW>
    else
      IShellLink equ <IShellLinkA>
    endif
    SLR_FLAGS typedef SDWORD
    SLR_NONE equ 0
    SLR_NO_UI equ 1h
    SLR_ANY_MATCH equ 2h
    SLR_UPDATE equ 4h
    SLR_NOUPDATE equ 8h
    SLR_NOSEARCH equ 10h
    SLR_NOTRACK equ 20h
    SLR_NOLINKINFO equ 40h
    SLR_INVOKE_MSI equ 80h
    SLR_NO_UI_WITH_MSG_PUMP equ 101h
    SLR_OFFER_DELETE_WITHOUT_FILE equ 200h
    SLR_KNOWNFOLDER equ 400h
    SLR_MACHINE_IN_LOCAL_TARGET equ 800h
    SLR_UPDATE_MACHINE_AND_SID equ 1000h
    SLR_NO_OBJECT_ID equ 2000h

    DEFINE_ENUM_FLAG_OPERATORS(SLR_FLAGS)
    SLGP_FLAGS typedef SDWORD
    SLGP_SHORTPATH equ 1h
    SLGP_UNCPRIORITY equ 2h
    SLGP_RAWPATH equ 4h
    SLGP_RELATIVEPRIORITY equ 8h

    DEFINE_ENUM_FLAG_OPERATORS(SLGP_FLAGS)
    externdef __MIDL_itf_shobjidl_core_0000_0057_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0057_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellLinkA_INTERFACE_DEFINED__
      __IShellLinkA_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellLinkA:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellLinkAVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellLinkAVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellLinkA, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellLinkA
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellLinkA
          DECLSPEC_XFGVIRT(IShellLinkA, GetPath)
          STD_METHOD GetPath, :ptr IShellLinkA, :LPSTR, :SDWORD, :ptr WIN32_FIND_DATAA, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkA, GetIDList)
          STD_METHOD GetIDList, :ptr IShellLinkA, :ptr PIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IShellLinkA, SetIDList)
          STD_METHOD SetIDList, :ptr IShellLinkA, :PCIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IShellLinkA, GetDescription)
          STD_METHOD GetDescription, :ptr IShellLinkA, :LPSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetDescription)
          STD_METHOD SetDescription, :ptr IShellLinkA, :LPCSTR
          DECLSPEC_XFGVIRT(IShellLinkA, GetWorkingDirectory)
          STD_METHOD GetWorkingDirectory, :ptr IShellLinkA, :LPSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetWorkingDirectory)
          STD_METHOD SetWorkingDirectory, :ptr IShellLinkA, :LPCSTR
          DECLSPEC_XFGVIRT(IShellLinkA, GetArguments)
          STD_METHOD GetArguments, :ptr IShellLinkA, :LPSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetArguments)
          STD_METHOD SetArguments, :ptr IShellLinkA, :LPCSTR
          DECLSPEC_XFGVIRT(IShellLinkA, GetHotkey)
          STD_METHOD GetHotkey, :ptr IShellLinkA, :ptr WORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetHotkey)
          STD_METHOD SetHotkey, :ptr IShellLinkA, :WORD
          DECLSPEC_XFGVIRT(IShellLinkA, GetShowCmd)
          STD_METHOD GetShowCmd, :ptr IShellLinkA, :ptr SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetShowCmd)
          STD_METHOD SetShowCmd, :ptr IShellLinkA, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, GetIconLocation)
          STD_METHOD GetIconLocation, :ptr IShellLinkA, :LPSTR, :SDWORD, :ptr SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetIconLocation)
          STD_METHOD SetIconLocation, :ptr IShellLinkA, :LPCSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetRelativePath)
          STD_METHOD SetRelativePath, :ptr IShellLinkA, :LPCSTR, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkA, Resolve)
          STD_METHOD Resolve, :ptr IShellLinkA, :HWND, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkA, SetPath)
          STD_METHOD SetPath, :ptr IShellLinkA, :LPCSTR
          ??Interface equ <>
          END_INTERFACE
        IShellLinkAVtbl ends
        IShellLinkA struct
          lpVtbl POINTER ?
        IShellLinkA ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellLinkW_INTERFACE_DEFINED__
      __IShellLinkW_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellLinkW:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellLinkWVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellLinkWVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellLinkW, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellLinkW
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellLinkW
          DECLSPEC_XFGVIRT(IShellLinkW, GetPath)
          STD_METHOD GetPath, :ptr IShellLinkW, :LPWSTR, :SDWORD, :ptr WIN32_FIND_DATAW, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkW, GetIDList)
          STD_METHOD GetIDList, :ptr IShellLinkW, :ptr PIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IShellLinkW, SetIDList)
          STD_METHOD SetIDList, :ptr IShellLinkW, :PCIDLIST_ABSOLUTE
          DECLSPEC_XFGVIRT(IShellLinkW, GetDescription)
          STD_METHOD GetDescription, :ptr IShellLinkW, :LPWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetDescription)
          STD_METHOD SetDescription, :ptr IShellLinkW, :LPCWSTR
          DECLSPEC_XFGVIRT(IShellLinkW, GetWorkingDirectory)
          STD_METHOD GetWorkingDirectory, :ptr IShellLinkW, :LPWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetWorkingDirectory)
          STD_METHOD SetWorkingDirectory, :ptr IShellLinkW, :LPCWSTR
          DECLSPEC_XFGVIRT(IShellLinkW, GetArguments)
          STD_METHOD GetArguments, :ptr IShellLinkW, :LPWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetArguments)
          STD_METHOD SetArguments, :ptr IShellLinkW, :LPCWSTR
          DECLSPEC_XFGVIRT(IShellLinkW, GetHotkey)
          STD_METHOD GetHotkey, :ptr IShellLinkW, :ptr WORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetHotkey)
          STD_METHOD SetHotkey, :ptr IShellLinkW, :WORD
          DECLSPEC_XFGVIRT(IShellLinkW, GetShowCmd)
          STD_METHOD GetShowCmd, :ptr IShellLinkW, :ptr SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetShowCmd)
          STD_METHOD SetShowCmd, :ptr IShellLinkW, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, GetIconLocation)
          STD_METHOD GetIconLocation, :ptr IShellLinkW, :LPWSTR, :SDWORD, :ptr SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetIconLocation)
          STD_METHOD SetIconLocation, :ptr IShellLinkW, :LPCWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetRelativePath)
          STD_METHOD SetRelativePath, :ptr IShellLinkW, :LPCWSTR, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkW, Resolve)
          STD_METHOD Resolve, :ptr IShellLinkW, :HWND, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkW, SetPath)
          STD_METHOD SetPath, :ptr IShellLinkW, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IShellLinkWVtbl ends
        IShellLinkW struct
          lpVtbl POINTER ?
        IShellLinkW ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellLinkDataList_INTERFACE_DEFINED__
      __IShellLinkDataList_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellLinkDataList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellLinkDataListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellLinkDataListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellLinkDataList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellLinkDataList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellLinkDataList
          DECLSPEC_XFGVIRT(IShellLinkDataList, AddDataBlock)
          STD_METHOD AddDataBlock, :ptr IShellLinkDataList, :ptr
          DECLSPEC_XFGVIRT(IShellLinkDataList, CopyDataBlock)
          STD_METHOD CopyDataBlock, :ptr IShellLinkDataList, :DWORD, :ptr ptr
          DECLSPEC_XFGVIRT(IShellLinkDataList, RemoveDataBlock)
          STD_METHOD RemoveDataBlock, :ptr IShellLinkDataList, :DWORD
          DECLSPEC_XFGVIRT(IShellLinkDataList, GetFlags)
          STD_METHOD GetFlags, :ptr IShellLinkDataList, :ptr DWORD
          DECLSPEC_XFGVIRT(IShellLinkDataList, SetFlags)
          STD_METHOD SetFlags, :ptr IShellLinkDataList, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IShellLinkDataListVtbl ends
        IShellLinkDataList struct
          lpVtbl POINTER ?
        IShellLinkDataList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      externdef __MIDL_itf_shobjidl_core_0000_0060_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0060_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IResolveShellLink_INTERFACE_DEFINED__
        __IResolveShellLink_INTERFACE_DEFINED__ equ <>
        externdef IID_IResolveShellLink:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IResolveShellLinkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IResolveShellLinkVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IResolveShellLink, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IResolveShellLink
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IResolveShellLink
            DECLSPEC_XFGVIRT(IResolveShellLink, ResolveShellLink)
            STD_METHOD ResolveShellLink, :ptr IResolveShellLink, :ptr IUnknown, :HWND, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IResolveShellLinkVtbl ends
          IResolveShellLink struct
            lpVtbl POINTER ?
          IResolveShellLink ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0061_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0061_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IActionProgressDialog_INTERFACE_DEFINED__
      __IActionProgressDialog_INTERFACE_DEFINED__ equ <>
      _SPINITF typedef SDWORD
      SPINITF_NORMAL equ 0
      SPINITF_MODAL equ 1h
      SPINITF_NOMINIMIZE equ 8h

      SPINITF typedef DWORD
      externdef IID_IActionProgressDialog:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IActionProgressDialogVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IActionProgressDialogVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IActionProgressDialog, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IActionProgressDialog
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IActionProgressDialog
          DECLSPEC_XFGVIRT(IActionProgressDialog, Initialize)
          STD_METHOD Initialize, :ptr IActionProgressDialog, :SPINITF, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(IActionProgressDialog, Stop)
          STD_METHOD Stop, :ptr IActionProgressDialog
          ??Interface equ <>
          END_INTERFACE
        IActionProgressDialogVtbl ends
        IActionProgressDialog struct
          lpVtbl POINTER ?
        IActionProgressDialog ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ARCONTENT_AUTORUNINF equ 00000002h
    ARCONTENT_AUDIOCD equ 00000004h
    ARCONTENT_DVDMOVIE equ 00000008h
    ARCONTENT_BLANKCD equ 00000010h
    ARCONTENT_BLANKDVD equ 00000020h
    ARCONTENT_UNKNOWNCONTENT equ 00000040h
    ARCONTENT_AUTOPLAYPIX equ 00000080h
    ARCONTENT_AUTOPLAYMUSIC equ 00000100h
    ARCONTENT_AUTOPLAYVIDEO equ 00000200h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ARCONTENT_VCD equ 00000400h
      ARCONTENT_SVCD equ 00000800h
      ARCONTENT_DVDAUDIO equ 00001000h
      ARCONTENT_BLANKBD equ 00002000h
      ARCONTENT_BLURAY equ 00004000h
      ARCONTENT_CAMERASTORAGE equ 00008000h
      ARCONTENT_CUSTOMEVENT equ 00010000h
      ARCONTENT_NONE equ 00000000h
      ARCONTENT_MASK equ 0001FFFEh
      ARCONTENT_PHASE_UNKNOWN equ 00000000h
      ARCONTENT_PHASE_PRESNIFF equ 10000000h
      ARCONTENT_PHASE_SNIFFING equ 20000000h
      ARCONTENT_PHASE_FINAL equ 40000000h
      ARCONTENT_PHASE_MASK equ 70000000h
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0062_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0062_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IActionProgress_INTERFACE_DEFINED__
      __IActionProgress_INTERFACE_DEFINED__ equ <>
      _SPBEGINF typedef SDWORD
      SPBEGINF_NORMAL equ 0
      SPBEGINF_AUTOTIME equ 2h
      SPBEGINF_NOPROGRESSBAR equ 10h
      SPBEGINF_MARQUEEPROGRESS equ 20h
      SPBEGINF_NOCANCELBUTTON equ 40h

      SPBEGINF typedef DWORD
      SPACTION typedef SDWORD
      SPACTION_NONE equ 0
      SPACTION_MOVING equ
      SPACTION_COPYING equ
      SPACTION_RECYCLING equ
      SPACTION_APPLYINGATTRIBS equ
      SPACTION_DOWNLOADING equ
      SPACTION_SEARCHING_INTERNET equ
      SPACTION_CALCULATING equ
      SPACTION_UPLOADING equ
      SPACTION_SEARCHING_FILES equ
      SPACTION_DELETING equ
      SPACTION_RENAMING equ
      SPACTION_FORMATTING equ
      SPACTION_COPY_MOVING equ
      _SPACTION typedef SPACTION

      SPTEXT typedef SDWORD
      SPTEXT_ACTIONDESCRIPTION equ 1
      SPTEXT_ACTIONDETAIL equ
      _SPTEXT typedef SPTEXT

      externdef IID_IActionProgress:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IActionProgressVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IActionProgressVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IActionProgress, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IActionProgress
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IActionProgress
          DECLSPEC_XFGVIRT(IActionProgress, Begin)
          STD_METHOD Begin, :ptr IActionProgress, :SPACTION, :SPBEGINF
          DECLSPEC_XFGVIRT(IActionProgress, UpdateProgress)
          STD_METHOD UpdateProgress, :ptr IActionProgress, :ULONGLONG, :ULONGLONG
          DECLSPEC_XFGVIRT(IActionProgress, UpdateText)
          STD_METHOD UpdateText, :ptr IActionProgress, :SPTEXT, :LPCWSTR, :BOOL
          DECLSPEC_XFGVIRT(IActionProgress, QueryCancel)
          STD_METHOD QueryCancel, :ptr IActionProgress, :ptr BOOL
          DECLSPEC_XFGVIRT(IActionProgress, ResetCancel)
          STD_METHOD ResetCancel, :ptr IActionProgress
          DECLSPEC_XFGVIRT(IActionProgress, End)
          STD_METHOD End_, :ptr IActionProgress
          ??Interface equ <>
          END_INTERFACE
        IActionProgressVtbl ends
        IActionProgress struct
          lpVtbl POINTER ?
        IActionProgress ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellExtInit_INTERFACE_DEFINED__
      __IShellExtInit_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellExtInit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellExtInitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellExtInitVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellExtInit, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellExtInit
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellExtInit
          DECLSPEC_XFGVIRT(IShellExtInit, Initialize)
          STD_METHOD Initialize, :ptr IShellExtInit, :PCIDLIST_ABSOLUTE, :ptr IDataObject, :HKEY
          ??Interface equ <>
          END_INTERFACE
        IShellExtInitVtbl ends
        IShellExtInit struct
          lpVtbl POINTER ?
        IShellExtInit ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IShellExtInit_RemoteInitialize_Proxy proto WIN_STD_CALL_CONV :ptr IShellExtInit, :PCIDLIST_ABSOLUTE, :ptr IDataObject, :HANDLE
      IShellExtInit_RemoteInitialize_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    LPSHELLEXTINIT typedef ptr IShellExtInit
    externdef __MIDL_itf_shobjidl_core_0000_0064_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0064_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellPropSheetExt_INTERFACE_DEFINED__
      __IShellPropSheetExt_INTERFACE_DEFINED__ equ <>
      _EXPPS typedef SDWORD
      EXPPS_FILETYPES equ 1h

      EXPPS typedef UINT
      externdef IID_IShellPropSheetExt:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellPropSheetExtVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellPropSheetExtVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellPropSheetExt, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellPropSheetExt
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellPropSheetExt
          DECLSPEC_XFGVIRT(IShellPropSheetExt, AddPages)
          STD_METHOD AddPages, :ptr IShellPropSheetExt, :LPFNSVADDPROPSHEETPAGE, :LPARAM
          DECLSPEC_XFGVIRT(IShellPropSheetExt, ReplacePage)
          STD_METHOD ReplacePage, :ptr IShellPropSheetExt, :EXPPS, :LPFNSVADDPROPSHEETPAGE, :LPARAM
          ??Interface equ <>
          END_INTERFACE
        IShellPropSheetExtVtbl ends
        IShellPropSheetExt struct
          lpVtbl POINTER ?
        IShellPropSheetExt ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPSHELLPROPSHEETEXT typedef ptr IShellPropSheetExt
    externdef __MIDL_itf_shobjidl_core_0000_0065_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0065_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IRemoteComputer_INTERFACE_DEFINED__
      __IRemoteComputer_INTERFACE_DEFINED__ equ <>
      externdef IID_IRemoteComputer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRemoteComputerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRemoteComputerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IRemoteComputer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRemoteComputer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRemoteComputer
          DECLSPEC_XFGVIRT(IRemoteComputer, Initialize)
          STD_METHOD Initialize, :ptr IRemoteComputer, :LPCWSTR, :BOOL
          ??Interface equ <>
          END_INTERFACE
        IRemoteComputerVtbl ends
        IRemoteComputer struct
          lpVtbl POINTER ?
        IRemoteComputer ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IQueryContinue_INTERFACE_DEFINED__
      __IQueryContinue_INTERFACE_DEFINED__ equ <>
      externdef IID_IQueryContinue:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IQueryContinueVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IQueryContinueVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IQueryContinue, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IQueryContinue
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IQueryContinue
          DECLSPEC_XFGVIRT(IQueryContinue, QueryContinue)
          STD_METHOD QueryContinue, :ptr IQueryContinue
          ??Interface equ <>
          END_INTERFACE
        IQueryContinueVtbl ends
        IQueryContinue struct
          lpVtbl POINTER ?
        IQueryContinue ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IObjectWithCancelEvent_INTERFACE_DEFINED__
      __IObjectWithCancelEvent_INTERFACE_DEFINED__ equ <>
      externdef IID_IObjectWithCancelEvent:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectWithCancelEventVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectWithCancelEventVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IObjectWithCancelEvent, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectWithCancelEvent
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectWithCancelEvent
          DECLSPEC_XFGVIRT(IObjectWithCancelEvent, GetCancelEvent)
          STD_METHOD GetCancelEvent, :ptr IObjectWithCancelEvent, :ptr HANDLE
          ??Interface equ <>
          END_INTERFACE
        IObjectWithCancelEventVtbl ends
        IObjectWithCancelEvent struct
          lpVtbl POINTER ?
        IObjectWithCancelEvent ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IUserNotification_INTERFACE_DEFINED__
      __IUserNotification_INTERFACE_DEFINED__ equ <>
      externdef IID_IUserNotification:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUserNotificationVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUserNotificationVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IUserNotification, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IUserNotification
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IUserNotification
          DECLSPEC_XFGVIRT(IUserNotification, SetBalloonInfo)
          STD_METHOD SetBalloonInfo, :ptr IUserNotification, :LPCWSTR, :LPCWSTR, :DWORD
          DECLSPEC_XFGVIRT(IUserNotification, SetBalloonRetry)
          STD_METHOD SetBalloonRetry, :ptr IUserNotification, :DWORD, :DWORD, :UINT
          DECLSPEC_XFGVIRT(IUserNotification, SetIconInfo)
          STD_METHOD SetIconInfo, :ptr IUserNotification, :HICON, :LPCWSTR
          DECLSPEC_XFGVIRT(IUserNotification, Show)
          STD_METHOD Show, :ptr IUserNotification, :ptr IQueryContinue, :DWORD
          DECLSPEC_XFGVIRT(IUserNotification, PlaySound)
          STD_METHOD PlaySound, :ptr IUserNotification, :LPCWSTR
          ??Interface equ <>
          END_INTERFACE
        IUserNotificationVtbl ends
        IUserNotification struct
          lpVtbl POINTER ?
        IUserNotification ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IItemNameLimits_INTERFACE_DEFINED__
      __IItemNameLimits_INTERFACE_DEFINED__ equ <>
      externdef IID_IItemNameLimits:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IItemNameLimitsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IItemNameLimitsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IItemNameLimits, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IItemNameLimits
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IItemNameLimits
          DECLSPEC_XFGVIRT(IItemNameLimits, GetValidCharacters)
          STD_METHOD GetValidCharacters, :ptr IItemNameLimits, :ptr LPWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IItemNameLimits, GetMaxLength)
          STD_METHOD GetMaxLength, :ptr IItemNameLimits, :LPCWSTR, :ptr SDWORD
          ??Interface equ <>
          END_INTERFACE
        IItemNameLimitsVtbl ends
        IItemNameLimits struct
          lpVtbl POINTER ?
        IItemNameLimits ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0070_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0070_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISearchFolderItemFactory_INTERFACE_DEFINED__
        __ISearchFolderItemFactory_INTERFACE_DEFINED__ equ <>
        externdef IID_ISearchFolderItemFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISearchFolderItemFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISearchFolderItemFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISearchFolderItemFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISearchFolderItemFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISearchFolderItemFactory
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetDisplayName)
            STD_METHOD SetDisplayName, :ptr ISearchFolderItemFactory, :LPCWSTR
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetFolderTypeID)
            STD_METHOD SetFolderTypeID, :ptr ISearchFolderItemFactory, :FOLDERTYPEID
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetFolderLogicalViewMode)
            STD_METHOD SetFolderLogicalViewMode, :ptr ISearchFolderItemFactory, :FOLDERLOGICALVIEWMODE
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetIconSize)
            STD_METHOD SetIconSize, :ptr ISearchFolderItemFactory, :SDWORD
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetVisibleColumns)
            STD_METHOD SetVisibleColumns, :ptr ISearchFolderItemFactory, :UINT, :ptr PROPERTYKEY
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetSortColumns)
            STD_METHOD SetSortColumns, :ptr ISearchFolderItemFactory, :UINT, :ptr SORTCOLUMN
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetGroupColumn)
            STD_METHOD SetGroupColumn, :ptr ISearchFolderItemFactory, :REFPROPERTYKEY
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetStacks)
            STD_METHOD SetStacks, :ptr ISearchFolderItemFactory, :UINT, :ptr PROPERTYKEY
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetScope)
            STD_METHOD SetScope, :ptr ISearchFolderItemFactory, :ptr IShellItemArray
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, SetCondition)
            STD_METHOD SetCondition, :ptr ISearchFolderItemFactory, :ptr ICondition
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, GetShellItem)
            STD_METHOD GetShellItem, :ptr ISearchFolderItemFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(ISearchFolderItemFactory, GetIDList)
            STD_METHOD GetIDList, :ptr ISearchFolderItemFactory, :ptr PIDLIST_ABSOLUTE
            ??Interface equ <>
            END_INTERFACE
          ISearchFolderItemFactoryVtbl ends
          ISearchFolderItemFactory struct
            lpVtbl POINTER ?
          ISearchFolderItemFactory ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    IEI_PRIORITY_MAX equ <ITSAT_MAX_PRIORITY>
    IEI_PRIORITY_MIN equ <ITSAT_MIN_PRIORITY>
    IEIT_PRIORITY_NORMAL equ <ITSAT_DEFAULT_PRIORITY>
    IEIFLAG_ASYNC equ 0001h
    IEIFLAG_CACHE equ 0002h
    IEIFLAG_ASPECT equ 0004h
    IEIFLAG_OFFLINE equ 0008h
    IEIFLAG_GLEAM equ 0010h
    IEIFLAG_SCREEN equ 0020h
    IEIFLAG_ORIGSIZE equ 0040h
    IEIFLAG_NOSTAMP equ 0080h
    IEIFLAG_NOBORDER equ 0100h
    IEIFLAG_QUALITY equ 0200h
    IEIFLAG_REFRESH equ 0400h
    externdef __MIDL_itf_shobjidl_core_0000_0071_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0071_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IExtractImage_INTERFACE_DEFINED__
      __IExtractImage_INTERFACE_DEFINED__ equ <>
      externdef IID_IExtractImage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExtractImageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExtractImageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IExtractImage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IExtractImage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IExtractImage
          DECLSPEC_XFGVIRT(IExtractImage, GetLocation)
          STD_METHOD GetLocation, :ptr IExtractImage, :LPWSTR, :DWORD, :ptr DWORD, :ptr SIZE_, :DWORD, :ptr DWORD
          DECLSPEC_XFGVIRT(IExtractImage, Extract)
          STD_METHOD Extract, :ptr IExtractImage, :ptr HBITMAP
          ??Interface equ <>
          END_INTERFACE
        IExtractImageVtbl ends
        IExtractImage struct
          lpVtbl POINTER ?
        IExtractImage ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPEXTRACTIMAGE typedef ptr IExtractImage
    externdef __MIDL_itf_shobjidl_core_0000_0072_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0072_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IExtractImage2_INTERFACE_DEFINED__
      __IExtractImage2_INTERFACE_DEFINED__ equ <>
      externdef IID_IExtractImage2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExtractImage2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExtractImage2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IExtractImage2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IExtractImage2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IExtractImage2
          DECLSPEC_XFGVIRT(IExtractImage, GetLocation)
          STD_METHOD GetLocation, :ptr IExtractImage2, :LPWSTR, :DWORD, :ptr DWORD, :ptr SIZE_, :DWORD, :ptr DWORD
          DECLSPEC_XFGVIRT(IExtractImage, Extract)
          STD_METHOD Extract, :ptr IExtractImage2, :ptr HBITMAP
          DECLSPEC_XFGVIRT(IExtractImage2, GetDateStamp)
          STD_METHOD GetDateStamp, :ptr IExtractImage2, :ptr FILETIME
          ??Interface equ <>
          END_INTERFACE
        IExtractImage2Vtbl ends
        IExtractImage2 struct
          lpVtbl POINTER ?
        IExtractImage2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPEXTRACTIMAGE2 typedef ptr IExtractImage2
    externdef __MIDL_itf_shobjidl_core_0000_0073_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0073_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IThumbnailHandlerFactory_INTERFACE_DEFINED__
      __IThumbnailHandlerFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IThumbnailHandlerFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IThumbnailHandlerFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IThumbnailHandlerFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IThumbnailHandlerFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IThumbnailHandlerFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IThumbnailHandlerFactory
          DECLSPEC_XFGVIRT(IThumbnailHandlerFactory, GetThumbnailHandler)
          STD_METHOD GetThumbnailHandler, :ptr IThumbnailHandlerFactory, :PCUITEMID_CHILD, :ptr IBindCtx, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IThumbnailHandlerFactoryVtbl ends
        IThumbnailHandlerFactory struct
          lpVtbl POINTER ?
        IThumbnailHandlerFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IParentAndItem_INTERFACE_DEFINED__
      __IParentAndItem_INTERFACE_DEFINED__ equ <>
      externdef IID_IParentAndItem:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IParentAndItemVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IParentAndItemVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IParentAndItem, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IParentAndItem
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IParentAndItem
          DECLSPEC_XFGVIRT(IParentAndItem, SetParentAndItem)
          STD_METHOD SetParentAndItem, :ptr IParentAndItem, :PCIDLIST_ABSOLUTE, :ptr IShellFolder, :PCUITEMID_CHILD
          DECLSPEC_XFGVIRT(IParentAndItem, GetParentAndItem)
          STD_METHOD GetParentAndItem, :ptr IParentAndItem, :ptr PIDLIST_ABSOLUTE, :ptr ptr IShellFolder, :ptr PITEMID_CHILD
          ??Interface equ <>
          END_INTERFACE
        IParentAndItemVtbl ends
        IParentAndItem struct
          lpVtbl POINTER ?
        IParentAndItem ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IParentAndItem_RemoteGetParentAndItem_Proxy proto WIN_STD_CALL_CONV :ptr IParentAndItem, :ptr PIDLIST_ABSOLUTE, :ptr ptr IShellFolder, :ptr PITEMID_CHILD
      IParentAndItem_RemoteGetParentAndItem_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __IDockingWindow_INTERFACE_DEFINED__
      __IDockingWindow_INTERFACE_DEFINED__ equ <>
      externdef IID_IDockingWindow:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDockingWindowVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDockingWindowVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDockingWindow, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDockingWindow
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDockingWindow
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          STD_METHOD GetWindow, :ptr IDockingWindow, :ptr HWND
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IDockingWindow, :BOOL
          DECLSPEC_XFGVIRT(IDockingWindow, ShowDW)
          STD_METHOD ShowDW, :ptr IDockingWindow, :BOOL
          DECLSPEC_XFGVIRT(IDockingWindow, CloseDW)
          STD_METHOD CloseDW, :ptr IDockingWindow, :DWORD
          DECLSPEC_XFGVIRT(IDockingWindow, ResizeBorderDW)
          STD_METHOD ResizeBorderDW, :ptr IDockingWindow, :LPCRECT, :ptr IUnknown, :BOOL
          ??Interface equ <>
          END_INTERFACE
        IDockingWindowVtbl ends
        IDockingWindow struct
          lpVtbl POINTER ?
        IDockingWindow ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    DBIM_MINSIZE equ 0001h
    DBIM_MAXSIZE equ 0002h
    DBIM_INTEGRAL equ 0004h
    DBIM_ACTUAL equ 0008h
    DBIM_TITLE equ 0010h
    DBIM_MODEFLAGS equ 0020h
    DBIM_BKCOLOR equ 0040h
    include pshpack8.inc
    DESKBANDINFO struct
      dwMask DWORD ?
      ptMinSize POINTL <>
      ptMaxSize POINTL <>
      ptIntegral POINTL <>
      ptActual POINTL <>
      wszTitle WCHAR 256 dup (?)
      dwModeFlags DWORD ?
      crBkgnd COLORREF ?
    DESKBANDINFO ends
    include poppack.inc
    DBIMF_NORMAL equ 0000h
    DBIMF_FIXED equ 0001h
    DBIMF_FIXEDBMP equ 0004h
    DBIMF_VARIABLEHEIGHT equ 0008h
    DBIMF_UNDELETEABLE equ 0010h
    DBIMF_DEBOSSED equ 0020h
    DBIMF_BKCOLOR equ 0040h
    DBIMF_USECHEVRON equ 0080h
    DBIMF_BREAK equ 0100h
    DBIMF_ADDTOFRONT equ 0200h
    DBIMF_TOPALIGN equ 0400h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      DBIMF_NOGRIPPER equ 0800h
      DBIMF_ALWAYSGRIPPER equ 1000h
      DBIMF_NOMARGINS equ 2000h
    endif
    DBIF_VIEWMODE_NORMAL equ 0000h
    DBIF_VIEWMODE_VERTICAL equ 0001h
    DBIF_VIEWMODE_FLOATING equ 0002h
    DBIF_VIEWMODE_TRANSPARENT equ 0004h
    tagDESKBANDCID typedef SDWORD
    DBID_BANDINFOCHANGED equ 0
    DBID_SHOWONLY equ 1
    DBID_MAXIMIZEBAND equ 2
    DBID_PUSHCHEVRON equ 3
    DBID_DELAYINIT equ 4
    DBID_FINISHINIT equ 5
    DBID_SETWINDOWTHEME equ 6
    DBID_PERMITAUTOHIDE equ 7

    DBPC_SELECTFIRST equ -1
    DBPC_SELECTLAST equ -2
    CGID_DeskBand equ <IID_IDeskBand>
    externdef __MIDL_itf_shobjidl_core_0000_0076_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0076_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDeskBand_INTERFACE_DEFINED__
      __IDeskBand_INTERFACE_DEFINED__ equ <>
      externdef IID_IDeskBand:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDeskBandVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDeskBandVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDeskBand, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDeskBand
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDeskBand
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          STD_METHOD GetWindow, :ptr IDeskBand, :ptr HWND
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IDeskBand, :BOOL
          DECLSPEC_XFGVIRT(IDockingWindow, ShowDW)
          STD_METHOD ShowDW, :ptr IDeskBand, :BOOL
          DECLSPEC_XFGVIRT(IDockingWindow, CloseDW)
          STD_METHOD CloseDW, :ptr IDeskBand, :DWORD
          DECLSPEC_XFGVIRT(IDockingWindow, ResizeBorderDW)
          STD_METHOD ResizeBorderDW, :ptr IDeskBand, :LPCRECT, :ptr IUnknown, :BOOL
          DECLSPEC_XFGVIRT(IDeskBand, GetBandInfo)
          STD_METHOD GetBandInfo, :ptr IDeskBand, :DWORD, :DWORD, :ptr DESKBANDINFO
          ??Interface equ <>
          END_INTERFACE
        IDeskBandVtbl ends
        IDeskBand struct
          lpVtbl POINTER ?
        IDeskBand ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0077_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0077_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDeskBandInfo_INTERFACE_DEFINED__
        __IDeskBandInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IDeskBandInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDeskBandInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDeskBandInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDeskBandInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDeskBandInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDeskBandInfo
            DECLSPEC_XFGVIRT(IDeskBandInfo, GetDefaultBandWidth)
            STD_METHOD GetDefaultBandWidth, :ptr IDeskBandInfo, :DWORD, :DWORD, :ptr SDWORD
            ??Interface equ <>
            END_INTERFACE
          IDeskBandInfoVtbl ends
          IDeskBandInfo struct
            lpVtbl POINTER ?
          IDeskBandInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0078_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0078_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITaskbarList_INTERFACE_DEFINED__
      __ITaskbarList_INTERFACE_DEFINED__ equ <>
      externdef IID_ITaskbarList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITaskbarListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITaskbarListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITaskbarList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITaskbarList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITaskbarList
          DECLSPEC_XFGVIRT(ITaskbarList, HrInit)
          STD_METHOD HrInit, :ptr ITaskbarList
          DECLSPEC_XFGVIRT(ITaskbarList, AddTab)
          STD_METHOD AddTab, :ptr ITaskbarList, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, DeleteTab)
          STD_METHOD DeleteTab, :ptr ITaskbarList, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, ActivateTab)
          STD_METHOD ActivateTab, :ptr ITaskbarList, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, SetActiveAlt)
          STD_METHOD SetActiveAlt, :ptr ITaskbarList, :HWND
          ??Interface equ <>
          END_INTERFACE
        ITaskbarListVtbl ends
        ITaskbarList struct
          lpVtbl POINTER ?
        ITaskbarList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ITaskbarList2_INTERFACE_DEFINED__
      __ITaskbarList2_INTERFACE_DEFINED__ equ <>
      externdef IID_ITaskbarList2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITaskbarList2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITaskbarList2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITaskbarList2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITaskbarList2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITaskbarList2
          DECLSPEC_XFGVIRT(ITaskbarList, HrInit)
          STD_METHOD HrInit, :ptr ITaskbarList2
          DECLSPEC_XFGVIRT(ITaskbarList, AddTab)
          STD_METHOD AddTab, :ptr ITaskbarList2, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, DeleteTab)
          STD_METHOD DeleteTab, :ptr ITaskbarList2, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, ActivateTab)
          STD_METHOD ActivateTab, :ptr ITaskbarList2, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, SetActiveAlt)
          STD_METHOD SetActiveAlt, :ptr ITaskbarList2, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList2, MarkFullscreenWindow)
          STD_METHOD MarkFullscreenWindow, :ptr ITaskbarList2, :HWND, :BOOL
          ??Interface equ <>
          END_INTERFACE
        ITaskbarList2Vtbl ends
        ITaskbarList2 struct
          lpVtbl POINTER ?
        ITaskbarList2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifdef MIDL_PASS
      ;[...]
    endif
    THUMBBUTTONFLAGS typedef SDWORD
    THBF_ENABLED equ 0
    THBF_DISABLED equ 1h
    THBF_DISMISSONCLICK equ 2h
    THBF_NOBACKGROUND equ 4h
    THBF_HIDDEN equ 8h
    THBF_NONINTERACTIVE equ 10h

    DEFINE_ENUM_FLAG_OPERATORS(THUMBBUTTONFLAGS)
    THUMBBUTTONMASK typedef SDWORD
    THB_BITMAP equ 1h
    THB_ICON equ 2h
    THB_TOOLTIP equ 4h
    THB_FLAGS equ 8h

    DEFINE_ENUM_FLAG_OPERATORS(THUMBBUTTONMASK)
    include pshpack8.inc
    THUMBBUTTON struct
      dwMask THUMBBUTTONMASK ?
      iId UINT ?
      iBitmap UINT ?
      hIcon HICON ?
      szTip WCHAR 260 dup (?)
      dwFlags THUMBBUTTONFLAGS ?
    THUMBBUTTON ends
    LPTHUMBBUTTON typedef ptr THUMBBUTTON
    include poppack.inc
    THBN_CLICKED equ 1800h
    externdef __MIDL_itf_shobjidl_core_0000_0080_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0080_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITaskbarList3_INTERFACE_DEFINED__
      __ITaskbarList3_INTERFACE_DEFINED__ equ <>
      TBPFLAG typedef SDWORD
      TBPF_NOPROGRESS equ 0
      TBPF_INDETERMINATE equ 1h
      TBPF_NORMAL equ 2h
      TBPF_ERROR equ 4h
      TBPF_PAUSED equ 8h

      DEFINE_ENUM_FLAG_OPERATORS(TBPFLAG)
      externdef IID_ITaskbarList3:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITaskbarList3Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITaskbarList3Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITaskbarList3, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITaskbarList3
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITaskbarList3
          DECLSPEC_XFGVIRT(ITaskbarList, HrInit)
          STD_METHOD HrInit, :ptr ITaskbarList3
          DECLSPEC_XFGVIRT(ITaskbarList, AddTab)
          STD_METHOD AddTab, :ptr ITaskbarList3, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, DeleteTab)
          STD_METHOD DeleteTab, :ptr ITaskbarList3, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, ActivateTab)
          STD_METHOD ActivateTab, :ptr ITaskbarList3, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, SetActiveAlt)
          STD_METHOD SetActiveAlt, :ptr ITaskbarList3, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList2, MarkFullscreenWindow)
          STD_METHOD MarkFullscreenWindow, :ptr ITaskbarList3, :HWND, :BOOL
          DECLSPEC_XFGVIRT(ITaskbarList3, SetProgressValue)
          STD_METHOD SetProgressValue, :ptr ITaskbarList3, :HWND, :ULONGLONG, :ULONGLONG
          DECLSPEC_XFGVIRT(ITaskbarList3, SetProgressState)
          STD_METHOD SetProgressState, :ptr ITaskbarList3, :HWND, :TBPFLAG
          DECLSPEC_XFGVIRT(ITaskbarList3, RegisterTab)
          STD_METHOD RegisterTab, :ptr ITaskbarList3, :HWND, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList3, UnregisterTab)
          STD_METHOD UnregisterTab, :ptr ITaskbarList3, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList3, SetTabOrder)
          STD_METHOD SetTabOrder, :ptr ITaskbarList3, :HWND, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList3, SetTabActive)
          STD_METHOD SetTabActive, :ptr ITaskbarList3, :HWND, :HWND, :DWORD
          DECLSPEC_XFGVIRT(ITaskbarList3, ThumbBarAddButtons)
          STD_METHOD ThumbBarAddButtons, :ptr ITaskbarList3, :HWND, :UINT, :LPTHUMBBUTTON
          DECLSPEC_XFGVIRT(ITaskbarList3, ThumbBarUpdateButtons)
          STD_METHOD ThumbBarUpdateButtons, :ptr ITaskbarList3, :HWND, :UINT, :LPTHUMBBUTTON
          DECLSPEC_XFGVIRT(ITaskbarList3, ThumbBarSetImageList)
          STD_METHOD ThumbBarSetImageList, :ptr ITaskbarList3, :HWND, :HIMAGELIST
          DECLSPEC_XFGVIRT(ITaskbarList3, SetOverlayIcon)
          STD_METHOD SetOverlayIcon, :ptr ITaskbarList3, :HWND, :HICON, :LPCWSTR
          DECLSPEC_XFGVIRT(ITaskbarList3, SetThumbnailTooltip)
          STD_METHOD SetThumbnailTooltip, :ptr ITaskbarList3, :HWND, :LPCWSTR
          DECLSPEC_XFGVIRT(ITaskbarList3, SetThumbnailClip)
          STD_METHOD SetThumbnailClip, :ptr ITaskbarList3, :HWND, :ptr RECT
          ??Interface equ <>
          END_INTERFACE
        ITaskbarList3Vtbl ends
        ITaskbarList3 struct
          lpVtbl POINTER ?
        ITaskbarList3 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ITaskbarList4_INTERFACE_DEFINED__
      __ITaskbarList4_INTERFACE_DEFINED__ equ <>
      STPFLAG typedef SDWORD
      STPF_NONE equ 0
      STPF_USEAPPTHUMBNAILALWAYS equ 1h
      STPF_USEAPPTHUMBNAILWHENACTIVE equ 2h
      STPF_USEAPPPEEKALWAYS equ 4h
      STPF_USEAPPPEEKWHENACTIVE equ 8h

      DEFINE_ENUM_FLAG_OPERATORS(STPFLAG)
      externdef IID_ITaskbarList4:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITaskbarList4Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITaskbarList4Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITaskbarList4, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITaskbarList4
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITaskbarList4
          DECLSPEC_XFGVIRT(ITaskbarList, HrInit)
          STD_METHOD HrInit, :ptr ITaskbarList4
          DECLSPEC_XFGVIRT(ITaskbarList, AddTab)
          STD_METHOD AddTab, :ptr ITaskbarList4, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, DeleteTab)
          STD_METHOD DeleteTab, :ptr ITaskbarList4, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, ActivateTab)
          STD_METHOD ActivateTab, :ptr ITaskbarList4, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList, SetActiveAlt)
          STD_METHOD SetActiveAlt, :ptr ITaskbarList4, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList2, MarkFullscreenWindow)
          STD_METHOD MarkFullscreenWindow, :ptr ITaskbarList4, :HWND, :BOOL
          DECLSPEC_XFGVIRT(ITaskbarList3, SetProgressValue)
          STD_METHOD SetProgressValue, :ptr ITaskbarList4, :HWND, :ULONGLONG, :ULONGLONG
          DECLSPEC_XFGVIRT(ITaskbarList3, SetProgressState)
          STD_METHOD SetProgressState, :ptr ITaskbarList4, :HWND, :TBPFLAG
          DECLSPEC_XFGVIRT(ITaskbarList3, RegisterTab)
          STD_METHOD RegisterTab, :ptr ITaskbarList4, :HWND, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList3, UnregisterTab)
          STD_METHOD UnregisterTab, :ptr ITaskbarList4, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList3, SetTabOrder)
          STD_METHOD SetTabOrder, :ptr ITaskbarList4, :HWND, :HWND
          DECLSPEC_XFGVIRT(ITaskbarList3, SetTabActive)
          STD_METHOD SetTabActive, :ptr ITaskbarList4, :HWND, :HWND, :DWORD
          DECLSPEC_XFGVIRT(ITaskbarList3, ThumbBarAddButtons)
          STD_METHOD ThumbBarAddButtons, :ptr ITaskbarList4, :HWND, :UINT, :LPTHUMBBUTTON
          DECLSPEC_XFGVIRT(ITaskbarList3, ThumbBarUpdateButtons)
          STD_METHOD ThumbBarUpdateButtons, :ptr ITaskbarList4, :HWND, :UINT, :LPTHUMBBUTTON
          DECLSPEC_XFGVIRT(ITaskbarList3, ThumbBarSetImageList)
          STD_METHOD ThumbBarSetImageList, :ptr ITaskbarList4, :HWND, :HIMAGELIST
          DECLSPEC_XFGVIRT(ITaskbarList3, SetOverlayIcon)
          STD_METHOD SetOverlayIcon, :ptr ITaskbarList4, :HWND, :HICON, :LPCWSTR
          DECLSPEC_XFGVIRT(ITaskbarList3, SetThumbnailTooltip)
          STD_METHOD SetThumbnailTooltip, :ptr ITaskbarList4, :HWND, :LPCWSTR
          DECLSPEC_XFGVIRT(ITaskbarList3, SetThumbnailClip)
          STD_METHOD SetThumbnailClip, :ptr ITaskbarList4, :HWND, :ptr RECT
          DECLSPEC_XFGVIRT(ITaskbarList4, SetTabProperties)
          STD_METHOD SetTabProperties, :ptr ITaskbarList4, :HWND, :STPFLAG
          ??Interface equ <>
          END_INTERFACE
        ITaskbarList4Vtbl ends
        ITaskbarList4 struct
          lpVtbl POINTER ?
        ITaskbarList4 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      if (_WIN32_IE ge _WIN32_IE_IE70)
        externdef __MIDL_itf_shobjidl_core_0000_0082_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0082_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IExplorerBrowserEvents_INTERFACE_DEFINED__
          __IExplorerBrowserEvents_INTERFACE_DEFINED__ equ <>
          externdef IID_IExplorerBrowserEvents:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IExplorerBrowserEventsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IExplorerBrowserEventsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IExplorerBrowserEvents, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IExplorerBrowserEvents
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IExplorerBrowserEvents
              DECLSPEC_XFGVIRT(IExplorerBrowserEvents, OnNavigationPending)
              STD_METHOD OnNavigationPending, :ptr IExplorerBrowserEvents, :PCIDLIST_ABSOLUTE
              DECLSPEC_XFGVIRT(IExplorerBrowserEvents, OnViewCreated)
              STD_METHOD OnViewCreated, :ptr IExplorerBrowserEvents, :ptr IShellView
              DECLSPEC_XFGVIRT(IExplorerBrowserEvents, OnNavigationComplete)
              STD_METHOD OnNavigationComplete, :ptr IExplorerBrowserEvents, :PCIDLIST_ABSOLUTE
              DECLSPEC_XFGVIRT(IExplorerBrowserEvents, OnNavigationFailed)
              STD_METHOD OnNavigationFailed, :ptr IExplorerBrowserEvents, :PCIDLIST_ABSOLUTE
              ??Interface equ <>
              END_INTERFACE
            IExplorerBrowserEventsVtbl ends
            IExplorerBrowserEvents struct
              lpVtbl POINTER ?
            IExplorerBrowserEvents ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        EXPLORER_BROWSER_OPTIONS typedef SDWORD
        EBO_NONE equ 0
        EBO_NAVIGATEONCE equ 1h
        EBO_SHOWFRAMES equ 2h
        EBO_ALWAYSNAVIGATE equ 4h
        EBO_NOTRAVELLOG equ 8h
        EBO_NOWRAPPERWINDOW equ 10h
        EBO_HTMLSHAREPOINTVIEW equ 20h
        EBO_NOBORDER equ 40h
        EBO_NOPERSISTVIEWSTATE equ 80h

        DEFINE_ENUM_FLAG_OPERATORS(EXPLORER_BROWSER_OPTIONS)
        EXPLORER_BROWSER_FILL_FLAGS typedef SDWORD
        EBF_NONE equ 0
        EBF_SELECTFROMDATAOBJECT equ 100h
        EBF_NODROPTARGET equ 200h

        DEFINE_ENUM_FLAG_OPERATORS(EXPLORER_BROWSER_FILL_FLAGS)
        externdef __MIDL_itf_shobjidl_core_0000_0083_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0083_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IExplorerBrowser_INTERFACE_DEFINED__
          __IExplorerBrowser_INTERFACE_DEFINED__ equ <>
          externdef IID_IExplorerBrowser:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IExplorerBrowserVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IExplorerBrowserVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IExplorerBrowser, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IExplorerBrowser
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IExplorerBrowser
              DECLSPEC_XFGVIRT(IExplorerBrowser, Initialize)
              STD_METHOD Initialize, :ptr IExplorerBrowser, :HWND, :ptr RECT, :ptr FOLDERSETTINGS
              DECLSPEC_XFGVIRT(IExplorerBrowser, Destroy)
              STD_METHOD Destroy_, :ptr IExplorerBrowser
              DECLSPEC_XFGVIRT(IExplorerBrowser, SetRect)
              STD_METHOD SetRect, :ptr IExplorerBrowser, :ptr HDWP, :RECT
              DECLSPEC_XFGVIRT(IExplorerBrowser, SetPropertyBag)
              STD_METHOD SetPropertyBag, :ptr IExplorerBrowser, :LPCWSTR
              DECLSPEC_XFGVIRT(IExplorerBrowser, SetEmptyText)
              STD_METHOD SetEmptyText, :ptr IExplorerBrowser, :LPCWSTR
              DECLSPEC_XFGVIRT(IExplorerBrowser, SetFolderSettings)
              STD_METHOD SetFolderSettings, :ptr IExplorerBrowser, :ptr FOLDERSETTINGS
              DECLSPEC_XFGVIRT(IExplorerBrowser, Advise)
              STD_METHOD Advise, :ptr IExplorerBrowser, :ptr IExplorerBrowserEvents, :ptr DWORD
              DECLSPEC_XFGVIRT(IExplorerBrowser, Unadvise)
              STD_METHOD Unadvise, :ptr IExplorerBrowser, :DWORD
              DECLSPEC_XFGVIRT(IExplorerBrowser, SetOptions)
              STD_METHOD SetOptions, :ptr IExplorerBrowser, :EXPLORER_BROWSER_OPTIONS
              DECLSPEC_XFGVIRT(IExplorerBrowser, GetOptions)
              STD_METHOD GetOptions, :ptr IExplorerBrowser, :ptr EXPLORER_BROWSER_OPTIONS
              DECLSPEC_XFGVIRT(IExplorerBrowser, BrowseToIDList)
              STD_METHOD BrowseToIDList, :ptr IExplorerBrowser, :PCUIDLIST_RELATIVE, :UINT
              DECLSPEC_XFGVIRT(IExplorerBrowser, BrowseToObject)
              STD_METHOD BrowseToObject, :ptr IExplorerBrowser, :ptr IUnknown, :UINT
              DECLSPEC_XFGVIRT(IExplorerBrowser, FillFromObject)
              STD_METHOD FillFromObject, :ptr IExplorerBrowser, :ptr IUnknown, :EXPLORER_BROWSER_FILL_FLAGS
              DECLSPEC_XFGVIRT(IExplorerBrowser, RemoveAll)
              STD_METHOD RemoveAll, :ptr IExplorerBrowser
              DECLSPEC_XFGVIRT(IExplorerBrowser, GetCurrentView)
              STD_METHOD GetCurrentView, :ptr IExplorerBrowser, :REFIID, :ptr ptr
              ??Interface equ <>
              END_INTERFACE
            IExplorerBrowserVtbl ends
            IExplorerBrowser struct
              lpVtbl POINTER ?
            IExplorerBrowser ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        externdef __MIDL_itf_shobjidl_core_0000_0084_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0084_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IEnumObjects_INTERFACE_DEFINED__
          __IEnumObjects_INTERFACE_DEFINED__ equ <>
          externdef IID_IEnumObjects:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IEnumObjectsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IEnumObjectsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IEnumObjects, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IEnumObjects
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IEnumObjects
              DECLSPEC_XFGVIRT(IEnumObjects, Next)
              STD_METHOD Next, :ptr IEnumObjects, :ULONG, :REFIID, :ptr ptr, :ptr ULONG
              DECLSPEC_XFGVIRT(IEnumObjects, Skip)
              STD_METHOD Skip, :ptr IEnumObjects, :ULONG
              DECLSPEC_XFGVIRT(IEnumObjects, Reset)
              STD_METHOD Reset, :ptr IEnumObjects
              DECLSPEC_XFGVIRT(IEnumObjects, Clone)
              STD_METHOD Clone, :ptr IEnumObjects, :ptr ptr IEnumObjects
              ??Interface equ <>
              END_INTERFACE
            IEnumObjectsVtbl ends
            IEnumObjects struct
              lpVtbl POINTER ?
            IEnumObjects ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
          IEnumObjects_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumObjects, :ULONG, :REFIID, :ptr ptr, :ptr ULONG
          IEnumObjects_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        endif
        _OPPROGDLGF typedef SDWORD
        OPPROGDLG_DEFAULT equ 0
        OPPROGDLG_ENABLEPAUSE equ 80h
        OPPROGDLG_ALLOWUNDO equ 100h
        OPPROGDLG_DONTDISPLAYSOURCEPATH equ 200h
        OPPROGDLG_DONTDISPLAYDESTPATH equ 400h
        OPPROGDLG_NOMULTIDAYESTIMATES equ 800h
        OPPROGDLG_DONTDISPLAYLOCATIONS equ 1000h

        OPPROGDLGF typedef DWORD
        externdef __MIDL_itf_shobjidl_core_0000_0085_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0085_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IOperationsProgressDialog_INTERFACE_DEFINED__
          __IOperationsProgressDialog_INTERFACE_DEFINED__ equ <>
          _PDMODE typedef SDWORD
          PDM_DEFAULT equ 0
          PDM_RUN equ 1h
          PDM_PREFLIGHT equ 2h
          PDM_UNDOING equ 4h
          PDM_ERRORSBLOCKING equ 8h
          PDM_INDETERMINATE equ 10h

          PDMODE typedef DWORD
          PDOPSTATUS typedef SDWORD
          PDOPS_RUNNING equ 1
          PDOPS_PAUSED equ 2
          PDOPS_CANCELLED equ 3
          PDOPS_STOPPED equ 4
          PDOPS_ERRORS equ 5

          externdef IID_IOperationsProgressDialog:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IOperationsProgressDialogVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IOperationsProgressDialogVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IOperationsProgressDialog, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, StartProgressDialog)
              STD_METHOD StartProgressDialog, :ptr IOperationsProgressDialog, :HWND, :OPPROGDLGF
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, StopProgressDialog)
              STD_METHOD StopProgressDialog, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, SetOperation)
              STD_METHOD SetOperation, :ptr IOperationsProgressDialog, :SPACTION
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, SetMode)
              STD_METHOD SetMode, :ptr IOperationsProgressDialog, :PDMODE
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, UpdateProgress)
              STD_METHOD UpdateProgress, :ptr IOperationsProgressDialog, :ULONGLONG, :ULONGLONG, :ULONGLONG, :ULONGLONG, :ULONGLONG, :ULONGLONG
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, UpdateLocations)
              STD_METHOD UpdateLocations, :ptr IOperationsProgressDialog, :ptr IShellItem, :ptr IShellItem, :ptr IShellItem
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, ResetTimer)
              STD_METHOD ResetTimer, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, PauseTimer)
              STD_METHOD PauseTimer, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, ResumeTimer)
              STD_METHOD ResumeTimer, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, GetMilliseconds)
              STD_METHOD GetMilliseconds, :ptr IOperationsProgressDialog, :ptr ULONGLONG, :ptr ULONGLONG
              DECLSPEC_XFGVIRT(IOperationsProgressDialog, GetOperationStatus)
              STD_METHOD GetOperationStatus, :ptr IOperationsProgressDialog, :ptr PDOPSTATUS
              ??Interface equ <>
              END_INTERFACE
            IOperationsProgressDialogVtbl ends
            IOperationsProgressDialog struct
              lpVtbl POINTER ?
            IOperationsProgressDialog ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        ifndef __IIOCancelInformation_INTERFACE_DEFINED__
          __IIOCancelInformation_INTERFACE_DEFINED__ equ <>
          externdef IID_IIOCancelInformation:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IIOCancelInformationVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IIOCancelInformationVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IIOCancelInformation, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IIOCancelInformation
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IIOCancelInformation
              DECLSPEC_XFGVIRT(IIOCancelInformation, SetCancelInformation)
              STD_METHOD SetCancelInformation, :ptr IIOCancelInformation, :DWORD, :UINT
              DECLSPEC_XFGVIRT(IIOCancelInformation, GetCancelInformation)
              STD_METHOD GetCancelInformation, :ptr IIOCancelInformation, :ptr DWORD, :ptr UINT
              ??Interface equ <>
              END_INTERFACE
            IIOCancelInformationVtbl ends
            IIOCancelInformation struct
              lpVtbl POINTER ?
            IIOCancelInformation ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        FOFX_NOSKIPJUNCTIONS equ 00010000h
        FOFX_PREFERHARDLINK equ 00020000h
        FOFX_SHOWELEVATIONPROMPT equ 00040000h
        FOFX_RECYCLEONDELETE equ 00080000h
        FOFX_EARLYFAILURE equ 00100000h
        FOFX_PRESERVEFILEEXTENSIONS equ 00200000h
        FOFX_KEEPNEWERFILE equ 00400000h
        FOFX_NOCOPYHOOKS equ 00800000h
        FOFX_NOMINIMIZEBOX equ 01000000h
        FOFX_MOVEACLSACROSSVOLUMES equ 02000000h
        FOFX_DONTDISPLAYSOURCEPATH equ 04000000h
        FOFX_DONTDISPLAYDESTPATH equ 08000000h
        FOFX_REQUIREELEVATION equ 10000000h
        FOFX_ADDUNDORECORD equ 20000000h
        FOFX_COPYASDOWNLOAD equ 40000000h
        FOFX_DONTDISPLAYLOCATIONS equ 80000000h
        externdef __MIDL_itf_shobjidl_core_0000_0087_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0087_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IFileOperation_INTERFACE_DEFINED__
          __IFileOperation_INTERFACE_DEFINED__ equ <>
          externdef IID_IFileOperation:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IFileOperationVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IFileOperationVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IFileOperation, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IFileOperation
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IFileOperation
              DECLSPEC_XFGVIRT(IFileOperation, Advise)
              STD_METHOD Advise, :ptr IFileOperation, :ptr IFileOperationProgressSink, :ptr DWORD
              DECLSPEC_XFGVIRT(IFileOperation, Unadvise)
              STD_METHOD Unadvise, :ptr IFileOperation, :DWORD
              DECLSPEC_XFGVIRT(IFileOperation, SetOperationFlags)
              STD_METHOD SetOperationFlags, :ptr IFileOperation, :DWORD
              DECLSPEC_XFGVIRT(IFileOperation, SetProgressMessage)
              STD_METHOD SetProgressMessage, :ptr IFileOperation, :LPCWSTR
              DECLSPEC_XFGVIRT(IFileOperation, SetProgressDialog)
              STD_METHOD SetProgressDialog, :ptr IFileOperation, :ptr IOperationsProgressDialog
              DECLSPEC_XFGVIRT(IFileOperation, SetProperties)
              STD_METHOD SetProperties, :ptr IFileOperation, :ptr IPropertyChangeArray
              DECLSPEC_XFGVIRT(IFileOperation, SetOwnerWindow)
              STD_METHOD SetOwnerWindow, :ptr IFileOperation, :HWND
              DECLSPEC_XFGVIRT(IFileOperation, ApplyPropertiesToItem)
              STD_METHOD ApplyPropertiesToItem, :ptr IFileOperation, :ptr IShellItem
              DECLSPEC_XFGVIRT(IFileOperation, ApplyPropertiesToItems)
              STD_METHOD ApplyPropertiesToItems, :ptr IFileOperation, :ptr IUnknown
              DECLSPEC_XFGVIRT(IFileOperation, RenameItem)
              STD_METHOD RenameItem, :ptr IFileOperation, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
              DECLSPEC_XFGVIRT(IFileOperation, RenameItems)
              STD_METHOD RenameItems, :ptr IFileOperation, :ptr IUnknown, :LPCWSTR
              DECLSPEC_XFGVIRT(IFileOperation, MoveItem)
              STD_METHOD MoveItem, :ptr IFileOperation, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
              DECLSPEC_XFGVIRT(IFileOperation, MoveItems)
              STD_METHOD MoveItems, :ptr IFileOperation, :ptr IUnknown, :ptr IShellItem
              DECLSPEC_XFGVIRT(IFileOperation, CopyItem)
              STD_METHOD CopyItem, :ptr IFileOperation, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
              DECLSPEC_XFGVIRT(IFileOperation, CopyItems)
              STD_METHOD CopyItems, :ptr IFileOperation, :ptr IUnknown, :ptr IShellItem
              DECLSPEC_XFGVIRT(IFileOperation, DeleteItem)
              STD_METHOD DeleteItem, :ptr IFileOperation, :ptr IShellItem, :ptr IFileOperationProgressSink
              DECLSPEC_XFGVIRT(IFileOperation, DeleteItems)
              STD_METHOD DeleteItems, :ptr IFileOperation, :ptr IUnknown
              DECLSPEC_XFGVIRT(IFileOperation, NewItem)
              STD_METHOD NewItem, :ptr IFileOperation, :ptr IShellItem, :DWORD, :LPCWSTR, :LPCWSTR, :ptr IFileOperationProgressSink
              DECLSPEC_XFGVIRT(IFileOperation, PerformOperations)
              STD_METHOD PerformOperations, :ptr IFileOperation
              DECLSPEC_XFGVIRT(IFileOperation, GetAnyOperationsAborted)
              STD_METHOD GetAnyOperationsAborted, :ptr IFileOperation, :ptr BOOL
              ??Interface equ <>
              END_INTERFACE
            IFileOperationVtbl ends
            IFileOperation struct
              lpVtbl POINTER ?
            IFileOperation ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
          FILE_OPERATION_FLAGS2 typedef SDWORD
          FOF2_NONE equ 0
          FOF2_MERGEFOLDERSONCOLLISION equ 1h

          DEFINE_ENUM_FLAG_OPERATORS(FILE_OPERATION_FLAGS2)
          externdef __MIDL_itf_shobjidl_core_0000_0088_v0_0_c_ifspec:RPC_IF_HANDLE
          externdef __MIDL_itf_shobjidl_core_0000_0088_v0_0_s_ifspec:RPC_IF_HANDLE
          ifndef __IFileOperation2_INTERFACE_DEFINED__
            __IFileOperation2_INTERFACE_DEFINED__ equ <>
            externdef IID_IFileOperation2:IID
            if Defined(__cplusplus) and  not Defined(CINTERFACE)
              ;[...]
            else
              IFileOperation2Vtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IFileOperation2Vtbl>
                DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
                STD_METHOD QueryInterface, :ptr IFileOperation2, :REFIID, :ptr ptr
                DECLSPEC_XFGVIRT(IUnknown, AddRef)
                STD_METHOD AddRef, :ptr IFileOperation2
                DECLSPEC_XFGVIRT(IUnknown, Release)
                STD_METHOD Release, :ptr IFileOperation2
                DECLSPEC_XFGVIRT(IFileOperation, Advise)
                STD_METHOD Advise, :ptr IFileOperation2, :ptr IFileOperationProgressSink, :ptr DWORD
                DECLSPEC_XFGVIRT(IFileOperation, Unadvise)
                STD_METHOD Unadvise, :ptr IFileOperation2, :DWORD
                DECLSPEC_XFGVIRT(IFileOperation, SetOperationFlags)
                STD_METHOD SetOperationFlags, :ptr IFileOperation2, :DWORD
                DECLSPEC_XFGVIRT(IFileOperation, SetProgressMessage)
                STD_METHOD SetProgressMessage, :ptr IFileOperation2, :LPCWSTR
                DECLSPEC_XFGVIRT(IFileOperation, SetProgressDialog)
                STD_METHOD SetProgressDialog, :ptr IFileOperation2, :ptr IOperationsProgressDialog
                DECLSPEC_XFGVIRT(IFileOperation, SetProperties)
                STD_METHOD SetProperties, :ptr IFileOperation2, :ptr IPropertyChangeArray
                DECLSPEC_XFGVIRT(IFileOperation, SetOwnerWindow)
                STD_METHOD SetOwnerWindow, :ptr IFileOperation2, :HWND
                DECLSPEC_XFGVIRT(IFileOperation, ApplyPropertiesToItem)
                STD_METHOD ApplyPropertiesToItem, :ptr IFileOperation2, :ptr IShellItem
                DECLSPEC_XFGVIRT(IFileOperation, ApplyPropertiesToItems)
                STD_METHOD ApplyPropertiesToItems, :ptr IFileOperation2, :ptr IUnknown
                DECLSPEC_XFGVIRT(IFileOperation, RenameItem)
                STD_METHOD RenameItem, :ptr IFileOperation2, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
                DECLSPEC_XFGVIRT(IFileOperation, RenameItems)
                STD_METHOD RenameItems, :ptr IFileOperation2, :ptr IUnknown, :LPCWSTR
                DECLSPEC_XFGVIRT(IFileOperation, MoveItem)
                STD_METHOD MoveItem, :ptr IFileOperation2, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
                DECLSPEC_XFGVIRT(IFileOperation, MoveItems)
                STD_METHOD MoveItems, :ptr IFileOperation2, :ptr IUnknown, :ptr IShellItem
                DECLSPEC_XFGVIRT(IFileOperation, CopyItem)
                STD_METHOD CopyItem, :ptr IFileOperation2, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
                DECLSPEC_XFGVIRT(IFileOperation, CopyItems)
                STD_METHOD CopyItems, :ptr IFileOperation2, :ptr IUnknown, :ptr IShellItem
                DECLSPEC_XFGVIRT(IFileOperation, DeleteItem)
                STD_METHOD DeleteItem, :ptr IFileOperation2, :ptr IShellItem, :ptr IFileOperationProgressSink
                DECLSPEC_XFGVIRT(IFileOperation, DeleteItems)
                STD_METHOD DeleteItems, :ptr IFileOperation2, :ptr IUnknown
                DECLSPEC_XFGVIRT(IFileOperation, NewItem)
                STD_METHOD NewItem, :ptr IFileOperation2, :ptr IShellItem, :DWORD, :LPCWSTR, :LPCWSTR, :ptr IFileOperationProgressSink
                DECLSPEC_XFGVIRT(IFileOperation, PerformOperations)
                STD_METHOD PerformOperations, :ptr IFileOperation2
                DECLSPEC_XFGVIRT(IFileOperation, GetAnyOperationsAborted)
                STD_METHOD GetAnyOperationsAborted, :ptr IFileOperation2, :ptr BOOL
                DECLSPEC_XFGVIRT(IFileOperation2, SetOperationFlags2)
                STD_METHOD SetOperationFlags2, :ptr IFileOperation2, :FILE_OPERATION_FLAGS2
                ??Interface equ <>
                END_INTERFACE
              IFileOperation2Vtbl ends
              IFileOperation2 struct
                lpVtbl POINTER ?
              IFileOperation2 ends
              ifdef COBJMACROS
                ;[...]
              endif
            endif
          endif
        endif
        externdef __MIDL_itf_shobjidl_core_0000_0089_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0089_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IObjectProvider_INTERFACE_DEFINED__
          __IObjectProvider_INTERFACE_DEFINED__ equ <>
          externdef IID_IObjectProvider:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IObjectProviderVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IObjectProviderVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IObjectProvider, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IObjectProvider
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IObjectProvider
              DECLSPEC_XFGVIRT(IObjectProvider, QueryObject)
              STD_METHOD QueryObject, :ptr IObjectProvider, :REFGUID, :REFIID, :ptr ptr
              ??Interface equ <>
              END_INTERFACE
            IObjectProviderVtbl ends
            IObjectProvider struct
              lpVtbl POINTER ?
            IObjectProvider ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0090_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0090_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __INamespaceWalkCB_INTERFACE_DEFINED__
        __INamespaceWalkCB_INTERFACE_DEFINED__ equ <>
        externdef IID_INamespaceWalkCB:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INamespaceWalkCBVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INamespaceWalkCBVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr INamespaceWalkCB, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr INamespaceWalkCB
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr INamespaceWalkCB
            DECLSPEC_XFGVIRT(INamespaceWalkCB, FoundItem)
            STD_METHOD FoundItem, :ptr INamespaceWalkCB, :ptr IShellFolder, :PCUITEMID_CHILD
            DECLSPEC_XFGVIRT(INamespaceWalkCB, EnterFolder)
            STD_METHOD EnterFolder, :ptr INamespaceWalkCB, :ptr IShellFolder, :PCUITEMID_CHILD
            DECLSPEC_XFGVIRT(INamespaceWalkCB, LeaveFolder)
            STD_METHOD LeaveFolder, :ptr INamespaceWalkCB, :ptr IShellFolder, :PCUITEMID_CHILD
            DECLSPEC_XFGVIRT(INamespaceWalkCB, InitializeProgressDialog)
            STD_METHOD InitializeProgressDialog, :ptr INamespaceWalkCB, :ptr LPWSTR, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          INamespaceWalkCBVtbl ends
          INamespaceWalkCB struct
            lpVtbl POINTER ?
          INamespaceWalkCB ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        externdef __MIDL_itf_shobjidl_core_0000_0091_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0091_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __INamespaceWalkCB2_INTERFACE_DEFINED__
          __INamespaceWalkCB2_INTERFACE_DEFINED__ equ <>
          externdef IID_INamespaceWalkCB2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            INamespaceWalkCB2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <INamespaceWalkCB2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr INamespaceWalkCB2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr INamespaceWalkCB2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr INamespaceWalkCB2
              DECLSPEC_XFGVIRT(INamespaceWalkCB, FoundItem)
              STD_METHOD FoundItem, :ptr INamespaceWalkCB2, :ptr IShellFolder, :PCUITEMID_CHILD
              DECLSPEC_XFGVIRT(INamespaceWalkCB, EnterFolder)
              STD_METHOD EnterFolder, :ptr INamespaceWalkCB2, :ptr IShellFolder, :PCUITEMID_CHILD
              DECLSPEC_XFGVIRT(INamespaceWalkCB, LeaveFolder)
              STD_METHOD LeaveFolder, :ptr INamespaceWalkCB2, :ptr IShellFolder, :PCUITEMID_CHILD
              DECLSPEC_XFGVIRT(INamespaceWalkCB, InitializeProgressDialog)
              STD_METHOD InitializeProgressDialog, :ptr INamespaceWalkCB2, :ptr LPWSTR, :ptr LPWSTR
              DECLSPEC_XFGVIRT(INamespaceWalkCB2, WalkComplete)
              STD_METHOD WalkComplete, :ptr INamespaceWalkCB2, :HRESULT
              ??Interface equ <>
              END_INTERFACE
            INamespaceWalkCB2Vtbl ends
            INamespaceWalkCB2 struct
              lpVtbl POINTER ?
            INamespaceWalkCB2 ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0092_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0092_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __INamespaceWalk_INTERFACE_DEFINED__
        __INamespaceWalk_INTERFACE_DEFINED__ equ <>
        NAMESPACEWALKFLAG typedef SDWORD
        NSWF_DEFAULT equ 0
        NSWF_NONE_IMPLIES_ALL equ 1h
        NSWF_ONE_IMPLIES_ALL equ 2h
        NSWF_DONT_TRAVERSE_LINKS equ 4h
        NSWF_DONT_ACCUMULATE_RESULT equ 8h
        NSWF_TRAVERSE_STREAM_JUNCTIONS equ 10h
        NSWF_FILESYSTEM_ONLY equ 20h
        NSWF_SHOW_PROGRESS equ 40h
        NSWF_FLAG_VIEWORDER equ 80h
        NSWF_IGNORE_AUTOPLAY_HIDA equ 100h
        NSWF_ASYNC equ 200h
        NSWF_DONT_RESOLVE_LINKS equ 400h
        NSWF_ACCUMULATE_FOLDERS equ 800h
        NSWF_DONT_SORT equ 1000h
        NSWF_USE_TRANSFER_MEDIUM equ 2000h
        NSWF_DONT_TRAVERSE_STREAM_JUNCTIONS equ 4000h
        NSWF_ANY_IMPLIES_ALL equ 8000h

        DEFINE_ENUM_FLAG_OPERATORS(NAMESPACEWALKFLAG)
        externdef IID_INamespaceWalk:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INamespaceWalkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INamespaceWalkVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr INamespaceWalk, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr INamespaceWalk
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr INamespaceWalk
            DECLSPEC_XFGVIRT(INamespaceWalk, Walk)
            STD_METHOD Walk, :ptr INamespaceWalk, :ptr IUnknown, :DWORD, :SDWORD, :ptr INamespaceWalkCB
            DECLSPEC_XFGVIRT(INamespaceWalk, GetIDArrayResult)
            STD_METHOD GetIDArrayResult, :ptr INamespaceWalk, :ptr UINT, :ptr ptr PIDLIST_ABSOLUTE
            ??Interface equ <>
            END_INTERFACE
          INamespaceWalkVtbl ends
          INamespaceWalk struct
            lpVtbl POINTER ?
          INamespaceWalk ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    FreeIDListArray proto WIN_STD_CALL_CONV :ptr PIDLIST_RELATIVE, :UINT
    if Defined(STRICT_TYPED_ITEMIDS) and Defined(__cplusplus)
      ;[...]
    else
      FreeIDListArrayFull equ <FreeIDListArray>
      FreeIDListArrayChild equ <FreeIDListArray>
    endif
    include pshpack8.inc
    BANDSITEINFO struct
      dwMask DWORD ?
      dwState DWORD ?
      dwStyle DWORD ?
    BANDSITEINFO ends
    tagBANDSITEINFO typedef BANDSITEINFO
    include poppack.inc
    tagBANDSITECID typedef SDWORD
    BSID_BANDADDED equ 0
    BSID_BANDREMOVED equ

    BSIM_STATE equ 00000001h
    BSIM_STYLE equ 00000002h
    BSSF_VISIBLE equ 00000001h
    BSSF_NOTITLE equ 00000002h
    BSSF_UNDELETEABLE equ 00001000h
    BSIS_AUTOGRIPPER equ 00000000h
    BSIS_NOGRIPPER equ 00000001h
    BSIS_ALWAYSGRIPPER equ 00000002h
    BSIS_LEFTALIGN equ 00000004h
    BSIS_SINGLECLICK equ 00000008h
    BSIS_NOCONTEXTMENU equ 00000010h
    BSIS_NODROPTARGET equ 00000020h
    BSIS_NOCAPTION equ 00000040h
    BSIS_PREFERNOLINEBREAK equ 00000080h
    BSIS_LOCKED equ 00000100h
    if (_WIN32_IE ge _WIN32_IE_IE70)
      BSIS_PRESERVEORDERDURINGLAYOUT equ 00000200h
      BSIS_FIXEDORDER equ 00000400h
    endif
    SID_SBandSite equ <IID_IBandSite>
    CGID_BandSite equ <IID_IBandSite>
    externdef __MIDL_itf_shobjidl_core_0000_0093_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0093_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IBandSite_INTERFACE_DEFINED__
      __IBandSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IBandSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IBandSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IBandSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IBandSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IBandSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IBandSite
          DECLSPEC_XFGVIRT(IBandSite, AddBand)
          STD_METHOD AddBand, :ptr IBandSite, :ptr IUnknown
          DECLSPEC_XFGVIRT(IBandSite, EnumBands)
          STD_METHOD EnumBands, :ptr IBandSite, :UINT, :ptr DWORD
          DECLSPEC_XFGVIRT(IBandSite, QueryBand)
          STD_METHOD QueryBand, :ptr IBandSite, :DWORD, :ptr ptr IDeskBand, :ptr DWORD, :LPWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IBandSite, SetBandState)
          STD_METHOD SetBandState, :ptr IBandSite, :DWORD, :DWORD, :DWORD
          DECLSPEC_XFGVIRT(IBandSite, RemoveBand)
          STD_METHOD RemoveBand, :ptr IBandSite, :DWORD
          DECLSPEC_XFGVIRT(IBandSite, GetBandObject)
          STD_METHOD GetBandObject, :ptr IBandSite, :DWORD, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IBandSite, SetBandSiteInfo)
          STD_METHOD SetBandSiteInfo, :ptr IBandSite, :ptr BANDSITEINFO
          DECLSPEC_XFGVIRT(IBandSite, GetBandSiteInfo)
          STD_METHOD GetBandSiteInfo, :ptr IBandSite, :ptr BANDSITEINFO
          ??Interface equ <>
          END_INTERFACE
        IBandSiteVtbl ends
        IBandSite struct
          lpVtbl POINTER ?
        IBandSite ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IBandSite_RemoteQueryBand_Proxy proto WIN_STD_CALL_CONV :ptr IBandSite, :DWORD, :ptr ptr IDeskBand, :ptr DWORD, :LPWSTR, :SDWORD
      IBandSite_RemoteQueryBand_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      externdef __MIDL_itf_shobjidl_core_0000_0094_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0094_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IModalWindow_INTERFACE_DEFINED__
        __IModalWindow_INTERFACE_DEFINED__ equ <>
        externdef IID_IModalWindow:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IModalWindowVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IModalWindowVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IModalWindow, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IModalWindow
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IModalWindow
            DECLSPEC_XFGVIRT(IModalWindow, Show)
            STD_METHOD Show, :ptr IModalWindow, :HWND
            ??Interface equ <>
            END_INTERFACE
          IModalWindowVtbl ends
          IModalWindow struct
            lpVtbl POINTER ?
          IModalWindow ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IModalWindow_RemoteShow_Proxy proto WIN_STD_CALL_CONV :ptr IModalWindow, :HWND
        IModalWindow_RemoteShow_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0095_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0095_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IContextMenuSite_INTERFACE_DEFINED__
      __IContextMenuSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IContextMenuSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IContextMenuSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IContextMenuSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IContextMenuSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IContextMenuSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IContextMenuSite
          DECLSPEC_XFGVIRT(IContextMenuSite, DoContextMenuPopup)
          STD_METHOD DoContextMenuPopup, :ptr IContextMenuSite, :ptr IUnknown, :UINT, :POINT
          ??Interface equ <>
          END_INTERFACE
        IContextMenuSiteVtbl ends
        IContextMenuSite struct
          lpVtbl POINTER ?
        IContextMenuSite ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP) or (_WIN32_IE ge _WIN32_IE_IE70)
      if (NTDDI_VERSION ge NTDDI_WINXP)
        externdef __MIDL_itf_shobjidl_core_0000_0096_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0096_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IMenuBand_INTERFACE_DEFINED__
          __IMenuBand_INTERFACE_DEFINED__ equ <>
          tagMENUBANDHANDLERCID typedef SDWORD
          MBHANDCID_PIDLSELECT equ 0

          externdef IID_IMenuBand:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IMenuBandVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IMenuBandVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IMenuBand, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IMenuBand
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IMenuBand
              DECLSPEC_XFGVIRT(IMenuBand, IsMenuMessage)
              STD_METHOD IsMenuMessage, :ptr IMenuBand, :ptr MSG
              DECLSPEC_XFGVIRT(IMenuBand, TranslateMenuMessage)
              STD_METHOD TranslateMenuMessage, :ptr IMenuBand, :ptr MSG, :ptr LRESULT
              ??Interface equ <>
              END_INTERFACE
            IMenuBandVtbl ends
            IMenuBand struct
              lpVtbl POINTER ?
            IMenuBand ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        ifndef __IRegTreeItem_INTERFACE_DEFINED__
          __IRegTreeItem_INTERFACE_DEFINED__ equ <>
          externdef IID_IRegTreeItem:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IRegTreeItemVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IRegTreeItemVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IRegTreeItem, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IRegTreeItem
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IRegTreeItem
              DECLSPEC_XFGVIRT(IRegTreeItem, GetCheckState)
              STD_METHOD GetCheckState, :ptr IRegTreeItem, :ptr BOOL
              DECLSPEC_XFGVIRT(IRegTreeItem, SetCheckState)
              STD_METHOD SetCheckState, :ptr IRegTreeItem, :BOOL
              ??Interface equ <>
              END_INTERFACE
            IRegTreeItemVtbl ends
            IRegTreeItem struct
              lpVtbl POINTER ?
            IRegTreeItem ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60)
      externdef __MIDL_itf_shobjidl_core_0000_0098_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0098_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDeskBar_INTERFACE_DEFINED__
        __IDeskBar_INTERFACE_DEFINED__ equ <>
        externdef IID_IDeskBar:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDeskBarVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDeskBarVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDeskBar, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDeskBar
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDeskBar
            DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
            STD_METHOD GetWindow, :ptr IDeskBar, :ptr HWND
            DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
            STD_METHOD ContextSensitiveHelp, :ptr IDeskBar, :BOOL
            DECLSPEC_XFGVIRT(IDeskBar, SetClient)
            STD_METHOD SetClient, :ptr IDeskBar, :ptr IUnknown
            DECLSPEC_XFGVIRT(IDeskBar, GetClient)
            STD_METHOD GetClient, :ptr IDeskBar, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IDeskBar, OnPosRectChangeDB)
            STD_METHOD OnPosRectChangeDB, :ptr IDeskBar, :ptr RECT
            ??Interface equ <>
            END_INTERFACE
          IDeskBarVtbl ends
          IDeskBar struct
            lpVtbl POINTER ?
          IDeskBar ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IMenuPopup_INTERFACE_DEFINED__
        __IMenuPopup_INTERFACE_DEFINED__ equ <>
        tagMENUPOPUPSELECT typedef SDWORD
        MPOS_EXECUTE equ 0
        MPOS_FULLCANCEL equ
        MPOS_CANCELLEVEL equ
        MPOS_SELECTLEFT equ
        MPOS_SELECTRIGHT equ
        MPOS_CHILDTRACKING equ

        tagMENUPOPUPPOPUPFLAGS typedef SDWORD
        MPPF_SETFOCUS equ 1h
        MPPF_INITIALSELECT equ 2h
        MPPF_NOANIMATE equ 4h
        MPPF_KEYBOARD equ 10h
        MPPF_REPOSITION equ 20h
        MPPF_FORCEZORDER equ 40h
        MPPF_FINALSELECT equ 80h
        MPPF_TOP equ 20000000h
        MPPF_LEFT equ 40000000h
        MPPF_RIGHT equ 60000000h
        MPPF_BOTTOM equ 80000000h
        MPPF_POS_MASK equ 0e0000000h
        MPPF_ALIGN_LEFT equ 2000000h
        MPPF_ALIGN_RIGHT equ 4000000h

        MP_POPUPFLAGS typedef SDWORD
        externdef IID_IMenuPopup:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMenuPopupVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMenuPopupVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMenuPopup, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMenuPopup
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMenuPopup
            DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
            STD_METHOD GetWindow, :ptr IMenuPopup, :ptr HWND
            DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
            STD_METHOD ContextSensitiveHelp, :ptr IMenuPopup, :BOOL
            DECLSPEC_XFGVIRT(IDeskBar, SetClient)
            STD_METHOD SetClient, :ptr IMenuPopup, :ptr IUnknown
            DECLSPEC_XFGVIRT(IDeskBar, GetClient)
            STD_METHOD GetClient, :ptr IMenuPopup, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IDeskBar, OnPosRectChangeDB)
            STD_METHOD OnPosRectChangeDB, :ptr IMenuPopup, :ptr RECT
            DECLSPEC_XFGVIRT(IMenuPopup, Popup)
            STD_METHOD Popup, :ptr IMenuPopup, :ptr POINTL, :ptr RECTL, :MP_POPUPFLAGS
            DECLSPEC_XFGVIRT(IMenuPopup, OnSelect)
            STD_METHOD OnSelect, :ptr IMenuPopup, :DWORD
            DECLSPEC_XFGVIRT(IMenuPopup, SetSubMenu)
            STD_METHOD SetSubMenu, :ptr IMenuPopup, :ptr IMenuPopup, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IMenuPopupVtbl ends
          IMenuPopup struct
            lpVtbl POINTER ?
          IMenuPopup ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      FILE_USAGE_TYPE typedef SDWORD
      FUT_PLAYING equ 0
      FUT_EDITING equ
      FUT_GENERIC equ

      OF_CAP_CANSWITCHTO equ 0001h
      OF_CAP_CANCLOSE equ 0002h
      externdef __MIDL_itf_shobjidl_core_0000_0100_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0100_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileIsInUse_INTERFACE_DEFINED__
        __IFileIsInUse_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileIsInUse:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileIsInUseVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileIsInUseVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileIsInUse, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileIsInUse
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileIsInUse
            DECLSPEC_XFGVIRT(IFileIsInUse, GetAppName)
            STD_METHOD GetAppName, :ptr IFileIsInUse, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IFileIsInUse, GetUsage)
            STD_METHOD GetUsage, :ptr IFileIsInUse, :ptr FILE_USAGE_TYPE
            DECLSPEC_XFGVIRT(IFileIsInUse, GetCapabilities)
            STD_METHOD GetCapabilities, :ptr IFileIsInUse, :ptr DWORD
            DECLSPEC_XFGVIRT(IFileIsInUse, GetSwitchToHWND)
            STD_METHOD GetSwitchToHWND, :ptr IFileIsInUse, :ptr HWND
            DECLSPEC_XFGVIRT(IFileIsInUse, CloseFile)
            STD_METHOD CloseFile, :ptr IFileIsInUse
            ??Interface equ <>
            END_INTERFACE
          IFileIsInUseVtbl ends
          IFileIsInUse struct
            lpVtbl POINTER ?
          IFileIsInUse ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      FDE_OVERWRITE_RESPONSE typedef SDWORD
      FDEOR_DEFAULT equ 0
      FDEOR_ACCEPT equ 1
      FDEOR_REFUSE equ 2

      FDE_SHAREVIOLATION_RESPONSE typedef SDWORD
      FDESVR_DEFAULT equ 0
      FDESVR_ACCEPT equ 1
      FDESVR_REFUSE equ 2

      FDAP typedef SDWORD
      FDAP_BOTTOM equ 0
      FDAP_TOP equ 1

      externdef __MIDL_itf_shobjidl_core_0000_0101_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0101_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialogEvents_INTERFACE_DEFINED__
        __IFileDialogEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileDialogEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileDialogEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileDialogEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileDialogEvents
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnFileOk)
            STD_METHOD OnFileOk, :ptr IFileDialogEvents, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnFolderChanging)
            STD_METHOD OnFolderChanging, :ptr IFileDialogEvents, :ptr IFileDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnFolderChange)
            STD_METHOD OnFolderChange, :ptr IFileDialogEvents, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnSelectionChange)
            STD_METHOD OnSelectionChange, :ptr IFileDialogEvents, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnShareViolation)
            STD_METHOD OnShareViolation, :ptr IFileDialogEvents, :ptr IFileDialog, :ptr IShellItem, :ptr FDE_SHAREVIOLATION_RESPONSE
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnTypeChange)
            STD_METHOD OnTypeChange, :ptr IFileDialogEvents, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IFileDialogEvents, OnOverwrite)
            STD_METHOD OnOverwrite, :ptr IFileDialogEvents, :ptr IFileDialog, :ptr IShellItem, :ptr FDE_OVERWRITE_RESPONSE
            ??Interface equ <>
            END_INTERFACE
          IFileDialogEventsVtbl ends
          IFileDialogEvents struct
            lpVtbl POINTER ?
          IFileDialogEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0102_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0102_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialog_INTERFACE_DEFINED__
        __IFileDialog_INTERFACE_DEFINED__ equ <>
        _FILEOPENDIALOGOPTIONS typedef SDWORD
        FOS_OVERWRITEPROMPT equ 2h
        FOS_STRICTFILETYPES equ 4h
        FOS_NOCHANGEDIR equ 8h
        FOS_PICKFOLDERS equ 20h
        FOS_FORCEFILESYSTEM equ 40h
        FOS_ALLNONSTORAGEITEMS equ 80h
        FOS_NOVALIDATE equ 100h
        FOS_ALLOWMULTISELECT equ 200h
        FOS_PATHMUSTEXIST equ 800h
        FOS_FILEMUSTEXIST equ 1000h
        FOS_CREATEPROMPT equ 2000h
        FOS_SHAREAWARE equ 4000h
        FOS_NOREADONLYRETURN equ 8000h
        FOS_NOTESTFILECREATE equ 10000h
        FOS_HIDEMRUPLACES equ 20000h
        FOS_HIDEPINNEDPLACES equ 40000h
        FOS_NODEREFERENCELINKS equ 100000h
        FOS_OKBUTTONNEEDSINTERACTION equ 200000h
        FOS_DONTADDTORECENT equ 2000000h
        FOS_FORCESHOWHIDDEN equ 10000000h
        FOS_DEFAULTNOMINIMODE equ 20000000h
        FOS_FORCEPREVIEWPANEON equ 40000000h
        FOS_SUPPORTSTREAMABLEITEMS equ 80000000h

        FILEOPENDIALOGOPTIONS typedef DWORD
        externdef IID_IFileDialog:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileDialog, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IModalWindow, Show)
            STD_METHOD Show, :ptr IFileDialog, :HWND
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypes)
            STD_METHOD SetFileTypes, :ptr IFileDialog, :UINT, :ptr COMDLG_FILTERSPEC
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypeIndex)
            STD_METHOD SetFileTypeIndex, :ptr IFileDialog, :UINT
            DECLSPEC_XFGVIRT(IFileDialog, GetFileTypeIndex)
            STD_METHOD GetFileTypeIndex, :ptr IFileDialog, :ptr UINT
            DECLSPEC_XFGVIRT(IFileDialog, Advise)
            STD_METHOD Advise, :ptr IFileDialog, :ptr IFileDialogEvents, :ptr DWORD
            DECLSPEC_XFGVIRT(IFileDialog, Unadvise)
            STD_METHOD Unadvise, :ptr IFileDialog, :DWORD
            DECLSPEC_XFGVIRT(IFileDialog, SetOptions)
            STD_METHOD SetOptions, :ptr IFileDialog, :FILEOPENDIALOGOPTIONS
            DECLSPEC_XFGVIRT(IFileDialog, GetOptions)
            STD_METHOD GetOptions, :ptr IFileDialog, :ptr FILEOPENDIALOGOPTIONS
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultFolder)
            STD_METHOD SetDefaultFolder, :ptr IFileDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, SetFolder)
            STD_METHOD SetFolder, :ptr IFileDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, GetFolder)
            STD_METHOD GetFolder, :ptr IFileDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, GetCurrentSelection)
            STD_METHOD GetCurrentSelection, :ptr IFileDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, SetFileName)
            STD_METHOD SetFileName, :ptr IFileDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, GetFileName)
            STD_METHOD GetFileName, :ptr IFileDialog, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetTitle)
            STD_METHOD SetTitle, :ptr IFileDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetOkButtonLabel)
            STD_METHOD SetOkButtonLabel, :ptr IFileDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetFileNameLabel)
            STD_METHOD SetFileNameLabel, :ptr IFileDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, GetResult)
            STD_METHOD GetResult, :ptr IFileDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, AddPlace)
            STD_METHOD AddPlace, :ptr IFileDialog, :ptr IShellItem, :FDAP
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultExtension)
            STD_METHOD SetDefaultExtension, :ptr IFileDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, Close)
            STD_METHOD Close, :ptr IFileDialog, :HRESULT
            DECLSPEC_XFGVIRT(IFileDialog, SetClientGuid)
            STD_METHOD SetClientGuid, :ptr IFileDialog, :REFGUID
            DECLSPEC_XFGVIRT(IFileDialog, ClearClientData)
            STD_METHOD ClearClientData, :ptr IFileDialog
            DECLSPEC_XFGVIRT(IFileDialog, SetFilter)
            STD_METHOD SetFilter, :ptr IFileDialog, :ptr IShellItemFilter
            ??Interface equ <>
            END_INTERFACE
          IFileDialogVtbl ends
          IFileDialog struct
            lpVtbl POINTER ?
          IFileDialog ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IFileSaveDialog_INTERFACE_DEFINED__
        __IFileSaveDialog_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileSaveDialog:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileSaveDialogVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileSaveDialogVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileSaveDialog, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileSaveDialog
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileSaveDialog
            DECLSPEC_XFGVIRT(IModalWindow, Show)
            STD_METHOD Show, :ptr IFileSaveDialog, :HWND
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypes)
            STD_METHOD SetFileTypes, :ptr IFileSaveDialog, :UINT, :ptr COMDLG_FILTERSPEC
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypeIndex)
            STD_METHOD SetFileTypeIndex, :ptr IFileSaveDialog, :UINT
            DECLSPEC_XFGVIRT(IFileDialog, GetFileTypeIndex)
            STD_METHOD GetFileTypeIndex, :ptr IFileSaveDialog, :ptr UINT
            DECLSPEC_XFGVIRT(IFileDialog, Advise)
            STD_METHOD Advise, :ptr IFileSaveDialog, :ptr IFileDialogEvents, :ptr DWORD
            DECLSPEC_XFGVIRT(IFileDialog, Unadvise)
            STD_METHOD Unadvise, :ptr IFileSaveDialog, :DWORD
            DECLSPEC_XFGVIRT(IFileDialog, SetOptions)
            STD_METHOD SetOptions, :ptr IFileSaveDialog, :FILEOPENDIALOGOPTIONS
            DECLSPEC_XFGVIRT(IFileDialog, GetOptions)
            STD_METHOD GetOptions, :ptr IFileSaveDialog, :ptr FILEOPENDIALOGOPTIONS
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultFolder)
            STD_METHOD SetDefaultFolder, :ptr IFileSaveDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, SetFolder)
            STD_METHOD SetFolder, :ptr IFileSaveDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, GetFolder)
            STD_METHOD GetFolder, :ptr IFileSaveDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, GetCurrentSelection)
            STD_METHOD GetCurrentSelection, :ptr IFileSaveDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, SetFileName)
            STD_METHOD SetFileName, :ptr IFileSaveDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, GetFileName)
            STD_METHOD GetFileName, :ptr IFileSaveDialog, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetTitle)
            STD_METHOD SetTitle, :ptr IFileSaveDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetOkButtonLabel)
            STD_METHOD SetOkButtonLabel, :ptr IFileSaveDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetFileNameLabel)
            STD_METHOD SetFileNameLabel, :ptr IFileSaveDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, GetResult)
            STD_METHOD GetResult, :ptr IFileSaveDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, AddPlace)
            STD_METHOD AddPlace, :ptr IFileSaveDialog, :ptr IShellItem, :FDAP
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultExtension)
            STD_METHOD SetDefaultExtension, :ptr IFileSaveDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, Close)
            STD_METHOD Close, :ptr IFileSaveDialog, :HRESULT
            DECLSPEC_XFGVIRT(IFileDialog, SetClientGuid)
            STD_METHOD SetClientGuid, :ptr IFileSaveDialog, :REFGUID
            DECLSPEC_XFGVIRT(IFileDialog, ClearClientData)
            STD_METHOD ClearClientData, :ptr IFileSaveDialog
            DECLSPEC_XFGVIRT(IFileDialog, SetFilter)
            STD_METHOD SetFilter, :ptr IFileSaveDialog, :ptr IShellItemFilter
            DECLSPEC_XFGVIRT(IFileSaveDialog, SetSaveAsItem)
            STD_METHOD SetSaveAsItem, :ptr IFileSaveDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileSaveDialog, SetProperties)
            STD_METHOD SetProperties, :ptr IFileSaveDialog, :ptr IPropertyStore
            DECLSPEC_XFGVIRT(IFileSaveDialog, SetCollectedProperties)
            STD_METHOD SetCollectedProperties, :ptr IFileSaveDialog, :ptr IPropertyDescriptionList, :BOOL
            DECLSPEC_XFGVIRT(IFileSaveDialog, GetProperties)
            STD_METHOD GetProperties, :ptr IFileSaveDialog, :ptr ptr IPropertyStore
            DECLSPEC_XFGVIRT(IFileSaveDialog, ApplyProperties)
            STD_METHOD ApplyProperties, :ptr IFileSaveDialog, :ptr IShellItem, :ptr IPropertyStore, :HWND, :ptr IFileOperationProgressSink
            ??Interface equ <>
            END_INTERFACE
          IFileSaveDialogVtbl ends
          IFileSaveDialog struct
            lpVtbl POINTER ?
          IFileSaveDialog ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IFileOpenDialog_INTERFACE_DEFINED__
        __IFileOpenDialog_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileOpenDialog:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileOpenDialogVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileOpenDialogVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileOpenDialog, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileOpenDialog
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileOpenDialog
            DECLSPEC_XFGVIRT(IModalWindow, Show)
            STD_METHOD Show, :ptr IFileOpenDialog, :HWND
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypes)
            STD_METHOD SetFileTypes, :ptr IFileOpenDialog, :UINT, :ptr COMDLG_FILTERSPEC
            DECLSPEC_XFGVIRT(IFileDialog, SetFileTypeIndex)
            STD_METHOD SetFileTypeIndex, :ptr IFileOpenDialog, :UINT
            DECLSPEC_XFGVIRT(IFileDialog, GetFileTypeIndex)
            STD_METHOD GetFileTypeIndex, :ptr IFileOpenDialog, :ptr UINT
            DECLSPEC_XFGVIRT(IFileDialog, Advise)
            STD_METHOD Advise, :ptr IFileOpenDialog, :ptr IFileDialogEvents, :ptr DWORD
            DECLSPEC_XFGVIRT(IFileDialog, Unadvise)
            STD_METHOD Unadvise, :ptr IFileOpenDialog, :DWORD
            DECLSPEC_XFGVIRT(IFileDialog, SetOptions)
            STD_METHOD SetOptions, :ptr IFileOpenDialog, :FILEOPENDIALOGOPTIONS
            DECLSPEC_XFGVIRT(IFileDialog, GetOptions)
            STD_METHOD GetOptions, :ptr IFileOpenDialog, :ptr FILEOPENDIALOGOPTIONS
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultFolder)
            STD_METHOD SetDefaultFolder, :ptr IFileOpenDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, SetFolder)
            STD_METHOD SetFolder, :ptr IFileOpenDialog, :ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, GetFolder)
            STD_METHOD GetFolder, :ptr IFileOpenDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, GetCurrentSelection)
            STD_METHOD GetCurrentSelection, :ptr IFileOpenDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, SetFileName)
            STD_METHOD SetFileName, :ptr IFileOpenDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, GetFileName)
            STD_METHOD GetFileName, :ptr IFileOpenDialog, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetTitle)
            STD_METHOD SetTitle, :ptr IFileOpenDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetOkButtonLabel)
            STD_METHOD SetOkButtonLabel, :ptr IFileOpenDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, SetFileNameLabel)
            STD_METHOD SetFileNameLabel, :ptr IFileOpenDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, GetResult)
            STD_METHOD GetResult, :ptr IFileOpenDialog, :ptr ptr IShellItem
            DECLSPEC_XFGVIRT(IFileDialog, AddPlace)
            STD_METHOD AddPlace, :ptr IFileOpenDialog, :ptr IShellItem, :FDAP
            DECLSPEC_XFGVIRT(IFileDialog, SetDefaultExtension)
            STD_METHOD SetDefaultExtension, :ptr IFileOpenDialog, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialog, Close)
            STD_METHOD Close, :ptr IFileOpenDialog, :HRESULT
            DECLSPEC_XFGVIRT(IFileDialog, SetClientGuid)
            STD_METHOD SetClientGuid, :ptr IFileOpenDialog, :REFGUID
            DECLSPEC_XFGVIRT(IFileDialog, ClearClientData)
            STD_METHOD ClearClientData, :ptr IFileOpenDialog
            DECLSPEC_XFGVIRT(IFileDialog, SetFilter)
            STD_METHOD SetFilter, :ptr IFileOpenDialog, :ptr IShellItemFilter
            DECLSPEC_XFGVIRT(IFileOpenDialog, GetResults)
            STD_METHOD GetResults, :ptr IFileOpenDialog, :ptr ptr IShellItemArray
            DECLSPEC_XFGVIRT(IFileOpenDialog, GetSelectedItems)
            STD_METHOD GetSelectedItems, :ptr IFileOpenDialog, :ptr ptr IShellItemArray
            ??Interface equ <>
            END_INTERFACE
          IFileOpenDialogVtbl ends
          IFileOpenDialog struct
            lpVtbl POINTER ?
          IFileOpenDialog ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      CDCONTROLSTATEF typedef SDWORD
      CDCS_INACTIVE equ 0
      CDCS_ENABLED equ 1h
      CDCS_VISIBLE equ 2h
      CDCS_ENABLEDVISIBLE equ 3h

      DEFINE_ENUM_FLAG_OPERATORS(CDCONTROLSTATEF)
      externdef __MIDL_itf_shobjidl_core_0000_0105_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0105_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialogCustomize_INTERFACE_DEFINED__
        __IFileDialogCustomize_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileDialogCustomize:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogCustomizeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogCustomizeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFileDialogCustomize, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileDialogCustomize
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileDialogCustomize
            DECLSPEC_XFGVIRT(IFileDialogCustomize, EnableOpenDropDown)
            STD_METHOD EnableOpenDropDown, :ptr IFileDialogCustomize, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddMenu)
            STD_METHOD AddMenu, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddPushButton)
            STD_METHOD AddPushButton, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddComboBox)
            STD_METHOD AddComboBox, :ptr IFileDialogCustomize, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddRadioButtonList)
            STD_METHOD AddRadioButtonList, :ptr IFileDialogCustomize, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddCheckButton)
            STD_METHOD AddCheckButton, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR, :BOOL
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddEditBox)
            STD_METHOD AddEditBox, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddSeparator)
            STD_METHOD AddSeparator, :ptr IFileDialogCustomize, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddText)
            STD_METHOD AddText, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetControlLabel)
            STD_METHOD SetControlLabel, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, GetControlState)
            STD_METHOD GetControlState, :ptr IFileDialogCustomize, :DWORD, :ptr CDCONTROLSTATEF
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetControlState)
            STD_METHOD SetControlState, :ptr IFileDialogCustomize, :DWORD, :CDCONTROLSTATEF
            DECLSPEC_XFGVIRT(IFileDialogCustomize, GetEditBoxText)
            STD_METHOD GetEditBoxText, :ptr IFileDialogCustomize, :DWORD, :ptr ptr WCHAR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetEditBoxText)
            STD_METHOD SetEditBoxText, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, GetCheckButtonState)
            STD_METHOD GetCheckButtonState, :ptr IFileDialogCustomize, :DWORD, :ptr BOOL
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetCheckButtonState)
            STD_METHOD SetCheckButtonState, :ptr IFileDialogCustomize, :DWORD, :BOOL
            DECLSPEC_XFGVIRT(IFileDialogCustomize, AddControlItem)
            STD_METHOD AddControlItem, :ptr IFileDialogCustomize, :DWORD, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, RemoveControlItem)
            STD_METHOD RemoveControlItem, :ptr IFileDialogCustomize, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, RemoveAllControlItems)
            STD_METHOD RemoveAllControlItems, :ptr IFileDialogCustomize, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, GetControlItemState)
            STD_METHOD GetControlItemState, :ptr IFileDialogCustomize, :DWORD, :DWORD, :ptr CDCONTROLSTATEF
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetControlItemState)
            STD_METHOD SetControlItemState, :ptr IFileDialogCustomize, :DWORD, :DWORD, :CDCONTROLSTATEF
            DECLSPEC_XFGVIRT(IFileDialogCustomize, GetSelectedControlItem)
            STD_METHOD GetSelectedControlItem, :ptr IFileDialogCustomize, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetSelectedControlItem)
            STD_METHOD SetSelectedControlItem, :ptr IFileDialogCustomize, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, StartVisualGroup)
            STD_METHOD StartVisualGroup, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IFileDialogCustomize, EndVisualGroup)
            STD_METHOD EndVisualGroup, :ptr IFileDialogCustomize
            DECLSPEC_XFGVIRT(IFileDialogCustomize, MakeProminent)
            STD_METHOD MakeProminent, :ptr IFileDialogCustomize, :DWORD
            DECLSPEC_XFGVIRT(IFileDialogCustomize, SetControlItemText)
            STD_METHOD SetControlItemText, :ptr IFileDialogCustomize, :DWORD, :DWORD, :LPCWSTR
            ??Interface equ <>
            END_INTERFACE
          IFileDialogCustomizeVtbl ends
          IFileDialogCustomize struct
            lpVtbl POINTER ?
          IFileDialogCustomize ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ASSOCIATIONLEVEL typedef SDWORD
      AL_MACHINE equ 0
      AL_EFFECTIVE equ
      AL_USER equ

      ASSOCIATIONTYPE typedef SDWORD
      AT_FILEEXTENSION equ 0
      AT_URLPROTOCOL equ
      AT_STARTMENUCLIENT equ
      AT_MIMETYPE equ

      externdef __MIDL_itf_shobjidl_core_0000_0106_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0106_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IApplicationAssociationRegistration_INTERFACE_DEFINED__
        __IApplicationAssociationRegistration_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationAssociationRegistration:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationAssociationRegistrationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationAssociationRegistrationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationAssociationRegistration, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationAssociationRegistration
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationAssociationRegistration
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistration, QueryCurrentDefault)
            STD_METHOD QueryCurrentDefault, :ptr IApplicationAssociationRegistration, :LPCWSTR, :ASSOCIATIONTYPE, :ASSOCIATIONLEVEL, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistration, QueryAppIsDefault)
            STD_METHOD QueryAppIsDefault, :ptr IApplicationAssociationRegistration, :LPCWSTR, :ASSOCIATIONTYPE, :ASSOCIATIONLEVEL, :LPCWSTR, :ptr BOOL
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistration, QueryAppIsDefaultAll)
            STD_METHOD QueryAppIsDefaultAll, :ptr IApplicationAssociationRegistration, :ASSOCIATIONLEVEL, :LPCWSTR, :ptr BOOL
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistration, SetAppAsDefault)
            STD_METHOD SetAppAsDefault, :ptr IApplicationAssociationRegistration, :LPCWSTR, :LPCWSTR, :ASSOCIATIONTYPE
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistration, SetAppAsDefaultAll)
            STD_METHOD SetAppAsDefaultAll, :ptr IApplicationAssociationRegistration, :LPCWSTR
            DECLSPEC_XFGVIRT(IApplicationAssociationRegistration, ClearUserAssociations)
            STD_METHOD ClearUserAssociations, :ptr IApplicationAssociationRegistration
            ??Interface equ <>
            END_INTERFACE
          IApplicationAssociationRegistrationVtbl ends
          IApplicationAssociationRegistration struct
            lpVtbl POINTER ?
          IApplicationAssociationRegistration ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      @DefProto DllImport, SHCreateAssociationRegistration, WIN_STD_CALL_CONV,, <:REFIID, :ptr ptr>, 8
    endif
    include pshpack1.inc
    DELEGATEITEMID struct
      cbSize WORD ?
      wOuter WORD ?
      cbInner WORD ?
      rgb BYTE 1 dup (?)
    DELEGATEITEMID ends
    include poppack.inc
    PCDELEGATEITEMID typedef ptr DELEGATEITEMID
    PDELEGATEITEMID typedef ptr DELEGATEITEMID
    externdef __MIDL_itf_shobjidl_core_0000_0107_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0107_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDelegateFolder_INTERFACE_DEFINED__
      __IDelegateFolder_INTERFACE_DEFINED__ equ <>
      externdef IID_IDelegateFolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDelegateFolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDelegateFolderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDelegateFolder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDelegateFolder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDelegateFolder
          DECLSPEC_XFGVIRT(IDelegateFolder, SetItemAlloc)
          STD_METHOD SetItemAlloc, :ptr IDelegateFolder, :ptr IMalloc
          ??Interface equ <>
          END_INTERFACE
        IDelegateFolderVtbl ends
        IDelegateFolder struct
          lpVtbl POINTER ?
        IDelegateFolder ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60)
      externdef __MIDL_itf_shobjidl_core_0000_0108_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0108_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBrowserFrameOptions_INTERFACE_DEFINED__
        __IBrowserFrameOptions_INTERFACE_DEFINED__ equ <>
        LPBROWSERFRAMEOPTIONS typedef ptr IBrowserFrameOptions
        _BROWSERFRAMEOPTIONS typedef SDWORD
        BFO_NONE equ 0
        BFO_BROWSER_PERSIST_SETTINGS equ 1h
        BFO_RENAME_FOLDER_OPTIONS_TOINTERNET equ 2h
        BFO_BOTH_OPTIONS equ 4h
        BIF_PREFER_INTERNET_SHORTCUT equ 8h
        BFO_BROWSE_NO_IN_NEW_PROCESS equ 10h
        BFO_ENABLE_HYPERLINK_TRACKING equ 20h
        BFO_USE_IE_OFFLINE_SUPPORT equ 40h
        BFO_SUBSTITUE_INTERNET_START_PAGE equ 80h
        BFO_USE_IE_LOGOBANDING equ 100h
        BFO_ADD_IE_TOCAPTIONBAR equ 200h
        BFO_USE_DIALUP_REF equ 400h
        BFO_USE_IE_TOOLBAR equ 800h
        BFO_NO_PARENT_FOLDER_SUPPORT equ 1000h
        BFO_NO_REOPEN_NEXT_RESTART equ 2000h
        BFO_GO_HOME_PAGE equ 4000h
        BFO_PREFER_IEPROCESS equ 8000h
        BFO_SHOW_NAVIGATION_CANCELLED equ 10000h
        BFO_USE_IE_STATUSBAR equ 20000h
        BFO_QUERY_ALL equ 0ffffffffh

        BROWSERFRAMEOPTIONS typedef DWORD
        externdef IID_IBrowserFrameOptions:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBrowserFrameOptionsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBrowserFrameOptionsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBrowserFrameOptions, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBrowserFrameOptions
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBrowserFrameOptions
            DECLSPEC_XFGVIRT(IBrowserFrameOptions, GetFrameOptions)
            STD_METHOD GetFrameOptions, :ptr IBrowserFrameOptions, :BROWSERFRAMEOPTIONS, :ptr BROWSERFRAMEOPTIONS
            ??Interface equ <>
            END_INTERFACE
          IBrowserFrameOptionsVtbl ends
          IBrowserFrameOptions struct
            lpVtbl POINTER ?
          IBrowserFrameOptions ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      NWMF typedef SDWORD
      NWMF_UNLOADING equ 1h
      NWMF_USERINITED equ 2h
      NWMF_FIRST equ 4h
      NWMF_OVERRIDEKEY equ 8h
      NWMF_SHOWHELP equ 10h
      NWMF_HTMLDIALOG equ 20h
      NWMF_FROMDIALOGCHILD equ 40h
      NWMF_USERREQUESTED equ 80h
      NWMF_USERALLOWED equ 100h
      NWMF_FORCEWINDOW equ 10000h
      NWMF_FORCETAB equ 20000h
      NWMF_SUGGESTWINDOW equ 40000h
      NWMF_SUGGESTTAB equ 80000h
      NWMF_INACTIVETAB equ 100000h

      DEFINE_ENUM_FLAG_OPERATORS(NWMF)
      SID_SNewWindowManager equ <IID_INewWindowManager>
      externdef __MIDL_itf_shobjidl_core_0000_0109_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0109_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __INewWindowManager_INTERFACE_DEFINED__
        __INewWindowManager_INTERFACE_DEFINED__ equ <>
        externdef IID_INewWindowManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INewWindowManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INewWindowManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr INewWindowManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr INewWindowManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr INewWindowManager
            DECLSPEC_XFGVIRT(INewWindowManager, EvaluateNewWindow)
            STD_METHOD EvaluateNewWindow, :ptr INewWindowManager, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :BOOL, :DWORD, :DWORD
            ??Interface equ <>
            END_INTERFACE
          INewWindowManagerVtbl ends
          INewWindowManager struct
            lpVtbl POINTER ?
          INewWindowManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAttachmentExecute_INTERFACE_DEFINED__
        __IAttachmentExecute_INTERFACE_DEFINED__ equ <>
        ATTACHMENT_PROMPT typedef SDWORD
        ATTACHMENT_PROMPT_NONE equ 0
        ATTACHMENT_PROMPT_SAVE equ 1h
        ATTACHMENT_PROMPT_EXEC equ 2h
        ATTACHMENT_PROMPT_EXEC_OR_SAVE equ 3h

        ATTACHMENT_ACTION typedef SDWORD
        ATTACHMENT_ACTION_CANCEL equ 0
        ATTACHMENT_ACTION_SAVE equ 1h
        ATTACHMENT_ACTION_EXEC equ 2h

        externdef IID_IAttachmentExecute:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAttachmentExecuteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAttachmentExecuteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAttachmentExecute, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAttachmentExecute
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAttachmentExecute
            DECLSPEC_XFGVIRT(IAttachmentExecute, SetClientTitle)
            STD_METHOD SetClientTitle, :ptr IAttachmentExecute, :LPCWSTR
            DECLSPEC_XFGVIRT(IAttachmentExecute, SetClientGuid)
            STD_METHOD SetClientGuid, :ptr IAttachmentExecute, :REFGUID
            DECLSPEC_XFGVIRT(IAttachmentExecute, SetLocalPath)
            STD_METHOD SetLocalPath, :ptr IAttachmentExecute, :LPCWSTR
            DECLSPEC_XFGVIRT(IAttachmentExecute, SetFileName)
            STD_METHOD SetFileName, :ptr IAttachmentExecute, :LPCWSTR
            DECLSPEC_XFGVIRT(IAttachmentExecute, SetSource)
            STD_METHOD SetSource, :ptr IAttachmentExecute, :LPCWSTR
            DECLSPEC_XFGVIRT(IAttachmentExecute, SetReferrer)
            STD_METHOD SetReferrer, :ptr IAttachmentExecute, :LPCWSTR
            DECLSPEC_XFGVIRT(IAttachmentExecute, CheckPolicy)
            STD_METHOD CheckPolicy, :ptr IAttachmentExecute
            DECLSPEC_XFGVIRT(IAttachmentExecute, Prompt)
            STD_METHOD Prompt, :ptr IAttachmentExecute, :HWND, :ATTACHMENT_PROMPT, :ptr ATTACHMENT_ACTION
            DECLSPEC_XFGVIRT(IAttachmentExecute, Save)
            STD_METHOD Save, :ptr IAttachmentExecute
            DECLSPEC_XFGVIRT(IAttachmentExecute, Execute)
            STD_METHOD Execute, :ptr IAttachmentExecute, :HWND, :LPCWSTR, :ptr HANDLE
            DECLSPEC_XFGVIRT(IAttachmentExecute, SaveWithUI)
            STD_METHOD SaveWithUI, :ptr IAttachmentExecute, :HWND
            DECLSPEC_XFGVIRT(IAttachmentExecute, ClearClientState)
            STD_METHOD ClearClientState, :ptr IAttachmentExecute
            ??Interface equ <>
            END_INTERFACE
          IAttachmentExecuteVtbl ends
          IAttachmentExecute struct
            lpVtbl POINTER ?
          IAttachmentExecute ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60)
      include pshpack8.inc
      SMDATA struct
        dwMask DWORD ?
        dwFlags DWORD ?
        hmenu HMENU ?
        hwnd HWND ?
        uId UINT ?
        uIdParent UINT ?
        uIdAncestor UINT ?
        punk POINTER ?
        pidlFolder PIDLIST_ABSOLUTE ?
        pidlItem PUITEMID_CHILD ?
        psf POINTER ?
        pvUserData POINTER ?
      SMDATA ends
      tagSMDATA typedef SMDATA
      LPSMDATA typedef ptr tagSMDATA
      SMDM_SHELLFOLDER equ 00000001h
      SMDM_HMENU equ 00000002h
      SMDM_TOOLBAR equ 00000004h
      SMINFO struct
        dwMask DWORD ?
        dwType DWORD ?
        dwFlags DWORD ?
        iIcon SDWORD ?
      SMINFO ends
      tagSMINFO typedef SMINFO
      PSMINFO typedef ptr tagSMINFO
      SMCSHCHANGENOTIFYSTRUCT struct
        lEvent SDWORD ?
        pidl1 PCIDLIST_ABSOLUTE ?
        pidl2 PCIDLIST_ABSOLUTE ?
      SMCSHCHANGENOTIFYSTRUCT ends
      SHCSCHANGENOTIFYSTRUCT typedef SMCSHCHANGENOTIFYSTRUCT
      PSMCSHCHANGENOTIFYSTRUCT typedef ptr SHCSCHANGENOTIFYSTRUCT
      include poppack.inc
      tagSMINFOMASK typedef SDWORD
      SMIM_TYPE equ 1h
      SMIM_FLAGS equ 2h
      SMIM_ICON equ 4h

      tagSMINFOTYPE typedef SDWORD
      SMIT_SEPARATOR equ 1h
      SMIT_STRING equ 2h

      tagSMINFOFLAGS typedef SDWORD
      SMIF_ICON equ 1h
      SMIF_ACCELERATOR equ 2h
      SMIF_DROPTARGET equ 4h
      SMIF_SUBMENU equ 8h
      SMIF_CHECKED equ 20h
      SMIF_DROPCASCADE equ 40h
      SMIF_HIDDEN equ 80h
      SMIF_DISABLED equ 100h
      SMIF_TRACKPOPUP equ 200h
      SMIF_DEMOTED equ 400h
      SMIF_ALTSTATE equ 800h
      SMIF_DRAGNDROP equ 1000h
      SMIF_NEW equ 2000h

      SMC_INITMENU equ 00000001h
      SMC_CREATE equ 00000002h
      SMC_EXITMENU equ 00000003h
      SMC_GETINFO equ 00000005h
      SMC_GETSFINFO equ 00000006h
      SMC_GETOBJECT equ 00000007h
      SMC_GETSFOBJECT equ 00000008h
      SMC_SFEXEC equ 00000009h
      SMC_SFSELECTITEM equ 0000000Ah
      SMC_REFRESH equ 00000010h
      SMC_DEMOTE equ 00000011h
      SMC_PROMOTE equ 00000012h
      SMC_DEFAULTICON equ 00000016h
      SMC_NEWITEM equ 00000017h
      SMC_CHEVRONEXPAND equ 00000019h
      SMC_DISPLAYCHEVRONTIP equ 0000002Ah
      SMC_SETSFOBJECT equ 0000002Dh
      SMC_SHCHANGENOTIFY equ 0000002Eh
      SMC_CHEVRONGETTIP equ 0000002Fh
      SMC_SFDDRESTRICTED equ 00000030h
      if (_WIN32_IE ge _WIN32_IE_IE70)
        SMC_SFEXEC_MIDDLE equ 00000031h
        SMC_GETAUTOEXPANDSTATE equ 00000041h
        SMC_AUTOEXPANDCHANGE equ 00000042h
        SMC_GETCONTEXTMENUMODIFIER equ 00000043h
        SMC_GETBKCONTEXTMENU equ 00000044h
        SMC_OPEN equ 00000045h
        SMAE_EXPANDED equ 00000001h
        SMAE_CONTRACTED equ 00000002h
        SMAE_USER equ 00000004h
        SMAE_VALID equ 00000007h
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0111_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0111_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IShellMenuCallback_INTERFACE_DEFINED__
        __IShellMenuCallback_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellMenuCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellMenuCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellMenuCallbackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IShellMenuCallback, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellMenuCallback
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellMenuCallback
            DECLSPEC_XFGVIRT(IShellMenuCallback, CallbackSM)
            STD_METHOD CallbackSM, :ptr IShellMenuCallback, :LPSMDATA, :UINT, :WPARAM, :LPARAM
            ??Interface equ <>
            END_INTERFACE
          IShellMenuCallbackVtbl ends
          IShellMenuCallback struct
            lpVtbl POINTER ?
          IShellMenuCallback ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SMINIT_DEFAULT equ 00000000h
      SMINIT_RESTRICT_DRAGDROP equ 00000002h
      SMINIT_TOPLEVEL equ 00000004h
      SMINIT_CACHED equ 00000010h
      if (_WIN32_IE ge _WIN32_IE_IE70)
        SMINIT_AUTOEXPAND equ 00000100h
        SMINIT_AUTOTOOLTIP equ 00000200h
        SMINIT_DROPONCONTAINER equ 00000400h
      endif
      SMINIT_VERTICAL equ 10000000h
      SMINIT_HORIZONTAL equ 20000000h
      ANCESTORDEFAULT equ -1
      SMSET_TOP equ 10000000h
      SMSET_BOTTOM equ 20000000h
      SMSET_DONTOWN equ 00000001h
      SMINV_REFRESH equ 00000001h
      SMINV_ID equ 00000008h
      externdef __MIDL_itf_shobjidl_core_0000_0112_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0112_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IShellMenu_INTERFACE_DEFINED__
        __IShellMenu_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellMenu:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellMenuVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellMenuVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IShellMenu, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellMenu
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellMenu
            DECLSPEC_XFGVIRT(IShellMenu, Initialize)
            STD_METHOD Initialize, :ptr IShellMenu, :ptr IShellMenuCallback, :UINT, :UINT, :DWORD
            DECLSPEC_XFGVIRT(IShellMenu, GetMenuInfo)
            STD_METHOD GetMenuInfo, :ptr IShellMenu, :ptr ptr IShellMenuCallback, :ptr UINT, :ptr UINT, :ptr DWORD
            DECLSPEC_XFGVIRT(IShellMenu, SetShellFolder)
            STD_METHOD SetShellFolder, :ptr IShellMenu, :ptr IShellFolder, :PCIDLIST_ABSOLUTE, :HKEY, :DWORD
            DECLSPEC_XFGVIRT(IShellMenu, GetShellFolder)
            STD_METHOD GetShellFolder, :ptr IShellMenu, :ptr DWORD, :ptr PIDLIST_ABSOLUTE, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IShellMenu, SetMenu)
            STD_METHOD SetMenu, :ptr IShellMenu, :HMENU, :HWND, :DWORD
            DECLSPEC_XFGVIRT(IShellMenu, GetMenu)
            STD_METHOD GetMenu, :ptr IShellMenu, :ptr HMENU, :ptr HWND, :ptr DWORD
            DECLSPEC_XFGVIRT(IShellMenu, InvalidateItem)
            STD_METHOD InvalidateItem, :ptr IShellMenu, :LPSMDATA, :DWORD
            DECLSPEC_XFGVIRT(IShellMenu, GetState)
            STD_METHOD GetState, :ptr IShellMenu, :LPSMDATA
            DECLSPEC_XFGVIRT(IShellMenu, SetMenuToolbar)
            STD_METHOD SetMenuToolbar, :ptr IShellMenu, :ptr IUnknown, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IShellMenuVtbl ends
          IShellMenu struct
            lpVtbl POINTER ?
          IShellMenu ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      KF_CATEGORY typedef SDWORD
      KF_CATEGORY_VIRTUAL equ 1
      KF_CATEGORY_FIXED equ 2
      KF_CATEGORY_COMMON equ 3
      KF_CATEGORY_PERUSER equ 4

      _KF_DEFINITION_FLAGS typedef SDWORD
      KFDF_LOCAL_REDIRECT_ONLY equ 2h
      KFDF_ROAMABLE equ 4h
      KFDF_PRECREATE equ 8h
      KFDF_STREAM equ 10h
      KFDF_PUBLISHEXPANDEDPATH equ 20h
      KFDF_NO_REDIRECT_UI equ 40h

      KF_DEFINITION_FLAGS typedef DWORD
      _KF_REDIRECT_FLAGS typedef SDWORD
      KF_REDIRECT_USER_EXCLUSIVE equ 1h
      KF_REDIRECT_COPY_SOURCE_DACL equ 2h
      KF_REDIRECT_OWNER_USER equ 4h
      KF_REDIRECT_SET_OWNER_EXPLICIT equ 8h
      KF_REDIRECT_CHECK_ONLY equ 10h
      KF_REDIRECT_WITH_UI equ 20h
      KF_REDIRECT_UNPIN equ 40h
      KF_REDIRECT_PIN equ 80h
      KF_REDIRECT_COPY_CONTENTS equ 200h
      KF_REDIRECT_DEL_SOURCE_CONTENTS equ 400h
      KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS equ 800h

      KF_REDIRECT_FLAGS typedef DWORD
      _KF_REDIRECTION_CAPABILITIES typedef SDWORD
      KF_REDIRECTION_CAPABILITIES_ALLOW_ALL equ 0ffh
      KF_REDIRECTION_CAPABILITIES_REDIRECTABLE equ 1h
      KF_REDIRECTION_CAPABILITIES_DENY_ALL equ 0fff00h
      KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED equ 100h
      KF_REDIRECTION_CAPABILITIES_DENY_POLICY equ 200h
      KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS equ 400h

      KF_REDIRECTION_CAPABILITIES typedef DWORD
      KNOWNFOLDER_DEFINITION struct
        category KF_CATEGORY ?
        pszName LPWSTR ?
        pszDescription LPWSTR ?
        fidParent KNOWNFOLDERID <>
        pszRelativePath LPWSTR ?
        pszParsingName LPWSTR ?
        pszTooltip LPWSTR ?
        pszLocalizedName LPWSTR ?
        pszIcon LPWSTR ?
        pszSecurity LPWSTR ?
        dwAttributes DWORD ?
        kfdFlags KF_DEFINITION_FLAGS ?
        ftidType FOLDERTYPEID <>
      KNOWNFOLDER_DEFINITION ends
      externdef __MIDL_itf_shobjidl_core_0000_0113_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0113_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IKnownFolder_INTERFACE_DEFINED__
        __IKnownFolder_INTERFACE_DEFINED__ equ <>
        externdef IID_IKnownFolder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IKnownFolderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IKnownFolderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IKnownFolder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IKnownFolder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IKnownFolder
            DECLSPEC_XFGVIRT(IKnownFolder, GetId)
            STD_METHOD GetId, :ptr IKnownFolder, :ptr KNOWNFOLDERID
            DECLSPEC_XFGVIRT(IKnownFolder, GetCategory)
            STD_METHOD GetCategory, :ptr IKnownFolder, :ptr KF_CATEGORY
            DECLSPEC_XFGVIRT(IKnownFolder, GetShellItem)
            STD_METHOD GetShellItem, :ptr IKnownFolder, :DWORD, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IKnownFolder, GetPath)
            STD_METHOD GetPath, :ptr IKnownFolder, :DWORD, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IKnownFolder, SetPath)
            STD_METHOD SetPath, :ptr IKnownFolder, :DWORD, :LPCWSTR
            DECLSPEC_XFGVIRT(IKnownFolder, GetIDList)
            STD_METHOD GetIDList, :ptr IKnownFolder, :DWORD, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IKnownFolder, GetFolderType)
            STD_METHOD GetFolderType, :ptr IKnownFolder, :ptr FOLDERTYPEID
            DECLSPEC_XFGVIRT(IKnownFolder, GetRedirectionCapabilities)
            STD_METHOD GetRedirectionCapabilities, :ptr IKnownFolder, :ptr KF_REDIRECTION_CAPABILITIES
            DECLSPEC_XFGVIRT(IKnownFolder, GetFolderDefinition)
            STD_METHOD GetFolderDefinition, :ptr IKnownFolder, :ptr KNOWNFOLDER_DEFINITION
            ??Interface equ <>
            END_INTERFACE
          IKnownFolderVtbl ends
          IKnownFolder struct
            lpVtbl POINTER ?
          IKnownFolder ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IKnownFolderManager_INTERFACE_DEFINED__
        __IKnownFolderManager_INTERFACE_DEFINED__ equ <>
        FFFP_MODE typedef SDWORD
        FFFP_EXACTMATCH equ 0
        FFFP_NEARESTPARENTMATCH equ

        externdef IID_IKnownFolderManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IKnownFolderManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IKnownFolderManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IKnownFolderManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IKnownFolderManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IKnownFolderManager
            DECLSPEC_XFGVIRT(IKnownFolderManager, FolderIdFromCsidl)
            STD_METHOD FolderIdFromCsidl, :ptr IKnownFolderManager, :SDWORD, :ptr KNOWNFOLDERID
            DECLSPEC_XFGVIRT(IKnownFolderManager, FolderIdToCsidl)
            STD_METHOD FolderIdToCsidl, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :ptr SDWORD
            DECLSPEC_XFGVIRT(IKnownFolderManager, GetFolderIds)
            STD_METHOD GetFolderIds, :ptr IKnownFolderManager, :ptr ptr KNOWNFOLDERID, :ptr UINT
            DECLSPEC_XFGVIRT(IKnownFolderManager, GetFolder)
            STD_METHOD GetFolder, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :ptr ptr IKnownFolder
            DECLSPEC_XFGVIRT(IKnownFolderManager, GetFolderByName)
            STD_METHOD GetFolderByName, :ptr IKnownFolderManager, :LPCWSTR, :ptr ptr IKnownFolder
            DECLSPEC_XFGVIRT(IKnownFolderManager, RegisterFolder)
            STD_METHOD RegisterFolder, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :ptr KNOWNFOLDER_DEFINITION
            DECLSPEC_XFGVIRT(IKnownFolderManager, UnregisterFolder)
            STD_METHOD UnregisterFolder, :ptr IKnownFolderManager, :REFKNOWNFOLDERID
            DECLSPEC_XFGVIRT(IKnownFolderManager, FindFolderFromPath)
            STD_METHOD FindFolderFromPath, :ptr IKnownFolderManager, :LPCWSTR, :FFFP_MODE, :ptr ptr IKnownFolder
            DECLSPEC_XFGVIRT(IKnownFolderManager, FindFolderFromIDList)
            STD_METHOD FindFolderFromIDList, :ptr IKnownFolderManager, :PCIDLIST_ABSOLUTE, :ptr ptr IKnownFolder
            DECLSPEC_XFGVIRT(IKnownFolderManager, Redirect)
            STD_METHOD Redirect, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :HWND, :KF_REDIRECT_FLAGS, :LPCWSTR, :UINT, :ptr KNOWNFOLDERID, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IKnownFolderManagerVtbl ends
          IKnownFolderManager struct
            lpVtbl POINTER ?
          IKnownFolderManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IKnownFolderManager_RemoteRedirect_Proxy proto WIN_STD_CALL_CONV :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :HWND, :KF_REDIRECT_FLAGS, :LPCWSTR, :UINT, :ptr GUID, :ptr LPWSTR
        IKnownFolderManager_RemoteRedirect_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      FreeKnownFolderDefinitionFields proto WIN_STD_CALL_CONV :ptr KNOWNFOLDER_DEFINITION
      SHARE_ROLE typedef SDWORD
      SHARE_ROLE_INVALID equ -1
      SHARE_ROLE_READER equ 0
      SHARE_ROLE_CONTRIBUTOR equ 1
      SHARE_ROLE_CO_OWNER equ 2
      SHARE_ROLE_OWNER equ 3
      SHARE_ROLE_CUSTOM equ 4
      SHARE_ROLE_MIXED equ 5

      DEF_SHARE_ID typedef SDWORD
      DEFSHAREID_USERS equ 1
      DEFSHAREID_PUBLIC equ 2

      externdef __MIDL_itf_shobjidl_core_0000_0115_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0115_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISharingConfigurationManager_INTERFACE_DEFINED__
        __ISharingConfigurationManager_INTERFACE_DEFINED__ equ <>
        externdef IID_ISharingConfigurationManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISharingConfigurationManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISharingConfigurationManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISharingConfigurationManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISharingConfigurationManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISharingConfigurationManager
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, CreateShare)
            STD_METHOD CreateShare, :ptr ISharingConfigurationManager, :DEF_SHARE_ID, :SHARE_ROLE
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, DeleteShare)
            STD_METHOD DeleteShare, :ptr ISharingConfigurationManager, :DEF_SHARE_ID
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, ShareExists)
            STD_METHOD ShareExists, :ptr ISharingConfigurationManager, :DEF_SHARE_ID
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, GetSharePermissions)
            STD_METHOD GetSharePermissions, :ptr ISharingConfigurationManager, :DEF_SHARE_ID, :ptr SHARE_ROLE
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, SharePrinters)
            STD_METHOD SharePrinters, :ptr ISharingConfigurationManager
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, StopSharingPrinters)
            STD_METHOD StopSharingPrinters, :ptr ISharingConfigurationManager
            DECLSPEC_XFGVIRT(ISharingConfigurationManager, ArePrintersShared)
            STD_METHOD ArePrintersShared, :ptr ISharingConfigurationManager
            ??Interface equ <>
            END_INTERFACE
          ISharingConfigurationManagerVtbl ends
          ISharingConfigurationManager struct
            lpVtbl POINTER ?
          ISharingConfigurationManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0116_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0116_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IRelatedItem_INTERFACE_DEFINED__
        __IRelatedItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IRelatedItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRelatedItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRelatedItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRelatedItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRelatedItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRelatedItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IRelatedItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IRelatedItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IRelatedItemVtbl ends
          IRelatedItem struct
            lpVtbl POINTER ?
          IRelatedItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IIdentityName_INTERFACE_DEFINED__
        __IIdentityName_INTERFACE_DEFINED__ equ <>
        externdef IID_IIdentityName:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IIdentityNameVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IIdentityNameVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IIdentityName, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IIdentityName
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IIdentityName
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IIdentityName, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IIdentityName, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IIdentityNameVtbl ends
          IIdentityName struct
            lpVtbl POINTER ?
          IIdentityName ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDelegateItem_INTERFACE_DEFINED__
        __IDelegateItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IDelegateItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDelegateItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDelegateItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDelegateItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDelegateItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDelegateItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IDelegateItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IDelegateItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IDelegateItemVtbl ends
          IDelegateItem struct
            lpVtbl POINTER ?
          IDelegateItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ICurrentItem_INTERFACE_DEFINED__
        __ICurrentItem_INTERFACE_DEFINED__ equ <>
        externdef IID_ICurrentItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICurrentItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICurrentItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICurrentItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICurrentItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICurrentItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr ICurrentItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr ICurrentItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          ICurrentItemVtbl ends
          ICurrentItem struct
            lpVtbl POINTER ?
          ICurrentItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ITransferMediumItem_INTERFACE_DEFINED__
        __ITransferMediumItem_INTERFACE_DEFINED__ equ <>
        externdef IID_ITransferMediumItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITransferMediumItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITransferMediumItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ITransferMediumItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ITransferMediumItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ITransferMediumItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr ITransferMediumItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr ITransferMediumItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          ITransferMediumItemVtbl ends
          ITransferMediumItem struct
            lpVtbl POINTER ?
          ITransferMediumItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDisplayItem_INTERFACE_DEFINED__
        __IDisplayItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IDisplayItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDisplayItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDisplayItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDisplayItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDisplayItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDisplayItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IDisplayItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IDisplayItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IDisplayItemVtbl ends
          IDisplayItem struct
            lpVtbl POINTER ?
          IDisplayItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IViewStateIdentityItem_INTERFACE_DEFINED__
        __IViewStateIdentityItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IViewStateIdentityItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IViewStateIdentityItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IViewStateIdentityItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IViewStateIdentityItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IViewStateIdentityItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IViewStateIdentityItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IViewStateIdentityItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IViewStateIdentityItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IViewStateIdentityItemVtbl ends
          IViewStateIdentityItem struct
            lpVtbl POINTER ?
          IViewStateIdentityItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPreviewItem_INTERFACE_DEFINED__
        __IPreviewItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IPreviewItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPreviewItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPreviewItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPreviewItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPreviewItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPreviewItem
            DECLSPEC_XFGVIRT(IRelatedItem, GetItemIDList)
            STD_METHOD GetItemIDList, :ptr IPreviewItem, :ptr PIDLIST_ABSOLUTE
            DECLSPEC_XFGVIRT(IRelatedItem, GetItem)
            STD_METHOD GetItem, :ptr IPreviewItem, :ptr ptr IShellItem
            ??Interface equ <>
            END_INTERFACE
          IPreviewItemVtbl ends
          IPreviewItem struct
            lpVtbl POINTER ?
          IPreviewItem ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0124_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0124_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDestinationStreamFactory_INTERFACE_DEFINED__
      __IDestinationStreamFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IDestinationStreamFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDestinationStreamFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDestinationStreamFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDestinationStreamFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDestinationStreamFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDestinationStreamFactory
          DECLSPEC_XFGVIRT(IDestinationStreamFactory, GetDestinationStream)
          STD_METHOD GetDestinationStream, :ptr IDestinationStreamFactory, :ptr ptr IStream
          ??Interface equ <>
          END_INTERFACE
        IDestinationStreamFactoryVtbl ends
        IDestinationStreamFactory struct
          lpVtbl POINTER ?
        IDestinationStreamFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0125_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0125_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICreateProcessInputs_INTERFACE_DEFINED__
        __ICreateProcessInputs_INTERFACE_DEFINED__ equ <>
        externdef IID_ICreateProcessInputs:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICreateProcessInputsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICreateProcessInputsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICreateProcessInputs, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICreateProcessInputs
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICreateProcessInputs
            DECLSPEC_XFGVIRT(ICreateProcessInputs, GetCreateFlags)
            STD_METHOD GetCreateFlags, :ptr ICreateProcessInputs, :ptr DWORD
            DECLSPEC_XFGVIRT(ICreateProcessInputs, SetCreateFlags)
            STD_METHOD SetCreateFlags, :ptr ICreateProcessInputs, :DWORD
            DECLSPEC_XFGVIRT(ICreateProcessInputs, AddCreateFlags)
            STD_METHOD AddCreateFlags, :ptr ICreateProcessInputs, :DWORD
            DECLSPEC_XFGVIRT(ICreateProcessInputs, SetHotKey)
            STD_METHOD SetHotKey, :ptr ICreateProcessInputs, :WORD
            DECLSPEC_XFGVIRT(ICreateProcessInputs, AddStartupFlags)
            STD_METHOD AddStartupFlags, :ptr ICreateProcessInputs, :DWORD
            DECLSPEC_XFGVIRT(ICreateProcessInputs, SetTitle)
            STD_METHOD SetTitle, :ptr ICreateProcessInputs, :LPCWSTR
            DECLSPEC_XFGVIRT(ICreateProcessInputs, SetEnvironmentVariable)
            STD_METHOD SetEnvironmentVariable, :ptr ICreateProcessInputs, :LPCWSTR, :LPCWSTR
            ??Interface equ <>
            END_INTERFACE
          ICreateProcessInputsVtbl ends
          ICreateProcessInputs struct
            lpVtbl POINTER ?
          ICreateProcessInputs ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ICreatingProcess_INTERFACE_DEFINED__
        __ICreatingProcess_INTERFACE_DEFINED__ equ <>
        externdef IID_ICreatingProcess:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICreatingProcessVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICreatingProcessVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICreatingProcess, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICreatingProcess
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICreatingProcess
            DECLSPEC_XFGVIRT(ICreatingProcess, OnCreating)
            STD_METHOD OnCreating, :ptr ICreatingProcess, :ptr ICreateProcessInputs
            ??Interface equ <>
            END_INTERFACE
          ICreatingProcessVtbl ends
          ICreatingProcess struct
            lpVtbl POINTER ?
          ICreatingProcess ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_ExecuteCreatingProcess equ <__uuidof(ICreatingProcess)>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      externdef __MIDL_itf_shobjidl_core_0000_0127_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0127_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ILaunchUIContext_INTERFACE_DEFINED__
        __ILaunchUIContext_INTERFACE_DEFINED__ equ <>
        externdef IID_ILaunchUIContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ILaunchUIContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ILaunchUIContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ILaunchUIContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ILaunchUIContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ILaunchUIContext
            DECLSPEC_XFGVIRT(ILaunchUIContext, SetAssociatedWindow)
            STD_METHOD SetAssociatedWindow, :ptr ILaunchUIContext, :HWND
            DECLSPEC_XFGVIRT(ILaunchUIContext, SetTabGroupingPreference)
            STD_METHOD SetTabGroupingPreference, :ptr ILaunchUIContext, :DWORD
            ??Interface equ <>
            END_INTERFACE
          ILaunchUIContextVtbl ends
          ILaunchUIContext struct
            lpVtbl POINTER ?
          ILaunchUIContext ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ILaunchUIContextProvider_INTERFACE_DEFINED__
        __ILaunchUIContextProvider_INTERFACE_DEFINED__ equ <>
        externdef IID_ILaunchUIContextProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ILaunchUIContextProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ILaunchUIContextProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ILaunchUIContextProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ILaunchUIContextProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ILaunchUIContextProvider
            DECLSPEC_XFGVIRT(ILaunchUIContextProvider, UpdateContext)
            STD_METHOD UpdateContext, :ptr ILaunchUIContextProvider, :ptr ILaunchUIContext
            ??Interface equ <>
            END_INTERFACE
          ILaunchUIContextProviderVtbl ends
          ILaunchUIContextProvider struct
            lpVtbl POINTER ?
          ILaunchUIContextProvider ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_LaunchUIContextProvider equ <__uuidof(ILaunchUIContextProvider)>
    endif
    _NMCII_FLAGS typedef SDWORD
    NMCII_NONE equ 0
    NMCII_ITEMS equ 1h
    NMCII_FOLDERS equ 2h

    NMCII_FLAGS typedef SDWORD
    _NMCSAEI_FLAGS typedef SDWORD
    NMCSAEI_SELECT equ 0
    NMCSAEI_EDIT equ 1h

    NMCSAEI_FLAGS typedef SDWORD
    externdef __MIDL_itf_shobjidl_core_0000_0129_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0129_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INewMenuClient_INTERFACE_DEFINED__
      __INewMenuClient_INTERFACE_DEFINED__ equ <>
      externdef IID_INewMenuClient:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INewMenuClientVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INewMenuClientVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr INewMenuClient, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INewMenuClient
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INewMenuClient
          DECLSPEC_XFGVIRT(INewMenuClient, IncludeItems)
          STD_METHOD IncludeItems, :ptr INewMenuClient, :ptr NMCII_FLAGS
          DECLSPEC_XFGVIRT(INewMenuClient, SelectAndEditItem)
          STD_METHOD SelectAndEditItem, :ptr INewMenuClient, :PCIDLIST_ABSOLUTE, :NMCSAEI_FLAGS
          ??Interface equ <>
          END_INTERFACE
        INewMenuClientVtbl ends
        INewMenuClient struct
          lpVtbl POINTER ?
        INewMenuClient ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SID_SNewMenuClient equ <IID_INewMenuClient>
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_core_0000_0130_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0130_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInitializeWithBindCtx_INTERFACE_DEFINED__
        __IInitializeWithBindCtx_INTERFACE_DEFINED__ equ <>
        externdef IID_IInitializeWithBindCtx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInitializeWithBindCtxVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInitializeWithBindCtxVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInitializeWithBindCtx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInitializeWithBindCtx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInitializeWithBindCtx
            DECLSPEC_XFGVIRT(IInitializeWithBindCtx, Initialize)
            STD_METHOD Initialize, :ptr IInitializeWithBindCtx, :ptr IBindCtx
            ??Interface equ <>
            END_INTERFACE
          IInitializeWithBindCtxVtbl ends
          IInitializeWithBindCtx struct
            lpVtbl POINTER ?
          IInitializeWithBindCtx ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellItemFilter_INTERFACE_DEFINED__
        __IShellItemFilter_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellItemFilter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellItemFilterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellItemFilterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IShellItemFilter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellItemFilter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellItemFilter
            DECLSPEC_XFGVIRT(IShellItemFilter, IncludeItem)
            STD_METHOD IncludeItem, :ptr IShellItemFilter, :ptr IShellItem
            DECLSPEC_XFGVIRT(IShellItemFilter, GetEnumFlagsForItem)
            STD_METHOD GetEnumFlagsForItem, :ptr IShellItemFilter, :ptr IShellItem, :ptr SHCONTF
            ??Interface equ <>
            END_INTERFACE
          IShellItemFilterVtbl ends
          IShellItemFilter struct
            lpVtbl POINTER ?
          IShellItemFilter ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0132_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0132_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INameSpaceTreeControl_INTERFACE_DEFINED__
      __INameSpaceTreeControl_INTERFACE_DEFINED__ equ <>
      _NSTCSTYLE typedef SDWORD
      NSTCS_HASEXPANDOS equ 1h
      NSTCS_HASLINES equ 2h
      NSTCS_SINGLECLICKEXPAND equ 4h
      NSTCS_FULLROWSELECT equ 8h
      NSTCS_SPRINGEXPAND equ 10h
      NSTCS_HORIZONTALSCROLL equ 20h
      NSTCS_ROOTHASEXPANDO equ 40h
      NSTCS_SHOWSELECTIONALWAYS equ 80h
      NSTCS_NOINFOTIP equ 200h
      NSTCS_EVENHEIGHT equ 400h
      NSTCS_NOREPLACEOPEN equ 800h
      NSTCS_DISABLEDRAGDROP equ 1000h
      NSTCS_NOORDERSTREAM equ 2000h
      NSTCS_RICHTOOLTIP equ 4000h
      NSTCS_BORDER equ 8000h
      NSTCS_NOEDITLABELS equ 10000h
      NSTCS_TABSTOP equ 20000h
      NSTCS_FAVORITESMODE equ 80000h
      NSTCS_AUTOHSCROLL equ 100000h
      NSTCS_FADEINOUTEXPANDOS equ 200000h
      NSTCS_EMPTYTEXT equ 400000h
      NSTCS_CHECKBOXES equ 800000h
      NSTCS_PARTIALCHECKBOXES equ 1000000h
      NSTCS_EXCLUSIONCHECKBOXES equ 2000000h
      NSTCS_DIMMEDCHECKBOXES equ 4000000h
      NSTCS_NOINDENTCHECKS equ 8000000h
      NSTCS_ALLOWJUNCTIONS equ 10000000h
      NSTCS_SHOWTABSBUTTON equ 20000000h
      NSTCS_SHOWDELETEBUTTON equ 40000000h
      NSTCS_SHOWREFRESHBUTTON equ 80000000h

      NSTCSTYLE typedef DWORD
      _NSTCROOTSTYLE typedef SDWORD
      NSTCRS_VISIBLE equ 0
      NSTCRS_HIDDEN equ 1h
      NSTCRS_EXPANDED equ 2h

      NSTCROOTSTYLE typedef DWORD
      _NSTCITEMSTATE typedef SDWORD
      NSTCIS_NONE equ 0
      NSTCIS_SELECTED equ 1h
      NSTCIS_EXPANDED equ 2h
      NSTCIS_BOLD equ 4h
      NSTCIS_DISABLED equ 8h
      NSTCIS_SELECTEDNOEXPAND equ 10h

      NSTCITEMSTATE typedef DWORD
      NSTCGNI typedef SDWORD
      NSTCGNI_NEXT equ 0
      NSTCGNI_NEXTVISIBLE equ 1
      NSTCGNI_PREV equ 2
      NSTCGNI_PREVVISIBLE equ 3
      NSTCGNI_PARENT equ 4
      NSTCGNI_CHILD equ 5
      NSTCGNI_FIRSTVISIBLE equ 6
      NSTCGNI_LASTVISIBLE equ 7

      externdef IID_INameSpaceTreeControl:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INameSpaceTreeControlVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INameSpaceTreeControlVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControl, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INameSpaceTreeControl
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INameSpaceTreeControl
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, Initialize)
          STD_METHOD Initialize, :ptr INameSpaceTreeControl, :HWND, :ptr RECT, :NSTCSTYLE
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, TreeAdvise)
          STD_METHOD TreeAdvise, :ptr INameSpaceTreeControl, :ptr IUnknown, :ptr DWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, TreeUnadvise)
          STD_METHOD TreeUnadvise, :ptr INameSpaceTreeControl, :DWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, AppendRoot)
          STD_METHOD AppendRoot, :ptr INameSpaceTreeControl, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, InsertRoot)
          STD_METHOD InsertRoot, :ptr INameSpaceTreeControl, :SDWORD, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, RemoveRoot)
          STD_METHOD RemoveRoot, :ptr INameSpaceTreeControl, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, RemoveAllRoots)
          STD_METHOD RemoveAllRoots, :ptr INameSpaceTreeControl
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetRootItems)
          STD_METHOD GetRootItems, :ptr INameSpaceTreeControl, :ptr ptr IShellItemArray
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, SetItemState)
          STD_METHOD SetItemState, :ptr INameSpaceTreeControl, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetItemState)
          STD_METHOD GetItemState, :ptr INameSpaceTreeControl, :ptr IShellItem, :NSTCITEMSTATE, :ptr NSTCITEMSTATE
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetSelectedItems)
          STD_METHOD GetSelectedItems, :ptr INameSpaceTreeControl, :ptr ptr IShellItemArray
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetItemCustomState)
          STD_METHOD GetItemCustomState, :ptr INameSpaceTreeControl, :ptr IShellItem, :ptr SDWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, SetItemCustomState)
          STD_METHOD SetItemCustomState, :ptr INameSpaceTreeControl, :ptr IShellItem, :SDWORD
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, EnsureItemVisible)
          STD_METHOD EnsureItemVisible, :ptr INameSpaceTreeControl, :ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, SetTheme)
          STD_METHOD SetTheme, :ptr INameSpaceTreeControl, :LPCWSTR
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetNextItem)
          STD_METHOD GetNextItem, :ptr INameSpaceTreeControl, :ptr IShellItem, :NSTCGNI, :ptr ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, HitTest)
          STD_METHOD HitTest, :ptr INameSpaceTreeControl, :ptr POINT, :ptr ptr IShellItem
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, GetItemRect)
          STD_METHOD GetItemRect, :ptr INameSpaceTreeControl, :ptr IShellItem, :ptr RECT
          DECLSPEC_XFGVIRT(INameSpaceTreeControl, CollapseAll)
          STD_METHOD CollapseAll, :ptr INameSpaceTreeControl
          ??Interface equ <>
          END_INTERFACE
        INameSpaceTreeControlVtbl ends
        INameSpaceTreeControl struct
          lpVtbl POINTER ?
        INameSpaceTreeControl ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SID_SNavigationPane equ <IID_INameSpaceTreeControl>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0133_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0133_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __INameSpaceTreeControlFolderCapabilities_INTERFACE_DEFINED__
        __INameSpaceTreeControlFolderCapabilities_INTERFACE_DEFINED__ equ <>
        NSTCFOLDERCAPABILITIES typedef SDWORD
        NSTCFC_NONE equ 0
        NSTCFC_PINNEDITEMFILTERING equ 1h
        NSTCFC_DELAY_REGISTER_NOTIFY equ 2h

        DEFINE_ENUM_FLAG_OPERATORS(NSTCFOLDERCAPABILITIES)
        externdef IID_INameSpaceTreeControlFolderCapabilities:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INameSpaceTreeControlFolderCapabilitiesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INameSpaceTreeControlFolderCapabilitiesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr INameSpaceTreeControlFolderCapabilities, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr INameSpaceTreeControlFolderCapabilities
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr INameSpaceTreeControlFolderCapabilities
            DECLSPEC_XFGVIRT(INameSpaceTreeControlFolderCapabilities, GetFolderCapabilities)
            STD_METHOD GetFolderCapabilities, :ptr INameSpaceTreeControlFolderCapabilities, :NSTCFOLDERCAPABILITIES, :ptr NSTCFOLDERCAPABILITIES
            ??Interface equ <>
            END_INTERFACE
          INameSpaceTreeControlFolderCapabilitiesVtbl ends
          INameSpaceTreeControlFolderCapabilities struct
            lpVtbl POINTER ?
          INameSpaceTreeControlFolderCapabilities ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    E_PREVIEWHANDLER_DRM_FAIL equ _HRESULT_TYPEDEF_(86420001h)
    E_PREVIEWHANDLER_NOAUTH equ _HRESULT_TYPEDEF_(86420002h)
    E_PREVIEWHANDLER_NOTFOUND equ _HRESULT_TYPEDEF_(86420003h)
    E_PREVIEWHANDLER_CORRUPT equ _HRESULT_TYPEDEF_(86420004h)
    externdef __MIDL_itf_shobjidl_core_0000_0134_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0134_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPreviewHandler_INTERFACE_DEFINED__
      __IPreviewHandler_INTERFACE_DEFINED__ equ <>
      externdef IID_IPreviewHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPreviewHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPreviewHandlerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPreviewHandler, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPreviewHandler
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPreviewHandler
          DECLSPEC_XFGVIRT(IPreviewHandler, SetWindow)
          STD_METHOD SetWindow, :ptr IPreviewHandler, :HWND, :ptr RECT
          DECLSPEC_XFGVIRT(IPreviewHandler, SetRect)
          STD_METHOD SetRect, :ptr IPreviewHandler, :ptr RECT
          DECLSPEC_XFGVIRT(IPreviewHandler, DoPreview)
          STD_METHOD DoPreview, :ptr IPreviewHandler
          DECLSPEC_XFGVIRT(IPreviewHandler, Unload)
          STD_METHOD Unload, :ptr IPreviewHandler
          DECLSPEC_XFGVIRT(IPreviewHandler, SetFocus)
          STD_METHOD SetFocus, :ptr IPreviewHandler
          DECLSPEC_XFGVIRT(IPreviewHandler, QueryFocus)
          STD_METHOD QueryFocus, :ptr IPreviewHandler, :ptr HWND
          DECLSPEC_XFGVIRT(IPreviewHandler, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IPreviewHandler, :ptr MSG
          ??Interface equ <>
          END_INTERFACE
        IPreviewHandlerVtbl ends
        IPreviewHandler struct
          lpVtbl POINTER ?
        IPreviewHandler ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPreviewHandlerFrame_INTERFACE_DEFINED__
      __IPreviewHandlerFrame_INTERFACE_DEFINED__ equ <>
      PREVIEWHANDLERFRAMEINFO struct
        haccel HACCEL ?
        cAccelEntries UINT ?
      PREVIEWHANDLERFRAMEINFO ends
      externdef IID_IPreviewHandlerFrame:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPreviewHandlerFrameVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPreviewHandlerFrameVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPreviewHandlerFrame, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPreviewHandlerFrame
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPreviewHandlerFrame
          DECLSPEC_XFGVIRT(IPreviewHandlerFrame, GetWindowContext)
          STD_METHOD GetWindowContext, :ptr IPreviewHandlerFrame, :ptr PREVIEWHANDLERFRAMEINFO
          DECLSPEC_XFGVIRT(IPreviewHandlerFrame, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IPreviewHandlerFrame, :ptr MSG
          ??Interface equ <>
          END_INTERFACE
        IPreviewHandlerFrameVtbl ends
        IPreviewHandlerFrame struct
          lpVtbl POINTER ?
        IPreviewHandlerFrame ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      EXPLORERPANE typedef GUID
      if 0
        ;[...]
      endif
      ifdef __cplusplus
        ;[...]
      else
        REFEXPLORERPANE equ <const EXPLORERPANE * __MIDL_CONST>
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0136_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0136_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IExplorerPaneVisibility_INTERFACE_DEFINED__
        __IExplorerPaneVisibility_INTERFACE_DEFINED__ equ <>
        _EXPLORERPANESTATE typedef SDWORD
        EPS_DONTCARE equ 0
        EPS_DEFAULT_ON equ 1h
        EPS_DEFAULT_OFF equ 2h
        EPS_STATEMASK equ 0ffffh
        EPS_INITIALSTATE equ 10000h
        EPS_FORCE equ 20000h

        EXPLORERPANESTATE typedef DWORD
        externdef IID_IExplorerPaneVisibility:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IExplorerPaneVisibilityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IExplorerPaneVisibilityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IExplorerPaneVisibility, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IExplorerPaneVisibility
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IExplorerPaneVisibility
            DECLSPEC_XFGVIRT(IExplorerPaneVisibility, GetPaneState)
            STD_METHOD GetPaneState, :ptr IExplorerPaneVisibility, :REFEXPLORERPANE, :ptr EXPLORERPANESTATE
            ??Interface equ <>
            END_INTERFACE
          IExplorerPaneVisibilityVtbl ends
          IExplorerPaneVisibility struct
            lpVtbl POINTER ?
          IExplorerPaneVisibility ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_ExplorerPaneVisibility equ <IID_IExplorerPaneVisibility>
      externdef __MIDL_itf_shobjidl_core_0000_0137_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0137_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IContextMenuCB_INTERFACE_DEFINED__
        __IContextMenuCB_INTERFACE_DEFINED__ equ <>
        externdef IID_IContextMenuCB:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IContextMenuCBVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IContextMenuCBVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IContextMenuCB, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IContextMenuCB
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IContextMenuCB
            DECLSPEC_XFGVIRT(IContextMenuCB, CallBack)
            STD_METHOD CallBack, :ptr IContextMenuCB, :ptr IShellFolder, :HWND, :ptr IDataObject, :UINT, :WPARAM, :LPARAM
            ??Interface equ <>
            END_INTERFACE
          IContextMenuCBVtbl ends
          IContextMenuCB struct
            lpVtbl POINTER ?
          IContextMenuCB ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0138_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0138_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDefaultExtractIconInit_INTERFACE_DEFINED__
      __IDefaultExtractIconInit_INTERFACE_DEFINED__ equ <>
      externdef IID_IDefaultExtractIconInit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDefaultExtractIconInitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDefaultExtractIconInitVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDefaultExtractIconInit, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDefaultExtractIconInit
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDefaultExtractIconInit
          DECLSPEC_XFGVIRT(IDefaultExtractIconInit, SetFlags)
          STD_METHOD SetFlags, :ptr IDefaultExtractIconInit, :UINT
          DECLSPEC_XFGVIRT(IDefaultExtractIconInit, SetKey)
          STD_METHOD SetKey, :ptr IDefaultExtractIconInit, :HKEY
          DECLSPEC_XFGVIRT(IDefaultExtractIconInit, SetNormalIcon)
          STD_METHOD SetNormalIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IDefaultExtractIconInit, SetOpenIcon)
          STD_METHOD SetOpenIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IDefaultExtractIconInit, SetShortcutIcon)
          STD_METHOD SetShortcutIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
          DECLSPEC_XFGVIRT(IDefaultExtractIconInit, SetDefaultIcon)
          STD_METHOD SetDefaultIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
          ??Interface equ <>
          END_INTERFACE
        IDefaultExtractIconInitVtbl ends
        IDefaultExtractIconInit struct
          lpVtbl POINTER ?
        IDefaultExtractIconInit ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    @DefProto DllImport, SHCreateDefaultExtractIcon, WIN_STD_CALL_CONV,, <:REFIID, :ptr ptr>, 8
    externdef __MIDL_itf_shobjidl_core_0000_0139_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0139_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IExplorerCommand_INTERFACE_DEFINED__
      __IExplorerCommand_INTERFACE_DEFINED__ equ <>
      _EXPCMDSTATE typedef SDWORD
      ECS_ENABLED equ 0
      ECS_DISABLED equ 1h
      ECS_HIDDEN equ 2h
      ECS_CHECKBOX equ 4h
      ECS_CHECKED equ 8h
      ECS_RADIOCHECK equ 10h

      EXPCMDSTATE typedef DWORD
      _EXPCMDFLAGS typedef SDWORD
      ECF_DEFAULT equ 0
      ECF_HASSUBCOMMANDS equ 1h
      ECF_HASSPLITBUTTON equ 2h
      ECF_HIDELABEL equ 4h
      ECF_ISSEPARATOR equ 8h
      ECF_HASLUASHIELD equ 10h
      ECF_SEPARATORBEFORE equ 20h
      ECF_SEPARATORAFTER equ 40h
      ECF_ISDROPDOWN equ 80h
      ECF_TOGGLEABLE equ 100h
      ECF_AUTOMENUICONS equ 200h

      EXPCMDFLAGS typedef DWORD
      externdef IID_IExplorerCommand:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExplorerCommandVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExplorerCommandVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IExplorerCommand, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IExplorerCommand
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IExplorerCommand
          DECLSPEC_XFGVIRT(IExplorerCommand, GetTitle)
          STD_METHOD GetTitle, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IExplorerCommand, GetIcon)
          STD_METHOD GetIcon, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IExplorerCommand, GetToolTip)
          STD_METHOD GetToolTip, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IExplorerCommand, GetCanonicalName)
          STD_METHOD GetCanonicalName, :ptr IExplorerCommand, :ptr GUID
          DECLSPEC_XFGVIRT(IExplorerCommand, GetState)
          STD_METHOD GetState, :ptr IExplorerCommand, :ptr IShellItemArray, :BOOL, :ptr EXPCMDSTATE
          DECLSPEC_XFGVIRT(IExplorerCommand, Invoke)
          STD_METHOD Invoke_, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr IBindCtx
          DECLSPEC_XFGVIRT(IExplorerCommand, GetFlags)
          STD_METHOD GetFlags, :ptr IExplorerCommand, :ptr EXPCMDFLAGS
          DECLSPEC_XFGVIRT(IExplorerCommand, EnumSubCommands)
          STD_METHOD EnumSubCommands, :ptr IExplorerCommand, :ptr ptr IEnumExplorerCommand
          ??Interface equ <>
          END_INTERFACE
        IExplorerCommandVtbl ends
        IExplorerCommand struct
          lpVtbl POINTER ?
        IExplorerCommand ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IExplorerCommandState_INTERFACE_DEFINED__
      __IExplorerCommandState_INTERFACE_DEFINED__ equ <>
      externdef IID_IExplorerCommandState:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExplorerCommandStateVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExplorerCommandStateVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IExplorerCommandState, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IExplorerCommandState
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IExplorerCommandState
          DECLSPEC_XFGVIRT(IExplorerCommandState, GetState)
          STD_METHOD GetState, :ptr IExplorerCommandState, :ptr IShellItemArray, :BOOL, :ptr EXPCMDSTATE
          ??Interface equ <>
          END_INTERFACE
        IExplorerCommandStateVtbl ends
        IExplorerCommandState struct
          lpVtbl POINTER ?
        IExplorerCommandState ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IInitializeCommand_INTERFACE_DEFINED__
      __IInitializeCommand_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeCommand:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeCommandVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeCommandVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInitializeCommand, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInitializeCommand
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInitializeCommand
          DECLSPEC_XFGVIRT(IInitializeCommand, Initialize)
          STD_METHOD Initialize, :ptr IInitializeCommand, :LPCWSTR, :ptr IPropertyBag
          ??Interface equ <>
          END_INTERFACE
        IInitializeCommandVtbl ends
        IInitializeCommand struct
          lpVtbl POINTER ?
        IInitializeCommand ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IEnumExplorerCommand_INTERFACE_DEFINED__
      __IEnumExplorerCommand_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumExplorerCommand:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumExplorerCommandVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumExplorerCommandVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IEnumExplorerCommand, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumExplorerCommand
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumExplorerCommand
          DECLSPEC_XFGVIRT(IEnumExplorerCommand, Next)
          STD_METHOD Next, :ptr IEnumExplorerCommand, :ULONG, :ptr ptr IExplorerCommand, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumExplorerCommand, Skip)
          STD_METHOD Skip, :ptr IEnumExplorerCommand, :ULONG
          DECLSPEC_XFGVIRT(IEnumExplorerCommand, Reset)
          STD_METHOD Reset, :ptr IEnumExplorerCommand
          DECLSPEC_XFGVIRT(IEnumExplorerCommand, Clone)
          STD_METHOD Clone, :ptr IEnumExplorerCommand, :ptr ptr IEnumExplorerCommand
          ??Interface equ <>
          END_INTERFACE
        IEnumExplorerCommandVtbl ends
        IEnumExplorerCommand struct
          lpVtbl POINTER ?
        IEnumExplorerCommand ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IEnumExplorerCommand_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumExplorerCommand, :ULONG, :ptr ptr IExplorerCommand, :ptr ULONG
      IEnumExplorerCommand_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __IExplorerCommandProvider_INTERFACE_DEFINED__
      __IExplorerCommandProvider_INTERFACE_DEFINED__ equ <>
      externdef IID_IExplorerCommandProvider:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExplorerCommandProviderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExplorerCommandProviderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IExplorerCommandProvider, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IExplorerCommandProvider
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IExplorerCommandProvider
          DECLSPEC_XFGVIRT(IExplorerCommandProvider, GetCommands)
          STD_METHOD GetCommands, :ptr IExplorerCommandProvider, :ptr IUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IExplorerCommandProvider, GetCommand)
          STD_METHOD GetCommand, :ptr IExplorerCommandProvider, :REFGUID, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IExplorerCommandProviderVtbl ends
        IExplorerCommandProvider struct
          lpVtbl POINTER ?
        IExplorerCommandProvider ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    HTHEME typedef HANDLE
    CPVIEW typedef SDWORD
    CPVIEW_CLASSIC equ 0
    CPVIEW_ALLITEMS equ CPVIEW_CLASSIC
    CPVIEW_CATEGORY equ 1
    CPVIEW_HOME equ CPVIEW_CATEGORY

    externdef __MIDL_itf_shobjidl_core_0000_0144_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0144_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOpenControlPanel_INTERFACE_DEFINED__
      __IOpenControlPanel_INTERFACE_DEFINED__ equ <>
      externdef IID_IOpenControlPanel:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOpenControlPanelVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOpenControlPanelVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IOpenControlPanel, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOpenControlPanel
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOpenControlPanel
          DECLSPEC_XFGVIRT(IOpenControlPanel, Open)
          STD_METHOD Open, :ptr IOpenControlPanel, :LPCWSTR, :LPCWSTR, :ptr IUnknown
          DECLSPEC_XFGVIRT(IOpenControlPanel, GetPath)
          STD_METHOD GetPath, :ptr IOpenControlPanel, :LPCWSTR, :LPWSTR, :UINT
          DECLSPEC_XFGVIRT(IOpenControlPanel, GetCurrentView)
          STD_METHOD GetCurrentView, :ptr IOpenControlPanel, :ptr CPVIEW
          ??Interface equ <>
          END_INTERFACE
        IOpenControlPanelVtbl ends
        IOpenControlPanel struct
          lpVtbl POINTER ?
        IOpenControlPanel ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    STR_FILE_SYS_BIND_DATA equ <L("File System Bind Data")>
    STR_FILE_SYS_BIND_DATA_WIN7_FORMAT equ <L("Win7FileSystemIdList")>
    externdef __MIDL_itf_shobjidl_core_0000_0145_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0145_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFileSystemBindData_INTERFACE_DEFINED__
      __IFileSystemBindData_INTERFACE_DEFINED__ equ <>
      externdef IID_IFileSystemBindData:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFileSystemBindDataVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFileSystemBindDataVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IFileSystemBindData, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFileSystemBindData
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFileSystemBindData
          DECLSPEC_XFGVIRT(IFileSystemBindData, SetFindData)
          STD_METHOD SetFindData, :ptr IFileSystemBindData, :ptr WIN32_FIND_DATAW
          DECLSPEC_XFGVIRT(IFileSystemBindData, GetFindData)
          STD_METHOD GetFindData, :ptr IFileSystemBindData, :ptr WIN32_FIND_DATAW
          ??Interface equ <>
          END_INTERFACE
        IFileSystemBindDataVtbl ends
        IFileSystemBindData struct
          lpVtbl POINTER ?
        IFileSystemBindData ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IFileSystemBindData2_INTERFACE_DEFINED__
      __IFileSystemBindData2_INTERFACE_DEFINED__ equ <>
      externdef IID_IFileSystemBindData2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFileSystemBindData2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFileSystemBindData2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IFileSystemBindData2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFileSystemBindData2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFileSystemBindData2
          DECLSPEC_XFGVIRT(IFileSystemBindData, SetFindData)
          STD_METHOD SetFindData, :ptr IFileSystemBindData2, :ptr WIN32_FIND_DATAW
          DECLSPEC_XFGVIRT(IFileSystemBindData, GetFindData)
          STD_METHOD GetFindData, :ptr IFileSystemBindData2, :ptr WIN32_FIND_DATAW
          DECLSPEC_XFGVIRT(IFileSystemBindData2, SetFileID)
          STD_METHOD SetFileID, :ptr IFileSystemBindData2, :LARGE_INTEGER
          DECLSPEC_XFGVIRT(IFileSystemBindData2, GetFileID)
          STD_METHOD GetFileID, :ptr IFileSystemBindData2, :ptr LARGE_INTEGER
          DECLSPEC_XFGVIRT(IFileSystemBindData2, SetJunctionCLSID)
          STD_METHOD SetJunctionCLSID, :ptr IFileSystemBindData2, :REFCLSID
          DECLSPEC_XFGVIRT(IFileSystemBindData2, GetJunctionCLSID)
          STD_METHOD GetJunctionCLSID, :ptr IFileSystemBindData2, :ptr CLSID
          ??Interface equ <>
          END_INTERFACE
        IFileSystemBindData2Vtbl ends
        IFileSystemBindData2 struct
          lpVtbl POINTER ?
        IFileSystemBindData2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      externdef __MIDL_itf_shobjidl_core_0000_0147_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0147_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICustomDestinationList_INTERFACE_DEFINED__
        __ICustomDestinationList_INTERFACE_DEFINED__ equ <>
        KNOWNDESTCATEGORY typedef SDWORD
        KDC_FREQUENT equ 1
        KDC_RECENT equ

        externdef IID_ICustomDestinationList:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICustomDestinationListVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICustomDestinationListVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICustomDestinationList, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICustomDestinationList
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICustomDestinationList
            DECLSPEC_XFGVIRT(ICustomDestinationList, SetAppID)
            STD_METHOD SetAppID, :ptr ICustomDestinationList, :LPCWSTR
            DECLSPEC_XFGVIRT(ICustomDestinationList, BeginList)
            STD_METHOD BeginList, :ptr ICustomDestinationList, :ptr UINT, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(ICustomDestinationList, AppendCategory)
            STD_METHOD AppendCategory, :ptr ICustomDestinationList, :LPCWSTR, :ptr IObjectArray
            DECLSPEC_XFGVIRT(ICustomDestinationList, AppendKnownCategory)
            STD_METHOD AppendKnownCategory, :ptr ICustomDestinationList, :KNOWNDESTCATEGORY
            DECLSPEC_XFGVIRT(ICustomDestinationList, AddUserTasks)
            STD_METHOD AddUserTasks, :ptr ICustomDestinationList, :ptr IObjectArray
            DECLSPEC_XFGVIRT(ICustomDestinationList, CommitList)
            STD_METHOD CommitList, :ptr ICustomDestinationList
            DECLSPEC_XFGVIRT(ICustomDestinationList, GetRemovedDestinations)
            STD_METHOD GetRemovedDestinations, :ptr ICustomDestinationList, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(ICustomDestinationList, DeleteList)
            STD_METHOD DeleteList, :ptr ICustomDestinationList, :LPCWSTR
            DECLSPEC_XFGVIRT(ICustomDestinationList, AbortList)
            STD_METHOD AbortList, :ptr ICustomDestinationList
            ??Interface equ <>
            END_INTERFACE
          ICustomDestinationListVtbl ends
          ICustomDestinationList struct
            lpVtbl POINTER ?
          ICustomDestinationList ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IApplicationDestinations_INTERFACE_DEFINED__
        __IApplicationDestinations_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationDestinations:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDestinationsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDestinationsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationDestinations, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDestinations
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDestinations
            DECLSPEC_XFGVIRT(IApplicationDestinations, SetAppID)
            STD_METHOD SetAppID, :ptr IApplicationDestinations, :LPCWSTR
            DECLSPEC_XFGVIRT(IApplicationDestinations, RemoveDestination)
            STD_METHOD RemoveDestination, :ptr IApplicationDestinations, :ptr IUnknown
            DECLSPEC_XFGVIRT(IApplicationDestinations, RemoveAllDestinations)
            STD_METHOD RemoveAllDestinations, :ptr IApplicationDestinations
            ??Interface equ <>
            END_INTERFACE
          IApplicationDestinationsVtbl ends
          IApplicationDestinations struct
            lpVtbl POINTER ?
          IApplicationDestinations ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IApplicationDocumentLists_INTERFACE_DEFINED__
        __IApplicationDocumentLists_INTERFACE_DEFINED__ equ <>
        APPDOCLISTTYPE typedef SDWORD
        ADLT_RECENT equ 0
        ADLT_FREQUENT equ

        externdef IID_IApplicationDocumentLists:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDocumentListsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDocumentListsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationDocumentLists, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDocumentLists
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDocumentLists
            DECLSPEC_XFGVIRT(IApplicationDocumentLists, SetAppID)
            STD_METHOD SetAppID, :ptr IApplicationDocumentLists, :LPCWSTR
            DECLSPEC_XFGVIRT(IApplicationDocumentLists, GetList)
            STD_METHOD GetList, :ptr IApplicationDocumentLists, :APPDOCLISTTYPE, :UINT, :REFIID, :ptr ptr
            ??Interface equ <>
            END_INTERFACE
          IApplicationDocumentListsVtbl ends
          IApplicationDocumentLists struct
            lpVtbl POINTER ?
          IApplicationDocumentLists ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IObjectWithAppUserModelID_INTERFACE_DEFINED__
        __IObjectWithAppUserModelID_INTERFACE_DEFINED__ equ <>
        externdef IID_IObjectWithAppUserModelID:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IObjectWithAppUserModelIDVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IObjectWithAppUserModelIDVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IObjectWithAppUserModelID, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IObjectWithAppUserModelID
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IObjectWithAppUserModelID
            DECLSPEC_XFGVIRT(IObjectWithAppUserModelID, SetAppID)
            STD_METHOD SetAppID, :ptr IObjectWithAppUserModelID, :LPCWSTR
            DECLSPEC_XFGVIRT(IObjectWithAppUserModelID, GetAppID)
            STD_METHOD GetAppID, :ptr IObjectWithAppUserModelID, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IObjectWithAppUserModelIDVtbl ends
          IObjectWithAppUserModelID struct
            lpVtbl POINTER ?
          IObjectWithAppUserModelID ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IObjectWithProgID_INTERFACE_DEFINED__
        __IObjectWithProgID_INTERFACE_DEFINED__ equ <>
        externdef IID_IObjectWithProgID:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IObjectWithProgIDVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IObjectWithProgIDVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IObjectWithProgID, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IObjectWithProgID
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IObjectWithProgID
            DECLSPEC_XFGVIRT(IObjectWithProgID, SetProgID)
            STD_METHOD SetProgID, :ptr IObjectWithProgID, :LPCWSTR
            DECLSPEC_XFGVIRT(IObjectWithProgID, GetProgID)
            STD_METHOD GetProgID, :ptr IObjectWithProgID, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IObjectWithProgIDVtbl ends
          IObjectWithProgID struct
            lpVtbl POINTER ?
          IObjectWithProgID ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IUpdateIDList_INTERFACE_DEFINED__
        __IUpdateIDList_INTERFACE_DEFINED__ equ <>
        externdef IID_IUpdateIDList:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUpdateIDListVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUpdateIDListVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IUpdateIDList, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUpdateIDList
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUpdateIDList
            DECLSPEC_XFGVIRT(IUpdateIDList, Update)
            STD_METHOD Update, :ptr IUpdateIDList, :ptr IBindCtx, :PCUITEMID_CHILD, :ptr PITEMID_CHILD
            ??Interface equ <>
            END_INTERFACE
          IUpdateIDListVtbl ends
          IUpdateIDList struct
            lpVtbl POINTER ?
          IUpdateIDList ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      @DefProto DllImport, SetCurrentProcessExplicitAppUserModelID, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
      @DefProto DllImport, GetCurrentProcessExplicitAppUserModelID, WIN_STD_CALL_CONV,, <:ptr PWSTR>, 4
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      externdef __MIDL_itf_shobjidl_core_0000_0153_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0153_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDesktopWallpaper_INTERFACE_DEFINED__
        __IDesktopWallpaper_INTERFACE_DEFINED__ equ <>
        DESKTOP_SLIDESHOW_OPTIONS typedef SDWORD
        DSO_SHUFFLEIMAGES equ 1h

        DEFINE_ENUM_FLAG_OPERATORS(DESKTOP_SLIDESHOW_OPTIONS)
        DESKTOP_SLIDESHOW_STATE typedef SDWORD
        DSS_ENABLED equ 1h
        DSS_SLIDESHOW equ 2h
        DSS_DISABLED_BY_REMOTE_SESSION equ 4h

        DEFINE_ENUM_FLAG_OPERATORS(DESKTOP_SLIDESHOW_STATE)
        DESKTOP_SLIDESHOW_DIRECTION typedef SDWORD
        DSD_FORWARD equ 0
        DSD_BACKWARD equ 1

        DESKTOP_WALLPAPER_POSITION typedef SDWORD
        DWPOS_CENTER equ 0
        DWPOS_TILE equ 1
        DWPOS_STRETCH equ 2
        DWPOS_FIT equ 3
        DWPOS_FILL equ 4
        DWPOS_SPAN equ 5

        externdef IID_IDesktopWallpaper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDesktopWallpaperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDesktopWallpaperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDesktopWallpaper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDesktopWallpaper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDesktopWallpaper
            DECLSPEC_XFGVIRT(IDesktopWallpaper, SetWallpaper)
            STD_METHOD SetWallpaper, :ptr IDesktopWallpaper, :LPCWSTR, :LPCWSTR
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetWallpaper)
            STD_METHOD GetWallpaper, :ptr IDesktopWallpaper, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetMonitorDevicePathAt)
            STD_METHOD GetMonitorDevicePathAt, :ptr IDesktopWallpaper, :UINT, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetMonitorDevicePathCount)
            STD_METHOD GetMonitorDevicePathCount, :ptr IDesktopWallpaper, :ptr UINT
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetMonitorRECT)
            STD_METHOD GetMonitorRECT, :ptr IDesktopWallpaper, :LPCWSTR, :ptr RECT
            DECLSPEC_XFGVIRT(IDesktopWallpaper, SetBackgroundColor)
            STD_METHOD SetBackgroundColor, :ptr IDesktopWallpaper, :COLORREF
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetBackgroundColor)
            STD_METHOD GetBackgroundColor, :ptr IDesktopWallpaper, :ptr COLORREF
            DECLSPEC_XFGVIRT(IDesktopWallpaper, SetPosition)
            STD_METHOD SetPosition, :ptr IDesktopWallpaper, :DESKTOP_WALLPAPER_POSITION
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetPosition)
            STD_METHOD GetPosition, :ptr IDesktopWallpaper, :ptr DESKTOP_WALLPAPER_POSITION
            DECLSPEC_XFGVIRT(IDesktopWallpaper, SetSlideshow)
            STD_METHOD SetSlideshow, :ptr IDesktopWallpaper, :ptr IShellItemArray
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetSlideshow)
            STD_METHOD GetSlideshow, :ptr IDesktopWallpaper, :ptr ptr IShellItemArray
            DECLSPEC_XFGVIRT(IDesktopWallpaper, SetSlideshowOptions)
            STD_METHOD SetSlideshowOptions, :ptr IDesktopWallpaper, :DESKTOP_SLIDESHOW_OPTIONS, :UINT
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetSlideshowOptions)
            STD_METHOD GetSlideshowOptions, :ptr IDesktopWallpaper, :ptr DESKTOP_SLIDESHOW_OPTIONS, :ptr UINT
            DECLSPEC_XFGVIRT(IDesktopWallpaper, AdvanceSlideshow)
            STD_METHOD AdvanceSlideshow, :ptr IDesktopWallpaper, :LPCWSTR, :DESKTOP_SLIDESHOW_DIRECTION
            DECLSPEC_XFGVIRT(IDesktopWallpaper, GetStatus)
            STD_METHOD GetStatus, :ptr IDesktopWallpaper, :ptr DESKTOP_SLIDESHOW_STATE
            DECLSPEC_XFGVIRT(IDesktopWallpaper, Enable)
            STD_METHOD Enable, :ptr IDesktopWallpaper, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IDesktopWallpaperVtbl ends
          IDesktopWallpaper struct
            lpVtbl POINTER ?
          IDesktopWallpaper ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    HOMEGROUP_SECURITY_GROUP_MULTI equ <L("HUG")>
    HOMEGROUP_SECURITY_GROUP equ <L("HomeUsers")>
    externdef __MIDL_itf_shobjidl_core_0000_0154_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0154_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IHomeGroup_INTERFACE_DEFINED__
      __IHomeGroup_INTERFACE_DEFINED__ equ <>
      HOMEGROUPSHARINGCHOICES typedef SDWORD
      HGSC_NONE equ 0
      HGSC_MUSICLIBRARY equ 1h
      HGSC_PICTURESLIBRARY equ 2h
      HGSC_VIDEOSLIBRARY equ 4h
      HGSC_DOCUMENTSLIBRARY equ 8h
      HGSC_PRINTERS equ 10h

      DEFINE_ENUM_FLAG_OPERATORS(HOMEGROUPSHARINGCHOICES)
      externdef IID_IHomeGroup:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IHomeGroupVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IHomeGroupVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IHomeGroup, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IHomeGroup
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IHomeGroup
          DECLSPEC_XFGVIRT(IHomeGroup, IsMember)
          STD_METHOD IsMember, :ptr IHomeGroup, :ptr BOOL
          DECLSPEC_XFGVIRT(IHomeGroup, ShowSharingWizard)
          STD_METHOD ShowSharingWizard, :ptr IHomeGroup, :HWND, :ptr HOMEGROUPSHARINGCHOICES
          ??Interface equ <>
          END_INTERFACE
        IHomeGroupVtbl ends
        IHomeGroup struct
          lpVtbl POINTER ?
        IHomeGroup ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IInitializeWithPropertyStore_INTERFACE_DEFINED__
      __IInitializeWithPropertyStore_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeWithPropertyStore:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeWithPropertyStoreVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeWithPropertyStoreVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInitializeWithPropertyStore, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInitializeWithPropertyStore
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInitializeWithPropertyStore
          DECLSPEC_XFGVIRT(IInitializeWithPropertyStore, Initialize)
          STD_METHOD Initialize, :ptr IInitializeWithPropertyStore, :ptr IPropertyStore
          ??Interface equ <>
          END_INTERFACE
        IInitializeWithPropertyStoreVtbl ends
        IInitializeWithPropertyStore struct
          lpVtbl POINTER ?
        IInitializeWithPropertyStore ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IOpenSearchSource_INTERFACE_DEFINED__
      __IOpenSearchSource_INTERFACE_DEFINED__ equ <>
      externdef IID_IOpenSearchSource:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOpenSearchSourceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOpenSearchSourceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IOpenSearchSource, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOpenSearchSource
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOpenSearchSource
          DECLSPEC_XFGVIRT(IOpenSearchSource, GetResults)
          STD_METHOD GetResults, :ptr IOpenSearchSource, :HWND, :LPCWSTR, :DWORD, :DWORD, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IOpenSearchSourceVtbl ends
        IOpenSearchSource struct
          lpVtbl POINTER ?
        IOpenSearchSource ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IShellLibrary_INTERFACE_DEFINED__
      __IShellLibrary_INTERFACE_DEFINED__ equ <>
      LIBRARYFOLDERFILTER typedef SDWORD
      LFF_FORCEFILESYSTEM equ 1
      LFF_STORAGEITEMS equ 2
      LFF_ALLITEMS equ 3

      LIBRARYOPTIONFLAGS typedef SDWORD
      LOF_DEFAULT equ 0
      LOF_PINNEDTONAVPANE equ 1h
      LOF_MASK_ALL equ 1h

      DEFINE_ENUM_FLAG_OPERATORS(LIBRARYOPTIONFLAGS)
      DEFAULTSAVEFOLDERTYPE typedef SDWORD
      DSFT_DETECT equ 1
      DSFT_PRIVATE equ
      DSFT_PUBLIC equ

      LIBRARYSAVEFLAGS typedef SDWORD
      LSF_FAILIFTHERE equ 0
      LSF_OVERRIDEEXISTING equ 1h
      LSF_MAKEUNIQUENAME equ 2h

      DEFINE_ENUM_FLAG_OPERATORS(LIBRARYSAVEFLAGS)
      externdef IID_IShellLibrary:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellLibraryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellLibraryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellLibrary, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellLibrary
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellLibrary
          DECLSPEC_XFGVIRT(IShellLibrary, LoadLibraryFromItem)
          STD_METHOD LoadLibraryFromItem, :ptr IShellLibrary, :ptr IShellItem, :DWORD
          DECLSPEC_XFGVIRT(IShellLibrary, LoadLibraryFromKnownFolder)
          STD_METHOD LoadLibraryFromKnownFolder, :ptr IShellLibrary, :REFKNOWNFOLDERID, :DWORD
          DECLSPEC_XFGVIRT(IShellLibrary, AddFolder)
          STD_METHOD AddFolder, :ptr IShellLibrary, :ptr IShellItem
          DECLSPEC_XFGVIRT(IShellLibrary, RemoveFolder)
          STD_METHOD RemoveFolder, :ptr IShellLibrary, :ptr IShellItem
          DECLSPEC_XFGVIRT(IShellLibrary, GetFolders)
          STD_METHOD GetFolders, :ptr IShellLibrary, :LIBRARYFOLDERFILTER, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellLibrary, ResolveFolder)
          STD_METHOD ResolveFolder, :ptr IShellLibrary, :ptr IShellItem, :DWORD, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellLibrary, GetDefaultSaveFolder)
          STD_METHOD GetDefaultSaveFolder, :ptr IShellLibrary, :DEFAULTSAVEFOLDERTYPE, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IShellLibrary, SetDefaultSaveFolder)
          STD_METHOD SetDefaultSaveFolder, :ptr IShellLibrary, :DEFAULTSAVEFOLDERTYPE, :ptr IShellItem
          DECLSPEC_XFGVIRT(IShellLibrary, GetOptions)
          STD_METHOD GetOptions, :ptr IShellLibrary, :ptr LIBRARYOPTIONFLAGS
          DECLSPEC_XFGVIRT(IShellLibrary, SetOptions)
          STD_METHOD SetOptions, :ptr IShellLibrary, :LIBRARYOPTIONFLAGS, :LIBRARYOPTIONFLAGS
          DECLSPEC_XFGVIRT(IShellLibrary, GetFolderType)
          STD_METHOD GetFolderType, :ptr IShellLibrary, :ptr FOLDERTYPEID
          DECLSPEC_XFGVIRT(IShellLibrary, SetFolderType)
          STD_METHOD SetFolderType, :ptr IShellLibrary, :REFFOLDERTYPEID
          DECLSPEC_XFGVIRT(IShellLibrary, GetIcon)
          STD_METHOD GetIcon, :ptr IShellLibrary, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IShellLibrary, SetIcon)
          STD_METHOD SetIcon, :ptr IShellLibrary, :LPCWSTR
          DECLSPEC_XFGVIRT(IShellLibrary, Commit)
          STD_METHOD Commit, :ptr IShellLibrary
          DECLSPEC_XFGVIRT(IShellLibrary, Save)
          STD_METHOD Save, :ptr IShellLibrary, :ptr IShellItem, :LPCWSTR, :LIBRARYSAVEFLAGS, :ptr ptr IShellItem
          DECLSPEC_XFGVIRT(IShellLibrary, SaveInKnownFolder)
          STD_METHOD SaveInKnownFolder, :ptr IShellLibrary, :REFKNOWNFOLDERID, :LPCWSTR, :LIBRARYSAVEFLAGS, :ptr ptr IShellItem
          ??Interface equ <>
          END_INTERFACE
        IShellLibraryVtbl ends
        IShellLibrary struct
          lpVtbl POINTER ?
        IShellLibrary ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    DEFAULT_FOLDER_MENU_RESTRICTIONS typedef SDWORD
    DFMR_DEFAULT equ 0
    DFMR_NO_STATIC_VERBS equ 8h
    DFMR_STATIC_VERBS_ONLY equ 10h
    DFMR_NO_RESOURCE_VERBS equ 20h
    DFMR_OPTIN_HANDLERS_ONLY equ 40h
    DFMR_RESOURCE_AND_FOLDER_VERBS_ONLY equ 80h
    DFMR_USE_SPECIFIED_HANDLERS equ 100h
    DFMR_USE_SPECIFIED_VERBS equ 200h
    DFMR_NO_ASYNC_VERBS equ 400h
    DFMR_NO_NATIVECPU_VERBS equ 800h
    DFMR_NO_NONWOW_VERBS equ 1000h

    DEFINE_ENUM_FLAG_OPERATORS(DEFAULT_FOLDER_MENU_RESTRICTIONS)
    externdef __MIDL_itf_shobjidl_core_0000_0158_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0158_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDefaultFolderMenuInitialize_INTERFACE_DEFINED__
      __IDefaultFolderMenuInitialize_INTERFACE_DEFINED__ equ <>
      externdef IID_IDefaultFolderMenuInitialize:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDefaultFolderMenuInitializeVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDefaultFolderMenuInitializeVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDefaultFolderMenuInitialize, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDefaultFolderMenuInitialize
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDefaultFolderMenuInitialize
          DECLSPEC_XFGVIRT(IDefaultFolderMenuInitialize, Initialize)
          STD_METHOD Initialize, :ptr IDefaultFolderMenuInitialize, :HWND, :ptr IContextMenuCB, :PCIDLIST_ABSOLUTE, :ptr IShellFolder, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr IUnknown, :UINT, :ptr HKEY
          DECLSPEC_XFGVIRT(IDefaultFolderMenuInitialize, SetMenuRestrictions)
          STD_METHOD SetMenuRestrictions, :ptr IDefaultFolderMenuInitialize, :DEFAULT_FOLDER_MENU_RESTRICTIONS
          DECLSPEC_XFGVIRT(IDefaultFolderMenuInitialize, GetMenuRestrictions)
          STD_METHOD GetMenuRestrictions, :ptr IDefaultFolderMenuInitialize, :DEFAULT_FOLDER_MENU_RESTRICTIONS, :ptr DEFAULT_FOLDER_MENU_RESTRICTIONS
          DECLSPEC_XFGVIRT(IDefaultFolderMenuInitialize, SetHandlerClsid)
          STD_METHOD SetHandlerClsid, :ptr IDefaultFolderMenuInitialize, :REFCLSID
          ??Interface equ <>
          END_INTERFACE
        IDefaultFolderMenuInitializeVtbl ends
        IDefaultFolderMenuInitialize struct
          lpVtbl POINTER ?
        IDefaultFolderMenuInitialize ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      ACTIVATEOPTIONS typedef SDWORD
      AO_NONE equ 0
      AO_DESIGNMODE equ 1h
      AO_NOERRORUI equ 2h
      AO_NOSPLASHSCREEN equ 4h
      AO_PRELAUNCH equ 2000000h

      DEFINE_ENUM_FLAG_OPERATORS(ACTIVATEOPTIONS)
      externdef __MIDL_itf_shobjidl_core_0000_0159_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0159_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IApplicationActivationManager_INTERFACE_DEFINED__
        __IApplicationActivationManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationActivationManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationActivationManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationActivationManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationActivationManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationActivationManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationActivationManager
            DECLSPEC_XFGVIRT(IApplicationActivationManager, ActivateApplication)
            STD_METHOD ActivateApplication, :ptr IApplicationActivationManager, :LPCWSTR, :LPCWSTR, :ACTIVATEOPTIONS, :ptr DWORD
            DECLSPEC_XFGVIRT(IApplicationActivationManager, ActivateForFile)
            STD_METHOD ActivateForFile, :ptr IApplicationActivationManager, :LPCWSTR, :ptr IShellItemArray, :LPCWSTR, :ptr DWORD
            DECLSPEC_XFGVIRT(IApplicationActivationManager, ActivateForProtocol)
            STD_METHOD ActivateForProtocol, :ptr IApplicationActivationManager, :LPCWSTR, :ptr IShellItemArray, :ptr DWORD
            ??Interface equ <>
            END_INTERFACE
          IApplicationActivationManagerVtbl ends
          IApplicationActivationManager struct
            lpVtbl POINTER ?
          IApplicationActivationManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
      externdef __MIDL_itf_shobjidl_core_0000_0160_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0160_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IVirtualDesktopManager_INTERFACE_DEFINED__
        __IVirtualDesktopManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IVirtualDesktopManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IVirtualDesktopManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IVirtualDesktopManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IVirtualDesktopManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IVirtualDesktopManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IVirtualDesktopManager
            DECLSPEC_XFGVIRT(IVirtualDesktopManager, IsWindowOnCurrentVirtualDesktop)
            STD_METHOD IsWindowOnCurrentVirtualDesktop, :ptr IVirtualDesktopManager, :HWND, :ptr BOOL
            DECLSPEC_XFGVIRT(IVirtualDesktopManager, GetWindowDesktopId)
            STD_METHOD GetWindowDesktopId, :ptr IVirtualDesktopManager, :HWND, :ptr GUID
            DECLSPEC_XFGVIRT(IVirtualDesktopManager, MoveWindowToDesktop)
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
    externdef __MIDL_itf_shobjidl_core_0000_0161_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0161_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ShellCoreObjects_LIBRARY_DEFINED__
      __ShellCoreObjects_LIBRARY_DEFINED__ equ <>
      externdef LIBID_ShellCoreObjects:IID
      externdef CLSID_DesktopWallpaper:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellDesktop:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellFSFolder:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_NetworkPlaces:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellLink:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DriveSizeCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DriveTypeCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FreeSpaceCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SizeCategorizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_PropertiesUI:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_UserNotification:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_TaskbarList:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellItem:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_NamespaceWalker:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FileOperation:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FileOpenDialog:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FileSaveDialog:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_KnownFolderManager:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SharingConfigurationManager:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_NetworkConnections:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ScheduledTasks:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ApplicationAssociationRegistration:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SearchFolderItemFactory:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_OpenControlPanel:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_MailRecipient:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_NetworkExplorerFolder:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DestinationList:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ApplicationDestinations:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ApplicationDocumentLists:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_HomeGroup:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellLibrary:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_AppStartupLink:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_EnumerableObjectCollection:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_FrameworkInputPane:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DefFolderMenu:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_AppVisibility:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_AppShellVerbHandler:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ExecuteUnknown:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_PackageDebugSettings:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SuspensionDependencyManager:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ApplicationActivationManager:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ApplicationDesignModeSettings:CLSID
      ifdef __cplusplus
        ;[...]
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, SHGetTemporaryPropertyForItem, WIN_STD_CALL_CONV,, <:ptr IShellItem, :REFPROPERTYKEY, :ptr PROPVARIANT>, 12
      @DefProto DllImport, SHSetTemporaryPropertyForItem, WIN_STD_CALL_CONV,, <:ptr IShellItem, :REFPROPERTYKEY, :REFPROPVARIANT>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      if (_WIN32_IE ge _WIN32_IE_IE70)
        LIBRARYMANAGEDIALOGOPTIONS typedef SDWORD
        LMD_DEFAULT equ 0
        LMD_ALLOWUNINDEXABLENETWORKLOCATIONS equ 1h

        DEFINE_ENUM_FLAG_OPERATORS(LIBRARYMANAGEDIALOGOPTIONS)
        @DefProto DllImport, SHShowManageLibraryUI, WIN_STD_CALL_CONV,, <:ptr IShellItem, :HWND, :LPCWSTR, :LPCWSTR, :LIBRARYMANAGEDIALOGOPTIONS>, 20
        @DefProto DllImport, SHResolveLibrary, WIN_STD_CALL_CONV,, <:ptr IShellItem>, 4
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef __MIDL_itf_shobjidl_core_0000_0162_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0162_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAssocHandlerInvoker_INTERFACE_DEFINED__
        __IAssocHandlerInvoker_INTERFACE_DEFINED__ equ <>
        externdef IID_IAssocHandlerInvoker:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAssocHandlerInvokerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAssocHandlerInvokerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAssocHandlerInvoker, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAssocHandlerInvoker
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAssocHandlerInvoker
            DECLSPEC_XFGVIRT(IAssocHandlerInvoker, SupportsSelection)
            STD_METHOD SupportsSelection, :ptr IAssocHandlerInvoker
            DECLSPEC_XFGVIRT(IAssocHandlerInvoker, Invoke)
            STD_METHOD Invoke_, :ptr IAssocHandlerInvoker
            ??Interface equ <>
            END_INTERFACE
          IAssocHandlerInvokerVtbl ends
          IAssocHandlerInvoker struct
            lpVtbl POINTER ?
          IAssocHandlerInvoker ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      AHTYPE typedef SDWORD
      AHTYPE_UNDEFINED equ 0
      AHTYPE_USER_APPLICATION equ 8h
      AHTYPE_ANY_APPLICATION equ 10h
      AHTYPE_MACHINEDEFAULT equ 20h
      AHTYPE_PROGID equ 40h
      AHTYPE_APPLICATION equ 80h
      AHTYPE_CLASS_APPLICATION equ 100h
      AHTYPE_ANY_PROGID equ 200h

      DEFINE_ENUM_FLAG_OPERATORS(AHTYPE)
      externdef __MIDL_itf_shobjidl_core_0000_0163_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0163_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAssocHandler_INTERFACE_DEFINED__
        __IAssocHandler_INTERFACE_DEFINED__ equ <>
        externdef IID_IAssocHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAssocHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAssocHandlerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAssocHandler, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAssocHandler
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAssocHandler
            DECLSPEC_XFGVIRT(IAssocHandler, GetName)
            STD_METHOD GetName, :ptr IAssocHandler, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IAssocHandler, GetUIName)
            STD_METHOD GetUIName, :ptr IAssocHandler, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IAssocHandler, GetIconLocation)
            STD_METHOD GetIconLocation, :ptr IAssocHandler, :ptr LPWSTR, :ptr SDWORD
            DECLSPEC_XFGVIRT(IAssocHandler, IsRecommended)
            STD_METHOD IsRecommended, :ptr IAssocHandler
            DECLSPEC_XFGVIRT(IAssocHandler, MakeDefault)
            STD_METHOD MakeDefault, :ptr IAssocHandler, :LPCWSTR
            DECLSPEC_XFGVIRT(IAssocHandler, Invoke)
            STD_METHOD Invoke_, :ptr IAssocHandler, :ptr IDataObject
            DECLSPEC_XFGVIRT(IAssocHandler, CreateInvoker)
            STD_METHOD CreateInvoker, :ptr IAssocHandler, :ptr IDataObject, :ptr ptr IAssocHandlerInvoker
            ??Interface equ <>
            END_INTERFACE
          IAssocHandlerVtbl ends
          IAssocHandler struct
            lpVtbl POINTER ?
          IAssocHandler ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IEnumAssocHandlers_INTERFACE_DEFINED__
        __IEnumAssocHandlers_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumAssocHandlers:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumAssocHandlersVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumAssocHandlersVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumAssocHandlers, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumAssocHandlers
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumAssocHandlers
            DECLSPEC_XFGVIRT(IEnumAssocHandlers, Next)
            STD_METHOD Next, :ptr IEnumAssocHandlers, :ULONG, :ptr ptr IAssocHandler, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          IEnumAssocHandlersVtbl ends
          IEnumAssocHandlers struct
            lpVtbl POINTER ?
          IEnumAssocHandlers ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ASSOC_FILTER typedef SDWORD
      ASSOC_FILTER_NONE equ 0
      ASSOC_FILTER_RECOMMENDED equ 1h

      DEFINE_ENUM_FLAG_OPERATORS(ASSOC_FILTER)
      @DefProto DllImport, SHAssocEnumHandlers, WIN_STD_CALL_CONV,, <:PCWSTR, :ASSOC_FILTER, :ptr ptr IEnumAssocHandlers>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      @DefProto DllImport, SHAssocEnumHandlersForProtocolByApplication, WIN_STD_CALL_CONV,, <:PCWSTR, :REFIID, :ptr ptr>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      externdef __MIDL_itf_shobjidl_core_0000_0165_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0165_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDataObjectProvider_INTERFACE_DEFINED__
        __IDataObjectProvider_INTERFACE_DEFINED__ equ <>
        externdef IID_IDataObjectProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDataObjectProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDataObjectProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDataObjectProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDataObjectProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDataObjectProvider
            DECLSPEC_XFGVIRT(IDataObjectProvider, GetDataObject)
            STD_METHOD GetDataObject, :ptr IDataObjectProvider, :ptr ptr IDataObject
            DECLSPEC_XFGVIRT(IDataObjectProvider, SetDataObject)
            STD_METHOD SetDataObject, :ptr IDataObjectProvider, :ptr IDataObject
            ??Interface equ <>
            END_INTERFACE
          IDataObjectProviderVtbl ends
          IDataObjectProvider struct
            lpVtbl POINTER ?
          IDataObjectProvider ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDataTransferManagerInterop_INTERFACE_DEFINED__
        __IDataTransferManagerInterop_INTERFACE_DEFINED__ equ <>
        externdef IID_IDataTransferManagerInterop:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDataTransferManagerInteropVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDataTransferManagerInteropVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDataTransferManagerInterop, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDataTransferManagerInterop
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDataTransferManagerInterop
            DECLSPEC_XFGVIRT(IDataTransferManagerInterop, GetForWindow)
            STD_METHOD GetForWindow, :ptr IDataTransferManagerInterop, :HWND, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IDataTransferManagerInterop, ShowShareUIForWindow)
            STD_METHOD ShowShareUIForWindow, :ptr IDataTransferManagerInterop, :HWND
            ??Interface equ <>
            END_INTERFACE
          IDataTransferManagerInteropVtbl ends
          IDataTransferManagerInterop struct
            lpVtbl POINTER ?
          IDataTransferManagerInterop ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      externdef __MIDL_itf_shobjidl_core_0000_0167_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0167_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFrameworkInputPaneHandler_INTERFACE_DEFINED__
        __IFrameworkInputPaneHandler_INTERFACE_DEFINED__ equ <>
        externdef IID_IFrameworkInputPaneHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFrameworkInputPaneHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFrameworkInputPaneHandlerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFrameworkInputPaneHandler, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFrameworkInputPaneHandler
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFrameworkInputPaneHandler
            DECLSPEC_XFGVIRT(IFrameworkInputPaneHandler, Showing)
            STD_METHOD Showing, :ptr IFrameworkInputPaneHandler, :ptr RECT, :BOOL
            DECLSPEC_XFGVIRT(IFrameworkInputPaneHandler, Hiding)
            STD_METHOD Hiding, :ptr IFrameworkInputPaneHandler, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IFrameworkInputPaneHandlerVtbl ends
          IFrameworkInputPaneHandler struct
            lpVtbl POINTER ?
          IFrameworkInputPaneHandler ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IFrameworkInputPane_INTERFACE_DEFINED__
        __IFrameworkInputPane_INTERFACE_DEFINED__ equ <>
        externdef IID_IFrameworkInputPane:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFrameworkInputPaneVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFrameworkInputPaneVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFrameworkInputPane, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFrameworkInputPane
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFrameworkInputPane
            DECLSPEC_XFGVIRT(IFrameworkInputPane, Advise)
            STD_METHOD Advise, :ptr IFrameworkInputPane, :ptr IUnknown, :ptr IFrameworkInputPaneHandler, :ptr DWORD
            DECLSPEC_XFGVIRT(IFrameworkInputPane, AdviseWithHWND)
            STD_METHOD AdviseWithHWND, :ptr IFrameworkInputPane, :HWND, :ptr IFrameworkInputPaneHandler, :ptr DWORD
            DECLSPEC_XFGVIRT(IFrameworkInputPane, Unadvise)
            STD_METHOD Unadvise, :ptr IFrameworkInputPane, :DWORD
            DECLSPEC_XFGVIRT(IFrameworkInputPane, Location)
            STD_METHOD Location, :ptr IFrameworkInputPane, :ptr RECT
            ??Interface equ <>
            END_INTERFACE
          IFrameworkInputPaneVtbl ends
          IFrameworkInputPane struct
            lpVtbl POINTER ?
          IFrameworkInputPane ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef PROP_CONTRACT_DELEGATE
        PROP_CONTRACT_DELEGATE equ <L("ContractDelegate")>
      endif
      SetContractDelegateWindow proto WIN_STD_CALL_CONV :HWND, :HWND
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      MONITOR_APP_VISIBILITY typedef SDWORD
      MAV_UNKNOWN equ 0
      MAV_NO_APP_VISIBLE equ 1
      MAV_APP_VISIBLE equ 2

      externdef __MIDL_itf_shobjidl_core_0000_0169_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0169_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAppVisibilityEvents_INTERFACE_DEFINED__
        __IAppVisibilityEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IAppVisibilityEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAppVisibilityEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAppVisibilityEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAppVisibilityEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAppVisibilityEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAppVisibilityEvents
            DECLSPEC_XFGVIRT(IAppVisibilityEvents, AppVisibilityOnMonitorChanged)
            STD_METHOD AppVisibilityOnMonitorChanged, :ptr IAppVisibilityEvents, :HMONITOR, :MONITOR_APP_VISIBILITY, :MONITOR_APP_VISIBILITY
            DECLSPEC_XFGVIRT(IAppVisibilityEvents, LauncherVisibilityChange)
            STD_METHOD LauncherVisibilityChange, :ptr IAppVisibilityEvents, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IAppVisibilityEventsVtbl ends
          IAppVisibilityEvents struct
            lpVtbl POINTER ?
          IAppVisibilityEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAppVisibility_INTERFACE_DEFINED__
        __IAppVisibility_INTERFACE_DEFINED__ equ <>
        externdef IID_IAppVisibility:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAppVisibilityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAppVisibilityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAppVisibility, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAppVisibility
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAppVisibility
            DECLSPEC_XFGVIRT(IAppVisibility, GetAppVisibilityOnMonitor)
            STD_METHOD GetAppVisibilityOnMonitor, :ptr IAppVisibility, :HMONITOR, :ptr MONITOR_APP_VISIBILITY
            DECLSPEC_XFGVIRT(IAppVisibility, IsLauncherVisible)
            STD_METHOD IsLauncherVisible, :ptr IAppVisibility, :ptr BOOL
            DECLSPEC_XFGVIRT(IAppVisibility, Advise)
            STD_METHOD Advise, :ptr IAppVisibility, :ptr IAppVisibilityEvents, :ptr DWORD
            DECLSPEC_XFGVIRT(IAppVisibility, Unadvise)
            STD_METHOD Unadvise, :ptr IAppVisibility, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IAppVisibilityVtbl ends
          IAppVisibility struct
            lpVtbl POINTER ?
          IAppVisibility ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifdef MIDL_PASS
        ;[...]
      endif
      PACKAGE_EXECUTION_STATE typedef SDWORD
      PES_UNKNOWN equ 0
      PES_RUNNING equ 1
      PES_SUSPENDING equ 2
      PES_SUSPENDED equ 3
      PES_TERMINATED equ 4

      externdef __MIDL_itf_shobjidl_core_0000_0171_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0171_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPackageExecutionStateChangeNotification_INTERFACE_DEFINED__
        __IPackageExecutionStateChangeNotification_INTERFACE_DEFINED__ equ <>
        externdef IID_IPackageExecutionStateChangeNotification:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPackageExecutionStateChangeNotificationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPackageExecutionStateChangeNotificationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPackageExecutionStateChangeNotification, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPackageExecutionStateChangeNotification
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPackageExecutionStateChangeNotification
            DECLSPEC_XFGVIRT(IPackageExecutionStateChangeNotification, OnStateChanged)
            STD_METHOD OnStateChanged, :ptr IPackageExecutionStateChangeNotification, :LPCWSTR, :PACKAGE_EXECUTION_STATE
            ??Interface equ <>
            END_INTERFACE
          IPackageExecutionStateChangeNotificationVtbl ends
          IPackageExecutionStateChangeNotification struct
            lpVtbl POINTER ?
          IPackageExecutionStateChangeNotification ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPackageDebugSettings_INTERFACE_DEFINED__
        __IPackageDebugSettings_INTERFACE_DEFINED__ equ <>
        externdef IID_IPackageDebugSettings:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPackageDebugSettingsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPackageDebugSettingsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPackageDebugSettings, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPackageDebugSettings
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPackageDebugSettings
            DECLSPEC_XFGVIRT(IPackageDebugSettings, EnableDebugging)
            STD_METHOD EnableDebugging, :ptr IPackageDebugSettings, :LPCWSTR, :LPCWSTR, :PZZWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, DisableDebugging)
            STD_METHOD DisableDebugging, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, Suspend)
            STD_METHOD Suspend, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, Resume)
            STD_METHOD Resume, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, TerminateAllProcesses)
            STD_METHOD TerminateAllProcesses, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, SetTargetSessionId)
            STD_METHOD SetTargetSessionId, :ptr IPackageDebugSettings, :ULONG
            DECLSPEC_XFGVIRT(IPackageDebugSettings, EnumerateBackgroundTasks)
            STD_METHOD EnumerateBackgroundTasks, :ptr IPackageDebugSettings, :LPCWSTR, :ptr ULONG, :ptr LPCGUID, :ptr ptr LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, ActivateBackgroundTask)
            STD_METHOD ActivateBackgroundTask, :ptr IPackageDebugSettings, :LPCGUID
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StartServicing)
            STD_METHOD StartServicing, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StopServicing)
            STD_METHOD StopServicing, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StartSessionRedirection)
            STD_METHOD StartSessionRedirection, :ptr IPackageDebugSettings, :LPCWSTR, :ULONG
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StopSessionRedirection)
            STD_METHOD StopSessionRedirection, :ptr IPackageDebugSettings, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, GetPackageExecutionState)
            STD_METHOD GetPackageExecutionState, :ptr IPackageDebugSettings, :LPCWSTR, :ptr PACKAGE_EXECUTION_STATE
            DECLSPEC_XFGVIRT(IPackageDebugSettings, RegisterForPackageStateChanges)
            STD_METHOD RegisterForPackageStateChanges, :ptr IPackageDebugSettings, :LPCWSTR, :ptr IPackageExecutionStateChangeNotification, :ptr DWORD
            DECLSPEC_XFGVIRT(IPackageDebugSettings, UnregisterForPackageStateChanges)
            STD_METHOD UnregisterForPackageStateChanges, :ptr IPackageDebugSettings, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IPackageDebugSettingsVtbl ends
          IPackageDebugSettings struct
            lpVtbl POINTER ?
          IPackageDebugSettings ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPackageDebugSettings2_INTERFACE_DEFINED__
        __IPackageDebugSettings2_INTERFACE_DEFINED__ equ <>
        externdef IID_IPackageDebugSettings2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPackageDebugSettings2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPackageDebugSettings2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPackageDebugSettings2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPackageDebugSettings2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPackageDebugSettings2
            DECLSPEC_XFGVIRT(IPackageDebugSettings, EnableDebugging)
            STD_METHOD EnableDebugging, :ptr IPackageDebugSettings2, :LPCWSTR, :LPCWSTR, :PZZWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, DisableDebugging)
            STD_METHOD DisableDebugging, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, Suspend)
            STD_METHOD Suspend, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, Resume)
            STD_METHOD Resume, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, TerminateAllProcesses)
            STD_METHOD TerminateAllProcesses, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, SetTargetSessionId)
            STD_METHOD SetTargetSessionId, :ptr IPackageDebugSettings2, :ULONG
            DECLSPEC_XFGVIRT(IPackageDebugSettings, EnumerateBackgroundTasks)
            STD_METHOD EnumerateBackgroundTasks, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr ULONG, :ptr LPCGUID, :ptr ptr LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, ActivateBackgroundTask)
            STD_METHOD ActivateBackgroundTask, :ptr IPackageDebugSettings2, :LPCGUID
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StartServicing)
            STD_METHOD StartServicing, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StopServicing)
            STD_METHOD StopServicing, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StartSessionRedirection)
            STD_METHOD StartSessionRedirection, :ptr IPackageDebugSettings2, :LPCWSTR, :ULONG
            DECLSPEC_XFGVIRT(IPackageDebugSettings, StopSessionRedirection)
            STD_METHOD StopSessionRedirection, :ptr IPackageDebugSettings2, :LPCWSTR
            DECLSPEC_XFGVIRT(IPackageDebugSettings, GetPackageExecutionState)
            STD_METHOD GetPackageExecutionState, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr PACKAGE_EXECUTION_STATE
            DECLSPEC_XFGVIRT(IPackageDebugSettings, RegisterForPackageStateChanges)
            STD_METHOD RegisterForPackageStateChanges, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr IPackageExecutionStateChangeNotification, :ptr DWORD
            DECLSPEC_XFGVIRT(IPackageDebugSettings, UnregisterForPackageStateChanges)
            STD_METHOD UnregisterForPackageStateChanges, :ptr IPackageDebugSettings2, :DWORD
            DECLSPEC_XFGVIRT(IPackageDebugSettings2, EnumerateApps)
            STD_METHOD EnumerateApps, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr ULONG, :ptr ptr LPWSTR, :ptr ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IPackageDebugSettings2Vtbl ends
          IPackageDebugSettings2 struct
            lpVtbl POINTER ?
          IPackageDebugSettings2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISuspensionDependencyManager_INTERFACE_DEFINED__
        __ISuspensionDependencyManager_INTERFACE_DEFINED__ equ <>
        externdef IID_ISuspensionDependencyManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISuspensionDependencyManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISuspensionDependencyManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISuspensionDependencyManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISuspensionDependencyManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISuspensionDependencyManager
            DECLSPEC_XFGVIRT(ISuspensionDependencyManager, RegisterAsChild)
            STD_METHOD RegisterAsChild, :ptr ISuspensionDependencyManager, :HANDLE
            DECLSPEC_XFGVIRT(ISuspensionDependencyManager, GroupChildWithParent)
            STD_METHOD GroupChildWithParent, :ptr ISuspensionDependencyManager, :HANDLE
            DECLSPEC_XFGVIRT(ISuspensionDependencyManager, UngroupChildFromParent)
            STD_METHOD UngroupChildFromParent, :ptr ISuspensionDependencyManager, :HANDLE
            ??Interface equ <>
            END_INTERFACE
          ISuspensionDependencyManagerVtbl ends
          ISuspensionDependencyManager struct
            lpVtbl POINTER ?
          ISuspensionDependencyManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      AHE_TYPE typedef SDWORD
      AHE_DESKTOP equ 0
      AHE_IMMERSIVE equ 1

      externdef __MIDL_itf_shobjidl_core_0000_0175_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0175_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IExecuteCommandApplicationHostEnvironment_INTERFACE_DEFINED__
        __IExecuteCommandApplicationHostEnvironment_INTERFACE_DEFINED__ equ <>
        externdef IID_IExecuteCommandApplicationHostEnvironment:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IExecuteCommandApplicationHostEnvironmentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IExecuteCommandApplicationHostEnvironmentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IExecuteCommandApplicationHostEnvironment, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IExecuteCommandApplicationHostEnvironment
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IExecuteCommandApplicationHostEnvironment
            DECLSPEC_XFGVIRT(IExecuteCommandApplicationHostEnvironment, GetValue)
            STD_METHOD GetValue, :ptr IExecuteCommandApplicationHostEnvironment, :ptr AHE_TYPE
            ??Interface equ <>
            END_INTERFACE
          IExecuteCommandApplicationHostEnvironmentVtbl ends
          IExecuteCommandApplicationHostEnvironment struct
            lpVtbl POINTER ?
          IExecuteCommandApplicationHostEnvironment ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      EC_HOST_UI_MODE typedef SDWORD
      ECHUIM_DESKTOP equ 0
      ECHUIM_IMMERSIVE equ
      ECHUIM_SYSTEM_LAUNCHER equ

      externdef __MIDL_itf_shobjidl_core_0000_0176_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0176_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IExecuteCommandHost_INTERFACE_DEFINED__
        __IExecuteCommandHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IExecuteCommandHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IExecuteCommandHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IExecuteCommandHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IExecuteCommandHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IExecuteCommandHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IExecuteCommandHost
            DECLSPEC_XFGVIRT(IExecuteCommandHost, GetUIMode)
            STD_METHOD GetUIMode, :ptr IExecuteCommandHost, :ptr EC_HOST_UI_MODE
            ??Interface equ <>
            END_INTERFACE
          IExecuteCommandHostVtbl ends
          IExecuteCommandHost struct
            lpVtbl POINTER ?
          IExecuteCommandHost ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_ExecuteCommandHost equ <IID_IExecuteCommandHost>
      APPLICATION_VIEW_STATE typedef SDWORD
      AVS_FULLSCREEN_LANDSCAPE equ 0
      AVS_FILLED equ
      AVS_SNAPPED equ
      AVS_FULLSCREEN_PORTRAIT equ

      EDGE_GESTURE_KIND typedef SDWORD
      EGK_TOUCH equ 0
      EGK_KEYBOARD equ
      EGK_MOUSE equ

      externdef __MIDL_itf_shobjidl_core_0000_0177_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0177_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IApplicationDesignModeSettings_INTERFACE_DEFINED__
        __IApplicationDesignModeSettings_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationDesignModeSettings:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDesignModeSettingsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDesignModeSettingsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationDesignModeSettings, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDesignModeSettings
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDesignModeSettings
            DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, SetNativeDisplaySize)
            STD_METHOD SetNativeDisplaySize, :ptr IApplicationDesignModeSettings, :SIZE_
            DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, SetScaleFactor)
            STD_METHOD SetScaleFactor, :ptr IApplicationDesignModeSettings, :DEVICE_SCALE_FACTOR
            DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, SetApplicationViewState)
            STD_METHOD SetApplicationViewState, :ptr IApplicationDesignModeSettings, :APPLICATION_VIEW_STATE
            DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, ComputeApplicationSize)
            STD_METHOD ComputeApplicationSize, :ptr IApplicationDesignModeSettings, :ptr SIZE_
            DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, IsApplicationViewStateSupported)
            STD_METHOD IsApplicationViewStateSupported, :ptr IApplicationDesignModeSettings, :APPLICATION_VIEW_STATE, :SIZE_, :DEVICE_SCALE_FACTOR, :ptr BOOL
            DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, TriggerEdgeGesture)
            STD_METHOD TriggerEdgeGesture, :ptr IApplicationDesignModeSettings, :EDGE_GESTURE_KIND
            ??Interface equ <>
            END_INTERFACE
          IApplicationDesignModeSettingsVtbl ends
          IApplicationDesignModeSettings struct
            lpVtbl POINTER ?
          IApplicationDesignModeSettings ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      NATIVE_DISPLAY_ORIENTATION typedef SDWORD
      NDO_LANDSCAPE equ 0
      NDO_PORTRAIT equ

      APPLICATION_VIEW_ORIENTATION typedef SDWORD
      AVO_LANDSCAPE equ 0
      AVO_PORTRAIT equ

      ADJACENT_DISPLAY_EDGES typedef SDWORD
      ADE_NONE equ 0
      ADE_LEFT equ 1h
      ADE_RIGHT equ 2h

      DEFINE_ENUM_FLAG_OPERATORS(ADJACENT_DISPLAY_EDGES)
      if (NTDDI_VERSION ge NTDDI_WINBLUE)
        APPLICATION_VIEW_MIN_WIDTH typedef SDWORD
        AVMW_DEFAULT equ 0
        AVMW_320 equ 1
        AVMW_500 equ 2

        externdef __MIDL_itf_shobjidl_core_0000_0178_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0178_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IApplicationDesignModeSettings2_INTERFACE_DEFINED__
          __IApplicationDesignModeSettings2_INTERFACE_DEFINED__ equ <>
          externdef IID_IApplicationDesignModeSettings2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IApplicationDesignModeSettings2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IApplicationDesignModeSettings2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IApplicationDesignModeSettings2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IApplicationDesignModeSettings2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IApplicationDesignModeSettings2
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, SetNativeDisplaySize)
              STD_METHOD SetNativeDisplaySize, :ptr IApplicationDesignModeSettings2, :SIZE_
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, SetScaleFactor)
              STD_METHOD SetScaleFactor, :ptr IApplicationDesignModeSettings2, :DEVICE_SCALE_FACTOR
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, SetApplicationViewState)
              STD_METHOD SetApplicationViewState, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_STATE
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, ComputeApplicationSize)
              STD_METHOD ComputeApplicationSize, :ptr IApplicationDesignModeSettings2, :ptr SIZE_
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, IsApplicationViewStateSupported)
              STD_METHOD IsApplicationViewStateSupported, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_STATE, :SIZE_, :DEVICE_SCALE_FACTOR, :ptr BOOL
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings, TriggerEdgeGesture)
              STD_METHOD TriggerEdgeGesture, :ptr IApplicationDesignModeSettings2, :EDGE_GESTURE_KIND
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, SetNativeDisplayOrientation)
              STD_METHOD SetNativeDisplayOrientation, :ptr IApplicationDesignModeSettings2, :NATIVE_DISPLAY_ORIENTATION
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, SetApplicationViewOrientation)
              STD_METHOD SetApplicationViewOrientation, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_ORIENTATION
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, SetAdjacentDisplayEdges)
              STD_METHOD SetAdjacentDisplayEdges, :ptr IApplicationDesignModeSettings2, :ADJACENT_DISPLAY_EDGES
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, SetIsOnLockScreen)
              STD_METHOD SetIsOnLockScreen, :ptr IApplicationDesignModeSettings2, :BOOL
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, SetApplicationViewMinWidth)
              STD_METHOD SetApplicationViewMinWidth, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_MIN_WIDTH
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, GetApplicationSizeBounds)
              STD_METHOD GetApplicationSizeBounds, :ptr IApplicationDesignModeSettings2, :ptr SIZE_, :ptr SIZE_
              DECLSPEC_XFGVIRT(IApplicationDesignModeSettings2, GetApplicationViewOrientation)
              STD_METHOD GetApplicationViewOrientation, :ptr IApplicationDesignModeSettings2, :SIZE_, :ptr APPLICATION_VIEW_ORIENTATION
              ??Interface equ <>
              END_INTERFACE
            IApplicationDesignModeSettings2Vtbl ends
            IApplicationDesignModeSettings2 struct
              lpVtbl POINTER ?
            IApplicationDesignModeSettings2 ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        DEFINE_GUID SID_URLExecutionContext, 0FB5F8EBCh, 0BBB6h, 4D10h, 0A4h, 61h, 77h, 72h, 91h, 0A0h, 90h, 30h
        STR_TAB_REUSE_IDENTIFIER equ <L("Tab Reuse Identifier")>
        STR_REFERRER_IDENTIFIER equ <L("Referrer Identifier")>
        externdef __MIDL_itf_shobjidl_core_0000_0179_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0179_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchTargetMonitor_INTERFACE_DEFINED__
          __ILaunchTargetMonitor_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchTargetMonitor:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchTargetMonitorVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchTargetMonitorVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr ILaunchTargetMonitor, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr ILaunchTargetMonitor
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr ILaunchTargetMonitor
              DECLSPEC_XFGVIRT(ILaunchTargetMonitor, GetMonitor)
              STD_METHOD GetMonitor, :ptr ILaunchTargetMonitor, :ptr HMONITOR
              ??Interface equ <>
              END_INTERFACE
            ILaunchTargetMonitorVtbl ends
            ILaunchTargetMonitor struct
              lpVtbl POINTER ?
            ILaunchTargetMonitor ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        SID_LaunchTargetMonitor equ <__uuidof((struct __declspec(uuid("8D547FA1-CC45-40C8-B7C1-D48C183F13F3")) LaunchTargetMonitor *) 0)>
        APPLICATION_VIEW_SIZE_PREFERENCE typedef SDWORD
        AVSP_DEFAULT equ 0
        AVSP_USE_LESS equ 1
        AVSP_USE_HALF equ 2
        AVSP_USE_MORE equ 3
        AVSP_USE_MINIMUM equ 4
        AVSP_USE_NONE equ 5
        AVSP_CUSTOM equ 6

        externdef __MIDL_itf_shobjidl_core_0000_0180_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0180_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchSourceViewSizePreference_INTERFACE_DEFINED__
          __ILaunchSourceViewSizePreference_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchSourceViewSizePreference:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchSourceViewSizePreferenceVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchSourceViewSizePreferenceVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr ILaunchSourceViewSizePreference, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr ILaunchSourceViewSizePreference
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr ILaunchSourceViewSizePreference
              DECLSPEC_XFGVIRT(ILaunchSourceViewSizePreference, GetSourceViewToPosition)
              STD_METHOD GetSourceViewToPosition, :ptr ILaunchSourceViewSizePreference, :ptr HWND
              DECLSPEC_XFGVIRT(ILaunchSourceViewSizePreference, GetSourceViewSizePreference)
              STD_METHOD GetSourceViewSizePreference, :ptr ILaunchSourceViewSizePreference, :ptr APPLICATION_VIEW_SIZE_PREFERENCE
              ??Interface equ <>
              END_INTERFACE
            ILaunchSourceViewSizePreferenceVtbl ends
            ILaunchSourceViewSizePreference struct
              lpVtbl POINTER ?
            ILaunchSourceViewSizePreference ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        DEFINE_GUID SID_LaunchSourceViewSizePreference, 80605492h, 67d9h, 414fh, 0afh, 89h, 0a1h, 0cdh, 0f1h, 24h, 2bh, 0c1h
        externdef __MIDL_itf_shobjidl_core_0000_0181_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0181_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchTargetViewSizePreference_INTERFACE_DEFINED__
          __ILaunchTargetViewSizePreference_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchTargetViewSizePreference:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchTargetViewSizePreferenceVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchTargetViewSizePreferenceVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr ILaunchTargetViewSizePreference, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr ILaunchTargetViewSizePreference
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr ILaunchTargetViewSizePreference
              DECLSPEC_XFGVIRT(ILaunchTargetViewSizePreference, GetTargetViewSizePreference)
              STD_METHOD GetTargetViewSizePreference, :ptr ILaunchTargetViewSizePreference, :ptr APPLICATION_VIEW_SIZE_PREFERENCE
              ??Interface equ <>
              END_INTERFACE
            ILaunchTargetViewSizePreferenceVtbl ends
            ILaunchTargetViewSizePreference struct
              lpVtbl POINTER ?
            ILaunchTargetViewSizePreference ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        DEFINE_GUID SID_LaunchTargetViewSizePreference, 26db2472h, 0b7b7h, 406bh, 97h, 2h, 73h, 0ah, 4eh, 20h, 0d3h, 0bfh
        externdef __MIDL_itf_shobjidl_core_0000_0182_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0182_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchSourceAppUserModelId_INTERFACE_DEFINED__
          __ILaunchSourceAppUserModelId_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchSourceAppUserModelId:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchSourceAppUserModelIdVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchSourceAppUserModelIdVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr ILaunchSourceAppUserModelId, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr ILaunchSourceAppUserModelId
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr ILaunchSourceAppUserModelId
              DECLSPEC_XFGVIRT(ILaunchSourceAppUserModelId, GetAppUserModelId)
              STD_METHOD GetAppUserModelId, :ptr ILaunchSourceAppUserModelId, :ptr LPWSTR
              ??Interface equ <>
              END_INTERFACE
            ILaunchSourceAppUserModelIdVtbl ends
            ILaunchSourceAppUserModelId struct
              lpVtbl POINTER ?
            ILaunchSourceAppUserModelId ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        DEFINE_GUID SID_LaunchSourceAppUserModelId, 2ce78010h, 74dbh, 48bch, 9ch, 6ah, 10h, 0f3h, 72h, 49h, 57h, 23h
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0183_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0183_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInitializeWithWindow_INTERFACE_DEFINED__
        __IInitializeWithWindow_INTERFACE_DEFINED__ equ <>
        externdef IID_IInitializeWithWindow:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInitializeWithWindowVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInitializeWithWindowVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInitializeWithWindow, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInitializeWithWindow
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInitializeWithWindow
            DECLSPEC_XFGVIRT(IInitializeWithWindow, Initialize)
            STD_METHOD Initialize, :ptr IInitializeWithWindow, :HWND
            ??Interface equ <>
            END_INTERFACE
          IInitializeWithWindowVtbl ends
          IInitializeWithWindow struct
            lpVtbl POINTER ?
          IInitializeWithWindow ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IHandlerInfo_INTERFACE_DEFINED__
        __IHandlerInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IHandlerInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHandlerInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHandlerInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHandlerInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHandlerInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHandlerInfo
            DECLSPEC_XFGVIRT(IHandlerInfo, GetApplicationDisplayName)
            STD_METHOD GetApplicationDisplayName, :ptr IHandlerInfo, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHandlerInfo, GetApplicationPublisher)
            STD_METHOD GetApplicationPublisher, :ptr IHandlerInfo, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHandlerInfo, GetApplicationIconReference)
            STD_METHOD GetApplicationIconReference, :ptr IHandlerInfo, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IHandlerInfoVtbl ends
          IHandlerInfo struct
            lpVtbl POINTER ?
          IHandlerInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_HandlerInfo equ <IID_IHandlerInfo>
      externdef __MIDL_itf_shobjidl_core_0000_0185_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0185_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHandlerInfo2_INTERFACE_DEFINED__
        __IHandlerInfo2_INTERFACE_DEFINED__ equ <>
        externdef IID_IHandlerInfo2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHandlerInfo2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHandlerInfo2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHandlerInfo2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHandlerInfo2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHandlerInfo2
            DECLSPEC_XFGVIRT(IHandlerInfo, GetApplicationDisplayName)
            STD_METHOD GetApplicationDisplayName, :ptr IHandlerInfo2, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHandlerInfo, GetApplicationPublisher)
            STD_METHOD GetApplicationPublisher, :ptr IHandlerInfo2, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHandlerInfo, GetApplicationIconReference)
            STD_METHOD GetApplicationIconReference, :ptr IHandlerInfo2, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHandlerInfo2, GetApplicationId)
            STD_METHOD GetApplicationId, :ptr IHandlerInfo2, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          IHandlerInfo2Vtbl ends
          IHandlerInfo2 struct
            lpVtbl POINTER ?
          IHandlerInfo2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IHandlerActivationHost_INTERFACE_DEFINED__
        __IHandlerActivationHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IHandlerActivationHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHandlerActivationHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHandlerActivationHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHandlerActivationHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHandlerActivationHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHandlerActivationHost
            DECLSPEC_XFGVIRT(IHandlerActivationHost, BeforeCoCreateInstance)
            STD_METHOD BeforeCoCreateInstance, :ptr IHandlerActivationHost, :REFCLSID, :ptr IShellItemArray, :ptr IHandlerInfo
            DECLSPEC_XFGVIRT(IHandlerActivationHost, BeforeCreateProcess)
            STD_METHOD BeforeCreateProcess, :ptr IHandlerActivationHost, :LPCWSTR, :LPCWSTR, :ptr IHandlerInfo
            ??Interface equ <>
            END_INTERFACE
          IHandlerActivationHostVtbl ends
          IHandlerActivationHost struct
            lpVtbl POINTER ?
          IHandlerActivationHost ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SID_SHandlerActivationHost equ <IID_IHandlerActivationHost>
      if (NTDDI_VERSION ge NTDDI_WIN10)
        externdef __MIDL_itf_shobjidl_core_0000_0187_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0187_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IAppActivationUIInfo_INTERFACE_DEFINED__
          __IAppActivationUIInfo_INTERFACE_DEFINED__ equ <>
          externdef IID_IAppActivationUIInfo:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IAppActivationUIInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IAppActivationUIInfoVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IAppActivationUIInfo, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IAppActivationUIInfo
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IAppActivationUIInfo
              DECLSPEC_XFGVIRT(IAppActivationUIInfo, GetMonitor)
              STD_METHOD GetMonitor, :ptr IAppActivationUIInfo, :ptr HMONITOR
              DECLSPEC_XFGVIRT(IAppActivationUIInfo, GetInvokePoint)
              STD_METHOD GetInvokePoint, :ptr IAppActivationUIInfo, :ptr POINT
              DECLSPEC_XFGVIRT(IAppActivationUIInfo, GetShowCommand)
              STD_METHOD GetShowCommand, :ptr IAppActivationUIInfo, :ptr SDWORD
              DECLSPEC_XFGVIRT(IAppActivationUIInfo, GetShowUI)
              STD_METHOD GetShowUI, :ptr IAppActivationUIInfo, :ptr BOOL
              DECLSPEC_XFGVIRT(IAppActivationUIInfo, GetKeyState)
              STD_METHOD GetKeyState, :ptr IAppActivationUIInfo, :ptr DWORD
              ??Interface equ <>
              END_INTERFACE
            IAppActivationUIInfoVtbl ends
            IAppActivationUIInfo struct
              lpVtbl POINTER ?
            IAppActivationUIInfo ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        SID_AppActivationUIInfo equ <IID_IAppActivationUIInfo>
      endif
      DEFINE_GUID SID_ShellExecuteNamedPropertyStore, 0eb84ada2h, 00ffh, 4992h, 83h, 24h, 0edh, 5ch, 0e0h, 61h, 0cbh, 29h
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      FLYOUT_PLACEMENT typedef SDWORD
      FP_DEFAULT equ 0
      FP_ABOVE equ
      FP_BELOW equ
      FP_LEFT equ
      FP_RIGHT equ

      externdef __MIDL_itf_shobjidl_core_0000_0188_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0188_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IContactManagerInterop_INTERFACE_DEFINED__
        __IContactManagerInterop_INTERFACE_DEFINED__ equ <>
        externdef IID_IContactManagerInterop:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IContactManagerInteropVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IContactManagerInteropVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IContactManagerInterop, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IContactManagerInterop
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IContactManagerInterop
            DECLSPEC_XFGVIRT(IContactManagerInterop, ShowContactCardForWindow)
            STD_METHOD ShowContactCardForWindow, :ptr IContactManagerInterop, :HWND, :ptr IUnknown, :ptr RECT, :FLYOUT_PLACEMENT
            ??Interface equ <>
            END_INTERFACE
          IContactManagerInteropVtbl ends
          IContactManagerInterop struct
            lpVtbl POINTER ?
          IContactManagerInterop ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0189_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0189_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellIconOverlayIdentifier_INTERFACE_DEFINED__
      __IShellIconOverlayIdentifier_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellIconOverlayIdentifier:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellIconOverlayIdentifierVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellIconOverlayIdentifierVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IShellIconOverlayIdentifier, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IShellIconOverlayIdentifier
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IShellIconOverlayIdentifier
          DECLSPEC_XFGVIRT(IShellIconOverlayIdentifier, IsMemberOf)
          STD_METHOD IsMemberOf, :ptr IShellIconOverlayIdentifier, :LPCWSTR, :DWORD
          DECLSPEC_XFGVIRT(IShellIconOverlayIdentifier, GetOverlayInfo)
          STD_METHOD GetOverlayInfo, :ptr IShellIconOverlayIdentifier, :LPWSTR, :SDWORD, :ptr SDWORD, :ptr DWORD
          DECLSPEC_XFGVIRT(IShellIconOverlayIdentifier, GetPriority)
          STD_METHOD GetPriority, :ptr IShellIconOverlayIdentifier, :ptr SDWORD
          ??Interface equ <>
          END_INTERFACE
        IShellIconOverlayIdentifierVtbl ends
        IShellIconOverlayIdentifier struct
          lpVtbl POINTER ?
        IShellIconOverlayIdentifier ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ISIOI_ICONFILE equ 00000001h
    ISIOI_ICONINDEX equ 00000002h
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      externdef __MIDL_itf_shobjidl_core_0000_0190_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0190_v0_0_s_ifspec:RPC_IF_HANDLE
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
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBannerNotificationHandler, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBannerNotificationHandler
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBannerNotificationHandler
            DECLSPEC_XFGVIRT(IBannerNotificationHandler, OnBannerEvent)
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
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SORT_ORDER_TYPE typedef SDWORD
      SOT_DEFAULT equ 0
      SOT_IGNORE_FOLDERNESS equ 1

      externdef __MIDL_itf_shobjidl_core_0000_0191_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0191_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISortColumnArray_INTERFACE_DEFINED__
        __ISortColumnArray_INTERFACE_DEFINED__ equ <>
        externdef IID_ISortColumnArray:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISortColumnArrayVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISortColumnArrayVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISortColumnArray, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISortColumnArray
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISortColumnArray
            DECLSPEC_XFGVIRT(ISortColumnArray, GetCount)
            STD_METHOD GetCount, :ptr ISortColumnArray, :ptr UINT
            DECLSPEC_XFGVIRT(ISortColumnArray, GetAt)
            STD_METHOD GetAt, :ptr ISortColumnArray, :UINT, :ptr SORTCOLUMN
            DECLSPEC_XFGVIRT(ISortColumnArray, GetSortType)
            STD_METHOD GetSortType, :ptr ISortColumnArray, :ptr SORT_ORDER_TYPE
            ??Interface equ <>
            END_INTERFACE
          ISortColumnArrayVtbl ends
          ISortColumnArray struct
            lpVtbl POINTER ?
          ISortColumnArray ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shobjidl_core_0000_0192_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0192_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertyKeyStore_INTERFACE_DEFINED__
      __IPropertyKeyStore_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyKeyStore:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyKeyStoreVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyKeyStoreVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyKeyStore, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyKeyStore
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyKeyStore
          DECLSPEC_XFGVIRT(IPropertyKeyStore, GetKeyCount)
          STD_METHOD GetKeyCount, :ptr IPropertyKeyStore, :ptr SDWORD
          DECLSPEC_XFGVIRT(IPropertyKeyStore, GetKeyAt)
          STD_METHOD GetKeyAt, :ptr IPropertyKeyStore, :SDWORD, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyKeyStore, AppendKey)
          STD_METHOD AppendKey, :ptr IPropertyKeyStore, :REFPROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyKeyStore, DeleteKey)
          STD_METHOD DeleteKey, :ptr IPropertyKeyStore, :SDWORD
          DECLSPEC_XFGVIRT(IPropertyKeyStore, IsKeyInStore)
          STD_METHOD IsKeyInStore, :ptr IPropertyKeyStore, :REFPROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyKeyStore, RemoveKey)
          STD_METHOD RemoveKey, :ptr IPropertyKeyStore, :REFPROPERTYKEY
          ??Interface equ <>
          END_INTERFACE
        IPropertyKeyStoreVtbl ends
        IPropertyKeyStore struct
          lpVtbl POINTER ?
        IPropertyKeyStore ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  externdef __MIDL_itf_shobjidl_core_0000_0193_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shobjidl_core_0000_0193_v0_0_s_ifspec:RPC_IF_HANDLE
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  HACCEL_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HACCEL
  HACCEL_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HACCEL
  HBITMAP_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HBITMAP
  HBITMAP_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HBITMAP
  HGLOBAL_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HGLOBAL
  HGLOBAL_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HGLOBAL
  HICON_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HICON
  HICON_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HICON
  HMENU_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMENU
  HMENU_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMENU
  HMONITOR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMONITOR
  HMONITOR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMONITOR
  HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  LPSAFEARRAY_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  PCIDLIST_ABSOLUTE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCIDLIST_ABSOLUTE
  PCUIDLIST_RELATIVE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCUIDLIST_RELATIVE
  PCUIDLIST_RELATIVE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUIDLIST_RELATIVE
  PCUIDLIST_RELATIVE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUIDLIST_RELATIVE
  PCUIDLIST_RELATIVE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCUIDLIST_RELATIVE
  PCUITEMID_CHILD_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCUITEMID_CHILD
  PCUITEMID_CHILD_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUITEMID_CHILD
  PCUITEMID_CHILD_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUITEMID_CHILD
  PCUITEMID_CHILD_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCUITEMID_CHILD
  PIDLIST_ABSOLUTE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PIDLIST_ABSOLUTE
  PIDLIST_ABSOLUTE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_ABSOLUTE
  PIDLIST_ABSOLUTE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_ABSOLUTE
  PIDLIST_ABSOLUTE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PIDLIST_ABSOLUTE
  PIDLIST_RELATIVE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PIDLIST_RELATIVE
  PIDLIST_RELATIVE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_RELATIVE
  PIDLIST_RELATIVE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_RELATIVE
  PIDLIST_RELATIVE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PIDLIST_RELATIVE
  PITEMID_CHILD_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PITEMID_CHILD
  VARIANT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  HACCEL_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HACCEL
  HACCEL_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HACCEL
  HBITMAP_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HBITMAP
  HBITMAP_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HBITMAP
  HGLOBAL_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HGLOBAL
  HGLOBAL_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HGLOBAL
  HICON_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HICON
  HICON_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HICON
  HMENU_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMENU
  HMENU_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMENU
  HMONITOR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMONITOR
  HMONITOR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMONITOR
  HMONITOR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMONITOR
  HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  LPSAFEARRAY_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  PCIDLIST_ABSOLUTE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCIDLIST_ABSOLUTE
  PCIDLIST_ABSOLUTE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCIDLIST_ABSOLUTE
  PCUIDLIST_RELATIVE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCUIDLIST_RELATIVE
  PCUIDLIST_RELATIVE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUIDLIST_RELATIVE
  PCUIDLIST_RELATIVE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUIDLIST_RELATIVE
  PCUIDLIST_RELATIVE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCUIDLIST_RELATIVE
  PCUITEMID_CHILD_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PCUITEMID_CHILD
  PCUITEMID_CHILD_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUITEMID_CHILD
  PCUITEMID_CHILD_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PCUITEMID_CHILD
  PCUITEMID_CHILD_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PCUITEMID_CHILD
  PIDLIST_ABSOLUTE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PIDLIST_ABSOLUTE
  PIDLIST_ABSOLUTE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_ABSOLUTE
  PIDLIST_ABSOLUTE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_ABSOLUTE
  PIDLIST_ABSOLUTE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PIDLIST_ABSOLUTE
  PIDLIST_RELATIVE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PIDLIST_RELATIVE
  PIDLIST_RELATIVE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_RELATIVE
  PIDLIST_RELATIVE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PIDLIST_RELATIVE
  PIDLIST_RELATIVE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PIDLIST_RELATIVE
  PITEMID_CHILD_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr PITEMID_CHILD
  PITEMID_CHILD_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr PITEMID_CHILD
  VARIANT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  IContextMenu_QueryContextMenu_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu, :HMENU, :UINT, :UINT, :UINT, :UINT
  IContextMenu_QueryContextMenu_Stub proto WIN_STD_CALL_CONV :ptr IContextMenu, :HMENU, :UINT, :UINT, :UINT, :UINT, :ptr UINT, :ptr ptr HANDLE, :ptr ptr ULONG
  IContextMenu_InvokeCommand_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu, :ptr CMINVOKECOMMANDINFO
  IContextMenu_InvokeCommand_Stub proto WIN_STD_CALL_CONV :ptr IContextMenu, :ptr CMINVOKECOMMANDINFOEX_REMOTE
  IContextMenu_GetCommandString_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
  IContextMenu_GetCommandString_Stub proto WIN_STD_CALL_CONV :ptr IContextMenu, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
  IContextMenu2_HandleMenuMsg_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu2, :UINT, :WPARAM, :LPARAM
  IContextMenu2_HandleMenuMsg_Stub proto WIN_STD_CALL_CONV :ptr IContextMenu2, :UINT, :WPARAM, :LPARAM
  IContextMenu3_HandleMenuMsg2_Proxy proto WIN_STD_CALL_CONV :ptr IContextMenu3, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
  IContextMenu3_HandleMenuMsg2_Stub proto WIN_STD_CALL_CONV :ptr IContextMenu3, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
  IEnumIDList_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumIDList, :ULONG, :ptr PITEMID_CHILD, :ptr ULONG
  IEnumIDList_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumIDList, :ULONG, :ptr PITEMID_CHILD, :ptr ULONG
  IEnumFullIDList_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumFullIDList, :ULONG, :ptr PIDLIST_ABSOLUTE, :ptr ULONG
  IEnumFullIDList_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumFullIDList, :ULONG, :ptr PIDLIST_ABSOLUTE, :ptr ULONG
  IShellFolder_SetNameOf_Proxy proto WIN_STD_CALL_CONV :ptr IShellFolder, :HWND, :PCUITEMID_CHILD, :LPCWSTR, :SHGDNF, :ptr PITEMID_CHILD
  IShellFolder_SetNameOf_Stub proto WIN_STD_CALL_CONV :ptr IShellFolder, :HWND, :PCUITEMID_CHILD, :LPCWSTR, :SHGDNF, :ptr PITEMID_CHILD
  IFolderView2_GetGroupBy_Proxy proto WIN_STD_CALL_CONV :ptr IFolderView2, :ptr PROPERTYKEY, :ptr BOOL
  IFolderView2_GetGroupBy_Stub proto WIN_STD_CALL_CONV :ptr IFolderView2, :ptr PROPERTYKEY, :ptr BOOL
  IEnumShellItems_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumShellItems, :ULONG, :ptr ptr IShellItem, :ptr ULONG
  IEnumShellItems_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumShellItems, :ULONG, :ptr ptr IShellItem, :ptr ULONG
  IShellExtInit_Initialize_Proxy proto WIN_STD_CALL_CONV :ptr IShellExtInit, :PCIDLIST_ABSOLUTE, :ptr IDataObject, :HKEY
  IShellExtInit_Initialize_Stub proto WIN_STD_CALL_CONV :ptr IShellExtInit, :PCIDLIST_ABSOLUTE, :ptr IDataObject, :HANDLE
  IParentAndItem_GetParentAndItem_Proxy proto WIN_STD_CALL_CONV :ptr IParentAndItem, :ptr PIDLIST_ABSOLUTE, :ptr ptr IShellFolder, :ptr PITEMID_CHILD
  IParentAndItem_GetParentAndItem_Stub proto WIN_STD_CALL_CONV :ptr IParentAndItem, :ptr PIDLIST_ABSOLUTE, :ptr ptr IShellFolder, :ptr PITEMID_CHILD
  IEnumObjects_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumObjects, :ULONG, :REFIID, :ptr ptr, :ptr ULONG
  IEnumObjects_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumObjects, :ULONG, :REFIID, :ptr ptr, :ptr ULONG
  IBandSite_QueryBand_Proxy proto WIN_STD_CALL_CONV :ptr IBandSite, :DWORD, :ptr ptr IDeskBand, :ptr DWORD, :LPWSTR, :SDWORD
  IBandSite_QueryBand_Stub proto WIN_STD_CALL_CONV :ptr IBandSite, :DWORD, :ptr ptr IDeskBand, :ptr DWORD, :LPWSTR, :SDWORD
  IModalWindow_Show_Proxy proto WIN_STD_CALL_CONV :ptr IModalWindow, :HWND
  IModalWindow_Show_Stub proto WIN_STD_CALL_CONV :ptr IModalWindow, :HWND
  IKnownFolderManager_Redirect_Proxy proto WIN_STD_CALL_CONV :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :HWND, :KF_REDIRECT_FLAGS, :LPCWSTR, :UINT, :ptr KNOWNFOLDERID, :ptr LPWSTR
  IKnownFolderManager_Redirect_Stub proto WIN_STD_CALL_CONV :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :HWND, :KF_REDIRECT_FLAGS, :LPCWSTR, :UINT, :ptr GUID, :ptr LPWSTR
  IEnumExplorerCommand_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumExplorerCommand, :ULONG, :ptr ptr IExplorerCommand, :ptr ULONG
  IEnumExplorerCommand_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumExplorerCommand, :ULONG, :ptr ptr IExplorerCommand, :ptr ULONG
  ifdef __cplusplus
    ;[...]
  endif
endif
