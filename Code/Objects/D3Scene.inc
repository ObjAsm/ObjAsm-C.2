; ==================================================================================================
; Title:      D3Scene.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm D3Scene implementation.
; ==================================================================================================


; ==================================================================================================
;    D3Scene implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Clear
; Purpose:    Clear the content of all cameras.
; Arguments:  None.
; Return:     Nothing.

Method D3Scene.Clear
  SetObject xcx
  OCall [xcx].pCameras::Collection.ForEach, $MethodAddr(D3Camera.Clear), NULL, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Colorize
; Purpose:    Compute the colors of all vertices.
; Arguments:  None.
; Return:     Nothing.

Method D3Scene.Colorize
  SetObject xax
  OCall [xax].pLights::Collection.ForEach, $MethodAddr(D3Light.Colorize), [xax].pObjects, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.CreateBox
; Purpose:    Crete a centered box D3Object.
; Arguments:  Arg1: -> Real4 number containing the box width.
;             Arg2: -> Real4 number containing the box height.
;             Arg3: -> Real4 number containing the box depth.
; Return:     xax -> New created D3Object.

Method D3Scene.CreateBox, uses xdi xsi, pWidth:POINTER, pHeight:POINTER, pDepth:POINTER, Color:COLORREF
  local Vector1:D3Vector, Vector2:D3Vector, Vector3:D3Vector, Vector4:D3Vector
  local Vector5:D3Vector, Vector6:D3Vector, Vector7:D3Vector, Vector8:D3Vector

  SetObject xsi
  fld1
  fld1
  faddp st(1), st(0)      ;2
  mov xax, pDepth
  fld REAL4 ptr [xax]
  fdiv st(0), st(1)
  fstReg edx
  fchs
  mov xax, pHeight
  fld REAL4 ptr [xax]
  fdiv st(0), st(2)
  fstReg ecx
  fchs
  mov xax, pWidth
  fld REAL4 ptr [xax]
  fdiv st(0), st(3)
  fstReg eax
  fchs

  mov Vector2.r4X, eax
  mov Vector3.r4X, eax
  mov Vector3.r4Y, ecx
  mov Vector4.r4Y, ecx
  mov Vector5.r4Z, edx
  mov Vector6.r4X, eax
  mov Vector6.r4Z, edx
  mov Vector7.r4X, eax
  mov Vector7.r4Y, ecx
  mov Vector7.r4Z, edx
  mov Vector8.r4Y, ecx
  mov Vector8.r4Z, edx

  fstpReg eax
  fstpReg ecx
  fstpReg edx
  fUnload                 ;2

  mov Vector1.r4X, eax
  mov Vector1.r4Y, ecx
  mov Vector1.r4Z, edx
  mov Vector2.r4Y, ecx
  mov Vector2.r4Z, edx
  mov Vector3.r4Z, edx
  mov Vector4.r4X, eax
  mov Vector4.r4Z, edx
  mov Vector5.r4X, eax
  mov Vector5.r4Y, ecx
  mov Vector6.r4Y, ecx
  mov Vector8.r4X, eax

  mov xdi, $OCall(xsi::D3Scene.NewObject)
  OCall xdi::D3Object.AddRectangle, addr Vector4, addr Vector3, addr Vector2, addr Vector1, Color
  OCall xdi::D3Object.AddRectangle, addr Vector5, addr Vector6, addr Vector7, addr Vector8, Color
  OCall xdi::D3Object.AddRectangle, addr Vector2, addr Vector3, addr Vector7, addr Vector6, Color
  OCall xdi::D3Object.AddRectangle, addr Vector1, addr Vector5, addr Vector8, addr Vector4, Color
  OCall xdi::D3Object.AddRectangle, addr Vector1, addr Vector2, addr Vector6, addr Vector5, Color
  OCall xdi::D3Object.AddRectangle, addr Vector3, addr Vector4, addr Vector8, addr Vector7, Color
  mov xax, xdi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.CreateGeoSphere
; Purpose:    Crete a centered sphere D3Object.
; Arguments:  Arg1: Number of meridians.
;             Arg2: Number of parallels.
;             Arg3: Real4 Sphere radius.
;             Arg4: Color
; Return:     xax -> New created D3Object.

