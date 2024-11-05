; ==================================================================================================
; Title:      MSXML2.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of MS XML2 API.
; Notes:      Version C.1.0, October 2017
;               - First release. Generated using COMView (www.japheth.de)
;                 Manually translated and edited.
; ==================================================================================================

echo *************************************************************************************

sTLBID_MSXML2                     textequ <F5078F18-C551-11D3-89B9-0000F81FE221>
_MajorVer_MSXML2 equ 4
_MinorVer_MSXML2 equ 0


sCLSID_DOMDocument                textequ <F6D90F11-9C73-11D3-B32E-00C04F990BB4>
sCLSID_DOMDocument26              textequ <F5078F1B-C551-11D3-89B9-0000F81FE221>
sCLSID_DOMDocument30              textequ <F5078F32-C551-11D3-89B9-0000F81FE221>
sCLSID_DOMDocument40              textequ <88D969C0-F192-11D4-A65F-0040963251E5>
sCLSID_FreeThreadedDOMDocument    textequ <F6D90F12-9C73-11D3-B32E-00C04F990BB4>
sCLSID_FreeThreadedDOMDocument26  textequ <F5078F1C-C551-11D3-89B9-0000F81FE221>
sCLSID_FreeThreadedDOMDocument30  textequ <F5078F33-C551-11D3-89B9-0000F81FE221>
sCLSID_FreeThreadedDOMDocument40  textequ <88D969C1-F192-11D4-A65F-0040963251E5>
sCLSID_XMLSchemaCache             textequ <373984C9-B845-449B-91E7-45AC83036ADE>
sCLSID_XMLSchemaCache26           textequ <F5078F1D-C551-11D3-89B9-0000F81FE221>
sCLSID_XMLSchemaCache30           textequ <F5078F34-C551-11D3-89B9-0000F81FE221>
sCLSID_XMLSchemaCache40           textequ <88D969C2-F192-11D4-A65F-0040963251E5>
sCLSID_XSLTemplate                textequ <2933BF94-7B36-11D2-B20E-00C04F983E60>
sCLSID_XSLTemplate26              textequ <F5078F21-C551-11D3-89B9-0000F81FE221>
sCLSID_XSLTemplate30              textequ <F5078F36-C551-11D3-89B9-0000F81FE221>
sCLSID_XSLTemplate40              textequ <88D969C3-F192-11D4-A65F-0040963251E5>
sCLSID_DSOControl                 textequ <F6D90F14-9C73-11D3-B32E-00C04F990BB4>
sCLSID_DSOControl26               textequ <F5078F1F-C551-11D3-89B9-0000F81FE221>
sCLSID_DSOControl30               textequ <F5078F39-C551-11D3-89B9-0000F81FE221>
sCLSID_DSOControl40               textequ <88D969C4-F192-11D4-A65F-0040963251E5>
sCLSID_XMLHTTP                    textequ <F6D90F16-9C73-11D3-B32E-00C04F990BB4>
sCLSID_XMLHTTP26                  textequ <F5078F1E-C551-11D3-89B9-0000F81FE221>
sCLSID_XMLHTTP30                  textequ <F5078F35-C551-11D3-89B9-0000F81FE221>
sCLSID_XMLHTTP40                  textequ <88D969C5-F192-11D4-A65F-0040963251E5>
sCLSID_ServerXMLHTTP              textequ <AFBA6B42-5692-48EA-8141-DC517DCF0EF1>
sCLSID_ServerXMLHTTP30            textequ <AFB40FFD-B609-40A3-9828-F88BBE11E4E3>
sCLSID_ServerXMLHTTP40            textequ <88D969C6-F192-11D4-A65F-0040963251E5>
sCLSID_SAXXMLReader               textequ <079AA557-4A18-424A-8EEE-E39F0A8D41B9>
sCLSID_SAXXMLReader30             textequ <3124C396-FB13-4836-A6AD-1317F1713688>
sCLSID_SAXXMLReader40             textequ <7C6E29BC-8B8B-4C3D-859E-AF6CD158BE0F>
sCLSID_MXXMLWriter                textequ <FC220AD8-A72A-4EE8-926E-0B7AD152A020>
sCLSID_MXXMLWriter30              textequ <3D813DFE-6C91-4A4E-8F41-04346A841D9C>
sCLSID_MXXMLWriter40              textequ <88D969C8-F192-11D4-A65F-0040963251E5>
sCLSID_MXHTMLWriter               textequ <A4C23EC3-6B70-4466-9127-550077239978>
sCLSID_MXHTMLWriter30             textequ <853D1540-C1A7-4AA9-A226-4D3BD301146D>
sCLSID_MXHTMLWriter40             textequ <88D969C9-F192-11D4-A65F-0040963251E5>
sCLSID_SAXAttributes              textequ <4DD441AD-526D-4A77-9F1B-9841ED802FB0>
sCLSID_SAXAttributes30            textequ <3E784A01-F3AE-4DC0-9354-9526B9370EBA>
sCLSID_SAXAttributes40            textequ <88D969CA-F192-11D4-A65F-0040963251E5>
sCLSID_MXNamespaceManager         textequ <88D969D5-F192-11D4-A65F-0040963251E5>
sCLSID_MXNamespaceManager40       textequ <88D969D6-F192-11D4-A65F-0040963251E5>
sCLSID_XMLDocument                textequ <CFC399AF-D876-11D0-9C10-00C04FC99C8E>



tagDOMNodeType typedef SDWORD
NODE_INVALID                        equ  0
NODE_ELEMENT                        equ  1
NODE_ATTRIBUTE                      equ  2
NODE_TEXT                           equ  3
NODE_CDATA_SECTION                  equ  4
NODE_ENTITY_REFERENCE               equ  5
NODE_ENTITY                         equ  6
NODE_PROCESSING_INSTRUCTION         equ  7
NODE_COMMENT                        equ  8
NODE_DOCUMENT                       equ  9
NODE_DOCUMENT_TYPE                  equ  10
NODE_DOCUMENT_FRAGMENT              equ  11
NODE_NOTATION                       equ  12


