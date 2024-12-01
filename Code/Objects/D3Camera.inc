; ==================================================================================================
; Title:      D3Camera.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm implementation of D3Camera. See D3Engine.inc.
; ==================================================================================================


; ==================================================================================================
;    D3Camera implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Clear
; Purpose:    Clear the content of the camera.
; Arguments:  None.
; Return:     Nothing.

Method D3Camera.Clear,, Unused1:XWORD, Unused2:XWORD
  SetObject xcx
  OCall [xcx].pSortedTriData::SortedDataCollection.DisposeAll
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Colorize
; Purpose:    Change the color of a D3Object when it is iluminated with a D3Light.
; Arguments:  Arg1: -> D3Light object.
; Return:     Nothing.

Method D3Camera.Colorize, uses xbx xsi, pLight:$ObjPtr(D3Light), Unused:XWORD
  SetObject xax
  mov xcx, [xax].$Obj(D3Camera).pSortedTriData
  mov ebx, [xcx].$Obj(Collection).dCount
  mov xsi, [xcx].$Obj(Collection).pItems
  test ebx, ebx
  .while !ZERO?
    mov xcx, [xsi]
    OCall [xcx].TriData.pTriangle::D3Triangle.Colorize, pLight, NULL
    add xsi, sizeof(POINTER)
    dec ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Deserialize
; Purpose:    Convert serialized members.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method D3Camera.Deserialize, uses xsi, pDeserInfo:PDESER_INFO
;  DbgText "D3Camera.Deserialize"
  SetObject xsi
  ACall xsi.Deserialize, pDeserInfo
  OCall [xsi].pSortedTriData::SortedDataCollection.Deserialize, pDeserInfo
  OCall [xsi].pObjectProjs::DataCollection.Deserialize, pDeserInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Done
; Purpose:    Finalize the camera object.
; Arguments:  None.
; Return:     Nothing.

Method D3Camera.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pSortedTriData
  Destroy [xsi].pObjectProjs
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Draw
; Purpose:    Draw the view of the D3Camera object to a DC.
; Arguments:  Arg1: DC handle.
;             Arg2: Speed flag.
; Return:     Nothing.

Method D3Camera.Draw, uses xbx xdi xsi, hDC:HDC, dSlow:DWORD
  local pObjectProjections:POINTER

  mov xsi, pSelf
  mov xcx, [xsi].$Obj(D3Camera).pSortedTriData
  mov ebx, [xcx].$Obj(Collection).dCount
  mov xdi, [xcx].$Obj(Collection).pItems
  m2m pObjectProjections, [xsi].$Obj(D3Camera).pObjectProjs, xax
  test ebx, ebx
  .while !ZERO?
    mov xsi, [xdi]
    OCall pObjectProjections::DataCollection.ItemAt, [xsi].TriData.dObjectIndex
    OCall [xsi].TriData.pTriangle::D3Triangle.Draw, hDC, xax
    .if dSlow == TRUE
      invoke Sleep, 2
    .endif
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SortedTriData.Compare
; Purpose:    Compare 2 items from the collection.
; Arguments:  Arg1: -> First item.
;             Arg2: -> Second item.
; Return:     eax = Compare result.

Method SortedTriData.Compare,, pItem1:PTriData, pItem2:PTriData
  local dResult:DWORD

  mov xdx, pItem2
  mov xcx, pItem1
  fld [xdx].TriData.r4Distance
  fsub [xcx].TriData.r4Distance
  fistp dResult
  mov eax, dResult
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Init
; Purpose:    Initialize D3Camera object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method D3Camera.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].pSortedTriData, $New(SortedDataCollection)
  OCall [xsi].pSortedTriData::SortedDataCollection.Init, xsi, 50, 50, COL_MAX_CAPACITY
  Override [xsi].pSortedTriData::SortedDataCollection.Compare, SortedTriData.Compare
  mov xax, [xsi].pSortedTriData
  mov [xax].$Obj(SortedCollection).dDuplicates, TRUE    ;Allow primitives at the same distance!

  mov [xsi].pObjectProjs, $New(DataCollection)
  OCall [xsi].pObjectProjs::DataCollection.Init, xsi, 50, 50, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Load
