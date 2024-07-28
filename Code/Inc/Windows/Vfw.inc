;Include file created by h2incX, Version C.01.00, 02/05/2019 09:11
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\Vfw.h', last modified: 22/10/2018 21:35
;Creation parameters: 

ifndef _INC_VFW
  _INC_VFW equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    VFWAPI equ <WINAPI>
    VFWAPIV equ <WINAPIV>
    if (_WIN32_WINNT ge _WIN32_WINNT_WS03)
      VFWAPI_INLINE equ <WINAPI_INLINE>
    else
      VFWAPI_INLINE equ <WINAPI>
    endif
    VideoForWindowsVersion proto WIN_STD_CALL_CONV
    InitVFW proto WIN_STD_CALL_CONV
    TermVFW proto WIN_STD_CALL_CONV
    ifdef __cplusplus
      ;[...]
    endif
    if  not Defined(_INC_MMSYSTEM) and ( not Defined(NOVIDEO) or  not Defined(NOAVICAP))
      include mmsystem.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef MKFOURCC
      MKFOURCC macro ch0, ch1, ch2, ch3
        exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
      endm
    endif
    if  not Defined(_INC_MMSYSTEM)
      mmioFOURCC equ <MKFOURCC>
    endif
    ifndef NOCOMPMAN
      ICVERSION equ 0104h
      DECLARE_HANDLE HIC
      BI_1632 equ 32333631h
      ifndef mmioFOURCC
        mmioFOURCC macro ch0, ch1, ch2, ch3
          exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
        endm
      endif
      ifndef aviTWOCC
        aviTWOCC macro ch0, ch1
          exitm <((ch0) or ((ch1) shl 8))>
        endm
      endif
      ifndef ICTYPE_VIDEO
        ICTYPE_VIDEO equ <mmioFOURCC('v', 'i', 'd', 'c')>
        ICTYPE_AUDIO equ <mmioFOURCC('a', 'u', 'd', 'c')>
      endif
      ifndef ICERR_OK
        ICERR_OK equ 0
        ICERR_DONTDRAW equ 1
        ICERR_NEWPALETTE equ 2
        ICERR_GOTOKEYFRAME equ 3
        ICERR_STOPDRAWING equ 4
        ICERR_UNSUPPORTED equ -1
        ICERR_BADFORMAT equ -2
        ICERR_MEMORY equ -3
        ICERR_INTERNAL equ -4
        ICERR_BADFLAGS equ -5
        ICERR_BADPARAM equ -6
        ICERR_BADSIZE equ -7
        ICERR_BADHANDLE equ -8
        ICERR_CANTUPDATE equ -9
        ICERR_ABORT equ -10
        ICERR_ERROR equ -100
        ICERR_BADBITDEPTH equ -200
        ICERR_BADIMAGESIZE equ -201
        ICERR_CUSTOM equ -400
      endif
      ifndef ICMODE_COMPRESS
        ICMODE_COMPRESS equ 1
        ICMODE_DECOMPRESS equ 2
        ICMODE_FASTDECOMPRESS equ 3
        ICMODE_QUERY equ 4
        ICMODE_FASTCOMPRESS equ 5
        ICMODE_DRAW equ 8
      endif
      ifndef _WIN32
        ;[...]
      endif
      AVIIF_LIST equ 00000001h
      AVIIF_TWOCC equ 00000002h
      AVIIF_KEYFRAME equ 00000010h
      ICQUALITY_LOW equ 0
      ICQUALITY_HIGH equ 10000
      ICQUALITY_DEFAULT equ -1
      ICM_USER equ (DRV_USER + 0000h)
      ICM_RESERVED equ <ICM_RESERVED_LOW>
      ICM_RESERVED_LOW equ (DRV_USER + 1000h)
      ICM_RESERVED_HIGH equ (DRV_USER + 2000h)
      ICM_GETSTATE equ (ICM_RESERVED + 0)
      ICM_SETSTATE equ (ICM_RESERVED + 1)
      ICM_GETINFO equ (ICM_RESERVED + 2)
      ICM_CONFIGURE equ (ICM_RESERVED + 10)
      ICM_ABOUT equ (ICM_RESERVED + 11)
      ICM_GETERRORTEXT equ (ICM_RESERVED + 12)
      ICM_GETFORMATNAME equ (ICM_RESERVED + 20)
      ICM_ENUMFORMATS equ (ICM_RESERVED + 21)
      ICM_GETDEFAULTQUALITY equ (ICM_RESERVED + 30)
      ICM_GETQUALITY equ (ICM_RESERVED + 31)
      ICM_SETQUALITY equ (ICM_RESERVED + 32)
      ICM_SET equ (ICM_RESERVED + 40)
      ICM_GET equ (ICM_RESERVED + 41)
      ICM_FRAMERATE equ <mmioFOURCC('F', 'r', 'm', 'R')>
      ICM_KEYFRAMERATE equ <mmioFOURCC('K', 'e', 'y', 'R')>
      ICM_COMPRESS_GET_FORMAT equ (ICM_USER + 4)
      ICM_COMPRESS_GET_SIZE equ (ICM_USER + 5)
      ICM_COMPRESS_QUERY equ (ICM_USER + 6)
      ICM_COMPRESS_BEGIN equ (ICM_USER + 7)
      ICM_COMPRESS equ (ICM_USER + 8)
      ICM_COMPRESS_END equ (ICM_USER + 9)
      ICM_DECOMPRESS_GET_FORMAT equ (ICM_USER + 10)
      ICM_DECOMPRESS_QUERY equ (ICM_USER + 11)
      ICM_DECOMPRESS_BEGIN equ (ICM_USER + 12)
      ICM_DECOMPRESS equ (ICM_USER + 13)
      ICM_DECOMPRESS_END equ (ICM_USER + 14)
      ICM_DECOMPRESS_SET_PALETTE equ (ICM_USER + 29)
      ICM_DECOMPRESS_GET_PALETTE equ (ICM_USER + 30)
      ICM_DRAW_QUERY equ (ICM_USER + 31)
      ICM_DRAW_BEGIN equ (ICM_USER + 15)
      ICM_DRAW_GET_PALETTE equ (ICM_USER + 16)
      ICM_DRAW_UPDATE equ (ICM_USER + 17)
      ICM_DRAW_START equ (ICM_USER + 18)
      ICM_DRAW_STOP equ (ICM_USER + 19)
      ICM_DRAW_BITS equ (ICM_USER + 20)
      ICM_DRAW_END equ (ICM_USER + 21)
      ICM_DRAW_GETTIME equ (ICM_USER + 32)
      ICM_DRAW equ (ICM_USER + 33)
      ICM_DRAW_WINDOW equ (ICM_USER + 34)
      ICM_DRAW_SETTIME equ (ICM_USER + 35)
      ICM_DRAW_REALIZE equ (ICM_USER + 36)
      ICM_DRAW_FLUSH equ (ICM_USER + 37)
      ICM_DRAW_RENDERBUFFER equ (ICM_USER + 38)
      ICM_DRAW_START_PLAY equ (ICM_USER + 39)
      ICM_DRAW_STOP_PLAY equ (ICM_USER + 40)
      ICM_DRAW_SUGGESTFORMAT equ (ICM_USER + 50)
      ICM_DRAW_CHANGEPALETTE equ (ICM_USER + 51)
      ICM_DRAW_IDLE equ (ICM_USER + 52)
      ICM_GETBUFFERSWANTED equ (ICM_USER + 41)
      ICM_GETDEFAULTKEYFRAMERATE equ (ICM_USER + 42)
      ICM_DECOMPRESSEX_BEGIN equ (ICM_USER + 60)
      ICM_DECOMPRESSEX_QUERY equ (ICM_USER + 61)
      ICM_DECOMPRESSEX equ (ICM_USER + 62)
      ICM_DECOMPRESSEX_END equ (ICM_USER + 63)
      ICM_COMPRESS_FRAMES_INFO equ (ICM_USER + 70)
      ICM_COMPRESS_FRAMES equ (ICM_USER + 71)
      ICM_SET_STATUS_PROC equ (ICM_USER + 72)
      ICOPEN struct
        dwSize DWORD ?
        fccType DWORD ?
        fccHandler DWORD ?
        dwVersion DWORD ?
        dwFlags DWORD ?
        dwError LRESULT ?
        pV1Reserved LPVOID ?
        pV2Reserved LPVOID ?
        dnDevNode DWORD ?
      ICOPEN ends
      ICINFO struct
        dwSize DWORD ?
        fccType DWORD ?
        fccHandler DWORD ?
        dwFlags DWORD ?
        dwVersion DWORD ?
        dwVersionICM DWORD ?
        szName WCHAR 16 dup (?)
        szDescription WCHAR 128 dup (?)
        szDriver WCHAR 128 dup (?)
      ICINFO ends
      VIDCF_QUALITY equ 0001h
      VIDCF_CRUNCH equ 0002h
      VIDCF_TEMPORAL equ 0004h
      VIDCF_COMPRESSFRAMES equ 0008h
      VIDCF_DRAW equ 0010h
      VIDCF_FASTTEMPORALC equ 0020h
      VIDCF_FASTTEMPORALD equ 0080h
      ICCOMPRESS_KEYFRAME equ 00000001h
      ICCOMPRESS struct
        dwFlags DWORD ?
        lpbiOutput LPBITMAPINFOHEADER ?
        lpOutput LPVOID ?
        lpbiInput LPBITMAPINFOHEADER ?
        lpInput LPVOID ?
        lpckid LPDWORD ?
        lpdwFlags LPDWORD ?
        lFrameNum LONG ?
        dwFrameSize DWORD ?
        dwQuality DWORD ?
        lpbiPrev LPBITMAPINFOHEADER ?
        lpPrev LPVOID ?
      ICCOMPRESS ends
      ICCOMPRESSFRAMES_PADDING equ 00000001h
      ICCOMPRESSFRAMES struct
        dwFlags DWORD ?
        lpbiOutput LPBITMAPINFOHEADER ?
        lOutput LPARAM ?
        lpbiInput LPBITMAPINFOHEADER ?
        lInput LPARAM ?
        lStartFrame LONG ?
        lFrameCount LONG ?
        lQuality LONG ?
        lDataRate LONG ?
        lKeyRate LONG ?
        dwRate DWORD ?
        dwScale DWORD ?
        dwOverheadPerFrame DWORD ?
        dwReserved2 DWORD ?
        TYPE_GetData typedef proto WIN_STD_CALL_CONV :LPARAM, :LONG, :LPVOID, :LONG
        GetData typedef ptr TYPE_GetData
        TYPE_PutData typedef proto WIN_STD_CALL_CONV :LPARAM, :LONG, :LPVOID, :LONG
        PutData typedef ptr TYPE_PutData
      ICCOMPRESSFRAMES ends
      ICSETSTATUSPROC struct
        dwFlags DWORD ?
        lParam LPARAM ?
        ICSTATUS_START equ 0
        ICSTATUS_STATUS equ 1
        ICSTATUS_END equ 2
        ICSTATUS_ERROR equ 3
        ICSTATUS_YIELD equ 4
        TYPE_Status typedef proto WIN_STD_CALL_CONV :LPARAM, :UINT, :LONG
        Status typedef ptr TYPE_Status
      ICSETSTATUSPROC ends
      ICDECOMPRESS_HURRYUP equ 80000000h
      ICDECOMPRESS_UPDATE equ 40000000h
      ICDECOMPRESS_PREROLL equ 20000000h
      ICDECOMPRESS_NULLFRAME equ 10000000h
      ICDECOMPRESS_NOTKEYFRAME equ 08000000h
      ICDECOMPRESS struct
        dwFlags DWORD ?
        lpbiInput LPBITMAPINFOHEADER ?
        lpInput LPVOID ?
        lpbiOutput LPBITMAPINFOHEADER ?
        lpOutput LPVOID ?
        ckid DWORD ?
      ICDECOMPRESS ends
      ICDECOMPRESSEX struct
        dwFlags DWORD ?
        lpbiSrc LPBITMAPINFOHEADER ?
        lpSrc LPVOID ?
        lpbiDst LPBITMAPINFOHEADER ?
        lpDst LPVOID ?
        xDst SDWORD ?
        yDst SDWORD ?
        dxDst SDWORD ?
        dyDst SDWORD ?
        xSrc SDWORD ?
        ySrc SDWORD ?
        dxSrc SDWORD ?
        dySrc SDWORD ?
      ICDECOMPRESSEX ends
      ICDRAW_QUERY equ 00000001h
      ICDRAW_FULLSCREEN equ 00000002h
      ICDRAW_HDC equ 00000004h
      ICDRAW_ANIMATE equ 00000008h
      ICDRAW_CONTINUE equ 00000010h
      ICDRAW_MEMORYDC equ 00000020h
      ICDRAW_UPDATING equ 00000040h
      ICDRAW_RENDER equ 00000080h
      ICDRAW_BUFFER equ 00000100h
      ICDRAWBEGIN struct
        dwFlags DWORD ?
        hpal HPALETTE ?
        hwnd HWND ?
        hdc HDC ?
        xDst SDWORD ?
        yDst SDWORD ?
        dxDst SDWORD ?
        dyDst SDWORD ?
        lpbi LPBITMAPINFOHEADER ?
        xSrc SDWORD ?
        ySrc SDWORD ?
        dxSrc SDWORD ?
        dySrc SDWORD ?
        dwRate DWORD ?
        dwScale DWORD ?
      ICDRAWBEGIN ends
      ICDRAW_HURRYUP equ 80000000h
      ICDRAW_UPDATE equ 40000000h
      ICDRAW_PREROLL equ 20000000h
      ICDRAW_NULLFRAME equ 10000000h
      ICDRAW_NOTKEYFRAME equ 08000000h
      ICDRAW struct
        dwFlags DWORD ?
        lpFormat LPVOID ?
        lpData LPVOID ?
        cbData DWORD ?
        lTime LONG ?
      ICDRAW ends
      ICDRAWSUGGEST struct
        lpbiIn LPBITMAPINFOHEADER ?
        lpbiSuggest LPBITMAPINFOHEADER ?
        dxSrc SDWORD ?
        dySrc SDWORD ?
        dxDst SDWORD ?
        dyDst SDWORD ?
        hicDecompressor HIC ?
      ICDRAWSUGGEST ends
      ICPALETTE struct
        dwFlags DWORD ?
        iStart SDWORD ?
        iLen SDWORD ?
        lppe LPPALETTEENTRY ?
      ICPALETTE ends
      ICInfo proto WIN_STD_CALL_CONV :DWORD, :DWORD, :ptr ICINFO
      ICInstall proto WIN_STD_CALL_CONV :DWORD, :DWORD, :LPARAM, :LPSTR, :UINT
      ICRemove proto WIN_STD_CALL_CONV :DWORD, :DWORD, :UINT
      ICGetInfo proto WIN_STD_CALL_CONV :HIC, :ptr ICINFO, :DWORD
      ICOpen proto WIN_STD_CALL_CONV :DWORD, :DWORD, :UINT
      ICOpenFunction proto WIN_STD_CALL_CONV :DWORD, :DWORD, :UINT, :FARPROC
      ICClose proto WIN_STD_CALL_CONV :HIC
      ICSendMessage proto WIN_STD_CALL_CONV :HIC, :UINT, :DWORD_PTR, :DWORD_PTR
      ifndef _WIN32
        ;[...]
      endif
      ICINSTALL_UNICODE equ 8000h
      ICINSTALL_FUNCTION equ 0001h
      ICINSTALL_DRIVER equ 0002h
      ICINSTALL_HDRV equ 0004h
      ICINSTALL_DRIVERW equ 8002h
      ICMF_CONFIGURE_QUERY equ 00000001h
      ICMF_ABOUT_QUERY equ 00000001h
      ICQueryAbout macro hic
        exitm <(ICSendMessage (hic, ICM_ABOUT, - 1, ICMF_ABOUT_QUERY) == ICERR_OK)>
      endm
      ICAbout macro hic, hwnd
        exitm <ICSendMessage (hic, ICM_ABOUT, (hwnd), 0)>
      endm
      ICQueryConfigure macro hic
        exitm <(ICSendMessage (hic, ICM_CONFIGURE, - 1, ICMF_CONFIGURE_QUERY) == ICERR_OK)>
      endm
      ICConfigure macro hic, hwnd
        exitm <ICSendMessage (hic, ICM_CONFIGURE, (hwnd), 0)>
      endm
      ICGetState macro hic, pv, cb
        exitm <ICSendMessage (hic, ICM_GETSTATE, (pv), (cb))>
      endm
      ICSetState macro hic, pv, cb
        exitm <ICSendMessage (hic, ICM_SETSTATE, (pv), (cb))>
      endm
      ICGetStateSize macro hic
        exitm <ICGetState(hic, NULL, 0)>
      endm
      ICGetDefaultQuality macro hic
        exitm <(ICSendMessage (hic, ICM_GETDEFAULTQUALITY, and dwICValue, sizeof(DWORD)), dwICValue)>
      endm
      ICGetDefaultKeyFrameRate macro hic
        exitm <(ICSendMessage (hic, ICM_GETDEFAULTKEYFRAMERATE, and dwICValue, sizeof(DWORD)), dwICValue)>
      endm
      ICDrawWindow macro hic, prc
        exitm <ICSendMessage (hic, ICM_DRAW_WINDOW, (prc), sizeof(RECT))>
      endm
      ICCompress proto c :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :LPBITMAPINFOHEADER, :LPVOID, :LPDWORD, :LPDWORD, :LONG, :DWORD, :DWORD, :LPBITMAPINFOHEADER, :LPVOID
      ICCompressBegin macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_BEGIN, (lpbiInput), (lpbiOutput))>
      endm
      ICCompressQuery macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_QUERY, (lpbiInput), (lpbiOutput))>
      endm
      ICCompressGetFormat macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_GET_FORMAT, (lpbiInput), (lpbiOutput))>
      endm
      ICCompressGetFormatSize macro hic, lpbi
        exitm <ICCompressGetFormat(hic, lpbi, NULL)>
      endm
      ICCompressGetSize macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_GET_SIZE, (lpbiInput), (lpbiOutput))>
      endm
      ICCompressEnd macro hic
        exitm <ICSendMessage (hic, ICM_COMPRESS_END, 0, 0)>
      endm
      ICDECOMPRESS_HURRYUP equ 80000000h
      ICDecompress proto c :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :LPBITMAPINFOHEADER, :LPVOID
      ICDecompressBegin macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_BEGIN, (lpbiInput), (lpbiOutput))>
      endm
      ICDecompressQuery macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_QUERY, (lpbiInput), (lpbiOutput))>
      endm
      ICDecompressGetFormat macro hic, lpbiInput, lpbiOutput
        exitm <(ICSendMessage (hic, ICM_DECOMPRESS_GET_FORMAT, (lpbiInput), (lpbiOutput)))>
      endm
      ICDecompressGetFormatSize macro hic, lpbi
        exitm <ICDecompressGetFormat(hic, lpbi, NULL)>
      endm
      ICDecompressGetPalette macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_GET_PALETTE, (lpbiInput), (lpbiOutput))>
      endm
      ICDecompressSetPalette macro hic, lpbiPalette
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_SET_PALETTE, (lpbiPalette), 0)>
      endm
      ICDecompressEnd macro hic
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_END, 0, 0)>
      endm
      ICDecompressEx proto WIN_STD_CALL_CONV :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      ICDecompressExBegin proto WIN_STD_CALL_CONV :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      ICDecompressExQuery proto WIN_STD_CALL_CONV :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      ICDecompressExEnd macro hic
        exitm <ICSendMessage (hic, ICM_DECOMPRESSEX_END, 0, 0)>
      endm
      ICDRAW_QUERY equ 00000001h
      ICDRAW_FULLSCREEN equ 00000002h
      ICDRAW_HDC equ 00000004h
      ICDrawBegin proto c :HIC, :DWORD, :HPALETTE, :HWND, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD, :DWORD
      ICDRAW_HURRYUP equ 80000000h
      ICDRAW_UPDATE equ 40000000h
      ICDraw proto c :HIC, :DWORD, :LPVOID, :LPVOID, :DWORD, :LONG
      ICDrawSuggestFormat proto WIN_STD_CALL_CONV :HIC, :LPBITMAPINFOHEADER, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HIC
      ICDrawQuery macro hic, lpbiInput
        exitm <ICSendMessage (hic, ICM_DRAW_QUERY, (lpbiInput), 0)>
      endm
      ICDrawChangePalette macro hic, lpbiInput
        exitm <ICSendMessage (hic, ICM_DRAW_CHANGEPALETTE, (lpbiInput), 0)>
      endm
      ICGetBuffersWanted macro hic, lpdwBuffers
        exitm <ICSendMessage (hic, ICM_GETBUFFERSWANTED, (lpdwBuffers), 0)>
      endm
      ICDrawEnd macro hic
        exitm <ICSendMessage (hic, ICM_DRAW_END, 0, 0)>
      endm
      ICDrawStart macro hic
        exitm <ICSendMessage (hic, ICM_DRAW_START, 0, 0)>
      endm
      ICDrawStartPlay macro hic, lFrom, lTo
        exitm <ICSendMessage (hic, ICM_DRAW_START_PLAY, (lFrom), (lTo))>
      endm
      ICDrawStop macro hic
        exitm <ICSendMessage (hic, ICM_DRAW_STOP, 0, 0)>
      endm
      ICDrawStopPlay macro hic
        exitm <ICSendMessage (hic, ICM_DRAW_STOP_PLAY, 0, 0)>
      endm
      ICDrawGetTime macro hic, lplTime
        exitm <ICSendMessage (hic, ICM_DRAW_GETTIME, (lplTime), 0)>
      endm
      ICDrawSetTime macro hic, lTime
        exitm <ICSendMessage (hic, ICM_DRAW_SETTIME, lTime, 0)>
      endm
      ICDrawRealize macro hic, hdc, fBackground
        exitm <ICSendMessage (hic, ICM_DRAW_REALIZE, (HDC) (hdc), (fBackground))>
      endm
      ICDrawFlush macro hic
        exitm <ICSendMessage (hic, ICM_DRAW_FLUSH, 0, 0)>
      endm
      ICDrawRenderBuffer macro hic
        exitm <ICSendMessage (hic, ICM_DRAW_RENDERBUFFER, 0, 0)>
      endm
      ICSetStatusProc proto WIN_STD_CALL_CONV :HIC, :DWORD, :LRESULT, :ptr
      ICDecompressOpen macro fccType, fccHandler, lpbiIn, lpbiOut
        exitm <ICLocate (fccType, fccHandler, lpbiIn, lpbiOut, ICMODE_DECOMPRESS)>
      endm
      ICDrawOpen macro fccType, fccHandler, lpbiIn
        exitm <ICLocate (fccType, fccHandler, lpbiIn, NULL, ICMODE_DRAW)>
      endm
      ICLocate proto WIN_STD_CALL_CONV :DWORD, :DWORD, :LPBITMAPINFOHEADER, :LPBITMAPINFOHEADER, :WORD
      ICGetDisplayFormat proto WIN_STD_CALL_CONV :HIC, :LPBITMAPINFOHEADER, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :SDWORD
      ICImageCompress proto WIN_STD_CALL_CONV :HIC, :UINT, :LPBITMAPINFO, :LPVOID, :LPBITMAPINFO, :LONG, :ptr LONG
      ICImageDecompress proto WIN_STD_CALL_CONV :HIC, :UINT, :LPBITMAPINFO, :LPVOID, :LPBITMAPINFO
      COMPVARS struct
        cbSize LONG ?
        dwFlags DWORD ?
        hic HIC ?
        fccType DWORD ?
        fccHandler DWORD ?
        lpbiIn LPBITMAPINFO ?
        lpbiOut LPBITMAPINFO ?
        lpBitsOut LPVOID ?
        lpBitsPrev LPVOID ?
        lFrame LONG ?
        lKey LONG ?
        lDataRate LONG ?
        lQ LONG ?
        lKeyCount LONG ?
        lpState LPVOID ?
        cbState LONG ?
      COMPVARS ends
      PCOMPVARS typedef ptr COMPVARS
      
      ICMF_COMPVARS_VALID equ 00000001h
      ICCompressorChoose proto WIN_STD_CALL_CONV :HWND, :UINT, :LPVOID, :LPVOID, :PCOMPVARS, :LPSTR
      ICMF_CHOOSE_KEYFRAME equ 0001h
      ICMF_CHOOSE_DATARATE equ 0002h
      ICMF_CHOOSE_PREVIEW equ 0004h
      ICMF_CHOOSE_ALLCOMPRESSORS equ 0008h
      ICSeqCompressFrameStart proto WIN_STD_CALL_CONV :PCOMPVARS, :LPBITMAPINFO
      ICSeqCompressFrameEnd proto WIN_STD_CALL_CONV :PCOMPVARS
      ICSeqCompressFrame proto WIN_STD_CALL_CONV :PCOMPVARS, :UINT, :LPVOID, :ptr BOOL, :ptr LONG
      ICCompressorFree proto WIN_STD_CALL_CONV :PCOMPVARS
    endif
    ifndef NODRAWDIB
      HDRAWDIB typedef HANDLE
      DDF_0001 equ 0001h
      DDF_UPDATE equ 0002h
      DDF_SAME_HDC equ 0004h
      DDF_SAME_DRAW equ 0008h
      DDF_DONTDRAW equ 0010h
      DDF_ANIMATE equ 0020h
      DDF_BUFFER equ 0040h
      DDF_JUSTDRAWIT equ 0080h
      DDF_FULLSCREEN equ 0100h
      DDF_BACKGROUNDPAL equ 0200h
      DDF_NOTKEYFRAME equ 0400h
      DDF_HURRYUP equ 0800h
      DDF_HALFTONE equ 1000h
      DDF_2000 equ 2000h
      DDF_PREROLL equ <DDF_DONTDRAW>
      DDF_SAME_DIB equ <DDF_SAME_DRAW>
      DDF_SAME_SIZE equ <DDF_SAME_DRAW>
      DrawDibInit proto WIN_STD_CALL_CONV
      DrawDibOpen proto WIN_STD_CALL_CONV
      DrawDibClose proto WIN_STD_CALL_CONV :HDRAWDIB
      DrawDibGetBuffer proto WIN_STD_CALL_CONV :HDRAWDIB, :LPBITMAPINFOHEADER, :DWORD, :DWORD
      DrawDibError proto WIN_STD_CALL_CONV :HDRAWDIB
      DrawDibGetPalette proto WIN_STD_CALL_CONV :HDRAWDIB
      DrawDibSetPalette proto WIN_STD_CALL_CONV :HDRAWDIB, :HPALETTE
      DrawDibChangePalette proto WIN_STD_CALL_CONV :HDRAWDIB, :SDWORD, :SDWORD, :LPPALETTEENTRY
      DrawDibRealize proto WIN_STD_CALL_CONV :HDRAWDIB, :HDC, :BOOL
      DrawDibStart proto WIN_STD_CALL_CONV :HDRAWDIB, :DWORD
      DrawDibStop proto WIN_STD_CALL_CONV :HDRAWDIB
      DrawDibBegin proto WIN_STD_CALL_CONV :HDRAWDIB, :HDC, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :UINT
      DrawDibDraw proto WIN_STD_CALL_CONV :HDRAWDIB, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT
      DrawDibUpdate macro hdd, hdc, x, y
        exitm <DrawDibDraw (hdd, hdc, x, y, 0, 0, NULL, NULL, 0, 0, 0, 0, DDF_UPDATE)>
      endm
      DrawDibEnd proto WIN_STD_CALL_CONV :HDRAWDIB
      DRAWDIBTIME struct
        timeCount LONG ?
        timeDraw LONG ?
        timeDecompress LONG ?
        timeDither LONG ?
        timeStretch LONG ?
        timeBlt LONG ?
        timeSetDIBits LONG ?
      DRAWDIBTIME ends
      LPDRAWDIBTIME typedef ptr DRAWDIBTIME
      
      DrawDibTime proto WIN_STD_CALL_CONV :HDRAWDIB, :LPDRAWDIBTIME
      PD_CAN_DRAW_DIB equ 0001h
      PD_CAN_STRETCHDIB equ 0002h
      PD_STRETCHDIB_1_1_OK equ 0004h
      PD_STRETCHDIB_1_2_OK equ 0008h
      PD_STRETCHDIB_1_N_OK equ 0010h
      DrawDibProfileDisplay proto WIN_STD_CALL_CONV :LPBITMAPINFOHEADER
      ifdef DRAWDIB_INCLUDE_STRETCHDIB
        StretchDIB proto WIN_STD_CALL_CONV :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      endif
    endif
    ifndef NOAVIFMT
      ifndef _INC_MMSYSTEM
        FOURCC typedef DWORD
      endif
      ifdef _MSC_VER
      endif
      ifndef mmioFOURCC
        mmioFOURCC macro ch0, ch1, ch2, ch3
          exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
        endm
      endif
      ifndef aviTWOCC
        aviTWOCC macro ch0, ch1
          exitm <((ch0) or ((ch1) shl 8))>
        endm
      endif
      TWOCC typedef WORD
      formtypeAVI equ <mmioFOURCC('A', 'V', 'I', ' ')>
      listtypeAVIHEADER equ <mmioFOURCC('h', 'd', 'r', 'l')>
      ckidAVIMAINHDR equ <mmioFOURCC('a', 'v', 'i', 'h')>
      listtypeSTREAMHEADER equ <mmioFOURCC('s', 't', 'r', 'l')>
      ckidSTREAMHEADER equ <mmioFOURCC('s', 't', 'r', 'h')>
      ckidSTREAMFORMAT equ <mmioFOURCC('s', 't', 'r', 'f')>
      ckidSTREAMHANDLERDATA equ <mmioFOURCC('s', 't', 'r', 'd')>
      ckidSTREAMNAME equ <mmioFOURCC('s', 't', 'r', 'n')>
      listtypeAVIMOVIE equ <mmioFOURCC('m', 'o', 'v', 'i')>
      listtypeAVIRECORD equ <mmioFOURCC('r', 'e', 'c', ' ')>
      ckidAVINEWINDEX equ <mmioFOURCC('i', 'd', 'x', '1')>
      streamtypeVIDEO equ <mmioFOURCC('v', 'i', 'd', 's')>
      streamtypeAUDIO equ <mmioFOURCC('a', 'u', 'd', 's')>
      streamtypeMIDI equ <mmioFOURCC('m', 'i', 'd', 's')>
      streamtypeTEXT equ <mmioFOURCC('t', 'x', 't', 's')>
      cktypeDIBbits equ <aviTWOCC('d', 'b')>
      cktypeDIBcompressed equ <aviTWOCC('d', 'c')>
      cktypePALchange equ <aviTWOCC('p', 'c')>
      cktypeWAVEbytes equ <aviTWOCC('w', 'b')>
      ckidAVIPADDING equ <mmioFOURCC('J', 'U', 'N', 'K')>
      FromHex macro n
        exitm <(((n) >= 'A') ? ((n) + 10 - 'A') : ((n) - '0'))>
      endm
      StreamFromFOURCC macro fcc
        exitm <(((FromHex(LOBYTE(LOWORD(fcc))) shl 4) + (FromHex(HIBYTE(LOWORD(fcc))))))>
      endm
      TWOCCFromFOURCC macro fcc
        exitm <HIWORD(fcc)>
      endm
      ToHex macro n
        exitm <((((n) > 9) ? ((n) - 10 + 'A') : ((n) + '0')))>
      endm
      MAKEAVICKID macro tcc, stream
        exitm <MAKELONG((ToHex((stream) and 0fh) shl 8) or (ToHex(((stream) and 0f0h) shr 4)), tcc)>
      endm
      AVIF_HASINDEX equ 00000010h
      AVIF_MUSTUSEINDEX equ 00000020h
      AVIF_ISINTERLEAVED equ 00000100h
      AVIF_WASCAPTUREFILE equ 00010000h
      AVIF_COPYRIGHTED equ 00020000h
      AVI_HEADERSIZE equ 2048
      MainAVIHeader struct
        dwMicroSecPerFrame DWORD ?
        dwMaxBytesPerSec DWORD ?
        dwPaddingGranularity DWORD ?
        dwFlags DWORD ?
        dwTotalFrames DWORD ?
        dwInitialFrames DWORD ?
        dwStreams DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwWidth DWORD ?
        dwHeight DWORD ?
        dwReserved DWORD 4 dup (?)
      MainAVIHeader ends
      AVISF_DISABLED equ 00000001h
      AVISF_VIDEO_PALCHANGES equ 00010000h
      AVIStreamHeader struct
        fccType FOURCC ?
        fccHandler FOURCC ?
        dwFlags DWORD ?
        wPriority WORD ?
        wLanguage WORD ?
        dwInitialFrames DWORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        dwStart DWORD ?
        dwLength DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwQuality DWORD ?
        dwSampleSize DWORD ?
        rcFrame RECT <>
      AVIStreamHeader ends
      AVIIF_LIST equ 00000001h
      AVIIF_KEYFRAME equ 00000010h
      AVIIF_FIRSTPART equ 00000020h
      AVIIF_LASTPART equ 00000040h
      AVIIF_MIDPART equ <(AVIIF_LASTPART or AVIIF_FIRSTPART)>
      AVIIF_NOTIME equ 00000100h
      AVIIF_COMPUSE equ 0FFF0000h
      AVIINDEXENTRY struct
        ckid DWORD ?
        dwFlags DWORD ?
        dwChunkOffset DWORD ?
        dwChunkLength DWORD ?
      AVIINDEXENTRY ends
      AVIPALCHANGE struct
        bFirstEntry BYTE ?
        bNumEntries BYTE ?
        wFlags WORD ?
        peNew PALETTEENTRY 0 dup (<>)
      AVIPALCHANGE ends
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef RC_INVOKED
      include pshpack8.inc
    endif
    ifndef NOMMREG
      include mmreg.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef NOAVIFILE
      ifndef mmioFOURCC
        mmioFOURCC macro ch0, ch1, ch2, ch3
          exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
        endm
      endif
      ifndef streamtypeVIDEO
        streamtypeVIDEO equ <mmioFOURCC('v', 'i', 'd', 's')>
        streamtypeAUDIO equ <mmioFOURCC('a', 'u', 'd', 's')>
        streamtypeMIDI equ <mmioFOURCC('m', 'i', 'd', 's')>
        streamtypeTEXT equ <mmioFOURCC('t', 'x', 't', 's')>
      endif
      ifndef AVIIF_KEYFRAME
        AVIIF_KEYFRAME equ 00000010h
      endif
      AVIGETFRAMEF_BESTDISPLAYFMT equ 1
      AVISTREAMINFOW struct
        fccType DWORD ?
        fccHandler DWORD ?
        dwFlags DWORD ?
        dwCaps DWORD ?
        wPriority WORD ?
        wLanguage WORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        dwStart DWORD ?
        dwLength DWORD ?
        dwInitialFrames DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwQuality DWORD ?
        dwSampleSize DWORD ?
        rcFrame RECT <>
        dwEditCount DWORD ?
        dwFormatChangeCount DWORD ?
        szName WCHAR 64 dup (?)
      AVISTREAMINFOW ends
      _AVISTREAMINFOW typedef AVISTREAMINFOW
      LPAVISTREAMINFOW typedef ptr AVISTREAMINFOW
      
      AVISTREAMINFOA struct
        fccType DWORD ?
        fccHandler DWORD ?
        dwFlags DWORD ?
        dwCaps DWORD ?
        wPriority WORD ?
        wLanguage WORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        dwStart DWORD ?
        dwLength DWORD ?
        dwInitialFrames DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwQuality DWORD ?
        dwSampleSize DWORD ?
        rcFrame RECT <>
        dwEditCount DWORD ?
        dwFormatChangeCount DWORD ?
        szName SBYTE 64 dup (?)
      AVISTREAMINFOA ends
      _AVISTREAMINFOA typedef AVISTREAMINFOA
      LPAVISTREAMINFOA typedef ptr AVISTREAMINFOA
      
      ifdef UNICODE
        AVISTREAMINFO equ <AVISTREAMINFOW>
        LPAVISTREAMINFO equ <LPAVISTREAMINFOW>
      else
        AVISTREAMINFO equ <AVISTREAMINFOA>
        LPAVISTREAMINFO equ <LPAVISTREAMINFOA>
      endif
      AVISTREAMINFO_DISABLED equ 00000001h
      AVISTREAMINFO_FORMATCHANGES equ 00010000h
      AVIFILEINFOW struct
        dwMaxBytesPerSec DWORD ?
        dwFlags DWORD ?
        dwCaps DWORD ?
        dwStreams DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwWidth DWORD ?
        dwHeight DWORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        dwLength DWORD ?
        dwEditCount DWORD ?
        szFileType WCHAR 64 dup (?)
      AVIFILEINFOW ends
      _AVIFILEINFOW typedef AVIFILEINFOW
      LPAVIFILEINFOW typedef ptr AVIFILEINFOW
      
      AVIFILEINFOA struct
        dwMaxBytesPerSec DWORD ?
        dwFlags DWORD ?
        dwCaps DWORD ?
        dwStreams DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwWidth DWORD ?
        dwHeight DWORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        dwLength DWORD ?
        dwEditCount DWORD ?
        szFileType SBYTE 64 dup (?)
      AVIFILEINFOA ends
      _AVIFILEINFOA typedef AVIFILEINFOA
      LPAVIFILEINFOA typedef ptr AVIFILEINFOA
      
      ifdef UNICODE
        AVIFILEINFO equ <AVIFILEINFOW>
        LPAVIFILEINFO equ <LPAVIFILEINFOW>
      else
        AVIFILEINFO equ <AVIFILEINFOA>
        LPAVIFILEINFO equ <LPAVIFILEINFOA>
      endif
      AVIFILEINFO_HASINDEX equ 00000010h
      AVIFILEINFO_MUSTUSEINDEX equ 00000020h
      AVIFILEINFO_ISINTERLEAVED equ 00000100h
      AVIFILEINFO_WASCAPTUREFILE equ 00010000h
      AVIFILEINFO_COPYRIGHTED equ 00020000h
      AVIFILECAPS_CANREAD equ 00000001h
      AVIFILECAPS_CANWRITE equ 00000002h
      AVIFILECAPS_ALLKEYFRAMES equ 00000010h
      AVIFILECAPS_NOCOMPRESSION equ 00000020h
      TYPE_AVISAVECALLBACK typedef proto WIN_STD_CALL_CONV :SDWORD
      AVISAVECALLBACK typedef ptr TYPE_AVISAVECALLBACK
      AVICOMPRESSOPTIONS struct
        fccType DWORD ?
        fccHandler DWORD ?
        dwKeyFrameEvery DWORD ?
        dwQuality DWORD ?
        dwBytesPerSecond DWORD ?
        dwFlags DWORD ?
        lpFormat LPVOID ?
        cbFormat DWORD ?
        lpParms LPVOID ?
        cbParms DWORD ?
        dwInterleaveEvery DWORD ?
      AVICOMPRESSOPTIONS ends
      LPAVICOMPRESSOPTIONS typedef ptr AVICOMPRESSOPTIONS
      
      AVICOMPRESSF_INTERLEAVE equ 00000001h
      AVICOMPRESSF_DATARATE equ 00000002h
      AVICOMPRESSF_KEYFRAMES equ 00000004h
      AVICOMPRESSF_VALID equ 00000008h
      ifdef __cplusplus
        ;[...]
      endif
      include ole2.inc
      ifdef __cplusplus
        ;[...]
      endif
      INTERFACE equ <IAVIStream>
      DECLARE_INTERFACE_ IAVIStream, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Create, :THIS_, :LPARAM
        STD_METHOD Info, :ptr THIS_, :LONG
        STD_METHOD FindSample, :THIS_, :LONG
        STD_METHOD ReadFormat, :THIS_, :LPVOID, :ptr LONG
        STD_METHOD SetFormat, :THIS_, :LPVOID, :LONG
        STD_METHOD Read, :THIS_, :LONG, :LPVOID, :LONG, :ptr LONG, :ptr LONG
        STD_METHOD Write, :THIS_, :LONG, :LPVOID, :LONG, :DWORD, :ptr LONG, :ptr LONG
        STD_METHOD Delete, :THIS_, :LONG
        STD_METHOD ReadData, :THIS_, :LPVOID, :ptr LONG
        STD_METHOD WriteData, :THIS_, :LPVOID, :LONG
        ifdef _WIN32
          STD_METHOD SetInfo, :ptr THIS_, :LONG
        else
          ;[...]
        endif
      END_DECLARE_INTERFACE_
      PAVISTREAM typedef ptr IAVIStream
      INTERFACE equ <IAVIStreaming>
      DECLARE_INTERFACE_ IAVIStreaming, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Begin, :THIS_, :LONG, :LONG
        STD_METHOD End_, :THIS_
      END_DECLARE_INTERFACE_
      PAVISTREAMING typedef ptr IAVIStreaming
      INTERFACE equ <IAVIEditStream>
      DECLARE_INTERFACE_ IAVIEditStream, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Cut, :ptr THIS_, :ptr LONG, :ptr PAVISTREAM
        STD_METHOD Copy, :ptr THIS_, :ptr LONG, :ptr PAVISTREAM
        STD_METHOD Paste, :ptr THIS_, :ptr LONG, :PAVISTREAM, :LONG, :LONG
        STD_METHOD Clone, :ptr THIS_
        STD_METHOD SetInfo, :ptr THIS_, :LONG
      END_DECLARE_INTERFACE_
      PAVIEDITSTREAM typedef ptr IAVIEditStream
      INTERFACE equ <IAVIPersistFile>
      DECLARE_INTERFACE_ IAVIPersistFile, IPersistFile
        STD_METHOD Reserved1, :THIS_
      END_DECLARE_INTERFACE_
      PAVIPERSISTFILE typedef ptr IAVIPersistFile
      INTERFACE equ <IAVIFile>
      PAVIFILE equ <IAVIFile ptr>
      DECLARE_INTERFACE_ IAVIFile, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Info, :ptr THIS_, :LONG
        STD_METHOD GetStream, :ptr THIS_, :DWORD, :LONG
        STD_METHOD CreateStream, :ptr THIS_, :ptr AVISTREAMINFOW
        STD_METHOD WriteData, :THIS_, :LPVOID, :LONG
        STD_METHOD ReadData, :THIS_, :LPVOID, :ptr LONG
        STD_METHOD EndRecord, :THIS_
        STD_METHOD DeleteStream, :THIS_, :LONG
      END_DECLARE_INTERFACE_
      PAVIFILE typedef ptr IAVIFile
      INTERFACE equ <IGetFrame>
      PGETFRAME equ <IGetFrame ptr>
      DECLARE_INTERFACE_ IGetFrame, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetFrame, :THIS_
        STD_METHOD Begin, :THIS_, :LONG, :LONG
        STD_METHOD End_, :THIS_
        STD_METHOD SetFormat, :THIS_, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      END_DECLARE_INTERFACE_
      PGETFRAME typedef ptr IGetFrame
      DEFINE_AVIGUID macro name_, l, w1, w2
        exitm <DEFINE_GUID(name_, l, w1, w2, 0C0h, 0, 0, 0, 0, 0, 0, 46h)>
      endm
      DEFINE_AVIGUID(IID_IAVIFile, 00020020h, 0, 0)
      DEFINE_AVIGUID(IID_IAVIStream, 00020021h, 0, 0)
      DEFINE_AVIGUID(IID_IAVIStreaming, 00020022h, 0, 0)
      DEFINE_AVIGUID(IID_IGetFrame, 00020023h, 0, 0)
      DEFINE_AVIGUID(IID_IAVIEditStream, 00020024h, 0, 0)
      DEFINE_AVIGUID(IID_IAVIPersistFile, 00020025h, 0, 0)
      ifndef UNICODE
        DEFINE_AVIGUID(CLSID_AVISimpleUnMarshal, 00020009h, 0, 0)
      endif
      DEFINE_AVIGUID(CLSID_AVIFile, 00020000h, 0, 0)
      AVIFILEHANDLER_CANREAD equ 0001h
      AVIFILEHANDLER_CANWRITE equ 0002h
      AVIFILEHANDLER_CANACCEPTNONRGB equ 0004h
      @DefProto DllImport, AVIFileInit, WIN_STD_CALL_CONV, AVIFileInit, <>, 0
      @DefProto DllImport, AVIFileExit, WIN_STD_CALL_CONV, AVIFileExit, <>, 0
      @DefProto DllImport, AVIFileAddRef, WIN_STD_CALL_CONV, AVIFileAddRef, <:PAVIFILE>, 4
      @DefProto DllImport, AVIFileRelease, WIN_STD_CALL_CONV, AVIFileRelease, <:PAVIFILE>, 4
      ifdef _WIN32
        @DefProto DllImport, AVIFileOpenA, WIN_STD_CALL_CONV, AVIFileOpenA, <:ptr PAVIFILE, :LPCSTR, :UINT, :LPCLSID>, 16
        @DefProto DllImport, AVIFileOpenW, WIN_STD_CALL_CONV, AVIFileOpenW, <:ptr PAVIFILE, :LPCWSTR, :UINT, :LPCLSID>, 16
        ifdef UNICODE
          AVIFileOpen equ <AVIFileOpenW>
        else
          AVIFileOpen equ <AVIFileOpenA>
        endif
      else
        ;[...]
      endif
      ifdef _WIN32
        @DefProto DllImport, AVIFileInfoW, WIN_STD_CALL_CONV, AVIFileInfoW, <:PAVIFILE, :LPAVIFILEINFOW, :LONG>, 12
        @DefProto DllImport, AVIFileInfoA, WIN_STD_CALL_CONV, AVIFileInfoA, <:PAVIFILE, :LPAVIFILEINFOA, :LONG>, 12
        ifdef UNICODE
          AVIFileInfo equ <AVIFileInfoW>
        else
          AVIFileInfo equ <AVIFileInfoA>
        endif
      else
        ;[...]
      endif
      @DefProto DllImport, AVIFileGetStream, WIN_STD_CALL_CONV, AVIFileGetStream, <:PAVIFILE, :ptr PAVISTREAM, :DWORD, :LONG>, 16
      ifdef _WIN32
        @DefProto DllImport, AVIFileCreateStreamW, WIN_STD_CALL_CONV, AVIFileCreateStreamW, <:PAVIFILE, :ptr PAVISTREAM, :ptr AVISTREAMINFOW>, 12
        @DefProto DllImport, AVIFileCreateStreamA, WIN_STD_CALL_CONV, AVIFileCreateStreamA, <:PAVIFILE, :ptr PAVISTREAM, :ptr AVISTREAMINFOA>, 12
        ifdef UNICODE
          AVIFileCreateStream equ <AVIFileCreateStreamW>
        else
          AVIFileCreateStream equ <AVIFileCreateStreamA>
        endif
      else
        ;[...]
      endif
      @DefProto DllImport, AVIFileWriteData, WIN_STD_CALL_CONV, AVIFileWriteData, <:PAVIFILE, :DWORD, :LPVOID, :LONG>, 16
      @DefProto DllImport, AVIFileReadData, WIN_STD_CALL_CONV, AVIFileReadData, <:PAVIFILE, :DWORD, :LPVOID, :ptr LONG>, 16
      @DefProto DllImport, AVIFileEndRecord, WIN_STD_CALL_CONV, AVIFileEndRecord, <:PAVIFILE>, 4
      @DefProto DllImport, AVIStreamAddRef, WIN_STD_CALL_CONV, AVIStreamAddRef, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamRelease, WIN_STD_CALL_CONV, AVIStreamRelease, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamInfoW, WIN_STD_CALL_CONV, AVIStreamInfoW, <:PAVISTREAM, :LPAVISTREAMINFOW, :LONG>, 12
      @DefProto DllImport, AVIStreamInfoA, WIN_STD_CALL_CONV, AVIStreamInfoA, <:PAVISTREAM, :LPAVISTREAMINFOA, :LONG>, 12
      ifdef UNICODE
        AVIStreamInfo equ <AVIStreamInfoW>
      else
        AVIStreamInfo equ <AVIStreamInfoA>
      endif
      @DefProto DllImport, AVIStreamFindSample, WIN_STD_CALL_CONV, AVIStreamFindSample, <:PAVISTREAM, :LONG, :LONG>, 12
      @DefProto DllImport, AVIStreamReadFormat, WIN_STD_CALL_CONV, AVIStreamReadFormat, <:PAVISTREAM, :LONG, :LPVOID, :ptr LONG>, 16
      @DefProto DllImport, AVIStreamSetFormat, WIN_STD_CALL_CONV, AVIStreamSetFormat, <:PAVISTREAM, :LONG, :LPVOID, :LONG>, 16
      @DefProto DllImport, AVIStreamReadData, WIN_STD_CALL_CONV, AVIStreamReadData, <:PAVISTREAM, :DWORD, :LPVOID, :ptr LONG>, 16
      @DefProto DllImport, AVIStreamWriteData, WIN_STD_CALL_CONV, AVIStreamWriteData, <:PAVISTREAM, :DWORD, :LPVOID, :LONG>, 16
      @DefProto DllImport, AVIStreamRead, WIN_STD_CALL_CONV, AVIStreamRead, <:PAVISTREAM, :LONG, :LONG, :LPVOID, :LONG, :ptr LONG, :ptr LONG>, 28
      AVISTREAMREAD_CONVENIENT equ -1
      @DefProto DllImport, AVIStreamWrite, WIN_STD_CALL_CONV, AVIStreamWrite, <:PAVISTREAM, :LONG, :LONG, :LPVOID, :LONG, :DWORD, :ptr LONG, :ptr LONG>, 32
      @DefProto DllImport, AVIStreamStart, WIN_STD_CALL_CONV, AVIStreamStart, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamLength, WIN_STD_CALL_CONV, AVIStreamLength, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamTimeToSample, WIN_STD_CALL_CONV, AVIStreamTimeToSample, <:PAVISTREAM, :LONG>, 8
      @DefProto DllImport, AVIStreamSampleToTime, WIN_STD_CALL_CONV, AVIStreamSampleToTime, <:PAVISTREAM, :LONG>, 8
      @DefProto DllImport, AVIStreamBeginStreaming, WIN_STD_CALL_CONV, AVIStreamBeginStreaming, <:PAVISTREAM, :LONG, :LONG, :LONG>, 16
      @DefProto DllImport, AVIStreamEndStreaming, WIN_STD_CALL_CONV, AVIStreamEndStreaming, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamGetFrameOpen, WIN_STD_CALL_CONV, AVIStreamGetFrameOpen, <:PAVISTREAM, :LPBITMAPINFOHEADER>, 8
      @DefProto DllImport, AVIStreamGetFrame, WIN_STD_CALL_CONV, AVIStreamGetFrame, <:PGETFRAME, :LONG>, 8
      @DefProto DllImport, AVIStreamGetFrameClose, WIN_STD_CALL_CONV, AVIStreamGetFrameClose, <:PGETFRAME>, 4
      @DefProto DllImport, AVIStreamOpenFromFileA, WIN_STD_CALL_CONV, AVIStreamOpenFromFileA, <:ptr PAVISTREAM, :LPCSTR, :DWORD, :LONG, :UINT, :ptr CLSID>, 24
      @DefProto DllImport, AVIStreamOpenFromFileW, WIN_STD_CALL_CONV, AVIStreamOpenFromFileW, <:ptr PAVISTREAM, :LPCWSTR, :DWORD, :LONG, :UINT, :ptr CLSID>, 24
      ifdef UNICODE
        AVIStreamOpenFromFile equ <AVIStreamOpenFromFileW>
      else
        AVIStreamOpenFromFile equ <AVIStreamOpenFromFileA>
      endif
      @DefProto DllImport, AVIStreamCreate, WIN_STD_CALL_CONV, AVIStreamCreate, <:ptr PAVISTREAM, :LONG, :LONG, :ptr CLSID>, 16
      FIND_DIR equ 0000000Fh
      FIND_NEXT equ 00000001h
      FIND_PREV equ 00000004h
      FIND_FROM_START equ 00000008h
      FIND_TYPE equ 000000F0h
      FIND_KEY equ 00000010h
      FIND_ANY equ 00000020h
      FIND_FORMAT equ 00000040h
      FIND_RET equ 0000F000h
      FIND_POS equ 00000000h
      FIND_LENGTH equ 00001000h
      FIND_OFFSET equ 00002000h
      FIND_SIZE equ 00003000h
      FIND_INDEX equ 00004000h
      AVIStreamFindKeyFrame equ <AVIStreamFindSample>
      FindKeyFrame equ <FindSample>
      AVIStreamClose equ <AVIStreamRelease>
      AVIFileClose equ <AVIFileRelease>
      AVIStreamInit equ <AVIFileInit>
      AVIStreamExit equ <AVIFileExit>
      SEARCH_NEAREST equ <FIND_PREV>
      SEARCH_BACKWARD equ <FIND_PREV>
      SEARCH_FORWARD equ <FIND_NEXT>
      SEARCH_KEY equ <FIND_KEY>
      SEARCH_ANY equ <FIND_ANY>
      AVIStreamSampleToSample macro pavi1, pavi2, l
        exitm <AVIStreamTimeToSample (pavi1, AVIStreamSampleToTime (pavi2, l))>
      endm
      AVIStreamNextSample macro pavi, l
        exitm <AVIStreamFindSample (pavi, l + 1, FIND_NEXT or FIND_ANY)>
      endm
      AVIStreamPrevSample macro pavi, l
        exitm <AVIStreamFindSample (pavi, l - 1, FIND_PREV or FIND_ANY)>
      endm
      AVIStreamNearestSample macro pavi, l
        exitm <AVIStreamFindSample (pavi, l, FIND_PREV or FIND_ANY)>
      endm
      AVIStreamNextKeyFrame macro pavi, l
        exitm <AVIStreamFindSample (pavi, l + 1, FIND_NEXT or FIND_KEY)>
      endm
      AVIStreamPrevKeyFrame macro pavi, l
        exitm <AVIStreamFindSample (pavi, l - 1, FIND_PREV or FIND_KEY)>
      endm
      AVIStreamNearestKeyFrame macro pavi, l
        exitm <AVIStreamFindSample (pavi, l, FIND_PREV or FIND_KEY)>
      endm
      AVIStreamIsKeyFrame macro pavi, l
        exitm <(AVIStreamNearestKeyFrame(pavi, l) == l)>
      endm
      AVIStreamPrevSampleTime macro pavi, t
        exitm <AVIStreamSampleToTime (pavi, AVIStreamPrevSample(pavi, AVIStreamTimeToSample (pavi, t)))>
      endm
      AVIStreamNextSampleTime macro pavi, t
        exitm <AVIStreamSampleToTime (pavi, AVIStreamNextSample(pavi, AVIStreamTimeToSample (pavi, t)))>
      endm
      AVIStreamNearestSampleTime macro pavi, t
        exitm <AVIStreamSampleToTime (pavi, AVIStreamNearestSample(pavi, AVIStreamTimeToSample (pavi, t)))>
      endm
      AVIStreamNextKeyFrameTime macro pavi, t
        exitm <AVIStreamSampleToTime (pavi, AVIStreamNextKeyFrame(pavi, AVIStreamTimeToSample (pavi, t)))>
      endm
      AVIStreamPrevKeyFrameTime macro pavi, t
        exitm <AVIStreamSampleToTime (pavi, AVIStreamPrevKeyFrame(pavi, AVIStreamTimeToSample (pavi, t)))>
      endm
      AVIStreamNearestKeyFrameTime macro pavi, t
        exitm <AVIStreamSampleToTime (pavi, AVIStreamNearestKeyFrame(pavi, AVIStreamTimeToSample (pavi, t)))>
      endm
      AVIStreamStartTime macro pavi
        exitm <AVIStreamSampleToTime (pavi, AVIStreamStart (pavi))>
      endm
      AVIStreamLengthTime macro pavi
        exitm <AVIStreamSampleToTime (pavi, AVIStreamLength (pavi))>
      endm
      AVIStreamEnd macro pavi
        exitm <(AVIStreamStart (pavi) + AVIStreamLength (pavi))>
      endm
      AVIStreamEndTime macro pavi
        exitm <AVIStreamSampleToTime (pavi, AVIStreamEnd(pavi))>
      endm
      AVIStreamSampleSize macro pavi, lPos, plSize
        exitm <AVIStreamRead (pavi, lPos, 1, NULL, 0, plSize, NULL)>
      endm
      AVIStreamFormatSize macro pavi, lPos, plSize
        exitm <AVIStreamReadFormat (pavi, lPos, NULL, plSize)>
      endm
      AVIStreamDataSize macro pavi, fcc, plSize
        exitm <AVIStreamReadData (pavi, fcc, NULL, plSize)>
      endm
      ifndef comptypeDIB
        comptypeDIB equ <mmioFOURCC('D', 'I', 'B', ' ')>
      endif
      @DefProto DllImport, AVIMakeCompressedStream, WIN_STD_CALL_CONV, AVIMakeCompressedStream, <:ptr PAVISTREAM, :PAVISTREAM, :ptr AVICOMPRESSOPTIONS, :ptr CLSID>, 16
      AVISaveA proto c :LPCSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :PAVISTREAM, :LPAVICOMPRESSOPTIONS, :vararg
      @DefProto DllImport, AVISaveVA, WIN_STD_CALL_CONV, AVISaveVA, <:LPCSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :ptr PAVISTREAM, :ptr LPAVICOMPRESSOPTIONS>, 24
      AVISaveW proto c :LPCWSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :PAVISTREAM, :LPAVICOMPRESSOPTIONS, :vararg
      @DefProto DllImport, AVISaveVW, WIN_STD_CALL_CONV, AVISaveVW, <:LPCWSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :ptr PAVISTREAM, :ptr LPAVICOMPRESSOPTIONS>, 24
      ifdef UNICODE
        AVISave equ <AVISaveW>
        AVISaveV equ <AVISaveVW>
      else
        AVISave equ <AVISaveA>
        AVISaveV equ <AVISaveVA>
      endif
      @DefProto DllImport, AVISaveOptions, WIN_STD_CALL_CONV, AVISaveOptions, <:HWND, :UINT, :SDWORD, :ptr PAVISTREAM, :ptr LPAVICOMPRESSOPTIONS>, 20
      @DefProto DllImport, AVISaveOptionsFree, WIN_STD_CALL_CONV, AVISaveOptionsFree, <:SDWORD, :ptr LPAVICOMPRESSOPTIONS>, 8
      @DefProto DllImport, AVIBuildFilterW, WIN_STD_CALL_CONV, AVIBuildFilterW, <:LPWSTR, :LONG, :BOOL>, 12
      @DefProto DllImport, AVIBuildFilterA, WIN_STD_CALL_CONV, AVIBuildFilterA, <:LPSTR, :LONG, :BOOL>, 12
      ifdef UNICODE
        AVIBuildFilter equ <AVIBuildFilterW>
      else
        AVIBuildFilter equ <AVIBuildFilterA>
      endif
      @DefProto DllImport, AVIMakeFileFromStreams, WIN_STD_CALL_CONV, AVIMakeFileFromStreams, <:ptr PAVIFILE, :SDWORD, :ptr PAVISTREAM>, 12
      @DefProto DllImport, AVIMakeStreamFromClipboard, WIN_STD_CALL_CONV, AVIMakeStreamFromClipboard, <:UINT, :HANDLE, :ptr PAVISTREAM>, 12
      @DefProto DllImport, AVIPutFileOnClipboard, WIN_STD_CALL_CONV, AVIPutFileOnClipboard, <:PAVIFILE>, 4
      @DefProto DllImport, AVIGetFromClipboard, WIN_STD_CALL_CONV, AVIGetFromClipboard, <:ptr PAVIFILE>, 4
      @DefProto DllImport, AVIClearClipboard, WIN_STD_CALL_CONV, AVIClearClipboard, <>, 0
      @DefProto DllImport, CreateEditableStream, WIN_STD_CALL_CONV, CreateEditableStream, <:ptr PAVISTREAM, :PAVISTREAM>, 8
      @DefProto DllImport, EditStreamCut, WIN_STD_CALL_CONV, EditStreamCut, <:PAVISTREAM, :ptr LONG, :ptr LONG, :ptr PAVISTREAM>, 16
      @DefProto DllImport, EditStreamCopy, WIN_STD_CALL_CONV, EditStreamCopy, <:PAVISTREAM, :ptr LONG, :ptr LONG, :ptr PAVISTREAM>, 16
      @DefProto DllImport, EditStreamPaste, WIN_STD_CALL_CONV, EditStreamPaste, <:PAVISTREAM, :ptr LONG, :ptr LONG, :PAVISTREAM, :LONG, :LONG>, 24
      @DefProto DllImport, EditStreamClone, WIN_STD_CALL_CONV, EditStreamClone, <:PAVISTREAM, :ptr PAVISTREAM>, 8
      @DefProto DllImport, EditStreamSetNameA, WIN_STD_CALL_CONV, EditStreamSetNameA, <:PAVISTREAM, :LPCSTR>, 8
      @DefProto DllImport, EditStreamSetNameW, WIN_STD_CALL_CONV, EditStreamSetNameW, <:PAVISTREAM, :LPCWSTR>, 8
      @DefProto DllImport, EditStreamSetInfoW, WIN_STD_CALL_CONV, EditStreamSetInfoW, <:PAVISTREAM, :LPAVISTREAMINFOW, :LONG>, 12
      @DefProto DllImport, EditStreamSetInfoA, WIN_STD_CALL_CONV, EditStreamSetInfoA, <:PAVISTREAM, :LPAVISTREAMINFOA, :LONG>, 12
      ifdef UNICODE
        EditStreamSetInfo equ <EditStreamSetInfoW>
        EditStreamSetName equ <EditStreamSetNameW>
      else
        EditStreamSetInfo equ <EditStreamSetInfoA>
        EditStreamSetName equ <EditStreamSetNameA>
      endif
      ifndef AVIERR_OK
        AVIERR_OK equ 0
        MAKE_AVIERR macro error_
          exitm <MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 4000h + error_)>
        endm
        AVIERR_UNSUPPORTED equ MAKE_AVIERR(101)
        AVIERR_BADFORMAT equ MAKE_AVIERR(102)
        AVIERR_MEMORY equ MAKE_AVIERR(103)
        AVIERR_INTERNAL equ MAKE_AVIERR(104)
        AVIERR_BADFLAGS equ MAKE_AVIERR(105)
        AVIERR_BADPARAM equ MAKE_AVIERR(106)
        AVIERR_BADSIZE equ MAKE_AVIERR(107)
        AVIERR_BADHANDLE equ MAKE_AVIERR(108)
        AVIERR_FILEREAD equ MAKE_AVIERR(109)
        AVIERR_FILEWRITE equ MAKE_AVIERR(110)
        AVIERR_FILEOPEN equ MAKE_AVIERR(111)
        AVIERR_COMPRESSOR equ MAKE_AVIERR(112)
        AVIERR_NOCOMPRESSOR equ MAKE_AVIERR(113)
        AVIERR_READONLY equ MAKE_AVIERR(114)
        AVIERR_NODATA equ MAKE_AVIERR(115)
        AVIERR_BUFFERTOOSMALL equ MAKE_AVIERR(116)
        AVIERR_CANTCOMPRESS equ MAKE_AVIERR(117)
        AVIERR_USERABORT equ MAKE_AVIERR(198)
        AVIERR_ERROR equ MAKE_AVIERR(199)
      endif
    endif
    ifndef NOMCIWND
      ifdef __cplusplus
        ;[...]
      else
        MCIWndSM equ <SendMessage>
      endif
      MCIWND_WINDOW_CLASS equ <TEXT("MCIWndClass")>
      MCIWndCreateA proto c :HWND, :HINSTANCE, :DWORD, :LPCSTR
      MCIWndCreateW proto c :HWND, :HINSTANCE, :DWORD, :LPCWSTR
      ifdef UNICODE
        MCIWndCreate equ <MCIWndCreateW>
      else
        MCIWndCreate equ <MCIWndCreateA>
      endif
      MCIWndRegisterClass proto c
      MCIWNDOPENF_NEW equ 0001h
      MCIWNDF_NOAUTOSIZEWINDOW equ 0001h
      MCIWNDF_NOPLAYBAR equ 0002h
      MCIWNDF_NOAUTOSIZEMOVIE equ 0004h
      MCIWNDF_NOMENU equ 0008h
      MCIWNDF_SHOWNAME equ 0010h
      MCIWNDF_SHOWPOS equ 0020h
      MCIWNDF_SHOWMODE equ 0040h
      MCIWNDF_SHOWALL equ 0070h
      MCIWNDF_NOTIFYMODE equ 0100h
      MCIWNDF_NOTIFYPOS equ 0200h
      MCIWNDF_NOTIFYSIZE equ 0400h
      MCIWNDF_NOTIFYERROR equ 1000h
      MCIWNDF_NOTIFYALL equ 1F00h
      MCIWNDF_NOTIFYANSI equ 0080h
      MCIWNDF_NOTIFYMEDIAA equ 0880h
      MCIWNDF_NOTIFYMEDIAW equ 0800h
      ifdef UNICODE
        MCIWNDF_NOTIFYMEDIA equ <MCIWNDF_NOTIFYMEDIAW>
      else
        MCIWNDF_NOTIFYMEDIA equ <MCIWNDF_NOTIFYMEDIAA>
      endif
      MCIWNDF_RECORD equ 2000h
      MCIWNDF_NOERRORDLG equ 4000h
      MCIWNDF_NOOPEN equ 8000h
      MCIWndCanPlay macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_CAN_PLAY, 0, 0)>
      endm
      MCIWndCanRecord macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_CAN_RECORD, 0, 0)>
      endm
      MCIWndCanSave macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_CAN_SAVE, 0, 0)>
      endm
      MCIWndCanWindow macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_CAN_WINDOW, 0, 0)>
      endm
      MCIWndCanEject macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_CAN_EJECT, 0, 0)>
      endm
      MCIWndCanConfig macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_CAN_CONFIG, 0, 0)>
      endm
      MCIWndPaletteKick macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_PALETTEKICK, 0, 0)>
      endm
      MCIWndSave macro hwnd, szFile
        exitm <MCIWndSM (hwnd, MCI_SAVE, 0, (szFile))>
      endm
      MCIWndSaveDialog macro hwnd
        exitm <MCIWndSave(hwnd, - 1)>
      endm
      MCIWndNew macro hwnd, lp
        exitm <MCIWndSM (hwnd, MCIWNDM_NEW, 0, (lp))>
      endm
      MCIWndRecord macro hwnd
        exitm <MCIWndSM (hwnd, MCI_RECORD, 0, 0)>
      endm
      MCIWndOpen macro hwnd, sz, f
        exitm <MCIWndSM (hwnd, MCIWNDM_OPEN, (f), (sz))>
      endm
      MCIWndOpenDialog macro hwnd
        exitm <MCIWndOpen(hwnd, - 1, 0)>
      endm
      MCIWndClose macro hwnd
        exitm <MCIWndSM (hwnd, MCI_CLOSE, 0, 0)>
      endm
      MCIWndPlay macro hwnd
        exitm <MCIWndSM (hwnd, MCI_PLAY, 0, 0)>
      endm
      MCIWndStop macro hwnd
        exitm <MCIWndSM (hwnd, MCI_STOP, 0, 0)>
      endm
      MCIWndPause macro hwnd
        exitm <MCIWndSM (hwnd, MCI_PAUSE, 0, 0)>
      endm
      MCIWndResume macro hwnd
        exitm <MCIWndSM (hwnd, MCI_RESUME, 0, 0)>
      endm
      MCIWndSeek macro hwnd, lPos
        exitm <MCIWndSM (hwnd, MCI_SEEK, 0, (lPos))>
      endm
      MCIWndEject macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_EJECT, 0, 0)>
      endm
      MCIWndHome macro hwnd
        exitm <MCIWndSeek(hwnd, MCIWND_START)>
      endm
      MCIWndEnd macro hwnd
        exitm <MCIWndSeek(hwnd, MCIWND_END)>
      endm
      MCIWndGetSource macro hwnd, prc
        exitm <MCIWndSM (hwnd, MCIWNDM_GET_SOURCE, 0, (LPRECT) (prc))>
      endm
      MCIWndPutSource macro hwnd, prc
        exitm <MCIWndSM (hwnd, MCIWNDM_PUT_SOURCE, 0, (LPRECT) (prc))>
      endm
      MCIWndGetDest macro hwnd, prc
        exitm <MCIWndSM (hwnd, MCIWNDM_GET_DEST, 0, (LPRECT) (prc))>
      endm
      MCIWndPutDest macro hwnd, prc
        exitm <MCIWndSM (hwnd, MCIWNDM_PUT_DEST, 0, (LPRECT) (prc))>
      endm
      MCIWndPlayReverse macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_PLAYREVERSE, 0, 0)>
      endm
      MCIWndPlayFrom macro hwnd, lPos
        exitm <MCIWndSM (hwnd, MCIWNDM_PLAYFROM, 0, (lPos))>
      endm
      MCIWndPlayTo macro hwnd, lPos
        exitm <MCIWndSM (hwnd, MCIWNDM_PLAYTO, 0, (lPos))>
      endm
      MCIWndPlayFromTo macro hwnd, lStart, lEnd
        exitm <(MCIWndSeek(hwnd, lStart), MCIWndPlayTo(hwnd, lEnd))>
      endm
      MCIWndGetDeviceID macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETDEVICEID, 0, 0)>
      endm
      MCIWndGetAlias macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETALIAS, 0, 0)>
      endm
      MCIWndGetMode macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_GETMODE, (len), (LPTSTR) (lp))>
      endm
      MCIWndGetPosition macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETPOSITION, 0, 0)>
      endm
      MCIWndGetPositionString macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_GETPOSITION, (len), (LPTSTR) (lp))>
      endm
      MCIWndGetStart macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETSTART, 0, 0)>
      endm
      MCIWndGetLength macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETLENGTH, 0, 0)>
      endm
      MCIWndGetEnd macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETEND, 0, 0)>
      endm
      MCIWndStep macro hwnd, n
        exitm <MCIWndSM (hwnd, MCI_STEP, 0, (n))>
      endm
      MCIWndDestroy macro hwnd
        exitm <(VOID) MCIWndSM (hwnd, WM_CLOSE, 0, 0)>
      endm
      MCIWndSetZoom macro hwnd, iZoom
        exitm <(VOID) MCIWndSM (hwnd, MCIWNDM_SETZOOM, 0, (iZoom))>
      endm
      MCIWndGetZoom macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETZOOM, 0, 0)>
      endm
      MCIWndSetVolume macro hwnd, iVol
        exitm <MCIWndSM (hwnd, MCIWNDM_SETVOLUME, 0, (iVol))>
      endm
      MCIWndGetVolume macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETVOLUME, 0, 0)>
      endm
      MCIWndSetSpeed macro hwnd, iSpeed
        exitm <MCIWndSM (hwnd, MCIWNDM_SETSPEED, 0, (iSpeed))>
      endm
      MCIWndGetSpeed macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETSPEED, 0, 0)>
      endm
      MCIWndSetTimeFormat macro hwnd, lp
        exitm <MCIWndSM (hwnd, MCIWNDM_SETTIMEFORMAT, 0, (LPTSTR) (lp))>
      endm
      MCIWndGetTimeFormat macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_GETTIMEFORMAT, (len), (LPTSTR) (lp))>
      endm
      MCIWndValidateMedia macro hwnd
        exitm <(VOID) MCIWndSM (hwnd, MCIWNDM_VALIDATEMEDIA, 0, 0)>
      endm
      MCIWndSetRepeat macro hwnd, f
        exitm <MCIWndSM (hwnd, MCIWNDM_SETREPEAT, 0, (f))>
      endm
      MCIWndGetRepeat macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETREPEAT, 0, 0)>
      endm
      MCIWndUseFrames macro hwnd
        exitm <MCIWndSetTimeFormat(hwnd, TEXT("frames"))>
      endm
      MCIWndUseTime macro hwnd
        exitm <MCIWndSetTimeFormat(hwnd, TEXT("ms"))>
      endm
      MCIWndSetActiveTimer macro hwnd, active
        exitm <(VOID) MCIWndSM (hwnd, MCIWNDM_SETACTIVETIMER, (active), 0)>
      endm
      MCIWndSetInactiveTimer macro hwnd, inactive
        exitm <(VOID) MCIWndSM (hwnd, MCIWNDM_SETINACTIVETIMER, (inactive), 0)>
      endm
      MCIWndSetTimers macro hwnd, active, inactive
        exitm <(VOID) MCIWndSM (hwnd, MCIWNDM_SETTIMERS, (active), (inactive))>
      endm
      MCIWndGetActiveTimer macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETACTIVETIMER, 0, 0) ;>
      endm
      MCIWndGetInactiveTimer macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETINACTIVETIMER, 0, 0) ;>
      endm
      MCIWndRealize macro hwnd, fBkgnd
        exitm <MCIWndSM (hwnd, MCIWNDM_REALIZE, (fBkgnd), 0)>
      endm
      MCIWndSendString macro hwnd, sz
        exitm <MCIWndSM (hwnd, MCIWNDM_SENDSTRING, 0, (LPTSTR) (sz))>
      endm
      MCIWndReturnString macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_RETURNSTRING, (len), (lp))>
      endm
      MCIWndGetError macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_GETERROR, (len), (lp))>
      endm
      MCIWndGetPalette macro hwnd
        exitm <(HPALETTE) MCIWndSM (hwnd, MCIWNDM_GETPALETTE, 0, 0)>
      endm
      MCIWndSetPalette macro hwnd, hpal
        exitm <MCIWndSM (hwnd, MCIWNDM_SETPALETTE, (HPALETTE) (hpal), 0)>
      endm
      MCIWndGetFileName macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_GETFILENAME, (len), (lp))>
      endm
      MCIWndGetDevice macro hwnd, lp, len
        exitm <MCIWndSM (hwnd, MCIWNDM_GETDEVICE, (len), (lp))>
      endm
      MCIWndGetStyles macro hwnd
        exitm <MCIWndSM (hwnd, MCIWNDM_GETSTYLES, 0, 0)>
      endm
      MCIWndChangeStyles macro hwnd, mask_, value
        exitm <MCIWndSM (hwnd, MCIWNDM_CHANGESTYLES, (mask_), (value))>
      endm
      MCIWndOpenInterface macro hwnd, pUnk
        exitm <MCIWndSM (hwnd, MCIWNDM_OPENINTERFACE, 0, (LPUNKNOWN) (pUnk))>
      endm
      MCIWndSetOwner macro hwnd, hwndP
        exitm <MCIWndSM (hwnd, MCIWNDM_SETOWNER, (hwndP), 0)>
      endm
      MCIWNDM_GETDEVICEID equ (WM_USER + 100)
      MCIWNDM_GETSTART equ (WM_USER + 103)
      MCIWNDM_GETLENGTH equ (WM_USER + 104)
      MCIWNDM_GETEND equ (WM_USER + 105)
      MCIWNDM_EJECT equ (WM_USER + 107)
      MCIWNDM_SETZOOM equ (WM_USER + 108)
      MCIWNDM_GETZOOM equ (WM_USER + 109)
      MCIWNDM_SETVOLUME equ (WM_USER + 110)
      MCIWNDM_GETVOLUME equ (WM_USER + 111)
      MCIWNDM_SETSPEED equ (WM_USER + 112)
      MCIWNDM_GETSPEED equ (WM_USER + 113)
      MCIWNDM_SETREPEAT equ (WM_USER + 114)
      MCIWNDM_GETREPEAT equ (WM_USER + 115)
      MCIWNDM_REALIZE equ (WM_USER + 118)
      MCIWNDM_VALIDATEMEDIA equ (WM_USER + 121)
      MCIWNDM_PLAYFROM equ (WM_USER + 122)
      MCIWNDM_PLAYTO equ (WM_USER + 123)
      MCIWNDM_GETPALETTE equ (WM_USER + 126)
      MCIWNDM_SETPALETTE equ (WM_USER + 127)
      MCIWNDM_SETTIMERS equ (WM_USER + 129)
      MCIWNDM_SETACTIVETIMER equ (WM_USER + 130)
      MCIWNDM_SETINACTIVETIMER equ (WM_USER + 131)
      MCIWNDM_GETACTIVETIMER equ (WM_USER + 132)
      MCIWNDM_GETINACTIVETIMER equ (WM_USER + 133)
      MCIWNDM_CHANGESTYLES equ (WM_USER + 135)
      MCIWNDM_GETSTYLES equ (WM_USER + 136)
      MCIWNDM_GETALIAS equ (WM_USER + 137)
      MCIWNDM_PLAYREVERSE equ (WM_USER + 139)
      MCIWNDM_GET_SOURCE equ (WM_USER + 140)
      MCIWNDM_PUT_SOURCE equ (WM_USER + 141)
      MCIWNDM_GET_DEST equ (WM_USER + 142)
      MCIWNDM_PUT_DEST equ (WM_USER + 143)
      MCIWNDM_CAN_PLAY equ (WM_USER + 144)
      MCIWNDM_CAN_WINDOW equ (WM_USER + 145)
      MCIWNDM_CAN_RECORD equ (WM_USER + 146)
      MCIWNDM_CAN_SAVE equ (WM_USER + 147)
      MCIWNDM_CAN_EJECT equ (WM_USER + 148)
      MCIWNDM_CAN_CONFIG equ (WM_USER + 149)
      MCIWNDM_PALETTEKICK equ (WM_USER + 150)
      MCIWNDM_OPENINTERFACE equ (WM_USER + 151)
      MCIWNDM_SETOWNER equ (WM_USER + 152)
      MCIWNDM_SENDSTRINGA equ (WM_USER + 101)
      MCIWNDM_GETPOSITIONA equ (WM_USER + 102)
      MCIWNDM_GETMODEA equ (WM_USER + 106)
      MCIWNDM_SETTIMEFORMATA equ (WM_USER + 119)
      MCIWNDM_GETTIMEFORMATA equ (WM_USER + 120)
      MCIWNDM_GETFILENAMEA equ (WM_USER + 124)
      MCIWNDM_GETDEVICEA equ (WM_USER + 125)
      MCIWNDM_GETERRORA equ (WM_USER + 128)
      MCIWNDM_NEWA equ (WM_USER + 134)
      MCIWNDM_RETURNSTRINGA equ (WM_USER + 138)
      MCIWNDM_OPENA equ (WM_USER + 153)
      MCIWNDM_SENDSTRINGW equ (WM_USER + 201)
      MCIWNDM_GETPOSITIONW equ (WM_USER + 202)
      MCIWNDM_GETMODEW equ (WM_USER + 206)
      MCIWNDM_SETTIMEFORMATW equ (WM_USER + 219)
      MCIWNDM_GETTIMEFORMATW equ (WM_USER + 220)
      MCIWNDM_GETFILENAMEW equ (WM_USER + 224)
      MCIWNDM_GETDEVICEW equ (WM_USER + 225)
      MCIWNDM_GETERRORW equ (WM_USER + 228)
      MCIWNDM_NEWW equ (WM_USER + 234)
      MCIWNDM_RETURNSTRINGW equ (WM_USER + 238)
      MCIWNDM_OPENW equ (WM_USER + 252)
      ifdef UNICODE
        MCIWNDM_SENDSTRING equ <MCIWNDM_SENDSTRINGW>
        MCIWNDM_GETPOSITION equ <MCIWNDM_GETPOSITIONW>
        MCIWNDM_GETMODE equ <MCIWNDM_GETMODEW>
        MCIWNDM_SETTIMEFORMAT equ <MCIWNDM_SETTIMEFORMATW>
        MCIWNDM_GETTIMEFORMAT equ <MCIWNDM_GETTIMEFORMATW>
        MCIWNDM_GETFILENAME equ <MCIWNDM_GETFILENAMEW>
        MCIWNDM_GETDEVICE equ <MCIWNDM_GETDEVICEW>
        MCIWNDM_GETERROR equ <MCIWNDM_GETERRORW>
        MCIWNDM_NEW equ <MCIWNDM_NEWW>
        MCIWNDM_RETURNSTRING equ <MCIWNDM_RETURNSTRINGW>
        MCIWNDM_OPEN equ <MCIWNDM_OPENW>
      else
        MCIWNDM_SENDSTRING equ <MCIWNDM_SENDSTRINGA>
        MCIWNDM_GETPOSITION equ <MCIWNDM_GETPOSITIONA>
        MCIWNDM_GETMODE equ <MCIWNDM_GETMODEA>
        MCIWNDM_SETTIMEFORMAT equ <MCIWNDM_SETTIMEFORMATA>
        MCIWNDM_GETTIMEFORMAT equ <MCIWNDM_GETTIMEFORMATA>
        MCIWNDM_GETFILENAME equ <MCIWNDM_GETFILENAMEA>
        MCIWNDM_GETDEVICE equ <MCIWNDM_GETDEVICEA>
        MCIWNDM_GETERROR equ <MCIWNDM_GETERRORA>
        MCIWNDM_NEW equ <MCIWNDM_NEWA>
        MCIWNDM_RETURNSTRING equ <MCIWNDM_RETURNSTRINGA>
        MCIWNDM_OPEN equ <MCIWNDM_OPENA>
      endif
      MCIWNDM_NOTIFYMODE equ (WM_USER + 200)
      MCIWNDM_NOTIFYPOS equ (WM_USER + 201)
      MCIWNDM_NOTIFYSIZE equ (WM_USER + 202)
      MCIWNDM_NOTIFYMEDIA equ (WM_USER + 203)
      MCIWNDM_NOTIFYERROR equ (WM_USER + 205)
      MCIWND_START equ -1
      MCIWND_END equ -2
      ifndef MCI_PLAY
        ifndef _WIN32
          ;[...]
        endif
        MCI_CLOSE equ 0804h
        MCI_PLAY equ 0806h
        MCI_SEEK equ 0807h
        MCI_STOP equ 0808h
        MCI_PAUSE equ 0809h
        MCI_STEP equ 080Eh
        MCI_RECORD equ 080Fh
        MCI_SAVE equ 0813h
        MCI_CUT equ 0851h
        MCI_COPY equ 0852h
        MCI_PASTE equ 0853h
        MCI_RESUME equ 0855h
        MCI_DELETE equ 0856h
      endif
      ifndef MCI_MODE_NOT_READY
        MCI_MODE_NOT_READY equ 524
        MCI_MODE_STOP equ 525
        MCI_MODE_PLAY equ 526
        MCI_MODE_RECORD equ 527
        MCI_MODE_SEEK equ 528
        MCI_MODE_PAUSE equ 529
        MCI_MODE_OPEN equ 530
      endif
    endif
    if  not Defined(NOAVICAP) or  not Defined(NOVIDEO)
      ifndef _RCINVOKED
        DECLARE_HANDLE HVIDEO
        LPHVIDEO typedef ptr HVIDEO
      endif
      VideoForWindowsVersion proto WIN_STD_CALL_CONV
      DV_ERR_OK equ 0
      DV_ERR_BASE equ 1
      DV_ERR_NONSPECIFIC equ <(DV_ERR_BASE)>
      DV_ERR_BADFORMAT equ (DV_ERR_BASE + 1)
      DV_ERR_STILLPLAYING equ (DV_ERR_BASE + 2)
      DV_ERR_UNPREPARED equ (DV_ERR_BASE + 3)
      DV_ERR_SYNC equ (DV_ERR_BASE + 4)
      DV_ERR_TOOMANYCHANNELS equ (DV_ERR_BASE + 5)
      DV_ERR_NOTDETECTED equ (DV_ERR_BASE + 6)
      DV_ERR_BADINSTALL equ (DV_ERR_BASE + 7)
      DV_ERR_CREATEPALETTE equ (DV_ERR_BASE + 8)
      DV_ERR_SIZEFIELD equ (DV_ERR_BASE + 9)
      DV_ERR_PARAM1 equ (DV_ERR_BASE + 10)
      DV_ERR_PARAM2 equ (DV_ERR_BASE + 11)
      DV_ERR_CONFIG1 equ (DV_ERR_BASE + 12)
      DV_ERR_CONFIG2 equ (DV_ERR_BASE + 13)
      DV_ERR_FLAGS equ (DV_ERR_BASE + 14)
      DV_ERR_13 equ (DV_ERR_BASE + 15)
      DV_ERR_NOTSUPPORTED equ (DV_ERR_BASE + 16)
      DV_ERR_NOMEM equ (DV_ERR_BASE + 17)
      DV_ERR_ALLOCATED equ (DV_ERR_BASE + 18)
      DV_ERR_BADDEVICEID equ (DV_ERR_BASE + 19)
      DV_ERR_INVALHANDLE equ (DV_ERR_BASE + 20)
      DV_ERR_BADERRNUM equ (DV_ERR_BASE + 21)
      DV_ERR_NO_BUFFERS equ (DV_ERR_BASE + 22)
      DV_ERR_MEM_CONFLICT equ (DV_ERR_BASE + 23)
      DV_ERR_IO_CONFLICT equ (DV_ERR_BASE + 24)
      DV_ERR_DMA_CONFLICT equ (DV_ERR_BASE + 25)
      DV_ERR_INT_CONFLICT equ (DV_ERR_BASE + 26)
      DV_ERR_PROTECT_ONLY equ (DV_ERR_BASE + 27)
      DV_ERR_LASTERROR equ (DV_ERR_BASE + 27)
      DV_ERR_USER_MSG equ (DV_ERR_BASE + 1000)
      ifndef _RCINVOKED
        ifndef MM_DRVM_OPEN
          MM_DRVM_OPEN equ 3D0h
          MM_DRVM_CLOSE equ 3D1h
          MM_DRVM_DATA equ 3D2h
          MM_DRVM_ERROR equ 3D3h
        endif
        DV_VM_OPEN equ <MM_DRVM_OPEN>
        DV_VM_CLOSE equ <MM_DRVM_CLOSE>
        DV_VM_DATA equ <MM_DRVM_DATA>
        DV_VM_ERROR equ <MM_DRVM_ERROR>
        VIDEOHDR struct
          lpData LPBYTE ?
          dwBufferLength DWORD ?
          dwBytesUsed DWORD ?
          dwTimeCaptured DWORD ?
          dwUser DWORD_PTR ?
          dwFlags DWORD ?
          dwReserved DWORD_PTR 4 dup (?)
        VIDEOHDR ends
        videohdr_tag typedef VIDEOHDR
        PVIDEOHDR typedef ptr VIDEOHDR
        LPVIDEOHDR typedef ptr VIDEOHDR
        
        VHDR_DONE equ 00000001h
        VHDR_PREPARED equ 00000002h
        VHDR_INQUEUE equ 00000004h
        VHDR_KEYFRAME equ 00000008h
        VHDR_VALID equ 0000000Fh
        CHANNEL_CAPS struct
          dwFlags DWORD ?
          dwSrcRectXMod DWORD ?
          dwSrcRectYMod DWORD ?
          dwSrcRectWidthMod DWORD ?
          dwSrcRectHeightMod DWORD ?
          dwDstRectXMod DWORD ?
          dwDstRectYMod DWORD ?
          dwDstRectWidthMod DWORD ?
          dwDstRectHeightMod DWORD ?
        CHANNEL_CAPS ends
        channel_caps_tag typedef CHANNEL_CAPS
        PCHANNEL_CAPS typedef ptr CHANNEL_CAPS
        LPCHANNEL_CAPS typedef ptr CHANNEL_CAPS
        
        VCAPS_OVERLAY equ 00000001h
        VCAPS_SRC_CAN_CLIP equ 00000002h
        VCAPS_DST_CAN_CLIP equ 00000004h
        VCAPS_CAN_SCALE equ 00000008h
        VIDEO_EXTERNALIN equ 0001h
        VIDEO_EXTERNALOUT equ 0002h
        VIDEO_IN equ 0004h
        VIDEO_OUT equ 0008h
        VIDEO_DLG_QUERY equ 0010h
        VIDEO_CONFIGURE_QUERY equ 8000h
        VIDEO_CONFIGURE_SET equ 1000h
        VIDEO_CONFIGURE_GET equ 2000h
        VIDEO_CONFIGURE_QUERYSIZE equ 0001h
        VIDEO_CONFIGURE_CURRENT equ 0010h
        VIDEO_CONFIGURE_NOMINAL equ 0020h
        VIDEO_CONFIGURE_MIN equ 0040h
        VIDEO_CONFIGURE_MAX equ 0080h
        DVM_USER equ 4000h
        DVM_CONFIGURE_START equ 1000h
        DVM_CONFIGURE_END equ 1FFFh
        DVM_PALETTE equ (DVM_CONFIGURE_START + 1)
        DVM_FORMAT equ (DVM_CONFIGURE_START + 2)
        DVM_PALETTERGB555 equ (DVM_CONFIGURE_START + 3)
        DVM_SRC_RECT equ (DVM_CONFIGURE_START + 4)
        DVM_DST_RECT equ (DVM_CONFIGURE_START + 5)
      endif
    endif
    ifndef NOAVICAP
      ifdef __cplusplus
        ;[...]
      else
        AVICapSM macro hwnd, m, w, l
          exitm <((IsWindow (hwnd)) ? SendMessage (hwnd, m, w, l) : 0)>
        endm
      endif
      ifndef RC_INVOKED
        WM_CAP_START equ <WM_USER>
        WM_CAP_UNICODE_START equ WM_USER + 100
        WM_CAP_GET_CAPSTREAMPTR equ (WM_CAP_START + 1)
        WM_CAP_SET_CALLBACK_ERRORW equ (WM_CAP_UNICODE_START + 2)
        WM_CAP_SET_CALLBACK_STATUSW equ (WM_CAP_UNICODE_START + 3)
        WM_CAP_SET_CALLBACK_ERRORA equ (WM_CAP_START + 2)
        WM_CAP_SET_CALLBACK_STATUSA equ (WM_CAP_START + 3)
        ifdef UNICODE
          WM_CAP_SET_CALLBACK_ERROR equ <WM_CAP_SET_CALLBACK_ERRORW>
          WM_CAP_SET_CALLBACK_STATUS equ <WM_CAP_SET_CALLBACK_STATUSW>
        else
          WM_CAP_SET_CALLBACK_ERROR equ <WM_CAP_SET_CALLBACK_ERRORA>
          WM_CAP_SET_CALLBACK_STATUS equ <WM_CAP_SET_CALLBACK_STATUSA>
        endif
        WM_CAP_SET_CALLBACK_YIELD equ (WM_CAP_START + 4)
        WM_CAP_SET_CALLBACK_FRAME equ (WM_CAP_START + 5)
        WM_CAP_SET_CALLBACK_VIDEOSTREAM equ (WM_CAP_START + 6)
        WM_CAP_SET_CALLBACK_WAVESTREAM equ (WM_CAP_START + 7)
        WM_CAP_GET_USER_DATA equ (WM_CAP_START + 8)
        WM_CAP_SET_USER_DATA equ (WM_CAP_START + 9)
        WM_CAP_DRIVER_CONNECT equ (WM_CAP_START + 10)
        WM_CAP_DRIVER_DISCONNECT equ (WM_CAP_START + 11)
        WM_CAP_DRIVER_GET_NAMEA equ (WM_CAP_START + 12)
        WM_CAP_DRIVER_GET_VERSIONA equ (WM_CAP_START + 13)
        WM_CAP_DRIVER_GET_NAMEW equ (WM_CAP_UNICODE_START + 12)
        WM_CAP_DRIVER_GET_VERSIONW equ (WM_CAP_UNICODE_START + 13)
        ifdef UNICODE
          WM_CAP_DRIVER_GET_NAME equ <WM_CAP_DRIVER_GET_NAMEW>
          WM_CAP_DRIVER_GET_VERSION equ <WM_CAP_DRIVER_GET_VERSIONW>
        else
          WM_CAP_DRIVER_GET_NAME equ <WM_CAP_DRIVER_GET_NAMEA>
          WM_CAP_DRIVER_GET_VERSION equ <WM_CAP_DRIVER_GET_VERSIONA>
        endif
        WM_CAP_DRIVER_GET_CAPS equ (WM_CAP_START + 14)
        WM_CAP_FILE_SET_CAPTURE_FILEA equ (WM_CAP_START + 20)
        WM_CAP_FILE_GET_CAPTURE_FILEA equ (WM_CAP_START + 21)
        WM_CAP_FILE_SAVEASA equ (WM_CAP_START + 23)
        WM_CAP_FILE_SAVEDIBA equ (WM_CAP_START + 25)
        WM_CAP_FILE_SET_CAPTURE_FILEW equ (WM_CAP_UNICODE_START + 20)
        WM_CAP_FILE_GET_CAPTURE_FILEW equ (WM_CAP_UNICODE_START + 21)
        WM_CAP_FILE_SAVEASW equ (WM_CAP_UNICODE_START + 23)
        WM_CAP_FILE_SAVEDIBW equ (WM_CAP_UNICODE_START + 25)
        ifdef UNICODE
          WM_CAP_FILE_SET_CAPTURE_FILE equ <WM_CAP_FILE_SET_CAPTURE_FILEW>
          WM_CAP_FILE_GET_CAPTURE_FILE equ <WM_CAP_FILE_GET_CAPTURE_FILEW>
          WM_CAP_FILE_SAVEAS equ <WM_CAP_FILE_SAVEASW>
          WM_CAP_FILE_SAVEDIB equ <WM_CAP_FILE_SAVEDIBW>
        else
          WM_CAP_FILE_SET_CAPTURE_FILE equ <WM_CAP_FILE_SET_CAPTURE_FILEA>
          WM_CAP_FILE_GET_CAPTURE_FILE equ <WM_CAP_FILE_GET_CAPTURE_FILEA>
          WM_CAP_FILE_SAVEAS equ <WM_CAP_FILE_SAVEASA>
          WM_CAP_FILE_SAVEDIB equ <WM_CAP_FILE_SAVEDIBA>
        endif
        WM_CAP_FILE_ALLOCATE equ (WM_CAP_START + 22)
        WM_CAP_FILE_SET_INFOCHUNK equ (WM_CAP_START + 24)
        WM_CAP_EDIT_COPY equ (WM_CAP_START + 30)
        WM_CAP_SET_AUDIOFORMAT equ (WM_CAP_START + 35)
        WM_CAP_GET_AUDIOFORMAT equ (WM_CAP_START + 36)
        WM_CAP_DLG_VIDEOFORMAT equ (WM_CAP_START + 41)
        WM_CAP_DLG_VIDEOSOURCE equ (WM_CAP_START + 42)
        WM_CAP_DLG_VIDEODISPLAY equ (WM_CAP_START + 43)
        WM_CAP_GET_VIDEOFORMAT equ (WM_CAP_START + 44)
        WM_CAP_SET_VIDEOFORMAT equ (WM_CAP_START + 45)
        WM_CAP_DLG_VIDEOCOMPRESSION equ (WM_CAP_START + 46)
        WM_CAP_SET_PREVIEW equ (WM_CAP_START + 50)
        WM_CAP_SET_OVERLAY equ (WM_CAP_START + 51)
        WM_CAP_SET_PREVIEWRATE equ (WM_CAP_START + 52)
        WM_CAP_SET_SCALE equ (WM_CAP_START + 53)
        WM_CAP_GET_STATUS equ (WM_CAP_START + 54)
        WM_CAP_SET_SCROLL equ (WM_CAP_START + 55)
        WM_CAP_GRAB_FRAME equ (WM_CAP_START + 60)
        WM_CAP_GRAB_FRAME_NOSTOP equ (WM_CAP_START + 61)
        WM_CAP_SEQUENCE equ (WM_CAP_START + 62)
        WM_CAP_SEQUENCE_NOFILE equ (WM_CAP_START + 63)
        WM_CAP_SET_SEQUENCE_SETUP equ (WM_CAP_START + 64)
        WM_CAP_GET_SEQUENCE_SETUP equ (WM_CAP_START + 65)
        WM_CAP_SET_MCI_DEVICEA equ (WM_CAP_START + 66)
        WM_CAP_GET_MCI_DEVICEA equ (WM_CAP_START + 67)
        WM_CAP_SET_MCI_DEVICEW equ (WM_CAP_UNICODE_START + 66)
        WM_CAP_GET_MCI_DEVICEW equ (WM_CAP_UNICODE_START + 67)
        ifdef UNICODE
          WM_CAP_SET_MCI_DEVICE equ <WM_CAP_SET_MCI_DEVICEW>
          WM_CAP_GET_MCI_DEVICE equ <WM_CAP_GET_MCI_DEVICEW>
        else
          WM_CAP_SET_MCI_DEVICE equ <WM_CAP_SET_MCI_DEVICEA>
          WM_CAP_GET_MCI_DEVICE equ <WM_CAP_GET_MCI_DEVICEA>
        endif
        WM_CAP_STOP equ (WM_CAP_START + 68)
        WM_CAP_ABORT equ (WM_CAP_START + 69)
        WM_CAP_SINGLE_FRAME_OPEN equ (WM_CAP_START + 70)
        WM_CAP_SINGLE_FRAME_CLOSE equ (WM_CAP_START + 71)
        WM_CAP_SINGLE_FRAME equ (WM_CAP_START + 72)
        WM_CAP_PAL_OPENA equ (WM_CAP_START + 80)
        WM_CAP_PAL_SAVEA equ (WM_CAP_START + 81)
        WM_CAP_PAL_OPENW equ (WM_CAP_UNICODE_START + 80)
        WM_CAP_PAL_SAVEW equ (WM_CAP_UNICODE_START + 81)
        ifdef UNICODE
          WM_CAP_PAL_OPEN equ <WM_CAP_PAL_OPENW>
          WM_CAP_PAL_SAVE equ <WM_CAP_PAL_SAVEW>
        else
          WM_CAP_PAL_OPEN equ <WM_CAP_PAL_OPENA>
          WM_CAP_PAL_SAVE equ <WM_CAP_PAL_SAVEA>
        endif
        WM_CAP_PAL_PASTE equ (WM_CAP_START + 82)
        WM_CAP_PAL_AUTOCREATE equ (WM_CAP_START + 83)
        WM_CAP_PAL_MANUALCREATE equ (WM_CAP_START + 84)
        WM_CAP_SET_CALLBACK_CAPCONTROL equ (WM_CAP_START + 85)
        WM_CAP_UNICODE_END equ <WM_CAP_PAL_SAVEW>
        WM_CAP_END equ <WM_CAP_UNICODE_END>
        capSetCallbackOnError macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_ERROR, 0, (fpProc)))>
        endm
        capSetCallbackOnStatus macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_STATUS, 0, (fpProc)))>
        endm
        capSetCallbackOnYield macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_YIELD, 0, (fpProc)))>
        endm
        capSetCallbackOnFrame macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_FRAME, 0, (fpProc)))>
        endm
        capSetCallbackOnVideoStream macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, (fpProc)))>
        endm
        capSetCallbackOnWaveStream macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_WAVESTREAM, 0, (fpProc)))>
        endm
        capSetCallbackOnCapControl macro hwnd, fpProc
          exitm <(AVICapSM(hwnd, WM_CAP_SET_CALLBACK_CAPCONTROL, 0, (fpProc)))>
        endm
        capSetUserData macro hwnd, lUser
          exitm <(AVICapSM(hwnd, WM_CAP_SET_USER_DATA, 0, lUser))>
        endm
        capGetUserData macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))>
        endm
        capDriverConnect macro hwnd, i
          exitm <(AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (i), 0))>
        endm
        capDriverDisconnect macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, 0, 0))>
        endm
        capDriverGetName macro hwnd, szName, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (wSize), (LPTSTR) (szName)))>
        endm
        capDriverGetVersion macro hwnd, szVer, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (wSize), (LPTSTR) (szVer)))>
        endm
        capDriverGetCaps macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (wSize), (LPCAPDRIVERCAPS) (s)))>
        endm
        capFileSetCaptureFile macro hwnd, szName
          exitm <(AVICapSM(hwnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, (LPTSTR) (szName)))>
        endm
        capFileGetCaptureFile macro hwnd, szName, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (wSize), (LPTSTR) (szName)))>
        endm
        capFileAlloc macro hwnd, dwSize
          exitm <(AVICapSM(hwnd, WM_CAP_FILE_ALLOCATE, 0, (dwSize)))>
        endm
        capFileSaveAs macro hwnd, szName
          exitm <(AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPTSTR) (szName)))>
        endm
        capFileSetInfoChunk macro hwnd, lpInfoChunk
          exitm <(AVICapSM(hwnd, WM_CAP_FILE_SET_INFOCHUNK, 0, (LPCAPINFOCHUNK) (lpInfoChunk)))>
        endm
        capFileSaveDIB macro hwnd, szName
          exitm <(AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPTSTR) (szName)))>
        endm
        capEditCopy macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0))>
        endm
        capSetAudioFormat macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_SET_AUDIOFORMAT, (wSize), (LPWAVEFORMATEX) (s)))>
        endm
        capGetAudioFormat macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (wSize), (LPWAVEFORMATEX) (s)))>
        endm
        capGetAudioFormatSize macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, 0, 0))>
        endm
        capDlgVideoFormat macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0))>
        endm
        capDlgVideoSource macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0))>
        endm
        capDlgVideoDisplay macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0))>
        endm
        capDlgVideoCompression macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0))>
        endm
        capGetVideoFormat macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, (wSize), (s)))>
        endm
        capGetVideoFormatSize macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, 0, 0))>
        endm
        capSetVideoFormat macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_SET_VIDEOFORMAT, (wSize), (s)))>
        endm
        capPreview macro hwnd, f
          exitm <(AVICapSM(hwnd, WM_CAP_SET_PREVIEW, (f), 0))>
        endm
        capPreviewRate macro hwnd, wMS
          exitm <(AVICapSM(hwnd, WM_CAP_SET_PREVIEWRATE, (wMS), 0))>
        endm
        capOverlay macro hwnd, f
          exitm <(AVICapSM(hwnd, WM_CAP_SET_OVERLAY, (f), 0))>
        endm
        capPreviewScale macro hwnd, f
          exitm <(AVICapSM(hwnd, WM_CAP_SET_SCALE, f, 0))>
        endm
        capGetStatus macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_GET_STATUS, (wSize), (LPCAPSTATUS) (s)))>
        endm
        capSetScrollPos macro hwnd, lpP
          exitm <(AVICapSM(hwnd, WM_CAP_SET_SCROLL, 0, (LPPOINT) (lpP)))>
        endm
        capGrabFrame macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_GRAB_FRAME, 0, 0))>
        endm
        capGrabFrameNoStop macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, 0, 0))>
        endm
        capCaptureSequence macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_SEQUENCE, 0, 0))>
        endm
        capCaptureSequenceNoFile macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, 0, 0))>
        endm
        capCaptureStop macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_STOP, 0, 0))>
        endm
        capCaptureAbort macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_ABORT, 0, 0))>
        endm
        capCaptureSingleFrameOpen macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, 0, 0))>
        endm
        capCaptureSingleFrameClose macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_CLOSE, 0, 0))>
        endm
        capCaptureSingleFrame macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, 0, 0))>
        endm
        capCaptureGetSetup macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (wSize), (LPCAPTUREPARMS) (s)))>
        endm
        capCaptureSetSetup macro hwnd, s, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_SET_SEQUENCE_SETUP, (wSize), (LPCAPTUREPARMS) (s)))>
        endm
        capSetMCIDeviceName macro hwnd, szName
          exitm <(AVICapSM(hwnd, WM_CAP_SET_MCI_DEVICE, 0, (LPTSTR) (szName)))>
        endm
        capGetMCIDeviceName macro hwnd, szName, wSize
          exitm <(AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (wSize), (LPTSTR) (szName)))>
        endm
        capPaletteOpen macro hwnd, szName
          exitm <(AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPTSTR) (szName)))>
        endm
        capPaletteSave macro hwnd, szName
          exitm <(AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPTSTR) (szName)))>
        endm
        capPalettePaste macro hwnd
          exitm <(AVICapSM(hwnd, WM_CAP_PAL_PASTE, 0, 0))>
        endm
        capPaletteAuto macro hwnd, iFrames, iColors
          exitm <(AVICapSM(hwnd, WM_CAP_PAL_AUTOCREATE, (iFrames), (iColors)))>
        endm
        capPaletteManual macro hwnd, fGrab, iColors
          exitm <(AVICapSM(hwnd, WM_CAP_PAL_MANUALCREATE, (fGrab), (iColors)))>
        endm
        CAPDRIVERCAPS struct
          wDeviceIndex UINT ?
          fHasOverlay BOOL ?
          fHasDlgVideoSource BOOL ?
          fHasDlgVideoFormat BOOL ?
          fHasDlgVideoDisplay BOOL ?
          fCaptureInitialized BOOL ?
          fDriverSuppliesPalettes BOOL ?
          hVideoIn HANDLE ?
          hVideoOut HANDLE ?
          hVideoExtIn HANDLE ?
          hVideoExtOut HANDLE ?
        CAPDRIVERCAPS ends
        tagCapDriverCaps typedef CAPDRIVERCAPS
        PCAPDRIVERCAPS typedef ptr CAPDRIVERCAPS
        LPCAPDRIVERCAPS typedef ptr CAPDRIVERCAPS
        
        CAPSTATUS struct
          uiImageWidth UINT ?
          uiImageHeight UINT ?
          fLiveWindow BOOL ?
          fOverlayWindow BOOL ?
          fScale_ BOOL ?
          ptScroll POINT <>
          fUsingDefaultPalette BOOL ?
          fAudioHardware BOOL ?
          fCapFileExists BOOL ?
          dwCurrentVideoFrame DWORD ?
          dwCurrentVideoFramesDropped DWORD ?
          dwCurrentWaveSamples DWORD ?
          dwCurrentTimeElapsedMS DWORD ?
          hPalCurrent HPALETTE ?
          fCapturingNow BOOL ?
          dwReturn DWORD ?
          wNumVideoAllocated UINT ?
          wNumAudioAllocated UINT ?
        CAPSTATUS ends
        tagCapStatus typedef CAPSTATUS
        PCAPSTATUS typedef ptr CAPSTATUS
        LPCAPSTATUS typedef ptr CAPSTATUS
        
        CAPTUREPARMS struct
          dwRequestMicroSecPerFrame DWORD ?
          fMakeUserHitOKToCapture BOOL ?
          wPercentDropForError UINT ?
          fYield BOOL ?
          dwIndexSize DWORD ?
          wChunkGranularity UINT ?
          fUsingDOSMemory BOOL ?
          wNumVideoRequested UINT ?
          fCaptureAudio BOOL ?
          wNumAudioRequested UINT ?
          vKeyAbort UINT ?
          fAbortLeftMouse BOOL ?
          fAbortRightMouse BOOL ?
          fLimitEnabled BOOL ?
          wTimeLimit UINT ?
          fMCIControl BOOL ?
          fStepMCIDevice BOOL ?
          dwMCIStartTime DWORD ?
          dwMCIStopTime DWORD ?
          fStepCaptureAt2x BOOL ?
          wStepCaptureAverageFrames UINT ?
          dwAudioBufferSize DWORD ?
          fDisableWriteCache BOOL ?
          AVStreamMaster UINT ?
        CAPTUREPARMS ends
        tagCaptureParms typedef CAPTUREPARMS
        PCAPTUREPARMS typedef ptr CAPTUREPARMS
        LPCAPTUREPARMS typedef ptr CAPTUREPARMS
        
        AVSTREAMMASTER_AUDIO equ 0
        AVSTREAMMASTER_NONE equ 1
        CAPINFOCHUNK struct
          fccInfoID FOURCC ?
          lpData LPVOID ?
          cbData LONG ?
        CAPINFOCHUNK ends
        tagCapInfoChunk typedef CAPINFOCHUNK
        PCAPINFOCHUNK typedef ptr CAPINFOCHUNK
        LPCAPINFOCHUNK typedef ptr CAPINFOCHUNK
        
        TYPE_CAPYIELDCALLBACK typedef proto WIN_STD_CALL_CONV :HWND
        CAPYIELDCALLBACK typedef ptr TYPE_CAPYIELDCALLBACK
        TYPE_CAPSTATUSCALLBACKW typedef proto WIN_STD_CALL_CONV :HWND, :SDWORD, :LPCWSTR
        CAPSTATUSCALLBACKW typedef ptr TYPE_CAPSTATUSCALLBACKW
        TYPE_CAPERRORCALLBACKW typedef proto WIN_STD_CALL_CONV :HWND, :SDWORD, :LPCWSTR
        CAPERRORCALLBACKW typedef ptr TYPE_CAPERRORCALLBACKW
        TYPE_CAPSTATUSCALLBACKA typedef proto WIN_STD_CALL_CONV :HWND, :SDWORD, :LPCSTR
        CAPSTATUSCALLBACKA typedef ptr TYPE_CAPSTATUSCALLBACKA
        TYPE_CAPERRORCALLBACKA typedef proto WIN_STD_CALL_CONV :HWND, :SDWORD, :LPCSTR
        CAPERRORCALLBACKA typedef ptr TYPE_CAPERRORCALLBACKA
        ifdef UNICODE
          CAPSTATUSCALLBACK equ <CAPSTATUSCALLBACKW>
          CAPERRORCALLBACK equ <CAPERRORCALLBACKW>
        else
          CAPSTATUSCALLBACK equ <CAPSTATUSCALLBACKA>
          CAPERRORCALLBACK equ <CAPERRORCALLBACKA>
        endif
        TYPE_CAPVIDEOCALLBACK typedef proto WIN_STD_CALL_CONV :HWND, :LPVIDEOHDR
        CAPVIDEOCALLBACK typedef ptr TYPE_CAPVIDEOCALLBACK
        TYPE_CAPWAVECALLBACK typedef proto WIN_STD_CALL_CONV :HWND, :LPWAVEHDR
        CAPWAVECALLBACK typedef ptr TYPE_CAPWAVECALLBACK
        TYPE_CAPCONTROLCALLBACK typedef proto WIN_STD_CALL_CONV :HWND, :SDWORD
        CAPCONTROLCALLBACK typedef ptr TYPE_CAPCONTROLCALLBACK
        CONTROLCALLBACK_PREROLL equ 1
        CONTROLCALLBACK_CAPTURING equ 2
        capCreateCaptureWindowA proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :SDWORD
        capGetDriverDescriptionA proto WIN_STD_CALL_CONV :UINT, :LPSTR, :SDWORD, :LPSTR, :SDWORD
        capCreateCaptureWindowW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :SDWORD
        capGetDriverDescriptionW proto WIN_STD_CALL_CONV :UINT, :LPWSTR, :SDWORD, :LPWSTR, :SDWORD
        ifdef UNICODE
          capCreateCaptureWindow equ <capCreateCaptureWindowW>
          capGetDriverDescription equ <capGetDriverDescriptionW>
        else
          capCreateCaptureWindow equ <capCreateCaptureWindowA>
          capGetDriverDescription equ <capGetDriverDescriptionA>
        endif
      endif
      infotypeDIGITIZATION_TIME equ <mmioFOURCC('I', 'D', 'I', 'T')>
      infotypeSMPTE_TIME equ <mmioFOURCC('I', 'S', 'M', 'P')>
      IDS_CAP_BEGIN equ 300
      IDS_CAP_END equ 301
      IDS_CAP_INFO equ 401
      IDS_CAP_OUTOFMEM equ 402
      IDS_CAP_FILEEXISTS equ 403
      IDS_CAP_ERRORPALOPEN equ 404
      IDS_CAP_ERRORPALSAVE equ 405
      IDS_CAP_ERRORDIBSAVE equ 406
      IDS_CAP_DEFAVIEXT equ 407
      IDS_CAP_DEFPALEXT equ 408
      IDS_CAP_CANTOPEN equ 409
      IDS_CAP_SEQ_MSGSTART equ 410
      IDS_CAP_SEQ_MSGSTOP equ 411
      IDS_CAP_VIDEDITERR equ 412
      IDS_CAP_READONLYFILE equ 413
      IDS_CAP_WRITEERROR equ 414
      IDS_CAP_NODISKSPACE equ 415
      IDS_CAP_SETFILESIZE equ 416
      IDS_CAP_SAVEASPERCENT equ 417
      IDS_CAP_DRIVER_ERROR equ 418
      IDS_CAP_WAVE_OPEN_ERROR equ 419
      IDS_CAP_WAVE_ALLOC_ERROR equ 420
      IDS_CAP_WAVE_PREPARE_ERROR equ 421
      IDS_CAP_WAVE_ADD_ERROR equ 422
      IDS_CAP_WAVE_SIZE_ERROR equ 423
      IDS_CAP_VIDEO_OPEN_ERROR equ 424
      IDS_CAP_VIDEO_ALLOC_ERROR equ 425
      IDS_CAP_VIDEO_PREPARE_ERROR equ 426
      IDS_CAP_VIDEO_ADD_ERROR equ 427
      IDS_CAP_VIDEO_SIZE_ERROR equ 428
      IDS_CAP_FILE_OPEN_ERROR equ 429
      IDS_CAP_FILE_WRITE_ERROR equ 430
      IDS_CAP_RECORDING_ERROR equ 431
      IDS_CAP_RECORDING_ERROR2 equ 432
      IDS_CAP_AVI_INIT_ERROR equ 433
      IDS_CAP_NO_FRAME_CAP_ERROR equ 434
      IDS_CAP_NO_PALETTE_WARN equ 435
      IDS_CAP_MCI_CONTROL_ERROR equ 436
      IDS_CAP_MCI_CANT_STEP_ERROR equ 437
      IDS_CAP_NO_AUDIO_CAP_ERROR equ 438
      IDS_CAP_AVI_DRAWDIB_ERROR equ 439
      IDS_CAP_COMPRESSOR_ERROR equ 440
      IDS_CAP_AUDIO_DROP_ERROR equ 441
      IDS_CAP_AUDIO_DROP_COMPERROR equ 442
      IDS_CAP_STAT_LIVE_MODE equ 500
      IDS_CAP_STAT_OVERLAY_MODE equ 501
      IDS_CAP_STAT_CAP_INIT equ 502
      IDS_CAP_STAT_CAP_FINI equ 503
      IDS_CAP_STAT_PALETTE_BUILD equ 504
      IDS_CAP_STAT_OPTPAL_BUILD equ 505
      IDS_CAP_STAT_I_FRAMES equ 506
      IDS_CAP_STAT_L_FRAMES equ 507
      IDS_CAP_STAT_CAP_L_FRAMES equ 508
      IDS_CAP_STAT_CAP_AUDIO equ 509
      IDS_CAP_STAT_VIDEOCURRENT equ 510
      IDS_CAP_STAT_VIDEOAUDIO equ 511
      IDS_CAP_STAT_VIDEOONLY equ 512
      IDS_CAP_STAT_FRAMESDROPPED equ 513
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef NOMSACM
      include msacm.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifdef OFN_READONLY
      GetOpenFileNamePreviewA proto WIN_STD_CALL_CONV :LPOPENFILENAMEA
      GetSaveFileNamePreviewA proto WIN_STD_CALL_CONV :LPOPENFILENAMEA
      GetOpenFileNamePreviewW proto WIN_STD_CALL_CONV :LPOPENFILENAMEW
      GetSaveFileNamePreviewW proto WIN_STD_CALL_CONV :LPOPENFILENAMEW
      ifdef UNICODE
        GetOpenFileNamePreview equ <GetOpenFileNamePreviewW>
        GetSaveFileNamePreview equ <GetSaveFileNamePreviewW>
      else
        GetOpenFileNamePreview equ <GetOpenFileNamePreviewA>
        GetSaveFileNamePreview equ <GetSaveFileNamePreviewA>
      endif
    endif
    ifndef RC_INVOKED
      include poppack.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
 