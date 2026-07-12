; ==================================================================================================
; Title:      BStrCCat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCCat
; Purpose:    Concatenate 2 BSTRs with length limitation.
;             The destination string buffer should have at least enough room for the maximum number
;             of characters + 1.
; Arguments:  Arg1: -> Destination BSTR.
;             Arg2: -> Source BSTR.
;             Arg3: Maximal number of charachters the destination string can hold excluding the ZTC.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrCCat proc pDstBStr:POINTER, pSrcBStr:POINTER, dMaxChars:DWORD
  shl r8d, 1                                            ; r8 = dMaxChars in BYTEs
  mov r9d, DWORD ptr [rcx - 4]                          ; Get current BYTEs in BSTR
  .if r9d < r8d                                         ; Check max char count
    sub r8d, r9d
    mov r10d, [rdx - 4]
    cmp r10d, r8d
    cmova r10d, r8d
    add [rcx - 4], r10d 
    add rcx, r9
    mov WORD ptr [rcx + r10], 0
    invoke MemClone, rcx, rdx, r10d
  .endif
  ret
BStrCCat endp

end
