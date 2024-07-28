;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9xof.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include d3dx9.inc
if  not Defined(__D3DX9XOF_H__)
  __D3DX9XOF_H__ equ <>
  if Defined(__cplusplus)
    ;[...]
  endif
  D3DXF_FILEFORMAT typedef DWORD
  D3DXF_FILEFORMAT_BINARY equ 0
  D3DXF_FILEFORMAT_TEXT equ 1
  D3DXF_FILEFORMAT_COMPRESSED equ 2
  D3DXF_FILESAVEOPTIONS typedef DWORD
  D3DXF_FILESAVE_TOFILE equ 00h
  D3DXF_FILESAVE_TOWFILE equ 01h
  D3DXF_FILELOADOPTIONS typedef DWORD
  D3DXF_FILELOAD_FROMFILE equ 00h
  D3DXF_FILELOAD_FROMWFILE equ 01h
  D3DXF_FILELOAD_FROMRESOURCE equ 02h
  D3DXF_FILELOAD_FROMMEMORY equ 03h
  D3DXF_FILELOADRESOURCE struct
    hModule HMODULE ?
    lpName LPCSTR ?
    lpType LPCSTR ?
  D3DXF_FILELOADRESOURCE ends
  _D3DXF_FILELOADRESOURCE typedef D3DXF_FILELOADRESOURCE
  D3DXF_FILELOADMEMORY struct
    lpMemory LPCVOID ?
    dSize SIZE_T ?
  D3DXF_FILELOADMEMORY ends
  _D3DXF_FILELOADMEMORY typedef D3DXF_FILELOADMEMORY
  if Defined(_WIN32) and  not Defined(_NO_COM)
    DEFINE_GUID IID_ID3DXFile, 0cef08cf9h, 7b4fh, 4429h, 96h, 24h, 2ah, 69h, 0ah, 93h, 32h, 01h
    DEFINE_GUID IID_ID3DXFileSaveObject, 0cef08cfah, 7b4fh, 4429h, 96h, 24h, 2ah, 69h, 0ah, 93h, 32h, 01h
    DEFINE_GUID IID_ID3DXFileSaveData, 0cef08cfbh, 7b4fh, 4429h, 96h, 24h, 2ah, 69h, 0ah, 93h, 32h, 01h
    DEFINE_GUID IID_ID3DXFileEnumObject, 0cef08cfch, 7b4fh, 4429h, 96h, 24h, 2ah, 69h, 0ah, 93h, 32h, 01h
    DEFINE_GUID IID_ID3DXFileData, 0cef08cfdh, 7b4fh, 4429h, 96h, 24h, 2ah, 69h, 0ah, 93h, 32h, 01h
  endif
  if Defined(__cplusplus)
    ;[...]
  endif
  ;ID3DXFile typedef ID3DXFile
  
  ;ID3DXFileSaveObject typedef ID3DXFileSaveObject
  
  ;ID3DXFileSaveData typedef ID3DXFileSaveData
  
  ;ID3DXFileEnumObject typedef ID3DXFileEnumObject
  
  ;ID3DXFileData typedef ID3DXFileData
  
  INTERFACE equ <ID3DXFile>
  DECLARE_INTERFACE_ ID3DXFile, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD CreateEnumObject, :THIS_, :D3DXF_FILELOADOPTIONS, :ptr ptr ID3DXFileEnumObject
    STD_METHOD CreateSaveObject, :THIS_, :D3DXF_FILESAVEOPTIONS, :D3DXF_FILEFORMAT, :ptr ptr ID3DXFileSaveObject
    STD_METHOD RegisterTemplates, :THIS_, :SIZE_T
    STD_METHOD RegisterEnumTemplates, :ptr THIS_
  END_DECLARE_INTERFACE_
  INTERFACE equ <ID3DXFileSaveObject>
  DECLARE_INTERFACE_ ID3DXFileSaveObject, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetFile, :ptr ptr THIS_
    STD_METHOD AddDataObject, :THIS_, :LPCSTR, :ptr GUID, :SIZE_T, :LPCVOID, :ptr ptr ID3DXFileSaveData
    STD_METHOD Save, :THIS_
  END_DECLARE_INTERFACE_
  INTERFACE equ <ID3DXFileSaveData>
  DECLARE_INTERFACE_ ID3DXFileSaveData, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetSave, :ptr ptr THIS_
    STD_METHOD GetName, :THIS_, :ptr SIZE_T
    STD_METHOD GetId, :THIS_
    STD_METHOD GetType, :ptr THIS_
    STD_METHOD AddDataObject, :THIS_, :LPCSTR, :ptr GUID, :SIZE_T, :LPCVOID, :ptr ptr ID3DXFileSaveData
    STD_METHOD AddDataReference, :THIS_, :ptr GUID
  END_DECLARE_INTERFACE_
  INTERFACE equ <ID3DXFileEnumObject>
  DECLARE_INTERFACE_ ID3DXFileEnumObject, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetFile, :ptr ptr THIS_
    STD_METHOD GetChildren, :ptr THIS_
    STD_METHOD GetChild, :THIS_, :ptr ptr ID3DXFileData
    STD_METHOD GetDataObjectById, :THIS_, :ptr ptr ID3DXFileData
    STD_METHOD GetDataObjectByName, :THIS_, :ptr ptr ID3DXFileData
  END_DECLARE_INTERFACE_
  INTERFACE equ <ID3DXFileData>
  DECLARE_INTERFACE_ ID3DXFileData, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetEnum, :ptr ptr THIS_
    STD_METHOD GetName, :THIS_, :ptr SIZE_T
    STD_METHOD GetId, :THIS_
    STD_METHOD Lock_, :ptr THIS_, :ptr LPCVOID
    STD_METHOD Unlock, :THIS_
    STD_METHOD GetType, :ptr THIS_
    STD_METHOD IsReference, :THIS_
    STD_METHOD GetChildren, :ptr THIS_
    STD_METHOD GetChild, :THIS_, :ptr ptr ID3DXFileData
  END_DECLARE_INTERFACE_
  @DefProto DllImport, D3DXFileCreate, WIN_STD_CALL_CONV,, <:ptr ptr ID3DXFile>, 4
  _FACD3DXF equ 876h
  D3DXFERR_BADOBJECT equ MAKE_HRESULT(1, _FACD3DXF, 900)
  D3DXFERR_BADVALUE equ MAKE_HRESULT(1, _FACD3DXF, 901)
  D3DXFERR_BADTYPE equ MAKE_HRESULT(1, _FACD3DXF, 902)
  D3DXFERR_NOTFOUND equ MAKE_HRESULT(1, _FACD3DXF, 903)
  D3DXFERR_NOTDONEYET equ MAKE_HRESULT(1, _FACD3DXF, 904)
  D3DXFERR_FILENOTFOUND equ MAKE_HRESULT(1, _FACD3DXF, 905)
  D3DXFERR_RESOURCENOTFOUND equ MAKE_HRESULT(1, _FACD3DXF, 906)
  D3DXFERR_BADRESOURCE equ MAKE_HRESULT(1, _FACD3DXF, 907)
  D3DXFERR_BADFILETYPE equ MAKE_HRESULT(1, _FACD3DXF, 908)
  D3DXFERR_BADFILEVERSION equ MAKE_HRESULT(1, _FACD3DXF, 909)
  D3DXFERR_BADFILEFLOATSIZE equ MAKE_HRESULT(1, _FACD3DXF, 910)
  D3DXFERR_BADFILE equ MAKE_HRESULT(1, _FACD3DXF, 911)
  D3DXFERR_PARSEERROR equ MAKE_HRESULT(1, _FACD3DXF, 912)
  D3DXFERR_BADARRAYSIZE equ MAKE_HRESULT(1, _FACD3DXF, 913)
  D3DXFERR_BADDATAREFERENCE equ MAKE_HRESULT(1, _FACD3DXF, 914)
  D3DXFERR_NOMOREOBJECTS equ MAKE_HRESULT(1, _FACD3DXF, 915)
  D3DXFERR_NOMOREDATA equ MAKE_HRESULT(1, _FACD3DXF, 916)
  D3DXFERR_BADCACHEFILE equ MAKE_HRESULT(1, _FACD3DXF, 917)
  ifndef WIN_TYPES
    WIN_TYPES macro itype, ptype
      exitm <typedef interface itype * LP ## ptype, * * LPLP ## ptype>
    endm
  endif
  LPD3DXFILEDATA typedef ptr ID3DXFILEDATA
;  WIN_TYPES(ID3DXFile, D3DXFILE)
;  WIN_TYPES(ID3DXFileEnumObject, D3DXFILEENUMOBJECT)
;  WIN_TYPES(ID3DXFileSaveObject, D3DXFILESAVEOBJECT)
;  WIN_TYPES(ID3DXFileData, D3DXFILEDATA)
;  WIN_TYPES(ID3DXFileSaveData, D3DXFILESAVEDATA)
  if Defined(__cplusplus)
    ;[...]
  endif
endif

