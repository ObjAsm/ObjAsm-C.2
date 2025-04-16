; ==================================================================================================
; Title:      BStrCCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCCatChar
; Purpose:    Append a WIDE character to a BStr with length limitation.
; Arguments:  Arg1: -> Destination BStr.
;             Arg2: -> WIDE character.
; Return:     rax -> BStr or NULL if failed.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCCatChar proc pDstBStr:POINTER, wChar:CHRW, dMaxChars:DWORD   
  ;rcx -> DstBStr, dx = wChar, r8 = dMaxChars
  shl r8, 1                                             ;r8 = dMaxChars in BYTEs
  mov r9d, DWORD ptr [rcx - 4]
  xor eax, eax
  cmp r8d, r9d
  jb @F                                                 ;Destination is full => return NULL
  add r9, 2
  mov DWORD ptr [rcx - 4], r9d                          ;Increment length
  mov DWORD ptr [rcx + r9], edx                         ;Write character and ZTC
  mov rax, rcx                                          ;Return -> BStr
@@:
  ret
BStrCCatChar endp

OPTION PROC:DEFAULT

end
