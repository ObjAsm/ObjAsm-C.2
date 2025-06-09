; ==================================================================================================
; Title:      StrCNew_T32P.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrCNewA / StrCNewW / StrCNewA_UEFI / StrCNewW_UEFI
; Purpose:    Allocate a new copy of the source string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNew
;             returns NULL and doesn't allocate any memory space. Otherwise, StrCNew makes a
;             duplicate of the source string. The maximal size of the new string is limited to the
;             second parameter.
; Arguments:  Arg1: -> Source string.
;             Arg2: Maximal character count.
; Return:     eax -> New string copy.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

.code
align ALIGN_CODE
ProcName proc pString:POINTER, dMaxChars:DWORD
  ANNOTATION use: pString dMaxChars

  mov eax, [esp + 4]                                    ;eax -> String
  test eax, eax                                         ;is NULL => fail
  jz @F
  invoke StrCLength, eax, [esp + 8]
  push eax
  invoke StrAlloc, eax
  pop ecx
  test eax, eax
  jz @F                                                 ;Allocation failed
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shl ecx, 1
  endif
  m2z WORD ptr [eax + ecx]                              ;Set termination zero
  push eax
  invoke MemClone, eax, [esp + 12], ecx                 ;Copy the source string
  pop eax
@@:
  ret 8
ProcName endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

