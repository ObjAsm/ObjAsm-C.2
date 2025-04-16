; ==================================================================================================
; Title:      St0ToStr_AXP.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness and platform independent code.
;             Version C.1.1, July 2022
;               - Support for f_ALIGN and f_PLUS added.
;             Version C.2.0, January 2023
;               - Missing ret added. Bug reported by a1sbofo.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  St0ToStrA
; Purpose:    Create an ANSI string representation of the content of the st(0) FPU register.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: Minimal number of places from the start of string up to the decimal point.
;                   (f_NOR only)
;             Arg3: Number of decimal places after the decimal point.
;             Arg4: Format flag (f_NOR, f_SCI, f_TRIM, f_ALIGNED) defined in fMath.inc
; Return:     eax = Result code f_OK, f_ERROR, f_NAN, ...
; Notes:      - Based on the work of Raymond Filiatreault (FpuLib).
;             - st4, st5, st6 and st7 must be empty.
;             - f_NOR: regular output format
;             - f_SCI: Scientific output format
;             - f_TRIM: Trim zeros on the right
;             - f_ALIGN: Add a heading space to align the output with other negative numbers
;             - f_PLUS: like f_ALIGN, but using a "+" character.

.code
align ALIGN_CODE
St0ToStrA proc uses xdi xsi pBuffer:POINTER, dPadding:DWORD, dDecimals:DWORD, dFlags:DWORD
  local dTempDw         :DWORD
  local dExponent       :DWORD
  local tBCD            :TBYTE
  local wPrvCtrlWord    :WORD
  local wTruncCtrlWord  :WORD
  local wStatusWord     :WORD
  local bUnpacked[20]   :BYTE

  ;Get the specified number of decimals and padding chars and make corrections if necessary
  .if dDecimals > 15                                    ;Number of decimals
    mov dDecimals, 15                                   ;A maximum of 15 decimals are allowed
  .endif
  .if dPadding > 17                                     ;Number of char before decimal point
    mov dPadding, 17                                    ;A maximum of 17 characters are allowed
  .endif

  ;Check first if value on FPU is valid or equal to zero
  fclex
  ftst                                                  ;Test value on FPU
  fstsw wStatusWord                                     ;Get result
  fwait
  test wStatusWord, mask fC3                            ;Check it for zero and NAN
  jz @@GetExponent                                      ;Continue if valid non-zero
  test wStatusWord, mask fC0                            ;Now check it for NAN
  jnz @@Error                                           ;Src is NAN or infinity - cannot convert

  ;Value to convert = 0
  xor eax, eax
  mov dExponent, eax
  lea xcx, tBCD
  mov [xcx], eax
  mov [xcx + 4], eax
  mov [xcx + 8], ax
  jmp @@UnpackBCD

