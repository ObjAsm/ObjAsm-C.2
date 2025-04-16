; ==================================================================================================
; Title:      BStrNew.asm
; Author:     G. Friedrich
; Version:    00000
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrNew
; Purpose:    Allocate an new copy of the source BStr.
;             If the pointer to the source string is NULL or points to an empty string, BStrNew
;             returns NULL and doesn't allocate any heap space. Otherwise, BStrNew makes a duplicate
;             of the source string.
;             The allocated space is Length(String) + 1 character.
; Arguments:  Arg1: -> Source BStr.
; Return:     eax -> New BStr copy.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrNew proc pBStr:POINTER
  mov eax, [esp + 4]                                    ;eax -> BStr
  test eax, eax
  jne @F
  ret 4
@@:
  mov edx, [eax - 4]
  push edx
  invoke BStrAlloc, edx
  pop ecx
  test eax, eax
  je @F                                                 ;Allocation failed
  mov edx, [esp + 4]                                    ;edx -> BStr
  push eax
  add ecx, 6                                            ;Lenght DWORD + ZTC
  sub edx, 4 
  sub eax, 4
  invoke MemClone, eax, edx, ecx
  pop eax                                               ;eax -> WIDE character array
@@:
  ret 4
BStrNew endp

OPTION PROC:DEFAULT

end
