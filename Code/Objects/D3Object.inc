; ==================================================================================================
; Title:      D3Object.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm D3Object implementation.
; ==================================================================================================


; ==================================================================================================
;    D3Object implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.AddPoint
; Purpose:    Add a D3Point to the D3Object object.
; Arguments:  Arg1: -> D3Vector structure pointing to the point.
;             Arg2: RGB color value of the point.
; Return:     Nothing.

Method D3Object.AddPoint, uses xbx xsi, pVector:PD3Vector, dColor:DWORD
  SetObject xsi
  mov xbx, $New(D3Triangle)
  OCall xbx::D3Triangle.Init, [xsi].pTriangles
  OCall [xsi].pTriangles::Collection.Insert, xbx
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector
  mov [xbx].$Obj(D3Triangle).dIndex1, eax
  mov [xbx].$Obj(D3Triangle).dIndex2, eax
  mov [xbx].$Obj(D3Triangle).dIndex3, eax
  mov eax, dColor
  mov [xbx].$Obj(D3Triangle).SrcColor, eax
  mov [xbx].$Obj(D3Triangle).OutColor1, eax
  mov [xbx].$Obj(D3Triangle).OutColor2, eax
  mov [xbx].$Obj(D3Triangle).OutColor3, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.AddLine
; Purpose:    Add a D3Line to the D3Object object.
; Arguments:  Arg1: -> D3Vector structure pointing to the first point.
;             Arg2: -> D3Vector structure pointing to the second point.
;             Arg3: RGB color value of the line.
; Return:     Nothing.

Method D3Object.AddLine, uses xbx xsi, pVector1:PD3Vector, pVector2:PD3Vector, dColor:DWORD
  SetObject xsi
  mov xbx, $New(D3Triangle)
  OCall xbx::D3Triangle.Init, [xsi].pTriangles
  OCall [xsi].pTriangles::Collection.Insert, xbx
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector1
  mov [xbx].$Obj(D3Triangle).dIndex1, eax
  mov [xbx].$Obj(D3Triangle).dIndex2, eax
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector2
  mov [xbx].$Obj(D3Triangle).dIndex3, eax
  mov eax, dColor
  mov [xbx].$Obj(D3Triangle).SrcColor, eax
  mov [xbx].$Obj(D3Triangle).OutColor1, eax
  mov [xbx].$Obj(D3Triangle).OutColor2, eax
  mov [xbx].$Obj(D3Triangle).OutColor3, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.AddObject
; Purpose:    Merge 2 D3Objects to one.
; Arguments:  Arg1: -> D3Object.
; Return:     xax -> Added D3Object.
; Note:       The D3Object still exist. If not longer needed, destroy it!

Method D3Object.AddObject, uses xsi, pObject:POINTER
  mov xsi, pObject
  OCall [xsi].$Obj(D3Object).pTriangles::Collection.ForEach, $MethodAddr(D3Triangle.Clone), pSelf, NULL
  mov xax, xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.AddRectangle
; Purpose:    Add a rectangle to the D3Object object. (2 triangles)
; Arguments:  Arg1: -> D3Vector structure pointing to the first point.
;             Arg2: -> D3Vector structure pointing to the second point.
;             Arg3: -> D3Vector structure pointing to the third point.
;             Arg4: -> D3Vector structure pointing to the fourth point.
;             Arg5: RGB color value of the rectangle.
; Return:     Nothing.

