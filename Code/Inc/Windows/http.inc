;Include file created by h2incX, Version C.1.1, 19/12/2020 17:58
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\Experimental\h2IncX\10.0.19041.0\um\http.h', last modified: 06/12/2019 15:44
;Creation parameters: 

ifndef __HTTP_H__
  __HTTP_H__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _WIN32_WINNT ge 0501h
      include winsock2.inc
      include ws2tcpip.inc
      ifdef __cplusplus
        ;[...]
      endif
      HTTP_INITIALIZE_SERVER equ 00000001h
      HTTP_INITIALIZE_CONFIG equ 00000002h
      HTTP_DEMAND_CBT equ 00000004h
      if _WIN32_WINNT ge 0600h
        HTTP_SERVER_PROPERTY typedef SDWORD
        HttpServerAuthenticationProperty equ 0
        HttpServerLoggingProperty equ 1
        HttpServerQosProperty equ 2
        HttpServerTimeoutsProperty equ 3
        HttpServerQueueLengthProperty equ 4
        HttpServerStateProperty equ 5
        HttpServer503VerbosityProperty equ 6
        HttpServerBindingProperty equ 7
        HttpServerExtendedAuthenticationProperty equ 8
        HttpServerListenEndpointProperty equ 9
        HttpServerChannelBindProperty equ 10
        HttpServerProtectionLevelProperty equ 11
        _HTTP_SERVER_PROPERTY typedef HTTP_SERVER_PROPERTY
        PHTTP_SERVER_PROPERTY typedef ptr HTTP_SERVER_PROPERTY
        
        HTTP_MAX_SERVER_QUEUE_LENGTH equ 7FFFFFFFh
        HTTP_MIN_SERVER_QUEUE_LENGTH equ 1
        HTTP_PROPERTY_FLAGS struct 8
          HTTP_PROPERTY_FLAGS_??100 record Present_??100:1
          HTTP_PROPERTY_FLAGS_??100 <>
        HTTP_PROPERTY_FLAGS ends
        _HTTP_PROPERTY_FLAGS typedef HTTP_PROPERTY_FLAGS
        PHTTP_PROPERTY_FLAGS typedef ptr HTTP_PROPERTY_FLAGS
        
        HTTP_ENABLED_STATE typedef SDWORD
        HttpEnabledStateActive equ 0
        HttpEnabledStateInactive equ 1
        _HTTP_ENABLED_STATE typedef HTTP_ENABLED_STATE
        PHTTP_ENABLED_STATE typedef ptr HTTP_ENABLED_STATE
        
        HTTP_STATE_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          State HTTP_ENABLED_STATE ?
        HTTP_STATE_INFO ends
        _HTTP_STATE_INFO typedef HTTP_STATE_INFO
        PHTTP_STATE_INFO typedef ptr HTTP_STATE_INFO
        
        HTTP_503_RESPONSE_VERBOSITY typedef SDWORD
        Http503ResponseVerbosityBasic equ 0
        Http503ResponseVerbosityLimited equ 1
        Http503ResponseVerbosityFull equ 2
        _HTTP_503_RESPONSE_VERBOSITY typedef HTTP_503_RESPONSE_VERBOSITY
        PHTTP_503_RESPONSE_VERBOSITY typedef ptr HTTP_503_RESPONSE_VERBOSITY
        
        HTTP_QOS_SETTING_TYPE typedef SDWORD
        HttpQosSettingTypeBandwidth equ 0
        HttpQosSettingTypeConnectionLimit equ 1
        HttpQosSettingTypeFlowRate equ 2
        _HTTP_QOS_SETTING_TYPE typedef HTTP_QOS_SETTING_TYPE
        PHTTP_QOS_SETTING_TYPE typedef ptr HTTP_QOS_SETTING_TYPE
        
        HTTP_QOS_SETTING_INFO struct 8
          QosType HTTP_QOS_SETTING_TYPE ?
          QosSetting PVOID ?
        HTTP_QOS_SETTING_INFO ends
        _HTTP_QOS_SETTING_INFO typedef HTTP_QOS_SETTING_INFO
        PHTTP_QOS_SETTING_INFO typedef ptr HTTP_QOS_SETTING_INFO
        
        HTTP_CONNECTION_LIMIT_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          MaxConnections ULONG ?
        HTTP_CONNECTION_LIMIT_INFO ends
        _HTTP_CONNECTION_LIMIT_INFO typedef HTTP_CONNECTION_LIMIT_INFO
        PHTTP_CONNECTION_LIMIT_INFO typedef ptr HTTP_CONNECTION_LIMIT_INFO
        
        HTTP_BANDWIDTH_LIMIT_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          MaxBandwidth ULONG ?
        HTTP_BANDWIDTH_LIMIT_INFO ends
        _HTTP_BANDWIDTH_LIMIT_INFO typedef HTTP_BANDWIDTH_LIMIT_INFO
        PHTTP_BANDWIDTH_LIMIT_INFO typedef ptr HTTP_BANDWIDTH_LIMIT_INFO
        
        HTTP_FLOWRATE_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          MaxBandwidth ULONG ?
          MaxPeakBandwidth ULONG ?
          BurstSize ULONG ?
        HTTP_FLOWRATE_INFO ends
        _HTTP_FLOWRATE_INFO typedef HTTP_FLOWRATE_INFO
        PHTTP_FLOWRATE_INFO typedef ptr HTTP_FLOWRATE_INFO
        
        HTTP_MIN_ALLOWED_BANDWIDTH_THROTTLING_RATE equ (1024)
        HTTP_LIMIT_INFINITE equ (- 1)
        HTTP_SERVICE_CONFIG_TIMEOUT_KEY typedef SDWORD
        IdleConnectionTimeout equ 0
        HeaderWaitTimeout equ 1
        _HTTP_SERVICE_CONFIG_TIMEOUT_KEY typedef HTTP_SERVICE_CONFIG_TIMEOUT_KEY
        PHTTP_SERVICE_CONFIG_TIMEOUT_KEY typedef ptr HTTP_SERVICE_CONFIG_TIMEOUT_KEY
        
        HTTP_SERVICE_CONFIG_TIMEOUT_PARAM typedef USHORT
        PHTTP_SERVICE_CONFIG_TIMEOUT_PARAM typedef ptr USHORT
        HTTP_SERVICE_CONFIG_TIMEOUT_SET struct 8
          KeyDesc HTTP_SERVICE_CONFIG_TIMEOUT_KEY ?
          ParamDesc HTTP_SERVICE_CONFIG_TIMEOUT_PARAM ?
        HTTP_SERVICE_CONFIG_TIMEOUT_SET ends
        _HTTP_SERVICE_CONFIG_TIMEOUT_SET typedef HTTP_SERVICE_CONFIG_TIMEOUT_SET
        PHTTP_SERVICE_CONFIG_TIMEOUT_SET typedef ptr HTTP_SERVICE_CONFIG_TIMEOUT_SET
        
        HTTP_TIMEOUT_LIMIT_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          EntityBody USHORT ?
          DrainEntityBody USHORT ?
          RequestQueue USHORT ?
          IdleConnection USHORT ?
          HeaderWait USHORT ?
          MinSendRate ULONG ?
        HTTP_TIMEOUT_LIMIT_INFO ends
        _HTTP_TIMEOUT_LIMIT_INFO typedef HTTP_TIMEOUT_LIMIT_INFO
        PHTTP_TIMEOUT_LIMIT_INFO typedef ptr HTTP_TIMEOUT_LIMIT_INFO
        
        HTTP_SERVICE_CONFIG_SETTING_KEY typedef SDWORD
        HttpNone equ 0
        HttpTlsThrottle equ 1
        _HTTP_SERVICE_CONFIG_SETTING_KEY typedef HTTP_SERVICE_CONFIG_SETTING_KEY
        PHTTP_SERVICE_CONFIG_SETTING_KEY typedef ptr HTTP_SERVICE_CONFIG_SETTING_KEY
        
        HTTP_SERVICE_CONFIG_SETTING_PARAM typedef ULONG
        PHTTP_SERVICE_CONFIG_SETTING_PARAM typedef ptr ULONG
        HTTP_SERVICE_CONFIG_SETTING_SET struct 8
          KeyDesc HTTP_SERVICE_CONFIG_SETTING_KEY ?
          ParamDesc HTTP_SERVICE_CONFIG_SETTING_PARAM ?
        HTTP_SERVICE_CONFIG_SETTING_SET ends
        _HTTP_SERVICE_CONFIG_SETTING_SET typedef HTTP_SERVICE_CONFIG_SETTING_SET
        PHTTP_SERVICE_CONFIG_SETTING_SET typedef ptr HTTP_SERVICE_CONFIG_SETTING_SET
        
        HTTP_LISTEN_ENDPOINT_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          EnableSharing BOOLEAN ?
        HTTP_LISTEN_ENDPOINT_INFO ends
        _HTTP_LISTEN_ENDPOINT_INFO typedef HTTP_LISTEN_ENDPOINT_INFO
        PHTTP_LISTEN_ENDPOINT_INFO typedef ptr HTTP_LISTEN_ENDPOINT_INFO
        
        HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS struct 8
          DomainNameLength USHORT ?
          DomainName PWSTR ?
          RealmLength USHORT ?
          Realm PWSTR ?
        HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS ends
        _HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS typedef HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS
        PHTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS typedef ptr HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS
        
        HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS struct 8
          RealmLength USHORT ?
          Realm PWSTR ?
        HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS ends
        _HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS typedef HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS
        PHTTP_SERVER_AUTHENTICATION_BASIC_PARAMS typedef ptr HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS
        
        HTTP_AUTH_ENABLE_BASIC equ 00000001h
        HTTP_AUTH_ENABLE_DIGEST equ 00000002h
        HTTP_AUTH_ENABLE_NTLM equ 00000004h
        HTTP_AUTH_ENABLE_NEGOTIATE equ 00000008h
        HTTP_AUTH_ENABLE_KERBEROS equ 00000010h
        HTTP_AUTH_ENABLE_ALL equ <(HTTP_AUTH_ENABLE_BASIC or HTTP_AUTH_ENABLE_DIGEST or HTTP_AUTH_ENABLE_NTLM or HTTP_AUTH_ENABLE_NEGOTIATE or HTTP_AUTH_ENABLE_KERBEROS)>
        HTTP_AUTH_EX_FLAG_ENABLE_KERBEROS_CREDENTIAL_CACHING equ 01h
        HTTP_AUTH_EX_FLAG_CAPTURE_CREDENTIAL equ 02h
        HTTP_SERVER_AUTHENTICATION_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          AuthSchemes ULONG ?
          ReceiveMutualAuth BOOLEAN ?
          ReceiveContextHandle BOOLEAN ?
          DisableNTLMCredentialCaching BOOLEAN ?
          ExFlags UCHAR ?
          DigestParams HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS <>
          BasicParams HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS <>
        HTTP_SERVER_AUTHENTICATION_INFO ends
        _HTTP_SERVER_AUTHENTICATION_INFO typedef HTTP_SERVER_AUTHENTICATION_INFO
        PHTTP_SERVER_AUTHENTICATION_INFO typedef ptr HTTP_SERVER_AUTHENTICATION_INFO
        
        if _WIN32_WINNT ge _WIN32_WINNT_WIN7
          HTTP_SERVICE_BINDING_TYPE typedef SDWORD
          HttpServiceBindingTypeNone equ 0
          HttpServiceBindingTypeW equ 1
          HttpServiceBindingTypeA equ 2
          _HTTP_SERVICE_BINDING_TYPE typedef HTTP_SERVICE_BINDING_TYPE
          
          HTTP_SERVICE_BINDING_BASE struct 8
            Type_ HTTP_SERVICE_BINDING_TYPE ?
          HTTP_SERVICE_BINDING_BASE ends
          _HTTP_SERVICE_BINDING_BASE typedef HTTP_SERVICE_BINDING_BASE
          PHTTP_SERVICE_BINDING_BASE typedef ptr HTTP_SERVICE_BINDING_BASE
          
          HTTP_SERVICE_BINDING_A struct 8
            Base HTTP_SERVICE_BINDING_BASE <>
            Buffer PCHAR ?
            BufferSize ULONG ?
          HTTP_SERVICE_BINDING_A ends
          _HTTP_SERVICE_BINDING_A typedef HTTP_SERVICE_BINDING_A
          PHTTP_SERVICE_BINDING_A typedef ptr HTTP_SERVICE_BINDING_A
          
          HTTP_SERVICE_BINDING_W struct 8
            Base HTTP_SERVICE_BINDING_BASE <>
            Buffer PWCHAR ?
            BufferSize ULONG ?
          HTTP_SERVICE_BINDING_W ends
          _HTTP_SERVICE_BINDING_W typedef HTTP_SERVICE_BINDING_W
          PHTTP_SERVICE_BINDING_W typedef ptr HTTP_SERVICE_BINDING_W
          
          HTTP_AUTHENTICATION_HARDENING_LEVELS typedef SDWORD
          HttpAuthenticationHardeningLegacy equ 0
          HttpAuthenticationHardeningMedium equ 1
          HttpAuthenticationHardeningStrict equ 2
          _HTTP_AUTHENTICATION_HARDENING_LEVELS typedef HTTP_AUTHENTICATION_HARDENING_LEVELS
          
          HTTP_CHANNEL_BIND_PROXY equ 1h
          HTTP_CHANNEL_BIND_PROXY_COHOSTING equ 20h
          HTTP_CHANNEL_BIND_NO_SERVICE_NAME_CHECK equ 2h
          HTTP_CHANNEL_BIND_DOTLESS_SERVICE equ 4h
          HTTP_CHANNEL_BIND_SECURE_CHANNEL_TOKEN equ 8h
          HTTP_CHANNEL_BIND_CLIENT_SERVICE equ 10h
          HTTP_CHANNEL_BIND_INFO struct 8
            Hardening HTTP_AUTHENTICATION_HARDENING_LEVELS ?
            Flags ULONG ?
            ServiceNames POINTER ?
            NumberOfServiceNames ULONG ?
          HTTP_CHANNEL_BIND_INFO ends
          _HTTP_CHANNEL_BIND_INFO typedef HTTP_CHANNEL_BIND_INFO
          PHTTP_CHANNEL_BIND_INFO typedef ptr HTTP_CHANNEL_BIND_INFO
          
          HTTP_REQUEST_CHANNEL_BIND_STATUS struct 8
            ServiceName PHTTP_SERVICE_BINDING_BASE ?
            ChannelToken PUCHAR ?
            ChannelTokenSize ULONG ?
            Flags ULONG ?
          HTTP_REQUEST_CHANNEL_BIND_STATUS ends
          _HTTP_REQUEST_CHANNEL_BIND_STATUS typedef HTTP_REQUEST_CHANNEL_BIND_STATUS
          PHTTP_REQUEST_CHANNEL_BIND_STATUS typedef ptr HTTP_REQUEST_CHANNEL_BIND_STATUS
          
        endif
        HTTP_REQUEST_TOKEN_BINDING_INFO struct 8
          TokenBinding PUCHAR ?
          TokenBindingSize ULONG ?
          EKM PUCHAR ?
          EKMSize ULONG ?
          KeyType UCHAR ?
        HTTP_REQUEST_TOKEN_BINDING_INFO ends
        _HTTP_REQUEST_TOKEN_BINDING_INFO typedef HTTP_REQUEST_TOKEN_BINDING_INFO
        PHTTP_REQUEST_TOKEN_BINDING_INFO typedef ptr HTTP_REQUEST_TOKEN_BINDING_INFO
        
        HTTP_LOG_FIELD_DATE equ 00000001h
        HTTP_LOG_FIELD_TIME equ 00000002h
        HTTP_LOG_FIELD_CLIENT_IP equ 00000004h
        HTTP_LOG_FIELD_USER_NAME equ 00000008h
        HTTP_LOG_FIELD_SITE_NAME equ 00000010h
        HTTP_LOG_FIELD_COMPUTER_NAME equ 00000020h
        HTTP_LOG_FIELD_SERVER_IP equ 00000040h
        HTTP_LOG_FIELD_METHOD equ 00000080h
        HTTP_LOG_FIELD_URI_STEM equ 00000100h
        HTTP_LOG_FIELD_URI_QUERY equ 00000200h
        HTTP_LOG_FIELD_STATUS equ 00000400h
        HTTP_LOG_FIELD_WIN32_STATUS equ 00000800h
        HTTP_LOG_FIELD_BYTES_SENT equ 00001000h
        HTTP_LOG_FIELD_BYTES_RECV equ 00002000h
        HTTP_LOG_FIELD_TIME_TAKEN equ 00004000h
        HTTP_LOG_FIELD_SERVER_PORT equ 00008000h
        HTTP_LOG_FIELD_USER_AGENT equ 00010000h
        HTTP_LOG_FIELD_COOKIE equ 00020000h
        HTTP_LOG_FIELD_REFERER equ 00040000h
        HTTP_LOG_FIELD_VERSION equ 00080000h
        HTTP_LOG_FIELD_HOST equ 00100000h
        HTTP_LOG_FIELD_SUB_STATUS equ 00200000h
        HTTP_LOG_FIELD_STREAM_ID equ 08000000h
        HTTP_LOG_FIELD_STREAM_ID_EX equ 10000000h
        HTTP_LOG_FIELD_TRANSPORT_TYPE equ 20000000h
        HTTP_LOG_FIELD_CLIENT_PORT equ 00400000h
        HTTP_LOG_FIELD_URI equ 00800000h
        HTTP_LOG_FIELD_SITE_ID equ 01000000h
        HTTP_LOG_FIELD_REASON equ 02000000h
        HTTP_LOG_FIELD_QUEUE_NAME equ 04000000h
        HTTP_LOGGING_TYPE typedef SDWORD
        HttpLoggingTypeW3C equ 0
        HttpLoggingTypeIIS equ 1
        HttpLoggingTypeNCSA equ 2
        HttpLoggingTypeRaw equ 3
        _HTTP_LOGGING_TYPE typedef HTTP_LOGGING_TYPE
        PHTTP_LOGGING_TYPE typedef ptr HTTP_LOGGING_TYPE
        
        HTTP_LOGGING_ROLLOVER_TYPE typedef SDWORD
        HttpLoggingRolloverSize equ 0
        HttpLoggingRolloverDaily equ 1
        HttpLoggingRolloverWeekly equ 2
        HttpLoggingRolloverMonthly equ 3
        HttpLoggingRolloverHourly equ 4
        _HTTP_LOGGING_ROLLOVER_TYPE typedef HTTP_LOGGING_ROLLOVER_TYPE
        PHTTP_LOGGING_ROLLOVER_TYPE typedef ptr HTTP_LOGGING_ROLLOVER_TYPE
        
        HTTP_MIN_ALLOWED_LOG_FILE_ROLLOVER_SIZE equ ((1 * 1024 * 1024))
        HTTP_LOGGING_FLAG_LOCAL_TIME_ROLLOVER equ 00000001h
        HTTP_LOGGING_FLAG_USE_UTF8_CONVERSION equ 00000002h
        HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY equ 00000004h
        HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY equ 00000008h
        HTTP_LOGGING_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          LoggingFlags ULONG ?
          SoftwareName PCWSTR ?
          SoftwareNameLength USHORT ?
          DirectoryNameLength USHORT ?
          DirectoryName PCWSTR ?
          Format HTTP_LOGGING_TYPE ?
          Fields ULONG ?
          pExtFields PVOID ?
          NumOfExtFields USHORT ?
          MaxRecordSize USHORT ?
          RolloverType HTTP_LOGGING_ROLLOVER_TYPE ?
          RolloverSize ULONG ?
          pSecurityDescriptor PSECURITY_DESCRIPTOR ?
        HTTP_LOGGING_INFO ends
        _HTTP_LOGGING_INFO typedef HTTP_LOGGING_INFO
        PHTTP_LOGGING_INFO typedef ptr HTTP_LOGGING_INFO
        
        HTTP_BINDING_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          RequestQueueHandle HANDLE ?
        HTTP_BINDING_INFO ends
        _HTTP_BINDING_INFO typedef HTTP_BINDING_INFO
        PHTTP_BINDING_INFO typedef ptr HTTP_BINDING_INFO
        
      endif
      if _WIN32_WINNT ge _WIN32_WINNT_WIN7
        HTTP_PROTECTION_LEVEL_TYPE typedef SDWORD
        HttpProtectionLevelUnrestricted equ 0
        HttpProtectionLevelEdgeRestricted equ 1
        HttpProtectionLevelRestricted equ 2
        _HTTP_PROTECTION_LEVEL_TYPE typedef HTTP_PROTECTION_LEVEL_TYPE
        PHTTP_PROTECTION_LEVEL_TYPE typedef ptr HTTP_PROTECTION_LEVEL_TYPE
        
        HTTP_PROTECTION_LEVEL_INFO struct 8
          Flags HTTP_PROPERTY_FLAGS <>
          Level HTTP_PROTECTION_LEVEL_TYPE ?
        HTTP_PROTECTION_LEVEL_INFO ends
        _HTTP_PROTECTION_LEVEL_INFO typedef HTTP_PROTECTION_LEVEL_INFO
        PHTTP_PROTECTION_LEVEL_INFO typedef ptr HTTP_PROTECTION_LEVEL_INFO
        
      endif
      if _WIN32_WINNT ge 0600h
        HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING equ 00000001h
        HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER equ 00000002h
      endif
      HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY equ 00000001h
      HTTP_RECEIVE_REQUEST_FLAG_FLUSH_BODY equ 00000002h
      if _WIN32_WINNT ge 0600h
        HTTP_RECEIVE_REQUEST_ENTITY_BODY_FLAG_FILL_BUFFER equ 00000001h
      endif
      HTTP_SEND_RESPONSE_FLAG_DISCONNECT equ 00000001h
      HTTP_SEND_RESPONSE_FLAG_MORE_DATA equ 00000002h
      HTTP_SEND_RESPONSE_FLAG_BUFFER_DATA equ 00000004h
      HTTP_SEND_RESPONSE_FLAG_ENABLE_NAGLING equ 00000008h
      HTTP_SEND_RESPONSE_FLAG_PROCESS_RANGES equ 00000020h
      HTTP_SEND_RESPONSE_FLAG_OPAQUE equ 00000040h
      HTTP_SEND_RESPONSE_FLAG_GOAWAY equ 00000100h
      HTTP_FLUSH_RESPONSE_FLAG_RECURSIVE equ 00000001h
      HTTP_OPAQUE_ID typedef ULONGLONG
      PHTTP_OPAQUE_ID typedef ptr ULONGLONG
      HTTP_REQUEST_ID typedef HTTP_OPAQUE_ID
      PHTTP_REQUEST_ID typedef ptr HTTP_OPAQUE_ID
      HTTP_CONNECTION_ID typedef HTTP_OPAQUE_ID
      PHTTP_CONNECTION_ID typedef ptr HTTP_OPAQUE_ID
      HTTP_RAW_CONNECTION_ID typedef HTTP_OPAQUE_ID
      PHTTP_RAW_CONNECTION_ID typedef ptr HTTP_OPAQUE_ID
      if _WIN32_WINNT ge 0600h
        HTTP_URL_GROUP_ID typedef HTTP_OPAQUE_ID
        PHTTP_URL_GROUP_ID typedef ptr HTTP_OPAQUE_ID
        HTTP_SERVER_SESSION_ID typedef HTTP_OPAQUE_ID
        PHTTP_SERVER_SESSION_ID typedef ptr HTTP_OPAQUE_ID
        HTTP_CLIENT_REQUEST_ID typedef HTTP_OPAQUE_ID
        PHTTP_CLIENT_REQUEST_ID typedef ptr HTTP_OPAQUE_ID
      endif
      HTTP_NULL_ID equ 0
      HTTP_IS_NULL_ID macro pid
        exitm <(HTTP_NULL_ID == * (pid))>
      endm
      HTTP_SET_NULL_ID macro pid
        exitm <(* (pid) = HTTP_NULL_ID)>
      endm
      HTTP_BYTE_RANGE_TO_EOF equ (- 1)
      HTTP_BYTE_RANGE struct 8
        StartingOffset ULARGE_INTEGER <>
        Length_ ULARGE_INTEGER <>
      HTTP_BYTE_RANGE ends
      _HTTP_BYTE_RANGE typedef HTTP_BYTE_RANGE
      PHTTP_BYTE_RANGE typedef ptr HTTP_BYTE_RANGE
      
      HTTP_VERSION_ struct 8
        MajorVersion USHORT ?
        MinorVersion USHORT ?
      HTTP_VERSION_ ends
      _HTTP_VERSION typedef HTTP_VERSION_
      PHTTP_VERSION typedef ptr HTTP_VERSION_
      
      HTTP_VERSION_UNKNOWN equ { 0, 0 }
      HTTP_VERSION_0_9 equ { 0, 9 }
      HTTP_VERSION_1_0 equ { 1, 0 }
      HTTP_VERSION_1_1 equ { 1, 1 }
      HTTP_VERSION_2_0 equ { 2, 0 }
      HTTP_VERSION_3_0 equ { 3, 0 }
      HTTP_SET_VERSION macro version, major, minor
        exitm <do { (version).MajorVersion = (major) ; (version).MinorVersion = (minor) ; } while (0, 0)>
      endm
      HTTP_EQUAL_VERSION macro version, major, minor
        exitm <((version).MajorVersion == (major) and (version).MinorVersion == (minor))>
      endm
      HTTP_GREATER_VERSION macro version, major, minor
        exitm <((version).MajorVersion > (major) or ((version).MajorVersion == (major) and (version).MinorVersion > (minor)))>
      endm
      HTTP_LESS_VERSION macro version, major, minor
        exitm <((version).MajorVersion < (major) or ((version).MajorVersion == (major) and (version).MinorVersion < (minor)))>
      endm
      HTTP_NOT_EQUAL_VERSION macro version, major, minor
        exitm <(! HTTP_EQUAL_VERSION(version, major, minor))>
      endm
      HTTP_GREATER_EQUAL_VERSION macro version, major, minor
        exitm <(! HTTP_LESS_VERSION(version, major, minor))>
      endm
      HTTP_LESS_EQUAL_VERSION macro version, major, minor
        exitm <(! HTTP_GREATER_VERSION(version, major, minor))>
      endm
      HTTP_SCHEME typedef SDWORD
      HttpSchemeHttp equ 0
      HttpSchemeHttps equ 1
      HttpSchemeMaximum equ 2
      _HTTP_URI_SCHEME typedef HTTP_SCHEME
      PHTTP_URI_SCHEME typedef ptr HTTP_SCHEME
      
      HTTP_VERB typedef SDWORD
      HttpVerbUnparsed equ 0
      HttpVerbUnknown equ 1
      HttpVerbInvalid equ 2
      HttpVerbOPTIONS equ 3
      HttpVerbGET equ 4
      HttpVerbHEAD equ 5
      HttpVerbPOST equ 6
      HttpVerbPUT equ 7
      HttpVerbDELETE equ 8
      HttpVerbTRACE equ 9
      HttpVerbCONNECT equ 10
      HttpVerbTRACK equ 11
      HttpVerbMOVE equ 12
      HttpVerbCOPY equ 13
      HttpVerbPROPFIND equ 14
      HttpVerbPROPPATCH equ 15
      HttpVerbMKCOL equ 16
      HttpVerbLOCK equ 17
      HttpVerbUNLOCK equ 18
      HttpVerbSEARCH equ 19
      HttpVerbMaximum equ 20
      _HTTP_VERB typedef HTTP_VERB
      PHTTP_VERB typedef ptr HTTP_VERB
      
      HTTP_HEADER_ID typedef SDWORD
      HttpHeaderCacheControl equ 0
      HttpHeaderConnection equ 1
      HttpHeaderDate equ 2
      HttpHeaderKeepAlive equ 3
      HttpHeaderPragma equ 4
      HttpHeaderTrailer equ 5
      HttpHeaderTransferEncoding equ 6
      HttpHeaderUpgrade equ 7
      HttpHeaderVia equ 8
      HttpHeaderWarning equ 9
      HttpHeaderAllow equ 10
      HttpHeaderContentLength equ 11
      HttpHeaderContentType equ 12
      HttpHeaderContentEncoding equ 13
      HttpHeaderContentLanguage equ 14
      HttpHeaderContentLocation equ 15
      HttpHeaderContentMd5 equ 16
      HttpHeaderContentRange equ 17
      HttpHeaderExpires equ 18
      HttpHeaderLastModified equ 19
      HttpHeaderAccept equ 20
      HttpHeaderAcceptCharset equ 21
      HttpHeaderAcceptEncoding equ 22
      HttpHeaderAcceptLanguage equ 23
      HttpHeaderAuthorization equ 24
      HttpHeaderCookie equ 25
      HttpHeaderExpect equ 26
      HttpHeaderFrom equ 27
      HttpHeaderHost equ 28
      HttpHeaderIfMatch equ 29
      HttpHeaderIfModifiedSince equ 30
      HttpHeaderIfNoneMatch equ 31
      HttpHeaderIfRange equ 32
      HttpHeaderIfUnmodifiedSince equ 33
      HttpHeaderMaxForwards equ 34
      HttpHeaderProxyAuthorization equ 35
      HttpHeaderReferer equ 36
      HttpHeaderRange equ 37
      HttpHeaderTe equ 38
      HttpHeaderTranslate equ 39
      HttpHeaderUserAgent equ 40
      HttpHeaderRequestMaximum equ 41
      HttpHeaderAcceptRanges equ 20
      HttpHeaderAge equ 21
      HttpHeaderEtag equ 22
      HttpHeaderLocation equ 23
      HttpHeaderProxyAuthenticate equ 24
      HttpHeaderRetryAfter equ 25
      HttpHeaderServer equ 26
      HttpHeaderSetCookie equ 27
      HttpHeaderVary equ 28
      HttpHeaderWwwAuthenticate equ 29
      HttpHeaderResponseMaximum equ 30
      HttpHeaderMaximum equ 41
      _HTTP_HEADER_ID typedef HTTP_HEADER_ID
      PHTTP_HEADER_ID typedef ptr HTTP_HEADER_ID
      
      HTTP_KNOWN_HEADER struct 8
        RawValueLength USHORT ?
        pRawValue PCSTR ?
      HTTP_KNOWN_HEADER ends
      _HTTP_KNOWN_HEADER typedef HTTP_KNOWN_HEADER
      PHTTP_KNOWN_HEADER typedef ptr HTTP_KNOWN_HEADER
      
      HTTP_UNKNOWN_HEADER struct 8
        NameLength USHORT ?
        RawValueLength USHORT ?
        pName PCSTR ?
        pRawValue PCSTR ?
      HTTP_UNKNOWN_HEADER ends
      _HTTP_UNKNOWN_HEADER typedef HTTP_UNKNOWN_HEADER
      PHTTP_UNKNOWN_HEADER typedef ptr HTTP_UNKNOWN_HEADER
      
      if _WIN32_WINNT ge 0600h
        HTTP_LOG_DATA_TYPE typedef SDWORD
        HttpLogDataTypeFields equ 0
        _HTTP_LOG_DATA_TYPE typedef HTTP_LOG_DATA_TYPE
        PHTTP_LOG_DATA_TYPE typedef ptr HTTP_LOG_DATA_TYPE
        
        HTTP_LOG_DATA struct 8
          Type_ HTTP_LOG_DATA_TYPE ?
        HTTP_LOG_DATA ends
        _HTTP_LOG_DATA typedef HTTP_LOG_DATA
        PHTTP_LOG_DATA typedef ptr HTTP_LOG_DATA
        
        HTTP_LOG_FIELDS_DATA struct 8
          Base HTTP_LOG_DATA <>
          UserNameLength USHORT ?
          UriStemLength USHORT ?
          ClientIpLength USHORT ?
          ServerNameLength USHORT ?
          ServiceNameLength USHORT ?
          ServerIpLength USHORT ?
          MethodLength USHORT ?
          UriQueryLength USHORT ?
          HostLength USHORT ?
          UserAgentLength USHORT ?
          CookieLength USHORT ?
          ReferrerLength USHORT ?
          UserName PWCHAR ?
          UriStem PWCHAR ?
          ClientIp PCHAR ?
          ServerName PCHAR ?
          ServiceName PCHAR ?
          ServerIp PCHAR ?
          Method_ PCHAR ?
          UriQuery PCHAR ?
          Host PCHAR ?
          UserAgent PCHAR ?
          Cookie PCHAR ?
          Referrer PCHAR ?
          ServerPort USHORT ?
          ProtocolStatus USHORT ?
          Win32Status ULONG ?
          MethodNum HTTP_VERB ?
          SubStatus USHORT ?
        HTTP_LOG_FIELDS_DATA ends
        _HTTP_LOG_FIELDS_DATA typedef HTTP_LOG_FIELDS_DATA
        PHTTP_LOG_FIELDS_DATA typedef ptr HTTP_LOG_FIELDS_DATA
        
      endif
      HTTP_DATA_CHUNK_TYPE typedef SDWORD
      HttpDataChunkFromMemory equ 0
      HttpDataChunkFromFileHandle equ 1
      HttpDataChunkFromFragmentCache equ 2
      HttpDataChunkFromFragmentCacheEx equ 3
      HttpDataChunkMaximum equ 4
      _HTTP_DATA_CHUNK_TYPE typedef HTTP_DATA_CHUNK_TYPE
      PHTTP_DATA_CHUNK_TYPE typedef ptr HTTP_DATA_CHUNK_TYPE
      
      HTTP_DATA_CHUNK struct 8
        DataChunkType HTTP_DATA_CHUNK_TYPE ?
        union
          struct FromMemory
            pBuffer PVOID ?
            BufferLength ULONG ?
          ends
          struct FromFileHandle
            ByteRange HTTP_BYTE_RANGE <>
            FileHandle HANDLE ?
          ends
          struct FromFragmentCache
            FragmentNameLength USHORT ?
            pFragmentName PCWSTR ?
          ends
          struct FromFragmentCacheEx
            ByteRange HTTP_BYTE_RANGE <>
            pFragmentName PCWSTR ?
          ends
        ends
      HTTP_DATA_CHUNK ends
      _HTTP_DATA_CHUNK typedef HTTP_DATA_CHUNK
      PHTTP_DATA_CHUNK typedef ptr HTTP_DATA_CHUNK
      
      HTTP_REQUEST_HEADERS struct 8
        UnknownHeaderCount USHORT ?
        pUnknownHeaders PHTTP_UNKNOWN_HEADER ?
        TrailerCount USHORT ?
        pTrailers PHTTP_UNKNOWN_HEADER ?
        KnownHeaders HTTP_KNOWN_HEADER HttpHeaderRequestMaximum dup (<>)
      HTTP_REQUEST_HEADERS ends
      _HTTP_REQUEST_HEADERS typedef HTTP_REQUEST_HEADERS
      PHTTP_REQUEST_HEADERS typedef ptr HTTP_REQUEST_HEADERS
      
      HTTP_RESPONSE_HEADERS struct 8
        UnknownHeaderCount USHORT ?
        pUnknownHeaders PHTTP_UNKNOWN_HEADER ?
        TrailerCount USHORT ?
        pTrailers PHTTP_UNKNOWN_HEADER ?
        KnownHeaders HTTP_KNOWN_HEADER HttpHeaderResponseMaximum dup (<>)
      HTTP_RESPONSE_HEADERS ends
      _HTTP_RESPONSE_HEADERS typedef HTTP_RESPONSE_HEADERS
      PHTTP_RESPONSE_HEADERS typedef ptr HTTP_RESPONSE_HEADERS
      
      HTTP_DELEGATE_REQUEST_PROPERTY_ID typedef SDWORD
      DelegateRequestReservedProperty equ 0
      _HTTP_DELEGATE_REQUEST_PROPERTY_ID typedef HTTP_DELEGATE_REQUEST_PROPERTY_ID
      PHTTP_DELEGATE_REQUEST_PROPERTY_ID typedef ptr HTTP_DELEGATE_REQUEST_PROPERTY_ID
      
      HTTP_DELEGATE_REQUEST_PROPERTY_INFO struct 8
        ProperyId HTTP_DELEGATE_REQUEST_PROPERTY_ID ?
        PropertyInfoLength ULONG ?
        PropertyInfo PVOID ?
      HTTP_DELEGATE_REQUEST_PROPERTY_INFO ends
      _HTTP_DELEGATE_REQUEST_PROPERTY_INFO typedef HTTP_DELEGATE_REQUEST_PROPERTY_INFO
      PHTTP_DELEGATE_REQUEST_PROPERTY_INFO typedef ptr HTTP_DELEGATE_REQUEST_PROPERTY_INFO
      
      HTTP_TRANSPORT_ADDRESS struct 8
        pRemoteAddress PSOCKADDR ?
        pLocalAddress PSOCKADDR ?
      HTTP_TRANSPORT_ADDRESS ends
      _HTTP_TRANSPORT_ADDRESS typedef HTTP_TRANSPORT_ADDRESS
      PHTTP_TRANSPORT_ADDRESS typedef ptr HTTP_TRANSPORT_ADDRESS
      
      HTTP_COOKED_URL struct 8
        FullUrlLength USHORT ?
        HostLength USHORT ?
        AbsPathLength USHORT ?
        QueryStringLength USHORT ?
        pFullUrl PCWSTR ?
        pHost PCWSTR ?
        pAbsPath PCWSTR ?
        pQueryString PCWSTR ?
      HTTP_COOKED_URL ends
      _HTTP_COOKED_URL typedef HTTP_COOKED_URL
      PHTTP_COOKED_URL typedef ptr HTTP_COOKED_URL
      
      HTTP_URL_CONTEXT typedef ULONGLONG
      if _WIN32_WINNT ge 0600h
        HTTP_URL_FLAG_REMOVE_ALL equ 00000001h
        HTTP_AUTH_STATUS typedef SDWORD
        HttpAuthStatusSuccess equ 0
        HttpAuthStatusNotAuthenticated equ 1
        HttpAuthStatusFailure equ 2
        _HTTP_AUTH_STATUS typedef HTTP_AUTH_STATUS
        PHTTP_AUTH_STATUS typedef ptr HTTP_AUTH_STATUS
        
        HTTP_REQUEST_AUTH_TYPE typedef SDWORD
        HttpRequestAuthTypeNone equ 0
        HttpRequestAuthTypeBasic equ 1
        HttpRequestAuthTypeDigest equ 2
        HttpRequestAuthTypeNTLM equ 3
        HttpRequestAuthTypeNegotiate equ 4
        HttpRequestAuthTypeKerberos equ 5
        _HTTP_REQUEST_AUTH_TYPE typedef HTTP_REQUEST_AUTH_TYPE
        PHTTP_REQUEST_AUTH_TYPE typedef ptr HTTP_REQUEST_AUTH_TYPE
        
      endif
      HTTP_SSL_CLIENT_CERT_INFO struct 8
        CertFlags ULONG ?
        CertEncodedSize ULONG ?
        pCertEncoded PUCHAR ?
        Token HANDLE ?
        CertDeniedByMapper BOOLEAN ?
      HTTP_SSL_CLIENT_CERT_INFO ends
      _HTTP_SSL_CLIENT_CERT_INFO typedef HTTP_SSL_CLIENT_CERT_INFO
      PHTTP_SSL_CLIENT_CERT_INFO typedef ptr HTTP_SSL_CLIENT_CERT_INFO
      
      if _WIN32_WINNT ge _WIN32_WINNT_WIN7
        HTTP_RECEIVE_SECURE_CHANNEL_TOKEN equ 1h
      endif
      HTTP_SSL_INFO struct 8
        ServerCertKeySize USHORT ?
        ConnectionKeySize USHORT ?
        ServerCertIssuerSize ULONG ?
        ServerCertSubjectSize ULONG ?
        pServerCertIssuer PCSTR ?
        pServerCertSubject PCSTR ?
        pClientCertInfo PHTTP_SSL_CLIENT_CERT_INFO ?
        SslClientCertNegotiated ULONG ?
      HTTP_SSL_INFO ends
      _HTTP_SSL_INFO typedef HTTP_SSL_INFO
      PHTTP_SSL_INFO typedef ptr HTTP_SSL_INFO
      
      HTTP_SSL_PROTOCOL_INFO struct 8
        Protocol ULONG ?
        CipherType ULONG ?
        CipherStrength ULONG ?
        HashType ULONG ?
        HashStrength ULONG ?
        KeyExchangeType ULONG ?
        KeyExchangeStrength ULONG ?
      HTTP_SSL_PROTOCOL_INFO ends
      _HTTP_SSL_PROTOCOL_INFO typedef HTTP_SSL_PROTOCOL_INFO
      PHTTP_SSL_PROTOCOL_INFO typedef ptr HTTP_SSL_PROTOCOL_INFO
      
      HTTP_REQUEST_SIZING_TYPE typedef SDWORD
      HttpRequestSizingTypeTlsHandshakeLeg1ClientData equ 0
      HttpRequestSizingTypeTlsHandshakeLeg1ServerData equ 1
      HttpRequestSizingTypeTlsHandshakeLeg2ClientData equ 2
      HttpRequestSizingTypeTlsHandshakeLeg2ServerData equ 3
      HttpRequestSizingTypeHeaders equ 4
      HttpRequestSizingTypeMax equ 5
      _HTTP_REQUEST_SIZING_TYPE typedef HTTP_REQUEST_SIZING_TYPE
      PHTTP_REQUEST_SIZING_TYPE typedef ptr HTTP_REQUEST_SIZING_TYPE
      
      HTTP_REQUEST_SIZING_INFO_FLAG_TCP_FAST_OPEN equ 00000001h
      HTTP_REQUEST_SIZING_INFO_FLAG_TLS_SESSION_RESUMPTION equ 00000002h
      HTTP_REQUEST_SIZING_INFO_FLAG_TLS_FALSE_START equ 00000004h
      HTTP_REQUEST_SIZING_INFO_FLAG_FIRST_REQUEST equ 00000008h
      HTTP_REQUEST_SIZING_INFO struct 8
        Flags ULONGLONG ?
        RequestIndex ULONG ?
        RequestSizingCount ULONG ?
        RequestSizing ULONGLONG HttpRequestSizingTypeMax dup (?)
      HTTP_REQUEST_SIZING_INFO ends
      _HTTP_REQUEST_SIZING_INFO typedef HTTP_REQUEST_SIZING_INFO
      PHTTP_REQUEST_SIZING_INFO typedef ptr HTTP_REQUEST_SIZING_INFO
      
      HTTP_REQUEST_TIMING_TYPE typedef SDWORD
      HttpRequestTimingTypeConnectionStart equ 0
      HttpRequestTimingTypeDataStart equ 1
      HttpRequestTimingTypeTlsCertificateLoadStart equ 2
      HttpRequestTimingTypeTlsCertificateLoadEnd equ 3
      HttpRequestTimingTypeTlsHandshakeLeg1Start equ 4
      HttpRequestTimingTypeTlsHandshakeLeg1End equ 5
      HttpRequestTimingTypeTlsHandshakeLeg2Start equ 6
      HttpRequestTimingTypeTlsHandshakeLeg2End equ 7
      HttpRequestTimingTypeTlsAttributesQueryStart equ 8
      HttpRequestTimingTypeTlsAttributesQueryEnd equ 9
      HttpRequestTimingTypeTlsClientCertQueryStart equ 10
      HttpRequestTimingTypeTlsClientCertQueryEnd equ 11
      HttpRequestTimingTypeHttp2StreamStart equ 12
      HttpRequestTimingTypeHttp2HeaderDecodeStart equ 13
      HttpRequestTimingTypeHttp2HeaderDecodeEnd equ 14
      HttpRequestTimingTypeRequestHeaderParseStart equ 15
      HttpRequestTimingTypeRequestHeaderParseEnd equ 16
      HttpRequestTimingTypeRequestRoutingStart equ 17
      HttpRequestTimingTypeRequestRoutingEnd equ 18
      HttpRequestTimingTypeRequestQueuedForInspection equ 19
      HttpRequestTimingTypeRequestDeliveredForInspection equ 20
      HttpRequestTimingTypeRequestReturnedAfterInspection equ 21
      HttpRequestTimingTypeRequestQueuedForDelegation equ 22
      HttpRequestTimingTypeRequestDeliveredForDelegation equ 23
      HttpRequestTimingTypeRequestReturnedAfterDelegation equ 24
      HttpRequestTimingTypeRequestQueuedForIO equ 25
      HttpRequestTimingTypeRequestDeliveredForIO equ 26
      HttpRequestTimingTypeHttp3StreamStart equ 27
      HttpRequestTimingTypeHttp3HeaderDecodeStart equ 28
      HttpRequestTimingTypeHttp3HeaderDecodeEnd equ 29
      HttpRequestTimingTypeMax equ 30
      _HTTP_REQUEST_TIMING_TYPE typedef HTTP_REQUEST_TIMING_TYPE
      PHTTP_REQUEST_TIMING_TYPE typedef ptr HTTP_REQUEST_TIMING_TYPE
      
      HTTP_REQUEST_TIMING_INFO struct 8
        RequestTimingCount ULONG ?
        RequestTiming ULONGLONG HttpRequestTimingTypeMax dup (?)
      HTTP_REQUEST_TIMING_INFO ends
      _HTTP_REQUEST_TIMING_INFO typedef HTTP_REQUEST_TIMING_INFO
      PHTTP_REQUEST_TIMING_INFO typedef ptr HTTP_REQUEST_TIMING_INFO
      
      if _WIN32_WINNT ge 0600h
        HTTP_REQUEST_INFO_TYPE typedef SDWORD
        HttpRequestInfoTypeAuth equ 0
        HttpRequestInfoTypeChannelBind equ 1
        HttpRequestInfoTypeSslProtocol equ 2
        HttpRequestInfoTypeSslTokenBindingDraft equ 3
        HttpRequestInfoTypeSslTokenBinding equ 4
        HttpRequestInfoTypeRequestTiming equ 5
        HttpRequestInfoTypeTcpInfoV0 equ 6
        HttpRequestInfoTypeRequestSizing equ 7
        HttpRequestInfoTypeQuicStats equ 8
        HttpRequestInfoTypeTcpInfoV1 equ 9
        _HTTP_REQUEST_INFO_TYPE typedef HTTP_REQUEST_INFO_TYPE
        PHTTP_REQUEST_INFO_TYPE typedef ptr HTTP_REQUEST_INFO_TYPE
        
        HTTP_REQUEST_INFO struct 8
          InfoType HTTP_REQUEST_INFO_TYPE ?
          InfoLength ULONG ?
          pInfo PVOID ?
        HTTP_REQUEST_INFO ends
        _HTTP_REQUEST_INFO typedef HTTP_REQUEST_INFO
        PHTTP_REQUEST_INFO typedef ptr HTTP_REQUEST_INFO
        
        ifndef __SECSTATUS_DEFINED__
          SECURITY_STATUS typedef LONG
          __SECSTATUS_DEFINED__ equ <>
        endif
        HTTP_REQUEST_AUTH_FLAG_TOKEN_FOR_CACHED_CRED equ 00000001h
        HTTP_REQUEST_AUTH_INFO struct 8
          AuthStatus HTTP_AUTH_STATUS ?
          SecStatus SECURITY_STATUS ?
          Flags ULONG ?
          AuthType HTTP_REQUEST_AUTH_TYPE ?
          AccessToken HANDLE ?
          ContextAttributes ULONG ?
          PackedContextLength ULONG ?
          PackedContextType ULONG ?
          PackedContext PVOID ?
          MutualAuthDataLength ULONG ?
          pMutualAuthData PCHAR ?
          PackageNameLength USHORT ?
          pPackageName PWSTR ?
        HTTP_REQUEST_AUTH_INFO ends
        _HTTP_REQUEST_AUTH_INFO typedef HTTP_REQUEST_AUTH_INFO
        PHTTP_REQUEST_AUTH_INFO typedef ptr HTTP_REQUEST_AUTH_INFO
        
      endif
      HTTP_REQUEST_V1 struct 8
        Flags ULONG ?
        ConnectionId HTTP_CONNECTION_ID ?
        RequestId HTTP_REQUEST_ID ?
        UrlContext HTTP_URL_CONTEXT ?
        Version HTTP_VERSION_ <>
        Verb HTTP_VERB ?
        UnknownVerbLength USHORT ?
        RawUrlLength USHORT ?
        pUnknownVerb PCSTR ?
        pRawUrl PCSTR ?
        CookedUrl HTTP_COOKED_URL <>
        Address HTTP_TRANSPORT_ADDRESS <>
        Headers HTTP_REQUEST_HEADERS <>
        BytesReceived ULONGLONG ?
        EntityChunkCount USHORT ?
        pEntityChunks PHTTP_DATA_CHUNK ?
        RawConnectionId HTTP_RAW_CONNECTION_ID ?
        pSslInfo PHTTP_SSL_INFO ?
      HTTP_REQUEST_V1 ends
      _HTTP_REQUEST_V1 typedef HTTP_REQUEST_V1
      PHTTP_REQUEST_V1 typedef ptr HTTP_REQUEST_V1
      
      if _WIN32_WINNT ge 0600h
        ifdef __cplusplus
          ;[...]
        else
          HTTP_REQUEST_V2 struct 8
            HTTP_REQUEST_V1 <>
            RequestInfoCount  USHORT  ?
            pRequestInfo  PHTTP_REQUEST_INFO  ?
          HTTP_REQUEST_V2 ends
        endif
        HTTP_REQUEST typedef HTTP_REQUEST_V2
      else
        HTTP_REQUEST typedef HTTP_REQUEST_V1
      endif
      PHTTP_REQUEST typedef ptr HTTP_REQUEST
      HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS equ 00000001h
      HTTP_REQUEST_FLAG_IP_ROUTED equ 00000002h
      HTTP_REQUEST_FLAG_HTTP2 equ 00000004h
      HTTP_RESPONSE_V1 struct 8
        Flags ULONG ?
        Version HTTP_VERSION_ <>
        StatusCode USHORT ?
        ReasonLength USHORT ?
        pReason PCSTR ?
        Headers HTTP_RESPONSE_HEADERS <>
        EntityChunkCount USHORT ?
        pEntityChunks PHTTP_DATA_CHUNK ?
      HTTP_RESPONSE_V1 ends
      _HTTP_RESPONSE_V1 typedef HTTP_RESPONSE_V1
      PHTTP_RESPONSE_V1 typedef ptr HTTP_RESPONSE_V1
      
      if _WIN32_WINNT ge 0600h
        HTTP_RESPONSE_FLAG_MULTIPLE_ENCODINGS_AVAILABLE equ 00000001h
        HTTP_RESPONSE_FLAG_MORE_ENTITY_BODY_EXISTS equ 00000002h
        HTTP_RESPONSE_INFO_TYPE typedef SDWORD
        HttpResponseInfoTypeMultipleKnownHeaders equ 0
        HttpResponseInfoTypeAuthenticationProperty equ 1
        HttpResponseInfoTypeQoSProperty equ 2
        HttpResponseInfoTypeChannelBind equ 3
        _HTTP_RESPONSE_INFO_TYPE typedef HTTP_RESPONSE_INFO_TYPE
        PHTTP_RESPONSE_INFO_TYPE typedef HTTP_RESPONSE_INFO_TYPE
        
        HTTP_RESPONSE_INFO struct 8
          Type_ HTTP_RESPONSE_INFO_TYPE ?
          Length_ ULONG ?
          pInfo PVOID ?
        HTTP_RESPONSE_INFO ends
        _HTTP_RESPONSE_INFO typedef HTTP_RESPONSE_INFO
        PHTTP_RESPONSE_INFO typedef ptr HTTP_RESPONSE_INFO
        
        HTTP_RESPONSE_INFO_FLAGS_PRESERVE_ORDER equ 00000001h
        HTTP_MULTIPLE_KNOWN_HEADERS struct 8
          HeaderId HTTP_HEADER_ID ?
          Flags ULONG ?
          KnownHeaderCount USHORT ?
          KnownHeaders PHTTP_KNOWN_HEADER ?
        HTTP_MULTIPLE_KNOWN_HEADERS ends
        _HTTP_MULTIPLE_KNOWN_HEADERS typedef HTTP_MULTIPLE_KNOWN_HEADERS
        PHTTP_MULTIPLE_KNOWN_HEADERS typedef ptr HTTP_MULTIPLE_KNOWN_HEADERS
        
        ifdef __cplusplus
          ;[...]
        else
          HTTP_RESPONSE_V2 struct 8
            HTTP_RESPONSE_V1 <>
            ResponseInfoCount USHORT  ?
            pResponseInfo PHTTP_RESPONSE_INFO ?
          HTTP_RESPONSE_V2 ends
        endif
        HTTP_RESPONSE typedef HTTP_RESPONSE_V2
      else
        HTTP_RESPONSE typedef HTTP_RESPONSE_V1
      endif
      PHTTP_RESPONSE typedef ptr HTTP_RESPONSE
      HTTPAPI_VERSION struct 8
        HttpApiMajorVersion USHORT ?
        HttpApiMinorVersion USHORT ?
      HTTPAPI_VERSION ends
      _HTTPAPI_VERSION typedef HTTPAPI_VERSION
      PHTTPAPI_VERSION typedef ptr HTTPAPI_VERSION
      
      if _WIN32_WINNT ge 0600h
        HTTPAPI_VERSION_2 equ { 2, 0 }
      endif
      HTTPAPI_VERSION_1 equ { 1, 0 }
      HTTPAPI_EQUAL_VERSION macro version, major, minor
        exitm <((version).HttpApiMajorVersion == (major) and (version).HttpApiMinorVersion == (minor))>
      endm
      HTTPAPI_GREATER_VERSION macro version, major, minor
        exitm <((version).HttpApiMajorVersion > (major) or ((version).HttpApiMajorVersion == (major) and (version).HttpApiMinorVersion > (minor)))>
      endm
      HTTPAPI_LESS_VERSION macro version, major, minor
        exitm <((version).HttpApiMajorVersion < (major) or ((version).HttpApiMajorVersion == (major) and (version).HttpApiMinorVersion < (minor)))>
      endm
      HTTPAPI_VERSION_GREATER_OR_EQUAL macro version, major, minor
        exitm <(! HTTPAPI_LESS_VERSION(version, major, minor))>
      endm
      HTTP_CACHE_POLICY_TYPE typedef SDWORD
      HttpCachePolicyNocache equ 0
      HttpCachePolicyUserInvalidates equ 1
      HttpCachePolicyTimeToLive equ 2
      HttpCachePolicyMaximum equ 3
      _HTTP_CACHE_POLICY_TYPE typedef HTTP_CACHE_POLICY_TYPE
      PHTTP_CACHE_POLICY_TYPE typedef ptr HTTP_CACHE_POLICY_TYPE
      
      HTTP_CACHE_POLICY struct 8
        Policy HTTP_CACHE_POLICY_TYPE ?
        SecondsToLive ULONG ?
      HTTP_CACHE_POLICY ends
      _HTTP_CACHE_POLICY typedef HTTP_CACHE_POLICY
      PHTTP_CACHE_POLICY typedef ptr HTTP_CACHE_POLICY
      
      HTTP_SERVICE_CONFIG_ID typedef SDWORD
      HttpServiceConfigIPListenList equ 0
      HttpServiceConfigSSLCertInfo equ 1
      HttpServiceConfigUrlAclInfo equ 2
      HttpServiceConfigTimeout equ 3
      HttpServiceConfigCache equ 4
      if _WIN32_WINNT ge _WIN32_WINNT_WIN8
        HttpServiceConfigSslSniCertInfo equ 5
        HttpServiceConfigSslCcsCertInfo equ 6
      endif
      if _WIN32_WINNT ge _WIN32_WINNT_WIN10
        HttpServiceConfigSetting equ 7
      endif
      HttpServiceConfigSslCertInfoEx equ 8
      HttpServiceConfigSslSniCertInfoEx equ 9
      HttpServiceConfigSslCcsCertInfoEx equ 10
      HttpServiceConfigSslScopedCcsCertInfo equ 11
      HttpServiceConfigSslScopedCcsCertInfoEx equ 12
      HttpServiceConfigMax equ 13
      _HTTP_SERVICE_CONFIG_ID typedef HTTP_SERVICE_CONFIG_ID
      PHTTP_SERVICE_CONFIG_ID typedef ptr HTTP_SERVICE_CONFIG_ID
      
      HTTP_SERVICE_CONFIG_QUERY_TYPE typedef SDWORD
      HttpServiceConfigQueryExact equ 0
      HttpServiceConfigQueryNext equ 1
      HttpServiceConfigQueryMax equ 2
      _HTTP_SERVICE_CONFIG_QUERY_TYPE typedef HTTP_SERVICE_CONFIG_QUERY_TYPE
      PHTTP_SERVICE_CONFIG_QUERY_TYPE typedef ptr HTTP_SERVICE_CONFIG_QUERY_TYPE
      
      HTTP_SERVICE_CONFIG_SSL_KEY struct 8
        pIpPort PSOCKADDR ?
      HTTP_SERVICE_CONFIG_SSL_KEY ends
      _HTTP_SERVICE_CONFIG_SSL_KEY typedef HTTP_SERVICE_CONFIG_SSL_KEY
      PHTTP_SERVICE_CONFIG_SSL_KEY typedef ptr HTTP_SERVICE_CONFIG_SSL_KEY
      
      HTTP_SERVICE_CONFIG_SSL_KEY_EX struct 8
        IpPort SOCKADDR_STORAGE <>
      HTTP_SERVICE_CONFIG_SSL_KEY_EX ends
      _HTTP_SERVICE_CONFIG_SSL_KEY_EX typedef HTTP_SERVICE_CONFIG_SSL_KEY_EX
      PHTTP_SERVICE_CONFIG_SSL_KEY_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_KEY_EX
      
      if _WIN32_WINNT ge _WIN32_WINNT_WIN8
        HTTP_SERVICE_CONFIG_SSL_SNI_KEY struct 8
          IpPort SOCKADDR_STORAGE <>
          Host PWSTR ?
        HTTP_SERVICE_CONFIG_SSL_SNI_KEY ends
        _HTTP_SERVICE_CONFIG_SSL_SNI_KEY typedef HTTP_SERVICE_CONFIG_SSL_SNI_KEY
        PHTTP_SERVICE_CONFIG_SSL_SNI_KEY typedef ptr HTTP_SERVICE_CONFIG_SSL_SNI_KEY
        
        HTTP_SERVICE_CONFIG_SSL_CCS_KEY struct 8
          LocalAddress SOCKADDR_STORAGE <>
        HTTP_SERVICE_CONFIG_SSL_CCS_KEY ends
        _HTTP_SERVICE_CONFIG_SSL_CCS_KEY typedef HTTP_SERVICE_CONFIG_SSL_CCS_KEY
        PHTTP_SERVICE_CONFIG_SSL_CCS_KEY typedef ptr HTTP_SERVICE_CONFIG_SSL_CCS_KEY
        
      endif
      HTTP_SERVICE_CONFIG_SSL_PARAM struct 8
        SslHashLength ULONG ?
        pSslHash PVOID ?
        AppId GUID <>
        pSslCertStoreName PWSTR ?
        DefaultCertCheckMode DWORD ?
        DefaultRevocationFreshnessTime DWORD ?
        DefaultRevocationUrlRetrievalTimeout DWORD ?
        pDefaultSslCtlIdentifier PWSTR ?
        pDefaultSslCtlStoreName PWSTR ?
        DefaultFlags DWORD ?
      HTTP_SERVICE_CONFIG_SSL_PARAM ends
      _HTTP_SERVICE_CONFIG_SSL_PARAM typedef HTTP_SERVICE_CONFIG_SSL_PARAM
      PHTTP_SERVICE_CONFIG_SSL_PARAM typedef ptr HTTP_SERVICE_CONFIG_SSL_PARAM
      
      HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE typedef SDWORD
      ExParamTypeHttp2Window equ 0
      ExParamTypeHttp2SettingsLimits equ 1
      ExParamTypeHttpPerformance equ 2
      ExParamTypeMax equ 3
      _HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE typedef HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE
      PHTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE typedef ptr HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE
      
      HTTP2_WINDOW_SIZE_PARAM struct 8
        Http2ReceiveWindowSize DWORD ?
      HTTP2_WINDOW_SIZE_PARAM ends
      _HTTP2_WINDOW_SIZE_PARAM typedef HTTP2_WINDOW_SIZE_PARAM
      PHTTP2_WINDOW_SIZE_PARAM typedef ptr HTTP2_WINDOW_SIZE_PARAM
      
      HTTP2_SETTINGS_LIMITS_PARAM struct 8
        Http2MaxSettingsPerFrame DWORD ?
        Http2MaxSettingsPerMinute DWORD ?
      HTTP2_SETTINGS_LIMITS_PARAM ends
      _HTTP2_SETTINGS_LIMITS_PARAM typedef HTTP2_SETTINGS_LIMITS_PARAM
      PHTTP2_SETTINGS_LIMITS_PARAM typedef ptr HTTP2_SETTINGS_LIMITS_PARAM
      
      HTTP_PERFORMANCE_PARAM struct 8
        SendBufferingFlags ULONGLONG ?
        EnableAggressiveICW BOOLEAN ?
        MaxBufferedSendBytes ULONG ?
        MaxConcurrentClientStreams ULONG ?
      HTTP_PERFORMANCE_PARAM ends
      _HTTP_PERFORMANCE_PARAM typedef HTTP_PERFORMANCE_PARAM
      PHTTP_PERFORMANCE_PARAM typedef ptr HTTP_PERFORMANCE_PARAM
      
      HTTP_SERVICE_CONFIG_SSL_PARAM_EX struct 8
        ParamType HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE ?
        Flags ULONGLONG ?
        union
          Http2WindowSizeParam HTTP2_WINDOW_SIZE_PARAM <>
          Http2SettingsLimitsParam HTTP2_SETTINGS_LIMITS_PARAM <>
          HttpPerformanceParam HTTP_PERFORMANCE_PARAM <>
        ends
      HTTP_SERVICE_CONFIG_SSL_PARAM_EX ends
      _HTTP_SERVICE_CONFIG_SSL_PARAM_EX typedef HTTP_SERVICE_CONFIG_SSL_PARAM_EX
      PHTTP_SERVICE_CONFIG_SSL_PARAM_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_PARAM_EX
      
      HTTP_SERVICE_CONFIG_SSL_FLAG_USE_DS_MAPPER equ 00000001h
      HTTP_SERVICE_CONFIG_SSL_FLAG_NEGOTIATE_CLIENT_CERT equ 00000002h
      if _WIN32_WINNT lt 0600h
        HTTP_SERVICE_CONFIG_SSL_FLAG_NO_RAW_FILTER equ 00000004h
      endif
      HTTP_SERVICE_CONFIG_SSL_FLAG_REJECT equ 00000008h
      HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_HTTP2 equ 00000010h
      HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_QUIC equ 00000020h
      HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_TLS13 equ 00000040h
      HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_OCSP_STAPLING equ 00000080h
      HTTP_SERVICE_CONFIG_SSL_FLAG_ENABLE_TOKEN_BINDING equ 00000100h
      HTTP_SERVICE_CONFIG_SSL_FLAG_LOG_EXTENDED_EVENTS equ 00000200h
      HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_LEGACY_TLS equ 00000400h
      HTTP_SERVICE_CONFIG_SSL_FLAG_ENABLE_SESSION_TICKET equ 00000800h
      HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_TLS12 equ 00001000h
      HTTP_SERVICE_CONFIG_SSL_SET struct 8
        KeyDesc HTTP_SERVICE_CONFIG_SSL_KEY <>
        ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM <>
      HTTP_SERVICE_CONFIG_SSL_SET ends
      _HTTP_SERVICE_CONFIG_SSL_SET typedef HTTP_SERVICE_CONFIG_SSL_SET
      PHTTP_SERVICE_CONFIG_SSL_SET typedef ptr HTTP_SERVICE_CONFIG_SSL_SET
      
      if _WIN32_WINNT ge _WIN32_WINNT_WIN8
        HTTP_SERVICE_CONFIG_SSL_SNI_SET struct 8
          KeyDesc HTTP_SERVICE_CONFIG_SSL_SNI_KEY <>
          ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM <>
        HTTP_SERVICE_CONFIG_SSL_SNI_SET ends
        _HTTP_SERVICE_CONFIG_SSL_SNI_SET typedef HTTP_SERVICE_CONFIG_SSL_SNI_SET
        PHTTP_SERVICE_CONFIG_SSL_SNI_SET typedef ptr HTTP_SERVICE_CONFIG_SSL_SNI_SET
        
        HTTP_SERVICE_CONFIG_SSL_CCS_SET struct 8
          KeyDesc HTTP_SERVICE_CONFIG_SSL_CCS_KEY <>
          ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM <>
        HTTP_SERVICE_CONFIG_SSL_CCS_SET ends
        _HTTP_SERVICE_CONFIG_SSL_CCS_SET typedef HTTP_SERVICE_CONFIG_SSL_CCS_SET
        PHTTP_SERVICE_CONFIG_SSL_CCS_SET typedef ptr HTTP_SERVICE_CONFIG_SSL_CCS_SET
        
        HTTP_SERVICE_CONFIG_SSL_SET_EX struct 8
          KeyDesc HTTP_SERVICE_CONFIG_SSL_KEY_EX <>
          ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM_EX <>
        HTTP_SERVICE_CONFIG_SSL_SET_EX ends
        _HTTP_SERVICE_CONFIG_SSL_SET_EX typedef HTTP_SERVICE_CONFIG_SSL_SET_EX
        PHTTP_SERVICE_CONFIG_SSL_SET_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_SET_EX
        
        HTTP_SERVICE_CONFIG_SSL_SNI_SET_EX struct 8
          KeyDesc HTTP_SERVICE_CONFIG_SSL_SNI_KEY <>
          ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM_EX <>
        HTTP_SERVICE_CONFIG_SSL_SNI_SET_EX ends
        _HTTP_SERVICE_CONFIG_SSL_SNI_SET_EX typedef HTTP_SERVICE_CONFIG_SSL_SNI_SET_EX
        PHTTP_SERVICE_CONFIG_SSL_SNI_SET_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_SNI_SET_EX
        
        HTTP_SERVICE_CONFIG_SSL_CCS_SET_EX struct 8
          KeyDesc HTTP_SERVICE_CONFIG_SSL_CCS_KEY <>
          ParamDesc HTTP_SERVICE_CONFIG_SSL_PARAM_EX <>
        HTTP_SERVICE_CONFIG_SSL_CCS_SET_EX ends
        _HTTP_SERVICE_CONFIG_SSL_CCS_SET_EX typedef HTTP_SERVICE_CONFIG_SSL_CCS_SET_EX
        PHTTP_SERVICE_CONFIG_SSL_CCS_SET_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_CCS_SET_EX
        
      endif
      HTTP_SERVICE_CONFIG_SSL_QUERY struct 8
        QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
        KeyDesc HTTP_SERVICE_CONFIG_SSL_KEY <>
        dwToken DWORD ?
      HTTP_SERVICE_CONFIG_SSL_QUERY ends
      _HTTP_SERVICE_CONFIG_SSL_QUERY typedef HTTP_SERVICE_CONFIG_SSL_QUERY
      PHTTP_SERVICE_CONFIG_SSL_QUERY typedef ptr HTTP_SERVICE_CONFIG_SSL_QUERY
      
      if _WIN32_WINNT ge _WIN32_WINNT_WIN8
        HTTP_SERVICE_CONFIG_SSL_SNI_QUERY struct 8
          QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
          KeyDesc HTTP_SERVICE_CONFIG_SSL_SNI_KEY <>
          dwToken DWORD ?
        HTTP_SERVICE_CONFIG_SSL_SNI_QUERY ends
        _HTTP_SERVICE_CONFIG_SSL_SNI_QUERY typedef HTTP_SERVICE_CONFIG_SSL_SNI_QUERY
        PHTTP_SERVICE_CONFIG_SSL_SNI_QUERY typedef ptr HTTP_SERVICE_CONFIG_SSL_SNI_QUERY
        
        HTTP_SERVICE_CONFIG_SSL_CCS_QUERY struct 8
          QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
          KeyDesc HTTP_SERVICE_CONFIG_SSL_CCS_KEY <>
          dwToken DWORD ?
        HTTP_SERVICE_CONFIG_SSL_CCS_QUERY ends
        _HTTP_SERVICE_CONFIG_SSL_CCS_QUERY typedef HTTP_SERVICE_CONFIG_SSL_CCS_QUERY
        PHTTP_SERVICE_CONFIG_SSL_CCS_QUERY typedef ptr HTTP_SERVICE_CONFIG_SSL_CCS_QUERY
        
        HTTP_SERVICE_CONFIG_SSL_QUERY_EX struct 8
          QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
          KeyDesc HTTP_SERVICE_CONFIG_SSL_KEY_EX <>
          dwToken DWORD ?
          ParamType HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE ?
        HTTP_SERVICE_CONFIG_SSL_QUERY_EX ends
        _HTTP_SERVICE_CONFIG_SSL_QUERY_EX typedef HTTP_SERVICE_CONFIG_SSL_QUERY_EX
        PHTTP_SERVICE_CONFIG_SSL_QUERY_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_QUERY_EX
        
        HTTP_SERVICE_CONFIG_SSL_SNI_QUERY_EX struct 8
          QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
          KeyDesc HTTP_SERVICE_CONFIG_SSL_SNI_KEY <>
          dwToken DWORD ?
          ParamType HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE ?
        HTTP_SERVICE_CONFIG_SSL_SNI_QUERY_EX ends
        _HTTP_SERVICE_CONFIG_SSL_SNI_QUERY_EX typedef HTTP_SERVICE_CONFIG_SSL_SNI_QUERY_EX
        PHTTP_SERVICE_CONFIG_SSL_SNI_QUERY_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_SNI_QUERY_EX
        
        HTTP_SERVICE_CONFIG_SSL_CCS_QUERY_EX struct 8
          QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
          KeyDesc HTTP_SERVICE_CONFIG_SSL_CCS_KEY <>
          dwToken DWORD ?
          ParamType HTTP_SSL_SERVICE_CONFIG_EX_PARAM_TYPE ?
        HTTP_SERVICE_CONFIG_SSL_CCS_QUERY_EX ends
        _HTTP_SERVICE_CONFIG_SSL_CCS_QUERY_EX typedef HTTP_SERVICE_CONFIG_SSL_CCS_QUERY_EX
        PHTTP_SERVICE_CONFIG_SSL_CCS_QUERY_EX typedef ptr HTTP_SERVICE_CONFIG_SSL_CCS_QUERY_EX
        
      endif
      HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM struct 8
        AddrLength USHORT ?
        pAddress PSOCKADDR ?
      HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM ends
      _HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM typedef HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM
      PHTTP_SERVICE_CONFIG_IP_LISTEN_PARAM typedef ptr HTTP_SERVICE_CONFIG_IP_LISTEN_PARAM
      
      HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY struct 8
        AddrCount ULONG ?
        AddrList SOCKADDR_STORAGE ANYSIZE_ARRAY dup (<>)
      HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY ends
      _HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY typedef HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY
      PHTTP_SERVICE_CONFIG_IP_LISTEN_QUERY typedef ptr HTTP_SERVICE_CONFIG_IP_LISTEN_QUERY
      
      HTTP_SERVICE_CONFIG_URLACL_KEY struct 8
        pUrlPrefix PWSTR ?
      HTTP_SERVICE_CONFIG_URLACL_KEY ends
      _HTTP_SERVICE_CONFIG_URLACL_KEY typedef HTTP_SERVICE_CONFIG_URLACL_KEY
      PHTTP_SERVICE_CONFIG_URLACL_KEY typedef ptr HTTP_SERVICE_CONFIG_URLACL_KEY
      
      HTTP_SERVICE_CONFIG_URLACL_PARAM struct 8
        pStringSecurityDescriptor PWSTR ?
      HTTP_SERVICE_CONFIG_URLACL_PARAM ends
      _HTTP_SERVICE_CONFIG_URLACL_PARAM typedef HTTP_SERVICE_CONFIG_URLACL_PARAM
      PHTTP_SERVICE_CONFIG_URLACL_PARAM typedef ptr HTTP_SERVICE_CONFIG_URLACL_PARAM
      
      HTTP_SERVICE_CONFIG_URLACL_SET struct 8
        KeyDesc HTTP_SERVICE_CONFIG_URLACL_KEY <>
        ParamDesc HTTP_SERVICE_CONFIG_URLACL_PARAM <>
      HTTP_SERVICE_CONFIG_URLACL_SET ends
      _HTTP_SERVICE_CONFIG_URLACL_SET typedef HTTP_SERVICE_CONFIG_URLACL_SET
      PHTTP_SERVICE_CONFIG_URLACL_SET typedef ptr HTTP_SERVICE_CONFIG_URLACL_SET
      
      HTTP_SERVICE_CONFIG_URLACL_QUERY struct 8
        QueryDesc HTTP_SERVICE_CONFIG_QUERY_TYPE ?
        KeyDesc HTTP_SERVICE_CONFIG_URLACL_KEY <>
        dwToken DWORD ?
      HTTP_SERVICE_CONFIG_URLACL_QUERY ends
      _HTTP_SERVICE_CONFIG_URLACL_QUERY typedef HTTP_SERVICE_CONFIG_URLACL_QUERY
      PHTTP_SERVICE_CONFIG_URLACL_QUERY typedef ptr HTTP_SERVICE_CONFIG_URLACL_QUERY
      
      HTTP_SERVICE_CONFIG_CACHE_KEY typedef SDWORD
      MaxCacheResponseSize equ 0
      CacheRangeChunkSize equ 1
      _HTTP_SERVICE_CONFIG_CACHE_KEY typedef HTTP_SERVICE_CONFIG_CACHE_KEY
      PHTTP_SERVICE_CONFIG_CACHE_KEY typedef ptr HTTP_SERVICE_CONFIG_CACHE_KEY
      
      HTTP_SERVICE_CONFIG_CACHE_PARAM typedef ULONG
      PHTTP_SERVICE_CONFIG_CACHE_PARAM typedef ptr ULONG
      HTTP_SERVICE_CONFIG_CACHE_SET struct 8
        KeyDesc HTTP_SERVICE_CONFIG_CACHE_KEY ?
        ParamDesc HTTP_SERVICE_CONFIG_CACHE_PARAM ?
      HTTP_SERVICE_CONFIG_CACHE_SET ends
      PHTTP_SERVICE_CONFIG_CACHE_SET typedef ptr HTTP_SERVICE_CONFIG_CACHE_SET
      
      HTTP_REQUEST_PROPERTY typedef SDWORD
      HttpRequestPropertyIsb equ 0
      HttpRequestPropertyTcpInfoV0 equ 1
      HttpRequestPropertyQuicStats equ 2
      HttpRequestPropertyTcpInfoV1 equ 3
      HttpRequestPropertySni equ 4
      _HTTP_REQUEST_PROPERTY typedef HTTP_REQUEST_PROPERTY
      PHTTP_REQUEST_PROPERTY typedef ptr HTTP_REQUEST_PROPERTY
      
      HTTP_QUERY_REQUEST_QUALIFIER_TCP struct 8
        Freshness ULONGLONG ?
      HTTP_QUERY_REQUEST_QUALIFIER_TCP ends
      _HTTP_QUERY_REQUEST_QUALIFIER_TCP typedef HTTP_QUERY_REQUEST_QUALIFIER_TCP
      PHTTP_QUERY_REQUEST_QUALIFIER_TCP typedef ptr HTTP_QUERY_REQUEST_QUALIFIER_TCP
      
      HTTP_QUERY_REQUEST_QUALIFIER_QUIC struct 8
        Freshness ULONGLONG ?
      HTTP_QUERY_REQUEST_QUALIFIER_QUIC ends
      _HTTP_QUERY_REQUEST_QUALIFIER_QUIC typedef HTTP_QUERY_REQUEST_QUALIFIER_QUIC
      PHTTP_QUERY_REQUEST_QUALIFIER_QUIC typedef ptr HTTP_QUERY_REQUEST_QUALIFIER_QUIC
      
      HTTP_REQUEST_PROPERTY_SNI_HOST_MAX_LENGTH equ 255
      HTTP_REQUEST_PROPERTY_SNI_FLAG_SNI_USED equ 00000001h
      HTTP_REQUEST_PROPERTY_SNI_FLAG_NO_SNI equ 00000002h
      HTTP_REQUEST_PROPERTY_SNI struct 8
        Hostname WCHAR HTTP_REQUEST_PROPERTY_SNI_HOST_MAX_LENGTH + 1 dup (?)
        Flags ULONG ?
      HTTP_REQUEST_PROPERTY_SNI ends
      _HTTP_REQUEST_PROPERTY_SNI typedef HTTP_REQUEST_PROPERTY_SNI
      PHTTP_REQUEST_PROPERTY_SNI typedef ptr HTTP_REQUEST_PROPERTY_SNI
      
      if  not Defined(HTTPAPI_LINKAGE)
        HTTPAPI_LINKAGE equ <DECLSPEC_IMPORT>
      endif
      @DefProto DllImport, HttpInitialize, WIN_STD_CALL_CONV,, <:HTTPAPI_VERSION, :ULONG, :PVOID>, 12
      @DefProto DllImport, HttpTerminate, WIN_STD_CALL_CONV,, <:ULONG, :PVOID>, 8
      @DefProto DllImport, HttpCreateHttpHandle, WIN_STD_CALL_CONV,, <:PHANDLE, :ULONG>, 8
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, HttpCreateRequestQueue, WIN_STD_CALL_CONV,, <:HTTPAPI_VERSION, :PCWSTR, :PSECURITY_ATTRIBUTES, :ULONG, :PHANDLE>, 20
        @DefProto DllImport, HttpCloseRequestQueue, WIN_STD_CALL_CONV,, <:HANDLE>, 4
        @DefProto DllImport, HttpSetRequestQueueProperty, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_SERVER_PROPERTY, :PVOID, :ULONG, :ULONG, :PVOID>, 24
        @DefProto DllImport, HttpQueryRequestQueueProperty, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_SERVER_PROPERTY, :PVOID, :ULONG, :ULONG, :PULONG, :PVOID>, 28
        @DefProto DllImport, HttpShutdownRequestQueue, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      endif
      @DefProto DllImport, HttpReceiveClientCertificate, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_CONNECTION_ID, :ULONG, :PHTTP_SSL_CLIENT_CERT_INFO, :ULONG, :PULONG, :LPOVERLAPPED>, 28
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, HttpCreateServerSession, WIN_STD_CALL_CONV,, <:HTTPAPI_VERSION, :PHTTP_SERVER_SESSION_ID, :ULONG>, 12
        @DefProto DllImport, HttpCloseServerSession, WIN_STD_CALL_CONV,, <:HTTP_SERVER_SESSION_ID>, 4
        @DefProto DllImport, HttpQueryServerSessionProperty, WIN_STD_CALL_CONV,, <:HTTP_SERVER_SESSION_ID, :HTTP_SERVER_PROPERTY, :PVOID, :ULONG, :PULONG>, 20
        @DefProto DllImport, HttpSetServerSessionProperty, WIN_STD_CALL_CONV,, <:HTTP_SERVER_SESSION_ID, :HTTP_SERVER_PROPERTY, :PVOID, :ULONG>, 16
      endif
      @DefProto DllImport, HttpAddUrl, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR, :PVOID>, 12
      @DefProto DllImport, HttpRemoveUrl, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR>, 8
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, HttpCreateUrlGroup, WIN_STD_CALL_CONV,, <:HTTP_SERVER_SESSION_ID, :PHTTP_URL_GROUP_ID, :ULONG>, 12
        @DefProto DllImport, HttpCloseUrlGroup, WIN_STD_CALL_CONV,, <:HTTP_URL_GROUP_ID>, 4
        @DefProto DllImport, HttpAddUrlToUrlGroup, WIN_STD_CALL_CONV,, <:HTTP_URL_GROUP_ID, :PCWSTR, :HTTP_URL_CONTEXT, :ULONG>, 16
        @DefProto DllImport, HttpRemoveUrlFromUrlGroup, WIN_STD_CALL_CONV,, <:HTTP_URL_GROUP_ID, :PCWSTR, :ULONG>, 12
        @DefProto DllImport, HttpSetUrlGroupProperty, WIN_STD_CALL_CONV,, <:HTTP_URL_GROUP_ID, :HTTP_SERVER_PROPERTY, :PVOID, :ULONG>, 16
        @DefProto DllImport, HttpQueryUrlGroupProperty, WIN_STD_CALL_CONV,, <:HTTP_URL_GROUP_ID, :HTTP_SERVER_PROPERTY, :PVOID, :ULONG, :PULONG>, 20
      endif
      if _WIN32_WINNT ge _WIN32_WINNT_WIN8
        @DefProto DllImport, HttpPrepareUrl, WIN_STD_CALL_CONV,, <:PVOID, :ULONG, :PCWSTR, :ptr PWSTR>, 16
      endif
      @DefProto DllImport, HttpReceiveHttpRequest, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :ULONG, :PHTTP_REQUEST, :ULONG, :PULONG, :LPOVERLAPPED>, 32
      @DefProto DllImport, HttpReceiveRequestEntityBody, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :ULONG, :PVOID, :ULONG, :PULONG, :LPOVERLAPPED>, 32
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, HttpSendHttpResponse, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :ULONG, :PHTTP_RESPONSE, :PHTTP_CACHE_POLICY, :PULONG, :PVOID, :ULONG, :LPOVERLAPPED, :PHTTP_LOG_DATA>, 44
      else
        @DefProto DllImport, HttpSendHttpResponse, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :ULONG, :PHTTP_RESPONSE, :PVOID, :PULONG, :PVOID, :ULONG, :LPOVERLAPPED, :PVOID>, 44
      endif
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, HttpSendResponseEntityBody, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :ULONG, :USHORT, :PHTTP_DATA_CHUNK, :PULONG, :PVOID, :ULONG, :LPOVERLAPPED, :PHTTP_LOG_DATA>, 44
      else
        @DefProto DllImport, HttpSendResponseEntityBody, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :ULONG, :USHORT, :PHTTP_DATA_CHUNK, :PULONG, :PVOID, :ULONG, :LPOVERLAPPED, :PVOID>, 44
      endif
      @DefProto DllImport, HttpDeclarePush, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :HTTP_VERB, :PCWSTR, :PCSTR, :PHTTP_REQUEST_HEADERS>, 28
      @DefProto DllImport, HttpWaitForDisconnect, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_CONNECTION_ID, :LPOVERLAPPED>, 12
      if _WIN32_WINNT ge 0600h
        @DefProto DllImport, HttpWaitForDisconnectEx, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_CONNECTION_ID, :ULONG, :LPOVERLAPPED>, 16
        @DefProto DllImport, HttpCancelHttpRequest, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_REQUEST_ID, :LPOVERLAPPED>, 16
        @DefProto DllImport, HttpWaitForDemandStart, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED>, 8
      endif
      @DefProto DllImport, HttpFlushResponseCache, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR, :ULONG, :LPOVERLAPPED>, 16
      @DefProto DllImport, HttpAddFragmentToCache, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR, :PHTTP_DATA_CHUNK, :PHTTP_CACHE_POLICY, :LPOVERLAPPED>, 20
      @DefProto DllImport, HttpReadFragmentFromCache, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR, :PHTTP_BYTE_RANGE, :PVOID, :ULONG, :PULONG, :LPOVERLAPPED>, 28
      @DefProto DllImport, HttpSetServiceConfiguration, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_SERVICE_CONFIG_ID, :PVOID, :ULONG, :LPOVERLAPPED>, 20
      @DefProto DllImport, HttpUpdateServiceConfiguration, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_SERVICE_CONFIG_ID, :PVOID, :ULONG, :LPOVERLAPPED>, 20
      @DefProto DllImport, HttpDeleteServiceConfiguration, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_SERVICE_CONFIG_ID, :PVOID, :ULONG, :LPOVERLAPPED>, 20
      @DefProto DllImport, HttpQueryServiceConfiguration, WIN_STD_CALL_CONV,, <:HANDLE, :HTTP_SERVICE_CONFIG_ID, :PVOID, :ULONG, :PVOID, :ULONG, :PULONG, :LPOVERLAPPED>, 32
      HttpGetExtension proto WIN_STD_CALL_CONV :HTTPAPI_VERSION, :ULONG, :PVOID, :ULONG
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
endif
 