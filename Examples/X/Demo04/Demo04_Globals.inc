; ==================================================================================================
; Title:      Demo04_Globals.inc
; Author:     G. Friedrich
; Purpose:    Global definitions for ObjAsm demonstration application Demo04.
; Version:    See Demo04.asm
;
; Description:
;   This file defines global constants, shared strings, and metadata used throughout the Demo04
;   application. These definitions are included by the main application modules and provide common
;   resources such as application titles, version text, and build information.
;
; ==================================================================================================


include Demo04_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)
