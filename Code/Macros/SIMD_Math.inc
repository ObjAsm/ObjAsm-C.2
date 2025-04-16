; ==================================================================================================
; Title:      SIMD_Math.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    SIMD (MMX, SSE, SEE2, SSE3, AVX, AVX2, etc.) math macros.
; Links:      http://softpixel.com/~cwright/programming/simd/
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



; --------------------------------------------------------------------------------------------------
; Macro:      Vec4_SquareMagnitude_SSE
; Purpose:    Calculate the squared magnitude of a VEC4.
; Arguments:  Arg1: xmm register holding the VEC4.
;             Arg2: xmm auxiliary register.
; Notes:      Output = Arg1.

Vec4_SquareMagnitude_SSE macro xSrcReg:req, xAuxReg:req
  mulps xmm&xSrcReg, xmm&xSrcReg                        ;;square vector elements
  movaps xmm&xAuxReg, xmm&xSrcReg                       ;;make a copy
  shufps xmm&xSrcReg, xmm&xAuxReg, 01001110b            ;;first addition of elements using shuffle
  addps xmm&xSrcReg, xmm&xAuxReg
  movaps xmm&xAuxReg, xmm&xSrcReg                       ;;make a copy
  shufps xmm&xAuxReg, xmm&xAuxReg, 00010001b            ;;second addition of elements using shuffle
  addps xmm&xSrcReg, xmm&xAuxReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Vec4_Magnitude_SSE
; Purpose:    Calculate the magnitude of a VEC4.
; Arguments:  Arg1: xmm register holding the VEC4.
;             Arg2: xmm auxiliary register.
; Notes:      Output = Arg1.

Vec4_Magnitude_SSE macro xSrcReg:req, xAuxReg:req
  Vec4_SquareMagnitude_SSE xSrcReg, xAuxReg
  sqrtps xmm&xSrcReg, xmm&xSrcReg                       ;;get the square root
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Vec4_Normalize_SSE
; Purpose:    Normalize a VEC4.
; Arguments:  Arg1: xmm register holding the VEC4.
;             Arg2..3: xmm auxiliary registers.
; Notes:      Output = Arg1.
; Link:       http://www.3dbuzz.com/vbforum/showthread.php?104753-HowTo-Inline-Assembly-amp-SSE-Vector-normalization-done-fast!

Vec4_Normalize_SSE macro xSrcReg:req, xAuxReg1:req, xAuxReg2:req
  movaps xmm&xAuxReg2, xmm&xSrcReg                      ;;make a copy
  Vec4_SquareMagnitude_SSE xSrcReg, xAuxReg1
  rsqrtps xmm&xSrcReg, xmm&xSrcReg
  mulps xmm&xSrcReg, xmm&xAuxReg2
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Vec4_CrossProduct_SSE
; Purpose:    Calculate the cross product of 2 VEC4.
; Arguments:  Arg1: xmm register holding the first VEC4.
;             Arg2: xmm register holding the second VEC4.
;             Arg3..4: xmm auxiliary registers.
; Link:       http://neilkemp.us/src/sse_tutorial/sse_tutorial.html
; Notes:      Output = Arg1.

Vec4_CrossProduct_SSE macro xSrcReg1:req, xSrcReg2:req, xAuxReg1, xAuxReg2
  movaps xmm&xAuxReg1, xmm&xSrcReg1                     ;;make a copy of vector 1
  movaps xmm&xAuxReg2, xmm&xSrcReg2                     ;;make a copy of vector 2

  shufps xmm&xSrcReg1, xmm&xSrcReg1, 11011000b          ;;flip the middle elements of 1
  shufps xmm&xSrcReg2, xmm&xSrcReg2, 11100001b          ;;flip first two elements of 2
  mulps  xmm&xSrcReg1, xmm&xSrcReg2                     ;;multiply the modified register vectors

  shufps xmm&xAuxReg1, xmm&xAuxReg1, 11100001b          ;;flip first two elements of the a copy
  shufps xmm&xAuxReg2, xmm&xAuxReg2, 11011000b          ;;flip the middle elements of the b copy
  mulps xmm&xAuxReg1, xmm&xAuxReg2                      ;;multiply the modified register vectors

  subps xmm&xSrcReg1, xmm&xAuxReg1                      ;;subtract the two resulting register vectors
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Vec4_DotProduct_SSE
; Purpose:    Calculate the dot product of 2 VEC4.
; Arguments:  Arg1: xmm register holding the first VEC4.
;             Arg2: xmm register holding the second VEC4.
;             Arg3: xmm auxiliary register.
; Notes:      Output = Arg1.

