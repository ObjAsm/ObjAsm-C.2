; ==================================================================================================
; Title:      XmlHelper.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    DOM-XML helper definitions.
; Notes:      Version C.1.0, November 2024
;               - First release.
; ==================================================================================================


PIXMLDOMImplementation            typedef ptr IXMLDOMImplementation
PIXMLDOMNode                      typedef ptr IXMLDOMNode
PIXMLDOMDocumentFragment          typedef ptr IXMLDOMDocumentFragment
PIXMLDOMDocument                  typedef ptr IXMLDOMDocument
PIXMLDOMNodeList                  typedef ptr IXMLDOMNodeList
PIXMLDOMNamedNodeMap              typedef ptr IXMLDOMNamedNodeMap
PIXMLDOMCharacterData             typedef ptr IXMLDOMCharacterData
PIXMLDOMAttribute                 typedef ptr IXMLDOMAttribute
PIXMLDOMElement                   typedef ptr IXMLDOMElement
PIXMLDOMText                      typedef ptr IXMLDOMText
PIXMLDOMComment                   typedef ptr IXMLDOMComment
PIXMLDOMProcessingInstruction     typedef ptr IXMLDOMProcessingInstruction
PIXMLDOMCDATASection              typedef ptr IXMLDOMCDATASection
PIXMLDOMDocumentType              typedef ptr IXMLDOMDocumentType
PIXMLDOMNotation                  typedef ptr IXMLDOMNotation
PIXMLDOMEntity                    typedef ptr IXMLDOMEntity
PIXMLDOMEntityReference           typedef ptr IXMLDOMEntityReference
PIXMLDOMParseError                typedef ptr IXMLDOMParseError
PIXMLHttpRequest                  typedef ptr IXMLHttpRequest
PIXMLDSOControl                   typedef ptr IXMLDSOControl
PIXMLElementCollection            typedef ptr IXMLElementCollection
PIXMLDocument                     typedef ptr IXMLDocument
PIXMLDocument2                    typedef ptr IXMLDocument2
PIXMLElement                      typedef ptr IXMLElement
PIXMLElement2                     typedef ptr IXMLElement2
PIXMLAttribute                    typedef ptr IXMLAttribute
PIXMLError                        typedef ptr IXMLError

PPIXMLDOMElement                  typedef ptr PIXMLDOMElement
PPIXMLDOMNode                     typedef ptr PIXMLDOMNode

.const
sCLSID_DOMDocument                textequ <2933bf90-7b36-11d2-b20e-00c04f983e60>
sCLSID_DOMFreeThreadedDocument    textequ <2933bf91-7b36-11d2-b20e-00c04f983e60>

sIID_IXMLDOMImplementation        textequ <2933BF8F-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMNode                  textequ <2933BF80-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMDocumentFragment      textequ <3efaa413-272f-11d2-836f-0000f87a7782>
sIID_IXMLDOMDocument              textequ <2933BF81-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMNodeList              textequ <2933BF82-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMNamedNodeMap          textequ <2933BF83-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMCharacterData         textequ <2933BF84-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMAttribute             textequ <2933BF85-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMElement               textequ <2933BF86-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMText                  textequ <2933BF87-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMComment               textequ <2933BF88-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMProcessingInstruction textequ <2933BF89-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMCDATASection          textequ <2933BF8A-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMDocumentType          textequ <2933BF8B-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMNotation              textequ <2933BF8C-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMEntity                textequ <2933BF8D-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMEntityReference       textequ <2933BF8E-7B36-11d2-B20E-00C04F983E60>
sIID_IXMLDOMParseError            textequ <3efaa426-272f-11d2-836f-0000f87a7782>
sIID_IXMLHttpRequest              textequ <ED8C108D-4349-11D2-91A4-00C04F7969E8>
sIID_IXMLDSOControl               textequ <310afa62-0575-11d2-9ca9-0060b0ec3d39>
sIID_IXMLElementCollection        textequ <65725580-9B5D-11d0-9BFE-00C04FC99C8E>
sIID_IXMLDocument                 textequ <F52E2B61-18A1-11d1-B105-00805F49916B>
sIID_IXMLDocument2                textequ <2B8DE2FE-8D2D-11d1-B2FC-00C04FD915A9>
sIID_IXMLElement                  textequ <3F7F31AC-E15F-11d0-9C25-00C04FC99C8E>
sIID_IXMLElement2                 textequ <2B8DE2FF-8D2D-11d1-B2FC-00C04FD915A9>
sIID_IXMLAttribute                textequ <D4D4A0FC-3B73-11d1-B2B4-00C04FB92596>
sIID_IXMLError                    textequ <948C5AD3-C58D-11d0-9C0B-00C04FC99C8E>
