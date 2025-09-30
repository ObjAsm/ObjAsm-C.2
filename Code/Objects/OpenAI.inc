; ==================================================================================================
; Title:      OpenAI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OpenAI objects.
; Links:      https://platform.openai.com/docs/api-reference/authentication
; Notes:      Version C.1.0, September 2025
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     OpenAI
; Purpose:    This object is used to communicate with OpenAI.
; Note:       Requires an environment variable called "OPENAI_API_KEY" to hold the OpenAI key.  

Object OpenAI,, CloudAI
  RedefineMethod    Init,             POINTER, PSTRING  ;-> Owner object, -> AiModel
  RedefineMethod    GetResponse
  RedefineMethod    SendPrompt,       PSTRING

  DefineVariable    pAiModel,         PSTRING,      NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

.const
String cOpenAiHeaders,  "Authorization: Bearer %OPENAI_API_KEY%", CRLF
ExtendString            "Content-Type: application/json"
String cOpenAiHostUrl,  "api.openai.com"
String cOpenAiUrlPath,  "/v1/responses"

;Test response:
;StringA cResponse,  '{', CRLF
;ExtendStringA       '  "id": "resp_68d93d6900d081908e52da95d2b8f452093675b15f35b8fe",', CRLF
;ExtendStringA       '  "object": "response",', CRLF
;ExtendStringA       '  "created_at": 1759067497,', CRLF
;ExtendStringA       '  "status": "completed",', CRLF
;ExtendStringA       '  "background": false,', CRLF
;ExtendStringA       '  "billing": {"payer": "developer"},', CRLF
;ExtendStringA       '  "error": null,', CRLF
;ExtendStringA       '  "incomplete_details": null,', CRLF
;ExtendStringA       '  "instructions": null,', CRLF
;ExtendStringA       '  "max_output_tokens": null,', CRLF
;ExtendStringA       '  "max_tool_calls": null,', CRLF
;ExtendStringA       '  "model": "gpt-5-2025-08-07",', CRLF
;ExtendStringA       '  "output": [', CRLF
;ExtendStringA       '      {', CRLF
;ExtendStringA       '          "id": "rs_68d93d69d6808190b6d0deb82041bdab093675b15f35b8fe",', CRLF
;ExtendStringA       '          "type": "reasoning",', CRLF
;ExtendStringA       '          "summary": []', CRLF
;ExtendStringA       '      },', CRLF
;ExtendStringA       '      {', CRLF
;ExtendStringA       '          "id": "msg_68d93d6b132881908dca29c7d0c6b856093675b15f35b8fe",', CRLF
;ExtendStringA       '          "type": "message",', CRLF
;ExtendStringA       '          "status": "completed",', CRLF
;ExtendStringA       '          "content": [', CRLF
;ExtendStringA       '              {', CRLF
;ExtendStringA       '                  "type": "output_text",', CRLF
;ExtendStringA       '                  "annotations": [],', CRLF
;ExtendStringA       '                  "logprobs": [],', CRLF
;ExtendStringA       '                  "text": "Under a silver moon, a sleepy unicorn tiptoed through a field of whispering daisies, sprinkling stardust dreams that gently tucked the world in for the night."', CRLF
;ExtendStringA       '              }', CRLF
;ExtendStringA       '          ],', CRLF
;ExtendStringA       '          "role": "assistant"', CRLF
;ExtendStringA       '      }', CRLF
;ExtendStringA       '  ],', CRLF
;ExtendStringA       '  "parallel_tool_calls": true,', CRLF
;ExtendStringA       '  "previous_response_id": null,', CRLF
;ExtendStringA       '  "prompt_cache_key": null,', CRLF
;ExtendStringA       '  "reasoning": {', CRLF
;ExtendStringA       '      "effort": "medium",', CRLF
;ExtendStringA       '      "summary": null', CRLF
;ExtendStringA       '  },', CRLF
;ExtendStringA       '  "safety_identifier": null,', CRLF
;ExtendStringA       '  "service_tier": "default",', CRLF
;ExtendStringA       '  "store": true,', CRLF
;ExtendStringA       '  "temperature": 1,', CRLF
;ExtendStringA       '  "text": {', CRLF
;ExtendStringA       '      "format": {', CRLF
;ExtendStringA       '          "type": "text"', CRLF
;ExtendStringA       '      },', CRLF
;ExtendStringA       '      "verbosity": "medium"', CRLF
;ExtendStringA       '  },', CRLF
;ExtendStringA       '  "tool_choice": "auto",', CRLF
;ExtendStringA       '  "tools": [],', CRLF
;ExtendStringA       '  "top_logprobs": 0,', CRLF
;ExtendStringA       '  "top_p": 1,', CRLF
;ExtendStringA       '  "truncation": "disabled",', CRLF
;ExtendStringA       '  "usage": {', CRLF
;ExtendStringA       '      "input_tokens": 17,', CRLF
;ExtendStringA       '      "input_tokens_details": {', CRLF
;ExtendStringA       '          "cached_tokens": 0', CRLF
;ExtendStringA       '      },', CRLF
;ExtendStringA       '      "output_tokens": 106,', CRLF
;ExtendStringA       '      "output_tokens_details": {', CRLF
;ExtendStringA       '          "reasoning_tokens": 64', CRLF
;ExtendStringA       '      },', CRLF
;ExtendStringA       '      "total_tokens": 123', CRLF
;ExtendStringA       '  },', CRLF
;ExtendStringA       '  "user": null,', CRLF
;ExtendStringA       '  "metadata": {}', CRLF
;ExtendStringA       '}'
;$$ResponseLen = ??StrLength

