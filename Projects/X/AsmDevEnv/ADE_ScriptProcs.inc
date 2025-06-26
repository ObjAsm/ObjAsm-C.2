; ==================================================================================================
; Title:      ADE_ScriptProcs.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; Script Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationDbgPrint
; Purpose:    Echo a string to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.DbgPrint("Hello World")

ApplicationDbgPrint proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke UTF8ToWideSize, xsi
  mov edi, eax
  MemAlloc eax
  .if xax != NULL
    mov xbx, xax
    invoke UTF8ToWide, xbx, xsi, edi
    invoke luaL_checklstring, pLuaState, 2, NULL        ;Get second stack argument and check for str
    invoke DbgOutTextA, xax, $RGB(0,0,0), DbgColorBackground, DBG_EFFECT_NORMAL, xbx
    MemFree xbx
  .endif
  xor eax, eax
  ret
ApplicationDbgPrint endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationDbgPrintLn
; Purpose:    Echo a string and a CRLF to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.DbgPrint("Hello World")

ApplicationDbgPrintLn proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke UTF8ToWideSize, xsi
  mov edi, eax
  MemAlloc eax
  .if xax != NULL
    mov xbx, xax
    invoke UTF8ToWide, xbx, xsi, edi
    invoke luaL_checklstring, pLuaState, 2, NULL        ;Get second stack argument and check for str
    invoke DbgOutTextA, xax, $RGB(0,0,0), DbgColorBackground, DBG_EFFECT_NEWLINE, xbx
    MemFree xbx
  .endif
  xor eax, eax
  ret
ApplicationDbgPrintLn endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationFreezeUI
; Purpose:    Freeze the Application UI.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEditor = Application.NewEditor("MyFile.txt")

ApplicationFreezeUI proc pLuaState:ptr lua_State
  ANNOTATION: use pLuaState
  invoke SendMessage, $ObjTmpl(Application).hWnd, WM_SETREDRAW, FALSE, 0
  xor eax, eax
  ret
ApplicationFreezeUI endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationInpBox
; Purpose:    Display a Input Box with custom text and caption.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Result = Application.MsgBox("Repeat operation", "Question", MB_YESNOCANCEL)

ApplicationInpBox proc uses xdi xsi pLuaState:ptr lua_State
  local InpDlg:$Obj(SimpleInputDialog)

  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke luaL_checklstring, pLuaState, 2, NULL          ;Get second stack argument and check for str
  mov xdi, xax
  New InpDlg::SimpleInputDialog
  OCall InpDlg::SimpleInputDialog.Init, addr $ObjTmpl(Application), $ObjTmpl(Application).hWnd, xsi, xdi
  OCall InpDlg::SimpleInputDialog.Show
  .if eax == IDCANCEL
    invoke lua_pushlstring, pLuaState, NULL, 0          ;Return nothing
  .else
    invoke StrLengthA, InpDlg.pResult
    invoke lua_pushlstring, pLuaState, InpDlg.pResult, eax  ;Return the MessageBox return value
  .endif
  OCall InpDlg::SimpleInputDialog.Done
  mov eax, 1
  ret
ApplicationInpBox endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationMsgBox
; Purpose:    Display a Message Box with custom text and caption.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Result = Application.MsgBox("Repeat operation", "Question", MB_YESNOCANCEL)

ApplicationMsgBox proc uses xdi xsi pLuaState:ptr lua_State
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke luaL_checklstring, pLuaState, 2, NULL          ;Get second stack argument and check for str
  mov xdi, xax
  invoke luaL_checkinteger, pLuaState, 3                ;Get third stack argument and check
  invoke MessageBoxA, $ObjTmpl(Application).hWnd, xsi, xdi, eax  
  invoke lua_pushinteger, pLuaState, eax                ;Return the MessageBox return value
  mov eax, 1
  ret
ApplicationMsgBox endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationNewEditor
; Purpose:    Creates a new Editor or opens a running instance.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEditor = Application.NewEditor("MyFile.txt")

