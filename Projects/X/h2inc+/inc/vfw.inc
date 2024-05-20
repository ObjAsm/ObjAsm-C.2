;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\vfw.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 16/12/2023 11:06:46

;****************************************************************************
ifndef _INC_VFW
  _INC_VFW equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*
    ;*  types
    ;*
    ;***************************************************************************
    VFWAPI equ <WINAPI>
    VFWAPIV equ <WINAPIV>
    if (_WIN32_WINNT ge _WIN32_WINNT_WS03)
      VFWAPI_INLINE equ <WINAPI_INLINE>
    else
      VFWAPI_INLINE equ <WINAPI>
    endif
    ;****************************************************************************
    ;*
    ;*  VideoForWindowsVersion() - returns version of VfW
    ;*
    ;***************************************************************************
    VideoForWindowsVersion proto WIN_STD_CALL_CONV
    ;****************************************************************************
    ;*
    ;*  call these to start stop using VfW from your app.
    ;*
    ;***************************************************************************
    InitVFW proto WIN_STD_CALL_CONV
    TermVFW proto WIN_STD_CALL_CONV
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*
    ;*  do we need MMSYSTEM?
    ;*
    ;****************************************************************************
    if  not Defined(_INC_MMSYSTEM) and ( not Defined(NOVIDEO) or  not Defined(NOAVICAP))
      include mmsystem.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*                                                                          *
    ;*        Macros                                                            *
    ;*                                                                          *
    ;*  should we define this??                                                 *
    ;*                                                                          *
    ;****************************************************************************
    ifndef MKFOURCC
      MKFOURCC macro ch0, ch1, ch2, ch3
        exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
      endm
    endif
    if  not Defined(_INC_MMSYSTEM)
      mmioFOURCC equ <MKFOURCC>
    endif
    ;****************************************************************************
    ;*
    ;*  COMPMAN - Installable Compression Manager.
    ;*
    ;****************************************************************************
    ifndef NOCOMPMAN
      ICVERSION equ 0104h
      ;* Handle to a Installable Compressor *
      DECLARE_HANDLE HIC
      ; this code in biCompression means the DIB must be accesed via
      ; 48 bit pointers! using *ONLY* the selector given.
      BI_1632 equ 32333631h; '1632'

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
        ICERR_CUSTOM equ -400; errors less than ICERR_CUSTOM...

      endif
      ;* Values for dwFlags of ICOpen() *
      ifndef ICMODE_COMPRESS
        ICMODE_COMPRESS equ 1
        ICMODE_DECOMPRESS equ 2
        ICMODE_FASTDECOMPRESS equ 3
        ICMODE_QUERY equ 4
        ICMODE_FASTCOMPRESS equ 5
        ICMODE_DRAW equ 8
      endif
      ifndef _WIN32; ;Internal

        ;[...]
        ; ;Internal
        ; ;Internal
      endif
      ; ;Internal
      ;* Flags for AVI file index *
      AVIIF_LIST equ 00000001h
      AVIIF_TWOCC equ 00000002h
      AVIIF_KEYFRAME equ 00000010h
      ;* quality flags *
      ICQUALITY_LOW equ 0
      ICQUALITY_HIGH equ 10000
      ICQUALITY_DEFAULT equ -1
      ;************************************************************************
      ;************************************************************************
      ICM_USER equ (DRV_USER + 0000h)
      ICM_RESERVED equ <ICM_RESERVED_LOW>
      ICM_RESERVED_LOW equ (DRV_USER + 1000h)
      ICM_RESERVED_HIGH equ (DRV_USER + 2000h)
      ;************************************************************************
      ;messages.
      ;************************************************************************
      ICM_GETSTATE equ (ICM_RESERVED + 0); Get compressor state

      ICM_SETSTATE equ (ICM_RESERVED + 1); Set compressor state

      ICM_GETINFO equ (ICM_RESERVED + 2); Query info about the compressor

      ICM_CONFIGURE equ (ICM_RESERVED + 10); show the configure dialog

      ICM_ABOUT equ (ICM_RESERVED + 11); show the about box

      ICM_GETERRORTEXT equ (ICM_RESERVED + 12); get error text TBD ;Internal

      ICM_GETFORMATNAME equ (ICM_RESERVED + 20); get a name for a format ;Internal

      ICM_ENUMFORMATS equ (ICM_RESERVED + 21); cycle through formats ;Internal

      ICM_GETDEFAULTQUALITY equ (ICM_RESERVED + 30); get the default value for quality

      ICM_GETQUALITY equ (ICM_RESERVED + 31); get the current value for quality

      ICM_SETQUALITY equ (ICM_RESERVED + 32); set the default value for quality

      ICM_SET equ (ICM_RESERVED + 40); Tell the driver something

      ICM_GET equ (ICM_RESERVED + 41); Ask the driver something

      ; Constants for ICM_SET:
      ICM_FRAMERATE equ <mmioFOURCC('F', 'r', 'm', 'R')>
      ICM_KEYFRAMERATE equ <mmioFOURCC('K', 'e', 'y', 'R')>
      ;************************************************************************
      ;ICM specific messages.
      ;************************************************************************
      ICM_COMPRESS_GET_FORMAT equ (ICM_USER + 4); get compress format or size

      ICM_COMPRESS_GET_SIZE equ (ICM_USER + 5); get output size

      ICM_COMPRESS_QUERY equ (ICM_USER + 6); query support for compress

      ICM_COMPRESS_BEGIN equ (ICM_USER + 7); begin a series of compress calls.

      ICM_COMPRESS equ (ICM_USER + 8); compress a frame

      ICM_COMPRESS_END equ (ICM_USER + 9); end of a series of compress calls.

      ICM_DECOMPRESS_GET_FORMAT equ (ICM_USER + 10); get decompress format or size

      ICM_DECOMPRESS_QUERY equ (ICM_USER + 11); query support for dempress

      ICM_DECOMPRESS_BEGIN equ (ICM_USER + 12); start a series of decompress calls

      ICM_DECOMPRESS equ (ICM_USER + 13); decompress a frame

      ICM_DECOMPRESS_END equ (ICM_USER + 14); end a series of decompress calls

      ICM_DECOMPRESS_SET_PALETTE equ (ICM_USER + 29); fill in the DIB color table

      ICM_DECOMPRESS_GET_PALETTE equ (ICM_USER + 30); fill in the DIB color table

      ICM_DRAW_QUERY equ (ICM_USER + 31); query support for dempress

      ICM_DRAW_BEGIN equ (ICM_USER + 15); start a series of draw calls

      ICM_DRAW_GET_PALETTE equ (ICM_USER + 16); get the palette needed for drawing

      ICM_DRAW_UPDATE equ (ICM_USER + 17); update screen with current frame ;Internal

      ICM_DRAW_START equ (ICM_USER + 18); start decompress clock

      ICM_DRAW_STOP equ (ICM_USER + 19); stop decompress clock

      ICM_DRAW_BITS equ (ICM_USER + 20); decompress a frame to screen ;Internal

      ICM_DRAW_END equ (ICM_USER + 21); end a series of draw calls

      ICM_DRAW_GETTIME equ (ICM_USER + 32); get value of decompress clock

      ICM_DRAW equ (ICM_USER + 33); generalized "render" message

      ICM_DRAW_WINDOW equ (ICM_USER + 34); drawing window has moved or hidden

      ICM_DRAW_SETTIME equ (ICM_USER + 35); set correct value for decompress clock

      ICM_DRAW_REALIZE equ (ICM_USER + 36); realize palette for drawing

      ICM_DRAW_FLUSH equ (ICM_USER + 37); clear out buffered frames

      ICM_DRAW_RENDERBUFFER equ (ICM_USER + 38); draw undrawn things in queue

      ICM_DRAW_START_PLAY equ (ICM_USER + 39); start of a play

      ICM_DRAW_STOP_PLAY equ (ICM_USER + 40); end of a play

      ICM_DRAW_SUGGESTFORMAT equ (ICM_USER + 50); Like ICGetDisplayFormat

      ICM_DRAW_CHANGEPALETTE equ (ICM_USER + 51); for animating palette

      ICM_DRAW_IDLE equ (ICM_USER + 52); send each frame time ;Internal

      ICM_GETBUFFERSWANTED equ (ICM_USER + 41); ask about prebuffering

      ICM_GETDEFAULTKEYFRAMERATE equ (ICM_USER + 42); get the default value for key frames

      ICM_DECOMPRESSEX_BEGIN equ (ICM_USER + 60); start a series of decompress calls

      ICM_DECOMPRESSEX_QUERY equ (ICM_USER + 61); start a series of decompress calls

      ICM_DECOMPRESSEX equ (ICM_USER + 62); decompress a frame

      ICM_DECOMPRESSEX_END equ (ICM_USER + 63); end a series of decompress calls

      ICM_COMPRESS_FRAMES_INFO equ (ICM_USER + 70); tell about compress to come

      ICM_COMPRESS_FRAMES equ (ICM_USER + 71); compress a bunch of frames ;Internal

      ICM_SET_STATUS_PROC equ (ICM_USER + 72); set status callback

      ;************************************************************************
      ;************************************************************************
      ICOPEN struct
        dwSize DWORD ?
        ; sizeof(ICOPEN)
        fccType DWORD ?
        ; 'vidc'
        fccHandler DWORD ?
        dwVersion DWORD ?
        ; version of compman opening you
        dwFlags DWORD ?
        ; LOWORD is type specific
        dwError LRESULT ?
        ; error return.
        pV1Reserved POINTER ?
        ; Reserved
        pV2Reserved POINTER ?
        ; Reserved
        dnDevNode DWORD ?
        ; Devnode for PnP devices
      ICOPEN ends
      ;************************************************************************
      ;************************************************************************
      ICINFO struct
        dwSize DWORD ?
        ; sizeof(ICINFO)
        fccType DWORD ?
        ; compressor type     'vidc' 'audc'
        fccHandler DWORD ?
        ; compressor sub-type 'rle ' 'jpeg' 'pcm '
        dwFlags DWORD ?
        ; flags LOWORD is type specific
        dwVersion DWORD ?
        ; version of the driver
        dwVersionICM DWORD ?
        ; version of the ICM used
        ; under Win32, the driver always returns UNICODE strings.
        szName WORD 16 dup (?)
        ; short name
        szDescription WORD 128 dup (?)
        ; long name
        szDriver WORD 128 dup (?)
        ; driver that contains compressor
      ICINFO ends
      ;* Flags for the <dwFlags> field of the <ICINFO> structure. *
      VIDCF_QUALITY equ 0001h; supports quality

      VIDCF_CRUNCH equ 0002h; supports crunching to a frame size

      VIDCF_TEMPORAL equ 0004h; supports inter-frame compress

      VIDCF_COMPRESSFRAMES equ 0008h; wants the compress all frames message

      VIDCF_DRAW equ 0010h; supports drawing

      VIDCF_FASTTEMPORALC equ 0020h; does not need prev frame on compress

      VIDCF_FASTTEMPORALD equ 0080h; does not need prev frame on decompress

      ;#define VIDCF_QUALITYTIME    0x0040  // supports temporal quality
      ;#define VIDCF_FASTTEMPORAL   (VIDCF_FASTTEMPORALC|VIDCF_FASTTEMPORALD)
      ;************************************************************************
      ;************************************************************************
      ICCOMPRESS_KEYFRAME equ 00000001h
      ICCOMPRESS struct
        dwFlags DWORD ?
        ; flags
        lpbiOutput LPBITMAPINFOHEADER ?
        ; output format
        lpOutput POINTER ?
        ; output data
        lpbiInput LPBITMAPINFOHEADER ?
        ; format of frame to compress
        lpInput POINTER ?
        ; frame data to compress
        lpckid LPDWORD ?
        ; ckid for data in AVI file
        lpdwFlags LPDWORD ?
        ; flags in the AVI index.
        lFrameNum SDWORD ?
        ; frame number of seq.
        dwFrameSize DWORD ?
        ; reqested size in bytes. (if non zero)
        dwQuality DWORD ?
        ; quality
        ; these are new fields
        lpbiPrev LPBITMAPINFOHEADER ?
        ; format of previous frame
        lpPrev POINTER ?
        ; previous frame
      ICCOMPRESS ends
      ;************************************************************************
      ;************************************************************************
      ICCOMPRESSFRAMES_PADDING equ 00000001h
      ICCOMPRESSFRAMES struct
        dwFlags DWORD ?
        ; flags
        lpbiOutput LPBITMAPINFOHEADER ?
        ; output format
        lOutput LPARAM ?
        ; output identifier
        lpbiInput LPBITMAPINFOHEADER ?
        ; format of frame to compress
        lInput LPARAM ?
        ; input identifier
        lStartFrame SDWORD ?
        ; start frame
        lFrameCount SDWORD ?
        ; # of frames
        lQuality SDWORD ?
        ; quality
        lDataRate SDWORD ?
        ; data rate
        lKeyRate SDWORD ?
        ; key frame rate
        dwRate DWORD ?
        ; frame rate, as always
        dwScale DWORD ?
        dwOverheadPerFrame DWORD ?
        dwReserved2 DWORD ?
        TYPE_GetData typedef proto WIN_STD_CALL_CONV :LPARAM, :LONG, :LPVOID, :LONG
        GetData typedef ptr TYPE_GetData

        TYPE_PutData typedef proto WIN_STD_CALL_CONV :LPARAM, :LONG, :LPVOID, :LONG
        PutData typedef ptr TYPE_PutData

      ICCOMPRESSFRAMES ends
      ; l == % done
      ; l == error string (LPSTR)
      ICSETSTATUSPROC struct
        dwFlags DWORD ?
        lParam LPARAM ?
        ; messages for Status callback
        ICSTATUS_START equ 0
        ICSTATUS_STATUS equ 1; l == % done

        ICSTATUS_END equ 2
        ICSTATUS_ERROR equ 3; l == error string (LPSTR)

        ICSTATUS_YIELD equ 4
        ; return nonzero means abort operation in progress
        TYPE_Status typedef proto WIN_STD_CALL_CONV :LPARAM, :UINT, :LONG
        Status typedef ptr TYPE_Status

      ICSETSTATUSPROC ends
      ;************************************************************************
      ;************************************************************************
      ICDECOMPRESS_HURRYUP equ 80000000h; don't draw just buffer (hurry up!)

      ICDECOMPRESS_UPDATE equ 40000000h; don't draw just update screen

      ICDECOMPRESS_PREROLL equ 20000000h; this frame is before real start

      ICDECOMPRESS_NULLFRAME equ 10000000h; repeat last frame

      ICDECOMPRESS_NOTKEYFRAME equ 08000000h; this frame is not a key frame

      ICDECOMPRESS struct
        dwFlags DWORD ?
        ; flags (from AVI index...)
        lpbiInput LPBITMAPINFOHEADER ?
        ; BITMAPINFO of compressed data
        ; biSizeImage has the chunk size
        lpInput POINTER ?
        ; compressed data
        lpbiOutput LPBITMAPINFOHEADER ?
        ; DIB to decompress to
        lpOutput POINTER ?
        ckid DWORD ?
        ; ckid from AVI file
      ICDECOMPRESS ends
      ICDECOMPRESSEX struct
        ; same as ICM_DECOMPRESS
        dwFlags DWORD ?
        lpbiSrc LPBITMAPINFOHEADER ?
        ; BITMAPINFO of compressed data
        lpSrc POINTER ?
        ; compressed data
        lpbiDst LPBITMAPINFOHEADER ?
        ; DIB to decompress to
        lpDst POINTER ?
        ; output data
        ; new for ICM_DECOMPRESSEX
        xDst SDWORD ?
        ; destination rectangle
        yDst SDWORD ?
        dxDst SDWORD ?
        dyDst SDWORD ?
        xSrc SDWORD ?
        ; source rectangle
        ySrc SDWORD ?
        dxSrc SDWORD ?
        dySrc SDWORD ?
      ICDECOMPRESSEX ends
      ;************************************************************************
      ;************************************************************************
      ICDRAW_QUERY equ 00000001h; test for support

      ICDRAW_FULLSCREEN equ 00000002h; draw to full screen

      ICDRAW_HDC equ 00000004h; draw to a HDC/HWND

      ICDRAW_ANIMATE equ 00000008h; expect palette animation

      ICDRAW_CONTINUE equ 00000010h; draw is a continuation of previous draw

      ICDRAW_MEMORYDC equ 00000020h; DC is offscreen, by the way

      ICDRAW_UPDATING equ 00000040h; We're updating, as opposed to playing

      ICDRAW_RENDER equ 00000080h; used to render data not draw it

      ICDRAW_BUFFER equ 00000100h; please buffer this data offscreen, we will need to update it

      ICDRAWBEGIN struct
        dwFlags DWORD ?
        ; flags
        hpal HPALETTE ?
        ; palette to draw with
        hwnd HWND ?
        ; window to draw to
        hdc HDC ?
        ; HDC to draw to
        xDst SDWORD ?
        ; destination rectangle
        yDst SDWORD ?
        dxDst SDWORD ?
        dyDst SDWORD ?
        lpbi LPBITMAPINFOHEADER ?
        ; format of frame to draw
        xSrc SDWORD ?
        ; source rectangle
        ySrc SDWORD ?
        dxSrc SDWORD ?
        dySrc SDWORD ?
        dwRate DWORD ?
        ; frames/second = (dwRate/dwScale)
        dwScale DWORD ?
      ICDRAWBEGIN ends
      ;************************************************************************
      ;************************************************************************
      ICDRAW_HURRYUP equ 80000000h; don't draw just buffer (hurry up!)

      ICDRAW_UPDATE equ 40000000h; don't draw just update screen

      ICDRAW_PREROLL equ 20000000h; this frame is before real start

      ICDRAW_NULLFRAME equ 10000000h; repeat last frame

      ICDRAW_NOTKEYFRAME equ 08000000h; this frame is not a key frame

      ICDRAW struct
        dwFlags DWORD ?
        ; flags
        lpFormat POINTER ?
        ; format of frame to decompress
        lpData POINTER ?
        ; frame data to decompress
        cbData DWORD ?
        lTime SDWORD ?
        ; time in drawbegin units (see dwRate and dwScale)
      ICDRAW ends
      ICDRAWSUGGEST struct
        lpbiIn LPBITMAPINFOHEADER ?
        ; format to be drawn
        lpbiSuggest LPBITMAPINFOHEADER ?
        ; location for suggested format (or NULL to get size)
        dxSrc SDWORD ?
        ; source extent or 0
        dySrc SDWORD ?
        dxDst SDWORD ?
        ; dest extent or 0
        dyDst SDWORD ?
        hicDecompressor HIC ?
        ; decompressor you can talk to
      ICDRAWSUGGEST ends
      ;************************************************************************
      ;************************************************************************
      ICPALETTE struct
        dwFlags DWORD ?
        ; flags (from AVI index...)
        iStart SDWORD ?
        ; first palette to change
        iLen SDWORD ?
        ; count of entries to change.
        lppe LPPALETTEENTRY ?
        ; palette
      ICPALETTE ends
      ;************************************************************************
      ;ICM function declarations
      ;************************************************************************
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
      ;* Values for wFlags of ICInstall() *
      ICINSTALL_UNICODE equ 8000h
      ICINSTALL_FUNCTION equ 0001h; lParam is a DriverProc (function ptr)

      ICINSTALL_DRIVER equ 0002h; lParam is a driver name (string)

      ICINSTALL_HDRV equ 0004h; lParam is a HDRVR (driver handle)

      ICINSTALL_DRIVERW equ 8002h; lParam is a unicode driver name

      ;************************************************************************
      ;query macros
      ;************************************************************************
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
      ;************************************************************************
      ;get/set state macros
      ;************************************************************************
      ICGetState macro hic, pv, cb
        exitm <ICSendMessage (hic, ICM_GETSTATE, (pv), (cb))>
      endm
      ICSetState macro hic, pv, cb
        exitm <ICSendMessage (hic, ICM_SETSTATE, (pv), (cb))>
      endm
      ICGetStateSize macro hic
        exitm <ICGetState(hic, NULL, 0)>
      endm
      ;************************************************************************
      ;get value macros
      ;************************************************************************
      ICGetDefaultQuality macro hic
        exitm <(ICSendMessage (hic, ICM_GETDEFAULTQUALITY, and dwICValue, sizeof(DWORD)), dwICValue)>
      endm
      ICGetDefaultKeyFrameRate macro hic
        exitm <(ICSendMessage (hic, ICM_GETDEFAULTKEYFRAMERATE, and dwICValue, sizeof(DWORD)), dwICValue)>
      endm
      ;************************************************************************
      ;draw window macro
      ;************************************************************************
      ICDrawWindow macro hic, prc
        exitm <ICSendMessage (hic, ICM_DRAW_WINDOW, (prc), sizeof(RECT))>
      endm
      ;************************************************************************
      ;compression functions
      ;************************************************************************
      ;*
      ;*  ICCompress()
      ;*
      ;*  compress a single frame
      ;*
      ;*
      ICCompress proto c :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :LPBITMAPINFOHEADER, :LPVOID, :LPDWORD, :LPDWORD, :LONG, :DWORD, :DWORD, :LPBITMAPINFOHEADER, :LPVOID
      ; previous frame
      ;*
      ;*  ICCompressBegin()
      ;*
      ;*  start compression from a source format (lpbiInput) to a dest
      ;*  format (lpbiOuput) is supported.
      ;*
      ;*
      ICCompressBegin macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_BEGIN, (lpbiInput), (lpbiOutput))>
      endm
      ;*
      ;*  ICCompressQuery()
      ;*
      ;*  determines if compression from a source format (lpbiInput) to a dest
      ;*  format (lpbiOuput) is supported.
      ;*
      ;*
      ICCompressQuery macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_QUERY, (lpbiInput), (lpbiOutput))>
      endm
      ;*
      ;*  ICCompressGetFormat()
      ;*
      ;*  get the output format, (format of compressed data)
      ;*  if lpbiOutput is NULL return the size in bytes needed for format.
      ;*
      ;*
      ICCompressGetFormat macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_GET_FORMAT, (lpbiInput), (lpbiOutput))>
      endm
      ICCompressGetFormatSize macro hic, lpbi
        exitm <ICCompressGetFormat(hic, lpbi, NULL)>
      endm
      ;*
      ;*  ICCompressSize()
      ;*
      ;*  return the maximal size of a compressed frame
      ;*
      ;*
      ICCompressGetSize macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_COMPRESS_GET_SIZE, (lpbiInput), (lpbiOutput))>
      endm
      ICCompressEnd macro hic
        exitm <ICSendMessage (hic, ICM_COMPRESS_END, 0, 0)>
      endm
      ;************************************************************************
      ;decompression functions
      ;************************************************************************
      ;*
      ;*  ICDecompress()
      ;*
      ;*  decompress a single frame
      ;*
      ;*
      ICDECOMPRESS_HURRYUP equ 80000000h; don't draw just buffer (hurry up!)

      ICDecompress proto c :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :LPBITMAPINFOHEADER, :LPVOID
      ; DIB to decompress to
      ;*
      ;*  ICDecompressBegin()
      ;*
      ;*  start compression from a source format (lpbiInput) to a dest
      ;*  format (lpbiOutput) is supported.
      ;*
      ;*
      ICDecompressBegin macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_BEGIN, (lpbiInput), (lpbiOutput))>
      endm
      ;*
      ;*  ICDecompressQuery()
      ;*
      ;*  determines if compression from a source format (lpbiInput) to a dest
      ;*  format (lpbiOutput) is supported.
      ;*
      ;*
      ICDecompressQuery macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_QUERY, (lpbiInput), (lpbiOutput))>
      endm
      ;*
      ;*  ICDecompressGetFormat()
      ;*
      ;*  get the output format, (format of un-compressed data)
      ;*  if lpbiOutput is NULL return the size in bytes needed for format.
      ;*
      ;*
      ICDecompressGetFormat macro hic, lpbiInput, lpbiOutput
        exitm <(ICSendMessage (hic, ICM_DECOMPRESS_GET_FORMAT, (lpbiInput), (lpbiOutput)))>
      endm
      ICDecompressGetFormatSize macro hic, lpbi
        exitm <ICDecompressGetFormat(hic, lpbi, NULL)>
      endm
      ;*
      ;*  ICDecompressGetPalette()
      ;*
      ;*  get the output palette
      ;*
      ;*
      ICDecompressGetPalette macro hic, lpbiInput, lpbiOutput
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_GET_PALETTE, (lpbiInput), (lpbiOutput))>
      endm
      ICDecompressSetPalette macro hic, lpbiPalette
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_SET_PALETTE, (lpbiPalette), 0)>
      endm
      ICDecompressEnd macro hic
        exitm <ICSendMessage (hic, ICM_DECOMPRESS_END, 0, 0)>
      endm
      ;************************************************************************
      ;decompression (ex) functions
      ;************************************************************************
      ; on Win16 these functions are macros that call ICMessage. ICMessage will
      ; not work on NT. rather than add new entrypoints we have given
      ; them as static inline functions
      ;*
      ;*  ICDecompressEx()
      ;*
      ;*  decompress a single frame
      ;*
      ;*
      ICDecompressEx proto WIN_STD_CALL_CONV :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      ; note that ICM swaps round the length and pointer
      ; length in lparam2, pointer in lparam1
      ;*
      ;*  ICDecompressExBegin()
      ;*
      ;*  start compression from a source format (lpbiInput) to a dest
      ;*  format (lpbiOutput) is supported.
      ;*
      ;*
      ICDecompressExBegin proto WIN_STD_CALL_CONV :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      ; note that ICM swaps round the length and pointer
      ; length in lparam2, pointer in lparam1
      ;*
      ;*  ICDecompressExQuery()
      ;*
      ;*
      ICDecompressExQuery proto WIN_STD_CALL_CONV :HIC, :DWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      ; note that ICM swaps round the length and pointer
      ; length in lparam2, pointer in lparam1
      ICDecompressExEnd macro hic
        exitm <ICSendMessage (hic, ICM_DECOMPRESSEX_END, 0, 0)>
      endm
      ;************************************************************************
      ;drawing functions
      ;************************************************************************
      ;*
      ;*  ICDrawBegin()
      ;*
      ;*  start decompressing data with format (lpbiInput) directly to the screen
      ;*
      ;*  return zero if the decompressor supports drawing.
      ;*
      ;*
      ICDRAW_QUERY equ 00000001h; test for support

      ICDRAW_FULLSCREEN equ 00000002h; draw to full screen

      ICDRAW_HDC equ 00000004h; draw to a HDC/HWND

      ICDrawBegin proto c :HIC, :DWORD, :HPALETTE, :HWND, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD, :DWORD
      ; frames/second = (dwRate/dwScale)
      ;*
      ;*  ICDraw()
      ;*
      ;*  decompress data directly to the screen
      ;*
      ;*
      ICDRAW_HURRYUP equ 80000000h; don't draw just buffer (hurry up!)

      ICDRAW_UPDATE equ 40000000h; don't draw just update screen

      ICDraw proto c :HIC, :DWORD, :LPVOID, :LPVOID, :DWORD, :LONG
      ; time to draw this frame
      ; ICMessage is not supported on Win32, so provide a static inline function
      ; to do the same job
      ICDrawSuggestFormat proto WIN_STD_CALL_CONV :HIC, :LPBITMAPINFOHEADER, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HIC
      ; note that ICM swaps round the length and pointer
      ; length in lparam2, pointer in lparam1
      ;*
      ;*  ICDrawQuery()
      ;*
      ;*  determines if the compressor is willing to render the specified format.
      ;*
      ;*
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
      ;************************************************************************
      ;Status callback functions
      ;************************************************************************
      ;*
      ;*  ICSetStatusProc()
      ;*
      ;*  Set the status callback function
      ;*
      ;*
      ; ICMessage is not supported on NT
      ICSetStatusProc proto WIN_STD_CALL_CONV :HIC, :DWORD, :LRESULT, :POINTER
      ; note that ICM swaps round the length and pointer
      ; length in lparam2, pointer in lparam1
      ;************************************************************************
      ;helper routines for DrawDib and MCIAVI...
      ;************************************************************************
      ICDecompressOpen macro fccType, fccHandler, lpbiIn, lpbiOut
        exitm <ICLocate (fccType, fccHandler, lpbiIn, lpbiOut, ICMODE_DECOMPRESS)>
      endm
      ICDrawOpen macro fccType, fccHandler, lpbiIn
        exitm <ICLocate (fccType, fccHandler, lpbiIn, NULL, ICMODE_DRAW)>
      endm
      ICLocate proto WIN_STD_CALL_CONV :DWORD, :DWORD, :LPBITMAPINFOHEADER, :LPBITMAPINFOHEADER, :WORD
      ICGetDisplayFormat proto WIN_STD_CALL_CONV :HIC, :LPBITMAPINFOHEADER, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :SDWORD
      ;************************************************************************
      ;Higher level functions
      ;************************************************************************
      ICImageCompress proto WIN_STD_CALL_CONV :HIC, :UINT, :LPBITMAPINFO, :LPVOID, :LPBITMAPINFO, :LONG, :ptr LONG
      ; compress to this size (0=whatever)
      ICImageDecompress proto WIN_STD_CALL_CONV :HIC, :UINT, :LPBITMAPINFO, :LPVOID, :LPBITMAPINFO
      ; decompress to this (NULL ==> default)
      ; Structure used by ICSeqCompressFrame and ICCompressorChoose routines
      ; Make sure this matches the autodoc in icm.c!
      COMPVARS struct
        cbSize SDWORD ?
        ; set to sizeof(COMPVARS) before
        ; calling ICCompressorChoose
        dwFlags DWORD ?
        ; see below...
        hic HIC ?
        ; HIC of chosen compressor
        fccType DWORD ?
        ; basically ICTYPE_VIDEO
        fccHandler DWORD ?
        ; handler of chosen compressor or
        ; "" or "DIB "
        lpbiIn LPBITMAPINFO ?
        ; input format
        lpbiOut LPBITMAPINFO ?
        ; output format - will compress to this
        lpBitsOut POINTER ?
        lpBitsPrev POINTER ?
        lFrame SDWORD ?
        lKey SDWORD ?
        ; key frames how often?
        lDataRate SDWORD ?
        ; desired data rate KB/Sec
        lQ SDWORD ?
        ; desired quality
        lKeyCount SDWORD ?
        lpState POINTER ?
        ; state of compressor
        cbState SDWORD ?
        ; size of the state
      COMPVARS ends
      PCOMPVARS typedef ptr COMPVARS
      ; FLAGS for dwFlags element of COMPVARS structure:
      ; set this flag if you initialize COMPVARS before calling ICCompressorChoose
      ICMF_COMPVARS_VALID equ 00000001h; COMPVARS contains valid data

      ;  allows user to choose compressor, quality etc...
      ICCompressorChoose proto WIN_STD_CALL_CONV :HWND, :UINT, :LPVOID, :LPVOID, :PCOMPVARS, :LPSTR
      ; dialog title (optional)
      ; defines for uiFlags
      ICMF_CHOOSE_KEYFRAME equ 0001h; show KeyFrame Every box

      ICMF_CHOOSE_DATARATE equ 0002h; show DataRate box

      ICMF_CHOOSE_PREVIEW equ 0004h; allow expanded preview dialog

      ICMF_CHOOSE_ALLCOMPRESSORS equ 0008h; don't only show those that

      ; can handle the input format
      ; or input data
      ICSeqCompressFrameStart proto WIN_STD_CALL_CONV :PCOMPVARS, :LPBITMAPINFO
      ICSeqCompressFrameEnd proto WIN_STD_CALL_CONV :PCOMPVARS
      ICSeqCompressFrame proto WIN_STD_CALL_CONV :PCOMPVARS, :UINT, :LPVOID, :ptr BOOL, :ptr LONG
      ; size to compress to/of returned image
      ICCompressorFree proto WIN_STD_CALL_CONV :PCOMPVARS
      ;* NOCOMPMAN *
    endif
    ;**************************************************************************
    ;*
    ;*  DRAWDIB - Routines for drawing to the display.
    ;*
    ;*************************************************************************
    ifndef NODRAWDIB
      ;* hdd *
      HDRAWDIB typedef HANDLE
      ;*********************************************************************
      ;DrawDib Flags
      ;**********************************************************************
      ;* ;Internal *
      DDF_0001 equ 0001h
      ;* re-draw the last DIB *
      DDF_UPDATE equ 0002h
      ;* HDC same as last call (all setup) *
      DDF_SAME_HDC equ 0004h
      ;* draw params are the same *
      DDF_SAME_DRAW equ 0008h
      ;* dont draw frame, just decompress *
      DDF_DONTDRAW equ 0010h
      ;* allow palette animation *
      DDF_ANIMATE equ 0020h
      ;* always buffer image *
      DDF_BUFFER equ 0040h
      ;* just draw it with GDI *
      DDF_JUSTDRAWIT equ 0080h
      ;* use DisplayDib *
      DDF_FULLSCREEN equ 0100h
      ;* Realize palette in background *
      DDF_BACKGROUNDPAL equ 0200h
      ;* this is a partial frame update, hint *
      DDF_NOTKEYFRAME equ 0400h
      ;* hurry up please! *
      DDF_HURRYUP equ 0800h
      ;* always halftone *
      DDF_HALFTONE equ 1000h
      ;* ;Internal *
      DDF_2000 equ 2000h
      ;* Builing up a non-keyframe *
      DDF_PREROLL equ <DDF_DONTDRAW>
      DDF_SAME_DIB equ <DDF_SAME_DRAW>
      DDF_SAME_SIZE equ <DDF_SAME_DRAW>
      ;*********************************************************************
      ;DrawDib functions
      ;*********************************************************************
      ;*							// ;Internal
      ;**  DrawDibInit()					// ;Internal
      ;**							// ;Internal
      ; ;Internal
      DrawDibInit proto WIN_STD_CALL_CONV
      ; ;Internal
      ; ;Internal
      ;*
      ;**  DrawDibOpen()
      ;**
      ;*
      DrawDibOpen proto WIN_STD_CALL_CONV
      ;*
      ;**  DrawDibClose()
      ;**
      ;*
      DrawDibClose proto WIN_STD_CALL_CONV :HDRAWDIB
      ;*
      ;** DrawDibGetBuffer()
      ;**
      ;*
      DrawDibGetBuffer proto WIN_STD_CALL_CONV :HDRAWDIB, :LPBITMAPINFOHEADER, :DWORD, :DWORD
      ;*							// ;Internal
      ;**  DrawDibError()					// ;Internal
      ; ;Internal
      DrawDibError proto WIN_STD_CALL_CONV :HDRAWDIB
      ; ;Internal
      ; ;Internal
      ;*
      ;**  DrawDibGetPalette()
      ;**
      ;**  get the palette used for drawing DIBs
      ;**
      ;*
      DrawDibGetPalette proto WIN_STD_CALL_CONV :HDRAWDIB
      ;*
      ;**  DrawDibSetPalette()
      ;**
      ;**  get the palette used for drawing DIBs
      ;**
      ;*
      DrawDibSetPalette proto WIN_STD_CALL_CONV :HDRAWDIB, :HPALETTE
      ;*
      ;**  DrawDibChangePalette()
      ;*
      DrawDibChangePalette proto WIN_STD_CALL_CONV :HDRAWDIB, :SDWORD, :SDWORD, :LPPALETTEENTRY
      ;*
      ;**  DrawDibRealize()
      ;**
      ;**  realize the palette in a HDD
      ;**
      ;*
      DrawDibRealize proto WIN_STD_CALL_CONV :HDRAWDIB, :HDC, :BOOL
      ;*
      ;**  DrawDibStart()
      ;**
      ;**  start of streaming playback
      ;**
      ;*
      DrawDibStart proto WIN_STD_CALL_CONV :HDRAWDIB, :DWORD
      ;*
      ;**  DrawDibStop()
      ;**
      ;**  start of streaming playback
      ;**
      ;*
      DrawDibStop proto WIN_STD_CALL_CONV :HDRAWDIB
      ;*
      ;**  DrawDibBegin()
      ;**
      ;**  prepare to draw
      ;**
      ;*
      DrawDibBegin proto WIN_STD_CALL_CONV :HDRAWDIB, :HDC, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :SDWORD, :SDWORD, :UINT
      ;*
      ;**  DrawDibDraw()
      ;**
      ;**  actualy draw a DIB to the screen.
      ;**
      ;*
      DrawDibDraw proto WIN_STD_CALL_CONV :HDRAWDIB, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT
      ;*
      ;**  DrawDibUpdate()
      ;**
      ;**  redraw the last image (may only be valid with DDF_BUFFER)
      ;*
      DrawDibUpdate macro hdd, hdc, x, y
        exitm <DrawDibDraw (hdd, hdc, x, y, 0, 0, NULL, NULL, 0, 0, 0, 0, DDF_UPDATE)>
      endm
      ;*
      ;**  DrawDibEnd()
      ;*
      DrawDibEnd proto WIN_STD_CALL_CONV :HDRAWDIB
      ;*
      ;**  DrawDibTime()  [for debugging purposes only]
      ;*
      DRAWDIBTIME struct
        timeCount SDWORD ?
        timeDraw SDWORD ?
        timeDecompress SDWORD ?
        timeDither SDWORD ?
        timeStretch SDWORD ?
        timeBlt SDWORD ?
        timeSetDIBits SDWORD ?
      DRAWDIBTIME ends
      LPDRAWDIBTIME typedef ptr DRAWDIBTIME
      DrawDibTime proto WIN_STD_CALL_CONV :HDRAWDIB, :LPDRAWDIBTIME
      ;* display profiling *
      ;* if you can draw at all *
      PD_CAN_DRAW_DIB equ 0001h
      ;* basicly RC_STRETCHDIB *
      PD_CAN_STRETCHDIB equ 0002h
      ;* is it fast? *
      PD_STRETCHDIB_1_1_OK equ 0004h
      ;* ... *
      PD_STRETCHDIB_1_2_OK equ 0008h
      ;* ... *
      PD_STRETCHDIB_1_N_OK equ 0010h
      DrawDibProfileDisplay proto WIN_STD_CALL_CONV :LPBITMAPINFOHEADER
      ifdef DRAWDIB_INCLUDE_STRETCHDIB
        StretchDIB proto WIN_STD_CALL_CONV :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPBITMAPINFOHEADER, :LPVOID, :SDWORD, :SDWORD, :SDWORD, :SDWORD
      endif
      ;* NODRAWDIB *
    endif
    ;****************************************************************************
    ;*
    ;*  AVIFMT - AVI file format definitions
    ;*
    ;****************************************************************************
    ifndef NOAVIFMT
      ifndef _INC_MMSYSTEM
        FOURCC typedef DWORD
      endif
      ifdef _MSC_VER
      endif
      ;* The following is a short description of the AVI file format.  Please
      ;* see the accompanying documentation for a full explanation.
      ;*
      ;* An AVI file is the following RIFF form:
      ;*
      ;*	RIFF('AVI'
      ;*	      LIST('hdrl'
      ;*		    avih(<MainAVIHeader>)
      ;*                  LIST ('strl'
      ;*                      strh(<Stream header>)
      ;*                      strf(<Stream format>)
      ;*                      ... additional header data
      ;*            LIST('movi'	
      ;*      	  { LIST('rec'
      ;*      		      SubChunk...
      ;*      		   )
      ;*      	      | SubChunk } ....	
      ;*            )
      ;*            [ <AVIIndex> ]
      ;*      )
      ;*
      ;*	The main file header specifies how many streams are present.  For
      ;*	each one, there must be a stream header chunk and a stream format
      ;*	chunk, enlosed in a 'strl' LIST chunk.  The 'strf' chunk contains
      ;*	type-specific format information; for a video stream, this should
      ;*	be a BITMAPINFO structure, including palette.  For an audio stream,
      ;*	this should be a WAVEFORMAT (or PCMWAVEFORMAT) structure.
      ;*
      ;*	The actual data is contained in subchunks within the 'movi' LIST
      ;*	chunk.  The first two characters of each data chunk are the
      ;*	stream number with which that data is associated.
      ;*
      ;*	Some defined chunk types:
      ;*           Video Streams:
      ;*                  ##db:	RGB DIB bits
      ;*                  ##dc:	RLE8 compressed DIB bits
      ;*                  ##pc:	Palette Change
      ;*
      ;*           Audio Streams:
      ;*                  ##wb:	waveform audio bytes
      ;*
      ;* The grouping into LIST 'rec' chunks implies only that the contents of
      ;*   the chunk should be read into memory at the same time.  This
      ;*   grouping is used for files specifically intended to be played from
      ;*   CD-ROM.
      ;*
      ;* The index chunk at the end of the file should contain one entry for
      ;*   each data chunk in the file.
      ;*
      ;* Limitations for the current software:
      ;*	Only one video stream and one audio stream are allowed.
      ;*	The streams must start at the beginning of the file.
      ;*
      ;*
      ;* To register codec types please obtain a copy of the Multimedia
      ;* Developer Registration Kit from:
      ;*
      ;*  Microsoft Corporation
      ;*  Multimedia Systems Group
      ;*  Product Marketing
      ;*  One Microsoft Way
      ;*  Redmond, WA 98052-6399
      ;*
      ;*
      ifndef mmioFOURCC
        mmioFOURCC macro ch0, ch1, ch2, ch3
          exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
        endm
      endif
      ;* Macro to make a TWOCC out of two characters *
      ifndef aviTWOCC
        aviTWOCC macro ch0, ch1
          exitm <((ch0) or ((ch1) shl 8))>
        endm
      endif
      TWOCC typedef WORD
      ;* form types, list types, and chunk types *
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
      ;*
      ;** Stream types for the <fccType> field of the stream header.
      ;*
      streamtypeVIDEO equ <mmioFOURCC('v', 'i', 'd', 's')>
      streamtypeAUDIO equ <mmioFOURCC('a', 'u', 'd', 's')>
      streamtypeMIDI equ <mmioFOURCC('m', 'i', 'd', 's')>
      streamtypeTEXT equ <mmioFOURCC('t', 'x', 't', 's')>
      ;* Basic chunk types *
      cktypeDIBbits equ <aviTWOCC('d', 'b')>
      cktypeDIBcompressed equ <aviTWOCC('d', 'c')>
      cktypePALchange equ <aviTWOCC('p', 'c')>
      cktypeWAVEbytes equ <aviTWOCC('w', 'b')>
      ;* Chunk id to use for extra chunks for padding. *
      ckidAVIPADDING equ <mmioFOURCC('J', 'U', 'N', 'K')>
      ;*
      ;** Useful macros
      ;**
      ;** Warning: These are nasty macro, and MS C 6.0 compiles some of them
      ;** incorrectly if optimizations are on.  Ack.
      ;*
      ;* Macro to get stream number out of a FOURCC ckid *
      FromHex macro n
        exitm <(((n) >= 'A') ? ((n) + 10 - 'A') : ((n) - '0'))>
      endm
      StreamFromFOURCC macro fcc
        exitm <(((FromHex(LOBYTE(LOWORD(fcc))) shl 4) + (FromHex(HIBYTE(LOWORD(fcc))))))>
      endm
      ;* Macro to get TWOCC chunk type out of a FOURCC ckid *
      TWOCCFromFOURCC macro fcc
        exitm <HIWORD(fcc)>
      endm
      ;* Macro to make a ckid for a chunk out of a TWOCC and a stream number
      ;** from 0-255.
      ;*
      ToHex macro n
        exitm <((((n) > 9) ? ((n) - 10 + 'A') : ((n) + '0')))>
      endm
      MAKEAVICKID macro tcc, stream
        exitm <MAKELONG((ToHex((stream) and 0fh) shl 8) or (ToHex(((stream) and 0f0h) shr 4)), tcc)>
      endm
      ;*
      ;** Main AVI File Header
      ;*
      ;* flags for use in <dwFlags> in AVIFileHdr *
      AVIF_HASINDEX equ 00000010h; Index at end of file?

      AVIF_MUSTUSEINDEX equ 00000020h
      AVIF_ISINTERLEAVED equ 00000100h
      AVIF_WASCAPTUREFILE equ 00010000h
      AVIF_COPYRIGHTED equ 00020000h
      ;* The AVI File Header LIST chunk should be padded to this size *
      AVI_HEADERSIZE equ 2048; size of AVI header list

      MainAVIHeader struct
        dwMicroSecPerFrame DWORD ?
        ; frame display rate (or 0L)
        dwMaxBytesPerSec DWORD ?
        ; max. transfer rate
        dwPaddingGranularity DWORD ?
        ; pad to multiples of this
        ; size; normally 2K.
        dwFlags DWORD ?
        ; the ever-present flags
        dwTotalFrames DWORD ?
        ; # frames in file
        dwInitialFrames DWORD ?
        dwStreams DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwWidth DWORD ?
        dwHeight DWORD ?
        dwReserved DWORD 4 dup (?)
      MainAVIHeader ends
      ;*
      ;** Stream header
      ;*
      AVISF_DISABLED equ 00000001h
      AVISF_VIDEO_PALCHANGES equ 00010000h
      AVIStreamHeader struct
        fccType FOURCC ?
        fccHandler FOURCC ?
        dwFlags DWORD ?
        ;* Contains AVITF_* flags *
        wPriority WORD ?
        wLanguage WORD ?
        dwInitialFrames DWORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        ;* dwRate / dwScale == samples/second *
        dwStart DWORD ?
        dwLength DWORD ?
        ;* In units above... *
        dwSuggestedBufferSize DWORD ?
        dwQuality DWORD ?
        dwSampleSize DWORD ?
        rcFrame RECT <>
      AVIStreamHeader ends
      ;* Flags for index *
      AVIIF_LIST equ 00000001h; chunk is a 'LIST'

      AVIIF_KEYFRAME equ 00000010h; this frame is a key frame.

      AVIIF_FIRSTPART equ 00000020h; this frame is the start of a partial frame.

      AVIIF_LASTPART equ 00000040h; this frame is the end of a partial frame.

      AVIIF_MIDPART equ <(AVIIF_LASTPART or AVIIF_FIRSTPART)>
      AVIIF_NOTIME equ 00000100h; this frame doesn't take any time

      AVIIF_COMPUSE equ 0FFF0000h; these bits are for compressor use

      AVIINDEXENTRY struct
        ckid DWORD ?
        dwFlags DWORD ?
        dwChunkOffset DWORD ?
        ; Position of chunk
        dwChunkLength DWORD ?
        ; Length of chunk
      AVIINDEXENTRY ends
      ;*
      ;** Palette change chunk
      ;**
      ;** Used in video streams.
      ;*
      AVIPALCHANGE struct
        bFirstEntry BYTE ?
        ;* first entry to change *
        bNumEntries BYTE ?
        ;* # entries to change (0 if 256) *
        wFlags WORD ?
        ;* Mostly to preserve alignment... *
        peNew PALETTEENTRY 0 dup (<>)
        ;* New color specifications *
      AVIPALCHANGE ends
      ;* NOAVIFMT *
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*
    ;*  MMREG.H (standard include file for MM defines, like FOURCC and things)
    ;*
    ;***************************************************************************
    ifndef RC_INVOKED
      include pshpack8.inc
    endif
    ifndef NOMMREG
      include mmreg.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*
    ;*  AVIFile - routines for reading/writing standard AVI files
    ;*
    ;***************************************************************************
    ifndef NOAVIFILE
      ;*
      ;* Ansi - Unicode thunking.
      ;*
      ;* Unicode or Ansi-only apps can call the avifile APIs.
      ;* any Win32 app who wants to use
      ;* any of the AVI COM interfaces must be UNICODE - the AVISTREAMINFO and
      ;* AVIFILEINFO structures used in the Info methods of these interfaces are
      ;* the unicode variants, and no thunking to or from ansi takes place
      ;* except in the AVIFILE api entrypoints.
      ;*
      ;* For Ansi/Unicode thunking: for each entrypoint or structure that
      ;* uses chars or strings, two versions are declared in the Win32 version,
      ;* ApiNameW and ApiNameA. The default name ApiName is #defined to one or
      ;* other of these depending on whether UNICODE is defined (during
      ;* compilation of the app that is including this header). The source will
      ;* contain ApiName and ApiNameA (with ApiName being the Win16 implementation,
      ;* and also #defined to ApiNameW, and ApiNameA being the thunk entrypoint).
      ;*
      ;*
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
        AVIIF_KEYFRAME equ 00000010h; this frame is a key frame.

      endif
      ; For GetFrame::SetFormat - use the best format for the display
      AVIGETFRAMEF_BESTDISPLAYFMT equ 1
      ; Structures used by AVIStreamInfo & AVIFileInfo.
      ; These are related to, but not identical to, the header chunks
      ; in an AVI file.
      ;*
      ;*
      ;* --- AVISTREAMINFO ------------------------------------------------
      ;*
      ;* for Unicode/Ansi thunking we need to declare three versions of this!
      ;*
      AVISTREAMINFOW struct
        fccType DWORD ?
        fccHandler DWORD ?
        dwFlags DWORD ?
        ;* Contains AVITF_* flags *
        dwCaps DWORD ?
        wPriority WORD ?
        wLanguage WORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        ;* dwRate / dwScale == samples/second *
        dwStart DWORD ?
        dwLength DWORD ?
        ;* In units above... *
        dwInitialFrames DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwQuality DWORD ?
        dwSampleSize DWORD ?
        rcFrame RECT <>
        dwEditCount DWORD ?
        dwFormatChangeCount DWORD ?
        szName WORD 64 dup (?)
      AVISTREAMINFOW ends
      _AVISTREAMINFOW typedef AVISTREAMINFOW
      LPAVISTREAMINFOW typedef ptr AVISTREAMINFOW
      AVISTREAMINFOA struct
        fccType DWORD ?
        fccHandler DWORD ?
        dwFlags DWORD ?
        ;* Contains AVITF_* flags *
        dwCaps DWORD ?
        wPriority WORD ?
        wLanguage WORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        ;* dwRate / dwScale == samples/second *
        dwStart DWORD ?
        dwLength DWORD ?
        ;* In units above... *
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
      ;*
      ;* --- AVIFILEINFO ----------------------------------------------------
      ;*
      ;*
      AVIFILEINFOW struct
        dwMaxBytesPerSec DWORD ?
        ; max. transfer rate
        dwFlags DWORD ?
        ; the ever-present flags
        dwCaps DWORD ?
        dwStreams DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwWidth DWORD ?
        dwHeight DWORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        ;* dwRate / dwScale == samples/second *
        dwLength DWORD ?
        dwEditCount DWORD ?
        szFileType WORD 64 dup (?)
        ; descriptive string for file type?
      AVIFILEINFOW ends
      _AVIFILEINFOW typedef AVIFILEINFOW
      LPAVIFILEINFOW typedef ptr AVIFILEINFOW
      AVIFILEINFOA struct
        dwMaxBytesPerSec DWORD ?
        ; max. transfer rate
        dwFlags DWORD ?
        ; the ever-present flags
        dwCaps DWORD ?
        dwStreams DWORD ?
        dwSuggestedBufferSize DWORD ?
        dwWidth DWORD ?
        dwHeight DWORD ?
        dwScale DWORD ?
        dwRate DWORD ?
        ;* dwRate / dwScale == samples/second *
        dwLength DWORD ?
        dwEditCount DWORD ?
        szFileType SBYTE 64 dup (?)
        ; descriptive string for file type?
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
      ; Flags for dwFlags
      AVIFILEINFO_HASINDEX equ 00000010h
      AVIFILEINFO_MUSTUSEINDEX equ 00000020h
      AVIFILEINFO_ISINTERLEAVED equ 00000100h
      AVIFILEINFO_WASCAPTUREFILE equ 00010000h
      AVIFILEINFO_COPYRIGHTED equ 00020000h
      ; Flags for dwCaps
      AVIFILECAPS_CANREAD equ 00000001h
      AVIFILECAPS_CANWRITE equ 00000002h
      AVIFILECAPS_ALLKEYFRAMES equ 00000010h
      AVIFILECAPS_NOCOMPRESSION equ 00000020h
      TYPE_AVISAVECALLBACK typedef proto WIN_STD_CALL_CONV :SDWORD
      AVISAVECALLBACK typedef ptr TYPE_AVISAVECALLBACK

      ;************************************************************************
      ;* Declaration for the AVICOMPRESSOPTIONS structure.  Make sure it 	*
      ;* matches the AutoDoc in avisave.c !!!                            	*
      ;************************************************************************
      AVICOMPRESSOPTIONS struct
        fccType DWORD ?
        ;* stream type, for consistency *
        fccHandler DWORD ?
        ;* compressor *
        dwKeyFrameEvery DWORD ?
        ;* keyframe rate *
        dwQuality DWORD ?
        ;* compress quality 0-10,000 *
        dwBytesPerSecond DWORD ?
        ;* bytes per second *
        dwFlags DWORD ?
        ;* flags... see below *
        lpFormat POINTER ?
        ;* save format *
        cbFormat DWORD ?
        lpParms POINTER ?
        ;* compressor options *
        cbParms DWORD ?
        dwInterleaveEvery DWORD ?
        ;* for non-video streams only *
      AVICOMPRESSOPTIONS ends
      LPAVICOMPRESSOPTIONS typedef ptr AVICOMPRESSOPTIONS
      ; Defines for the dwFlags field of the AVICOMPRESSOPTIONS struct
      ; Each of these flags determines if the appropriate field in the structure
      ; (dwInterleaveEvery, dwBytesPerSecond, and dwKeyFrameEvery) is payed
      ; attention to.  See the autodoc in avisave.c for details.
      AVICOMPRESSF_INTERLEAVE equ 00000001h; interleave

      AVICOMPRESSF_DATARATE equ 00000002h; use a data rate

      AVICOMPRESSF_KEYFRAMES equ 00000004h; use keyframes

      AVICOMPRESSF_VALID equ 00000008h; has valid data?

      ifdef __cplusplus
        ;[...]
      endif
      include ole2.inc
      ifdef __cplusplus
        ;[...]
      endif
      ;*	-	-	-	-	-	-	-	-	*
      ;****** AVI Stream Interface *******************************************
      INTERFACE equ <IAVIStream>
      DECLARE_INTERFACE_(IAVIStream, IUnknown)
        ??Interface equ <AVICOMPRESSOPTIONS>
        ; *** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; *** IAVIStream methods ***
        STDMETHOD Create, :LPARAM, :LPARAM
        STDMETHOD Info, :ptr AVISTREAMINFOW, :SDWORD
        STDMETHOD_ LONG, FindSample, :SDWORD, :SDWORD
        STDMETHOD ReadFormat, :SDWORD, :POINTER, :ptr SDWORD
        STDMETHOD SetFormat, :SDWORD, :POINTER, :SDWORD
        STDMETHOD Read, :SDWORD, :SDWORD, :POINTER, :SDWORD, :ptr SDWORD, :ptr SDWORD
        STDMETHOD Write, :SDWORD, :SDWORD, :POINTER, :SDWORD, :DWORD, :ptr SDWORD, :ptr SDWORD
        STDMETHOD Delete, :SDWORD, :SDWORD
        STDMETHOD ReadData, :DWORD, :POINTER, :ptr SDWORD
        STDMETHOD WriteData, :DWORD, :POINTER, :SDWORD
        ifdef _WIN32
          STDMETHOD SetInfo, :ptr AVISTREAMINFOW, :SDWORD
        else
          ;[...]
        endif
      DECLARE_INTERFACE__END

      PAVISTREAM typedef ptr IAVIStream
      INTERFACE equ <IAVIStreaming>
      DECLARE_INTERFACE_(IAVIStreaming, IUnknown)
        ??Interface equ <AVICOMPRESSOPTIONS>
        ; *** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; *** IAVIStreaming methods ***
        STDMETHOD Begin, :SDWORD, :SDWORD, :SDWORD
        ; expected end, or -1
        ; Should this be a float?
        STDMETHOD End_
      DECLARE_INTERFACE__END

      PAVISTREAMING typedef ptr IAVIStreaming
      INTERFACE equ <IAVIEditStream>
      DECLARE_INTERFACE_(IAVIEditStream, IUnknown)
        ??Interface equ <AVICOMPRESSOPTIONS>
        ; *** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; *** IAVIEditStream methods ***
        STDMETHOD Cut, :ptr SDWORD, :ptr SDWORD, :ptr PAVISTREAM
        STDMETHOD Copy, :ptr SDWORD, :ptr SDWORD, :ptr PAVISTREAM
        STDMETHOD Paste, :ptr SDWORD, :ptr SDWORD, :PAVISTREAM, :SDWORD, :SDWORD
        STDMETHOD Clone, :ptr PAVISTREAM
        STDMETHOD SetInfo, :ptr AVISTREAMINFOW, :SDWORD
      DECLARE_INTERFACE__END

      PAVIEDITSTREAM typedef ptr IAVIEditStream
      ;****** AVI File Interface *******************************************
      INTERFACE equ <IAVIPersistFile>
      DECLARE_INTERFACE_(IAVIPersistFile, IPersistFile)
        ??Interface equ <AVICOMPRESSOPTIONS>
        STDMETHOD Reserved1
      DECLARE_INTERFACE__END

      PAVIPERSISTFILE typedef ptr IAVIPersistFile
      INTERFACE equ <IAVIFile>
      PAVIFILE equ <IAVIFile FAR *>
      DECLARE_INTERFACE_(IAVIFile, IUnknown)
        ??Interface equ <AVICOMPRESSOPTIONS>
        ; *** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; *** IAVIFile methods ***
        STDMETHOD Info, :ptr AVIFILEINFOW, :SDWORD
        STDMETHOD GetStream, :ptr PAVISTREAM, :DWORD, :SDWORD
        STDMETHOD CreateStream, :ptr PAVISTREAM, :ptr AVISTREAMINFOW
        STDMETHOD WriteData, :DWORD, :POINTER, :SDWORD
        STDMETHOD ReadData, :DWORD, :POINTER, :ptr SDWORD
        STDMETHOD EndRecord
        STDMETHOD DeleteStream, :DWORD, :SDWORD
      DECLARE_INTERFACE__END

      PAVIFILE typedef ptr IAVIFile
      ;****** GetFrame Interface *******************************************
      INTERFACE equ <IGetFrame>
      PGETFRAME equ <IGetFrame FAR *>
      DECLARE_INTERFACE_(IGetFrame, IUnknown)
        ??Interface equ <AVICOMPRESSOPTIONS>
        ; *** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; *** IGetFrame methods ***
        STDMETHOD_ LPVOID, GetFrame, :SDWORD
        ;  STDMETHOD_(LPVOID,GetFrameData) (THIS_ _In_ LONG lPos) PURE;
        STDMETHOD Begin, :SDWORD, :SDWORD, :SDWORD
        STDMETHOD End_
        STDMETHOD SetFormat, :LPBITMAPINFOHEADER, :POINTER, :SDWORD, :SDWORD, :SDWORD, :SDWORD
        ;  STDMETHOD(DrawFrameStart) (THIS) PURE;
        ;  STDMETHOD(DrawFrame) (THIS_ _In_ LONG lPos, HDC hdc, _In_ int x, _In_ int y, _In_ int dx, _In_ int dy) PURE;
        ;  STDMETHOD(DrawFrameEnd) (THIS) PURE;
      DECLARE_INTERFACE__END

      PGETFRAME typedef ptr IGetFrame
      ;****** GUIDs *******************************************
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
      ; functions
      @DefProto DllImport, AVIFileInit, WIN_STD_CALL_CONV,, <>, 0
      ; Call this first!
      @DefProto DllImport, AVIFileExit, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, AVIFileAddRef, WIN_STD_CALL_CONV,, <:PAVIFILE>, 4
      @DefProto DllImport, AVIFileRelease, WIN_STD_CALL_CONV,, <:PAVIFILE>, 4
      ifdef _WIN32
        @DefProto DllImport, AVIFileOpenA, WIN_STD_CALL_CONV,, <:ptr PAVIFILE, :LPCSTR, :UINT, :LPCLSID>, 16
        @DefProto DllImport, AVIFileOpenW, WIN_STD_CALL_CONV,, <:ptr PAVIFILE, :LPCWSTR, :UINT, :LPCLSID>, 16
        ifdef UNICODE
          AVIFileOpen equ <AVIFileOpenW>
        else
          AVIFileOpen equ <AVIFileOpenA>
        endif
      else
      ; win16
        ;[...]
      endif
      ifdef _WIN32
        @DefProto DllImport, AVIFileInfoW, WIN_STD_CALL_CONV,, <:PAVIFILE, :LPAVIFILEINFOW, :LONG>, 12
        @DefProto DllImport, AVIFileInfoA, WIN_STD_CALL_CONV,, <:PAVIFILE, :LPAVIFILEINFOA, :LONG>, 12
        ifdef UNICODE
          AVIFileInfo equ <AVIFileInfoW>
        else
          AVIFileInfo equ <AVIFileInfoA>
        endif
      else
      ;win16 version
        ;[...]
      endif
      @DefProto DllImport, AVIFileGetStream, WIN_STD_CALL_CONV,, <:PAVIFILE, :ptr PAVISTREAM, :DWORD, :LONG>, 16
      ifdef _WIN32
        @DefProto DllImport, AVIFileCreateStreamW, WIN_STD_CALL_CONV,, <:PAVIFILE, :ptr PAVISTREAM, :ptr AVISTREAMINFOW>, 12
        @DefProto DllImport, AVIFileCreateStreamA, WIN_STD_CALL_CONV,, <:PAVIFILE, :ptr PAVISTREAM, :ptr AVISTREAMINFOA>, 12
        ifdef UNICODE
          AVIFileCreateStream equ <AVIFileCreateStreamW>
        else
          AVIFileCreateStream equ <AVIFileCreateStreamA>
        endif
      else
      ;win16 version
        ;[...]
      endif
      @DefProto DllImport, AVIFileWriteData, WIN_STD_CALL_CONV,, <:PAVIFILE, :DWORD, :LPVOID, :LONG>, 16
      @DefProto DllImport, AVIFileReadData, WIN_STD_CALL_CONV,, <:PAVIFILE, :DWORD, :LPVOID, :ptr LONG>, 16
      @DefProto DllImport, AVIFileEndRecord, WIN_STD_CALL_CONV,, <:PAVIFILE>, 4
      @DefProto DllImport, AVIStreamAddRef, WIN_STD_CALL_CONV,, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamRelease, WIN_STD_CALL_CONV,, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamInfoW, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPAVISTREAMINFOW, :LONG>, 12
      @DefProto DllImport, AVIStreamInfoA, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPAVISTREAMINFOA, :LONG>, 12
      ifdef UNICODE
        AVIStreamInfo equ <AVIStreamInfoW>
      else
        AVIStreamInfo equ <AVIStreamInfoA>
      endif
      @DefProto DllImport, AVIStreamFindSample, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG, :LONG>, 12
      @DefProto DllImport, AVIStreamReadFormat, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG, :LPVOID, :ptr LONG>, 16
      @DefProto DllImport, AVIStreamSetFormat, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG, :LPVOID, :LONG>, 16
      @DefProto DllImport, AVIStreamReadData, WIN_STD_CALL_CONV,, <:PAVISTREAM, :DWORD, :LPVOID, :ptr LONG>, 16
      @DefProto DllImport, AVIStreamWriteData, WIN_STD_CALL_CONV,, <:PAVISTREAM, :DWORD, :LPVOID, :LONG>, 16
      @DefProto DllImport, AVIStreamRead, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG, :LONG, :LPVOID, :LONG, :ptr LONG, :ptr LONG>, 28
      AVISTREAMREAD_CONVENIENT equ (- 1)
      @DefProto DllImport, AVIStreamWrite, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG, :LONG, :LPVOID, :LONG, :DWORD, :ptr LONG, :ptr LONG>, 32
      ; Right now, these just use AVIStreamInfo() to get information, then
      ; return some of it.  Can they be more efficient?
      @DefProto DllImport, AVIStreamStart, WIN_STD_CALL_CONV,, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamLength, WIN_STD_CALL_CONV,, <:PAVISTREAM>, 4
      @DefProto DllImport, AVIStreamTimeToSample, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG>, 8
      @DefProto DllImport, AVIStreamSampleToTime, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG>, 8
      @DefProto DllImport, AVIStreamBeginStreaming, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LONG, :LONG, :LONG>, 16
      @DefProto DllImport, AVIStreamEndStreaming, WIN_STD_CALL_CONV,, <:PAVISTREAM>, 4
      ; helper functions for using IGetFrame
      @DefProto DllImport, AVIStreamGetFrameOpen, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPBITMAPINFOHEADER>, 8
      @DefProto DllImport, AVIStreamGetFrame, WIN_STD_CALL_CONV,, <:PGETFRAME, :LONG>, 8
      @DefProto DllImport, AVIStreamGetFrameClose, WIN_STD_CALL_CONV,, <:PGETFRAME>, 4
      ; !!! We need some way to place an advise on a stream....
      ; STDAPI AVIStreamHasChanged   (PAVISTREAM pavi);
      ; Shortcut function
      @DefProto DllImport, AVIStreamOpenFromFileA, WIN_STD_CALL_CONV,, <:ptr PAVISTREAM, :LPCSTR, :DWORD, :LONG, :UINT, :ptr CLSID>, 24
      @DefProto DllImport, AVIStreamOpenFromFileW, WIN_STD_CALL_CONV,, <:ptr PAVISTREAM, :LPCWSTR, :DWORD, :LONG, :UINT, :ptr CLSID>, 24
      ifdef UNICODE
        AVIStreamOpenFromFile equ <AVIStreamOpenFromFileW>
      else
        AVIStreamOpenFromFile equ <AVIStreamOpenFromFileA>
      endif
      ; Use to create disembodied streams
      @DefProto DllImport, AVIStreamCreate, WIN_STD_CALL_CONV,, <:ptr PAVISTREAM, :LONG, :LONG, :ptr CLSID>, 16
      ; PHANDLER    AVIAPI AVIGetHandler         (PAVISTREAM pavi, PAVISTREAMHANDLER psh);
      ; PAVISTREAM  AVIAPI AVIGetStream          (PHANDLER p);
      ; flags for AVIStreamFindSample
      FIND_DIR equ 0000000Fh; direction

      FIND_NEXT equ 00000001h; go forward

      FIND_PREV equ 00000004h; go backward

      FIND_FROM_START equ 00000008h; start at the logical beginning

      FIND_TYPE equ 000000F0h; type mask

      FIND_KEY equ 00000010h; find key frame.

      FIND_ANY equ 00000020h; find any (non-empty) sample

      FIND_FORMAT equ 00000040h; find format change

      FIND_RET equ 0000F000h; return mask

      FIND_POS equ 00000000h; return logical position

      FIND_LENGTH equ 00001000h; return logical size

      FIND_OFFSET equ 00002000h; return physical position

      FIND_SIZE equ 00003000h; return physical size

      FIND_INDEX equ 00004000h; return physical index position

      ;  stuff to support backward compat.
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
      ;  helper macros.
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
      ;****************************************************************************
      ;*
      ;*  AVISave routines and structures
      ;*
      ;***************************************************************************
      ifndef comptypeDIB
        comptypeDIB equ <mmioFOURCC('D', 'I', 'B', ' ')>
      endif
      @DefProto DllImport, AVIMakeCompressedStream, WIN_STD_CALL_CONV,, <:ptr PAVISTREAM, :PAVISTREAM, :ptr AVICOMPRESSOPTIONS, :ptr CLSID>, 16
      AVISaveA proto c :LPCSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :PAVISTREAM, :LPAVICOMPRESSOPTIONS, :vararg
      @DefProto DllImport, AVISaveVA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :ptr PAVISTREAM, :ptr LPAVICOMPRESSOPTIONS>, 24
      AVISaveW proto c :LPCWSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :PAVISTREAM, :LPAVICOMPRESSOPTIONS, :vararg
      @DefProto DllImport, AVISaveVW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr CLSID, :AVISAVECALLBACK, :SDWORD, :ptr PAVISTREAM, :ptr LPAVICOMPRESSOPTIONS>, 24
      ifdef UNICODE
        AVISave equ <AVISaveW>
        AVISaveV equ <AVISaveVW>
      else
        AVISave equ <AVISaveA>
        AVISaveV equ <AVISaveVA>
      endif
      @DefProto DllImport, AVISaveOptions, WIN_STD_CALL_CONV,, <:HWND, :UINT, :SDWORD, :ptr PAVISTREAM, :ptr LPAVICOMPRESSOPTIONS>, 20
      @DefProto DllImport, AVISaveOptionsFree, WIN_STD_CALL_CONV,, <:SDWORD, :ptr LPAVICOMPRESSOPTIONS>, 8
      ; FLAGS FOR uiFlags:
      ; Same as the flags for ICCompressorChoose (see compman.h)
      ; These determine what the compression options dialog for video streams
      ; will look like.
      @DefProto DllImport, AVIBuildFilterW, WIN_STD_CALL_CONV,, <:LPWSTR, :LONG, :BOOL>, 12
      @DefProto DllImport, AVIBuildFilterA, WIN_STD_CALL_CONV,, <:LPSTR, :LONG, :BOOL>, 12
      ifdef UNICODE
        AVIBuildFilter equ <AVIBuildFilterW>
      else
        AVIBuildFilter equ <AVIBuildFilterA>
      endif
      @DefProto DllImport, AVIMakeFileFromStreams, WIN_STD_CALL_CONV,, <:ptr PAVIFILE, :SDWORD, :ptr PAVISTREAM>, 12
      @DefProto DllImport, AVIMakeStreamFromClipboard, WIN_STD_CALL_CONV,, <:UINT, :HANDLE, :ptr PAVISTREAM>, 12
      ;****************************************************************************
      ;*
      ;*  Clipboard routines
      ;*
      ;***************************************************************************
      @DefProto DllImport, AVIPutFileOnClipboard, WIN_STD_CALL_CONV,, <:PAVIFILE>, 4
      @DefProto DllImport, AVIGetFromClipboard, WIN_STD_CALL_CONV,, <:ptr PAVIFILE>, 4
      @DefProto DllImport, AVIClearClipboard, WIN_STD_CALL_CONV,, <>, 0
      ;****************************************************************************
      ;*
      ;*  Editing routines
      ;*
      ;***************************************************************************
      @DefProto DllImport, CreateEditableStream, WIN_STD_CALL_CONV,, <:ptr PAVISTREAM, :PAVISTREAM>, 8
      @DefProto DllImport, EditStreamCut, WIN_STD_CALL_CONV,, <:PAVISTREAM, :ptr LONG, :ptr LONG, :ptr PAVISTREAM>, 16
      @DefProto DllImport, EditStreamCopy, WIN_STD_CALL_CONV,, <:PAVISTREAM, :ptr LONG, :ptr LONG, :ptr PAVISTREAM>, 16
      @DefProto DllImport, EditStreamPaste, WIN_STD_CALL_CONV,, <:PAVISTREAM, :ptr LONG, :ptr LONG, :PAVISTREAM, :LONG, :LONG>, 24
      @DefProto DllImport, EditStreamClone, WIN_STD_CALL_CONV,, <:PAVISTREAM, :ptr PAVISTREAM>, 8
      @DefProto DllImport, EditStreamSetNameA, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPCSTR>, 8
      @DefProto DllImport, EditStreamSetNameW, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPCWSTR>, 8
      @DefProto DllImport, EditStreamSetInfoW, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPAVISTREAMINFOW, :LONG>, 12
      @DefProto DllImport, EditStreamSetInfoA, WIN_STD_CALL_CONV,, <:PAVISTREAM, :LPAVISTREAMINFOA, :LONG>, 12
      ifdef UNICODE
        EditStreamSetInfo equ <EditStreamSetInfoW>
        EditStreamSetName equ <EditStreamSetNameW>
      else
        EditStreamSetInfo equ <EditStreamSetInfoA>
        EditStreamSetName equ <EditStreamSetNameA>
      endif
      ;*	-	-	-	-	-	-	-	-	*
      ifndef AVIERR_OK
        AVIERR_OK equ 0
        MAKE_AVIERR macro error_
          exitm <MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 4000h + error_)>
        endm
        ; !!! Questions to be answered:
        ; How can you get a string form of these errors?
        ; Which of these errors should be replaced by errors in SCODE.H?
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
      ;* NOAVIFILE *
    endif
    ;****************************************************************************
    ;*
    ;*  MCIWnd - Window class for MCI objects
    ;*
    ;***************************************************************************
    ifndef NOMCIWND
      ;*----------------------------------------------------------------------------*\
      ;*
      ;*  MCIWnd
      ;*
      ;*    MCIWnd window class header file.
      ;*
      ;*    the MCIWnd window class is a window class for controling MCI devices
      ;*    MCI devices include, wave files, midi files, AVI Video, cd audio,
      ;*    vcr, video disc, and others..
      ;*
      ;*    to learn more about MCI and mci command sets see the
      ;*    "Microsoft Multimedia Programmers's guide" in the Win31 SDK
      ;*
      ;*    the easiest use of the MCIWnd class is like so:
      ;*
      ;*          hwnd = MCIWndCreate(hwndParent, hInstance, 0, "chimes.wav");
      ;*          ...
      ;*          MCIWndPlay(hwnd);
      ;*          MCIWndStop(hwnd);
      ;*          MCIWndPause(hwnd);
      ;*          ....
      ;*          MCIWndDestroy(hwnd);
      ;*
      ;*    this will create a window with a play/pause, stop and a playbar
      ;*    and start the wave file playing.
      ;*
      ;*    mciwnd.h defines macros for all the most common MCI commands, but
      ;*    any string command can be used if needed.
      ;*
      ;*    Note: unlike the mciSendString() API, no alias or file name needs
      ;*    to be specifed, since the device to use is implied by the window handle.
      ;*
      ;*          MCIWndSendString(hwnd, "setaudio stream to 2");
      ;*
      ;*    (C) Copyright Microsoft Corp. 1991-1995.  All rights reserved.
      ;*
      ;*    You have a royalty-free right to use, modify, reproduce and
      ;*    distribute the Sample Files (and/or any modified version) in
      ;*    any way you find useful, provided that you agree that
      ;*    Microsoft has no warranty obligations or liability for any
      ;*    Sample Application Files.
      ;*
      ;*    If you did not get this from Microsoft Sources, then it may not be the
      ;*    most current version.  This sample code in particular will be updated
      ;*    and include more documentation.
      ;*
      ;*    Sources are:
      ;*       CompuServe: WINSDK forum, MDK section.
      ;*       Anonymous FTP from ftp.uu.net vendor\microsoft\multimedia
      ;*
      ;* WIN32:
      ;*
      ;*    MCIWnd supports both ansi and unicode interfaces. For any message that
      ;*    takes or returns a text string, two versions of the message are defined,
      ;*    appended with A or W for Ansi or Wide Char. The message or api itself
      ;*    is defined to be one or other of these depending on whether you have
      ;*    UNICODE defined in your application.
      ;*    Thus for the api MCIWndCreate, there are in fact two apis,
      ;*    MCIWndCreateA and MCIWndCreateW. If you call MCIWndCreate, this will be
      ;*    re-routed to MCIWndCreateA unless UNICODE is defined when building your
      ;*    application. In any one application, you can mix calls to the
      ;*    Ansi and Unicode entrypoints.
      ;*
      ;*    If you use SendMessage instead of the macros below such as MCIWndOpen(),
      ;*    you will see that the messages have changed for WIN32, to support Ansi
      ;*    and Unicode entrypoints. In particular, MCI_OPEN has been replaced by
      ;*    MCWNDM_OPENA, or MCIWNDM_OPENW (MCIWNDM_OPEN is defined to be one or
      ;*    other of these).
      ;*
      ;*    Also, note that the WIN32 implementation of MCIWnd uses UNICODE
      ;*    so all apis and messages supporting ANSI strings do so by mapping them
      ;*    UNICODE strings and then calling the corresponding UNICODE entrypoint.
      ;*
      ;*----------------------------------------------------------------------------*
      ifdef __cplusplus
        ;[...]
      else
        ;* SendMessage in C *
        MCIWndSM equ <SendMessage>
        ;* __cplusplus *
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
      ; Flags for the MCIWndOpen command
      MCIWNDOPENF_NEW equ 0001h; open a new file

      ; window styles
      MCIWNDF_NOAUTOSIZEWINDOW equ 0001h; when movie size changes

      MCIWNDF_NOPLAYBAR equ 0002h; no toolbar

      MCIWNDF_NOAUTOSIZEMOVIE equ 0004h; when window size changes

      MCIWNDF_NOMENU equ 0008h; no popup menu from RBUTTONDOWN

      MCIWNDF_SHOWNAME equ 0010h; show name in caption

      MCIWNDF_SHOWPOS equ 0020h; show position in caption

      MCIWNDF_SHOWMODE equ 0040h; show mode in caption

      MCIWNDF_SHOWALL equ 0070h; show all

      MCIWNDF_NOTIFYMODE equ 0100h; tell parent of mode change

      MCIWNDF_NOTIFYPOS equ 0200h; tell parent of pos change

      MCIWNDF_NOTIFYSIZE equ 0400h; tell parent of size change

      MCIWNDF_NOTIFYERROR equ 1000h; tell parent of an error

      MCIWNDF_NOTIFYALL equ 1F00h; tell all

      MCIWNDF_NOTIFYANSI equ 0080h
      ; The MEDIA notification includes a text string.
      ; To receive notifications in ANSI instead of unicode set the
      ; MCIWNDF_NOTIFYANSI style bit. The macro below includes this bit
      ; by default unless you define UNICODE in your application.
      MCIWNDF_NOTIFYMEDIAA equ 0880h; tell parent of media change

      MCIWNDF_NOTIFYMEDIAW equ 0800h; tell parent of media change

      ifdef UNICODE
        MCIWNDF_NOTIFYMEDIA equ <MCIWNDF_NOTIFYMEDIAW>
      else
        MCIWNDF_NOTIFYMEDIA equ <MCIWNDF_NOTIFYMEDIAA>
      endif
      MCIWNDF_RECORD equ 2000h; Give a record button

      MCIWNDF_NOERRORDLG equ 4000h; Show Error Dlgs for MCI cmds?

      MCIWNDF_NOOPEN equ 8000h; Don't allow user to open things

      ; can macros
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
      ; if you dont give a device it will use the current device....
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
      ;#define MCIWndActivate(hwnd, f)     (void)MCIWndSM(hwnd, WM_ACTIVATE, (WPARAM)(BOOL)(f), 0)
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
      ; Messages an app will send to MCIWND
      ; all the text-related messages are defined out of order above (they need
      ; to be defined before the MCIWndOpen() macros
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
      ;define both A and W messages
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
      ; map defaults to A or W depending on app's UNICODE setting
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
      ; note that the source text for MCIWND will thus contain
      ; support for eg MCIWNDM_SENDSTRING (both the 16-bit entrypoint and
      ; in win32 mapped to MCIWNDM_SENDSTRINGW), and MCIWNDM_SENDSTRINGA (the
      ; win32 ansi thunk).
      ; Messages MCIWND will send to an app
      ; !!! Use less messages and use a code instead to indicate the type of notify? /* ;Internal */
      MCIWNDM_NOTIFYMODE equ (WM_USER + 200); wp = hwnd, lp = mode

      MCIWNDM_NOTIFYPOS equ (WM_USER + 201); wp = hwnd, lp = pos

      MCIWNDM_NOTIFYSIZE equ (WM_USER + 202); wp = hwnd

      MCIWNDM_NOTIFYMEDIA equ (WM_USER + 203); wp = hwnd, lp = fn

      MCIWNDM_NOTIFYERROR equ (WM_USER + 205); wp = hwnd, lp = error

      ; special seek values for START and END
      MCIWND_START equ -1
      MCIWND_END equ -2
      ifndef MCI_PLAY
        ;* MCI command message identifiers *
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
        ;* return values for 'status mode' command *
        MCI_MODE_NOT_READY equ (524)
        MCI_MODE_STOP equ (525)
        MCI_MODE_PLAY equ (526)
        MCI_MODE_RECORD equ (527)
        MCI_MODE_SEEK equ (528)
        MCI_MODE_PAUSE equ (529)
        MCI_MODE_OPEN equ (530)
      endif
      ;* NOAVIFILE *
    endif
    ;****************************************************************************
    ;*
    ;*  VIDEO - Video Capture Driver Interface
    ;*
    ;****************************************************************************
    if  not Defined(NOAVICAP) or  not Defined(NOVIDEO)
      ifndef _RCINVOKED
        ;* video data types *
        DECLARE_HANDLE HVIDEO
        ; generic handle
        LPHVIDEO typedef ptr HVIDEO
      endif
      ; ifndef RCINVOKED
      ;****************************************************************************
      ;version api
      ;****************************************************************************
      VideoForWindowsVersion proto WIN_STD_CALL_CONV
      ;****************************************************************************
      ;Error Return Values
      ;****************************************************************************
      ;* No error *
      DV_ERR_OK equ (0)
      ;* Error Base *
      DV_ERR_BASE equ (1)
      DV_ERR_NONSPECIFIC equ <(DV_ERR_BASE)>
      DV_ERR_BADFORMAT equ (DV_ERR_BASE + 1)
      ;* unsupported video format *
      DV_ERR_STILLPLAYING equ (DV_ERR_BASE + 2)
      ;* still something playing *
      DV_ERR_UNPREPARED equ (DV_ERR_BASE + 3)
      ;* header not prepared *
      DV_ERR_SYNC equ (DV_ERR_BASE + 4)
      ;* device is synchronous *
      DV_ERR_TOOMANYCHANNELS equ (DV_ERR_BASE + 5)
      ;* number of channels exceeded *
      ;* HW not detected *
      DV_ERR_NOTDETECTED equ (DV_ERR_BASE + 6)
      ;* Can not get Profile *
      DV_ERR_BADINSTALL equ (DV_ERR_BASE + 7)
      DV_ERR_CREATEPALETTE equ (DV_ERR_BASE + 8)
      DV_ERR_SIZEFIELD equ (DV_ERR_BASE + 9)
      DV_ERR_PARAM1 equ (DV_ERR_BASE + 10)
      DV_ERR_PARAM2 equ (DV_ERR_BASE + 11)
      DV_ERR_CONFIG1 equ (DV_ERR_BASE + 12)
      DV_ERR_CONFIG2 equ (DV_ERR_BASE + 13)
      DV_ERR_FLAGS equ (DV_ERR_BASE + 14)
      DV_ERR_13 equ (DV_ERR_BASE + 15)
      ;* function not suported *
      DV_ERR_NOTSUPPORTED equ (DV_ERR_BASE + 16)
      ;* out of memory *
      DV_ERR_NOMEM equ (DV_ERR_BASE + 17)
      ;* device is allocated *
      DV_ERR_ALLOCATED equ (DV_ERR_BASE + 18)
      DV_ERR_BADDEVICEID equ (DV_ERR_BASE + 19)
      DV_ERR_INVALHANDLE equ (DV_ERR_BASE + 20)
      DV_ERR_BADERRNUM equ (DV_ERR_BASE + 21)
      ;* out of buffers *
      DV_ERR_NO_BUFFERS equ (DV_ERR_BASE + 22)
      ;* Mem conflict detected *
      DV_ERR_MEM_CONFLICT equ (DV_ERR_BASE + 23)
      ;* I/O conflict detected *
      DV_ERR_IO_CONFLICT equ (DV_ERR_BASE + 24)
      ;* DMA conflict detected *
      DV_ERR_DMA_CONFLICT equ (DV_ERR_BASE + 25)
      ;* Interrupt conflict detected *
      DV_ERR_INT_CONFLICT equ (DV_ERR_BASE + 26)
      ;* Can not run in standard mode *
      DV_ERR_PROTECT_ONLY equ (DV_ERR_BASE + 27)
      DV_ERR_LASTERROR equ (DV_ERR_BASE + 27)
      ;#define DV_IDS_PROFILING        (DV_ERR_BASE + 900)
      ;#define DV_IDS_LISTBOX          (DV_ERR_BASE + 901)
      ;* Hardware specific errors *
      DV_ERR_USER_MSG equ (DV_ERR_BASE + 1000)
      ;****************************************************************************
      ;Callback Messages
      ;Note that the values for all installable driver callback messages are
      ;identical, (ie. MM_DRVM_DATA has the same value for capture drivers,
      ;installable video codecs, and the audio compression manager).
      ;****************************************************************************
      ifndef _RCINVOKED
        ifndef MM_DRVM_OPEN
          MM_DRVM_OPEN equ 3D0h
          MM_DRVM_CLOSE equ 3D1h
          MM_DRVM_DATA equ 3D2h
          MM_DRVM_ERROR equ 3D3h
        endif
        DV_VM_OPEN equ <MM_DRVM_OPEN>; Obsolete messages

        DV_VM_CLOSE equ <MM_DRVM_CLOSE>
        DV_VM_DATA equ <MM_DRVM_DATA>
        DV_VM_ERROR equ <MM_DRVM_ERROR>
        ;****************************************************************************
        ;Structures
        ;****************************************************************************
        ;* video data block header *
        VIDEOHDR struct
          lpData LPBYTE ?
          ;* pointer to locked data buffer *
          dwBufferLength DWORD ?
          ;* Length of data buffer *
          dwBytesUsed DWORD ?
          ;* Bytes actually used *
          dwTimeCaptured DWORD ?
          ;* Milliseconds from start of stream *
          dwUser XWORD ?
          ;* for client's use *
          dwFlags DWORD ?
          ;* assorted flags (see defines) *
          dwReserved XWORD 4 dup (?)
          ;* reserved for driver *
        VIDEOHDR ends
        videohdr_tag typedef VIDEOHDR
        PVIDEOHDR typedef ptr VIDEOHDR
        LPVIDEOHDR typedef ptr VIDEOHDR
        ;* dwFlags field of VIDEOHDR *
        ;* Done bit *
        VHDR_DONE equ 00000001h
        ;* Set if this header has been prepared *
        VHDR_PREPARED equ 00000002h
        ;* Reserved for driver *
        VHDR_INQUEUE equ 00000004h
        ;* Key Frame *
        VHDR_KEYFRAME equ 00000008h
        ;* valid flags ** ;Internal *
        VHDR_VALID equ 0000000Fh
        ;* Channel capabilities structure *
        CHANNEL_CAPS struct
          dwFlags DWORD ?
          ;* Capability flags*
          dwSrcRectXMod DWORD ?
          ;* Granularity of src rect in x *
          dwSrcRectYMod DWORD ?
          ;* Granularity of src rect in y *
          dwSrcRectWidthMod DWORD ?
          ;* Granularity of src rect width *
          dwSrcRectHeightMod DWORD ?
          ;* Granularity of src rect height *
          dwDstRectXMod DWORD ?
          ;* Granularity of dst rect in x *
          dwDstRectYMod DWORD ?
          ;* Granularity of dst rect in y *
          dwDstRectWidthMod DWORD ?
          ;* Granularity of dst rect width *
          dwDstRectHeightMod DWORD ?
          ;* Granularity of dst rect height *
        CHANNEL_CAPS ends
        channel_caps_tag typedef CHANNEL_CAPS
        PCHANNEL_CAPS typedef ptr CHANNEL_CAPS
        LPCHANNEL_CAPS typedef ptr CHANNEL_CAPS
        ;* dwFlags of CHANNEL_CAPS *
        ;* overlay channel *
        VCAPS_OVERLAY equ 00000001h
        ;* src rect can clip *
        VCAPS_SRC_CAN_CLIP equ 00000002h
        ;* dst rect can clip *
        VCAPS_DST_CAN_CLIP equ 00000004h
        ;* allows src != dst *
        VCAPS_CAN_SCALE equ 00000008h
        ;****************************************************************************
        ;API Flags
        ;****************************************************************************
        ; Types of channels to open with the videoOpen function
        VIDEO_EXTERNALIN equ 0001h
        VIDEO_EXTERNALOUT equ 0002h
        VIDEO_IN equ 0004h
        VIDEO_OUT equ 0008h
        ; Is a driver dialog available for this channel?
        VIDEO_DLG_QUERY equ 0010h
        ; videoConfigure (both GET and SET)
        VIDEO_CONFIGURE_QUERY equ 8000h
        ; videoConfigure (SET only)
        VIDEO_CONFIGURE_SET equ 1000h
        ; videoConfigure (GET only)
        VIDEO_CONFIGURE_GET equ 2000h
        VIDEO_CONFIGURE_QUERYSIZE equ 0001h
        VIDEO_CONFIGURE_CURRENT equ 0010h
        VIDEO_CONFIGURE_NOMINAL equ 0020h
        VIDEO_CONFIGURE_MIN equ 0040h
        VIDEO_CONFIGURE_MAX equ 0080h
        ;****************************************************************************
        ;CONFIGURE MESSAGES
        ;****************************************************************************
        DVM_USER equ 4000h
        DVM_CONFIGURE_START equ 1000h
        DVM_CONFIGURE_END equ 1FFFh
        DVM_PALETTE equ (DVM_CONFIGURE_START + 1)
        DVM_FORMAT equ (DVM_CONFIGURE_START + 2)
        DVM_PALETTERGB555 equ (DVM_CONFIGURE_START + 3)
        DVM_SRC_RECT equ (DVM_CONFIGURE_START + 4)
        DVM_DST_RECT equ (DVM_CONFIGURE_START + 5)
        ;* ifndef _RCINVOKED *
      endif
      ;* NOVIDEO *
    endif
    ;****************************************************************************
    ;*
    ;*  AVICAP - Window class for AVI capture
    ;*
    ;***************************************************************************
    ifndef NOAVICAP
      ifdef __cplusplus
        ;[...]
      else
        ;* SendMessage in C *
        AVICapSM macro hwnd, m, w, l
          exitm <((IsWindow (hwnd)) ? SendMessage (hwnd, m, w, l) : 0)>
        endm
        ;* __cplusplus *
      endif
      ifndef RC_INVOKED
        ; ------------------------------------------------------------------
        ;  Window Messages  WM_CAP... which can be sent to an AVICAP window
        ; ------------------------------------------------------------------
        ; UNICODE
        ; The Win32 version of AVICAP on NT supports UNICODE applications:
        ; for each API or message that takes a char or string parameter, there are
        ; two versions, ApiNameA and ApiNameW. The default name ApiName is #defined
        ; to one or other depending on whether UNICODE is defined. Apps can call
        ; the A and W apis directly, and mix them.
        ; The 32-bit AVICAP on NT uses unicode exclusively internally.
        ; ApiNameA() will be implemented as a call to ApiNameW() together with
        ; translation of strings.
        ; Defines start of the message range
        WM_CAP_START equ <WM_USER>
        ; start of unicode messages
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
        ; out of order to save on ifdefs
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
        ; Following added post VFW 1.1
        WM_CAP_SET_CALLBACK_CAPCONTROL equ (WM_CAP_START + 85)
        ; Defines end of the message range
        WM_CAP_UNICODE_END equ <WM_CAP_PAL_SAVEW>
        WM_CAP_END equ <WM_CAP_UNICODE_END>
        ; ------------------------------------------------------------------
        ;  Message crackers for above
        ; ------------------------------------------------------------------
        ; message wrapper macros are defined for the default messages only. Apps
        ; that wish to mix Ansi and UNICODE message sending will have to
        ; reference the _A and _W messages directly
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
        ; ------------------------------------------------------------------
        ;  Structures
        ; ------------------------------------------------------------------
        CAPDRIVERCAPS struct
          wDeviceIndex DWORD ?
          ; Driver index in system.ini
          fHasOverlay DWORD ?
          ; Can device overlay?
          fHasDlgVideoSource DWORD ?
          ; Has Video source dlg?
          fHasDlgVideoFormat DWORD ?
          ; Has Format dlg?
          fHasDlgVideoDisplay DWORD ?
          ; Has External out dlg?
          fCaptureInitialized DWORD ?
          ; Driver ready to capture?
          fDriverSuppliesPalettes DWORD ?
          ; Can driver make palettes?
          ; following always NULL on Win32.
          hVideoIn HANDLE ?
          ; Driver In channel
          hVideoOut HANDLE ?
          ; Driver Out channel
          hVideoExtIn HANDLE ?
          ; Driver Ext In channel
          hVideoExtOut HANDLE ?
          ; Driver Ext Out channel
        CAPDRIVERCAPS ends
        tagCapDriverCaps typedef CAPDRIVERCAPS
        PCAPDRIVERCAPS typedef ptr CAPDRIVERCAPS
        LPCAPDRIVERCAPS typedef ptr CAPDRIVERCAPS
        CAPSTATUS struct
          uiImageWidth DWORD ?
          ; Width of the image
          uiImageHeight DWORD ?
          ; Height of the image
          fLiveWindow DWORD ?
          ; Now Previewing video?
          fOverlayWindow DWORD ?
          ; Now Overlaying video?
          fScale_ DWORD ?
          ; Scale image to client?
          ptScroll POINT <>
          ; Scroll position
          fUsingDefaultPalette DWORD ?
          ; Using default driver palette?
          fAudioHardware DWORD ?
          ; Audio hardware present?
          fCapFileExists DWORD ?
          ; Does capture file exist?
          dwCurrentVideoFrame DWORD ?
          ; # of video frames cap'td
          dwCurrentVideoFramesDropped DWORD ?
          ; # of video frames dropped
          dwCurrentWaveSamples DWORD ?
          ; # of wave samples cap'td
          dwCurrentTimeElapsedMS DWORD ?
          ; Elapsed capture duration
          hPalCurrent HPALETTE ?
          ; Current palette in use
          fCapturingNow DWORD ?
          ; Capture in progress?
          dwReturn DWORD ?
          ; Error value after any operation
          wNumVideoAllocated DWORD ?
          ; Actual number of video buffers
          wNumAudioAllocated DWORD ?
          ; Actual number of audio buffers
        CAPSTATUS ends
        tagCapStatus typedef CAPSTATUS
        PCAPSTATUS typedef ptr CAPSTATUS
        LPCAPSTATUS typedef ptr CAPSTATUS
        ; Default values in parenthesis
        CAPTUREPARMS struct
          dwRequestMicroSecPerFrame DWORD ?
          ; Requested capture rate
          fMakeUserHitOKToCapture DWORD ?
          ; Show "Hit OK to cap" dlg?
          wPercentDropForError DWORD ?
          ; Give error msg if > (10%)
          fYield DWORD ?
          ; Capture via background task?
          dwIndexSize DWORD ?
          ; Max index size in frames (32K)
          wChunkGranularity DWORD ?
          ; Junk chunk granularity (2K)
          fUsingDOSMemory DWORD ?
          ; Use DOS buffers?
          wNumVideoRequested DWORD ?
          ; # video buffers, If 0, autocalc
          fCaptureAudio DWORD ?
          ; Capture audio?
          wNumAudioRequested DWORD ?
          ; # audio buffers, If 0, autocalc
          vKeyAbort DWORD ?
          ; Virtual key causing abort
          fAbortLeftMouse DWORD ?
          ; Abort on left mouse?
          fAbortRightMouse DWORD ?
          ; Abort on right mouse?
          fLimitEnabled DWORD ?
          ; Use wTimeLimit?
          wTimeLimit DWORD ?
          ; Seconds to capture
          fMCIControl DWORD ?
          ; Use MCI video source?
          fStepMCIDevice DWORD ?
          ; Step MCI device?
          dwMCIStartTime DWORD ?
          ; Time to start in MS
          dwMCIStopTime DWORD ?
          ; Time to stop in MS
          fStepCaptureAt2x DWORD ?
          ; Perform spatial averaging 2x
          wStepCaptureAverageFrames DWORD ?
          ; Temporal average n Frames
          dwAudioBufferSize DWORD ?
          ; Size of audio bufs (0 = default)
          fDisableWriteCache DWORD ?
          ; Attempt to disable write cache
          AVStreamMaster DWORD ?
          ; Which stream controls length?
        CAPTUREPARMS ends
        tagCaptureParms typedef CAPTUREPARMS
        PCAPTUREPARMS typedef ptr CAPTUREPARMS
        LPCAPTUREPARMS typedef ptr CAPTUREPARMS
        ; ------------------------------------------------------------------
        ;  AVStreamMaster
        ;  Since Audio and Video streams generally use non-synchronized capture
        ;  clocks, this flag determines whether the audio stream is to be considered
        ;  the master or controlling clock when writing the AVI file:
        ;  AVSTREAMMASTER_AUDIO  - Audio is master, video frame duration is forced
        ;                          to match audio duration (VFW 1.0, 1.1 default)
        ;  AVSTREAMMASTER_NONE   - No master, audio and video streams may be of
        ;                          different lengths
        ; ------------------------------------------------------------------
        ;* Audio master (VFW 1.0, 1.1) *
        AVSTREAMMASTER_AUDIO equ 0
        ;* No master *
        AVSTREAMMASTER_NONE equ 1
        CAPINFOCHUNK struct
          fccInfoID FOURCC ?
          ; Chunk ID, "ICOP" for copyright
          lpData POINTER ?
          ; pointer to data
          cbData SDWORD ?
          ; size of lpData
        CAPINFOCHUNK ends
        tagCapInfoChunk typedef CAPINFOCHUNK
        PCAPINFOCHUNK typedef ptr CAPINFOCHUNK
        LPCAPINFOCHUNK typedef ptr CAPINFOCHUNK
        ; ------------------------------------------------------------------
        ;  Callback Definitions
        ; ------------------------------------------------------------------
        STD_METHOD CAPYIELDCALLBACK, :HWND
        STD_METHOD CAPSTATUSCALLBACKW, :HWND, :SDWORD, :LPCWSTR
        STD_METHOD CAPERRORCALLBACKW, :HWND, :SDWORD, :LPCWSTR
        STD_METHOD CAPSTATUSCALLBACKA, :HWND, :SDWORD, :LPCSTR
        STD_METHOD CAPERRORCALLBACKA, :HWND, :SDWORD, :LPCSTR
        ifdef UNICODE
          CAPSTATUSCALLBACK equ <CAPSTATUSCALLBACKW>
          CAPERRORCALLBACK equ <CAPERRORCALLBACKW>
        else
          CAPSTATUSCALLBACK equ <CAPSTATUSCALLBACKA>
          CAPERRORCALLBACK equ <CAPERRORCALLBACKA>
        endif
        STD_METHOD CAPVIDEOCALLBACK, :HWND, :LPVIDEOHDR
        STD_METHOD CAPWAVECALLBACK, :HWND, :LPWAVEHDR
        STD_METHOD CAPCONTROLCALLBACK, :HWND, :SDWORD
        ; ------------------------------------------------------------------
        ;  CapControlCallback states
        ; ------------------------------------------------------------------
        ;* Waiting to start capture *
        CONTROLCALLBACK_PREROLL equ 1
        ;* Now capturing *
        CONTROLCALLBACK_CAPTURING equ 2
        ; ------------------------------------------------------------------
        ;  The only exported functions from AVICAP.DLL
        ; ------------------------------------------------------------------
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
        ;* RC_INVOKED *
      endif
      ; ------------------------------------------------------------------
      ; New Information chunk IDs
      ; ------------------------------------------------------------------
      infotypeDIGITIZATION_TIME equ <mmioFOURCC('I', 'D', 'I', 'T')>
      infotypeSMPTE_TIME equ <mmioFOURCC('I', 'S', 'M', 'P')>
      ; ------------------------------------------------------------------
      ; String IDs from status and error callbacks
      ; ------------------------------------------------------------------
      ;* "Capture Start" *
      IDS_CAP_BEGIN equ 300
      ;* "Capture End" *
      IDS_CAP_END equ 301
      ;* "%s" *
      IDS_CAP_INFO equ 401
      ;* "Out of memory" *
      IDS_CAP_OUTOFMEM equ 402
      ;* "File '%s' exists -- overwrite it?" *
      IDS_CAP_FILEEXISTS equ 403
      ;* "Error opening palette '%s'" *
      IDS_CAP_ERRORPALOPEN equ 404
      ;* "Error saving palette '%s'" *
      IDS_CAP_ERRORPALSAVE equ 405
      ;* "Error saving frame '%s'" *
      IDS_CAP_ERRORDIBSAVE equ 406
      ;* "avi" *
      IDS_CAP_DEFAVIEXT equ 407
      ;* "pal" *
      IDS_CAP_DEFPALEXT equ 408
      ;* "Cannot open '%s'" *
      IDS_CAP_CANTOPEN equ 409
      ;* "Select OK to start capture\nof video sequence\nto %s." *
      IDS_CAP_SEQ_MSGSTART equ 410
      ;* "Hit ESCAPE or click to end capture" *
      IDS_CAP_SEQ_MSGSTOP equ 411
      ;* "An error occurred while trying to run VidEdit." *
      IDS_CAP_VIDEDITERR equ 412
      ;* "The file '%s' is a read-only file." *
      IDS_CAP_READONLYFILE equ 413
      ;* "Unable to write to file '%s'.\nDisk may be full." *
      IDS_CAP_WRITEERROR equ 414
      ;* "There is no space to create a capture file on the specified device." *
      IDS_CAP_NODISKSPACE equ 415
      ;* "Set File Size" *
      IDS_CAP_SETFILESIZE equ 416
      ;* "SaveAs: %2ld%%  Hit Escape to abort." *
      IDS_CAP_SAVEASPERCENT equ 417
      ;* Driver specific error message *
      IDS_CAP_DRIVER_ERROR equ 418
      ;* "Error: Cannot open the wave input device.\nCheck sample size, frequency, and channels." *
      IDS_CAP_WAVE_OPEN_ERROR equ 419
      ;* "Error: Out of memory for wave buffers." *
      IDS_CAP_WAVE_ALLOC_ERROR equ 420
      ;* "Error: Cannot prepare wave buffers." *
      IDS_CAP_WAVE_PREPARE_ERROR equ 421
      ;* "Error: Cannot add wave buffers." *
      IDS_CAP_WAVE_ADD_ERROR equ 422
      ;* "Error: Bad wave size." *
      IDS_CAP_WAVE_SIZE_ERROR equ 423
      ;* "Error: Cannot open the video input device." *
      IDS_CAP_VIDEO_OPEN_ERROR equ 424
      ;* "Error: Out of memory for video buffers." *
      IDS_CAP_VIDEO_ALLOC_ERROR equ 425
      ;* "Error: Cannot prepare video buffers." *
      IDS_CAP_VIDEO_PREPARE_ERROR equ 426
      ;* "Error: Cannot add video buffers." *
      IDS_CAP_VIDEO_ADD_ERROR equ 427
      ;* "Error: Bad video size." *
      IDS_CAP_VIDEO_SIZE_ERROR equ 428
      ;* "Error: Cannot open capture file." *
      IDS_CAP_FILE_OPEN_ERROR equ 429
      ;* "Error: Cannot write to capture file.  Disk may be full." *
      IDS_CAP_FILE_WRITE_ERROR equ 430
      ;* "Error: Cannot write to capture file.  Data rate too high or disk full." *
      IDS_CAP_RECORDING_ERROR equ 431
      ;* "Error while recording" *
      IDS_CAP_RECORDING_ERROR2 equ 432
      ;* "Error: Unable to initialize for capture." *
      IDS_CAP_AVI_INIT_ERROR equ 433
      ;* "Warning: No frames captured.\nConfirm that vertical sync interrupts\nare configured and enabled." *
      IDS_CAP_NO_FRAME_CAP_ERROR equ 434
      ;* "Warning: Using default palette." *
      IDS_CAP_NO_PALETTE_WARN equ 435
      ;* "Error: Unable to access MCI device." *
      IDS_CAP_MCI_CONTROL_ERROR equ 436
      ;* "Error: Unable to step MCI device." *
      IDS_CAP_MCI_CANT_STEP_ERROR equ 437
      ;* "Error: No audio data captured.\nCheck audio card settings." *
      IDS_CAP_NO_AUDIO_CAP_ERROR equ 438
      ;* "Error: Unable to draw this data format." *
      IDS_CAP_AVI_DRAWDIB_ERROR equ 439
      ;* "Error: Unable to initialize compressor." *
      IDS_CAP_COMPRESSOR_ERROR equ 440
      ;* "Error: Audio data was lost during capture, reduce capture rate." *
      IDS_CAP_AUDIO_DROP_ERROR equ 441
      ;* "Error: Audio data was lost during capture.  Try capturing without compressing." *
      IDS_CAP_AUDIO_DROP_COMPERROR equ 442
      ;* status string IDs *
      ;* "Live window" *
      IDS_CAP_STAT_LIVE_MODE equ 500
      ;* "Overlay window" *
      IDS_CAP_STAT_OVERLAY_MODE equ 501
      ;* "Setting up for capture - Please wait" *
      IDS_CAP_STAT_CAP_INIT equ 502
      ;* "Finished capture, now writing frame %ld" *
      IDS_CAP_STAT_CAP_FINI equ 503
      ;* "Building palette map" *
      IDS_CAP_STAT_PALETTE_BUILD equ 504
      ;* "Computing optimal palette" *
      IDS_CAP_STAT_OPTPAL_BUILD equ 505
      ;* "%d frames" *
      IDS_CAP_STAT_I_FRAMES equ 506
      ;* "%ld frames" *
      IDS_CAP_STAT_L_FRAMES equ 507
      ;* "Captured %ld frames" *
      IDS_CAP_STAT_CAP_L_FRAMES equ 508
      ;* "Capturing audio" *
      IDS_CAP_STAT_CAP_AUDIO equ 509
      ;* "Captured %ld frames (%ld dropped) %d.%03d sec." *
      IDS_CAP_STAT_VIDEOCURRENT equ 510
      ;* "Captured %d.%03d sec.  %ld frames (%ld dropped) (%d.%03d fps).  %ld audio bytes (%d,%03d sps)" *
      IDS_CAP_STAT_VIDEOAUDIO equ 511
      ;* "Captured %d.%03d sec.  %ld frames (%ld dropped) (%d.%03d fps)" *
      IDS_CAP_STAT_VIDEOONLY equ 512
      ;* "Dropped %ld of %ld frames (%d.%02d%%) during capture." *
      IDS_CAP_STAT_FRAMESDROPPED equ 513
      ;* NOAVIFILE *
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*
    ;*  ACM (Audio compression manager)
    ;*
    ;***************************************************************************
    ifndef NOMSACM
      include msacm.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;****************************************************************************
    ;*
    ;*  FilePreview dialog.
    ;*
    ;***************************************************************************
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
    ; OFN_READONLY
    ifndef RC_INVOKED
      include poppack.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _INC_VFW *
endif
