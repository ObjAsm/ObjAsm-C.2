; ==================================================================================================
; Title:      DebugCenter_HttpServer.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of HttpServer objects.
; Notes:      Version C.1.2, December 2020
;               - First release.
;             https://docs.microsoft.com/en-us/windows/win32/http/http-api-start-page
;             https://docs.microsoft.com/en-us/windows/win32/http/urlprefix-strings
; Example:    https://docs.microsoft.com/en-us/windows/win32/http/http-server-sample-application
; URL:        https://myname:secret@www.example.com:8080/index.html?p1=A&p2=B#ressource
;             \___/   \____/ \____/ \_____________/ \__/ \________/ \_______/ \_______/
;               |       |      |           |         |       |          |         |
;             Schema   User Password      Host      Port    Path      Query    Fragment
; ==================================================================================================


;Server Commands
CMD_START     equ   0
CMD_STOP      equ   1
CMD_PAUSE     equ   2

;Http Status Code (RFC 2616 => https://www.ietf.org/rfc/rfc2616.txt)
HSC_CONTINUE                             equ  100
HSC_SWITCHING_PROTOCOLS                  equ  101
HSC_PROCESSING                           equ  102     ;WEBDAV
HSC_OK                                   equ  200
HSC_CREATED                              equ  201
HSC_ACCEPTED                             equ  202
HSC_NON_AUTHORITATIVE_INFORMATION        equ  203
HSC_NO_CONTENT                           equ  204
HSC_RESET_CONTENT                        equ  205
HSC_PARTIAL_CONTENT                      equ  206
HSC_MULTI_STATUS                         equ  207     ;WEBDAV
HSC_ALREADY_REPORTED                     equ  208     ;WEBDAV
HSC_IM_USED                              equ  226
HSC_MULTIPLE_CHOICES                     equ  300
HSC_MOVED_PERMANENTLY                    equ  301
HSC_FOUND                                equ  302
HSC_SEE_OTHER                            equ  303
HSC_NOT_MODIFIED                         equ  304
HSC_USE_PROXY                            equ  305
HSC_TEMPORARY_REDIRECT                   equ  307
HSC_PERMANENT_REDIRECT_EXPERIMENTAL      equ  308
HSC_BAD_REQUEST                          equ  400
HSC_UNAUTHORIZED                         equ  401
HSC_PAYMENT_REQUIRED                     equ  402
HSC_FORBIDDEN                            equ  403
HSC_NOT_FOUND                            equ  404
HSC_METHOD_NOT_ALLOWED                   equ  405
HSC_NOT_ACCEPTABLE                       equ  406
HSC_PROXY_AUTHENTICATION_REQUIRED        equ  407
HSC_REQUEST_TIMEOUT                      equ  408
HSC_CONFLICT                             equ  409
HSC_GONE                                 equ  410
HSC_LENGTH_REQUIRED                      equ  411
HSC_PRECONDITION_FAILED                  equ  412
HSC_REQUEST_ENTITY_TOO_LARGE             equ  413
HSC_REQUEST_URI_TOO_LONG                 equ  414
HSC_UNSUPPORTED_MEDIA_TYPE               equ  415
HSC_REQUESTED_RANGE_NOT_SATISFIABLE      equ  416
HSC_EXPECTATION_FAILED                   equ  417
HSC_I_M_A_TEAPOT                         equ  418     ;RFC 2324
HSC_ENHANCE_YOUR_CALM                    equ  420     ;TWITTER
HSC_UNPROCESSABLE_ENTITY                 equ  422     ;WEBDAV
HSC_LOCKED                               equ  423     ;WEBDAV
HSC_FAILED_DEPENDENCY                    equ  424     ;WEBDAV
HSC_RESERVED_FOR_WEBDAV                  equ  425     ;WEBDAV
HSC_UPGRADE_REQUIRED                     equ  426
HSC_PRECONDITION_REQUIRED                equ  428
HSC_TOO_MANY_REQUESTS                    equ  429
HSC_REQUEST_HEADER_FIELDS_TOO_LARGE      equ  431
HSC_NO_RESPONSE                          equ  444     ;NGINX
HSC_RETRY_WITH                           equ  449     ;MICROSOFT
HSC_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS equ  450     ;MICROSOFT
HSC_UNAVAILABLE_FOR_LEGAL_REASONS        equ  451
HSC_CLIENT_CLOSED_REQUEST                equ  499     ;NGINX
HSC_INTERNAL_SERVER_ERROR                equ  500
HSC_NOT_IMPLEMENTED                      equ  501
HSC_BAD_GATEWAY                          equ  502
HSC_SERVICE_UNAVAILABLE                  equ  503
HSC_GATEWAY_TIMEOUT                      equ  504
HSC_HTTP_VERSION_NOT_SUPPORTED           equ  505
HSC_VARIANT_ALSO_NEGOTIATES              equ  506     ;EXPERIMENTAL
HSC_INSUFFICIENT_STORAGE                 equ  507     ;WEBDAV
HSC_LOOP_DETECTED                        equ  508     ;WEBDAV
HSC_BANDWIDTH_LIMIT_EXCEEDED             equ  509     ;APACHE
HSC_NOT_EXTENDED                         equ  510
HSC_NETWORK_AUTHENTICATION_REQUIRED      equ  511
HSC_NETWORK_READ_TIMEOUT_ERROR           equ  598
HSC_NETWORK_CONNECT_TIMEOUT_ERROR        equ  599


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DataChunk
; Purpose:

Object DataChunk, 0, Primer
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, DWORD

  DefineVariable    pBuffer,          POINTER,  0
  DefineVariable    dBufferSize,      DWORD,    0
  DefineVariable    dBufferUsed,      DWORD,    0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     HttpServer
; Purpose:    This object provides the functionality of an HTTP server.

Object HttpServer, HttpServerID, Streamable
  VirtualMethod     AddURL,           PSTRINGW
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER
  VirtualMethod     HandleGetRequest, PHTTP_REQUEST
  VirtualMethod     HandlePostRequest,PHTTP_REQUEST
  VirtualMethod     ReceiveRequests
  VirtualMethod     Run
  VirtualMethod     SendResponse,     PHTTP_REQUEST, WORD, PSTRINGA, PSTRINGA

  DefineVariable    HttpApiVersion,   HTTPAPI_VERSION,  HTTPAPI_VERSION_1
  DefineVariable    dCommand,         DWORD,      CMD_STOP
  DefineVariable    hThread,          HANDLE,     0
  DefineVariable    hRequestQueue,    HANDLE,     0

  Embed   UrlColl,  XWCollection
ObjectEnd

; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataChunk.Done
; Purpose:
; Arguments:  None
; Return:     Nothing.

Method DataChunk.Done, uses xsi
  SetObject xsi
  mov xax, [xsi].pBuffer
  .if xax
    MemFree xax
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataChunk.Init
; Purpose:
; Arguments:  Arg1: -> Owner
;             Arg2: Buffer size to allocate
; Return:     Nothing.

Method DataChunk.Init, uses xsi, pOwner:POINTER, dBufferSize:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].dBufferSize, dBufferSize, eax
  MemAlloc eax
  mov [xsi].pBuffer, xax
MethodEnd

; ==================================================================================================

MAX_ULONG_STR equ 16*sizeof(CHR)    ;sizeof("4294967295") + ZTC + 5 padding chars = 16

InitHttpResponse macro Response, StatusCode, pReason
  invoke MemZero, addr Response, sizeof(Response)
  m2m Response.StatusCode, StatusCode, ax
  m2m Response.pReason, pReason, xcx
  invoke StrSizeA, pReason                              ;Size in bytes including ZTC
  dec eax                                               ;Discard the ZTC
  mov Response.ReasonLength, ax
endm

AddKnownHeader macro Response, HeaderId, pRawValA
  m2m Response.Headers.KnownHeaders[HeaderId*sizeof(HTTP_KNOWN_HEADER)].pRawValue, pRawValA, xcx
  invoke StrSizeA, pRawValA                             ;Size in bytes including ZTC
  dec eax                                               ;Discard the ZTC
  mov Response.Headers.KnownHeaders[HeaderId*sizeof(HTTP_KNOWN_HEADER)].RawValueLength, ax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.AddURL
; Purpose:    Add a new URL that the server listens to.
; Arguments:  Arg1: -> URL (WIDE String)
; Return:     eax = NO_ERROR indicates success, otherwise ERROR_XXX.
; Links:      https://stackoverflow.com/questions/6721153/httpaddurl-on-localhost-fails-for-non-admin-users

