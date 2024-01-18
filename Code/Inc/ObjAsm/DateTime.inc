; ==================================================================================================
; Title:      DateTime.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Collection of date and time functions.
; Notes:      Version C.1.0, October 2023
;               - First release.
;               - Timecounting on Windows starts on 1st January 1601 00:00:00 UTC
; Links:      https://en.wikipedia.org/wiki/Gregorian_calendar
;             https://learn.microsoft.com/en-us/windows/win32/intl/calendar-identifiers
;             https://devblogs.microsoft.com/oldnewthing/20131101-00/?p=2763
; ==================================================================================================


;DTL_TICKS is a generic time container.
;It can hold 100ns ticks (hecto-nano-second = HNSECS) or 1ms ticks (MILLIS)
;HNSECS: 0FFFFFFFFFFFFFFFFh =      1'844'674'407'370 secs =      21'350'398 days =      58'494 years
;MILLIS: 0FFFFFFFFFFFFFFFFh = 18'446'744'073'709'551 secs = 213'503'982'334 days = 584'942'417 years

CAL_DEFAULT equ 0

DTL_TICKS union                         ;The same as FILETIME, the native OS format
              QWORD ?
  struct
    dLow      DWORD ?
    dHigh     DWORD ?
  ends
DTL_TICKS ends
PDTL_TICKS typedef ptr DTL_TICKS

DTL_HNSECS typedef DTL_TICKS
PDTL_HNSECS typedef ptr DTL_HNSECS

DTL_MILLIS typedef DTL_TICKS
PDTL_MILLIS typedef ptr DTL_MILLIS

DTL_DATE struct
  union
    wCalID    WORD  ?
    struct
      bCalID  BYTE  ?                 ;Calender ID, mostly CAL_GREGORIAN (1)
      bEra    BYTE  ?                 ;E.g. Japanese Reiwa era
    ends
  ends
  wYear       WORD  ?
  wMonth      WORD  ?
  wDay        WORD  ?
DTL_DATE ends
PDTL_DATE typedef ptr DTL_DATE

DTL_TIME struct
  wHour       WORD  ?                 ;"H"our
  wMinute     WORD  ?                 ;"M"inute
  wSecond     WORD  ?                 ;"S"econd
  wMilli      WORD  ?                 ;"T"housandth second
DTL_TIME ends
PDTL_TIME typedef ptr DTL_TIME

DTL_DATETIME struct
  DTL_DATE    {}
  DTL_TIME    {}
DTL_DATETIME ends
PDTL_DATETIME typedef ptr DTL_DATETIME

;Date Formats: YYYY=Year with century, YY=Year short, MM=Month, DD=Day
DTF_CHAR macro ByteOffset, Char
  exitm <Char shl (8*ByteOffset)>
endm

TF_DATESEP_OFFSET   equ 1
DF_DATESEP_NONE     equ DTF_CHAR(TF_DATESEP_OFFSET, 0)
DF_DATESEP_LOCALE   equ DTF_CHAR(TF_DATESEP_OFFSET, 1)
DF_DATESEP_DOT      equ DTF_CHAR(TF_DATESEP_OFFSET, '.')
DF_DATESEP_SLASH    equ DTF_CHAR(TF_DATESEP_OFFSET, '/')
DF_DATESEP_MINUS    equ DTF_CHAR(TF_DATESEP_OFFSET, '-')
DF_DDMMYYYY         equ 00        ;Example: 27/03/1974
DF_DDMMYY           equ 01        ;Example: 27/03/74
DF_YYYY             equ 02        ;Example: 1974
DF_YYYYMM           equ 03        ;Example: 1974/03
DF_YYYYMMDD         equ 04        ;Example: 1974/03/27
DF_YY               equ 05        ;Example: 74
DF_YYMM             equ 06        ;Example: 74/03
DF_YYMMDD           equ 07        ;Example: 07/03/27
DF_MMDDYYYY         equ 08        ;Example: 03/27/1974  American Date Format
DF_MMDDYY           equ 09        ;Example: 03/27/74    American Date Format

