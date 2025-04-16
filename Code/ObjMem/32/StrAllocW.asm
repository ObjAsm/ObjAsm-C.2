; ==================================================================================================
; Title:      StrAllocW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrAllocW
; Purpose:    Allocate space for a WIDE string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     eax -> New allocated WIDE string or NULL if failed.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrAllocW proc dChars:DWORD
  mov eax, [esp + 4]                                    ;eax = dChars
  lea ecx, [2*eax + 2]                                  ;Make room for the ZTC & convert
  invoke GlobalAlloc, 0, ecx                            ;GMEM_FIXED
  m2z WORD ptr [eax]
  ret 4
StrAllocW endp

OPTION PROC:DEFAULT

end
