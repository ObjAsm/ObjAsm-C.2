; ==================================================================================================
; Title:      Model.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm supporting macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================

; Notes about ObjAsm:
; ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
;  1. Naming rules
;     a. Constants, structures, unions and native types are written in capitals and words are
;        separated with an underscore, e.g. MAX_SIZE.
;     b. Variables follows the "medial capitals" style (CamelCase), e.g. dSelection.
;  2. Prefixes:
;     a. Hidden Symbols prepended with "??" are "cross macro" symbols. Do not alter them with other
;        macros.
;     b. Local macro variables are reused as much as possible to minimize symbol table growth.
;        They are prepended with "$$".
;     c. Variable types are denoted using the following prefixes:
;        - x: XWORD (X is also used as suffix for proc naming)
;        - b: BYTE or BOOL
;        - w: WORD
;        - d: DWORD
;        - q: QWORD
;        - o: OWORD
;        - sb: SBYTE
;        - sw: SWORD
;        - sd: SDWORD
;        - sq: SQWORD
;        - so: SOWORD
;        - t: TBYTE
;        - c: CHR (CHRA, CHRW, CHRU)
;        - sz: zero terminated string (ANSI or WIDE)
;        - h: HANDLE
;        - p: POINTER
;        - pp: POINTER to a POINTER
;        - pv: POINTER to a vector
;        - v: Vector, e.g. VEC3 or VEC4
;        - m: matrix, e.g. MAT33 or MAT44
;        - sz: Zero terminated string of CHR characters, usually defined as CONST
;        - r4: REAL4
;        - r8: REAL8
;        - r10: REAL10
;        - P_: ptr type, e.g. ptr RECT = P_RECT
;        - POB_: ptr Object type
;        - TPL_: Object template
;        - $: macro that returns a text or a number
;        - s: user symbols (sIID_xxx)
;        - $$: hidden symbols, but reused by macros (save space on the symbol table)
;        - ??: hidden symbols, but shared between macros

;  3. Macro parameters are usually InsName, ObjName, MtdMame, VarName, IfcName, Args, ...
;  4. Stucture alingnement are usually 1, 4, 8.
;  5. Object is a synonym for class.
;  6. The following prefixes are used:
;       TPL_ : object template from which an instance is created.
;       POB_ : object POINTER type. Used to type cast e.g. variables, paramters, etc.
;  7. Each macro, procedure or method has a standard header, that can be parsed into a help system.
;     The header should include the following items in this format (descs should start at pos. 15):
;        ; Macro:      ... /Procedure/Method
;        ; Purpose:    ...
;        ; Arguments:  Arg1: ...
;        ;             Arg2: ...
;        ; Return:     ...
;  8. ObjAsm uses a dual method table (DMT) that fuses a virtual method table (VMT) with an interface
;     method table (IMT). The layout of the VMT is designed with negative offsets from the table
;     entry point. To have a quick access to a event translation table (ETT), a POINTER is inserted
;     in between the VMT and the IMT, shifting the VMT one entry back.
;  9. The event translation table (ETT) is used to dispatch Windows messages, COM and other events.
; 10. Information about objects are hold in a metadata chained list, that starts with p1stOMD.
; 11. Each object/instance can be identifed at runtime by its ID, declared with the "Object" macro.
;     If this ID is not declared, ObjAsm doesn't emmit an error. The ID is assumed as "0" and the
;     object/instance can not be identifed at runtime anymore.
; 12. Object definition and implementation are hold together in one single file (ObjName.inc).
;     To separate them, a conditional compilation switch called IMPLEMENT is used to encapsulate
;     the implementation. This switch is handled automatically.
; 13. Object implementation can be precompiled to a library file (ObjName.lib) using an auxiliary
;     assembly file (ObjName.asm) located in most cases in the same communal directory (ObjPath).
; 14. Communal paths and other basic definitions are defined in one file called OA_Setup64.inc
; 15. Including objects are done using the MakeObjects or LoadObjects macro. The first builds
;     the object source while the second loads the precompiled library file. Descendant objects
;     must be loaded in inheritance order. Included or loaded Objects have to be included or
;     loaded again. If no path is prepended to the object name, the ObjPath communal directory
;     is assumed.
; 16. An object may have virtual methods, that are invoked using the VMT and the OCall macro.
;     Interface methods use the IMT and may use ICall or OCall for their invoketion.
; 17. Static methods use a direct call to the method implementation without any indirection.
; 18. Dynamic methods are like virtual or interface methods, but the indirection is done using
;     a method address stored in the object instance. This way, subclassing of an object instance
;     can be done.
; 19. Superclassing can be done redefining the adresses stored in the DMT. For this purpose use the
;     RedefineMethod macro.
; 20. In this implementation, the VMT & IMT are per object, not per instance. To implement instance
;     dependant methods use "Dynamic Methods".
; 21. Object errors are written in the ObjErr.inc file. User defined errors should be kept in a
;     separate file.
; 22. Object IDs are written in the ObjIDs.inc file. User defined IDs should be kept in a separate
;     file.
; 23. WIDE string support is enabled adding the WIDE_STRING keyword to the SysSetup macro at the
;     beginning of the sorece. ANSI_STRING switches the ANSI string support on.
; 24. The "CHR", "PCHR" and "PSTRING" types change their meaning according the string compilation
;     target (ANSI_STRING or WIDE_STRING).
; 25. Debugging macros are enabled when DEBUG() is added to the SysSetup macro. The destination
;     of the debug information is directed using the Debug auguments WND, CON, LOG or PRN.
; 26. If a string procedure name contain one of the following characters, it behaves as follows:
;       - A: ANSI procedure
;       - W: WIDE procedure
;       - C: character count is limited
;       - E: returns the address of the ZTC
;       - I: case insensitive
;       - L: operation starts from left
;       - R: operation starts from right