DF_EUROPEAN         equ DF_DDMMYYYY or DF_DATESEP_DOT
DF_AMERICAN         equ DF_MMDDYYYY or DF_DATESEP_SLASH
DF_JAPANESE         equ DF_YYMMDD or DF_DATESEP_DOT
DF_ISO              equ DF_YYYYMMDD or DF_DATESEP_DOT

;Date Formats: HH=Hours, MM=Minutes, SS=Seconds, FFF=Milliseconds, PD=Period(AM/PM)
TF_TIMESEP_OFFSET   equ 1
TF_MSECSEP_OFFSET   equ 2
TF_TIMESEP_NONE     equ DTF_CHAR(TF_TIMESEP_OFFSET, 0)
TF_TIMESEP_LOCALE   equ DTF_CHAR(TF_TIMESEP_OFFSET, 1)
TF_TIMESEP_COLON    equ DTF_CHAR(TF_TIMESEP_OFFSET, ':')
TF_MSECSEP_NONE     equ DTF_CHAR(TF_MSECSEP_OFFSET, 0)
TF_MSECSEP_LOCALE   equ DTF_CHAR(TF_MSECSEP_OFFSET, 1)
TF_MSECSEP_DOT      equ DTF_CHAR(TF_MSECSEP_OFFSET, '.')
TF_MSECSEP_COMA     equ DTF_CHAR(TF_MSECSEP_OFFSET, ',')
TF_MSECSEP_COLON    equ DTF_CHAR(TF_MSECSEP_OFFSET, ':')
TF_HHMMSS           equ 00
TF_HHMMSS_PD        equ 01         ;PD (period): AM/PM - https://unicode.org/reports/tr35/tr35-6.html#Date_Format_Patterns
TF_HHMMSSFFF        equ 02
TF_DDHHMMSS         equ 03
TF_DDHHMMSSFFF      equ 04

TF_EUROPEAN         equ TF_HHMMSS or TF_TIMESEP_COLON
TF_AMERICAN         equ TF_HHMMSS_PD or TF_TIMESEP_COLON


DateToStr proto :PSTRING, :DWORD, :PDTL_DATE    ;Buffer size is known according to the format specifier
TimeToStr proto :PSTRING, :DWORD, :PDTL_TIME
DateTimeToStr proto :PSTRING, :DWORD, :PDTL_DATE, :DWORD, :PDTL_TIME
IsLeapYear proto :DWORD

GetSystemMillis proto :PDTL_MILLIS

GetUtcHnsecs proto :PDTL_HNSECS
GetLocHnsecs proto :PDTL_HNSECS
GetSysHnsecs proto :PDTL_HNSECS

HnsecsToTime proto :PDTL_TIME, :PDTL_HNSECS
HnsecsToDate proto :PDTL_DATE, :PDTL_HNSECS
HnsecsToDateTime proto :PDTL_DATETIME, :PDTL_HNSECS

TimeToHnsecs proto :PDTL_HNSECS, :PDTL_TIME
DateTimeToHnsecs proto :PDTL_HNSECS, :PDTL_DATETIME   ;Todo


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SubTicks
; Purpose:    Subtract 2 Tick values.
; Arguments:  Arg1: Source variable 1 (minuend)
;             Arg2: Source variable 2 (subtrahend)
;             Arg3: Optional destination variable
; Return:     rax / edx::eax = result ticks.

SubTicks macro SrcTicks1:req, SrcTicks2:req, DstTicks
  if TARGET_BITNESS eq 32
    mov eax, SrcTicks1.DTL_TICKS.dLow
    mov edx, SrcTicks1.DTL_TICKS.dHigh
    sub edx, SrcTicks2.DTL_TICKS.dHigh
    sbb eax, SrcTicks2.DTL_TICKS.dLow
    ifnb <DstTicks>
      mov DstTicks.DTL_TICKS.dHigh, edx
      mov DstTicks.DTL_TICKS.dLow, eax
    endif
  else
    mov rax, SrcTicks1
    sub rax, SrcTicks2
    ifnb <DstTicks>
      mov DstTicks, rax
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      AddTicks
; Purpose:    Add 2 Tick values.
; Arguments:  Arg1: Source variable 1
;             Arg2: Source variable 2
;             Arg3: Optional destination variable
; Return:     rax / edx::eax = result ticks.

