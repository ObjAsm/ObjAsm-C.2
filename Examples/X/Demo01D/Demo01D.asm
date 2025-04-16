; ==================================================================================================
; Title:      Demo01D.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application 1D using object streaming capabilities.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

MakeObjects Primer, Stream, DiskStream, .\Demo01D

.data                                                   ;Define global variables in the Data segment
pShape_1  $ObjPtr(Triangle)       NULL
pShape_2  $ObjPtr(Rectangle)      NULL
pDskStm   $ObjPtr(OA:DiskStream)  NULL

.code                                                   ;Begin Code segment
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of the OOP model
  DbgClearAll                                           ;Clear all DebugCenter windows

  New Triangle                                          ;Create an new instance of Triangle
  mov pShape_1, xax                                     ;Store instance pointer
  OCall pShape_1::Triangle.Init, 10, 15                 ;Initialize Triangle
  OCall pShape_1::Shape.GetArea                         ;Invoke GetArea method of Triangle
  DbgDec eax                                            ;Result = 75

  New Rectangle                                         ;Create an new instance of Rectangle
  mov pShape_2, xax                                     ;Store instance pointer
  OCall pShape_2::Rectangle.Init, 10, 15                ;Initialize Rectangle

  OCall pShape_2::Rectangle.GetPerimeter                ;Invoke GetPerimeter method
  DbgDec eax                                            ;Result = 50

;##\  New code
  mov pDskStm, $New(OA:DiskStream)
  OCall pDskStm::OA:DiskStream.Init, NULL, $OfsCStr("Data.stm"),0,0,NULL,0,0,0
  OCall pDskStm::OA:DiskStream.Put, pShape_1
  OCall pDskStm::OA:DiskStream.Put, pShape_2

  Destroy pShape_2                                      ;Invoke Rectangle's Done and disposes it
  Destroy pShape_1                                      ;Invoke Triangle's Done and disposes it
  Destroy pDskStm

; --------------------------------------------------------------------------------------------------
  DbgLine
  mov pDskStm, $New(OA:DiskStream)
  OCall pDskStm::OA:DiskStream.Init, NULL, $OfsCStr("Data.stm"),0,0,NULL,0,0,0
  mov pShape_1, $OCall(pDskStm::OA:DiskStream.Get, NULL)
  mov pShape_2, $OCall(pDskStm::OA:DiskStream.Get, NULL)

  OCall pShape_1::Shape.GetArea                         ;Invoke GetArea method of Triangle
  DbgDec eax                                            ;Result = 75

  OCall pShape_2::Rectangle.GetPerimeter                ;Invoke GetPerimeter method
  DbgDec eax                                            ;Result = 50
;##/

  Destroy pShape_2                                      ;Invoke Rectangle's Done and disposes it
  Destroy pShape_1                                      ;Invoke Triangle's Done and disposes it
  Destroy pDskStm

  SysDone                                               ;Runtime finalization of the OOP model

  invoke ExitProcess, 0                                 ;Exit program returning 0 to Windows OS
start endp

end
