;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\dciddi.h', last modified: 19/04/2018 10:47
;Creation parameters: 

ifndef _INC_DCIDDI
  _INC_DCIDDI equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    DCICOMMAND equ 3075
    DCI_VERSION equ 0100h
    DCICREATEPRIMARYSURFACE equ 1
    DCICREATEOFFSCREENSURFACE equ 2
    DCICREATEOVERLAYSURFACE equ 3
    DCIENUMSURFACE equ 4
    DCIESCAPE equ 5
    DCI_OK equ 0
    DCI_FAIL_GENERIC equ -1
    DCI_FAIL_UNSUPPORTEDVERSION equ -2
    DCI_FAIL_INVALIDSURFACE equ -3
    DCI_FAIL_UNSUPPORTED equ -4
    DCI_ERR_CURRENTLYNOTAVAIL equ -5
    DCI_ERR_INVALIDRECT equ -6
    DCI_ERR_UNSUPPORTEDFORMAT equ -7
    DCI_ERR_UNSUPPORTEDMASK equ -8
    DCI_ERR_TOOBIGHEIGHT equ -9
    DCI_ERR_TOOBIGWIDTH equ -10
    DCI_ERR_TOOBIGSIZE equ -11
    DCI_ERR_OUTOFMEMORY equ -12
    DCI_ERR_INVALIDPOSITION equ -13
    DCI_ERR_INVALIDSTRETCH equ -14
    DCI_ERR_INVALIDCLIPLIST equ -15
    DCI_ERR_SURFACEISOBSCURED equ -16
    DCI_ERR_XALIGN equ -17
    DCI_ERR_YALIGN equ -18
    DCI_ERR_XYALIGN equ -19
    DCI_ERR_WIDTHALIGN equ -20
    DCI_ERR_HEIGHTALIGN equ -21
    DCI_STATUS_POINTERCHANGED equ 1
    DCI_STATUS_STRIDECHANGED equ 2
    DCI_STATUS_FORMATCHANGED equ 4
    DCI_STATUS_SURFACEINFOCHANGED equ 8
    DCI_STATUS_CHROMAKEYCHANGED equ 16
    DCI_STATUS_WASSTILLDRAWING equ 32
    DCI_SUCCESS macro error_
      exitm <(((DCIRVAL) error_) >= 0)>
    endm
    DCI_SURFACE_TYPE equ 0000000Fh
    DCI_PRIMARY equ 00000000h
    DCI_OFFSCREEN equ 00000001h
    DCI_OVERLAY equ 00000002h
    DCI_VISIBLE equ 00000010h
    DCI_CHROMAKEY equ 00000020h
    DCI_1632_ACCESS equ 00000040h
    DCI_DWORDSIZE equ 00000080h
    DCI_DWORDALIGN equ 00000100h
    DCI_WRITEONLY equ 00000200h
    DCI_ASYNC equ 00000400h
    DCI_CAN_STRETCHX equ 00001000h
    DCI_CAN_STRETCHY equ 00002000h
    DCI_CAN_STRETCHXY equ <(DCI_CAN_STRETCHX or DCI_CAN_STRETCHY)>
    DCI_CAN_STRETCHXN equ 00004000h
    DCI_CAN_STRETCHYN equ 00008000h
    DCI_CAN_STRETCHXYN equ <(DCI_CAN_STRETCHXN or DCI_CAN_STRETCHYN)>
    DCI_CANOVERLAY equ 00010000h
    if (WINVER lt 0400h)
      ifndef RDH_RECTANGLES
        RECTL struct
          left LONG ?
          top LONG ?
          right LONG ?
          bottom LONG ?
        RECTL ends

        tagRECTL typedef RECTL
        PRECTL typedef ptr RECTL
        NPRECTL typedef ptr RECTL
        LPRECTL typedef ptr RECTL
        LPCRECTL typedef ptr RECTL
        RDH_RECTANGLES equ 0
        RGNDATAHEADER struct
          dwSize DWORD ?
          iType DWORD ?
          nCount DWORD ?
          nRgnSize DWORD ?
          rcBound RECTL <>
        RGNDATAHEADER ends

        tagRGNDATAHEADER typedef RGNDATAHEADER
        PRGNDATAHEADER typedef ptr RGNDATAHEADER
        NPRGNDATAHEADER typedef ptr RGNDATAHEADER
        LPRGNDATAHEADER typedef ptr RGNDATAHEADER
        LPCRGNDATAHEADER typedef ptr RGNDATAHEADER
        RGNDATA struct
          rdh RGNDATAHEADER <>
          Buffer SBYTE 1 dup (?)
        RGNDATA ends

        tagRGNDATA typedef RGNDATA
        PRGNDATA typedef ptr RGNDATA
        NPRGNDATA typedef ptr RGNDATA
        LPRGNDATA typedef ptr RGNDATA
        LPCRGNDATA typedef ptr RGNDATA
      endif
    endif
    DCIRVAL typedef SDWORD
    DCICMD struct
      dwCommand DWORD ?
      dwParam1 DWORD ?
      dwParam2 DWORD ?
      dwVersion DWORD ?
      dwReserved DWORD ?
    DCICMD ends

    _DCICMD typedef DCICMD
    DCICREATEINPUT struct
      cmd DCICMD <>
      dwCompression DWORD ?
      dwMask DWORD 3 dup (?)
      dwWidth DWORD ?
      dwHeight DWORD ?
      dwDCICaps DWORD ?
      dwBitCount DWORD ?
      lpSurface LPVOID ?
    DCICREATEINPUT ends

    _DCICREATEINPUT typedef DCICREATEINPUT
    LPDCICREATEINPUT typedef ptr DCICREATEINPUT
    
    DCISURFACEINFO struct
      dwSize DWORD ?
      dwDCICaps DWORD ?
      dwCompression DWORD ?
      dwMask DWORD 3 dup (?)
      dwWidth DWORD ?
      dwHeight DWORD ?
      lStride LONG ?
      dwBitCount DWORD ?
      dwOffSurface ULONG_PTR ?
      wSelSurface WORD ?
      wReserved WORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
      TYPE_BeginAccess typedef proto WIN_STD_CALL_CONV :LPVOID, :LPRECT
      BeginAccess typedef ptr TYPE_BeginAccess
      TYPE_EndAccess typedef proto WIN_STD_CALL_CONV :LPVOID
      EndAccess typedef ptr TYPE_EndAccess
      TYPE_DestroySurface typedef proto WIN_STD_CALL_CONV :LPVOID
      DestroySurface typedef ptr TYPE_DestroySurface
    DCISURFACEINFO ends

    _DCISURFACEINFO typedef DCISURFACEINFO
    LPDCISURFACEINFO typedef ptr DCISURFACEINFO
    
    TYPE_ENUM_CALLBACK typedef proto WIN_STD_CALL_CONV :LPDCISURFACEINFO, :LPVOID
    ENUM_CALLBACK typedef ptr TYPE_ENUM_CALLBACK
    DCIENUMINPUT struct
      cmd DCICMD <>
      rSrc RECT <>
      rDst RECT <>
      TYPE_EnumCallback typedef proto WIN_STD_CALL_CONV :LPDCISURFACEINFO, :LPVOID
      EnumCallback typedef ptr TYPE_EnumCallback
      lpContext LPVOID ?
    DCIENUMINPUT ends

    _DCIENUMINPUT typedef DCIENUMINPUT
    LPDCIENUMINPUT typedef ptr DCIENUMINPUT
    
    DCIPRIMARY typedef DCISURFACEINFO
    LPDCIPRIMARY typedef ptr DCISURFACEINFO
    DCIOFFSCREEN struct
      dciInfo DCISURFACEINFO <>
      TYPE_Draw typedef proto WIN_STD_CALL_CONV :LPVOID
      Draw typedef ptr TYPE_Draw
      TYPE_SetClipList typedef proto WIN_STD_CALL_CONV :LPVOID, :LPRGNDATA
      SetClipList typedef ptr TYPE_SetClipList
      TYPE_SetDestination typedef proto WIN_STD_CALL_CONV :LPVOID, :LPRECT, :LPRECT
      SetDestination typedef ptr TYPE_SetDestination
    DCIOFFSCREEN ends

    _DCIOFFSCREEN typedef DCIOFFSCREEN
    LPDCIOFFSCREEN typedef ptr DCIOFFSCREEN
    
    DCIOVERLAY struct
      dciInfo DCISURFACEINFO <>
      dwChromakeyValue DWORD ?
      dwChromakeyMask DWORD ?
    DCIOVERLAY ends

    _DCIOVERLAY typedef DCIOVERLAY
    LPDCIOVERLAY typedef ptr DCIOVERLAY
    
    ifndef YVU9
      YVU9 equ <mmioFOURCC('Y', 'V', 'U', '9')>
    endif
    ifndef Y411
      Y411 equ <mmioFOURCC('Y', '4', '1', '1')>
    endif
    ifndef YUY2
      YUY2 equ <mmioFOURCC('Y', 'U', 'Y', '2')>
    endif
    ifndef YVYU
      YVYU equ <mmioFOURCC('Y', 'V', 'Y', 'U')>
    endif
    ifndef UYVY
      UYVY equ <mmioFOURCC('U', 'Y', 'V', 'Y')>
    endif
    ifndef Y211
      Y211 equ <mmioFOURCC('Y', '2', '1', '1')>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

