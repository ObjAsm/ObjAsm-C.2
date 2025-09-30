; ==================================================================================================
; Title:      MovingThrobber.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm implementation of MovingThrobber objects.
; Notes:      Version C.1.0, August 2022
;               - First release.
;             Require an addition to the manifest to enable WS_EX_LAYERED style on child windows
;             <application>
;               <!--The ID below indicates app support for Windows 8 -->
;               <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}"/>
;             </application>
; Links:      https://stackoverflow.com/questions/3970066/creating-a-transparent-window-in-c-win32
;             https://stackoverflow.com/questions/42569348/how-to-use-ws-ex-layered-on-child-controls
;             https://www.codeguru.com/multimedia/rotate-a-bitmap-image/
;             https://api.flutter.dev/flutter/material/CircularProgressIndicator-class.html
;
; Example 1:  mov DefStruc.xCtlID, 123
;             mov DefStruc.dStyle, WS_VISIBLE or WS_CHILD
;             mov DefStruc.dExStyle, WS_EX_LAYERED
;             mov DefStruc.pTitle, NULL
;             mov DefStruc.sdPosX, 100
;             mov DefStruc.sdPosY, 100
;             mov DefStruc.dInterval, 50
;             c2m DefStruc.pResList, offset SpinnerList0, xax
;             mov DefStruc.dResListCount, SpinnerCount0
;             mov DefStruc.dImageType, TBR_IMAGE_PNG
;             mov [xsi].pControl, $New(MovingThrobber)
;             OCall [xsi].pControl::MovingThrobber.Init, xsi, [xsi].hWnd, addr DefStruc
;             OCall [xsi].pControl::MovingThrobber.Start
;             ...
;
; Example 2:  invoke CreateWindowEx, WS_EX_LAYERED, \
;                                    offset szMovingThrobberClass, NULL, \
;                                    WS_VISIBLE or WS_CHILD, \
;                                    100, 100, 1, 1, [xsi].hWnd, 123, hInstance, NULL
;             .if xax != 0
;               invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
;               mov [xsi].pControl, xax
;               mov [xax].$Obj(MovingThrobber).dInterval, 50
;               OCall [xsi].pControl::MovingThrobber.AddPngFromResList, \
;                                                                 offset SpinnerList0, SpinnerCount0
;               OCall [xsi].pControl::MovingThrobber.Start
;               ...
; ==================================================================================================


DEF_MTHROBBER struc
                DEF_THROBBER    {}
  pResList      POINTER   ?             ;-> Resource string list
  dResListCount DWORD     ?             ;List item count
DEF_MTHROBBER ends
PDEF_MTHROBBER typedef ptr DEF_MTHROBBER


; --------------------------------------------------------------------------------------------------
; Object:  MovingThrobber
; Purpose: Animated control that displays previously loaded images in sequence, to show a backround
;          activity, like GIF but mit transparency.

Object MovingThrobber, MovingThrobberID, Throbber
  VirtualMethod     AddBmpFromRes,      PSTRING
  VirtualMethod     AddBmpFromResList,  POINTER, DWORD
  VirtualMethod     AddPngFromRes,      PSTRING
  VirtualMethod     AddPngFromResList,  POINTER, DWORD
  RedefineMethod    Animate
  RedefineMethod    Dispose
  RedefineMethod    Init,               POINTER, HWND, PDEF_MTHROBBER
  VirtualMethod     InitRes,            POINTER, HWND
  StaticMethod      Startup
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  DefineVariable    dIndex,             DWORD,    0           ;Index into the bitmap HANDLE list
  DefineVariable    phBitmaps,          POINTER,  NULL        ;-> Bitmap HANDLE list
  DefineVariable    dBitmapCount,       DWORD,    0           ;Count it HANDLEs in the list
ObjectEnd


CStr szMovingThrobberClass, "OAC_MovingThrobber"

; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.AddBmpFromRes
; Purpose:    Load a BMP images from the resource section.
; Arguments   Arg1: -> Bitmap resource name.
; Return:     eax = Number of new loaded images, in this case 1 if succeded, otherwise 0.

Method MovingThrobber.AddBmpFromRes, uses xsi, pBmpName:PSTRING
  local BMP:BITMAP

  SetObject xsi
  m2z [xsi].dIndex
  .if [xsi].phBitmaps == NULL
    MemAlloc sizeof(HBITMAP)
  .else
    mov eax, [xsi].dBitmapCount
    inc eax
    shl eax, $Log2(sizeof(HBITMAP))
    MemReAlloc [xsi].phBitmaps, eax
  .endif
  .if xax != NULL
    mov [xsi].phBitmaps, xax

    invoke LoadImage, hInstance, pBmpName, IMAGE_BITMAP, 0, 0, 0
    .if xax != 0
      mov edx, [xsi].dBitmapCount
      mov xcx, [xsi].phBitmaps
      mov HBITMAP ptr [xcx + xdx*sizeof(HBITMAP)], xax
      inc edx
      mov [xsi].dBitmapCount, edx
      .if edx == 1                                      ;Only if it is the 1st image
        mov xcx, xax
        invoke GetObject, xcx, sizeof BMP, addr BMP
        .if eax != 0
          mov ecx, BMP.bmWidth
          mov edx, BMP.bmHeight
        .else
          xor ecx, ecx
          xor edx, edx
        .endif
        mov [xsi].BmpSize.x, ecx
        mov [xsi].BmpSize.y, edx
      .endif
      mov xax, 1
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.AddBmpFromResList
; Purpose:    Load a series of BMP images from the resource section.
; Arguments   Arg1: -> PNG resource name pointer list.
;             Arg2: Number of PSTRINGs in the list.
; Return:     eax = Number of new loaded images, or 0 if failed.

Method MovingThrobber.AddBmpFromResList, uses xbx xdi xsi, pList:POINTER, dCount:DWORD
  local BMP:BITMAP, dSuccessCount:DWORD

  SetObject xsi
  m2z [xsi].dIndex

  ;Allocate necessary memory
  mov eax, [xsi].dBitmapCount
  add eax, dCount
  shl eax, $Log2(sizeof(HBITMAP))
  .if [xsi].phBitmaps == NULL
    MemAlloc eax
  .else
    MemReAlloc [xsi].phBitmaps, eax
  .endif
  mov [xsi].phBitmaps, xax

  .if xax != NULL
    mov xdi, pList
    .if xdi != NULL
      xor ebx, ebx
      mov dSuccessCount, 0
      .while ebx < dCount
        invoke LoadImage, hInstance, PSTRING ptr [xdi], IMAGE_BITMAP, 0, 0, 0
        .if xax != 0
          mov edx, [xsi].dBitmapCount
          mov xcx, [xsi].phBitmaps
          inc dSuccessCount
          mov HBITMAP ptr [xcx + xdx*sizeof(HBITMAP)], xax
          inc edx
          mov [xsi].dBitmapCount, edx
          .if edx == 1                                      ;Only if it is the 1st image
            mov xcx, xax
            invoke GetObject, xcx, sizeof BMP, addr BMP
            .if eax != 0
              mov ecx, BMP.bmWidth
              mov edx, BMP.bmHeight
            .else
              xor ecx, ecx
              xor edx, edx
            .endif
            mov [xsi].BmpSize.x, ecx
            mov [xsi].BmpSize.y, edx
          .endif
        .endif
        inc ebx
        add xdi, sizeof PSTRING
      .endw
    .endif
    mov eax, dSuccessCount
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.AddPngFromRes
; Purpose:    Load a PNG image from the resource section.
; Arguments   Arg1: -> PNG resource name.
; Return:     eax = Number of new loaded images, in this case 1 if succeded, otherwise 0.

