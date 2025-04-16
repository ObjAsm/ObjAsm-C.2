; ==================================================================================================
; Title:      D3Math.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm D3Vector math procedures.
; ==================================================================================================


; ==================================================================================================
;    Structures, constants and definitions
; ==================================================================================================

Pi          equ         3.14159265359
r8Deg2Rad   equ         Pi/30
r8Rad2Deg   equ         30/Pi

r4Half      equ         3F000000h                       ;Binary representation of REAL4 0.5
r4One       equ         3F800000h                       ;Binary representation of REAL4 1.0
r4Two       equ         40000000h                       ;Binary representation of REAL4 2.0

; --------------------------------------------------------------------------------------------------
GetD3VectorFromTable macro Base:req, Index32:req, RegOut:=<xax>
  mov $SubReg(RegOut, 4), Index32
  shl RegOut, 2                                         ;;Size of D3Vector = 12 bytes
  lea RegOut, [RegOut + 2*RegOut]
  add RegOut, Base
endm

; --------------------------------------------------------------------------------------------------
Rotate macro X:req, Y:req, Z:req
  ?mov ecx, pVectron
  ?mov edx, xUseVo
  lea xax, [xcx + sizeof(D3Vector)]                     ;xax -> Vt
  .if edx == FALSE                                      ;xUseVo
    mov xdx, xax                                        ;xdx -> Vt
  .else
    mov xdx, xcx                                        ;xdx -> Vo
    m2m [xax].D3Vector.X, [xdx].D3Vector.X, xcx
  .endif
  ;FPU register usage           ;    0    |    1    |    2    |    3    |    4
                                ;   cos   |   sin   |         |         |
  fld [xdx].D3Vector.Y          ;    Y    |   cos   |   sin   |         |
  fmul st(0), st(1)             ;   Ycos  |   cos   |   sin   |         |
  fld [xdx].D3Vector.Z          ;    Z    |   Ycos  |   cos   |   sin   |
  fmul st(0), st(3)             ;   Zsin  |   Ycos  |   cos   |   sin   |
  faddp st(1), st(0)            ;Ycos+Zsin|   cos   |   sin   |         |
  fld [xdx].D3Vector.Z          ;    Z    |Ycos+Zsin|   cos   |   sin   |
  fmul st(0), st(2)             ;   Zcos  |Ycos+Zsin|   cos   |   sin   |
  fld [xdx].D3Vector.Y          ;    Y    |   Zcos  |Ycos+Zsin|   cos   |   sin
  fmul st(0), st(4)             ;   Ysin  |   Zcos  |Ycos+Zsin|   cos   |   sin
  fsubp st(1), st(0)            ;Ysin-Zcos|Ycos+Zsin|   cos   |   sin   |
  fstp [xax].D3Vector.Z         ;Ycos+Zsin|   cos   |   sin   |         |
  fstp [xax].D3Vector.Y         ;   cos   |   sin   |         |         |
endm
; --------------------------------------------------------------------------------------------------
RotateX proc pVectron:PD3Vectron, xUseVo:XWORD, xUnused:XWORD
  Rotate r4X, r4Y, r4Z
  ret
RotateX endp

; --------------------------------------------------------------------------------------------------
RotateY proc pVectron:PD3Vectron, xUseVo:XWORD, xUnused:XWORD
  Rotate r4Y, r4X, r4Z
  ret
RotateY endp

; --------------------------------------------------------------------------------------------------
RotateZ proc pVectron:PD3Vectron, xUseVo:XWORD, xUnused:XWORD
  Rotate r4Z, r4X, r4Y
  ret
RotateZ endp

