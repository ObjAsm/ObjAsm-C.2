; ==================================================================================================
; Title:      IsLeapYear_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include &MacPath&ConstDiv.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsLeapYear
; Purpose:    Check if a given year is a leap year (Gregorian calendar only).
; Arguments:  Arg1: Year, e.g. 2023
; Return:     eax = TRUE if the year is a leap year, otherwise FALSE
; Link:       https://en.wikipedia.org/wiki/Gregorian_calendar#:~:text=The%20rule%20for%20leap%20years%20is
; Note:       A year will be a leap year if it is divisible by 4 but not by 100. If a year is
;             divisible by 4 and by 100, it is not a leap year unless it is also divisible by 400.

align ALIGN_CODE
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
