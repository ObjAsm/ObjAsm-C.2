;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\coml2api.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:13:22

if  not Defined(_COML2API_H_)
  _COML2API_H_ equ <>
  ifdef _MSC_VER
  endif
  include apiset.inc
  include apisetcconv.inc
  include combaseapi.inc
  include objidl.inc
  include propidlbase.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    CWCSTORAGENAME equ 32
    STGM_DIRECT equ 00000000h
    STGM_TRANSACTED equ 00010000h
    STGM_SIMPLE equ 08000000h
    STGM_READ equ 00000000h
    STGM_WRITE equ 00000001h
    STGM_READWRITE equ 00000002h
    STGM_SHARE_DENY_NONE equ 00000040h
    STGM_SHARE_DENY_READ equ 00000030h
    STGM_SHARE_DENY_WRITE equ 00000020h
    STGM_SHARE_EXCLUSIVE equ 00000010h
    STGM_PRIORITY equ 00040000h
    STGM_DELETEONRELEASE equ 04000000h
    if (WINVER ge 400)
      STGM_NOSCRATCH equ 00100000h
    endif
    STGM_CREATE equ 00001000h
    STGM_CONVERT equ 00020000h
    STGM_FAILIFTHERE equ 00000000h
    STGM_NOSNAPSHOT equ 00200000h
    if (_WIN32_WINNT ge 0500h)
      STGM_DIRECT_SWMR equ 00400000h
    endif
    STGFMT typedef DWORD
    STGFMT_STORAGE equ 0
    STGFMT_NATIVE equ 1
    STGFMT_FILE equ 3
    STGFMT_ANY equ 4
    STGFMT_DOCFILE equ 5
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    STGFMT_DOCUMENT equ 0
    @DefProto DllImport, StgCreateDocfile, WIN_STD_CALL_CONV,, <:ptr WCHAR, :DWORD, :DWORD, :ptr ptr IStorage>, 16
    @DefProto DllImport, StgCreateDocfileOnILockBytes, WIN_STD_CALL_CONV,, <:ptr ILockBytes, :DWORD, :DWORD, :ptr ptr IStorage>, 16
    @DefProto DllImport, StgOpenStorage, WIN_STD_CALL_CONV,, <:ptr WCHAR, :ptr IStorage, :DWORD, :SNB, :DWORD, :ptr ptr IStorage>, 24
    @DefProto DllImport, StgOpenStorageOnILockBytes, WIN_STD_CALL_CONV,, <:ptr ILockBytes, :ptr IStorage, :DWORD, :SNB, :DWORD, :ptr ptr IStorage>, 24
    @DefProto DllImport, StgIsStorageFile, WIN_STD_CALL_CONV,, <:ptr WCHAR>, 4
    @DefProto DllImport, StgIsStorageILockBytes, WIN_STD_CALL_CONV,, <:ptr ILockBytes>, 4
    @DefProto DllImport, StgSetTimes, WIN_STD_CALL_CONV,, <:ptr WCHAR, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME>, 16
    if _WIN32_WINNT eq 500h
      STGOPTIONS_VERSION equ 1
    elseif _WIN32_WINNT gt 500h
      STGOPTIONS_VERSION equ 2
    else
      STGOPTIONS_VERSION equ 0
    endif
    STGOPTIONS struct
      usVersion USHORT ?
      reserved USHORT ?
      ulSectorSize ULONG ?
      if STGOPTIONS_VERSION ge 2
        pwcsTemplateFile POINTER ?
      endif
    STGOPTIONS ends
    tagSTGOPTIONS typedef STGOPTIONS
    @DefProto DllImport, StgCreateStorageEx, WIN_STD_CALL_CONV,, <:ptr WCHAR, :DWORD, :DWORD, :DWORD, :ptr STGOPTIONS, :PSECURITY_DESCRIPTOR, :REFIID, :ptr ptr>, 32
    @DefProto DllImport, StgOpenStorageEx, WIN_STD_CALL_CONV,, <:ptr WCHAR, :DWORD, :DWORD, :DWORD, :ptr STGOPTIONS, :PSECURITY_DESCRIPTOR, :REFIID, :ptr ptr>, 32
    ifndef _STGCREATEPROPSTG_DEFINED_
      @DefProto DllImport, StgCreatePropStg, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFFMTID, :ptr CLSID, :DWORD, :DWORD, :ptr ptr IPropertyStorage>, 24
      @DefProto DllImport, StgOpenPropStg, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFFMTID, :DWORD, :DWORD, :ptr ptr IPropertyStorage>, 20
      @DefProto DllImport, StgCreatePropSetStg, WIN_STD_CALL_CONV,, <:ptr IStorage, :DWORD, :ptr ptr IPropertySetStorage>, 12
      CCH_MAX_PROPSTG_NAME equ 31
      @DefProto DllImport, FmtIdToPropStgName, WIN_STD_CALL_CONV,, <:ptr FMTID, :LPOLESTR>, 8
      @DefProto DllImport, PropStgNameToFmtId, WIN_STD_CALL_CONV,, <:LPOLESTR, :ptr FMTID>, 8
    endif
    @DefProto DllImport, ReadClassStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :ptr CLSID>, 8
    @DefProto DllImport, WriteClassStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :REFCLSID>, 8
    @DefProto DllImport, ReadClassStm, WIN_STD_CALL_CONV,, <:LPSTREAM, :ptr CLSID>, 8
    @DefProto DllImport, WriteClassStm, WIN_STD_CALL_CONV,, <:LPSTREAM, :REFCLSID>, 8
    @DefProto DllImport, GetHGlobalFromILockBytes, WIN_STD_CALL_CONV,, <:LPLOCKBYTES, :ptr HGLOBAL>, 8
    @DefProto DllImport, CreateILockBytesOnHGlobal, WIN_STD_CALL_CONV,, <:HGLOBAL, :BOOL, :ptr LPLOCKBYTES>, 12
    @DefProto DllImport, GetConvertStg, WIN_STD_CALL_CONV,, <:LPSTORAGE>, 4
  endif
endif
