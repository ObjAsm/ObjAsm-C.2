;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\msxml.h', last modified: 19/04/2018 10:45
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
ifndef __msxml_h__
  __msxml_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IXMLDOMImplementation_FWD_DEFINED__
    __IXMLDOMImplementation_FWD_DEFINED__ equ <>
    ;IXMLDOMImplementation typedef IXMLDOMImplementation
    
  endif
  ifndef __IXMLDOMNode_FWD_DEFINED__
    __IXMLDOMNode_FWD_DEFINED__ equ <>
    ;IXMLDOMNode typedef IXMLDOMNode
    
  endif
  ifndef __IXMLDOMDocumentFragment_FWD_DEFINED__
    __IXMLDOMDocumentFragment_FWD_DEFINED__ equ <>
    ;IXMLDOMDocumentFragment typedef IXMLDOMDocumentFragment
    
  endif
  ifndef __IXMLDOMDocument_FWD_DEFINED__
    __IXMLDOMDocument_FWD_DEFINED__ equ <>
    ;IXMLDOMDocument typedef IXMLDOMDocument
    
  endif
  ifndef __IXMLDOMNodeList_FWD_DEFINED__
    __IXMLDOMNodeList_FWD_DEFINED__ equ <>
    ;IXMLDOMNodeList typedef IXMLDOMNodeList
    
  endif
  ifndef __IXMLDOMNamedNodeMap_FWD_DEFINED__
    __IXMLDOMNamedNodeMap_FWD_DEFINED__ equ <>
    ;IXMLDOMNamedNodeMap typedef IXMLDOMNamedNodeMap
    
  endif
  ifndef __IXMLDOMCharacterData_FWD_DEFINED__
    __IXMLDOMCharacterData_FWD_DEFINED__ equ <>
    ;IXMLDOMCharacterData typedef IXMLDOMCharacterData
    
  endif
  ifndef __IXMLDOMAttribute_FWD_DEFINED__
    __IXMLDOMAttribute_FWD_DEFINED__ equ <>
    ;IXMLDOMAttribute typedef IXMLDOMAttribute
    
  endif
  ifndef __IXMLDOMElement_FWD_DEFINED__
    __IXMLDOMElement_FWD_DEFINED__ equ <>
    ;IXMLDOMElement typedef IXMLDOMElement
    
  endif
  ifndef __IXMLDOMText_FWD_DEFINED__
    __IXMLDOMText_FWD_DEFINED__ equ <>
    ;IXMLDOMText typedef IXMLDOMText
    
  endif
  ifndef __IXMLDOMComment_FWD_DEFINED__
    __IXMLDOMComment_FWD_DEFINED__ equ <>
    ;IXMLDOMComment typedef IXMLDOMComment
    
  endif
  ifndef __IXMLDOMProcessingInstruction_FWD_DEFINED__
    __IXMLDOMProcessingInstruction_FWD_DEFINED__ equ <>
    ;IXMLDOMProcessingInstruction typedef IXMLDOMProcessingInstruction
    
  endif
  ifndef __IXMLDOMCDATASection_FWD_DEFINED__
    __IXMLDOMCDATASection_FWD_DEFINED__ equ <>
    ;IXMLDOMCDATASection typedef IXMLDOMCDATASection
    
  endif
  ifndef __IXMLDOMDocumentType_FWD_DEFINED__
    __IXMLDOMDocumentType_FWD_DEFINED__ equ <>
    ;IXMLDOMDocumentType typedef IXMLDOMDocumentType
    
  endif
  ifndef __IXMLDOMNotation_FWD_DEFINED__
    __IXMLDOMNotation_FWD_DEFINED__ equ <>
    ;IXMLDOMNotation typedef IXMLDOMNotation
    
  endif
  ifndef __IXMLDOMEntity_FWD_DEFINED__
    __IXMLDOMEntity_FWD_DEFINED__ equ <>
    ;IXMLDOMEntity typedef IXMLDOMEntity
    
  endif
  ifndef __IXMLDOMEntityReference_FWD_DEFINED__
    __IXMLDOMEntityReference_FWD_DEFINED__ equ <>
    ;IXMLDOMEntityReference typedef IXMLDOMEntityReference
    
  endif
  ifndef __IXMLDOMParseError_FWD_DEFINED__
    __IXMLDOMParseError_FWD_DEFINED__ equ <>
    ;IXMLDOMParseError typedef IXMLDOMParseError
    
  endif
  ifndef __IXTLRuntime_FWD_DEFINED__
    __IXTLRuntime_FWD_DEFINED__ equ <>
    ;IXTLRuntime typedef IXTLRuntime
    
  endif
  ifndef __XMLDOMDocumentEvents_FWD_DEFINED__
    __XMLDOMDocumentEvents_FWD_DEFINED__ equ <>
    ;XMLDOMDocumentEvents typedef XMLDOMDocumentEvents
    
  endif
  ifndef __DOMDocument_FWD_DEFINED__
    __DOMDocument_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DOMDocument typedef DOMDocument
      
    endif
  endif
  ifndef __DOMFreeThreadedDocument_FWD_DEFINED__
    __DOMFreeThreadedDocument_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;DOMFreeThreadedDocument typedef DOMFreeThreadedDocument
      
    endif
  endif
  ifndef __IXMLHttpRequest_FWD_DEFINED__
    __IXMLHttpRequest_FWD_DEFINED__ equ <>
    ;IXMLHttpRequest typedef IXMLHttpRequest
    
  endif
  ifndef __XMLHTTPRequest_FWD_DEFINED__
    __XMLHTTPRequest_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;XMLHTTPRequest typedef XMLHTTPRequest
      
    endif
  endif
  ifndef __IXMLDSOControl_FWD_DEFINED__
    __IXMLDSOControl_FWD_DEFINED__ equ <>
    ;IXMLDSOControl typedef IXMLDSOControl
    
  endif
  ifndef __XMLDSOControl_FWD_DEFINED__
    __XMLDSOControl_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;XMLDSOControl typedef XMLDSOControl
      
    endif
  endif
  ifndef __IXMLElementCollection_FWD_DEFINED__
    __IXMLElementCollection_FWD_DEFINED__ equ <>
    ;IXMLElementCollection typedef IXMLElementCollection
    
  endif
  ifndef __IXMLDocument_FWD_DEFINED__
    __IXMLDocument_FWD_DEFINED__ equ <>
    ;IXMLDocument typedef IXMLDocument
    
  endif
  ifndef __IXMLDocument2_FWD_DEFINED__
    __IXMLDocument2_FWD_DEFINED__ equ <>
    ;IXMLDocument2 typedef IXMLDocument2
    
  endif
  ifndef __IXMLElement_FWD_DEFINED__
    __IXMLElement_FWD_DEFINED__ equ <>
    ;IXMLElement typedef IXMLElement
    
  endif
  ifndef __IXMLElement2_FWD_DEFINED__
    __IXMLElement2_FWD_DEFINED__ equ <>
    ;IXMLElement2 typedef IXMLElement2
    
  endif
  ifndef __IXMLAttribute_FWD_DEFINED__
    __IXMLAttribute_FWD_DEFINED__ equ <>
    ;IXMLAttribute typedef IXMLAttribute
    
  endif
  ifndef __IXMLError_FWD_DEFINED__
    __IXMLError_FWD_DEFINED__ equ <>
    ;IXMLError typedef IXMLError
    
  endif
  ifndef __XMLDocument_FWD_DEFINED__
    __XMLDocument_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;XMLDocument typedef XMLDocument
      
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
      DOMNodeType typedef SDWORD
      NODE_INVALID equ 0
      NODE_ELEMENT equ 1
      NODE_ATTRIBUTE equ 2
      NODE_TEXT equ 3
      NODE_CDATA_SECTION equ 4
      NODE_ENTITY_REFERENCE equ 5
      NODE_ENTITY equ 6
      NODE_PROCESSING_INSTRUCTION equ 7
      NODE_COMMENT equ 8
      NODE_DOCUMENT equ 9
      NODE_DOCUMENT_TYPE equ 10
      NODE_DOCUMENT_FRAGMENT equ 11
      NODE_NOTATION equ 12
      tagDOMNodeType typedef DOMNodeType
      
      XMLELEM_TYPE typedef SDWORD
      XMLELEMTYPE_ELEMENT equ 0
      XMLELEMTYPE_TEXT equ 1
      XMLELEMTYPE_COMMENT equ 2
      XMLELEMTYPE_DOCUMENT equ 3
      XMLELEMTYPE_DTD equ 4
      XMLELEMTYPE_PI equ 5
      XMLELEMTYPE_OTHER equ 6
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
            STD_METHOD QueryInterface, :ptr IXMLDOMImplementation, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMImplementation
            STD_METHOD Release, :ptr IXMLDOMImplementation
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMImplementation, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMImplementation, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMImplementation, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMImplementation, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
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
            STD_METHOD QueryInterface, :ptr IXMLDOMNode, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMNode
            STD_METHOD Release, :ptr IXMLDOMNode
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNode, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNode, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNode, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMNode, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMNode, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMNode, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMNode, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMNode, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMNode, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMNode, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMNode, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMNode, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMNode, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMNode, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMNode, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMNode, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMNode, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMNode, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDOMDocumentFragment, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMDocumentFragment
            STD_METHOD Release, :ptr IXMLDOMDocumentFragment
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMDocumentFragment, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMDocumentFragment, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMDocumentFragment, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMDocumentFragment, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMDocumentFragment, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMDocumentFragment, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMDocumentFragment, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMDocumentFragment, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMDocumentFragment, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMDocumentFragment, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMDocumentFragment, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMDocumentFragment, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMDocumentFragment, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMDocumentFragment, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMDocumentFragment, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMDocumentFragment, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMDocumentFragment, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMDocumentFragment, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMDocumentFragment, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMDocumentFragment, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMDocumentFragment, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMDocumentFragment, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDOMDocument, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMDocument
            STD_METHOD Release, :ptr IXMLDOMDocument
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMDocument, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMDocument, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMDocument, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMDocument, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMDocument, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMDocument, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMDocument, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMDocument, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMDocument, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMDocument, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMDocument, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMDocument, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMDocument, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMDocument, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_doctype, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMDocumentType
            STD_METHOD get_implementation, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMImplementation
            STD_METHOD get_documentElement, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMElement
            STD_METHOD putref_documentElement, :ptr IXMLDOMDocument, :ptr IXMLDOMElement
            STD_METHOD createElement, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMElement
            STD_METHOD createDocumentFragment, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMDocumentFragment
            STD_METHOD createTextNode, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMText
            STD_METHOD createComment, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMComment
            STD_METHOD createCDATASection, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMCDATASection
            STD_METHOD createProcessingInstruction, :ptr IXMLDOMDocument, :BSTR, :BSTR, :ptr ptr IXMLDOMProcessingInstruction
            STD_METHOD createAttribute, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMAttribute
            STD_METHOD createEntityReference, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMEntityReference
            STD_METHOD getElementsByTagName, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD createNode, :ptr IXMLDOMDocument, :VARIANT, :BSTR, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD nodeFromID, :ptr IXMLDOMDocument, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD load, :ptr IXMLDOMDocument, :VARIANT, :ptr VARIANT_BOOL
            STD_METHOD get_readyState, :ptr IXMLDOMDocument, :ptr SDWORD
            STD_METHOD get_parseError, :ptr IXMLDOMDocument, :ptr ptr IXMLDOMParseError
            STD_METHOD get_url, :ptr IXMLDOMDocument, :ptr BSTR
            STD_METHOD get_async, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD put_async, :ptr IXMLDOMDocument, :VARIANT_BOOL
            STD_METHOD abort, :ptr IXMLDOMDocument
            STD_METHOD loadXML, :ptr IXMLDOMDocument, :BSTR, :ptr VARIANT_BOOL
            STD_METHOD save, :ptr IXMLDOMDocument, :VARIANT
            STD_METHOD get_validateOnParse, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD put_validateOnParse, :ptr IXMLDOMDocument, :VARIANT_BOOL
            STD_METHOD get_resolveExternals, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD put_resolveExternals, :ptr IXMLDOMDocument, :VARIANT_BOOL
            STD_METHOD get_preserveWhiteSpace, :ptr IXMLDOMDocument, :ptr VARIANT_BOOL
            STD_METHOD put_preserveWhiteSpace, :ptr IXMLDOMDocument, :VARIANT_BOOL
            STD_METHOD put_onreadystatechange, :ptr IXMLDOMDocument, :VARIANT
            STD_METHOD put_ondataavailable, :ptr IXMLDOMDocument, :VARIANT
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
            STD_METHOD QueryInterface, :ptr IXMLDOMNodeList, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMNodeList
            STD_METHOD Release, :ptr IXMLDOMNodeList
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNodeList, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNodeList, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNodeList, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMNodeList, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_item, :ptr IXMLDOMNodeList, :SDWORD, :ptr ptr IXMLDOMNode
            STD_METHOD get_length, :ptr IXMLDOMNodeList, :ptr SDWORD
            STD_METHOD nextNode, :ptr IXMLDOMNodeList, :ptr ptr IXMLDOMNode
            STD_METHOD reset, :ptr IXMLDOMNodeList
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
            STD_METHOD QueryInterface, :ptr IXMLDOMNamedNodeMap, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMNamedNodeMap
            STD_METHOD Release, :ptr IXMLDOMNamedNodeMap
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNamedNodeMap, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNamedNodeMap, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNamedNodeMap, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMNamedNodeMap, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD getNamedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD setNamedItem, :ptr IXMLDOMNamedNodeMap, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeNamedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_item, :ptr IXMLDOMNamedNodeMap, :SDWORD, :ptr ptr IXMLDOMNode
            STD_METHOD get_length, :ptr IXMLDOMNamedNodeMap, :ptr SDWORD
            STD_METHOD getQualifiedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD removeQualifiedItem, :ptr IXMLDOMNamedNodeMap, :BSTR, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD nextNode, :ptr IXMLDOMNamedNodeMap, :ptr ptr IXMLDOMNode
            STD_METHOD reset, :ptr IXMLDOMNamedNodeMap
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
            STD_METHOD QueryInterface, :ptr IXMLDOMCharacterData, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMCharacterData
            STD_METHOD Release, :ptr IXMLDOMCharacterData
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMCharacterData, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMCharacterData, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMCharacterData, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMCharacterData, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMCharacterData, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMCharacterData, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMCharacterData, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMCharacterData, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMCharacterData, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMCharacterData, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMCharacterData, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMCharacterData, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMCharacterData, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMCharacterData, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMCharacterData, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMCharacterData, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMCharacterData, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMCharacterData, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMCharacterData, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMCharacterData, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_data, :ptr IXMLDOMCharacterData, :ptr BSTR
            STD_METHOD put_data, :ptr IXMLDOMCharacterData, :BSTR
            STD_METHOD get_length, :ptr IXMLDOMCharacterData, :ptr SDWORD
            STD_METHOD substringData, :ptr IXMLDOMCharacterData, :SDWORD, :SDWORD, :ptr BSTR
            STD_METHOD appendData, :ptr IXMLDOMCharacterData, :BSTR
            STD_METHOD insertData, :ptr IXMLDOMCharacterData, :SDWORD, :BSTR
            STD_METHOD deleteData, :ptr IXMLDOMCharacterData, :SDWORD, :SDWORD
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
            STD_METHOD QueryInterface, :ptr IXMLDOMAttribute, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMAttribute
            STD_METHOD Release, :ptr IXMLDOMAttribute
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMAttribute, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMAttribute, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMAttribute, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMAttribute, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMAttribute, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMAttribute, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMAttribute, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMAttribute, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMAttribute, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMAttribute, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMAttribute, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMAttribute, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMAttribute, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMAttribute, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMAttribute, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMAttribute, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMAttribute, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMAttribute, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMAttribute, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_name, :ptr IXMLDOMAttribute, :ptr BSTR
            STD_METHOD get_value, :ptr IXMLDOMAttribute, :ptr VARIANT
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
            STD_METHOD QueryInterface, :ptr IXMLDOMElement, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMElement
            STD_METHOD Release, :ptr IXMLDOMElement
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMElement, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMElement, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMElement, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMElement, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMElement, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMElement, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMElement, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMElement, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMElement, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMElement, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMElement, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMElement, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMElement, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMElement, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMElement, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMElement, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMElement, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMElement, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMElement, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_tagName, :ptr IXMLDOMElement, :ptr BSTR
            STD_METHOD getAttribute, :ptr IXMLDOMElement, :BSTR, :ptr VARIANT
            STD_METHOD setAttribute, :ptr IXMLDOMElement, :BSTR, :VARIANT
            STD_METHOD removeAttribute, :ptr IXMLDOMElement, :BSTR
            STD_METHOD getAttributeNode, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMAttribute
            STD_METHOD setAttributeNode, :ptr IXMLDOMElement, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMAttribute
            STD_METHOD removeAttributeNode, :ptr IXMLDOMElement, :ptr IXMLDOMAttribute, :ptr ptr IXMLDOMAttribute
            STD_METHOD getElementsByTagName, :ptr IXMLDOMElement, :BSTR, :ptr ptr IXMLDOMNodeList
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
            STD_METHOD QueryInterface, :ptr IXMLDOMText, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMText
            STD_METHOD Release, :ptr IXMLDOMText
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMText, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMText, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMText, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMText, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMText, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMText, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMText, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMText, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMText, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMText, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMText, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMText, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMText, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMText, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMText, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMText, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMText, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMText, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMText, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMText, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMText, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMText, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMText, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMText, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMText, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_data, :ptr IXMLDOMText, :ptr BSTR
            STD_METHOD put_data, :ptr IXMLDOMText, :BSTR
            STD_METHOD get_length, :ptr IXMLDOMText, :ptr SDWORD
            STD_METHOD substringData, :ptr IXMLDOMText, :SDWORD, :SDWORD, :ptr BSTR
            STD_METHOD appendData, :ptr IXMLDOMText, :BSTR
            STD_METHOD insertData, :ptr IXMLDOMText, :SDWORD, :BSTR
            STD_METHOD deleteData, :ptr IXMLDOMText, :SDWORD, :SDWORD
            STD_METHOD replaceData, :ptr IXMLDOMText, :SDWORD, :SDWORD, :BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDOMComment, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMComment
            STD_METHOD Release, :ptr IXMLDOMComment
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMComment, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMComment, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMComment, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMComment, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMComment, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMComment, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMComment, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMComment, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMComment, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMComment, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMComment, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMComment, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMComment, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMComment, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMComment, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMComment, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMComment, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMComment, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMComment, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMComment, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMComment, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_data, :ptr IXMLDOMComment, :ptr BSTR
            STD_METHOD put_data, :ptr IXMLDOMComment, :BSTR
            STD_METHOD get_length, :ptr IXMLDOMComment, :ptr SDWORD
            STD_METHOD substringData, :ptr IXMLDOMComment, :SDWORD, :SDWORD, :ptr BSTR
            STD_METHOD appendData, :ptr IXMLDOMComment, :BSTR
            STD_METHOD insertData, :ptr IXMLDOMComment, :SDWORD, :BSTR
            STD_METHOD deleteData, :ptr IXMLDOMComment, :SDWORD, :SDWORD
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
            STD_METHOD QueryInterface, :ptr IXMLDOMProcessingInstruction, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMProcessingInstruction
            STD_METHOD Release, :ptr IXMLDOMProcessingInstruction
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMProcessingInstruction, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMProcessingInstruction, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMProcessingInstruction, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMProcessingInstruction, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMProcessingInstruction, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMProcessingInstruction, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMProcessingInstruction, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMProcessingInstruction, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMProcessingInstruction, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMProcessingInstruction, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMProcessingInstruction, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMProcessingInstruction, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMProcessingInstruction, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMProcessingInstruction, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMProcessingInstruction, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_target, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
            STD_METHOD get_data, :ptr IXMLDOMProcessingInstruction, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDOMCDATASection, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMCDATASection
            STD_METHOD Release, :ptr IXMLDOMCDATASection
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMCDATASection, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMCDATASection, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMCDATASection, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMCDATASection, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMCDATASection, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMCDATASection, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMCDATASection, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMCDATASection, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMCDATASection, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMCDATASection, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMCDATASection, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMCDATASection, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMCDATASection, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMCDATASection, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMCDATASection, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMCDATASection, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMCDATASection, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMCDATASection, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMCDATASection, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMCDATASection, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_data, :ptr IXMLDOMCDATASection, :ptr BSTR
            STD_METHOD put_data, :ptr IXMLDOMCDATASection, :BSTR
            STD_METHOD get_length, :ptr IXMLDOMCDATASection, :ptr SDWORD
            STD_METHOD substringData, :ptr IXMLDOMCDATASection, :SDWORD, :SDWORD, :ptr BSTR
            STD_METHOD appendData, :ptr IXMLDOMCDATASection, :BSTR
            STD_METHOD insertData, :ptr IXMLDOMCDATASection, :SDWORD, :BSTR
            STD_METHOD deleteData, :ptr IXMLDOMCDATASection, :SDWORD, :SDWORD
            STD_METHOD replaceData, :ptr IXMLDOMCDATASection, :SDWORD, :SDWORD, :BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDOMDocumentType, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMDocumentType
            STD_METHOD Release, :ptr IXMLDOMDocumentType
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMDocumentType, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMDocumentType, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMDocumentType, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMDocumentType, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMDocumentType, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMDocumentType, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMDocumentType, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMDocumentType, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMDocumentType, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMDocumentType, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMDocumentType, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMDocumentType, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMDocumentType, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMDocumentType, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMDocumentType, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMDocumentType, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMDocumentType, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMDocumentType, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMDocumentType, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_name, :ptr IXMLDOMDocumentType, :ptr BSTR
            STD_METHOD get_entities, :ptr IXMLDOMDocumentType, :ptr ptr IXMLDOMNamedNodeMap
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
            STD_METHOD QueryInterface, :ptr IXMLDOMNotation, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMNotation
            STD_METHOD Release, :ptr IXMLDOMNotation
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMNotation, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMNotation, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMNotation, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMNotation, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMNotation, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMNotation, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMNotation, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMNotation, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMNotation, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMNotation, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMNotation, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMNotation, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMNotation, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMNotation, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMNotation, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMNotation, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMNotation, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMNotation, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMNotation, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMNotation, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMNotation, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_publicId, :ptr IXMLDOMNotation, :ptr VARIANT
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
            STD_METHOD QueryInterface, :ptr IXMLDOMEntity, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMEntity
            STD_METHOD Release, :ptr IXMLDOMEntity
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMEntity, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMEntity, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMEntity, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMEntity, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMEntity, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMEntity, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMEntity, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMEntity, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMEntity, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMEntity, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMEntity, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMEntity, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMEntity, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMEntity, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMEntity, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMEntity, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMEntity, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMEntity, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMEntity, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMEntity, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXMLDOMEntity, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD get_publicId, :ptr IXMLDOMEntity, :ptr VARIANT
            STD_METHOD get_systemId, :ptr IXMLDOMEntity, :ptr VARIANT
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
            STD_METHOD QueryInterface, :ptr IXMLDOMEntityReference, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMEntityReference
            STD_METHOD Release, :ptr IXMLDOMEntityReference
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMEntityReference, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMEntityReference, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMEntityReference, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMEntityReference, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXMLDOMEntityReference, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXMLDOMEntityReference, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXMLDOMEntityReference, :VARIANT
            STD_METHOD get_nodeType, :ptr IXMLDOMEntityReference, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXMLDOMEntityReference, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXMLDOMEntityReference, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXMLDOMEntityReference, :ptr BSTR
            STD_METHOD get_text, :ptr IXMLDOMEntityReference, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLDOMEntityReference, :BSTR
            STD_METHOD get_specified, :ptr IXMLDOMEntityReference, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXMLDOMEntityReference, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXMLDOMEntityReference, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXMLDOMEntityReference, :VARIANT
            STD_METHOD get_dataType, :ptr IXMLDOMEntityReference, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXMLDOMEntityReference, :BSTR
            STD_METHOD get_xml, :ptr IXMLDOMEntityReference, :ptr BSTR
            STD_METHOD transformNode, :ptr IXMLDOMEntityReference, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXMLDOMEntityReference, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXMLDOMEntityReference, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXMLDOMEntityReference, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXMLDOMEntityReference, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXMLDOMEntityReference, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXMLDOMEntityReference, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDOMParseError, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDOMParseError
            STD_METHOD Release, :ptr IXMLDOMParseError
            STD_METHOD GetTypeInfoCount, :ptr IXMLDOMParseError, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDOMParseError, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDOMParseError, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDOMParseError, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_errorCode, :ptr IXMLDOMParseError, :ptr SDWORD
            STD_METHOD get_url, :ptr IXMLDOMParseError, :ptr BSTR
            STD_METHOD get_reason, :ptr IXMLDOMParseError, :ptr BSTR
            STD_METHOD get_srcText, :ptr IXMLDOMParseError, :ptr BSTR
            STD_METHOD get_line, :ptr IXMLDOMParseError, :ptr SDWORD
            STD_METHOD get_linepos, :ptr IXMLDOMParseError, :ptr SDWORD
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
            STD_METHOD QueryInterface, :ptr IXTLRuntime, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXTLRuntime
            STD_METHOD Release, :ptr IXTLRuntime
            STD_METHOD GetTypeInfoCount, :ptr IXTLRuntime, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXTLRuntime, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXTLRuntime, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXTLRuntime, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_nodeName, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD get_nodeValue, :ptr IXTLRuntime, :ptr VARIANT
            STD_METHOD put_nodeValue, :ptr IXTLRuntime, :VARIANT
            STD_METHOD get_nodeType, :ptr IXTLRuntime, :ptr DOMNodeType
            STD_METHOD get_parentNode, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            STD_METHOD get_childNodes, :ptr IXTLRuntime, :ptr ptr IXMLDOMNodeList
            STD_METHOD get_firstChild, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            STD_METHOD get_lastChild, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            STD_METHOD get_previousSibling, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            STD_METHOD get_nextSibling, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            STD_METHOD get_attributes, :ptr IXTLRuntime, :ptr ptr IXMLDOMNamedNodeMap
            STD_METHOD insertBefore, :ptr IXTLRuntime, :ptr IXMLDOMNode, :VARIANT, :ptr ptr IXMLDOMNode
            STD_METHOD replaceChild, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD removeChild, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD appendChild, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr ptr IXMLDOMNode
            STD_METHOD hasChildNodes, :ptr IXTLRuntime, :ptr VARIANT_BOOL
            STD_METHOD get_ownerDocument, :ptr IXTLRuntime, :ptr ptr IXMLDOMDocument
            STD_METHOD cloneNode, :ptr IXTLRuntime, :VARIANT_BOOL, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypeString, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD get_text, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD put_text, :ptr IXTLRuntime, :BSTR
            STD_METHOD get_specified, :ptr IXTLRuntime, :ptr VARIANT_BOOL
            STD_METHOD get_definition, :ptr IXTLRuntime, :ptr ptr IXMLDOMNode
            STD_METHOD get_nodeTypedValue, :ptr IXTLRuntime, :ptr VARIANT
            STD_METHOD put_nodeTypedValue, :ptr IXTLRuntime, :VARIANT
            STD_METHOD get_dataType, :ptr IXTLRuntime, :ptr VARIANT
            STD_METHOD put_dataType, :ptr IXTLRuntime, :BSTR
            STD_METHOD get_xml, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD transformNode, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr BSTR
            STD_METHOD selectNodes, :ptr IXTLRuntime, :BSTR, :ptr ptr IXMLDOMNodeList
            STD_METHOD selectSingleNode, :ptr IXTLRuntime, :BSTR, :ptr ptr IXMLDOMNode
            STD_METHOD get_parsed, :ptr IXTLRuntime, :ptr VARIANT_BOOL
            STD_METHOD get_namespaceURI, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD get_prefix, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD get_baseName, :ptr IXTLRuntime, :ptr BSTR
            STD_METHOD transformNodeToObject, :ptr IXTLRuntime, :ptr IXMLDOMNode, :VARIANT
            STD_METHOD uniqueID, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            STD_METHOD depth, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            STD_METHOD childNumber, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            STD_METHOD ancestorChildNumber, :ptr IXTLRuntime, :BSTR, :ptr IXMLDOMNode, :ptr SDWORD
            STD_METHOD absoluteChildNumber, :ptr IXTLRuntime, :ptr IXMLDOMNode, :ptr SDWORD
            STD_METHOD formatIndex, :ptr IXTLRuntime, :SDWORD, :BSTR, :ptr BSTR
            STD_METHOD formatNumber, :ptr IXTLRuntime, :REAL8, :BSTR, :ptr BSTR
            STD_METHOD formatDate, :ptr IXTLRuntime, :VARIANT, :BSTR, :VARIANT, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr XMLDOMDocumentEvents, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr XMLDOMDocumentEvents
            STD_METHOD Release, :ptr XMLDOMDocumentEvents
            STD_METHOD GetTypeInfoCount, :ptr XMLDOMDocumentEvents, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr XMLDOMDocumentEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr XMLDOMDocumentEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD QueryInterface, :ptr IXMLHttpRequest, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLHttpRequest
            STD_METHOD Release, :ptr IXMLHttpRequest
            STD_METHOD GetTypeInfoCount, :ptr IXMLHttpRequest, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLHttpRequest, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLHttpRequest, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLHttpRequest, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD open, :ptr IXMLHttpRequest, :BSTR, :BSTR, :VARIANT, :VARIANT, :VARIANT
            STD_METHOD setRequestHeader, :ptr IXMLHttpRequest, :BSTR, :BSTR
            STD_METHOD getResponseHeader, :ptr IXMLHttpRequest, :BSTR, :ptr BSTR
            STD_METHOD getAllResponseHeaders, :ptr IXMLHttpRequest, :ptr BSTR
            STD_METHOD send, :ptr IXMLHttpRequest, :VARIANT
            STD_METHOD abort, :ptr IXMLHttpRequest
            STD_METHOD get_status, :ptr IXMLHttpRequest, :ptr SDWORD
            STD_METHOD get_statusText, :ptr IXMLHttpRequest, :ptr BSTR
            STD_METHOD get_responseXML, :ptr IXMLHttpRequest, :ptr ptr IDispatch
            STD_METHOD get_responseText, :ptr IXMLHttpRequest, :ptr BSTR
            STD_METHOD get_responseBody, :ptr IXMLHttpRequest, :ptr VARIANT
            STD_METHOD get_responseStream, :ptr IXMLHttpRequest, :ptr VARIANT
            STD_METHOD get_readyState, :ptr IXMLHttpRequest, :ptr SDWORD
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
            STD_METHOD QueryInterface, :ptr IXMLDSOControl, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDSOControl
            STD_METHOD Release, :ptr IXMLDSOControl
            STD_METHOD GetTypeInfoCount, :ptr IXMLDSOControl, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDSOControl, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDSOControl, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDSOControl, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_XMLDocument, :ptr IXMLDSOControl, :ptr ptr IXMLDOMDocument
            STD_METHOD put_XMLDocument, :ptr IXMLDSOControl, :ptr IXMLDOMDocument
            STD_METHOD get_JavaDSOCompatible, :ptr IXMLDSOControl, :ptr BOOL
            STD_METHOD put_JavaDSOCompatible, :ptr IXMLDSOControl, :BOOL
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
            STD_METHOD QueryInterface, :ptr IXMLElementCollection, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLElementCollection
            STD_METHOD Release, :ptr IXMLElementCollection
            STD_METHOD GetTypeInfoCount, :ptr IXMLElementCollection, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLElementCollection, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLElementCollection, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLElementCollection, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD put_length, :ptr IXMLElementCollection, :SDWORD
            STD_METHOD get_length, :ptr IXMLElementCollection, :ptr SDWORD
            STD_METHOD get__newEnum, :ptr IXMLElementCollection, :ptr ptr IUnknown
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
            STD_METHOD QueryInterface, :ptr IXMLDocument, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDocument
            STD_METHOD Release, :ptr IXMLDocument
            STD_METHOD GetTypeInfoCount, :ptr IXMLDocument, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDocument, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDocument, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDocument, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_root, :ptr IXMLDocument, :ptr ptr IXMLElement
            STD_METHOD get_fileSize, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD get_fileModifiedDate, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD get_fileUpdatedDate, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD get_URL, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD put_URL, :ptr IXMLDocument, :BSTR
            STD_METHOD get_mimeType, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD get_readyState, :ptr IXMLDocument, :ptr SDWORD
            STD_METHOD get_charset, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD put_charset, :ptr IXMLDocument, :BSTR
            STD_METHOD get_version, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD get_doctype, :ptr IXMLDocument, :ptr BSTR
            STD_METHOD get_dtdURL, :ptr IXMLDocument, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLDocument2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLDocument2
            STD_METHOD Release, :ptr IXMLDocument2
            STD_METHOD GetTypeInfoCount, :ptr IXMLDocument2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLDocument2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLDocument2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLDocument2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_root, :ptr IXMLDocument2, :ptr ptr IXMLElement2
            STD_METHOD get_fileSize, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD get_fileModifiedDate, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD get_fileUpdatedDate, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD get_URL, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD put_URL, :ptr IXMLDocument2, :BSTR
            STD_METHOD get_mimeType, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD get_readyState, :ptr IXMLDocument2, :ptr SDWORD
            STD_METHOD get_charset, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD put_charset, :ptr IXMLDocument2, :BSTR
            STD_METHOD get_version, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD get_doctype, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD get_dtdURL, :ptr IXMLDocument2, :ptr BSTR
            STD_METHOD createElement, :ptr IXMLDocument2, :VARIANT, :VARIANT, :ptr ptr IXMLElement2
            STD_METHOD get_async, :ptr IXMLDocument2, :ptr VARIANT_BOOL
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
            STD_METHOD QueryInterface, :ptr IXMLElement, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLElement
            STD_METHOD Release, :ptr IXMLElement
            STD_METHOD GetTypeInfoCount, :ptr IXMLElement, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLElement, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLElement, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLElement, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_tagName, :ptr IXMLElement, :ptr BSTR
            STD_METHOD put_tagName, :ptr IXMLElement, :BSTR
            STD_METHOD get_parent, :ptr IXMLElement, :ptr ptr IXMLElement
            STD_METHOD setAttribute, :ptr IXMLElement, :BSTR, :VARIANT
            STD_METHOD getAttribute, :ptr IXMLElement, :BSTR, :ptr VARIANT
            STD_METHOD removeAttribute, :ptr IXMLElement, :BSTR
            STD_METHOD get_children, :ptr IXMLElement, :ptr ptr IXMLElementCollection
            STD_METHOD get_type, :ptr IXMLElement, :ptr SDWORD
            STD_METHOD get_text, :ptr IXMLElement, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLElement, :BSTR
            STD_METHOD addChild, :ptr IXMLElement, :ptr IXMLElement, :SDWORD, :SDWORD
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
            STD_METHOD QueryInterface, :ptr IXMLElement2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLElement2
            STD_METHOD Release, :ptr IXMLElement2
            STD_METHOD GetTypeInfoCount, :ptr IXMLElement2, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLElement2, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLElement2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLElement2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_tagName, :ptr IXMLElement2, :ptr BSTR
            STD_METHOD put_tagName, :ptr IXMLElement2, :BSTR
            STD_METHOD get_parent, :ptr IXMLElement2, :ptr ptr IXMLElement2
            STD_METHOD setAttribute, :ptr IXMLElement2, :BSTR, :VARIANT
            STD_METHOD getAttribute, :ptr IXMLElement2, :BSTR, :ptr VARIANT
            STD_METHOD removeAttribute, :ptr IXMLElement2, :BSTR
            STD_METHOD get_children, :ptr IXMLElement2, :ptr ptr IXMLElementCollection
            STD_METHOD get_type, :ptr IXMLElement2, :ptr SDWORD
            STD_METHOD get_text, :ptr IXMLElement2, :ptr BSTR
            STD_METHOD put_text, :ptr IXMLElement2, :BSTR
            STD_METHOD addChild, :ptr IXMLElement2, :ptr IXMLElement2, :SDWORD, :SDWORD
            STD_METHOD removeChild, :ptr IXMLElement2, :ptr IXMLElement2
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
            STD_METHOD QueryInterface, :ptr IXMLAttribute, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLAttribute
            STD_METHOD Release, :ptr IXMLAttribute
            STD_METHOD GetTypeInfoCount, :ptr IXMLAttribute, :ptr UINT
            STD_METHOD GetTypeInfo, :ptr IXMLAttribute, :UINT, :LCID, :ptr ptr ITypeInfo
            STD_METHOD GetIDsOfNames, :ptr IXMLAttribute, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            STD_METHOD Invoke_, :ptr IXMLAttribute, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            STD_METHOD get_name, :ptr IXMLAttribute, :ptr BSTR
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
            STD_METHOD QueryInterface, :ptr IXMLError, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IXMLError
            STD_METHOD Release, :ptr IXMLError
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