Method HttpServer.AddURL, uses xbx xsi, pURL:PSTRINGW
  SetObject xsi
  invoke HttpAddUrl, [xsi].hRequestQueue, pURL, NULL
  .if eax == NO_ERROR
    OCall [xsi].UrlColl::XWCollection.Insert, pURL
    mov eax, NO_ERROR
  .else
    mov ebx, eax
    OCall xsi.ErrorReport, NULL, HSV_ADDR_REG_ERROR
    mov eax, ebx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.Done
; Purpose:    Finalize the server.
; Arguments:  Arg1: None.
; Return:     Nothing.

RemoveUrl proc pURL:PSTRINGW, hRequestQueue:HANDLE, Arg:XWORD
  invoke HttpRemoveUrl, hRequestQueue, pURL
  ret
RemoveUrl endp

Method HttpServer.Done, uses xsi
  SetObject xsi
  mov [xsi].dCommand, CMD_STOP
  invoke WaitForSingleObject, [xsi].hThread, 500
  .if eax == WAIT_TIMEOUT
    invoke TerminateThread, [xsi].hThread, 0
  .endif
  invoke CloseHandle, [xsi].hThread

  .if [xsi].hRequestQueue != 0
    OCall [xsi].UrlColl::XWCollection.ForEach, addr RemoveUrl, [xsi].hRequestQueue, NULL
    invoke HttpCloseRequestQueue, [xsi].hRequestQueue
  .endif
  invoke HttpTerminate, HTTP_INITIALIZE_SERVER, NULL
  OCall [xsi].UrlColl::XWCollection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.HandleGetRequest
; Purpose:    Handle an HTTP Get response.
; Arguments:  Arg1: -> HTTP_REQUEST.
; Return:     eax = NO_ERROR if succeeded, otherwise a system error code.
; Link:       https://learn.microsoft.com/de-de/windows/win32/http/http-server-sample-application

Method HttpServer.HandleGetRequest,, pRequest:PHTTP_REQUEST
  SetObject xcx
  OCall xcx.SendResponse, pRequest, HSC_OK, $OfsCStrA("OK"), $OfsCStrA("You hit the DebugCenter server.", CRLF)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.HandlePostRequest
; Purpose:    Handle an HTTP Post response.
; Arguments:  Arg1: -> HTTP_REQUEST.
; Return:     eax = NO_ERROR if succeeded, otherwise a system error code.
; Link:       https://learn.microsoft.com/de-de/windows/win32/http/http-server-sample-application

