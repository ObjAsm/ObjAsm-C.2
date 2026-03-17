; ==================================================================================================
; Title:      RegEx.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of RegEx objects.
; Link:       http://www.pcre.org
;             https://www.pcre.org/original/doc/html/
;             https://learnxinyminutes.com/docs/pcre/
;             https://en.wikipedia.org/wiki/Regular_expression
; Notes:      Requires the following code in the main asm file:
;
;               % include &IncPath&Windows\PCRE844S.inc
;               % includelib &LibPath&Windows\PCRE844S.lib
;               % includelib &LibPath&Windows\MSVCRT.lib
;               % includelib &LibPath&Windows\UUID.lib
;
;               _chkstk proc c
;                   ret
;               _chkstk endp
;
;             This PCRE version (8.44) was compiled as a static library using VS 2019. It uses the
;             msvcrt provided memory management. The used calling convention is __stdcall.
;             In the "config.h" the followinf switches were set:
;                 HAVE_SYS_STAT_H, HAVE_SYS_TYPES_H, HAVE_WINDOWS_H, HAVE_STDINT_H, HAVE_INTTYPES_H,
;                 HAVE_STRERROR, HAVE_STRTOLL, HAVE__STRTOI64, SUPPORT_PCRE8, SUPPORT_PCRE16,
;                 SUPPORT_JIT, SUPPORT_UTF, SUPPORT_UCP, HAVE_LONG_LONG, HAVE_UNSIGNED_LONG_LONG
;
;             Version C.1.1, December 2020
;               - Updated to version 8.44
;             Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================
;
; Regular expression quick reference:
;
; Specific characters:
; \t    A tab character
; \n    A newline character (OS neutral)
; \r    A carriage return character
; \f    A form feed character
; \cX   Control character CTRL-X
; \NNN  Octal code for character NNN
;
; Metacharacters:
; The following 12 characters need to be escaped with a backslash - “\” - because by default,
; they mean something special.
;   \ | ( ) [ { ^ $ * + ? .
; .     Match any one character (except \n)
; |     Alternation
; ( )   Group and capture
; [ ]   Define character class
; \     Modify the meaning of the next char.
;
; Anchors:
; ^     Match at the beginning of a string (or line)
; $     Match at the end of a string (or line)
; \b    Match at a ‘word’ boundary
; \B    Match at not a ‘word’ boundary
; These are also known as zero width assertions.
;
; Quantifiers:
; These quantifiers apply to the preceding atom.
; *     Match 0 or more times
; +     Match 1 or more times
; ?     Match 0 or 1 times
; {N}   Match exactly N times
; {N,}  Match at least N times
; {N,M} Match at least N but not more than M times
; By default, quantifiers are “greedy”. They attempt to match as many characters as possible.
; In order to make them match as few characters as possible, follow them with a question mark “?”.
;
; Character class metacharacters:
; ^     If the first character of a class, negates that class
; -     Unless first or last character of a class, used for a range
;
; Character class shortcuts:
; \d    [0-9] A digit
; \D    [^0-9] A non-digit
; \h    any horizontal white space character.
; \H    any character that is not a horizontal white space character.
; \s    [ \t\n\r\f] A whitespace char.
; \S    [^ \t\n\r\f] A non-whitespace char.
; \v     any vertical white space character.
; \V     any character that is not a vertical white space character.
; \w    [a-zA-Z0-9_] A ‘word’ char.
; \W    [^a-zA-Z0-9_] A ‘non-word’ char.
; These shortcuts can be used either on their own, or within a character class.
;
; Metaquote & case translations:
; \Q    Quote (de-meta) characters until \E
; \U    Uppercase characters until \E
; \L    Lowercase characters until \E
;
; Special variables:
; $`    The characters to the left of the match
; $&    The characters that matched
; $’    The characters to the right of the match
; \N    The characters captured by the Nth set of parentheses (if on the match side)
; $N    The characters captured by the Nth set of parentheses (if not on the match side)



if TARGET_STR_TYPE eq STR_TYPE_ANSI
  RegEx textequ <RegExA>
  %include &ObjPath&RegExA.inc
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  RegEx textequ <RegExW>
  %include &ObjPath&RegExW.inc
else
  echo <Warning: incompatible TARGET_STR_TYPE>
endif
