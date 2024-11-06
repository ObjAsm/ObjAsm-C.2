; ==================================================================================================
; Title:      StrMidW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrMidW
; Purpose:    Extract a substring from a WIDE source string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Start character index. Index ranges [1 .. String length].
;             Arg3: Character count.
; Return:     eax = Number of copied characters.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrMidW proc pBuffer:POINTER, pSrcStringW:POINTER, dStartChar:DWORD, dCharCount:DWORD
  invoke StrLengthW, [esp + 8]
  mov ecx, eax
  inc ecx
  cmp eax, [esp + 12]                                   ;dStartChar
  jae @@1
  mov edx, [esp + 4]                                    ;Source too small
  xor eax, eax
  jmp @@Exit
align ALIGN_CODE
@@1:
  sub eax, [esp + 12]                                   ;dStartChar
  cmp eax, [esp + 16]                                   ;dCharCount
  jae @@2
  sub ecx, [esp + 12]                                   ;dStartChar
  mov [esp + 16], ecx                                   ;dCharCount
@@2:
  mov edx, [esp + 12]                                   ;dStartChar
  shl edx, 1
  add edx, [esp + 8]                                    ;pSrcStringW
  sub edx, 2
  mov ecx, [esp + 16]
  shl ecx, 1
  invoke MemShift, [esp + 12], edx, ecx
  mov eax, [esp + 16]                                   ;Set return value = number of copied chars
  mov edx, [esp + 4]
  lea edx, [edx + 2 * eax]
@@Exit:
  m2z WORD ptr [edx]                                    ;Set ZTC
  ret 16
StrMidW endp

OPTION PROC:DEFAULT

end