; Purpose:    Load a D3Camera from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method D3Camera.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  OCall xsi.Init, [xsi].pOwner
  OCall pStream::Stream.BinRead, addr [xsi].Displacement, sizeof(D3Vector)
  OCall pStream::Stream.BinRead, addr [xsi].Orientation,  sizeof(D3Vector)
  OCall pStream::Stream.BinRead, addr [xsi].VectronX,     sizeof(D3Vectron)
  OCall pStream::Stream.BinRead, addr [xsi].VectronY,     sizeof(D3Vectron)
  OCall pStream::Stream.BinRead, addr [xsi].VectronZ,     sizeof(D3Vectron)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Move
; Purpose:    Move the D3Camera.
; Arguments:  Arg1: -> Rotation D3Vector structure.
;             Arg2: -> Displacement D3Vector structure.
;             If both are NULL, Vo is copied to Vt.
; Return:     Nothing.

Method D3Camera.Move, uses xsi, pRotation:PD3Vector, pDisplacement:PD3Vector
  local xUseVo:XWORD

  SetObject xsi
  mov xUseVo, TRUE

  .if pRotation != NULL
    mov xdx, pRotation
    .if [xdx].D3Vector.r4X != 0
      fld [xdx].D3Vector.r4X
      fsincos
      invoke RotateX, addr [xsi].VectronX, xUseVo, 0
      invoke RotateX, addr [xsi].VectronY, xUseVo, 0
      invoke RotateX, addr [xsi].VectronZ, xUseVo, 0
      m2z xUseVo
      fUnload 2
    .endif

    mov xdx, pRotation
    .if [xdx].D3Vector.r4Y != 0
      fld [xdx].D3Vector.r4Y
      fsincos
      invoke RotateY, addr [xsi].VectronX, xUseVo, 0
      invoke RotateY, addr [xsi].VectronY, xUseVo, 0
      invoke RotateY, addr [xsi].VectronZ, xUseVo, 0
      m2z xUseVo
      fUnload 2
    .endif

    mov xdx, pRotation
    .if [xdx].D3Vector.r4Z != 0
      fld [xdx].D3Vector.r4Z
      fsincos
      invoke RotateZ, addr [xsi].VectronX, xUseVo, 0
      invoke RotateZ, addr [xsi].VectronY, xUseVo, 0
      invoke RotateZ, addr [xsi].VectronZ, xUseVo, 0
      m2z xUseVo
      fUnload 2
    .endif
  .endif

  mov xdx, pDisplacement
  .if xdx != NULL
    fld [xdx].D3Vector.r4X
    fld [xdx].D3Vector.r4Y
    fld [xdx].D3Vector.r4Z
    invoke Translate, addr [xsi].VectronX, xUseVo, 0
    invoke Translate, addr [xsi].VectronY, xUseVo, 0
    invoke Translate, addr [xsi].VectronZ, xUseVo, 0
    fUnload 3
  .elseif xUseVo == TRUE
    invoke MoveVo2Vt, addr [xsi].VectronX, 0, 0
    invoke MoveVo2Vt, addr [xsi].VectronY, 0, 0
    invoke MoveVo2Vt, addr [xsi].VectronZ, 0, 0
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Project
; Purpose:    Project all D3Objects to this D3Camera.
; Arguments:  Arg1: -> D3Scene D3Objects collection.
; Return:     Nothing.

Method D3Camera.Project,, pObjects:$ObjPtr(Collection), Unused:XWORD
  OCall pObjects::Collection.ForEach, $MethodAddr(D3Object.Project), pSelf, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     D3Camera.Store
; Purpose:    Store a D3Camera in a Stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method D3Camera.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite, addr [xsi].Displacement, sizeof(D3Vector)
  OCall pStream::Stream.BinWrite, addr [xsi].Orientation,  sizeof(D3Vector)
  OCall pStream::Stream.BinWrite, addr [xsi].VectronX,     sizeof(D3Vectron)
  OCall pStream::Stream.BinWrite, addr [xsi].VectronY,     sizeof(D3Vectron)
  OCall pStream::Stream.BinWrite, addr [xsi].VectronZ,     sizeof(D3Vectron)
MethodEnd
