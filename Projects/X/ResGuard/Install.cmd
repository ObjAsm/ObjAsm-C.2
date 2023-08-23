REM @echo off

@echo Project: ResGuard

copy ResGuard.inc "%OBJASM_PATH%\Code\Inc\ObjAsm\ResGuard.inc"
copy ResGuard.lib "%OBJASM_PATH%\Code\Lib\32\ObjAsm\ResGuard32.lib"
rem copy ResGuard.dll %windir%\SYSTEM32\ResGuard32.dll

copy ResGuard.dll "%OBJASM_PATH%\Projects\X\ResGuard\LeakTest1\ResGuard.dll"
