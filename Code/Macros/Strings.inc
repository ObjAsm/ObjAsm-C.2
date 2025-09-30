; ==================================================================================================
; Title:      Strings.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of zero terminated string handling macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 August 2022
;               - $PCG_RndChr and $PCG_RndStr added.
; ==================================================================================================


;Generic character and string type definitions
CHRA      typedef     BYTE                              ;ANSI character type
CHRW      typedef     WORD                              ;Wide character type
CHRU      typedef     DWORD                             ;Unicode 32 bit character type
DCHRA     typedef     WORD                              ;ANSI double character type
DCHRW     typedef     DWORD                             ;Wide double character type
DCHRU     typedef     QWORD                             ;Unicode 32 bit double character type
QCHRA     typedef     DWORD                             ;ANSI quadruple character type
QCHRW     typedef     QWORD                             ;Wide quadruple character type
OCHRA     typedef     QWORD                             ;ANSI octuple character type
PCHRA     typedef ptr CHRA                              ;ANSI character pointer type
PCHRW     typedef ptr CHRW                              ;Wide character pointer type
PCHRU     typedef ptr CHRU                              ;Unicode 32 bit character pointer type
PDCHRA    typedef ptr DCHRA                             ;ANSI double character pointer type
PDCHRW    typedef ptr DCHRW                             ;Wide double character pointer type
PDCHRU    typedef ptr DCHRU                             ;Unicode 32 bit double character pointer type
PQCHRA    typedef ptr QCHRA                             ;ANSI quadruple pointer type
PQCHRW    typedef ptr QCHRA                             ;Wide quadruple pointer type
POCHRA    typedef ptr OCHRA                             ;ANSI octuple pointer type
PSTRINGA  typedef ptr CHRA                              ;ANSI string pointer type
PSTRINGW  typedef ptr CHRW                              ;Wide string pointer type
PSTRINGU  typedef ptr CHRU                              ;Unicode 32 bit string pointer type

;Type neutral definitions
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  CHR     typedef     CHRA                              ;Generic character type
  DCHR    typedef     DCHRA                             ;Generic double character type
  QCHR    typedef     QCHRA                             ;Generic quadruple character type
else
  CHR     typedef     CHRW                              ;Generic character type
  DCHR    typedef     DCHRW                             ;Generic double character type
  QCHR    typedef     QCHRW                             ;Generic quadruple character type
endif
PCHR      typedef ptr CHR                               ;Generic character POINTER type
PDCHR     typedef ptr DCHR                              ;Generic double character POINTER type
PQCHR     typedef ptr QCHR                              ;Generic quadruple character POINTER type
PSTRING   typedef ptr CHR                               ;Generic string POINTER type

TAB   equ 9
CR    equ 13
LF    equ 10
SPC   equ 32
CRLF  equ <13,10>

;Now include ANSI and WIDE string support

% include &MacPath&WStrings.inc
% include &MacPath&AStrings.inc

; --------------------------------------------------------------------------------------------------
; Macro:      $Esc
; Purpose:    Convert escape sequences to the corresponding character codes.
; Arguments:  Arg1: Text.
; Return:     Processed text.
; Notes:      esc. seq.      code           symbol
;             --------------------------------------------------
;                 \:         21h            '!'
;                 \{         28h            '('
;                 \}         29h            ')'
;                 \[         3Ch            '<'
;                 \]         3Eh            '>'
;                 \=         22h            '"'
;                 \,         3Bh            ';'
;                 \0          0             zero character
;                 \n         0Dh, 0Ah       new line
;                 \r         0Dh            carrige return
;                 \l         0Ah            line feed
;                 \t         09h            horizontal tabulation
;
; Other combinations of the "\" character are treated as literals.

