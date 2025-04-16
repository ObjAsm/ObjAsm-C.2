; ==================================================================================================
; Title:      StrCPosA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCPosA
; Purpose:    Scan for ANSI string2 into ANSI string1 with length limitation.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: -> ANSI string to search for.
;             Arg3: Maximal character count.
; Return:     eax -> String position or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCPosA proc pString1A:POINTER, pString2A:POINTER, dMaxChars:DWORD
  push edi
  push esi
  push ebx
  invoke StrLengthA, [esp + 20]                         ;pString2 -> searched string
  test eax, eax
  je @@Exit                                             ;Returns eax = NULL
  mov ebx, eax                                          ;ebx = length of the searched string

  invoke StrCLengthA, [esp + 20], [esp + 24]            ;pString1A -> string to look in
  mov ecx, eax
  sub ecx, ebx
  inc ecx
  jb @@2

  mov edi, [esp + 16]                                   ;edi -> String1A
@@1:
  mov esi, [esp + 20]                                   ;esi -> String2A
  lodsb
  repne scasb                                           ;Search for first character
  jne @@2                                               ;Not found => Exit
  push edi
  push ecx
  lea ecx, [ebx - 1]
  repe cmpsb                                            ;Check for the rest of the string
  pop ecx
  pop edi
  jne @@1                                               ;Not equal => try next character
  lea eax, [edi - 1]                                    ;Found, return position
  jmp @@Exit

align ALIGN_CODE
@@2:
  xor eax, eax
@@Exit:
  pop ebx
  pop esi
  pop edi
  ret 12
StrCPosA endp

OPTION PROC:DEFAULT

end
