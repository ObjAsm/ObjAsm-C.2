; ==================================================================================================
; Title:      Demo02_Globals.inc
; Author:     G. Friedrich
; Purpose:    Global definitions for ObjAsm demonstration application Demo02.
; Version:    See Demo02.asm
;
; Description:
;   This file defines global constants, shared strings, and metadata used throughout the Demo02
;   application. These definitions are included by the main application modules and provide common
;   resources such as application titles, version text, and build information.
;
; ==================================================================================================


include Demo02_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)