;Get the size of the number
@@GetExponent:
  fld st(0)                                             ;Copy it
  fabs                                                  ;Insures a positive value
  fLogT                                                 ;log10(Src)
  fstcw wPrvCtrlWord                                    ;Get current control word
  fwait
  mov ax, wPrvCtrlWord
  or ax, 0C00h                                          ;Set it for truncating
  mov wTruncCtrlWord, ax
  fldcw wTruncCtrlWord                                  ;Change rounding code of FPU to truncate

  fist dExponent                                        ;Store characteristic of logarithm
  fldcw wPrvCtrlWord                                    ;Load back the former control word

  ftst                                                  ;Test logarithm for its sign
  fstsw wStatusWord                                     ;Get result
  fwait
  test wStatusWord, mask fC0                            ;Check if negative
  .if !ZERO?
    dec dExponent
  .endif
  fstp st(0)                                            ;Get rid of the logarithm

  ;Get the power of 10 required to generate an integer
  ;with the specified number of significant digits
  .ifBitClr dFlags, f_SCI                               ;Regular decimal notation
    mov eax, dExponent
    test eax, eax                                       ;Check if number is < 1
    .if !SIGN?
      .if eax > 15                                      ;If number is >= 10^16
        or dFlags, f_SCI                                ;Switch to scientific notation
        mov dDecimals, 15                               ;Make sure that 15 decimals fit into the result
        BitSet dFlags, f_SCI
        jmp Scientific
      .endif
      add eax, dDecimals
      .if eax > 15                                      ;If integer + decimal digits > 16
        sub eax, 15
        sub dDecimals, eax                              ;Reduce decimal digits as required
      .endif
    .endif
    mrm dTempDw, dDecimals, edx
  .else                                                 ;Scientific notation
  Scientific:
    mov eax, dDecimals
    sub eax, dExponent
    mov dTempDw, eax
  .endif

  ;Multiply the number by the power of 10 to generate required integer and store it as BCD
  fld st(0)
  .if dTempDw != 0
    fild dTempDw
    fExpT
    fmul                                                ;-> 16-digit integer
  .endif
  lea xax, tBCD
  fbstp tBCD                                            ;-> TBYTE containing the packed digits
  fstsw wStatusWord                                     ;Retrieve exception flags from FPU
  fwait
  test wStatusWord, BIT00                               ;Test for invalid operation
  jnz @@Error                                           ;Clean-up and return error

  ;Unpack BCD, the 10 BYTEs returned by the FPU being in the little-endian style
@@UnpackBCD:
  lea xsi, tBCD + 9                                     ;Go to the most significant byte (sign byte)
  lea xdi, bUnpacked
  .ifBitSet dFlags, f_PLUS
    mov eax, 302Bh                                      ;"+0"
  .else
    mov eax, 3020h                                      ;" 0"
  .endif
  mov cl, BYTE ptr [xsi]                                ;Sign byte
  .if cl == 80h
    mov al, "-"                                         ;Insert sign if negative number
  .endif
  stosw
  mov ecx, 9
  .repeat
    dec xsi
    movzx eax, BYTE ptr [xsi]
    ror ax, 4
    ror ah, 4
    add ax, 3030h                                       ;"00"
    stosw
    dec ecx
  .until ZERO?

  mov xdi, pBuffer
  lea xsi, bUnpacked
  .ifBitClr dFlags, f_SCI
    ;REGULAR NOTATION
    mov ecx, dPadding                                   ;Check if padding is specified
    test ecx, ecx
    jz @@NoPadding

    mov edx, 1                                          ;At least 1 integer + sign
    mov eax, dExponent
    test eax, eax
    .if !SIGN?                                          ;Only 1 integer digit if size is < 1
      add edx, eax                                      ;-> number of integer digits
    .endif
    sub xcx, xdx
    jle @@NoPadding
    mov al, " "
    rep stosb

    @@NoPadding:
    pushfx                                              ;Save padding flags
    lodsb
    .if al == ' '
      .ifBitSet dFlags, f_ALIGN
        stosb
      .endif
    .else
      stosb
    .endif

    mov ecx, 1                                          ;At least 1 integer digit
    mov eax, dExponent
    test eax, eax                                       ;Is size negative (i.e. number smaller than 1)
    .if !SIGN?
      add ecx, eax
    .endif
    mov eax, dDecimals
    sub xsi, xax
    sub xsi, xcx
    add xsi, 19                                         ;xsi -> 1st digit to display
    .if BYTE ptr [xsi - 1] == "1"
      dec xsi
      inc xcx
      popfx                                             ;Retrieve padding flags
      jle @F                                            ;No padding was necessary
      sub xdi, 1                                        ;Adjust for one less padding byte
    .else
      add xsp, @WordSize                                ;Free the stack
    .endif
    @@:
    rep movsb
    mov ecx, dDecimals
    .if ecx != 0
      mov al, "."
      stosb
      rep movsb
    .endif

  .else
    ;SCIENTIFIC NOTATION
    lodsb
    .if al == ' '
      .ifBitSet dFlags, f_ALIGN
        stosb
      .endif
    .else
      stosb
    .endif
    mov ecx, dDecimals
    mov eax, 18
    sub eax, ecx
    add xsi, xax
    cmp BYTE ptr [xsi - 1], "1"
    pushfx                                              ;Save flags for extra "1"
    .if ZERO?
      sub xsi, 1
    .endif
    movsb
    mov al, "."
    stosb
    rep movsb

    mov ax, "+E"
    mov ecx, dExponent
    popfx                                               ;Retrieve flags for extra "1"
    .if ZERO?
      inc ecx                                           ;Adjust exponent
    .endif
    test ecx, ecx
    .if SIGN?
      mov ax, "-E"
      neg ecx                                           ;Make number positive
    .endif
    stosw                                               ;Emit with proper sign

    ;Note: the absolute value of the exponent could not exceed 4931
    mov eax, ecx
    mov cl, 100
    div cl                                              ;-> thousands & hundreds in AL, tens & units in AH
    mov edx, eax
    and eax, 0FFh                                       ;Keep only the thousands & hundreds
    mov cl, 10
    div cl                                              ;-> thousands in AL, hundreds in AH
    add ax, 3030h                                       ;Convert to characters
    stosw                                               ;Insert them
    mov eax, edx
    shr eax, 8                                          ;Get the tens & units in AL
    div cl                                              ;Tens in AL, units in AH
    add ax, 3030h                                       ;Convert to characters
    stosw                                               ;Insert them
  .endif

  xor eax, eax
  stosb                                                 ;Write ZTC

  .ifBitSet dFlags, f_TRIM                              ;Trim right zeros
    .ifBitClr dFlags, f_SCI
      mov xdi, pBuffer
      mov xcx, -1
      xor eax, eax
      repne scasb
      not xcx
      mov xdi, pBuffer
      dec xcx
      .if !ZERO?                                        ;Lenght = 0
        mov al, "."
        repne scasb
        mov eax, NULL                                   ;Dont't change flags!
        .if ZERO?
          lea xax, [xdi - sizeof CHRA]
        .endif
      .endif
      .if xax != NULL
        mov xcx, xax
        add xax, 1
        .while CHRA ptr [xax] != 0
          .if CHRA ptr [xax] != "0"
            mov xcx, xax
            add xcx, 1
          .endif
          add xax, 1
        .endw
        m2z CHRA ptr [xcx]
      .endif
    .endif
  .endif
  mov eax, f_OK
  ret

