; ==================================================================================================
; Title:      Demo10_Serial_Globals.inc
; Author:     G. Friedrich
; Version:    See Demo10_Serial.asm
; Purpose:    ObjAsm Demo Application 10 with serialization.
; ==================================================================================================


include Demo10_Serial_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

DemoApp10ID     equ   5483621
MyClientID      equ   5483622
MyChildID       equ   5483623

.data
dSetupOption1   DWORD   3     ;None
