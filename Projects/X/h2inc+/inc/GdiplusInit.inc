;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusinit.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 08/01/2024 17:05:14

ifndef _GDIPLUSINIT_H
  _GDIPLUSINIT_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
    DebugEventLevel typedef SDWORD
    DebugEventLevelFatal equ 0
    DebugEventLevelWarning equ 1

    TYPE_DebugEventProc typedef proto WIN_STD_CALL_CONV :DebugEventLevel, :ptr CHAR
    DebugEventProc typedef ptr TYPE_DebugEventProc

    TYPE_NotificationHookProc typedef proto WIN_STD_CALL_CONV :ptr ULONG_PTR
    NotificationHookProc typedef ptr TYPE_NotificationHookProc

    TYPE_NotificationUnhookProc typedef proto WIN_STD_CALL_CONV :ULONG_PTR
    NotificationUnhookProc typedef ptr TYPE_NotificationUnhookProc

    GdiplusStartupInput struct
      GdiplusVersion UINT32 ?
      DebugEventCallback DebugEventProc ?
      SuppressBackgroundThread BOOL ?
      SuppressExternalCodecs BOOL ?
      GdiplusStartupInput typedef proto :DebugEventProc, :BOOL, :BOOL
    GdiplusStartupInput ends
    if (GDIPVER ge 0110h)
      2 typedef GdiplusStartupInputEx
      } typedef GdiplusStartupInputEx
      GdiplusStartupInputEx proto WIN_STD_CALL_CONV :INT_, :DebugEventProc, :BOOL, :BOOL
      GdiplusStartupInputEx proto WIN_STD_CALL_CONV :Version, :INT_, :DebugEventProc, :BOOL, :BOOL
      static_cast proto WIN_STD_CALL_CONV :gdiplusVersion
      GdiplusStartupParams typedef SDWORD
      GdiplusStartupDefault equ 00000000h
      GdiplusStartupNoSetRound equ 00000001h
      GdiplusStartupSetPSValue equ 00000002h
      GdiplusStartupReserved0 equ 00000004h
      GdiplusStartupTransparencyMask equ 0FF000000h

    endif
    GdiplusStartupOutput struct
      NotificationHook NotificationHookProc ?
      NotificationUnhook NotificationUnhookProc ?
    GdiplusStartupOutput ends
    GdiplusStartup proto WIN_STD_CALL_CONV :ptr ULONG_PTR, :ptr GdiplusStartupInput, :ptr GdiplusStartupOutput
    GdiplusShutdown proto WIN_STD_CALL_CONV :ULONG_PTR
    if _MSC_VER ge 1200
    endif
  endif
endif
