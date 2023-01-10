; ==================================================================================================
; Title:      Image.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Image objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Image
; Purpose:    This object is able to load BMP, GIF, JPEG, ICO, WMF, EMF, PNG, XBM, ICO, TIFF
;             images from files and resources.
; Notes:      - Required files:
;               % include &COMPath&COM.inc
;               % include &IncPath&Windows\IImgCtx.inc
;               % includelib &LibPath&Windows\Ole32.lib
;             - Initialization:   invoke CoInitialize, 0
;               Finalization:     invoke CoUninitialize
;             - This object is based on the ImgCtx functionality. There is very little information
;               about this interface on the net. The most important features about this interface,
;               is its ability to decode a wide range of file formats. The Load method accepts
;               URLs as wide strings. That means, the it can load a local file, a remote file from
;               the web or a local resource. The format is <scheme>:<scheme-specific-part>, where
;               scheme can be www, file or res.
;               Load is an asynchronous call that uses a callback mechanism to indicate its status.
;               This mechanism uses the same thread as the caller, so no synchronisation event can
;               be used.
;               To use the callback mechanism, the callback address must be registered using
;               IImgCtx.SetCallback and a trigger condition must be defined using
;               IImgCtx.SelectChanges. Tha callback procedure has 2 parameters. The first is a
;               pointer to an undocumented structure called CDwnCtx, The second is the value passed
;               as pPrivate in the IImgCtx.SetCallback method.
;               This mechanism uses the window message loop of the owner window where a message ID
;               WM_APPSTR + 00EAh is placed and handled in a hook. Applications are able to
;               intercept this message for their own purposes. The wParam and lParam arguments
;               are both NULL.
;             - Loading a resorce from the current file requires that the image resource is tagged
;               as resource 2110. Example:
;                  MyBMP IMAGE DISCARDABLE "BMP\Spiderman.bmp"
;               where IMAGE = 2110.
;             - The second argument of IImgCtx.Load can be one of the following constants:
;                 DWN_COLORMODE    = Explicit color mode requested
;                 DWN_DOWNLOADONLY = Download data only, don't decode
;                 DWN_FORCEDITHER  = Override automatic dithering
;                 DWN_RAWIMAGE     = Disable dithering
;                 DWN_MIRRORIMAGE  = Mirror the image
;             - Do not try to use the StrechtBlt interface method. It is not implemented (2019).
;               It returns 0x80004002.
;             - ImgCtx can only load an image once.


IMAGE_SIZE struct
  Union
    Rect RECT  {}
    struct
      DWORD ?             ;Anonymous placeholder 1 = RECT.left = 0
      DWORD ?             ;Anonymous placeholder 2 = RECT.top = 0
      struct
        x DWORD ?         ;Image width
        y DWORD ?         ;Image height
      ends
    ends
  ends
IMAGE_SIZE ends

Object Image, ImageID, Primer
  RedefineMethod  Done                                  ;Must be first virtual method!
  RedefineMethod  Init,             POINTER             ;-> Owner object.

  VirtualMethod   AlphaDraw,        HDC, DWORD, PRECT
  VirtualMethod   AlphaStretch,     HDC, DWORD, PRECT, PRECT
  VirtualMethod   AlphaTile,        HDC, DWORD, PPOINT, PRECT, PSIZE
  VirtualMethod   Draw,             HDC, PRECT
  VirtualMethod   GetCompatibleBmp, HDC
  VirtualMethod   LoadFromFileA,    PSTRINGA
  VirtualMethod   LoadFromFileW,    PSTRINGW
  VirtualMethod   LoadFromResA,     PSTRINGA
  VirtualMethod   LoadFromResW,     PSTRINGW
  VirtualMethod   Stretch,          HDC, PRECT, PRECT
  VirtualMethod   Tile,             HDC, PPOINT, PRECT, PSIZE

  DefineVariable  pIImgCtx,         POINTER,    NULL    ;-> IImgCtx interface
  DefineVariable  dState,           DWORD,      0
  DefineVariable  ImgSize,          IMAGE_SIZE, {}
