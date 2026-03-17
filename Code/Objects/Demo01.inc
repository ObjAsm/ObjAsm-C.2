; ==================================================================================================
; Title:      Demo01.inc
; Author:     G. Friedrich
; Purpose:    ObjAsm objects for applications Demo01A, Demo01A, Demo01C and Demo01D.
; Version:    See Demo01?.asm
;
; Description:
;   This file demonstrates how ObjAsm implements an object-oriented class hierarchy and how
;   inheritance, virtual methods, dynamic dispatch, instance variables and method overriding work
;   in assembly language.
;
; Class Model Overview:
;
;
;                 Primer (base class)
;                   ¦
;                   ¦
;                 Shape (abstract base class)
;                   ¦
;                   ¦
;         +--------------------+
;         ¦                    ¦
;      Triangle             Rectangle
;
;
; The Shape class provides:
;   - Two instance variables: dBase, dHeight
;   - An abstract method: GetArea  (must be implemented by derived classes)
;   - A private helper method: PrivMethod
;   - An Init method to set instance variables
;
; Triangle and Rectangle override GetArea differently and Rectangle adds more methods.
;
; ==================================================================================================


; -----------------------------------------
; Class Identification Numbers
; -----------------------------------------
; Every ObjAsm object must have a unique numeric ID.
; These IDs are used internally by the runtime system.

ShapeID      equ     0002
TriangleID   equ     0003
RectangleID  equ     0004


; ==================================================================================================
;     Object definitions
; ==================================================================================================

ObjNamespace Shapes                             ; Declare Shapes as namespace

Object Shape, ShapeID, OA:Primer                ; Define Shape class, derived from Primer base
  VirtualAbstract   GetArea                     ; Declare abstract method: must be overridden
  RedefineMethod    Init, DWORD, DWORD          ; Redefine Init with parameters (Base, Height)

  Private                                       ; All subsequent methods become private
  VirtualMethod     PrivMethod                  ; Private virtual method for internal testing

  DefineVariable    dBase,   DWORD,   100       ; Base length (default value = 100)
  DefineVariable    dHeight, DWORD,   200       ; Height value (default value = 200)
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Triangle, TriangleID, Shape              ; Define Triangle, derived from Shape
  RedefineMethod    GetArea                     ; Provide implementation for abstract GetArea
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Rectangle, RectangleID, Shape            ; Define Rectangle, derived from Shape
  RedefineMethod    GetArea                     ; Override base class GetArea method
  VirtualMethod     GetPerimeter                ; Additional method: compute rectangle perimeter
  DynamicMethod     TestFunction                ; Dynamic method, can be overridden at runtime
ObjectEnd


; ==================================================================================================
;     Shape implementation
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
  m2m [xcx].dBase,   dBase,   eax               ; Store passed Base value
  m2m [xcx].dHeight, dHeight, edx               ; Store passed Height value
  OCall xcx.PrivMethod                          ; Invoke private helper method
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Shape.PrivMethod
; Purpose:    Internal helper method used to validate calls during initialization.
; Arguments:  None.
; Return:     Nothing.

Method Shape.PrivMethod
  DbgText "Method: Shape.PrivMethod"
MethodEnd


; ==================================================================================================
;     Triangle implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Triangle.GetArea
; Purpose:    Compute the triangle area using formula: (Base * Height) / 2.
; Arguments:  None.
; Return:     eax = Triangle area.

Method Triangle.GetArea
  DbgText "Method: Triangle.GetArea"
  SetObject xcx
  mov eax, [xcx].dBase                          ; Load Base value
  mul [xcx].dHeight                             ; Multiply by Height
  shr eax, 1                                    ; Divide by 2
MethodEnd


; ==================================================================================================
;     Rectangle implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetArea
; Purpose:    Compute rectangle area: Base*Height.
; Arguments:  None.
; Return:     eax = Rectangle area.

Method Rectangle.GetArea
  DbgText "Method: Rectangle.GetArea"
  SetObject xcx
  mov eax, [xcx].dBase                          ; Load Base
  mul [xcx].dHeight                             ; Multiply by Height
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetPerimeter
; Purpose:    Compute rectangle perimeter = 2*(Base + Height).
; Arguments:  None.
; Return:     eax = Rectangle perimeter.

Method Rectangle.GetPerimeter
  DbgText "Method: Rectangle.GetPerimeter"
  SetObject xcx
  mov eax, [xcx].dBase                          ; Load Base
  add eax, [xcx].dHeight                        ; Add Height
  shl eax, 1                                    ; Multiply by 2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.TestFunction
; Purpose:    Default implementation returns TRUE. Used to demonstrate dynamic overrides.
; Arguments:  None.
; Return:     eax = TRUE.

Method Rectangle.TestFunction
  DbgText "Method: Rectangle.TestFunction"
  mov eax, TRUE
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
