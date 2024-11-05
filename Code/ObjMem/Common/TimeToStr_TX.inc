; ==================================================================================================
; Title:      TimeToStr_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include &MacPath&ConstDiv.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TimeToStrA / TimeToStrW
; Purpose:    Convert a DTL_TIME to a formated string representation.
; Arguments:  Arg1: -> Destination Buffer
;             Arg2: Format flags
;             Arg3: -> DTL_TIME
; Return:     eax = Number of bytes copied, including the ZTC.

align ALIGN_CODE
ProcName proc uses xdi xsi pDest:PSTRING, dFormat:DWORD, pHMST:PDTL_TIME
  local dTimeFormat:DWORD, dHours:DWORD, dPeriod:DWORD, TimeSepChar:CHR, cLocaleBuffer[4]:CHR

  mov xdi, pDest
  mov xsi, pHMST

  ;Sanity check for this calendar
  movzx eax, [xsi].DTL_TIME.wMinute
  cmp eax, 60
  jae @@Error
  movzx eax, [xsi].DTL_TIME.wSecond
  cmp eax, 60
  jae @@Error
  movzx eax, [xsi].DTL_TIME.wMilli
  cmp eax, 1000
  jae @@Error

  mov eax, dFormat
  shr eax, 8*TF_TIMESEP_OFFSET
  and eax, 0000000FFh
  .if eax == 1                                        ;Locale
    m2z cLocaleBuffer[0]
    invoke GetLocaleInfoEx, LOCALE_NAME_USER_DEFAULT, LOCALE_STIME, addr cLocaleBuffer, lengthof(cLocaleBuffer)
    mov $SubReg(eax, sizeof(CHR)), cLocaleBuffer[0]
  .endif
  mov TimeSepChar, $SubReg(eax, sizeof(CHR))

  mov eax, dFormat
  and eax, 0000000FFh
  mov dTimeFormat, eax

  movzx eax, [xsi].DTL_TIME.wHour
  mov dHours, eax
  .if dTimeFormat == TF_DDHHMMSS || dTimeFormat == TF_DDHHMMSSFFF
    cDivMod 24
    mov dHours, edx
    PrependZeros eax, 2
    WriteF xdi, "¦UD", eax
    AddSeparator TimeSepChar
  .endif

  .if dTimeFormat == TF_HHMMSS_PD
    mov eax, dHours
    cDivMod 12
    mov dHours, edx
    mov dPeriod, eax
  .endif

  ;All other formats
  cmp dHours, 24
  jae @@Error
  PrependZeros dHours, 2
  WriteF xdi, "¦UD", dHours
  AddSeparator TimeSepChar
  PrependZeros [xsi].DTL_TIME.wMinute, 2
  WriteF xdi, "¦UW", [xsi].DTL_TIME.wMinute
  AddSeparator TimeSepChar
  PrependZeros [xsi].DTL_TIME.wSecond, 2
  WriteF xdi, "¦UW", [xsi].DTL_TIME.wSecond

  .if dTimeFormat == TF_HHMMSSFFF || dTimeFormat == TF_DDHHMMSSFFF
    mov eax, dFormat
    shr eax, 8*TF_MSECSEP_OFFSET
    and eax, 0000000FFh
    .if eax == 1                                        ;Locale
      m2z cLocaleBuffer[0]
      invoke GetLocaleInfoEx, LOCALE_NAME_USER_DEFAULT, LOCALE_SDECIMAL, addr cLocaleBuffer, lengthof(cLocaleBuffer)
      mov $SubReg(eax, sizeof(CHR)), cLocaleBuffer[0]
    .endif
    AddSeparator $SubReg(eax, sizeof(CHR))
    PrependZeros [xsi].DTL_TIME.wMilli, 3
    WriteF xdi, "¦UW", [xsi].DTL_TIME.wMilli
  .endif

  .if dTimeFormat == TF_HHMMSS_PD
    .if dPeriod == 0
      FillString [xdi], < AM>
    .else
      FillString [xdi], < PM>
    .endif
    add xdi, ??StrSize
  .endif

  mov xax, xdi
  sub xax, pDest
  add eax, sizeof(CHR)
  ret

@@Error:
  mov xdx, pDest
  FillString [xdi], <?>
  mov eax, ??StrSize
  ret
ProcName endp
