; ==================================================================================================
; Title:      LuaHost.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Lua Host objects.
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


;Lua Host Messages we use to communicate with the main application
LHM_SCRIPT_FINISHED equ WM_USER + 10

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     LuaHost
; Purpose:    Implement a host container object for the Lua engine.
; Links:      https://www.lua.org/
; Notes:      - The Lua engine runs in its own thread, which is started with the Start method. 
;               This allows the engine to be used without freezing the GUI.

Object LuaHost, LuaHostID, Streamable
  RedefineMethod    Done
  VirtualMethod     Run
  VirtualMethod     Start,            PSTRINGA
  VirtualMethod     Stop

  DefineVariable    hThread,          HANDLE,       0
  DefineVariable    dFlags,           DWORD,        0
  DefineVariable    pScript,          PSTRINGA,     NULL
ObjectEnd



; ==================================================================================================

if IMPLEMENT

;Lua Host Flags
LHF_SCRIPT_STOP     equ BIT00

; ==================================================================================================
;    LuaHost implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     lua_HookProc
; Purpose:    Control Lua instruction flow to implement a "Stop" function.
; Arguments:  Arg1: -> lua_State
;             Arg2: -> lua_Debug
; Return:     eax = Number of arguments passed on the lua stack.

lua_HookProc proc uses xbx pLuaState:ptr lua_State, plua_Debug:ptr lua_Debug
;  ?mov edx, plua_Debug
;  DbgDec [xdx].lua_Debug.currentline

  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  .ifBitSet [xax].$Obj(LuaHost).dFlags, LHF_SCRIPT_STOP
    invoke lua_pushstring, pLuaState, $OfsCStrA("STOP")
    invoke lua_error, pLuaState
  .endif
  xor eax, eax
  ret
lua_HookProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     lua_RGB
; Purpose:    Return a decimal value from an rgb triplet.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

lua_RGB proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check it
  and eax, 255
  mov ebx, eax
  invoke luaL_checkinteger, pLuaState, 2                ;Get second stack argument and check it
  and eax, 255
  shl eax, 8
  add ebx, eax
  invoke luaL_checkinteger, pLuaState, 3                ;Get third stack argument and check it
  and eax, 255
  shl eax, 16
  add ebx, eax
  invoke lua_pushinteger, pLuaState, ebx

  mov eax, 1
  ret
lua_RGB endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OutputClear
; Purpose:    Clear Output RichEdit control content.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

OutputClear proc uses xbx pLuaState:ptr lua_State
  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xcx, [xax].$Obj(LuaHost).pOwner
  mov xbx, $invoke(GetDlgItem, [xcx].$Obj(Application).hWnd, IDC_RED_OUTPUT)
  invoke SendMessageA, xbx, EM_SETSEL, 0, -1
  invoke SendMessageA, xbx, WM_CLEAR, 0, 0
  invoke SendMessageA, xbx, EM_SCROLLCARET, 0, 0        ;Move caret into view
  xor eax, eax                                          ;No arguments
  ret
OutputClear endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OutputSetBackColor
; Purpose:    Set the background color of the Output RichEdit control.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

OutputSetBackColor proc uses xbx pLuaState:ptr lua_State
  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xbx, [xax].$Obj(LuaHost).pOwner
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for str
  mov [xbx].$Obj(Application).CFD.crBackColor, eax
  xor eax, eax                                          ;No arguments
  ret
OutputSetBackColor endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OutputSetTextColor
; Purpose:    Set the text color of the Output RichEdit control.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

OutputSetTextColor proc uses xbx pLuaState:ptr lua_State
  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xbx, [xax].$Obj(LuaHost).pOwner
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for str
  mov [xbx].$Obj(Application).CFD.crTextColor, eax
  xor eax, eax                                          ;No arguments
  ret
OutputSetTextColor endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OutputSetFont
; Purpose:    Set the text font of the Output RichEdit control.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