$Esc macro Text:req
  $$CES_Text textequ <>
  $$CES_Backslash = 0                                   ;;Backslash reached
  $$CES_LeadingQM = 0                                   ;;Leading quotation mark ( "...... )
  $$CES_SepComma = 0                                    ;;Separating comma ( ...,... )
  $$CES_Count = 0

  forc $$CES_Character, <Text>
    $$CES_Count = $$CES_Count + 1
    if $$CES_Count eq 1                                 ;;Ignore first character = "
    elseif $$CES_Count eq @SizeStr(Text)                ;;Ignore $$CES_LastChar character = "
    else                                                ;;Note: this is to avoid the % operator!
      $$CES_LastChar Catstr <$$CES_Character>
      if $$CES_Backslash
        $$CES_Backslash = 0
        ifidn <&$$CES_Character>, <\>
          if $$CES_SepComma
            $$CES_Text CatStr $$CES_Text, <,>
            $$CES_SepComma = 0
          endif
          if $$CES_LeadingQM
            $$CES_Text CatStr $$CES_Text, <&$$CES_Character>
          else
            $$CES_Text CatStr $$CES_Text, <">, <&$$CES_Character>  ;;Add ( " )
            $$CES_LeadingQM = 1                         ;;Set flag
          endif
        else
          if $$CES_LeadingQM
            $$CES_Text CatStr $$CES_Text, <">           ;;"
            $$CES_LeadingQM = 0
            $$CES_SepComma = 1
          endif
          if $$CES_SepComma
            $$CES_Text CatStr $$CES_Text, <,>
          endif

          $$CES_SepComma = 1
          ifidn <&$$CES_Character>, <n>                 ;;  \n   = CR, LF
            $$CES_Text CatStr $$CES_Text, <0Dh,0Ah>
          elseifidn <&$$CES_Character>, <:>             ;;  \:   = !
            $$CES_Text CatStr $$CES_Text, <21h>
          elseifidn <&$$CES_Character>, <{>             ;;  \{   = (
            $$CES_Text CatStr $$CES_Text, <28h>
          elseifidn <&$$CES_Character>, <}>             ;;  \}   = )
            $$CES_Text CatStr $$CES_Text, <29h>
          elseifidn <&$$CES_Character>, <[>             ;;  \[   = <
            $$CES_Text CatStr $$CES_Text, <3Ch>
          elseifidn <&$$CES_Character>, <]>             ;;  \]   = >
            $$CES_Text CatStr $$CES_Text, <3Eh>
          elseifidn <&$$CES_Character>, <=>             ;;  \=   = "
            $$CES_Text CatStr $$CES_Text, <22h>
          elseifidn <&$$CES_Character>, <,>             ;;  \,   = ;
            $$CES_Text CatStr $$CES_Text, <3Bh>
          elseifidn <&$$CES_Character>, <0>             ;;  \0   = 0
            $$CES_Text CatStr $$CES_Text, <0h>
          elseifidn <&$$CES_Character>, <r>             ;;  \r   = CR
            $$CES_Text CatStr $$CES_Text, <0Dh>
          elseifidn <&$$CES_Character>, <l>             ;;  \l   = LF
            $$CES_Text CatStr $$CES_Text, <0Ah>
          elseifidn <&$$CES_Character>, <t>             ;;  \t   = TAB
            $$CES_Text CatStr $$CES_Text, <9h>
          elseifidn <&$$CES_Character>, <\>             ;;       = \
            $$CES_Text CatStr $$CES_Text, <\>
          else
            $$CES_Text CatStr $$CES_Text, <"\>, <&$$CES_Character>
            $$CES_LeadingQM = 1
            $$CES_SepComma = 0
          endif
        endif
      else
        ifidn <&$$CES_Character>, <\>
          $$CES_Backslash = 1
        else
          if $$CES_SepComma
            $$CES_Text CatStr $$CES_Text, <,>
            $$CES_SepComma = 0
          endif
          if $$CES_LeadingQM
            $$CES_Text CatStr $$CES_Text, <&$$CES_Character>
          else
            $$CES_Text CatStr $$CES_Text, <">, <&$$CES_Character>  ;;Add leading ( " )
            $$CES_LeadingQM = 1                         ;;Set flag
          endif
        endif
      endif
    endif
  endm

  if $$CES_LeadingQM
    $$CES_Text CatStr $$CES_Text, <">                   ;;"
  endif

  ifidni $$CES_LastChar, <\>                            ;;If $$CES_LastChar char == "\" then add it!
    $$CES_Text CatStr $$CES_Text, <,"\">
  endif

% exitm <$$CES_Text>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $QuotedText / $QuotedString
; Purpose:    Convert a sequence of quoted strings/numbers in a list of chars and numbers.
;             $QuotedString appends a zero to the end.
; Arguments:  Arg1: Quoted text or numbers.
; Return:     Processed text.
;             ??CharCount = number of chars in the list.
; Example:    $QuotedString("example", 10, 13) returns "e","x","a","m","p","l","e",10,13,0

$QuotedText macro Text:vararg
  $$Sentence textequ <>
  $$TextLine textequ <>
  ??CharCount = 0

  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    $$Max = 0FFh          ;;Maximum 1 byte
  else
    $$Max = 0FFFFh        ;;Maximum 2 bytes
  endif

  ;;Continue regular processing
% for $$SubText, <Text>
    $$NumFlag textequ <0>
    $$QuotationMark SubStr <$$SubText>, 1, 1
%   ifdif <$$QuotationMark>, <">
%     ifdif <$$QuotationMark>, <'>
        $$NumFlag textequ <1>
        if $$SubText gt $$Max
          .err <$QuotedText: Numeric input out of range>
        endif
        $$Sentence textequ @CatStr(%$$TextLine, <$$SubText>, <,>)
        $$TextLine textequ $$Sentence
        ??CharCount = ??CharCount + 1
      endif
    endif

%   ifidn <$$NumFlag>, <0>
      if @SizeStr(<$$SubText>) ne 2
        $$Count = 0
%       forc $$Char, <$$SubText>
          ;;Strip quotation marks