ObjectEnd

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  $ObjMthd(LoadFromFile) textequ $ObjMthd(LoadFromFileA)
  $ObjMthd(LoadFromRes)  textequ $ObjMthd(LoadFromResA)
else
  $ObjMthd(LoadFromFile) textequ $ObjMthd(LoadFromFileW)
  $ObjMthd(LoadFromRes)  textequ $ObjMthd(LoadFromResW)
endif


; ==================================================================================================

if IMPLEMENT

sCLSID_IImgCtx  textequ   <3050F3D6-98B5-11CF-BB82-00AA00BDCE0B>
sIID_IImgCtx    textequ   <3050F3D7-98B5-11CF-BB82-00AA00BDCE0B>

.const
DefGUID IID_IImgCtx, %sIID_IImgCtx
DefGUID CLSID_IImgCtx, %sCLSID_IImgCtx

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.AlphaDraw
; Purpose:    Blend the image on a device context using the alpha information.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Source alpha value.
;             Arg3: -> Destination RECT (x, y, cx, cy).
; Return:     eax = 0 if succeeded, otherwise -1.

Method Image.AlphaDraw, uses xsi, hDC:HDC, dSrcAlpha:DWORD, pDstRect:PRECT
  local hTmpDC:HDC, hTmpBmp:HBITMAP, hPrvBmp:HBITMAP, bfn:BLENDFUNCTION, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .ifBitSet [xsi].dState, IMGLOAD_COMPLETE
    mov hTmpDC, $invoke(CreateCompatibleDC, hDC)
    mov hTmpBmp, $invoke(CreateCompatibleBitmap, hDC, [xsi].ImgSize.x, [xsi].ImgSize.y)
    mov hPrvBmp, $invoke(SelectObject, hTmpDC, hTmpBmp)
    ICall [xsi].pIImgCtx::IImgCtx.Draw, hTmpDC, addr [xsi].ImgSize.Rect
    .if SUCCEEDED(eax)
      mov bfn.BlendOp, AC_SRC_OVER
      mov bfn.BlendFlags, 0
      mov eax, dSrcAlpha
      mov bfn.SourceConstantAlpha, al
      mov bfn.AlphaFormat, AC_SRC_ALPHA
      mov xax, pDstRect
      invoke AlphaBlend, hDC, [xax].RECT.left, [xax].RECT.top, \
                              [xax].RECT.right, [xax].RECT.bottom, \
                         hTmpDC, 0, 0, [xsi].ImgSize.x, [xsi].ImgSize.y, bfn
      .if eax != FALSE
        mov dReturn, 0
      .endif
    .endif
    invoke SelectObject, hTmpDC, hPrvBmp
    invoke DeleteObject, hTmpBmp
    invoke DeleteObject, hTmpDC
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.AlphaStretch
; Purpose:    Blend the image on a device context using the alpha information.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Source alpha value.
;             Arg3: -> Destination RECT (x, y, cx, cy).
;             Arg4: -> Source RECT (x, y, cx, cy).
; Return:     eax = 0 if succeeded, otherwise -1.

