; ==================================================================================================
; Title:      DbgOpenWnd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOpenWnd
; Purpose:    Open Debug Center instance.
; Arguments:  None.
; Return:     eax = TRUE if it was opened, otherwise FALSE.

.code
align ALIGN_CODE
DbgOpenWnd proc uses ebx
  local StartupInfo:STARTUPINFO, ProcessInforamtion:PROCESS_INFORMATION
  local WP:WINDOWPLACEMENT, hKey: HKEY, dValueType:DWORD
  local dBufSize:DWORD, cBuffer[MAX_PATH]:CHRW

  .if hDbgDev == -1                                     ;Error condition?
    xor eax, eax
  .else
    ;On Win9x systems, IsWindow doesn't return TRUE, it returns something different from zero!
    invoke IsWindow, hDbgDev                            ;Is it a valid window handle?
    .if eax == FALSE
      invoke FindWindowW, offset szDbgCtrCls, NULL      ;Search for an open DbgWnd instance
      .if eax == 0
        lea ebx, cBuffer
        invoke RegOpenKeyExW, HKEY_CURRENT_USER, offset szDbgRegKey, 0, KEY_ALL_ACCESS, addr hKey
        mov dBufSize, sizeof cBuffer
        invoke RegQueryValueExW, hKey, $OfsCStrW("Path"), NULL, addr dValueType, ebx, addr dBufSize
        .if eax == ERROR_SUCCESS
          .if $invoke(FileExistW, ebx)
            mov StartupInfo.cb, sizeof StartupInfo
            m2z StartupInfo.lpReserved
            m2z StartupInfo.lpDesktop
            m2z StartupInfo.lpTitle
            m2z StartupInfo.dwFlags
            m2z StartupInfo.cbReserved2
            m2z StartupInfo.lpReserved2
            invoke CreateProcessW, ebx, NULL, NULL, NULL, FALSE, \
                                   CREATE_BREAKAWAY_FROM_JOB or CREATE_DEFAULT_ERROR_MODE or \
                                   NORMAL_PRIORITY_CLASS, \
                                   NULL, NULL, addr StartupInfo, addr ProcessInforamtion
            invoke WaitForInputIdle, ProcessInforamtion.hProcess, 4000
            .if eax == WAIT_TIMEOUT
              invoke MessageBoxW, 0, $OfsCStrW($Esc("Debug Center is not responding\:")), \
                                  offset szDbgErr, MB_OK or MB_ICONERROR
              mov hDbgDev, -1
              xor eax, eax                              ;Return FALSE
              jmp @@Exit
            .endif
            invoke FindWindowW, offset szDbgCtrCls, NULL
          .else
            invoke MessageBoxW, 0, $OfsCStrW($Esc("Debug Center not found\:")), \
                                offset szDbgErr, MB_OK or MB_ICONERROR
            mov hDbgDev, -1
            xor eax, eax                                ;Return FALSE
            jmp @@Exit
          .endif
        .else
          invoke MessageBoxW, 0, \
                   $OfsCStrW($Esc("Registration error\:\nStart DebugCenter manually...")), \
                   offset szDbgErr, MB_OK or MB_ICONERROR
          mov hDbgDev, -1
          xor eax, eax                                  ;Return FALSE
          jmp @@Exit
        .endif
      .endif

      .if eax != 0
        mov hDbgDev, eax                                ;Store the window handle
        mov WP.length_, sizeof WINDOWPLACEMENT
        invoke GetWindowPlacement, hDbgDev, addr WP
        .if WP.showCmd == SW_SHOWMINIMIZED
          invoke SendMessageW, hDbgDev, WM_COMMAND, IDM_DEBUG_CENTER_RESTORE, 0
        .endif
        mov eax, TRUE                                   ;Return value
      .else
        invoke MessageBoxW, 0, $OfsCStrW($Esc("Debug Center can not be opened\:")), \
                            offset szDbgErr, MB_OK or MB_ICONERROR
        mov hDbgDev, -1                                 ;Return FALSE
        xor eax, eax
      .endif
    .else
      mov WP.length_, sizeof WINDOWPLACEMENT
      invoke GetWindowPlacement, hDbgDev, addr WP
      .if WP.showCmd == SW_SHOWMINIMIZED
        invoke SendMessageW, hDbgDev, WM_COMMAND, IDM_DEBUG_CENTER_RESTORE, 0
      .endif
      mov eax, TRUE                                     ;Fix Win9x bug
    .endif
  .endif
@@Exit:
  ret
DbgOpenWnd endp

end
