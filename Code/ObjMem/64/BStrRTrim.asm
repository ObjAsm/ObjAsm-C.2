; ==================================================================================================
; Title:      BStrRTrim.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrRTrim
; Purpose:    Trim blank characters from the end of a BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrRTrim proc pDstBStr:POINTER, pSrcBStr:POINTER
  push rdi
  push rsi
  xor eax, eax
  mov r8, rcx                                           ;r8 -> DstBStr
  mov rdi, rdx                                          ;rdi -> SrcBStr
  mov ecx, 0FFFFFFFFH
  repne scasw                                           ;Get string length excluding zero
  not ecx
  lea rsi, [rdi - 4]                                    ;Get pointer to last character
  std
@@:
  lodsw
  dec ecx
  cmp ax, " "                                           ;Loop if space
  je @B
  cmp ax, 9                                             ;Loop if tab
  je @B
  cld
  mov rsi, rdx                                          ;rsi -> SrcBStr
  mov rdi, r8                                           ;rdi -> DstBStr
  mov DWORD ptr [rdi - 4], ecx
  rep movsw
  mov CHRW ptr [rdi], 0                                 ;Set ZTC
  pop rsi
  pop rdi
  ret
BStrRTrim endp

OPTION PROC:DEFAULT

end