_SOMITEMTYPE typedef SDWORD
SOMITEM_SCHEMA                      equ  4096      ;=01000h
SOMITEM_ATTRIBUTE                   equ  4097      ;=01001h
SOMITEM_ATTRIBUTEGROUP              equ  4098      ;=01002h
SOMITEM_NOTATION                    equ  4099      ;=01003h
SOMITEM_IDENTITYCONSTRAINT          equ  4352      ;=01100h
SOMITEM_KEY                         equ  4353      ;=01101h
SOMITEM_KEYREF                      equ  4354      ;=01102h
SOMITEM_UNIQUE                      equ  4355      ;=01103h
SOMITEM_ANYTYPE                     equ  8192      ;=02000h
SOMITEM_DATATYPE                    equ  8448      ;=02100h
SOMITEM_DATATYPE_ANYTYPE            equ  8449      ;=02101h
SOMITEM_DATATYPE_ANYURI             equ  8450      ;=02102h
SOMITEM_DATATYPE_BASE64BINARY       equ  8451    ;=02103h
SOMITEM_DATATYPE_BOOLEAN            equ  8452      ;=02104h
SOMITEM_DATATYPE_BYTE               equ  8453      ;=02105h
SOMITEM_DATATYPE_DATE               equ  8454      ;=02106h
SOMITEM_DATATYPE_DATETIME           equ  8455      ;=02107h
SOMITEM_DATATYPE_DAY                equ  8456      ;=02108h
SOMITEM_DATATYPE_DECIMAL            equ  8457      ;=02109h
SOMITEM_DATATYPE_DOUBLE             equ  8458      ;=0210Ah
SOMITEM_DATATYPE_DURATION           equ  8459      ;=0210Bh
SOMITEM_DATATYPE_ENTITIES           equ  8460      ;=0210Ch
SOMITEM_DATATYPE_ENTITY             equ  8461      ;=0210Dh
SOMITEM_DATATYPE_FLOAT              equ  8462      ;=0210Eh
SOMITEM_DATATYPE_HEXBINARY          equ  8463      ;=0210Fh
SOMITEM_DATATYPE_ID                 equ  8464      ;=02110h
SOMITEM_DATATYPE_IDREF              equ  8465      ;=02111h
SOMITEM_DATATYPE_IDREFS             equ  8466      ;=02112h
SOMITEM_DATATYPE_INT                equ  8467      ;=02113h
SOMITEM_DATATYPE_INTEGER            equ  8468      ;=02114h
SOMITEM_DATATYPE_LANGUAGE           equ  8469      ;=02115h
SOMITEM_DATATYPE_LONG               equ  8470      ;=02116h
SOMITEM_DATATYPE_MONTH              equ  8471      ;=02117h
SOMITEM_DATATYPE_MONTHDAY           equ  8472      ;=02118h
SOMITEM_DATATYPE_NAME               equ  8473      ;=02119h
SOMITEM_DATATYPE_NCNAME             equ  8474      ;=0211Ah
SOMITEM_DATATYPE_NEGATIVEINTEGER    equ  8475      ;=0211Bh
SOMITEM_DATATYPE_NMTOKEN            equ  8476      ;=0211Ch
SOMITEM_DATATYPE_NMTOKENS           equ  8477      ;=0211Dh
SOMITEM_DATATYPE_NONNEGATIVEINTEGER equ  8478      ;=0211Eh
SOMITEM_DATATYPE_NONPOSITIVEINTEGER equ  8479      ;=0211Fh
SOMITEM_DATATYPE_NORMALIZEDSTRING   equ  8480      ;=02120h
SOMITEM_DATATYPE_NOTATION           equ  8481      ;=02121h
SOMITEM_DATATYPE_POSITIVEINTEGER    equ  8482      ;=02122h
SOMITEM_DATATYPE_QNAME              equ  8483      ;=02123h
SOMITEM_DATATYPE_SHORT              equ  8484      ;=02124h
SOMITEM_DATATYPE_STRING             equ  8485      ;=02125h
SOMITEM_DATATYPE_TIME               equ  8486      ;=02126h
SOMITEM_DATATYPE_TOKEN              equ  8487      ;=02127h
SOMITEM_DATATYPE_UNSIGNEDBYTE       equ  8488      ;=02128h
SOMITEM_DATATYPE_UNSIGNEDINT        equ  8489      ;=02129h
SOMITEM_DATATYPE_UNSIGNEDLONG       equ  8490      ;=0212Ah
SOMITEM_DATATYPE_UNSIGNEDSHORT      equ  8491      ;=0212Bh
SOMITEM_DATATYPE_YEAR               equ  8492      ;=0212Ch
SOMITEM_DATATYPE_YEARMONTH          equ  8493      ;=0212Dh
SOMITEM_DATATYPE_ANYSIMPLETYPE      equ  8703      ;=021FFh
SOMITEM_SIMPLETYPE                  equ  8704      ;=02200h
SOMITEM_COMPLEXTYPE                 equ  9216      ;=02400h
SOMITEM_PARTICLE                    equ  16384      ;=04000h
SOMITEM_ANY                         equ  16385      ;=04001h
SOMITEM_ANYATTRIBUTE                equ  16386      ;=04002h
SOMITEM_ELEMENT                     equ  16387      ;=04003h
SOMITEM_GROUP                       equ  16640      ;=04100h
SOMITEM_ALL                         equ  16641      ;=04101h
SOMITEM_CHOICE                      equ  16642      ;=04102h
SOMITEM_SEQUENCE                    equ  16643      ;=04103h
SOMITEM_EMPTYPARTICLE               equ  16644      ;=04104h
SOMITEM_NULL                        equ  2048      ;=0800h
SOMITEM_NULL_TYPE                   equ  10240      ;=02800h
SOMITEM_NULL_ANY                    equ  18433      ;=04801h
SOMITEM_NULL_ANYATTRIBUTE           equ  18434      ;=04802h
SOMITEM_NULL_ELEMENT                equ  18435      ;=04803h


_SCHEMADERIVATIONMETHOD typedef SDWORD
SCHEMADERIVATIONMETHOD_EMPTY        equ  0
SCHEMADERIVATIONMETHOD_SUBSTITUTION equ  1
SCHEMADERIVATIONMETHOD_EXTENSION    equ  2
SCHEMADERIVATIONMETHOD_RESTRICTION  equ  4
SCHEMADERIVATIONMETHOD_LIST         equ  8
SCHEMADERIVATIONMETHOD_UNION        equ  16      ;=010h
SCHEMADERIVATIONMETHOD_ALL          equ  255      ;=0FFh
SCHEMADERIVATIONMETHOD_NONE         equ  256      ;=0100h


_SCHEMATYPEVARIETY typedef SDWORD
SCHEMATYPEVARIETY_NONE              equ  -1
SCHEMATYPEVARIETY_ATOMIC            equ  0
SCHEMATYPEVARIETY_LIST              equ  1
SCHEMATYPEVARIETY_UNION             equ  2


_SCHEMAWHITESPACE typedef SDWORD
SCHEMAWHITESPACE_NONE               equ  -1
SCHEMAWHITESPACE_PRESERVE           equ  0
SCHEMAWHITESPACE_REPLACE            equ  1
SCHEMAWHITESPACE_COLLAPSE           equ  2


_SCHEMAPROCESSCONTENTS typedef SDWORD
SCHEMAPROCESSCONTENTS_NONE          equ  0
SCHEMAPROCESSCONTENTS_SKIP          equ  1
SCHEMAPROCESSCONTENTS_LAX           equ  2
SCHEMAPROCESSCONTENTS_STRICT        equ  3


_SCHEMACONTENTTYPE typedef SDWORD
SCHEMACONTENTTYPE_EMPTY             equ  0
SCHEMACONTENTTYPE_TEXTONLY          equ  1
SCHEMACONTENTTYPE_ELEMENTONLY       equ  2
SCHEMACONTENTTYPE_MIXED             equ  3


_SCHEMAUSE typedef SDWORD
SCHEMAUSE_OPTIONAL                  equ  0
SCHEMAUSE_PROHIBITED                equ  1
SCHEMAUSE_REQUIRED                  equ  2


tagXMLEMEM_TYPE typedef SDWORD
XMLELEMTYPE_ELEMENT                 equ  0
XMLELEMTYPE_TEXT                    equ  1
XMLELEMTYPE_COMMENT                 equ  2
XMLELEMTYPE_DOCUMENT                equ  3
XMLELEMTYPE_DTD                     equ  4
XMLELEMTYPE_PI                      equ  5
XMLELEMTYPE_OTHER                   equ  6


_SERVERXMLHTTP_OPTION typedef SDWORD
SXH_OPTION_URL                      equ  -1
SXH_OPTION_URL_CODEPAGE             equ  0
SXH_OPTION_ESCAPE_PERCENT_IN_URL    equ  1
SXH_OPTION_IGNORE_SERVER_SSL_CERT_ERROR_FLAGS  equ  2
SXH_OPTION_SELECT_CLIENT_SSL_CERT   equ  3


_SXH_SERVER_CERT_OPTION typedef SDWORD
SXH_SERVER_CERT_IGNORE_UNKNOWN_CA   equ  256            ;=0100h
SXH_SERVER_CERT_IGNORE_WRONG_USAGE  equ  512            ;=0200h
SXH_SERVER_CERT_IGNORE_CERT_CN_INVALID    equ  4096     ;=01000h
SXH_SERVER_CERT_IGNORE_CERT_DATE_INVALID  equ  8192     ;=02000h
SXH_SERVER_CERT_IGNORE_ALL_SERVER_ERRORS  equ  13056    ;=03300h


