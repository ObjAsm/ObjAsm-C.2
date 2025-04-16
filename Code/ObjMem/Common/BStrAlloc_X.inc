; ==================================================================================================
; Title:      BStrAlloc_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, November 2024
;               - Allocation done using SysAllocStringByteLen.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrAlloc
; Purpose:    Allocate space for a BStr with n characters. The length field is set to zero.
; Arguments:  Arg1: Character count, without the ZTC.
; Return:     xax -> New allocated BString (BSTR) or NULL if failed.

.code
align ALIGN_CODE
BStrAlloc proc dChars:DWORD
  ?mov ecx, dChars
  lea edx, [2*ecx]                                      ;Convert to word sized
  invoke SysAllocStringByteLen, NULL, edx
  .if xax != NULL
    m2z DWORD ptr [xax - sizeof(DWORD)]                 ;Set length field to zero
  .endif
  ret
BStrAlloc endp
