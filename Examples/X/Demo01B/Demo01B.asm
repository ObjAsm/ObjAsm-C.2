; ==================================================================================================
; Title:      Demo01B.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application Demo01B, using console-based debug output.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   Demo01B works similarly to Demo01A, but routes DebugCenter output to a console window
;   instead of using DebugCenter’s GUI window. This demonstrates:
;       - How to use DEBUG(CON) for console debugging
;       - How to read input from CONIN$ to pause execution
;       - Creation, initialization, and method invocation on Triangle and Rectangle objects
;       - Dynamic method replacement using Override
;
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include and initialize standard ObjAsm modules

SysSetup OOP, NUI64, ANSI_STRING, DEBUG(CON)            ; Load OOP support and OS layer
                                                        ; Redirect Debug output to a console window
MakeObjects Primer, Demo01                              ; Include Shape, Triangle, and Rectangle classes

.data?                                                  ; -------------- Data? Segment -------------
pShape_1    $ObjPtr(Triangle)   ?                       ; Pointer to Triangle instance
pShape_2    $ObjPtr(Rectangle)  ?                       ; Pointer to Rectangle instance

cConInput   CHR     10 DUP(?)                           ; Input buffer for pausing console execution
dBytesRead  DWORD   ?                                   ; Stores number of bytes read from CONIN$

.code                                                   ; -------------- Code Segment --------------
start proc                                              ; Program entry point
  SysInit                                               ; Initialize ObjAsm runtime system

  ; ---------------- Triangle demonstration -----------------
  New Triangle                                          ; Create a new Triangle object
  mov pShape_1, xax                                     ; Store instance pointer

  OCall pShape_1::Triangle.Init, 10, 15                 ; Initialize with Base=10, Height=15
  OCall pShape_1::Shape.GetArea                         ; Compute Triangle area
  DbgDec eax                                            ; Expected result = 75

  ; ---------------- Rectangle demonstration ----------------
  New Rectangle                                         ; Create a new Rectangle object
  mov pShape_2, xax                                     ; Store instance pointer

  OCall pShape_2::Rectangle.Init, 10, 15                ; Initialize with Width=10, Height=15
  OCall pShape_2::Shape.GetArea                         ; Compute Rectangle area
  DbgDec eax                                            ; Expected result = 150

  OCall pShape_2::Rectangle.GetPerimeter                ; Compute Rectangle perimeter
  DbgDec eax                                            ; Expected result = 50

  ; ---------- Dynamic method override demonstration --------
  OCall pShape_2::Rectangle.TestFunction                ; Default implementation
  DbgDec xax                                            ; Expected output: TRUE = 1

  Override pShape_2::Rectangle.TestFunction, Rectangle.IsQuad
                                                        ; Replace TestFunction with IsQuad
                                                        ; (demonstrates runtime method substitution)
  OCall pShape_2::Rectangle.TestFunction                ; Call overridden method
  DbgDec xax                                            ; Expected output: FALSE = 0 for 10×15 rectangle

  ; ---------------------- Cleanup --------------------------
  Destroy pShape_2                                      ; Invoke Rectangle.Done and free object
  Destroy pShape_1                                      ; Invoke Triangle.Done and free object

  ; -------------------- Console pause ----------------------
  ; Display message and wait for ENTER
  DbgText " "
  DbgText "Press [ENTER] to continue..."

  invoke CreateFile, $OfsCStr("CONIN$"), GENERIC_READ, FILE_SHARE_READ, \
                      0, OPEN_EXISTING, 0, 0            ; Open console input
  invoke ReadFile, xax, addr cConInput, sizeof(cConInput), addr dBytesRead, NULL
                                                        ; Read user input (pauses program)
  SysDone                                               ; Finalize ObjAsm runtime

  invoke ExitProcess, 0                                 ; Exit application, return code = 0

start endp

end