; ——————————————————————————————————————————————————————————————————————————————————————————————————

ifdef __UASM__
  ASSEMBLER CatStr <U>, %__UASM__
elseifdef __JWASM__
  ASSEMBLER CatStr <J>, %__JWASM__                      ;Legacy
elseifdef __ASMC__
  ASSEMBLER CatStr <A>, %__ASMC__
else
  ASSEMBLER CatStr <M>, @Version
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SysSetup
; Purpose:    Load and configure standard modules.
; Arguments:  Support level: OOP, WIN32/WIN64, CON32/CON64, NUI32/NUI64, LIB32/LIB64.
;             Debug Switches : SHOWINFO, TRACE, RESGUARD, STKGUARD
;             Source identification: "..." (also used as LOG file name)
;             Default string type: ANSI_STRING or WIDE_STRING
; Return:     Nothing.

DEBUG macro DbgArgs:vararg
  ifndef ISABLE_DEBUG                                   ;;Use assembler option /D<ISABLE_DEBUG>
    $$DbgArgs equ DbgArgs                               ;;   to disable application debugging
    exitm <DEBUG_TRUE>
  else
    $$DbgArgs equ <>
    exitm <DEBUG_FALSE>
  endif
endm

RESGUARD_LOADED         =         0                     ;Set these flags
STKGUARDING             =         0
TRACING                 =         0
DEBUGGING               =         0

STR_TYPE_ANSI           equ       1
STR_TYPE_WIDE           equ       2
TARGET_STR_TYPE         =         STR_TYPE_WIDE         ;Default WIDE strings
TARGET_STR_AFFIX        textequ   <W>

OOP_DISABLED            equ       1                     ;OOP support disabled.
OOP_ENABLED             equ       2                     ;OOP support enabled.
TARGET_OOP              =         OOP_DISABLED

BIN_FORMAT_EXE          equ       1
BIN_FORMAT_DLL          equ       2
BIN_FORMAT_LIB          equ       3
TARGET_BIN_FORMAT       =         BIN_FORMAT_EXE

USER_INTERFACE_NONE     equ       1                     ;No user interface
USER_INTERFACE_GUI      equ       2                     ;Graphic user interface
USER_INTERFACE_CLI      equ       3                     ;Command line interface
TARGET_USER_INTERFACE   =         USER_INTERFACE_GUI    ;Default: Window

TARGET_BITNESS          =         32                    ;Default 32-bit

PLATFORM_NONE           equ       1
PLATFORM_UEFI           equ       2
PLATFORM_WINDOWS        equ       3
PLATFORM_OTHER          equ       4                     ;E.g. Linux distros
TARGET_PLATFORM         =         PLATFORM_WINDOWS

MODE_RLS                equ       1
MODE_DBG                equ       2
TARGET_MODE             =         MODE_RLS
TARGET_MODE_STR         textequ   <R>

