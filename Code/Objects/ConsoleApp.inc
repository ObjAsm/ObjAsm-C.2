; ==================================================================================================
; Title:      ConsoleApp.inc
; Author:     G. Friedrich
; Version:    C.1.3
; Purpose:    ObjAsm support of ConsoleApp objects.
; Link:       https://learn.microsoft.com/en-us/windows/console/creating-a-pseudoconsole-session
; Notes:      Version C.1.0, April 2024
;               - Initial release.
;             Version C.1.1, June 2025
;               - PrintLn bug corrected by HSE.
;             Version C.1.2, September 2025
;               - Added some functions based on fearless console x64 and some minor changes.
;             Version C.1.3, May 2026
;               - HideCursor/ShowCursor: cci.dwSize set to 25.
;               - GetInputChar: loop exit condition now tests bKeyDown as a separate field.
;               - Init: AttachConsole/AllocConsole removed.
;               - Init: hConsole opened via CONOUT$ for direct console access independent of
;                 stdout redirection. Done: hConsole closed.
;               - Write/WriteLn added and all other methods that must always reach the physical
;                 console (ClearScreen, SetCursorPos, etc.) now use hConsole instead of hOutput.
;                 hOutput continues to be used only by Print/PrintLn so that redirected output
;                 is forwarded correctly.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     ConsoleApp
; Purpose:    ConsoleApp is the base object for all console descendant application objects.

Object ConsoleApp, ConsoleAppID, Streamable
  VirtualMethod     ClearScreen
  RedefineMethod    Done
  VirtualMethod     GetCaption
  VirtualMethod     GetInputChar
  VirtualMethod     GetInputCharUC
  VirtualMethod     GetCursorPos
  VirtualMethod     GetOriginalCaption
  VirtualMethod     HideCursor
  RedefineMethod    Init,             POINTER
  VirtualMethod     Print,            PSTRING
  VirtualMethod     PrintLn,          PSTRING
  VirtualAbstract   Run
  VirtualMethod     SetCaption,       PSTRING
  VirtualMethod     SetColor,         WORD
  VirtualMethod     SetCursorPos,     DWORD, DWORD
  VirtualMethod     SetIcon,          HICON
  VirtualMethod     SetProgressBar,   DWORD, DWORD, DWORD, DWORD
  VirtualMethod     ShowCursor
  VirtualMethod     SpinnerProc
  VirtualMethod     StartSpinner
  VirtualMethod     StopSpinner
  VirtualMethod     Write,            PSTRING
  VirtualMethod     WriteLn,          PSTRING

  DefineVariable    dFlags,           DWORD,    0
  DefineVariable    hError,           HANDLE,   0
  DefineVariable    hInput,           HANDLE,   0
  DefineVariable    hOutput,          HANDLE,   0       ;Follows redirection; used by Print(Ln)
  DefineVariable    hConsole,         HANDLE,   0       ;Physical console; used by Write(Ln) etc.
  DefineVariable    hTimerQueue,      HANDLE,   0
  DefineVariable    pSetConsoleIcon,  POINTER,  NULL    ;SetConsoleIcon API proc
  DefineVariable    hSpinnerTimer,    HANDLE,   0
  DefineVariable    dSpinnerStep,     DWORD,    0       ;0..3
  DefineVariable    dSpinnerWaitTime, DWORD,    150     ;ms
  DefineVariable    SpinnerPosition,  POINT,    {0, 0}
  DefineVariable    cSpinnerPosChar,  CHR,      ' '
ObjectEnd


CAF_REDIRECTED      equ   BIT00    ; stdout is redirected
CAF_INTERACTIVE     equ   BIT01    ; stdin is a real console handle
CAF_OWNCONSOLE      equ   BIT02    ; Process owns the console; window closes on exit
CAF_HOST_CMD        equ   BIT03    ; Parent shell is cmd.exe
CAF_HOST_PS         equ   BIT04    ; Parent shell is powershell.exe or pwsh.exe
CAF_HOST_WT         equ   BIT05    ; Wrapped in Windows Terminal (WT_SESSION set)
CAF_HOST_CONEMU     equ   BIT06    ; Wrapped in ConEmu (ConEmuPID set)
CAF_HOST_EXPLORER   equ   BIT07    ; Parent process is explorer.exe