Method Image.AlphaStretch, uses xbx xsi, hDC:HDC, dSrcAlpha:DWORD, pDstRect:PRECT, pSrcRect:PRECT
  local hTmpDC:HDC, hTmpBmp:HBITMAP, hPrvBmp:HBITMAP, bfn:BLENDFUNCTION, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .ifBitSet [xsi].dState, IMGLOAD_COMPLETE
    mov hTmpDC, $invoke(CreateCompatibleDC, hDC)
    mov hTmpBmp, $invoke(CreateCompatibleBitmap, hDC, [xsi].ImgSize.x, [xsi].ImgSize.y)
    mov hPrvBmp, $invoke(SelectObject, hTmpDC, hTmpBmp)
    ICall [xsi].pIImgCtx::IImgCtx.Draw, hTmpDC, addr [xsi].ImgSize.Rect
    .if SUCCEEDED(eax)
      mov bfn.BlendOp, AC_SRC_OVER
      mov bfn.BlendFlags, 0
      mov eax, dSrcAlpha
      mov bfn.SourceConstantAlpha, al
      mov bfn.AlphaFormat, AC_SRC_ALPHA
      mov xax, pDstRect
      mov xbx, pSrcRect
      invoke AlphaBlend, hDC, [xax].RECT.left, [xax].RECT.top, \
                              [xax].RECT.right, [xax].RECT.bottom, \
                         hTmpDC, [xbx].RECT.left, [xbx].RECT.top, \
                              [xbx].RECT.right, [xbx].RECT.bottom, \
                         bfn
      .if eax != FALSE
        mov dReturn, 0
      .endif
    .endif
    invoke SelectObject, hTmpDC, hPrvBmp
    invoke DeleteObject, hTmpBmp
    invoke DeleteObject, hTmpDC
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.AlphaTile
; Purpose:    Tile the image on a device context.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Source alpha value.
;             Arg3: -> Origin POINT (x, y).
;             Arg4: -> Clip RECT (x, y, cx, cy).
;             Arg5: -> Size SIZE_ (cx, cy).
; Return:     eax = 0 if succeeded, otherwise -1.

Method Image.AlphaTile, uses xsi, hDC:HDC, dSrcAlpha:DWORD, pOrigin:PPOINT, pClipRect:PRECT, \
                                  pSize:PSIZE
  local hTmpDC:HDC, hTmpBmp:HBITMAP, hPrvBmp:HBITMAP
  local BmpRect:RECT, DstPos:SIZE_, bfn:BLENDFUNCTION, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .ifBitSet [xsi].dState, IMGLOAD_COMPLETE
    mov hTmpDC, $invoke(CreateCompatibleDC, hDC)

    mov BmpRect.top, 0
    mov BmpRect.left, 0

    mov xax, pClipRect
    s2s DstPos, SIZE_ ptr [xax].RECT.left, xdx
    s2s SIZE_ ptr BmpRect.right, SIZE_ ptr [xax].RECT.right, xcx

    mov hTmpBmp, $invoke(CreateCompatibleBitmap, hDC, [xax].RECT.right, [xax].RECT.bottom)
    mov hPrvBmp, $invoke(SelectObject, hTmpDC, hTmpBmp)
    ICall [xsi].pIImgCtx::IImgCtx.Tile, hTmpDC, pOrigin, addr BmpRect, pSize
    .if SUCCEEDED(eax)
      mov bfn.BlendOp, AC_SRC_OVER
      mov bfn.BlendFlags, 0
      mov eax, dSrcAlpha
      mov bfn.SourceConstantAlpha, al
      mov bfn.AlphaFormat, AC_SRC_ALPHA
      invoke AlphaBlend, hDC, DstPos.cx_, DstPos.cy, \
                              BmpRect.right, BmpRect.bottom, \
                         hTmpDC, 0, 0, \
                              BmpRect.right, BmpRect.bottom, \
                         bfn
      .if eax != FALSE
        mov dReturn, 0
      .endif
    .endif
    invoke SelectObject, hTmpDC, hPrvBmp
    invoke DeleteObject, hTmpBmp
    invoke DeleteObject, hTmpDC
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.Done
; Purpose:    Free allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method Image.Done, uses xsi
  SetObject xsi
  ICall [xsi].pIImgCtx::IImgCtx.Release
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.Draw
; Purpose:    Draw the image on a device context.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: -> Output RECT (x, y, cx, cy).
; Return:     eax = 0 if succeeded, otherwise -1.

Method Image.Draw,, hDC:HDC, pRect:PRECT
  local DstRect:RECT, dReturn:DWORD

  SetObject xcx
  mov dReturn, -1
  .ifBitSet [xcx].dState, IMGLOAD_COMPLETE
    mov xax, pRect
    mrm DstRect.left, [xax].RECT.left, edx
    add edx, [xax].RECT.right
    mov DstRect.right, edx

    mrm DstRect.top, [xax].RECT.top, edx
    add edx, [xax].RECT.bottom
    mov DstRect.bottom, edx

    ICall [xcx].pIImgCtx::IImgCtx.Draw, hDC, addr DstRect
    .if SUCCEEDED(eax)
      mov dReturn, 0
    .endif
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.GetCompatibleBmp
; Purpose:    Initialize the object
; Arguments:  Arg1: Device Context HANDLE.
; Return:     xax = HBITMAP or zero if failed.

