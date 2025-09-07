; ==================================================================================================
; Title:      WndPosMgr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm WndPosMgr.
; Notes:      Version 1.0.0, August 2025
;               - First release.
;             Version 1.1.0, September 2025
;               - When data is captured, any existing profile with the same name is replaced. 
;                 The remaining profiles are left untouched. 
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, CON64, WIDE_STRING;, DEBUG(WND)

% include &MacPath&LDLL.inc

MakeObjects Primer, Stream, DiskStream, ConsoleApp
MakeObjects Json

include WndPosMgr_Globals.inc
include WndPosMgr_Main.inc

.code
start proc
  SysInit
  DbgClearAll

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone
  xor eax, eax
  test $ObjTmpl(Application).dFlags, WPM_TERMINATE
  setz al
  invoke ExitProcess, eax
start endp

end


Example using german and english Windows:

{
  "Profiles":[
    {
      "Name":"Profile1",
      "Windows":[
        {
          "Caption":"Rechner",
          "Class":"ApplicationFrameWindow",          
          "Left":0,
          "Top":0,
          "Width":100,
          "Height":300,
          "Flags":0
        },
        {
          "Caption":"Unbenannt - Editor",
          "Class":"Notepad",
          "Left":100,
          "Top":100,
          "Width":500,
          "Height":500,
          "Flags":0
        }
      ]
    },
    {
      "Name":"Profile2",
      "Windows":[
        {
          "Caption":"Calculator",
          "Class":"ApplicationFrameWindow",          
          "Left":0,
          "Top":0,
          "Width":100,
          "Height":300,
          "Flags":0
        },
        {
          "Caption":"Untitled - Notepad",
          "Class":"Notepad",
          "Left":100,
          "Top":100,
          "Width":500,
          "Height":500,
          "Flags":0
        }
      ]
    }
  ]
}
