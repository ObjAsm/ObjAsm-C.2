; ==================================================================================================
; Title:      LuaHost_Main.inc
; Author:     G. Friedrich
; Version:    See LuaHost.asm
; Purpose:    ObjAsm Lua Host Application.
; ==================================================================================================


Object Application, -1, DialogModal
  VirtualMethod     EnableControls,   DWORD
  VirtualMethod     FileLoad,         PSTRING
  VirtualMethod     FileSave,         PSTRING, POINTER, DWORD

  RedefineMethod    Init
  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnDestroy,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM
  RedefineMethod    OnSize,           WPARAM, LPARAM

  VirtualEvent      OnDropFiles,      WM_DROPFILES
  VirtualEvent      OnFinished,       LHM_SCRIPT_FINISHED           ;Host notification

  DefineVariable    pFileName,        PSTRING,      NULL            ;Currently open FileName
  DefineVariable    hEditFont,        HFONT,        0               ;Script Control font
  DefineVariable    CFD,              CHARFORMAT2A, {sizeof CHARFORMAT2A} ;Output Control Format

  Embed     SplitterHor,      Splitter
  Embed     Host,             LuaHost
ObjectEnd


.code

; ==================================================================================================
;    Host implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Host.ScriptInit
; Purpose:    Script custom initialization.
; Arguments:  Arg1: -> lua_State.
; Return:     eax = LUA_OK if succeeded, otherwise an error code.

Method Host.ScriptInit,, plua_State:Plua_State
  DbgText "Host.ScriptInit"

  ;Create the Output object (table)
  invoke lua_createtable, plua_State, 0, 0

  invoke lua_pushstring, plua_State, $OfsCStrA("SetFont")
  invoke lua_pushcclosure, plua_State, addr OutputSetFont, 0
  invoke lua_settable, plua_State, -3

  invoke lua_pushstring, plua_State, $OfsCStrA("SetBackColor")
  invoke lua_pushcclosure, plua_State, addr OutputSetBackColor, 0
  invoke lua_settable, plua_State, -3

  invoke lua_pushstring, plua_State, $OfsCStrA("SetTextColor")
  invoke lua_pushcclosure, plua_State, addr OutputSetTextColor, 0
  invoke lua_settable, plua_State, -3

  invoke lua_pushstring, plua_State, $OfsCStrA("Write")
  invoke lua_pushcclosure, plua_State, addr OutputWrite, 0
  invoke lua_settable, plua_State, -3

  invoke lua_pushstring, plua_State, $OfsCStrA("WriteLn")
  invoke lua_pushcclosure, plua_State, addr OutputWriteLn, 0
  invoke lua_settable, plua_State, -3

  invoke lua_pushstring, plua_State, $OfsCStrA("Clear")
  invoke lua_pushcclosure, plua_State, addr OutputClear, 0
  invoke lua_settable, plua_State, -3

  invoke lua_setglobal, plua_State, $OfsCStrA("Output")

  ;Create the RGB global function
  invoke lua_pushcclosure, plua_State, addr lua_RGB, 0
  invoke lua_setglobal, plua_State, $OfsCStrA("RGB")

  ;Create the font effect constants
  invoke lua_pushinteger, plua_State, CFM_BOLD
  invoke lua_setglobal, plua_State, $OfsCStrA("FONT_BOLD")
  invoke lua_pushinteger, plua_State, CFM_ITALIC
  invoke lua_setglobal, plua_State, $OfsCStrA("FONT_ITALIC")
  invoke lua_pushinteger, plua_State, CFM_UNDERLINE
  invoke lua_setglobal, plua_State, $OfsCStrA("FONT_UNDERLINE")
  invoke lua_pushinteger, plua_State, CFM_STRIKEOUT
  invoke lua_setglobal, plua_State, $OfsCStrA("FONT_STRIKEOUT")
  invoke lua_pushinteger, plua_State, CFM_SUBSCRIPT
  invoke lua_setglobal, plua_State, $OfsCStrA("FONT_SUBSCRIPT")
  invoke lua_pushinteger, plua_State, CFM_SUPERSCRIPT
  invoke lua_setglobal, plua_State, $OfsCStrA("FONT_SUPERSCRIPT")

  mov eax, LUA_OK
MethodEnd


; ==================================================================================================
;    Application implementation
; ==================================================================================================

DEFAULT_FONT_HEIGHT equ 11

