; ==================================================================================================
; Title:      BStrLRTrim.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrLRTrim
; Purpose:    Trim blank characters from the beginning and the end of a BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrLRTrim proc pDstBStr:POINTER, pSrcBStr:POINTER      ;rcx -> DstBStr, rdx -> SrcBStr
  push rdi
  push rsi
  mov r8, rcx                                           ;r8 -> DstBStr
  mov rsi, rdx                                          ;rsi -> ScrBStr
@@1:
  lodsw
  cmp ax, 32                                            ;Loop if space
  je @@1
  cmp ax, 9                                             ;Loop if tab
  je @@1
  cmp ax, 0                                             ;Return empty string if zero
  jne @@2
  xor r9, r9
  jmp @@4
@@2:
  lea rdi, [rsi - 2]
  mov ecx, 0FFFFFFFFH
  mov r9, rdi
  xor eax, eax
  repne scasw                                           ;Compare ax with word at rdi and set status flags
  not ecx                                               ;Get string length including ZTC
  lea rsi, [rdi - 4]
  std
@@3:
  lodsw                                                 ;Load word at address rsi into ax
  dec ecx
  cmp ax, 32                                            ;Loop if space
  je @@3
  cmp ax, 9                                             ;Loop if tab
  je @@3
  cld
  mov rsi, r9                                           ;Move the rest of the string
  mov rdi, r8
  mov r9d, ecx
  rep movsw
@@4:
  xor eax, eax
  stosw                                                 ;Set ZTC
  mov DWORD ptr [r8 - 4], r9d
  pop rsi
  pop rdi
  ret
BStrLRTrim endp

OPTION PROC:DEFAULT

end
