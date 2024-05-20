;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sperror.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 16/12/2023 11:07:16

;*******************************************************************************
ifndef SPError_h
  SPError_h equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _WINERROR_
      include winerror.inc
    endif
    FACILITY_SAPI equ <FACILITY_ITF>
    SAPI_ERROR_BASE equ 5000h
    MAKE_SAPI_HRESULT macro sev, err
      exitm <MAKE_HRESULT(sev, FACILITY_SAPI, err)>
    endm
    MAKE_SAPI_ERROR macro err
      exitm <MAKE_SAPI_HRESULT(SEVERITY_ERROR, err + SAPI_ERROR_BASE)>
    endm
    MAKE_SAPI_SCODE macro scode
      exitm <MAKE_SAPI_HRESULT(SEVERITY_SUCCESS, scode + SAPI_ERROR_BASE)>
    endm
    ;*** SPERR_UNINITIALIZED                                   0x80045001    -2147201023
    ;*   The object has not been properly initialized.
    ;*
    SPERR_UNINITIALIZED equ MAKE_SAPI_ERROR(001h)
    ;*** SPERR_ALREADY_INITIALIZED                             0x80045002    -2147201022
    ;*   The object has already been initialized.
    ;*
    SPERR_ALREADY_INITIALIZED equ MAKE_SAPI_ERROR(002h)
    ;*** SPERR_UNSUPPORTED_FORMAT                              0x80045003    -2147201021
    ;*   The caller has specified an unsupported format.
    ;*
    SPERR_UNSUPPORTED_FORMAT equ MAKE_SAPI_ERROR(003h)
    ;*** SPERR_INVALID_FLAGS                                   0x80045004    -2147201020
    ;*   The caller has specified invalid flags for this operation.
    ;*
    SPERR_INVALID_FLAGS equ MAKE_SAPI_ERROR(004h)
    ;*** SP_END_OF_STREAM                                      0x00045005    282629
    ;*   The operation has reached the end of stream.
    ;*
    SP_END_OF_STREAM equ MAKE_SAPI_SCODE(005h)
    ;*** SPERR_DEVICE_BUSY                                     0x80045006    -2147201018
    ;*   The wave device is busy.
    ;*
    SPERR_DEVICE_BUSY equ MAKE_SAPI_ERROR(006h)
    ;*** SPERR_DEVICE_NOT_SUPPORTED                            0x80045007    -2147201017
    ;*   The wave device is not supported.
    ;*
    SPERR_DEVICE_NOT_SUPPORTED equ MAKE_SAPI_ERROR(007h)
    ;*** SPERR_DEVICE_NOT_ENABLED                              0x80045008    -2147201016
    ;*   The wave device is not enabled.
    ;*
    SPERR_DEVICE_NOT_ENABLED equ MAKE_SAPI_ERROR(008h)
    ;*** SPERR_NO_DRIVER                                       0x80045009    -2147201015
    ;*   There is no wave driver installed.
    ;*
    SPERR_NO_DRIVER equ MAKE_SAPI_ERROR(009h)
    ;*** SPERR_FILEMUSTBEUNICODE                               0x8004500a    -2147201014
    ;*   The file must be Unicode.
    ;*
    SPERR_FILE_MUST_BE_UNICODE equ MAKE_SAPI_ERROR(00ah)
    ;*** SP_INSUFFICIENTDATA                                   0x0004500b    282635
    ;*
    ;*
    SP_INSUFFICIENT_DATA equ MAKE_SAPI_SCODE(00bh)
    ;*** SPERR_INVALID_PHRASE_ID                               0x8004500c    -2147201012
    ;*   The phrase ID specified does not exist or is out of range.
    ;*
    SPERR_INVALID_PHRASE_ID equ MAKE_SAPI_ERROR(00ch)
    ;*** SPERR_BUFFER_TOO_SMALL                                0x8004500d    -2147201011
    ;*   The caller provided a buffer too small to return a result.
    ;*
    SPERR_BUFFER_TOO_SMALL equ MAKE_SAPI_ERROR(00dh)
    ;*** SPERR_FORMAT_NOT_SPECIFIED                            0x8004500e    -2147201010
    ;*   Caller did not specify a format prior to opening a stream.
    ;*
    SPERR_FORMAT_NOT_SPECIFIED equ MAKE_SAPI_ERROR(00eh)
    ;*** SPERR_AUDIO_STOPPED                                   0x8004500f    -2147201009
    ;*   This method is deprecated. Use SP_AUDIO_STOPPED instead.
    ;*
    SPERR_AUDIO_STOPPED equ MAKE_SAPI_ERROR(00fh)
    ;*** SP_AUDIO_PAUSED                                       0x00045010    282640
    ;*   This will be returned only on input (read) streams when the stream is paused.  Reads on
    ;*   paused streams will not block, and this return code indicates that all of the data has been
    ;*   removed from the stream.
    ;*
    SP_AUDIO_PAUSED equ MAKE_SAPI_SCODE(010h)
    ;*** SPERR_RULE_NOT_FOUND                                  0x80045011    -2147201007
    ;*   Invalid rule name passed to ActivateGrammar.
    ;*
    SPERR_RULE_NOT_FOUND equ MAKE_SAPI_ERROR(011h)
    ;*** SPERR_TTS_ENGINE_EXCEPTION                            0x80045012    -2147201006
    ;*   An exception was raised during a call to the current TTS driver.
    ;*
    SPERR_TTS_ENGINE_EXCEPTION equ MAKE_SAPI_ERROR(012h)
    ;*** SPERR_TTS_NLP_EXCEPTION                               0x80045013    -2147201005
    ;*   An exception was raised during a call to an application sentence filter.
    ;*
    SPERR_TTS_NLP_EXCEPTION equ MAKE_SAPI_ERROR(013h)
    ;*** SPERR_ENGINE_BUSY                                     0x80045014    -2147201004
    ;*   In speech recognition, the current method can not be performed while
    ;*   a grammar rule is active.
    ;*
    SPERR_ENGINE_BUSY equ MAKE_SAPI_ERROR(014h)
    ;*** SP_AUDIO_CONVERSION_ENABLED                           0x00045015    282645
    ;*   The operation was successful, but only with automatic stream format conversion.
    ;*
    SP_AUDIO_CONVERSION_ENABLED equ MAKE_SAPI_SCODE(015h)
    ;*** SP_NO_HYPOTHESIS_AVAILABLE                            0x00045016    282646
    ;*   There is currently no hypothesis recognition available.
    ;*
    SP_NO_HYPOTHESIS_AVAILABLE equ MAKE_SAPI_SCODE(016h)
    ;*** SPERR_CANT_CREATE                                     0x80045017    -2147201001
    ;*   Can not create a new object instance for the specified object category.
    ;*
    SPERR_CANT_CREATE equ MAKE_SAPI_ERROR(017h)
    ;*** SP_ALREADY_IN_LEX                                     0x00045018    282648
    ;*   The word, pronunciation, or POS pair being added is already in lexicon.
    ;*
    SP_ALREADY_IN_LEX equ MAKE_SAPI_SCODE(018h)
    ;*** SPERR_NOT_IN_LEX                                      0x80045019    -2147200999
    ;*   The word does not exist in the lexicon.
    ;*
    SPERR_NOT_IN_LEX equ MAKE_SAPI_ERROR(019h)
    ;*** SP_LEX_NOTHING_TO_SYNC                                0x0004501a    282650
    ;*   The client is currently synced with the lexicon.
    ;*
    SP_LEX_NOTHING_TO_SYNC equ MAKE_SAPI_SCODE(01ah)
    ;*** SPERR_LEX_VERY_OUT_OF_SYNC                            0x8004501b    -2147200997
    ;*   The client is excessively out of sync with the lexicon. Mismatches may not be incrementally sync'd.
    ;*
    SPERR_LEX_VERY_OUT_OF_SYNC equ MAKE_SAPI_ERROR(01bh)
    ;*** SPERR_UNDEFINED_FORWARD_RULE_REF                      0x8004501c    -2147200996
    ;*   A rule reference in a grammar was made to a named rule that was never defined.
    ;*
    SPERR_UNDEFINED_FORWARD_RULE_REF equ MAKE_SAPI_ERROR(01ch)
    ;*** SPERR_EMPTY_RULE                                      0x8004501d    -2147200995
    ;*   A non-dynamic grammar rule that has no body.
    ;*
    SPERR_EMPTY_RULE equ MAKE_SAPI_ERROR(01dh)
    ;*** SPERR_GRAMMAR_COMPILER_INTERNAL_ERROR                 0x8004501e    -2147200994
    ;*   The grammar compiler failed due to an internal state error.
    ;*
    SPERR_GRAMMAR_COMPILER_INTERNAL_ERROR equ MAKE_SAPI_ERROR(01eh)
    ;*** SPERR_RULE_NOT_DYNAMIC                                0x8004501f    -2147200993
    ;*   An attempt was made to modify a non-dynamic rule.
    ;*
    SPERR_RULE_NOT_DYNAMIC equ MAKE_SAPI_ERROR(01fh)
    ;*** SPERR_DUPLICATE_RULE_NAME                             0x80045020    -2147200992
    ;*   A rule name was duplicated.
    ;*
    SPERR_DUPLICATE_RULE_NAME equ MAKE_SAPI_ERROR(020h)
    ;*** SPERR_DUPLICATE_RESOURCE_NAME                         0x80045021    -2147200991
    ;*   A resource name was duplicated for a given rule.
    ;*
    SPERR_DUPLICATE_RESOURCE_NAME equ MAKE_SAPI_ERROR(021h)
    ;*** SPERR_TOO_MANY_GRAMMARS                               0x80045022    -2147200990
    ;*   Too many grammars have been loaded.
    ;*
    SPERR_TOO_MANY_GRAMMARS equ MAKE_SAPI_ERROR(022h)
    ;*** SPERR_CIRCULAR_REFERENCE                              0x80045023    -2147200989
    ;*   Circular reference in import rules of grammars.
    ;*
    SPERR_CIRCULAR_REFERENCE equ MAKE_SAPI_ERROR(023h)
    ;*** SPERR_INVALID_IMPORT                                  0x80045024    -2147200988
    ;*   A rule reference to an imported grammar that could not be resolved.
    ;*
    SPERR_INVALID_IMPORT equ MAKE_SAPI_ERROR(024h)
    ;*** SPERR_INVALID_WAV_FILE                                0x80045025    -2147200987
    ;*   The format of the WAV file is not supported.
    ;*
    SPERR_INVALID_WAV_FILE equ MAKE_SAPI_ERROR(025h)
    ;*** SP_REQUEST_PENDING                                    0x00045026    282662
    ;*   This success code indicates that an SR method called with the SPRIF_ASYNC flag is
    ;*   being processed.  When it has finished processing, an SPFEI_ASYNC_COMPLETED event will be generated.
    ;*
    SP_REQUEST_PENDING equ MAKE_SAPI_SCODE(026h)
    ;*** SPERR_ALL_WORDS_OPTIONAL                              0x80045027    -2147200985
    ;*   A grammar rule was defined with a null path through the rule.  That is, it is possible
    ;*   to satisfy the rule conditions with no words.
    ;*
    SPERR_ALL_WORDS_OPTIONAL equ MAKE_SAPI_ERROR(027h)
    ;*** SPERR_INSTANCE_CHANGE_INVALID                         0x80045028    -2147200984
    ;*   It is not possible to change the current engine or input.  This occurs in the
    ;*   following cases:
    ;*
    ;*       1) SelectEngine called while a recognition context exists, or
    ;*       2) SetInput called in the shared instance case.
    ;*
    SPERR_INSTANCE_CHANGE_INVALID equ MAKE_SAPI_ERROR(028h)
    ;*** SPERR_RULE_NAME_ID_CONFLICT                          0x80045029    -2147200983
    ;*   A rule exists with matching IDs (names) but different names (IDs).  
    ;*
    SPERR_RULE_NAME_ID_CONFLICT equ MAKE_SAPI_ERROR(029h)
    ;*** SPERR_NO_RULES                                       0x8004502a    -2147200982
    ;*   A grammar contains no top-level, dynamic, or exported rules.  There is no possible
    ;*   way to activate or otherwise use any rule in this grammar.
    ;*
    SPERR_NO_RULES equ MAKE_SAPI_ERROR(02ah)
    ;*** SPERR_CIRCULAR_RULE_REF                              0x8004502b    -2147200981
    ;*   Rule 'A' refers to a second rule 'B' which, in turn, refers to rule 'A'. 
    ;*
    SPERR_CIRCULAR_RULE_REF equ MAKE_SAPI_ERROR(02bh)
    ;*** SP_NO_PARSE_FOUND                                    0x0004502c    282668
    ;*   Parse path cannot be parsed given the currently active rules.
    ;*
    SP_NO_PARSE_FOUND equ MAKE_SAPI_SCODE(02ch)
    ;*** SPERR_NO_PARSE_FOUND                                 0x8004502d    -2147200979
    ;*   Parse path cannot be parsed given the currently active rules.
    ;*
    SPERR_INVALID_HANDLE equ MAKE_SAPI_ERROR(02dh)
    ;*** SPERR_REMOTE_CALL_TIMED_OUT                          0x8004502e    -2147200978
    ;*   A marshaled remote call failed to respond.
    ;*
    SPERR_REMOTE_CALL_TIMED_OUT equ MAKE_SAPI_ERROR(02eh)
    ;*** SPERR_AUDIO_BUFFER_OVERFLOW                           0x8004502f    -2147200977
    ;*   This will only be returned on input (read) streams when the stream is paused because
    ;*   the SR driver has not retrieved data recently.
    ;*
    SPERR_AUDIO_BUFFER_OVERFLOW equ MAKE_SAPI_ERROR(02fh)
    ;*** SPERR_NO_AUDIO_DATA                                   0x80045030    -2147200976
    ;*   The result does not contain any audio, nor does the portion of the element chain of the result
    ;*   contain any audio.
    ;*
    SPERR_NO_AUDIO_DATA equ MAKE_SAPI_ERROR(030h)
    ;*** SPERR_DEAD_ALTERNATE                                  0x80045031    -2147200975
    ;*   This alternate is no longer a valid alternate to the result it was obtained from.
    ;*   Returned from ISpPhraseAlt methods.
    ;*
    SPERR_DEAD_ALTERNATE equ MAKE_SAPI_ERROR(031h)
    ;*** SPERR_HIGH_LOW_CONFIDENCE                             0x80045032    -2147200974
    ;*   The result does not contain any audio, nor does the portion of the element chain of the result
    ;*   contain any audio.  Returned from ISpResult::GetAudio and ISpResult::SpeakAudio.
    ;*
    SPERR_HIGH_LOW_CONFIDENCE equ MAKE_SAPI_ERROR(032h)
    ;*** SPERR_INVALID_FORMAT_STRING                           0x80045033    -2147200973
    ;*   The XML format string for this RULEREF is invalid, e.g. not a GUID or REFCLSID.
    ;*
    SPERR_INVALID_FORMAT_STRING equ MAKE_SAPI_ERROR(033h)
    ;*** SP_UNSUPPORTED_ON_STREAM_INPUT                        0x00045034    282676
    ;*   The operation is not supported for stream input.
    ;*
    SP_UNSUPPORTED_ON_STREAM_INPUT equ MAKE_SAPI_SCODE(034h)
    ;*** SPERR_APPLEX_READ_ONLY                                0x80045035    -2147200971
    ;*   The operation is invalid for all but newly created application lexicons.
    ;*
    SPERR_APPLEX_READ_ONLY equ MAKE_SAPI_ERROR(035h)
    ;*** SPERR_NO_TERMINATING_RULE_PATH                        0x80045036    -2147200970
    ;*
    ;*
    SPERR_NO_TERMINATING_RULE_PATH equ MAKE_SAPI_ERROR(036h)
    ;*** SP_WORD_EXISTS_WITHOUT_PRONUNCIATION                  0x00045037    282679
    ;*   The word exists but without pronunciation.
    ;*
    SP_WORD_EXISTS_WITHOUT_PRONUNCIATION equ MAKE_SAPI_SCODE(037h)
    ;*** SPERR_STREAM_CLOSED                                   0x80045038    -2147200968
    ;*   An operation was attempted on a stream object that has been closed.
    ;*
    SPERR_STREAM_CLOSED equ MAKE_SAPI_ERROR(038h)
    ; --- The following error codes are taken directly from WIN32  ---
    ;*** SPERR_NO_MORE_ITEMS                                   0x80045039    -2147200967
    ;*   When enumerating items, the requested index is greater than the count of items.
    ;*
    SPERR_NO_MORE_ITEMS equ MAKE_SAPI_ERROR(039h)
    ;*** SPERR_NOT_FOUND                                       0x8004503a    -2147200966
    ;*   The requested data item (data key, value, etc.) was not found.
    ;*
    SPERR_NOT_FOUND equ MAKE_SAPI_ERROR(03ah)
    ;*** SPERR_INVALID_AUDIO_STATE                             0x8004503b    -2147200965
    ;*   Audio state passed to SetState() is invalid.
    ;*
    SPERR_INVALID_AUDIO_STATE equ MAKE_SAPI_ERROR(03bh)
    ;*** SPERR_GENERIC_MMSYS_ERROR                             0x8004503c    -2147200964
    ;*   A generic MMSYS error not caught by _MMRESULT_TO_HRESULT.
    ;*
    SPERR_GENERIC_MMSYS_ERROR equ MAKE_SAPI_ERROR(03ch)
    ;*** SPERR_MARSHALER_EXCEPTION                             0x8004503d    -2147200963
    ;*   An exception was raised during a call to the marshaling code.
    ;*
    SPERR_MARSHALER_EXCEPTION equ MAKE_SAPI_ERROR(03dh)
    ;*** SPERR_NOT_DYNAMIC_GRAMMAR                             0x8004503e    -2147200962
    ;*   Attempt was made to manipulate a non-dynamic grammar.
    ;*
    SPERR_NOT_DYNAMIC_GRAMMAR equ MAKE_SAPI_ERROR(03eh)
    ;*** SPERR_AMBIGUOUS_PROPERTY                              0x8004503f    -2147200961
    ;*   Cannot add ambiguous property.
    ;*
    SPERR_AMBIGUOUS_PROPERTY equ MAKE_SAPI_ERROR(03fh)
    ;*** SPERR_INVALID_REGISTRY_KEY                            0x80045040    -2147200960
    ;*   The key specified is invalid.
    ;*
    SPERR_INVALID_REGISTRY_KEY equ MAKE_SAPI_ERROR(040h)
    ;*** SPERR_INVALID_TOKEN_ID                                0x80045041    -2147200959
    ;*   The token specified is invalid.
    ;*
    SPERR_INVALID_TOKEN_ID equ MAKE_SAPI_ERROR(041h)
    ;*** SPERR_XML_BAD_SYNTAX                                  0x80045042    -2147200958
    ;*   The xml parser failed due to bad syntax.
    ;*
    SPERR_XML_BAD_SYNTAX equ MAKE_SAPI_ERROR(042h)
    ;*** SPERR_XML_RESOURCE_NOT_FOUND                          0x80045043    -2147200957
    ;*   The xml parser failed to load a required resource (e.g., voice, phoneconverter, etc.).
    ;*
    SPERR_XML_RESOURCE_NOT_FOUND equ MAKE_SAPI_ERROR(043h)
    ;*** SPERR_TOKEN_IN_USE                                    0x80045044    -2147200956
    ;*   Attempted to remove registry data from a token that is already in use elsewhere.
    ;*
    SPERR_TOKEN_IN_USE equ MAKE_SAPI_ERROR(044h)
    ;*** SPERR_TOKEN_DELETED                                   0x80045045    -2147200955
    ;*   Attempted to perform an action on an object token that has had associated registry key deleted.
    ;*
    SPERR_TOKEN_DELETED equ MAKE_SAPI_ERROR(045h)
    ;*** SPERR_MULTI_LINGUAL_NOT_SUPPORTED                     0x80045046    -2147200954
    ;*   The selected voice was registered as multi-lingual. SAPI does not support multi-lingual registration. 
    ;*
    SPERR_MULTI_LINGUAL_NOT_SUPPORTED equ MAKE_SAPI_ERROR(046h)
    ;*** SPERR_EXPORT_DYNAMIC_RULE                             0x80045047    -2147200953
    ;*   Exported rules cannot refer directly or indirectly to a dynamic rule.
    ;*
    SPERR_EXPORT_DYNAMIC_RULE equ MAKE_SAPI_ERROR(047h)
    ;*** SPERR_STGF_ERROR                                      0x80045048    -2147200952
    ;*   Error parsing the SAPI Text Grammar Format (XML grammar).
    ;*
    SPERR_STGF_ERROR equ MAKE_SAPI_ERROR(048h)
    ;*** SPERR_WORDFORMAT_ERROR                                0x80045049    -2147200951
    ;*   Incorrect word format, probably due to incorrect pronunciation string.
    ;*
    SPERR_WORDFORMAT_ERROR equ MAKE_SAPI_ERROR(049h)
    ;*** SPERR_STREAM_NOT_ACTIVE                               0x8004504a    -2147200950
    ;*   Methods associated with active audio stream cannot be called unless stream is active.
    ;*
    SPERR_STREAM_NOT_ACTIVE equ MAKE_SAPI_ERROR(04ah)
    ;*** SPERR_ENGINE_RESPONSE_INVALID                         0x8004504b    -2147200949
    ;*   Arguments or data supplied by the engine are in an invalid format or are inconsistent.
    ;*
    SPERR_ENGINE_RESPONSE_INVALID equ MAKE_SAPI_ERROR(04bh)
    ;*** SPERR_SR_ENGINE_EXCEPTION                             0x8004504c    -2147200948
    ;*   An exception was raised during a call to the current SR engine.
    ;*
    SPERR_SR_ENGINE_EXCEPTION equ MAKE_SAPI_ERROR(04ch)
    ;*** SPERR_STREAM_POS_INVALID                              0x8004504d    -2147200947
    ;*   Stream position information supplied from engine is inconsistent.
    ;*
    SPERR_STREAM_POS_INVALID equ MAKE_SAPI_ERROR(04dh)
    ;*** SP_RECOGNIZER_INACTIVE                                0x0004504e    282702
    ;*   Operation could not be completed because the recognizer is inactive. It is inactive either
    ;*   because the recognition state is currently inactive or because no rules are active .
    ;*
    SP_RECOGNIZER_INACTIVE equ MAKE_SAPI_SCODE(04eh)
    ;*** SPERR_REMOTE_CALL_ON_WRONG_THREAD                     0x8004504f    -2147200945
    ;*   When making a remote call to the server, the call was made on the wrong thread.
    ;*
    SPERR_REMOTE_CALL_ON_WRONG_THREAD equ MAKE_SAPI_ERROR(04fh)
    ;*** SPERR_REMOTE_PROCESS_TERMINATED                       0x80045050    -2147200944
    ;*   The remote process terminated unexpectedly.
    ;*
    SPERR_REMOTE_PROCESS_TERMINATED equ MAKE_SAPI_ERROR(050h)
    ;*** SPERR_REMOTE_PROCESS_ALREADY_RUNNING                  0x80045051    -2147200943
    ;*   The remote process is already running; it cannot be started a second time.
    ;*
    SPERR_REMOTE_PROCESS_ALREADY_RUNNING equ MAKE_SAPI_ERROR(051h)
    ;*** SPERR_LANGID_MISMATCH                                 0x80045052    -2147200942
    ;*   An attempt to load a CFG grammar with a LANGID different than other loaded grammars.
    ;*
    SPERR_LANGID_MISMATCH equ MAKE_SAPI_ERROR(052h)
    ;*** SP_PARTIAL_PARSE_FOUND                               0x00045053    282707
    ;*   A grammar-ending parse has been found that does not use all available words.
    ;*
    SP_PARTIAL_PARSE_FOUND equ MAKE_SAPI_SCODE(053h)
    ;*** SPERR_NOT_TOPLEVEL_RULE                              0x80045054    -2147200940
    ;*   An attempt to deactivate or activate a non-toplevel rule.
    ;*
    SPERR_NOT_TOPLEVEL_RULE equ MAKE_SAPI_ERROR(054h)
    ;*** SP_NO_RULE_ACTIVE                                    0x00045055    282709
    ;*   An attempt to parse when no rule was active.
    ;*
    SP_NO_RULE_ACTIVE equ MAKE_SAPI_SCODE(055h)
    ;*** SPERR_LEX_REQUIRES_COOKIE                            0x80045056    -2147200938
    ;*   An attempt to ask a container lexicon for all words at once.
    ;*
    SPERR_LEX_REQUIRES_COOKIE equ MAKE_SAPI_ERROR(056h)
    ;*** SP_STREAM_UNINITIALIZED                              0x00045057    282711
    ;*   An attempt to activate a rule/dictation/etc without calling SetInput 
    ;*   first in the inproc case.
    ;*
    SP_STREAM_UNINITIALIZED equ MAKE_SAPI_SCODE(057h)
    ; Error x058 is not used in SAPI 5.0
    ;*** SPERR_UNSUPPORTED_LANG                               0x80045059    -2147200935
    ;*   The requested language is not supported.
    ;*
    SPERR_UNSUPPORTED_LANG equ MAKE_SAPI_ERROR(059h)
    ;*** SPERR_VOICE_PAUSED                                   0x8004505a    -2147200934
    ;*   The operation cannot be performed because the voice is currently paused.
    ;*
    SPERR_VOICE_PAUSED equ MAKE_SAPI_ERROR(05ah)
    ;*** SPERR_AUDIO_BUFFER_UNDERFLOW                          0x8004505b    -2147200933
    ;*   This will only be returned on input (read) streams when the real time audio device
    ;*   stops returning data for a long period of time.
    ;*
    SPERR_AUDIO_BUFFER_UNDERFLOW equ MAKE_SAPI_ERROR(05bh)
    ;*** SPERR_AUDIO_STOPPED_UNEXPECTEDLY                     0x8004505c    -2147200932
    ;*   An audio device stopped returning data from the Read() method even though it was in
    ;*   the run state.  This error is only returned in the END_SR_STREAM event.
    ;*
    SPERR_AUDIO_STOPPED_UNEXPECTEDLY equ MAKE_SAPI_ERROR(05ch)
    ;*** SPERR_NO_WORD_PRONUNCIATION                           0x8004505d    -2147200931
    ;*   The SR engine is unable to add this word to a grammar. The application may need to supply 
    ;*   an explicit pronunciation for this word.
    ;*
    SPERR_NO_WORD_PRONUNCIATION equ MAKE_SAPI_ERROR(05dh)
    ;*** SPERR_ALTERNATES_WOULD_BE_INCONSISTENT                0x8004505e    -2147200930
    ;*   An attempt to call ScaleAudio on a recognition result having previously
    ;*   called GetAlternates. Allowing the call to succeed would result in
    ;*   the previously created alternates located in incorrect audio stream positions.
    ;*
    SPERR_ALTERNATES_WOULD_BE_INCONSISTENT equ MAKE_SAPI_ERROR(05eh)
    ;*** SPERR_NOT_SUPPORTED_FOR_SHARED_RECOGNIZER             0x8004505f    -2147200929
    ;*   The method called is not supported for the shared recognizer.
    ;*   For example, ISpRecognizer::GetInputStream().
    ;*
    SPERR_NOT_SUPPORTED_FOR_SHARED_RECOGNIZER equ MAKE_SAPI_ERROR(05fh)
    ;*** SPERR_TIMEOUT                                         0x80045060    -2147200928
    ;*   A task could not complete because the SR engine had timed out.
    ;*
    SPERR_TIMEOUT equ MAKE_SAPI_ERROR(060h)
    ;*** SPERR_REENTER_SYNCHRONIZE                             0x80045061    -2147200927
    ;*   A SR engine called synchronize while inside of a synchronize call.
    ;*
    SPERR_REENTER_SYNCHRONIZE equ MAKE_SAPI_ERROR(061h)
    ;*** SPERR_STATE_WITH_NO_ARCS                              0x80045062    -2147200926
    ;*   The grammar contains a node no arcs.
    ;*
    SPERR_STATE_WITH_NO_ARCS equ MAKE_SAPI_ERROR(062h)
    ;*** SPERR_NOT_ACTIVE_SESSION                              0x80045063    -2147200925
    ;*   Neither audio output and input is supported for non-active console sessions.
    ;*
    SPERR_NOT_ACTIVE_SESSION equ MAKE_SAPI_ERROR(063h)
    ;*** SPERR_ALREADY_DELETED                                 0x80045064    -2147200924
    ;*   The object is a stale reference and is invalid to use.
    ;*   For example having a ISpeechGrammarRule object reference and then calling 
    ;*   ISpeechRecoGrammar::Reset() will cause the rule object to be invalidated.
    ;*   Calling any methods after this will result in this error.
    ;*
    SPERR_ALREADY_DELETED equ MAKE_SAPI_ERROR(064h)
    ;*** SP_AUDIO_STOPPED                                      0x00045065    282725
    ;*   This can be returned from Read or Write calls audio streams when the stream is stopped.
    ;*
    SP_AUDIO_STOPPED equ MAKE_SAPI_SCODE(065h)
    ;*** SPERR_RECOXML_GENERATION_FAIL                             0x80045066    -2147200922
    ;*   The Recognition Parse Tree couldn't be genrated.
    ;*   For example, that the rule name begins with a digit.
    ;*   XML parser doesn't allow element name beginning with a digit.
    ;*
    SPERR_RECOXML_GENERATION_FAIL equ MAKE_SAPI_ERROR(066h)
    ;*** SPERR_SML_GENERATION_FAIL                             0x80045067    -2147200921
    ;*   The SML couldn't be genrated.
    ;*   For example, the transformation xslt template is not well formed.
    ;*
    SPERR_SML_GENERATION_FAIL equ MAKE_SAPI_ERROR(067h)
    ;*** SPERR_NOT_PROMPT_VOICE                                0x80045068   -2147200920
    ;*   The current voice is not a prompt voice, so the ISpPromptVoice
    ;*   functions don't work.
    ;*
    SPERR_NOT_PROMPT_VOICE equ MAKE_SAPI_ERROR(068h)
    ;*** SPERR_ROOTRULE_ALREADY_DEFINED                        0x80045069   -2147200919
    ;*   There is already a root rule for this grammar
    ;*   Defining another root rule will fail.
    ;*
    SPERR_ROOTRULE_ALREADY_DEFINED equ MAKE_SAPI_ERROR(069h)
    ;*** SPERR_SCRIPT_DISALLOWED                               0x80045070   -2147200912
    ;*   Support for embedded script not supported because browser security settings have disabled it
    ;*
    SPERR_SCRIPT_DISALLOWED equ MAKE_SAPI_ERROR(070h)
    ;*** SPERR_REMOTE_CALL_TIMED_OUT_START                     0x80045071    -2147200911
    ;*   A time out occurred starting the sapi server
    ;*
    SPERR_REMOTE_CALL_TIMED_OUT_START equ MAKE_SAPI_ERROR(071h)
    ;*** SPERR_REMOTE_CALL_TIMED_OUT_CONNECT                   0x80045072    -2147200910
    ;*   A timeout occurred obtaining the lock for starting or connecting to sapi server 
    ;*
    SPERR_REMOTE_CALL_TIMED_OUT_CONNECT equ MAKE_SAPI_ERROR(072h)
    ;*** SPERR_SECMGR_CHANGE_NOT_ALLOWED                       0x80045073    -2147200909
    ;*   When there is a cfg grammar loaded, we don't allow changing the security manager
    ;*
    SPERR_SECMGR_CHANGE_NOT_ALLOWED equ MAKE_SAPI_ERROR(073h)
    ;*** SP_COMPLETE_BUT_EXTENDABLE                            0x00045074    282740
    ;*   Parse is valid but could be extendable (internal use only)
    ;*
    SP_COMPLETE_BUT_EXTENDABLE equ MAKE_SAPI_SCODE(074h)
    ;*** SPERR_FAILED_TO_DELETE_FILE                           0x80045075    -2147200907
    ;*   Tried and failed to delete an existing file.
    ;*
    SPERR_FAILED_TO_DELETE_FILE equ MAKE_SAPI_ERROR(075h)
    ;*** SPERR_SHARED_ENGINE_DISABLED                          0x80045076    -2147200906
    ;*   The user has chosen to disable speech from running on the machine, or the 
    ;*   system is not set up to run speech {e.g. initial setup and tutorial has not been run}.    
    ;*
    SPERR_SHARED_ENGINE_DISABLED equ MAKE_SAPI_ERROR(076h)
    ;*** SPERR_RECOGNIZER_NOT_FOUND                            0x80045077    -2147200905
    ;*   No recognizer is installed.    
    ;*
    SPERR_RECOGNIZER_NOT_FOUND equ MAKE_SAPI_ERROR(077h)
    ;*** SPERR_AUDIO_NOT_FOUND                                 0x80045078    -2147200904
    ;*   No audio device is installed.    
    ;*
    SPERR_AUDIO_NOT_FOUND equ MAKE_SAPI_ERROR(078h)
    ;*** SPERR_NO_VOWEL                                        0x80045079    -2147200903
    ;*   No Vowel in a word 
    ;*
    SPERR_NO_VOWEL equ MAKE_SAPI_ERROR(079h)
    ;*** SPERR_UNSUPPORTED_PHONEME                             0x8004507A    -2147200902
    ;*   Unknown phoneme
    ;*
    SPERR_UNSUPPORTED_PHONEME equ MAKE_SAPI_ERROR(07Ah)
    ;*** SP_NO_RULES_TO_ACTIVATE                               0x0004507B    282747
    ;*   The grammar does not have any root or top-level active rules to activate.
    ;*
    SP_NO_RULES_TO_ACTIVATE equ MAKE_SAPI_SCODE(07Bh)
    ;*** SP_NO_WORDENTRY_NOTIFICATION                          0x0004507C    282748
    ;*   The engine does not need SAPI word entry handles for this grammar
    ;*
    SP_NO_WORDENTRY_NOTIFICATION equ MAKE_SAPI_SCODE(07Ch)
    ;*** SPERR_WORD_NEEDS_NORMALIZATION                        0x8004507D    -2147200899
    ;*   The word passed to the GetPronunciations interface needs normalizing first
    ;*
    SPERR_WORD_NEEDS_NORMALIZATION equ MAKE_SAPI_ERROR(07Dh)
    ;*** SPERR_CANNOT_NORMALIZE                                0x8004507E    -2147200898
    ;*   The word passed to the normalize interface cannot be normalized
    ;*
    SPERR_CANNOT_NORMALIZE equ MAKE_SAPI_ERROR(07Eh)
    ;*** S_LIMIT_REACHED                                       0x0004507F    282751
    ;*   The word being normalized has generated more than the maximum number of allowed normalized results
    ;*   Indicates that returned list is not exhaustive, but contains as many alternatives as the engine is willing to provide.
    ;*
    S_LIMIT_REACHED equ MAKE_SAPI_SCODE(07Fh)
    ;*** S_NOTSUPPORTED                                        0x00045080    282752
    ;*   We currently don't support this combination of function call + input
    ;*
    S_NOTSUPPORTED equ MAKE_SAPI_SCODE(080h)
    ;*** SPERR_TOPIC_NOT_ADAPTABLE                            0x80045081    -2147200895
    ;*   This topic is not adaptable
    ;*
    SPERR_TOPIC_NOT_ADAPTABLE equ MAKE_SAPI_ERROR(081h)
    ;*** SPERR_PHONEME_CONVERSION                            0x80045082    -2147200894
    ;*   Cannot convert the phonemes to the specified phonetic alphabet.
    ;*
    SPERR_PHONEME_CONVERSION equ MAKE_SAPI_ERROR(082h)
    ;*** SPERR_NOT_SUPPORTED_FOR_INPROC_RECOGNIZER           0x80045083    -2147200893
    ;*   The method called is not supported for the in-process recognizer.
    ;*   For example: SetTextFeedback
    ;*
    SPERR_NOT_SUPPORTED_FOR_INPROC_RECOGNIZER equ MAKE_SAPI_ERROR(083h)
    ;*** SPERR_OVERLOAD                 0x80045084         -2147200892
    ;*   The operation cannot be carried out due to overload and should be attempted again.
    ;*
    SPERR_OVERLOAD equ MAKE_SAPI_ERROR(084h)
    ;*** SPERR_LEX_INVALID_DATA         0x80045085         -2147200891
    ;*   The lexicon data is invalid or corrupted.
    ;*
    SPERR_LEX_INVALID_DATA equ MAKE_SAPI_ERROR(085h)
    ;*** SPERR_CFG_INVALID_DATA         0x80045086         -2147200890
    ;*   The data in the CFG grammar is invalid or corrupted
    ;*
    SPERR_CFG_INVALID_DATA equ MAKE_SAPI_ERROR(086h)
    ;*** SPERR_LEX_UNEXPECTED_FORMAT      0x80045087       -2147200889
    ;*   The lexicon is not in the expected format.
    ;*
    SPERR_LEX_UNEXPECTED_FORMAT equ MAKE_SAPI_ERROR(087h)
    ;*** SPERR_STRING_TOO_LONG          0x80045088         -2147200888
    ;*   The string is too long.
    ;*
    SPERR_STRING_TOO_LONG equ MAKE_SAPI_ERROR(088h)
    ;*** SPERR_STRING_EMPTY             0x80045089         -2147200887
    ;*   The string cannot be empty.
    ;*
    SPERR_STRING_EMPTY equ MAKE_SAPI_ERROR(089h)
    ;*** SPERR_NON_WORD_TRANSITION      0x80045090         -2147200880
    ;*   One of the parse transitions is not a word transition.
    ;*
    SPERR_NON_WORD_TRANSITION equ MAKE_SAPI_ERROR(090h)
    ;*** SPERR_SISR_ATTRIBUTES_NOT_ALLOWED     0x80045091   -2147200879
    ;*   Attributes are not allowed at the top level.
    ;*
    SPERR_SISR_ATTRIBUTES_NOT_ALLOWED equ MAKE_SAPI_ERROR(091h)
    ;*** SPERR_SISR_MIXED_NOT_ALLOWED          0x80045092   -2147200878
    ;*   Mixed content is not allowed at the top level.
    ;*
    SPERR_SISR_MIXED_NOT_ALLOWED equ MAKE_SAPI_ERROR(092h)
    ;*** SPERR_VOICE_NOT_FOUND                 0x80045093   -2147200877
    ;*   NO given voice is found
    ;*
    SPERR_VOICE_NOT_FOUND equ MAKE_SAPI_ERROR(093h)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
;--- This must be the last line in the file
