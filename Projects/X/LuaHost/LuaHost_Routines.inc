; ==================================================================================================
; Title:      LuaHost_Routines.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    General purpose routines needed for Script initialization.
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

