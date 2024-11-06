; ==================================================================================================
; Title:      BStrRTrim.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrRTrim
; Purpose:    Trim blank characters from the end of a BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrRTrim proc uses edi esi pDstBStr:POINTER, pSrcBStr:POINTER
  mov edi, pSrcBStr                                     ;edi -> SrcBStr
  mov ecx, 0FFFFFFFFH
  xor eax, eax
  repne scasw                                           ;Get string length excluding zero
  not ecx
  lea esi, [edi - 4]                                    ;Get pointer to last character
  std
@@:
  lodsw
  dec ecx
  cmp ax, 32                                            ;Loop if space
  je @B
  cmp ax, 9                                             ;Loop if tab
  je @B
  cld
  mov esi, pSrcBStr                                     ;esi -> SrcBStr
  mov edi, pDstBStr                                     ;edi -> DstBStr
  mov DWORD ptr [edi - 4], ecx
  rep movsw
  mov WORD ptr [edi], 0                                 ;Set ZTC
  ret 8
BStrRTrim endp

end
