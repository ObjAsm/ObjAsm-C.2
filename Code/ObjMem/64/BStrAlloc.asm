; ==================================================================================================
; Title:      BStrAlloc.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, November 2024
;               - Allocation done using SysAllocStringByteLen.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrAlloc
; Purpose:    Allocate space for a BString with n characters. The length field is set to zero.
; Arguments:  Arg1: Character count.
; Return:     rax -> New allocated BString or NULL if failed.

.code
align ALIGN_CODE
BStrAlloc proc dCharCount:DWORD                         ;ecx = dChars
  lea edx, [2*ecx + 6]                                  ;Convert to word sized & add DWORD + ZTC
  invoke SysAllocStringByteLen, NULL, edx
  .if rax != NULL
    m2z DWORD ptr [rax]                                 ;Set length field to zero
    add rax, 4                                          ;Point to the first WIDE character array
  .endif
  ret
BStrAlloc endp

end
