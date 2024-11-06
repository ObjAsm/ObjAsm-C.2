; ==================================================================================================
; Title:      bin2qwordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

NextCharW macro
  movzx ecx, CHRW ptr [ebx]
  add ebx, 2
  sub ecx, CHRW ptr "0"
  cmp ecx, 1
  ja @F
  rcl eax, 1
  rcl edx, 1                                            ;Pass the carry from prev operation
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2qwordW
; Purpose:    Compute a WIDE string binary representation of a QWORD.
; Arguments:  Arg1: -> WIDE binary string.
; Return:     edx::eax = QWORD.

OPTION PROC:NONE

.code
align ALIGN_CODE
bin2qwordW proc pBuffer:POINTER
  push ebx
  xor eax, eax
  xor edx, edx
  not eax
  mov ebx, [esp + 8]
  not edx
  repeat 64
    NextCharW
  endm
@@:
  not eax
  not edx
  pop ebx
  ret 4
bin2qwordW endp

OPTION PROC:DEFAULT

end
