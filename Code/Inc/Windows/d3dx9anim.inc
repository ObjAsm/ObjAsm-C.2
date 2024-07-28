;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9anim.h', last modified: 28/08/2017 14:00
;Creation parameters: 

ifndef __D3DX9ANIM_H__
  __D3DX9ANIM_H__ equ <>
  DEFINE_GUID IID_ID3DXAnimationSet, 698cfb3fh, 9289h, 4d95h, 9ah, 57h, 33h, 0a9h, 4bh, 5ah, 65h, 0f9h
  DEFINE_GUID IID_ID3DXKeyframedAnimationSet, 0fa4e8e3ah, 9786h, 407dh, 8bh, 4ch, 59h, 95h, 89h, 37h, 64h, 0afh
  DEFINE_GUID IID_ID3DXCompressedAnimationSet, 6cc2480dh, 3808h, 4739h, 9fh, 88h, 0deh, 49h, 0fah, 0cdh, 8dh, 4ch
  DEFINE_GUID IID_ID3DXAnimationController, 0ac8948ech, 0f86dh, 43e2h, 96h, 0deh, 31h, 0fch, 35h, 0f9h, 6dh, 9eh
  D3DXMESHDATATYPE typedef SDWORD
  D3DXMESHTYPE_MESH equ 001h
  D3DXMESHTYPE_PMESH equ 002h
  D3DXMESHTYPE_PATCHMESH equ 003h
  D3DXMESHTYPE_FORCE_DWORD equ 7fffffffh
  _D3DXMESHDATATYPE typedef D3DXMESHDATATYPE
  
  D3DXMESHDATA struct
    Type_ D3DXMESHDATATYPE ?
    union
      pMesh LPD3DXMESH ?
      pPMesh LPD3DXPMESH ?
      pPatchMesh LPD3DXPATCHMESH ?
    ends
  D3DXMESHDATA ends
  _D3DXMESHDATA typedef D3DXMESHDATA
  LPD3DXMESHDATA typedef ptr D3DXMESHDATA
  
  D3DXMESHCONTAINER struct
    Name_ LPSTR ?
    MeshData D3DXMESHDATA <>
    pMaterials LPD3DXMATERIAL ?
    pEffects LPD3DXEFFECTINSTANCE ?
    NumMaterials DWORD ?
    pAdjacency POINTER ?
    pSkinInfo LPD3DXSKININFO ?
    pNextMeshContainer POINTER ?
  D3DXMESHCONTAINER ends
  _D3DXMESHCONTAINER typedef D3DXMESHCONTAINER
  LPD3DXMESHCONTAINER typedef ptr D3DXMESHCONTAINER
  
  D3DXFRAME struct
    Name_ LPSTR ?
    TransformationMatrix D3DXMATRIX ?
    pMeshContainer LPD3DXMESHCONTAINER ?
    pFrameSibling POINTER ?
    pFrameFirstChild POINTER ?
  D3DXFRAME ends
  _D3DXFRAME typedef D3DXFRAME
  LPD3DXFRAME typedef ptr D3DXFRAME
  
  ;ID3DXAllocateHierarchy typedef ID3DXAllocateHierarchy
  
  LPD3DXALLOCATEHIERARCHY typedef ptr ID3DXAllocateHierarchy
  
  INTERFACE equ <ID3DXAllocateHierarchy>
  DECLARE_INTERFACE ID3DXAllocateHierarchy
    STD_METHOD CreateFrame, :THIS_, :ptr LPD3DXFRAME
    STD_METHOD CreateMeshContainer, :THIS_, :ptr D3DXMESHDATA, :ptr D3DXMATERIAL, :ptr D3DXEFFECTINSTANCE, :DWORD, :ptr DWORD, :LPD3DXSKININFO, :ptr LPD3DXMESHCONTAINER
    STD_METHOD DestroyFrame, :THIS_
    STD_METHOD DestroyMeshContainer, :THIS_
  END_DECLARE_INTERFACE
  ;ID3DXLoadUserData typedef ID3DXLoadUserData
  
  LPD3DXLOADUSERDATA typedef ptr ID3DXLoadUserData
  
  INTERFACE equ <ID3DXLoadUserData>
  DECLARE_INTERFACE ID3DXLoadUserData
    STD_METHOD LoadTopLevelData, :LPD3DXFILEDATA
    STD_METHOD LoadFrameChildData, :LPD3DXFRAME, :LPD3DXFILEDATA
    STD_METHOD LoadMeshChildData, :LPD3DXMESHCONTAINER, :LPD3DXFILEDATA
  END_DECLARE_INTERFACE
  ;ID3DXSaveUserData typedef ID3DXSaveUserData
  
  LPD3DXSAVEUSERDATA typedef ptr ID3DXSaveUserData
  
