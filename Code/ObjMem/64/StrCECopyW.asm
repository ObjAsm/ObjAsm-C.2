; ==================================================================================================
; Title:      StrCECopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCECopyW
; Purpose:    Copy the the source WIDE string with length limitation and return the ZTC address.
;             The destination buffer should hold the maximum number of characters + 1.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of characters not including the ZTC.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrCECopyW proc uses rbx pDstStrW:POINTER, pSrcStrW:POINTER, dMaxChars:DWORD
  invoke StrCLengthW, rdx, r8d                          ;pSrcStrW, dMaxChars
  shl rax, 1
  mov rbx, rax
  invoke MemShift, pDstStrW, pSrcStrW, eax
  mov rcx, pDstStrW
  lea rax, [rcx + rbx]
  m2z CHRW ptr [rax]                                    ;Set ZTC after mem shifting
  ret
StrCECopyW endp

end
