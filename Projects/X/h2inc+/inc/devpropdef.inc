;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\devpropdef.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:38

include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
  ifndef _DEVPROPDEF_H_
    _DEVPROPDEF_H_ equ <>
    DEVPROPTYPE typedef ULONG
    PDEVPROPTYPE typedef ptr ULONG
    DEVPROP_TYPEMOD_ARRAY equ 00001000h
    DEVPROP_TYPEMOD_LIST equ 00002000h
    DEVPROP_TYPE_EMPTY equ 00000000h
    DEVPROP_TYPE_NULL equ 00000001h
    DEVPROP_TYPE_SBYTE equ 00000002h
    DEVPROP_TYPE_BYTE equ 00000003h
    DEVPROP_TYPE_INT16 equ 00000004h
    DEVPROP_TYPE_UINT16 equ 00000005h
    DEVPROP_TYPE_INT32 equ 00000006h
    DEVPROP_TYPE_UINT32 equ 00000007h
    DEVPROP_TYPE_INT64 equ 00000008h
    DEVPROP_TYPE_UINT64 equ 00000009h
    DEVPROP_TYPE_FLOAT equ 0000000Ah
    DEVPROP_TYPE_DOUBLE equ 0000000Bh
    DEVPROP_TYPE_DECIMAL equ 0000000Ch
    DEVPROP_TYPE_GUID equ 0000000Dh
    DEVPROP_TYPE_CURRENCY equ 0000000Eh
    DEVPROP_TYPE_DATE equ 0000000Fh
    DEVPROP_TYPE_FILETIME equ 00000010h
    DEVPROP_TYPE_BOOLEAN equ 00000011h
    DEVPROP_TYPE_STRING equ 00000012h
    DEVPROP_TYPE_STRING_LIST equ <(DEVPROP_TYPE_STRING or DEVPROP_TYPEMOD_LIST)>
    DEVPROP_TYPE_SECURITY_DESCRIPTOR equ 00000013h
    DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING equ 00000014h
    DEVPROP_TYPE_DEVPROPKEY equ 00000015h
    DEVPROP_TYPE_DEVPROPTYPE equ 00000016h
    DEVPROP_TYPE_BINARY equ <(DEVPROP_TYPE_BYTE or DEVPROP_TYPEMOD_ARRAY)>
    DEVPROP_TYPE_ERROR equ 00000017h
    DEVPROP_TYPE_NTSTATUS equ 00000018h
    DEVPROP_TYPE_STRING_INDIRECT equ 00000019h
    MAX_DEVPROP_TYPE equ 00000019h
    MAX_DEVPROP_TYPEMOD equ 00002000h
    DEVPROP_MASK_TYPE equ 00000FFFh
    DEVPROP_MASK_TYPEMOD equ 0000F000h
    DEVPROP_BOOLEAN typedef CHAR
    PDEVPROP_BOOLEAN typedef ptr CHAR
    DEVPROP_TRUE equ ((DEVPROP_BOOLEAN) - 1)
    DEVPROP_FALSE equ ((DEVPROP_BOOLEAN) 0)
    ifndef DEVPROPKEY_DEFINED
      DEVPROPKEY_DEFINED equ <>
      DEVPROPGUID typedef GUID
      PDEVPROPGUID typedef ptr GUID
      DEVPROPID typedef ULONG
      PDEVPROPID typedef ptr ULONG
      DEVPROPKEY struct
        fmtid DEVPROPGUID <>
        pid DEVPROPID ?
      DEVPROPKEY ends
      _DEVPROPKEY typedef DEVPROPKEY
      PDEVPROPKEY typedef ptr DEVPROPKEY
    endif
    ifndef IsEqualDevPropKey
      ifdef __cplusplus
        ;[...]
      else
        IsEqualDevPropKey macro a, b
          exitm <(((a).pid == (b).pid) and IsEqualGUID(and (a).fmtid, and (b).fmtid))>
        endm
      endif
    endif
    ifdef MIDL_PASS
      ;[...]
    endif
    DEVPROPSTORE typedef SDWORD
    DEVPROP_STORE_SYSTEM equ 0
    DEVPROP_STORE_USER equ 1
    _DEVPROPSTORE typedef DEVPROPSTORE
    PDEVPROPSTORE typedef ptr DEVPROPSTORE
    DEVPROPCOMPKEY struct
      Key DEVPROPKEY <>
      Store DEVPROPSTORE ?
      ifdef MIDL_PASS
        ;[...]
      else
        LocaleName PCWSTR ?
      endif
    DEVPROPCOMPKEY ends
    _DEVPROPCOMPKEY typedef DEVPROPCOMPKEY
    PDEVPROPCOMPKEY typedef ptr DEVPROPCOMPKEY
    ifndef IsEqualLocaleName
      IsEqualLocaleName macro a, b
        exitm <(((a) == (b)) or (((a) != NULL) and ((b) != NULL) and (_wcsicmp ((a), (b)) == 0)))>
      endm
    endif
    ifndef IsEqualDevPropCompKey
      IsEqualDevPropCompKey macro a, b
        exitm <(IsEqualDevPropKey((a).Key, (b).Key) and ((a).Store == (b).Store) and IsEqualLocaleName((a).LocaleName, (b).LocaleName))>
      endm
      ifdef __cplusplus
        ;[...]
      endif
    endif
    DEVPROPERTY struct
      CompKey DEVPROPCOMPKEY <>
      Type_ DEVPROPTYPE ?
      BufferSize ULONG ?
      ifdef MIDL_PASS
        ;[...]
      else
        __field_bcount_opt(BufferSize)
        Buffer PVOID ?
      endif
    DEVPROPERTY ends
    _DEVPROPERTY typedef DEVPROPERTY
    PDEVPROPERTY typedef ptr DEVPROPERTY
    DEVPROPID_FIRST_USABLE equ 2
  endif
  ifdef DEFINE_DEVPROPKEY
  endif
  ifdef INITGUID
    DEFINE_DEVPROPKEY macro name_, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid
      exitm <EXTERN_C const DEVPROPKEY DECLSPEC_SELECTANY name_ = { { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }, pid }>
    endm
  else
    DEFINE_DEVPROPKEY macro name_, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid
      exitm <EXTERN_C const DEVPROPKEY name_>
    endm
  endif
endif