_SXH_PROXY_SETTING typedef SDWORD
SXH_PROXY_SET_DEFAULT               equ  0
SXH_PROXY_SET_PRECONFIG             equ  0
SXH_PROXY_SET_DIRECT                equ  1
SXH_PROXY_SET_PROXY                 equ  2


_xml_error struc 4
  _nLine        DWORD   ?
  _pchBuf       BSTR    ?
  _cchBuf       DWORD   ?
  _ich          DWORD   ?
  _pszFound     BSTR    ?
  _pszExpected  BSTR    ?
  _reserved1    DWORD   ?
  _reserved2    DWORD   ?
_xml_error ends


SCHEMATYPEVARIETY       typedef _SCHEMATYPEVARIETY
SCHEMAUSE               typedef _SCHEMAUSE
DOMNodeType             typedef tagDOMNodeType
SCHEMAWHITESPACE        typedef _SCHEMAWHITESPACE
XMLELEM_TYPE            typedef tagXMLEMEM_TYPE
SCHEMADERIVATIONMETHOD  typedef _SCHEMADERIVATIONMETHOD
SERVERXMLHTTP_OPTION    typedef _SERVERXMLHTTP_OPTION
SCHEMAPROCESSCONTENTS   typedef _SCHEMAPROCESSCONTENTS
SXH_SERVER_CERT_OPTION  typedef _SXH_SERVER_CERT_OPTION
SOMITEMTYPE             typedef _SOMITEMTYPE
SXH_PROXY_SETTING       typedef _SXH_PROXY_SETTING
SCHEMACONTENTTYPE       typedef _SCHEMACONTENTTYPE