Method D3Object.AddRectangle, uses xbx xdi xsi, pVector1:PD3Vector, pVector2:PD3Vector, \
                                                pVector3:PD3Vector, pVector4:PD3Vector, dColor:DWORD
  SetObject xsi
  mov xbx, $New(D3Triangle)
  OCall xbx::D3Triangle.Init, [xsi].pTriangles
  OCall [xsi].pTriangles::Collection.Insert, xbx
  mov xdi, $New(D3Triangle)
  OCall xdi::D3Triangle.Init, [xsi].pTriangles
  OCall [xsi].pTriangles::Collection.Insert, xdi

  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector1
  mov [xbx].$Obj(D3Triangle).dIndex1, eax
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector2
  mov [xbx].$Obj(D3Triangle).dIndex2, eax
  mov [xdi].$Obj(D3Triangle).dIndex3, eax
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector3
  mov [xdi].$Obj(D3Triangle).dIndex1, eax
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector4
  mov [xbx].$Obj(D3Triangle).dIndex3, eax
  mov [xdi].$Obj(D3Triangle).dIndex2, eax

  mov eax, dColor
  mov [xbx].$Obj(D3Triangle).SrcColor, eax
  mov [xbx].$Obj(D3Triangle).OutColor1, eax
  mov [xbx].$Obj(D3Triangle).OutColor2, eax
  mov [xbx].$Obj(D3Triangle).OutColor3, eax
  mov [xdi].$Obj(D3Triangle).SrcColor, eax
  mov [xdi].$Obj(D3Triangle).OutColor1, eax
  mov [xdi].$Obj(D3Triangle).OutColor2, eax
  mov [xdi].$Obj(D3Triangle).OutColor3, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.AddTriangle
; Purpose:    Add a D3Triangle to the D3Object object.
; Arguments:  Arg1: -> D3Vector structure pointing to the first point.
;             Arg2: -> D3Vector structure pointing to the second point.
;             Arg3: -> D3Vector structure pointing to the third point.
;             Arg4: RGB color value of the triangle.
; Return:     Nothing.

Method D3Object.AddTriangle, uses xbx xsi, pVector1:PD3Vector, pVector2:PD3Vector, \
                                           pVector3:PD3Vector, dColor:DWORD
  SetObject xsi
  mov xbx, $New(D3Triangle)
  OCall xbx::D3Triangle.Init, [xsi].pTriangles
  OCall [xsi].pTriangles::Collection.Insert, xbx
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector1
  mov [xbx].$Obj(D3Triangle).dIndex1, eax
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector2
  mov [xbx].$Obj(D3Triangle).dIndex2, eax
  OCall [xsi].pVectrons::D3VectronCollection.Append, pVector3
  mov [xbx].$Obj(D3Triangle).dIndex3, eax
  mov eax, dColor
  mov [xbx].$Obj(D3Triangle).SrcColor, eax
  mov [xbx].$Obj(D3Triangle).OutColor1, eax
  mov [xbx].$Obj(D3Triangle).OutColor2, eax
  mov [xbx].$Obj(D3Triangle).OutColor3, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Deserialize
; Purpose:    Convert serialized members.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method D3Object.Deserialize, uses xsi, pDeserInfo:PDESER_INFO
;  DbgText "D3Object.Deserialize"
  SetObject xsi
  ACall xsi.Deserialize, pDeserInfo
  OCall [xsi].pTriangles::Collection.Deserialize, pDeserInfo
  OCall [xsi].pVectrons::D3VectronCollection.Deserialize, pDeserInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Done
; Purpose:    Finalize the D3Object object.
; Arguments:  None.
; Return:     Nothing.

Method D3Object.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pVectrons
  Destroy [xsi].pTriangles
  ACall Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.InfoAddTriCount
; Purpose:    Add the number of triangles in this object to a given DWORD.
; Arguments:  Arg1: -> Acummulating count.
; Return:     Nothing.

Method D3Object.InfoAddTriCount,, pCount:POINTER, Unused:XWORD
  SetObject xdx
  mov xcx, [xdx].pTriangles
  mov eax, [xcx].$Obj(Collection).dCount
  mov xdx, pCount
  add DWORD ptr [xdx], eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Init
; Purpose:    Initialize the D3Object object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method D3Object.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].pTriangles, $New(Collection)
  OCall [xsi].pTriangles::Collection.Init, xsi, 300, 300, COL_MAX_CAPACITY
  mov [xsi].pVectrons, $New(D3VectronCollection)
  OCall [xsi].pVectrons::D3VectronCollection.Init, xsi, 100, 100, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Load
