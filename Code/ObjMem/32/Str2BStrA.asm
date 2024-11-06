; ==================================================================================================
; Title:      Str2BStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Str2BStrA
; Purpose:    Convert a ANSI string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof DWORD.
;             Arg2: -> Source ANSI string.
; Return:     Nothing.

.code
align ALIGN_CODE
Str2BStrA proc uses edi esi pDstBStr:POINTER, pSrcStrA:POINTER
  mov edi, pDstBStr
  mov esi, pSrcStrA
  invoke StrLengthA, esi
  mov ecx, eax
  add esi, eax
  inc ecx
  shl eax, 1
  push eax
  add edi, eax
  xor eax, eax
  std
@@:
  lodsb
  stosw
  dec ecx
  test ecx, ecx
  jne @B
  cld
  pop eax
  mov edi, pDstBStr
  mov DWORD ptr [edi - 4], eax
  shr eax, 1
  ret
Str2BStrA endp

end