Method HttpServer.HandlePostRequest, uses xbx xdi xsi, pRequest:PHTTP_REQUEST
  local dResult:DWORD, dBytesSent:DWORD
  local pEntityBuffer:PSTRING, dEntityBufferSize:DWORD, dBytesRead:DWORD, dTotalBytesRead:DWORD
  local Response:HTTP_RESPONSE_V1, CDS:COPYDATASTRUCT
  local Chuncks:$Obj(Collection)

  CHUNK_SIZE = 2048

  SetObject xsi
  mov dBytesRead, 0
  mov dTotalBytesRead, 0

  New Chuncks::Collection
  OCall Chuncks::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY

  ;Allocate space for an entity buffer. Buffer can be increased on demand.
  New DataChunk
  .if xax
    OCall Chuncks::Collection.Insert, xax
    mov xdi, xax
    OCall xax::DataChunk.Init, xsi, CHUNK_SIZE

    ;Initialize the HTTP response structure
    InitHttpResponse Response, 200, $OfsCStrA("OK")

    ;For POST, echo back the entity from the client
    ;NOTE: If the HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY flag had been passed with
    ;      HttpReceiveHttpRequest(), the entity would have been a part of HTTP_REQUEST
    ;      (using the pEntityChunks field). Because that flag was not passed, there
    ;      are no o entity bodies in HTTP_REQUEST.

    mov xbx, pRequest
    .ifBitSet [xbx].HTTP_REQUEST_V1.Flags, HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS
      ;The entity body is sent over multiple calls. Collect them in mem and send back.
      .while TRUE
        ;Read the entity chunk from the request.
        invoke HttpReceiveRequestEntityBody, [xsi].hRequestQueue, [xbx].HTTP_REQUEST_V1.RequestId, 0, \
                                             [xdi].$Obj(DataChunk).pBuffer, \
                                             [xdi].$Obj(DataChunk).dBufferSize, \
                                             addr [xdi].$Obj(DataChunk).dBufferUsed, NULL
        .if eax == NO_ERROR
          .if [xdi].$Obj(DataChunk).dBufferUsed != 0
            mov eax, [xdi].$Obj(DataChunk).dBufferUsed
            add dTotalBytesRead, eax
            New DataChunk
            .break .if !xax
            OCall Chuncks::Collection.Insert, xax
            mov xdi, xax
            OCall xax::DataChunk.Init, xsi, CHUNK_SIZE
          .endif

        .elseif eax == ERROR_HANDLE_EOF
          ;The last request entity body has been read. Send back a response.
          ;To illustrate entity sends via HttpSendResponseEntityBody, the response will be
          ;sent over multiple calls. To do this, pass the HTTP_SEND_RESPONSE_FLAG_MORE_DATA flag.
          MemAlloc dTotalBytesRead
          .break .if !xax
          mov pEntityBuffer, xax
          mov xbx, xax
          .ColForEach Chuncks
            mov edi, [xax].$Obj(DataChunk).dBufferUsed
            invoke MemClone, xbx, [xax].$Obj(DataChunk).pBuffer, edi
            add xbx, xdi
          .ColNext

          invoke Base64Decode, pEntityBuffer, dTotalBytesRead, NULL
          .if xax
            mov xbx, xax
            mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
            mov CDS.lpData, xax
            mov CDS.cbData, ecx
            mov xcx, [xsi].pOwner

            ;Reuse the existing WM_COPYDATA code
            invoke SendMessage, [xcx].$Obj(Window).hWnd, WM_COPYDATA, -1, addr CDS
            MemFree xbx
          .endif

          OCall xsi.SendResponse, pRequest, HSC_OK, \
                                  $OfsCStrA("OK"), $OfsCStrA("Post request served.", CRLF)
          xor eax, eax
          mov dResult, eax
          MemFree pEntityBuffer
          mov eax, dResult
          .break
        .else
          mov eax, NO_ERROR                             ;Ignore the rest
          .break

        .endif
      .endw

    .else
      ;This request does not have an entity body.
      invoke HttpSendHttpResponse, [xsi].hRequestQueue, [xbx].HTTP_REQUEST_V1.RequestId, 0, \
                                   addr Response, NULL, addr dBytesSent,
                                   NULL, 0, NULL, NULL
    .endif
  .endif