;  INTERFACE equ <ID3DXSaveUserData>
;  DECLARE_INTERFACE ID3DXSaveUserData
;    STD_METHOD AddFrameChildData, :ptr D3DXFRAME, :LPD3DXFILESAVEOBJECT, :LPD3DXFILESAVEDATA
;    STD_METHOD AddMeshChildData, :ptr D3DXMESHCONTAINER, :LPD3DXFILESAVEOBJECT, :LPD3DXFILESAVEDATA
;    STD_METHOD AddTopLevelDataObjectsPre, :LPD3DXFILESAVEOBJECT
;    STD_METHOD AddTopLevelDataObjectsPost, :LPD3DXFILESAVEOBJECT
;    STD_METHOD RegisterTemplates, :LPD3DXFILE
;    STD_METHOD SaveTemplates, :LPD3DXFILESAVEOBJECT
;  END_DECLARE_INTERFACE
;  D3DXCALLBACK_SEARCH_FLAGS typedef SDWORD
;  D3DXCALLBACK_SEARCH_EXCLUDING_INITIAL_POSITION equ 01h
;  D3DXCALLBACK_SEARCH_BEHIND_INITIAL_POSITION equ 02h
;  D3DXCALLBACK_SEARCH_FORCE_DWORD equ 7fffffffh
;  _D3DXCALLBACK_SEARCH_FLAGS typedef D3DXCALLBACK_SEARCH_FLAGS
;  
;  ;ID3DXAnimationSet typedef ID3DXAnimationSet
;  
;  LPD3DXANIMATIONSET typedef ptr ID3DXAnimationSet
;  
;  INTERFACE equ <ID3DXAnimationSet>
;  DECLARE_INTERFACE_ ID3DXAnimationSet, IUnknown
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetName, :THIS_
;    STD_METHOD GetPeriod, :THIS_
;    STD_METHOD GetPeriodicPosition, :THIS_
;    STD_METHOD GetNumAnimations, :THIS_
;    STD_METHOD GetAnimationNameByIndex, :THIS_, :ptr LPCSTR
;    STD_METHOD GetAnimationIndexByName, :THIS_, :ptr UINT
;    STD_METHOD GetSRT, :THIS_, :UINT, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3
;    STD_METHOD GetCallback, :THIS_, :DWORD, :ptr DOUBLE, :ptr LPVOID
;  END_DECLARE_INTERFACE_
;  D3DXPLAYBACK_TYPE typedef SDWORD
;  D3DXPLAY_LOOP equ 0
;  D3DXPLAY_ONCE equ 1
;  D3DXPLAY_PINGPONG equ 2
;  D3DXPLAY_FORCE_DWORD equ 7fffffffh
;  _D3DXPLAYBACK_TYPE typedef D3DXPLAYBACK_TYPE
;  
;  D3DXKEY_VECTOR3 struct
;    Time FLOAT ?
;    Value D3DXVECTOR3 ?
;  D3DXKEY_VECTOR3 ends
;  _D3DXKEY_VECTOR3 typedef D3DXKEY_VECTOR3
;  LPD3DXKEY_VECTOR3 typedef ptr D3DXKEY_VECTOR3
;  
;  D3DXKEY_QUATERNION struct
;    Time FLOAT ?
;    Value D3DXQUATERNION <>
;  D3DXKEY_QUATERNION ends
;  _D3DXKEY_QUATERNION typedef D3DXKEY_QUATERNION
;  LPD3DXKEY_QUATERNION typedef ptr D3DXKEY_QUATERNION
;  
;  D3DXKEY_CALLBACK struct
;    Time FLOAT ?
;    pCallbackData LPVOID ?
;  D3DXKEY_CALLBACK ends
;  _D3DXKEY_CALLBACK typedef D3DXKEY_CALLBACK
;  LPD3DXKEY_CALLBACK typedef ptr D3DXKEY_CALLBACK
;  
;  D3DXCOMPRESSION_FLAGS typedef SDWORD
;  D3DXCOMPRESS_DEFAULT equ 00h
;  D3DXCOMPRESS_FORCE_DWORD equ 7fffffffh
;  _D3DXCOMPRESSION_FLAGS typedef D3DXCOMPRESSION_FLAGS
;  
;  ;ID3DXKeyframedAnimationSet typedef ID3DXKeyframedAnimationSet
;  
;  LPD3DXKEYFRAMEDANIMATIONSET typedef ptr ID3DXKeyframedAnimationSet
;  
;  INTERFACE equ <ID3DXKeyframedAnimationSet>
;  DECLARE_INTERFACE_ ID3DXKeyframedAnimationSet, ID3DXAnimationSet
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetName, :THIS_
;    STD_METHOD GetPeriod, :THIS_
;    STD_METHOD GetPeriodicPosition, :THIS_
;    STD_METHOD GetNumAnimations, :THIS_
;    STD_METHOD GetAnimationNameByIndex, :THIS_, :ptr LPCSTR
;    STD_METHOD GetAnimationIndexByName, :THIS_, :ptr UINT
;    STD_METHOD GetSRT, :THIS_, :UINT, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3
;    STD_METHOD GetCallback, :THIS_, :DWORD, :ptr DOUBLE, :ptr LPVOID
;    STD_METHOD GetPlaybackType, :THIS_
;    STD_METHOD GetSourceTicksPerSecond, :THIS_
;    STD_METHOD GetNumScaleKeys, :THIS_
;    STD_METHOD GetScaleKeys, :THIS_, :LPD3DXKEY_VECTOR3
;    STD_METHOD GetScaleKey, :THIS_, :UINT, :LPD3DXKEY_VECTOR3
;    STD_METHOD SetScaleKey, :THIS_, :UINT, :LPD3DXKEY_VECTOR3
;    STD_METHOD GetNumRotationKeys, :THIS_
;    STD_METHOD GetRotationKeys, :THIS_, :LPD3DXKEY_QUATERNION
;    STD_METHOD GetRotationKey, :THIS_, :UINT, :LPD3DXKEY_QUATERNION
;    STD_METHOD SetRotationKey, :THIS_, :UINT, :LPD3DXKEY_QUATERNION
;    STD_METHOD GetNumTranslationKeys, :THIS_
;    STD_METHOD GetTranslationKeys, :THIS_, :LPD3DXKEY_VECTOR3
;    STD_METHOD GetTranslationKey, :THIS_, :UINT, :LPD3DXKEY_VECTOR3
;    STD_METHOD SetTranslationKey, :THIS_, :UINT, :LPD3DXKEY_VECTOR3
;    STD_METHOD GetNumCallbackKeys, :THIS_
;    STD_METHOD GetCallbackKeys, :THIS_
;    STD_METHOD GetCallbackKey, :THIS_, :LPD3DXKEY_CALLBACK
;    STD_METHOD SetCallbackKey, :THIS_, :LPD3DXKEY_CALLBACK
;    STD_METHOD UnregisterScaleKey, :THIS_, :UINT
;    STD_METHOD UnregisterRotationKey, :THIS_, :UINT
;    STD_METHOD UnregisterTranslationKey, :THIS_, :UINT
;    STD_METHOD RegisterAnimationSRTKeys, :THIS_, :UINT, :UINT, :UINT, :ptr D3DXKEY_VECTOR3, :ptr D3DXKEY_QUATERNION, :ptr D3DXKEY_VECTOR3, :ptr DWORD
;    STD_METHOD Compress, :THIS_, :FLOAT, :LPD3DXFRAME, :ptr LPD3DXBUFFER
;    STD_METHOD UnregisterAnimation, :THIS_
;  END_DECLARE_INTERFACE_
;  ;ID3DXCompressedAnimationSet typedef ID3DXCompressedAnimationSet
;  
;  LPD3DXCOMPRESSEDANIMATIONSET typedef ptr ID3DXCompressedAnimationSet
;  
;  INTERFACE equ <ID3DXCompressedAnimationSet>
;  DECLARE_INTERFACE_ ID3DXCompressedAnimationSet, ID3DXAnimationSet
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetName, :THIS_
;    STD_METHOD GetPeriod, :THIS_
;    STD_METHOD GetPeriodicPosition, :THIS_
;    STD_METHOD GetNumAnimations, :THIS_
;    STD_METHOD GetAnimationNameByIndex, :THIS_, :ptr LPCSTR
;    STD_METHOD GetAnimationIndexByName, :THIS_, :ptr UINT
;    STD_METHOD GetSRT, :THIS_, :UINT, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3
;    STD_METHOD GetCallback, :THIS_, :DWORD, :ptr DOUBLE, :ptr LPVOID
;    STD_METHOD GetPlaybackType, :THIS_
;    STD_METHOD GetSourceTicksPerSecond, :THIS_
;    STD_METHOD GetCompressedData, :ptr THIS_
;    STD_METHOD GetNumCallbackKeys, :THIS_
;    STD_METHOD GetCallbackKeys, :THIS_
;  END_DECLARE_INTERFACE_
;  D3DXPRIORITY_TYPE typedef SDWORD
;  D3DXPRIORITY_LOW equ 0
;  D3DXPRIORITY_HIGH equ 1
;  D3DXPRIORITY_FORCE_DWORD equ 7fffffffh
;  _D3DXPRIORITY_TYPE typedef D3DXPRIORITY_TYPE
;  
;  D3DXTRACK_DESC struct
;    Priority D3DXPRIORITY_TYPE ?
;    Weight FLOAT ?
;    Speed FLOAT ?
;    Position DOUBLE ?
;    Enable BOOL ?
;  D3DXTRACK_DESC ends
;  _D3DXTRACK_DESC typedef D3DXTRACK_DESC
;  LPD3DXTRACK_DESC typedef ptr D3DXTRACK_DESC
;  
;  D3DXEVENT_TYPE typedef SDWORD
;  D3DXEVENT_TRACKSPEED equ 0
;  D3DXEVENT_TRACKWEIGHT equ 1
;  D3DXEVENT_TRACKPOSITION equ 2
;  D3DXEVENT_TRACKENABLE equ 3
;  D3DXEVENT_PRIORITYBLEND equ 4
;  D3DXEVENT_FORCE_DWORD equ 7fffffffh
;  _D3DXEVENT_TYPE typedef D3DXEVENT_TYPE
;  
;  D3DXTRANSITION_TYPE typedef SDWORD
;  D3DXTRANSITION_LINEAR equ 000h
;  D3DXTRANSITION_EASEINEASEOUT equ 001h
;  D3DXTRANSITION_FORCE_DWORD equ 7fffffffh
;  _D3DXTRANSITION_TYPE typedef D3DXTRANSITION_TYPE
;  
;  D3DXEVENT_DESC struct
;    Type_ D3DXEVENT_TYPE ?
;    Track UINT ?
;    StartTime DOUBLE ?
;    Duration DOUBLE ?
;    Transition D3DXTRANSITION_TYPE ?
;    union
;      Weight FLOAT ?
;      Speed FLOAT ?
;      Position DOUBLE ?
;      Enable BOOL ?
;    ends
;  D3DXEVENT_DESC ends
;  _D3DXEVENT_DESC typedef D3DXEVENT_DESC
;  LPD3DXEVENT_DESC typedef ptr D3DXEVENT_DESC
;  
;  D3DXEVENTHANDLE typedef DWORD
;  LPD3DXEVENTHANDLE typedef ptr D3DXEVENTHANDLE
;  ;ID3DXAnimationCallbackHandler typedef ID3DXAnimationCallbackHandler
;  
;  LPD3DXANIMATIONCALLBACKHANDLER typedef ptr ID3DXAnimationCallbackHandler
;  
;  INTERFACE equ <ID3DXAnimationCallbackHandler>
;  DECLARE_INTERFACE ID3DXAnimationCallbackHandler
;    STD_METHOD HandleCallback, :THIS_, :LPVOID
;  END_DECLARE_INTERFACE
;  ;ID3DXAnimationController typedef ID3DXAnimationController
;  
;  LPD3DXANIMATIONCONTROLLER typedef ptr ID3DXAnimationController
;  
;  INTERFACE equ <ID3DXAnimationController>
;  DECLARE_INTERFACE_ ID3DXAnimationController, IUnknown
;    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;    STD_METHOD AddRef, :THIS_
;    STD_METHOD Release, :THIS_
;    STD_METHOD GetMaxNumAnimationOutputs, :THIS_
;    STD_METHOD GetMaxNumAnimationSets, :THIS_
;    STD_METHOD GetMaxNumTracks, :THIS_
;    STD_METHOD GetMaxNumEvents, :THIS_
;    STD_METHOD RegisterAnimationOutput, :THIS_, :ptr D3DXMATRIX, :ptr D3DXVECTOR3, :ptr D3DXQUATERNION, :ptr D3DXVECTOR3
;    STD_METHOD RegisterAnimationSet, :THIS_
;    STD_METHOD UnregisterAnimationSet, :THIS_
;    STD_METHOD GetNumAnimationSets, :THIS_
;    STD_METHOD GetAnimationSet, :THIS_, :ptr LPD3DXANIMATIONSET
;    STD_METHOD GetAnimationSetByName, :THIS_, :ptr LPD3DXANIMATIONSET
;    STD_METHOD AdvanceTime, :THIS_, :LPD3DXANIMATIONCALLBACKHANDLER
;    STD_METHOD ResetTime, :THIS_
;    STD_METHOD GetTime, :THIS_
;    STD_METHOD SetTrackAnimationSet, :THIS_, :LPD3DXANIMATIONSET
;    STD_METHOD GetTrackAnimationSet, :THIS_, :ptr LPD3DXANIMATIONSET
;    STD_METHOD SetTrackPriority, :THIS_, :D3DXPRIORITY_TYPE
;    STD_METHOD SetTrackSpeed, :THIS_, :FLOAT
;    STD_METHOD SetTrackWeight, :THIS_, :FLOAT
;    STD_METHOD SetTrackPosition, :THIS_, :DOUBLE
;    STD_METHOD SetTrackEnable, :THIS_, :BOOL
;    STD_METHOD SetTrackDesc, :THIS_, :LPD3DXTRACK_DESC
;    STD_METHOD GetTrackDesc, :THIS_, :LPD3DXTRACK_DESC
;    STD_METHOD SetPriorityBlend, :THIS_
;    STD_METHOD GetPriorityBlend, :THIS_
;    STD_METHOD KeyTrackSpeed, :THIS_, :FLOAT, :DOUBLE, :DOUBLE, :D3DXTRANSITION_TYPE
;    STD_METHOD KeyTrackWeight, :THIS_, :FLOAT, :DOUBLE, :DOUBLE, :D3DXTRANSITION_TYPE
;    STD_METHOD KeyTrackPosition, :THIS_, :DOUBLE, :DOUBLE
;    STD_METHOD KeyTrackEnable, :THIS_, :BOOL, :DOUBLE
;    STD_METHOD KeyPriorityBlend, :THIS_, :DOUBLE, :DOUBLE, :D3DXTRANSITION_TYPE
;    STD_METHOD UnkeyEvent, :THIS_
;    STD_METHOD UnkeyAllTrackEvents, :THIS_
;    STD_METHOD UnkeyAllPriorityBlends, :THIS_
;    STD_METHOD GetCurrentTrackEvent, :THIS_, :D3DXEVENT_TYPE
;    STD_METHOD GetCurrentPriorityBlend, :THIS_
;    STD_METHOD GetUpcomingTrackEvent, :THIS_, :D3DXEVENTHANDLE
;    STD_METHOD GetUpcomingPriorityBlend, :THIS_
;    STD_METHOD ValidateEvent, :THIS_
;    STD_METHOD GetEventDesc, :THIS_, :LPD3DXEVENT_DESC
;    STD_METHOD CloneAnimationController, :THIS_, :UINT, :UINT, :UINT, :ptr LPD3DXANIMATIONCONTROLLER
;  END_DECLARE_INTERFACE_
;  ifdef __cplusplus
;    ;[...]
;  endif
;  D3DXLoadMeshHierarchyFromXA proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :LPDIRECT3DDEVICE9, :LPD3DXALLOCATEHIERARCHY, :LPD3DXLOADUSERDATA, :ptr LPD3DXFRAME, :ptr LPD3DXANIMATIONCONTROLLER
;  D3DXLoadMeshHierarchyFromXW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :LPDIRECT3DDEVICE9, :LPD3DXALLOCATEHIERARCHY, :LPD3DXLOADUSERDATA, :ptr LPD3DXFRAME, :ptr LPD3DXANIMATIONCONTROLLER
;  ifdef UNICODE
;    D3DXLoadMeshHierarchyFromX equ <D3DXLoadMeshHierarchyFromXW>
;  else
;    D3DXLoadMeshHierarchyFromX equ <D3DXLoadMeshHierarchyFromXA>
;  endif
;  D3DXLoadMeshHierarchyFromXInMemory proto WIN_STD_CALL_CONV :LPCVOID, :DWORD, :DWORD, :LPDIRECT3DDEVICE9, :LPD3DXALLOCATEHIERARCHY, :LPD3DXLOADUSERDATA, :ptr LPD3DXFRAME, :ptr LPD3DXANIMATIONCONTROLLER
;  D3DXSaveMeshHierarchyToFileA proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :ptr D3DXFRAME, :LPD3DXANIMATIONCONTROLLER, :LPD3DXSAVEUSERDATA
;  D3DXSaveMeshHierarchyToFileW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :ptr D3DXFRAME, :LPD3DXANIMATIONCONTROLLER, :LPD3DXSAVEUSERDATA
;  ifdef UNICODE
;    D3DXSaveMeshHierarchyToFile equ <D3DXSaveMeshHierarchyToFileW>
;  else
;    D3DXSaveMeshHierarchyToFile equ <D3DXSaveMeshHierarchyToFileA>
;  endif
;  D3DXFrameDestroy proto WIN_STD_CALL_CONV :LPD3DXFRAME, :LPD3DXALLOCATEHIERARCHY
;  D3DXFrameAppendChild proto WIN_STD_CALL_CONV :LPD3DXFRAME, :ptr D3DXFRAME
;  D3DXFrameFind proto WIN_STD_CALL_CONV :ptr D3DXFRAME, :LPCSTR
;  D3DXFrameRegisterNamedMatrices proto WIN_STD_CALL_CONV :LPD3DXFRAME, :LPD3DXANIMATIONCONTROLLER
;  D3DXFrameNumNamedMatrices proto WIN_STD_CALL_CONV :ptr D3DXFRAME
;  D3DXFrameCalculateBoundingSphere proto WIN_STD_CALL_CONV :ptr D3DXFRAME, :LPD3DXVECTOR3, :ptr FLOAT
;  D3DXCreateKeyframedAnimationSet proto WIN_STD_CALL_CONV :LPCSTR, :DOUBLE, :D3DXPLAYBACK_TYPE, :UINT, :UINT, :ptr D3DXKEY_CALLBACK, :ptr LPD3DXKEYFRAMEDANIMATIONSET
;  D3DXCreateCompressedAnimationSet proto WIN_STD_CALL_CONV :LPCSTR, :DOUBLE, :D3DXPLAYBACK_TYPE, :LPD3DXBUFFER, :UINT, :ptr D3DXKEY_CALLBACK, :ptr LPD3DXCOMPRESSEDANIMATIONSET
;  D3DXCreateAnimationController proto WIN_STD_CALL_CONV :UINT, :UINT, :UINT, :UINT, :ptr LPD3DXANIMATIONCONTROLLER
;  ifdef __cplusplus
;    ;[...]
;  endif
endif

