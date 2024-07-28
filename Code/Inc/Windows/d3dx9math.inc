;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9math.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include d3dx9.inc
ifndef __D3DX9MATH_H__
  __D3DX9MATH_H__ equ <>
;  include math.inc
  if _MSC_VER ge 1200
  endif
  D3DX_PI equ ((FLOAT) 3.141592654)
  D3DX_1BYPI equ ((FLOAT) 0.318309886)
  D3DXToRadian macro degree
    exitm <((degree) * (D3DX_PI / 180.0))>
  endm
  D3DXToDegree macro radian
    exitm <((radian) * (180.0 / D3DX_PI))>
  endm
  D3DX_16F_DIG equ 3
  D3DX_16F_EPSILON equ 4.8875809E-4
  D3DX_16F_MANT_DIG equ 11
  D3DX_16F_MAX equ 6.550400E+004
  D3DX_16F_MAX_10_EXP equ 4
  D3DX_16F_MAX_EXP equ 15
  D3DX_16F_MIN equ 6.1035156E-5
  D3DX_16F_MIN_10_EXP equ -4
  D3DX_16F_MIN_EXP equ -14
  D3DX_16F_RADIX equ 2
  D3DX_16F_ROUNDS equ 1
  D3DXFLOAT16 struct
    ifdef __cplusplus
      ;[...]
    endif
    value WORD ?
  D3DXFLOAT16 ends
  LPD3DXFLOAT16 typedef ptr D3DXFLOAT16
  
  D3DXVECTOR2 struct
    ifdef __cplusplus
      ;[...]
    endif
    x FLOAT ?
  D3DXVECTOR2 ends
  LPD3DXVECTOR2 typedef ptr D3DXVECTOR2
  
  D3DXVECTOR2_16F struct
    ifdef __cplusplus
      ;[...]
    endif
    x D3DXFLOAT16 <>
  D3DXVECTOR2_16F ends
  LPD3DXVECTOR2_16F typedef ptr D3DXVECTOR2_16F
  
  ifdef __cplusplus
    ;[...]
  else
    D3DXVECTOR3 typedef _D3DVECTOR
    LPD3DXVECTOR3 typedef ptr _D3DVECTOR
    
  endif
  D3DXVECTOR3_16F struct
    ifdef __cplusplus
      ;[...]
    endif
    x D3DXFLOAT16 <>
  D3DXVECTOR3_16F ends
  LPD3DXVECTOR3_16F typedef ptr D3DXVECTOR3_16F
  
  D3DXVECTOR4 struct
    ifdef __cplusplus
      ;[...]
    endif
    x FLOAT ?
  D3DXVECTOR4 ends
  LPD3DXVECTOR4 typedef ptr D3DXVECTOR4
  
  D3DXVECTOR4_16F struct
    ifdef __cplusplus
      ;[...]
    endif
    x D3DXFLOAT16 <>
  D3DXVECTOR4_16F ends
  LPD3DXVECTOR4_16F typedef ptr D3DXVECTOR4_16F
  
  ifdef __cplusplus
    ;[...]
  else
    D3DXMATRIX typedef _D3DMATRIX
    LPD3DXMATRIX typedef ptr _D3DMATRIX
    
  endif
  ifdef __cplusplus
    ;[...]
  else
    _D3DXMATRIXA16 typedef D3DXMATRIX
  endif
  if _MSC_VER ge 1300
    D3DX_ALIGN16 equ <>;__declspec(align(16))
  else
    D3DX_ALIGN16 equ <>
  endif
  D3DXMATRIXA16 typedef D3DX_ALIGN16
  LPD3DXMATRIXA16 typedef ptr D3DX_ALIGN16
  D3DXQUATERNION struct
    ifdef __cplusplus
      ;[...]
    endif
    x FLOAT ?
  D3DXQUATERNION ends
  LPD3DXQUATERNION typedef ptr D3DXQUATERNION
  
  D3DXPLANE struct
    ifdef __cplusplus
      ;[...]
    endif
    a FLOAT ?
  D3DXPLANE ends
  LPD3DXPLANE typedef ptr D3DXPLANE
  
  D3DXCOLOR struct
    ifdef __cplusplus
      ;[...]
    endif
    r FLOAT ?
  D3DXCOLOR ends
  LPD3DXCOLOR typedef ptr D3DXCOLOR
  
  ifdef __cplusplus
    ;[...]
  endif
  D3DXFloat32To16Array proto WIN_STD_CALL_CONV :ptr D3DXFLOAT16, :ptr FLOAT, :UINT
  D3DXFloat16To32Array proto WIN_STD_CALL_CONV :ptr FLOAT, :ptr D3DXFLOAT16, :UINT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXVec2Length proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2
  D3DXVec2LengthSq proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2
  D3DXVec2Dot proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2CCW proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2Add proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2Subtract proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2Minimize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2Maximize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2Scale proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :FLOAT
  D3DXVec2Lerp proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXVec2Normalize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2
  D3DXVec2Hermite proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :FLOAT
  D3DXVec2CatmullRom proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :FLOAT
  D3DXVec2BaryCentric proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :FLOAT, :FLOAT
  D3DXVec2Transform proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR2, :ptr D3DXMATRIX
  D3DXVec2TransformCoord proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXMATRIX
  D3DXVec2TransformNormal proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :ptr D3DXMATRIX
  D3DXVec2TransformArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :UINT, :ptr D3DXVECTOR2, :UINT, :ptr D3DXMATRIX, :UINT
  D3DXVec2TransformCoordArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :UINT, :ptr D3DXVECTOR2, :UINT, :ptr D3DXMATRIX, :UINT
  D3DXVec2TransformNormalArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR2, :UINT, :ptr D3DXVECTOR2, :UINT, :ptr D3DXMATRIX, :UINT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXVec3Length proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3
  D3DXVec3LengthSq proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3
  D3DXVec3Dot proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Cross proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Add proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Subtract proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Minimize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Maximize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Scale proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :FLOAT
  D3DXVec3Lerp proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXVec3Normalize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXVec3Hermite proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :FLOAT
  D3DXVec3CatmullRom proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :FLOAT
  D3DXVec3BaryCentric proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :FLOAT, :FLOAT
  D3DXVec3Transform proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR3, :ptr D3DXMATRIX
  D3DXVec3TransformCoord proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXMATRIX
  D3DXVec3TransformNormal proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXMATRIX
  D3DXVec3TransformArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :UINT, :ptr D3DXVECTOR3, :UINT, :ptr D3DXMATRIX, :UINT
  D3DXVec3TransformCoordArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :UINT, :ptr D3DXVECTOR3, :UINT, :ptr D3DXMATRIX, :UINT
  D3DXVec3TransformNormalArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :UINT, :ptr D3DXVECTOR3, :UINT, :ptr D3DXMATRIX, :UINT
  D3DXVec3Project proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DVIEWPORT9, :ptr D3DXMATRIX, :ptr D3DXMATRIX, :ptr D3DXMATRIX
  D3DXVec3Unproject proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DVIEWPORT9, :ptr D3DXMATRIX, :ptr D3DXMATRIX, :ptr D3DXMATRIX
  D3DXVec3ProjectArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :UINT, :ptr D3DXVECTOR3, :UINT, :ptr D3DVIEWPORT9, :ptr D3DXMATRIX, :ptr D3DXMATRIX, :ptr D3DXMATRIX, :UINT
  D3DXVec3UnprojectArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :UINT, :ptr D3DXVECTOR3, :UINT, :ptr D3DVIEWPORT9, :ptr D3DXMATRIX, :ptr D3DXMATRIX, :ptr D3DXMATRIX, :UINT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXVec4Length proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4
  D3DXVec4LengthSq proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4
  D3DXVec4Dot proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Add proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Subtract proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Minimize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Maximize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Scale proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :FLOAT
  D3DXVec4Lerp proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXVec4Cross proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Normalize proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4
  D3DXVec4Hermite proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :FLOAT
  D3DXVec4CatmullRom proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :FLOAT
  D3DXVec4BaryCentric proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :FLOAT, :FLOAT
  D3DXVec4Transform proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :ptr D3DXVECTOR4, :ptr D3DXMATRIX
  D3DXVec4TransformArray proto WIN_STD_CALL_CONV :ptr D3DXVECTOR4, :UINT, :ptr D3DXVECTOR4, :UINT, :ptr D3DXMATRIX, :UINT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXMatrixIdentity proto WIN_STD_CALL_CONV :ptr D3DXMATRIX
  D3DXMatrixIsIdentity proto WIN_STD_CALL_CONV :ptr D3DXMATRIX
  ifdef __cplusplus
    ;[...]
  endif
  D3DXMatrixDeterminant proto WIN_STD_CALL_CONV :ptr D3DXMATRIX
  D3DXMatrixDecompose proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3, :ptr D3DXMATRIX
  D3DXMatrixTranspose proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXMATRIX
  D3DXMatrixMultiply proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXMATRIX, :ptr D3DXMATRIX
  D3DXMatrixMultiplyTranspose proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXMATRIX, :ptr D3DXMATRIX
  D3DXMatrixInverse proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr FLOAT, :ptr D3DXMATRIX
  D3DXMatrixScaling proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixTranslation proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixRotationX proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT
  D3DXMatrixRotationY proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT
  D3DXMatrixRotationZ proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT
  D3DXMatrixRotationAxis proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXVECTOR3, :FLOAT
  D3DXMatrixRotationQuaternion proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXQUATERNION
  D3DXMatrixRotationYawPitchRoll proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixTransformation proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3
  D3DXMatrixTransformation2D proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXVECTOR2, :FLOAT, :ptr D3DXVECTOR2, :ptr D3DXVECTOR2, :FLOAT, :ptr D3DXVECTOR2
  D3DXMatrixAffineTransformation proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3
  D3DXMatrixAffineTransformation2D proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :ptr D3DXVECTOR2, :FLOAT, :ptr D3DXVECTOR2
  D3DXMatrixLookAtRH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXMatrixLookAtLH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXMatrixPerspectiveRH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveLH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveFovRH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveFovLH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveOffCenterRH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixPerspectiveOffCenterLH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoRH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoLH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoOffCenterRH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixOrthoOffCenterLH proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :FLOAT
  D3DXMatrixShadow proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXVECTOR4, :ptr D3DXPLANE
  D3DXMatrixReflect proto WIN_STD_CALL_CONV :ptr D3DXMATRIX, :ptr D3DXPLANE
  ifdef __cplusplus
    ;[...]
  endif
  D3DXQuaternionLength proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION
  D3DXQuaternionLengthSq proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION
  D3DXQuaternionDot proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionIdentity proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION
  D3DXQuaternionIsIdentity proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION
  D3DXQuaternionConjugate proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  ifdef __cplusplus
    ;[...]
  endif
  D3DXQuaternionToAxisAngle proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXVECTOR3, :ptr FLOAT
  D3DXQuaternionRotationMatrix proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXMATRIX
  D3DXQuaternionRotationAxis proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXVECTOR3, :FLOAT
  D3DXQuaternionRotationYawPitchRoll proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :FLOAT, :FLOAT, :FLOAT
  D3DXQuaternionMultiply proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionNormalize proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionInverse proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionLn proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionExp proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionSlerp proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :FLOAT
  D3DXQuaternionSquad proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :FLOAT
  D3DXQuaternionSquadSetup proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION
  D3DXQuaternionBaryCentric proto WIN_STD_CALL_CONV :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :ptr D3DXQUATERNION, :FLOAT, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXPlaneDot proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXVECTOR4
  D3DXPlaneDotCoord proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXVECTOR3
  D3DXPlaneDotNormal proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXVECTOR3
  D3DXPlaneScale proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXPLANE, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXPlaneNormalize proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXPLANE
  D3DXPlaneIntersectLine proto WIN_STD_CALL_CONV :ptr D3DXVECTOR3, :ptr D3DXPLANE, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXPlaneFromPointNormal proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXPlaneFromPoints proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3, :ptr D3DXVECTOR3
  D3DXPlaneTransform proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :ptr D3DXPLANE, :ptr D3DXMATRIX
  D3DXPlaneTransformArray proto WIN_STD_CALL_CONV :ptr D3DXPLANE, :UINT, :ptr D3DXPLANE, :UINT, :ptr D3DXMATRIX, :UINT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXColorNegative proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR
  D3DXColorAdd proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :ptr D3DXCOLOR
  D3DXColorSubtract proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :ptr D3DXCOLOR
  D3DXColorScale proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :FLOAT
  D3DXColorModulate proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :ptr D3DXCOLOR
  D3DXColorLerp proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :ptr D3DXCOLOR, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  D3DXColorAdjustSaturation proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :FLOAT
  D3DXColorAdjustContrast proto WIN_STD_CALL_CONV :ptr D3DXCOLOR, :ptr D3DXCOLOR, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  D3DXFresnelTerm proto WIN_STD_CALL_CONV :FLOAT, :FLOAT
  ifdef __cplusplus
    ;[...]
  endif
  ;ID3DXMatrixStack typedef ID3DXMatrixStack
  
  LPD3DXMATRIXSTACK typedef ptr ID3DXMatrixStack
  
  DEFINE_GUID IID_ID3DXMatrixStack, 0c7885ba7h, 0f990h, 4fe7h, 92h, 2dh, 85h, 15h, 0e4h, 77h, 0ddh, 85h
  INTERFACE equ <ID3DXMatrixStack>
  DECLARE_INTERFACE_ ID3DXMatrixStack, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD Pop_, :THIS_
    STD_METHOD Push_, :THIS_
    STD_METHOD LoadIdentity, :THIS_
    STD_METHOD LoadMatrix, :ptr THIS_
    STD_METHOD MultMatrix, :ptr THIS_
    STD_METHOD MultMatrixLocal, :ptr THIS_
    STD_METHOD RotateAxis, :ptr THIS_, :FLOAT
    STD_METHOD RotateAxisLocal, :ptr THIS_, :FLOAT
    STD_METHOD RotateYawPitchRoll, :THIS_, :FLOAT, :FLOAT
    STD_METHOD RotateYawPitchRollLocal, :THIS_, :FLOAT, :FLOAT
    STD_METHOD Scale, :THIS_, :FLOAT, :FLOAT
    STD_METHOD ScaleLocal, :THIS_, :FLOAT, :FLOAT
    STD_METHOD Translate, :THIS_, :FLOAT, :FLOAT
    STD_METHOD TranslateLocal, :THIS_, :FLOAT, :FLOAT
    STD_METHOD GetTop, :THIS_
  END_DECLARE_INTERFACE_
  ifdef __cplusplus
    ;[...]
  endif
  D3DXCreateMatrixStack proto WIN_STD_CALL_CONV :DWORD, :ptr LPD3DXMATRIXSTACK
  ifdef __cplusplus
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  D3DXSH_MINORDER equ 2
  D3DXSH_MAXORDER equ 6
  D3DXSHEvalDirection proto WIN_STD_CALL_CONV :ptr FLOAT, :UINT, :ptr D3DXVECTOR3
  D3DXSHRotate proto WIN_STD_CALL_CONV :ptr FLOAT, :UINT, :ptr D3DXMATRIX, :ptr FLOAT
  D3DXSHRotateZ proto WIN_STD_CALL_CONV :ptr FLOAT, :UINT, :FLOAT, :ptr FLOAT
  D3DXSHAdd proto WIN_STD_CALL_CONV :ptr FLOAT, :UINT, :ptr FLOAT, :ptr FLOAT
  D3DXSHScale proto WIN_STD_CALL_CONV :ptr FLOAT, :UINT, :ptr FLOAT, :FLOAT
  D3DXSHDot proto WIN_STD_CALL_CONV :UINT, :ptr FLOAT, :ptr FLOAT
  D3DXSHMultiply2 proto WIN_STD_CALL_CONV :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHMultiply3 proto WIN_STD_CALL_CONV :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHMultiply4 proto WIN_STD_CALL_CONV :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHMultiply5 proto WIN_STD_CALL_CONV :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHMultiply6 proto WIN_STD_CALL_CONV :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHEvalDirectionalLight proto WIN_STD_CALL_CONV :UINT, :ptr D3DXVECTOR3, :FLOAT, :FLOAT, :FLOAT, :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHEvalSphericalLight proto WIN_STD_CALL_CONV :UINT, :ptr D3DXVECTOR3, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHEvalConeLight proto WIN_STD_CALL_CONV :UINT, :ptr D3DXVECTOR3, :FLOAT, :FLOAT, :FLOAT, :FLOAT, :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHEvalHemisphereLight proto WIN_STD_CALL_CONV :UINT, :ptr D3DXVECTOR3, :D3DXCOLOR, :D3DXCOLOR, :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  D3DXSHProjectCubeMap proto WIN_STD_CALL_CONV :UINT, :LPDIRECT3DCUBETEXTURE9, :ptr FLOAT, :ptr FLOAT, :ptr FLOAT
  ifdef __cplusplus
    ;[...]
  endif
;  include d3dx9math.inl
  if _MSC_VER ge 1200
  else
  endif
endif