AddTicks macro SrcTicks1:req, SrcTicks2:req, DstTicks:req
  if TARGET_BITNESS eq 32
    mov eax, SrcTicks1.DTL_TICKS.dLow
    mov edx, SrcTicks1.DTL_TICKS.dHigh
    add edx, SrcTicks2.DTL_TICKS.dHigh
    adc eax, SrcTicks2.DTL_TICKS.dLow
    ifnb <DstTicks>
      mov DstTicks.DTL_TICKS.dHigh, edx
      mov DstTicks.DTL_TICKS.dLow, eax
    endif
  else
    mov rax, SrcTicks1
    add rax, SrcTicks2
    ifnb <DstTicks>
      mov DstTicks, rax
    endif
  endif
endm

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetSystemMillis
; Purpose:    Get system millisecond count.
; Arguments:  Arg1: -> Destination variable
; Return:     rax / edx::eax = millisecond count.

GetSystemMillis proc pDest:PDTL_MILLIS
  invoke GetTickCount64                                 ;In 32 bit, the 64 bit counter value is returned in edx::eax
  mov xcx, pDest
  if TARGET_BITNESS eq 32
    mov [xcx].DTL_MILLIS.dLow, eax
    mov [xcx].DTL_MILLIS.dHigh, edx
  else
    mov DTL_MILLIS ptr [rcx], rax
  endif
  ret
GetSystemMillis endp
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetSysHnsecs
; Purpose:    Get the hecto-nano-seconds count from system start.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     rax / edx::eax = hecto-nano-second count.

GetSysHnsecs proc pDest:PDTL_HNSECS
  GetInterruptTicks
  .if pDest
    mov xcx, pDest
    if TARGET_BITNESS eq 32
      mov [ecx], eax
      mov [ecx + 4], edx
    else
      mov [rcx], rax
    endif
  .endif
  ret
GetSysHnsecs endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetLocHnsecs
; Purpose:    Get the system hecto-nano-seconds count.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     eax = TRUE if succeeded, otherwise FALSE.

GetLocHnsecs proc pDest:PDTL_HNSECS
  invoke GetSystemTimeAsFileTime, pDest                 ;Fast
  invoke FileTimeToLocalFileTime, pDest, pDest          ;Expensive
  test eax, eax
  setz al
  movzx eax, al
  ret
GetLocHnsecs endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetUtcHnsecs
; Purpose:    Get the UTC hecto-nano-seconds count.
; Arguments:  Arg1: -> hecto-nano-seconds
; Return:     Nothing, always succeed.

GetUtcHnsecs proc pDest:PDTL_HNSECS
  invoke GetSystemTimeAsFileTime, pDest                 ;Fast
GetUtcHnsecs endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DateToStr
; Purpose:    Convert a DTL_DATE to a formated string representation.
; Arguments:  Arg1: -> Destination Buffer
;             Arg2: Format flags
;             Arg3: -> DTL_DATE
; Return:     eax = Number of bytes copied.

PrependZeros macro Var, Count
  if Count eq 4
    .if &Var < 10
      FillText CHR ptr [xdi], <000>
      add xdi, ??StrSize
    .elseif &Var < 100
      FillText CHR ptr [xdi], <00>
      add xdi, ??StrSize
    .elseif &Var < 1000
      FillText CHR ptr [xdi], <0>
      add xdi, ??StrSize
    .endif
  elseif Count eq 3
    .if &Var < 10
      FillText CHR ptr [xdi], <00>
      add xdi, ??StrSize
    .elseif &Var < 100
      FillText CHR ptr [xdi], <0>
      add xdi, ??StrSize
    .endif
  else
    .if &Var < 10
      FillText CHR ptr [xdi], <0>
      add xdi, ??StrSize
    .endif
  endif
endm

AddSeparator macro Char
  .if &Char
    WriteF xdi, "¦CT", &Char
  .endif
endm

DateToStr proc uses xdi xsi pDest:PSTRING, dFormat:DWORD, pDate:PDTL_DATE
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
DateToStr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TimeToStr
; Purpose:    Convert a DTL_TIME to a formated string representation.
; Arguments:  Arg1: -> Destination Buffer
;             Arg2: Format flags
;             Arg3: -> DTL_TIME
; Return:     eax = Number of bytes copied.

