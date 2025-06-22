; ==================================================================================================
; Title:      ADE_ScriptEngine.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; ScriptEngine implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     ScriptEngine.FileLoad
; Purpose:    Load a file into the memory block.
; Arguments:  Arg1: -> FileName.
; Return:     xax -> MemBuffer or NULL if failed.

Method ScriptEngine.FileLoad, uses xbx xdi, pFileName:PSTRING
  local hFile:HANDLE, dBytesRead:DWORD

  ;Open the file
  xor ebx, ebx
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, \
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
; Method:     ScriptEngine.ScriptInit
; Purpose:    Script custom initialization.
; Arguments:  Arg1: -> lua_State.
; Return:     eax = LUA_OK if succeeded, otherwise an error code.

LuaAddToTable macro ElementGroup, ElementName
  
  invoke lua_pushstring, plua_State, @CatStr(<$OfsCStrA(!">, ElementName, <!")>)
  invoke lua_pushcclosure, plua_State, @CatStr(<addr >, ElementGroup, ElementName), 0
  invoke lua_settable, plua_State, -3
endm


Method ScriptEngine.ScriptInit,, plua_State:Plua_State
;  DbgText "ScriptEngine.ScriptInit"

;  invoke lua_createtable, plua_State, 0, 0
;  LuaAddToTable EditorLine, Write
;  invoke lua_setglobal, plua_State, $OfsCStrA("EditorLine")

  invoke lua_createtable, plua_State, 0, 0
  LuaAddToTable Application, DbgPrint
  LuaAddToTable Application, DbgPrintLn
  LuaAddToTable Application, FreezeUI
  LuaAddToTable Application, MsgBox
  LuaAddToTable Application, NewEditor
  LuaAddToTable Application, UnfreezeUI
  invoke lua_setglobal, plua_State, $OfsCStrA("Application")

  invoke lua_createtable, plua_State, 0, 0
  LuaAddToTable Editor, Close
;  LuaAddToTable Editor, DelLine
;  LuaAddToTable Editor, GetCaretPos
;  LuaAddToTable Editor, GetLineAttr
  LuaAddToTable Editor, GetLineCount
  LuaAddToTable Editor, GetLineText
  LuaAddToTable Editor, Hide
;  LuaAddToTable Editor, HideCaret
  LuaAddToTable Editor, Maximize
  LuaAddToTable Editor, Minimize
;  LuaAddToTable Editor, NewLine
  LuaAddToTable Editor, Save
  LuaAddToTable Editor, SaveAs
  LuaAddToTable Editor, SaveTo
;  LuaAddToTable Editor, SetCaretPos
;  LuaAddToTable Editor, SetLineAttr
  LuaAddToTable Editor, Restore
  LuaAddToTable Editor, SetLineText
  LuaAddToTable Editor, Show
;  LuaAddToTable Editor, ShowCaret
  invoke lua_setglobal, plua_State, $OfsCStrA("Editor")

  mov eax, LUA_OK
MethodEnd


; ==================================================================================================
; Script Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ApplicationDbgPrint
; Purpose:    Echo a string to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.DbgPrint("Hello World")

ApplicationDbgPrint proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dSize:DWORD

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke UTF8ToWideSize, xsi
  mov dSize, eax
  MemAlloc eax
  .if xax != NULL
    mov pBuffer, xax
    invoke UTF8ToWide, pBuffer, xsi, dSize
    invoke luaL_checklstring, pLuaState, 2, NULL        ;Get second stack argument and check for str
    invoke DbgOutTextA, xax, $RGB(0,0,0), DbgColorBackground, DBG_EFFECT_NORMAL, pBuffer
    MemFree pBuffer
  .endif
  xor eax, eax
  ret
ApplicationDbgPrint endp

; --------------------------------------------------------------------------------------------------
; Method:     ApplicationDbgPrintLn
; Purpose:    Echo a string and a CRLF to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.DbgPrint("Hello World")

ApplicationDbgPrintLn proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dSize:DWORD

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke UTF8ToWideSize, xsi
  mov dSize, eax
  MemAlloc eax
  .if xax != NULL
    mov pBuffer, xax
    invoke UTF8ToWide, pBuffer, xsi, dSize
    invoke luaL_checklstring, pLuaState, 2, NULL        ;Get second stack argument and check for str
    invoke DbgOutTextA, xax, $RGB(0,0,0), DbgColorBackground, DBG_EFFECT_NEWLINE, pBuffer
    MemFree pBuffer
  .endif
  xor eax, eax
  ret
ApplicationDbgPrintLn endp

; --------------------------------------------------------------------------------------------------
; Method:     ApplicationFreezeUI
; Purpose:    Freeze the Application UI.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEditor = Application.NewEditor("MyFile.txt")

ApplicationFreezeUI proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke SendMessage, $ObjTmpl(Application).hWnd, WM_SETREDRAW, FALSE, 0
  xor eax, eax
  ret
