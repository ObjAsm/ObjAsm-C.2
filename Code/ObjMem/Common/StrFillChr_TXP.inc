; ==================================================================================================
; Title:      StrFillChr_TXP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.2, December 2020.
;               - First release.
;               - Character, bitness and platform independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrFillChrA / StrFillChrW
; Purpose:    Fill a preallocated String with a character.
; Arguments:  Arg1: -> String.
;             Arg2: Character Count.
;             Arg3: Character.
; Return:     Nothing.

.code
align ALIGN_CODE
ProcName proc pString:POINTER, dCount:DWORD, cChar:CHR
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    invoke MemFillW, pString, dCount, cChar
  else
    invoke MemFillB, pString, dCount, cChar
  endif
  mov xax, pString
  mov ecx, dCount
  mov CHR ptr [xax + xcx*sizeof(CHR)], 0                ;Set ZTC
  ret
ProcName endp
