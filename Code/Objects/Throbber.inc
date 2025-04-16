; ==================================================================================================
; Title:      Throbber.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm implementation of Throbber base class.
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


TBR_STATUS_STOPPED    equ 0
TBR_STATUS_STARTING   equ 1
TBR_STATUS_RUNNING    equ 2
TBR_STATUS_STOPPING   equ 3

TBR_IMAGE_BMP         equ 0
TBR_IMAGE_PNG         equ 1

TBR_FLAG_SELF_INST                equ BIT00     ;Creation info
TBR_FLAG_ANIMATION_THREAD_STOP    equ BIT01     ;Command
TBR_FLAG_ANIMATION_THREAD_FREEZE  equ BIT02     ;Command
TBR_FLAG_ANIMATION_THREAD_FROZEN  equ BIT03     ;Feedback to MITBR_FLAG_ANIMATION_THREAD_FREEZE


DEF_THROBBER struc
  xCtlID        XWORD     ?         ;Contol ID
  dStyle        DWORD     ?         ;Style
  dExStyle      DWORD     ?         ;Extended style
  pTitle        PSTRING   ?         ;-> Window text
  sdPosX        SDWORD    ?         ;X position
  sdPosY        SDWORD    ?         ;Y position
  dInterval     DWORD     ?         ;Animation frame presentation interval
  dImageType    DWORD     ?         ;0: BMP, 1: PNG
DEF_THROBBER ends
PDEF_THROBBER typedef ptr DEF_THROBBER


; --------------------------------------------------------------------------------------------------
; Object:  Throbber
; Purpose: Control that shows an animation, like GIF but mit transparency.

Object Throbber, ThrobberID, WinPrimer
  VirtualAbstract   Animate  
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  VirtualAbstract   Dispose  
  RedefineMethod    Done
  VirtualMethod     Freeze
  VirtualMethod     Resume
  VirtualMethod     Start
  VirtualMethod     Stop

  DefineVariable    dFlags,             DWORD,    0
  DefineVariable    dStatus,            DWORD,    TBR_STATUS_STOPPED
  DefineVariable    hThread,            HANDLE,   0
  DefineVariable    BmpSize,            POINT,    {}
  DefineVariable    dInterval,          DWORD,    50          ;Frame presentation interval

  DefineVariable    r4Scaling,          REAL4,    0.0         ;Factor <= 1.0
  DefineVariable    r4ScalingChange,    REAL4,    0.05        ;Factor/Frame
  DefineVariable    dAlpha,             DWORD,    0           ;Factor 0..255
  DefineVariable    dAlphaChange,       DWORD,    255/20      ;Alpha/Frame
ObjectEnd


; ==================================================================================================

if IMPLEMENT

TBR_STATUS_STOPPED    equ 0
TBR_STATUS_STARTING   equ 1
TBR_STATUS_RUNNING    equ 2
TBR_STATUS_STOPPING   equ 3

TBR_SCALE_START_END   equ 1.0
TBR_SCALE_STOP_END    equ 0.0

; --------------------------------------------------------------------------------------------------
; Method:     Throbber.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method Throbber.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Throbber.Done
; Purpose:    None.
; Return:     Nothing.

Method Throbber.Done, uses xsi
  SetObject xsi

  BitSet [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_STOP
  invoke WaitForSingleObject, [xsi].hThread, INFINITE
  invoke CloseHandle, [xsi].hThread
  OCall xsi.Dispose
  .ifBitClr [xsi].dFlags, TBR_FLAG_SELF_INST
    invoke DestroyWindow, [xsi].hWnd
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Throbber.Freeze
; Purpose:    Halt the animation, e.g. to make changes on the images (delete, add, etc.)
; Arguments:  None.
; Return:     Nothing.

Method Throbber.Freeze, uses xbx xsi
  SetObject xsi
  mov ebx, [xsi].dInterval                              ;Save current value
  mov [xsi].dInterval, 0                                ;Skip waiting in the thread loop
  BitSet [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_FREEZE
  @@:
  .ifBitClr [xsi].dFlags, TBR_FLAG_ANIMATION_THREAD_FROZEN ;Check if the state was reached
    invoke Sleep, ebx                                   ;Wait
    jmp @B
  .endif
  mov [xsi].dInterval, ebx                              ;Restore setting
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Throbber.Resume
; Purpose:    Resume animation after a freeze state.
; Arguments:  None.
; Return:     Nothing.

Method Throbber.Resume
  SetObject xcx
  BitClr [xcx].dFlags, TBR_FLAG_ANIMATION_THREAD_FREEZE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Throbber.Start
; Purpose:    Start spinning.
; Arguments:  Arg1: Interval between steps.
; Return:     Nothing.

Method Throbber.Start
  SetObject xcx
  mov [xcx].dStatus, TBR_STATUS_STARTING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Throbber.Stop
; Purpose:    Stop spinning.
; Arguments:  None.
; Return:     Nothing.

Method Throbber.Stop
  SetObject xcx
  mov [xcx].dStatus, TBR_STATUS_STOPPING
MethodEnd

endif
