; ==================================================================================================
; Title:      GetObjectID.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GetObjectID
; Purpose:    Retrieve the type ID of an object instance.
; Arguments:  Arg1: -> Object instance.
; Return:     eax = Object class ID.

OPTION PROC:NONE

.code
align ALIGN_CODE
GetObjectID proc pObjectInstance:POINTER
  or rcx, rcx
  jz @F
  mov rdx, [rcx]                                        ;rdx -> DMT
  mov rcx, [rdx - sizeof(POINTER)]                      ;rcx -> ETT
  mov eax, [rcx - 2*sizeof(DWORD)]                      ;eax = Object type ID
  ret
@@:
  xor eax, eax
  ret
GetObjectID endp

OPTION PROC:DEFAULT

end
