;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusinit.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 08/01/2024 17:05:14

;**************************************************************************
ifndef _GDIPLUSINIT_H
  _GDIPLUSINIT_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* padding added after data member *
    endif
    DebugEventLevel typedef SDWORD
    DebugEventLevelFatal equ 0
    DebugEventLevelWarning equ 1

    ; Callback function that GDI+ can call, on debug builds, for assertions
    ; and warnings.
    TYPE_DebugEventProc typedef proto WIN_STD_CALL_CONV :DebugEventLevel, :ptr CHAR
    DebugEventProc typedef ptr TYPE_DebugEventProc

    ; Notification functions which the user must call appropriately if
    ; "SuppressBackgroundThread" (below) is set.
    TYPE_NotificationHookProc typedef proto WIN_STD_CALL_CONV :ptr ULONG_PTR
    NotificationHookProc typedef ptr TYPE_NotificationHookProc

    TYPE_NotificationUnhookProc typedef proto WIN_STD_CALL_CONV :ULONG_PTR
    NotificationUnhookProc typedef ptr TYPE_NotificationUnhookProc

    ; Input structure for GdiplusStartup()
    GdiplusStartupInput struct
      GdiplusVersion DWORD ?
      ; Must be 1  (or 2 for the Ex version)
      DebugEventCallback DebugEventProc ?
      ; Ignored on free builds
      SuppressBackgroundThread DWORD ?
      ; FALSE unless you're prepared to call 
      ; the hook/unhook functions properly
      SuppressExternalCodecs DWORD ?
      ; FALSE unless you want GDI+ only to use
      ; its internal image codecs.
      GdiplusStartupInput typedef proto :DebugEventProc, :BOOL, :BOOL
    GdiplusStartupInput ends
    if (GDIPVER ge 0110h)
      2 typedef GdiplusStartupInputEx
      ; Enables Heif and Avif image codecs.  Unlike other functionalities in Gdiplus,
      ; these two codecs require COM to be initiailized.
      } typedef GdiplusStartupInputEx
      ; Do we not set the FPU rounding mode
      GdiplusStartupInputEx proto WIN_STD_CALL_CONV :INT_, :DebugEventProc, :BOOL, :BOOL
      GdiplusStartupInputEx proto WIN_STD_CALL_CONV :Version, :INT_, :DebugEventProc, :BOOL, :BOOL
      UINT32 proto WIN_STD_CALL_CONV :gdiplusVersion
      GdiplusStartupParams typedef SDWORD
      GdiplusStartupDefault equ 00000000h
      GdiplusStartupNoSetRound equ 00000001h
      GdiplusStartupSetPSValue equ 00000002h
      GdiplusStartupReserved0 equ 00000004h
      GdiplusStartupTransparencyMask equ 0FF000000h

    endif
    ; Output structure for GdiplusStartup()
    GdiplusStartupOutput struct
      ; The following 2 fields are NULL if SuppressBackgroundThread is FALSE.
      ; Otherwise, they are functions which must be called appropriately to
      ; replace the background thread.
      ; These should be called on the application's main message loop - i.e.
      ; a message loop which is active for the lifetime of GDI+.
      ; "NotificationHook" should be called before starting the loop,
      ; and "NotificationUnhook" should be called after the loop ends.
      NotificationHook NotificationHookProc ?
      NotificationUnhook NotificationUnhookProc ?
    GdiplusStartupOutput ends
    ; GDI+ initialization. Must not be called from DllMain - can cause deadlock.
    ; Must be called before GDI+ API's or constructors are used.
    ; token  - may not be NULL - accepts a token to be passed in the corresponding
    ;          GdiplusShutdown call.
    ; input  - may not be NULL
    ; output - may be NULL only if input->SuppressBackgroundThread is FALSE.
    GdiplusStartup proto WIN_STD_CALL_CONV :ptr ULONG_PTR, :ptr GdiplusStartupInput, :ptr GdiplusStartupOutput
    ; GDI+ termination. Must be called before GDI+ is unloaded. 
    ; Must not be called from DllMain - can cause deadlock.
    ; GDI+ API's may not be called after GdiplusShutdown. Pay careful attention
    ; to GDI+ object destructors.
    GdiplusShutdown proto WIN_STD_CALL_CONV :ULONG_PTR
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