%         if ($$Count ne 0) and ($$Count ne (@SizeStr(<$$SubText>) - 1))
            $$QChar CatStr $$QuotationMark, <$$Char>, $$QuotationMark
            $$Sentence textequ @CatStr(%$$TextLine, <$$QChar>, <,>)
            $$TextLine textequ $$Sentence
            ??CharCount = ??CharCount + 1
          endif
          $$Count = $$Count + 1
        endm
      else
        .err <$QuotedText: Wrong string definition>
      endif
    endif

  endm
  exitm <@SubStr(%$$Sentence, 1, @SizeStr(%$$Sentence) - 1)>
endm

$QuotedString macro Text:vararg
% exitm <$QuotedText(Text, 0)>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $RepChr
; Purpose:    Repeat a character N times.
; Arguments:  Arg1: Character to repeat
;             Arg2: Character count.
; Return:     Quoted text.
; Example:    CStrW wBlanks, $RepChr(< >, 15)

$RepChr macro Char:req, Count:req
  $$Text textequ <>
  repeat Count
    $$Text CatStr $$Text, <Char>
  endm
  exitm @CatStr(<">, %$$Text, <">)
endm

; --------------------------------------------------------------------------------------------------

String macro StrName, QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    StringW <StrName>, <QuotedText>
  else
    StringA <StrName>, <QuotedText>
  endif
endm

ExtendString macro QuotedText:vararg          ;;Extends a Str definition overcomming the line length limit
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    ExtendStringW <QuotedText>
  else
    ExtendStringA <QuotedText>
  endif
endm

CStr macro TextReference:req, QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    CStrW <TextReference>, <QuotedText>
  else
    CStrA <TextReference>, <QuotedText>
  endif
endm

TStr macro TextReference:req, QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    TStrW <TextReference>, <QuotedText>
  else
    TStrA <TextReference>, <QuotedText>
  endif
endm

DStr macro TextReference:req, QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    DStrW <TextReference>, <QuotedText>
  else
    DStrA <TextReference>, <QuotedText>
  endif
endm

JStr macro TextReference:req, QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    JStrW <TextReference>, <QuotedText>
  else
    JStrA <TextReference>, <QuotedText>
  endif
endm

$CStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $CStrW(<QuotedText>)
  else
    exitm $CStrA(<QuotedText>)
  endif
endm

$TStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $TStrW(<QuotedText>)
  else
    exitm $TStrA(<QuotedText>)
  endif
endm

$DStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $DStrW(<QuotedText>)
  else
    exitm $DStrA(<QuotedText>)
  endif
endm

$JStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $JStrW(<QuotedText>)
  else
    exitm $JStrA(<QuotedText>)
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $Ofs(C/T/D/J)Str
; Purpose:    Place an ANSI or UNICODE string in the CONST, SEG_TEXT, _DATA or _TEXT Segment.
; Arguments:  Arg1: Quoted string text.
; Return:     String offset.

$OfsCStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $OfsCStrW(<QuotedText>)
  else
    exitm $OfsCStrA(<QuotedText>)
  endif
endm

$OfsTStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $OfsTStrW(<QuotedText>)
  else
    exitm $OfsTStrA(<QuotedText>)
  endif
endm

$OfsDStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $OfsDStrW(<QuotedText>)
  else
    exitm $OfsDStrA(<QuotedText>)
  endif
endm

$OfsJStr macro QuotedText:vararg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    exitm $OfsJStrW(<QuotedText>)
  else
    exitm $OfsJStrA(<QuotedText>)
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $PCG_RndChr
; Purpose:    Return at assembly-time a randomly generated (PCG) character value.
; Arguments:  None.
; Return:     Character value.

;Initial state
PCG32_STATE = @CatStr(@SubStr(%@Time, 1, 2), @SubStr(%@Time, 4, 2), @SubStr(%@Time, 7, 2), @SubStr(%@Date, 1, 2), @SubStr(%@Date, 4, 2))

$PCG_RndChr macro
  local r, t, x, a

  a = 0
  while a gt 'z' or a lt '0' or a ge ':' and a le '>' or \
        a ge '[' and a le '`' and a ne '_'
    PCG32_STATE = PCG32_STATE * 6364136223846793005 + 0xda3e39cb94b95bdb

    t = PCG32_STATE
    r = (((t shr 18) xor t) shr 27)
    ;r = (((t sar 18) xor t) sar 27)
    x = t shr 59
    t = r shr x
    r = r shl (-x and 31)
    r = r or t
    a = r and 0x7F
  endm

  exitm <a>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $PCG_RndStr
; Purpose:    Return at assembly-time a randomly generated (PCG) string in const segment.
;             On each run of the macro, a new string is generated
; Arguments:  Arg1: String length in chars.
; Return:     String location.
; Example:    DbgWriteF ,, "¦ST", offset $PCG_RndStr(64)

$PCG_RndStr macro n
  local ??StrLocation

  .SegConst
    align @WordSize
    ??StrLocation = $
    repeat n
      CHR $PCG_RndChr()
    endm
    CHR 0
  .SegRestore
  exitm <??StrLocation>
endm
