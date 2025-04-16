; ==================================================================================================
; Title:      Demo04_Template.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 4.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


TContainer macro T_Name:req, T_ID:req, T_Type:req 

Object T_Name, T_ID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,         POINTER
  
  DefineVariable    Internal,     T_Type,     0
ObjectEnd


.code
; ==================================================================================================
;    T_Name implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     T_Name.Init
; Purpose:    Initialize the object.
; Arguments:  Arg1 -> Owner.
; Return:     Nothing.

Method T_Name.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].Internal, sizeof(T_Type)                    ;Some value
  mov $SubReg(xax, sizeof(T_Type)), 20                  ;Set a value on a matching register
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     T_Name.Done
; Purpose:    Destructor
; Arguments:  None.
; Return:     Nothing.

Method T_Name.Done, uses xsi
  SetObject xsi
  DbgHex T_Type ptr [xsi].Internal
  ACall xsi.Done
MethodEnd

endm