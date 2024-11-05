; ==================================================================================================
; Title:      XML_Helper.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Some helper procs and definitions.
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

.code

StrA2NewStrW proc pStringA:PSTRINGA
	local pStringW:PSTRINGW, dCharCount:DWORD

	invoke StrLengthA, pStringA
	mov dCharCount, eax
	invoke StrAllocW, eax
	.if xax != NULL
	  mov pStringW, xax
	  inc dCharCount
  	invoke MultiByteToWideChar, CP_ACP, 0, pStringA, dCharCount, xax, dCharCount
  	mov xax, pStringW
  .endif
	ret
StrA2NewStrW endp

StrW2NewStrA proc pStringW:PSTRINGW
	local pStringA:PSTRINGA, dCharCount:DWORD

	invoke StrLengthW, pStringW
	mov dCharCount, eax
	invoke StrAllocA, eax
	.if xax != NULL
	  mov pStringA, xax
	  inc dCharCount
  	invoke WideCharToMultiByte, CP_ACP, 0, pStringW, dCharCount, xax, dCharCount, NULL, NULL
  	mov xax, pStringA
  .endif
	ret
StrW2NewStrA endp

StrA2NewBSTR proc pStringA:PSTRINGA
	local bstr:BSTR, dBufferCharCapacity:DWORD

	invoke StrSizeA, pStringA
  .if eax != 0
  	mov dBufferCharCapacity, eax
  	lea edx, [sizeof(CHRW)*eax]
  	mov bstr, $invoke(SysAllocStringByteLen, NULL, edx)
  	invoke MultiByteToWideChar, CP_ACP, 0, pStringA, -1, xax, dBufferCharCapacity
  	mov ecx, dBufferCharCapacity
  	dec ecx                                              ;This value does not include the ZTC 
  	mov xax, bstr
  	add ecx, ecx
  	mov [xax - sizeof DWORD], ecx
  .endif
	ret
StrA2NewBSTR endp

StrW2NewBSTR proc pStringW:PSTRINGW
	local bstr:BSTR, dBufferSize:DWORD

	invoke StrSizeW, pStringW
  .if eax != 0
  	mov dBufferSize, eax
  	mov bstr, $invoke(SysAllocStringByteLen, NULL, eax)
  	mov ecx, dBufferSize
  	sub ecx, sizeof(CHRW)                                ;This value does not include the ZTC
  	mov [xax - sizeof DWORD], ecx
  	invoke MemClone, xax, pStringW, dBufferSize
  	mov xax, bstr
  .endif
	ret
StrW2NewBSTR endp

BSTR2NewStrA proc bstr:BSTR
	local pBuffer:PSTRING, dBufferLen:DWORD

	invoke WideCharToMultiByte, CP_ACP, 0, bstr, -1, pBuffer, 0, NULL, NULL
  .if eax != 0
  	mov dBufferLen, eax
  	invoke GlobalAlloc, GPTR, eax
  	mov pBuffer, xax
  	invoke WideCharToMultiByte, CP_ACP, 0, bstr, -1, pBuffer, dBufferLen, NULL, NULL
  	mov xax, pBuffer
  .endif
	ret
BSTR2NewStrA endp

BSTR2NewStrW proc bstr:BSTR
	local pBuffer:PSTRING, dBufferSize:DWORD

	invoke StrSizeW, bstr
  .if eax != 0
  	mov dBufferSize, eax
  	invoke GlobalAlloc, GPTR, eax
  	mov pBuffer, xax
  	invoke MemClone, xax, bstr, dBufferSize
  	mov xax, pBuffer
  .endif
	ret
BSTR2NewStrW endp

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  Str2NewBSTR textequ <StrA2NewBSTR>
  BSTR2NewStr textequ <BSTR2NewStrA>
else
  Str2NewBSTR textequ <StrW2NewBSTR>
  BSTR2NewStr textequ <BSTR2NewStrW>
endif


DisposeBSTR proc bstr:BSTR
	?mov ecx, bstr
	invoke SysFreeString, xcx
	ret
DisposeBSTR endp

CompBSTRs proc bstr1:BSTR, bstr2:BSTR
  ?mov xcx, bstr1
  ?mov xdx, bstr2
  mov eax, DWORD ptr [xcx - sizeof DWORD]
  sub eax, DWORD ptr [xdx - sizeof DWORD]
  .if ZERO?
    invoke StrCompW, xcx, xdx
  .endif
	ret
CompBSTRs endp