@@Error:
  fxam
  fstsw wStatusWord                                     ;Retrieve exception flags from FPU

  xor eax, eax
  fwait
  .ifBitSet wStatusWord, mask fC0
    BitSet eax, BIT00
  .endif
  .ifBitSet wStatusWord, mask fC2
    BitSet eax, BIT01
  .endif
  .ifBitSet wStatusWord, mask fC3
    BitSet eax, BIT02
  .endif

  mov xcx, pBuffer
  .if eax == 0
    FillStringA [xcx], <Error>
    mov eax, f_ERROR
  .elseif eax == 1
    FillStringA [xcx], <NAN>
    mov eax, f_NAN
  .elseif eax == 2
    FillStringA [xcx], <Failed>
    mov eax, f_ERROR
  .elseif eax == 3
    .ifBitSet wStatusWord, mask fC1
      FillStringA [xcx], <-Inf>
      mov eax, f_INFN
    .else
      FillStringA [xcx], <+Inf>
      mov eax, f_INFP
    .endif
  .elseif eax == 4
    FillStringA [xcx], <Null>
    mov eax, f_ERROR
  .elseif eax == 5
    FillStringA [xcx], <Empty>
    mov eax, f_ERROR
  .elseif eax == 6
    FillStringA [xcx], <Denor>
    mov eax, f_DENOR
  .endif
  fclex                                                 ;Clear FPU exception flags
  ret
St0ToStrA endp
