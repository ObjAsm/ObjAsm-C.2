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
;               - ClearScreen bug corrected and adaptet for Windows Terminal.
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
  DefineVariable    hError,           HANDLE,   INVALID_HANDLE_VALUE
  DefineVariable    hInput,           HANDLE,   INVALID_HANDLE_VALUE
  DefineVariable    hOutput,          HANDLE,   INVALID_HANDLE_VALUE  ;Follows redirection; used by Print(Ln)
  DefineVariable    hConsole,         HANDLE,   INVALID_HANDLE_VALUE  ;Physical console; used by Write(Ln) etc.
  DefineVariable    dInputMode,       DWORD,    0
  DefineVariable    dOutputMode,      DWORD,    0
  DefineVariable    hTimerQueue,      HANDLE,   INVALID_HANDLE_VALUE
  DefineVariable    hSpinnerTimer,    HANDLE,   INVALID_HANDLE_VALUE
  DefineVariable    dSpinnerStep,     DWORD,    0       ;0..3
  DefineVariable    dSpinnerWaitTime, DWORD,    150     ;ms
  DefineVariable    SpinnerPosition,  POINT,    {0, 0}
  DefineVariable    cSpinnerPosChar,  CHR,      ' '
  DefineVariable    pSetConsoleIcon,  POINTER,  NULL    ;SetConsoleIcon API proc
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


; ============================================================
; VT / ANSI / xterm   Escape Sequence Reference
; ============================================================

