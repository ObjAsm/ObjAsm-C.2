; ==================================================================================================
; Title:      WebTextTranslator.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of WebTextTranslator objects.
; Notes:      Version C.1.0, November 2022
;               - First release.
; ==================================================================================================


WTT_TRANSLATION struct
  pText         PSTRINGW  ?
  pHint         PSTRINGW  ?
  pTranslation  PSTRINGW  ?
WTT_TRANSLATION ends
PWTT_TRANSLATION typedef ptr WTT_TRANSLATION

; --------------------------------------------------------------------------------------------------
; Object:     WebTextTranslator
; Purpose:    This object is able to translate a text in any supported language using the free
;             Web translation service from GOOGLE.
; Links:      https://cloud.google.com/translate/docs/languages

Object WebTextTranslator, WebTextTranslatorID, SortedCollection
  RedefineMethod    Compare,            PSTRINGW, PSTRINGW
  RedefineMethod    DestroyItem,        PWTT_TRANSLATION
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PSTRING, PSTRING
  VirtualMethod     Translate,          PSTRING, PSTRING
  RedefineMethod    GetItem,            $ObjPtr(Stream)                     ;-> Stream
  RedefineMethod    PutItem,            $ObjPtr(Stream), PWTT_TRANSLATION   ;-> Stream, -> Item
  RedefineMethod    KeyOf,              PWTT_TRANSLATION

  DefineVariable    pSrcLang,           PSTRING,      NULL
  DefineVariable    pDstLang,           PSTRING,      NULL
  DefineVariable    hInternet,          HINTERNET,    0
  DefineVariable    hConnect,           HINTERNET,    0
  DefineVariable    pRcvBufferUTF8,     POINTER,      NULL
  DefineVariable    pRcvBufferW,        POINTER,      NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

RCV_BUFFER_SIZE equ 4*PAGESIZE         ;Reserve 4 pages, should be enought

WTT_DELIMITERS struct
  dBegSize      DWORD     ?
  pBegDelimiter PSTRINGW  ?
  dEndSize      DWORD     ?
  pEndDelimiter PSTRINGW  ?
WTT_DELIMITERS ends

.const
WTT_DELIMITER_LIST label WTT_DELIMITERS
  WTT_DELIMITERS  {12, $OfsTStrW("&quot;"), 12, $OfsTStrW("&quot;")}
  WTT_DELIMITERS  {02, $OfsTStrW("«"),      02, $OfsTStrW("»")}
  WTT_DELIMITERS  {02, $OfsTStrW(201Ch),    02, $OfsTStrW(201Dh)}
  WTT_DELIMITERS  {02, $OfsTStrW(300Ch),    02, $OfsTStrW(300Dh)}
  WTT_DELIMITERS  {02, $OfsTStrW(201Eh),    02, $OfsTStrW(201Ch)}
  WTT_DELIMITERS  {00, NULL,                00, NULL}

.code
; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.Compare
; Purpose:    Compare the WIDE strings Key1 and Key2.
; Arguments:  Arg1: -> First key.
;             Arg2: -> Second key.
; Return:     eax =   (-)  if Key1 < Key2
;                      0   if Key1 = Key2
;                     (+)  if Key1 > Key2

Method WebTextTranslator.Compare,, pKey1:PSTRINGW, pKey2:PSTRINGW
  invoke StrCompW, pKey1, pKey2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.DestroyItem
; Purpose:    Auxiliar function to dispose a item from the collection. Don't call directly!
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method WebTextTranslator.DestroyItem, uses xbx, pItem:PWTT_TRANSLATION
  .if pItem != NULL
    mov xbx, pItem
    invoke StrDispose, [xbx].WTT_TRANSLATION.pText
    invoke StrDispose, [xbx].WTT_TRANSLATION.pHint
    invoke StrDispose, [xbx].WTT_TRANSLATION.pTranslation
    MemFree xbx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.Done
; Purpose:    Finalizes the object.
; Arguments:  None.
; Return:     Nothing.

