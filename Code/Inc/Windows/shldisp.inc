;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\shldisp.h', last modified: 19/04/2018 10:49
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
ifndef __shldisp_h__
  __shldisp_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IFolderViewOC_FWD_DEFINED__
    __IFolderViewOC_FWD_DEFINED__ equ <>
    ;IFolderViewOC typedef IFolderViewOC
    
  endif
  ifndef __DShellFolderViewEvents_FWD_DEFINED__
    __DShellFolderViewEvents_FWD_DEFINED__ equ <>
    ;DShellFolderViewEvents typedef DShellFolderViewEvents
    
  endif
  ifndef __ShellFolderViewOC_FWD_DEFINED__
    __ShellFolderViewOC_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellFolderViewOC typedef ShellFolderViewOC
      
    endif
  endif
  ifndef __DFConstraint_FWD_DEFINED__
    __DFConstraint_FWD_DEFINED__ equ <>
    ;DFConstraint typedef DFConstraint
    
  endif
  ifndef __FolderItem_FWD_DEFINED__
    __FolderItem_FWD_DEFINED__ equ <>
    ;FolderItem typedef FolderItem
    
  endif
  ifndef __FolderItems_FWD_DEFINED__
    __FolderItems_FWD_DEFINED__ equ <>
    ;FolderItems typedef FolderItems
    
  endif
  ifndef __FolderItemVerb_FWD_DEFINED__
    __FolderItemVerb_FWD_DEFINED__ equ <>
    ;FolderItemVerb typedef FolderItemVerb
    
  endif
  ifndef __FolderItemVerbs_FWD_DEFINED__
    __FolderItemVerbs_FWD_DEFINED__ equ <>
    ;FolderItemVerbs typedef FolderItemVerbs
    
  endif
  ifndef __Folder_FWD_DEFINED__
    __Folder_FWD_DEFINED__ equ <>
    ;Folder typedef Folder
    
  endif
  ifndef __Folder2_FWD_DEFINED__
    __Folder2_FWD_DEFINED__ equ <>
    ;Folder2 typedef Folder2
    
  endif
  ifndef __Folder3_FWD_DEFINED__
    __Folder3_FWD_DEFINED__ equ <>
    ;Folder3 typedef Folder3
    
  endif
  ifndef __FolderItem2_FWD_DEFINED__
    __FolderItem2_FWD_DEFINED__ equ <>
    ;FolderItem2 typedef FolderItem2
    
  endif
  ifndef __ShellFolderItem_FWD_DEFINED__
    __ShellFolderItem_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellFolderItem typedef ShellFolderItem
      
    endif
  endif
  ifndef __FolderItems2_FWD_DEFINED__
    __FolderItems2_FWD_DEFINED__ equ <>
    ;FolderItems2 typedef FolderItems2
    
  endif
  ifndef __FolderItems3_FWD_DEFINED__
    __FolderItems3_FWD_DEFINED__ equ <>
    ;FolderItems3 typedef FolderItems3
    
  endif
  ifndef __IShellLinkDual_FWD_DEFINED__
    __IShellLinkDual_FWD_DEFINED__ equ <>
    ;IShellLinkDual typedef IShellLinkDual
    
  endif
  ifndef __IShellLinkDual2_FWD_DEFINED__
    __IShellLinkDual2_FWD_DEFINED__ equ <>
    ;IShellLinkDual2 typedef IShellLinkDual2
    
  endif
  ifndef __ShellLinkObject_FWD_DEFINED__
    __ShellLinkObject_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellLinkObject typedef ShellLinkObject
      
    endif
  endif
  ifndef __IShellFolderViewDual_FWD_DEFINED__
    __IShellFolderViewDual_FWD_DEFINED__ equ <>
    ;IShellFolderViewDual typedef IShellFolderViewDual
    
  endif
  ifndef __IShellFolderViewDual2_FWD_DEFINED__
    __IShellFolderViewDual2_FWD_DEFINED__ equ <>
    ;IShellFolderViewDual2 typedef IShellFolderViewDual2
    
  endif
  ifndef __IShellFolderViewDual3_FWD_DEFINED__
    __IShellFolderViewDual3_FWD_DEFINED__ equ <>
    ;IShellFolderViewDual3 typedef IShellFolderViewDual3
    
  endif
  ifndef __ShellFolderView_FWD_DEFINED__
    __ShellFolderView_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellFolderView typedef ShellFolderView
      
    endif
  endif
  ifndef __IShellDispatch_FWD_DEFINED__
    __IShellDispatch_FWD_DEFINED__ equ <>
    ;IShellDispatch typedef IShellDispatch
    
  endif
  ifndef __IShellDispatch2_FWD_DEFINED__
    __IShellDispatch2_FWD_DEFINED__ equ <>
    ;IShellDispatch2 typedef IShellDispatch2
    
  endif
  ifndef __IShellDispatch3_FWD_DEFINED__
    __IShellDispatch3_FWD_DEFINED__ equ <>
    ;IShellDispatch3 typedef IShellDispatch3
    
  endif
  ifndef __IShellDispatch4_FWD_DEFINED__
    __IShellDispatch4_FWD_DEFINED__ equ <>
    ;IShellDispatch4 typedef IShellDispatch4
    
  endif
  ifndef __IShellDispatch5_FWD_DEFINED__
    __IShellDispatch5_FWD_DEFINED__ equ <>
    ;IShellDispatch5 typedef IShellDispatch5
    
  endif
  ifndef __IShellDispatch6_FWD_DEFINED__
    __IShellDispatch6_FWD_DEFINED__ equ <>
    ;IShellDispatch6 typedef IShellDispatch6
    
  endif
  ifndef __Shell_FWD_DEFINED__
    __Shell_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;Shell typedef Shell
      
    endif
  endif
  ifndef __ShellDispatchInproc_FWD_DEFINED__
    __ShellDispatchInproc_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;ShellDispatchInproc typedef ShellDispatchInproc
      
    endif
  endif
  ifndef __IFileSearchBand_FWD_DEFINED__
    __IFileSearchBand_FWD_DEFINED__ equ <>
    ;IFileSearchBand typedef IFileSearchBand
    
  endif
  ifndef __FileSearchBand_FWD_DEFINED__
    __FileSearchBand_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;FileSearchBand typedef FileSearchBand
      
    endif
  endif
  ifndef __IWebWizardHost_FWD_DEFINED__
    __IWebWizardHost_FWD_DEFINED__ equ <>
    ;IWebWizardHost typedef IWebWizardHost
    
  endif
  ifndef __IWebWizardHost2_FWD_DEFINED__
    __IWebWizardHost2_FWD_DEFINED__ equ <>
    ;IWebWizardHost2 typedef IWebWizardHost2
    
  endif
  ifndef __INewWDEvents_FWD_DEFINED__
    __INewWDEvents_FWD_DEFINED__ equ <>
    ;INewWDEvents typedef INewWDEvents
    
  endif
  ifndef __IAutoComplete_FWD_DEFINED__
    __IAutoComplete_FWD_DEFINED__ equ <>
    ;IAutoComplete typedef IAutoComplete
    
  endif
  ifndef __IAutoComplete2_FWD_DEFINED__
    __IAutoComplete2_FWD_DEFINED__ equ <>
    ;IAutoComplete2 typedef IAutoComplete2
    
  endif
  ifndef __IEnumACString_FWD_DEFINED__
    __IEnumACString_FWD_DEFINED__ equ <>
    ;IEnumACString typedef IEnumACString
    
  endif
  ifndef __IDataObjectAsyncCapability_FWD_DEFINED__
    __IDataObjectAsyncCapability_FWD_DEFINED__ equ <>
    ;IDataObjectAsyncCapability typedef IDataObjectAsyncCapability
    
  endif
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_shldisp_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shldisp_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __Shell32_LIBRARY_DEFINED__
      __Shell32_LIBRARY_DEFINED__ equ <>
      DECLSPEC_UUID("35f1a0d0-3e9a-11d2-8499-005345000000")
      OfflineFolderStatus typedef SDWORD
      OFS_INACTIVE equ -1
      OFS_ONLINE equ
      OFS_OFFLINE equ
      OFS_SERVERBACK equ
      OFS_DIRTYCACHE equ
      
      DECLSPEC_UUID("742A99A0-C77E-11D0-A32C-00A0C91EEDBA")
      ShellFolderViewOptions typedef SDWORD
      SFVVO_SHOWALLOBJECTS equ 1h
      SFVVO_SHOWEXTENSIONS equ 2h
      SFVVO_SHOWCOMPCOLOR equ 8h
      SFVVO_SHOWSYSFILES equ 20h
      SFVVO_WIN95CLASSIC equ 40h
      SFVVO_DOUBLECLICKINWEBVIEW equ 80h
      SFVVO_DESKTOPHTML equ 200h
      
      if (NTDDI_VERSION ge NTDDI_WIN8)
      endif
      DECLSPEC_UUID("CA31EA20-48D0-11CF-8350-444553540000")
      ShellSpecialFolderConstants typedef SDWORD
      ssfDESKTOP equ 0
      ssfPROGRAMS equ 2h
      ssfCONTROLS equ 3h
      ssfPRINTERS equ 4h
      ssfPERSONAL equ 5h
      ssfFAVORITES equ 6h
      ssfSTARTUP equ 7h
      ssfRECENT equ 8h
      ssfSENDTO equ 9h
      ssfBITBUCKET equ 0ah
      ssfSTARTMENU equ 0bh
      ssfDESKTOPDIRECTORY equ 10h
      ssfDRIVES equ 11h
      ssfNETWORK equ 12h
      ssfNETHOOD equ 13h
      ssfFONTS equ 14h
      ssfTEMPLATES equ 15h
      ssfCOMMONSTARTMENU equ 16h
      ssfCOMMONPROGRAMS equ 17h
      ssfCOMMONSTARTUP equ 18h
      ssfCOMMONDESKTOPDIR equ 19h
      ssfAPPDATA equ 1ah
      ssfPRINTHOOD equ 1bh
      ssfLOCALAPPDATA equ 1ch
      ssfALTSTARTUP equ 1dh
      ssfCOMMONALTSTARTUP equ 1eh
      ssfCOMMONFAVORITES equ 1fh
      ssfINTERNETCACHE equ 20h
      ssfCOOKIES equ 21h
      ssfHISTORY equ 22h
      ssfCOMMONAPPDATA equ 23h
      ssfWINDOWS equ 24h
      ssfSYSTEM equ 25h
      ssfPROGRAMFILES equ 26h
      ssfMYPICTURES equ 27h
      ssfPROFILE equ 28h
      ssfSYSTEMx86 equ 29h
      ssfPROGRAMFILESx86 equ 30h
      
      externdef LIBID_Shell32:IID
      ifndef __IFolderViewOC_INTERFACE_DEFINED__
        __IFolderViewOC_INTERFACE_DEFINED__ equ <>
        externdef IID_IFolderViewOC:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFolderViewOCVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFolderViewOCVtbl>
            STD_METHOD QueryInterface, :ptr IFolderViewOC, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFolderViewOC
            STD_METHOD Release, :ptr IFolderViewOC
            STD_METHOD GetTypeInfoCount, :ptr IFolderViewOC, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IFolderViewOC, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IFolderViewOC, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IFolderViewOC, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD SetFolderView, :ptr IFolderViewOC, :ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IFolderViewOCVtbl ends

          IFolderViewOC struct
            lpVtbl POINTER ?
          IFolderViewOC ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __DShellFolderViewEvents_DISPINTERFACE_DEFINED__
        __DShellFolderViewEvents_DISPINTERFACE_DEFINED__ equ <>
        externdef DIID_DShellFolderViewEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DShellFolderViewEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DShellFolderViewEventsVtbl>
            STD_METHOD QueryInterface, :ptr DShellFolderViewEvents, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr DShellFolderViewEvents
            STD_METHOD Release, :ptr DShellFolderViewEvents
            STD_METHOD GetTypeInfoCount, :ptr DShellFolderViewEvents, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr DShellFolderViewEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr DShellFolderViewEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr DShellFolderViewEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          DShellFolderViewEventsVtbl ends

          DShellFolderViewEvents struct
            lpVtbl POINTER ?
          DShellFolderViewEvents ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_ShellFolderViewOC:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __DFConstraint_INTERFACE_DEFINED__
        __DFConstraint_INTERFACE_DEFINED__ equ <>
        externdef IID_DFConstraint:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DFConstraintVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DFConstraintVtbl>
            STD_METHOD QueryInterface, :ptr DFConstraint, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr DFConstraint
            STD_METHOD Release, :ptr DFConstraint
            STD_METHOD GetTypeInfoCount, :ptr DFConstraint, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr DFConstraint, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr DFConstraint, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr DFConstraint, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Name, :ptr DFConstraint, :ptr BSTR
            STD_METHOD get_Value, :ptr DFConstraint, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          DFConstraintVtbl ends

          DFConstraint struct
            lpVtbl POINTER ?
          DFConstraint ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __FolderItem_INTERFACE_DEFINED__
        __FolderItem_INTERFACE_DEFINED__ equ <>
        LPFOLDERITEM typedef ptr FolderItem
        externdef IID_FolderItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemVtbl>
            STD_METHOD QueryInterface, :ptr FolderItem, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItem
            STD_METHOD Release, :ptr FolderItem
            STD_METHOD GetTypeInfoCount, :ptr FolderItem, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItem, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItem, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItem, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr FolderItem, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItem, :ptr ptr IDispatch
            STD_METHOD get_Name, :ptr FolderItem, :ptr BSTR
            STD_METHOD put_Name, :ptr FolderItem, :BSTR
            STD_METHOD get_Path, :ptr FolderItem, :ptr BSTR
            STD_METHOD get_GetLink, :ptr FolderItem, :ptr ptr IDispatch
            STD_METHOD get_GetFolder, :ptr FolderItem, :ptr ptr IDispatch
            STD_METHOD get_IsLink, :ptr FolderItem, :ptr VARIANT_BOOL
            STD_METHOD get_IsFolder, :ptr FolderItem, :ptr VARIANT_BOOL
            STD_METHOD get_IsFileSystem, :ptr FolderItem, :ptr VARIANT_BOOL
            STD_METHOD get_IsBrowsable, :ptr FolderItem, :ptr VARIANT_BOOL
            STD_METHOD get_ModifyDate, :ptr FolderItem, :ptr DATE
            STD_METHOD put_ModifyDate, :ptr FolderItem, :DATE
            STD_METHOD get_Size, :ptr FolderItem, :ptr LONG
            STD_METHOD get_Type, :ptr FolderItem, :ptr BSTR
            STD_METHOD Verbs, :ptr FolderItem, :ptr ptr FolderItemVerbs
            STD_METHOD InvokeVerb, :ptr FolderItem, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          FolderItemVtbl ends

          FolderItem struct
            lpVtbl POINTER ?
          FolderItem ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __FolderItems_INTERFACE_DEFINED__
        __FolderItems_INTERFACE_DEFINED__ equ <>
        externdef IID_FolderItems:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemsVtbl>
            STD_METHOD QueryInterface, :ptr FolderItems, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItems
            STD_METHOD Release, :ptr FolderItems
            STD_METHOD GetTypeInfoCount, :ptr FolderItems, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItems, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItems, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItems, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Count, :ptr FolderItems, :ptr SDWORD
            STD_METHOD get_Application, :ptr FolderItems, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItems, :ptr ptr IDispatch
            STD_METHOD Item, :ptr FolderItems, :VARIANT, :ptr ptr FolderItem
            STD_METHOD _NewEnum, :ptr FolderItems, :ptr ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          FolderItemsVtbl ends

          FolderItems struct
            lpVtbl POINTER ?
          FolderItems ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __FolderItemVerb_INTERFACE_DEFINED__
        __FolderItemVerb_INTERFACE_DEFINED__ equ <>
        externdef IID_FolderItemVerb:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemVerbVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemVerbVtbl>
            STD_METHOD QueryInterface, :ptr FolderItemVerb, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItemVerb
            STD_METHOD Release, :ptr FolderItemVerb
            STD_METHOD GetTypeInfoCount, :ptr FolderItemVerb, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItemVerb, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItemVerb, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItemVerb, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr FolderItemVerb, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItemVerb, :ptr ptr IDispatch
            STD_METHOD get_Name, :ptr FolderItemVerb, :ptr BSTR
            STD_METHOD DoIt, :ptr FolderItemVerb
            ??Interface equ <>
            END_INTERFACE
          FolderItemVerbVtbl ends

          FolderItemVerb struct
            lpVtbl POINTER ?
          FolderItemVerb ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __FolderItemVerbs_INTERFACE_DEFINED__
        __FolderItemVerbs_INTERFACE_DEFINED__ equ <>
        externdef IID_FolderItemVerbs:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemVerbsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemVerbsVtbl>
            STD_METHOD QueryInterface, :ptr FolderItemVerbs, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItemVerbs
            STD_METHOD Release, :ptr FolderItemVerbs
            STD_METHOD GetTypeInfoCount, :ptr FolderItemVerbs, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItemVerbs, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItemVerbs, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItemVerbs, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Count, :ptr FolderItemVerbs, :ptr SDWORD
            STD_METHOD get_Application, :ptr FolderItemVerbs, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItemVerbs, :ptr ptr IDispatch
            STD_METHOD Item, :ptr FolderItemVerbs, :VARIANT, :ptr ptr FolderItemVerb
            STD_METHOD _NewEnum, :ptr FolderItemVerbs, :ptr ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          FolderItemVerbsVtbl ends

          FolderItemVerbs struct
            lpVtbl POINTER ?
          FolderItemVerbs ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __Folder_INTERFACE_DEFINED__
        __Folder_INTERFACE_DEFINED__ equ <>
        externdef IID_Folder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderVtbl>
            STD_METHOD QueryInterface, :ptr Folder, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr Folder
            STD_METHOD Release, :ptr Folder
            STD_METHOD GetTypeInfoCount, :ptr Folder, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr Folder, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr Folder, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr Folder, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Title, :ptr Folder, :ptr BSTR
            STD_METHOD get_Application, :ptr Folder, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr Folder, :ptr ptr IDispatch
            STD_METHOD get_ParentFolder, :ptr Folder, :ptr ptr Folder
            STD_METHOD Items, :ptr Folder, :ptr ptr FolderItems
            STD_METHOD ParseName, :ptr Folder, :BSTR, :ptr ptr FolderItem
            STD_METHOD NewFolder, :ptr Folder, :BSTR, :VARIANT
            STD_METHOD MoveHere, :ptr Folder, :VARIANT, :VARIANT
            STD_METHOD CopyHere, :ptr Folder, :VARIANT, :VARIANT
            STD_METHOD GetDetailsOf, :ptr Folder, :VARIANT, :SDWORD, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          FolderVtbl ends

          Folder struct
            lpVtbl POINTER ?
          Folder ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __Folder2_INTERFACE_DEFINED__
        __Folder2_INTERFACE_DEFINED__ equ <>
        externdef IID_Folder2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          Folder2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <Folder2Vtbl>
            STD_METHOD QueryInterface, :ptr Folder2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr Folder2
            STD_METHOD Release, :ptr Folder2
            STD_METHOD GetTypeInfoCount, :ptr Folder2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr Folder2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr Folder2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr Folder2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Title, :ptr Folder2, :ptr BSTR
            STD_METHOD get_Application, :ptr Folder2, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr Folder2, :ptr ptr IDispatch
            STD_METHOD get_ParentFolder, :ptr Folder2, :ptr ptr Folder
            STD_METHOD Items, :ptr Folder2, :ptr ptr FolderItems
            STD_METHOD ParseName, :ptr Folder2, :BSTR, :ptr ptr FolderItem
            STD_METHOD NewFolder, :ptr Folder2, :BSTR, :VARIANT
            STD_METHOD MoveHere, :ptr Folder2, :VARIANT, :VARIANT
            STD_METHOD CopyHere, :ptr Folder2, :VARIANT, :VARIANT
            STD_METHOD GetDetailsOf, :ptr Folder2, :VARIANT, :SDWORD, :ptr BSTR
            STD_METHOD get_Self, :ptr Folder2, :ptr ptr FolderItem
            STD_METHOD get_OfflineStatus, :ptr Folder2, :ptr LONG
            STD_METHOD Synchronize, :ptr Folder2
            STD_METHOD get_HaveToShowWebViewBarricade, :ptr Folder2, :ptr VARIANT_BOOL
            STD_METHOD DismissedWebViewBarricade, :ptr Folder2
            ??Interface equ <>
            END_INTERFACE
          Folder2Vtbl ends

          Folder2 struct
            lpVtbl POINTER ?
          Folder2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __Folder3_INTERFACE_DEFINED__
        __Folder3_INTERFACE_DEFINED__ equ <>
        externdef IID_Folder3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          Folder3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <Folder3Vtbl>
            STD_METHOD QueryInterface, :ptr Folder3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr Folder3
            STD_METHOD Release, :ptr Folder3
            STD_METHOD GetTypeInfoCount, :ptr Folder3, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr Folder3, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr Folder3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr Folder3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Title, :ptr Folder3, :ptr BSTR
            STD_METHOD get_Application, :ptr Folder3, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr Folder3, :ptr ptr IDispatch
            STD_METHOD get_ParentFolder, :ptr Folder3, :ptr ptr Folder
            STD_METHOD Items, :ptr Folder3, :ptr ptr FolderItems
            STD_METHOD ParseName, :ptr Folder3, :BSTR, :ptr ptr FolderItem
            STD_METHOD NewFolder, :ptr Folder3, :BSTR, :VARIANT
            STD_METHOD MoveHere, :ptr Folder3, :VARIANT, :VARIANT
            STD_METHOD CopyHere, :ptr Folder3, :VARIANT, :VARIANT
            STD_METHOD GetDetailsOf, :ptr Folder3, :VARIANT, :SDWORD, :ptr BSTR
            STD_METHOD get_Self, :ptr Folder3, :ptr ptr FolderItem
            STD_METHOD get_OfflineStatus, :ptr Folder3, :ptr LONG
            STD_METHOD Synchronize, :ptr Folder3
            STD_METHOD get_HaveToShowWebViewBarricade, :ptr Folder3, :ptr VARIANT_BOOL
            STD_METHOD DismissedWebViewBarricade, :ptr Folder3
            STD_METHOD get_ShowWebViewBarricade, :ptr Folder3, :ptr VARIANT_BOOL
            STD_METHOD put_ShowWebViewBarricade, :ptr Folder3, :VARIANT_BOOL
            ??Interface equ <>
            END_INTERFACE
          Folder3Vtbl ends

          Folder3 struct
            lpVtbl POINTER ?
          Folder3 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __FolderItem2_INTERFACE_DEFINED__
        __FolderItem2_INTERFACE_DEFINED__ equ <>
        externdef IID_FolderItem2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItem2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItem2Vtbl>
            STD_METHOD QueryInterface, :ptr FolderItem2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItem2
            STD_METHOD Release, :ptr FolderItem2
            STD_METHOD GetTypeInfoCount, :ptr FolderItem2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItem2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItem2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItem2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr FolderItem2, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItem2, :ptr ptr IDispatch
            STD_METHOD get_Name, :ptr FolderItem2, :ptr BSTR
            STD_METHOD put_Name, :ptr FolderItem2, :BSTR
            STD_METHOD get_Path, :ptr FolderItem2, :ptr BSTR
            STD_METHOD get_GetLink, :ptr FolderItem2, :ptr ptr IDispatch
            STD_METHOD get_GetFolder, :ptr FolderItem2, :ptr ptr IDispatch
            STD_METHOD get_IsLink, :ptr FolderItem2, :ptr VARIANT_BOOL
            STD_METHOD get_IsFolder, :ptr FolderItem2, :ptr VARIANT_BOOL
            STD_METHOD get_IsFileSystem, :ptr FolderItem2, :ptr VARIANT_BOOL
            STD_METHOD get_IsBrowsable, :ptr FolderItem2, :ptr VARIANT_BOOL
            STD_METHOD get_ModifyDate, :ptr FolderItem2, :ptr DATE
            STD_METHOD put_ModifyDate, :ptr FolderItem2, :DATE
            STD_METHOD get_Size, :ptr FolderItem2, :ptr LONG
            STD_METHOD get_Type, :ptr FolderItem2, :ptr BSTR
            STD_METHOD Verbs, :ptr FolderItem2, :ptr ptr FolderItemVerbs
            STD_METHOD InvokeVerb, :ptr FolderItem2, :VARIANT
            STD_METHOD InvokeVerbEx, :ptr FolderItem2, :VARIANT, :VARIANT
            STD_METHOD ExtendedProperty, :ptr FolderItem2, :BSTR, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          FolderItem2Vtbl ends

          FolderItem2 struct
            lpVtbl POINTER ?
          FolderItem2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_ShellFolderItem:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __FolderItems2_INTERFACE_DEFINED__
        __FolderItems2_INTERFACE_DEFINED__ equ <>
        externdef IID_FolderItems2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItems2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItems2Vtbl>
            STD_METHOD QueryInterface, :ptr FolderItems2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItems2
            STD_METHOD Release, :ptr FolderItems2
            STD_METHOD GetTypeInfoCount, :ptr FolderItems2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItems2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItems2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItems2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Count, :ptr FolderItems2, :ptr SDWORD
            STD_METHOD get_Application, :ptr FolderItems2, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItems2, :ptr ptr IDispatch
            STD_METHOD Item, :ptr FolderItems2, :VARIANT, :ptr ptr FolderItem
            STD_METHOD _NewEnum, :ptr FolderItems2, :ptr ptr IUnknown
            STD_METHOD InvokeVerbEx, :ptr FolderItems2, :VARIANT, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          FolderItems2Vtbl ends

          FolderItems2 struct
            lpVtbl POINTER ?
          FolderItems2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __FolderItems3_INTERFACE_DEFINED__
        __FolderItems3_INTERFACE_DEFINED__ equ <>
        externdef IID_FolderItems3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItems3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItems3Vtbl>
            STD_METHOD QueryInterface, :ptr FolderItems3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr FolderItems3
            STD_METHOD Release, :ptr FolderItems3
            STD_METHOD GetTypeInfoCount, :ptr FolderItems3, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr FolderItems3, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr FolderItems3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr FolderItems3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Count, :ptr FolderItems3, :ptr SDWORD
            STD_METHOD get_Application, :ptr FolderItems3, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr FolderItems3, :ptr ptr IDispatch
            STD_METHOD Item, :ptr FolderItems3, :VARIANT, :ptr ptr FolderItem
            STD_METHOD _NewEnum, :ptr FolderItems3, :ptr ptr IUnknown
            STD_METHOD InvokeVerbEx, :ptr FolderItems3, :VARIANT, :VARIANT
            STD_METHOD Filter, :ptr FolderItems3, :SDWORD, :BSTR
            STD_METHOD get_Verbs, :ptr FolderItems3, :ptr ptr FolderItemVerbs
            ??Interface equ <>
            END_INTERFACE
          FolderItems3Vtbl ends

          FolderItems3 struct
            lpVtbl POINTER ?
          FolderItems3 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellLinkDual_INTERFACE_DEFINED__
        __IShellLinkDual_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellLinkDual:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellLinkDualVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellLinkDualVtbl>
            STD_METHOD QueryInterface, :ptr IShellLinkDual, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellLinkDual
            STD_METHOD Release, :ptr IShellLinkDual
            STD_METHOD GetTypeInfoCount, :ptr IShellLinkDual, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellLinkDual, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellLinkDual, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellLinkDual, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Path, :ptr IShellLinkDual, :ptr BSTR
            STD_METHOD put_Path, :ptr IShellLinkDual, :BSTR
            STD_METHOD get_Description, :ptr IShellLinkDual, :ptr BSTR
            STD_METHOD put_Description, :ptr IShellLinkDual, :BSTR
            STD_METHOD get_WorkingDirectory, :ptr IShellLinkDual, :ptr BSTR
            STD_METHOD put_WorkingDirectory, :ptr IShellLinkDual, :BSTR
            STD_METHOD get_Arguments, :ptr IShellLinkDual, :ptr BSTR
            STD_METHOD put_Arguments, :ptr IShellLinkDual, :BSTR
            STD_METHOD get_Hotkey, :ptr IShellLinkDual, :ptr SDWORD
            STD_METHOD put_Hotkey, :ptr IShellLinkDual, :SDWORD
            STD_METHOD get_ShowCommand, :ptr IShellLinkDual, :ptr SDWORD
            STD_METHOD put_ShowCommand, :ptr IShellLinkDual, :SDWORD
            STD_METHOD Resolve, :ptr IShellLinkDual, :SDWORD
            STD_METHOD GetIconLocation, :ptr IShellLinkDual, :ptr BSTR, :ptr SDWORD
            STD_METHOD SetIconLocation, :ptr IShellLinkDual, :BSTR, :SDWORD
            STD_METHOD Save, :ptr IShellLinkDual, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          IShellLinkDualVtbl ends

          IShellLinkDual struct
            lpVtbl POINTER ?
          IShellLinkDual ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellLinkDual2_INTERFACE_DEFINED__
        __IShellLinkDual2_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellLinkDual2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellLinkDual2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellLinkDual2Vtbl>
            STD_METHOD QueryInterface, :ptr IShellLinkDual2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellLinkDual2
            STD_METHOD Release, :ptr IShellLinkDual2
            STD_METHOD GetTypeInfoCount, :ptr IShellLinkDual2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellLinkDual2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellLinkDual2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellLinkDual2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Path, :ptr IShellLinkDual2, :ptr BSTR
            STD_METHOD put_Path, :ptr IShellLinkDual2, :BSTR
            STD_METHOD get_Description, :ptr IShellLinkDual2, :ptr BSTR
            STD_METHOD put_Description, :ptr IShellLinkDual2, :BSTR
            STD_METHOD get_WorkingDirectory, :ptr IShellLinkDual2, :ptr BSTR
            STD_METHOD put_WorkingDirectory, :ptr IShellLinkDual2, :BSTR
            STD_METHOD get_Arguments, :ptr IShellLinkDual2, :ptr BSTR
            STD_METHOD put_Arguments, :ptr IShellLinkDual2, :BSTR
            STD_METHOD get_Hotkey, :ptr IShellLinkDual2, :ptr SDWORD
            STD_METHOD put_Hotkey, :ptr IShellLinkDual2, :SDWORD
            STD_METHOD get_ShowCommand, :ptr IShellLinkDual2, :ptr SDWORD
            STD_METHOD put_ShowCommand, :ptr IShellLinkDual2, :SDWORD
            STD_METHOD Resolve, :ptr IShellLinkDual2, :SDWORD
            STD_METHOD GetIconLocation, :ptr IShellLinkDual2, :ptr BSTR, :ptr SDWORD
            STD_METHOD SetIconLocation, :ptr IShellLinkDual2, :BSTR, :SDWORD
            STD_METHOD Save, :ptr IShellLinkDual2, :VARIANT
            STD_METHOD get_Target, :ptr IShellLinkDual2, :ptr ptr FolderItem
            ??Interface equ <>
            END_INTERFACE
          IShellLinkDual2Vtbl ends

          IShellLinkDual2 struct
            lpVtbl POINTER ?
          IShellLinkDual2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_ShellLinkObject:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IShellFolderViewDual_INTERFACE_DEFINED__
        __IShellFolderViewDual_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellFolderViewDual:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFolderViewDualVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFolderViewDualVtbl>
            STD_METHOD QueryInterface, :ptr IShellFolderViewDual, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellFolderViewDual
            STD_METHOD Release, :ptr IShellFolderViewDual
            STD_METHOD GetTypeInfoCount, :ptr IShellFolderViewDual, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellFolderViewDual, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellFolderViewDual, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellFolderViewDual, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellFolderViewDual, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellFolderViewDual, :ptr ptr IDispatch
            STD_METHOD get_Folder, :ptr IShellFolderViewDual, :ptr ptr Folder
            STD_METHOD SelectedItems, :ptr IShellFolderViewDual, :ptr ptr FolderItems
            STD_METHOD get_FocusedItem, :ptr IShellFolderViewDual, :ptr ptr FolderItem
            STD_METHOD SelectItem, :ptr IShellFolderViewDual, :ptr VARIANT, :SDWORD
            STD_METHOD PopupItemMenu, :ptr IShellFolderViewDual, :ptr FolderItem, :VARIANT, :VARIANT, :ptr BSTR
            STD_METHOD get_Script, :ptr IShellFolderViewDual, :ptr ptr IDispatch
            STD_METHOD get_ViewOptions, :ptr IShellFolderViewDual, :ptr SDWORD
            ??Interface equ <>
            END_INTERFACE
          IShellFolderViewDualVtbl ends

          IShellFolderViewDual struct
            lpVtbl POINTER ?
          IShellFolderViewDual ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellFolderViewDual2_INTERFACE_DEFINED__
        __IShellFolderViewDual2_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellFolderViewDual2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFolderViewDual2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFolderViewDual2Vtbl>
            STD_METHOD QueryInterface, :ptr IShellFolderViewDual2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellFolderViewDual2
            STD_METHOD Release, :ptr IShellFolderViewDual2
            STD_METHOD GetTypeInfoCount, :ptr IShellFolderViewDual2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellFolderViewDual2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellFolderViewDual2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellFolderViewDual2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellFolderViewDual2, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellFolderViewDual2, :ptr ptr IDispatch
            STD_METHOD get_Folder, :ptr IShellFolderViewDual2, :ptr ptr Folder
            STD_METHOD SelectedItems, :ptr IShellFolderViewDual2, :ptr ptr FolderItems
            STD_METHOD get_FocusedItem, :ptr IShellFolderViewDual2, :ptr ptr FolderItem
            STD_METHOD SelectItem, :ptr IShellFolderViewDual2, :ptr VARIANT, :SDWORD
            STD_METHOD PopupItemMenu, :ptr IShellFolderViewDual2, :ptr FolderItem, :VARIANT, :VARIANT, :ptr BSTR
            STD_METHOD get_Script, :ptr IShellFolderViewDual2, :ptr ptr IDispatch
            STD_METHOD get_ViewOptions, :ptr IShellFolderViewDual2, :ptr SDWORD
            STD_METHOD get_CurrentViewMode, :ptr IShellFolderViewDual2, :ptr UINT
            STD_METHOD put_CurrentViewMode, :ptr IShellFolderViewDual2, :UINT
            STD_METHOD SelectItemRelative, :ptr IShellFolderViewDual2, :SDWORD
            ??Interface equ <>
            END_INTERFACE
          IShellFolderViewDual2Vtbl ends

          IShellFolderViewDual2 struct
            lpVtbl POINTER ?
          IShellFolderViewDual2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellFolderViewDual3_INTERFACE_DEFINED__
        __IShellFolderViewDual3_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellFolderViewDual3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFolderViewDual3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFolderViewDual3Vtbl>
            STD_METHOD QueryInterface, :ptr IShellFolderViewDual3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellFolderViewDual3
            STD_METHOD Release, :ptr IShellFolderViewDual3
            STD_METHOD GetTypeInfoCount, :ptr IShellFolderViewDual3, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellFolderViewDual3, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellFolderViewDual3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellFolderViewDual3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellFolderViewDual3, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellFolderViewDual3, :ptr ptr IDispatch
            STD_METHOD get_Folder, :ptr IShellFolderViewDual3, :ptr ptr Folder
            STD_METHOD SelectedItems, :ptr IShellFolderViewDual3, :ptr ptr FolderItems
            STD_METHOD get_FocusedItem, :ptr IShellFolderViewDual3, :ptr ptr FolderItem
            STD_METHOD SelectItem, :ptr IShellFolderViewDual3, :ptr VARIANT, :SDWORD
            STD_METHOD PopupItemMenu, :ptr IShellFolderViewDual3, :ptr FolderItem, :VARIANT, :VARIANT, :ptr BSTR
            STD_METHOD get_Script, :ptr IShellFolderViewDual3, :ptr ptr IDispatch
            STD_METHOD get_ViewOptions, :ptr IShellFolderViewDual3, :ptr SDWORD
            STD_METHOD get_CurrentViewMode, :ptr IShellFolderViewDual3, :ptr UINT
            STD_METHOD put_CurrentViewMode, :ptr IShellFolderViewDual3, :UINT
            STD_METHOD SelectItemRelative, :ptr IShellFolderViewDual3, :SDWORD
            STD_METHOD get_GroupBy, :ptr IShellFolderViewDual3, :ptr BSTR
            STD_METHOD put_GroupBy, :ptr IShellFolderViewDual3, :BSTR
            STD_METHOD get_FolderFlags, :ptr IShellFolderViewDual3, :ptr DWORD
            STD_METHOD put_FolderFlags, :ptr IShellFolderViewDual3, :DWORD
            STD_METHOD get_SortColumns, :ptr IShellFolderViewDual3, :ptr BSTR
            STD_METHOD put_SortColumns, :ptr IShellFolderViewDual3, :BSTR
            STD_METHOD put_IconSize, :ptr IShellFolderViewDual3, :SDWORD
            STD_METHOD get_IconSize, :ptr IShellFolderViewDual3, :ptr SDWORD
            STD_METHOD FilterView, :ptr IShellFolderViewDual3, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IShellFolderViewDual3Vtbl ends

          IShellFolderViewDual3 struct
            lpVtbl POINTER ?
          IShellFolderViewDual3 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_ShellFolderView:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IShellDispatch_INTERFACE_DEFINED__
        __IShellDispatch_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellDispatch:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatchVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatchVtbl>
            STD_METHOD QueryInterface, :ptr IShellDispatch, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellDispatch
            STD_METHOD Release, :ptr IShellDispatch
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellDispatch, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellDispatch, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellDispatch, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellDispatch, :ptr ptr IDispatch
            STD_METHOD NameSpace, :ptr IShellDispatch, :VARIANT, :ptr ptr Folder
            STD_METHOD BrowseForFolder, :ptr IShellDispatch, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            STD_METHOD Windows, :ptr IShellDispatch, :ptr ptr IDispatch
            STD_METHOD Open, :ptr IShellDispatch, :VARIANT
            STD_METHOD Explore, :ptr IShellDispatch, :VARIANT
            STD_METHOD MinimizeAll, :ptr IShellDispatch
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch
            STD_METHOD FileRun, :ptr IShellDispatch
            STD_METHOD CascadeWindows, :ptr IShellDispatch
            STD_METHOD TileVertically, :ptr IShellDispatch
            STD_METHOD TileHorizontally, :ptr IShellDispatch
            STD_METHOD ShutdownWindows, :ptr IShellDispatch
            STD_METHOD Suspend, :ptr IShellDispatch
            STD_METHOD EjectPC, :ptr IShellDispatch
            STD_METHOD SetTime, :ptr IShellDispatch
            STD_METHOD TrayProperties, :ptr IShellDispatch
            STD_METHOD Help, :ptr IShellDispatch
            STD_METHOD FindFiles, :ptr IShellDispatch
            STD_METHOD FindComputer, :ptr IShellDispatch
            STD_METHOD RefreshMenu, :ptr IShellDispatch
            STD_METHOD ControlPanelItem, :ptr IShellDispatch, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IShellDispatchVtbl ends

          IShellDispatch struct
            lpVtbl POINTER ?
          IShellDispatch ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellDispatch2_INTERFACE_DEFINED__
        __IShellDispatch2_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellDispatch2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch2Vtbl>
            STD_METHOD QueryInterface, :ptr IShellDispatch2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellDispatch2
            STD_METHOD Release, :ptr IShellDispatch2
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellDispatch2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellDispatch2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellDispatch2, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellDispatch2, :ptr ptr IDispatch
            STD_METHOD NameSpace, :ptr IShellDispatch2, :VARIANT, :ptr ptr Folder
            STD_METHOD BrowseForFolder, :ptr IShellDispatch2, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            STD_METHOD Windows, :ptr IShellDispatch2, :ptr ptr IDispatch
            STD_METHOD Open, :ptr IShellDispatch2, :VARIANT
            STD_METHOD Explore, :ptr IShellDispatch2, :VARIANT
            STD_METHOD MinimizeAll, :ptr IShellDispatch2
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch2
            STD_METHOD FileRun, :ptr IShellDispatch2
            STD_METHOD CascadeWindows, :ptr IShellDispatch2
            STD_METHOD TileVertically, :ptr IShellDispatch2
            STD_METHOD TileHorizontally, :ptr IShellDispatch2
            STD_METHOD ShutdownWindows, :ptr IShellDispatch2
            STD_METHOD Suspend, :ptr IShellDispatch2
            STD_METHOD EjectPC, :ptr IShellDispatch2
            STD_METHOD SetTime, :ptr IShellDispatch2
            STD_METHOD TrayProperties, :ptr IShellDispatch2
            STD_METHOD Help, :ptr IShellDispatch2
            STD_METHOD FindFiles, :ptr IShellDispatch2
            STD_METHOD FindComputer, :ptr IShellDispatch2
            STD_METHOD RefreshMenu, :ptr IShellDispatch2
            STD_METHOD ControlPanelItem, :ptr IShellDispatch2, :BSTR
            STD_METHOD IsRestricted, :ptr IShellDispatch2, :BSTR, :BSTR, :ptr SDWORD
            STD_METHOD ShellExecute, :ptr IShellDispatch2, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            STD_METHOD FindPrinter, :ptr IShellDispatch2, :BSTR, :BSTR, :BSTR
            STD_METHOD GetSystemInformation, :ptr IShellDispatch2, :BSTR, :ptr VARIANT
            STD_METHOD ServiceStart, :ptr IShellDispatch2, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD ServiceStop, :ptr IShellDispatch2, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD IsServiceRunning, :ptr IShellDispatch2, :BSTR, :ptr VARIANT
            STD_METHOD CanStartStopService, :ptr IShellDispatch2, :BSTR, :ptr VARIANT
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch2, :BSTR, :VARIANT, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch2Vtbl ends

          IShellDispatch2 struct
            lpVtbl POINTER ?
          IShellDispatch2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellDispatch3_INTERFACE_DEFINED__
        __IShellDispatch3_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellDispatch3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch3Vtbl>
            STD_METHOD QueryInterface, :ptr IShellDispatch3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellDispatch3
            STD_METHOD Release, :ptr IShellDispatch3
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch3, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellDispatch3, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellDispatch3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellDispatch3, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellDispatch3, :ptr ptr IDispatch
            STD_METHOD NameSpace, :ptr IShellDispatch3, :VARIANT, :ptr ptr Folder
            STD_METHOD BrowseForFolder, :ptr IShellDispatch3, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            STD_METHOD Windows, :ptr IShellDispatch3, :ptr ptr IDispatch
            STD_METHOD Open, :ptr IShellDispatch3, :VARIANT
            STD_METHOD Explore, :ptr IShellDispatch3, :VARIANT
            STD_METHOD MinimizeAll, :ptr IShellDispatch3
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch3
            STD_METHOD FileRun, :ptr IShellDispatch3
            STD_METHOD CascadeWindows, :ptr IShellDispatch3
            STD_METHOD TileVertically, :ptr IShellDispatch3
            STD_METHOD TileHorizontally, :ptr IShellDispatch3
            STD_METHOD ShutdownWindows, :ptr IShellDispatch3
            STD_METHOD Suspend, :ptr IShellDispatch3
            STD_METHOD EjectPC, :ptr IShellDispatch3
            STD_METHOD SetTime, :ptr IShellDispatch3
            STD_METHOD TrayProperties, :ptr IShellDispatch3
            STD_METHOD Help, :ptr IShellDispatch3
            STD_METHOD FindFiles, :ptr IShellDispatch3
            STD_METHOD FindComputer, :ptr IShellDispatch3
            STD_METHOD RefreshMenu, :ptr IShellDispatch3
            STD_METHOD ControlPanelItem, :ptr IShellDispatch3, :BSTR
            STD_METHOD IsRestricted, :ptr IShellDispatch3, :BSTR, :BSTR, :ptr SDWORD
            STD_METHOD ShellExecute, :ptr IShellDispatch3, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            STD_METHOD FindPrinter, :ptr IShellDispatch3, :BSTR, :BSTR, :BSTR
            STD_METHOD GetSystemInformation, :ptr IShellDispatch3, :BSTR, :ptr VARIANT
            STD_METHOD ServiceStart, :ptr IShellDispatch3, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD ServiceStop, :ptr IShellDispatch3, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD IsServiceRunning, :ptr IShellDispatch3, :BSTR, :ptr VARIANT
            STD_METHOD CanStartStopService, :ptr IShellDispatch3, :BSTR, :ptr VARIANT
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch3, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD AddToRecent, :ptr IShellDispatch3, :VARIANT, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch3Vtbl ends

          IShellDispatch3 struct
            lpVtbl POINTER ?
          IShellDispatch3 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellDispatch4_INTERFACE_DEFINED__
        __IShellDispatch4_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellDispatch4:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch4Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch4Vtbl>
            STD_METHOD QueryInterface, :ptr IShellDispatch4, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellDispatch4
            STD_METHOD Release, :ptr IShellDispatch4
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch4, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellDispatch4, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch4, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellDispatch4, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellDispatch4, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellDispatch4, :ptr ptr IDispatch
            STD_METHOD NameSpace, :ptr IShellDispatch4, :VARIANT, :ptr ptr Folder
            STD_METHOD BrowseForFolder, :ptr IShellDispatch4, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            STD_METHOD Windows, :ptr IShellDispatch4, :ptr ptr IDispatch
            STD_METHOD Open, :ptr IShellDispatch4, :VARIANT
            STD_METHOD Explore, :ptr IShellDispatch4, :VARIANT
            STD_METHOD MinimizeAll, :ptr IShellDispatch4
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch4
            STD_METHOD FileRun, :ptr IShellDispatch4
            STD_METHOD CascadeWindows, :ptr IShellDispatch4
            STD_METHOD TileVertically, :ptr IShellDispatch4
            STD_METHOD TileHorizontally, :ptr IShellDispatch4
            STD_METHOD ShutdownWindows, :ptr IShellDispatch4
            STD_METHOD Suspend, :ptr IShellDispatch4
            STD_METHOD EjectPC, :ptr IShellDispatch4
            STD_METHOD SetTime, :ptr IShellDispatch4
            STD_METHOD TrayProperties, :ptr IShellDispatch4
            STD_METHOD Help, :ptr IShellDispatch4
            STD_METHOD FindFiles, :ptr IShellDispatch4
            STD_METHOD FindComputer, :ptr IShellDispatch4
            STD_METHOD RefreshMenu, :ptr IShellDispatch4
            STD_METHOD ControlPanelItem, :ptr IShellDispatch4, :BSTR
            STD_METHOD IsRestricted, :ptr IShellDispatch4, :BSTR, :BSTR, :ptr SDWORD
            STD_METHOD ShellExecute, :ptr IShellDispatch4, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            STD_METHOD FindPrinter, :ptr IShellDispatch4, :BSTR, :BSTR, :BSTR
            STD_METHOD GetSystemInformation, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            STD_METHOD ServiceStart, :ptr IShellDispatch4, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD ServiceStop, :ptr IShellDispatch4, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD IsServiceRunning, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            STD_METHOD CanStartStopService, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch4, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD AddToRecent, :ptr IShellDispatch4, :VARIANT, :BSTR
            STD_METHOD WindowsSecurity, :ptr IShellDispatch4
            STD_METHOD ToggleDesktop, :ptr IShellDispatch4
            STD_METHOD ExplorerPolicy, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            STD_METHOD GetSetting, :ptr IShellDispatch4, :SDWORD, :ptr VARIANT_BOOL
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch4Vtbl ends

          IShellDispatch4 struct
            lpVtbl POINTER ?
          IShellDispatch4 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellDispatch5_INTERFACE_DEFINED__
        __IShellDispatch5_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellDispatch5:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch5Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch5Vtbl>
            STD_METHOD QueryInterface, :ptr IShellDispatch5, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellDispatch5
            STD_METHOD Release, :ptr IShellDispatch5
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch5, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellDispatch5, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch5, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellDispatch5, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellDispatch5, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellDispatch5, :ptr ptr IDispatch
            STD_METHOD NameSpace, :ptr IShellDispatch5, :VARIANT, :ptr ptr Folder
            STD_METHOD BrowseForFolder, :ptr IShellDispatch5, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            STD_METHOD Windows, :ptr IShellDispatch5, :ptr ptr IDispatch
            STD_METHOD Open, :ptr IShellDispatch5, :VARIANT
            STD_METHOD Explore, :ptr IShellDispatch5, :VARIANT
            STD_METHOD MinimizeAll, :ptr IShellDispatch5
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch5
            STD_METHOD FileRun, :ptr IShellDispatch5
            STD_METHOD CascadeWindows, :ptr IShellDispatch5
            STD_METHOD TileVertically, :ptr IShellDispatch5
            STD_METHOD TileHorizontally, :ptr IShellDispatch5
            STD_METHOD ShutdownWindows, :ptr IShellDispatch5
            STD_METHOD Suspend, :ptr IShellDispatch5
            STD_METHOD EjectPC, :ptr IShellDispatch5
            STD_METHOD SetTime, :ptr IShellDispatch5
            STD_METHOD TrayProperties, :ptr IShellDispatch5
            STD_METHOD Help, :ptr IShellDispatch5
            STD_METHOD FindFiles, :ptr IShellDispatch5
            STD_METHOD FindComputer, :ptr IShellDispatch5
            STD_METHOD RefreshMenu, :ptr IShellDispatch5
            STD_METHOD ControlPanelItem, :ptr IShellDispatch5, :BSTR
            STD_METHOD IsRestricted, :ptr IShellDispatch5, :BSTR, :BSTR, :ptr SDWORD
            STD_METHOD ShellExecute, :ptr IShellDispatch5, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            STD_METHOD FindPrinter, :ptr IShellDispatch5, :BSTR, :BSTR, :BSTR
            STD_METHOD GetSystemInformation, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            STD_METHOD ServiceStart, :ptr IShellDispatch5, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD ServiceStop, :ptr IShellDispatch5, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD IsServiceRunning, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            STD_METHOD CanStartStopService, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch5, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD AddToRecent, :ptr IShellDispatch5, :VARIANT, :BSTR
            STD_METHOD WindowsSecurity, :ptr IShellDispatch5
            STD_METHOD ToggleDesktop, :ptr IShellDispatch5
            STD_METHOD ExplorerPolicy, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            STD_METHOD GetSetting, :ptr IShellDispatch5, :SDWORD, :ptr VARIANT_BOOL
            STD_METHOD WindowSwitcher, :ptr IShellDispatch5
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch5Vtbl ends

          IShellDispatch5 struct
            lpVtbl POINTER ?
          IShellDispatch5 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IShellDispatch6_INTERFACE_DEFINED__
        __IShellDispatch6_INTERFACE_DEFINED__ equ <>
        externdef IID_IShellDispatch6:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch6Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch6Vtbl>
            STD_METHOD QueryInterface, :ptr IShellDispatch6, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IShellDispatch6
            STD_METHOD Release, :ptr IShellDispatch6
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch6, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IShellDispatch6, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch6, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IShellDispatch6, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_Application, :ptr IShellDispatch6, :ptr ptr IDispatch
            STD_METHOD get_Parent, :ptr IShellDispatch6, :ptr ptr IDispatch
            STD_METHOD NameSpace, :ptr IShellDispatch6, :VARIANT, :ptr ptr Folder
            STD_METHOD BrowseForFolder, :ptr IShellDispatch6, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            STD_METHOD Windows, :ptr IShellDispatch6, :ptr ptr IDispatch
            STD_METHOD Open, :ptr IShellDispatch6, :VARIANT
            STD_METHOD Explore, :ptr IShellDispatch6, :VARIANT
            STD_METHOD MinimizeAll, :ptr IShellDispatch6
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch6
            STD_METHOD FileRun, :ptr IShellDispatch6
            STD_METHOD CascadeWindows, :ptr IShellDispatch6
            STD_METHOD TileVertically, :ptr IShellDispatch6
            STD_METHOD TileHorizontally, :ptr IShellDispatch6
            STD_METHOD ShutdownWindows, :ptr IShellDispatch6
            STD_METHOD Suspend, :ptr IShellDispatch6
            STD_METHOD EjectPC, :ptr IShellDispatch6
            STD_METHOD SetTime, :ptr IShellDispatch6
            STD_METHOD TrayProperties, :ptr IShellDispatch6
            STD_METHOD Help, :ptr IShellDispatch6
            STD_METHOD FindFiles, :ptr IShellDispatch6
            STD_METHOD FindComputer, :ptr IShellDispatch6
            STD_METHOD RefreshMenu, :ptr IShellDispatch6
            STD_METHOD ControlPanelItem, :ptr IShellDispatch6, :BSTR
            STD_METHOD IsRestricted, :ptr IShellDispatch6, :BSTR, :BSTR, :ptr SDWORD
            STD_METHOD ShellExecute, :ptr IShellDispatch6, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            STD_METHOD FindPrinter, :ptr IShellDispatch6, :BSTR, :BSTR, :BSTR
            STD_METHOD GetSystemInformation, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            STD_METHOD ServiceStart, :ptr IShellDispatch6, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD ServiceStop, :ptr IShellDispatch6, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD IsServiceRunning, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            STD_METHOD CanStartStopService, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch6, :BSTR, :VARIANT, :ptr VARIANT
            STD_METHOD AddToRecent, :ptr IShellDispatch6, :VARIANT, :BSTR
            STD_METHOD WindowsSecurity, :ptr IShellDispatch6
            STD_METHOD ToggleDesktop, :ptr IShellDispatch6
            STD_METHOD ExplorerPolicy, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            STD_METHOD GetSetting, :ptr IShellDispatch6, :SDWORD, :ptr VARIANT_BOOL
            STD_METHOD WindowSwitcher, :ptr IShellDispatch6
            STD_METHOD SearchCommand, :ptr IShellDispatch6
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch6Vtbl ends

          IShellDispatch6 struct
            lpVtbl POINTER ?
          IShellDispatch6 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_Shell:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellDispatchInproc:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IFileSearchBand_INTERFACE_DEFINED__
        __IFileSearchBand_INTERFACE_DEFINED__ equ <>
        externdef IID_IFileSearchBand:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileSearchBandVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileSearchBandVtbl>
            STD_METHOD QueryInterface, :ptr IFileSearchBand, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFileSearchBand
            STD_METHOD Release, :ptr IFileSearchBand
            STD_METHOD GetTypeInfoCount, :ptr IFileSearchBand, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IFileSearchBand, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IFileSearchBand, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IFileSearchBand, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD SetFocus, :ptr IFileSearchBand
            STD_METHOD SetSearchParameters, :ptr IFileSearchBand, :ptr BSTR, :VARIANT_BOOL, :ptr VARIANT, :ptr VARIANT
            STD_METHOD get_SearchID, :ptr IFileSearchBand, :ptr BSTR
            STD_METHOD get_Scope, :ptr IFileSearchBand, :ptr VARIANT
            STD_METHOD get_QueryFile, :ptr IFileSearchBand, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          IFileSearchBandVtbl ends

          IFileSearchBand struct
            lpVtbl POINTER ?
          IFileSearchBand ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_FileSearchBand:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IWebWizardHost_INTERFACE_DEFINED__
        __IWebWizardHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IWebWizardHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebWizardHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebWizardHostVtbl>
            STD_METHOD QueryInterface, :ptr IWebWizardHost, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IWebWizardHost
            STD_METHOD Release, :ptr IWebWizardHost
            STD_METHOD GetTypeInfoCount, :ptr IWebWizardHost, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IWebWizardHost, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IWebWizardHost, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IWebWizardHost, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD FinalBack, :ptr IWebWizardHost
            STD_METHOD FinalNext, :ptr IWebWizardHost
            STD_METHOD Cancel, :ptr IWebWizardHost
            STD_METHOD put_Caption, :ptr IWebWizardHost, :BSTR
            STD_METHOD get_Caption, :ptr IWebWizardHost, :ptr BSTR
            STD_METHOD put_Property, :ptr IWebWizardHost, :BSTR, :ptr VARIANT
            STD_METHOD get_Property, :ptr IWebWizardHost, :BSTR, :ptr VARIANT
            STD_METHOD SetWizardButtons, :ptr IWebWizardHost, :VARIANT_BOOL, :VARIANT_BOOL, :VARIANT_BOOL
            STD_METHOD SetHeaderText, :ptr IWebWizardHost, :BSTR, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IWebWizardHostVtbl ends

          IWebWizardHost struct
            lpVtbl POINTER ?
          IWebWizardHost ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IWebWizardHost2_INTERFACE_DEFINED__
        __IWebWizardHost2_INTERFACE_DEFINED__ equ <>
        externdef IID_IWebWizardHost2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebWizardHost2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebWizardHost2Vtbl>
            STD_METHOD QueryInterface, :ptr IWebWizardHost2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IWebWizardHost2
            STD_METHOD Release, :ptr IWebWizardHost2
            STD_METHOD GetTypeInfoCount, :ptr IWebWizardHost2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IWebWizardHost2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IWebWizardHost2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IWebWizardHost2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD FinalBack, :ptr IWebWizardHost2
            STD_METHOD FinalNext, :ptr IWebWizardHost2
            STD_METHOD Cancel, :ptr IWebWizardHost2
            STD_METHOD put_Caption, :ptr IWebWizardHost2, :BSTR
            STD_METHOD get_Caption, :ptr IWebWizardHost2, :ptr BSTR
            STD_METHOD put_Property, :ptr IWebWizardHost2, :BSTR, :ptr VARIANT
            STD_METHOD get_Property, :ptr IWebWizardHost2, :BSTR, :ptr VARIANT
            STD_METHOD SetWizardButtons, :ptr IWebWizardHost2, :VARIANT_BOOL, :VARIANT_BOOL, :VARIANT_BOOL
            STD_METHOD SetHeaderText, :ptr IWebWizardHost2, :BSTR, :BSTR
            STD_METHOD SignString, :ptr IWebWizardHost2, :BSTR, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IWebWizardHost2Vtbl ends

          IWebWizardHost2 struct
            lpVtbl POINTER ?
          IWebWizardHost2 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __INewWDEvents_INTERFACE_DEFINED__
        __INewWDEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_INewWDEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INewWDEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INewWDEventsVtbl>
            STD_METHOD QueryInterface, :ptr INewWDEvents, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr INewWDEvents
            STD_METHOD Release, :ptr INewWDEvents
            STD_METHOD GetTypeInfoCount, :ptr INewWDEvents, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr INewWDEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr INewWDEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr INewWDEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD FinalBack, :ptr INewWDEvents
            STD_METHOD FinalNext, :ptr INewWDEvents
            STD_METHOD Cancel, :ptr INewWDEvents
            STD_METHOD put_Caption, :ptr INewWDEvents, :BSTR
            STD_METHOD get_Caption, :ptr INewWDEvents, :ptr BSTR
            STD_METHOD put_Property, :ptr INewWDEvents, :BSTR, :ptr VARIANT
            STD_METHOD get_Property, :ptr INewWDEvents, :BSTR, :ptr VARIANT
            STD_METHOD SetWizardButtons, :ptr INewWDEvents, :VARIANT_BOOL, :VARIANT_BOOL, :VARIANT_BOOL
            STD_METHOD SetHeaderText, :ptr INewWDEvents, :BSTR, :BSTR
            STD_METHOD PassportAuthenticate, :ptr INewWDEvents, :BSTR, :ptr VARIANT_BOOL
            ??Interface equ <>
            END_INTERFACE
          INewWDEventsVtbl ends

          INewWDEvents struct
            lpVtbl POINTER ?
          INewWDEvents ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    externdef __MIDL_itf_shldisp_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shldisp_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IAutoComplete_INTERFACE_DEFINED__
      __IAutoComplete_INTERFACE_DEFINED__ equ <>
      LPAUTOCOMPLETE typedef ptr IAutoComplete
      externdef IID_IAutoComplete:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAutoCompleteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAutoCompleteVtbl>
          STD_METHOD QueryInterface, :ptr IAutoComplete, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IAutoComplete
          STD_METHOD Release, :ptr IAutoComplete
          STD_METHOD Init, :ptr IAutoComplete, :HWND, :ptr IUnknown, :LPCWSTR, :LPCWSTR
          STD_METHOD Enable, :ptr IAutoComplete, :BOOL
          ??Interface equ <>
          END_INTERFACE
        IAutoCompleteVtbl ends

        IAutoComplete struct
          lpVtbl POINTER ?
        IAutoComplete ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IAutoComplete2_INTERFACE_DEFINED__
      __IAutoComplete2_INTERFACE_DEFINED__ equ <>
      LPAUTOCOMPLETE2 typedef ptr IAutoComplete2
      AUTOCOMPLETEOPTIONS typedef SDWORD
      ACO_NONE equ 0
      ACO_AUTOSUGGEST equ 1h
      ACO_AUTOAPPEND equ 2h
      ACO_SEARCH equ 4h
      ACO_FILTERPREFIXES equ 8h
      ACO_USETAB equ 10h
      ACO_UPDOWNKEYDROPSLIST equ 20h
      ACO_RTLREADING equ 40h
      ACO_WORD_FILTER equ 80h
      ACO_NOPREFIXFILTERING equ 100h
      _tagAUTOCOMPLETEOPTIONS typedef AUTOCOMPLETEOPTIONS
      
      externdef IID_IAutoComplete2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAutoComplete2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAutoComplete2Vtbl>
          STD_METHOD QueryInterface, :ptr IAutoComplete2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IAutoComplete2
          STD_METHOD Release, :ptr IAutoComplete2
          STD_METHOD Init, :ptr IAutoComplete2, :HWND, :ptr IUnknown, :LPCWSTR, :LPCWSTR
          STD_METHOD Enable, :ptr IAutoComplete2, :BOOL
          STD_METHOD SetOptions, :ptr IAutoComplete2, :DWORD
          STD_METHOD GetOptions, :ptr IAutoComplete2, :ptr DWORD
          ??Interface equ <>
          END_INTERFACE
        IAutoComplete2Vtbl ends

        IAutoComplete2 struct
          lpVtbl POINTER ?
        IAutoComplete2 ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    externdef __MIDL_itf_shldisp_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shldisp_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumACString_INTERFACE_DEFINED__
      __IEnumACString_INTERFACE_DEFINED__ equ <>
      PENUMACSTRING typedef ptr IEnumACString
      LPENUMACSTRING typedef ptr IEnumACString
      ACENUMOPTION typedef SDWORD
      ACEO_NONE equ 0
      ACEO_MOSTRECENTFIRST equ 1h
      ACEO_FIRSTUNUSED equ 10000h
      _tagACENUMOPTION typedef ACENUMOPTION
      
      externdef IID_IEnumACString:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumACStringVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumACStringVtbl>
          STD_METHOD QueryInterface, :ptr IEnumACString, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumACString
          STD_METHOD Release, :ptr IEnumACString
          STD_METHOD Next, :ptr IEnumACString, :ULONG, :ptr LPOLESTR, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumACString, :ULONG
          STD_METHOD Reset, :ptr IEnumACString
          STD_METHOD Clone, :ptr IEnumACString, :ptr ptr IEnumString
          STD_METHOD NextItem, :ptr IEnumACString, :LPWSTR, :ULONG, :ptr ULONG
          STD_METHOD SetEnumOptions, :ptr IEnumACString, :DWORD
          STD_METHOD GetEnumOptions, :ptr IEnumACString, :ptr DWORD
          ??Interface equ <>
          END_INTERFACE
        IEnumACStringVtbl ends

        IEnumACString struct
          lpVtbl POINTER ?
        IEnumACString ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDataObjectAsyncCapability_INTERFACE_DEFINED__
      __IDataObjectAsyncCapability_INTERFACE_DEFINED__ equ <>
      externdef IID_IDataObjectAsyncCapability:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDataObjectAsyncCapabilityVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDataObjectAsyncCapabilityVtbl>
          STD_METHOD QueryInterface, :ptr IDataObjectAsyncCapability, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDataObjectAsyncCapability
          STD_METHOD Release, :ptr IDataObjectAsyncCapability
          STD_METHOD SetAsyncMode, :ptr IDataObjectAsyncCapability, :BOOL
          STD_METHOD GetAsyncMode, :ptr IDataObjectAsyncCapability, :ptr BOOL
          STD_METHOD StartOperation, :ptr IDataObjectAsyncCapability, :ptr IBindCtx
          STD_METHOD InOperation, :ptr IDataObjectAsyncCapability, :ptr BOOL
          STD_METHOD EndOperation, :ptr IDataObjectAsyncCapability, :HRESULT, :ptr IBindCtx, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IDataObjectAsyncCapabilityVtbl ends

        IDataObjectAsyncCapability struct
          lpVtbl POINTER ?
        IDataObjectAsyncCapability ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  externdef __MIDL_itf_shldisp_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shldisp_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif

