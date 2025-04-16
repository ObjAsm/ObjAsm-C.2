; ==================================================================================================
; Title:      GifPlayer.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of GIF objects.
; Notes:      Version C.1.0, October 2017
;               - First relese.
; ==================================================================================================


GifPlayerState  record  GPS_Unused:6 = 0, GPS_Resource:1 = FALSE, GPS_FirstDraw:1 = TRUE

; --------------------------------------------------------------------------------------------------
; Object:     GifPlayer
; Purpose:    This object is designed to play an animated GIF resource or file on a window. It uses
;             the GifDecoder object to restore the compressed picture binary data.
;             The GIF (Graphics Interchange Format) is the Copyright property of CompuServe Inc.
;             The Unisys LZW patent expired June 20th, 2003 in the USA and one year later
;             (July 7th, 2004) in the rest of the world.
;
;             Supported features:
;               - 2, 4, 8, 16, 32, 64, 128 and 256 color gifs.
;               - Outputting data as monochrome, 16 and 256 color bitmaps.
;
;             Not supported features:
;               - Interlaced gifs.
;               - Non-image drawing extensions (plain text extension).

Object GifPlayer, GifPlayerID, WinPrimer
  VirtualMethod     BreakoutFrames, POINTER, DWORD
  VirtualMethod     Dispatch,       HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, POINTER, SDWORD, SDWORD, DWORD, DWORD, XWORD
  VirtualMethod     InitRes,        HWND
  VirtualMethod     LoadResData,    HANDLE, POINTER
  VirtualMethod     LoadFileData,   PSTRING
  StaticMethod      Startup
  VirtualMethod     WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnDestroy,      WM_DESTROY
  VirtualEvent      OnEnable,       WM_ENABLE
  VirtualEvent      OnPaint,        WM_PAINT
  VirtualEvent      OnTimer,        WM_TIMER

  DefineVariable    ClientRect,     RECT,       {}          ;Client Rect
  DefineVariable    hBackDC,        HDC,        0           ;Memory background DC
  DefineVariable    hBackBmp,       HBITMAP,    0           ;Background bitmap
  DefineVariable    hPrevBackBmp,   HBITMAP,    0           ;Previous hBackDC bitmap
  DefineVariable    hGifDC,         HDC,        0           ;Gif DC
  DefineVariable    hGifBmp,        HBITMAP,    0           ;Work bitmap
  DefineVariable    hPrevGifBmp,    HBITMAP,    0           ;Previous hGifDC bitmap
  DefineVariable    hMemDC,         HDC,        0           ;Memory DC
  DefineVariable    hMemBmp,        HBITMAP,    0           ;Work bitmap
  DefineVariable    hPrevMemBmp,    HBITMAP,    0           ;Previous hMemDC bitmap
  DefineVariable    hTimer,         HANDLE,     0           ;Timer handle
  DefineVariable    dCurrFrame,     DWORD,      -1          ;Current frame
  DefineVariable    dState,         DWORD,      00000001y   ;TRUE for first Paint action

  Embed   FrameColl,  Collection                            ;Collection of GifFrame objects
ObjectEnd


Object GifFrame, GifFrameID, Streamable
  RedefineMethod    Done

  DefineVariable    hBmp,                 HBITMAP,  0
  DefineVariable    dLeft,                DWORD,    0
  DefineVariable    dTop,                 DWORD,    0
  DefineVariable    dDelayTime,           DWORD,    0
  DefineVariable    bDisposalMethod,      BYTE,     0
  DefineVariable    bHasTransparency,     BYTE,     FALSE
  DefineVariable    TransparentColor,     COLORREF, $RGB(000,000,000)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

GIFPLAYSERSTYLE equ WS_CHILD or WS_CHILDWINDOW or WS_CLIPSIBLINGS or WS_VISIBLE

GIF_EXTENSIONINTRODUCER     equ     021h        ;033 = "!"
GIF_IMAGEDESCRIPTOR         equ     02Ch        ;044 = ","
GIF_TRAILER                 equ     03Bh        ;059 = ";"
GIF_PLAINTEXTEXTENSION      equ     001h        ;001
GIF_GRAPHICCONTROLEXTENSION equ     0F9h        ;249
GIF_COMMENTEXTENSION        equ     0FEh        ;254
GIF_APPLICATIONEXTENSION    equ     0FFh        ;255

GIF_TIMER_ID                equ     1AB592DFh   ;Random number

BI_RGB                      equ     0
BI_RLE8                     equ     1
BI_RLE4                     equ     2
BI_BITFIELDS                equ     3

CStr szGifPlayer, "GifPlayer"

.code

GifBinRead macro Var:req, VarSize:req
  ifidn <VarSize>, <1>
    mov al, [xdi]
    ifdifi <Var>, <al>
      mov Var, al
    endif
    inc xdi
  elseifidn <VarSize>, <2>
    mov ax, [xdi]
    ifdifi <Var>, <ax>
      mov Var, ax
    endif
    add xdi, 2
  elseifidn <VarSize>, <4>
    mov eax, [xdi]
    ifdifi <Var>, <eax>
      mov Var, eax
    endif
    add xdi, 4
  else
    invoke MemClone, addr Var, xdi, VarSize
    add xdi, VarSize
  endif
endm

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.BreakoutFrames
; Purpose:    Decode all frames in the data stream.
; Arguments:  Arg1: -> Data.
;             Arg2: Data size.
; Return:     Nothing.

BITMAP_INFO struc
  BmpInfoHeader   BITMAPINFOHEADER  {?}
  ColorTable      RGBQUAD           256 dup({?})
BITMAP_INFO ends

Method GifPlayer.BreakoutFrames, uses xbx xdi xsi, pData:POINTER, dDataSize:DWORD
  local bPackedFields:BYTE, pResEnd:POINTER, wBitsPerPixel:WORD
  local pGlobalColorTable:POINTER, dGlobalColorTableEntries:DWORD
  local pLocalColorTable:POINTER, dLocalColorTableEntries:DWORD
  local bTranspColorIndex:BYTE, pBuffer:POINTER, dBufferSize:DWORD
  local wLogWidth:WORD, wLogHeight:WORD, dAlignedWidth:DWORD
  local wImgWidth:WORD, wImgHeight:WORD
  local bBgColorIndex:BYTE, bPxAspectRatio:BYTE
  local bDescriptor:BYTE, bExtensionType:BYTE, bInterlacedFlag:BYTE
  local pSrc:POINTER, pWorkBuffer:POINTER, dCounter:DWORD, dImgHeight:DWORD
  local BmpInfo:BITMAP_INFO
  local dColorTableEntries:DWORD, dFormat:DWORD         ;Image format (IMAGEFORMAT_XXXXX)
  local Decoder:$Obj(GifDecoder)

  SetObject xsi
  New Decoder::GifDecoder
  OCall Decoder::GifDecoder.Init, xsi
  mov xdi, pData
  invoke StrCICompA, xdi, $OfsCStrA("GIF87A"), 6
  .if xax != 0
    invoke StrCICompA, xdi, $OfsCStrA("GIF89A"), 6
    .if xax != 0
      OCall xsi.ErrorReport, NULL, GIF_WRONG_SIGNATURE
      jmp @@Exit
    .endif
  .endif
  add xdi, 6                                            ;sizeof signature "GIF89A"

  GifBinRead wLogWidth, 2
  GifBinRead wLogHeight, 2
  GifBinRead bPackedFields, 1

  mov al, bPackedFields
  and eax, 00000000011100000b
  shr eax, 5
  lea eax, [eax + 2*eax + 3]
  mov wBitsPerPixel, ax

  GifBinRead bBgColorIndex, 1
  GifBinRead bPxAspectRatio, 1                          ;Not used

  .ifBitSet bPackedFields, BIT07                        ;GlobalColorTableFlag
    mov pGlobalColorTable, xdi
    mov cl, bPackedFields
    and cl, 00000111b
    inc cl
    mov xax, 1
    shl xax, cl
    mov dGlobalColorTableEntries, eax                   ;2 ^ (TableSizeExp + 1)
    lea xax, [xax + 2*xax]                              ;3*eax
    add xdi, xax                                        ;Skip over
  .else
    m2z pGlobalColorTable
  .endif

  mov eax, dDataSize
  add xax, pData
  mov pResEnd, xax

  xor ebx, ebx
  .repeat
    .if xdi > pResEnd
      OCall xsi.ErrorReport, NULL, GIF_FORMAT_ERROR
      .break
    .endif

    GifBinRead bDescriptor, 1                           ;Read Descriptor

    .if bDescriptor ==  GIF_IMAGEDESCRIPTOR
      .if xbx == NULL
        mov xbx, $New(GifFrame)
        OCall xax::GifFrame.Init, xsi
      .endif

      xor eax, eax
      GifBinRead ax, 2                                  ;wImgLeft
      mov [xbx].$Obj(GifFrame).dLeft, eax
      GifBinRead ax, 2                                  ;wImgTop
      mov [xbx].$Obj(GifFrame).dTop, eax
      GifBinRead wImgWidth, 2
      GifBinRead wImgHeight, 2
      GifBinRead bPackedFields, 1

      .ifBitSet bPackedFields, BIT07                    ;LocalColorTableFlag
        mov pLocalColorTable, xdi
        mov cl, bPackedFields
        and cl, 00000111b
        inc cl
        mov xax, 1
        shl xax, cl
        mov dLocalColorTableEntries, eax                ;2 ^ (TableSizeExp + 1)
        lea xax, [xax + 2*xax]                          ;* 3
        add xdi, xax                                    ;Skip over
      .else
        m2z pLocalColorTable
      .endif

      m2z bInterlacedFlag
      .ifBitSet bPackedFields, BIT06                    ;InterlacedFlag
        inc bInterlacedFlag
      .endif

      ;------ Build the color table ------------------
      .if pLocalColorTable != NULL
        mov xcx, pLocalColorTable
        mov edx, dLocalColorTableEntries
      .elseif pGlobalColorTable != NULL
        mov xcx, pGlobalColorTable
        mov edx, dGlobalColorTableEntries
      .else
        OCall xsi.ErrorReport, NULL, GIF_MISSING_COLOR_TABLE
        jmp @@Exit
      .endif
      mov dColorTableEntries, edx

      .if edx == 2
        mov  eax, GIF_IMAGEFORMAT_1BIT
      .elseif edx <= 16
        mov eax, GIF_IMAGEFORMAT_4BIT
      .else
        mov eax, GIF_IMAGEFORMAT_8BIT
      .endif
      mov dFormat, eax

      xor edx, edx
      .while edx < dColorTableEntries
        mov eax, [xcx]                                  ;RR GG BB ?? => eax: ?? BB GG RR
        bswap eax                                       ;eax: RR GG BB ??
        shr eax, 8                                      ;eax: 00 RR GG BB (RGBQUAD)
        mov BmpInfo.ColorTable[sizeof(RGBQUAD)*xdx], eax
        add xcx, 3
        inc edx
      .endw

      .if [xbx].$Obj(GifFrame).bHasTransparency != FALSE
        xor ecx, ecx
        mov cl, bTranspColorIndex
        mov eax, BmpInfo.ColorTable[sizeof(RGBQUAD)*xcx]
        bswap eax                                       ;eax: RR GG BB ??
        shr eax, 8                                      ;eax: 00 RR GG BB (RGBQUAD)
        mov [xbx].$Obj(GifFrame).TransparentColor, eax
      .endif

      ;------ Set Bitmap information -----------------
      mov BmpInfo.BmpInfoHeader.biSize, sizeof(BITMAPINFOHEADER)
      movzx eax, wImgWidth
      mov BmpInfo.BmpInfoHeader.biWidth, eax
      movzx eax, wImgHeight
      neg eax                                           ;negative because it outputs a top-down bitmap
      mov BmpInfo.BmpInfoHeader.biHeight, eax
      mov BmpInfo.BmpInfoHeader.biPlanes, 1
      .if dFormat == GIF_IMAGEFORMAT_1BIT
        mov ax, 1
      .elseif dFormat == GIF_IMAGEFORMAT_4BIT
        mov ax, 4
      .else
        mov ax, 8
      .endif
      mov BmpInfo.BmpInfoHeader.biBitCount, ax
      mov BmpInfo.BmpInfoHeader.biCompression, BI_RGB
      m2z BmpInfo.BmpInfoHeader.biSizeImage
      m2z BmpInfo.BmpInfoHeader.biXPelsPerMeter
      m2z BmpInfo.BmpInfoHeader.biYPelsPerMeter
      m2m BmpInfo.BmpInfoHeader.biClrUsed, dColorTableEntries, eax
      m2z BmpInfo.BmpInfoHeader.biClrImportant

      ;------ Create a data buffer -------------------
      movzx eax, wImgWidth
      mov ecx, eax
      ;Get aligned width
      .if dFormat == GIF_IMAGEFORMAT_1BIT
        and ecx, 11111b
        .if ecx != 0
          shr eax, 5
          inc eax
          shl eax, 5                                    ;Get number of bytes
        .endif
      .elseif dFormat == GIF_IMAGEFORMAT_4BIT
        and ecx, 111b
        .if ecx != 0
          shr eax, 3
          inc eax
          shl eax, 3                                    ;Get number of bytes
        .endif
      .elseif dFormat == GIF_IMAGEFORMAT_8BIT
        and ecx, 11b
        .if ecx != 0
          shr eax, 2
          inc eax
          shl eax, 2                                    ;Get number of bytes
        .endif
      .endif
      mov dAlignedWidth, eax
      movzx ecx, wImgHeight
      mul ecx                                           ;Multiply output width by the number of scanlines
      mov dBufferSize, eax
      mov pBuffer, $MemAlloc(xax, MEM_INIT_ZERO)        ;Memory block must be zeroed!

      ;------ LZW decompression ----------------------
      movzx eax, wImgHeight
      mov dImgHeight, eax
      movzx eax, wImgWidth
      OCall Decoder::GifDecoder.Decode, xdi, pBuffer, dAlignedWidth, eax, dImgHeight, dFormat
      lea xdi, [xax + 1]

      ;------ Rearrange Interlaced image -------------
      .if bInterlacedFlag != FALSE
        mov pWorkBuffer, $MemAlloc(dBufferSize)
        m2m pSrc, pBuffer, xdx

        ;Pass 1: every 8th row, starting with 0
        mov dCounter, 0
        .repeat
          mov ecx, dCounter
          shl ecx, 3
          .break .if cx >= wImgHeight
          mov eax, dAlignedWidth
          mul ecx
          add xax, pWorkBuffer
          invoke MemClone, xax, pSrc, dAlignedWidth
          mov eax, dAlignedWidth
          add pSrc, xax
          inc dCounter
        .until FALSE

        ;Pass 2: every 8th row, startibg with 4
        mov dCounter, 0
        .repeat
          mov ecx, dCounter
          shl ecx, 3
          add ecx, 4
          .break .if cx >= wImgHeight
          mov eax, dAlignedWidth
          mul ecx
          add xax, pWorkBuffer
          invoke MemClone, xax, pSrc, dAlignedWidth
          mov eax, dAlignedWidth
          add pSrc, xax
          inc dCounter
        .until FALSE

        ;Pass 3: every 4th row, startibg with 2
        mov dCounter, 0
        .repeat
          mov ecx, dCounter
          shl ecx, 2
          inc ecx
          inc ecx
          .break .if cx >= wImgHeight
          mov eax, dAlignedWidth
          mul ecx
          add xax, pWorkBuffer
          invoke MemClone, xax, pSrc, dAlignedWidth
          mov eax, dAlignedWidth
          add pSrc, xax
          inc dCounter
        .until FALSE

        ;Pass 4: every 2nd row, startibg with 1
        mov dCounter, 0
        .repeat
          mov ecx, dCounter
          shl ecx, 1
          inc ecx
          .break .if cx >= wImgHeight
          mov eax, dAlignedWidth
          mul ecx
          add xax, pWorkBuffer
          invoke MemClone, xax, pSrc, dAlignedWidth
          mov eax, dAlignedWidth
          add pSrc, xax
          inc dCounter
        .until FALSE

        MemFree pBuffer
        m2m pBuffer, pWorkBuffer, xdx
      .endif

      ;------ Create a DDB ---------------------------
      lea xdx, BmpInfo.BmpInfoHeader
      invoke CreateDIBitmap, [xsi].hMemDC, xdx, CBM_INIT, pBuffer, xdx, DIB_RGB_COLORS
      mov [xbx].$Obj(GifFrame).hBmp, xax
      MemFree pBuffer

      OCall [xsi].FrameColl::Collection.Insert, xbx
      xor ebx, ebx

    .elseif bDescriptor == GIF_EXTENSIONINTRODUCER
      GifBinRead bExtensionType, 1
      .if bExtensionType == GIF_GRAPHICCONTROLEXTENSION
        mov xbx, $New(GifFrame)
        OCall xax::GifFrame.Init, xsi

        inc xdi                                         ;Skip block size
        GifBinRead bPackedFields, 1
        mov al, bPackedFields
        and al, 00111000b
        shr al, 3
        mov [xbx].$Obj(GifFrame).bDisposalMethod, al
        mov al, bPackedFields
        and al, 00000001b
        mov [xbx].$Obj(GifFrame).bHasTransparency, al

        xor eax, eax
        GifBinRead ax, 2                                ;in 1/100 sec
        add eax, eax
        lea eax, [eax + 4*eax]
        mov [xbx].$Obj(GifFrame).dDelayTime, eax        ;x 10 (in 1/1000 sec)

        GifBinRead bTranspColorIndex, 1
        inc xdi                                         ;Skip block terminator
      .elseif bExtensionType == GIF_APPLICATIONEXTENSION  ;Skip over
        xor eax, eax
        GifBinRead al, 1
        add xdi, xax
        .while BYTE ptr [xdi] != 0                      ;Skip data sub-blocks
          xor eax, eax
          GifBinRead al, 1
          add xdi, xax
        .endw
        inc xdi
      .elseif bExtensionType == GIF_COMMENTEXTENSION    ;Skip over
        xor eax, eax
        GifBinRead al, 1
        add xdi, xax
        .while BYTE ptr [xdi] != 0                      ;Skip data sub-blocks
          xor eax, eax
          GifBinRead al, 1
          add xdi, xax
        .endw
        inc xdi
      .elseif bExtensionType == GIF_PLAINTEXTEXTENSION  ;Skip over
        xor eax, eax
        GifBinRead al, 1
        add xdi, xax
        .while BYTE ptr [xdi] != 0                      ;Skip data sub-blocks
          xor eax, eax
          GifBinRead al, 1
          add xdi, xax
        .endw
        inc xdi
      .endif
    .elseif bDescriptor ==  GIF_TRAILER
      .break
    .else
      OCall xsi.ErrorReport, NULL, GIF_UNKNOWN_BLOCK
      .break
    .endif
  .until FALSE

@@Exit:
  OCall Decoder::GifDecoder.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.

Method GifPlayer.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.Done
; Purpose:    Finalize the GifPlayer object.
; Arguments:  None.
; Return:     Nothing.

Method GifPlayer.Done, uses xsi
  SetObject xsi
  invoke DestroyWindow, [xsi].hWnd
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.Init
; Purpose:    Initialize the GifPlayer object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Resource name.
;             Arg4: X position.
;             Arg5: Y position.
;             Arg6: Width.
;             Arg7: Height.
;             Arg8: Control ID.
; Return:     Nothing.

Method GifPlayer.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pResName:POINTER, \
                                     sdPosX:SDWORD, sdPosY:SDWORD, dWidth:DWORD, dHeight:DWORD, \
                                     xID:XWORD
  SetObject xsi
  ACall xsi.Init, pOwner, 0
  mov xbx, xID
  invoke CreateWindowEx, 0, offset szGifPlayer, pResName, GIFPLAYSERSTYLE, \
                         sdPosX, sdPosY, dWidth, dHeight, hParent, xbx, hInstance, pSelf
  mov [xsi].hWnd, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.InitRes
; Purpose:    Initialize the GifPlayer object when called from a ressource.
; Arguments:  Arg1: Window HANDLE.
; Return:     Nothing.

Method GifPlayer.InitRes,, hWnd:HWND
  SetObject xcx
  BitSet [xcx].dState, mask GPS_Resource
  ACall xcx.Init, NULL, hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.LoadResData
; Purpose:    Load GIF data from a "GIF" type resource.
; Arguments:  Arg1: Module instance handle where the resource is stored.
;             Arg2: -> resource name or resource ID.
; Return:     xax = HGLOBAL of a memory block that holds the GIF data.
;             ecx = Number of loaded bytes.

Method GifPlayer.LoadResData, uses xbx xdi xsi, hInst:HANDLE, pResName:POINTER
  SetObject xsi
  invoke FindResource, hInst, pResName, $OfsCStr("GIF")
  .if xax == 0
    OCall xsi.ErrorReport, NULL, GIF_RES_NOT_FOUND
    xor eax, eax
    xor ecx, ecx
  .else
    mov xbx, xax
    invoke LoadResource, hInst, xbx
    .if xax == 0
      OCall xsi.ErrorReport, NULL, GIF_RES_LOAD_ERROR
      xor eax, eax
      xor ecx, ecx
    .else
      mov xdi, xax
      invoke SizeofResource, hInst, xbx
      mov ecx, eax
      mov xax, xdi
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.LoadFileData
; Purpose:    Load GIF data from a file.
; Arguments:  Arg1: -> File name.
; Return:     xax -> Memory block that holds the GIF data.
;             ecx = Number of loaded bytes.

Method GifPlayer.LoadFileData, uses xdi xsi, pFileName:PSTRING
  local dBytesRead:DWORD, dFileSize:DWORD, hFile:HANDLE

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL
  .if xax == INVALID_HANDLE_VALUE
    OCall xsi.ErrorReport, NULL, GIF_FILE_NOT_FOUND
    xor eax, eax
    xor ecx, ecx
  .else
    mov hFile, xax
    invoke GetFileSizeEx, hFile, addr dFileSize
    .if xax == -1
      OCall xsi.ErrorReport, NULL, GIF_FILE_LOAD_ERROR
      invoke CloseHandle, hFile
      xor eax, eax
      xor ecx, ecx
    .else
      MemAlloc xax
      .if xax == 0
        OCall xsi.ErrorReport, NULL, GIF_OUT_OF_MEMORY
        invoke CloseHandle, hFile
        xor eax, eax
        xor ecx, ecx
      .else
        mov xdi, xax
        invoke ReadFile, hFile, xdi, dFileSize, addr dBytesRead, NULL
        mov ecx, dBytesRead
        .if (xax == NULL) || (ecx != dFileSize)
          OCall xsi.ErrorReport, NULL, GIF_FILE_LOAD_ERROR
          invoke CloseHandle, hFile
          xor eax, eax
          xor ecx, ecx
        .else
          invoke CloseHandle, hFile
          mov xax, xdi
          mov ecx, dBytesRead
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method GifPlayer.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local pData:POINTER, dDataSize:DWORD

  SetObject xsi
  OCall [xsi].FrameColl::Collection.Init, xsi, 10, 5, COL_MAX_CAPACITY
  mov xax, lParam
  mov xcx, [xax].CREATESTRUCT.lpszName
  OCall xsi.LoadResData, hInstance, [xax].CREATESTRUCT.lpszName
  .if [xsi].dErrorCode == OBJ_OK
    mov dDataSize, ecx
    mov pData, $invoke(LockResource, xax)

    invoke GetClientRect, [xsi].hWnd, addr [xsi].ClientRect
    mov xbx, $invoke(GetDC, [xsi].hWnd)

    ;Prepare for a background copy (see WM_PAINT)
    mov [xsi].hBackDC, $invoke(CreateCompatibleDC, xbx)
    invoke CreateCompatibleBitmap, xbx, [xsi].ClientRect.right, [xsi].ClientRect.bottom
    mov [xsi].hBackBmp, xax
    mov [xsi].hPrevBackBmp, $invoke(SelectObject, [xsi].hBackDC, [xsi].hBackBmp)

    ;Make a Gif DC
    mov [xsi].hGifDC, $invoke(CreateCompatibleDC, xbx)

    ;Make a work bitmap
    mov [xsi].hMemDC, $invoke(CreateCompatibleDC, xbx)
    invoke CreateCompatibleBitmap, xbx, [xsi].ClientRect.right, [xsi].ClientRect.bottom
    mov [xsi].hMemBmp, xax
    mov [xsi].hPrevMemBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)

    OCall xsi.BreakoutFrames, pData, dDataSize

    invoke ReleaseDC, [xsi].hWnd, xbx
;    invoke GetWindowLong, [xsi].hWnd, GWL_STYLE
;    .ifBitClr eax, WS_DISABLED                 ;Start Timer if control is active
;      invoke PostMessage, [xsi].hWnd, WM_TIMER, NULL, NULL
;    .endif
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GifPlayer.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if [xsi].hTimer != 0
    invoke KillTimer, [xsi].hWnd, GIF_TIMER_ID
    m2z [xsi].hTimer
  .endif
  OCall [xsi].FrameColl::Collection.Done
  invoke DeleteObject, [xsi].hBackBmp
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemBmp)
  invoke DeleteDC, [xsi].hMemDC
  invoke DeleteDC, [xsi].hBackDC
  invoke DeleteDC, [xsi].hGifDC
  invoke SetWindowLong, [xsi].hWnd, GWL_USERDATA, NULL

  ;Only if the GifPlayer was started from a resource, then autodestroy it.
  .ifBitSet [xsi].dState, mask GPS_Resource
    Destroy xsi
  .endif

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.OnEnable
; Purpose:    Event procedure for WM_ENABLE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method GifPlayer.OnEnable, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == FALSE                                   ;Disable
    .if [xsi].hTimer != 0
      invoke KillTimer, [xsi].hWnd, GIF_TIMER_ID
      m2z [xsi].hTimer
    .endif
  .else
    .if [xsi].hTimer == 0
      invoke PostMessage, [xsi].hWnd, WM_TIMER, GIF_TIMER_ID, NULL
    .endif
  .endif
  invoke DefWindowProc, [xsi].hWnd, WM_ENABLE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GifPlayer.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  .ifBitSet [xsi].dState, mask GPS_FirstDraw
    BitClr [xsi].dState, mask GPS_FirstDraw
    ;Make a copy of the background
    invoke BitBlt, [xsi].hBackDC, 0, 0, [xsi].ClientRect.right, [xsi].ClientRect.bottom,
                   PS.hdc, 0, 0, SRCCOPY
    invoke BitBlt, [xsi].hMemDC,  0, 0, [xsi].ClientRect.right, [xsi].ClientRect.bottom,
                   PS.hdc, 0, 0, SRCCOPY
    invoke GetWindowLong, [xsi].hWnd, GWL_STYLE
    .ifBitClr eax, WS_DISABLED                          ;Start Timer if control is active
      invoke PostMessage, [xsi].hWnd, WM_TIMER, GIF_TIMER_ID, NULL
    .endif
  .else
    invoke BitBlt, PS.hdc, PS.rcPaint.left, PS.rcPaint.top, PS.rcPaint.right, PS.rcPaint.bottom, \
                   [xsi].hMemDC, PS.rcPaint.left, PS.rcPaint.top, SRCCOPY
  .endif
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.OnTimer
; Purpose:    Event procedure for WM_TIMER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GifPlayer.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == GIF_TIMER_ID
    .if [xsi].FrameColl.dCount > 0

      ; - Stop timer -----------------------------------------------------------------------------
      .if [xsi].hTimer != 0
        invoke KillTimer, [xsi].hWnd, GIF_TIMER_ID
        m2z [xsi].hTimer
      .endif

      inc [xsi].dCurrFrame

      mov eax, [xsi].FrameColl.dCount
      .if eax == [xsi].dCurrFrame
        m2z [xsi].dCurrFrame                            ;Reset if past last frame
      .endif
      OCall [xsi].FrameColl::Collection.ItemAt, [xsi].dCurrFrame
      .if xax != NULL
        mov xdi, xax
        assume xdi:$ObjPtr(GifFrame)

        ; --- Action select ----------------------------------------------------------------------
        xor eax, eax
        mov al, [xdi].bDisposalMethod
        ;Case 0      ;Undefined
        ;Case 1      ;Leave => do nothing
        .if eax == 1 || eax == 2                        ;Restore Background
          invoke BitBlt, [xsi].hMemDC, 0, 0, [xsi].ClientRect.right, [xsi].ClientRect.bottom,
                         [xsi].hBackDC, 0, 0, SRCCOPY
        .elseif eax == 3                                ;Restore previous frame => not implemented
        .endif

        ; --- Bitmap drawing ---------------------------------------------------------------------
        mov xbx, $invoke(GetDC, [xsi].hWnd)
        .if [xdi].bHasTransparency != FALSE
;            invoke BitBlt, [xsi].hMemDC, 0, 0, [xsi].ClientRect.right, [xsi].ClientRect.bottom,
;                           [xsi].hBackDC, 0, 0, SRCCOPY
          invoke DrawTransparentBitmap, [xsi].hMemDC, [xdi].hBmp, [xdi].dLeft, [xdi].dTop, \
                                        [xdi].TransparentColor
        .else
          mov [xsi].hPrevGifBmp, $invoke(SelectObject, [xsi].hGifDC, [xdi].hBmp)
          invoke BitBlt, [xsi].hMemDC, [xdi].dLeft, [xdi].dTop, [xsi].ClientRect.right, \
                         [xsi].ClientRect.bottom, \
                         [xsi].hGifDC, 0, 0, SRCCOPY
          invoke SelectObject, [xsi].hGifDC, [xsi].hPrevGifBmp
        .endif
        invoke BitBlt, xbx, 0, 0, [xsi].ClientRect.right, [xsi].ClientRect.bottom,
                       [xsi].hMemDC, 0, 0, SRCCOPY
        invoke ReleaseDC, [xsi].hWnd, xbx
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE

        ; --- Restart timer ----------------------------------------------------------------------
        mov [xsi].hTimer, $invoke(SetTimer, [xsi].hWnd, GIF_TIMER_ID, [xdi].dDelayTime, NULL)
        assume xdi:NOTHING
      .endif
    .endif
  .endif

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.Startup
; Purpose:    Register the GifPlayer window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method GifPlayer.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(GifPlayer.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szGifPlayer, xax
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GifPlayer.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method GifPlayer.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;if lpCreateParams is NULL, then it is a resource call => create new object instance
      mov xsi, $New(GifPlayer)
      OCall xax::GifPlayer.InitRes, pSelf
      mov xcx, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      mrm [xsi].$Obj(GifPlayer).hWnd, pSelf, xcx        ;pSelf = hWnd
    .endif
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
    OCall xsi::GifPlayer.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLong returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::GifPlayer.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
  ret
MethodEnd


; ==================================================================================================
;    GifFrame implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     GifFrame.Done
; Purpose:    Finalize a GifFrame object and releases allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method GifFrame.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBmp
  ACall xsi.Done
MethodEnd

endif
