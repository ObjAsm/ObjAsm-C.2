; ==================================================================================================
; Title:      ADE_ScriptProcs.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; Script Application implementation
; ==================================================================================================

CStrA szOutOfMemory,          "Out of memory"
CStrA szInvalidEditorHandle,  "Invalid editor handle"
CStrA szInvalidLineNumber,    "Invalid line number = %d"
CStrA szInvalidCharIndex,     "Invalid character index = %d"
CStrA szInvalidDisplayIndex,  "Invalid display index = %d"

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationDbgPrint
; Purpose:    Echo a string to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.DbgPrint("Output", "Hello World")

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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szOutOfMemory      ;This proc does not return
ApplicationDbgPrint endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationDbgPrintLn
; Purpose:    Echo a string and a CRLF to DebugCenter.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.DbgPrint("Output", "Hello World")

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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szOutOfMemory      ;This proc does not return
ApplicationDbgPrintLn endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationFreezeUI
; Purpose:    Freeze the Application UI.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.FreezeUI()

ApplicationFreezeUI proc pLuaState:ptr lua_State
  ANNOTATION: use pLuaState
  invoke SendMessage, $ObjTmpl(Application).hWnd, WM_SETREDRAW, FALSE, 0
  xor eax, eax
  ret
ApplicationFreezeUI endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationGetActiveEditor
; Purpose:    Return the current active Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   hEdit = Application.GetActiveEditor()  --nil if no active editor

ApplicationGetActiveEditor proc pLuaState:ptr lua_State
  OCall $ObjTmpl(Application)::Application.GetActiveEditor
  .if xax != NULL
    invoke lua_pushinteger, pLuaState, [xax].$Obj(Editor).hWnd   ;Return the Editor window HANDLE
  .else
    invoke lua_pushnil, pLuaState
  .endif
  mov eax, 1
  ret
ApplicationGetActiveEditor endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationInpBox
; Purpose:    Display a Input Box with custom text and caption.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Result = Application.InpBox("Repeat operation", "Question")

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
; Lua call:   Result = Application.MsgBox("Repeat operation", "Question", 3)
; Note:       Frequent used flags:
;             MB_OK                = 00000000h
;             MB_OKCANCEL          = 00000001h
;             MB_ABORTRETRYIGNORE  = 00000002h
;             MB_YESNOCANCEL       = 00000003h
;             MB_YESNO             = 00000004h
;             MB_RETRYCANCEL       = 00000005h
;             MB_CANCELTRYCONTINUE = 00000006h
;             MB_ICONHAND          = 00000010h
;             MB_ICONQUESTION      = 00000020h
;             MB_ICONEXCLAMATION   = 00000030h
;             MB_ICONASTERISK      = 00000040h

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
; Note:       If the method fails, it returns 0.

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
    invoke lua_pushinteger, pLuaState, xax              ;Return the Editor window HANDLE
    MemFree xbx
    mov eax, 1
    ret
  .endif
  invoke luaL_error, pLuaState, addr szOutOfMemory      ;This proc does not return
ApplicationNewEditor endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ApplicationUnfreezeUI
; Purpose:    Unfreeze the application UI.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Application.UnfreezeUI()

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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorClose endp

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
          xor eax, eax
          ret
        .endif
      .endif
      inc edi
      lea xdx, szInvalidLineNumber
      invoke luaL_error, pLuaState, xdx, edi            ;This proc does not return
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorDelLine endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetCaretPos
; Purpose:    Get editor caret position.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   CharIndex, LineNumber = Editor.GetCaretPos(hEditor)

EditorGetCaretPos proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, [xax].$Obj(Editor).pFocusedView
      .if xbx != NULL
        invoke lua_pushinteger, pLuaState, [xbx].$Obj(EditorView).CaretLocation.dCharIndex
        mov eax, [xbx].$Obj(EditorView).CaretLocation.dCharIndex
        inc eax
        invoke lua_pushinteger, pLuaState, eax
      .else
        invoke lua_pushnil, pLuaState
        invoke lua_pushnil, pLuaState
      .endif
      mov eax, 2
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetCaretPos endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetDisplayCount
; Purpose:    Retrieve the current Display Location. 
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   DisplayCount = Editor.GetDisplayCount(hEditor)

EditorGetDisplayCount proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      invoke lua_pushinteger, pLuaState, [xax].$Obj(Editor).Displays.dCount
      mov eax, 1
      ret
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetDisplayCount endp

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
        mov eax, [xax].$Obj(EditorLine).dFlags
        invoke lua_pushinteger, pLuaState, eax
        mov eax, 1
        ret
      .endif
      inc eax
      lea xdx, szInvalidLineNumber
      invoke luaL_error, pLuaState, xdx, eax            ;This proc does not return
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
      invoke lua_pushinteger, pLuaState, eax
      mov eax, 1
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetLineCount endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetLineSelRange
; Purpose:    Retrieve the selected line range in this Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   BegIndex,EndIndex = Editor.GetLineSelRange(hEditor, LineNumber)

EditorGetLineSelRange proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke luaL_checkinteger, pLuaState, 2            ;Get second stack argument and check for int
      lea edx, [eax - 1]
      .if edx < [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
      if TARGET_BITNESS eq 32
        mov ebx, [xax].$Obj(EditorLine).Selection.dEndIndex
        mov eax, [xax].$Obj(EditorLine).Selection.dBegIndex
      else
        movsxd rbx, [xax].$Obj(EditorLine).Selection.dEndIndex
        movsxd rax, [xax].$Obj(EditorLine).Selection.dBegIndex
      endif
        invoke lua_pushinteger, pLuaState, xax
        invoke lua_pushinteger, pLuaState, xbx
        mov eax, 2
        ret
      .endif
      lea xdx, szInvalidLineNumber
      invoke luaL_error, pLuaState, xdx, eax            ;This proc does not return
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetLineSelRange endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetLineText
; Purpose:    Retrieve the text content of a specific line.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   sLineBuffer = Editor.GetLineText(hEditor, dLineNumber)

EditorGetLineText proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke luaL_checkinteger, pLuaState, 2            ;Get second stack argument and check for int
      lea edx, [eax - 1]
      .if edx < [xbx].$Obj(Editor).Lines.dCount
        OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx 
        mov xbx, xax
        mov xcx, [xbx].$Obj(EditorLine).pBuffer
        .if xcx == NULL
          invoke lua_pushlstring, pLuaState, NULL, 0
          mov eax, 1
          ret
        .else
          invoke WideToUTF8Size, xcx
          mov edi, eax                                    ;edi includes the space for the ZTC
          MemAlloc eax
          .if xax != NULL
            mov xsi, xax
            invoke WideToUTF8, xsi, [xbx].$Obj(EditorLine).pBuffer, edi
            lea eax, [edi - 1]                            ;Remove ZTC count
            invoke lua_pushlstring, pLuaState, xsi, eax   ;Lua makes an internal copy
            MemFree xsi                                   ;This buffer can be disposed now
            mov eax, 1
            ret
          .endif
          invoke luaL_error, pLuaState, addr szOutOfMemory;This proc does not return
        .endif
      .endif
      lea xdx, szInvalidLineNumber
      invoke luaL_error, pLuaState, xdx, eax            ;This proc does not return
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetLineText endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetSelLineRange
; Purpose:    Retrieve the selected line number range in this Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   dFirstLineNumber,dLastLineNumber = Editor.GetSelLineRange(hEditor)
;             if nothing is selected, it returns 0,0.

EditorGetSelLineRange proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xcx, [xax].$Obj(Editor).SelectionRange.pBegSelInfo
      mov xdx, [xax].$Obj(Editor).SelectionRange.pEndSelInfo
      .if xcx != NULL && xdx != NULL
        mov eax, [xcx].LOCATION.dLineIndex
        mov ebx, [xdx].LOCATION.dLineIndex
        inc eax
        inc ebx
      .else
        xor eax, eax
        xor ebx, ebx
      .endif
      invoke lua_pushinteger, pLuaState, eax
      invoke lua_pushinteger, pLuaState, ebx
      mov eax, 2
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetSelLineRange endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorGetViewLocation
; Purpose:    Retrieve the current Display Location. 
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   CharIndex, LineNumber = Editor.GetViewLocation(hEditor, DisplayIndex)

EditorGetViewLocation proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    mov xsi, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check for int
    mov edi, eax                                        ;edi = View Index
    invoke SendMessage, xsi, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      .if edi < [xax].$Obj(Editor).Displays.dCount
        OCall [xax].$Obj(Editor).Displays::Collection.ItemAt, edi
        mov edx, [xax].$Obj(EditorDisplay).View.FirstVisChar.dCharIndex
        mov ebx, [xax].$Obj(EditorDisplay).View.FirstVisChar.dLineIndex
        invoke lua_pushinteger, pLuaState, edx
        invoke lua_pushinteger, pLuaState, ebx
        mov eax, 2
        ret
      .endif
      lea xdx, szInvalidDisplayIndex
      invoke luaL_error, pLuaState, xdx, edi            ;This proc does not return
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorGetViewLocation endp

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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorHide endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorHideCaret
; Purpose:    Hide the editor caret.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.HideCaret(hEditor)

EditorHideCaret proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xcx, [xax].$Obj(Editor).pFocusedView
      .if xcx != NULL
        OCall xcx::EditorView.CaretHide
      .endif
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorHideCaret endp

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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorMinimize endp

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
          xor eax, eax
          ret
        .endif
      .endif
      inc edi
      lea xdx, szInvalidLineNumber
      invoke luaL_error, pLuaState, xdx, edi            ;This proc does not return
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorSave endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSaveAs
; Purpose:    Save the Editor content to a file.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.Save(hEditor)
; Note:       No asking if it should replace the file.

EditorSaveAs proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::Editor.SaveAs
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
        MemFree xsi
        xor eax, eax
        ret
      .endif
      MemFree xsi
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorSaveTo endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSelSet
; Purpose:    Set selection in this Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.SelSet(hEditor, dCharIndex1, dLineNumber1, dCharIndex2, dLineNumber2)

EditorSelSet proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      OCall xbx::Editor.SelectionResetLines             ;Reset selection
      ;Make a full line selection
      invoke luaL_checkinteger, pLuaState, 2            ;Get second stack argument and check for int
      mov [xbx].$Obj(Editor).SelectionFst.dCharIndex, eax
      invoke luaL_checkinteger, pLuaState, 3            ;Get third stack argument and check for int
      dec eax
      mov [xbx].$Obj(Editor).SelectionFst.dLineIndex, eax
      invoke luaL_checkinteger, pLuaState, 4            ;Get fourth stack argument and check for int
      mov [xbx].$Obj(Editor).SelectionLst.dCharIndex, eax
      invoke luaL_checkinteger, pLuaState, 5            ;Get fifth stack argument and check for int
      dec eax
      mov [xbx].$Obj(Editor).SelectionLst.dLineIndex, eax
      OCall xbx::Editor.SelectionSet
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorSelSet endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSelReset
; Purpose:    Reset selection in this Editor.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.SelReset(hEditor)

EditorSelReset proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::Editor.SelectionResetAll
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorSelReset endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSetCaretPos
; Purpose:    Set editor caret position.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.SetCaretPos(hEditor, x, y)

EditorSetCaretPos proc uses xbx pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, [xax].$Obj(Editor).pFocusedView
      .if xbx != NULL
        invoke luaL_checkinteger, pLuaState, 2          ;Get second stack argument and check for int
        mov [xbx].$Obj(EditorView).CaretLocation.dCharIndex, eax
        invoke luaL_checkinteger, pLuaState, 3          ;Get third stack argument and check for int
        dec eax
        mov [xbx].$Obj(EditorView).CaretLocation.dLineIndex, eax
        OCall xbx::EditorView.CaretSet
      .endif
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorSetCaretPos endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorSetViewLocation
; Purpose:    Set the Display Location. 
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.SetViewLocation(hEditor, DisplayIndex, CharIndex, LineNumber)

EditorSetViewLocation proc uses xbx xdi xsi pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    mov xsi, xax
    invoke luaL_checkinteger, pLuaState, 2              ;Get second stack argument and check for int
    mov edi, eax                                        ;edi = View Index
    invoke SendMessage, xsi, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xsi, xax                                      ;xsi -> Editor
      .if edi < [xax].$Obj(Editor).Displays.dCount
        OCall [xax].$Obj(Editor).Displays::Collection.ItemAt, edi
        mov xdi, xax                                    ;xdi -> EditorDisplay
        invoke luaL_checkinteger, pLuaState, 3          ;Get third stack argument and check for int
        .if eax >= 0
          mov ebx, eax                                  ;ebx = CharIndex
          invoke luaL_checkinteger, pLuaState, 4        ;Get fourth stack argument and check for int
          dec eax
          .if eax < [xsi].$Obj(Editor).Lines.dCount
            .if eax < [xdi].$Obj(EditorDisplay).View.FirstVisChar.dLineIndex
              mov edx, [xdi].$Obj(EditorDisplay).View.FirstVisChar.dLineIndex
              sub edx, eax
              OCall [xdi].$Obj(EditorDisplay).View::EditorView.ScrollVisPageUp, edx
            .elseif eax > [xdi].$Obj(EditorDisplay).View.FirstVisChar.dLineIndex
              mov edx, eax
              sub edx, [xdi].$Obj(EditorDisplay).View.FirstVisChar.dLineIndex
              OCall [xdi].$Obj(EditorDisplay).View::EditorView.ScrollVisPageDown, edx
            .endif
            .if ebx < [xdi].$Obj(EditorDisplay).View.FirstVisChar.dCharIndex
              mov edx, [xdi].$Obj(EditorDisplay).View.FirstVisChar.dCharIndex
              sub edx, ebx
              OCall [xdi].$Obj(EditorDisplay).View::EditorView.ScrollPageLeft, edx
            .elseif ebx > [xdi].$Obj(EditorDisplay).View.FirstVisChar.dCharIndex
              mov edx, ebx
              sub edx, [xdi].$Obj(EditorDisplay).View.FirstVisChar.dCharIndex
              OCall [xdi].$Obj(EditorDisplay).View::EditorView.ScrollPageRight, edx
            .endif
            xor eax, eax
            ret
          .endif
          inc eax
          lea xdx, szInvalidLineNumber
          invoke luaL_error, pLuaState, xdx, eax        ;This proc does not return
        .endif
        lea xdx, szInvalidCharIndex
        invoke luaL_error, pLuaState, xdx, eax          ;This proc does not return
      .endif
      lea xdx, szInvalidDisplayIndex
      invoke luaL_error, pLuaState, xdx, edi            ;This proc does not return
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorSetViewLocation endp

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
          xor eax, eax
          ret
        .endif
      .endif
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
            OCall pEditor::Editor.ManageEditCmds
            MemFree xsi
            xor eax, eax
            ret
          .endif
        .endif
      .endif
      MemFree xsi
    .endif  
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
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
    xor eax, eax
    ret
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorShow endp

; --------------------------------------------------------------------------------------------------
; Procedure:  EditorShowCaret
; Purpose:    Show the editor caret.
; Arguments:  Arg1: -> lua_State
; Return:     eax = Number of arguments returned on the lua stack.
; Lua call:   Editor.HideCaret(hEditor)

EditorShowCaret proc pLuaState:ptr lua_State
  invoke luaL_checkinteger, pLuaState, 1                ;Get first stack argument and check for int
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xcx, [xax].$Obj(Editor).pFocusedView
      .if xcx != NULL
        OCall xcx::EditorView.CaretShow
      .endif
      xor eax, eax
      ret
    .endif
  .endif
  invoke luaL_error, pLuaState, addr szInvalidEditorHandle   ;This proc does not return
EditorShowCaret endp