Method D3Scene.CreateGeoSphere, uses xbx xdi xsi, dMeridians:DWORD, dParallels:DWORD, \
                                                  r4Radius:REAL4, Color:COLORREF
  local dCurrParallel:DWORD, r4CurrY:REAL4, pSphere:$ObjPtr(D3Object)
  local r4DeltaAlpha:REAL4, r4DeltaBeta:REAL4, r4PhaseShift:REAL4, r4Phase:REAL4
  local dBaseIndex:DWORD, pVectorMemory:POINTER
  local pVec1:PD3Vector, pVec2:PD3Vector

  xor edx, edx
  mov eax, dMeridians
  inc eax
  mul dParallels
  inc eax
  inc eax
  mov ecx, sizeof(D3Vector)
  mul ecx                           ;Sizeof(D3Vector) * [(Meridians + 1) * Parallels + 2]

  mov pVectorMemory, $MemAlloc(eax) ;Allocate memory for all GeoSphere vectors
  mov xsi, xax                      ;Save memory block POINTER in xsi

  ;FPU register usage               ;   0   |   1   |   2   |   3   |   4   |   5   |   6    |

  ;Set first D3Vector in the south pole
  fld r4Radius                      ;   R   |       |       |       |       |       |        |
  xor ecx, ecx
  mov r4Phase, ecx
  mov [xsi].D3Vector.r4X, ecx
  mov [xsi].D3Vector.r4Z, ecx
  fst [xsi].D3Vector.r4Y            ;   R   |       |       |       |       |       |        |
  add xsi, sizeof(D3Vector)
  m2m dCurrParallel, dParallels, ecx

  ;Compute D3Vectors of parallels
  fldpi                             ;   Pi  |   R   |       |       |       |       |        |
  fild dParallels                   ;  Para |   Pi  |   R   |       |       |       |        |
  fdivp st(1), st(0)                ; DAlpha|   R   |       |       |       |       |        |
  fst r4DeltaAlpha                  ; Alpha |   R   |       |       |       |       |        |

  fldpi                             ;   Pi  | Alpha |   R   |       |       |       |        |
  fldpi                             ;   Pi  |   Pi  | Alpha |   R   |       |       |        |
  faddp st(1), st(0)                ;  2*Pi | Alpha |   R   |       |       |       |        |
  fild dMeridians                   ;  Meri |  2*Pi | Alpha |   R   |       |       |        |
  fdivp st(1), st(0)                ; DBeta | Alpha |   R   |       |       |       |        |
  fst r4DeltaBeta                   ; Alpha |   R   |       |       |       |       |        |
  fld1
  fld1
  faddp st(1), st(0)
  fdivp st(1), st(0)
  fchs
  fstp r4PhaseShift                 ; Alpha |   R   |       |       |       |       |        |
  fldz                              ;  Beta | Alpha |   R   |       |       |       |        |

  .while dCurrParallel > 0          ;Reverse count: dParallels..1
    fld st(1)                       ; Alpha |  Beta | Alpha |   R   |       |       |        |
    fsincos                         ;  cos  |  sin  |  Beta | Alpha |   R   |       |        |
    fmul st(0), st(4)               ; R*cos |  sin  |  Beta | Alpha |   R   |       |        |
    fstp r4CurrY                    ;  sin  |  Beta | Alpha |   R   |       |       |        |
    fmul st(0), st(3)               ; R*sin |  Beta | Alpha |   R   |       |       |        |

    fld r4Phase
    fadd r4PhaseShift
    fst r4Phase
    fstp st(2)

    xor ebx, ebx
    .while ebx <= dMeridians        ;Forward count: 0..dMeridians
      fld st(1)                     ;  Beta | R*sin |  Beta | Alpha |   R   |       |        |
      fsincos                       ;  cos  |  sin  | R*sin |  Beta | Alpha |   R   |        |
      fmul st(0), st(2)             ;   Z   |  sin  | R*sin |  Beta | Alpha |   R   |        |
      fstp [xsi].D3Vector.r4Z       ;  sin  | R*sin |  Beta | Alpha |   R   |       |        |
      fmul st(0), st(1)             ;   X   | R*sin |  Beta | Alpha |   R   |       |        |
      fstp [xsi].D3Vector.r4X       ; R*sin |  Beta | Alpha |   R   |       |       |        |
      fld r4DeltaBeta               ; DBeta | R*sin |  Beta | Alpha |   R   |       |        |
      faddp st(2), st(0)            ; R*sin |  Beta | Alpha |   R   |       |       |        |
      m2m [xsi].D3Vector.r4Y, r4CurrY, ecx
      add xsi, sizeof(D3Vector)
      inc ebx
    .endw
    fUnload                         ;  Beta | Alpha |   R   |       |       |       |        |
    fld r4DeltaAlpha                ; DAlpha|  Beta | Alpha |   R   |       |       |        |
    faddp st(2), st(0)              ;  Beta | Alpha |   R   |       |       |       |        |
    dec dCurrParallel
  .endw
  fUnload 2                         ;   R   |       |       |       |       |       |        |

  ;Set last D3Vector in the north pole
  xor ecx, ecx
  mov [xsi].D3Vector.r4X, ecx
  mov [xsi].D3Vector.r4Z, ecx
  fchs
  fstp [xsi].D3Vector.r4Y

  mov pSphere, $OCall(pSelf.NewObject)

  ;Make south pole casquete
  xor ebx, ebx
  .while ebx < dMeridians
    mov edx, ebx
    inc edx
    GetD3VectorFromTable pVectorMemory, edx, xsi
    inc edx
    GetD3VectorFromTable pVectorMemory, edx, xax
    OCall pSphere::D3Object.AddTriangle, pVectorMemory, xsi, xax, Color
    inc ebx
  .endw

  ;Make middle part
  xor ebx, ebx
  inc ebx
  dec dParallels
  .while ebx < dParallels
    xor edx, edx
    mov eax, dMeridians
    inc eax
    mul ebx
    inc eax
    mov dBaseIndex, eax                   ;dBaseIndex = (Meridians + 1) * dCurrParallel + 1
    xor edi, edi
    .while edi < dMeridians
      mov ecx, dBaseIndex
      add ecx, edi
      GetD3VectorFromTable pVectorMemory, ecx, xdx
      inc ecx
      GetD3VectorFromTable pVectorMemory, ecx, xax
      mov pVec1, xax
      sub ecx, dMeridians
      dec ecx
      GetD3VectorFromTable pVectorMemory, ecx, xax
      mov pVec2, xax
      dec ecx
      GetD3VectorFromTable pVectorMemory, ecx
      OCall pSphere::D3Object.AddRectangle, xdx, pVec1, pVec2, xax, Color
      inc edi
    .endw
    inc ebx
  .endw

  ;Make north pole casquete
  mov ecx, dBaseIndex
  add ecx, dMeridians
  inc ecx
  GetD3VectorFromTable pVectorMemory, ecx, xsi
  xor ebx, ebx
  .while ebx < dMeridians
    mov ecx, dBaseIndex
    add ecx, ebx
    GetD3VectorFromTable pVectorMemory, ecx
    inc ecx
    GetD3VectorFromTable pVectorMemory, ecx, xdi
    OCall pSphere::D3Object.AddTriangle, xsi, xdi, xax, Color
    inc ebx
  .endw

  MemFree pVectorMemory
  mov xax, pSphere
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Deserialize
; Purpose:    Convert serialized members.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method D3Scene.Deserialize, uses xsi, pDeserInfo:PDESER_INFO
;  DbgText "D3Scene.Deserialize"
  SetObject xsi
  ACall xsi.Deserialize, pDeserInfo
  OCall [xsi].pObjects::Collection.Deserialize, pDeserInfo
  OCall [xsi].pCameras::Collection.Deserialize, pDeserInfo
  OCall [xsi].pLights::Collection.Deserialize, pDeserInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.DestroyCamera
