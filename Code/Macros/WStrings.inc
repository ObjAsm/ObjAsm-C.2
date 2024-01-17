; ==================================================================================================
; Title:      WStrings.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of UNICODE (UTF-16 - Windows WIDE strings) string handling macros.
; Notes:      - The International Organization for Standardization (ISO) and International
;               Electrotechnical Commission (IEC) 10646 standard (ISO/IEC 10646) specifies the
;               Universal Multiple-Octet Coded Character Set (UCS) that has a 2-byte version
;               (UCS-2) and a 4-byte version (UCS-4). The 2-byte version of this ISO standard
;               UCS-2 is identical to Unicode without surrogates. ISO 10646 also defines an
;               extension technique, for encoding some UCS-4 codes in a UCS-2 encoded string.
;               This extension called UTF-16, is identical to Unicode with surrogates.
;             - For some APIs, the beginning of the WIDE string must be aligned to a word boundary!
;
; Link:       http://en.wikipedia.org/wiki/UCS-2
;             http://www.unicode.org/standard/standard.html
;             http://msdn.microsoft.com/en-us/library/dd374081(VS.85).aspx
;             https://docs.microsoft.com/en-us/windows/win32/intl/surrogates-and-supplementary-characters
;
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



; ==================================================================================================
; (($)C|($)D|($)J)WStr: Defines an WIDE string in (C) const, (D) data or (J) code
;                  segment returning a reference to it if the "$" prefix was used.
; $Ofs(C|D|J)WStr: Same as ($C|$D|$J)WStr, but returns the string offset.

; Note: Use ??StrSize (byte count including the ZTC) or  
;           ??StrLength (character count without the ZTC).
; ==================================================================================================



; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      StringW / ($)CStrW / ($)TStrW / ($)DStrW / ($)JStrW
; Purpose:    Place an WIDE string in the .const, .text, .data or .code segment.
; Arguments:  Arg1: Reference name (optional).
;             Arg2: Quoted string text.
; Return:     Nothing / Reference to the string.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
;             - sizeof and length of directives work with this macro.
; Example:    CStrW MyStrW, 'Note: "', "Director's cut", '"', 13, 10
;             Resulting WIDE string:  Note: "Director's cut" + CRLF

StringW macro StrName, QuotedText:vararg
  ;;Because the forc handles the backslash as an escape character, we add an
  ;;backslash charater to mimic the behaviour of the StringA macro.
  ;;JWASM 2.07B don't need this workaround.
  ifdef __JWASM__
    $$Text textequ <QuotedText>
    goto Continue
  elseifdef __UASM__
    $$Text textequ <QuotedText>
    goto Continue
  endif

  ;ML specific code
  $$Text textequ <>
  $$TextSize SizeStr <QuotedText>
  $$StartPos = 1
:SearchBackslasch
  $$FindPos InStr $$StartPos, <QuotedText>, <\>
  if $$FindPos ne 0
    $$AddText SubStr <QuotedText>, $$StartPos, $$FindPos - $$StartPos + 1
    $$Text CatStr $$Text, $$AddText, <\>
    if $$FindPos lt $$TextSize
      $$StartPos = $$FindPos + 1
      goto SearchBackslasch
    endif
  else
    if $$StartPos le $$TextSize
      $$AddText SubStr <QuotedText>, $$StartPos, $$TextSize - $$StartPos + 1
      $$Text CatStr $$Text, $$AddText
    endif
  endif

:Continue
  ;;Continue regular processing
  $$StrStart = $

  $$CharCount = 0
% for $$SubText, <$$Text>
    $$NumFlag textequ <0>
    $$QuotationMark SubStr <$$SubText>, 1, 1
%   ifdif <$$QuotationMark>, <">
%     ifdif <$$QuotationMark>, <'>
        $$NumFlag textequ <1>
      endif
    endif

%   ifidn <$$NumFlag>, <0>
      $$SubTextSize = @SizeStr(<$$SubText>)
      if $$SubTextSize ne 2
        $$CharCount = $$CharCount + $$SubTextSize - 2
      endif
    else
      $$CharCount = $$CharCount + 1
    endif
  endm

  StrName WORD $$CharCount dup(?)
  org $ - $$CharCount*2

  ;;Continue regular processing
  $$SrcLine textequ < dw >
% for $$SubText, <$$Text>
    $$NumFlag textequ <0>
    $$QuotationMark SubStr <$$SubText>, 1, 1
%   ifdif <$$QuotationMark>, <">
%     ifdif <$$QuotationMark>, <'>
        $$NumFlag textequ <1>
        if $$SubText gt 0FFFFh        ;;Maximum 2 bytes
          .err <WIDE string numeric input out of range>
        endif
        $$Sentence textequ @CatStr(%$$SrcLine, <$$SubText>, <,>)
        $$SrcLine textequ $$Sentence
      endif
    endif

%   ifidn <$$NumFlag>, <0>
      if @SizeStr(<$$SubText>) ne 2
        $$Count = 0
