; ==================================================================================================
; Title:      D3Light.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm D3Light implementation.
; ==================================================================================================


; ==================================================================================================
;    D3Light implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     D3Light.Colorize
; Purpose:    Colorize all D3Triangles facing the Camera with this D3Light.
; Arguments:  Arg1: -> D3Scene D3Objects collection.
; Return:     Nothing.

Method D3Light.Colorize,, pCameras:$ObjPtr(Collection), Unused:XWORD
  OCall pCameras::Collection.ForEach, $MethodAddr(D3Camera.Colorize), pSelf, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Light.Load
; Purpose:    Load a D3Light from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method D3Light.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  OCall pStream::Stream.BinRead, addr [xsi].Origin, sizeof(D3Vector)
  mov [xsi].r4Intensity, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].Color, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dFlags, $32($OCall(pStream::Stream.BinRead32))
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Light.Move
; Purpose:    Move (displaces) the D3Light.
; Arguments:  Arg1: -> Displacement D3Vector structure.
; Return:     Nothing.

Method D3Light.Move,, pDisplacement:POINTER
  SetObject xcx, D3Light
  invoke MemClone, addr [xcx].Origin, pDisplacement, sizeof(D3Vector)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3Light.Store
; Purpose:    Store a D3Light in a Stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method D3Light.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite, addr [xsi].Origin, sizeof(D3Vector)
  OCall pStream::Stream.BinWrite32, [xsi].r4Intensity
  OCall pStream::Stream.BinWrite32, [xsi].Color
  OCall pStream::Stream.BinWrite32, [xsi].dFlags
MethodEnd