MethodEnd

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:     HttpServer.HandlePostRequest
;; Purpose:    Handle an HTTP Post response.
;; Arguments:  Arg1: -> HTTP_REQUEST.
;; Return:     eax = NO_ERROR if succeeded, otherwise a system error code.
;; Link:       https://learn.microsoft.com/de-de/windows/win32/http/http-server-sample-application
;
;Method HttpServer.HandlePostRequest, uses xbx xdi xsi, pRequest:PHTTP_REQUEST
;  local dResult:DWORD, dBytesSent:DWORD
;  local pEntityBuffer:PSTRING, dEntityBufferSize:DWORD, dBytesRead:DWORD
;  local dTotalBytesRead:DWORD, TotalBytesToRead:DWORD
;  local pUnencryptedBuffer:POINTER, dTotalUnencryptedSize:DWORD, dUnencryptedSize:DWORD
;  local Response:HTTP_RESPONSE
;  local Chuncks:$Obj(Collection)
;  local CDS:COPYDATASTRUCT
;
;  CHUNK_SIZE = 2048
;
;  SetObject xsi
;  mov dBytesRead, 0
;  mov TotalBytesToRead, 0
;  mov dTotalBytesRead, 0
;  mov pUnencryptedBuffer, NULL
;  mov dTotalUnencryptedSize, 0
;
;  New Chuncks::Collection
;  OCall Chuncks::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;
;  ;Allocate space for an entity buffer. Buffer can be increased on demand.
;  New DataChunk
;  .if xax
;    OCall Chuncks::Collection.Insert, xax
;    mov xdi, xax
;    OCall xax::DataChunk.Init, xsi, CHUNK_SIZE
;
;    ;Initialize the HTTP response structure
;    InitHttpResponse Response, 200, $OfsCStrA("OK")
;
;    ;For POST, echo back the entity from the client
;    ;NOTE: If the HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY flag had been passed with
;    ;      HttpReceiveHttpRequest(), the entity would have been a part of HTTP_REQUEST
;    ;      (using the pEntityChunks field). Because that flag was not passed, there
;    ;      are no o entity bodies in HTTP_REQUEST.
;
;    mov xbx, pRequest
;    .ifBitSet [xbx].HTTP_REQUEST.Flags, HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS
;      ;The entity body is sent over multiple calls. Collect them in mem and send back.
;      .while TRUE
;        ;Read the entity chunk from the request.
;        invoke HttpReceiveRequestEntityBody, [xsi].hRequestQueue, [xbx].HTTP_REQUEST.RequestId, 0, \
;                                             [xdi].$Obj(DataChunk).pBuffer, \
;                                             [xdi].$Obj(DataChunk).dBufferSize, \
;                                             addr [xdi].$Obj(DataChunk).dBufferUsed, NULL
;        .if eax == NO_ERROR
;          .if [xdi].$Obj(DataChunk).dBufferUsed != 0
;            mov eax, [xdi].$Obj(DataChunk).dBufferUsed
;            add dTotalBytesRead, eax
;            New DataChunk
;            .break .if !xax
;            OCall Chuncks::Collection.Insert, xax
;            mov xdi, xax
;            OCall xax::DataChunk.Init, xsi, CHUNK_SIZE
;          .endif
;
;        .elseif eax == ERROR_HANDLE_EOF
;          ;The last request entity body has been read. Send back a response.
;          ;To illustrate entity sends via HttpSendResponseEntityBody, the response will be
;          ;sent over multiple calls. To do this, pass the HTTP_SEND_RESPONSE_FLAG_MORE_DATA flag.
;          MemAlloc dTotalBytesRead
;          .break .if !xax
;          mov pEntityBuffer, xax
;          mov xbx, xax
;          .ColForEach Chuncks
;            mov edi, [xax].$Obj(DataChunk).dBufferUsed
;            invoke MemClone, xbx, [xax].$Obj(DataChunk).pBuffer, edi
;            add xbx, xdi
;          .ColNext
;
;          invoke CryptStringToBinaryA, pEntityBuffer, dTotalBytesRead, CRYPT_STRING_BASE64, NULL, addr dUnencryptedSize, NULL, NULL
;          MemAlloc dUnencryptedSize
;          .if xax
;            mov pUnencryptedBuffer, xax
;            invoke CryptStringToBinaryA, pEntityBuffer, dTotalBytesRead, CRYPT_STRING_BASE64, pUnencryptedBuffer, addr dUnencryptedSize, NULL, NULL
;            mov xcx, [xsi].pOwner
;            mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
;            m2m CDS.lpData, pUnencryptedBuffer, xax
;            m2m CDS.cbData, dUnencryptedSize, eax
;            invoke SendMessage, [xcx].$Obj(Window).hWnd, WM_COPYDATA, -1, addr CDS
;            MemFree pUnencryptedBuffer
;          .endif
;
;          OCall xsi.SendResponse, pRequest, HSC_OK, \
;                                  $OfsCStrA("OK"), $OfsCStrA("Post request served.", CRLF)
;          xor eax, eax
;          mov dResult, eax
;          MemFree pEntityBuffer
;          mov eax, dResult
;          .break
;        .else
;          mov eax, NO_ERROR                             ;Ignore the rest
;          .break
;
;        .endif
;      .endw
;
;    .else
;      ;This request does not have an entity body.
;      invoke HttpSendHttpResponse, [xsi].hRequestQueue, [xbx].HTTP_REQUEST.RequestId, 0, \
;                                   addr Response, NULL, addr dBytesSent,
;                                   NULL, 0, NULL, NULL
;    .endif
;  .endif
;MethodEnd
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.Init
; Purpose:    Initialize the server.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method HttpServer.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner

; https://learn.microsoft.com/hr-HR/troubleshoot/windows-server/application-management/http-listener-fails-initialize
  invoke GetCurrentProcess
  invoke SetPrivilegeToken, xax, $OfsCStr("SeChangeNotifyPrivilege"), TRUE

  invoke HttpInitialize, [xsi].HttpApiVersion, HTTP_INITIALIZE_SERVER, NULL
  invoke HttpCreateRequestQueue, [xsi].HttpApiVersion, NULL, NULL, 0, addr [xsi].hRequestQueue
  OCall [xsi].UrlColl::XWCollection.Init, xsi, 10, 10, 0FFFFFFFFh
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.ReceiveRequests
; Purpose:    The function to receive a request. This function calls the corresponding function to
;             handle the response. This method is executed in it own thread.
; Arguments:  Arg1: None.
; Return:     Nothing.

Method HttpServer.ReceiveRequests, uses xsi
  local dResult:DWORD, RequestId:QWORD, dBytesRead:DWORD
  local pRequest:PHTTP_REQUEST, dRequestSize:DWORD

  SetObject xsi
  ;Allocate a 2 KB buffer. This size should work for most requests.
  ;The buffer size can be increased if required. Space is also required for an HTTP_REQUEST struct.
  mov dRequestSize, sizeof(HTTP_REQUEST) + 2048;
  MemAlloc dRequestSize
  .if xax != NULL
    mov pRequest, xax

    ;Wait for a new request. This is indicated by a NULL request ID.
    if TARGET_BITNESS eq 32
      mov DWORD ptr RequestId[0], HTTP_NULL_ID
      mov DWORD ptr RequestId[4], HTTP_NULL_ID
    else
      mov RequestId, HTTP_NULL_ID
    endif

    .while [xsi].dCommand == CMD_START
      invoke MemZero, pRequest, dRequestSize
      invoke HttpReceiveHttpRequest, [xsi].hRequestQueue, RequestId, 0, pRequest, dRequestSize, \
                                     addr dBytesRead, NULL  ;Synch. call
      .if eax == NO_ERROR
        mov xcx, pRequest
        mov eax, [xcx].HTTP_REQUEST_V1.Verb
        .if eax == HttpVerbGET
          OCall xsi.HandleGetRequest, pRequest

        .elseif eax == HttpVerbPOST
          OCall xsi.HandlePostRequest, pRequest

        .else
          OCall xsi.SendResponse, pRequest, HSC_SERVICE_UNAVAILABLE, \
                                  $OfsCStrA("Not Implemented"), NULL
        .endif
        .break .if eax != NO_ERROR

      .elseif eax == ERROR_MORE_DATA
        ;The input buffer was too small to hold the request headers. Increase the buffer size and
        ;call the API again. When calling the API again, handle the request that failed by passing
        ;a RequestID. This RequestID is read from the old buffer.
        mov xcx, pRequest
        if TARGET_BITNESS eq 32
          m2m DWORD ptr RequestId[0], DWORD ptr [xcx].HTTP_REQUEST.RequestId[0], eax
          m2m DWORD ptr RequestId[4], DWORD ptr [xcx].HTTP_REQUEST.RequestId[4], ecx
        else
          m2m RequestId, [xcx].HTTP_REQUEST_V1.RequestId, xax
        endif
        add dRequestSize, 2048
        MemReAlloc pRequest, dRequestSize
        .break .if xax == NULL
        mov pRequest, xax

      if TARGET_BITNESS eq 32
      .elseif eax == ERROR_CONNECTION_INVALID && \
              ((DWORD ptr RequestId[0] != HTTP_NULL_ID) || \
               (DWORD ptr RequestId[4] != HTTP_NULL_ID))
        ;The TCP connection was corrupted by the peer when attempting to handle a request with
        ;more buffer. Continue to the next request.
        mov DWORD ptr RequestId[0], HTTP_NULL_ID
        mov DWORD ptr RequestId[4], HTTP_NULL_ID
      else
      .elseif eax == ERROR_CONNECTION_INVALID && RequestId != HTTP_NULL_ID
        ;The TCP connection was corrupted by the peer when attempting to handle a request with
        ;more buffer. Continue to the next request.
        mov RequestId, HTTP_NULL_ID
      endif
      .else
        .break

      .endif
    .endw
    MemFree pRequest
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.Run
; Purpose:    Run the server.
; Arguments:  None.
; Return:     Nothing.

