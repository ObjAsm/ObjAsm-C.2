;Include file created by h2incX, Version B.01.01, 22/10/2018 23:24
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\shobjidl_core.h', last modified: 19/04/2018 10:49
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
ifndef __shobjidl_core_h__
  __shobjidl_core_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IContextMenu_FWD_DEFINED__
    __IContextMenu_FWD_DEFINED__ equ <>
    ;IContextMenu typedef IContextMenu
    
  endif
  ifndef __IContextMenu2_FWD_DEFINED__
    __IContextMenu2_FWD_DEFINED__ equ <>
    ;IContextMenu2 typedef IContextMenu2
    
  endif
  ifndef __IContextMenu3_FWD_DEFINED__
    __IContextMenu3_FWD_DEFINED__ equ <>
    ;IContextMenu3 typedef IContextMenu3
    
  endif
  ifndef __IExecuteCommand_FWD_DEFINED__
    __IExecuteCommand_FWD_DEFINED__ equ <>
    ;IExecuteCommand typedef IExecuteCommand
    
  endif
  ifndef __IPersistFolder_FWD_DEFINED__
    __IPersistFolder_FWD_DEFINED__ equ <>
    ;IPersistFolder typedef IPersistFolder
    
  endif
  ifndef __IRunnableTask_FWD_DEFINED__
    __IRunnableTask_FWD_DEFINED__ equ <>
    ;IRunnableTask typedef IRunnableTask
    
  endif
  ifndef __IShellTaskScheduler_FWD_DEFINED__
    __IShellTaskScheduler_FWD_DEFINED__ equ <>
    ;IShellTaskScheduler typedef IShellTaskScheduler
    
  endif
  ifndef __IPersistFolder2_FWD_DEFINED__
    __IPersistFolder2_FWD_DEFINED__ equ <>
    ;IPersistFolder2 typedef IPersistFolder2
    
  endif
  ifndef __IPersistFolder3_FWD_DEFINED__
    __IPersistFolder3_FWD_DEFINED__ equ <>
    ;IPersistFolder3 typedef IPersistFolder3
    
  endif
  ifndef __IPersistIDList_FWD_DEFINED__
    __IPersistIDList_FWD_DEFINED__ equ <>
    ;IPersistIDList typedef IPersistIDList
    
  endif
  ifndef __IEnumIDList_FWD_DEFINED__
    __IEnumIDList_FWD_DEFINED__ equ <>
    ;IEnumIDList typedef IEnumIDList
    
  endif
  ifndef __IEnumFullIDList_FWD_DEFINED__
    __IEnumFullIDList_FWD_DEFINED__ equ <>
    ;IEnumFullIDList typedef IEnumFullIDList
    
  endif
  ifndef __IFileSyncMergeHandler_FWD_DEFINED__
    __IFileSyncMergeHandler_FWD_DEFINED__ equ <>
    ;IFileSyncMergeHandler typedef IFileSyncMergeHandler
    
  endif
  ifndef __IObjectWithFolderEnumMode_FWD_DEFINED__
    __IObjectWithFolderEnumMode_FWD_DEFINED__ equ <>
    ;IObjectWithFolderEnumMode typedef IObjectWithFolderEnumMode
    
  endif
  ifndef __IParseAndCreateItem_FWD_DEFINED__
    __IParseAndCreateItem_FWD_DEFINED__ equ <>
    ;IParseAndCreateItem typedef IParseAndCreateItem
    
  endif
  ifndef __IShellFolder_FWD_DEFINED__
    __IShellFolder_FWD_DEFINED__ equ <>
    ;IShellFolder typedef IShellFolder
    
  endif
  ifndef __IEnumExtraSearch_FWD_DEFINED__
    __IEnumExtraSearch_FWD_DEFINED__ equ <>
    ;IEnumExtraSearch typedef IEnumExtraSearch
    
  endif
  ifndef __IShellFolder2_FWD_DEFINED__
    __IShellFolder2_FWD_DEFINED__ equ <>
    ;IShellFolder2 typedef IShellFolder2
    
  endif
  ifndef __IShellView_FWD_DEFINED__
    __IShellView_FWD_DEFINED__ equ <>
    ;IShellView typedef IShellView
    
  endif
  ifndef __IShellView2_FWD_DEFINED__
    __IShellView2_FWD_DEFINED__ equ <>
    ;IShellView2 typedef IShellView2
    
  endif
  ifndef __IFolderView_FWD_DEFINED__
    __IFolderView_FWD_DEFINED__ equ <>
    ;IFolderView typedef IFolderView
    
  endif
  ifndef __IFolderView2_FWD_DEFINED__
    __IFolderView2_FWD_DEFINED__ equ <>
    ;IFolderView2 typedef IFolderView2
    
  endif
  ifndef __IFolderViewSettings_FWD_DEFINED__
    __IFolderViewSettings_FWD_DEFINED__ equ <>
    ;IFolderViewSettings typedef IFolderViewSettings
    
  endif
  ifndef __IPreviewHandlerVisuals_FWD_DEFINED__
    __IPreviewHandlerVisuals_FWD_DEFINED__ equ <>
    ;IPreviewHandlerVisuals typedef IPreviewHandlerVisuals
    
  endif
  ifndef __ICommDlgBrowser_FWD_DEFINED__
    __ICommDlgBrowser_FWD_DEFINED__ equ <>
    ;ICommDlgBrowser typedef ICommDlgBrowser
    
  endif
  ifndef __ICommDlgBrowser2_FWD_DEFINED__
    __ICommDlgBrowser2_FWD_DEFINED__ equ <>
    ;ICommDlgBrowser2 typedef ICommDlgBrowser2
    
  endif
  ifndef __IColumnManager_FWD_DEFINED__
    __IColumnManager_FWD_DEFINED__ equ <>
    ;IColumnManager typedef IColumnManager
    
  endif
  ifndef __IFolderFilterSite_FWD_DEFINED__
    __IFolderFilterSite_FWD_DEFINED__ equ <>
    ;IFolderFilterSite typedef IFolderFilterSite
    
  endif
  ifndef __IFolderFilter_FWD_DEFINED__
    __IFolderFilter_FWD_DEFINED__ equ <>
    ;IFolderFilter typedef IFolderFilter
    
  endif
  ifndef __IInputObjectSite_FWD_DEFINED__
    __IInputObjectSite_FWD_DEFINED__ equ <>
    ;IInputObjectSite typedef IInputObjectSite
    
  endif
  ifndef __IInputObject_FWD_DEFINED__
    __IInputObject_FWD_DEFINED__ equ <>
    ;IInputObject typedef IInputObject
    
  endif
  ifndef __IInputObject2_FWD_DEFINED__
    __IInputObject2_FWD_DEFINED__ equ <>
    ;IInputObject2 typedef IInputObject2
    
  endif
  ifndef __IShellIcon_FWD_DEFINED__
    __IShellIcon_FWD_DEFINED__ equ <>
    ;IShellIcon typedef IShellIcon
    
  endif
  ifndef __IShellBrowser_FWD_DEFINED__
    __IShellBrowser_FWD_DEFINED__ equ <>
    ;IShellBrowser typedef IShellBrowser
    
  endif
  ifndef __IProfferService_FWD_DEFINED__
    __IProfferService_FWD_DEFINED__ equ <>
    ;IProfferService typedef IProfferService
    
  endif
  ifndef __IShellItem_FWD_DEFINED__
    __IShellItem_FWD_DEFINED__ equ <>
    ;IShellItem typedef IShellItem
    
  endif
  ifndef __IShellItem2_FWD_DEFINED__
    __IShellItem2_FWD_DEFINED__ equ <>
    ;IShellItem2 typedef IShellItem2
    
  endif
  ifndef __IShellItemImageFactory_FWD_DEFINED__
    __IShellItemImageFactory_FWD_DEFINED__ equ <>
    ;IShellItemImageFactory typedef IShellItemImageFactory
    
  endif
  ifndef __IEnumShellItems_FWD_DEFINED__
    __IEnumShellItems_FWD_DEFINED__ equ <>
    ;IEnumShellItems typedef IEnumShellItems
    
  endif
  ifndef __ITransferAdviseSink_FWD_DEFINED__
    __ITransferAdviseSink_FWD_DEFINED__ equ <>
    ;ITransferAdviseSink typedef ITransferAdviseSink
    
  endif
  ifndef __ITransferSource_FWD_DEFINED__
    __ITransferSource_FWD_DEFINED__ equ <>
    ;ITransferSource typedef ITransferSource
    
  endif
  ifndef __IEnumResources_FWD_DEFINED__
    __IEnumResources_FWD_DEFINED__ equ <>
    ;IEnumResources typedef IEnumResources
    
  endif
  ifndef __IShellItemResources_FWD_DEFINED__
    __IShellItemResources_FWD_DEFINED__ equ <>
    ;IShellItemResources typedef IShellItemResources
    
  endif
  ifndef __ITransferDestination_FWD_DEFINED__
    __ITransferDestination_FWD_DEFINED__ equ <>
    ;ITransferDestination typedef ITransferDestination
    
  endif
  ifndef __IFileOperationProgressSink_FWD_DEFINED__
    __IFileOperationProgressSink_FWD_DEFINED__ equ <>
    ;IFileOperationProgressSink typedef IFileOperationProgressSink
    
  endif
  ifndef __IShellItemArray_FWD_DEFINED__
    __IShellItemArray_FWD_DEFINED__ equ <>
    ;IShellItemArray typedef IShellItemArray
    
  endif
  ifndef __IInitializeWithItem_FWD_DEFINED__
    __IInitializeWithItem_FWD_DEFINED__ equ <>
    ;IInitializeWithItem typedef IInitializeWithItem
    
  endif
  ifndef __IObjectWithSelection_FWD_DEFINED__
    __IObjectWithSelection_FWD_DEFINED__ equ <>
    ;IObjectWithSelection typedef IObjectWithSelection
    
  endif
  ifndef __IObjectWithBackReferences_FWD_DEFINED__
    __IObjectWithBackReferences_FWD_DEFINED__ equ <>
    ;IObjectWithBackReferences typedef IObjectWithBackReferences
    
  endif
  ifndef __IPropertyUI_FWD_DEFINED__
    __IPropertyUI_FWD_DEFINED__ equ <>
    ;IPropertyUI typedef IPropertyUI
    
  endif
  ifndef __ICategoryProvider_FWD_DEFINED__
    __ICategoryProvider_FWD_DEFINED__ equ <>
    ;ICategoryProvider typedef ICategoryProvider
    
  endif
  ifndef __ICategorizer_FWD_DEFINED__
    __ICategorizer_FWD_DEFINED__ equ <>
    ;ICategorizer typedef ICategorizer
    
  endif
  ifndef __IDropTargetHelper_FWD_DEFINED__
    __IDropTargetHelper_FWD_DEFINED__ equ <>
    ;IDropTargetHelper typedef IDropTargetHelper
    
  endif
  ifndef __IDragSourceHelper_FWD_DEFINED__
    __IDragSourceHelper_FWD_DEFINED__ equ <>
    ;IDragSourceHelper typedef IDragSourceHelper
    
  endif
  ifndef __IShellLinkA_FWD_DEFINED__
    __IShellLinkA_FWD_DEFINED__ equ <>
    ;IShellLinkA typedef IShellLinkA
    
  endif
  ifndef __IShellLinkW_FWD_DEFINED__
    __IShellLinkW_FWD_DEFINED__ equ <>
    ;IShellLinkW typedef IShellLinkW
    
  endif
  ifndef __IShellLinkDataList_FWD_DEFINED__
    __IShellLinkDataList_FWD_DEFINED__ equ <>
    ;IShellLinkDataList typedef IShellLinkDataList
    
  endif
  ifndef __IResolveShellLink_FWD_DEFINED__
    __IResolveShellLink_FWD_DEFINED__ equ <>
    ;IResolveShellLink typedef IResolveShellLink
    
  endif
  ifndef __IActionProgressDialog_FWD_DEFINED__
    __IActionProgressDialog_FWD_DEFINED__ equ <>
    ;IActionProgressDialog typedef IActionProgressDialog
    
  endif
  ifndef __IActionProgress_FWD_DEFINED__
    __IActionProgress_FWD_DEFINED__ equ <>
    ;IActionProgress typedef IActionProgress
    
  endif
  ifndef __IShellExtInit_FWD_DEFINED__
    __IShellExtInit_FWD_DEFINED__ equ <>
    ;IShellExtInit typedef IShellExtInit
    
  endif
  ifndef __IShellPropSheetExt_FWD_DEFINED__
    __IShellPropSheetExt_FWD_DEFINED__ equ <>
    ;IShellPropSheetExt typedef IShellPropSheetExt
    
  endif
  ifndef __IRemoteComputer_FWD_DEFINED__
    __IRemoteComputer_FWD_DEFINED__ equ <>
    ;IRemoteComputer typedef IRemoteComputer
    
  endif
  ifndef __IQueryContinue_FWD_DEFINED__
    __IQueryContinue_FWD_DEFINED__ equ <>
    ;IQueryContinue typedef IQueryContinue
    
  endif
  ifndef __IObjectWithCancelEvent_FWD_DEFINED__
    __IObjectWithCancelEvent_FWD_DEFINED__ equ <>
    ;IObjectWithCancelEvent typedef IObjectWithCancelEvent
    
  endif
  ifndef __IUserNotification_FWD_DEFINED__
    __IUserNotification_FWD_DEFINED__ equ <>
    ;IUserNotification typedef IUserNotification
    
  endif
  ifndef __IItemNameLimits_FWD_DEFINED__
    __IItemNameLimits_FWD_DEFINED__ equ <>
    ;IItemNameLimits typedef IItemNameLimits
    
  endif
  ifndef __ISearchFolderItemFactory_FWD_DEFINED__
    __ISearchFolderItemFactory_FWD_DEFINED__ equ <>
    ;ISearchFolderItemFactory typedef ISearchFolderItemFactory
    
  endif
  ifndef __IExtractImage_FWD_DEFINED__
    __IExtractImage_FWD_DEFINED__ equ <>
    ;IExtractImage typedef IExtractImage
    
  endif
  ifndef __IExtractImage2_FWD_DEFINED__
    __IExtractImage2_FWD_DEFINED__ equ <>
    ;IExtractImage2 typedef IExtractImage2
    
  endif
  ifndef __IThumbnailHandlerFactory_FWD_DEFINED__
    __IThumbnailHandlerFactory_FWD_DEFINED__ equ <>
    ;IThumbnailHandlerFactory typedef IThumbnailHandlerFactory
    
  endif
  ifndef __IParentAndItem_FWD_DEFINED__
    __IParentAndItem_FWD_DEFINED__ equ <>
    ;IParentAndItem typedef IParentAndItem
    
  endif
  ifndef __IDockingWindow_FWD_DEFINED__
    __IDockingWindow_FWD_DEFINED__ equ <>
    ;IDockingWindow typedef IDockingWindow
    
  endif
  ifndef __IDeskBand_FWD_DEFINED__
    __IDeskBand_FWD_DEFINED__ equ <>
    ;IDeskBand typedef IDeskBand
    
  endif
  ifndef __IDeskBandInfo_FWD_DEFINED__
    __IDeskBandInfo_FWD_DEFINED__ equ <>
    ;IDeskBandInfo typedef IDeskBandInfo
    
  endif
  ifndef __ITaskbarList_FWD_DEFINED__
    __ITaskbarList_FWD_DEFINED__ equ <>
    ;ITaskbarList typedef ITaskbarList
    
  endif
  ifndef __ITaskbarList2_FWD_DEFINED__
    __ITaskbarList2_FWD_DEFINED__ equ <>
    ;ITaskbarList2 typedef ITaskbarList2
    
  endif
  ifndef __ITaskbarList3_FWD_DEFINED__
    __ITaskbarList3_FWD_DEFINED__ equ <>
    ;ITaskbarList3 typedef ITaskbarList3
    
  endif
  ifndef __ITaskbarList4_FWD_DEFINED__
    __ITaskbarList4_FWD_DEFINED__ equ <>
    ;ITaskbarList4 typedef ITaskbarList4
    
  endif
  ifndef __IExplorerBrowserEvents_FWD_DEFINED__
    __IExplorerBrowserEvents_FWD_DEFINED__ equ <>
    ;IExplorerBrowserEvents typedef IExplorerBrowserEvents
    
  endif
  ifndef __IExplorerBrowser_FWD_DEFINED__
    __IExplorerBrowser_FWD_DEFINED__ equ <>
    ;IExplorerBrowser typedef IExplorerBrowser
    
  endif
  ifndef __IEnumObjects_FWD_DEFINED__
    __IEnumObjects_FWD_DEFINED__ equ <>
    ;IEnumObjects typedef IEnumObjects
    
  endif
  ifndef __IOperationsProgressDialog_FWD_DEFINED__
    __IOperationsProgressDialog_FWD_DEFINED__ equ <>
    ;IOperationsProgressDialog typedef IOperationsProgressDialog
    
  endif
  ifndef __IIOCancelInformation_FWD_DEFINED__
    __IIOCancelInformation_FWD_DEFINED__ equ <>
    ;IIOCancelInformation typedef IIOCancelInformation
    
  endif
  ifndef __IFileOperation_FWD_DEFINED__
    __IFileOperation_FWD_DEFINED__ equ <>
    ;IFileOperation typedef IFileOperation
    
  endif
  ifndef __IFileOperation2_FWD_DEFINED__
    __IFileOperation2_FWD_DEFINED__ equ <>
    ;IFileOperation2 typedef IFileOperation2
    
  endif
  ifndef __IObjectProvider_FWD_DEFINED__
    __IObjectProvider_FWD_DEFINED__ equ <>
    ;IObjectProvider typedef IObjectProvider
    
  endif
  ifndef __INamespaceWalkCB_FWD_DEFINED__
    __INamespaceWalkCB_FWD_DEFINED__ equ <>
    ;INamespaceWalkCB typedef INamespaceWalkCB
    
  endif
  ifndef __INamespaceWalkCB2_FWD_DEFINED__
    __INamespaceWalkCB2_FWD_DEFINED__ equ <>
    ;INamespaceWalkCB2 typedef INamespaceWalkCB2
    
  endif
  ifndef __INamespaceWalk_FWD_DEFINED__
    __INamespaceWalk_FWD_DEFINED__ equ <>
    ;INamespaceWalk typedef INamespaceWalk
    
  endif
  ifndef __IBandSite_FWD_DEFINED__
    __IBandSite_FWD_DEFINED__ equ <>
    ;IBandSite typedef IBandSite
    
  endif
  ifndef __IModalWindow_FWD_DEFINED__
    __IModalWindow_FWD_DEFINED__ equ <>
    ;IModalWindow typedef IModalWindow
    
  endif
  ifndef __IContextMenuSite_FWD_DEFINED__
    __IContextMenuSite_FWD_DEFINED__ equ <>
    ;IContextMenuSite typedef IContextMenuSite
    
  endif
  ifndef __IMenuBand_FWD_DEFINED__
    __IMenuBand_FWD_DEFINED__ equ <>
    ;IMenuBand typedef IMenuBand
    
  endif
  ifndef __IRegTreeItem_FWD_DEFINED__
    __IRegTreeItem_FWD_DEFINED__ equ <>
    ;IRegTreeItem typedef IRegTreeItem
    
  endif
  ifndef __IDeskBar_FWD_DEFINED__
    __IDeskBar_FWD_DEFINED__ equ <>
    ;IDeskBar typedef IDeskBar
    
  endif
  ifndef __IMenuPopup_FWD_DEFINED__
    __IMenuPopup_FWD_DEFINED__ equ <>
    ;IMenuPopup typedef IMenuPopup
    
  endif
  ifndef __IFileIsInUse_FWD_DEFINED__
    __IFileIsInUse_FWD_DEFINED__ equ <>
    ;IFileIsInUse typedef IFileIsInUse
    
  endif
  ifndef __IFileDialogEvents_FWD_DEFINED__
    __IFileDialogEvents_FWD_DEFINED__ equ <>
    ;IFileDialogEvents typedef IFileDialogEvents
    
  endif
  ifndef __IFileDialog_FWD_DEFINED__
    __IFileDialog_FWD_DEFINED__ equ <>
    ;IFileDialog typedef IFileDialog
    
  endif
  ifndef __IFileSaveDialog_FWD_DEFINED__
    __IFileSaveDialog_FWD_DEFINED__ equ <>
    ;IFileSaveDialog typedef IFileSaveDialog
    
  endif
  ifndef __IFileOpenDialog_FWD_DEFINED__
    __IFileOpenDialog_FWD_DEFINED__ equ <>
    ;IFileOpenDialog typedef IFileOpenDialog
    
  endif
  ifndef __IFileDialogCustomize_FWD_DEFINED__
    __IFileDialogCustomize_FWD_DEFINED__ equ <>
    ;IFileDialogCustomize typedef IFileDialogCustomize
    
  endif
  ifndef __IApplicationAssociationRegistration_FWD_DEFINED__
    __IApplicationAssociationRegistration_FWD_DEFINED__ equ <>
    ;IApplicationAssociationRegistration typedef IApplicationAssociationRegistration
    
  endif
  ifndef __IDelegateFolder_FWD_DEFINED__
    __IDelegateFolder_FWD_DEFINED__ equ <>
    ;IDelegateFolder typedef IDelegateFolder
    
  endif
  ifndef __IBrowserFrameOptions_FWD_DEFINED__
    __IBrowserFrameOptions_FWD_DEFINED__ equ <>
    ;IBrowserFrameOptions typedef IBrowserFrameOptions
    
  endif
  ifndef __INewWindowManager_FWD_DEFINED__
    __INewWindowManager_FWD_DEFINED__ equ <>
    ;INewWindowManager typedef INewWindowManager
    
  endif
  ifndef __IAttachmentExecute_FWD_DEFINED__
    __IAttachmentExecute_FWD_DEFINED__ equ <>
    ;IAttachmentExecute typedef IAttachmentExecute
    
  endif
  ifndef __IShellMenuCallback_FWD_DEFINED__
    __IShellMenuCallback_FWD_DEFINED__ equ <>
    ;IShellMenuCallback typedef IShellMenuCallback
    
  endif
  ifndef __IShellMenu_FWD_DEFINED__
    __IShellMenu_FWD_DEFINED__ equ <>
    ;IShellMenu typedef IShellMenu
    
  endif
  ifndef __IKnownFolder_FWD_DEFINED__
    __IKnownFolder_FWD_DEFINED__ equ <>
    ;IKnownFolder typedef IKnownFolder
    
  endif
  ifndef __IKnownFolderManager_FWD_DEFINED__
    __IKnownFolderManager_FWD_DEFINED__ equ <>
    ;IKnownFolderManager typedef IKnownFolderManager
    
  endif
  ifndef __ISharingConfigurationManager_FWD_DEFINED__
    __ISharingConfigurationManager_FWD_DEFINED__ equ <>
    ;ISharingConfigurationManager typedef ISharingConfigurationManager
    
  endif
  ifndef __IRelatedItem_FWD_DEFINED__
    __IRelatedItem_FWD_DEFINED__ equ <>
    ;IRelatedItem typedef IRelatedItem
    
  endif
  ifndef __IIdentityName_FWD_DEFINED__
    __IIdentityName_FWD_DEFINED__ equ <>
    ;IIdentityName typedef IIdentityName
    
  endif
  ifndef __IDelegateItem_FWD_DEFINED__
    __IDelegateItem_FWD_DEFINED__ equ <>
    ;IDelegateItem typedef IDelegateItem
    
  endif
  ifndef __ICurrentItem_FWD_DEFINED__
    __ICurrentItem_FWD_DEFINED__ equ <>
    ;ICurrentItem typedef ICurrentItem
    
  endif
  ifndef __ITransferMediumItem_FWD_DEFINED__
    __ITransferMediumItem_FWD_DEFINED__ equ <>
    ;ITransferMediumItem typedef ITransferMediumItem
    
  endif
  ifndef __IDisplayItem_FWD_DEFINED__
    __IDisplayItem_FWD_DEFINED__ equ <>
    ;IDisplayItem typedef IDisplayItem
    
  endif
  ifndef __IViewStateIdentityItem_FWD_DEFINED__
    __IViewStateIdentityItem_FWD_DEFINED__ equ <>
    ;IViewStateIdentityItem typedef IViewStateIdentityItem
    
  endif
  ifndef __IPreviewItem_FWD_DEFINED__
    __IPreviewItem_FWD_DEFINED__ equ <>
    ;IPreviewItem typedef IPreviewItem
    
  endif
  ifndef __IDestinationStreamFactory_FWD_DEFINED__
    __IDestinationStreamFactory_FWD_DEFINED__ equ <>
    ;IDestinationStreamFactory typedef IDestinationStreamFactory
    
  endif
  ifndef __ICreateProcessInputs_FWD_DEFINED__
    __ICreateProcessInputs_FWD_DEFINED__ equ <>
    ;ICreateProcessInputs typedef ICreateProcessInputs
    
  endif
  ifndef __ICreatingProcess_FWD_DEFINED__
    __ICreatingProcess_FWD_DEFINED__ equ <>
    ;ICreatingProcess typedef ICreatingProcess
    
  endif
  ifndef __INewMenuClient_FWD_DEFINED__
    __INewMenuClient_FWD_DEFINED__ equ <>
    ;INewMenuClient typedef INewMenuClient
    
  endif
  ifndef __IInitializeWithBindCtx_FWD_DEFINED__
    __IInitializeWithBindCtx_FWD_DEFINED__ equ <>
    ;IInitializeWithBindCtx typedef IInitializeWithBindCtx
    
  endif
  ifndef __IShellItemFilter_FWD_DEFINED__
    __IShellItemFilter_FWD_DEFINED__ equ <>
    ;IShellItemFilter typedef IShellItemFilter
    
  endif
  ifndef __INameSpaceTreeControl_FWD_DEFINED__
    __INameSpaceTreeControl_FWD_DEFINED__ equ <>
    ;INameSpaceTreeControl typedef INameSpaceTreeControl
    
  endif
  ifndef __INameSpaceTreeControlFolderCapabilities_FWD_DEFINED__
    __INameSpaceTreeControlFolderCapabilities_FWD_DEFINED__ equ <>
    ;INameSpaceTreeControlFolderCapabilities typedef INameSpaceTreeControlFolderCapabilities
    
  endif
  ifndef __IPreviewHandler_FWD_DEFINED__
    __IPreviewHandler_FWD_DEFINED__ equ <>
    ;IPreviewHandler typedef IPreviewHandler
    
  endif
  ifndef __IPreviewHandlerFrame_FWD_DEFINED__
    __IPreviewHandlerFrame_FWD_DEFINED__ equ <>
    ;IPreviewHandlerFrame typedef IPreviewHandlerFrame
    
  endif
  ifndef __IExplorerPaneVisibility_FWD_DEFINED__
    __IExplorerPaneVisibility_FWD_DEFINED__ equ <>
    ;IExplorerPaneVisibility typedef IExplorerPaneVisibility
    
  endif
  ifndef __IContextMenuCB_FWD_DEFINED__
    __IContextMenuCB_FWD_DEFINED__ equ <>
    ;IContextMenuCB typedef IContextMenuCB
    
  endif
  ifndef __IDefaultExtractIconInit_FWD_DEFINED__
    __IDefaultExtractIconInit_FWD_DEFINED__ equ <>
    ;IDefaultExtractIconInit typedef IDefaultExtractIconInit
    
  endif
  ifndef __IExplorerCommand_FWD_DEFINED__
    __IExplorerCommand_FWD_DEFINED__ equ <>
    ;IExplorerCommand typedef IExplorerCommand
    
  endif
  ifndef __IExplorerCommandState_FWD_DEFINED__
    __IExplorerCommandState_FWD_DEFINED__ equ <>
    ;IExplorerCommandState typedef IExplorerCommandState
    
  endif
  ifndef __IInitializeCommand_FWD_DEFINED__
    __IInitializeCommand_FWD_DEFINED__ equ <>
    ;IInitializeCommand typedef IInitializeCommand
    
  endif
  ifndef __IEnumExplorerCommand_FWD_DEFINED__
    __IEnumExplorerCommand_FWD_DEFINED__ equ <>
    ;IEnumExplorerCommand typedef IEnumExplorerCommand
    
  endif
  ifndef __IExplorerCommandProvider_FWD_DEFINED__
    __IExplorerCommandProvider_FWD_DEFINED__ equ <>
    ;IExplorerCommandProvider typedef IExplorerCommandProvider
    
  endif
  ifndef __IOpenControlPanel_FWD_DEFINED__
    __IOpenControlPanel_FWD_DEFINED__ equ <>
    ;IOpenControlPanel typedef IOpenControlPanel
    
  endif
  ifndef __IFileSystemBindData_FWD_DEFINED__
    __IFileSystemBindData_FWD_DEFINED__ equ <>
    ;IFileSystemBindData typedef IFileSystemBindData
    
  endif
  ifndef __IFileSystemBindData2_FWD_DEFINED__
    __IFileSystemBindData2_FWD_DEFINED__ equ <>
    ;IFileSystemBindData2 typedef IFileSystemBindData2
    
  endif
  ifndef __ICustomDestinationList_FWD_DEFINED__
    __ICustomDestinationList_FWD_DEFINED__ equ <>
    ;ICustomDestinationList typedef ICustomDestinationList
    
  endif
  ifndef __IApplicationDestinations_FWD_DEFINED__
    __IApplicationDestinations_FWD_DEFINED__ equ <>
    ;IApplicationDestinations typedef IApplicationDestinations
    
  endif
  ifndef __IApplicationDocumentLists_FWD_DEFINED__
    __IApplicationDocumentLists_FWD_DEFINED__ equ <>
    ;IApplicationDocumentLists typedef IApplicationDocumentLists
    
  endif
  ifndef __IObjectWithAppUserModelID_FWD_DEFINED__
    __IObjectWithAppUserModelID_FWD_DEFINED__ equ <>
    ;IObjectWithAppUserModelID typedef IObjectWithAppUserModelID
    
  endif
  ifndef __IObjectWithProgID_FWD_DEFINED__
    __IObjectWithProgID_FWD_DEFINED__ equ <>
    ;IObjectWithProgID typedef IObjectWithProgID
    
  endif
  ifndef __IUpdateIDList_FWD_DEFINED__
    __IUpdateIDList_FWD_DEFINED__ equ <>
    ;IUpdateIDList typedef IUpdateIDList
    
  endif
  ifndef __IDesktopWallpaper_FWD_DEFINED__
    __IDesktopWallpaper_FWD_DEFINED__ equ <>
    ;IDesktopWallpaper typedef IDesktopWallpaper
    
  endif
  ifndef __IHomeGroup_FWD_DEFINED__
    __IHomeGroup_FWD_DEFINED__ equ <>
    ;IHomeGroup typedef IHomeGroup
    
  endif
  ifndef __IInitializeWithPropertyStore_FWD_DEFINED__
    __IInitializeWithPropertyStore_FWD_DEFINED__ equ <>
    ;IInitializeWithPropertyStore typedef IInitializeWithPropertyStore
    
  endif
  ifndef __IOpenSearchSource_FWD_DEFINED__
    __IOpenSearchSource_FWD_DEFINED__ equ <>
    ;IOpenSearchSource typedef IOpenSearchSource
    
  endif
  ifndef __IShellLibrary_FWD_DEFINED__
    __IShellLibrary_FWD_DEFINED__ equ <>
    ;IShellLibrary typedef IShellLibrary
    
  endif
  ifndef __IDefaultFolderMenuInitialize_FWD_DEFINED__
    __IDefaultFolderMenuInitialize_FWD_DEFINED__ equ <>
    ;IDefaultFolderMenuInitialize typedef IDefaultFolderMenuInitialize
    
  endif
  ifndef __IApplicationActivationManager_FWD_DEFINED__
    __IApplicationActivationManager_FWD_DEFINED__ equ <>
    ;IApplicationActivationManager typedef IApplicationActivationManager
    
  endif
  ifndef __DesktopWallpaper_FWD_DEFINED__
    __DesktopWallpaper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DesktopWallpaper typedef DesktopWallpaper
      
    endif
  endif
  ifndef __ShellDesktop_FWD_DEFINED__
    __ShellDesktop_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellDesktop typedef ShellDesktop
      
    endif
  endif
  ifndef __ShellFSFolder_FWD_DEFINED__
    __ShellFSFolder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellFSFolder typedef ShellFSFolder
      
    endif
  endif
  ifndef __NetworkPlaces_FWD_DEFINED__
    __NetworkPlaces_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;NetworkPlaces typedef NetworkPlaces
      
    endif
  endif
  ifndef __ShellLink_FWD_DEFINED__
    __ShellLink_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellLink typedef ShellLink
      
    endif
  endif
  ifndef __DriveSizeCategorizer_FWD_DEFINED__
    __DriveSizeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DriveSizeCategorizer typedef DriveSizeCategorizer
      
    endif
  endif
  ifndef __DriveTypeCategorizer_FWD_DEFINED__
    __DriveTypeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DriveTypeCategorizer typedef DriveTypeCategorizer
      
    endif
  endif
  ifndef __FreeSpaceCategorizer_FWD_DEFINED__
    __FreeSpaceCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FreeSpaceCategorizer typedef FreeSpaceCategorizer
      
    endif
  endif
  ifndef __SizeCategorizer_FWD_DEFINED__
    __SizeCategorizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;SizeCategorizer typedef SizeCategorizer
      
    endif
  endif
  ifndef __PropertiesUI_FWD_DEFINED__
    __PropertiesUI_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;PropertiesUI typedef PropertiesUI
      
    endif
  endif
  ifndef __UserNotification_FWD_DEFINED__
    __UserNotification_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;UserNotification typedef UserNotification
      
    endif
  endif
  ifndef __TaskbarList_FWD_DEFINED__
    __TaskbarList_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;TaskbarList typedef TaskbarList
      
    endif
  endif
  ifndef __ShellItem_FWD_DEFINED__
    __ShellItem_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellItem typedef ShellItem
      
    endif
  endif
  ifndef __NamespaceWalker_FWD_DEFINED__
    __NamespaceWalker_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;NamespaceWalker typedef NamespaceWalker
      
    endif
  endif
  ifndef __FileOperation_FWD_DEFINED__
    __FileOperation_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FileOperation typedef FileOperation
      
    endif
  endif
  ifndef __FileOpenDialog_FWD_DEFINED__
    __FileOpenDialog_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FileOpenDialog typedef FileOpenDialog
      
    endif
  endif
  ifndef __FileSaveDialog_FWD_DEFINED__
    __FileSaveDialog_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FileSaveDialog typedef FileSaveDialog
      
    endif
  endif
  ifndef __KnownFolderManager_FWD_DEFINED__
    __KnownFolderManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;KnownFolderManager typedef KnownFolderManager
      
    endif
  endif
  ifndef __SharingConfigurationManager_FWD_DEFINED__
    __SharingConfigurationManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;SharingConfigurationManager typedef SharingConfigurationManager
      
    endif
  endif
  ifndef __NetworkConnections_FWD_DEFINED__
    __NetworkConnections_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;NetworkConnections typedef NetworkConnections
      
    endif
  endif
  ifndef __ScheduledTasks_FWD_DEFINED__
    __ScheduledTasks_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ScheduledTasks typedef ScheduledTasks
      
    endif
  endif
  ifndef __ApplicationAssociationRegistration_FWD_DEFINED__
    __ApplicationAssociationRegistration_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ApplicationAssociationRegistration typedef ApplicationAssociationRegistration
      
    endif
  endif
  ifndef __SearchFolderItemFactory_FWD_DEFINED__
    __SearchFolderItemFactory_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;SearchFolderItemFactory typedef SearchFolderItemFactory
      
    endif
  endif
  ifndef __OpenControlPanel_FWD_DEFINED__
    __OpenControlPanel_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;OpenControlPanel typedef OpenControlPanel
      
    endif
  endif
  ifndef __MailRecipient_FWD_DEFINED__
    __MailRecipient_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;MailRecipient typedef MailRecipient
      
    endif
  endif
  ifndef __NetworkExplorerFolder_FWD_DEFINED__
    __NetworkExplorerFolder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;NetworkExplorerFolder typedef NetworkExplorerFolder
      
    endif
  endif
  ifndef __DestinationList_FWD_DEFINED__
    __DestinationList_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DestinationList typedef DestinationList
      
    endif
  endif
  ifndef __ApplicationDestinations_FWD_DEFINED__
    __ApplicationDestinations_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ApplicationDestinations typedef ApplicationDestinations
      
    endif
  endif
  ifndef __ApplicationDocumentLists_FWD_DEFINED__
    __ApplicationDocumentLists_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ApplicationDocumentLists typedef ApplicationDocumentLists
      
    endif
  endif
  ifndef __HomeGroup_FWD_DEFINED__
    __HomeGroup_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;HomeGroup typedef HomeGroup
      
    endif
  endif
  ifndef __ShellLibrary_FWD_DEFINED__
    __ShellLibrary_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellLibrary typedef ShellLibrary
      
    endif
  endif
  ifndef __AppStartupLink_FWD_DEFINED__
    __AppStartupLink_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;AppStartupLink typedef AppStartupLink
      
    endif
  endif
  ifndef __EnumerableObjectCollection_FWD_DEFINED__
    __EnumerableObjectCollection_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;EnumerableObjectCollection typedef EnumerableObjectCollection
      
    endif
  endif
  ifndef __FrameworkInputPane_FWD_DEFINED__
    __FrameworkInputPane_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FrameworkInputPane typedef FrameworkInputPane
      
    endif
  endif
  ifndef __DefFolderMenu_FWD_DEFINED__
    __DefFolderMenu_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DefFolderMenu typedef DefFolderMenu
      
    endif
  endif
  ifndef __AppVisibility_FWD_DEFINED__
    __AppVisibility_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;AppVisibility typedef AppVisibility
      
    endif
  endif
  ifndef __AppShellVerbHandler_FWD_DEFINED__
    __AppShellVerbHandler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;AppShellVerbHandler typedef AppShellVerbHandler
      
    endif
  endif
  ifndef __ExecuteUnknown_FWD_DEFINED__
    __ExecuteUnknown_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ExecuteUnknown typedef ExecuteUnknown
      
    endif
  endif
  ifndef __PackageDebugSettings_FWD_DEFINED__
    __PackageDebugSettings_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;PackageDebugSettings typedef PackageDebugSettings
      
    endif
  endif
  ifndef __SuspensionDependencyManager_FWD_DEFINED__
    __SuspensionDependencyManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;SuspensionDependencyManager typedef SuspensionDependencyManager
      
    endif
  endif
  ifndef __ApplicationActivationManager_FWD_DEFINED__
    __ApplicationActivationManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ApplicationActivationManager typedef ApplicationActivationManager
      
    endif
  endif
  ifndef __ApplicationDesignModeSettings_FWD_DEFINED__
    __ApplicationDesignModeSettings_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ApplicationDesignModeSettings typedef ApplicationDesignModeSettings
      
    endif
  endif
  ifndef __IAssocHandlerInvoker_FWD_DEFINED__
    __IAssocHandlerInvoker_FWD_DEFINED__ equ <>
    ;IAssocHandlerInvoker typedef IAssocHandlerInvoker
    
  endif
  ifndef __IAssocHandler_FWD_DEFINED__
    __IAssocHandler_FWD_DEFINED__ equ <>
    ;IAssocHandler typedef IAssocHandler
    
  endif
  ifndef __IEnumAssocHandlers_FWD_DEFINED__
    __IEnumAssocHandlers_FWD_DEFINED__ equ <>
    ;IEnumAssocHandlers typedef IEnumAssocHandlers
    
  endif
  ifndef __IDataObjectProvider_FWD_DEFINED__
    __IDataObjectProvider_FWD_DEFINED__ equ <>
    ;IDataObjectProvider typedef IDataObjectProvider
    
  endif
  ifndef __IDataTransferManagerInterop_FWD_DEFINED__
    __IDataTransferManagerInterop_FWD_DEFINED__ equ <>
    ;IDataTransferManagerInterop typedef IDataTransferManagerInterop
    
  endif
  ifndef __IFrameworkInputPaneHandler_FWD_DEFINED__
    __IFrameworkInputPaneHandler_FWD_DEFINED__ equ <>
    ;IFrameworkInputPaneHandler typedef IFrameworkInputPaneHandler
    
  endif
  ifndef __IFrameworkInputPane_FWD_DEFINED__
    __IFrameworkInputPane_FWD_DEFINED__ equ <>
    ;IFrameworkInputPane typedef IFrameworkInputPane
    
  endif
  ifndef __IAppVisibilityEvents_FWD_DEFINED__
    __IAppVisibilityEvents_FWD_DEFINED__ equ <>
    ;IAppVisibilityEvents typedef IAppVisibilityEvents
    
  endif
  ifndef __IAppVisibility_FWD_DEFINED__
    __IAppVisibility_FWD_DEFINED__ equ <>
    ;IAppVisibility typedef IAppVisibility
    
  endif
  ifndef __IPackageExecutionStateChangeNotification_FWD_DEFINED__
    __IPackageExecutionStateChangeNotification_FWD_DEFINED__ equ <>
    ;IPackageExecutionStateChangeNotification typedef IPackageExecutionStateChangeNotification
    
  endif
  ifndef __IPackageDebugSettings_FWD_DEFINED__
    __IPackageDebugSettings_FWD_DEFINED__ equ <>
    ;IPackageDebugSettings typedef IPackageDebugSettings
    
  endif
  ifndef __IPackageDebugSettings2_FWD_DEFINED__
    __IPackageDebugSettings2_FWD_DEFINED__ equ <>
    ;IPackageDebugSettings2 typedef IPackageDebugSettings2
    
  endif
  ifndef __ISuspensionDependencyManager_FWD_DEFINED__
    __ISuspensionDependencyManager_FWD_DEFINED__ equ <>
    ;ISuspensionDependencyManager typedef ISuspensionDependencyManager
    
  endif
  ifndef __IExecuteCommandApplicationHostEnvironment_FWD_DEFINED__
    __IExecuteCommandApplicationHostEnvironment_FWD_DEFINED__ equ <>
    ;IExecuteCommandApplicationHostEnvironment typedef IExecuteCommandApplicationHostEnvironment
    
  endif
  ifndef __IExecuteCommandHost_FWD_DEFINED__
    __IExecuteCommandHost_FWD_DEFINED__ equ <>
    ;IExecuteCommandHost typedef IExecuteCommandHost
    
  endif
  ifndef __IApplicationDesignModeSettings_FWD_DEFINED__
    __IApplicationDesignModeSettings_FWD_DEFINED__ equ <>
    ;IApplicationDesignModeSettings typedef IApplicationDesignModeSettings
    
  endif
  ifndef __IApplicationDesignModeSettings2_FWD_DEFINED__
    __IApplicationDesignModeSettings2_FWD_DEFINED__ equ <>
    ;IApplicationDesignModeSettings2 typedef IApplicationDesignModeSettings2
    
  endif
  ifndef __ILaunchTargetMonitor_FWD_DEFINED__
    __ILaunchTargetMonitor_FWD_DEFINED__ equ <>
    ;ILaunchTargetMonitor typedef ILaunchTargetMonitor
    
  endif
  ifndef __ILaunchSourceViewSizePreference_FWD_DEFINED__
    __ILaunchSourceViewSizePreference_FWD_DEFINED__ equ <>
    ;ILaunchSourceViewSizePreference typedef ILaunchSourceViewSizePreference
    
  endif
  ifndef __ILaunchTargetViewSizePreference_FWD_DEFINED__
    __ILaunchTargetViewSizePreference_FWD_DEFINED__ equ <>
    ;ILaunchTargetViewSizePreference typedef ILaunchTargetViewSizePreference
    
  endif
  ifndef __ILaunchSourceAppUserModelId_FWD_DEFINED__
    __ILaunchSourceAppUserModelId_FWD_DEFINED__ equ <>
    ;ILaunchSourceAppUserModelId typedef ILaunchSourceAppUserModelId
    
  endif
  ifndef __IInitializeWithWindow_FWD_DEFINED__
    __IInitializeWithWindow_FWD_DEFINED__ equ <>
    ;IInitializeWithWindow typedef IInitializeWithWindow
    
  endif
  ifndef __IHandlerInfo_FWD_DEFINED__
    __IHandlerInfo_FWD_DEFINED__ equ <>
    ;IHandlerInfo typedef IHandlerInfo
    
  endif
  ifndef __IHandlerActivationHost_FWD_DEFINED__
    __IHandlerActivationHost_FWD_DEFINED__ equ <>
    ;IHandlerActivationHost typedef IHandlerActivationHost
    
  endif
  ifndef __IAppActivationUIInfo_FWD_DEFINED__
    __IAppActivationUIInfo_FWD_DEFINED__ equ <>
    ;IAppActivationUIInfo typedef IAppActivationUIInfo
    
  endif
  ifndef __IContactManagerInterop_FWD_DEFINED__
    __IContactManagerInterop_FWD_DEFINED__ equ <>
    ;IContactManagerInterop typedef IContactManagerInterop
    
  endif
  ifndef __IShellIconOverlayIdentifier_FWD_DEFINED__
    __IShellIconOverlayIdentifier_FWD_DEFINED__ equ <>
    ;IShellIconOverlayIdentifier typedef IShellIconOverlayIdentifier
    
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
          STD_METHOD QueryInterface, :ptr IContextMenu, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IContextMenu
          STD_METHOD Release, :ptr IContextMenu
          STD_METHOD QueryContextMenu, :ptr IContextMenu, :HMENU, :UINT, :UINT, :UINT, :UINT
          STD_METHOD InvokeCommand, :ptr IContextMenu, :ptr CMINVOKECOMMANDINFO
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
          STD_METHOD QueryInterface, :ptr IContextMenu2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IContextMenu2
          STD_METHOD Release, :ptr IContextMenu2
          STD_METHOD QueryContextMenu, :ptr IContextMenu2, :HMENU, :UINT, :UINT, :UINT, :UINT
          STD_METHOD InvokeCommand, :ptr IContextMenu2, :ptr CMINVOKECOMMANDINFO
          STD_METHOD GetCommandString, :ptr IContextMenu2, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
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
          STD_METHOD QueryInterface, :ptr IContextMenu3, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IContextMenu3
          STD_METHOD Release, :ptr IContextMenu3
          STD_METHOD QueryContextMenu, :ptr IContextMenu3, :HMENU, :UINT, :UINT, :UINT, :UINT
          STD_METHOD InvokeCommand, :ptr IContextMenu3, :ptr CMINVOKECOMMANDINFO
          STD_METHOD GetCommandString, :ptr IContextMenu3, :UINT_PTR, :UINT, :ptr UINT, :ptr CHAR, :UINT
          STD_METHOD HandleMenuMsg, :ptr IContextMenu3, :UINT, :WPARAM, :LPARAM
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
          STD_METHOD QueryInterface, :ptr IExecuteCommand, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IExecuteCommand
          STD_METHOD Release, :ptr IExecuteCommand
          STD_METHOD SetKeyState, :ptr IExecuteCommand, :DWORD
          STD_METHOD SetParameters, :ptr IExecuteCommand, :LPCWSTR
          STD_METHOD SetPosition, :ptr IExecuteCommand, :POINT
          STD_METHOD SetShowWindow, :ptr IExecuteCommand, :SDWORD
          STD_METHOD SetNoShowUI, :ptr IExecuteCommand, :BOOL
          STD_METHOD SetDirectory, :ptr IExecuteCommand, :LPCWSTR
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
          STD_METHOD QueryInterface, :ptr IPersistFolder, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPersistFolder
          STD_METHOD Release, :ptr IPersistFolder
          STD_METHOD GetClassID, :ptr IPersistFolder, :ptr CLSID
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
          STD_METHOD QueryInterface, :ptr IRunnableTask, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IRunnableTask
          STD_METHOD Release, :ptr IRunnableTask
          STD_METHOD Run, :ptr IRunnableTask
          STD_METHOD Kill_, :ptr IRunnableTask, :BOOL
          STD_METHOD Suspend, :ptr IRunnableTask
          STD_METHOD Resume, :ptr IRunnableTask
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
          STD_METHOD QueryInterface, :ptr IShellTaskScheduler, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellTaskScheduler
          STD_METHOD Release, :ptr IShellTaskScheduler
          STD_METHOD AddTask, :ptr IShellTaskScheduler, :ptr IRunnableTask, :REFTASKOWNERID, :DWORD_PTR, :DWORD
          STD_METHOD RemoveTasks, :ptr IShellTaskScheduler, :REFTASKOWNERID, :DWORD_PTR, :BOOL
          STD_METHOD CountTasks, :ptr IShellTaskScheduler, :REFTASKOWNERID
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
          STD_METHOD QueryInterface, :ptr IPersistFolder2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPersistFolder2
          STD_METHOD Release, :ptr IPersistFolder2
          STD_METHOD GetClassID, :ptr IPersistFolder2, :ptr CLSID
          STD_METHOD Initialize, :ptr IPersistFolder2, :PCIDLIST_ABSOLUTE
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
          STD_METHOD QueryInterface, :ptr IPersistFolder3, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPersistFolder3
          STD_METHOD Release, :ptr IPersistFolder3
          STD_METHOD GetClassID, :ptr IPersistFolder3, :ptr CLSID
          STD_METHOD Initialize, :ptr IPersistFolder3, :PCIDLIST_ABSOLUTE
          STD_METHOD GetCurFolder, :ptr IPersistFolder3, :ptr PIDLIST_ABSOLUTE
          STD_METHOD InitializeEx, :ptr IPersistFolder3, :ptr IBindCtx, :PCIDLIST_ABSOLUTE, :ptr PERSIST_FOLDER_TARGET_INFO
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
            STD_METHOD QueryInterface, :ptr IPersistIDList, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPersistIDList
            STD_METHOD Release, :ptr IPersistIDList
            STD_METHOD GetClassID, :ptr IPersistIDList, :ptr CLSID
            STD_METHOD SetIDList, :ptr IPersistIDList, :PCIDLIST_ABSOLUTE
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
          STD_METHOD QueryInterface, :ptr IEnumIDList, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumIDList
          STD_METHOD Release, :ptr IEnumIDList
          STD_METHOD Next, :ptr IEnumIDList, :ULONG, :ptr PITEMID_CHILD, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumIDList, :ULONG
          STD_METHOD Reset, :ptr IEnumIDList
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
          STD_METHOD QueryInterface, :ptr IEnumFullIDList, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumFullIDList
          STD_METHOD Release, :ptr IEnumFullIDList
          STD_METHOD Next, :ptr IEnumFullIDList, :ULONG, :ptr PIDLIST_ABSOLUTE, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumFullIDList, :ULONG
          STD_METHOD Reset, :ptr IEnumFullIDList
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
          STD_METHOD QueryInterface, :ptr IFileSyncMergeHandler, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFileSyncMergeHandler
          STD_METHOD Release, :ptr IFileSyncMergeHandler
          STD_METHOD Merge, :ptr IFileSyncMergeHandler, :LPCWSTR, :LPCWSTR, :ptr MERGE_UPDATE_STATUS
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
            STD_METHOD QueryInterface, :ptr IObjectWithFolderEnumMode, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IObjectWithFolderEnumMode
            STD_METHOD Release, :ptr IObjectWithFolderEnumMode
            STD_METHOD SetMode, :ptr IObjectWithFolderEnumMode, :FOLDER_ENUM_MODE
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
            STD_METHOD QueryInterface, :ptr IParseAndCreateItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IParseAndCreateItem
            STD_METHOD Release, :ptr IParseAndCreateItem
            STD_METHOD SetItem, :ptr IParseAndCreateItem, :ptr IShellItem
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
          STD_METHOD QueryInterface, :ptr IShellFolder, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellFolder
          STD_METHOD Release, :ptr IShellFolder
          STD_METHOD ParseDisplayName, :ptr IShellFolder, :HWND, :ptr IBindCtx, :LPWSTR, :ptr ULONG, :ptr PIDLIST_RELATIVE, :ptr ULONG
          STD_METHOD EnumObjects, :ptr IShellFolder, :HWND, :SHCONTF, :ptr ptr IEnumIDList
          STD_METHOD BindToObject, :ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          STD_METHOD BindToStorage, :ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          STD_METHOD CompareIDs, :ptr IShellFolder, :LPARAM, :PCUIDLIST_RELATIVE, :PCUIDLIST_RELATIVE
          STD_METHOD CreateViewObject, :ptr IShellFolder, :HWND, :REFIID, :ptr ptr
          STD_METHOD GetAttributesOf, :ptr IShellFolder, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr SFGAOF
          STD_METHOD GetUIObjectOf, :ptr IShellFolder, :HWND, :UINT, :PCUITEMID_CHILD_ARRAY, :REFIID, :ptr UINT, :ptr ptr
          STD_METHOD GetDisplayNameOf, :ptr IShellFolder, :PCUITEMID_CHILD, :SHGDNF, :ptr STRRET
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
          STD_METHOD QueryInterface, :ptr IEnumExtraSearch, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumExtraSearch
          STD_METHOD Release, :ptr IEnumExtraSearch
          STD_METHOD Next, :ptr IEnumExtraSearch, :ULONG, :ptr EXTRASEARCH, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumExtraSearch, :ULONG
          STD_METHOD Reset, :ptr IEnumExtraSearch
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
          STD_METHOD QueryInterface, :ptr IShellFolder2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellFolder2
          STD_METHOD Release, :ptr IShellFolder2
          STD_METHOD ParseDisplayName, :ptr IShellFolder2, :HWND, :ptr IBindCtx, :LPWSTR, :ptr ULONG, :ptr PIDLIST_RELATIVE, :ptr ULONG
          STD_METHOD EnumObjects, :ptr IShellFolder2, :HWND, :SHCONTF, :ptr ptr IEnumIDList
          STD_METHOD BindToObject, :ptr IShellFolder2, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          STD_METHOD BindToStorage, :ptr IShellFolder2, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr
          STD_METHOD CompareIDs, :ptr IShellFolder2, :LPARAM, :PCUIDLIST_RELATIVE, :PCUIDLIST_RELATIVE
          STD_METHOD CreateViewObject, :ptr IShellFolder2, :HWND, :REFIID, :ptr ptr
          STD_METHOD GetAttributesOf, :ptr IShellFolder2, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr SFGAOF
          STD_METHOD GetUIObjectOf, :ptr IShellFolder2, :HWND, :UINT, :PCUITEMID_CHILD_ARRAY, :REFIID, :ptr UINT, :ptr ptr
          STD_METHOD GetDisplayNameOf, :ptr IShellFolder2, :PCUITEMID_CHILD, :SHGDNF, :ptr STRRET
          STD_METHOD SetNameOf, :ptr IShellFolder2, :HWND, :PCUITEMID_CHILD, :LPCWSTR, :SHGDNF, :ptr PITEMID_CHILD
          STD_METHOD GetDefaultSearchGUID, :ptr IShellFolder2, :ptr GUID
          STD_METHOD EnumSearches, :ptr IShellFolder2, :ptr ptr IEnumExtraSearch
          STD_METHOD GetDefaultColumn, :ptr IShellFolder2, :DWORD, :ptr ULONG, :ptr ULONG
          STD_METHOD GetDefaultColumnState, :ptr IShellFolder2, :UINT, :ptr SHCOLSTATEF
          STD_METHOD GetDetailsEx, :ptr IShellFolder2, :PCUITEMID_CHILD, :ptr SHCOLUMNID, :ptr VARIANT
          STD_METHOD GetDetailsOf, :ptr IShellFolder2, :PCUITEMID_CHILD, :UINT, :ptr SHELLDETAILS
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
          STD_METHOD QueryInterface, :ptr IShellView, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellView
          STD_METHOD Release, :ptr IShellView
          STD_METHOD GetWindow, :ptr IShellView, :ptr HWND
          STD_METHOD ContextSensitiveHelp, :ptr IShellView, :BOOL
          STD_METHOD TranslateAccelerator, :ptr IShellView, :ptr MSG
          STD_METHOD EnableModeless, :ptr IShellView, :BOOL
          STD_METHOD UIActivate, :ptr IShellView, :UINT
          STD_METHOD Refresh, :ptr IShellView
          STD_METHOD CreateViewWindow, :ptr IShellView, :ptr IShellView, :LPCFOLDERSETTINGS, :ptr IShellBrowser, :ptr RECT, :ptr HWND
          STD_METHOD DestroyViewWindow, :ptr IShellView
          STD_METHOD GetCurrentInfo, :ptr IShellView, :LPFOLDERSETTINGS
          STD_METHOD AddPropertySheetPages, :ptr IShellView, :DWORD, :LPFNSVADDPROPSHEETPAGE, :LPARAM
          STD_METHOD SaveViewState, :ptr IShellView
          STD_METHOD SelectItem, :ptr IShellView, :PCUITEMID_CHILD, :SVSIF
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
          STD_METHOD QueryInterface, :ptr IShellView2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellView2
          STD_METHOD Release, :ptr IShellView2
          STD_METHOD GetWindow, :ptr IShellView2, :ptr HWND
          STD_METHOD ContextSensitiveHelp, :ptr IShellView2, :BOOL
          STD_METHOD TranslateAccelerator, :ptr IShellView2, :ptr MSG
          STD_METHOD EnableModeless, :ptr IShellView2, :BOOL
          STD_METHOD UIActivate, :ptr IShellView2, :UINT
          STD_METHOD Refresh, :ptr IShellView2
          STD_METHOD CreateViewWindow, :ptr IShellView2, :ptr IShellView, :LPCFOLDERSETTINGS, :ptr IShellBrowser, :ptr RECT, :ptr HWND
          STD_METHOD DestroyViewWindow, :ptr IShellView2
          STD_METHOD GetCurrentInfo, :ptr IShellView2, :LPFOLDERSETTINGS
          STD_METHOD AddPropertySheetPages, :ptr IShellView2, :DWORD, :LPFNSVADDPROPSHEETPAGE, :LPARAM
          STD_METHOD SaveViewState, :ptr IShellView2
          STD_METHOD SelectItem, :ptr IShellView2, :PCUITEMID_CHILD, :SVSIF
          STD_METHOD GetItemObject, :ptr IShellView2, :UINT, :REFIID, :ptr ptr
          STD_METHOD GetView, :ptr IShellView2, :ptr SHELLVIEWID, :ULONG
          STD_METHOD CreateViewWindow2, :ptr IShellView2, :LPSV2CVW2_PARAMS
          STD_METHOD HandleRename, :ptr IShellView2, :PCUITEMID_CHILD
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
          STD_METHOD QueryInterface, :ptr IFolderView, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFolderView
          STD_METHOD Release, :ptr IFolderView
          STD_METHOD GetCurrentViewMode, :ptr IFolderView, :ptr UINT
          STD_METHOD SetCurrentViewMode, :ptr IFolderView, :UINT
          STD_METHOD GetFolder, :ptr IFolderView, :REFIID, :ptr ptr
          STD_METHOD Item, :ptr IFolderView, :SDWORD, :ptr PITEMID_CHILD
          STD_METHOD ItemCount, :ptr IFolderView, :UINT, :ptr SDWORD
          STD_METHOD Items, :ptr IFolderView, :UINT, :REFIID, :ptr ptr
          STD_METHOD GetSelectionMarkedItem, :ptr IFolderView, :ptr SDWORD
          STD_METHOD GetFocusedItem, :ptr IFolderView, :ptr SDWORD
          STD_METHOD GetItemPosition, :ptr IFolderView, :PCUITEMID_CHILD, :ptr POINT
          STD_METHOD GetSpacing, :ptr IFolderView, :ptr POINT
          STD_METHOD GetDefaultSpacing, :ptr IFolderView, :ptr POINT
          STD_METHOD GetAutoArrange, :ptr IFolderView
          STD_METHOD SelectItem, :ptr IFolderView, :SDWORD, :DWORD
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
            STD_METHOD QueryInterface, :ptr IFolderView2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFolderView2
            STD_METHOD Release, :ptr IFolderView2
            STD_METHOD GetCurrentViewMode, :ptr IFolderView2, :ptr UINT
            STD_METHOD SetCurrentViewMode, :ptr IFolderView2, :UINT
            STD_METHOD GetFolder, :ptr IFolderView2, :REFIID, :ptr ptr
            STD_METHOD Item, :ptr IFolderView2, :SDWORD, :ptr PITEMID_CHILD
            STD_METHOD ItemCount, :ptr IFolderView2, :UINT, :ptr SDWORD
            STD_METHOD Items, :ptr IFolderView2, :UINT, :REFIID, :ptr ptr
            STD_METHOD GetSelectionMarkedItem, :ptr IFolderView2, :ptr SDWORD
            STD_METHOD GetFocusedItem, :ptr IFolderView2, :ptr SDWORD
            STD_METHOD GetItemPosition, :ptr IFolderView2, :PCUITEMID_CHILD, :ptr POINT
            STD_METHOD GetSpacing, :ptr IFolderView2, :ptr POINT
            STD_METHOD GetDefaultSpacing, :ptr IFolderView2, :ptr POINT
            STD_METHOD GetAutoArrange, :ptr IFolderView2
            STD_METHOD SelectItem, :ptr IFolderView2, :SDWORD, :DWORD
            STD_METHOD SelectAndPositionItems, :ptr IFolderView2, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr POINT, :DWORD
            STD_METHOD SetGroupBy, :ptr IFolderView2, :REFPROPERTYKEY, :BOOL
            STD_METHOD GetGroupBy, :ptr IFolderView2, :ptr PROPERTYKEY, :ptr BOOL
            STD_METHOD SetViewProperty, :ptr IFolderView2, :PCUITEMID_CHILD, :REFPROPERTYKEY, :REFPROPVARIANT
            STD_METHOD GetViewProperty, :ptr IFolderView2, :PCUITEMID_CHILD, :REFPROPERTYKEY, :ptr PROPVARIANT
            STD_METHOD SetTileViewProperties, :ptr IFolderView2, :PCUITEMID_CHILD, :LPCWSTR
            STD_METHOD SetExtendedTileViewProperties, :ptr IFolderView2, :PCUITEMID_CHILD, :LPCWSTR
            STD_METHOD SetText, :ptr IFolderView2, :FVTEXTTYPE, :LPCWSTR
            STD_METHOD SetCurrentFolderFlags, :ptr IFolderView2, :DWORD, :DWORD
            STD_METHOD GetCurrentFolderFlags, :ptr IFolderView2, :ptr DWORD
            STD_METHOD GetSortColumnCount, :ptr IFolderView2, :ptr SDWORD
            STD_METHOD SetSortColumns, :ptr IFolderView2, :ptr SORTCOLUMN, :SDWORD
            STD_METHOD GetSortColumns, :ptr IFolderView2, :ptr SORTCOLUMN, :SDWORD
            STD_METHOD GetItem, :ptr IFolderView2, :SDWORD, :REFIID, :ptr ptr
            STD_METHOD GetVisibleItem, :ptr IFolderView2, :SDWORD, :BOOL, :ptr SDWORD
            STD_METHOD GetSelectedItem, :ptr IFolderView2, :SDWORD, :ptr SDWORD
            STD_METHOD GetSelection, :ptr IFolderView2, :BOOL, :ptr ptr IShellItemArray
            STD_METHOD GetSelectionState, :ptr IFolderView2, :PCUITEMID_CHILD, :ptr DWORD
            STD_METHOD InvokeVerbOnSelection, :ptr IFolderView2, :LPCSTR
            STD_METHOD SetViewModeAndIconSize, :ptr IFolderView2, :FOLDERVIEWMODE, :SDWORD
            STD_METHOD GetViewModeAndIconSize, :ptr IFolderView2, :ptr FOLDERVIEWMODE, :ptr SDWORD
            STD_METHOD SetGroupSubsetCount, :ptr IFolderView2, :UINT
            STD_METHOD GetGroupSubsetCount, :ptr IFolderView2, :ptr UINT
            STD_METHOD SetRedraw, :ptr IFolderView2, :BOOL
            STD_METHOD IsMoveInSameFolder, :ptr IFolderView2
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
              STD_METHOD QueryInterface, :ptr IFolderViewSettings, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IFolderViewSettings
              STD_METHOD Release, :ptr IFolderViewSettings
              STD_METHOD GetColumnPropertyList, :ptr IFolderViewSettings, :REFIID, :ptr ptr
              STD_METHOD GetGroupByProperty, :ptr IFolderViewSettings, :ptr PROPERTYKEY, :ptr BOOL
              STD_METHOD GetViewMode, :ptr IFolderViewSettings, :ptr FOLDERLOGICALVIEWMODE
              STD_METHOD GetIconSize, :ptr IFolderViewSettings, :ptr UINT
              STD_METHOD GetFolderFlags, :ptr IFolderViewSettings, :ptr FOLDERFLAGS, :ptr FOLDERFLAGS
              STD_METHOD GetSortColumns, :ptr IFolderViewSettings, :ptr SORTCOLUMN, :UINT, :ptr UINT
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
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      externdef __MIDL_itf_shobjidl_core_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPreviewHandlerVisuals_INTERFACE_DEFINED__
        __IPreviewHandlerVisuals_INTERFACE_DEFINED__ equ <>
        externdef IID_IPreviewHandlerVisuals:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPreviewHandlerVisualsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPreviewHandlerVisualsVtbl>
            STD_METHOD QueryInterface, :ptr IPreviewHandlerVisuals, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPreviewHandlerVisuals
            STD_METHOD Release, :ptr IPreviewHandlerVisuals
            STD_METHOD SetBackgroundColor, :ptr IPreviewHandlerVisuals, :COLORREF
            STD_METHOD SetFont, :ptr IPreviewHandlerVisuals, :ptr LOGFONTW
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
    externdef __MIDL_itf_shobjidl_core_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ICommDlgBrowser_INTERFACE_DEFINED__
      __ICommDlgBrowser_INTERFACE_DEFINED__ equ <>
      externdef IID_ICommDlgBrowser:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICommDlgBrowserVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICommDlgBrowserVtbl>
          STD_METHOD QueryInterface, :ptr ICommDlgBrowser, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICommDlgBrowser
          STD_METHOD Release, :ptr ICommDlgBrowser
          STD_METHOD OnDefaultCommand, :ptr ICommDlgBrowser, :ptr IShellView
          STD_METHOD OnStateChange, :ptr ICommDlgBrowser, :ptr IShellView, :ULONG
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
      externdef __MIDL_itf_shobjidl_core_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICommDlgBrowser2_INTERFACE_DEFINED__
        __ICommDlgBrowser2_INTERFACE_DEFINED__ equ <>
        externdef IID_ICommDlgBrowser2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICommDlgBrowser2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICommDlgBrowser2Vtbl>
            STD_METHOD QueryInterface, :ptr ICommDlgBrowser2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICommDlgBrowser2
            STD_METHOD Release, :ptr ICommDlgBrowser2
            STD_METHOD OnDefaultCommand, :ptr ICommDlgBrowser2, :ptr IShellView
            STD_METHOD OnStateChange, :ptr ICommDlgBrowser2, :ptr IShellView, :ULONG
            STD_METHOD IncludeObject, :ptr ICommDlgBrowser2, :ptr IShellView, :PCUITEMID_CHILD
            STD_METHOD Notify, :ptr ICommDlgBrowser2, :ptr IShellView, :DWORD
            STD_METHOD GetDefaultMenuText, :ptr ICommDlgBrowser2, :ptr IShellView, :LPWSTR, :SDWORD
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
      externdef __MIDL_itf_shobjidl_core_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IColumnManager_INTERFACE_DEFINED__
        __IColumnManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IColumnManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IColumnManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IColumnManagerVtbl>
            STD_METHOD QueryInterface, :ptr IColumnManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IColumnManager
            STD_METHOD Release, :ptr IColumnManager
            STD_METHOD SetColumnInfo, :ptr IColumnManager, :REFPROPERTYKEY, :ptr CM_COLUMNINFO
            STD_METHOD GetColumnInfo, :ptr IColumnManager, :REFPROPERTYKEY, :ptr CM_COLUMNINFO
            STD_METHOD GetColumnCount, :ptr IColumnManager, :CM_ENUM_FLAGS, :ptr UINT
            STD_METHOD GetColumns, :ptr IColumnManager, :CM_ENUM_FLAGS, :ptr PROPERTYKEY, :UINT
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
    externdef __MIDL_itf_shobjidl_core_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFolderFilterSite_INTERFACE_DEFINED__
      __IFolderFilterSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IFolderFilterSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFolderFilterSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFolderFilterSiteVtbl>
          STD_METHOD QueryInterface, :ptr IFolderFilterSite, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFolderFilterSite
          STD_METHOD Release, :ptr IFolderFilterSite
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
          STD_METHOD QueryInterface, :ptr IFolderFilter, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFolderFilter
          STD_METHOD Release, :ptr IFolderFilter
          STD_METHOD ShouldShow, :ptr IFolderFilter, :ptr IShellFolder, :PCIDLIST_ABSOLUTE, :PCUITEMID_CHILD
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
          STD_METHOD QueryInterface, :ptr IInputObjectSite, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInputObjectSite
          STD_METHOD Release, :ptr IInputObjectSite
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
          STD_METHOD QueryInterface, :ptr IInputObject, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInputObject
          STD_METHOD Release, :ptr IInputObject
          STD_METHOD UIActivateIO, :ptr IInputObject, :BOOL, :ptr MSG
          STD_METHOD HasFocusIO, :ptr IInputObject
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
          STD_METHOD QueryInterface, :ptr IInputObject2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInputObject2
          STD_METHOD Release, :ptr IInputObject2
          STD_METHOD UIActivateIO, :ptr IInputObject2, :BOOL, :ptr MSG
          STD_METHOD HasFocusIO, :ptr IInputObject2
          STD_METHOD TranslateAcceleratorIO, :ptr IInputObject2, :ptr MSG
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
          STD_METHOD QueryInterface, :ptr IShellIcon, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellIcon
          STD_METHOD Release, :ptr IShellIcon
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
    externdef __MIDL_itf_shobjidl_core_0000_0033_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0033_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellBrowser_INTERFACE_DEFINED__
      __IShellBrowser_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellBrowser:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellBrowserVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellBrowserVtbl>
          STD_METHOD QueryInterface, :ptr IShellBrowser, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellBrowser
          STD_METHOD Release, :ptr IShellBrowser
          STD_METHOD GetWindow, :ptr IShellBrowser, :ptr HWND
          STD_METHOD ContextSensitiveHelp, :ptr IShellBrowser, :BOOL
          STD_METHOD InsertMenusSB, :ptr IShellBrowser, :HMENU, :LPOLEMENUGROUPWIDTHS
          STD_METHOD SetMenuSB, :ptr IShellBrowser, :HMENU, :HOLEMENU, :HWND
          STD_METHOD RemoveMenusSB, :ptr IShellBrowser, :HMENU
          STD_METHOD SetStatusTextSB, :ptr IShellBrowser, :LPCWSTR
          STD_METHOD EnableModelessSB, :ptr IShellBrowser, :BOOL
          STD_METHOD TranslateAcceleratorSB, :ptr IShellBrowser, :ptr MSG, :WORD
          STD_METHOD BrowseObject, :ptr IShellBrowser, :PCUIDLIST_RELATIVE, :UINT
          STD_METHOD GetViewStateStream, :ptr IShellBrowser, :DWORD, :ptr ptr IStream
          STD_METHOD GetControlWindow, :ptr IShellBrowser, :UINT, :ptr HWND
          STD_METHOD SendControlMsg, :ptr IShellBrowser, :UINT, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
          STD_METHOD QueryActiveShellView, :ptr IShellBrowser, :ptr ptr IShellView
          STD_METHOD OnViewWindowActive, :ptr IShellBrowser, :ptr IShellView
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
    externdef __MIDL_itf_shobjidl_core_0000_0034_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0034_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IProfferService_INTERFACE_DEFINED__
      __IProfferService_INTERFACE_DEFINED__ equ <>
      externdef IID_IProfferService:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProfferServiceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProfferServiceVtbl>
          STD_METHOD QueryInterface, :ptr IProfferService, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IProfferService
          STD_METHOD Release, :ptr IProfferService
          STD_METHOD ProfferService, :ptr IProfferService, :REFGUID, :ptr IServiceProvider, :ptr DWORD
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
    STR_DONT_RESOLVE_LINK equ <L("Don't Resolve Link")>
    STR_GET_ASYNC_HANDLER equ <L("GetAsyncHandler")>
    externdef __MIDL_itf_shobjidl_core_0000_0035_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0035_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IShellItem, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellItem
          STD_METHOD Release, :ptr IShellItem
          STD_METHOD BindToHandler, :ptr IShellItem, :ptr IBindCtx, :REFGUID, :REFIID, :ptr ptr
          STD_METHOD GetParent, :ptr IShellItem, :ptr ptr IShellItem
          STD_METHOD GetDisplayName, :ptr IShellItem, :SIGDN, :ptr LPWSTR
          STD_METHOD GetAttributes, :ptr IShellItem, :SFGAOF, :ptr SFGAOF
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
    externdef __MIDL_itf_shobjidl_core_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellItem2_INTERFACE_DEFINED__
      __IShellItem2_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellItem2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItem2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItem2Vtbl>
          STD_METHOD QueryInterface, :ptr IShellItem2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellItem2
          STD_METHOD Release, :ptr IShellItem2
          STD_METHOD BindToHandler, :ptr IShellItem2, :ptr IBindCtx, :REFGUID, :REFIID, :ptr ptr
          STD_METHOD GetParent, :ptr IShellItem2, :ptr ptr IShellItem
          STD_METHOD GetDisplayName, :ptr IShellItem2, :SIGDN, :ptr LPWSTR
          STD_METHOD GetAttributes, :ptr IShellItem2, :SFGAOF, :ptr SFGAOF
          STD_METHOD Compare, :ptr IShellItem2, :ptr IShellItem, :SICHINTF, :ptr SDWORD
          STD_METHOD GetPropertyStore, :ptr IShellItem2, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          STD_METHOD GetPropertyStoreWithCreateObject, :ptr IShellItem2, :GETPROPERTYSTOREFLAGS, :ptr IUnknown, :REFIID, :ptr ptr
          STD_METHOD GetPropertyStoreForKeys, :ptr IShellItem2, :ptr PROPERTYKEY, :UINT, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          STD_METHOD GetPropertyDescriptionList, :ptr IShellItem2, :REFPROPERTYKEY, :REFIID, :ptr ptr
          STD_METHOD Update, :ptr IShellItem2, :ptr IBindCtx
          STD_METHOD GetProperty, :ptr IShellItem2, :REFPROPERTYKEY, :ptr PROPVARIANT
          STD_METHOD GetCLSID, :ptr IShellItem2, :REFPROPERTYKEY, :ptr CLSID
          STD_METHOD GetFileTime, :ptr IShellItem2, :REFPROPERTYKEY, :ptr FILETIME
          STD_METHOD GetInt32, :ptr IShellItem2, :REFPROPERTYKEY, :ptr SDWORD
          STD_METHOD GetString, :ptr IShellItem2, :REFPROPERTYKEY, :ptr LPWSTR
          STD_METHOD GetUInt32, :ptr IShellItem2, :REFPROPERTYKEY, :ptr ULONG
          STD_METHOD GetUInt64, :ptr IShellItem2, :REFPROPERTYKEY, :ptr ULONGLONG
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
    externdef __MIDL_itf_shobjidl_core_0000_0037_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0037_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellItemImageFactory_INTERFACE_DEFINED__
      __IShellItemImageFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellItemImageFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellItemImageFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellItemImageFactoryVtbl>
          STD_METHOD QueryInterface, :ptr IShellItemImageFactory, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellItemImageFactory
          STD_METHOD Release, :ptr IShellItemImageFactory
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
      externdef __MIDL_itf_shobjidl_core_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumShellItems_INTERFACE_DEFINED__
        __IEnumShellItems_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumShellItems:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumShellItemsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumShellItemsVtbl>
            STD_METHOD QueryInterface, :ptr IEnumShellItems, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IEnumShellItems
            STD_METHOD Release, :ptr IEnumShellItems
            STD_METHOD Next, :ptr IEnumShellItems, :ULONG, :ptr ptr IShellItem, :ptr ULONG
            STD_METHOD Skip, :ptr IEnumShellItems, :ULONG
            STD_METHOD Reset, :ptr IEnumShellItems
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
      externdef __MIDL_itf_shobjidl_core_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr ITransferAdviseSink, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ITransferAdviseSink
            STD_METHOD Release, :ptr ITransferAdviseSink
            STD_METHOD UpdateProgress, :ptr ITransferAdviseSink, :ULONGLONG, :ULONGLONG, :SDWORD, :SDWORD, :SDWORD, :SDWORD
            STD_METHOD UpdateTransferState, :ptr ITransferAdviseSink, :TRANSFER_ADVISE_STATE
            STD_METHOD ConfirmOverwrite, :ptr ITransferAdviseSink, :ptr IShellItem, :ptr IShellItem, :LPCWSTR
            STD_METHOD ConfirmEncryptionLoss, :ptr ITransferAdviseSink, :ptr IShellItem
            STD_METHOD FileFailure, :ptr ITransferAdviseSink, :ptr IShellItem, :LPCWSTR, :HRESULT, :LPWSTR, :ULONG
            STD_METHOD SubStreamFailure, :ptr ITransferAdviseSink, :ptr IShellItem, :LPCWSTR, :HRESULT
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
      externdef __MIDL_itf_shobjidl_core_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ITransferSource_INTERFACE_DEFINED__
        __ITransferSource_INTERFACE_DEFINED__ equ <>
        externdef IID_ITransferSource:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITransferSourceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITransferSourceVtbl>
            STD_METHOD QueryInterface, :ptr ITransferSource, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ITransferSource
            STD_METHOD Release, :ptr ITransferSource
            STD_METHOD Advise, :ptr ITransferSource, :ptr ITransferAdviseSink, :ptr DWORD
            STD_METHOD Unadvise, :ptr ITransferSource, :DWORD
            STD_METHOD SetProperties, :ptr ITransferSource, :ptr IPropertyChangeArray
            STD_METHOD OpenItem, :ptr ITransferSource, :ptr IShellItem, :TRANSFER_SOURCE_FLAGS, :REFIID, :ptr ptr
            STD_METHOD MoveItem, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            STD_METHOD RecycleItem, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            STD_METHOD RemoveItem, :ptr ITransferSource, :ptr IShellItem, :TRANSFER_SOURCE_FLAGS
            STD_METHOD RenameItem, :ptr ITransferSource, :ptr IShellItem, :LPCWSTR, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            STD_METHOD LinkItem, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :TRANSFER_SOURCE_FLAGS, :ptr ptr IShellItem
            STD_METHOD ApplyPropertiesToItem, :ptr ITransferSource, :ptr IShellItem, :ptr ptr IShellItem
            STD_METHOD GetDefaultDestinationName, :ptr ITransferSource, :ptr IShellItem, :ptr IShellItem, :ptr LPWSTR
            STD_METHOD EnterFolder, :ptr ITransferSource, :ptr IShellItem
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
    externdef __MIDL_itf_shobjidl_core_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumResources_INTERFACE_DEFINED__
      __IEnumResources_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumResources:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumResourcesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumResourcesVtbl>
          STD_METHOD QueryInterface, :ptr IEnumResources, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumResources
          STD_METHOD Release, :ptr IEnumResources
          STD_METHOD Next, :ptr IEnumResources, :ULONG, :ptr SHELL_ITEM_RESOURCE, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumResources, :ULONG
          STD_METHOD Reset, :ptr IEnumResources
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
          STD_METHOD QueryInterface, :ptr IShellItemResources, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellItemResources
          STD_METHOD Release, :ptr IShellItemResources
          STD_METHOD GetAttributes, :ptr IShellItemResources, :ptr DWORD
          STD_METHOD GetSize, :ptr IShellItemResources, :ptr ULONGLONG
          STD_METHOD GetTimes, :ptr IShellItemResources, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
          STD_METHOD SetTimes, :ptr IShellItemResources, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
          STD_METHOD GetResourceDescription, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE, :ptr LPWSTR
          STD_METHOD EnumResources, :ptr IShellItemResources, :ptr ptr IEnumResources
          STD_METHOD SupportsResource, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE
          STD_METHOD OpenResource, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE, :REFIID, :ptr ptr
          STD_METHOD CreateResource, :ptr IShellItemResources, :ptr SHELL_ITEM_RESOURCE, :REFIID, :ptr ptr
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
          STD_METHOD QueryInterface, :ptr ITransferDestination, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITransferDestination
          STD_METHOD Release, :ptr ITransferDestination
          STD_METHOD Advise, :ptr ITransferDestination, :ptr ITransferAdviseSink, :ptr DWORD
          STD_METHOD Unadvise, :ptr ITransferDestination, :DWORD
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
      externdef __MIDL_itf_shobjidl_core_0000_0044_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0044_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileOperationProgressSink_INTERFACE_DEFINED__
        __IFileOperationProgressSink_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileOperationProgressSink:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileOperationProgressSinkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileOperationProgressSinkVtbl>
            STD_METHOD QueryInterface, :ptr IFileOperationProgressSink, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileOperationProgressSink
            STD_METHOD Release, :ptr IFileOperationProgressSink
            STD_METHOD StartOperations, :ptr IFileOperationProgressSink
            STD_METHOD FinishOperations, :ptr IFileOperationProgressSink, :HRESULT
            STD_METHOD PreRenameItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR
            STD_METHOD PostRenameItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR, :HRESULT, :ptr IShellItem
            STD_METHOD PreMoveItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR
            STD_METHOD PostMoveItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :HRESULT, :ptr IShellItem
            STD_METHOD PreCopyItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR
            STD_METHOD PostCopyItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :HRESULT, :ptr IShellItem
            STD_METHOD PreDeleteItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem
            STD_METHOD PostDeleteItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :HRESULT, :ptr IShellItem
            STD_METHOD PreNewItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR
            STD_METHOD PostNewItem, :ptr IFileOperationProgressSink, :DWORD, :ptr IShellItem, :LPCWSTR, :LPCWSTR, :DWORD, :HRESULT, :ptr IShellItem
            STD_METHOD UpdateProgress, :ptr IFileOperationProgressSink, :UINT, :UINT
            STD_METHOD ResetTimer, :ptr IFileOperationProgressSink
            STD_METHOD PauseTimer, :ptr IFileOperationProgressSink
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
    externdef __MIDL_itf_shobjidl_core_0000_0045_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0045_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IShellItemArray, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellItemArray
          STD_METHOD Release, :ptr IShellItemArray
          STD_METHOD BindToHandler, :ptr IShellItemArray, :ptr IBindCtx, :REFGUID, :REFIID, :ptr ptr
          STD_METHOD GetPropertyStore, :ptr IShellItemArray, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          STD_METHOD GetPropertyDescriptionList, :ptr IShellItemArray, :REFPROPERTYKEY, :REFIID, :ptr ptr
          STD_METHOD GetAttributes, :ptr IShellItemArray, :SIATTRIBFLAGS, :SFGAOF, :ptr SFGAOF
          STD_METHOD GetCount, :ptr IShellItemArray, :ptr DWORD
          STD_METHOD GetItemAt, :ptr IShellItemArray, :DWORD, :ptr ptr IShellItem
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
    externdef __MIDL_itf_shobjidl_core_0000_0046_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0046_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IInitializeWithItem_INTERFACE_DEFINED__
      __IInitializeWithItem_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeWithItem:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeWithItemVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeWithItemVtbl>
          STD_METHOD QueryInterface, :ptr IInitializeWithItem, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInitializeWithItem
          STD_METHOD Release, :ptr IInitializeWithItem
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
          STD_METHOD QueryInterface, :ptr IObjectWithSelection, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IObjectWithSelection
          STD_METHOD Release, :ptr IObjectWithSelection
          STD_METHOD SetSelection, :ptr IObjectWithSelection, :ptr IShellItemArray
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
          STD_METHOD QueryInterface, :ptr IObjectWithBackReferences, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IObjectWithBackReferences
          STD_METHOD Release, :ptr IObjectWithBackReferences
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
    externdef __MIDL_itf_shobjidl_core_0000_0049_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0049_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertyUI_INTERFACE_DEFINED__
      __IPropertyUI_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyUI:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyUIVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyUIVtbl>
          STD_METHOD QueryInterface, :ptr IPropertyUI, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPropertyUI
          STD_METHOD Release, :ptr IPropertyUI
          STD_METHOD ParsePropertyName, :ptr IPropertyUI, :LPCWSTR, :ptr FMTID, :ptr PROPID, :ptr ULONG
          STD_METHOD GetCannonicalName, :ptr IPropertyUI, :REFFMTID, :PROPID, :LPWSTR, :DWORD
          STD_METHOD GetDisplayName, :ptr IPropertyUI, :REFFMTID, :PROPID, :PROPERTYUI_NAME_FLAGS, :LPWSTR, :DWORD
          STD_METHOD GetPropertyDescription, :ptr IPropertyUI, :REFFMTID, :PROPID, :LPWSTR, :DWORD
          STD_METHOD GetDefaultWidth, :ptr IPropertyUI, :REFFMTID, :PROPID, :ptr ULONG
          STD_METHOD GetFlags, :ptr IPropertyUI, :REFFMTID, :PROPID, :ptr PROPERTYUI_FLAGS
          STD_METHOD FormatForDisplay, :ptr IPropertyUI, :REFFMTID, :PROPID, :ptr PROPVARIANT, :PROPERTYUI_FORMAT_FLAGS, :LPWSTR, :DWORD
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
          STD_METHOD QueryInterface, :ptr ICategoryProvider, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICategoryProvider
          STD_METHOD Release, :ptr ICategoryProvider
          STD_METHOD CanCategorizeOnSCID, :ptr ICategoryProvider, :ptr SHCOLUMNID
          STD_METHOD GetDefaultCategory, :ptr ICategoryProvider, :ptr GUID, :ptr SHCOLUMNID
          STD_METHOD GetCategoryForSCID, :ptr ICategoryProvider, :ptr SHCOLUMNID, :ptr GUID
          STD_METHOD EnumCategories, :ptr ICategoryProvider, :ptr ptr IEnumGUID
          STD_METHOD GetCategoryName, :ptr ICategoryProvider, :ptr GUID, :LPWSTR, :UINT
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
    externdef __MIDL_itf_shobjidl_core_0000_0051_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0051_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ICategorizer_INTERFACE_DEFINED__
      __ICategorizer_INTERFACE_DEFINED__ equ <>
      externdef IID_ICategorizer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICategorizerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICategorizerVtbl>
          STD_METHOD QueryInterface, :ptr ICategorizer, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICategorizer
          STD_METHOD Release, :ptr ICategorizer
          STD_METHOD GetDescription, :ptr ICategorizer, :LPWSTR, :UINT
          STD_METHOD GetCategory, :ptr ICategorizer, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr DWORD
          STD_METHOD GetCategoryInfo, :ptr ICategorizer, :DWORD, :ptr CATEGORY_INFO
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
        sizeDragImage SIZE_ <>
        ptOffset POINT <>
        hbmpDragImage HBITMAP ?
        crColorKey COLORREF ?
      SHDRAGIMAGE ends
      LPSHDRAGIMAGE typedef ptr SHDRAGIMAGE
      
      include poppack.inc
      DI_GETDRAGIMAGE equ <TEXT("ShellGetDragImage")>
      externdef __MIDL_itf_shobjidl_core_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDropTargetHelper_INTERFACE_DEFINED__
        __IDropTargetHelper_INTERFACE_DEFINED__ equ <>
        externdef IID_IDropTargetHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDropTargetHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDropTargetHelperVtbl>
            STD_METHOD QueryInterface, :ptr IDropTargetHelper, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDropTargetHelper
            STD_METHOD Release, :ptr IDropTargetHelper
            STD_METHOD DragEnter, :ptr IDropTargetHelper, :HWND, :ptr IDataObject, :ptr POINT, :DWORD
            STD_METHOD DragLeave, :ptr IDropTargetHelper
            STD_METHOD DragOver, :ptr IDropTargetHelper, :ptr POINT, :DWORD
            STD_METHOD Drop, :ptr IDropTargetHelper, :ptr IDataObject, :ptr POINT, :DWORD
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
            STD_METHOD QueryInterface, :ptr IDragSourceHelper, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDragSourceHelper
            STD_METHOD Release, :ptr IDragSourceHelper
            STD_METHOD InitializeFromBitmap, :ptr IDragSourceHelper, :LPSHDRAGIMAGE, :ptr IDataObject
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
    externdef __MIDL_itf_shobjidl_core_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IShellLinkA_INTERFACE_DEFINED__
      __IShellLinkA_INTERFACE_DEFINED__ equ <>
      externdef IID_IShellLinkA:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IShellLinkAVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IShellLinkAVtbl>
          STD_METHOD QueryInterface, :ptr IShellLinkA, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellLinkA
          STD_METHOD Release, :ptr IShellLinkA
          STD_METHOD GetPath, :ptr IShellLinkA, :LPSTR, :SDWORD, :ptr WIN32_FIND_DATAA, :DWORD
          STD_METHOD GetIDList, :ptr IShellLinkA, :ptr PIDLIST_ABSOLUTE
          STD_METHOD SetIDList, :ptr IShellLinkA, :PCIDLIST_ABSOLUTE
          STD_METHOD GetDescription, :ptr IShellLinkA, :LPSTR, :SDWORD
          STD_METHOD SetDescription, :ptr IShellLinkA, :LPCSTR
          STD_METHOD GetWorkingDirectory, :ptr IShellLinkA, :LPSTR, :SDWORD
          STD_METHOD SetWorkingDirectory, :ptr IShellLinkA, :LPCSTR
          STD_METHOD GetArguments, :ptr IShellLinkA, :LPSTR, :SDWORD
          STD_METHOD SetArguments, :ptr IShellLinkA, :LPCSTR
          STD_METHOD GetHotkey, :ptr IShellLinkA, :ptr WORD
          STD_METHOD SetHotkey, :ptr IShellLinkA, :WORD
          STD_METHOD GetShowCmd, :ptr IShellLinkA, :ptr SDWORD
          STD_METHOD SetShowCmd, :ptr IShellLinkA, :SDWORD
          STD_METHOD GetIconLocation, :ptr IShellLinkA, :LPSTR, :SDWORD, :ptr SDWORD
          STD_METHOD SetIconLocation, :ptr IShellLinkA, :LPCSTR, :SDWORD
          STD_METHOD SetRelativePath, :ptr IShellLinkA, :LPCSTR, :DWORD
          STD_METHOD Resolve, :ptr IShellLinkA, :HWND, :DWORD
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
          STD_METHOD QueryInterface, :ptr IShellLinkW, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellLinkW
          STD_METHOD Release, :ptr IShellLinkW
          STD_METHOD GetPath, :ptr IShellLinkW, :LPWSTR, :SDWORD, :ptr WIN32_FIND_DATAW, :DWORD
          STD_METHOD GetIDList, :ptr IShellLinkW, :ptr PIDLIST_ABSOLUTE
          STD_METHOD SetIDList, :ptr IShellLinkW, :PCIDLIST_ABSOLUTE
          STD_METHOD GetDescription, :ptr IShellLinkW, :LPWSTR, :SDWORD
          STD_METHOD SetDescription, :ptr IShellLinkW, :LPCWSTR
          STD_METHOD GetWorkingDirectory, :ptr IShellLinkW, :LPWSTR, :SDWORD
          STD_METHOD SetWorkingDirectory, :ptr IShellLinkW, :LPCWSTR
          STD_METHOD GetArguments, :ptr IShellLinkW, :LPWSTR, :SDWORD
          STD_METHOD SetArguments, :ptr IShellLinkW, :LPCWSTR
          STD_METHOD GetHotkey, :ptr IShellLinkW, :ptr WORD
          STD_METHOD SetHotkey, :ptr IShellLinkW, :WORD
          STD_METHOD GetShowCmd, :ptr IShellLinkW, :ptr SDWORD
          STD_METHOD SetShowCmd, :ptr IShellLinkW, :SDWORD
          STD_METHOD GetIconLocation, :ptr IShellLinkW, :LPWSTR, :SDWORD, :ptr SDWORD
          STD_METHOD SetIconLocation, :ptr IShellLinkW, :LPCWSTR, :SDWORD
          STD_METHOD SetRelativePath, :ptr IShellLinkW, :LPCWSTR, :DWORD
          STD_METHOD Resolve, :ptr IShellLinkW, :HWND, :DWORD
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
          STD_METHOD QueryInterface, :ptr IShellLinkDataList, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellLinkDataList
          STD_METHOD Release, :ptr IShellLinkDataList
          STD_METHOD AddDataBlock, :ptr IShellLinkDataList, :ptr
          STD_METHOD CopyDataBlock, :ptr IShellLinkDataList, :DWORD, :ptr ptr
          STD_METHOD RemoveDataBlock, :ptr IShellLinkDataList, :DWORD
          STD_METHOD GetFlags, :ptr IShellLinkDataList, :ptr DWORD
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
      externdef __MIDL_itf_shobjidl_core_0000_0057_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0057_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IResolveShellLink_INTERFACE_DEFINED__
        __IResolveShellLink_INTERFACE_DEFINED__ equ <>
        externdef IID_IResolveShellLink:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IResolveShellLinkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IResolveShellLinkVtbl>
            STD_METHOD QueryInterface, :ptr IResolveShellLink, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IResolveShellLink
            STD_METHOD Release, :ptr IResolveShellLink
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
    externdef __MIDL_itf_shobjidl_core_0000_0058_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0058_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IActionProgressDialog, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IActionProgressDialog
          STD_METHOD Release, :ptr IActionProgressDialog
          STD_METHOD Initialize, :ptr IActionProgressDialog, :SPINITF, :LPCWSTR, :LPCWSTR
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
    externdef __MIDL_itf_shobjidl_core_0000_0059_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0059_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IActionProgress, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IActionProgress
          STD_METHOD Release, :ptr IActionProgress
          STD_METHOD Begin, :ptr IActionProgress, :SPACTION, :SPBEGINF
          STD_METHOD UpdateProgress, :ptr IActionProgress, :ULONGLONG, :ULONGLONG
          STD_METHOD UpdateText, :ptr IActionProgress, :SPTEXT, :LPCWSTR, :BOOL
          STD_METHOD QueryCancel, :ptr IActionProgress, :ptr BOOL
          STD_METHOD ResetCancel, :ptr IActionProgress
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
          STD_METHOD QueryInterface, :ptr IShellExtInit, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellExtInit
          STD_METHOD Release, :ptr IShellExtInit
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
    endif
    LPSHELLEXTINIT typedef ptr IShellExtInit
    externdef __MIDL_itf_shobjidl_core_0000_0061_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0061_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IShellPropSheetExt, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellPropSheetExt
          STD_METHOD Release, :ptr IShellPropSheetExt
          STD_METHOD AddPages, :ptr IShellPropSheetExt, :LPFNSVADDPROPSHEETPAGE, :LPARAM
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
    externdef __MIDL_itf_shobjidl_core_0000_0062_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0062_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IRemoteComputer_INTERFACE_DEFINED__
      __IRemoteComputer_INTERFACE_DEFINED__ equ <>
      externdef IID_IRemoteComputer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRemoteComputerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRemoteComputerVtbl>
          STD_METHOD QueryInterface, :ptr IRemoteComputer, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IRemoteComputer
          STD_METHOD Release, :ptr IRemoteComputer
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
          STD_METHOD QueryInterface, :ptr IQueryContinue, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IQueryContinue
          STD_METHOD Release, :ptr IQueryContinue
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
          STD_METHOD QueryInterface, :ptr IObjectWithCancelEvent, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IObjectWithCancelEvent
          STD_METHOD Release, :ptr IObjectWithCancelEvent
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
          STD_METHOD QueryInterface, :ptr IUserNotification, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IUserNotification
          STD_METHOD Release, :ptr IUserNotification
          STD_METHOD SetBalloonInfo, :ptr IUserNotification, :LPCWSTR, :LPCWSTR, :DWORD
          STD_METHOD SetBalloonRetry, :ptr IUserNotification, :DWORD, :DWORD, :UINT
          STD_METHOD SetIconInfo, :ptr IUserNotification, :HICON, :LPCWSTR
          STD_METHOD Show, :ptr IUserNotification, :ptr IQueryContinue, :DWORD
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
          STD_METHOD QueryInterface, :ptr IItemNameLimits, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IItemNameLimits
          STD_METHOD Release, :ptr IItemNameLimits
          STD_METHOD GetValidCharacters, :ptr IItemNameLimits, :ptr LPWSTR, :ptr LPWSTR
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
      externdef __MIDL_itf_shobjidl_core_0000_0067_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0067_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISearchFolderItemFactory_INTERFACE_DEFINED__
        __ISearchFolderItemFactory_INTERFACE_DEFINED__ equ <>
        externdef IID_ISearchFolderItemFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISearchFolderItemFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISearchFolderItemFactoryVtbl>
            STD_METHOD QueryInterface, :ptr ISearchFolderItemFactory, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISearchFolderItemFactory
            STD_METHOD Release, :ptr ISearchFolderItemFactory
            STD_METHOD SetDisplayName, :ptr ISearchFolderItemFactory, :LPCWSTR
            STD_METHOD SetFolderTypeID, :ptr ISearchFolderItemFactory, :FOLDERTYPEID
            STD_METHOD SetFolderLogicalViewMode, :ptr ISearchFolderItemFactory, :FOLDERLOGICALVIEWMODE
            STD_METHOD SetIconSize, :ptr ISearchFolderItemFactory, :SDWORD
            STD_METHOD SetVisibleColumns, :ptr ISearchFolderItemFactory, :UINT, :ptr PROPERTYKEY
            STD_METHOD SetSortColumns, :ptr ISearchFolderItemFactory, :UINT, :ptr SORTCOLUMN
            STD_METHOD SetGroupColumn, :ptr ISearchFolderItemFactory, :REFPROPERTYKEY
            STD_METHOD SetStacks, :ptr ISearchFolderItemFactory, :UINT, :ptr PROPERTYKEY
            STD_METHOD SetScope, :ptr ISearchFolderItemFactory, :ptr IShellItemArray
            STD_METHOD SetCondition, :ptr ISearchFolderItemFactory, :ptr ICondition
            STD_METHOD GetShellItem, :ptr ISearchFolderItemFactory, :REFIID, :ptr ptr
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
    externdef __MIDL_itf_shobjidl_core_0000_0068_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0068_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IExtractImage_INTERFACE_DEFINED__
      __IExtractImage_INTERFACE_DEFINED__ equ <>
      externdef IID_IExtractImage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExtractImageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExtractImageVtbl>
          STD_METHOD QueryInterface, :ptr IExtractImage, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IExtractImage
          STD_METHOD Release, :ptr IExtractImage
          STD_METHOD GetLocation, :ptr IExtractImage, :LPWSTR, :DWORD, :ptr DWORD, :ptr SIZE_, :DWORD, :ptr DWORD
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
    externdef __MIDL_itf_shobjidl_core_0000_0069_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0069_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IExtractImage2_INTERFACE_DEFINED__
      __IExtractImage2_INTERFACE_DEFINED__ equ <>
      externdef IID_IExtractImage2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IExtractImage2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IExtractImage2Vtbl>
          STD_METHOD QueryInterface, :ptr IExtractImage2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IExtractImage2
          STD_METHOD Release, :ptr IExtractImage2
          STD_METHOD GetLocation, :ptr IExtractImage2, :LPWSTR, :DWORD, :ptr DWORD, :ptr SIZE_, :DWORD, :ptr DWORD
          STD_METHOD Extract, :ptr IExtractImage2, :ptr HBITMAP
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
    externdef __MIDL_itf_shobjidl_core_0000_0070_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0070_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IThumbnailHandlerFactory_INTERFACE_DEFINED__
      __IThumbnailHandlerFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IThumbnailHandlerFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IThumbnailHandlerFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IThumbnailHandlerFactoryVtbl>
          STD_METHOD QueryInterface, :ptr IThumbnailHandlerFactory, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IThumbnailHandlerFactory
          STD_METHOD Release, :ptr IThumbnailHandlerFactory
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
          STD_METHOD QueryInterface, :ptr IParentAndItem, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IParentAndItem
          STD_METHOD Release, :ptr IParentAndItem
          STD_METHOD SetParentAndItem, :ptr IParentAndItem, :PCIDLIST_ABSOLUTE, :ptr IShellFolder, :PCUITEMID_CHILD
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
          STD_METHOD QueryInterface, :ptr IDockingWindow, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDockingWindow
          STD_METHOD Release, :ptr IDockingWindow
          STD_METHOD GetWindow, :ptr IDockingWindow, :ptr HWND
          STD_METHOD ContextSensitiveHelp, :ptr IDockingWindow, :BOOL
          STD_METHOD ShowDW, :ptr IDockingWindow, :BOOL
          STD_METHOD CloseDW, :ptr IDockingWindow, :DWORD
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
    externdef __MIDL_itf_shobjidl_core_0000_0073_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0073_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDeskBand_INTERFACE_DEFINED__
      __IDeskBand_INTERFACE_DEFINED__ equ <>
      externdef IID_IDeskBand:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDeskBandVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDeskBandVtbl>
          STD_METHOD QueryInterface, :ptr IDeskBand, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDeskBand
          STD_METHOD Release, :ptr IDeskBand
          STD_METHOD GetWindow, :ptr IDeskBand, :ptr HWND
          STD_METHOD ContextSensitiveHelp, :ptr IDeskBand, :BOOL
          STD_METHOD ShowDW, :ptr IDeskBand, :BOOL
          STD_METHOD CloseDW, :ptr IDeskBand, :DWORD
          STD_METHOD ResizeBorderDW, :ptr IDeskBand, :LPCRECT, :ptr IUnknown, :BOOL
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
      externdef __MIDL_itf_shobjidl_core_0000_0074_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0074_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDeskBandInfo_INTERFACE_DEFINED__
        __IDeskBandInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IDeskBandInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDeskBandInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDeskBandInfoVtbl>
            STD_METHOD QueryInterface, :ptr IDeskBandInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDeskBandInfo
            STD_METHOD Release, :ptr IDeskBandInfo
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
    externdef __MIDL_itf_shobjidl_core_0000_0075_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0075_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITaskbarList_INTERFACE_DEFINED__
      __ITaskbarList_INTERFACE_DEFINED__ equ <>
      externdef IID_ITaskbarList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITaskbarListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITaskbarListVtbl>
          STD_METHOD QueryInterface, :ptr ITaskbarList, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITaskbarList
          STD_METHOD Release, :ptr ITaskbarList
          STD_METHOD HrInit, :ptr ITaskbarList
          STD_METHOD AddTab, :ptr ITaskbarList, :HWND
          STD_METHOD DeleteTab, :ptr ITaskbarList, :HWND
          STD_METHOD ActivateTab, :ptr ITaskbarList, :HWND
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
          STD_METHOD QueryInterface, :ptr ITaskbarList2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITaskbarList2
          STD_METHOD Release, :ptr ITaskbarList2
          STD_METHOD HrInit, :ptr ITaskbarList2
          STD_METHOD AddTab, :ptr ITaskbarList2, :HWND
          STD_METHOD DeleteTab, :ptr ITaskbarList2, :HWND
          STD_METHOD ActivateTab, :ptr ITaskbarList2, :HWND
          STD_METHOD SetActiveAlt, :ptr ITaskbarList2, :HWND
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
    externdef __MIDL_itf_shobjidl_core_0000_0077_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0077_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr ITaskbarList3, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITaskbarList3
          STD_METHOD Release, :ptr ITaskbarList3
          STD_METHOD HrInit, :ptr ITaskbarList3
          STD_METHOD AddTab, :ptr ITaskbarList3, :HWND
          STD_METHOD DeleteTab, :ptr ITaskbarList3, :HWND
          STD_METHOD ActivateTab, :ptr ITaskbarList3, :HWND
          STD_METHOD SetActiveAlt, :ptr ITaskbarList3, :HWND
          STD_METHOD MarkFullscreenWindow, :ptr ITaskbarList3, :HWND, :BOOL
          STD_METHOD SetProgressValue, :ptr ITaskbarList3, :HWND, :ULONGLONG, :ULONGLONG
          STD_METHOD SetProgressState, :ptr ITaskbarList3, :HWND, :TBPFLAG
          STD_METHOD RegisterTab, :ptr ITaskbarList3, :HWND, :HWND
          STD_METHOD UnregisterTab, :ptr ITaskbarList3, :HWND
          STD_METHOD SetTabOrder, :ptr ITaskbarList3, :HWND, :HWND
          STD_METHOD SetTabActive, :ptr ITaskbarList3, :HWND, :HWND, :DWORD
          STD_METHOD ThumbBarAddButtons, :ptr ITaskbarList3, :HWND, :UINT, :LPTHUMBBUTTON
          STD_METHOD ThumbBarUpdateButtons, :ptr ITaskbarList3, :HWND, :UINT, :LPTHUMBBUTTON
          STD_METHOD ThumbBarSetImageList, :ptr ITaskbarList3, :HWND, :HIMAGELIST
          STD_METHOD SetOverlayIcon, :ptr ITaskbarList3, :HWND, :HICON, :LPCWSTR
          STD_METHOD SetThumbnailTooltip, :ptr ITaskbarList3, :HWND, :LPCWSTR
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
          STD_METHOD QueryInterface, :ptr ITaskbarList4, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITaskbarList4
          STD_METHOD Release, :ptr ITaskbarList4
          STD_METHOD HrInit, :ptr ITaskbarList4
          STD_METHOD AddTab, :ptr ITaskbarList4, :HWND
          STD_METHOD DeleteTab, :ptr ITaskbarList4, :HWND
          STD_METHOD ActivateTab, :ptr ITaskbarList4, :HWND
          STD_METHOD SetActiveAlt, :ptr ITaskbarList4, :HWND
          STD_METHOD MarkFullscreenWindow, :ptr ITaskbarList4, :HWND, :BOOL
          STD_METHOD SetProgressValue, :ptr ITaskbarList4, :HWND, :ULONGLONG, :ULONGLONG
          STD_METHOD SetProgressState, :ptr ITaskbarList4, :HWND, :TBPFLAG
          STD_METHOD RegisterTab, :ptr ITaskbarList4, :HWND, :HWND
          STD_METHOD UnregisterTab, :ptr ITaskbarList4, :HWND
          STD_METHOD SetTabOrder, :ptr ITaskbarList4, :HWND, :HWND
          STD_METHOD SetTabActive, :ptr ITaskbarList4, :HWND, :HWND, :DWORD
          STD_METHOD ThumbBarAddButtons, :ptr ITaskbarList4, :HWND, :UINT, :LPTHUMBBUTTON
          STD_METHOD ThumbBarUpdateButtons, :ptr ITaskbarList4, :HWND, :UINT, :LPTHUMBBUTTON
          STD_METHOD ThumbBarSetImageList, :ptr ITaskbarList4, :HWND, :HIMAGELIST
          STD_METHOD SetOverlayIcon, :ptr ITaskbarList4, :HWND, :HICON, :LPCWSTR
          STD_METHOD SetThumbnailTooltip, :ptr ITaskbarList4, :HWND, :LPCWSTR
          STD_METHOD SetThumbnailClip, :ptr ITaskbarList4, :HWND, :ptr RECT
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
        externdef __MIDL_itf_shobjidl_core_0000_0079_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0079_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IExplorerBrowserEvents_INTERFACE_DEFINED__
          __IExplorerBrowserEvents_INTERFACE_DEFINED__ equ <>
          externdef IID_IExplorerBrowserEvents:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IExplorerBrowserEventsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IExplorerBrowserEventsVtbl>
              STD_METHOD QueryInterface, :ptr IExplorerBrowserEvents, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IExplorerBrowserEvents
              STD_METHOD Release, :ptr IExplorerBrowserEvents
              STD_METHOD OnNavigationPending, :ptr IExplorerBrowserEvents, :PCIDLIST_ABSOLUTE
              STD_METHOD OnViewCreated, :ptr IExplorerBrowserEvents, :ptr IShellView
              STD_METHOD OnNavigationComplete, :ptr IExplorerBrowserEvents, :PCIDLIST_ABSOLUTE
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
        externdef __MIDL_itf_shobjidl_core_0000_0080_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0080_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IExplorerBrowser_INTERFACE_DEFINED__
          __IExplorerBrowser_INTERFACE_DEFINED__ equ <>
          externdef IID_IExplorerBrowser:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IExplorerBrowserVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IExplorerBrowserVtbl>
              STD_METHOD QueryInterface, :ptr IExplorerBrowser, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IExplorerBrowser
              STD_METHOD Release, :ptr IExplorerBrowser
              STD_METHOD Initialize, :ptr IExplorerBrowser, :HWND, :ptr RECT, :ptr FOLDERSETTINGS
              STD_METHOD Destroy_, :ptr IExplorerBrowser
              STD_METHOD SetRect, :ptr IExplorerBrowser, :ptr HDWP, :RECT
              STD_METHOD SetPropertyBag, :ptr IExplorerBrowser, :LPCWSTR
              STD_METHOD SetEmptyText, :ptr IExplorerBrowser, :LPCWSTR
              STD_METHOD SetFolderSettings, :ptr IExplorerBrowser, :ptr FOLDERSETTINGS
              STD_METHOD Advise, :ptr IExplorerBrowser, :ptr IExplorerBrowserEvents, :ptr DWORD
              STD_METHOD Unadvise, :ptr IExplorerBrowser, :DWORD
              STD_METHOD SetOptions, :ptr IExplorerBrowser, :EXPLORER_BROWSER_OPTIONS
              STD_METHOD GetOptions, :ptr IExplorerBrowser, :ptr EXPLORER_BROWSER_OPTIONS
              STD_METHOD BrowseToIDList, :ptr IExplorerBrowser, :PCUIDLIST_RELATIVE, :UINT
              STD_METHOD BrowseToObject, :ptr IExplorerBrowser, :ptr IUnknown, :UINT
              STD_METHOD FillFromObject, :ptr IExplorerBrowser, :ptr IUnknown, :EXPLORER_BROWSER_FILL_FLAGS
              STD_METHOD RemoveAll, :ptr IExplorerBrowser
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
        externdef __MIDL_itf_shobjidl_core_0000_0081_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0081_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IEnumObjects_INTERFACE_DEFINED__
          __IEnumObjects_INTERFACE_DEFINED__ equ <>
          externdef IID_IEnumObjects:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IEnumObjectsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IEnumObjectsVtbl>
              STD_METHOD QueryInterface, :ptr IEnumObjects, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IEnumObjects
              STD_METHOD Release, :ptr IEnumObjects
              STD_METHOD Next, :ptr IEnumObjects, :ULONG, :REFIID, :ptr ptr, :ptr ULONG
              STD_METHOD Skip, :ptr IEnumObjects, :ULONG
              STD_METHOD Reset, :ptr IEnumObjects
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
        externdef __MIDL_itf_shobjidl_core_0000_0082_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0082_v0_0_s_ifspec:RPC_IF_HANDLE
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
              STD_METHOD QueryInterface, :ptr IOperationsProgressDialog, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IOperationsProgressDialog
              STD_METHOD Release, :ptr IOperationsProgressDialog
              STD_METHOD StartProgressDialog, :ptr IOperationsProgressDialog, :HWND, :OPPROGDLGF
              STD_METHOD StopProgressDialog, :ptr IOperationsProgressDialog
              STD_METHOD SetOperation, :ptr IOperationsProgressDialog, :SPACTION
              STD_METHOD SetMode, :ptr IOperationsProgressDialog, :PDMODE
              STD_METHOD UpdateProgress, :ptr IOperationsProgressDialog, :ULONGLONG, :ULONGLONG, :ULONGLONG, :ULONGLONG, :ULONGLONG, :ULONGLONG
              STD_METHOD UpdateLocations, :ptr IOperationsProgressDialog, :ptr IShellItem, :ptr IShellItem, :ptr IShellItem
              STD_METHOD ResetTimer, :ptr IOperationsProgressDialog
              STD_METHOD PauseTimer, :ptr IOperationsProgressDialog
              STD_METHOD ResumeTimer, :ptr IOperationsProgressDialog
              STD_METHOD GetMilliseconds, :ptr IOperationsProgressDialog, :ptr ULONGLONG, :ptr ULONGLONG
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
              STD_METHOD QueryInterface, :ptr IIOCancelInformation, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IIOCancelInformation
              STD_METHOD Release, :ptr IIOCancelInformation
              STD_METHOD SetCancelInformation, :ptr IIOCancelInformation, :DWORD, :UINT
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
        externdef __MIDL_itf_shobjidl_core_0000_0084_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0084_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IFileOperation_INTERFACE_DEFINED__
          __IFileOperation_INTERFACE_DEFINED__ equ <>
          externdef IID_IFileOperation:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IFileOperationVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IFileOperationVtbl>
              STD_METHOD QueryInterface, :ptr IFileOperation, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IFileOperation
              STD_METHOD Release, :ptr IFileOperation
              STD_METHOD Advise, :ptr IFileOperation, :ptr IFileOperationProgressSink, :ptr DWORD
              STD_METHOD Unadvise, :ptr IFileOperation, :DWORD
              STD_METHOD SetOperationFlags, :ptr IFileOperation, :DWORD
              STD_METHOD SetProgressMessage, :ptr IFileOperation, :LPCWSTR
              STD_METHOD SetProgressDialog, :ptr IFileOperation, :ptr IOperationsProgressDialog
              STD_METHOD SetProperties, :ptr IFileOperation, :ptr IPropertyChangeArray
              STD_METHOD SetOwnerWindow, :ptr IFileOperation, :HWND
              STD_METHOD ApplyPropertiesToItem, :ptr IFileOperation, :ptr IShellItem
              STD_METHOD ApplyPropertiesToItems, :ptr IFileOperation, :ptr IUnknown
              STD_METHOD RenameItem, :ptr IFileOperation, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
              STD_METHOD RenameItems, :ptr IFileOperation, :ptr IUnknown, :LPCWSTR
              STD_METHOD MoveItem, :ptr IFileOperation, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
              STD_METHOD MoveItems, :ptr IFileOperation, :ptr IUnknown, :ptr IShellItem
              STD_METHOD CopyItem, :ptr IFileOperation, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
              STD_METHOD CopyItems, :ptr IFileOperation, :ptr IUnknown, :ptr IShellItem
              STD_METHOD DeleteItem, :ptr IFileOperation, :ptr IShellItem, :ptr IFileOperationProgressSink
              STD_METHOD DeleteItems, :ptr IFileOperation, :ptr IUnknown
              STD_METHOD NewItem, :ptr IFileOperation, :ptr IShellItem, :DWORD, :LPCWSTR, :LPCWSTR, :ptr IFileOperationProgressSink
              STD_METHOD PerformOperations, :ptr IFileOperation
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
          externdef __MIDL_itf_shobjidl_core_0000_0085_v0_0_c_ifspec:RPC_IF_HANDLE
          externdef __MIDL_itf_shobjidl_core_0000_0085_v0_0_s_ifspec:RPC_IF_HANDLE
          ifndef __IFileOperation2_INTERFACE_DEFINED__
            __IFileOperation2_INTERFACE_DEFINED__ equ <>
            externdef IID_IFileOperation2:IID
            if Defined(__cplusplus) and  not Defined(CINTERFACE)
              ;[...]
            else
              IFileOperation2Vtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IFileOperation2Vtbl>
                STD_METHOD QueryInterface, :ptr IFileOperation2, :REFIID, :ptr ptr
                STD_METHOD AddRef, :ptr IFileOperation2
                STD_METHOD Release, :ptr IFileOperation2
                STD_METHOD Advise, :ptr IFileOperation2, :ptr IFileOperationProgressSink, :ptr DWORD
                STD_METHOD Unadvise, :ptr IFileOperation2, :DWORD
                STD_METHOD SetOperationFlags, :ptr IFileOperation2, :DWORD
                STD_METHOD SetProgressMessage, :ptr IFileOperation2, :LPCWSTR
                STD_METHOD SetProgressDialog, :ptr IFileOperation2, :ptr IOperationsProgressDialog
                STD_METHOD SetProperties, :ptr IFileOperation2, :ptr IPropertyChangeArray
                STD_METHOD SetOwnerWindow, :ptr IFileOperation2, :HWND
                STD_METHOD ApplyPropertiesToItem, :ptr IFileOperation2, :ptr IShellItem
                STD_METHOD ApplyPropertiesToItems, :ptr IFileOperation2, :ptr IUnknown
                STD_METHOD RenameItem, :ptr IFileOperation2, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
                STD_METHOD RenameItems, :ptr IFileOperation2, :ptr IUnknown, :LPCWSTR
                STD_METHOD MoveItem, :ptr IFileOperation2, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
                STD_METHOD MoveItems, :ptr IFileOperation2, :ptr IUnknown, :ptr IShellItem
                STD_METHOD CopyItem, :ptr IFileOperation2, :ptr IShellItem, :ptr IShellItem, :LPCWSTR, :ptr IFileOperationProgressSink
                STD_METHOD CopyItems, :ptr IFileOperation2, :ptr IUnknown, :ptr IShellItem
                STD_METHOD DeleteItem, :ptr IFileOperation2, :ptr IShellItem, :ptr IFileOperationProgressSink
                STD_METHOD DeleteItems, :ptr IFileOperation2, :ptr IUnknown
                STD_METHOD NewItem, :ptr IFileOperation2, :ptr IShellItem, :DWORD, :LPCWSTR, :LPCWSTR, :ptr IFileOperationProgressSink
                STD_METHOD PerformOperations, :ptr IFileOperation2
                STD_METHOD GetAnyOperationsAborted, :ptr IFileOperation2, :ptr BOOL
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
        externdef __MIDL_itf_shobjidl_core_0000_0086_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0086_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IObjectProvider_INTERFACE_DEFINED__
          __IObjectProvider_INTERFACE_DEFINED__ equ <>
          externdef IID_IObjectProvider:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IObjectProviderVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IObjectProviderVtbl>
              STD_METHOD QueryInterface, :ptr IObjectProvider, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IObjectProvider
              STD_METHOD Release, :ptr IObjectProvider
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
      externdef __MIDL_itf_shobjidl_core_0000_0087_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0087_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __INamespaceWalkCB_INTERFACE_DEFINED__
        __INamespaceWalkCB_INTERFACE_DEFINED__ equ <>
        externdef IID_INamespaceWalkCB:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INamespaceWalkCBVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INamespaceWalkCBVtbl>
            STD_METHOD QueryInterface, :ptr INamespaceWalkCB, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr INamespaceWalkCB
            STD_METHOD Release, :ptr INamespaceWalkCB
            STD_METHOD FoundItem, :ptr INamespaceWalkCB, :ptr IShellFolder, :PCUITEMID_CHILD
            STD_METHOD EnterFolder, :ptr INamespaceWalkCB, :ptr IShellFolder, :PCUITEMID_CHILD
            STD_METHOD LeaveFolder, :ptr INamespaceWalkCB, :ptr IShellFolder, :PCUITEMID_CHILD
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
        externdef __MIDL_itf_shobjidl_core_0000_0088_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0088_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __INamespaceWalkCB2_INTERFACE_DEFINED__
          __INamespaceWalkCB2_INTERFACE_DEFINED__ equ <>
          externdef IID_INamespaceWalkCB2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            INamespaceWalkCB2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <INamespaceWalkCB2Vtbl>
              STD_METHOD QueryInterface, :ptr INamespaceWalkCB2, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr INamespaceWalkCB2
              STD_METHOD Release, :ptr INamespaceWalkCB2
              STD_METHOD FoundItem, :ptr INamespaceWalkCB2, :ptr IShellFolder, :PCUITEMID_CHILD
              STD_METHOD EnterFolder, :ptr INamespaceWalkCB2, :ptr IShellFolder, :PCUITEMID_CHILD
              STD_METHOD LeaveFolder, :ptr INamespaceWalkCB2, :ptr IShellFolder, :PCUITEMID_CHILD
              STD_METHOD InitializeProgressDialog, :ptr INamespaceWalkCB2, :ptr LPWSTR, :ptr LPWSTR
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
      externdef __MIDL_itf_shobjidl_core_0000_0089_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0089_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr INamespaceWalk, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr INamespaceWalk
            STD_METHOD Release, :ptr INamespaceWalk
            STD_METHOD Walk, :ptr INamespaceWalk, :ptr IUnknown, :DWORD, :SDWORD, :ptr INamespaceWalkCB
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
    externdef __MIDL_itf_shobjidl_core_0000_0090_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0090_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IBandSite_INTERFACE_DEFINED__
      __IBandSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IBandSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IBandSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IBandSiteVtbl>
          STD_METHOD QueryInterface, :ptr IBandSite, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IBandSite
          STD_METHOD Release, :ptr IBandSite
          STD_METHOD AddBand, :ptr IBandSite, :ptr IUnknown
          STD_METHOD EnumBands, :ptr IBandSite, :UINT, :ptr DWORD
          STD_METHOD QueryBand, :ptr IBandSite, :DWORD, :ptr ptr IDeskBand, :ptr DWORD, :LPWSTR, :SDWORD
          STD_METHOD SetBandState, :ptr IBandSite, :DWORD, :DWORD, :DWORD
          STD_METHOD RemoveBand, :ptr IBandSite, :DWORD
          STD_METHOD GetBandObject, :ptr IBandSite, :DWORD, :REFIID, :ptr ptr
          STD_METHOD SetBandSiteInfo, :ptr IBandSite, :ptr BANDSITEINFO
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
      externdef __MIDL_itf_shobjidl_core_0000_0091_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0091_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IModalWindow_INTERFACE_DEFINED__
        __IModalWindow_INTERFACE_DEFINED__ equ <>
        externdef IID_IModalWindow:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IModalWindowVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IModalWindowVtbl>
            STD_METHOD QueryInterface, :ptr IModalWindow, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IModalWindow
            STD_METHOD Release, :ptr IModalWindow
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
    externdef __MIDL_itf_shobjidl_core_0000_0092_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0092_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IContextMenuSite_INTERFACE_DEFINED__
      __IContextMenuSite_INTERFACE_DEFINED__ equ <>
      externdef IID_IContextMenuSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IContextMenuSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IContextMenuSiteVtbl>
          STD_METHOD QueryInterface, :ptr IContextMenuSite, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IContextMenuSite
          STD_METHOD Release, :ptr IContextMenuSite
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
        externdef __MIDL_itf_shobjidl_core_0000_0093_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0093_v0_0_s_ifspec:RPC_IF_HANDLE
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
              STD_METHOD QueryInterface, :ptr IMenuBand, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IMenuBand
              STD_METHOD Release, :ptr IMenuBand
              STD_METHOD IsMenuMessage, :ptr IMenuBand, :ptr MSG
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
              STD_METHOD QueryInterface, :ptr IRegTreeItem, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IRegTreeItem
              STD_METHOD Release, :ptr IRegTreeItem
              STD_METHOD GetCheckState, :ptr IRegTreeItem, :ptr BOOL
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
      externdef __MIDL_itf_shobjidl_core_0000_0095_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0095_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDeskBar_INTERFACE_DEFINED__
        __IDeskBar_INTERFACE_DEFINED__ equ <>
        externdef IID_IDeskBar:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDeskBarVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDeskBarVtbl>
            STD_METHOD QueryInterface, :ptr IDeskBar, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDeskBar
            STD_METHOD Release, :ptr IDeskBar
            STD_METHOD GetWindow, :ptr IDeskBar, :ptr HWND
            STD_METHOD ContextSensitiveHelp, :ptr IDeskBar, :BOOL
            STD_METHOD SetClient, :ptr IDeskBar, :ptr IUnknown
            STD_METHOD GetClient, :ptr IDeskBar, :ptr ptr IUnknown
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
            STD_METHOD QueryInterface, :ptr IMenuPopup, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IMenuPopup
            STD_METHOD Release, :ptr IMenuPopup
            STD_METHOD GetWindow, :ptr IMenuPopup, :ptr HWND
            STD_METHOD ContextSensitiveHelp, :ptr IMenuPopup, :BOOL
            STD_METHOD SetClient, :ptr IMenuPopup, :ptr IUnknown
            STD_METHOD GetClient, :ptr IMenuPopup, :ptr ptr IUnknown
            STD_METHOD OnPosRectChangeDB, :ptr IMenuPopup, :ptr RECT
            STD_METHOD Popup, :ptr IMenuPopup, :ptr POINTL, :ptr RECTL, :MP_POPUPFLAGS
            STD_METHOD OnSelect, :ptr IMenuPopup, :DWORD
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
      externdef __MIDL_itf_shobjidl_core_0000_0097_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0097_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileIsInUse_INTERFACE_DEFINED__
        __IFileIsInUse_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileIsInUse:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileIsInUseVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileIsInUseVtbl>
            STD_METHOD QueryInterface, :ptr IFileIsInUse, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileIsInUse
            STD_METHOD Release, :ptr IFileIsInUse
            STD_METHOD GetAppName, :ptr IFileIsInUse, :ptr LPWSTR
            STD_METHOD GetUsage, :ptr IFileIsInUse, :ptr FILE_USAGE_TYPE
            STD_METHOD GetCapabilities, :ptr IFileIsInUse, :ptr DWORD
            STD_METHOD GetSwitchToHWND, :ptr IFileIsInUse, :ptr HWND
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0098_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0098_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialogEvents_INTERFACE_DEFINED__
        __IFileDialogEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileDialogEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogEventsVtbl>
            STD_METHOD QueryInterface, :ptr IFileDialogEvents, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileDialogEvents
            STD_METHOD Release, :ptr IFileDialogEvents
            STD_METHOD OnFileOk, :ptr IFileDialogEvents, :ptr IFileDialog
            STD_METHOD OnFolderChanging, :ptr IFileDialogEvents, :ptr IFileDialog, :ptr IShellItem
            STD_METHOD OnFolderChange, :ptr IFileDialogEvents, :ptr IFileDialog
            STD_METHOD OnSelectionChange, :ptr IFileDialogEvents, :ptr IFileDialog
            STD_METHOD OnShareViolation, :ptr IFileDialogEvents, :ptr IFileDialog, :ptr IShellItem, :ptr FDE_SHAREVIOLATION_RESPONSE
            STD_METHOD OnTypeChange, :ptr IFileDialogEvents, :ptr IFileDialog
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
      externdef __MIDL_itf_shobjidl_core_0000_0099_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0099_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr IFileDialog, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileDialog
            STD_METHOD Release, :ptr IFileDialog
            STD_METHOD Show, :ptr IFileDialog, :HWND
            STD_METHOD SetFileTypes, :ptr IFileDialog, :UINT, :ptr COMDLG_FILTERSPEC
            STD_METHOD SetFileTypeIndex, :ptr IFileDialog, :UINT
            STD_METHOD GetFileTypeIndex, :ptr IFileDialog, :ptr UINT
            STD_METHOD Advise, :ptr IFileDialog, :ptr IFileDialogEvents, :ptr DWORD
            STD_METHOD Unadvise, :ptr IFileDialog, :DWORD
            STD_METHOD SetOptions, :ptr IFileDialog, :FILEOPENDIALOGOPTIONS
            STD_METHOD GetOptions, :ptr IFileDialog, :ptr FILEOPENDIALOGOPTIONS
            STD_METHOD SetDefaultFolder, :ptr IFileDialog, :ptr IShellItem
            STD_METHOD SetFolder, :ptr IFileDialog, :ptr IShellItem
            STD_METHOD GetFolder, :ptr IFileDialog, :ptr ptr IShellItem
            STD_METHOD GetCurrentSelection, :ptr IFileDialog, :ptr ptr IShellItem
            STD_METHOD SetFileName, :ptr IFileDialog, :LPCWSTR
            STD_METHOD GetFileName, :ptr IFileDialog, :ptr LPWSTR
            STD_METHOD SetTitle, :ptr IFileDialog, :LPCWSTR
            STD_METHOD SetOkButtonLabel, :ptr IFileDialog, :LPCWSTR
            STD_METHOD SetFileNameLabel, :ptr IFileDialog, :LPCWSTR
            STD_METHOD GetResult, :ptr IFileDialog, :ptr ptr IShellItem
            STD_METHOD AddPlace, :ptr IFileDialog, :ptr IShellItem, :FDAP
            STD_METHOD SetDefaultExtension, :ptr IFileDialog, :LPCWSTR
            STD_METHOD Close, :ptr IFileDialog, :HRESULT
            STD_METHOD SetClientGuid, :ptr IFileDialog, :REFGUID
            STD_METHOD ClearClientData, :ptr IFileDialog
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
            STD_METHOD QueryInterface, :ptr IFileSaveDialog, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileSaveDialog
            STD_METHOD Release, :ptr IFileSaveDialog
            STD_METHOD Show, :ptr IFileSaveDialog, :HWND
            STD_METHOD SetFileTypes, :ptr IFileSaveDialog, :UINT, :ptr COMDLG_FILTERSPEC
            STD_METHOD SetFileTypeIndex, :ptr IFileSaveDialog, :UINT
            STD_METHOD GetFileTypeIndex, :ptr IFileSaveDialog, :ptr UINT
            STD_METHOD Advise, :ptr IFileSaveDialog, :ptr IFileDialogEvents, :ptr DWORD
            STD_METHOD Unadvise, :ptr IFileSaveDialog, :DWORD
            STD_METHOD SetOptions, :ptr IFileSaveDialog, :FILEOPENDIALOGOPTIONS
            STD_METHOD GetOptions, :ptr IFileSaveDialog, :ptr FILEOPENDIALOGOPTIONS
            STD_METHOD SetDefaultFolder, :ptr IFileSaveDialog, :ptr IShellItem
            STD_METHOD SetFolder, :ptr IFileSaveDialog, :ptr IShellItem
            STD_METHOD GetFolder, :ptr IFileSaveDialog, :ptr ptr IShellItem
            STD_METHOD GetCurrentSelection, :ptr IFileSaveDialog, :ptr ptr IShellItem
            STD_METHOD SetFileName, :ptr IFileSaveDialog, :LPCWSTR
            STD_METHOD GetFileName, :ptr IFileSaveDialog, :ptr LPWSTR
            STD_METHOD SetTitle, :ptr IFileSaveDialog, :LPCWSTR
            STD_METHOD SetOkButtonLabel, :ptr IFileSaveDialog, :LPCWSTR
            STD_METHOD SetFileNameLabel, :ptr IFileSaveDialog, :LPCWSTR
            STD_METHOD GetResult, :ptr IFileSaveDialog, :ptr ptr IShellItem
            STD_METHOD AddPlace, :ptr IFileSaveDialog, :ptr IShellItem, :FDAP
            STD_METHOD SetDefaultExtension, :ptr IFileSaveDialog, :LPCWSTR
            STD_METHOD Close, :ptr IFileSaveDialog, :HRESULT
            STD_METHOD SetClientGuid, :ptr IFileSaveDialog, :REFGUID
            STD_METHOD ClearClientData, :ptr IFileSaveDialog
            STD_METHOD SetFilter, :ptr IFileSaveDialog, :ptr IShellItemFilter
            STD_METHOD SetSaveAsItem, :ptr IFileSaveDialog, :ptr IShellItem
            STD_METHOD SetProperties, :ptr IFileSaveDialog, :ptr IPropertyStore
            STD_METHOD SetCollectedProperties, :ptr IFileSaveDialog, :ptr IPropertyDescriptionList, :BOOL
            STD_METHOD GetProperties, :ptr IFileSaveDialog, :ptr ptr IPropertyStore
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
            STD_METHOD QueryInterface, :ptr IFileOpenDialog, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileOpenDialog
            STD_METHOD Release, :ptr IFileOpenDialog
            STD_METHOD Show, :ptr IFileOpenDialog, :HWND
            STD_METHOD SetFileTypes, :ptr IFileOpenDialog, :UINT, :ptr COMDLG_FILTERSPEC
            STD_METHOD SetFileTypeIndex, :ptr IFileOpenDialog, :UINT
            STD_METHOD GetFileTypeIndex, :ptr IFileOpenDialog, :ptr UINT
            STD_METHOD Advise, :ptr IFileOpenDialog, :ptr IFileDialogEvents, :ptr DWORD
            STD_METHOD Unadvise, :ptr IFileOpenDialog, :DWORD
            STD_METHOD SetOptions, :ptr IFileOpenDialog, :FILEOPENDIALOGOPTIONS
            STD_METHOD GetOptions, :ptr IFileOpenDialog, :ptr FILEOPENDIALOGOPTIONS
            STD_METHOD SetDefaultFolder, :ptr IFileOpenDialog, :ptr IShellItem
            STD_METHOD SetFolder, :ptr IFileOpenDialog, :ptr IShellItem
            STD_METHOD GetFolder, :ptr IFileOpenDialog, :ptr ptr IShellItem
            STD_METHOD GetCurrentSelection, :ptr IFileOpenDialog, :ptr ptr IShellItem
            STD_METHOD SetFileName, :ptr IFileOpenDialog, :LPCWSTR
            STD_METHOD GetFileName, :ptr IFileOpenDialog, :ptr LPWSTR
            STD_METHOD SetTitle, :ptr IFileOpenDialog, :LPCWSTR
            STD_METHOD SetOkButtonLabel, :ptr IFileOpenDialog, :LPCWSTR
            STD_METHOD SetFileNameLabel, :ptr IFileOpenDialog, :LPCWSTR
            STD_METHOD GetResult, :ptr IFileOpenDialog, :ptr ptr IShellItem
            STD_METHOD AddPlace, :ptr IFileOpenDialog, :ptr IShellItem, :FDAP
            STD_METHOD SetDefaultExtension, :ptr IFileOpenDialog, :LPCWSTR
            STD_METHOD Close, :ptr IFileOpenDialog, :HRESULT
            STD_METHOD SetClientGuid, :ptr IFileOpenDialog, :REFGUID
            STD_METHOD ClearClientData, :ptr IFileOpenDialog
            STD_METHOD SetFilter, :ptr IFileOpenDialog, :ptr IShellItemFilter
            STD_METHOD GetResults, :ptr IFileOpenDialog, :ptr ptr IShellItemArray
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
      externdef __MIDL_itf_shobjidl_core_0000_0102_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0102_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFileDialogCustomize_INTERFACE_DEFINED__
        __IFileDialogCustomize_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileDialogCustomize:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileDialogCustomizeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileDialogCustomizeVtbl>
            STD_METHOD QueryInterface, :ptr IFileDialogCustomize, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileDialogCustomize
            STD_METHOD Release, :ptr IFileDialogCustomize
            STD_METHOD EnableOpenDropDown, :ptr IFileDialogCustomize, :DWORD
            STD_METHOD AddMenu, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD AddPushButton, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD AddComboBox, :ptr IFileDialogCustomize, :DWORD
            STD_METHOD AddRadioButtonList, :ptr IFileDialogCustomize, :DWORD
            STD_METHOD AddCheckButton, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR, :BOOL
            STD_METHOD AddEditBox, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD AddSeparator, :ptr IFileDialogCustomize, :DWORD
            STD_METHOD AddText, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD SetControlLabel, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD GetControlState, :ptr IFileDialogCustomize, :DWORD, :ptr CDCONTROLSTATEF
            STD_METHOD SetControlState, :ptr IFileDialogCustomize, :DWORD, :CDCONTROLSTATEF
            STD_METHOD GetEditBoxText, :ptr IFileDialogCustomize, :DWORD, :ptr ptr WCHAR
            STD_METHOD SetEditBoxText, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD GetCheckButtonState, :ptr IFileDialogCustomize, :DWORD, :ptr BOOL
            STD_METHOD SetCheckButtonState, :ptr IFileDialogCustomize, :DWORD, :BOOL
            STD_METHOD AddControlItem, :ptr IFileDialogCustomize, :DWORD, :DWORD, :LPCWSTR
            STD_METHOD RemoveControlItem, :ptr IFileDialogCustomize, :DWORD, :DWORD
            STD_METHOD RemoveAllControlItems, :ptr IFileDialogCustomize, :DWORD
            STD_METHOD GetControlItemState, :ptr IFileDialogCustomize, :DWORD, :DWORD, :ptr CDCONTROLSTATEF
            STD_METHOD SetControlItemState, :ptr IFileDialogCustomize, :DWORD, :DWORD, :CDCONTROLSTATEF
            STD_METHOD GetSelectedControlItem, :ptr IFileDialogCustomize, :DWORD, :ptr DWORD
            STD_METHOD SetSelectedControlItem, :ptr IFileDialogCustomize, :DWORD, :DWORD
            STD_METHOD StartVisualGroup, :ptr IFileDialogCustomize, :DWORD, :LPCWSTR
            STD_METHOD EndVisualGroup, :ptr IFileDialogCustomize
            STD_METHOD MakeProminent, :ptr IFileDialogCustomize, :DWORD
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0103_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0103_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IApplicationAssociationRegistration_INTERFACE_DEFINED__
        __IApplicationAssociationRegistration_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationAssociationRegistration:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationAssociationRegistrationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationAssociationRegistrationVtbl>
            STD_METHOD QueryInterface, :ptr IApplicationAssociationRegistration, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IApplicationAssociationRegistration
            STD_METHOD Release, :ptr IApplicationAssociationRegistration
            STD_METHOD QueryCurrentDefault, :ptr IApplicationAssociationRegistration, :LPCWSTR, :ASSOCIATIONTYPE, :ASSOCIATIONLEVEL, :ptr LPWSTR
            STD_METHOD QueryAppIsDefault, :ptr IApplicationAssociationRegistration, :LPCWSTR, :ASSOCIATIONTYPE, :ASSOCIATIONLEVEL, :LPCWSTR, :ptr BOOL
            STD_METHOD QueryAppIsDefaultAll, :ptr IApplicationAssociationRegistration, :ASSOCIATIONLEVEL, :LPCWSTR, :ptr BOOL
            STD_METHOD SetAppAsDefault, :ptr IApplicationAssociationRegistration, :LPCWSTR, :LPCWSTR, :ASSOCIATIONTYPE
            STD_METHOD SetAppAsDefaultAll, :ptr IApplicationAssociationRegistration, :LPCWSTR
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
    externdef __MIDL_itf_shobjidl_core_0000_0104_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0104_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDelegateFolder_INTERFACE_DEFINED__
      __IDelegateFolder_INTERFACE_DEFINED__ equ <>
      externdef IID_IDelegateFolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDelegateFolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDelegateFolderVtbl>
          STD_METHOD QueryInterface, :ptr IDelegateFolder, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDelegateFolder
          STD_METHOD Release, :ptr IDelegateFolder
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
      externdef __MIDL_itf_shobjidl_core_0000_0105_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0105_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr IBrowserFrameOptions, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IBrowserFrameOptions
            STD_METHOD Release, :ptr IBrowserFrameOptions
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
      externdef __MIDL_itf_shobjidl_core_0000_0106_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0106_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __INewWindowManager_INTERFACE_DEFINED__
        __INewWindowManager_INTERFACE_DEFINED__ equ <>
        externdef IID_INewWindowManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INewWindowManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INewWindowManagerVtbl>
            STD_METHOD QueryInterface, :ptr INewWindowManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr INewWindowManager
            STD_METHOD Release, :ptr INewWindowManager
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
            STD_METHOD QueryInterface, :ptr IAttachmentExecute, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAttachmentExecute
            STD_METHOD Release, :ptr IAttachmentExecute
            STD_METHOD SetClientTitle, :ptr IAttachmentExecute, :LPCWSTR
            STD_METHOD SetClientGuid, :ptr IAttachmentExecute, :REFGUID
            STD_METHOD SetLocalPath, :ptr IAttachmentExecute, :LPCWSTR
            STD_METHOD SetFileName, :ptr IAttachmentExecute, :LPCWSTR
            STD_METHOD SetSource, :ptr IAttachmentExecute, :LPCWSTR
            STD_METHOD SetReferrer, :ptr IAttachmentExecute, :LPCWSTR
            STD_METHOD CheckPolicy, :ptr IAttachmentExecute
            STD_METHOD Prompt, :ptr IAttachmentExecute, :HWND, :ATTACHMENT_PROMPT, :ptr ATTACHMENT_ACTION
            STD_METHOD Save, :ptr IAttachmentExecute
            STD_METHOD Execute, :ptr IAttachmentExecute, :HWND, :LPCWSTR, :ptr HANDLE
            STD_METHOD SaveWithUI, :ptr IAttachmentExecute, :HWND
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
      externdef __MIDL_itf_shobjidl_core_0000_0108_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0108_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IShellMenuCallback_INTERFACE_DEFINED__
        __IShellMenuCallback_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellMenuCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellMenuCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellMenuCallbackVtbl>
            STD_METHOD QueryInterface, :ptr IShellMenuCallback, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellMenuCallback
            STD_METHOD Release, :ptr IShellMenuCallback
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
      externdef __MIDL_itf_shobjidl_core_0000_0109_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0109_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IShellMenu_INTERFACE_DEFINED__
        __IShellMenu_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellMenu:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellMenuVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellMenuVtbl>
            STD_METHOD QueryInterface, :ptr IShellMenu, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellMenu
            STD_METHOD Release, :ptr IShellMenu
            STD_METHOD Initialize, :ptr IShellMenu, :ptr IShellMenuCallback, :UINT, :UINT, :DWORD
            STD_METHOD GetMenuInfo, :ptr IShellMenu, :ptr ptr IShellMenuCallback, :ptr UINT, :ptr UINT, :ptr DWORD
            STD_METHOD SetShellFolder, :ptr IShellMenu, :ptr IShellFolder, :PCIDLIST_ABSOLUTE, :HKEY, :DWORD
            STD_METHOD GetShellFolder, :ptr IShellMenu, :ptr DWORD, :ptr PIDLIST_ABSOLUTE, :REFIID, :ptr ptr
            STD_METHOD SetMenu, :ptr IShellMenu, :HMENU, :HWND, :DWORD
            STD_METHOD GetMenu, :ptr IShellMenu, :ptr HMENU, :ptr HWND, :ptr DWORD
            STD_METHOD InvalidateItem, :ptr IShellMenu, :LPSMDATA, :DWORD
            STD_METHOD GetState, :ptr IShellMenu, :LPSMDATA
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
      externdef __MIDL_itf_shobjidl_core_0000_0110_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0110_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IKnownFolder_INTERFACE_DEFINED__
        __IKnownFolder_INTERFACE_DEFINED__ equ <>
        externdef IID_IKnownFolder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IKnownFolderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IKnownFolderVtbl>
            STD_METHOD QueryInterface, :ptr IKnownFolder, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IKnownFolder
            STD_METHOD Release, :ptr IKnownFolder
            STD_METHOD GetId, :ptr IKnownFolder, :ptr KNOWNFOLDERID
            STD_METHOD GetCategory, :ptr IKnownFolder, :ptr KF_CATEGORY
            STD_METHOD GetShellItem, :ptr IKnownFolder, :DWORD, :REFIID, :ptr ptr
            STD_METHOD GetPath, :ptr IKnownFolder, :DWORD, :ptr LPWSTR
            STD_METHOD SetPath, :ptr IKnownFolder, :DWORD, :LPCWSTR
            STD_METHOD GetIDList, :ptr IKnownFolder, :DWORD, :ptr PIDLIST_ABSOLUTE
            STD_METHOD GetFolderType, :ptr IKnownFolder, :ptr FOLDERTYPEID
            STD_METHOD GetRedirectionCapabilities, :ptr IKnownFolder, :ptr KF_REDIRECTION_CAPABILITIES
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
            STD_METHOD QueryInterface, :ptr IKnownFolderManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IKnownFolderManager
            STD_METHOD Release, :ptr IKnownFolderManager
            STD_METHOD FolderIdFromCsidl, :ptr IKnownFolderManager, :SDWORD, :ptr KNOWNFOLDERID
            STD_METHOD FolderIdToCsidl, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :ptr SDWORD
            STD_METHOD GetFolderIds, :ptr IKnownFolderManager, :ptr ptr KNOWNFOLDERID, :ptr UINT
            STD_METHOD GetFolder, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :ptr ptr IKnownFolder
            STD_METHOD GetFolderByName, :ptr IKnownFolderManager, :LPCWSTR, :ptr ptr IKnownFolder
            STD_METHOD RegisterFolder, :ptr IKnownFolderManager, :REFKNOWNFOLDERID, :ptr KNOWNFOLDER_DEFINITION
            STD_METHOD UnregisterFolder, :ptr IKnownFolderManager, :REFKNOWNFOLDERID
            STD_METHOD FindFolderFromPath, :ptr IKnownFolderManager, :LPCWSTR, :FFFP_MODE, :ptr ptr IKnownFolder
            STD_METHOD FindFolderFromIDList, :ptr IKnownFolderManager, :PCIDLIST_ABSOLUTE, :ptr ptr IKnownFolder
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0112_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0112_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISharingConfigurationManager_INTERFACE_DEFINED__
        __ISharingConfigurationManager_INTERFACE_DEFINED__ equ <>
        externdef IID_ISharingConfigurationManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISharingConfigurationManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISharingConfigurationManagerVtbl>
            STD_METHOD QueryInterface, :ptr ISharingConfigurationManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISharingConfigurationManager
            STD_METHOD Release, :ptr ISharingConfigurationManager
            STD_METHOD CreateShare, :ptr ISharingConfigurationManager, :DEF_SHARE_ID, :SHARE_ROLE
            STD_METHOD DeleteShare, :ptr ISharingConfigurationManager, :DEF_SHARE_ID
            STD_METHOD ShareExists, :ptr ISharingConfigurationManager, :DEF_SHARE_ID
            STD_METHOD GetSharePermissions, :ptr ISharingConfigurationManager, :DEF_SHARE_ID, :ptr SHARE_ROLE
            STD_METHOD SharePrinters, :ptr ISharingConfigurationManager
            STD_METHOD StopSharingPrinters, :ptr ISharingConfigurationManager
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
      externdef __MIDL_itf_shobjidl_core_0000_0113_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0113_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IRelatedItem_INTERFACE_DEFINED__
        __IRelatedItem_INTERFACE_DEFINED__ equ <>
        externdef IID_IRelatedItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRelatedItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRelatedItemVtbl>
            STD_METHOD QueryInterface, :ptr IRelatedItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRelatedItem
            STD_METHOD Release, :ptr IRelatedItem
            STD_METHOD GetItemIDList, :ptr IRelatedItem, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr IIdentityName, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IIdentityName
            STD_METHOD Release, :ptr IIdentityName
            STD_METHOD GetItemIDList, :ptr IIdentityName, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr IDelegateItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDelegateItem
            STD_METHOD Release, :ptr IDelegateItem
            STD_METHOD GetItemIDList, :ptr IDelegateItem, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr ICurrentItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICurrentItem
            STD_METHOD Release, :ptr ICurrentItem
            STD_METHOD GetItemIDList, :ptr ICurrentItem, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr ITransferMediumItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ITransferMediumItem
            STD_METHOD Release, :ptr ITransferMediumItem
            STD_METHOD GetItemIDList, :ptr ITransferMediumItem, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr IDisplayItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDisplayItem
            STD_METHOD Release, :ptr IDisplayItem
            STD_METHOD GetItemIDList, :ptr IDisplayItem, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr IViewStateIdentityItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IViewStateIdentityItem
            STD_METHOD Release, :ptr IViewStateIdentityItem
            STD_METHOD GetItemIDList, :ptr IViewStateIdentityItem, :ptr PIDLIST_ABSOLUTE
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
            STD_METHOD QueryInterface, :ptr IPreviewItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPreviewItem
            STD_METHOD Release, :ptr IPreviewItem
            STD_METHOD GetItemIDList, :ptr IPreviewItem, :ptr PIDLIST_ABSOLUTE
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
    externdef __MIDL_itf_shobjidl_core_0000_0121_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0121_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDestinationStreamFactory_INTERFACE_DEFINED__
      __IDestinationStreamFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IDestinationStreamFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDestinationStreamFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDestinationStreamFactoryVtbl>
          STD_METHOD QueryInterface, :ptr IDestinationStreamFactory, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDestinationStreamFactory
          STD_METHOD Release, :ptr IDestinationStreamFactory
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
      externdef __MIDL_itf_shobjidl_core_0000_0122_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0122_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICreateProcessInputs_INTERFACE_DEFINED__
        __ICreateProcessInputs_INTERFACE_DEFINED__ equ <>
        externdef IID_ICreateProcessInputs:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICreateProcessInputsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICreateProcessInputsVtbl>
            STD_METHOD QueryInterface, :ptr ICreateProcessInputs, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICreateProcessInputs
            STD_METHOD Release, :ptr ICreateProcessInputs
            STD_METHOD GetCreateFlags, :ptr ICreateProcessInputs, :ptr DWORD
            STD_METHOD SetCreateFlags, :ptr ICreateProcessInputs, :DWORD
            STD_METHOD AddCreateFlags, :ptr ICreateProcessInputs, :DWORD
            STD_METHOD SetHotKey, :ptr ICreateProcessInputs, :WORD
            STD_METHOD AddStartupFlags, :ptr ICreateProcessInputs, :DWORD
            STD_METHOD SetTitle, :ptr ICreateProcessInputs, :LPCWSTR
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
            STD_METHOD QueryInterface, :ptr ICreatingProcess, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICreatingProcess
            STD_METHOD Release, :ptr ICreatingProcess
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
    _NMCII_FLAGS typedef SDWORD
    NMCII_NONE equ 0
    NMCII_ITEMS equ 1h
    NMCII_FOLDERS equ 2h
    
    NMCII_FLAGS typedef SDWORD
    _NMCSAEI_FLAGS typedef SDWORD
    NMCSAEI_SELECT equ 0
    NMCSAEI_EDIT equ 1h
    
    NMCSAEI_FLAGS typedef SDWORD
    externdef __MIDL_itf_shobjidl_core_0000_0124_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0124_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INewMenuClient_INTERFACE_DEFINED__
      __INewMenuClient_INTERFACE_DEFINED__ equ <>
      externdef IID_INewMenuClient:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INewMenuClientVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INewMenuClientVtbl>
          STD_METHOD QueryInterface, :ptr INewMenuClient, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INewMenuClient
          STD_METHOD Release, :ptr INewMenuClient
          STD_METHOD IncludeItems, :ptr INewMenuClient, :ptr NMCII_FLAGS
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
      externdef __MIDL_itf_shobjidl_core_0000_0125_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0125_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInitializeWithBindCtx_INTERFACE_DEFINED__
        __IInitializeWithBindCtx_INTERFACE_DEFINED__ equ <>
        externdef IID_IInitializeWithBindCtx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInitializeWithBindCtxVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInitializeWithBindCtxVtbl>
            STD_METHOD QueryInterface, :ptr IInitializeWithBindCtx, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IInitializeWithBindCtx
            STD_METHOD Release, :ptr IInitializeWithBindCtx
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
            STD_METHOD QueryInterface, :ptr IShellItemFilter, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellItemFilter
            STD_METHOD Release, :ptr IShellItemFilter
            STD_METHOD IncludeItem, :ptr IShellItemFilter, :ptr IShellItem
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
    externdef __MIDL_itf_shobjidl_core_0000_0127_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0127_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr INameSpaceTreeControl, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr INameSpaceTreeControl
          STD_METHOD Release, :ptr INameSpaceTreeControl
          STD_METHOD Initialize, :ptr INameSpaceTreeControl, :HWND, :ptr RECT, :NSTCSTYLE
          STD_METHOD TreeAdvise, :ptr INameSpaceTreeControl, :ptr IUnknown, :ptr DWORD
          STD_METHOD TreeUnadvise, :ptr INameSpaceTreeControl, :DWORD
          STD_METHOD AppendRoot, :ptr INameSpaceTreeControl, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          STD_METHOD InsertRoot, :ptr INameSpaceTreeControl, :SDWORD, :ptr IShellItem, :SHCONTF, :NSTCROOTSTYLE, :ptr IShellItemFilter
          STD_METHOD RemoveRoot, :ptr INameSpaceTreeControl, :ptr IShellItem
          STD_METHOD RemoveAllRoots, :ptr INameSpaceTreeControl
          STD_METHOD GetRootItems, :ptr INameSpaceTreeControl, :ptr ptr IShellItemArray
          STD_METHOD SetItemState, :ptr INameSpaceTreeControl, :ptr IShellItem, :NSTCITEMSTATE, :NSTCITEMSTATE
          STD_METHOD GetItemState, :ptr INameSpaceTreeControl, :ptr IShellItem, :NSTCITEMSTATE, :ptr NSTCITEMSTATE
          STD_METHOD GetSelectedItems, :ptr INameSpaceTreeControl, :ptr ptr IShellItemArray
          STD_METHOD GetItemCustomState, :ptr INameSpaceTreeControl, :ptr IShellItem, :ptr SDWORD
          STD_METHOD SetItemCustomState, :ptr INameSpaceTreeControl, :ptr IShellItem, :SDWORD
          STD_METHOD EnsureItemVisible, :ptr INameSpaceTreeControl, :ptr IShellItem
          STD_METHOD SetTheme, :ptr INameSpaceTreeControl, :LPCWSTR
          STD_METHOD GetNextItem, :ptr INameSpaceTreeControl, :ptr IShellItem, :NSTCGNI, :ptr ptr IShellItem
          STD_METHOD HitTest, :ptr INameSpaceTreeControl, :ptr POINT, :ptr ptr IShellItem
          STD_METHOD GetItemRect, :ptr INameSpaceTreeControl, :ptr IShellItem, :ptr RECT
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
      externdef __MIDL_itf_shobjidl_core_0000_0128_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0128_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr INameSpaceTreeControlFolderCapabilities, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr INameSpaceTreeControlFolderCapabilities
            STD_METHOD Release, :ptr INameSpaceTreeControlFolderCapabilities
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
    externdef __MIDL_itf_shobjidl_core_0000_0129_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0129_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPreviewHandler_INTERFACE_DEFINED__
      __IPreviewHandler_INTERFACE_DEFINED__ equ <>
      externdef IID_IPreviewHandler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPreviewHandlerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPreviewHandlerVtbl>
          STD_METHOD QueryInterface, :ptr IPreviewHandler, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPreviewHandler
          STD_METHOD Release, :ptr IPreviewHandler
          STD_METHOD SetWindow, :ptr IPreviewHandler, :HWND, :ptr RECT
          STD_METHOD SetRect, :ptr IPreviewHandler, :ptr RECT
          STD_METHOD DoPreview, :ptr IPreviewHandler
          STD_METHOD Unload, :ptr IPreviewHandler
          STD_METHOD SetFocus, :ptr IPreviewHandler
          STD_METHOD QueryFocus, :ptr IPreviewHandler, :ptr HWND
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
          STD_METHOD QueryInterface, :ptr IPreviewHandlerFrame, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPreviewHandlerFrame
          STD_METHOD Release, :ptr IPreviewHandlerFrame
          STD_METHOD GetWindowContext, :ptr IPreviewHandlerFrame, :ptr PREVIEWHANDLERFRAMEINFO
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
        REFEXPLORERPANE equ <ptr EXPLORERPANE>
      endif
      externdef __MIDL_itf_shobjidl_core_0000_0131_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0131_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr IExplorerPaneVisibility, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IExplorerPaneVisibility
            STD_METHOD Release, :ptr IExplorerPaneVisibility
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
      externdef __MIDL_itf_shobjidl_core_0000_0132_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0132_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IContextMenuCB_INTERFACE_DEFINED__
        __IContextMenuCB_INTERFACE_DEFINED__ equ <>
        externdef IID_IContextMenuCB:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IContextMenuCBVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IContextMenuCBVtbl>
            STD_METHOD QueryInterface, :ptr IContextMenuCB, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IContextMenuCB
            STD_METHOD Release, :ptr IContextMenuCB
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
    externdef __MIDL_itf_shobjidl_core_0000_0133_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0133_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDefaultExtractIconInit_INTERFACE_DEFINED__
      __IDefaultExtractIconInit_INTERFACE_DEFINED__ equ <>
      externdef IID_IDefaultExtractIconInit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDefaultExtractIconInitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDefaultExtractIconInitVtbl>
          STD_METHOD QueryInterface, :ptr IDefaultExtractIconInit, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDefaultExtractIconInit
          STD_METHOD Release, :ptr IDefaultExtractIconInit
          STD_METHOD SetFlags, :ptr IDefaultExtractIconInit, :UINT
          STD_METHOD SetKey, :ptr IDefaultExtractIconInit, :HKEY
          STD_METHOD SetNormalIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
          STD_METHOD SetOpenIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
          STD_METHOD SetShortcutIcon, :ptr IDefaultExtractIconInit, :LPCWSTR, :SDWORD
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
    externdef __MIDL_itf_shobjidl_core_0000_0134_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0134_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IExplorerCommand, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IExplorerCommand
          STD_METHOD Release, :ptr IExplorerCommand
          STD_METHOD GetTitle, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr LPWSTR
          STD_METHOD GetIcon, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr LPWSTR
          STD_METHOD GetToolTip, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr LPWSTR
          STD_METHOD GetCanonicalName, :ptr IExplorerCommand, :ptr GUID
          STD_METHOD GetState, :ptr IExplorerCommand, :ptr IShellItemArray, :BOOL, :ptr EXPCMDSTATE
          STD_METHOD Invoke_, :ptr IExplorerCommand, :ptr IShellItemArray, :ptr IBindCtx
          STD_METHOD GetFlags, :ptr IExplorerCommand, :ptr EXPCMDFLAGS
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
          STD_METHOD QueryInterface, :ptr IExplorerCommandState, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IExplorerCommandState
          STD_METHOD Release, :ptr IExplorerCommandState
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
          STD_METHOD QueryInterface, :ptr IInitializeCommand, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInitializeCommand
          STD_METHOD Release, :ptr IInitializeCommand
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
          STD_METHOD QueryInterface, :ptr IEnumExplorerCommand, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumExplorerCommand
          STD_METHOD Release, :ptr IEnumExplorerCommand
          STD_METHOD Next, :ptr IEnumExplorerCommand, :ULONG, :ptr ptr IExplorerCommand, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumExplorerCommand, :ULONG
          STD_METHOD Reset, :ptr IEnumExplorerCommand
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
          STD_METHOD QueryInterface, :ptr IExplorerCommandProvider, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IExplorerCommandProvider
          STD_METHOD Release, :ptr IExplorerCommandProvider
          STD_METHOD GetCommands, :ptr IExplorerCommandProvider, :ptr IUnknown, :REFIID, :ptr ptr
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
    
    externdef __MIDL_itf_shobjidl_core_0000_0139_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0139_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOpenControlPanel_INTERFACE_DEFINED__
      __IOpenControlPanel_INTERFACE_DEFINED__ equ <>
      externdef IID_IOpenControlPanel:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOpenControlPanelVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOpenControlPanelVtbl>
          STD_METHOD QueryInterface, :ptr IOpenControlPanel, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IOpenControlPanel
          STD_METHOD Release, :ptr IOpenControlPanel
          STD_METHOD Open, :ptr IOpenControlPanel, :LPCWSTR, :LPCWSTR, :ptr IUnknown
          STD_METHOD GetPath, :ptr IOpenControlPanel, :LPCWSTR, :LPWSTR, :UINT
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
    externdef __MIDL_itf_shobjidl_core_0000_0140_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0140_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFileSystemBindData_INTERFACE_DEFINED__
      __IFileSystemBindData_INTERFACE_DEFINED__ equ <>
      externdef IID_IFileSystemBindData:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFileSystemBindDataVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFileSystemBindDataVtbl>
          STD_METHOD QueryInterface, :ptr IFileSystemBindData, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFileSystemBindData
          STD_METHOD Release, :ptr IFileSystemBindData
          STD_METHOD SetFindData, :ptr IFileSystemBindData, :ptr WIN32_FIND_DATAW
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
          STD_METHOD QueryInterface, :ptr IFileSystemBindData2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IFileSystemBindData2
          STD_METHOD Release, :ptr IFileSystemBindData2
          STD_METHOD SetFindData, :ptr IFileSystemBindData2, :ptr WIN32_FIND_DATAW
          STD_METHOD GetFindData, :ptr IFileSystemBindData2, :ptr WIN32_FIND_DATAW
          STD_METHOD SetFileID, :ptr IFileSystemBindData2, :LARGE_INTEGER
          STD_METHOD GetFileID, :ptr IFileSystemBindData2, :ptr LARGE_INTEGER
          STD_METHOD SetJunctionCLSID, :ptr IFileSystemBindData2, :REFCLSID
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
      externdef __MIDL_itf_shobjidl_core_0000_0142_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0142_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr ICustomDestinationList, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICustomDestinationList
            STD_METHOD Release, :ptr ICustomDestinationList
            STD_METHOD SetAppID, :ptr ICustomDestinationList, :LPCWSTR
            STD_METHOD BeginList, :ptr ICustomDestinationList, :ptr UINT, :REFIID, :ptr ptr
            STD_METHOD AppendCategory, :ptr ICustomDestinationList, :LPCWSTR, :ptr IObjectArray
            STD_METHOD AppendKnownCategory, :ptr ICustomDestinationList, :KNOWNDESTCATEGORY
            STD_METHOD AddUserTasks, :ptr ICustomDestinationList, :ptr IObjectArray
            STD_METHOD CommitList, :ptr ICustomDestinationList
            STD_METHOD GetRemovedDestinations, :ptr ICustomDestinationList, :REFIID, :ptr ptr
            STD_METHOD DeleteList, :ptr ICustomDestinationList, :LPCWSTR
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
            STD_METHOD QueryInterface, :ptr IApplicationDestinations, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IApplicationDestinations
            STD_METHOD Release, :ptr IApplicationDestinations
            STD_METHOD SetAppID, :ptr IApplicationDestinations, :LPCWSTR
            STD_METHOD RemoveDestination, :ptr IApplicationDestinations, :ptr IUnknown
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
            STD_METHOD QueryInterface, :ptr IApplicationDocumentLists, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IApplicationDocumentLists
            STD_METHOD Release, :ptr IApplicationDocumentLists
            STD_METHOD SetAppID, :ptr IApplicationDocumentLists, :LPCWSTR
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
            STD_METHOD QueryInterface, :ptr IObjectWithAppUserModelID, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IObjectWithAppUserModelID
            STD_METHOD Release, :ptr IObjectWithAppUserModelID
            STD_METHOD SetAppID, :ptr IObjectWithAppUserModelID, :LPCWSTR
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
            STD_METHOD QueryInterface, :ptr IObjectWithProgID, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IObjectWithProgID
            STD_METHOD Release, :ptr IObjectWithProgID
            STD_METHOD SetProgID, :ptr IObjectWithProgID, :LPCWSTR
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
            STD_METHOD QueryInterface, :ptr IUpdateIDList, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IUpdateIDList
            STD_METHOD Release, :ptr IUpdateIDList
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
      externdef __MIDL_itf_shobjidl_core_0000_0148_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0148_v0_0_s_ifspec:RPC_IF_HANDLE
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
            STD_METHOD QueryInterface, :ptr IDesktopWallpaper, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDesktopWallpaper
            STD_METHOD Release, :ptr IDesktopWallpaper
            STD_METHOD SetWallpaper, :ptr IDesktopWallpaper, :LPCWSTR, :LPCWSTR
            STD_METHOD GetWallpaper, :ptr IDesktopWallpaper, :LPCWSTR, :ptr LPWSTR
            STD_METHOD GetMonitorDevicePathAt, :ptr IDesktopWallpaper, :UINT, :ptr LPWSTR
            STD_METHOD GetMonitorDevicePathCount, :ptr IDesktopWallpaper, :ptr UINT
            STD_METHOD GetMonitorRECT, :ptr IDesktopWallpaper, :LPCWSTR, :ptr RECT
            STD_METHOD SetBackgroundColor, :ptr IDesktopWallpaper, :COLORREF
            STD_METHOD GetBackgroundColor, :ptr IDesktopWallpaper, :ptr COLORREF
            STD_METHOD SetPosition, :ptr IDesktopWallpaper, :DESKTOP_WALLPAPER_POSITION
            STD_METHOD GetPosition, :ptr IDesktopWallpaper, :ptr DESKTOP_WALLPAPER_POSITION
            STD_METHOD SetSlideshow, :ptr IDesktopWallpaper, :ptr IShellItemArray
            STD_METHOD GetSlideshow, :ptr IDesktopWallpaper, :ptr ptr IShellItemArray
            STD_METHOD SetSlideshowOptions, :ptr IDesktopWallpaper, :DESKTOP_SLIDESHOW_OPTIONS, :UINT
            STD_METHOD GetSlideshowOptions, :ptr IDesktopWallpaper, :ptr DESKTOP_SLIDESHOW_OPTIONS, :ptr UINT
            STD_METHOD AdvanceSlideshow, :ptr IDesktopWallpaper, :LPCWSTR, :DESKTOP_SLIDESHOW_DIRECTION
            STD_METHOD GetStatus, :ptr IDesktopWallpaper, :ptr DESKTOP_SLIDESHOW_STATE
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
    externdef __MIDL_itf_shobjidl_core_0000_0149_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0149_v0_0_s_ifspec:RPC_IF_HANDLE
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
          STD_METHOD QueryInterface, :ptr IHomeGroup, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IHomeGroup
          STD_METHOD Release, :ptr IHomeGroup
          STD_METHOD IsMember, :ptr IHomeGroup, :ptr BOOL
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
          STD_METHOD QueryInterface, :ptr IInitializeWithPropertyStore, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IInitializeWithPropertyStore
          STD_METHOD Release, :ptr IInitializeWithPropertyStore
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
          STD_METHOD QueryInterface, :ptr IOpenSearchSource, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IOpenSearchSource
          STD_METHOD Release, :ptr IOpenSearchSource
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
          STD_METHOD QueryInterface, :ptr IShellLibrary, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IShellLibrary
          STD_METHOD Release, :ptr IShellLibrary
          STD_METHOD LoadLibraryFromItem, :ptr IShellLibrary, :ptr IShellItem, :DWORD
          STD_METHOD LoadLibraryFromKnownFolder, :ptr IShellLibrary, :REFKNOWNFOLDERID, :DWORD
          STD_METHOD AddFolder, :ptr IShellLibrary, :ptr IShellItem
          STD_METHOD RemoveFolder, :ptr IShellLibrary, :ptr IShellItem
          STD_METHOD GetFolders, :ptr IShellLibrary, :LIBRARYFOLDERFILTER, :REFIID, :ptr ptr
          STD_METHOD ResolveFolder, :ptr IShellLibrary, :ptr IShellItem, :DWORD, :REFIID, :ptr ptr
          STD_METHOD GetDefaultSaveFolder, :ptr IShellLibrary, :DEFAULTSAVEFOLDERTYPE, :REFIID, :ptr ptr
          STD_METHOD SetDefaultSaveFolder, :ptr IShellLibrary, :DEFAULTSAVEFOLDERTYPE, :ptr IShellItem
          STD_METHOD GetOptions, :ptr IShellLibrary, :ptr LIBRARYOPTIONFLAGS
          STD_METHOD SetOptions, :ptr IShellLibrary, :LIBRARYOPTIONFLAGS, :LIBRARYOPTIONFLAGS
          STD_METHOD GetFolderType, :ptr IShellLibrary, :ptr FOLDERTYPEID
          STD_METHOD SetFolderType, :ptr IShellLibrary, :REFFOLDERTYPEID
          STD_METHOD GetIcon, :ptr IShellLibrary, :ptr LPWSTR
          STD_METHOD SetIcon, :ptr IShellLibrary, :LPCWSTR
          STD_METHOD Commit, :ptr IShellLibrary
          STD_METHOD Save, :ptr IShellLibrary, :ptr IShellItem, :LPCWSTR, :LIBRARYSAVEFLAGS, :ptr ptr IShellItem
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
    
    DEFINE_ENUM_FLAG_OPERATORS(DEFAULT_FOLDER_MENU_RESTRICTIONS)
    externdef __MIDL_itf_shobjidl_core_0000_0153_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0153_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDefaultFolderMenuInitialize_INTERFACE_DEFINED__
      __IDefaultFolderMenuInitialize_INTERFACE_DEFINED__ equ <>
      externdef IID_IDefaultFolderMenuInitialize:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDefaultFolderMenuInitializeVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDefaultFolderMenuInitializeVtbl>
          STD_METHOD QueryInterface, :ptr IDefaultFolderMenuInitialize, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDefaultFolderMenuInitialize
          STD_METHOD Release, :ptr IDefaultFolderMenuInitialize
          STD_METHOD Initialize, :ptr IDefaultFolderMenuInitialize, :HWND, :ptr IContextMenuCB, :PCIDLIST_ABSOLUTE, :ptr IShellFolder, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr IUnknown, :UINT, :ptr HKEY
          STD_METHOD SetMenuRestrictions, :ptr IDefaultFolderMenuInitialize, :DEFAULT_FOLDER_MENU_RESTRICTIONS
          STD_METHOD GetMenuRestrictions, :ptr IDefaultFolderMenuInitialize, :DEFAULT_FOLDER_MENU_RESTRICTIONS, :ptr DEFAULT_FOLDER_MENU_RESTRICTIONS
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
      externdef __MIDL_itf_shobjidl_core_0000_0154_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0154_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IApplicationActivationManager_INTERFACE_DEFINED__
        __IApplicationActivationManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationActivationManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationActivationManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationActivationManagerVtbl>
            STD_METHOD QueryInterface, :ptr IApplicationActivationManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IApplicationActivationManager
            STD_METHOD Release, :ptr IApplicationActivationManager
            STD_METHOD ActivateApplication, :ptr IApplicationActivationManager, :LPCWSTR, :LPCWSTR, :ACTIVATEOPTIONS, :ptr DWORD
            STD_METHOD ActivateForFile, :ptr IApplicationActivationManager, :LPCWSTR, :ptr IShellItemArray, :LPCWSTR, :ptr DWORD
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
    externdef __MIDL_itf_shobjidl_core_0000_0155_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shobjidl_core_0000_0155_v0_0_s_ifspec:RPC_IF_HANDLE
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
      externdef __MIDL_itf_shobjidl_core_0000_0156_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0156_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAssocHandlerInvoker_INTERFACE_DEFINED__
        __IAssocHandlerInvoker_INTERFACE_DEFINED__ equ <>
        externdef IID_IAssocHandlerInvoker:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAssocHandlerInvokerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAssocHandlerInvokerVtbl>
            STD_METHOD QueryInterface, :ptr IAssocHandlerInvoker, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAssocHandlerInvoker
            STD_METHOD Release, :ptr IAssocHandlerInvoker
            STD_METHOD SupportsSelection, :ptr IAssocHandlerInvoker
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
      ifndef __IAssocHandler_INTERFACE_DEFINED__
        __IAssocHandler_INTERFACE_DEFINED__ equ <>
        externdef IID_IAssocHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAssocHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAssocHandlerVtbl>
            STD_METHOD QueryInterface, :ptr IAssocHandler, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAssocHandler
            STD_METHOD Release, :ptr IAssocHandler
            STD_METHOD GetName, :ptr IAssocHandler, :ptr LPWSTR
            STD_METHOD GetUIName, :ptr IAssocHandler, :ptr LPWSTR
            STD_METHOD GetIconLocation, :ptr IAssocHandler, :ptr LPWSTR, :ptr SDWORD
            STD_METHOD IsRecommended, :ptr IAssocHandler
            STD_METHOD MakeDefault, :ptr IAssocHandler, :LPCWSTR
            STD_METHOD Invoke_, :ptr IAssocHandler, :ptr IDataObject
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
            STD_METHOD QueryInterface, :ptr IEnumAssocHandlers, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IEnumAssocHandlers
            STD_METHOD Release, :ptr IEnumAssocHandlers
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
      externdef __MIDL_itf_shobjidl_core_0000_0159_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0159_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDataObjectProvider_INTERFACE_DEFINED__
        __IDataObjectProvider_INTERFACE_DEFINED__ equ <>
        externdef IID_IDataObjectProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDataObjectProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDataObjectProviderVtbl>
            STD_METHOD QueryInterface, :ptr IDataObjectProvider, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDataObjectProvider
            STD_METHOD Release, :ptr IDataObjectProvider
            STD_METHOD GetDataObject, :ptr IDataObjectProvider, :ptr ptr IDataObject
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
            STD_METHOD QueryInterface, :ptr IDataTransferManagerInterop, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IDataTransferManagerInterop
            STD_METHOD Release, :ptr IDataTransferManagerInterop
            STD_METHOD GetForWindow, :ptr IDataTransferManagerInterop, :HWND, :REFIID, :ptr ptr
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
      externdef __MIDL_itf_shobjidl_core_0000_0161_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0161_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IFrameworkInputPaneHandler_INTERFACE_DEFINED__
        __IFrameworkInputPaneHandler_INTERFACE_DEFINED__ equ <>
        externdef IID_IFrameworkInputPaneHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFrameworkInputPaneHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFrameworkInputPaneHandlerVtbl>
            STD_METHOD QueryInterface, :ptr IFrameworkInputPaneHandler, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFrameworkInputPaneHandler
            STD_METHOD Release, :ptr IFrameworkInputPaneHandler
            STD_METHOD Showing, :ptr IFrameworkInputPaneHandler, :ptr RECT, :BOOL
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
            STD_METHOD QueryInterface, :ptr IFrameworkInputPane, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFrameworkInputPane
            STD_METHOD Release, :ptr IFrameworkInputPane
            STD_METHOD Advise, :ptr IFrameworkInputPane, :ptr IUnknown, :ptr IFrameworkInputPaneHandler, :ptr DWORD
            STD_METHOD AdviseWithHWND, :ptr IFrameworkInputPane, :HWND, :ptr IFrameworkInputPaneHandler, :ptr DWORD
            STD_METHOD Unadvise, :ptr IFrameworkInputPane, :DWORD
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0163_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0163_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAppVisibilityEvents_INTERFACE_DEFINED__
        __IAppVisibilityEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IAppVisibilityEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAppVisibilityEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAppVisibilityEventsVtbl>
            STD_METHOD QueryInterface, :ptr IAppVisibilityEvents, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAppVisibilityEvents
            STD_METHOD Release, :ptr IAppVisibilityEvents
            STD_METHOD AppVisibilityOnMonitorChanged, :ptr IAppVisibilityEvents, :HMONITOR, :MONITOR_APP_VISIBILITY, :MONITOR_APP_VISIBILITY
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
            STD_METHOD QueryInterface, :ptr IAppVisibility, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAppVisibility
            STD_METHOD Release, :ptr IAppVisibility
            STD_METHOD GetAppVisibilityOnMonitor, :ptr IAppVisibility, :HMONITOR, :ptr MONITOR_APP_VISIBILITY
            STD_METHOD IsLauncherVisible, :ptr IAppVisibility, :ptr BOOL
            STD_METHOD Advise, :ptr IAppVisibility, :ptr IAppVisibilityEvents, :ptr DWORD
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0165_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0165_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPackageExecutionStateChangeNotification_INTERFACE_DEFINED__
        __IPackageExecutionStateChangeNotification_INTERFACE_DEFINED__ equ <>
        externdef IID_IPackageExecutionStateChangeNotification:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPackageExecutionStateChangeNotificationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPackageExecutionStateChangeNotificationVtbl>
            STD_METHOD QueryInterface, :ptr IPackageExecutionStateChangeNotification, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPackageExecutionStateChangeNotification
            STD_METHOD Release, :ptr IPackageExecutionStateChangeNotification
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
            STD_METHOD QueryInterface, :ptr IPackageDebugSettings, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPackageDebugSettings
            STD_METHOD Release, :ptr IPackageDebugSettings
            STD_METHOD EnableDebugging, :ptr IPackageDebugSettings, :LPCWSTR, :LPCWSTR, :PZZWSTR
            STD_METHOD DisableDebugging, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD Suspend, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD Resume, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD TerminateAllProcesses, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD SetTargetSessionId, :ptr IPackageDebugSettings, :ULONG
            STD_METHOD EnumerateBackgroundTasks, :ptr IPackageDebugSettings, :LPCWSTR, :ptr ULONG, :ptr LPCGUID, :ptr ptr LPCWSTR
            STD_METHOD ActivateBackgroundTask, :ptr IPackageDebugSettings, :LPCGUID
            STD_METHOD StartServicing, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD StopServicing, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD StartSessionRedirection, :ptr IPackageDebugSettings, :LPCWSTR, :ULONG
            STD_METHOD StopSessionRedirection, :ptr IPackageDebugSettings, :LPCWSTR
            STD_METHOD GetPackageExecutionState, :ptr IPackageDebugSettings, :LPCWSTR, :ptr PACKAGE_EXECUTION_STATE
            STD_METHOD RegisterForPackageStateChanges, :ptr IPackageDebugSettings, :LPCWSTR, :ptr IPackageExecutionStateChangeNotification, :ptr DWORD
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
            STD_METHOD QueryInterface, :ptr IPackageDebugSettings2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPackageDebugSettings2
            STD_METHOD Release, :ptr IPackageDebugSettings2
            STD_METHOD EnableDebugging, :ptr IPackageDebugSettings2, :LPCWSTR, :LPCWSTR, :PZZWSTR
            STD_METHOD DisableDebugging, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD Suspend, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD Resume, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD TerminateAllProcesses, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD SetTargetSessionId, :ptr IPackageDebugSettings2, :ULONG
            STD_METHOD EnumerateBackgroundTasks, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr ULONG, :ptr LPCGUID, :ptr ptr LPCWSTR
            STD_METHOD ActivateBackgroundTask, :ptr IPackageDebugSettings2, :LPCGUID
            STD_METHOD StartServicing, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD StopServicing, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD StartSessionRedirection, :ptr IPackageDebugSettings2, :LPCWSTR, :ULONG
            STD_METHOD StopSessionRedirection, :ptr IPackageDebugSettings2, :LPCWSTR
            STD_METHOD GetPackageExecutionState, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr PACKAGE_EXECUTION_STATE
            STD_METHOD RegisterForPackageStateChanges, :ptr IPackageDebugSettings2, :LPCWSTR, :ptr IPackageExecutionStateChangeNotification, :ptr DWORD
            STD_METHOD UnregisterForPackageStateChanges, :ptr IPackageDebugSettings2, :DWORD
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
            STD_METHOD QueryInterface, :ptr ISuspensionDependencyManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISuspensionDependencyManager
            STD_METHOD Release, :ptr ISuspensionDependencyManager
            STD_METHOD RegisterAsChild, :ptr ISuspensionDependencyManager, :HANDLE
            STD_METHOD GroupChildWithParent, :ptr ISuspensionDependencyManager, :HANDLE
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0169_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0169_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IExecuteCommandApplicationHostEnvironment_INTERFACE_DEFINED__
        __IExecuteCommandApplicationHostEnvironment_INTERFACE_DEFINED__ equ <>
        externdef IID_IExecuteCommandApplicationHostEnvironment:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IExecuteCommandApplicationHostEnvironmentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IExecuteCommandApplicationHostEnvironmentVtbl>
            STD_METHOD QueryInterface, :ptr IExecuteCommandApplicationHostEnvironment, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IExecuteCommandApplicationHostEnvironment
            STD_METHOD Release, :ptr IExecuteCommandApplicationHostEnvironment
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0170_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0170_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IExecuteCommandHost_INTERFACE_DEFINED__
        __IExecuteCommandHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IExecuteCommandHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IExecuteCommandHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IExecuteCommandHostVtbl>
            STD_METHOD QueryInterface, :ptr IExecuteCommandHost, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IExecuteCommandHost
            STD_METHOD Release, :ptr IExecuteCommandHost
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0171_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0171_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IApplicationDesignModeSettings_INTERFACE_DEFINED__
        __IApplicationDesignModeSettings_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationDesignModeSettings:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDesignModeSettingsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDesignModeSettingsVtbl>
            STD_METHOD QueryInterface, :ptr IApplicationDesignModeSettings, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IApplicationDesignModeSettings
            STD_METHOD Release, :ptr IApplicationDesignModeSettings
            STD_METHOD SetNativeDisplaySize, :ptr IApplicationDesignModeSettings, :SIZE_
            STD_METHOD SetScaleFactor, :ptr IApplicationDesignModeSettings, :DEVICE_SCALE_FACTOR
            STD_METHOD SetApplicationViewState, :ptr IApplicationDesignModeSettings, :APPLICATION_VIEW_STATE
            STD_METHOD ComputeApplicationSize, :ptr IApplicationDesignModeSettings, :ptr SIZE_
            STD_METHOD IsApplicationViewStateSupported, :ptr IApplicationDesignModeSettings, :APPLICATION_VIEW_STATE, :SIZE_, :DEVICE_SCALE_FACTOR, :ptr BOOL
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
        
        externdef __MIDL_itf_shobjidl_core_0000_0172_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0172_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IApplicationDesignModeSettings2_INTERFACE_DEFINED__
          __IApplicationDesignModeSettings2_INTERFACE_DEFINED__ equ <>
          externdef IID_IApplicationDesignModeSettings2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IApplicationDesignModeSettings2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IApplicationDesignModeSettings2Vtbl>
              STD_METHOD QueryInterface, :ptr IApplicationDesignModeSettings2, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IApplicationDesignModeSettings2
              STD_METHOD Release, :ptr IApplicationDesignModeSettings2
              STD_METHOD SetNativeDisplaySize, :ptr IApplicationDesignModeSettings2, :SIZE_
              STD_METHOD SetScaleFactor, :ptr IApplicationDesignModeSettings2, :DEVICE_SCALE_FACTOR
              STD_METHOD SetApplicationViewState, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_STATE
              STD_METHOD ComputeApplicationSize, :ptr IApplicationDesignModeSettings2, :ptr SIZE_
              STD_METHOD IsApplicationViewStateSupported, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_STATE, :SIZE_, :DEVICE_SCALE_FACTOR, :ptr BOOL
              STD_METHOD TriggerEdgeGesture, :ptr IApplicationDesignModeSettings2, :EDGE_GESTURE_KIND
              STD_METHOD SetNativeDisplayOrientation, :ptr IApplicationDesignModeSettings2, :NATIVE_DISPLAY_ORIENTATION
              STD_METHOD SetApplicationViewOrientation, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_ORIENTATION
              STD_METHOD SetAdjacentDisplayEdges, :ptr IApplicationDesignModeSettings2, :ADJACENT_DISPLAY_EDGES
              STD_METHOD SetIsOnLockScreen, :ptr IApplicationDesignModeSettings2, :BOOL
              STD_METHOD SetApplicationViewMinWidth, :ptr IApplicationDesignModeSettings2, :APPLICATION_VIEW_MIN_WIDTH
              STD_METHOD GetApplicationSizeBounds, :ptr IApplicationDesignModeSettings2, :ptr SIZE_, :ptr SIZE_
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
        externdef __MIDL_itf_shobjidl_core_0000_0173_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0173_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchTargetMonitor_INTERFACE_DEFINED__
          __ILaunchTargetMonitor_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchTargetMonitor:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchTargetMonitorVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchTargetMonitorVtbl>
              STD_METHOD QueryInterface, :ptr ILaunchTargetMonitor, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr ILaunchTargetMonitor
              STD_METHOD Release, :ptr ILaunchTargetMonitor
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
        
        externdef __MIDL_itf_shobjidl_core_0000_0174_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0174_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchSourceViewSizePreference_INTERFACE_DEFINED__
          __ILaunchSourceViewSizePreference_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchSourceViewSizePreference:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchSourceViewSizePreferenceVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchSourceViewSizePreferenceVtbl>
              STD_METHOD QueryInterface, :ptr ILaunchSourceViewSizePreference, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr ILaunchSourceViewSizePreference
              STD_METHOD Release, :ptr ILaunchSourceViewSizePreference
              STD_METHOD GetSourceViewToPosition, :ptr ILaunchSourceViewSizePreference, :ptr HWND
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
        externdef __MIDL_itf_shobjidl_core_0000_0175_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0175_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchTargetViewSizePreference_INTERFACE_DEFINED__
          __ILaunchTargetViewSizePreference_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchTargetViewSizePreference:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchTargetViewSizePreferenceVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchTargetViewSizePreferenceVtbl>
              STD_METHOD QueryInterface, :ptr ILaunchTargetViewSizePreference, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr ILaunchTargetViewSizePreference
              STD_METHOD Release, :ptr ILaunchTargetViewSizePreference
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
        externdef __MIDL_itf_shobjidl_core_0000_0176_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0176_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __ILaunchSourceAppUserModelId_INTERFACE_DEFINED__
          __ILaunchSourceAppUserModelId_INTERFACE_DEFINED__ equ <>
          externdef IID_ILaunchSourceAppUserModelId:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            ILaunchSourceAppUserModelIdVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <ILaunchSourceAppUserModelIdVtbl>
              STD_METHOD QueryInterface, :ptr ILaunchSourceAppUserModelId, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr ILaunchSourceAppUserModelId
              STD_METHOD Release, :ptr ILaunchSourceAppUserModelId
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
      externdef __MIDL_itf_shobjidl_core_0000_0177_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0177_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInitializeWithWindow_INTERFACE_DEFINED__
        __IInitializeWithWindow_INTERFACE_DEFINED__ equ <>
        externdef IID_IInitializeWithWindow:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInitializeWithWindowVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInitializeWithWindowVtbl>
            STD_METHOD QueryInterface, :ptr IInitializeWithWindow, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IInitializeWithWindow
            STD_METHOD Release, :ptr IInitializeWithWindow
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
            STD_METHOD QueryInterface, :ptr IHandlerInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IHandlerInfo
            STD_METHOD Release, :ptr IHandlerInfo
            STD_METHOD GetApplicationDisplayName, :ptr IHandlerInfo, :ptr LPWSTR
            STD_METHOD GetApplicationPublisher, :ptr IHandlerInfo, :ptr LPWSTR
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
      externdef __MIDL_itf_shobjidl_core_0000_0179_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0179_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHandlerActivationHost_INTERFACE_DEFINED__
        __IHandlerActivationHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IHandlerActivationHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHandlerActivationHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHandlerActivationHostVtbl>
            STD_METHOD QueryInterface, :ptr IHandlerActivationHost, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IHandlerActivationHost
            STD_METHOD Release, :ptr IHandlerActivationHost
            STD_METHOD BeforeCoCreateInstance, :ptr IHandlerActivationHost, :REFCLSID, :ptr IShellItemArray, :ptr IHandlerInfo
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
        externdef __MIDL_itf_shobjidl_core_0000_0180_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_shobjidl_core_0000_0180_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IAppActivationUIInfo_INTERFACE_DEFINED__
          __IAppActivationUIInfo_INTERFACE_DEFINED__ equ <>
          externdef IID_IAppActivationUIInfo:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IAppActivationUIInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IAppActivationUIInfoVtbl>
              STD_METHOD QueryInterface, :ptr IAppActivationUIInfo, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IAppActivationUIInfo
              STD_METHOD Release, :ptr IAppActivationUIInfo
              STD_METHOD GetMonitor, :ptr IAppActivationUIInfo, :ptr HMONITOR
              STD_METHOD GetInvokePoint, :ptr IAppActivationUIInfo, :ptr POINT
              STD_METHOD GetShowCommand, :ptr IAppActivationUIInfo, :ptr SDWORD
              STD_METHOD GetShowUI, :ptr IAppActivationUIInfo, :ptr BOOL
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
      
      externdef __MIDL_itf_shobjidl_core_0000_0181_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_shobjidl_core_0000_0181_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IContactManagerInterop_INTERFACE_DEFINED__
        __IContactManagerInterop_INTERFACE_DEFINED__ equ <>
        externdef IID_IContactManagerInterop:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IContactManagerInteropVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IContactManagerInteropVtbl>
            STD_METHOD QueryInterface, :ptr IContactManagerInterop, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IContactManagerInterop
            STD_METHOD Release, :ptr IContactManagerInterop
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
  endif
  externdef __MIDL_itf_shobjidl_core_0000_0182_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shobjidl_core_0000_0182_v0_0_s_ifspec:RPC_IF_HANDLE
  ifndef __IShellIconOverlayIdentifier_INTERFACE_DEFINED__
    __IShellIconOverlayIdentifier_INTERFACE_DEFINED__ equ <>
    externdef IID_IShellIconOverlayIdentifier:IID
    if Defined(__cplusplus) and  not Defined(CINTERFACE)
      ;[...]
    else
      IShellIconOverlayIdentifierVtbl struct
        BEGIN_INTERFACE
        ??Interface equ <IShellIconOverlayIdentifierVtbl>
        STD_METHOD QueryInterface, :ptr IShellIconOverlayIdentifier, :REFIID, :ptr ptr
        STD_METHOD AddRef, :ptr IShellIconOverlayIdentifier
        STD_METHOD Release, :ptr IShellIconOverlayIdentifier
        STD_METHOD IsMemberOf, :ptr IShellIconOverlayIdentifier, :LPCWSTR, :DWORD
        STD_METHOD GetOverlayInfo, :ptr IShellIconOverlayIdentifier, :LPWSTR, :SDWORD, :ptr SDWORD, :ptr DWORD
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
  externdef __MIDL_itf_shobjidl_core_0000_0183_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shobjidl_core_0000_0183_v0_0_s_ifspec:RPC_IF_HANDLE
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

