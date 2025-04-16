; ==================================================================================================
; Title:      StrLRTrimW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLRTrimW
; Purpose:    Trim blank characters from the beginning and the end of a WIDE string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLRTrimW proc pBuffer:POINTER, pSrcStringW:POINTER
  mov ecx, [esp + 8]                                    ;ecx -> SrcStringW
@@1:
  mov ax, [ecx]
  add ecx, 2
  cmp ax, ' '                                           ;Loop if space
  je @@1
  cmp ax, 9                                             ;Loop if tab
  je @@1
  cmp ax, 0                                             ;Return empty string if zero
  jne @@2
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov [edx], ax
  ret 8
align ALIGN_CODE
@@2:
  sub ecx, 2
  push ecx
  invoke StrEndW, ecx
align ALIGN_CODE
@@3:
  sub eax, 2
  mov cx, [eax]
  cmp cx, ' '                                           ;Loop if space
  je @@3
  cmp cx, 9                                             ;Loop if tab
  je @@3
  pop ecx
  sub eax, ecx
  add eax, 2
  mov edx, [esp + 4]
  .if edx != ecx
    push eax
    invoke MemClone, edx, ecx, eax
    pop eax
  .endif
  add eax, [esp + 4]
  m2z WORD ptr [eax]                                    ;Set ZTC
  ret 8
StrLRTrimW endp

OPTION PROC:DEFAULT

end
