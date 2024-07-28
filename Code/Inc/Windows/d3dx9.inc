;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef __D3DX_INTERNAL__
    .err <Incorrect D3DX header used>
  endif
  ifndef __D3DX9_H__
    __D3DX9_H__ equ <>
    D3DX9_DLL_W equ <L("d3dx9_47.dll")>
    D3DX9_DLL_A equ <"d3dx9_47.dll">
    ifdef UNICODE
      D3DX9_DLL equ <D3DX9_DLL_W>
    else
      D3DX9_DLL equ <D3DX9_DLL_A>
    endif
    include limits.inc
    D3DX_DEFAULT equ (- 1)
    D3DX_DEFAULT_NONPOW2 equ (- 2)
    D3DX_DEFAULT_FLOAT equ <FLT_MAX>
    D3DX_FROM_FILE equ (- 3)
    D3DFMT_FROM_FILE equ ((D3DFORMAT) - 3)
    ifndef D3DXINLINE
      ifdef _MSC_VER
        if (_MSC_VER ge 1200)
          D3DXINLINE equ <__forceinline>
        else
          D3DXINLINE equ <__inline>
        endif
      else
        ifdef __cplusplus
          ;[...]
        else
          D3DXINLINE equ <>
        endif
      endif
    endif
    include d3d9.inc
    include d3dx9math.inc
    include d3dx9core.inc
    include d3dx9xof.inc
    include d3dx9mesh.inc
    include d3dx9shader.inc
    include d3dx9effect.inc
    include d3dx9tex.inc
    include d3dx9shape.inc
    include d3dx9anim.inc
    _FACDD equ 876h
    MAKE_DDHRESULT macro code
      exitm <MAKE_HRESULT(1, _FACDD, code)>
    endm
    _D3DXERR typedef SDWORD
    D3DXERR_CANNOTMODIFYINDEXBUFFER equ MAKE_DDHRESULT(2900)
    D3DXERR_INVALIDMESH equ MAKE_DDHRESULT(2901)
    D3DXERR_CANNOTATTRSORT equ MAKE_DDHRESULT(2902)
    D3DXERR_SKINNINGNOTSUPPORTED equ MAKE_DDHRESULT(2903)
    D3DXERR_TOOMANYINFLUENCES equ MAKE_DDHRESULT(2904)
    D3DXERR_INVALIDDATA equ MAKE_DDHRESULT(2905)
    D3DXERR_LOADEDMESHASNODATA equ MAKE_DDHRESULT(2906)
    D3DXERR_DUPLICATENAMEDFRAGMENT equ MAKE_DDHRESULT(2907)
    D3DXERR_CANNOTREMOVELASTITEM equ MAKE_DDHRESULT(2908)
    
  endif
endif