ApplicationFreezeUI endp

; --------------------------------------------------------------------------------------------------
; Method:     ApplicationMsgBox
; Purpose:    Display a MessageBox with custom text and caption.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Result = Application.MsgBox("Repeat operation", "Question", MB_YESNOCANCEL)

ApplicationMsgBox proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke luaL_checklstring, pLuaState, 2, NULL          ;Get second stack argument and check for str
  mov xdi, xax
  invoke luaL_checkinteger, pLuaState, 3                ;Get first stack argument and check
  invoke MessageBoxA, $ObjTmpl(Application).hWnd, xsi, xdi, eax  
  invoke lua_pushinteger, pLuaState, eax                ;Return the MessageBox return value
  mov eax, 1
  ret
ApplicationMsgBox endp

; --------------------------------------------------------------------------------------------------
; Method:     ApplicationNewEditor
; Purpose:    Creates a new Editor or opens a running instance.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEditor = Application.NewEditor("MyFile.txt")

ApplicationNewEditor proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dSize:DWORD

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke UTF8ToWideSize, xsi
  mov dSize, eax
  MemAlloc eax
  .if xax != NULL
    mov pBuffer, xax
    invoke UTF8ToWide, pBuffer, xsi, dSize
    OCall $ObjTmpl(Application)::Application.LaunchEditor, pBuffer, SW_HIDE
    .if xax != NULL
      mov xax, [xax].$Obj(Editor).hWnd
    .endif
  .endif
  invoke lua_pushinteger, pLuaState, xax                ;Return the Editor window HANDLE
  mov eax, 1
  ret
ApplicationNewEditor endp

; --------------------------------------------------------------------------------------------------
; Method:     ApplicationUnfreezeUI
; Purpose:    Unfreeze the application UI.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEditor = Application.NewEditor("MyFile.txt")

ApplicationUnfreezeUI proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke SendMessage, $ObjTmpl(Application).hWnd, WM_SETREDRAW, TRUE, 0
  xor eax, eax
  ret
ApplicationUnfreezeUI endp



; ==================================================================================================
; Script Editor implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     EditorClose
; Purpose:    Close the Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Close(hEditor)
; Note:       No saving is performed.

EditorClose proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke SendMessage, xax, WM_CLOSE, 0, 0 
  .endif
  xor eax, eax
  ret
EditorClose endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorGetLineCount
; Purpose:    Retrieve the number of lines in this Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   LineCount = Editor.GetLineCount(hEditor)

EditorGetLineCount proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov eax, [xax].$Obj(Editor).Lines.dCount
    .endif
  .endif
  invoke lua_pushinteger, pLuaState, eax
  mov eax, 1
  ret
EditorGetLineCount endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorGetLineText
; Purpose:    Retrieve the text content of a specific line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   sLineBuffer = Editor.GetLineText(hEditor, dLineNumber)

EditorGetLineText proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dSize:DWORD, hEditor:HWND, dLineNumber:DWORD, pEditor:$ObjPtr(Editor)

  mov dSize, 0
  mov pBuffer, NULL
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    mov hEditor, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check
    mov dLineNumber, eax

    invoke SendMessage, hEditor, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov pEditor, xax
      mov xcx, xax
      xor eax, eax
      mov edx, dLineNumber
      dec edx
      .if edx < [xcx].$Obj(Editor).Lines.dCount
        OCall [xcx].$Obj(Editor).Lines::Collection.ItemAt, edx 
        .if xax != NULL
          mov xbx, xax
          invoke WideToUTF8Size, [xbx].$Obj(EditorLine).pBuffer
          mov dSize, eax                                ;dSize includes the space for the ZTC
          MemAlloc eax
          .if xax != NULL
            mov pBuffer, xax
            invoke WideToUTF8, pBuffer, [xbx].$Obj(EditorLine).pBuffer, dSize
            mov eax, dSize 
            dec eax
          .endif
        .endif
      .endif
    .endif  
  .endif
  invoke lua_pushlstring, pLuaState, pBuffer, eax       ;Lua makes an internal copy
  MemFree pBuffer                                       ;This buffer can be disposed now
  mov eax, 1
  ret
EditorGetLineText endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorHide
; Purpose:    Hide the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Hide(hEditor)

EditorHide proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke ShowWindow, xax, SW_HIDE
  .endif
  xor eax, eax
  ret
EditorHide endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorMaximize
; Purpose:    Maximize the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Maximize(hEditor)

EditorMaximize proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke ShowWindow, xax, SW_MAXIMIZE
  .endif
  xor eax, eax
  ret
EditorMaximize endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorMinimize
; Purpose:    Minimize the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Minimize(hEditor)

EditorMinimize proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke ShowWindow, xax, SW_MINIMIZE
  .endif
  xor eax, eax
  ret
