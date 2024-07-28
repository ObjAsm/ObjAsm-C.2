;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9effect.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include d3dx9.inc
ifndef __D3DX9EFFECT_H__
  __D3DX9EFFECT_H__ equ <>
  D3DXFX_DONOTSAVESTATE equ (1 shl 0)
  D3DXFX_DONOTSAVESHADERSTATE equ (1 shl 1)
  D3DXFX_DONOTSAVESAMPLERSTATE equ (1 shl 2)
  D3DXFX_NOT_CLONEABLE equ (1 shl 11)
  D3DXFX_LARGEADDRESSAWARE equ (1 shl 17)
  D3DX_PARAMETER_SHARED equ (1 shl 0)
  D3DX_PARAMETER_LITERAL equ (1 shl 1)
  D3DX_PARAMETER_ANNOTATION equ (1 shl 2)
;  D3DXEFFECT_DESC struct
;    Creator LPCSTR ?
;    Parameters UINT ?
;    Techniques UINT ?
;    Functions UINT ?
;  D3DXEFFECT_DESC ends
;  _D3DXEFFECT_DESC typedef D3DXEFFECT_DESC
;  D3DXPARAMETER_DESC struct
;    Name_ LPCSTR ?
;    Semantic LPCSTR ?
;    Class D3DXPARAMETER_CLASS ?
;    Type_ D3DXPARAMETER_TYPE ?
;    Rows UINT ?
;    Columns UINT ?
;    Elements UINT ?
;    Annotations UINT ?
;    StructMembers UINT ?
;    Flags DWORD ?
;    Bytes UINT ?
;  D3DXPARAMETER_DESC ends
;  _D3DXPARAMETER_DESC typedef D3DXPARAMETER_DESC
;  D3DXTECHNIQUE_DESC struct
;    Name_ LPCSTR ?
;    Passes UINT ?
;    Annotations UINT ?
;  D3DXTECHNIQUE_DESC ends
;  _D3DXTECHNIQUE_DESC typedef D3DXTECHNIQUE_DESC
;  D3DXPASS_DESC struct
;    Name_ LPCSTR ?
;    Annotations UINT ?
;    pVertexShaderFunction POINTER ?
;    pPixelShaderFunction POINTER ?
;  D3DXPASS_DESC ends
;  _D3DXPASS_DESC typedef D3DXPASS_DESC
;  D3DXFUNCTION_DESC struct
;    Name_ LPCSTR ?
;    Annotations UINT ?
;  D3DXFUNCTION_DESC ends
;  _D3DXFUNCTION_DESC typedef D3DXFUNCTION_DESC
;  ;ID3DXEffectPool typedef ID3DXEffectPool
;  
;  LPD3DXEFFECTPOOL typedef ptr ID3DXEffectPool
;  
;  DEFINE_GUID IID_ID3DXEffectPool, 9537ab04h, 3250h, 412eh, 82h, 13h, 0fch, 0d2h, 0f8h, 67h, 79h, 33h
;  INTERFACE equ <ID3DXEffectPool>
;  DECLARE_INTERFACE_ ID3DXEffectPool, IUnknown
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;  END_DECLARE_INTERFACE_
;  ;ID3DXBaseEffect typedef ID3DXBaseEffect
;  
;  LPD3DXBASEEFFECT typedef ptr ID3DXBaseEffect
;  
;  DEFINE_GUID IID_ID3DXBaseEffect, 17c18ach, 103fh, 4417h, 8ch, 51h, 6bh, 0f6h, 0efh, 1eh, 56h, 0beh
;  INTERFACE equ <ID3DXBaseEffect>
;  DECLARE_INTERFACE_ ID3DXBaseEffect, IUnknown
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetDesc, :ptr THIS_
;    STD_METHOD GetParameterDesc, :THIS_, :ptr D3DXPARAMETER_DESC
;    STD_METHOD GetTechniqueDesc, :THIS_, :ptr D3DXTECHNIQUE_DESC
;    STD_METHOD GetPassDesc, :THIS_, :ptr D3DXPASS_DESC
;    STD_METHOD GetFunctionDesc, :THIS_, :ptr D3DXFUNCTION_DESC
;    STD_METHOD GetParameter, :THIS_, :UINT
;    STD_METHOD GetParameterByName, :THIS_, :LPCSTR
;    STD_METHOD GetParameterBySemantic, :THIS_, :LPCSTR
;    STD_METHOD GetParameterElement, :THIS_, :UINT
;    STD_METHOD GetTechnique, :THIS_
;    STD_METHOD GetTechniqueByName, :THIS_
;    STD_METHOD GetPass, :THIS_, :UINT
;    STD_METHOD GetPassByName, :THIS_, :LPCSTR
;    STD_METHOD GetFunction, :THIS_
;    STD_METHOD GetFunctionByName, :THIS_
;    STD_METHOD GetAnnotation, :THIS_, :UINT
;    STD_METHOD GetAnnotationByName, :THIS_, :LPCSTR
;    STD_METHOD SetValue, :THIS_, :LPCVOID, :UINT
;    STD_METHOD GetValue, :THIS_, :LPVOID, :UINT
;    STD_METHOD SetBool, :THIS_, :BOOL
;    STD_METHOD GetBool, :THIS_, :ptr BOOL
;    STD_METHOD SetBoolArray, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD GetBoolArray, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD SetInt, :THIS_, :INT_
;    STD_METHOD GetInt, :THIS_, :ptr INT_
;    STD_METHOD SetIntArray, :THIS_, :ptr INT_, :UINT
;    STD_METHOD GetIntArray, :THIS_, :ptr INT_, :UINT
;    STD_METHOD SetFloat, :THIS_, :FLOAT
;    STD_METHOD GetFloat, :THIS_, :ptr FLOAT
;    STD_METHOD SetFloatArray, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD GetFloatArray, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD SetVector, :THIS_, :ptr D3DXVECTOR4
;    STD_METHOD GetVector, :THIS_, :ptr D3DXVECTOR4
;    STD_METHOD SetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
;    STD_METHOD GetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
;    STD_METHOD SetMatrix, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD GetMatrix, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD SetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD GetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD SetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD SetString, :THIS_, :LPCSTR
;    STD_METHOD GetString, :THIS_, :ptr LPCSTR
;    STD_METHOD SetTexture, :THIS_, :LPDIRECT3DBASETEXTURE9
;    STD_METHOD GetTexture, :THIS_, :ptr LPDIRECT3DBASETEXTURE9
;    STD_METHOD GetPixelShader, :THIS_, :ptr LPDIRECT3DPIXELSHADER9
;    STD_METHOD GetVertexShader, :THIS_, :ptr LPDIRECT3DVERTEXSHADER9
;    STD_METHOD SetArrayRange, :THIS_, :UINT, :UINT
;  END_DECLARE_INTERFACE_
;  ;ID3DXEffectStateManager typedef ID3DXEffectStateManager
;  
;  LPD3DXEFFECTSTATEMANAGER typedef ptr ID3DXEffectStateManager
;  
;  DEFINE_GUID IID_ID3DXEffectStateManager, 79aab587h, 6dbch, 4fa7h, 82h, 0deh, 37h, 0fah, 17h, 81h, 0c5h, 0ceh
;  INTERFACE equ <ID3DXEffectStateManager>
;  DECLARE_INTERFACE_ ID3DXEffectStateManager, IUnknown
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD SetTransform, :THIS_, :ptr D3DMATRIX
;    STD_METHOD SetMaterial, :ptr THIS_
;    STD_METHOD SetLight, :THIS_, :ptr D3DLIGHT9
;    STD_METHOD LightEnable, :THIS_, :BOOL
;    STD_METHOD SetRenderState, :THIS_, :DWORD
;    STD_METHOD SetTexture, :THIS_, :LPDIRECT3DBASETEXTURE9
;    STD_METHOD SetTextureStageState, :THIS_, :D3DTEXTURESTAGESTATETYPE, :DWORD
;    STD_METHOD SetSamplerState, :THIS_, :D3DSAMPLERSTATETYPE, :DWORD
;    STD_METHOD SetNPatchMode, :THIS_
;    STD_METHOD SetFVF, :THIS_
;    STD_METHOD SetVertexShader, :THIS_
;    STD_METHOD SetVertexShaderConstantF, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD SetVertexShaderConstantI, :THIS_, :ptr INT_, :UINT
;    STD_METHOD SetVertexShaderConstantB, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD SetPixelShader, :THIS_
;    STD_METHOD SetPixelShaderConstantF, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD SetPixelShaderConstantI, :THIS_, :ptr INT_, :UINT
;    STD_METHOD SetPixelShaderConstantB, :THIS_, :ptr BOOL, :UINT
;  END_DECLARE_INTERFACE_
;  ;ID3DXEffect typedef ID3DXEffect
;  
;  LPD3DXEFFECT typedef ptr ID3DXEffect
;  
;  DEFINE_GUID IID_ID3DXEffect, 0f6ceb4b3h, 4e4ch, 40ddh, 0b8h, 83h, 8dh, 8dh, 0e5h, 0eah, 0ch, 0d5h
;  INTERFACE equ <ID3DXEffect>
;  DECLARE_INTERFACE_ ID3DXEffect, ID3DXBaseEffect
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetDesc, :ptr THIS_
;    STD_METHOD GetParameterDesc, :THIS_, :ptr D3DXPARAMETER_DESC
;    STD_METHOD GetTechniqueDesc, :THIS_, :ptr D3DXTECHNIQUE_DESC
;    STD_METHOD GetPassDesc, :THIS_, :ptr D3DXPASS_DESC
;    STD_METHOD GetFunctionDesc, :THIS_, :ptr D3DXFUNCTION_DESC
;    STD_METHOD GetParameter, :THIS_, :UINT
;    STD_METHOD GetParameterByName, :THIS_, :LPCSTR
;    STD_METHOD GetParameterBySemantic, :THIS_, :LPCSTR
;    STD_METHOD GetParameterElement, :THIS_, :UINT
;    STD_METHOD GetTechnique, :THIS_
;    STD_METHOD GetTechniqueByName, :THIS_
;    STD_METHOD GetPass, :THIS_, :UINT
;    STD_METHOD GetPassByName, :THIS_, :LPCSTR
;    STD_METHOD GetFunction, :THIS_
;    STD_METHOD GetFunctionByName, :THIS_
;    STD_METHOD GetAnnotation, :THIS_, :UINT
;    STD_METHOD GetAnnotationByName, :THIS_, :LPCSTR
;    STD_METHOD SetValue, :THIS_, :LPCVOID, :UINT
;    STD_METHOD GetValue, :THIS_, :LPVOID, :UINT
;    STD_METHOD SetBool, :THIS_, :BOOL
;    STD_METHOD GetBool, :THIS_, :ptr BOOL
;    STD_METHOD SetBoolArray, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD GetBoolArray, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD SetInt, :THIS_, :INT_
;    STD_METHOD GetInt, :THIS_, :ptr INT_
;    STD_METHOD SetIntArray, :THIS_, :ptr INT_, :UINT
;    STD_METHOD GetIntArray, :THIS_, :ptr INT_, :UINT
;    STD_METHOD SetFloat, :THIS_, :FLOAT
;    STD_METHOD GetFloat, :THIS_, :ptr FLOAT
;    STD_METHOD SetFloatArray, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD GetFloatArray, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD SetVector, :THIS_, :ptr D3DXVECTOR4
;    STD_METHOD GetVector, :THIS_, :ptr D3DXVECTOR4
;    STD_METHOD SetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
;    STD_METHOD GetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
;    STD_METHOD SetMatrix, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD GetMatrix, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD SetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD GetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD SetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD SetString, :THIS_, :LPCSTR
;    STD_METHOD GetString, :THIS_, :ptr LPCSTR
;    STD_METHOD SetTexture, :THIS_, :LPDIRECT3DBASETEXTURE9
;    STD_METHOD GetTexture, :THIS_, :ptr LPDIRECT3DBASETEXTURE9
;    STD_METHOD GetPixelShader, :THIS_, :ptr LPDIRECT3DPIXELSHADER9
;    STD_METHOD GetVertexShader, :THIS_, :ptr LPDIRECT3DVERTEXSHADER9
;    STD_METHOD SetArrayRange, :THIS_, :UINT, :UINT
;    STD_METHOD GetPool, :ptr THIS_
;    STD_METHOD SetTechnique, :THIS_
;    STD_METHOD GetCurrentTechnique, :THIS_
;    STD_METHOD ValidateTechnique, :THIS_
;    STD_METHOD FindNextValidTechnique, :THIS_, :ptr D3DXHANDLE
;    STD_METHOD IsParameterUsed, :THIS_, :D3DXHANDLE
;    STD_METHOD Begin, :ptr THIS_, :DWORD
;    STD_METHOD BeginPass, :THIS_
;    STD_METHOD CommitChanges, :THIS_
;    STD_METHOD EndPass, :THIS_
;    STD_METHOD End_, :THIS_
;    STD_METHOD GetDevice, :ptr THIS_
;    STD_METHOD OnLostDevice, :THIS_
;    STD_METHOD OnResetDevice, :THIS_
;    STD_METHOD SetStateManager, :THIS_
;    STD_METHOD GetStateManager, :ptr THIS_
;    STD_METHOD BeginParameterBlock, :THIS_
;    STD_METHOD EndParameterBlock, :THIS_
;    STD_METHOD ApplyParameterBlock, :THIS_
;    STD_METHOD DeleteParameterBlock, :THIS_
;    STD_METHOD CloneEffect, :THIS_, :ptr LPD3DXEFFECT
;    STD_METHOD SetRawValue, :THIS_, :LPCVOID, :UINT, :UINT
;  END_DECLARE_INTERFACE_
;  ;ID3DXEffectCompiler typedef ID3DXEffectCompiler
;  
;  LPD3DXEFFECTCOMPILER typedef ptr ID3DXEffectCompiler
;  
;  DEFINE_GUID IID_ID3DXEffectCompiler, 51b8a949h, 1a31h, 47e6h, 0beh, 0a0h, 4bh, 30h, 0dbh, 53h, 0f1h, 0e0h
;  INTERFACE equ <ID3DXEffectCompiler>
;  DECLARE_INTERFACE_ ID3DXEffectCompiler, ID3DXBaseEffect
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetDesc, :ptr THIS_
;    STD_METHOD GetParameterDesc, :THIS_, :ptr D3DXPARAMETER_DESC
;    STD_METHOD GetTechniqueDesc, :THIS_, :ptr D3DXTECHNIQUE_DESC
;    STD_METHOD GetPassDesc, :THIS_, :ptr D3DXPASS_DESC
;    STD_METHOD GetFunctionDesc, :THIS_, :ptr D3DXFUNCTION_DESC
;    STD_METHOD GetParameter, :THIS_, :UINT
;    STD_METHOD GetParameterByName, :THIS_, :LPCSTR
;    STD_METHOD GetParameterBySemantic, :THIS_, :LPCSTR
;    STD_METHOD GetParameterElement, :THIS_, :UINT
;    STD_METHOD GetTechnique, :THIS_
;    STD_METHOD GetTechniqueByName, :THIS_
;    STD_METHOD GetPass, :THIS_, :UINT
;    STD_METHOD GetPassByName, :THIS_, :LPCSTR
;    STD_METHOD GetFunction, :THIS_
;    STD_METHOD GetFunctionByName, :THIS_
;    STD_METHOD GetAnnotation, :THIS_, :UINT
;    STD_METHOD GetAnnotationByName, :THIS_, :LPCSTR
;    STD_METHOD SetValue, :THIS_, :LPCVOID, :UINT
;    STD_METHOD GetValue, :THIS_, :LPVOID, :UINT
;    STD_METHOD SetBool, :THIS_, :BOOL
;    STD_METHOD GetBool, :THIS_, :ptr BOOL
;    STD_METHOD SetBoolArray, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD GetBoolArray, :THIS_, :ptr BOOL, :UINT
;    STD_METHOD SetInt, :THIS_, :INT_
;    STD_METHOD GetInt, :THIS_, :ptr INT_
;    STD_METHOD SetIntArray, :THIS_, :ptr INT_, :UINT
;    STD_METHOD GetIntArray, :THIS_, :ptr INT_, :UINT
;    STD_METHOD SetFloat, :THIS_, :FLOAT
;    STD_METHOD GetFloat, :THIS_, :ptr FLOAT
;    STD_METHOD SetFloatArray, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD GetFloatArray, :THIS_, :ptr FLOAT, :UINT
;    STD_METHOD SetVector, :THIS_, :ptr D3DXVECTOR4
;    STD_METHOD GetVector, :THIS_, :ptr D3DXVECTOR4
;    STD_METHOD SetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
;    STD_METHOD GetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
;    STD_METHOD SetMatrix, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD GetMatrix, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD SetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD GetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
;    STD_METHOD SetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
;    STD_METHOD SetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD GetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
;    STD_METHOD SetString, :THIS_, :LPCSTR
;    STD_METHOD GetString, :THIS_, :ptr LPCSTR
;    STD_METHOD SetTexture, :THIS_, :LPDIRECT3DBASETEXTURE9
;    STD_METHOD GetTexture, :THIS_, :ptr LPDIRECT3DBASETEXTURE9
;    STD_METHOD GetPixelShader, :THIS_, :ptr LPDIRECT3DPIXELSHADER9
;    STD_METHOD GetVertexShader, :THIS_, :ptr LPDIRECT3DVERTEXSHADER9
;    STD_METHOD SetArrayRange, :THIS_, :UINT, :UINT
;    STD_METHOD SetLiteral, :THIS_, :BOOL
;    STD_METHOD GetLiteral, :THIS_, :ptr BOOL
;    STD_METHOD CompileEffect, :THIS_, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
;    STD_METHOD CompileShader, :THIS_, :LPCSTR, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER, :ptr LPD3DXCONSTANTTABLE
;  END_DECLARE_INTERFACE_
;  ifdef __cplusplus
;    ;[...]
;  endif
  D3DXCreateEffectPool proto WIN_STD_CALL_CONV :ptr LPD3DXEFFECTPOOL
  D3DXCreateEffectFromFileA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  D3DXCreateEffectFromFileW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXCreateEffectFromFile equ <D3DXCreateEffectFromFileW>
  else
    D3DXCreateEffectFromFile equ <D3DXCreateEffectFromFileA>
  endif
  D3DXCreateEffectFromResourceA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :HMODULE, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  D3DXCreateEffectFromResourceW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :HMODULE, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXCreateEffectFromResource equ <D3DXCreateEffectFromResourceW>
  else
    D3DXCreateEffectFromResource equ <D3DXCreateEffectFromResourceA>
  endif
  D3DXCreateEffect proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :LPCVOID, :UINT, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  D3DXCreateEffectFromFileExA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  D3DXCreateEffectFromFileExW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXCreateEffectFromFileEx equ <D3DXCreateEffectFromFileExW>
  else
    D3DXCreateEffectFromFileEx equ <D3DXCreateEffectFromFileExA>
  endif
  D3DXCreateEffectFromResourceExA proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :HMODULE, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  D3DXCreateEffectFromResourceExW proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :HMODULE, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXCreateEffectFromResourceEx equ <D3DXCreateEffectFromResourceExW>
  else
    D3DXCreateEffectFromResourceEx equ <D3DXCreateEffectFromResourceExA>
  endif
  D3DXCreateEffectEx proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9, :LPCVOID, :UINT, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :DWORD, :LPD3DXEFFECTPOOL, :ptr LPD3DXEFFECT, :ptr LPD3DXBUFFER
  D3DXCreateEffectCompilerFromFileA proto WIN_STD_CALL_CONV :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXEFFECTCOMPILER, :ptr LPD3DXBUFFER
  D3DXCreateEffectCompilerFromFileW proto WIN_STD_CALL_CONV :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXEFFECTCOMPILER, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXCreateEffectCompilerFromFile equ <D3DXCreateEffectCompilerFromFileW>
  else
    D3DXCreateEffectCompilerFromFile equ <D3DXCreateEffectCompilerFromFileA>
  endif
  D3DXCreateEffectCompilerFromResourceA proto WIN_STD_CALL_CONV :HMODULE, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXEFFECTCOMPILER, :ptr LPD3DXBUFFER
  D3DXCreateEffectCompilerFromResourceW proto WIN_STD_CALL_CONV :HMODULE, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXEFFECTCOMPILER, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXCreateEffectCompilerFromResource equ <D3DXCreateEffectCompilerFromResourceW>
  else
    D3DXCreateEffectCompilerFromResource equ <D3DXCreateEffectCompilerFromResourceA>
  endif
  D3DXCreateEffectCompiler proto WIN_STD_CALL_CONV :LPCSTR, :UINT, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXEFFECTCOMPILER, :ptr LPD3DXBUFFER
  D3DXDisassembleEffect proto WIN_STD_CALL_CONV :LPD3DXEFFECT, :BOOL, :ptr LPD3DXBUFFER
  ifdef __cplusplus
    ;[...]
  endif
endif