DEBUGGING               =         0

??ObjectContext         textequ   <>


SysSetup macro Arguments:vararg
  for Argument, <Arguments>
    ifidni <Argument>, <WIDE_STRING>                    ;;WIDE string support
      TARGET_STR_TYPE = STR_TYPE_WIDE
      TARGET_STR_AFFIX textequ <W>
      UNICODE equ 1
    elseifidni <Argument>, <ANSI_STRING>                ;;ANSI string support
      TARGET_STR_TYPE = STR_TYPE_ANSI
      TARGET_STR_AFFIX textequ <A>

    elseifidni <Argument>, <DEBUG_TRUE>
      ifndef RELEASE_OA
        DEBUGGING = 1
        TARGET_MODE = MODE_DBG
        TARGET_MODE_STR textequ <D>
      else
        DEBUGGING = 0
        TARGET_MODE = MODE_RLS
        TARGET_MODE_STR textequ <R>
      endif

    elseifidni <Argument>, <DEBUG_FALSE>
      DEBUGGING = 0
      TARGET_MODE = MODE_RLS
      TARGET_MODE_STR textequ <R>

    elseifidni <Argument>, <OOP>
      TARGET_OOP = OOP_ENABLED

    elseifidni <Argument>, <NUI32>
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <NUI64>
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 64

    elseifidni <Argument>, <WIN32>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_USER_INTERFACE = USER_INTERFACE_GUI
      TARGET_BITNESS = 32
    elseifidni <Argument>, <WIN64>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_USER_INTERFACE = USER_INTERFACE_GUI
      TARGET_BITNESS = 64

    elseifidni <Argument>, <CON32>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_USER_INTERFACE = USER_INTERFACE_CLI
      TARGET_BITNESS = 32
    elseifidni <Argument>, <CON64>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_USER_INTERFACE = USER_INTERFACE_CLI
      TARGET_BITNESS = 64

    elseifidni  <Argument>, <LIB32>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_BIN_FORMAT = BIN_FORMAT_LIB
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <LIB64>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_BIN_FORMAT = BIN_FORMAT_LIB
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 64

    elseifidni <Argument>, <DLL32>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_BIN_FORMAT = BIN_FORMAT_DLL
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni <Argument>, <DLL64>
      TARGET_PLATFORM = PLATFORM_WINDOWS
      TARGET_BIN_FORMAT = BIN_FORMAT_DLL
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 64

    elseifidni <Argument>, <UEFI32>
      TARGET_BIN_FORMAT = BIN_FORMAT_DLL
      TARGET_USER_INTERFACE = USER_INTERFACE_CLI
      TARGET_BITNESS = 32
      TARGET_PLATFORM = PLATFORM_UEFI

    elseifidni <Argument>, <UEFI64>
      TARGET_BIN_FORMAT = BIN_FORMAT_DLL
      TARGET_USER_INTERFACE = USER_INTERFACE_CLI
      TARGET_BITNESS = 64
      TARGET_PLATFORM = PLATFORM_UEFI

    else
      echo SysSetup - Invalid argument
      echo
    endif
  endm


  if TARGET_BITNESS eq 32
    % include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
  else
    % include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
  endif

  .nolist
  .nocref

  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    % include &IncPath&Windows\\Windows.inc
    % include &MacPath&System.inc
    % include &MacPath&Memory.inc
    % include &MacPath&Strings.inc
    % include &MacPath&WinHelpers.inc
    % include &IncPath&ObjAsm\\ObjMem.inc
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    % include &MacPath&UefiMac.inc
    % include &IncPath&UEFI\\UefiBase.inc
    % include &MacPath&System.inc
    % include &MacPath&Memory.inc
    % include &MacPath&Strings.inc
    % include &IncPath&ObjAsm\\ObjMem.inc
    % include &IncPath&UEFI\\UefiGUID.inc
    % include &IncPath&UEFI\\UefiUtil.inc
  endif
  % include &MacPath&ConstDiv.inc

  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    if TARGET_BIN_FORMAT ne BIN_FORMAT_LIB                ;;Only load libs when target is not a lib
      % includelib &LibPath&Windows\\GDI32.lib
      % includelib &LibPath&Windows\\Kernel32.lib
      % includelib &LibPath&Windows\\User32.lib
      % includelib &LibPath&Windows\\Advapi32.lib
    endif
  endif
  if TARGET_BIN_FORMAT ne BIN_FORMAT_LIB
    if TARGET_BITNESS eq 32
      % includelib &LibPath&ObjAsm\\ObjMem32.lib
    else
      % includelib &LibPath&ObjAsm\\ObjMem64.lib
    endif
  endif

  .list
  .cref


  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    externdef hInstance:HINSTANCE                       ;;Export hInstance symbol
    externdef hProcessHeap:HANDLE                       ;;Export hProcessHeap symbol
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    externdef hImage:EFI_HANDLE
    externdef pSystemTable:POINTER
    externdef pBootServices:P_BOOT_SERVICES
    externdef pRuntimeServices:P_RUNTIME_SERVICES
    externdef pConsoleOut:PCONOUT
    externdef pConsoleIn:PCONIN
  endif

  externdef p1stOMD:POINTER                             ;;Export p1stOMD symbol

  ;;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  if TARGET_OOP eq OOP_ENABLED
    echo OOP Support:    ENABLED
    IMPLEMENT         = TRUE                            ;;Default = implement object methods
    MAKETEMPL         = TRUE                            ;;Default = create object templates
    SHOWINHERITANCE   = TRUE                            ;;Output the object inheritance path
    CREATETYPEDEFS    = TRUE                            ;;Emits TYPEDEF object POINTER information
    % include &MacPath&Objects.inc                      ;;Here is our OOP support! => ObjAsm

    if DEBUGGING
      S_OBJID segment                                   ;;Define a new segment
        ??ObjIDTableStart equ $
      S_OBJID ends                                      ;;Switch back to previous segment
      ??ObjIDTableCount = 0

      S_OBJERR segment                                  ;;Define a new segment
        ??ObjErrTableStart equ $
      S_OBJERR ends                                     ;;Switch back to previous segment
      ??ObjErrTableCount = 0

    endif
    % include &ObjPath&ObjIDs.inc                       ;;These include files must follow the
    % include &ObjPath&ObjErrs.inc                      ;;  previous segment definitions
  else
    echo OOP Support:    DISABLED
    IMPLEMENT         = FALSE                           ;;Don't implement unless MakeObject is used
    MAKETEMPL         = FALSE                           ;;Don't create any object template
    SHOWINHERITANCE   = FALSE                           ;;Don't output the inheritance path
    CREATETYPEDEFS    = FALSE                           ;;Don't emit TYPEDEF object POINTER info
  endif

  if TARGET_PLATFORM eq PLATFORM_NONE
    echo Platform:       NONE
  elseif TARGET_PLATFORM eq PLATFORM_WINDOWS
    echo Platform:       WINDOWS
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    echo Platform:       UEFI
  elseif TARGET_PLATFORM eq PLATFORM_OTHER
    echo Platform:       OTHER
  endif

  if TARGET_USER_INTERFACE eq USER_INTERFACE_NONE
    echo User Interface: NONE
  elseif TARGET_USER_INTERFACE eq USER_INTERFACE_GUI
    echo User Interface: GRAPHIC
  elseif TARGET_USER_INTERFACE eq USER_INTERFACE_CLI
    echo User Interface: COMMAND LINE
  endif

  if TARGET_BIN_FORMAT eq BIN_FORMAT_EXE
    echo Binary Format:  EXE
  elseif TARGET_BIN_FORMAT eq BIN_FORMAT_DLL
    echo Binary Format:  DLL
  elseif TARGET_BIN_FORMAT eq BIN_FORMAT_LIB
    echo Binary Format:  LIB
    IMPLEMENT         = FALSE                           ;;Don't implement unless MakeObject is used
    MAKETEMPL         = FALSE                           ;;Don't create any object template
    SHOWINHERITANCE   = FALSE                           ;;Don't output the inheritance path
  endif

  if TARGET_BITNESS eq 32
    echo Bitness:        32
  else
    echo Bitness:        64
  endif

  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    echo String Type:    ANSI
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    echo String Type:    WIDE (UNICODE)
  endif

  ;;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  if DEBUGGING
    if TARGET_BITNESS eq 64
      ??StackBase equ <rbp>                             ;;Set default
      option stackbase:??StackBase                      ;;use rbp as stackbase for easier debugging
    endif

    % include &MacPath&DebugShare.inc

    DBG_SAVE_CPU_CONTEXT = TRUE                         ;;Debug macros preserve the CPU context
    DBG_SAVE_XMM_CONTEXT = TRUE                         ;;Debug macros preserve the XMM context
    DBG_SAVE_FPU_CONTEXT = TRUE                         ;;Debug macros preserve the FPU context

    DBG_DEVICE textequ <WIN_WND>                        ;;Default debug device
    DBG_TRACE = FALSE
    DBG_INFO  = FALSE
    DBG_SHOW_TIME_STAMP = FALSE
    $$sz1 textequ <>

    %for $$Arg, <$$DbgArgs>
      ifidni <$$Arg>, <RESGUARD>
        % include &IncPath&ObjAsm\ResGuard.inc
        if TARGET_BITNESS eq 32
          % includelib &LibPath&ObjAsm\ResGuard32.lib
        else
          % includelib &LibPath&ObjAsm\ResGuard64.lib
        endif
        RESGUARD_LOADED = TRUE
      elseifidni <$$Arg>, <STKGUARD>
        STKGUARDING = TRUE
      elseifidni <$$Arg>, <WND>
        DBG_DEVICE textequ <WND>
      elseifidni <$$Arg>, <CON>
        DBG_DEVICE textequ <CON>
      elseifidni <$$Arg>, <LOG>
        DBG_DEVICE textequ <LOG>
      elseifidni <$$Arg>, <INFO>
        DBG_INFO = TRUE
      elseifidni <$$Arg>, <TRACE>
        DBG_TRACE = TRUE
      elseifidni <$$Arg>, <TIME>
        DBG_SHOW_TIME_STAMP = TRUE
      else
        if @InStr(1, $$Arg, <!">) eq 1
          $$sz1 textequ <$$Arg>
        endif
      endif
    endm

    externdef dDbgDev:DWORD                           ;;Export dDbgDev symbol
    externdef dDbgOpt:DWORD                           ;;Export dDbgOpt symbol
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      externdef DbgCritSect:CRITICAL_SECTION          ;;Export DbgCritSect symbol
    endif

    if TARGET_BIN_FORMAT eq BIN_FORMAT_LIB
      ;;Debug support symbols
      ??ObjIDTableCount = 0
      ??ObjErrTableCount = 0
      externdef szDbgSrc:CHRW
      externdef szDbgInvalid:CHRA
      externdef szDbgErr:CHRW
      externdef szDbgObjErr:CHRW
      externdef szDbgFPU1:CHRA
      externdef szDbgFPU2:CHRA
      externdef szDbgFPU3:CHRA
      externdef szDbgFPU4:CHRA
      externdef szDbgFPU5:CHRA
      externdef szDbgFPU6:CHRA
      externdef szDbgFPU7:CHRA
      externdef szDbgMemFmt:CHRA
      externdef szDbgElipsis:CHRA
      externdef szDbgInvalid:CHRA
      externdef szDbgPoint2:CHRA
      externdef szDbgComma:CHRA
      externdef szDbgCtrCls:CHRW
      externdef hDbgDev:HANDLE
      externdef pObjIDTableStart:POINTER
      externdef dObjIDTableCount:DWORD
      externdef pObjErrTableStart:POINTER
      externdef dObjErrTableCount:DWORD

    else

      ifb $$sz1
        CStrW szDbgSrc, @CatStr(<!">, %@FileName, <!">) ;;Use the Project File Name
      else
        CStrW szDbgSrc, $$sz1                           ;;Use the specified name
      endif

      .data
      align ALIGN_DATA
      if TARGET_PLATFORM eq PLATFORM_WINDOWS
        %ifidn <DBG_DEVICE>, <WND>
          dDbgDev   DWORD   DBG_DEV_WIN_DC
        %elseifidn <DBG_DEVICE>, <CON>
          dDbgDev   DWORD   DBG_DEV_WIN_CON
        %elseifidn <DBG_DEVICE>, <LOG>
          dDbgDev   DWORD   DBG_DEV_WIN_LOG
        endif
      elseif TARGET_PLATFORM eq PLATFORM_UEFI
        dDbgDev   DWORD   DBG_DEV_UEFI_CON
      endif

      if DBG_INFO eq TRUE
        dDbgOpt   DWORD   DBG_OPT_SHOWINFO
      else
        dDbgOpt   DWORD   0
      endif

      if TARGET_PLATFORM eq PLATFORM_WINDOWS
        DbgCritSect  CRITICAL_SECTION  {}
      endif

      if DBG_TRACE
        TRACING = TRUE

        S_PROF segment
          ??pDbgTraceInstance  POINTER  NULL
        S_PROF ends
      else
        TRACING = FALSE
      endif

      if STKGUARDING ne FALSE
        if TARGET_BITNESS eq 32
          xStkGrdCookie  DWORD  0                       ;;Create Cookie variable
        else
          xStkGrdCookie  QWORD  0                       ;;Create Cookie variable
        endif
      endif

    endif

    if TARGET_BITNESS eq 32
      %echo Mode:           DEBUG
    else
      %echo Mode:           DEBUG => DBG_DEVICE, using &??StackBase as stackframe pointer
    endif

    if STKGUARDING ne FALSE
      echo STACKGUARD:     ACTIVE
    endif

    if RESGUARD_LOADED ne FALSE
      echo RESGUARD:       ACTIVE
    endif

  else
    if TARGET_BITNESS eq 32
      %echo Mode:           RELEASE
    else
      %echo Mode:           RELEASE => using &??StackBase as stackframe pointer
    endif
  endif
  % include &MacPath&Debug.inc

  TARGET_SUFFIX CatStr $ToStr(%TARGET_BITNESS), TARGET_STR_AFFIX
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SysInit
; Purpose:    Initialize the model and internal variables.
; Arguments:  Windows:
;               Arg1: Instance HANDLE. If not specified, the Module HANDLE is loaded into hInstance.
;               Arg2: unused.
;             UEFI:
;               Arg1: Image HANDLE.
;               Arg2: -> SystemTable.

SysInit macro Arg1, Arg2
.data
  align ALIGN_DATA
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    hInstance         HINSTANCE   0                     ;;Module instance
    hProcessHeap      HANDLE      0                     ;;Process Heap HANDLE
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    hImage            EFI_HANDLE  0
    pSystemTable      POINTER     NULL
    pBootServices     P_BOOT_SERVICES     NULL
    pRuntimeServices  P_RUNTIME_SERVICES  NULL
    pConsoleOut       PCONOUT     NULL
    pConsoleIn        PCONIN      NULL
  endif

  if TARGET_OOP eq OOP_ENABLED
    p1stOMD     POINTER     ??1stOMD                    ;;-> 1st item in object metadata chain
  endif

.code
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    ifnb <Arg1>                                         ;;Used for DLLs
      m2m hInstance, Arg1, xax
    else
      mov hInstance, $invoke(GetModuleHandle, NULL)     ;;Retrieves module instance HANDLE
    endif

    mov hProcessHeap, $invoke(GetProcessHeap)           ;;Get and save the process heap HANDLE

    if DEBUGGING
      invoke InitializeCriticalSection, addr DbgCritSect
      if TARGET_OOP eq OOP_ENABLED
        m2m pObjErrTableStart, ??ObjErrTableStart, xax
        mov dObjErrTableCount, ??ObjErrTableCount
        m2m pObjIDTableStart, ??ObjIDTableStart, xax
        mov dObjIDTableCount, ??ObjIDTableCount
      endif

      ifidn DBG_DEVICE, <CON>
        mov DbgColorForeground, DBG_COLOR_FOREGROUND_CON
        mov DbgColorBackground, DBG_COLOR_BACKGROUND_CON
        mov DbgColorComment, DBG_COLOR_COMMENT_CON
        mov DbgColorWarning, DBG_COLOR_WARNING_CON
        mov DbgColorError, DBG_COLOR_ERROR_CON
        mov DbgColorString, DBG_COLOR_STRING_CON
        mov DbgColorMessage, DBG_COLOR_MESSAGE_CON
        mov DbgColorObject, DBG_COLOR_OBJECT_CON
        mov DbgColorInterface, DBG_COLOR_INTERFACE_CON
        mov DbgColorVMT, DBG_COLOR_VMT_CON
        mov DbgColorFPU, DBG_COLOR_FPU_CON
        mov DbgColorMemory, DBG_COLOR_MEMORY_CON
        mov DbgColorDefaultPre, DBG_COLOR_DEFAULT_PRE_CON
        mov DbgColorDefaultVar, DBG_COLOR_DEFAULT_VAR_CON
        mov DbgColorLine, DBG_COLOR_LINE_CON
        mov DbgColorRed, DBG_COLOR_RED_CON
        mov DbgColorGreen, DBG_COLOR_GREEN_CON
        mov DbgColorBlue, DBG_COLOR_BLUE_CON
      elseifidn DBG_DEVICE, <LOG>
        mov DbgColorForeground, DBG_COLOR_FOREGROUND_WND_LIGHT
        mov DbgColorBackground, DBG_COLOR_BACKGROUND_WND_LIGHT
        mov DbgColorComment, DBG_COLOR_COMMENT_WND_LIGHT
        mov DbgColorWarning, DBG_COLOR_WARNING_WND_LIGHT
        mov DbgColorError, DBG_COLOR_ERROR_WND_LIGHT
        mov DbgColorString, DBG_COLOR_STRING_WND_LIGHT
        mov DbgColorMessage, DBG_COLOR_MESSAGE_WND_LIGHT
        mov DbgColorObject, DBG_COLOR_OBJECT_WND_LIGHT
        mov DbgColorInterface, DBG_COLOR_INTERFACE_WND_LIGHT
        mov DbgColorVMT, DBG_COLOR_VMT_WND_LIGHT
        mov DbgColorFPU, DBG_COLOR_FPU_WND_LIGHT
        mov DbgColorMemory, DBG_COLOR_MEMORY_WND_LIGHT
        mov DbgColorDefaultPre, DBG_COLOR_DEFAULT_PRE_WND_LIGHT
        mov DbgColorDefaultVar, DBG_COLOR_DEFAULT_VAR_WND_LIGHT
        mov DbgColorLine, DBG_COLOR_LINE_WND_LIGHT
        mov DbgColorRed, DBG_COLOR_RED_WND_LIGHT
        mov DbgColorGreen, DBG_COLOR_GREEN_WND_LIGHT
        mov DbgColorBlue, DBG_COLOR_BLUE_WND_LIGHT
      else
        mov DbgHighContrast.cbSize, sizeof(HIGHCONTRAST)
        mov DbgHighContrast.dwFlags, 0                  ;;Just in case the API fails
        invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, 0, addr DbgHighContrast, FALSE
        .ifBitSet DbgHighContrast.dwFlags, HCF_HIGHCONTRASTON
          mov DbgColorForeground, DBG_COLOR_FOREGROUND_HC
          mov DbgColorBackground, DBG_COLOR_BACKGROUND_HC
          mov DbgColorComment, DBG_COLOR_COMMENT_HC
          mov DbgColorWarning, DBG_COLOR_WARNING_HC
          mov DbgColorError, DBG_COLOR_ERROR_HC
          mov DbgColorString, DBG_COLOR_STRING_HC
          mov DbgColorMessage, DBG_COLOR_MESSAGE_HC
          mov DbgColorObject, DBG_COLOR_OBJECT_HC
          mov DbgColorInterface, DBG_COLOR_INTERFACE_HC
          mov DbgColorVMT, DBG_COLOR_VMT_HC
          mov DbgColorFPU, DBG_COLOR_FPU_HC
          mov DbgColorMemory, DBG_COLOR_MEMORY_HC
          mov DbgColorDefaultPre, DBG_COLOR_DEFAULT_PRE_HC
          mov DbgColorDefaultVar, DBG_COLOR_DEFAULT_VAR_HC
          mov DbgColorLine, DBG_COLOR_LINE_HC
          mov DbgColorRed, DBG_COLOR_RED_HC
          mov DbgColorGreen, DBG_COLOR_GREEN_HC
          mov DbgColorBlue, DBG_COLOR_BLUE_HC
        .else
          invoke AppsUseLightTheme
          .if eax != FALSE
            mov DbgColorForeground, DBG_COLOR_FOREGROUND_WND_LIGHT
            mov DbgColorBackground, DBG_COLOR_BACKGROUND_WND_LIGHT
            mov DbgColorComment, DBG_COLOR_COMMENT_WND_LIGHT
            mov DbgColorWarning, DBG_COLOR_WARNING_WND_LIGHT
            mov DbgColorError, DBG_COLOR_ERROR_WND_LIGHT
            mov DbgColorString, DBG_COLOR_STRING_WND_LIGHT
            mov DbgColorMessage, DBG_COLOR_MESSAGE_WND_LIGHT
            mov DbgColorObject, DBG_COLOR_OBJECT_WND_LIGHT
            mov DbgColorInterface, DBG_COLOR_INTERFACE_WND_LIGHT
            mov DbgColorVMT, DBG_COLOR_VMT_WND_LIGHT
            mov DbgColorFPU, DBG_COLOR_FPU_WND_LIGHT
            mov DbgColorMemory, DBG_COLOR_MEMORY_WND_LIGHT
            mov DbgColorDefaultPre, DBG_COLOR_DEFAULT_PRE_WND_LIGHT
            mov DbgColorDefaultVar, DBG_COLOR_DEFAULT_VAR_WND_LIGHT
            mov DbgColorLine, DBG_COLOR_LINE_WND_LIGHT
            mov DbgColorRed, DBG_COLOR_RED_WND_LIGHT
            mov DbgColorGreen, DBG_COLOR_GREEN_WND_LIGHT
            mov DbgColorBlue, DBG_COLOR_BLUE_WND_LIGHT
          .else
            mov DbgColorForeground, DBG_COLOR_FOREGROUND_WND_DARK
            mov DbgColorBackground, DBG_COLOR_BACKGROUND_WND_DARK
            mov DbgColorComment, DBG_COLOR_COMMENT_WND_DARK
            mov DbgColorWarning, DBG_COLOR_WARNING_WND_DARK
            mov DbgColorError, DBG_COLOR_ERROR_WND_DARK
            mov DbgColorString, DBG_COLOR_STRING_WND_DARK
            mov DbgColorMessage, DBG_COLOR_MESSAGE_WND_DARK
            mov DbgColorObject, DBG_COLOR_OBJECT_WND_DARK
            mov DbgColorInterface, DBG_COLOR_INTERFACE_WND_DARK
            mov DbgColorVMT, DBG_COLOR_VMT_WND_DARK
            mov DbgColorFPU, DBG_COLOR_FPU_WND_DARK
            mov DbgColorMemory, DBG_COLOR_MEMORY_WND_DARK
            mov DbgColorDefaultPre, DBG_COLOR_DEFAULT_PRE_WND_DARK
            mov DbgColorDefaultVar, DBG_COLOR_DEFAULT_VAR_WND_DARK
            mov DbgColorLine, DBG_COLOR_LINE_WND_DARK
            mov DbgColorRed, DBG_COLOR_RED_WND_DARK
            mov DbgColorGreen, DBG_COLOR_GREEN_WND_DARK
            mov DbgColorBlue, DBG_COLOR_BLUE_WND_DARK
          .endif
        .endif
      endif
    endif

    if STKGUARDING ne FALSE
      rdtsc                                             ;;Generate a run-time random QWORD cookie
      xor xax, xdx
      mov xStkGrdCookie, xax
    endif

  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    ifnb <Arg1>
      m2m hImage, Arg1, xcx
    endif
    ifnb <Arg2>
      mrm pSystemTable, Arg2, xdx
      m2m pRuntimeServices, [xdx].EFI_SYSTEM_TABLE.RuntimeServices, xax
      m2m pBootServices, [xdx].EFI_SYSTEM_TABLE.BootServices, xcx
      m2m pConsoleIn, [xdx].EFI_SYSTEM_TABLE.ConIn, xax
      m2m pConsoleOut, [xdx].EFI_SYSTEM_TABLE.ConOut, xcx
    endif

    if DEBUGGING
      m2m pObjErrTableStart, ??ObjErrTableStart, xax
      mov dObjErrTableCount, ??ObjErrTableCount
      m2m pObjIDTableStart, ??ObjIDTableStart, xax
      mov dObjIDTableCount, ??ObjIDTableCount
    endif
  endif

  if TARGET_OOP eq OOP_ENABLED
    ObjectsInit
  endif
  
  if RESGUARD_LOADED ne FALSE
    if TARGET_BITNESS eq 32
      invoke ResGuardInit, ebp
    else
      invoke ResGuardInit, rsp
    endif
  endif

endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SysDone
; Purpose:    Finalize the model.
; Arguments:  None.

SysDone macro
  if TARGET_OOP eq OOP_ENABLED
    ObjectsDone
  endif

  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    if DEBUGGING
      invoke DeleteCriticalSection, addr DbgCritSect
    endif
  endif
endm