.code
; ==================================================================================================
;    OpenAI implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     OpenAI.Init
; Purpose:    Initialize the OpenAI object and open an Internet connection to the cloud host.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> AI model.
; Return:     Nothing.

Method OpenAI.Init,, pOwner:POINTER, pAiModel:PSTRING
  SetObject xcx

  m2m [xcx].pAiModel, pAiModel, xax
  ACall xcx.Init, pOwner, addr cOpenAiHostUrl
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OpenAI.GetResponse
; Purpose:    Retrieve AI response.
; Arguments:  None.
; Return:     xax -> Response string. Must be disposed using StrDispose when no longer needed.

Method OpenAI.GetResponse, uses xbx xdi xsi
  local Response:$Obj(Json), pResponse:PSTRING
  local pOutput:PJSON_PROPERTY, pOutputObject:PJSON_PROPERTY
  local pContent:PJSON_PROPERTY, pContentObject:PJSON_PROPERTY

  SetObject xsi
  mov pResponse, NULL
  New Response::Json
  OCall Response::Json.Init, xsi
  OCall Response::Json.Read, addr [xsi].MemStream
  OCall Response::Json.GetProperty, addr Response.RootProperty, $OfsCStr("output")
  .if xax != NULL
    mov pOutput, xax
    xor ebx, ebx
    .while TRUE
      OCall Response::Json.GetArrayItem, pOutput, ebx
      .break .if xax == NULL
      mov pOutputObject, xax
      OCall Response::Json.GetProperty, pOutputObject, $OfsCStr("type")
      .break .if xax == NULL
      invoke StrComp, [xax].JSON_PROPERTY.pValue, $OfsCStr("message")
      .if eax == 0
        OCall Response::Json.GetProperty, pOutputObject, $OfsCStr("content")
        .break .if xax == NULL
        mov pContent, xax
        xor edi, edi
        .while TRUE
          OCall Response::Json.GetArrayItem, pContent, edi
          .break .if xax == NULL
          mov pContentObject, xax
          OCall Response::Json.GetProperty, pContentObject, $OfsCStr("type")
          .break .if xax == NULL
          invoke StrComp, [xax].JSON_PROPERTY.pValue, $OfsCStr("output_text")
          .if eax == 0
            OCall Response::Json.GetProperty, pContentObject, $OfsCStr("text")
            .break .if xax == NULL
            mov pResponse, $invoke(StrNew, [xax].JSON_PROPERTY.pValue)
            jmp @@Exit
          .endif
          inc edi
        .endw
      .endif
      inc ebx
    .endw
  .endif

@@Exit:
  mov xax, pResponse
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OpenAI.SendPrompt
; Purpose:    Send a prompt to OpenAI.
; Arguments:  Arg1: -> PSTRING.
; Return:     Nothing.

Method OpenAI.SendPrompt, uses xbx xdi xsi, pPrompt:PSTRING
  local hRequest:HINTERNET, dBytesRead:DWORD
  local pBody:POINTER, dBodySize:DWORD
  local cExpandedHeaders[4096]:CHR

  SetObject xsi
  .if pPrompt != NULL
    invoke StrLength, pPrompt
    add eax, 200*sizeof(CHR)                            ;Add 200 extra CHRs for the rest of the JSON
    MemAlloc eax
    .if xax != NULL
      mov pBody, xax
      mov xbx, pBody
      WriteF xbx, "{\`model\`:\`¦ST\`,\`input\`:\`¦ST\`}", [xsi].pAiModel, pPrompt
      sub xbx, pBody                                    ;ebx = body size without ZTC
      invoke HttpOpenRequest, [xsi].hConnect, $OfsCStr("POST"), addr cOpenAiUrlPath, \
                              NULL, NULL, NULL, \
                              INTERNET_FLAG_RELOAD or INTERNET_FLAG_EXISTING_CONNECT or \
                              INTERNET_FLAG_SECURE, NULL
      .if xax != 0
        mov hRequest, xax
        invoke ExpandEnvironmentStrings, addr cOpenAiHeaders, \
                                         addr cExpandedHeaders, lengthof(cExpandedHeaders)
        invoke HttpAddRequestHeaders, hRequest, addr cExpandedHeaders, -1, 0
        invoke HttpSendRequest, hRequest, NULL, 0, pBody, ebx

        mov ebx, RCV_BUFFER_SIZE
        mov xdi, [xsi].MemStream.pBuffer
        .repeat
          invoke InternetReadFile, hRequest, xdi, ebx, addr dBytesRead
          mov ecx, dBytesRead
          .break .if eax == 0 || ecx == 0
          add [xsi].MemStream.dCurrSize, ecx
          add xdi, xcx
          sub ebx, ecx
          .if ebx == 0
            mov edx, [xsi].MemStream.dLimit
            add edx, RCV_BUFFER_SIZE
            OCall [xsi].MemStream::MemoryStream.SetCapacity, edx
            .break .if eax == 0
            mov ebx, RCV_BUFFER_SIZE
          .endif
        .until FALSE
        .if ebx != 0
          mov CHRA ptr [xdi], 0
        .endif

      .endif
    ;  Test response
    ;  invoke StrCopyA, [xsi].MemStream.pBuffer, addr cResponse
    ;  m2m [xsi].MemStream.dCurrSize, $$ResponseLen, ecx
;      DbgStrA [xsi].MemStream.pBuffer
;      DbgDec [xsi].MemStream.dCurrSize
    .endif
  .endif
MethodEnd

endif
