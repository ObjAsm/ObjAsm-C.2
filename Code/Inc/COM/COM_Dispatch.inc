; ==================================================================================================
; Title:      COM_Dispatch.inc
; Author:     G.Friedrich
; Version:    C.1.0
; Purpose:    COM dispatching helper procedures compatible with ObjAsm definitions.
; Notes:      Version 1.0.0, October 2017.
;               - First release.
; ==================================================================================================


externdef IID_NULL:GUID

if TARGET_BITNESS eq 32
  ExecDispatch proto C :POINTER, :DWORD, :WORD, :DWORD, :DWORD, :VARARG
else
  ExecDispatch proto :POINTER, :DWORD, :WORD, :DWORD, :DWORD, :VARARG
endif

CallDispatch proto :POINTER, :DWORD, :WORD, :DWORD, :POINTER, :POINTER

; --------------------------------------------------------------------------------------------------
; Macro:      GetMethodDispatchID
; Purpose:    Return the method ID of a specified interface.
; Arguments:  Arg1: Instance Pointer.
;             Arg2: Interface Name.
;             Arg3: Method Name.
;             Arg4: Destrination variable.
;             Arg5: (optional) Local Identifier.
; Usage:      GetMethodDispatchID pIDemo16, IDemo16, "Increment", dDispatchID

GetMethodDispatchID macro InterfacePointer:req, InterfaceName:req, MethodName:req, DstVar:req, LCID
  local OfsMtdName

  ifb <LCID>
    invoke GetUserDefaultLCID
    lea xcx, DstVar                                     ;;use rcx as address of destination variable
    $$ArgDest textequ <xcx>
    $$ArgLCID textequ <eax>                             ;;use eax as LCID value
  else
    ifidni <LCID>, <ecx>
      lea xax, DstVar                                   ;;use rax as address of destination variable
      $$ArgDest textequ <xax>
      $$ArgLCID textequ <ecx>                           ;;use ecx as LCID value
    else                                                ;;ecx was not used here => use it!
      lea xcx, DstVar                                   ;;use rcx as address of destination variable
      $$ArgDest textequ <xcx>
      $$ArgLCID textequ <LCID>                          ;;use LCID as specified in the param. list
    endif
  endif
  .const
    OfsMtdName  POINTER  $OfsCStrW(MethodName)          ;;Allocate method name and store its offset
  .code
  ICall InterfacePointer::InterfaceName.GetIDsOfNames, offset IID_NULL, addr OfsMtdName, 1, \
                                                       $$ArgLCID, $$ArgDest
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DEFINE_COM_MTD_DSP
; Purpose:    Define some equates to use a Dispatch interface.
; Arguments:  Arg1: Interface name.
;             Arg2: Method name.
;             Arg3: Method Dispatch ID.
;             Arg4: Method type.
;             Arg5: Return value type.
;             Arg6: Method argument types.
; Return:     Nothing

DEFINE_COM_MTD_DSP macro IName, MName:req, DispID:req, MtdType:req, RetType, Args:vararg
  $$ArgTypes textequ <>
  $$Index = 0
  for $$Parm, <Args>
    $$Index = $$Index + 1                               ;;Increment argument count
    $$ArgTypes CatStr $$ArgTypes, %$$Parm, <,>
  endm
  if $$Index gt 0
    $$ArgTypes SubStr $$ArgTypes, 1, @SizeStr(%$$ArgTypes) - 1  ;;Remove last comma
  endif

  ifnb <RetType>
    $$ReturnType textequ %RetType
  else
    $$ReturnType textequ <-1>                           ;;Set Flag if no return value is required
  endif

  DISPATCH_INFO_&IName&_&MName& CatStr <DispID>, <,>, %DISPATCH_&MtdType&, <,>, %$$Index
  DISPATCH_TYPE_&IName&_&MName& CatStr $$ReturnType, <,>, $$ArgTypes
endm

; --------------------------------------------------------------------------------------------------
; Macro:      COM_AutoDispatch
; Purpose:    Perform a COM method call using the Dispatch interface. Variant arguments are created
;             automatically onto stack.
; Arguments:  Arg1: pInterface::Interface.Method
;             Arg2: Method arguments
; Return:     eax = Method return value.
;             ecx = Argument index if an error happened.

COM_AutoDispatch macro Cast:req, Args:vararg
  $$Pos1 InStr <Cast>, <::>
  if $$Pos1 ne 0
    $$PName SubStr <Cast>, 1, $$Pos1 - 1
    $$Pos2 InStr $$Pos1 + 2, <Cast>, <.>
    if $$Pos2 ne 0
      $$IName SubStr <Cast>, $$Pos1 + 2, $$Pos2 - $$Pos1 - 2
      $$MName SubStr <Cast>, $$Pos2 + 1
    else
      .err <ComAutoDispatch format error. Dot-method missing.>
      exitm
    endif
  else
    .err <ComAutoDispatch format error. Double points missing.>
    exitm
  endif

  invoke ExecDispatch, $$PName, @CatStr(<DISPATCH_INFO_>, %$$IName, <_>, %$$MName), \
                       @CatStr(<DISPATCH_TYPE_>, %$$IName, <_>, %$$MName), Args
endm

; --------------------------------------------------------------------------------------------------
; Macro:      COM_Dispatch
; Purpose:    Perform a COM method call using the Dispatch interface. Varint arguments have to
;             be supplied.
; Arguments:  Arg1: pInterface::Interface.Method
;             Arg2: -> Method last variant argument.
;             Arg3: -> Return Variant.
; Return:     eax = Method return value.
;             ecx = Argument index if an error happened.

COM_Dispatch macro Cast:req, pVarArgs:=<NULL>, pVarRet:=<NULL>
  $$Pos1 InStr <Cast>, <::>
  if $$Pos1 ne 0
    $$PName SubStr <Cast>, 1, $$Pos1 - 1
    $$Pos2 InStr $$Pos1 + 2, <Cast>, <.>
    if $$Pos2 ne 0
      $$IName SubStr <Cast>, $$Pos1 + 2, $$Pos2 - $$Pos1 - 2
      $$MName SubStr <Cast>, $$Pos2 + 1
    else
      .err <COM_Dispatch format error. Dot-method missing.>
      exitm
    endif
  else
    .err <COM_Dispatch format error. Double points missing.>
    exitm
  endif

  invoke CallDispatch, $$PName, @CatStr(<DISPATCH_INFO_>, %$$IName, <_>, %$$MName), pVarArgs, pVarRet
endm
