;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9core.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include d3dx9.inc
ifndef __D3DX9CORE_H__
  __D3DX9CORE_H__ equ <>
  D3DX_VERSION equ 0902h
  D3DX_SDK_VERSION equ 47
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCheckVersion proto WIN_STD_CALL_CONV :UINT, :UINT
  ifdef __cplusplus
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  D3DXDebugMute proto WIN_STD_CALL_CONV :BOOL
  ifdef __cplusplus
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  D3DXGetDriverLevel proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9
  ifdef __cplusplus
    ;[...]
  endif
  ;ID3DXBuffer typedef ID3DXBuffer
  
  LPD3DXBUFFER typedef ptr ID3DXBuffer
  
  DEFINE_GUID IID_ID3DXBuffer, 8ba5fb08h, 5195h, 40e2h, 0ach, 58h, 0dh, 98h, 9ch, 3ah, 1h, 2h
  INTERFACE equ <ID3DXBuffer>
  DECLARE_INTERFACE_ ID3DXBuffer, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetBufferPointer, :THIS_
    STD_METHOD GetBufferSize, :THIS_
  END_DECLARE_INTERFACE_
  D3DXSPRITE_DONOTSAVESTATE equ (1 shl 0)
  D3DXSPRITE_DONOTMODIFY_RENDERSTATE equ (1 shl 1)
  D3DXSPRITE_OBJECTSPACE equ (1 shl 2)
  D3DXSPRITE_BILLBOARD equ (1 shl 3)
  D3DXSPRITE_ALPHABLEND equ (1 shl 4)
  D3DXSPRITE_SORT_TEXTURE equ (1 shl 5)
  D3DXSPRITE_SORT_DEPTH_FRONTTOBACK equ (1 shl 6)
  D3DXSPRITE_SORT_DEPTH_BACKTOFRONT equ (1 shl 7)
  D3DXSPRITE_DO_NOT_ADDREF_TEXTURE equ (1 shl 8)
  ;ID3DXSprite typedef ID3DXSprite
  
  LPD3DXSPRITE typedef ptr ID3DXSprite
  
  DEFINE_GUID IID_ID3DXSprite, 0ba0b762dh, 7d28h, 43ech, 0b9h, 0dch, 2fh, 84h, 44h, 3bh, 6h, 14h
  INTERFACE equ <ID3DXSprite>
  DECLARE_INTERFACE_ ID3DXSprite, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetDevice, :ptr THIS_
    STD_METHOD GetTransform, :ptr THIS_
    STD_METHOD SetTransform, :ptr THIS_
    STD_METHOD SetWorldViewRH, :ptr THIS_, :ptr D3DXMATRIX
    STD_METHOD SetWorldViewLH, :ptr THIS_, :ptr D3DXMATRIX
    STD_METHOD Begin, :THIS_
    STD_METHOD Draw, :THIS_, :ptr RECT, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :D3DCOLOR
    STD_METHOD Flush, :THIS_
    STD_METHOD End_, :THIS_
    STD_METHOD OnLostDevice, :THIS_
    STD_METHOD OnResetDevice, :THIS_
  END_DECLARE_INTERFACE_
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreateSprite proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :ptr LPD3DXSPRITE
  ifdef __cplusplus
    ;[...]
  endif
  D3DXFONT_DESCA struct
    Height INT_ ?
    Width_ UINT ?
    Weight UINT ?
    MipLevels UINT ?
    Italic BOOL ?
    CharSet BYTE ?
    OutputPrecision BYTE ?
    Quality BYTE ?
    PitchAndFamily BYTE ?
    FaceName CHAR LF_FACESIZE dup (?)
  D3DXFONT_DESCA ends

  _D3DXFONT_DESCA typedef D3DXFONT_DESCA
  LPD3DXFONT_DESCA typedef ptr D3DXFONT_DESCA
  
  D3DXFONT_DESCW struct
    Height INT_ ?
    Width_ UINT ?
    Weight UINT ?
    MipLevels UINT ?
    Italic BOOL ?
    CharSet BYTE ?
    OutputPrecision BYTE ?
    Quality BYTE ?
    PitchAndFamily BYTE ?
    FaceName WCHAR LF_FACESIZE dup (?)
  D3DXFONT_DESCW ends

  _D3DXFONT_DESCW typedef D3DXFONT_DESCW
  LPD3DXFONT_DESCW typedef ptr D3DXFONT_DESCW
  
  ifdef UNICODE
    D3DXFONT_DESC typedef D3DXFONT_DESCW
    LPD3DXFONT_DESC typedef LPD3DXFONT_DESCW
  else
    D3DXFONT_DESC typedef D3DXFONT_DESCA
    LPD3DXFONT_DESC typedef LPD3DXFONT_DESCA
  endif
  ;ID3DXFont typedef ID3DXFont
  
  LPD3DXFONT typedef ptr ID3DXFont
  
  DEFINE_GUID IID_ID3DXFont, 0d79dbb70h, 5f21h, 4d36h, 0bbh, 0c2h, 0ffh, 52h, 5ch, 21h, 3ch, 0dch
  INTERFACE equ <ID3DXFont>
  DECLARE_INTERFACE_ ID3DXFont, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetDevice, :ptr THIS_
    STD_METHOD GetDescA, :ptr THIS_
    STD_METHOD GetDescW, :ptr THIS_
    STD_METHOD GetTextMetricsA, :ptr THIS_
    STD_METHOD GetTextMetricsW, :ptr THIS_
    STD_METHOD GetDC, :THIS_
    STD_METHOD GetGlyphData, :THIS_, :ptr LPDIRECT3DTEXTURE9, :ptr RECT, :ptr POINT
    STD_METHOD PreloadCharacters, :THIS_, :UINT
    STD_METHOD PreloadGlyphs, :THIS_, :UINT
    STD_METHOD PreloadTextA, :THIS_, :INT_
    STD_METHOD PreloadTextW, :THIS_, :INT_
    STD_METHOD DrawTextA, :THIS_, :LPCSTR, :INT_, :LPRECT, :DWORD, :D3DCOLOR
    STD_METHOD DrawTextW, :THIS_, :LPCWSTR, :INT_, :LPRECT, :DWORD, :D3DCOLOR
    STD_METHOD OnLostDevice, :THIS_
    STD_METHOD OnResetDevice, :THIS_
    ifdef __cplusplus
      ;[...]
    endif
  END_DECLARE_INTERFACE_
  ifndef GetTextMetrics
    ifdef UNICODE
      GetTextMetrics equ <GetTextMetricsW>
    else
      GetTextMetrics equ <GetTextMetricsA>
    endif
  endif
  ifndef DrawText
    ifdef UNICODE
      DrawText equ <DrawTextW>
    else
      DrawText equ <DrawTextA>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreateFontA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :INT_, :UINT, :UINT, :UINT, :BOOL, :DWORD, :DWORD, :DWORD, :DWORD, :LPCSTR, :ptr LPD3DXFONT
  D3DXCreateFontW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :INT_, :UINT, :UINT, :UINT, :BOOL, :DWORD, :DWORD, :DWORD, :DWORD, :LPCWSTR, :ptr LPD3DXFONT
  ifdef UNICODE
    D3DXCreateFont equ <D3DXCreateFontW>
  else
    D3DXCreateFont equ <D3DXCreateFontA>
  endif
  D3DXCreateFontIndirectA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :ptr D3DXFONT_DESCA, :ptr LPD3DXFONT
  D3DXCreateFontIndirectW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :ptr D3DXFONT_DESCW, :ptr LPD3DXFONT
  ifdef UNICODE
    D3DXCreateFontIndirect equ <D3DXCreateFontIndirectW>
  else
    D3DXCreateFontIndirect equ <D3DXCreateFontIndirectA>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  D3DXRTS_DESC struct
    Width_ UINT ?
    Height UINT ?
    Format D3DFORMAT ?
    DepthStencil BOOL ?
    DepthStencilFormat D3DFORMAT ?
  D3DXRTS_DESC ends

  _D3DXRTS_DESC typedef D3DXRTS_DESC
  LPD3DXRTS_DESC typedef ptr D3DXRTS_DESC
  
  ;ID3DXRenderToSurface typedef ID3DXRenderToSurface
  
  LPD3DXRENDERTOSURFACE typedef ptr ID3DXRenderToSurface
  
  DEFINE_GUID IID_ID3DXRenderToSurface, 6985f346h, 2c3dh, 43b3h, 0beh, 8bh, 0dah, 0aeh, 8ah, 3h, 0d8h, 94h
  INTERFACE equ <ID3DXRenderToSurface>
  DECLARE_INTERFACE_ ID3DXRenderToSurface, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetDevice, :ptr THIS_
    STD_METHOD GetDesc, :ptr THIS_
    STD_METHOD BeginScene, :THIS_, :ptr D3DVIEWPORT9
    STD_METHOD EndScene, :THIS_
    STD_METHOD OnLostDevice, :THIS_
    STD_METHOD OnResetDevice, :THIS_
  END_DECLARE_INTERFACE_
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreateRenderToSurface proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :UINT, :UINT, :D3DFORMAT, :BOOL, :D3DFORMAT, :ptr LPD3DXRENDERTOSURFACE
  ifdef __cplusplus
    ;[...]
  endif
  D3DXRTE_DESC struct
    Size_ UINT ?
    MipLevels UINT ?
    Format D3DFORMAT ?
    DepthStencil BOOL ?
    DepthStencilFormat D3DFORMAT ?
  D3DXRTE_DESC ends

  _D3DXRTE_DESC typedef D3DXRTE_DESC
  LPD3DXRTE_DESC typedef ptr D3DXRTE_DESC
  
  ;ID3DXRenderToEnvMap typedef ID3DXRenderToEnvMap
  
  LPD3DXRenderToEnvMap typedef ptr ID3DXRenderToEnvMap
  
  DEFINE_GUID IID_ID3DXRenderToEnvMap, 313f1b4bh, 0c7b0h, 4fa2h, 9dh, 9dh, 8dh, 38h, 0bh, 64h, 38h, 5eh
  INTERFACE equ <ID3DXRenderToEnvMap>
  DECLARE_INTERFACE_ ID3DXRenderToEnvMap, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetDevice, :ptr THIS_
    STD_METHOD GetDesc, :ptr THIS_
    STD_METHOD BeginCube, :THIS_
    STD_METHOD BeginSphere, :THIS_
    STD_METHOD BeginHemisphere, :THIS_, :LPDIRECT3DTEXTURE9
    STD_METHOD BeginParabolic, :THIS_, :LPDIRECT3DTEXTURE9
    STD_METHOD Face, :THIS_, :DWORD
    STD_METHOD End_, :THIS_
    STD_METHOD OnLostDevice, :THIS_
    STD_METHOD OnResetDevice, :THIS_
  END_DECLARE_INTERFACE_
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreateRenderToEnvMap proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :UINT, :UINT, :D3DFORMAT, :BOOL, :D3DFORMAT, :ptr LPD3DXRenderToEnvMap
  ifdef __cplusplus
    ;[...]
  endif
  ;ID3DXLine typedef ID3DXLine
  
  LPD3DXLINE typedef ptr ID3DXLine
  
  DEFINE_GUID IID_ID3DXLine, 0d379ba7fh, 9042h, 4ac4h, 9fh, 5eh, 58h, 19h, 2ah, 4ch, 6bh, 0d8h
  INTERFACE equ <ID3DXLine>
  DECLARE_INTERFACE_ ID3DXLine, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetDevice, :ptr THIS_
    STD_METHOD Begin, :THIS_
    STD_METHOD Draw, :ptr THIS_, :DWORD, :D3DCOLOR
    STD_METHOD DrawTransform, :ptr THIS_, :DWORD, :ptr D3DXMATRIX, :D3DCOLOR
    STD_METHOD SetPattern, :THIS_
    STD_METHOD GetPattern, :THIS_
    STD_METHOD SetPatternScale, :THIS_
    STD_METHOD GetPatternScale, :THIS_
    STD_METHOD SetWidth, :THIS_
    STD_METHOD GetWidth, :THIS_
    STD_METHOD SetAntialias, :THIS_
    STD_METHOD GetAntialias, :THIS_
    STD_METHOD SetGLLines, :THIS_
    STD_METHOD GetGLLines, :THIS_
    STD_METHOD End_, :THIS_
    STD_METHOD OnLostDevice, :THIS_
    STD_METHOD OnResetDevice, :THIS_
  END_DECLARE_INTERFACE_
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreateLine proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :ptr LPD3DXLINE
  ifdef __cplusplus
    ;[...]
  endif
endif