Method Image.GetCompatibleBmp, uses xsi, hDC:HDC
  local hTmpDC:HDC, hPrvBmp: HBITMAP, hBmp:HBITMAP

  SetObject xsi
  .ifBitSet [xsi].dState, IMGLOAD_COMPLETE
    mov hTmpDC, $invoke(CreateCompatibleDC, hDC)
    mov hBmp, $invoke(CreateCompatibleBitmap, hDC, [xsi].ImgSize.x, [xsi].ImgSize.y)
    mov hPrvBmp, $invoke(SelectObject, hTmpDC, hBmp)
    ICall [xsi].pIImgCtx::IImgCtx.Draw, hTmpDC, addr [xsi].ImgSize.Rect
    .if !SUCCEEDED(eax)
      invoke DeleteObject, hBmp
      mov hBmp, 0
    .endif
    invoke SelectObject, hTmpDC, hPrvBmp
    invoke DeleteObject, hTmpDC
    mov xax, hBmp
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Callback for ImgCtx
; Purpose:    Notification callback. Is called only if the callback is set using IImgCtx.SetCallback
;             and a trigger condition is defined using IImgCtx.SelectChanges.
;             This mechanism used the messageloop of the owner window where a message
;             WM_APPSTR + 00EAh is placed and handled in a hook. Applications can intercept this
;             message for their own purposes. The wParam and lParam arguments are both NULL.
; Arguments:  Arg1: -> CDwnCtx structure. Since it is undocumented, don't use it!
;             Arg2: private data. In this case it is used to passed pSelf.
; Return:     Nothing.

;ImgCtxCallback proc uses xsi pCDwnCtx:ptr CDwnCtx, pSelf:$ObjPtr(Image)
;  ret
;ImgCtxCallback endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.Init
; Purpose:    Initialize the object
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method Image.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  invoke CoCreateInstance, offset CLSID_IImgCtx, 0, CLSCTX_ALL, offset IID_IImgCtx, \
                           addr [xsi].pIImgCtx
;  .if eax == 0
;    ICall [xsi].pIImgCtx::IImgCtx.SetCallback, offset ImgCtxCallback, xsi
;    ICall [xsi].pIImgCtx::IImgCtx.SelectChanges, IMGCHG_COMPLETE, IMGCHG_COMPLETE, FALSE
;  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.LoadFromFileA
; Purpose:    Load the image from file.
; Arguments:  Arg1: -> ANSI file name.
; Return:     eax = 0 if succeeded, othewise -1.

Method Image.LoadFromFileA, uses xsi, pFileNameA:PSTRINGA
  local wBuffer[2*MAX_PATH]:CHRW, pFullfileNameW:PSTRINGW, dLen:DWORD, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .if [xsi].pIImgCtx != NULL
    invoke StrA2StrW, addr wBuffer, pFileNameA
    invoke GetFullPathNameW, addr wBuffer, 0, NULL, NULL
    mov dLen, eax
    shl eax, 1
    mov pFullfileNameW, $MemAlloc(eax)
    invoke GetFullPathNameW, addr wBuffer, dLen, pFullfileNameW, NULL
    ICall [xsi].pIImgCtx::IImgCtx.Load, pFullfileNameW, DWN_COLORMODE
    .if SUCCEEDED(eax)
      .repeat
        ICall [xsi].pIImgCtx::IImgCtx.GetStateInfo, addr [xsi].dState, addr [xsi].ImgSize.x, FALSE
        mov ecx, [xsi].dState
        .ifBitClr ecx, IMGLOAD_LOADING
          .ifBitClr ecx, IMGLOAD_NOTLOADED or IMGLOAD_STOPPED or IMGLOAD_ERROR
            mov dReturn, 0
          .endif
          .break
        .endif
        invoke SwitchToThread
      .until FALSE
    .endif
    MemFree pFullfileNameW
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.LoadFromFileW
; Purpose:    Load the image from file.
; Arguments:  Arg1: -> WIDE file name.
; Return:     eax = 0 if succeeded, othewise -1.

