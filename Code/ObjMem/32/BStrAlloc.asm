; ==================================================================================================
; Title:      BStrAlloc.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrAlloc
; Purpose:    Allocate space for a BStr with n characters. The length field is set to zero.
; Arguments:  Arg1: Character count.
; Return:     eax -> New allocated BStr or NULL if failed.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrAlloc proc dChars:DWORD
  mov ecx, [esp + 4]                                    ;ecx = dChars
  lea edx, [2*ecx + 6]                                  ;Convert to word sized & add DWORD + ZTC
  invoke GlobalAlloc, 0, edx                            ;GMEM_FIXED = 0
  .if eax != NULL
    m2z DWORD ptr [eax]                                 ;Set length field to zero
    add eax, 4                                          ;Point to the WIDE character array
  .endif
  ret 4
BStrAlloc endp

OPTION PROC:DEFAULT

end
