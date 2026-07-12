; ==================================================================================================
; Title:      BStrCNew.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCNew
; Purpose:    Allocate a new copy of the source BSTR with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, BStrCNew
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNew makes a duplicate
;             of the source string. The maximal size of the new string is limited to the second
;             parameter.
; Arguments:  Arg1: -> Source BSTR.
;             Arg2: Maximal character count.
; Return:     eax -> New BSTR copy.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCNew proc pBStr:POINTER, dMaxChars:DWORD
  mov eax, [esp + 4]                                    ; eax = pBStr
  .if eax != NULL
    mov edx, [esp + 8]                                  ; edx = dMaxChars
    mov ecx, DWORD ptr [eax - 4]                        ; ecx = bytes on pBStr                
    shr ecx, 1                                          ; ecx = # chars
    cmp ecx, edx                                        ; edx = dMaxChars
    cmova ecx, edx
    push ecx
    invoke BStrAlloc, ecx
    pop ecx
    .if eax != NULL
      push eax
      add ecx, ecx
      mov DWORD ptr [eax - 4], ecx
      push ecx
      push [esp + 12]                                   ; pBStr
      push [esp + 8]                                    ; New BSTR
      call MemClone                                     ; Copy string with limit
      pop ecx
      mov WORD ptr [ecx + eax], 0                       ; Set ZTC
      mov eax, ecx
    .endif
  .endif
  ret 8
BStrCNew endp

OPTION PROC:DEFAULT

end
