;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dvp.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:14:20

ifndef __DVP_INCLUDED__
  __DVP_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if Defined(_WIN32) and ( not Defined(_NO_COM) or Defined(DEFINE_GUID))
      DEFINE_GUID IID_IDDVideoPortContainer, 6C142760h, 0A733h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
      DEFINE_GUID IID_IDirectDrawVideoPort, 0B36D93E0h, 2B43h, 11CFh, 0A2h, 0DEh, 00h, 0AAh, 00h, 0B9h, 33h, 56h
      DEFINE_GUID IID_IDirectDrawVideoPortNotify, 0A655FB94h, 0589h, 4E57h, 0B3h, 33h, 56h, 7Ah, 89h, 46h, 8Ch, 88h
      DEFINE_GUID DDVPTYPE_E_HREFH_VREFH, 54F39980h, 0DA60h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID DDVPTYPE_E_HREFH_VREFL, 92783220h, 0DA60h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID DDVPTYPE_E_HREFL_VREFH, 0A07A02E0h, 0DA60h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID DDVPTYPE_E_HREFL_VREFL, 0E09C77E0h, 0DA60h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID DDVPTYPE_CCIR656, 0FCA326A0h, 0DA60h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID DDVPTYPE_BROOKTREE, 1352A560h, 0DA61h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID DDVPTYPE_PHILIPS, 332CF160h, 0DA61h, 11CFh, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
    endif
    ifndef GUID_DEFS_ONLY
      if Defined(_WIN32) and  not Defined(_NO_COM)
        COM_NO_WINDOWS_H equ <>
        include objbase.inc
      else
        ;[...]
      endif
      ifndef MAXULONG_PTR
        ULONG_PTR equ <DWORD>
      endif
      ifdef __cplusplus
        ;[...]
      endif
      LPDDVIDEOPORTCONTAINER typedef ptr IDDVideoPortContainer
      LPDIRECTDRAWVIDEOPORT typedef ptr IDirectDrawVideoPort
      LPDIRECTDRAWVIDEOPORTNOTIFY typedef ptr IDirectDrawVideoPortNotify
      LPDDVIDEOPORTCONNECT typedef ptr _DDVIDEOPORTCONNECT
      LPDDVIDEOPORTCAPS typedef ptr _DDVIDEOPORTCAPS
      LPDDVIDEOPORTDESC typedef ptr _DDVIDEOPORTDESC
      LPDDVIDEOPORTINFO typedef ptr _DDVIDEOPORTINFO
      LPDDVIDEOPORTBANDWIDTH typedef ptr _DDVIDEOPORTBANDWIDTH
      LPDDVIDEOPORTSTATUS typedef ptr _DDVIDEOPORTSTATUS
      LPDDVIDEOPORTNOTIFY typedef ptr _DDVIDEOPORTNOTIFY
      DDVIDEOPORTCONTAINERCALLBACKS typedef IDDVideoPortContainerVtbl
      DIRECTDRAWVIDEOPORTCALLBACKS typedef IDirectDrawVideoPortVtbl
      DIRECTDRAWVIDEOPORTNOTIFYCALLBACKS typedef IDirectDrawVideoPortNotifyVtbl
      TYPE_LPDDENUMVIDEOCALLBACK typedef proto WIN_STD_CALL_CONV :LPDDVIDEOPORTCAPS, :LPVOID
      LPDDENUMVIDEOCALLBACK typedef ptr TYPE_LPDDENUMVIDEOCALLBACK

      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDDVideoPortContainer>
        DECLARE_INTERFACE_(IDDVideoPortContainer, IUnknown)
          STDMETHOD QueryInterface, :, :ptr 
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          STDMETHOD CreateVideoPort, :, :, :ptr , :ptr 
          STDMETHOD EnumVideoPorts, :, :, :, :
          STDMETHOD GetVideoPortConnectInfo, :, :, :
          STDMETHOD QueryVideoPortStatus, :, :
        DECLARE_INTERFACE__END

        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IVideoPortContainer_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IVideoPortContainer_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IVideoPortContainer_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IVideoPortContainer_CreateVideoPort macro p, a, b, c_, d
            exitm <(p) - lpVtbl - CreateVideoPort (p, a, b, c_, d)>
          endm
          IVideoPortContainer_EnumVideoPorts macro p, a, b, c_, d
            exitm <(p) - lpVtbl - EnumVideoPorts (p, a, b, c_, d)>
          endm
          IVideoPortContainer_GetVideoPortConnectInfo macro p, a, b, c_
            exitm <(p) - lpVtbl - GetVideoPortConnectInfo (p, a, b, c_)>
          endm
          IVideoPortContainer_QueryVideoPortStatus macro p, a, b
            exitm <(p) - lpVtbl - QueryVideoPortStatus (p, a, b)>
          endm
        else
          ;[...]
        endif
      endif
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDirectDrawVideoPort>
        DECLARE_INTERFACE_(IDirectDrawVideoPort, IUnknown)
          STDMETHOD QueryInterface, :, :ptr 
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          STDMETHOD Flip, :, :
          STDMETHOD GetBandwidthInfo, :, :, :, :, :
          STDMETHOD GetColorControls, :
          STDMETHOD GetInputFormats, :, :, :
          STDMETHOD GetOutputFormats, :, :, :, :
          STDMETHOD GetFieldPolarity, :
          STDMETHOD GetVideoLine, :
          STDMETHOD GetVideoSignalStatus, :
          STDMETHOD SetColorControls, :
          STDMETHOD SetTargetSurface, :, :
          STDMETHOD StartVideo, :
          STDMETHOD StopVideo
          STDMETHOD UpdateVideo, :
          STDMETHOD WaitForSync, :, :, :
        DECLARE_INTERFACE__END

        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IVideoPort_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IVideoPort_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IVideoPort_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IVideoPort_SetTargetSurface macro p, a, b
            exitm <(p) - lpVtbl - SetTargetSurface (p, a, b)>
          endm
          IVideoPort_Flip macro p, a, b
            exitm <(p) - lpVtbl - Flip (p, a, b)>
          endm
          IVideoPort_GetBandwidthInfo macro p, a, b, c_, d, e
            exitm <(p) - lpVtbl - GetBandwidthInfo (p, a, b, c_, d, e)>
          endm
          IVideoPort_GetColorControls macro p, a
            exitm <(p) - lpVtbl - GetColorControls (p, a)>
          endm
          IVideoPort_GetInputFormats macro p, a, b, c_
            exitm <(p) - lpVtbl - GetInputFormats (p, a, b, c_)>
          endm
          IVideoPort_GetOutputFormats macro p, a, b, c_, d
            exitm <(p) - lpVtbl - GetOutputFormats (p, a, b, c_, d)>
          endm
          IVideoPort_GetFieldPolarity macro p, a
            exitm <(p) - lpVtbl - GetFieldPolarity (p, a)>
          endm
          IVideoPort_GetVideoLine macro p, a
            exitm <(p) - lpVtbl - GetVideoLine (p, a)>
          endm
          IVideoPort_GetVideoSignalStatus macro p, a
            exitm <(p) - lpVtbl - GetVideoSignalStatus (p, a)>
          endm
          IVideoPort_SetColorControls macro p, a
            exitm <(p) - lpVtbl - SetColorControls (p, a)>
          endm
          IVideoPort_StartVideo macro p, a
            exitm <(p) - lpVtbl - StartVideo (p, a)>
          endm
          IVideoPort_StopVideo macro p
            exitm <(p) - lpVtbl - StopVideo (p)>
          endm
          IVideoPort_UpdateVideo macro p, a
            exitm <(p) - lpVtbl - UpdateVideo (p, a)>
          endm
          IVideoPort_WaitForSync macro p, a, b, c_
            exitm <(p) - lpVtbl - WaitForSync (p, a, b, c_)>
          endm
        else
          ;[...]
        endif
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
        if Defined(_WIN32) and  not Defined(_NO_COM)
          INTERFACE equ <IDirectDrawVideoPortNotify>
          DECLARE_INTERFACE_(IDirectDrawVideoPortNotify, IUnknown)
            STDMETHOD QueryInterface, :, :ptr 
            STDMETHOD_ ULONG, AddRef
            STDMETHOD_ ULONG, Release
            STDMETHOD AcquireNotification, :ptr , :
            STDMETHOD ReleaseNotification, :
          DECLARE_INTERFACE__END

          if  not Defined(__cplusplus) or Defined(CINTERFACE)
            IVideoPortNotify_QueryInterface macro p, a, b
              exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
            endm
            IVideoPortNotify_AddRef macro p
              exitm <(p) - lpVtbl - AddRef (p)>
            endm
            IVideoPortNotify_Release macro p
              exitm <(p) - lpVtbl - Release (p)>
            endm
            IVideoPortNotify_AcquireNotification macro p, a, b
              exitm <(p) - lpVtbl - AcquireNotification (p, a, b)>
            endm
            IVideoPortNotify_ReleaseNotification macro p, a
              exitm <(p) - lpVtbl - ReleaseNotification (p, a)>
            endm
          else
            ;[...]
          endif
        endif
      endif
      DDVIDEOPORTCONNECT struct
        dwSize DWORD ?
        dwPortWidth DWORD ?
        guidTypeID GUID <>
        dwFlags DWORD ?
        dwReserved1 ULONG_PTR ?
      DDVIDEOPORTCONNECT ends
      _DDVIDEOPORTCONNECT typedef DDVIDEOPORTCONNECT
      DDVIDEOPORTCAPS struct
        dwSize DWORD ?
        dwFlags DWORD ?
        dwMaxWidth DWORD ?
        dwMaxVBIWidth DWORD ?
        dwMaxHeight DWORD ?
        dwVideoPortID DWORD ?
        dwCaps DWORD ?
        dwFX DWORD ?
        dwNumAutoFlipSurfaces DWORD ?
        dwAlignVideoPortBoundary DWORD ?
        dwAlignVideoPortPrescaleWidth DWORD ?
        dwAlignVideoPortCropBoundary DWORD ?
        dwAlignVideoPortCropWidth DWORD ?
        dwPreshrinkXStep DWORD ?
        dwPreshrinkYStep DWORD ?
        dwNumVBIAutoFlipSurfaces DWORD ?
        dwNumPreferredAutoflip DWORD ?
        wNumFilterTapsX WORD ?
        wNumFilterTapsY WORD ?
      DDVIDEOPORTCAPS ends
      _DDVIDEOPORTCAPS typedef DDVIDEOPORTCAPS
      DDVPD_WIDTH equ 00000001h
      DDVPD_HEIGHT equ 00000002h
      DDVPD_ID equ 00000004h
      DDVPD_CAPS equ 00000008h
      DDVPD_FX equ 00000010h
      DDVPD_AUTOFLIP equ 00000020h
      DDVPD_ALIGN equ 00000040h
      DDVPD_PREFERREDAUTOFLIP equ 00000080h
      DDVPD_FILTERQUALITY equ 00000100h
      DDVIDEOPORTDESC struct
        dwSize DWORD ?
        dwFieldWidth DWORD ?
        dwVBIWidth DWORD ?
        dwFieldHeight DWORD ?
        dwMicrosecondsPerField DWORD ?
        dwMaxPixelsPerSecond DWORD ?
        dwVideoPortID DWORD ?
        dwReserved1 DWORD ?
        VideoPortType DDVIDEOPORTCONNECT <>
        dwReserved2 ULONG_PTR ?
        dwReserved3 ULONG_PTR ?
      DDVIDEOPORTDESC ends
      _DDVIDEOPORTDESC typedef DDVIDEOPORTDESC
      DDVIDEOPORTINFO struct
        dwSize DWORD ?
        dwOriginX DWORD ?
        dwOriginY DWORD ?
        dwVPFlags DWORD ?
        rCrop RECT <>
        dwPrescaleWidth DWORD ?
        dwPrescaleHeight DWORD ?
        lpddpfInputFormat LPDDPIXELFORMAT ?
        lpddpfVBIInputFormat LPDDPIXELFORMAT ?
        lpddpfVBIOutputFormat LPDDPIXELFORMAT ?
        dwVBIHeight DWORD ?
        dwReserved1 ULONG_PTR ?
        dwReserved2 ULONG_PTR ?
      DDVIDEOPORTINFO ends
      _DDVIDEOPORTINFO typedef DDVIDEOPORTINFO
      DDVIDEOPORTBANDWIDTH struct
        dwSize DWORD ?
        dwCaps DWORD ?
        dwOverlay DWORD ?
        dwColorkey DWORD ?
        dwYInterpolate DWORD ?
        dwYInterpAndColorkey DWORD ?
        dwReserved1 ULONG_PTR ?
        dwReserved2 ULONG_PTR ?
      DDVIDEOPORTBANDWIDTH ends
      _DDVIDEOPORTBANDWIDTH typedef DDVIDEOPORTBANDWIDTH
      DDVIDEOPORTSTATUS struct
        dwSize DWORD ?
        bInUse BOOL ?
        dwFlags DWORD ?
        dwReserved1 DWORD ?
        VideoPortType DDVIDEOPORTCONNECT <>
        dwReserved2 ULONG_PTR ?
        dwReserved3 ULONG_PTR ?
      DDVIDEOPORTSTATUS ends
      _DDVIDEOPORTSTATUS typedef DDVIDEOPORTSTATUS
      DDVIDEOPORTNOTIFY struct
        ApproximateTimeStamp LARGE_INTEGER <>
        lField LONG ?
        dwSurfaceIndex UINT ?
        lDone LONG ?
      DDVIDEOPORTNOTIFY ends
      _DDVIDEOPORTNOTIFY typedef DDVIDEOPORTNOTIFY
      DDVPCONNECT_DOUBLECLOCK equ 00000001h
      DDVPCONNECT_VACT equ 00000002h
      DDVPCONNECT_INVERTPOLARITY equ 00000004h
      DDVPCONNECT_DISCARDSVREFDATA equ 00000008h
      DDVPCONNECT_HALFLINE equ 00000010h
      DDVPCONNECT_INTERLACED equ 00000020h
      DDVPCONNECT_SHAREEVEN equ 00000040h
      DDVPCONNECT_SHAREODD equ 00000080h
      DDVPCAPS_AUTOFLIP equ 00000001h
      DDVPCAPS_INTERLACED equ 00000002h
      DDVPCAPS_NONINTERLACED equ 00000004h
      DDVPCAPS_READBACKFIELD equ 00000008h
      DDVPCAPS_READBACKLINE equ 00000010h
      DDVPCAPS_SHAREABLE equ 00000020h
      DDVPCAPS_SKIPEVENFIELDS equ 00000040h
      DDVPCAPS_SKIPODDFIELDS equ 00000080h
      DDVPCAPS_SYNCMASTER equ 00000100h
      DDVPCAPS_VBISURFACE equ 00000200h
      DDVPCAPS_COLORCONTROL equ 00000400h
      DDVPCAPS_OVERSAMPLEDVBI equ 00000800h
      DDVPCAPS_SYSTEMMEMORY equ 00001000h
      DDVPCAPS_VBIANDVIDEOINDEPENDENT equ 00002000h
      DDVPCAPS_HARDWAREDEINTERLACE equ 00004000h
      DDVPFX_CROPTOPDATA equ 00000001h
      DDVPFX_CROPX equ 00000002h
      DDVPFX_CROPY equ 00000004h
      DDVPFX_INTERLEAVE equ 00000008h
      DDVPFX_MIRRORLEFTRIGHT equ 00000010h
      DDVPFX_MIRRORUPDOWN equ 00000020h
      DDVPFX_PRESHRINKX equ 00000040h
      DDVPFX_PRESHRINKY equ 00000080h
      DDVPFX_PRESHRINKXB equ 00000100h
      DDVPFX_PRESHRINKYB equ 00000200h
      DDVPFX_PRESHRINKXS equ 00000400h
      DDVPFX_PRESHRINKYS equ 00000800h
      DDVPFX_PRESTRETCHX equ 00001000h
      DDVPFX_PRESTRETCHY equ 00002000h
      DDVPFX_PRESTRETCHXN equ 00004000h
      DDVPFX_PRESTRETCHYN equ 00008000h
      DDVPFX_VBICONVERT equ 00010000h
      DDVPFX_VBINOSCALE equ 00020000h
      DDVPFX_IGNOREVBIXCROP equ 00040000h
      DDVPFX_VBINOINTERLEAVE equ 00080000h
      DDVP_AUTOFLIP equ 00000001h
      DDVP_CONVERT equ 00000002h
      DDVP_CROP equ 00000004h
      DDVP_INTERLEAVE equ 00000008h
      DDVP_MIRRORLEFTRIGHT equ 00000010h
      DDVP_MIRRORUPDOWN equ 00000020h
      DDVP_PRESCALE equ 00000040h
      DDVP_SKIPEVENFIELDS equ 00000080h
      DDVP_SKIPODDFIELDS equ 00000100h
      DDVP_SYNCMASTER equ 00000200h
      DDVP_VBICONVERT equ 00000400h
      DDVP_VBINOSCALE equ 00000800h
      DDVP_OVERRIDEBOBWEAVE equ 00001000h
      DDVP_IGNOREVBIXCROP equ 00002000h
      DDVP_VBINOINTERLEAVE equ 00004000h
      DDVP_HARDWAREDEINTERLACE equ 00008000h
      DDVPFORMAT_VIDEO equ 00000001h
      DDVPFORMAT_VBI equ 00000002h
      DDVPTARGET_VIDEO equ 00000001h
      DDVPTARGET_VBI equ 00000002h
      DDVPWAIT_BEGIN equ 00000001h
      DDVPWAIT_END equ 00000002h
      DDVPWAIT_LINE equ 00000003h
      DDVPFLIP_VIDEO equ 00000001h
      DDVPFLIP_VBI equ 00000002h
      DDVPSQ_NOSIGNAL equ 00000001h
      DDVPSQ_SIGNALOK equ 00000002h
      DDVPB_VIDEOPORT equ 00000001h
      DDVPB_OVERLAY equ 00000002h
      DDVPB_TYPE equ 00000004h
      DDVPBCAPS_SOURCE equ 00000001h
      DDVPBCAPS_DESTINATION equ 00000002h
      DDVPCREATE_VBIONLY equ 00000001h
      DDVPCREATE_VIDEOONLY equ 00000002h
      DDVPSTATUS_VBIONLY equ 00000001h
      DDVPSTATUS_VIDEOONLY equ 00000002h
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
endif
