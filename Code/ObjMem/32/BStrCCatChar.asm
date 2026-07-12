; ==================================================================================================
; Title:      BStrCCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCCatChar
; Purpose:    Append a WIDE character to a BSTR with length limitation.
; Arguments:  Arg1: -> Destination BSTR.
;             Arg2: -> WIDE character.
;             Arg3: Maximal number of charachters the destination string can hold excluding the ZTC.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCCatChar proc pDstBStr:POINTER, wChar:WORD, dMaxChars:DWORD
  mov ecx, [esp + 4]                                    ; ecx -> DstBStr
  mov eax, DWORD ptr [esp + 12]                         ; eax = dMaxChars
  shl eax, 1                                            ; dMaxChars => BYTEs
  mov edx, [ecx - 4]                                    ; edx  = current BYTEs in BSTR
  .if edx < eax                                         ; Check max char count in BYTEs
    movzx eax, WORD ptr [esp + 8]                       ; Include the ZTC in the write operation
    add DWORD ptr [ecx - 4], 2                          ; Increment size
    mov DWORD ptr [ecx + edx], eax                      ; Write character and ZTC
  .endif
  ret 12
BStrCCatChar endp

OPTION PROC:DEFAULT

end
