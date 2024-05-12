; ==================================================================================================
; Title:      ConsoleApp.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ConsoleApp objects.
; Link:       https://learn.microsoft.com/en-us/windows/console/creating-a-pseudoconsole-session
; Notes:      Version C.1.0, April 2024
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ConsoleApp
; Purpose:    ConsoleApp is the base object for all console descendant application objects.

Object ConsoleApp, ConsoleAppID, Streamable
  VirtualAbstract   Run

  RedefineMethod    Done
  VirtualMethod     GetChar
  VirtualMethod     GetCharUC
  RedefineMethod    Init,             POINTER
  VirtualMethod     Print,            PSTRING
  VirtualMethod     PrintLn,          PSTRING
  VirtualMethod     SetCaption,       PSTRING
  VirtualMethod     SetColor,         WORD

  DefineVariable    hError,           HANDLE,     0
  DefineVariable    hInput,           HANDLE,     0
  DefineVariable    hOutput,          HANDLE,     0
ObjectEnd


; ==================================================================================================


if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.Done
; Purpose:    Finalize the ConsoleApp object.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.Done, uses xsi
  SetObject xsi
  invoke FreeConsole
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.GetChar
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

Method ConsoleApp.GetChar, uses xsi
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.GetCharUC
; Purpose:    Get a character from the console input and convert it to uppercase.
; Arguments:  None.
; Return:     al/ax = Uppercase character.

Method ConsoleApp.GetCharUC, uses xbx xsi
  SetObject xsi
  OCall xsi.GetChar
  .if eax >= 'a' && eax <= 'z'
    sub eax, 'a' - 'A'
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.Init
; Purpose:    Initialize the ConsoleApp object.
; Arguments:  Arg1 -> Owner.
; Return:     Nothing.

Method ConsoleApp.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  invoke AttachConsole, ATTACH_PARENT_PROCESS
  .if eax == 0
    invoke AllocConsole
  .endif
  .if eax != 0
    mov [xsi].hError,  $invoke(GetStdHandle, STD_ERROR_HANDLE)
    mov [xsi].hInput,  $invoke(GetStdHandle, STD_INPUT_HANDLE)
    mov [xsi].hOutput, $invoke(GetStdHandle, STD_OUTPUT_HANDLE)
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.Print
; Purpose:    Output a message on the console.
; Arguments:  Arg1: -> Message.
; Return:     Nothing.

Method ConsoleApp.Print, uses xbx xsi, pMessage:PSTRING
  local dCharsWritten:DWORD

  SetObject xsi
  invoke StrLength, pMessage
  lea xbx, dCharsWritten
  invoke WriteConsole, [xsi].hOutput, pMessage, eax, xbx, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.PrintLn
; Purpose:    Output a message and a line break on the console.
; Arguments:  Arg1: -> Message.
; Return:     Nothing.

Method ConsoleApp.PrintLn, uses xbx xsi, pMessage:PSTRING
  local dCharsWritten:DWORD

  SetObject xsi
  OCall xsi.Print, pMessage
  lea xbx, dCharsWritten
  invoke WriteConsole, [xsi].hOutput, addr cCRLF, 2*sizeof(CHR), xbx, NULL  ;MUST be 1 CHAR only!
  ;The console only accepts LF. A CR is shown as a space.
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.SetCaption
; Purpose:    Set console caption text.
; Arguments:  Arg1: -> Text.
; Return:     Nothing.

Method ConsoleApp.SetCaption,, pCaption:PSTRING
  invoke SetConsoleTitle, pCaption
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConsoleApp.SetColor
; Purpose:    Set the output foreground and background color.
; Arguments:  Arg1: Color setting.
;             Combination of FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_INTENSITY
;             and BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED and BACKGROUND_INTENSITY.
; Return:     Nothing.

Method ConsoleApp.SetColor,, wColorSetting:WORD
  SetObject xax
  invoke SetConsoleTextAttribute, [xax].hOutput, wColorSetting
MethodEnd

endif
