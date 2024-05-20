;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\scarderr.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:14

;*
ifndef SCARD_S_SUCCESS
  ; =============================
  ; Facility SCARD Error Messages
  ; =============================
  SCARD_S_SUCCESS equ <NO_ERROR>
  ;  Values are 32 bit values laid out as follows:
  ;   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
  ;   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
  ;  +-+-+-+-+-+---------------------+-------------------------------+
  ;  |S|R|C|N|r|    Facility         |               Code            |
  ;  +-+-+-+-+-+---------------------+-------------------------------+
  ;  where
  ;      S - Severity - indicates success/fail
  ;          0 - Success
  ;          1 - Fail (COERROR)
  ;      R - reserved portion of the facility code, corresponds to NT's
  ;              second severity bit.
  ;      C - reserved portion of the facility code, corresponds to NT's
  ;              C field.
  ;      N - reserved portion of the facility code. Used to indicate a
  ;              mapped NT status value.
  ;      r - reserved portion of the facility code. Reserved for internal
  ;              use. Used to indicate HRESULT values that are not status
  ;              values, but are instead message ids for display strings.
  ;      Facility - is the facility code
  ;      Code - is the facility's status code
  ; Define the facility codes
  FACILITY_SYSTEM equ 0h
  FACILITY_SCARD equ 10h
  ; Define the severity codes
  STATUS_SEVERITY_INFORMATIONAL equ 1h
  STATUS_SEVERITY_WARNING equ 2h
  STATUS_SEVERITY_ERROR equ 3h
  ; MessageId: SCARD_F_INTERNAL_ERROR
  ; MessageText:
  ; An internal consistency check failed.
  SCARD_F_INTERNAL_ERROR equ (80100001h)
  ; MessageId: SCARD_E_CANCELLED
  ; MessageText:
  ; The action was cancelled by an SCardCancel request.
  SCARD_E_CANCELLED equ (80100002h)
  ; MessageId: SCARD_E_INVALID_HANDLE
  ; MessageText:
  ; The supplied handle was invalid.
  SCARD_E_INVALID_HANDLE equ (80100003h)
  ; MessageId: SCARD_E_INVALID_PARAMETER
  ; MessageText:
  ; One or more of the supplied parameters could not be properly interpreted.
  SCARD_E_INVALID_PARAMETER equ (80100004h)
  ; MessageId: SCARD_E_INVALID_TARGET
  ; MessageText:
  ; Registry startup information is missing or invalid.
  SCARD_E_INVALID_TARGET equ (80100005h)
  ; MessageId: SCARD_E_NO_MEMORY
  ; MessageText:
  ; Not enough memory available to complete this command.
  SCARD_E_NO_MEMORY equ (80100006h)
  ; MessageId: SCARD_F_WAITED_TOO_LONG
  ; MessageText:
  ; An internal consistency timer has expired.
  SCARD_F_WAITED_TOO_LONG equ (80100007h)
  ; MessageId: SCARD_E_INSUFFICIENT_BUFFER
  ; MessageText:
  ; The data buffer to receive returned data is too small for the returned data.
  SCARD_E_INSUFFICIENT_BUFFER equ (80100008h)
  ; MessageId: SCARD_E_UNKNOWN_READER
  ; MessageText:
  ; The specified reader name is not recognized.
  SCARD_E_UNKNOWN_READER equ (80100009h)
  ; MessageId: SCARD_E_TIMEOUT
  ; MessageText:
  ; The user-specified timeout value has expired.
  SCARD_E_TIMEOUT equ (8010000Ah)
  ; MessageId: SCARD_E_SHARING_VIOLATION
  ; MessageText:
  ; The smart card cannot be accessed because of other connections outstanding.
  SCARD_E_SHARING_VIOLATION equ (8010000Bh)
  ; MessageId: SCARD_E_NO_SMARTCARD
  ; MessageText:
  ; The operation requires a smart card, but no smart card is currently in the device.
  SCARD_E_NO_SMARTCARD equ (8010000Ch)
  ; MessageId: SCARD_E_UNKNOWN_CARD
  ; MessageText:
  ; The specified smart card name is not recognized.
  SCARD_E_UNKNOWN_CARD equ (8010000Dh)
  ; MessageId: SCARD_E_CANT_DISPOSE
  ; MessageText:
  ; The system could not dispose of the media in the requested manner.
  SCARD_E_CANT_DISPOSE equ (8010000Eh)
  ; MessageId: SCARD_E_PROTO_MISMATCH
  ; MessageText:
  ; The requested protocols are incompatible with the protocol currently in use with the smart card.
  SCARD_E_PROTO_MISMATCH equ (8010000Fh)
  ; MessageId: SCARD_E_NOT_READY
  ; MessageText:
  ; The reader or smart card is not ready to accept commands.
  SCARD_E_NOT_READY equ (80100010h)
  ; MessageId: SCARD_E_INVALID_VALUE
  ; MessageText:
  ; One or more of the supplied parameters values could not be properly interpreted.
  SCARD_E_INVALID_VALUE equ (80100011h)
  ; MessageId: SCARD_E_SYSTEM_CANCELLED
  ; MessageText:
  ; The action was cancelled by the system, presumably to log off or shut down.
  SCARD_E_SYSTEM_CANCELLED equ (80100012h)
  ; MessageId: SCARD_F_COMM_ERROR
  ; MessageText:
  ; An internal communications error has been detected.
  SCARD_F_COMM_ERROR equ (80100013h)
  ; MessageId: SCARD_F_UNKNOWN_ERROR
  ; MessageText:
  ; An internal error has been detected, but the source is unknown.
  SCARD_F_UNKNOWN_ERROR equ (80100014h)
  ; MessageId: SCARD_E_INVALID_ATR
  ; MessageText:
  ; An ATR obtained from the registry is not a valid ATR string.
  SCARD_E_INVALID_ATR equ (80100015h)
  ; MessageId: SCARD_E_NOT_TRANSACTED
  ; MessageText:
  ; An attempt was made to end a non-existent transaction.
  SCARD_E_NOT_TRANSACTED equ (80100016h)
  ; MessageId: SCARD_E_READER_UNAVAILABLE
  ; MessageText:
  ; The specified reader is not currently available for use.
  SCARD_E_READER_UNAVAILABLE equ (80100017h)
  ; MessageId: SCARD_P_SHUTDOWN
  ; MessageText:
  ; The operation has been aborted to allow the server application to exit.
  SCARD_P_SHUTDOWN equ (80100018h)
  ; MessageId: SCARD_E_PCI_TOO_SMALL
  ; MessageText:
  ; The PCI Receive buffer was too small.
  SCARD_E_PCI_TOO_SMALL equ (80100019h)
  ; MessageId: SCARD_E_READER_UNSUPPORTED
  ; MessageText:
  ; The reader driver does not meet minimal requirements for support.
  SCARD_E_READER_UNSUPPORTED equ (8010001Ah)
  ; MessageId: SCARD_E_DUPLICATE_READER
  ; MessageText:
  ; The reader driver did not produce a unique reader name.
  SCARD_E_DUPLICATE_READER equ (8010001Bh)
  ; MessageId: SCARD_E_CARD_UNSUPPORTED
  ; MessageText:
  ; The smart card does not meet minimal requirements for support.
  SCARD_E_CARD_UNSUPPORTED equ (8010001Ch)
  ; MessageId: SCARD_E_NO_SERVICE
  ; MessageText:
  ; The Smart Card Resource Manager is not running.
  SCARD_E_NO_SERVICE equ (8010001Dh)
  ; MessageId: SCARD_E_SERVICE_STOPPED
  ; MessageText:
  ; The Smart Card Resource Manager has shut down.
  SCARD_E_SERVICE_STOPPED equ (8010001Eh)
  ; MessageId: SCARD_E_UNEXPECTED
  ; MessageText:
  ; An unexpected card error has occurred.
  SCARD_E_UNEXPECTED equ (8010001Fh)
  ; MessageId: SCARD_E_ICC_INSTALLATION
  ; MessageText:
  ; No Primary Provider can be found for the smart card.
  SCARD_E_ICC_INSTALLATION equ (80100020h)
  ; MessageId: SCARD_E_ICC_CREATEORDER
  ; MessageText:
  ; The requested order of object creation is not supported.
  SCARD_E_ICC_CREATEORDER equ (80100021h)
  ; MessageId: SCARD_E_UNSUPPORTED_FEATURE
  ; MessageText:
  ; This smart card does not support the requested feature.
  SCARD_E_UNSUPPORTED_FEATURE equ (80100022h)
  ; MessageId: SCARD_E_DIR_NOT_FOUND
  ; MessageText:
  ; The identified directory does not exist in the smart card.
  SCARD_E_DIR_NOT_FOUND equ (80100023h)
  ; MessageId: SCARD_E_FILE_NOT_FOUND
  ; MessageText:
  ; The identified file does not exist in the smart card.
  SCARD_E_FILE_NOT_FOUND equ (80100024h)
  ; MessageId: SCARD_E_NO_DIR
  ; MessageText:
  ; The supplied path does not represent a smart card directory.
  SCARD_E_NO_DIR equ (80100025h)
  ; MessageId: SCARD_E_NO_FILE
  ; MessageText:
  ; The supplied path does not represent a smart card file.
  SCARD_E_NO_FILE equ (80100026h)
  ; MessageId: SCARD_E_NO_ACCESS
  ; MessageText:
  ; Access is denied to this file.
  SCARD_E_NO_ACCESS equ (80100027h)
  ; MessageId: SCARD_E_WRITE_TOO_MANY
  ; MessageText:
  ; The smart card does not have enough memory to store the information.
  SCARD_E_WRITE_TOO_MANY equ (80100028h)
  ; MessageId: SCARD_E_BAD_SEEK
  ; MessageText:
  ; There was an error trying to set the smart card file object pointer.
  SCARD_E_BAD_SEEK equ (80100029h)
  ; MessageId: SCARD_E_INVALID_CHV
  ; MessageText:
  ; The supplied PIN is incorrect.
  SCARD_E_INVALID_CHV equ (8010002Ah)
  ; MessageId: SCARD_E_UNKNOWN_RES_MNG
  ; MessageText:
  ; An unrecognized error code was returned from a layered component.
  SCARD_E_UNKNOWN_RES_MNG equ (8010002Bh)
  ; MessageId: SCARD_E_NO_SUCH_CERTIFICATE
  ; MessageText:
  ; The requested certificate does not exist.
  SCARD_E_NO_SUCH_CERTIFICATE equ (8010002Ch)
  ; MessageId: SCARD_E_CERTIFICATE_UNAVAILABLE
  ; MessageText:
  ; The requested certificate could not be obtained.
  SCARD_E_CERTIFICATE_UNAVAILABLE equ (8010002Dh)
  ; MessageId: SCARD_E_NO_READERS_AVAILABLE
  ; MessageText:
  ; Cannot find a smart card reader.
  SCARD_E_NO_READERS_AVAILABLE equ (8010002Eh)
  ; MessageId: SCARD_E_COMM_DATA_LOST
  ; MessageText:
  ; A communications error with the smart card has been detected.  Retry the operation.
  SCARD_E_COMM_DATA_LOST equ (8010002Fh)
  ; MessageId: SCARD_E_NO_KEY_CONTAINER
  ; MessageText:
  ; The requested key container does not exist on the smart card.
  SCARD_E_NO_KEY_CONTAINER equ (80100030h)
  ; MessageId: SCARD_E_SERVER_TOO_BUSY
  ; MessageText:
  ; The Smart Card Resource Manager is too busy to complete this operation.
  SCARD_E_SERVER_TOO_BUSY equ (80100031h)
  ; MessageId: SCARD_E_PIN_CACHE_EXPIRED
  ; MessageText:
  ; The smart card PIN cache has expired.
  SCARD_E_PIN_CACHE_EXPIRED equ (80100032h)
  ; MessageId: SCARD_E_NO_PIN_CACHE
  ; MessageText:
  ; The smart card PIN cannot be cached.
  SCARD_E_NO_PIN_CACHE equ (80100033h)
  ; MessageId: SCARD_E_READ_ONLY_CARD
  ; MessageText:
  ; The smart card is read only and cannot be written to.
  SCARD_E_READ_ONLY_CARD equ (80100034h)
  ; These are warning codes.
  ; MessageId: SCARD_W_UNSUPPORTED_CARD
  ; MessageText:
  ; The reader cannot communicate with the smart card, due to ATR configuration conflicts.
  SCARD_W_UNSUPPORTED_CARD equ (80100065h)
  ; MessageId: SCARD_W_UNRESPONSIVE_CARD
  ; MessageText:
  ; The smart card is not responding to a reset.
  SCARD_W_UNRESPONSIVE_CARD equ (80100066h)
  ; MessageId: SCARD_W_UNPOWERED_CARD
  ; MessageText:
  ; Power has been removed from the smart card, so that further communication is not possible.
  SCARD_W_UNPOWERED_CARD equ (80100067h)
  ; MessageId: SCARD_W_RESET_CARD
  ; MessageText:
  ; The smart card has been reset, so any shared state information is invalid.
  SCARD_W_RESET_CARD equ (80100068h)
  ; MessageId: SCARD_W_REMOVED_CARD
  ; MessageText:
  ; The smart card has been removed, so that further communication is not possible.
  SCARD_W_REMOVED_CARD equ (80100069h)
  ; MessageId: SCARD_W_SECURITY_VIOLATION
  ; MessageText:
  ; Access was denied because of a security violation.
  SCARD_W_SECURITY_VIOLATION equ (8010006Ah)
  ; MessageId: SCARD_W_WRONG_CHV
  ; MessageText:
  ; The card cannot be accessed because the wrong PIN was presented.
  SCARD_W_WRONG_CHV equ (8010006Bh)
  ; MessageId: SCARD_W_CHV_BLOCKED
  ; MessageText:
  ; The card cannot be accessed because the maximum number of PIN entry attempts has been reached.
  SCARD_W_CHV_BLOCKED equ (8010006Ch)
  ; MessageId: SCARD_W_EOF
  ; MessageText:
  ; The end of the smart card file has been reached.
  SCARD_W_EOF equ (8010006Dh)
  ; MessageId: SCARD_W_CANCELLED_BY_USER
  ; MessageText:
  ; The action was cancelled by the user.
  SCARD_W_CANCELLED_BY_USER equ (8010006Eh)
  ; MessageId: SCARD_W_CARD_NOT_AUTHENTICATED
  ; MessageText:
  ; No PIN was presented to the smart card.
  SCARD_W_CARD_NOT_AUTHENTICATED equ (8010006Fh)
  ; MessageId: SCARD_W_CACHE_ITEM_NOT_FOUND
  ; MessageText:
  ; The requested item could not be found in the cache.
  SCARD_W_CACHE_ITEM_NOT_FOUND equ (80100070h)
  ; MessageId: SCARD_W_CACHE_ITEM_STALE
  ; MessageText:
  ; The requested cache item is too old and was deleted from the cache.
  SCARD_W_CACHE_ITEM_STALE equ (80100071h)
  ; MessageId: SCARD_W_CACHE_ITEM_TOO_BIG
  ; MessageText:
  ; The new cache item exceeds the maximum per-item size defined for the cache.
  SCARD_W_CACHE_ITEM_TOO_BIG equ (80100072h)
endif
; SCARD_S_SUCCESS
