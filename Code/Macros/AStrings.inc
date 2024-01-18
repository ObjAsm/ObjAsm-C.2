; ==================================================================================================
; Title:      AStrings.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of null-terminated ANSI string handling macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ==================================================================================================
; (($)X)Str:  Defines an ANSI string in (X = C) CONST, (X = T) SEG_TEXT, (X = D) _DATA or
;             (X = J) _TEXT segment returning a reference to it if the "$" prefix was used.
; $Ofs(X)Str: Same as ($C|$T|$D|$J)Str, but returns the string offset.
;
; Note:   ??StrSize = BYTE count including the ZTC
;         ??StrLength = Character count without the ZTC
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      StringA / ($)CStrA / ($)DStrA / ($)JStrA
; Purpose:    Place an ANSI string in the CONST, _DATA or _TEXT segment.
; Arguments:  Arg1: Reference name (optional).
;             Arg2: Quoted string text.
; Return:     Nothing / Reference to the string.

StringA macro StrName, QuotedText:vararg
  $$StrStart = $
  $$StrLabel textequ <StrName>
  for $$StrSubText:=<>, <QuotedText>
    $$StrLabel db $$StrSubText
    $$StrLabel textequ <>                               ;;Set to blank for the next loop
  endm
  CHRA 0                                                ;;Set ZTC
  ??StrSize = $ - $$StrStart                            ;;??StrSize includes the ZTC
  ??StrLength = ??StrSize - 1                           ;;??StrLength = character count without ZTC
endm

CStrA macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegConst
    align @WordSize
    StringA <TextReference>, <QuotedText>
  .SegRestore
endm

TStrA macro TextReference:req, QuotedText:vararg
  public TextReference
  SEG_TEXT segment
    align @WordSize
    StringA <TextReference>, <QuotedText>
  SEG_TEXT ends
endm

DStrA macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegData
    align @WordSize
    StringA <TextReference>, <QuotedText>
  .SegRestore
endm

JStrA macro TextReference:req, QuotedText:vararg
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  StringA <TextReference>, <QuotedText>
  Lbl:
endm

$CStrA macro QuotedText:vararg
  local ??StrLocation
  .SegConst
    align @WordSize
    ??StrLocation = $
    StringA <TextReference>, <QuotedText>
  .SegRestore
  exitm <??StrLocation>
endm

$TStrA macro QuotedText:vararg
  local ??StrLocation
  SEG_TEXT segment
    align @WordSize
    ??StrLocation = $
    StringA <TextReference>, <QuotedText>
  SEG_TEXT ends
  exitm <??StrLocation>
endm

$DStrA macro QuotedText:vararg
  local ??StrLocation
  .SegData
    align @WordSize
    ??StrLocation = $
    StringA <TextReference>, <QuotedText>
  .SegRestore
  exitm <??StrLocation>
endm

$JStrA macro QuotedText:vararg
  local ??StrLocation
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  ??StrLocation = $
  StringA <TextReference>, <QuotedText>
  Lbl:
  exitm <??StrLocation>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Ofs(C|T|D|J)StrA
; Purpose:    Place an ANSI string in the CONST, SEG_TEXT, _DATA or _TEXT segment
; Arguments:  Arg1: Quoted string text.
; Return:     String offset.

$OfsCStrA macro QuotedText:vararg
  local ??StrLocation
  .SegConst
    align @WordSize
    ??StrLocation = $
    StringA <>, <QuotedText>
  .SegRestore
  exitm <offset ??StrLocation>
endm

$OfsTStrA macro QuotedText:vararg
  local ??StrLocation
  SEG_TEXT segment
    align @WordSize
    ??StrLocation = $
    StringA <>, <QuotedText>
  SEG_TEXT ends
  exitm <offset ??StrLocation>
endm

$OfsDStrA macro QuotedText:vararg
  local ??StrLocation
  .SegData
    align @WordSize
    ??StrLocation = $
    StringA <>, <QuotedText>
  .SegRestore
  exitm <offset ??StrLocation>
endm

$OfsJStrA macro QuotedText:vararg
  local ??StrLocation
  local Lbl

  .code
  jmp Lbl
  align @WordSize
  ??StrLocation = $
  StringA <>, <QuotedText>
  Lbl:
  exitm <offset ??StrLocation>
endm
