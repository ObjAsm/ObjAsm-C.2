; ==================================================================================================
; Title:      DbgPostServer_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


externdef pDbgIpStrA:PSTRINGA
externdef wDbgIpPort:WORD
externdef hDbgInternet:HANDLE

WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exclude WinSock.inc
INTERNET_PROTOCOL_VERSION   equ 4

% include &IncPath&Windows\wininet.inc
% include &IncPath&Windows\wincrypt.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgPostServer
; Purpose:    Send a POST request to the DebugCenter Server
; Arguments:  Arg1: -> Data.
;             Arg2: DataSize.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

align ALIGN_CODE
DbgPostServer proc pData:POINTER, dDataSize:DWORD
  local dResult:DWORD, pEncyptedData:POINTER, dEncyptedDataLength:DWORD, dContext:DWORD
  local hConnection:HINTERNET, hRequest:HINTERNET
   
  invoke CryptBinaryToStringA, pData, dDataSize, CRYPT_STRING_BASE64 or CRYPT_STRING_NOCRLF, \
                               NULL, addr dEncyptedDataLength
  ;dEncyptedBufferLength includes the ZTC
  .if eax != 0
    MemAlloc dEncyptedDataLength
    .if xax
      mov pEncyptedData, xax
      invoke CryptBinaryToStringA, pData, dDataSize, CRYPT_STRING_BASE64 or CRYPT_STRING_NOCRLF, \
                                   pEncyptedData, addr dEncyptedDataLength
      .if eax != 0
        invoke InternetConnectA, hDbgInternet, pDbgIpStrA, wDbgIpPort, NULL, NULL, \
                                 INTERNET_SERVICE_HTTP, 0, addr dContext
        .if xax
          mov hConnection, xax
          invoke HttpOpenRequestA, hConnection, $OfsCStrA("POST"), NULL, $OfsCStrA("HTTP/1.1"), \
                                   NULL, NULL, \
                                   INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_AUTH or \
                                   INTERNET_FLAG_NO_COOKIES or INTERNET_FLAG_NO_UI, \
                                   addr dContext
          .if xax
            mov hRequest, xax
            mov eax, dEncyptedDataLength
            inc eax
            ;HttpSendRequest waits for a response or timeouts
            invoke HttpSendRequestA, hRequest, NULL, 0, pEncyptedData, eax
            mov dResult, eax
            invoke InternetCloseHandle, hRequest
          .endif 
          invoke InternetCloseHandle, hConnection
        .endif
      .endif
      MemFree pEncyptedData
    .endif
  .endif

  mov eax, dResult
  ret
DbgPostServer endp
