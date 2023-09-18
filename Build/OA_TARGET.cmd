REM Set targets

REM TARGET_PLATFORM: NONE, WINDOWS, UEFI, OTHER
REM TARGET_USER_INTERFACE: NONE, GUI, CLI
REM TARGET_BITNESS: 32, 64
REM TARGET_BIN_FORMAT: EXE, DLL, LIB
REM TARGET_STRING_TYPE: ANSI, WIDE
REM TARGET_SUPPORT_OOP: ENABLED, DISABLED
REM TARGET_MODE: RLS, DBG
REM TARGET_MODE_STR: RELEASE, DEBUG
REM TARGET_SUFFIX_STR: , 32, 64

set TARGET_SUPPORT_OOP=DISABLED
set TARGET_MODE=RLS
set TARGET_MODE_STR=RELEASE
set TARGET_SUFFIX_STR=

REM Read main project file and get build targets
for /f "tokens=1,* eol=;" %%X in (!ProjectName!.asm) do (
  if %%X==SysSetup (
    for /f "tokens=1 delims=;" %%Z in ("%%Y") do (
      for %%A in (%%Z) do (
        if %%A == OOP (
          set TARGET_SUPPORT_OOP=ENABLED
        ) else if %%A == WIN64 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=GUI
          set TARGET_BITNESS=64
          set TARGET_BIN_FORMAT=EXE
        ) else if %%A == WIN32 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=GUI
          set TARGET_BITNESS=32
          set TARGET_BIN_FORMAT=EXE
        ) else if %%A == NUI64 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=NONE
          set TARGET_BITNESS=64
          set TARGET_BIN_FORMAT=EXE
        ) else if %%A == NUI32 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=NONE
          set TARGET_BITNESS=32
          set TARGET_BIN_FORMAT=EXE
        ) else if %%A == LIB64 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=GUI
          set TARGET_BITNESS=64
          set TARGET_BIN_FORMAT=LIB
        ) else if %%A == LIB32 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=GUI
          set TARGET_BITNESS=32
          set TARGET_BIN_FORMAT=LIB
        ) else if %%A == DLL64 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=GUI
          set TARGET_BITNESS=64
          set TARGET_BIN_FORMAT=DLL
        ) else if %%A == DLL32 (
          set TARGET_PLATFORM=WINDOWS
          set TARGET_USER_INTERFACE=GUI
          set TARGET_BITNESS=32
          set TARGET_BIN_FORMAT=DLL
        ) else if %%A == UEFI64 (
          set TARGET_PLATFORM=UEFI
          set TARGET_USER_INTERFACE=CLI
          set TARGET_BITNESS=64
          set TARGET_BIN_FORMAT=DLL
        ) else if %%A == UEFI32 (
          set TARGET_PLATFORM=UEFI
          set TARGET_USER_INTERFACE=CLI
          set TARGET_BITNESS=32
          set TARGET_BIN_FORMAT=DLL
        ) else if %%A == ANSI_STRING (
          set TARGET_STRING_TYPE=ANSI
        ) else if %%A == WIDE_STRING (
          set TARGET_STRING_TYPE=WIDE
        ) else if %%A == SUFFIX (
          set TARGET_SUFFIX_STR=!TARGET_BITNESS!
        ) else (
          for /f "tokens=1-9 delims=(,)" %%M in ("%%A") do (
            if %%M == DEBUG (
              set TARGET_MODE=DBG
              set TARGET_MODE_STR=DEBUG
            )
          )
        )
      )
    ) 
  ) 
)