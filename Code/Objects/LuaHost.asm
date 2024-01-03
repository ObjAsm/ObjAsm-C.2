; ==================================================================================================
; Title:      LuaHost.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for LuaHost object.
; Notes:      Version C.1.0, November 2023
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &IncPath&Lua\luaconf546.inc
% include &IncPath&Lua\lua546.inc
% include &IncPath&Lua\lualib546.inc
% include &IncPath&Lua\lauxlib546.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer

;Add here the file that defines the object(s) to be included in the library
MakeObjects LuaHost

end
