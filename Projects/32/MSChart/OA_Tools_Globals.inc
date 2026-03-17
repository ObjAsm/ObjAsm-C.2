; ==================================================================================================
; Title:      OA_Tools_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Tools for ObjAsm.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


include OA_Tools_Shared.inc

%CStr szAppTitle,   "&APP_TITLE"
%CStr szAboutText,  "&ABOUT_TEXT", 13, 10, \
                    "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                    "Designed with ObjAsm", 13, 10, \
                    "© &COPYRIGHT", 13, 10, 13, 10, \ 
                    @CatStr(<!">, %BUILD_DATE_STR, \
                            <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                            %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

CStr szRegKey,      "Software\OA_Tools"
CStr szCOMViewErr,  "COMView can not be started.", 13, 10, \
                    "Probably it is not installed...", 13, 10, \
                    "You can download it from:", 13, 10, \
                    "http://www.japheth.de"

CStr szOLEViewErr,  "OLEView can not be started.", 13, 10, \
                    "Probably it is not installed..."

CStr szRegSrv1,     "\WINDOWS\SYSTEM\REGSVR32.EXE"
CStr szRegSrv2,     "\WINDOWS\SYSTEM32\REGSVR32.EXE"

;Object IDs
OA_ToolsID          equ    100000
ClientWndID         equ    100001
ChildWndID          equ    100002