TimeToStr proc uses xdi xsi pDest:PSTRING, dFormat:DWORD, pHMST:PDTL_TIME
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
TimeToStr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DateTimeToStr
; Purpose:
; Arguments:  Arg1: -> Destination Buffer
;             Arg2: Date Format flags
;             Arg3: -> DTL_DATE
;             Arg4: Time Format flags
;             Arg5: -> DTL_TIME
; Return:     eax = Number of bytes copied.

DateTimeToStr proc uses xbx pDest:PSTRING, dDateFormat:DWORD, pDate:PDTL_DATE, \
                                           dTimeFormat:DWORD, pTime:PDTL_TIME
  invoke DateToStr, pDest, dDateFormat, pDate
  mov xbx, xax
  mov xcx, pDest
  add xcx, xax
  mov CHR ptr [xax], " "
  add xcx, sizeof(CHR)
  invoke TimeToStr, xcx, dTimeFormat, pTime
  lea xax, [xax + xbx + sizeof(CHR)]
  ret
DateTimeToStr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  HnsecsToTime
; Purpose:    Convert hecto-nano-seconds into DTL_TIME information.
; Arguments:  Arg1: -> DTL_TIME
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE id succeeded, otherwise FALSE.

HnsecsToTime proc uses xbx pTime:PDTL_TIME, pHnsecs:PDTL_HNSECS
  if TARGET_BITNESS eq 32
    mov xcx, pHnsecs
    mov eax, [xcx]
    mov edx, [xcx + 4]
    mov ebx, 10000                                  ;Remove all up to ms
    qddiv
    mov ebx, 1000
    qddiv
    mov xcx, pTime
    mov [xcx].DTL_TIME.wMilli, bx
    mov ebx, 60
    qddiv
    mov xcx, pTime
    mov [xcx].DTL_TIME.wSecond, bx
    mov ebx, 60
    qddiv
    mov xcx, pTime
    mov [xcx].DTL_TIME.wMinute, bx
    mov [xcx].DTL_TIME.wHour, ax
    .if edx != 0 || eax > 0FFFFh                    ;Overflow?
      xor eax, eax
    .else
      mov eax, TRUE
    .endif
  else
    mov xcx, pHnsecs
    mov rax, [xcx]
    mov ebx, 10000                                  ;Remove all up to ms
    xor edx, edx
    div rbx
    mov xcx, pTime
    mov ebx, 1000                                   ;Get ms and secs
    xor edx, edx
    div rbx
    mov [xcx].DTL_TIME.wMilli, dx
    xor edx, edx
    mov ebx, 60
    div rbx
    mov [xcx].DTL_TIME.wSecond, dx
    xor edx, edx
    div rbx
    mov [xcx].DTL_TIME.wMinute, dx
    mov [xcx].DTL_TIME.wHour, ax
    .if rax > 0FFFFh                                ;Overflow
      xor eax, eax
    .else
      mov eax, TRUE
    .endif
  endif
  ret
HnsecsToTime endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  HnsecsToDate
; Purpose:    Convert hecto-nano-seconds into DTL_DATE information.
; Arguments:  Arg1: -> DTL_DATE
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE if succeeded, otherwise FALSE.

HnsecsToDate proc pDate:PDTL_DATE, pHnsecs:PDTL_HNSECS
  local SysTime:SYSTEMTIME

  invoke FileTimeToSystemTime, pHnsecs, addr SysTime
  mov xcx, pDate
  .if eax
    mov [xcx].DTL_DATE.wCalID, CAL_GREGORIAN
    m2m DWORD ptr [xcx].DTL_DATE.wYear, DWORD ptr SysTime.wYear, eax
    m2m [xcx].DTL_DATE.wDay, SysTime.wDay, cx
    mov eax, TRUE
  .else
    m2z DWORD ptr [xcx].DTL_DATE.wCalID
    m2z DWORD ptr [xcx].DTL_DATE.wMonth                 ;eax already zero here
  .endif
  ret
HnsecsToDate endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  HnsecsToDateTime
; Purpose:    Convert hecto-nano-seconds into DTL_DATETIME information.
; Arguments:  Arg1: -> DTL_DATETIME
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE id succeeded, otherwise FALSE.

