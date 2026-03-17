; ==================================================================================================
; Title:      Demo05.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Vector Demo
; Notes:      Version C.1.0, September 2021
;               - Initial release.
;
; Description:
;   Demo05 demonstrates the functionality of ObjAsm Vector classes, including:
;     - XWordVector for 64-bit element storage
;     - ByteVector for 8-bit element storage
;     - Common vector operations such as insertion, deletion, indexing, iteration, 
;       and element-wise enumeration via callback procedures.
;
;   Additional topics illustrated in this demo:
;     - The ForEach callback mechanism for item enumeration
;     - Serialization of vector contents using DiskStream
;     - Deserialization using DesLUT for type lookup support
;     - Reconstruction of serialized objects into either existing or newly allocated instances
;
;   Diagnostic output is written to DebugCenter, showing every step of the vector operations.
;   The example provides a clear and complete demonstration of vector manipulation and
;   persistent storage within ObjAsm’s object-oriented model.
;
; ==================================================================================================



% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include and initialize standard modules
SysSetup OOP, NUI64, WIDE_STRING, DEBUG(WND)            ; Load OOP modules and OS-related objects

MakeObjects Primer, Stream, DiskStream
MakeObjects Vector, XWordVector, ByteVector

.code                                                   ; Begin code segment
; Callback for XWORD vector content
ShowItemA proc xItem:XWORD, xArg1:XWORD, xArg2:XWORD
  DbgDec xItem
  ret
ShowItemA endp

; Callback for BYTE vector content
ShowItemB proc xItem:BYTE, xArg1:XWORD, xArg2:XWORD
  DbgDec xItem
  ret
ShowItemB endp


