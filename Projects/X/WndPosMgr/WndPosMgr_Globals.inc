; ==================================================================================================
; Title:      WndPosMgr_Globals.inc
; Author:     G. Friedrich
; Version:    See WndPosMgr.asm
; ==================================================================================================


include WndPosMgr_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)


String cUsageHeader,"WndPosMgr version ", @CatStr(<!">,<%VER_PRODUCTVERSION_STR>,<!">), ", ", @CatStr(<!">,<%COPYRIGHT>,<!">), CRLF
String cUsageText,  "Usage: WndPosMgr.exe [Options] ProfileName", CRLF
  ExtendString      "  Options: (prepended by '-' or '/')", CRLF
  ExtendString      "    -c capture virtual desktop window positions", CRLF
  ExtendString      "    -h | -?: show usage help", CRLF

COLOR_HEADER            equ FOREGROUND_GREEN or FOREGROUND_INTENSITY
COLOR_REGULAR           equ FOREGROUND_BLUE or FOREGROUND_GREEN or FOREGROUND_RED
COLOR_WARNING           equ FOREGROUND_RED
COLOR_ERROR             equ FOREGROUND_RED or FOREGROUND_INTENSITY
COLOR_QUESTION          equ FOREGROUND_GREEN or FOREGROUND_INTENSITY