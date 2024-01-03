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
  DynamicMethod     ScriptInit,       Plua_State

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
  
  OCall xsi.ScriptInit, xbx
  cmp eax, LUA_OK
  jnz @@Error

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
  invoke PostMessage, [xax].$Obj(WinPrimer).hWnd, LHM_SCRIPT_FINISHED, dRetVal, 0
  invoke CloseHandle, [xsi].hThread                     ;Decrement HANDLE count to release hThrend
  mov eax, dRetVal                                      ; when terminated
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     LuaHost.ScriptInit
; Purpose:    Script custom initialization.
; Arguments:  Arg1: -> lua_State.
; Return:     eax = LUA_OK if succeeded, otherwise an error code.

Method LuaHost.ScriptInit,, plua_State:Plua_State
  DbgText "LuaHost.ScriptInit"
  mov eax, LUA_OK
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
