;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9shape.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include d3dx9.inc
ifndef __D3DX9SHAPES_H__
  __D3DX9SHAPES_H__ equ <>
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreatePolygon proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :FLOAT, :UINT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER
  D3DXCreateBox proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :FLOAT, :FLOAT, :FLOAT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER
  D3DXCreateCylinder proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :FLOAT, :FLOAT, :FLOAT, :UINT, :UINT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER
  D3DXCreateSphere proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :FLOAT, :UINT, :UINT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER
  D3DXCreateTorus proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :FLOAT, :FLOAT, :UINT, :UINT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER
  D3DXCreateTeapot proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER
  D3DXCreateTextA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :HDC, :LPCSTR, :FLOAT, :FLOAT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER, :LPGLYPHMETRICSFLOAT
  D3DXCreateTextW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :HDC, :LPCWSTR, :FLOAT, :FLOAT, :ptr LPD3DXMESH, :ptr LPD3DXBUFFER, :LPGLYPHMETRICSFLOAT
  ifdef UNICODE
    D3DXCreateText equ <D3DXCreateTextW>
  else
    D3DXCreateText equ <D3DXCreateTextA>
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

