;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shldisp.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:24:02

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
ifndef __shldisp_h__
  __shldisp_h__ equ <>
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
  ifndef __IFolderViewOC_FWD_DEFINED__
    __IFolderViewOC_FWD_DEFINED__ equ <>
    ;* __IFolderViewOC_FWD_DEFINED__ *
  endif
  ifndef __DShellFolderViewEvents_FWD_DEFINED__
    __DShellFolderViewEvents_FWD_DEFINED__ equ <>
    ;* __DShellFolderViewEvents_FWD_DEFINED__ *
  endif
  ifndef __ShellFolderViewOC_FWD_DEFINED__
    __ShellFolderViewOC_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellFolderViewOC_FWD_DEFINED__ *
  endif
  ifndef __DFConstraint_FWD_DEFINED__
    __DFConstraint_FWD_DEFINED__ equ <>
    ;* __DFConstraint_FWD_DEFINED__ *
  endif
  ifndef __FolderItem_FWD_DEFINED__
    __FolderItem_FWD_DEFINED__ equ <>
    ;* __FolderItem_FWD_DEFINED__ *
  endif
  ifndef __FolderItems_FWD_DEFINED__
    __FolderItems_FWD_DEFINED__ equ <>
    ;* __FolderItems_FWD_DEFINED__ *
  endif
  ifndef __FolderItemVerb_FWD_DEFINED__
    __FolderItemVerb_FWD_DEFINED__ equ <>
    ;* __FolderItemVerb_FWD_DEFINED__ *
  endif
  ifndef __FolderItemVerbs_FWD_DEFINED__
    __FolderItemVerbs_FWD_DEFINED__ equ <>
    ;* __FolderItemVerbs_FWD_DEFINED__ *
  endif
  ifndef __Folder_FWD_DEFINED__
    __Folder_FWD_DEFINED__ equ <>
    ;* __Folder_FWD_DEFINED__ *
  endif
  ifndef __Folder2_FWD_DEFINED__
    __Folder2_FWD_DEFINED__ equ <>
    ;* __Folder2_FWD_DEFINED__ *
  endif
  ifndef __Folder3_FWD_DEFINED__
    __Folder3_FWD_DEFINED__ equ <>
    ;* __Folder3_FWD_DEFINED__ *
  endif
  ifndef __FolderItem2_FWD_DEFINED__
    __FolderItem2_FWD_DEFINED__ equ <>
    ;* __FolderItem2_FWD_DEFINED__ *
  endif
  ifndef __ShellFolderItem_FWD_DEFINED__
    __ShellFolderItem_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellFolderItem_FWD_DEFINED__ *
  endif
  ifndef __FolderItems2_FWD_DEFINED__
    __FolderItems2_FWD_DEFINED__ equ <>
    ;* __FolderItems2_FWD_DEFINED__ *
  endif
  ifndef __FolderItems3_FWD_DEFINED__
    __FolderItems3_FWD_DEFINED__ equ <>
    ;* __FolderItems3_FWD_DEFINED__ *
  endif
  ifndef __IShellLinkDual_FWD_DEFINED__
    __IShellLinkDual_FWD_DEFINED__ equ <>
    ;* __IShellLinkDual_FWD_DEFINED__ *
  endif
  ifndef __IShellLinkDual2_FWD_DEFINED__
    __IShellLinkDual2_FWD_DEFINED__ equ <>
    ;* __IShellLinkDual2_FWD_DEFINED__ *
  endif
  ifndef __ShellLinkObject_FWD_DEFINED__
    __ShellLinkObject_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellLinkObject_FWD_DEFINED__ *
  endif
  ifndef __IShellFolderViewDual_FWD_DEFINED__
    __IShellFolderViewDual_FWD_DEFINED__ equ <>
    ;* __IShellFolderViewDual_FWD_DEFINED__ *
  endif
  ifndef __IShellFolderViewDual2_FWD_DEFINED__
    __IShellFolderViewDual2_FWD_DEFINED__ equ <>
    ;* __IShellFolderViewDual2_FWD_DEFINED__ *
  endif
  ifndef __IShellFolderViewDual3_FWD_DEFINED__
    __IShellFolderViewDual3_FWD_DEFINED__ equ <>
    ;* __IShellFolderViewDual3_FWD_DEFINED__ *
  endif
  ifndef __ShellFolderView_FWD_DEFINED__
    __ShellFolderView_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellFolderView_FWD_DEFINED__ *
  endif
  ifndef __IShellDispatch_FWD_DEFINED__
    __IShellDispatch_FWD_DEFINED__ equ <>
    ;* __IShellDispatch_FWD_DEFINED__ *
  endif
  ifndef __IShellDispatch2_FWD_DEFINED__
    __IShellDispatch2_FWD_DEFINED__ equ <>
    ;* __IShellDispatch2_FWD_DEFINED__ *
  endif
  ifndef __IShellDispatch3_FWD_DEFINED__
    __IShellDispatch3_FWD_DEFINED__ equ <>
    ;* __IShellDispatch3_FWD_DEFINED__ *
  endif
  ifndef __IShellDispatch4_FWD_DEFINED__
    __IShellDispatch4_FWD_DEFINED__ equ <>
    ;* __IShellDispatch4_FWD_DEFINED__ *
  endif
  ifndef __IShellDispatch5_FWD_DEFINED__
    __IShellDispatch5_FWD_DEFINED__ equ <>
    ;* __IShellDispatch5_FWD_DEFINED__ *
  endif
  ifndef __IShellDispatch6_FWD_DEFINED__
    __IShellDispatch6_FWD_DEFINED__ equ <>
    ;* __IShellDispatch6_FWD_DEFINED__ *
  endif
  ifndef __Shell_FWD_DEFINED__
    __Shell_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __Shell_FWD_DEFINED__ *
  endif
  ifndef __ShellDispatchInproc_FWD_DEFINED__
    __ShellDispatchInproc_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellDispatchInproc_FWD_DEFINED__ *
  endif
  ifndef __IFileSearchBand_FWD_DEFINED__
    __IFileSearchBand_FWD_DEFINED__ equ <>
    ;* __IFileSearchBand_FWD_DEFINED__ *
  endif
  ifndef __FileSearchBand_FWD_DEFINED__
    __FileSearchBand_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __FileSearchBand_FWD_DEFINED__ *
  endif
  ifndef __IWebWizardHost_FWD_DEFINED__
    __IWebWizardHost_FWD_DEFINED__ equ <>
    ;* __IWebWizardHost_FWD_DEFINED__ *
  endif
  ifndef __IWebWizardHost2_FWD_DEFINED__
    __IWebWizardHost2_FWD_DEFINED__ equ <>
    ;* __IWebWizardHost2_FWD_DEFINED__ *
  endif
  ifndef __INewWDEvents_FWD_DEFINED__
    __INewWDEvents_FWD_DEFINED__ equ <>
    ;* __INewWDEvents_FWD_DEFINED__ *
  endif
  ifndef __IAutoComplete_FWD_DEFINED__
    __IAutoComplete_FWD_DEFINED__ equ <>
    ;* __IAutoComplete_FWD_DEFINED__ *
  endif
  ifndef __IAutoComplete2_FWD_DEFINED__
    __IAutoComplete2_FWD_DEFINED__ equ <>
    ;* __IAutoComplete2_FWD_DEFINED__ *
  endif
  ifndef __IEnumACString_FWD_DEFINED__
    __IEnumACString_FWD_DEFINED__ equ <>
    ;* __IEnumACString_FWD_DEFINED__ *
  endif
  ifndef __IDataObjectAsyncCapability_FWD_DEFINED__
    __IDataObjectAsyncCapability_FWD_DEFINED__ equ <>
    ;* __IDataObjectAsyncCapability_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_shldisp_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_shldisp_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shldisp_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __Shell32_LIBRARY_DEFINED__
      __Shell32_LIBRARY_DEFINED__ equ <>
      ;* library Shell32 *
      ;* [version][lcid][helpstring][uuid] *
      ;* [helpstring][uuid] *
      DECLSPEC_UUID("35f1a0d0-3e9a-11d2-8499-005345000000")
      OfflineFolderStatus typedef SDWORD
      OFS_INACTIVE equ -1
      OFS_ONLINE equ
      OFS_OFFLINE equ
      OFS_SERVERBACK equ
      OFS_DIRTYCACHE equ

      ;* [helpstring][uuid] *
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
      ; NTDDI_WIN8
      ;* [helpstring][uuid] *
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
        ;* interface IFolderViewOC *
        ;* [object][dual][oleautomation][hidden][helpcontext][helpstring][uuid] *
        externdef IID_IFolderViewOC:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFolderViewOCVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFolderViewOCVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IFolderViewOC, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFolderViewOC
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFolderViewOC
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IFolderViewOC, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IFolderViewOC, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IFolderViewOC, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IFolderViewOC, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IFolderViewOC, SetFolderView)
            ;* [helpcontext][helpstring] *
            STD_METHOD SetFolderView, :ptr IFolderViewOC, :ptr IDispatch
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IFolderViewOCVtbl ends
          IFolderViewOC struct
            lpVtbl POINTER ?
          IFolderViewOC ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IFolderViewOC_INTERFACE_DEFINED__ *
      endif
      ifndef __DShellFolderViewEvents_DISPINTERFACE_DEFINED__
        __DShellFolderViewEvents_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface DShellFolderViewEvents *
        ;* [helpstring][uuid] *
        externdef DIID_DShellFolderViewEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DShellFolderViewEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DShellFolderViewEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr DShellFolderViewEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr DShellFolderViewEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr DShellFolderViewEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr DShellFolderViewEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr DShellFolderViewEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr DShellFolderViewEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __DShellFolderViewEvents_DISPINTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellFolderViewOC:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __DFConstraint_INTERFACE_DEFINED__
        __DFConstraint_INTERFACE_DEFINED__ equ <>
        ;* interface DFConstraint *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_DFConstraint:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DFConstraintVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DFConstraintVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr DFConstraint, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr DFConstraint
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr DFConstraint
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr DFConstraint, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr DFConstraint, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr DFConstraint, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr DFConstraint, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(DFConstraint, get_Name)
            ;* [helpstring][propget] *
            STD_METHOD get_Name, :ptr DFConstraint, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(DFConstraint, get_Value)
            ;* [helpstring][propget] *
            STD_METHOD get_Value, :ptr DFConstraint, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          DFConstraintVtbl ends
          DFConstraint struct
            lpVtbl POINTER ?
          DFConstraint ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __DFConstraint_INTERFACE_DEFINED__ *
      endif
      ifndef __FolderItem_INTERFACE_DEFINED__
        __FolderItem_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItem *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        ;* [unique] *
        LPFOLDERITEM typedef ptr FolderItem
        externdef IID_FolderItem:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItem, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItem
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItem
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItem, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItem, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItem, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItem, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItem, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItem, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItem, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_Name)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Name, :ptr FolderItem, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, put_Name)
            ;* [helpstring][propput][id] *
            STD_METHOD put_Name, :ptr FolderItem, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(FolderItem, get_Path)
            ;* [helpstring][propget] *
            STD_METHOD get_Path, :ptr FolderItem, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_GetLink)
            ;* [helpstring][propget] *
            STD_METHOD get_GetLink, :ptr FolderItem, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_GetFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_GetFolder, :ptr FolderItem, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsLink)
            ;* [helpstring][propget] *
            STD_METHOD get_IsLink, :ptr FolderItem, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_IsFolder, :ptr FolderItem, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsFileSystem)
            ;* [helpstring][propget] *
            STD_METHOD get_IsFileSystem, :ptr FolderItem, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsBrowsable)
            ;* [helpstring][propget] *
            STD_METHOD get_IsBrowsable, :ptr FolderItem, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_ModifyDate)
            ;* [helpstring][propget] *
            STD_METHOD get_ModifyDate, :ptr FolderItem, :ptr DATE
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, put_ModifyDate)
            ;* [helpstring][propput] *
            STD_METHOD put_ModifyDate, :ptr FolderItem, :DATE
            ;* [in] *
            DECLSPEC_XFGVIRT(FolderItem, get_Size)
            ;* [helpstring][propget] *
            STD_METHOD get_Size, :ptr FolderItem, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_Type)
            ;* [helpstring][propget] *
            STD_METHOD get_Type, :ptr FolderItem, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, Verbs)
            ;* [helpstring] *
            STD_METHOD Verbs, :ptr FolderItem, :ptr ptr FolderItemVerbs
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, InvokeVerb)
            ;* [helpstring] *
            STD_METHOD InvokeVerb, :ptr FolderItem, :VARIANT
            ;* [optional][in] *
            ??Interface equ <>
            END_INTERFACE
          FolderItemVtbl ends
          FolderItem struct
            lpVtbl POINTER ?
          FolderItem ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __FolderItem_INTERFACE_DEFINED__ *
      endif
      ifndef __FolderItems_INTERFACE_DEFINED__
        __FolderItems_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItems *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_FolderItems:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItems, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItems
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItems
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItems, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItems, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItems, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItems, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItems, get_Count)
            ;* [helpstring][propget] *
            STD_METHOD get_Count, :ptr FolderItems, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItems, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItems, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, Item)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD Item, :ptr FolderItems, :VARIANT, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, _NewEnum)
            ;* [helpstring][id] *
            STD_METHOD _NewEnum, :ptr FolderItems, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          FolderItemsVtbl ends
          FolderItems struct
            lpVtbl POINTER ?
          FolderItems ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __FolderItems_INTERFACE_DEFINED__ *
      endif
      ifndef __FolderItemVerb_INTERFACE_DEFINED__
        __FolderItemVerb_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItemVerb *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_FolderItemVerb:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemVerbVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemVerbVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItemVerb, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItemVerb
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItemVerb
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItemVerb, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItemVerb, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItemVerb, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItemVerb, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItemVerb, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItemVerb, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerb, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItemVerb, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerb, get_Name)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Name, :ptr FolderItemVerb, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerb, DoIt)
            ;* [helpstring] *
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
          ;* C style interface *
        endif
        ;* __FolderItemVerb_INTERFACE_DEFINED__ *
      endif
      ifndef __FolderItemVerbs_INTERFACE_DEFINED__
        __FolderItemVerbs_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItemVerbs *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_FolderItemVerbs:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItemVerbsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItemVerbsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItemVerbs, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItemVerbs
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItemVerbs
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItemVerbs, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItemVerbs, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItemVerbs, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItemVerbs, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItemVerbs, get_Count)
            ;* [helpstring][propget] *
            STD_METHOD get_Count, :ptr FolderItemVerbs, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerbs, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItemVerbs, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerbs, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItemVerbs, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerbs, Item)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD Item, :ptr FolderItemVerbs, :VARIANT, :ptr ptr FolderItemVerb
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItemVerbs, _NewEnum)
            ;* [helpstring][id] *
            STD_METHOD _NewEnum, :ptr FolderItemVerbs, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          FolderItemVerbsVtbl ends
          FolderItemVerbs struct
            lpVtbl POINTER ?
          FolderItemVerbs ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __FolderItemVerbs_INTERFACE_DEFINED__ *
      endif
      ifndef __Folder_INTERFACE_DEFINED__
        __Folder_INTERFACE_DEFINED__ equ <>
        ;* interface Folder *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_Folder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr Folder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr Folder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr Folder
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr Folder, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr Folder, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr Folder, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr Folder, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(Folder, get_Title)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Title, :ptr Folder, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr Folder, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr Folder, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_ParentFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_ParentFolder, :ptr Folder, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, Items)
            ;* [helpstring] *
            STD_METHOD Items, :ptr Folder, :ptr ptr FolderItems
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, ParseName)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ParseName, :ptr Folder, :BSTR, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, NewFolder)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NewFolder, :ptr Folder, :BSTR, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, MoveHere)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD MoveHere, :ptr Folder, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, CopyHere)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CopyHere, :ptr Folder, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, GetDetailsOf)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetDetailsOf, :ptr Folder, :VARIANT, :SDWORD, :ptr BSTR
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          FolderVtbl ends
          Folder struct
            lpVtbl POINTER ?
          Folder ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __Folder_INTERFACE_DEFINED__ *
      endif
      ifndef __Folder2_INTERFACE_DEFINED__
        __Folder2_INTERFACE_DEFINED__ equ <>
        ;* interface Folder2 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_Folder2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          Folder2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <Folder2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr Folder2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr Folder2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr Folder2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr Folder2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr Folder2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr Folder2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr Folder2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(Folder, get_Title)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Title, :ptr Folder2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr Folder2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr Folder2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_ParentFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_ParentFolder, :ptr Folder2, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, Items)
            ;* [helpstring] *
            STD_METHOD Items, :ptr Folder2, :ptr ptr FolderItems
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, ParseName)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ParseName, :ptr Folder2, :BSTR, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, NewFolder)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NewFolder, :ptr Folder2, :BSTR, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, MoveHere)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD MoveHere, :ptr Folder2, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, CopyHere)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CopyHere, :ptr Folder2, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, GetDetailsOf)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetDetailsOf, :ptr Folder2, :VARIANT, :SDWORD, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, get_Self)
            ;* [helpstring][propget] *
            STD_METHOD get_Self, :ptr Folder2, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, get_OfflineStatus)
            ;* [helpstring][propget] *
            STD_METHOD get_OfflineStatus, :ptr Folder2, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, Synchronize)
            ;* [helpstring] *
            STD_METHOD Synchronize, :ptr Folder2
            DECLSPEC_XFGVIRT(Folder2, get_HaveToShowWebViewBarricade)
            ;* [helpstring][propget][id] *
            STD_METHOD get_HaveToShowWebViewBarricade, :ptr Folder2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, DismissedWebViewBarricade)
            ;* [helpstring] *
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
          ;* C style interface *
        endif
        ;* __Folder2_INTERFACE_DEFINED__ *
      endif
      ifndef __Folder3_INTERFACE_DEFINED__
        __Folder3_INTERFACE_DEFINED__ equ <>
        ;* interface Folder3 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_Folder3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          Folder3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <Folder3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr Folder3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr Folder3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr Folder3
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr Folder3, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr Folder3, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr Folder3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr Folder3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(Folder, get_Title)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Title, :ptr Folder3, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr Folder3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr Folder3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, get_ParentFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_ParentFolder, :ptr Folder3, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, Items)
            ;* [helpstring] *
            STD_METHOD Items, :ptr Folder3, :ptr ptr FolderItems
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, ParseName)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ParseName, :ptr Folder3, :BSTR, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder, NewFolder)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NewFolder, :ptr Folder3, :BSTR, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, MoveHere)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD MoveHere, :ptr Folder3, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, CopyHere)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CopyHere, :ptr Folder3, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(Folder, GetDetailsOf)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetDetailsOf, :ptr Folder3, :VARIANT, :SDWORD, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, get_Self)
            ;* [helpstring][propget] *
            STD_METHOD get_Self, :ptr Folder3, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, get_OfflineStatus)
            ;* [helpstring][propget] *
            STD_METHOD get_OfflineStatus, :ptr Folder3, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, Synchronize)
            ;* [helpstring] *
            STD_METHOD Synchronize, :ptr Folder3
            DECLSPEC_XFGVIRT(Folder2, get_HaveToShowWebViewBarricade)
            ;* [helpstring][propget][id] *
            STD_METHOD get_HaveToShowWebViewBarricade, :ptr Folder3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder2, DismissedWebViewBarricade)
            ;* [helpstring] *
            STD_METHOD DismissedWebViewBarricade, :ptr Folder3
            DECLSPEC_XFGVIRT(Folder3, get_ShowWebViewBarricade)
            ;* [helpstring][propget][id] *
            STD_METHOD get_ShowWebViewBarricade, :ptr Folder3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(Folder3, put_ShowWebViewBarricade)
            ;* [helpstring][propput][id] *
            STD_METHOD put_ShowWebViewBarricade, :ptr Folder3, :VARIANT_BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          Folder3Vtbl ends
          Folder3 struct
            lpVtbl POINTER ?
          Folder3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __Folder3_INTERFACE_DEFINED__ *
      endif
      ifndef __FolderItem2_INTERFACE_DEFINED__
        __FolderItem2_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItem2 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_FolderItem2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItem2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItem2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItem2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItem2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItem2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItem2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItem2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItem2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItem2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItem, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItem2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItem2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_Name)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Name, :ptr FolderItem2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, put_Name)
            ;* [helpstring][propput][id] *
            STD_METHOD put_Name, :ptr FolderItem2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(FolderItem, get_Path)
            ;* [helpstring][propget] *
            STD_METHOD get_Path, :ptr FolderItem2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_GetLink)
            ;* [helpstring][propget] *
            STD_METHOD get_GetLink, :ptr FolderItem2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_GetFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_GetFolder, :ptr FolderItem2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsLink)
            ;* [helpstring][propget] *
            STD_METHOD get_IsLink, :ptr FolderItem2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsFolder)
            ;* [helpstring][propget] *
            STD_METHOD get_IsFolder, :ptr FolderItem2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsFileSystem)
            ;* [helpstring][propget] *
            STD_METHOD get_IsFileSystem, :ptr FolderItem2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_IsBrowsable)
            ;* [helpstring][propget] *
            STD_METHOD get_IsBrowsable, :ptr FolderItem2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_ModifyDate)
            ;* [helpstring][propget] *
            STD_METHOD get_ModifyDate, :ptr FolderItem2, :ptr DATE
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, put_ModifyDate)
            ;* [helpstring][propput] *
            STD_METHOD put_ModifyDate, :ptr FolderItem2, :DATE
            ;* [in] *
            DECLSPEC_XFGVIRT(FolderItem, get_Size)
            ;* [helpstring][propget] *
            STD_METHOD get_Size, :ptr FolderItem2, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, get_Type)
            ;* [helpstring][propget] *
            STD_METHOD get_Type, :ptr FolderItem2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, Verbs)
            ;* [helpstring] *
            STD_METHOD Verbs, :ptr FolderItem2, :ptr ptr FolderItemVerbs
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItem, InvokeVerb)
            ;* [helpstring] *
            STD_METHOD InvokeVerb, :ptr FolderItem2, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(FolderItem2, InvokeVerbEx)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD InvokeVerbEx, :ptr FolderItem2, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(FolderItem2, ExtendedProperty)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ExtendedProperty, :ptr FolderItem2, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          FolderItem2Vtbl ends
          FolderItem2 struct
            lpVtbl POINTER ?
          FolderItem2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __FolderItem2_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellFolderItem:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __FolderItems2_INTERFACE_DEFINED__
        __FolderItems2_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItems2 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_FolderItems2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItems2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItems2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItems2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItems2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItems2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItems2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItems2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItems2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItems2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItems, get_Count)
            ;* [helpstring][propget] *
            STD_METHOD get_Count, :ptr FolderItems2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItems2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItems2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, Item)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD Item, :ptr FolderItems2, :VARIANT, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, _NewEnum)
            ;* [helpstring][id] *
            STD_METHOD _NewEnum, :ptr FolderItems2, :ptr ptr IUnknown
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems2, InvokeVerbEx)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD InvokeVerbEx, :ptr FolderItems2, :VARIANT, :VARIANT
            ;* [optional][in] *
            ??Interface equ <>
            END_INTERFACE
          FolderItems2Vtbl ends
          FolderItems2 struct
            lpVtbl POINTER ?
          FolderItems2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __FolderItems2_INTERFACE_DEFINED__ *
      endif
      ifndef __FolderItems3_INTERFACE_DEFINED__
        __FolderItems3_INTERFACE_DEFINED__ equ <>
        ;* interface FolderItems3 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_FolderItems3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          FolderItems3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <FolderItems3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr FolderItems3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr FolderItems3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr FolderItems3
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr FolderItems3, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr FolderItems3, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr FolderItems3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr FolderItems3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(FolderItems, get_Count)
            ;* [helpstring][propget] *
            STD_METHOD get_Count, :ptr FolderItems3, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr FolderItems3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr FolderItems3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, Item)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD Item, :ptr FolderItems3, :VARIANT, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems, _NewEnum)
            ;* [helpstring][id] *
            STD_METHOD _NewEnum, :ptr FolderItems3, :ptr ptr IUnknown
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(FolderItems2, InvokeVerbEx)
            ;* [helpstring] *
            ;* [optional][in] *
            STD_METHOD InvokeVerbEx, :ptr FolderItems3, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(FolderItems3, Filter)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD Filter, :ptr FolderItems3, :SDWORD, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(FolderItems3, get_Verbs)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Verbs, :ptr FolderItems3, :ptr ptr FolderItemVerbs
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          FolderItems3Vtbl ends
          FolderItems3 struct
            lpVtbl POINTER ?
          FolderItems3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __FolderItems3_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellLinkDual_INTERFACE_DEFINED__
        __IShellLinkDual_INTERFACE_DEFINED__ equ <>
        ;* interface IShellLinkDual *
        ;* [object][hidden][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellLinkDual:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellLinkDualVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellLinkDualVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellLinkDual, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellLinkDual
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellLinkDual
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellLinkDual, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellLinkDual, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellLinkDual, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellLinkDual, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Path)
            ;* [helpstring][propget] *
            STD_METHOD get_Path, :ptr IShellLinkDual, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Path)
            ;* [helpstring][propput] *
            STD_METHOD put_Path, :ptr IShellLinkDual, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Description)
            ;* [helpstring][propget] *
            STD_METHOD get_Description, :ptr IShellLinkDual, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Description)
            ;* [helpstring][propput] *
            STD_METHOD put_Description, :ptr IShellLinkDual, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_WorkingDirectory)
            ;* [helpstring][propget] *
            STD_METHOD get_WorkingDirectory, :ptr IShellLinkDual, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_WorkingDirectory)
            ;* [helpstring][propput] *
            STD_METHOD put_WorkingDirectory, :ptr IShellLinkDual, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Arguments)
            ;* [helpstring][propget] *
            STD_METHOD get_Arguments, :ptr IShellLinkDual, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Arguments)
            ;* [helpstring][propput] *
            STD_METHOD put_Arguments, :ptr IShellLinkDual, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Hotkey)
            ;* [helpstring][propget] *
            STD_METHOD get_Hotkey, :ptr IShellLinkDual, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Hotkey)
            ;* [helpstring][propput] *
            STD_METHOD put_Hotkey, :ptr IShellLinkDual, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_ShowCommand)
            ;* [helpstring][propget] *
            STD_METHOD get_ShowCommand, :ptr IShellLinkDual, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_ShowCommand)
            ;* [helpstring][propput] *
            STD_METHOD put_ShowCommand, :ptr IShellLinkDual, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, Resolve)
            ;* [helpstring] *
            STD_METHOD Resolve, :ptr IShellLinkDual, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, GetIconLocation)
            ;* [helpstring] *
            ;* [out] *
            STD_METHOD GetIconLocation, :ptr IShellLinkDual, :ptr BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, SetIconLocation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD SetIconLocation, :ptr IShellLinkDual, :BSTR, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, Save)
            ;* [helpstring] *
            STD_METHOD Save, :ptr IShellLinkDual, :VARIANT
            ;* [optional][in] *
            ??Interface equ <>
            END_INTERFACE
          IShellLinkDualVtbl ends
          IShellLinkDual struct
            lpVtbl POINTER ?
          IShellLinkDual ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellLinkDual_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellLinkDual2_INTERFACE_DEFINED__
        __IShellLinkDual2_INTERFACE_DEFINED__ equ <>
        ;* interface IShellLinkDual2 *
        ;* [object][hidden][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellLinkDual2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellLinkDual2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellLinkDual2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellLinkDual2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellLinkDual2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellLinkDual2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellLinkDual2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellLinkDual2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellLinkDual2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellLinkDual2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Path)
            ;* [helpstring][propget] *
            STD_METHOD get_Path, :ptr IShellLinkDual2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Path)
            ;* [helpstring][propput] *
            STD_METHOD put_Path, :ptr IShellLinkDual2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Description)
            ;* [helpstring][propget] *
            STD_METHOD get_Description, :ptr IShellLinkDual2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Description)
            ;* [helpstring][propput] *
            STD_METHOD put_Description, :ptr IShellLinkDual2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_WorkingDirectory)
            ;* [helpstring][propget] *
            STD_METHOD get_WorkingDirectory, :ptr IShellLinkDual2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_WorkingDirectory)
            ;* [helpstring][propput] *
            STD_METHOD put_WorkingDirectory, :ptr IShellLinkDual2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Arguments)
            ;* [helpstring][propget] *
            STD_METHOD get_Arguments, :ptr IShellLinkDual2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Arguments)
            ;* [helpstring][propput] *
            STD_METHOD put_Arguments, :ptr IShellLinkDual2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_Hotkey)
            ;* [helpstring][propget] *
            STD_METHOD get_Hotkey, :ptr IShellLinkDual2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_Hotkey)
            ;* [helpstring][propput] *
            STD_METHOD put_Hotkey, :ptr IShellLinkDual2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, get_ShowCommand)
            ;* [helpstring][propget] *
            STD_METHOD get_ShowCommand, :ptr IShellLinkDual2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, put_ShowCommand)
            ;* [helpstring][propput] *
            STD_METHOD put_ShowCommand, :ptr IShellLinkDual2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, Resolve)
            ;* [helpstring] *
            STD_METHOD Resolve, :ptr IShellLinkDual2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, GetIconLocation)
            ;* [helpstring] *
            ;* [out] *
            STD_METHOD GetIconLocation, :ptr IShellLinkDual2, :ptr BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellLinkDual, SetIconLocation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD SetIconLocation, :ptr IShellLinkDual2, :BSTR, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellLinkDual, Save)
            ;* [helpstring] *
            STD_METHOD Save, :ptr IShellLinkDual2, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellLinkDual2, get_Target)
            ;* [helpstring][propget] *
            STD_METHOD get_Target, :ptr IShellLinkDual2, :ptr ptr FolderItem
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellLinkDual2Vtbl ends
          IShellLinkDual2 struct
            lpVtbl POINTER ?
          IShellLinkDual2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellLinkDual2_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellLinkObject:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IShellFolderViewDual_INTERFACE_DEFINED__
        __IShellFolderViewDual_INTERFACE_DEFINED__ equ <>
        ;* interface IShellFolderViewDual *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellFolderViewDual:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFolderViewDualVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFolderViewDualVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellFolderViewDual, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellFolderViewDual
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellFolderViewDual
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellFolderViewDual, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellFolderViewDual, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellFolderViewDual, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellFolderViewDual, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellFolderViewDual, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellFolderViewDual, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Folder)
            ;* [helpstring][propget] *
            STD_METHOD get_Folder, :ptr IShellFolderViewDual, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, SelectedItems)
            ;* [helpstring] *
            STD_METHOD SelectedItems, :ptr IShellFolderViewDual, :ptr ptr FolderItems
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_FocusedItem)
            ;* [helpstring][propget] *
            STD_METHOD get_FocusedItem, :ptr IShellFolderViewDual, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, SelectItem)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD SelectItem, :ptr IShellFolderViewDual, :ptr VARIANT, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, PopupItemMenu)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD PopupItemMenu, :ptr IShellFolderViewDual, :ptr FolderItem, :VARIANT, :VARIANT, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Script)
            ;* [helpcontext][helpstring][propget] *
            STD_METHOD get_Script, :ptr IShellFolderViewDual, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_ViewOptions)
            ;* [helpcontext][helpstring][propget] *
            STD_METHOD get_ViewOptions, :ptr IShellFolderViewDual, :ptr SDWORD
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellFolderViewDualVtbl ends
          IShellFolderViewDual struct
            lpVtbl POINTER ?
          IShellFolderViewDual ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellFolderViewDual_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellFolderViewDual2_INTERFACE_DEFINED__
        __IShellFolderViewDual2_INTERFACE_DEFINED__ equ <>
        ;* interface IShellFolderViewDual2 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellFolderViewDual2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFolderViewDual2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFolderViewDual2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellFolderViewDual2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellFolderViewDual2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellFolderViewDual2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellFolderViewDual2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellFolderViewDual2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellFolderViewDual2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellFolderViewDual2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellFolderViewDual2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellFolderViewDual2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Folder)
            ;* [helpstring][propget] *
            STD_METHOD get_Folder, :ptr IShellFolderViewDual2, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, SelectedItems)
            ;* [helpstring] *
            STD_METHOD SelectedItems, :ptr IShellFolderViewDual2, :ptr ptr FolderItems
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_FocusedItem)
            ;* [helpstring][propget] *
            STD_METHOD get_FocusedItem, :ptr IShellFolderViewDual2, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, SelectItem)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD SelectItem, :ptr IShellFolderViewDual2, :ptr VARIANT, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, PopupItemMenu)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD PopupItemMenu, :ptr IShellFolderViewDual2, :ptr FolderItem, :VARIANT, :VARIANT, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Script)
            ;* [helpcontext][helpstring][propget] *
            STD_METHOD get_Script, :ptr IShellFolderViewDual2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_ViewOptions)
            ;* [helpcontext][helpstring][propget] *
            STD_METHOD get_ViewOptions, :ptr IShellFolderViewDual2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual2, get_CurrentViewMode)
            ;* [helpstring][propget] *
            STD_METHOD get_CurrentViewMode, :ptr IShellFolderViewDual2, :ptr UINT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual2, put_CurrentViewMode)
            ;* [helpstring][propput] *
            STD_METHOD put_CurrentViewMode, :ptr IShellFolderViewDual2, :UINT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual2, SelectItemRelative)
            ;* [helpstring] *
            STD_METHOD SelectItemRelative, :ptr IShellFolderViewDual2, :SDWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellFolderViewDual2Vtbl ends
          IShellFolderViewDual2 struct
            lpVtbl POINTER ?
          IShellFolderViewDual2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellFolderViewDual2_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellFolderViewDual3_INTERFACE_DEFINED__
        __IShellFolderViewDual3_INTERFACE_DEFINED__ equ <>
        ;* interface IShellFolderViewDual3 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellFolderViewDual3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFolderViewDual3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFolderViewDual3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellFolderViewDual3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellFolderViewDual3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellFolderViewDual3
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellFolderViewDual3, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellFolderViewDual3, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellFolderViewDual3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellFolderViewDual3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellFolderViewDual3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellFolderViewDual3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Folder)
            ;* [helpstring][propget] *
            STD_METHOD get_Folder, :ptr IShellFolderViewDual3, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, SelectedItems)
            ;* [helpstring] *
            STD_METHOD SelectedItems, :ptr IShellFolderViewDual3, :ptr ptr FolderItems
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_FocusedItem)
            ;* [helpstring][propget] *
            STD_METHOD get_FocusedItem, :ptr IShellFolderViewDual3, :ptr ptr FolderItem
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, SelectItem)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD SelectItem, :ptr IShellFolderViewDual3, :ptr VARIANT, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, PopupItemMenu)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD PopupItemMenu, :ptr IShellFolderViewDual3, :ptr FolderItem, :VARIANT, :VARIANT, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_Script)
            ;* [helpcontext][helpstring][propget] *
            STD_METHOD get_Script, :ptr IShellFolderViewDual3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual, get_ViewOptions)
            ;* [helpcontext][helpstring][propget] *
            STD_METHOD get_ViewOptions, :ptr IShellFolderViewDual3, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual2, get_CurrentViewMode)
            ;* [helpstring][propget] *
            STD_METHOD get_CurrentViewMode, :ptr IShellFolderViewDual3, :ptr UINT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual2, put_CurrentViewMode)
            ;* [helpstring][propput] *
            STD_METHOD put_CurrentViewMode, :ptr IShellFolderViewDual3, :UINT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual2, SelectItemRelative)
            ;* [helpstring] *
            STD_METHOD SelectItemRelative, :ptr IShellFolderViewDual3, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, get_GroupBy)
            ;* [helpstring][propget] *
            STD_METHOD get_GroupBy, :ptr IShellFolderViewDual3, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, put_GroupBy)
            ;* [helpstring][propput] *
            STD_METHOD put_GroupBy, :ptr IShellFolderViewDual3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, get_FolderFlags)
            ;* [helpstring][propget] *
            STD_METHOD get_FolderFlags, :ptr IShellFolderViewDual3, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, put_FolderFlags)
            ;* [helpstring][propput] *
            STD_METHOD put_FolderFlags, :ptr IShellFolderViewDual3, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, get_SortColumns)
            ;* [helpstring][propget] *
            STD_METHOD get_SortColumns, :ptr IShellFolderViewDual3, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, put_SortColumns)
            ;* [helpstring][propput] *
            STD_METHOD put_SortColumns, :ptr IShellFolderViewDual3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, put_IconSize)
            ;* [helpstring][propput] *
            STD_METHOD put_IconSize, :ptr IShellFolderViewDual3, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, get_IconSize)
            ;* [helpstring][propget] *
            STD_METHOD get_IconSize, :ptr IShellFolderViewDual3, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFolderViewDual3, FilterView)
            ;* [helpstring] *
            STD_METHOD FilterView, :ptr IShellFolderViewDual3, :BSTR
            ;* [unique][in] *
            ??Interface equ <>
            END_INTERFACE
          IShellFolderViewDual3Vtbl ends
          IShellFolderViewDual3 struct
            lpVtbl POINTER ?
          IShellFolderViewDual3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellFolderViewDual3_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellFolderView:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IShellDispatch_INTERFACE_DEFINED__
        __IShellDispatch_INTERFACE_DEFINED__ equ <>
        ;* interface IShellDispatch *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellDispatch:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatchVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatchVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellDispatch, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellDispatch, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellDispatch, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellDispatch, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellDispatch, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellDispatch, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, NameSpace)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NameSpace, :ptr IShellDispatch, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, BrowseForFolder)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD BrowseForFolder, :ptr IShellDispatch, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Windows)
            ;* [helpstring] *
            STD_METHOD Windows, :ptr IShellDispatch, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Open)
            ;* [helpstring] *
            STD_METHOD Open, :ptr IShellDispatch, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, Explore)
            ;* [helpstring] *
            STD_METHOD Explore, :ptr IShellDispatch, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, MinimizeAll)
            ;* [helpstring] *
            STD_METHOD MinimizeAll, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, UndoMinimizeALL)
            ;* [helpstring] *
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, FileRun)
            ;* [helpstring] *
            STD_METHOD FileRun, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, CascadeWindows)
            ;* [helpstring] *
            STD_METHOD CascadeWindows, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, TileVertically)
            ;* [helpstring] *
            STD_METHOD TileVertically, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, TileHorizontally)
            ;* [helpstring] *
            STD_METHOD TileHorizontally, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, ShutdownWindows)
            ;* [helpstring] *
            STD_METHOD ShutdownWindows, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, Suspend)
            ;* [helpstring] *
            STD_METHOD Suspend, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, EjectPC)
            ;* [helpstring] *
            STD_METHOD EjectPC, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, SetTime)
            ;* [helpstring] *
            STD_METHOD SetTime, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, TrayProperties)
            ;* [helpstring] *
            STD_METHOD TrayProperties, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, Help)
            ;* [helpstring] *
            STD_METHOD Help, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, FindFiles)
            ;* [helpstring] *
            STD_METHOD FindFiles, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, FindComputer)
            ;* [helpstring] *
            STD_METHOD FindComputer, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, RefreshMenu)
            ;* [helpstring] *
            STD_METHOD RefreshMenu, :ptr IShellDispatch
            DECLSPEC_XFGVIRT(IShellDispatch, ControlPanelItem)
            ;* [helpstring] *
            STD_METHOD ControlPanelItem, :ptr IShellDispatch, :BSTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellDispatchVtbl ends
          IShellDispatch struct
            lpVtbl POINTER ?
          IShellDispatch ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellDispatch_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellDispatch2_INTERFACE_DEFINED__
        __IShellDispatch2_INTERFACE_DEFINED__ equ <>
        ;* interface IShellDispatch2 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellDispatch2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellDispatch2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellDispatch2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellDispatch2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellDispatch, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellDispatch2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellDispatch2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, NameSpace)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NameSpace, :ptr IShellDispatch2, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, BrowseForFolder)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD BrowseForFolder, :ptr IShellDispatch2, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Windows)
            ;* [helpstring] *
            STD_METHOD Windows, :ptr IShellDispatch2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Open)
            ;* [helpstring] *
            STD_METHOD Open, :ptr IShellDispatch2, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, Explore)
            ;* [helpstring] *
            STD_METHOD Explore, :ptr IShellDispatch2, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, MinimizeAll)
            ;* [helpstring] *
            STD_METHOD MinimizeAll, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, UndoMinimizeALL)
            ;* [helpstring] *
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, FileRun)
            ;* [helpstring] *
            STD_METHOD FileRun, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, CascadeWindows)
            ;* [helpstring] *
            STD_METHOD CascadeWindows, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, TileVertically)
            ;* [helpstring] *
            STD_METHOD TileVertically, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, TileHorizontally)
            ;* [helpstring] *
            STD_METHOD TileHorizontally, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, ShutdownWindows)
            ;* [helpstring] *
            STD_METHOD ShutdownWindows, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, Suspend)
            ;* [helpstring] *
            STD_METHOD Suspend, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, EjectPC)
            ;* [helpstring] *
            STD_METHOD EjectPC, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, SetTime)
            ;* [helpstring] *
            STD_METHOD SetTime, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, TrayProperties)
            ;* [helpstring] *
            STD_METHOD TrayProperties, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, Help)
            ;* [helpstring] *
            STD_METHOD Help, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, FindFiles)
            ;* [helpstring] *
            STD_METHOD FindFiles, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, FindComputer)
            ;* [helpstring] *
            STD_METHOD FindComputer, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, RefreshMenu)
            ;* [helpstring] *
            STD_METHOD RefreshMenu, :ptr IShellDispatch2
            DECLSPEC_XFGVIRT(IShellDispatch, ControlPanelItem)
            ;* [helpstring] *
            STD_METHOD ControlPanelItem, :ptr IShellDispatch2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsRestricted)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsRestricted, :ptr IShellDispatch2, :BSTR, :BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShellExecute)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD ShellExecute, :ptr IShellDispatch2, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, FindPrinter)
            ;* [helpstring] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD FindPrinter, :ptr IShellDispatch2, :BSTR, :BSTR, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, GetSystemInformation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSystemInformation, :ptr IShellDispatch2, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStart)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStart, :ptr IShellDispatch2, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStop)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStop, :ptr IShellDispatch2, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsServiceRunning)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD IsServiceRunning, :ptr IShellDispatch2, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, CanStartStopService)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CanStartStopService, :ptr IShellDispatch2, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShowBrowserBar)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch2, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch2Vtbl ends
          IShellDispatch2 struct
            lpVtbl POINTER ?
          IShellDispatch2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellDispatch2_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellDispatch3_INTERFACE_DEFINED__
        __IShellDispatch3_INTERFACE_DEFINED__ equ <>
        ;* interface IShellDispatch3 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellDispatch3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellDispatch3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch3, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellDispatch3, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellDispatch3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellDispatch, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellDispatch3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellDispatch3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, NameSpace)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NameSpace, :ptr IShellDispatch3, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, BrowseForFolder)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD BrowseForFolder, :ptr IShellDispatch3, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Windows)
            ;* [helpstring] *
            STD_METHOD Windows, :ptr IShellDispatch3, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Open)
            ;* [helpstring] *
            STD_METHOD Open, :ptr IShellDispatch3, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, Explore)
            ;* [helpstring] *
            STD_METHOD Explore, :ptr IShellDispatch3, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, MinimizeAll)
            ;* [helpstring] *
            STD_METHOD MinimizeAll, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, UndoMinimizeALL)
            ;* [helpstring] *
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, FileRun)
            ;* [helpstring] *
            STD_METHOD FileRun, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, CascadeWindows)
            ;* [helpstring] *
            STD_METHOD CascadeWindows, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, TileVertically)
            ;* [helpstring] *
            STD_METHOD TileVertically, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, TileHorizontally)
            ;* [helpstring] *
            STD_METHOD TileHorizontally, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, ShutdownWindows)
            ;* [helpstring] *
            STD_METHOD ShutdownWindows, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, Suspend)
            ;* [helpstring] *
            STD_METHOD Suspend, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, EjectPC)
            ;* [helpstring] *
            STD_METHOD EjectPC, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, SetTime)
            ;* [helpstring] *
            STD_METHOD SetTime, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, TrayProperties)
            ;* [helpstring] *
            STD_METHOD TrayProperties, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, Help)
            ;* [helpstring] *
            STD_METHOD Help, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, FindFiles)
            ;* [helpstring] *
            STD_METHOD FindFiles, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, FindComputer)
            ;* [helpstring] *
            STD_METHOD FindComputer, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, RefreshMenu)
            ;* [helpstring] *
            STD_METHOD RefreshMenu, :ptr IShellDispatch3
            DECLSPEC_XFGVIRT(IShellDispatch, ControlPanelItem)
            ;* [helpstring] *
            STD_METHOD ControlPanelItem, :ptr IShellDispatch3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsRestricted)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsRestricted, :ptr IShellDispatch3, :BSTR, :BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShellExecute)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD ShellExecute, :ptr IShellDispatch3, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, FindPrinter)
            ;* [helpstring] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD FindPrinter, :ptr IShellDispatch3, :BSTR, :BSTR, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, GetSystemInformation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSystemInformation, :ptr IShellDispatch3, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStart)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStart, :ptr IShellDispatch3, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStop)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStop, :ptr IShellDispatch3, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsServiceRunning)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD IsServiceRunning, :ptr IShellDispatch3, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, CanStartStopService)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CanStartStopService, :ptr IShellDispatch3, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShowBrowserBar)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch3, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch3, AddToRecent)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD AddToRecent, :ptr IShellDispatch3, :VARIANT, :BSTR
            ;* [optional][in] *
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch3Vtbl ends
          IShellDispatch3 struct
            lpVtbl POINTER ?
          IShellDispatch3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellDispatch3_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellDispatch4_INTERFACE_DEFINED__
        __IShellDispatch4_INTERFACE_DEFINED__ equ <>
        ;* interface IShellDispatch4 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellDispatch4:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch4Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch4Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellDispatch4, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch4, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellDispatch4, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch4, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellDispatch4, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellDispatch, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellDispatch4, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellDispatch4, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, NameSpace)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NameSpace, :ptr IShellDispatch4, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, BrowseForFolder)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD BrowseForFolder, :ptr IShellDispatch4, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Windows)
            ;* [helpstring] *
            STD_METHOD Windows, :ptr IShellDispatch4, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Open)
            ;* [helpstring] *
            STD_METHOD Open, :ptr IShellDispatch4, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, Explore)
            ;* [helpstring] *
            STD_METHOD Explore, :ptr IShellDispatch4, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, MinimizeAll)
            ;* [helpstring] *
            STD_METHOD MinimizeAll, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, UndoMinimizeALL)
            ;* [helpstring] *
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, FileRun)
            ;* [helpstring] *
            STD_METHOD FileRun, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, CascadeWindows)
            ;* [helpstring] *
            STD_METHOD CascadeWindows, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, TileVertically)
            ;* [helpstring] *
            STD_METHOD TileVertically, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, TileHorizontally)
            ;* [helpstring] *
            STD_METHOD TileHorizontally, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, ShutdownWindows)
            ;* [helpstring] *
            STD_METHOD ShutdownWindows, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, Suspend)
            ;* [helpstring] *
            STD_METHOD Suspend, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, EjectPC)
            ;* [helpstring] *
            STD_METHOD EjectPC, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, SetTime)
            ;* [helpstring] *
            STD_METHOD SetTime, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, TrayProperties)
            ;* [helpstring] *
            STD_METHOD TrayProperties, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, Help)
            ;* [helpstring] *
            STD_METHOD Help, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, FindFiles)
            ;* [helpstring] *
            STD_METHOD FindFiles, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, FindComputer)
            ;* [helpstring] *
            STD_METHOD FindComputer, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, RefreshMenu)
            ;* [helpstring] *
            STD_METHOD RefreshMenu, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch, ControlPanelItem)
            ;* [helpstring] *
            STD_METHOD ControlPanelItem, :ptr IShellDispatch4, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsRestricted)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsRestricted, :ptr IShellDispatch4, :BSTR, :BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShellExecute)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD ShellExecute, :ptr IShellDispatch4, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, FindPrinter)
            ;* [helpstring] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD FindPrinter, :ptr IShellDispatch4, :BSTR, :BSTR, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, GetSystemInformation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSystemInformation, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStart)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStart, :ptr IShellDispatch4, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStop)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStop, :ptr IShellDispatch4, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsServiceRunning)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD IsServiceRunning, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, CanStartStopService)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CanStartStopService, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShowBrowserBar)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch4, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch3, AddToRecent)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD AddToRecent, :ptr IShellDispatch4, :VARIANT, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch4, WindowsSecurity)
            ;* [helpstring] *
            STD_METHOD WindowsSecurity, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch4, ToggleDesktop)
            ;* [helpstring] *
            STD_METHOD ToggleDesktop, :ptr IShellDispatch4
            DECLSPEC_XFGVIRT(IShellDispatch4, ExplorerPolicy)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ExplorerPolicy, :ptr IShellDispatch4, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch4, GetSetting)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSetting, :ptr IShellDispatch4, :SDWORD, :ptr VARIANT_BOOL
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellDispatch4Vtbl ends
          IShellDispatch4 struct
            lpVtbl POINTER ?
          IShellDispatch4 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellDispatch4_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellDispatch5_INTERFACE_DEFINED__
        __IShellDispatch5_INTERFACE_DEFINED__ equ <>
        ;* interface IShellDispatch5 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellDispatch5:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch5Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch5Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellDispatch5, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch5, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellDispatch5, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch5, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellDispatch5, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellDispatch, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellDispatch5, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellDispatch5, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, NameSpace)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NameSpace, :ptr IShellDispatch5, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, BrowseForFolder)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD BrowseForFolder, :ptr IShellDispatch5, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Windows)
            ;* [helpstring] *
            STD_METHOD Windows, :ptr IShellDispatch5, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Open)
            ;* [helpstring] *
            STD_METHOD Open, :ptr IShellDispatch5, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, Explore)
            ;* [helpstring] *
            STD_METHOD Explore, :ptr IShellDispatch5, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, MinimizeAll)
            ;* [helpstring] *
            STD_METHOD MinimizeAll, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, UndoMinimizeALL)
            ;* [helpstring] *
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, FileRun)
            ;* [helpstring] *
            STD_METHOD FileRun, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, CascadeWindows)
            ;* [helpstring] *
            STD_METHOD CascadeWindows, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, TileVertically)
            ;* [helpstring] *
            STD_METHOD TileVertically, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, TileHorizontally)
            ;* [helpstring] *
            STD_METHOD TileHorizontally, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, ShutdownWindows)
            ;* [helpstring] *
            STD_METHOD ShutdownWindows, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, Suspend)
            ;* [helpstring] *
            STD_METHOD Suspend, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, EjectPC)
            ;* [helpstring] *
            STD_METHOD EjectPC, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, SetTime)
            ;* [helpstring] *
            STD_METHOD SetTime, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, TrayProperties)
            ;* [helpstring] *
            STD_METHOD TrayProperties, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, Help)
            ;* [helpstring] *
            STD_METHOD Help, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, FindFiles)
            ;* [helpstring] *
            STD_METHOD FindFiles, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, FindComputer)
            ;* [helpstring] *
            STD_METHOD FindComputer, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, RefreshMenu)
            ;* [helpstring] *
            STD_METHOD RefreshMenu, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch, ControlPanelItem)
            ;* [helpstring] *
            STD_METHOD ControlPanelItem, :ptr IShellDispatch5, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsRestricted)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsRestricted, :ptr IShellDispatch5, :BSTR, :BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShellExecute)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD ShellExecute, :ptr IShellDispatch5, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, FindPrinter)
            ;* [helpstring] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD FindPrinter, :ptr IShellDispatch5, :BSTR, :BSTR, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, GetSystemInformation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSystemInformation, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStart)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStart, :ptr IShellDispatch5, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStop)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStop, :ptr IShellDispatch5, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsServiceRunning)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD IsServiceRunning, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, CanStartStopService)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CanStartStopService, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShowBrowserBar)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch5, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch3, AddToRecent)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD AddToRecent, :ptr IShellDispatch5, :VARIANT, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch4, WindowsSecurity)
            ;* [helpstring] *
            STD_METHOD WindowsSecurity, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch4, ToggleDesktop)
            ;* [helpstring] *
            STD_METHOD ToggleDesktop, :ptr IShellDispatch5
            DECLSPEC_XFGVIRT(IShellDispatch4, ExplorerPolicy)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ExplorerPolicy, :ptr IShellDispatch5, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch4, GetSetting)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSetting, :ptr IShellDispatch5, :SDWORD, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch5, WindowSwitcher)
            ;* [helpstring] *
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
          ;* C style interface *
        endif
        ;* __IShellDispatch5_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellDispatch6_INTERFACE_DEFINED__
        __IShellDispatch6_INTERFACE_DEFINED__ equ <>
        ;* interface IShellDispatch6 *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IShellDispatch6:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellDispatch6Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellDispatch6Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellDispatch6, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellDispatch6, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellDispatch6, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellDispatch6, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IShellDispatch6, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellDispatch, get_Application)
            ;* [helpstring][propget] *
            STD_METHOD get_Application, :ptr IShellDispatch6, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, get_Parent)
            ;* [helpstring][propget] *
            STD_METHOD get_Parent, :ptr IShellDispatch6, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, NameSpace)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD NameSpace, :ptr IShellDispatch6, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, BrowseForFolder)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD BrowseForFolder, :ptr IShellDispatch6, :SDWORD, :BSTR, :SDWORD, :VARIANT, :ptr ptr Folder
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Windows)
            ;* [helpstring] *
            STD_METHOD Windows, :ptr IShellDispatch6, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch, Open)
            ;* [helpstring] *
            STD_METHOD Open, :ptr IShellDispatch6, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, Explore)
            ;* [helpstring] *
            STD_METHOD Explore, :ptr IShellDispatch6, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch, MinimizeAll)
            ;* [helpstring] *
            STD_METHOD MinimizeAll, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, UndoMinimizeALL)
            ;* [helpstring] *
            STD_METHOD UndoMinimizeALL, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, FileRun)
            ;* [helpstring] *
            STD_METHOD FileRun, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, CascadeWindows)
            ;* [helpstring] *
            STD_METHOD CascadeWindows, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, TileVertically)
            ;* [helpstring] *
            STD_METHOD TileVertically, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, TileHorizontally)
            ;* [helpstring] *
            STD_METHOD TileHorizontally, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, ShutdownWindows)
            ;* [helpstring] *
            STD_METHOD ShutdownWindows, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, Suspend)
            ;* [helpstring] *
            STD_METHOD Suspend, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, EjectPC)
            ;* [helpstring] *
            STD_METHOD EjectPC, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, SetTime)
            ;* [helpstring] *
            STD_METHOD SetTime, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, TrayProperties)
            ;* [helpstring] *
            STD_METHOD TrayProperties, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, Help)
            ;* [helpstring] *
            STD_METHOD Help, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, FindFiles)
            ;* [helpstring] *
            STD_METHOD FindFiles, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, FindComputer)
            ;* [helpstring] *
            STD_METHOD FindComputer, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, RefreshMenu)
            ;* [helpstring] *
            STD_METHOD RefreshMenu, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch, ControlPanelItem)
            ;* [helpstring] *
            STD_METHOD ControlPanelItem, :ptr IShellDispatch6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsRestricted)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsRestricted, :ptr IShellDispatch6, :BSTR, :BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShellExecute)
            ;* [helpstring] *
            ;* [in] *
            ;* [optional][in] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD ShellExecute, :ptr IShellDispatch6, :BSTR, :VARIANT, :VARIANT, :VARIANT, :VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, FindPrinter)
            ;* [helpstring] *
            ;* [optional][in] *
            ;* [optional][in] *
            STD_METHOD FindPrinter, :ptr IShellDispatch6, :BSTR, :BSTR, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch2, GetSystemInformation)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSystemInformation, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStart)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStart, :ptr IShellDispatch6, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ServiceStop)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ServiceStop, :ptr IShellDispatch6, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, IsServiceRunning)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD IsServiceRunning, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, CanStartStopService)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD CanStartStopService, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch2, ShowBrowserBar)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserBar, :ptr IShellDispatch6, :BSTR, :VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch3, AddToRecent)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD AddToRecent, :ptr IShellDispatch6, :VARIANT, :BSTR
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IShellDispatch4, WindowsSecurity)
            ;* [helpstring] *
            STD_METHOD WindowsSecurity, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch4, ToggleDesktop)
            ;* [helpstring] *
            STD_METHOD ToggleDesktop, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch4, ExplorerPolicy)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD ExplorerPolicy, :ptr IShellDispatch6, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch4, GetSetting)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD GetSetting, :ptr IShellDispatch6, :SDWORD, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellDispatch5, WindowSwitcher)
            ;* [helpstring] *
            STD_METHOD WindowSwitcher, :ptr IShellDispatch6
            DECLSPEC_XFGVIRT(IShellDispatch6, SearchCommand)
            ;* [helpstring] *
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
          ;* C style interface *
        endif
        ;* __IShellDispatch6_INTERFACE_DEFINED__ *
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
        ;* interface IFileSearchBand *
        ;* [object][unique][hidden][dual][oleautomation][helpstring][uuid] *
        externdef IID_IFileSearchBand:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFileSearchBandVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFileSearchBandVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IFileSearchBand, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFileSearchBand
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFileSearchBand
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IFileSearchBand, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IFileSearchBand, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IFileSearchBand, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IFileSearchBand, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IFileSearchBand, SetFocus)
            ;* [helpstring][id] *
            STD_METHOD SetFocus, :ptr IFileSearchBand
            DECLSPEC_XFGVIRT(IFileSearchBand, SetSearchParameters)
            ;* [helpstring][id] *
            ;* [in] *
            ;* [in] *
            ;* [optional][in] *
            STD_METHOD SetSearchParameters, :ptr IFileSearchBand, :ptr BSTR, :VARIANT_BOOL, :ptr VARIANT, :ptr VARIANT
            ;* [optional][in] *
            DECLSPEC_XFGVIRT(IFileSearchBand, get_SearchID)
            ;* [helpstring][propget][id] *
            STD_METHOD get_SearchID, :ptr IFileSearchBand, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IFileSearchBand, get_Scope)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Scope, :ptr IFileSearchBand, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IFileSearchBand, get_QueryFile)
            ;* [helpstring][propget][id] *
            STD_METHOD get_QueryFile, :ptr IFileSearchBand, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IFileSearchBandVtbl ends
          IFileSearchBand struct
            lpVtbl POINTER ?
          IFileSearchBand ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IFileSearchBand_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_FileSearchBand:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IWebWizardHost_INTERFACE_DEFINED__
        __IWebWizardHost_INTERFACE_DEFINED__ equ <>
        ;* interface IWebWizardHost *
        ;* [helpstring][dual][object][uuid] *
        externdef IID_IWebWizardHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebWizardHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebWizardHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWebWizardHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWebWizardHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWebWizardHost
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IWebWizardHost, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IWebWizardHost, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IWebWizardHost, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IWebWizardHost, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IWebWizardHost, FinalBack)
            ;* [id] *
            STD_METHOD FinalBack, :ptr IWebWizardHost
            DECLSPEC_XFGVIRT(IWebWizardHost, FinalNext)
            ;* [id] *
            STD_METHOD FinalNext, :ptr IWebWizardHost
            DECLSPEC_XFGVIRT(IWebWizardHost, Cancel)
            ;* [id] *
            STD_METHOD Cancel, :ptr IWebWizardHost
            DECLSPEC_XFGVIRT(IWebWizardHost, put_Caption)
            ;* [propput][id] *
            STD_METHOD put_Caption, :ptr IWebWizardHost, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, get_Caption)
            ;* [propget][id] *
            STD_METHOD get_Caption, :ptr IWebWizardHost, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebWizardHost, put_Property)
            ;* [propput][id] *
            ;* [in] *
            STD_METHOD put_Property, :ptr IWebWizardHost, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, get_Property)
            ;* [propget][id] *
            ;* [in] *
            STD_METHOD get_Property, :ptr IWebWizardHost, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebWizardHost, SetWizardButtons)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SetWizardButtons, :ptr IWebWizardHost, :VARIANT_BOOL, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, SetHeaderText)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetHeaderText, :ptr IWebWizardHost, :BSTR, :BSTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IWebWizardHostVtbl ends
          IWebWizardHost struct
            lpVtbl POINTER ?
          IWebWizardHost ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWebWizardHost_INTERFACE_DEFINED__ *
      endif
      ifndef __IWebWizardHost2_INTERFACE_DEFINED__
        __IWebWizardHost2_INTERFACE_DEFINED__ equ <>
        ;* interface IWebWizardHost2 *
        ;* [dual][object][uuid] *
        externdef IID_IWebWizardHost2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebWizardHost2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebWizardHost2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWebWizardHost2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWebWizardHost2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWebWizardHost2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IWebWizardHost2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IWebWizardHost2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IWebWizardHost2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr IWebWizardHost2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IWebWizardHost, FinalBack)
            ;* [id] *
            STD_METHOD FinalBack, :ptr IWebWizardHost2
            DECLSPEC_XFGVIRT(IWebWizardHost, FinalNext)
            ;* [id] *
            STD_METHOD FinalNext, :ptr IWebWizardHost2
            DECLSPEC_XFGVIRT(IWebWizardHost, Cancel)
            ;* [id] *
            STD_METHOD Cancel, :ptr IWebWizardHost2
            DECLSPEC_XFGVIRT(IWebWizardHost, put_Caption)
            ;* [propput][id] *
            STD_METHOD put_Caption, :ptr IWebWizardHost2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, get_Caption)
            ;* [propget][id] *
            STD_METHOD get_Caption, :ptr IWebWizardHost2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebWizardHost, put_Property)
            ;* [propput][id] *
            ;* [in] *
            STD_METHOD put_Property, :ptr IWebWizardHost2, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, get_Property)
            ;* [propget][id] *
            ;* [in] *
            STD_METHOD get_Property, :ptr IWebWizardHost2, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebWizardHost, SetWizardButtons)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SetWizardButtons, :ptr IWebWizardHost2, :VARIANT_BOOL, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, SetHeaderText)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetHeaderText, :ptr IWebWizardHost2, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost2, SignString)
            ;* [id] *
            ;* [in] *
            STD_METHOD SignString, :ptr IWebWizardHost2, :BSTR, :ptr BSTR
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IWebWizardHost2Vtbl ends
          IWebWizardHost2 struct
            lpVtbl POINTER ?
          IWebWizardHost2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWebWizardHost2_INTERFACE_DEFINED__ *
      endif
      ifndef __INewWDEvents_INTERFACE_DEFINED__
        __INewWDEvents_INTERFACE_DEFINED__ equ <>
        ;* interface INewWDEvents *
        ;* [helpstring][dual][object][uuid] *
        externdef IID_INewWDEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INewWDEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INewWDEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr INewWDEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr INewWDEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr INewWDEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr INewWDEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr INewWDEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr INewWDEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr INewWDEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IWebWizardHost, FinalBack)
            ;* [id] *
            STD_METHOD FinalBack, :ptr INewWDEvents
            DECLSPEC_XFGVIRT(IWebWizardHost, FinalNext)
            ;* [id] *
            STD_METHOD FinalNext, :ptr INewWDEvents
            DECLSPEC_XFGVIRT(IWebWizardHost, Cancel)
            ;* [id] *
            STD_METHOD Cancel, :ptr INewWDEvents
            DECLSPEC_XFGVIRT(IWebWizardHost, put_Caption)
            ;* [propput][id] *
            STD_METHOD put_Caption, :ptr INewWDEvents, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, get_Caption)
            ;* [propget][id] *
            STD_METHOD get_Caption, :ptr INewWDEvents, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebWizardHost, put_Property)
            ;* [propput][id] *
            ;* [in] *
            STD_METHOD put_Property, :ptr INewWDEvents, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, get_Property)
            ;* [propget][id] *
            ;* [in] *
            STD_METHOD get_Property, :ptr INewWDEvents, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebWizardHost, SetWizardButtons)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SetWizardButtons, :ptr INewWDEvents, :VARIANT_BOOL, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebWizardHost, SetHeaderText)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetHeaderText, :ptr INewWDEvents, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(INewWDEvents, PassportAuthenticate)
            ;* [id] *
            ;* [in] *
            STD_METHOD PassportAuthenticate, :ptr INewWDEvents, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          INewWDEventsVtbl ends
          INewWDEvents struct
            lpVtbl POINTER ?
          INewWDEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __INewWDEvents_INTERFACE_DEFINED__ *
      endif
      ;* __Shell32_LIBRARY_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shldisp_0000_0001 *
    ;* [local] *
    ;-------------------------------------------------------------------------
    ; IAutoComplete interface
    ; [Member functions]
    ; IAutoComplete::Init(hwndEdit, punkACL, pwszRegKeyPath, pwszQuickComplete)
    ;   This function initializes an AutoComplete object, telling it
    ;   what control to subclass, and what list of strings to process.
    ; IAutoComplete::Enable(fEnable)
    ;   This function enables or disables the AutoComplete functionality.
    ;-------------------------------------------------------------------------
    externdef __MIDL_itf_shldisp_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shldisp_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IAutoComplete_INTERFACE_DEFINED__
      __IAutoComplete_INTERFACE_DEFINED__ equ <>
      ;* interface IAutoComplete *
      ;* [unique][uuid][object][local][helpstring] *
      ;* [unique] *
      LPAUTOCOMPLETE typedef ptr IAutoComplete
      externdef IID_IAutoComplete:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAutoCompleteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAutoCompleteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IAutoComplete, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IAutoComplete
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IAutoComplete
          DECLSPEC_XFGVIRT(IAutoComplete, Init)
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          STD_METHOD Init, :ptr IAutoComplete, :HWND, :ptr IUnknown, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(IAutoComplete, Enable)
          STD_METHOD Enable, :ptr IAutoComplete, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IAutoCompleteVtbl ends
        IAutoComplete struct
          lpVtbl POINTER ?
        IAutoComplete ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IAutoComplete_INTERFACE_DEFINED__ *
    endif
    ifndef __IAutoComplete2_INTERFACE_DEFINED__
      __IAutoComplete2_INTERFACE_DEFINED__ equ <>
      ;* interface IAutoComplete2 *
      ;* [unique][uuid][object][local][helpstring] *
      ;* [unique] *
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
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IAutoComplete2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IAutoComplete2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IAutoComplete2
          DECLSPEC_XFGVIRT(IAutoComplete, Init)
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          STD_METHOD Init, :ptr IAutoComplete2, :HWND, :ptr IUnknown, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(IAutoComplete, Enable)
          STD_METHOD Enable, :ptr IAutoComplete2, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IAutoComplete2, SetOptions)
          STD_METHOD SetOptions, :ptr IAutoComplete2, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IAutoComplete2, GetOptions)
          ;* [annotation][out] *
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
        ;* C style interface *
      endif
      ;* __IAutoComplete2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shldisp_0000_0003 *
    ;* [local] *
    ; INTERFACE: IEnumACString
    ; This interface was implemented to return autocomplete strings
    ; into the caller's buffer (to reduce the number of memory allocations).
    ; A sort index is also returned to control the order of items displayed.
    ; by autocomplete.  The sort index should be set to zero if unused.
    ; The NextItem method increments the current index by one (similar to Next
    ; when one item is requested).
    externdef __MIDL_itf_shldisp_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_shldisp_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumACString_INTERFACE_DEFINED__
      __IEnumACString_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumACString *
      ;* [unique][uuid][object][local][helpstring] *
      ;* [unique] *
      PENUMACSTRING typedef ptr IEnumACString
      ;* [unique] *
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
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumACString, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumACString
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumACString
          DECLSPEC_XFGVIRT(IEnumString, Next)
          ;* [local] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD Next, :ptr IEnumACString, :ULONG, :ptr LPOLESTR, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumString, Skip)
          STD_METHOD Skip, :ptr IEnumACString, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumString, Reset)
          STD_METHOD Reset, :ptr IEnumACString
          DECLSPEC_XFGVIRT(IEnumString, Clone)
          STD_METHOD Clone, :ptr IEnumACString, :ptr ptr IEnumString
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumACString, NextItem)
          ;* [annotation][size_is][unique][string][out] *
          ;* [in] *
          ;* [annotation][out] *
          STD_METHOD NextItem, :ptr IEnumACString, :LPWSTR, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumACString, SetEnumOptions)
          STD_METHOD SetEnumOptions, :ptr IEnumACString, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumACString, GetEnumOptions)
          ;* [annotation][out] *
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
        ;* C style interface *
      endif
      ;* __IEnumACString_INTERFACE_DEFINED__ *
    endif
    ifndef __IDataObjectAsyncCapability_INTERFACE_DEFINED__
      __IDataObjectAsyncCapability_INTERFACE_DEFINED__ equ <>
      ;* interface IDataObjectAsyncCapability *
      ;* [object][uuid] *
      externdef IID_IDataObjectAsyncCapability:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDataObjectAsyncCapabilityVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDataObjectAsyncCapabilityVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDataObjectAsyncCapability, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDataObjectAsyncCapability
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDataObjectAsyncCapability
          DECLSPEC_XFGVIRT(IDataObjectAsyncCapability, SetAsyncMode)
          STD_METHOD SetAsyncMode, :ptr IDataObjectAsyncCapability, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IDataObjectAsyncCapability, GetAsyncMode)
          STD_METHOD GetAsyncMode, :ptr IDataObjectAsyncCapability, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IDataObjectAsyncCapability, StartOperation)
          STD_METHOD StartOperation, :ptr IDataObjectAsyncCapability, :ptr IBindCtx
          ;* [optional][unique][in] *
          DECLSPEC_XFGVIRT(IDataObjectAsyncCapability, InOperation)
          STD_METHOD InOperation, :ptr IDataObjectAsyncCapability, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IDataObjectAsyncCapability, EndOperation)
          ;* [in] *
          ;* [unique][in] *
          STD_METHOD EndOperation, :ptr IDataObjectAsyncCapability, :HRESULT, :ptr IBindCtx, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IDataObjectAsyncCapabilityVtbl ends
        IDataObjectAsyncCapability struct
          lpVtbl POINTER ?
        IDataObjectAsyncCapability ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDataObjectAsyncCapability_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_shldisp_0000_0005 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_shldisp_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shldisp_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
