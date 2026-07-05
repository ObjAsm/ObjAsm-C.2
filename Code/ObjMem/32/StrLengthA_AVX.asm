; ==================================================================================================
; Title:      StrLengthA_AVX.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop
TARGET_CPU_SIMD_FEATURES = TARGET_CPU_SIMD_FEATURES or CPU_FEATURE_SIMD_AVX

; --------------------------------------------------------------------------------------------------
; Procedure: StrLengthA_AVX
; Purpose:   Determine the length of an ANSI string not including the zero terminating character.
; Arguments: Arg1: -> Source ANSI string.
; Return:    eax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthA_AVX proc pStringA:POINTER
  invoke StrSizeA_AVX, POINTER ptr [esp + 4]
  dec eax
  ret 4
StrLengthA_AVX endp
OPTION PROC:DEFAULT

end