Method Image.LoadFromFileW, uses xsi, pFileNameW:PSTRINGW
  local pFullfileNameW:PSTRINGW, dLen:DWORD, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .if [xsi].pIImgCtx != NULL
    invoke GetFullPathNameW, pFileNameW, 0, NULL, NULL
    mov dLen, eax
    shl eax, 1
    mov pFullfileNameW, $MemAlloc(eax)
    invoke GetFullPathNameW, pFileNameW, dLen, pFullfileNameW, NULL
    ICall [xsi].pIImgCtx::IImgCtx.Load, pFullfileNameW, DWN_COLORMODE
    .if SUCCEEDED(eax)
      .repeat
        ICall [xsi].pIImgCtx::IImgCtx.GetStateInfo, addr [xsi].dState, addr [xsi].ImgSize.x, FALSE
        mov ecx, [xsi].dState
        .ifBitClr ecx, IMGLOAD_LOADING
          .ifBitClr ecx, IMGLOAD_NOTLOADED or IMGLOAD_STOPPED or IMGLOAD_ERROR
            mov dReturn, 0
          .endif
          .break
        .endif
        invoke SwitchToThread
      .until FALSE
    .endif
    MemFree pFullfileNameW
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.LoadFromResA
; Purpose:    Load the image from resource.
; Arguments:  Arg1: -> ANSI resource name.
; Return:     eax = 0 if succeeded, othewise -1.

Method Image.LoadFromResA, uses xbx xsi, pResNameA:PSTRINGA
  local wBuffer[2*1024]:CHRW, dSize:DWORD, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .if [xsi].pIImgCtx != NULL
    mov dSize, $32($invoke(StrSizeA, pResNameA))
    FillStringW wBuffer, <res://>
    lea xbx, wBuffer
    invoke GetModuleFileNameW, 0, addr [xbx + sizeof(CHRW)*6], sizeof(wBuffer) - sizeof(CHRW)*6
    invoke StrCCatCharW, xbx, "/", lengthof(wBuffer)
    invoke StrEndW, xbx
    lea xcx, [xbx + sizeof wBuffer]
    mov edx, dSize
    shl edx, 1                                            ;ANSI to WIDE
    add xdx, xax
    .if xdx <= xcx
      invoke StrA2StrW, xax, pResNameA
      ICall [xsi].pIImgCtx::IImgCtx.Load, xbx, DWN_COLORMODE
      .if SUCCEEDED(eax)
        .repeat
          ICall [xsi].pIImgCtx::IImgCtx.GetStateInfo, addr [xsi].dState, addr [xsi].ImgSize.x, FALSE
          mov ecx, [xsi].dState
          .ifBitClr ecx, IMGLOAD_LOADING
            .ifBitClr ecx, IMGLOAD_NOTLOADED or IMGLOAD_STOPPED or IMGLOAD_ERROR
              mov dReturn, 0
            .endif
            .break
          .endif
          invoke SwitchToThread
        .until FALSE
      .endif
    .endif
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.LoadFromResW
; Purpose:    Load the image from resource.
; Arguments:  Arg1: -> WIDE resource name.
; Return:     eax = 0 if succeeded, othewise -1.