OutputSetFont proc uses xbx xdi xsi pLuaState:ptr lua_State
  local hDC:HDC

  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xbx, [xax].$Obj(LuaHost).pOwner

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check it
  lea xcx, [xbx].$Obj(Application).CFD.szFaceName
  invoke StrCopyA, xcx, xax

  mov xsi, $invoke(GetDlgItem, [xbx].$Obj(Application).hWnd, IDC_RED_OUTPUT)
  mov hDC, $invoke(GetWindowDC, xax)
  mov edi, $32($invoke(GetDeviceCaps, xax, LOGPIXELSY))
  invoke luaL_checkinteger, pLuaState, 2                ;Get second stack argument and check it
  invoke MulDiv, eax, 1920, edi
  mov [xbx].$Obj(Application).CFD.yHeight, eax
  invoke ReleaseDC, xsi, hDC

  invoke luaL_checkinteger, pLuaState, 3                ;Get third stack argument and check it
  mov [xbx].$Obj(Application).CFD.dwEffects, eax

  xor eax, eax                                          ;No arguments
  ret
OutputSetFont endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OutputWrite
; Purpose:    Writes a string on the Output RichEdit control.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

OutputWrite proc uses xbx pLuaState:ptr lua_State
  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xcx, [xax].$Obj(LuaHost).pOwner
  mov xbx, $invoke(GetDlgItem, [xcx].$Obj(Application).hWnd, IDC_RED_OUTPUT)

  invoke SendMessageA, xbx, EM_SETCHARFORMAT, SCF_SELECTION, offset $ObjTmpl(Application).CFD
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  invoke SendMessageA, xbx, EM_REPLACESEL, TRUE, xax
  invoke SendMessageA, xbx, EM_SCROLLCARET, 0, 0        ;Move caret into view
  xor eax, eax                                          ;No arguments
  ret
OutputWrite endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OutputWriteLn
; Purpose:    Writes a string on the Output RichEdit control with a CRLF at the end.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments passed on the lua stack.

OutputWriteLn proc uses xbx pLuaState:ptr lua_State
  invoke lua_getglobal, pLuaState, $OfsCStrA("pLuaHost")  ;Retrieve -> LuaHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xcx, [xax].$Obj(LuaHost).pOwner
  mov xbx, $invoke(GetDlgItem, [xcx].$Obj(Application).hWnd, IDC_RED_OUTPUT)

  invoke SendMessageA, xbx, EM_SETCHARFORMAT, SCF_SELECTION, offset $ObjTmpl(Application).CFD
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  invoke SendMessageA, xbx, EM_REPLACESEL, TRUE, xax
  invoke SendMessageA, xbx, EM_REPLACESEL, TRUE, offset bCRLF
  invoke SendMessageA, xbx, EM_SCROLLCARET, 0, 0        ;Move caret into view
  xor eax, eax                                          ;No arguments
  ret
OutputWriteLn endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     LuaHost.Done
; Purpose:    Finalize the Script engine object.
; Arguments:  None.
; Return:     Nothing.

Method LuaHost.Done, uses xsi
  DbgText "LuaHost.Done"
  SetObject xsi
  .if [xsi].hThread != 0
    invoke WaitForSingleObject, [xsi].hThread, 4000     ;Wait max 4 secs
    .if eax == WAIT_TIMEOUT
      DbgWarning "Script thread was forced to terminate; some resources may not be released."
      invoke TerminateThread, [xsi].hThread, -1
      invoke CloseHandle, [xsi].hThread
    .endif
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     LuaHost.Run
; Purpose:    Message Handler for LHM_SCRIPT_EXECUTE.
; Arguments:  None.
; Return:     eax = return value (Lua error code).