COM_INTERFACE_BEG ISAXXMLReader, IUnknown, <A4F96ED0-F829-476E-81C0-CDC7BD2A0802>
  COM_STD_METHOD  getFeature, :ptr WORD,:ptr BOOL
  COM_STD_METHOD  putFeature, :ptr WORD,:BOOL
  COM_STD_METHOD  getProperty, :ptr WORD,:ptr VARIANT
  COM_STD_METHOD  putProperty, :ptr WORD,:VARIANT
  COM_STD_METHOD  getEntityResolver, :ptr ptr ISAXEntityResolver
  COM_STD_METHOD  putEntityResolver, :ptr ISAXEntityResolver
  COM_STD_METHOD  getContentHandler, :ptr ptr ISAXContentHandler
  COM_STD_METHOD  putContentHandler, :ptr ISAXContentHandler
  COM_STD_METHOD  getDTDHandler, :ptr ptr ISAXDTDHandler
  COM_STD_METHOD  putDTDHandler, :ptr ISAXDTDHandler
  COM_STD_METHOD  getErrorHandler, :ptr ptr ISAXErrorHandler
  COM_STD_METHOD  putErrorHandler, :ptr ISAXErrorHandler
  COM_STD_METHOD  getBaseURL, :ptr ptr WORD
  COM_STD_METHOD  putBaseURL, :ptr WORD
  COM_STD_METHOD  getSecureBaseURL, :ptr ptr WORD
  COM_STD_METHOD  putSecureBaseURL, :ptr WORD
  COM_STD_METHOD  parse, :VARIANT
  COM_STD_METHOD  parseURL, :ptr WORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXEntityResolver, IUnknown, <99BCA7BD-E8C4-4D5F-A0CF-6D907901FF07>
  COM_STD_METHOD  resolveEntity, :ptr WORD,:ptr WORD,:ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXContentHandler, IUnknown, <1545CDFA-9E4E-4497-A8A4-2BF7D0112C44>
  COM_STD_METHOD  putDocumentLocator, :ptr ISAXLocator
  COM_STD_METHOD  startDocument
  COM_STD_METHOD  endDocument
  COM_STD_METHOD  startPrefixMapping, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  endPrefixMapping, :ptr WORD,:SDWORD
  COM_STD_METHOD  startElement, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr ISAXAttributes
  COM_STD_METHOD  endElement, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  characters, :ptr WORD,:SDWORD
  COM_STD_METHOD  ignorableWhitespace,  :ptr WORD,:SDWORD
  COM_STD_METHOD  processingInstruction, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  skippedEntity, :ptr WORD,:SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXLocator, IUnknown, <9B7E472A-0DE4-4640-BFF3-84D38A051C31>
  COM_STD_METHOD  getColumnNumber, :ptr SDWORD
  COM_STD_METHOD  getLineNumber, :ptr SDWORD
  COM_STD_METHOD  getPublicId, :ptr ptr WORD
  COM_STD_METHOD  getSystemId, :ptr ptr WORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXAttributes, IUnknown, <F078ABE1-45D2-4832-91EA-4466CE2F25C9>
  COM_STD_METHOD  getLength, :ptr SDWORD
  COM_STD_METHOD  getURI, :SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getLocalName, :SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getQName, :SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getName, :SDWORD,:ptr ptr WORD,:ptr SDWORD,:ptr ptr WORD,:ptr SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getIndexFromName, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr SDWORD
  COM_STD_METHOD  getIndexFromQName, :ptr WORD,:SDWORD,:ptr SDWORD
  COM_STD_METHOD  getType, :SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getTypeFromName, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getTypeFromQName, :ptr WORD,:SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getValue, :SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getValueFromName, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getValueFromQName, :ptr WORD,:SDWORD,:ptr ptr WORD,:ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXDTDHandler, IUnknown, <E15C1BAF-AFB3-4D60-8C36-19A8C45DEFED>
  COM_STD_METHOD  notationDecl, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  unparsedEntityDecl, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXErrorHandler, IUnknown, <A60511C4-CCF5-479E-98A3-DC8DC545B7D0>
  COM_STD_METHOD  error, :ptr ISAXLocator,:ptr WORD,:HRESULT
  COM_STD_METHOD  fatalError, :ptr ISAXLocator,:ptr WORD,:HRESULT
  COM_STD_METHOD  ignorableWarning, :ptr ISAXLocator,:ptr WORD,:HRESULT
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXXMLFilter, ISAXXMLReader, <70409222-CA09-4475-ACB8-40312FE8D145>
  COM_STD_METHOD  getParent, :ptr ptr ISAXXMLReader
  COM_STD_METHOD  putParent, :ptr ISAXXMLReader
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXLexicalHandler, IUnknown, <7F85D5F5-47A8-4497-BDA5-84BA04819EA6>
  COM_STD_METHOD  startDTD, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  endDTD
  COM_STD_METHOD  startEntity, :ptr WORD,:SDWORD
  COM_STD_METHOD  endEntity, :ptr WORD,:SDWORD
  COM_STD_METHOD  startCDATA
  COM_STD_METHOD  endCDATA
  COM_STD_METHOD  comment_, :ptr WORD,:SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISAXDeclHandler, IUnknown, <862629AC-771A-47B2-8337-4E6843C1BE90>
  COM_STD_METHOD  elementDecl, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  attributeDecl, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  internalEntityDecl, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD
  COM_STD_METHOD  externalEntityDecl, :ptr WORD,:SDWORD,:ptr WORD,:SDWORD,:ptr WORD,:SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXXMLReader, IDispatch, <8C033CAA-6CD6-4F73-B728-4531AF74945F>
  COM_STD_METHOD  getFeature, :BSTR,:ptr BOOL
  COM_STD_METHOD  putFeature, :BSTR,:BOOL
  COM_STD_METHOD  getProperty, :BSTR,:ptr VARIANT
  COM_STD_METHOD  putProperty, :BSTR,:VARIANT
  COM_STD_METHOD  get_entityResolver, :ptr ptr IVBSAXEntityResolver
  COM_STD_METHOD  putref_entityResolver, :ptr IVBSAXEntityResolver
  COM_STD_METHOD  get_contentHandler, :ptr ptr IVBSAXContentHandler
  COM_STD_METHOD  putref_contentHandler, :ptr IVBSAXContentHandler
  COM_STD_METHOD  get_dtdHandler, :ptr ptr IVBSAXDTDHandler
  COM_STD_METHOD  putref_dtdHandler, :ptr IVBSAXDTDHandler
  COM_STD_METHOD  get_errorHandler, :ptr ptr IVBSAXErrorHandler
  COM_STD_METHOD  putref_errorHandler, :ptr IVBSAXErrorHandler
  COM_STD_METHOD  get_baseURL, :ptr BSTR
  COM_STD_METHOD  put_baseURL, :BSTR
  COM_STD_METHOD  get_secureBaseURL, :ptr BSTR
  COM_STD_METHOD  put_secureBaseURL, :BSTR
  COM_STD_METHOD  parse, :VARIANT
  COM_STD_METHOD  parseURL, :BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXEntityResolver, IDispatch, <0C05D096-F45B-4ACA-AD1A-AA0BC25518DC>
  COM_STD_METHOD  resolveEntity, :ptr BSTR,:ptr BSTR,:ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXContentHandler, IDispatch, <2ED7290A-4DD5-4B46-BB26-4E4155E77FAA>
  COM_STD_METHOD  putref_documentLocator, :ptr IVBSAXLocator
  COM_STD_METHOD  startDocument
  COM_STD_METHOD  endDocument
  COM_STD_METHOD  startPrefixMapping, :ptr BSTR,:ptr BSTR
  COM_STD_METHOD  endPrefixMapping, :ptr BSTR
  COM_STD_METHOD  startElement, :ptr BSTR,:ptr BSTR,:ptr BSTR,:ptr IVBSAXAttributes
  COM_STD_METHOD  endElement, :ptr BSTR,:ptr BSTR,:ptr BSTR
  COM_STD_METHOD  characters, :ptr BSTR
  COM_STD_METHOD  ignorableWhitespace, :ptr BSTR
  COM_STD_METHOD  processingInstruction, :ptr BSTR,:ptr BSTR
  COM_STD_METHOD  skippedEntity, :ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXLocator, IDispatch, <796E7AC5-5AA2-4EFF-ACAD-3FAAF01A3288>
  COM_STD_METHOD  get_columnNumber, :ptr SDWORD
  COM_STD_METHOD  get_lineNumber, :ptr SDWORD
  COM_STD_METHOD  get_publicId, :ptr BSTR
  COM_STD_METHOD  get_systemId, :ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXAttributes, IDispatch, <10DC0586-132B-4CAC-8BB3-DB00AC8B7EE0>
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  getURI, :SDWORD,:ptr BSTR
  COM_STD_METHOD  getLocalName, :SDWORD,:ptr BSTR
  COM_STD_METHOD  getQName, :SDWORD,:ptr BSTR
  COM_STD_METHOD  getIndexFromName, :BSTR,:BSTR,:ptr SDWORD
  COM_STD_METHOD  getIndexFromQName, :BSTR,:ptr SDWORD
  COM_STD_METHOD  getType, :SDWORD,:ptr BSTR
  COM_STD_METHOD  getTypeFromName, :BSTR,:BSTR,:ptr BSTR
  COM_STD_METHOD  getTypeFromQName, :BSTR,:ptr BSTR
  COM_STD_METHOD  getValue, :SDWORD,:ptr BSTR
  COM_STD_METHOD  getValueFromName, :BSTR,:BSTR,:ptr BSTR
  COM_STD_METHOD  getValueFromQName, :BSTR,:ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXDTDHandler, IDispatch, <24FB3297-302D-4620-BA39-3A732D850558>
  COM_STD_METHOD  notationDecl, :ptr BSTR,:ptr BSTR,:ptr BSTR
  COM_STD_METHOD  unparsedEntityDecl, :ptr BSTR,:ptr BSTR,:ptr BSTR,:ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXErrorHandler, IDispatch, <D963D3FE-173C-4862-9095-B92F66995F52>
  COM_STD_METHOD  error, :ptr IVBSAXLocator,:ptr BSTR,:SDWORD
  COM_STD_METHOD  fatalError, :ptr IVBSAXLocator,:ptr BSTR,:SDWORD
  COM_STD_METHOD  ignorableWarning, :ptr IVBSAXLocator,:ptr BSTR,:SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXXMLFilter, IDispatch, <1299EB1B-5B88-433E-82DE-82CA75AD4E04>
  COM_STD_METHOD  get_parent, :ptr ptr IVBSAXXMLReader
  COM_STD_METHOD  putref_parent, :ptr IVBSAXXMLReader
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXLexicalHandler, IDispatch, <032AAC35-8C0E-4D9D-979F-E3B702935576>
  COM_STD_METHOD  startDTD, :ptr BSTR,:ptr BSTR,:ptr BSTR
  COM_STD_METHOD  endDTD
  COM_STD_METHOD  startEntity, :ptr BSTR
  COM_STD_METHOD  endEntity, :ptr BSTR
  COM_STD_METHOD  startCDATA
  COM_STD_METHOD  endCDATA
  COM_STD_METHOD  comment_, :ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IVBSAXDeclHandler, IDispatch, <E8917260-7579-4BE1-B5DD-7AFBFA6F077B>
  COM_STD_METHOD  elementDecl, :ptr BSTR,:ptr BSTR
  COM_STD_METHOD  attributeDecl, :ptr BSTR,:ptr BSTR,:ptr BSTR,:ptr BSTR,:ptr BSTR
  COM_STD_METHOD  internalEntityDecl, :ptr BSTR,:ptr BSTR
  COM_STD_METHOD  externalEntityDecl, :ptr BSTR,:ptr BSTR,:ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IMXWriter, IDispatch, <4D7FF4BA-1565-4EA8-94E1-6E724A46F98D>
  COM_STD_METHOD  put_output, :VARIANT
  COM_STD_METHOD  get_output, :ptr VARIANT
  COM_STD_METHOD  put_encoding, :BSTR
  COM_STD_METHOD  get_encoding, :ptr BSTR
  COM_STD_METHOD  put_byteOrderMark, :BOOL
  COM_STD_METHOD  get_byteOrderMark, :ptr BOOL
  COM_STD_METHOD  put_indent, :BOOL
  COM_STD_METHOD  get_indent, :ptr BOOL
  COM_STD_METHOD  put_standalone, :BOOL
  COM_STD_METHOD  get_standalone, :ptr BOOL
  COM_STD_METHOD  put_omitXMLDeclaration, :BOOL
  COM_STD_METHOD  get_omitXMLDeclaration, :ptr BOOL
  COM_STD_METHOD  put_version, :BSTR
  COM_STD_METHOD  get_version, :ptr BSTR
  COM_STD_METHOD  put_disableOutputEscaping, :BOOL
  COM_STD_METHOD  get_disableOutputEscaping, :ptr BOOL
  COM_STD_METHOD  flush
COM_INTERFACE_END

