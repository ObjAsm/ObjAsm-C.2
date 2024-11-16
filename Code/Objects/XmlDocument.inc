; ==================================================================================================
; Title:      XmlDocument.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DOM-XML objects.
; Notes:      Version C.1.0, November 2024
;               - First release.
;               - This is a port from sources of Veria Kalantary - Ideas of East Company
;                 http://www.IdeasofEast.com; http://www.ioe.co.ir
; Links:      https://learn.microsoft.com/en-us/dotnet/standard/data/xml/xml-document-object-model-dom
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XmlNode
; Purpose:    This object implements the W3C Document Object Model (DOM) Level 1 Core and the Core
;             DOM Level 2. The DOM is an in-memory (cache) tree representation of an XML document.
;             XmlNode is the base object.

Object XmlNode, XmlNodeID, Primer
  VirtualMethod   AddChild,           PSTRING
  RedefineMethod  Done
  VirtualMethod   GetAttribute,       PSTRING
  VirtualMethod   GetChildNode,       DWORD
  VirtualMethod   GetChildNodes
  VirtualMethod   GetChildNodesCount
  VirtualMethod   GetFirstChild
  VirtualMethod   GetLastChild
  VirtualMethod   GetName
  VirtualMethod   GetParentNode
  VirtualMethod   GetText,
  VirtualMethod   GetType
  VirtualMethod   GetValue,           ptr VARIANT
  VirtualMethod   GetXML
  VirtualMethod   HasAttribute,       PSTRING
  VirtualMethod   HasChildNodes
  VirtualMethod   IsTextElement
  VirtualMethod   PrevSibling
  VirtualMethod   NextSibling
  VirtualMethod   SetAttribute,       PSTRING, PSTRING
  VirtualMethod   SetNode,            PIXMLDOMElement
  VirtualMethod   SetText,            PSTRING
  VirtualMethod   SetValue,           PSTRING

  DefineVariable  pNode,      PIXMLDOMElement,  NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     XmlDocument
; Purpose:    This object represents an XML document. You can use XmlDocument to load and save
;             XML data. It also includes methods for node creation.

Object XmlDocument, XmlDocumentID, Primer
  VirtualMethod   AddChild,           PSTRING
  VirtualMethod   AddChildToParent,   PIXMLDOMNode, PIXMLDOMNode
  VirtualMethod   Clear
  VirtualMethod   CreateElement,      PSTRING
  RedefineMethod  Done
  VirtualMethod   GetDocumentElement
  VirtualMethod   GetXML
  RedefineMethod  Init,               POINTER
  VirtualMethod   LoadFromFile,       PSTRING
  VirtualMethod   LoadFromXML,        PSTRING
  VirtualMethod   SaveToFile,         PSTRING
  VirtualMethod   SaveToXML,          ptr BSTR
  VirtualMethod   SetXML,             PSTRING

  DefineVariable  pDocument,  PIXMLDOMDocument,  NULL

  Embed  DocumentElement,   XmlNode
ObjectEnd


; ==================================================================================================
;    XmlNode implementation
; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.AddChild
; Purpose:    Add a child node.
; Arguments:  Arg1: -> Node name.
; Return:     xax -> New node.

Method XmlNode.AddChild, uses xsi, pNodeName:PSTRING
  local bstr:BSTR, pDocument:PIXMLDOMDocument
  local pChild:PIXMLDOMElement, pNewNode:PIXMLDOMNode

  SetObject xsi
  invoke CoCreateInstance, addr CLSID_DOMDocument, NULL, \
                           CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
                           addr IID_IXMLDOMDocument, addr pDocument
  ICall pDocument::IXMLDOMDocument.put_async, VARIANT_FALSE
  mov bstr, $invoke(Str2NewBStr, pNodeName)
  ICall pDocument::IXMLDOMDocument.createElement, bstr, addr pChild
  invoke BStrDispose, bstr
  ICall [xsi].pNode::IXMLDOMNode.appendChild, pChild, addr pNewNode
  .if eax != S_OK && pNewNode != NULL
    ICall pNewNode::IXMLDOMNode.Release
  .endif
  ICall pDocument::IXMLDOMDocument.Release
  mov xax, pChild
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.Done
; Purpose:    Finalizes the object.
; Arguments:  None.
; Return:     Nothing.