ApplicationNewEditor proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checklstring, pLuaState, 1, NULL          ;Get first stack argument and check for str
  mov xsi, xax
  invoke UTF8ToWideSize, xsi
  mov edi, eax
  MemAlloc eax
  .if xax != NULL
    mov xbx, xax
    invoke UTF8ToWide, xbx, xsi, edi
    OCall $ObjTmpl(Application)::Application.LaunchEditor, xbx, SW_HIDE
    .if xax != NULL
      mov xax, [xax].$Obj(Editor).hWnd
    .endif
  .endif
  invoke lua_pushinteger, pLuaState, xax                ;Return the Editor window HANDLE
  mov eax, 1
  ret
ApplicationNewEditor endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationUnfreezeUI
; Purpose:    Unfreeze the application UI.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEditor = Application.NewEditor("MyFile.txt")

ApplicationUnfreezeUI proc pLuaState:ptr lua_State
  ANNOTATION: use pLuaState
  invoke SendMessage, $ObjTmpl(Application).hWnd, WM_SETREDRAW, TRUE, 0
  xor eax, eax
  ret
ApplicationUnfreezeUI endp



; ==================================================================================================
; Script Editor implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorClose
; Purpose:    Close the Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Close(hEditor)
; Note:       No saving is performed.

EditorClose proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_CLOSE, 0, 0 
  .endif
  xor eax, eax
  ret
EditorClose endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetLineAttr
; Purpose:    Retrieve the attributes of a specific Editor line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Attr = Editor.GetLineAttr(hEditor, dLineNumber)

