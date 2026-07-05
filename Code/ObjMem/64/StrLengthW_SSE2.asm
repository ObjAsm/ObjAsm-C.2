; ==================================================================================================
; Title:      StrLengthW_SSE2.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop
TARGET_CPU_SIMD_FEATURES = TARGET_CPU_SIMD_FEATURES or CPU_FEATURE_SIMD_SSE2
TARGET_CPU_FEATURES = TARGET_CPU_FEATURES or (CPU_FEATURE_FPU or CPU_FEATURE_CX8 or CPU_FEATURE_CLFLUSH)

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLengthW_SSE2
; Purpose:    Determine the length of a WIDE string not including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Length of the string in characters.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrLengthW_SSE2 proc pStringW:POINTER
  invoke StrSizeW_SSE2, rcx
  shr eax, 1
  dec eax
  ret
StrLengthW_SSE2 endp
OPTION PROC:DEFAULT

end
