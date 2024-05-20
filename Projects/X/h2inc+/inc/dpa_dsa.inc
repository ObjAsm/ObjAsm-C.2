;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dpa_dsa.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:13:44

;\*****************************************************************************
ifndef _INC_DPADSA
  _INC_DPADSA equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    ;* nonstandard extension : single line comment *
    ;* nonstandard extension used : nameless struct/union *
    ;* padding added after data member *
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _HRESULT_DEFINED
      _HRESULT_DEFINED equ <>
      HRESULT typedef SDWORD
    endif
    ; !_HRESULT_DEFINED
    ; Define API decoration for direct importing of DLL references.
    ifndef WINCOMMCTRLAPI
      if  not Defined(_COMCTL32_) and Defined(_WIN32)
        WINCOMMCTRLAPI equ <DECLSPEC_IMPORT>
      else
        WINCOMMCTRLAPI equ <>
      endif
    endif
    ; WINCOMMCTRLAPI
    ifdef __cplusplus
      ;[...]
    endif
    ifndef NO_COMMCTRL_DA
      __COMMCTRL_DA_DEFINED__ equ <>
      ;====== Dynamic Array routines ==========================================
      ; Note that the STL and other libraries have similar functionality.
      ; The routines here are specific to Windows and may not be as convenient
      ; or fully functional as those in other libraries.
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

      ; Dynamic structure array
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
      ; NTDDI_VISTA
      DSA_APPEND equ <DA_LAST>
      DSA_ERR equ <DA_ERR>
      PFNDSAENUMCALLBACK equ <PFNDAENUMCALLBACK>
      PFNDSAENUMCALLBACKCONST equ <PFNDAENUMCALLBACKCONST>
      PFNDSACOMPARE equ <PFNDACOMPARE>
      PFNDSACOMPARECONST equ <PFNDACOMPARECONST>
      ; Dynamic pointer array
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
      ; NTDDI_VISTA
      @DefProto DllImport, DPA_Sort, WIN_STD_CALL_CONV,, <:HDPA, :PFNDACOMPARE, :LPARAM>, 12
      ifdef __cplusplus
        ;[...]
      endif
      ; Save to and load from a stream.  The stream callback gets a pointer to
      ; a DPASTREAMINFO structure.
      ; For DPA_SaveStream, the callback is responsible for writing the pvItem
      ; info to the stream.  (It's not necessary to write the iPos to the
      ; stream.)  Return S_OK if the element was saved, S_FALSE if it wasn't
      ; but continue anyway, or some failure.
      ; For DPA_LoadStream, the callback is responsible for allocating an
      ; item and setting the pvItem field to the new pointer.  Return S_OK
      ; if the element was loaded, S_FALSE it it wasn't but continue anyway,
      ; or some failure.
      DPASTREAMINFO struct
        iPos SDWORD ?
        ; Index of item
        pvItem POINTER ?
      DPASTREAMINFO ends
      _DPASTREAMINFO typedef DPASTREAMINFO
      TYPE_PFNDPASTREAM typedef proto WIN_STD_CALL_CONV :ptr DPASTREAMINFO, :ptr IStream, :ptr
      PFNDPASTREAM typedef ptr TYPE_PFNDPASTREAM

      @DefProto DllImport, DPA_LoadStream, WIN_STD_CALL_CONV,, <:ptr HDPA, :PFNDPASTREAM, :ptr IStream, :ptr>, 16
      @DefProto DllImport, DPA_SaveStream, WIN_STD_CALL_CONV,, <:HDPA, :PFNDPASTREAM, :ptr IStream, :ptr>, 16
      ; Merge two DPAs.  This takes two (optionally) presorted arrays and merges
      ; the source array into the dest.  DPA_Merge uses the provided callbacks
      ; to perform comparison and merge operations.  The merge callback is
      ; called when two elements (one in each list) match according to the
      ; compare function.  This allows portions of an element in one list to
      ; be merged with the respective element in the second list.
      ; The first DPA (hdpaDest) is the output array.
      ; Merge options:
      ;    DPAM_SORTED       The arrays are already sorted; don't sort
      ;    DPAM_UNION        The resulting array is the union of all elements
      ;                      in both arrays (DPAMM_INSERT may be sent for
      ;                      this merge option.)
      ;    DPAM_INTERSECT    Only elements in the source array that intersect
      ;                      with the dest array are merged.  (DPAMM_DELETE
      ;                      may be sent for this merge option.)
      ;    DPAM_NORMAL       Like DPAM_INTERSECT except the dest array
      ;                      also maintains its original, additional elements.
      DPAM_SORTED equ 00000001h
      DPAM_NORMAL equ 00000002h
      DPAM_UNION equ 00000004h
      DPAM_INTERSECT equ 00000008h
      ; The merge callback should merge contents of the two items and return
      ; the pointer of the merged item.  It's okay to simply use pvDest
      ; as the returned pointer.
      TYPE_PFNDPAMERGE typedef proto WIN_STD_CALL_CONV :UINT, :ptr, :ptr, :LPARAM
      PFNDPAMERGE typedef ptr TYPE_PFNDPAMERGE

      TYPE_PFNDPAMERGECONST typedef proto WIN_STD_CALL_CONV :UINT, :ptr, :ptr, :LPARAM
      PFNDPAMERGECONST typedef ptr TYPE_PFNDPAMERGECONST

      ; Messages for merge callback
      DPAMM_MERGE equ 1
      DPAMM_DELETE equ 2
      DPAMM_INSERT equ 3
      @DefProto DllImport, DPA_Merge, WIN_STD_CALL_CONV,, <:HDPA, :HDPA, :DWORD, :PFNDACOMPARE, :PFNDPAMERGE, :LPARAM>, 24
      ifdef __cplusplus
        ;[...]
      endif
      ; Search array.  If DPAS_SORTED, then array is assumed to be sorted
      ; according to pfnCompare, and binary search algorithm is used.
      ; Otherwise, linear search is used.
      ; Searching starts at iStart (0 to start search at beginning).
      ; DPAS_INSERTBEFORE/AFTER govern what happens if an exact match is not
      ; found.  If neither are specified, this function returns -1 if no exact
      ; match is found.  Otherwise, the index of the item before or after the
      ; closest (including exact) match is returned.
      ; Search option flags
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
    ; NO_COMMCTRL_DA
    @DefProto DllImport, Str_SetPtrW, WIN_STD_CALL_CONV,, <:ptr LPWSTR, :LPCWSTR>, 8
    ;* RC complains about long symbols in #ifs *
    if  not Defined(RC_INVOKED)
      if Defined(ISOLATION_AWARE_ENABLED) and (ISOLATION_AWARE_ENABLED ne 0)
        ;[...]
      endif
      ;* RC *
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _INC_DPADSA *
endif