Method WebTextTranslator.Done, uses xsi
  SetObject xsi
  .if [xsi].hConnect != 0
    invoke InternetCloseHandle, [xsi].hConnect
  .endif
  .if [xsi].hInternet != 0
    invoke InternetCloseHandle, [xsi].hInternet
  .endif
  .if [xsi].pRcvBufferUTF8 != NULL
    invoke VirtualFree, [xsi].pRcvBufferUTF8, 0, MEM_RELEASE
  .endif
  .if [xsi].pRcvBufferW != NULL
    invoke VirtualFree, [xsi].pRcvBufferW, 0, MEM_RELEASE
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.GetItem
; Purpose:    Read a string from the stream by calling Stream.ReadStr.
; Arguments:  Arg1: -> Stream object.
; Return:     xax -> WTT_TRANSLATION.

Method WebTextTranslator.GetItem, uses xbx, pStream:$ObjPtr(Stream)
  MemAlloc sizeof WTT_TRANSLATION
  .if xax != NULL
    mov xbx, xax
    mov [xbx].WTT_TRANSLATION.pText, $OCall(pStream::Stream.StrRead)
    mov [xbx].WTT_TRANSLATION.pHint, $OCall(pStream::Stream.StrRead)
    mov [xbx].WTT_TRANSLATION.pTranslation, $OCall(pStream::Stream.StrRead)
    mov xax, xbx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.PutItem
; Purpose:    Write the WIDE string item on to the Stream by calling Stream.WriteStrW.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> WTT_TRANSLATION.
; Return:     Nothing.

Method WebTextTranslator.PutItem, uses xbx, pStream:$ObjPtr(Stream), pItem:PWTT_TRANSLATION
  .if pItem != NULL
    mov xbx, pItem
    OCall pStream::Stream.StrWriteW, [xbx].WTT_TRANSLATION.pText
    OCall pStream::Stream.StrWriteW, [xbx].WTT_TRANSLATION.pHint 
    OCall pStream::Stream.StrWriteW, [xbx].WTT_TRANSLATION.pTranslation
  .endif 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner.
;             Arg2: -> Destination language.
;             Arg3: -> Source language.
; Return:     Nothing.
; Note:       See https://cloud.google.com/translate/docs/languages

Method WebTextTranslator.Init, uses xsi, pOwner:POINTER, pDstLang:PSTRING, pSrcLang:PSTRING
  SetObject xsi
  ACall xsi.Init, pOwner, 10, 10, COL_MAX_CAPACITY
  mov [xsi].dDuplicates, FALSE
  m2m [xsi].pSrcLang, pSrcLang, xax
  m2m [xsi].pDstLang, pDstLang, xcx
  invoke InternetOpen, NULL, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0
  .if xax != 0
    mov [xsi].hInternet, xax
    invoke InternetConnect, [xsi].hInternet, $OfsCStr("translate.google.com"), \
                            INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL
    .if xax != 0
      mov [xsi].hConnect, xax

      invoke VirtualAlloc, NULL, RCV_BUFFER_SIZE, MEM_COMMIT, PAGE_READWRITE
      .if xax != NULL
        mov [xsi].pRcvBufferUTF8, xax
        invoke VirtualAlloc, NULL, sizeof(CHRW)*RCV_BUFFER_SIZE, MEM_COMMIT, PAGE_READWRITE
        .if xax != NULL
          mov [xsi].pRcvBufferW, xax
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.KeyOf
; Purpose:    KeyOf is overridden in cases where the key of the item is not the item itself.
; Arguments:  Arg1: -> Item.
; Return:     eax = Given an item from the collection, KeyOf should return the corresponding key of
;                   the item.

Method WebTextTranslator.KeyOf,, pItem:PWTT_TRANSLATION
  ?mov xdx, pItem
  mov xax, [xdx].WTT_TRANSLATION.pText
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WebTextTranslator.Translate
; Purpose:    Translates a given text. For a better translation, a hint thext can be supplied, e.g.
;             a context keyword.
; Arguments:  Arg1: -> Text to be translated.
;             Arg2: -> Text hint.
; Return:     xax -> Translated wide text. The returned string must be deallocated using StrDispose.

