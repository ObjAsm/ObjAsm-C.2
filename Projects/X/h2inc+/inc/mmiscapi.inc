;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmiscapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:20

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _MMISCAPI_H_
  _MMISCAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ; mm common definitions
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNODRV
      ;****************************************************************************
      ;Installable driver support
      ;****************************************************************************
      ifdef _WIN32
        DRVCONFIGINFOEX struct
          dwDCISize DWORD ?
          lpszDCISectionName =POINTER ?
          lpszDCIAliasName =POINTER ?
          dnDevNode DWORD ?
        DRVCONFIGINFOEX ends
        PDRVCONFIGINFOEX typedef ptr DRVCONFIGINFOEX
        NPDRVCONFIGINFOEX typedef ptr DRVCONFIGINFOEX
        LPDRVCONFIGINFOEX typedef ptr DRVCONFIGINFOEX
      else
        ;[...]
      endif
      if (WINVER lt 030ah) or Defined(_WIN32)
        ifndef DRV_LOAD
          ;* Driver messages *
          DRV_LOAD equ 0001h
          DRV_ENABLE equ 0002h
          DRV_OPEN equ 0003h
          DRV_CLOSE equ 0004h
          DRV_DISABLE equ 0005h
          DRV_FREE equ 0006h
          DRV_CONFIGURE equ 0007h
          DRV_QUERYCONFIGURE equ 0008h
          DRV_INSTALL equ 0009h
          DRV_REMOVE equ 000Ah
          DRV_EXITSESSION equ 000Bh
          DRV_POWER equ 000Fh
          DRV_RESERVED equ 0800h
          DRV_USER equ 4000h
          ;* LPARAM of DRV_CONFIGURE message *
          ifdef _WIN32
            DRVCONFIGINFO struct
              dwDCISize DWORD ?
              lpszDCISectionName =POINTER ?
              lpszDCIAliasName =POINTER ?
            DRVCONFIGINFO ends
            tagDRVCONFIGINFO typedef DRVCONFIGINFO
            PDRVCONFIGINFO typedef ptr DRVCONFIGINFO
            NPDRVCONFIGINFO typedef ptr DRVCONFIGINFO
            LPDRVCONFIGINFO typedef ptr DRVCONFIGINFO
          else
            ;[...]
          endif
          ;* Supported return values for DRV_CONFIGURE message *
          DRVCNF_CANCEL equ 0000h
          DRVCNF_OK equ 0001h
          DRVCNF_RESTART equ 0002h
          ;* installable driver function prototypes *
          ifdef _WIN32
            TYPE_DRIVERPROC typedef proto WIN_STD_CALL_CONV :DWORD_PTR, :HDRVR, :UINT, :LPARAM, :LPARAM
            DRIVERPROC typedef ptr TYPE_DRIVERPROC

            @DefProto DllImport, CloseDriver, WIN_STD_CALL_CONV,, <:HDRVR, :LPARAM, :LPARAM>, 12
            @DefProto DllImport, OpenDriver, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPARAM>, 12
            @DefProto DllImport, SendDriverMessage, WIN_STD_CALL_CONV,, <:HDRVR, :UINT, :LPARAM, :LPARAM>, 16
            @DefProto DllImport, DrvGetModuleHandle, WIN_STD_CALL_CONV,, <:HDRVR>, 4
            @DefProto DllImport, GetDriverModuleHandle, WIN_STD_CALL_CONV,, <:HDRVR>, 4
            @DefProto DllImport, DefDriverProc, WIN_STD_CALL_CONV,, <:DWORD_PTR, :HDRVR, :UINT, :LPARAM, :LPARAM>, 20
          else
            ;[...]
          endif
          ;* DRV_LOAD *
        endif
        ;* ifdef (WINVER < 0x030a) || defined(_WIN32) *
      endif
      if (WINVER ge 030ah)
        ;* return values from DriverProc() function *
        DRV_CANCEL equ <DRVCNF_CANCEL>
        DRV_OK equ <DRVCNF_OK>
        DRV_RESTART equ <DRVCNF_RESTART>
        ;* ifdef WINVER >= 0x030a *
      endif
      DRV_MCI_FIRST equ <DRV_RESERVED>
      DRV_MCI_LAST equ (DRV_RESERVED + 0FFFh)
      ;***************************************************************************
      ;Driver Helper function moved from mmddk.h
      ;***************************************************************************
      DriverCallback proto WIN_STD_CALL_CONV :DWORD_PTR, :DWORD, :HDRVR, :DWORD, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
      ;****************************************************************************
      ;Sound schemes
      ;****************************************************************************
      sndOpenSound proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :INT32, :PHANDLE
      ; removed from winmmi.h
      ;****************************************************************************
      ;API to install/remove/query a MMSYS driver
      ;****************************************************************************
      ;* generic prototype for audio device driver entry-point functions
      ; midMessage(), modMessage(), widMessage(), wodMessage(), auxMessage()
      ;*
      TYPE_DRIVERMSGPROC typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
      DRIVERMSGPROC typedef ptr TYPE_DRIVERMSGPROC

      mmDrvInstall proto WIN_STD_CALL_CONV :HDRVR, :LPCWSTR, :DRIVERMSGPROC, :UINT
      ;* ifndef MMNODRV *
    endif
    ifndef MMNOMMIO
      ;****************************************************************************
      ;Multimedia File I/O support
      ;****************************************************************************
      ;* MMIO error return values *
      MMIOERR_BASE equ 256
      ;* file not found *
      MMIOERR_FILENOTFOUND equ (MMIOERR_BASE + 1)
      ;* out of memory *
      MMIOERR_OUTOFMEMORY equ (MMIOERR_BASE + 2)
      ;* cannot open *
      MMIOERR_CANNOTOPEN equ (MMIOERR_BASE + 3)
      ;* cannot close *
      MMIOERR_CANNOTCLOSE equ (MMIOERR_BASE + 4)
      ;* cannot read *
      MMIOERR_CANNOTREAD equ (MMIOERR_BASE + 5)
      ;* cannot write *
      MMIOERR_CANNOTWRITE equ (MMIOERR_BASE + 6)
      ;* cannot seek *
      MMIOERR_CANNOTSEEK equ (MMIOERR_BASE + 7)
      ;* cannot expand file *
      MMIOERR_CANNOTEXPAND equ (MMIOERR_BASE + 8)
      ;* chunk not found *
      MMIOERR_CHUNKNOTFOUND equ (MMIOERR_BASE + 9)
      ;*  *
      MMIOERR_UNBUFFERED equ (MMIOERR_BASE + 10)
      ;* path incorrect *
      MMIOERR_PATHNOTFOUND equ (MMIOERR_BASE + 11)
      ;* file was protected *
      MMIOERR_ACCESSDENIED equ (MMIOERR_BASE + 12)
      ;* file in use *
      MMIOERR_SHARINGVIOLATION equ (MMIOERR_BASE + 13)
      ;* network not responding *
      MMIOERR_NETWORKERROR equ (MMIOERR_BASE + 14)
      ;* no more file handles  *
      MMIOERR_TOOMANYOPENFILES equ (MMIOERR_BASE + 15)
      ;* default error file error *
      MMIOERR_INVALIDFILE equ (MMIOERR_BASE + 16)
      ;* MMIO constants *
      ;* compound file name separator char. *
      CFSEPCHAR equ <' + '>
      ;* MMIO data types *
      ;* a four character code *
      FOURCC typedef DWORD
      ;* a huge version of LPSTR *
      HPSTR typedef ptr SBYTE
      ;* a handle to an open file *
      DECLARE_HANDLE HMMIO
      TYPE_MMIOPROC typedef proto WIN_STD_CALL_CONV :LPSTR, :UINT, :LPARAM, :LPARAM
      MMIOPROC typedef ptr TYPE_MMIOPROC

      LPMMIOPROC typedef ptr MMIOPROC
      ;* general MMIO information data structure *
      MMIOINFO struct
        ;* general fields *
        dwFlags DWORD ?
        ;* general status flags *
        fccIOProc FOURCC ?
        ;* pointer to I/O procedure *
        pIOProc LPMMIOPROC ?
        ;* pointer to I/O procedure *
        wErrorRet DWORD ?
        ;* place for error to be returned *
        htask HTASK ?
        ;* alternate local task *
        ;* fields maintained by MMIO functions during buffered I/O *
        cchBuffer SDWORD ?
        ;* size of I/O buffer (or 0L) *
        pchBuffer HPSTR ?
        ;* start of I/O buffer (or NULL) *
        pchNext HPSTR ?
        ;* pointer to next byte to read/write *
        pchEndRead HPSTR ?
        ;* pointer to last valid byte to read *
        pchEndWrite HPSTR ?
        ;* pointer to last byte to write *
        lBufOffset SDWORD ?
        ;* disk offset of start of buffer *
        ;* fields maintained by I/O procedure *
        lDiskOffset SDWORD ?
        ;* disk offset of next read or write *
        adwInfo DWORD 3 dup (?)
        ;* data specific to type of MMIOPROC *
        ;* other fields maintained by MMIO *
        dwReserved1 DWORD ?
        ;* reserved for MMIO use *
        dwReserved2 DWORD ?
        ;* reserved for MMIO use *
        hmmio HMMIO ?
        ;* handle to open file *
      MMIOINFO ends
      _MMIOINFO typedef MMIOINFO
      PMMIOINFO typedef ptr MMIOINFO
      NPMMIOINFO typedef ptr MMIOINFO
      LPMMIOINFO typedef ptr MMIOINFO
      LPCMMIOINFO typedef ptr MMIOINFO
      ;* RIFF chunk information data structure *
      MMCKINFO struct
        ckid FOURCC ?
        ;* chunk ID *
        cksize DWORD ?
        ;* chunk size *
        fccType FOURCC ?
        ;* form type or list type *
        dwDataOffset DWORD ?
        ;* offset of data portion of chunk *
        dwFlags DWORD ?
        ;* flags used by MMIO functions *
      MMCKINFO ends
      _MMCKINFO typedef MMCKINFO
      PMMCKINFO typedef ptr MMCKINFO
      NPMMCKINFO typedef ptr MMCKINFO
      LPMMCKINFO typedef ptr MMCKINFO
      LPCMMCKINFO typedef ptr MMCKINFO
      ;* bit field masks *
      ;* open file for reading/writing/both *
      MMIO_RWMODE equ 00000003h
      ;* file sharing mode number *
      MMIO_SHAREMODE equ 00000070h
      ;* constants for dwFlags field of MMIOINFO *
      ;* create new file (or truncate file) *
      MMIO_CREATE equ 00001000h
      ;* parse new file returning path *
      MMIO_PARSE equ 00000100h
      ;* create new file (or truncate file) *
      MMIO_DELETE equ 00000200h
      ;* checks for existence of file *
      MMIO_EXIST equ 00004000h
      ;* mmioOpen() should allocate a buffer *
      MMIO_ALLOCBUF equ 00010000h
      ;* mmioOpen() should retrieve temp name *
      MMIO_GETTEMP equ 00020000h
      ;* I/O buffer is dirty *
      MMIO_DIRTY equ 10000000h
      ;* read/write mode numbers (bit field MMIO_RWMODE) *
      ;* open file for reading only *
      MMIO_READ equ 00000000h
      ;* open file for writing only *
      MMIO_WRITE equ 00000001h
      ;* open file for reading and writing *
      MMIO_READWRITE equ 00000002h
      ;* share mode numbers (bit field MMIO_SHAREMODE) *
      ;* compatibility mode *
      MMIO_COMPAT equ 00000000h
      ;* exclusive-access mode *
      MMIO_EXCLUSIVE equ 00000010h
      ;* deny writing to other processes *
      MMIO_DENYWRITE equ 00000020h
      ;* deny reading to other processes *
      MMIO_DENYREAD equ 00000030h
      ;* deny nothing to other processes *
      MMIO_DENYNONE equ 00000040h
      ;* various MMIO flags *
      ;* mmioClose: keep file handle open *
      MMIO_FHOPEN equ 0010h
      ;* mmioFlush: empty the I/O buffer *
      MMIO_EMPTYBUF equ 0010h
      ;* mmioStringToFOURCC: to u-case *
      MMIO_TOUPPER equ 0010h
      ;* mmioInstallIOProc: install MMIOProc *
      MMIO_INSTALLPROC equ 00010000h
      ;* mmioInstallIOProc: install globally *
      MMIO_GLOBALPROC equ 10000000h
      ;* mmioInstallIOProc: remove MMIOProc *
      MMIO_REMOVEPROC equ 00020000h
      ;* mmioInstallIOProc: Unicode MMIOProc *
      MMIO_UNICODEPROC equ 01000000h
      ;* mmioInstallIOProc: find an MMIOProc *
      MMIO_FINDPROC equ 00040000h
      ;* mmioDescend: find a chunk by ID *
      MMIO_FINDCHUNK equ 0010h
      ;* mmioDescend: find a LIST chunk *
      MMIO_FINDRIFF equ 0020h
      ;* mmioDescend: find a RIFF chunk *
      MMIO_FINDLIST equ 0040h
      ;* mmioCreateChunk: make a LIST chunk *
      MMIO_CREATERIFF equ 0020h
      ;* mmioCreateChunk: make a RIFF chunk *
      MMIO_CREATELIST equ 0040h
      ;* message numbers for MMIOPROC I/O procedure functions *
      ;* read *
      MMIOM_READ equ <MMIO_READ>
      ;* write *
      MMIOM_WRITE equ <MMIO_WRITE>
      ;* seek to a new position in file *
      MMIOM_SEEK equ 2
      ;* open file *
      MMIOM_OPEN equ 3
      ;* close file *
      MMIOM_CLOSE equ 4
      ;* write and flush *
      MMIOM_WRITEFLUSH equ 5
      if (WINVER ge 030ah)
        ;* rename specified file *
        MMIOM_RENAME equ 6
        ;* ifdef WINVER >= 0x030a *
      endif
      ;* beginning of user-defined messages *
      MMIOM_USER equ 8000h
      ;* standard four character codes *
      FOURCC_RIFF equ <mmioFOURCC('R', 'I', 'F', 'F')>
      FOURCC_LIST equ <mmioFOURCC('L', 'I', 'S', 'T')>
      ;* four character codes used to identify standard built-in I/O procedures *
      FOURCC_DOS equ <mmioFOURCC('D', 'O', 'S', ' ')>
      FOURCC_MEM equ <mmioFOURCC('M', 'E', 'M', ' ')>
      ;* flags for mmioSeek() *
      ifndef SEEK_SET
        ;* seek to an absolute position *
        SEEK_SET equ 0
        ;* seek relative to current position *
        SEEK_CUR equ 1
        ;* seek relative to end of file *
        SEEK_END equ 2
        ;* ifndef SEEK_SET *
      endif
      ;* other constants *
      ;* default buffer size *
      MMIO_DEFAULTBUFFER equ 8192
      ;* MMIO macros *
      mmioFOURCC macro ch0, ch1, ch2, ch3
        exitm <MAKEFOURCC(ch0, ch1, ch2, ch3)>
      endm
      ;* MMIO function prototypes *
      ifdef _WIN32
        @DefProto DllImport, mmioStringToFOURCCA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
        @DefProto DllImport, mmioStringToFOURCCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT>, 8
        ifdef UNICODE
          mmioStringToFOURCC equ <mmioStringToFOURCCW>
        else
          mmioStringToFOURCC equ <mmioStringToFOURCCA>
        endif
        ; !UNICODE
        @DefProto DllImport, mmioInstallIOProcA, WIN_STD_CALL_CONV,, <:FOURCC, :LPMMIOPROC, :DWORD>, 12
        @DefProto DllImport, mmioInstallIOProcW, WIN_STD_CALL_CONV,, <:FOURCC, :LPMMIOPROC, :DWORD>, 12
        ifdef UNICODE
          mmioInstallIOProc equ <mmioInstallIOProcW>
        else
          mmioInstallIOProc equ <mmioInstallIOProcA>
        endif
        ; !UNICODE
        @DefProto DllImport, mmioOpenA, WIN_STD_CALL_CONV,, <:LPSTR, :LPMMIOINFO, :DWORD>, 12
        @DefProto DllImport, mmioOpenW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPMMIOINFO, :DWORD>, 12
        ifdef UNICODE
          mmioOpen equ <mmioOpenW>
        else
          mmioOpen equ <mmioOpenA>
        endif
        ; !UNICODE
        @DefProto DllImport, mmioRenameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCMMIOINFO, :DWORD>, 16
        @DefProto DllImport, mmioRenameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCMMIOINFO, :DWORD>, 16
        ifdef UNICODE
          mmioRename equ <mmioRenameW>
        else
          mmioRename equ <mmioRenameA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, mmioClose, WIN_STD_CALL_CONV,, <:HMMIO, :UINT>, 8
      @DefProto DllImport, mmioRead, WIN_STD_CALL_CONV,, <:HMMIO, :HPSTR, :LONG>, 12
      @DefProto DllImport, mmioWrite, WIN_STD_CALL_CONV,, <:HMMIO, :ptr SBYTE, :LONG>, 12
      @DefProto DllImport, mmioSeek, WIN_STD_CALL_CONV,, <:HMMIO, :LONG, :SDWORD>, 12
      @DefProto DllImport, mmioGetInfo, WIN_STD_CALL_CONV,, <:HMMIO, :LPMMIOINFO, :UINT>, 12
      @DefProto DllImport, mmioSetInfo, WIN_STD_CALL_CONV,, <:HMMIO, :LPCMMIOINFO, :UINT>, 12
      @DefProto DllImport, mmioSetBuffer, WIN_STD_CALL_CONV,, <:HMMIO, :LPSTR, :LONG, :UINT>, 16
      @DefProto DllImport, mmioFlush, WIN_STD_CALL_CONV,, <:HMMIO, :UINT>, 8
      @DefProto DllImport, mmioAdvance, WIN_STD_CALL_CONV,, <:HMMIO, :LPMMIOINFO, :UINT>, 12
      @DefProto DllImport, mmioSendMessage, WIN_STD_CALL_CONV,, <:HMMIO, :UINT, :LPARAM, :LPARAM>, 16
      @DefProto DllImport, mmioDescend, WIN_STD_CALL_CONV,, <:HMMIO, :LPMMCKINFO, :ptr MMCKINFO, :UINT>, 16
      @DefProto DllImport, mmioAscend, WIN_STD_CALL_CONV,, <:HMMIO, :LPMMCKINFO, :UINT>, 12
      @DefProto DllImport, mmioCreateChunk, WIN_STD_CALL_CONV,, <:HMMIO, :LPMMCKINFO, :UINT>, 12
      ;* ifndef MMNOMMIO *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _MMISCAPI_H_