EditorGetLineAttr proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke luaL_checkinteger, pLuaState, 2            ;Get second stack argument and check for int
      dec eax
      .if eax < [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, eax 
        .if xax != NULL
          mov eax, [xax].$Obj(EditorLine).dFlags
        .endif
      .else
        xor eax, eax
      .endif
    .endif
  .endif
  invoke lua_pushinteger, pLuaState, eax
  mov eax, 1
  ret
EditorGetLineAttr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetLineCount
; Purpose:    Retrieve the number of lines in this Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   LineCount = Editor.GetLineCount(hEditor)

EditorGetLineCount proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
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
; Procedure:  EditorGetLineText
; Purpose:    Retrieve the text content of a specific line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   sLineBuffer = Editor.GetLineText(hEditor, dLineNumber)

EditorGetLineText proc uses xbx xdi xsi pLuaState:ptr lua_State
  xor esi, esi
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke luaL_checkinteger, pLuaState, 2            ;Get second stack argument and check for int
      lea edx, [eax - 1]
      xor eax, eax
      .if edx < [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx 
        .if xax != NULL
          mov xbx, xax
          invoke WideToUTF8Size, [xbx].$Obj(EditorLine).pBuffer
          mov edi, eax                                  ;edi includes the space for the ZTC
          MemAlloc eax
          .if xax != NULL
            mov xsi, xax
            invoke WideToUTF8, xsi, [xbx].$Obj(EditorLine).pBuffer, edi
            lea eax, [edi - 1]                          ;Remove ZTC count
          .endif
        .endif
      .endif
    .endif  
  .endif
  invoke lua_pushlstring, pLuaState, xsi, eax           ;Lua makes an internal copy
  .if xsi != NULL
    MemFree xsi                                         ;This buffer can be disposed now
  .endif
  mov eax, 1
  ret
EditorGetLineText endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorHide
; Purpose:    Hide the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Hide(hEditor)

EditorHide proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke ShowWindow, xax, SW_HIDE
  .endif
  xor eax, eax
  ret
EditorHide endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorMaximize
; Purpose:    Maximize the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Maximize(hEditor)

EditorMaximize proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke ShowWindow, xax, SW_MAXIMIZE
  .endif
  xor eax, eax
  ret
EditorMaximize endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorMinimize
; Purpose:    Minimize the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Minimize(hEditor)

EditorMinimize proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke ShowWindow, xax, SW_MINIMIZE
  .endif
  xor eax, eax
  ret
EditorMinimize endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorDelLine
; Purpose:    Delete an exiting editor line. 
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.DelLine(hEditor, dLineNumber)

EditorDelLine proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    mov xsi, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check for int
    lea edi, [eax - 1]                                  ;edi = LineIndex

    invoke SendMessage, xsi, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      .if edi < [xax].$Obj(Editor).Lines.dCount
        mov xbx, xax
        mov xsi, $OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup)
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi
        OCall xax::EditorLine.LineDelete, edi, esi
        .if xax != NULL 
          OCall xbx::Editor.InformDeletionOf, edi
          OCall xbx::Editor.ManageEditCmds
        .endif
      .endif
    .endif  
  .endif
  xor eax, eax
  ret
EditorDelLine endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorNewLine
; Purpose:    Insert a new editor line. 
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.NewLine(hEditor, dLineNumber)

EditorNewLine proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    mov xsi, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check for int
    lea edi, [eax - 1]                                  ;edi = LineIndex

    invoke SendMessage, xsi, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      .if edi <= [xax].$Obj(Editor).Lines.dCount
        mov xbx, xax
        OCall [xax].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup
        OCall xbx::Editor.LineNew, 0, edi, eax
        .if xax != NULL 
          OCall xax::EditorLine.SetDirty
          OCall xbx::Editor.InformInsertionOf, edi
          OCall xbx::Editor.ManageEditCmds
        .endif
      .endif
    .endif  
  .endif
  xor eax, eax
  ret
EditorNewLine endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorRestore
; Purpose:    Restore the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Restore(hEditor)

EditorRestore proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke ShowWindow, xax, SW_RESTORE
  .endif
  xor eax, eax
  ret
EditorRestore endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSave
; Purpose:    Save the Editor content.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSave proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
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
; Procedure:  EditorSaveAs
; Purpose:    Save the Editor content to a file.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSaveAs proc uses pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
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
; Procedure:  EditorSaveTo
; Purpose:    Save the Editor content to a file.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSaveTo proc uses xbx xdi xsi pLuaState:ptr lua_State
  local hEditor:HWND

  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    mov hEditor, xax
    invoke luaL_checklstring, pLuaState, 2, NULL        ;Get second stack argument and check for str
    mov xbx, xax
    invoke UTF8ToWideSize, xbx
    mov edi, eax
    MemAlloc eax
    .if xax != NULL
      mov xsi, xax
      invoke UTF8ToWide, xsi, xbx, edi
      invoke SendMessage, hEditor, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        OCall xax::Editor.SaveTo, xsi
      .endif
      MemFree xsi
    .endif
  .endif
  xor eax, eax
  ret
EditorSaveTo endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSetLineAttr
; Purpose:    Set the attributes of a specific Editor line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Attr = Editor.GetLineAttr(hEditor, dLineNumber)

EditorSetLineAttr proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke luaL_checkinteger, pLuaState, 2            ;Get second stack argument and check for int
      dec eax
      .if eax < [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, eax 
        .if xax != NULL
          mov xbx, xax
          invoke luaL_checkinteger, pLuaState, 3        ;Get third stack argument and check for int
          mov [xbx].$Obj(EditorLine).dFlags, eax
        .endif
      .endif
    .endif
  .endif
  xor eax, eax
  ret
EditorSetLineAttr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSetLineText
; Purpose:    Set the text content of a specific line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   sLineBuffer = Editor.GetLineText(hEditor, dLineNumber)

EditorSetLineText proc uses xbx xdi xsi pLuaState:ptr lua_State
  local dSize:DWORD, hEditor:HWND, pEditor:$ObjPtr(Editor), dActionGroup:DWORD

  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    mov hEditor, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check for int
    lea edi, [eax - 1]
    invoke luaL_checklstring, pLuaState, 3, NULL        ;Get third stack argument and check for str
    mov xbx, xax
    invoke UTF8ToWideSize, xbx
    mov dSize, eax
    MemAlloc eax
    .if xax != NULL
      mov xsi, xax
      invoke UTF8ToWide, xsi, xbx, dSize
      invoke SendMessage, hEditor, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov pEditor, xax
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
            OCall xbx::EditorLine.CharInsert, 0, eax, xsi, edi, dActionGroup
          .endif
        .endif
        OCall pEditor::Editor.ManageEditCmds
      .endif
      MemFree xsi
    .endif  
  .endif
  xor eax, eax
  ret
EditorSetLineText endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorShow
; Purpose:    Display the Editor window.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Show(hEditor)

EditorShow proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke ShowWindow, xax, SW_SHOW
  .endif
  xor eax, eax
  ret
EditorShow endp