Method WebTextTranslator.Translate, uses xbx xdi xsi, pSrcText:PSTRING, pHint:PSTRING
  local hRequest:HINTERNET, cURI[128]:CHR, pItem:PWTT_TRANSLATION
  local dBytesRead:DWORD, pStartChar:POINTER, pTranslation:PSTRINGW

  SetObject xsi
  mov pTranslation, NULL
  OCall xsi.Search, pSrcText
  .if eax == FALSE
    mov edi, ecx
    MemAlloc sizeof WTT_TRANSLATION
    .if xax != NULL
      mov pItem, xax
      mov xbx, xax
      mov [xbx].WTT_TRANSLATION.pText, $invoke(StrNew, pSrcText)
      mov [xbx].WTT_TRANSLATION.pHint, $invoke(StrNew, pHint)
      m2z [xbx].WTT_TRANSLATION.pTranslation
      OCall xsi.InsertAt, edi, xbx
    
      lea xdi, cURI
      .if pHint == NULL
        WriteF xdi, '/m?hl=en&tl=¦ST&sl=¦ST&q="¦ST"', [xsi].pDstLang, [xsi].pSrcLang, pSrcText
      .else
        WriteF xdi, '/m?hl=en&tl=¦ST&sl=¦ST&q=¦ST "¦ST"', [xsi].pDstLang, [xsi].pSrcLang, pHint, pSrcText
      .endif
      invoke HttpOpenRequest, [xsi].hConnect, NULL, addr cURI, NULL, NULL, NULL, \
                              INTERNET_FLAG_RELOAD or INTERNET_FLAG_EXISTING_CONNECT or \
                              INTERNET_FLAG_SECURE, NULL
      .if xax != 0
        mov hRequest, xax
        invoke HttpSendRequest, hRequest, NULL, 0, NULL, 0
        mov xdi, [xsi].pRcvBufferUTF8
        mov ebx, RCV_BUFFER_SIZE - 1
        .repeat
          invoke InternetReadFile, hRequest, xdi, ebx, addr dBytesRead
          mov ecx, dBytesRead
          .break .if eax == 0 || ecx == 0
          add xdi, xcx
          sub ebx, ecx
        .until FALSE
        mov CHRA ptr [xdi], 0
    
        invoke UTF8ToWide, [xsi].pRcvBufferW, [xsi].pRcvBufferUTF8, sizeof(CHRW)*RCV_BUFFER_SIZE
        .if ecx == 0
          invoke StrPosW, [xsi].pRcvBufferW, $OfsCStrW(3Ch, 'div class="result-container"', 3Eh)
          .if xax != NULL
            mov xbx, offset WTT_DELIMITER_LIST
            lea xdi, [xax + sizeof(CHRW)*30]
            
            invoke StrPosW, xdi, $OfsCStrW(3Ch, "/div", 3Eh)
            mov CHRW ptr [xax], 0
            .while [xbx].WTT_DELIMITERS.dBegSize != 0
              invoke StrPosW, xdi, [xbx].WTT_DELIMITERS.pBegDelimiter
              .if xax != NULL
                mov ecx, [xbx].WTT_DELIMITERS.dBegSize
                add xax, xcx
                mov pStartChar, xax
                invoke StrPosW, xax, [xbx].WTT_DELIMITERS.pEndDelimiter
                .if xax != NULL
                  mov CHRW ptr [xax], 0
                  invoke StrNewW, pStartChar
                  mov xcx, pItem
                  mov [xcx].WTT_TRANSLATION.pTranslation, xax
                  mov pTranslation, xax
                  .break
                .endif
              .endif
              add xbx, sizeof WTT_DELIMITERS
            .endw
          .endif
        .endif
      .endif
    .endif
    mov xax, pTranslation
  .else
    mov edx, ecx
    OCall xsi.ItemAt, edx
    mov xax, [xax].WTT_TRANSLATION.pTranslation
  .endif
MethodEnd

endif
