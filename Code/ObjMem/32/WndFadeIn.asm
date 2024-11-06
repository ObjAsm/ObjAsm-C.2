; ==================================================================================================
; Title:      WndFadeIn.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

CStrW wUser32Dll,  "User32.dll"
CStrA bSLWA,       "SetLayeredWindowAttributes"

TypeSLWA typedef proto :HANDLE, :POINTER, :DWORD, :DWORD

WS_EX_LAYERED   equ   80000h
LMA_ALPHA       equ   2
LMA_COLORKEY    equ   1

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  WndFadeIn
; Purpose:    Fade in a window when WS_EX_LAYERED is set.
; Arguments:  Arg1: Window HANDLE.
;             Arg2: Transparency start value.
;             Arg3: Transparency end value.
;             Arg4: Transparency increment value.
;             Arg5: Delay between steps.
; Return:     Nothing.

.code
align ALIGN_CODE
WndFadeIn proc uses ebx edi, hWnd:HWND, dStart:DWORD, dStop:DWORD, dStep:DWORD, dSleep:DWORD
  local VerInfo:OSVERSIONINFO

  invoke GetWindowLong, hWnd, GWL_EXSTYLE
  .ifBitSet eax, WS_EX_LAYERED
    ;Fade in algo for 2000 & XP only
    mov VerInfo.dwOSVersionInfoSize, sizeof OSVERSIONINFO
    invoke GetVersionEx, addr VerInfo
    .if VerInfo.dwMajorVersion >= 5                         ;Win2000 or XP ?
      invoke GetModuleHandleW, offset wUser32Dll            ;Load function dynamically to avoid
      mov edi, $invoke(GetProcAddress, eax, offset bSLWA)   ;problems with Win9x OS.
      invoke TypeSLWA ptr edi, hWnd, NULL, dStart, LMA_ALPHA
      invoke ShowWindow, hWnd, SW_SHOWNA
      mov eax, dStop
      .if eax > dStart
        mov eax, dStep
        .if eax
          mov ebx, dStart
          .repeat
            invoke TypeSLWA ptr edi, hWnd, NULL, ebx, LMA_ALPHA
            invoke UpdateWindow, hWnd
            invoke Sleep, dSleep                            ;Wait a little bit
            add ebx, dStep
          .until ebx >= dStop
          invoke TypeSLWA ptr edi, hWnd, NULL, dStop, LMA_ALPHA
          jmp @F
        .endif
      .endif
    .endif
  .endif
  invoke ShowWindow, hWnd, SW_SHOWNORMAL                    ;In case something failed
@@:
  ret
WndFadeIn endp

end
