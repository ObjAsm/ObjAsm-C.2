; ==================================================================================================
; Title:      ITaskbarApp_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm ITaskbar Demo.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


include ITaskbarApp_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)
