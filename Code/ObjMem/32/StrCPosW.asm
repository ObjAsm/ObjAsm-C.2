; ==================================================================================================
; Title:      StrCPosW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCPosW
; Purpose:    Scan from the beginning of a WIDE string for a character.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Character to search for.
; Return:     eax -> Character position or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCPosW proc pString1W:POINTER, pString2W:POINTER, dMaxChars:DWORD
  push edi
  push esi
  push ebx
  invoke StrLengthW, [esp + 20]                         ;pString2W -> searched string
  test eax, eax
  je @@Exit                                             ;Returns eax = NULL
  mov ebx, eax                                          ;ebx = length of the searched string

  invoke StrCLengthW, [esp + 20], [esp + 24]            ;pString1W -> string to look in
  mov ecx, eax
  sub ecx, ebx
  inc ecx
  jb @@2

  mov edi, [esp + 16]                                   ;edi -> String1W
@@1:
  mov esi, [esp + 20]                                   ;esi -> String2W
  lodsw
  repne scasw                                           ;Search for first character
  jne @@2                                               ;Not found => Exit
  push edi
  push ecx
  lea ecx, [ebx - 1]
  repe cmpsw                                            ;Check for the rest of the string
  pop ecx
  pop edi
  jne @@1                                               ;Not equal => try next character
  lea eax, [edi - 2]                                    ;Found, return position
  jmp @@Exit

align ALIGN_CODE
@@2:
  xor eax, eax
@@Exit:
  pop ebx
  pop esi
  pop edi
  ret 12
StrCPosW endp

OPTION PROC:DEFAULT

end
