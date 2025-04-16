; ==================================================================================================
; Title:      StrMidA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrMidA
; Purpose:    Extract a substring from an ANSI source string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Start character index. Index ranges [1 .. String length].
;             Arg3: Character count.
; Return:     eax = Number of copied characters.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrMidA proc pBuffer:POINTER, pSrcStringA:POINTER, dStartChar:DWORD, dCharCount:DWORD
  invoke StrLengthA, [esp + 8]
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
  add edx, [esp + 8]                                    ;pSrcStringA
  dec edx
  invoke MemShift, [esp + 12], edx, [esp + 16]
  mov eax, [esp + 16]                                   ;Set return value = number of copied chars
  mov edx, [esp + 4]
  add edx, eax
@@Exit:
  m2z BYTE ptr [edx]                                    ;Set ZTC
  ret 16
StrMidA endp

OPTION PROC:DEFAULT

end