Vec4_DotProduct_SSE macro xSrcReg1:req, xSrcReg2:req, xAuxReg:req
  mulps xmm&xSrcReg1, xmm&xSrcReg2
  movaps xmm&xAuxReg, xmm&xSrcReg1
  shufps xmm&xSrcReg1, xmm&xSrcReg1, 01001110b
  addps xmm&xSrcReg1, xmm&xAuxReg
  shufps xmm&xAuxReg, xmm&xAuxReg, 00010001b
  addps xmm&xSrcReg1, xmm&xAuxReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Load_A_SSE
; Purpose:    Load a matrix from aligned memory to xmm registers.
; Arguments:  Arg1: -> MAT44.
;             Arg2..5: xmm registers that will recieve the MAT44 rows.

Mat44_Load_A_SSE macro SrcReg, xReg1:req, xReg2:req, xReg3:req, xReg4:req
  movaps xmm&xReg1, [SrcReg]
  movaps xmm&xReg2, [SrcReg + 010h]
  movaps xmm&xReg3, [SrcReg + 020h]
  movaps xmm&xReg4, [SrcReg + 030h]
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Load_U_SSE
; Purpose:    Load a matrix from unaligned memory to xmm registers.
; Arguments:  Arg1: -> MAT44.
;             Arg2..5: xmm registers that will recieve the MAT44 rows.

Mat44_Load_U_SSE macro SrcReg, xReg1:req, xReg2:req, xReg3:req, xReg4:req
  movups xmm&xReg1, [SrcReg]
  movups xmm&xReg2, [SrcReg + 010h]
  movups xmm&xReg3, [SrcReg + 020h]
  movups xmm&xReg4, [SrcReg + 030h]
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Store_A_SSE
; Purpose:    Store a matrix from xmm registers to aligned memory.
; Arguments:  Arg1: -> MAT44.
;             Arg2..5: xmm registers that will recieve the MAT44 rows.

Mat44_Store_A_SSE macro SrcReg, xReg1:req, xReg2:req, xReg3:req, xReg4:req
  movaps [SrcReg], xmm&xReg1
  movaps [SrcReg + 010h], xmm&xReg2
  movaps [SrcReg + 020h], xmm&xReg3
  movaps [SrcReg + 030h], xmm&xReg4
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Store_U_SSE
; Purpose:    Store a matrix from xmm registers to unaligned memory.
; Arguments:  Arg1: -> MAT44.
;             Arg2..5: xmm registers that will recieve the MAT44 rows.

Mat44_Store_U_SSE macro SrcReg, xReg1:req, xReg2:req, xReg3:req, xReg4:req
  movups [SrcReg], xmm&xReg1
  movups [SrcReg + 010h], xmm&xReg2
  movups [SrcReg + 020h], xmm&xReg3
  movups [SrcReg + 030h], xmm&xReg4
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Transpose_SSE
; Purpose:    Transpose the MAT44 loaded in xmm registers.
; Arguments:  Arg1..4: xmm registers holding the MAT44 columns.
;             Arg5: auxiliary xmm register.
; Notes:      Output = Arg1..4 xmm registers holding the MAT44 rows.

