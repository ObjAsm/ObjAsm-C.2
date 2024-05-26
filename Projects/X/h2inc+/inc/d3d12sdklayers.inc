;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\d3d12sdklayers.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:19:34

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
ifndef __d3d12sdklayers_h__
  __d3d12sdklayers_h__ equ <>
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
  ifndef __ID3D12Debug_FWD_DEFINED__
    __ID3D12Debug_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12Debug1_FWD_DEFINED__
    __ID3D12Debug1_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12Debug2_FWD_DEFINED__
    __ID3D12Debug2_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12Debug3_FWD_DEFINED__
    __ID3D12Debug3_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12Debug4_FWD_DEFINED__
    __ID3D12Debug4_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12Debug5_FWD_DEFINED__
    __ID3D12Debug5_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12Debug6_FWD_DEFINED__
    __ID3D12Debug6_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugDevice1_FWD_DEFINED__
    __ID3D12DebugDevice1_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugDevice_FWD_DEFINED__
    __ID3D12DebugDevice_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugDevice2_FWD_DEFINED__
    __ID3D12DebugDevice2_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugCommandQueue_FWD_DEFINED__
    __ID3D12DebugCommandQueue_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugCommandList1_FWD_DEFINED__
    __ID3D12DebugCommandList1_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugCommandList_FWD_DEFINED__
    __ID3D12DebugCommandList_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12DebugCommandList2_FWD_DEFINED__
    __ID3D12DebugCommandList2_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12SharingContract_FWD_DEFINED__
    __ID3D12SharingContract_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12InfoQueue_FWD_DEFINED__
    __ID3D12InfoQueue_FWD_DEFINED__ equ <>
  endif
  ifndef __ID3D12InfoQueue1_FWD_DEFINED__
    __ID3D12InfoQueue1_FWD_DEFINED__ equ <>
  endif
  include OAIdl.inc
  include OCIdl.inc
  include d3d12.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_d3d12sdklayers_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12Debug_INTERFACE_DEFINED__
      __ID3D12Debug_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug
          DECLSPEC_XFGVIRT(ID3D12Debug, EnableDebugLayer)
          STD_METHOD EnableDebugLayer, :ptr ID3D12Debug
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugVtbl ends
        ID3D12Debug struct
          lpVtbl POINTER ?
        ID3D12Debug ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    D3D12_GPU_BASED_VALIDATION_FLAGS typedef SDWORD
    D3D12_GPU_BASED_VALIDATION_FLAGS_NONE equ 0
    D3D12_GPU_BASED_VALIDATION_FLAGS_DISABLE_STATE_TRACKING equ 1h

    DEFINE_ENUM_FLAG_OPERATORS(D3D12_GPU_BASED_VALIDATION_FLAGS)
    externdef __MIDL_itf_d3d12sdklayers_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12Debug1_INTERFACE_DEFINED__
      __ID3D12Debug1_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug1:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12Debug1Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12Debug1Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug1, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug1
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug1
          DECLSPEC_XFGVIRT(ID3D12Debug1, EnableDebugLayer)
          STD_METHOD EnableDebugLayer, :ptr ID3D12Debug1
          DECLSPEC_XFGVIRT(ID3D12Debug1, SetEnableGPUBasedValidation)
          STD_METHOD SetEnableGPUBasedValidation, :ptr ID3D12Debug1, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug1, SetEnableSynchronizedCommandQueueValidation)
          STD_METHOD SetEnableSynchronizedCommandQueueValidation, :ptr ID3D12Debug1, :BOOL
          ??Interface equ <>
          END_INTERFACE
        ID3D12Debug1Vtbl ends
        ID3D12Debug1 struct
          lpVtbl POINTER ?
        ID3D12Debug1 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12Debug2_INTERFACE_DEFINED__
      __ID3D12Debug2_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12Debug2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12Debug2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug2
          DECLSPEC_XFGVIRT(ID3D12Debug2, SetGPUBasedValidationFlags)
          STD_METHOD SetGPUBasedValidationFlags, :ptr ID3D12Debug2, :D3D12_GPU_BASED_VALIDATION_FLAGS
          ??Interface equ <>
          END_INTERFACE
        ID3D12Debug2Vtbl ends
        ID3D12Debug2 struct
          lpVtbl POINTER ?
        ID3D12Debug2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12Debug3_INTERFACE_DEFINED__
      __ID3D12Debug3_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug3:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12Debug3Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12Debug3Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug3, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug3
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug3
          DECLSPEC_XFGVIRT(ID3D12Debug, EnableDebugLayer)
          STD_METHOD EnableDebugLayer, :ptr ID3D12Debug3
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableGPUBasedValidation)
          STD_METHOD SetEnableGPUBasedValidation, :ptr ID3D12Debug3, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableSynchronizedCommandQueueValidation)
          STD_METHOD SetEnableSynchronizedCommandQueueValidation, :ptr ID3D12Debug3, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetGPUBasedValidationFlags)
          STD_METHOD SetGPUBasedValidationFlags, :ptr ID3D12Debug3, :D3D12_GPU_BASED_VALIDATION_FLAGS
          ??Interface equ <>
          END_INTERFACE
        ID3D12Debug3Vtbl ends
        ID3D12Debug3 struct
          lpVtbl POINTER ?
        ID3D12Debug3 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12Debug4_INTERFACE_DEFINED__
      __ID3D12Debug4_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug4:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12Debug4Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12Debug4Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug4, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug4
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug4
          DECLSPEC_XFGVIRT(ID3D12Debug, EnableDebugLayer)
          STD_METHOD EnableDebugLayer, :ptr ID3D12Debug4
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableGPUBasedValidation)
          STD_METHOD SetEnableGPUBasedValidation, :ptr ID3D12Debug4, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableSynchronizedCommandQueueValidation)
          STD_METHOD SetEnableSynchronizedCommandQueueValidation, :ptr ID3D12Debug4, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetGPUBasedValidationFlags)
          STD_METHOD SetGPUBasedValidationFlags, :ptr ID3D12Debug4, :D3D12_GPU_BASED_VALIDATION_FLAGS
          DECLSPEC_XFGVIRT(ID3D12Debug4, DisableDebugLayer)
          STD_METHOD DisableDebugLayer, :ptr ID3D12Debug4
          ??Interface equ <>
          END_INTERFACE
        ID3D12Debug4Vtbl ends
        ID3D12Debug4 struct
          lpVtbl POINTER ?
        ID3D12Debug4 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12Debug5_INTERFACE_DEFINED__
      __ID3D12Debug5_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug5:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12Debug5Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12Debug5Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug5, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug5
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug5
          DECLSPEC_XFGVIRT(ID3D12Debug, EnableDebugLayer)
          STD_METHOD EnableDebugLayer, :ptr ID3D12Debug5
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableGPUBasedValidation)
          STD_METHOD SetEnableGPUBasedValidation, :ptr ID3D12Debug5, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableSynchronizedCommandQueueValidation)
          STD_METHOD SetEnableSynchronizedCommandQueueValidation, :ptr ID3D12Debug5, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetGPUBasedValidationFlags)
          STD_METHOD SetGPUBasedValidationFlags, :ptr ID3D12Debug5, :D3D12_GPU_BASED_VALIDATION_FLAGS
          DECLSPEC_XFGVIRT(ID3D12Debug4, DisableDebugLayer)
          STD_METHOD DisableDebugLayer, :ptr ID3D12Debug5
          DECLSPEC_XFGVIRT(ID3D12Debug5, SetEnableAutoName)
          STD_METHOD SetEnableAutoName, :ptr ID3D12Debug5, :BOOL
          ??Interface equ <>
          END_INTERFACE
        ID3D12Debug5Vtbl ends
        ID3D12Debug5 struct
          lpVtbl POINTER ?
        ID3D12Debug5 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12Debug6_INTERFACE_DEFINED__
      __ID3D12Debug6_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12Debug6:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12Debug6Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12Debug6Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12Debug6, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12Debug6
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12Debug6
          DECLSPEC_XFGVIRT(ID3D12Debug, EnableDebugLayer)
          STD_METHOD EnableDebugLayer, :ptr ID3D12Debug6
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableGPUBasedValidation)
          STD_METHOD SetEnableGPUBasedValidation, :ptr ID3D12Debug6, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetEnableSynchronizedCommandQueueValidation)
          STD_METHOD SetEnableSynchronizedCommandQueueValidation, :ptr ID3D12Debug6, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug3, SetGPUBasedValidationFlags)
          STD_METHOD SetGPUBasedValidationFlags, :ptr ID3D12Debug6, :D3D12_GPU_BASED_VALIDATION_FLAGS
          DECLSPEC_XFGVIRT(ID3D12Debug4, DisableDebugLayer)
          STD_METHOD DisableDebugLayer, :ptr ID3D12Debug6
          DECLSPEC_XFGVIRT(ID3D12Debug5, SetEnableAutoName)
          STD_METHOD SetEnableAutoName, :ptr ID3D12Debug6, :BOOL
          DECLSPEC_XFGVIRT(ID3D12Debug6, SetForceLegacyBarrierValidation)
          STD_METHOD SetForceLegacyBarrierValidation, :ptr ID3D12Debug6, :BOOL
          ??Interface equ <>
          END_INTERFACE
        ID3D12Debug6Vtbl ends
        ID3D12Debug6 struct
          lpVtbl POINTER ?
        ID3D12Debug6 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    DEFINE_GUID WKPDID_D3DAutoDebugObjectNameW, 0d4902e36h, 757ah, 4942h, 95h, 94h, 0b6h, 76h, 9ah, 0fah, 43h, 0cdh
    D3D12_RLDO_FLAGS typedef SDWORD
    D3D12_RLDO_NONE equ 0
    D3D12_RLDO_SUMMARY equ 1h
    D3D12_RLDO_DETAIL equ 2h
    D3D12_RLDO_IGNORE_INTERNAL equ 4h

    DEFINE_ENUM_FLAG_OPERATORS(D3D12_RLDO_FLAGS)
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE typedef SDWORD
    D3D12_DEBUG_DEVICE_PARAMETER_FEATURE_FLAGS equ 0
    D3D12_DEBUG_DEVICE_PARAMETER_GPU_BASED_VALIDATION_SETTINGS equ
    D3D12_DEBUG_DEVICE_PARAMETER_GPU_SLOWDOWN_PERFORMANCE_FACTOR equ

    D3D12_DEBUG_FEATURE typedef SDWORD
    D3D12_DEBUG_FEATURE_NONE equ 0
    D3D12_DEBUG_FEATURE_ALLOW_BEHAVIOR_CHANGING_DEBUG_AIDS equ 1h
    D3D12_DEBUG_FEATURE_CONSERVATIVE_RESOURCE_STATE_TRACKING equ 2h
    D3D12_DEBUG_FEATURE_DISABLE_VIRTUALIZED_BUNDLES_VALIDATION equ 4h
    D3D12_DEBUG_FEATURE_EMULATE_WINDOWS7 equ 8h

    DEFINE_ENUM_FLAG_OPERATORS(D3D12_DEBUG_FEATURE)
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE typedef SDWORD
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_NONE equ 0
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_STATE_TRACKING_ONLY equ
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_UNGUARDED_VALIDATION equ
    D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE_GUARDED_VALIDATION equ
    NUM_D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODES equ

    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS typedef SDWORD
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_NONE equ 0
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_TRACKING_ONLY_SHADERS equ 1h
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_UNGUARDED_VALIDATION_SHADERS equ 2h
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAG_FRONT_LOAD_CREATE_GUARDED_VALIDATION_SHADERS equ 4h
    D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS_VALID_MASK equ 7h

    DEFINE_ENUM_FLAG_OPERATORS(D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS)
    D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS struct
      MaxMessagesPerCommandList UINT ?
      DefaultShaderPatchMode D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE ?
      PipelineStateCreateFlags D3D12_GPU_BASED_VALIDATION_PIPELINE_STATE_CREATE_FLAGS ?
    D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS ends
    D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR struct
      SlowdownFactor FLOAT ?
    D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR ends
    externdef __MIDL_itf_d3d12sdklayers_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12DebugDevice1_INTERFACE_DEFINED__
      __ID3D12DebugDevice1_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugDevice1:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugDevice1Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugDevice1Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugDevice1, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugDevice1
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugDevice1
          DECLSPEC_XFGVIRT(ID3D12DebugDevice1, SetDebugParameter)
          STD_METHOD SetDebugParameter, :ptr ID3D12DebugDevice1, :D3D12_DEBUG_DEVICE_PARAMETER_TYPE, :ptr, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugDevice1, GetDebugParameter)
          STD_METHOD GetDebugParameter, :ptr ID3D12DebugDevice1, :D3D12_DEBUG_DEVICE_PARAMETER_TYPE, :ptr, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugDevice1, ReportLiveDeviceObjects)
          STD_METHOD ReportLiveDeviceObjects, :ptr ID3D12DebugDevice1, :D3D12_RLDO_FLAGS
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugDevice1Vtbl ends
        ID3D12DebugDevice1 struct
          lpVtbl POINTER ?
        ID3D12DebugDevice1 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12DebugDevice_INTERFACE_DEFINED__
      __ID3D12DebugDevice_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugDevice:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugDeviceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugDeviceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugDevice, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugDevice
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugDevice
          DECLSPEC_XFGVIRT(ID3D12DebugDevice, SetFeatureMask)
          STD_METHOD SetFeatureMask, :ptr ID3D12DebugDevice, :D3D12_DEBUG_FEATURE
          DECLSPEC_XFGVIRT(ID3D12DebugDevice, GetFeatureMask)
          STD_METHOD GetFeatureMask, :ptr ID3D12DebugDevice
          DECLSPEC_XFGVIRT(ID3D12DebugDevice, ReportLiveDeviceObjects)
          STD_METHOD ReportLiveDeviceObjects, :ptr ID3D12DebugDevice, :D3D12_RLDO_FLAGS
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugDeviceVtbl ends
        ID3D12DebugDevice struct
          lpVtbl POINTER ?
        ID3D12DebugDevice ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12DebugDevice2_INTERFACE_DEFINED__
      __ID3D12DebugDevice2_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugDevice2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugDevice2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugDevice2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugDevice2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugDevice2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugDevice2
          DECLSPEC_XFGVIRT(ID3D12DebugDevice, SetFeatureMask)
          STD_METHOD SetFeatureMask, :ptr ID3D12DebugDevice2, :D3D12_DEBUG_FEATURE
          DECLSPEC_XFGVIRT(ID3D12DebugDevice, GetFeatureMask)
          STD_METHOD GetFeatureMask, :ptr ID3D12DebugDevice2
          DECLSPEC_XFGVIRT(ID3D12DebugDevice, ReportLiveDeviceObjects)
          STD_METHOD ReportLiveDeviceObjects, :ptr ID3D12DebugDevice2, :D3D12_RLDO_FLAGS
          DECLSPEC_XFGVIRT(ID3D12DebugDevice2, SetDebugParameter)
          STD_METHOD SetDebugParameter, :ptr ID3D12DebugDevice2, :D3D12_DEBUG_DEVICE_PARAMETER_TYPE, :ptr, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugDevice2, GetDebugParameter)
          STD_METHOD GetDebugParameter, :ptr ID3D12DebugDevice2, :D3D12_DEBUG_DEVICE_PARAMETER_TYPE, :ptr, :UINT
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugDevice2Vtbl ends
        ID3D12DebugDevice2 struct
          lpVtbl POINTER ?
        ID3D12DebugDevice2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    DEFINE_GUID DXGI_DEBUG_D3D12, 0cf59a98ch, 0a950h, 4326h, 91h, 0efh, 9bh, 0bah, 0a1h, 7bh, 0fdh, 95h
    externdef __MIDL_itf_d3d12sdklayers_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12DebugCommandQueue_INTERFACE_DEFINED__
      __ID3D12DebugCommandQueue_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugCommandQueue:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugCommandQueueVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugCommandQueueVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugCommandQueue, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugCommandQueue
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugCommandQueue
          DECLSPEC_XFGVIRT(ID3D12DebugCommandQueue, AssertResourceState)
          STD_METHOD AssertResourceState, :ptr ID3D12DebugCommandQueue, :ptr ID3D12Resource, :UINT, :UINT
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugCommandQueueVtbl ends
        ID3D12DebugCommandQueue struct
          lpVtbl POINTER ?
        ID3D12DebugCommandQueue ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE typedef SDWORD
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_GPU_BASED_VALIDATION_SETTINGS equ 0

    D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS struct
      ShaderPatchMode D3D12_GPU_BASED_VALIDATION_SHADER_PATCH_MODE ?
    D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS ends
    externdef __MIDL_itf_d3d12sdklayers_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12DebugCommandList1_INTERFACE_DEFINED__
      __ID3D12DebugCommandList1_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugCommandList1:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugCommandList1Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugCommandList1Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugCommandList1, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugCommandList1
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugCommandList1
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList1, AssertResourceState)
          STD_METHOD AssertResourceState, :ptr ID3D12DebugCommandList1, :ptr ID3D12Resource, :UINT, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList1, SetDebugParameter)
          STD_METHOD SetDebugParameter, :ptr ID3D12DebugCommandList1, :D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE, :ptr, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList1, GetDebugParameter)
          STD_METHOD GetDebugParameter, :ptr ID3D12DebugCommandList1, :D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE, :ptr, :UINT
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugCommandList1Vtbl ends
        ID3D12DebugCommandList1 struct
          lpVtbl POINTER ?
        ID3D12DebugCommandList1 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12DebugCommandList_INTERFACE_DEFINED__
      __ID3D12DebugCommandList_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugCommandList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugCommandListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugCommandListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugCommandList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugCommandList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugCommandList
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList, AssertResourceState)
          STD_METHOD AssertResourceState, :ptr ID3D12DebugCommandList, :ptr ID3D12Resource, :UINT, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList, SetFeatureMask)
          STD_METHOD SetFeatureMask, :ptr ID3D12DebugCommandList, :D3D12_DEBUG_FEATURE
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList, GetFeatureMask)
          STD_METHOD GetFeatureMask, :ptr ID3D12DebugCommandList
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugCommandListVtbl ends
        ID3D12DebugCommandList struct
          lpVtbl POINTER ?
        ID3D12DebugCommandList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12DebugCommandList2_INTERFACE_DEFINED__
      __ID3D12DebugCommandList2_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12DebugCommandList2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12DebugCommandList2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12DebugCommandList2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12DebugCommandList2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12DebugCommandList2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12DebugCommandList2
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList, AssertResourceState)
          STD_METHOD AssertResourceState, :ptr ID3D12DebugCommandList2, :ptr ID3D12Resource, :UINT, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList, SetFeatureMask)
          STD_METHOD SetFeatureMask, :ptr ID3D12DebugCommandList2, :D3D12_DEBUG_FEATURE
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList, GetFeatureMask)
          STD_METHOD GetFeatureMask, :ptr ID3D12DebugCommandList2
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList2, SetDebugParameter)
          STD_METHOD SetDebugParameter, :ptr ID3D12DebugCommandList2, :D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE, :ptr, :UINT
          DECLSPEC_XFGVIRT(ID3D12DebugCommandList2, GetDebugParameter)
          STD_METHOD GetDebugParameter, :ptr ID3D12DebugCommandList2, :D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE, :ptr, :UINT
          ??Interface equ <>
          END_INTERFACE
        ID3D12DebugCommandList2Vtbl ends
        ID3D12DebugCommandList2 struct
          lpVtbl POINTER ?
        ID3D12DebugCommandList2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ID3D12SharingContract_INTERFACE_DEFINED__
      __ID3D12SharingContract_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12SharingContract:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12SharingContractVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12SharingContractVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12SharingContract, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12SharingContract
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12SharingContract
          DECLSPEC_XFGVIRT(ID3D12SharingContract, Present)
          STD_METHOD Present, :ptr ID3D12SharingContract, :ptr ID3D12Resource, :UINT, :HWND
          DECLSPEC_XFGVIRT(ID3D12SharingContract, SharedFenceSignal)
          STD_METHOD SharedFenceSignal, :ptr ID3D12SharingContract, :ptr ID3D12Fence, :UINT64
          DECLSPEC_XFGVIRT(ID3D12SharingContract, BeginCapturableWork)
          STD_METHOD BeginCapturableWork, :ptr ID3D12SharingContract, :REFGUID
          DECLSPEC_XFGVIRT(ID3D12SharingContract, EndCapturableWork)
          STD_METHOD EndCapturableWork, :ptr ID3D12SharingContract, :REFGUID
          ??Interface equ <>
          END_INTERFACE
        ID3D12SharingContractVtbl ends
        ID3D12SharingContract struct
          lpVtbl POINTER ?
        ID3D12SharingContract ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    D3D12_MESSAGE_CATEGORY typedef SDWORD
    D3D12_MESSAGE_CATEGORY_APPLICATION_DEFINED equ 0
    D3D12_MESSAGE_CATEGORY_MISCELLANEOUS equ
    D3D12_MESSAGE_CATEGORY_INITIALIZATION equ
    D3D12_MESSAGE_CATEGORY_CLEANUP equ
    D3D12_MESSAGE_CATEGORY_COMPILATION equ
    D3D12_MESSAGE_CATEGORY_STATE_CREATION equ
    D3D12_MESSAGE_CATEGORY_STATE_SETTING equ
    D3D12_MESSAGE_CATEGORY_STATE_GETTING equ
    D3D12_MESSAGE_CATEGORY_RESOURCE_MANIPULATION equ
    D3D12_MESSAGE_CATEGORY_EXECUTION equ
    D3D12_MESSAGE_CATEGORY_SHADER equ

    D3D12_MESSAGE_SEVERITY typedef SDWORD
    D3D12_MESSAGE_SEVERITY_CORRUPTION equ 0
    D3D12_MESSAGE_SEVERITY_ERROR equ
    D3D12_MESSAGE_SEVERITY_WARNING equ
    D3D12_MESSAGE_SEVERITY_INFO equ
    D3D12_MESSAGE_SEVERITY_MESSAGE equ

    D3D12_MESSAGE_ID typedef SDWORD
    D3D12_MESSAGE_ID_UNKNOWN equ 0
    D3D12_MESSAGE_ID_STRING_FROM_APPLICATION equ 1
    D3D12_MESSAGE_ID_CORRUPTED_THIS equ 2
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER1 equ 3
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER2 equ 4
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER3 equ 5
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER4 equ 6
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER5 equ 7
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER6 equ 8
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER7 equ 9
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER8 equ 10
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER9 equ 11
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER10 equ 12
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER11 equ 13
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER12 equ 14
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER13 equ 15
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER14 equ 16
    D3D12_MESSAGE_ID_CORRUPTED_PARAMETER15 equ 17
    D3D12_MESSAGE_ID_CORRUPTED_MULTITHREADING equ 18
    D3D12_MESSAGE_ID_MESSAGE_REPORTING_OUTOFMEMORY equ 19
    D3D12_MESSAGE_ID_GETPRIVATEDATA_MOREDATA equ 20
    D3D12_MESSAGE_ID_SETPRIVATEDATA_INVALIDFREEDATA equ 21
    D3D12_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS equ 24
    D3D12_MESSAGE_ID_SETPRIVATEDATA_OUTOFMEMORY equ 25
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_UNRECOGNIZEDFORMAT equ 26
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDESC equ 27
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDFORMAT equ 28
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDVIDEOPLANESLICE equ 29
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDPLANESLICE equ 30
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDDIMENSIONS equ 31
    D3D12_MESSAGE_ID_CREATESHADERRESOURCEVIEW_INVALIDRESOURCE equ 32
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNRECOGNIZEDFORMAT equ 35
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_UNSUPPORTEDFORMAT equ 36
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDESC equ 37
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDFORMAT equ 38
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDVIDEOPLANESLICE equ 39
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDPLANESLICE equ 40
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDDIMENSIONS equ 41
    D3D12_MESSAGE_ID_CREATERENDERTARGETVIEW_INVALIDRESOURCE equ 42
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_UNRECOGNIZEDFORMAT equ 45
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDESC equ 46
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFORMAT equ 47
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDDIMENSIONS equ 48
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDRESOURCE equ 49
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_OUTOFMEMORY equ 52
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TOOMANYELEMENTS equ 53
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDFORMAT equ 54
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INCOMPATIBLEFORMAT equ 55
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOT equ 56
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDINPUTSLOTCLASS equ 57
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_STEPRATESLOTCLASSMISMATCH equ 58
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSLOTCLASSCHANGE equ 59
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDSTEPRATECHANGE equ 60
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_INVALIDALIGNMENT equ 61
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_DUPLICATESEMANTIC equ 62
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_UNPARSEABLEINPUTSIGNATURE equ 63
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_NULLSEMANTIC equ 64
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_MISSINGELEMENT equ 65
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_OUTOFMEMORY equ 66
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERBYTECODE equ 67
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDSHADERTYPE equ 68
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_OUTOFMEMORY equ 69
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERBYTECODE equ 70
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDSHADERTYPE equ 71
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTOFMEMORY equ 72
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERBYTECODE equ 73
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE equ 74
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMENTRIES equ 75
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSTREAMSTRIDEUNUSED equ 76
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_OUTPUTSLOT0EXPECTED equ 79
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSLOT equ 80
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_ONLYONEELEMENTPERSLOT equ 81
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDCOMPONENTCOUNT equ 82
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTARTCOMPONENTANDCOMPONENTCOUNT equ 83
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDGAPDEFINITION equ 84
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_REPEATEDOUTPUT equ 85
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDOUTPUTSTREAMSTRIDE equ 86
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGSEMANTIC equ 87
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MASKMISMATCH equ 88
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_CANTHAVEONLYGAPS equ 89
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DECLTOOCOMPLEX equ 90
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_MISSINGOUTPUTSIGNATURE equ 91
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_OUTOFMEMORY equ 92
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERBYTECODE equ 93
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDSHADERTYPE equ 94
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFILLMODE equ 95
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDCULLMODE equ 96
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDDEPTHBIASCLAMP equ 97
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDSLOPESCALEDDEPTHBIAS equ 98
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHWRITEMASK equ 100
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDDEPTHFUNC equ 101
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFAILOP equ 102
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILZFAILOP equ 103
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILPASSOP equ 104
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDFRONTFACESTENCILFUNC equ 105
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFAILOP equ 106
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILZFAILOP equ 107
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILPASSOP equ 108
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_INVALIDBACKFACESTENCILFUNC equ 109
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLEND equ 111
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLEND equ 112
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOP equ 113
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDSRCBLENDALPHA equ 114
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDDESTBLENDALPHA equ 115
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDBLENDOPALPHA equ 116
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDRENDERTARGETWRITEMASK equ 117
    D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_INVALID equ 135
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_NOT_SET equ 200
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ROOT_SIGNATURE_MISMATCH equ 201
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_NOT_SET equ 202
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_STRIDE_TOO_SMALL equ 209
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_BUFFER_TOO_SMALL equ 210
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_NOT_SET equ 211
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_FORMAT_INVALID equ 212
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_BUFFER_TOO_SMALL equ 213
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INVALID_PRIMITIVETOPOLOGY equ 219
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_VERTEX_STRIDE_UNALIGNED equ 221
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_INDEX_OFFSET_UNALIGNED equ 222
    D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_AT_FAULT equ 232
    D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_POSSIBLY_AT_FAULT equ 233
    D3D12_MESSAGE_ID_DEVICE_REMOVAL_PROCESS_NOT_AT_FAULT equ 234
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TRAILING_DIGIT_IN_SEMANTIC equ 239
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_TRAILING_DIGIT_IN_SEMANTIC equ 240
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_TYPE_MISMATCH equ 245
    D3D12_MESSAGE_ID_CREATEINPUTLAYOUT_EMPTY_LAYOUT equ 253
    D3D12_MESSAGE_ID_LIVE_OBJECT_SUMMARY equ 255
    D3D12_MESSAGE_ID_LIVE_DEVICE equ 274
    D3D12_MESSAGE_ID_LIVE_SWAPCHAIN equ 275
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILVIEW_INVALIDFLAGS equ 276
    D3D12_MESSAGE_ID_CREATEVERTEXSHADER_INVALIDCLASSLINKAGE equ 277
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADER_INVALIDCLASSLINKAGE equ 278
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAMTORASTERIZER equ 280
    D3D12_MESSAGE_ID_CREATEPIXELSHADER_INVALIDCLASSLINKAGE equ 283
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDSTREAM equ 284
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDENTRIES equ 285
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UNEXPECTEDSTRIDES equ 286
    D3D12_MESSAGE_ID_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_INVALIDNUMSTRIDES equ 287
    D3D12_MESSAGE_ID_CREATEHULLSHADER_OUTOFMEMORY equ 289
    D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERBYTECODE equ 290
    D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDSHADERTYPE equ 291
    D3D12_MESSAGE_ID_CREATEHULLSHADER_INVALIDCLASSLINKAGE equ 292
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_OUTOFMEMORY equ 294
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERBYTECODE equ 295
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDSHADERTYPE equ 296
    D3D12_MESSAGE_ID_CREATEDOMAINSHADER_INVALIDCLASSLINKAGE equ 297
    D3D12_MESSAGE_ID_RESOURCE_UNMAP_NOTMAPPED equ 310
    D3D12_MESSAGE_ID_DEVICE_CHECKFEATURESUPPORT_MISMATCHED_DATA_SIZE equ 318
    D3D12_MESSAGE_ID_CREATECOMPUTESHADER_OUTOFMEMORY equ 321
    D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDSHADERBYTECODE equ 322
    D3D12_MESSAGE_ID_CREATECOMPUTESHADER_INVALIDCLASSLINKAGE equ 323
    D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEFLOATOPSNOTSUPPORTED equ 331
    D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEFLOATOPSNOTSUPPORTED equ 332
    D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEFLOATOPSNOTSUPPORTED equ 333
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEFLOATOPSNOTSUPPORTED equ 334
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEFLOATOPSNOTSUPPORTED equ 335
    D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEFLOATOPSNOTSUPPORTED equ 336
    D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEFLOATOPSNOTSUPPORTED equ 337
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDRESOURCE equ 340
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDESC equ 341
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFORMAT equ 342
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDVIDEOPLANESLICE equ 343
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDPLANESLICE equ 344
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDDIMENSIONS equ 345
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_UNRECOGNIZEDFORMAT equ 346
    D3D12_MESSAGE_ID_CREATEUNORDEREDACCESSVIEW_INVALIDFLAGS equ 354
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALIDFORCEDSAMPLECOUNT equ 401
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_INVALIDLOGICOPS equ 403
    D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_DOUBLEEXTENSIONSNOTSUPPORTED equ 410
    D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_DOUBLEEXTENSIONSNOTSUPPORTED equ 412
    D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_DOUBLEEXTENSIONSNOTSUPPORTED equ 414
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_DOUBLEEXTENSIONSNOTSUPPORTED equ 416
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_DOUBLEEXTENSIONSNOTSUPPORTED equ 418
    D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_DOUBLEEXTENSIONSNOTSUPPORTED equ 420
    D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_DOUBLEEXTENSIONSNOTSUPPORTED equ 422
    D3D12_MESSAGE_ID_DEVICE_CREATEVERTEXSHADER_UAVSNOTSUPPORTED equ 425
    D3D12_MESSAGE_ID_DEVICE_CREATEHULLSHADER_UAVSNOTSUPPORTED equ 426
    D3D12_MESSAGE_ID_DEVICE_CREATEDOMAINSHADER_UAVSNOTSUPPORTED equ 427
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADER_UAVSNOTSUPPORTED equ 428
    D3D12_MESSAGE_ID_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT_UAVSNOTSUPPORTED equ 429
    D3D12_MESSAGE_ID_DEVICE_CREATEPIXELSHADER_UAVSNOTSUPPORTED equ 430
    D3D12_MESSAGE_ID_DEVICE_CREATECOMPUTESHADER_UAVSNOTSUPPORTED equ 431
    D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_INVALIDSOURCERECT equ 447
    D3D12_MESSAGE_ID_DEVICE_CLEARVIEW_EMPTYRECT equ 448
    D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_INVALID_PARAMETER equ 493
    D3D12_MESSAGE_ID_COPYTILEMAPPINGS_INVALID_PARAMETER equ 494
    D3D12_MESSAGE_ID_CREATEDEVICE_INVALIDARGS equ 506
    D3D12_MESSAGE_ID_CREATEDEVICE_WARNING equ 507
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_TYPE equ 519
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_NULL_POINTER equ 520
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SUBRESOURCE equ 521
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_RESERVED_BITS equ 522
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISSING_BIND_FLAGS equ 523
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_MISC_FLAGS equ 524
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MATCHING_STATES equ 525
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINATION equ 526
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_BEFORE_AFTER_MISMATCH equ 527
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_RESOURCE equ 528
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_SAMPLE_COUNT equ 529
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS equ 530
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMBINED_FLAGS equ 531
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAGS_FOR_FORMAT equ 532
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_SPLIT_BARRIER equ 533
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_END equ 534
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_UNMATCHED_BEGIN equ 535
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_FLAG equ 536
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_COMMAND_LIST_TYPE equ 537
    D3D12_MESSAGE_ID_INVALID_SUBRESOURCE_STATE equ 538
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CONTENTION equ 540
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET equ 541
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_RESET_BUNDLE equ 542
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_CANNOT_RESET equ 543
    D3D12_MESSAGE_ID_COMMAND_LIST_OPEN equ 544
    D3D12_MESSAGE_ID_INVALID_BUNDLE_API equ 546
    D3D12_MESSAGE_ID_COMMAND_LIST_CLOSED equ 547
    D3D12_MESSAGE_ID_WRONG_COMMAND_ALLOCATOR_TYPE equ 549
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_SYNC equ 552
    D3D12_MESSAGE_ID_COMMAND_LIST_SYNC equ 553
    D3D12_MESSAGE_ID_SET_DESCRIPTOR_HEAP_INVALID equ 554
    D3D12_MESSAGE_ID_CREATE_COMMANDQUEUE equ 557
    D3D12_MESSAGE_ID_CREATE_COMMANDALLOCATOR equ 558
    D3D12_MESSAGE_ID_CREATE_PIPELINESTATE equ 559
    D3D12_MESSAGE_ID_CREATE_COMMANDLIST12 equ 560
    D3D12_MESSAGE_ID_CREATE_RESOURCE equ 562
    D3D12_MESSAGE_ID_CREATE_DESCRIPTORHEAP equ 563
    D3D12_MESSAGE_ID_CREATE_ROOTSIGNATURE equ 564
    D3D12_MESSAGE_ID_CREATE_LIBRARY equ 565
    D3D12_MESSAGE_ID_CREATE_HEAP equ 566
    D3D12_MESSAGE_ID_CREATE_MONITOREDFENCE equ 567
    D3D12_MESSAGE_ID_CREATE_QUERYHEAP equ 568
    D3D12_MESSAGE_ID_CREATE_COMMANDSIGNATURE equ 569
    D3D12_MESSAGE_ID_LIVE_COMMANDQUEUE equ 570
    D3D12_MESSAGE_ID_LIVE_COMMANDALLOCATOR equ 571
    D3D12_MESSAGE_ID_LIVE_PIPELINESTATE equ 572
    D3D12_MESSAGE_ID_LIVE_COMMANDLIST12 equ 573
    D3D12_MESSAGE_ID_LIVE_RESOURCE equ 575
    D3D12_MESSAGE_ID_LIVE_DESCRIPTORHEAP equ 576
    D3D12_MESSAGE_ID_LIVE_ROOTSIGNATURE equ 577
    D3D12_MESSAGE_ID_LIVE_LIBRARY equ 578
    D3D12_MESSAGE_ID_LIVE_HEAP equ 579
    D3D12_MESSAGE_ID_LIVE_MONITOREDFENCE equ 580
    D3D12_MESSAGE_ID_LIVE_QUERYHEAP equ 581
    D3D12_MESSAGE_ID_LIVE_COMMANDSIGNATURE equ 582
    D3D12_MESSAGE_ID_DESTROY_COMMANDQUEUE equ 583
    D3D12_MESSAGE_ID_DESTROY_COMMANDALLOCATOR equ 584
    D3D12_MESSAGE_ID_DESTROY_PIPELINESTATE equ 585
    D3D12_MESSAGE_ID_DESTROY_COMMANDLIST12 equ 586
    D3D12_MESSAGE_ID_DESTROY_RESOURCE equ 588
    D3D12_MESSAGE_ID_DESTROY_DESCRIPTORHEAP equ 589
    D3D12_MESSAGE_ID_DESTROY_ROOTSIGNATURE equ 590
    D3D12_MESSAGE_ID_DESTROY_LIBRARY equ 591
    D3D12_MESSAGE_ID_DESTROY_HEAP equ 592
    D3D12_MESSAGE_ID_DESTROY_MONITOREDFENCE equ 593
    D3D12_MESSAGE_ID_DESTROY_QUERYHEAP equ 594
    D3D12_MESSAGE_ID_DESTROY_COMMANDSIGNATURE equ 595
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONS equ 597
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMISCFLAGS equ 599
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDARG_RETURN equ 602
    D3D12_MESSAGE_ID_CREATERESOURCE_OUTOFMEMORY_RETURN equ 603
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDESC equ 604
    D3D12_MESSAGE_ID_POSSIBLY_INVALID_SUBRESOURCE_STATE equ 607
    D3D12_MESSAGE_ID_INVALID_USE_OF_NON_RESIDENT_RESOURCE equ 608
    D3D12_MESSAGE_ID_POSSIBLE_INVALID_USE_OF_NON_RESIDENT_RESOURCE equ 609
    D3D12_MESSAGE_ID_BUNDLE_PIPELINE_STATE_MISMATCH equ 610
    D3D12_MESSAGE_ID_PRIMITIVE_TOPOLOGY_MISMATCH_PIPELINE_STATE equ 611
    D3D12_MESSAGE_ID_RENDER_TARGET_FORMAT_MISMATCH_PIPELINE_STATE equ 613
    D3D12_MESSAGE_ID_RENDER_TARGET_SAMPLE_DESC_MISMATCH_PIPELINE_STATE equ 614
    D3D12_MESSAGE_ID_DEPTH_STENCIL_FORMAT_MISMATCH_PIPELINE_STATE equ 615
    D3D12_MESSAGE_ID_DEPTH_STENCIL_SAMPLE_DESC_MISMATCH_PIPELINE_STATE equ 616
    D3D12_MESSAGE_ID_CREATESHADER_INVALIDBYTECODE equ 622
    D3D12_MESSAGE_ID_CREATEHEAP_NULLDESC equ 623
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDSIZE equ 624
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDHEAPTYPE equ 625
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES equ 626
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMEMORYPOOL equ 627
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDPROPERTIES equ 628
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDALIGNMENT equ 629
    D3D12_MESSAGE_ID_CREATEHEAP_UNRECOGNIZEDMISCFLAGS equ 630
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDMISCFLAGS equ 631
    D3D12_MESSAGE_ID_CREATEHEAP_INVALIDARG_RETURN equ 632
    D3D12_MESSAGE_ID_CREATEHEAP_OUTOFMEMORY_RETURN equ 633
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAPPROPERTIES equ 634
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPTYPE equ 635
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDCPUPAGEPROPERTIES equ 636
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDMEMORYPOOL equ 637
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPPROPERTIES equ 638
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_UNRECOGNIZEDHEAPMISCFLAGS equ 639
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDHEAPMISCFLAGS equ 640
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALIDARG_RETURN equ 641
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_OUTOFMEMORY_RETURN equ 642
    D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_UNRECOGNIZEDHEAPTYPE equ 643
    D3D12_MESSAGE_ID_GETCUSTOMHEAPPROPERTIES_INVALIDHEAPTYPE equ 644
    D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_INVALID_DESC equ 645
    D3D12_MESSAGE_ID_INVALID_DESCRIPTOR_HANDLE equ 646
    D3D12_MESSAGE_ID_CREATERASTERIZERSTATE_INVALID_CONSERVATIVERASTERMODE equ 647
    D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_RESOURCE equ 649
    D3D12_MESSAGE_ID_CREATE_CONSTANT_BUFFER_VIEW_INVALID_DESC equ 650
    D3D12_MESSAGE_ID_CREATE_UNORDEREDACCESS_VIEW_INVALID_COUNTER_USAGE equ 652
    D3D12_MESSAGE_ID_COPY_DESCRIPTORS_INVALID_RANGES equ 653
    D3D12_MESSAGE_ID_COPY_DESCRIPTORS_WRITE_ONLY_DESCRIPTOR equ 654
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RTV_FORMAT_NOT_UNKNOWN equ 655
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_RENDER_TARGET_COUNT equ 656
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VERTEX_SHADER_NOT_SET equ 657
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_NOT_SET equ 658
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_HS_DS_SIGNATURE_MISMATCH equ 659
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERINDEX equ 660
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_COMPONENTTYPE equ 661
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_REGISTERMASK equ 662
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SYSTEMVALUE equ 663
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_NEVERWRITTEN_ALWAYSREADS equ 664
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_MINPRECISION equ 665
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_LINKAGE_SEMANTICNAME_NOT_FOUND equ 666
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_XOR_DS_MISMATCH equ 667
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HULL_SHADER_INPUT_TOPOLOGY_MISMATCH equ 668
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_CONTROL_POINT_COUNT_MISMATCH equ 669
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_DS_TESSELLATOR_DOMAIN_MISMATCH equ 670
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_CENTER_MULTISAMPLE_PATTERN equ 671
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_USE_OF_FORCED_SAMPLE_COUNT equ 672
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_PRIMITIVETOPOLOGY equ 673
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SYSTEMVALUE equ 674
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_DUAL_SOURCE_BLENDING_CAN_ONLY_HAVE_RENDER_TARGET_0 equ 675
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_BLENDING equ 676
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_TYPE_MISMATCH equ 677
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_OM_RENDER_TARGET_DOES_NOT_SUPPORT_LOGIC_OPS equ 678
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RENDERTARGETVIEW_NOT_SET equ 679
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DEPTHSTENCILVIEW_NOT_SET equ 680
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_INPUT_PRIMITIVE_MISMATCH equ 681
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_POSITION_NOT_PRESENT equ 682
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE_FLAGS equ 683
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_INDEX_BUFFER_PROPERTIES equ 684
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INVALID_SAMPLE_DESC equ 685
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_HS_ROOT_SIGNATURE_MISMATCH equ 686
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_DS_ROOT_SIGNATURE_MISMATCH equ 687
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VS_ROOT_SIGNATURE_MISMATCH equ 688
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_GS_ROOT_SIGNATURE_MISMATCH equ 689
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_ROOT_SIGNATURE_MISMATCH equ 690
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MISSING_ROOT_SIGNATURE equ 691
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_OPEN_BUNDLE equ 692
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_DESCRIPTOR_HEAP_MISMATCH equ 693
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_TYPE equ 694
    D3D12_MESSAGE_ID_DRAW_EMPTY_SCISSOR_RECTANGLE equ 695
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_BLOB_NOT_FOUND equ 696
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_DESERIALIZE_FAILED equ 697
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_INVALID_CONFIGURATION equ 698
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_SUPPORTED_ON_DEVICE equ 699
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLRESOURCEPROPERTIES equ 700
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_NULLHEAP equ 701
    D3D12_MESSAGE_ID_GETRESOURCEALLOCATIONINFO_INVALIDRDESCS equ 702
    D3D12_MESSAGE_ID_MAKERESIDENT_NULLOBJECTARRAY equ 703
    D3D12_MESSAGE_ID_EVICT_NULLOBJECTARRAY equ 705
    D3D12_MESSAGE_ID_SET_DESCRIPTOR_TABLE_INVALID equ 708
    D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_INVALID equ 709
    D3D12_MESSAGE_ID_SET_ROOT_CONSTANT_BUFFER_VIEW_INVALID equ 710
    D3D12_MESSAGE_ID_SET_ROOT_SHADER_RESOURCE_VIEW_INVALID equ 711
    D3D12_MESSAGE_ID_SET_ROOT_UNORDERED_ACCESS_VIEW_INVALID equ 712
    D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID_DESC equ 713
    D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID_DESC equ 715
    D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID_DESC equ 717
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDDIMENSIONALITY equ 718
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDLAYOUT equ 719
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDDIMENSIONALITY equ 720
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDALIGNMENT equ 721
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDMIPLEVELS equ 722
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDSAMPLEDESC equ 723
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDLAYOUT equ 724
    D3D12_MESSAGE_ID_SET_INDEX_BUFFER_INVALID equ 725
    D3D12_MESSAGE_ID_SET_VERTEX_BUFFERS_INVALID equ 726
    D3D12_MESSAGE_ID_SET_STREAM_OUTPUT_BUFFERS_INVALID equ 727
    D3D12_MESSAGE_ID_SET_RENDER_TARGETS_INVALID equ 728
    D3D12_MESSAGE_ID_CREATEQUERY_HEAP_INVALID_PARAMETERS equ 729
    D3D12_MESSAGE_ID_BEGIN_END_QUERY_INVALID_PARAMETERS equ 731
    D3D12_MESSAGE_ID_CLOSE_COMMAND_LIST_OPEN_QUERY equ 732
    D3D12_MESSAGE_ID_RESOLVE_QUERY_DATA_INVALID_PARAMETERS equ 733
    D3D12_MESSAGE_ID_SET_PREDICATION_INVALID_PARAMETERS equ 734
    D3D12_MESSAGE_ID_TIMESTAMPS_NOT_SUPPORTED equ 735
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDFORMAT equ 737
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDFORMAT equ 738
    D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDSUBRESOURCERANGE equ 739
    D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_INVALIDBASEOFFSET equ 740
    D3D12_MESSAGE_ID_GETCOPYABLELAYOUT_INVALIDSUBRESOURCERANGE equ 739
    D3D12_MESSAGE_ID_GETCOPYABLELAYOUT_INVALIDBASEOFFSET equ 740
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_INVALID_HEAP equ 741
    D3D12_MESSAGE_ID_CREATE_SAMPLER_INVALID equ 742
    D3D12_MESSAGE_ID_CREATECOMMANDSIGNATURE_INVALID equ 743
    D3D12_MESSAGE_ID_EXECUTE_INDIRECT_INVALID_PARAMETERS equ 744
    D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_RESOURCE_DIMENSION equ 745
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUE equ 815
    D3D12_MESSAGE_ID_CREATERESOURCE_UNRECOGNIZEDCLEARVALUEFORMAT equ 816
    D3D12_MESSAGE_ID_CREATERESOURCE_INVALIDCLEARVALUEFORMAT equ 817
    D3D12_MESSAGE_ID_CREATERESOURCE_CLEARVALUEDENORMFLUSH equ 818
    D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE equ 820
    D3D12_MESSAGE_ID_CLEARDEPTHSTENCILVIEW_MISMATCHINGCLEARVALUE equ 821
    D3D12_MESSAGE_ID_MAP_INVALIDHEAP equ 822
    D3D12_MESSAGE_ID_UNMAP_INVALIDHEAP equ 823
    D3D12_MESSAGE_ID_MAP_INVALIDRESOURCE equ 824
    D3D12_MESSAGE_ID_UNMAP_INVALIDRESOURCE equ 825
    D3D12_MESSAGE_ID_MAP_INVALIDSUBRESOURCE equ 826
    D3D12_MESSAGE_ID_UNMAP_INVALIDSUBRESOURCE equ 827
    D3D12_MESSAGE_ID_MAP_INVALIDRANGE equ 828
    D3D12_MESSAGE_ID_UNMAP_INVALIDRANGE equ 829
    D3D12_MESSAGE_ID_MAP_INVALIDDATAPOINTER equ 832
    D3D12_MESSAGE_ID_MAP_INVALIDARG_RETURN equ 833
    D3D12_MESSAGE_ID_MAP_OUTOFMEMORY_RETURN equ 834
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_BUNDLENOTSUPPORTED equ 835
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_COMMANDLISTMISMATCH equ 836
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_OPENCOMMANDLIST equ 837
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_FAILEDCOMMANDLIST equ 838
    D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLDST equ 839
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDDSTRESOURCEDIMENSION equ 840
    D3D12_MESSAGE_ID_COPYBUFFERREGION_DSTRANGEOUTOFBOUNDS equ 841
    D3D12_MESSAGE_ID_COPYBUFFERREGION_NULLSRC equ 842
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDSRCRESOURCEDIMENSION equ 843
    D3D12_MESSAGE_ID_COPYBUFFERREGION_SRCRANGEOUTOFBOUNDS equ 844
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALIDCOPYFLAGS equ 845
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLDST equ 846
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTTYPE equ 847
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCEDIMENSION equ 848
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTRESOURCE equ 849
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTSUBRESOURCE equ 850
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTOFFSET equ 851
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDDSTFORMAT equ 852
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTFORMAT equ 853
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDIMENSIONS equ 854
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTROWPITCH equ 855
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTPLACEMENT equ 856
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTDSPLACEDFOOTPRINTFORMAT equ 857
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_DSTREGIONOUTOFBOUNDS equ 858
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_NULLSRC equ 859
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCTYPE equ 860
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCEDIMENSION equ 861
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCRESOURCE equ 862
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCSUBRESOURCE equ 863
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCOFFSET equ 864
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_UNRECOGNIZEDSRCFORMAT equ 865
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCFORMAT equ 866
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDIMENSIONS equ 867
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCROWPITCH equ 868
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCPLACEMENT equ 869
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCDSPLACEDFOOTPRINTFORMAT equ 870
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_SRCREGIONOUTOFBOUNDS equ 871
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDDSTCOORDINATES equ 872
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDSRCBOX equ 873
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_FORMATMISMATCH equ 874
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_EMPTYBOX equ 875
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_INVALIDCOPYFLAGS equ 876
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SUBRESOURCE_INDEX equ 877
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_FORMAT equ 878
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_MISMATCH equ 879
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALID_SAMPLE_COUNT equ 880
    D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_INVALID_SHADER equ 881
    D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_CS_ROOT_SIGNATURE_MISMATCH equ 882
    D3D12_MESSAGE_ID_CREATECOMPUTEPIPELINESTATE_MISSING_ROOT_SIGNATURE equ 883
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALIDCACHEDBLOB equ 884
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBADAPTERMISMATCH equ 885
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDRIVERVERSIONMISMATCH equ 886
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBDESCMISMATCH equ 887
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CACHEDBLOBIGNORED equ 888
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDHEAP equ 889
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDRESOURCE equ 890
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDBOX equ 891
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_INVALIDSUBRESOURCE equ 892
    D3D12_MESSAGE_ID_WRITETOSUBRESOURCE_EMPTYBOX equ 893
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDHEAP equ 894
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDRESOURCE equ 895
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDBOX equ 896
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_INVALIDSUBRESOURCE equ 897
    D3D12_MESSAGE_ID_READFROMSUBRESOURCE_EMPTYBOX equ 898
    D3D12_MESSAGE_ID_TOO_MANY_NODES_SPECIFIED equ 899
    D3D12_MESSAGE_ID_INVALID_NODE_INDEX equ 900
    D3D12_MESSAGE_ID_GETHEAPPROPERTIES_INVALIDRESOURCE equ 901
    D3D12_MESSAGE_ID_NODE_MASK_MISMATCH equ 902
    D3D12_MESSAGE_ID_COMMAND_LIST_OUTOFMEMORY equ 903
    D3D12_MESSAGE_ID_COMMAND_LIST_MULTIPLE_SWAPCHAIN_BUFFER_REFERENCES equ 904
    D3D12_MESSAGE_ID_COMMAND_LIST_TOO_MANY_SWAPCHAIN_REFERENCES equ 905
    D3D12_MESSAGE_ID_COMMAND_QUEUE_TOO_MANY_SWAPCHAIN_REFERENCES equ 906
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_WRONGSWAPCHAINBUFFERREFERENCE equ 907
    D3D12_MESSAGE_ID_COMMAND_LIST_SETRENDERTARGETS_INVALIDNUMRENDERTARGETS equ 908
    D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_TYPE equ 909
    D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_FLAGS equ 910
    D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFLAGS equ 911
    D3D12_MESSAGE_ID_CREATESHAREDRESOURCE_INVALIDFORMAT equ 912
    D3D12_MESSAGE_ID_CREATESHAREDHEAP_INVALIDFLAGS equ 913
    D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_UNRECOGNIZEDPROPERTIES equ 914
    D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDSIZE equ 915
    D3D12_MESSAGE_ID_REFLECTSHAREDPROPERTIES_INVALIDOBJECT equ 916
    D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDOBJECT equ 917
    D3D12_MESSAGE_ID_KEYEDMUTEX_INVALIDKEY equ 918
    D3D12_MESSAGE_ID_KEYEDMUTEX_WRONGSTATE equ 919
    D3D12_MESSAGE_ID_CREATE_QUEUE_INVALID_PRIORITY equ 920
    D3D12_MESSAGE_ID_OBJECT_DELETED_WHILE_STILL_IN_USE equ 921
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_FLAGS equ 922
    D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_HAS_NO_RESOURCE equ 923
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_RENDER_TARGET_DELETED equ 924
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_ALL_RENDER_TARGETS_HAVE_UNKNOWN_FORMAT equ 925
    D3D12_MESSAGE_ID_HEAP_ADDRESS_RANGE_INTERSECTS_MULTIPLE_BUFFERS equ 926
    D3D12_MESSAGE_ID_EXECUTECOMMANDLISTS_GPU_WRITTEN_READBACK_RESOURCE_MAPPED equ 927
    D3D12_MESSAGE_ID_UNMAP_RANGE_NOT_EMPTY equ 929
    D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE equ 930
    D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE equ 931
    D3D12_MESSAGE_ID_NO_GRAPHICS_API_SUPPORT equ 932
    D3D12_MESSAGE_ID_NO_COMPUTE_API_SUPPORT equ 933
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_RESOURCE_FLAGS_NOT_SUPPORTED equ 934
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_ARGUMENT_UNINITIALIZED equ 935
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_HEAP_INDEX_OUT_OF_BOUNDS equ 936
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TABLE_REGISTER_INDEX_OUT_OF_BOUNDS equ 937
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_UNINITIALIZED equ 938
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_DESCRIPTOR_TYPE_MISMATCH equ 939
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SRV_RESOURCE_DIMENSION_MISMATCH equ 940
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UAV_RESOURCE_DIMENSION_MISMATCH equ 941
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INCOMPATIBLE_RESOURCE_STATE equ 942
    D3D12_MESSAGE_ID_COPYRESOURCE_NULLDST equ 943
    D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDDSTRESOURCE equ 944
    D3D12_MESSAGE_ID_COPYRESOURCE_NULLSRC equ 945
    D3D12_MESSAGE_ID_COPYRESOURCE_INVALIDSRCRESOURCE equ 946
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLDST equ 947
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDDSTRESOURCE equ 948
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_NULLSRC equ 949
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_INVALIDSRCRESOURCE equ 950
    D3D12_MESSAGE_ID_PIPELINE_STATE_TYPE_MISMATCH equ 951
    D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_NOT_SET equ 952
    D3D12_MESSAGE_ID_COMMAND_LIST_DISPATCH_ROOT_SIGNATURE_MISMATCH equ 953
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_ZERO_BARRIERS equ 954
    D3D12_MESSAGE_ID_BEGIN_END_EVENT_MISMATCH equ 955
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_POSSIBLE_BEFORE_AFTER_MISMATCH equ 956
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_BEGIN_END equ 957
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_INVALID_RESOURCE equ 958
    D3D12_MESSAGE_ID_USE_OF_ZERO_REFCOUNT_OBJECT equ 959
    D3D12_MESSAGE_ID_OBJECT_EVICTED_WHILE_STILL_IN_USE equ 960
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_ROOT_DESCRIPTOR_ACCESS_OUT_OF_BOUNDS equ 961
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_INVALIDLIBRARYBLOB equ 962
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_DRIVERVERSIONMISMATCH equ 963
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_ADAPTERVERSIONMISMATCH equ 964
    D3D12_MESSAGE_ID_CREATEPIPELINELIBRARY_UNSUPPORTED equ 965
    D3D12_MESSAGE_ID_CREATE_PIPELINELIBRARY equ 966
    D3D12_MESSAGE_ID_LIVE_PIPELINELIBRARY equ 967
    D3D12_MESSAGE_ID_DESTROY_PIPELINELIBRARY equ 968
    D3D12_MESSAGE_ID_STOREPIPELINE_NONAME equ 969
    D3D12_MESSAGE_ID_STOREPIPELINE_DUPLICATENAME equ 970
    D3D12_MESSAGE_ID_LOADPIPELINE_NAMENOTFOUND equ 971
    D3D12_MESSAGE_ID_LOADPIPELINE_INVALIDDESC equ 972
    D3D12_MESSAGE_ID_PIPELINELIBRARY_SERIALIZE_NOTENOUGHMEMORY equ 973
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_PS_OUTPUT_RT_OUTPUT_MISMATCH equ 974
    D3D12_MESSAGE_ID_SETEVENTONMULTIPLEFENCECOMPLETION_INVALIDFLAGS equ 975
    D3D12_MESSAGE_ID_CREATE_QUEUE_VIDEO_NOT_SUPPORTED equ 976
    D3D12_MESSAGE_ID_CREATE_COMMAND_ALLOCATOR_VIDEO_NOT_SUPPORTED equ 977
    D3D12_MESSAGE_ID_CREATEQUERY_HEAP_VIDEO_DECODE_STATISTICS_NOT_SUPPORTED equ 978
    D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDLIST equ 979
    D3D12_MESSAGE_ID_CREATE_VIDEODECODER equ 980
    D3D12_MESSAGE_ID_CREATE_VIDEODECODESTREAM equ 981
    D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDLIST equ 982
    D3D12_MESSAGE_ID_LIVE_VIDEODECODER equ 983
    D3D12_MESSAGE_ID_LIVE_VIDEODECODESTREAM equ 984
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDLIST equ 985
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODER equ 986
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODESTREAM equ 987
    D3D12_MESSAGE_ID_DECODE_FRAME_INVALID_PARAMETERS equ 988
    D3D12_MESSAGE_ID_DEPRECATED_API equ 989
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_MISMATCHING_COMMAND_LIST_TYPE equ 990
    D3D12_MESSAGE_ID_COMMAND_LIST_DESCRIPTOR_TABLE_NOT_SET equ 991
    D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_CONSTANT_BUFFER_VIEW_NOT_SET equ 992
    D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_SHADER_RESOURCE_VIEW_NOT_SET equ 993
    D3D12_MESSAGE_ID_COMMAND_LIST_ROOT_UNORDERED_ACCESS_VIEW_NOT_SET equ 994
    D3D12_MESSAGE_ID_DISCARD_INVALID_SUBRESOURCE_RANGE equ 995
    D3D12_MESSAGE_ID_DISCARD_ONE_SUBRESOURCE_FOR_MIPS_WITH_RECTS equ 996
    D3D12_MESSAGE_ID_DISCARD_NO_RECTS_FOR_NON_TEXTURE2D equ 997
    D3D12_MESSAGE_ID_COPY_ON_SAME_SUBRESOURCE equ 998
    D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PAGEABLE equ 999
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_UNSUPPORTED equ 1000
    D3D12_MESSAGE_ID_STATIC_DESCRIPTOR_INVALID_DESCRIPTOR_CHANGE equ 1001
    D3D12_MESSAGE_ID_DATA_STATIC_DESCRIPTOR_INVALID_DATA_CHANGE equ 1002
    D3D12_MESSAGE_ID_DATA_STATIC_WHILE_SET_AT_EXECUTE_DESCRIPTOR_INVALID_DATA_CHANGE equ 1003
    D3D12_MESSAGE_ID_EXECUTE_BUNDLE_STATIC_DESCRIPTOR_DATA_STATIC_NOT_SET equ 1004
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_ACCESS_OUT_OF_BOUNDS equ 1005
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_SAMPLER_MODE_MISMATCH equ 1006
    D3D12_MESSAGE_ID_CREATE_FENCE_INVALID_FLAGS equ 1007
    D3D12_MESSAGE_ID_RESOURCE_BARRIER_DUPLICATE_SUBRESOURCE_TRANSITIONS equ 1008
    D3D12_MESSAGE_ID_SETRESIDENCYPRIORITY_INVALID_PRIORITY equ 1009
    D3D12_MESSAGE_ID_CREATE_DESCRIPTOR_HEAP_LARGE_NUM_DESCRIPTORS equ 1013
    D3D12_MESSAGE_ID_BEGIN_EVENT equ 1014
    D3D12_MESSAGE_ID_END_EVENT equ 1015
    D3D12_MESSAGE_ID_CREATEDEVICE_DEBUG_LAYER_STARTUP_OPTIONS equ 1016
    D3D12_MESSAGE_ID_CREATEDEPTHSTENCILSTATE_DEPTHBOUNDSTEST_UNSUPPORTED equ 1017
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_DUPLICATE_SUBOBJECT equ 1018
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_UNKNOWN_SUBOBJECT equ 1019
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_ZERO_SIZE_STREAM equ 1020
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_INVALID_STREAM equ 1021
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_CANNOT_DEDUCE_TYPE equ 1022
    D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_RESOURCE_DIMENSION_MISMATCH equ 1023
    D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_PRIVILEGE_FOR_GLOBAL_REALTIME equ 1024
    D3D12_MESSAGE_ID_CREATE_COMMAND_QUEUE_INSUFFICIENT_HARDWARE_SUPPORT_FOR_GLOBAL_REALTIME equ 1025
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_ARCHITECTURE equ 1026
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DST equ 1027
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE_DIMENSION equ 1028
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DST_RANGE_OUT_OF_BOUNDS equ 1029
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_SRC equ 1030
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE_DIMENSION equ 1031
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_SRC_RANGE_OUT_OF_BOUNDS equ 1032
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_OFFSET_ALIGNMENT equ 1033
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_RESOURCES equ 1034
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_NULL_DEPENDENT_SUBRESOURCE_RANGES equ 1035
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_RESOURCE equ 1036
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DEPENDENT_SUBRESOURCE_RANGE equ 1037
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_SUBRESOURCE_OUT_OF_BOUNDS equ 1038
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_DEPENDENT_RANGE_OUT_OF_BOUNDS equ 1039
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_ZERO_DEPENDENCIES equ 1040
    D3D12_MESSAGE_ID_DEVICE_CREATE_SHARED_HANDLE_INVALIDARG equ 1041
    D3D12_MESSAGE_ID_DESCRIPTOR_HANDLE_WITH_INVALID_RESOURCE equ 1042
    D3D12_MESSAGE_ID_SETDEPTHBOUNDS_INVALIDARGS equ 1043
    D3D12_MESSAGE_ID_GPU_BASED_VALIDATION_RESOURCE_STATE_IMPRECISE equ 1044
    D3D12_MESSAGE_ID_COMMAND_LIST_PIPELINE_STATE_NOT_SET equ 1045
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_SHADER_MODEL_MISMATCH equ 1046
    D3D12_MESSAGE_ID_OBJECT_ACCESSED_WHILE_STILL_IN_USE equ 1047
    D3D12_MESSAGE_ID_PROGRAMMABLE_MSAA_UNSUPPORTED equ 1048
    D3D12_MESSAGE_ID_SETSAMPLEPOSITIONS_INVALIDARGS equ 1049
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCEREGION_INVALID_RECT equ 1050
    D3D12_MESSAGE_ID_CREATE_VIDEODECODECOMMANDQUEUE equ 1051
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDLIST equ 1052
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSCOMMANDQUEUE equ 1053
    D3D12_MESSAGE_ID_LIVE_VIDEODECODECOMMANDQUEUE equ 1054
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDLIST equ 1055
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSCOMMANDQUEUE equ 1056
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODECOMMANDQUEUE equ 1057
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDLIST equ 1058
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSCOMMANDQUEUE equ 1059
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSOR equ 1060
    D3D12_MESSAGE_ID_CREATE_VIDEOPROCESSSTREAM equ 1061
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSOR equ 1062
    D3D12_MESSAGE_ID_LIVE_VIDEOPROCESSSTREAM equ 1063
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSOR equ 1064
    D3D12_MESSAGE_ID_DESTROY_VIDEOPROCESSSTREAM equ 1065
    D3D12_MESSAGE_ID_PROCESS_FRAME_INVALID_PARAMETERS equ 1066
    D3D12_MESSAGE_ID_COPY_INVALIDLAYOUT equ 1067
    D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION equ 1068
    D3D12_MESSAGE_ID_CREATE_CRYPTO_SESSION_POLICY equ 1069
    D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION equ 1070
    D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION equ 1071
    D3D12_MESSAGE_ID_LIVE_CRYPTO_SESSION_POLICY equ 1072
    D3D12_MESSAGE_ID_LIVE_PROTECTED_RESOURCE_SESSION equ 1073
    D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION equ 1074
    D3D12_MESSAGE_ID_DESTROY_CRYPTO_SESSION_POLICY equ 1075
    D3D12_MESSAGE_ID_DESTROY_PROTECTED_RESOURCE_SESSION equ 1076
    D3D12_MESSAGE_ID_PROTECTED_RESOURCE_SESSION_UNSUPPORTED equ 1077
    D3D12_MESSAGE_ID_FENCE_INVALIDOPERATION equ 1078
    D3D12_MESSAGE_ID_CREATEQUERY_HEAP_COPY_QUEUE_TIMESTAMPS_NOT_SUPPORTED equ 1079
    D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_DEFERRED equ 1080
    D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMFIRSTUSE equ 1081
    D3D12_MESSAGE_ID_SAMPLEPOSITIONS_MISMATCH_RECORDTIME_ASSUMEDFROMCLEAR equ 1082
    D3D12_MESSAGE_ID_CREATE_VIDEODECODERHEAP equ 1083
    D3D12_MESSAGE_ID_LIVE_VIDEODECODERHEAP equ 1084
    D3D12_MESSAGE_ID_DESTROY_VIDEODECODERHEAP equ 1085
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDARG_RETURN equ 1086
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_OUTOFMEMORY_RETURN equ 1087
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDADDRESS equ 1088
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_INVALIDHANDLE equ 1089
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_DEST equ 1090
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_MODE equ 1091
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_INVALID_ALIGNMENT equ 1092
    D3D12_MESSAGE_ID_WRITEBUFFERIMMEDIATE_NOT_SUPPORTED equ 1093
    D3D12_MESSAGE_ID_SETVIEWINSTANCEMASK_INVALIDARGS equ 1094
    D3D12_MESSAGE_ID_VIEW_INSTANCING_UNSUPPORTED equ 1095
    D3D12_MESSAGE_ID_VIEW_INSTANCING_INVALIDARGS equ 1096
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_DECODE_REFERENCE_ONLY_FLAG equ 1097
    D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_DECODE_REFERENCE_ONLY_FLAG equ 1098
    D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_FAILURE equ 1099
    D3D12_MESSAGE_ID_CREATE_VIDEO_DECODE_HEAP_CAPS_UNSUPPORTED equ 1100
    D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_INVALID_INPUT equ 1101
    D3D12_MESSAGE_ID_CREATE_VIDEO_DECODER_UNSUPPORTED equ 1102
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_METADATA_ERROR equ 1103
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_VIEW_INSTANCING_VERTEX_SIZE_EXCEEDED equ 1104
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_RUNTIME_INTERNAL_ERROR equ 1105
    D3D12_MESSAGE_ID_NO_VIDEO_API_SUPPORT equ 1106
    D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_INVALID_INPUT equ 1107
    D3D12_MESSAGE_ID_CREATE_VIDEO_PROCESSOR_CAPS_FAILURE equ 1108
    D3D12_MESSAGE_ID_VIDEO_PROCESS_SUPPORT_UNSUPPORTED_FORMAT equ 1109
    D3D12_MESSAGE_ID_VIDEO_DECODE_FRAME_INVALID_ARGUMENT equ 1110
    D3D12_MESSAGE_ID_ENQUEUE_MAKE_RESIDENT_INVALID_FLAGS equ 1111
    D3D12_MESSAGE_ID_OPENEXISTINGHEAP_UNSUPPORTED equ 1112
    D3D12_MESSAGE_ID_VIDEO_PROCESS_FRAMES_INVALID_ARGUMENT equ 1113
    D3D12_MESSAGE_ID_VIDEO_DECODE_SUPPORT_UNSUPPORTED equ 1114
    D3D12_MESSAGE_ID_CREATE_COMMANDRECORDER equ 1115
    D3D12_MESSAGE_ID_LIVE_COMMANDRECORDER equ 1116
    D3D12_MESSAGE_ID_DESTROY_COMMANDRECORDER equ 1117
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_VIDEO_NOT_SUPPORTED equ 1118
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_SUPPORT_FLAGS equ 1119
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_INVALID_FLAGS equ 1120
    D3D12_MESSAGE_ID_CREATE_COMMAND_RECORDER_MORE_RECORDERS_THAN_LOGICAL_PROCESSORS equ 1121
    D3D12_MESSAGE_ID_CREATE_COMMANDPOOL equ 1122
    D3D12_MESSAGE_ID_LIVE_COMMANDPOOL equ 1123
    D3D12_MESSAGE_ID_DESTROY_COMMANDPOOL equ 1124
    D3D12_MESSAGE_ID_CREATE_COMMAND_POOL_INVALID_FLAGS equ 1125
    D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_VIDEO_NOT_SUPPORTED equ 1126
    D3D12_MESSAGE_ID_COMMAND_RECORDER_SUPPORT_FLAGS_MISMATCH equ 1127
    D3D12_MESSAGE_ID_COMMAND_RECORDER_CONTENTION equ 1128
    D3D12_MESSAGE_ID_COMMAND_RECORDER_USAGE_WITH_CREATECOMMANDLIST_COMMAND_LIST equ 1129
    D3D12_MESSAGE_ID_COMMAND_ALLOCATOR_USAGE_WITH_CREATECOMMANDLIST1_COMMAND_LIST equ 1130
    D3D12_MESSAGE_ID_CANNOT_EXECUTE_EMPTY_COMMAND_LIST equ 1131
    D3D12_MESSAGE_ID_CANNOT_RESET_COMMAND_POOL_WITH_OPEN_COMMAND_LISTS equ 1132
    D3D12_MESSAGE_ID_CANNOT_USE_COMMAND_RECORDER_WITHOUT_CURRENT_TARGET equ 1133
    D3D12_MESSAGE_ID_CANNOT_CHANGE_COMMAND_RECORDER_TARGET_WHILE_RECORDING equ 1134
    D3D12_MESSAGE_ID_COMMAND_POOL_SYNC equ 1135
    D3D12_MESSAGE_ID_EVICT_UNDERFLOW equ 1136
    D3D12_MESSAGE_ID_CREATE_META_COMMAND equ 1137
    D3D12_MESSAGE_ID_LIVE_META_COMMAND equ 1138
    D3D12_MESSAGE_ID_DESTROY_META_COMMAND equ 1139
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_DST_RESOURCE equ 1140
    D3D12_MESSAGE_ID_COPYBUFFERREGION_INVALID_SRC_RESOURCE equ 1141
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_DST_RESOURCE equ 1142
    D3D12_MESSAGE_ID_ATOMICCOPYBUFFER_INVALID_SRC_RESOURCE equ 1143
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_BUFFER equ 1144
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_NULL_RESOURCE_DESC equ 1145
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_UNSUPPORTED equ 1146
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_DIMENSION equ 1147
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_FLAGS equ 1148
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_BUFFER_OFFSET equ 1149
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_DIMENSION equ 1150
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_INVALID_RESOURCE_FLAGS equ 1151
    D3D12_MESSAGE_ID_CREATEPLACEDRESOURCEONBUFFER_OUTOFMEMORY_RETURN equ 1152
    D3D12_MESSAGE_ID_CANNOT_CREATE_GRAPHICS_AND_VIDEO_COMMAND_RECORDER equ 1153
    D3D12_MESSAGE_ID_UPDATETILEMAPPINGS_POSSIBLY_MISMATCHING_PROPERTIES equ 1154
    D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE equ 1155
    D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INCOMPATIBLE_WITH_STRUCTURED_BUFFERS equ 1156
    D3D12_MESSAGE_ID_COMPUTE_ONLY_DEVICE_OPERATION_UNSUPPORTED equ 1157
    D3D12_MESSAGE_ID_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INVALID equ 1158
    D3D12_MESSAGE_ID_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_INVALID equ 1159
    D3D12_MESSAGE_ID_COPY_RAYTRACING_ACCELERATION_STRUCTURE_INVALID equ 1160
    D3D12_MESSAGE_ID_DISPATCH_RAYS_INVALID equ 1161
    D3D12_MESSAGE_ID_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_INVALID equ 1162
    D3D12_MESSAGE_ID_CREATE_LIFETIMETRACKER equ 1163
    D3D12_MESSAGE_ID_LIVE_LIFETIMETRACKER equ 1164
    D3D12_MESSAGE_ID_DESTROY_LIFETIMETRACKER equ 1165
    D3D12_MESSAGE_ID_DESTROYOWNEDOBJECT_OBJECTNOTOWNED equ 1166
    D3D12_MESSAGE_ID_CREATE_TRACKEDWORKLOAD equ 1167
    D3D12_MESSAGE_ID_LIVE_TRACKEDWORKLOAD equ 1168
    D3D12_MESSAGE_ID_DESTROY_TRACKEDWORKLOAD equ 1169
    D3D12_MESSAGE_ID_RENDER_PASS_ERROR equ 1170
    D3D12_MESSAGE_ID_META_COMMAND_ID_INVALID equ 1171
    D3D12_MESSAGE_ID_META_COMMAND_UNSUPPORTED_PARAMS equ 1172
    D3D12_MESSAGE_ID_META_COMMAND_FAILED_ENUMERATION equ 1173
    D3D12_MESSAGE_ID_META_COMMAND_PARAMETER_SIZE_MISMATCH equ 1174
    D3D12_MESSAGE_ID_UNINITIALIZED_META_COMMAND equ 1175
    D3D12_MESSAGE_ID_META_COMMAND_INVALID_GPU_VIRTUAL_ADDRESS equ 1176
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDLIST equ 1177
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDLIST equ 1178
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDLIST equ 1179
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODECOMMANDQUEUE equ 1180
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODECOMMANDQUEUE equ 1181
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODECOMMANDQUEUE equ 1182
    D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONESTIMATOR equ 1183
    D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONESTIMATOR equ 1184
    D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONESTIMATOR equ 1185
    D3D12_MESSAGE_ID_CREATE_VIDEOMOTIONVECTORHEAP equ 1186
    D3D12_MESSAGE_ID_LIVE_VIDEOMOTIONVECTORHEAP equ 1187
    D3D12_MESSAGE_ID_DESTROY_VIDEOMOTIONVECTORHEAP equ 1188
    D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOADS equ 1189
    D3D12_MESSAGE_ID_MULTIPLE_TRACKED_WORKLOAD_PAIRS equ 1190
    D3D12_MESSAGE_ID_OUT_OF_ORDER_TRACKED_WORKLOAD_PAIR equ 1191
    D3D12_MESSAGE_ID_CANNOT_ADD_TRACKED_WORKLOAD equ 1192
    D3D12_MESSAGE_ID_INCOMPLETE_TRACKED_WORKLOAD_PAIR equ 1193
    D3D12_MESSAGE_ID_CREATE_STATE_OBJECT_ERROR equ 1194
    D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_ERROR equ 1195
    D3D12_MESSAGE_ID_GET_SHADER_STACK_SIZE_ERROR equ 1196
    D3D12_MESSAGE_ID_GET_PIPELINE_STACK_SIZE_ERROR equ 1197
    D3D12_MESSAGE_ID_SET_PIPELINE_STACK_SIZE_ERROR equ 1198
    D3D12_MESSAGE_ID_GET_SHADER_IDENTIFIER_SIZE_INVALID equ 1199
    D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_INVALID equ 1200
    D3D12_MESSAGE_ID_CHECK_DRIVER_MATCHING_IDENTIFIER_DRIVER_REPORTED_ISSUE equ 1201
    D3D12_MESSAGE_ID_RENDER_PASS_INVALID_RESOURCE_BARRIER equ 1202
    D3D12_MESSAGE_ID_RENDER_PASS_DISALLOWED_API_CALLED equ 1203
    D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_NEST_RENDER_PASSES equ 1204
    D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_END_WITHOUT_BEGIN equ 1205
    D3D12_MESSAGE_ID_RENDER_PASS_CANNOT_CLOSE_COMMAND_LIST equ 1206
    D3D12_MESSAGE_ID_RENDER_PASS_GPU_WORK_WHILE_SUSPENDED equ 1207
    D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_SUSPEND_RESUME equ 1208
    D3D12_MESSAGE_ID_RENDER_PASS_NO_PRIOR_SUSPEND_WITHIN_EXECUTECOMMANDLISTS equ 1209
    D3D12_MESSAGE_ID_RENDER_PASS_NO_SUBSEQUENT_RESUME_WITHIN_EXECUTECOMMANDLISTS equ 1210
    D3D12_MESSAGE_ID_TRACKED_WORKLOAD_COMMAND_QUEUE_MISMATCH equ 1211
    D3D12_MESSAGE_ID_TRACKED_WORKLOAD_NOT_SUPPORTED equ 1212
    D3D12_MESSAGE_ID_RENDER_PASS_MISMATCHING_NO_ACCESS equ 1213
    D3D12_MESSAGE_ID_RENDER_PASS_UNSUPPORTED_RESOLVE equ 1214
    D3D12_MESSAGE_ID_CLEARUNORDEREDACCESSVIEW_INVALID_RESOURCE_PTR equ 1215
    D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_SIGNAL equ 1216
    D3D12_MESSAGE_ID_WINDOWS7_FENCE_OUTOFORDER_WAIT equ 1217
    D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_ESTIMATOR_INVALID_ARGUMENT equ 1218
    D3D12_MESSAGE_ID_VIDEO_CREATE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT equ 1219
    D3D12_MESSAGE_ID_ESTIMATE_MOTION_INVALID_ARGUMENT equ 1220
    D3D12_MESSAGE_ID_RESOLVE_MOTION_VECTOR_HEAP_INVALID_ARGUMENT equ 1221
    D3D12_MESSAGE_ID_GETGPUVIRTUALADDRESS_INVALID_HEAP_TYPE equ 1222
    D3D12_MESSAGE_ID_SET_BACKGROUND_PROCESSING_MODE_INVALID_ARGUMENT equ 1223
    D3D12_MESSAGE_ID_CREATE_COMMAND_LIST_INVALID_COMMAND_LIST_TYPE_FOR_FEATURE_LEVEL equ 1224
    D3D12_MESSAGE_ID_CREATE_VIDEOEXTENSIONCOMMAND equ 1225
    D3D12_MESSAGE_ID_LIVE_VIDEOEXTENSIONCOMMAND equ 1226
    D3D12_MESSAGE_ID_DESTROY_VIDEOEXTENSIONCOMMAND equ 1227
    D3D12_MESSAGE_ID_INVALID_VIDEO_EXTENSION_COMMAND_ID equ 1228
    D3D12_MESSAGE_ID_VIDEO_EXTENSION_COMMAND_INVALID_ARGUMENT equ 1229
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_NOT_UNIQUE_IN_DXIL_LIBRARY equ 1230
    D3D12_MESSAGE_ID_VARIABLE_SHADING_RATE_NOT_ALLOWED_WITH_TIR equ 1231
    D3D12_MESSAGE_ID_GEOMETRY_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE equ 1232
    D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_SHADING_RATE equ 1233
    D3D12_MESSAGE_ID_RSSETSHADING_RATE_SHADING_RATE_NOT_PERMITTED_BY_CAP equ 1234
    D3D12_MESSAGE_ID_RSSETSHADING_RATE_INVALID_COMBINER equ 1235
    D3D12_MESSAGE_ID_RSSETSHADINGRATEIMAGE_REQUIRES_TIER_2 equ 1236
    D3D12_MESSAGE_ID_RSSETSHADINGRATE_REQUIRES_TIER_1 equ 1237
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_FORMAT equ 1238
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_ARRAY_SIZE equ 1239
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_MIP_LEVEL equ 1240
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_COUNT equ 1241
    D3D12_MESSAGE_ID_SHADING_RATE_IMAGE_INCORRECT_SAMPLE_QUALITY equ 1242
    D3D12_MESSAGE_ID_NON_RETAIL_SHADER_MODEL_WONT_VALIDATE equ 1243
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_ROOT_SIGNATURE_MISMATCH equ 1244
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_ROOT_SIGNATURE_MISMATCH equ 1245
    D3D12_MESSAGE_ID_ADD_TO_STATE_OBJECT_ERROR equ 1246
    D3D12_MESSAGE_ID_CREATE_PROTECTED_RESOURCE_SESSION_INVALID_ARGUMENT equ 1247
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_PSO_DESC_MISMATCH equ 1248
    D3D12_MESSAGE_ID_CREATEPIPELINESTATE_MS_INCOMPLETE_TYPE equ 1249
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_AS_NOT_MS_MISMATCH equ 1250
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_MS_NOT_PS_MISMATCH equ 1251
    D3D12_MESSAGE_ID_NONZERO_SAMPLER_FEEDBACK_MIP_REGION_WITH_INCOMPATIBLE_FORMAT equ 1252
    D3D12_MESSAGE_ID_CREATEGRAPHICSPIPELINESTATE_INPUTLAYOUT_SHADER_MISMATCH equ 1253
    D3D12_MESSAGE_ID_EMPTY_DISPATCH equ 1254
    D3D12_MESSAGE_ID_RESOURCE_FORMAT_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY equ 1255
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_MIP_REGION equ 1256
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_DIMENSION equ 1257
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_COUNT equ 1258
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_SAMPLE_QUALITY equ 1259
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_INVALID_LAYOUT equ 1260
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_MAP_REQUIRES_UNORDERED_ACCESS_FLAG equ 1261
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_NULL_ARGUMENTS equ 1262
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_UAV_REQUIRES_SAMPLER_FEEDBACK_CAPABILITY equ 1263
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_REQUIRES_FEEDBACK_MAP_FORMAT equ 1264
    D3D12_MESSAGE_ID_CREATEMESHSHADER_INVALIDSHADERBYTECODE equ 1265
    D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTOFMEMORY equ 1266
    D3D12_MESSAGE_ID_CREATEMESHSHADERWITHSTREAMOUTPUT_INVALIDSHADERTYPE equ 1267
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_INVALID_FORMAT equ 1268
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_INVALID_MIP_LEVEL_COUNT equ 1269
    D3D12_MESSAGE_ID_RESOLVESUBRESOURCE_SAMPLER_FEEDBACK_TRANSCODE_ARRAY_SIZE_MISMATCH equ 1270
    D3D12_MESSAGE_ID_SAMPLER_FEEDBACK_CREATE_UAV_MISMATCHING_TARGETED_RESOURCE equ 1271
    D3D12_MESSAGE_ID_CREATEMESHSHADER_OUTPUTEXCEEDSMAXSIZE equ 1272
    D3D12_MESSAGE_ID_CREATEMESHSHADER_GROUPSHAREDEXCEEDSMAXSIZE equ 1273
    D3D12_MESSAGE_ID_VERTEX_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE equ 1274
    D3D12_MESSAGE_ID_MESH_SHADER_OUTPUTTING_BOTH_VIEWPORT_ARRAY_INDEX_AND_SHADING_RATE_NOT_SUPPORTED_ON_DEVICE equ 1275
    D3D12_MESSAGE_ID_CREATEMESHSHADER_MISMATCHEDASMSPAYLOADSIZE equ 1276
    D3D12_MESSAGE_ID_CREATE_ROOT_SIGNATURE_UNBOUNDED_STATIC_DESCRIPTORS equ 1277
    D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_INVALIDSHADERBYTECODE equ 1278
    D3D12_MESSAGE_ID_CREATEAMPLIFICATIONSHADER_OUTOFMEMORY equ 1279
    D3D12_MESSAGE_ID_CREATE_SHADERCACHESESSION equ 1280
    D3D12_MESSAGE_ID_LIVE_SHADERCACHESESSION equ 1281
    D3D12_MESSAGE_ID_DESTROY_SHADERCACHESESSION equ 1282
    D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_INVALIDARGS equ 1283
    D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_DISABLED equ 1284
    D3D12_MESSAGE_ID_CREATESHADERCACHESESSION_ALREADYOPEN equ 1285
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_DEVELOPERMODE equ 1286
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_INVALIDFLAGS equ 1287
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_STATEALREADYSET equ 1288
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_IGNOREDFLAG equ 1289
    D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_ALREADYPRESENT equ 1290
    D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_HASHCOLLISION equ 1291
    D3D12_MESSAGE_ID_SHADERCACHESESSION_STOREVALUE_CACHEFULL equ 1292
    D3D12_MESSAGE_ID_SHADERCACHESESSION_FINDVALUE_NOTFOUND equ 1293
    D3D12_MESSAGE_ID_SHADERCACHESESSION_CORRUPT equ 1294
    D3D12_MESSAGE_ID_SHADERCACHESESSION_DISABLED equ 1295
    D3D12_MESSAGE_ID_OVERSIZED_DISPATCH equ 1296
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODER equ 1297
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODER equ 1298
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODER equ 1299
    D3D12_MESSAGE_ID_CREATE_VIDEOENCODERHEAP equ 1300
    D3D12_MESSAGE_ID_LIVE_VIDEOENCODERHEAP equ 1301
    D3D12_MESSAGE_ID_DESTROY_VIDEOENCODERHEAP equ 1302
    D3D12_MESSAGE_ID_COPYTEXTUREREGION_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG equ 1303
    D3D12_MESSAGE_ID_COPYRESOURCE_MISMATCH_ENCODE_REFERENCE_ONLY_FLAG equ 1304
    D3D12_MESSAGE_ID_ENCODE_FRAME_INVALID_PARAMETERS equ 1305
    D3D12_MESSAGE_ID_ENCODE_FRAME_UNSUPPORTED_PARAMETERS equ 1306
    D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_INVALID_PARAMETERS equ 1307
    D3D12_MESSAGE_ID_RESOLVE_ENCODER_OUTPUT_METADATA_UNSUPPORTED_PARAMETERS equ 1308
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_INVALID_PARAMETERS equ 1309
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_UNSUPPORTED_PARAMETERS equ 1310
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_INVALID_PARAMETERS equ 1311
    D3D12_MESSAGE_ID_CREATE_VIDEO_ENCODER_HEAP_UNSUPPORTED_PARAMETERS equ 1312
    D3D12_MESSAGE_ID_CREATECOMMANDLIST_NULL_COMMANDALLOCATOR equ 1313
    D3D12_MESSAGE_ID_CLEAR_UNORDERED_ACCESS_VIEW_INVALID_DESCRIPTOR_HANDLE equ 1314
    D3D12_MESSAGE_ID_DESCRIPTOR_HEAP_NOT_SHADER_VISIBLE equ 1315
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOP_WARNING equ 1316
    D3D12_MESSAGE_ID_CREATEBLENDSTATE_BLENDOPALPHA_WARNING equ 1317
    D3D12_MESSAGE_ID_WRITE_COMBINE_PERFORMANCE_WARNING equ 1318
    D3D12_MESSAGE_ID_RESOLVE_QUERY_INVALID_QUERY_STATE equ 1319
    D3D12_MESSAGE_ID_SETPRIVATEDATA_NO_ACCESS equ 1320
    D3D12_MESSAGE_ID_COMMAND_LIST_STATIC_DESCRIPTOR_SAMPLER_MODE_MISMATCH equ 1321
    D3D12_MESSAGE_ID_GETCOPYABLEFOOTPRINTS_UNSUPPORTED_BUFFER_WIDTH equ 1322
    D3D12_MESSAGE_ID_CREATEMESHSHADER_TOPOLOGY_MISMATCH equ 1323
    D3D12_MESSAGE_ID_VRS_SUM_COMBINER_REQUIRES_CAPABILITY equ 1324
    D3D12_MESSAGE_ID_SETTING_SHADING_RATE_FROM_MS_REQUIRES_CAPABILITY equ 1325
    D3D12_MESSAGE_ID_SHADERCACHESESSION_SHADERCACHEDELETE_NOTSUPPORTED equ 1326
    D3D12_MESSAGE_ID_SHADERCACHECONTROL_SHADERCACHECLEAR_NOTSUPPORTED equ 1327
    D3D12_MESSAGE_ID_CREATERESOURCE_STATE_IGNORED equ 1328
    D3D12_MESSAGE_ID_UNUSED_CROSS_EXECUTE_SPLIT_BARRIER equ 1329
    D3D12_MESSAGE_ID_DEVICE_OPEN_SHARED_HANDLE_ACCESS_DENIED equ 1330
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_VALUES equ 1331
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_ACCESS equ 1332
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_SYNC equ 1333
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_LAYOUT equ 1334
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_TYPE equ 1335
    D3D12_MESSAGE_ID_OUT_OF_BOUNDS_BARRIER_SUBRESOURCE_RANGE equ 1336
    D3D12_MESSAGE_ID_INCOMPATIBLE_BARRIER_RESOURCE_DIMENSION equ 1337
    D3D12_MESSAGE_ID_SET_SCISSOR_RECTS_INVALID_RECT equ 1338
    D3D12_MESSAGE_ID_SHADING_RATE_SOURCE_REQUIRES_DIMENSION_TEXTURE2D equ 1339
    D3D12_MESSAGE_ID_BUFFER_BARRIER_SUBREGION_OUT_OF_BOUNDS equ 1340
    D3D12_MESSAGE_ID_UNSUPPORTED_BARRIER_LAYOUT equ 1341
    D3D12_MESSAGE_ID_CREATERESOURCEANDHEAP_INVALID_PARAMETERS equ 1342
    D3D12_MESSAGE_ID_ENHANCED_BARRIERS_NOT_SUPPORTED equ 1343
    D3D12_MESSAGE_ID_CAST_TARGET_TEXEL_SIZE_MISMATCH equ 1344
    D3D12_MESSAGE_ID_CAST_TO_PLANAR_NOT_SUPORTED equ 1345
    D3D12_MESSAGE_ID_LEGACY_BARRIER_VALIDATION_FORCED_ON equ 1346
    D3D12_MESSAGE_ID_EMPTY_ROOT_DESCRIPTOR_TABLE equ 1347
    D3D12_MESSAGE_ID_COMMAND_LIST_DRAW_ELEMENT_OFFSET_UNALIGNED equ 1348
    D3D12_MESSAGE_ID_ALPHA_BLEND_FACTOR_NOT_SUPPORTED equ 1349
    D3D12_MESSAGE_ID_D3D12_MESSAGES_END equ

    D3D12_MESSAGE struct
      Category D3D12_MESSAGE_CATEGORY ?
      Severity D3D12_MESSAGE_SEVERITY ?
      ID D3D12_MESSAGE_ID ?
      pDescription POINTER ?
      DescriptionByteLength SIZE_T ?
    D3D12_MESSAGE ends
    D3D12_INFO_QUEUE_FILTER_DESC struct
      NumCategories UINT ?
      pCategoryList POINTER ?
      NumSeverities UINT ?
      pSeverityList POINTER ?
      NumIDs UINT ?
      pIDList POINTER ?
    D3D12_INFO_QUEUE_FILTER_DESC ends
    D3D12_INFO_QUEUE_FILTER struct
      AllowList D3D12_INFO_QUEUE_FILTER_DESC <>
      DenyList D3D12_INFO_QUEUE_FILTER_DESC <>
    D3D12_INFO_QUEUE_FILTER ends
    D3D12_INFO_QUEUE_DEFAULT_MESSAGE_COUNT_LIMIT equ 1024
    externdef __MIDL_itf_d3d12sdklayers_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12InfoQueue_INTERFACE_DEFINED__
      __ID3D12InfoQueue_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12InfoQueue:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12InfoQueueVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12InfoQueueVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12InfoQueue, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetMessageCountLimit)
          STD_METHOD SetMessageCountLimit, :ptr ID3D12InfoQueue, :UINT64
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, ClearStoredMessages)
          STD_METHOD ClearStoredMessages, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetMessage)
          STD_METHOD GetMessage, :ptr ID3D12InfoQueue, :UINT64, :ptr D3D12_MESSAGE, :ptr SIZE_T
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumMessagesAllowedByStorageFilter)
          STD_METHOD GetNumMessagesAllowedByStorageFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumMessagesDeniedByStorageFilter)
          STD_METHOD GetNumMessagesDeniedByStorageFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumStoredMessages)
          STD_METHOD GetNumStoredMessages, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumStoredMessagesAllowedByRetrievalFilter)
          STD_METHOD GetNumStoredMessagesAllowedByRetrievalFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumMessagesDiscardedByMessageCountLimit)
          STD_METHOD GetNumMessagesDiscardedByMessageCountLimit, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetMessageCountLimit)
          STD_METHOD GetMessageCountLimit, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddStorageFilterEntries)
          STD_METHOD AddStorageFilterEntries, :ptr ID3D12InfoQueue, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetStorageFilter)
          STD_METHOD GetStorageFilter, :ptr ID3D12InfoQueue, :ptr D3D12_INFO_QUEUE_FILTER, :ptr SIZE_T
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, ClearStorageFilter)
          STD_METHOD ClearStorageFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushEmptyStorageFilter)
          STD_METHOD PushEmptyStorageFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushCopyOfStorageFilter)
          STD_METHOD PushCopyOfStorageFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushStorageFilter)
          STD_METHOD PushStorageFilter, :ptr ID3D12InfoQueue, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PopStorageFilter)
          STD_METHOD PopStorageFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetStorageFilterStackSize)
          STD_METHOD GetStorageFilterStackSize, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddRetrievalFilterEntries)
          STD_METHOD AddRetrievalFilterEntries, :ptr ID3D12InfoQueue, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetRetrievalFilter)
          STD_METHOD GetRetrievalFilter, :ptr ID3D12InfoQueue, :ptr D3D12_INFO_QUEUE_FILTER, :ptr SIZE_T
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, ClearRetrievalFilter)
          STD_METHOD ClearRetrievalFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushEmptyRetrievalFilter)
          STD_METHOD PushEmptyRetrievalFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushCopyOfRetrievalFilter)
          STD_METHOD PushCopyOfRetrievalFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushRetrievalFilter)
          STD_METHOD PushRetrievalFilter, :ptr ID3D12InfoQueue, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PopRetrievalFilter)
          STD_METHOD PopRetrievalFilter, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetRetrievalFilterStackSize)
          STD_METHOD GetRetrievalFilterStackSize, :ptr ID3D12InfoQueue
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddMessage)
          STD_METHOD AddMessage, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_CATEGORY, :D3D12_MESSAGE_SEVERITY, :D3D12_MESSAGE_ID, :LPCSTR
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddApplicationMessage)
          STD_METHOD AddApplicationMessage, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_SEVERITY, :LPCSTR
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetBreakOnCategory)
          STD_METHOD SetBreakOnCategory, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_CATEGORY, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetBreakOnSeverity)
          STD_METHOD SetBreakOnSeverity, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_SEVERITY, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetBreakOnID)
          STD_METHOD SetBreakOnID, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_ID, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetBreakOnCategory)
          STD_METHOD GetBreakOnCategory, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_CATEGORY
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetBreakOnSeverity)
          STD_METHOD GetBreakOnSeverity, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_SEVERITY
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetBreakOnID)
          STD_METHOD GetBreakOnID, :ptr ID3D12InfoQueue, :D3D12_MESSAGE_ID
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetMuteDebugOutput)
          STD_METHOD SetMuteDebugOutput, :ptr ID3D12InfoQueue, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetMuteDebugOutput)
          STD_METHOD GetMuteDebugOutput, :ptr ID3D12InfoQueue
          ??Interface equ <>
          END_INTERFACE
        ID3D12InfoQueueVtbl ends
        ID3D12InfoQueue struct
          lpVtbl POINTER ?
        ID3D12InfoQueue ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    D3D12_MESSAGE_CALLBACK_FLAGS typedef SDWORD
    D3D12_MESSAGE_CALLBACK_FLAG_NONE equ 0
    D3D12_MESSAGE_CALLBACK_IGNORE_FILTERS equ 1h

    DEFINE_ENUM_FLAG_OPERATORS(D3D12_MESSAGE_CALLBACK_FLAGS)
    TYPE_D3D12MessageFunc typedef proto WIN_STD_CALL_CONV :D3D12_MESSAGE_CATEGORY, :D3D12_MESSAGE_SEVERITY, :D3D12_MESSAGE_ID, :LPCSTR, :ptr
    D3D12MessageFunc typedef ptr TYPE_D3D12MessageFunc

    externdef __MIDL_itf_d3d12sdklayers_0000_0016_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_d3d12sdklayers_0000_0016_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ID3D12InfoQueue1_INTERFACE_DEFINED__
      __ID3D12InfoQueue1_INTERFACE_DEFINED__ equ <>
      externdef IID_ID3D12InfoQueue1:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ID3D12InfoQueue1Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ID3D12InfoQueue1Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ID3D12InfoQueue1, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetMessageCountLimit)
          STD_METHOD SetMessageCountLimit, :ptr ID3D12InfoQueue1, :UINT64
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, ClearStoredMessages)
          STD_METHOD ClearStoredMessages, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetMessage)
          STD_METHOD GetMessage, :ptr ID3D12InfoQueue1, :UINT64, :ptr D3D12_MESSAGE, :ptr SIZE_T
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumMessagesAllowedByStorageFilter)
          STD_METHOD GetNumMessagesAllowedByStorageFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumMessagesDeniedByStorageFilter)
          STD_METHOD GetNumMessagesDeniedByStorageFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumStoredMessages)
          STD_METHOD GetNumStoredMessages, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumStoredMessagesAllowedByRetrievalFilter)
          STD_METHOD GetNumStoredMessagesAllowedByRetrievalFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetNumMessagesDiscardedByMessageCountLimit)
          STD_METHOD GetNumMessagesDiscardedByMessageCountLimit, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetMessageCountLimit)
          STD_METHOD GetMessageCountLimit, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddStorageFilterEntries)
          STD_METHOD AddStorageFilterEntries, :ptr ID3D12InfoQueue1, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetStorageFilter)
          STD_METHOD GetStorageFilter, :ptr ID3D12InfoQueue1, :ptr D3D12_INFO_QUEUE_FILTER, :ptr SIZE_T
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, ClearStorageFilter)
          STD_METHOD ClearStorageFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushEmptyStorageFilter)
          STD_METHOD PushEmptyStorageFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushCopyOfStorageFilter)
          STD_METHOD PushCopyOfStorageFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushStorageFilter)
          STD_METHOD PushStorageFilter, :ptr ID3D12InfoQueue1, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PopStorageFilter)
          STD_METHOD PopStorageFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetStorageFilterStackSize)
          STD_METHOD GetStorageFilterStackSize, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddRetrievalFilterEntries)
          STD_METHOD AddRetrievalFilterEntries, :ptr ID3D12InfoQueue1, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetRetrievalFilter)
          STD_METHOD GetRetrievalFilter, :ptr ID3D12InfoQueue1, :ptr D3D12_INFO_QUEUE_FILTER, :ptr SIZE_T
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, ClearRetrievalFilter)
          STD_METHOD ClearRetrievalFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushEmptyRetrievalFilter)
          STD_METHOD PushEmptyRetrievalFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushCopyOfRetrievalFilter)
          STD_METHOD PushCopyOfRetrievalFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PushRetrievalFilter)
          STD_METHOD PushRetrievalFilter, :ptr ID3D12InfoQueue1, :ptr D3D12_INFO_QUEUE_FILTER
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, PopRetrievalFilter)
          STD_METHOD PopRetrievalFilter, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetRetrievalFilterStackSize)
          STD_METHOD GetRetrievalFilterStackSize, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddMessage)
          STD_METHOD AddMessage, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_CATEGORY, :D3D12_MESSAGE_SEVERITY, :D3D12_MESSAGE_ID, :LPCSTR
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, AddApplicationMessage)
          STD_METHOD AddApplicationMessage, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_SEVERITY, :LPCSTR
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetBreakOnCategory)
          STD_METHOD SetBreakOnCategory, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_CATEGORY, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetBreakOnSeverity)
          STD_METHOD SetBreakOnSeverity, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_SEVERITY, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetBreakOnID)
          STD_METHOD SetBreakOnID, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_ID, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetBreakOnCategory)
          STD_METHOD GetBreakOnCategory, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_CATEGORY
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetBreakOnSeverity)
          STD_METHOD GetBreakOnSeverity, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_SEVERITY
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetBreakOnID)
          STD_METHOD GetBreakOnID, :ptr ID3D12InfoQueue1, :D3D12_MESSAGE_ID
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, SetMuteDebugOutput)
          STD_METHOD SetMuteDebugOutput, :ptr ID3D12InfoQueue1, :BOOL
          DECLSPEC_XFGVIRT(ID3D12InfoQueue, GetMuteDebugOutput)
          STD_METHOD GetMuteDebugOutput, :ptr ID3D12InfoQueue1
          DECLSPEC_XFGVIRT(ID3D12InfoQueue1, RegisterMessageCallback)
          STD_METHOD RegisterMessageCallback, :ptr ID3D12InfoQueue1, :D3D12MessageFunc, :D3D12_MESSAGE_CALLBACK_FLAGS, :ptr, :ptr DWORD
          DECLSPEC_XFGVIRT(ID3D12InfoQueue1, UnregisterMessageCallback)
          STD_METHOD UnregisterMessageCallback, :ptr ID3D12InfoQueue1, :DWORD
          ??Interface equ <>
          END_INTERFACE
        ID3D12InfoQueue1Vtbl ends
        ID3D12InfoQueue1 struct
          lpVtbl POINTER ?
        ID3D12InfoQueue1 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  DEFINE_GUID IID_ID3D12Debug, 344488b7h, 6846h, 474bh, 0b9h, 89h, 0f0h, 27h, 44h, 82h, 45h, 0e0h
  DEFINE_GUID IID_ID3D12Debug1, 0affaa4cah, 63feh, 4d8eh, 0b8h, 0adh, 15h, 90h, 00h, 0afh, 43h, 04h
  DEFINE_GUID IID_ID3D12Debug2, 93a665c4h, 0a3b2h, 4e5dh, 0b6h, 92h, 0a2h, 6ah, 0e1h, 4eh, 33h, 74h
  DEFINE_GUID IID_ID3D12Debug3, 5cf4e58fh, 0f671h, 4ff1h, 0a5h, 42h, 36h, 86h, 0e3h, 0d1h, 53h, 0d1h
  DEFINE_GUID IID_ID3D12Debug4, 014b816eh, 9ec5h, 4a2fh, 0a8h, 45h, 0ffh, 0beh, 44h, 1ch, 0e1h, 3ah
  DEFINE_GUID IID_ID3D12Debug5, 548d6b12h, 09fah, 40e0h, 90h, 69h, 5dh, 0cdh, 58h, 9ah, 52h, 0c9h
  DEFINE_GUID IID_ID3D12Debug6, 82a816d6h, 5d01h, 4157h, 97h, 0d0h, 49h, 75h, 46h, 3fh, 0d1h, 0edh
  DEFINE_GUID IID_ID3D12DebugDevice1, 0a9b71770h, 0d099h, 4a65h, 0a6h, 98h, 3dh, 0eeh, 10h, 02h, 0fh, 88h
  DEFINE_GUID IID_ID3D12DebugDevice, 3febd6ddh, 4973h, 4787h, 81h, 94h, 0e4h, 5fh, 9eh, 28h, 92h, 3eh
  DEFINE_GUID IID_ID3D12DebugDevice2, 60eccbc1h, 378dh, 4df1h, 89h, 4ch, 0f8h, 0ach, 5ch, 0e4h, 0d7h, 0ddh
  DEFINE_GUID IID_ID3D12DebugCommandQueue, 09e0bf36h, 54ach, 484fh, 88h, 47h, 4bh, 0aeh, 0eah, 0b6h, 05h, 3ah
  DEFINE_GUID IID_ID3D12DebugCommandList1, 102ca951h, 311bh, 4b01h, 0b1h, 1fh, 0ech, 0b8h, 3eh, 06h, 1bh, 37h
  DEFINE_GUID IID_ID3D12DebugCommandList, 09e0bf36h, 54ach, 484fh, 88h, 47h, 4bh, 0aeh, 0eah, 0b6h, 05h, 3fh
  DEFINE_GUID IID_ID3D12DebugCommandList2, 0aeb575cfh, 4e06h, 48beh, 0bah, 3bh, 0c4h, 50h, 0fch, 96h, 65h, 2eh
  DEFINE_GUID IID_ID3D12SharingContract, 0adf7d52h, 929ch, 4e61h, 0adh, 0dbh, 0ffh, 0edh, 30h, 0deh, 66h, 0efh
  DEFINE_GUID IID_ID3D12InfoQueue, 0742a90bh, 0c387h, 483fh, 0b9h, 46h, 30h, 0a7h, 0e4h, 0e6h, 14h, 58h
  DEFINE_GUID IID_ID3D12InfoQueue1, 2852dd88h, 0b484h, 4c0ch, 0b6h, 0b1h, 67h, 16h, 85h, 00h, 0e6h, 00h
  externdef __MIDL_itf_d3d12sdklayers_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_d3d12sdklayers_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif
