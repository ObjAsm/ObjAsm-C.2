; ==================================================================================================
; Title:      StrLRTrimA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLRTrimA
; Purpose:    Trim blank characters from the beginning and the end of an ANSI string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLRTrimA proc pBuffer:POINTER, pSrcStringA:POINTER
  mov ecx, [esp + 8]                                    ;ecx -> SrcStringA
@@1:
  mov al, [ecx]
  inc ecx
  cmp al, ' '                                           ;Loop if space
  je @@1
  cmp al, 9                                             ;Loop if tab
  je @@1
  cmp al, 0                                             ;Return empty string if zero
  jne @@2
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov [edx], al
  ret 8
align ALIGN_CODE
@@2:
  dec ecx
  push ecx
  invoke StrEndA, ecx
align ALIGN_CODE
@@3:
  dec eax
  mov cl, [eax]
  cmp cl, ' '                                           ;Loop if space
  je @@3
  cmp cl, 9                                             ;Loop if tab
  je @@3
  pop ecx
  sub eax, ecx
  inc eax
  mov edx, [esp + 4]
  .if edx != ecx
    push eax
    invoke MemClone, edx, ecx, eax
    pop eax
  .endif
  add eax, [esp + 4]
  m2z BYTE ptr [eax]                                    ;Set ZTC
  ret 8
StrLRTrimA endp

OPTION PROC:DEFAULT

end
