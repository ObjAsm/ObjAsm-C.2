; ==================================================================================================
; Title:      Demo01.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 1.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


ShapeID      equ     0002                       ;Shape object ID
TriangleID   equ     0003                       ;Triangle object ID
RectangleID  equ     0004                       ;Rectangle object ID

; ==================================================================================================
;     Object definitions
; ==================================================================================================

ObjNamespace Shapes

Object Shape, ShapeID, OA:Primer                ;Start Shape definition, inherided from Primer
  VirtualAbstract   GetArea                     ;Define an abstract static method.
  RedefineMethod    Init,       DWORD, DWORD    ;Base, Height
  Private                                       ;Make all following methods private
  VirtualMethod     PrivMethod                  ;Private static method

  DefineVariable    dBase,      DWORD,    100   ;Set dBase to 0
  DefineVariable    dHeight,    DWORD,    200   ;Set dHeight to 0
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Triangle, TriangleID, Shape              ;Start TriangleShape def., inherited from Shape
  RedefineMethod    GetArea                     ;Define shape's abstract method.
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Rectangle, RectangleID, Shape            ;Start Rectangle def., inherited from Shape
  RedefineMethod    GetArea                     ;Define shape's abstract method.
  VirtualMethod     GetPerimeter                ;Define a new static method.
  DynamicMethod     TestFunction                ;Define a dynamic method
ObjectEnd


; ==================================================================================================
;     Shape implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Shape.Init
; Purpose:    Set object variables.
; Arguments:  Arg1: Base.
;             Arg2: Height.
; Return:     Nothing.

Method Shape.Init,, dBase:DWORD, dHeight:DWORD
  DbgText "Method: Shape.Init"
  SetObject xcx
  m2m [xcx].dBase, dBase, eax                           ;Store dBase in instance data
  m2m [xcx].dHeight, dHeight, edx                       ;Store dHeight in instance data
  OCall xcx.PrivMethod                                  ;Test the private method
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Shape.PrivMethod
; Purpose:    Set object variables.
; Arguments:  Arg1: Base.
;             Arg2: Height.
; Return:     Nothing.

Method Shape.PrivMethod
  DbgText "Method: Shape.PrivMethod"
MethodEnd


; ==================================================================================================
;     Triangle implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Triangle.GetArea
; Purpose:    Calculate the triangle area.
; Arguments:  None.
; Return:     eax = Triangle area.

Method Triangle.GetArea
  DbgText "Method: Triangle.GetArea"
  SetObject xcx
  mov eax, [xcx].dBase                                  ;Get dBase from instance data
  mul [xcx].dHeight                                     ;Multiply by dHeight from instance data
  shr eax, 1                                            ;eax = Base * Height / 2
MethodEnd


; ==================================================================================================
;     Rectangle implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetArea
; Purpose:    Calculate the rectangle area.
; Arguments:  None.
; Return:     eax = Rectangle area.

Method Rectangle.GetArea
  DbgText "Method: Rectangle.GetArea"
  SetObject xcx
  mov eax, [xcx].dBase                                  ;Get dBase from instance data
  mul [xcx].dHeight                                     ;Multiply by dHeight from instance data
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetPerimeter
; Purpose:    Calculate the rectangle perimeter.
; Arguments:  None.
; Return:     eax = Rectangle perimeter.

Method Rectangle.GetPerimeter
  DbgText "Method: Rectangle.GetPerimeter"
  SetObject xcx
  mov eax, [xcx].dBase                                  ;Get dBase from instance data
  add eax, [xcx].dHeight                                ;Add dHeight from instance data
  shl eax, 1                                            ;eax = 2 * (Base + Height)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.TestFunction
; Purpose:    By default, return TRUE.
; Arguments:  None.
; Return:     eax = TRUE.

Method Rectangle.TestFunction
  DbgText "Method: Rectangle.TestFunction"
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IsQuad
; Purpose:    Checke if the rectangle has equal sides.
; Arguments:  None.
; Return:     eax = TRUE or FALSE.

Method Rectangle.IsQuad
  DbgText "Method: IsQuad"
  SetObject xcx
  mov eax, [xcx].dBase                                  ;Get dBase from instance data
  .if eax == [xcx].dHeight                              ;Compare with dHeight from instance data
    mov eax, TRUE                                       ;if equal => eax = TRUE
  .else
    xor eax, eax                                        ;if not equal => eax = FALSE
  .endif
MethodEnd
