;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\cguid.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 12/02/2024 17:05:56

include winapifamily.inc
ifndef __CGUID_H__
  __CGUID_H__ equ <>
  if _MSC_VER gt 1000
  endif
  if (_MSC_VER ge 800)
    if (_MSC_VER ge 1200)
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    externdef GUID_NULL:IID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_WINXP)
      externdef CATID_MARSHALER:IID
    endif
    externdef IID_IRpcChannel:IID
    externdef IID_IRpcStub:IID
    externdef IID_IStubManager:IID
    externdef IID_IRpcProxy:IID
    externdef IID_IProxyManager:IID
    externdef IID_IPSFactory:IID
    externdef IID_IInternalMoniker:IID
    externdef IID_IDfReserved1:IID
    externdef IID_IDfReserved2:IID
    externdef IID_IDfReserved3:IID
    externdef CLSID_StdMarshal:CLSID
    externdef CLSID_AggStdMarshal:CLSID
    externdef CLSID_StdAsyncActManager:CLSID
    externdef IID_IStub:IID
    externdef IID_IProxy:IID
    externdef IID_IEnumGeneric:IID
    externdef IID_IEnumHolder:IID
    externdef IID_IEnumCallback:IID
    externdef IID_IOleManager:IID
    externdef IID_IOlePresObj:IID
    externdef IID_IDebug:IID
    externdef IID_IDebugStream:IID
    externdef CLSID_PSGenObject:CLSID
    externdef CLSID_PSClientSite:CLSID
    externdef CLSID_PSClassObject:CLSID
    externdef CLSID_PSInPlaceActive:CLSID
    externdef CLSID_PSInPlaceFrame:CLSID
    externdef CLSID_PSDragDrop:CLSID
    externdef CLSID_PSBindCtx:CLSID
    externdef CLSID_PSEnumerators:CLSID
    externdef CLSID_StaticMetafile:CLSID
    externdef CLSID_StaticDib:CLSID
    externdef CID_CDfsVolume:CLSID
    externdef CLSID_DCOMAccessControl:CLSID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef CLSID_GlobalOptions:CLSID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef CLSID_StdGlobalInterfaceTable:CLSID
    externdef CLSID_MachineGlobalObjectTable:CLSID
    externdef CLSID_ActivationCapabilities:CLSID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef CLSID_ComBinding:CLSID
    externdef CLSID_StdEvent:CLSID
    externdef CLSID_ManualResetEvent:CLSID
    externdef CLSID_SynchronizeContainer:CLSID
    if (NTDDI_VERSION ge NTDDI_WINXP)
      externdef CLSID_AddrControl:CLSID
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      externdef CLSID_ContextSwitcher:CLSID
    endif
    externdef CLSID_CCDFormKrnl:CLSID
    externdef CLSID_CCDPropertyPage:CLSID
    externdef CLSID_CCDFormDialog:CLSID
    externdef CLSID_CCDCommandButton:CLSID
    externdef CLSID_CCDComboBox:CLSID
    externdef CLSID_CCDTextBox:CLSID
    externdef CLSID_CCDCheckBox:CLSID
    externdef CLSID_CCDLabel:CLSID
    externdef CLSID_CCDOptionButton:CLSID
    externdef CLSID_CCDListBox:CLSID
    externdef CLSID_CCDScrollBar:CLSID
    externdef CLSID_CCDGroupBox:CLSID
    externdef CLSID_CCDGeneralPropertyPage:CLSID
    externdef CLSID_CCDGenericPropertyPage:CLSID
    externdef CLSID_CCDFontPropertyPage:CLSID
    externdef CLSID_CCDColorPropertyPage:CLSID
    externdef CLSID_CCDLabelPropertyPage:CLSID
    externdef CLSID_CCDCheckBoxPropertyPage:CLSID
    externdef CLSID_CCDTextBoxPropertyPage:CLSID
    externdef CLSID_CCDOptionButtonPropertyPage:CLSID
    externdef CLSID_CCDListBoxPropertyPage:CLSID
    externdef CLSID_CCDCommandButtonPropertyPage:CLSID
    externdef CLSID_CCDComboBoxPropertyPage:CLSID
    externdef CLSID_CCDScrollBarPropertyPage:CLSID
    externdef CLSID_CCDGroupBoxPropertyPage:CLSID
    externdef CLSID_CCDXObjectPropertyPage:CLSID
    externdef CLSID_CStdPropertyFrame:CLSID
    externdef CLSID_CFormPropertyPage:CLSID
    externdef CLSID_CGridPropertyPage:CLSID
    externdef CLSID_CWSJArticlePage:CLSID
    externdef CLSID_CSystemPage:CLSID
    externdef CLSID_IdentityUnmarshal:CLSID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    externdef CLSID_InProcFreeMarshaler:CLSID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef CLSID_Picture_Metafile:CLSID
    externdef CLSID_Picture_EnhMetafile:CLSID
    externdef CLSID_Picture_Dib:CLSID
    externdef GUID_TRISTATE:GUID
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 800)
    if (_MSC_VER ge 1200)
    else
    endif
  endif
endif
