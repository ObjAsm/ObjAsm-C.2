;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dmemmgr.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 16/12/2023 11:07:08

;***************************************************************************
ifndef __DMEMMGR_INCLUDED__
  __DMEMMGR_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    ifndef __NTDDKCOMP__
      ;*
      ;* pointer to video memory
      ;*
      FLATPTR typedef ULONG_PTR
      LPVIDMEM typedef ptr _VIDMEM
    else
      ;*
      ;* pointer to video memory, potentially 64-bit
      ;*
      FLATPTR typedef ULONG_PTR
      LPVIDMEM typedef ptr _VIDEOMEMORY
    endif
    ;*
    ;* Structure for querying extended heap alignment requirements
    ;*
    SURFACEALIGNMENT struct
      union
        struct Linear
          dwStartAlignment DWORD ?
          dwPitchAlignment DWORD ?
          dwFlags DWORD ?
          dwReserved2 DWORD ?
        ends
        struct Rectangular
          dwXAlignment DWORD ?
          dwYAlignment DWORD ?
          dwFlags DWORD ?
          dwReserved2 DWORD ?
        ends
      ends
    SURFACEALIGNMENT ends
    _SURFACEALIGNMENT typedef SURFACEALIGNMENT
    LPSURFACEALIGNMENT typedef ptr _SURFACEALIGNMENT
    ;* Surface can be discarded to   *
    SURFACEALIGN_DISCARDABLE equ 00000001h
    ;* make room for another surface *
    HEAPALIGNMENT struct
      dwSize DWORD ?
      ddsCaps DDSCAPS <>
      ;* Indicates which alignment fields are valid.*
      dwReserved DWORD ?
      ExecuteBuffer SURFACEALIGNMENT <>
      ;* Surfaces tagged with DDSCAPS_EXECUTEBUFFER *
      Overlay SURFACEALIGNMENT <>
      ;* Surfaces tagged with DDSCAPS_OVERLAY       *
      Texture SURFACEALIGNMENT <>
      ;* Surfaces tagged with DDSCAPS_TEXTURE       *
      ZBuffer SURFACEALIGNMENT <>
      ;* Surfaces tagged with DDSCAPS_ZBUFFER       *
      AlphaBuffer SURFACEALIGNMENT <>
      ;* Surfaces tagged with DDSCAPS_ALPHA         *
      Offscreen SURFACEALIGNMENT <>
      ;* Surfaces tagged with DDSCAPS_OFFSCREENPLAIN*
      FlipTarget SURFACEALIGNMENT <>
      ;* Surfaces whose bits are potential primaries i.e. back buffers*
    HEAPALIGNMENT ends
    _HEAPALIGNMENT typedef HEAPALIGNMENT
    LPHEAPALIGNMENT typedef ptr _HEAPALIGNMENT
    DD_GETHEAPALIGNMENTDATA struct
      dwInstance XWORD ?
      ; driver context
      dwHeap DWORD ?
      ; heap index passed by DirectDraw
      ddRVal HRESULT ?
      ; return value
      GetHeapAlignment POINTER ?
      ; Unused: Win95 compatibility
      Alignment HEAPALIGNMENT <>
      ; Filled in by driver.
    DD_GETHEAPALIGNMENTDATA ends
    _DD_GETHEAPALIGNMENTDATA typedef DD_GETHEAPALIGNMENTDATA
    PDD_GETHEAPALIGNMENTDATA typedef ptr _DD_GETHEAPALIGNMENTDATA
    ;*
    ;* video memory manager structures
    ;*
    VMEML struct
      next POINTER ?
      ptr_ FLATPTR ?
      size_ DWORD ?
      bDiscardable DWORD ?
    VMEML ends
    _VMEML typedef VMEML
    LPVMEML typedef ptr VMEML
    LPLPVMEML typedef ptr ptr VMEML
    VMEMR struct
      next POINTER ?
      prev POINTER ?
      ;*
      ;* The pUp, pDown, pLeft and pRight members were removed in DX5
      ;*
      pUp POINTER ?
      pDown POINTER ?
      pLeft POINTER ?
      pRight POINTER ?
      ptr_ FLATPTR ?
      size_ DWORD ?
      x DWORD ?
      y DWORD ?
      cx_ DWORD ?
      cy DWORD ?
      flags DWORD ?
      pBits FLATPTR ?
      bDiscardable DWORD ?
    VMEMR ends
    _VMEMR typedef VMEMR
    LPVMEMR typedef ptr VMEMR
    LPLPVMEMR typedef ptr ptr VMEMR
    VMEMHEAP struct
      dwFlags DWORD ?
      stride DWORD ?
      freeList POINTER ?
      allocList POINTER ?
      dwTotalSize DWORD ?
      fpGARTLin FLATPTR ?
      ;* AGP: GART linear base of heap (app. visible)   *
      fpGARTDev FLATPTR ?
      ;* AGP: GART device base of heap (driver visible) *
      dwCommitedSize DWORD ?
      ;* AGP: Number of bytes commited to heap          *
      ;*
      ;* Extended alignment data:
      ;* Filled in by DirectDraw in response to a GetHeapAlignment HAL call.
      ;*
      dwCoalesceCount DWORD ?
      Alignment HEAPALIGNMENT <>
      ;*
      ;* These are analogous to VIDMEM.ddsCaps and VIDMEM.ddsCapsAlt. These values are queried from the
      ;* driver by a GetDriverInfo call. See the documentation for GUID_DDMoreSurfaceCaps
      ;*
      ddsCapsEx DDSCAPSEX <>
      ddsCapsExAlt DDSCAPSEX <>
      ifndef IS_16
        ; Full physical address of heap base for NT AGP heaps.
        liPhysAGPBase LARGE_INTEGER <>
      endif
      ; hdev for use with VidMemAllocAligned on NT.  Set by the system at
      ; initialization time.
      hdevAGP HANDLE ?
      ; Physical reservation handle for NT heaps.
      pvPhysRsrv POINTER ?
      if (NTDDI_VERSION ge NTDDI_WINXP)
        pAgpCommitMask POINTER ?
        dwAgpCommitMaskSize DWORD ?
      endif
    VMEMHEAP ends
    _VMEMHEAP typedef VMEMHEAP
    LPVMEMHEAP typedef ptr VMEMHEAP
    ;* Heap is linear                    *
    VMEMHEAP_LINEAR equ 00000001h
    ;* Heap is rectangular               *
    VMEMHEAP_RECTANGULAR equ 00000002h
    ;* Heap has extended alignment info  *
    VMEMHEAP_ALIGNMENT equ 00000004h
    ;*
    ;* This legacy export doesn't handle nonlocal heaps
    ;* This function is not available on Windows NT
    ;*
    ifndef __NTDDKCOMP__
      VidMemAlloc proto WIN_STD_CALL_CONV :LPVMEMHEAP, :DWORD, :DWORD
    endif
    ;*
    ;* This export can be used by drivers to allocate aligned surfaces from heaps which
    ;* they have previously exposed to DirectDraw. This function can allocate from nonlocal heaps.
    ;*
    HeapVidMemAllocAligned proto WIN_STD_CALL_CONV :LPVIDMEM, :DWORD, :DWORD, :LPSURFACEALIGNMENT, :LPLONG
    ;*
    ;* This export can free memory allocated via either allocation function
    ;*
    VidMemFree proto WIN_STD_CALL_CONV :LPVMEMHEAP, :FLATPTR
    ifdef __cplusplus
      ;[...]
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