COM_INTERFACE_BEG IMXAttributes, IDispatch, <F10D27CC-3EC0-415C-8ED8-77AB1C5E7262>
  COM_STD_METHOD  addAttribute, :BSTR,:BSTR,:BSTR,:BSTR,:BSTR
  COM_STD_METHOD  addAttributeFromIndex, :VARIANT,:SDWORD
  COM_STD_METHOD  clear
  COM_STD_METHOD  removeAttribute, :SDWORD
  COM_STD_METHOD  setAttribute, :SDWORD,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR
  COM_STD_METHOD  setAttributes, :VARIANT
  COM_STD_METHOD  setLocalName, :SDWORD,:BSTR
  COM_STD_METHOD  setQName, :SDWORD,:BSTR
  COM_STD_METHOD  setType, :SDWORD,:BSTR
  COM_STD_METHOD  setURI, :SDWORD,:BSTR
  COM_STD_METHOD  setValue, :SDWORD,:BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IMXReaderControl, IDispatch, <808F4E35-8D5A-4FBE-8466-33A41279ED30>
  COM_STD_METHOD  abort
  COM_STD_METHOD  resume
  COM_STD_METHOD  suspend
COM_INTERFACE_END

COM_INTERFACE_BEG IMXSchemaDeclHandler, IDispatch, <FA4BB38C-FAF9-4CCA-9302-D1DD0FE520DB>
  COM_STD_METHOD  schemaElementDecl, :ptr ISchemaElement
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaItem, IDispatch, <50EA08B3-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_name, :ptr BSTR
  COM_STD_METHOD  get_namespaceURI, :ptr BSTR
  COM_STD_METHOD  get_schema, :ptr ptr ISchema
  COM_STD_METHOD  get_id, :ptr BSTR
  COM_STD_METHOD  get_itemType, :ptr SOMITEMTYPE
  COM_STD_METHOD  get_unhandledAttributes, :ptr ptr IVBSAXAttributes
  COM_STD_METHOD  writeAnnotation, :LPUNKNOWN,:ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaParticle, ISchemaItem, <50EA08B5-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_minOccurs, :ptr VARIANT
  COM_STD_METHOD  get_maxOccurs, :ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaElement, ISchemaParticle, <50EA08B7-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_type, :ptr ptr ISchemaType
  COM_STD_METHOD  get_scope, :ptr ptr ISchemaComplexType
  COM_STD_METHOD  get_defaultValue, :ptr BSTR
  COM_STD_METHOD  get_fixedValue, :ptr BSTR
  COM_STD_METHOD  get_isNillable, :ptr BOOL
  COM_STD_METHOD  get_identityConstraints, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_substitutionGroup, :ptr ptr ISchemaElement
  COM_STD_METHOD  get_substitutionGroupExclusions, :ptr SCHEMADERIVATIONMETHOD
  COM_STD_METHOD  get_disallowedSubstitutions, :ptr SCHEMADERIVATIONMETHOD
  COM_STD_METHOD  get_isAbstract, :ptr BOOL
  COM_STD_METHOD  get_isReference, :ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ISchema, ISchemaItem, <50EA08B4-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_targetNamespace, :ptr BSTR
  COM_STD_METHOD  get_version, :ptr BSTR
  COM_STD_METHOD  get_types, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_elements, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_attributes, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_attributeGroups, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_modelGroups, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_notations, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_schemaLocations, :ptr ptr ISchemaStringCollection
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaItemCollection, IDispatch, <50EA08B2-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_item, :SDWORD,:ptr ptr ISchemaItem
  COM_STD_METHOD  itemByName, :BSTR,:ptr ptr ISchemaItem
  COM_STD_METHOD  itemByQName, :BSTR,:BSTR,:ptr ptr ISchemaItem
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaStringCollection, IDispatch, <50EA08B1-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_item, :SDWORD,:ptr BSTR
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMImplementation, IDispatch, <2933BF8F-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  hasFeature, :BSTR,:BSTR,:ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMNode, IDispatch, <2933BF80-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_nodeName, :ptr BSTR
  COM_STD_METHOD  get_nodeValue, :ptr VARIANT
  COM_STD_METHOD  put_nodeValue, :VARIANT
  COM_STD_METHOD  get_nodeType, :ptr DOMNodeType
  COM_STD_METHOD  get_parentNode, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_childNodes, :ptr ptr IXMLDOMNodeList
  COM_STD_METHOD  get_firstChild, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_lastChild, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_previousSibling, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_nextSibling, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_attributes, :ptr ptr IXMLDOMNamedNodeMap
  COM_STD_METHOD  insertBefore, :ptr IXMLDOMNode,:VARIANT,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  replaceChild, :ptr IXMLDOMNode,:ptr IXMLDOMNode,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  removeChild, :ptr IXMLDOMNode,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  appendChild, :ptr IXMLDOMNode,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  hasChildNodes, :ptr BOOL
  COM_STD_METHOD  get_ownerDocument, :ptr ptr IXMLDOMDocument
  COM_STD_METHOD  cloneNode, :BOOL,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_nodeTypeString, :ptr BSTR
  COM_STD_METHOD  get_text, :ptr BSTR
  COM_STD_METHOD  put_text, :BSTR
  COM_STD_METHOD  get_specified, :ptr BOOL
  COM_STD_METHOD  get_definition, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_nodeTypedValue, :ptr VARIANT
  COM_STD_METHOD  put_nodeTypedValue, :VARIANT
  COM_STD_METHOD  get_dataType, :ptr VARIANT
  COM_STD_METHOD  put_dataType, :BSTR
  COM_STD_METHOD  get_xml, :ptr BSTR
  COM_STD_METHOD  transformNode, :ptr IXMLDOMNode,:ptr BSTR
  COM_STD_METHOD  selectNodes, :BSTR,:ptr ptr IXMLDOMNodeList
  COM_STD_METHOD  selectSingleNode, :BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_parsed, :ptr BOOL
  COM_STD_METHOD  get_namespaceURI, :ptr BSTR
  COM_STD_METHOD  get_prefix, :ptr BSTR
  COM_STD_METHOD  get_baseName, :ptr BSTR
  COM_STD_METHOD  transformNodeToObject, :ptr IXMLDOMNode,:VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaType, ISchemaItem, <50EA08B8-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_baseTypes, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_final, :ptr SCHEMADERIVATIONMETHOD
  COM_STD_METHOD  get_variety, :ptr SCHEMATYPEVARIETY
  COM_STD_METHOD  get_derivedBy, :ptr SCHEMADERIVATIONMETHOD
  COM_STD_METHOD  isValid, :BSTR,:ptr BOOL
  COM_STD_METHOD  get_minExclusive, :ptr BSTR
  COM_STD_METHOD  get_minInclusive, :ptr BSTR
  COM_STD_METHOD  get_maxExclusive, :ptr BSTR
  COM_STD_METHOD  get_maxInclusive, :ptr BSTR
  COM_STD_METHOD  get_totalDigits, :ptr VARIANT
  COM_STD_METHOD  get_fractionDigits, :ptr VARIANT
  COM_STD_METHOD  get_length, :ptr VARIANT
  COM_STD_METHOD  get_minLength, :ptr VARIANT
  COM_STD_METHOD  get_maxLength, :ptr VARIANT
  COM_STD_METHOD  get_enumeration, :ptr ptr ISchemaStringCollection
  COM_STD_METHOD  get_whitespace, :ptr SCHEMAWHITESPACE
  COM_STD_METHOD  get_patterns, :ptr ptr ISchemaStringCollection
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMNodeList, IDispatch, <2933BF82-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_item, :SDWORD,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  nextNode, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  reset
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMNamedNodeMap, IDispatch, <2933BF83-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  getNamedItem, :BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  setNamedItem, :ptr IXMLDOMNode,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  removeNamedItem, :BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_item, :SDWORD,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  getQualifiedItem, :BSTR,:BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  removeQualifiedItem, :BSTR,:BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  nextNode, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  reset
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMDocumentType, IXMLDOMNode, <2933BF8B-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_name, :ptr BSTR
  COM_STD_METHOD  get_entities, :ptr ptr IXMLDOMNamedNodeMap
  COM_STD_METHOD  get_notations, :ptr ptr IXMLDOMNamedNodeMap
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMElement, IXMLDOMNode, <2933BF86-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_tagName, :ptr BSTR
  COM_STD_METHOD  getAttribute, :BSTR,:ptr VARIANT
  COM_STD_METHOD  setAttribute, :BSTR,:VARIANT
  COM_STD_METHOD  removeAttribute, :BSTR
  COM_STD_METHOD  getAttributeNode, :BSTR,:ptr ptr IXMLDOMAttribute
  COM_STD_METHOD  setAttributeNode, :ptr IXMLDOMAttribute,:ptr ptr IXMLDOMAttribute
  COM_STD_METHOD  removeAttributeNode, :ptr IXMLDOMAttribute,:ptr ptr IXMLDOMAttribute
  COM_STD_METHOD  getElementsByTagName, :BSTR,:ptr ptr IXMLDOMNodeList
  COM_STD_METHOD  normalize
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMAttribute, IXMLDOMNode, <2933BF85-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_name, :ptr BSTR
  COM_STD_METHOD  get_value, :ptr VARIANT
  COM_STD_METHOD  put_value, :VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMDocumentFragment, IXMLDOMNode, <3EFAA413-272F-11D2-836F-0000F87A7782>
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaComplexType, ISchemaType, <50EA08B9-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_isAbstract, :ptr BOOL
  COM_STD_METHOD  get_anyAttribute, :ptr ptr ISchemaAny
  COM_STD_METHOD  get_attributes, :ptr ptr ISchemaItemCollection
  COM_STD_METHOD  get_contentType, :ptr SCHEMACONTENTTYPE
  COM_STD_METHOD  get_contentModel, :ptr ptr ISchemaModelGroup
  COM_STD_METHOD  get_prohibitedSubstitutions, :ptr SCHEMADERIVATIONMETHOD
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaAny, ISchemaParticle, <50EA08BC-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_namespaces, :ptr ptr ISchemaStringCollection
  COM_STD_METHOD  get_processContents, :ptr SCHEMAPROCESSCONTENTS
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMCharacterData, IXMLDOMNode, <2933BF84-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_data, :ptr BSTR
  COM_STD_METHOD  put_data, :BSTR
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  substringData, :SDWORD,:SDWORD,:ptr BSTR
  COM_STD_METHOD  appendData, :BSTR
  COM_STD_METHOD  insertData, :SDWORD,:BSTR
  COM_STD_METHOD  deleteData, :SDWORD,:SDWORD
  COM_STD_METHOD  replaceData, :SDWORD,:SDWORD,:BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMComment, IXMLDOMCharacterData, <2933BF88-7B36-11D2-B20E-00C04F983E60>
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMText, IXMLDOMCharacterData, <2933BF87-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  splitText, :SDWORD,:ptr ptr IXMLDOMText
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMCDATASection, IXMLDOMText, <2933BF8A-7B36-11D2-B20E-00C04F983E60>
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaModelGroup, ISchemaParticle, <50EA08BB-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_particles, :ptr ptr ISchemaItemCollection
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMSchemaCollection, IDispatch, <373984C8-B845-449B-91E7-45AC83036ADE>
  COM_STD_METHOD  add_, :BSTR,:VARIANT
  COM_STD_METHOD  get, :BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  remove, :BSTR
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  get_namespaceURI, :SDWORD,:ptr BSTR
  COM_STD_METHOD  addCollection, :ptr IXMLDOMSchemaCollection
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaAttribute, ISchemaItem, <50EA08B6-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_type, :ptr ptr ISchemaType
  COM_STD_METHOD  get_scope, :ptr ptr ISchemaComplexType
  COM_STD_METHOD  get_defaultValue, :ptr BSTR
  COM_STD_METHOD  get_fixedValue, :ptr BSTR
  COM_STD_METHOD  get_use, :ptr SCHEMAUSE
  COM_STD_METHOD  get_isReference, :ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMProcessingInstruction, IXMLDOMNode, <2933BF89-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_target, :ptr BSTR
  COM_STD_METHOD  get_data, :ptr BSTR
  COM_STD_METHOD  put_data, :BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMEntityReference, IXMLDOMNode, <2933BF8E-7B36-11D2-B20E-00C04F983E60>
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaAttributeGroup, ISchemaItem, <50EA08BA-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_anyAttribute, :ptr ptr ISchemaAny
  COM_STD_METHOD  get_attributes, :ptr ptr ISchemaItemCollection
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaIdentityConstraint, ISchemaItem, <50EA08BD-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_selector, :ptr BSTR
  COM_STD_METHOD  get_fields, :ptr ptr ISchemaStringCollection
  COM_STD_METHOD  get_referencedKey, :ptr ptr ISchemaIdentityConstraint
