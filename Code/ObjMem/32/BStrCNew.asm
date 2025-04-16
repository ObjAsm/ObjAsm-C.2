; ==================================================================================================
; Title:      BStrCNew.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCNew
; Purpose:    Allocate a new copy of the source BStr with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, BStrCNew
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNew makes a duplicate
;             of the source string. The maximal size of the new string is limited to the second
;             parameter.
; Arguments:  Arg1: -> Source BStr.
;             Arg2: Maximal character count.
; Return:     eax -> New BStr copy.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCNew proc pBStr:POINTER, dMaxChars:DWORD
  mov edx, [esp + 4]                                    ;edx -> BStr
  test edx, edx
  je @@1
  mov eax, [edx - 4]
  test eax, eax
  jne @@2
@@1:
  xor eax, eax
  ret 8
@@2:
  shl DWORD ptr [esp + 8], 1                            ;dMaxChars => BYTEs
  .if eax > [esp + 8]                                   ;dMaxChars
    mov eax, [esp + 8]                                  ;dMaxChars
  .endif
  push eax
  invoke BStrAlloc, eax
  pop ecx
  test eax, eax
  je @@Exit
  mov DWORD ptr [eax - 4], ecx                          ;Store BStr length
  m2z WORD ptr [eax + ecx]                              ;Set zero terminator
  push eax
  invoke MemClone, eax, [esp + 12], ecx                 ;Copy BStr content
  pop eax                                               ;eax -> WIDE character array
@@Exit:
  ret 8
BStrCNew endp

OPTION PROC:DEFAULT

end
