; ==================================================================================================
; Title:      CRC_32.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of 32 bit CRC objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     CRC_32
; Purpose:    Implement an object to calculate a 32 bit CRC value of a data stream.
; Link:       http://www.geocities.com/SiliconValley/Pines/8659/crc.htm

Object CRC_32, CRC_32ID, Primer
  RedefineMethod  Init,     POINTER, DWORD              ;-> Owner, Polynomial [POLYNOMIAL_ANSI...]
  VirtualMethod   Calc,     POINTER, DWORD
  VirtualMethod   Reset

  DefineVariable  dValue,   DWORD,    -1                ;Initial Value
  DefineVariable  Table,    DWORD,    256 dup(0)        ;CRC lookup table
ObjectEnd

POLYNOMIAL_ANSI     equ   0EDB88320h                    ;ANSI X3.66
POLYNOMIAL_WZIP     equ   004C11DB7h                    ;PKZip, Ethernet, PNG

; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     CRC_32.Init
; Purpose:    Initialize the CRC_32 object filling a internal lookup table.
; Arguments:  Arg1: -> Owner object.
;             Arg2: CRC polynomial [POLYNOMIAL_ANSI, POLYNOMIAL_WZIP]
; Return:     Nothing.

Method CRC_32.Init, uses xbx xdi xsi, pOwner:POINTER, dPolynomial:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  mov edi, dPolynomial

  ;Fill the lookup table
  lea xax, [xsi].Table
  xor ebx, ebx
  .while ebx < 256
    mov ecx, ebx
    mov edx, 8
    .repeat
      test ecx, 1
      .if !ZERO?
        and ecx, 0FFFFFFFEh
        shr ecx, 1
        and ecx, 07FFFFFFFh
        xor ecx, edi
      .else
        and ecx, 0FFFFFFFEh
        shr ecx, 1
        and ecx, 07FFFFFFFh
      .endif
      dec edx
    .until ZERO?
    mov DWORD ptr [xax], ecx
    add xax, sizeof DWORD
    inc ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    CRC_32.Calc
; Purpose:   Calculate a new CRC_32 value based on the new data block and the previous CRC_32.
; Arguments: Arg1: -> New data block.
;            Arg2: Data block size in bytes.
; Return:    eax = CRC_32 value.

Method CRC_32.Calc, uses xbx xdi xsi, pBuffer:POINTER, dSize:DWORD
  SetObject xdi
  mov edx, [xdi].dValue                                 ;Result of the previous CRC_32 or
  mov xsi, pBuffer                                      ; -1 if just initialized
  mov ecx, dSize

  jecxz @@Exit                                          ;Just in case the array is empty
  test xsi, xsi
  jz @@Exit                                             ;Avoid NULL pointers

  lea xbx, [xdi].Table
@@:
  lodsb
  xor al, dl
  movzx eax, al
  shr edx, 8
  xor edx, [xbx + sizeof(DWORD)*xax]
  loop @B

  mov [xdi].dValue, edx

@@Exit:
  mov eax, [xdi].dValue
  not eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CRC_32.Reset
; Purpose:    Reset the previous CRC calculation.
; Arguments:  None.
; Return:     Nothing.

Method CRC_32.Reset
  SetObject xcx
  mov [xcx].dValue, -1
MethodEnd

endif
