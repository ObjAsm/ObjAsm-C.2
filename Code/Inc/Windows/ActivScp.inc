;Include file created by h2incX, Version C.01.00, 20/07/2019 16:29
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\ActivScp.h', last modified: 22/10/2018 21:37
;Creation parameters: 

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
endif
ifndef __activscp_h__
  __activscp_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IActiveScriptSite_FWD_DEFINED__
    __IActiveScriptSite_FWD_DEFINED__ equ <>
    ;IActiveScriptSite typedef IActiveScriptSite
    
  endif
  ifndef __IActiveScriptError_FWD_DEFINED__
    __IActiveScriptError_FWD_DEFINED__ equ <>
    ;IActiveScriptError typedef IActiveScriptError
    
  endif
  ifndef __IActiveScriptError64_FWD_DEFINED__
    __IActiveScriptError64_FWD_DEFINED__ equ <>
    ;IActiveScriptError64 typedef IActiveScriptError64
    
  endif
  ifndef __IActiveScriptSiteWindow_FWD_DEFINED__
    __IActiveScriptSiteWindow_FWD_DEFINED__ equ <>
    ;IActiveScriptSiteWindow typedef IActiveScriptSiteWindow
    
  endif
  ifndef __IActiveScriptSiteUIControl_FWD_DEFINED__
    __IActiveScriptSiteUIControl_FWD_DEFINED__ equ <>
    ;IActiveScriptSiteUIControl typedef IActiveScriptSiteUIControl
    
  endif
  ifndef __IActiveScriptSiteInterruptPoll_FWD_DEFINED__
    __IActiveScriptSiteInterruptPoll_FWD_DEFINED__ equ <>
    ;IActiveScriptSiteInterruptPoll typedef IActiveScriptSiteInterruptPoll
    
  endif
  ifndef __IActiveScript_FWD_DEFINED__
    __IActiveScript_FWD_DEFINED__ equ <>
    ;IActiveScript typedef IActiveScript
    
  endif
  ifndef __IActiveScriptParse32_FWD_DEFINED__
    __IActiveScriptParse32_FWD_DEFINED__ equ <>
    ;IActiveScriptParse32 typedef IActiveScriptParse32
    
  endif
  ifndef __IActiveScriptParse64_FWD_DEFINED__
    __IActiveScriptParse64_FWD_DEFINED__ equ <>
    ;IActiveScriptParse64 typedef IActiveScriptParse64
    
  endif
  ifndef __IActiveScriptParseProcedureOld32_FWD_DEFINED__
    __IActiveScriptParseProcedureOld32_FWD_DEFINED__ equ <>
    ;IActiveScriptParseProcedureOld32 typedef IActiveScriptParseProcedureOld32
    
  endif
  ifndef __IActiveScriptParseProcedureOld64_FWD_DEFINED__
    __IActiveScriptParseProcedureOld64_FWD_DEFINED__ equ <>
    ;IActiveScriptParseProcedureOld64 typedef IActiveScriptParseProcedureOld64
    
  endif
  ifndef __IActiveScriptParseProcedure32_FWD_DEFINED__
    __IActiveScriptParseProcedure32_FWD_DEFINED__ equ <>
    ;IActiveScriptParseProcedure32 typedef IActiveScriptParseProcedure32
    
  endif
  ifndef __IActiveScriptParseProcedure64_FWD_DEFINED__
    __IActiveScriptParseProcedure64_FWD_DEFINED__ equ <>
    ;IActiveScriptParseProcedure64 typedef IActiveScriptParseProcedure64
    
  endif
  ifndef __IActiveScriptParseProcedure2_32_FWD_DEFINED__
    __IActiveScriptParseProcedure2_32_FWD_DEFINED__ equ <>
    ;IActiveScriptParseProcedure2_32 typedef IActiveScriptParseProcedure2_32
    
  endif
  ifndef __IActiveScriptParseProcedure2_64_FWD_DEFINED__
    __IActiveScriptParseProcedure2_64_FWD_DEFINED__ equ <>
    ;IActiveScriptParseProcedure2_64 typedef IActiveScriptParseProcedure2_64
    
  endif
  ifndef __IActiveScriptEncode_FWD_DEFINED__
    __IActiveScriptEncode_FWD_DEFINED__ equ <>
    ;IActiveScriptEncode typedef IActiveScriptEncode
    
  endif
  ifndef __IActiveScriptHostEncode_FWD_DEFINED__
    __IActiveScriptHostEncode_FWD_DEFINED__ equ <>
    ;IActiveScriptHostEncode typedef IActiveScriptHostEncode
    
  endif
  ifndef __IBindEventHandler_FWD_DEFINED__
    __IBindEventHandler_FWD_DEFINED__ equ <>
    ;IBindEventHandler typedef IBindEventHandler
    
  endif
  ifndef __IActiveScriptStats_FWD_DEFINED__
    __IActiveScriptStats_FWD_DEFINED__ equ <>
    ;IActiveScriptStats typedef IActiveScriptStats
    
  endif
  ifndef __IActiveScriptProperty_FWD_DEFINED__
    __IActiveScriptProperty_FWD_DEFINED__ equ <>
    ;IActiveScriptProperty typedef IActiveScriptProperty
    
  endif
  ifndef __ITridentEventSink_FWD_DEFINED__
    __ITridentEventSink_FWD_DEFINED__ equ <>
    ;ITridentEventSink typedef ITridentEventSink
    
  endif
  ifndef __IActiveScriptGarbageCollector_FWD_DEFINED__
    __IActiveScriptGarbageCollector_FWD_DEFINED__ equ <>
    ;IActiveScriptGarbageCollector typedef IActiveScriptGarbageCollector
    
  endif
  ifndef __IActiveScriptSIPInfo_FWD_DEFINED__
    __IActiveScriptSIPInfo_FWD_DEFINED__ equ <>
    ;IActiveScriptSIPInfo typedef IActiveScriptSIPInfo
    
  endif
  ifndef __IActiveScriptSiteTraceInfo_FWD_DEFINED__
    __IActiveScriptSiteTraceInfo_FWD_DEFINED__ equ <>
    ;IActiveScriptSiteTraceInfo typedef IActiveScriptSiteTraceInfo
    
  endif
  ifndef __IActiveScriptTraceInfo_FWD_DEFINED__
    __IActiveScriptTraceInfo_FWD_DEFINED__ equ <>
    ;IActiveScriptTraceInfo typedef IActiveScriptTraceInfo
    
  endif
  ifndef __IActiveScriptStringCompare_FWD_DEFINED__
    __IActiveScriptStringCompare_FWD_DEFINED__ equ <>
    ;IActiveScriptStringCompare typedef IActiveScriptStringCompare
    
  endif
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef __ActivScp_h
    __ActivScp_h equ <>
    include winapifamily.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef _NO_SCRIPT_GUIDS
        DEFINE_GUID CATID_ActiveScript, 0f0b7a1a1h, 9847h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID CATID_ActiveScriptParse, 0f0b7a1a2h, 9847h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID CATID_ActiveScriptEncode, 0f0b7a1a3h, 9847h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScript, 0bb1a2ae1h, 0a4f9h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScriptParse32, 0bb1a2ae2h, 0a4f9h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScriptParse64, 0c7ef7658h, 0e1eeh, 480eh, 97h, 0eah, 0d5h, 2ch, 0b4h, 0d7h, 6dh, 17h
        DEFINE_GUID IID_IActiveScriptEncode, 0bb1a2ae3h, 0a4f9h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScriptHostEncode, 0bee9b76eh, 0cfe3h, 11d1h, 0b7h, 47h, 00h, 0c0h, 4fh, 0c2h, 0b0h, 85h
        DEFINE_GUID IID_IActiveScriptParseProcedureOld32, 1cff0050h, 6fddh, 11d0h, 93h, 28h, 00h, 0a0h, 0c9h, 0dh, 0cah, 0a9h
        DEFINE_GUID IID_IActiveScriptParseProcedureOld64, 21f57128h, 08c9h, 4638h, 0bah, 12h, 22h, 0d1h, 5dh, 88h, 0dch, 5ch
        DEFINE_GUID IID_IActiveScriptParseProcedure32, 0aa5b6a80h, 0b834h, 11d0h, 93h, 2fh, 00h, 0a0h, 0c9h, 0dh, 0cah, 0a9h
        DEFINE_GUID IID_IActiveScriptParseProcedure64, 0c64713b6h, 0e029h, 4cc5h, 92h, 00h, 43h, 8bh, 72h, 89h, 0bh, 6ah
        DEFINE_GUID IID_IActiveScriptParseProcedure2_32, 71ee5b20h, 0fb04h, 11d1h, 0b3h, 0a8h, 00h, 0a0h, 0c9h, 11h, 0e8h, 0b2h
        DEFINE_GUID IID_IActiveScriptParseProcedure2_64, 0fe7c4271h, 210ch, 448dh, 9fh, 54h, 76h, 0dah, 0b7h, 04h, 7bh, 28h
        DEFINE_GUID IID_IActiveScriptSite, 0db01a1e3h, 0a42bh, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScriptSiteTraceInfo, 4b7272aeh, 1955h, 4bfeh, 98h, 0b0h, 78h, 6h, 21h, 88h, 85h, 69h
        DEFINE_GUID IID_IActiveScriptSiteWindow, 0d10f6761h, 83e9h, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScriptSiteInterruptPoll, 539698a0h, 0cdcah, 11cfh, 0a5h, 0ebh, 00h, 0aah, 00h, 47h, 0a0h, 63h
        DEFINE_GUID IID_IActiveScriptSiteUIControl, 0aedae97eh, 0d7eeh, 4796h, 0b9h, 60h, 7fh, 9h, 2ah, 0e8h, 44h, 0abh
        DEFINE_GUID IID_IActiveScriptError, 0eae1ba61h, 0a4edh, 11cfh, 8fh, 20h, 00h, 80h, 5fh, 2ch, 0d0h, 64h
        DEFINE_GUID IID_IActiveScriptError64, 0b21fb2a1h, 5b8fh, 4963h, 8ch, 21h, 21h, 45h, 0fh, 84h, 0edh, 7fh
        DEFINE_GUID IID_IBindEventHandler, 63cdbcb0h, 0c1b1h, 11d0h, 93h, 36h, 00h, 0a0h, 0c9h, 0dh, 0cah, 0a9h
        DEFINE_GUID IID_IActiveScriptStats, 0b8da6310h, 0e19bh, 11d0h, 93h, 3ch, 00h, 0a0h, 0c9h, 0dh, 0cah, 0a9h
        DEFINE_GUID IID_IActiveScriptProperty, 4954E0D0h, 0FBC7h, 11D1h, 84h, 10h, 00h, 60h, 08h, 0C3h, 0FBh, 0FCh
        DEFINE_GUID IID_ITridentEventSink, 1dc9ca50h, 6efh, 11d2h, 84h, 15h, 00h, 60h, 08h, 0c3h, 0fbh, 0fch
        DEFINE_GUID IID_IActiveScriptGarbageCollector, 6aa2c4a0h, 2b53h, 11d4h, 0a2h, 0a0h, 00h, 10h, 4bh, 0d3h, 50h, 90h
        DEFINE_GUID IID_IActiveScriptSIPInfo, 764651d0h, 38deh, 11d4h, 0a2h, 0a3h, 00h, 10h, 4bh, 0d3h, 50h, 90h
        DEFINE_GUID IID_IActiveScriptTraceInfo, 0C35456E7h, 0BEBFh, 4a1bh, 86h, 0A9h, 24h, 0D5h, 6Bh, 0E8h, 0B3h, 69h
        DEFINE_GUID OID_VBSSIP, 1629f04eh, 2799h, 4db5h, 8fh, 0e5h, 0ach, 0e1h, 0fh, 17h, 0ebh, 0abh
        DEFINE_GUID OID_JSSIP, 6c9e010h, 38ceh, 11d4h, 0a2h, 0a3h, 00h, 10h, 4bh, 0d3h, 50h, 90h
        DEFINE_GUID OID_WSFSIP, 1a610570h, 38ceh, 11d4h, 0a2h, 0a3h, 00h, 10h, 4bh, 0d3h, 50h, 90h
        DEFINE_GUID IID_IActiveScriptStringCompare, 58562769h, 0ED52h, 42f7h, 84h, 03h, 49h, 63h, 51h, 4Eh, 1Fh, 11h
      endif
      SCRIPTITEM_ISVISIBLE equ 00000002h
      SCRIPTITEM_ISSOURCE equ 00000004h
      SCRIPTITEM_GLOBALMEMBERS equ 00000008h
      SCRIPTITEM_ISPERSISTENT equ 00000040h
      SCRIPTITEM_CODEONLY equ 00000200h
      SCRIPTITEM_NOCODE equ 00000400h
      SCRIPTITEM_ALL_FLAGS equ <(SCRIPTITEM_ISSOURCE or SCRIPTITEM_ISVISIBLE or SCRIPTITEM_ISPERSISTENT or SCRIPTITEM_GLOBALMEMBERS or SCRIPTITEM_NOCODE or SCRIPTITEM_CODEONLY)>
      SCRIPTTYPELIB_ISCONTROL equ 00000010h
      SCRIPTTYPELIB_ISPERSISTENT equ 00000040h
      SCRIPTTYPELIB_ALL_FLAGS equ <(SCRIPTTYPELIB_ISCONTROL or SCRIPTTYPELIB_ISPERSISTENT)>
      SCRIPTTEXT_DELAYEXECUTION equ 00000001h
      SCRIPTTEXT_ISVISIBLE equ 00000002h
      SCRIPTTEXT_ISEXPRESSION equ 00000020h
      SCRIPTTEXT_ISPERSISTENT equ 00000040h
      SCRIPTTEXT_HOSTMANAGESSOURCE equ 00000080h
      SCRIPTTEXT_ISXDOMAIN equ 00000100h
      SCRIPTTEXT_ISNONUSERCODE equ 00000200h
      SCRIPTTEXT_ALL_FLAGS equ <(SCRIPTTEXT_DELAYEXECUTION or SCRIPTTEXT_ISVISIBLE or SCRIPTTEXT_ISEXPRESSION or SCRIPTTEXT_ISPERSISTENT or SCRIPTTEXT_HOSTMANAGESSOURCE or SCRIPTTEXT_ISXDOMAIN or SCRIPTTEXT_ISNONUSERCODE)>
      SCRIPTPROC_ISEXPRESSION equ 00000020h
      SCRIPTPROC_HOSTMANAGESSOURCE equ 00000080h
      SCRIPTPROC_IMPLICIT_THIS equ 00000100h
      SCRIPTPROC_IMPLICIT_PARENTS equ 00000200h
      SCRIPTPROC_ISXDOMAIN equ 00000400h
      SCRIPTPROC_ALL_FLAGS equ <(SCRIPTPROC_HOSTMANAGESSOURCE or SCRIPTPROC_ISEXPRESSION or SCRIPTPROC_IMPLICIT_THIS or SCRIPTPROC_IMPLICIT_PARENTS or SCRIPTPROC_ISXDOMAIN)>
      SCRIPTINFO_IUNKNOWN equ 00000001h
      SCRIPTINFO_ITYPEINFO equ 00000002h
      SCRIPTINFO_ALL_FLAGS equ <(SCRIPTINFO_IUNKNOWN or SCRIPTINFO_ITYPEINFO)>
      SCRIPTINTERRUPT_DEBUG equ 00000001h
      SCRIPTINTERRUPT_RAISEEXCEPTION equ 00000002h
      SCRIPTINTERRUPT_ALL_FLAGS equ <(SCRIPTINTERRUPT_DEBUG or SCRIPTINTERRUPT_RAISEEXCEPTION)>
      SCRIPTSTAT_STATEMENT_COUNT equ 1
      SCRIPTSTAT_INSTRUCTION_COUNT equ 2
      SCRIPTSTAT_INTSTRUCTION_TIME equ 3
      SCRIPTSTAT_TOTAL_TIME equ 4
      SCRIPT_ENCODE_SECTION equ 00000001h
      SCRIPT_ENCODE_DEFAULT_LANGUAGE equ 00000001h
      SCRIPT_ENCODE_NO_ASP_LANGUAGE equ 00000002h
      SCRIPTPROP_NAME equ 00000000h
      SCRIPTPROP_MAJORVERSION equ 00000001h
      SCRIPTPROP_MINORVERSION equ 00000002h
      SCRIPTPROP_BUILDNUMBER equ 00000003h
      SCRIPTPROP_DELAYEDEVENTSINKING equ 00001000h
      SCRIPTPROP_CATCHEXCEPTION equ 00001001h
      SCRIPTPROP_CONVERSIONLCID equ 00001002h
      SCRIPTPROP_HOSTSTACKREQUIRED equ 00001003h
      SCRIPTPROP_SCRIPTSAREFULLYTRUSTED equ 00001004h
      SCRIPTPROP_DEBUGGER equ 00001100h
      SCRIPTPROP_JITDEBUG equ 00001101h
      SCRIPTPROP_GCCONTROLSOFTCLOSE equ 00002000h
      SCRIPTPROP_INTEGERMODE equ 00003000h
      SCRIPTPROP_STRINGCOMPAREINSTANCE equ 00003001h
      SCRIPTPROP_INVOKEVERSIONING equ 00004000h
      SCRIPTPROP_HACK_FIBERSUPPORT equ 70000000h
      SCRIPTPROP_HACK_TRIDENTEVENTSINK equ 70000001h
      SCRIPTPROP_ABBREVIATE_GLOBALNAME_RESOLUTION equ 70000002h
      SCRIPTPROP_HOSTKEEPALIVE equ 70000004h
      SCRIPT_E_RECORDED equ 86664004h
      SCRIPT_E_REPORTED equ 80020101h
      SCRIPT_E_PROPAGATE equ 80020102h
      SCRIPTLANGUAGEVERSION typedef SDWORD
      SCRIPTLANGUAGEVERSION_DEFAULT equ 0
      SCRIPTLANGUAGEVERSION_5_7 equ 1
      SCRIPTLANGUAGEVERSION_5_8 equ 2
      SCRIPTLANGUAGEVERSION_MAX equ 255
      tagSCRIPTLANGUAGEVERSION typedef SCRIPTLANGUAGEVERSION
      
      SCRIPTSTATE typedef SDWORD
      SCRIPTSTATE_UNINITIALIZED equ 0
      SCRIPTSTATE_INITIALIZED equ 5
      SCRIPTSTATE_STARTED equ 1
      SCRIPTSTATE_CONNECTED equ 2
      SCRIPTSTATE_DISCONNECTED equ 3
      SCRIPTSTATE_CLOSED equ 4
      tagSCRIPTSTATE typedef SCRIPTSTATE
      
      SCRIPTTRACEINFO typedef SDWORD
      SCRIPTTRACEINFO_SCRIPTSTART equ 0
      SCRIPTTRACEINFO_SCRIPTEND equ 1
      SCRIPTTRACEINFO_COMCALLSTART equ 2
      SCRIPTTRACEINFO_COMCALLEND equ 3
      SCRIPTTRACEINFO_CREATEOBJSTART equ 4
      SCRIPTTRACEINFO_CREATEOBJEND equ 5
      SCRIPTTRACEINFO_GETOBJSTART equ 6
      SCRIPTTRACEINFO_GETOBJEND equ 7
      tagSCRIPTTRACEINFO typedef SCRIPTTRACEINFO
      
      SCRIPTTHREADSTATE typedef SDWORD
      SCRIPTTHREADSTATE_NOTINSCRIPT equ 0
      SCRIPTTHREADSTATE_RUNNING equ 1
      tagSCRIPTTHREADSTATE typedef SCRIPTTHREADSTATE
      
      SCRIPTGCTYPE typedef SDWORD
      SCRIPTGCTYPE_NORMAL equ 0
      SCRIPTGCTYPE_EXHAUSTIVE equ 1
      tagSCRIPTGCTYPE typedef SCRIPTGCTYPE
      
      SCRIPTUICITEM typedef SDWORD
      SCRIPTUICITEM_INPUTBOX equ 1
      SCRIPTUICITEM_MSGBOX equ 2
      tagSCRIPTUICITEM typedef SCRIPTUICITEM
      
      SCRIPTUICHANDLING typedef SDWORD
      SCRIPTUICHANDLING_ALLOW equ 0
      SCRIPTUICHANDLING_NOUIERROR equ 1
      SCRIPTUICHANDLING_NOUIDEFAULT equ 2
      tagSCRIPTUICHANDLING typedef SCRIPTUICHANDLING
      
      SCRIPTTHREADID typedef DWORD
      SCRIPTTHREADID_CURRENT equ ((SCRIPTTHREADID) - 1)
      SCRIPTTHREADID_BASE equ ((SCRIPTTHREADID) - 2)
      SCRIPTTHREADID_ALL equ ((SCRIPTTHREADID) - 3)
      externdef __MIDL_itf_activscp_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activscp_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptSite_INTERFACE_DEFINED__
        __IActiveScriptSite_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptSite, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptSite
            STD_METHOD Release, :ptr IActiveScriptSite
            STD_METHOD GetLCID, :ptr IActiveScriptSite, :ptr LCID
            STD_METHOD GetItemInfo, :ptr IActiveScriptSite, :LPCOLESTR, :DWORD, :ptr ptr IUnknown, :ptr ptr ITypeInfo
            STD_METHOD GetDocVersionString, :ptr IActiveScriptSite, :ptr BSTR
            STD_METHOD OnScriptTerminate, :ptr IActiveScriptSite, :ptr VARIANT, :ptr EXCEPINFO
            STD_METHOD OnStateChange, :ptr IActiveScriptSite, :SCRIPTSTATE
            STD_METHOD OnScriptError, :ptr IActiveScriptSite, :ptr IActiveScriptError
            STD_METHOD OnEnterScript, :ptr IActiveScriptSite
            STD_METHOD OnLeaveScript, :ptr IActiveScriptSite
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteVtbl ends

          IActiveScriptSite struct
            lpVtbl POINTER ?
          IActiveScriptSite ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptError_INTERFACE_DEFINED__
        __IActiveScriptError_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptError:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptErrorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptErrorVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptError, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptError
            STD_METHOD Release, :ptr IActiveScriptError
            STD_METHOD GetExceptionInfo, :ptr IActiveScriptError, :ptr EXCEPINFO
            STD_METHOD GetSourcePosition, :ptr IActiveScriptError, :ptr DWORD, :ptr ULONG, :ptr LONG
            STD_METHOD GetSourceLineText, :ptr IActiveScriptError, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptErrorVtbl ends

          IActiveScriptError struct
            lpVtbl POINTER ?
          IActiveScriptError ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IActiveScriptError_RemoteGetExceptionInfo_Proxy proto WIN_STD_CALL_CONV :ptr IActiveScriptError, :ptr EXCEPINFO
        IActiveScriptError_RemoteGetExceptionInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IActiveScriptError64_INTERFACE_DEFINED__
        __IActiveScriptError64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptError64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptError64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptError64Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptError64, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptError64
            STD_METHOD Release, :ptr IActiveScriptError64
            STD_METHOD GetExceptionInfo, :ptr IActiveScriptError64, :ptr EXCEPINFO
            STD_METHOD GetSourcePosition, :ptr IActiveScriptError64, :ptr DWORD, :ptr ULONG, :ptr LONG
            STD_METHOD GetSourceLineText, :ptr IActiveScriptError64, :ptr BSTR
            STD_METHOD GetSourcePosition64, :ptr IActiveScriptError64, :ptr DWORDLONG, :ptr ULONG, :ptr LONG
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptError64Vtbl ends

          IActiveScriptError64 struct
            lpVtbl POINTER ?
          IActiveScriptError64 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSiteWindow_INTERFACE_DEFINED__
        __IActiveScriptSiteWindow_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteWindow:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteWindowVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteWindowVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteWindow, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptSiteWindow
            STD_METHOD Release, :ptr IActiveScriptSiteWindow
            STD_METHOD GetWindow, :ptr IActiveScriptSiteWindow, :ptr HWND
            STD_METHOD EnableModeless, :ptr IActiveScriptSiteWindow, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteWindowVtbl ends

          IActiveScriptSiteWindow struct
            lpVtbl POINTER ?
          IActiveScriptSiteWindow ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSiteUIControl_INTERFACE_DEFINED__
        __IActiveScriptSiteUIControl_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteUIControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteUIControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteUIControlVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteUIControl, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptSiteUIControl
            STD_METHOD Release, :ptr IActiveScriptSiteUIControl
            STD_METHOD GetUIBehavior, :ptr IActiveScriptSiteUIControl, :SCRIPTUICITEM, :ptr SCRIPTUICHANDLING
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteUIControlVtbl ends

          IActiveScriptSiteUIControl struct
            lpVtbl POINTER ?
          IActiveScriptSiteUIControl ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED__
        __IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteInterruptPoll:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteInterruptPollVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteInterruptPollVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteInterruptPoll, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptSiteInterruptPoll
            STD_METHOD Release, :ptr IActiveScriptSiteInterruptPoll
            STD_METHOD QueryContinue, :ptr IActiveScriptSiteInterruptPoll
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteInterruptPollVtbl ends

          IActiveScriptSiteInterruptPoll struct
            lpVtbl POINTER ?
          IActiveScriptSiteInterruptPoll ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScript_INTERFACE_DEFINED__
        __IActiveScript_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScript:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScript, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScript
            STD_METHOD Release, :ptr IActiveScript
            STD_METHOD SetScriptSite, :ptr IActiveScript, :ptr IActiveScriptSite
            STD_METHOD GetScriptSite, :ptr IActiveScript, :REFIID, :ptr ptr
            STD_METHOD SetScriptState, :ptr IActiveScript, :SCRIPTSTATE
            STD_METHOD GetScriptState, :ptr IActiveScript, :ptr SCRIPTSTATE
            STD_METHOD Close, :ptr IActiveScript
            STD_METHOD AddNamedItem, :ptr IActiveScript, :LPCOLESTR, :DWORD
            STD_METHOD AddTypeLib, :ptr IActiveScript, :REFGUID, :DWORD, :DWORD, :DWORD
            STD_METHOD GetScriptDispatch, :ptr IActiveScript, :LPCOLESTR, :ptr ptr IDispatch
            STD_METHOD GetCurrentScriptThreadID, :ptr IActiveScript, :ptr SCRIPTTHREADID
            STD_METHOD GetScriptThreadID, :ptr IActiveScript, :DWORD, :ptr SCRIPTTHREADID
            STD_METHOD GetScriptThreadState, :ptr IActiveScript, :SCRIPTTHREADID, :ptr SCRIPTTHREADSTATE
            STD_METHOD InterruptScriptThread, :ptr IActiveScript, :SCRIPTTHREADID, :ptr EXCEPINFO, :DWORD
            STD_METHOD Clone, :ptr IActiveScript, :ptr ptr IActiveScript
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptVtbl ends

          IActiveScript struct
            lpVtbl POINTER ?
          IActiveScript ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptParse32_INTERFACE_DEFINED__
        __IActiveScriptParse32_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParse32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParse32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParse32Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParse32, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParse32
            STD_METHOD Release, :ptr IActiveScriptParse32
            STD_METHOD InitNew, :ptr IActiveScriptParse32
            STD_METHOD AddScriptlet, :ptr IActiveScriptParse32, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :DWORD, :ULONG, :DWORD, :ptr BSTR, :ptr EXCEPINFO
            STD_METHOD ParseScriptText, :ptr IActiveScriptParse32, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORD, :ULONG, :DWORD, :ptr VARIANT, :ptr EXCEPINFO
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParse32Vtbl ends

          IActiveScriptParse32 struct
            lpVtbl POINTER ?
          IActiveScriptParse32 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptParse64_INTERFACE_DEFINED__
        __IActiveScriptParse64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParse64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParse64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParse64Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParse64, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParse64
            STD_METHOD Release, :ptr IActiveScriptParse64
            STD_METHOD InitNew, :ptr IActiveScriptParse64
            STD_METHOD AddScriptlet, :ptr IActiveScriptParse64, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :DWORDLONG, :ULONG, :DWORD, :ptr BSTR, :ptr EXCEPINFO
            STD_METHOD ParseScriptText, :ptr IActiveScriptParse64, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORDLONG, :ULONG, :DWORD, :ptr VARIANT, :ptr EXCEPINFO
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParse64Vtbl ends

          IActiveScriptParse64 struct
            lpVtbl POINTER ?
          IActiveScriptParse64 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifdef _WIN64
        IActiveScriptParse equ <IActiveScriptParse64>
        IID_IActiveScriptParse equ <IID_IActiveScriptParse64>
      else
        IActiveScriptParse equ <IActiveScriptParse32>
        IID_IActiveScriptParse equ <IID_IActiveScriptParse32>
      endif
      PIActiveScriptParse typedef ptr IActiveScriptParse
      externdef __MIDL_itf_activscp_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activscp_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptParseProcedureOld32_INTERFACE_DEFINED__
        __IActiveScriptParseProcedureOld32_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParseProcedureOld32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParseProcedureOld32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParseProcedureOld32Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParseProcedureOld32, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParseProcedureOld32
            STD_METHOD Release, :ptr IActiveScriptParseProcedureOld32
            STD_METHOD ParseProcedureText, :ptr IActiveScriptParseProcedureOld32, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORD, :ULONG, :DWORD, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParseProcedureOld32Vtbl ends

          IActiveScriptParseProcedureOld32 struct
            lpVtbl POINTER ?
          IActiveScriptParseProcedureOld32 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptParseProcedureOld64_INTERFACE_DEFINED__
        __IActiveScriptParseProcedureOld64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParseProcedureOld64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParseProcedureOld64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParseProcedureOld64Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParseProcedureOld64, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParseProcedureOld64
            STD_METHOD Release, :ptr IActiveScriptParseProcedureOld64
            STD_METHOD ParseProcedureText, :ptr IActiveScriptParseProcedureOld64, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORDLONG, :ULONG, :DWORD, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParseProcedureOld64Vtbl ends

          IActiveScriptParseProcedureOld64 struct
            lpVtbl POINTER ?
          IActiveScriptParseProcedureOld64 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifdef _WIN64
        IActiveScriptParseProcedureOld equ <IActiveScriptParseProcedureOld64>
        IID_IActiveScriptParseProcedureOld equ <IID_IActiveScriptParseProcedureOld64>
      else
        IActiveScriptParseProcedureOld equ <IActiveScriptParseProcedureOld32>
        IID_IActiveScriptParseProcedureOld equ <IID_IActiveScriptParseProcedureOld32>
      endif
      PIActiveScriptParseProcedureOld typedef ptr IActiveScriptParseProcedureOld
      externdef __MIDL_itf_activscp_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activscp_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptParseProcedure32_INTERFACE_DEFINED__
        __IActiveScriptParseProcedure32_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParseProcedure32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParseProcedure32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParseProcedure32Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParseProcedure32, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParseProcedure32
            STD_METHOD Release, :ptr IActiveScriptParseProcedure32
            STD_METHOD ParseProcedureText, :ptr IActiveScriptParseProcedure32, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORD, :ULONG, :DWORD, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParseProcedure32Vtbl ends

          IActiveScriptParseProcedure32 struct
            lpVtbl POINTER ?
          IActiveScriptParseProcedure32 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptParseProcedure64_INTERFACE_DEFINED__
        __IActiveScriptParseProcedure64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParseProcedure64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParseProcedure64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParseProcedure64Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParseProcedure64, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParseProcedure64
            STD_METHOD Release, :ptr IActiveScriptParseProcedure64
            STD_METHOD ParseProcedureText, :ptr IActiveScriptParseProcedure64, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORDLONG, :ULONG, :DWORD, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParseProcedure64Vtbl ends

          IActiveScriptParseProcedure64 struct
            lpVtbl POINTER ?
          IActiveScriptParseProcedure64 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifdef _WIN64
        IActiveScriptParseProcedure equ <IActiveScriptParseProcedure64>
        IID_IActiveScriptParseProcedure equ <IID_IActiveScriptParseProcedure64>
      else
        IActiveScriptParseProcedure equ <IActiveScriptParseProcedure32>
        IID_IActiveScriptParseProcedure equ <IID_IActiveScriptParseProcedure32>
      endif
      PIActiveScriptParseProcedure typedef ptr IActiveScriptParseProcedure
      externdef __MIDL_itf_activscp_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activscp_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptParseProcedure2_32_INTERFACE_DEFINED__
        __IActiveScriptParseProcedure2_32_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParseProcedure2_32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParseProcedure2_32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParseProcedure2_32Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParseProcedure2_32, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParseProcedure2_32
            STD_METHOD Release, :ptr IActiveScriptParseProcedure2_32
            STD_METHOD ParseProcedureText, :ptr IActiveScriptParseProcedure2_32, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORD, :ULONG, :DWORD, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParseProcedure2_32Vtbl ends

          IActiveScriptParseProcedure2_32 struct
            lpVtbl POINTER ?
          IActiveScriptParseProcedure2_32 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptParseProcedure2_64_INTERFACE_DEFINED__
        __IActiveScriptParseProcedure2_64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptParseProcedure2_64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptParseProcedure2_64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptParseProcedure2_64Vtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptParseProcedure2_64, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptParseProcedure2_64
            STD_METHOD Release, :ptr IActiveScriptParseProcedure2_64
            STD_METHOD ParseProcedureText, :ptr IActiveScriptParseProcedure2_64, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :LPCOLESTR, :ptr IUnknown, :LPCOLESTR, :DWORDLONG, :ULONG, :DWORD, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptParseProcedure2_64Vtbl ends

          IActiveScriptParseProcedure2_64 struct
            lpVtbl POINTER ?
          IActiveScriptParseProcedure2_64 ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifdef _WIN64
        IActiveScriptParseProcedure2 equ <IActiveScriptParseProcedure2_64>
        IID_IActiveScriptParseProcedure2 equ <IID_IActiveScriptParseProcedure2_64>
      else
        IActiveScriptParseProcedure2 equ <IActiveScriptParseProcedure2_32>
        IID_IActiveScriptParseProcedure2 equ <IID_IActiveScriptParseProcedure2_32>
      endif
      PIActiveScriptParseProcedure2 typedef ptr IActiveScriptParseProcedure2
      externdef __MIDL_itf_activscp_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activscp_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptEncode_INTERFACE_DEFINED__
        __IActiveScriptEncode_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptEncode:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptEncodeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptEncodeVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptEncode, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptEncode
            STD_METHOD Release, :ptr IActiveScriptEncode
            STD_METHOD EncodeSection, :ptr IActiveScriptEncode, :LPCOLESTR, :DWORD, :LPOLESTR, :DWORD, :ptr DWORD
            STD_METHOD DecodeScript, :ptr IActiveScriptEncode, :LPCOLESTR, :DWORD, :LPOLESTR, :DWORD, :ptr DWORD
            STD_METHOD GetEncodeProgId, :ptr IActiveScriptEncode, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptEncodeVtbl ends

          IActiveScriptEncode struct
            lpVtbl POINTER ?
          IActiveScriptEncode ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptHostEncode_INTERFACE_DEFINED__
        __IActiveScriptHostEncode_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptHostEncode:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptHostEncodeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptHostEncodeVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptHostEncode, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptHostEncode
            STD_METHOD Release, :ptr IActiveScriptHostEncode
            STD_METHOD EncodeScriptHostFile, :ptr IActiveScriptHostEncode, :BSTR, :ptr BSTR, :DWORD, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptHostEncodeVtbl ends

          IActiveScriptHostEncode struct
            lpVtbl POINTER ?
          IActiveScriptHostEncode ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IBindEventHandler_INTERFACE_DEFINED__
        __IBindEventHandler_INTERFACE_DEFINED__ equ <>
        externdef IID_IBindEventHandler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindEventHandlerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindEventHandlerVtbl>
            STD_METHOD QueryInterface, :ptr IBindEventHandler, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IBindEventHandler
            STD_METHOD Release, :ptr IBindEventHandler
            STD_METHOD BindHandler, :ptr IBindEventHandler, :LPCOLESTR, :ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IBindEventHandlerVtbl ends

          IBindEventHandler struct
            lpVtbl POINTER ?
          IBindEventHandler ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptStats_INTERFACE_DEFINED__
        __IActiveScriptStats_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptStats:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptStatsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptStatsVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptStats, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptStats
            STD_METHOD Release, :ptr IActiveScriptStats
            STD_METHOD GetStat, :ptr IActiveScriptStats, :DWORD, :ptr ULONG, :ptr ULONG
            STD_METHOD GetStatEx, :ptr IActiveScriptStats, :REFGUID, :ptr ULONG, :ptr ULONG
            STD_METHOD ResetStats, :ptr IActiveScriptStats
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptStatsVtbl ends

          IActiveScriptStats struct
            lpVtbl POINTER ?
          IActiveScriptStats ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptProperty_INTERFACE_DEFINED__
        __IActiveScriptProperty_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptProperty:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptPropertyVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptPropertyVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptProperty, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptProperty
            STD_METHOD Release, :ptr IActiveScriptProperty
            STD_METHOD GetProperty, :ptr IActiveScriptProperty, :DWORD, :ptr VARIANT, :ptr VARIANT
            STD_METHOD SetProperty, :ptr IActiveScriptProperty, :DWORD, :ptr VARIANT, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptPropertyVtbl ends

          IActiveScriptProperty struct
            lpVtbl POINTER ?
          IActiveScriptProperty ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ITridentEventSink_INTERFACE_DEFINED__
        __ITridentEventSink_INTERFACE_DEFINED__ equ <>
        externdef IID_ITridentEventSink:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ITridentEventSinkVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ITridentEventSinkVtbl>
            STD_METHOD QueryInterface, :ptr ITridentEventSink, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ITridentEventSink
            STD_METHOD Release, :ptr ITridentEventSink
            STD_METHOD FireEvent, :ptr ITridentEventSink, :LPCOLESTR, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO
            ??Interface equ <>
            END_INTERFACE
          ITridentEventSinkVtbl ends

          ITridentEventSink struct
            lpVtbl POINTER ?
          ITridentEventSink ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptGarbageCollector_INTERFACE_DEFINED__
        __IActiveScriptGarbageCollector_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptGarbageCollector:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptGarbageCollectorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptGarbageCollectorVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptGarbageCollector, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptGarbageCollector
            STD_METHOD Release, :ptr IActiveScriptGarbageCollector
            STD_METHOD CollectGarbage, :ptr IActiveScriptGarbageCollector, :SCRIPTGCTYPE
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptGarbageCollectorVtbl ends

          IActiveScriptGarbageCollector struct
            lpVtbl POINTER ?
          IActiveScriptGarbageCollector ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSIPInfo_INTERFACE_DEFINED__
        __IActiveScriptSIPInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSIPInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSIPInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSIPInfoVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptSIPInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptSIPInfo
            STD_METHOD Release, :ptr IActiveScriptSIPInfo
            STD_METHOD GetSIPOID, :ptr IActiveScriptSIPInfo, :ptr GUID
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSIPInfoVtbl ends

          IActiveScriptSIPInfo struct
            lpVtbl POINTER ?
          IActiveScriptSIPInfo ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSiteTraceInfo_INTERFACE_DEFINED__
        __IActiveScriptSiteTraceInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteTraceInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteTraceInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteTraceInfoVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteTraceInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptSiteTraceInfo
            STD_METHOD Release, :ptr IActiveScriptSiteTraceInfo
            STD_METHOD SendScriptTraceInfo, :ptr IActiveScriptSiteTraceInfo, :SCRIPTTRACEINFO, :GUID, :DWORD, :LONG, :LONG, :DWORD64
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteTraceInfoVtbl ends

          IActiveScriptSiteTraceInfo struct
            lpVtbl POINTER ?
          IActiveScriptSiteTraceInfo ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptTraceInfo_INTERFACE_DEFINED__
        __IActiveScriptTraceInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptTraceInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptTraceInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptTraceInfoVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptTraceInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptTraceInfo
            STD_METHOD Release, :ptr IActiveScriptTraceInfo
            STD_METHOD StartScriptTracing, :ptr IActiveScriptTraceInfo, :ptr IActiveScriptSiteTraceInfo, :GUID
            STD_METHOD StopScriptTracing, :ptr IActiveScriptTraceInfo
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptTraceInfoVtbl ends

          IActiveScriptTraceInfo struct
            lpVtbl POINTER ?
          IActiveScriptTraceInfo ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptStringCompare_INTERFACE_DEFINED__
        __IActiveScriptStringCompare_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptStringCompare:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptStringCompareVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptStringCompareVtbl>
            STD_METHOD QueryInterface, :ptr IActiveScriptStringCompare, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActiveScriptStringCompare
            STD_METHOD Release, :ptr IActiveScriptStringCompare
            STD_METHOD StrComp, :ptr IActiveScriptStringCompare, :BSTR, :BSTR, :ptr LONG
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptStringCompareVtbl ends

          IActiveScriptStringCompare struct
            lpVtbl POINTER ?
          IActiveScriptStringCompare ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
  endif
  externdef __MIDL_itf_activscp_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_activscp_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  VARIANT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  VARIANT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  IActiveScriptError_GetExceptionInfo_Proxy proto WIN_STD_CALL_CONV :ptr IActiveScriptError, :ptr EXCEPINFO
  IActiveScriptError_GetExceptionInfo_Stub proto WIN_STD_CALL_CONV :ptr IActiveScriptError, :ptr EXCEPINFO
  ifdef __cplusplus
    ;[...]
  endif
endif
 