Method XmlNode.Done, uses xsi
  SetObject xsi
  ICall [xsi].pNode::IXMLDOMNode.Release
  mov [xsi].pNode, NULL
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetAttribute
; Purpose:    Return a specific attribute by name.
; Arguments:  Arg1: -> Attribute name.
; Return:     xax -> Attribute string.

Method XmlNode.GetAttribute, uses xsi, Attribute:PSTRING
  local var:VARIANT, bstr:BSTR, pStr:PSTRING

  SetObject xsi
  mov bstr, $invoke(Str2NewBStr, Attribute)
  ICall [xsi].pNode::IXMLDOMElement.getAttribute, bstr, addr var
  invoke BStrDispose, bstr
  mov pStr, $invoke(BStr2NewStr, var.bstrVal)
  invoke BStrDispose, bstr
  mov xax, pStr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetChildNode
; Purpose:    Return a node by index.
; Arguments:  Arg1: Index from 0..Count - 1
; Return:     xax -> Node or NULL if failed.

Method XmlNode.GetChildNode, uses xsi, dIndex:DWORD
  local bstr:BSTR, pNodes:PIXMLDOMNodeList, pNode:PIXMLDOMNode, pElement:PIXMLDOMElement

  SetObject xsi
  ICall [xsi].pNode::IXMLDOMNode.get_childNodes, addr pNodes
  ICall pNodes::IXMLDOMNodeList.get_item, dIndex, addr pNode
  ICall pNode::IXMLDOMNode.get_nodeTypeString, addr bstr
  invoke BStrComp, bstr, $OfsCBStr("text")
  .if eax == 0
    mov xax, pNode
  .else
    ICall pNode::IXMLDOMNode.QueryInterface, addr IID_IXMLDOMElement, addr pElement
    ICall pNode::IXMLDOMNode.Release
    mov xax, pElement
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetChildNodes
; Purpose:    Return a list object containing all nodes.
; Arguments:  None.
; Return:     xax -> Nodes.

Method XmlNode.GetChildNodes
  local pChildNodes:PIXMLDOMNodeList

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_childNodes, addr pChildNodes
  mov xax, pChildNodes
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetChildNodesCount
; Purpose:    Return the number of child nodes.
; Arguments:  None.
; Return:     eax = Count of child nodes.

Method XmlNode.GetChildNodesCount, uses xsi
  local pChildNodes:PIXMLDOMNodeList, dChildCount:DWORD

  SetObject xsi
  ICall [xsi].pNode::IXMLDOMNode.get_childNodes, addr pChildNodes
  ICall pChildNodes::IXMLDOMNodeList.get_length, addr dChildCount
  ICall pChildNodes::IXMLDOMNodeList.Release
  mov eax, dChildCount
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetFirstChild
; Purpose:    Return the first child node.
; Arguments:  None.
; Return:     xax -> First child node or NULL if failed.

Method XmlNode.GetFirstChild, uses xsi
  local pNode:PIXMLDOMNode, pElement:PIXMLDOMElement

  SetObject xsi
  ICall [xsi].pNode::IXMLDOMNode.get_firstChild, addr pNode
  ICall pNode::IXMLDOMNode.QueryInterface, addr IID_IXMLDOMElement, addr pElement
  ICall pNode::IXMLDOMNode.Release
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetLastChild
; Purpose:    Return the last child node.
; Arguments:  None.
; Return:     xax -> Last child node or NULL if failed.

