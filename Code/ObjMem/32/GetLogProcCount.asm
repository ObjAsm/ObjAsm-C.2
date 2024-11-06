; ==================================================================================================
; Title:      GetLogProcCount.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; Links:      - http://software.intel.com/en-us/articles/multi-core-detect
;             - http://cache-www.intel.com/cd/00/00/27/66/276613_276613.pdf
;             - http://cache-www.intel.com/cd/00/00/27/66/276611_276611.txt
;             - http://www.koders.com/cpp/fid3BC912972A64FC64C38645FD079927D1081454F9.aspx
;             - http://software.intel.com/en-us/articles/multi-core-detect
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetLogProcCount
; Purpose:    Return the number of logical CPUs on the current system.
; Arguments:  None
; Return:     eax = Number of logical processors.

.code
align ALIGN_CODE
GetLogProcCount proc uses ebx edi esi pMaskTable:POINTER
  local dProcessAffinity:DWORD, dSystemAffinity:DWORD, hCurrentProcessHandle:HANDLE

  invoke GetCurrentProcess
  mov hCurrentProcessHandle, eax
  invoke GetProcessAffinityMask, hCurrentProcessHandle, \
                                 addr dProcessAffinity, addr dSystemAffinity
  .if eax != FALSE
    xor edi, edi
    xor ebx, ebx
    inc edi
    mov esi, pMaskTable
@@:
    test edi, dSystemAffinity
    .if !ZERO?
      ;Check if this logical processor is available to this process
      invoke SetProcessAffinityMask, hCurrentProcessHandle, edi
      .if eax != 0
        .if esi != NULL
          mov DWORD ptr [esi + 4*ebx], edi
        .endif
        invoke Sleep, 0                                 ;Give OS time to switch CPU
        inc ebx
      .endif
    .endif
    shl edi, 1                                          ;Prepare mask for the next logical processor
    jz @F                                               ;Exit if the mask is above 32
    cmp edi, dSystemAffinity
    jbe @B
@@:
    ;Set previous process affinity mask
    invoke SetProcessAffinityMask, hCurrentProcessHandle, dProcessAffinity

    mov eax, ebx
  .endif                                                ;Return 0 if GetProcessAffinityMask failed

  ret
GetLogProcCount endp

end
