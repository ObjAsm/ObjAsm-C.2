; ==================================================================================================
; Title:      qword2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:BYTE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2hexA
; Purpose:    Convert a QWORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 17 BYTEs large to allocate the output string
;             (16 character BYTEs + ZTC = 17 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
qword2hexA proc pBuffer:POINTER, qValue:QWORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  lea ecx, [esp + 8]                                    ;ecx -> qValue

  movzx eax, BYTE ptr [ecx]
  m2z BYTE ptr [edx + 16]                               ;Set ZTC
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 14], ax

  movzx ax, BYTE ptr [ecx + 1]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 12], ax

  movzx ax, BYTE ptr [ecx + 2]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 10], ax

  movzx ax, BYTE ptr [ecx + 3]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 08], ax

  movzx ax, BYTE ptr [ecx + 4]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 06], ax

  movzx ax, BYTE ptr [ecx + 5]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 04], ax

  movzx ax, BYTE ptr [ecx + 6]
  movzx ecx, BYTE ptr [ecx + 7]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov cx, WORD ptr HexCharTableA[2*ecx]
  mov [edx + 2], ax
  mov [edx], cx
  ret 12
qword2hexA endp

OPTION PROC:DEFAULT


;Version C.1.0
;
;MakeHexChar macro reg:req, pos:req
;    cmp reg, "9"
;    jbe @F
;    add reg, 7
;@@:
;    mov BYTE ptr [eax + pos], reg
;endm
;
;OPTION PROC:NONE;
;
;align ALIGN_CODE
;qword2hex proc pBuffer:POINTER, qValue:QWORD
;    mov edx, [esp + 8]              ;(QuadWord ptr qValue).LoDWord
;    mov ecx, edx
;    shr edx, 4
;
;    and edx, 0F0F0F0Fh
;    and ecx, 0F0F0F0Fh
;    add edx, "0000"
;    add ecx, "0000"
;
;    mov eax, [esp + 4]              ;pBuffer
;
;    MakeHexChar cl, 15
;    MakeHexChar dl, 14
;    MakeHexChar ch, 13
;    MakeHexChar dh, 12
;    shr ecx, 16
;    shr edx, 16
;    MakeHexChar cl, 11
;    MakeHexChar dl, 10
;    MakeHexChar ch, 9
;    MakeHexChar dh, 8
;
;    mov edx, [esp + 12]             ;(QuadWord ptr qValue).HiDWord
;    mov ecx, edx
;    shr edx, 4
;
;    and edx, 0F0F0F0Fh
;    and ecx, 0F0F0F0Fh
;    add edx, "0000"
;    add ecx, "0000"
;
;    MakeHexChar cl, 7
;    MakeHexChar dl, 6
;    MakeHexChar ch, 5
;    MakeHexChar dh, 4
;    shr ecx, 16
;    shr edx, 16
;    MakeHexChar cl, 3
;    MakeHexChar dl, 2
;    MakeHexChar ch, 1
;    MakeHexChar dh, 0
;
;    and BYTE ptr [eax + 16], 0
;
;    ret 12
;qword2hex endp
;
;OPTION PROLOGUE:PrologueDef
;OPTION EPILOGUE:EpilogueDef

end
