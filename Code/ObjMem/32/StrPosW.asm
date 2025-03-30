; ==================================================================================================
; Title:      StrPosW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrPosW
; Purpose:    Find the occurence of string2 into string1.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: -> Searched WIDE string.
; Return:     eax -> string occurence or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrPosW proc pString1W:POINTER, pString2W:POINTER
  push edi
  push esi
  push ebx
  invoke StrLengthW, [esp + 20]                         ;pString2W -> searched string
  test eax, eax
  je @@Exit                                             ;Returns eax = NULL
  mov ebx, eax                                          ;ebx = length of the searched string

  invoke StrLengthW, [esp + 16]                         ;pString1W -> string to look in
  mov ecx, eax
  sub ecx, ebx
  inc ecx
  jb @@2

  mov edi, [esp + 16]                                   ;edi -> pString1W
@@1:
  mov esi, [esp + 20]                                   ;esi -> pString2W
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
  ret 8
StrPosW endp

OPTION PROC:DEFAULT

end