; Purpose:    Destroy a D3Camera from the D3Scene object.
; Arguments:  Arg1: -> D3Camera object.
; Return:     Nothing.

Method D3Scene.DestroyCamera,, pCamera:$ObjPtr(D3Camera)
  SetObject xcx
  OCall [xcx].pCameras::Collection.Dispose, pCamera
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.DestroyLight
; Purpose:    Destroy a D3Light from the D3Scene object.
; Arguments:  Arg1: -> D3Light object.
; Return:     Nothing.

Method D3Scene.DestroyLight,, pLight:$ObjPtr(D3Light)
  SetObject xcx
  OCall [xcx].pLights::Collection.Dispose, pLight
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.DestroyObject
; Purpose:    Destroy a D3Object from the D3Scene object.
; Arguments:  Arg1: -> D3Light object.
; Return:     Nothing.

Method D3Scene.DestroyObject,, pObject:$ObjPtr(D3Object)
  SetObject xcx
  OCall [xcx].pObjects::Collection.Dispose, pObject
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Done
; Purpose:    Finalize the D3Scene object.
; Arguments:  None.
; Return:     Nothing.

Method D3Scene.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pLights
  Destroy [xsi].pCameras
  Destroy [xsi].pObjects
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.InfoTriCount
; Purpose:    Compute the number of D3Triangles in the D3Scene.
; Arguments:  None.
; Return:     eax = Number of D3Triangles.

