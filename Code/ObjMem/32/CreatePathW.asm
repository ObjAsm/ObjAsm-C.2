; ==================================================================================================
; Title:      CreatePathW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreatePathW
; Purpose:    Create a path on the destination drive.
; Arguments:  Arg1: -> Wide path string.
; Return:     Nothing.

.code
align ALIGN_CODE
CreatePathW proc uses ebx esi pPathNameW:POINTER
  local FFD:WIN32_FIND_DATAW
  local cBuffer[MAX_PATH]:CHRW

  lea ebx, cBuffer
  invoke StrECopyW, ebx, pPathNameW
  FillStringW [eax], <\\*.*>
  invoke FindFirstFileW, ebx, addr FFD
  cmp eax, INVALID_HANDLE_VALUE
  je @@0
  invoke FindClose, eax                                 ;Directory just exists!
  mov eax, TRUE
  jmp @@Exit
@@0:
  mov ebx, pPathNameW
  invoke StrLScanW, ebx, "\"
  test eax, eax
  jz @@Exit
  add eax, 2
  mov esi, eax
@@1:
  invoke StrLScanW, esi, "\"
  mov esi, eax
  test eax, eax
  je @@2
  sub eax, ebx
  shr eax, 1
  invoke StrCCopyW, addr cBuffer, ebx, eax
  jmp @@3
@@2:
  invoke StrCopyW, addr cBuffer, ebx
@@3:
  invoke CreateDirectoryW, addr cBuffer, NULL
  test esi, esi
  jz @@Exit
  add esi, 2
  jmp @@1
@@Exit:
  ret
CreatePathW endp

end