COM_INTERFACE_END

COM_INTERFACE_BEG ISchemaNotation, ISchemaItem, <50EA08BE-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  get_systemIdentifier, :ptr BSTR
  COM_STD_METHOD  get_publicIdentifier, :ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLElementCollection, IDispatch, <65725580-9B5D-11D0-9BFE-00C04FC99C8E>
  COM_STD_METHOD  put_length, :SDWORD
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
  COM_STD_METHOD  item, :VARIANT,:VARIANT,:ptr LPDISPATCH
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDocument, IDispatch, <F52E2B61-18A1-11D1-B105-00805F49916B>
  COM_STD_METHOD  get_root, :ptr ptr IXMLElement
  COM_STD_METHOD  get_fileSize, :ptr BSTR
  COM_STD_METHOD  get_fileModifiedDate, :ptr BSTR
  COM_STD_METHOD  get_fileUpdatedDate, :ptr BSTR
  COM_STD_METHOD  get_url, :ptr BSTR
  COM_STD_METHOD  put_url, :BSTR
  COM_STD_METHOD  get_mimeType, :ptr BSTR
  COM_STD_METHOD  get_readyState, :ptr SDWORD
  COM_STD_METHOD  get_charset, :ptr BSTR
  COM_STD_METHOD  put_charset, :BSTR
  COM_STD_METHOD  get_version, :ptr BSTR
  COM_STD_METHOD  get_doctype, :ptr BSTR
  COM_STD_METHOD  get_dtdURL, :ptr BSTR
  COM_STD_METHOD  createElement, :VARIANT,:VARIANT,:ptr ptr IXMLElement
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLElement, IDispatch, <3F7F31AC-E15F-11D0-9C25-00C04FC99C8E>
  COM_STD_METHOD  get_tagName, :ptr BSTR
  COM_STD_METHOD  put_tagName, :BSTR
  COM_STD_METHOD  get_parent, :ptr ptr IXMLElement
  COM_STD_METHOD  setAttribute, :BSTR,:VARIANT
  COM_STD_METHOD  getAttribute, :BSTR,:ptr VARIANT
  COM_STD_METHOD  removeAttribute, :BSTR
  COM_STD_METHOD  get_children, :ptr ptr IXMLElementCollection
  COM_STD_METHOD  get_type, :ptr SDWORD
  COM_STD_METHOD  get_text, :ptr BSTR
  COM_STD_METHOD  put_text, :BSTR
  COM_STD_METHOD  addChild, :ptr IXMLElement,:SDWORD,:SDWORD
  COM_STD_METHOD  removeChild, :ptr IXMLElement
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDocument2, IDispatch, <2B8DE2FE-8D2D-11D1-B2FC-00C04FD915A9>
  COM_STD_METHOD  get_root, :ptr ptr IXMLElement2
  COM_STD_METHOD  get_fileSize, :ptr BSTR
  COM_STD_METHOD  get_fileModifiedDate, :ptr BSTR
  COM_STD_METHOD  get_fileUpdatedDate, :ptr BSTR
  COM_STD_METHOD  get_url, :ptr BSTR
  COM_STD_METHOD  put_url, :BSTR
  COM_STD_METHOD  get_mimeType, :ptr BSTR
  COM_STD_METHOD  get_readyState, :ptr SDWORD
  COM_STD_METHOD  get_charset, :ptr BSTR
  COM_STD_METHOD  put_charset, :BSTR
  COM_STD_METHOD  get_version, :ptr BSTR
  COM_STD_METHOD  get_doctype, :ptr BSTR
  COM_STD_METHOD  get_dtdURL, :ptr BSTR
  COM_STD_METHOD  createElement, :VARIANT,:VARIANT,:ptr ptr IXMLElement2
  COM_STD_METHOD  get_async, :ptr BOOL
  COM_STD_METHOD  put_async, :BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLElement2, IDispatch, <2B8DE2FF-8D2D-11D1-B2FC-00C04FD915A9>
  COM_STD_METHOD  get_tagName, :ptr BSTR
  COM_STD_METHOD  put_tagName, :BSTR
  COM_STD_METHOD  get_parent, :ptr ptr IXMLElement2
  COM_STD_METHOD  setAttribute, :BSTR,:VARIANT
  COM_STD_METHOD  getAttribute, :BSTR,:ptr VARIANT
  COM_STD_METHOD  removeAttribute, :BSTR
  COM_STD_METHOD  get_children, :ptr ptr IXMLElementCollection
  COM_STD_METHOD  get_type, :ptr SDWORD
  COM_STD_METHOD  get_text, :ptr BSTR
  COM_STD_METHOD  put_text, :BSTR
  COM_STD_METHOD  addChild, :ptr IXMLElement2,:SDWORD,:SDWORD
  COM_STD_METHOD  removeChild, :ptr IXMLElement2
  COM_STD_METHOD  get_attributes, :ptr ptr IXMLElementCollection
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLAttribute, IDispatch, <D4D4A0FC-3B73-11D1-B2B4-00C04FB92596>
  COM_STD_METHOD  get_name, :ptr BSTR
  COM_STD_METHOD  get_value, :ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLError, IUnknown, <948C5AD3-C58D-11D0-9C0B-00C04FC99C8E>
  COM_STD_METHOD  _GetErrorInfo, :ptr _xml_error
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMDocument, IXMLDOMNode, <2933BF81-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_doctype, :ptr ptr IXMLDOMDocumentType
  COM_STD_METHOD  get_implementation, :ptr ptr IXMLDOMImplementation
  COM_STD_METHOD  get_documentElement, :ptr ptr IXMLDOMElement
  COM_STD_METHOD  putref_documentElement, :ptr IXMLDOMElement
  COM_STD_METHOD  createElement, :BSTR,:ptr ptr IXMLDOMElement
  COM_STD_METHOD  createDocumentFragment, :ptr ptr IXMLDOMDocumentFragment
  COM_STD_METHOD  createTextNode, :BSTR,:ptr ptr IXMLDOMText
  COM_STD_METHOD  createComment, :BSTR,:ptr ptr IXMLDOMComment
  COM_STD_METHOD  createCDATASection, :BSTR,:ptr ptr IXMLDOMCDATASection
  COM_STD_METHOD  createProcessingInstruction, :BSTR,:BSTR,:ptr ptr IXMLDOMProcessingInstruction
  COM_STD_METHOD  createAttribute, :BSTR,:ptr ptr IXMLDOMAttribute
  COM_STD_METHOD  createEntityReference, :BSTR,:ptr ptr IXMLDOMEntityReference
  COM_STD_METHOD  getElementsByTagName, :BSTR,:ptr ptr IXMLDOMNodeList
  COM_STD_METHOD  createNode, :VARIANT,:BSTR,:BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  nodeFromID, :BSTR,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  load, :VARIANT,:ptr BOOL
  COM_STD_METHOD  get_readyState, :ptr SDWORD
  COM_STD_METHOD  get_parseError, :ptr ptr IXMLDOMParseError
  COM_STD_METHOD  get_url, :ptr BSTR
  COM_STD_METHOD  get_async, :ptr BOOL
  COM_STD_METHOD  put_async, :BOOL
  COM_STD_METHOD  abort
  COM_STD_METHOD  loadXML, :BSTR,:ptr BOOL
  COM_STD_METHOD  save, :VARIANT
  COM_STD_METHOD  get_validateOnParse, :ptr BOOL
  COM_STD_METHOD  put_validateOnParse, :BOOL
  COM_STD_METHOD  get_resolveExternals, :ptr BOOL
  COM_STD_METHOD  put_resolveExternals, :BOOL
  COM_STD_METHOD  get_preserveWhiteSpace, :ptr BOOL
  COM_STD_METHOD  put_preserveWhiteSpace, :BOOL
  COM_STD_METHOD  put_onreadystatechange, :VARIANT
  COM_STD_METHOD  put_ondataavailable, :VARIANT
  COM_STD_METHOD  put_ontransformnode, :VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMParseError, IDispatch, <3EFAA426-272F-11D2-836F-0000F87A7782>
  COM_STD_METHOD  get_errorCode, :ptr SDWORD
  COM_STD_METHOD  get_url, :ptr BSTR
  COM_STD_METHOD  get_reason, :ptr BSTR
  COM_STD_METHOD  get_srcText, :ptr BSTR
  COM_STD_METHOD  get_line, :ptr SDWORD
  COM_STD_METHOD  get_linepos, :ptr SDWORD
  COM_STD_METHOD  get_filepos, :ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMNotation, IXMLDOMNode, <2933BF8C-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_publicId, :ptr VARIANT
  COM_STD_METHOD  get_systemId, :ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMSelection, IXMLDOMNodeList, <AA634FC7-5888-44A7-A257-3A47150D3A0E>
  COM_STD_METHOD  get_expr, :ptr BSTR
  COM_STD_METHOD  put_expr, :BSTR
  COM_STD_METHOD  get_context, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  putref_context, :ptr IXMLDOMNode
  COM_STD_METHOD  peekNode, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  matches, :ptr IXMLDOMNode,:ptr ptr IXMLDOMNode
  COM_STD_METHOD  removeNext, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  removeAll
  COM_STD_METHOD  clone, :ptr ptr IXMLDOMSelection
  COM_STD_METHOD  getProperty, :BSTR,:ptr VARIANT
  COM_STD_METHOD  setProperty, :BSTR,:VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IDSOControl, IDispatch, <310AFA62-0575-11D2-9CA9-0060B0EC3D39>
  COM_STD_METHOD  get_XMLDocument, :ptr ptr IXMLDOMDocument
  COM_STD_METHOD  put_XMLDocument, :ptr IXMLDOMDocument
  COM_STD_METHOD  get_JavaDSOCompatible, :ptr SDWORD
  COM_STD_METHOD  put_JavaDSOCompatible, :SDWORD
  COM_STD_METHOD  get_readyState, :ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLHTTPRequest, IDispatch, <ED8C108D-4349-11D2-91A4-00C04F7969E8>
  COM_STD_METHOD  open, :BSTR,:BSTR,:VARIANT,:VARIANT,:VARIANT
  COM_STD_METHOD  setRequestHeader, :BSTR,:BSTR
  COM_STD_METHOD  getResponseHeader, :BSTR,:ptr BSTR
  COM_STD_METHOD  getAllResponseHeaders, :ptr BSTR
  COM_STD_METHOD  _send, :VARIANT
  COM_STD_METHOD  abort
  COM_STD_METHOD  get_status, :ptr SDWORD
  COM_STD_METHOD  get_statusText, :ptr BSTR
  COM_STD_METHOD  get_responseXML, :ptr LPDISPATCH
  COM_STD_METHOD  get_responseText, :ptr BSTR
  COM_STD_METHOD  get_responseBody, :ptr VARIANT
  COM_STD_METHOD  get_responseStream, :ptr VARIANT
  COM_STD_METHOD  get_readyState, :ptr SDWORD
  COM_STD_METHOD  put_onreadystatechange, :LPDISPATCH
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMSchemaCollection2, IXMLDOMSchemaCollection, <50EA08B0-DD1B-4664-9A50-C2F40F4BD79A>
  COM_STD_METHOD  validate
  COM_STD_METHOD  put_validateOnLoad, :BOOL
  COM_STD_METHOD  get_validateOnLoad, :ptr BOOL
  COM_STD_METHOD  getSchema, :BSTR,:ptr ptr ISchema
  COM_STD_METHOD  getDeclaration, :ptr IXMLDOMNode,:ptr ptr ISchemaItem
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMEntity, IXMLDOMNode, <2933BF8D-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_publicId, :ptr VARIANT
  COM_STD_METHOD  get_systemId, :ptr VARIANT
  COM_STD_METHOD  get_notationName, :ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IXTLRuntime, IXMLDOMNode, <3EFAA425-272F-11D2-836F-0000F87A7782>
  COM_STD_METHOD  uniqueID, :ptr IXMLDOMNode,:ptr SDWORD
  COM_STD_METHOD  depth, :ptr IXMLDOMNode,:ptr SDWORD
  COM_STD_METHOD  childNumber, :ptr IXMLDOMNode,:ptr SDWORD
  COM_STD_METHOD  ancestorChildNumber, :BSTR,:ptr IXMLDOMNode,:ptr SDWORD
  COM_STD_METHOD  absoluteChildNumber, :ptr IXMLDOMNode,:ptr SDWORD
  COM_STD_METHOD  formatIndex, :SDWORD,:BSTR,:ptr BSTR
  COM_STD_METHOD  formatNumber, :REAL8,:BSTR,:ptr BSTR
  COM_STD_METHOD  formatDate, :VARIANT,:BSTR,:VARIANT,:ptr BSTR
  COM_STD_METHOD  formatTime, :VARIANT,:BSTR,:VARIANT,:ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IXMLDOMDocument2, IXMLDOMDocument, <2933BF95-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  get_namespaces, :ptr ptr IXMLDOMSchemaCollection
  COM_STD_METHOD  get_schemas, :ptr VARIANT
  COM_STD_METHOD  putref_schemas, :VARIANT
  COM_STD_METHOD  validate, :ptr ptr IXMLDOMParseError
  COM_STD_METHOD  setProperty, :BSTR,:VARIANT
  COM_STD_METHOD  getProperty, :BSTR,:ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IServerXMLHTTPRequest, IXMLHTTPRequest, <2E9196BF-13BA-4DD4-91CA-6C571F281495>
  COM_STD_METHOD  setTimeouts, :SDWORD,:SDWORD,:SDWORD,:SDWORD
  COM_STD_METHOD  waitForResponse, :VARIANT,:ptr BOOL
  COM_STD_METHOD  getOption, :SERVERXMLHTTP_OPTION,:ptr VARIANT
  COM_STD_METHOD  setOption, :SERVERXMLHTTP_OPTION,:VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IXSLTemplate, IDispatch, <2933BF93-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  putref_stylesheet, :ptr IXMLDOMNode
  COM_STD_METHOD  get_stylesheet, :ptr ptr IXMLDOMNode
  COM_STD_METHOD  createProcessor, :ptr ptr IXSLProcessor
