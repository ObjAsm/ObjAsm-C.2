;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ndkinfo.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 16/12/2023 11:05:36

ifndef _NDKINFO_H_
  _NDKINFO_H_ equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    NDK_VERSION struct
      Major USHORT ?
      Minor USHORT ?
    NDK_VERSION ends
    NDK_RDMA_TECHNOLOGY typedef SDWORD
    NdkUndefined equ 0
    NdkiWarp equ 1
    NdkInfiniBand equ 2
    NdkRoCE equ 3
    NdkRoCEv2 equ 4
    NdkMaxTechnology equ 5
    _NDK_RDMA_TECHNOLOGY typedef NDK_RDMA_TECHNOLOGY

    NDK_ADAPTER_INFO struct
      Version NDK_VERSION <>
      VendorId UINT32 ?
      DeviceId UINT32 ?
      MaxRegistrationSize SIZE_T ?
      MaxWindowSize SIZE_T ?
      FRMRPageCount ULONG ?
      MaxInitiatorRequestSge ULONG ?
      MaxReceiveRequestSge ULONG ?
      MaxReadRequestSge ULONG ?
      MaxTransferLength ULONG ?
      MaxInlineDataSize ULONG ?
      MaxInboundReadLimit ULONG ?
      MaxOutboundReadLimit ULONG ?
      MaxReceiveQueueDepth ULONG ?
      MaxInitiatorQueueDepth ULONG ?
      MaxSrqDepth ULONG ?
      MaxCqDepth ULONG ?
      LargeRequestThreshold ULONG ?
      MaxCallerData ULONG ?
      MaxCalleeData ULONG ?
      AdapterFlags ULONG ?
      RdmaTechnology NDK_RDMA_TECHNOLOGY ?
    NDK_ADAPTER_INFO ends
    _NDK_ADAPTER_INFO typedef NDK_ADAPTER_INFO
    NDK_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED equ 00000001h
    NDK_ADAPTER_FLAG_RDMA_READ_SINK_NOT_REQUIRED equ 00000002h
    NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORTED equ 00000004h
    NDK_ADAPTER_FLAG_MULTI_ENGINE_SUPPORTED equ 00000008h
    NDK_ADAPTER_FLAG_RDMA_READ_LOCAL_INVALIDATE_SUPPORTED equ 00000010h
    NDK_ADAPTER_FLAG_CQ_RESIZE_SUPPORTED equ 00000100h
    NDK_ADAPTER_FLAG_LOOPBACK_CONNECTIONS_SUPPORTED equ 00010000h
  endif
endif
