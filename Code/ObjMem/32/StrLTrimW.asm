; ==================================================================================================
; Title:      StrLTrimW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLTrimW
; Purpose:    Trim blank characters from the beginning of a WIDE string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLTrimW proc pBuffer:POINTER, pSrcStringW:POINTER
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
  invoke StrLengthW, ecx
  add eax, 2                                            ;Include ZTC
  pop ecx
  invoke MemClone, [esp + 16], ecx, eax
  ret 8
StrLTrimW endp

OPTION PROC:DEFAULT

end
