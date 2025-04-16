; ==================================================================================================
; Title:      StrCECopyA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCECopyA
; Purpose:    Copy the the source ANSI string with length limitation and return the ZTC address.
;             The destination buffer should hold the maximum number of characters + 1.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of characters not including the ZTC.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
StrCECopyA proc uses rbx pDstStrA:POINTER, pSrcStrA:POINTER, dMaxChars:DWORD
  invoke StrCLengthA, rdx, r8d                          ;pSrcStr, dMaxChars
  mov rbx, rax
  invoke MemShift, pDstStrA, pSrcStrA, eax
  mov rcx, pDstStrA
  lea rax, [rcx + rbx]
  m2z CHRA ptr [rax]                                    ;Set ZTC after mem shifting
  ret
StrCECopyA endp

end
