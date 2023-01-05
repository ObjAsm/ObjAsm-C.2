; ==================================================================================================
; Title:      IcmpApp_Globals.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm IcmpApp.
; Notes:      Version C.2.0, December 2022
;               - First release.
; ==================================================================================================


include IcmpApp_Shared.inc

CStr szIcoName,   "ICON_APP"
%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)

CStr cErrDestCpt, "ICMP Application Message"
CStr cErrDestMsg, "{PA20}", \
                  "[FI55]",\
                    "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                    "[H+2]Invalid Destination[~]{P}", \
                    "[C#5F4FFF]", \
                      "[I]Enter a valid destination URL or IP address[~]", \
                    "[~]", \
                  "[~]"

DSTTYPE_NONE      equ   0
DSTTYPE_IPV4      equ   1
DSTTYPE_IPV6      equ   2
DSTTYPE_URL       equ   3

EM_GETZOOM equ (WM_USER + 224)
EM_SETZOOM equ (WM_USER + 225)