Method Image.LoadFromResW, uses xbx xsi, pResNameW:PSTRINGW
  local wBuffer[2*1024]:CHRW, dSize:DWORD, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .if [xsi].pIImgCtx != NULL
    mov dSize, $32($invoke(StrSizeW, pResNameW))
    FillStringW wBuffer, <res://>
    lea xbx, wBuffer
    invoke GetModuleFileNameW, 0, addr [xbx + sizeof(CHRW)*6], sizeof(wBuffer) - sizeof(CHRW)*6
    invoke StrCCatCharW, xbx, "/", lengthof(wBuffer)
    invoke StrEndW, xbx
    lea xcx, [xbx + sizeof wBuffer]
    mov edx, dSize
    add xdx, xax
    .if xdx <= xcx
      invoke MemClone, xax, pResNameW, dSize
      ICall [xsi].pIImgCtx::IImgCtx.Load, xbx, DWN_COLORMODE
      .if SUCCEEDED(eax)
        .repeat
          ICall [xsi].pIImgCtx::IImgCtx.GetStateInfo, addr [xsi].dState, addr [xsi].ImgSize.x, FALSE
          mov ecx, [xsi].dState
          .ifBitClr ecx, IMGLOAD_LOADING
            .ifBitClr ecx, IMGLOAD_NOTLOADED or IMGLOAD_STOPPED or IMGLOAD_ERROR
              mov dReturn, 0
            .endif
            .break
          .endif
          invoke SwitchToThread
        .until FALSE
      .endif
    .endif
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.Stretch
; Purpose:    Blit the image on a device context.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: -> Destination RECT (x, y, cx, cy).
;             Arg3: -> Source RECT (x, y, cx, cy).
; Return:     eax = 0 if succeeded, otherwise -1.

Method Image.Stretch, uses xbx xsi, hDC:HDC, pDstRect:PRECT, pSrcRect:PRECT
  local hTmpDC:HDC, hTmpBmp:HBITMAP, hPrvBmp:HBITMAP, dPrvStretchMode:DWORD, dReturn:DWORD

  SetObject xsi
  mov dReturn, -1
  .ifBitSet [xsi].dState, IMGLOAD_COMPLETE
    mov hTmpDC, $invoke(CreateCompatibleDC, hDC)
    mov hTmpBmp, $invoke(CreateCompatibleBitmap, hDC, [xsi].ImgSize.x, [xsi].ImgSize.y)
    mov hPrvBmp, $invoke(SelectObject, hTmpDC, hTmpBmp)
    ICall [xsi].pIImgCtx::IImgCtx.Draw, hTmpDC, addr [xsi].ImgSize.Rect
    .if SUCCEEDED(eax)
      mov dPrvStretchMode, $32($invoke(SetStretchBltMode, hDC, STRETCH_HALFTONE))

      mov xax, pDstRect
      mov xbx, pSrcRect
      invoke StretchBlt, hDC, [xax].RECT.left, [xax].RECT.top, [xax].RECT.right, [xax].RECT.bottom, \
                         hTmpDC, [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right,[xbx].RECT.bottom,\
                         SRCCOPY

      invoke SetStretchBltMode, hDC, dPrvStretchMode

      invoke SelectObject, hTmpDC, hPrvBmp
      invoke DeleteObject, hTmpBmp
      invoke DeleteObject, hTmpDC
      mov dReturn, 0
    .endif
  .endif
  mov eax, dReturn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Image.Tile
; Purpose:    Tile the image on a device context.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: -> Origin POINT (x, y). Indicates where in the rezised picture to start to tile.
;             Arg3: -> Clip RECT (x, y, cx, cy). Destination RECT in DC.
;             Arg4: -> Size SIZE_ (cx, cy). Dimensions of resized tile.
; Return:     eax = 0 if succeeded, otherwise -1.

Method Image.Tile,, hDC:HDC, pOrigin:PPOINT, pClipRect:PRECT, pSize:PSIZE
  local DstRect:RECT, dReturn:DWORD

  SetObject xcx
  mov dReturn, -1
  .ifBitSet [xcx].dState, IMGLOAD_COMPLETE
    mov xax, pClipRect
    mrm DstRect.left, [xax].RECT.left, edx
    add edx, [xax].RECT.right
    mov DstRect.right, edx

    mrm DstRect.top, [xax].RECT.top, edx
    add edx, [xax].RECT.bottom
    mov DstRect.bottom, edx

    ICall [xcx].pIImgCtx::IImgCtx.Tile, hDC, pOrigin, addr DstRect, pSize
    .if SUCCEEDED(eax)
      mov dReturn, 0
    .endif
  .endif
  mov eax, dReturn
MethodEnd

endif
