; ==================================================================================================
; Title:      D3Triangle.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm D3Trinagle implementation.
; ==================================================================================================


; ==================================================================================================
;    D3Triangle implementation
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Triangle.Colorize
; Purpose:    Change the color of a D3Triangle when it is iluminated with a D3Light.
; Arguments:  Arg1: -> D3Light object.
; Return:     Nothing.

CollectionItemAt macro pColl:req, Index:req             ;;Unsafe! No index checking.
  mov xdx, pColl
  mov ecx, Index
  mov xdx, [xdx].$Obj(Collection).pItems
  mov xax, POINTER ptr [xdx + sizeof(POINTER)*xcx]
endm

Method D3Triangle.Colorize, uses xbx xdi xsi, pLight:$ObjPtr(D3Light), Unused:XWORD
  local Vector21:D3Vector, Vector31:D3Vector, Vector1L:D3Vector, NormalVector:D3Vector

  SetObject xsi
  mov xax, [xsi].pOwner                                 ;Triangles collection
  mov xdi, [xax].$Obj(Collection).pOwner                ;D3Object

  CollectionItemAt [xdi].$Obj(D3Object).pVectrons, [xsi].dIndex1
  lea xbx, [xax].D3Vectron.Vt

  CollectionItemAt [xdi].$Obj(D3Object).pVectrons, [xsi].dIndex2
  lea xdx, [xax].D3Vectron.Vt
  invoke VectorSubVector, addr Vector21, xdx, xbx       ;Calc triangle border vector 21

  CollectionItemAt [xdi].$Obj(D3Object).pVectrons, [xsi].dIndex3
  lea xdx, [xax].D3Vectron.Vt
  invoke VectorSubVector, addr Vector31, xdx, xbx       ;Calc triangle border vector 31

  lea xbx, NormalVector
  invoke VectorCrossVector, xbx, addr Vector31, addr Vector21 ;Calc triangle normal vector
  invoke VectorNormalize, xbx, xbx                      ;Normalize it

  lea xdi, Vector1L
  mov xax, pLight
  invoke VectorSubVector, xdi, xbx, addr [xax].$Obj(D3Light).Origin ;Calc light beam vector

  invoke VectorDotVector, xbx, xdi                      ;Calc cos angle between light beam & normal
  invoke VectorModulus, xdi                             ;Calc length of light beam
  fdivp st(1), st(0)                                    ;            (ZF)(PF)(CF)
  ftst                                                  ;Condition    C3  C2  C0
  fstsw ax                                              ;ST(0) > 0.0   0   0   0
  sahf                                                  ;ST(0) < 0.0   0   0   1
                                                        ;ST(0) = 0.0   1   0   0
  .if CARRY?                                            ;Unordered     1   1   1
    ;Colorize the dark side
    xor eax, eax
    mov [xsi].OutColor1, eax
    mov [xsi].OutColor2, eax
    mov [xsi].OutColor3, eax
  .else
    ;Colorize the rest
    movzx xax, [xsi].SrcColor.RGBQUAD.rgbBlue
    fildReg xax                                         ;              2
    fmul st(0), st(1)                                   ;    Normal   /\
    fistpReg xax                                        ;       \  21/  \ Triangle
    mov [xsi].OutColor1.RGBQUAD.rgbBlue, al             ;        \  /    \
                                                        ;         \/______\3
    movzx xax, [xsi].SrcColor.RGBQUAD.rgbGreen             ;         1|  31
    fildReg xax                                         ;          |
    fmul st(0), st(1)                                   ;          |
    fistpReg xax                                        ;          |
    mov [xsi].OutColor1.RGBQUAD.rgbGreen, al            ;        1L| Light beam
                                                        ;          |
    movzx xax, [xsi].SrcColor.RGBQUAD.rgbRed               ;          |
    fildReg xax                                         ;          |
    fmul st(0), st(1)                                   ;         L*
    fistpReg xax                                        ;     Light source
    mov [xsi].OutColor1.RGBQUAD.rgbRed, al

    mov eax, [xsi].OutColor1
    mov [xsi].OutColor2, eax
    mov [xsi].OutColor3, eax
  .endif

  fUnload
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Triangle.Clone
; Purpose:    Duplicate the Triangle and inserts it in the D3Object Triangle collection,
;             updating the Vectrons collection.
; Arguments:  Arg1: -> New D3Object.
; Return:     Nothing.