EditorMinimize endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorRestore
; Purpose:    Restore the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Restore(hEditor)

EditorRestore proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke ShowWindow, xax, SW_RESTORE
  .endif
  xor eax, eax
  ret
EditorRestore endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorSave
; Purpose:    Save the Editor content.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSave proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::Editor.Save
    .endif
  .endif
  xor eax, eax
  ret
EditorSave endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorSaveAs
; Purpose:    Save the Editor content to a file.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSaveAs proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::Editor.SaveAs
    .endif
  .endif
  xor eax, eax
  ret
EditorSaveAs endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorSaveTo
; Purpose:    Save the Editor content to a file.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSaveTo proc uses xbx xdi xsi pLuaState:ptr lua_State
  local hEditor:HWND, dSize:DWORD, pBuffer:POINTER

  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    mov hEditor, xax
    invoke luaL_checklstring, pLuaState, 2, NULL        ;Get second stack argument and check
    mov xbx, xax
    invoke UTF8ToWideSize, xbx
    mov dSize, eax
    MemAlloc eax
    .if xax != NULL
      mov pBuffer, xax
      invoke UTF8ToWide, pBuffer, xbx, dSize
      invoke SendMessage, hEditor, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        OCall xax::Editor.SaveTo, pBuffer
      .endif
      MemFree pBuffer
    .endif
  .endif
  xor eax, eax
  ret
EditorSaveTo endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorSetLineText
; Purpose:    Set the text content of a specific line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   sLineBuffer = Editor.GetLineText(hEditor, dLineNumber)

EditorSetLineText proc uses xbx xdi xsi pLuaState:ptr lua_State
  local pBuffer:POINTER, dSize:DWORD, hEditor:HWND, dLineNumber:DWORD, pEditor:$ObjPtr(Editor)
  local dActionGroup:DWORD

  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    mov hEditor, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check
    mov dLineNumber, eax
    invoke luaL_checklstring, pLuaState, 3, NULL        ;Get third stack argument and check
    mov xbx, xax
    invoke UTF8ToWideSize, xbx
    mov dSize, eax
    MemAlloc eax
    .if xax != NULL
      mov pBuffer, xax
      invoke UTF8ToWide, pBuffer, xbx, dSize
      invoke SendMessage, hEditor, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov pEditor, xax
        mov edi, dLineNumber
        dec edi
        .if edi < [xax].$Obj(Editor).Lines.dCount
          OCall [xax].$Obj(Editor).Lines::Collection.ItemAt, edi 
          .if xax != NULL
            mov xbx, xax
            mov xax, pEditor
            mov dActionGroup, $32($OCall([xax].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
            OCall xbx::EditorLine.CharDelete, 0, -1, edi, dActionGroup
            mov eax, dSize
            shr eax, 1                                  ;Convert to chars
            dec eax                                     ;Remove the ZTC
            OCall xbx::EditorLine.CharInsert, 0, eax, pBuffer, edi, dActionGroup
          .endif
        .endif
        OCall pEditor::Editor.ManageEditCmds
      .endif
      MemFree pBuffer
    .endif  
  .endif
  xor eax, eax
  ret
EditorSetLineText endp

; --------------------------------------------------------------------------------------------------
; Method:     EditorShow
; Purpose:    Display the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Show(hEditor)

EditorShow proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check
  .if xax != 0
    invoke ShowWindow, xax, SW_SHOW
  .endif
  xor eax, eax
  ret
EditorShow endp



















;; --------------------------------------------------------------------------------------------------
;; Method:     EditorLineWrite
;; Purpose:    Writes a string on the Output RichEdit control.
;; Arguments:  Arg1: -> lua_State
;; Return:     eax = Number of arguments returned on the lua stack.
;
;EditorLineWrite proc uses xdi xsi pLuaState:ptr lua_State
;  local pBuffer:POINTER, dSize:DWORD
;
;  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
;  mov xsi, xax
;  invoke UTF8ToWideSize, xsi
;  mov dSize, eax
;  MemAlloc eax
;  .if xax != NULL
;    mov pBuffer, xax
;    invoke UTF8ToWide, pBuffer, xsi, dSize
;    OCall $ObjTmpl(Application)::Application.GetActiveEditor
;    .if xax != NULL
;      mov xdi, [xax].$Obj(Editor).pFocusedView
;      OCall xdi::EditorView.VertIndex2EditorLine, [xdi].$Obj(EditorView).CaretLocation.dLineIndex
;      shr dSize, 1
;      dec dSize
;      OCall xax::EditorLine.CharInsert, 0, dSize, pBuffer, [xdi].$Obj(EditorView).CaretLocation.dLineIndex, 0
;    .endif
;    MemFree pBuffer
;  .endif
;  xor eax, eax                                          ;No arguments
;  ret
;EditorLineWrite endp
;