Method XmlNode.GetLastChild, uses xsi
  local pNode:PIXMLDOMNode, pElement:PIXMLDOMElement

  SetObject xsi
  ICall [xsi].pNode::IXMLDOMNode.get_lastChild, addr pNode
  ICall pNode::IXMLDOMNode.QueryInterface, addr IID_IXMLDOMElement, addr pElement
  ICall pNode::IXMLDOMNode.Release
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetName
; Purpose:    Return the name of the node.
; Arguments:  None.
; Return:     xax -> Name string. When no longer needed, it must be freed using StrDispose.

Method XmlNode.GetName
  local bstr:BSTR, pStr:PSTRING

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_nodeName, addr bstr
  mov pStr, $invoke(BStr2NewStr, bstr)
  invoke BStrDispose, bstr
  mov xax, pStr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetParentNode
; Purpose:    Return the parent node
; Arguments:  None.
; Return:     xax -> Parent node.

Method XmlNode.GetParentNode
  local pNode:PIXMLDOMNode, pElement:PIXMLDOMElement

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_parentNode, addr pNode
  ICall pNode::IXMLDOMNode.QueryInterface, addr IID_IXMLDOMElement, addr pElement
  ICall pNode::IXMLDOMNode.Release
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetText
; Purpose:    Return a text from the node.
; Arguments:  None.
; Return:     xax -> Test string. When no longer needed, it must be freed using StrDispose.

Method XmlNode.GetText
  local bstr:BSTR, pStr:PSTRING

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_text, addr bstr
  mov pStr, $invoke(BStr2NewStr, bstr)
  invoke BStrDispose, bstr
  mov xax, pStr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetType
; Purpose:    Return the type name of the node.
; Arguments:  None.
; Return:     xax -> Type string. When no longer needed, it must be freed using StrDispose.

Method XmlNode.GetType
  local bstr:BSTR, pStr:PSTRING

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_nodeTypeString, addr bstr
  mov pStr, $invoke(BStr2NewStr, bstr)
  invoke BStrDispose, bstr
  mov xax, pStr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetValue
; Purpose:    Return the value contained in the node.
; Arguments:  Arg1: -> VARIANT
; Return:     eax = S_OK. If it fails, it returns an HRESULT error code.

Method XmlNode.GetValue,, pVar:ptr VARIANT
  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_nodeValue, pVar
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.GetXML
; Purpose:    Return the XML string from the node.
; Arguments:  None.
; Return:     xax -> XML string. When no longer needed, it must be freed using StrDispose.

Method XmlNode.GetXML
  local bstr:BSTR, pStr:PSTRING

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_xml, addr bstr
  mov pStr, $invoke(BStr2NewStr, bstr)
  invoke BStrDispose, bstr
  mov xax, pStr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.HasAttribute
; Purpose:    Check if the node has a given attribute.
; Arguments:  Arg1: -> Attribute name.
; Return:     eax = TRUE or FALSE.

Method XmlNode.HasAttribute, uses xsi, Attribute:PSTRING
  local pAttribute:PIXMLDOMAttribute
  local bstr:BSTR

  SetObject xsi
  mov bstr, $invoke(Str2NewBStr, Attribute)
  ICall [xsi].pNode::IXMLDOMElement.getAttributeNode, bstr, addr pAttribute
  invoke BStrDispose, bstr
  .if pAttribute == NULL
    mov eax, FALSE
  .else
    mov eax, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.HasChildNodes
; Purpose:    Check if the node has children nodes.
; Arguments:  None.
; Return:     eax = TRUE or FALSE.

Method XmlNode.HasChildNodes
  local hasChild:VARIANT_BOOL

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.hasChildNodes, addr hasChild
  .if hasChild == 0
    mov eax, FALSE
  .else
    mov eax, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.IsTextElement
; Purpose:    Check if the node element is of type "text".
; Arguments:  None.
; Return:     eax = TRUE or FALSE.

