; ==================================================================================================
; Title:      BStrings.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of BSTR string handling macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; BSTR format as defined in the OLE 2.0 specification (MS ActiveX).
;
;          4 bytes      2 bytes per character             2 bytes
;       ————————————————————————————————————————————————————————————————————
;  ... | Byte Lenght | UNICODE character array | Zero Termination Character | ...
;       ————————————————————————————————————————————————————————————————————
;                    ^
;                    BSTR points here!



; ==================================================================================================
; (($)C/($)T/($)D/($)J)BStr: Defines an BSTR string in (C) S_CONST, (T) S_TEXT,  (D) S_DATA or
;                            (J) code segment, returning a reference to it,
;                            if the "$" prefix was used.
; $Ofs(C/T/D/J)BStr:         Same as ($C/$T/$D/$J)BStr, but returns the symbolic string offset.
;
; Note: - Use ??StrSize (byte count including the ZTC) or  
;         ??StrLength (character count without the ZTC).
;         Both values do not include the byte length header (DWORD).
;       - The "Byte Lenght" prefix includes the ZTC.
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      BString / ($)CBStr / ($)TBStr / ($)DBStr / ($)JBStr
; Purpose:    Place an BSTR string in the S_CONST, S_DATA or S_TEXT segment.
; Arguments:  Arg1: Reference name (optional).
;             Arg2: Quoted string text.
; Return:     Nothing / Reference to the string.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
; Example:    CBStr MyBStr, 'Note: "', "Director's cut", '"', 13, 10
;             Resulting BStr:   Note: "Director's cut" + CRLF

BString macro StrName, QuotedText:vararg
  $$Count = 0
  for $$SubText, <QuotedText>
    $$NumFlag textequ <0>
    $$QuotationMark SubStr <$$SubText>, 1, 1
%   ifdif <$$QuotationMark>, <">
%     ifdif <$$QuotationMark>, <'>
        $$NumFlag textequ <1>
        if $$SubText le 0FFFFh        ;;Maximum 2 bytes
          $$Count = $$Count + 2
        else
          .err <BSTR numeric input out of range>
        endif
      endif
    endif

%   ifidn <$$NumFlag>, <0>
%     ifdif <@SizeStr(<$$SubText>)>, <02>
        ;;Strip quotation marks and loop
%       forc $$Char, <@SubStr(<$$SubText>, 2, @SizeStr(<$$SubText>) - 2)>
          $$Count = $$Count + 2
        endm
      else
        .err <Wrong BSTR definition>
      endif
    endif
  endm

% dd $$Count        ;;Set byte Count before the UNICODE string is placed

  $$StrStart = $
  $$SrcLine textequ @CatStr(StrName, < dw >)
  for $$SubText, <QuotedText>
    $$NumFlag textequ <0>
    $$QuotationMark SubStr <$$SubText>, 1, 1
%   ifdif <$$QuotationMark>, <">
%     ifdif <$$QuotationMark>, <'>
        $$NumFlag textequ <1>
        $$Sentence textequ @CatStr(%$$SrcLine, <$$SubText>, <,>)
        $$SrcLine textequ $$Sentence
      endif
    endif

%   ifidn <$$NumFlag>, <0>
%     ifdif <@SizeStr(<$$SubText>)>, <02>
        ;;Strip quotation marks and loop
%       forc $$Char, <@SubStr(<$$SubText>, 2, @SizeStr(<$$SubText>) - 2)>
          if @SizeStr(%$$SrcLine) gt 95
            ;;Output $$Sentence
%           $$Sentence
            ;;Initiate new $$SubText
            $$SrcLine textequ <dw >
            $$Sentence textequ <>
          endif
          $$QChar CatStr $$QuotationMark, <$$Char>, $$QuotationMark
          $$Sentence textequ @CatStr(%$$SrcLine, <$$QChar>, <,>)
          $$SrcLine textequ $$Sentence
        endm
      endif
    endif

    ;;Output $$Sentence
%   $$Sentence
    ;;Initiate new $$SubText
    $$SrcLine textequ <dw >
  endm
  ;;Set zero termination mark
  dw 0
  ??StrSize = $ - $$StrStart                            ;;??StrSize includes the ZTC 
  ??StrLength = ??StrSize/2 - 1                         ;;??StrLength = character count without ZTC
endm

CBStr macro TextReference:req, QuotedText:vararg
  externdef TextReference:WORD
  S_CONST Segment
    align @WordSize
    BString <TextReference>, <QuotedText>
  S_CONST ends
endm

TBStr macro TextReference:req, QuotedText:vararg
  externdef TextReference:WORD
  S_TEXT Segment
    align @WordSize
    BString <TextReference>, <QuotedText>
  S_TEXT ends
endm

DBStr macro TextReference:req, QuotedText:vararg
  externdef TextReference:WORD
  S_DATA Segment
    align @WordSize
    BString <TextReference>, <QuotedText>
  S_DATA ends
endm

JBStr macro TextReference, QuotedText:vararg
  local Lbl

  jmp Lbl
  align @WordSize
  BString <TextReference>, <QuotedText>
  Lbl:
endm

$CBStr macro QuotedText:vararg
  local ??StrLocation
  S_CONST Segment
    align @WordSize
    ??StrLocation = $
    BString <>, <QuotedText>
  S_CONST ends
  exitm <??StrLocation + 4>
endm

$TBStr macro QuotedText:vararg
  local ??StrLocation
  S_TEXT Segment
    align @WordSize
    ??StrLocation = $
    BString <>, <QuotedText>
  S_TEXT ends
  exitm <??StrLocation + 4>
endm

$DBStr macro QuotedText:vararg
  local ??StrLocation
  S_DATA Segment
    align @WordSize
    ??StrLocation = $
    BString <>, <QuotedText>
  S_DATA ends
  exitm <??StrLocation + 4>
endm

$JBStr macro QuotedText:vararg
  local ??StrLocation
  local Lbl

  jmp Lbl
  align @WordSize
  ??StrLocation = $
  BString <>, <QuotedText>
  Lbl:
  exitm <??StrLocation + 4>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Ofs(C/T/D/J)BStr
; Purpose:    Place an BSTR string in the S_CONST, S_TEXT, S_DATA segment.
; Arguments:  Arg1: Quoted string text.
; Return:     String offset.

$OfsCBStr macro QuotedText:vararg
  local ??StrLocation
  S_CONST Segment
    align @WordSize
    ??StrLocation = $
    BString <>, <QuotedText>
  S_CONST ends
  exitm <offset ??StrLocation + 4>
endm

$OfsTBStr macro QuotedText:vararg
  local ??StrLocation
  S_TEXT Segment
    align @WordSize
    ??StrLocation = $
    BString <>, <QuotedText>
  S_TEXT ends
  exitm <offset ??StrLocation + 4>
endm

$OfsDBStr macro QuotedText:vararg
  local ??StrLocation
  S_DATA Segment
    align @WordSize
    ??StrLocation = $
    BString <>, <QuotedText>
  S_DATA ends
  exitm <offset ??StrLocation + 4>
endm

$OfsJBStr macro QuotedText:vararg
  local ??StrLocation
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  ??StrLocation = $
  BString <>, <QuotedText>
  Lbl:
  exitm <offset ??StrLocation + 4>
endm
