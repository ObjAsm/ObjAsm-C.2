;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ddrawi.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:52:26

;***************************************************************************
ifndef __DDRAWI_INCLUDED__
  __DDRAWI_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; This is a helper for external driver builds.
    if ( not Defined(WIN95)) and ( not Defined(WINNT))
      WIN95 equ <>
    endif
    ;*
    ;* METAQUESTION: Why are Windows handles stored as DWORDs instead of
    ;*       their proper types?
    ;* METAANSWER:   To make the thunk to the 16-bit side completely painless.
    ;*
    OBJECT_ISROOT equ 80000000h; object is root object

    ;*
    ;* stuff for drivers
    ;*
    ifndef _WIN32
      ;[...]
      ; !defined(GUID_DEFINED)
    endif
    ;*
    ;* These definitions are required to allow polymorphic structure members (i.e. those
    ;* that are referred to both as DWORDs and as pointers) to resolve into a type
    ;* of correct size to hold the largest of those two types (i.e. pointer) on 64 bit
    ;* systems. For 32 bit environments, ULONG_PTR resolves to a DWORD.
    ;*
    ifndef MAXULONG_PTR
      ULONG_PTR equ <DWORD>
      PULONG_PTR equ <LPDWORD>
    endif
    ;MAXULONG_PTR
    include ddraw.inc
    include dvp.inc
    include ddkernel.inc
    include dmemmgr.inc
    ifdef IS_16
      ; ddraw16 16-bit compiler cannot handle 32-bit d3d headers included by d3dhal.h
      ; so for ddraw16 build, explicitly list d3dhal ptr types here
      LPD3DHAL_GLOBALDRIVERDATA equ <ULONG_PTR>
      LPD3DHAL_CALLBACKS equ <ULONG_PTR>
      LPD3DHAL_CALLBACKS2 equ <ULONG_PTR>
      LPD3DHAL_CALLBACKS3 equ <ULONG_PTR>
      LPD3DHAL_D3DEXTENDEDCAPS equ <ULONG_PTR>
      LPD3DHAL_COMMANDBUFFERCALLBACKS equ <ULONG_PTR>
    endif
    ifndef _WIN32
      ;[...]
    endif
    DDUNSUPPORTEDMODE equ (- 1)
    VALID_ALIGNMENT macro align_
      exitm <(! ((align_ == 0) or (align_ % 2) != 0))>
    endm
    ifdef _WIN32
      ;*
      ;* These GUIDs are used to identify driver info structures, not interfaces,
      ;* so the prefix GUID_ is used instead of IID_.
      ;*
      ;*
      DEFINE_GUID GUID_MiscellaneousCallbacks, 0efd60cc0h, 49e7h, 11d0h, 88h, 9dh, 00h, 0aah, 00h, 0bbh, 0b7h, 6ah
      DEFINE_GUID GUID_VideoPortCallbacks, 0efd60cc1h, 49e7h, 11d0h, 88h, 9dh, 00h, 0aah, 00h, 0bbh, 0b7h, 6ah
      DEFINE_GUID GUID_ColorControlCallbacks, 0efd60cc2h, 49e7h, 11d0h, 88h, 9dh, 00h, 0aah, 00h, 0bbh, 0b7h, 6ah
      DEFINE_GUID GUID_VideoPortCaps, 0efd60cc3h, 49e7h, 11d0h, 88h, 9dh, 00h, 0aah, 00h, 0bbh, 0b7h, 6ah
      DEFINE_GUID GUID_D3DCallbacks2, 0ba584e1h, 70b6h, 11d0h, 88h, 9dh, 00h, 0aah, 00h, 0bbh, 0b7h, 6ah
      DEFINE_GUID GUID_D3DCallbacks3, 0ddf41230h, 0ec0ah, 11d0h, 0a9h, 0b6h, 00h, 0aah, 00h, 0c0h, 99h, 3eh
      DEFINE_GUID GUID_NonLocalVidMemCaps, 86c4fa80h, 8d84h, 11d0h, 94h, 0e8h, 00h, 0c0h, 4fh, 0c3h, 41h, 37h
      DEFINE_GUID GUID_KernelCallbacks, 80863800h, 6B06h, 11D0h, 9Bh, 06h, 0h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID GUID_KernelCaps, 0FFAA7540h, 7AA8h, 11D0h, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID GUID_D3DExtendedCaps, 7de41f80h, 9d93h, 11d0h, 89h, 0abh, 0h, 0a0h, 0c9h, 5h, 41h, 29h
      DEFINE_GUID GUID_ZPixelFormats, 93869880h, 36cfh, 11d1h, 9bh, 1bh, 0h, 0aah, 0h, 0bbh, 0b8h, 0aeh
      DEFINE_GUID GUID_DDMoreSurfaceCaps, 3b8a0466h, 0f269h, 11d1h, 88h, 0bh, 0h, 0c0h, 4fh, 0d9h, 30h, 0c5h
      DEFINE_GUID GUID_DDStereoMode, 0f828169ch, 0a8e8h, 11d2h, 0a1h, 0f2h, 0h, 0a0h, 0c9h, 83h, 0eah, 0f6h
      DEFINE_GUID GUID_OptSurfaceKmodeInfo, 0e05c8472h, 51d4h, 11d1h, 8ch, 0ceh, 0h, 0a0h, 0c9h, 6h, 29h, 0a8h
      DEFINE_GUID GUID_OptSurfaceUmodeInfo, 9d792804h, 5fa8h, 11d1h, 8ch, 0d0h, 0h, 0a0h, 0c9h, 6h, 29h, 0a8h
      DEFINE_GUID GUID_UserModeDriverInfo, 0f0b0e8e2h, 5f97h, 11d1h, 8ch, 0d0h, 0h, 0a0h, 0c9h, 6h, 29h, 0a8h
      DEFINE_GUID GUID_UserModeDriverPassword, 97f861b6h, 60a1h, 11d1h, 8ch, 0d0h, 0h, 0a0h, 0c9h, 6h, 29h, 0a8h
      DEFINE_GUID GUID_D3DParseUnknownCommandCallback, 2e04ffa0h, 98e4h, 11d1h, 8ch, 0e1h, 0h, 0a0h, 0c9h, 6h, 29h, 0a8h
      DEFINE_GUID GUID_MotionCompCallbacks, 0b1122b40h, 5dA5h, 11d1h, 8fh, 0cFh, 00h, 0c0h, 4fh, 0c2h, 9bh, 4eh
      DEFINE_GUID GUID_Miscellaneous2Callbacks, 406B2F00h, 3E5Ah, 11D1h, 0B6h, 40h, 00h, 0AAh, 00h, 0A1h, 0F9h, 6Ah
    endif
    ;_WIN32
    ; The Callback that the drivers can use to parse unknown commands
    ; passed to them via the DrawPrimitives2 callback. The driver obtains this
    ; callback thru a GetDriverInfo call with GUID_D3DParseUnknownCommandCallback
    ; made by ddraw somewhere around the initialization time.
    ifdef __cplusplus
      ;[...]
    endif
    D3DParseUnknownCommand proto WIN_STD_CALL_CONV :LPVOID, :ptr LPVOID
    ;*
    ;* This DDPF flag is used by drivers to signify that this format is new and may be
    ;* a candidate for hiding from certain applications
    ;* KEEP THIS DEFINITION IN SYNC WITH THAT OF DDPF_RESERVED1 IN DDRAW.H
    ;*
    DDPF_NOVEL_TEXTURE_FORMAT equ 00100000h
    ;*
    ;* This DDPF flag is used to indicate a DX8+ format capability entry in
    ;* the texture format list. It is not visible to applications.
    ;*
    DDPF_D3DFORMAT equ 00200000h
    ;*
    ;* List of operations supported on formats in DX8+ texture list.
    ;* See the DX8 DDK for a complete description of these flags.
    ;*
    D3DFORMAT_OP_TEXTURE equ 00000001h
    D3DFORMAT_OP_VOLUMETEXTURE equ 00000002h
    D3DFORMAT_OP_CUBETEXTURE equ 00000004h
    D3DFORMAT_OP_OFFSCREEN_RENDERTARGET equ 00000008h
    D3DFORMAT_OP_SAME_FORMAT_RENDERTARGET equ 00000010h
    D3DFORMAT_OP_ZSTENCIL equ 00000040h
    D3DFORMAT_OP_ZSTENCIL_WITH_ARBITRARY_COLOR_DEPTH equ 00000080h
    ; This format can be used as a render target if the current display mode
    ; is the same depth if the alpha channel is ignored. e.g. if the device 
    ; can render to A8R8G8B8 when the display mode is X8R8G8B8, then the
    ; format op list entry for A8R8G8B8 should have this cap. 
    D3DFORMAT_OP_SAME_FORMAT_UP_TO_ALPHA_RENDERTARGET equ 00000100h
    ; This format contains DirectDraw support (including Flip).  This flag
    ; should not to be set on alpha formats.
    D3DFORMAT_OP_DISPLAYMODE equ 00000400h
    ; The rasterizer can support some level of Direct3D support in this format
    ; and implies that the driver can create a Context in this mode (for some 
    ; render target format).  When this flag is set, the D3DFORMAT_OP_DISPLAYMODE
    ; flag must also be set.
    D3DFORMAT_OP_3DACCELERATION equ 00000800h
    ; If the driver needs a private format to be D3D or driver manageable,
    ; then it needs to tell D3D the pixelsize in bits per pixel by setting
    ; dwPrivateFormatBitCount in DDPIXELFORMAT and by setting the below
    ; format op. If the below format op is not set, then D3D or the driver
    ; will NOT be allowed to manage the format.
    D3DFORMAT_OP_PIXELSIZE equ 00001000h
    ; Indicates that this format can be converted to any RGB format for which
    ; D3DFORMAT_MEMBEROFGROUP_ARGB is specified
    D3DFORMAT_OP_CONVERT_TO_ARGB equ 00002000h
    ; Indicates that this format can be used to create offscreen plain surfaces.
    D3DFORMAT_OP_OFFSCREENPLAIN equ 00004000h
    ; Indicated that this format can be read as an SRGB texture (meaning that the
    ; sampler will linearize the looked up data)
    D3DFORMAT_OP_SRGBREAD equ 00008000h
    ; Indicates that this format can be used in the bumpmap instructions
    D3DFORMAT_OP_BUMPMAP equ 00010000h
    ; Indicates that this format can be sampled by the displacement map sampler
    D3DFORMAT_OP_DMAP equ 00020000h
    ; Indicates that this format cannot be used with texture filtering
    D3DFORMAT_OP_NOFILTER equ 00040000h
    ; Indicates that format conversions are supported to this RGB format if
    ; D3DFORMAT_OP_CONVERT_TO_ARGB is specified in the source format.
    D3DFORMAT_MEMBEROFGROUP_ARGB equ 00080000h
    ; Indicated that this format can be written as an SRGB target (meaning that the
    ; pixel pipe will DE-linearize data on output to format)
    D3DFORMAT_OP_SRGBWRITE equ 00100000h
    ; Indicates that this format cannot be used with alpha blending
    D3DFORMAT_OP_NOALPHABLEND equ 00200000h
    ;Indicates that the device can auto-generated sublevels for resources
    ;of this format
    D3DFORMAT_OP_AUTOGENMIPMAP equ 00400000h
    ; Indicates that this format cannot be used by vertex texture sampler
    D3DFORMAT_OP_VERTEXTEXTURE equ 00800000h
    ; Indicates that this format supports neither texture coordinate wrap modes, nor mipmapping
    D3DFORMAT_OP_NOTEXCOORDWRAPNORMIP equ 01000000h
    ;*
    ;* List of processes attached to a DirectDraw object
    ;*
    PROCESS_LIST struct
      lpLink POINTER ?
      dwProcessId DWORD ?
      dwRefCnt DWORD ?
      dwAlphaDepth DWORD ?
      dwZDepth DWORD ?
    PROCESS_LIST ends
    _PROCESS_LIST typedef PROCESS_LIST
    LPPROCESS_LIST typedef ptr PROCESS_LIST
    ;*
    ;* Information about the refresh rates that monitor/display card can support
    ;*
    DDMONITORINFO struct
      Manufacturer WORD ?
      ; Montor manufacturer
      Product WORD ?
      ; Monitor product ID
      SerialNumber DWORD ?
      ; Monitor serial number
      DeviceIdentifier GUID <>
      ; From DDDEVICEIDENTIFIER, describes card/driver
      Mode640x480 SDWORD ?
      ; Highest refresh rate support, 0 if none, -1 if untested
      Mode800x600 SDWORD ?
      Mode1024x768 SDWORD ?
      Mode1280x1024 SDWORD ?
      Mode1600x1200 SDWORD ?
      ModeReserved1 SDWORD ?
      ModeReserved2 SDWORD ?
      ModeReserved3 SDWORD ?
    DDMONITORINFO ends
    _DDMONITORINFO typedef DDMONITORINFO
    LPDDMONITORINFO typedef ptr DDMONITORINFO
    ;*
    ;* DeleteFromActiveProcessList return codes
    ;*
    DELETED_OK equ 0
    DELETED_LASTONE equ 1
    DELETED_NOTFOUND equ 2
    DDBLT_ANYALPHA equ <(DDBLT_ALPHASRCSURFACEOVERRIDE or DDBLT_ALPHASRCCONSTOVERRIDE or DDBLT_ALPHASRC or DDBLT_ALPHADESTSURFACEOVERRIDE or DDBLT_ALPHADESTCONSTOVERRIDE or DDBLT_ALPHADEST)>
    DDOVER_ANYALPHA equ <(DDOVER_ALPHASRCSURFACEOVERRIDE or DDOVER_ALPHASRCCONSTOVERRIDE or DDOVER_ALPHASRC or DDOVER_ALPHADESTSURFACEOVERRIDE or DDOVER_ALPHADESTCONSTOVERRIDE or DDOVER_ALPHADEST)>
    DIRECTDRAWCLIPPERCALLBACKS typedef IDirectDrawClipperVtbl
    DIRECTDRAWPALETTECALLBACKS typedef IDirectDrawPaletteVtbl
    DIRECTDRAWSURFACECALLBACKS typedef IDirectDrawSurfaceVtbl
    DIRECTDRAWSURFACE2CALLBACKS typedef IDirectDrawSurface2Vtbl
    DIRECTDRAWSURFACE3CALLBACKS typedef IDirectDrawSurface3Vtbl
    DIRECTDRAWSURFACE4CALLBACKS typedef IDirectDrawSurface4Vtbl
    DIRECTDRAWSURFACE7CALLBACKS typedef IDirectDrawSurface7Vtbl
    DIRECTDRAWCOLORCONTROLCALLBACKS typedef IDirectDrawColorControlVtbl
    DIRECTDRAWCALLBACKS typedef IDirectDrawVtbl
    DIRECTDRAW2CALLBACKS typedef IDirectDraw2Vtbl
    DIRECTDRAW4CALLBACKS typedef IDirectDraw4Vtbl
    DIRECTDRAW7CALLBACKS typedef IDirectDraw7Vtbl
    DIRECTDRAWKERNELCALLBACKS typedef IDirectDrawKernelVtbl
    DIRECTDRAWSURFACEKERNELCALLBACKS typedef IDirectDrawSurfaceKernelVtbl
    DIRECTDRAWGAMMACONTROLCALLBACKS typedef IDirectDrawGammaControlVtbl
    LPDIRECTDRAWCLIPPERCALLBACKS typedef ptr DIRECTDRAWCLIPPERCALLBACKS
    LPDIRECTDRAWPALETTECALLBACKS typedef ptr DIRECTDRAWPALETTECALLBACKS
    LPDIRECTDRAWSURFACECALLBACKS typedef ptr DIRECTDRAWSURFACECALLBACKS
    LPDIRECTDRAWCALLBACKS typedef ptr DIRECTDRAWCALLBACKS
    ifdef __cplusplus
      ;[...]
    endif
    if Defined(IS_32) or Defined(WIN32) or Defined(_WIN32)
      IS_32 equ <>
      DDAPI equ <WINAPI>
      EXTERN_DDAPI equ <WINAPI>
    else
      ;[...]
    endif
    ;*
    ;* DCI escape
    ;*
    ifndef DCICOMMAND
      DCICOMMAND equ 3075; escape value

    endif
    ;*
    ;* this is the DirectDraw version
    ;* passed to the driver in DCICMD.dwVersion
    ;*
    ;* Most older HALs will fail if DD_VERSION does not match what they
    ;* are expecting.  Therefore, DD_VERSION cannot change if we want DX5+ to
    ;* run on DX2/3 HALs.  For this reason, we added a new version call that
    ;* allows the HAL to know the real version of DirectDraw, which is equal
    ;* to DD_RUNTIME_VERSION.  This is for informational purposes only.  HALs
    ;* should not fail DirectDraw if they receive an unknown DirectDraw runtime
    ;* version.
    ;*
    DD_VERSION equ 00000200h
    DD_RUNTIME_VERSION equ 00000902h
    ;*
    ;* this is the HAL version.
    ;* the driver returns this number from QUERYESCSUPPORT/DCICOMMAND
    ;*
    DD_HAL_VERSION equ 0100h
    include dciddi.inc
    DDCREATEDRIVEROBJECT equ 10; create an object

    DDGET32BITDRIVERNAME equ 11; get a 32-bit driver name

    DDNEWCALLBACKFNS equ 12; new callback fns coming

    DDVERSIONINFO equ 13; tells driver the ddraw version

    DD32BITDRIVERDATA struct
      szName SBYTE 260 dup (?)
      ; 32-bit driver name
      szEntryPoint SBYTE 64 dup (?)
      ; entry point
      dwContext DWORD ?
      ; context to pass to entry point
    DD32BITDRIVERDATA ends
    LPDD32BITDRIVERDATA typedef ptr DD32BITDRIVERDATA
    DDVERSIONDATA struct
      dwHALVersion DWORD ?
      ; Version of DirectDraw for which the HAL was created
      dwReserved1 XWORD ?
      ; Reserved for future use
      dwReserved2 XWORD ?
      ; Reserved for future use
    DDVERSIONDATA ends
    LPDDVERSIONDATA typedef ptr DDVERSIONDATA
    TYPE_LPDD32BITDRIVERINIT typedef proto WIN_STD_CALL_CONV :DWORD
    LPDD32BITDRIVERINIT typedef ptr TYPE_LPDD32BITDRIVERINIT

    ;*
    ;* pointer to video meory
    ;*
    FLATPTR typedef ULONG_PTR
    ;*
    ;* indicates that DDRAW.DLL has been unloaded...
    ;*
    DDRAW_DLL_UNLOADED equ 1
    ;*
    ;* critical section types
    ;*
    CSECT_HANDLE typedef LPVOID
    ifdef NOUSE_CRITSECTS
      CSECT typedef xxx
      ; generate an error for now
    else
      if Defined(IS_32) and  not Defined(_NOCSECT_TYPE)
        CSECT typedef CRITICAL_SECTION
        LPCSECT typedef ptr CSECT
      else
        CSECT struct
          vals DWORD 6 dup (?)
        CSECT ends
        LPCSECT typedef ptr
      endif
    endif
    ;*
    ;* DLL names
    ;*
    DDHAL_DRIVER_DLLNAME equ <"DDRAW16.DLL">
    DDHAL_APP_DLLNAME equ <"DDRAW.DLL">
    ;*
    ;* maximum size of a driver name
    ;*
    ifndef CCHDEVICENAME
      CCHDEVICENAME equ 32
    endif
    MAX_DRIVER_NAME equ <CCHDEVICENAME>
    ;*
    ;* largest palette supported
    ;*
    MAX_PALETTE_SIZE equ 256
    ;*
    ;* maximum number of surfaces that can be autoflipped between
    ;*
    MAX_AUTOFLIP_BUFFERS equ 10
    ;*
    ;* Indicates the surface is an execute buffer, i.e., a linear chunk of system
    ;* or video memory that holds a Direct3D display list. A driver reports this
    ;* cap to indicate that it can create execute buffers in video memory and
    ;* Direct3D uses this bit to request execute buffers. However, it is not
    ;* visible to via the API.
    ;*
    DDSCAPS_EXECUTEBUFFER equ <DDSCAPS_RESERVED2>
    ;*
    ;* Indicates to the driver that the "execute" buffer that is to be created is actually
    ;* a vertex buffer. Used by CreateVertexBuffer in D3D
    ;*
    DDSCAPS2_VERTEXBUFFER equ <DDSCAPS2_RESERVED1>
    ;*
    ;* Indicates to the driver that the "execute" buffer that is to be created is actually
    ;* a command buffer. Used by internally in D3D
    ;*
    DDSCAPS2_COMMANDBUFFER equ <DDSCAPS2_RESERVED2>
    ;*
    ;* Indicates to the driver that the "execute" buffer that is to be created is actually
    ;* an index buffer.
    ;*
    DDSCAPS2_INDEXBUFFER equ <DDSCAPS2_RESERVED3>
    ;*
    ;* Indicates to the driver that the render target contains video data
    ;*
    DDSCAPS3_VIDEO equ <DDSCAPS3_RESERVED2>
    ;*
    ;* Internal formats are not exposed to applications.
    ;*
    D3DFMT_INTERNAL_D32 equ 71
    D3DFMT_INTERNAL_S1D15 equ 72
    D3DFMT_INTERNAL_D15S1 equ 73
    D3DFMT_INTERNAL_S8D24 equ 74
    D3DFMT_INTERNAL_D24S8 equ 75
    D3DFMT_INTERNAL_X8D24 equ 76
    D3DFMT_INTERNAL_D24X8 equ 77
    ;*
    ;* pre-declare pointers to structs containing data for DDHAL fns
    ;*
    LPDDHAL_CREATEPALETTEDATA typedef ptr _DDHAL_CREATEPALETTEDATA
    LPDDHAL_CREATESURFACEDATA typedef ptr _DDHAL_CREATESURFACEDATA
    LPDDHAL_CANCREATESURFACEDATA typedef ptr _DDHAL_CANCREATESURFACEDATA
    LPDDHAL_WAITFORVERTICALBLANKDATA typedef ptr _DDHAL_WAITFORVERTICALBLANKDATA
    LPDDHAL_DESTROYDRIVERDATA typedef ptr _DDHAL_DESTROYDRIVERDATA
    LPDDHAL_SETMODEDATA typedef ptr _DDHAL_SETMODEDATA
    LPDDHAL_DRVSETCOLORKEYDATA typedef ptr _DDHAL_DRVSETCOLORKEYDATA
    LPDDHAL_GETSCANLINEDATA typedef ptr _DDHAL_GETSCANLINEDATA
    LPDDHAL_DESTROYPALETTEDATA typedef ptr _DDHAL_DESTROYPALETTEDATA
    LPDDHAL_SETENTRIESDATA typedef ptr _DDHAL_SETENTRIESDATA
    LPDDHAL_BLTDATA typedef ptr _DDHAL_BLTDATA
    LPDDHAL_LOCKDATA typedef ptr _DDHAL_LOCKDATA
    LPDDHAL_UNLOCKDATA typedef ptr _DDHAL_UNLOCKDATA
    LPDDHAL_UPDATEOVERLAYDATA typedef ptr _DDHAL_UPDATEOVERLAYDATA
    LPDDHAL_SETOVERLAYPOSITIONDATA typedef ptr _DDHAL_SETOVERLAYPOSITIONDATA
    LPDDHAL_SETPALETTEDATA typedef ptr _DDHAL_SETPALETTEDATA
    LPDDHAL_FLIPDATA typedef ptr _DDHAL_FLIPDATA
    LPDDHAL_DESTROYSURFACEDATA typedef ptr _DDHAL_DESTROYSURFACEDATA
    LPDDHAL_SETCLIPLISTDATA typedef ptr _DDHAL_SETCLIPLISTDATA
    LPDDHAL_ADDATTACHEDSURFACEDATA typedef ptr _DDHAL_ADDATTACHEDSURFACEDATA
    LPDDHAL_SETCOLORKEYDATA typedef ptr _DDHAL_SETCOLORKEYDATA
    LPDDHAL_GETBLTSTATUSDATA typedef ptr _DDHAL_GETBLTSTATUSDATA
    LPDDHAL_GETFLIPSTATUSDATA typedef ptr _DDHAL_GETFLIPSTATUSDATA
    LPDDHAL_SETEXCLUSIVEMODEDATA typedef ptr _DDHAL_SETEXCLUSIVEMODEDATA
    LPDDHAL_FLIPTOGDISURFACEDATA typedef ptr _DDHAL_FLIPTOGDISURFACEDATA
    LPDDHAL_CANCREATEVPORTDATA typedef ptr _DDHAL_CANCREATEVPORTDATA
    LPDDHAL_CREATEVPORTDATA typedef ptr _DDHAL_CREATEVPORTDATA
    LPDDHAL_FLIPVPORTDATA typedef ptr _DDHAL_FLIPVPORTDATA
    LPDDHAL_GETVPORTCONNECTDATA typedef ptr _DDHAL_GETVPORTCONNECTDATA
    LPDDHAL_GETVPORTBANDWIDTHDATA typedef ptr _DDHAL_GETVPORTBANDWIDTHDATA
    LPDDHAL_GETVPORTINPUTFORMATDATA typedef ptr _DDHAL_GETVPORTINPUTFORMATDATA
    LPDDHAL_GETVPORTOUTPUTFORMATDATA typedef ptr _DDHAL_GETVPORTOUTPUTFORMATDATA
    LPDDHAL_GETVPORTFIELDDATA typedef ptr _DDHAL_GETVPORTFIELDDATA
    LPDDHAL_GETVPORTLINEDATA typedef ptr _DDHAL_GETVPORTLINEDATA
    LPDDHAL_DESTROYVPORTDATA typedef ptr _DDHAL_DESTROYVPORTDATA
    LPDDHAL_GETVPORTFLIPSTATUSDATA typedef ptr _DDHAL_GETVPORTFLIPSTATUSDATA
    LPDDHAL_UPDATEVPORTDATA typedef ptr _DDHAL_UPDATEVPORTDATA
    LPDDHAL_WAITFORVPORTSYNCDATA typedef ptr _DDHAL_WAITFORVPORTSYNCDATA
    LPDDHAL_GETVPORTSIGNALDATA typedef ptr _DDHAL_GETVPORTSIGNALDATA
    LPDDHAL_VPORTCOLORDATA typedef ptr _DDHAL_VPORTCOLORDATA
    LPDDHAL_COLORCONTROLDATA typedef ptr _DDHAL_COLORCONTROLDATA
    LPDDHAL_GETAVAILDRIVERMEMORYDATA typedef ptr _DDHAL_GETAVAILDRIVERMEMORYDATA
    LPDDHAL_UPDATENONLOCALHEAPDATA typedef ptr _DDHAL_UPDATENONLOCALHEAPDATA
    LPDDHAL_GETHEAPALIGNMENTDATA typedef ptr _DDHAL_GETHEAPALIGNMENTDATA
    LPDDHAL_GETDRIVERINFODATA typedef ptr _DDHAL_GETDRIVERINFODATA
    LPDDHAL_SYNCSURFACEDATA typedef ptr _DDHAL_SYNCSURFACEDATA
    LPDDHAL_SYNCVIDEOPORTDATA typedef ptr _DDHAL_SYNCVIDEOPORTDATA
    LPDDHAL_GETMOCOMPGUIDSDATA typedef ptr _DDHAL_GETMOCOMPGUIDSDATA
    LPDDHAL_GETMOCOMPFORMATSDATA typedef ptr _DDHAL_GETMOCOMPFORMATSDATA
    LPDDHAL_CREATEMOCOMPDATA typedef ptr _DDHAL_CREATEMOCOMPDATA
    LPDDHAL_GETMOCOMPCOMPBUFFDATA typedef ptr _DDHAL_GETMOCOMPCOMPBUFFDATA
    LPDDHAL_GETINTERNALMOCOMPDATA typedef ptr _DDHAL_GETINTERNALMOCOMPDATA
    LPDDHAL_BEGINMOCOMPFRAMEDATA typedef ptr _DDHAL_BEGINMOCOMPFRAMEDATA
    LPDDHAL_ENDMOCOMPFRAMEDATA typedef ptr _DDHAL_ENDMOCOMPFRAMEDATA
    LPDDHAL_RENDERMOCOMPDATA typedef ptr _DDHAL_RENDERMOCOMPDATA
    LPDDHAL_QUERYMOCOMPSTATUSDATA typedef ptr _DDHAL_QUERYMOCOMPSTATUSDATA
    LPDDHAL_DESTROYMOCOMPDATA typedef ptr _DDHAL_DESTROYMOCOMPDATA
    LPDDHAL_CREATESURFACEEXDATA typedef ptr _DDHAL_CREATESURFACEEXDATA
    LPDDHAL_GETDRIVERSTATEDATA typedef ptr _DDHAL_GETDRIVERSTATEDATA
    LPDDHAL_DESTROYDDLOCALDATA typedef ptr _DDHAL_DESTROYDDLOCALDATA
    ;*
    ;* value in the fpVidMem; indicates dwBlockSize is valid (surface object)
    ;*
    DDHAL_PLEASEALLOC_BLOCKSIZE equ 00000002h
    ;*
    ;* Values in fpVidMem: Indicates dwLinearSizde is valid.
    ;* THIS VALUE CAN ONLY BE USED BY A D3D Optimize DRIVER FUNCTION
    ;* IT IS INVALID FOR A DRIVER TO RETURN THIS VALUE FROM CreateSurface32.
    ;*
    DDHAL_PLEASEALLOC_LINEARSIZE equ 00000003h
    ;*
    ;* DRIVER SERVICES
    ;*
    ;* These services exported from ddraw.dll can be called by the HAL.
    ;* They are intended for use by the d3d Optimize HAL call.
    ;*
    LateAllocateSurfaceMem proto WIN_STD_CALL_CONV :LPDIRECTDRAWSURFACE, :DWORD, :DWORD, :DWORD
    GetNextMipMap proto WIN_STD_CALL_CONV :LPDIRECTDRAWSURFACE
    ;*
    ;* video memory data structures (passed in DDHALINFO)
    ;*
    VIDMEM struct
      dwFlags DWORD ?
      ; flags
      fpStart FLATPTR ?
      ; start of memory chunk
      union
        fpEnd FLATPTR ?
        ; end of memory chunk
        dwWidth DWORD ?
        ; width of chunk (rectanglar memory)
      ends
      ddsCaps DDSCAPS <>
      ; what this memory CANNOT be used for
      ddsCapsAlt DDSCAPS <>
      ; what this memory CANNOT be used for if it must
      union
        lpHeap LPVMEMHEAP ?
        ; heap pointer, used by DDRAW
        dwHeight DWORD ?
        ; height of chunk (rectanguler memory)
      ends
    VIDMEM ends
    _VIDMEM typedef VIDMEM
    LPVIDMEM typedef ptr VIDMEM
    ;*
    ;* flags for vidmem struct
    ;*
    VIDMEM_ISLINEAR equ 00000001h; heap is linear

    VIDMEM_ISRECTANGULAR equ 00000002h; heap is rectangular

    VIDMEM_ISHEAP equ 00000004h; heap is preallocated by driver

    VIDMEM_ISNONLOCAL equ 00000008h; heap populated with non-local video memory

    VIDMEM_ISWC equ 00000010h; heap populated with write combining memory

    VIDMEM_HEAPDISABLED equ 00000020h; heap disabled

    VIDMEMINFO struct
      fpPrimary FLATPTR ?
      ;* 0*
      ; pointer to primary surface
      dwFlags DWORD ?
      ;* 4*
      ; flags
      dwDisplayWidth DWORD ?
      ;* 8*
      ; current display width
      dwDisplayHeight DWORD ?
      ;* c*
      ; current display height
      lDisplayPitch SDWORD ?
      ;*10*
      ; current display pitch
      ddpfDisplay DDPIXELFORMAT <>
      ;*14*
      ; pixel format of display
      dwOffscreenAlign DWORD ?
      ;*34*
      ; byte alignment for offscreen surfaces
      dwOverlayAlign DWORD ?
      ;*38*
      ; byte alignment for overlays
      dwTextureAlign DWORD ?
      ;*3c*
      ; byte alignment for textures
      dwZBufferAlign DWORD ?
      ;*40*
      ; byte alignment for z buffers
      dwAlphaAlign DWORD ?
      ;*44*
      ; byte alignment for alpha
      dwNumHeaps DWORD ?
      ;*48*
      ; number of memory heaps in vmList
      pvmList LPVIDMEM ?
      ;*4c*
      ; array of heaps
    VIDMEMINFO ends
    _VIDMEMINFO typedef VIDMEMINFO
    LPVIDMEMINFO typedef ptr VIDMEMINFO
    ; PRIVATE
    HEAPALIAS struct
      fpVidMem FLATPTR ?
      ; start of aliased vid mem
      lpAlias POINTER ?
      ; start of heap alias
      dwAliasSize DWORD ?
      ; size of alias allocated
    HEAPALIAS ends
    _HEAPALIAS typedef HEAPALIAS
    LPHEAPALIAS typedef ptr HEAPALIAS
    ; PRIVATE
    HEAPALIASINFO struct
      dwRefCnt DWORD ?
      ; reference count of these aliases
      dwFlags DWORD ?
      ; flags
      dwNumHeaps DWORD ?
      ; number of aliased heaps
      lpAliases LPHEAPALIAS ?
      ; array of heaps
    HEAPALIASINFO ends
    _HEAPALIASINFO typedef HEAPALIASINFO
    LPHEAPALIASINFO typedef ptr HEAPALIASINFO
    HEAPALIASINFO_MAPPEDREAL equ 00000001h; PRIVATE: heap aliases mapped to real video memory

    HEAPALIASINFO_MAPPEDDUMMY equ 00000002h; PRIVATE: heap aliased mapped to dummy memory

    LPDDRAWI_DIRECTDRAW_INT typedef ptr _DDRAWI_DIRECTDRAW_INT
    LPDDRAWI_DIRECTDRAW_LCL typedef ptr _DDRAWI_DIRECTDRAW_LCL
    LPDDRAWI_DIRECTDRAW_GBL typedef ptr _DDRAWI_DIRECTDRAW_GBL
    LPDDRAWI_DDRAWSURFACE_GBL typedef ptr _DDRAWI_DDRAWSURFACE_GBL
    LPDDRAWI_DDRAWSURFACE_GBL_MORE typedef ptr _DDRAWI_DDRAWSURFACE_GBL_MORE
    LPDDRAWI_DDRAWPALETTE_GBL typedef ptr _DDRAWI_DDRAWPALETTE_GBL
    LPDDRAWI_DDRAWPALETTE_INT typedef ptr _DDRAWI_DDRAWPALETTE_INT
    LPDDRAWI_DDRAWCLIPPER_INT typedef ptr _DDRAWI_DDRAWCLIPPER_INT
    LPDDRAWI_DDRAWCLIPPER_GBL typedef ptr _DDRAWI_DDRAWCLIPPER_GBL
    LPDDRAWI_DDRAWSURFACE_MORE typedef ptr _DDRAWI_DDRAWSURFACE_MORE
    LPDDRAWI_DDRAWSURFACE_LCL typedef ptr _DDRAWI_DDRAWSURFACE_LCL
    LPDDRAWI_DDRAWSURFACE_INT typedef ptr _DDRAWI_DDRAWSURFACE_INT
    LPDDRAWI_DDVIDEOPORT_INT typedef ptr _DDRAWI_DDVIDEOPORT_INT
    LPDDRAWI_DDVIDEOPORT_LCL typedef ptr _DDRAWI_DDVIDEOPORT_LCL
    LPDDRAWI_DDRAWPALETTE_LCL typedef ptr _DDRAWI_DDRAWPALETTE_LCL
    LPDDRAWI_DDRAWCLIPPER_LCL typedef ptr _DDRAWI_DDRAWCLIPPER_LCL
    LPDDRAWI_DDMOTIONCOMP_INT typedef ptr _DDRAWI_DDMOTIONCOMP_INT
    LPDDRAWI_DDMOTIONCOMP_LCL typedef ptr _DDRAWI_DDMOTIONCOMP_LCL
    ;*
    ;* List of IUnknowns aggregated by a DirectDraw surface.
    ;*
    IUNKNOWN_LIST struct
      lpLink POINTER ?
      lpGuid POINTER ?
      lpIUnknown POINTER ?
    IUNKNOWN_LIST ends
    _IUNKNOWN_LIST typedef IUNKNOWN_LIST
    LPIUNKNOWN_LIST typedef ptr IUNKNOWN_LIST
    ;*
    ;* hardware emulation layer stuff
    ;*
    TYPE_LPDDHEL_INIT typedef proto WIN_STD_CALL_CONV :LPDDRAWI_DIRECTDRAW_GBL, :BOOL
    LPDDHEL_INIT typedef ptr TYPE_LPDDHEL_INIT

    ;*
    ;* These structures contain the entry points in the display driver that
    ;* DDRAW will call.   Entries that the display driver does not care about
    ;* should be NULL.   Passed to DDRAW in DDHALINFO.
    ;*
    ;*
    ;* DIRECTDRAW object callbacks
    ;*
    TYPE_LPDDHAL_SETCOLORKEY typedef proto WIN_STD_CALL_CONV :LPDDHAL_DRVSETCOLORKEYDATA
    LPDDHAL_SETCOLORKEY typedef ptr TYPE_LPDDHAL_SETCOLORKEY

    TYPE_LPDDHAL_CANCREATESURFACE typedef proto WIN_STD_CALL_CONV :LPDDHAL_CANCREATESURFACEDATA
    LPDDHAL_CANCREATESURFACE typedef ptr TYPE_LPDDHAL_CANCREATESURFACE

    TYPE_LPDDHAL_WAITFORVERTICALBLANK typedef proto WIN_STD_CALL_CONV :LPDDHAL_WAITFORVERTICALBLANKDATA
    LPDDHAL_WAITFORVERTICALBLANK typedef ptr TYPE_LPDDHAL_WAITFORVERTICALBLANK

    TYPE_LPDDHAL_CREATESURFACE typedef proto WIN_STD_CALL_CONV :LPDDHAL_CREATESURFACEDATA
    LPDDHAL_CREATESURFACE typedef ptr TYPE_LPDDHAL_CREATESURFACE

    TYPE_LPDDHAL_DESTROYDRIVER typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYDRIVERDATA
    LPDDHAL_DESTROYDRIVER typedef ptr TYPE_LPDDHAL_DESTROYDRIVER

    TYPE_LPDDHAL_SETMODE typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETMODEDATA
    LPDDHAL_SETMODE typedef ptr TYPE_LPDDHAL_SETMODE

    TYPE_LPDDHAL_CREATEPALETTE typedef proto WIN_STD_CALL_CONV :LPDDHAL_CREATEPALETTEDATA
    LPDDHAL_CREATEPALETTE typedef ptr TYPE_LPDDHAL_CREATEPALETTE

    TYPE_LPDDHAL_GETSCANLINE typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETSCANLINEDATA
    LPDDHAL_GETSCANLINE typedef ptr TYPE_LPDDHAL_GETSCANLINE

    TYPE_LPDDHAL_SETEXCLUSIVEMODE typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETEXCLUSIVEMODEDATA
    LPDDHAL_SETEXCLUSIVEMODE typedef ptr TYPE_LPDDHAL_SETEXCLUSIVEMODE

    TYPE_LPDDHAL_FLIPTOGDISURFACE typedef proto WIN_STD_CALL_CONV :LPDDHAL_FLIPTOGDISURFACEDATA
    LPDDHAL_FLIPTOGDISURFACE typedef ptr TYPE_LPDDHAL_FLIPTOGDISURFACE

    TYPE_LPDDHAL_GETDRIVERINFO typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETDRIVERINFODATA
    LPDDHAL_GETDRIVERINFO typedef ptr TYPE_LPDDHAL_GETDRIVERINFO

    DDHAL_DDCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      DestroyDriver LPDDHAL_DESTROYDRIVER ?
      CreateSurface LPDDHAL_CREATESURFACE ?
      SetColorKey LPDDHAL_SETCOLORKEY ?
      SetMode LPDDHAL_SETMODE ?
      WaitForVerticalBlank LPDDHAL_WAITFORVERTICALBLANK ?
      CanCreateSurface LPDDHAL_CANCREATESURFACE ?
      CreatePalette LPDDHAL_CREATEPALETTE ?
      GetScanLine LPDDHAL_GETSCANLINE ?
      ; *** New fields for DX2 *** //
      SetExclusiveMode LPDDHAL_SETEXCLUSIVEMODE ?
      FlipToGDISurface LPDDHAL_FLIPTOGDISURFACE ?
    DDHAL_DDCALLBACKS ends
    _DDHAL_DDCALLBACKS typedef DDHAL_DDCALLBACKS
    LPDDHAL_DDCALLBACKS typedef ptr DDHAL_DDCALLBACKS
    DDCALLBACKSSIZE_V1 equ <(offsetof (DDHAL_DDCALLBACKS, SetExclusiveMode))>
    DDCALLBACKSSIZE equ <sizeof(DDHAL_DDCALLBACKS)>
    DDHAL_CB32_DESTROYDRIVER equ 00000001h
    DDHAL_CB32_CREATESURFACE equ 00000002h
    DDHAL_CB32_SETCOLORKEY equ 00000004h
    DDHAL_CB32_SETMODE equ 00000008h
    DDHAL_CB32_WAITFORVERTICALBLANK equ 00000010h
    DDHAL_CB32_CANCREATESURFACE equ 00000020h
    DDHAL_CB32_CREATEPALETTE equ 00000040h
    DDHAL_CB32_GETSCANLINE equ 00000080h
    DDHAL_CB32_SETEXCLUSIVEMODE equ 00000100h
    DDHAL_CB32_FLIPTOGDISURFACE equ 00000200h
    ;*
    ;* DIRECTDRAWPALETTE object callbacks
    ;*
    TYPE_LPDDHALPALCB_DESTROYPALETTE typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYPALETTEDATA
    LPDDHALPALCB_DESTROYPALETTE typedef ptr TYPE_LPDDHALPALCB_DESTROYPALETTE

    TYPE_LPDDHALPALCB_SETENTRIES typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETENTRIESDATA
    LPDDHALPALCB_SETENTRIES typedef ptr TYPE_LPDDHALPALCB_SETENTRIES

    DDHAL_DDPALETTECALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      DestroyPalette LPDDHALPALCB_DESTROYPALETTE ?
      SetEntries LPDDHALPALCB_SETENTRIES ?
    DDHAL_DDPALETTECALLBACKS ends
    _DDHAL_DDPALETTECALLBACKS typedef DDHAL_DDPALETTECALLBACKS
    LPDDHAL_DDPALETTECALLBACKS typedef ptr DDHAL_DDPALETTECALLBACKS
    DDPALETTECALLBACKSSIZE equ <sizeof(DDHAL_DDPALETTECALLBACKS)>
    DDHAL_PALCB32_DESTROYPALETTE equ 00000001h
    DDHAL_PALCB32_SETENTRIES equ 00000002h
    ;*
    ;* DIRECTDRAWSURFACE object callbacks
    ;*
    TYPE_LPDDHALSURFCB_LOCK typedef proto WIN_STD_CALL_CONV :LPDDHAL_LOCKDATA
    LPDDHALSURFCB_LOCK typedef ptr TYPE_LPDDHALSURFCB_LOCK

    TYPE_LPDDHALSURFCB_UNLOCK typedef proto WIN_STD_CALL_CONV :LPDDHAL_UNLOCKDATA
    LPDDHALSURFCB_UNLOCK typedef ptr TYPE_LPDDHALSURFCB_UNLOCK

    TYPE_LPDDHALSURFCB_BLT typedef proto WIN_STD_CALL_CONV :LPDDHAL_BLTDATA
    LPDDHALSURFCB_BLT typedef ptr TYPE_LPDDHALSURFCB_BLT

    TYPE_LPDDHALSURFCB_UPDATEOVERLAY typedef proto WIN_STD_CALL_CONV :LPDDHAL_UPDATEOVERLAYDATA
    LPDDHALSURFCB_UPDATEOVERLAY typedef ptr TYPE_LPDDHALSURFCB_UPDATEOVERLAY

    TYPE_LPDDHALSURFCB_SETOVERLAYPOSITION typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETOVERLAYPOSITIONDATA
    LPDDHALSURFCB_SETOVERLAYPOSITION typedef ptr TYPE_LPDDHALSURFCB_SETOVERLAYPOSITION

    TYPE_LPDDHALSURFCB_SETPALETTE typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETPALETTEDATA
    LPDDHALSURFCB_SETPALETTE typedef ptr TYPE_LPDDHALSURFCB_SETPALETTE

    TYPE_LPDDHALSURFCB_FLIP typedef proto WIN_STD_CALL_CONV :LPDDHAL_FLIPDATA
    LPDDHALSURFCB_FLIP typedef ptr TYPE_LPDDHALSURFCB_FLIP

    TYPE_LPDDHALSURFCB_DESTROYSURFACE typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYSURFACEDATA
    LPDDHALSURFCB_DESTROYSURFACE typedef ptr TYPE_LPDDHALSURFCB_DESTROYSURFACE

    TYPE_LPDDHALSURFCB_SETCLIPLIST typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETCLIPLISTDATA
    LPDDHALSURFCB_SETCLIPLIST typedef ptr TYPE_LPDDHALSURFCB_SETCLIPLIST

    TYPE_LPDDHALSURFCB_ADDATTACHEDSURFACE typedef proto WIN_STD_CALL_CONV :LPDDHAL_ADDATTACHEDSURFACEDATA
    LPDDHALSURFCB_ADDATTACHEDSURFACE typedef ptr TYPE_LPDDHALSURFCB_ADDATTACHEDSURFACE

    TYPE_LPDDHALSURFCB_SETCOLORKEY typedef proto WIN_STD_CALL_CONV :LPDDHAL_SETCOLORKEYDATA
    LPDDHALSURFCB_SETCOLORKEY typedef ptr TYPE_LPDDHALSURFCB_SETCOLORKEY

    TYPE_LPDDHALSURFCB_GETBLTSTATUS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETBLTSTATUSDATA
    LPDDHALSURFCB_GETBLTSTATUS typedef ptr TYPE_LPDDHALSURFCB_GETBLTSTATUS

    TYPE_LPDDHALSURFCB_GETFLIPSTATUS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETFLIPSTATUSDATA
    LPDDHALSURFCB_GETFLIPSTATUS typedef ptr TYPE_LPDDHALSURFCB_GETFLIPSTATUS

    DDHAL_DDSURFACECALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      DestroySurface LPDDHALSURFCB_DESTROYSURFACE ?
      Flip LPDDHALSURFCB_FLIP ?
      SetClipList LPDDHALSURFCB_SETCLIPLIST ?
      Lock_ LPDDHALSURFCB_LOCK ?
      Unlock LPDDHALSURFCB_UNLOCK ?
      Blt LPDDHALSURFCB_BLT ?
      SetColorKey LPDDHALSURFCB_SETCOLORKEY ?
      AddAttachedSurface LPDDHALSURFCB_ADDATTACHEDSURFACE ?
      GetBltStatus LPDDHALSURFCB_GETBLTSTATUS ?
      GetFlipStatus LPDDHALSURFCB_GETFLIPSTATUS ?
      UpdateOverlay LPDDHALSURFCB_UPDATEOVERLAY ?
      SetOverlayPosition LPDDHALSURFCB_SETOVERLAYPOSITION ?
      reserved4 POINTER ?
      SetPalette LPDDHALSURFCB_SETPALETTE ?
    DDHAL_DDSURFACECALLBACKS ends
    _DDHAL_DDSURFACECALLBACKS typedef DDHAL_DDSURFACECALLBACKS
    LPDDHAL_DDSURFACECALLBACKS typedef ptr DDHAL_DDSURFACECALLBACKS
    DDSURFACECALLBACKSSIZE equ <sizeof(DDHAL_DDSURFACECALLBACKS)>
    DDHAL_SURFCB32_DESTROYSURFACE equ 00000001h
    DDHAL_SURFCB32_FLIP equ 00000002h
    DDHAL_SURFCB32_SETCLIPLIST equ 00000004h
    DDHAL_SURFCB32_LOCK equ 00000008h
    DDHAL_SURFCB32_UNLOCK equ 00000010h
    DDHAL_SURFCB32_BLT equ 00000020h
    DDHAL_SURFCB32_SETCOLORKEY equ 00000040h
    DDHAL_SURFCB32_ADDATTACHEDSURFACE equ 00000080h
    DDHAL_SURFCB32_GETBLTSTATUS equ 00000100h
    DDHAL_SURFCB32_GETFLIPSTATUS equ 00000200h
    DDHAL_SURFCB32_UPDATEOVERLAY equ 00000400h
    DDHAL_SURFCB32_SETOVERLAYPOSITION equ 00000800h
    DDHAL_SURFCB32_RESERVED4 equ 00001000h
    DDHAL_SURFCB32_SETPALETTE equ 00002000h
    ; This structure can be queried from the driver from DX5 onward
    ; using GetDriverInfo with GUID_MiscellaneousCallbacks
    TYPE_LPDDHAL_GETAVAILDRIVERMEMORY typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETAVAILDRIVERMEMORYDATA
    LPDDHAL_GETAVAILDRIVERMEMORY typedef ptr TYPE_LPDDHAL_GETAVAILDRIVERMEMORY

    TYPE_LPDDHAL_UPDATENONLOCALHEAP typedef proto WIN_STD_CALL_CONV :LPDDHAL_UPDATENONLOCALHEAPDATA
    LPDDHAL_UPDATENONLOCALHEAP typedef ptr TYPE_LPDDHAL_UPDATENONLOCALHEAP

    TYPE_LPDDHAL_GETHEAPALIGNMENT typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETHEAPALIGNMENTDATA
    LPDDHAL_GETHEAPALIGNMENT typedef ptr TYPE_LPDDHAL_GETHEAPALIGNMENT

    ;*
    ;* This prototype is identical to that of GetBltStatus
    ;*
    DDHAL_DDMISCELLANEOUSCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      GetAvailDriverMemory LPDDHAL_GETAVAILDRIVERMEMORY ?
      UpdateNonLocalHeap LPDDHAL_UPDATENONLOCALHEAP ?
      GetHeapAlignment LPDDHAL_GETHEAPALIGNMENT ?
      ;*
      ;* The GetSysmemBltStatus callback uses the same prototype as GetBltStatus.
      ;* It is legal to point both pointers to the same driver routine.
      ;*
      GetSysmemBltStatus LPDDHALSURFCB_GETBLTSTATUS ?
    DDHAL_DDMISCELLANEOUSCALLBACKS ends
    _DDHAL_DDMISCELLANEOUSCALLBACKS typedef DDHAL_DDMISCELLANEOUSCALLBACKS
    LPDDHAL_DDMISCELLANEOUSCALLBACKS typedef ptr DDHAL_DDMISCELLANEOUSCALLBACKS
    DDHAL_MISCCB32_GETAVAILDRIVERMEMORY equ 00000001h
    DDHAL_MISCCB32_UPDATENONLOCALHEAP equ 00000002h
    DDHAL_MISCCB32_GETHEAPALIGNMENT equ 00000004h
    DDHAL_MISCCB32_GETSYSMEMBLTSTATUS equ 00000008h
    DDMISCELLANEOUSCALLBACKSSIZE equ <sizeof(DDHAL_DDMISCELLANEOUSCALLBACKS)>
    ; DDHAL_DDMISCELLANEOUS2CALLBACKS:
    ;   This structure can be queried from the driver from DX7 onward
    ;   using GetDriverInfo with GUID_Miscellaneous2Callbacks
    TYPE_LPDDHAL_CREATESURFACEEX typedef proto WIN_STD_CALL_CONV :LPDDHAL_CREATESURFACEEXDATA
    LPDDHAL_CREATESURFACEEX typedef ptr TYPE_LPDDHAL_CREATESURFACEEX

    TYPE_LPDDHAL_GETDRIVERSTATE typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETDRIVERSTATEDATA
    LPDDHAL_GETDRIVERSTATE typedef ptr TYPE_LPDDHAL_GETDRIVERSTATE

    TYPE_LPDDHAL_DESTROYDDLOCAL typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYDDLOCALDATA
    LPDDHAL_DESTROYDDLOCAL typedef ptr TYPE_LPDDHAL_DESTROYDDLOCAL

    DDHAL_DDMISCELLANEOUS2CALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      Reserved POINTER ?
      CreateSurfaceEx LPDDHAL_CREATESURFACEEX ?
      GetDriverState LPDDHAL_GETDRIVERSTATE ?
      DestroyDDLocal LPDDHAL_DESTROYDDLOCAL ?
    DDHAL_DDMISCELLANEOUS2CALLBACKS ends
    _DDHAL_DDMISCELLANEOUS2CALLBACKS typedef DDHAL_DDMISCELLANEOUS2CALLBACKS
    LPDDHAL_DDMISCELLANEOUS2CALLBACKS typedef ptr DDHAL_DDMISCELLANEOUS2CALLBACKS
    DDHAL_MISC2CB32_CREATESURFACEEX equ 00000002h
    DDHAL_MISC2CB32_GETDRIVERSTATE equ 00000004h
    DDHAL_MISC2CB32_DESTROYDDLOCAL equ 00000008h
    DDMISCELLANEOUS2CALLBACKSSIZE equ <sizeof(DDHAL_DDMISCELLANEOUS2CALLBACKS)>
    ;*
    ;* DIRECTDRAWEXEBUF pseudo object callbacks
    ;*
    ;* NOTE: Execute buffers are not a distinct object type, they piggy back off
    ;* the surface data structures and high level API. However, they have their
    ;* own HAL callbacks as they may have different driver semantics from "normal"
    ;* surfaces. They also piggy back off the HAL data structures.
    ;*
    ;* !!! NOTE: Need to resolve whether we export execute buffer copying as a
    ;* blit or some other from of copy instruction.
    ;*
    TYPE_LPDDHALEXEBUFCB_CANCREATEEXEBUF typedef proto WIN_STD_CALL_CONV :LPDDHAL_CANCREATESURFACEDATA
    LPDDHALEXEBUFCB_CANCREATEEXEBUF typedef ptr TYPE_LPDDHALEXEBUFCB_CANCREATEEXEBUF

    TYPE_LPDDHALEXEBUFCB_CREATEEXEBUF typedef proto WIN_STD_CALL_CONV :LPDDHAL_CREATESURFACEDATA
    LPDDHALEXEBUFCB_CREATEEXEBUF typedef ptr TYPE_LPDDHALEXEBUFCB_CREATEEXEBUF

    TYPE_LPDDHALEXEBUFCB_DESTROYEXEBUF typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYSURFACEDATA
    LPDDHALEXEBUFCB_DESTROYEXEBUF typedef ptr TYPE_LPDDHALEXEBUFCB_DESTROYEXEBUF

    TYPE_LPDDHALEXEBUFCB_LOCKEXEBUF typedef proto WIN_STD_CALL_CONV :LPDDHAL_LOCKDATA
    LPDDHALEXEBUFCB_LOCKEXEBUF typedef ptr TYPE_LPDDHALEXEBUFCB_LOCKEXEBUF

    TYPE_LPDDHALEXEBUFCB_UNLOCKEXEBUF typedef proto WIN_STD_CALL_CONV :LPDDHAL_UNLOCKDATA
    LPDDHALEXEBUFCB_UNLOCKEXEBUF typedef ptr TYPE_LPDDHALEXEBUFCB_UNLOCKEXEBUF

    DDHAL_DDEXEBUFCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      CanCreateExecuteBuffer LPDDHALEXEBUFCB_CANCREATEEXEBUF ?
      CreateExecuteBuffer LPDDHALEXEBUFCB_CREATEEXEBUF ?
      DestroyExecuteBuffer LPDDHALEXEBUFCB_DESTROYEXEBUF ?
      LockExecuteBuffer LPDDHALEXEBUFCB_LOCKEXEBUF ?
      UnlockExecuteBuffer LPDDHALEXEBUFCB_UNLOCKEXEBUF ?
    DDHAL_DDEXEBUFCALLBACKS ends
    _DDHAL_DDEXEBUFCALLBACKS typedef DDHAL_DDEXEBUFCALLBACKS
    LPDDHAL_DDEXEBUFCALLBACKS typedef ptr DDHAL_DDEXEBUFCALLBACKS
    DDEXEBUFCALLBACKSSIZE equ <sizeof(DDHAL_DDEXEBUFCALLBACKS)>
    DDHAL_EXEBUFCB32_CANCREATEEXEBUF equ 00000001h
    DDHAL_EXEBUFCB32_CREATEEXEBUF equ 00000002h
    DDHAL_EXEBUFCB32_DESTROYEXEBUF equ 00000004h
    DDHAL_EXEBUFCB32_LOCKEXEBUF equ 00000008h
    DDHAL_EXEBUFCB32_UNLOCKEXEBUF equ 00000010h
    ;*
    ;* DIRECTVIDEOPORT object callbacks
    ;*
    TYPE_LPDDHALVPORTCB_CANCREATEVIDEOPORT typedef proto WIN_STD_CALL_CONV :LPDDHAL_CANCREATEVPORTDATA
    LPDDHALVPORTCB_CANCREATEVIDEOPORT typedef ptr TYPE_LPDDHALVPORTCB_CANCREATEVIDEOPORT

    TYPE_LPDDHALVPORTCB_CREATEVIDEOPORT typedef proto WIN_STD_CALL_CONV :LPDDHAL_CREATEVPORTDATA
    LPDDHALVPORTCB_CREATEVIDEOPORT typedef ptr TYPE_LPDDHALVPORTCB_CREATEVIDEOPORT

    TYPE_LPDDHALVPORTCB_FLIP typedef proto WIN_STD_CALL_CONV :LPDDHAL_FLIPVPORTDATA
    LPDDHALVPORTCB_FLIP typedef ptr TYPE_LPDDHALVPORTCB_FLIP

    TYPE_LPDDHALVPORTCB_GETBANDWIDTH typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTBANDWIDTHDATA
    LPDDHALVPORTCB_GETBANDWIDTH typedef ptr TYPE_LPDDHALVPORTCB_GETBANDWIDTH

    TYPE_LPDDHALVPORTCB_GETINPUTFORMATS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTINPUTFORMATDATA
    LPDDHALVPORTCB_GETINPUTFORMATS typedef ptr TYPE_LPDDHALVPORTCB_GETINPUTFORMATS

    TYPE_LPDDHALVPORTCB_GETOUTPUTFORMATS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTOUTPUTFORMATDATA
    LPDDHALVPORTCB_GETOUTPUTFORMATS typedef ptr TYPE_LPDDHALVPORTCB_GETOUTPUTFORMATS

    TYPE_LPDDHALVPORTCB_GETFIELD typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTFIELDDATA
    LPDDHALVPORTCB_GETFIELD typedef ptr TYPE_LPDDHALVPORTCB_GETFIELD

    TYPE_LPDDHALVPORTCB_GETLINE typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTLINEDATA
    LPDDHALVPORTCB_GETLINE typedef ptr TYPE_LPDDHALVPORTCB_GETLINE

    TYPE_LPDDHALVPORTCB_GETVPORTCONNECT typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTCONNECTDATA
    LPDDHALVPORTCB_GETVPORTCONNECT typedef ptr TYPE_LPDDHALVPORTCB_GETVPORTCONNECT

    TYPE_LPDDHALVPORTCB_DESTROYVPORT typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYVPORTDATA
    LPDDHALVPORTCB_DESTROYVPORT typedef ptr TYPE_LPDDHALVPORTCB_DESTROYVPORT

    TYPE_LPDDHALVPORTCB_GETFLIPSTATUS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTFLIPSTATUSDATA
    LPDDHALVPORTCB_GETFLIPSTATUS typedef ptr TYPE_LPDDHALVPORTCB_GETFLIPSTATUS

    TYPE_LPDDHALVPORTCB_UPDATE typedef proto WIN_STD_CALL_CONV :LPDDHAL_UPDATEVPORTDATA
    LPDDHALVPORTCB_UPDATE typedef ptr TYPE_LPDDHALVPORTCB_UPDATE

    TYPE_LPDDHALVPORTCB_WAITFORSYNC typedef proto WIN_STD_CALL_CONV :LPDDHAL_WAITFORVPORTSYNCDATA
    LPDDHALVPORTCB_WAITFORSYNC typedef ptr TYPE_LPDDHALVPORTCB_WAITFORSYNC

    TYPE_LPDDHALVPORTCB_GETSIGNALSTATUS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETVPORTSIGNALDATA
    LPDDHALVPORTCB_GETSIGNALSTATUS typedef ptr TYPE_LPDDHALVPORTCB_GETSIGNALSTATUS

    TYPE_LPDDHALVPORTCB_COLORCONTROL typedef proto WIN_STD_CALL_CONV :LPDDHAL_VPORTCOLORDATA
    LPDDHALVPORTCB_COLORCONTROL typedef ptr TYPE_LPDDHALVPORTCB_COLORCONTROL

    DDHAL_DDVIDEOPORTCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      CanCreateVideoPort LPDDHALVPORTCB_CANCREATEVIDEOPORT ?
      CreateVideoPort LPDDHALVPORTCB_CREATEVIDEOPORT ?
      FlipVideoPort LPDDHALVPORTCB_FLIP ?
      GetVideoPortBandwidth LPDDHALVPORTCB_GETBANDWIDTH ?
      GetVideoPortInputFormats LPDDHALVPORTCB_GETINPUTFORMATS ?
      GetVideoPortOutputFormats LPDDHALVPORTCB_GETOUTPUTFORMATS ?
      lpReserved1 POINTER ?
      GetVideoPortField LPDDHALVPORTCB_GETFIELD ?
      GetVideoPortLine LPDDHALVPORTCB_GETLINE ?
      GetVideoPortConnectInfo LPDDHALVPORTCB_GETVPORTCONNECT ?
      DestroyVideoPort LPDDHALVPORTCB_DESTROYVPORT ?
      GetVideoPortFlipStatus LPDDHALVPORTCB_GETFLIPSTATUS ?
      UpdateVideoPort LPDDHALVPORTCB_UPDATE ?
      WaitForVideoPortSync LPDDHALVPORTCB_WAITFORSYNC ?
      GetVideoSignalStatus LPDDHALVPORTCB_GETSIGNALSTATUS ?
      ColorControl LPDDHALVPORTCB_COLORCONTROL ?
    DDHAL_DDVIDEOPORTCALLBACKS ends
    _DDHAL_DDVIDEOPORTCALLBACKS typedef DDHAL_DDVIDEOPORTCALLBACKS
    LPDDHAL_DDVIDEOPORTCALLBACKS typedef ptr DDHAL_DDVIDEOPORTCALLBACKS
    DDVIDEOPORTCALLBACKSSIZE equ <sizeof(DDHAL_DDVIDEOPORTCALLBACKS)>
    DDHAL_VPORT32_CANCREATEVIDEOPORT equ 00000001h
    DDHAL_VPORT32_CREATEVIDEOPORT equ 00000002h
    DDHAL_VPORT32_FLIP equ 00000004h
    DDHAL_VPORT32_GETBANDWIDTH equ 00000008h
    DDHAL_VPORT32_GETINPUTFORMATS equ 00000010h
    DDHAL_VPORT32_GETOUTPUTFORMATS equ 00000020h
    DDHAL_VPORT32_GETFIELD equ 00000080h
    DDHAL_VPORT32_GETLINE equ 00000100h
    DDHAL_VPORT32_GETCONNECT equ 00000200h
    DDHAL_VPORT32_DESTROY equ 00000400h
    DDHAL_VPORT32_GETFLIPSTATUS equ 00000800h
    DDHAL_VPORT32_UPDATE equ 00001000h
    DDHAL_VPORT32_WAITFORSYNC equ 00002000h
    DDHAL_VPORT32_GETSIGNALSTATUS equ 00004000h
    DDHAL_VPORT32_COLORCONTROL equ 00008000h
    ;*
    ;* DIRECTDRAWCOLORCONTROL object callbacks
    ;*
    TYPE_LPDDHALCOLORCB_COLORCONTROL typedef proto WIN_STD_CALL_CONV :LPDDHAL_COLORCONTROLDATA
    LPDDHALCOLORCB_COLORCONTROL typedef ptr TYPE_LPDDHALCOLORCB_COLORCONTROL

    DDHAL_DDCOLORCONTROLCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      ColorControl LPDDHALCOLORCB_COLORCONTROL ?
    DDHAL_DDCOLORCONTROLCALLBACKS ends
    _DDHAL_DDCOLORCONTROLCALLBACKS typedef DDHAL_DDCOLORCONTROLCALLBACKS
    LPDDHAL_DDCOLORCONTROLCALLBACKS typedef ptr DDHAL_DDCOLORCONTROLCALLBACKS
    DDCOLORCONTROLCALLBACKSSIZE equ <sizeof(DDHAL_DDCOLORCONTROLCALLBACKS)>
    DDHAL_COLOR_COLORCONTROL equ 00000001h
    ;*
    ;* DIRECTDRAWSURFACEKERNEL object callbacks
    ;* This structure can be queried from the driver from DX5 onward
    ;* using GetDriverInfo with GUID_KernelCallbacks
    ;*
    TYPE_LPDDHALKERNELCB_SYNCSURFACE typedef proto WIN_STD_CALL_CONV :LPDDHAL_SYNCSURFACEDATA
    LPDDHALKERNELCB_SYNCSURFACE typedef ptr TYPE_LPDDHALKERNELCB_SYNCSURFACE

    TYPE_LPDDHALKERNELCB_SYNCVIDEOPORT typedef proto WIN_STD_CALL_CONV :LPDDHAL_SYNCVIDEOPORTDATA
    LPDDHALKERNELCB_SYNCVIDEOPORT typedef ptr TYPE_LPDDHALKERNELCB_SYNCVIDEOPORT

    DDHAL_DDKERNELCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      SyncSurfaceData LPDDHALKERNELCB_SYNCSURFACE ?
      SyncVideoPortData LPDDHALKERNELCB_SYNCVIDEOPORT ?
    DDHAL_DDKERNELCALLBACKS ends
    _DDHAL_DDKERNELCALLBACKS typedef DDHAL_DDKERNELCALLBACKS
    LPDDHAL_DDKERNELCALLBACKS typedef ptr DDHAL_DDKERNELCALLBACKS
    DDHAL_KERNEL_SYNCSURFACEDATA equ 00000001h
    DDHAL_KERNEL_SYNCVIDEOPORTDATA equ 00000002h
    DDKERNELCALLBACKSSIZE equ <sizeof(DDHAL_DDKERNELCALLBACKS)>
    TYPE_LPDDGAMMACALIBRATORPROC typedef proto WIN_STD_CALL_CONV :LPDDGAMMARAMP, :LPBYTE
    LPDDGAMMACALIBRATORPROC typedef ptr TYPE_LPDDGAMMACALIBRATORPROC

    ;*
    ;* DIRECTDRAWMOTIONCOMP object callbacks
    ;*
    TYPE_LPDDHALMOCOMPCB_GETGUIDS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETMOCOMPGUIDSDATA
    LPDDHALMOCOMPCB_GETGUIDS typedef ptr TYPE_LPDDHALMOCOMPCB_GETGUIDS

    TYPE_LPDDHALMOCOMPCB_GETFORMATS typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETMOCOMPFORMATSDATA
    LPDDHALMOCOMPCB_GETFORMATS typedef ptr TYPE_LPDDHALMOCOMPCB_GETFORMATS

    TYPE_LPDDHALMOCOMPCB_CREATE typedef proto WIN_STD_CALL_CONV :LPDDHAL_CREATEMOCOMPDATA
    LPDDHALMOCOMPCB_CREATE typedef ptr TYPE_LPDDHALMOCOMPCB_CREATE

    TYPE_LPDDHALMOCOMPCB_GETCOMPBUFFINFO typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETMOCOMPCOMPBUFFDATA
    LPDDHALMOCOMPCB_GETCOMPBUFFINFO typedef ptr TYPE_LPDDHALMOCOMPCB_GETCOMPBUFFINFO

    TYPE_LPDDHALMOCOMPCB_GETINTERNALINFO typedef proto WIN_STD_CALL_CONV :LPDDHAL_GETINTERNALMOCOMPDATA
    LPDDHALMOCOMPCB_GETINTERNALINFO typedef ptr TYPE_LPDDHALMOCOMPCB_GETINTERNALINFO

    TYPE_LPDDHALMOCOMPCB_BEGINFRAME typedef proto WIN_STD_CALL_CONV :LPDDHAL_BEGINMOCOMPFRAMEDATA
    LPDDHALMOCOMPCB_BEGINFRAME typedef ptr TYPE_LPDDHALMOCOMPCB_BEGINFRAME

    TYPE_LPDDHALMOCOMPCB_ENDFRAME typedef proto WIN_STD_CALL_CONV :LPDDHAL_ENDMOCOMPFRAMEDATA
    LPDDHALMOCOMPCB_ENDFRAME typedef ptr TYPE_LPDDHALMOCOMPCB_ENDFRAME

    TYPE_LPDDHALMOCOMPCB_RENDER typedef proto WIN_STD_CALL_CONV :LPDDHAL_RENDERMOCOMPDATA
    LPDDHALMOCOMPCB_RENDER typedef ptr TYPE_LPDDHALMOCOMPCB_RENDER

    TYPE_LPDDHALMOCOMPCB_QUERYSTATUS typedef proto WIN_STD_CALL_CONV :LPDDHAL_QUERYMOCOMPSTATUSDATA
    LPDDHALMOCOMPCB_QUERYSTATUS typedef ptr TYPE_LPDDHALMOCOMPCB_QUERYSTATUS

    TYPE_LPDDHALMOCOMPCB_DESTROY typedef proto WIN_STD_CALL_CONV :LPDDHAL_DESTROYMOCOMPDATA
    LPDDHALMOCOMPCB_DESTROY typedef ptr TYPE_LPDDHALMOCOMPCB_DESTROY

    DDHAL_DDMOTIONCOMPCALLBACKS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      GetMoCompGuids LPDDHALMOCOMPCB_GETGUIDS ?
      GetMoCompFormats LPDDHALMOCOMPCB_GETFORMATS ?
      CreateMoComp LPDDHALMOCOMPCB_CREATE ?
      GetMoCompBuffInfo LPDDHALMOCOMPCB_GETCOMPBUFFINFO ?
      GetInternalMoCompInfo LPDDHALMOCOMPCB_GETINTERNALINFO ?
      BeginMoCompFrame LPDDHALMOCOMPCB_BEGINFRAME ?
      EndMoCompFrame LPDDHALMOCOMPCB_ENDFRAME ?
      RenderMoComp LPDDHALMOCOMPCB_RENDER ?
      QueryMoCompStatus LPDDHALMOCOMPCB_QUERYSTATUS ?
      DestroyMoComp LPDDHALMOCOMPCB_DESTROY ?
    DDHAL_DDMOTIONCOMPCALLBACKS ends
    _DDHAL_DDMOTIONCOMPCALLBACKS typedef DDHAL_DDMOTIONCOMPCALLBACKS
    LPDDHAL_DDMOTIONCOMPCALLBACKS typedef ptr DDHAL_DDMOTIONCOMPCALLBACKS
    DDMOTIONCOMPCALLBACKSSIZE equ <sizeof(DDHAL_DDMOTIONCOMPCALLBACKS)>
    DDHAL_MOCOMP32_GETGUIDS equ 00000001h
    DDHAL_MOCOMP32_GETFORMATS equ 00000002h
    DDHAL_MOCOMP32_CREATE equ 00000004h
    DDHAL_MOCOMP32_GETCOMPBUFFINFO equ 00000008h
    DDHAL_MOCOMP32_GETINTERNALINFO equ 00000010h
    DDHAL_MOCOMP32_BEGINFRAME equ 00000020h
    DDHAL_MOCOMP32_ENDFRAME equ 00000040h
    DDHAL_MOCOMP32_RENDER equ 00000080h
    DDHAL_MOCOMP32_QUERYSTATUS equ 00000100h
    DDHAL_MOCOMP32_DESTROY equ 00000200h
    ;*
    ;* CALLBACK RETURN VALUES
    ;*                      * these are values returned by the driver from the above callback routines
    ;*
    ;*
    ;* indicates that the display driver didn't do anything with the call
    ;*
    DDHAL_DRIVER_NOTHANDLED equ 00000000h
    ;*
    ;* indicates that the display driver handled the call; HRESULT value is valid
    ;*
    DDHAL_DRIVER_HANDLED equ 00000001h
    ;*
    ;* indicates that the display driver couldn't handle the call because it
    ;* ran out of color key hardware resources
    ;*
    DDHAL_DRIVER_NOCKEYHW equ 00000002h
    ;*
    ;* Capabilities structure for non-local video memory
    ;*
    DDNONLOCALVIDMEMCAPS struct
      dwSize DWORD ?
      dwNLVBCaps DWORD ?
      ; driver specific capabilities for non-local->local vidmem blts
      dwNLVBCaps2 DWORD ?
      ; more driver specific capabilities non-local->local vidmem blts
      dwNLVBCKeyCaps DWORD ?
      ; driver color key capabilities for non-local->local vidmem blts
      dwNLVBFXCaps DWORD ?
      ; driver FX capabilities for non-local->local blts
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for non-local->local blts
    DDNONLOCALVIDMEMCAPS ends
    _DDNONLOCALVIDMEMCAPS typedef DDNONLOCALVIDMEMCAPS
    LPDDNONLOCALVIDMEMCAPS typedef ptr _DDNONLOCALVIDMEMCAPS
    ;*
    ;* More driver surface capabilities (in addition to those described in DDCORECAPS).
    ;* This struct contains the caps bits added to the DDCAPS.ddsCaps structure in DX6.
    ;*
    DDMORESURFACECAPS struct
      dwSize DWORD ?
      ; size of DDMORESURFACECAPS structure
      ddsCapsMore DDSCAPSEX <>
      ;*
      ;* The DDMORESURFACECAPS struct is of variable size. The following list may be
      ;* filled in by DX6-aware drivers (see DDVERSIONINFO) to restrict their
      ;* video memory heaps (those which are exposed to DirectDraw) to
      ;* certain sets of DDSCAPS_ bits. Thse entries are exactly analogous to
      ;* the ddsCaps and ddsCapsAlt members of the VIDMEM structures listed in
      ;* the VIDMEMINFO.pvmList member of DDHALINFO.vmiData. There should be
      ;* exactly DDHALINFO.vmiData.dwNumHeaps copies of tagExtendedHeapRestrictions
      ;* in this struct. The size of this struct is thus:
      ;*  DDMORESURFACECAPS.dwSize = sizeof(DDMORESURFACECAPS) +
      ;*          (DDHALINFO.vmiData.dwNumHeaps-1) * sizeof(DDSCAPSEX)*2;
      ;* Note the -1 accounts for the fact that DDMORESURFACECAPS is declared to have 1
      ;* tagExtendedHeapRestrictions member.
      ;*
      struct ddsExtendedHeapRestrictions
        ddsCapsEx DDSCAPSEX <>
        ddsCapsExAlt DDSCAPSEX <>
      ends
      ] typedef ptr ddsExtendedHeapRestrictions
    DDMORESURFACECAPS ends
    _DDMORESURFACECAPS typedef DDMORESURFACECAPS
    LPDDMORESURFACECAPS typedef ptr DDMORESURFACECAPS
    ; Stereo, driver returns DD_OK if mode is ok for stereo
    DDSTEREOMODE struct
      dwSize DWORD ?
      ; size of DDSTEREOMODECAPS structure
      dwHeight DWORD ?
      dwWidth DWORD ?
      dwBpp DWORD ?
      dwRefreshRate DWORD ?
      bSupported DWORD ?
      ; driver supports this video mode...
    DDSTEREOMODE ends
    _DDSTEREOMODE typedef DDSTEREOMODE
    LPDDSTEREOMODE typedef ptr DDSTEREOMODE
    ;*
    ;* DDRAW palette interface struct
    ;*
    DDRAWI_DDRAWPALETTE_INT struct
      lpVtbl POINTER ?
      ; pointer to array of interface methods
      lpLcl LPDDRAWI_DDRAWPALETTE_LCL ?
      ; pointer to interface data
      lpLink LPDDRAWI_DDRAWPALETTE_INT ?
      ; link to next interface
      dwIntRefCnt DWORD ?
      ; interface reference count
    DDRAWI_DDRAWPALETTE_INT ends
    _DDRAWI_DDRAWPALETTE_INT typedef DDRAWI_DDRAWPALETTE_INT
    ;*
    ;* DDRAW internal version of DIRECTDRAWPALETTE object; it has data after the vtable
    ;*
    DDRAWI_DDRAWPALETTE_GBL struct
      dwRefCnt DWORD ?
      ; reference count
      dwFlags DWORD ?
      ; flags
      lpDD_lcl LPDDRAWI_DIRECTDRAW_LCL ?
      ; PRIVATE: DIRECTDRAW object
      dwProcessId DWORD ?
      ; owning process
      lpColorTable LPPALETTEENTRY ?
      ; array of palette entries
      union
        dwReserved1 XWORD ?
        ; reserved for use by display driver which created this object
        hHELGDIPalette HPALETTE ?
      ends
      ;*
      ;* Fields added in version 5.0. Check if the ddraw version >= 5 (passed during
      ;* driver initialization) to see if these fields will be present.
      ;*
      dwDriverReserved DWORD ?
      ; For use by HAL, regardless of who created object
      dwContentsStamp DWORD ?
      ; Incremented when palette changes.
      ;*
      ;* Fields added in version 6
      ;*
      dwSaveStamp DWORD ?
      ; Incremented when palette changes.
      ;*
      ;* And in version 7
      ;*
      dwHandle DWORD ?
      ;Handle used in drawprim2 palette notification
    DDRAWI_DDRAWPALETTE_GBL ends
    _DDRAWI_DDRAWPALETTE_GBL typedef DDRAWI_DDRAWPALETTE_GBL
    ;*
    ;* (CMcC) The palette no longer maintains a back pointer to the owning surface
    ;* (there may now be many owning surfaces). So the lpDDSurface is now dwReserved0
    ;* (this mod. assumes that sizeof(DWORD) == sizeof(LPDDRAWI_DDRAWSURFACE_LCL). A
    ;* fairly safe assumption I think.
    ;*
    DDRAWI_DDRAWPALETTE_LCL struct
      lpPalMore DWORD ?
      ; pointer to additional local data
      lpGbl LPDDRAWI_DDRAWPALETTE_GBL ?
      ; pointer to data
      dwUnused0 XWORD ?
      ; not currently used.
      dwLocalRefCnt DWORD ?
      ; local ref cnt
      pUnkOuter POINTER ?
      ; outer IUnknown
      lpDD_lcl LPDDRAWI_DIRECTDRAW_LCL ?
      ; pointer to owning local driver object
      dwReserved1 XWORD ?
      ; reserved for use by display driver
      ;*
      ;* Added for DX6
      ;*
      dwDDRAWReserved1 XWORD ?
      dwDDRAWReserved2 XWORD ?
      dwDDRAWReserved3 XWORD ?
    DDRAWI_DDRAWPALETTE_LCL ends
    _DDRAWI_DDRAWPALETTE_LCL typedef DDRAWI_DDRAWPALETTE_LCL
    ; bit definition for dwFlags in DDRAWI_DDRAWPALETTE_GBL and
    ; dwPaletteFlags in D3DHAL_DP2SETPALETTE
    DDRAWIPAL_256 equ 00000001h; 256 entry palette

    DDRAWIPAL_16 equ 00000002h; 16 entry palette

    DDRAWIPAL_GDI equ 00000004h; palette allocated through GDI

    DDRAWIPAL_STORED_8 equ 00000008h; palette stored as 8bpp/entry

    DDRAWIPAL_STORED_16 equ 00000010h; palette stored as 16bpp/entry

    DDRAWIPAL_STORED_24 equ 00000020h; palette stored as 24bpp/entry

    DDRAWIPAL_EXCLUSIVE equ 00000040h; palette being used in exclusive mode

    DDRAWIPAL_INHEL equ 00000080h; palette is done in the hel

    DDRAWIPAL_DIRTY equ 00000100h; gdi palette out 'o sync

    DDRAWIPAL_ALLOW256 equ 00000200h; can fully update palette

    DDRAWIPAL_4 equ 00000400h; 4 entry palette

    DDRAWIPAL_2 equ 00000800h; 2 entry palette

    DDRAWIPAL_STORED_8INDEX equ 00001000h; palette stored as 8-bit index into dst palette

    DDRAWIPAL_ALPHA equ 00002000h; palette entries contain alpha

    ;*
    ;* DDRAW clipper interface struct
    ;*
    DDRAWI_DDRAWCLIPPER_INT struct
      lpVtbl POINTER ?
      ; pointer to array of interface methods
      lpLcl LPDDRAWI_DDRAWCLIPPER_LCL ?
      ; pointer to interface data
      lpLink LPDDRAWI_DDRAWCLIPPER_INT ?
      ; link to next interface
      dwIntRefCnt DWORD ?
      ; interface reference count
    DDRAWI_DDRAWCLIPPER_INT ends
    _DDRAWI_DDRAWCLIPPER_INT typedef DDRAWI_DDRAWCLIPPER_INT
    ;*
    ;* DDRAW internal version of DIRECTDRAWCLIPPER object; it has data after the vtable
    ;*
    DDRAWI_DDRAWCLIPPER_GBL struct
      dwRefCnt DWORD ?
      ; reference count
      dwFlags DWORD ?
      ; flags
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; PRIVATE: DIRECTDRAW object
      dwProcessId DWORD ?
      ; owning process
      dwReserved1 XWORD ?
      ; reserved for use by display driver
      hWnd XWORD ?
      ; window
      lpStaticClipList LPRGNDATA ?
      ; clip list set by app
    DDRAWI_DDRAWCLIPPER_GBL ends
    _DDRAWI_DDRAWCLIPPER_GBL typedef DDRAWI_DDRAWCLIPPER_GBL
    ;*
    ;* (CMcC) As with palettes, the clipper no longer maintains a back pointer to the
    ;* owning surface (there may now be many owning surfaces). So the lpDDSurface
    ;* is now dwReserved0 (this mod. assumes that sizeof(DWORD) ==
    ;* sizeof(LPDDRAWI_DDRAWSURFACE_LCL). A fairly safe assumption I think.
    ;*
    DDRAWI_DDRAWCLIPPER_LCL struct
      lpClipMore DWORD ?
      ; pointer to additional local data
      lpGbl LPDDRAWI_DDRAWCLIPPER_GBL ?
      ; pointer to data
      lpDD_lcl LPDDRAWI_DIRECTDRAW_LCL ?
      ; pointer to owning local DD object
      dwLocalRefCnt DWORD ?
      ; local ref cnt
      pUnkOuter POINTER ?
      ; outer IUnknown
      lpDD_int LPDDRAWI_DIRECTDRAW_INT ?
      ; pointer to owning DD object interface
      dwReserved1 XWORD ?
      ; reserved for use by display driver
      pAddrefedThisOwner POINTER ?
      ;This is the ddraw object that created this
      ;clipper, if nonzero. Must Release it when clipper
      ;is released.
    DDRAWI_DDRAWCLIPPER_LCL ends
    _DDRAWI_DDRAWCLIPPER_LCL typedef DDRAWI_DDRAWCLIPPER_LCL
    DDRAWICLIP_WATCHWINDOW equ 00000001h
    DDRAWICLIP_ISINITIALIZED equ 00000002h
    DDRAWICLIP_INMASTERSPRITELIST equ 00000004h; clipper is referenced in master sprite list

    ;*
    ;* ATTACHLIST - internally used to maintain list of attached surfaces
    ;*
    ATTACHLIST struct
      dwFlags DWORD ?
      lpLink POINTER ?
      ; link to next attached surface
      lpAttached POINTER ?
      ; attached surface local obj
      lpIAttached POINTER ?
      ; attached surface interface
    ATTACHLIST ends
    _ATTACHLIST typedef ATTACHLIST
    LPATTACHLIST typedef ptr ATTACHLIST
    DDAL_IMPLICIT equ 00000001h
    ;*
    ;* DBLNODE - a node in a doubly-linked list of surface interfaces
    ;*
    DBLNODE struct
      next POINTER ?
      ; link to next node
      prev POINTER ?
      ; link to previous node
      object_ LPDDRAWI_DDRAWSURFACE_LCL ?
      ; link to object
      object_int LPDDRAWI_DDRAWSURFACE_INT ?
      ; object interface
    DBLNODE ends
    _DBLNODE typedef DBLNODE
    LPDBLNODE typedef ptr DBLNODE
    ;*
    ;* ACCESSRECTLIST - internally used to all rectangles that are accessed on a surface
    ;*
    ACCESSRECTLIST struct
      lpLink POINTER ?
      ; link to next attached surface
      rDest RECT <>
      ; rectangle being used
      lpOwner LPDDRAWI_DIRECTDRAW_LCL ?
      ; owning local object
      lpSurfaceData POINTER ?
      ; associated screen ptr
      dwFlags DWORD ?
      ; PRIVATE: flags
      lpHeapAliasInfo LPHEAPALIASINFO ?
      ; PRIVATE: aliased heaps being used by this lock
    ACCESSRECTLIST ends
    _ACCESSRECTLIST typedef ACCESSRECTLIST
    LPACCESSRECTLIST typedef ptr ACCESSRECTLIST
    ACCESSRECT_VRAMSTYLE equ 00000001h; PRIVATE: this lock is vram style (vidmem or implict sysmem)

    ACCESSRECT_NOTHOLDINGWIN16LOCK equ 00000002h; PRIVATE: this lock is not holding the Win16 lock

    ACCESSRECT_BROKEN equ 00000004h; PRIVATE: this lock was broken by an invalidate - don't call HAL on unlock

    ifndef WIN95
      ;* 
      ;* Do not change the size of this struct. This will move various members of surface and ddraw
      ;* structs and will prevent binaries from running on old win2k systems (or mismatched later NT builds)
      ;*
      DISPLAYMODEINFO struct
        wWidth WORD ?
        wHeight WORD ?
        wBPP BYTE ?
        wMonitorsAttachedToDesktop BYTE ?
        wRefreshRate WORD ?
      DISPLAYMODEINFO ends
      _DISPLAYMODEINFO typedef DISPLAYMODEINFO
      LPDISPLAYMODEINFO typedef ptr _DISPLAYMODEINFO
      EQUAL_DISPLAYMODE macro a, b
        exitm <(0 == memcmp (and (a), and (b), sizeof(DISPLAYMODEINFO)))>
      endm
    endif
    ;*
    ;* DDRAW surface interface struct
    ;*
    DDRAWI_DDRAWSURFACE_INT struct
      lpVtbl POINTER ?
      ; pointer to array of interface methods
      lpLcl LPDDRAWI_DDRAWSURFACE_LCL ?
      ; pointer to interface data
      lpLink LPDDRAWI_DDRAWSURFACE_INT ?
      ; link to next interface
      dwIntRefCnt DWORD ?
      ; interface reference count
    DDRAWI_DDRAWSURFACE_INT ends
    _DDRAWI_DDRAWSURFACE_INT typedef DDRAWI_DDRAWSURFACE_INT
    ;*
    ;* DDRAW internal version of DIRECTDRAWSURFACE struct
    ;*
    ;* the GBL structure is global data for all duplicate objects
    ;*
    DDRAWI_DDRAWSURFACE_GBL struct
      dwRefCnt DWORD ?
      ; reference count
      dwGlobalFlags DWORD ?
      ; global flags
      union
        lpRectList LPACCESSRECTLIST ?
        ; list of accesses
        dwBlockSizeY DWORD ?
        ; block size that display driver requested (return)
        lSlicePitch SDWORD ?
        ; slice pitch for volume textures
      ends
      union
        lpVidMemHeap LPVMEMHEAP ?
        ; heap vidmem was alloc'ed from
        dwBlockSizeX DWORD ?
        ; block size that display driver requested (return)
      ends
      union
        lpDD LPDDRAWI_DIRECTDRAW_GBL ?
        ; internal DIRECTDRAW object
        lpDDHandle POINTER ?
        ; handle to internal DIRECTDRAW object
        ; for use by display driver
        ; when calling fns in DDRAW16.DLL
      ends
      fpVidMem FLATPTR ?
      ; pointer to video memory
      union
        lPitch SDWORD ?
        ; pitch of surface
        dwLinearSize DWORD ?
        ; linear size of non-rectangular surface
      ends
      wHeight WORD ?
      ; height of surface
      wWidth WORD ?
      ; width of surface
      dwUsageCount DWORD ?
      ; number of access to this surface
      dwReserved1 XWORD ?
      ; reserved for use by display driver
      ; NOTE: this part of the structure is ONLY allocated if the pixel
      ;       format differs from that of the primary display
      ddpfSurface DDPIXELFORMAT <>
      ; pixel format of surface
    DDRAWI_DDRAWSURFACE_GBL ends
    _DDRAWI_DDRAWSURFACE_GBL typedef DDRAWI_DDRAWSURFACE_GBL
    ;*
    ;* This is an extender structure that is allocated off the end of the SURFACE_GBL
    ;* structure. DO NOT place any structures whose size can change in here.
    ;*
    GET_LPDDRAWSURFACE_GBL_MORE macro psurf_gbl
      exitm <(* (LPDDRAWI_DDRAWSURFACE_GBL_MORE *) (psurf_gbl - sizeof(DWORD_PTR)))>
    endm
    ;*
    ;* Return the physical memory pointer for a given surface global object.
    ;*
    ;* NOTE: The physical memory pointer is ONLY valid for surfaces allocated from
    ;* non-local video memory. This field will not be valid for system memory or
    ;* local video memory surfaces.
    ;*
    SURFACE_PHYSICALVIDMEM macro psurf_gbl
      exitm <(GET_LPDDRAWSURFACE_GBL_MORE(psurf_gbl) - fpPhysicalVidMem)>
    endm
    ;*
    ;* NOTE: This structure contains a set of fields for describing linear to physical
    ;* page mappings in the case of page locked system memory. It can also contain the
    ;* physical surface pointer of a surface in non-local memory. As there is no point
    ;* in having both a linear to physical page translation table and a physical memory
    ;* pointer for the same surface they are placed in a union.
    ;*
    DDRAWI_DDRAWSURFACE_GBL_MORE struct
      dwSize DWORD ?
      union
        dwPhysicalPageTable DWORD ?
        ; Physical address of page table (array of physical addresses/one per 4K page)
        fpPhysicalVidMem FLATPTR ?
        ; Physical address of surface (non-local video memory only)
      ends
      pPageTable LPDWORD ?
      ; Linear address of page table
      cPages DWORD ?
      ; Number of Pages
      dwSavedDCContext XWORD ?
      ; PRIVATE: For use by DDSurface::GetDC
      fpAliasedVidMem FLATPTR ?
      ; PRIVATE: Alias for original fpVidMem
      dwDriverReserved XWORD ?
      ; Reserved for driver use (both system and video memory surfaces)
      dwHELReserved XWORD ?
      ; PRIVATE: For HEL use only
      cPageUnlocks DWORD ?
      ; Incremented whenever a surface is PageUnlocked
      hKernelSurface XWORD ?
      ; Kernel handle for this surface
      dwKernelRefCnt DWORD ?
      ; Ref count for kernel handle
      lpColorInfo LPDDCOLORCONTROL ?
      ; PRIVATE: Initial color control settings
      fpNTAlias FLATPTR ?
      ; PRIVATE: Used internally by NT DirectDraw
      dwContentsStamp DWORD ?
      ; Changes when surface data may have changed. 0 means no information
      lpvUnswappedDriverReserved POINTER ?
      ; Reserved for use by display driver. Is not swapped when Flip is called on this surface
      lpDDRAWReserved2 POINTER ?
      dwDDRAWReserved1 DWORD ?
      dwDDRAWReserved2 DWORD ?
      fpAliasOfVidMem FLATPTR ?
      ; PRIVATE: The original VidMem pointer of which fpAliasedVidMem is an alias of
      ; This is used to compare with a given fpVidMem to see if we can use the cached fpAliasedVidMem or
      ; if we need to call GetAliasedVidMem.
    DDRAWI_DDRAWSURFACE_GBL_MORE ends
    _DDRAWI_DDRAWSURFACE_GBL_MORE typedef DDRAWI_DDRAWSURFACE_GBL_MORE
    ;*
    ;* a structure holding additional LCL surface information (can't simply be appended
    ;* to the LCL structure as that structure is of variable size).
    ;*
    DDRAWI_DDRAWSURFACE_MORE struct
      dwSize DWORD ?
      lpIUnknowns POINTER ?
      ; IUnknowns aggregated by this surface
      lpDD_lcl LPDDRAWI_DIRECTDRAW_LCL ?
      ; Pointer to the DirectDraw local object
      dwPageLockCount DWORD ?
      ; count of pagelocks
      dwBytesAllocated DWORD ?
      ; size of sys mem allocated
      lpDD_int LPDDRAWI_DIRECTDRAW_INT ?
      ; Pointer to the DirectDraw interface
      dwMipMapCount DWORD ?
      ; Number of mip-map levels in the chain
      lpDDIClipper LPDDRAWI_DDRAWCLIPPER_INT ?
      ; Interface to attached clipper object
      ;------- Fields added in Version 5.0 -------
      lpHeapAliasInfo LPHEAPALIASINFO ?
      ; PRIVATE: Aliased heaps being referenced by this lock
      dwOverlayFlags DWORD ?
      ; Current overlay flags
      rgjunc POINTER ?
      ; Blitter function table for new blitter
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port currently writting data to this surface
      lpddOverlayFX LPDDOVERLAYFX ?
      ; current overlay fx
      ddsCapsEx DDSCAPSEX <>
      dwTextureStage DWORD ?
      ; stage in multitexture cascade
      lpDDRAWReserved POINTER ?
      lpDDRAWReserved2 POINTER ?
      lpDDrawReserved3 POINTER ?
      dwDDrawReserved4 DWORD ?
      lpDDrawReserved5 POINTER ?
      lpGammaRamp LPDWORD ?
      lpOriginalGammaRamp LPDWORD ?
      lpDDrawReserved6 POINTER ?
      ifndef WIN95
        dmiDDrawReserved7 DISPLAYMODEINFO <>
      endif
      dwSurfaceHandle DWORD ?
      ; cookie for use with CreateSurfaceEx DDI
      qwDDrawReserved8 DWORD 2 dup (?)
      lpDDrawReserved9 POINTER ?
      cSurfaces DWORD ?
      ;PRIVATE
      pCreatedDDSurfaceDesc2 LPDDSURFACEDESC2 ?
      ;PRIVATE
      slist POINTER ?
      ;PRIVATE
      dwFVF DWORD ?
      ; saved FVF flags for exe bufs
      lpVB POINTER ?
      ;PRIVATE
    DDRAWI_DDRAWSURFACE_MORE ends
    _DDRAWI_DDRAWSURFACE_MORE typedef DDRAWI_DDRAWSURFACE_MORE
    ;*
    ;* Special values assigned to dwPFIndex member of DDRAWI_DDRAWSURFACE_MORE.
    ;*
    PFINDEX_UNINITIALIZED equ (0); pixel-format index is in uninitialized state

    PFINDEX_UNSUPPORTED equ (not 0); surface's pixel format is not supported by HEL

    ;*
    ;* the LCL structure is local data for each individual surface object
    ;*
    _DDRAWI_DDRAWSURFACE_LCL struct
      lpSurfMore LPDDRAWI_DDRAWSURFACE_MORE ?
      ; pointer to additional local data
      lpGbl LPDDRAWI_DDRAWSURFACE_GBL ?
      ; pointer to surface shared data
      hDDSurface XWORD ?
      ; NT Kernel-mode handle was dwUnused0
      lpAttachList LPATTACHLIST ?
      ; link to surfaces we attached to
      lpAttachListFrom LPATTACHLIST ?
      ; link to surfaces that attached to this one
      dwLocalRefCnt DWORD ?
      ; object refcnt
      dwProcessId DWORD ?
      ; owning process
      dwFlags DWORD ?
      ; flags
      ddsCaps DDSCAPS <>
      ; capabilities of surface
      union
        lpDDPalette LPDDRAWI_DDRAWPALETTE_INT ?
        ; associated palette
        lp16DDPalette LPDDRAWI_DDRAWPALETTE_INT ?
        ; 16-bit ptr to associated palette
      ends
      union
        lpDDClipper LPDDRAWI_DDRAWCLIPPER_LCL ?
        ; associated clipper
        lp16DDClipper LPDDRAWI_DDRAWCLIPPER_INT ?
        ; 16-bit ptr to associated clipper
      ends
      dwModeCreatedIn DWORD ?
      dwBackBufferCount DWORD ?
      ; number of back buffers created
      ddckCKDestBlt DDCOLORKEY <>
      ; color key for destination blt use
      ddckCKSrcBlt DDCOLORKEY <>
      ; color key for source blt use
      ;    IUnknown              FAR *pUnkOuter; // outer IUnknown
      hDC XWORD ?
      ; owned dc
      dwReserved1 XWORD ?
      ; reserved for use by display driver
      ;*
      ;* NOTE: this part of the structure is ONLY allocated if the surface
      ;*       can be used for overlays.  ddckCKSrcOverlay MUST NOT BE MOVED
      ;*       from the start of this area.
      ;*
      ddckCKSrcOverlay DDCOLORKEY <>
      ; color key for source overlay use
      ddckCKDestOverlay DDCOLORKEY <>
      ; color key for destination overlay use
      lpSurfaceOverlaying LPDDRAWI_DDRAWSURFACE_INT ?
      ; surface we are overlaying
      dbnOverlayNode DBLNODE <>
      ;*
      ;* overlay rectangle, used by DDHEL
      ;*
      rcOverlaySrc RECT <>
      rcOverlayDest RECT <>
      ;*
      ;* the below values are kept here for ddhel. they're set by UpdateOverlay,
      ;* they're used whenever the overlays are redrawn.
      ;*
      dwClrXparent DWORD ?
      ; the *actual* color key (override, colorkey, or CLR_INVALID)
      dwAlpha DWORD ?
      ; the per surface alpha
      ;*
      ;* overlay position
      ;*
      lOverlayX SDWORD ?
      ; current x position
      lOverlayY SDWORD ?
      ; current y position
    _DDRAWI_DDRAWSURFACE_LCL ends
    DDRAWI_DDRAWSURFACE_LCL typedef _DDRAWI_DDRAWSURFACE_LCL
    DDRAWISURFGBL_MEMFREE equ 00000001h; video memory has been freed

    DDRAWISURFGBL_SYSMEMREQUESTED equ 00000002h; surface is in system memory at request of user

    DDRAWISURFGBL_ISGDISURFACE equ 00000004h; This surface represents what GDI thinks is front buffer

    DDRAWISURFGBL_SOFTWAREAUTOFLIP equ 00000008h; This surface is autoflipped using software

    DDRAWISURFGBL_LOCKNOTHOLDINGWIN16LOCK equ 00000010h; PRIVATE: a vram lock of the entire surface is not holding the Win16 lock

    DDRAWISURFGBL_LOCKVRAMSTYLE equ 00000020h; PRIVATE: entire surface was locked with VRAM style lock

    DDRAWISURFGBL_LOCKBROKEN equ 00000040h; PRIVATE: a lock of the entire surface was broken by an invalidate

    DDRAWISURFGBL_IMPLICITHANDLE equ 00000080h; This dwKernelHandle was created implicitly

    DDRAWISURFGBL_ISCLIENTMEM equ 00000100h; PRIVATE: the memory pointer to by fpVidMem was allocated by the client

    DDRAWISURFGBL_HARDWAREOPSOURCE equ 00000200h; This surface was the source for an asynchronous hardware operation

    DDRAWISURFGBL_HARDWAREOPDEST equ 00000400h; This surface was dest for an asynchronous hardware operation

    DDRAWISURFGBL_HARDWAREOPSTARTED equ <(DDRAWISURFGBL_HARDWAREOPSOURCE or DDRAWISURFGBL_HARDWAREOPDEST)>
    DDRAWISURFGBL_VPORTINTERLEAVED equ 00000800h; This surface contains interleaved video port data

    DDRAWISURFGBL_VPORTDATA equ 00001000h; This surface received data from the video port

    DDRAWISURFGBL_LATEALLOCATELINEAR equ 00002000h; Optimized surface was allocated as a formless chunk. lPitch invalid, dwLinearSize valid.

    DDRAWISURFGBL_SYSMEMEXECUTEBUFFER equ 00004000h; Driver sets this flag to tell ddraw that the surface was allocated in system memory

    DDRAWISURFGBL_FASTLOCKHELD equ 00008000h; PRIVATE: indicates that InternLock took the fast path

    DDRAWISURFGBL_READONLYLOCKHELD equ 00010000h; PRIVATE: indicates that the application indicated read-only lock

    DDRAWISURFGBL_DX8SURFACE equ 00080000h; PRIVATE: indicates that the surace was created using DX8

    DDRAWISURFGBL_DDHELDONTFREE equ 00100000h; PRIVATE: indicates that the surace memory should not be freed by the HEL

    DDRAWISURFGBL_NOTIFYWHENUNLOCKED equ 00200000h; PRIVATE: indicates that the this surface help a NOSYSLOCK lock when a mode change occured

    ;*
    ;* NOTE: This flag was previously DDRAWISURFGBL_INVALID. This flags has been retired
    ;* and replaced by DDRAWISURF_INVALID in the local object.
    ;*
    DDRAWISURFGBL_RESERVED0 equ 80000000h; Reserved flag

    DDRAWISURF_ATTACHED equ 00000001h; surface is attached to another

    DDRAWISURF_IMPLICITCREATE equ 00000002h; surface implicitly created

    DDRAWISURF_ISFREE equ 00000004h; surface already freed (temp flag)

    DDRAWISURF_ATTACHED_FROM equ 00000008h; surface has others attached to it

    DDRAWISURF_IMPLICITROOT equ 00000010h; surface root of implicit creation

    DDRAWISURF_PARTOFPRIMARYCHAIN equ 00000020h; surface is part of primary chain

    DDRAWISURF_DATAISALIASED equ 00000040h; used for thunking

    DDRAWISURF_HASDC equ 00000080h; has a DC

    DDRAWISURF_HASCKEYDESTOVERLAY equ 00000100h; surface has CKDestOverlay

    DDRAWISURF_HASCKEYDESTBLT equ 00000200h; surface has CKDestBlt

    DDRAWISURF_HASCKEYSRCOVERLAY equ 00000400h; surface has CKSrcOverlay

    DDRAWISURF_HASCKEYSRCBLT equ 00000800h; surface has CKSrcBlt

    DDRAWISURF_LOCKEXCLUDEDCURSOR equ 00001000h; surface was locked and excluded cursor

    DDRAWISURF_HASPIXELFORMAT equ 00002000h; surface structure has pixel format data

    DDRAWISURF_HASOVERLAYDATA equ 00004000h; surface structure has overlay data

    DDRAWISURF_SETGAMMA equ 00008000h; gamma ramp for this surface is active

    DDRAWISURF_SW_CKEYDESTOVERLAY equ 00010000h; surface expects to process colorkey in software

    DDRAWISURF_SW_CKEYDESTBLT equ 00020000h; surface expects to process colorkey in software

    DDRAWISURF_SW_CKEYSRCOVERLAY equ 00040000h; surface expects to process colorkey in software

    DDRAWISURF_SW_CKEYSRCBLT equ 00080000h; surface expects to process colorkey in software

    DDRAWISURF_HW_CKEYDESTOVERLAY equ 00100000h; surface expects to process colorkey in hardware

    DDRAWISURF_HW_CKEYDESTBLT equ 00200000h; surface expects to process colorkey in hardware

    DDRAWISURF_HW_CKEYSRCOVERLAY equ 00400000h; surface expects to process colorkey in hardware

    DDRAWISURF_HW_CKEYSRCBLT equ 00800000h; surface expects to process colorkey in hardware

    DDRAWISURF_INMASTERSPRITELIST equ 01000000h; surface is referenced in master sprite list

    DDRAWISURF_HELCB equ 02000000h; surface is the ddhel cb. must call hel for lock/blt.

    DDRAWISURF_FRONTBUFFER equ 04000000h; surface was originally a front buffer

    DDRAWISURF_BACKBUFFER equ 08000000h; surface was originally backbuffer

    DDRAWISURF_INVALID equ 10000000h; surface has been invalidated by mode set

    DDRAWISURF_DCIBUSY equ 20000000h; HEL has turned off BUSY so DCI would work

    DDRAWISURF_GETDCNULL equ 40000000h; getdc could not lock and so returned GetDC(NULL)

    ;#define DDRAWISURF_CANTLOCK             0x20000000L     // surface cannot be locked (primary created by HEL)
    DDRAWISURF_STEREOSURFACELEFT equ 20000000h; surface is left of stereo pair

    DDRAWISURF_DRIVERMANAGED equ 40000000h; Surface is a driver managed texture (D3D)

    DDRAWISURF_DCILOCK equ 80000000h; Surface was locked using DCIBeginAccess

    ;*
    ;* rop stuff
    ;*
    ROP_HAS_SOURCE equ 00000001h
    ROP_HAS_PATTERN equ 00000002h
    ROP_HAS_SOURCEPATTERN equ <ROP_HAS_SOURCE or ROP_HAS_PATTERN>
    ;*
    ;* mode information
    ;*
    DDHALMODEINFO struct
      dwWidth DWORD ?
      ; width (in pixels) of mode
      dwHeight DWORD ?
      ; height (in pixels) of mode
      lPitch SDWORD ?
      ; pitch (in bytes) of mode
      dwBPP DWORD ?
      ; bits per pixel
      wFlags WORD ?
      ; flags
      wRefreshRate WORD ?
      ; refresh rate
      dwRBitMask DWORD ?
      ; red bit mask
      dwGBitMask DWORD ?
      ; green bit mask
      dwBBitMask DWORD ?
      ; blue bit mask
      dwAlphaBitMask DWORD ?
      ; alpha bit mask
    DDHALMODEINFO ends
    _DDHALMODEINFO typedef DDHALMODEINFO
    LPDDHALMODEINFO typedef ptr DDHALMODEINFO
    DDMODEINFO_PALETTIZED equ 0001h; mode is palettized

    DDMODEINFO_MODEX equ 0002h; mode is a modex mode

    DDMODEINFO_UNSUPPORTED equ 0004h; mode is not supported by driver

    ;*
    ;* Note internally, standard VGA modes are tagged as MODEX and STANDARDVGA
    ;*
    DDMODEINFO_STANDARDVGA equ 0008h; mode is standard vga, e.g. mode 0x13

    DDMODEINFO_MAXREFRESH equ 0010h; refresh rate specified is the max supported

    DDMODEINFO_STEREO equ 0020h; mode can be switched to stereo

    ;*
    ;* DDRAW interface struct
    ;*
    DDRAWI_DIRECTDRAW_INT struct
      lpVtbl POINTER ?
      ; pointer to array of interface methods
      lpLcl LPDDRAWI_DIRECTDRAW_LCL ?
      ; pointer to interface data
      lpLink LPDDRAWI_DIRECTDRAW_INT ?
      ; link to next interface
      dwIntRefCnt DWORD ?
      ; interface reference count
    DDRAWI_DIRECTDRAW_INT ends
    _DDRAWI_DIRECTDRAW_INT typedef DDRAWI_DIRECTDRAW_INT
    ;*
    ;* DDRAW version of DirectDraw object; it has data after the vtable
    ;*
    ;* all entries marked as PRIVATE are not for use by the display driver
    ;*
    DDHAL_CALLBACKS struct
      cbDDCallbacks DDHAL_DDCALLBACKS <>
      ; addresses in display driver for DIRECTDRAW object HAL
      cbDDSurfaceCallbacks DDHAL_DDSURFACECALLBACKS <>
      ; addresses in display driver for DIRECTDRAWSURFACE object HAL
      cbDDPaletteCallbacks DDHAL_DDPALETTECALLBACKS <>
      ; addresses in display driver for DIRECTDRAWPALETTE object HAL
      HALDD DDHAL_DDCALLBACKS <>
      ; HAL for DIRECTDRAW object
      HALDDSurface DDHAL_DDSURFACECALLBACKS <>
      ; HAL for DIRECTDRAWSURFACE object
      HALDDPalette DDHAL_DDPALETTECALLBACKS <>
      ; HAL for DIRECTDRAWPALETTE object
      HELDD DDHAL_DDCALLBACKS <>
      ; HEL for DIRECTDRAW object
      HELDDSurface DDHAL_DDSURFACECALLBACKS <>
      ; HEL for DIRECTDRAWSURFACE object
      HELDDPalette DDHAL_DDPALETTECALLBACKS <>
      ; HEL for DIRECTDRAWPALETTE object
      cbDDExeBufCallbacks DDHAL_DDEXEBUFCALLBACKS <>
      ; addresses in display driver for DIRECTDRAWEXEBUF pseudo object HAL
      HALDDExeBuf DDHAL_DDEXEBUFCALLBACKS <>
      ; HAL for DIRECTDRAWEXEBUF pseudo object
      HELDDExeBuf DDHAL_DDEXEBUFCALLBACKS <>
      ; HEL for DIRECTDRAWEXEBUF preudo object
      cbDDVideoPortCallbacks DDHAL_DDVIDEOPORTCALLBACKS <>
      ; addresses in display driver for VideoPort object HAL
      HALDDVideoPort DDHAL_DDVIDEOPORTCALLBACKS <>
      ; HAL for DIRECTDRAWVIDEOPORT psuedo object
      cbDDColorControlCallbacks DDHAL_DDCOLORCONTROLCALLBACKS <>
      ; addresses in display driver for color control object HAL
      HALDDColorControl DDHAL_DDCOLORCONTROLCALLBACKS <>
      ; HAL for DIRECTDRAWCOLORCONTROL psuedo object
      cbDDMiscellaneousCallbacks DDHAL_DDMISCELLANEOUSCALLBACKS <>
      HALDDMiscellaneous DDHAL_DDMISCELLANEOUSCALLBACKS <>
      cbDDKernelCallbacks DDHAL_DDKERNELCALLBACKS <>
      HALDDKernel DDHAL_DDKERNELCALLBACKS <>
      cbDDMotionCompCallbacks DDHAL_DDMOTIONCOMPCALLBACKS <>
      HALDDMotionComp DDHAL_DDMOTIONCOMPCALLBACKS <>
    DDHAL_CALLBACKS ends
    _DDHAL_CALLBACKS typedef DDHAL_CALLBACKS
    LPDDHAL_CALLBACKS typedef ptr DDHAL_CALLBACKS
    ;*
    ;* This structure mirrors the first entries of the DDCAPS but is of a fixed
    ;* size and will not grow as DDCAPS grows. This is the structure your driver
    ;* returns in DDCOREINFO. Additional caps will be requested via a GetDriverInfo
    ;* call.
    ;*
    DDCORECAPS struct
      dwSize DWORD ?
      ; size of the DDDRIVERCAPS structure
      dwCaps DWORD ?
      ; driver specific capabilities
      dwCaps2 DWORD ?
      ; more driver specific capabilites
      dwCKeyCaps DWORD ?
      ; color key capabilities of the surface
      dwFXCaps DWORD ?
      ; driver specific stretching and effects capabilites
      dwFXAlphaCaps DWORD ?
      ; alpha driver specific capabilities
      dwPalCaps DWORD ?
      ; palette capabilities
      dwSVCaps DWORD ?
      ; stereo vision capabilities
      dwAlphaBltConstBitDepths DWORD ?
      ; DDBD_2,4,8
      dwAlphaBltPixelBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaBltSurfaceBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaOverlayConstBitDepths DWORD ?
      ; DDBD_2,4,8
      dwAlphaOverlayPixelBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwZBufferBitDepths DWORD ?
      ; DDBD_8,16,24,32
      dwVidMemTotal DWORD ?
      ; total amount of video memory
      dwVidMemFree DWORD ?
      ; amount of free video memory
      dwMaxVisibleOverlays DWORD ?
      ; maximum number of visible overlays
      dwCurrVisibleOverlays DWORD ?
      ; current number of visible overlays
      dwNumFourCCCodes DWORD ?
      ; number of four cc codes
      dwAlignBoundarySrc DWORD ?
      ; source rectangle alignment
      dwAlignSizeSrc DWORD ?
      ; source rectangle byte size
      dwAlignBoundaryDest DWORD ?
      ; dest rectangle alignment
      dwAlignSizeDest DWORD ?
      ; dest rectangle byte size
      dwAlignStrideAlign DWORD ?
      ; stride alignment
      dwRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported
      ddsCaps DDSCAPS <>
      ; DDSCAPS structure has all the general capabilities
      dwMinOverlayStretch DWORD ?
      ; minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxOverlayStretch DWORD ?
      ; maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinLiveVideoStretch DWORD ?
      ; minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxLiveVideoStretch DWORD ?
      ; maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinHwCodecStretch DWORD ?
      ; minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxHwCodecStretch DWORD ?
      ; maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwReserved1 DWORD ?
      ; reserved
      dwReserved2 DWORD ?
      ; reserved
      dwReserved3 DWORD ?
      ; reserved
      dwSVBCaps DWORD ?
      ; driver specific capabilities for System->Vmem blts
      dwSVBCKeyCaps DWORD ?
      ; driver color key capabilities for System->Vmem blts
      dwSVBFXCaps DWORD ?
      ; driver FX capabilities for System->Vmem blts
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for System->Vmem blts
      dwVSBCaps DWORD ?
      ; driver specific capabilities for Vmem->System blts
      dwVSBCKeyCaps DWORD ?
      ; driver color key capabilities for Vmem->System blts
      dwVSBFXCaps DWORD ?
      ; driver FX capabilities for Vmem->System blts
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for Vmem->System blts
      dwSSBCaps DWORD ?
      ; driver specific capabilities for System->System blts
      dwSSBCKeyCaps DWORD ?
      ; driver color key capabilities for System->System blts
      dwSSBFXCaps DWORD ?
      ; driver FX capabilities for System->System blts
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for System->System blts
      dwMaxVideoPorts DWORD ?
      ; maximum number of usable video ports
      dwCurrVideoPorts DWORD ?
      ; current number of video ports used
      dwSVBCaps2 DWORD ?
      ; more driver specific capabilities for System->Vmem blts
    DDCORECAPS ends
    _DDCORECAPS typedef DDCORECAPS
    LPDDCORECAPS typedef ptr DDCORECAPS
    DDRAWI_DIRECTDRAW_GBL struct
      dwRefCnt DWORD ?
      ;*  0*
      ; reference count
      dwFlags DWORD ?
      ;*  4*
      ; flags
      fpPrimaryOrig FLATPTR ?
      ;*  8*
      ; primary surf vid mem. ptr
      ddCaps DDCORECAPS <>
      ;*  c*
      ; driver caps
      dwInternal1 DWORD ?
      ;*148*
      ; Private to ddraw.dll
      dwUnused1 DWORD 9 dup (?)
      ;*16c*
      ; not currently used
      lpDDCBtmp LPDDHAL_CALLBACKS ?
      ;*170*
      ; HAL callbacks
      dsList LPDDRAWI_DDRAWSURFACE_INT ?
      ;*174*
      ; PRIVATE: list of all surfaces
      palList LPDDRAWI_DDRAWPALETTE_INT ?
      ;*178*
      ; PRIVATE: list of all palettes
      clipperList LPDDRAWI_DDRAWCLIPPER_INT ?
      ;*17c*
      ; PRIVATE: list of all clippers
      lp16DD LPDDRAWI_DIRECTDRAW_GBL ?
      ;*180*
      ; PRIVATE: 16-bit ptr to this struct
      dwMaxOverlays DWORD ?
      ;*184*
      ; maximum number of overlays
      dwCurrOverlays DWORD ?
      ;*188*
      ; current number of visible overlays
      dwMonitorFrequency DWORD ?
      ;*18c*
      ; monitor frequency in current mode
      ddHELCaps DDCORECAPS <>
      ;*190*
      ; HEL capabilities
      dwUnused2 DWORD 50 dup (?)
      ;*2cc*
      ; not currently used
      ddckCKDestOverlay DDCOLORKEY <>
      ;*394*
      ; color key for destination overlay use
      ddckCKSrcOverlay DDCOLORKEY <>
      ;*39c*
      ; color key for source overlay use
      vmiData VIDMEMINFO <>
      ;*3a4*
      ; info about vid memory
      lpDriverHandle POINTER ?
      ;*3f4*
      ; handle for use by display driver
      ; to call fns in DDRAW16.DLL
      lpExclusiveOwner LPDDRAWI_DIRECTDRAW_LCL ?
      ;*3f8*
      ; PRIVATE: exclusive local object
      dwModeIndex DWORD ?
      ;*3fc*
      ; current mode index
      dwModeIndexOrig DWORD ?
      ;*400*
      ; original mode index
      dwNumFourCC DWORD ?
      ;*404*
      ; number of fourcc codes supported
      lpdwFourCC POINTER ?
      ;*408*
      ; PRIVATE: fourcc codes supported
      dwNumModes DWORD ?
      ;*40c*
      ; number of modes supported
      lpModeInfo LPDDHALMODEINFO ?
      ;*410*
      ; PRIVATE: mode information
      plProcessList PROCESS_LIST <>
      ;*424*
      ; PRIVATE: list of processes using driver
      dwSurfaceLockCount DWORD ?
      ;*428*
      ; total number of outstanding locks
      dwAliasedLockCnt DWORD ?
      ;*42c*
      ; PRIVATE: number of outstanding aliased locks
      dwReserved3 XWORD ?
      ;*430*
      ; reserved for use by display driver
      hDD XWORD ?
      ;*434*
      ; PRIVATE: NT Kernel-mode handle (was dwFree3).
      cObsolete SBYTE 12 dup (?)
      ;*438*
      ; Obsolete field, do not use
      dwReserved1 DWORD ?
      ;*444*
      ; reserved for use by display driver
      dwReserved2 DWORD ?
      ;*448*
      ; reserved for use by display driver
      dbnOverlayRoot DBLNODE <>
      ;*44c*
      ; The root node of the doubly-
      ; linked list of overlay z orders.
      lpwPDeviceFlags LPWORD ?
      ;*45c*
      ; driver physical device flags
      dwPDevice DWORD ?
      ;*460*
      ; driver physical device (16:16 pointer)
      dwWin16LockCnt DWORD ?
      ;*464*
      ; count on win16 holds
      dwUnused3 DWORD ?
      ;*468*
      ; was lpWin16LockOwner
      hInstance DWORD ?
      ;*46c*
      ; instance handle of driver
      dwEvent16 DWORD ?
      ;*470*
      ; 16-bit event
      dwSaveNumModes DWORD ?
      ;*474*
      ; saved number of modes supported
      ;------- Fields added in Version 2.0 -------
      lpD3DGlobalDriverData XWORD ?
      ;*478*
      ; Global D3D Data
      lpD3DHALCallbacks XWORD ?
      ;*47c*
      ; D3D HAL Callbacks
      ddBothCaps DDCORECAPS <>
      ;*480*
      ; logical AND of driver and HEL caps
      ;------- Fields added in Version 5.0 -------
      lpDDVideoPortCaps LPDDVIDEOPORTCAPS ?
      ;*5bc*
      ; Info returned by the HAL (an array if more than one video port)
      dvpList LPDDRAWI_DDVIDEOPORT_INT ?
      ;*5c0*
      ; PRIVATE: list of all video ports
      lpD3DHALCallbacks2 XWORD ?
      ;*5c4*
      ; Post-DX3 D3D HAL callbacks
      rectDevice RECT <>
      ;*5c8*
      ; rectangle (in desktop coord) for device
      cMonitors DWORD ?
      ;*5d8*
      ; number of monitors in the system
      gpbmiSrc POINTER ?
      ;*5dc*
      ; PRIVATE: used by HEL
      gpbmiDest POINTER ?
      ;*5e0*
      ; PRIVATE: used by HEL
      phaiHeapAliases LPHEAPALIASINFO ?
      ;*5e4*
      ; PRIVATE: video memory heap aliases
      hKernelHandle XWORD ?
      ;*5e8*
      pfnNotifyProc XWORD ?
      ;*5ec*
      ; Notification proc registered w/ VDD
      lpDDKernelCaps LPDDKERNELCAPS ?
      ;*5f0*
      ; Capabilies of kernel mode interface
      lpddNLVCaps LPDDNONLOCALVIDMEMCAPS ?
      ;*5f4*
      ; hardware non-local to local vidmem caps
      lpddNLVHELCaps LPDDNONLOCALVIDMEMCAPS ?
      ;*5f8*
      ; emulation layer non-local to local vidmem caps
      lpddNLVBothCaps LPDDNONLOCALVIDMEMCAPS ?
      ;*5fc*
      ; logical AND of hardware and emulation non-local to local vidmem caps
      lpD3DExtendedCaps XWORD ?
      ;*600*
      ; extended caps for D3D
      ;--------Fields added in Version 5.0A
      dwDOSBoxEvent DWORD ?
      ;*604*
      ; Event set when returning from a DOS box
      rectDesktop RECT <>
      ;*608*
      ; Desktop coordinates
      cDriverName SBYTE MAX_DRIVER_NAME dup (?)
      ;*618*
      ; Display name
      ;------- Fields added in Version 6.0 -------
      lpD3DHALCallbacks3 XWORD ?
      ;*638*
      ; DX6 D3D callbacks
      dwNumZPixelFormats DWORD ?
      ;*63c*
      ; Number of z-buffer+stencil pixel formats
      lpZPixelFormats LPDDPIXELFORMAT ?
      ;*640*
      ; Pointer to array of z-buffer pixel formats
      mcList LPDDRAWI_DDMOTIONCOMP_INT ?
      ;*644*
      ; PRIVATE: list of all motion comp objects
      hDDVxd DWORD ?
      ;*648*
      ; handle to ddraw.vxd
      ddsCapsMore DDSCAPSEX <>
      ;*64c*
      ; as queried via GUID_DDMoreSurfaceCaps
    DDRAWI_DIRECTDRAW_GBL ends
    _DDRAWI_DIRECTDRAW_GBL typedef DDRAWI_DIRECTDRAW_GBL
    DDRAWI_DIRECTDRAW_LCL struct
      lpDDMore DWORD ?
      ; pointer to additional local data
      lpGbl LPDDRAWI_DIRECTDRAW_GBL ?
      ; pointer to data
      dwUnused0 DWORD ?
      ; not currently used
      dwLocalFlags DWORD ?
      ; local flags (DDRAWILCL_)
      dwLocalRefCnt DWORD ?
      ; local ref cnt
      dwProcessId DWORD ?
      ; owning process id
      pUnkOuter POINTER ?
      ; outer IUnknown
      dwObsolete1 DWORD ?
      hWnd XWORD ?
      hDC XWORD ?
      dwErrorMode DWORD ?
      lpPrimary LPDDRAWI_DDRAWSURFACE_INT ?
      lpCB LPDDRAWI_DDRAWSURFACE_INT ?
      dwPreferredMode DWORD ?
      ;------- Fields added in Version 2.0 -------
      hD3DInstance HINSTANCE ?
      ; Handle of Direct3D's DLL.
      pD3DIUnknown POINTER ?
      ; Direct3D's aggregated IUnknown.
      lpDDCB LPDDHAL_CALLBACKS ?
      ; HAL callbacks
      hDDVxd XWORD ?
      ; handle to ddraw.vxd
      ;------- Fields added in Version 5.0 -------
      dwAppHackFlags DWORD ?
      ; app compatibilty flags
      ;------- Fields added in Version 5.A -------
      hFocusWnd XWORD ?
      ; Focus window set via SetCoopLevel
      dwHotTracking DWORD ?
      ; Reactive menu etc setting cached while fullscreen
      dwIMEState DWORD ?
      ; IME toolbar setting cached while fullscreen
      ;------- Fields added in Version 6.0 -------
      hWndPopup XWORD ?
      hDD XWORD ?
      ; PRIVATE: NT Kernel-mode handle
      hGammaCalibrator XWORD ?
      ; Private
      lpGammaCalibrator LPDDGAMMACALIBRATORPROC ?
      ; Private
    DDRAWI_DIRECTDRAW_LCL ends
    _DDRAWI_DIRECTDRAW_LCL typedef DDRAWI_DIRECTDRAW_LCL
    DDRAWILCL_HASEXCLUSIVEMODE equ 00000001h
    DDRAWILCL_ISFULLSCREEN equ 00000002h
    DDRAWILCL_SETCOOPCALLED equ 00000004h
    DDRAWILCL_ACTIVEYES equ 00000008h
    DDRAWILCL_ACTIVENO equ 00000010h
    DDRAWILCL_HOOKEDHWND equ 00000020h
    DDRAWILCL_ALLOWMODEX equ 00000040h
    DDRAWILCL_V1SCLBEHAVIOUR equ 00000080h
    DDRAWILCL_MODEHASBEENCHANGED equ 00000100h
    DDRAWILCL_CREATEDWINDOW equ 00000200h
    DDRAWILCL_DIRTYDC equ 00000400h; Set on ChangeDisplaySettings, cleared when device DC is reinited

    DDRAWILCL_DISABLEINACTIVATE equ 00000800h
    DDRAWILCL_CURSORCLIPPED equ 00001000h
    DDRAWILCL_EXPLICITMONITOR equ 00002000h; device was chosen explicitly i.e. not DDrawCreate(NULL)

    DDRAWILCL_MULTITHREADED equ 00004000h; App threaten to be multithreaded

    DDRAWILCL_FPUSETUP equ 00008000h; D3D does not need to switch to single prec/exceptions disabled each time

    DDRAWILCL_POWEREDDOWN equ 00010000h; Private: indicates that screen saver is powered down

    DDRAWILCL_DIRECTDRAW7 equ 00020000h; PRIVATE: Marks if this is a IDirectDraw7 object

    DDRAWILCL_ATTEMPTEDD3DCONTEXT equ 00040000h; PRIVATE: Marks if this ddraw local has attempted to create a d3d context

    DDRAWILCL_FPUPRESERVE equ 00080000h; D3D needs to switch to single prec/exceptions disabled each time

    DDRAWILCL_DX8DRIVER equ 00100000h; PRIVATE: Set if this drvier can handle lightweight surfaces

    DDRAWILCL_DIRECTDRAW8 equ 00200000h; PRIVATE: Marks if this is a IDirectDraw8 object

    DDRAWI_xxxxxxxxx1 equ 00000001h; unused

    DDRAWI_xxxxxxxxx2 equ 00000002h; unused

    DDRAWI_VIRTUALDESKTOP equ 00000008h; driver is really a multi-monitor virtual desktop

    DDRAWI_MODEX equ 00000010h; driver is using modex

    DDRAWI_DISPLAYDRV equ 00000020h; driver is display driver

    DDRAWI_FULLSCREEN equ 00000040h; driver in fullscreen mode

    DDRAWI_MODECHANGED equ 00000080h; display mode has been changed

    DDRAWI_NOHARDWARE equ 00000100h; no driver hardware at all

    DDRAWI_PALETTEINIT equ 00000200h; GDI palette stuff has been initalized

    DDRAWI_NOEMULATION equ 00000400h; no emulation at all

    DDRAWI_HASCKEYDESTOVERLAY equ 00000800h; driver has CKDestOverlay

    DDRAWI_HASCKEYSRCOVERLAY equ 00001000h; driver has CKSrcOverlay

    DDRAWI_HASGDIPALETTE equ 00002000h; GDI palette exists on primary surface

    DDRAWI_EMULATIONINITIALIZED equ 00004000h; emulation is initialized

    DDRAWI_HASGDIPALETTE_EXCLUSIVE equ 00008000h; exclusive mode palette

    DDRAWI_MODEXILLEGAL equ 00010000h; modex is not supported by this hardware

    DDRAWI_FLIPPEDTOGDI equ 00020000h; driver has been flipped to show GDI surface

    DDRAWI_NEEDSWIN16FORVRAMLOCK equ 00040000h; PRIVATE: Win16 lock must be taken when locking a VRAM surface

    DDRAWI_PDEVICEVRAMBITCLEARED equ 00080000h; PRIVATE: the PDEVICE's VRAM bit was cleared by a lock

    DDRAWI_STANDARDVGA equ 00100000h; Device is using standard VGA mode (DDRAWI_MODEX will be set)

    DDRAWI_EXTENDEDALIGNMENT equ 00200000h; At least one heap has extended alignment. Ignore alignment in VIDMEMINFO

    DDRAWI_CHANGINGMODE equ 00400000h; Currently in the middle of a mode change

    DDRAWI_GDIDRV equ 00800000h; Driver is a GDI driver

    DDRAWI_ATTACHEDTODESKTOP equ 01000000h; Device is attached to the desktop

    DDRAWI_UMODELOADED equ 02000000h; User mode driver dll is loaded

    DDRAWI_DDRAWDATANOTFETCHED equ 04000000h; PRIVATE: Marks mode-change data fetched (NT)

    DDRAWI_SECONDARYDRIVERLOADED equ 08000000h; PRIVATE: Marks if a secndary PVR-style HAL was loaded

    DDRAWI_TESTINGMODES equ 10000000h; PRIVATE: A mode test in is progress

    DDRAWI_DRIVERINFO2 equ 20000000h; PRIVATE: Driver supports GetDriverInfo2

    DDRAWI_BADPDEV equ 40000000h; PRIVATE: Indiactes that we should not re-use this PDEV

    ;*
    ;* VideoPort object interface
    ;*
    DDRAWI_DDVIDEOPORT_INT struct
      lpVtbl POINTER ?
      ; pointer to array of interface methods
      lpLcl LPDDRAWI_DDVIDEOPORT_LCL ?
      ; pointer to interface data
      lpLink LPDDRAWI_DDVIDEOPORT_INT ?
      ; link to next interface
      dwIntRefCnt DWORD ?
      ; interface reference count
      dwFlags DWORD ?
      ; Private
    DDRAWI_DDVIDEOPORT_INT ends
    _DDRAWI_DDVIDEOPORT_INT typedef DDRAWI_DDVIDEOPORT_INT
    DDRAWI_DDVIDEOPORT_LCL struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; pointer to DIRECTDRAW_LCL
      ddvpDesc DDVIDEOPORTDESC <>
      ; description used at create time
      ddvpInfo DDVIDEOPORTINFO <>
      ; most recent video port info
      lpSurface LPDDRAWI_DDRAWSURFACE_INT ?
      ; surface receiving the data
      lpVBISurface LPDDRAWI_DDRAWSURFACE_INT ?
      ; surface receiving the VBI data
      lpFlipInts POINTER ?
      ; PRIVATE: surfaces currently being autoflipped
      dwNumAutoflip DWORD ?
      ; Number of current autoflip surfaces
      dwProcessID DWORD ?
      ; ID of process owning this video port
      dwStateFlags DWORD ?
      dwFlags DWORD ?
      dwRefCnt DWORD ?
      fpLastFlip FLATPTR ?
      ; Location from which we last flipped
      dwReserved1 XWORD ?
      ; Reserved for display driver
      dwReserved2 XWORD ?
      ; Reserved for display driver
      hDDVideoPort HANDLE ?
      ; NT Kernel-mode handle
      dwNumVBIAutoflip DWORD ?
      ;Number of VBI surfaces currently being autoflipped
      lpVBIDesc LPDDVIDEOPORTDESC ?
      ; PRIVATE
      lpVideoDesc LPDDVIDEOPORTDESC ?
      ; PRIVATE
      lpVBIInfo LPDDVIDEOPORTINFO ?
      ; PRIVATE
      lpVideoInfo LPDDVIDEOPORTINFO ?
      ; PRIVATE
      dwVBIProcessID DWORD ?
      ; ID of process owning this video port
      lpVPNotify LPDDRAWI_DDVIDEOPORT_INT ?
    DDRAWI_DDVIDEOPORT_LCL ends
    _DDRAWI_DDVIDEOPORT_LCL typedef DDRAWI_DDVIDEOPORT_LCL
    DDRAWIVPORT_ON equ 00000001h; Video port is pumping data

    DDRAWIVPORT_SOFTWARE_AUTOFLIP equ 00000002h; Video port cannot use hardware autoflip

    DDRAWIVPORT_COLORKEYANDINTERP equ 00000004h; Overlay cannot bob and colorkey at same time

    DDRAWIVPORT_NOKERNELHANDLES equ 00000008h; Unable to allocate kernel resources

    DDRAWIVPORT_SOFTWARE_BOB equ 00000010h; All bobbing must be performed in software

    DDRAWIVPORT_VBION equ 00000020h; Video is on for the VBI region

    DDRAWIVPORT_VIDEOON equ 00000040h; Video is on for the video region

    ;*
    ;* MotionComp object interface
    ;*
    DDRAWI_DDMOTIONCOMP_INT struct
      lpVtbl POINTER ?
      lpLcl LPDDRAWI_DDMOTIONCOMP_LCL ?
      lpLink LPDDRAWI_DDMOTIONCOMP_INT ?
      dwIntRefCnt DWORD ?
    DDRAWI_DDMOTIONCOMP_INT ends
    _DDRAWI_DDMOTIONCOMP_INT typedef DDRAWI_DDMOTIONCOMP_INT
    DDRAWI_DDMOTIONCOMP_LCL struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      guid GUID <>
      dwUncompWidth DWORD ?
      dwUncompHeight DWORD ?
      ddUncompPixelFormat DDPIXELFORMAT <>
      dwInternalFlags DWORD ?
      dwRefCnt DWORD ?
      dwProcessId DWORD ?
      hMoComp HANDLE ?
      dwDriverReserved1 DWORD ?
      dwDriverReserved2 DWORD ?
      dwDriverReserved3 DWORD ?
      lpDriverReserved1 POINTER ?
      lpDriverReserved2 POINTER ?
      lpDriverReserved3 POINTER ?
    DDRAWI_DDMOTIONCOMP_LCL ends
    _DDRAWI_DDMOTIONCOMP_LCL typedef DDRAWI_DDMOTIONCOMP_LCL
    ;*
    ;* structure for display driver to call DDHAL_Create with
    ;*
    DDHALINFO struct
      dwSize DWORD ?
      lpDDCallbacks LPDDHAL_DDCALLBACKS ?
      ; direct draw object callbacks
      lpDDSurfaceCallbacks LPDDHAL_DDSURFACECALLBACKS ?
      ; surface object callbacks
      lpDDPaletteCallbacks LPDDHAL_DDPALETTECALLBACKS ?
      ; palette object callbacks
      vmiData VIDMEMINFO <>
      ; video memory info
      ddCaps DDCORECAPS <>
      ; core hw specific caps
      dwMonitorFrequency DWORD ?
      ; monitor frequency in current mode
      GetDriverInfo LPDDHAL_GETDRIVERINFO ?
      ; callback to get arbitrary vtable from driver
      dwModeIndex DWORD ?
      ; current mode: index into array
      lpdwFourCC LPDWORD ?
      ; fourcc codes supported
      dwNumModes DWORD ?
      ; number of modes supported
      lpModeInfo LPDDHALMODEINFO ?
      ; mode information
      dwFlags DWORD ?
      ; create flags
      lpPDevice POINTER ?
      ; physical device ptr
      hInstance DWORD ?
      ; instance handle of driver
      ;------- Fields added in Version 2.0 -------
      lpD3DGlobalDriverData XWORD ?
      ; D3D global Data
      lpD3DHALCallbacks XWORD ?
      ; D3D callbacks
      lpDDExeBufCallbacks LPDDHAL_DDEXEBUFCALLBACKS ?
      ; Execute buffer pseudo object callbacks
    DDHALINFO ends
    _DDHALINFO typedef DDHALINFO
    LPDDHALINFO typedef ptr DDHALINFO
    DDHALINFOSIZE_V2 equ <sizeof(DDHALINFO)>
    DDHALINFO_ISPRIMARYDISPLAY equ 00000001h; indicates driver is primary display driver

    DDHALINFO_MODEXILLEGAL equ 00000002h; indicates this hardware does not support modex modes

    DDHALINFO_GETDRIVERINFOSET equ 00000004h; indicates that GetDriverInfo is set

    DDHALINFO_GETDRIVERINFO2 equ 00000008h; indicates driver support GetDriverInfo2 variant

    ; of GetDriverInfo. New for DX 8.0
    ;*
    ;* DDRAW16.DLL entry points
    ;*
    TYPE_LPDDHAL_SETINFO typedef proto WIN_STD_CALL_CONV :LPDDHALINFO, :BOOL
    LPDDHAL_SETINFO typedef ptr TYPE_LPDDHAL_SETINFO

    TYPE_LPDDHAL_VIDMEMALLOC typedef proto WIN_STD_CALL_CONV :LPDDRAWI_DIRECTDRAW_GBL, :SDWORD, :DWORD, :DWORD
    LPDDHAL_VIDMEMALLOC typedef ptr TYPE_LPDDHAL_VIDMEMALLOC

    TYPE_LPDDHAL_VIDMEMFREE typedef proto WIN_STD_CALL_CONV :LPDDRAWI_DIRECTDRAW_GBL, :SDWORD, :FLATPTR
    LPDDHAL_VIDMEMFREE typedef ptr TYPE_LPDDHAL_VIDMEMFREE

    DDHAL_SetInfo proto WIN_STD_CALL_CONV :LPDDHALINFO, :BOOL
    DDHAL_VidMemAlloc proto WIN_STD_CALL_CONV :LPDDRAWI_DIRECTDRAW_GBL, :SDWORD, :DWORD, :DWORD
    DDHAL_VidMemFree proto WIN_STD_CALL_CONV :LPDDRAWI_DIRECTDRAW_GBL, :SDWORD, :FLATPTR
    DDHALDDRAWFNS struct
      dwSize DWORD ?
      lpSetInfo LPDDHAL_SETINFO ?
      lpVidMemAlloc LPDDHAL_VIDMEMALLOC ?
      lpVidMemFree LPDDHAL_VIDMEMFREE ?
    DDHALDDRAWFNS ends
    LPDDHALDDRAWFNS typedef ptr DDHALDDRAWFNS
    ;****************************************************************************
    ;*
    ;* DDHAL structures for Surface Object callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL Blt and AlphaBlt fns
    ;*
    DDHAL_BLTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDDestSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; dest surface
      rDest RECTL <>
      ; dest rect
      lpDDSrcSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; src surface
      rSrc RECTL <>
      ; src rect
      dwFlags DWORD ?
      ; blt flags
      dwROPFlags DWORD ?
      ; ROP flags (valid for ROPS only)
      bltFX DDBLTFX <>
      ; blt FX
      ddRVal HRESULT ?
      ; return value
      Blt LPDDHALSURFCB_BLT ?
      ; PRIVATE: ptr to callback
      IsClipped DWORD ?
      ; clipped blt?
      rOrigDest RECTL <>
      ; unclipped dest rect
      ; (only valid if IsClipped)
      rOrigSrc RECTL <>
      ; unclipped src rect
      ; (only valid if IsClipped)
      dwRectCnt DWORD ?
      ; count of dest rects
      ; (only valid if IsClipped)
      prDestRects LPRECT ?
      ; array of dest rects
    DDHAL_BLTDATA ends
    _DDHAL_BLTDATA typedef DDHAL_BLTDATA
    ;*
    ;* structure for passing information to DDHAL Lock fn
    ;*
    DDHAL_LOCKDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      bHasRect DWORD ?
      ; rArea is valid
      rArea RECTL <>
      ; area being locked
      lpSurfData POINTER ?
      ; pointer to screen memory (return value)
      ddRVal HRESULT ?
      ; return value
      Lock_ LPDDHALSURFCB_LOCK ?
      ; PRIVATE: ptr to callback
      dwFlags DWORD ?
      ; DDLOCK flags
    DDHAL_LOCKDATA ends
    _DDHAL_LOCKDATA typedef DDHAL_LOCKDATA
    ;*
    ;* structure for passing information to DDHAL Unlock fn
    ;*
    DDHAL_UNLOCKDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      ddRVal HRESULT ?
      ; return value
      Unlock LPDDHALSURFCB_UNLOCK ?
      ; PRIVATE: ptr to callback
    DDHAL_UNLOCKDATA ends
    _DDHAL_UNLOCKDATA typedef DDHAL_UNLOCKDATA
    ;*
    ;* structure for passing information to DDHAL UpdateOverlay fn
    ;*
    DDHAL_UPDATEOVERLAYDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDDestSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; dest surface
      rDest RECTL <>
      ; dest rect
      lpDDSrcSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; src surface
      rSrc RECTL <>
      ; src rect
      dwFlags DWORD ?
      ; flags
      overlayFX DDOVERLAYFX <>
      ; overlay FX
      ddRVal HRESULT ?
      ; return value
      UpdateOverlay LPDDHALSURFCB_UPDATEOVERLAY ?
      ; PRIVATE: ptr to callback
    DDHAL_UPDATEOVERLAYDATA ends
    _DDHAL_UPDATEOVERLAYDATA typedef DDHAL_UPDATEOVERLAYDATA
    ;*
    ;* structure for passing information to DDHAL UpdateOverlay fn
    ;*
    DDHAL_SETOVERLAYPOSITIONDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSrcSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; src surface
      lpDDDestSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; dest surface
      lXPos SDWORD ?
      ; x position
      lYPos SDWORD ?
      ; y position
      ddRVal HRESULT ?
      ; return value
      SetOverlayPosition LPDDHALSURFCB_SETOVERLAYPOSITION ?
      ; PRIVATE: ptr to callback
    DDHAL_SETOVERLAYPOSITIONDATA ends
    _DDHAL_SETOVERLAYPOSITIONDATA typedef DDHAL_SETOVERLAYPOSITIONDATA
    ;*
    ;* structure for passing information to DDHAL SetPalette fn
    ;*
    DDHAL_SETPALETTEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      lpDDPalette LPDDRAWI_DDRAWPALETTE_GBL ?
      ; palette to set to surface
      ddRVal HRESULT ?
      ; return value
      SetPalette LPDDHALSURFCB_SETPALETTE ?
      ; PRIVATE: ptr to callback
      Attach DWORD ?
      ; attach this palette?
    DDHAL_SETPALETTEDATA ends
    _DDHAL_SETPALETTEDATA typedef DDHAL_SETPALETTEDATA
    ;*
    ;* structure for passing information to DDHAL Flip fn
    ;*
    DDHAL_FLIPDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpSurfCurr LPDDRAWI_DDRAWSURFACE_LCL ?
      ; current surface
      lpSurfTarg LPDDRAWI_DDRAWSURFACE_LCL ?
      ; target surface (to flip to)
      dwFlags DWORD ?
      ; flags
      ddRVal HRESULT ?
      ; return value
      Flip LPDDHALSURFCB_FLIP ?
      ; PRIVATE: ptr to callback
      lpSurfCurrLeft LPDDRAWI_DDRAWSURFACE_LCL ?
      ; current surface
      lpSurfTargLeft LPDDRAWI_DDRAWSURFACE_LCL ?
      ; target surface (to flip to)
    DDHAL_FLIPDATA ends
    _DDHAL_FLIPDATA typedef DDHAL_FLIPDATA
    ;*
    ;* structure for passing information to DDHAL DestroySurface fn
    ;*
    DDHAL_DESTROYSURFACEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      ddRVal HRESULT ?
      ; return value
      DestroySurface LPDDHALSURFCB_DESTROYSURFACE ?
      ; PRIVATE: ptr to callback
    DDHAL_DESTROYSURFACEDATA ends
    _DDHAL_DESTROYSURFACEDATA typedef DDHAL_DESTROYSURFACEDATA
    ;*
    ;* structure for passing information to DDHAL SetClipList fn
    ;*
    DDHAL_SETCLIPLISTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      ddRVal HRESULT ?
      ; return value
      SetClipList LPDDHALSURFCB_SETCLIPLIST ?
      ; PRIVATE: ptr to callback
    DDHAL_SETCLIPLISTDATA ends
    _DDHAL_SETCLIPLISTDATA typedef DDHAL_SETCLIPLISTDATA
    ;*
    ;* structure for passing information to DDHAL AddAttachedSurface fn
    ;*
    DDHAL_ADDATTACHEDSURFACEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      lpSurfAttached LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface to attach
      ddRVal HRESULT ?
      ; return value
      AddAttachedSurface LPDDHALSURFCB_ADDATTACHEDSURFACE ?
      ; PRIVATE: ptr to callback
    DDHAL_ADDATTACHEDSURFACEDATA ends
    _DDHAL_ADDATTACHEDSURFACEDATA typedef DDHAL_ADDATTACHEDSURFACEDATA
    ;*
    ;* structure for passing information to DDHAL SetColorKey fn
    ;*
    DDHAL_SETCOLORKEYDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      dwFlags DWORD ?
      ; flags
      ckNew DDCOLORKEY <>
      ; new color key
      ddRVal HRESULT ?
      ; return value
      SetColorKey LPDDHALSURFCB_SETCOLORKEY ?
      ; PRIVATE: ptr to callback
    DDHAL_SETCOLORKEYDATA ends
    _DDHAL_SETCOLORKEYDATA typedef DDHAL_SETCOLORKEYDATA
    ;*
    ;* structure for passing information to DDHAL GetBltStatus fn
    ;*
    DDHAL_GETBLTSTATUSDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      dwFlags DWORD ?
      ; flags
      ddRVal HRESULT ?
      ; return value
      GetBltStatus LPDDHALSURFCB_GETBLTSTATUS ?
      ; PRIVATE: ptr to callback
    DDHAL_GETBLTSTATUSDATA ends
    _DDHAL_GETBLTSTATUSDATA typedef DDHAL_GETBLTSTATUSDATA
    ;*
    ;* structure for passing information to DDHAL GetFlipStatus fn
    ;*
    DDHAL_GETFLIPSTATUSDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      dwFlags DWORD ?
      ; flags
      ddRVal HRESULT ?
      ; return value
      GetFlipStatus LPDDHALSURFCB_GETFLIPSTATUS ?
      ; PRIVATE: ptr to callback
    DDHAL_GETFLIPSTATUSDATA ends
    _DDHAL_GETFLIPSTATUSDATA typedef DDHAL_GETFLIPSTATUSDATA
    ;****************************************************************************
    ;*
    ;* DDHAL structures for Palette Object callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL DestroyPalette fn
    ;*
    DDHAL_DESTROYPALETTEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDPalette LPDDRAWI_DDRAWPALETTE_GBL ?
      ; palette struct
      ddRVal HRESULT ?
      ; return value
      DestroyPalette LPDDHALPALCB_DESTROYPALETTE ?
      ; PRIVATE: ptr to callback
    DDHAL_DESTROYPALETTEDATA ends
    _DDHAL_DESTROYPALETTEDATA typedef DDHAL_DESTROYPALETTEDATA
    ;*
    ;* structure for passing information to DDHAL SetEntries fn
    ;*
    DDHAL_SETENTRIESDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDPalette LPDDRAWI_DDRAWPALETTE_GBL ?
      ; palette struct
      dwBase DWORD ?
      ; base palette index
      dwNumEntries DWORD ?
      ; number of palette entries
      lpEntries LPPALETTEENTRY ?
      ; color table
      ddRVal HRESULT ?
      ; return value
      SetEntries LPDDHALPALCB_SETENTRIES ?
      ; PRIVATE: ptr to callback
    DDHAL_SETENTRIESDATA ends
    _DDHAL_SETENTRIESDATA typedef DDHAL_SETENTRIESDATA
    ;****************************************************************************
    ;*
    ;* DDHAL structures for Driver Object callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL CreateSurface fn
    ;*
    DDHAL_CREATESURFACEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurfaceDesc LPDDSURFACEDESC ?
      ; description of surface being created
      lplpSList POINTER ?
      ; list of created surface objects
      dwSCnt DWORD ?
      ; number of surfaces in SList
      ddRVal HRESULT ?
      ; return value
      CreateSurface LPDDHAL_CREATESURFACE ?
      ; PRIVATE: ptr to callback
    DDHAL_CREATESURFACEDATA ends
    _DDHAL_CREATESURFACEDATA typedef DDHAL_CREATESURFACEDATA
    ;*
    ;* structure for passing information to DDHAL CanCreateSurface fn
    ;*
    DDHAL_CANCREATESURFACEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurfaceDesc LPDDSURFACEDESC ?
      ; description of surface being created
      bIsDifferentPixelFormat DWORD ?
      ; pixel format differs from primary surface
      ddRVal HRESULT ?
      ; return value
      CanCreateSurface LPDDHAL_CANCREATESURFACE ?
      ; PRIVATE: ptr to callback
    DDHAL_CANCREATESURFACEDATA ends
    _DDHAL_CANCREATESURFACEDATA typedef DDHAL_CANCREATESURFACEDATA
    ;*
    ;* structure for passing information to DDHAL CreatePalette fn
    ;*
    DDHAL_CREATEPALETTEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDPalette LPDDRAWI_DDRAWPALETTE_GBL ?
      ; ddraw palette struct
      lpColorTable LPPALETTEENTRY ?
      ; colors to go in palette
      ddRVal HRESULT ?
      ; return value
      CreatePalette LPDDHAL_CREATEPALETTE ?
      ; PRIVATE: ptr to callback
      is_excl DWORD ?
      ; process has exclusive mode
    DDHAL_CREATEPALETTEDATA ends
    _DDHAL_CREATEPALETTEDATA typedef DDHAL_CREATEPALETTEDATA
    ;*
    ;* Return if the vertical blank is in progress
    ;*
    DDWAITVB_I_TESTVB equ 80000006h
    ;*
    ;* structure for passing information to DDHAL WaitForVerticalBlank fn
    ;*
    DDHAL_WAITFORVERTICALBLANKDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      dwFlags DWORD ?
      ; flags
      bIsInVB DWORD ?
      ; is in vertical blank
      hEvent XWORD ?
      ; event
      ddRVal HRESULT ?
      ; return value
      WaitForVerticalBlank LPDDHAL_WAITFORVERTICALBLANK ?
      ; PRIVATE: ptr to callback
    DDHAL_WAITFORVERTICALBLANKDATA ends
    _DDHAL_WAITFORVERTICALBLANKDATA typedef DDHAL_WAITFORVERTICALBLANKDATA
    ;*
    ;* structure for passing information to DDHAL DestroyDriver fn
    ;*
    DDHAL_DESTROYDRIVERDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      ddRVal HRESULT ?
      ; return value
      DestroyDriver LPDDHAL_DESTROYDRIVER ?
      ; PRIVATE: ptr to callback
    DDHAL_DESTROYDRIVERDATA ends
    _DDHAL_DESTROYDRIVERDATA typedef DDHAL_DESTROYDRIVERDATA
    ;*
    ;* structure for passing information to DDHAL SetMode fn
    ;*
    DDHAL_SETMODEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      dwModeIndex DWORD ?
      ; new mode
      ddRVal HRESULT ?
      ; return value
      SetMode LPDDHAL_SETMODE ?
      ; PRIVATE: ptr to callback
      inexcl DWORD ?
      ; in exclusive mode
      useRefreshRate DWORD ?
      ; use the refresh rate data in the mode info
    DDHAL_SETMODEDATA ends
    _DDHAL_SETMODEDATA typedef DDHAL_SETMODEDATA
    ;*
    ;* structure for passing information to DDHAL driver SetColorKey fn
    ;*
    DDHAL_DRVSETCOLORKEYDATA struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface struct
      dwFlags DWORD ?
      ; flags
      ckNew DDCOLORKEY <>
      ; new color key
      ddRVal HRESULT ?
      ; return value
      SetColorKey LPDDHAL_SETCOLORKEY ?
      ; PRIVATE: ptr to callback
    DDHAL_DRVSETCOLORKEYDATA ends
    _DDHAL_DRVSETCOLORKEYDATA typedef DDHAL_DRVSETCOLORKEYDATA
    ;*
    ;* structure for passing information to DDHAL GetScanLine fn
    ;*
    DDHAL_GETSCANLINEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      dwScanLine DWORD ?
      ; returned scan line
      ddRVal HRESULT ?
      ; return value
      GetScanLine LPDDHAL_GETSCANLINE ?
      ; PRIVATE: ptr to callback
    DDHAL_GETSCANLINEDATA ends
    _DDHAL_GETSCANLINEDATA typedef DDHAL_GETSCANLINEDATA
    ;*
    ;* structure for passing information to DDHAL SetExclusiveMode fn
    ;*
    DDHAL_SETEXCLUSIVEMODEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      dwEnterExcl DWORD ?
      ; TRUE if entering exclusive mode, FALSE is leaving
      dwReserved DWORD ?
      ; reserved for future use
      ddRVal HRESULT ?
      ; return value
      SetExclusiveMode LPDDHAL_SETEXCLUSIVEMODE ?
      ; PRIVATE: ptr to callback
    DDHAL_SETEXCLUSIVEMODEDATA ends
    _DDHAL_SETEXCLUSIVEMODEDATA typedef DDHAL_SETEXCLUSIVEMODEDATA
    ;*
    ;* structure for passing information to DDHAL FlipToGDISurface fn
    ;*
    DDHAL_FLIPTOGDISURFACEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      dwToGDI DWORD ?
      ; TRUE if flipping to the GDI surface, FALSE if flipping away
      dwReserved DWORD ?
      ; reserved for future use
      ddRVal HRESULT ?
      ; return value
      FlipToGDISurface LPDDHAL_FLIPTOGDISURFACE ?
      ; PRIVATE: ptr to callback
    DDHAL_FLIPTOGDISURFACEDATA ends
    _DDHAL_FLIPTOGDISURFACEDATA typedef DDHAL_FLIPTOGDISURFACEDATA
    ;****************************************************************************
    ;*
    ;* DDHAL structures for VideoPort callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL CanCreateVideoPort fn
    ;*
    DDHAL_CANCREATEVPORTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpDDVideoPortDesc LPDDVIDEOPORTDESC ?
      ddRVal HRESULT ?
      ; return value
      CanCreateVideoPort LPDDHALVPORTCB_CANCREATEVIDEOPORT ?
      ; PRIVATE: ptr to callback
    DDHAL_CANCREATEVPORTDATA ends
    _DDHAL_CANCREATEVPORTDATA typedef DDHAL_CANCREATEVPORTDATA
    ;*
    ;* structure for passing information to DDHAL CreateVideoPort fn
    ;*
    DDHAL_CREATEVPORTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpDDVideoPortDesc LPDDVIDEOPORTDESC ?
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port created
      ddRVal HRESULT ?
      ; return value
      CreateVideoPort LPDDHALVPORTCB_CREATEVIDEOPORT ?
      ; PRIVATE: ptr to callback
    DDHAL_CREATEVPORTDATA ends
    _DDHAL_CREATEVPORTDATA typedef DDHAL_CREATEVPORTDATA
    ;*
    ;* structure for passing information to DDHAL FlipVideoPort fn
    ;*
    DDHAL_FLIPVPORTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      lpSurfCurr LPDDRAWI_DDRAWSURFACE_LCL ?
      ; current surface
      lpSurfTarg LPDDRAWI_DDRAWSURFACE_LCL ?
      ; target surface
      ddRVal HRESULT ?
      ; return value
      FlipVideoPort LPDDHALVPORTCB_FLIP ?
      ; PRIVATE: ptr to callback
    DDHAL_FLIPVPORTDATA ends
    _DDHAL_FLIPVPORTDATA typedef DDHAL_FLIPVPORTDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortBandwidth fn
    ;*
    DDHAL_GETVPORTBANDWIDTHDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      lpddpfFormat LPDDPIXELFORMAT ?
      ; Format for bandwidth
      dwWidth DWORD ?
      dwHeight DWORD ?
      dwFlags DWORD ?
      ; Prescale factor for bandwidth
      lpBandwidth LPDDVIDEOPORTBANDWIDTH ?
      ; Returned bandwidth parameters
      ddRVal HRESULT ?
      ; return value
      GetVideoPortBandwidth LPDDHALVPORTCB_GETBANDWIDTH ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTBANDWIDTHDATA ends
    _DDHAL_GETVPORTBANDWIDTHDATA typedef DDHAL_GETVPORTBANDWIDTHDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortInputFormats fn
    ;*
    DDHAL_GETVPORTINPUTFORMATDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwFlags DWORD ?
      ; VBI, regular, or both
      lpddpfFormat LPDDPIXELFORMAT ?
      ; Array of formats
      dwNumFormats DWORD ?
      ; # of formats in array
      ddRVal HRESULT ?
      ; return value
      GetVideoPortInputFormats LPDDHALVPORTCB_GETINPUTFORMATS ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTINPUTFORMATDATA ends
    _DDHAL_GETVPORTINPUTFORMATDATA typedef DDHAL_GETVPORTINPUTFORMATDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortOutputFormats fn
    ;*
    DDHAL_GETVPORTOUTPUTFORMATDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwFlags DWORD ?
      ; VBI, regular, or both
      lpddpfInputFormat LPDDPIXELFORMAT ?
      ; Input format
      lpddpfOutputFormats LPDDPIXELFORMAT ?
      ; Array of output formats
      dwNumFormats DWORD ?
      ; # of formats in array
      ddRVal HRESULT ?
      ; return value
      GetVideoPortOutputFormats LPDDHALVPORTCB_GETOUTPUTFORMATS ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTOUTPUTFORMATDATA ends
    _DDHAL_GETVPORTOUTPUTFORMATDATA typedef DDHAL_GETVPORTOUTPUTFORMATDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortField fn
    ;*
    DDHAL_GETVPORTFIELDDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      bField DWORD ?
      ; TRUE if even
      ddRVal HRESULT ?
      ; return value
      GetVideoPortField LPDDHALVPORTCB_GETFIELD ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTFIELDDATA ends
    _DDHAL_GETVPORTFIELDDATA typedef DDHAL_GETVPORTFIELDDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortLine fn
    ;*
    DDHAL_GETVPORTLINEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwLine DWORD ?
      ; Current line counter
      ddRVal HRESULT ?
      ; return value
      GetVideoPortLine LPDDHALVPORTCB_GETLINE ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTLINEDATA ends
    _DDHAL_GETVPORTLINEDATA typedef DDHAL_GETVPORTLINEDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortConnectInfo fn
    ;*
    DDHAL_GETVPORTCONNECTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      dwPortId DWORD ?
      ; ID of desired video port
      lpConnect LPDDVIDEOPORTCONNECT ?
      ; Array of DDVIDEOPORTCONNECT structures
      dwNumEntries DWORD ?
      ; # of structures in array
      ddRVal HRESULT ?
      ; return value
      GetVideoPortConnectInfo LPDDHALVPORTCB_GETVPORTCONNECT ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTCONNECTDATA ends
    _DDHAL_GETVPORTCONNECTDATA typedef DDHAL_GETVPORTCONNECTDATA
    ;*
    ;* structure for passing information to DDHAL DestroyVideoPort fn
    ;*
    DDHAL_DESTROYVPORTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      ddRVal HRESULT ?
      ; return value
      DestroyVideoPort LPDDHALVPORTCB_DESTROYVPORT ?
      ; PRIVATE: ptr to callback
    DDHAL_DESTROYVPORTDATA ends
    _DDHAL_DESTROYVPORTDATA typedef DDHAL_DESTROYVPORTDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoPortFlipStatus fn
    ;*
    DDHAL_GETVPORTFLIPSTATUSDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      fpSurface FLATPTR ?
      ; surface struct
      ddRVal HRESULT ?
      ; return value
      GetVideoPortFlipStatus LPDDHALVPORTCB_GETFLIPSTATUS ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTFLIPSTATUSDATA ends
    _DDHAL_GETVPORTFLIPSTATUSDATA typedef DDHAL_GETVPORTFLIPSTATUSDATA
    ;*
    ;* structure for passing information to DDHAL UpdateVideoPort fn
    ;*
    DDHAL_UPDATEVPORTDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      lplpDDSurface POINTER ?
      ; surface struct
      lplpDDVBISurface POINTER ?
      ; VBI surface structure
      lpVideoInfo LPDDVIDEOPORTINFO ?
      ; Video information
      dwFlags DWORD ?
      ; DDRAWI_VPORTSTART, DDRAWI_VPORTSTOP, DDRAWI_VPORTUPDATE
      dwNumAutoflip DWORD ?
      ; # of autoflip surfaces. If > 1, lpDDSurface and lpDDVBISurface are arrays.
      dwNumVBIAutoflip DWORD ?
      ; # of autoflip surfaces. If > 1, lpDDSurface and lpDDVBISurface are arrays.
      ddRVal HRESULT ?
      ; return value
      UpdateVideoPort LPDDHALVPORTCB_UPDATE ?
      ; PRIVATE: ptr to callback
    DDHAL_UPDATEVPORTDATA ends
    _DDHAL_UPDATEVPORTDATA typedef DDHAL_UPDATEVPORTDATA
    DDRAWI_VPORTSTART equ 0001h
    DDRAWI_VPORTSTOP equ 0002h
    DDRAWI_VPORTUPDATE equ 0003h
    ;*
    ;* structure for passing information to DDHAL WaitForVideoPortSync fn
    ;*
    DDHAL_WAITFORVPORTSYNCDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwFlags DWORD ?
      ; DDVPEVENT_XXXX
      dwLine DWORD ?
      dwTimeOut DWORD ?
      ; Max time to wait before returning
      ddRVal HRESULT ?
      ; return value
      WaitForVideoPortSync LPDDHALVPORTCB_WAITFORSYNC ?
      ; PRIVATE: ptr to callback
    DDHAL_WAITFORVPORTSYNCDATA ends
    _DDHAL_WAITFORVPORTSYNCDATA typedef DDHAL_WAITFORVPORTSYNCDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoSignalStatus fn
    ;*
    DDHAL_GETVPORTSIGNALDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwStatus DWORD ?
      ; Video signal status
      ddRVal HRESULT ?
      ; return value
      GetVideoSignalStatus LPDDHALVPORTCB_GETSIGNALSTATUS ?
      ; PRIVATE: ptr to callback
    DDHAL_GETVPORTSIGNALDATA ends
    _DDHAL_GETVPORTSIGNALDATA typedef DDHAL_GETVPORTSIGNALDATA
    ;*
    ;* structure for passing information to DDHAL GetVideoSignalStatus fn
    ;*
    DDHAL_VPORTCOLORDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwFlags DWORD ?
      ; Video signal status
      lpColorData LPDDCOLORCONTROL ?
      ddRVal HRESULT ?
      ; return value
      ColorControl LPDDHALVPORTCB_COLORCONTROL ?
      ; PRIVATE: ptr to callback
    DDHAL_VPORTCOLORDATA ends
    _DDHAL_VPORTCOLORDATA typedef DDHAL_VPORTCOLORDATA
    DDRAWI_VPORTGETCOLOR equ 0001h
    DDRAWI_VPORTSETCOLOR equ 0002h
    ;****************************************************************************
    ;*
    ;* DDHAL structures for Color Control callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL ColorControl fn
    ;*
    DDHAL_COLORCONTROLDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; surface
      lpColorData LPDDCOLORCONTROL ?
      ; color control information
      dwFlags DWORD ?
      ; DDRAWI_GETCOLOR/DDRAWI_SETCOLOR
      ddRVal HRESULT ?
      ; return value
      ColorControl LPDDHALCOLORCB_COLORCONTROL ?
      ; PRIVATE: ptr to callback
    DDHAL_COLORCONTROLDATA ends
    _DDHAL_COLORCONTROLDATA typedef DDHAL_COLORCONTROLDATA
    DDRAWI_GETCOLOR equ 0001h
    DDRAWI_SETCOLOR equ 0002h
    ;****************************************************************************
    ;*
    ;* DDHAL structure for GetDriverData callback
    ;*
    ;***************************************************************************
    DDHAL_GETDRIVERINFODATA struct
      ; Input fields filled in by DirectDraw
      dwSize DWORD ?
      ; Size of this structure
      dwFlags DWORD ?
      ; Flags
      guidInfo GUID <>
      ; GUID that DirectX is querying for
      dwExpectedSize DWORD ?
      ; Size of callbacks structure expected by DirectDraw.
      lpvData POINTER ?
      ; Buffer that will receive the requested data
      ; Output fields filled in by driver
      dwActualSize DWORD ?
      ; Size of callbacks structure expected by driver
      ddRVal HRESULT ?
      ; Return value from driver
      ; Input field: Context information for driver
      ; On Win95, this is the dwReserved3 field of the DIRECTDRAW_GBL
      ; On NT, this is the hDD field of DIRECTDRAW_GBL
      dwContext XWORD ?
      ; Context Information
    DDHAL_GETDRIVERINFODATA ends
    _DDHAL_GETDRIVERINFODATA typedef DDHAL_GETDRIVERINFODATA
    ;****************************************************************************
    ;*
    ;* DDHAL structure for misc. driver callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL GetAvailDriverMemory fn
    ;*
    DDHAL_GETAVAILDRIVERMEMORYDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      DDSCaps DDSCAPS <>
      ; caps for type of surface memory
      dwTotal DWORD ?
      ; total memory for this kind of surface
      dwFree DWORD ?
      ; free memory for this kind of surface
      ddRVal HRESULT ?
      ; return value
      GetAvailDriverMemory LPDDHAL_GETAVAILDRIVERMEMORY ?
      ; PRIVATE: ptr to callback
      ddsCapsEx DDSCAPSEX <>
      ; Added in V6. Driver should check DDVERSION info
      ; to see if this field is present.
    DDHAL_GETAVAILDRIVERMEMORYDATA ends
    _DDHAL_GETAVAILDRIVERMEMORYDATA typedef DDHAL_GETAVAILDRIVERMEMORYDATA
    ;*
    ;* structure for passing information to DDHEL UpdateNonLocalHeap
    ;*
    DDHAL_UPDATENONLOCALHEAPDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_GBL ?
      ; driver struct
      dwHeap DWORD ?
      ; heap index
      fpGARTLin FLATPTR ?
      ; linear GART address of start of heap
      fpGARTDev FLATPTR ?
      ; high physical GART address of start of heap
      ulPolicyMaxBytes XWORD ?
      ; maximum amount of AGP memory to use
      ddRVal HRESULT ?
      ; return value
      UpdateNonLocalHeap LPDDHAL_UPDATENONLOCALHEAP ?
      ; PRIVATE: ptr to callback
    DDHAL_UPDATENONLOCALHEAPDATA ends
    _DDHAL_UPDATENONLOCALHEAPDATA typedef DDHAL_UPDATENONLOCALHEAPDATA
    ;*
    ;* Heap Alignment Data Structures
    ;*
    DDHAL_GETHEAPALIGNMENTDATA struct
      dwInstance XWORD ?
      ; driver context as returned from 32-bit driver init routine
      dwHeap DWORD ?
      ; heap index passed by DirectDraw
      ddRVal HRESULT ?
      ; return value
      GetHeapAlignment LPDDHAL_GETHEAPALIGNMENT ?
      ; PRIVATE: ptr to callback.
      Alignment HEAPALIGNMENT <>
      ; Filled in by driver. Defined in dmemmgr.h
    DDHAL_GETHEAPALIGNMENTDATA ends
    _DDHAL_GETHEAPALIGNMENTDATA typedef DDHAL_GETHEAPALIGNMENTDATA
    ;*
    ;* These are the only caps you can set in DDHAL_GETHEAPALIGNMENTDATA.Alignment.ddsCaps.
    ;* Any other caps will be rejected by DirectDraw.
    ;*
    DDHAL_ALIGNVALIDCAPS equ <(DDSCAPS_OFFSCREENPLAIN or DDSCAPS_EXECUTEBUFFER or DDSCAPS_OVERLAY or DDSCAPS_TEXTURE or DDSCAPS_ZBUFFER or DDSCAPS_ALPHA or DDSCAPS_FLIP)>
    ;*
    ;* Note that GetSysmemBltStatus uses the same parameter block as GetBltStatus,
    ;* namely DDHAL_GETBLTSTATUSDATA
    ;*
    DDHAL_CREATESURFACEEXDATA struct
      dwFlags DWORD ?
      ; Currently always 0 and not used
      lpDDLcl LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpDDSLcl LPDDRAWI_DDRAWSURFACE_LCL ?
      ; list of created surface objects
      ddRVal HRESULT ?
      ; return value
    DDHAL_CREATESURFACEEXDATA ends
    _DDHAL_CREATESURFACEEXDATA typedef DDHAL_CREATESURFACEEXDATA
    DDHAL_GETDRIVERSTATEDATA struct
      dwFlags DWORD ?
      ; Flags to indicate the data
      ; required
      union
        ; LPDDRAWI_DIRECTDRAW_GBL     lpDD;           // driver struct
        dwhContext XWORD ?
        ; d3d context
      ends
      lpdwStates LPDWORD ?
      ; ptr to the state data
      ; to be filled in by the
      ; driver
      dwLength DWORD ?
      ddRVal HRESULT ?
      ; return value
    DDHAL_GETDRIVERSTATEDATA ends
    _DDHAL_GETDRIVERSTATEDATA typedef DDHAL_GETDRIVERSTATEDATA
    DDHAL_DESTROYDDLOCALDATA struct
      dwFlags DWORD ?
      pDDLcl LPDDRAWI_DIRECTDRAW_LCL ?
      ddRVal HRESULT ?
    DDHAL_DESTROYDDLOCALDATA ends
    _DDHAL_DESTROYDDLOCALDATA typedef DDHAL_DESTROYDDLOCALDATA
    ;****************************************************************************
    ;*
    ;* DDHAL structure for kernel callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL SyncSurfaceData fn
    ;*
    DDHAL_SYNCSURFACEDATA struct
      dwSize DWORD ?
      ; Size of this structure
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpDDSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; Surface to sync with
      dwSurfaceOffset DWORD ?
      ; Offset in frame buffer of surface
      fpLockPtr XWORD ?
      ; Surface lock ptr
      lPitch SDWORD ?
      ; Surface pitch
      dwOverlayOffset DWORD ?
      ; Added to dwSurfaceOffset for origin, clipping, etc.
      dwOverlaySrcWidth DWORD ?
      ; Src width of overlay
      dwOverlaySrcHeight DWORD ?
      ; Src height of overlay
      dwOverlayDestWidth DWORD ?
      ; Dest width of overlay
      dwOverlayDestHeight DWORD ?
      ; Dest height of overlay
      dwDriverReserved1 XWORD ?
      ; Reserved for the HAL
      dwDriverReserved2 XWORD ?
      ; Reserved for the HAL
      dwDriverReserved3 XWORD ?
      ; Reserved for the HAL
      ddRVal HRESULT ?
    DDHAL_SYNCSURFACEDATA ends
    _DDHAL_SYNCSURFACEDATA typedef DDHAL_SYNCSURFACEDATA
    ;*
    ;* structure for passing information to DDHAL SyncVideoPortData fn
    ;*
    DDHAL_SYNCVIDEOPORTDATA struct
      dwSize DWORD ?
      ; Size of this structure
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      ; driver struct
      lpVideoPort LPDDRAWI_DDVIDEOPORT_LCL ?
      ; Video port object
      dwOriginOffset DWORD ?
      ; Start address relative to surface
      dwHeight DWORD ?
      ; Height of total video region (per field)
      dwVBIHeight DWORD ?
      ; Height of VBI region (per field)
      dwDriverReserved1 XWORD ?
      ; Reserved for the HAL
      dwDriverReserved2 XWORD ?
      ; Reserved for the HAL
      dwDriverReserved3 XWORD ?
      ; Reserved for the HAL
      ddRVal HRESULT ?
    DDHAL_SYNCVIDEOPORTDATA ends
    _DDHAL_SYNCVIDEOPORTDATA typedef DDHAL_SYNCVIDEOPORTDATA
    ;****************************************************************************
    ;*
    ;* DDHAL structure for motion comp callbacks
    ;*
    ;***************************************************************************
    ;*
    ;* structure for passing information to DDHAL GetMoCompGuids
    ;*
    DDHAL_GETMOCOMPGUIDSDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      dwNumGuids DWORD ?
      lpGuids LPGUID ?
      ddRVal HRESULT ?
      GetMoCompGuids LPDDHALMOCOMPCB_GETGUIDS ?
    DDHAL_GETMOCOMPGUIDSDATA ends
    _DDHAL_GETMOCOMPGUIDSDATA typedef DDHAL_GETMOCOMPGUIDSDATA
    ;*
    ;* structure for passing information to DDHAL GetMoCompFormats
    ;*
    DDHAL_GETMOCOMPFORMATSDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpGuid LPGUID ?
      dwNumFormats DWORD ?
      lpFormats LPDDPIXELFORMAT ?
      ddRVal HRESULT ?
      GetMoCompFormats LPDDHALMOCOMPCB_GETFORMATS ?
    DDHAL_GETMOCOMPFORMATSDATA ends
    _DDHAL_GETMOCOMPFORMATSDATA typedef DDHAL_GETMOCOMPFORMATSDATA
    ;*
    ;* structure for passing information to DDHAL CreateMoComp
    ;*
    DDHAL_CREATEMOCOMPDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpMoComp LPDDRAWI_DDMOTIONCOMP_LCL ?
      lpGuid LPGUID ?
      dwUncompWidth DWORD ?
      dwUncompHeight DWORD ?
      ddUncompPixelFormat DDPIXELFORMAT <>
      lpData POINTER ?
      dwDataSize DWORD ?
      ddRVal HRESULT ?
      CreateMoComp LPDDHALMOCOMPCB_CREATE ?
    DDHAL_CREATEMOCOMPDATA ends
    _DDHAL_CREATEMOCOMPDATA typedef DDHAL_CREATEMOCOMPDATA
    ;*
    ;* structure for passing information to DDHAL GetMoCompBuffInfo
    ;*
    DDMCCOMPBUFFERINFO struct
      dwSize DWORD ?
      ; [in]   size of the struct
      dwNumCompBuffers DWORD ?
      ; [out]  number of buffers required for compressed data
      dwWidthToCreate DWORD ?
      ; [out]    Width of surface to create
      dwHeightToCreate DWORD ?
      ; [out]    Height of surface to create
      dwBytesToAllocate DWORD ?
      ; [out]    Total number of bytes used by each surface
      ddCompCaps DDSCAPS2 <>
      ; [out]    caps to create surfaces to store compressed data
      ddPixelFormat DDPIXELFORMAT <>
      ; [out]  format to create surfaces to store compressed data
    DDMCCOMPBUFFERINFO ends
    _DDMCCOMPBUFFERINFO typedef DDMCCOMPBUFFERINFO
    LPDDMCCOMPBUFFERINFO typedef ptr DDMCCOMPBUFFERINFO
    DDHAL_GETMOCOMPCOMPBUFFDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpGuid LPGUID ?
      dwWidth DWORD ?
      ; [in]   width of uncompressed data
      dwHeight DWORD ?
      ; [in]   height of uncompressed data
      ddPixelFormat DDPIXELFORMAT <>
      ; [in]   pixel-format of uncompressed data
      dwNumTypesCompBuffs DWORD ?
      ; [in/out] number of memory types required for comp buffers
      lpCompBuffInfo LPDDMCCOMPBUFFERINFO ?
      ; [in]   driver supplied info regarding comp buffers (allocated by client)
      ddRVal HRESULT ?
      ; [out]
      GetMoCompBuffInfo LPDDHALMOCOMPCB_GETCOMPBUFFINFO ?
    DDHAL_GETMOCOMPCOMPBUFFDATA ends
    _DDHAL_GETMOCOMPCOMPBUFFDATA typedef DDHAL_GETMOCOMPCOMPBUFFDATA
    ;*
    ;* structure for passing information to DDHAL GetMoCompBuffInfo
    ;*
    DDHAL_GETINTERNALMOCOMPDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpGuid LPGUID ?
      dwWidth DWORD ?
      ; [in]   width of uncompressed data
      dwHeight DWORD ?
      ; [in]   height of uncompressed data
      ddPixelFormat DDPIXELFORMAT <>
      ; [in]   pixel-format of uncompressed data
      dwScratchMemAlloc DWORD ?
      ; [out]  amount of scratch memory will the hal allocate for its private use
      ddRVal HRESULT ?
      ; [out]
      GetInternalMoCompInfo LPDDHALMOCOMPCB_GETINTERNALINFO ?
    DDHAL_GETINTERNALMOCOMPDATA ends
    _DDHAL_GETINTERNALMOCOMPDATA typedef DDHAL_GETINTERNALMOCOMPDATA
    ;*
    ;* structure for passing information to DDHAL BeginMoCompFrame
    ;*
    DDHAL_BEGINMOCOMPFRAMEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpMoComp LPDDRAWI_DDMOTIONCOMP_LCL ?
      lpDestSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; [in]  destination buffer in which to decoding this frame
      dwInputDataSize DWORD ?
      ; [in]  size of other misc input data to begin frame
      lpInputData POINTER ?
      ; [in]  pointer to misc input data
      dwOutputDataSize DWORD ?
      ; [in]  size of other misc output data to begin frame
      lpOutputData POINTER ?
      ; [in]  pointer to output misc data (allocated by client)
      ddRVal HRESULT ?
      ; [out]
      BeginMoCompFrame LPDDHALMOCOMPCB_BEGINFRAME ?
    DDHAL_BEGINMOCOMPFRAMEDATA ends
    _DDHAL_BEGINMOCOMPFRAMEDATA typedef DDHAL_BEGINMOCOMPFRAMEDATA
    ;*
    ;* structure for passing information to DDHAL EndMoCompFrame
    ;*
    DDHAL_ENDMOCOMPFRAMEDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpMoComp LPDDRAWI_DDMOTIONCOMP_LCL ?
      lpInputData POINTER ?
      dwInputDataSize DWORD ?
      ddRVal HRESULT ?
      EndMoCompFrame LPDDHALMOCOMPCB_ENDFRAME ?
    DDHAL_ENDMOCOMPFRAMEDATA ends
    _DDHAL_ENDMOCOMPFRAMEDATA typedef DDHAL_ENDMOCOMPFRAMEDATA
    ;*
    ;* structure for passing information to DDHAL RenderMoComp
    ;*
    DDMCBUFFERINFO struct
      dwSize DWORD ?
      ; [in]    size of the struct
      lpCompSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; [in]    pointer to buffer containing compressed data
      dwDataOffset DWORD ?
      ; [in]    offset of relevant data from the beginning of buffer
      dwDataSize DWORD ?
      ; [in]    size of relevant data
      lpPrivate POINTER ?
      ; Reserved for DirectDraw;
    DDMCBUFFERINFO ends
    _DDMCBUFFERINFO typedef DDMCBUFFERINFO
    LPDDMCBUFFERINFO typedef ptr DDMCBUFFERINFO
    DDHAL_RENDERMOCOMPDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpMoComp LPDDRAWI_DDMOTIONCOMP_LCL ?
      dwNumBuffers DWORD ?
      ; [in]  Number of entries in the lpMacroBlockInfo array
      lpBufferInfo LPDDMCBUFFERINFO ?
      ; [in]  Surfaces containing macro block info
      dwFunction DWORD ?
      ; [in]  Function
      lpInputData POINTER ?
      dwInputDataSize DWORD ?
      lpOutputData POINTER ?
      dwOutputDataSize DWORD ?
      ddRVal HRESULT ?
      ; [out]
      RenderMoComp LPDDHALMOCOMPCB_RENDER ?
    DDHAL_RENDERMOCOMPDATA ends
    _DDHAL_RENDERMOCOMPDATA typedef DDHAL_RENDERMOCOMPDATA
    ;*
    ;* structure for passing information to DDHAL QueryMoCompStatus
    ;*
    DDHAL_QUERYMOCOMPSTATUSDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpMoComp LPDDRAWI_DDMOTIONCOMP_LCL ?
      lpSurface LPDDRAWI_DDRAWSURFACE_LCL ?
      ; [in]  Surface being queried
      dwFlags DWORD ?
      ; [in]  DDMCQUERY_XXX falgs
      ddRVal HRESULT ?
      ; [out]
      QueryMoCompStatus LPDDHALMOCOMPCB_QUERYSTATUS ?
    DDHAL_QUERYMOCOMPSTATUSDATA ends
    _DDHAL_QUERYMOCOMPSTATUSDATA typedef DDHAL_QUERYMOCOMPSTATUSDATA
    DDMCQUERY_READ equ 00000001h
    ;*
    ;* structure for passing information to DDHAL DestroyVideo
    ;*
    DDHAL_DESTROYMOCOMPDATA struct
      lpDD LPDDRAWI_DIRECTDRAW_LCL ?
      lpMoComp LPDDRAWI_DDMOTIONCOMP_LCL ?
      ddRVal HRESULT ?
      DestroyMoComp LPDDHALMOCOMPCB_DESTROY ?
    DDHAL_DESTROYMOCOMPDATA ends
    _DDHAL_DESTROYMOCOMPDATA typedef DDHAL_DESTROYMOCOMPDATA
    ifdef __cplusplus
      ;[...]
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
