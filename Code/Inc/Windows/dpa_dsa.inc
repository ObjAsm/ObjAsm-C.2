;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dpa_dsa.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:13:44

ifndef _INC_DPADSA
  _INC_DPADSA equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _HRESULT_DEFINED
      _HRESULT_DEFINED equ <>
      HRESULT typedef SDWORD
    endif
    ifndef WINCOMMCTRLAPI
      if  not Defined(_COMCTL32_) and Defined(_WIN32)
        WINCOMMCTRLAPI equ <DECLSPEC_IMPORT>
      else
        WINCOMMCTRLAPI equ <>
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef NO_COMMCTRL_DA
      __COMMCTRL_DA_DEFINED__ equ <>
      DA_LAST equ (7FFFFFFFh)
      DA_ERR equ (- 1)
      TYPE_PFNDAENUMCALLBACK typedef proto WIN_STD_CALL_CONV :ptr, :ptr
      PFNDAENUMCALLBACK typedef ptr TYPE_PFNDAENUMCALLBACK

      TYPE_PFNDAENUMCALLBACKCONST typedef proto WIN_STD_CALL_CONV :ptr, :ptr
      PFNDAENUMCALLBACKCONST typedef ptr TYPE_PFNDAENUMCALLBACKCONST

      TYPE_PFNDACOMPARE typedef proto WIN_STD_CALL_CONV :ptr, :ptr, :LPARAM
      PFNDACOMPARE typedef ptr TYPE_PFNDACOMPARE

      TYPE_PFNDACOMPARECONST typedef proto WIN_STD_CALL_CONV :ptr, :ptr, :LPARAM
      PFNDACOMPARECONST typedef ptr TYPE_PFNDACOMPARECONST

      HDSA typedef ptr _DSA
      @DefProto DllImport, DSA_Create, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
      @DefProto DllImport, DSA_Destroy, WIN_STD_CALL_CONV,, <:HDSA>, 4
      @DefProto DllImport, DSA_DestroyCallback, WIN_STD_CALL_CONV,, <:HDSA, :PFNDAENUMCALLBACK, :ptr>, 12
      ifdef __cplusplus
        ;[...]
      endif
      @DefProto DllImport, DSA_DeleteItem, WIN_STD_CALL_CONV,, <:HDSA, :SDWORD>, 8
      @DefProto DllImport, DSA_DeleteAllItems, WIN_STD_CALL_CONV,, <:HDSA>, 4
      @DefProto DllImport, DSA_EnumCallback, WIN_STD_CALL_CONV,, <:HDSA, :PFNDAENUMCALLBACK, :ptr>, 12
      ifdef __cplusplus
        ;[...]
      endif
      @DefProto DllImport, DSA_InsertItem, WIN_STD_CALL_CONV,, <:HDSA, :SDWORD, :ptr>, 12
      @DefProto DllImport, DSA_GetItemPtr, WIN_STD_CALL_CONV,, <:HDSA, :SDWORD>, 8
      @DefProto DllImport, DSA_GetItem, WIN_STD_CALL_CONV,, <:HDSA, :SDWORD, :ptr>, 12
      @DefProto DllImport, DSA_SetItem, WIN_STD_CALL_CONV,, <:HDSA, :SDWORD, :ptr>, 12
      DSA_GetItemCount macro hdsa
        exitm <(* (hdsa))>
      endm
      DSA_AppendItem macro hdsa, pitem
        exitm <DSA_InsertItem (hdsa, DA_LAST, pitem)>
      endm
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, DSA_Clone, WIN_STD_CALL_CONV,, <:HDSA>, 4
        @DefProto DllImport, DSA_GetSize, WIN_STD_CALL_CONV,, <:HDSA>, 4
        @DefProto DllImport, DSA_Sort, WIN_STD_CALL_CONV,, <:HDSA, :PFNDACOMPARE, :LPARAM>, 12
        ifdef __cplusplus
          ;[...]
        endif
      endif
      DSA_APPEND equ <DA_LAST>
      DSA_ERR equ <DA_ERR>
      PFNDSAENUMCALLBACK equ <PFNDAENUMCALLBACK>
      PFNDSAENUMCALLBACKCONST equ <PFNDAENUMCALLBACKCONST>
      PFNDSACOMPARE equ <PFNDACOMPARE>
      PFNDSACOMPARECONST equ <PFNDACOMPARECONST>
      HDPA typedef ptr _DPA
      @DefProto DllImport, DPA_Create, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      @DefProto DllImport, DPA_CreateEx, WIN_STD_CALL_CONV,, <:SDWORD, :HANDLE>, 8
      @DefProto DllImport, DPA_Clone, WIN_STD_CALL_CONV,, <:HDPA, :HDPA>, 8
      @DefProto DllImport, DPA_Destroy, WIN_STD_CALL_CONV,, <:HDPA>, 4
      @DefProto DllImport, DPA_DestroyCallback, WIN_STD_CALL_CONV,, <:HDPA, :PFNDAENUMCALLBACK, :ptr>, 12
      ifdef __cplusplus
        ;[...]
      endif
      @DefProto DllImport, DPA_DeletePtr, WIN_STD_CALL_CONV,, <:HDPA, :SDWORD>, 8
      @DefProto DllImport, DPA_DeleteAllPtrs, WIN_STD_CALL_CONV,, <:HDPA>, 4
      @DefProto DllImport, DPA_EnumCallback, WIN_STD_CALL_CONV,, <:HDPA, :PFNDAENUMCALLBACK, :ptr>, 12
      ifdef __cplusplus
        ;[...]
      endif
      @DefProto DllImport, DPA_Grow, WIN_STD_CALL_CONV,, <:HDPA, :SDWORD>, 8
      @DefProto DllImport, DPA_InsertPtr, WIN_STD_CALL_CONV,, <:HDPA, :SDWORD, :ptr>, 12
      @DefProto DllImport, DPA_SetPtr, WIN_STD_CALL_CONV,, <:HDPA, :SDWORD, :ptr>, 12
      @DefProto DllImport, DPA_GetPtr, WIN_STD_CALL_CONV,, <:HDPA, :INT_PTR>, 8
      @DefProto DllImport, DPA_GetPtrIndex, WIN_STD_CALL_CONV,, <:HDPA, :ptr>, 8
      DPA_GetPtrCount macro hdpa
        exitm <(* (hdpa))>
      endm
      DPA_SetPtrCount macro hdpa, cItems
        exitm <(* (hdpa) = (cItems))>
      endm
      DPA_FastDeleteLastPtr macro hdpa
        exitm <(- * (hdpa))>
      endm
      DPA_GetPtrPtr macro hdpa
        exitm <(* (((hdpa) + sizeof(void *))))>
      endm
      DPA_FastGetPtr macro hdpa, i
        exitm <(DPA_GetPtrPtr(hdpa) [ i ])>
      endm
      DPA_AppendPtr macro hdpa, pitem
        exitm <DPA_InsertPtr (hdpa, DA_LAST, pitem)>
      endm
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, DPA_GetSize, WIN_STD_CALL_CONV,, <:HDPA>, 4
      endif
      @DefProto DllImport, DPA_Sort, WIN_STD_CALL_CONV,, <:HDPA, :PFNDACOMPARE, :LPARAM>, 12
      ifdef __cplusplus
        ;[...]
      endif
      DPASTREAMINFO struct
        iPos SDWORD ?
        pvItem POINTER ?
      DPASTREAMINFO ends
      _DPASTREAMINFO typedef DPASTREAMINFO
      TYPE_PFNDPASTREAM typedef proto WIN_STD_CALL_CONV :ptr DPASTREAMINFO, :ptr IStream, :ptr
      PFNDPASTREAM typedef ptr TYPE_PFNDPASTREAM

      @DefProto DllImport, DPA_LoadStream, WIN_STD_CALL_CONV,, <:ptr HDPA, :PFNDPASTREAM, :ptr IStream, :ptr>, 16
      @DefProto DllImport, DPA_SaveStream, WIN_STD_CALL_CONV,, <:HDPA, :PFNDPASTREAM, :ptr IStream, :ptr>, 16
      DPAM_SORTED equ 00000001h
      DPAM_NORMAL equ 00000002h
      DPAM_UNION equ 00000004h
      DPAM_INTERSECT equ 00000008h
      TYPE_PFNDPAMERGE typedef proto WIN_STD_CALL_CONV :UINT, :ptr, :ptr, :LPARAM
      PFNDPAMERGE typedef ptr TYPE_PFNDPAMERGE

      TYPE_PFNDPAMERGECONST typedef proto WIN_STD_CALL_CONV :UINT, :ptr, :ptr, :LPARAM
      PFNDPAMERGECONST typedef ptr TYPE_PFNDPAMERGECONST

      DPAMM_MERGE equ 1
      DPAMM_DELETE equ 2
      DPAMM_INSERT equ 3
      @DefProto DllImport, DPA_Merge, WIN_STD_CALL_CONV,, <:HDPA, :HDPA, :DWORD, :PFNDACOMPARE, :PFNDPAMERGE, :LPARAM>, 24
      ifdef __cplusplus
        ;[...]
      endif
      DPAS_SORTED equ 0001h
      DPAS_INSERTBEFORE equ 0002h
      DPAS_INSERTAFTER equ 0004h
      @DefProto DllImport, DPA_Search, WIN_STD_CALL_CONV,, <:HDPA, :ptr, :SDWORD, :PFNDACOMPARE, :LPARAM, :UINT>, 24
      ifdef __cplusplus
        ;[...]
      endif
      DPA_SortedInsertPtr macro hdpa, pFind, iStart, pfnCompare, lParam, options, pitem
        exitm <DPA_InsertPtr (hdpa, DPA_Search (hdpa, pFind, iStart, pfnCompare, lParam, (DPAS_SORTED or (options))), (pitem))>
      endm
      DPA_APPEND equ <DA_LAST>
      DPA_ERR equ <DA_ERR>
      PFNDPAENUMCALLBACK equ <PFNDAENUMCALLBACK>
      PFNDPAENUMCALLBACKCONST equ <PFNDAENUMCALLBACKCONST>
      PFNDPACOMPARE equ <PFNDACOMPARE>
      PFNDPACOMPARECONST equ <PFNDACOMPARECONST>
    endif
    @DefProto DllImport, Str_SetPtrW, WIN_STD_CALL_CONV,, <:ptr LPWSTR, :LPCWSTR>, 8
    if  not Defined(RC_INVOKED)
      if Defined(ISOLATION_AWARE_ENABLED) and (ISOLATION_AWARE_ENABLED ne 0)
        ;[...]
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
  endif
endif
