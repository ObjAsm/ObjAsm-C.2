; ==================================================================================================
; Title:   MemLeak.asm
; Author:  G. Friedrich  @ March 2005
; Version: 1.0.0
; Purpose: Memory Leakage demonstration program.
; ==================================================================================================


%include @Environ(OA32_PATH)\\Code\\Macros\\Model.inc       ;Include & initialize standard modules
SysSetup OOP_WINDOWS, DEBUG(WND, RESGUARD)                  ;Loads OOP files and OS related objects

include MemLeak_Globals.inc                                 ;Includes application globals

;Load or build the following objects
LoadObjects Stream, Collection             
LoadObjects Dialog, DialogModal, DialogAbout
LoadObjects DialogModeless, DialogModalIndirect
LoadObjects SimpleImageList, MaskedImageList
LoadObjects MsgInterceptor, WinControl, Toolbar, Rebar, Statusbar, Tooltip, XMenu
LoadObjects WinApp, SdiApp

.code
include MemLeak.inc                                         ;Includes MemLeak object

start:                                                      ;Program entry point
    SysInit                                                 ;Runtime initialization of OOP model

    ResGuard_Start                                          ;Activates ResGuard system
    invoke P0, 123
    OCall TPL_MemLeak::MemLeak.Init                         ;Initialize the object data
    OCall TPL_MemLeak::MemLeak.Run                          ;Execute the application
    OCall TPL_MemLeak::MemLeak.Done                         ;Finalize it
    ResGuard_Show                                           ;Shows ResGuard results

    SysDone                                                 ;Runtime finalization of the OOP model
    invoke ExitProcess, 0                                   ;Exits program returning 0 to the OS
end start                                                   ;Code end and defines prg entry point
