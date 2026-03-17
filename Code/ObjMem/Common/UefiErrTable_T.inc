; ==================================================================================================
; Title:      UefiErrTable_T.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - Initial release.
;               - Character independant code.
; ==================================================================================================


.const
align ALIGN_DATA
UefiErrTable label POINTER
  POINTER $OfsTStr("SUCCESS")
  POINTER $OfsTStr("LOAD_ERROR")
  POINTER $OfsTStr("INVALID_PARAMETER")
  POINTER $OfsTStr("UNSUPPORTED")
  POINTER $OfsTStr("BAD_BUFFER_SIZE")
  POINTER $OfsTStr("BUFFER_TOO_SMALL")
  POINTER $OfsTStr("NOT_READY")
  POINTER $OfsTStr("DEVICE_ERROR")
  POINTER $OfsTStr("WRITE_PROTECTED")
  POINTER $OfsTStr("OUT_OF_RESOURCES")
  POINTER $OfsTStr("VOLUME_CORRUPTED")
  POINTER $OfsTStr("VOLUME_FULL")
  POINTER $OfsTStr("NO_MEDIA")
  POINTER $OfsTStr("MEDIA_CHANGED")
  POINTER $OfsTStr("NOT_FOUND")
  POINTER $OfsTStr("ACCESS_DENIED")
  POINTER $OfsTStr("NO_RESPONSE")
  POINTER $OfsTStr("NO_MAPPING")
  POINTER $OfsTStr("TIMEOUT")
  POINTER $OfsTStr("NOT_STARTED")
  POINTER $OfsTStr("ALREADY_STARTED")
  POINTER $OfsTStr("ABORTED")
  POINTER $OfsTStr("ICMP_ERROR")
  POINTER $OfsTStr("TFTP_ERROR")
  POINTER $OfsTStr("PROTOCOL_ERROR")
UefiErrTableCount equ ($ - UefiErrTable)/sizeof(POINTER)
