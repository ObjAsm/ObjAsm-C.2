; ==================================================================================================
; Title:      HelloObjAsm.asm
; Author:     Héctor S. Enrique / G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm UEFI Demo.
; Notes:      Version C.1.0, June 2022
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64, DEBUG(CON)           ;Load OOP files and basic OS support

MakeObjects Primer, Demo01                              ;Contains Triangle and Rectangle

.data
  pShape_1    $ObjPtr(Triangle)   NULL
  pShape_2    $ObjPtr(Rectangle)  NULL

.code
start proc uses xbx xdi xsi ImageHandle:EFI_HANDLE, pSysTable:PTR_EFI_SYSTEM_TABLE
  local cBuffer[100]:CHR

  ;Runtime model initialization
  SysInit ImageHandle, pSysTable

  mov xbx, pConsoleOut
  assume xbx:ptr ConOut
  invoke [xbx].ClearScreen, xbx
  ;Color change: Bits 0..3 are the foreground color, and bits 4..6 are the background color
  invoke [xbx].SetAttribute, xbx, EFI_YELLOW or EFI_BACKGROUND_BLACK
  invoke [xbx].ConOut.OutputString, xbx, $OfsCStr("Hello ObjAsm", 13, 10)
  invoke [xbx].SetAttribute, xbx, EFI_WHITE or EFI_BACKGROUND_BLACK

  New Triangle                                          ;Create an new instance of Triangle
  mov pShape_1, xax                                     ;Store instance pointer

  OCall pShape_1::Triangle.Init, 10, 15                 ;Initialize Triangle
  OCall pShape_1::Shape.GetArea                         ;Invoke GetArea method of Triangle
  DbgDec eax, "Triangle Area"                           ;Result = 75

  New Rectangle                                         ;Create an new instance of Rectangle
  mov pShape_2, xax                                     ;Store instance pointer
  OCall pShape_2::Rectangle.Init, 10, 15                ;Initialize Rectangle
  OCall pShape_2::Shape.GetArea                         ;Invoke GetArea method of Rectangle
  DbgDec eax, "Rectangle Area"                          ;Result = 150

  OCall pShape_2::Rectangle.GetPerimeter                ;Invoke GetPerimeter method
  DbgDec eax, "Rectangle Perimeter"                     ;Result = 50
  
  Destroy pShape_2                                      ;Invoke Rectangle's Done and disposes it
  Destroy pShape_1                                      ;Invoke Triangle's Done and disposes it

  invoke [xbx].SetAttribute, xbx, EFI_LIGHTGREEN or EFI_BACKGROUND_BLACK
  invoke [xbx].OutputString, xbx, $OfsCStr(13, 10, "press a key to continue...")

  invoke Wait4Key

  invoke [xbx].SetAttribute, xbx, EFI_YELLOW or EFI_BACKGROUND_BLACK
  invoke [xbx].OutputString, xbx, $OfsCStr(13, 10, "bye bye...", 13, 10)
  assume xbx:nothing

  SysDone

  mov xbx, pBootServices
  invoke [xbx].EFI_BOOT_SERVICES.Exit, ImageHandle, EFI_SUCCESS, 0, NULL

  ret
start endp

end
