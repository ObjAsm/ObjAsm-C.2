; ==================================================================================================
; Title:      WndPosMgr_Globals.inc
; Author:     G. Friedrich
; Version:    See WndPosMgr.asm
; ==================================================================================================


include WndPosMgr_Shared.inc

%CStr szAppTitle,     "&APP_TITLE"
%CStr szAboutText,    "&ABOUT_TEXT", 13, 10, \
                      "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                      "Designed with ObjAsm", 13, 10, \
                      "© &COPYRIGHT", 13, 10, 13, 10, \ 
                      @CatStr(<!">, %BUILD_DATE_STR, \
                              <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                              %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

CStr  szFileName,     "WndPosMgr.json"
CStr  szProfiles,     "Profiles"
CStr  szName,         "Name"
CStr  szWindows,      "Windows"
CStr  szCaption,      "Caption"
CStr  szClass,        "Class"
CStr  szLeft,         "Left"
CStr  szTop,          "Top"
CStr  szWidth,        "Width"
CStr  szHeight,       "Height"
CStr  szFlags,        "Flags"


String szUsageHeader, "WndPosMgr version ", @CatStr(<!">,<%VER_PRODUCTVERSION_STR>,<!">), ", ", \
                      @CatStr(<!">,<%COPYRIGHT>,<!">), CRLF
String szUsageText,   "Usage: WndPosMgr.exe [Option] ProfileName", CRLF
  ExtendString        "  Option: (prepended by '-' or '/')", CRLF
  ExtendString        "    -c Capture the position of all visible windows on the virtual desktop", CRLF
  ExtendString        "    -d Delete the profile ", CRLF
  ExtendString        "    -h | -?: show usage help", CRLF

COLOR_HEADER          equ FOREGROUND_GREEN or FOREGROUND_INTENSITY
COLOR_REGULAR         equ FOREGROUND_BLUE or FOREGROUND_GREEN or FOREGROUND_RED
COLOR_WARNING         equ FOREGROUND_RED
COLOR_ERROR           equ FOREGROUND_RED or FOREGROUND_INTENSITY
COLOR_QUESTION        equ FOREGROUND_GREEN or FOREGROUND_INTENSITY