; ==================================================================================================
; Title:      BStrLRTrim.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrLRTrim
; Purpose:    Trim blank characters from the beginning and the end of a BStr.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrLRTrim proc uses edi esi pDstBStr:POINTER, pSrcBStr:POINTER
  mov esi, pSrcBStr                                     ;esi -> ScrBStr
@@1:
  lodsw
  cmp ax, 32                                            ;Loop if space
  je @@1
  cmp ax, 9                                             ;Loop if tab
  je @@1
  cmp ax, 0                                             ;Return empty string if zero
  jne @@2
  mov edi, pDstBStr                                     ;edi -> DstBStr
  xor ecx, ecx
  jmp @@4
@@2:
  lea edi, [esi - 2]
  push edi
  mov ecx, 0FFFFFFFFH
  xor eax, eax
  repne scasw                                           ;Get string length including zero
  not ecx
  lea esi, [edi - 4]
  std
@@3:
  lodsw
  dec ecx
  cmp ax, 32                                            ;Loop if space
  je @@3
  cmp ax, 9                                             ;Loop if tab
  je @@3
  cld
  pop esi                                               ;Move the rest of the string
  mov edi, pDstBStr
  push ecx
  rep movsw
  pop ecx
@@4:
  xor eax, eax
  stosw                                                 ;Set ZTC
  mov edi, pDstBStr
  mov DWORD ptr [edi - 4], ecx
  ret
BStrLRTrim endp

end
