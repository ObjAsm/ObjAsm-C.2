;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3d9.h', last modified: 19/04/2018 09:46
;Creation parameters: 

ifndef _D3D9_H_
  _D3D9_H_ equ <>
  ifndef DIRECT3D_VERSION
    DIRECT3D_VERSION equ 0900h
  endif
  if (DIRECT3D_VERSION ge 0900h)
    include winapifamily.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef D3D_DEBUG_INFO
        ;[...]
      else
        D3D_SDK_VERSION equ 32
        D3D9b_SDK_VERSION equ 31
      endif
      include stdlib.inc
      COM_NO_WINDOWS_H equ <>
      include objbase.inc
      include windows.inc
      if  not Defined(HMONITOR_DECLARED) and (WINVER lt 0500h)
        HMONITOR_DECLARED equ <>
        DECLARE_HANDLE HMONITOR
      endif
      D3DAPI equ <WINAPI>
      if Defined(_WIN32) and  not Defined(_NO_COM)
        DEFINE_GUID IID_IDirect3D9, 81bdcbcah, 64d4h, 426dh, 0aeh, 8dh, 0adh, 1h, 47h, 0f4h, 27h, 5ch
        DEFINE_GUID IID_IDirect3DDevice9, 0d0223b96h, 0bf7ah, 43fdh, 92h, 0bdh, 0a4h, 3bh, 0dh, 82h, 0b9h, 0ebh
        DEFINE_GUID IID_IDirect3DResource9, 5eec05dh, 8f7dh, 4362h, 0b9h, 99h, 0d1h, 0bah, 0f3h, 57h, 0c7h, 4h
        DEFINE_GUID IID_IDirect3DBaseTexture9, 580ca87eh, 1d3ch, 4d54h, 99h, 1dh, 0b7h, 0d3h, 0e3h, 0c2h, 98h, 0ceh
        DEFINE_GUID IID_IDirect3DTexture9, 85c31227h, 3de5h, 4f00h, 9bh, 3ah, 0f1h, 1ah, 0c3h, 8ch, 18h, 0b5h
        DEFINE_GUID IID_IDirect3DCubeTexture9, 0fff32f81h, 0d953h, 473ah, 92h, 23h, 93h, 0d6h, 52h, 0abh, 0a9h, 3fh
        DEFINE_GUID IID_IDirect3DVolumeTexture9, 2518526ch, 0e789h, 4111h, 0a7h, 0b9h, 47h, 0efh, 32h, 8dh, 13h, 0e6h
        DEFINE_GUID IID_IDirect3DVertexBuffer9, 0b64bb1b5h, 0fd70h, 4df6h, 0bfh, 91h, 19h, 0d0h, 0a1h, 24h, 55h, 0e3h
        DEFINE_GUID IID_IDirect3DIndexBuffer9, 7c9dd65eh, 0d3f7h, 4529h, 0ach, 0eeh, 78h, 58h, 30h, 0ach, 0deh, 35h
        DEFINE_GUID IID_IDirect3DSurface9, 0cfbaf3ah, 9ff6h, 429ah, 99h, 0b3h, 0a2h, 79h, 6ah, 0f8h, 0b8h, 9bh
        DEFINE_GUID IID_IDirect3DVolume9, 24f416e6h, 1f67h, 4aa7h, 0b8h, 8eh, 0d3h, 3fh, 6fh, 31h, 28h, 0a1h
        DEFINE_GUID IID_IDirect3DSwapChain9, 794950f2h, 0adfch, 458ah, 90h, 5eh, 10h, 0a1h, 0bh, 0bh, 50h, 3bh
        DEFINE_GUID IID_IDirect3DVertexDeclaration9, 0dd13c59ch, 36fah, 4098h, 0a8h, 0fbh, 0c7h, 0edh, 39h, 0dch, 85h, 46h
        DEFINE_GUID IID_IDirect3DVertexShader9, 0efc5557eh, 6265h, 4613h, 8ah, 94h, 43h, 85h, 78h, 89h, 0ebh, 36h
        DEFINE_GUID IID_IDirect3DPixelShader9, 6d3bdbdch, 5b02h, 4415h, 0b8h, 52h, 0ceh, 5eh, 8bh, 0cch, 0b2h, 89h
        DEFINE_GUID IID_IDirect3DStateBlock9, 0b07c4fe5h, 310dh, 4ba8h, 0a2h, 3ch, 4fh, 0fh, 20h, 6fh, 21h, 8bh
        DEFINE_GUID IID_IDirect3DQuery9, 0d9771460h, 0a695h, 4f26h, 0bbh, 0d3h, 27h, 0b8h, 40h, 0b5h, 41h, 0cch
        DEFINE_GUID IID_HelperName, 0e4a36723h, 0fdfeh, 4b22h, 0b1h, 46h, 3ch, 4h, 0c0h, 7fh, 4ch, 0c8h
        if  not Defined(D3D_DISABLE_9EX)
          DEFINE_GUID IID_IDirect3D9Ex, 02177241h, 69FCh, 400Ch, 8Fh, 0F1h, 93h, 0A4h, 4Dh, 0F6h, 86h, 1Dh
          DEFINE_GUID IID_IDirect3DDevice9Ex, 0b18b10ceh, 2649h, 405ah, 87h, 0fh, 95h, 0f7h, 77h, 0d4h, 31h, 3ah
          DEFINE_GUID IID_IDirect3DSwapChain9Ex, 91886cafh, 1c3dh, 4d2eh, 0a0h, 0abh, 3eh, 4ch, 7dh, 8dh, 33h, 3h
          DEFINE_GUID IID_IDirect3D9ExOverlayExtension, 187aeb13h, 0aaf5h, 4c59h, 87h, 6dh, 0e0h, 59h, 8h, 8ch, 0dh, 0f8h
          DEFINE_GUID IID_IDirect3DDevice9Video, 26dc4561h, 0a1eeh, 4ae7h, 96h, 0dah, 11h, 8ah, 36h, 0c0h, 0ech, 95h
          DEFINE_GUID IID_IDirect3DAuthenticatedChannel9, 0ff24beeeh, 0da21h, 4bebh, 98h, 0b5h, 0d2h, 0f8h, 99h, 0f9h, 8ah, 0f9h
          DEFINE_GUID IID_IDirect3DCryptoSession9, 0fa0ab799h, 7a9ch, 48cah, 8ch, 5bh, 23h, 7eh, 71h, 0a5h, 44h, 34h
        endif
      endif
      ifdef __cplusplus
        ;[...]
      endif
      ;IDirect3D9 typedef IDirect3D9
      
      ;IDirect3DDevice9 typedef IDirect3DDevice9
      
      ;IDirect3DStateBlock9 typedef IDirect3DStateBlock9
      
      ;IDirect3DVertexDeclaration9 typedef IDirect3DVertexDeclaration9
      
      ;IDirect3DVertexShader9 typedef IDirect3DVertexShader9
      
      ;IDirect3DPixelShader9 typedef IDirect3DPixelShader9
      
      ;IDirect3DResource9 typedef IDirect3DResource9
      
      ;IDirect3DBaseTexture9 typedef IDirect3DBaseTexture9
      
      ;IDirect3DTexture9 typedef IDirect3DTexture9
      
      ;IDirect3DVolumeTexture9 typedef IDirect3DVolumeTexture9
      
      ;IDirect3DCubeTexture9 typedef IDirect3DCubeTexture9
      
      ;IDirect3DVertexBuffer9 typedef IDirect3DVertexBuffer9
      
      ;IDirect3DIndexBuffer9 typedef IDirect3DIndexBuffer9
      
      ;IDirect3DSurface9 typedef IDirect3DSurface9
      
      ;IDirect3DVolume9 typedef IDirect3DVolume9
      
      ;IDirect3DSwapChain9 typedef IDirect3DSwapChain9
      
      ;IDirect3DQuery9 typedef IDirect3DQuery9
      
      if  not Defined(D3D_DISABLE_9EX)
        ;IDirect3D9Ex typedef IDirect3D9Ex
        
        ;IDirect3DDevice9Ex typedef IDirect3DDevice9Ex
        
        ;IDirect3DSwapChain9Ex typedef IDirect3DSwapChain9Ex
        
        ;IDirect3D9ExOverlayExtension typedef IDirect3D9ExOverlayExtension
        
        ;IDirect3DDevice9Video typedef IDirect3DDevice9Video
        
        ;IDirect3DAuthenticatedChannel9 typedef IDirect3DAuthenticatedChannel9
        
        ;IDirect3DCryptoSession9 typedef IDirect3DCryptoSession9
        
      endif
      include d3d9types.inc
      include d3d9caps.inc
      ifdef __cplusplus
        ;[...]
      endif
      Direct3DCreate9 proto WIN_STD_CALL_CONV :UINT
      D3DPERF_BeginEvent proto WIN_STD_CALL_CONV :D3DCOLOR, :LPCWSTR
      D3DPERF_EndEvent proto WIN_STD_CALL_CONV
      D3DPERF_SetMarker proto WIN_STD_CALL_CONV :D3DCOLOR, :LPCWSTR
      D3DPERF_SetRegion proto WIN_STD_CALL_CONV :D3DCOLOR, :LPCWSTR
      D3DPERF_QueryRepeatFrame proto WIN_STD_CALL_CONV
      D3DPERF_SetOptions proto WIN_STD_CALL_CONV :DWORD
      D3DPERF_GetStatus proto WIN_STD_CALL_CONV
      INTERFACE equ <IDirect3D9>
      DECLARE_INTERFACE_ IDirect3D9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD RegisterSoftwareDevice, :ptr THIS_
        STD_METHOD GetAdapterCount, :THIS_
        STD_METHOD GetAdapterIdentifier, :THIS_, :DWORD, :ptr D3DADAPTER_IDENTIFIER9
        STD_METHOD GetAdapterModeCount, :THIS_, :D3DFORMAT
        STD_METHOD EnumAdapterModes, :THIS_, :D3DFORMAT, :UINT, :ptr D3DDISPLAYMODE
        STD_METHOD GetAdapterDisplayMode, :THIS_, :ptr D3DDISPLAYMODE
        STD_METHOD CheckDeviceType, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :D3DFORMAT, :BOOL
        STD_METHOD CheckDeviceFormat, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :DWORD, :D3DRESOURCETYPE, :D3DFORMAT
        STD_METHOD CheckDeviceMultiSampleType, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :BOOL, :D3DMULTISAMPLE_TYPE, :ptr DWORD
        STD_METHOD CheckDepthStencilMatch, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :D3DFORMAT, :D3DFORMAT
        STD_METHOD CheckDeviceFormatConversion, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :D3DFORMAT
        STD_METHOD GetDeviceCaps, :THIS_, :D3DDEVTYPE, :ptr D3DCAPS9
        STD_METHOD GetAdapterMonitor, :THIS_
        STD_METHOD CreateDevice, :THIS_, :D3DDEVTYPE, :HWND, :DWORD, :ptr D3DPRESENT_PARAMETERS, :ptr ptr IDirect3DDevice9
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3D9 typedef ptr IDirect3D9
      PDIRECT3D9 typedef ptr IDirect3D9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3D9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3D9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3D9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3D9_RegisterSoftwareDevice macro p, a
          exitm <(p) - lpVtbl - RegisterSoftwareDevice (p, a)>
        endm
        IDirect3D9_GetAdapterCount macro p
          exitm <(p) - lpVtbl - GetAdapterCount (p)>
        endm
        IDirect3D9_GetAdapterIdentifier macro p, a, b, c_
          exitm <(p) - lpVtbl - GetAdapterIdentifier (p, a, b, c_)>
        endm
        IDirect3D9_GetAdapterModeCount macro p, a, b
          exitm <(p) - lpVtbl - GetAdapterModeCount (p, a, b)>
        endm
        IDirect3D9_EnumAdapterModes macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumAdapterModes (p, a, b, c_, d)>
        endm
        IDirect3D9_GetAdapterDisplayMode macro p, a, b
          exitm <(p) - lpVtbl - GetAdapterDisplayMode (p, a, b)>
        endm
        IDirect3D9_CheckDeviceType macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - CheckDeviceType (p, a, b, c_, d, e)>
        endm
        IDirect3D9_CheckDeviceFormat macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - CheckDeviceFormat (p, a, b, c_, d, e, f)>
        endm
        IDirect3D9_CheckDeviceMultiSampleType macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - CheckDeviceMultiSampleType (p, a, b, c_, d, e, f)>
        endm
        IDirect3D9_CheckDepthStencilMatch macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - CheckDepthStencilMatch (p, a, b, c_, d, e)>
        endm
        IDirect3D9_CheckDeviceFormatConversion macro p, a, b, c_, d
          exitm <(p) - lpVtbl - CheckDeviceFormatConversion (p, a, b, c_, d)>
        endm
        IDirect3D9_GetDeviceCaps macro p, a, b, c_
          exitm <(p) - lpVtbl - GetDeviceCaps (p, a, b, c_)>
        endm
        IDirect3D9_GetAdapterMonitor macro p, a
          exitm <(p) - lpVtbl - GetAdapterMonitor (p, a)>
        endm
        IDirect3D9_CreateDevice macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - CreateDevice (p, a, b, c_, d, e, f)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DDevice9>
      DECLARE_INTERFACE_ IDirect3DDevice9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD TestCooperativeLevel, :THIS_
        STD_METHOD GetAvailableTextureMem, :THIS_
        STD_METHOD EvictManagedResources, :THIS_
        STD_METHOD GetDirect3D, :ptr ptr THIS_
        STD_METHOD GetDeviceCaps, :ptr THIS_
        STD_METHOD GetDisplayMode, :THIS_, :ptr D3DDISPLAYMODE
        STD_METHOD GetCreationParameters, :ptr THIS_
        STD_METHOD SetCursorProperties, :THIS_, :UINT, :ptr IDirect3DSurface9
        STD_METHOD SetCursorPosition, :THIS_, :SDWORD, :DWORD
        STD_METHOD ShowCursor, :THIS_
        STD_METHOD CreateAdditionalSwapChain, :ptr THIS_, :ptr ptr IDirect3DSwapChain9
        STD_METHOD GetSwapChain, :THIS_, :ptr ptr IDirect3DSwapChain9
        STD_METHOD GetNumberOfSwapChains, :THIS_
        STD_METHOD Reset, :ptr THIS_
        STD_METHOD Present, :ptr THIS_, :ptr RECT, :HWND, :ptr RGNDATA
        STD_METHOD GetBackBuffer, :THIS_, :UINT, :D3DBACKBUFFER_TYPE, :ptr ptr IDirect3DSurface9
        STD_METHOD GetRasterStatus, :THIS_, :ptr D3DRASTER_STATUS
        STD_METHOD SetDialogBoxMode, :THIS_
        STD_METHOD SetGammaRamp, :THIS_, :DWORD, :ptr D3DGAMMARAMP
        STD_METHOD GetGammaRamp, :THIS_, :ptr D3DGAMMARAMP
        STD_METHOD CreateTexture, :THIS_, :UINT, :UINT, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DTexture9, :ptr HANDLE
        STD_METHOD CreateVolumeTexture, :THIS_, :UINT, :UINT, :UINT, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DVolumeTexture9, :ptr HANDLE
        STD_METHOD CreateCubeTexture, :THIS_, :UINT, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DCubeTexture9, :ptr HANDLE
        STD_METHOD CreateVertexBuffer, :THIS_, :DWORD, :DWORD, :D3DPOOL, :ptr ptr IDirect3DVertexBuffer9, :ptr HANDLE
        STD_METHOD CreateIndexBuffer, :THIS_, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DIndexBuffer9, :ptr HANDLE
        STD_METHOD CreateRenderTarget, :THIS_, :UINT, :D3DFORMAT, :D3DMULTISAMPLE_TYPE, :DWORD, :BOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE
        STD_METHOD CreateDepthStencilSurface, :THIS_, :UINT, :D3DFORMAT, :D3DMULTISAMPLE_TYPE, :DWORD, :BOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE
        STD_METHOD UpdateSurface, :ptr THIS_, :ptr RECT, :ptr IDirect3DSurface9, :ptr POINT
        STD_METHOD UpdateTexture, :ptr THIS_, :ptr IDirect3DBaseTexture9
        STD_METHOD GetRenderTargetData, :ptr THIS_, :ptr IDirect3DSurface9
        STD_METHOD GetFrontBufferData, :THIS_, :ptr IDirect3DSurface9
        STD_METHOD StretchRect, :ptr THIS_, :ptr RECT, :ptr IDirect3DSurface9, :ptr RECT, :D3DTEXTUREFILTERTYPE
        STD_METHOD ColorFill, :ptr THIS_, :ptr RECT, :D3DCOLOR
        STD_METHOD CreateOffscreenPlainSurface, :THIS_, :UINT, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE
        STD_METHOD SetRenderTarget, :THIS_, :ptr IDirect3DSurface9
        STD_METHOD GetRenderTarget, :THIS_, :ptr ptr IDirect3DSurface9
        STD_METHOD SetDepthStencilSurface, :ptr THIS_
        STD_METHOD GetDepthStencilSurface, :ptr ptr THIS_
        STD_METHOD BeginScene, :THIS_
        STD_METHOD EndScene, :THIS_
        STD_METHOD Clear, :THIS_, :ptr D3DRECT, :DWORD, :D3DCOLOR, :REAL4, :DWORD
        STD_METHOD SetTransform, :THIS_, :ptr D3DMATRIX
        STD_METHOD GetTransform, :THIS_, :ptr D3DMATRIX
        STD_METHOD MultiplyTransform, :THIS_, :ptr D3DMATRIX
        STD_METHOD SetViewport, :ptr THIS_
        STD_METHOD GetViewport, :ptr THIS_
        STD_METHOD SetMaterial, :ptr THIS_
        STD_METHOD GetMaterial, :ptr THIS_
        STD_METHOD SetLight, :THIS_, :ptr D3DLIGHT9
        STD_METHOD GetLight, :THIS_, :ptr D3DLIGHT9
        STD_METHOD LightEnable, :THIS_, :BOOL
        STD_METHOD GetLightEnable, :THIS_, :ptr BOOL
        STD_METHOD SetClipPlane, :THIS_, :ptr REAL4
        STD_METHOD GetClipPlane, :THIS_, :ptr REAL4
        STD_METHOD SetRenderState, :THIS_, :DWORD
        STD_METHOD GetRenderState, :THIS_, :ptr DWORD
        STD_METHOD CreateStateBlock, :THIS_, :ptr ptr IDirect3DStateBlock9
        STD_METHOD BeginStateBlock, :THIS_
        STD_METHOD EndStateBlock, :ptr ptr THIS_
        STD_METHOD SetClipStatus, :ptr THIS_
        STD_METHOD GetClipStatus, :ptr THIS_
        STD_METHOD GetTexture, :THIS_, :ptr ptr IDirect3DBaseTexture9
        STD_METHOD SetTexture, :THIS_, :ptr IDirect3DBaseTexture9
        STD_METHOD GetTextureStageState, :THIS_, :D3DTEXTURESTAGESTATETYPE, :ptr DWORD
        STD_METHOD SetTextureStageState, :THIS_, :D3DTEXTURESTAGESTATETYPE, :DWORD
        STD_METHOD GetSamplerState, :THIS_, :D3DSAMPLERSTATETYPE, :ptr DWORD
        STD_METHOD SetSamplerState, :THIS_, :D3DSAMPLERSTATETYPE, :DWORD
        STD_METHOD ValidateDevice, :ptr THIS_
        STD_METHOD SetPaletteEntries, :THIS_, :ptr PALETTEENTRY
        STD_METHOD GetPaletteEntries, :THIS_, :ptr PALETTEENTRY
        STD_METHOD SetCurrentTexturePalette, :THIS_
        STD_METHOD GetCurrentTexturePalette, :ptr THIS_
        STD_METHOD SetScissorRect, :ptr THIS_
        STD_METHOD GetScissorRect, :ptr THIS_
        STD_METHOD SetSoftwareVertexProcessing, :THIS_
        STD_METHOD GetSoftwareVertexProcessing, :THIS_
        STD_METHOD SetNPatchMode, :THIS_
        STD_METHOD GetNPatchMode, :THIS_
        STD_METHOD DrawPrimitive, :THIS_, :UINT, :UINT
        STD_METHOD DrawIndexedPrimitive, :THIS_, :INT_, :UINT, :UINT, :UINT, :UINT
        STD_METHOD DrawPrimitiveUP, :THIS_, :UINT, :ptr, :UINT
        STD_METHOD DrawIndexedPrimitiveUP, :THIS_, :UINT, :UINT, :UINT, :ptr, :D3DFORMAT, :ptr, :UINT
        STD_METHOD ProcessVertices, :THIS_, :UINT, :UINT, :ptr IDirect3DVertexBuffer9, :ptr IDirect3DVertexDeclaration9, :DWORD
        STD_METHOD CreateVertexDeclaration, :ptr THIS_, :ptr ptr IDirect3DVertexDeclaration9
        STD_METHOD SetVertexDeclaration, :ptr THIS_
        STD_METHOD GetVertexDeclaration, :ptr ptr THIS_
        STD_METHOD SetFVF, :THIS_
        STD_METHOD GetFVF, :ptr THIS_
        STD_METHOD CreateVertexShader, :ptr THIS_, :ptr ptr IDirect3DVertexShader9
        STD_METHOD SetVertexShader, :ptr THIS_
        STD_METHOD GetVertexShader, :ptr ptr THIS_
        STD_METHOD SetVertexShaderConstantF, :THIS_, :ptr REAL4, :UINT
        STD_METHOD GetVertexShaderConstantF, :THIS_, :ptr REAL4, :UINT
        STD_METHOD SetVertexShaderConstantI, :THIS_, :ptr SDWORD, :UINT
        STD_METHOD GetVertexShaderConstantI, :THIS_, :ptr SDWORD, :UINT
        STD_METHOD SetVertexShaderConstantB, :THIS_, :ptr BOOL, :UINT
        STD_METHOD GetVertexShaderConstantB, :THIS_, :ptr BOOL, :UINT
        STD_METHOD SetStreamSource, :THIS_, :ptr IDirect3DVertexBuffer9, :UINT, :UINT
        STD_METHOD GetStreamSource, :THIS_, :ptr ptr IDirect3DVertexBuffer9, :ptr UINT, :ptr UINT
        STD_METHOD SetStreamSourceFreq, :THIS_, :UINT
        STD_METHOD GetStreamSourceFreq, :THIS_, :ptr UINT
        STD_METHOD SetIndices, :ptr THIS_
        STD_METHOD GetIndices, :ptr ptr THIS_
        STD_METHOD CreatePixelShader, :ptr THIS_, :ptr ptr IDirect3DPixelShader9
        STD_METHOD SetPixelShader, :ptr THIS_
        STD_METHOD GetPixelShader, :ptr ptr THIS_
        STD_METHOD SetPixelShaderConstantF, :THIS_, :ptr REAL4, :UINT
        STD_METHOD GetPixelShaderConstantF, :THIS_, :ptr REAL4, :UINT
        STD_METHOD SetPixelShaderConstantI, :THIS_, :ptr SDWORD, :UINT
        STD_METHOD GetPixelShaderConstantI, :THIS_, :ptr SDWORD, :UINT
        STD_METHOD SetPixelShaderConstantB, :THIS_, :ptr BOOL, :UINT
        STD_METHOD GetPixelShaderConstantB, :THIS_, :ptr BOOL, :UINT
        STD_METHOD DrawRectPatch, :THIS_, :ptr REAL4, :ptr D3DRECTPATCH_INFO
        STD_METHOD DrawTriPatch, :THIS_, :ptr REAL4, :ptr D3DTRIPATCH_INFO
        STD_METHOD DeletePatch, :THIS_
        STD_METHOD CreateQuery, :THIS_, :ptr ptr IDirect3DQuery9
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DDEVICE9 typedef ptr IDirect3DDevice9
      PDIRECT3DDEVICE9 typedef ptr IDirect3DDevice9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DDevice9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DDevice9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DDevice9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DDevice9_TestCooperativeLevel macro p
          exitm <(p) - lpVtbl - TestCooperativeLevel (p)>
        endm
        IDirect3DDevice9_GetAvailableTextureMem macro p
          exitm <(p) - lpVtbl - GetAvailableTextureMem (p)>
        endm
        IDirect3DDevice9_EvictManagedResources macro p
          exitm <(p) - lpVtbl - EvictManagedResources (p)>
        endm
        IDirect3DDevice9_GetDirect3D macro p, a
          exitm <(p) - lpVtbl - GetDirect3D (p, a)>
        endm
        IDirect3DDevice9_GetDeviceCaps macro p, a
          exitm <(p) - lpVtbl - GetDeviceCaps (p, a)>
        endm
        IDirect3DDevice9_GetDisplayMode macro p, a, b
          exitm <(p) - lpVtbl - GetDisplayMode (p, a, b)>
        endm
        IDirect3DDevice9_GetCreationParameters macro p, a
          exitm <(p) - lpVtbl - GetCreationParameters (p, a)>
        endm
        IDirect3DDevice9_SetCursorProperties macro p, a, b, c_
          exitm <(p) - lpVtbl - SetCursorProperties (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetCursorPosition macro p, a, b, c_
          exitm <(p) - lpVtbl - SetCursorPosition (p, a, b, c_)>
        endm
        IDirect3DDevice9_ShowCursor macro p, a
          exitm <(p) - lpVtbl - ShowCursor (p, a)>
        endm
        IDirect3DDevice9_CreateAdditionalSwapChain macro p, a, b
          exitm <(p) - lpVtbl - CreateAdditionalSwapChain (p, a, b)>
        endm
        IDirect3DDevice9_GetSwapChain macro p, a, b
          exitm <(p) - lpVtbl - GetSwapChain (p, a, b)>
        endm
        IDirect3DDevice9_GetNumberOfSwapChains macro p
          exitm <(p) - lpVtbl - GetNumberOfSwapChains (p)>
        endm
        IDirect3DDevice9_Reset macro p, a
          exitm <(p) - lpVtbl - Reset (p, a)>
        endm
        IDirect3DDevice9_Present macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Present (p, a, b, c_, d)>
        endm
        IDirect3DDevice9_GetBackBuffer macro p, a, b, c_, d
          exitm <(p) - lpVtbl - GetBackBuffer (p, a, b, c_, d)>
        endm
        IDirect3DDevice9_GetRasterStatus macro p, a, b
          exitm <(p) - lpVtbl - GetRasterStatus (p, a, b)>
        endm
        IDirect3DDevice9_SetDialogBoxMode macro p, a
          exitm <(p) - lpVtbl - SetDialogBoxMode (p, a)>
        endm
        IDirect3DDevice9_SetGammaRamp macro p, a, b, c_
          exitm <(p) - lpVtbl - SetGammaRamp (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetGammaRamp macro p, a, b
          exitm <(p) - lpVtbl - GetGammaRamp (p, a, b)>
        endm
        IDirect3DDevice9_CreateTexture macro p, a, b, c_, d, e, f, g, h
          exitm <(p) - lpVtbl - CreateTexture (p, a, b, c_, d, e, f, g, h)>
        endm
        IDirect3DDevice9_CreateVolumeTexture macro p, a, b, c_, d, e, f, g, h, i
          exitm <(p) - lpVtbl - CreateVolumeTexture (p, a, b, c_, d, e, f, g, h, i)>
        endm
        IDirect3DDevice9_CreateCubeTexture macro p, a, b, c_, d, e, f, g
          exitm <(p) - lpVtbl - CreateCubeTexture (p, a, b, c_, d, e, f, g)>
        endm
        IDirect3DDevice9_CreateVertexBuffer macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - CreateVertexBuffer (p, a, b, c_, d, e, f)>
        endm
        IDirect3DDevice9_CreateIndexBuffer macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - CreateIndexBuffer (p, a, b, c_, d, e, f)>
        endm
        IDirect3DDevice9_CreateRenderTarget macro p, a, b, c_, d, e, f, g, h
          exitm <(p) - lpVtbl - CreateRenderTarget (p, a, b, c_, d, e, f, g, h)>
        endm
        IDirect3DDevice9_CreateDepthStencilSurface macro p, a, b, c_, d, e, f, g, h
          exitm <(p) - lpVtbl - CreateDepthStencilSurface (p, a, b, c_, d, e, f, g, h)>
        endm
        IDirect3DDevice9_UpdateSurface macro p, a, b, c_, d
          exitm <(p) - lpVtbl - UpdateSurface (p, a, b, c_, d)>
        endm
        IDirect3DDevice9_UpdateTexture macro p, a, b
          exitm <(p) - lpVtbl - UpdateTexture (p, a, b)>
        endm
        IDirect3DDevice9_GetRenderTargetData macro p, a, b
          exitm <(p) - lpVtbl - GetRenderTargetData (p, a, b)>
        endm
        IDirect3DDevice9_GetFrontBufferData macro p, a, b
          exitm <(p) - lpVtbl - GetFrontBufferData (p, a, b)>
        endm
        IDirect3DDevice9_StretchRect macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - StretchRect (p, a, b, c_, d, e)>
        endm
        IDirect3DDevice9_ColorFill macro p, a, b, c_
          exitm <(p) - lpVtbl - ColorFill (p, a, b, c_)>
        endm
        IDirect3DDevice9_CreateOffscreenPlainSurface macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - CreateOffscreenPlainSurface (p, a, b, c_, d, e, f)>
        endm
        IDirect3DDevice9_SetRenderTarget macro p, a, b
          exitm <(p) - lpVtbl - SetRenderTarget (p, a, b)>
        endm
        IDirect3DDevice9_GetRenderTarget macro p, a, b
          exitm <(p) - lpVtbl - GetRenderTarget (p, a, b)>
        endm
        IDirect3DDevice9_SetDepthStencilSurface macro p, a
          exitm <(p) - lpVtbl - SetDepthStencilSurface (p, a)>
        endm
        IDirect3DDevice9_GetDepthStencilSurface macro p, a
          exitm <(p) - lpVtbl - GetDepthStencilSurface (p, a)>
        endm
        IDirect3DDevice9_BeginScene macro p
          exitm <(p) - lpVtbl - BeginScene (p)>
        endm
        IDirect3DDevice9_EndScene macro p
          exitm <(p) - lpVtbl - EndScene (p)>
        endm
        IDirect3DDevice9_Clear macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - Clear (p, a, b, c_, d, e, f)>
        endm
        IDirect3DDevice9_SetTransform macro p, a, b
          exitm <(p) - lpVtbl - SetTransform (p, a, b)>
        endm
        IDirect3DDevice9_GetTransform macro p, a, b
          exitm <(p) - lpVtbl - GetTransform (p, a, b)>
        endm
        IDirect3DDevice9_MultiplyTransform macro p, a, b
          exitm <(p) - lpVtbl - MultiplyTransform (p, a, b)>
        endm
        IDirect3DDevice9_SetViewport macro p, a
          exitm <(p) - lpVtbl - SetViewport (p, a)>
        endm
        IDirect3DDevice9_GetViewport macro p, a
          exitm <(p) - lpVtbl - GetViewport (p, a)>
        endm
        IDirect3DDevice9_SetMaterial macro p, a
          exitm <(p) - lpVtbl - SetMaterial (p, a)>
        endm
        IDirect3DDevice9_GetMaterial macro p, a
          exitm <(p) - lpVtbl - GetMaterial (p, a)>
        endm
        IDirect3DDevice9_SetLight macro p, a, b
          exitm <(p) - lpVtbl - SetLight (p, a, b)>
        endm
        IDirect3DDevice9_GetLight macro p, a, b
          exitm <(p) - lpVtbl - GetLight (p, a, b)>
        endm
        IDirect3DDevice9_LightEnable macro p, a, b
          exitm <(p) - lpVtbl - LightEnable (p, a, b)>
        endm
        IDirect3DDevice9_GetLightEnable macro p, a, b
          exitm <(p) - lpVtbl - GetLightEnable (p, a, b)>
        endm
        IDirect3DDevice9_SetClipPlane macro p, a, b
          exitm <(p) - lpVtbl - SetClipPlane (p, a, b)>
        endm
        IDirect3DDevice9_GetClipPlane macro p, a, b
          exitm <(p) - lpVtbl - GetClipPlane (p, a, b)>
        endm
        IDirect3DDevice9_SetRenderState macro p, a, b
          exitm <(p) - lpVtbl - SetRenderState (p, a, b)>
        endm
        IDirect3DDevice9_GetRenderState macro p, a, b
          exitm <(p) - lpVtbl - GetRenderState (p, a, b)>
        endm
        IDirect3DDevice9_CreateStateBlock macro p, a, b
          exitm <(p) - lpVtbl - CreateStateBlock (p, a, b)>
        endm
        IDirect3DDevice9_BeginStateBlock macro p
          exitm <(p) - lpVtbl - BeginStateBlock (p)>
        endm
        IDirect3DDevice9_EndStateBlock macro p, a
          exitm <(p) - lpVtbl - EndStateBlock (p, a)>
        endm
        IDirect3DDevice9_SetClipStatus macro p, a
          exitm <(p) - lpVtbl - SetClipStatus (p, a)>
        endm
        IDirect3DDevice9_GetClipStatus macro p, a
          exitm <(p) - lpVtbl - GetClipStatus (p, a)>
        endm
        IDirect3DDevice9_GetTexture macro p, a, b
          exitm <(p) - lpVtbl - GetTexture (p, a, b)>
        endm
        IDirect3DDevice9_SetTexture macro p, a, b
          exitm <(p) - lpVtbl - SetTexture (p, a, b)>
        endm
        IDirect3DDevice9_GetTextureStageState macro p, a, b, c_
          exitm <(p) - lpVtbl - GetTextureStageState (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetTextureStageState macro p, a, b, c_
          exitm <(p) - lpVtbl - SetTextureStageState (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetSamplerState macro p, a, b, c_
          exitm <(p) - lpVtbl - GetSamplerState (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetSamplerState macro p, a, b, c_
          exitm <(p) - lpVtbl - SetSamplerState (p, a, b, c_)>
        endm
        IDirect3DDevice9_ValidateDevice macro p, a
          exitm <(p) - lpVtbl - ValidateDevice (p, a)>
        endm
        IDirect3DDevice9_SetPaletteEntries macro p, a, b
          exitm <(p) - lpVtbl - SetPaletteEntries (p, a, b)>
        endm
        IDirect3DDevice9_GetPaletteEntries macro p, a, b
          exitm <(p) - lpVtbl - GetPaletteEntries (p, a, b)>
        endm
        IDirect3DDevice9_SetCurrentTexturePalette macro p, a
          exitm <(p) - lpVtbl - SetCurrentTexturePalette (p, a)>
        endm
        IDirect3DDevice9_GetCurrentTexturePalette macro p, a
          exitm <(p) - lpVtbl - GetCurrentTexturePalette (p, a)>
        endm
        IDirect3DDevice9_SetScissorRect macro p, a
          exitm <(p) - lpVtbl - SetScissorRect (p, a)>
        endm
        IDirect3DDevice9_GetScissorRect macro p, a
          exitm <(p) - lpVtbl - GetScissorRect (p, a)>
        endm
        IDirect3DDevice9_SetSoftwareVertexProcessing macro p, a
          exitm <(p) - lpVtbl - SetSoftwareVertexProcessing (p, a)>
        endm
        IDirect3DDevice9_GetSoftwareVertexProcessing macro p
          exitm <(p) - lpVtbl - GetSoftwareVertexProcessing (p)>
        endm
        IDirect3DDevice9_SetNPatchMode macro p, a
          exitm <(p) - lpVtbl - SetNPatchMode (p, a)>
        endm
        IDirect3DDevice9_GetNPatchMode macro p
          exitm <(p) - lpVtbl - GetNPatchMode (p)>
        endm
        IDirect3DDevice9_DrawPrimitive macro p, a, b, c_
          exitm <(p) - lpVtbl - DrawPrimitive (p, a, b, c_)>
        endm
        IDirect3DDevice9_DrawIndexedPrimitive macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - DrawIndexedPrimitive (p, a, b, c_, d, e, f)>
        endm
        IDirect3DDevice9_DrawPrimitiveUP macro p, a, b, c_, d
          exitm <(p) - lpVtbl - DrawPrimitiveUP (p, a, b, c_, d)>
        endm
        IDirect3DDevice9_DrawIndexedPrimitiveUP macro p, a, b, c_, d, e, f, g, h
          exitm <(p) - lpVtbl - DrawIndexedPrimitiveUP (p, a, b, c_, d, e, f, g, h)>
        endm
        IDirect3DDevice9_ProcessVertices macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - ProcessVertices (p, a, b, c_, d, e, f)>
        endm
        IDirect3DDevice9_CreateVertexDeclaration macro p, a, b
          exitm <(p) - lpVtbl - CreateVertexDeclaration (p, a, b)>
        endm
        IDirect3DDevice9_SetVertexDeclaration macro p, a
          exitm <(p) - lpVtbl - SetVertexDeclaration (p, a)>
        endm
        IDirect3DDevice9_GetVertexDeclaration macro p, a
          exitm <(p) - lpVtbl - GetVertexDeclaration (p, a)>
        endm
        IDirect3DDevice9_SetFVF macro p, a
          exitm <(p) - lpVtbl - SetFVF (p, a)>
        endm
        IDirect3DDevice9_GetFVF macro p, a
          exitm <(p) - lpVtbl - GetFVF (p, a)>
        endm
        IDirect3DDevice9_CreateVertexShader macro p, a, b
          exitm <(p) - lpVtbl - CreateVertexShader (p, a, b)>
        endm
        IDirect3DDevice9_SetVertexShader macro p, a
          exitm <(p) - lpVtbl - SetVertexShader (p, a)>
        endm
        IDirect3DDevice9_GetVertexShader macro p, a
          exitm <(p) - lpVtbl - GetVertexShader (p, a)>
        endm
        IDirect3DDevice9_SetVertexShaderConstantF macro p, a, b, c_
          exitm <(p) - lpVtbl - SetVertexShaderConstantF (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetVertexShaderConstantF macro p, a, b, c_
          exitm <(p) - lpVtbl - GetVertexShaderConstantF (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetVertexShaderConstantI macro p, a, b, c_
          exitm <(p) - lpVtbl - SetVertexShaderConstantI (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetVertexShaderConstantI macro p, a, b, c_
          exitm <(p) - lpVtbl - GetVertexShaderConstantI (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetVertexShaderConstantB macro p, a, b, c_
          exitm <(p) - lpVtbl - SetVertexShaderConstantB (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetVertexShaderConstantB macro p, a, b, c_
          exitm <(p) - lpVtbl - GetVertexShaderConstantB (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetStreamSource macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetStreamSource (p, a, b, c_, d)>
        endm
        IDirect3DDevice9_GetStreamSource macro p, a, b, c_, d
          exitm <(p) - lpVtbl - GetStreamSource (p, a, b, c_, d)>
        endm
        IDirect3DDevice9_SetStreamSourceFreq macro p, a, b
          exitm <(p) - lpVtbl - SetStreamSourceFreq (p, a, b)>
        endm
        IDirect3DDevice9_GetStreamSourceFreq macro p, a, b
          exitm <(p) - lpVtbl - GetStreamSourceFreq (p, a, b)>
        endm
        IDirect3DDevice9_SetIndices macro p, a
          exitm <(p) - lpVtbl - SetIndices (p, a)>
        endm
        IDirect3DDevice9_GetIndices macro p, a
          exitm <(p) - lpVtbl - GetIndices (p, a)>
        endm
        IDirect3DDevice9_CreatePixelShader macro p, a, b
          exitm <(p) - lpVtbl - CreatePixelShader (p, a, b)>
        endm
        IDirect3DDevice9_SetPixelShader macro p, a
          exitm <(p) - lpVtbl - SetPixelShader (p, a)>
        endm
        IDirect3DDevice9_GetPixelShader macro p, a
          exitm <(p) - lpVtbl - GetPixelShader (p, a)>
        endm
        IDirect3DDevice9_SetPixelShaderConstantF macro p, a, b, c_
          exitm <(p) - lpVtbl - SetPixelShaderConstantF (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetPixelShaderConstantF macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPixelShaderConstantF (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetPixelShaderConstantI macro p, a, b, c_
          exitm <(p) - lpVtbl - SetPixelShaderConstantI (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetPixelShaderConstantI macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPixelShaderConstantI (p, a, b, c_)>
        endm
        IDirect3DDevice9_SetPixelShaderConstantB macro p, a, b, c_
          exitm <(p) - lpVtbl - SetPixelShaderConstantB (p, a, b, c_)>
        endm
        IDirect3DDevice9_GetPixelShaderConstantB macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPixelShaderConstantB (p, a, b, c_)>
        endm
        IDirect3DDevice9_DrawRectPatch macro p, a, b, c_
          exitm <(p) - lpVtbl - DrawRectPatch (p, a, b, c_)>
        endm
        IDirect3DDevice9_DrawTriPatch macro p, a, b, c_
          exitm <(p) - lpVtbl - DrawTriPatch (p, a, b, c_)>
        endm
        IDirect3DDevice9_DeletePatch macro p, a
          exitm <(p) - lpVtbl - DeletePatch (p, a)>
        endm
        IDirect3DDevice9_CreateQuery macro p, a, b
          exitm <(p) - lpVtbl - CreateQuery (p, a, b)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DStateBlock9>
      DECLARE_INTERFACE_ IDirect3DStateBlock9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD Capture, :THIS_
        STD_METHOD Apply, :THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DSTATEBLOCK9 typedef ptr IDirect3DStateBlock9
      PDIRECT3DSTATEBLOCK9 typedef ptr IDirect3DStateBlock9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DStateBlock9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DStateBlock9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DStateBlock9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DStateBlock9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DStateBlock9_Capture macro p
          exitm <(p) - lpVtbl - Capture (p)>
        endm
        IDirect3DStateBlock9_Apply macro p
          exitm <(p) - lpVtbl - Apply (p)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DSwapChain9>
      DECLARE_INTERFACE_ IDirect3DSwapChain9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Present, :ptr THIS_, :ptr RECT, :HWND, :ptr RGNDATA, :DWORD
        STD_METHOD GetFrontBufferData, :ptr THIS_
        STD_METHOD GetBackBuffer, :THIS_, :D3DBACKBUFFER_TYPE, :ptr ptr IDirect3DSurface9
        STD_METHOD GetRasterStatus, :ptr THIS_
        STD_METHOD GetDisplayMode, :ptr THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD GetPresentParameters, :ptr THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DSWAPCHAIN9 typedef ptr IDirect3DSwapChain9
      PDIRECT3DSWAPCHAIN9 typedef ptr IDirect3DSwapChain9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DSwapChain9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DSwapChain9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DSwapChain9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DSwapChain9_Present macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - Present (p, a, b, c_, d, e)>
        endm
        IDirect3DSwapChain9_GetFrontBufferData macro p, a
          exitm <(p) - lpVtbl - GetFrontBufferData (p, a)>
        endm
        IDirect3DSwapChain9_GetBackBuffer macro p, a, b, c_
          exitm <(p) - lpVtbl - GetBackBuffer (p, a, b, c_)>
        endm
        IDirect3DSwapChain9_GetRasterStatus macro p, a
          exitm <(p) - lpVtbl - GetRasterStatus (p, a)>
        endm
        IDirect3DSwapChain9_GetDisplayMode macro p, a
          exitm <(p) - lpVtbl - GetDisplayMode (p, a)>
        endm
        IDirect3DSwapChain9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DSwapChain9_GetPresentParameters macro p, a
          exitm <(p) - lpVtbl - GetPresentParameters (p, a)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DResource9>
      DECLARE_INTERFACE_ IDirect3DResource9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
      END_DECLARE_INTERFACE_
      LPDIRECT3DRESOURCE9 typedef ptr IDirect3DResource9
      PDIRECT3DRESOURCE9 typedef ptr IDirect3DResource9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DResource9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DResource9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DResource9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DResource9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DResource9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DResource9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DResource9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DResource9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DResource9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DResource9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DResource9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DVertexDeclaration9>
      DECLARE_INTERFACE_ IDirect3DVertexDeclaration9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD GetDeclaration, :ptr THIS_, :ptr UINT
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DVERTEXDECLARATION9 typedef ptr IDirect3DVertexDeclaration9
      PDIRECT3DVERTEXDECLARATION9 typedef ptr IDirect3DVertexDeclaration9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DVertexDeclaration9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DVertexDeclaration9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DVertexDeclaration9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DVertexDeclaration9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DVertexDeclaration9_GetDeclaration macro p, a, b
          exitm <(p) - lpVtbl - GetDeclaration (p, a, b)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DVertexShader9>
      DECLARE_INTERFACE_ IDirect3DVertexShader9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD GetFunction, :ptr THIS_, :ptr UINT
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DVERTEXSHADER9 typedef ptr IDirect3DVertexShader9
      PDIRECT3DVERTEXSHADER9 typedef ptr IDirect3DVertexShader9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DVertexShader9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DVertexShader9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DVertexShader9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DVertexShader9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DVertexShader9_GetFunction macro p, a, b
          exitm <(p) - lpVtbl - GetFunction (p, a, b)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DPixelShader9>
      DECLARE_INTERFACE_ IDirect3DPixelShader9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD GetFunction, :ptr THIS_, :ptr UINT
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DPIXELSHADER9 typedef ptr IDirect3DPixelShader9
      PDIRECT3DPIXELSHADER9 typedef ptr IDirect3DPixelShader9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DPixelShader9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DPixelShader9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DPixelShader9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DPixelShader9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DPixelShader9_GetFunction macro p, a, b
          exitm <(p) - lpVtbl - GetFunction (p, a, b)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DBaseTexture9>
      DECLARE_INTERFACE_ IDirect3DBaseTexture9, IDirect3DResource9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD SetLOD, :THIS_
        STD_METHOD GetLOD, :THIS_
        STD_METHOD GetLevelCount, :THIS_
        STD_METHOD SetAutoGenFilterType, :THIS_
        STD_METHOD GetAutoGenFilterType, :THIS_
        STD_METHOD GenerateMipSubLevels, :THIS_
      END_DECLARE_INTERFACE_
      LPDIRECT3DBASETEXTURE9 typedef ptr IDirect3DBaseTexture9
      PDIRECT3DBASETEXTURE9 typedef ptr IDirect3DBaseTexture9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DBaseTexture9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DBaseTexture9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DBaseTexture9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DBaseTexture9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DBaseTexture9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DBaseTexture9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DBaseTexture9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DBaseTexture9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DBaseTexture9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DBaseTexture9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DBaseTexture9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DBaseTexture9_SetLOD macro p, a
          exitm <(p) - lpVtbl - SetLOD (p, a)>
        endm
        IDirect3DBaseTexture9_GetLOD macro p
          exitm <(p) - lpVtbl - GetLOD (p)>
        endm
        IDirect3DBaseTexture9_GetLevelCount macro p
          exitm <(p) - lpVtbl - GetLevelCount (p)>
        endm
        IDirect3DBaseTexture9_SetAutoGenFilterType macro p, a
          exitm <(p) - lpVtbl - SetAutoGenFilterType (p, a)>
        endm
        IDirect3DBaseTexture9_GetAutoGenFilterType macro p
          exitm <(p) - lpVtbl - GetAutoGenFilterType (p)>
        endm
        IDirect3DBaseTexture9_GenerateMipSubLevels macro p
          exitm <(p) - lpVtbl - GenerateMipSubLevels (p)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DTexture9>
      DECLARE_INTERFACE_ IDirect3DTexture9, IDirect3DBaseTexture9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD SetLOD, :THIS_
        STD_METHOD GetLOD, :THIS_
        STD_METHOD GetLevelCount, :THIS_
        STD_METHOD SetAutoGenFilterType, :THIS_
        STD_METHOD GetAutoGenFilterType, :THIS_
        STD_METHOD GenerateMipSubLevels, :THIS_
        STD_METHOD GetLevelDesc, :THIS_, :ptr D3DSURFACE_DESC
        STD_METHOD GetSurfaceLevel, :THIS_, :ptr ptr IDirect3DSurface9
        STD_METHOD LockRect, :THIS_, :ptr D3DLOCKED_RECT, :ptr RECT, :DWORD
        STD_METHOD UnlockRect, :THIS_
        STD_METHOD AddDirtyRect, :ptr THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DTEXTURE9 typedef ptr IDirect3DTexture9
      PDIRECT3DTEXTURE9 typedef ptr IDirect3DTexture9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DTexture9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DTexture9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DTexture9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DTexture9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DTexture9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DTexture9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DTexture9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DTexture9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DTexture9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DTexture9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DTexture9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DTexture9_SetLOD macro p, a
          exitm <(p) - lpVtbl - SetLOD (p, a)>
        endm
        IDirect3DTexture9_GetLOD macro p
          exitm <(p) - lpVtbl - GetLOD (p)>
        endm
        IDirect3DTexture9_GetLevelCount macro p
          exitm <(p) - lpVtbl - GetLevelCount (p)>
        endm
        IDirect3DTexture9_SetAutoGenFilterType macro p, a
          exitm <(p) - lpVtbl - SetAutoGenFilterType (p, a)>
        endm
        IDirect3DTexture9_GetAutoGenFilterType macro p
          exitm <(p) - lpVtbl - GetAutoGenFilterType (p)>
        endm
        IDirect3DTexture9_GenerateMipSubLevels macro p
          exitm <(p) - lpVtbl - GenerateMipSubLevels (p)>
        endm
        IDirect3DTexture9_GetLevelDesc macro p, a, b
          exitm <(p) - lpVtbl - GetLevelDesc (p, a, b)>
        endm
        IDirect3DTexture9_GetSurfaceLevel macro p, a, b
          exitm <(p) - lpVtbl - GetSurfaceLevel (p, a, b)>
        endm
        IDirect3DTexture9_LockRect macro p, a, b, c_, d
          exitm <(p) - lpVtbl - LockRect (p, a, b, c_, d)>
        endm
        IDirect3DTexture9_UnlockRect macro p, a
          exitm <(p) - lpVtbl - UnlockRect (p, a)>
        endm
        IDirect3DTexture9_AddDirtyRect macro p, a
          exitm <(p) - lpVtbl - AddDirtyRect (p, a)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DVolumeTexture9>
      DECLARE_INTERFACE_ IDirect3DVolumeTexture9, IDirect3DBaseTexture9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD SetLOD, :THIS_
        STD_METHOD GetLOD, :THIS_
        STD_METHOD GetLevelCount, :THIS_
        STD_METHOD SetAutoGenFilterType, :THIS_
        STD_METHOD GetAutoGenFilterType, :THIS_
        STD_METHOD GenerateMipSubLevels, :THIS_
        STD_METHOD GetLevelDesc, :THIS_, :ptr D3DVOLUME_DESC
        STD_METHOD GetVolumeLevel, :THIS_, :ptr ptr IDirect3DVolume9
        STD_METHOD LockBox, :THIS_, :ptr D3DLOCKED_BOX, :ptr D3DBOX, :DWORD
        STD_METHOD UnlockBox, :THIS_
        STD_METHOD AddDirtyBox, :ptr THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DVOLUMETEXTURE9 typedef ptr IDirect3DVolumeTexture9
      PDIRECT3DVOLUMETEXTURE9 typedef ptr IDirect3DVolumeTexture9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DVolumeTexture9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DVolumeTexture9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DVolumeTexture9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DVolumeTexture9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DVolumeTexture9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DVolumeTexture9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DVolumeTexture9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DVolumeTexture9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DVolumeTexture9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DVolumeTexture9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DVolumeTexture9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DVolumeTexture9_SetLOD macro p, a
          exitm <(p) - lpVtbl - SetLOD (p, a)>
        endm
        IDirect3DVolumeTexture9_GetLOD macro p
          exitm <(p) - lpVtbl - GetLOD (p)>
        endm
        IDirect3DVolumeTexture9_GetLevelCount macro p
          exitm <(p) - lpVtbl - GetLevelCount (p)>
        endm
        IDirect3DVolumeTexture9_SetAutoGenFilterType macro p, a
          exitm <(p) - lpVtbl - SetAutoGenFilterType (p, a)>
        endm
        IDirect3DVolumeTexture9_GetAutoGenFilterType macro p
          exitm <(p) - lpVtbl - GetAutoGenFilterType (p)>
        endm
        IDirect3DVolumeTexture9_GenerateMipSubLevels macro p
          exitm <(p) - lpVtbl - GenerateMipSubLevels (p)>
        endm
        IDirect3DVolumeTexture9_GetLevelDesc macro p, a, b
          exitm <(p) - lpVtbl - GetLevelDesc (p, a, b)>
        endm
        IDirect3DVolumeTexture9_GetVolumeLevel macro p, a, b
          exitm <(p) - lpVtbl - GetVolumeLevel (p, a, b)>
        endm
        IDirect3DVolumeTexture9_LockBox macro p, a, b, c_, d
          exitm <(p) - lpVtbl - LockBox (p, a, b, c_, d)>
        endm
        IDirect3DVolumeTexture9_UnlockBox macro p, a
          exitm <(p) - lpVtbl - UnlockBox (p, a)>
        endm
        IDirect3DVolumeTexture9_AddDirtyBox macro p, a
          exitm <(p) - lpVtbl - AddDirtyBox (p, a)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DCubeTexture9>
      DECLARE_INTERFACE_ IDirect3DCubeTexture9, IDirect3DBaseTexture9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD SetLOD, :THIS_
        STD_METHOD GetLOD, :THIS_
        STD_METHOD GetLevelCount, :THIS_
        STD_METHOD SetAutoGenFilterType, :THIS_
        STD_METHOD GetAutoGenFilterType, :THIS_
        STD_METHOD GenerateMipSubLevels, :THIS_
        STD_METHOD GetLevelDesc, :THIS_, :ptr D3DSURFACE_DESC
        STD_METHOD GetCubeMapSurface, :THIS_, :UINT, :ptr ptr IDirect3DSurface9
        STD_METHOD LockRect, :THIS_, :UINT, :ptr D3DLOCKED_RECT, :ptr RECT, :DWORD
        STD_METHOD UnlockRect, :THIS_, :UINT
        STD_METHOD AddDirtyRect, :THIS_, :ptr RECT
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DCUBETEXTURE9 typedef ptr IDirect3DCubeTexture9
      PDIRECT3DCUBETEXTURE9 typedef ptr IDirect3DCubeTexture9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DCubeTexture9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DCubeTexture9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DCubeTexture9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DCubeTexture9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DCubeTexture9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DCubeTexture9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DCubeTexture9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DCubeTexture9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DCubeTexture9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DCubeTexture9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DCubeTexture9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DCubeTexture9_SetLOD macro p, a
          exitm <(p) - lpVtbl - SetLOD (p, a)>
        endm
        IDirect3DCubeTexture9_GetLOD macro p
          exitm <(p) - lpVtbl - GetLOD (p)>
        endm
        IDirect3DCubeTexture9_GetLevelCount macro p
          exitm <(p) - lpVtbl - GetLevelCount (p)>
        endm
        IDirect3DCubeTexture9_SetAutoGenFilterType macro p, a
          exitm <(p) - lpVtbl - SetAutoGenFilterType (p, a)>
        endm
        IDirect3DCubeTexture9_GetAutoGenFilterType macro p
          exitm <(p) - lpVtbl - GetAutoGenFilterType (p)>
        endm
        IDirect3DCubeTexture9_GenerateMipSubLevels macro p
          exitm <(p) - lpVtbl - GenerateMipSubLevels (p)>
        endm
        IDirect3DCubeTexture9_GetLevelDesc macro p, a, b
          exitm <(p) - lpVtbl - GetLevelDesc (p, a, b)>
        endm
        IDirect3DCubeTexture9_GetCubeMapSurface macro p, a, b, c_
          exitm <(p) - lpVtbl - GetCubeMapSurface (p, a, b, c_)>
        endm
        IDirect3DCubeTexture9_LockRect macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - LockRect (p, a, b, c_, d, e)>
        endm
        IDirect3DCubeTexture9_UnlockRect macro p, a, b
          exitm <(p) - lpVtbl - UnlockRect (p, a, b)>
        endm
        IDirect3DCubeTexture9_AddDirtyRect macro p, a, b
          exitm <(p) - lpVtbl - AddDirtyRect (p, a, b)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DVertexBuffer9>
      DECLARE_INTERFACE_ IDirect3DVertexBuffer9, IDirect3DResource9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD Lock_, :THIS_, :UINT, :ptr ptr, :DWORD
        STD_METHOD Unlock, :THIS_
        STD_METHOD GetDesc, :ptr THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DVERTEXBUFFER9 typedef ptr IDirect3DVertexBuffer9
      PDIRECT3DVERTEXBUFFER9 typedef ptr IDirect3DVertexBuffer9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DVertexBuffer9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DVertexBuffer9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DVertexBuffer9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DVertexBuffer9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DVertexBuffer9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DVertexBuffer9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DVertexBuffer9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DVertexBuffer9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DVertexBuffer9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DVertexBuffer9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DVertexBuffer9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DVertexBuffer9_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirect3DVertexBuffer9_Unlock macro p
          exitm <(p) - lpVtbl - Unlock (p)>
        endm
        IDirect3DVertexBuffer9_GetDesc macro p, a
          exitm <(p) - lpVtbl - GetDesc (p, a)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DIndexBuffer9>
      DECLARE_INTERFACE_ IDirect3DIndexBuffer9, IDirect3DResource9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD Lock_, :THIS_, :UINT, :ptr ptr, :DWORD
        STD_METHOD Unlock, :THIS_
        STD_METHOD GetDesc, :ptr THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DINDEXBUFFER9 typedef ptr IDirect3DIndexBuffer9
      PDIRECT3DINDEXBUFFER9 typedef ptr IDirect3DIndexBuffer9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DIndexBuffer9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DIndexBuffer9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DIndexBuffer9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DIndexBuffer9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DIndexBuffer9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DIndexBuffer9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DIndexBuffer9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DIndexBuffer9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DIndexBuffer9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DIndexBuffer9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DIndexBuffer9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DIndexBuffer9_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirect3DIndexBuffer9_Unlock macro p
          exitm <(p) - lpVtbl - Unlock (p)>
        endm
        IDirect3DIndexBuffer9_GetDesc macro p, a
          exitm <(p) - lpVtbl - GetDesc (p, a)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DSurface9>
      DECLARE_INTERFACE_ IDirect3DSurface9, IDirect3DResource9
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD PreLoad, :THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD GetContainer, :THIS_, :ptr ptr
        STD_METHOD GetDesc, :ptr THIS_
        STD_METHOD LockRect, :ptr THIS_, :ptr RECT, :DWORD
        STD_METHOD UnlockRect, :THIS_
        STD_METHOD GetDC, :ptr THIS_
        STD_METHOD ReleaseDC, :THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DSURFACE9 typedef ptr IDirect3DSurface9
      PDIRECT3DSURFACE9 typedef ptr IDirect3DSurface9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DSurface9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DSurface9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DSurface9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DSurface9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DSurface9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DSurface9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DSurface9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DSurface9_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirect3DSurface9_GetPriority macro p
          exitm <(p) - lpVtbl - GetPriority (p)>
        endm
        IDirect3DSurface9_PreLoad macro p
          exitm <(p) - lpVtbl - PreLoad (p)>
        endm
        IDirect3DSurface9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DSurface9_GetContainer macro p, a, b
          exitm <(p) - lpVtbl - GetContainer (p, a, b)>
        endm
        IDirect3DSurface9_GetDesc macro p, a
          exitm <(p) - lpVtbl - GetDesc (p, a)>
        endm
        IDirect3DSurface9_LockRect macro p, a, b, c_
          exitm <(p) - lpVtbl - LockRect (p, a, b, c_)>
        endm
        IDirect3DSurface9_UnlockRect macro p
          exitm <(p) - lpVtbl - UnlockRect (p)>
        endm
        IDirect3DSurface9_GetDC macro p, a
          exitm <(p) - lpVtbl - GetDC (p, a)>
        endm
        IDirect3DSurface9_ReleaseDC macro p, a
          exitm <(p) - lpVtbl - ReleaseDC (p, a)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DVolume9>
      DECLARE_INTERFACE_ IDirect3DVolume9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD SetPrivateData, :THIS_, :ptr, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :ptr, :ptr DWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD GetContainer, :THIS_, :ptr ptr
        STD_METHOD GetDesc, :ptr THIS_
        STD_METHOD LockBox, :ptr THIS_, :ptr D3DBOX, :DWORD
        STD_METHOD UnlockBox, :THIS_
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DVOLUME9 typedef ptr IDirect3DVolume9
      PDIRECT3DVOLUME9 typedef ptr IDirect3DVolume9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DVolume9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DVolume9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DVolume9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DVolume9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DVolume9_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirect3DVolume9_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirect3DVolume9_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirect3DVolume9_GetContainer macro p, a, b
          exitm <(p) - lpVtbl - GetContainer (p, a, b)>
        endm
        IDirect3DVolume9_GetDesc macro p, a
          exitm <(p) - lpVtbl - GetDesc (p, a)>
        endm
        IDirect3DVolume9_LockBox macro p, a, b, c_
          exitm <(p) - lpVtbl - LockBox (p, a, b, c_)>
        endm
        IDirect3DVolume9_UnlockBox macro p
          exitm <(p) - lpVtbl - UnlockBox (p)>
        endm
      else
        ;[...]
      endif
      INTERFACE equ <IDirect3DQuery9>
      DECLARE_INTERFACE_ IDirect3DQuery9, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr ptr
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetDevice, :ptr ptr THIS_
        STD_METHOD GetType, :THIS_
        STD_METHOD GetDataSize, :THIS_
        STD_METHOD Issue, :THIS_
        STD_METHOD GetData, :ptr THIS_, :DWORD, :DWORD
        ifdef D3D_DEBUG_INFO
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      LPDIRECT3DQUERY9 typedef ptr IDirect3DQuery9
      PDIRECT3DQUERY9 typedef ptr IDirect3DQuery9
      
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirect3DQuery9_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirect3DQuery9_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirect3DQuery9_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirect3DQuery9_GetDevice macro p, a
          exitm <(p) - lpVtbl - GetDevice (p, a)>
        endm
        IDirect3DQuery9_GetType macro p
          exitm <(p) - lpVtbl - GetType (p)>
        endm
        IDirect3DQuery9_GetDataSize macro p
          exitm <(p) - lpVtbl - GetDataSize (p)>
        endm
        IDirect3DQuery9_Issue macro p, a
          exitm <(p) - lpVtbl - Issue (p, a)>
        endm
        IDirect3DQuery9_GetData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetData (p, a, b, c_)>
        endm
      else
        ;[...]
      endif
      D3DSPD_IUNKNOWN equ 00000001h
      D3DCREATE_FPU_PRESERVE equ 00000002h
      D3DCREATE_MULTITHREADED equ 00000004h
      D3DCREATE_PUREDEVICE equ 00000010h
      D3DCREATE_SOFTWARE_VERTEXPROCESSING equ 00000020h
      D3DCREATE_HARDWARE_VERTEXPROCESSING equ 00000040h
      D3DCREATE_MIXED_VERTEXPROCESSING equ 00000080h
      D3DCREATE_DISABLE_DRIVER_MANAGEMENT equ 00000100h
      D3DCREATE_ADAPTERGROUP_DEVICE equ 00000200h
      D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX equ 00000400h
      D3DCREATE_NOWINDOWCHANGES equ 00000800h
      if  not Defined(D3D_DISABLE_9EX)
        D3DCREATE_DISABLE_PSGP_THREADING equ 00002000h
        D3DCREATE_ENABLE_PRESENTSTATS equ 00004000h
        D3DCREATE_DISABLE_PRINTSCREEN equ 00008000h
        D3DCREATE_SCREENSAVER equ 10000000h
      endif
      D3DADAPTER_DEFAULT equ 0
      D3DENUM_WHQL_LEVEL equ 00000002h
      if  not Defined(D3D_DISABLE_9EX)
        D3DENUM_NO_DRIVERVERSION equ 00000004h
      endif
      D3DPRESENT_BACK_BUFFERS_MAX equ 3
      if  not Defined(D3D_DISABLE_9EX)
        D3DPRESENT_BACK_BUFFERS_MAX_EX equ 30
      endif
      D3DSGR_NO_CALIBRATION equ 00000000h
      D3DSGR_CALIBRATE equ 00000001h
      D3DCURSOR_IMMEDIATE_UPDATE equ 00000001h
      D3DPRESENT_DONOTWAIT equ 00000001h
      D3DPRESENT_LINEAR_CONTENT equ 00000002h
      if  not Defined(D3D_DISABLE_9EX)
        D3DPRESENT_DONOTFLIP equ 00000004h
        D3DPRESENT_FLIPRESTART equ 00000008h
        D3DPRESENT_VIDEO_RESTRICT_TO_MONITOR equ 00000010h
        D3DPRESENT_UPDATEOVERLAYONLY equ 00000020h
        D3DPRESENT_HIDEOVERLAY equ 00000040h
        D3DPRESENT_UPDATECOLORKEY equ 00000080h
        D3DPRESENT_FORCEIMMEDIATE equ 00000100h
      endif
      _FACD3D equ 876h
      MAKE_D3DHRESULT macro code
        exitm <MAKE_HRESULT(1, _FACD3D, code)>
      endm
      MAKE_D3DSTATUS macro code
        exitm <MAKE_HRESULT(0, _FACD3D, code)>
      endm
      D3D_OK equ <S_OK>
      D3DERR_WRONGTEXTUREFORMAT equ MAKE_D3DHRESULT(2072)
      D3DERR_UNSUPPORTEDCOLOROPERATION equ MAKE_D3DHRESULT(2073)
      D3DERR_UNSUPPORTEDCOLORARG equ MAKE_D3DHRESULT(2074)
      D3DERR_UNSUPPORTEDALPHAOPERATION equ MAKE_D3DHRESULT(2075)
      D3DERR_UNSUPPORTEDALPHAARG equ MAKE_D3DHRESULT(2076)
      D3DERR_TOOMANYOPERATIONS equ MAKE_D3DHRESULT(2077)
      D3DERR_CONFLICTINGTEXTUREFILTER equ MAKE_D3DHRESULT(2078)
      D3DERR_UNSUPPORTEDFACTORVALUE equ MAKE_D3DHRESULT(2079)
      D3DERR_CONFLICTINGRENDERSTATE equ MAKE_D3DHRESULT(2081)
      D3DERR_UNSUPPORTEDTEXTUREFILTER equ MAKE_D3DHRESULT(2082)
      D3DERR_CONFLICTINGTEXTUREPALETTE equ MAKE_D3DHRESULT(2086)
      D3DERR_DRIVERINTERNALERROR equ MAKE_D3DHRESULT(2087)
      D3DERR_NOTFOUND equ MAKE_D3DHRESULT(2150)
      D3DERR_MOREDATA equ MAKE_D3DHRESULT(2151)
      D3DERR_DEVICELOST equ MAKE_D3DHRESULT(2152)
      D3DERR_DEVICENOTRESET equ MAKE_D3DHRESULT(2153)
      D3DERR_NOTAVAILABLE equ MAKE_D3DHRESULT(2154)
      D3DERR_OUTOFVIDEOMEMORY equ MAKE_D3DHRESULT(380)
      D3DERR_INVALIDDEVICE equ MAKE_D3DHRESULT(2155)
      D3DERR_INVALIDCALL equ MAKE_D3DHRESULT(2156)
      D3DERR_DRIVERINVALIDCALL equ MAKE_D3DHRESULT(2157)
      D3DERR_WASSTILLDRAWING equ MAKE_D3DHRESULT(540)
      D3DOK_NOAUTOGEN equ MAKE_D3DSTATUS(2159)
      if  not Defined(D3D_DISABLE_9EX)
        D3DERR_DEVICEREMOVED equ MAKE_D3DHRESULT(2160)
        S_NOT_RESIDENT equ MAKE_D3DSTATUS(2165)
        S_RESIDENT_IN_SHARED_MEMORY equ MAKE_D3DSTATUS(2166)
        S_PRESENT_MODE_CHANGED equ MAKE_D3DSTATUS(2167)
        S_PRESENT_OCCLUDED equ MAKE_D3DSTATUS(2168)
        D3DERR_DEVICEHUNG equ MAKE_D3DHRESULT(2164)
        D3DERR_UNSUPPORTEDOVERLAY equ MAKE_D3DHRESULT(2171)
        D3DERR_UNSUPPORTEDOVERLAYFORMAT equ MAKE_D3DHRESULT(2172)
        D3DERR_CANNOTPROTECTCONTENT equ MAKE_D3DHRESULT(2173)
        D3DERR_UNSUPPORTEDCRYPTO equ MAKE_D3DHRESULT(2174)
        D3DERR_PRESENT_STATISTICS_DISJOINT equ MAKE_D3DHRESULT(2180)
        Direct3DCreate9Ex proto WIN_STD_CALL_CONV :UINT, :ptr ptr IDirect3D9Ex
        INTERFACE equ <IDirect3D9Ex>
        DECLARE_INTERFACE_ IDirect3D9Ex, IDirect3D9
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD RegisterSoftwareDevice, :ptr THIS_
          STD_METHOD GetAdapterCount, :THIS_
          STD_METHOD GetAdapterIdentifier, :THIS_, :DWORD, :ptr D3DADAPTER_IDENTIFIER9
          STD_METHOD GetAdapterModeCount, :THIS_, :D3DFORMAT
          STD_METHOD EnumAdapterModes, :THIS_, :D3DFORMAT, :UINT, :ptr D3DDISPLAYMODE
          STD_METHOD GetAdapterDisplayMode, :THIS_, :ptr D3DDISPLAYMODE
          STD_METHOD CheckDeviceType, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :D3DFORMAT, :BOOL
          STD_METHOD CheckDeviceFormat, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :DWORD, :D3DRESOURCETYPE, :D3DFORMAT
          STD_METHOD CheckDeviceMultiSampleType, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :BOOL, :D3DMULTISAMPLE_TYPE, :ptr DWORD
          STD_METHOD CheckDepthStencilMatch, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :D3DFORMAT, :D3DFORMAT
          STD_METHOD CheckDeviceFormatConversion, :THIS_, :D3DDEVTYPE, :D3DFORMAT, :D3DFORMAT
          STD_METHOD GetDeviceCaps, :THIS_, :D3DDEVTYPE, :ptr D3DCAPS9
          STD_METHOD GetAdapterMonitor, :THIS_
          STD_METHOD CreateDevice, :THIS_, :D3DDEVTYPE, :HWND, :DWORD, :ptr D3DPRESENT_PARAMETERS, :ptr ptr IDirect3DDevice9
          STD_METHOD GetAdapterModeCountEx, :THIS_, :ptr D3DDISPLAYMODEFILTER
          STD_METHOD EnumAdapterModesEx, :THIS_, :ptr D3DDISPLAYMODEFILTER, :UINT, :ptr D3DDISPLAYMODEEX
          STD_METHOD GetAdapterDisplayModeEx, :THIS_, :ptr D3DDISPLAYMODEEX, :ptr D3DDISPLAYROTATION
          STD_METHOD CreateDeviceEx, :THIS_, :D3DDEVTYPE, :HWND, :DWORD, :ptr D3DPRESENT_PARAMETERS, :ptr D3DDISPLAYMODEEX, :ptr ptr IDirect3DDevice9Ex
          STD_METHOD GetAdapterLUID, :THIS_, :ptr LUID
        END_DECLARE_INTERFACE_
        LPDIRECT3D9EX typedef ptr IDirect3D9Ex
        PDIRECT3D9EX typedef ptr IDirect3D9Ex
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3D9Ex_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3D9Ex_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3D9Ex_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3D9Ex_RegisterSoftwareDevice macro p, a
            exitm <(p) - lpVtbl - RegisterSoftwareDevice (p, a)>
          endm
          IDirect3D9Ex_GetAdapterCount macro p
            exitm <(p) - lpVtbl - GetAdapterCount (p)>
          endm
          IDirect3D9Ex_GetAdapterIdentifier macro p, a, b, c_
            exitm <(p) - lpVtbl - GetAdapterIdentifier (p, a, b, c_)>
          endm
          IDirect3D9Ex_GetAdapterModeCount macro p, a, b
            exitm <(p) - lpVtbl - GetAdapterModeCount (p, a, b)>
          endm
          IDirect3D9Ex_EnumAdapterModes macro p, a, b, c_, d
            exitm <(p) - lpVtbl - EnumAdapterModes (p, a, b, c_, d)>
          endm
          IDirect3D9Ex_GetAdapterDisplayMode macro p, a, b
            exitm <(p) - lpVtbl - GetAdapterDisplayMode (p, a, b)>
          endm
          IDirect3D9Ex_CheckDeviceType macro p, a, b, c_, d, e
            exitm <(p) - lpVtbl - CheckDeviceType (p, a, b, c_, d, e)>
          endm
          IDirect3D9Ex_CheckDeviceFormat macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - CheckDeviceFormat (p, a, b, c_, d, e, f)>
          endm
          IDirect3D9Ex_CheckDeviceMultiSampleType macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - CheckDeviceMultiSampleType (p, a, b, c_, d, e, f)>
          endm
          IDirect3D9Ex_CheckDepthStencilMatch macro p, a, b, c_, d, e
            exitm <(p) - lpVtbl - CheckDepthStencilMatch (p, a, b, c_, d, e)>
          endm
          IDirect3D9Ex_CheckDeviceFormatConversion macro p, a, b, c_, d
            exitm <(p) - lpVtbl - CheckDeviceFormatConversion (p, a, b, c_, d)>
          endm
          IDirect3D9Ex_GetDeviceCaps macro p, a, b, c_
            exitm <(p) - lpVtbl - GetDeviceCaps (p, a, b, c_)>
          endm
          IDirect3D9Ex_GetAdapterMonitor macro p, a
            exitm <(p) - lpVtbl - GetAdapterMonitor (p, a)>
          endm
          IDirect3D9Ex_CreateDevice macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - CreateDevice (p, a, b, c_, d, e, f)>
          endm
          IDirect3D9Ex_GetAdapterModeCountEx macro p, a, b
            exitm <(p) - lpVtbl - GetAdapterModeCountEx (p, a, b)>
          endm
          IDirect3D9Ex_EnumAdapterModesEx macro p, a, b, c_, d
            exitm <(p) - lpVtbl - EnumAdapterModesEx (p, a, b, c_, d)>
          endm
          IDirect3D9Ex_GetAdapterDisplayModeEx macro p, a, b, c_
            exitm <(p) - lpVtbl - GetAdapterDisplayModeEx (p, a, b, c_)>
          endm
          IDirect3D9Ex_CreateDeviceEx macro p, a, b, c_, d, e, f, g
            exitm <(p) - lpVtbl - CreateDeviceEx (p, a, b, c_, d, e, f, g)>
          endm
          IDirect3D9Ex_GetAdapterLUID macro p, a, b
            exitm <(p) - lpVtbl - GetAdapterLUID (p, a, b)>
          endm
        else
          ;[...]
        endif
        INTERFACE equ <IDirect3DDevice9Ex>
        DECLARE_INTERFACE_ IDirect3DDevice9Ex, IDirect3DDevice9
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD TestCooperativeLevel, :THIS_
          STD_METHOD GetAvailableTextureMem, :THIS_
          STD_METHOD EvictManagedResources, :THIS_
          STD_METHOD GetDirect3D, :ptr ptr THIS_
          STD_METHOD GetDeviceCaps, :ptr THIS_
          STD_METHOD GetDisplayMode, :THIS_, :ptr D3DDISPLAYMODE
          STD_METHOD GetCreationParameters, :ptr THIS_
          STD_METHOD SetCursorProperties, :THIS_, :UINT, :ptr IDirect3DSurface9
          STD_METHOD SetCursorPosition, :THIS_, :SDWORD, :DWORD
          STD_METHOD ShowCursor, :THIS_
          STD_METHOD CreateAdditionalSwapChain, :ptr THIS_, :ptr ptr IDirect3DSwapChain9
          STD_METHOD GetSwapChain, :THIS_, :ptr ptr IDirect3DSwapChain9
          STD_METHOD GetNumberOfSwapChains, :THIS_
          STD_METHOD Reset, :ptr THIS_
          STD_METHOD Present, :ptr THIS_, :ptr RECT, :HWND, :ptr RGNDATA
          STD_METHOD GetBackBuffer, :THIS_, :UINT, :D3DBACKBUFFER_TYPE, :ptr ptr IDirect3DSurface9
          STD_METHOD GetRasterStatus, :THIS_, :ptr D3DRASTER_STATUS
          STD_METHOD SetDialogBoxMode, :THIS_
          STD_METHOD SetGammaRamp, :THIS_, :DWORD, :ptr D3DGAMMARAMP
          STD_METHOD GetGammaRamp, :THIS_, :ptr D3DGAMMARAMP
          STD_METHOD CreateTexture, :THIS_, :UINT, :UINT, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DTexture9, :ptr HANDLE
          STD_METHOD CreateVolumeTexture, :THIS_, :UINT, :UINT, :UINT, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DVolumeTexture9, :ptr HANDLE
          STD_METHOD CreateCubeTexture, :THIS_, :UINT, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DCubeTexture9, :ptr HANDLE
          STD_METHOD CreateVertexBuffer, :THIS_, :DWORD, :DWORD, :D3DPOOL, :ptr ptr IDirect3DVertexBuffer9, :ptr HANDLE
          STD_METHOD CreateIndexBuffer, :THIS_, :DWORD, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DIndexBuffer9, :ptr HANDLE
          STD_METHOD CreateRenderTarget, :THIS_, :UINT, :D3DFORMAT, :D3DMULTISAMPLE_TYPE, :DWORD, :BOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE
          STD_METHOD CreateDepthStencilSurface, :THIS_, :UINT, :D3DFORMAT, :D3DMULTISAMPLE_TYPE, :DWORD, :BOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE
          STD_METHOD UpdateSurface, :ptr THIS_, :ptr RECT, :ptr IDirect3DSurface9, :ptr POINT
          STD_METHOD UpdateTexture, :ptr THIS_, :ptr IDirect3DBaseTexture9
          STD_METHOD GetRenderTargetData, :ptr THIS_, :ptr IDirect3DSurface9
          STD_METHOD GetFrontBufferData, :THIS_, :ptr IDirect3DSurface9
          STD_METHOD StretchRect, :ptr THIS_, :ptr RECT, :ptr IDirect3DSurface9, :ptr RECT, :D3DTEXTUREFILTERTYPE
          STD_METHOD ColorFill, :ptr THIS_, :ptr RECT, :D3DCOLOR
          STD_METHOD CreateOffscreenPlainSurface, :THIS_, :UINT, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE
          STD_METHOD SetRenderTarget, :THIS_, :ptr IDirect3DSurface9
          STD_METHOD GetRenderTarget, :THIS_, :ptr ptr IDirect3DSurface9
          STD_METHOD SetDepthStencilSurface, :ptr THIS_
          STD_METHOD GetDepthStencilSurface, :ptr ptr THIS_
          STD_METHOD BeginScene, :THIS_
          STD_METHOD EndScene, :THIS_
          STD_METHOD Clear, :THIS_, :ptr D3DRECT, :DWORD, :D3DCOLOR, :REAL4, :DWORD
          STD_METHOD SetTransform, :THIS_, :ptr D3DMATRIX
          STD_METHOD GetTransform, :THIS_, :ptr D3DMATRIX
          STD_METHOD MultiplyTransform, :THIS_, :ptr D3DMATRIX
          STD_METHOD SetViewport, :ptr THIS_
          STD_METHOD GetViewport, :ptr THIS_
          STD_METHOD SetMaterial, :ptr THIS_
          STD_METHOD GetMaterial, :ptr THIS_
          STD_METHOD SetLight, :THIS_, :ptr D3DLIGHT9
          STD_METHOD GetLight, :THIS_, :ptr D3DLIGHT9
          STD_METHOD LightEnable, :THIS_, :BOOL
          STD_METHOD GetLightEnable, :THIS_, :ptr BOOL
          STD_METHOD SetClipPlane, :THIS_, :ptr REAL4
          STD_METHOD GetClipPlane, :THIS_, :ptr REAL4
          STD_METHOD SetRenderState, :THIS_, :DWORD
          STD_METHOD GetRenderState, :THIS_, :ptr DWORD
          STD_METHOD CreateStateBlock, :THIS_, :ptr ptr IDirect3DStateBlock9
          STD_METHOD BeginStateBlock, :THIS_
          STD_METHOD EndStateBlock, :ptr ptr THIS_
          STD_METHOD SetClipStatus, :ptr THIS_
          STD_METHOD GetClipStatus, :ptr THIS_
          STD_METHOD GetTexture, :THIS_, :ptr ptr IDirect3DBaseTexture9
          STD_METHOD SetTexture, :THIS_, :ptr IDirect3DBaseTexture9
          STD_METHOD GetTextureStageState, :THIS_, :D3DTEXTURESTAGESTATETYPE, :ptr DWORD
          STD_METHOD SetTextureStageState, :THIS_, :D3DTEXTURESTAGESTATETYPE, :DWORD
          STD_METHOD GetSamplerState, :THIS_, :D3DSAMPLERSTATETYPE, :ptr DWORD
          STD_METHOD SetSamplerState, :THIS_, :D3DSAMPLERSTATETYPE, :DWORD
          STD_METHOD ValidateDevice, :ptr THIS_
          STD_METHOD SetPaletteEntries, :THIS_, :ptr PALETTEENTRY
          STD_METHOD GetPaletteEntries, :THIS_, :ptr PALETTEENTRY
          STD_METHOD SetCurrentTexturePalette, :THIS_
          STD_METHOD GetCurrentTexturePalette, :ptr THIS_
          STD_METHOD SetScissorRect, :ptr THIS_
          STD_METHOD GetScissorRect, :ptr THIS_
          STD_METHOD SetSoftwareVertexProcessing, :THIS_
          STD_METHOD GetSoftwareVertexProcessing, :THIS_
          STD_METHOD SetNPatchMode, :THIS_
          STD_METHOD GetNPatchMode, :THIS_
          STD_METHOD DrawPrimitive, :THIS_, :UINT, :UINT
          STD_METHOD DrawIndexedPrimitive, :THIS_, :INT_, :UINT, :UINT, :UINT, :UINT
          STD_METHOD DrawPrimitiveUP, :THIS_, :UINT, :ptr, :UINT
          STD_METHOD DrawIndexedPrimitiveUP, :THIS_, :UINT, :UINT, :UINT, :ptr, :D3DFORMAT, :ptr, :UINT
          STD_METHOD ProcessVertices, :THIS_, :UINT, :UINT, :ptr IDirect3DVertexBuffer9, :ptr IDirect3DVertexDeclaration9, :DWORD
          STD_METHOD CreateVertexDeclaration, :ptr THIS_, :ptr ptr IDirect3DVertexDeclaration9
          STD_METHOD SetVertexDeclaration, :ptr THIS_
          STD_METHOD GetVertexDeclaration, :ptr ptr THIS_
          STD_METHOD SetFVF, :THIS_
          STD_METHOD GetFVF, :ptr THIS_
          STD_METHOD CreateVertexShader, :ptr THIS_, :ptr ptr IDirect3DVertexShader9
          STD_METHOD SetVertexShader, :ptr THIS_
          STD_METHOD GetVertexShader, :ptr ptr THIS_
          STD_METHOD SetVertexShaderConstantF, :THIS_, :ptr REAL4, :UINT
          STD_METHOD GetVertexShaderConstantF, :THIS_, :ptr REAL4, :UINT
          STD_METHOD SetVertexShaderConstantI, :THIS_, :ptr SDWORD, :UINT
          STD_METHOD GetVertexShaderConstantI, :THIS_, :ptr SDWORD, :UINT
          STD_METHOD SetVertexShaderConstantB, :THIS_, :ptr BOOL, :UINT
          STD_METHOD GetVertexShaderConstantB, :THIS_, :ptr BOOL, :UINT
          STD_METHOD SetStreamSource, :THIS_, :ptr IDirect3DVertexBuffer9, :UINT, :UINT
          STD_METHOD GetStreamSource, :THIS_, :ptr ptr IDirect3DVertexBuffer9, :ptr UINT, :ptr UINT
          STD_METHOD SetStreamSourceFreq, :THIS_, :UINT
          STD_METHOD GetStreamSourceFreq, :THIS_, :ptr UINT
          STD_METHOD SetIndices, :ptr THIS_
          STD_METHOD GetIndices, :ptr ptr THIS_
          STD_METHOD CreatePixelShader, :ptr THIS_, :ptr ptr IDirect3DPixelShader9
          STD_METHOD SetPixelShader, :ptr THIS_
          STD_METHOD GetPixelShader, :ptr ptr THIS_
          STD_METHOD SetPixelShaderConstantF, :THIS_, :ptr REAL4, :UINT
          STD_METHOD GetPixelShaderConstantF, :THIS_, :ptr REAL4, :UINT
          STD_METHOD SetPixelShaderConstantI, :THIS_, :ptr SDWORD, :UINT
          STD_METHOD GetPixelShaderConstantI, :THIS_, :ptr SDWORD, :UINT
          STD_METHOD SetPixelShaderConstantB, :THIS_, :ptr BOOL, :UINT
          STD_METHOD GetPixelShaderConstantB, :THIS_, :ptr BOOL, :UINT
          STD_METHOD DrawRectPatch, :THIS_, :ptr REAL4, :ptr D3DRECTPATCH_INFO
          STD_METHOD DrawTriPatch, :THIS_, :ptr REAL4, :ptr D3DTRIPATCH_INFO
          STD_METHOD DeletePatch, :THIS_
          STD_METHOD CreateQuery, :THIS_, :ptr ptr IDirect3DQuery9
          STD_METHOD SetConvolutionMonoKernel, :THIS_, :UINT, :ptr REAL4, :ptr REAL4
          STD_METHOD ComposeRects, :ptr THIS_, :ptr IDirect3DSurface9, :ptr IDirect3DVertexBuffer9, :UINT, :ptr IDirect3DVertexBuffer9, :D3DCOMPOSERECTSOP, :SDWORD, :SDWORD
          STD_METHOD PresentEx, :ptr THIS_, :ptr RECT, :HWND, :ptr RGNDATA, :DWORD
          STD_METHOD GetGPUThreadPriority, :ptr THIS_
          STD_METHOD SetGPUThreadPriority, :THIS_
          STD_METHOD WaitForVBlank, :THIS_
          STD_METHOD CheckResourceResidency, :ptr ptr THIS_, :UINT32
          STD_METHOD SetMaximumFrameLatency, :THIS_
          STD_METHOD GetMaximumFrameLatency, :ptr THIS_
          STD_METHOD CheckDeviceState, :THIS_
          STD_METHOD CreateRenderTargetEx, :THIS_, :UINT, :D3DFORMAT, :D3DMULTISAMPLE_TYPE, :DWORD, :BOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE, :DWORD
          STD_METHOD CreateOffscreenPlainSurfaceEx, :THIS_, :UINT, :D3DFORMAT, :D3DPOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE, :DWORD
          STD_METHOD CreateDepthStencilSurfaceEx, :THIS_, :UINT, :D3DFORMAT, :D3DMULTISAMPLE_TYPE, :DWORD, :BOOL, :ptr ptr IDirect3DSurface9, :ptr HANDLE, :DWORD
          STD_METHOD ResetEx, :ptr THIS_, :ptr D3DDISPLAYMODEEX
          STD_METHOD GetDisplayModeEx, :THIS_, :ptr D3DDISPLAYMODEEX, :ptr D3DDISPLAYROTATION
        END_DECLARE_INTERFACE_
        LPDIRECT3DDEVICE9EX typedef ptr IDirect3DDevice9Ex
        PDIRECT3DDEVICE9EX typedef ptr IDirect3DDevice9Ex
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3DDevice9Ex_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3DDevice9Ex_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3DDevice9Ex_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3DDevice9Ex_TestCooperativeLevel macro p
            exitm <(p) - lpVtbl - TestCooperativeLevel (p)>
          endm
          IDirect3DDevice9Ex_GetAvailableTextureMem macro p
            exitm <(p) - lpVtbl - GetAvailableTextureMem (p)>
          endm
          IDirect3DDevice9Ex_EvictManagedResources macro p
            exitm <(p) - lpVtbl - EvictManagedResources (p)>
          endm
          IDirect3DDevice9Ex_GetDirect3D macro p, a
            exitm <(p) - lpVtbl - GetDirect3D (p, a)>
          endm
          IDirect3DDevice9Ex_GetDeviceCaps macro p, a
            exitm <(p) - lpVtbl - GetDeviceCaps (p, a)>
          endm
          IDirect3DDevice9Ex_GetDisplayMode macro p, a, b
            exitm <(p) - lpVtbl - GetDisplayMode (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetCreationParameters macro p, a
            exitm <(p) - lpVtbl - GetCreationParameters (p, a)>
          endm
          IDirect3DDevice9Ex_SetCursorProperties macro p, a, b, c_
            exitm <(p) - lpVtbl - SetCursorProperties (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetCursorPosition macro p, a, b, c_
            exitm <(p) - lpVtbl - SetCursorPosition (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_ShowCursor macro p, a
            exitm <(p) - lpVtbl - ShowCursor (p, a)>
          endm
          IDirect3DDevice9Ex_CreateAdditionalSwapChain macro p, a, b
            exitm <(p) - lpVtbl - CreateAdditionalSwapChain (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetSwapChain macro p, a, b
            exitm <(p) - lpVtbl - GetSwapChain (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetNumberOfSwapChains macro p
            exitm <(p) - lpVtbl - GetNumberOfSwapChains (p)>
          endm
          IDirect3DDevice9Ex_Reset macro p, a
            exitm <(p) - lpVtbl - Reset (p, a)>
          endm
          IDirect3DDevice9Ex_Present macro p, a, b, c_, d
            exitm <(p) - lpVtbl - Present (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_GetBackBuffer macro p, a, b, c_, d
            exitm <(p) - lpVtbl - GetBackBuffer (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_GetRasterStatus macro p, a, b
            exitm <(p) - lpVtbl - GetRasterStatus (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetDialogBoxMode macro p, a
            exitm <(p) - lpVtbl - SetDialogBoxMode (p, a)>
          endm
          IDirect3DDevice9Ex_SetGammaRamp macro p, a, b, c_
            exitm <(p) - lpVtbl - SetGammaRamp (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetGammaRamp macro p, a, b
            exitm <(p) - lpVtbl - GetGammaRamp (p, a, b)>
          endm
          IDirect3DDevice9Ex_CreateTexture macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - CreateTexture (p, a, b, c_, d, e, f, g, h)>
          endm
          IDirect3DDevice9Ex_CreateVolumeTexture macro p, a, b, c_, d, e, f, g, h, i
            exitm <(p) - lpVtbl - CreateVolumeTexture (p, a, b, c_, d, e, f, g, h, i)>
          endm
          IDirect3DDevice9Ex_CreateCubeTexture macro p, a, b, c_, d, e, f, g
            exitm <(p) - lpVtbl - CreateCubeTexture (p, a, b, c_, d, e, f, g)>
          endm
          IDirect3DDevice9Ex_CreateVertexBuffer macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - CreateVertexBuffer (p, a, b, c_, d, e, f)>
          endm
          IDirect3DDevice9Ex_CreateIndexBuffer macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - CreateIndexBuffer (p, a, b, c_, d, e, f)>
          endm
          IDirect3DDevice9Ex_CreateRenderTarget macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - CreateRenderTarget (p, a, b, c_, d, e, f, g, h)>
          endm
          IDirect3DDevice9Ex_CreateDepthStencilSurface macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - CreateDepthStencilSurface (p, a, b, c_, d, e, f, g, h)>
          endm
          IDirect3DDevice9Ex_UpdateSurface macro p, a, b, c_, d
            exitm <(p) - lpVtbl - UpdateSurface (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_UpdateTexture macro p, a, b
            exitm <(p) - lpVtbl - UpdateTexture (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetRenderTargetData macro p, a, b
            exitm <(p) - lpVtbl - GetRenderTargetData (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetFrontBufferData macro p, a, b
            exitm <(p) - lpVtbl - GetFrontBufferData (p, a, b)>
          endm
          IDirect3DDevice9Ex_StretchRect macro p, a, b, c_, d, e
            exitm <(p) - lpVtbl - StretchRect (p, a, b, c_, d, e)>
          endm
          IDirect3DDevice9Ex_ColorFill macro p, a, b, c_
            exitm <(p) - lpVtbl - ColorFill (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_CreateOffscreenPlainSurface macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - CreateOffscreenPlainSurface (p, a, b, c_, d, e, f)>
          endm
          IDirect3DDevice9Ex_SetRenderTarget macro p, a, b
            exitm <(p) - lpVtbl - SetRenderTarget (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetRenderTarget macro p, a, b
            exitm <(p) - lpVtbl - GetRenderTarget (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetDepthStencilSurface macro p, a
            exitm <(p) - lpVtbl - SetDepthStencilSurface (p, a)>
          endm
          IDirect3DDevice9Ex_GetDepthStencilSurface macro p, a
            exitm <(p) - lpVtbl - GetDepthStencilSurface (p, a)>
          endm
          IDirect3DDevice9Ex_BeginScene macro p
            exitm <(p) - lpVtbl - BeginScene (p)>
          endm
          IDirect3DDevice9Ex_EndScene macro p
            exitm <(p) - lpVtbl - EndScene (p)>
          endm
          IDirect3DDevice9Ex_Clear macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - Clear (p, a, b, c_, d, e, f)>
          endm
          IDirect3DDevice9Ex_SetTransform macro p, a, b
            exitm <(p) - lpVtbl - SetTransform (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetTransform macro p, a, b
            exitm <(p) - lpVtbl - GetTransform (p, a, b)>
          endm
          IDirect3DDevice9Ex_MultiplyTransform macro p, a, b
            exitm <(p) - lpVtbl - MultiplyTransform (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetViewport macro p, a
            exitm <(p) - lpVtbl - SetViewport (p, a)>
          endm
          IDirect3DDevice9Ex_GetViewport macro p, a
            exitm <(p) - lpVtbl - GetViewport (p, a)>
          endm
          IDirect3DDevice9Ex_SetMaterial macro p, a
            exitm <(p) - lpVtbl - SetMaterial (p, a)>
          endm
          IDirect3DDevice9Ex_GetMaterial macro p, a
            exitm <(p) - lpVtbl - GetMaterial (p, a)>
          endm
          IDirect3DDevice9Ex_SetLight macro p, a, b
            exitm <(p) - lpVtbl - SetLight (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetLight macro p, a, b
            exitm <(p) - lpVtbl - GetLight (p, a, b)>
          endm
          IDirect3DDevice9Ex_LightEnable macro p, a, b
            exitm <(p) - lpVtbl - LightEnable (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetLightEnable macro p, a, b
            exitm <(p) - lpVtbl - GetLightEnable (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetClipPlane macro p, a, b
            exitm <(p) - lpVtbl - SetClipPlane (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetClipPlane macro p, a, b
            exitm <(p) - lpVtbl - GetClipPlane (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetRenderState macro p, a, b
            exitm <(p) - lpVtbl - SetRenderState (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetRenderState macro p, a, b
            exitm <(p) - lpVtbl - GetRenderState (p, a, b)>
          endm
          IDirect3DDevice9Ex_CreateStateBlock macro p, a, b
            exitm <(p) - lpVtbl - CreateStateBlock (p, a, b)>
          endm
          IDirect3DDevice9Ex_BeginStateBlock macro p
            exitm <(p) - lpVtbl - BeginStateBlock (p)>
          endm
          IDirect3DDevice9Ex_EndStateBlock macro p, a
            exitm <(p) - lpVtbl - EndStateBlock (p, a)>
          endm
          IDirect3DDevice9Ex_SetClipStatus macro p, a
            exitm <(p) - lpVtbl - SetClipStatus (p, a)>
          endm
          IDirect3DDevice9Ex_GetClipStatus macro p, a
            exitm <(p) - lpVtbl - GetClipStatus (p, a)>
          endm
          IDirect3DDevice9Ex_GetTexture macro p, a, b
            exitm <(p) - lpVtbl - GetTexture (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetTexture macro p, a, b
            exitm <(p) - lpVtbl - SetTexture (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetTextureStageState macro p, a, b, c_
            exitm <(p) - lpVtbl - GetTextureStageState (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetTextureStageState macro p, a, b, c_
            exitm <(p) - lpVtbl - SetTextureStageState (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetSamplerState macro p, a, b, c_
            exitm <(p) - lpVtbl - GetSamplerState (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetSamplerState macro p, a, b, c_
            exitm <(p) - lpVtbl - SetSamplerState (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_ValidateDevice macro p, a
            exitm <(p) - lpVtbl - ValidateDevice (p, a)>
          endm
          IDirect3DDevice9Ex_SetPaletteEntries macro p, a, b
            exitm <(p) - lpVtbl - SetPaletteEntries (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetPaletteEntries macro p, a, b
            exitm <(p) - lpVtbl - GetPaletteEntries (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetCurrentTexturePalette macro p, a
            exitm <(p) - lpVtbl - SetCurrentTexturePalette (p, a)>
          endm
          IDirect3DDevice9Ex_GetCurrentTexturePalette macro p, a
            exitm <(p) - lpVtbl - GetCurrentTexturePalette (p, a)>
          endm
          IDirect3DDevice9Ex_SetScissorRect macro p, a
            exitm <(p) - lpVtbl - SetScissorRect (p, a)>
          endm
          IDirect3DDevice9Ex_GetScissorRect macro p, a
            exitm <(p) - lpVtbl - GetScissorRect (p, a)>
          endm
          IDirect3DDevice9Ex_SetSoftwareVertexProcessing macro p, a
            exitm <(p) - lpVtbl - SetSoftwareVertexProcessing (p, a)>
          endm
          IDirect3DDevice9Ex_GetSoftwareVertexProcessing macro p
            exitm <(p) - lpVtbl - GetSoftwareVertexProcessing (p)>
          endm
          IDirect3DDevice9Ex_SetNPatchMode macro p, a
            exitm <(p) - lpVtbl - SetNPatchMode (p, a)>
          endm
          IDirect3DDevice9Ex_GetNPatchMode macro p
            exitm <(p) - lpVtbl - GetNPatchMode (p)>
          endm
          IDirect3DDevice9Ex_DrawPrimitive macro p, a, b, c_
            exitm <(p) - lpVtbl - DrawPrimitive (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_DrawIndexedPrimitive macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - DrawIndexedPrimitive (p, a, b, c_, d, e, f)>
          endm
          IDirect3DDevice9Ex_DrawPrimitiveUP macro p, a, b, c_, d
            exitm <(p) - lpVtbl - DrawPrimitiveUP (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_DrawIndexedPrimitiveUP macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - DrawIndexedPrimitiveUP (p, a, b, c_, d, e, f, g, h)>
          endm
          IDirect3DDevice9Ex_ProcessVertices macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - ProcessVertices (p, a, b, c_, d, e, f)>
          endm
          IDirect3DDevice9Ex_CreateVertexDeclaration macro p, a, b
            exitm <(p) - lpVtbl - CreateVertexDeclaration (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetVertexDeclaration macro p, a
            exitm <(p) - lpVtbl - SetVertexDeclaration (p, a)>
          endm
          IDirect3DDevice9Ex_GetVertexDeclaration macro p, a
            exitm <(p) - lpVtbl - GetVertexDeclaration (p, a)>
          endm
          IDirect3DDevice9Ex_SetFVF macro p, a
            exitm <(p) - lpVtbl - SetFVF (p, a)>
          endm
          IDirect3DDevice9Ex_GetFVF macro p, a
            exitm <(p) - lpVtbl - GetFVF (p, a)>
          endm
          IDirect3DDevice9Ex_CreateVertexShader macro p, a, b
            exitm <(p) - lpVtbl - CreateVertexShader (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetVertexShader macro p, a
            exitm <(p) - lpVtbl - SetVertexShader (p, a)>
          endm
          IDirect3DDevice9Ex_GetVertexShader macro p, a
            exitm <(p) - lpVtbl - GetVertexShader (p, a)>
          endm
          IDirect3DDevice9Ex_SetVertexShaderConstantF macro p, a, b, c_
            exitm <(p) - lpVtbl - SetVertexShaderConstantF (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetVertexShaderConstantF macro p, a, b, c_
            exitm <(p) - lpVtbl - GetVertexShaderConstantF (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetVertexShaderConstantI macro p, a, b, c_
            exitm <(p) - lpVtbl - SetVertexShaderConstantI (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetVertexShaderConstantI macro p, a, b, c_
            exitm <(p) - lpVtbl - GetVertexShaderConstantI (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetVertexShaderConstantB macro p, a, b, c_
            exitm <(p) - lpVtbl - SetVertexShaderConstantB (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetVertexShaderConstantB macro p, a, b, c_
            exitm <(p) - lpVtbl - GetVertexShaderConstantB (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetStreamSource macro p, a, b, c_, d
            exitm <(p) - lpVtbl - SetStreamSource (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_GetStreamSource macro p, a, b, c_, d
            exitm <(p) - lpVtbl - GetStreamSource (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_SetStreamSourceFreq macro p, a, b
            exitm <(p) - lpVtbl - SetStreamSourceFreq (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetStreamSourceFreq macro p, a, b
            exitm <(p) - lpVtbl - GetStreamSourceFreq (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetIndices macro p, a
            exitm <(p) - lpVtbl - SetIndices (p, a)>
          endm
          IDirect3DDevice9Ex_GetIndices macro p, a
            exitm <(p) - lpVtbl - GetIndices (p, a)>
          endm
          IDirect3DDevice9Ex_CreatePixelShader macro p, a, b
            exitm <(p) - lpVtbl - CreatePixelShader (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetPixelShader macro p, a
            exitm <(p) - lpVtbl - SetPixelShader (p, a)>
          endm
          IDirect3DDevice9Ex_GetPixelShader macro p, a
            exitm <(p) - lpVtbl - GetPixelShader (p, a)>
          endm
          IDirect3DDevice9Ex_SetPixelShaderConstantF macro p, a, b, c_
            exitm <(p) - lpVtbl - SetPixelShaderConstantF (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetPixelShaderConstantF macro p, a, b, c_
            exitm <(p) - lpVtbl - GetPixelShaderConstantF (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetPixelShaderConstantI macro p, a, b, c_
            exitm <(p) - lpVtbl - SetPixelShaderConstantI (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetPixelShaderConstantI macro p, a, b, c_
            exitm <(p) - lpVtbl - GetPixelShaderConstantI (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_SetPixelShaderConstantB macro p, a, b, c_
            exitm <(p) - lpVtbl - SetPixelShaderConstantB (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_GetPixelShaderConstantB macro p, a, b, c_
            exitm <(p) - lpVtbl - GetPixelShaderConstantB (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_DrawRectPatch macro p, a, b, c_
            exitm <(p) - lpVtbl - DrawRectPatch (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_DrawTriPatch macro p, a, b, c_
            exitm <(p) - lpVtbl - DrawTriPatch (p, a, b, c_)>
          endm
          IDirect3DDevice9Ex_DeletePatch macro p, a
            exitm <(p) - lpVtbl - DeletePatch (p, a)>
          endm
          IDirect3DDevice9Ex_CreateQuery macro p, a, b
            exitm <(p) - lpVtbl - CreateQuery (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetConvolutionMonoKernel macro p, a, b, c_, d
            exitm <(p) - lpVtbl - SetConvolutionMonoKernel (p, a, b, c_, d)>
          endm
          IDirect3DDevice9Ex_ComposeRects macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - ComposeRects (p, a, b, c_, d, e, f, g, h)>
          endm
          IDirect3DDevice9Ex_PresentEx macro p, a, b, c_, d, e
            exitm <(p) - lpVtbl - PresentEx (p, a, b, c_, d, e)>
          endm
          IDirect3DDevice9Ex_GetGPUThreadPriority macro p, a
            exitm <(p) - lpVtbl - GetGPUThreadPriority (p, a)>
          endm
          IDirect3DDevice9Ex_SetGPUThreadPriority macro p, a
            exitm <(p) - lpVtbl - SetGPUThreadPriority (p, a)>
          endm
          IDirect3DDevice9Ex_WaitForVBlank macro p, a
            exitm <(p) - lpVtbl - WaitForVBlank (p, a)>
          endm
          IDirect3DDevice9Ex_CheckResourceResidency macro p, a, b
            exitm <(p) - lpVtbl - CheckResourceResidency (p, a, b)>
          endm
          IDirect3DDevice9Ex_SetMaximumFrameLatency macro p, a
            exitm <(p) - lpVtbl - SetMaximumFrameLatency (p, a)>
          endm
          IDirect3DDevice9Ex_GetMaximumFrameLatency macro p, a
            exitm <(p) - lpVtbl - GetMaximumFrameLatency (p, a)>
          endm
          IDirect3DDevice9Ex_CheckDeviceState macro p, a
            exitm <(p) - lpVtbl - CheckDeviceState (p, a)>
          endm
          IDirect3DDevice9Ex_CreateRenderTargetEx macro p, a, b, c_, d, e, f, g, h, i
            exitm <(p) - lpVtbl - CreateRenderTargetEx (p, a, b, c_, d, e, f, g, h, i)>
          endm
          IDirect3DDevice9Ex_CreateOffscreenPlainSurfaceEx macro p, a, b, c_, d, e, f, g
            exitm <(p) - lpVtbl - CreateOffscreenPlainSurfaceEx (p, a, b, c_, d, e, f, g)>
          endm
          IDirect3DDevice9Ex_CreateDepthStencilSurfaceEx macro p, a, b, c_, d, e, f, g, h, i
            exitm <(p) - lpVtbl - CreateDepthStencilSurfaceEx (p, a, b, c_, d, e, f, g, h, i)>
          endm
          IDirect3DDevice9Ex_ResetEx macro p, a, b
            exitm <(p) - lpVtbl - ResetEx (p, a, b)>
          endm
          IDirect3DDevice9Ex_GetDisplayModeEx macro p, a, b, c_
            exitm <(p) - lpVtbl - GetDisplayModeEx (p, a, b, c_)>
          endm
        else
          ;[...]
        endif
        INTERFACE equ <IDirect3DSwapChain9Ex>
        DECLARE_INTERFACE_ IDirect3DSwapChain9Ex, IDirect3DSwapChain9
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD Present, :ptr THIS_, :ptr RECT, :HWND, :ptr RGNDATA, :DWORD
          STD_METHOD GetFrontBufferData, :ptr THIS_
          STD_METHOD GetBackBuffer, :THIS_, :D3DBACKBUFFER_TYPE, :ptr ptr IDirect3DSurface9
          STD_METHOD GetRasterStatus, :ptr THIS_
          STD_METHOD GetDisplayMode, :ptr THIS_
          STD_METHOD GetDevice, :ptr ptr THIS_
          STD_METHOD GetPresentParameters, :ptr THIS_
          STD_METHOD GetLastPresentCount, :ptr THIS_
          STD_METHOD GetPresentStats, :ptr THIS_
          STD_METHOD GetDisplayModeEx, :ptr THIS_, :ptr D3DDISPLAYROTATION
        END_DECLARE_INTERFACE_
        LPDIRECT3DSWAPCHAIN9EX typedef ptr IDirect3DSwapChain9Ex
        PDIRECT3DSWAPCHAIN9EX typedef ptr IDirect3DSwapChain9Ex
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3DSwapChain9Ex_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3DSwapChain9Ex_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3DSwapChain9Ex_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3DSwapChain9Ex_Present macro p, a, b, c_, d, e
            exitm <(p) - lpVtbl - Present (p, a, b, c_, d, e)>
          endm
          IDirect3DSwapChain9Ex_GetFrontBufferData macro p, a
            exitm <(p) - lpVtbl - GetFrontBufferData (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetBackBuffer macro p, a, b, c_
            exitm <(p) - lpVtbl - GetBackBuffer (p, a, b, c_)>
          endm
          IDirect3DSwapChain9Ex_GetRasterStatus macro p, a
            exitm <(p) - lpVtbl - GetRasterStatus (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetDisplayMode macro p, a
            exitm <(p) - lpVtbl - GetDisplayMode (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetDevice macro p, a
            exitm <(p) - lpVtbl - GetDevice (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetPresentParameters macro p, a
            exitm <(p) - lpVtbl - GetPresentParameters (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetLastPresentCount macro p, a
            exitm <(p) - lpVtbl - GetLastPresentCount (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetPresentStats macro p, a
            exitm <(p) - lpVtbl - GetPresentStats (p, a)>
          endm
          IDirect3DSwapChain9Ex_GetDisplayModeEx macro p, a, b
            exitm <(p) - lpVtbl - GetDisplayModeEx (p, a, b)>
          endm
        else
          ;[...]
        endif
      endif
      if  not Defined(D3D_DISABLE_9EX)
        INTERFACE equ <IDirect3D9ExOverlayExtension>
        DECLARE_INTERFACE_ IDirect3D9ExOverlayExtension, IUnknown
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD CheckDeviceOverlayType, :THIS_, :D3DDEVTYPE, :UINT, :UINT, :D3DFORMAT, :ptr D3DDISPLAYMODEEX, :D3DDISPLAYROTATION, :ptr D3DOVERLAYCAPS
        END_DECLARE_INTERFACE_
        LPDIRECT3D9EXOVERLAYEXTENSION typedef ptr IDirect3D9ExOverlayExtension
        PDIRECT3D9EXOVERLAYEXTENSION typedef ptr IDirect3D9ExOverlayExtension
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3D9ExOverlayExtension_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3D9ExOverlayExtension_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3D9ExOverlayExtension_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3D9ExOverlayExtension_CheckDeviceOverlayType macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - CheckDeviceOverlayType (p, a, b, c_, d, e, f, g, h)>
          endm
        else
          ;[...]
        endif
        INTERFACE equ <IDirect3DDevice9Video>
        DECLARE_INTERFACE_ IDirect3DDevice9Video, IUnknown
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD GetContentProtectionCaps, :ptr THIS_, :ptr GUID, :ptr D3DCONTENTPROTECTIONCAPS
          STD_METHOD CreateAuthenticatedChannel, :THIS_, :ptr ptr IDirect3DAuthenticatedChannel9, :ptr HANDLE
          STD_METHOD CreateCryptoSession, :ptr THIS_, :ptr GUID, :ptr ptr IDirect3DCryptoSession9, :ptr HANDLE
        END_DECLARE_INTERFACE_
        LPDIRECT3DDEVICE9VIDEO typedef ptr IDirect3DDevice9Video
        PDIRECT3DDEVICE9VIDEO typedef ptr IDirect3DDevice9Video
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3DDevice9Video_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3DDevice9Video_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3DDevice9Video_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3DDevice9Video_GetContentProtectionCaps macro p, a, b, c_
            exitm <(p) - lpVtbl - GetContentProtectionCaps (p, a, b, c_)>
          endm
          IDirect3DDevice9Video_CreateAuthenticatedChannel macro p, a, b, c_
            exitm <(p) - lpVtbl - CreateAuthenticatedChannel (p, a, b, c_)>
          endm
          IDirect3DDevice9Video_CreateCryptoSession macro p, a, b, c_, d
            exitm <(p) - lpVtbl - CreateCryptoSession (p, a, b, c_, d)>
          endm
        else
          ;[...]
        endif
        INTERFACE equ <IDirect3DAuthenticatedChannel9>
        DECLARE_INTERFACE_ IDirect3DAuthenticatedChannel9, IUnknown
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD GetCertificateSize, :ptr THIS_
          STD_METHOD GetCertificate, :THIS_, :ptr BYTE
          STD_METHOD NegotiateKeyExchange, :THIS_, :ptr VOID
          STD_METHOD Query, :THIS_, :ptr VOID, :UINT, :ptr VOID
          STD_METHOD Configure, :THIS_, :ptr VOID, :ptr D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT
        END_DECLARE_INTERFACE_
        LPDIRECT3DAUTHENTICATEDCHANNEL9 typedef ptr IDirect3DAuthenticatedChannel9
        PDIRECT3DAUTHENTICATEDCHANNEL9 typedef ptr IDirect3DAuthenticatedChannel9
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3DAuthenticatedChannel9_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3DAuthenticatedChannel9_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3DAuthenticatedChannel9_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3DAuthenticatedChannel9_GetCertificateSize macro p, a
            exitm <(p) - lpVtbl - GetCertificateSize (p, a)>
          endm
          IDirect3DAuthenticatedChannel9_GetCertificate macro p, a, b
            exitm <(p) - lpVtbl - GetCertificate (p, a, b)>
          endm
          IDirect3DAuthenticatedChannel9_NegotiateKeyExchange macro p, a, b
            exitm <(p) - lpVtbl - NegotiateKeyExchange (p, a, b)>
          endm
          IDirect3DAuthenticatedChannel9_Query macro p, a, b, c_, d
            exitm <(p) - lpVtbl - Query (p, a, b, c_, d)>
          endm
          IDirect3DAuthenticatedChannel9_Configure macro p, a, b, c_
            exitm <(p) - lpVtbl - Configure (p, a, b, c_)>
          endm
        else
          ;[...]
        endif
        INTERFACE equ <IDirect3DCryptoSession9>
        DECLARE_INTERFACE_ IDirect3DCryptoSession9, IUnknown
          STD_METHOD QueryInterface, :THIS_, :ptr ptr
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD GetCertificateSize, :ptr THIS_
          STD_METHOD GetCertificate, :THIS_, :ptr BYTE
          STD_METHOD NegotiateKeyExchange, :THIS_, :ptr VOID
          STD_METHOD EncryptionBlt, :ptr THIS_, :ptr IDirect3DSurface9, :UINT, :ptr VOID
          STD_METHOD DecryptionBlt, :ptr THIS_, :ptr IDirect3DSurface9, :UINT, :ptr D3DENCRYPTED_BLOCK_INFO, :ptr VOID, :ptr VOID
          STD_METHOD GetSurfacePitch, :ptr THIS_, :ptr UINT
          STD_METHOD StartSessionKeyRefresh, :ptr THIS_, :UINT
          STD_METHOD FinishSessionKeyRefresh, :THIS_
          STD_METHOD GetEncryptionBltKey, :ptr THIS_, :UINT
        END_DECLARE_INTERFACE_
        LPDIRECT3DCRYPTOSESSION9 typedef ptr IDirect3DCryptoSession9
        PDIRECT3DCRYPTOSESSION9 typedef ptr IDirect3DCryptoSession9
        
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirect3DCryptoSession9_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirect3DCryptoSession9_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirect3DCryptoSession9_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirect3DCryptoSession9_GetCertificateSize macro p, a
            exitm <(p) - lpVtbl - GetCertificateSize (p, a)>
          endm
          IDirect3DCryptoSession9_GetCertificate macro p, a, b
            exitm <(p) - lpVtbl - GetCertificate (p, a, b)>
          endm
          IDirect3DCryptoSession9_NegotiateKeyExchange macro p, a, b
            exitm <(p) - lpVtbl - NegotiateKeyExchange (p, a, b)>
          endm
          IDirect3DCryptoSession9_EncryptionBlt macro p, a, b, c_, d
            exitm <(p) - lpVtbl - EncryptionBlt (p, a, b, c_, d)>
          endm
          IDirect3DCryptoSession9_DecryptionBlt macro p, a, b, c_, d, e, f
            exitm <(p) - lpVtbl - DecryptionBlt (p, a, b, c_, d, e, f)>
          endm
          IDirect3DCryptoSession9_GetSurfacePitch macro p, a, b
            exitm <(p) - lpVtbl - GetSurfacePitch (p, a, b)>
          endm
          IDirect3DCryptoSession9_StartSessionKeyRefresh macro p, a, b
            exitm <(p) - lpVtbl - StartSessionKeyRefresh (p, a, b)>
          endm
          IDirect3DCryptoSession9_FinishSessionKeyRefresh macro p
            exitm <(p) - lpVtbl - FinishSessionKeyRefresh (p)>
          endm
          IDirect3DCryptoSession9_GetEncryptionBltKey macro p, a, b
            exitm <(p) - lpVtbl - GetEncryptionBltKey (p, a, b)>
          endm
        else
          ;[...]
        endif
      endif
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
endif

