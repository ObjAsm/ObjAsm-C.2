; ==================================================================================================
; Title:      DateToStr_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include &MacPath&ConstDiv.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DateToStrA / DateToStrW
; Purpose:    Convert a DTL_DATE to a formated string representation.
; Arguments:  Arg1: -> Destination Buffer
;             Arg2: Format flags
;             Arg3: -> DTL_DATE
; Return:     eax = Number of bytes copied, including the ZTC.

align ALIGN_CODE
ProcName proc uses xdi xsi pDest:PSTRING, dFormat:DWORD, pDate:PDTL_DATE
  local DateSepChar:CHR, cLocaleBuffer[4]:CHR

.const
D2S_JumpTable label POINTER
  POINTER offset @@DDMMYYYY
  POINTER offset @@DDMMYY
  POINTER offset @@YYYY
  POINTER offset @@YYYYMM
  POINTER offset @@YYYYMMDD
  POINTER offset @@YY
  POINTER offset @@YYMM
  POINTER offset @@YYMMDD
  POINTER offset @@MMDDYYYY
  POINTER offset @@MMDDYY
D2S_JumpTableEntries = ($ - D2S_JumpTable)/sizeof(POINTER)

.code
  mov xdi, pDest
  mov xsi, pDate

  .if [xsi].DTL_DATE.wCalID == CAL_DEFAULT || [xsi].DTL_DATE.wCalID == CAL_GREGORIAN

    ;Sanity check for this calendar
    movzx eax, [xsi].DTL_DATE.wMonth
    cmp eax, 0
    je @@Error
    cmp eax, 12
    ja @@Error
    movzx ecx, [xsi].DTL_DATE.wDay
    cmp ecx, 0
    je @@Error

    .if eax == 4 || eax == 6 || eax == 9 || eax == 11
      cmp ecx, 30
    .elseif eax == 2
      ;https://en.wikipedia.org/wiki/Gregorian_calendar#:~:text=The%20rule%20for%20leap%20years%20is
      movzx eax, [xsi].DTL_DATE.wYear
      cmod 400
      .if edx == 0
        cmp ecx, 29
      .else
        movzx eax, [xsi].DTL_DATE.wYear
        cmod 100
        .if edx == 0
          cmp ecx, 28
        .else
          movzx eax, [xsi].DTL_DATE.wYear
          and eax, 011b
          .if eax == 0
            cmp ecx, 29
          .else
            cmp ecx, 28
          .endif
        .endif
      .endif
    .else
      cmp ecx, 31
    .endif
    ja @@Error

    mov eax, dFormat
    shr eax, 8*TF_DATESEP_OFFSET
    and eax, 0000000FFh
    .if eax == 1                                        ;Locale
      m2z cLocaleBuffer[0]
      invoke GetLocaleInfoEx, LOCALE_NAME_USER_DEFAULT, LOCALE_SDATE, addr cLocaleBuffer, lengthof(cLocaleBuffer)
      mov $SubReg(eax, sizeof(CHR)), cLocaleBuffer[0]
    .endif
    mov DateSepChar, $SubReg(eax, sizeof(CHR))

    mov eax, dFormat
    and eax, 0000000FFh
    cmp eax, D2S_JumpTableEntries
    jae @@Error

    mov xcx, offset D2S_JumpTable
    jmp POINTER ptr [xcx + xax*sizeof(POINTER)]

  @@DDMMYYYY:
    PrependZeros [xsi].DTL_DATE.wDay, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wDay
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wYear, 4
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wYear
    jmp @@Exit

  @@DDMMYY:
    PrependZeros [xsi].DTL_DATE.wDay, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wDay
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    AddSeparator DateSepChar
    movzx eax, [xsi].DTL_DATE.wYear
    cmod 1000
    PrependZeros edx, 2
    WriteF xdi, "¦UW", dx
    jmp @@Exit

  @@YYYY:
    PrependZeros [xsi].DTL_DATE.wYear, 4
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wYear
    jmp @@Exit

  @@YYYYMM:
    PrependZeros [xsi].DTL_DATE.wYear, 4
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wYear
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    jmp @@Exit

  @@YY:
    movzx eax, [xsi].DTL_DATE.wYear
    cmod 100
    PrependZeros [xsi].DTL_DATE.wYear, 2
    WriteF xdi, "¦UW", dx
    jmp @@Exit

  @@YYMM:
    movzx eax, [xsi].DTL_DATE.wYear
    cmod 100
    PrependZeros edx, 2
    WriteF xdi, "¦UW", dx
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    jmp @@Exit

  @@YYYYMMDD:
    PrependZeros [xsi].DTL_DATE.wYear, 4
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wYear
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wDay, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wDay
    jmp @@Exit

  @@YYMMDD:
    movzx eax, [xsi].DTL_DATE.wYear
    cmod 1000
    PrependZeros edx, 2
    WriteF xdi, "¦UW", dx
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wDay, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wDay
    jmp @@Exit

  @@MMDDYYYY:
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wDay, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wDay
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wYear, 4
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wYear
    jmp @@Exit

  @@MMDDYY:
    PrependZeros [xsi].DTL_DATE.wMonth, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wMonth
    AddSeparator DateSepChar
    PrependZeros [xsi].DTL_DATE.wDay, 2
    WriteF xdi, "¦UW", [xsi].DTL_DATE.wDay
    AddSeparator DateSepChar
    movzx eax, [xsi].DTL_DATE.wYear
    cmod 1000
    PrependZeros edx, 2
    WriteF xdi, "¦UW", dx

@@Exit:
    mov xax, xdi
    sub xax, pDest
    add eax, sizeof(CHR)
  .else
@@Error:
    mov xdx, pDest
    FillString [xdi], <?>
    mov eax, ??StrSize
  .endif

  ret
ProcName endp
