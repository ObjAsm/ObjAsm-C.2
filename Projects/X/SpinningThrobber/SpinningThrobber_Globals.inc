; ==================================================================================================
; Title:      SpinningThrobber_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Spinning Throbber.
; Notes:      Version C.1.0, August 2022
;               - Initial release.
; ==================================================================================================


include SpinningThrobber_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)

CStr cWarningMsg, "{PA15}", \
                  "[B,H+5,C#FF0000]Warning:  [~]", \
                  "[B,H+2]Unsupported Operating System[~]{P}", \
                  "[U]Description:[~]{P}", \ 
                  "[FI25]", \
                    "This Demo Application requires at least Windows 8.0{B}", \
                    "This operating system does not meet this requirement.{B}{B}", \
                  "[~]"

CStr cAppWarning, "Application Warning"