%       forc $$Char, <$$SubText>
          ;;Strip quotation marks
%         if ($$Count ne 0) and ($$Count ne (@SizeStr(<$$SubText>) - 1))
            if @SizeStr(%$$SrcLine) gt 95
              ;;Output $$Sentence
%             $$Sentence
              ;;Initiate new $$SubText
              $$SrcLine textequ <dw >
              $$Sentence textequ <>
            endif
            $$QChar CatStr $$QuotationMark, <$$Char>, $$QuotationMark
            $$Sentence textequ @CatStr(%$$SrcLine, <$$QChar>, <,>)
            $$SrcLine textequ $$Sentence
          endif
          $$Count = $$Count + 1
        endm
      else
        .err <Wrong WIDE string definition>
      endif
    endif

    ;;Output $$Sentence
%   $$Sentence
    ;;Initiate new $$SubText
    $$SrcLine textequ <dw >
  endm
  ;;Set ZTC
  CHRW 0
  ??StrSize = $ - $$StrStart                            ;;??StrSize includes the ZTC 
  ??StrLength = ??StrSize/2 - 1                         ;;??StrLength = character count without ZTC
endm

CStrW macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegConst
    align @WordSize
    StringW <TextReference>, <QuotedText>
  .SegRestore
endm

TStrW macro TextReference:req, QuotedText:vararg
  public TextReference
  SEG_TEXT segment
    align @WordSize
    StringW <TextReference>, <QuotedText>
  SEG_TEXT ends
endm

DStrW macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegData
    align @WordSize
    StringW <TextReference>, <QuotedText>
  .SegRestore
endm

JStrW macro TextReference, QuotedText:vararg
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  StringW <TextReference>, <QuotedText>
  Lbl:
endm

$CStrW macro QuotedText:vararg
  local ??StrLocation
  .SegConst
    align @WordSize
    ??StrLocation = $
    StringW <>, <QuotedText>
  .SegRestore
  exitm <??StrLocation>
endm

$TStrW macro QuotedText:vararg
  local ??StrLocation
  SEG_TEXT segment
    align @WordSize
    ??StrLocation = $
    StringW <>, <QuotedText>
  SEG_TEXT ends
  exitm <??StrLocation>
endm

$DStrW macro QuotedText:vararg
  local ??StrLocation
  .SegData
    align @WordSize
    ??StrLocation = $
    StringW <>, <QuotedText>
  .SegRestore
  exitm <??StrLocation>
endm

$JStrW macro QuotedText:vararg
  local ??StrLocation
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  ??StrLocation = $
  StringW <>, <QuotedText>
  Lbl:
  exitm <??StrLocation>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Ofs(C|T|D|J)WStr
; Purpose:    Place an WIDE string in the CONST, CTEXT, _DATA or _TEXT segment.
; Arguments:  Arg1: Quoted string text.
; Return:     String offset.

$OfsCStrW macro QuotedText:vararg
  local ??StrLocation
  .SegConst
    align @WordSize
    ??StrLocation = $
    StringW <>, <QuotedText>
  .SegRestore
  exitm <offset(??StrLocation)>
endm

$OfsTStrW macro QuotedText:vararg
  local ??StrLocation
  SEG_TEXT segment
    align @WordSize
    ??StrLocation = $
    StringW <>, <QuotedText>
  SEG_TEXT ends
  exitm <offset(??StrLocation)>
endm

$OfsDStrW macro QuotedText:vararg
  local ??StrLocation
  .SegData
    align @WordSize
    ??StrLocation = $
    StringW <>, <QuotedText>
  .SegRestore
  exitm <offset(??StrLocation)>
endm

$OfsJStrW macro QuotedText:vararg
  local ??StrLocation
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  ??StrLocation = $
  StringW <>, <QuotedText>
  Lbl:
  exitm <offset(??StrLocation)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

SURROGATE_MASK  equ     1111110000000000y               ;0FC00h
SURROGATE_HIGH  equ     1101100000000000y               ;0D800h
SURROGATE_LOW   equ     1101110000000000y               ;0DC00h
UTF8_BOM        textequ <0EFh,0BBh,0BFh>
UTF16BE_BOM     textequ <0FEh,0FFh>                     ;Big Endian
UTF16LE_BOM     textequ <0FFh,0FEh>                     ;Little Endian  (used by Windows in memory)

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsSurrogateHigh
; Purpose:    Check if the WIDE char is a high surrogate.
; Arguments:  Arg1: Wide character.
; Return:     ZERO? if character is a high surrogate.

IsSurrogateHigh macro CharReg:req
  and CharReg, SURROGATE_MASK
  cmp CharReg, SURROGATE_HIGH 
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsSurrogateLow
; Purpose:    Check if the WIDE char is a low surrogate.
; Arguments:  Arg1: Wide character.
; Return:     ZERO? if character is a low surrogate.

IsSurrogateLow macro CharReg:req
  and CharReg, SURROGATE_MASK
  cmp CharReg, SURROGATE_LOW 
endm
