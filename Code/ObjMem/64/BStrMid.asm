; ==================================================================================================
; Title:      BStrMid.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrMid
; Purpose:    Extract a substring from a BStr string.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source Bstr.
;             Arg3: Start character index. Index ranges [0 .. length-1].
;             Arg3: Character count.
; Return:     eax = String length.

.code
align ALIGN_CODE
BStrMid proc pDstBStr:POINTER, pSrcBStr:POINTER, dStartChar:DWORD, dCharCount:DWORD
  ;rcx -> DstBStr, rdx -> SrcBStr, r8d = dStartChar, r9d = dCharCount
  mov rcx, pSrcBStr
  mov eax, DWORD ptr [rcx - sizeof(DWORD)]
  .if eax <= dStartChar
    mov rdx, pDstBStr                                   ;Source too small; rdx -> DstBStr
    xor eax, eax
    xor ecx, ecx
  .else
    mov edx, dStartChar
    push rdx
    add edx, dCharCount
    .if edx <= eax                                      ;Compare with Length
      sub ecx, dStartChar
      mov dCharCount, ecx
    .endif
    pop rdx
    dec edx
    shl edx, 1
    add rdx, pSrcBStr
    mov r8d, dCharCount                                 ;Set return value
    push r8
    shl r8, 1
    push r8
    invoke MemShift, pDstBStr, rdx, r8d                 ;pDstBStr
    mov rdx, pDstBStr
    pop rcx
    add rdx, rcx
    pop rax                                             ;Returns character count
  .endif
  m2z CHRW ptr [rdx]                                    ;Set ZTC
  mov rdx, pDstBStr
  mov DCHRW ptr [rdx - sizeof(DCHRW)], ecx
  ret
BStrMid endp

end