Method D3Triangle.Clone, uses xbx xdi xsi, pObject:POINTER, Unused:XWORD
  local pTriangle:$ObjPtr(D3Triangle)

  SetObject xsi
  mov xbx, pObject
  mov pTriangle, $New(D3Triangle)
  OCall [xbx].$Obj(D3Object).pTriangles::Collection.Insert, xax
  OCall xax::D3Triangle.Init, [xbx].$Obj(D3Object).pTriangles

  mov xax, [xsi].pOwner                                 ;Triangle collection
  mov xdi, [xax].$Obj(Collection).pOwner                ;D3Object
  OCall [xdi].$Obj(D3Object).pVectrons::D3VectronCollection.ItemAt, [xsi].dIndex1
  OCall [xbx].$Obj(D3Object).pVectrons::D3VectronCollection.Append, addr [xax].D3Vectron.Vt
  mov xcx, pTriangle
  mov [xcx].$Obj(D3Triangle).dIndex1, eax
  OCall [xdi].$Obj(D3Object).pVectrons::D3VectronCollection.ItemAt, [xsi].dIndex2
  OCall [xbx].$Obj(D3Object).pVectrons::D3VectronCollection.Append, addr [xax].D3Vectron.Vt
  mov xcx, pTriangle
  mov [xcx].$Obj(D3Triangle).dIndex2, eax
  OCall [xdi].$Obj(D3Object).pVectrons::D3VectronCollection.ItemAt, [xsi].dIndex3
  OCall [xbx].$Obj(D3Object).pVectrons::D3VectronCollection.Append, addr [xax].D3Vectron.Vt
  mov xcx, pTriangle
  mov [xcx].$Obj(D3Triangle).dIndex3, eax

  m2m [xcx].$Obj(D3Triangle).SrcColor, [xsi].SrcColor, eax
  m2m [xcx].$Obj(D3Triangle).OutColor1, [xsi].OutColor1, eax
  m2m [xcx].$Obj(D3Triangle).OutColor2, [xsi].OutColor2, eax
  m2m [xcx].$Obj(D3Triangle).OutColor3, [xsi].OutColor3, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Triangle.Draw
; Purpose:    Draw a D3Triangle object on the D3Camara DC.
; Arguments:  Arg1: D3Camara DC HANDLE.
;             Arg2: -> D3Camara POINT buffer.
; Return:     Nothing.

SetVertex macro Arg:req, UseSourceColor:=<FALSE>
  GetD3VectorFromTable pObjProj, [xsi].dIndex&Arg
  ;Convert coordinates from real4 to integer
  lea xcx, TrVx3.V&Arg
  fld [xax].D3Vector.r4X
  fistp [xcx].TriVertex.sdX
  fld [xax].D3Vector.r4Y
  fistp [xcx].TriVertex.sdY
  ;Copy colors from BYTE to WORD
  if UseSourceColor eq FALSE
    mov al, [xsi].OutColor&Arg.RGBQUAD.rgbRed
    shl ax, 8
    mov [xcx].TriVertex.wRed, ax
    mov al, [xsi].OutColor&Arg.RGBQUAD.rgbGreen
    shl ax, 8
    mov [xcx].TriVertex.wGreen, ax
    mov al, [xsi].OutColor&Arg.RGBQUAD.rgbBlue
    shl ax, 8
    mov [xcx].TriVertex.wBlue, ax
  else
    mov al, [xsi].SrcColor.RGBQUAD.rgbRed
    shl ax, 8
    mov [xcx].TriVertex.wRed, ax
    mov al, [xsi].SrcColor.RGBQUAD.rgbGreen
    shl ax, 8
    mov [xcx].TriVertex.wGreen, ax
    mov al, [xsi].SrcColor.RGBQUAD.rgbBlue
    shl ax, 8
    mov [xcx].TriVertex.wBlue, ax
  endif
endm

SetPoint macro Idx:req
  GetD3VectorFromTable pObjProj, [xsi].dIndex&Idx
  lea xcx, Poly3.P&Idx
  fld [xax].D3Vector.r4X
  fistp [xcx].POINT.x
  fld [xax].D3Vector.r4Y
  fistp [xcx].POINT.y
