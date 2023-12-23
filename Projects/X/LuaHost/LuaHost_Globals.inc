; ==================================================================================================
; Title:      LuaHost_Globals.inc
; Author:     G. Friedrich
; Version:    See LuaHost.asm
; Purpose:    ObjAsm LuaHost Application.
; ==================================================================================================


include LuaHost_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

IDC_TEXT_ABOUT      equ   100

IDD_MAIN            equ   1000
IDC_RED_SCRIPT      equ   1001
IDC_RED_OUTPUT      equ   1002
IDC_BTN_LOAD        equ   1003
IDC_BTN_SAVE        equ   1004
IDC_BTN_RUN         equ   1005
IDC_BTN_STOP        equ   1006
IDC_BTN_ABOUT       equ   1007
IDC_SBR_GRIPPER     equ   1008


CStr szCaption,     "ObjAsm  - LuaHost Demonstration -  "
CStr szLoadFilter,  "Lua files (*.lua)", 0, "*.lua", 0
CStr szFileTypeErr, "Error: Unknown file type."
CStr szLuaExt,      ".lua"
