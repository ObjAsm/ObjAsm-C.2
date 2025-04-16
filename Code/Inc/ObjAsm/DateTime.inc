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


; --------------------------------------------------------------------------------------------------
; Macro:      SysTime2DateTime
; Purpose:    Convert a SYSTIME struct to a DTL_DATETIME rearranging the position of some members.
; Arguments:  Arg1: SYSTIME structure
;             Arg2: (optional) Calendar
; Note:       Uses eax.

SysTime2DateTime macro SysTime:req, Calendar:=<CAL_GREGORIAN>
  mov eax, DWORD ptr SysTime.wYear
  mov DWORD ptr SysTime.wMonth, eax
  mov SysTime.wYear, Calendar
endm

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
; Macro:      PrependZeros
; Purpose:    Add enough "0" digits to complete DigitCount.
; Arguments:  Arg1: Value
;             Arg2: Max digits
; Return:     xdi -> Next char.
; Note:       On entry, xdi -> first char to fill.

PrependZeros macro Var, DigitCount
  if DigitCount eq 4
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
  elseif DigitCount eq 3
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

; --------------------------------------------------------------------------------------------------
; Macro:      AddSeparator
; Purpose:    Add a separator
; Arguments:  Arg1: Character
; Return:     xdi -> Next char.
; Note:       On entry, xdi -> first char to fill.

AddSeparator macro Char
  .if &Char
    WriteF xdi, "¦CT", &Char
  .endif
endm

