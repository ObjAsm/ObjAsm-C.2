;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmiscapi.h\mmiscapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:20

ifdef _MSC_VER
endif
ifndef _MMISCAPI_H_
  _MMISCAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNODRV
      ifdef _WIN32
        DRVCONFIGINFOEX struct
          dwDCISize DWORD ?
          lpszDCISectionName LPCWSTR ?
          lpszDCIAliasName LPCWSTR ?
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
          ifdef _WIN32
            DRVCONFIGINFO struct
              dwDCISize DWORD ?
              lpszDCISectionName LPCWSTR ?
              lpszDCIAliasName LPCWSTR ?
            DRVCONFIGINFO ends
            tagDRVCONFIGINFO typedef DRVCONFIGINFO
            PDRVCONFIGINFO typedef ptr DRVCONFIGINFO
            NPDRVCONFIGINFO typedef ptr DRVCONFIGINFO
            LPDRVCONFIGINFO typedef ptr DRVCONFIGINFO
          else
            ;[...]
          endif
          DRVCNF_CANCEL equ 0000h
          DRVCNF_OK equ 0001h
          DRVCNF_RESTART equ 0002h
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
        endif
      endif
      if (WINVER ge 030ah)
        DRV_CANCEL equ <DRVCNF_CANCEL>
        DRV_OK equ <DRVCNF_OK>
        DRV_RESTART equ <DRVCNF_RESTART>
      endif
      DRV_MCI_FIRST equ <DRV_RESERVED>
      DRV_MCI_LAST equ (DRV_RESERVED + 0FFFh)
      DriverCallback proto WIN_STD_CALL_CONV :DWORD_PTR, :DWORD, :HDRVR, :DWORD, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
      sndOpenSound proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :INT32, :PHANDLE
      TYPE_DRIVERMSGPROC typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
      DRIVERMSGPROC typedef ptr TYPE_DRIVERMSGPROC

      mmDrvInstall proto WIN_STD_CALL_CONV :HDRVR, :LPCWSTR, :DRIVERMSGPROC, :UINT
    endif
    ifndef MMNOMMIO
      MMIOERR_BASE equ 256
      MMIOERR_FILENOTFOUND equ (MMIOERR_BASE + 1)
      MMIOERR_OUTOFMEMORY equ (MMIOERR_BASE + 2)
      MMIOERR_CANNOTOPEN equ (MMIOERR_BASE + 3)
      MMIOERR_CANNOTCLOSE equ (MMIOERR_BASE + 4)
      MMIOERR_CANNOTREAD equ (MMIOERR_BASE + 5)
      MMIOERR_CANNOTWRITE equ (MMIOERR_BASE + 6)
      MMIOERR_CANNOTSEEK equ (MMIOERR_BASE + 7)
      MMIOERR_CANNOTEXPAND equ (MMIOERR_BASE + 8)
      MMIOERR_CHUNKNOTFOUND equ (MMIOERR_BASE + 9)
      MMIOERR_UNBUFFERED equ (MMIOERR_BASE + 10)
      MMIOERR_PATHNOTFOUND equ (MMIOERR_BASE + 11)
      MMIOERR_ACCESSDENIED equ (MMIOERR_BASE + 12)
      MMIOERR_SHARINGVIOLATION equ (MMIOERR_BASE + 13)
      MMIOERR_NETWORKERROR equ (MMIOERR_BASE + 14)
      MMIOERR_TOOMANYOPENFILES equ (MMIOERR_BASE + 15)
      MMIOERR_INVALIDFILE equ (MMIOERR_BASE + 16)
      CFSEPCHAR equ <' + '>
      FOURCC typedef DWORD
      HPSTR typedef ptr SBYTE
      DECLARE_HANDLE HMMIO
      TYPE_MMIOPROC typedef proto WIN_STD_CALL_CONV :LPSTR, :UINT, :LPARAM, :LPARAM
      MMIOPROC typedef ptr TYPE_MMIOPROC

      LPMMIOPROC typedef ptr MMIOPROC
      MMIOINFO struct
        dwFlags DWORD ?
        fccIOProc FOURCC ?
        pIOProc LPMMIOPROC ?
        wErrorRet UINT ?
        htask HTASK ?
        cchBuffer LONG ?
        pchBuffer HPSTR ?
        pchNext HPSTR ?
        pchEndRead HPSTR ?
        pchEndWrite HPSTR ?
        lBufOffset LONG ?
        lDiskOffset LONG ?
        adwInfo DWORD 3 dup (?)
        dwReserved1 DWORD ?
        dwReserved2 DWORD ?
        hmmio HMMIO ?
      MMIOINFO ends
      _MMIOINFO typedef MMIOINFO
      PMMIOINFO typedef ptr MMIOINFO
      NPMMIOINFO typedef ptr MMIOINFO
      LPMMIOINFO typedef ptr MMIOINFO
      LPCMMIOINFO typedef ptr MMIOINFO
      MMCKINFO struct
        ckid FOURCC ?
        cksize DWORD ?
        fccType FOURCC ?
        dwDataOffset DWORD ?
        dwFlags DWORD ?
      MMCKINFO ends
      _MMCKINFO typedef MMCKINFO
      PMMCKINFO typedef ptr MMCKINFO
      NPMMCKINFO typedef ptr MMCKINFO
      LPMMCKINFO typedef ptr MMCKINFO
      LPCMMCKINFO typedef ptr MMCKINFO
      MMIO_RWMODE equ 00000003h
      MMIO_SHAREMODE equ 00000070h
      MMIO_CREATE equ 00001000h
      MMIO_PARSE equ 00000100h
      MMIO_DELETE equ 00000200h
      MMIO_EXIST equ 00004000h
      MMIO_ALLOCBUF equ 00010000h
      MMIO_GETTEMP equ 00020000h
      MMIO_DIRTY equ 10000000h
      MMIO_READ equ 00000000h
      MMIO_WRITE equ 00000001h
      MMIO_READWRITE equ 00000002h
      MMIO_COMPAT equ 00000000h
      MMIO_EXCLUSIVE equ 00000010h
      MMIO_DENYWRITE equ 00000020h
      MMIO_DENYREAD equ 00000030h
      MMIO_DENYNONE equ 00000040h
      MMIO_FHOPEN equ 0010h
      MMIO_EMPTYBUF equ 0010h
      MMIO_TOUPPER equ 0010h
      MMIO_INSTALLPROC equ 00010000h
      MMIO_GLOBALPROC equ 10000000h
      MMIO_REMOVEPROC equ 00020000h
      MMIO_UNICODEPROC equ 01000000h
      MMIO_FINDPROC equ 00040000h
      MMIO_FINDCHUNK equ 0010h
      MMIO_FINDRIFF equ 0020h
      MMIO_FINDLIST equ 0040h
      MMIO_CREATERIFF equ 0020h
      MMIO_CREATELIST equ 0040h
      MMIOM_READ equ <MMIO_READ>
      MMIOM_WRITE equ <MMIO_WRITE>
      MMIOM_SEEK equ 2
      MMIOM_OPEN equ 3
      MMIOM_CLOSE equ 4
      MMIOM_WRITEFLUSH equ 5
      if (WINVER ge 030ah)
        MMIOM_RENAME equ 6
      endif
      MMIOM_USER equ 8000h
      FOURCC_RIFF equ <mmioFOURCC('R', 'I', 'F', 'F')>
      FOURCC_LIST equ <mmioFOURCC('L', 'I', 'S', 'T')>
      FOURCC_DOS equ <mmioFOURCC('D', 'O', 'S', ' ')>
      FOURCC_MEM equ <mmioFOURCC('M', 'E', 'M', ' ')>
      ifndef SEEK_SET
        SEEK_SET equ 0
        SEEK_CUR equ 1
        SEEK_END equ 2
      endif
      MMIO_DEFAULTBUFFER equ 8192
      mmioFOURCC macro ch0, ch1, ch2, ch3
        exitm <MAKEFOURCC(ch0, ch1, ch2, ch3)>
      endm
      ifdef _WIN32
        @DefProto DllImport, mmioStringToFOURCCA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
        @DefProto DllImport, mmioStringToFOURCCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT>, 8
        ifdef UNICODE
          mmioStringToFOURCC equ <mmioStringToFOURCCW>
        else
          mmioStringToFOURCC equ <mmioStringToFOURCCA>
        endif
        @DefProto DllImport, mmioInstallIOProcA, WIN_STD_CALL_CONV,, <:FOURCC, :LPMMIOPROC, :DWORD>, 12
        @DefProto DllImport, mmioInstallIOProcW, WIN_STD_CALL_CONV,, <:FOURCC, :LPMMIOPROC, :DWORD>, 12
        ifdef UNICODE
          mmioInstallIOProc equ <mmioInstallIOProcW>
        else
          mmioInstallIOProc equ <mmioInstallIOProcA>
        endif
        @DefProto DllImport, mmioOpenA, WIN_STD_CALL_CONV,, <:LPSTR, :LPMMIOINFO, :DWORD>, 12
        @DefProto DllImport, mmioOpenW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPMMIOINFO, :DWORD>, 12
        ifdef UNICODE
          mmioOpen equ <mmioOpenW>
        else
          mmioOpen equ <mmioOpenA>
        endif
        @DefProto DllImport, mmioRenameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCMMIOINFO, :DWORD>, 16
        @DefProto DllImport, mmioRenameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCMMIOINFO, :DWORD>, 16
        ifdef UNICODE
          mmioRename equ <mmioRenameW>
        else
          mmioRename equ <mmioRenameA>
        endif
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
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
