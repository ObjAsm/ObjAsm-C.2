;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ddkernel.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:14:20

;***************************************************************************
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
    ;*
    ;* GUIDS used by to get kernel interfaces
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      DEFINE_GUID IID_IDirectDrawKernel, 8D56C120h, 6A08h, 11D0h, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID IID_IDirectDrawSurfaceKernel, 60755DA0h, 6A40h, 11D0h, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
    endif
    ;*============================================================================
    ;*
    ;* DirectDraw Structures
    ;*
    ;* Various structures used to invoke the kernel API functions.
    ;*
    ;*==========================================================================*
    LPDIRECTDRAWKERNEL typedef ptr IDirectDrawKernel
    LPDIRECTDRAWSURFACEKERNEL typedef ptr IDirectDrawSurfaceKernel
    LPDDKERNELCAPS typedef ptr _DDKERNELCAPS
    ;*
    ;* INTERACES FOLLOW:
    ;*	IDirectDrawKernel
    ;*	IVideoPort
    ;*
    ;*
    ;* IDirectDrawKernel
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawKernel>
      DECLARE_INTERFACE_(IDirectDrawKernel, IUnknown)
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDraw methods ***
        STDMETHOD GetCaps, :LPDDKERNELCAPS
        STDMETHOD GetKernelHandle, :PULONG_PTR
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
    ;*
    ;* IDirectDrawSurfaceKernel
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawSurfaceKernel>
      DECLARE_INTERFACE_(IDirectDrawSurfaceKernel, IUnknown)
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDraw methods ***
        STDMETHOD GetKernelHandle, :PULONG_PTR
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
    ;*
    ;* DDKERNELCAPS
    ;*
    DDKERNELCAPS struct
      dwSize DWORD ?
      ; size of the DDKERNELCAPS structure
      dwCaps DWORD ?
      ; Contains the DDKERNELCAPS_XXX flags
      dwIRQCaps DWORD ?
      ; Contains the DDIRQ_XXX flags
    DDKERNELCAPS ends
    _DDKERNELCAPS typedef DDKERNELCAPS
    LPDDKERNELCAPS typedef ptr DDKERNELCAPS
    ;****************************************************************************
    ;*
    ;* DDKERNELCAPS CAPS
    ;*
    ;****************************************************************************
    ;*
    ;* Indicates that the device supports field skipping.
    ;*
    DDKERNELCAPS_SKIPFIELDS equ 00000001h
    ;*
    ;* Indicates that the device can support software autoflipping.
    ;*
    DDKERNELCAPS_AUTOFLIP equ 00000002h
    ;*
    ;* Indicates that the device can switch between bob and weave.
    ;*
    DDKERNELCAPS_SETSTATE equ 00000004h
    ;*
    ;* Indicates that a client can gain direct access to the frame buffer.
    ;*
    DDKERNELCAPS_LOCK equ 00000008h
    ;*
    ;* Indicates that a client can manually flip the video port.
    ;*
    DDKERNELCAPS_FLIPVIDEOPORT equ 00000010h
    ;*
    ;* Indicates that a client can manually flip the overlay.
    ;*
    DDKERNELCAPS_FLIPOVERLAY equ 00000020h
    ;*
    ;* Indicates that the device supports a video port capture interface
    ;* capable of transfering data to system memory.
    ;*
    DDKERNELCAPS_CAPTURE_SYSMEM equ 00000040h
    ;*
    ;* Indicates that the device supports a video port capture interface
    ;* capable of transfering data to non-local video memory.
    ;*
    DDKERNELCAPS_CAPTURE_NONLOCALVIDMEM equ 00000080h
    ;*
    ;* Indicates that the device can report the polarity (even/odd) of
    ;* the curent video field.
    ;*
    DDKERNELCAPS_FIELDPOLARITY equ 00000100h
    ;*
    ;* Indicates that the device supports inverting the DIBs while capturing
    ;* the data.
    ;*
    DDKERNELCAPS_CAPTURE_INVERTED equ 00000200h
    ;****************************************************************************
    ;*
    ;* DDKERNELCAPS IRQ CAPS
    ;*
    ;****************************************************************************
    ;*
    ;* The device can generate display VSYNC IRQs
    ;*
    DDIRQ_DISPLAY_VSYNC equ 00000001h
    ;*
    ;* Reserved
    ;*
    DDIRQ_RESERVED1 equ 00000002h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 0
    ;*
    DDIRQ_VPORT0_VSYNC equ 00000004h
    ;*
    ;* The device can generate video ports line IRQs using video port 0
    ;*
    DDIRQ_VPORT0_LINE equ 00000008h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 1
    ;*
    DDIRQ_VPORT1_VSYNC equ 00000010h
    ;*
    ;* The device can generate video ports line IRQs using video port 1
    ;*
    DDIRQ_VPORT1_LINE equ 00000020h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 2
    ;*
    DDIRQ_VPORT2_VSYNC equ 00000040h
    ;*
    ;* The device can generate video ports line IRQs using video port 2
    ;*
    DDIRQ_VPORT2_LINE equ 00000080h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 3
    ;*
    DDIRQ_VPORT3_VSYNC equ 00000100h
    ;*
    ;* The device can generate video ports line IRQs using video port 3
    ;*
    DDIRQ_VPORT3_LINE equ 00000200h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 4
    ;*
    DDIRQ_VPORT4_VSYNC equ 00000400h
    ;*
    ;* The device can generate video ports line IRQs using video port 4
    ;*
    DDIRQ_VPORT4_LINE equ 00000800h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 5
    ;*
    DDIRQ_VPORT5_VSYNC equ 00001000h
    ;*
    ;* The device can generate video ports line IRQs using video port 5
    ;*
    DDIRQ_VPORT5_LINE equ 00002000h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 6
    ;*
    DDIRQ_VPORT6_VSYNC equ 00004000h
    ;*
    ;* The device can generate video ports line IRQs using video port 6
    ;*
    DDIRQ_VPORT6_LINE equ 00008000h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 7
    ;*
    DDIRQ_VPORT7_VSYNC equ 00010000h
    ;*
    ;* The device can generate video ports line IRQs using video port 7
    ;*
    DDIRQ_VPORT7_LINE equ 00020000h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 8
    ;*
    DDIRQ_VPORT8_VSYNC equ 00040000h
    ;*
    ;* The device can generate video ports line IRQs using video port 8
    ;*
    DDIRQ_VPORT8_LINE equ 00080000h
    ;*
    ;* The device can generate video ports VSYNC IRQs using video port 9
    ;*
    DDIRQ_VPORT9_VSYNC equ 00010000h
    ;*
    ;* The device can generate video ports line IRQs using video port 9
    ;*
    DDIRQ_VPORT9_LINE equ 00020000h
    ifdef __cplusplus
      ;[...]
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
