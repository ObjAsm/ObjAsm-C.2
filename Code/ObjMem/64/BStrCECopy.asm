; ==================================================================================================
; Title:      BStrCECopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCECopy
; Purpose:    Copy the the source BSTR with length limitation and return the address of the ZTC.
;             The destination buffer should hold the maximum number of characters + 1.
; Arguments:  Arg1: -> Destination BSTR.
;             Arg2: -> Source BSTR.
;             Arg3: Maximal number of charachters the destination string can hold including the ZTC.
; Return:     rax = NULL or -> ZTC.

.code
align ALIGN_CODE
BStrCECopy proc uses rbx pDstBStr:POINTER, pSrcBStr:POINTER, dMaxChars:DWORD  ;rcx -> DstBStr, rdx -> SrcBStr
  shl r8d, 1                                            ; r8d = dMaxChars in BYTEs
  mov eax, [rdx - 4]                                    ; eax = bytes from SrcBStr
  cmp r8d, eax
  cmova r8d, eax                                        ; Get the the min value
  lea rbx, [rcx + r8]                                   ; Calculate end of string
  mov DWORD ptr [rcx - 4], r8d                          ; Store size
  invoke MemClone, rcx, rdx, r8d                        ; SHift string content
  mov WORD ptr[rbx], 0                                  ; Set ZTC
  mov rax, rbx
  ret
BStrCECopy endp

end