; --------------------------------------------------------------------------------------------------
Translate proc pVectron:PD3Vectron, xUseVo:XWORD, xUnused:XWORD
  ?mov ecx, pVectron
  ?mov edx, xUseVo
  lea xax, [xcx + sizeof(D3Vector)]
  cmp edx, FALSE
  cmovz xdx, xax
  cmovnz xdx, xcx
  ;FPU register usage           ;    0    |    1    |    2    |    3    |    4    |    5
  fld [xdx].D3Vector.r4X        ;   r4X   |  DispZ  |  DispY  |  DispX  |         |
  fadd st(0), st(3)             ;r4X+DispX|  DispZ  |  DispY  |  DispX  |         |
  fld [xdx].D3Vector.r4Y        ;   r4Y   |r4X+DispX|  DispZ  |  DispY  |  DispX  |
  fadd st(0), st(3)             ;r4Y+DispY|r4X+DispX|  DispZ  |  DispY  |  DispX  |
  fld [xdx].D3Vector.r4Z        ;   r4Z   |r4Y+DispY|r4X+DispX|  DispZ  |  DispY  |  DispX
  fadd st(0), st(3)             ;r4Z+DispZ|r4Y+DispY|r4X+DispX|  DispZ  |  DispY  |  DispX

  fstp [xax].D3Vector.r4Z       ;r4Y+DispY|r4X+DispX|  DispZ  |  DispY  |  DispX
  fstp [xax].D3Vector.r4Y       ;r4X+DispX|  DispZ  |  DispY  |  DispX  |
  fstp [xax].D3Vector.r4X       ;  DispZ  |  DispY  |  DispX  |         |
  ret
Translate endp

; --------------------------------------------------------------------------------------------------
MoveVo2Vt proc pVectron:PD3Vectron, xUnused1:XWORD, xUnused2:XWORD
  ?mov ecx, pVectron
  s2s [xcx].D3Vectron.Vt, [xcx].D3Vectron.Vo, xmm0, xmm1, xax, xdx
  ret
MoveVo2Vt endp

; --------------------------------------------------------------------------------------------------
VectorCrossVector proc pDstVector:PD3Vector, pSrcVector1:PD3Vector, pSrcVector2:PD3Vector
  ?mov ecx, pDstVector
  ?mov edx, pSrcVector1
  mov xax, pSrcVector2
  fld [xdx].D3Vector.r4Y
  fmul [xax].D3Vector.r4Z
  fld [xax].D3Vector.r4Y
  fmul [xdx].D3Vector.r4Z
  fsubp st(1), st(0)
  fstp [xcx].D3Vector.r4X

  fld [xax].D3Vector.r4X
  fmul [xdx].D3Vector.r4Z
  fld [xdx].D3Vector.r4X
  fmul [xax].D3Vector.r4Z
  fsubp st(1), st(0)
  fstp [xcx].D3Vector.r4Y

  fld [xdx].D3Vector.r4X
  fmul [xax].D3Vector.r4Y
  fld [xax].D3Vector.r4X
  fmul [xdx].D3Vector.r4Y
  fsubp st(1), st(0)
  fstp [xcx].D3Vector.r4Z

  ret
VectorCrossVector endp

; --------------------------------------------------------------------------------------------------
VectorDotVector proc pVector1:PD3Vector, pVector2:PD3Vector
  ?mov ecx, pVector1
  ?mov edx, pVector2
  fld [xcx].D3Vector.r4X
  fmul [xdx].D3Vector.r4X
  fld [xcx].D3Vector.r4Y
  fmul [xdx].D3Vector.r4Y
  fld [xcx].D3Vector.r4Z
  fmul [xdx].D3Vector.r4Z
  faddp st(1), st(0)
  faddp st(1), st(0)
  ret
VectorDotVector endp

; --------------------------------------------------------------------------------------------------
VectorCrossVectorDotVector proc pVector1:PD3Vector, pVector2:PD3Vector, pVector3:PD3Vector
  ?mov ecx, pVector1
  ?mov edx, pVector2
  mov xax, pVector3
  fld [xcx].D3Vector.r4Y
  fmul [xdx].D3Vector.r4Z
  fld [xdx].D3Vector.r4Y
  fmul [xcx].D3Vector.r4Z
  fsubp st(1), st(0)
  fmul [xax].D3Vector.r4X

  fld [xdx].D3Vector.r4X
  fmul [xcx].D3Vector.r4Z
  fld [xcx].D3Vector.r4X
  fmul [xdx].D3Vector.r4Z
  fsubp st(1), st(0)
  fmul [xax].D3Vector.r4Y
  faddp st(1), st(0)

  fld [xcx].D3Vector.r4X
  fmul [xdx].D3Vector.r4Y
  fld [xdx].D3Vector.r4X
  fmul [xcx].D3Vector.r4Y
  fsubp st(1), st(0)
  fmul [xax].D3Vector.r4Z
  faddp st(1), st(0)

  ret