Mat44_Transpose_SSE macro xReg1:req, xReg2:req, xReg3:req, xReg4:req, xRegAux:req
  movaps xmm&xRegAux, xmm&xReg3                         ;;xmm&xRegAux: c4 c3 c2 c1
  punpckldq xmm&xReg3, xmm&xReg4                        ;;xmm&xReg3:   d2 c2 d1 c1
  punpckhdq xmm&xRegAux, xmm&xReg4                      ;;xmm&xRegAux: d4 c4 d3 c3

  movaps xmm&xReg4, xmm&xReg1                           ;;xmm&xReg4:   a4 a3 a2 a1
  punpckldq xmm&xReg1, xmm&xReg2                        ;;xmm&xReg1:   b2 a2 b1 a1
  punpckhdq xmm&xReg4, xmm&xReg2                        ;;xmm&xReg4:   b4 a4 b3 a3

  movaps xmm&xReg2, xmm&xReg1                           ;;xmm&xReg2:   b2 a2 b1 a1
  punpcklqdq xmm&xReg1, xmm&xReg3                       ;;xmm&xReg1:   d1 c1 b1 a1
  punpckhqdq xmm&xReg2, xmm&xReg3                       ;;xmm&xReg2:   d2 c2 b2 a2

  movaps xmm&xReg3, xmm&xReg4                           ;;xmm&xReg3:   b4 a4 b3 a3
  punpckhqdq xmm&xReg4, xmm&xRegAux                     ;;xmm&xReg4:   d4 c4 b4 a4
  punpcklqdq xmm&xReg3, xmm&xRegAux                     ;;xmm&xReg3:   d3 c3 b3 a3
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Transpose_SSE_2
; Purpose:    Transpose the MAT44 loaded in xmm registers.
;             This code is somewhat slower as Mat44_Transpose_SSE but can be compiled with ML6.15
; Arguments:  Arg1..4: xmm registers holding the MAT44 columns.
;             Arg5..6: auxiliary xmm registers.
; Notes:      Output = Arg1..4 xmm registers holding the MAT44 rows.

Mat44_Transpose_SSE_2 macro xReg1:req, xReg2:req, xReg3:req, xReg4:req, xRegAux1:req, xRegAux2:req
  movaps xmm&xRegAux1, xmm&xReg1
  movaps xmm&xRegAux2, xmm&xReg3
  shufps xmm&xReg1, xmm&xReg2, 01000100b
  shufps xmm&xRegAux1, xmm&xReg2, 11101110b
  shufps xmm&xReg3, xmm&xReg4, 01000100b
  movaps xmm&xReg2, xmm&xReg1
  shufps xmm&xRegAux2, xmm&xReg4, 11101110b
  shufps xmm&xReg1, xmm&xReg3, 10001000b
  movaps xmm&xReg4, xmm&xRegAux1
  shufps xmm&xReg2, xmm&xReg3, 11011101b
  movaps xmm&xReg3, xmm&xRegAux1
  shufps xmm&xReg4, xmm&xRegAux2, 11011101b
  shufps xmm&xReg3, xmm&xRegAux2, 10001000b
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Mat44_Mult_Vec4_SSE
; Purpose:    Mutiplication of MAT44 by VEC4
; Arguments:  Arg1..4: xmm registers holding the MAT44 columns.
;             Arg5: xmm register holding the input VEC4.
;             Arg6..8: auxiliary xmm registers.
; Notes:      Output = Arg5.

Mat44_Mult_Vec4_SSE macro xCol1, xCol2, xCol3, xCol4, xVec, xAux1, xAux2, xAux3
  movaps xmm&xAux1, xmm&xVec
  movaps xmm&xAux2, xmm&xVec
  movaps xmm&xAux3, xmm&xVec

  shufps xmm&xVec,  xmm&xVec,  00000000b                ;;broadcast x
  shufps xmm&xAux1, xmm&xAux1, 01010101b                ;;broadcast y
  shufps xmm&xAux2, xmm&xAux2, 10101010b                ;;broadcast z
  shufps xmm&xAux3, xmm&xAux3, 11111111b                ;;broadcast w

  mulps xmm&xVec,  xmm&xCol1
  mulps xmm&xAux1, xmm&xCol2
  mulps xmm&xAux2, xmm&xCol3
  mulps xmm&xAux3, xmm&xCol4

  addps xmm&xVec, xmm&xAux1
  addps xmm&xVec, xmm&xAux2
  addps xmm&xVec, xmm&xAux3
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Real8ToXmm
; Purpose:    Moves Real8 values to an xmm register
; Arguments:  Arg1: Real8 value
;             Arg2: Real8 value
; Example:    movaps xmm15, XMMWORD ptr Real8ToXmm(1.0, -1.0)

Real8ToXmm macro par1, par2
  local xmmValue

  .data
  align 16
  xmmValue dq par1, par2
  .code
  exitm <xmmValue>
endm
