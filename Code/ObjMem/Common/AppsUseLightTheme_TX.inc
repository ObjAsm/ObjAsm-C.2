; ==================================================================================================
; Title:      AppsUseLightTheme_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, December 2022.
;               - First release.
;               - Bitness independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  AppsUseLightTheme
; Purpose:    Checks whether the "Light mode" is activated for the applications.
; Arguments:  None.
; Return:     eax = TRUE or FALSE.

align ALIGN_CODE
AppsUseLightTheme proc
  local hKey:HKEY, dValueType:DWORD, dValue:DWORD, dValueSize:DWORD

  mov dValue, TRUE
  mov dValueSize, sizeof(dValue)
  invoke RegOpenKeyExW, HKEY_CURRENT_USER, \
                       $OfsCStrW("Software\Microsoft\Windows\CurrentVersion\Themes\Personalize"), \
                       0, KEY_QUERY_VALUE, addr hKey
  .if eax == ERROR_SUCCESS
    invoke RegQueryValueExW, hKey, $OfsCStrW("AppsUseLightTheme"), NULL, addr dValueType, \
                             addr dValue, addr dValueSize
    invoke RegCloseKey, hKey
  .endif
  mov eax, dValue
  ret
AppsUseLightTheme endp