; Purpose:    Load a D3Object from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method D3Object.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  mov [xsi].pVectrons, $OCall(pStream::DiskStream.Get, pDeserInfo)
  mov [xsi].pTriangles, $OCall(pStream::DiskStream.Get, pDeserInfo)
  mov [xsi].dFlags, $32($OCall(pStream::Stream.BinRead32))
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Move
; Purpose:    Move (rotates and displaces) the D3Object.
; Arguments:  Arg1: -> Rotation D3Vector structure.
;             Arg2: -> Displacement D3Vector structure.
;             If both are NULL, Vo is copied to Vt.
; Return:     Nothing.

Method D3Object.Move, uses xsi, pRotation:PD3Vector, pDisplacement:PD3Vector
  local xUseVo:XWORD

  SetObject xsi
  mov xUseVo, TRUE

  .if pRotation != NULL
    mov xdi, [xsi].pVectrons

    mov xdx, pRotation
    fld [xdx].D3Vector.r4X
    fsincos
    .ColForEach [xdi], ebx
      mov xcx, xax
      mov xdx, xUseVo
      Rotate r4X, r4Y, r4Z
    .ColNext
    mov xUseVo, FALSE
    fUnload 2

    mov xdx, pRotation
    fld [xdx].D3Vector.r4Y
    fsincos
    .ColForEach [xdi], ebx
      mov xcx, xax
      mov xdx, xUseVo
      Rotate r4Y, r4X, r4Z
    .ColNext
    mov xUseVo, FALSE
    fUnload 2

    mov xdx, pRotation
    fld [xdx].D3Vector.r4Z
    fsincos
    .ColForEach [xdi], ebx
      mov xcx, xax
      mov xdx, xUseVo
      Rotate r4Z, r4X, r4Y
    .ColNext
    mov xUseVo, FALSE
    fUnload 2
  .endif

  mov xdx, pDisplacement
  .if xdx != NULL
    fld [xdx].D3Vector.r4X
    fld [xdx].D3Vector.r4Y
    fld [xdx].D3Vector.r4Z
    OCall [xsi].pVectrons::D3VectronCollection.ForEach, offset Translate, xUseVo, NULL
    fUnload 3
  .elseif xUseVo == TRUE
    OCall [xsi].pVectrons::D3VectronCollection.ForEach, offset MoveVo2Vt, NULL, NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Project
; Purpose:    Project a D3Object to a D3Camera.
; Arguments:  Arg1: -> D3Camera object.
; Return:     Nothing.

InfoMakeProj struc
  pCamera     $ObjPtr(D3Camera)   ?
  ppBuffer    POINTER             ?         ;-> ObjProjcollection item POINTER
InfoMakeProj ends
PInfoMakeProj typedef ptr InfoMakeProj

MakeProjection proc uses xbx xdi xsi pVectron:PD3Vectron, pInfoMakeProj:PInfoMakeProj, xUnused:XWORD
  mov xdi, pVectron
  mov xdx, pInfoMakeProj
  mov xbx, [xdx].InfoMakeProj.pCamera
  mov xax, [xdx].InfoMakeProj.ppBuffer
  mov xsi, [xax]
  mov ecx, sizeof(D3Vector)
  add [xax], ecx

  invoke VectorDotVector, addr [xdi].D3Vectron.Vt, addr [xbx].$Obj(D3Camera).VectronX.Vt
  fadd [xbx].$Obj(D3Camera).Displacement.r4X
  fstp REAL4 ptr [xsi].D3Vector.r4X
  invoke VectorDotVector, addr [xdi].D3Vectron.Vt, addr [xbx].$Obj(D3Camera).VectronY.Vt
  fadd [xbx].$Obj(D3Camera).Displacement.r4Y
  fstp REAL4 ptr [xsi].D3Vector.r4Y
  invoke VectorDotVector, addr [xdi].D3Vectron.Vt, addr [xbx].$Obj(D3Camera).VectronZ.Vt
  fadd [xbx].$Obj(D3Camera).Displacement.r4Z
  fstp REAL4 ptr [xsi].D3Vector.r4Z
  ret
