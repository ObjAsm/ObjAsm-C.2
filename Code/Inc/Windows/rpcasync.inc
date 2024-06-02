;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpcasync.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 16/12/2023 11:05:40

include winapifamily.inc
ifndef __RPCASYNC_H__
  __RPCASYNC_H__ equ <>
  if _MSC_VER gt 1000
  endif
  if Defined(__RPC_WIN64__)
    include pshpack8.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if Defined(_KRPCENV_)
      include ntddk.inc
    endif
    if Defined(RPC_NO_WINDOWS_H) or Defined(_KRPCENV_)
      include windef.inc
    endif
    if _MSC_VER ge 1200
    endif
    RPC_ASYNC_VERSION_1_0 equ <sizeof(RPC_ASYNC_STATE)>
    RPC_NOTIFICATION_TYPES typedef SDWORD
    RpcNotificationTypeNone equ 0
    RpcNotificationTypeEvent equ 1
    if  not Defined(_KRPCENV_)
      RpcNotificationTypeApc equ 2
      RpcNotificationTypeIoc equ 3
      RpcNotificationTypeHwnd equ 4
    endif
    RpcNotificationTypeCallback equ 5
    _RPC_NOTIFICATION_TYPES typedef RPC_NOTIFICATION_TYPES

    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPC_ASYNC_EVENT typedef SDWORD
      RpcCallComplete equ 0
      RpcSendComplete equ 1
      RpcReceiveComplete equ 2
      RpcClientDisconnect equ 3
      RpcClientCancel equ 4
      _RPC_ASYNC_EVENT typedef RPC_ASYNC_EVENT

    else
      RPC_ASYNC_EVENT typedef SDWORD
      RpcCallComplete equ 0
      RpcSendComplete equ 1
      RpcReceiveComplete equ 2
      RpcClientDisconnect equ 3
      _RPC_ASYNC_EVENT typedef RPC_ASYNC_EVENT

    endif
    RPCNOTIFICATION_ROUTINE typedef proto :ptr _RPC_ASYNC_STATE, :ptr, :RPC_ASYNC_EVENT
    PFN_RPCNOTIFICATION_ROUTINE typedef ptr RPCNOTIFICATION_ROUTINE
    RPC_ASYNC_NOTIFICATION_INFO union
      if  not Defined(_KRPCENV_)
        struct APC
          NotificationRoutine PFN_RPCNOTIFICATION_ROUTINE ?
          hThread HANDLE ?
        ends
        if  not Defined(RPC_NO_WINDOWS_H) or Defined(_WINBASE_)
          struct IOC
            hIOPort HANDLE ?
            dwNumberOfBytesTransferred DWORD ?
            dwCompletionKey DWORD_PTR ?
            lpOverlapped LPOVERLAPPED ?
          ends
        endif
        if  not Defined(RPC_NO_WINDOWS_H)
          struct HWND
            hWnd HWND ?
            Msg UINT ?
          ends
        endif
      endif
      if  not Defined(_KRPCENV_)
        hEvent HANDLE ?
      else
        Event_ PKEVENT ?
      endif
      NotificationRoutine PFN_RPCNOTIFICATION_ROUTINE ?
    RPC_ASYNC_NOTIFICATION_INFO ends
    _RPC_ASYNC_NOTIFICATION_INFO typedef RPC_ASYNC_NOTIFICATION_INFO
    PRPC_ASYNC_NOTIFICATION_INFO typedef ptr RPC_ASYNC_NOTIFICATION_INFO
    RPC_ASYNC_STATE struct
      Size_ DWORD ?
      Signature DWORD ?
      Lock_ SDWORD ?
      Flags DWORD ?
      StubInfo POINTER ?
      UserInfo POINTER ?
      RuntimeInfo POINTER ?
      Event_ RPC_ASYNC_EVENT ?
      NotificationType RPC_NOTIFICATION_TYPES ?
      u RPC_ASYNC_NOTIFICATION_INFO <>
      Reserved LONG_PTR 4 dup (?)
    RPC_ASYNC_STATE ends
    _RPC_ASYNC_STATE typedef RPC_ASYNC_STATE
    PRPC_ASYNC_STATE typedef ptr RPC_ASYNC_STATE
    RPC_C_NOTIFY_ON_SEND_COMPLETE equ 1h
    RPC_C_INFINITE_TIMEOUT equ <INFINITE>
    RpcAsyncGetCallHandle macro pAsync
      exitm <(((PRPC_ASYNC_STATE) pAsync) - RuntimeInfo)>
    endm
    if  not Defined(_KRPCENV_)
      @DefProto DllImport, RpcAsyncRegisterInfo, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE>, 4
    endif
    @DefProto DllImport, RpcAsyncInitializeHandle, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE, :DWORD>, 8
    @DefProto DllImport, RpcAsyncGetCallStatus, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE>, 4
    @DefProto DllImport, RpcAsyncCompleteCall, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE, :ptr>, 8
    @DefProto DllImport, RpcAsyncAbortCall, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE, :DWORD>, 8
    @DefProto DllImport, RpcAsyncCancelCall, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE, :BOOL>, 8
    if (NTDDI_VERSION ge NTDDI_WINXP)
      if  not Defined(RPC_NO_WINDOWS_H) or Defined(_KRPCENV_) or Defined(_WINBASE_)
        ExtendedErrorParamTypes typedef SDWORD
        eeptAnsiString equ 1
        eeptUnicodeString equ 2
        eeptLongVal equ 3
        eeptShortVal equ 4
        eeptPointerVal equ 5
        eeptNone equ 6
        eeptBinary equ 7
        tagExtendedErrorParamTypes typedef ExtendedErrorParamTypes

        MaxNumberOfEEInfoParams equ 4
        RPC_EEINFO_VERSION equ 1
        BinaryParam struct
          Buffer POINTER ?
          Size_ SWORD ?
        BinaryParam ends
        tagBinaryParam typedef BinaryParam
        RPC_EE_INFO_PARAM struct
          ParameterType ExtendedErrorParamTypes ?
          union u
            AnsiString LPSTR ?
            UnicodeString LPWSTR ?
            LVal SDWORD ?
            SVal SWORD ?
            PVal ULONGLONG ?
            BVal BinaryParam <>
          ends
        RPC_EE_INFO_PARAM ends
        tagRPC_EE_INFO_PARAM typedef RPC_EE_INFO_PARAM
        EEInfoPreviousRecordsMissing equ 1
        EEInfoNextRecordsMissing equ 2
        EEInfoUseFileTime equ 4
        EEInfoGCCOM equ 11
        if (NTDDI_VERSION ge NTDDI_WS03)
          EEInfoGCFRS equ 12
        endif
        RPC_EXTENDED_ERROR_INFO struct
          Version ULONG ?
          ComputerName LPWSTR ?
          ProcessID ULONG ?
          union u
            if  not Defined(_KRPCENV_)
              SystemTime SYSTEMTIME <>
              FileTime FILETIME <>
            else
              KernelTime LARGE_INTEGER <>
            endif
          ends
          GeneratingComponent ULONG ?
          Status ULONG ?
          DetectionLocation USHORT ?
          Flags USHORT ?
          NumberOfParameters SDWORD ?
          Parameters RPC_EE_INFO_PARAM MaxNumberOfEEInfoParams dup (<>)
        RPC_EXTENDED_ERROR_INFO ends
        tagRPC_EXTENDED_ERROR_INFO typedef RPC_EXTENDED_ERROR_INFO
        RPC_ERROR_ENUM_HANDLE struct
          Signature ULONG ?
          CurrentPos POINTER ?
          Head POINTER ?
        RPC_ERROR_ENUM_HANDLE ends
        tagRPC_ERROR_ENUM_HANDLE typedef RPC_ERROR_ENUM_HANDLE
        @DefProto DllImport, RpcErrorStartEnumeration, WIN_STD_CALL_CONV,, <:ptr RPC_ERROR_ENUM_HANDLE>, 4
        @DefProto DllImport, RpcErrorGetNextRecord, WIN_STD_CALL_CONV,, <:ptr RPC_ERROR_ENUM_HANDLE, :BOOL, :ptr RPC_EXTENDED_ERROR_INFO>, 12
        @DefProto DllImport, RpcErrorEndEnumeration, WIN_STD_CALL_CONV,, <:ptr RPC_ERROR_ENUM_HANDLE>, 4
        @DefProto DllImport, RpcErrorResetEnumeration, WIN_STD_CALL_CONV,, <:ptr RPC_ERROR_ENUM_HANDLE>, 4
        @DefProto DllImport, RpcErrorGetNumberOfRecords, WIN_STD_CALL_CONV,, <:ptr RPC_ERROR_ENUM_HANDLE, :ptr SDWORD>, 8
        @DefProto DllImport, RpcErrorSaveErrorInfo, WIN_STD_CALL_CONV,, <:ptr RPC_ERROR_ENUM_HANDLE, :ptr PVOID, :ptr size_t>, 12
        @DefProto DllImport, RpcErrorLoadErrorInfo, WIN_STD_CALL_CONV,, <:PVOID, :size_t, :ptr RPC_ERROR_ENUM_HANDLE>, 12
        @DefProto DllImport, RpcErrorAddRecord, WIN_STD_CALL_CONV,, <:ptr RPC_EXTENDED_ERROR_INFO>, 4
        @DefProto DllImport, RpcErrorClearInformation, WIN_STD_CALL_CONV,, <>, 0
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      endif
      if  not Defined(_KRPCENV_)
        @DefProto DllImport, RpcAsyncCleanupThread, WIN_STD_CALL_CONV,, <:DWORD>, 4
        @DefProto DllImport, RpcGetAuthorizationContextForClient, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :BOOL, :PVOID, :PLARGE_INTEGER, :LUID, :DWORD, :PVOID, :ptr PVOID>, 32
        @DefProto DllImport, RpcFreeAuthorizationContext, WIN_STD_CALL_CONV,, <:ptr PVOID>, 4
        @DefProto DllImport, RpcSsContextLockExclusive, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :PVOID>, 8
        @DefProto DllImport, RpcSsContextLockShared, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :PVOID>, 8
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RpcLocalAddressFormat typedef SDWORD
          rlafInvalid equ 0
          rlafIPv4 equ 1
          rlafIPv6 equ 2
          tagRpcLocalAddressFormat typedef RpcLocalAddressFormat

          RPC_CALL_LOCAL_ADDRESS_V1 struct
            Version DWORD ?
            Buffer POINTER ?
            BufferSize DWORD ?
            AddressFormat RpcLocalAddressFormat ?
          RPC_CALL_LOCAL_ADDRESS_V1 ends
          _RPC_CALL_LOCAL_ADDRESS_V1 typedef RPC_CALL_LOCAL_ADDRESS_V1
          PRPC_CALL_LOCAL_ADDRESS_V1 typedef ptr RPC_CALL_LOCAL_ADDRESS_V1
          if ((NTDDI_VERSION ge NTDDI_VISTA) and (NTDDI_VERSION lt NTDDI_WIN8))
            RPC_CALL_ATTRIBUTES_VERSION equ (2)
          endif
          RPC_QUERY_SERVER_PRINCIPAL_NAME equ (02h)
          RPC_QUERY_CLIENT_PRINCIPAL_NAME equ (04h)
          RPC_QUERY_CALL_LOCAL_ADDRESS equ (08h)
          RPC_QUERY_CLIENT_PID equ (10h)
          RPC_QUERY_IS_CLIENT_LOCAL equ (20h)
          RPC_QUERY_NO_AUTH_REQUIRED equ (40h)
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          RPC_CALL_ATTRIBUTES_VERSION equ (3)
          RPC_QUERY_CLIENT_ID equ (80h)
        endif
        if ((NTDDI_VERSION ge NTDDI_WINXP) and (NTDDI_VERSION lt NTDDI_VISTA))
          RPC_CALL_ATTRIBUTES_VERSION equ (1)
          RPC_QUERY_SERVER_PRINCIPAL_NAME equ (2)
          RPC_QUERY_CLIENT_PRINCIPAL_NAME equ (4)
        endif
        RPC_CALL_ATTRIBUTES_V1_W struct
          Version DWORD ?
          Flags DWORD ?
          ServerPrincipalNameBufferLength DWORD ?
          ServerPrincipalName POINTER ?
          ClientPrincipalNameBufferLength DWORD ?
          ClientPrincipalName POINTER ?
          AuthenticationLevel DWORD ?
          AuthenticationService DWORD ?
          NullSession BOOL ?
        RPC_CALL_ATTRIBUTES_V1_W ends
        tagRPC_CALL_ATTRIBUTES_V1_W typedef RPC_CALL_ATTRIBUTES_V1_W
        RPC_CALL_ATTRIBUTES_V1_A struct
          Version DWORD ?
          Flags DWORD ?
          ServerPrincipalNameBufferLength DWORD ?
          ServerPrincipalName POINTER ?
          ClientPrincipalNameBufferLength DWORD ?
          ClientPrincipalName POINTER ?
          AuthenticationLevel DWORD ?
          AuthenticationService DWORD ?
          NullSession BOOL ?
        RPC_CALL_ATTRIBUTES_V1_A ends
        tagRPC_CALL_ATTRIBUTES_V1_A typedef RPC_CALL_ATTRIBUTES_V1_A
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_CALL_STATUS_CANCELLED equ 01h
          RPC_CALL_STATUS_DISCONNECTED equ 02h
          RpcCallType typedef SDWORD
          rctInvalid equ 0
          rctNormal equ 1
          rctTraining equ 2
          rctGuaranteed equ 3
          tagRpcCallType typedef RpcCallType

          RpcCallClientLocality typedef SDWORD
          rcclInvalid equ 0
          rcclLocal equ 1
          rcclRemote equ 2
          rcclClientUnknownLocality equ 3
          tagRpcCallClientLocality typedef RpcCallClientLocality

          RPC_CALL_ATTRIBUTES_V2_W struct
            Version DWORD ?
            Flags DWORD ?
            ServerPrincipalNameBufferLength DWORD ?
            ServerPrincipalName POINTER ?
            ClientPrincipalNameBufferLength DWORD ?
            ClientPrincipalName POINTER ?
            AuthenticationLevel DWORD ?
            AuthenticationService DWORD ?
            NullSession BOOL ?
            KernelModeCaller BOOL ?
            ProtocolSequence DWORD ?
            IsClientLocal RpcCallClientLocality ?
            ClientPID HANDLE ?
            CallStatus DWORD ?
            CallType RpcCallType ?
            CallLocalAddress POINTER ?
            OpNum WORD ?
            InterfaceUuid UUID <>
          RPC_CALL_ATTRIBUTES_V2_W ends
          tagRPC_CALL_ATTRIBUTES_V2_W typedef RPC_CALL_ATTRIBUTES_V2_W
          RPC_CALL_ATTRIBUTES_V2_A struct
            Version DWORD ?
            Flags DWORD ?
            ServerPrincipalNameBufferLength DWORD ?
            ServerPrincipalName POINTER ?
            ClientPrincipalNameBufferLength DWORD ?
            ClientPrincipalName POINTER ?
            AuthenticationLevel DWORD ?
            AuthenticationService DWORD ?
            NullSession BOOL ?
            KernelModeCaller BOOL ?
            ProtocolSequence DWORD ?
            IsClientLocal DWORD ?
            ClientPID HANDLE ?
            CallStatus DWORD ?
            CallType RpcCallType ?
            CallLocalAddress POINTER ?
            OpNum WORD ?
            InterfaceUuid UUID <>
          RPC_CALL_ATTRIBUTES_V2_A ends
          tagRPC_CALL_ATTRIBUTES_V2_A typedef RPC_CALL_ATTRIBUTES_V2_A
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          RPC_CALL_ATTRIBUTES_V3_W struct
            Version DWORD ?
            Flags DWORD ?
            ServerPrincipalNameBufferLength DWORD ?
            ServerPrincipalName POINTER ?
            ClientPrincipalNameBufferLength DWORD ?
            ClientPrincipalName POINTER ?
            AuthenticationLevel DWORD ?
            AuthenticationService DWORD ?
            NullSession BOOL ?
            KernelModeCaller BOOL ?
            ProtocolSequence DWORD ?
            IsClientLocal RpcCallClientLocality ?
            ClientPID HANDLE ?
            CallStatus DWORD ?
            CallType RpcCallType ?
            CallLocalAddress POINTER ?
            OpNum WORD ?
            InterfaceUuid UUID <>
            ClientIdentifierBufferLength DWORD ?
            ClientIdentifier POINTER ?
          RPC_CALL_ATTRIBUTES_V3_W ends
          tagRPC_CALL_ATTRIBUTES_V3_W typedef RPC_CALL_ATTRIBUTES_V3_W
          RPC_CALL_ATTRIBUTES_V3_A struct
            Version DWORD ?
            Flags DWORD ?
            ServerPrincipalNameBufferLength DWORD ?
            ServerPrincipalName POINTER ?
            ClientPrincipalNameBufferLength DWORD ?
            ClientPrincipalName POINTER ?
            AuthenticationLevel DWORD ?
            AuthenticationService DWORD ?
            NullSession BOOL ?
            KernelModeCaller BOOL ?
            ProtocolSequence DWORD ?
            IsClientLocal DWORD ?
            ClientPID HANDLE ?
            CallStatus DWORD ?
            CallType RpcCallType ?
            CallLocalAddress POINTER ?
            OpNum WORD ?
            InterfaceUuid UUID <>
            ClientIdentifierBufferLength DWORD ?
            ClientIdentifier POINTER ?
          RPC_CALL_ATTRIBUTES_V3_A ends
          tagRPC_CALL_ATTRIBUTES_V3_A typedef RPC_CALL_ATTRIBUTES_V3_A
        endif
        @DefProto DllImport, RpcServerInqCallAttributesW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr>, 8
        @DefProto DllImport, RpcServerInqCallAttributesA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr>, 8
        ifdef UNICODE
          RPC_CALL_ATTRIBUTES_V1 equ <RPC_CALL_ATTRIBUTES_V1_W>
          if (NTDDI_VERSION ge NTDDI_VISTA)
            RPC_CALL_ATTRIBUTES_V2 equ <RPC_CALL_ATTRIBUTES_V2_W>
          endif
          if (NTDDI_VERSION ge NTDDI_WIN8)
            RPC_CALL_ATTRIBUTES_V3 equ <RPC_CALL_ATTRIBUTES_V3_W>
          endif
          RpcServerInqCallAttributes equ <RpcServerInqCallAttributesW>
        else
          RPC_CALL_ATTRIBUTES_V1 equ <RPC_CALL_ATTRIBUTES_V1_A>
          if (NTDDI_VERSION ge NTDDI_VISTA)
            RPC_CALL_ATTRIBUTES_V2 equ <RPC_CALL_ATTRIBUTES_V2_A>
          endif
          if (NTDDI_VERSION ge NTDDI_WIN8)
            RPC_CALL_ATTRIBUTES_V3 equ <RPC_CALL_ATTRIBUTES_V3_A>
          endif
          RpcServerInqCallAttributes equ <RpcServerInqCallAttributesA>
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          RPC_CALL_ATTRIBUTES typedef RPC_CALL_ATTRIBUTES_V3
        elseif (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_CALL_ATTRIBUTES typedef RPC_CALL_ATTRIBUTES_V2
        else
          RPC_CALL_ATTRIBUTES typedef RPC_CALL_ATTRIBUTES_V1
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_NOTIFICATIONS typedef SDWORD
          RpcNotificationCallNone equ 0
          RpcNotificationClientDisconnect equ 1
          RpcNotificationCallCancel equ 2
          _RPC_NOTIFICATIONS typedef RPC_NOTIFICATIONS

          RpcNotificationCallStatusChange equ <RpcNotificationClientDisconnect>
          @DefProto DllImport, RpcServerSubscribeForNotification, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_NOTIFICATIONS, :RPC_NOTIFICATION_TYPES, :ptr RPC_ASYNC_NOTIFICATION_INFO>, 16
          @DefProto DllImport, RpcServerUnsubscribeForNotification, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_NOTIFICATIONS, :ptr DWORD>, 12
        endif
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, RpcBindingBind, WIN_STD_CALL_CONV,, <:PRPC_ASYNC_STATE, :RPC_BINDING_HANDLE, :RPC_IF_HANDLE>, 12
        @DefProto DllImport, RpcBindingUnbind, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    endif
    I_RpcAsyncSetHandle proto WIN_STD_CALL_CONV :PRPC_MESSAGE, :PRPC_ASYNC_STATE
    I_RpcAsyncAbortCall proto WIN_STD_CALL_CONV :PRPC_ASYNC_STATE, :DWORD
    if (NTDDI_VERSION ge NTDDI_WINXP)
      I_RpcExceptionFilter proto WIN_STD_CALL_CONV :DWORD
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      @DefProto DllImport, I_RpcBindingInqClientTokenAttributes, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr LUID, :ptr LUID, :ptr LUID>, 16
    endif
    if _MSC_VER ge 1200
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(__RPC_WIN64__)
    include poppack.inc
  endif
endif
