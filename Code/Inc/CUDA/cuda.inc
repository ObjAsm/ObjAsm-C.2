;/*
; * Copyright 1993-2018 NVIDIA Corporation.  All rights reserved.
; *
; * NOTICE TO LICENSEE:
; *
; * This source code and/or documentation ("Licensed Deliverables") are
; * subject to NVIDIA intellectual property rights under U.S. and
; * international Copyright laws.
; *
; * These Licensed Deliverables contained herein is PROPRIETARY and
; * CONFIDENTIAL to NVIDIA and is being provided under the terms and
; * conditions of a form of NVIDIA software license agreement by and
; * between NVIDIA and Licensee ("License Agreement") or electronically
; * accepted by Licensee.  Notwithstanding any terms or conditions to
; * the contrary in the License Agreement, reproduction or disclosure
; * of the Licensed Deliverables to any third party without the express
; * written consent of NVIDIA is prohibited.
; *
; * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
; * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE
; * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  IT IS
; * PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.
; * NVIDIA DISCLAIMS ALL WARRANTIES WITH REGARD TO THESE LICENSED
; * DELIVERABLES, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
; * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
; * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
; * LICENSE AGREEMENT, IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY
; * SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
; * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
; * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
; * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
; * OF THESE LICENSED DELIVERABLES.
; *
; * U.S. Government End Users.  These Licensed Deliverables are a
; * "commercial item" as that term is defined at 48 C.F.R. 2.101 (OCT
; * 1995), consisting of "commercial computer software" and "commercial
; * computer software documentation" as such terms are used in 48
; * C.F.R. 12.212 (SEPT 1995) and is provided to the U.S. Government
; * only as a commercial end item.  Consistent with 48 C.F.R.12.212 and
; * 48 C.F.R. 227.7202-1 through 227.7202-4 (JUNE 1995), all
; * U.S. Government End Users acquire the Licensed Deliverables with
; * only those rights set forth herein.
; *
; * Any use of the Licensed Deliverables in individual and commercial
; * software must include, in the user documentation and internal
; * comments to the code, the above Disclaimer and U.S. Government End
; * Users Notice.
; */

IFDEF _MSC_VER
cuuint32_t TYPEDEF DWORD
cuuint64_t TYPEDEF QWORD
ELSE
Include stdint.SDK
cuuint32_t TYPEDEF DWORD
cuuint64_t TYPEDEF QWORD
ENDIF 

;/**
; * CUDA API versioning support
; */
IF Defined(__CUDA_API_VERSION_INTERNAL) OR Defined(__DOXYGEN_ONLY__) OR Defined(CUDA_ENABLE_DEPRECATED)
__CUDA_DEPRECATED  equ 1  
ELSEIF Defined(_MSC_VER)
__CUDA_DEPRECATED  equ  < deprecated>
ELSEIF Defined(__GNUC__)
__CUDA_DEPRECATED  equ  < >
ELSE
__CUDA_DEPRECATED  equ  0
ENDIF 

IF Defined(CUDA_FORCE_API_VERSION)
IF ( CUDA_FORCE_API_VERSION EQ 3010)
__CUDA_API_VERSION  equ < 3010>
ELSE
.ERR <"Unsupported value of CUDA_FORCE_API_VERSION">
ENDIF 
ELSE
__CUDA_API_VERSION  equ  < 10010>
ENDIF ;/* CUDA_FORCE_API_VERSION */ 

IF Defined(__CUDA_API_VERSION_INTERNAL) OR Defined(CUDA_API_PER_THREAD_DEFAULT_STREAM)
__CUDA_API_PER_THREAD_DEFAULT_STREAM  equ  
__CUDA_API_PTDS  equ  < api>
__CUDA_API_PTSZ  equ  < api>
ELSE
__CUDA_API_PTDS  equ  < api>
__CUDA_API_PTSZ  equ  < api>
ENDIF 

IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION GE 3020
cuDeviceTotalMem  equ  < cuDeviceTotalMem_v2>
cuCtxCreate  equ  < cuCtxCreate_v2>
cuModuleGetGlobal  equ  < cuModuleGetGlobal_v2>
cuMemGetInfo  equ  < cuMemGetInfo_v2>
cuMemAlloc  equ  < cuMemAlloc_v2>
cuMemAllocPitch  equ  < cuMemAllocPitch_v2>
cuMemFree  equ  < cuMemFree_v2>
cuMemGetAddressRange  equ  < cuMemGetAddressRange_v2>
cuMemAllocHost  equ  < cuMemAllocHost_v2>
cuMemHostGetDevicePointer  equ  < cuMemHostGetDevicePointer_v2>
cuMemcpyHtoD  equ  < cuMemcpyHtoD_v2>
cuMemcpyDtoH  equ  < cuMemcpyDtoH_v2>
cuMemcpyDtoD  equ  < cuMemcpyDtoD_v2>
cuMemcpyDtoA  equ  < cuMemcpyDtoA_v2>
cuMemcpyAtoD  equ  < cuMemcpyAtoD_v2>
cuMemcpyHtoA  equ  < cuMemcpyHtoA_v2>
cuMemcpyAtoH  equ  < cuMemcpyAtoH_v2>
cuMemcpyAtoA  equ  < cuMemcpyAtoA_v2>
cuMemcpyHtoAAsync  equ  < cuMemcpyHtoAAsync_v2>
cuMemcpyAtoHAsync  equ  < cuMemcpyAtoHAsync_v2>
cuMemcpy2D  equ  < cuMemcpy2D_v2>
cuMemcpy2DUnaligned  equ  < cuMemcpy2DUnaligned_v2>
cuMemcpy3D  equ  < cuMemcpy3D_v2>
cuMemcpyHtoDAsync  equ  < cuMemcpyHtoDAsync_v2>
cuMemcpyDtoHAsync  equ  < cuMemcpyDtoHAsync_v2>
cuMemcpyDtoDAsync  equ  < cuMemcpyDtoDAsync_v2>
cuMemcpy2DAsync  equ  < cuMemcpy2DAsync_v2>
cuMemcpy3DAsync  equ  < cuMemcpy3DAsync_v2>
cuMemsetD8  equ  < cuMemsetD8_v2>
cuMemsetD16  equ  < cuMemsetD16_v2>
cuMemsetD32  equ  < cuMemsetD32_v2>
cuMemsetD2D8  equ  < cuMemsetD2D8_v2>
cuMemsetD2D16  equ  < cuMemsetD2D16_v2>
cuMemsetD2D32  equ  < cuMemsetD2D32_v2>
cuArrayCreate  equ  < cuArrayCreate_v2>
cuArrayGetDescriptor  equ  < cuArrayGetDescriptor_v2>
cuArray3DCreate  equ  < cuArray3DCreate_v2>
cuArray3DGetDescriptor  equ  < cuArray3DGetDescriptor_v2>
cuTexRefSetAddress  equ  < cuTexRefSetAddress_v2>
cuTexRefGetAddress  equ  < cuTexRefGetAddress_v2>
cuGraphicsResourceGetMappedPointer  equ  < cuGraphicsResourceGetMappedPointer_v2>
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 3020 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION GE 4000
cuCtxDestroy  equ  < cuCtxDestroy_v2>
cuCtxPopCurrent  equ  < cuCtxPopCurrent_v2>
cuCtxPushCurrent  equ  < cuCtxPushCurrent_v2>
cuStreamDestroy  equ  < cuStreamDestroy_v2>
cuEventDestroy  equ  < cuEventDestroy_v2>
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 4000 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION GE 4010
cuTexRefSetAddress2D  equ  < cuTexRefSetAddress2D_v3>
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 4010 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION GE 6050
cuLinkCreate  equ  < cuLinkCreate_v2>
cuLinkAddData  equ  < cuLinkAddData_v2>
cuLinkAddFile  equ  < cuLinkAddFile_v2>
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 6050 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION GE 6050
cuMemHostRegister  equ  < cuMemHostRegister_v2>
cuGraphicsResourceSetMapFlags  equ  < cuGraphicsResourceSetMapFlags_v2>
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 6050 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION GE 10010
cuStreamBeginCapture  equ  < cuStreamBeginCapture_v2>
ELSEIF Defined(__CUDA_API_PER_THREAD_DEFAULT_STREAM)
cuStreamBeginCapture  equ  < cuStreamBeginCapture>
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION >= 10010 */ 
IF not Defined(__CUDA_API_VERSION_INTERNAL)
IF Defined(__CUDA_API_VERSION) AND  __CUDA_API_VERSION GE 3020 AND  __CUDA_API_VERSION LT 4010
cuTexRefSetAddress2D  equ  < cuTexRefSetAddress2D_v2>
ENDIF ;/* __CUDA_API_VERSION && __CUDA_API_VERSION >= 3020 && __CUDA_API_VERSION < 4010 */ 
ENDIF ;/* __CUDA_API_VERSION_INTERNAL */ 
IF Defined(__CUDA_API_PER_THREAD_DEFAULT_STREAM)
cuMemcpy  equ  < cuMemcpy>
cuMemcpyAsync  equ  < cuMemcpyAsync>
cuMemcpyPeer  equ  < cuMemcpyPeer>
cuMemcpyPeerAsync  equ  < cuMemcpyPeerAsync>
cuMemcpy3DPeer  equ  < cuMemcpy3DPeer>
cuMemcpy3DPeerAsync  equ  < cuMemcpy3DPeerAsync>
cuMemPrefetchAsync  equ  < cuMemPrefetchAsync>
cuMemsetD8Async  equ  < cuMemsetD8Async>
cuMemsetD16Async  equ  < cuMemsetD16Async>
cuMemsetD32Async  equ  < cuMemsetD32Async>
cuMemsetD2D8Async  equ  < cuMemsetD2D8Async>
cuMemsetD2D16Async  equ  < cuMemsetD2D16Async>
cuMemsetD2D32Async  equ  < cuMemsetD2D32Async>
cuStreamGetPriority  equ  < cuStreamGetPriority>
cuStreamGetFlags  equ  < cuStreamGetFlags>
cuStreamGetCtx  equ  < cuStreamGetCtx>
cuStreamWaitEvent  equ  < cuStreamWaitEvent>
cuStreamEndCapture  equ  < cuStreamEndCapture>
cuStreamIsCapturing  equ  < cuStreamIsCapturing>
cuStreamGetCaptureInfo  equ  < cuStreamGetCaptureInfo>
cuStreamAddCallback  equ  < cuStreamAddCallback>
cuStreamAttachMemAsync  equ  < cuStreamAttachMemAsync>
cuStreamQuery  equ  < cuStreamQuery>
cuStreamSynchronize  equ  < cuStreamSynchronize>
cuEventRecord  equ  < cuEventRecord>
cuLaunchKernel  equ  < cuLaunchKernel>
cuLaunchHostFunc  equ  < cuLaunchHostFunc>
cuGraphicsMapResources  equ  < cuGraphicsMapResources>
cuGraphicsUnmapResources  equ  < cuGraphicsUnmapResources>
cuStreamWriteValue32  equ  < cuStreamWriteValue32>
cuStreamWaitValue32  equ  < cuStreamWaitValue32>
cuStreamWriteValue64  equ  < cuStreamWriteValue64>
cuStreamWaitValue64  equ  < cuStreamWaitValue64>
cuStreamBatchMemOp  equ  < cuStreamBatchMemOp>
cuLaunchCooperativeKernel  equ  < cuLaunchCooperativeKernel>
cuSignalExternalSemaphoresAsync  equ  < cuSignalExternalSemaphoresAsync>
cuWaitExternalSemaphoresAsync  equ  < cuWaitExternalSemaphoresAsync>
cuGraphLaunch  equ  < cuGraphLaunch>
ENDIF 
;/**
; * \file cuda.h
; * \brief Header file for the CUDA Toolkit application programming interface.
; *
; * \file cudaGL.h
; * \brief Header file for the OpenGL interoperability functions of the
; * low-level CUDA driver application programming interface.
; *
; * \file cudaD3D9.h
; * \brief Header file for the Direct3D 9 interoperability functions of the
; * low-level CUDA driver application programming interface.
; */
;/**
; * \defgroup CUDA_TYPES Data types used by CUDA driver
; * @{
; */
;/**
; * CUDA API version number
; */
CUDA_VERSION  equ  < 10010>
IFDEF __cplusplus
ENDIF 
;/**
; * CUDA device pointer
; * CUdeviceptr is defined as an unsigned integer type whose size matches the size of a pointer on the target platform.
; */
IF  __CUDA_API_VERSION GE 3020
;/**
;*#if defined(_WIN64) || defined(__LP64__)
;*typedef __int64 CUdeviceptr;
;*#else
;*typedef unsigned int CUdeviceptr;
;*#endif
;*/
IF Defined(_WIN64) OR Defined(__LP64__)
CUdeviceptr TYPEDEF QWORD
ELSE
CUdeviceptr TYPEDEF DWORD
ENDIF 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
CUdevice TYPEDEF DWORD
CUcontext TYPEDEF XWORD
CUmodule TYPEDEF XWORD
CUfunction TYPEDEF XWORD
CUarray TYPEDEF XWORD
CUmipmappedArray TYPEDEF XWORD
CUtexref TYPEDEF XWORD
CUsurfref TYPEDEF XWORD
CUevent TYPEDEF XWORD
CUstream TYPEDEF XWORD
CUgraphicsResource TYPEDEF XWORD
CUtexObject TYPEDEF QWORD
CUsurfObject TYPEDEF QWORD
CUexternalMemory TYPEDEF XWORD
CUexternalSemaphore TYPEDEF XWORD
CUgraph TYPEDEF XWORD
CUgraphNode TYPEDEF XWORD
CUgraphExec TYPEDEF XWORD
IFNDEF CU_UUID_HAS_BEEN_DEFINED
CU_UUID_HAS_BEEN_DEFINED  equ  

CUuuid  STRUCT; DEFALIGNMASM
  bytes BYTE 16 dup (?)
CUuuid    ENDS


ENDIF 
IF  __CUDA_API_VERSION GE 4010
;/**
; * CUDA IPC handle size
; */
CU_IPC_HANDLE_SIZE  equ  < 64>
;/**
; * CUDA IPC event handle
; */

CUipcEventHandle  STRUCT DEFALIGNMASM
  reserved BYTE CU_IPC_HANDLE_SIZE dup (?)
CUipcEventHandle    ENDS


;/**
; * CUDA IPC mem handle
; */

CUipcMemHandle  STRUCT DEFALIGNMASM
  reserved BYTE CU_IPC_HANDLE_SIZE dup (?)
CUipcMemHandle    ENDS


;/**
; * CUDA Ipc Mem Flags
; */

CUipcMem_flags  TYPEDEF DWORD ;enum

;CUipcMem_flags  UNION DEFALIGNMASM
  CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS  EQU <01h >
;CUipcMem_flags    ENDS


ENDIF 
;/**
; * CUDA Mem Attach Flags
; */

CUmemAttach_flags  TYPEDEF DWORD ;enum

;CUmemAttach_flags  UNION DEFALIGNMASM
  CU_MEM_ATTACH_GLOBAL  EQU <01h >  ;/**< Memory can be accessed by any stream on any device */ 
  CU_MEM_ATTACH_HOST  EQU <02h >  ;/**< Memory cannot be accessed by any stream on any device */ 
  CU_MEM_ATTACH_SINGLE  EQU <04h >
;CUmemAttach_flags    ENDS


;/**
; * Context creation flags
; */

CUctx_flags  TYPEDEF DWORD ;enum

;CUctx_flags  UNION DEFALIGNMASM
  CU_CTX_SCHED_AUTO  EQU <000h >  ;/**< Automatic scheduling */ 
  CU_CTX_SCHED_SPIN  EQU <001h >  ;/**< Set spin as default scheduling */ 
  CU_CTX_SCHED_YIELD  EQU <002h >  ;/**< Set yield as default scheduling */ 
  CU_CTX_SCHED_BLOCKING_SYNC  EQU <004h >  ;/**< Set blocking synchronization as default scheduling */ 
  CU_CTX_BLOCKING_SYNC  EQU <004h >
  CU_CTX_SCHED_MASK  EQU <007h >
  CU_CTX_MAP_HOST  EQU <008h >  ;/**< Support mapped pinned allocations */ 
  CU_CTX_LMEM_RESIZE_TO_MAX  EQU <010h >  ;/**< Keep local memory allocation after launch */ 
  CU_CTX_FLAGS_MASK  EQU <01fh >
;CUctx_flags    ENDS


;/**
; * Stream creation flags
; */

CUstream_flags  TYPEDEF DWORD ;enum

;CUstream_flags  UNION DEFALIGNMASM
  CU_STREAM_DEFAULT  EQU <00h >  ;/**< Default stream flag */ 
  CU_STREAM_NON_BLOCKING  EQU <01h >
;CUstream_flags    ENDS


;/**
; * Legacy stream handle
; *
; * Stream handle that can be passed as a CUstream to use an implicit stream
; * with legacy synchronization behavior.
; *
; * See details of the \link_sync_behavior
; */
CU_STREAM_LEGACY  equ  <  01h>
;/**
; * Per-thread stream handle
; *
; * Stream handle that can be passed as a CUstream to use an implicit stream
; * with per-thread synchronization behavior.
; *
; * See details of the \link_sync_behavior
; */
CU_STREAM_PER_THREAD  equ  <  02h>
;/**
; * Event creation flags
; */

CUevent_flags  TYPEDEF DWORD ;enum

;CUevent_flags  UNION DEFALIGNMASM
  CU_EVENT_DEFAULT  EQU <00h >  ;/**< Default event flag */ 
  CU_EVENT_BLOCKING_SYNC  EQU <01h >  ;/**< Event uses blocking synchronization */ 
  CU_EVENT_DISABLE_TIMING  EQU <02h >  ;/**< Event will not record timing data */ 
  CU_EVENT_INTERPROCESS  EQU <04h >
;CUevent_flags    ENDS


IF  __CUDA_API_VERSION GE 8000
;/**
; * Flags for ::cuStreamWaitValue32 and ::cuStreamWaitValue64
; */

CUstreamWaitValue_flags  TYPEDEF DWORD ;enum

;CUstreamWaitValue_flags  UNION DEFALIGNMASM
  CU_STREAM_WAIT_VALUE_GEQ  EQU <00h >
  CU_STREAM_WAIT_VALUE_EQ  EQU <01h >  ;/**< Wait until *addr == value. */ 
  CU_STREAM_WAIT_VALUE_AND  EQU <02h >  ;/**< Wait until (*addr & value) != 0. */ 
  CU_STREAM_WAIT_VALUE_NOR  EQU <03h >
  CU_STREAM_WAIT_VALUE_FLUSH  EQU <1   SHL 30 >
;CUstreamWaitValue_flags    ENDS


;/**
; * Flags for ::cuStreamWriteValue32
; */

CUstreamWriteValue_flags  TYPEDEF DWORD ;enum

;CUstreamWriteValue_flags  UNION DEFALIGNMASM
  CU_STREAM_WRITE_VALUE_DEFAULT  EQU <00h >  ;/**< Default behavior */ 
  CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER  EQU <01h >
;CUstreamWriteValue_flags    ENDS


;/**
; * Operations for ::cuStreamBatchMemOp
; */

CUstreamBatchMemOpType  TYPEDEF DWORD ;enum

;CUstreamBatchMemOpType  UNION DEFALIGNMASM
  CU_STREAM_MEM_OP_WAIT_VALUE_32  EQU <1 >  ;/**< Represents a ::cuStreamWaitValue32 operation */ 
  CU_STREAM_MEM_OP_WRITE_VALUE_32  EQU <2 >  ;/**< Represents a ::cuStreamWriteValue32 operation */ 
  CU_STREAM_MEM_OP_WAIT_VALUE_64  EQU <4 >  ;/**< Represents a ::cuStreamWaitValue64 operation */ 
  CU_STREAM_MEM_OP_WRITE_VALUE_64  EQU <5 >  ;/**< Represents a ::cuStreamWriteValue64 operation */ 
  CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES  EQU <3 >
;CUstreamBatchMemOpType    ENDS


;/**
; * Per-operation parameters for ::cuStreamBatchMemOp
; */

CUstreamBatchMemOpParams  UNION DEFALIGNMASM
  operation CUstreamBatchMemOpType ?
  STRUCT  waitValue
  operation CUstreamBatchMemOpType ?
  address XWORD ?
  union
  value DWORD ?
  value64 QWORD ?
  ENDS
  flags DWORD ?
  aliasA XWORD ? ;/**< For driver internal use. Initial value is unimportant. */ 
  ENDS
  STRUCT  writeValue
  operation CUstreamBatchMemOpType ?
  address XWORD ?
  union
  value DWORD ?
  value64 QWORD ?
  ENDS
  flags DWORD ?
  aliasA XWORD ? ;/**< For driver internal use. Initial value is unimportant. */ 
  ENDS
  STRUCT  flushRemoteWrites
  operation CUstreamBatchMemOpType ?
  flags DWORD ?
  ENDS
  pad QWORD 6 dup (?)
CUstreamBatchMemOpParams    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 8000 */ 
;/**
; * Occupancy calculator flag
; */

CUoccupancy_flags  TYPEDEF DWORD ;enum

;CUoccupancy_flags  UNION DEFALIGNMASM
  CU_OCCUPANCY_DEFAULT  EQU <00h >  ;/**< Default behavior */ 
  CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE  EQU <01h >
;CUoccupancy_flags    ENDS


;/**
; * Array formats
; */

CUarray_format  TYPEDEF DWORD ;enum

;CUarray_format  UNION DEFALIGNMASM
  CU_AD_FORMAT_UNSIGNED_INT8  EQU <001h >  ;/**< Unsigned 8-bit integers */ 
  CU_AD_FORMAT_UNSIGNED_INT16  EQU <002h >  ;/**< Unsigned 16-bit integers */ 
  CU_AD_FORMAT_UNSIGNED_INT32  EQU <003h >  ;/**< Unsigned 32-bit integers */ 
  CU_AD_FORMAT_SIGNED_INT8  EQU <008h >  ;/**< Signed 8-bit integers */ 
  CU_AD_FORMAT_SIGNED_INT16  EQU <009h >  ;/**< Signed 16-bit integers */ 
  CU_AD_FORMAT_SIGNED_INT32  EQU <00ah >  ;/**< Signed 32-bit integers */ 
  CU_AD_FORMAT_HALF  EQU <010h >  ;/**< 16-bit floating point */ 
  CU_AD_FORMAT_FLOAT  EQU <020h >
;CUarray_format    ENDS


;/**
; * Texture reference addressing modes
; */

CUaddress_mode  TYPEDEF DWORD ;enum

;CUaddress_mode  UNION DEFALIGNMASM
  CU_TR_ADDRESS_MODE_WRAP  EQU <0 >  ;/**< Wrapping address mode */ 
  CU_TR_ADDRESS_MODE_CLAMP  EQU <1 >  ;/**< Clamp to edge address mode */ 
  CU_TR_ADDRESS_MODE_MIRROR  EQU <2 >  ;/**< Mirror address mode */ 
  CU_TR_ADDRESS_MODE_BORDER  EQU <3 >
;CUaddress_mode    ENDS


;/**
; * Texture reference filtering modes
; */

CUfilter_mode  TYPEDEF DWORD ;enum

;CUfilter_mode  UNION DEFALIGNMASM
  CU_TR_FILTER_MODE_POINT  EQU <0 >  ;/**< Point filter mode */ 
  CU_TR_FILTER_MODE_LINEAR  EQU <1 >
;CUfilter_mode    ENDS


;/**
; * Device properties
; */

CUdevice_attribute  TYPEDEF DWORD ;enum

;CUdevice_attribute  UNION DEFALIGNMASM
  CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK  EQU <1 >  ;/**< Maximum number of threads per block */ 
  CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X  EQU <2 >  ;/**< Maximum block dimension X */ 
  CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y  EQU <3 >  ;/**< Maximum block dimension Y */ 
  CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z  EQU <4 >  ;/**< Maximum block dimension Z */ 
  CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X  EQU <5 >  ;/**< Maximum grid dimension X */ 
  CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y  EQU <6 >  ;/**< Maximum grid dimension Y */ 
  CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z  EQU <7 >  ;/**< Maximum grid dimension Z */ 
  CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK  EQU <8 >  ;/**< Maximum shared memory available per block in bytes */ 
  CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK  EQU <8 >  ;/**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK */ 
  CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY  EQU <9 >  ;/**< Memory available on device for __constant__ variables in a CUDA C kernel in bytes */ 
  CU_DEVICE_ATTRIBUTE_WARP_SIZE  EQU <10 >  ;/**< Warp size in threads */ 
  CU_DEVICE_ATTRIBUTE_MAX_PITCH  EQU <11 >  ;/**< Maximum pitch in bytes allowed by memory copies */ 
  CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK  EQU <12 >  ;/**< Maximum number of 32-bit registers available per block */ 
  CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK  EQU <12 >  ;/**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK */ 
  CU_DEVICE_ATTRIBUTE_CLOCK_RATE  EQU <13 >  ;/**< Typical clock frequency in kilohertz */ 
  CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT  EQU <14 >  ;/**< Alignment requirement for textures */ 
  CU_DEVICE_ATTRIBUTE_GPU_OVERLAP  EQU <15 >  ;/**< Device can possibly copy memory and execute a kernel concurrently. Deprecated. Use instead CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT. */ 
  CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT  EQU <16 >  ;/**< Number of multiprocessors on device */ 
  CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT  EQU <17 >  ;/**< Specifies whether there is a run time limit on kernels */ 
  CU_DEVICE_ATTRIBUTE_INTEGRATED  EQU <18 >  ;/**< Device is integrated with host memory */ 
  CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY  EQU <19 >  ;/**< Device can map host memory into CUDA address space */ 
  CU_DEVICE_ATTRIBUTE_COMPUTE_MODE  EQU <20 >  ;/**< Compute mode (See ::CUcomputemode for details) */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH  EQU <21 >  ;/**< Maximum 1D texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH  EQU <22 >  ;/**< Maximum 2D texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT  EQU <23 >  ;/**< Maximum 2D texture height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH  EQU <24 >  ;/**< Maximum 3D texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT  EQU <25 >  ;/**< Maximum 3D texture height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH  EQU <26 >  ;/**< Maximum 3D texture depth */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH  EQU <27 >  ;/**< Maximum 2D layered texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT  EQU <28 >  ;/**< Maximum 2D layered texture height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS  EQU <29 >  ;/**< Maximum layers in a 2D layered texture */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH  EQU <27 >  ;/**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT  EQU <28 >  ;/**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES  EQU <29 >  ;/**< Deprecated, use CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS */ 
  CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT  EQU <30 >  ;/**< Alignment requirement for surfaces */ 
  CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS  EQU <31 >  ;/**< Device can possibly execute multiple kernels concurrently */ 
  CU_DEVICE_ATTRIBUTE_ECC_ENABLED  EQU <32 >  ;/**< Device has ECC support enabled */ 
  CU_DEVICE_ATTRIBUTE_PCI_BUS_ID  EQU <33 >  ;/**< PCI bus ID of the device */ 
  CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID  EQU <34 >  ;/**< PCI device ID of the device */ 
  CU_DEVICE_ATTRIBUTE_TCC_DRIVER  EQU <35 >  ;/**< Device is using TCC driver model */ 
  CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE  EQU <36 >  ;/**< Peak memory clock frequency in kilohertz */ 
  CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH  EQU <37 >  ;/**< Global memory bus width in bits */ 
  CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE  EQU <38 >  ;/**< Size of L2 cache in bytes */ 
  CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR  EQU <39 >  ;/**< Maximum resident threads per multiprocessor */ 
  CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT  EQU <40 >  ;/**< Number of asynchronous engines */ 
  CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING  EQU <41 >  ;/**< Device shares a unified address space with the host */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH  EQU <42 >  ;/**< Maximum 1D layered texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS  EQU <43 >  ;/**< Maximum layers in a 1D layered texture */ 
  CU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER  EQU <44 >  ;/**< Deprecated, do not use. */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH  EQU <45 >  ;/**< Maximum 2D texture width if CUDA_ARRAY3D_TEXTURE_GATHER is set */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT  EQU <46 >  ;/**< Maximum 2D texture height if CUDA_ARRAY3D_TEXTURE_GATHER is set */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE  EQU <47 >  ;/**< Alternate maximum 3D texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE  EQU <48 >  ;/**< Alternate maximum 3D texture height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE  EQU <49 >  ;/**< Alternate maximum 3D texture depth */ 
  CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID  EQU <50 >  ;/**< PCI domain ID of the device */ 
  CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT  EQU <51 >  ;/**< Pitch alignment requirement for textures */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH  EQU <52 >  ;/**< Maximum cubemap texture width/height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH  EQU <53 >  ;/**< Maximum cubemap layered texture width/height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS  EQU <54 >  ;/**< Maximum layers in a cubemap layered texture */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH  EQU <55 >  ;/**< Maximum 1D surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH  EQU <56 >  ;/**< Maximum 2D surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT  EQU <57 >  ;/**< Maximum 2D surface height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH  EQU <58 >  ;/**< Maximum 3D surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT  EQU <59 >  ;/**< Maximum 3D surface height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH  EQU <60 >  ;/**< Maximum 3D surface depth */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH  EQU <61 >  ;/**< Maximum 1D layered surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS  EQU <62 >  ;/**< Maximum layers in a 1D layered surface */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH  EQU <63 >  ;/**< Maximum 2D layered surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT  EQU <64 >  ;/**< Maximum 2D layered surface height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS  EQU <65 >  ;/**< Maximum layers in a 2D layered surface */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH  EQU <66 >  ;/**< Maximum cubemap surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH  EQU <67 >  ;/**< Maximum cubemap layered surface width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS  EQU <68 >  ;/**< Maximum layers in a cubemap layered surface */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH  EQU <69 >  ;/**< Maximum 1D linear texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH  EQU <70 >  ;/**< Maximum 2D linear texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT  EQU <71 >  ;/**< Maximum 2D linear texture height */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH  EQU <72 >  ;/**< Maximum 2D linear texture pitch in bytes */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH  EQU <73 >  ;/**< Maximum mipmapped 2D texture width */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT  EQU <74 >  ;/**< Maximum mipmapped 2D texture height */ 
  CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR  EQU <75 >  ;/**< Major compute capability version number */ 
  CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR  EQU <76 >  ;/**< Minor compute capability version number */ 
  CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH  EQU <77 >  ;/**< Maximum mipmapped 1D texture width */ 
  CU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED  EQU <78 >  ;/**< Device supports stream priorities */ 
  CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED  EQU <79 >  ;/**< Device supports caching globals in L1 */ 
  CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED  EQU <80 >  ;/**< Device supports caching locals in L1 */ 
  CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR  EQU <81 >  ;/**< Maximum shared memory available per multiprocessor in bytes */ 
  CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR  EQU <82 >  ;/**< Maximum number of 32-bit registers available per multiprocessor */ 
  CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY  EQU <83 >  ;/**< Device can allocate managed memory on this system */ 
  CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD  EQU <84 >  ;/**< Device is on a multi-GPU board */ 
  CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID  EQU <85 >  ;/**< Unique id for a group of devices on the same multi-GPU board */ 
  CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED  EQU <86 >  ;/**< Link between the device and the host supports native atomic operations (this is a placeholder attribute, and is not supported on any current hardware)*/ 
  CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO  EQU <87 >  ;/**< Ratio of single precision performance (in floating-point operations per second) to double precision performance */ 
  CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS  EQU <88 >  ;/**< Device supports coherently accessing pageable memory without calling cudaHostRegister on it */ 
  CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS  EQU <89 >  ;/**< Device can coherently access managed memory concurrently with the CPU */ 
  CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED  EQU <90 >  ;/**< Device supports compute preemption. */ 
  CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM  EQU <91 >  ;/**< Device can access host registered memory at the same virtual address as the CPU */ 
  CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS  EQU <92 >  ;/**< ::cuStreamBatchMemOp and related APIs are supported. */ 
  CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS  EQU <93 >  ;/**< 64-bit operations are supported in ::cuStreamBatchMemOp and related APIs. */ 
  CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR  EQU <94 >  ;/**< ::CU_STREAM_WAIT_VALUE_NOR is supported. */ 
  CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH  EQU <95 >  ;/**< Device supports launching cooperative kernels via ::cuLaunchCooperativeKernel */ 
  CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH  EQU <96 >  ;/**< Device can participate in cooperative kernels launched via ::cuLaunchCooperativeKernelMultiDevice */ 
  CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN  EQU <97 >  ;/**< Maximum optin shared memory per block */ 
  CU_DEVICE_ATTRIBUTE_CAN_FLUSH_REMOTE_WRITES  EQU <98 >  ;/**< Both the ::CU_STREAM_WAIT_VALUE_FLUSH flag and the ::CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES MemOp are supported on the device. See \ref CUDA_MEMOP for additional details. */ 
  CU_DEVICE_ATTRIBUTE_HOST_REGISTER_SUPPORTED  EQU <99 >  ;/**< Device supports host memory registration via ::cudaHostRegister. */ 
  CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES  EQU <100 >  ;/**< Device accesses pageable memory via the host's page tables. */ 
  CU_DEVICE_ATTRIBUTE_DIRECT_MANAGED_MEM_ACCESS_FROM_HOST  EQU <101 >  ;/**< The host can directly access managed memory on the device without migration. */ 
  CU_DEVICE_ATTRIBUTE_MAX  EQU <066H>
;CUdevice_attribute    ENDS

;/**
; * Legacy device properties
; */

CUdevprop  STRUCT; DEFALIGNMASM
  maxThreadsPerBlock DWORD ? ;/**< Maximum number of threads per block */ 
  maxThreadsDim DWORD 3 dup (?) ;/**< Maximum size of each dimension of a block */ 
  maxGridSize DWORD 3 dup (?) ;/**< Maximum size of each dimension of a grid */ 
  sharedMemPerBlock DWORD ? ;/**< Shared memory available per block in bytes */ 
  totalConstantMemory DWORD ? ;/**< Constant memory available on device in bytes */ 
  SIMDWidth DWORD ? ;/**< Warp size in threads */ 
  memPitch DWORD ? ;/**< Maximum pitch in bytes allowed by memory copies */ 
  regsPerBlock DWORD ? ;/**< 32-bit registers available per block */ 
  clockRate DWORD ? ;/**< Clock frequency in kilohertz */ 
  textureAlign DWORD ? ;/**< Alignment requirement for textures */ 
CUdevprop    ENDS


;/**
; * Pointer information
; */

CUpointer_attribute  TYPEDEF DWORD ;enum

;CUpointer_attribute  UNION DEFALIGNMASM
  CU_POINTER_ATTRIBUTE_CONTEXT  EQU <1 >  ;/**< The ::CUcontext on which a pointer was allocated or registered */ 
  CU_POINTER_ATTRIBUTE_MEMORY_TYPE  EQU <2 >  ;/**< The ::CUmemorytype describing the physical location of a pointer */ 
  CU_POINTER_ATTRIBUTE_DEVICE_POINTER  EQU <3 >  ;/**< The address at which a pointer's memory may be accessed on the device */ 
  CU_POINTER_ATTRIBUTE_HOST_POINTER  EQU <4 >  ;/**< The address at which a pointer's memory may be accessed on the host */ 
  CU_POINTER_ATTRIBUTE_P2P_TOKENS  EQU <5 >  ;/**< A pair of tokens for use with the nv-p2p.h Linux kernel interface */ 
  CU_POINTER_ATTRIBUTE_SYNC_MEMOPS  EQU <6 >  ;/**< Synchronize every synchronous memory operation initiated on this region */ 
  CU_POINTER_ATTRIBUTE_BUFFER_ID  EQU <7 >  ;/**< A process-wide unique ID for an allocated memory region*/ 
  CU_POINTER_ATTRIBUTE_IS_MANAGED  EQU <8 >  ;/**< Indicates if the pointer points to managed memory */ 
  CU_POINTER_ATTRIBUTE_DEVICE_ORDINAL  EQU <9 >
;CUpointer_attribute    ENDS


;/**
; * Function properties
; */

CUfunction_attribute  TYPEDEF DWORD ;enum

;CUfunction_attribute  UNION DEFALIGNMASM
  CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK  EQU <0 >
  CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES  EQU <1 >
  CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES  EQU <2 >
  CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES  EQU <3 >
  CU_FUNC_ATTRIBUTE_NUM_REGS  EQU <4 >
  CU_FUNC_ATTRIBUTE_PTX_VERSION  EQU <5 >
  CU_FUNC_ATTRIBUTE_BINARY_VERSION  EQU <6 >
  CU_FUNC_ATTRIBUTE_CACHE_MODE_CA  EQU <7 >
  CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES  EQU <8 >
  CU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT  EQU <9 >
  CU_FUNC_ATTRIBUTE_MAX  EQU <0AH>
;CUfunction_attribute    ENDS


;/**
; * Function cache configurations
; */

CUfunc_cache  TYPEDEF DWORD ;enum

;CUfunc_cache  UNION DEFALIGNMASM
  CU_FUNC_CACHE_PREFER_NONE  EQU <000h >  ;/**< no preference for shared memory or L1 (default) */ 
  CU_FUNC_CACHE_PREFER_SHARED  EQU <001h >  ;/**< prefer larger shared memory and smaller L1 cache */ 
  CU_FUNC_CACHE_PREFER_L1  EQU <002h >  ;/**< prefer larger L1 cache and smaller shared memory */ 
  CU_FUNC_CACHE_PREFER_EQUAL  EQU <003h >
;CUfunc_cache    ENDS


;/**
; * Shared memory configurations
; */

CUsharedconfig  TYPEDEF DWORD ;enum

;CUsharedconfig  UNION DEFALIGNMASM
  CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE  EQU <000h >  ;/**< set default shared memory bank size */ 
  CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE  EQU <001h >  ;/**< set shared memory bank width to four bytes */ 
  CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE  EQU <002h >
;CUsharedconfig    ENDS


;/**
; * Shared memory carveout configurations. These may be passed to ::cuFuncSetAttribute
; */

CUshared_carveout  TYPEDEF DWORD ;enum

;CUshared_carveout  UNION DEFALIGNMASM
  CU_SHAREDMEM_CARVEOUT_DEFAULT  EQU <  - 1 >  ;/**< No preference for shared memory or L1 (default) */ 
  CU_SHAREDMEM_CARVEOUT_MAX_SHARED  EQU <100 >  ;/**< Prefer maximum available shared memory, minimum L1 cache */ 
  CU_SHAREDMEM_CARVEOUT_MAX_L1  EQU <0 >
;CUshared_carveout    ENDS


;/**
; * Memory types
; */

CUmemorytype  TYPEDEF DWORD ;enum

;CUmemorytype  UNION DEFALIGNMASM
  CU_MEMORYTYPE_HOST  EQU <001h >  ;/**< Host memory */ 
  CU_MEMORYTYPE_DEVICE  EQU <002h >  ;/**< Device memory */ 
  CU_MEMORYTYPE_ARRAY  EQU <003h >  ;/**< Array memory */ 
  CU_MEMORYTYPE_UNIFIED  EQU <004h >
;CUmemorytype    ENDS


;/**
; * Compute Modes
; */

CUcomputemode  TYPEDEF DWORD ;enum

;CUcomputemode  UNION DEFALIGNMASM
  CU_COMPUTEMODE_DEFAULT  EQU <0 >  ;/**< Default compute mode (Multiple contexts allowed per device) */ 
  CU_COMPUTEMODE_PROHIBITED  EQU <2 >  ;/**< Compute-prohibited mode (No contexts can be created on this device at this time) */ 
  CU_COMPUTEMODE_EXCLUSIVE_PROCESS  EQU <3 >
;CUcomputemode    ENDS


;/**
; * Memory advise values
; */

CUmem_advise  TYPEDEF DWORD ;enum

;CUmem_advise  UNION DEFALIGNMASM
  CU_MEM_ADVISE_SET_READ_MOSTLY  EQU <1 >  ;/**< Data will mostly be read and only occassionally be written to */ 
  CU_MEM_ADVISE_UNSET_READ_MOSTLY  EQU <2 >  ;/**< Undo the effect of ::CU_MEM_ADVISE_SET_READ_MOSTLY */ 
  CU_MEM_ADVISE_SET_PREFERRED_LOCATION  EQU <3 >  ;/**< Set the preferred location for the data as the specified device */ 
  CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION  EQU <4 >  ;/**< Clear the preferred location for the data */ 
  CU_MEM_ADVISE_SET_ACCESSED_BY  EQU <5 >  ;/**< Data will be accessed by the specified device, so prevent page faults as much as possible */ 
  CU_MEM_ADVISE_UNSET_ACCESSED_BY  EQU <6 >
;CUmem_advise    ENDS



CUmem_range_attribute  TYPEDEF DWORD ;enum

;CUmem_range_attribute  UNION DEFALIGNMASM
  CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY  EQU <1 >  ;/**< Whether the range will mostly be read and only occassionally be written to */ 
  CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION  EQU <2 >  ;/**< The preferred location of the range */ 
  CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY  EQU <3 >  ;/**< Memory range has ::CU_MEM_ADVISE_SET_ACCESSED_BY set for specified device */ 
  CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION  EQU <4 >
;CUmem_range_attribute    ENDS


;/**
; * Online compiler and linker options
; */

CUjit_option  TYPEDEF DWORD ;enum

;CUjit_option  UNION DEFALIGNMASM
  CU_JIT_MAX_REGISTERS  EQU <0 >
  CU_JIT_THREADS_PER_BLOCK  EQU <01H>
  CU_JIT_WALL_TIME  EQU <02H>
  CU_JIT_INFO_LOG_BUFFER  EQU <03H>
  CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES  EQU <04H>
  CU_JIT_ERROR_LOG_BUFFER  EQU <05H>
  CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES  EQU <06H>
  CU_JIT_OPTIMIZATION_LEVEL  EQU <07H>
  CU_JIT_TARGET_FROM_CUCONTEXT  EQU <08H>
  CU_JIT_TARGET  EQU <09H>
  CU_JIT_FALLBACK_STRATEGY  EQU <0AH>
  CU_JIT_GENERATE_DEBUG_INFO  EQU <0BH>
  CU_JIT_LOG_VERBOSE  EQU <0CH>
  CU_JIT_GENERATE_LINE_INFO  EQU <0DH>
  CU_JIT_CACHE_MODE  EQU <0EH>
  CU_JIT_NEW_SM3X_OPT  EQU <0FH>
  CU_JIT_FAST_COMPILE  EQU <010H>
  CU_JIT_GLOBAL_SYMBOL_NAMES  EQU <011H>
  CU_JIT_GLOBAL_SYMBOL_ADDRESSES  EQU <012H>
  CU_JIT_GLOBAL_SYMBOL_COUNT  EQU <013H>
  CU_JIT_NUM_OPTIONS  EQU <014H>
;CUjit_option    ENDS


;/**
; * Online compilation targets
; */

CUjit_target  TYPEDEF DWORD ;enum

;CUjit_target  UNION DEFALIGNMASM
  CU_TARGET_COMPUTE_20  EQU <20 >  ;/**< Compute device class 2.0 */ 
  CU_TARGET_COMPUTE_21  EQU <21 >  ;/**< Compute device class 2.1 */ 
  CU_TARGET_COMPUTE_30  EQU <30 >  ;/**< Compute device class 3.0 */ 
  CU_TARGET_COMPUTE_32  EQU <32 >  ;/**< Compute device class 3.2 */ 
  CU_TARGET_COMPUTE_35  EQU <35 >  ;/**< Compute device class 3.5 */ 
  CU_TARGET_COMPUTE_37  EQU <37 >  ;/**< Compute device class 3.7 */ 
  CU_TARGET_COMPUTE_50  EQU <50 >  ;/**< Compute device class 5.0 */ 
  CU_TARGET_COMPUTE_52  EQU <52 >  ;/**< Compute device class 5.2 */ 
  CU_TARGET_COMPUTE_53  EQU <53 >  ;/**< Compute device class 5.3 */ 
  CU_TARGET_COMPUTE_60  EQU <60 >  ;/**< Compute device class 6.0.*/ 
  CU_TARGET_COMPUTE_61  EQU <61 >  ;/**< Compute device class 6.1.*/ 
  CU_TARGET_COMPUTE_62  EQU <62 >  ;/**< Compute device class 6.2.*/ 
  CU_TARGET_COMPUTE_70  EQU <70 >  ;/**< Compute device class 7.0.*/ 
  CU_TARGET_COMPUTE_72  EQU <72 >  ;/**< Compute device class 7.2.*/ 
  CU_TARGET_COMPUTE_75  EQU <75 >
;CUjit_target    ENDS


;/**
; * Cubin matching fallback strategies
; */

CUjit_fallback  TYPEDEF DWORD ;enum

;CUjit_fallback  UNION DEFALIGNMASM
  CU_PREFER_PTX  EQU <0 >  ;/**< Prefer to compile ptx if exact binary match not found */ 
  CU_PREFER_BINARY  EQU <01H>
;CUjit_fallback    ENDS


;/**
; * Caching modes for dlcm
; */

CUjit_cacheMode  TYPEDEF DWORD ;enum

;CUjit_cacheMode  UNION DEFALIGNMASM
  CU_JIT_CACHE_OPTION_NONE  EQU <0 >  ;/**< Compile with no -dlcm flag specified */ 
  CU_JIT_CACHE_OPTION_CG  EQU <01H>  ;/**< Compile with L1 cache disabled */ 
  CU_JIT_CACHE_OPTION_CA  EQU <02H>
;CUjit_cacheMode    ENDS


;/**
; * Device code formats
; */

CUjitInputType  TYPEDEF DWORD ;enum

;CUjitInputType  UNION DEFALIGNMASM
  CU_JIT_INPUT_CUBIN  EQU <0 >
  CU_JIT_INPUT_PTX  EQU <01H>
  CU_JIT_INPUT_FATBINARY  EQU <02H>
  CU_JIT_INPUT_OBJECT  EQU <03H>
  CU_JIT_INPUT_LIBRARY  EQU <04H>
  CU_JIT_NUM_INPUT_TYPES  EQU <05H>
;CUjitInputType    ENDS


IF  __CUDA_API_VERSION GE 5050
CUlinkState TYPEDEF XWORD
ENDIF ;/* __CUDA_API_VERSION >= 5050 */ 
;/**
; * Flags to register a graphics resource
; */

CUgraphicsRegisterFlags  TYPEDEF DWORD ;enum

;CUgraphicsRegisterFlags  UNION DEFALIGNMASM
  CU_GRAPHICS_REGISTER_FLAGS_NONE  EQU <000h >
  CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY  EQU <001h >
  CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD  EQU <002h >
  CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST  EQU <004h >
  CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER  EQU <008h >
;CUgraphicsRegisterFlags    ENDS


;/**
; * Flags for mapping and unmapping interop resources
; */

CUgraphicsMapResourceFlags  TYPEDEF DWORD ;enum

;CUgraphicsMapResourceFlags  UNION DEFALIGNMASM
  CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE  EQU <000h >
  CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY  EQU <001h >
  CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD  EQU <002h >
;CUgraphicsMapResourceFlags    ENDS


;/**
; * Array indices for cube faces
; */

CUarray_cubemap_face  TYPEDEF DWORD ;enum

;CUarray_cubemap_face  UNION DEFALIGNMASM
  CU_CUBEMAP_FACE_POSITIVE_X  EQU <000h >  ;/**< Positive X face of cubemap */ 
  CU_CUBEMAP_FACE_NEGATIVE_X  EQU <001h >  ;/**< Negative X face of cubemap */ 
  CU_CUBEMAP_FACE_POSITIVE_Y  EQU <002h >  ;/**< Positive Y face of cubemap */ 
  CU_CUBEMAP_FACE_NEGATIVE_Y  EQU <003h >  ;/**< Negative Y face of cubemap */ 
  CU_CUBEMAP_FACE_POSITIVE_Z  EQU <004h >  ;/**< Positive Z face of cubemap */ 
  CU_CUBEMAP_FACE_NEGATIVE_Z  EQU <005h >
;CUarray_cubemap_face    ENDS


;/**
; * Limits
; */

CUlimit  TYPEDEF DWORD ;enum

;CUlimit  UNION DEFALIGNMASM
  CU_LIMIT_STACK_SIZE  EQU <000h >  ;/**< GPU thread stack size */ 
  CU_LIMIT_PRINTF_FIFO_SIZE  EQU <001h >  ;/**< GPU printf FIFO size */ 
  CU_LIMIT_MALLOC_HEAP_SIZE  EQU <002h >  ;/**< GPU malloc heap size */ 
  CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH  EQU <003h >  ;/**< GPU device runtime launch synchronize depth */ 
  CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT  EQU <004h >  ;/**< GPU device runtime pending launch count */ 
  CU_LIMIT_MAX_L2_FETCH_GRANULARITY  EQU <005h >  ;/**< A value between 0 and 128 that indicates the maximum fetch granularity of L2 (in Bytes). This is a hint */ 
  CU_LIMIT_MAX  EQU <06BH>
;CUlimit    ENDS


;/**
; * Resource types
; */

CUresourcetype  TYPEDEF DWORD ;enum

;CUresourcetype  UNION DEFALIGNMASM
  CU_RESOURCE_TYPE_ARRAY  EQU <000h >  ;/**< Array resoure */ 
  CU_RESOURCE_TYPE_MIPMAPPED_ARRAY  EQU <001h >  ;/**< Mipmapped array resource */ 
  CU_RESOURCE_TYPE_LINEAR  EQU <002h >  ;/**< Linear resource */ 
  CU_RESOURCE_TYPE_PITCH2D  EQU <003h >
;CUresourcetype    ENDS


IFDEF _WIN32
CUDA_CB  equ  < __stdcall>
ELSE
CUDA_CB  equ  
ENDIF 
IF  __CUDA_API_VERSION GE 10000
;/**
; * CUDA host function
; * \param userData Argument value passed to the function
; */
ZCUhostFn TYPEDEF PROTO :XWORD

;/**
; * GPU kernel node parameters
; */

CUDA_KERNEL_NODE_PARAMS  STRUCT DEFALIGNMASM
  func XWORD ? ;/**< Kernel to launch */ 
  gridDimX DWORD ? ;/**< Width of grid in blocks */ 
  gridDimY DWORD ? ;/**< Height of grid in blocks */ 
  gridDimZ DWORD ? ;/**< Depth of grid in blocks */ 
  blockDimX DWORD ? ;/**< X dimension of each thread block */ 
  blockDimY DWORD ? ;/**< Y dimension of each thread block */ 
  blockDimZ DWORD ? ;/**< Z dimension of each thread block */ 
  sharedMemBytes DWORD ? ;/**< Dynamic shared-memory size per thread block in bytes */ 
kernelParams XWORD ?
extra XWORD ?
CUDA_KERNEL_NODE_PARAMS    ENDS


;/**
; * Memset node parameters
; */

CUDA_MEMSET_NODE_PARAMS  STRUCT DEFALIGNMASM
  dst XWORD ? ;/**< Destination device pointer */ 
  pitch DWORD ? ;/**< Pitch of destination device pointer. Unused if height is 1 */ 
  value DWORD ? ;/**< Value to be set */ 
  elementSize DWORD ? ;/**< Size of each element in bytes. Must be 1, 2, or 4. */ 
  awidth DWORD ? ;/**< Width in bytes, of the row */ 
  height DWORD ? ;/**< Number of rows */ 
CUDA_MEMSET_NODE_PARAMS    ENDS


;/**
; * Host node parameters
; */

CUDA_HOST_NODE_PARAMS  STRUCT DEFALIGNMASM
  fnF XWORD ? ;/**< The function to call when the node executes */ 
userData XWORD ?
CUDA_HOST_NODE_PARAMS    ENDS


;/**
; * Graph node types
; */

CUgraphNodeType  TYPEDEF DWORD ;enum

;CUgraphNodeType  UNION DEFALIGNMASM
  CU_GRAPH_NODE_TYPE_KERNEL  EQU <0 >  ;/**< GPU kernel node */ 
  CU_GRAPH_NODE_TYPE_MEMCPY  EQU <1 >  ;/**< Memcpy node */ 
  CU_GRAPH_NODE_TYPE_MEMSET  EQU <2 >  ;/**< Memset node */ 
  CU_GRAPH_NODE_TYPE_HOST  EQU <3 >  ;/**< Host (executable) node */ 
  CU_GRAPH_NODE_TYPE_GRAPH  EQU <4 >  ;/**< Node which executes an embedded graph */ 
  CU_GRAPH_NODE_TYPE_EMPTY  EQU <5 >  ;/**< Empty (no-op) node */ 
  CU_GRAPH_NODE_TYPE_COUNT  EQU <06H>
;CUgraphNodeType    ENDS


;/**
; * Possible stream capture statuses returned by ::cuStreamIsCapturing
; */

CUstreamCaptureStatus  TYPEDEF DWORD ;enum

;CUstreamCaptureStatus  UNION DEFALIGNMASM
  CU_STREAM_CAPTURE_STATUS_NONE  EQU <0 >  ;/**< Stream is not capturing */ 
  CU_STREAM_CAPTURE_STATUS_ACTIVE  EQU <1 >  ;/**< Stream is actively capturing */ 
  CU_STREAM_CAPTURE_STATUS_INVALIDATED  EQU <2 >
;CUstreamCaptureStatus    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
IF  __CUDA_API_VERSION GE 10010
;/**
; * Possible modes for stream capture thread interactions. For more details see
; * ::cuStreamBeginCapture and ::cuThreadExchangeStreamCaptureMode
; */

CUstreamCaptureMode  TYPEDEF DWORD ;enum

;CUstreamCaptureMode  UNION DEFALIGNMASM
  CU_STREAM_CAPTURE_MODE_GLOBAL  EQU <0 >
  CU_STREAM_CAPTURE_MODE_THREAD_LOCAL  EQU <1 >
  CU_STREAM_CAPTURE_MODE_RELAXED  EQU <2 >
;CUstreamCaptureMode    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 10010 */ 
;/**
; * Error codes
; */

CUresult  TYPEDEF DWORD ;enum

;CUresult  UNION DEFALIGNMASM
  CUDA_SUCCESS  EQU <0 >
  CUDA_ERROR_INVALID_VALUE  EQU <1 >
  CUDA_ERROR_OUT_OF_MEMORY  EQU <2 >
  CUDA_ERROR_NOT_INITIALIZED  EQU <3 >
  CUDA_ERROR_DEINITIALIZED  EQU <4 >
  CUDA_ERROR_PROFILER_DISABLED  EQU <5 >
  CUDA_ERROR_PROFILER_NOT_INITIALIZED  EQU <6 >
  CUDA_ERROR_PROFILER_ALREADY_STARTED  EQU <7 >
  CUDA_ERROR_PROFILER_ALREADY_STOPPED  EQU <8 >
  CUDA_ERROR_NO_DEVICE  EQU <100 >
  CUDA_ERROR_INVALID_DEVICE  EQU <101 >
  CUDA_ERROR_INVALID_IMAGE  EQU <200 >
  CUDA_ERROR_INVALID_CONTEXT  EQU <201 >
  CUDA_ERROR_CONTEXT_ALREADY_CURRENT  EQU <202 >
  CUDA_ERROR_MAP_FAILED  EQU <205 >
  CUDA_ERROR_UNMAP_FAILED  EQU <206 >
  CUDA_ERROR_ARRAY_IS_MAPPED  EQU <207 >
  CUDA_ERROR_ALREADY_MAPPED  EQU <208 >
  CUDA_ERROR_NO_BINARY_FOR_GPU  EQU <209 >
  CUDA_ERROR_ALREADY_ACQUIRED  EQU <210 >
  CUDA_ERROR_NOT_MAPPED  EQU <211 >
  CUDA_ERROR_NOT_MAPPED_AS_ARRAY  EQU <212 >
  CUDA_ERROR_NOT_MAPPED_AS_POINTER  EQU <213 >
  CUDA_ERROR_ECC_UNCORRECTABLE  EQU <214 >
  CUDA_ERROR_UNSUPPORTED_LIMIT  EQU <215 >
  CUDA_ERROR_CONTEXT_ALREADY_IN_USE  EQU <216 >
  CUDA_ERROR_PEER_ACCESS_UNSUPPORTED  EQU <217 >
  CUDA_ERROR_INVALID_PTX  EQU <218 >
  CUDA_ERROR_INVALID_GRAPHICS_CONTEXT  EQU <219 >
  CUDA_ERROR_NVLINK_UNCORRECTABLE  EQU <220 >
  CUDA_ERROR_JIT_COMPILER_NOT_FOUND  EQU <221 >
  CUDA_ERROR_INVALID_SOURCE  EQU <300 >
  CUDA_ERROR_FILE_NOT_FOUND  EQU <301 >
  CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND  EQU <302 >
  CUDA_ERROR_SHARED_OBJECT_INIT_FAILED  EQU <303 >
  CUDA_ERROR_OPERATING_SYSTEM  EQU <304 >
  CUDA_ERROR_INVALID_HANDLE  EQU <400 >
  CUDA_ERROR_ILLEGAL_STATE  EQU <401 >
  CUDA_ERROR_NOT_FOUND  EQU <500 >
  CUDA_ERROR_NOT_READY  EQU <600 >
  CUDA_ERROR_ILLEGAL_ADDRESS  EQU <700 >
  CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES  EQU <701 >
  CUDA_ERROR_LAUNCH_TIMEOUT  EQU <702 >
  CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING  EQU <703 >
  CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED  EQU <704 >
  CUDA_ERROR_PEER_ACCESS_NOT_ENABLED  EQU <705 >
  CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE  EQU <708 >
  CUDA_ERROR_CONTEXT_IS_DESTROYED  EQU <709 >
  CUDA_ERROR_ASSERT  EQU <710 >
  CUDA_ERROR_TOO_MANY_PEERS  EQU <711 >
  CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED  EQU <712 >
  CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED  EQU <713 >
  CUDA_ERROR_HARDWARE_STACK_ERROR  EQU <714 >
  CUDA_ERROR_ILLEGAL_INSTRUCTION  EQU <715 >
  CUDA_ERROR_MISALIGNED_ADDRESS  EQU <716 >
  CUDA_ERROR_INVALID_ADDRESS_SPACE  EQU <717 >
  CUDA_ERROR_INVALID_PC  EQU <718 >
  CUDA_ERROR_LAUNCH_FAILED  EQU <719 >
  CUDA_ERROR_COOPERATIVE_LAUNCH_TOO_LARGE  EQU <720 >
  CUDA_ERROR_NOT_PERMITTED  EQU <800 >
  CUDA_ERROR_NOT_SUPPORTED  EQU <801 >
  CUDA_ERROR_SYSTEM_NOT_READY  EQU <802 >
  CUDA_ERROR_SYSTEM_DRIVER_MISMATCH  EQU <803 >
  CUDA_ERROR_COMPAT_NOT_SUPPORTED_ON_DEVICE  EQU <804 >
  CUDA_ERROR_STREAM_CAPTURE_UNSUPPORTED  EQU <900 >
  CUDA_ERROR_STREAM_CAPTURE_INVALIDATED  EQU <901 >
  CUDA_ERROR_STREAM_CAPTURE_MERGE  EQU <902 >
  CUDA_ERROR_STREAM_CAPTURE_UNMATCHED  EQU <903 >
  CUDA_ERROR_STREAM_CAPTURE_UNJOINED  EQU <904 >
  CUDA_ERROR_STREAM_CAPTURE_ISOLATION  EQU <905 >
  CUDA_ERROR_STREAM_CAPTURE_IMPLICIT  EQU <906 >
  CUDA_ERROR_CAPTURED_EVENT  EQU <907 >
  CUDA_ERROR_STREAM_CAPTURE_WRONG_THREAD  EQU <908 >
  CUDA_ERROR_UNKNOWN  EQU <999 >
;CUresult    ENDS

;/**
; * P2P Attributes
; */

CUdevice_P2PAttribute  TYPEDEF DWORD ;enum

;CUdevice_P2PAttribute  UNION DEFALIGNMASM
  CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK  EQU <001h >  ;/**< A relative value indicating the performance of the link between two devices */ 
  CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED  EQU <002h >  ;/**< P2P Access is enable */ 
  CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED  EQU <003h >  ;/**< Atomic operation over the link supported */ 
  CU_DEVICE_P2P_ATTRIBUTE_ACCESS_ACCESS_SUPPORTED  EQU <004h >  ;/**< \deprecated use CU_DEVICE_P2P_ATTRIBUTE_CUDA_ARRAY_ACCESS_SUPPORTED instead */ 
  CU_DEVICE_P2P_ATTRIBUTE_CUDA_ARRAY_ACCESS_SUPPORTED  EQU <004h >
;CUdevice_P2PAttribute    ENDS


;/**
; * CUDA stream callback
; * \param hStream The stream the callback was added to, as passed to ::cuStreamAddCallback.  May be NULL.
; * \param status ::CUDA_SUCCESS or any persistent error on the stream.
; * \param userData User parameter provided at registration.
; */
ZCUstreamCallback TYPEDEF PROTO hStream:XWORD,status:CUresult,:XWORD

;/**
; * Block size to per-block dynamic shared memory mapping for a certain
; * kernel \param blockSize Block size of the kernel.
; *
; * \return The dynamic shared memory needed by a block.
; */
ZCUoccupancyB2DSize TYPEDEF PROTO blockSize:DWORD

;/**
; * If set, host memory is portable between CUDA contexts.
; * Flag for ::cuMemHostAlloc()
; */
CU_MEMHOSTALLOC_PORTABLE  equ  < 001h>
;/**
; * If set, host memory is mapped into CUDA address space and
; * ::cuMemHostGetDevicePointer() may be called on the host pointer.
; * Flag for ::cuMemHostAlloc()
; */
CU_MEMHOSTALLOC_DEVICEMAP  equ  < 002h>
;/**
; * If set, host memory is allocated as write-combined - fast to write,
; * faster to DMA, slow to read except via SSE4 streaming load instruction
; * (MOVNTDQA).
; * Flag for ::cuMemHostAlloc()
; */
CU_MEMHOSTALLOC_WRITECOMBINED  equ  < 004h>
;/**
; * If set, host memory is portable between CUDA contexts.
; * Flag for ::cuMemHostRegister()
; */
CU_MEMHOSTREGISTER_PORTABLE  equ  < 001h>
;/**
; * If set, host memory is mapped into CUDA address space and
; * ::cuMemHostGetDevicePointer() may be called on the host pointer.
; * Flag for ::cuMemHostRegister()
; */
CU_MEMHOSTREGISTER_DEVICEMAP  equ  < 002h>
;/**
; * If set, the passed memory pointer is treated as pointing to some
; * memory-mapped I/O space, e.g. belonging to a third-party PCIe device.
; * On Windows the flag is a no-op.
; * On Linux that memory is marked as non cache-coherent for the GPU and
; * is expected to be physically contiguous. It may return
; * CUDA_ERROR_NOT_PERMITTED if run as an unprivileged user,
; * CUDA_ERROR_NOT_SUPPORTED on older Linux kernel versions.
; * On all other platforms, it is not supported and CUDA_ERROR_NOT_SUPPORTED
; * is returned.
; * Flag for ::cuMemHostRegister()
; */
CU_MEMHOSTREGISTER_IOMEMORY  equ  < 004h>
IF  __CUDA_API_VERSION GE 3020
;/**
; * 2D memory copy parameters
; */

CUDA_MEMCPY2D  STRUCT DEFALIGNMASM
  srcXInBytes DWORD ? ;/**< Source X in bytes */ 
  srcY DWORD ? ;/**< Source Y */ 
  srcMemoryType CUmemorytype ? ;/**< Source memory type (host, device, array) */ 
srcHost XWORD ?
  srcDevice XWORD ? ;/**< Source device pointer */ 
  srcArray XWORD ? ;/**< Source array reference */ 
  srcPitch DWORD ? ;/**< Source pitch (ignored when src is array) */ 
  dstXInBytes DWORD ? ;/**< Destination X in bytes */ 
  dstY DWORD ? ;/**< Destination Y */ 
  dstMemoryType CUmemorytype ? ;/**< Destination memory type (host, device, array) */ 
dstHost XWORD ?
  dstDevice XWORD ? ;/**< Destination device pointer */ 
  dstArray XWORD ? ;/**< Destination array reference */ 
  dstPitch DWORD ? ;/**< Destination pitch (ignored when dst is array) */ 
  WidthInBytes DWORD ? ;/**< Width of 2D memory copy in bytes */ 
  Height DWORD ? ;/**< Height of 2D memory copy */ 
CUDA_MEMCPY2D    ENDS


;/**
; * 3D memory copy parameters
; */

CUDA_MEMCPY3D  STRUCT DEFALIGNMASM
  srcXInBytes DWORD ? ;/**< Source X in bytes */ 
  srcY DWORD ? ;/**< Source Y */ 
  srcZ DWORD ? ;/**< Source Z */ 
  srcLOD DWORD ? ;/**< Source LOD */ 
  srcMemoryType CUmemorytype ? ;/**< Source memory type (host, device, array) */ 
srcHost XWORD ?
  srcDevice XWORD ? ;/**< Source device pointer */ 
  srcArray XWORD ? ;/**< Source array reference */ 
reserved0 XWORD ?
  srcPitch DWORD ? ;/**< Source pitch (ignored when src is array) */ 
  srcHeight DWORD ? ;/**< Source height (ignored when src is array; may be 0 if Depth==1) */ 
  dstXInBytes DWORD ? ;/**< Destination X in bytes */ 
  dstY DWORD ? ;/**< Destination Y */ 
  dstZ DWORD ? ;/**< Destination Z */ 
  dstLOD DWORD ? ;/**< Destination LOD */ 
  dstMemoryType CUmemorytype ? ;/**< Destination memory type (host, device, array) */ 
dstHost XWORD ?
  dstDevice XWORD ? ;/**< Destination device pointer */ 
  dstArray XWORD ? ;/**< Destination array reference */ 
reserved1 XWORD ?
  dstPitch DWORD ? ;/**< Destination pitch (ignored when dst is array) */ 
  dstHeight DWORD ? ;/**< Destination height (ignored when dst is array; may be 0 if Depth==1) */ 
  WidthInBytes DWORD ? ;/**< Width of 3D memory copy in bytes */ 
  Height DWORD ? ;/**< Height of 3D memory copy */ 
  Depth DWORD ? ;/**< Depth of 3D memory copy */ 
CUDA_MEMCPY3D    ENDS


;/**
; * 3D memory cross-context copy parameters
; */

CUDA_MEMCPY3D_PEER  STRUCT DEFALIGNMASM
  srcXInBytes DWORD ? ;/**< Source X in bytes */ 
  srcY DWORD ? ;/**< Source Y */ 
  srcZ DWORD ? ;/**< Source Z */ 
  srcLOD DWORD ? ;/**< Source LOD */ 
  srcMemoryType CUmemorytype ? ;/**< Source memory type (host, device, array) */ 
srcHost XWORD ?
  srcDevice XWORD ? ;/**< Source device pointer */ 
  srcArray XWORD ? ;/**< Source array reference */ 
  srcContext XWORD ? ;/**< Source context (ignored with srcMemoryType is ::CU_MEMORYTYPE_ARRAY) */ 
  srcPitch DWORD ? ;/**< Source pitch (ignored when src is array) */ 
  srcHeight DWORD ? ;/**< Source height (ignored when src is array; may be 0 if Depth==1) */ 
  dstXInBytes DWORD ? ;/**< Destination X in bytes */ 
  dstY DWORD ? ;/**< Destination Y */ 
  dstZ DWORD ? ;/**< Destination Z */ 
  dstLOD DWORD ? ;/**< Destination LOD */ 
  dstMemoryType CUmemorytype ? ;/**< Destination memory type (host, device, array) */ 
dstHost XWORD ?
  dstDevice XWORD ? ;/**< Destination device pointer */ 
  dstArray XWORD ? ;/**< Destination array reference */ 
  dstContext XWORD ? ;/**< Destination context (ignored with dstMemoryType is ::CU_MEMORYTYPE_ARRAY) */ 
  dstPitch DWORD ? ;/**< Destination pitch (ignored when dst is array) */ 
  dstHeight DWORD ? ;/**< Destination height (ignored when dst is array; may be 0 if Depth==1) */ 
  WidthInBytes DWORD ? ;/**< Width of 3D memory copy in bytes */ 
  Height DWORD ? ;/**< Height of 3D memory copy */ 
  Depth DWORD ? ;/**< Depth of 3D memory copy */ 
CUDA_MEMCPY3D_PEER    ENDS


;/**
; * Array descriptor
; */

CUDA_ARRAY_DESCRIPTOR  STRUCT DEFALIGNMASM
  awidth DWORD ? ;/**< Width of array */ 
  Height DWORD ? ;/**< Height of array */ 
  Format CUarray_format ? ;/**< Array format */ 
  NumChannels DWORD ? ;/**< Channels per array element */ 
CUDA_ARRAY_DESCRIPTOR    ENDS


;/**
; * 3D array descriptor
; */

CUDA_ARRAY3D_DESCRIPTOR  STRUCT DEFALIGNMASM
  awidth DWORD ? ;/**< Width of 3D array */ 
  Height DWORD ? ;/**< Height of 3D array */ 
  Depth DWORD ? ;/**< Depth of 3D array */ 
  Format CUarray_format ? ;/**< Array format */ 
  NumChannels DWORD ? ;/**< Channels per array element */ 
  Flags DWORD ? ;/**< Flags */ 
CUDA_ARRAY3D_DESCRIPTOR    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
IF  __CUDA_API_VERSION GE 5000
;/**
; * CUDA Resource descriptor
; */

CUDA_RESOURCE_DESC  STRUCT DEFALIGNMASM
  resType CUresourcetype ? ;/**< Resource type */ 
  union  res
  STRUCT  array
  hArray XWORD ? ;/**< CUDA array */ 
  ENDS
  STRUCT  mipmap
  hMipmappedArray XWORD ? ;/**< CUDA mipmapped array */ 
  ENDS
  STRUCT  linear
  devPtr XWORD ? ;/**< Device pointer */ 
  format CUarray_format ? ;/**< Array format */ 
  numChannels DWORD ? ;/**< Channels per array element */ 
  sizeInBytes DWORD ? ;/**< Size in bytes */ 
  ENDS
  STRUCT  pitch2D
  devPtr XWORD ? ;/**< Device pointer */ 
  format CUarray_format ? ;/**< Array format */ 
  numChannels DWORD ? ;/**< Channels per array element */ 
  awidth DWORD ? ;/**< Width of the array in elements */ 
  height DWORD ? ;/**< Height of the array in elements */ 
  pitchInBytes DWORD ? ;/**< Pitch between two rows in bytes */ 
  ENDS
  STRUCT  reserved
  reserved DWORD 32 dup (?)
  ENDS
  ENDS
  flags DWORD ? ;/**< Flags (must be zero) */ 
CUDA_RESOURCE_DESC    ENDS


;/**
; * Texture descriptor
; */

CUDA_TEXTURE_DESC  STRUCT DEFALIGNMASM
  addressMode CUaddress_mode 3 dup (?) ;/**< Address modes */ 
  filterMode CUfilter_mode ? ;/**< Filter mode */ 
  flags DWORD ? ;/**< Flags */ 
  maxAnisotropy DWORD ? ;/**< Maximum anisotropy ratio */ 
  mipmapFilterMode CUfilter_mode ? ;/**< Mipmap filter mode */ 
  mipmapLevelBias REAL4 ? ;/**< Mipmap level bias */ 
  minMipmapLevelClamp REAL4 ? ;/**< Mipmap minimum level clamp */ 
  maxMipmapLevelClamp REAL4 ? ;/**< Mipmap maximum level clamp */ 
  borderColor REAL4 4 dup (?) ;/**< Border Color */ 
  reserved DWORD 12 dup (?)
CUDA_TEXTURE_DESC    ENDS


;/**
; * Resource view format
; */

CUresourceViewFormat  TYPEDEF DWORD ;enum

;CUresourceViewFormat  UNION DEFALIGNMASM
  CU_RES_VIEW_FORMAT_NONE  EQU <000h >  ;/**< No resource view format (use underlying resource format) */ 
  CU_RES_VIEW_FORMAT_UINT_1X8  EQU <001h >  ;/**< 1 channel unsigned 8-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_2X8  EQU <002h >  ;/**< 2 channel unsigned 8-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_4X8  EQU <003h >  ;/**< 4 channel unsigned 8-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_1X8  EQU <004h >  ;/**< 1 channel signed 8-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_2X8  EQU <005h >  ;/**< 2 channel signed 8-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_4X8  EQU <006h >  ;/**< 4 channel signed 8-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_1X16  EQU <007h >  ;/**< 1 channel unsigned 16-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_2X16  EQU <008h >  ;/**< 2 channel unsigned 16-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_4X16  EQU <009h >  ;/**< 4 channel unsigned 16-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_1X16  EQU <00ah >  ;/**< 1 channel signed 16-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_2X16  EQU <00bh >  ;/**< 2 channel signed 16-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_4X16  EQU <00ch >  ;/**< 4 channel signed 16-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_1X32  EQU <00dh >  ;/**< 1 channel unsigned 32-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_2X32  EQU <00eh >  ;/**< 2 channel unsigned 32-bit integers */ 
  CU_RES_VIEW_FORMAT_UINT_4X32  EQU <00fh >  ;/**< 4 channel unsigned 32-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_1X32  EQU <010h >  ;/**< 1 channel signed 32-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_2X32  EQU <011h >  ;/**< 2 channel signed 32-bit integers */ 
  CU_RES_VIEW_FORMAT_SINT_4X32  EQU <012h >  ;/**< 4 channel signed 32-bit integers */ 
  CU_RES_VIEW_FORMAT_FLOAT_1X16  EQU <013h >  ;/**< 1 channel 16-bit floating point */ 
  CU_RES_VIEW_FORMAT_FLOAT_2X16  EQU <014h >  ;/**< 2 channel 16-bit floating point */ 
  CU_RES_VIEW_FORMAT_FLOAT_4X16  EQU <015h >  ;/**< 4 channel 16-bit floating point */ 
  CU_RES_VIEW_FORMAT_FLOAT_1X32  EQU <016h >  ;/**< 1 channel 32-bit floating point */ 
  CU_RES_VIEW_FORMAT_FLOAT_2X32  EQU <017h >  ;/**< 2 channel 32-bit floating point */ 
  CU_RES_VIEW_FORMAT_FLOAT_4X32  EQU <018h >  ;/**< 4 channel 32-bit floating point */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC1  EQU <019h >  ;/**< Block compressed 1 */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC2  EQU <01ah >  ;/**< Block compressed 2 */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC3  EQU <01bh >  ;/**< Block compressed 3 */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC4  EQU <01ch >  ;/**< Block compressed 4 unsigned */ 
  CU_RES_VIEW_FORMAT_SIGNED_BC4  EQU <01dh >  ;/**< Block compressed 4 signed */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC5  EQU <01eh >  ;/**< Block compressed 5 unsigned */ 
  CU_RES_VIEW_FORMAT_SIGNED_BC5  EQU <01fh >  ;/**< Block compressed 5 signed */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC6H  EQU <020h >  ;/**< Block compressed 6 unsigned half-float */ 
  CU_RES_VIEW_FORMAT_SIGNED_BC6H  EQU <021h >  ;/**< Block compressed 6 signed half-float */ 
  CU_RES_VIEW_FORMAT_UNSIGNED_BC7  EQU <022h >
;CUresourceViewFormat    ENDS

;/**
; * Resource view descriptor
; */

CUDA_RESOURCE_VIEW_DESC  STRUCT DEFALIGNMASM
  format CUresourceViewFormat ? ;/**< Resource view format */ 
  awidth DWORD ? ;/**< Width of the resource view */ 
  height DWORD ? ;/**< Height of the resource view */ 
  depth DWORD ? ;/**< Depth of the resource view */ 
  firstMipmapLevel DWORD ? ;/**< First defined mipmap level */ 
  lastMipmapLevel DWORD ? ;/**< Last defined mipmap level */ 
  firstLayer DWORD ? ;/**< First layer index */ 
  lastLayer DWORD ? ;/**< Last layer index */ 
  reserved DWORD 16 dup (?)
CUDA_RESOURCE_VIEW_DESC    ENDS


;/**
; * GPU Direct v3 tokens
; */

CUDA_POINTER_ATTRIBUTE_P2P_TOKENS  STRUCT DEFALIGNMASM
  p2pToken QWORD ?
  vaSpaceToken DWORD ?
CUDA_POINTER_ATTRIBUTE_P2P_TOKENS    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 5000 */ 
IF  __CUDA_API_VERSION GE 9000
;/**
; * Kernel launch parameters
; */

CUDA_LAUNCH_PARAMS  STRUCT DEFALIGNMASM
  function XWORD ? ;/**< Kernel to launch */ 
  gridDimX DWORD ? ;/**< Width of grid in blocks */ 
  gridDimY DWORD ? ;/**< Height of grid in blocks */ 
  gridDimZ DWORD ? ;/**< Depth of grid in blocks */ 
  blockDimX DWORD ? ;/**< X dimension of each thread block */ 
  blockDimY DWORD ? ;/**< Y dimension of each thread block */ 
  blockDimZ DWORD ? ;/**< Z dimension of each thread block */ 
  sharedMemBytes DWORD ? ;/**< Dynamic shared-memory size per thread block in bytes */ 
  hStream XWORD ? ;/**< Stream identifier */ 
kernelParams XWORD ?
CUDA_LAUNCH_PARAMS    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 9000 */ 
IF  __CUDA_API_VERSION GE 10000
;/**
; * External memory handle types
; */

CUexternalMemoryHandleType  TYPEDEF DWORD ;enum

;CUexternalMemoryHandleType  UNION DEFALIGNMASM
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD  EQU <1 >
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32  EQU <2 >
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT  EQU <3 >
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP  EQU <4 >
  CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE  EQU <5 >
;CUexternalMemoryHandleType    ENDS


;/**
; * Indicates that the external memory object is a dedicated resource
; */
CUDA_EXTERNAL_MEMORY_DEDICATED  equ  < 01h>
;/**
; * External memory handle descriptor
; */

CUDA_EXTERNAL_MEMORY_HANDLE_DESC  STRUCT DEFALIGNMASM
  atype CUexternalMemoryHandleType ?
  union  handle
  fd DWORD ?
  STRUCT  win32
handle XWORD ?
nameN XWORD ?
  ENDS
  ENDS
  asize QWORD ?
  flags DWORD ?
  reserved DWORD 16 dup (?)
CUDA_EXTERNAL_MEMORY_HANDLE_DESC    ENDS


;/**
; * External memory buffer descriptor
; */

CUDA_EXTERNAL_MEMORY_BUFFER_DESC  STRUCT DEFALIGNMASM
  aoffset QWORD ?
  asize QWORD ?
  flags DWORD ?
  reserved DWORD 16 dup (?)
CUDA_EXTERNAL_MEMORY_BUFFER_DESC    ENDS


;/**
; * External memory mipmap descriptor
; */

CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC  STRUCT DEFALIGNMASM
  aoffset QWORD ?
  arrayDesc CUDA_ARRAY3D_DESCRIPTOR <> 
  numLevels DWORD ?
  reserved DWORD 16 dup (?)
CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC    ENDS


;/**
; * External semaphore handle types
; */

CUexternalSemaphoreHandleType  TYPEDEF DWORD ;enum

;CUexternalSemaphoreHandleType  UNION DEFALIGNMASM
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD  EQU <1 >
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32  EQU <2 >
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT  EQU <3 >
  CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE  EQU <4 >
;CUexternalSemaphoreHandleType    ENDS


;/**
; * External semaphore handle descriptor
; */

CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC  STRUCT DEFALIGNMASM
  atype CUexternalSemaphoreHandleType ?
  union  handle
  fd DWORD ?
  STRUCT  win32
handle XWORD ?
nameN XWORD ?
  ENDS
  ENDS
  flags DWORD ?
  reserved DWORD 16 dup (?)
CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC    ENDS


;/**
; * External semaphore signal parameters
; */

CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS  STRUCT DEFALIGNMASM
  STRUCT  params
  STRUCT  fence
  value QWORD ?
  ENDS
  reserved DWORD 16 dup (?)
  ENDS
  flags DWORD ?
  reserved DWORD 16 dup (?)
CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS    ENDS


;/**
; * External semaphore wait parameters
; */

CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS  STRUCT DEFALIGNMASM
  STRUCT  params
  STRUCT  fence
  value QWORD ?
  ENDS
  reserved DWORD 16 dup (?)
  ENDS
  flags DWORD ?
  reserved DWORD 16 dup (?)
CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS    ENDS


ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
;/**
; * If set, each kernel launched as part of ::cuLaunchCooperativeKernelMultiDevice only
; * waits for prior work in the stream corresponding to that GPU to complete before the
; * kernel begins execution.
; */
CUDA_COOPERATIVE_LAUNCH_MULTI_DEVICE_NO_PRE_LAUNCH_SYNC  equ  < 001h>
;/**
; * If set, any subsequent work pushed in a stream that participated in a call to
; * ::cuLaunchCooperativeKernelMultiDevice will only wait for the kernel launched on
; * the GPU corresponding to that stream to complete before it begins execution.
; */
CUDA_COOPERATIVE_LAUNCH_MULTI_DEVICE_NO_POST_LAUNCH_SYNC  equ  < 002h>
;/**
; * If set, the CUDA array is a collection of layers, where each layer is either a 1D
; * or a 2D array and the Depth member of CUDA_ARRAY3D_DESCRIPTOR specifies the number
; * of layers, not the depth of a 3D array.
; */
CUDA_ARRAY3D_LAYERED  equ  < 001h>
;/**
; * Deprecated, use CUDA_ARRAY3D_LAYERED
; */
CUDA_ARRAY3D_2DARRAY  equ  < 001h>
;/**
; * This flag must be set in order to bind a surface reference
; * to the CUDA array
; */
CUDA_ARRAY3D_SURFACE_LDST  equ  < 002h>
;/**
; * If set, the CUDA array is a collection of six 2D arrays, representing faces of a cube. The
; * width of such a CUDA array must be equal to its height, and Depth must be six.
; * If ::CUDA_ARRAY3D_LAYERED flag is also set, then the CUDA array is a collection of cubemaps
; * and Depth must be a multiple of six.
; */
CUDA_ARRAY3D_CUBEMAP  equ  < 004h>
;/**
; * This flag must be set in order to perform texture gather operations
; * on a CUDA array.
; */
CUDA_ARRAY3D_TEXTURE_GATHER  equ  < 008h>
;/**
; * This flag if set indicates that the CUDA
; * array is a DEPTH_TEXTURE.
; */
CUDA_ARRAY3D_DEPTH_TEXTURE  equ  < 010h>
;/**
; * This flag indicates that the CUDA array may be bound as a color target
; * in an external graphics API
; */
CUDA_ARRAY3D_COLOR_ATTACHMENT  equ  < 020h>
;/**
; * Override the texref format with a format inferred from the array.
; * Flag for ::cuTexRefSetArray()
; */
CU_TRSA_OVERRIDE_FORMAT  equ  < 001h>
;/**
; * Read the texture as integers rather than promoting the values to floats
; * in the range [0,1].
; * Flag for ::cuTexRefSetFlags()
; */
CU_TRSF_READ_AS_INTEGER  equ  < 001h>
;/**
; * Use normalized texture coordinates in the range [0,1) instead of [0,dim).
; * Flag for ::cuTexRefSetFlags()
; */
CU_TRSF_NORMALIZED_COORDINATES  equ  < 002h>
;/**
; * Perform sRGB->linear conversion during texture read.
; * Flag for ::cuTexRefSetFlags()
; */
CU_TRSF_SRGB  equ  < 010h>
;/**
; * End of array terminator for the \p extra parameter to
; * ::cuLaunchKernel
; */
CU_LAUNCH_PARAM_END  equ  <  000h>
;/**
; * Indicator that the next value in the \p extra parameter to
; * ::cuLaunchKernel will be a pointer to a buffer containing all kernel
; * parameters used for launching kernel \p f.  This buffer needs to
; * honor all alignment/padding requirements of the individual parameters.
; * If ::CU_LAUNCH_PARAM_BUFFER_SIZE is not also specified in the
; * \p extra array, then ::CU_LAUNCH_PARAM_BUFFER_POINTER will have no
; * effect.
; */
CU_LAUNCH_PARAM_BUFFER_POINTER  equ  <  001h>
;/**
; * Indicator that the next value in the \p extra parameter to
; * ::cuLaunchKernel will be a pointer to a size_t which contains the
; * size of the buffer specified with ::CU_LAUNCH_PARAM_BUFFER_POINTER.
; * It is required that ::CU_LAUNCH_PARAM_BUFFER_POINTER also be specified
; * in the \p extra array if the value associated with
; * ::CU_LAUNCH_PARAM_BUFFER_SIZE is not zero.
; */
CU_LAUNCH_PARAM_BUFFER_SIZE  equ  <  002h>
;/**
; * For texture references loaded into the module, use default texunit from
; * texture reference.
; */
CU_PARAM_TR_DEFAULT  equ  < - 1>
;/**
; * Device that represents the CPU
; */
CU_DEVICE_CPU  equ  <  - 1>
;/**
; * Device that represents an invalid device
; */
CU_DEVICE_INVALID  equ  <  - 2>
IFDEF _WIN32
CUDAAPI  equ  < __stdcall>
ELSE
CUDAAPI  equ  
ENDIF 
;/**
; * \defgroup CUDA_ERROR Error Handling
; *
; * ___MANBRIEF___ error handling functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the error handling functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Gets the string description of an error code
; *
; * Sets \p *pStr to the address of a NULL-terminated string description
; * of the error code \p error.
; * If the error code is not recognized, ::CUDA_ERROR_INVALID_VALUE
; * will be returned and \p *pStr will be set to the NULL address.
; *
; * \param error - Error code to convert to string
; * \param pStr - Address of the string pointer.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::CUresult,
; * ::cudaGetErrorString
; */
;API
cuGetErrorString PROTO error:CUresult ,pStr:XWORD 
;/**
; * \brief Gets the string representation of an error code enum name
; *
; * Sets \p *pStr to the address of a NULL-terminated string representation
; * of the name of the enum error code \p error.
; * If the error code is not recognized, ::CUDA_ERROR_INVALID_VALUE
; * will be returned and \p *pStr will be set to the NULL address.
; *
; * \param error - Error code to convert to string
; * \param pStr - Address of the string pointer.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::CUresult,
; * ::cudaGetErrorName
; */
;API
cuGetErrorName PROTO error:CUresult ,pStr:XWORD 
;/**
; * \defgroup CUDA_INITIALIZE Initialization
; *
; * ___MANBRIEF___ initialization functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the initialization functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Initialize the CUDA driver API
; *
; * Initializes the driver API and must be called before any other function from
; * the driver API. Currently, the \p Flags parameter must be 0. If ::cuInit()
; * has not been called, any function from the driver API will return
; * ::CUDA_ERROR_NOT_INITIALIZED.
; *
; * \param Flags - Initialization flag for CUDA.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_SYSTEM_DRIVER_MISMATCH,
; * ::CUDA_ERROR_COMPAT_NOT_SUPPORTED_ON_DEVICE
; * \notefnerr
; */
;API
cuInit PROTO Flags:DWORD 
;/**
; * \defgroup CUDA_VERSION Version Management
; *
; * ___MANBRIEF___ version management functions of the low-level CUDA driver
; * API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the version management functions of the low-level
; * CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Returns the latest CUDA version supported by driver
; *
; * Returns in \p *driverVersion the version of CUDA supported by
; * the driver.  The version is returned as
; * (1000 &times; major + 10 &times; minor). For example, CUDA 9.2
; * would be represented by 9020.
; *
; * This function automatically returns ::CUDA_ERROR_INVALID_VALUE if
; * \p driverVersion is NULL.
; *
; * \param driverVersion - Returns the CUDA driver version
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cudaDriverGetVersion,
; * ::cudaRuntimeGetVersion
; */
;API
cuDriverGetVersion PROTO driverVersion:XWORD 
;/**
; * \defgroup CUDA_DEVICE Device Management
; *
; * ___MANBRIEF___ device management functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the device management functions of the low-level
; * CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Returns a handle to a compute device
; *
; * Returns in \p *device a device handle given an ordinal in the range <b>[0,
; * ::cuDeviceGetCount()-1]</b>.
; *
; * \param device  - Returned device handle
; * \param ordinal - Device number to get handle for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGetLuid,
; * ::cuDeviceTotalMem
; */
;API
cuDeviceGet PROTO device:XWORD ,ordinal:DWORD 
;/**
; * \brief Returns the number of compute-capable devices
; *
; * Returns in \p *count the number of devices with compute capability greater
; * than or equal to 2.0 that are available for execution. If there is no such
; * device, ::cuDeviceGetCount() returns 0.
; *
; * \param count - Returned number of compute-capable devices
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetName,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGetLuid,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem,
; * ::cudaGetDeviceCount
; */
;API
cuDeviceGetCount PROTO count:XWORD 
;/**
; * \brief Returns an identifer string for the device
; *
; * Returns an ASCII string identifying the device \p dev in the NULL-terminated
; * string pointed to by \p name. \p len specifies the maximum length of the
; * string that may be returned.
; *
; * \param name - Returned identifier string for the device
; * \param len  - Maximum length of string to store in \p name
; * \param dev  - Device to get identifier string for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGetLuid,
; * ::cuDeviceGetCount,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem,
; * ::cudaGetDeviceProperties
; */
;API
cuDeviceGetName PROTO aname:XWORD ,len:DWORD ,dev:DWORD 
IF  __CUDA_API_VERSION GE 9020
;/**
; * \brief Return an UUID for the device
; *
; * Returns 16-octets identifing the device \p dev in the structure
; * pointed by the \p uuid.
; *
; * \param uuid - Returned UUID
; * \param dev  - Device to get identifier string for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGetLuid,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem,
; * ::cudaGetDeviceProperties
; */
;API
cuDeviceGetUuid PROTO uuid:XWORD ,dev:DWORD 
ENDIF 
IF Defined(_WIN32) AND  __CUDA_API_VERSION GE 10000
;/**
; * \brief Return an LUID and device node mask for the device
; *
; * Return identifying information (\p luid and \p deviceNodeMask) to allow
; * matching device with graphics APIs.
; *
; * \param luid - Returned LUID
; * \param deviceNodeMask - Returned device node mask
; * \param dev  - Device to get identifier string for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem,
; * ::cudaGetDeviceProperties
; */
;API
cuDeviceGetLuid PROTO luid:XWORD ,deviceNodeMask:XWORD ,dev:DWORD 
ENDIF 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Returns the total amount of memory on the device
; *
; * Returns in \p *bytes the total amount of memory available on the device
; * \p dev in bytes.
; *
; * \param bytes - Returned memory available on device in bytes
; * \param dev   - Device handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGet,
; * ::cudaMemGetInfo
; */
;API
cuDeviceTotalMem PROTO bytes:XWORD ,dev:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Returns information about the device
; *
; * Returns in \p *pi the integer value of the attribute \p attrib on device
; * \p dev. The supported attributes are:
; * - ::CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK: Maximum number of threads per
; *   block;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X: Maximum x-dimension of a block;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y: Maximum y-dimension of a block;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z: Maximum z-dimension of a block;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X: Maximum x-dimension of a grid;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y: Maximum y-dimension of a grid;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z: Maximum z-dimension of a grid;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK: Maximum amount of
; *   shared memory available to a thread block in bytes;
; * - ::CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY: Memory available on device for
; *   __constant__ variables in a CUDA C kernel in bytes;
; * - ::CU_DEVICE_ATTRIBUTE_WARP_SIZE: Warp size in threads;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_PITCH: Maximum pitch in bytes allowed by the
; *   memory copy functions that involve memory regions allocated through
; *   ::cuMemAllocPitch();
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH: Maximum 1D
; *  texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH: Maximum width
; *  for a 1D texture bound to linear memory;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH: Maximum
; *  mipmapped 1D texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH: Maximum 2D
; *  texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT: Maximum 2D
; *  texture height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH: Maximum width
; *  for a 2D texture bound to linear memory;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT: Maximum height
; *  for a 2D texture bound to linear memory;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH: Maximum pitch
; *  in bytes for a 2D texture bound to linear memory;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH: Maximum
; *  mipmapped 2D texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT: Maximum
; *  mipmapped 2D texture height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH: Maximum 3D
; *  texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT: Maximum 3D
; *  texture height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH: Maximum 3D
; *  texture depth;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE:
; *  Alternate maximum 3D texture width, 0 if no alternate
; *  maximum 3D texture size is supported;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE:
; *  Alternate maximum 3D texture height, 0 if no alternate
; *  maximum 3D texture size is supported;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE:
; *  Alternate maximum 3D texture depth, 0 if no alternate
; *  maximum 3D texture size is supported;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH:
; *  Maximum cubemap texture width or height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH:
; *  Maximum 1D layered texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS:
; *   Maximum layers in a 1D layered texture;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH:
; *  Maximum 2D layered texture width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT:
; *   Maximum 2D layered texture height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS:
; *   Maximum layers in a 2D layered texture;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH:
; *   Maximum cubemap layered texture width or height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS:
; *   Maximum layers in a cubemap layered texture;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH:
; *   Maximum 1D surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH:
; *   Maximum 2D surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT:
; *   Maximum 2D surface height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH:
; *   Maximum 3D surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT:
; *   Maximum 3D surface height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH:
; *   Maximum 3D surface depth;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH:
; *   Maximum 1D layered surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS:
; *   Maximum layers in a 1D layered surface;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH:
; *   Maximum 2D layered surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT:
; *   Maximum 2D layered surface height;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS:
; *   Maximum layers in a 2D layered surface;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH:
; *   Maximum cubemap surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH:
; *   Maximum cubemap layered surface width;
; * - ::CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS:
; *   Maximum layers in a cubemap layered surface;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK: Maximum number of 32-bit
; *   registers available to a thread block;
; * - ::CU_DEVICE_ATTRIBUTE_CLOCK_RATE: The typical clock frequency in kilohertz;
; * - ::CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT: Alignment requirement; texture
; *   base addresses aligned to ::textureAlign bytes do not need an offset
; *   applied to texture fetches;
; * - ::CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT: Pitch alignment requirement
; *   for 2D texture references bound to pitched memory;
; * - ::CU_DEVICE_ATTRIBUTE_GPU_OVERLAP: 1 if the device can concurrently copy
; *   memory between host and device while executing a kernel, or 0 if not;
; * - ::CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT: Number of multiprocessors on
; *   the device;
; * - ::CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT: 1 if there is a run time limit
; *   for kernels executed on the device, or 0 if not;
; * - ::CU_DEVICE_ATTRIBUTE_INTEGRATED: 1 if the device is integrated with the
; *   memory subsystem, or 0 if not;
; * - ::CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY: 1 if the device can map host
; *   memory into the CUDA address space, or 0 if not;
; * - ::CU_DEVICE_ATTRIBUTE_COMPUTE_MODE: Compute mode that device is currently
; *   in. Available modes are as follows:
; *   - ::CU_COMPUTEMODE_DEFAULT: Default mode - Device is not restricted and
; *     can have multiple CUDA contexts present at a single time.
; *   - ::CU_COMPUTEMODE_PROHIBITED: Compute-prohibited mode - Device is
; *     prohibited from creating new CUDA contexts.
; *   - ::CU_COMPUTEMODE_EXCLUSIVE_PROCESS:  Compute-exclusive-process mode - Device
; *     can have only one context used by a single process at a time.
; * - ::CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS: 1 if the device supports
; *   executing multiple kernels within the same context simultaneously, or 0 if
; *   not. It is not guaranteed that multiple kernels will be resident
; *   on the device concurrently so this feature should not be relied upon for
; *   correctness;
; * - ::CU_DEVICE_ATTRIBUTE_ECC_ENABLED: 1 if error correction is enabled on the
; *    device, 0 if error correction is disabled or not supported by the device;
; * - ::CU_DEVICE_ATTRIBUTE_PCI_BUS_ID: PCI bus identifier of the device;
; * - ::CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID: PCI device (also known as slot) identifier
; *   of the device;
; * - ::CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID: PCI domain identifier of the device
; * - ::CU_DEVICE_ATTRIBUTE_TCC_DRIVER: 1 if the device is using a TCC driver. TCC
; *    is only available on Tesla hardware running Windows Vista or later;
; * - ::CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE: Peak memory clock frequency in kilohertz;
; * - ::CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH: Global memory bus width in bits;
; * - ::CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE: Size of L2 cache in bytes. 0 if the device doesn't have L2 cache;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR: Maximum resident threads per multiprocessor;
; * - ::CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING: 1 if the device shares a unified address space with
; *   the host, or 0 if not;
; * - ::CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR: Major compute capability version number;
; * - ::CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR: Minor compute capability version number;
; * - ::CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED: 1 if device supports caching globals
; *    in L1 cache, 0 if caching globals in L1 cache is not supported by the device;
; * - ::CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED: 1 if device supports caching locals
; *    in L1 cache, 0 if caching locals in L1 cache is not supported by the device;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR: Maximum amount of
; *   shared memory available to a multiprocessor in bytes; this amount is shared
; *   by all thread blocks simultaneously resident on a multiprocessor;
; * - ::CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR: Maximum number of 32-bit
; *   registers available to a multiprocessor; this number is shared by all thread
; *   blocks simultaneously resident on a multiprocessor;
; * - ::CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY: 1 if device supports allocating managed memory
; *   on this system, 0 if allocating managed memory is not supported by the device on this system.
; * - ::CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD: 1 if device is on a multi-GPU board, 0 if not.
; * - ::CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID: Unique identifier for a group of devices
; *   associated with the same board. Devices on the same multi-GPU board will share the same identifier.
; * - ::CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED: 1 if Link between the device and the host
; *   supports native atomic operations.
; * - ::CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO: Ratio of single precision performance
; *   (in floating-point operations per second) to double precision performance.
; * - ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS: Device suppports coherently accessing
; *   pageable memory without calling cudaHostRegister on it.
; * - ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS: Device can coherently access managed memory
; *   concurrently with the CPU.
; * - ::CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED: Device supports Compute Preemption.
; * - ::CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM: Device can access host registered
; *   memory at the same virtual address as the CPU.
; * -  ::CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN: The maximum per block shared memory size
; *    suported on this device. This is the maximum value that can be opted into when using the cuFuncSetAttribute() call.
; *    For more details see ::CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES
; * - ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES: Device accesses pageable memory via the host's
; *   page tables.
; * - ::CU_DEVICE_ATTRIBUTE_DIRECT_MANAGED_MEM_ACCESS_FROM_HOST: The host can directly access managed memory on the device without migration.
; *
; * \param pi     - Returned device attribute value
; * \param attrib - Device attribute to query
; * \param dev    - Device handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem,
; * ::cudaDeviceGetAttribute,
; * ::cudaGetDeviceProperties
; */
;API
cuDeviceGetAttribute PROTO pi:XWORD ,attrib:CUdevice_attribute ,dev:DWORD 
;/**
; * \defgroup CUDA_DEVICE_DEPRECATED Device Management [DEPRECATED]
; *
; * ___MANBRIEF___ deprecated device management functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the device management functions of the low-level
; * CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Returns properties for a selected device
; *
; * \deprecated
; *
; * This function was deprecated as of CUDA 5.0 and replaced by ::cuDeviceGetAttribute().
; *
; * Returns in \p *prop the properties of device \p dev. The ::CUdevprop
; * structure is defined as:
; *
; * \code
;     typedef struct CUdevprop_st {
;     int maxThreadsPerBlock;
;     int maxThreadsDim[3];
;     int maxGridSize[3];
;     int sharedMemPerBlock;
;     int totalConstantMemory;
;     int SIMDWidth;
;     int memPitch;
;     int regsPerBlock;
;     int clockRate;
;     int textureAlign
;  } CUdevprop;
; * \endcode
; * where:
; *
; * - ::maxThreadsPerBlock is the maximum number of threads per block;
; * - ::maxThreadsDim[3] is the maximum sizes of each dimension of a block;
; * - ::maxGridSize[3] is the maximum sizes of each dimension of a grid;
; * - ::sharedMemPerBlock is the total amount of shared memory available per
; *   block in bytes;
; * - ::totalConstantMemory is the total amount of constant memory available on
; *   the device in bytes;
; * - ::SIMDWidth is the warp size;
; * - ::memPitch is the maximum pitch allowed by the memory copy functions that
; *   involve memory regions allocated through ::cuMemAllocPitch();
; * - ::regsPerBlock is the total number of registers available per block;
; * - ::clockRate is the clock frequency in kilohertz;
; * - ::textureAlign is the alignment requirement; texture base addresses that
; *   are aligned to ::textureAlign bytes do not need an offset applied to
; *   texture fetches.
; *
; * \param prop - Returned properties of device
; * \param dev  - Device to get properties for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem
; */
;API
cuDeviceGetProperties PROTO prop:XWORD ,dev:DWORD 
;/**
; * \brief Returns the compute capability of the device
; *
; * \deprecated
; *
; * This function was deprecated as of CUDA 5.0 and its functionality superceded
; * by ::cuDeviceGetAttribute().
; *
; * Returns in \p *major and \p *minor the major and minor revision numbers that
; * define the compute capability of the device \p dev.
; *
; * \param major - Major revision number
; * \param minor - Minor revision number
; * \param dev   - Device handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetCount,
; * ::cuDeviceGetName,
; * ::cuDeviceGetUuid,
; * ::cuDeviceGet,
; * ::cuDeviceTotalMem
; */
;API
cuDeviceComputeCapability PROTO major:XWORD ,minor:XWORD ,dev:DWORD 
;/**
; * \defgroup CUDA_PRIMARY_CTX Primary Context Management
; *
; * ___MANBRIEF___ primary context management functions of the low-level CUDA driver
; * API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the primary context management functions of the low-level
; * CUDA driver application programming interface.
; *
; * The primary context is unique per device and shared with the CUDA runtime API.
; * These functions allow integration with other libraries using CUDA.
; *
; * @{
; */
IF  __CUDA_API_VERSION GE 7000
;/**
; * \brief Retain the primary context on the GPU
; *
; * Retains the primary context on the device, creating it if necessary,
; * increasing its usage count. The caller must call
; * ::cuDevicePrimaryCtxRelease() when done using the context.
; * Unlike ::cuCtxCreate() the newly created context is not pushed onto the stack.
; *
; * Context creation will fail with ::CUDA_ERROR_UNKNOWN if the compute mode of
; * the device is ::CU_COMPUTEMODE_PROHIBITED.  The function ::cuDeviceGetAttribute()
; * can be used with ::CU_DEVICE_ATTRIBUTE_COMPUTE_MODE to determine the compute mode
; * of the device.
; * The <i>nvidia-smi</i> tool can be used to set the compute mode for
; * devices. Documentation for <i>nvidia-smi</i> can be obtained by passing a
; * -h option to it.
; *
; * Please note that the primary context always supports pinned allocations. Other
; * flags can be specified by ::cuDevicePrimaryCtxSetFlags().
; *
; * \param pctx  - Returned context handle of the new context
; * \param dev   - Device for which primary context is requested
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa ::cuDevicePrimaryCtxRelease,
; * ::cuDevicePrimaryCtxSetFlags,
; * ::cuCtxCreate,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuDevicePrimaryCtxRetain PROTO pctx:XWORD ,dev:DWORD 
;/**
; * \brief Release the primary context on the GPU
; *
; * Releases the primary context interop on the device by decreasing the usage
; * count by 1. If the usage drops to 0 the primary context of device \p dev
; * will be destroyed regardless of how many threads it is current to.
; *
; * Please note that unlike ::cuCtxDestroy() this method does not pop the context
; * from stack in any circumstances.
; *
; * \param dev - Device which primary context is released
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa ::cuDevicePrimaryCtxRetain,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuDevicePrimaryCtxRelease PROTO dev:DWORD 
;/**
; * \brief Set flags for the primary context
; *
; * Sets the flags for the primary context on the device overwriting perviously
; * set ones. If the primary context is already created
; * ::CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE is returned.
; *
; * The three LSBs of the \p flags parameter can be used to control how the OS
; * thread, which owns the CUDA context at the time of an API call, interacts
; * with the OS scheduler when waiting for results from the GPU. Only one of
; * the scheduling flags can be set when creating a context.
; *
; * - ::CU_CTX_SCHED_SPIN: Instruct CUDA to actively spin when waiting for
; * results from the GPU. This can decrease latency when waiting for the GPU,
; * but may lower the performance of CPU threads if they are performing work in
; * parallel with the CUDA thread.
; *
; * - ::CU_CTX_SCHED_YIELD: Instruct CUDA to yield its thread when waiting for
; * results from the GPU. This can increase latency when waiting for the GPU,
; * but can increase the performance of CPU threads performing work in parallel
; * with the GPU.
; *
; * - ::CU_CTX_SCHED_BLOCKING_SYNC: Instruct CUDA to block the CPU thread on a
; * synchronization primitive when waiting for the GPU to finish work.
; *
; * - ::CU_CTX_BLOCKING_SYNC: Instruct CUDA to block the CPU thread on a
; * synchronization primitive when waiting for the GPU to finish work. <br>
; * <b>Deprecated:</b> This flag was deprecated as of CUDA 4.0 and was
; * replaced with ::CU_CTX_SCHED_BLOCKING_SYNC.
; *
; * - ::CU_CTX_SCHED_AUTO: The default value if the \p flags parameter is zero,
; * uses a heuristic based on the number of active CUDA contexts in the
; * process \e C and the number of logical processors in the system \e P. If
; * \e C > \e P, then CUDA will yield to other OS threads when waiting for
; * the GPU (::CU_CTX_SCHED_YIELD), otherwise CUDA will not yield while
; * waiting for results and actively spin on the processor (::CU_CTX_SCHED_SPIN).
; * Additionally, on Tegra devices, ::CU_CTX_SCHED_AUTO uses a heuristic based on
; * the power profile of the platform and may choose ::CU_CTX_SCHED_BLOCKING_SYNC
; * for low-powered devices.
; *
; * - ::CU_CTX_LMEM_RESIZE_TO_MAX: Instruct CUDA to not reduce local memory
; * after resizing local memory for a kernel. This can prevent thrashing by
; * local memory allocations when launching many kernels with high local
; * memory usage at the cost of potentially increased memory usage.
; *
; * \param dev   - Device for which the primary context flags are set
; * \param flags - New flags for the device
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE
; * \notefnerr
; *
; * \sa ::cuDevicePrimaryCtxRetain,
; * ::cuDevicePrimaryCtxGetState,
; * ::cuCtxCreate,
; * ::cuCtxGetFlags,
; * ::cudaSetDeviceFlags
; */
;API
cuDevicePrimaryCtxSetFlags PROTO dev:DWORD ,flags:DWORD 
;/**
; * \brief Get the state of the primary context
; *
; * Returns in \p *flags the flags for the primary context of \p dev, and in
; * \p *active whether it is active.  See ::cuDevicePrimaryCtxSetFlags for flag
; * values.
; *
; * \param dev    - Device to get primary context flags for
; * \param flags  - Pointer to store flags
; * \param active - Pointer to store context state; 0 = inactive, 1 = active
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \notefnerr
; *
; * \sa
; * ::cuDevicePrimaryCtxSetFlags,
; * ::cuCtxGetFlags,
; * ::cudaGetDeviceFlags
; */
;API
cuDevicePrimaryCtxGetState PROTO dev:DWORD ,flags:XWORD ,active:XWORD 
;/**
; * \brief Destroy all allocations and reset all state on the primary context
; *
; * Explicitly destroys and cleans up all resources associated with the current
; * device in the current process.
; *
; * Note that it is responsibility of the calling function to ensure that no
; * other module in the process is using the device any more. For that reason
; * it is recommended to use ::cuDevicePrimaryCtxRelease() in most cases.
; * However it is safe for other modules to call ::cuDevicePrimaryCtxRelease()
; * even after resetting the device.
; *
; * \param dev - Device for which primary context is destroyed
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE
; * \notefnerr
; *
; * \sa ::cuDevicePrimaryCtxRetain,
; * ::cuDevicePrimaryCtxRelease,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cudaDeviceReset
; */
;API
cuDevicePrimaryCtxReset PROTO dev:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 7000 */ 
;/**
; * \defgroup CUDA_CTX Context Management
; *
; * ___MANBRIEF___ context management functions of the low-level CUDA driver
; * API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the context management functions of the low-level
; * CUDA driver application programming interface.
; *
; * Please note that some functions are described in
; * \ref CUDA_PRIMARY_CTX "Primary Context Management" section.
; *
; * @{
; */
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Create a CUDA context
; *
; * \note In most cases it is recommended to use ::cuDevicePrimaryCtxRetain.
; *
; * Creates a new CUDA context and associates it with the calling thread. The
; * \p flags parameter is described below. The context is created with a usage
; * count of 1 and the caller of ::cuCtxCreate() must call ::cuCtxDestroy() or
; * when done using the context. If a context is already current to the thread,
; * it is supplanted by the newly created context and may be restored by a subsequent
; * call to ::cuCtxPopCurrent().
; *
; * The three LSBs of the \p flags parameter can be used to control how the OS
; * thread, which owns the CUDA context at the time of an API call, interacts
; * with the OS scheduler when waiting for results from the GPU. Only one of
; * the scheduling flags can be set when creating a context.
; *
; * - ::CU_CTX_SCHED_SPIN: Instruct CUDA to actively spin when waiting for
; * results from the GPU. This can decrease latency when waiting for the GPU,
; * but may lower the performance of CPU threads if they are performing work in
; * parallel with the CUDA thread.
; *
; * - ::CU_CTX_SCHED_YIELD: Instruct CUDA to yield its thread when waiting for
; * results from the GPU. This can increase latency when waiting for the GPU,
; * but can increase the performance of CPU threads performing work in parallel
; * with the GPU.
; *
; * - ::CU_CTX_SCHED_BLOCKING_SYNC: Instruct CUDA to block the CPU thread on a
; * synchronization primitive when waiting for the GPU to finish work.
; *
; * - ::CU_CTX_BLOCKING_SYNC: Instruct CUDA to block the CPU thread on a
; * synchronization primitive when waiting for the GPU to finish work. <br>
; * <b>Deprecated:</b> This flag was deprecated as of CUDA 4.0 and was
; * replaced with ::CU_CTX_SCHED_BLOCKING_SYNC.
; *
; * - ::CU_CTX_SCHED_AUTO: The default value if the \p flags parameter is zero,
; * uses a heuristic based on the number of active CUDA contexts in the
; * process \e C and the number of logical processors in the system \e P. If
; * \e C > \e P, then CUDA will yield to other OS threads when waiting for
; * the GPU (::CU_CTX_SCHED_YIELD), otherwise CUDA will not yield while
; * waiting for results and actively spin on the processor (::CU_CTX_SCHED_SPIN).
; * Additionally, on Tegra devices, ::CU_CTX_SCHED_AUTO uses a heuristic based on
; * the power profile of the platform and may choose ::CU_CTX_SCHED_BLOCKING_SYNC
; * for low-powered devices.
; *
; * - ::CU_CTX_MAP_HOST: Instruct CUDA to support mapped pinned allocations.
; * This flag must be set in order to allocate pinned host memory that is
; * accessible to the GPU.
; *
; * - ::CU_CTX_LMEM_RESIZE_TO_MAX: Instruct CUDA to not reduce local memory
; * after resizing local memory for a kernel. This can prevent thrashing by
; * local memory allocations when launching many kernels with high local
; * memory usage at the cost of potentially increased memory usage.
; *
; * Context creation will fail with ::CUDA_ERROR_UNKNOWN if the compute mode of
; * the device is ::CU_COMPUTEMODE_PROHIBITED. The function ::cuDeviceGetAttribute()
; * can be used with ::CU_DEVICE_ATTRIBUTE_COMPUTE_MODE to determine the
; * compute mode of the device. The <i>nvidia-smi</i> tool can be used to set
; * the compute mode for * devices.
; * Documentation for <i>nvidia-smi</i> can be obtained by passing a
; * -h option to it.
; *
; * \param pctx  - Returned context handle of the new context
; * \param flags - Context creation flags
; * \param dev   - Device to create context on
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxCreate PROTO pctx:XWORD ,flags:DWORD ,dev:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Destroy a CUDA context
; *
; * Destroys the CUDA context specified by \p ctx.  The context \p ctx will be
; * destroyed regardless of how many threads it is current to.
; * It is the responsibility of the calling function to ensure that no API
; * call issues using \p ctx while ::cuCtxDestroy() is executing.
; *
; * If \p ctx is current to the calling thread then \p ctx will also be
; * popped from the current thread's context stack (as though ::cuCtxPopCurrent()
; * were called).  If \p ctx is current to other threads, then \p ctx will
; * remain current to those threads, and attempting to access \p ctx from
; * those threads will result in the error ::CUDA_ERROR_CONTEXT_IS_DESTROYED.
; *
; * \param ctx - Context to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxDestroy PROTO ctx:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Pushes a context on the current CPU thread
; *
; * Pushes the given context \p ctx onto the CPU thread's stack of current
; * contexts. The specified context becomes the CPU thread's current context, so
; * all CUDA functions that operate on the current context are affected.
; *
; * The previous current context may be made current again by calling
; * ::cuCtxDestroy() or ::cuCtxPopCurrent().
; *
; * \param ctx - Context to push
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxPushCurrent PROTO ctx:XWORD 
;/**
; * \brief Pops the current CUDA context from the current CPU thread.
; *
; * Pops the current CUDA context from the CPU thread and passes back the
; * old context handle in \p *pctx. That context may then be made current
; * to a different CPU thread by calling ::cuCtxPushCurrent().
; *
; * If a context was current to the CPU thread before ::cuCtxCreate() or
; * ::cuCtxPushCurrent() was called, this function makes that context current to
; * the CPU thread again.
; *
; * \param pctx - Returned new context handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxPopCurrent PROTO pctx:XWORD 
;/**
; * \brief Binds the specified CUDA context to the calling CPU thread
; *
; * Binds the specified CUDA context to the calling CPU thread.
; * If \p ctx is NULL then the CUDA context previously bound to the
; * calling CPU thread is unbound and ::CUDA_SUCCESS is returned.
; *
; * If there exists a CUDA context stack on the calling CPU thread, this
; * will replace the top of that stack with \p ctx.
; * If \p ctx is NULL then this will be equivalent to popping the top
; * of the calling CPU thread's CUDA context stack (or a no-op if the
; * calling CPU thread's CUDA context stack is empty).
; *
; * \param ctx - Context to bind to the calling CPU thread
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa
; * ::cuCtxGetCurrent,
; * ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cudaSetDevice
; */
;API
cuCtxSetCurrent PROTO ctx:XWORD 
;/**
; * \brief Returns the CUDA context bound to the calling CPU thread.
; *
; * Returns in \p *pctx the CUDA context bound to the calling CPU thread.
; * If no context is bound to the calling CPU thread then \p *pctx is
; * set to NULL and ::CUDA_SUCCESS is returned.
; *
; * \param pctx - Returned context handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * \notefnerr
; *
; * \sa
; * ::cuCtxSetCurrent,
; * ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cudaGetDevice
; */
;API
cuCtxGetCurrent PROTO pctx:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
;/**
; * \brief Returns the device ID for the current context
; *
; * Returns in \p *device the ordinal of the current context's device.
; *
; * \param device - Returned device ID for the current context
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cudaGetDevice
; */
;API
cuCtxGetDevice PROTO device:XWORD 
IF  __CUDA_API_VERSION GE 7000
;/**
; * \brief Returns the flags for the current context
; *
; * Returns in \p *flags the flags of the current context. See ::cuCtxCreate
; * for flag values.
; *
; * \param flags - Pointer to store flags of current context
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetCurrent,
; * ::cuCtxGetDevice
; * ::cuCtxGetLimit,
; * ::cuCtxGetSharedMemConfig,
; * ::cuCtxGetStreamPriorityRange,
; * ::cudaGetDeviceFlags
; */
;API
cuCtxGetFlags PROTO flags:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 7000 */ 
;/**
; * \brief Block for a context's tasks to complete
; *
; * Blocks until the device has completed all preceding requested tasks.
; * ::cuCtxSynchronize() returns an error if one of the preceding tasks failed.
; * If the context was created with the ::CU_CTX_SCHED_BLOCKING_SYNC flag, the
; * CPU thread will block until the GPU context has finished its work.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cudaDeviceSynchronize
; */
;API
cuCtxSynchronize PROTO  
;/**
; * \brief Set resource limits
; *
; * Setting \p limit to \p value is a request by the application to update
; * the current limit maintained by the context. The driver is free to
; * modify the requested value to meet h/w requirements (this could be
; * clamping to minimum or maximum values, rounding up to nearest element
; * size, etc). The application can use ::cuCtxGetLimit() to find out exactly
; * what the limit has been set to.
; *
; * Setting each ::CUlimit has its own specific restrictions, so each is
; * discussed here.
; *
; * - ::CU_LIMIT_STACK_SIZE controls the stack size in bytes of each GPU thread.
; *
; * - ::CU_LIMIT_PRINTF_FIFO_SIZE controls the size in bytes of the FIFO used
; *   by the ::printf() device system call. Setting ::CU_LIMIT_PRINTF_FIFO_SIZE
; *   must be performed before launching any kernel that uses the ::printf()
; *   device system call, otherwise ::CUDA_ERROR_INVALID_VALUE will be returned.
; *
; * - ::CU_LIMIT_MALLOC_HEAP_SIZE controls the size in bytes of the heap used
; *   by the ::malloc() and ::free() device system calls. Setting
; *   ::CU_LIMIT_MALLOC_HEAP_SIZE must be performed before launching any kernel
; *   that uses the ::malloc() or ::free() device system calls, otherwise
; *   ::CUDA_ERROR_INVALID_VALUE will be returned.
; *
; * - ::CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH controls the maximum nesting depth of
; *   a grid at which a thread can safely call ::cudaDeviceSynchronize(). Setting
; *   this limit must be performed before any launch of a kernel that uses the
; *   device runtime and calls ::cudaDeviceSynchronize() above the default sync
; *   depth, two levels of grids. Calls to ::cudaDeviceSynchronize() will fail
; *   with error code ::cudaErrorSyncDepthExceeded if the limitation is
; *   violated. This limit can be set smaller than the default or up the maximum
; *   launch depth of 24. When setting this limit, keep in mind that additional
; *   levels of sync depth require the driver to reserve large amounts of device
; *   memory which can no longer be used for user allocations. If these
; *   reservations of device memory fail, ::cuCtxSetLimit will return
; *   ::CUDA_ERROR_OUT_OF_MEMORY, and the limit can be reset to a lower value.
; *   This limit is only applicable to devices of compute capability 3.5 and
; *   higher. Attempting to set this limit on devices of compute capability less
; *   than 3.5 will result in the error ::CUDA_ERROR_UNSUPPORTED_LIMIT being
; *   returned.
; *
; * - ::CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT controls the maximum number of
; *   outstanding device runtime launches that can be made from the current
; *   context. A grid is outstanding from the point of launch up until the grid
; *   is known to have been completed. Device runtime launches which violate
; *   this limitation fail and return ::cudaErrorLaunchPendingCountExceeded when
; *   ::cudaGetLastError() is called after launch. If more pending launches than
; *   the default (2048 launches) are needed for a module using the device
; *   runtime, this limit can be increased. Keep in mind that being able to
; *   sustain additional pending launches will require the driver to reserve
; *   larger amounts of device memory upfront which can no longer be used for
; *   allocations. If these reservations fail, ::cuCtxSetLimit will return
; *   ::CUDA_ERROR_OUT_OF_MEMORY, and the limit can be reset to a lower value.
; *   This limit is only applicable to devices of compute capability 3.5 and
; *   higher. Attempting to set this limit on devices of compute capability less
; *   than 3.5 will result in the error ::CUDA_ERROR_UNSUPPORTED_LIMIT being
; *   returned.
; *
; * - ::CU_LIMIT_MAX_L2_FETCH_GRANULARITY controls the L2 cache fetch granularity.
; *   Values can range from 0B to 128B. This is purely a performance hint and
; *   it can be ignored or clamped depending on the platform.
; *
; * \param limit - Limit to set
; * \param value - Size of limit
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNSUPPORTED_LIMIT,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSynchronize,
; * ::cudaDeviceSetLimit
; */
;API
cuCtxSetLimit PROTO limit:CUlimit ,value:DWORD 
;/**
; * \brief Returns resource limits
; *
; * Returns in \p *pvalue the current size of \p limit.  The supported
; * ::CUlimit values are:
; * - ::CU_LIMIT_STACK_SIZE: stack size in bytes of each GPU thread.
; * - ::CU_LIMIT_PRINTF_FIFO_SIZE: size in bytes of the FIFO used by the
; *   ::printf() device system call.
; * - ::CU_LIMIT_MALLOC_HEAP_SIZE: size in bytes of the heap used by the
; *   ::malloc() and ::free() device system calls.
; * - ::CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH: maximum grid depth at which a thread
; *   can issue the device runtime call ::cudaDeviceSynchronize() to wait on
; *   child grid launches to complete.
; * - ::CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT: maximum number of outstanding
; *   device runtime launches that can be made from this context.
; * - ::CU_LIMIT_MAX_L2_FETCH_GRANULARITY: L2 cache fetch granularity.
; *
; * \param limit  - Limit to query
; * \param pvalue - Returned size of limit
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNSUPPORTED_LIMIT
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cudaDeviceGetLimit
; */
;API
cuCtxGetLimit PROTO pvalue:XWORD ,limit:CUlimit 
;/**
; * \brief Returns the preferred cache configuration for the current context.
; *
; * On devices where the L1 cache and shared memory use the same hardware
; * resources, this function returns through \p pconfig the preferred cache configuration
; * for the current context. This is only a preference. The driver will use
; * the requested configuration if possible, but it is free to choose a different
; * configuration if required to execute functions.
; *
; * This will return a \p pconfig of ::CU_FUNC_CACHE_PREFER_NONE on devices
; * where the size of the L1 cache and shared memory are fixed.
; *
; * The supported cache configurations are:
; * - ::CU_FUNC_CACHE_PREFER_NONE: no preference for shared memory or L1 (default)
; * - ::CU_FUNC_CACHE_PREFER_SHARED: prefer larger shared memory and smaller L1 cache
; * - ::CU_FUNC_CACHE_PREFER_L1: prefer larger L1 cache and smaller shared memory
; * - ::CU_FUNC_CACHE_PREFER_EQUAL: prefer equal sized L1 cache and shared memory
; *
; * \param pconfig - Returned cache configuration
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cuFuncSetCacheConfig,
; * ::cudaDeviceGetCacheConfig
; */
;API
cuCtxGetCacheConfig PROTO pconfig:XWORD 
;/**
; * \brief Sets the preferred cache configuration for the current context.
; *
; * On devices where the L1 cache and shared memory use the same hardware
; * resources, this sets through \p config the preferred cache configuration for
; * the current context. This is only a preference. The driver will use
; * the requested configuration if possible, but it is free to choose a different
; * configuration if required to execute the function. Any function preference
; * set via ::cuFuncSetCacheConfig() will be preferred over this context-wide
; * setting. Setting the context-wide cache configuration to
; * ::CU_FUNC_CACHE_PREFER_NONE will cause subsequent kernel launches to prefer
; * to not change the cache configuration unless required to launch the kernel.
; *
; * This setting does nothing on devices where the size of the L1 cache and
; * shared memory are fixed.
; *
; * Launching a kernel with a different preference than the most recent
; * preference setting may insert a device-side synchronization point.
; *
; * The supported cache configurations are:
; * - ::CU_FUNC_CACHE_PREFER_NONE: no preference for shared memory or L1 (default)
; * - ::CU_FUNC_CACHE_PREFER_SHARED: prefer larger shared memory and smaller L1 cache
; * - ::CU_FUNC_CACHE_PREFER_L1: prefer larger L1 cache and smaller shared memory
; * - ::CU_FUNC_CACHE_PREFER_EQUAL: prefer equal sized L1 cache and shared memory
; *
; * \param config - Requested cache configuration
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cuFuncSetCacheConfig,
; * ::cudaDeviceSetCacheConfig
; */
;API
cuCtxSetCacheConfig PROTO config:CUfunc_cache 
IF  __CUDA_API_VERSION GE 4020
;/**
; * \brief Returns the current shared memory configuration for the current context.
; *
; * This function will return in \p pConfig the current size of shared memory banks
; * in the current context. On devices with configurable shared memory banks,
; * ::cuCtxSetSharedMemConfig can be used to change this setting, so that all
; * subsequent kernel launches will by default use the new bank size. When
; * ::cuCtxGetSharedMemConfig is called on devices without configurable shared
; * memory, it will return the fixed bank size of the hardware.
; *
; * The returned bank configurations can be either:
; * - ::CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE:  shared memory bank width is
; *   four bytes.
; * - ::CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE: shared memory bank width will
; *   eight bytes.
; *
; * \param pConfig - returned shared memory configuration
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cuCtxGetSharedMemConfig,
; * ::cuFuncSetCacheConfig,
; * ::cudaDeviceGetSharedMemConfig
; */
;API
cuCtxGetSharedMemConfig PROTO pConfig:XWORD 
;/**
; * \brief Sets the shared memory configuration for the current context.
; *
; * On devices with configurable shared memory banks, this function will set
; * the context's shared memory bank size which is used for subsequent kernel
; * launches.
; *
; * Changed the shared memory configuration between launches may insert a device
; * side synchronization point between those launches.
; *
; * Changing the shared memory bank size will not increase shared memory usage
; * or affect occupancy of kernels, but may have major effects on performance.
; * Larger bank sizes will allow for greater potential bandwidth to shared memory,
; * but will change what kinds of accesses to shared memory will result in bank
; * conflicts.
; *
; * This function will do nothing on devices with fixed shared memory bank size.
; *
; * The supported bank configurations are:
; * - ::CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE: set bank width to the default initial
; *   setting (currently, four bytes).
; * - ::CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE: set shared memory bank width to
; *   be natively four bytes.
; * - ::CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE: set shared memory bank width to
; *   be natively eight bytes.
; *
; * \param config - requested shared memory configuration
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cuCtxGetSharedMemConfig,
; * ::cuFuncSetCacheConfig,
; * ::cudaDeviceSetSharedMemConfig
; */
;API
cuCtxSetSharedMemConfig PROTO config:CUsharedconfig 
ENDIF 
;/**
; * \brief Gets the context's API version.
; *
; * Returns a version number in \p version corresponding to the capabilities of
; * the context (e.g. 3010 or 3020), which library developers can use to direct
; * callers to a specific API version. If \p ctx is NULL, returns the API version
; * used to create the currently bound context.
; *
; * Note that new API versions are only introduced when context capabilities are
; * changed that break binary compatibility, so the API version and driver version
; * may be different. For example, it is valid for the API version to be 3020 while
; * the driver version is 4020.
; *
; * \param ctx     - Context to check
; * \param version - Pointer to version
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxGetApiVersion PROTO ctx:XWORD ,version:XWORD 
;/**
; * \brief Returns numerical values that correspond to the least and
; * greatest stream priorities.
; *
; * Returns in \p *leastPriority and \p *greatestPriority the numerical values that correspond
; * to the least and greatest stream priorities respectively. Stream priorities
; * follow a convention where lower numbers imply greater priorities. The range of
; * meaningful stream priorities is given by [\p *greatestPriority, \p *leastPriority].
; * If the user attempts to create a stream with a priority value that is
; * outside the meaningful range as specified by this API, the priority is
; * automatically clamped down or up to either \p *leastPriority or \p *greatestPriority
; * respectively. See ::cuStreamCreateWithPriority for details on creating a
; * priority stream.
; * A NULL may be passed in for \p *leastPriority or \p *greatestPriority if the value
; * is not desired.
; *
; * This function will return '0' in both \p *leastPriority and \p *greatestPriority if
; * the current context's device does not support stream priorities
; * (see ::cuDeviceGetAttribute).
; *
; * \param leastPriority    - Pointer to an int in which the numerical value for least
; *                           stream priority is returned
; * \param greatestPriority - Pointer to an int in which the numerical value for greatest
; *                           stream priority is returned
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \notefnerr
; *
; * \sa ::cuStreamCreateWithPriority,
; * ::cuStreamGetPriority,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize,
; * ::cudaDeviceGetStreamPriorityRange
; */
;API
cuCtxGetStreamPriorityRange PROTO leastPriority:XWORD ,greatestPriority:XWORD 
;/**
; * \defgroup CUDA_CTX_DEPRECATED Context Management [DEPRECATED]
; *
; * ___MANBRIEF___ deprecated context management functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the deprecated context management functions of the low-level
; * CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Increment a context's usage-count
; *
; * \deprecated
; *
; * Note that this function is deprecated and should not be used.
; *
; * Increments the usage count of the context and passes back a context handle
; * in \p *pctx that must be passed to ::cuCtxDetach() when the application is
; * done with the context. ::cuCtxAttach() fails if there is no context current
; * to the thread.
; *
; * Currently, the \p flags parameter must be 0.
; *
; * \param pctx  - Returned context handle of the current context
; * \param flags - Context attach flags (must be 0)
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxDetach,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxAttach PROTO pctx:XWORD ,flags:DWORD 
;/**
; * \brief Decrement a context's usage-count
; *
; * \deprecated
; *
; * Note that this function is deprecated and should not be used.
; *
; * Decrements the usage count of the context \p ctx, and destroys the context
; * if the usage count goes to 0. The context must be a handle that was passed
; * back by ::cuCtxCreate() or ::cuCtxAttach(), and must be current to the
; * calling thread.
; *
; * \param ctx - Context to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa ::cuCtxCreate,
; * ::cuCtxDestroy,
; * ::cuCtxGetApiVersion,
; * ::cuCtxGetCacheConfig,
; * ::cuCtxGetDevice,
; * ::cuCtxGetFlags,
; * ::cuCtxGetLimit,
; * ::cuCtxPopCurrent,
; * ::cuCtxPushCurrent,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxSetLimit,
; * ::cuCtxSynchronize
; */
;API
cuCtxDetach PROTO ctx:XWORD 
;/**
; * \defgroup CUDA_MODULE Module Management
; *
; * ___MANBRIEF___ module management functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the module management functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Loads a compute module
; *
; * Takes a filename \p fname and loads the corresponding module \p module into
; * the current context. The CUDA driver API does not attempt to lazily
; * allocate the resources needed by a module; if the memory for functions and
; * data (constant and global) needed by the module cannot be allocated,
; * ::cuModuleLoad() fails. The file should be a \e cubin file as output by
; * \b nvcc, or a \e PTX file either as output by \b nvcc or handwritten, or
; * a \e fatbin file as output by \b nvcc from toolchain 4.0 or later.
; *
; * \param module - Returned module
; * \param fname  - Filename of module to load
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_PTX,
; * ::CUDA_ERROR_NOT_FOUND,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_FILE_NOT_FOUND,
; * ::CUDA_ERROR_NO_BINARY_FOR_GPU,
; * ::CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
; * ::CUDA_ERROR_JIT_COMPILER_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload
; */
;API
cuModuleLoad PROTO module:XWORD ,fname:XWORD 
;/**
; * \brief Load a module's data
; *
; * Takes a pointer \p image and loads the corresponding module \p module into
; * the current context. The pointer may be obtained by mapping a \e cubin or
; * \e PTX or \e fatbin file, passing a \e cubin or \e PTX or \e fatbin file
; * as a NULL-terminated text string, or incorporating a \e cubin or \e fatbin
; * object into the executable resources and using operating system calls such
; * as Windows \c FindResource() to obtain the pointer.
; *
; * \param module - Returned module
; * \param image  - Module data to load
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_PTX,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_NO_BINARY_FOR_GPU,
; * ::CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
; * ::CUDA_ERROR_JIT_COMPILER_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload
; */
;API
cuModuleLoadData PROTO module:XWORD ,image:XWORD 
;/**
; * \brief Load a module's data with options
; *
; * Takes a pointer \p image and loads the corresponding module \p module into
; * the current context. The pointer may be obtained by mapping a \e cubin or
; * \e PTX or \e fatbin file, passing a \e cubin or \e PTX or \e fatbin file
; * as a NULL-terminated text string, or incorporating a \e cubin or \e fatbin
; * object into the executable resources and using operating system calls such
; * as Windows \c FindResource() to obtain the pointer. Options are passed as
; * an array via \p options and any corresponding parameters are passed in
; * \p optionValues. The number of total options is supplied via \p numOptions.
; * Any outputs will be returned via \p optionValues.
; *
; * \param module       - Returned module
; * \param image        - Module data to load
; * \param numOptions   - Number of options
; * \param options      - Options for JIT
; * \param optionValues - Option values for JIT
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_PTX,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_NO_BINARY_FOR_GPU,
; * ::CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
; * ::CUDA_ERROR_JIT_COMPILER_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload
; */
;API
cuModuleLoadDataEx PROTO module:XWORD ,image:XWORD ,numOptions:DWORD ,options:XWORD ,optionValues:XWORD 
;/**
; * \brief Load a module's data
; *
; * Takes a pointer \p fatCubin and loads the corresponding module \p module
; * into the current context. The pointer represents a <i>fat binary</i> object,
; * which is a collection of different \e cubin and/or \e PTX files, all
; * representing the same device code, but compiled and optimized for different
; * architectures.
; *
; * Prior to CUDA 4.0, there was no documented API for constructing and using
; * fat binary objects by programmers.  Starting with CUDA 4.0, fat binary
; * objects can be constructed by providing the <i>-fatbin option</i> to \b nvcc.
; * More information can be found in the \b nvcc document.
; *
; * \param module   - Returned module
; * \param fatCubin - Fat binary to load
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_PTX,
; * ::CUDA_ERROR_NOT_FOUND,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_NO_BINARY_FOR_GPU,
; * ::CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
; * ::CUDA_ERROR_JIT_COMPILER_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleUnload
; */
;API
cuModuleLoadFatBinary PROTO module:XWORD ,fatCubin:XWORD 
;/**
; * \brief Unloads a module
; *
; * Unloads a module \p hmod from the current context.
; *
; * \param hmod - Module to unload
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary
; */
;API
cuModuleUnload PROTO hmod:XWORD 
;/**
; * \brief Returns a function handle
; *
; * Returns in \p *hfunc the handle of the function of name \p name located in
; * module \p hmod. If no function of that name exists, ::cuModuleGetFunction()
; * returns ::CUDA_ERROR_NOT_FOUND.
; *
; * \param hfunc - Returned function handle
; * \param hmod  - Module to retrieve function from
; * \param name  - Name of function to retrieve
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload
; */
;API
cuModuleGetFunction PROTO hfunc:XWORD ,hmod:XWORD ,aname:XWORD 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Returns a global pointer from a module
; *
; * Returns in \p *dptr and \p *bytes the base pointer and size of the
; * global of name \p name located in module \p hmod. If no variable of that name
; * exists, ::cuModuleGetGlobal() returns ::CUDA_ERROR_NOT_FOUND. Both
; * parameters \p dptr and \p bytes are optional. If one of them is
; * NULL, it is ignored.
; *
; * \param dptr  - Returned global device pointer
; * \param bytes - Returned global size in bytes
; * \param hmod  - Module to retrieve global from
; * \param name  - Name of global to retrieve
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload,
; * ::cudaGetSymbolAddress,
; * ::cudaGetSymbolSize
; */
;API
cuModuleGetGlobal PROTO dptr:XWORD ,bytes:XWORD ,hmod:XWORD ,aname:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Returns a handle to a texture reference
; *
; * Returns in \p *pTexRef the handle of the texture reference of name \p name
; * in the module \p hmod. If no texture reference of that name exists,
; * ::cuModuleGetTexRef() returns ::CUDA_ERROR_NOT_FOUND. This texture reference
; * handle should not be destroyed, since it will be destroyed when the module
; * is unloaded.
; *
; * \param pTexRef  - Returned texture reference
; * \param hmod     - Module to retrieve texture reference from
; * \param name     - Name of texture reference to retrieve
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetSurfRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload,
; * ::cudaGetTextureReference
; */
;API
cuModuleGetTexRef PROTO pTexRef:XWORD ,hmod:XWORD ,aname:XWORD 
;/**
; * \brief Returns a handle to a surface reference
; *
; * Returns in \p *pSurfRef the handle of the surface reference of name \p name
; * in the module \p hmod. If no surface reference of that name exists,
; * ::cuModuleGetSurfRef() returns ::CUDA_ERROR_NOT_FOUND.
; *
; * \param pSurfRef  - Returned surface reference
; * \param hmod     - Module to retrieve surface reference from
; * \param name     - Name of surface reference to retrieve
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuModuleGetFunction,
; * ::cuModuleGetGlobal,
; * ::cuModuleGetTexRef,
; * ::cuModuleLoad,
; * ::cuModuleLoadData,
; * ::cuModuleLoadDataEx,
; * ::cuModuleLoadFatBinary,
; * ::cuModuleUnload,
; * ::cudaGetSurfaceReference
; */
;API
cuModuleGetSurfRef PROTO pSurfRef:XWORD ,hmod:XWORD ,aname:XWORD 
IF  __CUDA_API_VERSION GE 5050
;/**
; * \brief Creates a pending JIT linker invocation.
; *
; * If the call is successful, the caller owns the returned CUlinkState, which
; * should eventually be destroyed with ::cuLinkDestroy.  The
; * device code machine size (32 or 64 bit) will match the calling application.
; *
; * Both linker and compiler options may be specified.  Compiler options will
; * be applied to inputs to this linker action which must be compiled from PTX.
; * The options ::CU_JIT_WALL_TIME,
; * ::CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES, and ::CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES
; * will accumulate data until the CUlinkState is destroyed.
; *
; * \p optionValues must remain valid for the life of the CUlinkState if output
; * options are used.  No other references to inputs are maintained after this
; * call returns.
; *
; * \param numOptions   Size of options arrays
; * \param options      Array of linker and compiler options
; * \param optionValues Array of option values, each cast to void *
; * \param stateOut     On success, this will contain a CUlinkState to specify
; *                     and complete this action
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_JIT_COMPILER_NOT_FOUND
; * \notefnerr
; *
; * \sa ::cuLinkAddData,
; * ::cuLinkAddFile,
; * ::cuLinkComplete,
; * ::cuLinkDestroy
; */
;API
cuLinkCreate PROTO numOptions:DWORD ,options:XWORD ,optionValues:XWORD ,stateOut:XWORD 
;/**
; * \brief Add an input to a pending linker invocation
; *
; * Ownership of \p data is retained by the caller.  No reference is retained to any
; * inputs after this call returns.
; *
; * This method accepts only compiler options, which are used if the data must
; * be compiled from PTX, and does not accept any of
; * ::CU_JIT_WALL_TIME, ::CU_JIT_INFO_LOG_BUFFER, ::CU_JIT_ERROR_LOG_BUFFER,
; * ::CU_JIT_TARGET_FROM_CUCONTEXT, or ::CU_JIT_TARGET.
; *
; * \param state        A pending linker action.
; * \param type         The type of the input data.
; * \param data         The input data.  PTX must be NULL-terminated.
; * \param size         The length of the input data.
; * \param name         An optional name for this input in log messages.
; * \param numOptions   Size of options.
; * \param options      Options to be applied only for this input (overrides options from ::cuLinkCreate).
; * \param optionValues Array of option values, each cast to void *.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_IMAGE,
; * ::CUDA_ERROR_INVALID_PTX,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_NO_BINARY_FOR_GPU
; *
; * \sa ::cuLinkCreate,
; * ::cuLinkAddFile,
; * ::cuLinkComplete,
; * ::cuLinkDestroy
; */
;API
cuLinkAddData PROTO state:XWORD ,atype:CUjitInputType ,data:XWORD ,asize:DWORD ,aname:XWORD ,numOptions:DWORD ,options:XWORD ,optionValues:XWORD 
;/**
; * \brief Add a file input to a pending linker invocation
; *
; * No reference is retained to any inputs after this call returns.
; *
; * This method accepts only compiler options, which are used if the input
; * must be compiled from PTX, and does not accept any of
; * ::CU_JIT_WALL_TIME, ::CU_JIT_INFO_LOG_BUFFER, ::CU_JIT_ERROR_LOG_BUFFER,
; * ::CU_JIT_TARGET_FROM_CUCONTEXT, or ::CU_JIT_TARGET.
; *
; * This method is equivalent to invoking ::cuLinkAddData on the contents
; * of the file.
; *
; * \param state        A pending linker action
; * \param type         The type of the input data
; * \param path         Path to the input file
; * \param numOptions   Size of options
; * \param options      Options to be applied only for this input (overrides options from ::cuLinkCreate)
; * \param optionValues Array of option values, each cast to void *
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_FILE_NOT_FOUND
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_IMAGE,
; * ::CUDA_ERROR_INVALID_PTX,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_NO_BINARY_FOR_GPU
; *
; * \sa ::cuLinkCreate,
; * ::cuLinkAddData,
; * ::cuLinkComplete,
; * ::cuLinkDestroy
; */
;API
cuLinkAddFile PROTO state:XWORD ,atype:CUjitInputType ,path:XWORD ,numOptions:DWORD ,options:XWORD ,optionValues:XWORD 
;/**
; * \brief Complete a pending linker invocation
; *
; * Completes the pending linker action and returns the cubin image for the linked
; * device code, which can be used with ::cuModuleLoadData.  The cubin is owned by
; * \p state, so it should be loaded before \p state is destroyed via ::cuLinkDestroy.
; * This call does not destroy \p state.
; *
; * \param state    A pending linker invocation
; * \param cubinOut On success, this will point to the output image
; * \param sizeOut  Optional parameter to receive the size of the generated image
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; *
; * \sa ::cuLinkCreate,
; * ::cuLinkAddData,
; * ::cuLinkAddFile,
; * ::cuLinkDestroy,
; * ::cuModuleLoadData
; */
;API
cuLinkComplete PROTO state:XWORD ,cubinOut:XWORD ,sizeOut:XWORD 
;/**
; * \brief Destroys state for a JIT linker invocation.
; *
; * \param state State object for the linker invocation
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_HANDLE
; *
; * \sa ::cuLinkCreate
; */
;API
cuLinkDestroy PROTO state:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 5050 */ 
;/**
; * \defgroup CUDA_MEM Memory Management
; *
; * ___MANBRIEF___ memory management functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the memory management functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Gets free and total memory
; *
; * Returns in \p *free and \p *total respectively, the free and total amount of
; * memory available for allocation by the CUDA context, in bytes.
; *
; * \param free  - Returned free memory in bytes
; * \param total - Returned total memory in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemGetInfo
; */
;API
cuMemGetInfo PROTO free:XWORD ,total:XWORD 
;/**
; * \brief Allocates device memory
; *
; * Allocates \p bytesize bytes of linear memory on the device and returns in
; * \p *dptr a pointer to the allocated memory. The allocated memory is suitably
; * aligned for any kind of variable. The memory is not cleared. If \p bytesize
; * is 0, ::cuMemAlloc() returns ::CUDA_ERROR_INVALID_VALUE.
; *
; * \param dptr     - Returned device pointer
; * \param bytesize - Requested allocation size in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMalloc
; */
;API
cuMemAlloc PROTO dptr:XWORD ,bytesize:DWORD 
;/**
; * \brief Allocates pitched device memory
; *
; * Allocates at least \p WidthInBytes * \p Height bytes of linear memory on
; * the device and returns in \p *dptr a pointer to the allocated memory. The
; * function may pad the allocation to ensure that corresponding pointers in
; * any given row will continue to meet the alignment requirements for
; * coalescing as the address is updated from row to row. \p ElementSizeBytes
; * specifies the size of the largest reads and writes that will be performed
; * on the memory range. \p ElementSizeBytes may be 4, 8 or 16 (since coalesced
; * memory transactions are not possible on other data sizes). If
; * \p ElementSizeBytes is smaller than the actual read/write size of a kernel,
; * the kernel will run correctly, but possibly at reduced speed. The pitch
; * returned in \p *pPitch by ::cuMemAllocPitch() is the width in bytes of the
; * allocation. The intended usage of pitch is as a separate parameter of the
; * allocation, used to compute addresses within the 2D array. Given the row
; * and column of an array element of type \b T, the address is computed as:
; * \code
;   T* pElement = (T*)((char*)BaseAddress + Row * Pitch) + Column;
; * \endcode
; *
; * The pitch returned by ::cuMemAllocPitch() is guaranteed to work with
; * ::cuMemcpy2D() under all circumstances. For allocations of 2D arrays, it is
; * recommended that programmers consider performing pitch allocations using
; * ::cuMemAllocPitch(). Due to alignment restrictions in the hardware, this is
; * especially true if the application will be performing 2D memory copies
; * between different regions of device memory (whether linear memory or CUDA
; * arrays).
; *
; * The byte alignment of the pitch returned by ::cuMemAllocPitch() is guaranteed
; * to match or exceed the alignment requirement for texture binding with
; * ::cuTexRefSetAddress2D().
; *
; * \param dptr             - Returned device pointer
; * \param pPitch           - Returned pitch of allocation in bytes
; * \param WidthInBytes     - Requested allocation width in bytes
; * \param Height           - Requested allocation height in rows
; * \param ElementSizeBytes - Size of largest reads/writes for range
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMallocPitch
; */
;API
cuMemAllocPitch PROTO dptr:XWORD ,pPitch:XWORD ,WidthInBytes:DWORD ,Height:DWORD ,ElementSizeBytes:DWORD 
;/**
; * \brief Frees device memory
; *
; * Frees the memory space pointed to by \p dptr, which must have been returned
; * by a previous call to ::cuMemAlloc() or ::cuMemAllocPitch().
; *
; * \param dptr - Pointer to memory to free
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaFree
; */
;API
cuMemFree PROTO dptr:CUdeviceptr 
;/**
; * \brief Get information on memory allocations
; *
; * Returns the base address in \p *pbase and size in \p *psize of the
; * allocation by ::cuMemAlloc() or ::cuMemAllocPitch() that contains the input
; * pointer \p dptr. Both parameters \p pbase and \p psize are optional. If one
; * of them is NULL, it is ignored.
; *
; * \param pbase - Returned base address
; * \param psize - Returned size of device memory allocation
; * \param dptr  - Device pointer to query
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_NOT_FOUND,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32
; */
;API
cuMemGetAddressRange PROTO pbase:XWORD ,psize:XWORD ,dptr:CUdeviceptr 
;/**
; * \brief Allocates page-locked host memory
; *
; * Allocates \p bytesize bytes of host memory that is page-locked and
; * accessible to the device. The driver tracks the virtual memory ranges
; * allocated with this function and automatically accelerates calls to
; * functions such as ::cuMemcpy(). Since the memory can be accessed directly by
; * the device, it can be read or written with much higher bandwidth than
; * pageable memory obtained with functions such as ::malloc(). Allocating
; * excessive amounts of memory with ::cuMemAllocHost() may degrade system
; * performance, since it reduces the amount of memory available to the system
; * for paging. As a result, this function is best used sparingly to allocate
; * staging areas for data exchange between host and device.
; *
; * Note all host memory allocated using ::cuMemHostAlloc() will automatically
; * be immediately accessible to all contexts on all devices which support unified
; * addressing (as may be queried using ::CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING).
; * The device pointer that may be used to access this host memory from those
; * contexts is always equal to the returned host pointer \p *pp.
; * See \ref CUDA_UNIFIED for additional details.
; *
; * \param pp       - Returned host pointer to page-locked memory
; * \param bytesize - Requested allocation size in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMallocHost
; */
;API
cuMemAllocHost PROTO pp:XWORD ,bytesize:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Frees page-locked host memory
; *
; * Frees the memory space pointed to by \p p, which must have been returned by
; * a previous call to ::cuMemAllocHost().
; *
; * \param p - Pointer to memory to free
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaFreeHost
; */
;API
cuMemFreeHost PROTO p:XWORD 
;/**
; * \brief Allocates page-locked host memory
; *
; * Allocates \p bytesize bytes of host memory that is page-locked and accessible
; * to the device. The driver tracks the virtual memory ranges allocated with
; * this function and automatically accelerates calls to functions such as
; * ::cuMemcpyHtoD(). Since the memory can be accessed directly by the device,
; * it can be read or written with much higher bandwidth than pageable memory
; * obtained with functions such as ::malloc(). Allocating excessive amounts of
; * pinned memory may degrade system performance, since it reduces the amount
; * of memory available to the system for paging. As a result, this function is
; * best used sparingly to allocate staging areas for data exchange between
; * host and device.
; *
; * The \p Flags parameter enables different options to be specified that
; * affect the allocation, as follows.
; *
; * - ::CU_MEMHOSTALLOC_PORTABLE: The memory returned by this call will be
; *   considered as pinned memory by all CUDA contexts, not just the one that
; *   performed the allocation.
; *
; * - ::CU_MEMHOSTALLOC_DEVICEMAP: Maps the allocation into the CUDA address
; *   space. The device pointer to the memory may be obtained by calling
; *   ::cuMemHostGetDevicePointer().
; *
; * - ::CU_MEMHOSTALLOC_WRITECOMBINED: Allocates the memory as write-combined
; *   (WC). WC memory can be transferred across the PCI Express bus more
; *   quickly on some system configurations, but cannot be read efficiently by
; *   most CPUs. WC memory is a good option for buffers that will be written by
; *   the CPU and read by the GPU via mapped pinned memory or host->device
; *   transfers.
; *
; * All of these flags are orthogonal to one another: a developer may allocate
; * memory that is portable, mapped and/or write-combined with no restrictions.
; *
; * The CUDA context must have been created with the ::CU_CTX_MAP_HOST flag in
; * order for the ::CU_MEMHOSTALLOC_DEVICEMAP flag to have any effect.
; *
; * The ::CU_MEMHOSTALLOC_DEVICEMAP flag may be specified on CUDA contexts for
; * devices that do not support mapped pinned memory. The failure is deferred
; * to ::cuMemHostGetDevicePointer() because the memory may be mapped into
; * other CUDA contexts via the ::CU_MEMHOSTALLOC_PORTABLE flag.
; *
; * The memory allocated by this function must be freed with ::cuMemFreeHost().
; *
; * Note all host memory allocated using ::cuMemHostAlloc() will automatically
; * be immediately accessible to all contexts on all devices which support unified
; * addressing (as may be queried using ::CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING).
; * Unless the flag ::CU_MEMHOSTALLOC_WRITECOMBINED is specified, the device pointer
; * that may be used to access this host memory from those contexts is always equal
; * to the returned host pointer \p *pp.  If the flag ::CU_MEMHOSTALLOC_WRITECOMBINED
; * is specified, then the function ::cuMemHostGetDevicePointer() must be used
; * to query the device pointer, even if the context supports unified addressing.
; * See \ref CUDA_UNIFIED for additional details.
; *
; * \param pp       - Returned host pointer to page-locked memory
; * \param bytesize - Requested allocation size in bytes
; * \param Flags    - Flags for allocation request
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaHostAlloc
; */
;API
cuMemHostAlloc PROTO pp:XWORD ,bytesize:DWORD ,Flags:DWORD 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Passes back device pointer of mapped pinned memory
; *
; * Passes back the device pointer \p pdptr corresponding to the mapped, pinned
; * host buffer \p p allocated by ::cuMemHostAlloc.
; *
; * ::cuMemHostGetDevicePointer() will fail if the ::CU_MEMHOSTALLOC_DEVICEMAP
; * flag was not specified at the time the memory was allocated, or if the
; * function is called on a GPU that does not support mapped pinned memory.
; *
; * For devices that have a non-zero value for the device attribute
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM, the memory
; * can also be accessed from the device using the host pointer \p p.
; * The device pointer returned by ::cuMemHostGetDevicePointer() may or may not
; * match the original host pointer \p p and depends on the devices visible to the
; * application. If all devices visible to the application have a non-zero value for the
; * device attribute, the device pointer returned by ::cuMemHostGetDevicePointer()
; * will match the original pointer \p p. If any device visible to the application
; * has a zero value for the device attribute, the device pointer returned by
; * ::cuMemHostGetDevicePointer() will not match the original host pointer \p p,
; * but it will be suitable for use on all devices provided Unified Virtual Addressing
; * is enabled. In such systems, it is valid to access the memory using either pointer
; * on devices that have a non-zero value for the device attribute. Note however that
; * such devices should access the memory using only of the two pointers and not both.
; *
; * \p Flags provides for future releases. For now, it must be set to 0.
; *
; * \param pdptr - Returned device pointer
; * \param p     - Host pointer
; * \param Flags - Options (must be 0)
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaHostGetDevicePointer
; */
;API
cuMemHostGetDevicePointer PROTO pdptr:XWORD ,p:XWORD ,Flags:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Passes back flags that were used for a pinned allocation
; *
; * Passes back the flags \p pFlags that were specified when allocating
; * the pinned host buffer \p p allocated by ::cuMemHostAlloc.
; *
; * ::cuMemHostGetFlags() will fail if the pointer does not reside in
; * an allocation performed by ::cuMemAllocHost() or ::cuMemHostAlloc().
; *
; * \param pFlags - Returned flags word
; * \param p     - Host pointer
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cuMemAllocHost,
; * ::cuMemHostAlloc,
; * ::cudaHostGetFlags
; */
;API
cuMemHostGetFlags PROTO pFlags:XWORD ,p:XWORD 
IF  __CUDA_API_VERSION GE 6000
;/**
; * \brief Allocates memory that will be automatically managed by the Unified Memory system
; *
; * Allocates \p bytesize bytes of managed memory on the device and returns in
; * \p *dptr a pointer to the allocated memory. If the device doesn't support
; * allocating managed memory, ::CUDA_ERROR_NOT_SUPPORTED is returned. Support
; * for managed memory can be queried using the device attribute
; * ::CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY. The allocated memory is suitably
; * aligned for any kind of variable. The memory is not cleared. If \p bytesize
; * is 0, ::cuMemAllocManaged returns ::CUDA_ERROR_INVALID_VALUE. The pointer
; * is valid on the CPU and on all GPUs in the system that support managed memory.
; * All accesses to this pointer must obey the Unified Memory programming model.
; *
; * \p flags specifies the default stream association for this allocation.
; * \p flags must be one of ::CU_MEM_ATTACH_GLOBAL or ::CU_MEM_ATTACH_HOST. If
; * ::CU_MEM_ATTACH_GLOBAL is specified, then this memory is accessible from
; * any stream on any device. If ::CU_MEM_ATTACH_HOST is specified, then the
; * allocation should not be accessed from devices that have a zero value for the
; * device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS; an explicit call to
; * ::cuStreamAttachMemAsync will be required to enable access on such devices.
; *
; * If the association is later changed via ::cuStreamAttachMemAsync to
; * a single stream, the default association as specifed during ::cuMemAllocManaged
; * is restored when that stream is destroyed. For __managed__ variables, the
; * default association is always ::CU_MEM_ATTACH_GLOBAL. Note that destroying a
; * stream is an asynchronous operation, and as a result, the change to default
; * association won't happen until all work in the stream has completed.
; *
; * Memory allocated with ::cuMemAllocManaged should be released with ::cuMemFree.
; *
; * Device memory oversubscription is possible for GPUs that have a non-zero value for the
; * device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS. Managed memory on
; * such GPUs may be evicted from device memory to host memory at any time by the Unified
; * Memory driver in order to make room for other allocations.
; *
; * In a multi-GPU system where all GPUs have a non-zero value for the device attribute
; * ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS, managed memory may not be populated when this
; * API returns and instead may be populated on access. In such systems, managed memory can
; * migrate to any processor's memory at any time. The Unified Memory driver will employ heuristics to
; * maintain data locality and prevent excessive page faults to the extent possible. The application
; * can also guide the driver about memory usage patterns via ::cuMemAdvise. The application
; * can also explicitly migrate memory to a desired processor's memory via
; * ::cuMemPrefetchAsync.
; *
; * In a multi-GPU system where all of the GPUs have a zero value for the device attribute
; * ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS and all the GPUs have peer-to-peer support
; * with each other, the physical storage for managed memory is created on the GPU which is active
; * at the time ::cuMemAllocManaged is called. All other GPUs will reference the data at reduced
; * bandwidth via peer mappings over the PCIe bus. The Unified Memory driver does not migrate
; * memory among such GPUs.
; *
; * In a multi-GPU system where not all GPUs have peer-to-peer support with each other and
; * where the value of the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS
; * is zero for at least one of those GPUs, the location chosen for physical storage of managed
; * memory is system-dependent.
; * - On Linux, the location chosen will be device memory as long as the current set of active
; * contexts are on devices that either have peer-to-peer support with each other or have a
; * non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS.
; * If there is an active context on a GPU that does not have a non-zero value for that device
; * attribute and it does not have peer-to-peer support with the other devices that have active
; * contexts on them, then the location for physical storage will be 'zero-copy' or host memory.
; * Note that this means that managed memory that is located in device memory is migrated to
; * host memory if a new context is created on a GPU that doesn't have a non-zero value for
; * the device attribute and does not support peer-to-peer with at least one of the other devices
; * that has an active context. This in turn implies that context creation may fail if there is
; * insufficient host memory to migrate all managed allocations.
; * - On Windows, the physical storage is always created in 'zero-copy' or host memory.
; * All GPUs will reference the data at reduced bandwidth over the PCIe bus. In these
; * circumstances, use of the environment variable CUDA_VISIBLE_DEVICES is recommended to
; * restrict CUDA to only use those GPUs that have peer-to-peer support.
; * Alternatively, users can also set CUDA_MANAGED_FORCE_DEVICE_ALLOC to a
; * non-zero value to force the driver to always use device memory for physical storage.
; * When this environment variable is set to a non-zero value, all contexts created in
; * that process on devices that support managed memory have to be peer-to-peer compatible
; * with each other. Context creation will fail if a context is created on a device that
; * supports managed memory and is not peer-to-peer compatible with any of the other
; * managed memory supporting devices on which contexts were previously created, even if
; * those contexts have been destroyed. These environment variables are described
; * in the CUDA programming guide under the "CUDA environment variables" section.
; * - On ARM, managed memory is not available on discrete gpu with Drive PX-2.
; *
; * \param dptr     - Returned device pointer
; * \param bytesize - Requested allocation size in bytes
; * \param flags    - Must be one of ::CU_MEM_ATTACH_GLOBAL or ::CU_MEM_ATTACH_HOST
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_NOT_SUPPORTED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cuDeviceGetAttribute, ::cuStreamAttachMemAsync,
; * ::cudaMallocManaged
; */
;API
cuMemAllocManaged PROTO dptr:XWORD ,bytesize:DWORD ,flags:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 6000 */ 
IF  __CUDA_API_VERSION GE 4010
;/**
; * \brief Returns a handle to a compute device
; *
; * Returns in \p *device a device handle given a PCI bus ID string.
; *
; * \param dev      - Returned device handle
; *
; * \param pciBusId - String in one of the following forms:
; * [domain]:[bus]:[device].[function]
; * [domain]:[bus]:[device]
; * [bus]:[device].[function]
; * where \p domain, \p bus, \p device, and \p function are all hexadecimal values
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGet,
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetPCIBusId,
; * ::cudaDeviceGetByPCIBusId
; */
;API
cuDeviceGetByPCIBusId PROTO dev:XWORD ,pciBusId:XWORD 
;/**
; * \brief Returns a PCI Bus Id string for the device
; *
; * Returns an ASCII string identifying the device \p dev in the NULL-terminated
; * string pointed to by \p pciBusId. \p len specifies the maximum length of the
; * string that may be returned.
; *
; * \param pciBusId - Returned identifier string for the device in the following format
; * [domain]:[bus]:[device].[function]
; * where \p domain, \p bus, \p device, and \p function are all hexadecimal values.
; * pciBusId should be large enough to store 13 characters including the NULL-terminator.
; *
; * \param len      - Maximum length of string to store in \p name
; *
; * \param dev      - Device to get identifier string for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceGet,
; * ::cuDeviceGetAttribute,
; * ::cuDeviceGetByPCIBusId,
; * ::cudaDeviceGetPCIBusId
; */
;API
cuDeviceGetPCIBusId PROTO pciBusId:XWORD ,len:DWORD ,dev:DWORD 
;/**
; * \brief Gets an interprocess handle for a previously allocated event
; *
; * Takes as input a previously allocated event. This event must have been
; * created with the ::CU_EVENT_INTERPROCESS and ::CU_EVENT_DISABLE_TIMING
; * flags set. This opaque handle may be copied into other processes and
; * opened with ::cuIpcOpenEventHandle to allow efficient hardware
; * synchronization between GPU work in different processes.
; *
; * After the event has been opened in the importing process,
; * ::cuEventRecord, ::cuEventSynchronize, ::cuStreamWaitEvent and
; * ::cuEventQuery may be used in either process. Performing operations
; * on the imported event after the exported event has been freed
; * with ::cuEventDestroy will result in undefined behavior.
; *
; * IPC functionality is restricted to devices with support for unified
; * addressing on Linux and Windows operating systems.
; * IPC functionality on Windows is restricted to GPUs in TCC mode
; *
; * \param pHandle - Pointer to a user allocated CUipcEventHandle
; *                    in which to return the opaque event handle
; * \param event   - Event allocated with ::CU_EVENT_INTERPROCESS and
; *                    ::CU_EVENT_DISABLE_TIMING flags.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_MAP_FAILED,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuEventCreate,
; * ::cuEventDestroy,
; * ::cuEventSynchronize,
; * ::cuEventQuery,
; * ::cuStreamWaitEvent,
; * ::cuIpcOpenEventHandle,
; * ::cuIpcGetMemHandle,
; * ::cuIpcOpenMemHandle,
; * ::cuIpcCloseMemHandle,
; * ::cudaIpcGetEventHandle
; */
;API
cuIpcGetEventHandle PROTO pHandle:XWORD ,event:XWORD 
;/**
; * \brief Opens an interprocess event handle for use in the current process
; *
; * Opens an interprocess event handle exported from another process with
; * ::cuIpcGetEventHandle. This function returns a ::CUevent that behaves like
; * a locally created event with the ::CU_EVENT_DISABLE_TIMING flag specified.
; * This event must be freed with ::cuEventDestroy.
; *
; * Performing operations on the imported event after the exported event has
; * been freed with ::cuEventDestroy will result in undefined behavior.
; *
; * IPC functionality is restricted to devices with support for unified
; * addressing on Linux and Windows operating systems.
; * IPC functionality on Windows is restricted to GPUs in TCC mode
; *
; * \param phEvent - Returns the imported event
; * \param handle  - Interprocess handle to open
; *
; * \returns
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_MAP_FAILED,
; * ::CUDA_ERROR_PEER_ACCESS_UNSUPPORTED,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuEventCreate,
; * ::cuEventDestroy,
; * ::cuEventSynchronize,
; * ::cuEventQuery,
; * ::cuStreamWaitEvent,
; * ::cuIpcGetEventHandle,
; * ::cuIpcGetMemHandle,
; * ::cuIpcOpenMemHandle,
; * ::cuIpcCloseMemHandle,
; * ::cudaIpcOpenEventHandle
; */
;API
cuIpcOpenEventHandle PROTO phEvent:XWORD ,handle:CUipcEventHandle 
;/**
; * \brief Gets an interprocess memory handle for an existing device memory
; * allocation
; *
; * Takes a pointer to the base of an existing device memory allocation created
; * with ::cuMemAlloc and exports it for use in another process. This is a
; * lightweight operation and may be called multiple times on an allocation
; * without adverse effects.
; *
; * If a region of memory is freed with ::cuMemFree and a subsequent call
; * to ::cuMemAlloc returns memory with the same device address,
; * ::cuIpcGetMemHandle will return a unique handle for the
; * new memory.
; *
; * IPC functionality is restricted to devices with support for unified
; * addressing on Linux and Windows operating systems.
; * IPC functionality on Windows is restricted to GPUs in TCC mode
; *
; * \param pHandle - Pointer to user allocated ::CUipcMemHandle to return
; *                    the handle in.
; * \param dptr    - Base pointer to previously allocated device memory
; *
; * \returns
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_MAP_FAILED,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuMemAlloc,
; * ::cuMemFree,
; * ::cuIpcGetEventHandle,
; * ::cuIpcOpenEventHandle,
; * ::cuIpcOpenMemHandle,
; * ::cuIpcCloseMemHandle,
; * ::cudaIpcGetMemHandle
; */
;API
cuIpcGetMemHandle PROTO pHandle:XWORD ,dptr:CUdeviceptr 
;/**
; * \brief Opens an interprocess memory handle exported from another process
; * and returns a device pointer usable in the local process.
; *
; * Maps memory exported from another process with ::cuIpcGetMemHandle into
; * the current device address space. For contexts on different devices
; * ::cuIpcOpenMemHandle can attempt to enable peer access between the
; * devices as if the user called ::cuCtxEnablePeerAccess. This behavior is
; * controlled by the ::CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS flag.
; * ::cuDeviceCanAccessPeer can determine if a mapping is possible.
; *
; * ::cuIpcOpenMemHandle can open handles to devices that may not be visible
; * in the process calling the API.
; *
; * Contexts that may open ::CUipcMemHandles are restricted in the following way.
; * ::CUipcMemHandles from each ::CUdevice in a given process may only be opened
; * by one ::CUcontext per ::CUdevice per other process.
; *
; * Memory returned from ::cuIpcOpenMemHandle must be freed with
; * ::cuIpcCloseMemHandle.
; *
; * Calling ::cuMemFree on an exported memory region before calling
; * ::cuIpcCloseMemHandle in the importing context will result in undefined
; * behavior.
; *
; * IPC functionality is restricted to devices with support for unified
; * addressing on Linux and Windows operating systems.
; * IPC functionality on Windows is restricted to GPUs in TCC mode
; *
; * \param pdptr  - Returned device pointer
; * \param handle - ::CUipcMemHandle to open
; * \param Flags  - Flags for this operation. Must be specified as ::CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS
; *
; * \returns
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_MAP_FAILED,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_TOO_MANY_PEERS,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \note No guarantees are made about the address returned in \p *pdptr.
; * In particular, multiple processes may not receive the same address for the same \p handle.
; *
; * \sa
; * ::cuMemAlloc,
; * ::cuMemFree,
; * ::cuIpcGetEventHandle,
; * ::cuIpcOpenEventHandle,
; * ::cuIpcGetMemHandle,
; * ::cuIpcCloseMemHandle,
; * ::cuCtxEnablePeerAccess,
; * ::cuDeviceCanAccessPeer,
; * ::cudaIpcOpenMemHandle
; */
;API
cuIpcOpenMemHandle PROTO pdptr:XWORD ,handle:CUipcMemHandle ,Flags:DWORD 
;/**
; * \brief Close memory mapped with ::cuIpcOpenMemHandle
; *
; * Unmaps memory returnd by ::cuIpcOpenMemHandle. The original allocation
; * in the exporting process as well as imported mappings in other processes
; * will be unaffected.
; *
; * Any resources used to enable peer access will be freed if this is the
; * last mapping using them.
; *
; * IPC functionality is restricted to devices with support for unified
; * addressing on Linux and Windows operating systems.
; * IPC functionality on Windows is restricted to GPUs in TCC mode
; *
; * \param dptr - Device pointer returned by ::cuIpcOpenMemHandle
; *
; * \returns
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_MAP_FAILED,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \sa
; * ::cuMemAlloc,
; * ::cuMemFree,
; * ::cuIpcGetEventHandle,
; * ::cuIpcOpenEventHandle,
; * ::cuIpcGetMemHandle,
; * ::cuIpcOpenMemHandle,
; * ::cudaIpcCloseMemHandle
; */
;API
cuIpcCloseMemHandle PROTO dptr:CUdeviceptr 
ENDIF ;/* __CUDA_API_VERSION >= 4010 */ 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Registers an existing host memory range for use by CUDA
; *
; * Page-locks the memory range specified by \p p and \p bytesize and maps it
; * for the device(s) as specified by \p Flags. This memory range also is added
; * to the same tracking mechanism as ::cuMemHostAlloc to automatically accelerate
; * calls to functions such as ::cuMemcpyHtoD(). Since the memory can be accessed
; * directly by the device, it can be read or written with much higher bandwidth
; * than pageable memory that has not been registered.  Page-locking excessive
; * amounts of memory may degrade system performance, since it reduces the amount
; * of memory available to the system for paging. As a result, this function is
; * best used sparingly to register staging areas for data exchange between
; * host and device.
; *
; * This function has limited support on Mac OS X. OS 10.7 or higher is required.
; *
; * The \p Flags parameter enables different options to be specified that
; * affect the allocation, as follows.
; *
; * - ::CU_MEMHOSTREGISTER_PORTABLE: The memory returned by this call will be
; *   considered as pinned memory by all CUDA contexts, not just the one that
; *   performed the allocation.
; *
; * - ::CU_MEMHOSTREGISTER_DEVICEMAP: Maps the allocation into the CUDA address
; *   space. The device pointer to the memory may be obtained by calling
; *   ::cuMemHostGetDevicePointer().
; *
; * - ::CU_MEMHOSTREGISTER_IOMEMORY: The pointer is treated as pointing to some
; *   I/O memory space, e.g. the PCI Express resource of a 3rd party device.
; *
; * All of these flags are orthogonal to one another: a developer may page-lock
; * memory that is portable or mapped with no restrictions.
; *
; * The CUDA context must have been created with the ::CU_CTX_MAP_HOST flag in
; * order for the ::CU_MEMHOSTREGISTER_DEVICEMAP flag to have any effect.
; *
; * The ::CU_MEMHOSTREGISTER_DEVICEMAP flag may be specified on CUDA contexts for
; * devices that do not support mapped pinned memory. The failure is deferred
; * to ::cuMemHostGetDevicePointer() because the memory may be mapped into
; * other CUDA contexts via the ::CU_MEMHOSTREGISTER_PORTABLE flag.
; *
; * For devices that have a non-zero value for the device attribute
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM, the memory
; * can also be accessed from the device using the host pointer \p p.
; * The device pointer returned by ::cuMemHostGetDevicePointer() may or may not
; * match the original host pointer \p ptr and depends on the devices visible to the
; * application. If all devices visible to the application have a non-zero value for the
; * device attribute, the device pointer returned by ::cuMemHostGetDevicePointer()
; * will match the original pointer \p ptr. If any device visible to the application
; * has a zero value for the device attribute, the device pointer returned by
; * ::cuMemHostGetDevicePointer() will not match the original host pointer \p ptr,
; * but it will be suitable for use on all devices provided Unified Virtual Addressing
; * is enabled. In such systems, it is valid to access the memory using either pointer
; * on devices that have a non-zero value for the device attribute. Note however that
; * such devices should access the memory using only of the two pointers and not both.
; *
; * The memory page-locked by this function must be unregistered with
; * ::cuMemHostUnregister().
; *
; * \param p        - Host pointer to memory to page-lock
; * \param bytesize - Size in bytes of the address range to page-lock
; * \param Flags    - Flags for allocation request
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED,
; * ::CUDA_ERROR_NOT_PERMITTED,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \notefnerr
; *
; * \sa
; * ::cuMemHostUnregister,
; * ::cuMemHostGetFlags,
; * ::cuMemHostGetDevicePointer,
; * ::cudaHostRegister
; */
;API
cuMemHostRegister PROTO p:XWORD ,bytesize:DWORD ,Flags:DWORD 
;/**
; * \brief Unregisters a memory range that was registered with cuMemHostRegister.
; *
; * Unmaps the memory range whose base address is specified by \p p, and makes
; * it pageable again.
; *
; * The base address must be the same one specified to ::cuMemHostRegister().
; *
; * \param p - Host pointer to memory to unregister
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED,
; * \notefnerr
; *
; * \sa
; * ::cuMemHostRegister,
; * ::cudaHostUnregister
; */
;API
cuMemHostUnregister PROTO p:XWORD 
;/**
; * \brief Copies memory
; *
; * Copies data between two pointers.
; * \p dst and \p src are base pointers of the destination and source, respectively.
; * \p ByteCount specifies the number of bytes to copy.
; * Note that this function infers the type of the transfer (host to host, host to
; *   device, device to device, or device to host) from the pointer values.  This
; *   function is only allowed in contexts which support unified addressing.
; *
; * \param dst - Destination unified virtual address space pointer
; * \param src - Source unified virtual address space pointer
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy,
; * ::cudaMemcpyToSymbol,
; * ::cudaMemcpyFromSymbol
; */
;API
cuMemcpy PROTO dst:CUdeviceptr ,src:CUdeviceptr ,ByteCount:DWORD 
;/**
; * \brief Copies device memory between two contexts
; *
; * Copies from device memory in one context to device memory in another
; * context. \p dstDevice is the base device pointer of the destination memory
; * and \p dstContext is the destination context.  \p srcDevice is the base
; * device pointer of the source memory and \p srcContext is the source pointer.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstDevice  - Destination device pointer
; * \param dstContext - Destination context
; * \param srcDevice  - Source device pointer
; * \param srcContext - Source context
; * \param ByteCount  - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuMemcpyDtoD, ::cuMemcpy3DPeer, ::cuMemcpyDtoDAsync, ::cuMemcpyPeerAsync,
; * ::cuMemcpy3DPeerAsync,
; * ::cudaMemcpyPeer
; */
;API
cuMemcpyPeer PROTO dstDevice:CUdeviceptr ,dstContext:XWORD ,srcDevice:CUdeviceptr ,srcContext:XWORD ,ByteCount:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Copies memory from Host to Device
; *
; * Copies from host memory to device memory. \p dstDevice and \p srcHost are
; * the base addresses of the destination and source, respectively. \p ByteCount
; * specifies the number of bytes to copy.
; *
; * \param dstDevice - Destination device pointer
; * \param srcHost   - Source host pointer
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy,
; * ::cudaMemcpyToSymbol
; */
;API
cuMemcpyHtoD PROTO dstDevice:CUdeviceptr ,srcHost:XWORD ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Device to Host
; *
; * Copies from device to host memory. \p dstHost and \p srcDevice specify the
; * base pointers of the destination and source, respectively. \p ByteCount
; * specifies the number of bytes to copy.
; *
; * \param dstHost   - Destination host pointer
; * \param srcDevice - Source device pointer
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy,
; * ::cudaMemcpyFromSymbol
; */
;API
cuMemcpyDtoH PROTO dstHost:XWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Device to Device
; *
; * Copies from device memory to device memory. \p dstDevice and \p srcDevice
; * are the base pointers of the destination and source, respectively.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstDevice - Destination device pointer
; * \param srcDevice - Source device pointer
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy,
; * ::cudaMemcpyToSymbol,
; * ::cudaMemcpyFromSymbol
; */
;API
cuMemcpyDtoD PROTO dstDevice:CUdeviceptr ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Device to Array
; *
; * Copies from device memory to a 1D CUDA array. \p dstArray and \p dstOffset
; * specify the CUDA array handle and starting index of the destination data.
; * \p srcDevice specifies the base pointer of the source. \p ByteCount
; * specifies the number of bytes to copy.
; *
; * \param dstArray  - Destination array
; * \param dstOffset - Offset in bytes of destination array
; * \param srcDevice - Source device pointer
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpyToArray
; */
;API
cuMemcpyDtoA PROTO dstArray:XWORD ,dstOffset:DWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Array to Device
; *
; * Copies from one 1D CUDA array to device memory. \p dstDevice specifies the
; * base pointer of the destination and must be naturally aligned with the CUDA
; * array elements. \p srcArray and \p srcOffset specify the CUDA array handle
; * and the offset in bytes into the array where the copy is to begin.
; * \p ByteCount specifies the number of bytes to copy and must be evenly
; * divisible by the array element size.
; *
; * \param dstDevice - Destination device pointer
; * \param srcArray  - Source array
; * \param srcOffset - Offset in bytes of source array
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpyFromArray
; */
;API
cuMemcpyAtoD PROTO dstDevice:CUdeviceptr ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Host to Array
; *
; * Copies from host memory to a 1D CUDA array. \p dstArray and \p dstOffset
; * specify the CUDA array handle and starting offset in bytes of the destination
; * data.  \p pSrc specifies the base address of the source. \p ByteCount specifies
; * the number of bytes to copy.
; *
; * \param dstArray  - Destination array
; * \param dstOffset - Offset in bytes of destination array
; * \param srcHost   - Source host pointer
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpyToArray
; */
;API
cuMemcpyHtoA PROTO dstArray:XWORD ,dstOffset:DWORD ,srcHost:XWORD ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Array to Host
; *
; * Copies from one 1D CUDA array to host memory. \p dstHost specifies the base
; * pointer of the destination. \p srcArray and \p srcOffset specify the CUDA
; * array handle and starting offset in bytes of the source data.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstHost   - Destination device pointer
; * \param srcArray  - Source array
; * \param srcOffset - Offset in bytes of source array
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpyFromArray
; */
;API
cuMemcpyAtoH PROTO dstHost:XWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;/**
; * \brief Copies memory from Array to Array
; *
; * Copies from one 1D CUDA array to another. \p dstArray and \p srcArray
; * specify the handles of the destination and source CUDA arrays for the copy,
; * respectively. \p dstOffset and \p srcOffset specify the destination and
; * source offsets in bytes into the CUDA arrays. \p ByteCount is the number of
; * bytes to be copied. The size of the elements in the CUDA arrays need not be
; * the same format, but the elements must be the same size; and count must be
; * evenly divisible by that size.
; *
; * \param dstArray  - Destination array
; * \param dstOffset - Offset in bytes of destination array
; * \param srcArray  - Source array
; * \param srcOffset - Offset in bytes of source array
; * \param ByteCount - Size of memory copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpyArrayToArray
; */
;API
cuMemcpyAtoA PROTO dstArray:XWORD ,dstOffset:DWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;/**
; * \brief Copies memory for 2D arrays
; *
; * Perform a 2D memory copy according to the parameters specified in \p pCopy.
; * The ::CUDA_MEMCPY2D structure is defined as:
; *
; * \code
;   typedef struct CUDA_MEMCPY2D_st {
;      unsigned int srcXInBytes, srcY;
;      CUmemorytype srcMemoryType;
;          const void *srcHost;
;          CUdeviceptr srcDevice;
;          CUarray srcArray;
;          unsigned int srcPitch;
;      unsigned int dstXInBytes, dstY;
;      CUmemorytype dstMemoryType;
;          void *dstHost;
;          CUdeviceptr dstDevice;
;          CUarray dstArray;
;          unsigned int dstPitch;
;      unsigned int WidthInBytes;
;      unsigned int Height;
;   } CUDA_MEMCPY2D;
; * \endcode
; * where:
; * - ::srcMemoryType and ::dstMemoryType specify the type of memory of the
; *   source and destination, respectively; ::CUmemorytype_enum is defined as:
; *
; * \code
;   typedef enum CUmemorytype_enum {
;      CU_MEMORYTYPE_HOST = 0x01,
;      CU_MEMORYTYPE_DEVICE = 0x02,
;      CU_MEMORYTYPE_ARRAY = 0x03,
;      CU_MEMORYTYPE_UNIFIED = 0x04
;   } CUmemorytype;
; * \endcode
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::srcDevice and ::srcPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::srcArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_HOST, ::srcHost and ::srcPitch
; * specify the (host) base address of the source data and the bytes per row to
; * apply. ::srcArray is ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_DEVICE, ::srcDevice and ::srcPitch
; * specify the (device) base address of the source data and the bytes per row
; * to apply. ::srcArray is ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_ARRAY, ::srcArray specifies the
; * handle of the source data. ::srcHost, ::srcDevice and ::srcPitch are
; * ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_HOST, ::dstHost and ::dstPitch
; * specify the (host) base address of the destination data and the bytes per
; * row to apply. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::dstDevice and ::dstPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::dstArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_DEVICE, ::dstDevice and ::dstPitch
; * specify the (device) base address of the destination data and the bytes per
; * row to apply. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_ARRAY, ::dstArray specifies the
; * handle of the destination data. ::dstHost, ::dstDevice and ::dstPitch are
; * ignored.
; *
; * - ::srcXInBytes and ::srcY specify the base address of the source data for
; *   the copy.
; *
; * \par
; * For host pointers, the starting address is
; * \code
;  void* Start = (void*)((char*)srcHost+srcY*srcPitch + srcXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr Start = srcDevice+srcY*srcPitch+srcXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::srcXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::dstXInBytes and ::dstY specify the base address of the destination data
; *   for the copy.
; *
; * \par
; * For host pointers, the base address is
; * \code
;  void* dstStart = (void*)((char*)dstHost+dstY*dstPitch + dstXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr dstStart = dstDevice+dstY*dstPitch+dstXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::dstXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::WidthInBytes and ::Height specify the width (in bytes) and height of
; *   the 2D copy being performed.
; * - If specified, ::srcPitch must be greater than or equal to ::WidthInBytes +
; *   ::srcXInBytes, and ::dstPitch must be greater than or equal to
; *   ::WidthInBytes + dstXInBytes.
; *
; * \par
; * ::cuMemcpy2D() returns an error if any pitch is greater than the maximum
; * allowed (::CU_DEVICE_ATTRIBUTE_MAX_PITCH). ::cuMemAllocPitch() passes back
; * pitches that always work with ::cuMemcpy2D(). On intra-device memory copies
; * (device to device, CUDA array to device, CUDA array to CUDA array),
; * ::cuMemcpy2D() may fail for pitches not computed by ::cuMemAllocPitch().
; * ::cuMemcpy2DUnaligned() does not have this restriction, but may run
; * significantly slower in the cases where ::cuMemcpy2D() would have returned
; * an error code.
; *
; * \param pCopy - Parameters for the memory copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy2D,
; * ::cudaMemcpy2DToArray,
; * ::cudaMemcpy2DFromArray
; */
;API
cuMemcpy2D PROTO pCopy:XWORD 
;/**
; * \brief Copies memory for 2D arrays
; *
; * Perform a 2D memory copy according to the parameters specified in \p pCopy.
; * The ::CUDA_MEMCPY2D structure is defined as:
; *
; * \code
;   typedef struct CUDA_MEMCPY2D_st {
;      unsigned int srcXInBytes, srcY;
;      CUmemorytype srcMemoryType;
;      const void *srcHost;
;      CUdeviceptr srcDevice;
;      CUarray srcArray;
;      unsigned int srcPitch;
;      unsigned int dstXInBytes, dstY;
;      CUmemorytype dstMemoryType;
;      void *dstHost;
;      CUdeviceptr dstDevice;
;      CUarray dstArray;
;      unsigned int dstPitch;
;      unsigned int WidthInBytes;
;      unsigned int Height;
;   } CUDA_MEMCPY2D;
; * \endcode
; * where:
; * - ::srcMemoryType and ::dstMemoryType specify the type of memory of the
; *   source and destination, respectively; ::CUmemorytype_enum is defined as:
; *
; * \code
;   typedef enum CUmemorytype_enum {
;      CU_MEMORYTYPE_HOST = 0x01,
;      CU_MEMORYTYPE_DEVICE = 0x02,
;      CU_MEMORYTYPE_ARRAY = 0x03,
;      CU_MEMORYTYPE_UNIFIED = 0x04
;   } CUmemorytype;
; * \endcode
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::srcDevice and ::srcPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::srcArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_HOST, ::srcHost and ::srcPitch
; * specify the (host) base address of the source data and the bytes per row to
; * apply. ::srcArray is ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_DEVICE, ::srcDevice and ::srcPitch
; * specify the (device) base address of the source data and the bytes per row
; * to apply. ::srcArray is ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_ARRAY, ::srcArray specifies the
; * handle of the source data. ::srcHost, ::srcDevice and ::srcPitch are
; * ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::dstDevice and ::dstPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::dstArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_HOST, ::dstHost and ::dstPitch
; * specify the (host) base address of the destination data and the bytes per
; * row to apply. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_DEVICE, ::dstDevice and ::dstPitch
; * specify the (device) base address of the destination data and the bytes per
; * row to apply. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_ARRAY, ::dstArray specifies the
; * handle of the destination data. ::dstHost, ::dstDevice and ::dstPitch are
; * ignored.
; *
; * - ::srcXInBytes and ::srcY specify the base address of the source data for
; *   the copy.
; *
; * \par
; * For host pointers, the starting address is
; * \code
;  void* Start = (void*)((char*)srcHost+srcY*srcPitch + srcXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr Start = srcDevice+srcY*srcPitch+srcXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::srcXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::dstXInBytes and ::dstY specify the base address of the destination data
; *   for the copy.
; *
; * \par
; * For host pointers, the base address is
; * \code
;  void* dstStart = (void*)((char*)dstHost+dstY*dstPitch + dstXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr dstStart = dstDevice+dstY*dstPitch+dstXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::dstXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::WidthInBytes and ::Height specify the width (in bytes) and height of
; *   the 2D copy being performed.
; * - If specified, ::srcPitch must be greater than or equal to ::WidthInBytes +
; *   ::srcXInBytes, and ::dstPitch must be greater than or equal to
; *   ::WidthInBytes + dstXInBytes.
; *
; * \par
; * ::cuMemcpy2D() returns an error if any pitch is greater than the maximum
; * allowed (::CU_DEVICE_ATTRIBUTE_MAX_PITCH). ::cuMemAllocPitch() passes back
; * pitches that always work with ::cuMemcpy2D(). On intra-device memory copies
; * (device to device, CUDA array to device, CUDA array to CUDA array),
; * ::cuMemcpy2D() may fail for pitches not computed by ::cuMemAllocPitch().
; * ::cuMemcpy2DUnaligned() does not have this restriction, but may run
; * significantly slower in the cases where ::cuMemcpy2D() would have returned
; * an error code.
; *
; * \param pCopy - Parameters for the memory copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy2D,
; * ::cudaMemcpy2DToArray,
; * ::cudaMemcpy2DFromArray
; */
;API
cuMemcpy2DUnaligned PROTO pCopy:XWORD 
;/**
; * \brief Copies memory for 3D arrays
; *
; * Perform a 3D memory copy according to the parameters specified in
; * \p pCopy. The ::CUDA_MEMCPY3D structure is defined as:
; *
; * \code
;        typedef struct CUDA_MEMCPY3D_st {
;            unsigned int srcXInBytes, srcY, srcZ;
;            unsigned int srcLOD;
;            CUmemorytype srcMemoryType;
;                const void *srcHost;
;                CUdeviceptr srcDevice;
;                CUarray srcArray;
;                unsigned int srcPitch;  // ignored when src is array
;                unsigned int srcHeight; // ignored when src is array; may be 0 if Depth==1
;            unsigned int dstXInBytes, dstY, dstZ;
;            unsigned int dstLOD;
;            CUmemorytype dstMemoryType;
;                void *dstHost;
;                CUdeviceptr dstDevice;
;                CUarray dstArray;
;                unsigned int dstPitch;  // ignored when dst is array
;                unsigned int dstHeight; // ignored when dst is array; may be 0 if Depth==1
;            unsigned int WidthInBytes;
;            unsigned int Height;
;            unsigned int Depth;
;        } CUDA_MEMCPY3D;
; * \endcode
; * where:
; * - ::srcMemoryType and ::dstMemoryType specify the type of memory of the
; *   source and destination, respectively; ::CUmemorytype_enum is defined as:
; *
; * \code
;   typedef enum CUmemorytype_enum {
;      CU_MEMORYTYPE_HOST = 0x01,
;      CU_MEMORYTYPE_DEVICE = 0x02,
;      CU_MEMORYTYPE_ARRAY = 0x03,
;      CU_MEMORYTYPE_UNIFIED = 0x04
;   } CUmemorytype;
; * \endcode
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::srcDevice and ::srcPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::srcArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_HOST, ::srcHost, ::srcPitch and
; * ::srcHeight specify the (host) base address of the source data, the bytes
; * per row, and the height of each 2D slice of the 3D array. ::srcArray is
; * ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_DEVICE, ::srcDevice, ::srcPitch and
; * ::srcHeight specify the (device) base address of the source data, the bytes
; * per row, and the height of each 2D slice of the 3D array. ::srcArray is
; * ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_ARRAY, ::srcArray specifies the
; * handle of the source data. ::srcHost, ::srcDevice, ::srcPitch and
; * ::srcHeight are ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::dstDevice and ::dstPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::dstArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_HOST, ::dstHost and ::dstPitch
; * specify the (host) base address of the destination data, the bytes per row,
; * and the height of each 2D slice of the 3D array. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_DEVICE, ::dstDevice and ::dstPitch
; * specify the (device) base address of the destination data, the bytes per
; * row, and the height of each 2D slice of the 3D array. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_ARRAY, ::dstArray specifies the
; * handle of the destination data. ::dstHost, ::dstDevice, ::dstPitch and
; * ::dstHeight are ignored.
; *
; * - ::srcXInBytes, ::srcY and ::srcZ specify the base address of the source
; *   data for the copy.
; *
; * \par
; * For host pointers, the starting address is
; * \code
;  void* Start = (void*)((char*)srcHost+(srcZ*srcHeight+srcY)*srcPitch + srcXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr Start = srcDevice+(srcZ*srcHeight+srcY)*srcPitch+srcXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::srcXInBytes must be evenly divisible by the array
; * element size.
; *
; * - dstXInBytes, ::dstY and ::dstZ specify the base address of the
; *   destination data for the copy.
; *
; * \par
; * For host pointers, the base address is
; * \code
;  void* dstStart = (void*)((char*)dstHost+(dstZ*dstHeight+dstY)*dstPitch + dstXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr dstStart = dstDevice+(dstZ*dstHeight+dstY)*dstPitch+dstXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::dstXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::WidthInBytes, ::Height and ::Depth specify the width (in bytes), height
; *   and depth of the 3D copy being performed.
; * - If specified, ::srcPitch must be greater than or equal to ::WidthInBytes +
; *   ::srcXInBytes, and ::dstPitch must be greater than or equal to
; *   ::WidthInBytes + dstXInBytes.
; * - If specified, ::srcHeight must be greater than or equal to ::Height +
; *   ::srcY, and ::dstHeight must be greater than or equal to ::Height + ::dstY.
; *
; * \par
; * ::cuMemcpy3D() returns an error if any pitch is greater than the maximum
; * allowed (::CU_DEVICE_ATTRIBUTE_MAX_PITCH).
; *
; * The ::srcLOD and ::dstLOD members of the ::CUDA_MEMCPY3D structure must be
; * set to 0.
; *
; * \param pCopy - Parameters for the memory copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMemcpy3D
; */
;API
cuMemcpy3D PROTO pCopy:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Copies memory between contexts
; *
; * Perform a 3D memory copy according to the parameters specified in
; * \p pCopy.  See the definition of the ::CUDA_MEMCPY3D_PEER structure
; * for documentation of its parameters.
; *
; * \param pCopy - Parameters for the memory copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_sync
; *
; * \sa ::cuMemcpyDtoD, ::cuMemcpyPeer, ::cuMemcpyDtoDAsync, ::cuMemcpyPeerAsync,
; * ::cuMemcpy3DPeerAsync,
; * ::cudaMemcpy3DPeer
; */
;API
cuMemcpy3DPeer PROTO pCopy:XWORD 
;/**
; * \brief Copies memory asynchronously
; *
; * Copies data between two pointers.
; * \p dst and \p src are base pointers of the destination and source, respectively.
; * \p ByteCount specifies the number of bytes to copy.
; * Note that this function infers the type of the transfer (host to host, host to
; *   device, device to device, or device to host) from the pointer values.  This
; *   function is only allowed in contexts which support unified addressing.
; *
; * \param dst       - Destination unified virtual address space pointer
; * \param src       - Source unified virtual address space pointer
; * \param ByteCount - Size of memory copy in bytes
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpyAsync,
; * ::cudaMemcpyToSymbolAsync,
; * ::cudaMemcpyFromSymbolAsync
; */
;API
cuMemcpyAsync PROTO dst:CUdeviceptr ,src:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;/**
; * \brief Copies device memory between two contexts asynchronously.
; *
; * Copies from device memory in one context to device memory in another
; * context. \p dstDevice is the base device pointer of the destination memory
; * and \p dstContext is the destination context.  \p srcDevice is the base
; * device pointer of the source memory and \p srcContext is the source pointer.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstDevice  - Destination device pointer
; * \param dstContext - Destination context
; * \param srcDevice  - Source device pointer
; * \param srcContext - Source context
; * \param ByteCount  - Size of memory copy in bytes
; * \param hStream    - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuMemcpyDtoD, ::cuMemcpyPeer, ::cuMemcpy3DPeer, ::cuMemcpyDtoDAsync,
; * ::cuMemcpy3DPeerAsync,
; * ::cudaMemcpyPeerAsync
; */
;API
cuMemcpyPeerAsync PROTO dstDevice:CUdeviceptr ,dstContext:XWORD ,srcDevice:CUdeviceptr ,srcContext:XWORD ,ByteCount:DWORD ,hStream:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Copies memory from Host to Device
; *
; * Copies from host memory to device memory. \p dstDevice and \p srcHost are
; * the base addresses of the destination and source, respectively. \p ByteCount
; * specifies the number of bytes to copy.
; *
; * \param dstDevice - Destination device pointer
; * \param srcHost   - Source host pointer
; * \param ByteCount - Size of memory copy in bytes
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpyAsync,
; * ::cudaMemcpyToSymbolAsync
; */
;API
cuMemcpyHtoDAsync PROTO dstDevice:CUdeviceptr ,srcHost:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;/**
; * \brief Copies memory from Device to Host
; *
; * Copies from device to host memory. \p dstHost and \p srcDevice specify the
; * base pointers of the destination and source, respectively. \p ByteCount
; * specifies the number of bytes to copy.
; *
; * \param dstHost   - Destination host pointer
; * \param srcDevice - Source device pointer
; * \param ByteCount - Size of memory copy in bytes
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpyAsync,
; * ::cudaMemcpyFromSymbolAsync
; */
;API
cuMemcpyDtoHAsync PROTO dstHost:XWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;/**
; * \brief Copies memory from Device to Device
; *
; * Copies from device memory to device memory. \p dstDevice and \p srcDevice
; * are the base pointers of the destination and source, respectively.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstDevice - Destination device pointer
; * \param srcDevice - Source device pointer
; * \param ByteCount - Size of memory copy in bytes
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpyAsync,
; * ::cudaMemcpyToSymbolAsync,
; * ::cudaMemcpyFromSymbolAsync
; */
;API
cuMemcpyDtoDAsync PROTO dstDevice:CUdeviceptr ,srcDevice:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;/**
; * \brief Copies memory from Host to Array
; *
; * Copies from host memory to a 1D CUDA array. \p dstArray and \p dstOffset
; * specify the CUDA array handle and starting offset in bytes of the
; * destination data. \p srcHost specifies the base address of the source.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstArray  - Destination array
; * \param dstOffset - Offset in bytes of destination array
; * \param srcHost   - Source host pointer
; * \param ByteCount - Size of memory copy in bytes
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpyToArrayAsync
; */
;API
cuMemcpyHtoAAsync PROTO dstArray:XWORD ,dstOffset:DWORD ,srcHost:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;/**
; * \brief Copies memory from Array to Host
; *
; * Copies from one 1D CUDA array to host memory. \p dstHost specifies the base
; * pointer of the destination. \p srcArray and \p srcOffset specify the CUDA
; * array handle and starting offset in bytes of the source data.
; * \p ByteCount specifies the number of bytes to copy.
; *
; * \param dstHost   - Destination pointer
; * \param srcArray  - Source array
; * \param srcOffset - Offset in bytes of source array
; * \param ByteCount - Size of memory copy in bytes
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpyFromArrayAsync
; */
;API
cuMemcpyAtoHAsync PROTO dstHost:XWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD ,hStream:XWORD 
;/**
; * \brief Copies memory for 2D arrays
; *
; * Perform a 2D memory copy according to the parameters specified in \p pCopy.
; * The ::CUDA_MEMCPY2D structure is defined as:
; *
; * \code
;   typedef struct CUDA_MEMCPY2D_st {
;      unsigned int srcXInBytes, srcY;
;      CUmemorytype srcMemoryType;
;      const void *srcHost;
;      CUdeviceptr srcDevice;
;      CUarray srcArray;
;      unsigned int srcPitch;
;      unsigned int dstXInBytes, dstY;
;      CUmemorytype dstMemoryType;
;      void *dstHost;
;      CUdeviceptr dstDevice;
;      CUarray dstArray;
;      unsigned int dstPitch;
;      unsigned int WidthInBytes;
;      unsigned int Height;
;   } CUDA_MEMCPY2D;
; * \endcode
; * where:
; * - ::srcMemoryType and ::dstMemoryType specify the type of memory of the
; *   source and destination, respectively; ::CUmemorytype_enum is defined as:
; *
; * \code
;   typedef enum CUmemorytype_enum {
;      CU_MEMORYTYPE_HOST = 0x01,
;      CU_MEMORYTYPE_DEVICE = 0x02,
;      CU_MEMORYTYPE_ARRAY = 0x03,
;      CU_MEMORYTYPE_UNIFIED = 0x04
;   } CUmemorytype;
; * \endcode
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_HOST, ::srcHost and ::srcPitch
; * specify the (host) base address of the source data and the bytes per row to
; * apply. ::srcArray is ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::srcDevice and ::srcPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::srcArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_DEVICE, ::srcDevice and ::srcPitch
; * specify the (device) base address of the source data and the bytes per row
; * to apply. ::srcArray is ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_ARRAY, ::srcArray specifies the
; * handle of the source data. ::srcHost, ::srcDevice and ::srcPitch are
; * ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::dstDevice and ::dstPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::dstArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_HOST, ::dstHost and ::dstPitch
; * specify the (host) base address of the destination data and the bytes per
; * row to apply. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_DEVICE, ::dstDevice and ::dstPitch
; * specify the (device) base address of the destination data and the bytes per
; * row to apply. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_ARRAY, ::dstArray specifies the
; * handle of the destination data. ::dstHost, ::dstDevice and ::dstPitch are
; * ignored.
; *
; * - ::srcXInBytes and ::srcY specify the base address of the source data for
; *   the copy.
; *
; * \par
; * For host pointers, the starting address is
; * \code
;  void* Start = (void*)((char*)srcHost+srcY*srcPitch + srcXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr Start = srcDevice+srcY*srcPitch+srcXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::srcXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::dstXInBytes and ::dstY specify the base address of the destination data
; *   for the copy.
; *
; * \par
; * For host pointers, the base address is
; * \code
;  void* dstStart = (void*)((char*)dstHost+dstY*dstPitch + dstXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr dstStart = dstDevice+dstY*dstPitch+dstXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::dstXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::WidthInBytes and ::Height specify the width (in bytes) and height of
; *   the 2D copy being performed.
; * - If specified, ::srcPitch must be greater than or equal to ::WidthInBytes +
; *   ::srcXInBytes, and ::dstPitch must be greater than or equal to
; *   ::WidthInBytes + dstXInBytes.
; * - If specified, ::srcPitch must be greater than or equal to ::WidthInBytes +
; *   ::srcXInBytes, and ::dstPitch must be greater than or equal to
; *   ::WidthInBytes + dstXInBytes.
; * - If specified, ::srcHeight must be greater than or equal to ::Height +
; *   ::srcY, and ::dstHeight must be greater than or equal to ::Height + ::dstY.
; *
; * \par
; * ::cuMemcpy2DAsync() returns an error if any pitch is greater than the maximum
; * allowed (::CU_DEVICE_ATTRIBUTE_MAX_PITCH). ::cuMemAllocPitch() passes back
; * pitches that always work with ::cuMemcpy2D(). On intra-device memory copies
; * (device to device, CUDA array to device, CUDA array to CUDA array),
; * ::cuMemcpy2DAsync() may fail for pitches not computed by ::cuMemAllocPitch().
; *
; * \param pCopy   - Parameters for the memory copy
; * \param hStream - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpy2DAsync,
; * ::cudaMemcpy2DToArrayAsync,
; * ::cudaMemcpy2DFromArrayAsync
; */
;API
cuMemcpy2DAsync PROTO pCopy:XWORD ,hStream:XWORD 
;/**
; * \brief Copies memory for 3D arrays
; *
; * Perform a 3D memory copy according to the parameters specified in
; * \p pCopy. The ::CUDA_MEMCPY3D structure is defined as:
; *
; * \code
;        typedef struct CUDA_MEMCPY3D_st {
;            unsigned int srcXInBytes, srcY, srcZ;
;            unsigned int srcLOD;
;            CUmemorytype srcMemoryType;
;                const void *srcHost;
;                CUdeviceptr srcDevice;
;                CUarray srcArray;
;                unsigned int srcPitch;  // ignored when src is array
;                unsigned int srcHeight; // ignored when src is array; may be 0 if Depth==1
;            unsigned int dstXInBytes, dstY, dstZ;
;            unsigned int dstLOD;
;            CUmemorytype dstMemoryType;
;                void *dstHost;
;                CUdeviceptr dstDevice;
;                CUarray dstArray;
;                unsigned int dstPitch;  // ignored when dst is array
;                unsigned int dstHeight; // ignored when dst is array; may be 0 if Depth==1
;            unsigned int WidthInBytes;
;            unsigned int Height;
;            unsigned int Depth;
;        } CUDA_MEMCPY3D;
; * \endcode
; * where:
; * - ::srcMemoryType and ::dstMemoryType specify the type of memory of the
; *   source and destination, respectively; ::CUmemorytype_enum is defined as:
; *
; * \code
;   typedef enum CUmemorytype_enum {
;      CU_MEMORYTYPE_HOST = 0x01,
;      CU_MEMORYTYPE_DEVICE = 0x02,
;      CU_MEMORYTYPE_ARRAY = 0x03,
;      CU_MEMORYTYPE_UNIFIED = 0x04
;   } CUmemorytype;
; * \endcode
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::srcDevice and ::srcPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::srcArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_HOST, ::srcHost, ::srcPitch and
; * ::srcHeight specify the (host) base address of the source data, the bytes
; * per row, and the height of each 2D slice of the 3D array. ::srcArray is
; * ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_DEVICE, ::srcDevice, ::srcPitch and
; * ::srcHeight specify the (device) base address of the source data, the bytes
; * per row, and the height of each 2D slice of the 3D array. ::srcArray is
; * ignored.
; *
; * \par
; * If ::srcMemoryType is ::CU_MEMORYTYPE_ARRAY, ::srcArray specifies the
; * handle of the source data. ::srcHost, ::srcDevice, ::srcPitch and
; * ::srcHeight are ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_UNIFIED, ::dstDevice and ::dstPitch
; *   specify the (unified virtual address space) base address of the source data
; *   and the bytes per row to apply.  ::dstArray is ignored.
; * This value may be used only if unified addressing is supported in the calling
; *   context.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_HOST, ::dstHost and ::dstPitch
; * specify the (host) base address of the destination data, the bytes per row,
; * and the height of each 2D slice of the 3D array. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_DEVICE, ::dstDevice and ::dstPitch
; * specify the (device) base address of the destination data, the bytes per
; * row, and the height of each 2D slice of the 3D array. ::dstArray is ignored.
; *
; * \par
; * If ::dstMemoryType is ::CU_MEMORYTYPE_ARRAY, ::dstArray specifies the
; * handle of the destination data. ::dstHost, ::dstDevice, ::dstPitch and
; * ::dstHeight are ignored.
; *
; * - ::srcXInBytes, ::srcY and ::srcZ specify the base address of the source
; *   data for the copy.
; *
; * \par
; * For host pointers, the starting address is
; * \code
;  void* Start = (void*)((char*)srcHost+(srcZ*srcHeight+srcY)*srcPitch + srcXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr Start = srcDevice+(srcZ*srcHeight+srcY)*srcPitch+srcXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::srcXInBytes must be evenly divisible by the array
; * element size.
; *
; * - dstXInBytes, ::dstY and ::dstZ specify the base address of the
; *   destination data for the copy.
; *
; * \par
; * For host pointers, the base address is
; * \code
;  void* dstStart = (void*)((char*)dstHost+(dstZ*dstHeight+dstY)*dstPitch + dstXInBytes);
; * \endcode
; *
; * \par
; * For device pointers, the starting address is
; * \code
;  CUdeviceptr dstStart = dstDevice+(dstZ*dstHeight+dstY)*dstPitch+dstXInBytes;
; * \endcode
; *
; * \par
; * For CUDA arrays, ::dstXInBytes must be evenly divisible by the array
; * element size.
; *
; * - ::WidthInBytes, ::Height and ::Depth specify the width (in bytes), height
; *   and depth of the 3D copy being performed.
; * - If specified, ::srcPitch must be greater than or equal to ::WidthInBytes +
; *   ::srcXInBytes, and ::dstPitch must be greater than or equal to
; *   ::WidthInBytes + dstXInBytes.
; * - If specified, ::srcHeight must be greater than or equal to ::Height +
; *   ::srcY, and ::dstHeight must be greater than or equal to ::Height + ::dstY.
; *
; * \par
; * ::cuMemcpy3DAsync() returns an error if any pitch is greater than the maximum
; * allowed (::CU_DEVICE_ATTRIBUTE_MAX_PITCH).
; *
; * The ::srcLOD and ::dstLOD members of the ::CUDA_MEMCPY3D structure must be
; * set to 0.
; *
; * \param pCopy - Parameters for the memory copy
; * \param hStream - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemcpy3DAsync
; */
;API
cuMemcpy3DAsync PROTO pCopy:XWORD ,hStream:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Copies memory between contexts asynchronously.
; *
; * Perform a 3D memory copy according to the parameters specified in
; * \p pCopy.  See the definition of the ::CUDA_MEMCPY3D_PEER structure
; * for documentation of its parameters.
; *
; * \param pCopy - Parameters for the memory copy
; * \param hStream - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuMemcpyDtoD, ::cuMemcpyPeer, ::cuMemcpyDtoDAsync, ::cuMemcpyPeerAsync,
; * ::cuMemcpy3DPeerAsync,
; * ::cudaMemcpy3DPeerAsync
; */
;API
cuMemcpy3DPeerAsync PROTO pCopy:XWORD ,hStream:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Initializes device memory
; *
; * Sets the memory range of \p N 8-bit values to the specified value
; * \p uc.
; *
; * \param dstDevice - Destination device pointer
; * \param uc        - Value to set
; * \param N         - Number of elements
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset
; */
;API
cuMemsetD8 PROTO dstDevice:CUdeviceptr ,uc:DWORD ,N:DWORD 
;/**
; * \brief Initializes device memory
; *
; * Sets the memory range of \p N 16-bit values to the specified value
; * \p us. The \p dstDevice pointer must be two byte aligned.
; *
; * \param dstDevice - Destination device pointer
; * \param us        - Value to set
; * \param N         - Number of elements
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset
; */
;API
cuMemsetD16 PROTO dstDevice:CUdeviceptr ,us:DWORD ,N:DWORD 
;/**
; * \brief Initializes device memory
; *
; * Sets the memory range of \p N 32-bit values to the specified value
; * \p ui. The \p dstDevice pointer must be four byte aligned.
; *
; * \param dstDevice - Destination device pointer
; * \param ui        - Value to set
; * \param N         - Number of elements
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32Async,
; * ::cudaMemset
; */
;API
cuMemsetD32 PROTO dstDevice:CUdeviceptr ,ui:DWORD ,N:DWORD 
;/**
; * \brief Initializes device memory
; *
; * Sets the 2D memory range of \p Width 8-bit values to the specified value
; * \p uc. \p Height specifies the number of rows to set, and \p dstPitch
; * specifies the number of bytes between each row. This function performs
; * fastest when the pitch is one that has been passed back by
; * ::cuMemAllocPitch().
; *
; * \param dstDevice - Destination device pointer
; * \param dstPitch  - Pitch of destination device pointer
; * \param uc        - Value to set
; * \param Width     - Width of row
; * \param Height    - Number of rows
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset2D
; */
;API
cuMemsetD2D8 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,uc:DWORD ,awidth:DWORD ,Height:DWORD 
;/**
; * \brief Initializes device memory
; *
; * Sets the 2D memory range of \p Width 16-bit values to the specified value
; * \p us. \p Height specifies the number of rows to set, and \p dstPitch
; * specifies the number of bytes between each row. The \p dstDevice pointer
; * and \p dstPitch offset must be two byte aligned. This function performs
; * fastest when the pitch is one that has been passed back by
; * ::cuMemAllocPitch().
; *
; * \param dstDevice - Destination device pointer
; * \param dstPitch  - Pitch of destination device pointer
; * \param us        - Value to set
; * \param Width     - Width of row
; * \param Height    - Number of rows
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset2D
; */
;API
cuMemsetD2D16 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,us:DWORD ,awidth:DWORD ,Height:DWORD 
;/**
; * \brief Initializes device memory
; *
; * Sets the 2D memory range of \p Width 32-bit values to the specified value
; * \p ui. \p Height specifies the number of rows to set, and \p dstPitch
; * specifies the number of bytes between each row. The \p dstDevice pointer
; * and \p dstPitch offset must be four byte aligned. This function performs
; * fastest when the pitch is one that has been passed back by
; * ::cuMemAllocPitch().
; *
; * \param dstDevice - Destination device pointer
; * \param dstPitch  - Pitch of destination device pointer
; * \param ui        - Value to set
; * \param Width     - Width of row
; * \param Height    - Number of rows
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset2D
; */
;API
cuMemsetD2D32 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,ui:DWORD ,awidth:DWORD ,Height:DWORD 
;/**
; * \brief Sets device memory
; *
; * Sets the memory range of \p N 8-bit values to the specified value
; * \p uc.
; *
; * \param dstDevice - Destination device pointer
; * \param uc        - Value to set
; * \param N         - Number of elements
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemsetAsync
; */
;API
cuMemsetD8Async PROTO dstDevice:CUdeviceptr ,uc:DWORD ,N:DWORD ,hStream:XWORD 
;/**
; * \brief Sets device memory
; *
; * Sets the memory range of \p N 16-bit values to the specified value
; * \p us. The \p dstDevice pointer must be two byte aligned.
; *
; * \param dstDevice - Destination device pointer
; * \param us        - Value to set
; * \param N         - Number of elements
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemsetAsync
; */
;API
cuMemsetD16Async PROTO dstDevice:CUdeviceptr ,us:DWORD ,N:DWORD ,hStream:XWORD 
;/**
; * \brief Sets device memory
; *
; * Sets the memory range of \p N 32-bit values to the specified value
; * \p ui. The \p dstDevice pointer must be four byte aligned.
; *
; * \param dstDevice - Destination device pointer
; * \param ui        - Value to set
; * \param N         - Number of elements
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async, ::cuMemsetD32,
; * ::cudaMemsetAsync
; */
;API
cuMemsetD32Async PROTO dstDevice:CUdeviceptr ,ui:DWORD ,N:DWORD ,hStream:XWORD 
;/**
; * \brief Sets device memory
; *
; * Sets the 2D memory range of \p Width 8-bit values to the specified value
; * \p uc. \p Height specifies the number of rows to set, and \p dstPitch
; * specifies the number of bytes between each row. This function performs
; * fastest when the pitch is one that has been passed back by
; * ::cuMemAllocPitch().
; *
; * \param dstDevice - Destination device pointer
; * \param dstPitch  - Pitch of destination device pointer
; * \param uc        - Value to set
; * \param Width     - Width of row
; * \param Height    - Number of rows
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset2DAsync
; */
;API
cuMemsetD2D8Async PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,uc:DWORD ,awidth:DWORD ,Height:DWORD ,hStream:XWORD 
;/**
; * \brief Sets device memory
; *
; * Sets the 2D memory range of \p Width 16-bit values to the specified value
; * \p us. \p Height specifies the number of rows to set, and \p dstPitch
; * specifies the number of bytes between each row. The \p dstDevice pointer
; * and \p dstPitch offset must be two byte aligned. This function performs
; * fastest when the pitch is one that has been passed back by
; * ::cuMemAllocPitch().
; *
; * \param dstDevice - Destination device pointer
; * \param dstPitch  - Pitch of destination device pointer
; * \param us        - Value to set
; * \param Width     - Width of row
; * \param Height    - Number of rows
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D32, ::cuMemsetD2D32Async,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset2DAsync
; */
;API
cuMemsetD2D16Async PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,us:DWORD ,awidth:DWORD ,Height:DWORD ,hStream:XWORD 
;/**
; * \brief Sets device memory
; *
; * Sets the 2D memory range of \p Width 32-bit values to the specified value
; * \p ui. \p Height specifies the number of rows to set, and \p dstPitch
; * specifies the number of bytes between each row. The \p dstDevice pointer
; * and \p dstPitch offset must be four byte aligned. This function performs
; * fastest when the pitch is one that has been passed back by
; * ::cuMemAllocPitch().
; *
; * \param dstDevice - Destination device pointer
; * \param dstPitch  - Pitch of destination device pointer
; * \param ui        - Value to set
; * \param Width     - Width of row
; * \param Height    - Number of rows
; * \param hStream   - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; * \note_memset
; * \note_null_stream
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D8Async,
; * ::cuMemsetD2D16, ::cuMemsetD2D16Async, ::cuMemsetD2D32,
; * ::cuMemsetD8, ::cuMemsetD8Async, ::cuMemsetD16, ::cuMemsetD16Async,
; * ::cuMemsetD32, ::cuMemsetD32Async,
; * ::cudaMemset2DAsync
; */
;API
cuMemsetD2D32Async PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,ui:DWORD ,awidth:DWORD ,Height:DWORD ,hStream:XWORD 
;/**
; * \brief Creates a 1D or 2D CUDA array
; *
; * Creates a CUDA array according to the ::CUDA_ARRAY_DESCRIPTOR structure
; * \p pAllocateArray and returns a handle to the new CUDA array in \p *pHandle.
; * The ::CUDA_ARRAY_DESCRIPTOR is defined as:
; *
; * \code
;    typedef struct {
;        unsigned int Width;
;        unsigned int Height;
;        CUarray_format Format;
;        unsigned int NumChannels;
;    } CUDA_ARRAY_DESCRIPTOR;
; * \endcode
; * where:
; *
; * - \p Width, and \p Height are the width, and height of the CUDA array (in
; * elements); the CUDA array is one-dimensional if height is 0, two-dimensional
; * otherwise;
; * - ::Format specifies the format of the elements; ::CUarray_format is
; * defined as:
; * \code
;    typedef enum CUarray_format_enum {
;        CU_AD_FORMAT_UNSIGNED_INT8 = 0x01,
;        CU_AD_FORMAT_UNSIGNED_INT16 = 0x02,
;        CU_AD_FORMAT_UNSIGNED_INT32 = 0x03,
;        CU_AD_FORMAT_SIGNED_INT8 = 0x08,
;        CU_AD_FORMAT_SIGNED_INT16 = 0x09,
;        CU_AD_FORMAT_SIGNED_INT32 = 0x0a,
;        CU_AD_FORMAT_HALF = 0x10,
;        CU_AD_FORMAT_FLOAT = 0x20
;    } CUarray_format;
; *  \endcode
; * - \p NumChannels specifies the number of packed components per CUDA array
; * element; it may be 1, 2, or 4;
; *
; * Here are examples of CUDA array descriptions:
; *
; * Description for a CUDA array of 2048 floats:
; * \code
;    CUDA_ARRAY_DESCRIPTOR desc;
;    desc.Format = CU_AD_FORMAT_FLOAT;
;    desc.NumChannels = 1;
;    desc.Width = 2048;
;    desc.Height = 1;
; * \endcode
; *
; * Description for a 64 x 64 CUDA array of floats:
; * \code
;    CUDA_ARRAY_DESCRIPTOR desc;
;    desc.Format = CU_AD_FORMAT_FLOAT;
;    desc.NumChannels = 1;
;    desc.Width = 64;
;    desc.Height = 64;
; * \endcode
; *
; * Description for a \p width x \p height CUDA array of 64-bit, 4x16-bit
; * float16's:
; * \code
;    CUDA_ARRAY_DESCRIPTOR desc;
;    desc.FormatFlags = CU_AD_FORMAT_HALF;
;    desc.NumChannels = 4;
;    desc.Width = width;
;    desc.Height = height;
; * \endcode
; *
; * Description for a \p width x \p height CUDA array of 16-bit elements, each
; * of which is two 8-bit unsigned chars:
; * \code
;    CUDA_ARRAY_DESCRIPTOR arrayDesc;
;    desc.FormatFlags = CU_AD_FORMAT_UNSIGNED_INT8;
;    desc.NumChannels = 2;
;    desc.Width = width;
;    desc.Height = height;
; * \endcode
; *
; * \param pHandle        - Returned array
; * \param pAllocateArray - Array descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMallocArray
; */
;API
cuArrayCreate PROTO pHandle:XWORD ,pAllocateArray:XWORD 
;/**
; * \brief Get a 1D or 2D CUDA array descriptor
; *
; * Returns in \p *pArrayDescriptor a descriptor containing information on the
; * format and dimensions of the CUDA array \p hArray. It is useful for
; * subroutines that have been passed a CUDA array, but need to know the CUDA
; * array parameters for validation or other purposes.
; *
; * \param pArrayDescriptor - Returned array descriptor
; * \param hArray           - Array to get descriptor of
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaArrayGetInfo
; */
;API
cuArrayGetDescriptor PROTO pArrayDescriptor:XWORD ,hArray:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Destroys a CUDA array
; *
; * Destroys the CUDA array \p hArray.
; *
; * \param hArray - Array to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_ARRAY_IS_MAPPED,
; * ::CUDA_ERROR_CONTEXT_IS_DESTROYED
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaFreeArray
; */
;API
cuArrayDestroy PROTO hArray:XWORD 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Creates a 3D CUDA array
; *
; * Creates a CUDA array according to the ::CUDA_ARRAY3D_DESCRIPTOR structure
; * \p pAllocateArray and returns a handle to the new CUDA array in \p *pHandle.
; * The ::CUDA_ARRAY3D_DESCRIPTOR is defined as:
; *
; * \code
;    typedef struct {
;        unsigned int Width;
;        unsigned int Height;
;        unsigned int Depth;
;        CUarray_format Format;
;        unsigned int NumChannels;
;        unsigned int Flags;
;    } CUDA_ARRAY3D_DESCRIPTOR;
; * \endcode
; * where:
; *
; * - \p Width, \p Height, and \p Depth are the width, height, and depth of the
; * CUDA array (in elements); the following types of CUDA arrays can be allocated:
; *     - A 1D array is allocated if \p Height and \p Depth extents are both zero.
; *     - A 2D array is allocated if only \p Depth extent is zero.
; *     - A 3D array is allocated if all three extents are non-zero.
; *     - A 1D layered CUDA array is allocated if only \p Height is zero and the
; *       ::CUDA_ARRAY3D_LAYERED flag is set. Each layer is a 1D array. The number
; *       of layers is determined by the depth extent.
; *     - A 2D layered CUDA array is allocated if all three extents are non-zero and
; *       the ::CUDA_ARRAY3D_LAYERED flag is set. Each layer is a 2D array. The number
; *       of layers is determined by the depth extent.
; *     - A cubemap CUDA array is allocated if all three extents are non-zero and the
; *       ::CUDA_ARRAY3D_CUBEMAP flag is set. \p Width must be equal to \p Height, and
; *       \p Depth must be six. A cubemap is a special type of 2D layered CUDA array,
; *       where the six layers represent the six faces of a cube. The order of the six
; *       layers in memory is the same as that listed in ::CUarray_cubemap_face.
; *     - A cubemap layered CUDA array is allocated if all three extents are non-zero,
; *       and both, ::CUDA_ARRAY3D_CUBEMAP and ::CUDA_ARRAY3D_LAYERED flags are set.
; *       \p Width must be equal to \p Height, and \p Depth must be a multiple of six.
; *       A cubemap layered CUDA array is a special type of 2D layered CUDA array that
; *       consists of a collection of cubemaps. The first six layers represent the first
; *       cubemap, the next six layers form the second cubemap, and so on.
; *
; * - ::Format specifies the format of the elements; ::CUarray_format is
; * defined as:
; * \code
;    typedef enum CUarray_format_enum {
;        CU_AD_FORMAT_UNSIGNED_INT8 = 0x01,
;        CU_AD_FORMAT_UNSIGNED_INT16 = 0x02,
;        CU_AD_FORMAT_UNSIGNED_INT32 = 0x03,
;        CU_AD_FORMAT_SIGNED_INT8 = 0x08,
;        CU_AD_FORMAT_SIGNED_INT16 = 0x09,
;        CU_AD_FORMAT_SIGNED_INT32 = 0x0a,
;        CU_AD_FORMAT_HALF = 0x10,
;        CU_AD_FORMAT_FLOAT = 0x20
;    } CUarray_format;
; *  \endcode
; *
; * - \p NumChannels specifies the number of packed components per CUDA array
; * element; it may be 1, 2, or 4;
; *
; * - ::Flags may be set to
; *   - ::CUDA_ARRAY3D_LAYERED to enable creation of layered CUDA arrays. If this flag is set,
; *     \p Depth specifies the number of layers, not the depth of a 3D array.
; *   - ::CUDA_ARRAY3D_SURFACE_LDST to enable surface references to be bound to the CUDA array.
; *     If this flag is not set, ::cuSurfRefSetArray will fail when attempting to bind the CUDA array
; *     to a surface reference.
; *   - ::CUDA_ARRAY3D_CUBEMAP to enable creation of cubemaps. If this flag is set, \p Width must be
; *     equal to \p Height, and \p Depth must be six. If the ::CUDA_ARRAY3D_LAYERED flag is also set,
; *     then \p Depth must be a multiple of six.
; *   - ::CUDA_ARRAY3D_TEXTURE_GATHER to indicate that the CUDA array will be used for texture gather.
; *     Texture gather can only be performed on 2D CUDA arrays.
; *
; * \p Width, \p Height and \p Depth must meet certain size requirements as listed in the following table.
; * All values are specified in elements. Note that for brevity's sake, the full name of the device attribute
; * is not specified. For ex., TEXTURE1D_WIDTH refers to the device attribute
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH.
; *
; * Note that 2D CUDA arrays have different size requirements if the ::CUDA_ARRAY3D_TEXTURE_GATHER flag
; * is set. \p Width and \p Height must not be greater than ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH
; * and ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT respectively, in that case.
; *
; * <table>
; * <tr><td><b>CUDA array type</b></td>
; * <td><b>Valid extents that must always be met<br>{(width range in elements), (height range),
; * (depth range)}</b></td>
; * <td><b>Valid extents with CUDA_ARRAY3D_SURFACE_LDST set<br>
; * {(width range in elements), (height range), (depth range)}</b></td></tr>
; * <tr><td>1D</td>
; * <td><small>{ (1,TEXTURE1D_WIDTH), 0, 0 }</small></td>
; * <td><small>{ (1,SURFACE1D_WIDTH), 0, 0 }</small></td></tr>
; * <tr><td>2D</td>
; * <td><small>{ (1,TEXTURE2D_WIDTH), (1,TEXTURE2D_HEIGHT), 0 }</small></td>
; * <td><small>{ (1,SURFACE2D_WIDTH), (1,SURFACE2D_HEIGHT), 0 }</small></td></tr>
; * <tr><td>3D</td>
; * <td><small>{ (1,TEXTURE3D_WIDTH), (1,TEXTURE3D_HEIGHT), (1,TEXTURE3D_DEPTH) }
; * <br>OR<br>{ (1,TEXTURE3D_WIDTH_ALTERNATE), (1,TEXTURE3D_HEIGHT_ALTERNATE),
; * (1,TEXTURE3D_DEPTH_ALTERNATE) }</small></td>
; * <td><small>{ (1,SURFACE3D_WIDTH), (1,SURFACE3D_HEIGHT),
; * (1,SURFACE3D_DEPTH) }</small></td></tr>
; * <tr><td>1D Layered</td>
; * <td><small>{ (1,TEXTURE1D_LAYERED_WIDTH), 0,
; * (1,TEXTURE1D_LAYERED_LAYERS) }</small></td>
; * <td><small>{ (1,SURFACE1D_LAYERED_WIDTH), 0,
; * (1,SURFACE1D_LAYERED_LAYERS) }</small></td></tr>
; * <tr><td>2D Layered</td>
; * <td><small>{ (1,TEXTURE2D_LAYERED_WIDTH), (1,TEXTURE2D_LAYERED_HEIGHT),
; * (1,TEXTURE2D_LAYERED_LAYERS) }</small></td>
; * <td><small>{ (1,SURFACE2D_LAYERED_WIDTH), (1,SURFACE2D_LAYERED_HEIGHT),
; * (1,SURFACE2D_LAYERED_LAYERS) }</small></td></tr>
; * <tr><td>Cubemap</td>
; * <td><small>{ (1,TEXTURECUBEMAP_WIDTH), (1,TEXTURECUBEMAP_WIDTH), 6 }</small></td>
; * <td><small>{ (1,SURFACECUBEMAP_WIDTH),
; * (1,SURFACECUBEMAP_WIDTH), 6 }</small></td></tr>
; * <tr><td>Cubemap Layered</td>
; * <td><small>{ (1,TEXTURECUBEMAP_LAYERED_WIDTH), (1,TEXTURECUBEMAP_LAYERED_WIDTH),
; * (1,TEXTURECUBEMAP_LAYERED_LAYERS) }</small></td>
; * <td><small>{ (1,SURFACECUBEMAP_LAYERED_WIDTH), (1,SURFACECUBEMAP_LAYERED_WIDTH),
; * (1,SURFACECUBEMAP_LAYERED_LAYERS) }</small></td></tr>
; * </table>
; *
; * Here are examples of CUDA array descriptions:
; *
; * Description for a CUDA array of 2048 floats:
; * \code
;    CUDA_ARRAY3D_DESCRIPTOR desc;
;    desc.Format = CU_AD_FORMAT_FLOAT;
;    desc.NumChannels = 1;
;    desc.Width = 2048;
;    desc.Height = 0;
;    desc.Depth = 0;
; * \endcode
; *
; * Description for a 64 x 64 CUDA array of floats:
; * \code
;    CUDA_ARRAY3D_DESCRIPTOR desc;
;    desc.Format = CU_AD_FORMAT_FLOAT;
;    desc.NumChannels = 1;
;    desc.Width = 64;
;    desc.Height = 64;
;    desc.Depth = 0;
; * \endcode
; *
; * Description for a \p width x \p height x \p depth CUDA array of 64-bit,
; * 4x16-bit float16's:
; * \code
;    CUDA_ARRAY3D_DESCRIPTOR desc;
;    desc.FormatFlags = CU_AD_FORMAT_HALF;
;    desc.NumChannels = 4;
;    desc.Width = width;
;    desc.Height = height;
;    desc.Depth = depth;
; * \endcode
; *
; * \param pHandle        - Returned array
; * \param pAllocateArray - 3D array descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa ::cuArray3DGetDescriptor, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaMalloc3DArray
; */
;API
cuArray3DCreate PROTO pHandle:XWORD ,pAllocateArray:XWORD 
;/**
; * \brief Get a 3D CUDA array descriptor
; *
; * Returns in \p *pArrayDescriptor a descriptor containing information on the
; * format and dimensions of the CUDA array \p hArray. It is useful for
; * subroutines that have been passed a CUDA array, but need to know the CUDA
; * array parameters for validation or other purposes.
; *
; * This function may be called on 1D and 2D arrays, in which case the \p Height
; * and/or \p Depth members of the descriptor struct will be set to 0.
; *
; * \param pArrayDescriptor - Returned 3D array descriptor
; * \param hArray           - 3D array to get descriptor of
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_CONTEXT_IS_DESTROYED
; * \notefnerr
; *
; * \sa ::cuArray3DCreate, ::cuArrayCreate,
; * ::cuArrayDestroy, ::cuArrayGetDescriptor, ::cuMemAlloc, ::cuMemAllocHost,
; * ::cuMemAllocPitch, ::cuMemcpy2D, ::cuMemcpy2DAsync, ::cuMemcpy2DUnaligned,
; * ::cuMemcpy3D, ::cuMemcpy3DAsync, ::cuMemcpyAtoA, ::cuMemcpyAtoD,
; * ::cuMemcpyAtoH, ::cuMemcpyAtoHAsync, ::cuMemcpyDtoA, ::cuMemcpyDtoD, ::cuMemcpyDtoDAsync,
; * ::cuMemcpyDtoH, ::cuMemcpyDtoHAsync, ::cuMemcpyHtoA, ::cuMemcpyHtoAAsync,
; * ::cuMemcpyHtoD, ::cuMemcpyHtoDAsync, ::cuMemFree, ::cuMemFreeHost,
; * ::cuMemGetAddressRange, ::cuMemGetInfo, ::cuMemHostAlloc,
; * ::cuMemHostGetDevicePointer, ::cuMemsetD2D8, ::cuMemsetD2D16,
; * ::cuMemsetD2D32, ::cuMemsetD8, ::cuMemsetD16, ::cuMemsetD32,
; * ::cudaArrayGetInfo
; */
;API
cuArray3DGetDescriptor PROTO pArrayDescriptor:XWORD ,hArray:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
IF  __CUDA_API_VERSION GE 5000
;/**
; * \brief Creates a CUDA mipmapped array
; *
; * Creates a CUDA mipmapped array according to the ::CUDA_ARRAY3D_DESCRIPTOR structure
; * \p pMipmappedArrayDesc and returns a handle to the new CUDA mipmapped array in \p *pHandle.
; * \p numMipmapLevels specifies the number of mipmap levels to be allocated. This value is
; * clamped to the range [1, 1 + floor(log2(max(width, height, depth)))].
; *
; * The ::CUDA_ARRAY3D_DESCRIPTOR is defined as:
; *
; * \code
;    typedef struct {
;        unsigned int Width;
;        unsigned int Height;
;        unsigned int Depth;
;        CUarray_format Format;
;        unsigned int NumChannels;
;        unsigned int Flags;
;    } CUDA_ARRAY3D_DESCRIPTOR;
; * \endcode
; * where:
; *
; * - \p Width, \p Height, and \p Depth are the width, height, and depth of the
; * CUDA array (in elements); the following types of CUDA arrays can be allocated:
; *     - A 1D mipmapped array is allocated if \p Height and \p Depth extents are both zero.
; *     - A 2D mipmapped array is allocated if only \p Depth extent is zero.
; *     - A 3D mipmapped array is allocated if all three extents are non-zero.
; *     - A 1D layered CUDA mipmapped array is allocated if only \p Height is zero and the
; *       ::CUDA_ARRAY3D_LAYERED flag is set. Each layer is a 1D array. The number
; *       of layers is determined by the depth extent.
; *     - A 2D layered CUDA mipmapped array is allocated if all three extents are non-zero and
; *       the ::CUDA_ARRAY3D_LAYERED flag is set. Each layer is a 2D array. The number
; *       of layers is determined by the depth extent.
; *     - A cubemap CUDA mipmapped array is allocated if all three extents are non-zero and the
; *       ::CUDA_ARRAY3D_CUBEMAP flag is set. \p Width must be equal to \p Height, and
; *       \p Depth must be six. A cubemap is a special type of 2D layered CUDA array,
; *       where the six layers represent the six faces of a cube. The order of the six
; *       layers in memory is the same as that listed in ::CUarray_cubemap_face.
; *     - A cubemap layered CUDA mipmapped array is allocated if all three extents are non-zero,
; *       and both, ::CUDA_ARRAY3D_CUBEMAP and ::CUDA_ARRAY3D_LAYERED flags are set.
; *       \p Width must be equal to \p Height, and \p Depth must be a multiple of six.
; *       A cubemap layered CUDA array is a special type of 2D layered CUDA array that
; *       consists of a collection of cubemaps. The first six layers represent the first
; *       cubemap, the next six layers form the second cubemap, and so on.
; *
; * - ::Format specifies the format of the elements; ::CUarray_format is
; * defined as:
; * \code
;    typedef enum CUarray_format_enum {
;        CU_AD_FORMAT_UNSIGNED_INT8 = 0x01,
;        CU_AD_FORMAT_UNSIGNED_INT16 = 0x02,
;        CU_AD_FORMAT_UNSIGNED_INT32 = 0x03,
;        CU_AD_FORMAT_SIGNED_INT8 = 0x08,
;        CU_AD_FORMAT_SIGNED_INT16 = 0x09,
;        CU_AD_FORMAT_SIGNED_INT32 = 0x0a,
;        CU_AD_FORMAT_HALF = 0x10,
;        CU_AD_FORMAT_FLOAT = 0x20
;    } CUarray_format;
; *  \endcode
; *
; * - \p NumChannels specifies the number of packed components per CUDA array
; * element; it may be 1, 2, or 4;
; *
; * - ::Flags may be set to
; *   - ::CUDA_ARRAY3D_LAYERED to enable creation of layered CUDA mipmapped arrays. If this flag is set,
; *     \p Depth specifies the number of layers, not the depth of a 3D array.
; *   - ::CUDA_ARRAY3D_SURFACE_LDST to enable surface references to be bound to individual mipmap levels of
; *     the CUDA mipmapped array. If this flag is not set, ::cuSurfRefSetArray will fail when attempting to
; *     bind a mipmap level of the CUDA mipmapped array to a surface reference.
;  *   - ::CUDA_ARRAY3D_CUBEMAP to enable creation of mipmapped cubemaps. If this flag is set, \p Width must be
; *     equal to \p Height, and \p Depth must be six. If the ::CUDA_ARRAY3D_LAYERED flag is also set,
; *     then \p Depth must be a multiple of six.
; *   - ::CUDA_ARRAY3D_TEXTURE_GATHER to indicate that the CUDA mipmapped array will be used for texture gather.
; *     Texture gather can only be performed on 2D CUDA mipmapped arrays.
; *
; * \p Width, \p Height and \p Depth must meet certain size requirements as listed in the following table.
; * All values are specified in elements. Note that for brevity's sake, the full name of the device attribute
; * is not specified. For ex., TEXTURE1D_MIPMAPPED_WIDTH refers to the device attribute
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH.
; *
; * <table>
; * <tr><td><b>CUDA array type</b></td>
; * <td><b>Valid extents that must always be met<br>{(width range in elements), (height range),
; * (depth range)}</b></td>
; * <td><b>Valid extents with CUDA_ARRAY3D_SURFACE_LDST set<br>
; * {(width range in elements), (height range), (depth range)}</b></td></tr>
; * <tr><td>1D</td>
; * <td><small>{ (1,TEXTURE1D_MIPMAPPED_WIDTH), 0, 0 }</small></td>
; * <td><small>{ (1,SURFACE1D_WIDTH), 0, 0 }</small></td></tr>
; * <tr><td>2D</td>
; * <td><small>{ (1,TEXTURE2D_MIPMAPPED_WIDTH), (1,TEXTURE2D_MIPMAPPED_HEIGHT), 0 }</small></td>
; * <td><small>{ (1,SURFACE2D_WIDTH), (1,SURFACE2D_HEIGHT), 0 }</small></td></tr>
; * <tr><td>3D</td>
; * <td><small>{ (1,TEXTURE3D_WIDTH), (1,TEXTURE3D_HEIGHT), (1,TEXTURE3D_DEPTH) }
; * <br>OR<br>{ (1,TEXTURE3D_WIDTH_ALTERNATE), (1,TEXTURE3D_HEIGHT_ALTERNATE),
; * (1,TEXTURE3D_DEPTH_ALTERNATE) }</small></td>
; * <td><small>{ (1,SURFACE3D_WIDTH), (1,SURFACE3D_HEIGHT),
; * (1,SURFACE3D_DEPTH) }</small></td></tr>
; * <tr><td>1D Layered</td>
; * <td><small>{ (1,TEXTURE1D_LAYERED_WIDTH), 0,
; * (1,TEXTURE1D_LAYERED_LAYERS) }</small></td>
; * <td><small>{ (1,SURFACE1D_LAYERED_WIDTH), 0,
; * (1,SURFACE1D_LAYERED_LAYERS) }</small></td></tr>
; * <tr><td>2D Layered</td>
; * <td><small>{ (1,TEXTURE2D_LAYERED_WIDTH), (1,TEXTURE2D_LAYERED_HEIGHT),
; * (1,TEXTURE2D_LAYERED_LAYERS) }</small></td>
; * <td><small>{ (1,SURFACE2D_LAYERED_WIDTH), (1,SURFACE2D_LAYERED_HEIGHT),
; * (1,SURFACE2D_LAYERED_LAYERS) }</small></td></tr>
; * <tr><td>Cubemap</td>
; * <td><small>{ (1,TEXTURECUBEMAP_WIDTH), (1,TEXTURECUBEMAP_WIDTH), 6 }</small></td>
; * <td><small>{ (1,SURFACECUBEMAP_WIDTH),
; * (1,SURFACECUBEMAP_WIDTH), 6 }</small></td></tr>
; * <tr><td>Cubemap Layered</td>
; * <td><small>{ (1,TEXTURECUBEMAP_LAYERED_WIDTH), (1,TEXTURECUBEMAP_LAYERED_WIDTH),
; * (1,TEXTURECUBEMAP_LAYERED_LAYERS) }</small></td>
; * <td><small>{ (1,SURFACECUBEMAP_LAYERED_WIDTH), (1,SURFACECUBEMAP_LAYERED_WIDTH),
; * (1,SURFACECUBEMAP_LAYERED_LAYERS) }</small></td></tr>
; * </table>
; *
; *
; * \param pHandle             - Returned mipmapped array
; * \param pMipmappedArrayDesc - mipmapped array descriptor
; * \param numMipmapLevels     - Number of mipmap levels
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa
; * ::cuMipmappedArrayDestroy,
; * ::cuMipmappedArrayGetLevel,
; * ::cuArrayCreate,
; * ::cudaMallocMipmappedArray
; */
;API
cuMipmappedArrayCreate PROTO pHandle:XWORD ,pMipmappedArrayDesc:XWORD ,numMipmapLevels:DWORD 
;/**
; * \brief Gets a mipmap level of a CUDA mipmapped array
; *
; * Returns in \p *pLevelArray a CUDA array that represents a single mipmap level
; * of the CUDA mipmapped array \p hMipmappedArray.
; *
; * If \p level is greater than the maximum number of levels in this mipmapped array,
; * ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; * \param pLevelArray     - Returned mipmap level CUDA array
; * \param hMipmappedArray - CUDA mipmapped array
; * \param level           - Mipmap level
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa
; * ::cuMipmappedArrayCreate,
; * ::cuMipmappedArrayDestroy,
; * ::cuArrayCreate,
; * ::cudaGetMipmappedArrayLevel
; */
;API
cuMipmappedArrayGetLevel PROTO pLevelArray:XWORD ,hMipmappedArray:XWORD ,level:DWORD 
;/**
; * \brief Destroys a CUDA mipmapped array
; *
; * Destroys the CUDA mipmapped array \p hMipmappedArray.
; *
; * \param hMipmappedArray - Mipmapped array to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_ARRAY_IS_MAPPED,
; * ::CUDA_ERROR_CONTEXT_IS_DESTROYED
; * \notefnerr
; *
; * \sa
; * ::cuMipmappedArrayCreate,
; * ::cuMipmappedArrayGetLevel,
; * ::cuArrayCreate,
; * ::cudaFreeMipmappedArray
; */
;API
cuMipmappedArrayDestroy PROTO hMipmappedArray:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 5000 */ 
;/**
; * \defgroup CUDA_UNIFIED Unified Addressing
; *
; * ___MANBRIEF___ unified addressing functions of the low-level CUDA driver
; * API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the unified addressing functions of the
; * low-level CUDA driver application programming interface.
; *
; * @{
; *
; * \section CUDA_UNIFIED_overview Overview
; *
; * CUDA devices can share a unified address space with the host.
; * For these devices there is no distinction between a device
; * pointer and a host pointer -- the same pointer value may be
; * used to access memory from the host program and from a kernel
; * running on the device (with exceptions enumerated below).
; *
; * \section CUDA_UNIFIED_support Supported Platforms
; *
; * Whether or not a device supports unified addressing may be
; * queried by calling ::cuDeviceGetAttribute() with the device
; * attribute ::CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING.
; *
; * Unified addressing is automatically enabled in 64-bit processes
; *
; * \section CUDA_UNIFIED_lookup Looking Up Information from Pointer Values
; *
; * It is possible to look up information about the memory which backs a
; * pointer value.  For instance, one may want to know if a pointer points
; * to host or device memory.  As another example, in the case of device
; * memory, one may want to know on which CUDA device the memory
; * resides.  These properties may be queried using the function
; * ::cuPointerGetAttribute()
; *
; * Since pointers are unique, it is not necessary to specify information
; * about the pointers specified to the various copy functions in the
; * CUDA API.  The function ::cuMemcpy() may be used to perform a copy
; * between two pointers, ignoring whether they point to host or device
; * memory (making ::cuMemcpyHtoD(), ::cuMemcpyDtoD(), and ::cuMemcpyDtoH()
; * unnecessary for devices supporting unified addressing).  For
; * multidimensional copies, the memory type ::CU_MEMORYTYPE_UNIFIED may be
; * used to specify that the CUDA driver should infer the location of the
; * pointer from its value.
; *
; * \section CUDA_UNIFIED_automaphost Automatic Mapping of Host Allocated Host Memory
; *
; * All host memory allocated in all contexts using ::cuMemAllocHost() and
; * ::cuMemHostAlloc() is always directly accessible from all contexts on
; * all devices that support unified addressing.  This is the case regardless
; * of whether or not the flags ::CU_MEMHOSTALLOC_PORTABLE and
; * ::CU_MEMHOSTALLOC_DEVICEMAP are specified.
; *
; * The pointer value through which allocated host memory may be accessed
; * in kernels on all devices that support unified addressing is the same
; * as the pointer value through which that memory is accessed on the host,
; * so it is not necessary to call ::cuMemHostGetDevicePointer() to get the device
; * pointer for these allocations.
; *
; * Note that this is not the case for memory allocated using the flag
; * ::CU_MEMHOSTALLOC_WRITECOMBINED, as discussed below.
; *
; * \section CUDA_UNIFIED_autopeerregister Automatic Registration of Peer Memory
; *
; * Upon enabling direct access from a context that supports unified addressing
; * to another peer context that supports unified addressing using
; * ::cuCtxEnablePeerAccess() all memory allocated in the peer context using
; * ::cuMemAlloc() and ::cuMemAllocPitch() will immediately be accessible
; * by the current context.  The device pointer value through
; * which any peer memory may be accessed in the current context
; * is the same pointer value through which that memory may be
; * accessed in the peer context.
; *
; * \section CUDA_UNIFIED_exceptions Exceptions, Disjoint Addressing
; *
; * Not all memory may be accessed on devices through the same pointer
; * value through which they are accessed on the host.  These exceptions
; * are host memory registered using ::cuMemHostRegister() and host memory
; * allocated using the flag ::CU_MEMHOSTALLOC_WRITECOMBINED.  For these
; * exceptions, there exists a distinct host and device address for the
; * memory.  The device address is guaranteed to not overlap any valid host
; * pointer range and is guaranteed to have the same value across all
; * contexts that support unified addressing.
; *
; * This device address may be queried using ::cuMemHostGetDevicePointer()
; * when a context using unified addressing is current.  Either the host
; * or the unified device pointer value may be used to refer to this memory
; * through ::cuMemcpy() and similar functions using the
; * ::CU_MEMORYTYPE_UNIFIED memory type.
; *
; */
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Returns information about a pointer
; *
; * The supported attributes are:
; *
; * - ::CU_POINTER_ATTRIBUTE_CONTEXT:
; *
; *      Returns in \p *data the ::CUcontext in which \p ptr was allocated or
; *      registered.
; *      The type of \p data must be ::CUcontext *.
; *
; *      If \p ptr was not allocated by, mapped by, or registered with
; *      a ::CUcontext which uses unified virtual addressing then
; *      ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; * - ::CU_POINTER_ATTRIBUTE_MEMORY_TYPE:
; *
; *      Returns in \p *data the physical memory type of the memory that
; *      \p ptr addresses as a ::CUmemorytype enumerated value.
; *      The type of \p data must be unsigned int.
; *
; *      If \p ptr addresses device memory then \p *data is set to
; *      ::CU_MEMORYTYPE_DEVICE.  The particular ::CUdevice on which the
; *      memory resides is the ::CUdevice of the ::CUcontext returned by the
; *      ::CU_POINTER_ATTRIBUTE_CONTEXT attribute of \p ptr.
; *
; *      If \p ptr addresses host memory then \p *data is set to
; *      ::CU_MEMORYTYPE_HOST.
; *
; *      If \p ptr was not allocated by, mapped by, or registered with
; *      a ::CUcontext which uses unified virtual addressing then
; *      ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; *      If the current ::CUcontext does not support unified virtual
; *      addressing then ::CUDA_ERROR_INVALID_CONTEXT is returned.
; *
; * - ::CU_POINTER_ATTRIBUTE_DEVICE_POINTER:
; *
; *      Returns in \p *data the device pointer value through which
; *      \p ptr may be accessed by kernels running in the current
; *      ::CUcontext.
; *      The type of \p data must be CUdeviceptr *.
; *
; *      If there exists no device pointer value through which
; *      kernels running in the current ::CUcontext may access
; *      \p ptr then ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; *      If there is no current ::CUcontext then
; *      ::CUDA_ERROR_INVALID_CONTEXT is returned.
; *
; *      Except in the exceptional disjoint addressing cases discussed
; *      below, the value returned in \p *data will equal the input
; *      value \p ptr.
; *
; * - ::CU_POINTER_ATTRIBUTE_HOST_POINTER:
; *
; *      Returns in \p *data the host pointer value through which
; *      \p ptr may be accessed by by the host program.
; *      The type of \p data must be void **.
; *      If there exists no host pointer value through which
; *      the host program may directly access \p ptr then
; *      ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; *      Except in the exceptional disjoint addressing cases discussed
; *      below, the value returned in \p *data will equal the input
; *      value \p ptr.
; *
; * - ::CU_POINTER_ATTRIBUTE_P2P_TOKENS:
; *
; *      Returns in \p *data two tokens for use with the nv-p2p.h Linux
; *      kernel interface. \p data must be a struct of type
; *      CUDA_POINTER_ATTRIBUTE_P2P_TOKENS.
; *
; *      \p ptr must be a pointer to memory obtained from :cuMemAlloc().
; *      Note that p2pToken and vaSpaceToken are only valid for the
; *      lifetime of the source allocation. A subsequent allocation at
; *      the same address may return completely different tokens.
; *      Querying this attribute has a side effect of setting the attribute
; *      ::CU_POINTER_ATTRIBUTE_SYNC_MEMOPS for the region of memory that
; *      \p ptr points to.
; *
; * - ::CU_POINTER_ATTRIBUTE_SYNC_MEMOPS:
; *
; *      A boolean attribute which when set, ensures that synchronous memory operations
; *      initiated on the region of memory that \p ptr points to will always synchronize.
; *      See further documentation in the section titled "API synchronization behavior"
; *      to learn more about cases when synchronous memory operations can
; *      exhibit asynchronous behavior.
; *
; * - ::CU_POINTER_ATTRIBUTE_BUFFER_ID:
; *
; *      Returns in \p *data a buffer ID which is guaranteed to be unique within the process.
; *      \p data must point to an __int64.
; *
; *      \p ptr must be a pointer to memory obtained from a CUDA memory allocation API.
; *      Every memory allocation from any of the CUDA memory allocation APIs will
; *      have a unique ID over a process lifetime. Subsequent allocations do not reuse IDs
; *      from previous freed allocations. IDs are only unique within a single process.
; *
; *
; * - ::CU_POINTER_ATTRIBUTE_IS_MANAGED:
; *
; *      Returns in \p *data a boolean that indicates whether the pointer points to
; *      managed memory or not.
; *
; * - ::CU_POINTER_ATTRIBUTE_DEVICE_ORDINAL:
; *
; *      Returns in \p *data an integer representing a device ordinal of a device against
; *      which the memory was allocated or registered.
; *
; * \par
; *
; * Note that for most allocations in the unified virtual address space
; * the host and device pointer for accessing the allocation will be the
; * same.  The exceptions to this are
; *  - user memory registered using ::cuMemHostRegister
; *  - host memory allocated using ::cuMemHostAlloc with the
; *    ::CU_MEMHOSTALLOC_WRITECOMBINED flag
; * For these types of allocation there will exist separate, disjoint host
; * and device addresses for accessing the allocation.  In particular
; *  - The host address will correspond to an invalid unmapped device address
; *    (which will result in an exception if accessed from the device)
; *  - The device address will correspond to an invalid unmapped host address
; *    (which will result in an exception if accessed from the host).
; * For these types of allocations, querying ::CU_POINTER_ATTRIBUTE_HOST_POINTER
; * and ::CU_POINTER_ATTRIBUTE_DEVICE_POINTER may be used to retrieve the host
; * and device addresses from either address.
; *
; * \param data      - Returned pointer attribute value
; * \param attribute - Pointer attribute to query
; * \param ptr       - Pointer
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuPointerSetAttribute,
; * ::cuMemAlloc,
; * ::cuMemFree,
; * ::cuMemAllocHost,
; * ::cuMemFreeHost,
; * ::cuMemHostAlloc,
; * ::cuMemHostRegister,
; * ::cuMemHostUnregister,
; * ::cudaPointerGetAttributes
; */
;API
cuPointerGetAttribute PROTO data:XWORD ,attribute:CUpointer_attribute ,aPtr:CUdeviceptr 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 8000
;/**
; * \brief Prefetches memory to the specified destination device
; *
; * Prefetches memory to the specified destination device.  \p devPtr is the
; * base device pointer of the memory to be prefetched and \p dstDevice is the
; * destination device. \p count specifies the number of bytes to copy. \p hStream
; * is the stream in which the operation is enqueued. The memory range must refer
; * to managed memory allocated via ::cuMemAllocManaged or declared via __managed__ variables.
; *
; * Passing in CU_DEVICE_CPU for \p dstDevice will prefetch the data to host memory. If
; * \p dstDevice is a GPU, then the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS
; * must be non-zero. Additionally, \p hStream must be associated with a device that has a
; * non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS.
; *
; * The start address and end address of the memory range will be rounded down and rounded up
; * respectively to be aligned to CPU page size before the prefetch operation is enqueued
; * in the stream.
; *
; * If no physical memory has been allocated for this region, then this memory region
; * will be populated and mapped on the destination device. If there's insufficient
; * memory to prefetch the desired region, the Unified Memory driver may evict pages from other
; * ::cuMemAllocManaged allocations to host memory in order to make room. Device memory
; * allocated using ::cuMemAlloc or ::cuArrayCreate will not be evicted.
; *
; * By default, any mappings to the previous location of the migrated pages are removed and
; * mappings for the new location are only setup on \p dstDevice. The exact behavior however
; * also depends on the settings applied to this memory range via ::cuMemAdvise as described
; * below:
; *
; * If ::CU_MEM_ADVISE_SET_READ_MOSTLY was set on any subset of this memory range,
; * then that subset will create a read-only copy of the pages on \p dstDevice.
; *
; * If ::CU_MEM_ADVISE_SET_PREFERRED_LOCATION was called on any subset of this memory
; * range, then the pages will be migrated to \p dstDevice even if \p dstDevice is not the
; * preferred location of any pages in the memory range.
; *
; * If ::CU_MEM_ADVISE_SET_ACCESSED_BY was called on any subset of this memory range,
; * then mappings to those pages from all the appropriate processors are updated to
; * refer to the new location if establishing such a mapping is possible. Otherwise,
; * those mappings are cleared.
; *
; * Note that this API is not required for functionality and only serves to improve performance
; * by allowing the application to migrate data to a suitable location before it is accessed.
; * Memory accesses to this range are always coherent and are allowed even when the data is
; * actively being migrated.
; *
; * Note that this function is asynchronous with respect to the host and all work
; * on other devices.
; *
; * \param devPtr    - Pointer to be prefetched
; * \param count     - Size in bytes
; * \param dstDevice - Destination device to prefetch to
; * \param hStream    - Stream to enqueue prefetch operation
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuMemcpy, ::cuMemcpyPeer, ::cuMemcpyAsync,
; * ::cuMemcpy3DPeerAsync, ::cuMemAdvise,
; * ::cudaMemPrefetchAsync
; */
;API
cuMemPrefetchAsync PROTO devPtr:CUdeviceptr ,count:DWORD ,dstDevice:DWORD ,hStream:XWORD 
;/**
; * \brief Advise about the usage of a given memory range
; *
; * Advise the Unified Memory subsystem about the usage pattern for the memory range
; * starting at \p devPtr with a size of \p count bytes. The start address and end address of the memory
; * range will be rounded down and rounded up respectively to be aligned to CPU page size before the
; * advice is applied. The memory range must refer to managed memory allocated via ::cuMemAllocManaged
; * or declared via __managed__ variables. The memory range could also refer to system-allocated pageable
; * memory provided it represents a valid, host-accessible region of memory and all additional constraints
; * imposed by \p advice as outlined below are also satisfied. Specifying an invalid system-allocated pageable
; * memory range results in an error being returned.
; *
; * The \p advice parameter can take the following values:
; * - ::CU_MEM_ADVISE_SET_READ_MOSTLY: This implies that the data is mostly going to be read
; * from and only occasionally written to. Any read accesses from any processor to this region will create a
; * read-only copy of at least the accessed pages in that processor's memory. Additionally, if ::cuMemPrefetchAsync
; * is called on this region, it will create a read-only copy of the data on the destination processor.
; * If any processor writes to this region, all copies of the corresponding page will be invalidated
; * except for the one where the write occurred. The \p device argument is ignored for this advice.
; * Note that for a page to be read-duplicated, the accessing processor must either be the CPU or a GPU
; * that has a non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS.
; * Also, if a context is created on a device that does not have the device attribute
; * ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS set, then read-duplication will not occur until
; * all such contexts are destroyed.
; * If the memory region refers to valid system-allocated pageable memory, then the accessing device must
; * have a non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS for a read-only
; * copy to be created on that device. Note however that if the accessing device also has a non-zero value for the
; * device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES, then setting this advice
; * will not create a read-only copy when that device accesses this memory region.
; *
; * - ::CU_MEM_ADVISE_UNSET_READ_MOSTLY:  Undoes the effect of ::CU_MEM_ADVISE_SET_READ_MOSTLY and also prevents the
; * Unified Memory driver from attempting heuristic read-duplication on the memory range. Any read-duplicated
; * copies of the data will be collapsed into a single copy. The location for the collapsed
; * copy will be the preferred location if the page has a preferred location and one of the read-duplicated
; * copies was resident at that location. Otherwise, the location chosen is arbitrary.
; *
; * - ::CU_MEM_ADVISE_SET_PREFERRED_LOCATION: This advice sets the preferred location for the
; * data to be the memory belonging to \p device. Passing in CU_DEVICE_CPU for \p device sets the
; * preferred location as host memory. If \p device is a GPU, then it must have a non-zero value for the
; * device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS. Setting the preferred location
; * does not cause data to migrate to that location immediately. Instead, it guides the migration policy
; * when a fault occurs on that memory region. If the data is already in its preferred location and the
; * faulting processor can establish a mapping without requiring the data to be migrated, then
; * data migration will be avoided. On the other hand, if the data is not in its preferred location
; * or if a direct mapping cannot be established, then it will be migrated to the processor accessing
; * it. It is important to note that setting the preferred location does not prevent data prefetching
; * done using ::cuMemPrefetchAsync.
; * Having a preferred location can override the page thrash detection and resolution logic in the Unified
; * Memory driver. Normally, if a page is detected to be constantly thrashing between for example host and device
; * memory, the page may eventually be pinned to host memory by the Unified Memory driver. But
; * if the preferred location is set as device memory, then the page will continue to thrash indefinitely.
; * If ::CU_MEM_ADVISE_SET_READ_MOSTLY is also set on this memory region or any subset of it, then the
; * policies associated with that advice will override the policies of this advice, unless read accesses from
; * \p device will not result in a read-only copy being created on that device as outlined in description for
; * the advice ::CU_MEM_ADVISE_SET_READ_MOSTLY.
; * If the memory region refers to valid system-allocated pageable memory, then \p device must have a non-zero
; * value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS. Additionally, if \p device has
; * a non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES,
; * then this call has no effect. Note however that this behavior may change in the future.
; *
; * - ::CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION: Undoes the effect of ::CU_MEM_ADVISE_SET_PREFERRED_LOCATION
; * and changes the preferred location to none.
; *
; * - ::CU_MEM_ADVISE_SET_ACCESSED_BY: This advice implies that the data will be accessed by \p device.
; * Passing in ::CU_DEVICE_CPU for \p device will set the advice for the CPU. If \p device is a GPU, then
; * the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS must be non-zero.
; * This advice does not cause data migration and has no impact on the location of the data per se. Instead,
; * it causes the data to always be mapped in the specified processor's page tables, as long as the
; * location of the data permits a mapping to be established. If the data gets migrated for any reason,
; * the mappings are updated accordingly.
; * This advice is recommended in scenarios where data locality is not important, but avoiding faults is.
; * Consider for example a system containing multiple GPUs with peer-to-peer access enabled, where the
; * data located on one GPU is occasionally accessed by peer GPUs. In such scenarios, migrating data
; * over to the other GPUs is not as important because the accesses are infrequent and the overhead of
; * migration may be too high. But preventing faults can still help improve performance, and so having
; * a mapping set up in advance is useful. Note that on CPU access of this data, the data may be migrated
; * to host memory because the CPU typically cannot access device memory directly. Any GPU that had the
; * ::CU_MEM_ADVISE_SET_ACCESSED_BY flag set for this data will now have its mapping updated to point to the
; * page in host memory.
; * If ::CU_MEM_ADVISE_SET_READ_MOSTLY is also set on this memory region or any subset of it, then the
; * policies associated with that advice will override the policies of this advice. Additionally, if the
; * preferred location of this memory region or any subset of it is also \p device, then the policies
; * associated with ::CU_MEM_ADVISE_SET_PREFERRED_LOCATION will override the policies of this advice.
; * If the memory region refers to valid system-allocated pageable memory, then \p device must have a non-zero
; * value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS. Additionally, if \p device has
; * a non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES,
; * then this call has no effect.
; *
; * - ::CU_MEM_ADVISE_UNSET_ACCESSED_BY: Undoes the effect of ::CU_MEM_ADVISE_SET_ACCESSED_BY. Any mappings to
; * the data from \p device may be removed at any time causing accesses to result in non-fatal page faults.
; * If the memory region refers to valid system-allocated pageable memory, then \p device must have a non-zero
; * value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS. Additionally, if \p device has
; * a non-zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES,
; * then this call has no effect.
; *
; * \param devPtr - Pointer to memory to set the advice for
; * \param count  - Size in bytes of the memory range
; * \param advice - Advice to be applied for the specified memory range
; * \param device - Device to apply the advice for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuMemcpy, ::cuMemcpyPeer, ::cuMemcpyAsync,
; * ::cuMemcpy3DPeerAsync, ::cuMemPrefetchAsync,
; * ::cudaMemAdvise
; */
;API
cuMemAdvise PROTO devPtr:CUdeviceptr ,count:DWORD ,advice:CUmem_advise ,device:DWORD 
;/**
; * \brief Query an attribute of a given memory range
; *
; * Query an attribute about the memory range starting at \p devPtr with a size of \p count bytes. The
; * memory range must refer to managed memory allocated via ::cuMemAllocManaged or declared via
; * __managed__ variables.
; *
; * The \p attribute parameter can take the following values:
; * - ::CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY: If this attribute is specified, \p data will be interpreted
; * as a 32-bit integer, and \p dataSize must be 4. The result returned will be 1 if all pages in the given
; * memory range have read-duplication enabled, or 0 otherwise.
; * - ::CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION: If this attribute is specified, \p data will be
; * interpreted as a 32-bit integer, and \p dataSize must be 4. The result returned will be a GPU device
; * id if all pages in the memory range have that GPU as their preferred location, or it will be CU_DEVICE_CPU
; * if all pages in the memory range have the CPU as their preferred location, or it will be CU_DEVICE_INVALID
; * if either all the pages don't have the same preferred location or some of the pages don't have a
; * preferred location at all. Note that the actual location of the pages in the memory range at the time of
; * the query may be different from the preferred location.
; * - ::CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY: If this attribute is specified, \p data will be interpreted
; * as an array of 32-bit integers, and \p dataSize must be a non-zero multiple of 4. The result returned
; * will be a list of device ids that had ::CU_MEM_ADVISE_SET_ACCESSED_BY set for that entire memory range.
; * If any device does not have that advice set for the entire memory range, that device will not be included.
; * If \p data is larger than the number of devices that have that advice set for that memory range,
; * CU_DEVICE_INVALID will be returned in all the extra space provided. For ex., if \p dataSize is 12
; * (i.e. \p data has 3 elements) and only device 0 has the advice set, then the result returned will be
; * { 0, CU_DEVICE_INVALID, CU_DEVICE_INVALID }. If \p data is smaller than the number of devices that have
; * that advice set, then only as many devices will be returned as can fit in the array. There is no
; * guarantee on which specific devices will be returned, however.
; * - ::CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION: If this attribute is specified, \p data will be
; * interpreted as a 32-bit integer, and \p dataSize must be 4. The result returned will be the last location
; * to which all pages in the memory range were prefetched explicitly via ::cuMemPrefetchAsync. This will either be
; * a GPU id or CU_DEVICE_CPU depending on whether the last location for prefetch was a GPU or the CPU
; * respectively. If any page in the memory range was never explicitly prefetched or if all pages were not
; * prefetched to the same location, CU_DEVICE_INVALID will be returned. Note that this simply returns the
; * last location that the applicaton requested to prefetch the memory range to. It gives no indication as to
; * whether the prefetch operation to that location has completed or even begun.
; *
; * \param data      - A pointers to a memory location where the result
; *                    of each attribute query will be written to.
; * \param dataSize  - Array containing the size of data
; * \param attribute - The attribute to query
; * \param devPtr    - Start of the range to query
; * \param count     - Size of the range to query
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; * \note_async
; * \note_null_stream
; *
; * \sa ::cuMemRangeGetAttributes, ::cuMemPrefetchAsync,
; * ::cuMemAdvise,
; * ::cudaMemRangeGetAttribute
; */
;API
cuMemRangeGetAttribute PROTO data:XWORD ,dataSize:DWORD ,attribute:CUmem_range_attribute ,devPtr:CUdeviceptr ,count:DWORD 
;/**
; * \brief Query attributes of a given memory range.
; *
; * Query attributes of the memory range starting at \p devPtr with a size of \p count bytes. The
; * memory range must refer to managed memory allocated via ::cuMemAllocManaged or declared via
; * __managed__ variables. The \p attributes array will be interpreted to have \p numAttributes
; * entries. The \p dataSizes array will also be interpreted to have \p numAttributes entries.
; * The results of the query will be stored in \p data.
; *
; * The list of supported attributes are given below. Please refer to ::cuMemRangeGetAttribute for
; * attribute descriptions and restrictions.
; *
; * - ::CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY
; * - ::CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION
; * - ::CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY
; * - ::CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION
; *
; * \param data          - A two-dimensional array containing pointers to memory
; *                        locations where the result of each attribute query will be written to.
; * \param dataSizes     - Array containing the sizes of each result
; * \param attributes    - An array of attributes to query
; *                        (numAttributes and the number of attributes in this array should match)
; * \param numAttributes - Number of attributes to query
; * \param devPtr        - Start of the range to query
; * \param count         - Size of the range to query
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa ::cuMemRangeGetAttribute, ::cuMemAdvise
; * ::cuMemPrefetchAsync,
; * ::cudaMemRangeGetAttributes
; */
;API
cuMemRangeGetAttributes PROTO data:XWORD ,dataSizes:XWORD ,attributes:XWORD ,numAttributes:DWORD ,devPtr:CUdeviceptr ,count:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 8000 */ 
IF  __CUDA_API_VERSION GE 6000
;/**
; * \brief Set attributes on a previously allocated memory region
; *
; * The supported attributes are:
; *
; * - ::CU_POINTER_ATTRIBUTE_SYNC_MEMOPS:
; *
; *      A boolean attribute that can either be set (1) or unset (0). When set,
; *      the region of memory that \p ptr points to is guaranteed to always synchronize
; *      memory operations that are synchronous. If there are some previously initiated
; *      synchronous memory operations that are pending when this attribute is set, the
; *      function does not return until those memory operations are complete.
; *      See further documentation in the section titled "API synchronization behavior"
; *      to learn more about cases when synchronous memory operations can
; *      exhibit asynchronous behavior.
; *      \p value will be considered as a pointer to an unsigned integer to which this attribute is to be set.
; *
; * \param value     - Pointer to memory containing the value to be set
; * \param attribute - Pointer attribute to set
; * \param ptr       - Pointer to a memory region allocated using CUDA memory allocation APIs
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa ::cuPointerGetAttribute,
; * ::cuPointerGetAttributes,
; * ::cuMemAlloc,
; * ::cuMemFree,
; * ::cuMemAllocHost,
; * ::cuMemFreeHost,
; * ::cuMemHostAlloc,
; * ::cuMemHostRegister,
; * ::cuMemHostUnregister
; */
;API
cuPointerSetAttribute PROTO value:XWORD ,attribute:CUpointer_attribute ,aPtr:CUdeviceptr 
ENDIF ;/* __CUDA_API_VERSION >= 6000 */ 
IF  __CUDA_API_VERSION GE 7000
;/**
; * \brief Returns information about a pointer.
; *
; * The supported attributes are (refer to ::cuPointerGetAttribute for attribute descriptions and restrictions):
; *
; * - ::CU_POINTER_ATTRIBUTE_CONTEXT
; * - ::CU_POINTER_ATTRIBUTE_MEMORY_TYPE
; * - ::CU_POINTER_ATTRIBUTE_DEVICE_POINTER
; * - ::CU_POINTER_ATTRIBUTE_HOST_POINTER
; * - ::CU_POINTER_ATTRIBUTE_SYNC_MEMOPS
; * - ::CU_POINTER_ATTRIBUTE_BUFFER_ID
; * - ::CU_POINTER_ATTRIBUTE_IS_MANAGED
; * - ::CU_POINTER_ATTRIBUTE_DEVICE_ORDINAL
; *
; * \param numAttributes - Number of attributes to query
; * \param attributes    - An array of attributes to query
; *                      (numAttributes and the number of attributes in this array should match)
; * \param data          - A two-dimensional array containing pointers to memory
; *                      locations where the result of each attribute query will be written to.
; * \param ptr           - Pointer to query
; *
; * Unlike ::cuPointerGetAttribute, this function will not return an error when the \p ptr
; * encountered is not a valid CUDA pointer. Instead, the attributes are assigned default NULL values
; * and CUDA_SUCCESS is returned.
; *
; * If \p ptr was not allocated by, mapped by, or registered with a ::CUcontext which uses UVA
; * (Unified Virtual Addressing), ::CUDA_ERROR_INVALID_CONTEXT is returned.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuPointerGetAttribute,
; * ::cuPointerSetAttribute,
; * ::cudaPointerGetAttributes
; */
;API
cuPointerGetAttributes PROTO numAttributes:DWORD ,attributes:XWORD ,data:XWORD ,aPtr:CUdeviceptr 
ENDIF ;/* __CUDA_API_VERSION >= 7000 */ 
;/**
; * \defgroup CUDA_STREAM Stream Management
; *
; * ___MANBRIEF___ stream management functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the stream management functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Create a stream
; *
; * Creates a stream and returns a handle in \p phStream.  The \p Flags argument
; * determines behaviors of the stream.  Valid values for \p Flags are:
; * - ::CU_STREAM_DEFAULT: Default stream creation flag.
; * - ::CU_STREAM_NON_BLOCKING: Specifies that work running in the created
; *   stream may run concurrently with work in stream 0 (the NULL stream), and that
; *   the created stream should perform no implicit synchronization with stream 0.
; *
; * \param phStream - Returned newly created stream
; * \param Flags    - Parameters for stream creation
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuStreamDestroy,
; * ::cuStreamCreateWithPriority,
; * ::cuStreamGetPriority,
; * ::cuStreamGetFlags,
; * ::cuStreamWaitEvent,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamAddCallback,
; * ::cudaStreamCreate,
; * ::cudaStreamCreateWithFlags
; */
;API
cuStreamCreate PROTO phStream:XWORD ,Flags:DWORD 
;/**
; * \brief Create a stream with the given priority
; *
; * Creates a stream with the specified priority and returns a handle in \p phStream.
; * This API alters the scheduler priority of work in the stream. Work in a higher
; * priority stream may preempt work already executing in a low priority stream.
; *
; * \p priority follows a convention where lower numbers represent higher priorities.
; * '0' represents default priority. The range of meaningful numerical priorities can
; * be queried using ::cuCtxGetStreamPriorityRange. If the specified priority is
; * outside the numerical range returned by ::cuCtxGetStreamPriorityRange,
; * it will automatically be clamped to the lowest or the highest number in the range.
; *
; * \param phStream    - Returned newly created stream
; * \param flags       - Flags for stream creation. See ::cuStreamCreate for a list of
; *                      valid flags
; * \param priority    - Stream priority. Lower numbers represent higher priorities.
; *                      See ::cuCtxGetStreamPriorityRange for more information about
; *                      meaningful stream priorities that can be passed.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \note Stream priorities are supported only on GPUs
; * with compute capability 3.5 or higher.
; *
; * \note In the current implementation, only compute kernels launched in
; * priority streams are affected by the stream's priority. Stream priorities have
; * no effect on host-to-device and device-to-host memory operations.
; *
; * \sa ::cuStreamDestroy,
; * ::cuStreamCreate,
; * ::cuStreamGetPriority,
; * ::cuCtxGetStreamPriorityRange,
; * ::cuStreamGetFlags,
; * ::cuStreamWaitEvent,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamAddCallback,
; * ::cudaStreamCreateWithPriority
; */
;API
cuStreamCreateWithPriority PROTO phStream:XWORD ,flags:DWORD ,priority:DWORD 
;/**
; * \brief Query the priority of a given stream
; *
; * Query the priority of a stream created using ::cuStreamCreate or ::cuStreamCreateWithPriority
; * and return the priority in \p priority. Note that if the stream was created with a
; * priority outside the numerical range returned by ::cuCtxGetStreamPriorityRange,
; * this function returns the clamped priority.
; * See ::cuStreamCreateWithPriority for details about priority clamping.
; *
; * \param hStream    - Handle to the stream to be queried
; * \param priority   - Pointer to a signed integer in which the stream's priority is returned
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuStreamDestroy,
; * ::cuStreamCreate,
; * ::cuStreamCreateWithPriority,
; * ::cuCtxGetStreamPriorityRange,
; * ::cuStreamGetFlags,
; * ::cudaStreamGetPriority
; */
;API
cuStreamGetPriority PROTO hStream:XWORD ,priority:XWORD 
;/**
; * \brief Query the flags of a given stream
; *
; * Query the flags of a stream created using ::cuStreamCreate or ::cuStreamCreateWithPriority
; * and return the flags in \p flags.
; *
; * \param hStream    - Handle to the stream to be queried
; * \param flags      - Pointer to an unsigned integer in which the stream's flags are returned
; *                     The value returned in \p flags is a logical 'OR' of all flags that
; *                     were used while creating this stream. See ::cuStreamCreate for the list
; *                     of valid flags
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa ::cuStreamDestroy,
; * ::cuStreamCreate,
; * ::cuStreamGetPriority,
; * ::cudaStreamGetFlags
; */
;API
cuStreamGetFlags PROTO hStream:XWORD ,flags:XWORD 
IF  __CUDA_API_VERSION GE 9020
;/**
; * \brief Query the context associated with a stream
; *
; * Returns the CUDA context that the stream is associated with.
; *
; * The stream handle \p hStream can refer to any of the following:
; * <ul>
; *   <li>a stream created via any of the CUDA driver APIs such as ::cuStreamCreate
; *   and ::cuStreamCreateWithPriority, or their runtime API equivalents such as
; *   ::cudaStreamCreate, ::cudaStreamCreateWithFlags and ::cudaStreamCreateWithPriority.
; *   The returned context is the context that was active in the calling thread when the
; *   stream was created. Passing an invalid handle will result in undefined behavior.</li>
; *   <li>any of the special streams such as the NULL stream, ::CU_STREAM_LEGACY and
; *   ::CU_STREAM_PER_THREAD. The runtime API equivalents of these are also accepted,
; *   which are NULL, ::cudaStreamLegacy and ::cudaStreamPerThread respectively.
; *   Specifying any of the special handles will return the context current to the
; *   calling thread. If no context is current to the calling thread,
; *   ::CUDA_ERROR_INVALID_CONTEXT is returned.</li>
; * </ul>
; *
; * \param hStream - Handle to the stream to be queried
; * \param pctx    - Returned context associated with the stream
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * \notefnerr
; *
; * \sa ::cuStreamDestroy,
; * ::cuStreamCreateWithPriority,
; * ::cuStreamGetPriority,
; * ::cuStreamGetFlags,
; * ::cuStreamWaitEvent,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamAddCallback,
; * ::cudaStreamCreate,
; * ::cudaStreamCreateWithFlags
; */
;API
cuStreamGetCtx PROTO hStream:XWORD ,pctx:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 9020 */ 
;/**
; * \brief Make a compute stream wait on an event
; *
; * Makes all future work submitted to \p hStream wait for all work captured in
; * \p hEvent.  See ::cuEventRecord() for details on what is captured by an event.
; * The synchronization will be performed efficiently on the device when applicable.
; * \p hEvent may be from a different context or device than \p hStream.
; *
; * \param hStream - Stream to wait
; * \param hEvent  - Event to wait on (may not be NULL)
; * \param Flags   - Parameters for the operation (must be 0)
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuEventRecord,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamAddCallback,
; * ::cuStreamDestroy,
; * ::cudaStreamWaitEvent
; */
;API
cuStreamWaitEvent PROTO hStream:XWORD ,hEvent:XWORD ,Flags:DWORD 
;/**
; * \brief Add a callback to a compute stream
; *
; * \note This function is slated for eventual deprecation and removal. If
; * you do not require the callback to execute in case of a device error,
; * consider using ::cuLaunchHostFunc. Additionally, this function is not
; * supported with ::cuStreamBeginCapture and ::cuStreamEndCapture, unlike
; * ::cuLaunchHostFunc.
; *
; * Adds a callback to be called on the host after all currently enqueued
; * items in the stream have completed.  For each
; * cuStreamAddCallback call, the callback will be executed exactly once.
; * The callback will block later work in the stream until it is finished.
; *
; * The callback may be passed ::CUDA_SUCCESS or an error code.  In the event
; * of a device error, all subsequently executed callbacks will receive an
; * appropriate ::CUresult.
; *
; * Callbacks must not make any CUDA API calls.  Attempting to use a CUDA API
; * will result in ::CUDA_ERROR_NOT_PERMITTED.  Callbacks must not perform any
; * synchronization that may depend on outstanding device work or other callbacks
; * that are not mandated to run earlier.  Callbacks without a mandated order
; * (in independent streams) execute in undefined order and may be serialized.
; *
; * For the purposes of Unified Memory, callback execution makes a number of
; * guarantees:
; * <ul>
; *   <li>The callback stream is considered idle for the duration of the
; *   callback.  Thus, for example, a callback may always use memory attached
; *   to the callback stream.</li>
; *   <li>The start of execution of a callback has the same effect as
; *   synchronizing an event recorded in the same stream immediately prior to
; *   the callback.  It thus synchronizes streams which have been "joined"
; *   prior to the callback.</li>
; *   <li>Adding device work to any stream does not have the effect of making
; *   the stream active until all preceding host functions and stream callbacks
; *   have executed.  Thus, for
; *   example, a callback might use global attached memory even if work has
; *   been added to another stream, if the work has been ordered behind the
; *   callback with an event.</li>
; *   <li>Completion of a callback does not cause a stream to become
; *   active except as described above.  The callback stream will remain idle
; *   if no device work follows the callback, and will remain idle across
; *   consecutive callbacks without device work in between.  Thus, for example,
; *   stream synchronization can be done by signaling from a callback at the
; *   end of the stream.</li>
; * </ul>
; *
; * \param hStream  - Stream to add callback to
; * \param callback - The function to call once preceding stream operations are complete
; * \param userData - User specified data to be passed to the callback function
; * \param flags    - Reserved for future use, must be 0
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamWaitEvent,
; * ::cuStreamDestroy,
; * ::cuMemAllocManaged,
; * ::cuStreamAttachMemAsync,
; * ::cuStreamLaunchHostFunc,
; * ::cudaStreamAddCallback
; */
;API
cuStreamAddCallback PROTO hStream:XWORD ,callback:XWORD ,userData:XWORD ,flags:DWORD 
IF  __CUDA_API_VERSION GE 10000
;/**
; * \brief Begins graph capture on a stream
; *
; * Begin graph capture on \p hStream. When a stream is in capture mode, all operations
; * pushed into the stream will not be executed, but will instead be captured into
; * a graph, which will be returned via ::cuStreamEndCapture. Capture may not be initiated
; * if \p stream is CU_STREAM_LEGACY. Capture must be ended on the same stream in which
; * it was initiated, and it may only be initiated if the stream is not already in capture
; * mode. The capture mode may be queried via ::cuStreamIsCapturing. A unique id
; * representing the capture sequence may be queried via ::cuStreamGetCaptureInfo.
; *
; * If \p mode is not ::CU_STREAM_CAPTURE_MODE_RELAXED, ::cuStreamEndCapture must be
; * called on this stream from the same thread.
; *
; * \param hStream - Stream in which to initiate capture
; * \param mode    - Controls the interaction of this capture sequence with other API
; *                  calls that are potentially unsafe. For more details see
; *                  ::cuThreadExchangeStreamCaptureMode.
; *
; * \note Kernels captured using this API must not use texture and surface references.
; *       Reading or writing through any texture or surface reference is undefined
; *       behavior. This restriction does not apply to texture and surface objects.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cuStreamCreate,
; * ::cuStreamIsCapturing,
; * ::cuStreamEndCapture,
; * ::cuThreadExchangeStreamCaptureMode
; */
;API
cuStreamBeginCapture PROTO hStream:XWORD ,Mode1:CUstreamCaptureMode 
ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
IF  __CUDA_API_VERSION GE 10010
;/**
; * \brief Swaps the stream capture interaction mode for a thread
; *
; * Sets the calling thread's stream capture interaction mode to the value contained
; * in \p *mode, and overwrites \p *mode with the previous mode for the thread. To
; * facilitate deterministic behavior across function or module boundaries, callers
; * are encouraged to use this API in a push-pop fashion: \code
;     CUstreamCaptureMode mode = desiredMode;
;     cuThreadExchangeStreamCaptureMode(&mode);
;     ...
;     cuThreadExchangeStreamCaptureMode(&mode); // restore previous mode
; * \endcode
; *
; * During stream capture (see ::cuStreamBeginCapture), some actions, such as a call
; * to ::cudaMalloc, may be unsafe. In the case of ::cudaMalloc, the operation is
; * not enqueued asynchronously to a stream, and is not observed by stream capture.
; * Therefore, if the sequence of operations captured via ::cuStreamBeginCapture
; * depended on the allocation being replayed whenever the graph is launched, the
; * captured graph would be invalid.
; *
; * Therefore, stream capture places restrictions on API calls that can be made within
; * or concurrently to a ::cuStreamBeginCapture-::cuStreamEndCapture sequence. This
; * behavior can be controlled via this API and flags to ::cuStreamBeginCapture.
; *
; * A thread's mode is one of the following:
; * - \p CU_STREAM_CAPTURE_MODE_GLOBAL: This is the default mode. If the local thread has
; *   an ongoing capture sequence that was not initiated with
; *   \p CU_STREAM_CAPTURE_MODE_RELAXED at \p cuStreamBeginCapture, or if any other thread
; *   has a concurrent capture sequence initiated with \p CU_STREAM_CAPTURE_MODE_GLOBAL,
; *   this thread is prohibited from potentially unsafe API calls.
; * - \p CU_STREAM_CAPTURE_MODE_THREAD_LOCAL: If the local thread has an ongoing capture
; *   sequence not initiated with \p CU_STREAM_CAPTURE_MODE_RELAXED, it is prohibited
; *   from potentially unsafe API calls. Concurrent capture sequences in other threads
; *   are ignored.
; * - \p CU_STREAM_CAPTURE_MODE_RELAXED: The local thread is not prohibited from potentially
; *   unsafe API calls. Note that the thread is still prohibited from API calls which
; *   necessarily conflict with stream capture, for example, attempting ::cuEventQuery
; *   on an event that was last recorded inside a capture sequence.
; *
; * \param mode - Pointer to mode value to swap with the current mode
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cuStreamBeginCapture
; */
;API
cuThreadExchangeStreamCaptureMode PROTO Mode1:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10010 */ 
IF  __CUDA_API_VERSION GE 10000
;/**
; * \brief Ends capture on a stream, returning the captured graph
; *
; * End capture on \p hStream, returning the captured graph via \p phGraph.
; * Capture must have been initiated on \p hStream via a call to ::cuStreamBeginCapture.
; * If capture was invalidated, due to a violation of the rules of stream capture, then
; * a NULL graph will be returned.
; *
; * If the \p mode argument to ::cuStreamBeginCapture was not
; * ::CU_STREAM_CAPTURE_MODE_RELAXED, this call must be from the same thread as
; * ::cuStreamBeginCapture.
; *
; * \param hStream - Stream to query
; * \param phGraph - The captured graph
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_STREAM_CAPTURE_WRONG_THREAD
; * \notefnerr
; *
; * \sa
; * ::cuStreamCreate,
; * ::cuStreamBeginCapture,
; * ::cuStreamIsCapturing
; */
;API
cuStreamEndCapture PROTO hStream:XWORD ,phGraph:XWORD 
;/**
; * \brief Returns a stream's capture status
; *
; * Return the capture status of \p hStream via \p captureStatus. After a successful
; * call, \p *captureStatus will contain one of the following:
; * - ::CU_STREAM_CAPTURE_STATUS_NONE: The stream is not capturing.
; * - ::CU_STREAM_CAPTURE_STATUS_ACTIVE: The stream is capturing.
; * - ::CU_STREAM_CAPTURE_STATUS_INVALIDATED: The stream was capturing but an error
; *   has invalidated the capture sequence. The capture sequence must be terminated
; *   with ::cuStreamEndCapture on the stream where it was initiated in order to
; *   continue using \p hStream.
; *
; * Note that, if this is called on ::CU_STREAM_LEGACY (the "null stream") while
; * a blocking stream in the same context is capturing, it will return
; * ::CUDA_ERROR_STREAM_CAPTURE_IMPLICIT and \p *captureStatus is unspecified
; * after the call. The blocking stream capture is not invalidated.
; *
; * When a blocking stream is capturing, the legacy stream is in an
; * unusable state until the blocking stream capture is terminated. The legacy
; * stream is not supported for stream capture, but attempted use would have an
; * implicit dependency on the capturing stream(s).
; *
; * \param hStream       - Stream to query
; * \param captureStatus - Returns the stream's capture status
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_STREAM_CAPTURE_IMPLICIT
; * \notefnerr
; *
; * \sa
; * ::cuStreamCreate,
; * ::cuStreamBeginCapture,
; * ::cuStreamEndCapture
; */
;API
cuStreamIsCapturing PROTO hStream:XWORD ,captureStatus:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
IF  __CUDA_API_VERSION GE 10010
;/**
; * \brief Query capture status of a stream
; *
; * Query the capture status of a stream and and get an id for 
; * the capture sequence, which is unique over the lifetime of the process.
; *
; * If called on ::CU_STREAM_LEGACY (the "null stream") while a stream not created 
; * with ::CU_STREAM_NON_BLOCKING is capturing, returns ::CUDA_ERROR_STREAM_CAPTURE_IMPLICIT.
; *
; * A valid id is returned only if both of the following are true:
; * - the call returns CUDA_SUCCESS
; * - captureStatus is set to ::CU_STREAM_CAPTURE_STATUS_ACTIVE
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_STREAM_CAPTURE_IMPLICIT
; * \notefnerr
; *
; * \sa
; * ::cuStreamBeginCapture,
; * ::cuStreamIsCapturing
; */
;API
cuStreamGetCaptureInfo PROTO hStream:XWORD ,captureStatus:XWORD ,id:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10010 */ 
IF  __CUDA_API_VERSION GE 6000
;/**
; * \brief Attach memory to a stream asynchronously
; *
; * Enqueues an operation in \p hStream to specify stream association of
; * \p length bytes of memory starting from \p dptr. This function is a
; * stream-ordered operation, meaning that it is dependent on, and will
; * only take effect when, previous work in stream has completed. Any
; * previous association is automatically replaced.
; *
; * \p dptr must point to one of the following types of memories:
; * - managed memory declared using the __managed__ keyword or allocated with
; *   ::cuMemAllocManaged.
; * - a valid host-accessible region of system-allocated pageable memory. This
; *   type of memory may only be specified if the device associated with the
; *   stream reports a non-zero value for the device attribute
; *   ::CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS.
; *
; * For managed allocations, \p length must be either zero or the entire
; * allocation's size. Both indicate that the entire allocation's stream
; * association is being changed. Currently, it is not possible to change stream
; * association for a portion of a managed allocation.
; *
; * For pageable host allocations, \p length must be non-zero.
; *
; * The stream association is specified using \p flags which must be
; * one of ::CUmemAttach_flags.
; * If the ::CU_MEM_ATTACH_GLOBAL flag is specified, the memory can be accessed
; * by any stream on any device.
; * If the ::CU_MEM_ATTACH_HOST flag is specified, the program makes a guarantee
; * that it won't access the memory on the device from any stream on a device that
; * has a zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS.
; * If the ::CU_MEM_ATTACH_SINGLE flag is specified and \p hStream is associated with
; * a device that has a zero value for the device attribute ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS,
; * the program makes a guarantee that it will only access the memory on the device
; * from \p hStream. It is illegal to attach singly to the NULL stream, because the
; * NULL stream is a virtual global stream and not a specific stream. An error will
; * be returned in this case.
; *
; * When memory is associated with a single stream, the Unified Memory system will
; * allow CPU access to this memory region so long as all operations in \p hStream
; * have completed, regardless of whether other streams are active. In effect,
; * this constrains exclusive ownership of the managed memory region by
; * an active GPU to per-stream activity instead of whole-GPU activity.
; *
; * Accessing memory on the device from streams that are not associated with
; * it will produce undefined results. No error checking is performed by the
; * Unified Memory system to ensure that kernels launched into other streams
; * do not access this region.
; *
; * It is a program's responsibility to order calls to ::cuStreamAttachMemAsync
; * via events, synchronization or other means to ensure legal access to memory
; * at all times. Data visibility and coherency will be changed appropriately
; * for all kernels which follow a stream-association change.
; *
; * If \p hStream is destroyed while data is associated with it, the association is
; * removed and the association reverts to the default visibility of the allocation
; * as specified at ::cuMemAllocManaged. For __managed__ variables, the default
; * association is always ::CU_MEM_ATTACH_GLOBAL. Note that destroying a stream is an
; * asynchronous operation, and as a result, the change to default association won't
; * happen until all work in the stream has completed.
; *
; * \param hStream - Stream in which to enqueue the attach operation
; * \param dptr    - Pointer to memory (must be a pointer to managed memory or
; *                  to a valid host-accessible region of system-allocated
; *                  pageable memory)
; * \param length  - Length of memory
; * \param flags   - Must be one of ::CUmemAttach_flags
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamWaitEvent,
; * ::cuStreamDestroy,
; * ::cuMemAllocManaged,
; * ::cudaStreamAttachMemAsync
; */
;API
cuStreamAttachMemAsync PROTO hStream:XWORD ,dptr:CUdeviceptr ,length1:DWORD ,flags:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 6000 */ 
;/**
; * \brief Determine status of a compute stream
; *
; * Returns ::CUDA_SUCCESS if all operations in the stream specified by
; * \p hStream have completed, or ::CUDA_ERROR_NOT_READY if not.
; *
; * For the purposes of Unified Memory, a return value of ::CUDA_SUCCESS
; * is equivalent to having called ::cuStreamSynchronize().
; *
; * \param hStream - Stream to query status of
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_READY
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuStreamWaitEvent,
; * ::cuStreamDestroy,
; * ::cuStreamSynchronize,
; * ::cuStreamAddCallback,
; * ::cudaStreamQuery
; */
;API
cuStreamQuery PROTO hStream:XWORD 
;/**
; * \brief Wait until a stream's tasks are completed
; *
; * Waits until the device has completed all operations in the stream specified
; * by \p hStream. If the context was created with the
; * ::CU_CTX_SCHED_BLOCKING_SYNC flag, the CPU thread will block until the
; * stream is finished with all of its tasks.
; *
; * \param hStream - Stream to wait for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuStreamDestroy,
; * ::cuStreamWaitEvent,
; * ::cuStreamQuery,
; * ::cuStreamAddCallback,
; * ::cudaStreamSynchronize
; */
;API
cuStreamSynchronize PROTO hStream:XWORD 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Destroys a stream
; *
; * Destroys the stream specified by \p hStream.
; *
; * In case the device is still doing work in the stream \p hStream
; * when ::cuStreamDestroy() is called, the function will return immediately
; * and the resources associated with \p hStream will be released automatically
; * once the device has completed all work in \p hStream.
; *
; * \param hStream - Stream to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuStreamWaitEvent,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamAddCallback,
; * ::cudaStreamDestroy
; */
;API
cuStreamDestroy PROTO hStream:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
;/**
; * \defgroup CUDA_EVENT Event Management
; *
; * ___MANBRIEF___ event management functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the event management functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Creates an event
; *
; * Creates an event *phEvent for the current context with the flags specified via
; * \p Flags. Valid flags include:
; * - ::CU_EVENT_DEFAULT: Default event creation flag.
; * - ::CU_EVENT_BLOCKING_SYNC: Specifies that the created event should use blocking
; *   synchronization.  A CPU thread that uses ::cuEventSynchronize() to wait on
; *   an event created with this flag will block until the event has actually
; *   been recorded.
; * - ::CU_EVENT_DISABLE_TIMING: Specifies that the created event does not need
; *   to record timing data.  Events created with this flag specified and
; *   the ::CU_EVENT_BLOCKING_SYNC flag not specified will provide the best
; *   performance when used with ::cuStreamWaitEvent() and ::cuEventQuery().
; * - ::CU_EVENT_INTERPROCESS: Specifies that the created event may be used as an
; *   interprocess event by ::cuIpcGetEventHandle(). ::CU_EVENT_INTERPROCESS must
; *   be specified along with ::CU_EVENT_DISABLE_TIMING.
; *
; * \param phEvent - Returns newly created event
; * \param Flags   - Event creation flags
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \notefnerr
; *
; * \sa
; * ::cuEventRecord,
; * ::cuEventQuery,
; * ::cuEventSynchronize,
; * ::cuEventDestroy,
; * ::cuEventElapsedTime,
; * ::cudaEventCreate,
; * ::cudaEventCreateWithFlags
; */
;API
cuEventCreate PROTO phEvent:XWORD ,Flags:DWORD 
;/**
; * \brief Records an event
; *
; * Captures in \p hEvent the contents of \p hStream at the time of this call.
; * \p hEvent and \p hStream must be from the same context.
; * Calls such as ::cuEventQuery() or ::cuStreamWaitEvent() will then
; * examine or wait for completion of the work that was captured. Uses of
; * \p hStream after this call do not modify \p hEvent. See note on default
; * stream behavior for what is captured in the default case.
; *
; * ::cuEventRecord() can be called multiple times on the same event and
; * will overwrite the previously captured state. Other APIs such as
; * ::cuStreamWaitEvent() use the most recently captured state at the time
; * of the API call, and are not affected by later calls to
; * ::cuEventRecord(). Before the first call to ::cuEventRecord(), an
; * event represents an empty set of work, so for example ::cuEventQuery()
; * would return ::CUDA_SUCCESS.
; *
; * \param hEvent  - Event to record
; * \param hStream - Stream to record event for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuEventCreate,
; * ::cuEventQuery,
; * ::cuEventSynchronize,
; * ::cuStreamWaitEvent,
; * ::cuEventDestroy,
; * ::cuEventElapsedTime,
; * ::cudaEventRecord
; */
;API
cuEventRecord PROTO hEvent:XWORD ,hStream:XWORD 
;/**
; * \brief Queries an event's status
; *
; * Queries the status of all work currently captured by \p hEvent. See
; * ::cuEventRecord() for details on what is captured by an event.
; *
; * Returns ::CUDA_SUCCESS if all captured work has been completed, or
; * ::CUDA_ERROR_NOT_READY if any captured work is incomplete.
; *
; * For the purposes of Unified Memory, a return value of ::CUDA_SUCCESS
; * is equivalent to having called ::cuEventSynchronize().
; *
; * \param hEvent - Event to query
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_READY
; * \notefnerr
; *
; * \sa ::cuEventCreate,
; * ::cuEventRecord,
; * ::cuEventSynchronize,
; * ::cuEventDestroy,
; * ::cuEventElapsedTime,
; * ::cudaEventQuery
; */
;API
cuEventQuery PROTO hEvent:XWORD 
;/**
; * \brief Waits for an event to complete
; *
; * Waits until the completion of all work currently captured in \p hEvent.
; * See ::cuEventRecord() for details on what is captured by an event.
; *
; * Waiting for an event that was created with the ::CU_EVENT_BLOCKING_SYNC
; * flag will cause the calling CPU thread to block until the event has
; * been completed by the device.  If the ::CU_EVENT_BLOCKING_SYNC flag has
; * not been set, then the CPU thread will busy-wait until the event has
; * been completed by the device.
; *
; * \param hEvent - Event to wait for
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuEventCreate,
; * ::cuEventRecord,
; * ::cuEventQuery,
; * ::cuEventDestroy,
; * ::cuEventElapsedTime,
; * ::cudaEventSynchronize
; */
;API
cuEventSynchronize PROTO hEvent:XWORD 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Destroys an event
; *
; * Destroys the event specified by \p hEvent.
; *
; * An event may be destroyed before it is complete (i.e., while
; * ::cuEventQuery() would return ::CUDA_ERROR_NOT_READY). In this case, the
; * call does not block on completion of the event, and any associated
; * resources will automatically be released asynchronously at completion.
; *
; * \param hEvent - Event to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuEventCreate,
; * ::cuEventRecord,
; * ::cuEventQuery,
; * ::cuEventSynchronize,
; * ::cuEventElapsedTime,
; * ::cudaEventDestroy
; */
;API
cuEventDestroy PROTO hEvent:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
;/**
; * \brief Computes the elapsed time between two events
; *
; * Computes the elapsed time between two events (in milliseconds with a
; * resolution of around 0.5 microseconds).
; *
; * If either event was last recorded in a non-NULL stream, the resulting time
; * may be greater than expected (even if both used the same stream handle). This
; * happens because the ::cuEventRecord() operation takes place asynchronously
; * and there is no guarantee that the measured latency is actually just between
; * the two events. Any number of other different stream operations could execute
; * in between the two measured events, thus altering the timing in a significant
; * way.
; *
; * If ::cuEventRecord() has not been called on either event then
; * ::CUDA_ERROR_INVALID_HANDLE is returned. If ::cuEventRecord() has been called
; * on both events but one or both of them has not yet been completed (that is,
; * ::cuEventQuery() would return ::CUDA_ERROR_NOT_READY on at least one of the
; * events), ::CUDA_ERROR_NOT_READY is returned. If either event was created with
; * the ::CU_EVENT_DISABLE_TIMING flag, then this function will return
; * ::CUDA_ERROR_INVALID_HANDLE.
; *
; * \param pMilliseconds - Time between \p hStart and \p hEnd in ms
; * \param hStart        - Starting event
; * \param hEnd          - Ending event
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_READY
; * \notefnerr
; *
; * \sa ::cuEventCreate,
; * ::cuEventRecord,
; * ::cuEventQuery,
; * ::cuEventSynchronize,
; * ::cuEventDestroy,
; * ::cudaEventElapsedTime
; */
;API
cuEventElapsedTime PROTO pMilliseconds:XWORD ,hStart:XWORD ,hEnd:XWORD 
;/**
; * \defgroup CUDA_EXTRES_INTEROP External Resource Interoperability
; *
; * ___MANBRIEF___ External resource interoperability functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the external resource interoperability functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
IF  __CUDA_API_VERSION GE 10000
;/**
; * \brief Imports an external memory object
; *
; * Imports an externally allocated memory object and returns
; * a handle to that in \p extMem_out.
; *
; * The properties of the handle being imported must be described in
; * \p memHandleDesc. The ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC structure
; * is defined as follows:
; *
; * \code
;        typedef struct CUDA_EXTERNAL_MEMORY_HANDLE_DESC_st {
;            CUexternalMemoryHandleType type;
;            union {
;                int fd;
;                struct {
;                    void *handle;
;                    const void *name;
;                } win32;
;            } handle;
;            __int64 size;
;            unsigned int flags;
;        } CUDA_EXTERNAL_MEMORY_HANDLE_DESC;
; * \endcode
; *
; * where ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::type specifies the type
; * of handle being imported. ::CUexternalMemoryHandleType is
; * defined as:
; *
; * \code
;        typedef enum CUexternalMemoryHandleType_enum {
;            CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD        = 1,
;            CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32     = 2,
;            CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT = 3,
;            CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP       = 4,
;            CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE   = 5
;        } CUexternalMemoryHandleType;
; * \endcode
; *
; * If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::type is
; * ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD, then
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::fd must be a valid
; * file descriptor referencing a memory object. Ownership of
; * the file descriptor is transferred to the CUDA driver when the
; * handle is imported successfully. Performing any operations on the
; * file descriptor after it is imported results in undefined behavior.
; *
; * If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::type is
; * ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32, then exactly one
; * of ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle and
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name must not be
; * NULL. If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle
; * is not NULL, then it must represent a valid shared NT handle that
; * references a memory object. Ownership of this handle is
; * not transferred to CUDA after the import operation, so the
; * application must release the handle using the appropriate system
; * call. If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name
; * is not NULL, then it must point to a NULL-terminated array of
; * UTF-16 characters that refers to a memory object.
; *
; * If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::type is
; * ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT, then
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle must
; * be non-NULL and
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name
; * must be NULL. The handle specified must be a globally shared KMT
; * handle. This handle does not hold a reference to the underlying
; * object, and thus will be invalid when all references to the
; * memory object are destroyed.
; *
; * If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::type is
; * ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP, then exactly one
; * of ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle and
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name must not be
; * NULL. If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle
; * is not NULL, then it must represent a valid shared NT handle that
; * is returned by ID3DDevice::CreateSharedHandle when referring to a
; * ID3D12Heap object. This handle holds a reference to the underlying
; * object. If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name
; * is not NULL, then it must point to a NULL-terminated array of
; * UTF-16 characters that refers to a ID3D12Heap object.
; *
; * If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::type is
; * ::CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE, then exactly one
; * of ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle and
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name must not be
; * NULL. If ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::handle
; * is not NULL, then it must represent a valid shared NT handle that
; * is returned by ID3DDevice::CreateSharedHandle when referring to a
; * ID3D12Resource object. This handle holds a reference to the
; * underlying object. If
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::handle::win32::name
; * is not NULL, then it must point to a NULL-terminated array of
; * UTF-16 characters that refers to a ID3D12Resource object.
; *
; * The size of the memory object must be specified in
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::size.
; *
; * Specifying the flag ::CUDA_EXTERNAL_MEMORY_DEDICATED in
; * ::CUDA_EXTERNAL_MEMORY_HANDLE_DESC::flags indicates that the
; * resource is a dedicated resource. The definition of what a
; * dedicated resource is outside the scope of this extension.
; *
; * \param extMem_out    - Returned handle to an external memory object
; * \param memHandleDesc - Memory import handle descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \note If the Vulkan memory imported into CUDA is mapped on the CPU then the
; * application must use vkInvalidateMappedMemoryRanges/vkFlushMappedMemoryRanges
; * as well as appropriate Vulkan pipeline barriers to maintain coherence between
; * CPU and GPU. For more information on these APIs, please refer to "Synchronization
; * and Cache Control" chapter from Vulkan specification.
; *
; * \sa ::cuDestroyExternalMemory,
; * ::cuExternalMemoryGetMappedBuffer,
; * ::cuExternalMemoryGetMappedMipmappedArray
; */
;API
cuImportExternalMemory PROTO extMem_out:XWORD ,memHandleDesc:XWORD 
;/**
; * \brief Maps a buffer onto an imported memory object
; *
; * Maps a buffer onto an imported memory object and returns a device
; * pointer in \p devPtr.
; *
; * The properties of the buffer being mapped must be described in
; * \p bufferDesc. The ::CUDA_EXTERNAL_MEMORY_BUFFER_DESC structure is
; * defined as follows:
; *
; * \code
;        typedef struct CUDA_EXTERNAL_MEMORY_BUFFER_DESC_st {
;            __int64 offset;
;            __int64 size;
;            unsigned int flags;
;        } CUDA_EXTERNAL_MEMORY_BUFFER_DESC;
; * \endcode
; *
; * where ::CUDA_EXTERNAL_MEMORY_BUFFER_DESC::offset is the offset in
; * the memory object where the buffer's base address is.
; * ::CUDA_EXTERNAL_MEMORY_BUFFER_DESC::size is the size of the buffer.
; * ::CUDA_EXTERNAL_MEMORY_BUFFER_DESC::flags must be zero.
; *
; * The offset and size have to be suitably aligned to match the
; * requirements of the external API. Mapping two buffers whose ranges
; * overlap may or may not result in the same virtual address being
; * returned for the overlapped portion. In such cases, the application
; * must ensure that all accesses to that region from the GPU are
; * volatile. Otherwise writes made via one address are not guaranteed
; * to be visible via the other address, even if they're issued by the
; * same thread. It is recommended that applications map the combined
; * range instead of mapping separate buffers and then apply the
; * appropriate offsets to the returned pointer to derive the
; * individual buffers.
; *
; * The returned pointer \p devPtr must be freed using ::cuMemFree.
; *
; * \param devPtr     - Returned device pointer to buffer
; * \param extMem     - Handle to external memory object
; * \param bufferDesc - Buffer descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuImportExternalMemory
; * ::cuDestroyExternalMemory,
; * ::cuExternalMemoryGetMappedMipmappedArray
; */
;API
cuExternalMemoryGetMappedBuffer PROTO devPtr:XWORD ,extMem:XWORD ,bufferDesc:XWORD 
;/**
; * \brief Maps a CUDA mipmapped array onto an external memory object
; *
; * Maps a CUDA mipmapped array onto an external object and returns a
; * handle to it in \p mipmap.
; *
; * The properties of the CUDA mipmapped array being mapped must be
; * described in \p mipmapDesc. The structure
; * ::CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC is defined as follows:
; *
; * \code
;        typedef struct CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC_st {
;            __int64 offset;
;            CUDA_ARRAY3D_DESCRIPTOR arrayDesc;
;            unsigned int numLevels;
;        } CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC;
; * \endcode
; *
; * where ::CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC::offset is the
; * offset in the memory object where the base level of the mipmap
; * chain is.
; * ::CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC::arrayDesc describes
; * the format, dimensions and type of the base level of the mipmap
; * chain. For further details on these parameters, please refer to the
; * documentation for ::cuMipmappedArrayCreate. Note that if the mipmapped
; * array is bound as a color target in the graphics API, then the flag
; * ::CUDA_ARRAY3D_COLOR_ATTACHMENT must be specified in
; * ::CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC::arrayDesc::Flags.
; * ::CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC::numLevels specifies
; * the total number of levels in the mipmap chain.
; *
; * The returned CUDA mipmapped array must be freed using ::cuMipmappedArrayDestroy.
; *
; * \param mipmap     - Returned CUDA mipmapped array
; * \param extMem     - Handle to external memory object
; * \param mipmapDesc - CUDA array descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuImportExternalMemory
; * ::cuDestroyExternalMemory,
; * ::cuExternalMemoryGetMappedBuffer
; */
;API
cuExternalMemoryGetMappedMipmappedArray PROTO mipmap:XWORD ,extMem:XWORD ,mipmapDesc:XWORD 
;/**
; * \brief Destroys an external memory object.
; *
; * Destroys the specified external memory object. Any existing buffers
; * and CUDA mipmapped arrays mapped onto this object must no longer be
; * used and must be explicitly freed using ::cuMemFree and
; * ::cuMipmappedArrayDestroy respectively.
; *
; * \param extMem - External memory object to be destroyed
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuImportExternalMemory
; * ::cuExternalMemoryGetMappedBuffer,
; * ::cuExternalMemoryGetMappedMipmappedArray
; */
;API
cuDestroyExternalMemory PROTO extMem:XWORD 
;/**
; * \brief Imports an external semaphore
; *
; * Imports an externally allocated synchronization object and returns
; * a handle to that in \p extSem_out.
; *
; * The properties of the handle being imported must be described in
; * \p semHandleDesc. The ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC is
; * defined as follows:
; *
; * \code
;        typedef struct CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC_st {
;            CUexternalSemaphoreHandleType type;
;            union {
;                int fd;
;                struct {
;                    void *handle;
;                    const void *name;
;                } win32;
;            } handle;
;            unsigned int flags;
;        } CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC;
; * \endcode
; *
; * where ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::type specifies the type of
; * handle being imported. ::CUexternalSemaphoreHandleType is defined
; * as:
; *
; * \code
;        typedef enum CUexternalSemaphoreHandleType_enum {
;            CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD        = 1,
;            CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32     = 2,
;            CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT = 3,
;            CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE      = 4
;        } CUexternalSemaphoreHandleType;
; * \endcode
; *
; * If ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::type is
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD, then
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::fd must be a valid
; * file descriptor referencing a synchronization object. Ownership of
; * the file descriptor is transferred to the CUDA driver when the
; * handle is imported successfully. Performing any operations on the
; * file descriptor after it is imported results in undefined behavior.
; *
; * If ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::type is
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32, then exactly one
; * of ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::handle and
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::name must not be
; * NULL. If
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::handle
; * is not NULL, then it must represent a valid shared NT handle that
; * references a synchronization object. Ownership of this handle is
; * not transferred to CUDA after the import operation, so the
; * application must release the handle using the appropriate system
; * call. If ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::name
; * is not NULL, then it must name a valid synchronization object.
; *
; * If ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::type is
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT, then
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::handle must
; * be non-NULL and
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::name
; * must be NULL. The handle specified must be a globally shared KMT
; * handle. This handle does not hold a reference to the underlying
; * object, and thus will be invalid when all references to the
; * synchronization object are destroyed.
; *
; * If ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::type is
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE, then exactly one
; * of ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::handle and
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::name must not be
; * NULL. If
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::handle
; * is not NULL, then it must represent a valid shared NT handle that
; * is returned by ID3DDevice::CreateSharedHandle when referring to a
; * ID3D12Fence object. This handle holds a reference to the underlying
; * object. If
; * ::CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC::handle::win32::name
; * is not NULL, then it must name a valid synchronization object that
; * refers to a valid ID3D12Fence object.
; *
; * \param extSem_out    - Returned handle to an external semaphore
; * \param semHandleDesc - Semaphore import handle descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuDestroyExternalSemaphore,
; * ::cuSignalExternalSemaphoresAsync,
; * ::cuWaitExternalSemaphoresAsync
; */
;API
cuImportExternalSemaphore PROTO extSem_out:XWORD ,semHandleDesc:XWORD 
;/**
; * \brief Signals a set of external semaphore objects
; *
; * Enqueues a signal operation on a set of externally allocated
; * semaphore object in the specified stream. The operations will be
; * executed when all prior operations in the stream complete.
; *
; * The exact semantics of signaling a semaphore depends on the type of
; * the object.
; *
; * If the semaphore object is any one of the following types:
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD,
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32,
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT
; * then signaling the semaphore will set it to the signaled state.
; *
; * If the semaphore object is of the type
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE, then the
; * semaphore will be set to the value specified in
; * ::CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS::params::fence::value.
; *
; * \param extSemArray - Set of external semaphores to be signaled
; * \param paramsArray - Array of semaphore parameters
; * \param numExtSems  - Number of semaphores to signal
; * \param stream     - Stream to enqueue the signal operations in
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuImportExternalSemaphore,
; * ::cuDestroyExternalSemaphore,
; * ::cuWaitExternalSemaphoresAsync
; */
;API
cuSignalExternalSemaphoresAsync PROTO extSemArray:XWORD ,paramsArray:XWORD ,numExtSems:DWORD ,stream:XWORD 
;/**
; * \brief Waits on a set of external semaphore objects
; *
; * Enqueues a wait operation on a set of externally allocated
; * semaphore object in the specified stream. The operations will be
; * executed when all prior operations in the stream complete.
; *
; * The exact semantics of waiting on a semaphore depends on the type
; * of the object.
; *
; * If the semaphore object is any one of the following types:
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD,
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32,
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT
; * then waiting on the semaphore will wait until the semaphore reaches
; * the signaled state. The semaphore will then be reset to the
; * unsignaled state. Therefore for every signal operation, there can
; * only be one wait operation.
; *
; * If the semaphore object is of the type
; * ::CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE, then waiting on
; * the semaphore will wait until the value of the semaphore is
; * greater than or equal to
; * ::CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS::params::fence::value.
; *
; * \param extSemArray - External semaphores to be waited on
; * \param paramsArray - Array of semaphore parameters
; * \param numExtSems  - Number of semaphores to wait on
; * \param stream      - Stream to enqueue the wait operations in
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuImportExternalSemaphore,
; * ::cuDestroyExternalSemaphore,
; * ::cuSignalExternalSemaphoresAsync
; */
;API
cuWaitExternalSemaphoresAsync PROTO extSemArray:XWORD ,paramsArray:XWORD ,numExtSems:DWORD ,stream:XWORD 
;/**
; * \brief Destroys an external semaphore
; *
; * Destroys an external semaphore object and releases any references
; * to the underlying resource. Any outstanding signals or waits must
; * have completed before the semaphore is destroyed.
; *
; * \param extSem - External semaphore to be destroyed
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_HANDLE
; * \notefnerr
; *
; * \sa ::cuImportExternalSemaphore,
; * ::cuSignalExternalSemaphoresAsync,
; * ::cuWaitExternalSemaphoresAsync
; */
;API
cuDestroyExternalSemaphore PROTO extSem:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
;/**
; * \defgroup CUDA_MEMOP Stream memory operations
; *
; * ___MANBRIEF___ Stream memory operations of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the stream memory operations of the low-level CUDA
; * driver application programming interface.
; *
; * The whole set of operations is disabled by default. Users are required
; * to explicitly enable them, e.g. on Linux by passing the kernel module
; * parameter shown below:
; *     modprobe nvidia NVreg_EnableStreamMemOPs=1
; * There is currently no way to enable these operations on other operating
; * systems.
; *
; * Users can programmatically query whether the device supports these
; * operations with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS.
; *
; * Support for the ::CU_STREAM_WAIT_VALUE_NOR flag can be queried with
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR.
; *
; * Support for the ::cuStreamWriteValue64() and ::cuStreamWaitValue64()
; * functions, as well as for the ::CU_STREAM_MEM_OP_WAIT_VALUE_64 and
; * ::CU_STREAM_MEM_OP_WRITE_VALUE_64 flags, can be queried with
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS.
; *
; * Support for both ::CU_STREAM_WAIT_VALUE_FLUSH and
; * ::CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES requires dedicated platform
; * hardware features and can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_FLUSH_REMOTE_WRITES.
; *
; * Note that all memory pointers passed as parameters to these operations
; * are device pointers. Where necessary a device pointer should be
; * obtained, for example with ::cuMemHostGetDevicePointer().
; *
; * None of the operations accepts pointers to managed memory buffers
; * (::cuMemAllocManaged).
; *
; * @{
; */
IF  __CUDA_API_VERSION GE 8000
;/**
; * \brief Wait on a memory location
; *
; * Enqueues a synchronization of the stream on the given memory location. Work
; * ordered after the operation will block until the given condition on the
; * memory is satisfied. By default, the condition is to wait for
; * (int32_t)(*addr - value) >= 0, a cyclic greater-or-equal.
; * Other condition types can be specified via \p flags.
; *
; * If the memory was registered via ::cuMemHostRegister(), the device pointer
; * should be obtained with ::cuMemHostGetDevicePointer(). This function cannot
; * be used with managed memory (::cuMemAllocManaged).
; *
; * Support for this can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS.
; *
; * Support for CU_STREAM_WAIT_VALUE_NOR can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR.
; *
; * \param stream The stream to synchronize on the memory location.
; * \param addr The memory location to wait on.
; * \param value The value to compare with the memory location.
; * \param flags See ::CUstreamWaitValue_flags.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \notefnerr
; *
; * \sa ::cuStreamWaitValue64,
; * ::cuStreamWriteValue32,
; * ::cuStreamWriteValue64
; * ::cuStreamBatchMemOp,
; * ::cuMemHostRegister,
; * ::cuStreamWaitEvent
; */
;API
cuStreamWaitValue32 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:DWORD ,flags:DWORD 
;/**
; * \brief Wait on a memory location
; *
; * Enqueues a synchronization of the stream on the given memory location. Work
; * ordered after the operation will block until the given condition on the
; * memory is satisfied. By default, the condition is to wait for
; * (int64_t)(*addr - value) >= 0, a cyclic greater-or-equal.
; * Other condition types can be specified via \p flags.
; *
; * If the memory was registered via ::cuMemHostRegister(), the device pointer
; * should be obtained with ::cuMemHostGetDevicePointer().
; *
; * Support for this can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS.
; *
; * \param stream The stream to synchronize on the memory location.
; * \param addr The memory location to wait on.
; * \param value The value to compare with the memory location.
; * \param flags See ::CUstreamWaitValue_flags.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \notefnerr
; *
; * \sa ::cuStreamWaitValue32,
; * ::cuStreamWriteValue32,
; * ::cuStreamWriteValue64,
; * ::cuStreamBatchMemOp,
; * ::cuMemHostRegister,
; * ::cuStreamWaitEvent
; */
;API
cuStreamWaitValue64 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:QWORD ,flags:DWORD 
;/**
; * \brief Write a value to memory
; *
; * Write a value to memory. Unless the ::CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER
; * flag is passed, the write is preceded by a system-wide memory fence,
; * equivalent to a __threadfence_system() but scoped to the stream
; * rather than a CUDA thread.
; *
; * If the memory was registered via ::cuMemHostRegister(), the device pointer
; * should be obtained with ::cuMemHostGetDevicePointer(). This function cannot
; * be used with managed memory (::cuMemAllocManaged).
; *
; * Support for this can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS.
; *
; * \param stream The stream to do the write in.
; * \param addr The device address to write to.
; * \param value The value to write.
; * \param flags See ::CUstreamWriteValue_flags.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \notefnerr
; *
; * \sa ::cuStreamWriteValue64,
; * ::cuStreamWaitValue32,
; * ::cuStreamWaitValue64,
; * ::cuStreamBatchMemOp,
; * ::cuMemHostRegister,
; * ::cuEventRecord
; */
;API
cuStreamWriteValue32 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:DWORD ,flags:DWORD 
;/**
; * \brief Write a value to memory
; *
; * Write a value to memory. Unless the ::CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER
; * flag is passed, the write is preceded by a system-wide memory fence,
; * equivalent to a __threadfence_system() but scoped to the stream
; * rather than a CUDA thread.
; *
; * If the memory was registered via ::cuMemHostRegister(), the device pointer
; * should be obtained with ::cuMemHostGetDevicePointer().
; *
; * Support for this can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS.
; *
; * \param stream The stream to do the write in.
; * \param addr The device address to write to.
; * \param value The value to write.
; * \param flags See ::CUstreamWriteValue_flags.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \notefnerr
; *
; * \sa ::cuStreamWriteValue32,
; * ::cuStreamWaitValue32,
; * ::cuStreamWaitValue64,
; * ::cuStreamBatchMemOp,
; * ::cuMemHostRegister,
; * ::cuEventRecord
; */
;API
cuStreamWriteValue64 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:QWORD ,flags:DWORD 
;/**
; * \brief Batch operations to synchronize the stream via memory operations
; *
; * This is a batch version of ::cuStreamWaitValue32() and ::cuStreamWriteValue32().
; * Batching operations may avoid some performance overhead in both the API call
; * and the device execution versus adding them to the stream in separate API
; * calls. The operations are enqueued in the order they appear in the array.
; *
; * See ::CUstreamBatchMemOpType for the full set of supported operations, and
; * ::cuStreamWaitValue32(), ::cuStreamWaitValue64(), ::cuStreamWriteValue32(),
; * and ::cuStreamWriteValue64() for details of specific operations.
; *
; * Basic support for this can be queried with ::cuDeviceGetAttribute() and
; * ::CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS. See related APIs for details
; * on querying support for specific operations.
; *
; * \param stream The stream to enqueue the operations in.
; * \param count The number of operations in the array. Must be less than 256.
; * \param paramArray The types and parameters of the individual operations.
; * \param flags Reserved for future expansion; must be 0.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \notefnerr
; *
; * \sa ::cuStreamWaitValue32,
; * ::cuStreamWaitValue64,
; * ::cuStreamWriteValue32,
; * ::cuStreamWriteValue64,
; * ::cuMemHostRegister
; */
;API
cuStreamBatchMemOp PROTO stream:XWORD ,count:DWORD ,paramArray:XWORD ,flags:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 8000 */ 
;/**
; * \defgroup CUDA_EXEC Execution Control
; *
; * ___MANBRIEF___ execution control functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the execution control functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Returns information about a function
; *
; * Returns in \p *pi the integer value of the attribute \p attrib on the kernel
; * given by \p hfunc. The supported attributes are:
; * - ::CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK: The maximum number of threads
; *   per block, beyond which a launch of the function would fail. This number
; *   depends on both the function and the device on which the function is
; *   currently loaded.
; * - ::CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES: The size in bytes of
; *   statically-allocated shared memory per block required by this function.
; *   This does not include dynamically-allocated shared memory requested by
; *   the user at runtime.
; * - ::CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES: The size in bytes of user-allocated
; *   constant memory required by this function.
; * - ::CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES: The size in bytes of local memory
; *   used by each thread of this function.
; * - ::CU_FUNC_ATTRIBUTE_NUM_REGS: The number of registers used by each thread
; *   of this function.
; * - ::CU_FUNC_ATTRIBUTE_PTX_VERSION: The PTX virtual architecture version for
; *   which the function was compiled. This value is the major PTX version * 10
; *   + the minor PTX version, so a PTX version 1.3 function would return the
; *   value 13. Note that this may return the undefined value of 0 for cubins
; *   compiled prior to CUDA 3.0.
; * - ::CU_FUNC_ATTRIBUTE_BINARY_VERSION: The binary architecture version for
; *   which the function was compiled. This value is the major binary
; *   version * 10 + the minor binary version, so a binary version 1.3 function
; *   would return the value 13. Note that this will return a value of 10 for
; *   legacy cubins that do not have a properly-encoded binary architecture
; *   version.
; * - ::CU_FUNC_CACHE_MODE_CA: The attribute to indicate whether the function has
; *   been compiled with user specified option "-Xptxas --dlcm=ca" set .
; * - ::CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES: The maximum size in bytes of
; *   dynamically-allocated shared memory.
; * - ::CU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT: Preferred shared memory-L1
; *   cache split ratio in percent of total shared memory.
; *
; * \param pi     - Returned attribute value
; * \param attrib - Attribute requested
; * \param hfunc  - Function to query attribute of
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuFuncSetCacheConfig,
; * ::cuLaunchKernel,
; * ::cudaFuncGetAttributes
; * ::cudaFuncSetAttribute
; */
;API
cuFuncGetAttribute PROTO pi:XWORD ,attrib:CUfunction_attribute ,hfunc:XWORD 
IF  __CUDA_API_VERSION GE 9000
;/**
; * \brief Sets information about a function
; *
; * This call sets the value of a specified attribute \p attrib on the kernel given
; * by \p hfunc to an integer value specified by \p val
; * This function returns CUDA_SUCCESS if the new value of the attribute could be
; * successfully set. If the set fails, this call will return an error.
; * Not all attributes can have values set. Attempting to set a value on a read-only
; * attribute will result in an error (CUDA_ERROR_INVALID_VALUE)
; *
; * Supported attributes for the cuFuncSetAttribute call are:
; * - ::CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES: This maximum size in bytes of
; *   dynamically-allocated shared memory. The value should contain the requested
; *   maximum size of dynamically-allocated shared memory. The sum of this value and
; *   the function attribute ::CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES cannot exceed the
; *   device attribute ::CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN.
; *   The maximal size of requestable dynamic shared memory may differ by GPU
; *   architecture.
; * - ::CU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT: On devices where the L1
; *   cache and shared memory use the same hardware resources, this sets the shared memory
; *   carveout preference, in percent of the total shared memory. 
; *   See ::CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR
; *   This is only a hint, and the driver can choose a different ratio if required to execute the function.
; *
; * \param hfunc  - Function to query attribute of
; * \param attrib - Attribute requested
; * \param value   - The value to set
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuFuncSetCacheConfig,
; * ::cuLaunchKernel,
; * ::cudaFuncGetAttributes
; * ::cudaFuncSetAttribute
; */
;API
cuFuncSetAttribute PROTO hfunc:XWORD ,attrib:CUfunction_attribute ,value:DWORD 
ENDIF ; __CUDA_API_VERSION >= 9000
;/**
; * \brief Sets the preferred cache configuration for a device function
; *
; * On devices where the L1 cache and shared memory use the same hardware
; * resources, this sets through \p config the preferred cache configuration for
; * the device function \p hfunc. This is only a preference. The driver will use
; * the requested configuration if possible, but it is free to choose a different
; * configuration if required to execute \p hfunc.  Any context-wide preference
; * set via ::cuCtxSetCacheConfig() will be overridden by this per-function
; * setting unless the per-function setting is ::CU_FUNC_CACHE_PREFER_NONE. In
; * that case, the current context-wide setting will be used.
; *
; * This setting does nothing on devices where the size of the L1 cache and
; * shared memory are fixed.
; *
; * Launching a kernel with a different preference than the most recent
; * preference setting may insert a device-side synchronization point.
; *
; *
; * The supported cache configurations are:
; * - ::CU_FUNC_CACHE_PREFER_NONE: no preference for shared memory or L1 (default)
; * - ::CU_FUNC_CACHE_PREFER_SHARED: prefer larger shared memory and smaller L1 cache
; * - ::CU_FUNC_CACHE_PREFER_L1: prefer larger L1 cache and smaller shared memory
; * - ::CU_FUNC_CACHE_PREFER_EQUAL: prefer equal sized L1 cache and shared memory
; *
; * \param hfunc  - Kernel to configure cache for
; * \param config - Requested cache configuration
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuFuncGetAttribute,
; * ::cuLaunchKernel,
; * ::cudaFuncSetCacheConfig
; */
;API
cuFuncSetCacheConfig PROTO hfunc:XWORD ,config:CUfunc_cache 
IF  __CUDA_API_VERSION GE 4020
;/**
; * \brief Sets the shared memory configuration for a device function.
; *
; * On devices with configurable shared memory banks, this function will
; * force all subsequent launches of the specified device function to have
; * the given shared memory bank size configuration. On any given launch of the
; * function, the shared memory configuration of the device will be temporarily
; * changed if needed to suit the function's preferred configuration. Changes in
; * shared memory configuration between subsequent launches of functions,
; * may introduce a device side synchronization point.
; *
; * Any per-function setting of shared memory bank size set via
; * ::cuFuncSetSharedMemConfig will override the context wide setting set with
; * ::cuCtxSetSharedMemConfig.
; *
; * Changing the shared memory bank size will not increase shared memory usage
; * or affect occupancy of kernels, but may have major effects on performance.
; * Larger bank sizes will allow for greater potential bandwidth to shared memory,
; * but will change what kinds of accesses to shared memory will result in bank
; * conflicts.
; *
; * This function will do nothing on devices with fixed shared memory bank size.
; *
; * The supported bank configurations are:
; * - ::CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE: use the context's shared memory
; *   configuration when launching this function.
; * - ::CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE: set shared memory bank width to
; *   be natively four bytes when launching this function.
; * - ::CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE: set shared memory bank width to
; *   be natively eight bytes when launching this function.
; *
; * \param hfunc  - kernel to be given a shared memory config
; * \param config - requested shared memory configuration
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuCtxGetSharedMemConfig,
; * ::cuCtxSetSharedMemConfig,
; * ::cuFuncGetAttribute,
; * ::cuLaunchKernel,
; * ::cudaFuncSetSharedMemConfig
; */
;API
cuFuncSetSharedMemConfig PROTO hfunc:XWORD ,config:CUsharedconfig 
ENDIF 
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Launches a CUDA function
; *
; * Invokes the kernel \p f on a \p gridDimX x \p gridDimY x \p gridDimZ
; * grid of blocks. Each block contains \p blockDimX x \p blockDimY x
; * \p blockDimZ threads.
; *
; * \p sharedMemBytes sets the amount of dynamic shared memory that will be
; * available to each thread block.
; *
; * Kernel parameters to \p f can be specified in one of two ways:
; *
; * 1) Kernel parameters can be specified via \p kernelParams.  If \p f
; * has N parameters, then \p kernelParams needs to be an array of N
; * pointers.  Each of \p kernelParams[0] through \p kernelParams[N-1]
; * must point to a region of memory from which the actual kernel
; * parameter will be copied.  The number of kernel parameters and their
; * offsets and sizes do not need to be specified as that information is
; * retrieved directly from the kernel's image.
; *
; * 2) Kernel parameters can also be packaged by the application into
; * a single buffer that is passed in via the \p extra parameter.
; * This places the burden on the application of knowing each kernel
; * parameter's size and alignment/padding within the buffer.  Here is
; * an example of using the \p extra parameter in this manner:
; * \code
;    size_t argBufferSize;
;    char argBuffer[256];
;    // populate argBuffer and argBufferSize
;    void *config[] = {
;        CU_LAUNCH_PARAM_BUFFER_POINTER, argBuffer,
;        CU_LAUNCH_PARAM_BUFFER_SIZE,    &argBufferSize,
;        CU_LAUNCH_PARAM_END
;    };
;    status = cuLaunchKernel(f, gx, gy, gz, bx, by, bz, sh, s, NULL, config);
; * \endcode
; *
; * The \p extra parameter exists to allow ::cuLaunchKernel to take
; * additional less commonly used arguments.  \p extra specifies a list of
; * names of extra settings and their corresponding values.  Each extra
; * setting name is immediately followed by the corresponding value.  The
; * list must be terminated with either NULL or ::CU_LAUNCH_PARAM_END.
; *
; * - ::CU_LAUNCH_PARAM_END, which indicates the end of the \p extra
; *   array;
; * - ::CU_LAUNCH_PARAM_BUFFER_POINTER, which specifies that the next
; *   value in \p extra will be a pointer to a buffer containing all
; *   the kernel parameters for launching kernel \p f;
; * - ::CU_LAUNCH_PARAM_BUFFER_SIZE, which specifies that the next
; *   value in \p extra will be a pointer to a size_t containing the
; *   size of the buffer specified with ::CU_LAUNCH_PARAM_BUFFER_POINTER;
; *
; * The error ::CUDA_ERROR_INVALID_VALUE will be returned if kernel
; * parameters are specified with both \p kernelParams and \p extra
; * (i.e. both \p kernelParams and \p extra are non-NULL).
; *
; * Calling ::cuLaunchKernel() sets persistent function state that is
; * the same as function state set through the following deprecated APIs:
; *  ::cuFuncSetBlockShape(),
; *  ::cuFuncSetSharedSize(),
; *  ::cuParamSetSize(),
; *  ::cuParamSeti(),
; *  ::cuParamSetf(),
; *  ::cuParamSetv().
; *
; * When the kernel \p f is launched via ::cuLaunchKernel(), the previous
; * block shape, shared size and parameter info associated with \p f
; * is overwritten.
; *
; * Note that to use ::cuLaunchKernel(), the kernel \p f must either have
; * been compiled with toolchain version 3.2 or later so that it will
; * contain kernel parameter information, or have no kernel parameters.
; * If either of these conditions is not met, then ::cuLaunchKernel() will
; * return ::CUDA_ERROR_INVALID_IMAGE.
; *
; * \param f              - Kernel to launch
; * \param gridDimX       - Width of grid in blocks
; * \param gridDimY       - Height of grid in blocks
; * \param gridDimZ       - Depth of grid in blocks
; * \param blockDimX      - X dimension of each thread block
; * \param blockDimY      - Y dimension of each thread block
; * \param blockDimZ      - Z dimension of each thread block
; * \param sharedMemBytes - Dynamic shared-memory size per thread block in bytes
; * \param hStream        - Stream identifier
; * \param kernelParams   - Array of pointers to kernel parameters
; * \param extra          - Extra options
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_IMAGE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_LAUNCH_FAILED,
; * ::CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
; * ::CUDA_ERROR_LAUNCH_TIMEOUT,
; * ::CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuFuncSetCacheConfig,
; * ::cuFuncGetAttribute,
; * ::cudaLaunchKernel
; */
;API
cuLaunchKernel PROTO f:XWORD ,gridDimX:DWORD ,gridDimY:DWORD ,gridDimZ:DWORD ,blockDimX:DWORD ,blockDimY:DWORD ,blockDimZ:DWORD ,sharedMemBytes:DWORD ,hStream:XWORD ,kernelParams:XWORD ,extra:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 9000
;/**
; * \brief Launches a CUDA function where thread blocks can cooperate and synchronize as they execute
; *
; * Invokes the kernel \p f on a \p gridDimX x \p gridDimY x \p gridDimZ
; * grid of blocks. Each block contains \p blockDimX x \p blockDimY x
; * \p blockDimZ threads.
; *
; * \p sharedMemBytes sets the amount of dynamic shared memory that will be
; * available to each thread block.
; *
; * The device on which this kernel is invoked must have a non-zero value for
; * the device attribute ::CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH.
; *
; * The total number of blocks launched cannot exceed the maximum number of blocks per
; * multiprocessor as returned by ::cuOccupancyMaxActiveBlocksPerMultiprocessor (or
; * ::cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags) times the number of multiprocessors
; * as specified by the device attribute ::CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT.
; *
; * The kernel cannot make use of CUDA dynamic parallelism.
; *
; * Kernel parameters must be specified via \p kernelParams.  If \p f
; * has N parameters, then \p kernelParams needs to be an array of N
; * pointers.  Each of \p kernelParams[0] through \p kernelParams[N-1]
; * must point to a region of memory from which the actual kernel
; * parameter will be copied.  The number of kernel parameters and their
; * offsets and sizes do not need to be specified as that information is
; * retrieved directly from the kernel's image.
; *
; * Calling ::cuLaunchCooperativeKernel() sets persistent function state that is
; * the same as function state set through ::cuLaunchKernel API
; *
; * When the kernel \p f is launched via ::cuLaunchCooperativeKernel(), the previous
; * block shape, shared size and parameter info associated with \p f
; * is overwritten.
; *
; * Note that to use ::cuLaunchCooperativeKernel(), the kernel \p f must either have
; * been compiled with toolchain version 3.2 or later so that it will
; * contain kernel parameter information, or have no kernel parameters.
; * If either of these conditions is not met, then ::cuLaunchCooperativeKernel() will
; * return ::CUDA_ERROR_INVALID_IMAGE.
; *
; * \param f              - Kernel to launch
; * \param gridDimX       - Width of grid in blocks
; * \param gridDimY       - Height of grid in blocks
; * \param gridDimZ       - Depth of grid in blocks
; * \param blockDimX      - X dimension of each thread block
; * \param blockDimY      - Y dimension of each thread block
; * \param blockDimZ      - Z dimension of each thread block
; * \param sharedMemBytes - Dynamic shared-memory size per thread block in bytes
; * \param hStream        - Stream identifier
; * \param kernelParams   - Array of pointers to kernel parameters
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_IMAGE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_LAUNCH_FAILED,
; * ::CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
; * ::CUDA_ERROR_LAUNCH_TIMEOUT,
; * ::CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
; * ::CUDA_ERROR_COOPERATIVE_LAUNCH_TOO_LARGE,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuFuncSetCacheConfig,
; * ::cuFuncGetAttribute,
; * ::cuLaunchCooperativeKernelMultiDevice,
; * ::cudaLaunchCooperativeKernel
; */
;API
cuLaunchCooperativeKernel PROTO f:XWORD ,gridDimX:DWORD ,gridDimY:DWORD ,gridDimZ:DWORD ,blockDimX:DWORD ,blockDimY:DWORD ,blockDimZ:DWORD ,sharedMemBytes:DWORD ,hStream:XWORD ,kernelParams:XWORD 
;/**
; * \brief Launches CUDA functions on multiple devices where thread blocks can cooperate and synchronize as they execute
; *
; * Invokes kernels as specified in the \p launchParamsList array where each element
; * of the array specifies all the parameters required to perform a single kernel launch.
; * These kernels can cooperate and synchronize as they execute. The size of the array is
; * specified by \p numDevices.
; *
; * No two kernels can be launched on the same device. All the devices targeted by this
; * multi-device launch must be identical. All devices must have a non-zero value for the
; * device attribute ::CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH.
; *
; * All kernels launched must be identical with respect to the compiled code. Note that
; * any __device__, __constant__ or __managed__ variables present in the module that owns
; * the kernel launched on each device, are independently instantiated on every device.
; * It is the application's responsiblity to ensure these variables are initialized and
; * used appropriately.
; *
; * The size of the grids as specified in blocks, the size of the blocks themselves
; * and the amount of shared memory used by each thread block must also match across
; * all launched kernels.
; *
; * The streams used to launch these kernels must have been created via either ::cuStreamCreate
; * or ::cuStreamCreateWithPriority. The NULL stream or ::CU_STREAM_LEGACY or ::CU_STREAM_PER_THREAD
; * cannot be used.
; *
; * The total number of blocks launched per kernel cannot exceed the maximum number of blocks
; * per multiprocessor as returned by ::cuOccupancyMaxActiveBlocksPerMultiprocessor (or
; * ::cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags) times the number of multiprocessors
; * as specified by the device attribute ::CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT. Since the
; * total number of blocks launched per device has to match across all devices, the maximum
; * number of blocks that can be launched per device will be limited by the device with the
; * least number of multiprocessors.
; *
; * The kernels cannot make use of CUDA dynamic parallelism.
; *
; * The ::CUDA_LAUNCH_PARAMS structure is defined as:
; * \code
;        typedef struct CUDA_LAUNCH_PARAMS_st
;        {
;            CUfunction function;
;            unsigned int gridDimX;
;            unsigned int gridDimY;
;            unsigned int gridDimZ;
;            unsigned int blockDimX;
;            unsigned int blockDimY;
;            unsigned int blockDimZ;
;            unsigned int sharedMemBytes;
;            CUstream hStream;
;            void **kernelParams;
;        } CUDA_LAUNCH_PARAMS;
; * \endcode
; * where:
; * - ::CUDA_LAUNCH_PARAMS::function specifies the kernel to be launched. All functions must
; *   be identical with respect to the compiled code.
; * - ::CUDA_LAUNCH_PARAMS::gridDimX is the width of the grid in blocks. This must match across
; *   all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::gridDimY is the height of the grid in blocks. This must match across
; *   all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::gridDimZ is the depth of the grid in blocks. This must match across
; *   all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::blockDimX is the X dimension of each thread block. This must match across
; *   all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::blockDimX is the Y dimension of each thread block. This must match across
; *   all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::blockDimZ is the Z dimension of each thread block. This must match across
; *   all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::sharedMemBytes is the dynamic shared-memory size per thread block in bytes.
; *   This must match across all kernels launched.
; * - ::CUDA_LAUNCH_PARAMS::hStream is the handle to the stream to perform the launch in. This cannot
; *   be the NULL stream or ::CU_STREAM_LEGACY or ::CU_STREAM_PER_THREAD. The CUDA context associated
; *   with this stream must match that associated with ::CUDA_LAUNCH_PARAMS::function.
; * - ::CUDA_LAUNCH_PARAMS::kernelParams is an array of pointers to kernel parameters. If
; *   ::CUDA_LAUNCH_PARAMS::function has N parameters, then ::CUDA_LAUNCH_PARAMS::kernelParams
; *   needs to be an array of N pointers. Each of ::CUDA_LAUNCH_PARAMS::kernelParams[0] through
; *   ::CUDA_LAUNCH_PARAMS::kernelParams[N-1] must point to a region of memory from which the actual
; *   kernel parameter will be copied. The number of kernel parameters and their offsets and sizes
; *   do not need to be specified as that information is retrieved directly from the kernel's image.
; *
; * By default, the kernel won't begin execution on any GPU until all prior work in all the specified
; * streams has completed. This behavior can be overridden by specifying the flag
; * ::CUDA_COOPERATIVE_LAUNCH_MULTI_DEVICE_NO_PRE_LAUNCH_SYNC. When this flag is specified, each kernel
; * will only wait for prior work in the stream corresponding to that GPU to complete before it begins
; * execution.
; *
; * Similarly, by default, any subsequent work pushed in any of the specified streams will not begin
; * execution until the kernels on all GPUs have completed. This behavior can be overridden by specifying
; * the flag ::CUDA_COOPERATIVE_LAUNCH_MULTI_DEVICE_NO_POST_LAUNCH_SYNC. When this flag is specified,
; * any subsequent work pushed in any of the specified streams will only wait for the kernel launched
; * on the GPU corresponding to that stream to complete before it begins execution.
; *
; * Calling ::cuLaunchCooperativeKernelMultiDevice() sets persistent function state that is
; * the same as function state set through ::cuLaunchKernel API when called individually for each
; * element in \p launchParamsList.
; *
; * When kernels are launched via ::cuLaunchCooperativeKernelMultiDevice(), the previous
; * block shape, shared size and parameter info associated with each ::CUDA_LAUNCH_PARAMS::function
; * in \p launchParamsList is overwritten.
; *
; * Note that to use ::cuLaunchCooperativeKernelMultiDevice(), the kernels must either have
; * been compiled with toolchain version 3.2 or later so that it will
; * contain kernel parameter information, or have no kernel parameters.
; * If either of these conditions is not met, then ::cuLaunchCooperativeKernelMultiDevice() will
; * return ::CUDA_ERROR_INVALID_IMAGE.
; *
; * \param launchParamsList - List of launch parameters, one per device
; * \param numDevices       - Size of the \p launchParamsList array
; * \param flags            - Flags to control launch behavior
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_IMAGE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_LAUNCH_FAILED,
; * ::CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
; * ::CUDA_ERROR_LAUNCH_TIMEOUT,
; * ::CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
; * ::CUDA_ERROR_COOPERATIVE_LAUNCH_TOO_LARGE,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuCtxGetCacheConfig,
; * ::cuCtxSetCacheConfig,
; * ::cuFuncSetCacheConfig,
; * ::cuFuncGetAttribute,
; * ::cuLaunchCooperativeKernel,
; * ::cudaLaunchCooperativeKernelMultiDevice
; */
;API
cuLaunchCooperativeKernelMultiDevice PROTO launchParamsList:XWORD ,numDevices:DWORD ,flags:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 9000 */ 
IF  __CUDA_API_VERSION GE 10000
;/**
; * \brief Enqueues a host function call in a stream
; *
; * Enqueues a host function to run in a stream.  The function will be called
; * after currently enqueued work and will block work added after it.
; *
; * The host function must not make any CUDA API calls.  Attempting to use a
; * CUDA API may result in ::CUDA_ERROR_NOT_PERMITTED, but this is not required.
; * The host function must not perform any synchronization that may depend on
; * outstanding CUDA work not mandated to run earlier.  Host functions without a
; * mandated order (such as in independent streams) execute in undefined order
; * and may be serialized.
; *
; * For the purposes of Unified Memory, execution makes a number of guarantees:
; * <ul>
; *   <li>The stream is considered idle for the duration of the function's
; *   execution.  Thus, for example, the function may always use memory attached
; *   to the stream it was enqueued in.</li>
; *   <li>The start of execution of the function has the same effect as
; *   synchronizing an event recorded in the same stream immediately prior to
; *   the function.  It thus synchronizes streams which have been "joined"
; *   prior to the function.</li>
; *   <li>Adding device work to any stream does not have the effect of making
; *   the stream active until all preceding host functions and stream callbacks
; *   have executed.  Thus, for
; *   example, a function might use global attached memory even if work has
; *   been added to another stream, if the work has been ordered behind the
; *   function call with an event.</li>
; *   <li>Completion of the function does not cause a stream to become
; *   active except as described above.  The stream will remain idle
; *   if no device work follows the function, and will remain idle across
; *   consecutive host functions or stream callbacks without device work in
; *   between.  Thus, for example,
; *   stream synchronization can be done by signaling from a host function at the
; *   end of the stream.</li>
; * </ul>
; *
; * Note that, in contrast to ::cuStreamAddCallback, the function will not be
; * called in the event of an error in the CUDA context.
; *
; * \param hStream  - Stream to enqueue function call in
; * \param fn       - The function to call once preceding stream operations are complete
; * \param userData - User-specified data to be passed to the function
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_SUPPORTED
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuStreamCreate,
; * ::cuStreamQuery,
; * ::cuStreamSynchronize,
; * ::cuStreamWaitEvent,
; * ::cuStreamDestroy,
; * ::cuMemAllocManaged,
; * ::cuStreamAttachMemAsync,
; * ::cuStreamAddCallback
; */
;API
cuLaunchHostFunc PROTO hStream:XWORD ,fn:XWORD ,userData:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
;/**
; * \defgroup CUDA_EXEC_DEPRECATED Execution Control [DEPRECATED]
; *
; * ___MANBRIEF___ deprecated execution control functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the deprecated execution control functions of the
; * low-level CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Sets the block-dimensions for the function
; *
; * \deprecated
; *
; * Specifies the \p x, \p y, and \p z dimensions of the thread blocks that are
; * created when the kernel given by \p hfunc is launched.
; *
; * \param hfunc - Kernel to specify dimensions of
; * \param x     - X dimension
; * \param y     - Y dimension
; * \param z     - Z dimension
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuFuncSetSharedSize,
; * ::cuFuncSetCacheConfig,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSeti,
; * ::cuParamSetf,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuFuncSetBlockShape PROTO hfunc:XWORD ,X:DWORD ,Y:DWORD ,z:DWORD 
;/**
; * \brief Sets the dynamic shared-memory size for the function
; *
; * \deprecated
; *
; * Sets through \p bytes the amount of dynamic shared memory that will be
; * available to each thread block when the kernel given by \p hfunc is launched.
; *
; * \param hfunc - Kernel to specify dynamic shared-memory size for
; * \param bytes - Dynamic shared-memory size per thread in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetCacheConfig,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSeti,
; * ::cuParamSetf,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuFuncSetSharedSize PROTO hfunc:XWORD ,bytes:DWORD 
;/**
; * \brief Sets the parameter size for the function
; *
; * \deprecated
; *
; * Sets through \p numbytes the total size in bytes needed by the function
; * parameters of the kernel corresponding to \p hfunc.
; *
; * \param hfunc    - Kernel to set parameter size for
; * \param numbytes - Size of parameter list in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetf,
; * ::cuParamSeti,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuParamSetSize PROTO hfunc:XWORD ,numbytes:DWORD 
;/**
; * \brief Adds an integer parameter to the function's argument list
; *
; * \deprecated
; *
; * Sets an integer parameter that will be specified the next time the
; * kernel corresponding to \p hfunc will be invoked. \p offset is a byte offset.
; *
; * \param hfunc  - Kernel to add parameter to
; * \param offset - Offset to add parameter to argument list
; * \param value  - Value of parameter
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSetf,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuParamSeti PROTO hfunc:XWORD ,aoffset:DWORD ,value:DWORD 
;/**
; * \brief Adds a floating-point parameter to the function's argument list
; *
; * \deprecated
; *
; * Sets a floating-point parameter that will be specified the next time the
; * kernel corresponding to \p hfunc will be invoked. \p offset is a byte offset.
; *
; * \param hfunc  - Kernel to add parameter to
; * \param offset - Offset to add parameter to argument list
; * \param value  - Value of parameter
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSeti,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuParamSetf PROTO hfunc:XWORD ,aoffset:DWORD ,value:REAL4 
;/**
; * \brief Adds arbitrary data to the function's argument list
; *
; * \deprecated
; *
; * Copies an arbitrary amount of data (specified in \p numbytes) from \p ptr
; * into the parameter space of the kernel corresponding to \p hfunc. \p offset
; * is a byte offset.
; *
; * \param hfunc    - Kernel to add data to
; * \param offset   - Offset to add data to argument list
; * \param ptr      - Pointer to arbitrary data
; * \param numbytes - Size of data to copy in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSetf,
; * ::cuParamSeti,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuParamSetv PROTO hfunc:XWORD ,aoffset:DWORD ,aPtr:XWORD ,numbytes:DWORD 
;/**
; * \brief Launches a CUDA function
; *
; * \deprecated
; *
; * Invokes the kernel \p f on a 1 x 1 x 1 grid of blocks. The block
; * contains the number of threads specified by a previous call to
; * ::cuFuncSetBlockShape().
; *
; * \param f - Kernel to launch
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_LAUNCH_FAILED,
; * ::CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
; * ::CUDA_ERROR_LAUNCH_TIMEOUT,
; * ::CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSetf,
; * ::cuParamSeti,
; * ::cuParamSetv,
; * ::cuLaunchGrid,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuLaunch PROTO f:XWORD 
;/**
; * \brief Launches a CUDA function
; *
; * \deprecated
; *
; * Invokes the kernel \p f on a \p grid_width x \p grid_height grid of
; * blocks. Each block contains the number of threads specified by a previous
; * call to ::cuFuncSetBlockShape().
; *
; * \param f           - Kernel to launch
; * \param grid_width  - Width of grid in blocks
; * \param grid_height - Height of grid in blocks
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_LAUNCH_FAILED,
; * ::CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
; * ::CUDA_ERROR_LAUNCH_TIMEOUT,
; * ::CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSetf,
; * ::cuParamSeti,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGridAsync,
; * ::cuLaunchKernel
; */
;API
cuLaunchGrid PROTO f:XWORD ,grid_width:DWORD ,grid_height:DWORD 
;/**
; * \brief Launches a CUDA function
; *
; * \deprecated
; *
; * Invokes the kernel \p f on a \p grid_width x \p grid_height grid of
; * blocks. Each block contains the number of threads specified by a previous
; * call to ::cuFuncSetBlockShape().
; *
; * \param f           - Kernel to launch
; * \param grid_width  - Width of grid in blocks
; * \param grid_height - Height of grid in blocks
; * \param hStream     - Stream identifier
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_LAUNCH_FAILED,
; * ::CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
; * ::CUDA_ERROR_LAUNCH_TIMEOUT,
; * ::CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
; * ::CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
; *
; * \note In certain cases where cubins are created with no ABI (i.e., using \p ptxas \p --abi-compile \p no),
; *       this function may serialize kernel launches. In order to force the CUDA driver to retain
; *       asynchronous behavior, set the ::CU_CTX_LMEM_RESIZE_TO_MAX flag during context creation (see ::cuCtxCreate).
; *
; * \note_null_stream
; * \notefnerr
; *
; * \sa ::cuFuncSetBlockShape,
; * ::cuFuncSetSharedSize,
; * ::cuFuncGetAttribute,
; * ::cuParamSetSize,
; * ::cuParamSetf,
; * ::cuParamSeti,
; * ::cuParamSetv,
; * ::cuLaunch,
; * ::cuLaunchGrid,
; * ::cuLaunchKernel
; */
;API
cuLaunchGridAsync PROTO f:XWORD ,grid_width:DWORD ,grid_height:DWORD ,hStream:XWORD 
;/**
; * \brief Adds a texture-reference to the function's argument list
; *
; * \deprecated
; *
; * Makes the CUDA array or linear memory bound to the texture reference
; * \p hTexRef available to a device program as a texture. In this version of
; * CUDA, the texture-reference must be obtained via ::cuModuleGetTexRef() and
; * the \p texunit parameter must be set to ::CU_PARAM_TR_DEFAULT.
; *
; * \param hfunc   - Kernel to add texture-reference to
; * \param texunit - Texture unit (must be ::CU_PARAM_TR_DEFAULT)
; * \param hTexRef - Texture-reference to add to argument list
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; */
;API
cuParamSetTexRef PROTO hfunc:XWORD ,texunit:DWORD ,hTexRef:XWORD 
IF  __CUDA_API_VERSION GE 10000
;/**
; * \defgroup CUDA_GRAPH Graph Management
; *
; * ___MANBRIEF___ graph management functions of the low-level CUDA driver API
; * (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the graph management functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Creates a graph
; *
; * Creates an empty graph, which is returned via \p phGraph.
; *
; * \param phGraph - Returns newly created graph
; * \param flags   - Graph creation flags, must be 0
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphAddMemsetNode,
; * ::cuGraphInstantiate,
; * ::cuGraphDestroy,
; * ::cuGraphGetNodes,
; * ::cuGraphGetRootNodes,
; * ::cuGraphGetEdges,
; * ::cuGraphClone
; */
;API
cuGraphCreate PROTO phGraph:XWORD ,flags:DWORD 
;/**
; * \brief Creates a kernel execution node and adds it to a graph
; *
; * Creates a new kernel execution node and adds it to \p hGraph with \p numDependencies
; * dependencies specified via \p dependencies and arguments specified in \p nodeParams.
; * It is possible for \p numDependencies to be 0, in which case the node will be placed
; * at the root of the graph. \p dependencies may not have any duplicate entries.
; * A handle to the new node will be returned in \p phGraphNode.
; *
; * The CUDA_KERNEL_NODE_PARAMS structure is defined as:
; *
; * \code
; *  typedef struct CUDA_KERNEL_NODE_PARAMS_st {
; *      CUfunction func;
; *      unsigned int gridDimX;
; *      unsigned int gridDimY;
; *      unsigned int gridDimZ;
; *      unsigned int blockDimX;
; *      unsigned int blockDimY;
; *      unsigned int blockDimZ;
; *      unsigned int sharedMemBytes;
; *      void **kernelParams;
; *      void **extra;
; *  } CUDA_KERNEL_NODE_PARAMS;
; * \endcode
; *
; * When the graph is launched, the node will invoke kernel \p func on a (\p gridDimX x
; * \p gridDimY x \p gridDimZ) grid of blocks. Each block contains
; * (\p blockDimX x \p blockDimY x \p blockDimZ) threads.
; *
; * \p sharedMemBytes sets the amount of dynamic shared memory that will be
; * available to each thread block.
; *
; * Kernel parameters to \p func can be specified in one of two ways:
; *
; * 1) Kernel parameters can be specified via \p kernelParams. If the kernel has N
; * parameters, then \p kernelParams needs to be an array of N pointers. Each pointer,
; * from \p kernelParams[0] to \p kernelParams[N-1], points to the region of memory from which the actual
; * parameter will be copied. The number of kernel parameters and their offsets and sizes do not need
; * to be specified as that information is retrieved directly from the kernel's image.
; *
; * 2) Kernel parameters can also be packaged by the application into a single buffer that is passed in
; * via \p extra. This places the burden on the application of knowing each kernel
; * parameter's size and alignment/padding within the buffer. The \p extra parameter exists
; * to allow this function to take additional less commonly used arguments. \p extra specifies
; * a list of names of extra settings and their corresponding values. Each extra setting name is
; * immediately followed by the corresponding value. The list must be terminated with either NULL or
; * CU_LAUNCH_PARAM_END.
; *
; * - ::CU_LAUNCH_PARAM_END, which indicates the end of the \p extra
; *   array;
; * - ::CU_LAUNCH_PARAM_BUFFER_POINTER, which specifies that the next
; *   value in \p extra will be a pointer to a buffer
; *   containing all the kernel parameters for launching kernel
; *   \p func;
; * - ::CU_LAUNCH_PARAM_BUFFER_SIZE, which specifies that the next
; *   value in \p extra will be a pointer to a size_t
; *   containing the size of the buffer specified with
; *   ::CU_LAUNCH_PARAM_BUFFER_POINTER;
; *
; * The error ::CUDA_ERROR_INVALID_VALUE will be returned if kernel parameters are specified with both
; * \p kernelParams and \p extra (i.e. both \p kernelParams and
; * \p extra are non-NULL).
; *
; * The \p kernelParams or \p extra array, as well as the argument values it points to,
; * are copied during this call.
; *
; * \note Kernels launched using graphs must not use texture and surface references. Reading or
; *       writing through any texture or surface reference is undefined behavior.
; *       This restriction does not apply to texture and surface objects.
; *
; * \param phGraphNode     - Returns newly created node
; * \param hGraph          - Graph to which to add the node
; * \param dependencies    - Dependencies of the node
; * \param numDependencies - Number of dependencies
; * \param nodeParams      - Parameters for the GPU execution node
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuLaunchKernel,
; * ::cuGraphKernelNodeGetParams,
; * ::cuGraphKernelNodeSetParams,
; * ::cuGraphCreate,
; * ::cuGraphDestroyNode,
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphAddMemsetNode
; */
;API
cuGraphAddKernelNode PROTO phGraphNode:XWORD ,hGraph:XWORD ,dependencies:XWORD ,numDependencies:DWORD ,nodeParams:XWORD 
;/**
; * \brief Returns a kernel node's parameters
; *
; * Returns the parameters of kernel node \p hNode in \p nodeParams.
; * The \p kernelParams or \p extra array returned in \p nodeParams,
; * as well as the argument values it points to, are owned by the node.
; * This memory remains valid until the node is destroyed or its
; * parameters are modified, and should not be modified
; * directly. Use ::cuGraphKernelNodeSetParams to update the
; * parameters of this node.
; *
; * The params will contain either \p kernelParams or \p extra,
; * according to which of these was most recently set on the node.
; *
; * \param hNode      - Node to get the parameters for
; * \param nodeParams - Pointer to return the parameters
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuLaunchKernel,
; * ::cuGraphAddKernelNode,
; * ::cuGraphKernelNodeSetParams
; */
;API
cuGraphKernelNodeGetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Sets a kernel node's parameters
; *
; * Sets the parameters of kernel node \p hNode to \p nodeParams.
; *
; * \param hNode      - Node to set the parameters for
; * \param nodeParams - Parameters to copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuLaunchKernel,
; * ::cuGraphAddKernelNode,
; * ::cuGraphKernelNodeGetParams
; */
;API
cuGraphKernelNodeSetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Creates a memcpy node and adds it to a graph
; *
; * Creates a new memcpy node and adds it to \p hGraph with \p numDependencies
; * dependencies specified via \p dependencies.
; * It is possible for \p numDependencies to be 0, in which case the node will be placed
; * at the root of the graph. \p dependencies may not have any duplicate entries.
; * A handle to the new node will be returned in \p phGraphNode.
; *
; * When the graph is launched, the node will perform the memcpy described by \p copyParams.
; * See ::cuMemcpy3D() for a description of the structure and its restrictions.
; *
; * Memcpy nodes have some additional restrictions with regards to managed memory, if the
; * system contains at least one device which has a zero value for the device attribute
; * ::CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS. If one or more of the operands refer
; * to managed memory, then using the memory type ::CU_MEMORYTYPE_UNIFIED is disallowed
; * for those operand(s). The managed memory will be treated as residing on either the
; * host or the device, depending on which memory type is specified.
; *
; * \param phGraphNode     - Returns newly created node
; * \param hGraph          - Graph to which to add the node
; * \param dependencies    - Dependencies of the node
; * \param numDependencies - Number of dependencies
; * \param copyParams      - Parameters for the memory copy
; * \param ctx             - Context on which to run the node
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuMemcpy3D,
; * ::cuGraphMemcpyNodeGetParams,
; * ::cuGraphMemcpyNodeSetParams,
; * ::cuGraphCreate,
; * ::cuGraphDestroyNode,
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemsetNode
; */
;API
cuGraphAddMemcpyNode PROTO phGraphNode:XWORD ,hGraph:XWORD ,dependencies:XWORD ,numDependencies:DWORD ,copyParams:XWORD ,ctx:XWORD 
;/**
; * \brief Returns a memcpy node's parameters
; *
; * Returns the parameters of memcpy node \p hNode in \p nodeParams.
; *
; * \param hNode      - Node to get the parameters for
; * \param nodeParams - Pointer to return the parameters
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuMemcpy3D,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphMemcpyNodeSetParams
; */
;API
cuGraphMemcpyNodeGetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Sets a memcpy node's parameters
; *
; * Sets the parameters of memcpy node \p hNode to \p nodeParams.
; *
; * \param hNode      - Node to set the parameters for
; * \param nodeParams - Parameters to copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuMemcpy3D,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphMemcpyNodeGetParams
; */
;API
cuGraphMemcpyNodeSetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Creates a memset node and adds it to a graph
; *
; * Creates a new memset node and adds it to \p hGraph with \p numDependencies
; * dependencies specified via \p dependencies.
; * It is possible for \p numDependencies to be 0, in which case the node will be placed
; * at the root of the graph. \p dependencies may not have any duplicate entries.
; * A handle to the new node will be returned in \p phGraphNode.
; *
; * The element size must be 1, 2, or 4 bytes.
; * When the graph is launched, the node will perform the memset described by \p memsetParams.
; *
; * \param phGraphNode     - Returns newly created node
; * \param hGraph          - Graph to which to add the node
; * \param dependencies    - Dependencies of the node
; * \param numDependencies - Number of dependencies
; * \param memsetParams    - Parameters for the memory set
; * \param ctx             - Context on which to run the node
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_CONTEXT
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuMemsetD2D32,
; * ::cuGraphMemsetNodeGetParams,
; * ::cuGraphMemsetNodeSetParams,
; * ::cuGraphCreate,
; * ::cuGraphDestroyNode,
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemcpyNode
; */
;API
cuGraphAddMemsetNode PROTO phGraphNode:XWORD ,hGraph:XWORD ,dependencies:XWORD ,numDependencies:DWORD ,memsetParams:XWORD ,ctx:XWORD 
;/**
; * \brief Returns a memset node's parameters
; *
; * Returns the parameters of memset node \p hNode in \p nodeParams.
; *
; * \param hNode      - Node to get the parameters for
; * \param nodeParams - Pointer to return the parameters
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuMemsetD2D32,
; * ::cuGraphAddMemsetNode,
; * ::cuGraphMemsetNodeSetParams
; */
;API
cuGraphMemsetNodeGetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Sets a memset node's parameters
; *
; * Sets the parameters of memset node \p hNode to \p nodeParams.
; *
; * \param hNode      - Node to set the parameters for
; * \param nodeParams - Parameters to copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuMemsetD2D32,
; * ::cuGraphAddMemsetNode,
; * ::cuGraphMemsetNodeGetParams
; */
;API
cuGraphMemsetNodeSetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Creates a host execution node and adds it to a graph
; *
; * Creates a new CPU execution node and adds it to \p hGraph with \p numDependencies
; * dependencies specified via \p dependencies and arguments specified in \p nodeParams.
; * It is possible for \p numDependencies to be 0, in which case the node will be placed
; * at the root of the graph. \p dependencies may not have any duplicate entries.
; * A handle to the new node will be returned in \p phGraphNode.
; *
; * When the graph is launched, the node will invoke the specified CPU function.
; * Host nodes are not supported under MPS with pre-Volta GPUs.
; *
; * \param phGraphNode     - Returns newly created node
; * \param hGraph          - Graph to which to add the node
; * \param dependencies    - Dependencies of the node
; * \param numDependencies - Number of dependencies
; * \param nodeParams      - Parameters for the host node
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_NOT_SUPPORTED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuLaunchHostFunc,
; * ::cuGraphHostNodeGetParams,
; * ::cuGraphHostNodeSetParams,
; * ::cuGraphCreate,
; * ::cuGraphDestroyNode,
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphAddMemsetNode
; */
;API
cuGraphAddHostNode PROTO phGraphNode:XWORD ,hGraph:XWORD ,dependencies:XWORD ,numDependencies:DWORD ,nodeParams:XWORD 
;/**
; * \brief Returns a host node's parameters
; *
; * Returns the parameters of host node \p hNode in \p nodeParams.
; *
; * \param hNode      - Node to get the parameters for
; * \param nodeParams - Pointer to return the parameters
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuLaunchHostFunc,
; * ::cuGraphAddHostNode,
; * ::cuGraphHostNodeSetParams
; */
;API
cuGraphHostNodeGetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Sets a host node's parameters
; *
; * Sets the parameters of host node \p hNode to \p nodeParams.
; *
; * \param hNode      - Node to set the parameters for
; * \param nodeParams - Parameters to copy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuLaunchHostFunc,
; * ::cuGraphAddHostNode,
; * ::cuGraphHostNodeGetParams
; */
;API
cuGraphHostNodeSetParams PROTO hNode:XWORD ,nodeParams:XWORD 
;/**
; * \brief Creates a child graph node and adds it to a graph
; *
; * Creates a new node which executes an embedded graph, and adds it to \p hGraph with
; * \p numDependencies dependencies specified via \p dependencies.
; * It is possible for \p numDependencies to be 0, in which case the node will be placed
; * at the root of the graph. \p dependencies may not have any duplicate entries.
; * A handle to the new node will be returned in \p phGraphNode.
; *
; * The node executes an embedded child graph. The child graph is cloned in this call.
; *
; * \param phGraphNode     - Returns newly created node
; * \param hGraph          - Graph to which to add the node
; * \param dependencies    - Dependencies of the node
; * \param numDependencies - Number of dependencies
; * \param childGraph      - The graph to clone into this node
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphChildGraphNodeGetGraph,
; * ::cuGraphCreate,
; * ::cuGraphDestroyNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphAddMemsetNode,
; * ::cuGraphClone
; */
;API
cuGraphAddChildGraphNode PROTO phGraphNode:XWORD ,hGraph:XWORD ,dependencies:XWORD ,numDependencies:DWORD ,childGraph:XWORD 
;/**
; * \brief Gets a handle to the embedded graph of a child graph node
; *
; * Gets a handle to the embedded graph in a child graph node. This call
; * does not clone the graph. Changes to the graph will be reflected in
; * the node, and the node retains ownership of the graph.
; *
; * \param hNode   - Node to get the embedded graph for
; * \param phGraph - Location to store a handle to the graph
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphNodeFindInClone
; */
;API
cuGraphChildGraphNodeGetGraph PROTO hNode:XWORD ,phGraph:XWORD 
;/**
; * \brief Creates an empty node and adds it to a graph
; *
; * Creates a new node which performs no operation, and adds it to \p hGraph with
; * \p numDependencies dependencies specified via \p dependencies.
; * It is possible for \p numDependencies to be 0, in which case the node will be placed
; * at the root of the graph. \p dependencies may not have any duplicate entries.
; * A handle to the new node will be returned in \p phGraphNode.
; *
; * An empty node performs no operation during execution, but can be used for
; * transitive ordering. For example, a phased execution graph with 2 groups of n
; * nodes with a barrier between them can be represented using an empty node and
; * 2*n dependency edges, rather than no empty node and n^2 dependency edges.
; *
; * \param phGraphNode     - Returns newly created node
; * \param hGraph          - Graph to which to add the node
; * \param dependencies    - Dependencies of the node
; * \param numDependencies - Number of dependencies
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphCreate,
; * ::cuGraphDestroyNode,
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphAddMemsetNode
; */
;API
cuGraphAddEmptyNode PROTO phGraphNode:XWORD ,hGraph:XWORD ,dependencies:XWORD ,numDependencies:DWORD 
;/**
; * \brief Clones a graph
; *
; * This function creates a copy of \p originalGraph and returns it in \p * phGraphClone.
; * All parameters are copied into the cloned graph. The original graph may be modified
; * after this call without affecting the clone.
; *
; * Child graph nodes in the original graph are recursively copied into the clone.
; *
; * \param phGraphClone  - Returns newly created cloned graph
; * \param originalGraph - Graph to clone
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_OUT_OF_MEMORY
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphCreate,
; * ::cuGraphNodeFindInClone
; */
;API
cuGraphClone PROTO phGraphClone:XWORD ,originalGraph:XWORD 
;/**
; * \brief Finds a cloned version of a node
; *
; * This function returns the node in \p hClonedGraph corresponding to \p hOriginalNode
; * in the original graph.
; *
; * \p hClonedGraph must have been cloned from \p hOriginalGraph via ::cuGraphClone.
; * \p hOriginalNode must have been in \p hOriginalGraph at the time of the call to
; * ::cuGraphClone, and the corresponding cloned node in \p hClonedGraph must not have
; * been removed. The cloned node is then returned via \p phClonedNode.
; *
; * \param phNode  - Returns handle to the cloned node
; * \param hOriginalNode - Handle to the original node
; * \param hClonedGraph - Cloned graph to query
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphClone
; */
;API
cuGraphNodeFindInClone PROTO phNode:XWORD ,hOriginalNode:XWORD ,hClonedGraph:XWORD 
;/**
; * \brief Returns a node's type
; *
; * Returns the node type of \p hNode in \p type.
; *
; * \param hNode - Node to query
; * \param type  - Pointer to return the node type
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphGetNodes,
; * ::cuGraphGetRootNodes,
; * ::cuGraphChildGraphNodeGetGraph,
; * ::cuGraphKernelNodeGetParams,
; * ::cuGraphKernelNodeSetParams,
; * ::cuGraphHostNodeGetParams,
; * ::cuGraphHostNodeSetParams,
; * ::cuGraphMemcpyNodeGetParams,
; * ::cuGraphMemcpyNodeSetParams,
; * ::cuGraphMemsetNodeGetParams,
; * ::cuGraphMemsetNodeSetParams
; */
;API
cuGraphNodeGetType PROTO hNode:XWORD ,atype:XWORD 
;/**
; * \brief Returns a graph's nodes
; *
; * Returns a list of \p hGraph's nodes. \p nodes may be NULL, in which case this
; * function will return the number of nodes in \p numNodes. Otherwise,
; * \p numNodes entries will be filled in. If \p numNodes is higher than the actual
; * number of nodes, the remaining entries in \p nodes will be set to NULL, and the
; * number of nodes actually obtained will be returned in \p numNodes.
; *
; * \param hGraph   - Graph to query
; * \param nodes    - Pointer to return the nodes
; * \param numNodes - See description
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphCreate,
; * ::cuGraphGetRootNodes,
; * ::cuGraphGetEdges,
; * ::cuGraphNodeGetType,
; * ::cuGraphNodeGetDependencies,
; * ::cuGraphNodeGetDependentNodes
; */
;API
cuGraphGetNodes PROTO hGraph:XWORD ,nodes:XWORD ,numNodes:XWORD 
;/**
; * \brief Returns a graph's root nodes
; *
; * Returns a list of \p hGraph's root nodes. \p rootNodes may be NULL, in which case this
; * function will return the number of root nodes in \p numRootNodes. Otherwise,
; * \p numRootNodes entries will be filled in. If \p numRootNodes is higher than the actual
; * number of root nodes, the remaining entries in \p rootNodes will be set to NULL, and the
; * number of nodes actually obtained will be returned in \p numRootNodes.
; *
; * \param hGraph       - Graph to query
; * \param rootNodes    - Pointer to return the root nodes
; * \param numRootNodes - See description
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphCreate,
; * ::cuGraphGetNodes,
; * ::cuGraphGetEdges,
; * ::cuGraphNodeGetType,
; * ::cuGraphNodeGetDependencies,
; * ::cuGraphNodeGetDependentNodes
; */
;API
cuGraphGetRootNodes PROTO hGraph:XWORD ,rootNodes:XWORD ,numRootNodes:XWORD 
;/**
; * \brief Returns a graph's dependency edges
; *
; * Returns a list of \p hGraph's dependency edges. Edges are returned via corresponding
; * indices in \p from and \p to; that is, the node in \p to[i] has a dependency on the
; * node in \p from[i]. \p from and \p to may both be NULL, in which
; * case this function only returns the number of edges in \p numEdges. Otherwise,
; * \p numEdges entries will be filled in. If \p numEdges is higher than the actual
; * number of edges, the remaining entries in \p from and \p to will be set to NULL, and
; * the number of edges actually returned will be written to \p numEdges.
; *
; * \param hGraph   - Graph to get the edges from
; * \param from     - Location to return edge endpoints
; * \param to       - Location to return edge endpoints
; * \param numEdges - See description
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphGetNodes,
; * ::cuGraphGetRootNodes,
; * ::cuGraphAddDependencies,
; * ::cuGraphRemoveDependencies,
; * ::cuGraphNodeGetDependencies,
; * ::cuGraphNodeGetDependentNodes
; */
;API
cuGraphGetEdges PROTO hGraph:XWORD ,from:XWORD ,to:XWORD ,numEdges:XWORD 
;/**
; * \brief Returns a node's dependencies
; *
; * Returns a list of \p node's dependencies. \p dependencies may be NULL, in which case this
; * function will return the number of dependencies in \p numDependencies. Otherwise,
; * \p numDependencies entries will be filled in. If \p numDependencies is higher than the actual
; * number of dependencies, the remaining entries in \p dependencies will be set to NULL, and the
; * number of nodes actually obtained will be returned in \p numDependencies.
; *
; * \param hNode           - Node to query
; * \param dependencies    - Pointer to return the dependencies
; * \param numDependencies - See description
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphNodeGetDependentNodes,
; * ::cuGraphGetNodes,
; * ::cuGraphGetRootNodes,
; * ::cuGraphGetEdges,
; * ::cuGraphAddDependencies,
; * ::cuGraphRemoveDependencies
; */
;API
cuGraphNodeGetDependencies PROTO hNode:XWORD ,dependencies:XWORD ,numDependencies:XWORD 
;/**
; * \brief Returns a node's dependent nodes
; *
; * Returns a list of \p node's dependent nodes. \p dependentNodes may be NULL, in which
; * case this function will return the number of dependent nodes in \p numDependentNodes.
; * Otherwise, \p numDependentNodes entries will be filled in. If \p numDependentNodes is
; * higher than the actual number of dependent nodes, the remaining entries in
; * \p dependentNodes will be set to NULL, and the number of nodes actually obtained will
; * be returned in \p numDependentNodes.
; *
; * \param hNode             - Node to query
; * \param dependentNodes    - Pointer to return the dependent nodes
; * \param numDependentNodes - See description
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphNodeGetDependencies,
; * ::cuGraphGetNodes,
; * ::cuGraphGetRootNodes,
; * ::cuGraphGetEdges,
; * ::cuGraphAddDependencies,
; * ::cuGraphRemoveDependencies
; */
;API
cuGraphNodeGetDependentNodes PROTO hNode:XWORD ,dependentNodes:XWORD ,numDependentNodes:XWORD 
;/**
; * \brief Adds dependency edges to a graph
; *
; * The number of dependencies to be added is defined by \p numDependencies
; * Elements in \p from and \p to at corresponding indices define a dependency.
; * Each node in \p from and \p to must belong to \p hGraph.
; *
; * If \p numDependencies is 0, elements in \p from and \p to will be ignored.
; * Specifying an existing dependency will return an error.
; *
; * \param hGraph - Graph to which dependencies are added
; * \param from - Array of nodes that provide the dependencies
; * \param to - Array of dependent nodes
; * \param numDependencies - Number of dependencies to be added
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphRemoveDependencies,
; * ::cuGraphGetEdges,
; * ::cuGraphNodeGetDependencies,
; * ::cuGraphNodeGetDependentNodes
; */
;API
cuGraphAddDependencies PROTO hGraph:XWORD ,from:XWORD ,to:XWORD ,numDependencies:DWORD 
;/**
; * \brief Removes dependency edges from a graph
; *
; * The number of \p dependencies to be removed is defined by \p numDependencies.
; * Elements in \p from and \p to at corresponding indices define a dependency.
; * Each node in \p from and \p to must belong to \p hGraph.
; *
; * If \p numDependencies is 0, elements in \p from and \p to will be ignored.
; * Specifying a non-existing dependency will return an error.
; *
; * \param hGraph - Graph from which to remove dependencies
; * \param from - Array of nodes that provide the dependencies
; * \param to - Array of dependent nodes
; * \param numDependencies - Number of dependencies to be removed
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphAddDependencies,
; * ::cuGraphGetEdges,
; * ::cuGraphNodeGetDependencies,
; * ::cuGraphNodeGetDependentNodes
; */
;API
cuGraphRemoveDependencies PROTO hGraph:XWORD ,from:XWORD ,to:XWORD ,numDependencies:DWORD 
;/**
; * \brief Remove a node from the graph
; *
; * Removes \p hNode from its graph. This operation also severs any dependencies of other nodes
; * on \p hNode and vice versa.
; *
; * \param hNode  - Node to remove
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphAddChildGraphNode,
; * ::cuGraphAddEmptyNode,
; * ::cuGraphAddKernelNode,
; * ::cuGraphAddHostNode,
; * ::cuGraphAddMemcpyNode,
; * ::cuGraphAddMemsetNode
; */
;API
cuGraphDestroyNode PROTO hNode:XWORD 
;/**
; * \brief Creates an executable graph from a graph
; *
; * Instantiates \p hGraph as an executable graph. The graph is validated for any
; * structural constraints or intra-node constraints which were not previously
; * validated. If instantiation is successful, a handle to the instantiated graph
; * is returned in \p graphExec.
; *
; * If there are any errors, diagnostic information may be returned in \p errorNode and
; * \p logBuffer. This is the primary way to inspect instantiation errors. The output
; * will be null terminated unless the diagnostics overflow
; * the buffer. In this case, they will be truncated, and the last byte can be
; * inspected to determine if truncation occurred.
; *
; * \param phGraphExec - Returns instantiated graph
; * \param hGraph      - Graph to instantiate
; * \param phErrorNode - In case of an instantiation error, this may be modified to
; *                      indicate a node contributing to the error
; * \param logBuffer   - A character buffer to store diagnostic messages
; * \param bufferSize  - Size of the log buffer in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphCreate,
; * ::cuGraphLaunch,
; * ::cuGraphExecDestroy
; */
;API
cuGraphInstantiate PROTO phGraphExec:XWORD ,hGraph:XWORD ,phErrorNode:XWORD ,logBuffer:XWORD ,bufferSize:DWORD 
IF  __CUDA_API_VERSION GE 10010
;/**
; * \brief Sets the parameters for a kernel node in the given graphExec
; *
; * Sets the parameters of a kernel node in an executable graph \p hGraphExec. 
; * The node is identified by the corresponding node \p hNode in the 
; * non-executable graph, from which the executable graph was instantiated. 
; *
; * \p hNode must not have been removed from the original graph. The \p func field 
; * of \p nodeParams cannot be modified and must match the original value.
; * All other values can be modified. 
; *
; * The modifications take effect at the next launch of \p hGraphExec. Already 
; * enqueued or running launches of \p hGraphExec are not affected by this call. 
; * \p hNode is also not modified by this call.
; *
; * \param hGraphExec  - The executable graph in which to set the specified node
; * \param hNode       - kernel node from the graph from which graphExec was instantiated
; * \param nodeParams  - Updated Parameters to set
; * 
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_INVALID_VALUE,
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphAddKernelNode,
; * ::cuGraphKernelNodeSetParams,
; * ::cuGraphInstantiate
; */
;API
cuGraphExecKernelNodeSetParams PROTO hGraphExec:XWORD ,hNode:XWORD ,nodeParams:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10010 */ 
;/**
; * \brief Launches an executable graph in a stream
; *
; * Executes \p hGraphExec in \p hStream. Only one instance of \p hGraphExec may be executing
; * at a time. Each launch is ordered behind both any previous work in \p hStream
; * and any previous launches of \p hGraphExec. To execute a graph concurrently, it must be
; * instantiated multiple times into multiple executable graphs.
; *
; * \param hGraphExec - Executable graph to launch
; * \param hStream    - Stream in which to launch the graph
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphInstantiate,
; * ::cuGraphExecDestroy
; */
;API
cuGraphLaunch PROTO hGraphExec:XWORD ,hStream:XWORD 
;/**
; * \brief Destroys an executable graph
; *
; * Destroys the executable graph specified by \p hGraphExec, as well
; * as all of its executable nodes. If the executable graph is
; * in-flight, it will not be terminated, but rather freed
; * asynchronously on completion.
; *
; * \param hGraphExec - Executable graph to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphInstantiate,
; * ::cuGraphLaunch
; */
;API
cuGraphExecDestroy PROTO hGraphExec:XWORD 
;/**
; * \brief Destroys a graph
; *
; * Destroys the graph specified by \p hGraph, as well as all of its nodes.
; *
; * \param hGraph - Graph to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \note_graph_thread_safety
; * \notefnerr
; *
; * \sa
; * ::cuGraphCreate
; */
;API
cuGraphDestroy PROTO hGraph:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 10000 */ 
IF  __CUDA_API_VERSION GE 6050
;/**
; * \defgroup CUDA_OCCUPANCY Occupancy
; *
; * ___MANBRIEF___ occupancy calculation functions of the low-level CUDA driver
; * API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the occupancy calculation functions of the low-level CUDA
; * driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Returns occupancy of a function
; *
; * Returns in \p *numBlocks the number of the maximum active blocks per
; * streaming multiprocessor.
; *
; * \param numBlocks       - Returned occupancy
; * \param func            - Kernel for which occupancy is calculated
; * \param blockSize       - Block size the kernel is intended to be launched with
; * \param dynamicSMemSize - Per-block dynamic shared memory usage intended, in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa
; * ::cudaOccupancyMaxActiveBlocksPerMultiprocessor
; */
;API
cuOccupancyMaxActiveBlocksPerMultiprocessor PROTO numBlocks:XWORD ,func:XWORD ,blockSize:DWORD ,dynamicSMemSize:DWORD 
;/**
; * \brief Returns occupancy of a function
; *
; * Returns in \p *numBlocks the number of the maximum active blocks per
; * streaming multiprocessor.
; *
; * The \p Flags parameter controls how special cases are handled. The
; * valid flags are:
; *
; * - ::CU_OCCUPANCY_DEFAULT, which maintains the default behavior as
; *   ::cuOccupancyMaxActiveBlocksPerMultiprocessor;
; *
; * - ::CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE, which suppresses the
; *   default behavior on platform where global caching affects
; *   occupancy. On such platforms, if caching is enabled, but
; *   per-block SM resource usage would result in zero occupancy, the
; *   occupancy calculator will calculate the occupancy as if caching
; *   is disabled. Setting ::CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE makes
; *   the occupancy calculator to return 0 in such cases. More information
; *   can be found about this feature in the "Unified L1/Texture Cache"
; *   section of the Maxwell tuning guide.
; *
; * \param numBlocks       - Returned occupancy
; * \param func            - Kernel for which occupancy is calculated
; * \param blockSize       - Block size the kernel is intended to be launched with
; * \param dynamicSMemSize - Per-block dynamic shared memory usage intended, in bytes
; * \param flags           - Requested behavior for the occupancy calculator
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa
; * ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
; */
;API
cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags PROTO numBlocks:XWORD ,func:XWORD ,blockSize:DWORD ,dynamicSMemSize:DWORD ,flags:DWORD 
;/**
; * \brief Suggest a launch configuration with reasonable occupancy
; *
; * Returns in \p *blockSize a reasonable block size that can achieve
; * the maximum occupancy (or, the maximum number of active warps with
; * the fewest blocks per multiprocessor), and in \p *minGridSize the
; * minimum grid size to achieve the maximum occupancy.
; *
; * If \p blockSizeLimit is 0, the configurator will use the maximum
; * block size permitted by the device / function instead.
; *
; * If per-block dynamic shared memory allocation is not needed, the
; * user should leave both \p blockSizeToDynamicSMemSize and \p
; * dynamicSMemSize as 0.
; *
; * If per-block dynamic shared memory allocation is needed, then if
; * the dynamic shared memory size is constant regardless of block
; * size, the size should be passed through \p dynamicSMemSize, and \p
; * blockSizeToDynamicSMemSize should be NULL.
; *
; * Otherwise, if the per-block dynamic shared memory size varies with
; * different block sizes, the user needs to provide a unary function
; * through \p blockSizeToDynamicSMemSize that computes the dynamic
; * shared memory needed by \p func for any given block size. \p
; * dynamicSMemSize is ignored. An example signature is:
; *
; * \code
; *    // Take block size, returns dynamic shared memory needed
; *    size_t blockToSmem(int blockSize);
; * \endcode
; *
; * \param minGridSize - Returned minimum grid size needed to achieve the maximum occupancy
; * \param blockSize   - Returned maximum block size that can achieve the maximum occupancy
; * \param func        - Kernel for which launch configuration is calculated
; * \param blockSizeToDynamicSMemSize - A function that calculates how much per-block dynamic shared memory \p func uses based on the block size
; * \param dynamicSMemSize - Dynamic shared memory usage intended, in bytes
; * \param blockSizeLimit  - The maximum block size \p func is designed to handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa
; * ::cudaOccupancyMaxPotentialBlockSize
; */
;API
cuOccupancyMaxPotentialBlockSize PROTO minGridSize:XWORD ,blockSize:XWORD ,func:XWORD ,blockSizeToDynamicSMemSize:XWORD ,dynamicSMemSize:DWORD ,blockSizeLimit:DWORD 
;/**
; * \brief Suggest a launch configuration with reasonable occupancy
; *
; * An extended version of ::cuOccupancyMaxPotentialBlockSize. In
; * addition to arguments passed to ::cuOccupancyMaxPotentialBlockSize,
; * ::cuOccupancyMaxPotentialBlockSizeWithFlags also takes a \p Flags
; * parameter.
; *
; * The \p Flags parameter controls how special cases are handled. The
; * valid flags are:
; *
; * - ::CU_OCCUPANCY_DEFAULT, which maintains the default behavior as
; *   ::cuOccupancyMaxPotentialBlockSize;
; *
; * - ::CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE, which suppresses the
; *   default behavior on platform where global caching affects
; *   occupancy. On such platforms, the launch configurations that
; *   produces maximal occupancy might not support global
; *   caching. Setting ::CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE
; *   guarantees that the the produced launch configuration is global
; *   caching compatible at a potential cost of occupancy. More information
; *   can be found about this feature in the "Unified L1/Texture Cache"
; *   section of the Maxwell tuning guide.
; *
; * \param minGridSize - Returned minimum grid size needed to achieve the maximum occupancy
; * \param blockSize   - Returned maximum block size that can achieve the maximum occupancy
; * \param func        - Kernel for which launch configuration is calculated
; * \param blockSizeToDynamicSMemSize - A function that calculates how much per-block dynamic shared memory \p func uses based on the block size
; * \param dynamicSMemSize - Dynamic shared memory usage intended, in bytes
; * \param blockSizeLimit  - The maximum block size \p func is designed to handle
; * \param flags       - Options
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa
; * ::cudaOccupancyMaxPotentialBlockSizeWithFlags
; */
;API
cuOccupancyMaxPotentialBlockSizeWithFlags PROTO minGridSize:XWORD ,blockSize:XWORD ,func:XWORD ,blockSizeToDynamicSMemSize:XWORD ,dynamicSMemSize:DWORD ,blockSizeLimit:DWORD ,flags:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 6050 */ 
;/**
; * \defgroup CUDA_TEXREF_DEPRECATED Texture Reference Management [DEPRECATED]
; *
; * ___MANBRIEF___ deprecated texture reference management functions of the
; * low-level CUDA driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the deprecated texture reference management
; * functions of the low-level CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Binds an array as a texture reference
; *
; * \deprecated
; *
; * Binds the CUDA array \p hArray to the texture reference \p hTexRef. Any
; * previous address or CUDA array state associated with the texture reference
; * is superseded by this function. \p Flags must be set to
; * ::CU_TRSA_OVERRIDE_FORMAT. Any CUDA array previously bound to \p hTexRef is
; * unbound.
; *
; * \param hTexRef - Texture reference to bind
; * \param hArray  - Array to bind
; * \param Flags   - Options (must be ::CU_TRSA_OVERRIDE_FORMAT)
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToArray
; */
;API
cuTexRefSetArray PROTO hTexRef:XWORD ,hArray:XWORD ,Flags:DWORD 
;/**
; * \brief Binds a mipmapped array to a texture reference
; *
; * \deprecated
; *
; * Binds the CUDA mipmapped array \p hMipmappedArray to the texture reference \p hTexRef.
; * Any previous address or CUDA array state associated with the texture reference
; * is superseded by this function. \p Flags must be set to ::CU_TRSA_OVERRIDE_FORMAT.
; * Any CUDA array previously bound to \p hTexRef is unbound.
; *
; * \param hTexRef         - Texture reference to bind
; * \param hMipmappedArray - Mipmapped array to bind
; * \param Flags           - Options (must be ::CU_TRSA_OVERRIDE_FORMAT)
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetMipmappedArray PROTO hTexRef:XWORD ,hMipmappedArray:XWORD ,Flags:DWORD 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Binds an address as a texture reference
; *
; * \deprecated
; *
; * Binds a linear address range to the texture reference \p hTexRef. Any
; * previous address or CUDA array state associated with the texture reference
; * is superseded by this function. Any memory previously bound to \p hTexRef
; * is unbound.
; *
; * Since the hardware enforces an alignment requirement on texture base
; * addresses, ::cuTexRefSetAddress() passes back a byte offset in
; * \p *ByteOffset that must be applied to texture fetches in order to read from
; * the desired memory. This offset must be divided by the texel size and
; * passed to kernels that read from the texture so they can be applied to the
; * ::tex1Dfetch() function.
; *
; * If the device memory pointer was returned from ::cuMemAlloc(), the offset
; * is guaranteed to be 0 and NULL may be passed as the \p ByteOffset parameter.
; *
; * The total number of elements (or texels) in the linear address range
; * cannot exceed ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH.
; * The number of elements is computed as (\p bytes / bytesPerElement),
; * where bytesPerElement is determined from the data format and number of
; * components set using ::cuTexRefSetFormat().
; *
; * \param ByteOffset - Returned byte offset
; * \param hTexRef    - Texture reference to bind
; * \param dptr       - Device pointer to bind
; * \param bytes      - Size of memory to bind in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTexture
; */
;API
cuTexRefSetAddress PROTO ByteOffset:XWORD ,hTexRef:XWORD ,dptr:CUdeviceptr ,bytes:DWORD 
;/**
; * \brief Binds an address as a 2D texture reference
; *
; * \deprecated
; *
; * Binds a linear address range to the texture reference \p hTexRef. Any
; * previous address or CUDA array state associated with the texture reference
; * is superseded by this function. Any memory previously bound to \p hTexRef
; * is unbound.
; *
; * Using a ::tex2D() function inside a kernel requires a call to either
; * ::cuTexRefSetArray() to bind the corresponding texture reference to an
; * array, or ::cuTexRefSetAddress2D() to bind the texture reference to linear
; * memory.
; *
; * Function calls to ::cuTexRefSetFormat() cannot follow calls to
; * ::cuTexRefSetAddress2D() for the same texture reference.
; *
; * It is required that \p dptr be aligned to the appropriate hardware-specific
; * texture alignment. You can query this value using the device attribute
; * ::CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT. If an unaligned \p dptr is
; * supplied, ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; * \p Pitch has to be aligned to the hardware-specific texture pitch alignment.
; * This value can be queried using the device attribute
; * ::CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT. If an unaligned \p Pitch is
; * supplied, ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; * Width and Height, which are specified in elements (or texels), cannot exceed
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH and
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT respectively.
; * \p Pitch, which is specified in bytes, cannot exceed
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH.
; *
; * \param hTexRef - Texture reference to bind
; * \param desc    - Descriptor of CUDA array
; * \param dptr    - Device pointer to bind
; * \param Pitch   - Line pitch in bytes
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTexture2D
; */
;API
cuTexRefSetAddress2D PROTO hTexRef:XWORD ,desc:XWORD ,dptr:CUdeviceptr ,Pitch:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Sets the format for a texture reference
; *
; * \deprecated
; *
; * Specifies the format of the data to be read by the texture reference
; * \p hTexRef. \p fmt and \p NumPackedComponents are exactly analogous to the
; * ::Format and ::NumChannels members of the ::CUDA_ARRAY_DESCRIPTOR structure:
; * They specify the format of each component and the number of components per
; * array element.
; *
; * \param hTexRef             - Texture reference
; * \param fmt                 - Format to set
; * \param NumPackedComponents - Number of components per array element
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaCreateChannelDesc,
; * ::cudaBindTexture,
; * ::cudaBindTexture2D,
; * ::cudaBindTextureToArray,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetFormat PROTO hTexRef:XWORD ,fmt:CUarray_format ,NumPackedComponents:DWORD 
;/**
; * \brief Sets the addressing mode for a texture reference
; *
; * \deprecated
; *
; * Specifies the addressing mode \p am for the given dimension \p dim of the
; * texture reference \p hTexRef. If \p dim is zero, the addressing mode is
; * applied to the first parameter of the functions used to fetch from the
; * texture; if \p dim is 1, the second, and so on. ::CUaddress_mode is defined
; * as:
; * \code
;   typedef enum CUaddress_mode_enum {
;      CU_TR_ADDRESS_MODE_WRAP = 0,
;      CU_TR_ADDRESS_MODE_CLAMP = 1,
;      CU_TR_ADDRESS_MODE_MIRROR = 2,
;      CU_TR_ADDRESS_MODE_BORDER = 3
;   } CUaddress_mode;
; * \endcode
; *
; * Note that this call has no effect if \p hTexRef is bound to linear memory.
; * Also, if the flag, ::CU_TRSF_NORMALIZED_COORDINATES, is not set, the only
; * supported address mode is ::CU_TR_ADDRESS_MODE_CLAMP.
; *
; * \param hTexRef - Texture reference
; * \param dim     - Dimension
; * \param am      - Addressing mode to set
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTexture,
; * ::cudaBindTexture2D,
; * ::cudaBindTextureToArray,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetAddressMode PROTO hTexRef:XWORD ,dim:DWORD ,am:CUaddress_mode 
;/**
; * \brief Sets the filtering mode for a texture reference
; *
; * \deprecated
; *
; * Specifies the filtering mode \p fm to be used when reading memory through
; * the texture reference \p hTexRef. ::CUfilter_mode_enum is defined as:
; *
; * \code
;   typedef enum CUfilter_mode_enum {
;      CU_TR_FILTER_MODE_POINT = 0,
;      CU_TR_FILTER_MODE_LINEAR = 1
;   } CUfilter_mode;
; * \endcode
; *
; * Note that this call has no effect if \p hTexRef is bound to linear memory.
; *
; * \param hTexRef - Texture reference
; * \param fm      - Filtering mode to set
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToArray
; */
;API
cuTexRefSetFilterMode PROTO hTexRef:XWORD ,fm:CUfilter_mode 
;/**
; * \brief Sets the mipmap filtering mode for a texture reference
; *
; * \deprecated
; *
; * Specifies the mipmap filtering mode \p fm to be used when reading memory through
; * the texture reference \p hTexRef. ::CUfilter_mode_enum is defined as:
; *
; * \code
;   typedef enum CUfilter_mode_enum {
;      CU_TR_FILTER_MODE_POINT = 0,
;      CU_TR_FILTER_MODE_LINEAR = 1
;   } CUfilter_mode;
; * \endcode
; *
; * Note that this call has no effect if \p hTexRef is not bound to a mipmapped array.
; *
; * \param hTexRef - Texture reference
; * \param fm      - Filtering mode to set
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetMipmapFilterMode PROTO hTexRef:XWORD ,fm:CUfilter_mode 
;/**
; * \brief Sets the mipmap level bias for a texture reference
; *
; * \deprecated
; *
; * Specifies the mipmap level bias \p bias to be added to the specified mipmap level when
; * reading memory through the texture reference \p hTexRef.
; *
; * Note that this call has no effect if \p hTexRef is not bound to a mipmapped array.
; *
; * \param hTexRef - Texture reference
; * \param bias    - Mipmap level bias
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetMipmapLevelBias PROTO hTexRef:XWORD ,bias:REAL4 
;/**
; * \brief Sets the mipmap min/max mipmap level clamps for a texture reference
; *
; * \deprecated
; *
; * Specifies the min/max mipmap level clamps, \p minMipmapLevelClamp and \p maxMipmapLevelClamp
; * respectively, to be used when reading memory through the texture reference
; * \p hTexRef.
; *
; * Note that this call has no effect if \p hTexRef is not bound to a mipmapped array.
; *
; * \param hTexRef        - Texture reference
; * \param minMipmapLevelClamp - Mipmap min level clamp
; * \param maxMipmapLevelClamp - Mipmap max level clamp
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetMipmapLevelClamp PROTO hTexRef:XWORD ,minMipmapLevelClamp:REAL4 ,maxMipmapLevelClamp:REAL4 
;/**
; * \brief Sets the maximum anisotropy for a texture reference
; *
; * \deprecated
; *
; * Specifies the maximum anisotropy \p maxAniso to be used when reading memory through
; * the texture reference \p hTexRef.
; *
; * Note that this call has no effect if \p hTexRef is bound to linear memory.
; *
; * \param hTexRef  - Texture reference
; * \param maxAniso - Maximum anisotropy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTextureToArray,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetMaxAnisotropy PROTO hTexRef:XWORD ,maxAniso:DWORD 
;/**
; * \brief Sets the border color for a texture reference
; *
; * \deprecated
; *
; * Specifies the value of the RGBA color via the \p pBorderColor to the texture reference
; * \p hTexRef. The color value supports only float type and holds color components in
; * the following sequence:
; * pBorderColor[0] holds 'R' component
; * pBorderColor[1] holds 'G' component
; * pBorderColor[2] holds 'B' component
; * pBorderColor[3] holds 'A' component
; *
; * Note that the color values can be set only when the Address mode is set to
; * CU_TR_ADDRESS_MODE_BORDER using ::cuTexRefSetAddressMode.
; * Applications using integer border color values have to "reinterpret_cast" their values to float.
; *
; * \param hTexRef       - Texture reference
; * \param pBorderColor  - RGBA color
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddressMode,
; * ::cuTexRefGetAddressMode, ::cuTexRefGetBorderColor,
; * ::cudaBindTexture,
; * ::cudaBindTexture2D,
; * ::cudaBindTextureToArray,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetBorderColor PROTO hTexRef:XWORD ,pBorderColor:XWORD 
;/**
; * \brief Sets the flags for a texture reference
; *
; * \deprecated
; *
; * Specifies optional flags via \p Flags to specify the behavior of data
; * returned through the texture reference \p hTexRef. The valid flags are:
; *
; * - ::CU_TRSF_READ_AS_INTEGER, which suppresses the default behavior of
; *   having the texture promote integer data to floating point data in the
; *   range [0, 1]. Note that texture with 32-bit integer format
; *   would not be promoted, regardless of whether or not this
; *   flag is specified;
; * - ::CU_TRSF_NORMALIZED_COORDINATES, which suppresses the
; *   default behavior of having the texture coordinates range
; *   from [0, Dim) where Dim is the width or height of the CUDA
; *   array. Instead, the texture coordinates [0, 1.0) reference
; *   the entire breadth of the array dimension;
; *
; * \param hTexRef - Texture reference
; * \param Flags   - Optional flags to set
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat,
; * ::cudaBindTexture,
; * ::cudaBindTexture2D,
; * ::cudaBindTextureToArray,
; * ::cudaBindTextureToMipmappedArray
; */
;API
cuTexRefSetFlags PROTO hTexRef:XWORD ,Flags:DWORD 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Gets the address associated with a texture reference
; *
; * \deprecated
; *
; * Returns in \p *pdptr the base address bound to the texture reference
; * \p hTexRef, or returns ::CUDA_ERROR_INVALID_VALUE if the texture reference
; * is not bound to any device memory range.
; *
; * \param pdptr   - Returned device address
; * \param hTexRef - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetAddress PROTO pdptr:XWORD ,hTexRef:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Gets the array bound to a texture reference
; *
; * \deprecated
; *
; * Returns in \p *phArray the CUDA array bound to the texture reference
; * \p hTexRef, or returns ::CUDA_ERROR_INVALID_VALUE if the texture reference
; * is not bound to any CUDA array.
; *
; * \param phArray - Returned array
; * \param hTexRef - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetArray PROTO phArray:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the mipmapped array bound to a texture reference
; *
; * \deprecated
; *
; * Returns in \p *phMipmappedArray the CUDA mipmapped array bound to the texture
; * reference \p hTexRef, or returns ::CUDA_ERROR_INVALID_VALUE if the texture reference
; * is not bound to any CUDA mipmapped array.
; *
; * \param phMipmappedArray - Returned mipmapped array
; * \param hTexRef          - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetMipmappedArray PROTO phMipmappedArray:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the addressing mode used by a texture reference
; *
; * \deprecated
; *
; * Returns in \p *pam the addressing mode corresponding to the
; * dimension \p dim of the texture reference \p hTexRef. Currently, the only
; * valid value for \p dim are 0 and 1.
; *
; * \param pam     - Returned addressing mode
; * \param hTexRef - Texture reference
; * \param dim     - Dimension
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetAddressMode PROTO pam:XWORD ,hTexRef:XWORD ,dim:DWORD 
;/**
; * \brief Gets the filter-mode used by a texture reference
; *
; * \deprecated
; *
; * Returns in \p *pfm the filtering mode of the texture reference
; * \p hTexRef.
; *
; * \param pfm     - Returned filtering mode
; * \param hTexRef - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetFilterMode PROTO pfm:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the format used by a texture reference
; *
; * \deprecated
; *
; * Returns in \p *pFormat and \p *pNumChannels the format and number
; * of components of the CUDA array bound to the texture reference \p hTexRef.
; * If \p pFormat or \p pNumChannels is NULL, it will be ignored.
; *
; * \param pFormat      - Returned format
; * \param pNumChannels - Returned number of components
; * \param hTexRef      - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags
; */
;API
cuTexRefGetFormat PROTO pFormat:XWORD ,pNumChannels:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the mipmap filtering mode for a texture reference
; *
; * \deprecated
; *
; * Returns the mipmap filtering mode in \p pfm that's used when reading memory through
; * the texture reference \p hTexRef.
; *
; * \param pfm     - Returned mipmap filtering mode
; * \param hTexRef - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetMipmapFilterMode PROTO pfm:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the mipmap level bias for a texture reference
; *
; * \deprecated
; *
; * Returns the mipmap level bias in \p pBias that's added to the specified mipmap
; * level when reading memory through the texture reference \p hTexRef.
; *
; * \param pbias   - Returned mipmap level bias
; * \param hTexRef - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetMipmapLevelBias PROTO pbias:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the min/max mipmap level clamps for a texture reference
; *
; * \deprecated
; *
; * Returns the min/max mipmap level clamps in \p pminMipmapLevelClamp and \p pmaxMipmapLevelClamp
; * that's used when reading memory through the texture reference \p hTexRef.
; *
; * \param pminMipmapLevelClamp - Returned mipmap min level clamp
; * \param pmaxMipmapLevelClamp - Returned mipmap max level clamp
; * \param hTexRef              - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetMipmapLevelClamp PROTO pminMipmapLevelClamp:XWORD ,pmaxMipmapLevelClamp:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the maximum anisotropy for a texture reference
; *
; * \deprecated
; *
; * Returns the maximum anisotropy in \p pmaxAniso that's used when reading memory through
; * the texture reference \p hTexRef.
; *
; * \param pmaxAniso - Returned maximum anisotropy
; * \param hTexRef   - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFlags, ::cuTexRefGetFormat
; */
;API
cuTexRefGetMaxAnisotropy PROTO pmaxAniso:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the border color used by a texture reference
; *
; * \deprecated
; *
; * Returns in \p pBorderColor, values of the RGBA color used by
; * the texture reference \p hTexRef.
; * The color value is of type float and holds color components in
; * the following sequence:
; * pBorderColor[0] holds 'R' component
; * pBorderColor[1] holds 'G' component
; * pBorderColor[2] holds 'B' component
; * pBorderColor[3] holds 'A' component
; *
; * \param hTexRef  - Texture reference
; * \param pBorderColor   - Returned Type and Value of RGBA color
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddressMode,
; * ::cuTexRefSetAddressMode, ::cuTexRefSetBorderColor
; */
;API
cuTexRefGetBorderColor PROTO pBorderColor:XWORD ,hTexRef:XWORD 
;/**
; * \brief Gets the flags used by a texture reference
; *
; * \deprecated
; *
; * Returns in \p *pFlags the flags of the texture reference \p hTexRef.
; *
; * \param pFlags  - Returned flags
; * \param hTexRef - Texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefSetAddress,
; * ::cuTexRefSetAddress2D, ::cuTexRefSetAddressMode, ::cuTexRefSetArray,
; * ::cuTexRefSetFilterMode, ::cuTexRefSetFlags, ::cuTexRefSetFormat,
; * ::cuTexRefGetAddress, ::cuTexRefGetAddressMode, ::cuTexRefGetArray,
; * ::cuTexRefGetFilterMode, ::cuTexRefGetFormat
; */
;API
cuTexRefGetFlags PROTO pFlags:XWORD ,hTexRef:XWORD 
;/**
; * \brief Creates a texture reference
; *
; * \deprecated
; *
; * Creates a texture reference and returns its handle in \p *pTexRef. Once
; * created, the application must call ::cuTexRefSetArray() or
; * ::cuTexRefSetAddress() to associate the reference with allocated memory.
; * Other texture reference functions are used to specify the format and
; * interpretation (addressing, filtering, etc.) to be used when the memory is
; * read through this texture reference.
; *
; * \param pTexRef - Returned texture reference
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefDestroy
; */
;API
cuTexRefCreate PROTO pTexRef:XWORD 
;/**
; * \brief Destroys a texture reference
; *
; * \deprecated
; *
; * Destroys the texture reference specified by \p hTexRef.
; *
; * \param hTexRef - Texture reference to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuTexRefCreate
; */
;API
cuTexRefDestroy PROTO hTexRef:XWORD 
;/**
; * \defgroup CUDA_SURFREF_DEPRECATED Surface Reference Management [DEPRECATED]
; *
; * ___MANBRIEF___ surface reference management functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the surface reference management functions of the
; * low-level CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Sets the CUDA array for a surface reference.
; *
; * \deprecated
; *
; * Sets the CUDA array \p hArray to be read and written by the surface reference
; * \p hSurfRef.  Any previous CUDA array state associated with the surface
; * reference is superseded by this function.  \p Flags must be set to 0.
; * The ::CUDA_ARRAY3D_SURFACE_LDST flag must have been set for the CUDA array.
; * Any CUDA array previously bound to \p hSurfRef is unbound.
; * \param hSurfRef - Surface reference handle
; * \param hArray - CUDA array handle
; * \param Flags - set to 0
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuModuleGetSurfRef,
; * ::cuSurfRefGetArray,
; * ::cudaBindSurfaceToArray
; */
;API
cuSurfRefSetArray PROTO hSurfRef:XWORD ,hArray:XWORD ,Flags:DWORD 
;/**
; * \brief Passes back the CUDA array bound to a surface reference.
; *
; * \deprecated
; *
; * Returns in \p *phArray the CUDA array bound to the surface reference
; * \p hSurfRef, or returns ::CUDA_ERROR_INVALID_VALUE if the surface reference
; * is not bound to any CUDA array.
; * \param phArray - Surface reference handle
; * \param hSurfRef - Surface reference handle
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa ::cuModuleGetSurfRef, ::cuSurfRefSetArray
; */
;API
cuSurfRefGetArray PROTO phArray:XWORD ,hSurfRef:XWORD 
IF  __CUDA_API_VERSION GE 5000
;/**
; * \defgroup CUDA_TEXOBJECT Texture Object Management
; *
; * ___MANBRIEF___ texture object management functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the texture object management functions of the
; * low-level CUDA driver application programming interface. The texture
; * object API is only supported on devices of compute capability 3.0 or higher.
; *
; * @{
; */
;/**
; * \brief Creates a texture object
; *
; * Creates a texture object and returns it in \p pTexObject. \p pResDesc describes
; * the data to texture from. \p pTexDesc describes how the data should be sampled.
; * \p pResViewDesc is an optional argument that specifies an alternate format for
; * the data described by \p pResDesc, and also describes the subresource region
; * to restrict access to when texturing. \p pResViewDesc can only be specified if
; * the type of resource is a CUDA array or a CUDA mipmapped array.
; *
; * Texture objects are only supported on devices of compute capability 3.0 or higher.
; * Additionally, a texture object is an opaque value, and, as such, should only be
; * accessed through CUDA API calls.
; *
; * The ::CUDA_RESOURCE_DESC structure is defined as:
; * \code
;        typedef struct CUDA_RESOURCE_DESC_st
;        {
;            CUresourcetype resType;
;            union {
;                struct {
;                    CUarray hArray;
;                } array;
;                struct {
;                    CUmipmappedArray hMipmappedArray;
;                } mipmap;
;                struct {
;                    CUdeviceptr devPtr;
;                    CUarray_format format;
;                    unsigned int numChannels;
;                    size_t sizeInBytes;
;                } linear;
;                struct {
;                    CUdeviceptr devPtr;
;                    CUarray_format format;
;                    unsigned int numChannels;
;                    size_t width;
;                    size_t height;
;                    size_t pitchInBytes;
;                } pitch2D;
;            } res;
;            unsigned int flags;
;        } CUDA_RESOURCE_DESC;
; * \endcode
; * where:
; * - ::CUDA_RESOURCE_DESC::resType specifies the type of resource to texture from.
; * CUresourceType is defined as:
; * \code
;        typedef enum CUresourcetype_enum {
;            CU_RESOURCE_TYPE_ARRAY           = 0x00,
;            CU_RESOURCE_TYPE_MIPMAPPED_ARRAY = 0x01,
;            CU_RESOURCE_TYPE_LINEAR          = 0x02,
;            CU_RESOURCE_TYPE_PITCH2D         = 0x03
;        } CUresourcetype;
; * \endcode
; *
; * \par
; * If ::CUDA_RESOURCE_DESC::resType is set to ::CU_RESOURCE_TYPE_ARRAY, ::CUDA_RESOURCE_DESC::res::array::hArray
; * must be set to a valid CUDA array handle.
; *
; * \par
; * If ::CUDA_RESOURCE_DESC::resType is set to ::CU_RESOURCE_TYPE_MIPMAPPED_ARRAY, ::CUDA_RESOURCE_DESC::res::mipmap::hMipmappedArray
; * must be set to a valid CUDA mipmapped array handle.
; *
; * \par
; * If ::CUDA_RESOURCE_DESC::resType is set to ::CU_RESOURCE_TYPE_LINEAR, ::CUDA_RESOURCE_DESC::res::linear::devPtr
; * must be set to a valid device pointer, that is aligned to ::CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT.
; * ::CUDA_RESOURCE_DESC::res::linear::format and ::CUDA_RESOURCE_DESC::res::linear::numChannels
; * describe the format of each component and the number of components per array element. ::CUDA_RESOURCE_DESC::res::linear::sizeInBytes
; * specifies the size of the array in bytes. The total number of elements in the linear address range cannot exceed
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH. The number of elements is computed as (sizeInBytes / (sizeof(format) * numChannels)).
; *
; * \par
; * If ::CUDA_RESOURCE_DESC::resType is set to ::CU_RESOURCE_TYPE_PITCH2D, ::CUDA_RESOURCE_DESC::res::pitch2D::devPtr
; * must be set to a valid device pointer, that is aligned to ::CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT.
; * ::CUDA_RESOURCE_DESC::res::pitch2D::format and ::CUDA_RESOURCE_DESC::res::pitch2D::numChannels
; * describe the format of each component and the number of components per array element. ::CUDA_RESOURCE_DESC::res::pitch2D::width
; * and ::CUDA_RESOURCE_DESC::res::pitch2D::height specify the width and height of the array in elements, and cannot exceed
; * ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH and ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT respectively.
; * ::CUDA_RESOURCE_DESC::res::pitch2D::pitchInBytes specifies the pitch between two rows in bytes and has to be aligned to
; * ::CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT. Pitch cannot exceed ::CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH.
; *
; * - ::flags must be set to zero.
; *
; *
; * The ::CUDA_TEXTURE_DESC struct is defined as
; * \code
;        typedef struct CUDA_TEXTURE_DESC_st {
;            CUaddress_mode addressMode[3];
;            CUfilter_mode filterMode;
;            unsigned int flags;
;            unsigned int maxAnisotropy;
;            CUfilter_mode mipmapFilterMode;
;            float mipmapLevelBias;
;            float minMipmapLevelClamp;
;            float maxMipmapLevelClamp;
;        } CUDA_TEXTURE_DESC;
; * \endcode
; * where
; * - ::CUDA_TEXTURE_DESC::addressMode specifies the addressing mode for each dimension of the texture data. ::CUaddress_mode is defined as:
; *   \code
;        typedef enum CUaddress_mode_enum {
;            CU_TR_ADDRESS_MODE_WRAP = 0,
;            CU_TR_ADDRESS_MODE_CLAMP = 1,
;            CU_TR_ADDRESS_MODE_MIRROR = 2,
;            CU_TR_ADDRESS_MODE_BORDER = 3
;        } CUaddress_mode;
; *   \endcode
; *   This is ignored if ::CUDA_RESOURCE_DESC::resType is ::CU_RESOURCE_TYPE_LINEAR. Also, if the flag, ::CU_TRSF_NORMALIZED_COORDINATES
; *   is not set, the only supported address mode is ::CU_TR_ADDRESS_MODE_CLAMP.
; *
; * - ::CUDA_TEXTURE_DESC::filterMode specifies the filtering mode to be used when fetching from the texture. CUfilter_mode is defined as:
; *   \code
;        typedef enum CUfilter_mode_enum {
;            CU_TR_FILTER_MODE_POINT = 0,
;            CU_TR_FILTER_MODE_LINEAR = 1
;        } CUfilter_mode;
; *   \endcode
; *   This is ignored if ::CUDA_RESOURCE_DESC::resType is ::CU_RESOURCE_TYPE_LINEAR.
; *
; * - ::CUDA_TEXTURE_DESC::flags can be any combination of the following:
; *   - ::CU_TRSF_READ_AS_INTEGER, which suppresses the default behavior of having the texture promote integer data to floating point data in the
; *     range [0, 1]. Note that texture with 32-bit integer format would not be promoted, regardless of whether or not this flag is specified.
; *   - ::CU_TRSF_NORMALIZED_COORDINATES, which suppresses the default behavior of having the texture coordinates range from [0, Dim) where Dim is
; *     the width or height of the CUDA array. Instead, the texture coordinates [0, 1.0) reference the entire breadth of the array dimension; Note
; *     that for CUDA mipmapped arrays, this flag has to be set.
; *
; * - ::CUDA_TEXTURE_DESC::maxAnisotropy specifies the maximum anisotropy ratio to be used when doing anisotropic filtering. This value will be
; *   clamped to the range [1,16].
; *
; * - ::CUDA_TEXTURE_DESC::mipmapFilterMode specifies the filter mode when the calculated mipmap level lies between two defined mipmap levels.
; *
; * - ::CUDA_TEXTURE_DESC::mipmapLevelBias specifies the offset to be applied to the calculated mipmap level.
; *
; * - ::CUDA_TEXTURE_DESC::minMipmapLevelClamp specifies the lower end of the mipmap level range to clamp access to.
; *
; * - ::CUDA_TEXTURE_DESC::maxMipmapLevelClamp specifies the upper end of the mipmap level range to clamp access to.
; *
; *
; * The ::CUDA_RESOURCE_VIEW_DESC struct is defined as
; * \code
;        typedef struct CUDA_RESOURCE_VIEW_DESC_st
;        {
;            CUresourceViewFormat format;
;            size_t width;
;            size_t height;
;            size_t depth;
;            unsigned int firstMipmapLevel;
;            unsigned int lastMipmapLevel;
;            unsigned int firstLayer;
;            unsigned int lastLayer;
;        } CUDA_RESOURCE_VIEW_DESC;
; * \endcode
; * where:
; * - ::CUDA_RESOURCE_VIEW_DESC::format specifies how the data contained in the CUDA array or CUDA mipmapped array should
; *   be interpreted. Note that this can incur a change in size of the texture data. If the resource view format is a block
; *   compressed format, then the underlying CUDA array or CUDA mipmapped array has to have a base of format ::CU_AD_FORMAT_UNSIGNED_INT32.
; *   with 2 or 4 channels, depending on the block compressed format. For ex., BC1 and BC4 require the underlying CUDA array to have
; *   a format of ::CU_AD_FORMAT_UNSIGNED_INT32 with 2 channels. The other BC formats require the underlying resource to have the same base
; *   format but with 4 channels.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::width specifies the new width of the texture data. If the resource view format is a block
; *   compressed format, this value has to be 4 times the original width of the resource. For non block compressed formats,
; *   this value has to be equal to that of the original resource.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::height specifies the new height of the texture data. If the resource view format is a block
; *   compressed format, this value has to be 4 times the original height of the resource. For non block compressed formats,
; *   this value has to be equal to that of the original resource.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::depth specifies the new depth of the texture data. This value has to be equal to that of the
; *   original resource.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::firstMipmapLevel specifies the most detailed mipmap level. This will be the new mipmap level zero.
; *   For non-mipmapped resources, this value has to be zero.::CUDA_TEXTURE_DESC::minMipmapLevelClamp and ::CUDA_TEXTURE_DESC::maxMipmapLevelClamp
; *   will be relative to this value. For ex., if the firstMipmapLevel is set to 2, and a minMipmapLevelClamp of 1.2 is specified,
; *   then the actual minimum mipmap level clamp will be 3.2.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::lastMipmapLevel specifies the least detailed mipmap level. For non-mipmapped resources, this value
; *   has to be zero.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::firstLayer specifies the first layer index for layered textures. This will be the new layer zero.
; *   For non-layered resources, this value has to be zero.
; *
; * - ::CUDA_RESOURCE_VIEW_DESC::lastLayer specifies the last layer index for layered textures. For non-layered resources,
; *   this value has to be zero.
; *
; *
; * \param pTexObject   - Texture object to create
; * \param pResDesc     - Resource descriptor
; * \param pTexDesc     - Texture descriptor
; * \param pResViewDesc - Resource view descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuTexObjectDestroy,
; * ::cudaCreateTextureObject
; */
;API
cuTexObjectCreate PROTO pTexObject:XWORD ,pResDesc:XWORD ,pTexDesc:XWORD ,pResViewDesc:XWORD 
;/**
; * \brief Destroys a texture object
; *
; * Destroys the texture object specified by \p texObject.
; *
; * \param texObject - Texture object to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuTexObjectCreate,
; * ::cudaDestroyTextureObject
; */
;API
cuTexObjectDestroy PROTO texObject:QWORD 
;/**
; * \brief Returns a texture object's resource descriptor
; *
; * Returns the resource descriptor for the texture object specified by \p texObject.
; *
; * \param pResDesc  - Resource descriptor
; * \param texObject - Texture object
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuTexObjectCreate,
; * ::cudaGetTextureObjectResourceDesc,
; */
;API
cuTexObjectGetResourceDesc PROTO pResDesc:XWORD ,texObject:QWORD 
;/**
; * \brief Returns a texture object's texture descriptor
; *
; * Returns the texture descriptor for the texture object specified by \p texObject.
; *
; * \param pTexDesc  - Texture descriptor
; * \param texObject - Texture object
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuTexObjectCreate,
; * ::cudaGetTextureObjectTextureDesc
; */
;API
cuTexObjectGetTextureDesc PROTO pTexDesc:XWORD ,texObject:QWORD 
;/**
; * \brief Returns a texture object's resource view descriptor
; *
; * Returns the resource view descriptor for the texture object specified by \p texObject.
; * If no resource view was set for \p texObject, the ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; * \param pResViewDesc - Resource view descriptor
; * \param texObject    - Texture object
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuTexObjectCreate,
; * ::cudaGetTextureObjectResourceViewDesc
; */
;API
cuTexObjectGetResourceViewDesc PROTO pResViewDesc:XWORD ,texObject:QWORD 
;/**
; * \defgroup CUDA_SURFOBJECT Surface Object Management
; *
; * ___MANBRIEF___ surface object management functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the surface object management functions of the
; * low-level CUDA driver application programming interface. The surface
; * object API is only supported on devices of compute capability 3.0 or higher.
; *
; * @{
; */
;/**
; * \brief Creates a surface object
; *
; * Creates a surface object and returns it in \p pSurfObject. \p pResDesc describes
; * the data to perform surface load/stores on. ::CUDA_RESOURCE_DESC::resType must be
; * ::CU_RESOURCE_TYPE_ARRAY and  ::CUDA_RESOURCE_DESC::res::array::hArray
; * must be set to a valid CUDA array handle. ::CUDA_RESOURCE_DESC::flags must be set to zero.
; *
; * Surface objects are only supported on devices of compute capability 3.0 or higher.
; * Additionally, a surface object is an opaque value, and, as such, should only be
; * accessed through CUDA API calls.
; *
; * \param pSurfObject - Surface object to create
; * \param pResDesc    - Resource descriptor
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuSurfObjectDestroy,
; * ::cudaCreateSurfaceObject
; */
;API
cuSurfObjectCreate PROTO pSurfObject:XWORD ,pResDesc:XWORD 
;/**
; * \brief Destroys a surface object
; *
; * Destroys the surface object specified by \p surfObject.
; *
; * \param surfObject - Surface object to destroy
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuSurfObjectCreate,
; * ::cudaDestroySurfaceObject
; */
;API
cuSurfObjectDestroy PROTO surfObject:QWORD 
;/**
; * \brief Returns a surface object's resource descriptor
; *
; * Returns the resource descriptor for the surface object specified by \p surfObject.
; *
; * \param pResDesc   - Resource descriptor
; * \param surfObject - Surface object
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE
; *
; * \sa
; * ::cuSurfObjectCreate,
; * ::cudaGetSurfaceObjectResourceDesc
; */
;API
cuSurfObjectGetResourceDesc PROTO pResDesc:XWORD ,surfObject:QWORD 
ENDIF ;/* __CUDA_API_VERSION >= 5000 */ 
;/**
; * \defgroup CUDA_PEER_ACCESS Peer Context Memory Access
; *
; * ___MANBRIEF___ direct peer context memory access functions of the low-level
; * CUDA driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the direct peer context memory access functions
; * of the low-level CUDA driver application programming interface.
; *
; * @{
; */
IF  __CUDA_API_VERSION GE 4000
;/**
; * \brief Queries if a device may directly access a peer device's memory.
; *
; * Returns in \p *canAccessPeer a value of 1 if contexts on \p dev are capable of
; * directly accessing memory from contexts on \p peerDev and 0 otherwise.
; * If direct access of \p peerDev from \p dev is possible, then access may be
; * enabled on two specific contexts by calling ::cuCtxEnablePeerAccess().
; *
; * \param canAccessPeer - Returned access capability
; * \param dev           - Device from which allocations on \p peerDev are to
; *                        be directly accessed.
; * \param peerDev       - Device on which the allocations to be directly accessed
; *                        by \p dev reside.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_DEVICE
; * \notefnerr
; *
; * \sa
; * ::cuCtxEnablePeerAccess,
; * ::cuCtxDisablePeerAccess,
; * ::cudaDeviceCanAccessPeer
; */
;API
cuDeviceCanAccessPeer PROTO canAccessPeer:XWORD ,dev:DWORD ,peerDev:DWORD 
;/**
; * \brief Enables direct access to memory allocations in a peer context.
; *
; * If both the current context and \p peerContext are on devices which support unified
; * addressing (as may be queried using ::CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING) and same
; * major compute capability, then on success all allocations from \p peerContext will
; * immediately be accessible by the current context.  See \ref CUDA_UNIFIED for additional
; * details.
; *
; * Note that access granted by this call is unidirectional and that in order to access
; * memory from the current context in \p peerContext, a separate symmetric call
; * to ::cuCtxEnablePeerAccess() is required.
; *
; * There is a system-wide maximum of eight peer connections per device.
; *
; * Returns ::CUDA_ERROR_PEER_ACCESS_UNSUPPORTED if ::cuDeviceCanAccessPeer() indicates
; * that the ::CUdevice of the current context cannot directly access memory
; * from the ::CUdevice of \p peerContext.
; *
; * Returns ::CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED if direct access of
; * \p peerContext from the current context has already been enabled.
; *
; * Returns ::CUDA_ERROR_TOO_MANY_PEERS if direct peer access is not possible
; * because hardware resources required for peer access have been exhausted.
; *
; * Returns ::CUDA_ERROR_INVALID_CONTEXT if there is no current context, \p peerContext
; * is not a valid context, or if the current context is \p peerContext.
; *
; * Returns ::CUDA_ERROR_INVALID_VALUE if \p Flags is not 0.
; *
; * \param peerContext - Peer context to enable direct access to from the current context
; * \param Flags       - Reserved for future use and must be set to 0
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED,
; * ::CUDA_ERROR_TOO_MANY_PEERS,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_PEER_ACCESS_UNSUPPORTED,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cuDeviceCanAccessPeer,
; * ::cuCtxDisablePeerAccess,
; * ::cudaDeviceEnablePeerAccess
; */
;API
cuCtxEnablePeerAccess PROTO peerContext:XWORD ,Flags:DWORD 
;/**
; * \brief Disables direct access to memory allocations in a peer context and
; * unregisters any registered allocations.
; *
;  Returns ::CUDA_ERROR_PEER_ACCESS_NOT_ENABLED if direct peer access has
; * not yet been enabled from \p peerContext to the current context.
; *
; * Returns ::CUDA_ERROR_INVALID_CONTEXT if there is no current context, or if
; * \p peerContext is not a valid context.
; *
; * \param peerContext - Peer context to disable direct access to
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_PEER_ACCESS_NOT_ENABLED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * \notefnerr
; *
; * \sa
; * ::cuDeviceCanAccessPeer,
; * ::cuCtxEnablePeerAccess,
; * ::cudaDeviceDisablePeerAccess
; */
;API
cuCtxDisablePeerAccess PROTO peerContext:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 4000 */ 
IF  __CUDA_API_VERSION GE 8000
;/**
; * \brief Queries attributes of the link between two devices.
; *
; * Returns in \p *value the value of the requested attribute \p attrib of the
; * link between \p srcDevice and \p dstDevice. The supported attributes are:
; * - ::CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK: A relative value indicating the
; *   performance of the link between two devices.
; * - ::CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED P2P: 1 if P2P Access is enable.
; * - ::CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED: 1 if Atomic operations over
; *   the link are supported.
; * - ::CU_DEVICE_P2P_ATTRIBUTE_CUDA_ARRAY_ACCESS_SUPPORTED: 1 if cudaArray can
; *   be accessed over the link.
; *
; * Returns ::CUDA_ERROR_INVALID_DEVICE if \p srcDevice or \p dstDevice are not valid
; * or if they represent the same device.
; *
; * Returns ::CUDA_ERROR_INVALID_VALUE if \p attrib is not valid or if \p value is
; * a null pointer.
; *
; * \param value         - Returned value of the requested attribute
; * \param attrib        - The requested attribute of the link between \p srcDevice and \p dstDevice.
; * \param srcDevice     - The source device of the target link.
; * \param dstDevice     - The destination device of the target link.
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_DEVICE,
; * ::CUDA_ERROR_INVALID_VALUE
; * \notefnerr
; *
; * \sa
; * ::cuCtxEnablePeerAccess,
; * ::cuCtxDisablePeerAccess,
; * ::cuDeviceCanAccessPeer,
; * ::cudaDeviceGetP2PAttribute
; */
;API
cuDeviceGetP2PAttribute PROTO value:XWORD ,attrib:CUdevice_P2PAttribute ,srcDevice:DWORD ,dstDevice:DWORD 
ENDIF ;/* __CUDA_API_VERSION >= 8000 */ 
;/**
; * \defgroup CUDA_GRAPHICS Graphics Interoperability
; *
; * ___MANBRIEF___ graphics interoperability functions of the low-level CUDA
; * driver API (___CURRENT_FILE___) ___ENDMANBRIEF___
; *
; * This section describes the graphics interoperability functions of the
; * low-level CUDA driver application programming interface.
; *
; * @{
; */
;/**
; * \brief Unregisters a graphics resource for access by CUDA
; *
; * Unregisters the graphics resource \p resource so it is not accessible by
; * CUDA unless registered again.
; *
; * If \p resource is invalid then ::CUDA_ERROR_INVALID_HANDLE is
; * returned.
; *
; * \param resource - Resource to unregister
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_UNKNOWN
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsD3D9RegisterResource,
; * ::cuGraphicsD3D10RegisterResource,
; * ::cuGraphicsD3D11RegisterResource,
; * ::cuGraphicsGLRegisterBuffer,
; * ::cuGraphicsGLRegisterImage,
; * ::cudaGraphicsUnregisterResource
; */
;API
cuGraphicsUnregisterResource PROTO resource:XWORD 
;/**
; * \brief Get an array through which to access a subresource of a mapped graphics resource.
; *
; * Returns in \p *pArray an array through which the subresource of the mapped
; * graphics resource \p resource which corresponds to array index \p arrayIndex
; * and mipmap level \p mipLevel may be accessed.  The value set in \p *pArray may
; * change every time that \p resource is mapped.
; *
; * If \p resource is not a texture then it cannot be accessed via an array and
; * ::CUDA_ERROR_NOT_MAPPED_AS_ARRAY is returned.
; * If \p arrayIndex is not a valid array index for \p resource then
; * ::CUDA_ERROR_INVALID_VALUE is returned.
; * If \p mipLevel is not a valid mipmap level for \p resource then
; * ::CUDA_ERROR_INVALID_VALUE is returned.
; * If \p resource is not mapped then ::CUDA_ERROR_NOT_MAPPED is returned.
; *
; * \param pArray      - Returned array through which a subresource of \p resource may be accessed
; * \param resource    - Mapped resource to access
; * \param arrayIndex  - Array index for array textures or cubemap face
; *                      index as defined by ::CUarray_cubemap_face for
; *                      cubemap textures for the subresource to access
; * \param mipLevel    - Mipmap level for the subresource to access
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_MAPPED,
; * ::CUDA_ERROR_NOT_MAPPED_AS_ARRAY
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsResourceGetMappedPointer,
; * ::cudaGraphicsSubResourceGetMappedArray
; */
;API
cuGraphicsSubResourceGetMappedArray PROTO pArray:XWORD ,resource:XWORD ,arrayIndex:DWORD ,mipLevel:DWORD 
IF  __CUDA_API_VERSION GE 5000
;/**
; * \brief Get a mipmapped array through which to access a mapped graphics resource.
; *
; * Returns in \p *pMipmappedArray a mipmapped array through which the mapped graphics
; * resource \p resource. The value set in \p *pMipmappedArray may change every time
; * that \p resource is mapped.
; *
; * If \p resource is not a texture then it cannot be accessed via a mipmapped array and
; * ::CUDA_ERROR_NOT_MAPPED_AS_ARRAY is returned.
; * If \p resource is not mapped then ::CUDA_ERROR_NOT_MAPPED is returned.
; *
; * \param pMipmappedArray - Returned mipmapped array through which \p resource may be accessed
; * \param resource        - Mapped resource to access
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_MAPPED,
; * ::CUDA_ERROR_NOT_MAPPED_AS_ARRAY
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsResourceGetMappedPointer,
; * ::cudaGraphicsResourceGetMappedMipmappedArray
; */
;API
cuGraphicsResourceGetMappedMipmappedArray PROTO pMipmappedArray:XWORD ,resource:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 5000 */ 
IF  __CUDA_API_VERSION GE 3020
;/**
; * \brief Get a device pointer through which to access a mapped graphics resource.
; *
; * Returns in \p *pDevPtr a pointer through which the mapped graphics resource
; * \p resource may be accessed.
; * Returns in \p pSize the size of the memory in bytes which may be accessed from that pointer.
; * The value set in \p pPointer may change every time that \p resource is mapped.
; *
; * If \p resource is not a buffer then it cannot be accessed via a pointer and
; * ::CUDA_ERROR_NOT_MAPPED_AS_POINTER is returned.
; * If \p resource is not mapped then ::CUDA_ERROR_NOT_MAPPED is returned.
; * *
; * \param pDevPtr    - Returned pointer through which \p resource may be accessed
; * \param pSize      - Returned size of the buffer accessible starting at \p *pPointer
; * \param resource   - Mapped resource to access
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_MAPPED,
; * ::CUDA_ERROR_NOT_MAPPED_AS_POINTER
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsMapResources,
; * ::cuGraphicsSubResourceGetMappedArray,
; * ::cudaGraphicsResourceGetMappedPointer
; */
;API
cuGraphicsResourceGetMappedPointer PROTO pDevPtr:XWORD ,pSize:XWORD ,resource:XWORD 
ENDIF ;/* __CUDA_API_VERSION >= 3020 */ 
;/**
; * \brief Set usage flags for mapping a graphics resource
; *
; * Set \p flags for mapping the graphics resource \p resource.
; *
; * Changes to \p flags will take effect the next time \p resource is mapped.
; * The \p flags argument may be any of the following:
; * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE: Specifies no hints about how this
; *   resource will be used. It is therefore assumed that this resource will be
; *   read from and written to by CUDA kernels.  This is the default value.
; * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_READONLY: Specifies that CUDA kernels which
; *   access this resource will not write to this resource.
; * - ::CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITEDISCARD: Specifies that CUDA kernels
; *   which access this resource will not read from this resource and will
; *   write over the entire contents of the resource, so none of the data
; *   previously stored in the resource will be preserved.
; *
; * If \p resource is presently mapped for access by CUDA then
; * ::CUDA_ERROR_ALREADY_MAPPED is returned.
; * If \p flags is not one of the above values then ::CUDA_ERROR_INVALID_VALUE is returned.
; *
; * \param resource - Registered resource to set flags for
; * \param flags    - Parameters for resource mapping
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_VALUE,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_ALREADY_MAPPED
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsMapResources,
; * ::cudaGraphicsResourceSetMapFlags
; */
;API
cuGraphicsResourceSetMapFlags PROTO resource:XWORD ,flags:DWORD 
;/**
; * \brief Map graphics resources for access by CUDA
; *
; * Maps the \p count graphics resources in \p resources for access by CUDA.
; *
; * The resources in \p resources may be accessed by CUDA until they
; * are unmapped. The graphics API from which \p resources were registered
; * should not access any resources while they are mapped by CUDA. If an
; * application does so, the results are undefined.
; *
; * This function provides the synchronization guarantee that any graphics calls
; * issued before ::cuGraphicsMapResources() will complete before any subsequent CUDA
; * work issued in \p stream begins.
; *
; * If \p resources includes any duplicate entries then ::CUDA_ERROR_INVALID_HANDLE is returned.
; * If any of \p resources are presently mapped for access by CUDA then ::CUDA_ERROR_ALREADY_MAPPED is returned.
; *
; * \param count      - Number of resources to map
; * \param resources  - Resources to map for CUDA usage
; * \param hStream    - Stream with which to synchronize
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_ALREADY_MAPPED,
; * ::CUDA_ERROR_UNKNOWN
; * \note_null_stream
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsResourceGetMappedPointer,
; * ::cuGraphicsSubResourceGetMappedArray,
; * ::cuGraphicsUnmapResources,
; * ::cudaGraphicsMapResources
; */
;API
cuGraphicsMapResources PROTO count:DWORD ,resources:XWORD ,hStream:XWORD 
;/**
; * \brief Unmap graphics resources.
; *
; * Unmaps the \p count graphics resources in \p resources.
; *
; * Once unmapped, the resources in \p resources may not be accessed by CUDA
; * until they are mapped again.
; *
; * This function provides the synchronization guarantee that any CUDA work issued
; * in \p stream before ::cuGraphicsUnmapResources() will complete before any
; * subsequently issued graphics work begins.
; *
; *
; * If \p resources includes any duplicate entries then ::CUDA_ERROR_INVALID_HANDLE is returned.
; * If any of \p resources are not presently mapped for access by CUDA then ::CUDA_ERROR_NOT_MAPPED is returned.
; *
; * \param count      - Number of resources to unmap
; * \param resources  - Resources to unmap
; * \param hStream    - Stream with which to synchronize
; *
; * \return
; * ::CUDA_SUCCESS,
; * ::CUDA_ERROR_DEINITIALIZED,
; * ::CUDA_ERROR_NOT_INITIALIZED,
; * ::CUDA_ERROR_INVALID_CONTEXT,
; * ::CUDA_ERROR_INVALID_HANDLE,
; * ::CUDA_ERROR_NOT_MAPPED,
; * ::CUDA_ERROR_UNKNOWN
; * \note_null_stream
; * \notefnerr
; *
; * \sa
; * ::cuGraphicsMapResources,
; * ::cudaGraphicsUnmapResources
; */
;API
cuGraphicsUnmapResources PROTO count:DWORD ,resources:XWORD ,hStream:XWORD 
;API
cuGetExportTable PROTO ppExportTable:XWORD ,pExportTableId:XWORD 
;/**
; * CUDA API versioning support
; */
IF Defined(__CUDA_API_VERSION_INTERNAL)
ENDIF ;/* __CUDA_API_VERSION_INTERNAL */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR ( __CUDA_API_VERSION GE 4000 AND  __CUDA_API_VERSION LT 6050)
;API
cuMemHostRegister PROTO p:XWORD ,bytesize:DWORD ,Flags:DWORD 
ENDIF ;/* defined(__CUDA_API_VERSION_INTERNAL) || (__CUDA_API_VERSION >= 4000 && __CUDA_API_VERSION < 6050) */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION LT 6050
;API
cuGraphicsResourceSetMapFlags PROTO resource:XWORD ,flags:DWORD 
ENDIF ;/* defined(__CUDA_API_VERSION_INTERNAL) || __CUDA_API_VERSION < 6050 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR ( __CUDA_API_VERSION GE 5050 AND  __CUDA_API_VERSION LT 6050)
;API
cuLinkCreate PROTO numOptions:DWORD ,options:XWORD ,optionValues:XWORD ,stateOut:XWORD 
;API
cuLinkAddData PROTO state:XWORD ,atype:CUjitInputType ,data:XWORD ,asize:DWORD ,aname:XWORD ,numOptions:DWORD ,options:XWORD ,optionValues:XWORD 
;API
cuLinkAddFile PROTO state:XWORD ,atype:CUjitInputType ,path:XWORD ,numOptions:DWORD ,options:XWORD ,optionValues:XWORD 
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || (__CUDA_API_VERSION >= 5050 && __CUDA_API_VERSION < 6050) */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR ( __CUDA_API_VERSION GE 3020 AND  __CUDA_API_VERSION LT 4010)
;API
cuTexRefSetAddress2D_v2 PROTO hTexRef:XWORD ,desc:XWORD ,dptr:CUdeviceptr ,Pitch:DWORD 
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || (__CUDA_API_VERSION >= 3020 && __CUDA_API_VERSION < 4010) */ 
;/**
; * CUDA API made obselete at API version 3020
; */
IF Defined(__CUDA_API_VERSION_INTERNAL)
CUdeviceptr  equ  < CUdeviceptr_v1>
CUDA_MEMCPY2D_st  equ  < CUDA_MEMCPY2D_v1_st>
CUDA_MEMCPY2D  equ  < CUDA_MEMCPY2D_v1>
CUDA_MEMCPY3D_st  equ  < CUDA_MEMCPY3D_v1_st>
CUDA_MEMCPY3D  equ  < CUDA_MEMCPY3D_v1>
CUDA_ARRAY_DESCRIPTOR_st  equ  < CUDA_ARRAY_DESCRIPTOR_v1_st>
CUDA_ARRAY_DESCRIPTOR  equ  < CUDA_ARRAY_DESCRIPTOR_v1>
CUDA_ARRAY3D_DESCRIPTOR_st  equ  < CUDA_ARRAY3D_DESCRIPTOR_v1_st>
CUDA_ARRAY3D_DESCRIPTOR  equ  < CUDA_ARRAY3D_DESCRIPTOR_v1>
ENDIF ;/* CUDA_FORCE_LEGACY32_INTERNAL */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION LT 3020
;/**< typedef __int64 CUdeviceptr */ 

CUDA_MEMCPY2D  STRUCT; DEFALIGNMASM
  srcXInBytes DWORD ? ;/**< Source X in bytes */ 
  srcY DWORD ? ;/**< Source Y */ 
  srcMemoryType CUmemorytype ? ;/**< Source memory type (host, device, array) */ 
srcHost XWORD ?
  srcDevice XWORD ? ;/**< Source device pointer */ 
  srcArray XWORD ? ;/**< Source array reference */ 
  srcPitch DWORD ? ;/**< Source pitch (ignored when src is array) */ 
  dstXInBytes DWORD ? ;/**< Destination X in bytes */ 
  dstY DWORD ? ;/**< Destination Y */ 
  dstMemoryType CUmemorytype ? ;/**< Destination memory type (host, device, array) */ 
dstHost XWORD ?
  dstDevice XWORD ? ;/**< Destination device pointer */ 
  dstArray XWORD ? ;/**< Destination array reference */ 
  dstPitch DWORD ? ;/**< Destination pitch (ignored when dst is array) */ 
  WidthInBytes DWORD ? ;/**< Width of 2D memory copy in bytes */ 
  Height DWORD ? ;/**< Height of 2D memory copy */ 
CUDA_MEMCPY2D    ENDS



CUDA_MEMCPY3D  STRUCT; DEFALIGNMASM
  srcXInBytes DWORD ? ;/**< Source X in bytes */ 
  srcY DWORD ? ;/**< Source Y */ 
  srcZ DWORD ? ;/**< Source Z */ 
  srcLOD DWORD ? ;/**< Source LOD */ 
  srcMemoryType CUmemorytype ? ;/**< Source memory type (host, device, array) */ 
srcHost XWORD ?
  srcDevice XWORD ? ;/**< Source device pointer */ 
  srcArray XWORD ? ;/**< Source array reference */ 
reserved0 XWORD ?
  srcPitch DWORD ? ;/**< Source pitch (ignored when src is array) */ 
  srcHeight DWORD ? ;/**< Source height (ignored when src is array; may be 0 if Depth==1) */ 
  dstXInBytes DWORD ? ;/**< Destination X in bytes */ 
  dstY DWORD ? ;/**< Destination Y */ 
  dstZ DWORD ? ;/**< Destination Z */ 
  dstLOD DWORD ? ;/**< Destination LOD */ 
  dstMemoryType CUmemorytype ? ;/**< Destination memory type (host, device, array) */ 
dstHost XWORD ?
  dstDevice XWORD ? ;/**< Destination device pointer */ 
  dstArray XWORD ? ;/**< Destination array reference */ 
reserved1 XWORD ?
  dstPitch DWORD ? ;/**< Destination pitch (ignored when dst is array) */ 
  dstHeight DWORD ? ;/**< Destination height (ignored when dst is array; may be 0 if Depth==1) */ 
  WidthInBytes DWORD ? ;/**< Width of 3D memory copy in bytes */ 
  Height DWORD ? ;/**< Height of 3D memory copy */ 
  Depth DWORD ? ;/**< Depth of 3D memory copy */ 
CUDA_MEMCPY3D    ENDS



CUDA_ARRAY_DESCRIPTOR  STRUCT; DEFALIGNMASM
  awidth DWORD ? ;/**< Width of array */ 
  Height DWORD ? ;/**< Height of array */ 
  Format CUarray_format ? ;/**< Array format */ 
  NumChannels DWORD ? ;/**< Channels per array element */ 
CUDA_ARRAY_DESCRIPTOR    ENDS



CUDA_ARRAY3D_DESCRIPTOR  STRUCT; DEFALIGNMASM
  awidth DWORD ? ;/**< Width of 3D array */ 
  Height DWORD ? ;/**< Height of 3D array */ 
  Depth DWORD ? ;/**< Depth of 3D array */ 
  Format CUarray_format ? ;/**< Array format */ 
  NumChannels DWORD ? ;/**< Channels per array element */ 
  Flags DWORD ? ;/**< Flags */ 
CUDA_ARRAY3D_DESCRIPTOR    ENDS


;API
cuDeviceTotalMem PROTO bytes:XWORD ,dev:DWORD 
;API
cuCtxCreate PROTO pctx:XWORD ,flags:DWORD ,dev:DWORD 
;API
cuModuleGetGlobal PROTO dptr:XWORD ,bytes:XWORD ,hmod:XWORD ,aname:XWORD 
;API
cuMemGetInfo PROTO free:XWORD ,total:XWORD 
;API
cuMemAlloc PROTO dptr:XWORD ,bytesize:DWORD 
;API
cuMemAllocPitch PROTO dptr:XWORD ,pPitch:XWORD ,WidthInBytes:DWORD ,Height:DWORD ,ElementSizeBytes:DWORD 
;API
cuMemFree PROTO dptr:CUdeviceptr 
;API
cuMemGetAddressRange PROTO pbase:XWORD ,psize:XWORD ,dptr:CUdeviceptr 
;API
cuMemAllocHost PROTO pp:XWORD ,bytesize:DWORD 
;API
cuMemHostGetDevicePointer PROTO pdptr:XWORD ,p:XWORD ,Flags:DWORD 
;API
cuMemcpyHtoD PROTO dstDevice:CUdeviceptr ,srcHost:XWORD ,ByteCount:DWORD 
;API
cuMemcpyDtoH PROTO dstHost:XWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyDtoD PROTO dstDevice:CUdeviceptr ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyDtoA PROTO dstArray:XWORD ,dstOffset:DWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyAtoD PROTO dstDevice:CUdeviceptr ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;API
cuMemcpyHtoA PROTO dstArray:XWORD ,dstOffset:DWORD ,srcHost:XWORD ,ByteCount:DWORD 
;API
cuMemcpyAtoH PROTO dstHost:XWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;API
cuMemcpyAtoA PROTO dstArray:XWORD ,dstOffset:DWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;API
cuMemcpyHtoAAsync PROTO dstArray:XWORD ,dstOffset:DWORD ,srcHost:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyAtoHAsync PROTO dstHost:XWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpy2D PROTO pCopy:XWORD 
;API
cuMemcpy2DUnaligned PROTO pCopy:XWORD 
;API
cuMemcpy3D PROTO pCopy:XWORD 
;API
cuMemcpyHtoDAsync PROTO dstDevice:CUdeviceptr ,srcHost:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyDtoHAsync PROTO dstHost:XWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyDtoDAsync PROTO dstDevice:CUdeviceptr ,srcDevice:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpy2DAsync PROTO pCopy:XWORD ,hStream:XWORD 
;API
cuMemcpy3DAsync PROTO pCopy:XWORD ,hStream:XWORD 
;API
cuMemsetD8 PROTO dstDevice:CUdeviceptr ,uc:DWORD ,N:DWORD 
;API
cuMemsetD16 PROTO dstDevice:CUdeviceptr ,us:DWORD ,N:DWORD 
;API
cuMemsetD32 PROTO dstDevice:CUdeviceptr ,ui:DWORD ,N:DWORD 
;API
cuMemsetD2D8 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,uc:DWORD ,awidth:DWORD ,Height:DWORD 
;API
cuMemsetD2D16 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,us:DWORD ,awidth:DWORD ,Height:DWORD 
;API
cuMemsetD2D32 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,ui:DWORD ,awidth:DWORD ,Height:DWORD 
;API
cuArrayCreate PROTO pHandle:XWORD ,pAllocateArray:XWORD 
;API
cuArrayGetDescriptor PROTO pArrayDescriptor:XWORD ,hArray:XWORD 
;API
cuArray3DCreate PROTO pHandle:XWORD ,pAllocateArray:XWORD 
;API
cuArray3DGetDescriptor PROTO pArrayDescriptor:XWORD ,hArray:XWORD 
;API
cuTexRefSetAddress PROTO ByteOffset:XWORD ,hTexRef:XWORD ,dptr:CUdeviceptr ,bytes:DWORD 
;API
cuTexRefSetAddress2D PROTO hTexRef:XWORD ,desc:XWORD ,dptr:CUdeviceptr ,Pitch:DWORD 
;API
cuTexRefGetAddress PROTO pdptr:XWORD ,hTexRef:XWORD 
;API
cuGraphicsResourceGetMappedPointer PROTO pDevPtr:XWORD ,pSize:XWORD ,resource:XWORD 
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION < 3020 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL) OR  __CUDA_API_VERSION LT 4000
;API
cuCtxDestroy PROTO ctx:XWORD 
;API
cuCtxPopCurrent PROTO pctx:XWORD 
;API
cuCtxPushCurrent PROTO ctx:XWORD 
;API
cuStreamDestroy PROTO hStream:XWORD 
;API
cuEventDestroy PROTO hEvent:XWORD 
ENDIF ;/* __CUDA_API_VERSION_INTERNAL || __CUDA_API_VERSION < 4000 */ 
IF Defined(__CUDA_API_VERSION_INTERNAL)
ENDIF ;/* __CUDA_API_VERSION_INTERNAL */ 
IF Defined(__CUDA_API_VERSION_INTERNAL)
;API
cuMemcpyHtoD_v2 PROTO dstDevice:CUdeviceptr ,srcHost:XWORD ,ByteCount:DWORD 
;API
cuMemcpyDtoH_v2 PROTO dstHost:XWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyDtoD_v2 PROTO dstDevice:CUdeviceptr ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyDtoA_v2 PROTO dstArray:XWORD ,dstOffset:DWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyAtoD_v2 PROTO dstDevice:CUdeviceptr ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;API
cuMemcpyHtoA_v2 PROTO dstArray:XWORD ,dstOffset:DWORD ,srcHost:XWORD ,ByteCount:DWORD 
;API
cuMemcpyAtoH_v2 PROTO dstHost:XWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;API
cuMemcpyAtoA_v2 PROTO dstArray:XWORD ,dstOffset:DWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD 
;API
cuMemcpyHtoAAsync_v2 PROTO dstArray:XWORD ,dstOffset:DWORD ,srcHost:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyAtoHAsync_v2 PROTO dstHost:XWORD ,srcArray:XWORD ,srcOffset:DWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpy2D_v2 PROTO pCopy:XWORD 
;API
cuMemcpy2DUnaligned_v2 PROTO pCopy:XWORD 
;API
cuMemcpy3D_v2 PROTO pCopy:XWORD 
;API
cuMemcpyHtoDAsync_v2 PROTO dstDevice:CUdeviceptr ,srcHost:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyDtoHAsync_v2 PROTO dstHost:XWORD ,srcDevice:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyDtoDAsync_v2 PROTO dstDevice:CUdeviceptr ,srcDevice:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpy2DAsync_v2 PROTO pCopy:XWORD ,hStream:XWORD 
;API
cuMemcpy3DAsync_v2 PROTO pCopy:XWORD ,hStream:XWORD 
;API
cuMemsetD8_v2 PROTO dstDevice:CUdeviceptr ,uc:DWORD ,N:DWORD 
;API
cuMemsetD16_v2 PROTO dstDevice:CUdeviceptr ,us:DWORD ,N:DWORD 
;API
cuMemsetD32_v2 PROTO dstDevice:CUdeviceptr ,ui:DWORD ,N:DWORD 
;API
cuMemsetD2D8_v2 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,uc:DWORD ,awidth:DWORD ,Height:DWORD 
;API
cuMemsetD2D16_v2 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,us:DWORD ,awidth:DWORD ,Height:DWORD 
;API
cuMemsetD2D32_v2 PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,ui:DWORD ,awidth:DWORD ,Height:DWORD 
;API
cuMemcpy PROTO dst:CUdeviceptr ,src:CUdeviceptr ,ByteCount:DWORD 
;API
cuMemcpyAsync PROTO dst:CUdeviceptr ,src:CUdeviceptr ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpyPeer PROTO dstDevice:CUdeviceptr ,dstContext:XWORD ,srcDevice:CUdeviceptr ,srcContext:XWORD ,ByteCount:DWORD 
;API
cuMemcpyPeerAsync PROTO dstDevice:CUdeviceptr ,dstContext:XWORD ,srcDevice:CUdeviceptr ,srcContext:XWORD ,ByteCount:DWORD ,hStream:XWORD 
;API
cuMemcpy3DPeer PROTO pCopy:XWORD 
;API
cuMemcpy3DPeerAsync PROTO pCopy:XWORD ,hStream:XWORD 
;API
cuMemsetD8Async PROTO dstDevice:CUdeviceptr ,uc:DWORD ,N:DWORD ,hStream:XWORD 
;API
cuMemsetD16Async PROTO dstDevice:CUdeviceptr ,us:DWORD ,N:DWORD ,hStream:XWORD 
;API
cuMemsetD32Async PROTO dstDevice:CUdeviceptr ,ui:DWORD ,N:DWORD ,hStream:XWORD 
;API
cuMemsetD2D8Async PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,uc:DWORD ,awidth:DWORD ,Height:DWORD ,hStream:XWORD 
;API
cuMemsetD2D16Async PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,us:DWORD ,awidth:DWORD ,Height:DWORD ,hStream:XWORD 
;API
cuMemsetD2D32Async PROTO dstDevice:CUdeviceptr ,dstPitch:DWORD ,ui:DWORD ,awidth:DWORD ,Height:DWORD ,hStream:XWORD 
;API
cuStreamGetPriority PROTO hStream:XWORD ,priority:XWORD 
;API
cuStreamGetFlags PROTO hStream:XWORD ,flags:XWORD 
;API
cuStreamGetCtx PROTO hStream:XWORD ,pctx:XWORD 
;API
cuStreamWaitEvent PROTO hStream:XWORD ,hEvent:XWORD ,Flags:DWORD 
;API
cuStreamAddCallback PROTO hStream:XWORD ,callback:XWORD ,userData:XWORD ,flags:DWORD 
;API
cuStreamAttachMemAsync PROTO hStream:XWORD ,dptr:CUdeviceptr ,length1:DWORD ,flags:DWORD 
;API
cuStreamQuery PROTO hStream:XWORD 
;API
cuStreamSynchronize PROTO hStream:XWORD 
;API
cuEventRecord PROTO hEvent:XWORD ,hStream:XWORD 
;API
cuLaunchKernel PROTO f:XWORD ,gridDimX:DWORD ,gridDimY:DWORD ,gridDimZ:DWORD ,blockDimX:DWORD ,blockDimY:DWORD ,blockDimZ:DWORD ,sharedMemBytes:DWORD ,hStream:XWORD ,kernelParams:XWORD ,extra:XWORD 
;API
cuLaunchHostFunc PROTO hStream:XWORD ,fn:XWORD ,userData:XWORD 
;API
cuGraphicsMapResources PROTO count:DWORD ,resources:XWORD ,hStream:XWORD 
;API
cuGraphicsUnmapResources PROTO count:DWORD ,resources:XWORD ,hStream:XWORD 
;API
cuStreamWriteValue32 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:DWORD ,flags:DWORD 
;API
cuStreamWaitValue32 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:DWORD ,flags:DWORD 
;API
cuStreamWriteValue64 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:QWORD ,flags:DWORD 
;API
cuStreamWaitValue64 PROTO stream:XWORD ,aaddr:CUdeviceptr ,value:QWORD ,flags:DWORD 
;API
cuStreamBatchMemOp PROTO stream:XWORD ,count:DWORD ,paramArray:XWORD ,flags:DWORD 
;API
cuMemPrefetchAsync PROTO devPtr:CUdeviceptr ,count:DWORD ,dstDevice:DWORD ,hStream:XWORD 
;API
cuLaunchCooperativeKernel PROTO f:XWORD ,gridDimX:DWORD ,gridDimY:DWORD ,gridDimZ:DWORD ,blockDimX:DWORD ,blockDimY:DWORD ,blockDimZ:DWORD ,sharedMemBytes:DWORD ,hStream:XWORD ,kernelParams:XWORD 
;API
cuSignalExternalSemaphoresAsync PROTO extSemArray:XWORD ,paramsArray:XWORD ,numExtSems:DWORD ,stream:XWORD 
;API
cuWaitExternalSemaphoresAsync PROTO extSemArray:XWORD ,paramsArray:XWORD ,numExtSems:DWORD ,stream:XWORD 
;API
cuStreamBeginCapture PROTO hStream:XWORD 
;API
cuStreamBeginCapture_ptsz PROTO hStream:XWORD 
;API
cuStreamBeginCapture_v2 PROTO hStream:XWORD ,Mode1:CUstreamCaptureMode 
;API
cuStreamEndCapture PROTO hStream:XWORD ,phGraph:XWORD 
;API
cuStreamIsCapturing PROTO hStream:XWORD ,captureStatus:XWORD 
;API
cuStreamGetCaptureInfo PROTO hStream:XWORD ,captureStatus:XWORD ,id:XWORD 
;API
cuGraphLaunch PROTO hGraph:XWORD ,hStream:XWORD 
ENDIF 
IFDEF __cplusplus
ENDIF 
