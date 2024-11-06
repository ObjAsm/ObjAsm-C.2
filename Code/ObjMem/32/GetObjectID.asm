; ==================================================================================================
; Title:      GetObjectID.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetObjectID
; Purpose:    Retrieve the type ID of an object instance.
; Arguments:  Arg1: -> Object instance.
; Return:     eax = Object class ID.

OPTION PROC:NONE

.code
align ALIGN_CODE
GetObjectID proc pObjectInstance:POINTER
  mov eax, [esp + 4]                                    ;pObjectInstance
  test eax, eax
  jz @F
  mov edx, [eax]                                        ;edx -> DMT
  mov ecx, [edx - sizeof(POINTER)]                      ;ecx -> ETT
  mov eax, [ecx - 2*sizeof(DWORD)]                      ;eax = Object type ID
@@:
  ret 4
GetObjectID endp

OPTION PROC:DEFAULT

end
