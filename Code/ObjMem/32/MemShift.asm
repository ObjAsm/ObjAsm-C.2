; ==================================================================================================
; Title:      MemShift.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemShift
; Purpose:    Copy a memory block from a source to a destination buffer.
;             Source and destination may overlap.
;             Destination buffer must be at least as large as number of BYTEs to shift, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source buffer.
;             Arg3: Number of BYTEs to shift.
; Return:     eax = Number of BYTEs shifted.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemShift proc pDstMem:POINTER, pSrcMem:POINTER, dByteCount:DWORD
  push edi
  push esi
  mov edi, [esp + 12]                                   ;edi -> DstMem
  mov esi, [esp + 16]                                   ;esi -> SrcMem
  mov ecx, [esp + 20]                                   ;ecx = dByteCount
  cmp esi, edi
  jae @@1
  std
  lea esi, [esi + ecx - 4]
  lea edi, [edi + ecx - 4]
  shr ecx, 2
  rep movsd
  mov ecx, [esp + 20]                                   ;ecx = dByteCount
  mov eax, ecx                                          ;Return value: eax = dByteCount 
  and ecx, 3
  add edi, 3
  add esi, 3
  rep movsb
  cld
  pop esi
  pop edi
  ret 12

align ALIGN_CODE
@@1:
  shr ecx, 2
  rep movsd
  mov ecx, [esp + 20]                                   ;ecx = dByteCount
  mov eax, ecx                                          ;Return value: eax = dByteCount 
  and ecx, 3
  rep movsb
  pop esi
  pop edi
  ret 12
MemShift endp

OPTION PROC:DEFAULT

end
