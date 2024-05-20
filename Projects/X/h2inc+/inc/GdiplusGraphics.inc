;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusgraphics.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUSGRAPHICS_H
  _GDIPLUSGRAPHICS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
        ;* signed/unsigned mismatch *
      endif
      ;* padding added after data member *
    endif
    ;------------------------------------------------------------------------
    ; GDI Interop methods
    ;------------------------------------------------------------------------
    ; Locks the graphics until ReleaseDC is called
    ;------------------------------------------------------------------------
    ; Rendering modes
    ;------------------------------------------------------------------------
    if (GDIPVER ge 0110h)
    endif
    ;(GDIPVER >= 0x0110)
    ;------------------------------------------------------------------------
    ; Manipulate current world transform
    ;------------------------------------------------------------------------
    ;------------------------------------------------------------------------
    ; GetNearestColor (for <= 8bpp surfaces).  Note: Alpha is ignored.
    ;------------------------------------------------------------------------
    ; Draw a cached bitmap on this graphics destination offset by
    ; x, y. Note this will fail with WrongState if the CachedBitmap
    ; native format differs from this Graphics.
    if (GDIPVER ge 0110h)
    endif
    ;(GDIPVER >= 0x0110)
    ; The following methods are for playing an EMF+ to a graphics
    ; via the enumeration interface.  Each record of the EMF+ is
    ; sent to the callback (along with the callbackData).  Then
    ; the callback can invoke the Metafile::PlayRecord method
    ; to play the particular record.
    ; This is different than the other SetClip methods because it assumes
    ; that the HRGN is already in device units, so it doesn't transform
    ; the coordinates in the HRGN.
    ; Only valid when recording metafiles.
    ;----------------------------------------------------------------------------
    ; Implementation of GraphicsPath methods that use Graphics
    ;----------------------------------------------------------------------------
    ; The GetBounds rectangle may not be the tightest bounds.
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
