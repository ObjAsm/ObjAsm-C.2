; ==================================================================================================
; Title:      h2inc+_BStrA.inc
; Authors:    G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm support of BStrA string handling macros.
; ==================================================================================================


;
;          4 bytes     1 byte per character        1 byte
;      ————————————————————————————————————————————————————————————————
;  ... | Byte Lenght | ANSI character array | Zero termination marker | ...
;      ————————————————————————————————————————————————————————————————
;                    ^
;                    BStrA points here!



; ==================================================================================================
; (($)C/($)T/($)D/($)J)BStrA: Defines an BSTR string in (C) SEG_CONST, (T) SEG_TEXT,  (D) SEG_DATA or
;                             (J) code segment, returning a reference to it,
;                             if the "$" prefix was used.
; $Ofs(C/T/D/J)BStrA:         Same as ($C/$T/$D/$J)BStr, but returns the symbolic string offset.
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      BStrA / ($)CBStrA / ($)TBStrA / ($)DBStrA / ($)JBStrA
; Purpose:    Place an BSTR string in the SEG_CONST, SEG_DATA or SEG_TEXT segment.
; Arguments:  Arg1: Reference name (optional).
;             Arg2: Quoted string text.
; Returns:    Nothing / Reference to the string.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
; Example:    CBStr MyBStr, 'Note: "', "Director's cut", '"', 13, 10
;             Resulting BStr:   Note: "Director's cut" + CRLF

BStrA macro StrName, QuotedText:vararg
    ??Count = 0
    for ??SubText, <QuotedText>
      ??NumFlag textequ <0>
      ??QuotationMark SubStr <??SubText>, 1, 1
%     ifdif <??QuotationMark>, <">
%       ifdif <??QuotationMark>, <'>
          ??NumFlag textequ <1>
          if ??SubText le 0FFh            ;;Maximum 1 byte
            ??Count = ??Count + 1
          else
            .err <BStrA numeric input out of range>
          endif
        endif
      endif

%     ifidn <??NumFlag>, <0>
%       ifdif <@SizeStr(<??SubText>)>, <02>
          ;;Strip quotation marks and loop
%         forc ??Char, <@SubStr(<??SubText>, 2, @SizeStr(<??SubText>) - 2)>
            ??Count = ??Count + 1
          endm
        else
          .err <Wrong BStr definition>
        endif
      endif
    endm

%   dd ??Count + 1       ;;Set byte count incl. ZTC before the ANSI string is placed

    if ??Count eq 0
      StrName db 0
    else
      ??SrcLine textequ @CatStr(StrName, < db >)
      for ??SubText, <QuotedText>
        ??NumFlag textequ <0>
        ??QuotationMark SubStr <??SubText>, 1, 1
%       ifdif <??QuotationMark>, <">
%         ifdif <??QuotationMark>, <'>
            ??NumFlag textequ <1>
            ??Sentence textequ @CatStr(%??SrcLine, <??SubText>, <,>)
            ??SrcLine textequ ??Sentence
          endif
        endif

%       ifidn <??NumFlag>, <0>
%         ifdif <@SizeStr(<??SubText>)>, <02>
            ;;Strip quotation marks and loop
%           forc ??Char, <@SubStr(<??SubText>, 2, @SizeStr(<??SubText>) - 2)>
              if @SizeStr(%??SrcLine) gt 95
                ;;Output ??Sentence
%               ??Sentence
                ;;Initiate new ??SubText
                ??SrcLine textequ <db >
                ??Sentence textequ <>
              endif
              ??QChar CatStr ??QuotationMark, <??Char>, ??QuotationMark
              ??Sentence textequ @CatStr(%??SrcLine, <??QChar>, <,>)
              ??SrcLine textequ ??Sentence
            endm
          endif
        endif

        ;;Output ??Sentence
%       ??Sentence
        ;;Initiate new ??SubText
        ??SrcLine textequ <db >
      endm
      ;;Set zero termination mark
      db 0
    endif
endm

CBStrA macro TextReference:req, QuotedText:vararg
    externdef TextReference:BYTE
    SEG_CONST Segment
      align 4
      BStrA <TextReference>, <QuotedText>
    SEG_CONST ends
endm

TBStrA macro TextReference:req, QuotedText:vararg
    externdef TextReference:BYTE
    SEG_TEXT Segment
      align 4
      BStrA <TextReference>, <QuotedText>
    SEG_TEXT ends
endm

DBStrA macro TextReference:req, QuotedText:vararg
    externdef TextReference:BYTE
    SEG_DATA Segment
      align 4
      BStrA <TextReference>, <QuotedText>
    SEG_DATA ends
endm

JBStrA macro TextReference, QuotedText:vararg
    local Lbl

    jmp Lbl
    align 4
    BStrA <TextReference>, <QuotedText>
    Lbl:
endm

$CBStrA macro QuotedText:vararg
    local ??StrLocation
    SEG_CONST Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    SEG_CONST ends
    exitm <??StrLocation + 4>
endm

$TBStrA macro QuotedText:vararg
    local ??StrLocation
    SEG_TEXT Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    SEG_TEXT ends
    exitm <??StrLocation + 4>
endm

$DBStrA macro QuotedText:vararg
    local ??StrLocation
    SEG_DATA Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    SEG_DATA ends
    exitm <??StrLocation + 4>
endm

$JBStr macro QuotedText:vararg
    local ??StrLocation
    local Lbl

    jmp Lbl
    align 4
    ??StrLocation = $
    BStrA <>, <QuotedText>
    Lbl:
    exitm <??StrLocation + 4>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Ofs(C/T/D/J)BStrA
; Purpose:    Place an BSTR string in the SEG_CONST, SEG_TEXT, SEG_DATA segment.
; Arguments:  Arg1: Quoted string text.
; Returns:    String offset.

$OfsCBStrA macro QuotedText:vararg
    local ??StrLocation
    SEG_CONST Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    SEG_CONST ends
    exitm <offset ??StrLocation + 4>
endm

$OfsTBStrA macro QuotedText:vararg
    local ??StrLocation
    SEG_TEXT Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    SEG_TEXT ends
    exitm <offset ??StrLocation + 4>
endm

$OfsDBStrA macro QuotedText:vararg
    local ??StrLocation
    SEG_DATA Segment
      align 4
      ??StrLocation = $
      BStrA <>, <QuotedText>
    SEG_DATA ends
    exitm <offset ??StrLocation + 4>
endm

$OfsJBStrA macro QuotedText:vararg
    local ??StrLocation
    local Lbl

    .code
    jmp Lbl
    align 4
    ??StrLocation = $
    BStrA <>, <QuotedText>
    Lbl:
    exitm <offset ??StrLocation + 4>
endm
