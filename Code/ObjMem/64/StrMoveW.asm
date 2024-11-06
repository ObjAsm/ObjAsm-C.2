; ==================================================================================================
; Title:      StrMoveW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrMoveW
; Purpose:    Move part of a WIDE string. The ZTC is NOT appended automatically.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Character count.
; Return:     Nothing.

.code
align ALIGN_CODE
StrMoveW proc pDstStringW:POINTER, pSrcStringW:POINTER, dCharCount:DWORD
  mov eax, r8d                                          ;dCharCount
  shl eax, 1
  invoke MemShift, rcx, rdx, eax                        ;pDstStringW, pSrcStringW
  ret
StrMoveW endp

end
