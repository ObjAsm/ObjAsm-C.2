REM @echo off

@echo Project: ResGuard 64 bit

copy ResGuard.inc "%OBJASM_PATH%\Code\Inc\ObjAsm\ResGuard.inc"
copy ResGuard64.lib "%OBJASM_PATH%\Code\Lib\64\ObjAsm\ResGuard64.lib"
rem copy ResGuard64.dll %windir%\SYSTEM32\ResGuard64.dll

copy ResGuard64.dll "%OBJASM_PATH%\Projects\X\ResGuard\LeakTest1\ResGuard64.dll"


