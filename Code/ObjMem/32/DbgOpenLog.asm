; ==================================================================================================
; Title:      DbgOpenLog.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOpenLog
; Purpose:    Open a Log-File.
; Arguments:  None.
; Return:     eax = TRUE if it was opened, otherwise FALSE.

.code
align ALIGN_CODE
DbgOpenLog proc
  local cFileName[MAX_PATH]:CHRW

  .if hDbgDev == -1
    xor eax, eax
  .else
    .if hDbgDev == 0
      invoke StrECopyW, addr cFileName, offset szDbgSrc
      FillStringW [eax], <.dbg>
      invoke CreateFileW, addr cFileName, GENERIC_WRITE, \
                          FILE_SHARE_READ or FILE_SHARE_WRITE, \
                          NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
      .if eax == INVALID_HANDLE_VALUE
        invoke MessageBoxW, 0, $OfsCStrW($Esc("Debug file can not be created\:")), \
                            offset szDbgErr, MB_OK or MB_ICONERROR
        mov hDbgDev, -1
        xor eax, eax                              ;eax = FALSE
      .else
        mov hDbgDev, eax
        mov eax, TRUE
      .endif
    .endif
  .endif
  ret
DbgOpenLog endp

end
