; ==================================================================================================
; Title:      Demo01D.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Objects for ObjAsm application Demo01D.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   This file defines the Shape class hierarchy for Demo01D, extended with streaming support.
;   All classes derive from OA:Streamable, enabling runtime object serialization and deserialization
;   via Stream and DiskStream.
;
;   Implemented features:
;     - Load and Store methods for binary persistence
;     - Abstract and overridden methods (GetArea)
;     - Additional methods specific to Rectangle (GetPerimeter / TestFunction / IsQuad)
;
; ==================================================================================================


; -----------------------------------------
; Class Identification Numbers
; -----------------------------------------

ShapeID      equ     0002                       ; Shape class ID
TriangleID   equ     0003                       ; Triangle class ID
RectangleID  equ     0004                       ; Rectangle class ID


; ==================================================================================================
;     Object Definitions
; ==================================================================================================

ObjNamespace Shapes                             ; Declare Shapes as namespace

; --------------------------------------------------------------------------------------------------
; Shape (base class, streamable)
; --------------------------------------------------------------------------------------------------

Object Shape, ShapeID, OA:Streamable            ; Shape inherits from Streamable (supports Load/Store)
  VirtualAbstract   GetArea                     ; Abstract method: must be implemented by derived classes

  RedefineMethod    Init,   DWORD, DWORD        ; Parameters: Base, Height
  RedefineMethod    Load,   $ObjPtr(OA:Stream), POINTER   ; Load(stream, owner)
  RedefineMethod    Store,  $ObjPtr(OA:Stream)            ; Store(stream)

  Private
  VirtualMethod     PrivateMtd                  ; Private helper method

  DefineVariable    dBase,   DWORD, 100         ; Instance variable: Base value
  DefineVariable    dHeight, DWORD, 200         ; Instance variable: Height
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Triangle (derived from Shape)
; --------------------------------------------------------------------------------------------------

Object Triangle, TriangleID, Shape
  RedefineMethod    GetArea                     ; Override abstract GetArea
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Rectangle (derived from Shape)
; --------------------------------------------------------------------------------------------------

Object Rectangle, RectangleID, Shape
  RedefineMethod    GetArea                     ; Override triangle/shape area method
  VirtualMethod     GetPerimeter                ; Additional method
  DynamicMethod     TestFunction                ; Dynamically overridable method
ObjectEnd


; ==================================================================================================
;     Shape Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Shape.Init
; Purpose:    Initialize instance variables dBase and dHeight.
; Arguments:  Arg1: Base value to assign.
;             Arg2: Height value to assign.
; Return:     Nothing.

Method Shape.Init,, dBase:DWORD, dHeight:DWORD
  DbgText "Method: Shape.Init"
  SetObject xcx
  m2m [xcx].dBase,   dBase,   eax               ; Store Base
  m2m [xcx].dHeight, dHeight, edx               ; Store Height
  OCall xcx.PrivateMtd                          ; Call private helper
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Shape.PrivMethod
; Purpose:    Internal helper method used to validate calls during initialization.
; Arguments:  None.
; Return:     Nothing.

Method Shape.PrivateMtd
  DbgText "Method: Shape.Private"
MethodEnd


; --------------------------------------------------------------------------------------------------
; Method:     Shape.Load
; Purpose:    Load object data from a stream.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Owner object.
; Return:     Nothing.

Method Shape.Load, uses xsi, pStream:$ObjPtr(OA:Stream), pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner                       ; Initialize after loading
  OCall pStream::OA:Stream.BinRead, addr [xsi].dBase,   sizeof(DWORD)
  OCall pStream::OA:Stream.BinRead, addr [xsi].dHeight, sizeof(DWORD)
MethodEnd


; --------------------------------------------------------------------------------------------------
; Method:     Shape.Store
; Purpose:    Store object data into a stream.
; Arguments:  Arg1: -> Stream object
; Return:     Nothing.

Method Shape.Store, uses xsi, pStream:$ObjPtr(OA:Stream)
  SetObject xsi
  OCall pStream::OA:Stream.BinWrite, addr [xsi].dBase,   sizeof(DWORD)
  OCall pStream::OA:Stream.BinWrite, addr [xsi].dHeight, sizeof(DWORD)
MethodEnd



; ==================================================================================================
;     Triangle Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Triangle.GetArea
; Purpose:    Compute the triangle area using formula: (Base * Height) / 2.
; Arguments:  None.
; Return:     eax = Triangle area.

Method Triangle.GetArea
  DbgText "Method: Triangle.GetArea"
  SetObject xcx
  mov eax, [xcx].dBase                        ; Load Base
  mul [xcx].dHeight                           ; Multiply by Height
  shr eax, 1                                  ; Divide by 2
MethodEnd


; ==================================================================================================
;     Rectangle Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetArea
; Purpose:    Compute rectangle area: Base*Height.
; Arguments:  None.
; Return:     eax = Rectangle area.

Method Rectangle.GetArea
  DbgText "Method: Rectangle.GetArea"
  SetObject xcx
  mov eax, [xcx].dBase
  mul [xcx].dHeight
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetPerimeter
; Purpose:    Compute rectangle perimeter = 2*(Base + Height).
; Arguments:  None.
; Return:     eax = Rectangle perimeter.

Method Rectangle.GetPerimeter
  DbgText "Method: Rectangle.GetPerimeter"
  SetObject xcx
  mov eax, [xcx].dBase
  add eax, [xcx].dHeight
  shl eax, 1                                   ; Multiply by 2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.TestFunction
; Purpose:    Default implementation returns TRUE. Used to demonstrate dynamic overrides.
; Arguments:  None.
; Return:     eax = TRUE.

Method Rectangle.TestFunction
  DbgText "Method: Rectangle.TestFunction"
  mov xax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.IsQuad
; Purpose:    Check whether the rectangle has equal sides (i.e., is a square).
; Arguments:  None.
; Return:     eax = TRUE if square, FALSE otherwise.

Method Rectangle.IsQuad
  DbgText "Method: Rectangle.IsQuad"
  SetObject xcx
  mov eax, [xcx].dBase                          ; Load Base
  .if eax == [xcx].dHeight                      ; Compare Base and Height
    mov eax, TRUE                               ; Equal => TRUE (square)
  .else
    xor eax, eax                                ; Not equal => FALSE
  .endif
MethodEnd