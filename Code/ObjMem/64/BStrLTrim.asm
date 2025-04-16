; ==================================================================================================
; Title:      BStrLTrim.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrLTrim
; Purpose:    Trim blank characters from the beginning of a BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrLTrim proc pDstBStr:POINTER, pSrcBStr:POINTER
  push rdi
  push rsi
  mov rsi, rdx                                          ;rsi -> SrcBStr
  mov r8, rcx                                           ;r8 -> DstBStr
@@:
  lodsw
  cmp ax, 32                                            ;Loop if space
  je @B
  cmp ax, 9                                             ;Loop if tab
  je @B

  lea rdi, [rsi - 2]                                    ;Get a pointer to first character
  mov r9, rdi
  mov ecx, 0FFFFFFFFH
  xor eax, eax
  repne scasw                                           ;Get string length including zero
  not rcx
  mov rsi, r9
  mov rdi, r8                                           ;rdi -> DstBStr
  mov r9d, ecx
  rep movsw                                             ;Move rest of the string
  dec r9d
  dec r9d                                               ;Don't count ZTC
  mov DWORD ptr [r8 - 4], r9d
  pop rsi
  pop rdi
  ret
BStrLTrim endp

OPTION PROC:DEFAULT

end