Method MovingThrobber.AddPngFromRes, uses xsi, pPngName:PSTRING
  local GPSI:GdiplusStartupInput, xToken:XWORD
  local pBitmap:ptr GpBitmap, hBmp:HBITMAP
  local hResource:HRSRC, dResSize:DWORD, pResource:POINTER
  local hGlobal:HANDLE, pIStream:ptr IStream, pMem:POINTER
  local BMP:BITMAP

  SetObject xsi
  m2z [xsi].dIndex

  .if [xsi].phBitmaps == NULL
    MemAlloc sizeof(HBITMAP)
  .else
    mov eax, [xsi].dBitmapCount
    inc eax
    shl eax, $Log2(sizeof(HBITMAP))
    MemReAlloc [xsi].phBitmaps, eax
  .endif
  .if xax != NULL
    mov [xsi].phBitmaps, xax

    ;Initialize GDI+
    mov GPSI.GdiplusVersion, 1
    mov GPSI.DebugEventCallback, NULL
    mov GPSI.SuppressBackgroundThread, FALSE
    invoke GdiplusStartup, addr xToken, addr GPSI, NULL
    .if eax == 0
      mov hBmp, 0
      ;Find Resource
      invoke FindResource, hInstance, pPngName, $OfsCStr("PNG")
      .if xax != 0
        mov hResource, xax
        mov dResSize, $32($invoke(SizeofResource, 0, hResource))
        ;Allocate memory and copy resource bytes
        mov pResource, $invoke(LoadResource, hInstance, hResource)
        invoke GlobalAlloc, GMEM_MOVEABLE, dResSize
        .if xax != 0
          mov hGlobal, xax
          mov pMem, $invoke(GlobalLock, hGlobal)
          invoke MemClone, pMem, pResource, dResSize
          invoke GlobalUnlock, hGlobal
          invoke CreateStreamOnHGlobal, hGlobal, 0, addr pIStream
          ;Create GDI+ object
          invoke GdipCreateBitmapFromStream, pIStream, addr pBitmap
          .if eax == 0
            ;Create HBITMAP
            invoke GdipCreateHBITMAPFromBitmap, pBitmap, addr hBmp, 0
            invoke GdipDisposeImage, pBitmap
          .endif
          invoke GlobalFree, hGlobal
        .endif
        invoke FreeResource, hResource
      .endif

      mov xax, hBmp
      .if xax != 0
        mov edx, [xsi].dBitmapCount
        mov xcx, [xsi].phBitmaps
        mov HBITMAP ptr [xcx + xdx*sizeof(HBITMAP)], xax
        inc edx
        mov [xsi].dBitmapCount, edx
        .if edx == 1                                      ;Only it it is the first image
          mov xcx, xax
          invoke GetObject, xcx, sizeof BMP, addr BMP
          .if eax != 0
            mov ecx, BMP.bmWidth
            mov edx, BMP.bmHeight
          .else
            xor ecx, ecx
            xor edx, edx
          .endif
          mov [xsi].BmpSize.x, ecx
          mov [xsi].BmpSize.y, edx
        .endif
        mov xax, 1
      .endif
    .else
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.AddPngFromResList
; Purpose:    Load a series of PNG images from the resource section.
; Arguments   Arg1: -> PNG resource name pointer list.
;             Arg2: Number of PSTRINGs in the list.
; Return:     eax = Number of new loaded images, or 0 if failed.

