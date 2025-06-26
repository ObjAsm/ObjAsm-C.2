; ==================================================================================================
; Title:      ADE_ScriptEngine.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; ScriptEngine implementation
; ==================================================================================================

;Lua Host Messages we use to communicate with the main application
SEM_SCRIPT_FINISHED equ WM_USER + 10

;ScriptEnding Flags
SEF_SCRIPT_STOP     equ BIT00

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  SEP_GlobalErrorHandler
; Purpose:    Echo a string to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Link:       https://chatgpt.com/c/685a52ef-4c34-800f-999b-dba9f246b7f4

SEP_GlobalErrorHandler proc pLuaState:ptr lua_State
  invoke lua_tolstring, pLuaState, 1, NULL
  .if xax == NULL
    mov xax, $OfsCStr("(error with no message)")
  .endif
  invoke luaL_traceback, pLuaState, pLuaState, xax, 1
  mov eax, 1
  ret
SEP_GlobalErrorHandler endp

; --------------------------------------------------------------------------------------------------
; Method:     SEP_HookProc
; Purpose:    Control Lua instruction flow to implement a "Stop" function.
; Arguments:  Arg1: -> lua_State
;             Arg2: -> lua_Debug
; Return:     eax = Number of arguments passed on the lua stack.

SEP_HookProc proc pLuaState:ptr lua_State, plua_Debug:ptr lua_Debug
;  ?mov edx, plua_Debug
;  DbgDec [xdx].lua_Debug.currentline
  .ifBitSet $ObjTmpl(Application).ScriptHost.dFlags, SEF_SCRIPT_STOP
    invoke lua_pushstring, pLuaState, $OfsCStrA("STOP")
    invoke lua_error, pLuaState
    mov eax, 1
  .else
    xor eax, eax
  .endif
  ret
SEP_HookProc endp

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.Done
; Purpose:    Finalize the Script engine object.
; Arguments:  None.
; Return:     Nothing.

Method ScriptEngine.Done, uses xsi
;  DbgText "ScriptEngine.Done"
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

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.Execute
; Purpose:    Script worker (sync/async).
; Arguments:  None.
; Return:     eax = return value (Lua error code).

;int main(int argc, char **argv) {
;
;    // Push error handler to stack
;    lua_pushcfunction(L, lua_error_handler);
;    int errfunc_index = lua_gettop(L);
;
;    // Load script
;    if (luaL_loadfile(L, argv[1]) != LUA_OK) {
;        fprintf(stderr, "Error loading file: %s\n", lua_tostring(L, -1));
;        lua_close(L);
;        return EXIT_FAILURE;
;    }
;
;    // Call script with error handler
;    if (lua_pcall(L, 0, LUA_MULTRET, errfunc_index) != LUA_OK) {
;        // Error is now the traceback string from our handler
;        fprintf(stderr, "Lua error:\n%s\n", lua_tostring(L, -1));
;        lua_pop(L, 1); // remove error message
;    }
;
;    // Clean up
;    lua_pop(L, 1); // remove error handler
;    lua_close(L);
;    return EXIT_SUCCESS;
;}

LuaAddToTable macro ElementGroup, ElementName
  
  invoke lua_pushstring, xbx, @CatStr(<$OfsCStrA(!">, ElementName, <!")>)
  invoke lua_pushcclosure, xbx, @CatStr(<addr >, ElementGroup, ElementName), 0
  invoke lua_settable, xbx, -3
endm


Method ScriptEngine.Execute, uses xbx xsi
  local pLuaState:ptr lua_State, dRetVal:DWORD, errfunc_index:DWORD

;  DbgText "ScriptEngine.Execute"
  SetObject xsi
  mov dRetVal, LUA_OK

  ;Initialize Lua & load libraries
  mov xbx, $invoke(luaL_newstate)                       ;Create a new interpreter instance
  invoke luaL_openlibs, xbx                             ;Load standrd libraries

  ;Create interface tables
  invoke lua_createtable, xbx, 0, 0
  LuaAddToTable Application, DbgPrint
  LuaAddToTable Application, DbgPrintLn
  LuaAddToTable Application, FreezeUI
  LuaAddToTable Application, InpBox
  LuaAddToTable Application, MsgBox
  LuaAddToTable Application, NewEditor
  LuaAddToTable Application, UnfreezeUI
  invoke lua_setglobal, xbx, $OfsCStrA("Application")

  invoke lua_createtable, xbx, 0, 0
  LuaAddToTable Editor, Close
  LuaAddToTable Editor, DelLine
;  LuaAddToTable Editor, GetCaretPos
  LuaAddToTable Editor, GetLineAttr
  LuaAddToTable Editor, GetLineCount
  LuaAddToTable Editor, GetLineText
  LuaAddToTable Editor, Hide
