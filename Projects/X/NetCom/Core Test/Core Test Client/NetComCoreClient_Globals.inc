; =================================================================================================
; Title:      NetComCoreClient_Globals.inc
; Author:     G. Friedrich
; Version:    See NetComCoreClient.asm
; Purpose:    NetCom Client Application.
; =================================================================================================


include NetComCoreClient_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)


