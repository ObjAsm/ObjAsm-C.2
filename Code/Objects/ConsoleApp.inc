; ==================================================================================================
; Title:      ConsoleApp.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of ConsoleApp objects.
; Link:       https://learn.microsoft.com/en-us/windows/console/creating-a-pseudoconsole-session
; Notes:      Version C.1.0, April 2024
;               - First release.
;             Version C.1.1, June 2025
;               - PrintLn bug corrected by HSE.
;             Version C.1.2, September 2025
;               - Added some functions based on fearless console x64 and some minor changes.
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

  DefineVariable    hError,           HANDLE,   0
  DefineVariable    hInput,           HANDLE,   0
  DefineVariable    hOutput,          HANDLE,   0
  DefineVariable    hTimerQueue,      HANDLE,   0
  DefineVariable    pSetConsoleIcon,  POINTER,  NULL    ;SetConsoleIcon API proc
  DefineVariable    hSpinnerTimer,    HANDLE,   0
  DefineVariable    dSpinnerStep,     DWORD,    0       ;0..3
  DefineVariable    dSpinnerWaitTime, DWORD,    150     ;ms
  DefineVariable    SpinnerPosition,  POINT,    {0, 0}
  DefineVariable    cSpinnerPosChar,  CHR,      ' '
ObjectEnd


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

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.ClearScreen
; Purpose:    Remove the screen content.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.ClearScreen, uses xsi
  local dCharCellCount:DWORD, dCharsWritten:DWORD
  local coord:COORD, csbi:CONSOLE_SCREEN_BUFFER_INFO

  SetObject xsi
  invoke GetConsoleScreenBufferInfo, [xsi].hOutput, addr csbi
  .if eax != 0
    mov eax, csbi.dwSize                                ;2 word values returned for screen size

    ;Extract the 2 values and multiply them together
    mov ebx, eax
    shr eax, 16
    mul bx
    mov dCharCellCount, eax

    mov coord.X, 0
    mov coord.Y, 0

    invoke FillConsoleOutputCharacter, [xsi].hOutput, ' ', dCharCellCount, \
                                       addr coord, addr dCharsWritten
    invoke FillConsoleOutputAttribute, [xsi].hOutput, csbi.wAttributes, dCharCellCount, \
                                       addr coord, addr dCharsWritten
    invoke SetConsoleCursorPosition, [xsi].hOutput, addr coord
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Done
; Purpose:    Finalize the ConsoleApp object.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.Done, uses xsi
  SetObject xsi
  invoke FreeConsole
  invoke DeleteTimerQueueEx, [xsi].hTimerQueue, NULL
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
; Return:     Nothing.
; Note:       eax = x position or -1 if failed.
;             ecx = y position or -1 if failed.

Method ConsoleApp.GetCursorPos
  local csbi:CONSOLE_SCREEN_BUFFER_INFO

  SetObject xcx
  invoke GetConsoleScreenBufferInfo, [xcx].hOutput, addr csbi
  .if eax != 0
    movzx eax, WORD ptr csbi.dwCursorPosition
    movzx ecx, word ptr [csbi + sizeof WORD].dwCursorPosition
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
  .until (edx == KEY_EVENT) && (edx == InpRec.Event_.KeyEvent.bKeyDown)
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
  .if eax >= 'a' && eax <= 'z'
    sub eax, 'a' - 'A'
  .endif
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
  mov cci.dwSize, sizeof cci
  mov cci.bVisible, FALSE
  lea xdx, cci
  invoke SetConsoleCursorInfo, [xax].hOutput, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Init
; Purpose:    Initialize the ConsoleApp object.
; Arguments:  Arg1: -> Owner.
; Return:     Nothing.

Method ConsoleApp.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  invoke AttachConsole, ATTACH_PARENT_PROCESS
  .if eax == 0
    invoke AllocConsole
  .endif
  mov [xsi].hError,  $invoke(GetStdHandle, STD_ERROR_HANDLE)
  mov [xsi].hInput,  $invoke(GetStdHandle, STD_INPUT_HANDLE)
  mov [xsi].hOutput, $invoke(GetStdHandle, STD_OUTPUT_HANDLE)

  mov [xsi].hTimerQueue, $invoke(CreateTimerQueue)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Print
; Purpose:    Output a message on the console.
; Arguments:  Arg1: -> Message.
; Return:     Nothing.

Method ConsoleApp.Print, uses xbx, pMessage:PSTRING
  local dCharsWritten:DWORD

  invoke StrLength, pMessage
  lea xbx, dCharsWritten
  SetObject xcx
  invoke WriteConsole, [xcx].hOutput, pMessage, eax, xbx, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.PrintLn
; Purpose:    Output a message and a line break on the console.
; Arguments:  Arg1: -> Message. If NULL, only CRLF is printed.
; Return:     Nothing.

Method ConsoleApp.PrintLn, uses xsi, pMessage:PSTRING
  local dCharsWritten:DWORD

  SetObject xsi
  .if pMessage != NULL
    OCall xsi.Print, pMessage
  .endif
  invoke WriteConsole, [xsi].hOutput, addr cCRLF, 2, addr dCharsWritten, NULL
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
; Purpose:    Set console caption text.
; Arguments:  Arg1: X character cell coordinate.
;             Arg2: Y character cell coordinate.
; Return:     Nothing.

Method ConsoleApp.SetCursorPos,, dCoordX:DWORD, dCoordY:DWORD
  SetObject xax
  mov edx, dCoordY
  shl edx, 16
  mov dx, WORD ptr dCoordX
  invoke SetConsoleCursorPosition, [xax].hOutput, edx
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
  invoke SetConsoleTextAttribute, [xax].hOutput, wColorSetting
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetProgressBar
; Purpose:    Set console ProgressBar at given coordinates.
; Arguments:  Arg1: X character cell coordinate.
;             Arg2: Y character cell coordinate.
;             Arg3: Progress [0..MaxProgress]
;             Arg7: Max progress value
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
  invoke WriteConsole, [xsi].hOutput, addr cBuffer, ebx, addr dCharsWritten, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.SetIcon
; Purpose:    Set the console cursor.
; Arguments:  None.
; Return:     Nothing.
; Note:       THE SetConsoleIcon API is not exported, so we need to get the proc address first.

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
  invoke TypeSetConsoleIcon ptr xax, hIcon
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.ShowCursor
; Purpose:    Show the console cursor.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.ShowCursor
  local cci:CONSOLE_CURSOR_INFO

  SetObject xax
  mov cci.dwSize, sizeof cci
  mov cci.bVisible, TRUE
  lea xdx, cci
  invoke SetConsoleCursorInfo, [xax].hOutput, xdx
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
  invoke WriteConsole, [xsi].hOutput, addr cBuffer, 1, addr dCharsWritten, NULL
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
      invoke ReadConsoleOutputCharacter, [xsi].hOutput, addr [xsi].cSpinnerPosChar, 1, \
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
  invoke DeleteTimerQueueTimer, [xsi].hTimerQueue, [xsi].hSpinnerTimer, NULL
  mov [xsi].hSpinnerTimer, 0
  mov eax, [xsi].SpinnerPosition.x
  mov ecx, [xsi].SpinnerPosition.y
  mov coord.X, ax
  mov coord.Y, cx
  invoke WriteConsoleOutputCharacter, [xsi].hOutput, addr [xsi].cSpinnerPosChar, 1, \
                                      coord, addr dCharsWritten
  OCall xsi.SetCursorPos, [xsi].SpinnerPosition.x, [xsi].SpinnerPosition.y
  OCall xsi.ShowCursor
MethodEnd

endif
