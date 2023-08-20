@echo off

@echo Project: ResGuard

copy ResGuard.inc %OBJASM_PATH%\Code\Inc\ObjAsm\ResGuard.inc
copy ResGuard.lib %OBJASM_PATH%\Code\Lib\32\ObjAsm\ResGuard32.lib
copy ResGuard.dll %windir%\SYSTEM32\ResGuard32.dll