Method XmlNode.IsTextElement, uses xsi
  local bstr:BSTR, pType:POINTER, pNode:PIXMLDOMNode, pNodes:PIXMLDOMNodeList

  SetObject xsi
  mov pType, $OCall(xsi.GetType)
  invoke StrComp, xax, offset szElement
  .if eax == 0
    invoke StrDispose, pType
    OCall xsi.HasChildNodes
    .if eax
      OCall xsi.GetChildNodesCount
      .if eax == 1
        ICall [xsi].pNode::IXMLDOMNode.get_childNodes, addr pNodes
        ICall pNodes::IXMLDOMNodeList.get_item, 0, addr pNode
        ICall pNode::IXMLDOMNode.get_nodeTypeString, addr bstr
        invoke BStrComp, bstr, $OfsCBStr("text")
        .if eax == 0
          mov eax, TRUE
        .else
          mov eax, FALSE
        .endif
        jmp @@EOM
      .endif
    .endif
  .else
    invoke StrDispose, pType
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.PrevSibling
; Purpose:    Return the previous sibling node.
; Arguments:  None.
; Return:     xax -> Previous sibling node.

Method XmlNode.PrevSibling
  local pNode:PIXMLDOMNode, pElement:PIXMLDOMElement

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_previousSibling, addr pNode
  ICall pNode::IXMLDOMNode.QueryInterface, addr IID_IXMLDOMElement, addr pElement
  ICall pNode::IXMLDOMNode.Release
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.NextSibling
; Purpose:    Return the next sibling node.
; Arguments:  None.
; Return:     xax -> Next sibling node.

Method XmlNode.NextSibling
  local pNode:PIXMLDOMNode, pElement:PIXMLDOMElement

  SetObject xcx
  ICall [xcx].pNode::IXMLDOMNode.get_nextSibling, addr pNode
  ICall pNode::IXMLDOMNode.QueryInterface, addr IID_IXMLDOMElement, addr pElement
  ICall pNode::IXMLDOMNode.Release
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.SetAttribute
; Purpose:    Set an atribute of the node.
; Arguments:  Arg1: -> Attribute name string.
;             Arg2: -> Attribute value string.
; Return:     Nothing.

Method XmlNode.SetAttribute, uses xsi, Attribute:PSTRING, Value:PSTRING
  local pDocument:PIXMLDOMDocument
  local pAttribute:PIXMLDOMAttribute, pPrvAttribute:PIXMLDOMAttribute
  local bstr:BSTR, var:VARIANT

  SetObject xsi
  mov pPrvAttribute, NULL
  invoke CoCreateInstance, addr CLSID_DOMDocument, NULL, \
                           CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
                           addr IID_IXMLDOMDocument, addr pDocument
  ICall pDocument::IXMLDOMDocument.put_async, VARIANT_FALSE
  mov bstr, $invoke(Str2NewBStr, Attribute)
  mov var.vt, VT_BSTR
  mov var.bstrVal, $invoke(Str2NewBStr, Value)
  ICall pDocument::IXMLDOMDocument.createAttribute, bstr, addr pAttribute
  ICall pAttribute::IXMLDOMAttribute.put_value, var
  ICall [xsi].pNode::IXMLDOMElement.setAttributeNode, pAttribute, addr pPrvAttribute
  invoke BStrDispose, bstr
  .if pPrvAttribute != NULL
    ICall pPrvAttribute::IXMLDOMAttribute.Release
  .endif
  ICall pAttribute::IXMLDOMAttribute.Release
  invoke VariantClear, addr var
  ICall pDocument::IXMLDOMDocument.Release
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.SetNode
; Purpose:    Assign an IXMLDOMElement to the node.
; Arguments:  Arg1: -> IXMLDOMElement
; Return:     Nothing.

Method XmlNode.SetNode,, pNode:PIXMLDOMElement
  SetObject xcx
  ?mov xdx, pNode
  mov [xcx].pNode, xdx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.SetText
; Purpose:    Set a text value to the node.
; Arguments:  Arg1: -> Text string.
; Return:     Nothing.