MakeProjection endp

InfoMakeTriData struc
  pCamera     $ObjPtr(D3Camera)   ?
  dObjIndex   DWORD               ?
InfoMakeTriData ends
PInfoMakeTriData typedef ptr InfoMakeTriData

MakeTriData proc uses xbx xsi pTriangle:$ObjPtr(D3Triangle), pInfo:PInfoMakeTriData, xUnused:XWORD
  local pVec1:PD3Vector, pVec2:PD3Vector, pVec3:PD3Vector

  mov xax, pInfo
  mov xbx, [xax].InfoMakeTriData.pCamera
  OCall [xbx].$Obj(D3Camera).pObjectProjs::DataCollection.ItemAt, [xax].InfoMakeTriData.dObjIndex
  mov xcx, pTriangle

  GetD3VectorFromTable xax, [xcx].$Obj(D3Triangle).dIndex1, xdx
  mov pVec1, xdx
  GetD3VectorFromTable xax, [xcx].$Obj(D3Triangle).dIndex2, xdx
  mov pVec2, xdx
  GetD3VectorFromTable xax, [xcx].$Obj(D3Triangle).dIndex3, xdx
  mov pVec3, xdx
  mov xcx, pVec2
  mov xax, pVec1

  ;Inner product
  ;FPU register usage            0    |    1    |    2
  fld [xcx].D3Vector.r4X    ;   V2x   |         |
  fsub [xax].D3Vector.r4X   ; V2x-V1x |         |
  fld [xdx].D3Vector.r4Y    ;   V3y   | V2x-V1x |
  fsub [xax].D3Vector.r4Y   ; V3y-V1y | V2x-V1x |
  fmulp st(1), st(0)        ;    A    |         |
  fld [xax].D3Vector.r4X    ;   V1x   |    A    |
  fsub [xdx].D3Vector.r4X   ; V1x-V3x |    A    |
  fld [xcx].D3Vector.r4Y    ;   V2y   | V1x-V3x |    A
  fsub [xax].D3Vector.r4Y   ; V2y-V1y | V1x-V3x |    A
  fmulp st(1), st(0)        ;   -B    |    A    |
  faddp st(1), st(0)        ;   A-B   |         |

  ftst
  fstsw ax
  sahf
  fUnload
  jae @F                    ;Equal zero for Lines and Points
  jmp @@Exit

@@:
  mov xsi, $MemAlloc(sizeof(TriData))
  mov xax, pInfo
  m2m [xsi].TriData.dObjectIndex, [xax].InfoMakeTriData.dObjIndex, eax
  m2m [xsi].TriData.pTriangle, pTriangle, xax

  mov xdx, pVec3
  mov xcx, pVec2
  mov xax, pVec1
  fld [xdx].D3Vector.r4Z
  fld [xcx].D3Vector.r4Z
  fld [xax].D3Vector.r4Z

  fcom st(1)                ;Add min and max values and store the result in TriData.r4Distance
  fstsw ax
  sahf
  jb @F
  fxch st(1)
@@:
  fcom st(2)
  fstsw ax
  sahf
  ja @F
  fxch st(2)
@@:
  fcom st(1)
  fstsw ax
  sahf
  ja @F
  fxch st(1)
@@:
  faddp st(2), st(0)
  fUnload
  fstp [xsi].TriData.r4Distance

  OCall [xbx].$Obj(D3Camera).pSortedTriData::SortedDataCollection.Insert, xsi   ;Sorted insert
@@Exit:
  ret
MakeTriData endp

