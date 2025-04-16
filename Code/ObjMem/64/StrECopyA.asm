; ==================================================================================================
; Title:      StrECopyA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrECopyA
; Purpose:    Copy an ANSI string to a buffer and return the address of the ZTC.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination ANSI character string.
;             Arg2: -> Source ANSI string.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrECopyA proc uses rbx pDstStrA:POINTER, pSrcStrA:POINTER
  invoke StrSizeA, rdx                                  ;pSrcStrA
  mov rbx, rax
  invoke MemShift, pDstStrA, pSrcStrA, eax
  mov rcx, pDstStrA
  lea rax, [rcx + rbx - sizeof CHRA]
  ret
StrECopyA endp

end
