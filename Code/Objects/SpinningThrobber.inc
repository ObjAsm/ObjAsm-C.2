; ==================================================================================================
; Title:      SpinningThrobber.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm implementation of SpinningThrobber objects.
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
; ==================================================================================================


DEF_STHROBBER struc
            DEF_THROBBER  {}
  pResName  POINTER       ?             ;-> Resource name
DEF_STHROBBER ends
PDEF_STHROBBER typedef ptr DEF_STHROBBER


; --------------------------------------------------------------------------------------------------
; Object:  SpinningThrobber
; Purpose: Animated control that displays a rotating image to show a background activity.

Object SpinningThrobber, SpinningThrobberID, Throbber
  RedefineMethod    Animate
  RedefineMethod    Dispose
  RedefineMethod    Init,               POINTER, HWND, PDEF_STHROBBER
  VirtualMethod     InitRes,            POINTER, HWND
  VirtualMethod     LoadBmpFromRes,     PSTRING
  VirtualMethod     LoadPngFromRes,     PSTRING
  StaticMethod      Startup
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  DefineVariable    hBitmap,            HBITMAP,  0
  DefineVariable    r4Rotation,         REAL4,    0.0                 ;Rad/Frame
  DefineVariable    r4RotationChange,   REAL4,    0.5235987666666667  ;Rad/Frame
ObjectEnd


CStr szSpinningThrobberClass, "OAC_SpinningThrobber"

; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.Animate
; Purpose:    Show the animation.
; Arguments:  None.
; Return:     Nothing.

Method SpinningThrobber.Animate
  local hSrcDC:HDC, hPrvSrcBmp:HBITMAP, hModDC:HDC, hPrvModBmp:HBITMAP, hDstDC:HDC
  local xform:XFORM, bfn:BLENDFUNCTION
  local PtSize:POINT, PtZero:POINT

;  DbgText "SpinningThrobber.OnTimer"
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

      mov hPrvSrcBmp, $invoke(SelectObject, hSrcDC, [xsi].hBitmap)
      invoke CreateCompatibleBitmap, hDstDC, [xsi].BmpSize.x, [xsi].BmpSize.y
      mov hPrvModBmp, $invoke(SelectObject, hModDC, xax)

      .if [xsi].dStatus != TBR_STATUS_STOPPED
        fld [xsi].r4Rotation
        fadd [xsi].r4RotationChange
        fst [xsi].r4Rotation
        fSinCos                                         ;  sin   ;  cos

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
            fmul st(1), st(0)
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
          .if !CARRY?
            mov [xsi].dStatus, TBR_STATUS_STOPPED
            fstp [xsi].r4Scaling
            fUnload 3
            jmp @F
          .endif
          fUnload
          fmul st(1), st(0)
          fmul st(2), st(0)
          fstp [xsi].r4Scaling
        .endif

        fst xform.eM21                                  ;  sin   ;  cos
        fchs                                            ; -sin   ;  cos
        fstp xform.eM12                                 ;  cos
        fst xform.eM11
        fstp xform.eM22
        fld1                                            ;   1
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
; Method:     SpinningThrobber.Dispose
; Purpose:    Free the allocated Bitmap.
; Arguments:  None.
; Return:     Nothing.

Method SpinningThrobber.Dispose, uses xbx xsi
  SetObject xsi
  .if [xsi].hBitmap != 0
    invoke DeleteObject, [xsi].hBitmap
    mov [xsi].hBitmap, 0
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.Init
; Purpose:    Initialize the SpinningThrobber object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method SpinningThrobber.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_STHROBBER
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_STHROBBER
  mov ecx, [xbx].dExStyle
  or ecx, WS_EX_LAYERED
  invoke CreateWindowEx, ecx, offset(szSpinningThrobberClass), [xbx].pTitle, \
                         [xbx].dStyle, [xbx].sdPosX, [xbx].sdPosY, 1, 1, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  ACall xsi.Init, pOwner, xax
  .if [xbx].pResName != NULL
    .if [xbx].dImageType == TBR_IMAGE_BMP 
      OCall xsi.LoadBmpFromRes, [xbx].pResName
    .elseif [xbx].dImageType == TBR_IMAGE_PNG
      OCall xsi.LoadPngFromRes, [xbx].pResName
    .endif
  .endif
  m2m [xsi].dInterval, [xbx].dInterval, xax

  BitClr [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_STOP
  invoke CreateThread, 0, 0, $MethodAddr(SpinningThrobber.Animate), \
                       xsi, CREATE_SUSPENDED, NULL
  mov [xsi].hThread, xax
  invoke ResumeThread, xax
  assume xbx:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.InitRes
; Purpose:    Initialize the SpinningThrobber object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Window HANDLE.
;             Arg3: Frame presentation interval.
; Return:     Nothing.

Method SpinningThrobber.InitRes, uses xsi, pOwner:POINTER, hWnd:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hWnd
  mov eax, [xsi].dFlags
  BitSet eax, TBR_FLAG_SELF_INST
  BitClr eax, TBR_FLAG_ANIMATION_THREAD_STOP
  mov [xsi].dFlags, eax
  invoke CreateThread, 0, 0, $MethodAddr(SpinningThrobber.Animate), \
                       xsi, CREATE_SUSPENDED, NULL
  mov [xsi].hThread, xax
  invoke ResumeThread, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.LoadBmpFromRes
; Purpose:    Load a bitmap from the resource section and add it to the spinner resources.
; Arguments   Arg1: -> Bitmap resource name.
; Return:     Nothing.

Method SpinningThrobber.LoadBmpFromRes, uses xsi, pBmpName:PSTRING
  local BMP:BITMAP

  SetObject xsi
  OCall xsi.Dispose
  mov [xsi].hBitmap, $invoke(LoadImage, hInstance, pBmpName, IMAGE_BITMAP, 0, 0, 0)
  invoke GetObject, [xsi].hBitmap, sizeof BMP, addr BMP
  m2m [xsi].BmpSize.x, BMP.bmWidth, eax
  m2m [xsi].BmpSize.y, BMP.bmHeight, ecx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.LoadPngFromRes
; Purpose:    Load a PNG from the resource section and add it to the spinner resources.
; Arguments   Arg1: -> Image resource name. Must be of type IMAGE = 2110.
; Return:     Nothing.

Method SpinningThrobber.LoadPngFromRes, uses xsi, pPngName:PSTRING
  local BMP:BITMAP

  SetObject xsi
  OCall xsi.Dispose
  mov [xsi].hBitmap, $invoke(LoadPngFromResource, pPngName)
  invoke GetObject, [xsi].hBitmap, sizeof BMP, addr BMP
  m2m [xsi].BmpSize.x, BMP.bmWidth, eax
  m2m [xsi].BmpSize.y, BMP.bmHeight, ecx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method SpinningThrobber.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(SpinningThrobber.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szSpinningThrobberClass, xdx
  mov WC.hIcon, 0
  mov WC.hCursor, 0
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SpinningThrobber.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             SpinningThrobber HANDLE is passed in pSelf (hidden parameter).

Method SpinningThrobber.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "SpinningThrobber.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(SpinningThrobber)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      OCall xsi::SpinningThrobber.InitRes, xax, pSelf
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(SpinningThrobber).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::SpinningThrobber.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::SpinningThrobber.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(SpinningThrobber).dFlags, TBR_FLAG_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

endif