HnsecsToDateTime proc pDateTime:PDTL_DATETIME, pHnsecs:PDTL_HNSECS
  invoke FileTimeToSystemTime, pHnsecs, pDateTime
  mov xcx, pDateTime
  .if eax
    ;Move the first structure members
    mov eax, DWORD ptr [xcx].DTL_DATETIME.wCalID
    mov DWORD ptr [xcx].DTL_DATETIME.wYear, eax
    mov [xcx].DTL_DATETIME.wCalID, CAL_GREGORIAN
    mov eax, TRUE
  .else
    m2z DWORD ptr [xcx].DTL_DATETIME.wCalID
    m2z DWORD ptr [xcx].DTL_DATETIME.wMonth
    m2z DWORD ptr [xcx].DTL_DATETIME.wHour
    m2z DWORD ptr [xcx].DTL_DATETIME.wSecond            ;eax already zero here
  .endif
  ret
HnsecsToDateTime endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TimeToHnsecs
; Purpose:    Convert DTL_TIME information into hecto-nano-seconds.
; Arguments:  Arg1 -> hnsecs or NULL
;             Arg2 -> DTL_TIME
; Return:     rax or edx::eax = Time.

if TARGET_BITNESS eq 32
  TimeToHnsecs proc uses ebx edi pHnsecs:PDTL_HNSECS, pTime:PDTL_TIME
    mov edx, pTime
    movzx eax, [edx].DTL_TIME.wHour
    mov ecx, 60*60*10000
    mul ecx
    mov ebx, eax
    mov edi, edx
    movzx eax, [edx].DTL_TIME.wMinute
    mov ecx, 60*10000
    mul ecx
    add ebx, eax
    adc edi, edx
    movzx eax, [edx].DTL_TIME.wSecond
    mov ecx, 10000
    mul ecx
    add ebx, eax
    adc edi, edx
    movzx eax, [edx].DTL_TIME.wMilli
    mov ecx, 10
    mul ecx
    add eax, ebx
    adc edx, edi
    mov edx, pHnsecs
    .if edx != NULL
      mov [edx].DTL_HNSECS.dLow, eax
      mov [edx].DTL_HNSECS.dHigh, edx
    .endif
    ret
  TimeToHnsecs endp
else
  TimeToHnsecs proc uses rbx pHnsecs:PDTL_HNSECS, pTime:PDTL_TIME
    mov rdx, pTime
    movzx eax, [rdx].DTL_TIME.wHour
    mov rcx, 60*60*10000
    mul rcx
    mov rbx, rax
    movzx eax, [rdx].DTL_TIME.wMinute
    mov rcx, 60*10000
    mul rcx
    add rbx, rax
    movzx eax, [rdx].DTL_TIME.wSecond
    mov rcx, 10000
    mul rcx
    add rbx, rax
    movzx eax, [rdx].DTL_TIME.wMilli
    mov rcx, 10
    mul rcx
    add rax, rbx
    mov rdx, pHnsecs
    .if rdx != NULL
      mov [rdx], rax
    .endif
    ret
  TimeToHnsecs endp
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsLeapYear
; Purpose:    Check if a given year is a leap year (Gregorian calendar only).
; Arguments:  Arg1: Year, e.g. 2023
; Return:     eax = TRUE if the year is a leap year, otherwise FALSE
; Link:       https://en.wikipedia.org/wiki/Gregorian_calendar#:~:text=The%20rule%20for%20leap%20years%20is
; Note:       A year will be a leap year if it is divisible by 4 but not by 100. If a year is
;             divisible by 4 and by 100, it is not a leap year unless it is also divisible by 400.

IsLeapYear proc dYear:DWORD
  ?mov ecx, dYear                                       ;In 32 bit, load ecx with the year
  mov eax, ecx
  cDivMod 100                                           ;Calc eax = Year/100, edx = Year mod 100
  test edx, edx
  cmovnz eax, ecx                                       ;Reload year if the remainder is not zero
  and eax, 3                                            ;Check divisibility by 4
  setz al                                               ;Set TRUE/FALSE
  ret
IsLeapYear endp
