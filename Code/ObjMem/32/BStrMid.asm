; ==================================================================================================
; Title:      BStrMid.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrMid
; Purpose:    Extract a substring from a BStr string.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source Bstr.
;             Arg3: Start character index. Index ranges [1 .. String length].
;             Arg3: Character count.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrMid proc pDstBStr:POINTER, pSrcBStr:POINTER, dStart:DWORD, dCount:DWORD
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov eax, DWORD ptr [ecx - 4]                          
  cmp dStart, eax                                       
  jna @@1                                               
  mov edx, [esp + 4]                                    ;Source too small; edx -> DstBStr
  xor eax, eax                                          
  xor ecx, ecx                                          
  jmp @@Exit                                            
@@1:                                                      
  mov edx, [esp + 12]                                   ;edx = dStart
  push edx                                              
  add edx, [esp + 20]                                   ;dCount
  cmp edx, eax                                          ;Compare with Length
  jna @@2                                               
  sub ecx, [esp + 16]                                   ;dStart
  mov [esp + 20], ecx                                   ;Store in dCount
@@2:                                                      
  pop edx                                               
  dec edx                                               
  shl edx, 1                                            
  add edx, [esp + 8]                                    ;pSrcBStr
  mov eax, [esp + 16]                                   ;Set return value   eax = dCount
  push eax                                              
  shl eax, 1                                            
  push eax                                              
  invoke MemShift, [esp + 20], edx, eax                 ;pDstBStr
  mov edx, [esp + 12]                                   ;edx -> DstBStr
  pop ecx                                               
  add edx, ecx                                          
  pop eax                                               ;Returns character count
@@Exit:                                                   
  m2z CHRW ptr [edx]                                    ;Set ZTC
  mov edx, [esp + 4]                                    ;edx -> DstBStr
  mov DWORD ptr [edx - 4], ecx
  ret 16
BStrMid endp

OPTION PROC:DEFAULT

end