VectorCrossVectorDotVector endp

; --------------------------------------------------------------------------------------------------
VectorAddVector proc pDstVector:PD3Vector, pSrcVector1:PD3Vector, pSrcVector2:PD3Vector
  ?mov ecx, pDstVector
  ?mov edx, pSrcVector1
  mov xax, pSrcVector2
  fld [xdx].D3Vector.r4X
  fadd [xax].D3Vector.r4X
  fld [xdx].D3Vector.r4Y
  fadd [xax].D3Vector.r4Y
  fld [xdx].D3Vector.r4Z
  fadd [xax].D3Vector.r4Z

  fstp [xcx].D3Vector.r4Z
  fstp [xcx].D3Vector.r4Y
  fstp [xcx].D3Vector.r4X
  ret
VectorAddVector endp

; --------------------------------------------------------------------------------------------------
VectorSubVector proc pDstVector:PD3Vector, pSrcVector1:PD3Vector, pSrcVector2:PD3Vector
  ?mov ecx, pDstVector
  ?mov edx, pSrcVector1
  mov xax, pSrcVector2
  fld [xdx].D3Vector.r4X
  fsub [xax].D3Vector.r4X
  fld [xdx].D3Vector.r4Y
  fsub [xax].D3Vector.r4Y
  fld [xdx].D3Vector.r4Z
  fsub [xax].D3Vector.r4Z

  fstp [xcx].D3Vector.r4Z
  fstp [xcx].D3Vector.r4Y
  fstp [xcx].D3Vector.r4X
  ret
VectorSubVector endp

; --------------------------------------------------------------------------------------------------
VectorModulus proc pVector:PD3Vector
  ?mov ecx, pVector
  fld [xcx].D3Vector.r4X
  fmul [xcx].D3Vector.r4X
  fld [xcx].D3Vector.r4Y
  fmul [xcx].D3Vector.r4Y
  faddp st(1), st(0)
  fld [xcx].D3Vector.r4Z
  fmul [xcx].D3Vector.r4Z
  faddp st(1), st(0)
  fsqrt
  ret
VectorModulus endp

; --------------------------------------------------------------------------------------------------
VectorScale proc pDstVector:PD3Vector, pSrcVector:PD3Vector, pFactor:PD3Vector
  ?mov ecx, pDstVector
  ?mov edx, pSrcVector
  mov xax, pFactor
  fld1
  fld REAL4 ptr [xax]
  fdivp st(1), st(0)
  fld [xdx].D3Vector.r4X
  fmul st(0), st(1)
  fstp [xcx].D3Vector.r4X
  fld [xdx].D3Vector.r4Y
  fmul st(0), st(1)
  fstp [xcx].D3Vector.r4Y
  fld [xdx].D3Vector.r4Z
  fmul st(0), st(1)
  fstp [xcx].D3Vector.r4Z
  fUnload
  ret
VectorScale endp

; --------------------------------------------------------------------------------------------------
VectorNormalize proc pDstVector:PD3Vector, pSrcVector:PD3Vector
  ?mov ecx, pDstVector
  ?mov edx, pSrcVector
  ;Get Vector Modulus
  fld1
  fld [xdx].D3Vector.r4X
  fmul [xdx].D3Vector.r4X
  fld [xdx].D3Vector.r4Y
  fmul [xdx].D3Vector.r4Y
  fld [xdx].D3Vector.r4Z
  fmul [xdx].D3Vector.r4Z
  faddp st(1), st(0)
  faddp st(1), st(0)
  fsqrt
  fdivp st(1), st(0)

  ;Scale the SrcVector and store it as DstVector
  fld [xdx].D3Vector.r4X
  fmul st(0), st(1)
  fstp [xcx].D3Vector.r4X
  fld [xdx].D3Vector.r4Y
  fmul st(0), st(1)
  fstp [xcx].D3Vector.r4Y
  fld [xdx].D3Vector.r4Z
  fmul st(0), st(1)
  fstp [xcx].D3Vector.r4Z
  fUnload

  ret
VectorNormalize endp