Method XmlNode.SetText, uses xsi, Value:PSTRING
  local bstr:BSTR

  SetObject xsi
  mov bstr, $invoke(Str2NewBStr, Value)
  ICall [xsi].pNode::IXMLDOMNode.put_text, bstr
  invoke BStrDispose, bstr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlNode.SetValue
; Purpose:    Set a value to the node.
; Arguments:  Arg1: -> Value string
; Return:     Nothing.

Method XmlNode.SetValue, uses xsi, Value:PSTRING
  local var:VARIANT

  SetObject xsi
  invoke VariantInit, addr var
  mov var.vt, VT_BSTR
  mov var.bstrVal, $invoke(Str2NewBStr, Value)
  ICall [xsi].pNode::IXMLDOMNode.put_nodeValue, var
  invoke VariantClear, addr var
MethodEnd


; ==================================================================================================
;    XmlDocument implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.AddChild
; Purpose:    Add a new child node to the document.
; Arguments:  Arg1: -> Child node name.
; Return:     xax -> Node.

Method XmlDocument.AddChild, uses xsi, pNodeName:PSTRING
  local pElement:PIXMLDOMElement

  SetObject xsi
  mov pElement, $OCall(xsi.CreateElement, pNodeName)
  OCall xsi.AddChildToParent, xax, [xsi].pDocument
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.AddChildToParent
; Purpose:    Add a new child node to a parent node.
; Arguments:  Arg1: -> Child node.
;             Arg2: -> Parent node.
; Return:     Nothing.

Method XmlDocument.AddChildToParent,, pChild:PIXMLDOMNode, pParent:PIXMLDOMNode
  local pNewNode:PIXMLDOMNode

  ICall pParent::IXMLDOMNode.appendChild, pChild, addr pNewNode
  .if eax != S_OK && pNewNode != NULL
    ICall pNewNode::IXMLDOMNode.Release
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.Clear
; Purpose:    Unload the XML information.
; Arguments:  None.
; Return:     eax = TRUE or FALSE if failed.

Method XmlDocument.Clear
  local bIsSuccessful:VARIANT_BOOL

  SetObject xcx
  ICall [xcx].pDocument::IXMLDOMDocument.loadXML, NULL, addr bIsSuccessful
  xor eax, eax
  cmp bIsSuccessful, VARIANT_TRUE
  setz al
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.CreateElement
; Purpose:    Create a new element in the document.
; Arguments:  Arg1: -> Element name.
; Return:     xax -> New Node or NULL if failed.

Method XmlDocument.CreateElement, uses xsi, ElementName:PSTRING
  local bstr:BSTR, pChild:PIXMLDOMElement

  SetObject xsi
  mov bstr, $invoke(Str2NewBStr, ElementName)
  ICall [xsi].pDocument::IXMLDOMDocument.createElement, bstr, addr pChild
  invoke BStrDispose, bstr
  mov xax, pChild
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.Done
; Purpose:    Finalizes the object
; Arguments:  None.
; Return:     Nothing.

Method XmlDocument.Done, uses xsi
  SetObject xsi
  OCall [xsi].DocumentElement::XmlNode.Done
  ICall [xsi].pDocument::IXMLDOMDocument.Release
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.GetDocumentElement
; Purpose:    Returns the document element
; Arguments:  None.
; Return:     xax -> Element or NULL if failed.

Method XmlDocument.GetDocumentElement
  local pElement:PIXMLDOMElement

  SetObject xcx
  ICall [xcx].pDocument::IXMLDOMDocument.get_documentElement, addr pElement
  mov xax, pElement
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.GetXML
; Purpose:    Return the XML string from the document.
; Arguments:  None.
; Return:     xax -> XML string or NULL if failed.
;             When no longer used it must be free using StrDispose

