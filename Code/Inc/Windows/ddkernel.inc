;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ddkernel.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef __DDKM_INCLUDED__
  __DDKM_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if Defined(_WIN32) and  not Defined(_NO_COM)
      COM_NO_WINDOWS_H equ <>
      include objbase.inc
    else
      ;[...]
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      DEFINE_GUID IID_IDirectDrawKernel, 8D56C120h, 6A08h, 11D0h, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID IID_IDirectDrawSurfaceKernel, 60755DA0h, 6A40h, 11D0h, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
    endif
    LPDIRECTDRAWKERNEL typedef ptr IDirectDrawKernel
    
    LPDIRECTDRAWSURFACEKERNEL typedef ptr IDirectDrawSurfaceKernel
    
    LPDDKERNELCAPS typedef ptr _DDKERNELCAPS
    
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawKernel>
      DECLARE_INTERFACE_ IDirectDrawKernel, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetKernelHandle, :THIS_
        STD_METHOD ReleaseKernelHandle, :THIS_
      END_DECLARE_INTERFACE_
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawKernel_GetCaps macro p, a
          exitm <(p) - lpVtbl - GetCaps (p, a)>
        endm
        IDirectDrawKernel_GetKernelHandle macro p, a
          exitm <(p) - lpVtbl - GetKernelHandle (p, a)>
        endm
        IDirectDrawKernel_ReleaseKernelHandle macro p
          exitm <(p) - lpVtbl - ReleaseKernelHandle (p)>
        endm
      endif
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawSurfaceKernel>
      DECLARE_INTERFACE_ IDirectDrawSurfaceKernel, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetKernelHandle, :THIS_
        STD_METHOD ReleaseKernelHandle, :THIS_
      END_DECLARE_INTERFACE_
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawSurfaceKernel_GetKernelHandle macro p, a
          exitm <(p) - lpVtbl - GetKernelHandle (p, a)>
        endm
        IDirectDrawSurfaceKernel_ReleaseKernelHandle macro p
          exitm <(p) - lpVtbl - ReleaseKernelHandle (p)>
        endm
      endif
    endif
    DDKERNELCAPS struct
      dwSize DWORD ?
      dwCaps DWORD ?
      dwIRQCaps DWORD ?
    DDKERNELCAPS ends

    _DDKERNELCAPS typedef DDKERNELCAPS
    LPDDKERNELCAPS typedef ptr DDKERNELCAPS
    
    DDKERNELCAPS_SKIPFIELDS equ 00000001h
    DDKERNELCAPS_AUTOFLIP equ 00000002h
    DDKERNELCAPS_SETSTATE equ 00000004h
    DDKERNELCAPS_LOCK equ 00000008h
    DDKERNELCAPS_FLIPVIDEOPORT equ 00000010h
    DDKERNELCAPS_FLIPOVERLAY equ 00000020h
    DDKERNELCAPS_CAPTURE_SYSMEM equ 00000040h
    DDKERNELCAPS_CAPTURE_NONLOCALVIDMEM equ 00000080h
    DDKERNELCAPS_FIELDPOLARITY equ 00000100h
    DDKERNELCAPS_CAPTURE_INVERTED equ 00000200h
    DDIRQ_DISPLAY_VSYNC equ 00000001h
    DDIRQ_RESERVED1 equ 00000002h
    DDIRQ_VPORT0_VSYNC equ 00000004h
    DDIRQ_VPORT0_LINE equ 00000008h
    DDIRQ_VPORT1_VSYNC equ 00000010h
    DDIRQ_VPORT1_LINE equ 00000020h
    DDIRQ_VPORT2_VSYNC equ 00000040h
    DDIRQ_VPORT2_LINE equ 00000080h
    DDIRQ_VPORT3_VSYNC equ 00000100h
    DDIRQ_VPORT3_LINE equ 00000200h
    DDIRQ_VPORT4_VSYNC equ 00000400h
    DDIRQ_VPORT4_LINE equ 00000800h
    DDIRQ_VPORT5_VSYNC equ 00001000h
    DDIRQ_VPORT5_LINE equ 00002000h
    DDIRQ_VPORT6_VSYNC equ 00004000h
    DDIRQ_VPORT6_LINE equ 00008000h
    DDIRQ_VPORT7_VSYNC equ 00010000h
    DDIRQ_VPORT7_LINE equ 00020000h
    DDIRQ_VPORT8_VSYNC equ 00040000h
    DDIRQ_VPORT8_LINE equ 00080000h
    DDIRQ_VPORT9_VSYNC equ 00010000h
    DDIRQ_VPORT9_LINE equ 00020000h
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif

