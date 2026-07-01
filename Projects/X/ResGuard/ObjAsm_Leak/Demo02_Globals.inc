; ==================================================================================================
; Title:      Demo02_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 2.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


include Demo02_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", CRLF, \
                  "Version &VER_PRODUCTVERSION_STR", CRLF, \
                  "Designed with ObjAsm", CRLF, \
                  "© &COPYRIGHT", CRLF, CRLF, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)
