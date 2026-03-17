; ==================================================================================================
; Title:      Demo03_Globals.inc
; Author:     G. Friedrich
; Purpose:    Global definitions for ObjAsm demonstration application Demo03.
; Version:    See Demo03.asm
;
; Description:
;   This module defines the global constants, text resources, and build-time metadata used by
;   the Demo03 application. These values are referenced by the main application object and the
;   resource script to provide:
;     - Application title and about-box text
;     - Icon and bitmap resource identifiers
;     - Version information and build details
;
;   Build-related fields (e.g., BUILD_NUMBER, BUILD_DATE_STR) are automatically updated by the
;   build process to ensure synchronized versioning across all compiled components.
;
; ==================================================================================================


include Demo03_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

