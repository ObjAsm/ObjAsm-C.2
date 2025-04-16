; ==================================================================================================
; Title:      StrECopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrECopyW
; Purpose:    Copy a WIDE string to a buffer and return the address of the ZTC.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination WIDE character string.
;             Arg2: -> Source WIDE string.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrECopyW proc uses rbx pDstStrW:POINTER, pSrcStrW:POINTER
  invoke StrSizeW, rdx                                  ;pSrcStrW
  mov rbx, rax
  invoke MemShift, pDstStrW, pSrcStrW, eax
  mov rcx, pDstStrW
  lea rax, [rcx + rbx - sizeof CHRW]
  ret
StrECopyW endp

end
