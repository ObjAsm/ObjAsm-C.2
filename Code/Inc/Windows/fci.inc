;Include file created by h2incX, Version C.01.00, 25/10/2023 19:01
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um\fci.h', last modified: 08/05/2023 18:07
;Creation parameters: 

include fdi_fci_types.inc
ifndef INCLUDED_FCI
  INCLUDED_FCI equ 1
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    include specstrings.inc
    LPSTR typedef ptr SBYTE
    include basetsd.inc
    ifdef __cplusplus
      ;[...]
    endif
    ifndef _WIN64
      include pshpack4.inc
    endif
    FCIERROR typedef SDWORD
    FCIERR_NONE equ 0
    FCIERR_OPEN_SRC equ 1
    FCIERR_READ_SRC equ 2
    FCIERR_ALLOC_FAIL equ 3
    FCIERR_TEMP_FILE equ 4
    FCIERR_BAD_COMPR_TYPE equ 5
    FCIERR_CAB_FILE equ 6
    FCIERR_USER_ABORT equ 7
    FCIERR_MCI_FAIL equ 8
    FCIERR_CAB_FORMAT_LIMIT equ 9
    
    ifndef _A_NAME_IS_UTF
      _A_NAME_IS_UTF equ 80h
    endif
    ifndef _A_EXEC
      _A_EXEC equ 40h
    endif
    HFCI typedef ptr
    CCAB struct
      cb ULONG ?
      cbFolderThresh ULONG ?
      cbReserveCFHeader UINT ?
      cbReserveCFFolder UINT ?
      cbReserveCFData UINT ?
      iCab SDWORD ?
      iDisk SDWORD ?
      ifndef REMOVE_CHICAGO_M6_HACK
        fFailOnIncompressible SDWORD ?
      endif
      setID USHORT ?
      szDisk SBYTE CB_MAX_DISK_NAME dup (?)
      szCab SBYTE CB_MAX_CABINET_NAME dup (?)
      szCabPath SBYTE CB_MAX_CAB_PATH dup (?)
    CCAB ends

    PCCAB typedef ptr CCAB
    TYPE_PFNFCIALLOC typedef proto c :ULONG
    PFNFCIALLOC typedef ptr TYPE_PFNFCIALLOC
    FNFCIALLOC macro fn
      exitm <void HUGE * FAR DIAMONDAPI fn (ULONG cb)>
    endm
    TYPE_PFNFCIFREE typedef proto c :ptr
    PFNFCIFREE typedef ptr TYPE_PFNFCIFREE
    FNFCIFREE macro fn
      exitm <void FAR DIAMONDAPI fn (void HUGE * memory)>
    endm
    TYPE_PFNFCIOPEN typedef proto c :LPSTR, :SDWORD, :SDWORD, :ptr SDWORD, :ptr
    PFNFCIOPEN typedef ptr TYPE_PFNFCIOPEN
    TYPE_PFNFCIREAD typedef proto c :INT_PTR, :ptr, :UINT, :ptr SDWORD, :ptr
    PFNFCIREAD typedef ptr TYPE_PFNFCIREAD
    TYPE_PFNFCIWRITE typedef proto c :INT_PTR, :ptr, :UINT, :ptr SDWORD, :ptr
    PFNFCIWRITE typedef ptr TYPE_PFNFCIWRITE
    TYPE_PFNFCICLOSE typedef proto c :INT_PTR, :ptr SDWORD, :ptr
    PFNFCICLOSE typedef ptr TYPE_PFNFCICLOSE
    TYPE_PFNFCISEEK typedef proto c :INT_PTR, :SDWORD, :SDWORD, :ptr SDWORD, :ptr
    PFNFCISEEK typedef ptr TYPE_PFNFCISEEK
    TYPE_PFNFCIDELETE typedef proto c :LPSTR, :ptr SDWORD, :ptr
    PFNFCIDELETE typedef ptr TYPE_PFNFCIDELETE
    FNFCIOPEN macro fn
      exitm <INT_PTR FAR DIAMONDAPI fn (_In_ LPSTR pszFile, int oflag, int pmode, int FAR * err, void FAR * pv)>
    endm
    FNFCIREAD macro fn
      exitm <UINT FAR DIAMONDAPI fn (INT_PTR hf, void FAR * memory, UINT cb, int FAR * err, void FAR * pv)>
    endm
    FNFCIWRITE macro fn
      exitm <UINT FAR DIAMONDAPI fn (INT_PTR hf, void FAR * memory, UINT cb, int FAR * err, void FAR * pv)>
    endm
    FNFCICLOSE macro fn
      exitm <int FAR DIAMONDAPI fn (INT_PTR hf, int FAR * err, void FAR * pv)>
    endm
    FNFCISEEK macro fn
      exitm <long FAR DIAMONDAPI fn (INT_PTR hf, long dist, int seektype, int FAR * err, void FAR * pv)>
    endm
    FNFCIDELETE macro fn
      exitm <int FAR DIAMONDAPI fn (_In_ LPSTR pszFile, int FAR * err, void FAR * pv)>
    endm
    TYPE_PFNFCIGETNEXTCABINET typedef proto c :PCCAB, :ULONG, :ptr
    PFNFCIGETNEXTCABINET typedef ptr TYPE_PFNFCIGETNEXTCABINET
    FNFCIGETNEXTCABINET macro fn
      exitm <BOOL DIAMONDAPI fn (PCCAB pccab, ULONG cbPrevCab, void FAR * pv)>
    endm
    TYPE_PFNFCIFILEPLACED typedef proto c :PCCAB, :LPSTR, :SDWORD, :BOOL, :ptr
    PFNFCIFILEPLACED typedef ptr TYPE_PFNFCIFILEPLACED
    FNFCIFILEPLACED macro fn
      exitm <int DIAMONDAPI fn (PCCAB pccab, _In_ LPSTR pszFile, long cbFile, BOOL fContinuation, void FAR * pv)>
    endm
    TYPE_PFNFCIGETOPENINFO typedef proto c :LPSTR, :ptr USHORT, :ptr USHORT, :ptr USHORT, :ptr SDWORD, :ptr
    PFNFCIGETOPENINFO typedef ptr TYPE_PFNFCIGETOPENINFO
    FNFCIGETOPENINFO macro fn
      exitm <INT_PTR DIAMONDAPI fn (_In_ LPSTR pszName, USHORT * pdate, USHORT * ptime, USHORT * pattribs, int FAR * err, void FAR * pv)>
    endm
    statusFile equ 0
    statusFolder equ 1
    statusCabinet equ 2
    TYPE_PFNFCISTATUS typedef proto c :UINT, :ULONG, :ULONG, :ptr
    PFNFCISTATUS typedef ptr TYPE_PFNFCISTATUS
    FNFCISTATUS macro fn
      exitm <long DIAMONDAPI fn (UINT typeStatus, ULONG cb1, ULONG cb2, void FAR * pv)>
    endm
    TYPE_PFNFCIGETTEMPFILE typedef proto c :ptr SBYTE, :SDWORD, :ptr
    PFNFCIGETTEMPFILE typedef ptr TYPE_PFNFCIGETTEMPFILE
    FNFCIGETTEMPFILE macro fn
      exitm <BOOL DIAMONDAPI fn (_Out_writes_bytes_(cbTempName) char * pszTempName, _In_range_(<=, 260) int cbTempName, void FAR * pv)>
    endm
    FCICreate proto c :PERF, :PFNFCIFILEPLACED, :PFNFCIALLOC, :PFNFCIFREE, :PFNFCIOPEN, :PFNFCIREAD, :PFNFCIWRITE, :PFNFCICLOSE, :PFNFCISEEK, :PFNFCIDELETE, :PFNFCIGETTEMPFILE, :PCCAB, :ptr
    FCIAddFile proto c :HFCI, :LPSTR, :LPSTR, :BOOL, :PFNFCIGETNEXTCABINET, :PFNFCISTATUS, :PFNFCIGETOPENINFO, :TCOMP
    FCIFlushCabinet proto c :HFCI, :BOOL, :PFNFCIGETNEXTCABINET, :PFNFCISTATUS
    FCIFlushFolder proto c :HFCI, :PFNFCIGETNEXTCABINET, :PFNFCISTATUS
    FCIDestroy proto c :HFCI
    ifndef _WIN64
      include poppack.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
 