;  LuaAddToTable Editor, HideCaret
  LuaAddToTable Editor, Maximize
  LuaAddToTable Editor, Minimize
  LuaAddToTable Editor, NewLine
  LuaAddToTable Editor, Save
  LuaAddToTable Editor, SaveAs
  LuaAddToTable Editor, SaveTo
;  LuaAddToTable Editor, SetCaretPos
  LuaAddToTable Editor, SetLineAttr
  LuaAddToTable Editor, Restore
  LuaAddToTable Editor, SetLineText
  LuaAddToTable Editor, Show
;  LuaAddToTable Editor, ShowCaret
  invoke lua_setglobal, xbx, $OfsCStrA("Editor")
  
  ;Setup the error handler
  invoke lua_pushcclosure, xbx, addr SEP_GlobalErrorHandler, 0
  invoke lua_gettop, xbx 
  mov errfunc_index, eax

  ;Setup the call hook
  invoke lua_sethook, xbx, addr SEP_HookProc, LUA_MASKLINE, 0
  
  ;Load the script
  invoke luaL_loadstring, xbx, [xsi].pScript
  cmp eax, LUA_OK
  jnz @@Error

  ;Execute the script
  invoke lua_pcallk, xbx, 0, LUA_MULTRET, 0, 0, NULL
  cmp eax, LUA_OK
  jz @F

@@Error:
  invoke lua_tolstring, xbx, -1, NULL
  invoke MessageBoxA, $ObjTmpl(Application).hWnd, xax, $OfsCStrA("Lua Error"), MB_OK or MB_ICONSTOP
  invoke lua_settop, xbx, -2                            ;invoke lua_pop, xbx, 1 = Remove error message
  mov dRetVal, EXIT_FAILURE                             ;EXIT_FAILURE/EXIT_SUCCESS

@@:
  ;Inform the main Application that the script has finished and pass an result value 
  mov xax, [xsi].pOwner
  invoke PostMessage, [xax].$Obj(WinPrimer).hWnd, SEM_SCRIPT_FINISHED, dRetVal, [xsi].pScript
  .if [xsi].hThread != 0
    invoke CloseHandle, [xsi].hThread                   ;Decrement HANDLE count to release hThread
  .endif                                                ; when terminated
  invoke lua_close, xbx                                 ;Shutdown
  mov eax, dRetVal                                      ;Exit
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.FileLoad
; Purpose:    Load a file into the memory block.
; Arguments:  Arg1: -> WIDE FileName.
; Return:     xax -> MemBuffer or NULL if failed.

Method ScriptEngine.FileLoad, uses xbx xdi, pFileName:PSTRINGW
  local hFile:HANDLE, dBytesRead:DWORD

  ;Open the file
  xor ebx, ebx
  invoke CreateFileW, pFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, \
                      FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    ;Get a buffer to read in the file, with room to null-terminate
    mov hFile, xax
    invoke GetFileSize, xax, NULL
    .if eax != -1
      mov edi, eax
      inc eax                                           ;ZTC
      MemAlloc eax
      .if xax != NULL
        mov xbx, xax
        invoke ReadFile, hFile, xbx, edi, addr dBytesRead, 0
        .if eax == FALSE || dBytesRead != edi
          MemFree xbx
          xor ebx, ebx
        .else
          m2z BYTE ptr [xbx + xdi]                      ;Set ZTC
        .endif
      .endif
    .endif
    invoke CloseHandle, hFile
  .endif
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.Run
; Purpose:    Start synchronious script execution.
; Arguments:  Arg1: -> UTF8 stream containing the script to execute.
; Return:     eax = return value (Lua error code).

Method ScriptEngine.Run, uses xbx xsi, pScript:PSTRINGA
;  DbgText "ScriptEngine.Run"
  SetObject xsi
  m2m [xsi].pScript, pScript, xax
  OCall xsi.Execute
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.Start
; Purpose:    Start asynchronious script execution.
; Arguments:  Arg1: -> UTF8 stream containing the script to execute.
; Return:     eax = LUA_OK if succeeded, otherwise an LUA error code.

Method ScriptEngine.Start, uses xsi, pScript:PSTRINGA
  DbgText "ScriptEngine.Start"
  SetObject xsi
  m2m [xsi].pScript, pScript, xax
  invoke CreateThread, NULL, 0, $MethodAddr(xsi::ScriptEngine.Execute), xsi, CREATE_SUSPENDED, NULL
  .if xax != 0
    mov [xsi].hThread, xax
    mov [xsi].dFlags, 0                                 ;Reset all other flags
    invoke ResumeThread, xax
    mov eax, LUA_OK
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.Stop
; Purpose:    Stop script execution.
; Arguments:  None.
; Return:     Nothing.

Method ScriptEngine.Stop
  DbgText "ScriptEngine.Stop"
  SetObject xcx
  BitSet [xcx].dFlags, SEF_SCRIPT_STOP
MethodEnd


