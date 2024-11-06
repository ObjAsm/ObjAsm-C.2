; ==================================================================================================
; Title:      BStrLTrim.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrLTrim
; Purpose:    Trim blank characters from the beginning of a BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrLTrim proc uses edi esi pDstBStr:POINTER, pSrcBStr:POINTER
  mov esi, pSrcBStr                                     ;esi -> SrcBStr
@@:
  lodsw
  cmp ax, 32                                            ;Loop if space
  je @B
  cmp ax, 9                                             ;Loop if tab
  je @B

  lea edi, [esi - 2]                                    ;Get a pointer to first character
  push edi
  mov ecx, 0FFFFFFFFH
  xor eax, eax
  repne scasw                                           ;Get string length including zero
  not ecx
  pop esi
  mov edi, pDstBStr                                     ;edi -> DstBStr
  push edi
  push ecx
  rep movsw                                             ;Move rest of the string
  pop ecx
  pop edi
  dec ecx
  dec ecx                                               ;Don't count ZTC
  mov DWORD ptr [edi - 4], ecx
  ret
BStrLTrim endp

end
