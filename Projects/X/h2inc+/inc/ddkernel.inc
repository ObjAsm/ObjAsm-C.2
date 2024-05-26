;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ddkernel.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:14:20

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
      DECLARE_INTERFACE_(IDirectDrawKernel, IUnknown)
        STDMETHOD QueryInterface, :, :ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetCaps, :
        STDMETHOD GetKernelHandle, :
        STDMETHOD ReleaseKernelHandle
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirectDrawSurfaceKernel, IUnknown)
        STDMETHOD QueryInterface, :, :ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetKernelHandle, :
        STDMETHOD ReleaseKernelHandle
      DECLARE_INTERFACE__END

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