endm

Polygon3 struc
  P1  POINT   {?, ?}
  P2  POINT   {?, ?}
  P3  POINT   {?, ?}
Polygon3 ends

;; % includelib ...\Msimg32.lib  is needed
TriVertex3 struc
  V1  TriVertex   {?, ?, ?, ?, ?, ?}
  V2  TriVertex   {?, ?, ?, ?, ?, ?}
  V3  TriVertex   {?, ?, ?, ?, ?, ?}
TriVertex3 ends

.const
  D3GRADIENTTRIANGLE  GradientTriangle  {0, 1, 2}

.code
Method D3Triangle.Draw, uses xsi, hDC:HDC, pObjProj:POINTER
  local TrVx3:TriVertex3, Poly3:Polygon3
  local hPrevBrush:HBRUSH, hBrush:HBRUSH
  local hPrevPen:HPEN, hPen:HPEN

  SetObject xsi
  SetVertex 1
  SetVertex 2
  SetVertex 3
  invoke GradientFill, hDC, addr TrVx3, 3, offset D3GRADIENTTRIANGLE, 1, GRADIENT_FILL_TRIANGLE

;  SetPoint 1
;  SetPoint 2
;  SetPoint 3
;  mov hBrush, $invoke(CreateSolidBrush, DWORD ptr [xsi].OutColor1)
;  mov hPen, $invoke(CreatePen, PS_SOLID, 1, DWORD ptr [xsi].SrcColor)
;  mov hPrevBrush, $invoke(SelectObject, hDC, hBrush)
;  mov hPrevPen, $invoke(SelectObject, hDC, hPen)
;  invoke SetDCBrushColor, hDC, DWORD ptr [xsi].SrcColor
;  invoke SetDCPenColor, hDC, DWORD ptr [xsi].SrcColor
;  invoke Polygon, hDC, addr Poly3, 4
;  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevPen)
;  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevBrush)
MethodEnd

;Method D3Triangle.Draw, uses xsi, hDC:HDC, pObjProj:POINTER
;  local Poly3:Polygon3, hPrevBrush:HBRUSH, hBrush:HBRUSH
;
;  SetObject xsi
;  SetPoint 1
;  SetPoint 2
;  SetPoint 3
;  mov hBrush, $invoke(CreateSolidBrush, DWORD ptr [xsi].OutColor1)
;  mov hPrevBrush, $invoke(SelectObject, hDC, hBrush)
;  invoke Polygon, hDC, addr Poly3, 3
;  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevBrush)
;MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Triangle.Load
; Purpose:    Load and initializes the D3Triangle object from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method D3Triangle.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  mov [xsi].bTransparency, $8($OCall(pStream::Stream.BinRead8))
  mov [xsi].bEmisivity,    $8($OCall(pStream::Stream.BinRead8))
  mov [xsi].bReflectivity, $8($OCall(pStream::Stream.BinRead8))
  mov [xsi].bBrillance,    $8($OCall(pStream::Stream.BinRead8))
  mov [xsi].dIndex1,       $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dIndex2,       $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dIndex3,       $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].SrcColor,      $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].OutColor1,     $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].OutColor2,     $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].OutColor3,     $32($OCall(pStream::Stream.BinRead32))
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Triangle.Store
; Purpose:    Store the D3Triangle object in a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method D3Triangle.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite8,  [xsi].bTransparency
  OCall pStream::Stream.BinWrite8,  [xsi].bEmisivity
  OCall pStream::Stream.BinWrite8,  [xsi].bReflectivity
  OCall pStream::Stream.BinWrite8,  [xsi].bBrillance
  OCall pStream::Stream.BinWrite32, [xsi].dIndex1
  OCall pStream::Stream.BinWrite32, [xsi].dIndex2
  OCall pStream::Stream.BinWrite32, [xsi].dIndex3
  OCall pStream::Stream.BinWrite32, [xsi].SrcColor
  OCall pStream::Stream.BinWrite32, [xsi].OutColor1
  OCall pStream::Stream.BinWrite32, [xsi].OutColor2
  OCall pStream::Stream.BinWrite32, [xsi].OutColor3
MethodEnd
