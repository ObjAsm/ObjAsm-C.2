; ==================================================================================================
; Title:      ShTypes.inc
; Transl.:    G. Friedrich
; Version:    C.1.0
; Purpose:    COM interfaces for shell objects.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


;===========================================================================
;
; Object identifiers in the explorer's name space (ItemID and IDList)
;
;  All the items that the user can browse with the explorer (such as files,
; directories, servers, work-groups, etc.) has an identifier which is unique
; among items within the parent folder. Those identifiers are called item
; IDs (SHITEMID). Since all its parent folders have their own item IDs,
; any items can be uniquely identified by a list of item IDs, which is called
; an ID list (ITEMIDLIST).
;
;  ID lists are almost always allocated by the task allocator (see some
; description below as well as OLE 2.0 SDK) and may be passed across
; some of shell interfaces (such as IShellFolder). Each item ID in an ID list
; is only meaningful to its parent folder (which has generated it), and all
; the clients must treat it as an opaque binary data except the first two
; bytes, which indicates the size of the item ID.
;
;  When a shell extension -- which implements the IShellFolder interace --
; generates an item ID, it may put any information in it, not only the data
; with that it needs to identifies the item, but also some additional
; information, which would help implementing some other functions efficiently.
; For example, the shell's IShellFolder implementation of file system items
; stores the primary (long) name of a file or a directory as the item
; identifier, but it also stores its alternative (short) name, size and date
; etc.
;
;  When an ID list is passed to one of shell APIs (such as SHGetPathFromIDList),
; it is always an absolute path -- relative from the root of the name space,
; which is the desktop folder. When an ID list is passed to one of IShellFolder
; member function, it is always a relative path from the folder (unless it
; is explicitly specified).
;
;===========================================================================

SHITEMID struc
    cb      USHORT  ?
    abID    BYTE    ?
SHITEMID ends

LPSHITEMID typedef ptr SHITEMID

ITEMIDLIST struc
    mkid    SHITEMID  {}
ITEMIDLIST ends


;ITEMIDLIST_RELATIVE (*PIDLIST_RELATIVE)
;variable count (>= 0 items) list of contiguous SHITEMIDs
;terminated with a zero-length SHITEMID
;relative to a parent folder

;ITEMID_CHILD (*PITEMID_CHILD)
;single item list (0 - 1 items) of contiguous SHITEMIDs
;terminated with a zero-length SHITEMID
;relative to a parent folder

;ITEMIDLIST_ABSOLUTE (*PIDLIST_ABSOLUTE)
;variable count list (>= 0 items) of contiguous SHITEMIDs
;terminated with a zero-length SHITEMID
;relative only to the Desktop folder
;an empty list is a pidl to the desktop itself


;This structure is defined in winbase.h which is not visible to idl files,
;so we redeclare it here.

WIN32_FIND_DATAA struc
    dwFileAttributes          DWORD       ?
    ftCreationTime            FILETIME    {}
    ftLastAccessTime          FILETIME    {}
    ftLastWriteTime           FILETIME    {}
    nFileSizeHigh             DWORD       ?
    nFileSizeLow              DWORD       ?
    dwReserved0               DWORD       ?
    dwReserved1               DWORD       ?
    cFileName                 CHRA MAX_PATH dup(?)
    cAlternateFileName        CHRA 14 dup (?)
ifdef _MAC
    dwFileType                DWORD       ?
    dwCreatorType             DWORD       ?
    wFinderFlags              WORD        ?
endif
WIN32_FIND_DATAA ends
LPWIN32_FIND_DATAA typedef ptr WIN32_FIND_DATAA

WIN32_FIND_DATAW struc
    dwFileAttributes          DWORD       ?
    ftCreationTime            FILETIME    {}
    ftLastAccessTime          FILETIME    {}
    ftLastWriteTime           FILETIME    {}
    nFileSizeHigh             DWORD       ?
    nFileSizeLow              DWORD       ?
    dwReserved0               DWORD       ?
    dwReserved1               DWORD       ?
    cFileName                 CHRW MAX_PATH dup(?)
    cAlternateFileName        CHRW 14 dup (?)
ifdef _MAC
    dwFileType                DWORD       ?
    dwCreatorType             DWORD       ?
    wFinderFlags              WORD        ?
endif
WIN32_FIND_DATAW ends
LPWIN32_FIND_DATAW typedef ptr WIN32_FIND_DATAW


STRRET_WSTR    equ  0000
STRRET_OFFSET  equ  0001
STRRET_CSTR    equ  0002


STRRET struct
    uType             DWORD   ?
    union
      pOleStr         LPWSTR  ?
      uOffset         DWORD   ?
      cStr            CHRA MAX_PATH dup(?)
    ends
STRRET ends
LPSTRRET typedef ptr STRRET


SHELLDETAILS struc
    fmt     SDWORD    ?
    cxChar  SDWORD    ?
    str_    STRRET    {}
SHELLDETAILS ends

PERCEIVED_TYPE_FIRST           equ  -3
PERCEIVED_TYPE_CUSTOM          equ  -3
PERCEIVED_TYPE_UNSPECIFIED     equ  -2
PERCEIVED_TYPE_FOLDER          equ  -1
PERCEIVED_TYPE_UNKNOWN         equ  0
PERCEIVED_TYPE_TEXT            equ  1
PERCEIVED_TYPE_IMAGE           equ  2
PERCEIVED_TYPE_AUDIO           equ  3
PERCEIVED_TYPE_VIDEO           equ  4
PERCEIVED_TYPE_COMPRESSED      equ  5
PERCEIVED_TYPE_DOCUMENT        equ  6
PERCEIVED_TYPE_SYSTEM          equ  7
PERCEIVED_TYPE_APPLICATION     equ  8
PERCEIVED_TYPE_GAMEMEDIA       equ  9
PERCEIVED_TYPE_CONTACTS        equ  10
PERCEIVED_TYPE_LAST            equ  10

PERCEIVEDFLAG typedef DWORD

COMDLG_FILTERSPEC struc
    pszName     LPCWSTR     ?
    pszSpec     LPCWSTR     ?
COMDLG_FILTERSPEC ends

KNOWNFOLDERID typedef GUID
FOLDERTYPEID typedef GUID
REFFOLDERTYPEID typedef ptr FOLDERTYPEID
TASKOWNERID typedef GUID
REFTASKOWNERID typedef ptr TASKOWNERID
ELEMENTID typedef GUID
REFELEMENTID typedef ptr ELEMENTID

LF_FACESIZE equ 32

LOGFONTA struc
    lfHeight                LONG  ?    
    lfWidth                 LONG  ?    
    lfEscapement            LONG  ?    
    lfOrientation           LONG  ?    
    lfWeight                LONG  ?    
    lfItalic                BYTE  ?    
    lfUnderline             BYTE  ?    
    lfStrikeOut             BYTE  ?    
    lfCharSet               BYTE  ?    
    lfOutPrecision          BYTE  ?    
    lfClipPrecision         BYTE  ?    
    lfQuality               BYTE  ?    
    lfPitchAndFamily        BYTE  ?    
    lfFaceName              CHRA LF_FACESIZE dup(?)
LOGFONTA ends
PLOGFONTA typedef ptr LOGFONTA

LOGFONTW struc
    lfHeight                LONG  ?    
    lfWidth                 LONG  ?    
    lfEscapement            LONG  ?    
    lfOrientation           LONG  ?    
    lfWeight                LONG  ?    
    lfItalic                BYTE  ?    
    lfUnderline             BYTE  ?    
    lfStrikeOut             BYTE  ?    
    lfCharSet               BYTE  ?    
    lfOutPrecision          BYTE  ?    
    lfClipPrecision         BYTE  ?    
    lfQuality               BYTE  ?    
    lfPitchAndFamily        BYTE  ?    
    lfFaceName              CHRW LF_FACESIZE dup(?)
LOGFONTW ends
PLOGFONTW typedef ptr LOGFONTW

ifdef UNICODE
  LOGFONT typedef LOGFONTW
  PLOGFONT typedef ptr LOGFONTW
else
  LOGFONT typedef LOGFONTA
  PLOGFONT typedef ptr LOGFONTA
endif

SHCOLSTATE_DEFAULT            equ 00000000h
SHCOLSTATE_TYPE_STR           equ 00000001h
SHCOLSTATE_TYPE_INT           equ 00000002h
SHCOLSTATE_TYPE_DATE          equ 00000003h
SHCOLSTATE_TYPEMASK           equ 0000000Fh
SHCOLSTATE_ONBYDEFAULT        equ 00000010h   ;should on by default in details view
SHCOLSTATE_SLOW               equ 00000020h   ;will be slow to compute, do on a background thread
SHCOLSTATE_EXTENDED           equ 00000040h   ;provided by a handler, not the folder
SHCOLSTATE_SECONDARYUI        equ 00000080h   ;not displayed in context menu, but listed in the "More..." dialog
SHCOLSTATE_HIDDEN             equ 00000100h   ;not displayed in the UI
SHCOLSTATE_PREFER_VARCMP      equ 00000200h   ;VarCmp() (with folderness test) produces same result as CompareIDs()
SHCOLSTATE_PREFER_FMTCMP      equ 00000400h   ;comparison of PSFormatForDisplay result produces same result as CompareIDs()
SHCOLSTATE_NOSORTBYFOLDERNESS equ 00000800h   ;do not sort folders separately
SHCOLSTATE_VIEWONLY           equ 00010000h   ;only displayed in the UI
SHCOLSTATE_BATCHREAD          equ 00020000h   ;marks columns with values that should be read in a batch
SHCOLSTATE_NO_GROUPBY         equ 00040000h   ;grouping is disabled for this column
SHCOLSTATE_FIXED_WIDTH        equ 00001000h   ;Can't resize the column
SHCOLSTATE_NODPISCALE         equ 00002000h   ;Width is the same in all DPIs
SHCOLSTATE_FIXED_RATIO        equ 00004000h   ;Fixed width augments with height
SHCOLSTATE_DISPLAYMASK        equ 0000F000h   ;To filter out new display flags

SHCOLSTATEF typedef DWORD

;SHCOLUMNID typedef PROPERTYKEY
LPCSHCOLUMNID typedef ptr SHCOLUMNID

;This enum matches the ResolutionScale enum in DisplayProperties.idl.
;Do NOT modify without updating it there as well.

SCALE_100_PERCENT   equ 100
SCALE_120_PERCENT   equ 120   ;phone only
SCALE_140_PERCENT   equ 140
SCALE_150_PERCENT   equ 150   ;phone only
SCALE_160_PERCENT   equ 160   ;phone only
SCALE_180_PERCENT   equ 180
SCALE_225_PERCENT   equ 225   ;phone only