Method D3Scene.InfoTriCount
  local dCount:DWORD

  xor eax, eax
  mov dCount, eax
  SetObject xcx
  mov xdx, $MethodAddr(D3Object.InfoAddTriCount)
  OCall [xcx].pObjects::Collection.ForEach, xdx, addr dCount, NULL
  mov eax, dCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Init
; Purpose:    Initialize the D3Scene object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method D3Scene.Init, uses xsi, pOwner:POINTER
  SetObject xsi, D3Scene
  ACall xsi.Init, pOwner
  mov [xsi].pCameras, $New(Collection)
  OCall [xsi].pCameras::Collection.Init, xsi, 1, 1, COL_MAX_CAPACITY
  mov [xsi].pLights, $New(Collection)
  OCall [xsi].pLights::Collection.Init, xsi, 1, 1, COL_MAX_CAPACITY
  mov [xsi].pObjects, $New(Collection)
  OCall [xsi].pObjects::Collection.Init, xsi, 1, 1, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Load
; Purpose:    Load a D3Scene from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method D3Scene.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo

  ;Read these objects from the stream
  mov [xsi].pCameras, $OCall(pStream::DiskStream.Get, pDeserInfo)
  mov [xsi].pLights,  $OCall(pStream::DiskStream.Get, pDeserInfo)
  mov [xsi].pObjects, $OCall(pStream::DiskStream.Get, pDeserInfo)

  OCall xsi.Project
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.NewCamera
; Purpose:    Add a new D3Camera to the D3Scene object.
; Arguments:  None.
; Return:     xax -> New D3Camera object.

Method D3Scene.NewCamera, uses xbx xsi
  SetObject xsi
  mov xbx, $New(D3Camera)
  OCall xax::D3Camera.Init, [xsi].pCameras
  OCall [xsi].pCameras::Collection.Insert, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.NewLight
; Purpose:    Add a new D3Light to the D3Scene object.
; Arguments:  None.
; Return:     xax -> New D3Light object.

Method D3Scene.NewLight, uses xbx xsi
  SetObject xsi
  mov xbx, $New(D3Light)
  OCall xax::D3Light.Init, [xsi].pLights
  OCall [xsi].pLights::Collection.Insert, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.NewObject
; Purpose:    Add a new D3Object to the D3Scene object.
; Arguments:  None.
; Return:     xax -> New D3Object object.

Method D3Scene.NewObject, uses xbx xsi
  SetObject xsi
  mov xbx, $New(D3Object)
  OCall xbx::D3Object.Init, [xsi].pObjects
  OCall [xsi].pObjects::Collection.Insert, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Project
; Purpose:    Project all D3Objects in the D3Scene to all D3Cameras.
; Arguments:  None.
; Return:     Nothing.

Method D3Scene.Project, uses xsi
  SetObject xsi
  OCall [xsi].pCameras::Collection.ForEach, $MethodAddr(D3Camera.Project), [xsi].pObjects, NULL
  OCall [xsi].pLights::Collection.ForEach, $MethodAddr(D3Light.Colorize), [xsi].pCameras, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Scene.Store
; Purpose:    Store a D3Scene to a Stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method D3Scene.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream

  ;Write these objects to the stream
  OCall pStream::Stream.Put, [xsi].pCameras
  OCall pStream::Stream.Put, [xsi].pLights
  OCall pStream::Stream.Put, [xsi].pObjects
MethodEnd
