; ==================================================================================================
; Title:      GetWinVersion_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022.
;               - First release.
;               - Bitness independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  GetWinVersion
; Purpose:    Get Windows true version numbers directly from NTDLL.
; Arguments:  Arg1: -> Major Version. Can be NULL.
;             Arg2: -> Minor Version. Can be NULL.
;             Arg3: -> Build Number. Can be NULL.
; Return:     Nothing.
; Links:      https://www.geoffchappell.com/studies/windows/win32/ntdll/api/ldrinit/getntversionnumbers.htm

.code
align ALIGN_CODE
GetWinVersion proc pMajorVersion:POINTER, pMinorVersion:POINTER, pBuildNumber:POINTER
  local hLib:HANDLE

  mov hLib, $invoke(LoadLibraryW, $OfsCStrW("NTDLL.dll"))
  invoke GetProcAddress, hLib, $OfsCStrA("RtlGetNtVersionNumbers")
  if TARGET_BITNESS eq 64
    mov rcx, pMajorVersion
    mov rdx, pMinorVersion
    mov r8, pBuildNumber
  else
    push pBuildNumber
    push pMinorVersion
    push pMajorVersion
  endif
  call xax
  invoke FreeLibrary, hLib
  ret
GetWinVersion endp