;Lua Host Dialog Control Bit Mask
LHD_BTN_LOAD    equ   BIT00
LHD_BTN_SAVE    equ   BIT01
LHD_BTN_RUN     equ   BIT02
LHD_BTN_STOP    equ   BIT03
LHD_RED_SCRIPT  equ   BIT04
LHD_RED_OUTPUT  equ   BIT05

; --------------------------------------------------------------------------------------------------
; Method:     Application.EnableControls
; Purpose:    Enable the UI Buttons specified in the mask and disable the rest
; Arguments:  Arg1: Enable flag [LHD_xxx...].
; Return:     xax -> MemBlock or NULL if failed.

LHD_EnableControl macro TextID
  invoke GetDlgItem, [xsi].hWnd, IDC_&TextID&
  xor edx, edx
  test dEnableMask, LHD_&TextID&
  setnz dl
  invoke EnableWindow, xax, edx
endm

Method Application.EnableControls, uses xsi, dEnableMask:DWORD
  SetObject xsi
  LHD_EnableControl BTN_LOAD
  LHD_EnableControl BTN_SAVE
  LHD_EnableControl BTN_RUN
  LHD_EnableControl BTN_STOP
  LHD_EnableControl RED_SCRIPT
  LHD_EnableControl RED_OUTPUT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.FileLoad
; Purpose:    Load a file into the memory block.
; Arguments:  Arg1: -> FileName.
; Return:     eax: TRUE if succeeded, otherwise FALSE.

Method Application.FileLoad, uses xbx xsi, pFileName:PSTRING
  local hFile:HANDLE, dFileSize:DWORD, dBytesRead:DWORD, pMemBlock:POINTER
  local cBuffer[1024*sizeof CHR]:CHR

  SetObject xsi
  ;Open the file
  xor ebx, ebx
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, \
                     FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    ;Get a buffer to read in the file, with room to null-terminate
    invoke GetFileSize, xax, NULL
    .if eax != -1
      mov dFileSize, eax
      inc eax
      MemAlloc eax
      .if xax != NULL
        mov pMemBlock, xax
        lea xax, dBytesRead
        invoke ReadFile, hFile, pMemBlock, dFileSize, xax, 0
        mov ecx, dBytesRead
        .if eax == FALSE || ecx != dFileSize
          MemFree pMemBlock
        .else
          ;Set ZTC
          mov eax, dFileSize
          add xax, pMemBlock
          m2z BYTE ptr [xax]

          invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, WM_SETTEXT, 0, pMemBlock
          MemFree pMemBlock
          OCall xsi.EnableControls, LHD_BTN_LOAD or LHD_BTN_SAVE or LHD_BTN_RUN or \
                                    LHD_RED_SCRIPT or LHD_RED_OUTPUT
          invoke StrCCopy, addr cBuffer, offset szCaption, lengthof cBuffer
          invoke StrCECat, addr cBuffer, pFileName, lengthof cBuffer
          invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, addr cBuffer

          .if [xsi].pFileName != NULL
            invoke StrDispose, [xsi].pFileName
          .endif
          mov [xsi].pFileName, $invoke(StrNew, pFileName)
          inc ebx
        .endif
      .endif
    .endif
    invoke CloseHandle, hFile
  .endif
  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.FileSave
; Purpose:    Write memory block into a file.
; Arguments:  Arg1: -> FileName.
;             Arg2: -> Memblock.
;             Arg3: -> MemSize.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Application.FileSave, uses xsi, pFileName:PSTRING, pMemBlock:POINTER, dMemSize:DWORD
  local hFile:HANDLE, dBytesWritten:DWORD, dResult:DWORD
  local cBuffer[1024*sizeof CHR]:CHR

  SetObject xsi
  invoke FileExist, pFileName
  .if eax != FALSE
    invoke MessageBox, [xsi].hWnd, $OfsCStr("File already exist. Overwrite it?"), \
                       offset szCaption, MB_OKCANCEL or MB_ICONWARNING
    .if eax == IDCANCEL
      jmp @@Exit
    .endif
  .endif
  ;Open the file
  invoke CreateFile, pFileName, GENERIC_WRITE, FILE_SHARE_WRITE, 0, \
                     CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    mov dResult, $32($invoke(WriteFile, hFile, pMemBlock, dMemSize, addr dBytesWritten, NULL))
    invoke CloseHandle, hFile

    invoke StrCCopy, addr cBuffer, offset szCaption, lengthof cBuffer
    invoke StrCECat, addr cBuffer, pFileName, lengthof cBuffer
    invoke SendMessageA, [xsi].hWnd, WM_SETTEXT, 0, addr cBuffer

    .if [xsi].pFileName != NULL
      invoke StrDispose, [xsi].pFileName
    .endif
    mov [xsi].pFileName, $invoke(StrNew, pFileName)

    mov eax, dResult
  .else
