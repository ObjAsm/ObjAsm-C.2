; ==================================================================================================
; Title:      BStrAlloc.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrAlloc
; Purpose:    Allocate space for a BStr with n characters. The length field is set to zero.
; Arguments:  Arg1: Character count.
; Return:     rax -> New allocated BStr or NULL if failed.

.code
align ALIGN_CODE
BStrAlloc proc dCharCount:DWORD                         ;ecx = dChars
  lea rdx, [2*rcx + 6]                                  ;Convert to word sized & add DWORD + ZTC
  invoke GlobalAlloc, 0, rdx                            ;GMEM_FIXED = 0
  .if rax != NULL
    m2z DWORD ptr [rax]                                 ;Set length field to zero
    add rax, 4                                          ;Point to the WIDE character array
  .endif
  ret
BStrAlloc endp

end