Method MovingThrobber.AddPngFromResList, uses xbx xdi xsi, pList:POINTER, dListCount:DWORD
  local GPSI:GdiplusStartupInput, xToken:XWORD
  local pBitmap:ptr GpBitmap, hBmp:HBITMAP
  local hResource:HRSRC, dResSize:DWORD, pResource:POINTER
  local hGlobal:HANDLE, pIStream:ptr IStream, pMem:POINTER
  local BMP:BITMAP, dSuccessCount:DWORD

  SetObject xsi
  m2z [xsi].dIndex

  ;Allocate necessary memory
  mov eax, [xsi].dBitmapCount
  add eax, dListCount
  shl eax, $Log2(sizeof(HBITMAP))
  .if [xsi].phBitmaps == NULL
    MemAlloc eax
  .else
    MemReAlloc [xsi].phBitmaps, eax
  .endif
  mov [xsi].phBitmaps, xax

  .if xax != NULL
    ;Initialize GDI+
    mov GPSI.GdiplusVersion, 1
    mov GPSI.DebugEventCallback, NULL
    mov GPSI.SuppressBackgroundThread, FALSE
    invoke GdiplusStartup, addr xToken, addr GPSI, NULL
    .if eax == 0
      mov xdi, pList
      .if xdi != NULL
        xor ebx, ebx
        mov dSuccessCount, 0
        .while ebx < dListCount
          mov hBmp, 0
          ;Find Resource
          invoke FindResource, hInstance, PSTRING ptr [xdi], $OfsCStr("PNG")
          .if xax != 0
            mov hResource, xax
            mov dResSize, $32($invoke(SizeofResource, 0, hResource))
            ;Allocate memory and copy resource bytes
            mov pResource, $invoke(LoadResource, hInstance, hResource)
            invoke GlobalAlloc, GMEM_MOVEABLE, dResSize
            .if xax != 0
              mov hGlobal, xax
              mov pMem, $invoke(GlobalLock, hGlobal)
              invoke MemClone, pMem, pResource, dResSize
              invoke GlobalUnlock, hGlobal
              invoke CreateStreamOnHGlobal, hGlobal, 0, addr pIStream
              ;Create GDI+ object
              invoke GdipCreateBitmapFromStream, pIStream, addr pBitmap
              .if eax == 0
                ;Create HBITMAP
                invoke GdipCreateHBITMAPFromBitmap, pBitmap, addr hBmp, 0
                invoke GdipDisposeImage, pBitmap
              .endif
              invoke GlobalFree, hGlobal
            .endif
            invoke FreeResource, hResource
          .endif

          mov xax, hBmp
          .if xax != 0
            mov edx, [xsi].dBitmapCount
            mov xcx, [xsi].phBitmaps
            inc dSuccessCount
            mov HBITMAP ptr [xcx + xdx*sizeof(HBITMAP)], xax
            inc edx
            mov [xsi].dBitmapCount, edx
            .if edx == 1                                      ;Only if it is the 1st image
              invoke GetObject, hBmp, sizeof BMP, addr BMP
              .if eax != 0
                mov ecx, BMP.bmWidth
                mov edx, BMP.bmHeight
              .else
                xor ecx, ecx
                xor edx, edx
              .endif
              mov [xsi].BmpSize.x, ecx
              mov [xsi].BmpSize.y, edx
            .endif
          .endif
          inc ebx
          add xdi, sizeof PSTRING
        .endw
      .endif
      invoke GdiplusShutdown, xToken
      mov eax, dSuccessCount
    .else
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.Animate
; Purpose:    Show the animation.
; Arguments:  None.
; Return:     Nothing.

