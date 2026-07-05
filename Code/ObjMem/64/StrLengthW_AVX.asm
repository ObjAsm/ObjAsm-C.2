; ==================================================================================================
; Title:      StrLengthW_AVX.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop
TARGET_CPU_SIMD_FEATURES = TARGET_CPU_SIMD_FEATURES or CPU_FEATURE_SIMD_AVX
TARGET_CPU_FEATURES = TARGET_CPU_FEATURES or (CPU_FEATURE_FPU or CPU_FEATURE_CX8 or CPU_FEATURE_CLFLUSH)

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLengthW_AVX
; Purpose:    Determine the length of a WIDE string not including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthW_AVX proc pStringW:POINTER
  invoke StrSizeW_AVX, rcx
  shr eax, 1
  dec eax
  ret
StrLengthW_AVX endp
OPTION PROC:DEFAULT

end