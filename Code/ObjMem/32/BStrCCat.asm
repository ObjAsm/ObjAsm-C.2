; ==================================================================================================
; Title:      BStrCCat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
  mov ecx, pDstBStr
  mov edx, dMaxChars
  shl edx, 1                                            ; edx = dMaxChars in BYTEs
  mov eax, DWORD ptr [ecx - 4]                          ; Get current BYTEs in BSTR
  .if eax < edx                                         ; Check max char count
    sub edx, eax
    mov eax, pSrcBStr
    mov eax, [eax - 4]
    cmp edx, eax
    cmova edx, eax
    mov eax, [ecx - 4]
    add [ecx - 4], edx
    add ecx, eax 
    mov WORD ptr [ecx + edx], 0
    invoke MemClone, ecx, [esp + 16], edx
  .endif
  ret 12
BStrCCat endp

end
