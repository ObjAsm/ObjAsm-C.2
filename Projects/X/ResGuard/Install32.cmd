REM @echo off

@echo Project: ResGuard 32 bit

copy ResGuard.inc "%OBJASM_PATH%\Code\Inc\ObjAsm\ResGuard.inc"
copy ResGuard32.lib "%OBJASM_PATH%\Code\Lib\32\ObjAsm\ResGuard32.lib"
rem copy ResGuard32.dll %windir%\SYSTEM32\ResGuard32.dll

copy ResGuard32.dll "%OBJASM_PATH%\Projects\X\ResGuard\LeakTest1\ResGuard32.dll"
