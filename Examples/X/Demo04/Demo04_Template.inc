; ==================================================================================================
; Title:      Demo04_Template.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program Demo04 - template for type-customized container objects.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   This file defines a reusable template for creating lightweight container objects in Demo04.
;   The template allows type specialization by parameterizing:
;     - The object name
;     - The object ID
;     - The underlying data type stored internally
;
;   Each generated container object:
;     - Inherits from Primer
;     - Defines a single internal variable of the specified type
;     - Implements Init and Done methods for customized initialization and destruction
;
;   Demo04 uses this template to create several container types (BYTE, WORD, DWORD, QWORD, XWORD),
;   demonstrating type-safe storage and initialization using ObjAsm's metaprogramming features.
;
; ==================================================================================================


TContainer macro T_Name:req, T_ID:req, T_Type:req

Object T_Name, T_ID, Primer
  RedefineMethod    Done
  RedefineMethod    Init, POINTER

  DefineVariable    T_Data, T_Type, 0
ObjectEnd


.code
; ==================================================================================================
;    T_Name implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     T_Name.Init
; Purpose:    Initialize the container object.
; Arguments:  Arg1 -> Pointer to the owner object.
; Return:     Nothing.

Method T_Name.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].T_Data, sizeof(T_Type)              ; Assign an initial value based on the type size
  mov $SubReg(xax, sizeof(T_Type)), 20          ; Set value into a matching register size
MethodEnd


; --------------------------------------------------------------------------------------------------
; Method:     T_Name.Done
; Purpose:    Finalize (destruct) the container object.
; Arguments:  None.
; Return:     Nothing.

Method T_Name.Done, uses xsi
  SetObject xsi
  DbgHex T_Type ptr [xsi].T_Data                ; Display internal data for debugging purposes
  ACall xsi.Done
MethodEnd

endm