@@Exit:
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the Dialog object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  SetObject xsi
  ACall xsi.Init, NULL, 0, IDD_MAIN
  Override [xsi].Host::LuaHost.ScriptInit, Host.ScriptInit 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local AbtDlg:$Obj(DialogAbout), hIcon:HICON
  local OpenFileName:OPENFILENAME, cFileName[MAX_PATH*sizeof CHR]:CHR
  local hDC:HDC, pScript:PSTRINGA

  SetObject xsi
  mov xax, wParam

  .if ax == IDC_BTN_LOAD
    mov OpenFileName.lStructSize, sizeof OPENFILENAME
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xcx
    c2m OpenFileName.lpstrFilter, offset szLoadFilter, xax
    m2z OpenFileName.lpstrCustomFilter
    m2z OpenFileName.nMaxCustFilter
    m2z OpenFileName.nFilterIndex
    lea xax, cFileName
    m2z CHR ptr [xax]
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof cFileName - 1
    m2z OpenFileName.lpstrFileTitle
    m2z OpenFileName.nMaxFileTitle
    m2z OpenFileName.lpstrInitialDir
    c2m OpenFileName.lpstrTitle, $OfsCStr("Choose a Lua File to load"), xax
    c2m OpenFileName.lpstrDefExt, offset szLuaExt, xax
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    m2z OpenFileName.FlagsEx
    invoke GetOpenFileName, addr OpenFileName
    .if eax == TRUE
      OCall xsi.FileLoad, addr cFileName
    .endif
    xor eax, eax

  .elseif ax == IDC_BTN_ABOUT
    New AbtDlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall AbtDlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall AbtDlg::DialogAbout.Show
    OCall AbtDlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                      ;Return zero

  .elseif ax == IDC_BTN_SAVE
    mov OpenFileName.lStructSize, sizeof OPENFILENAME
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xcx
    m2m OpenFileName.lpstrFilter, offset szLoadFilter, xax
    m2z OpenFileName.lpstrCustomFilter
    m2z OpenFileName.nMaxCustFilter
    m2z OpenFileName.nFilterIndex
    lea xax, cFileName
    m2z CHR ptr [xax]
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof cFileName - 1
    m2z OpenFileName.lpstrFileTitle
    m2z OpenFileName.nMaxFileTitle
    m2z OpenFileName.lpstrInitialDir
    c2m OpenFileName.lpstrTitle, $OfsCStr("Choose a Lua file to save"), xax
    c2m OpenFileName.lpstrDefExt, offset szLuaExt, xax
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    m2z OpenFileName.FlagsEx
    invoke GetSaveFileName, addr OpenFileName
    .if eax == TRUE
      invoke SendDlgItemMessage, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXTLENGTH, 0, 0
      lea xbx, [xax + 1]
      mov pScript, $MemAlloc(xbx)
      invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXT, xbx, pScript
      OCall xsi.FileSave, addr cFileName, pScript, ebx
      MemFree pScript
    .endif
    xor eax, eax

  .elseif ax == IDC_BTN_RUN
    invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXTLENGTH, 0, 0
    .if eax != 0
      inc eax                                         ;ZTC
      mov ebx, eax
      MemAlloc eax                                    ;LuaHost releases it in its own thread
      .if xax != NULL
        mov pScript, xax
        invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXT, ebx, pScript
        OCall xsi.EnableControls, LHD_BTN_STOP

        ;Fill the CHARFORMAT2A structure with default values for the output control
        mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_RED_OUTPUT)
        mov [xsi].CFD.dwMask, CFM_COLOR or CFM_BACKCOLOR or \
                              CFM_FACE or CFM_SIZE or \
                              CFM_BOLD or CFM_ITALIC or CFM_STRIKEOUT or CFM_UNDERLINE or \
                              CFM_SUBSCRIPT or CFM_SUPERSCRIPT
        m2z [xsi].CFD.dwEffects
        mov hDC, $invoke(GetWindowDC, xbx)
        invoke GetDeviceCaps, hDC, LOGPIXELSY
        invoke MulDiv, DEFAULT_FONT_HEIGHT, 1920, eax
        mov [xsi].CFD.yHeight, eax
        mov [xsi].CFD.crTextColor, $RGB(0,0,0)
        mov [xsi].CFD.crBackColor, $RGB(255,255,255)
        FillStringA [xsi].CFD.szFaceName, <Lucida Console>
        invoke ReleaseDC, xbx, hDC

        ;Start script execution
        OCall [xsi].Host::LuaHost.Start, pScript
        .if eax == FALSE
          DbgWarning "Failed to start the script"
        .endif
      .endif
    .endif
    xor eax, eax                                      ;Return zero

  .elseif ax == IDC_BTN_STOP
    OCall [xsi].Host::LuaHost.Stop
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if [xsi].hEditFont != 0
    invoke DeleteObject, [xsi].hEditFont
  .endif

  OCall [xsi].SplitterHor::Splitter.Done

  .if [xsi].pFileName != 0
    invoke StrDispose, [xsi].pFileName
  .endif

  OCall [xsi].Host::LuaHost.Done

  ACall xsi.OnDestroy, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnDropFiles
; Purpose:    Event procedure for WM_DROPFILES message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnDropFiles, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov edi, $32($invoke(DragQueryFile, wParam, 0, NULL, 0))
  inc edi                                               ;Include ZTC
  mov xbx, $invoke(StrAlloc, edi)
  invoke DragQueryFile, wParam, 0, xbx, edi             ;Get the FileName
  invoke PathFindExtension, xbx
  .if xax != NULL
    .if $invoke(StrIComp, xax, offset szLuaExt) == 0
      OCall xsi.FileLoad, xbx
      test eax, eax
      jnz @@Exit
    .endif
  .endif
  invoke MessageBox, [xsi].hWnd, offset szFileTypeErr, offset szAppTitle, MB_ICONEXCLAMATION

  @@Exit:
  invoke StrDispose, xbx
  invoke DragFinish, wParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnFinished
; Purpose:    Event procedure for LHM_SCRIPT_FINISHED message.
; Arguments:  Arg1: First message parameter (Lua result).
;             Arg2: Second message parameter (pScript).
; Return:     Nothing.

Method Application.OnFinished, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "Application.OnFinished"
  SetObject xsi
  OCall xsi.EnableControls, LHD_BTN_LOAD or LHD_BTN_SAVE or LHD_BTN_RUN or \
                            LHD_RED_SCRIPT or LHD_RED_OUTPUT
  .if wParam != LUA_OK
    .if wParam == LUA_ERRRUN
      .ifBitSet [xsi].Host.dFlags, LHF_SCRIPT_STOP
        mov xdx, $OfsCStr("The user has stopped the running script")
        invoke MessageBox, [xsi].hWnd, xdx, $OfsCStr("Information"), MB_OK or MB_ICONINFORMATION
        ExitMethod
      .else
        mov xdx, $OfsCStr("Fatal error while running the script")
      .endif
    .elseif wParam == LUA_ERRSYNTAX
      mov xdx, $OfsCStr("Fatal script syntax error")
    .elseif wParam == LUA_ERRMEM
      mov xdx, $OfsCStr("Fatal memory allocation error")
    .elseif wParam == LUA_ERRERR
      mov xdx, $OfsCStr("Fatal error handler error")
    .else
      mov xdx, $OfsCStr("Fatal unknown Error")
    .endif
    invoke MessageBox, [xsi].hWnd, xdx, offset szError, MB_OK or MB_ICONERROR
  .endif
  MemFree lParam
  invoke SetFocus, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  local LogFnt:LOGFONT, hDC:HDC

  SetObject xsi
  OCall [xsi].SplitterHor::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_HORIZONTAL, 250, 50, 50

  OCall [xsi].Host::LuaHost.Init, xsi
  OCall xsi.EnableControls, LHD_BTN_LOAD

  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
    ;Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif

  ;Set the Editbox font to "Lucida Console", 11pt, regular
  FillString LogFnt.lfFaceName, <Lucida Console>
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, DEFAULT_FONT_HEIGHT, eax, -72
  mov LogFnt.lfHeight, eax
  m2z LogFnt.lfWidth
  m2z LogFnt.lfEscapement
  m2z LogFnt.lfOrientation
  mov LogFnt.lfWeight, FW_DONTCARE
  m2z LogFnt.lfItalic
  m2z LogFnt.lfUnderline
  m2z LogFnt.lfStrikeOut
  mov LogFnt.lfCharSet, DEFAULT_CHARSET
  mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov LogFnt.lfQuality, CLEARTYPE_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xsi].hEditFont, $invoke(CreateFontIndirect, addr LogFnt)
  invoke ReleaseDC, [xsi].hWnd, hDC
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_RED_SCRIPT, WM_SETFONT, [xsi].hEditFont, TRUE

  invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, EM_REPLACESEL, TRUE,
          $OfsCStrA(CRLF, CRLF, CRLF, TAB, "Drop a lua file here or press the 'Load' button on the right")

  invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, offset szCaption
  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_LOAD)
  OCall xsi.CtlsSet
  invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, 0 ;Position all controls
  invoke SetForegroundWindow, [xsi].hWnd

  xor eax, eax                                          ;Return FALSE to prevent Windows from
