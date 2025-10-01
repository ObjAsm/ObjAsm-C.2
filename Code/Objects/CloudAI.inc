; ==================================================================================================
; Title:      CloudAI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of CloudAI objects.
; Notes:      Version C.1.0, September 2025
;               - First release.
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Object:     CloudAI
; Purpose:    This object is used to communicate with a cloud hosted AI.

Object CloudAI,, Primer
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, PSTRING,   ;-> Owner object, -> URL

  VirtualAbstract   ExtractAnswer
  VirtualAbstract   GetResponse,      HINTERNET
  VirtualAbstract   SendPrompt,       PSTRING

  DefineVariable    hInternet,        HINTERNET,    0
  DefineVariable    hConnect,         HINTERNET,    0

  Embed MemStream,  MemoryStream
ObjectEnd

; ==================================================================================================

if IMPLEMENT
RCV_BUFFER_SIZE equ 4*PAGESIZE         ;Reserve 4 pages, should be enough


.code
; ==================================================================================================
;    CloudAI implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     CloudAI.Done
; Purpose:    Finalize the CloudAI object.
; Arguments:  None.
; Return:     Nothing.

Method CloudAI.Done, uses xsi
  SetObject xsi
  .if [xsi].hConnect != 0
    invoke InternetCloseHandle, [xsi].hConnect
  .endif
  .if [xsi].hInternet != 0
    invoke InternetCloseHandle, [xsi].hInternet
  .endif
  OCall [xsi].MemStream::MemoryStream.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CloudAI.Init
; Purpose:    Initialize the CloudAI object and open an Internet connection to the cloud host
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Host URL.
; Return:     Nothing.

Method CloudAI.Init, uses xsi, pOwner:POINTER, pUrlHost:PSTRING
  local dRecieveTimeout:DWORD

  SetObject xsi

  ACall xsi.Init, pOwner
  mov [xsi].hInternet, 0
  mov [xsi].hConnect, 0
  
  OCall [xsi].MemStream::MemoryStream.Init, xsi, RCV_BUFFER_SIZE, RCV_BUFFER_SIZE, 100*RCV_BUFFER_SIZE

  invoke InternetOpen, $OfsCStr("ObjAsmClient/1.0"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0
  .if xax != 0
    mov [xsi].hInternet, xax
    mov dRecieveTimeout, 60*1000                        ;60 secs
    invoke InternetSetOption, [xsi].hInternet, INTERNET_OPTION_RECEIVE_TIMEOUT, \
                              addr dRecieveTimeout, sizeof dRecieveTimeout
    invoke InternetConnect, [xsi].hInternet, pUrlHost, \
                            INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL
    .if xax != 0
      mov [xsi].hConnect, xax
    .endif
  .endif
MethodEnd

endif
