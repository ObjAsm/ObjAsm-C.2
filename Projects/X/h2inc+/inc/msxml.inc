;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\msxml.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:17:08

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef __msxml_h__
  __msxml_h__ equ <>
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
  ifndef __IXMLDOMImplementation_FWD_DEFINED__
    __IXMLDOMImplementation_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMNode_FWD_DEFINED__
    __IXMLDOMNode_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMDocumentFragment_FWD_DEFINED__
    __IXMLDOMDocumentFragment_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMDocument_FWD_DEFINED__
    __IXMLDOMDocument_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMNodeList_FWD_DEFINED__
    __IXMLDOMNodeList_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMNamedNodeMap_FWD_DEFINED__
    __IXMLDOMNamedNodeMap_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMCharacterData_FWD_DEFINED__
    __IXMLDOMCharacterData_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMAttribute_FWD_DEFINED__
    __IXMLDOMAttribute_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMElement_FWD_DEFINED__
    __IXMLDOMElement_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMText_FWD_DEFINED__
    __IXMLDOMText_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMComment_FWD_DEFINED__
    __IXMLDOMComment_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMProcessingInstruction_FWD_DEFINED__
    __IXMLDOMProcessingInstruction_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMCDATASection_FWD_DEFINED__
    __IXMLDOMCDATASection_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMDocumentType_FWD_DEFINED__
    __IXMLDOMDocumentType_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMNotation_FWD_DEFINED__
    __IXMLDOMNotation_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMEntity_FWD_DEFINED__
    __IXMLDOMEntity_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMEntityReference_FWD_DEFINED__
    __IXMLDOMEntityReference_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDOMParseError_FWD_DEFINED__
    __IXMLDOMParseError_FWD_DEFINED__ equ <>
  endif
  ifndef __IXTLRuntime_FWD_DEFINED__
    __IXTLRuntime_FWD_DEFINED__ equ <>
  endif
  ifndef __XMLDOMDocumentEvents_FWD_DEFINED__
    __XMLDOMDocumentEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __DOMDocument_FWD_DEFINED__
    __DOMDocument_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DOMFreeThreadedDocument_FWD_DEFINED__
    __DOMFreeThreadedDocument_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __IXMLHttpRequest_FWD_DEFINED__
    __IXMLHttpRequest_FWD_DEFINED__ equ <>
  endif
  ifndef __XMLHTTPRequest_FWD_DEFINED__
    __XMLHTTPRequest_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __IXMLDSOControl_FWD_DEFINED__
    __IXMLDSOControl_FWD_DEFINED__ equ <>
  endif
  ifndef __XMLDSOControl_FWD_DEFINED__
    __XMLDSOControl_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __IXMLElementCollection_FWD_DEFINED__
    __IXMLElementCollection_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDocument_FWD_DEFINED__
    __IXMLDocument_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLDocument2_FWD_DEFINED__
    __IXMLDocument2_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLElement_FWD_DEFINED__
    __IXMLElement_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLElement2_FWD_DEFINED__
    __IXMLElement2_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLAttribute_FWD_DEFINED__
    __IXMLAttribute_FWD_DEFINED__ equ <>
  endif
  ifndef __IXMLError_FWD_DEFINED__
    __IXMLError_FWD_DEFINED__ equ <>
  endif
  ifndef __XMLDocument_FWD_DEFINED__
    __XMLDocument_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  include unknwn.inc
  include objidl.inc
  include oaidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    XML_ERROR struct
      _nLine DWORD ?
      _pchBuf BSTR ?
      _cchBuf DWORD ?
      _ich DWORD ?
      _pszFound BSTR ?
      _pszExpected BSTR ?
      _reserved1 DWORD ?
      _reserved2 DWORD ?
    XML_ERROR ends
    _xml_error typedef XML_ERROR
    externdef __MIDL_itf_msxml_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_msxml_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __MSXML_LIBRARY_DEFINED__
      __MSXML_LIBRARY_DEFINED__ equ <>
      include winapifamily.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        DOMNodeType typedef SDWORD
        NODE_INVALID equ 0
        NODE_ELEMENT equ
        NODE_ATTRIBUTE equ
        NODE_TEXT equ
        NODE_CDATA_SECTION equ
        NODE_ENTITY_REFERENCE equ
        NODE_ENTITY equ
        NODE_PROCESSING_INSTRUCTION equ
        NODE_COMMENT equ
        NODE_DOCUMENT equ
        NODE_DOCUMENT_TYPE equ
        NODE_DOCUMENT_FRAGMENT equ
        NODE_NOTATION equ
        tagDOMNodeType typedef DOMNodeType

      endif
      include winapifamily.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      endif
      XMLELEM_TYPE typedef SDWORD
      XMLELEMTYPE_ELEMENT equ 0
      XMLELEMTYPE_TEXT equ
      XMLELEMTYPE_COMMENT equ
      XMLELEMTYPE_DOCUMENT equ
      XMLELEMTYPE_DTD equ
      XMLELEMTYPE_PI equ
      XMLELEMTYPE_OTHER equ
      tagXMLEMEM_TYPE typedef XMLELEM_TYPE

      externdef LIBID_MSXML:IID
      ifndef __IXMLDOMImplementation_INTERFACE_DEFINED__
        __IXMLDOMImplementation_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMImplementation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMImplementationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMImplementationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMImplementation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMImplementation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMImplementation
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMImplementation, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMImplementation, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMImplementation, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMImplementation, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMImplementation, hasFeature)
            STD_METHOD hasFeature, :ptr IXMLDOMImplementation, :BSTR, :BSTR, :ptr VARIANT_BOOL
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMImplementationVtbl ends
          IXMLDOMImplementation struct
            lpVtbl POINTER ?
          IXMLDOMImplementation ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMNode_INTERFACE_DEFINED__
        __IXMLDOMNode_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMNode:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMNodeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMNodeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMNode, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNode, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNode, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNode, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMNode, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMNode, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMNode, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMNode, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMNode, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMNode, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMNode, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMNode, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMNode, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMNode, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMNode, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMNode, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMNode, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMNode, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMNodeVtbl ends
          IXMLDOMNode struct
            lpVtbl POINTER ?
          IXMLDOMNode ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMDocumentFragment_INTERFACE_DEFINED__
        __IXMLDOMDocumentFragment_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMDocumentFragment:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMDocumentFragmentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMDocumentFragmentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMDocumentFragment, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMDocumentFragment
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMDocumentFragment
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMDocumentFragment, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMDocumentFragment, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMDocumentFragment, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMDocumentFragment, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMDocumentFragment, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMDocumentFragment, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMDocumentFragment, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMDocumentFragment, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMDocumentFragment, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMDocumentFragment, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMDocumentFragment, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMDocumentFragment, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMDocumentFragment, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMDocumentFragment, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMDocumentFragment, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMDocumentFragment, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMDocumentFragment, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMDocumentFragment, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMDocumentFragmentVtbl ends
          IXMLDOMDocumentFragment struct
            lpVtbl POINTER ?
          IXMLDOMDocumentFragment ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMDocument_INTERFACE_DEFINED__
        __IXMLDOMDocument_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMDocument:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMDocumentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMDocumentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMDocument, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMDocument, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMDocument, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMDocument, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMDocument, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMDocument, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMDocument, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMDocument, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMDocument, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMDocument, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMDocument, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMDocument, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMDocument, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMDocument, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_doctype)
            STD_METHOD get_doctype, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMDocumentType
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_implementation)
            STD_METHOD get_implementation, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMImplementation
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_documentElement)
            STD_METHOD get_documentElement, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMElement
            DECLSPEC_XFGVIRT(IXMLDOMDocument, putref_documentElement)
            STD_METHOD putref_documentElement, :ptr IXMLDOMDocument, :ptr IXMLDOMElement
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createElement)
            STD_METHOD createElement, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMElement
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createDocumentFragment)
            STD_METHOD createDocumentFragment, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMDocumentFragment
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createTextNode)
            STD_METHOD createTextNode, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMText
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createComment)
            STD_METHOD createComment, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMComment
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createCDATASection)
            STD_METHOD createCDATASection, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMCDATASection
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createProcessingInstruction)
            STD_METHOD createProcessingInstruction, :ptr IXMLDOMDocument, :BSTR, :BSTR, :ptr ptr IXMLDOMProcessingInstruction
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createAttribute)
            STD_METHOD createAttribute, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMAttribute
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createEntityReference)
            STD_METHOD createEntityReference, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMEntityReference
            DECLSPEC_XFGVIRT(IXMLDOMDocument, getElementsByTagName)
            STD_METHOD getElementsByTagName, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMDocument, createNode)
            STD_METHOD createNode, :ptr IXMLDOMDocument, :VARIANT, :BSTR, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMDocument, nodeFromID)
            STD_METHOD nodeFromID, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMDocument, load)
            STD_METHOD load, :ptr IXMLDOMDocument, :VARIANT, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_readyState)
            STD_METHOD get_readyState, :ptr IXMLDOMDocument, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_parseError)
            STD_METHOD get_parseError, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMParseError
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_url)
            STD_METHOD get_url, :ptr IXMLDOMDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_async)
            STD_METHOD get_async, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_async)
            STD_METHOD put_async, :ptr IXMLDOMDocument, :VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, abort)
            STD_METHOD abort, :ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMDocument, loadXML)
            STD_METHOD loadXML, :ptr IXMLDOMDocument, :BSTR, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, save)
            STD_METHOD save, :ptr IXMLDOMDocument, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_validateOnParse)
            STD_METHOD get_validateOnParse, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_validateOnParse)
            STD_METHOD put_validateOnParse, :ptr IXMLDOMDocument, :VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_resolveExternals)
            STD_METHOD get_resolveExternals, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_resolveExternals)
            STD_METHOD put_resolveExternals, :ptr IXMLDOMDocument, :VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, get_preserveWhiteSpace)
            STD_METHOD get_preserveWhiteSpace, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_preserveWhiteSpace)
            STD_METHOD put_preserveWhiteSpace, :ptr IXMLDOMDocument, :VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_onreadystatechange)
            STD_METHOD put_onreadystatechange, :ptr IXMLDOMDocument, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_ondataavailable)
            STD_METHOD put_ondataavailable, :ptr IXMLDOMDocument, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMDocument, put_ontransformnode)
            STD_METHOD put_ontransformnode, :ptr IXMLDOMDocument, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMDocumentVtbl ends
          IXMLDOMDocument struct
            lpVtbl POINTER ?
          IXMLDOMDocument ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMNodeList_INTERFACE_DEFINED__
        __IXMLDOMNodeList_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMNodeList:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMNodeListVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMNodeListVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMNodeList, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNodeList, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNodeList, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNodeList, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMNodeList, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNodeList, get_item)
            STD_METHOD get_item, :ptr IXMLDOMNodeList, :SDWORD, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNodeList, get_length)
            STD_METHOD get_length, :ptr IXMLDOMNodeList, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMNodeList, nextNode)
            STD_METHOD nextNode, :ptr IXMLDOMNodeList, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNodeList, reset)
            STD_METHOD reset, :ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNodeList, get__newEnum)
            STD_METHOD get__newEnum, :ptr IXMLDOMNodeList, :ptr ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMNodeListVtbl ends
          IXMLDOMNodeList struct
            lpVtbl POINTER ?
          IXMLDOMNodeList ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMNamedNodeMap_INTERFACE_DEFINED__
        __IXMLDOMNamedNodeMap_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMNamedNodeMap:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMNamedNodeMapVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMNamedNodeMapVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMNamedNodeMap, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNamedNodeMap, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNamedNodeMap, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNamedNodeMap, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMNamedNodeMap, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, getNamedItem)
            STD_METHOD getNamedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, setNamedItem)
            STD_METHOD setNamedItem, :ptr IXMLDOMNamedNodeMap, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, removeNamedItem)
            STD_METHOD removeNamedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, get_item)
            STD_METHOD get_item, :ptr IXMLDOMNamedNodeMap, :SDWORD, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, get_length)
            STD_METHOD get_length, :ptr IXMLDOMNamedNodeMap, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, getQualifiedItem)
            STD_METHOD getQualifiedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, removeQualifiedItem)
            STD_METHOD removeQualifiedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, nextNode)
            STD_METHOD nextNode, :ptr IXMLDOMNamedNodeMap, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, reset)
            STD_METHOD reset, :ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNamedNodeMap, get__newEnum)
            STD_METHOD get__newEnum, :ptr IXMLDOMNamedNodeMap, :ptr ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMNamedNodeMapVtbl ends
          IXMLDOMNamedNodeMap struct
            lpVtbl POINTER ?
          IXMLDOMNamedNodeMap ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMCharacterData_INTERFACE_DEFINED__
        __IXMLDOMCharacterData_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMCharacterData:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMCharacterDataVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMCharacterDataVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMCharacterData, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMCharacterData
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMCharacterData
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMCharacterData, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMCharacterData, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMCharacterData, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMCharacterData, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMCharacterData, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMCharacterData, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMCharacterData, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMCharacterData, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMCharacterData, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMCharacterData, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMCharacterData, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMCharacterData, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMCharacterData, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMCharacterData, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMCharacterData, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMCharacterData, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMCharacterData, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMCharacterData, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_data)
            STD_METHOD get_data, :ptr IXMLDOMCharacterData, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, put_data)
            STD_METHOD put_data, :ptr IXMLDOMCharacterData, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_length)
            STD_METHOD get_length, :ptr IXMLDOMCharacterData, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, substringData)
            STD_METHOD substringData, :ptr IXMLDOMCharacterData, :SDWORD, :SDWORD, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, appendData)
            STD_METHOD appendData, :ptr IXMLDOMCharacterData, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, insertData)
            STD_METHOD insertData, :ptr IXMLDOMCharacterData, :SDWORD, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, deleteData)
            STD_METHOD deleteData, :ptr IXMLDOMCharacterData, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, replaceData)
            STD_METHOD replaceData, :ptr IXMLDOMCharacterData, :SDWORD, :SDWORD, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMCharacterDataVtbl ends
          IXMLDOMCharacterData struct
            lpVtbl POINTER ?
          IXMLDOMCharacterData ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMAttribute_INTERFACE_DEFINED__
        __IXMLDOMAttribute_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMAttribute:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMAttributeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMAttributeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMAttribute, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMAttribute
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMAttribute
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMAttribute, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMAttribute, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMAttribute, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMAttribute, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMAttribute, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMAttribute, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMAttribute, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMAttribute, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMAttribute, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMAttribute, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMAttribute, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMAttribute, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMAttribute, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMAttribute, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMAttribute, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMAttribute, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMAttribute, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMAttribute, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMAttribute, get_name)
            STD_METHOD get_name, :ptr IXMLDOMAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMAttribute, get_value)
            STD_METHOD get_value, :ptr IXMLDOMAttribute, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMAttribute, put_value)
            STD_METHOD put_value, :ptr IXMLDOMAttribute, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMAttributeVtbl ends
          IXMLDOMAttribute struct
            lpVtbl POINTER ?
          IXMLDOMAttribute ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMElement_INTERFACE_DEFINED__
        __IXMLDOMElement_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMElement:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMElementVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMElementVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMElement, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMElement
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMElement
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMElement, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMElement, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMElement, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMElement, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMElement, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMElement, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMElement, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMElement, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMElement, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMElement, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMElement, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMElement, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMElement, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMElement, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMElement, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMElement, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMElement, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMElement, get_tagName)
            STD_METHOD get_tagName, :ptr IXMLDOMElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMElement, getAttribute)
            STD_METHOD getAttribute, :ptr IXMLDOMElement, :BSTR, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMElement, setAttribute)
            STD_METHOD setAttribute, :ptr IXMLDOMElement, :BSTR, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMElement, removeAttribute)
            STD_METHOD removeAttribute, :ptr IXMLDOMElement, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMElement, getAttributeNode)
            STD_METHOD getAttributeNode, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMAttribute
            DECLSPEC_XFGVIRT(IXMLDOMElement, setAttributeNode)
            STD_METHOD setAttributeNode, :ptr IXMLDOMElement, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMAttribute
            DECLSPEC_XFGVIRT(IXMLDOMElement, removeAttributeNode)
            STD_METHOD removeAttributeNode, :ptr IXMLDOMElement, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMAttribute
            DECLSPEC_XFGVIRT(IXMLDOMElement, getElementsByTagName)
            STD_METHOD getElementsByTagName, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMElement, normalize)
            STD_METHOD normalize, :ptr IXMLDOMElement
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMElementVtbl ends
          IXMLDOMElement struct
            lpVtbl POINTER ?
          IXMLDOMElement ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMText_INTERFACE_DEFINED__
        __IXMLDOMText_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMText:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMTextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMTextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMText, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMText
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMText
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMText, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMText, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMText, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMText, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMText, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMText, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMText, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMText, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMText, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMText, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMText, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMText, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMText, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMText, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMText, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMText, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMText, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMText, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMText, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMText, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMText, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMText, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMText, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_data)
            STD_METHOD get_data, :ptr IXMLDOMText, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, put_data)
            STD_METHOD put_data, :ptr IXMLDOMText, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_length)
            STD_METHOD get_length, :ptr IXMLDOMText, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, substringData)
            STD_METHOD substringData, :ptr IXMLDOMText, :SDWORD, :SDWORD, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, appendData)
            STD_METHOD appendData, :ptr IXMLDOMText, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, insertData)
            STD_METHOD insertData, :ptr IXMLDOMText, :SDWORD, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, deleteData)
            STD_METHOD deleteData, :ptr IXMLDOMText, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, replaceData)
            STD_METHOD replaceData, :ptr IXMLDOMText, :SDWORD, :SDWORD, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMText, splitText)
            STD_METHOD splitText, :ptr IXMLDOMText, :SDWORD, :ptr ptr IXMLDOMText
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMTextVtbl ends
          IXMLDOMText struct
            lpVtbl POINTER ?
          IXMLDOMText ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMComment_INTERFACE_DEFINED__
        __IXMLDOMComment_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMComment:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMCommentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMCommentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMComment, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMComment
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMComment
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMComment, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMComment, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMComment, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMComment, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMComment, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMComment, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMComment, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMComment, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMComment, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMComment, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMComment, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMComment, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMComment, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMComment, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMComment, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMComment, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMComment, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMComment, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMComment, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_data)
            STD_METHOD get_data, :ptr IXMLDOMComment, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, put_data)
            STD_METHOD put_data, :ptr IXMLDOMComment, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_length)
            STD_METHOD get_length, :ptr IXMLDOMComment, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, substringData)
            STD_METHOD substringData, :ptr IXMLDOMComment, :SDWORD, :SDWORD, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, appendData)
            STD_METHOD appendData, :ptr IXMLDOMComment, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, insertData)
            STD_METHOD insertData, :ptr IXMLDOMComment, :SDWORD, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, deleteData)
            STD_METHOD deleteData, :ptr IXMLDOMComment, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, replaceData)
            STD_METHOD replaceData, :ptr IXMLDOMComment, :SDWORD, :SDWORD, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMCommentVtbl ends
          IXMLDOMComment struct
            lpVtbl POINTER ?
          IXMLDOMComment ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMProcessingInstruction_INTERFACE_DEFINED__
        __IXMLDOMProcessingInstruction_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMProcessingInstruction:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMProcessingInstructionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMProcessingInstructionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMProcessingInstruction, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMProcessingInstruction
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMProcessingInstruction
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMProcessingInstruction, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMProcessingInstruction, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMProcessingInstruction, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMProcessingInstruction, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMProcessingInstruction, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMProcessingInstruction, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMProcessingInstruction, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMProcessingInstruction, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMProcessingInstruction, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMProcessingInstruction, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMProcessingInstruction, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMProcessingInstruction, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMProcessingInstruction, get_target)
            STD_METHOD get_target, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMProcessingInstruction, get_data)
            STD_METHOD get_data, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMProcessingInstruction, put_data)
            STD_METHOD put_data, :ptr IXMLDOMProcessingInstruction, :BSTR
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMProcessingInstructionVtbl ends
          IXMLDOMProcessingInstruction struct
            lpVtbl POINTER ?
          IXMLDOMProcessingInstruction ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMCDATASection_INTERFACE_DEFINED__
        __IXMLDOMCDATASection_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMCDATASection:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMCDATASectionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMCDATASectionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMCDATASection, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMCDATASection
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMCDATASection
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMCDATASection, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMCDATASection, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMCDATASection, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMCDATASection, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMCDATASection, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMCDATASection, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMCDATASection, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMCDATASection, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMCDATASection, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMCDATASection, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMCDATASection, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMCDATASection, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMCDATASection, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMCDATASection, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMCDATASection, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMCDATASection, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMCDATASection, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMCDATASection, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_data)
            STD_METHOD get_data, :ptr IXMLDOMCDATASection, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, put_data)
            STD_METHOD put_data, :ptr IXMLDOMCDATASection, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, get_length)
            STD_METHOD get_length, :ptr IXMLDOMCDATASection, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, substringData)
            STD_METHOD substringData, :ptr IXMLDOMCDATASection, :SDWORD, :SDWORD, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, appendData)
            STD_METHOD appendData, :ptr IXMLDOMCDATASection, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, insertData)
            STD_METHOD insertData, :ptr IXMLDOMCDATASection, :SDWORD, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, deleteData)
            STD_METHOD deleteData, :ptr IXMLDOMCDATASection, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMCharacterData, replaceData)
            STD_METHOD replaceData, :ptr IXMLDOMCDATASection, :SDWORD, :SDWORD, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMText, splitText)
            STD_METHOD splitText, :ptr IXMLDOMCDATASection, :SDWORD, :ptr ptr IXMLDOMText
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMCDATASectionVtbl ends
          IXMLDOMCDATASection struct
            lpVtbl POINTER ?
          IXMLDOMCDATASection ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMDocumentType_INTERFACE_DEFINED__
        __IXMLDOMDocumentType_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMDocumentType:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMDocumentTypeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMDocumentTypeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMDocumentType, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMDocumentType
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMDocumentType
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMDocumentType, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMDocumentType, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMDocumentType, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMDocumentType, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMDocumentType, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMDocumentType, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMDocumentType, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMDocumentType, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMDocumentType, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMDocumentType, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMDocumentType, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMDocumentType, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMDocumentType, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMDocumentType, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMDocumentType, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMDocumentType, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMDocumentType, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMDocumentType, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMDocumentType, get_name)
            STD_METHOD get_name, :ptr IXMLDOMDocumentType, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMDocumentType, get_entities)
            STD_METHOD get_entities, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMDocumentType, get_notations)
            STD_METHOD get_notations, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNamedNodeMap
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMDocumentTypeVtbl ends
          IXMLDOMDocumentType struct
            lpVtbl POINTER ?
          IXMLDOMDocumentType ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMNotation_INTERFACE_DEFINED__
        __IXMLDOMNotation_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMNotation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMNotationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMNotationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMNotation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMNotation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMNotation
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNotation, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNotation, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNotation, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMNotation, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMNotation, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMNotation, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMNotation, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMNotation, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMNotation, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMNotation, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMNotation, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMNotation, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMNotation, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMNotation, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMNotation, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMNotation, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMNotation, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMNotation, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMNotation, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNotation, get_publicId)
            STD_METHOD get_publicId, :ptr IXMLDOMNotation, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNotation, get_systemId)
            STD_METHOD get_systemId, :ptr IXMLDOMNotation, :ptr VARIANT
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMNotationVtbl ends
          IXMLDOMNotation struct
            lpVtbl POINTER ?
          IXMLDOMNotation ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMEntity_INTERFACE_DEFINED__
        __IXMLDOMEntity_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMEntity:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMEntityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMEntityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMEntity, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMEntity
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMEntity
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMEntity, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMEntity, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMEntity, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMEntity, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMEntity, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMEntity, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMEntity, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMEntity, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMEntity, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMEntity, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMEntity, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMEntity, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMEntity, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMEntity, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMEntity, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMEntity, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMEntity, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMEntity, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMEntity, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMEntity, get_publicId)
            STD_METHOD get_publicId, :ptr IXMLDOMEntity, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMEntity, get_systemId)
            STD_METHOD get_systemId, :ptr IXMLDOMEntity, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMEntity, get_notationName)
            STD_METHOD get_notationName, :ptr IXMLDOMEntity, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMEntityVtbl ends
          IXMLDOMEntity struct
            lpVtbl POINTER ?
          IXMLDOMEntity ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMEntityReference_INTERFACE_DEFINED__
        __IXMLDOMEntityReference_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMEntityReference:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMEntityReferenceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMEntityReferenceVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMEntityReference, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMEntityReference
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMEntityReference
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMEntityReference, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMEntityReference, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMEntityReference, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMEntityReference, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXMLDOMEntityReference, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXMLDOMEntityReference, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXMLDOMEntityReference, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXMLDOMEntityReference, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXMLDOMEntityReference, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXMLDOMEntityReference, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXMLDOMEntityReference, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMEntityReference, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMEntityReference, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXMLDOMEntityReference, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXMLDOMEntityReference, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXMLDOMEntityReference, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXMLDOMEntityReference, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXMLDOMEntityReference, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXMLDOMEntityReference, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :VARIANT
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMEntityReferenceVtbl ends
          IXMLDOMEntityReference struct
            lpVtbl POINTER ?
          IXMLDOMEntityReference ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDOMParseError_INTERFACE_DEFINED__
        __IXMLDOMParseError_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDOMParseError:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDOMParseErrorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDOMParseErrorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDOMParseError, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDOMParseError
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDOMParseError
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMParseError, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDOMParseError, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMParseError, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDOMParseError, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_errorCode)
            STD_METHOD get_errorCode, :ptr IXMLDOMParseError, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_url)
            STD_METHOD get_url, :ptr IXMLDOMParseError, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_reason)
            STD_METHOD get_reason, :ptr IXMLDOMParseError, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_srcText)
            STD_METHOD get_srcText, :ptr IXMLDOMParseError, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_line)
            STD_METHOD get_line, :ptr IXMLDOMParseError, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_linepos)
            STD_METHOD get_linepos, :ptr IXMLDOMParseError, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDOMParseError, get_filepos)
            STD_METHOD get_filepos, :ptr IXMLDOMParseError, :ptr SDWORD
            ??Interface equ <>
            END_INTERFACE
          IXMLDOMParseErrorVtbl ends
          IXMLDOMParseError struct
            lpVtbl POINTER ?
          IXMLDOMParseError ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXTLRuntime_INTERFACE_DEFINED__
        __IXTLRuntime_INTERFACE_DEFINED__ equ <>
        externdef IID_IXTLRuntime:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXTLRuntimeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXTLRuntimeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXTLRuntime, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXTLRuntime
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXTLRuntime
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXTLRuntime, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXTLRuntime, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXTLRuntime, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXTLRuntime, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeName)
            STD_METHOD get_nodeName, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeValue)
            STD_METHOD get_nodeValue, :ptr IXTLRuntime, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeValue)
            STD_METHOD put_nodeValue, :ptr IXTLRuntime, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeType)
            STD_METHOD get_nodeType, :ptr IXTLRuntime, :ptr DOMNodeType
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parentNode)
            STD_METHOD get_parentNode, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_childNodes)
            STD_METHOD get_childNodes, :ptr IXTLRuntime, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_firstChild)
            STD_METHOD get_firstChild, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_lastChild)
            STD_METHOD get_lastChild, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_previousSibling)
            STD_METHOD get_previousSibling, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nextSibling)
            STD_METHOD get_nextSibling, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_attributes)
            STD_METHOD get_attributes, :ptr IXTLRuntime, :ptr ptr IXMLDOMNamedNodeMap
            DECLSPEC_XFGVIRT(IXMLDOMNode, insertBefore)
            STD_METHOD insertBefore, :ptr IXTLRuntime, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, replaceChild)
            STD_METHOD replaceChild, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, removeChild)
            STD_METHOD removeChild, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, appendChild)
            STD_METHOD appendChild, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, hasChildNodes)
            STD_METHOD hasChildNodes, :ptr IXTLRuntime, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_ownerDocument)
            STD_METHOD get_ownerDocument, :ptr IXTLRuntime, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDOMNode, cloneNode)
            STD_METHOD cloneNode, :ptr IXTLRuntime, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypeString)
            STD_METHOD get_nodeTypeString, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_text)
            STD_METHOD get_text, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_text)
            STD_METHOD put_text, :ptr IXTLRuntime, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_specified)
            STD_METHOD get_specified, :ptr IXTLRuntime, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_definition)
            STD_METHOD get_definition, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_nodeTypedValue)
            STD_METHOD get_nodeTypedValue, :ptr IXTLRuntime, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_nodeTypedValue)
            STD_METHOD put_nodeTypedValue, :ptr IXTLRuntime, :VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_dataType)
            STD_METHOD get_dataType, :ptr IXTLRuntime, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLDOMNode, put_dataType)
            STD_METHOD put_dataType, :ptr IXTLRuntime, :BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_xml)
            STD_METHOD get_xml, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNode)
            STD_METHOD transformNode, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectNodes)
            STD_METHOD selectNodes, :ptr IXTLRuntime, :BSTR, :ptr ptr IXMLDOMNodeList
            DECLSPEC_XFGVIRT(IXMLDOMNode, selectSingleNode)
            STD_METHOD selectSingleNode, :ptr IXTLRuntime, :BSTR, :ptr ptr IXMLDOMNode
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_parsed)
            STD_METHOD get_parsed, :ptr IXTLRuntime, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_namespaceURI)
            STD_METHOD get_namespaceURI, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_prefix)
            STD_METHOD get_prefix, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, get_baseName)
            STD_METHOD get_baseName, :ptr IXTLRuntime, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDOMNode, transformNodeToObject)
            STD_METHOD transformNodeToObject, :ptr IXTLRuntime, :ptr IXMLDOMNode, :VARIANT
            DECLSPEC_XFGVIRT(IXTLRuntime, uniqueID)
            STD_METHOD uniqueID, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXTLRuntime, depth)
            STD_METHOD depth, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXTLRuntime, childNumber)
            STD_METHOD childNumber, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXTLRuntime, ancestorChildNumber)
            STD_METHOD ancestorChildNumber, :ptr IXTLRuntime, :BSTR, :ptr IXMLDOMNode, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXTLRuntime, absoluteChildNumber)
            STD_METHOD absoluteChildNumber, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXTLRuntime, formatIndex)
            STD_METHOD formatIndex, :ptr IXTLRuntime, :SDWORD, :BSTR, :ptr BSTR
            DECLSPEC_XFGVIRT(IXTLRuntime, formatNumber)
            STD_METHOD formatNumber, :ptr IXTLRuntime, :REAL8, :BSTR, :ptr BSTR
            DECLSPEC_XFGVIRT(IXTLRuntime, formatDate)
            STD_METHOD formatDate, :ptr IXTLRuntime, :VARIANT, :BSTR, :VARIANT, :ptr BSTR
            DECLSPEC_XFGVIRT(IXTLRuntime, formatTime)
            STD_METHOD formatTime, :ptr IXTLRuntime, :VARIANT, :BSTR, :VARIANT, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IXTLRuntimeVtbl ends
          IXTLRuntime struct
            lpVtbl POINTER ?
          IXTLRuntime ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __XMLDOMDocumentEvents_DISPINTERFACE_DEFINED__
        __XMLDOMDocumentEvents_DISPINTERFACE_DEFINED__ equ <>
        externdef DIID_XMLDOMDocumentEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          XMLDOMDocumentEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <XMLDOMDocumentEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr XMLDOMDocumentEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr XMLDOMDocumentEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr XMLDOMDocumentEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr XMLDOMDocumentEvents, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr XMLDOMDocumentEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr XMLDOMDocumentEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr XMLDOMDocumentEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          XMLDOMDocumentEventsVtbl ends
          XMLDOMDocumentEvents struct
            lpVtbl POINTER ?
          XMLDOMDocumentEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_DOMDocument:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_DOMFreeThreadedDocument:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IXMLHttpRequest_INTERFACE_DEFINED__
        __IXMLHttpRequest_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLHttpRequest:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLHttpRequestVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLHttpRequestVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLHttpRequest, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLHttpRequest
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLHttpRequest
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLHttpRequest, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLHttpRequest, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLHttpRequest, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLHttpRequest, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLHttpRequest, open)
            STD_METHOD open, :ptr IXMLHttpRequest, :BSTR, :BSTR, :VARIANT, :VARIANT, :VARIANT
            DECLSPEC_XFGVIRT(IXMLHttpRequest, setRequestHeader)
            STD_METHOD setRequestHeader, :ptr IXMLHttpRequest, :BSTR, :BSTR
            DECLSPEC_XFGVIRT(IXMLHttpRequest, getResponseHeader)
            STD_METHOD getResponseHeader, :ptr IXMLHttpRequest, :BSTR, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLHttpRequest, getAllResponseHeaders)
            STD_METHOD getAllResponseHeaders, :ptr IXMLHttpRequest, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLHttpRequest, send)
            STD_METHOD send, :ptr IXMLHttpRequest, :VARIANT
            DECLSPEC_XFGVIRT(IXMLHttpRequest, abort)
            STD_METHOD abort, :ptr IXMLHttpRequest
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_status)
            STD_METHOD get_status, :ptr IXMLHttpRequest, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_statusText)
            STD_METHOD get_statusText, :ptr IXMLHttpRequest, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_responseXML)
            STD_METHOD get_responseXML, :ptr IXMLHttpRequest, :ptr ptr IDispatch
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_responseText)
            STD_METHOD get_responseText, :ptr IXMLHttpRequest, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_responseBody)
            STD_METHOD get_responseBody, :ptr IXMLHttpRequest, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_responseStream)
            STD_METHOD get_responseStream, :ptr IXMLHttpRequest, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLHttpRequest, get_readyState)
            STD_METHOD get_readyState, :ptr IXMLHttpRequest, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLHttpRequest, put_onreadystatechange)
            STD_METHOD put_onreadystatechange, :ptr IXMLHttpRequest, :ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IXMLHttpRequestVtbl ends
          IXMLHttpRequest struct
            lpVtbl POINTER ?
          IXMLHttpRequest ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_XMLHTTPRequest:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IXMLDSOControl_INTERFACE_DEFINED__
        __IXMLDSOControl_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDSOControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDSOControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDSOControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDSOControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDSOControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDSOControl
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDSOControl, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDSOControl, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDSOControl, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDSOControl, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDSOControl, get_XMLDocument)
            STD_METHOD get_XMLDocument, :ptr IXMLDSOControl, :ptr ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDSOControl, put_XMLDocument)
            STD_METHOD put_XMLDocument, :ptr IXMLDSOControl, :ptr IXMLDOMDocument
            DECLSPEC_XFGVIRT(IXMLDSOControl, get_JavaDSOCompatible)
            STD_METHOD get_JavaDSOCompatible, :ptr IXMLDSOControl, :ptr BOOL
            DECLSPEC_XFGVIRT(IXMLDSOControl, put_JavaDSOCompatible)
            STD_METHOD put_JavaDSOCompatible, :ptr IXMLDSOControl, :BOOL
            DECLSPEC_XFGVIRT(IXMLDSOControl, get_readyState)
            STD_METHOD get_readyState, :ptr IXMLDSOControl, :ptr SDWORD
            ??Interface equ <>
            END_INTERFACE
          IXMLDSOControlVtbl ends
          IXMLDSOControl struct
            lpVtbl POINTER ?
          IXMLDSOControl ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_XMLDSOControl:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IXMLElementCollection_INTERFACE_DEFINED__
        __IXMLElementCollection_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLElementCollection:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLElementCollectionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLElementCollectionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLElementCollection, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLElementCollection
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLElementCollection
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLElementCollection, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLElementCollection, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLElementCollection, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLElementCollection, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLElementCollection, put_length)
            STD_METHOD put_length, :ptr IXMLElementCollection, :SDWORD
            DECLSPEC_XFGVIRT(IXMLElementCollection, get_length)
            STD_METHOD get_length, :ptr IXMLElementCollection, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLElementCollection, get__newEnum)
            STD_METHOD get__newEnum, :ptr IXMLElementCollection, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IXMLElementCollection, item)
            STD_METHOD item, :ptr IXMLElementCollection, :VARIANT, :VARIANT, :ptr ptr IDispatch
            ??Interface equ <>
            END_INTERFACE
          IXMLElementCollectionVtbl ends
          IXMLElementCollection struct
            lpVtbl POINTER ?
          IXMLElementCollection ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDocument_INTERFACE_DEFINED__
        __IXMLDocument_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDocument:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDocumentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDocumentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDocument, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDocument
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDocument
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDocument, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDocument, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDocument, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDocument, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDocument, get_root)
            STD_METHOD get_root, :ptr IXMLDocument, :ptr ptr IXMLElement
            DECLSPEC_XFGVIRT(IXMLDocument, get_fileSize)
            STD_METHOD get_fileSize, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_fileModifiedDate)
            STD_METHOD get_fileModifiedDate, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_fileUpdatedDate)
            STD_METHOD get_fileUpdatedDate, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_URL)
            STD_METHOD get_URL, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, put_URL)
            STD_METHOD put_URL, :ptr IXMLDocument, :BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_mimeType)
            STD_METHOD get_mimeType, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_readyState)
            STD_METHOD get_readyState, :ptr IXMLDocument, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDocument, get_charset)
            STD_METHOD get_charset, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, put_charset)
            STD_METHOD put_charset, :ptr IXMLDocument, :BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_version)
            STD_METHOD get_version, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_doctype)
            STD_METHOD get_doctype, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, get_dtdURL)
            STD_METHOD get_dtdURL, :ptr IXMLDocument, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument, createElement)
            STD_METHOD createElement, :ptr IXMLDocument, :VARIANT, :VARIANT, :ptr ptr IXMLElement
            ??Interface equ <>
            END_INTERFACE
          IXMLDocumentVtbl ends
          IXMLDocument struct
            lpVtbl POINTER ?
          IXMLDocument ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLDocument2_INTERFACE_DEFINED__
        __IXMLDocument2_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLDocument2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLDocument2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLDocument2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLDocument2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLDocument2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLDocument2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLDocument2, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLDocument2, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLDocument2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLDocument2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLDocument2, get_root)
            STD_METHOD get_root, :ptr IXMLDocument2, :ptr ptr IXMLElement2
            DECLSPEC_XFGVIRT(IXMLDocument2, get_fileSize)
            STD_METHOD get_fileSize, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_fileModifiedDate)
            STD_METHOD get_fileModifiedDate, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_fileUpdatedDate)
            STD_METHOD get_fileUpdatedDate, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_URL)
            STD_METHOD get_URL, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, put_URL)
            STD_METHOD put_URL, :ptr IXMLDocument2, :BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_mimeType)
            STD_METHOD get_mimeType, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_readyState)
            STD_METHOD get_readyState, :ptr IXMLDocument2, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLDocument2, get_charset)
            STD_METHOD get_charset, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, put_charset)
            STD_METHOD put_charset, :ptr IXMLDocument2, :BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_version)
            STD_METHOD get_version, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_doctype)
            STD_METHOD get_doctype, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, get_dtdURL)
            STD_METHOD get_dtdURL, :ptr IXMLDocument2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLDocument2, createElement)
            STD_METHOD createElement, :ptr IXMLDocument2, :VARIANT, :VARIANT, :ptr ptr IXMLElement2
            DECLSPEC_XFGVIRT(IXMLDocument2, get_async)
            STD_METHOD get_async, :ptr IXMLDocument2, :ptr VARIANT_BOOL
            DECLSPEC_XFGVIRT(IXMLDocument2, put_async)
            STD_METHOD put_async, :ptr IXMLDocument2, :VARIANT_BOOL
            ??Interface equ <>
            END_INTERFACE
          IXMLDocument2Vtbl ends
          IXMLDocument2 struct
            lpVtbl POINTER ?
          IXMLDocument2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLElement_INTERFACE_DEFINED__
        __IXMLElement_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLElement:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLElementVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLElementVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLElement, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLElement
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLElement
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLElement, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLElement, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLElement, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLElement, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLElement, get_tagName)
            STD_METHOD get_tagName, :ptr IXMLElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLElement, put_tagName)
            STD_METHOD put_tagName, :ptr IXMLElement, :BSTR
            DECLSPEC_XFGVIRT(IXMLElement, get_parent)
            STD_METHOD get_parent, :ptr IXMLElement, :ptr ptr IXMLElement
            DECLSPEC_XFGVIRT(IXMLElement, setAttribute)
            STD_METHOD setAttribute, :ptr IXMLElement, :BSTR, :VARIANT
            DECLSPEC_XFGVIRT(IXMLElement, getAttribute)
            STD_METHOD getAttribute, :ptr IXMLElement, :BSTR, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLElement, removeAttribute)
            STD_METHOD removeAttribute, :ptr IXMLElement, :BSTR
            DECLSPEC_XFGVIRT(IXMLElement, get_children)
            STD_METHOD get_children, :ptr IXMLElement, :ptr ptr IXMLElementCollection
            DECLSPEC_XFGVIRT(IXMLElement, get_type)
            STD_METHOD get_type, :ptr IXMLElement, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLElement, get_text)
            STD_METHOD get_text, :ptr IXMLElement, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLElement, put_text)
            STD_METHOD put_text, :ptr IXMLElement, :BSTR
            DECLSPEC_XFGVIRT(IXMLElement, addChild)
            STD_METHOD addChild, :ptr IXMLElement, :ptr IXMLElement, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(IXMLElement, removeChild)
            STD_METHOD removeChild, :ptr IXMLElement, :ptr IXMLElement
            ??Interface equ <>
            END_INTERFACE
          IXMLElementVtbl ends
          IXMLElement struct
            lpVtbl POINTER ?
          IXMLElement ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLElement2_INTERFACE_DEFINED__
        __IXMLElement2_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLElement2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLElement2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLElement2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLElement2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLElement2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLElement2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLElement2, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLElement2, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLElement2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLElement2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLElement2, get_tagName)
            STD_METHOD get_tagName, :ptr IXMLElement2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLElement2, put_tagName)
            STD_METHOD put_tagName, :ptr IXMLElement2, :BSTR
            DECLSPEC_XFGVIRT(IXMLElement2, get_parent)
            STD_METHOD get_parent, :ptr IXMLElement2, :ptr ptr IXMLElement2
            DECLSPEC_XFGVIRT(IXMLElement2, setAttribute)
            STD_METHOD setAttribute, :ptr IXMLElement2, :BSTR, :VARIANT
            DECLSPEC_XFGVIRT(IXMLElement2, getAttribute)
            STD_METHOD getAttribute, :ptr IXMLElement2, :BSTR, :ptr VARIANT
            DECLSPEC_XFGVIRT(IXMLElement2, removeAttribute)
            STD_METHOD removeAttribute, :ptr IXMLElement2, :BSTR
            DECLSPEC_XFGVIRT(IXMLElement2, get_children)
            STD_METHOD get_children, :ptr IXMLElement2, :ptr ptr IXMLElementCollection
            DECLSPEC_XFGVIRT(IXMLElement2, get_type)
            STD_METHOD get_type, :ptr IXMLElement2, :ptr SDWORD
            DECLSPEC_XFGVIRT(IXMLElement2, get_text)
            STD_METHOD get_text, :ptr IXMLElement2, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLElement2, put_text)
            STD_METHOD put_text, :ptr IXMLElement2, :BSTR
            DECLSPEC_XFGVIRT(IXMLElement2, addChild)
            STD_METHOD addChild, :ptr IXMLElement2, :ptr IXMLElement2, :SDWORD, :SDWORD
            DECLSPEC_XFGVIRT(IXMLElement2, removeChild)
            STD_METHOD removeChild, :ptr IXMLElement2, :ptr IXMLElement2
            DECLSPEC_XFGVIRT(IXMLElement2, get_attributes)
            STD_METHOD get_attributes, :ptr IXMLElement2, :ptr ptr IXMLElementCollection
            ??Interface equ <>
            END_INTERFACE
          IXMLElement2Vtbl ends
          IXMLElement2 struct
            lpVtbl POINTER ?
          IXMLElement2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLAttribute_INTERFACE_DEFINED__
        __IXMLAttribute_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLAttribute:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLAttributeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLAttributeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLAttribute, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLAttribute
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLAttribute
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IXMLAttribute, :ptr UINT
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            STD_METHOD GetTypeInfo, :ptr IXMLAttribute, :UINT, :LCID, :ptr ptr ITypeInfo
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            STD_METHOD GetIDsOfNames, :ptr IXMLAttribute, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            STD_METHOD Invoke_, :ptr IXMLAttribute, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IXMLAttribute, get_name)
            STD_METHOD get_name, :ptr IXMLAttribute, :ptr BSTR
            DECLSPEC_XFGVIRT(IXMLAttribute, get_value)
            STD_METHOD get_value, :ptr IXMLAttribute, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IXMLAttributeVtbl ends
          IXMLAttribute struct
            lpVtbl POINTER ?
          IXMLAttribute ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IXMLError_INTERFACE_DEFINED__
        __IXMLError_INTERFACE_DEFINED__ equ <>
        externdef IID_IXMLError:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IXMLErrorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IXMLErrorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IXMLError, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IXMLError
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IXMLError
            DECLSPEC_XFGVIRT(IXMLError, GetErrorInfo)
            STD_METHOD GetErrorInfo, :ptr IXMLError, :ptr XML_ERROR
            ??Interface equ <>
            END_INTERFACE
          IXMLErrorVtbl ends
          IXMLError struct
            lpVtbl POINTER ?
          IXMLError ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_XMLDocument:CLSID
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_msxml_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_msxml_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif
