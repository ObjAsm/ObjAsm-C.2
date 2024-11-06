; ==================================================================================================
; Title:      CreatePathA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreatePathA
; Purpose:    Create a path on the destination drive.
; Arguments:  Arg1: -> ANSI path string.
; Return:     Nothing.

.code
align ALIGN_CODE
CreatePathA proc uses ebx esi pPathNameA:POINTER
  local FFD:WIN32_FIND_DATA
  local cBuffer[MAX_PATH]:CHRA

  lea ebx, cBuffer
  invoke StrECopyA, ebx, pPathNameA
  FillStringA [eax], <\\*.*>
  invoke FindFirstFileA, ebx, addr FFD
  cmp eax, INVALID_HANDLE_VALUE
  je @@0
  invoke FindClose, eax                                 ;Directory just exists!
  mov eax, TRUE
  jmp @@Exit
@@0:
  mov ebx, pPathNameA
  invoke StrLScanA, ebx, "\"
  test eax, eax
  jz @@Exit
  inc eax
  mov esi, eax
@@1:
  invoke StrLScanA, esi, "\"
  mov esi, eax
  test eax, eax
  je @@2
  sub eax, ebx
  invoke StrCCopyA, addr cBuffer, ebx, eax
  jmp @@3
@@2:
  invoke StrCopyA, addr cBuffer, ebx
@@3:
  invoke CreateDirectoryA, addr cBuffer, NULL
  test esi, esi
  jz @@Exit
  inc esi
  jmp @@1
@@Exit:
  ret
CreatePathA endp

end
