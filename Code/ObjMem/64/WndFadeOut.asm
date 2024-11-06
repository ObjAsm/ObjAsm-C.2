; ==================================================================================================
; Title:      WndFadeOut.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef wUser32Dll:WORD
externdef bSLWA:BYTE

TypeSLWA typedef proto :HANDLE, :POINTER, :DWORD, :DWORD

WS_EX_LAYERED   equ   80000h
LMA_ALPHA       equ   2
LMA_COLORKEY    equ   1

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  WndFadeOut
; Purpose:    Fade out a window when WS_EX_LAYERED is set.
; Arguments:  Arg1: Window HANDLE.
;             Arg2: Transparency start value.
;             Arg3: Transparency end value.
;             Arg4: Transparency decrement value.
;             Arg5: Delay between steps.
; Return:     Nothing.

.code
align ALIGN_CODE
WndFadeOut proc uses rbx rdi, hWnd:HWND, dStart:DWORD, dStop:DWORD, dStep:DWORD, dSleep:DWORD
  local VerInfo:OSVERSIONINFO

  invoke GetWindowLong, hWnd, GWL_EXSTYLE
  .ifBitSet eax, WS_EX_LAYERED
    ;Fade out algo for 2000 & XP only
    mov VerInfo.dwOSVersionInfoSize, sizeof(OSVERSIONINFO)
    invoke GetVersionEx, addr VerInfo
    .if VerInfo.dwMajorVersion >= 5                       ;Win2000 or XP ?
      invoke GetModuleHandleW, offset wUser32Dll          ;Load function dynamically to avoid
      mov rdi, $invoke(GetProcAddress, rax, offset bSLWA) ;problems with Win9x OS.
      mov eax, dStop
      .if eax < dStart
        mov eax, dStep
        .if eax
          mov ebx, dStart
          .repeat
            invoke TypeSLWA ptr rdi, hWnd, NULL, ebx, LMA_ALPHA
            invoke UpdateWindow, hWnd
            invoke Sleep, dSleep                          ;Wait a little bit
            sub ebx, dStep
          .until SDWORD ptr ebx <= dStop
          invoke TypeSLWA ptr rdi, hWnd, NULL, dStop, LMA_ALPHA
        .endif
      .endif
    .endif
  .endif
  ret
WndFadeOut endp

end
