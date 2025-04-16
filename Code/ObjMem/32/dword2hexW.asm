; ==================================================================================================
; Title:      dword2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:BYTE

; --------------------------------------------------------------------------------------------------
; Procedure:  dword2hexW
; Purpose:    Convert a DWORD to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 18 BYTEs large to allocate the output string
;             (8 character WORDs + ZTC = 18 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
dword2hexW proc pBuffer:POINTER, dValue:DWORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  lea ecx, [esp + 8]                                    ;ecx -> dValue
  movzx eax, BYTE ptr [ecx]
  mov eax, DCHRW ptr HexCharTableW[sizeof(DCHRW)*eax]
  m2z CHRW ptr [edx + 4*sizeof(DCHRW)]                  ;Set ZTC
  mov DCHRW ptr [edx + 3*sizeof(DCHRW)], eax
  movzx eax, BYTE ptr [ecx + 1]
  mov eax, DCHRW ptr HexCharTableW[sizeof(DCHRW)*eax]
  mov DCHRW ptr [edx + 2*sizeof(DCHRW)], eax
  movzx eax, BYTE ptr [ecx + 2]
  movzx ecx, BYTE ptr [ecx + 3]
  mov eax, DCHRW ptr HexCharTableW[sizeof(DCHRW)*eax]
  mov ecx, DCHRW ptr HexCharTableW[sizeof(DCHRW)*ecx]
  mov DCHRW ptr [edx + 1*sizeof(DCHRW)], eax
  mov DCHRW ptr [edx + 0*sizeof(DCHRW)], ecx
  ret 8
dword2hexW endp

OPTION PROC:DEFAULT

end
