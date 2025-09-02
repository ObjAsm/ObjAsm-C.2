; ==================================================================================================
; Title:      WndPosMgr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm WndPosMgr.
; Notes:      Version C.1.0, August 2025
;               - First release.
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
  movzx eax, $ObjTmpl(Application).bTerminate
  invoke ExitProcess, eax
start endp

end


Example:
{
  "Profiles":[
    {
      "Name":"Profile1",
      "Apps":[
        {
          "Name":"Rechner",
          "X":0,
          "Y":0,
          "W":100,
          "H":300,
          "Flags":0
        },
        {
          "Name":"Unbenannt - Editor",
          "X":100,
          "Y":100,
          "W":500,
          "H":500,
          "Flags":0
        }
      ]
    },
    {
      "Name":"Profile2",
      "Apps":[
        {
          "Name":"Notepad",
          "X":0,
          "Y":0,
          "W":100,
          "H":100,
          "Flags":0
        },
        {
          "Name":"Calculator",
          "X":100,
          "Y":100,
          "W":100,
          "H":100,
          "Flags":0
        }
      ]
    }
  ]
}
