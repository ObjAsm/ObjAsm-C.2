;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dvp.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:14:20

;***************************************************************************
ifndef __DVP_INCLUDED__
  __DVP_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;*
    ;* GUIDS used by DirectDrawVideoPort objects
    ;*
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
      ;*
      ;* These definitions are required to allow polymorphic structure members (i.e. those
      ;* that are referred to both as DWORDs and as pointers) to resolve into a type
      ;* of correct size to hold the largest of those two types (i.e. pointer) on 64 bit
      ;* systems. For 32 bit environments, ULONG_PTR resolves to a DWORD.
      ;*
      ifndef MAXULONG_PTR
        ULONG_PTR equ <DWORD>
      endif
      ;MAXULONG_PTR
      ifdef __cplusplus
        ;[...]
      endif
      ;*============================================================================
      ;*
      ;* DirectDraw Structures
      ;*
      ;* Various structures used to invoke DirectDraw.
      ;*
      ;*==========================================================================*
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
      ;*
      ;* API's
      ;*
      TYPE_LPDDENUMVIDEOCALLBACK typedef proto WIN_STD_CALL_CONV :LPDDVIDEOPORTCAPS, :LPVOID
      LPDDENUMVIDEOCALLBACK typedef ptr TYPE_LPDDENUMVIDEOCALLBACK

      ;*
      ;* INTERACES FOLLOW:
      ;*	IDirectDrawVideoPort
      ;*	IVideoPort
      ;*
      ;*
      ;* IDirectDrawVideoPortContainer
      ;*
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDDVideoPortContainer>
        DECLARE_INTERFACE_(IDDVideoPortContainer, IUnknown)
          ;*** IUnknown methods ***
          STDMETHOD QueryInterface, :REFIID, :ptr POINTER
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          ;*** IDirectDrawVideoPort methods ***
          STDMETHOD CreateVideoPort, :DWORD, :LPDDVIDEOPORTDESC, :ptr LPDIRECTDRAWVIDEOPORT, :ptr IUnknown
          STDMETHOD EnumVideoPorts, :DWORD, :LPDDVIDEOPORTCAPS, :POINTER, :LPDDENUMVIDEOCALLBACK
          STDMETHOD GetVideoPortConnectInfo, :DWORD, :LPDWORD, :LPDDVIDEOPORTCONNECT
          STDMETHOD QueryVideoPortStatus, :DWORD, :LPDDVIDEOPORTSTATUS
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
      ;*
      ;* IDirectDrawVideoPort
      ;*
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDirectDrawVideoPort>
        DECLARE_INTERFACE_(IDirectDrawVideoPort, IUnknown)
          ;*** IUnknown methods ***
          STDMETHOD QueryInterface, :REFIID, :ptr POINTER
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          ;*** IVideoPort methods ***
          STDMETHOD Flip, :LPDIRECTDRAWSURFACE, :DWORD
          STDMETHOD GetBandwidthInfo, :LPDDPIXELFORMAT, :DWORD, :DWORD, :DWORD, :LPDDVIDEOPORTBANDWIDTH
          STDMETHOD GetColorControls, :LPDDCOLORCONTROL
          STDMETHOD GetInputFormats, :LPDWORD, :LPDDPIXELFORMAT, :DWORD
          STDMETHOD GetOutputFormats, :LPDDPIXELFORMAT, :LPDWORD, :LPDDPIXELFORMAT, :DWORD
          STDMETHOD GetFieldPolarity, :LPBOOL
          STDMETHOD GetVideoLine, :LPDWORD
          STDMETHOD GetVideoSignalStatus, :LPDWORD
          STDMETHOD SetColorControls, :LPDDCOLORCONTROL
          STDMETHOD SetTargetSurface, :LPDIRECTDRAWSURFACE, :DWORD
          STDMETHOD StartVideo, :LPDDVIDEOPORTINFO
          STDMETHOD StopVideo
          STDMETHOD UpdateVideo, :LPDDVIDEOPORTINFO
          STDMETHOD WaitForSync, :DWORD, :DWORD, :DWORD
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
      ;*
      ;* IDirectDrawVideoPort
      ;*
      if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
        if Defined(_WIN32) and  not Defined(_NO_COM)
          INTERFACE equ <IDirectDrawVideoPortNotify>
          DECLARE_INTERFACE_(IDirectDrawVideoPortNotify, IUnknown)
            ;*** IUnknown methods ***
            STDMETHOD QueryInterface, :REFIID, :ptr POINTER
            STDMETHOD_ ULONG, AddRef
            STDMETHOD_ ULONG, Release
            ;*** IVideoPort methods ***
            STDMETHOD AcquireNotification, :ptr HANDLE, :LPDDVIDEOPORTNOTIFY
            STDMETHOD ReleaseNotification, :HANDLE
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
      ;*
      ;* DDVIDEOPORTCONNECT
      ;*
      DDVIDEOPORTCONNECT struct
        dwSize DWORD ?
        ; size of the DDVIDEOPORTCONNECT structure
        dwPortWidth DWORD ?
        ; Width of the video port
        guidTypeID GUID <>
        ; Description of video port connection
        dwFlags DWORD ?
        ; Connection flags
        dwReserved1 XWORD ?
        ; Reserved, set to zero.
      DDVIDEOPORTCONNECT ends
      _DDVIDEOPORTCONNECT typedef DDVIDEOPORTCONNECT
      ;*
      ;* DDVIDEOPORTCAPS
      ;*
      DDVIDEOPORTCAPS struct
        dwSize DWORD ?
        ; size of the DDVIDEOPORTCAPS structure
        dwFlags DWORD ?
        ; indicates which fields contain data
        dwMaxWidth DWORD ?
        ; max width of the video port field
        dwMaxVBIWidth DWORD ?
        ; max width of the VBI data
        dwMaxHeight DWORD ?
        ; max height of the video port field
        dwVideoPortID DWORD ?
        ; Video port ID (0 - (dwMaxVideoPorts -1))
        dwCaps DWORD ?
        ; Video port capabilities
        dwFX DWORD ?
        ; More video port capabilities
        dwNumAutoFlipSurfaces DWORD ?
        ; Max number of autoflippable surfaces allowed
        dwAlignVideoPortBoundary DWORD ?
        ; Byte restriction of placement within the surface
        dwAlignVideoPortPrescaleWidth DWORD ?
        ; Byte restriction of width after prescaling
        dwAlignVideoPortCropBoundary DWORD ?
        ; Byte restriction of left cropping
        dwAlignVideoPortCropWidth DWORD ?
        ; Byte restriction of cropping width
        dwPreshrinkXStep DWORD ?
        ; Width can be shrunk in steps of 1/x
        dwPreshrinkYStep DWORD ?
        ; Height can be shrunk in steps of 1/x
        dwNumVBIAutoFlipSurfaces DWORD ?
        ; Max number of VBI autoflippable surfaces allowed
        dwNumPreferredAutoflip DWORD ?
        ; Optimal number of autoflippable surfaces for hardware
        wNumFilterTapsX WORD ?
        ; Number of taps the prescaler uses in the X direction (0 - no prescale, 1 - replication, etc.)
        wNumFilterTapsY WORD ?
        ; Number of taps the prescaler uses in the Y direction (0 - no prescale, 1 - replication, etc.)
      DDVIDEOPORTCAPS ends
      _DDVIDEOPORTCAPS typedef DDVIDEOPORTCAPS
      ;*
      ;* The dwMaxWidth and dwMaxVBIWidth members are valid
      ;*
      DDVPD_WIDTH equ 00000001h
      ;*
      ;* The dwMaxHeight member is valid
      ;*
      DDVPD_HEIGHT equ 00000002h
      ;*
      ;* The dwVideoPortID member is valid
      ;*
      DDVPD_ID equ 00000004h
      ;*
      ;* The dwCaps member is valid
      ;*
      DDVPD_CAPS equ 00000008h
      ;*
      ;* The dwFX member is valid
      ;*
      DDVPD_FX equ 00000010h
      ;*
      ;* The dwNumAutoFlipSurfaces member is valid
      ;*
      DDVPD_AUTOFLIP equ 00000020h
      ;*
      ;* All of the alignment members are valid
      ;*
      DDVPD_ALIGN equ 00000040h
      ;*
      ;* The dwNumPreferredAutoflip member is valid
      ;*
      DDVPD_PREFERREDAUTOFLIP equ 00000080h
      ;*
      ;* The wNumFilterTapsX and wNumFilterTapsY fields are valid
      ;*
      DDVPD_FILTERQUALITY equ 00000100h
      ;*
      ;* DDVIDEOPORTDESC
      ;*
      DDVIDEOPORTDESC struct
        dwSize DWORD ?
        ; size of the DDVIDEOPORTDESC structure
        dwFieldWidth DWORD ?
        ; width of the video port field
        dwVBIWidth DWORD ?
        ; width of the VBI data
        dwFieldHeight DWORD ?
        ; height of the video port field
        dwMicrosecondsPerField DWORD ?
        ; Microseconds per video field
        dwMaxPixelsPerSecond DWORD ?
        ; Maximum pixel rate per second
        dwVideoPortID DWORD ?
        ; Video port ID (0 - (dwMaxVideoPorts -1))
        dwReserved1 DWORD ?
        ; Reserved for future use - set to zero (struct padding)
        VideoPortType DDVIDEOPORTCONNECT <>
        ; Description of video port connection
        dwReserved2 XWORD ?
        ; Reserved for future use - set to zero
        dwReserved3 XWORD ?
        ; Reserved for future use - set to zero
      DDVIDEOPORTDESC ends
      _DDVIDEOPORTDESC typedef DDVIDEOPORTDESC
      ;*
      ;* DDVIDEOPORTINFO
      ;*
      DDVIDEOPORTINFO struct
        dwSize DWORD ?
        ; Size of the structure
        dwOriginX DWORD ?
        ; Placement of the video data within the surface.
        dwOriginY DWORD ?
        ; Placement of the video data within the surface.
        dwVPFlags DWORD ?
        ; Video port options
        rCrop RECT <>
        ; Cropping rectangle (optional).
        dwPrescaleWidth DWORD ?
        ; Determines pre-scaling/zooming in the X direction (optional).
        dwPrescaleHeight DWORD ?
        ; Determines pre-scaling/zooming in the Y direction (optional).
        lpddpfInputFormat LPDDPIXELFORMAT ?
        ; Video format written to the video port
        lpddpfVBIInputFormat LPDDPIXELFORMAT ?
        ; Input format of the VBI data
        lpddpfVBIOutputFormat LPDDPIXELFORMAT ?
        ; Output format of the data
        dwVBIHeight DWORD ?
        ; Specifies the number of lines of data within the vertical blanking interval.
        dwReserved1 XWORD ?
        ; Reserved for future use - set to zero
        dwReserved2 XWORD ?
        ; Reserved for future use - set to zero
      DDVIDEOPORTINFO ends
      _DDVIDEOPORTINFO typedef DDVIDEOPORTINFO
      ;*
      ;* DDVIDEOPORTBANDWIDTH
      ;*
      DDVIDEOPORTBANDWIDTH struct
        dwSize DWORD ?
        ; Size of the structure
        dwCaps DWORD ?
        dwOverlay DWORD ?
        ; Zoom factor at which overlay is supported
        dwColorkey DWORD ?
        ; Zoom factor at which overlay w/ colorkey is supported
        dwYInterpolate DWORD ?
        ; Zoom factor at which overlay w/ Y interpolation is supported
        dwYInterpAndColorkey DWORD ?
        ; Zoom factor at which ovelray w/ Y interpolation and colorkeying is supported
        dwReserved1 XWORD ?
        ; Reserved for future use - set to zero
        dwReserved2 XWORD ?
        ; Reserved for future use - set to zero
      DDVIDEOPORTBANDWIDTH ends
      _DDVIDEOPORTBANDWIDTH typedef DDVIDEOPORTBANDWIDTH
      ;*
      ;* DDVIDEOPORTSTATUS
      ;*
      DDVIDEOPORTSTATUS struct
        dwSize DWORD ?
        ; Size of the structure
        bInUse DWORD ?
        ; TRUE if video port is currently being used
        dwFlags DWORD ?
        ; Currently not used
        dwReserved1 DWORD ?
        ; Reserved for future use
        VideoPortType DDVIDEOPORTCONNECT <>
        ; Information about the connection
        dwReserved2 XWORD ?
        ; Reserved for future use
        dwReserved3 XWORD ?
        ; Reserved for future use
      DDVIDEOPORTSTATUS ends
      _DDVIDEOPORTSTATUS typedef DDVIDEOPORTSTATUS
      ;*
      ;* DDVIDEOPORTNOTIFY
      ;*
      DDVIDEOPORTNOTIFY struct
        ApproximateTimeStamp LARGE_INTEGER <>
        ; Timestamp in the event notification
        lField SDWORD ?
        ; 0 if even, 1 if odd, -1 if unknown
        dwSurfaceIndex DWORD ?
        ; Index in the surface chain of the surface that received the sample
        lDone SDWORD ?
        ; Call InterlockedIncrement on this when done with sample
      DDVIDEOPORTNOTIFY ends
      _DDVIDEOPORTNOTIFY typedef DDVIDEOPORTNOTIFY
      ;*============================================================================
      ;*
      ;* Video Port Flags
      ;*
      ;* All flags are bit flags.
      ;*
      ;*==========================================================================*
      ;****************************************************************************
      ;*
      ;* VIDEOPORT DDVIDEOPORTCONNECT FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* When this is set by the driver and passed to the client, this
      ;* indicates that the video port is capable of double clocking the data.
      ;* When this is set by the client, this indicates that the video port
      ;* should enable double clocking.  This flag is only valid with external
      ;* syncs.
      ;*
      DDVPCONNECT_DOUBLECLOCK equ 00000001h
      ;*
      ;* When this is set by the driver and passed to the client, this
      ;* indicates that the video port is capable of using an external VACT
      ;* signal. When this is set by the client, this indicates that the
      ;* video port should use the external VACT signal.
      ;*
      DDVPCONNECT_VACT equ 00000002h
      ;*
      ;* When this is set by the driver and passed to the client, this
      ;* indicates that the video port is capable of treating even fields
      ;* like odd fields and visa versa.  When this is set by the client,
      ;* this indicates that the video port should treat even fields like odd
      ;* fields.
      ;*
      DDVPCONNECT_INVERTPOLARITY equ 00000004h
      ;*
      ;* Indicates that any data written to the video port during the VREF
      ;* period will not be written into the frame buffer. This flag is read only.
      ;*
      DDVPCONNECT_DISCARDSVREFDATA equ 00000008h
      ;*
      ;* When this is set be the driver and passed to the client, this
      ;* indicates that the device will write half lines into the frame buffer
      ;* if half lines are provided by the decoder.  If this is set by the client,
      ;* this indicates that the decoder will be supplying half lines.
      ;*
      DDVPCONNECT_HALFLINE equ 00000010h
      ;*
      ;* Indicates that the signal is interlaced. This flag is only
      ;* set by the client.
      ;*
      DDVPCONNECT_INTERLACED equ 00000020h
      ;*
      ;* Indicates that video port is shareable and that this video port
      ;* will use the even fields.  This flag is only set by the client.
      ;*
      DDVPCONNECT_SHAREEVEN equ 00000040h
      ;*
      ;* Indicates that video port is shareable and that this video port
      ;* will use the odd fields.  This flag is only set by the client.
      ;*
      DDVPCONNECT_SHAREODD equ 00000080h
      ;****************************************************************************
      ;*
      ;* VIDEOPORT DDVIDEOPORTDESC CAPS
      ;*
      ;****************************************************************************
      ;*
      ;* Flip can be performed automatically to avoid tearing.
      ;*
      DDVPCAPS_AUTOFLIP equ 00000001h
      ;*
      ;* Supports interlaced video
      ;*
      DDVPCAPS_INTERLACED equ 00000002h
      ;*
      ;* Supports non-interlaced video
      ;*
      DDVPCAPS_NONINTERLACED equ 00000004h
      ;*
      ;* Indicates that the device can return whether the current field
      ;* of an interlaced signal is even or odd.
      ;*
      DDVPCAPS_READBACKFIELD equ 00000008h
      ;*
      ;* Indicates that the device can return the current line of video
      ;* being written into the frame buffer.
      ;*
      DDVPCAPS_READBACKLINE equ 00000010h
      ;*
      ;* Allows two gen-locked video streams to share a single video port,
      ;* where one stream uses the even fields and the other uses the odd
      ;* fields. Separate parameters (including address, scaling,
      ;* cropping, etc.) are maintained for both fields.)
      ;*
      DDVPCAPS_SHAREABLE equ 00000020h
      ;*
      ;* Even fields of video can be automatically discarded.
      ;*
      DDVPCAPS_SKIPEVENFIELDS equ 00000040h
      ;*
      ;* Odd fields of video can be automatically discarded.
      ;*
      DDVPCAPS_SKIPODDFIELDS equ 00000080h
      ;*
      ;* Indicates that the device is capable of driving the graphics
      ;* VSYNC with the video port VSYNC.
      ;*
      DDVPCAPS_SYNCMASTER equ 00000100h
      ;*
      ;* Indicates that data within the vertical blanking interval can
      ;* be written to a different surface.
      ;*
      DDVPCAPS_VBISURFACE equ 00000200h
      ;*
      ;* Indicates that the video port can perform color operations
      ;* on the incoming data before it is written to the frame buffer.
      ;*
      DDVPCAPS_COLORCONTROL equ 00000400h
      ;*
      ;* Indicates that the video port can accept VBI data in a different
      ;* width or format than the regular video data.
      ;*
      DDVPCAPS_OVERSAMPLEDVBI equ 00000800h
      ;*
      ;* Indicates that the video port can write data directly to system memory
      ;*
      DDVPCAPS_SYSTEMMEMORY equ 00001000h
      ;*
      ;* Indicates that the VBI and video portions of the video stream can
      ;* be controlled by an independent processes.
      ;*
      DDVPCAPS_VBIANDVIDEOINDEPENDENT equ 00002000h
      ;*
      ;* Indicates that the video port contains high quality hardware
      ;* de-interlacing hardware that should be used instead of the
      ;* bob/weave algorithms.
      ;*
      DDVPCAPS_HARDWAREDEINTERLACE equ 00004000h
      ;****************************************************************************
      ;*
      ;* VIDEOPORT DDVIDEOPORTDESC FX
      ;*
      ;****************************************************************************
      ;*
      ;* Limited cropping is available to crop out the vertical interval data.
      ;*
      DDVPFX_CROPTOPDATA equ 00000001h
      ;*
      ;* Incoming data can be cropped in the X direction before it is written
      ;* to the surface.
      ;*
      DDVPFX_CROPX equ 00000002h
      ;*
      ;* Incoming data can be cropped in the Y direction before it is written
      ;* to the surface.
      ;*
      DDVPFX_CROPY equ 00000004h
      ;*
      ;* Supports interleaving interlaced fields in memory.
      ;*
      DDVPFX_INTERLEAVE equ 00000008h
      ;*
      ;* Supports mirroring left to right as the video data is written
      ;* into the frame buffer.
      ;*
      DDVPFX_MIRRORLEFTRIGHT equ 00000010h
      ;*
      ;* Supports mirroring top to bottom as the video data is written
      ;* into the frame buffer.
      ;*
      DDVPFX_MIRRORUPDOWN equ 00000020h
      ;*
      ;* Data can be arbitrarily shrunk in the X direction before it
      ;* is written to the surface.
      ;*
      DDVPFX_PRESHRINKX equ 00000040h
      ;*
      ;* Data can be arbitrarily shrunk in the Y direction before it
      ;* is written to the surface.
      ;*
      DDVPFX_PRESHRINKY equ 00000080h
      ;*
      ;* Data can be binary shrunk (1/2, 1/4, 1/8, etc.) in the X
      ;* direction before it is written to the surface.
      ;*
      DDVPFX_PRESHRINKXB equ 00000100h
      ;*
      ;* Data can be binary shrunk (1/2, 1/4, 1/8, etc.) in the Y
      ;* direction before it is written to the surface.
      ;*
      DDVPFX_PRESHRINKYB equ 00000200h
      ;*
      ;* Data can be shrunk in increments of 1/x in the X direction
      ;* (where X is specified in the DDVIDEOPORTCAPS.dwPreshrinkXStep)
      ;* before it is written to the surface.
      ;*
      DDVPFX_PRESHRINKXS equ 00000400h
      ;*
      ;* Data can be shrunk in increments of 1/x in the Y direction
      ;* (where X is specified in the DDVIDEOPORTCAPS.dwPreshrinkYStep)
      ;* before it is written to the surface.
      ;*
      DDVPFX_PRESHRINKYS equ 00000800h
      ;*
      ;* Data can be arbitrarily stretched in the X direction before
      ;* it is written to the surface.
      ;*
      DDVPFX_PRESTRETCHX equ 00001000h
      ;*
      ;* Data can be arbitrarily stretched in the Y direction before
      ;* it is written to the surface.
      ;*
      DDVPFX_PRESTRETCHY equ 00002000h
      ;*
      ;* Data can be integer stretched in the X direction before it is
      ;* written to the surface.
      ;*
      DDVPFX_PRESTRETCHXN equ 00004000h
      ;*
      ;* Data can be integer stretched in the Y direction before it is
      ;* written to the surface.
      ;*
      DDVPFX_PRESTRETCHYN equ 00008000h
      ;*
      ;* Indicates that data within the vertical blanking interval can
      ;* be converted independently of the remaining video data.
      ;*
      DDVPFX_VBICONVERT equ 00010000h
      ;*
      ;* Indicates that scaling can be disabled for data within the
      ;* vertical blanking interval.
      ;*
      DDVPFX_VBINOSCALE equ 00020000h
      ;*
      ;* Indicates that the video data can ignore the left and right
      ;* cropping coordinates when cropping oversampled VBI data.
      ;*
      DDVPFX_IGNOREVBIXCROP equ 00040000h
      ;*
      ;* Indicates that interleaving can be disabled for data within the
      ;* vertical blanking interval.
      ;*
      DDVPFX_VBINOINTERLEAVE equ 00080000h
      ;****************************************************************************
      ;*
      ;* VIDEOPORT DDVIDEOPORTINFO FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* Perform automatic flipping.   Auto-flipping is performed between
      ;* the overlay surface that was attached to the video port using
      ;* IDirectDrawVideoPort::AttachSurface and the overlay surfaces that
      ;* are attached to the surface via the IDirectDrawSurface::AttachSurface
      ;* method.  The flip order is the order in which the overlay surfaces
      ;* were. attached.
      ;*
      DDVP_AUTOFLIP equ 00000001h
      ;*
      ;* Perform conversion using the ddpfOutputFormat information.
      ;*
      DDVP_CONVERT equ 00000002h
      ;*
      ;* Perform cropping using the specified rectangle.
      ;*
      DDVP_CROP equ 00000004h
      ;*
      ;* Indicates that interlaced fields should be interleaved in memory.
      ;*
      DDVP_INTERLEAVE equ 00000008h
      ;*
      ;* Indicates that the data should be mirrored left to right as it's
      ;* written into the frame buffer.
      ;*
      DDVP_MIRRORLEFTRIGHT equ 00000010h
      ;*
      ;* Indicates that the data should be mirrored top to bottom as it's
      ;* written into the frame buffer.
      ;*
      DDVP_MIRRORUPDOWN equ 00000020h
      ;*
      ;* Perform pre-scaling/zooming based on the pre-scale parameters.
      ;*
      DDVP_PRESCALE equ 00000040h
      ;*
      ;* Ignore input of even fields.
      ;*
      DDVP_SKIPEVENFIELDS equ 00000080h
      ;*
      ;* Ignore input of odd fields.
      ;*
      DDVP_SKIPODDFIELDS equ 00000100h
      ;*
      ;* Drive the graphics VSYNCs using the video port VYSNCs.
      ;*
      DDVP_SYNCMASTER equ 00000200h
      ;*
      ;* The ddpfVBIOutputFormatFormat member contains data that should be used
      ;* to convert the data within the vertical blanking interval.
      ;*
      DDVP_VBICONVERT equ 00000400h
      ;*
      ;* Indicates that data within the vertical blanking interval
      ;* should not be scaled.
      ;*
      DDVP_VBINOSCALE equ 00000800h
      ;*
      ;* Indicates that these bob/weave decisions should not be
      ;* overriden by other interfaces.
      ;*
      DDVP_OVERRIDEBOBWEAVE equ 00001000h
      ;*
      ;* Indicates that the video data should ignore the left and right
      ;* cropping coordinates when cropping the VBI data.
      ;*
      DDVP_IGNOREVBIXCROP equ 00002000h
      ;*
      ;* Indicates that interleaving can be disabled for data within the
      ;* vertical blanking interval.
      ;*
      DDVP_VBINOINTERLEAVE equ 00004000h
      ;*
      ;* Indicates that the video port should use the hardware
      ;* de-interlacing hardware.
      ;*
      DDVP_HARDWAREDEINTERLACE equ 00008000h
      ;****************************************************************************
      ;*
      ;* DIRIRECTDRAWVIDEOPORT GETINPUTFORMAT/GETOUTPUTFORMAT FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* Return formats for the video data
      ;*
      DDVPFORMAT_VIDEO equ 00000001h
      ;*
      ;* Return formats for the VBI data
      ;*
      DDVPFORMAT_VBI equ 00000002h
      ;****************************************************************************
      ;*
      ;* DIRIRECTDRAWVIDEOPORT SETTARGETSURFACE FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* Surface should receive video data (and VBI data if a surface
      ;* is not explicitly attached for that purpose)
      ;*
      DDVPTARGET_VIDEO equ 00000001h
      ;*
      ;* Surface should receive VBI data
      ;*
      DDVPTARGET_VBI equ 00000002h
      ;****************************************************************************
      ;*
      ;* DIRIRECTDRAWVIDEOPORT WAITFORSYNC FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* Waits until the beginning of the next VSYNC
      ;*
      DDVPWAIT_BEGIN equ 00000001h
      ;*
      ;* Waits until the end of the next/current VSYNC
      ;*
      DDVPWAIT_END equ 00000002h
      ;*
      ;* Waits until the beginning of the specified line
      ;*
      DDVPWAIT_LINE equ 00000003h
      ;****************************************************************************
      ;*
      ;* DIRECTDRAWVIDEOPORT FLIP FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* Flips the normal video surface
      ;*
      DDVPFLIP_VIDEO equ 00000001h
      ;*
      ;* Flips the VBI surface
      ;*
      DDVPFLIP_VBI equ 00000002h
      ;****************************************************************************
      ;*
      ;* DIRIRECTDRAWVIDEOPORT GETVIDEOSIGNALSTATUS VALUES
      ;*
      ;****************************************************************************
      ;*
      ;* No video signal is present at the video port
      ;*
      DDVPSQ_NOSIGNAL equ 00000001h
      ;*
      ;* A valid video signal is present at the video port
      ;*
      DDVPSQ_SIGNALOK equ 00000002h
      ;****************************************************************************
      ;*
      ;* VIDEOPORTBANDWIDTH Flags
      ;*
      ;****************************************************************************
      ;*
      ;* The specified height/width refer to the size of the video port data
      ;* written into memory, after prescaling has occured.
      ;*
      DDVPB_VIDEOPORT equ 00000001h
      ;*
      ;* The specified height/width refer to the source size of the overlay.
      ;*
      DDVPB_OVERLAY equ 00000002h
      ;*
      ;* This is a query for the device to return which caps this device requires.
      ;*
      DDVPB_TYPE equ 00000004h
      ;****************************************************************************
      ;*
      ;* VIDEOPORTBANDWIDTH Caps
      ;*
      ;****************************************************************************
      ;*
      ;* The bandwidth for this device is dependant on the overlay source size.
      ;*
      DDVPBCAPS_SOURCE equ 00000001h
      ;*
      ;* The bandwidth for this device is dependant on the overlay destination
      ;* size.
      ;*
      DDVPBCAPS_DESTINATION equ 00000002h
      ;****************************************************************************
      ;*
      ;* DDVIDEOPORTCONTAINER CreateVideoPort flags
      ;*
      ;****************************************************************************
      ;*
      ;* The process only wants to control the VBI portion of the video stream.
      ;*
      DDVPCREATE_VBIONLY equ 00000001h
      ;*
      ;* The process only wants to control the non-VBI (video) portion of
      ;* the video stream.
      ;*
      DDVPCREATE_VIDEOONLY equ 00000002h
      ;****************************************************************************
      ;*
      ;* DDVIDEOPORTSTATUS flags
      ;*
      ;****************************************************************************
      ;*
      ;* The video port interface is only controlling the VBI portion of the
      ;* video stream
      ;*
      DDVPSTATUS_VBIONLY equ 00000001h
      ;*
      ;* The video port interface is only controlling the video portion of the
      ;* video stream
      ;*
      DDVPSTATUS_VIDEOONLY equ 00000002h
      ifdef __cplusplus
        ;[...]
      endif
    endif
    ; GUID_DEFS_ONLY
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
