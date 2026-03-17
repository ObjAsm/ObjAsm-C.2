; ==================================================================================================
; Title:      Demo01D.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application Demo01D using object streaming capabilities.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   This program demonstrates how ObjAsm supports object persistence using Stream and DiskStream.
;
;   Concepts shown:
;     - Saving (Put) objects to a structured stream file
;     - Restoring (Get) objects from disk
;     - Using DiskStream for serialization
;     - Reconstructing objects with all instance data preserved
;     - Verifying behavior through method calls after reloading
;
;   The program:
;     1. Creates a Triangle and Rectangle dynamically.
;     2. Initializes and uses them.
;     3. Streams both objects to "Data.stm".
;     4. Destroys the objects in memory.
;     5. Restores both objects from the stream.
;     6. Validates that the restored objects behave identically.
;
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include & initialize standard ObjAsm modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)            ; Load OOP support and DebugCenter (window)

MakeObjects Primer, Stream, DiskStream, .\Demo01D       ; Include class hierarchy for this demo

.data?                                                  ; ---------------- Data? Segment ---------------
pShape_1    $ObjPtr(Triangle)       ?                   ; Pointer to Triangle instance
pShape_2    $ObjPtr(Rectangle)      ?                   ; Pointer to Rectangle instance
pDskStm     $ObjPtr(OA:DiskStream)  ?                   ; Pointer to DiskStream instance

.code                                                   ; ---------------- Code Segment ----------------
start proc                                              ; Program entry point
  SysInit                                               ; Initialize runtime and class system
  DbgClearAll                                           ; Clear DebugCenter windows

  ;---------------- Create and initialize objects ----------------
  New Triangle                                          ; Allocate Triangle
  mov pShape_1, xax                                     ; Save instance pointer
  OCall pShape_1::Triangle.Init, 10, 15                 ; Initialize using Base=10 and Height=15

  OCall pShape_1::Shape.GetArea                         ; Test
  DbgDec eax                                            ; Result = 75

  New Rectangle                                         ; Allocate Rectangle
  mov pShape_2, xax                                     ; Save instance pointer
  OCall pShape_2::Rectangle.Init, 10, 15                ; Initialize Rectangle using Base=10 and Height=15

  OCall pShape_2::Rectangle.GetPerimeter                ; Test
  DbgDec eax                                            ; Result = 50

  ;---------------- Serialize both objects to disk ---------------
  mov pDskStm, $New(OA:DiskStream)                      ; Create new DiskStream instance
  OCall pDskStm::OA:DiskStream.Init, \
        NULL, $OfsCStr("Data.stm"), 0, 0, NULL, 0, 0, 0 ; Open file for writing

  OCall pDskStm::OA:DiskStream.Put, pShape_1            ; Stream Triangle
  OCall pDskStm::OA:DiskStream.Put, pShape_2            ; Stream Rectangle

  ;---------------- Cleanup original objects ---------------------
  Destroy pShape_2                                      ; Dispose Rectangle
  Destroy pShape_1                                      ; Dispose Triangle
  Destroy pDskStm                                       ; Close stream

  ; ==================================================================================================
  ; Restore objects from stream
  ; ==================================================================================================

  DbgLine                                               ; Visual separator in debug output

  mov pDskStm, $New(OA:DiskStream)                      ; Recreate DiskStream
  OCall pDskStm::OA:DiskStream.Init, \
        NULL, $OfsCStr("Data.stm"), 0, 0, NULL, 0, 0, 0 ; Reopen file for reading

  mov pShape_1, $OCall(pDskStm::OA:DiskStream.Get, NULL); Restore Triangle
  mov pShape_2, $OCall(pDskStm::OA:DiskStream.Get, NULL); Restore Rectangle

  ;---------------- Validate restored objects --------------------
  OCall pShape_1::Shape.GetArea                         ; Triangle area again
  DbgDec eax                                            ; Expected = 75

  OCall pShape_2::Rectangle.GetPerimeter                ; Rectangle perimeter again
  DbgDec eax                                            ; Expected = 50

  ;---------------- Final cleanup --------------------------------
  Destroy pShape_2                                      ; Dispose restored Rectangle
  Destroy pShape_1                                      ; Dispose restored Triangle
  Destroy pDskStm                                       ; Dispose DiskStream

  SysDone                                               ; Shutdown ObjAsm runtime

  invoke ExitProcess, 0                                 ; Return 0 to Windows OS
start endp

end