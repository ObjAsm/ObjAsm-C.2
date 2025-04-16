; ==================================================================================================
; Title:      Splash.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Splash objects.
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     Splash
; Purpose:    Implement a fade in / fade out splash window. 

Object Splash, SplashID, Window
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, HBITMAP, DWORD
  VirtualMethod     FadeIn
  VirtualMethod     FadeOut
  StaticMethod      Startup
  StaticMethod      Worker

  VirtualEvent      OnPaint,          WM_PAINT

  DefineVariable    BmpData,          BITMAP,   {}
  DefineVariable    hPrvBmp,          HBITMAP,  0
  DefineVariable    hMemDC,           HDC,      0
  DefineVariable    hSkinRegion,      HRGN,     0
  DefineVariable    hThread,          HANDLE,   0
  DefineVariable    hEvent,           HANDLE,   0
  DefineVariable    dMinShowTime,     DWORD,    1500
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szSplash, "Splash"

.data
DibSection DIBSECTION {};{0,100,200,800,1,32,0};,(sizeof BITMAPINFOHEADER, 100,200,1,32,0,0,0,0,0,0)}

.code

; --------------------------------------------------------------------------------------------------
; Method:     Splash.Done
; Purpose:    Finalize the Splash object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method Splash.Done, uses xsi
  SetObject xsi

  ;Wait to finish the fade in
  invoke WaitForSingleObject, [xsi].hEvent, INFINITE
  invoke CloseHandle, [xsi].hEvent
  m2z [xsi].hEvent

  ;Housekeeping
  invoke CloseHandle, [xsi].hThread
  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBmp
  invoke DeleteDC, [xsi].hMemDC
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Splash.Init
; Purpose:    Initialize the Splash object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: BMP HANDLE.
;             Arg3: RGB transparent BMP color.
; Return:     Nothing.

Method Splash.Init, uses xsi, pOwner:POINTER, hBmp:HBITMAP, dTranparentColor:DWORD
  local hScreenDC:HDC

  SetObject xsi
  ACall xsi.Init, pOwner, NULL
  ;Get BMP information
  invoke GetObject, hBmp, sizeof BITMAP, addr [xsi].BmpData

  ;Create a region of the bitmap to skin the window
  mov hScreenDC, $invoke(GetDC, 0)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hScreenDC)
  invoke ReleaseDC, 0, hScreenDC
  mov [xsi].hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, hBmp)
  mov [xsi].hSkinRegion, $invoke(Bmp2Rgn, hBmp, dTranparentColor)

  ;Create worker thread to fade in the splash window
  mov [xsi].hEvent, $invoke(CreateEvent, NULL, FALSE, FALSE, NULL)
  invoke CreateThread, NULL, 0, $MethodAddr(Splash.Worker), xsi, CREATE_SUSPENDED, NULL
  mov [xsi].hThread, xax
  invoke SetEvent, [xsi].hEvent
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Splash.FadeIn
; Purpose:    Start the fade in process.
; Arguments:  None.
; Return:     Nothing.

Method Splash.FadeIn, uses xsi
  SetObject xsi
  invoke ResetEvent, [xsi].hEvent
  invoke ResumeThread, [xsi].hThread
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Splash.FadeOut
; Purpose:    Start the fade out process.
; Arguments:  None.
; Return:     Nothing.

Method Splash.FadeOut
  SetObject xcx
  invoke SetEvent, [xcx].hEvent
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Splash.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Splash.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke BitBlt, xax, 0, 0, [xsi].BmpData.bmWidth, [xsi].BmpData.bmHeight, \
                 [xsi].hMemDC, 0, 0, SRCCOPY
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Splash.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Splash.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_SAVEBITS or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(Splash.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szSplash, xdx
  m2z WC.hIcon
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_WAIT)

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Splash.Worker
; Purpose:    Worker thread called by Init method.
; Arguments:  None.
; Return:     Nothing.

Method Splash.Worker, uses xsi
  local dPosX:DWORD, dPosY:DWORD

  SetObject xsi, Splash

  ;Window creation
  invoke CenterForm, [xsi].BmpData.bmWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))
  mov dPosX, eax
  invoke CenterForm, [xsi].BmpData.bmHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))
  mov dPosY, eax
  invoke CreateWindowEx, WS_EX_TOOLWINDOW or WS_EX_TOPMOST or WS_EX_LAYERED, \
             offset szSplash, offset szSplash, WS_POPUP, \
             dPosX, dPosY, [xsi].BmpData.bmWidth, [xsi].BmpData.bmHeight, 0, 0, hInstance, pSelf
  invoke SetWindowRgn, [xsi].hWnd, [xsi].hSkinRegion, FALSE ;The region is now owned by the window!

  ;Fade in/out
  invoke SetThreadPriority, [xsi].hThread, THREAD_PRIORITY_TIME_CRITICAL
  invoke WndFadeIn, [xsi].hWnd, 0, 255, 15, 20
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
  invoke SetThreadPriority, [xsi].hThread, THREAD_PRIORITY_LOWEST
  invoke Sleep, [xsi].dMinShowTime
  invoke WaitForSingleObject, [xsi].hEvent, INFINITE
  invoke ResetEvent, [xsi].hEvent                       ;Signal we are redy with the fade in
  invoke SetThreadPriority, [xsi].hThread, THREAD_PRIORITY_TIME_CRITICAL
  invoke WndFadeOut, [xsi].hWnd, 255, 0, 15, 20

  ;Window destruction
  invoke DestroyWindow, [xsi].hWnd
  invoke SetEvent, [xsi].hEvent                         ;Signal we are redy with the fade in
MethodEnd

endif
