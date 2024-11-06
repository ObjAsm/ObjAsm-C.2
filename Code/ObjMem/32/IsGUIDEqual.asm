; ==================================================================================================
; Title:      IsGUIDEqual.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsGUIDEqual
; Purpose:    Compare 2 GUIDs.
; Arguments:  Arg1: -> GUID1
;             Arg2: -> GUID2.
; Return:     eax = TRUE if they are equal, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsGUIDEqual proc pGUID1:POINTER, pGUID2:POINTER
  mov eax, [esp + 4]
  mov ecx, [esp + 8]
  mov edx, DWORD ptr [eax]
  cmp edx, DWORD ptr [ecx]
  jne @F
  mov edx, DWORD ptr [eax + 4]
  cmp edx, DWORD ptr [ecx + 4]
  jne @F
  mov edx, DWORD ptr [eax + 8]
  cmp edx, DWORD ptr [ecx + 8]
  jne @F
  mov edx, DWORD ptr [eax + 12]
  cmp edx, DWORD ptr [ecx + 12]
  jne @F
  mov eax, TRUE
  ret 8
@@:
  xor eax, eax
  ret 8
IsGUIDEqual endp

OPTION PROC:DEFAULT

end