; --- Cursor movement -----------------------------------------
; ESC[H                    Move cursor to home (0,0) (CUP)
; ESC[{r};{c}H             Move cursor to row r, column c (CUP)
; ESC[{r};{c}f             Move cursor to row r, column c (HVP)
; ESC[#A                   Move cursor up # lines (CUU)
; ESC[#B                   Move cursor down # lines (CUD)
; ESC[#C                   Move cursor right # columns (CUF)
; ESC[#D                   Move cursor left # columns (CUB)
; ESC[#E                   Move to beginning of next line, # lines down (CNL)
; ESC[#F                   Move to beginning of prev line, # lines up (CPL)
; ESC[#G                   Move cursor to column # (CHA)
; ESC[#d                   Move cursor to row # (VPA)
; ESC[#e                   Move cursor down # rows (VPR)
; ESC[#`                   Move cursor to column # (HPA) - same as CHA
; ESC[#a                   Move cursor right # columns (HPR) - same as CUF
; ESC[6n                   Request cursor position - terminal replies ESC[r;cR (CPR)
; ESC[?6n                  Extended cursor position report - terminal replies ESC[?r;cR
; ESC[s                    Save cursor position (SCO / SCOSC)
; ESC[u                    Restore cursor position (SCO / SCORC)
; ESC 7                    Save cursor position + attributes (DECSC)
; ESC 8                    Restore cursor position + attributes (DECRC)

; --- Erase ---------------------------------------------------
; ESC[J  / ESC[0J          Erase from cursor to end of screen (ED)
; ESC[1J                   Erase from cursor to beginning of screen (ED)
; ESC[2J                   Erase entire visible screen (ED)
; ESC[3J                   Erase saved scrollback lines (xterm extension)
; ESC[?J / ESC[?0J         Selective erase to end of screen (DECSED)
; ESC[?1J                  Selective erase to beginning of screen (DECSED)
; ESC[?2J                  Selective erase entire screen (DECSED)
; ESC[K  / ESC[0K          Erase from cursor to end of line (EL)
; ESC[1K                   Erase from start of line to cursor (EL)
; ESC[2K                   Erase entire current line (EL)
; ESC[?K / ESC[?0K         Selective erase to end of line (DECSEL)
; ESC[?1K                  Selective erase to beginning of line (DECSEL)
; ESC[?2K                  Selective erase entire line (DECSEL)

; --- Insert / Delete -----------------------------------------
; ESC[#@                   Insert # blank characters at cursor (ICH)
; ESC[#P                   Delete # characters at cursor (DCH)
; ESC[#X                   Erase # characters at cursor, no shift (ECH)
; ESC[#L                   Insert # blank lines above cursor (IL)
; ESC[#M                   Delete # lines from cursor down (DL)

; --- Scroll --------------------------------------------------
; ESC[#S                   Scroll up # lines (SU)
; ESC[#T                   Scroll down # lines (SD)
; ESC[{t};{b}r             Set scroll region: top=t, bottom=b (DECSTBM)
; ESC[{l};{r}s             Set left/right margins l and r (DECSLRM - requires DECLRMM)
; ESC M                    Reverse index - scroll down one if at top of region (RI)

; --- Rectangular area operations (VT400+) -------------------
; ESC[{Pt};{Pl};{Pb};{Pr};{Ps}$r   Change attributes in rectangle (DECCARA)
; ESC[{Pt};{Pl};{Pb};{Pr};{Ps}$t   Reverse attributes in rectangle (DECRARA)
; ESC[{Pt};{Pl};{Pb};{Pr};{Ps}$v   Copy rectangular area (DECCRA)
; ESC[{Pt};{Pl};{Pb};{Pr};{Pp}$w   Request present cursor position report (DECRQPSR)
; ESC[{Pt};{Pl};{Pb};{Pr};{Ps}$x   Fill rectangle with character (DECFRA)
; ESC[{Pt};{Pl};{Pb};{Pr}$z        Erase rectangle (DECERA)
; ESC[{Pt};{Pl};{Pb};{Pr}${        Selective erase rectangle (DECSERA)

; --- SGR - Reset & text attributes --------------------------
; ESC[0m                   Reset all attributes
; ESC[1m                   Bold
; ESC[2m                   Dim / faint
; ESC[3m                   Italic
; ESC[4m                   Underline (single)
; ESC[4:0m                 Underline - no underline (alias for ESC[24m)
; ESC[4:1m                 Underline - single (default when ESC[4m used)
; ESC[4:2m                 Underline - double
; ESC[4:3m                 Underline - curly / wavy
; ESC[4:4m                 Underline - dotted
; ESC[4:5m                 Underline - dashed
; ESC[5m                   Blink (slow, < 150 times/min)
; ESC[6m                   Blink rapid (>= 150 times/min) - rarely supported
; ESC[7m                   Reverse video (swap fg/bg)
; ESC[8m                   Conceal / hidden
; ESC[9m                   Strikethrough (crossed-out)
; ESC[10m                  Primary (default) font
; ESC[11m–ESC[19m          Alternate fonts 1–9
; ESC[20m                  Fraktur / gothic (rarely supported)
; ESC[21m                  Doubly underlined (or reset bold in some terminals)
; ESC[22m                  Reset bold and dim (normal intensity)
; ESC[23m                  Reset italic and fraktur
; ESC[24m                  Reset underline
; ESC[25m                  Reset blink
; ESC[26m                  Proportional spacing (ECMA-48; rarely supported)
; ESC[27m                  Reset reverse video
; ESC[28m                  Reset conceal (reveal)
; ESC[29m                  Reset strikethrough
; ESC[50m                  Reset proportional spacing
; ESC[51m                  Framed
; ESC[52m                  Encircled
; ESC[53m                  Overlined
; ESC[54m                  Reset framed and encircled
; ESC[55m                  Reset overlined
; ESC[73m                  Superscript (mintty / VTE extension)
; ESC[74m                  Subscript (mintty / VTE extension)
; ESC[75m                  Reset superscript and subscript

; --- SGR - Standard colors -----------------------------------
; ESC[30m–ESC[37m          Foreground: Black Red Green Yellow Blue Magenta Cyan White
; ESC[38;5;{n}m            Foreground: 256-color index n (0–255)
; ESC[38;2;{r};{g};{b}m    Foreground: 24-bit RGB true color
; ESC[38;2:{r}:{g}:{b}m    Foreground: 24-bit RGB (colon-separated, ISO 8613-6 form)
; ESC[39m                  Foreground: default color
; ESC[40m–ESC[47m          Background: Black Red Green Yellow Blue Magenta Cyan White
; ESC[48;5;{n}m            Background: 256-color index n (0–255)
; ESC[48;2;{r};{g};{b}m    Background: 24-bit RGB true color
; ESC[48;2:{r}:{g}:{b}m    Background: 24-bit RGB (colon-separated)
; ESC[49m                  Background: default color
; ESC[58;5;{n}m            Underline color: 256-color index n
; ESC[58;2;{r};{g};{b}m    Underline color: 24-bit RGB (xterm/VTE/kitty)
; ESC[59m                  Underline color: default

; --- SGR - Bright / high-intensity colors --------------------
; ESC[90m–ESC[97m          Foreground: Bright Black … Bright White (aixterm extension)
; ESC[100m–ESC[107m        Background: Bright Black … Bright White (aixterm extension)

; --- SGR - Character protection -----------------------------
; ESC[0"q                  DECSCA - unprotected (default)
; ESC[1"q                  DECSCA - protected (not erased by DECSED/DECSEL)
; ESC[2"q                  DECSCA - unprotected

; --- Cursor appearance ---------------------------------------
; ESC[?25l                 Hide cursor (DECTCEM off)
; ESC[?25h                 Show cursor (DECTCEM on)
; ESC[?12h                 Enable cursor blinking
; ESC[?12l                 Disable cursor blinking
; ESC[0 q                  Cursor shape: default (terminal-defined)
; ESC[1 q                  Cursor shape: blinking block
; ESC[2 q                  Cursor shape: steady block
; ESC[3 q                  Cursor shape: blinking underline
; ESC[4 q                  Cursor shape: steady underline
; ESC[5 q                  Cursor shape: blinking bar (I-beam)
; ESC[6 q                  Cursor shape: steady bar (I-beam)

; --- Screen / buffer -----------------------------------------
; ESC[?1049h               Switch to alternate screen buffer (saves cursor)
; ESC[?1049l               Return to main screen buffer (restores cursor)
; ESC[?47h                 Enter alternate screen (older - no cursor save)
; ESC[?47l                 Exit alternate screen (older)
; ESC[?1047h               Switch to alternate screen buffer (xterm)
; ESC[?1047l               Return to main screen buffer (xterm)
; ESC[?2004h               Enable bracketed paste mode
; ESC[?2004l               Disable bracketed paste mode

; --- Window / terminal size queries (xterm) -----------------
; ESC[14t                  Report terminal window size in pixels ? ESC[4;height;widtht
; ESC[16t                  Report cell size in pixels ? ESC[6;height;widtht
; ESC[18t                  Report terminal size in characters ? ESC[8;rows;colst
; ESC[19t                  Report screen size in characters
; ESC[20t                  Report icon label ? ESC]L{label}ESC\
; ESC[21t                  Report window title ? ESC]l{title}ESC\
; ESC[22;0t                Save window title (and icon) to stack
; ESC[22;1t                Save icon label to stack
; ESC[22;2t                Save window title to stack
; ESC[23;0t                Restore window title (and icon) from stack
; ESC[23;1t                Restore icon label from stack
; ESC[23;2t                Restore window title from stack

; --- DEC private modes (h = set, l = reset) -----------------
; ESC[?1h  / ESC[?1l       Application / normal cursor keys (DECCKM)
; ESC[?2l                  VT52 mode (DECANM) - no set; use ESC[?2h to leave
; ESC[?3h  / ESC[?3l       132 / 80 column mode (DECCOLM)
; ESC[?4h  / ESC[?4l       Smooth / jump scroll (DECSCLM)
; ESC[?5h  / ESC[?5l       Reverse / normal screen video (DECSCNM)
; ESC[?6h  / ESC[?6l       Origin relative / absolute (DECOM)
; ESC[?7h  / ESC[?7l       Auto-wrap on / off (DECAWM)
; ESC[?8h  / ESC[?8l       Auto-repeat keys on / off (DECARM)
; ESC[?9h  / ESC[?9l       X10 mouse reporting on / off
; ESC[?10h / ESC[?10l      Show / hide toolbar (rxvt)
; ESC[?12h / ESC[?12l      Blinking cursor on / off (AT&T 610)
; ESC[?18h / ESC[?18l      Print form feed on / off (DECPFF)
; ESC[?19h / ESC[?19l      Print extent full screen / scrolling region (DECPEX)
; ESC[?25h / ESC[?25l      Show / hide cursor (DECTCEM)
; ESC[?30h / ESC[?30l      Show / hide scrollbar (rxvt)
; ESC[?35h / ESC[?35l      Font-shifting on / off (rxvt)
; ESC[?38h / ESC[?38l      Tektronix mode on / off (DECTEK)
; ESC[?40h / ESC[?40l      Allow / disallow 80?132 column mode (xterm)
; ESC[?41h / ESC[?41l      more(1) fix on / off (xterm)
; ESC[?42h / ESC[?42l      National replacement character set on / off (DECNRCM)
; ESC[?44h / ESC[?44l      Margin bell on / off (xterm)
; ESC[?45h / ESC[?45l      Reverse-wraparound on / off (xterm)
; ESC[?46h / ESC[?46l      Logging on / off (xterm - requires compile-time option)
; ESC[?47h / ESC[?47l      Alternate screen on / off (older form)
; ESC[?66h / ESC[?66l      Application / normal numeric keypad (DECNKM)
; ESC[?67h / ESC[?67l      Backspace key sends BS / DEL (DECBKM)
; ESC[?69h / ESC[?69l      Left/right margin mode on / off (DECLRMM)
; ESC[?80h / ESC[?80l      Sixel display - sixel scrolling on / off
; ESC[?95h / ESC[?95l      Do not clear screen on DECCOLM change (xterm)
; ESC[?1000h / ESC[?1000l  X10-compatible mouse button reporting on / off
; ESC[?1001h / ESC[?1001l  Hilite mouse tracking on / off (highlight mode)
; ESC[?1002h / ESC[?1002l  Button-event mouse tracking on / off
; ESC[?1003h / ESC[?1003l  Any-event mouse tracking on / off
; ESC[?1004h / ESC[?1004l  Focus in/out events on / off
; ESC[?1005h / ESC[?1005l  UTF-8 extended mouse coordinate encoding on / off
; ESC[?1006h / ESC[?1006l  SGR extended mouse coordinate encoding on / off
; ESC[?1007h / ESC[?1007l  Alternate scroll on / off (xterm - mouse wheel ? cursor keys in alt screen)
; ESC[?1010h / ESC[?1010l  Scroll to bottom on tty output on / off (rxvt)
; ESC[?1011h / ESC[?1011l  Scroll to bottom on key press on / off (rxvt)
; ESC[?1015h / ESC[?1015l  URXVT extended mouse coordinate encoding on / off
; ESC[?1016h / ESC[?1016l  SGR pixel mouse coordinate encoding on / off
; ESC[?1034h / ESC[?1034l  Interpret meta key on / off (xterm - sets 8th bit)
; ESC[?1035h / ESC[?1035l  Special modifiers for alt and num lock on / off (xterm)
; ESC[?1036h / ESC[?1036l  Send ESC when meta key is pressed on / off (xterm)
; ESC[?1037h / ESC[?1037l  Send DEL from the editing-keypad Delete key on / off (xterm)
; ESC[?1039h / ESC[?1039l  Alt sends ESC on / off (xterm)
; ESC[?1040h / ESC[?1040l  Keep selection even if not highlighted on / off (xterm)
; ESC[?1041h / ESC[?1041l  Use Clipboard selection on / off (xterm)
; ESC[?1042h / ESC[?1042l  Enable urgency on bell on / off (xterm)
; ESC[?1043h / ESC[?1043l  Enable raising window on bell on / off (xterm)
; ESC[?1044h / ESC[?1044l  Reuse most recent data copied to clipboard on / off (xterm)
; ESC[?1046h / ESC[?1046l  Enable / disable switching to alternate screen buffer (xterm)
; ESC[?1047h / ESC[?1047l  Alternate screen buffer on / off (xterm)
; ESC[?1048h / ESC[?1048l  Save / restore cursor (xterm)
; ESC[?1049h / ESC[?1049l  Save cursor + switch to alternate screen / restore (xterm)
; ESC[?2004h / ESC[?2004l  Bracketed paste mode on / off
; ESC[?2026h / ESC[?2026l  Synchronized output on / off (xterm 379+, kitty, etc.)

; --- ANSI modes (h = set, l = reset) ------------------------
; ESC[2h  / ESC[2l         Keyboard locked / unlocked (KAM)
; ESC[4h  / ESC[4l         Insert / replace mode (IRM)
; ESC[12h / ESC[12l        Local echo off / on (SRM)
; ESC[20h / ESC[20l        Newline / linefeed mode (LNM)

; --- Tab stops -----------------------------------------------
; HT   (0x09)              Advance to next tab stop
; ESC H                    Set tab stop at current column (HTS)
; ESC[g  / ESC[0g          Clear tab stop at current column (TBC)
; ESC[3g                   Clear all tab stops (TBC)
; ESC[{n}I                 Move forward # tab stops (CHT)
; ESC[{n}Z                 Move backward # tab stops (CBT)

; --- Margins -------------------------------------------------
; ESC[{t};{b}r             Set top/bottom scroll margins (DECSTBM)
; ESC[{l};{r}s             Set left/right margins (DECSLRM - requires DECLRMM enabled)

; --- Character sets and encoding ----------------------------
; ESC ( A                  Designate G0 = UK character set
; ESC ( B                  Designate G0 = US ASCII (default)
; ESC ( 0                  Designate G0 = DEC special graphics (line drawing)
; ESC ) B                  Designate G1 = US ASCII
; ESC ) 0                  Designate G1 = DEC special graphics
; ESC * B                  Designate G2 = US ASCII (VT220+)
; ESC + B                  Designate G3 = US ASCII (VT220+)
; ESC N                    Single shift G2 (SS2) - next char from G2 set
; ESC O                    Single shift G3 (SS3) - next char from G3 set
; ESC ~                    Invoke G1 into GR (LS1R)
; ESC n                    Invoke G2 into GL (LS2)
; ESC }                    Invoke G2 into GR (LS2R)
; ESC o                    Invoke G3 into GL (LS3)
; ESC |                    Invoke G3 into GR (LS3R)
; ESC % @                  Return to ISO 2022 / ECMA-35 (default coding)
; ESC % G                  Select UTF-8 encoding

; --- Device / status -----------------------------------------
; ESC[0c                   Primary device attributes (DA1) - terminal replies ESC[?{params}c
; ESC[>0c                  Secondary device attributes (DA2) - terminal replies ESC[>{Pp};{Pv};{Pc}c
; ESC[=0c                  Tertiary device attributes (DA3) - terminal replies DCS!|{data}ST
; ESC Z                    Identify terminal (DECID) - same reply as DA1
; ESC[5n                   Device status report - terminal replies ESC[0n (ok) or ESC[3n (error)
; ESC[6n                   Cursor position report - terminal replies ESC[{r};{c}R
; ESC[?6n                  Extended cursor position - terminal replies ESC[?{r};{c}R
; ESC[?15n                 Printer status - terminal replies ESC[?{n}n
; ESC[?25n                 User-defined key (UDK) status
; ESC[?26n                 Keyboard dialect report
; ESC[!p                   Soft terminal reset (DECSTR)
; ESC[{pg};{pc}"p          Set conformance level (DECSCL)
; ESC[#p                   Push video attributes onto stack (XTPUSHSGR / XTSAVE)
; ESC[#{q}                 Pop video attributes from stack (XTPOPSGR / XTRESTORE)
; ESC[>{n}m                Set/reset key modifier options (xterm modifyOtherKeys)
; ESC[?{n}m                Query key modifier options (xterm)

; --- Keyboard / key modifiers (xterm) -----------------------
; ESC[>4;{n}m              Set modifyOtherKeys: 0=off 1=enabled 2=all keys
; ESC[>4m                  Reset modifyOtherKeys
; ESC[?4m                  Query modifyOtherKeys

; --- VT52 mode sequences (after ESC[?2l) --------------------
; ESC A                    Cursor up
; ESC B                    Cursor down
; ESC C                    Cursor right
; ESC D                    Cursor left
; ESC F                    Enter graphics mode
; ESC G                    Exit graphics mode
; ESC H                    Cursor to home
; ESC I                    Reverse line feed
; ESC J                    Erase to end of screen
; ESC K                    Erase to end of line
; ESC Y {r} {c}            Direct cursor address (row and col as 0x20 + value)
; ESC Z                    Identify - terminal replies ESC/Z
; ESC =                    Application keypad
; ESC >                    Normal keypad
; ESC <                    Exit VT52 mode (return to ANSI/VT100)

; --- OSC - Operating System Commands -------------------------
; (Terminated by BEL 0x07 or ST = ESC \)
; ESC]0;{title}BEL         Set icon name and window title
; ESC]1;{name}BEL          Set icon name only
; ESC]2;{title}BEL         Set window title only
; ESC]3;{prop=val}BEL      Set X11 window property
; ESC]4;{n};{spec}BEL      Set palette color n (spec = rgb:rr/gg/bb or X11 name)
; ESC]4;{n};?BEL           Query palette color n - terminal replies ESC]4;n;rgb:...BEL
; ESC]5;{n};{spec}BEL      Set special color n
; ESC]5;{n};?BEL           Query special color n
; ESC]6;{url}BEL           Set current working document URI (some terminals)
; ESC]7;{url}BEL           Set current working directory URI (iTerm2 / VTE)
; ESC]8;;{url}BEL          Hyperlink start (OSC 8)
; ESC]8;;BEL               Hyperlink end
; ESC]9;{msg}BEL           Desktop notification / toast (Windows Terminal)
; ESC]9;4;{state};{pct}BEL Taskbar progress (Windows Terminal): state 0=off 1=normal 2=error 3=indeterminate 4=paused
; ESC]10;{color}BEL        Set default foreground color
; ESC]10;?BEL              Query default foreground color
; ESC]11;{color}BEL        Set default background color
; ESC]11;?BEL              Query default background color
; ESC]12;{color}BEL        Set cursor color
; ESC]12;?BEL              Query cursor color
; ESC]13;{color}BEL        Set mouse foreground color
; ESC]14;{color}BEL        Set mouse background color
; ESC]15;{color}BEL        Set Tektronix foreground color
; ESC]16;{color}BEL        Set Tektronix background color
; ESC]17;{color}BEL        Set highlight foreground color
; ESC]18;{color}BEL        Set Tektronix cursor color
; ESC]19;{color}BEL        Set highlight background color
; ESC]46;{path}BEL         Set log file path (xterm)
; ESC]50;{spec}BEL         Set font (xterm)
; ESC]51;{args}BEL         Emacs shell (xterm - used by Emacs)
; ESC]52;{pc};{data}BEL    Manipulate clipboard (OSC 52); pc = clipboard target (c=clipboard), data = base64 or ? to query
; ESC]104;{n}BEL           Reset palette color n (omit n = reset all)
; ESC]105;{n}BEL           Reset special color n
; ESC]110BEL               Reset default foreground color
; ESC]111BEL               Reset default background color
; ESC]112BEL               Reset cursor color
; ESC]113BEL               Reset mouse foreground color
; ESC]114BEL               Reset mouse background color
; ESC]115BEL               Reset Tektronix foreground color
; ESC]116BEL               Reset Tektronix background color
; ESC]133;A BEL            Shell integration: prompt start (FTCS_PROMPT)
; ESC]133;B BEL            Shell integration: prompt end (FTCS_COMMAND_START)
; ESC]133;C BEL            Shell integration: command executed (FTCS_COMMAND_EXECUTED)
; ESC]133;D;{code} BEL     Shell integration: command finished, exit code (FTCS_COMMAND_FINISHED)
; ESC]1337;SetMark BEL     Add scroll mark / command mark (iTerm2 / Windows Terminal)
; ESC]1337;CurrentDir={path}BEL  Report current directory (iTerm2)
; ESC]1337;File={args}:{base64}BEL  Inline image protocol (iTerm2 imgcat)

; --- Miscellaneous -------------------------------------------
; ESC[#}                   XTPUSHSGR - push SGR attributes onto stack
; ESC[#{                   XTPOPSGR  - pop SGR attributes from stack
; ESC[0x                   DECREQTPARM - request terminal parameters; terminal replies ESC[{params}x
; ESC[{n}y                 DECTST - invoke confidence tests (n=2: power-up test)
; ESC[1~                   Home key (application keypad / editing)
; ESC[2~                   Insert key
; ESC[3~                   Delete key
; ESC[4~                   End key
; ESC[5~                   Page up
; ESC[6~                   Page down
; ESC OP                   F1  (SS3 P)
; ESC OQ                   F2  (SS3 Q)
; ESC OR                   F3  (SS3 R)
; ESC OS                   F4  (SS3 S)
; ESC[15~                  F5
; ESC[17~                  F6
; ESC[18~                  F7
; ESC[19~                  F8
; ESC[20~                  F9
; ESC[21~                  F10
; ESC[23~                  F11
; ESC[24~                  F12

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
  local dCharCellCount:DWORD, dCharsWritten:DWORD, csbi:CONSOLE_SCREEN_BUFFER_INFO

  SetObject xsi
  .ifBitClr [xsi].dFlags, CAF_REDIRECTED
    .ifBitSet [xsi].dFlags, CAF_HOST_WT or CAF_HOST_PS
      invoke WriteConsole, [xsi].hConsole, $OfsCStr(27, "[2J", 27, "[3J", 27, "[H"), \
                           ??StrLength, addr dCharsWritten, NULL
    .else
      invoke GetConsoleScreenBufferInfo, [xsi].hConsole, addr csbi
      .if eax != 0
        movzx eax, csbi.dwSize.X
        mul csbi.dwSize.Y
        mov dCharCellCount, eax
    
        invoke FillConsoleOutputCharacter, [xsi].hConsole, ' ', dCharCellCount, \
                                           COORD ptr 0, addr dCharsWritten
        invoke FillConsoleOutputAttribute, [xsi].hConsole, csbi.wAttributes, dCharCellCount, \
                                           COORD ptr 0, addr dCharsWritten
        invoke SetConsoleCursorPosition, [xsi].hConsole, COORD ptr 0
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ConsoleApp.Done
; Purpose:    Finalize the ConsoleApp object.
; Arguments:  None.
; Return:     Nothing.

Method ConsoleApp.Done, uses xsi
  SetObject xsi
  .if [xsi].hSpinnerTimer != INVALID_HANDLE_VALUE
    OCall xsi.StopSpinner
  .endif

  ;Delete the timer queue and wait for all callbacks to finish before closing handles.
  ;INVALID_HANDLE_VALUE makes DeleteTimerQueueEx block until pending callbacks return.
  invoke DeleteTimerQueueEx, [xsi].hTimerQueue, INVALID_HANDLE_VALUE
  mov [xsi].hTimerQueue, INVALID_HANDLE_VALUE

  ;Close hConsole only if it was separately opened (stdout was redirected).
  ;When not redirected hConsole == hOutput and must not be closed twice.
  mov xcx, [xsi].hConsole
  .if xcx != [xsi].hOutput && xcx != INVALID_HANDLE_VALUE
    invoke CloseHandle, xcx
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
  local pe32:PROCESSENTRY32_, cBuffer[MAX_PATH]:CHR
  local hSnapshot:HANDLE, dParentPID:DWORD, dCurrentPID:DWORD
  local dPIDs[16]:DWORD                                 ; Buffer for attached process IDs (DWORDs)

  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].dFlags, 0

  mov [xsi].hError,  $invoke(GetStdHandle, STD_ERROR_HANDLE)
  mov [xsi].hInput,  $invoke(GetStdHandle, STD_INPUT_HANDLE)
  mov [xsi].hOutput, $invoke(GetStdHandle, STD_OUTPUT_HANDLE)

  ; --- Detect stdout redirection ---
  invoke GetConsoleMode, [xsi].hOutput, addr [xsi].dOutputMode
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
  invoke GetConsoleMode, [xsi].hInput, addr [xsi].dInputMode
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

    invoke Process32First_, hSnapshot, addr pe32
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
  .if [xsi].hTimerQueue != INVALID_HANDLE_VALUE && [xsi].hSpinnerTimer == INVALID_HANDLE_VALUE
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
  mov [xsi].hSpinnerTimer, INVALID_HANDLE_VALUE
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
