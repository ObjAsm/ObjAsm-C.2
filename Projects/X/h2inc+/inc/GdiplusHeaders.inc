;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusheaders.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

;\**************************************************************************
ifndef _GDIPLUSHEADERS_H
  _GDIPLUSHEADERS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* member function does not override any base class virtual member function *
      ;* no override available for virtual member function from base 'class'; function is hidden *
      ;* padding added after data member *
    endif
    ; buffer     - where to put the data
    ; bufferSize - how big the buffer is (should be at least as big as GetDataSize())
    ; sizeFilled - if not NULL, this is an OUT param that says how many bytes
    ;              of data were written to the buffer.
    ;--------------------------------------------------------------------------
    ; FontFamily
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Font
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Font Collection
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Abstract base class for Image and Metafile
    ;--------------------------------------------------------------------------
    if (GDIPVER ge 0110h)
    endif
    ;(GDIPVER >= 0x0110)
    if (GDIPVER ge 0110h)
      ; The palette must be allocated and count must be set to the number of
      ; entries in the palette. If there are not enough, the API will fail.
      ; Palette to initialize.
      ; palette enumeration type.
      ; how many optimal colors
      ; add a transparent color to the palette.
      ; optional bitmap for median cut.
      ; optional parameter.
      ; optional parameter.
    endif
    ;(GDIPVER >= 0x0110)
    ; This changes both the start and end cap.
    ; Playback a metafile from a HMETAFILE
    ; If deleteWmf is TRUE, then when the metafile is deleted,
    ; the hWmf will also be deleted.  Otherwise, it won't be.
    ; Playback a metafile from a HENHMETAFILE
    ; If deleteEmf is TRUE, then when the metafile is deleted,
    ; the hEmf will also be deleted.  Otherwise, it won't be.
    ; Playback a WMF metafile from a file.
    ; Record a metafile to memory.
    ; Record a metafile to memory.
    ; Record a metafile to memory.
    ; Once this method is called, the Metafile object is in an invalid state
    ; and can no longer be used.  It is the responsiblity of the caller to
    ; invoke DeleteEnhMetaFile to delete this hEmf.
    ; Used in conjuction with Graphics::EnumerateMetafile to play an EMF+
    ; The data must be DWORD aligned if it's an EMF or EMF+.  It must be
    ; WORD aligned if it's a WMF.
    ; If you're using a printer HDC for the metafile, but you want the
    ; metafile rasterized at screen resolution, then use this API to set
    ; the rasterization dpi of the metafile to the screen resolution,
    ; e.g. 96 dpi or 120 dpi.
    if (GDIPVER ge 0110h)
    endif
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; !_GDIPLUSHEADERS.HPP