Method LuaHost.Run, uses xbx xsi
  local pLuaState:ptr lua_State, dRetVal:DWORD

  DbgText "LuaHost.Run"

  SetObject xsi
  mov dRetVal, LUA_OK

  ;Initialize Lua & load libraries
  mov xbx, $invoke(luaL_newstate)
  invoke luaL_openlibs, xbx

  ;Store a pointer to the LuaHost as a global variable
  invoke lua_pushinteger, xbx, xsi
  invoke lua_setglobal, xbx, $OfsCStrA("pLuaHost")

  ;Set the call hook
  invoke lua_sethook, xbx, addr lua_HookProc, LUA_MASKLINE, 0

  ;Create the Output object (table)
  invoke lua_createtable, xbx, 0, 0

  invoke lua_pushstring, xbx, $OfsCStrA("SetFont")
  invoke lua_pushcclosure, xbx, addr OutputSetFont, 0
  invoke lua_settable, xbx, -3

  invoke lua_pushstring, xbx, $OfsCStrA("SetBackColor")
  invoke lua_pushcclosure, xbx, addr OutputSetBackColor, 0
  invoke lua_settable, xbx, -3

  invoke lua_pushstring, xbx, $OfsCStrA("SetTextColor")
  invoke lua_pushcclosure, xbx, addr OutputSetTextColor, 0
  invoke lua_settable, xbx, -3

  invoke lua_pushstring, xbx, $OfsCStrA("Write")
  invoke lua_pushcclosure, xbx, addr OutputWrite, 0
  invoke lua_settable, xbx, -3

  invoke lua_pushstring, xbx, $OfsCStrA("WriteLn")
  invoke lua_pushcclosure, xbx, addr OutputWriteLn, 0
  invoke lua_settable, xbx, -3

  invoke lua_pushstring, xbx, $OfsCStrA("Clear")
  invoke lua_pushcclosure, xbx, addr OutputClear, 0
  invoke lua_settable, xbx, -3

  invoke lua_setglobal, xbx, $OfsCStrA("Output")

  ;Create the RGB global function
  invoke lua_pushcclosure, xbx, addr lua_RGB, 0
  invoke lua_setglobal, xbx, $OfsCStrA("RGB")

  ;Create the font effect constants
  invoke lua_pushinteger, xbx, CFM_BOLD
  invoke lua_setglobal, xbx, $OfsCStrA("FONT_BOLD")
  invoke lua_pushinteger, xbx, CFM_ITALIC
  invoke lua_setglobal, xbx, $OfsCStrA("FONT_ITALIC")
  invoke lua_pushinteger, xbx, CFM_UNDERLINE
  invoke lua_setglobal, xbx, $OfsCStrA("FONT_UNDERLINE")
  invoke lua_pushinteger, xbx, CFM_STRIKEOUT
  invoke lua_setglobal, xbx, $OfsCStrA("FONT_STRIKEOUT")
  invoke lua_pushinteger, xbx, CFM_SUBSCRIPT
  invoke lua_setglobal, xbx, $OfsCStrA("FONT_SUBSCRIPT")
  invoke lua_pushinteger, xbx, CFM_SUPERSCRIPT
  invoke lua_setglobal, xbx, $OfsCStrA("FONT_SUPERSCRIPT")

  ;Load the script
  invoke luaL_loadstring, xbx, [xsi].pScript
  cmp eax, LUA_OK
  jnz @@Error

  ;Execute the script
  invoke lua_pcallk, xbx, 0, LUA_MULTRET, 0, 0, NULL

@@Error:
  mov dRetVal, eax

  ;Housekeeping
  invoke lua_close, xbx                                 ;Run the garbage collector one last time
  MemFree [xsi].pScript
  m2z [xsi].pScript

  ;Inform the main Application that the script has finished and pass an result value 
  mov xax, [xsi].pOwner
  invoke PostMessage, [xax].$Obj(Application).hWnd, LHM_SCRIPT_FINISHED, dRetVal, 0
  invoke CloseHandle, [xsi].hThread                     ;Decrement HANDLE count to release hThrend
  mov eax, dRetVal                                      ; when terminated
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     LuaHost.Start
; Purpose:    Start script execution.
; Arguments:  Arg1: -> ANSI string containing the script to execute.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method LuaHost.Start, uses xsi, pScript:PSTRINGA
  DbgText "LuaHost.Start"
  SetObject xsi
  m2m [xsi].pScript, pScript, xax
  invoke CreateThread, NULL, 0, $MethodAddr(xsi::LuaHost.Run), xsi, CREATE_SUSPENDED, NULL
  .if xax != 0
    mov [xsi].hThread, xax
    mov [xsi].dFlags, 0                                 ;Reset all other flags
    invoke ResumeThread, xax
    mov eax, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     LuaHost.Stop
; Purpose:    Stop script execution.
; Arguments:  None.
; Return:     Nothing.

Method LuaHost.Stop
  DbgText "LuaHost.Stop"
  SetObject xcx
  BitSet [xcx].dFlags, LHF_SCRIPT_STOP
MethodEnd

endif