Method XmlDocument.GetXML
  local bstr:BSTR, pStr:PSTRING

  SetObject xcx
  OCall xcx.SaveToXML, addr bstr
  mov pStr, $invoke(BStr2NewStr, bstr)
  invoke BStrDispose, bstr
  mov xax, pStr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.Init
; Purpose:    Initializes the object
; Arguments:  Arg1: -> Owner.
; Return:     Nothing.

Method XmlDocument.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  invoke CoCreateInstance, addr CLSID_DOMDocument, NULL, \
                           CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER, \
                           addr IID_IXMLDOMDocument, addr [xsi].pDocument
  ICall [xsi].pDocument::IXMLDOMDocument.put_async, VARIANT_FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.LoadFromFile
; Purpose:    Load XML data from a file.
; Arguments:  Arg1: -> File name.
; Return:     eax = TRUE or FALSE if failed.

Method XmlDocument.LoadFromFile, uses xsi, pFileName:PSTRING
  local hFile:HANDLE, dReadBytes:DWORD, dSize:DWORD, dResult:DWORD
  local pBuffer:PSTRINGA, pStringW:PSTRINGW

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,\
                     FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    invoke GetFileSize, hFile, NULL
    mov dSize, eax
    inc eax                                             ;Add space for the ZTC
    MemAlloc eax
    .if xax != NULL
      mov pBuffer, xax
      invoke ReadFile, hFile, pBuffer, dSize, addr dReadBytes, NULL
      invoke CloseHandle, hFile
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        OCall xsi.LoadFromXML, pBuffer
        mov dResult, eax
      else
        mov pStringW, $invoke(StrA2NewStrW, pBuffer)
        OCall xsi.LoadFromXML, pStringW
        mov dResult, eax
        invoke StrDispose, pStringW
      endif
      MemFree pBuffer
      mov eax, dResult
    .else
      DbgWarning "Cannot allocate enough memory"
      xor eax, eax
    .endif
  .else
    DbgWarning "Cannot open XML file"
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.LoadFromXML
; Purpose:    Load data from XML string.
; Arguments:  Arg1: -> XML data string.
; Return:     eax = TRUE or FALSE if failed.

Method XmlDocument.LoadFromXML, uses xsi, pXML:PSTRING
  local bIsSuccessful:VARIANT_BOOL, bstr:BSTR

  SetObject xsi
  mov bstr, $invoke(Str2NewBStr, pXML)
  ICall [xsi].pDocument::IXMLDOMDocument.loadXML, bstr, addr bIsSuccessful
  invoke BStrDispose, bstr
  mov [xsi].DocumentElement.pNode, $OCall(xsi.GetDocumentElement)
  xor eax, eax
  cmp bIsSuccessful, VARIANT_TRUE
  setz al
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.SaveToFile
; Purpose:    Save document to a file.
; Arguments:  Arg1: -> File name.
; Return:     Nothing.

Method XmlDocument.SaveToFile, uses xsi, pFileName:PSTRING
  local bstr:BSTR, var:VARIANT

  SetObject xsi
  ICall [xsi].pDocument::IXMLDOMDocument.get_xml, addr bstr
  mov var.vt, VT_BSTR
  mov var.bstrVal, $invoke(Str2NewBStr, pFileName)
  ICall [xsi].pDocument::IXMLDOMDocument.save, var
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.SaveToXML
; Purpose:    Return a string containing the XML data.
; Arguments:  Arg1: -> Destination BSTR.
; Return:     Nothing.

Method XmlDocument.SaveToXML,, pBstr:ptr BSTR
  SetObject xcx
  ICall [xcx].pDocument::IXMLDOMDocument.get_xml, pBstr
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     XmlDocument.SetXML
; Purpose:    Load the XML data string.
; Arguments:  Arg1: -> XML data string.
; Return:     Nothing.

Method XmlDocument.SetXML,, pXML:PSTRING
  SetObject xcx
  OCall xcx::XmlDocument.LoadFromXML, pXML
MethodEnd

endif
