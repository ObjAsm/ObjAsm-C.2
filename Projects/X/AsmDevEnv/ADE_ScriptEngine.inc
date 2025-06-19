; ==================================================================================================
; Title:      ADE_ScriptEngine.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of project window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



; ==================================================================================================
; ScriptEngine implementation
; ==================================================================================================

.code

; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.ScriptInit
; Purpose:    Script custom initialization.
; Arguments:  Arg1: -> lua_State.
; Return:     eax = LUA_OK if succeeded, otherwise an error code.

Method ScriptEngine.ScriptInit,, plua_State:Plua_State
  DbgText "ScriptEngine.ScriptInit"

  ;Create the Output object (table)
  invoke lua_createtable, plua_State, 0, 0
  invoke lua_pushstring, plua_State, $OfsCStrA("Write")
  invoke lua_pushcclosure, plua_State, addr EditorLineWrite, 0
  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("Delete")
;  invoke lua_pushcclosure, plua_State, addr EditorLineDelete, 0
;  invoke lua_settable, plua_State, -3
  invoke lua_setglobal, plua_State, $OfsCStrA("EditorLine")

  invoke lua_createtable, plua_State, 0, 0
  invoke lua_pushstring, plua_State, $OfsCStrA("OpenEditor")
  invoke lua_pushcclosure, plua_State, addr ApplicationOpenEditor, 0
  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("CloseEditor")
;  invoke lua_pushcclosure, plua_State, addr ApplicationCloseEditor, 0
;  invoke lua_settable, plua_State, -3
  invoke lua_setglobal, plua_State, $OfsCStrA("Application")
;
;  invoke lua_createtable, plua_State, 0, 0
;  invoke lua_pushstring, plua_State, $OfsCStrA("GetCaretPos")
;  invoke lua_pushcclosure, plua_State, addr EditorGetCaretPos, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("SetCaretPos")
;  invoke lua_pushcclosure, plua_State, addr EditorSetCaretPos, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("GetLine")
;  invoke lua_pushcclosure, plua_State, addr EditorGetLine, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("Close")
;  invoke lua_pushcclosure, plua_State, addr EditorClose, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("Find")
;  invoke lua_pushcclosure, plua_State, addr EditorFind, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("Save")
;  invoke lua_pushcclosure, plua_State, addr EditorSave, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_pushstring, plua_State, $OfsCStrA("SaveAs")
;  invoke lua_pushcclosure, plua_State, addr EditorSaveAs, 0
;  invoke lua_settable, plua_State, -3
;  invoke lua_setglobal, plua_State, $OfsCStrA("Editor")

  mov eax, LUA_OK
MethodEnd


; --------------------------------------------------------------------------------------------------
; Method:     ApplicationOpenEditor
; Purpose:    Open a specific Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.

ApplicationOpenEditor proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dChars:DWORD

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str

  ret
ApplicationOpenEditor endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorLineWrite
; Purpose:    Writes a string on the Output RichEdit control.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.

EditorLineWrite proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dChars:DWORD

  invoke lua_getglobal, pLuaState, $OfsCStrA("pScriptHost")  ;Retrieve -> ScriptHost
  invoke lua_tointegerx, pLuaState, -1, NULL
  mov xbx, [xax].$Obj(LuaHost).pOwner

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke MultiByteToWideChar, CP_UTF8, 0, xsi, -1, NULL, 0
  mov dChars, eax
  shl eax, 1
  MemAlloc eax
  .if xax != NULL
    mov pBuffer, xax
    invoke MultiByteToWideChar, CP_UTF8, 0, xsi, -1, pBuffer, dChars

    OCall xbx::Application.GetActiveEditor
    .if xax != NULL
      mov xdi, [xax].$Obj(Editor).pFocusedView 
      OCall xdi::EditorView.VertIndex2EditorLine, [xdi].$Obj(EditorView).CaretLocation.dLineIndex
      dec dChars                                        ;Discard ZTC
      OCall xax::EditorLine.CharInsert, 0, dChars, pBuffer, [xdi].$Obj(EditorView).CaretLocation.dLineIndex, 0
    .endif
    MemFree pBuffer
  .endif
  xor eax, eax                                          ;No arguments
  ret
EditorLineWrite endp
