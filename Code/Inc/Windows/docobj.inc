;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\docobj.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:16:08

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
ifndef __docobj_h__
  __docobj_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if Defined(_CONTROL_FLOW_GUARD_XFG)
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  ifndef __IOleDocument_FWD_DEFINED__
    __IOleDocument_FWD_DEFINED__ equ <>
  endif
  ifndef __IOleDocumentSite_FWD_DEFINED__
    __IOleDocumentSite_FWD_DEFINED__ equ <>
  endif
  ifndef __IOleDocumentView_FWD_DEFINED__
    __IOleDocumentView_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumOleDocumentViews_FWD_DEFINED__
    __IEnumOleDocumentViews_FWD_DEFINED__ equ <>
  endif
  ifndef __IContinueCallback_FWD_DEFINED__
    __IContinueCallback_FWD_DEFINED__ equ <>
  endif
  ifndef __IPrint_FWD_DEFINED__
    __IPrint_FWD_DEFINED__ equ <>
  endif
  ifndef __IOleCommandTarget_FWD_DEFINED__
    __IOleCommandTarget_FWD_DEFINED__ equ <>
  endif
  ifndef __IZoomEvents_FWD_DEFINED__
    __IZoomEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IProtectFocus_FWD_DEFINED__
    __IProtectFocus_FWD_DEFINED__ equ <>
  endif
  ifndef __IProtectedModeMenuServices_FWD_DEFINED__
    __IProtectedModeMenuServices_FWD_DEFINED__ equ <>
  endif
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPOLEDOCUMENT_DEFINED
      _LPOLEDOCUMENT_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IOleDocument_INTERFACE_DEFINED__
        __IOleDocument_INTERFACE_DEFINED__ equ <>
        LPOLEDOCUMENT typedef ptr IOleDocument
        DOCMISC typedef SDWORD
        DOCMISC_CANCREATEMULTIPLEVIEWS equ 1
        DOCMISC_SUPPORTCOMPLEXRECTANGLES equ 2
        DOCMISC_CANTOPENEDIT equ 4
        DOCMISC_NOFILESUPPORT equ 8
        __MIDL_IOleDocument_0001 typedef DOCMISC

        externdef IID_IOleDocument:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IOleDocumentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IOleDocumentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IOleDocument, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IOleDocument
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IOleDocument
            DECLSPEC_XFGVIRT(IOleDocument, CreateView)
            STD_METHOD CreateView, :ptr IOleDocument, :ptr IOleInPlaceSite, :ptr IStream, :DWORD, :ptr ptr IOleDocumentView
            DECLSPEC_XFGVIRT(IOleDocument, GetDocMiscStatus)
            STD_METHOD GetDocMiscStatus, :ptr IOleDocument, :ptr DWORD
            DECLSPEC_XFGVIRT(IOleDocument, EnumViews)
            STD_METHOD EnumViews, :ptr IOleDocument, :ptr ptr IEnumOleDocumentViews, :ptr ptr IOleDocumentView
            ??Interface equ <>
            END_INTERFACE
          IOleDocumentVtbl ends
          IOleDocument struct
            lpVtbl POINTER ?
          IOleDocument ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPOLEDOCUMENTSITE_DEFINED
      _LPOLEDOCUMENTSITE_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IOleDocumentSite_INTERFACE_DEFINED__
        __IOleDocumentSite_INTERFACE_DEFINED__ equ <>
        LPOLEDOCUMENTSITE typedef ptr IOleDocumentSite
        externdef IID_IOleDocumentSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IOleDocumentSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IOleDocumentSiteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IOleDocumentSite, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IOleDocumentSite
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IOleDocumentSite
            DECLSPEC_XFGVIRT(IOleDocumentSite, ActivateMe)
            STD_METHOD ActivateMe, :ptr IOleDocumentSite, :ptr IOleDocumentView
            ??Interface equ <>
            END_INTERFACE
          IOleDocumentSiteVtbl ends
          IOleDocumentSite struct
            lpVtbl POINTER ?
          IOleDocumentSite ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPOLEDOCUMENTVIEW_DEFINED
      _LPOLEDOCUMENTVIEW_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IOleDocumentView_INTERFACE_DEFINED__
        __IOleDocumentView_INTERFACE_DEFINED__ equ <>
        LPOLEDOCUMENTVIEW typedef ptr IOleDocumentView
        externdef IID_IOleDocumentView:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IOleDocumentViewVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IOleDocumentViewVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IOleDocumentView, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IOleDocumentView
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IOleDocumentView
            DECLSPEC_XFGVIRT(IOleDocumentView, SetInPlaceSite)
            STD_METHOD SetInPlaceSite, :ptr IOleDocumentView, :ptr IOleInPlaceSite
            DECLSPEC_XFGVIRT(IOleDocumentView, GetInPlaceSite)
            STD_METHOD GetInPlaceSite, :ptr IOleDocumentView, :ptr ptr IOleInPlaceSite
            DECLSPEC_XFGVIRT(IOleDocumentView, GetDocument)
            STD_METHOD GetDocument, :ptr IOleDocumentView, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IOleDocumentView, SetRect)
            STD_METHOD SetRect, :ptr IOleDocumentView, :LPRECT
            DECLSPEC_XFGVIRT(IOleDocumentView, GetRect)
            STD_METHOD GetRect, :ptr IOleDocumentView, :LPRECT
            DECLSPEC_XFGVIRT(IOleDocumentView, SetRectComplex)
            STD_METHOD SetRectComplex, :ptr IOleDocumentView, :LPRECT, :LPRECT, :LPRECT, :LPRECT
            DECLSPEC_XFGVIRT(IOleDocumentView, Show)
            STD_METHOD Show, :ptr IOleDocumentView, :BOOL
            DECLSPEC_XFGVIRT(IOleDocumentView, UIActivate)
            STD_METHOD UIActivate, :ptr IOleDocumentView, :BOOL
            DECLSPEC_XFGVIRT(IOleDocumentView, Open)
            STD_METHOD Open, :ptr IOleDocumentView
            DECLSPEC_XFGVIRT(IOleDocumentView, CloseView)
            STD_METHOD CloseView, :ptr IOleDocumentView, :DWORD
            DECLSPEC_XFGVIRT(IOleDocumentView, SaveViewState)
            STD_METHOD SaveViewState, :ptr IOleDocumentView, :LPSTREAM
            DECLSPEC_XFGVIRT(IOleDocumentView, ApplyViewState)
            STD_METHOD ApplyViewState, :ptr IOleDocumentView, :LPSTREAM
            DECLSPEC_XFGVIRT(IOleDocumentView, Clone)
            STD_METHOD Clone, :ptr IOleDocumentView, :ptr IOleInPlaceSite, :ptr ptr IOleDocumentView
            ??Interface equ <>
            END_INTERFACE
          IOleDocumentViewVtbl ends
          IOleDocumentView struct
            lpVtbl POINTER ?
          IOleDocumentView ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPENUMOLEDOCUMENTVIEWS_DEFINED
      _LPENUMOLEDOCUMENTVIEWS_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumOleDocumentViews_INTERFACE_DEFINED__
        __IEnumOleDocumentViews_INTERFACE_DEFINED__ equ <>
        LPENUMOLEDOCUMENTVIEWS typedef ptr IEnumOleDocumentViews
        externdef IID_IEnumOleDocumentViews:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumOleDocumentViewsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumOleDocumentViewsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumOleDocumentViews, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumOleDocumentViews
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumOleDocumentViews
            DECLSPEC_XFGVIRT(IEnumOleDocumentViews, Next)
            STD_METHOD Next, :ptr IEnumOleDocumentViews, :ULONG, :ptr ptr IOleDocumentView, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumOleDocumentViews, Skip)
            STD_METHOD Skip, :ptr IEnumOleDocumentViews, :ULONG
            DECLSPEC_XFGVIRT(IEnumOleDocumentViews, Reset)
            STD_METHOD Reset, :ptr IEnumOleDocumentViews
            DECLSPEC_XFGVIRT(IEnumOleDocumentViews, Clone)
            STD_METHOD Clone, :ptr IEnumOleDocumentViews, :ptr ptr IEnumOleDocumentViews
            ??Interface equ <>
            END_INTERFACE
          IEnumOleDocumentViewsVtbl ends
          IEnumOleDocumentViews struct
            lpVtbl POINTER ?
          IEnumOleDocumentViews ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumOleDocumentViews_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumOleDocumentViews, :ULONG, :ptr ptr IOleDocumentView, :ptr ULONG
        IEnumOleDocumentViews_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    ifndef _LPCONTINUECALLBACK_DEFINED
      _LPCONTINUECALLBACK_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IContinueCallback_INTERFACE_DEFINED__
        __IContinueCallback_INTERFACE_DEFINED__ equ <>
        LPCONTINUECALLBACK typedef ptr IContinueCallback
        externdef IID_IContinueCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IContinueCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IContinueCallbackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IContinueCallback, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IContinueCallback
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IContinueCallback
            DECLSPEC_XFGVIRT(IContinueCallback, FContinue)
            STD_METHOD FContinue, :ptr IContinueCallback
            DECLSPEC_XFGVIRT(IContinueCallback, FContinuePrinting)
            STD_METHOD FContinuePrinting, :ptr IContinueCallback, :LONG, :LONG, :ptr wchar_t
            ??Interface equ <>
            END_INTERFACE
          IContinueCallbackVtbl ends
          IContinueCallback struct
            lpVtbl POINTER ?
          IContinueCallback ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPPRINT_DEFINED
      _LPPRINT_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPrint_INTERFACE_DEFINED__
        __IPrint_INTERFACE_DEFINED__ equ <>
        LPPRINT typedef ptr IPrint
        PRINTFLAG typedef SDWORD
        PRINTFLAG_MAYBOTHERUSER equ 1
        PRINTFLAG_PROMPTUSER equ 2
        PRINTFLAG_USERMAYCHANGEPRINTER equ 4
        PRINTFLAG_RECOMPOSETODEVICE equ 8
        PRINTFLAG_DONTACTUALLYPRINT equ 16
        PRINTFLAG_FORCEPROPERTIES equ 32
        PRINTFLAG_PRINTTOFILE equ 64
        __MIDL_IPrint_0001 typedef PRINTFLAG

        PAGERANGE struct
          nFromPage LONG ?
          nToPage LONG ?
        PAGERANGE ends
        tagPAGERANGE typedef PAGERANGE
        PAGESET struct
          cbStruct ULONG ?
          fOddPages BOOL ?
          fEvenPages BOOL ?
          cPageRange ULONG ?
          rgPages PAGERANGE 1 dup (<>)
        PAGESET ends
        tagPAGESET typedef PAGESET
        PAGESET_TOLASTPAGE equ ((- 1))
        externdef IID_IPrint:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPrintVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPrintVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPrint, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPrint
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPrint
            DECLSPEC_XFGVIRT(IPrint, SetInitialPageNum)
            STD_METHOD SetInitialPageNum, :ptr IPrint, :LONG
            DECLSPEC_XFGVIRT(IPrint, GetPageInfo)
            STD_METHOD GetPageInfo, :ptr IPrint, :ptr LONG, :ptr LONG
            DECLSPEC_XFGVIRT(IPrint, Print)
            STD_METHOD Print, :ptr IPrint, :DWORD, :ptr ptr DVTARGETDEVICE, :ptr ptr PAGESET, :ptr STGMEDIUM, :ptr IContinueCallback, :LONG, :ptr LONG, :ptr LONG
            ??Interface equ <>
            END_INTERFACE
          IPrintVtbl ends
          IPrint struct
            lpVtbl POINTER ?
          IPrint ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IPrint_RemotePrint_Proxy proto WIN_STD_CALL_CONV :ptr IPrint, :DWORD, :ptr ptr DVTARGETDEVICE, :ptr ptr PAGESET, :ptr RemSTGMEDIUM, :ptr IContinueCallback, :LONG, :ptr LONG, :ptr LONG
        IPrint_RemotePrint_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    ifndef _LPOLECOMMANDTARGET_DEFINED
      _LPOLECOMMANDTARGET_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0006_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0006_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IOleCommandTarget_INTERFACE_DEFINED__
        __IOleCommandTarget_INTERFACE_DEFINED__ equ <>
        LPOLECOMMANDTARGET typedef ptr IOleCommandTarget
        OLECMDF typedef SDWORD
        OLECMDF_SUPPORTED equ 1h
        OLECMDF_ENABLED equ 2h
        OLECMDF_LATCHED equ 4h
        OLECMDF_NINCHED equ 8h
        OLECMDF_INVISIBLE equ 10h
        OLECMDF_DEFHIDEONCTXTMENU equ 20h

        OLECMD struct
          cmdID ULONG ?
          cmdf DWORD ?
        OLECMD ends
        _tagOLECMD typedef OLECMD
        OLECMDTEXT struct
          cmdtextf DWORD ?
          cwActual ULONG ?
          cwBuf ULONG ?
          rgwz wchar_t 1 dup (?)
        OLECMDTEXT ends
        _tagOLECMDTEXT typedef OLECMDTEXT
        OLECMDTEXTF typedef SDWORD
        OLECMDTEXTF_NONE equ 0
        OLECMDTEXTF_NAME equ 1
        OLECMDTEXTF_STATUS equ 2

        OLECMDEXECOPT typedef SDWORD
        OLECMDEXECOPT_DODEFAULT equ 0
        OLECMDEXECOPT_PROMPTUSER equ 1
        OLECMDEXECOPT_DONTPROMPTUSER equ 2
        OLECMDEXECOPT_SHOWHELP equ 3

        OLECMDID typedef SDWORD
        OLECMDID_OPEN equ 1
        OLECMDID_NEW equ 2
        OLECMDID_SAVE equ 3
        OLECMDID_SAVEAS equ 4
        OLECMDID_SAVECOPYAS equ 5
        OLECMDID_PRINT equ 6
        OLECMDID_PRINTPREVIEW equ 7
        OLECMDID_PAGESETUP equ 8
        OLECMDID_SPELL equ 9
        OLECMDID_PROPERTIES equ 10
        OLECMDID_CUT equ 11
        OLECMDID_COPY equ 12
        OLECMDID_PASTE equ 13
        OLECMDID_PASTESPECIAL equ 14
        OLECMDID_UNDO equ 15
        OLECMDID_REDO equ 16
        OLECMDID_SELECTALL equ 17
        OLECMDID_CLEARSELECTION equ 18
        OLECMDID_ZOOM equ 19
        OLECMDID_GETZOOMRANGE equ 20
        OLECMDID_UPDATECOMMANDS equ 21
        OLECMDID_REFRESH equ 22
        OLECMDID_STOP equ 23
        OLECMDID_HIDETOOLBARS equ 24
        OLECMDID_SETPROGRESSMAX equ 25
        OLECMDID_SETPROGRESSPOS equ 26
        OLECMDID_SETPROGRESSTEXT equ 27
        OLECMDID_SETTITLE equ 28
        OLECMDID_SETDOWNLOADSTATE equ 29
        OLECMDID_STOPDOWNLOAD equ 30
        OLECMDID_ONTOOLBARACTIVATED equ 31
        OLECMDID_FIND equ 32
        OLECMDID_DELETE equ 33
        OLECMDID_HTTPEQUIV equ 34
        OLECMDID_HTTPEQUIV_DONE equ 35
        OLECMDID_ENABLE_INTERACTION equ 36
        OLECMDID_ONUNLOAD equ 37
        OLECMDID_PROPERTYBAG2 equ 38
        OLECMDID_PREREFRESH equ 39
        OLECMDID_SHOWSCRIPTERROR equ 40
        OLECMDID_SHOWMESSAGE equ 41
        OLECMDID_SHOWFIND equ 42
        OLECMDID_SHOWPAGESETUP equ 43
        OLECMDID_SHOWPRINT equ 44
        OLECMDID_CLOSE equ 45
        OLECMDID_ALLOWUILESSSAVEAS equ 46
        OLECMDID_DONTDOWNLOADCSS equ 47
        OLECMDID_UPDATEPAGESTATUS equ 48
        OLECMDID_PRINT2 equ 49
        OLECMDID_PRINTPREVIEW2 equ 50
        OLECMDID_SETPRINTTEMPLATE equ 51
        OLECMDID_GETPRINTTEMPLATE equ 52
        OLECMDID_PAGEACTIONBLOCKED equ 55
        OLECMDID_PAGEACTIONUIQUERY equ 56
        OLECMDID_FOCUSVIEWCONTROLS equ 57
        OLECMDID_FOCUSVIEWCONTROLSQUERY equ 58
        OLECMDID_SHOWPAGEACTIONMENU equ 59
        OLECMDID_ADDTRAVELENTRY equ 60
        OLECMDID_UPDATETRAVELENTRY equ 61
        OLECMDID_UPDATEBACKFORWARDSTATE equ 62
        OLECMDID_OPTICAL_ZOOM equ 63
        OLECMDID_OPTICAL_GETZOOMRANGE equ 64
        OLECMDID_WINDOWSTATECHANGED equ 65
        OLECMDID_ACTIVEXINSTALLSCOPE equ 66
        OLECMDID_UPDATETRAVELENTRY_DATARECOVERY equ 67
        OLECMDID_SHOWTASKDLG equ 68
        OLECMDID_POPSTATEEVENT equ 69
        OLECMDID_VIEWPORT_MODE equ 70
        OLECMDID_LAYOUT_VIEWPORT_WIDTH equ 71
        OLECMDID_VISUAL_VIEWPORT_EXCLUDE_BOTTOM equ 72
        OLECMDID_USER_OPTICAL_ZOOM equ 73
        OLECMDID_PAGEAVAILABLE equ 74
        OLECMDID_GETUSERSCALABLE equ 75
        OLECMDID_UPDATE_CARET equ 76
        OLECMDID_ENABLE_VISIBILITY equ 77
        OLECMDID_MEDIA_PLAYBACK equ 78
        OLECMDID_SETFAVICON equ 79
        OLECMDID_SET_HOST_FULLSCREENMODE equ 80
        OLECMDID_EXITFULLSCREEN equ 81
        OLECMDID_SCROLLCOMPLETE equ 82
        OLECMDID_ONBEFOREUNLOAD equ 83
        OLECMDID_SHOWMESSAGE_BLOCKABLE equ 84
        OLECMDID_SHOWTASKDLG_BLOCKABLE equ 85

        MEDIAPLAYBACK_STATE typedef SDWORD
        MEDIAPLAYBACK_RESUME equ 0
        MEDIAPLAYBACK_PAUSE equ 1
        MEDIAPLAYBACK_PAUSE_AND_SUSPEND equ 2
        MEDIAPLAYBACK_RESUME_FROM_SUSPEND equ 3

        OLECMDERR_E_FIRST equ (OLE_E_LAST + 1)
        OLECMDERR_E_NOTSUPPORTED equ <(OLECMDERR_E_FIRST)>
        OLECMDERR_E_DISABLED equ (OLECMDERR_E_FIRST + 1)
        OLECMDERR_E_NOHELP equ (OLECMDERR_E_FIRST + 2)
        OLECMDERR_E_CANCELED equ (OLECMDERR_E_FIRST + 3)
        OLECMDERR_E_UNKNOWNGROUP equ (OLECMDERR_E_FIRST + 4)
        MSOCMDERR_E_FIRST equ <OLECMDERR_E_FIRST>
        MSOCMDERR_E_NOTSUPPORTED equ <OLECMDERR_E_NOTSUPPORTED>
        MSOCMDERR_E_DISABLED equ <OLECMDERR_E_DISABLED>
        MSOCMDERR_E_NOHELP equ <OLECMDERR_E_NOHELP>
        MSOCMDERR_E_CANCELED equ <OLECMDERR_E_CANCELED>
        MSOCMDERR_E_UNKNOWNGROUP equ <OLECMDERR_E_UNKNOWNGROUP>
        OLECMD_TASKDLGID_ONBEFOREUNLOAD equ 1
        if (NTDDI_VERSION ge NTDDI_WINXPSP2)
          OLECMDARGINDEX_SHOWPAGEACTIONMENU_HWND equ 0
          OLECMDARGINDEX_SHOWPAGEACTIONMENU_X equ 1
          OLECMDARGINDEX_SHOWPAGEACTIONMENU_Y equ 2
          OLECMDARGINDEX_ACTIVEXINSTALL_PUBLISHER equ 0
          OLECMDARGINDEX_ACTIVEXINSTALL_DISPLAYNAME equ 1
          OLECMDARGINDEX_ACTIVEXINSTALL_CLSID equ 2
          OLECMDARGINDEX_ACTIVEXINSTALL_INSTALLSCOPE equ 3
          OLECMDARGINDEX_ACTIVEXINSTALL_SOURCEURL equ 4
          INSTALL_SCOPE_INVALID equ 0
          INSTALL_SCOPE_MACHINE equ 1
          INSTALL_SCOPE_USER equ 2
          IGNOREMIME typedef SDWORD
          IGNOREMIME_PROMPT equ 1h
          IGNOREMIME_TEXT equ 2h

          WPCSETTING typedef SDWORD
          WPCSETTING_LOGGING_ENABLED equ 1h
          WPCSETTING_FILEDOWNLOAD_BLOCKED equ 2h

        endif
        externdef IID_IOleCommandTarget:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IOleCommandTargetVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IOleCommandTargetVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IOleCommandTarget, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IOleCommandTarget
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IOleCommandTarget
            DECLSPEC_XFGVIRT(IOleCommandTarget, QueryStatus)
            STD_METHOD QueryStatus, :ptr IOleCommandTarget, :ptr GUID, :ULONG, :ptr OLECMD, :ptr OLECMDTEXT
            DECLSPEC_XFGVIRT(IOleCommandTarget, Exec)
            STD_METHOD Exec, :ptr IOleCommandTarget, :ptr GUID, :DWORD, :DWORD, :ptr VARIANT, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          IOleCommandTargetVtbl ends
          IOleCommandTarget struct
            lpVtbl POINTER ?
          IOleCommandTarget ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    OLECMDID_REFRESHFLAG typedef SDWORD
    OLECMDIDF_REFRESH_NORMAL equ 0
    OLECMDIDF_REFRESH_IFEXPIRED equ 1
    OLECMDIDF_REFRESH_CONTINUE equ 2
    OLECMDIDF_REFRESH_COMPLETELY equ 3
    OLECMDIDF_REFRESH_NO_CACHE equ 4
    OLECMDIDF_REFRESH_RELOAD equ 5
    OLECMDIDF_REFRESH_LEVELMASK equ 00FFh
    OLECMDIDF_REFRESH_CLEARUSERINPUT equ 1000h
    if (NTDDI_VERSION ge NTDDI_WINXPSP2)
      OLECMDIDF_REFRESH_PROMPTIFOFFLINE equ 2000h
      OLECMDIDF_REFRESH_THROUGHSCRIPT equ 4000h
      OLECMDIDF_REFRESH_SKIPBEFOREUNLOADEVENT equ 8000h
      OLECMDIDF_REFRESH_PAGEACTION_ACTIVEXINSTALL equ 00010000h
      OLECMDIDF_REFRESH_PAGEACTION_FILEDOWNLOAD equ 00020000h
      OLECMDIDF_REFRESH_PAGEACTION_LOCALMACHINE equ 00040000h
      OLECMDIDF_REFRESH_PAGEACTION_POPUPWINDOW equ 00080000h
      OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNLOCALMACHINE equ 00100000h
      OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNTRUSTED equ 00200000h
      OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNINTRANET equ 00400000h
      OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNINTERNET equ 00800000h
      OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNRESTRICTED equ 01000000h
    elseif (NTDDI_VERSION ge NTDDI_WINXP)
      OLECMDIDF_REFRESH_PROMPTIFOFFLINE equ 2000h
      OLECMDIDF_REFRESH_THROUGHSCRIPT equ 4000h
    else
      OLECMDIDF_REFRESH_PROMPTIFOFFLINE equ 2000h
    endif
    OLECMDIDF_REFRESH_PAGEACTION_MIXEDCONTENT equ 02000000h
    OLECMDIDF_REFRESH_PAGEACTION_INVALID_CERT equ 04000000h
    OLECMDIDF_REFRESH_PAGEACTION_ALLOW_VERSION equ 08000000h

    if (NTDDI_VERSION ge NTDDI_WINXPSP2)
      OLECMDID_PAGEACTIONFLAG typedef SDWORD
      OLECMDIDF_PAGEACTION_FILEDOWNLOAD equ 00000001h
      OLECMDIDF_PAGEACTION_ACTIVEXINSTALL equ 00000002h
      OLECMDIDF_PAGEACTION_ACTIVEXTRUSTFAIL equ 00000004h
      OLECMDIDF_PAGEACTION_ACTIVEXUSERDISABLE equ 00000008h
      OLECMDIDF_PAGEACTION_ACTIVEXDISALLOW equ 00000010h
      OLECMDIDF_PAGEACTION_ACTIVEXUNSAFE equ 00000020h
      OLECMDIDF_PAGEACTION_POPUPWINDOW equ 00000040h
      OLECMDIDF_PAGEACTION_LOCALMACHINE equ 00000080h
      OLECMDIDF_PAGEACTION_MIMETEXTPLAIN equ 00000100h
      OLECMDIDF_PAGEACTION_SCRIPTNAVIGATE equ 00000200h
      OLECMDIDF_PAGEACTION_SCRIPTNAVIGATE_ACTIVEXINSTALL equ 00000200h
      OLECMDIDF_PAGEACTION_PROTLOCKDOWNLOCALMACHINE equ 00000400h
      OLECMDIDF_PAGEACTION_PROTLOCKDOWNTRUSTED equ 00000800h
      OLECMDIDF_PAGEACTION_PROTLOCKDOWNINTRANET equ 00001000h
      OLECMDIDF_PAGEACTION_PROTLOCKDOWNINTERNET equ 00002000h
      OLECMDIDF_PAGEACTION_PROTLOCKDOWNRESTRICTED equ 00004000h
      OLECMDIDF_PAGEACTION_PROTLOCKDOWNDENY equ 00008000h
      OLECMDIDF_PAGEACTION_POPUPALLOWED equ 00010000h
      OLECMDIDF_PAGEACTION_SCRIPTPROMPT equ 00020000h
      OLECMDIDF_PAGEACTION_ACTIVEXUSERAPPROVAL equ 00040000h
      OLECMDIDF_PAGEACTION_MIXEDCONTENT equ 00080000h
      OLECMDIDF_PAGEACTION_INVALID_CERT equ 00100000h
      OLECMDIDF_PAGEACTION_INTRANETZONEREQUEST equ 00200000h
      OLECMDIDF_PAGEACTION_XSSFILTERED equ 00400000h
      OLECMDIDF_PAGEACTION_SPOOFABLEIDNHOST equ 00800000h
      OLECMDIDF_PAGEACTION_ACTIVEX_EPM_INCOMPATIBLE equ 01000000h
      OLECMDIDF_PAGEACTION_SCRIPTNAVIGATE_ACTIVEXUSERAPPROVAL equ 02000000h
      OLECMDIDF_PAGEACTION_WPCBLOCKED equ 04000000h
      OLECMDIDF_PAGEACTION_WPCBLOCKED_ACTIVEX equ 08000000h
      OLECMDIDF_PAGEACTION_EXTENSION_COMPAT_BLOCKED equ 10000000h
      OLECMDIDF_PAGEACTION_NORESETACTIVEX equ 20000000h
      OLECMDIDF_PAGEACTION_GENERIC_STATE equ 40000000h
      OLECMDIDF_PAGEACTION_RESET equ 80000000h

      OLECMDID_BROWSERSTATEFLAG typedef SDWORD
      OLECMDIDF_BROWSERSTATE_EXTENSIONSOFF equ 00000001h
      OLECMDIDF_BROWSERSTATE_IESECURITY equ 00000002h
      OLECMDIDF_BROWSERSTATE_PROTECTEDMODE_OFF equ 00000004h
      OLECMDIDF_BROWSERSTATE_RESET equ 00000008h
      OLECMDIDF_BROWSERSTATE_REQUIRESACTIVEX equ 00000010h
      OLECMDIDF_BROWSERSTATE_DESKTOPHTMLDIALOG equ 00000020h
      OLECMDIDF_BROWSERSTATE_BLOCKEDVERSION equ 00000040h

      OLECMDID_OPTICAL_ZOOMFLAG typedef SDWORD
      OLECMDIDF_OPTICAL_ZOOM_NOPERSIST equ 00000001h
      OLECMDIDF_OPTICAL_ZOOM_NOLAYOUT equ 00000010h
      OLECMDIDF_OPTICAL_ZOOM_NOTRANSIENT equ 00000020h
      OLECMDIDF_OPTICAL_ZOOM_RELOADFORNEWTAB equ 00000040h

      PAGEACTION_UI typedef SDWORD
      PAGEACTION_UI_DEFAULT equ 0
      PAGEACTION_UI_MODAL equ 1
      PAGEACTION_UI_MODELESS equ 2
      PAGEACTION_UI_SILENT equ 3

    endif
    OLECMDID_WINDOWSTATE_FLAG typedef SDWORD
    OLECMDIDF_WINDOWSTATE_USERVISIBLE equ 00000001h
    OLECMDIDF_WINDOWSTATE_ENABLED equ 00000002h
    OLECMDIDF_WINDOWSTATE_USERVISIBLE_VALID equ 00010000h
    OLECMDIDF_WINDOWSTATE_ENABLED_VALID equ 00020000h

    OLECMDID_VIEWPORT_MODE_FLAG typedef SDWORD
    OLECMDIDF_VIEWPORTMODE_FIXED_LAYOUT_WIDTH equ 00000001h
    OLECMDIDF_VIEWPORTMODE_EXCLUDE_VISUAL_BOTTOM equ 00000002h
    OLECMDIDF_VIEWPORTMODE_FIXED_LAYOUT_WIDTH_VALID equ 00010000h
    OLECMDIDF_VIEWPORTMODE_EXCLUDE_VISUAL_BOTTOM_VALID equ 00020000h

    IMsoDocument equ <IOleDocument>
    IMsoDocumentSite equ <IOleDocumentSite>
    IMsoView equ <IOleDocumentView>
    IEnumMsoView equ <IEnumOleDocumentViews>
    IMsoCommandTarget equ <IOleCommandTarget>
    LPMSODOCUMENT equ <LPOLEDOCUMENT>
    LPMSODOCUMENTSITE equ <LPOLEDOCUMENTSITE>
    LPMSOVIEW equ <LPOLEDOCUMENTVIEW>
    LPENUMMSOVIEW equ <LPENUMOLEDOCUMENTVIEWS>
    LPMSOCOMMANDTARGET equ <LPOLECOMMANDTARGET>
    MSOCMD equ <OLECMD>
    MSOCMDTEXT equ <OLECMDTEXT>
    IID_IMsoDocument equ <IID_IOleDocument>
    IID_IMsoDocumentSite equ <IID_IOleDocumentSite>
    IID_IMsoView equ <IID_IOleDocumentView>
    IID_IEnumMsoView equ <IID_IEnumOleDocumentViews>
    IID_IMsoCommandTarget equ <IID_IOleCommandTarget>
    MSOCMDF_SUPPORTED equ <OLECMDF_SUPPORTED>
    MSOCMDF_ENABLED equ <OLECMDF_ENABLED>
    MSOCMDF_LATCHED equ <OLECMDF_LATCHED>
    MSOCMDF_NINCHED equ <OLECMDF_NINCHED>
    MSOCMDTEXTF_NONE equ <OLECMDTEXTF_NONE>
    MSOCMDTEXTF_NAME equ <OLECMDTEXTF_NAME>
    MSOCMDTEXTF_STATUS equ <OLECMDTEXTF_STATUS>
    MSOCMDEXECOPT_DODEFAULT equ <OLECMDEXECOPT_DODEFAULT>
    MSOCMDEXECOPT_PROMPTUSER equ <OLECMDEXECOPT_PROMPTUSER>
    MSOCMDEXECOPT_DONTPROMPTUSER equ <OLECMDEXECOPT_DONTPROMPTUSER>
    MSOCMDEXECOPT_SHOWHELP equ <OLECMDEXECOPT_SHOWHELP>
    MSOCMDID_OPEN equ <OLECMDID_OPEN>
    MSOCMDID_NEW equ <OLECMDID_NEW>
    MSOCMDID_SAVE equ <OLECMDID_SAVE>
    MSOCMDID_SAVEAS equ <OLECMDID_SAVEAS>
    MSOCMDID_SAVECOPYAS equ <OLECMDID_SAVECOPYAS>
    MSOCMDID_PRINT equ <OLECMDID_PRINT>
    MSOCMDID_PRINTPREVIEW equ <OLECMDID_PRINTPREVIEW>
    MSOCMDID_PAGESETUP equ <OLECMDID_PAGESETUP>
    MSOCMDID_SPELL equ <OLECMDID_SPELL>
    MSOCMDID_PROPERTIES equ <OLECMDID_PROPERTIES>
    MSOCMDID_CUT equ <OLECMDID_CUT>
    MSOCMDID_COPY equ <OLECMDID_COPY>
    MSOCMDID_PASTE equ <OLECMDID_PASTE>
    MSOCMDID_PASTESPECIAL equ <OLECMDID_PASTESPECIAL>
    MSOCMDID_UNDO equ <OLECMDID_UNDO>
    MSOCMDID_REDO equ <OLECMDID_REDO>
    MSOCMDID_SELECTALL equ <OLECMDID_SELECTALL>
    MSOCMDID_CLEARSELECTION equ <OLECMDID_CLEARSELECTION>
    MSOCMDID_ZOOM equ <OLECMDID_ZOOM>
    MSOCMDID_GETZOOMRANGE equ <OLECMDID_GETZOOMRANGE>
    externdef SID_SContainerDispatch:GUID
    externdef __MIDL_itf_docobj_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_docobj_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IZoomEvents_INTERFACE_DEFINED__
      __IZoomEvents_INTERFACE_DEFINED__ equ <>
      externdef IID_IZoomEvents:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IZoomEventsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IZoomEventsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IZoomEvents, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IZoomEvents
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IZoomEvents
          DECLSPEC_XFGVIRT(IZoomEvents, OnZoomPercentChanged)
          STD_METHOD OnZoomPercentChanged, :ptr IZoomEvents, :ULONG
          ??Interface equ <>
          END_INTERFACE
        IZoomEventsVtbl ends
        IZoomEvents struct
          lpVtbl POINTER ?
        IZoomEvents ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IProtectFocus_INTERFACE_DEFINED__
      __IProtectFocus_INTERFACE_DEFINED__ equ <>
      externdef IID_IProtectFocus:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProtectFocusVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProtectFocusVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IProtectFocus, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProtectFocus
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProtectFocus
          DECLSPEC_XFGVIRT(IProtectFocus, AllowFocusChange)
          STD_METHOD AllowFocusChange, :ptr IProtectFocus, :ptr BOOL
          ??Interface equ <>
          END_INTERFACE
        IProtectFocusVtbl ends
        IProtectFocus struct
          lpVtbl POINTER ?
        IProtectFocus ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    SID_SProtectFocus equ <IID_IProtectFocus>
    ifndef _LPPROTECTEDMODEMENUSERVICES_DEFINED
      _LPPROTECTEDMODEMENUSERVICES_DEFINED equ <>
      externdef __MIDL_itf_docobj_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_docobj_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IProtectedModeMenuServices_INTERFACE_DEFINED__
        __IProtectedModeMenuServices_INTERFACE_DEFINED__ equ <>
        externdef IID_IProtectedModeMenuServices:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProtectedModeMenuServicesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProtectedModeMenuServicesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IProtectedModeMenuServices, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProtectedModeMenuServices
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProtectedModeMenuServices
            DECLSPEC_XFGVIRT(IProtectedModeMenuServices, CreateMenu)
            STD_METHOD CreateMenu, :ptr IProtectedModeMenuServices, :ptr HMENU
            DECLSPEC_XFGVIRT(IProtectedModeMenuServices, LoadMenu)
            STD_METHOD LoadMenu, :ptr IProtectedModeMenuServices, :LPCWSTR, :LPCWSTR, :ptr HMENU
            DECLSPEC_XFGVIRT(IProtectedModeMenuServices, LoadMenuID)
            STD_METHOD LoadMenuID, :ptr IProtectedModeMenuServices, :LPCWSTR, :WORD, :ptr HMENU
            ??Interface equ <>
            END_INTERFACE
          IProtectedModeMenuServicesVtbl ends
          IProtectedModeMenuServices struct
            lpVtbl POINTER ?
          IProtectedModeMenuServices ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) and  not WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    PAGESET struct
    PAGESET ends
    tagPAGESET typedef PAGESET
  endif
  externdef __MIDL_itf_docobj_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_docobj_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
  HMENU_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMENU
  HMENU_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMENU
  VARIANT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  HMENU_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMENU
  HMENU_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMENU
  VARIANT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  IEnumOleDocumentViews_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumOleDocumentViews, :ULONG, :ptr ptr IOleDocumentView, :ptr ULONG
  IEnumOleDocumentViews_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumOleDocumentViews, :ULONG, :ptr ptr IOleDocumentView, :ptr ULONG
  IPrint_Print_Proxy proto WIN_STD_CALL_CONV :ptr IPrint, :DWORD, :ptr ptr DVTARGETDEVICE, :ptr ptr PAGESET, :ptr STGMEDIUM, :ptr IContinueCallback, :LONG, :ptr LONG, :ptr LONG
  IPrint_Print_Stub proto WIN_STD_CALL_CONV :ptr IPrint, :DWORD, :ptr ptr DVTARGETDEVICE, :ptr ptr PAGESET, :ptr RemSTGMEDIUM, :ptr IContinueCallback, :LONG, :ptr LONG, :ptr LONG
  ifdef __cplusplus
    ;[...]
  endif
endif
