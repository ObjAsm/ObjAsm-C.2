; ==================================================================================================
; Title:      Demo01C.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application Demo01C using static objects and templates.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   This program demonstrates how to use:
;     - Static object instances allocated in the .data segment
;     - Object Templates created via $ObjTmpl()
;     - Standard initialization and method invocation via OCall
;     - Dynamic method overriding
;     - Finalization using Done for static and template objects
;
;   Compared to Demo01A and Demo01B, this example shows how ObjAsm allows objects to exist without
;   requiring dynamic allocation (New) by defining static instances or using class-level templates.
;
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include and initialize standard ObjAsm modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)            ; Load OOP system, OS layer, and DebugCenter (window)

MakeObjects Primer, Demo01                              ; Include Shape, Triangle, and Rectangle classes

.data                                                   ; ---------------- Data Segment ----------------
Shape_1    $ObjInst(Triangle)                           ; Static instance of Triangle
pShape_1   $ObjPtr(Triangle)   NULL                     ; Pointer to static Triangle instance
pShape_2   $ObjPtr(Rectangle)  NULL                     ; Pointer to Rectangle template instance

.code                                                   ; ---------------- Code Segment ----------------
start proc                                              ; Program entry point
  SysInit                                               ; Initialize ObjAsm runtime and class system
  DbgClearAll                                           ; Reset DebugCenter windows

  ;---------------- Use static Triangle instance -------------------
  mov xax, offset Shape_1                               ; Get address of static object
  mov pShape_1, xax                                     ; Store instance pointer

  ;DbgObject pShape_1::Triangle                         ; Optional: dump object layout

  OCall pShape_1::Triangle.Init, 10, 15                 ; Initialize Triangle using Base=10 and Height=15
  OCall pShape_1::Shape.GetArea                         ; Compute Triangle area
  DbgDec eax                                            ; Expected result = 75

  ;---------------- Use Rectangle Template instance ----------------
  mov xax, offset $ObjTmpl(Rectangle)                   ; Access Rectangle Object Template
  mov pShape_2, xax                                     ; Store pointer to template-based instance

  OCall pShape_2::Rectangle.Init, 10, 15                ; Initialize Rectangle using Base=10 and Height=15

  ;---------------- Rectangle operations ---------------------------
  OCall pShape_2::Shape.GetArea                         ; Compute Rectangle area
  DbgDec eax                                            ; Expected result = 150

  OCall pShape_2::Rectangle.GetPerimeter                ; Compute perimeter
  DbgDec eax                                            ; Expected result = 50

  ;------------ Demonstrate dynamic method overriding --------------
  OCall pShape_2::Rectangle.TestFunction                ; Default TestFunction
  DbgDec xax                                            ; Expected = TRUE (1)

  Override pShape_2::Rectangle.TestFunction, Rectangle.IsQuad
                                                        ; Replace TestFunction with IsQuad
  OCall pShape_2::Rectangle.TestFunction                ; Execute overridden version
  DbgDec xax                                            ; Expected IsQuad result = FALSE (0)

  ;---------------------- Cleanup ----------------------------------
  OCall pShape_2::Rectangle.Done                        ; Finalize Rectangle template instance
  OCall pShape_1::Triangle.Done                         ; Finalize static Triangle instance

  SysDone                                               ; Finalize ObjAsm runtime
  invoke ExitProcess, 0                                 ; Terminate program (return code = 0)
start endp

end