;Additional color definitions
FOREGROUND_WHITE            equ (FOREGROUND_RED or FOREGROUND_BLUE or FOREGROUND_GREEN)
FOREGROUND_YELLOW           equ (FOREGROUND_RED or FOREGROUND_GREEN)
FOREGROUND_CYAN             equ (FOREGROUND_BLUE or FOREGROUND_GREEN)
FOREGROUND_MAGENTA          equ (FOREGROUND_RED or FOREGROUND_BLUE)
FOREGROUND_BLACK            equ 0

FOREGROUND_INTENSE_RED      equ (FOREGROUND_RED or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_GREEN    equ (FOREGROUND_GREEN or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_BLUE     equ (FOREGROUND_BLUE or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_WHITE    equ (FOREGROUND_WHITE or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_YELLOW   equ (FOREGROUND_YELLOW or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_CYAN     equ (FOREGROUND_CYAN or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_MAGENTA  equ (FOREGROUND_MAGENTA or FOREGROUND_INTENSITY)

BACKGROUND_WHITE            equ (BACKGROUND_RED or BACKGROUND_BLUE or BACKGROUND_GREEN)
BACKGROUND_YELLOW           equ (BACKGROUND_RED or BACKGROUND_GREEN)
BACKGROUND_CYAN             equ (BACKGROUND_BLUE or BACKGROUND_GREEN)
BACKGROUND_MAGENTA          equ (BACKGROUND_RED or BACKGROUND_BLUE)
BACKGROUND_BLACK            equ 0

BACKGROUND_INTENSE_RED      equ (BACKGROUND_RED or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_GREEN    equ (BACKGROUND_GREEN or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_BLUE     equ (BACKGROUND_BLUE or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_WHITE    equ (BACKGROUND_WHITE or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_YELLOW   equ (BACKGROUND_YELLOW or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_CYAN     equ (BACKGROUND_CYAN or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_MAGENTA  equ (BACKGROUND_MAGENTA or BACKGROUND_INTENSITY)

; ==================================================================================================


if IMPLEMENT

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  PROCESSENTRY32_ textequ <PROCESSENTRY32>
  Process32First_ textequ <Process32First>
  Process32Next_  textequ <Process32Next>
else
  PROCESSENTRY32_ textequ <PROCESSENTRY32W>
  Process32First_ textequ <Process32FirstW>
  Process32Next_  textequ <Process32NextW>
endif

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.ClearScreen
; Purpose:    Remove the screen content.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.ClearScreen, uses xsi
  local dCharCellCount:DWORD, dCharsWritten:DWORD
  local coord:COORD, csbi:CONSOLE_SCREEN_BUFFER_INFO

  SetObject xsi
  invoke GetConsoleScreenBufferInfo, [xsi].hConsole, addr csbi
  .if eax != 0
    movzx eax, csbi.dwSize.X
    movzx ecx, csbi.dwSize.Y
    mul ecx
    mov dCharCellCount, eax

    mov coord.X, 0
    mov coord.Y, 0

    invoke FillConsoleOutputCharacter, [xsi].hConsole, ' ', dCharCellCount, \
                                       addr coord, addr dCharsWritten
    invoke FillConsoleOutputAttribute, [xsi].hConsole, csbi.wAttributes, dCharCellCount, \
                                       addr coord, addr dCharsWritten
    invoke SetConsoleCursorPosition, [xsi].hConsole, addr coord
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Done
; Purpose:    Finalize the ConsoleApp object.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.Done, uses xsi
  SetObject xsi

  ;Delete the timer queue and wait for all callbacks to finish before closing handles.
  ;INVALID_HANDLE_VALUE makes DeleteTimerQueueEx block until pending callbacks return.
  invoke DeleteTimerQueueEx, [xsi].hTimerQueue, INVALID_HANDLE_VALUE

  ;Close hConsole only if it was separately opened (stdout was redirected).
  ;When not redirected hConsole == hOutput and must not be closed twice.
  .ifBitSet [xsi].dFlags, CAF_REDIRECTED
    invoke CloseHandle, [xsi].hConsole
  .endif
  invoke FreeConsole

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.GetCaption
; Purpose:    Return the current console caption.
; Arguments:  None.
; Return:     Nothing.
; Note:       Returned STRING must be freed using StrDispose.

Method ConsoleApp.GetCaption
  local cBuffer[4096]:CHR

  invoke GetConsoleTitle, addr cBuffer, lengthof(cBuffer)
  invoke StrNew, addr cBuffer
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.GetCursorPos
; Purpose:    Return the current cursor position.
; Arguments:  None.
; Return:     eax = x position or -1 if failed.
;             ecx = y position or -1 if failed.

Method ConsoleApp.GetCursorPos
  local csbi:CONSOLE_SCREEN_BUFFER_INFO

  SetObject xcx
  invoke GetConsoleScreenBufferInfo, [xcx].hConsole, addr csbi
  .if eax != 0
    movzx eax, csbi.dwCursorPosition.X
    movzx ecx, csbi.dwCursorPosition.Y
  .else
    mov eax, -1
    mov ecx, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.GetInputChar
; Purpose:    This function returns when any console key is pressed (bKeyDown = 1).
;             A possible drawback is that all input event records are removed from
;             the console input queue until a key is pressed. In many cases, this is
;             not an issue. The virtual key code, virtual scan code, TCHAR character,
;             and control key state values are returned in registers.
; Arguments:  None.
; Return:     al/ax = Character.
;             ecx = control key state flags
;                 Bit   Name                Meaning
;                  0    RIGHT_ALT_PRESSED   Right ALT key is pressed
;                  1    LEFT_ALT_PRESSED    Left ALT key is pressed
;                  2    RIGHT_CTRL_PRESSED  Right CTRL key is pressed
;                  3    LEFT_CTRL_PRESSED   Left CTRL key is pressed
;                  4    SHIFT_PRESSED       SHIFT key is pressed
;                  5    NUMLOCK_ON          NUM LOCK light is on
;                  6    SCROLLLOCK_ON       SCROLL LOCK light is on
;                  7    CAPSLOCK_ON         CAPS LOCK light is on
;                  8    ENHANCED_KEY        Key is enhanced
;              edx = low word (dx) = virtual key code
;                    high word = virtual scan code

Method ConsoleApp.GetInputChar, uses xsi
  local InpRec:INPUT_RECORD, dRecCnt:DWORD

  SetObject xsi
  .repeat
    invoke ReadConsoleInput, [xsi].hInput, addr InpRec, 1, addr dRecCnt
    movzx edx, WORD ptr InpRec.EventType
  .until (edx == KEY_EVENT) && (InpRec.Event_.KeyEvent.bKeyDown != 0)
  movzx eax, CHRW ptr InpRec.Event_.KeyEvent.uChar.UnicodeChar
  mov ecx, InpRec.Event_.KeyEvent.dwControlKeyState
  mov edx, DWORD ptr InpRec.Event_.KeyEvent.wVirtualKeyCode
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.GetInputCharUC
; Purpose:    Get a character from the console input and convert it to uppercase.
; Arguments:  None.
; Return:     al/ax = Uppercase character.

Method ConsoleApp.GetInputCharUC
  SetObject xcx
  OCall xcx.GetInputChar
  invoke CharUpper, xax                                 ; Handles full Unicode uppercase mapping
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.GetOriginalCaption
; Purpose:    Return the original console caption.
; Arguments:  None.
; Return:     Nothing.
; Note:       Returned STRING must be freed using StrDispose.

Method ConsoleApp.GetOriginalCaption
  local cBuffer[4096]:CHR

  invoke GetConsoleOriginalTitle, addr cBuffer, lengthof(cBuffer)
  invoke StrNew, addr cBuffer
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.HideCursor
; Purpose:    Hide the console cursor.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.HideCursor
  local cci:CONSOLE_CURSOR_INFO

  SetObject xax
  mov cci.dwSize, 25                                    ;Cursor fill percentage (1-100)
  mov cci.bVisible, FALSE
  lea xdx, cci
  invoke SetConsoleCursorInfo, [xax].hConsole, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Init
; Purpose:    Initialize the ConsoleApp object.
; Arguments:  Arg1: -> Owner.
; Return:     Nothing.
; Note:       For a console subsystem executable, Windows has already set up valid standard
;             handles before entry. AttachConsole/AllocConsole are therefore not called.
;             hOutput stores the inherited stdout handle and follows any redirection.
;             When stdout is a real console handle (GetConsoleMode succeeds), hConsole
;             reuses hOutput so that WriteConsole operates on the same handle and the
;             console Unicode mode is preserved, fixing wide-string output.
;             When stdout is redirected (GetConsoleMode fails), hConsole is opened
;             directly on CONOUT$ so Write/WriteLn and all console control methods
;             always reach the physical console regardless of redirection.

Method ConsoleApp.Init, uses xsi, pOwner:POINTER
  local pe32:PROCESSENTRY32_
  local dMode:DWORD, cBuffer[MAX_PATH]:CHR
  local hSnapshot:HANDLE, dParentPID:DWORD, dCurrentPID:DWORD
  local dPIDs[16]:DWORD                                 ; Buffer for attached process IDs (DWORDs)

  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].dFlags, 0

  mov [xsi].hError,  $invoke(GetStdHandle, STD_ERROR_HANDLE)
  mov [xsi].hInput,  $invoke(GetStdHandle, STD_INPUT_HANDLE)
  mov [xsi].hOutput, $invoke(GetStdHandle, STD_OUTPUT_HANDLE)

  ; --- Detect stdout redirection ---
  invoke GetConsoleMode, [xsi].hOutput, addr dMode
  .if eax != 0
    mov xax, [xsi].hOutput
  .else
    BitSet [xsi].dFlags, CAF_REDIRECTED
    invoke CreateFile, $OfsCStr("CONOUT$"), \
                       GENERIC_READ or GENERIC_WRITE, FILE_SHARE_WRITE, \
                       NULL, OPEN_EXISTING, 0, 0
    .if xax == INVALID_HANDLE_VALUE
      mov xax, [xsi].hOutput
    .endif
  .endif
  mov [xsi].hConsole, xax

  ; --- Detect interactive session ---
  invoke GetConsoleMode, [xsi].hInput, addr dMode
  .if eax != 0
    BitSet [xsi].dFlags, CAF_INTERACTIVE
  .endif

  mov [xsi].hTimerQueue, $invoke(CreateTimerQueue)

  ; --- Host detection ---

  ; 1. Windows Terminal: check WT_SESSION env var (cheapest)
  invoke GetEnvironmentVariable, $OfsCStr("WT_SESSION"), addr cBuffer, sizeof cBuffer
  .if eax != 0
    BitSet [xsi].dFlags, CAF_HOST_WT
  .endif

  ; 2. ConEmu: check ConEmuPID env var
  invoke GetEnvironmentVariable, $OfsCStr("ConEmuPID"), addr cBuffer, sizeof cBuffer
  .if eax != 0
    BitSet [xsi].dFlags, CAF_HOST_CONEMU
  .endif

  ; 3. Walk the process list to find our parent and check its name
  invoke GetCurrentProcessId
  mov dCurrentPID, eax
  mov dParentPID, 0

  invoke CreateToolhelp32Snapshot, TH32CS_SNAPPROCESS, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hSnapshot, xax
    mov pe32.dwSize, sizeof PROCESSENTRY32W

    invoke Process32First, hSnapshot, addr pe32
    .while eax != 0
      mov eax, pe32.th32ProcessID
      .if eax == dCurrentPID
        mov eax, pe32.th32ParentProcessID
        mov dParentPID, eax
        .break
      .endif
      invoke Process32Next_, hSnapshot, addr pe32
    .endw

    .if dParentPID != 0
      invoke Process32First_, hSnapshot, addr pe32
      .while eax != 0
        mov eax, pe32.th32ProcessID
        .if eax == dParentPID
          invoke StrIComp, addr pe32.szExeFile, $OfsCStrW("cmd.exe")
          .if eax == 0
            BitSet [xsi].dFlags, CAF_HOST_CMD
          .endif
          invoke StrIComp, addr pe32.szExeFile, $OfsCStrW("powershell.exe")
          .if eax == 0
            BitSet [xsi].dFlags, CAF_HOST_PS
          .endif
          invoke StrIComp, addr pe32.szExeFile, $OfsCStrW("pwsh.exe")
          .if eax == 0
            BitSet [xsi].dFlags, CAF_HOST_PS
          .endif
          invoke StrIComp, addr pe32.szExeFile, $OfsCStrW("explorer.exe")
          .if eax == 0
            BitSet [xsi].dFlags, CAF_HOST_EXPLORER
          .endif
          .break
        .endif
        invoke Process32Next_, hSnapshot, addr pe32
      .endw
    .endif

    invoke CloseHandle, hSnapshot
  .endif
  
  invoke GetConsoleProcessList, addr dPIDs, lengthof(dPIDs)
  .if eax <= 1
    ; Only one process attached = we own the console = window will close on exit
    BitSet [xsi].dFlags, CAF_OWNCONSOLE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Print
; Purpose:    Output a message on the console. Output can be redirected!
; Arguments:  Arg1: -> Message.
; Return:     Nothing.

Method ConsoleApp.Print, uses xbx, pMessage:PSTRING
  local dWritten:DWORD

  invoke StrLength, pMessage
  SetObject xcx
  lea xbx, dWritten
  .ifBitSet [xcx].dFlags, CAF_REDIRECTED
    invoke WriteFile, [xcx].hOutput, pMessage, addr [eax*sizeof(CHR)], xbx, NULL
  .else
    invoke WriteConsole, [xcx].hConsole, pMessage, eax, xbx, NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.PrintLn
; Purpose:    Output a message and a line break on the console. Output can be redirected!
; Arguments:  Arg1: -> Message. If NULL, only CRLF is printed.
; Return:     Nothing.

Method ConsoleApp.PrintLn, uses xsi, pMessage:PSTRING
  local dWritten:DWORD

  SetObject xsi
  .if pMessage != NULL
    OCall xsi.Print, pMessage
  .endif
  .ifBitSet [xsi].dFlags, CAF_REDIRECTED
    invoke WriteFile, [xsi].hOutput, addr cCRLF, 2*sizeof(CHR), addr dWritten, NULL
  .else
    invoke WriteConsole, [xsi].hConsole, addr cCRLF, 2, addr dWritten, NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetCaption
; Purpose:    Set console caption text.
; Arguments:  Arg1: -> Text.
; Return:     Nothing.

Method ConsoleApp.SetCaption,, pCaption:PSTRING
  invoke SetConsoleTitle, pCaption
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetCursorPos
; Purpose:    Set the cursor position.
; Arguments:  Arg1: X character cell coordinate.
;             Arg2: Y character cell coordinate.
; Return:     Nothing.

Method ConsoleApp.SetCursorPos,, dCoordX:DWORD, dCoordY:DWORD
  SetObject xax
  mov edx, dCoordY
  shl edx, 16
  mov dx, WORD ptr dCoordX
  invoke SetConsoleCursorPosition, [xax].hConsole, edx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetColor
; Purpose:    Set the output foreground and background color.
; Arguments:  Arg1: Color setting.
;             Combination of
;             Foreground: FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_INTENSITY
;             Background: BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED, BACKGROUND_INTENSITY
; Return:     Nothing.

Method ConsoleApp.SetColor,, wColorSetting:WORD
  SetObject xax
  invoke SetConsoleTextAttribute, [xax].hConsole, wColorSetting
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetProgressBar
; Purpose:    Set console ProgressBar at given coordinates.
; Arguments:  Arg1: X character cell coordinate.
;             Arg2: Y character cell coordinate.
;             Arg3: Progress [0..MaxProgress]
;             Arg4: Max progress value
; Return:     Nothing.

Method ConsoleApp.SetProgressBar, uses xbx xsi, dCoordX:DWORD, dCoordY:DWORD, \
                                                dProgress:DWORD, dMax:DWORD
  local dCharsWritten:DWORD, cBuffer[1024]:CHR

  SetObject xsi
  OCall xsi.SetCursorPos, dCoordX, dCoordY
  mov ecx, lengthof cBuffer - 2
  mov ebx, dMax
  cmp ebx, ecx
  cmovg ebx, ecx
  mov eax, dProgress
  cmp eax, ebx
  cmovg eax, ebx

  lea xdx, cBuffer
  mov CHR ptr [xdx], '['
  add xdx, sizeof(CHR)
  xor ecx, ecx
  .while ecx < eax
    mov CHR ptr [xdx], '='
    add xdx, sizeof(CHR)
    inc ecx
  .endw
  .while ecx < ebx
    mov CHR ptr [xdx], ' '
    add xdx, sizeof(CHR)
    inc ecx
  .endw
  mov CHR ptr [xdx], ']'
  add ebx, 2
  invoke WriteConsole, [xsi].hConsole, addr cBuffer, ebx, addr dCharsWritten, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetIcon
; Purpose:    Set the console icon.
; Arguments:  Arg1: Icon handle.
; Return:     Nothing.
; Note:       The SetConsoleIcon API is not exported, so we need to get the proc address first.

TypeSetConsoleIcon typedef proto :HANDLE

Method ConsoleApp.SetIcon, uses xsi, hIcon:HICON
  SetObject xsi
  .if [xsi].pSetConsoleIcon == NULL
    invoke GetModuleHandle, $OfsCStr("kernel32.dll")
    invoke GetProcAddress, xax, $OfsCStr("SetConsoleIcon")
    mov [xsi].pSetConsoleIcon, xax
  .else
    mov xax, [xsi].pSetConsoleIcon
  .endif
  .if xax != NULL
    invoke TypeSetConsoleIcon ptr xax, hIcon
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.ShowCursor
; Purpose:    Show the console cursor.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.ShowCursor
  local cci:CONSOLE_CURSOR_INFO

  SetObject xax
  mov cci.dwSize, 25                                    ;Cursor fill percentage (1-100)
  mov cci.bVisible, TRUE
  lea xdx, cci
  invoke SetConsoleCursorInfo, [xax].hConsole, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SpinnerProc
; Purpose:    Spinner timer procedure.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.SpinnerProc, uses xsi
  local dCharsWritten:DWORD, cBuffer:CHR

  SetObject xsi
  OCall xsi.SetCursorPos, [xsi].SpinnerPosition.x, [xsi].SpinnerPosition.y
  mov eax, [xsi].dSpinnerStep
  .if eax == 0
    mov CHR ptr cBuffer, '|'     ;7C
  .elseif eax == 1
    mov CHR ptr cBuffer, '/'     ;2F
  .elseif eax == 2
    mov CHR ptr cBuffer, '-'     ;2D
  .else
    mov CHR ptr cBuffer, '\'     ;5C
  .endif
  inc eax
  and eax, 3
  mov [xsi].dSpinnerStep, eax
  invoke WriteConsole, [xsi].hConsole, addr cBuffer, 1, addr dCharsWritten, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.StartSpinner
; Purpose:    Start the spinner at current cursor location.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.StartSpinner, uses xsi
  local dCharsRead:DWORD, coord:COORD

  SetObject xsi
  .if [xsi].hTimerQueue != 0
    OCall xsi.GetCursorPos
    .if eax != -1
      mov [xsi].SpinnerPosition.x, eax
      mov [xsi].SpinnerPosition.y, ecx
      mov coord.X, ax
      mov coord.Y, cx
      invoke ReadConsoleOutputCharacter, [xsi].hConsole, addr [xsi].cSpinnerPosChar, 1, \
                                         coord, addr dCharsRead
      OCall xsi.HideCursor
      invoke CreateTimerQueueTimer, addr [xsi].hSpinnerTimer, [xsi].hTimerQueue, \
                                    $MethodAddr(ConsoleApp.SpinnerProc), \
                                    xsi, [xsi].dSpinnerWaitTime, [xsi].dSpinnerWaitTime, 0
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.StopSpinner
; Purpose:    Stop the spinner.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.StopSpinner, uses xsi
  local dCharsWritten:DWORD, coord:COORD

  SetObject xsi
  invoke DeleteTimerQueueTimer, [xsi].hTimerQueue, [xsi].hSpinnerTimer, INVALID_HANDLE_VALUE
  mov [xsi].hSpinnerTimer, 0
  mov eax, [xsi].SpinnerPosition.x
  mov ecx, [xsi].SpinnerPosition.y
  mov coord.X, ax
  mov coord.Y, cx
  invoke WriteConsoleOutputCharacter, [xsi].hConsole, addr [xsi].cSpinnerPosChar, 1, \
                                      coord, addr dCharsWritten
  OCall xsi.SetCursorPos, [xsi].SpinnerPosition.x, [xsi].SpinnerPosition.y
  OCall xsi.ShowCursor
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Write
; Purpose:    Output a message on the console ONLY.
; Arguments:  Arg1: -> Message.
; Return:     Nothing.

Method ConsoleApp.Write, uses xbx, pMessage:PSTRING
  local dCharsWritten:DWORD

  invoke StrLength, pMessage
  lea xbx, dCharsWritten
  SetObject xcx
  invoke WriteConsole, [xcx].hConsole, pMessage, eax, xbx, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.WriteLn
; Purpose:    Output a message and a line break on the console ONLY.
; Arguments:  Arg1: -> Message. If NULL, only CRLF is printed.
; Return:     Nothing.

Method ConsoleApp.WriteLn, uses xsi, pMessage:PSTRING
  local dCharsWritten:DWORD

  SetObject xsi
  .if pMessage != NULL
    OCall xsi.Write, pMessage
  .endif
  invoke WriteConsole, [xsi].hConsole, addr cCRLF, 2, addr dCharsWritten, NULL
MethodEnd

endif
