; ==================================================================================================
; Title:      StrLengthW_AVX.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop
TARGET_CPU_SIMD_FEATURES = TARGET_CPU_SIMD_FEATURES or CPU_FEATURE_SIMD_AVX

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLengthW_AVX
; Purpose:    Determine the length of a WIDE string not including the zero terminating character.
; Arguments:  Arg1: -> Wide string.
; Return:     eax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthW_AVX proc pStringW:POINTER
  invoke StrSizeW_AVX, POINTER ptr [esp + 4]
  shr eax, 1
  dec eax
  ret 4
StrLengthW_AVX endp
OPTION PROC:DEFAULT

end