Method MovingThrobber.Animate, uses xbx xsi
  local hSrcDC:HDC, hPrvSrcBmp:HBITMAP, hDstDC:HDC
  local hModDC:HDC, hPrvModBmp:HBITMAP
  local xform:XFORM, bfn:BLENDFUNCTION
  local PtSize:POINT, PtZero:POINT
  local hModBmp:HBITMAP

  SetObject xsi
  mov PtZero.x, 0
  mov PtZero.y, 0
  mov bfn.BlendOp, AC_SRC_OVER
  mov bfn.BlendFlags, 0
  mov bfn.AlphaFormat, AC_SRC_ALPHA

  .repeat
    mov eax, [xsi].dFlags
    .ifBitSet eax, TBR_FLAG_ANIMATION_THREAD_STOP
      .break
    .elseIfBitSet eax, TBR_FLAG_ANIMATION_THREAD_FREEZE
      BitSet [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_FROZEN
    .else
      BitClr [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_FROZEN
      mov hDstDC, $invoke(GetDC, [xsi].hWnd)
      mov hSrcDC, $invoke(CreateCompatibleDC, hDstDC)
      mov hModDC, $invoke(CreateCompatibleDC, hDstDC)

      mov ebx, [xsi].dIndex
      mov xax, [xsi].phBitmaps
      .if xax != NULL && ebx < [xsi].dBitmapCount
        mov xdx, HBITMAP ptr [xax + xbx*sizeof(HBITMAP)]
      .else
        xor edx, edx
      .endif
      mov hPrvSrcBmp, $invoke(SelectObject, hSrcDC, xdx)
      inc ebx
      .if ebx >= [xsi].dBitmapCount
        xor ebx, ebx
      .endif
      mov [xsi].dIndex, ebx

      invoke CreateCompatibleBitmap, hDstDC, [xsi].BmpSize.x, [xsi].BmpSize.y
      mov hModBmp, xax
      mov hPrvModBmp, $invoke(SelectObject, hModDC, xax)

      .if [xsi].dStatus != TBR_STATUS_STOPPED
        fld1
        fldz

        mov eax, [xsi].dAlpha
        .if [xsi].dStatus == TBR_STATUS_STARTING
          add eax, [xsi].dAlphaChange
          .if eax > 255
            mov eax, 255                                ;Saturate
          .endif
          mov [xsi].dAlpha, eax

          fld [xsi].r4Scaling
          fadd [xsi].r4ScalingChange

          fld1
          fcom
          fGetFlags
          .if CARRY?
            mov [xsi].dStatus, TBR_STATUS_RUNNING
            fstp [xsi].r4Scaling                        ;1.0
            fUnload
          .else
            fUnload
            fmul st(2), st(0)
            fstp [xsi].r4Scaling
          .endif

        .elseif [xsi].dStatus == TBR_STATUS_STOPPING
          sub eax, [xsi].dAlphaChange
          .if SDWORD ptr eax < 0
            xor eax, eax
          .endif
          mov [xsi].dAlpha, eax

          fld [xsi].r4Scaling
          fsub [xsi].r4ScalingChange

          fldz
          fcom
          fGetFlags
          .if !CARRY?                                   ;Carry if st(0) < source
            mov [xsi].dStatus, TBR_STATUS_STOPPED
            fstp [xsi].r4Scaling
            fUnload 3
            jmp @F
          .endif
          fUnload
          fmul st(2), st(0)
          fstp [xsi].r4Scaling
        .endif

        fst xform.eM21                                  ;   0    ; Scaled
        fstp xform.eM12                                 ; Scaled
        fst xform.eM11
        fstp xform.eM22
        fld1
        fld1                                            ;   1    ;    1
        faddp st(1), st(0)                              ;   2
        fild [xsi].BmpSize.x                            ;   W    ;    2
        fdiv st(0), st(1)                               ;  W/2   ;    2
        fstp xform.eDx_                                 ;   2
        fild [xsi].BmpSize.y                            ;   H    ;    2
        fdivrp st(1), st(0)                             ;  H/2
        fstp xform.eDy

        invoke SetGraphicsMode, hModDC, GM_ADVANCED
        invoke SetWorldTransform, hModDC, addr xform

        mov edx, [xsi].BmpSize.x
        mov eax, [xsi].BmpSize.y
        shr edx, 1
        neg edx
        shr eax, 1
        neg eax
        invoke BitBlt, hModDC, edx, eax, [xsi].BmpSize.x, [xsi].BmpSize.y, hSrcDC, 0, 0, SRCCOPY
      .endif

    @@:
      mov eax, [xsi].dAlpha
      mov bfn.SourceConstantAlpha, al
      s2s PtSize, [xsi].BmpSize, xax, xcx, xmm0
      ;Note: UpdateLayeredWindow changes the window width and height
      ;      according to the hModDC selected bitmap size!
      invoke UpdateLayeredWindow, [xsi].hWnd, hDstDC, NULL, addr PtSize, \
                                  hModDC, addr PtZero, $RGB(0,0,0), addr bfn, ULW_ALPHA
      invoke SelectObject, hSrcDC, hPrvSrcBmp
      invoke DeleteDC, hSrcDC
      invoke SelectObject, hModDC, hPrvModBmp
      invoke DeleteObject, xax
      invoke DeleteDC, hModDC
      invoke ReleaseDC, [xsi].hWnd, hDstDC

    .endif

    invoke Sleep, [xsi].dInterval
  .until FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.Dispose
; Purpose:    Free all allocated Bitmaps.
; Arguments:  None.
; Return:     Nothing.

Method MovingThrobber.Dispose, uses xbx xdi xsi
  SetObject xsi
  .if [xsi].phBitmaps != NULL
    xor ebx, ebx
    mov xdi, [xsi].phBitmaps
    .while ebx < [xsi].dBitmapCount
      invoke DeleteObject, HBITMAP ptr [xdi + xbx*sizeof(HBITMAP)]
      inc xbx
    .endw
    MemFree xdi
    mov [xsi].phBitmaps, NULL
    m2z [xsi].dBitmapCount
    m2z [xsi].dIndex
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.Init
; Purpose:    Initialize the MovingThrobber object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method MovingThrobber.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_MTHROBBER
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_MTHROBBER
  mov ecx, [xbx].dExStyle
  or ecx, WS_EX_LAYERED or WS_EX_NOACTIVATE
  invoke CreateWindowEx, ecx, offset(szMovingThrobberClass), [xbx].pTitle, \
                         [xbx].dStyle, [xbx].sdPosX, [xbx].sdPosY, 1, 1, \
                         hParent, [xbx].xCtlID, hInstance, xsi
  ACall xsi.Init, pOwner, xax
  .if [xbx].dImageType == TBR_IMAGE_BMP
    OCall xsi.AddBmpFromResList, [xbx].pResList, [xbx].dResListCount
  .elseif [xbx].dImageType == TBR_IMAGE_PNG
    OCall xsi.AddPngFromResList, [xbx].pResList, [xbx].dResListCount
  .endif
  m2m [xsi].dInterval, [xbx].dInterval, xax

  BitClr [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_STOP
  invoke CreateThread, 0, 0, $MethodAddr(MovingThrobber.Animate), \
                       xsi, CREATE_SUSPENDED, NULL
  mov [xsi].hThread, xax
  invoke ResumeThread, xax

  assume xbx:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.InitRes
; Purpose:    Initialize the MovingThrobber object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Window HANDLE.
; Return:     Nothing.

Method MovingThrobber.InitRes, uses xsi, pOwner:POINTER, hWnd:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hWnd
  mov eax, [xsi].dFlags
  BitSet eax, TBR_FLAG_SELF_INST
  BitClr eax, TBR_FLAG_ANIMATION_THREAD_STOP
  mov [xsi].dFlags, eax
  invoke CreateThread, 0, 0, $MethodAddr(MovingThrobber.Animate), \
                       xsi, CREATE_SUSPENDED, NULL
  mov [xsi].hThread, xax
  invoke ResumeThread, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method MovingThrobber.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(MovingThrobber.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szMovingThrobberClass, xdx
  m2z WC.hIcon
  m2z WC.hCursor
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MovingThrobber.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             MovingThrobber HANDLE is passed in pSelf (hidden parameter).

Method MovingThrobber.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "MovingThrobber.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(MovingThrobber)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER to parent object
      .endif
      OCall xsi::MovingThrobber.InitRes, xax, pSelf
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(MovingThrobber).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance POINTER
    OCall xsi::MovingThrobber.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::MovingThrobber.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(MovingThrobber).dFlags, TBR_FLAG_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

endif
