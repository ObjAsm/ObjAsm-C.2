; ==================================================================================================
; Title:      Demo01A.asm
; Author:     G. Friedrich
; Purpose:    ObjAsm demonstration application Demo01A.
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release
;
; Description:
;   This demo illustrates the basic principles of the ObjAsm object model:
;     - Creating object instances dynamically at runtime
;     - Calling methods using OCall
;     - Demonstrating polymorphism through overridden methods
;     - Using DebugCenter to display intermediate values
;   The program creates a Triangle and a Rectangle object, initializes them, retrieves their 
;   areas, perimeters, and tests a method override in action.
;
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include and initialize standard ObjAsm modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)            ; Load OOP support, OS layer, and debug window

MakeObjects Primer, Demo01                              ; Include Shape base class and derived classes

.data?                                                  ; ---------------- Data? Segment --------------
pShape_1  $ObjPtr(Triangle)   ?                         ; Pointer to an instance of Triangle
pShape_2  $ObjPtr(Rectangle)  ?                         ; Pointer to an instance of Rectangle

.code                                                   ; ---------------- Code Segment ----------------
start proc                                              ; Program entry point
  SysInit                                               ; Initialize the ObjAsm runtime and class system
  DbgClearAll                                           ; Clear all DebugCenter windows for clean output

  ;---------------- Create and handle Triangle object ----------------
  New Triangle                                          ; Allocate a new Triangle instance
  mov pShape_1, xax                                     ; Save pointer to Triangle instance

  OCall pShape_1::Triangle.Init, 10, 15                 ; Initialize Triangle using base=10 and height=15
  OCall pShape_1::Shape.GetArea                         ; Call polymorphic GetArea method
  DbgDec eax                                            ; Expected result = 75

  ;---------------- Create and handle Rectangle object ---------------
  New Rectangle                                         ; Allocate a new Rectangle instance
  mov pShape_2, xax                                     ; Save pointer to Rectangle instance

  OCall pShape_2::Rectangle.Init, 10, 15                ; Initialize Rectangle using width=10 and height=15
  OCall pShape_2::Shape.GetArea                         ; Compute area through base class method
  DbgDec eax                                            ; Expected result = 150

  OCall pShape_2::Rectangle.GetPerimeter                ; Compute rectangle perimeter
  DbgDec eax                                            ; Expected result = 50

  ;---------------- Demonstrate method overriding --------------------
  OCall pShape_2::Rectangle.TestFunction                ; Call default TestFunction implementation
  DbgDec xax                                            ; Expected output: TRUE (1)

  Override pShape_2::Rectangle.TestFunction, Rectangle.IsQuad
                                                        ; Override TestFunction with IsQuad method
                                                        ; (demonstrates dynamic method replacement)
  OCall pShape_2::Rectangle.TestFunction                ; Call the method again after override
  DbgDec xax                                            ; Expected output of IsQuad: FALSE (0)

  ;---------------- Cleanup and shutdown -----------------------------
  Destroy pShape_2                                      ; Call Rectangle.Done and free instance memory
  Destroy pShape_1                                      ; Call Triangle.Done and free instance memory

  SysDone                                               ; Finalize ObjAsm environment and cleanup runtime

  invoke ExitProcess, 0                                 ; Terminate program and return status 0
start endp

end