COM_INTERFACE_END

COM_INTERFACE_BEG IXSLProcessor, IDispatch, <2933BF92-7B36-11D2-B20E-00C04F983E60>
  COM_STD_METHOD  put_input, :VARIANT
  COM_STD_METHOD  get_input, :ptr VARIANT
  COM_STD_METHOD  get_ownerTemplate, :ptr ptr IXSLTemplate
  COM_STD_METHOD  setStartMode, :BSTR,:BSTR
  COM_STD_METHOD  get_startMode, :ptr BSTR
  COM_STD_METHOD  get_startModeURI, :ptr BSTR
  COM_STD_METHOD  put_output, :VARIANT
  COM_STD_METHOD  get_output, :ptr VARIANT
  COM_STD_METHOD  transform, :ptr BOOL
  COM_STD_METHOD  reset
  COM_STD_METHOD  get_readyState, :ptr SDWORD
  COM_STD_METHOD  addParameter, :BSTR,:VARIANT,:BSTR
  COM_STD_METHOD  addObject, :LPDISPATCH,:BSTR
  COM_STD_METHOD  get_stylesheet, :ptr ptr IXMLDOMNode
COM_INTERFACE_END

COM_INTERFACE_BEG IServerXMLHTTPRequest2, IServerXMLHTTPRequest, <2E01311B-C322-4B0A-BD77-B90CFDC8DCE7>
  COM_STD_METHOD  setProxy, :SXH_PROXY_SETTING,:VARIANT,:VARIANT
  COM_STD_METHOD  setProxyCredentials, :BSTR,:BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IMXNamespacePrefixes, IDispatch, <C90352F4-643C-4FBC-BB23-E996EB2D51FD>
  COM_STD_METHOD  get_item, :SDWORD,:ptr BSTR
  COM_STD_METHOD  get_length, :ptr SDWORD
  COM_STD_METHOD  get__newEnum, :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IVBMXNamespaceManager, IDispatch, <C90352F5-643C-4FBC-BB23-E996EB2D51FD>
  COM_STD_METHOD  put_allowOverride, :BOOL
  COM_STD_METHOD  get_allowOverride, :ptr BOOL
  COM_STD_METHOD  reset
  COM_STD_METHOD  _pushContext
  COM_STD_METHOD  pushNodeContext, :ptr IXMLDOMNode,:BOOL
  COM_STD_METHOD  _popContext
  COM_STD_METHOD  declarePrefix, :BSTR,:BSTR
  COM_STD_METHOD  getDeclaredPrefixes, :ptr ptr IMXNamespacePrefixes
  COM_STD_METHOD  getPrefixes, :BSTR,:ptr ptr IMXNamespacePrefixes
  COM_STD_METHOD  getURI, :BSTR,:ptr VARIANT
  COM_STD_METHOD  getURIFromNode, :BSTR,:ptr IXMLDOMNode,:ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IMXNamespaceManager, IUnknown, <C90352F6-643C-4FBC-BB23-E996EB2D51FD>
  COM_STD_METHOD  putAllowOverride, :BOOL
  COM_STD_METHOD  getAllowOverride, :ptr BOOL
  COM_STD_METHOD  reset
  COM_STD_METHOD  _pushContext
  COM_STD_METHOD  pushNodeContext, :ptr IXMLDOMNode,:BOOL
  COM_STD_METHOD  _popContext
  COM_STD_METHOD  declarePrefix, :ptr WORD,:ptr WORD
  COM_STD_METHOD  getDeclaredPrefix, :SDWORD,:ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getPrefix, :ptr WORD,:SDWORD,:ptr WORD,:ptr SDWORD
  COM_STD_METHOD  getURI, :ptr WORD,:ptr IXMLDOMNode,:ptr WORD,:ptr SDWORD
COM_INTERFACE_END

;--- dispinterface only
COM_INTERFACE_BEG XMLDOMDocumentEvents, IDispatch, <3EFAA427-272F-11D2-836F-0000F87A7782>
  COM_DISP_METHOD  ondataavailable, :ptr HRESULT
  COM_DISP_METHOD  onreadystatechange, :ptr HRESULT
COM_INTERFACE_END

DEFINE_COM_DISP_METHOD  XMLDOMDocumentEvents , ondataavailable, 0C6h, METHOD, 
DEFINE_COM_DISP_METHOD  XMLDOMDocumentEvents , onreadystatechange, 0FFFFFD9Fh, METHOD, 
