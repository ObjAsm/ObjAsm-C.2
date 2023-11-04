; ==================================================================================================
; Title:      CursorIconStructs.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Cursor and Icon structure definitions not found in MS header files.
; Notes:      Version C.1.0, November 2023
;               - First release.
; Links:      https://devblogs.microsoft.com/oldnewthing/20120720-00/?p=7083
;             https://devblogs.microsoft.com/oldnewthing/20231025-00/?p=108925
; ==================================================================================================


RES_ICON    equ 1
RES_CURSOR  equ 2

GRP_HEADER struct 2
  wReserved     WORD  ?
  wResType      WORD  ?
  wResCount     WORD  ?
GRP_HEADER ends
PGRP_HEADER typedef ptr GRP_HEADER

LOCALHEADER struct            ;https://learn.microsoft.com/en-us/windows/win32/menurc/localheader
  wHotSpotX     WORD  ?
  wHotSpotY     WORD  ?
LOCALHEADER ends

GRP_ENTRY_BEG struct 2        ;Common structure for File and Rsrc 
  bWidth        BYTE  ?
  bHeight       BYTE  ?
  bColorCount   BYTE  ?
  bReserved     BYTE  ?
  union
    struct                    ;Icons
      wPlanes   WORD  ?
      wBitCount WORD  ?
    ends
    struct                    ;Cursors
      wHotSpotX WORD  ?
      wHotSpotY WORD  ?
    ends
  ends
  dwBytesInRes  DWORD ?
GRP_ENTRY_BEG ends

GRP_FILE_ENTRY struct 2
  GRP_ENTRY_BEG       {}     
  dOffset       DWORD ?
GRP_FILE_ENTRY ends

GRP_RSRC_ENTRY struct 2
  GRP_ENTRY_BEG       {}     
  nIconCursorId WORD  ?
GRP_RSRC_ENTRY ends
