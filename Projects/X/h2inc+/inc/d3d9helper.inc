;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\d3d9helper.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 16/12/2023 11:07:08

ifndef _D3D9_H_
  _D3D9_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef DIRECT3D_VERSION
      DIRECT3D_VERSION equ 0900h
    endif
    if (DIRECT3D_VERSION ge 0900h)
      D3D_SDK_VERSION equ (31 or 80000000h)
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
      endif
      ifdef __cplusplus
        ;[...]
      endif
      include d3d9types.inc
      include d3d9caps.inc
      ifdef __cplusplus
        ;[...]
      endif
      Direct3DCreate9 proto WIN_STD_CALL_CONV :UINT
      INTERFACE equ <IDirect3D9>
      DECLARE_INTERFACE_(IDirect3D9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD RegisterSoftwareDevice, :ptr 
        STDMETHOD_ UINT, GetAdapterCount
        STDMETHOD GetAdapterIdentifier, :, :, :ptr 
        STDMETHOD_ UINT, GetAdapterModeCount, :, :
        STDMETHOD EnumAdapterModes, :, :, :, :ptr 
        STDMETHOD GetAdapterDisplayMode, :, :ptr 
        STDMETHOD CheckDeviceType, :, :, :, :, :
        STDMETHOD CheckDeviceFormat, :, :, :, :, :, :
        STDMETHOD CheckDeviceMultiSampleType, :, :, :, :, :, :ptr 
        STDMETHOD CheckDepthStencilMatch, :, :, :, :, :
        STDMETHOD CheckDeviceFormatConversion, :, :, :, :
        STDMETHOD GetDeviceCaps, :, :, :ptr 
        STDMETHOD_ HMONITOR, GetAdapterMonitor, :
        STDMETHOD CreateDevice, :, :, :, :, :ptr , :ptr ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DDevice9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD TestCooperativeLevel
        STDMETHOD_ UINT, GetAvailableTextureMem
        STDMETHOD EvictManagedResources
        STDMETHOD GetDirect3D, :ptr ptr 
        STDMETHOD GetDeviceCaps, :ptr 
        STDMETHOD GetDisplayMode, :, :ptr 
        STDMETHOD GetCreationParameters, :ptr 
        STDMETHOD SetCursorProperties, :, :, :ptr 
        STDMETHOD_ void, SetCursorPosition, :, :, :
        STDMETHOD_ BOOL, ShowCursor, :
        STDMETHOD CreateAdditionalSwapChain, :ptr , :ptr ptr 
        STDMETHOD GetSwapChain, :, :ptr ptr 
        STDMETHOD_ UINT, GetNumberOfSwapChains
        STDMETHOD Reset, :ptr 
        STDMETHOD Present, :ptr , :ptr , :, :ptr 
        STDMETHOD GetBackBuffer, :, :, :, :ptr ptr 
        STDMETHOD GetRasterStatus, :, :ptr 
        STDMETHOD SetDialogBoxMode, :
        STDMETHOD_ void, SetGammaRamp, :, :, :ptr 
        STDMETHOD_ void, GetGammaRamp, :, :ptr 
        STDMETHOD CreateTexture, :, :, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD CreateVolumeTexture, :, :, :, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD CreateCubeTexture, :, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD CreateVertexBuffer, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD CreateIndexBuffer, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD CreateRenderTarget, :, :, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD CreateDepthStencilSurface, :, :, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD UpdateSurface, :ptr , :ptr , :ptr , :ptr 
        STDMETHOD UpdateTexture, :ptr , :ptr 
        STDMETHOD GetRenderTargetData, :ptr , :ptr 
        STDMETHOD GetFrontBufferData, :, :ptr 
        STDMETHOD StretchRect, :ptr , :ptr , :ptr , :ptr , :
        STDMETHOD ColorFill, :ptr , :ptr , :
        STDMETHOD CreateOffscreenPlainSurface, :, :, :, :, :ptr ptr , :ptr 
        STDMETHOD SetRenderTarget, :, :ptr 
        STDMETHOD GetRenderTarget, :, :ptr ptr 
        STDMETHOD SetDepthStencilSurface, :ptr 
        STDMETHOD GetDepthStencilSurface, :ptr ptr 
        STDMETHOD BeginScene
        STDMETHOD EndScene
        STDMETHOD Clear, :, :ptr , :, :, :, :
        STDMETHOD SetTransform, :, :ptr 
        STDMETHOD GetTransform, :, :ptr 
        STDMETHOD MultiplyTransform, :, :ptr 
        STDMETHOD SetViewport, :ptr 
        STDMETHOD GetViewport, :ptr 
        STDMETHOD SetMaterial, :ptr 
        STDMETHOD GetMaterial, :ptr 
        STDMETHOD SetLight, :, :ptr 
        STDMETHOD GetLight, :, :ptr 
        STDMETHOD LightEnable, :, :
        STDMETHOD GetLightEnable, :, :ptr 
        STDMETHOD SetClipPlane, :, :ptr 
        STDMETHOD GetClipPlane, :, :ptr 
        STDMETHOD SetRenderState, :, :
        STDMETHOD GetRenderState, :, :ptr 
        STDMETHOD CreateStateBlock, :, :ptr ptr 
        STDMETHOD BeginStateBlock
        STDMETHOD EndStateBlock, :ptr ptr 
        STDMETHOD SetClipStatus, :ptr 
        STDMETHOD GetClipStatus, :ptr 
        STDMETHOD GetTexture, :, :ptr ptr 
        STDMETHOD SetTexture, :, :ptr 
        STDMETHOD GetTextureStageState, :, :, :ptr 
        STDMETHOD SetTextureStageState, :, :, :
        STDMETHOD GetSamplerState, :, :, :ptr 
        STDMETHOD SetSamplerState, :, :, :
        STDMETHOD ValidateDevice, :ptr 
        STDMETHOD SetPaletteEntries, :, :ptr 
        STDMETHOD GetPaletteEntries, :, :ptr 
        STDMETHOD SetCurrentTexturePalette, :
        STDMETHOD GetCurrentTexturePalette, :ptr 
        STDMETHOD SetScissorRect, :ptr 
        STDMETHOD GetScissorRect, :ptr 
        STDMETHOD SetSoftwareVertexProcessing, :
        STDMETHOD_ BOOL, GetSoftwareVertexProcessing
        STDMETHOD SetNPatchMode, :
        STDMETHOD_ float, GetNPatchMode
        STDMETHOD DrawPrimitive, :, :, :
        STDMETHOD DrawIndexedPrimitive, :, :, :, :, :, :
        STDMETHOD DrawPrimitiveUP, :, :, :ptr , :
        STDMETHOD DrawIndexedPrimitiveUP, :, :, :, :, :ptr , :, :ptr , :
        STDMETHOD ProcessVertices, :, :, :, :ptr , :ptr , :
        STDMETHOD CreateVertexDeclaration, :ptr , :ptr ptr 
        STDMETHOD SetVertexDeclaration, :ptr 
        STDMETHOD GetVertexDeclaration, :ptr ptr 
        STDMETHOD SetFVF, :
        STDMETHOD GetFVF, :ptr 
        STDMETHOD CreateVertexShader, :ptr , :ptr ptr 
        STDMETHOD SetVertexShader, :ptr 
        STDMETHOD GetVertexShader, :ptr ptr 
        STDMETHOD SetVertexShaderConstantF, :, :ptr , :
        STDMETHOD GetVertexShaderConstantF, :, :ptr , :
        STDMETHOD SetVertexShaderConstantI, :, :ptr , :
        STDMETHOD GetVertexShaderConstantI, :, :ptr , :
        STDMETHOD SetVertexShaderConstantB, :, :ptr , :
        STDMETHOD GetVertexShaderConstantB, :, :ptr , :
        STDMETHOD SetStreamSource, :, :ptr , :, :
        STDMETHOD GetStreamSource, :, :ptr ptr , :ptr , :ptr 
        STDMETHOD SetStreamSourceFreq, :, :
        STDMETHOD GetStreamSourceFreq, :, :ptr 
        STDMETHOD SetIndices, :ptr 
        STDMETHOD GetIndices, :ptr ptr 
        STDMETHOD CreatePixelShader, :ptr , :ptr ptr 
        STDMETHOD SetPixelShader, :ptr 
        STDMETHOD GetPixelShader, :ptr ptr 
        STDMETHOD SetPixelShaderConstantF, :, :ptr , :
        STDMETHOD GetPixelShaderConstantF, :, :ptr , :
        STDMETHOD SetPixelShaderConstantI, :, :ptr , :
        STDMETHOD GetPixelShaderConstantI, :, :ptr , :
        STDMETHOD SetPixelShaderConstantB, :, :ptr , :
        STDMETHOD GetPixelShaderConstantB, :, :ptr , :
        STDMETHOD DrawRectPatch, :, :ptr , :ptr 
        STDMETHOD DrawTriPatch, :, :ptr , :ptr 
        STDMETHOD DeletePatch, :
        STDMETHOD CreateQuery, :, :ptr ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DStateBlock9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD Capture
        STDMETHOD Apply
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DSwapChain9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD Present, :ptr , :ptr , :, :ptr , :
        STDMETHOD GetFrontBufferData, :ptr 
        STDMETHOD GetBackBuffer, :, :, :ptr ptr 
        STDMETHOD GetRasterStatus, :ptr 
        STDMETHOD GetDisplayMode, :ptr 
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD GetPresentParameters, :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DResource9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DVertexDeclaration9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD GetDeclaration, :ptr , :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DVertexShader9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD GetFunction, :ptr , :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DPixelShader9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD GetFunction, :ptr , :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DBaseTexture9, IDirect3DResource9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD_ DWORD, SetLOD, :
        STDMETHOD_ DWORD, GetLOD
        STDMETHOD_ DWORD, GetLevelCount
        STDMETHOD SetAutoGenFilterType, :
        STDMETHOD_ D3DTEXTUREFILTERTYPE, GetAutoGenFilterType
        STDMETHOD_ void, GenerateMipSubLevels
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DTexture9, IDirect3DBaseTexture9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD_ DWORD, SetLOD, :
        STDMETHOD_ DWORD, GetLOD
        STDMETHOD_ DWORD, GetLevelCount
        STDMETHOD SetAutoGenFilterType, :
        STDMETHOD_ D3DTEXTUREFILTERTYPE, GetAutoGenFilterType
        STDMETHOD_ void, GenerateMipSubLevels
        STDMETHOD GetLevelDesc, :, :ptr 
        STDMETHOD GetSurfaceLevel, :, :ptr ptr 
        STDMETHOD LockRect, :, :ptr , :ptr , :
        STDMETHOD UnlockRect, :
        STDMETHOD AddDirtyRect, :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DVolumeTexture9, IDirect3DBaseTexture9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD_ DWORD, SetLOD, :
        STDMETHOD_ DWORD, GetLOD
        STDMETHOD_ DWORD, GetLevelCount
        STDMETHOD SetAutoGenFilterType, :
        STDMETHOD_ D3DTEXTUREFILTERTYPE, GetAutoGenFilterType
        STDMETHOD_ void, GenerateMipSubLevels
        STDMETHOD GetLevelDesc, :, :ptr 
        STDMETHOD GetVolumeLevel, :, :ptr ptr 
        STDMETHOD LockBox, :, :ptr , :ptr , :
        STDMETHOD UnlockBox, :
        STDMETHOD AddDirtyBox, :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DCubeTexture9, IDirect3DBaseTexture9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD_ DWORD, SetLOD, :
        STDMETHOD_ DWORD, GetLOD
        STDMETHOD_ DWORD, GetLevelCount
        STDMETHOD SetAutoGenFilterType, :
        STDMETHOD_ D3DTEXTUREFILTERTYPE, GetAutoGenFilterType
        STDMETHOD_ void, GenerateMipSubLevels
        STDMETHOD GetLevelDesc, :, :ptr 
        STDMETHOD GetCubeMapSurface, :, :, :ptr ptr 
        STDMETHOD LockRect, :, :, :ptr , :ptr , :
        STDMETHOD UnlockRect, :, :
        STDMETHOD AddDirtyRect, :, :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DVertexBuffer9, IDirect3DResource9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD Lock_, :, :, :ptr ptr , :
        STDMETHOD Unlock
        STDMETHOD GetDesc, :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DIndexBuffer9, IDirect3DResource9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD Lock_, :, :, :ptr ptr , :
        STDMETHOD Unlock
        STDMETHOD GetDesc, :ptr 
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DSurface9, IDirect3DResource9)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD_ DWORD, SetPriority, :
        STDMETHOD_ DWORD, GetPriority
        STDMETHOD_ void, PreLoad
        STDMETHOD_ D3DRESOURCETYPE, GetType
        STDMETHOD GetContainer, :, :ptr ptr 
        STDMETHOD GetDesc, :ptr 
        STDMETHOD LockRect, :ptr , :ptr , :
        STDMETHOD UnlockRect
        STDMETHOD GetDC, :ptr 
        STDMETHOD ReleaseDC, :
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DVolume9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD SetPrivateData, :, :ptr , :, :
        STDMETHOD GetPrivateData, :, :ptr , :ptr 
        STDMETHOD FreePrivateData, :
        STDMETHOD GetContainer, :, :ptr ptr 
        STDMETHOD GetDesc, :ptr 
        STDMETHOD LockBox, :ptr , :ptr , :
        STDMETHOD UnlockBox
      DECLARE_INTERFACE__END

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
      DECLARE_INTERFACE_(IDirect3DQuery9, IUnknown)
        STDMETHOD QueryInterface, :, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD GetDevice, :ptr ptr 
        STDMETHOD_ D3DQUERYTYPE, GetType
        STDMETHOD_ DWORD, GetDataSize
        STDMETHOD Issue, :
        STDMETHOD GetData, :ptr , :, :
      DECLARE_INTERFACE__END

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
      D3DADAPTER_DEFAULT equ 0
      D3DENUM_NO_DRIVERVERSION equ 00000004h
      D3DPRESENT_BACK_BUFFERS_MAX equ 3
      D3DSGR_NO_CALIBRATION equ 00000000h
      D3DSGR_CALIBRATE equ 00000001h
      D3DCURSOR_IMMEDIATE_UPDATE equ 00000001h
      D3DPRESENT_DONOTWAIT equ 00000001h
      D3DPRESENT_LINEAR_CONTENT equ 00000002h
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
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
endif