start proc uses xbx xdi xsi                             ; Program entry point
  local DesSerInfo:DESER_INFO
  local pVector:POINTER

  SysInit                                               ; Initialize ObjAsm OOP runtime
  DbgClearAll                                           ; Clear all DebugCenter output windows

  ; ----------------------------------------------------------------------------
  ; XWORD Vector operations
  ; ----------------------------------------------------------------------------
  mov xbx, offset $ObjTmpl(%XWordVector)                ; Use the object template
  OCall xbx::%XWordVector.Init, NULL, 1, 1, $Obj(%XWordVector)_MaxCapacity

  ; Insert sample values
  OCall xbx::%XWordVector.Insert, 10
  OCall xbx::%XWordVector.Insert, 20
  OCall xbx::%XWordVector.Insert, 30
  OCall xbx::%XWordVector.Insert, 40
  OCall xbx::%XWordVector.Insert, 50
  OCall xbx::%XWordVector.Insert, 60
  OCall xbx::%XWordVector.Insert, 70
  OCall xbx::%XWordVector.Insert, 80
  OCall xbx::%XWordVector.Insert, 90
  OCall xbx::%XWordVector.Insert, 100
  OCall xbx::%XWordVector.Insert, 110
  OCall xbx::%XWordVector.Insert, 120
  OCall xbx::%XWordVector.Insert, 130
  OCall xbx::%XWordVector.Insert, 140

  ; Retrieve first elements
  OCall xbx::%XWordVector.ItemAt, 0
  DbgDec XWORD ptr [xax]
  OCall xbx::%XWordVector.ItemAt, 1
  DbgDec XWORD ptr [xax]
  OCall xbx::%XWordVector.ItemAt, 2
  DbgDec XWORD ptr [xax]
  OCall xbx::%XWordVector.ItemAt, 3
  DbgDec XWORD ptr [xax]
  DbgLine

  ; Index lookups
  OCall xbx::%XWordVector.IndexOf, 30                   ; Returns 2
  DbgDec eax
  OCall xbx::%XWordVector.IndexOf, 200                  ; Returns -1 (not found)
  DbgDec eax
  DbgLine

  ; Enumerate all items
  OCall xbx::%XWordVector.ForEach, offset ShowItemA, NULL, NULL
  DbgLine

  ; Delete several elements
  OCall xbx::%XWordVector.DeleteAt, 1
  OCall xbx::%XWordVector.DeleteAt, 2
  OCall xbx::%XWordVector.DeleteAt, 3
  OCall xbx::%XWordVector.DeleteAt, 4
  OCall xbx::%XWordVector.DeleteAt, 5
  OCall xbx::%XWordVector.DeleteAt, 6
  OCall xbx::%XWordVector.DeleteAt, 7
  OCall xbx::%XWordVector.ForEach, offset ShowItemA, NULL, NULL
  DbgLine

  ; Insert at specific positions
  OCall xbx::%XWordVector.InsertAt, 1, 20
  OCall xbx::%XWordVector.InsertAt, 3, 40
  OCall xbx::%XWordVector.InsertAt, 5, 60
  OCall xbx::%XWordVector.InsertAt, 7, 80
  OCall xbx::%XWordVector.InsertAt, 9, 100
  OCall xbx::%XWordVector.InsertAt, 11, 120
  OCall xbx::%XWordVector.InsertAt, 13, 140
  OCall xbx::%XWordVector.ForEach, offset ShowItemA, NULL, NULL
  DbgLine2

  ; ----------------------------------------------------------------------------
  ; BYTE Vector operations
  ; ----------------------------------------------------------------------------
  mov xbx, offset $ObjTmpl(ByteVector)                  ; Use the object template
  OCall xbx::ByteVector.Init, NULL, 1, 1, $Obj(ByteVector)_MaxCapacity

  ; Insert sample values
  OCall xbx::ByteVector.Insert, 10
  OCall xbx::ByteVector.Insert, 20
  OCall xbx::ByteVector.Insert, 30
  OCall xbx::ByteVector.Insert, 40
  OCall xbx::ByteVector.Insert, 50
  OCall xbx::ByteVector.Insert, 60
  OCall xbx::ByteVector.Insert, 70
  OCall xbx::ByteVector.Insert, 80
  OCall xbx::ByteVector.Insert, 90
  OCall xbx::ByteVector.Insert, 100
  OCall xbx::ByteVector.Insert, 110
  OCall xbx::ByteVector.Insert, 120
  OCall xbx::ByteVector.Insert, 130
  OCall xbx::ByteVector.Insert, 140

  ; Retrieve and display first elements
  OCall xbx::ByteVector.ItemAt, 0
  DbgDec BYTE ptr [xax]
  OCall xbx::ByteVector.ItemAt, 1
  DbgDec BYTE ptr [xax]
  OCall xbx::ByteVector.ItemAt, 2
  DbgDec BYTE ptr [xax]
  OCall xbx::ByteVector.ItemAt, 3
  DbgDec BYTE ptr [xax]
  DbgLine

  ; Index lookups
  OCall xbx::ByteVector.IndexOf, 30                     ; Returns 2
  DbgDec eax
  OCall xbx::ByteVector.IndexOf, 200                    ; Returns -1 (not found)
  DbgDec eax
  DbgLine

  ; Enumerate items
  OCall xbx::ByteVector.ForEach, offset ShowItemB, NULL, NULL
  DbgLine

  ; Deletions
  OCall xbx::ByteVector.DeleteAt, 1
  OCall xbx::ByteVector.DeleteAt, 2
  OCall xbx::ByteVector.DeleteAt, 3
  OCall xbx::ByteVector.DeleteAt, 4
  OCall xbx::ByteVector.DeleteAt, 5
  OCall xbx::ByteVector.DeleteAt, 6
  OCall xbx::ByteVector.DeleteAt, 7
  OCall xbx::ByteVector.ForEach, offset ShowItemB, NULL, NULL
  DbgLine

  ; Insert new values at specific positions
  OCall xbx::ByteVector.InsertAt, 1, 20
  OCall xbx::ByteVector.InsertAt, 3, 40
  OCall xbx::ByteVector.InsertAt, 5, 60
  OCall xbx::ByteVector.InsertAt, 7, 80
  OCall xbx::ByteVector.InsertAt, 9, 100
  OCall xbx::ByteVector.InsertAt, 11, 120
  OCall xbx::ByteVector.InsertAt, 13, 140
  OCall xbx::ByteVector.ForEach, offset ShowItemB, NULL, NULL

  DbgLine2

  ; ----------------------------------------------------------------------------
  ; Serialization and Deserialization
  ; ----------------------------------------------------------------------------

  ; Prepare deserialization lookup table
  mov xsi, offset $ObjTmpl(DesLUT)
  mov DesSerInfo.pDesLUT, xsi
  OCall xsi::DesLUT.Init, NULL, 10, 10, 100

  mov xdi, offset $ObjTmpl(DiskStream)

  ; Store vector contents, clear the vector, then reload them
  OCall xdi::DiskStream.Init, NULL, $OfsCStr(".\Vector1.stm"), 0,0,0,0,0,0
  OCall xbx::ByteVector.Store, xdi
  OCall xbx::ByteVector.DeleteAll
  OCall xbx::ByteVector.ForEach, offset ShowItemB, NULL, NULL

  OCall xdi::DiskStream.Seek, QWORD ptr 0, STM_BEGIN    ; Reset stream pointer
  OCall xbx::ByteVector.Load, xdi, addr DesSerInfo
  OCall xbx::ByteVector.ForEach, offset ShowItemB, NULL, NULL
  OCall xdi::DiskStream.Done

  ; Store full vector object, reload as a NEW instance
  OCall xdi::DiskStream.Init, NULL, $OfsCStr(".\Vector2.stm"),0,0,0,0,0,0
  OCall xdi::DiskStream.Put, xbx
  OCall xbx::ByteVector.DeleteAll
  OCall xbx::ByteVector.ForEach, offset ShowItemB, NULL, NULL
  DbgLine

  OCall xdi::DiskStream.Seek, QWORD ptr 0, STM_BEGIN    ; Reset stream
  mov pVector, $OCall(xdi::DiskStream.Get, addr DesSerInfo)
  .if xax != NULL
    OCall pVector::ByteVector.ForEach, offset ShowItemB, NULL, NULL
    Destroy pVector
  .endif
  OCall xdi::DiskStream.Done

  ; ----------------------------------------------------------------------------
  ; Final cleanup
  ; ----------------------------------------------------------------------------
  OCall xbx::ByteVector.Done
  OCall xsi::DesLUT.Done

  DbgLine
  DbgText "Ready"

  SysDone                                               ; Finalize ObjAsm runtime
  invoke ExitProcess, 0                                 ; Exit with return code 0
start endp

end