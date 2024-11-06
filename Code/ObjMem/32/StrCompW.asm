; ==================================================================================================
; Title:      StrCompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCompW
; Purpose:    Compare 2 WIDE strings with case sensitivity.
; Arguments:  Arg1: -> WIDE string 1.
;             Arg2: -> WIDE string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

align ALIGN_CODE
StrCompW proc pString1W:POINTER, pString2W:POINTER
  push edi
  push esi
  invoke StrLengthW, [esp + 12]                         ;pString1W
  lea ecx, [eax + 1]                                    ;Include the ZTC
  mov edi, [esp + 12]                                   ;edi -> String1W
  mov esi, [esp + 16]                                   ;esi -> String2W
  repe cmpsw
  movzx eax, WORD ptr [edi - 2]
  movzx ecx, WORD ptr [esi - 2]
  sub eax, ecx
  pop esi
  pop edi
  ret 8
StrCompW endp

OPTION PROC:DEFAULT

end
