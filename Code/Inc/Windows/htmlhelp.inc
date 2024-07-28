; htmlhelp.inc

HH_DISPLAY_TOPIC          equ 0000h
HH_HELP_FINDER            equ 0000h   ;WinHelp equivalent
HH_DISPLAY_TOC            equ 0001h
HH_DISPLAY_INDEX          equ 0002h
HH_DISPLAY_SEARCH         equ 0003h
HH_SET_WIN_TYPE           equ 0004h
HH_GET_WIN_TYPE           equ 0005h
HH_GET_WIN_HANDLE         equ 0006h
HH_ENUM_INFO_TYPE         equ 0007h   ;Get Info type name, call repeatedly to enumerate, -1 at end
HH_SET_INFO_TYPE          equ 0008h   ;Add Info type to filter.
HH_SYNC                   equ 0009h
HH_RESERVED1              equ 000Ah
HH_RESERVED2              equ 000Bh
HH_RESERVED3              equ 000Ch
HH_KEYWORD_LOOKUP         equ 000Dh
HH_DISPLAY_TEXT_POPUP     equ 000Eh   ;Display string resource id or text in a popup window
HH_HELP_CONTEXT           equ 000Fh   ;Display mapped numeric value in dwData
HH_TP_HELP_CONTEXTMENU    equ 0010h   ;Text popup help, same as WinHelp HELP_CONTEXTMENU
HH_TP_HELP_WM_HELP        equ 0011h   ;Text popup help, same as WinHelp HELP_WM_HELP
HH_CLOSE_ALL              equ 0012h   ;Close all windows opened directly or indirectly by the caller
HH_ALINK_LOOKUP           equ 0013h   ;ALink version of HH_KEYWORD_LOOKUP
HH_GET_LAST_ERROR         equ 0014h   ;Not currently implemented // See HHERROR.h
HH_ENUM_CATEGORY          equ 0015h	  ;Get category name, call repeatedly to enumerate, -1 at end
HH_ENUM_CATEGORY_IT       equ 0016h   ;Get category info type members, call repeatedly to enumerate, -1 at end
HH_RESET_IT_FILTER        equ 0017h   ;Clear the info type filter of all info types.
HH_SET_INCLUSIVE_FILTER   equ 0018h   ;set inclusive filtering method for untyped topics to be included in display
HH_SET_EXCLUSIVE_FILTER   equ 0019h   ;set exclusive filtering method for untyped topics to be excluded from display
HH_INITIALIZE             equ 001Ch   ;Initializes the help system.
HH_UNINITIALIZE           equ 001Dh   ;Uninitializes the help system.
HH_SET_QUERYSERVICE       equ 001Eh   ;Set the Host IQueryService interface
HH_PRETRANSLATEMESSAGE    equ 00fdh   ;Pumps messages. (NULL, NULL, MSG*).
HH_SET_GLOBAL_PROPERTY    equ 00fch   ;Set a global property. (NULL, NULL, HH_GPROP)
HH_SAFE_DISPLAY_TOPIC     equ 0020h   ;Private addition to the interface for InternetExplorer.


HtmlHelpA PROTO :HANDLE,:POINTER,:DWORD,:DWORD
HtmlHelpW PROTO :HANDLE,:POINTER,:DWORD,:DWORD

IFDEF UNICODE
  HtmlHelp equ <HtmlHelpW>
else
  HtmlHelp equ <HtmlHelpA>
endif