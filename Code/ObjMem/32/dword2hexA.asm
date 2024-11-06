; ==================================================================================================
; Title:      dword2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:BYTE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2hexA
; Purpose:    Convert a DWORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 9 BYTEs large to allocate the output string
;             (8 character BYTEs + ZTC = 9 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
dword2hexA proc pBuffer:POINTER, dValue:DWORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  lea ecx, [esp + 8]                                    ;ecx -> dValue
  movzx eax, BYTE ptr [ecx]
  mov ax, DCHRA ptr HexCharTableA[sizeof(DCHRA)*eax]
  m2z CHRA ptr [edx + 4*sizeof(DCHRA)]                  ;Set ZTC
  mov DCHRA ptr [edx + 3*sizeof(DCHRA)], ax
  movzx eax, BYTE ptr [ecx + 1]
  mov ax, DCHRA ptr HexCharTableA[sizeof(DCHRA)*eax]
  mov DCHRA ptr [edx + 2*sizeof(DCHRA)], ax
  movzx eax, BYTE ptr [ecx + 2]
  movzx ecx, BYTE ptr [ecx + 3]
  mov ax, DCHRA ptr HexCharTableA[sizeof(DCHRA)*eax]
  mov cx, DCHRA ptr HexCharTableA[sizeof(DCHRA)*ecx]
  mov DCHRA ptr [edx + 1*sizeof(DCHRA)], ax
  mov DCHRA ptr [edx + 0*sizeof(DCHRA)], cx
  ret 8
dword2hexA endp

OPTION PROC:DEFAULT

end
