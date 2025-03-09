; ==================================================================================================
; Title:      ADE_ChildWnd.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm Child Window implementation.
; ==================================================================================================


; ==================================================================================================
; ChildWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.Done
; Purpose:    Finalize the ChildWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ChildWnd.Done
  SetObject xcx
  mov xax, [xcx].pOwner
  dec [xax].$Obj(ClientWnd).dChildCount
  ACall xcx.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.Init
; Purpose:    Initialize the ChildWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ChildWnd.Init,, pOwner:POINTER
  SetObject xcx
  mov xax, pOwner                                       ;xax -> ClientWnd
  inc [xax].$Obj(ClientWnd).dChildCount
  ACall xcx.Init, pOwner, NULL                          ;hWnd is set in WndProc
MethodEnd
