; ==================================================================================================
; Title:      ShortToLongPathNameA.asm
; Author:     G. Friedrich / J. Trudgen
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  ShortToLongPathNameA
; Purpose:    Allocate a new ANSI string containing the long path of a short path string.
; Arguments:  Arg1: -> Short path ANSI string.
; Return:     eax -> Long path ANSI string or NULL if failed.

.code
align ALIGN_CODE
ShortToLongPathNameA proc uses edi esi pShortPathNameA:POINTER
  local Buffer[MAX_PATH]:BYTE
  local Result[MAX_PATH]:BYTE
  local FFD:WIN32_FIND_DATA

  invoke StrLScanA, pShortPathNameA, "~"
  test eax, eax
  jz @@0
  invoke StrLScanA, pShortPathNameA, "\"
  test eax, eax
  jnz @@1
@@0:
  invoke StrNewA, pShortPathNameA
  jmp @@Exit
@@1:
  mov esi, eax
  sub eax, pShortPathNameA
  inc esi
  invoke StrCCopyA, addr Result, pShortPathNameA, eax
  invoke StrEndA, pShortPathNameA
  mov edi, eax
@@2:
  invoke StrLScanA, esi, "\"
  mov esi, eax
  invoke StrCatCharA, addr Result, "\"
  test esi, esi
  jnz @@3
  mov eax, edi
  jmp @@4
@@3:
  mov eax, esi
@@4:
  sub eax, pShortPathNameA
  invoke StrCCopyA, addr Buffer, pShortPathNameA, eax
  invoke FindFirstFile, addr Buffer, addr FFD
  invoke FindClose, eax
  invoke StrCatA, addr Result, addr FFD.cFileName
  test esi, esi
  jz @@5
  inc esi
  cmp esi, edi
  jne @@2
  invoke StrCatCharA, addr Result, "\"
@@5:
  invoke StrNewA, addr Result
@@Exit:
  ret
ShortToLongPathNameA endp

end