Method HttpServer.Run, uses xsi
  SetObject xsi
  invoke CreateThread, NULL, 0, $MethodAddr(xsi::HttpServer.ReceiveRequests), \
                       xsi, CREATE_SUSPENDED, NULL
  mov [xsi].hThread, xax
  mov [xsi].dCommand, CMD_START
  invoke ResumeThread, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HttpServer.SendResponse
; Purpose:    Send an HTTP response.
; Arguments:  Arg1: Request Queue HANDLE.
;             Arg2: -> HTTP_REQUEST.
;             Arg3: Status Code.
;             Arg4: -> Reason ANSI string.
;             Arg5: -> Entity ANSI string.
; Return:     eax = NO_ERROR if succeeded, otherwise a system error code.

Method HttpServer.SendResponse, uses xsi, pRequest:PHTTP_REQUEST, wStatusCode:WORD, \
                                          pReason:PSTRINGA, pEntityString:PSTRINGA
  local Response:HTTP_RESPONSE_V1, DataChunk:HTTP_DATA_CHUNK, dBytesSent:DWORD

  SetObject xsi

  ;Initialize the HTTP response structure
  InitHttpResponse Response, wStatusCode, pReason

  ;Add a known header.
  AddKnownHeader Response, HttpHeaderContentType, $OfsCStrA("text/html")

  .if pEntityString != NULL
    mov DataChunk.DataChunkType, HttpDataChunkFromMemory
    m2m DataChunk.FromMemory.pBuffer, pEntityString, xcx
    mov DataChunk.FromMemory.BufferLength, $32($invoke(StrSizeA, pEntityString))

    mov Response.EntityChunkCount, 1
    lea xax, DataChunk
    mov Response.pEntityChunks, xax
  .endif

  ;Because the entity body is sent in one call, it is not required to specify the Content-Length.
  mov xdx, pRequest
  invoke HttpSendHttpResponse, [xsi].hRequestQueue, [xdx].HTTP_REQUEST_V1.RequestId, 0, addr Response, \
                               NULL, addr dBytesSent, NULL, 0, NULL, NULL
MethodEnd
