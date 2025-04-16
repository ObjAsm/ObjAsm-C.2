; ==================================================================================================
; Title:      Demo01D.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application 1D.
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

Object Shape, ShapeID, OA:Streamable            ;Start Shape definition, inherided from Streamable!
  VirtualAbstract   GetArea                     ;Define an abstract static method.
  RedefineMethod    Init,       DWORD, DWORD    ;Base, Height
  RedefineMethod    Load,       $ObjPtr(OA:Stream), POINTER  ;-> Stream, -> Owner
  RedefineMethod    Store,      $ObjPtr(OA:Stream)           ;-> Stream
  Private
  VirtualMethod     PrivateMtd                  ;Private static method

  DefineVariable    dBase,      DWORD,    100   ;Set dBase to 0
  DefineVariable    dHeight,    DWORD,    200   ;Set dHeight to 0
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Triangle, TriangleID, Shape              ;Start Triangle def., inherited from Shape
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
    m2m [xcx].dBase, dBase, eax                 ;Store dBase in instance data
    m2m [xcx].dHeight, dHeight, edx             ;Store dHeight in instance data
    OCall xcx.PrivateMtd                        ;Test the private method
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Shape.PrivateMtd
; Purpose:    Set object variables.
; Arguments:  Arg1: Base.
;             Arg2: Height.
; Return:     Nothing.

Method Shape.PrivateMtd
    DbgText "Method: Shape.Private"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Shape.Load
; Purpose:    Load an object from a stream.
; Arguments:  Arg1: -> Stream
;             Arg2: -> Owner
; Return:     Nothing.

Method Shape.Load, uses xsi, pStream:$ObjPtr(OA:Stream), pOwner:POINTER
    SetObject xsi
    ACall xsi.Init, pOwner
    OCall pStream::OA:Stream.BinRead, addr [xsi].dBase, sizeof(DWORD)
    OCall pStream::OA:Stream.BinRead, addr [xsi].dHeight, sizeof(DWORD)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Shape.Store
; Purpose:    Store an object into a stream.
; Arguments:  Arg1: -> Stream
;             Arg2: -> Owner
; Return:     Nothing.

Method Shape.Store, uses xsi, pStream:$ObjPtr(OA:Stream)
    SetObject xsi
    OCall pStream::OA:Stream.BinWrite, addr [xsi].dBase, sizeof(DWORD)
    OCall pStream::OA:Stream.BinWrite, addr [xsi].dHeight, sizeof(DWORD)
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
    mov eax, [xcx].dBase                        ;Get dBase from instance data
    mul [xcx].dHeight                           ;Multiply by dHeight from instance data
    shr eax, 1                                  ;eax = Base * Height / 2
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
    mov eax, [xcx].dBase                        ;Get dBase from instance data
    mul [xcx].dHeight                           ;Multiply by dHeight from instance data
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.GetPerimeter
; Purpose:    Calculate the rectangle perimeter.
; Arguments:  None.
; Return:     eax = Rectangle perimeter.

Method Rectangle.GetPerimeter
    DbgText "Method: Rectangle.GetPerimeter"
    SetObject xcx
    mov eax, [xcx].dBase                        ;Get dBase from instance data
    add eax, [xcx].dHeight                      ;Add dHeight from instance data
    shl eax, 1                                  ;eax = 2 * (Base + Height)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rectangle.TestFunction
; Purpose:    By default, return TRUE.
; Arguments:  None.
; Return:     rax = TRUE.

Method Rectangle.TestFunction
    DbgText "Method: Rectangle.TestFunction"
    mov xax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IsQuad
; Purpose:    Check if the rectangle has equal sides.
; Arguments:  None.
; Return:     eax = TRUE or FALSE.

Method Rectangle.IsQuad
    DbgText "Method: IsQuad"
    SetObject xcx
    mov eax, [xcx].dBase                        ;Get dBase from instance data
    .if eax == [xcx].dHeight                    ;Compare with dHeight from instance data
      mov xax, TRUE                             ;if equal => xax = TRUE
    .else
      xor eax, eax                              ;if not equal => xax = FALSE
    .endif
MethodEnd
