; ==================================================================================================
; Title:      IsLeapYear.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsLeapYear
; Purpose:    Check if a given year is a leap year (Gregorian calendar only).
; Arguments:  Arg1: Year, e.g. 2023
; Return:     eax = TRUE if the year is a leap year, otherwise FALSE
; Link:       https://en.wikipedia.org/wiki/Gregorian_calendar#:~:text=The%20rule%20for%20leap%20years%20is
; Note:       A year will be a leap year if it is divisible by 4 but not by 100. If a year is
;             divisible by 4 and by 100, it is not a leap year unless it is also divisible by 400.

% include &ObjMemPath&Common\IsLeapYear_X.inc

end