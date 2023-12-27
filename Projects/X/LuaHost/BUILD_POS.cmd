REM This file is called by the build tool chain.
@echo off
copy %OBJASM_PATH%\Code\Lib\!TARGET_BITNESS!\Lua\!TARGET_MODE_STR!\*.* >> !LogFile!
