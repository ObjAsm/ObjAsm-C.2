; ==================================================================================================
; Title:      BStrRight.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrRight
; Purpose:    Copy the right n characters from the source string into the destination buffer.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
;             Arg3: Character count.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrRight proc pDstBStr:POINTER, pSrcBStr:POINTER, dCharCount:DWORD
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov eax, DWORD ptr [ecx - 4]                          
  shl DWORD ptr [esp + 12], 1                           ;dCharCount
  cmp eax, [esp + 12]                                   ;dCharCount
  jle @F                                                
  mov eax, [esp + 12]                                   ;dCharCount
@@:                                                       
  mov edx, DWORD ptr [ecx - 4]                          ;Compute position
  sub edx, eax                                          
  add edx, ecx                                          
  push eax                                              
  invoke MemShift, POINTER ptr [esp + 16], edx, eax     ;Move string; pDstBStr
  pop eax                                               
  mov edx, [esp + 4]                                    ;pDstBStr
  mov DWORD ptr [edx - 4], eax                          ;Store length
  add edx, eax                                          
  m2z WORD ptr [edx]                                    ;Set ZTC
  shr eax, 1                                            ;Return character count
  ret 12
BStrRight endp

OPTION PROC:DEFAULT

end
