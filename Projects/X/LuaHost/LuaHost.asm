; ==================================================================================================
; Title:      LuaHost.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Lua Host Application.
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN32, ANSI_STRING;, DEBUG(WND);, ResGuard)

% include &IncPath&Windows\Shlwapi.inc
% include &IncPath&Windows\Richedit.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Lua\luaconf546.inc
% include &IncPath&Lua\lua546.inc
% include &IncPath&Lua\lualib546.inc
% include &IncPath&Lua\lauxlib546.inc

% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Lua\lua546.lib

;Load or build the following objects
MakeObjects Primer, Stream
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinControl, FlipBox, Splitter
MakeObjects LuaHost


.code
include LuaHost_Globals.inc
include LuaHost_Main.inc

start proc uses xbx
  SysInit

  ResGuard_Start

  DbgClearAll

  invoke InitCommonControls
  mov xbx, $invoke(LoadLibrary, $OfsCStr("RichEd20.dll"))

  OCall $ObjTmpl(Application)::Application.Init, NULL, 0, IDD_MAIN
  OCall $ObjTmpl(Application)::Application.Show
  OCall $ObjTmpl(Application)::Application.Done

  invoke FreeLibrary, xbx

  ResGuard_Show
  ResGuard_Stop

  SysDone
  invoke ExitProcess, 0
start endp

end