Method D3Object.Project, uses xbx xdi xsi, pCamera:$ObjPtr(D3Camera), Unused:XWORD
  local pBuffer:POINTER, dObjIndex:DWORD
  local TriDataInfo:InfoMakeTriData, ProjInfo:InfoMakeProj

  SetObject xsi
  mov xdi, pCamera
  OCall [xsi].pOwner::Collection.IndexOf, xsi
  mov dObjIndex, eax
  mov xax, [xdi].$Obj(D3Camera).pObjectProjs
  mov edx, [xax].$Obj(Collection).dCount
  .if dObjIndex < edx
    OCall [xdi].$Obj(D3Camera).pObjectProjs::DataCollection.ItemAt, dObjIndex
  .else
    mov xcx, [xsi].pVectrons
    mov eax, [xcx].$Obj(Collection).dCount
    mov edx, sizeof(D3Vector)
    mul edx
    MemAlloc eax
    OCall [xdi].$Obj(D3Camera).pObjectProjs::DataCollection.Insert, xax
  .endif
  ;xax -> Buffer structure that will hold the projected vectors
  mov pBuffer, xax
  m2m ProjInfo.pCamera, pCamera, xax
  lea xax, pBuffer
  mov ProjInfo.ppBuffer, xax
  OCall [xsi].pVectrons::DataCollection.ForEach, offset MakeProjection, addr ProjInfo, NULL

  ; ---- Destroy all entries that have TriData.dObjectIndex = dObjIndex ----
  ReleaseObject
  mov xsi, [xdi].$Obj(D3Camera).pSortedTriData
  mov ebx, [xsi].$Obj(Collection).dCount
  mov xsi, [xsi].$Obj(Collection).pItems
  test ebx, ebx
  .while !ZERO?
    mov xdx, [xsi]          ;Get TriData structure
    mov eax, [xdx].TriData.dObjectIndex
    .if eax == dObjIndex
      OCall [xdi].$Obj(D3Camera).pSortedTriData::SortedCollection.Dispose, xdx
    .else
      add xsi, sizeof(POINTER)
    .endif
    dec ebx
  .endw

  ; -------------------------------------------------------------------------------
  SetObject xsi
  m2m TriDataInfo.pCamera, pCamera, xax
  m2m TriDataInfo.dObjIndex, dObjIndex, eax
  OCall [xsi].pTriangles::Collection.ForEach, offset MakeTriData, addr TriDataInfo, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Store
; Purpose:    Store a D3Object in a Stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method D3Object.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.Put, [xsi].pVectrons
  OCall pStream::Stream.Put, [xsi].pTriangles
  OCall pStream::Stream.BinWrite32, [xsi].dFlags
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Object.Scale
; Purpose:    Scale a D3Object.
; Arguments:  Arg1: Factor.
; Return:     Nothing.

Method D3Object.Scale, uses xbx xdi xsi, r4ScaleFactor:REAL4
  local DWVector:$Obj(SortedDWordVector), pTriangle:$ObjPtr(D3Triangle)

  SetObject xsi
  New DWVector::SortedDWordVector
  OCall DWVector::SortedDWordVector.Init, xsi, 100, 100, 0FFFFFFFFh/sizeof(DWORD)
  mov xdi, [xsi].pTriangles
  .ColForEach [xdi], ebx
    mov pTriangle, xax
    OCall DWVector::SortedDWordVector.Insert, [xax].$Obj(D3Triangle).dIndex1 
    mov xax, pTriangle
    OCall DWVector::SortedDWordVector.Insert, [xax].$Obj(D3Triangle).dIndex2 
    mov xax, pTriangle
    OCall DWVector::SortedDWordVector.Insert, [xax].$Obj(D3Triangle).dIndex3
  .ColNext 
  
  .VecForEach DWVector::SortedDWordVector, ebx
    OCall [xsi].pVectrons::D3VectronCollection.ItemAt, DWORD ptr [xax]
    mov xdi, xax
    fld r4ScaleFactor
    fld [xdi].D3Vectron.Vo.r4X
    fmul st(0), st(1)
    fstp [xdi].D3Vectron.Vo.r4X
    fld [xdi].D3Vectron.Vo.r4Y
    fmul st(0), st(1)
    fstp [xdi].D3Vectron.Vo.r4Y
    fld [xdi].D3Vectron.Vo.r4Z
    fmulp st(1), st(0)
    fstp [xdi].D3Vectron.Vo.r4Z
  .VecNext
  
  OCall DWVector::SortedDWordVector.Done
  
MethodEnd