MethodEnd                                               ;setting the default keyboard focus.

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

BUTTON_WIDTH      equ   130
BUTTON_HEIGHT     equ   35
BUTTON_HSPACE     equ   10
BUTTON_VSPACE     equ   10
BUTTON_CSPACE     equ   10
BORDER_HSPACE     equ   10
BORDER_VSPACE     equ   10
SPLITTER_VSPACE   equ   1
SPLITTER_HEIGTH   equ   8

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local DlgRect:RECT, SpHorRect:RECT
  local hControl:HWND, CtlRect:RECT
  local X1:DWORD, Y1:DWORD
  local dEditWidth:DWORD

  DbgText "Application.OnSize"
  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr DlgRect

    ;Get horizontal Splitter position
    invoke GetWindowRect, [xsi].SplitterHor.hWnd, addr SpHorRect
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.right

    ;Place Code Edit control
    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_RED_SCRIPT)
    invoke GetWindowRect, hControl, addr CtlRect
    mov ecx, DlgRect.right
    sub ecx, BUTTON_WIDTH + 2*BORDER_HSPACE + BUTTON_CSPACE
    mov dEditWidth, ecx
    mov eax, SpHorRect.top
    sub eax, BORDER_VSPACE + SPLITTER_VSPACE
    invoke MoveWindow, hControl, BORDER_HSPACE, BORDER_VSPACE, dEditWidth, eax, FALSE

    ;Place Output Edit control
    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_RED_OUTPUT)
    mov eax, SpHorRect.top
    add eax, SPLITTER_HEIGTH + SPLITTER_VSPACE
    mov ebx, DlgRect.bottom
    sub ebx, eax
    sub ebx, BORDER_VSPACE
    invoke MoveWindow, hControl, BORDER_HSPACE, eax, dEditWidth, ebx, FALSE

    ;Place horizontal Splitter control
    invoke MoveWindow, [xsi].SplitterHor.hWnd, BORDER_HSPACE, SpHorRect.top, dEditWidth, \
                       SPLITTER_HEIGTH, FALSE

    ;Place Button controls
    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_LOAD)
    mov eax, dEditWidth
    add eax, BORDER_HSPACE + BUTTON_CSPACE
    mov X1, eax
    mov Y1, BORDER_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_SAVE)
    add Y1, BUTTON_HEIGHT + BUTTON_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_RUN)
    add Y1, BUTTON_HEIGHT + 4*BUTTON_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_STOP)
    add Y1, BUTTON_HEIGHT + BUTTON_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_ABOUT)
    mov eax, DlgRect.bottom
    sub eax, 4*BORDER_VSPACE + BUTTON_HEIGHT
    mov ecx, Y1
    add ecx, BUTTON_VSPACE + BUTTON_HEIGHT
    .if SDWORD ptr eax < ecx
      mov eax, ecx
    .endif
    invoke MoveWindow, hControl, X1, eax, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_SBR_GRIPPER)
    invoke GetClientRect, hControl, addr CtlRect
    mov edx, DlgRect.right
    sub edx, CtlRect.right
    mov eax, DlgRect.bottom
    sub eax, CtlRect.bottom
    invoke MoveWindow, hControl, edx, eax, CtlRect.right, CtlRect.bottom, FALSE

    ;Redraw all child windows
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                         RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN

    xor eax, eax                                        ;Return zero
  .endif
MethodEnd
