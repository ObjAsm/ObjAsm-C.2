;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winnls.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:13:44

;--*
ifndef _WINNLS_
  _WINNLS_ equ <>
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef NOAPISET
    include datetimeapi.inc
    ; Datetime APISET dependencies
    include libloaderapi.inc
    ; LibLoader Apiset dependencies
  endif
  if _MSC_VER ge 1200
    ; padding added after data member
  endif
  ; Deprecated attribute support for NLS
  ; Disable NLS deprecation for the moment
  if  not Defined(DISABLE_NLS_DEPRECATION)
    DISABLE_NLS_DEPRECATION equ <>
  endif
  ; Deprecated NLS types/functions
  if  not Defined(DISABLE_NLS_DEPRECATION)
    if Defined(__cplusplus)
      ;[...]
        ; _MSC_VER > 1900
        ; Not Standard C++ or MSVC, ignore the construct.
      ; C++ deprecation
    else
    ; C - disable deprecation
      DEPRECATED macro x
        exitm <>
      endm
    endif
  else
  ; Deprecation is disabled
    DEPRECATED macro x
      exitm <>
    endm
    ;* DISABLE_NLS_DEPRECATION *
  endif
  ifndef NONLS
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ifdef _MAC
        ;[...]
      endif
      if  not Defined(_NORMALIZE_)
        WINNORMALIZEAPI equ <DECLSPEC_IMPORT>
      else
        WINNORMALIZEAPI equ <>
      endif
      ;//////////////////////////////////////////////////////////////////////////
      ;  Constants
      ;  Define all constants for the NLS component here.
      ;//////////////////////////////////////////////////////////////////////////
      ;  String Length Maximums.
      MAX_LEADBYTES equ 12; 5 ranges, 2 bytes ea., 0 term.

      MAX_DEFAULTCHAR equ 2; single or double byte

      ;  Surrogate pairs
      ;  Conversion examples:
      ;  A) The first character in the Surrogate range (D800, DC00) as UTF-32:
      ;  1.  D800: binary 1101100000000000  (lower ten bits: 0000000000)
      ;  2.  DC00: binary 1101110000000000  (lower ten bits: 0000000000)
      ;  3.  Concatenate 0000000000+0000000000 = 0x0000
      ;  4.  Add 0x10000
      ;  Result: U+10000. This is correct, since the first character in the Supplementary character
      ;  range immediately follows the last code point in the 16-bit UTF-16 range (U+FFFF)
      ;  B) A UTF-32 code point such as U+2040A (this a CJK character in CJK Extension B), and wish
      ;  to convert it in UTF-16:
      ;  1.  Subtract 0x10000 - Result: 0x1040A
      ;  2.  Split into two ten-bit pieces: 0001000001 0000001010
      ;  3.  Add 1101100000000000 (0xD800) to the high 10 bits piece (0001000001) - Result: 1101100001000001 (0xD841)
      ;  4.  Add 1101110000000000 (0xDC00) to the low 10 bits piece (0000001010) - Result: 1101110000001010 (0xDC0A)
      ;  RESULT: The surrogate pair: U+D841, U+DC0A
      ;  Special Unicode code point values, for use with UTF-16 surrogate pairs.
      HIGH_SURROGATE_START equ 0d800h
      HIGH_SURROGATE_END equ 0dbffh
      LOW_SURROGATE_START equ 0dc00h
      LOW_SURROGATE_END equ 0dfffh
      ;  MBCS and Unicode Translation Flags.
      ;  Please use Unicode, either UTF-16 (WCHAR) or UTF-8 (CP_UTF8)
      ; MB_PRECOMPOSED and MB_COMPOSITE are deprecated, not recommended, and
      ; provide out-of-date behavior.
      ; Windows typically uses Unicode Normalization Form C type sequences,
      ; If explicit normalization forms are required, please use NormalizeString.
      MB_PRECOMPOSED equ 00000001h; DEPRECATED: use single precomposed characters when possible.

      MB_COMPOSITE equ 00000002h; DEPRECATED: use multiple discrete characters when possible.

      MB_USEGLYPHCHARS equ 00000004h; DEPRECATED: use glyph chars, not ctrl chars

      MB_ERR_INVALID_CHARS equ 00000008h; error for invalid chars

      ; WC_COMPOSITECHECK, WC_DISCARDNS and WC_SEPCHARS are deprecated, not recommended,
      ; and provide out-of-date behavior.
      ; Windows typically uses Unicode Normalization Form C type sequences,
      ; If explicit normalization forms are required, please use NormalizeString.
      WC_COMPOSITECHECK equ 00000200h; convert composite to precomposed

      WC_DISCARDNS equ 00000010h; discard non-spacing chars          // Used with WC_COMPOSITECHECK

      WC_SEPCHARS equ 00000020h; generate separate chars            // Used with WC_COMPOSITECHECK

      WC_DEFAULTCHAR equ 00000040h; replace w/ default char            // Used with WC_COMPOSITECHECK

      if (WINVER ge 0600h)
        WC_ERR_INVALID_CHARS equ 00000080h; error for invalid chars

      endif
      if (WINVER ge 0500h)
        WC_NO_BEST_FIT_CHARS equ 00000400h; do not use best fit chars

        ;* WINVER >= 0x0500 *
      endif
      ;  Character Type Flags.
      CT_CTYPE1 equ 00000001h; ctype 1 information

      CT_CTYPE2 equ 00000002h; ctype 2 information

      CT_CTYPE3 equ 00000004h; ctype 3 information

      ;  CType 1 Flag Bits.
      C1_UPPER equ 0001h; upper case

      C1_LOWER equ 0002h; lower case

      C1_DIGIT equ 0004h; decimal digits

      C1_SPACE equ 0008h; spacing characters

      C1_PUNCT equ 0010h; punctuation characters

      C1_CNTRL equ 0020h; control characters

      C1_BLANK equ 0040h; blank characters

      C1_XDIGIT equ 0080h; other digits

      C1_ALPHA equ 0100h; any linguistic character

      C1_DEFINED equ 0200h; defined character

      ;  CType 2 Flag Bits.
      C2_LEFTTORIGHT equ 0001h; left to right

      C2_RIGHTTOLEFT equ 0002h; right to left

      C2_EUROPENUMBER equ 0003h; European number, digit

      C2_EUROPESEPARATOR equ 0004h; European numeric separator

      C2_EUROPETERMINATOR equ 0005h; European numeric terminator

      C2_ARABICNUMBER equ 0006h; Arabic number

      C2_COMMONSEPARATOR equ 0007h; common numeric separator

      C2_BLOCKSEPARATOR equ 0008h; block separator

      C2_SEGMENTSEPARATOR equ 0009h; segment separator

      C2_WHITESPACE equ 000Ah; white space

      C2_OTHERNEUTRAL equ 000Bh; other neutrals

      C2_NOTAPPLICABLE equ 0000h; no implicit directionality

      ;  CType 3 Flag Bits.
      C3_NONSPACING equ 0001h; nonspacing character

      C3_DIACRITIC equ 0002h; diacritic mark

      C3_VOWELMARK equ 0004h; vowel mark

      C3_SYMBOL equ 0008h; symbols

      C3_KATAKANA equ 0010h; katakana character

      C3_HIRAGANA equ 0020h; hiragana character

      C3_HALFWIDTH equ 0040h; half width character

      C3_FULLWIDTH equ 0080h; full width character

      C3_IDEOGRAPH equ 0100h; ideographic character

      C3_KASHIDA equ 0200h; Arabic kashida character

      C3_LEXICAL equ 0400h; lexical character

      C3_HIGHSURROGATE equ 0800h; high surrogate code unit

      C3_LOWSURROGATE equ 1000h; low surrogate code unit

      C3_ALPHA equ 8000h; any linguistic char (C1_ALPHA)

      C3_NOTAPPLICABLE equ 0000h; ctype 3 is not applicable

      ;  String Flags.
      NORM_IGNORECASE equ 00000001h; ignore case

      NORM_IGNORENONSPACE equ 00000002h; ignore nonspacing chars

      NORM_IGNORESYMBOLS equ 00000004h; ignore symbols

      LINGUISTIC_IGNORECASE equ 00000010h; linguistically appropriate 'ignore case'

      LINGUISTIC_IGNOREDIACRITIC equ 00000020h; linguistically appropriate 'ignore nonspace'

      NORM_IGNOREKANATYPE equ 00010000h; ignore kanatype

      NORM_IGNOREWIDTH equ 00020000h; ignore width

      NORM_LINGUISTIC_CASING equ 08000000h; use linguistic rules for casing

      ;  Locale Independent Mapping Flags.
      MAP_FOLDCZONE equ 00000010h; fold compatibility zone chars

      MAP_PRECOMPOSED equ 00000020h; convert to precomposed chars

      MAP_COMPOSITE equ 00000040h; convert to composite chars

      MAP_FOLDDIGITS equ 00000080h; all digits to ASCII 0-9

      if (WINVER ge 0500h)
        MAP_EXPAND_LIGATURES equ 00002000h; expand all ligatures

        ;* WINVER >= 0x0500 *
      endif
      ;  Locale Dependent Mapping Flags.
      LCMAP_LOWERCASE equ 00000100h; lower case letters

      LCMAP_UPPERCASE equ 00000200h; UPPER CASE LETTERS

      if (WINVER ge _WIN32_WINNT_WIN7)
        LCMAP_TITLECASE equ 00000300h; Title Case Letters

      endif
      ; (WINVER >= _WIN32_WINNT_WIN7)
      LCMAP_SORTKEY equ 00000400h; WC sort key (normalize)

      LCMAP_BYTEREV equ 00000800h; byte reversal

      LCMAP_HIRAGANA equ 00100000h; map katakana to hiragana

      LCMAP_KATAKANA equ 00200000h; map hiragana to katakana

      LCMAP_HALFWIDTH equ 00400000h; map double byte to single byte

      LCMAP_FULLWIDTH equ 00800000h; map single byte to double byte

      LCMAP_LINGUISTIC_CASING equ 01000000h; use linguistic rules for casing

      LCMAP_SIMPLIFIED_CHINESE equ 02000000h; map traditional chinese to simplified chinese

      LCMAP_TRADITIONAL_CHINESE equ 04000000h; map simplified chinese to traditional chinese

      if (WINVER ge _WIN32_WINNT_WIN8)
        LCMAP_SORTHANDLE equ 20000000h
        LCMAP_HASH equ 00040000h
      endif
      ; (WINVER >= _WIN32_WINNT_WIN7)
      ;  Search Flags
      FIND_STARTSWITH equ 00100000h; see if value is at the beginning of source

      FIND_ENDSWITH equ 00200000h; see if value is at the end of source

      FIND_FROMSTART equ 00400000h; look for value in source, starting at the beginning

      FIND_FROMEND equ 00800000h; look for value in source, starting at the end

      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      ; Language Group Enumeration Flags.
      ; The "Language Group" concept is an obsolete concept.
      ; The groups returned are not well defined, arbitrary, inconsistent, inaccurate,
      ; no longer maintained, and no longer supported.
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      LGRPID_INSTALLED equ 00000001h; installed language group ids

      LGRPID_SUPPORTED equ 00000002h; supported language group ids

      ;  Locale Enumeration Flags.
      LCID_INSTALLED equ 00000001h; installed locale ids

      LCID_SUPPORTED equ 00000002h; supported locale ids

      LCID_ALTERNATE_SORTS equ 00000004h; alternate sort locale ids

      if (WINVER ge _WIN32_WINNT_VISTA)
        ;  Named based enumeration flags.
        LOCALE_ALL equ 0; enumerate all named based locales

        LOCALE_WINDOWS equ 00000001h; shipped locales and/or replacements for them

        LOCALE_SUPPLEMENTAL equ 00000002h; supplemental locales only

        LOCALE_ALTERNATE_SORTS equ 00000004h; alternate sort locales

        LOCALE_REPLACEMENT equ 00000008h; locales that replace shipped locales (callback flag only)

      endif
      ; (WINVER >= _WIN32_WINNT_VISTA)
      if (WINVER ge _WIN32_WINNT_WIN7)
        LOCALE_NEUTRALDATA equ 00000010h; Locales that are "neutral" (language only, region data is default)

        LOCALE_SPECIFICDATA equ 00000020h; Locales that contain language and region data

      endif
      ; (WINVER >= _WIN32_WINNT_WIN7)
      ;  Code Page Enumeration Flags.
      CP_INSTALLED equ 00000001h; installed code page ids

      CP_SUPPORTED equ 00000002h; supported code page ids

      ;  Sorting Flags.
      ;    WORD Sort:    culturally correct sort
      ;                  hyphen and apostrophe are special cased
      ;                  example: "coop" and "co-op" will sort together in a list
      ;                        co_op     <-------  underscore (symbol)
      ;                        coat
      ;                        comb
      ;                        coop
      ;                        co-op     <-------  hyphen (punctuation)
      ;                        cork
      ;                        went
      ;                        were
      ;                        we're     <-------  apostrophe (punctuation)
      ;    STRING Sort:  hyphen and apostrophe will sort with all other symbols
      ;                        co-op     <-------  hyphen (punctuation)
      ;                        co_op     <-------  underscore (symbol)
      ;                        coat
      ;                        comb
      ;                        coop
      ;                        cork
      ;                        we're     <-------  apostrophe (punctuation)
      ;                        went
      ;                        were
      SORT_STRINGSORT equ 00001000h; use string sort method

      ;  Sort digits as numbers (ie: 2 comes before 10)
      if (WINVER ge _WIN32_WINNT_WIN7)
        SORT_DIGITSASNUMBERS equ 00000008h; use digits as numbers sort method

      endif
      ; (WINVER >= _WIN32_WINNT_WIN7)
      ;  Compare String Return Values.
      CSTR_LESS_THAN equ 1; string 1 less than string 2

      CSTR_EQUAL equ 2; string 1 equal to string 2

      CSTR_GREATER_THAN equ 3; string 1 greater than string 2

      ;  Code Page Default Values.
      ;  Please Use Unicode, either UTF-16 (as in WCHAR) or UTF-8 (code page CP_ACP)
      CP_ACP equ 0; default to ANSI code page

      CP_OEMCP equ 1; default to OEM  code page

      CP_MACCP equ 2; default to MAC  code page

      CP_THREAD_ACP equ 3; current thread's ANSI code page

      CP_SYMBOL equ 42; SYMBOL translations

      CP_UTF7 equ 65000; UTF-7 translation

      CP_UTF8 equ 65001; UTF-8 translation

      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      ;  Country/Region Codes.
      ;  DEPRECATED: The GEOID  concept is deprecated, please use
      ;  Country/Region Names instead, eg: "US" instead of a GEOID like 244.
      ;  See the documentation for GetGeoInfoEx.
      ;  WARNING: These values are arbitrarily assigned values, please use
      ;           standard country/region names instead, such as "US".
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      CTRY_DEFAULT equ 0
      CTRY_ALBANIA equ 355; Albania

      CTRY_ALGERIA equ 213; Algeria

      CTRY_ARGENTINA equ 54; Argentina

      CTRY_ARMENIA equ 374; Armenia

      CTRY_AUSTRALIA equ 61; Australia

      CTRY_AUSTRIA equ 43; Austria

      CTRY_AZERBAIJAN equ 994; Azerbaijan

      CTRY_BAHRAIN equ 973; Bahrain

      CTRY_BELARUS equ 375; Belarus

      CTRY_BELGIUM equ 32; Belgium

      CTRY_BELIZE equ 501; Belize

      CTRY_BOLIVIA equ 591; Bolivia

      CTRY_BRAZIL equ 55; Brazil

      CTRY_BRUNEI_DARUSSALAM equ 673; Brunei Darussalam

      CTRY_BULGARIA equ 359; Bulgaria

      CTRY_CANADA equ 2; Canada

      CTRY_CARIBBEAN equ 1; Caribbean

      CTRY_CHILE equ 56; Chile

      CTRY_COLOMBIA equ 57; Colombia

      CTRY_COSTA_RICA equ 506; Costa Rica

      CTRY_CROATIA equ 385; Croatia

      CTRY_CZECH equ 420; Czech Republic

      CTRY_DENMARK equ 45; Denmark

      CTRY_DOMINICAN_REPUBLIC equ 1; Dominican Republic

      CTRY_ECUADOR equ 593; Ecuador

      CTRY_EGYPT equ 20; Egypt

      CTRY_EL_SALVADOR equ 503; El Salvador

      CTRY_ESTONIA equ 372; Estonia

      CTRY_FAEROE_ISLANDS equ 298; Faeroe Islands

      CTRY_FINLAND equ 358; Finland

      CTRY_FRANCE equ 33; France

      CTRY_GEORGIA equ 995; Georgia

      CTRY_GERMANY equ 49; Germany

      CTRY_GREECE equ 30; Greece

      CTRY_GUATEMALA equ 502; Guatemala

      CTRY_HONDURAS equ 504; Honduras

      CTRY_HONG_KONG equ 852; Hong Kong S.A.R., P.R.C.

      CTRY_HUNGARY equ 36; Hungary

      CTRY_ICELAND equ 354; Iceland

      CTRY_INDIA equ 91; India

      CTRY_INDONESIA equ 62; Indonesia

      CTRY_IRAN equ 981; Iran

      CTRY_IRAQ equ 964; Iraq

      CTRY_IRELAND equ 353; Ireland

      CTRY_ISRAEL equ 972; Israel

      CTRY_ITALY equ 39; Italy

      CTRY_JAMAICA equ 1; Jamaica

      CTRY_JAPAN equ 81; Japan

      CTRY_JORDAN equ 962; Jordan

      CTRY_KAZAKSTAN equ 7; Kazakstan

      CTRY_KENYA equ 254; Kenya

      CTRY_KUWAIT equ 965; Kuwait

      CTRY_KYRGYZSTAN equ 996; Kyrgyzstan

      CTRY_LATVIA equ 371; Latvia

      CTRY_LEBANON equ 961; Lebanon

      CTRY_LIBYA equ 218; Libya

      CTRY_LIECHTENSTEIN equ 41; Liechtenstein

      CTRY_LITHUANIA equ 370; Lithuania

      CTRY_LUXEMBOURG equ 352; Luxembourg

      CTRY_MACAU equ 853; Macao SAR, PRC

      CTRY_MACEDONIA equ 389; Former Yugoslav Republic of Macedonia

      CTRY_MALAYSIA equ 60; Malaysia

      CTRY_MALDIVES equ 960; Maldives

      CTRY_MEXICO equ 52; Mexico

      CTRY_MONACO equ 33; Principality of Monaco

      CTRY_MONGOLIA equ 976; Mongolia

      CTRY_MOROCCO equ 212; Morocco

      CTRY_NETHERLANDS equ 31; Netherlands

      CTRY_NEW_ZEALAND equ 64; New Zealand

      CTRY_NICARAGUA equ 505; Nicaragua

      CTRY_NORWAY equ 47; Norway

      CTRY_OMAN equ 968; Oman

      CTRY_PAKISTAN equ 92; Islamic Republic of Pakistan

      CTRY_PANAMA equ 507; Panama

      CTRY_PARAGUAY equ 595; Paraguay

      CTRY_PERU equ 51; Peru

      CTRY_PHILIPPINES equ 63; Republic of the Philippines

      CTRY_POLAND equ 48; Poland

      CTRY_PORTUGAL equ 351; Portugal

      CTRY_PRCHINA equ 86; People's Republic of China

      CTRY_PUERTO_RICO equ 1; Puerto Rico

      CTRY_QATAR equ 974; Qatar

      CTRY_ROMANIA equ 40; Romania

      CTRY_RUSSIA equ 7; Russia

      CTRY_SAUDI_ARABIA equ 966; Saudi Arabia

      CTRY_SERBIA equ 381; Serbia

      CTRY_SINGAPORE equ 65; Singapore

      CTRY_SLOVAK equ 421; Slovak Republic

      CTRY_SLOVENIA equ 386; Slovenia

      CTRY_SOUTH_AFRICA equ 27; South Africa

      CTRY_SOUTH_KOREA equ 82; Korea

      CTRY_SPAIN equ 34; Spain

      CTRY_SWEDEN equ 46; Sweden

      CTRY_SWITZERLAND equ 41; Switzerland

      CTRY_SYRIA equ 963; Syria

      CTRY_TAIWAN equ 886; Taiwan

      CTRY_TATARSTAN equ 7; Tatarstan

      CTRY_THAILAND equ 66; Thailand

      CTRY_TRINIDAD_Y_TOBAGO equ 1; Trinidad y Tobago

      CTRY_TUNISIA equ 216; Tunisia

      CTRY_TURKEY equ 90; Turkey

      CTRY_UAE equ 971; U.A.E.

      CTRY_UKRAINE equ 380; Ukraine

      CTRY_UNITED_KINGDOM equ 44; United Kingdom

      CTRY_UNITED_STATES equ 1; United States

      CTRY_URUGUAY equ 598; Uruguay

      CTRY_UZBEKISTAN equ 7; Uzbekistan

      CTRY_VENEZUELA equ 58; Venezuela

      CTRY_VIET_NAM equ 84; Viet Nam

      CTRY_YEMEN equ 967; Yemen

      CTRY_ZIMBABWE equ 263; Zimbabwe

      ;  Locale Types.
      ;  These types are used for the GetLocaleInfo NLS API routine.
      ;  Some of these types are also used for the SetLocaleInfo NLS API routine.
      ;  The following LCTypes may be used in combination with any other LCTypes.
      ;    LOCALE_NOUSEROVERRIDE is also used in GetTimeFormat and
      ;    GetDateFormat.
      ;    LOCALE_RETURN_NUMBER will return the result from GetLocaleInfo as a
      ;    number instead of a string.  This flag is only valid for the LCTypes
      ;    beginning with LOCALE_I.
      ;    DEPRECATED: LOCALE_USE_CP_ACP is used in many of the A (Ansi) apis that need
      ;                to do string translation.  Callers are encouraged to use the W
      ;                (WCHAR/Unicode) apis instead.
      LOCALE_NOUSEROVERRIDE equ 80000000h; Not Recommended - do not use user overrides

      LOCALE_USE_CP_ACP equ 40000000h; DEPRECATED, call Unicode APIs instead: use the system ACP

      if (WINVER ge 0400h)
        LOCALE_RETURN_NUMBER equ 20000000h; return number instead of string

        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge _WIN32_WINNT_WIN7)
        LOCALE_RETURN_GENITIVE_NAMES equ 10000000h;Flag to return the Genitive forms of month names

        LOCALE_ALLOW_NEUTRAL_NAMES equ 08000000h;Flag to allow returning neutral names/lcids for name conversion

      endif
      ;(WINVER >= _WIN32_WINNT_WIN7)
      ;  The following LCTypes are mutually exclusive in that they may NOT
      ;  be used in combination with each other.
      ; These are the various forms of the name of the locale:
      LOCALE_SLOCALIZEDDISPLAYNAME equ 00000002h; localized name of locale, eg "German (Germany)" in UI language

      if (WINVER ge _WIN32_WINNT_WIN7)
        LOCALE_SENGLISHDISPLAYNAME equ 00000072h; Display name (language + country/region usually) in English, eg "German (Germany)"

        LOCALE_SNATIVEDISPLAYNAME equ 00000073h; Display name in native locale language, eg "Deutsch (Deutschland)

      endif
      ;(WINVER >= _WIN32_WINNT_WIN7)
      if (WINVER ge _WIN32_WINNT_VISTA)
        LOCALE_SLOCALIZEDLANGUAGENAME equ 0000006fh; Language Display Name for a language, eg "German" in UI language

      endif
      ;(WINVER >= _WIN32_WINNT_VISTA)
      LOCALE_SENGLISHLANGUAGENAME equ 00001001h; English name of language, eg "German"

      LOCALE_SNATIVELANGUAGENAME equ 00000004h; native name of language, eg "Deutsch"

      LOCALE_SLOCALIZEDCOUNTRYNAME equ 00000006h; localized name of country/region, eg "Germany" in UI language

      LOCALE_SENGLISHCOUNTRYNAME equ 00001002h; English name of country/region, eg "Germany"

      LOCALE_SNATIVECOUNTRYNAME equ 00000008h; native name of country/region, eg "Deutschland"

      ; Additional LCTypes
      LOCALE_IDIALINGCODE equ 00000005h; country/region dialing code, example: en-US and en-CA return 1.

      LOCALE_SLIST equ 0000000Ch; list item separator, eg "," for "1,2,3,4"

      LOCALE_IMEASURE equ 0000000Dh; 0 = metric, 1 = US measurement system

      LOCALE_SDECIMAL equ 0000000Eh; decimal separator, eg "." for 1,234.00

      LOCALE_STHOUSAND equ 0000000Fh; thousand separator, eg "," for 1,234.00

      LOCALE_SGROUPING equ 00000010h; digit grouping, eg "3;0" for 1,000,000

      LOCALE_IDIGITS equ 00000011h; number of fractional digits eg 2 for 1.00

      LOCALE_ILZERO equ 00000012h; leading zeros for decimal, 0 for .97, 1 for 0.97

      LOCALE_INEGNUMBER equ 00001010h; negative number mode, 0-4, see documentation

      LOCALE_SNATIVEDIGITS equ 00000013h; native digits for 0-9, eg "0123456789"

      LOCALE_SCURRENCY equ 00000014h; local monetary symbol, eg "$"

      LOCALE_SINTLSYMBOL equ 00000015h; intl monetary symbol, eg "USD"

      LOCALE_SMONDECIMALSEP equ 00000016h; monetary decimal separator, eg "." for $1,234.00

      LOCALE_SMONTHOUSANDSEP equ 00000017h; monetary thousand separator, eg "," for $1,234.00

      LOCALE_SMONGROUPING equ 00000018h; monetary grouping, eg "3;0" for $1,000,000.00

      LOCALE_ICURRDIGITS equ 00000019h; # local monetary digits, eg 2 for $1.00

      LOCALE_ICURRENCY equ 0000001Bh; positive currency mode, 0-3, see documentation

      LOCALE_INEGCURR equ 0000001Ch; negative currency mode, 0-15, see documentation

      LOCALE_SSHORTDATE equ 0000001Fh; short date format string, eg "MM/dd/yyyy"

      LOCALE_SLONGDATE equ 00000020h; long date format string, eg "dddd, MMMM dd, yyyy"

      LOCALE_STIMEFORMAT equ 00001003h; time format string, eg "HH:mm:ss"

      LOCALE_SAM equ 00000028h; AM designator, eg "AM"

      LOCALE_SPM equ 00000029h; PM designator, eg "PM"

      LOCALE_ICALENDARTYPE equ 00001009h; type of calendar specifier, eg CAL_GREGORIAN

      LOCALE_IOPTIONALCALENDAR equ 0000100Bh; additional calendar types specifier, eg CAL_GREGORIAN_US

      LOCALE_IFIRSTDAYOFWEEK equ 0000100Ch; first day of week specifier, 0-6, 0=Monday, 6=Sunday

      LOCALE_IFIRSTWEEKOFYEAR equ 0000100Dh; first week of year specifier, 0-2, see documentation

      LOCALE_SDAYNAME1 equ 0000002Ah; long name for Monday

      LOCALE_SDAYNAME2 equ 0000002Bh; long name for Tuesday

      LOCALE_SDAYNAME3 equ 0000002Ch; long name for Wednesday

      LOCALE_SDAYNAME4 equ 0000002Dh; long name for Thursday

      LOCALE_SDAYNAME5 equ 0000002Eh; long name for Friday

      LOCALE_SDAYNAME6 equ 0000002Fh; long name for Saturday

      LOCALE_SDAYNAME7 equ 00000030h; long name for Sunday

      LOCALE_SABBREVDAYNAME1 equ 00000031h; abbreviated name for Monday

      LOCALE_SABBREVDAYNAME2 equ 00000032h; abbreviated name for Tuesday

      LOCALE_SABBREVDAYNAME3 equ 00000033h; abbreviated name for Wednesday

      LOCALE_SABBREVDAYNAME4 equ 00000034h; abbreviated name for Thursday

      LOCALE_SABBREVDAYNAME5 equ 00000035h; abbreviated name for Friday

      LOCALE_SABBREVDAYNAME6 equ 00000036h; abbreviated name for Saturday

      LOCALE_SABBREVDAYNAME7 equ 00000037h; abbreviated name for Sunday

      LOCALE_SMONTHNAME1 equ 00000038h; long name for January

      LOCALE_SMONTHNAME2 equ 00000039h; long name for February

      LOCALE_SMONTHNAME3 equ 0000003Ah; long name for March

      LOCALE_SMONTHNAME4 equ 0000003Bh; long name for April

      LOCALE_SMONTHNAME5 equ 0000003Ch; long name for May

      LOCALE_SMONTHNAME6 equ 0000003Dh; long name for June

      LOCALE_SMONTHNAME7 equ 0000003Eh; long name for July

      LOCALE_SMONTHNAME8 equ 0000003Fh; long name for August

      LOCALE_SMONTHNAME9 equ 00000040h; long name for September

      LOCALE_SMONTHNAME10 equ 00000041h; long name for October

      LOCALE_SMONTHNAME11 equ 00000042h; long name for November

      LOCALE_SMONTHNAME12 equ 00000043h; long name for December

      LOCALE_SMONTHNAME13 equ 0000100Eh; long name for 13th month (if exists)

      LOCALE_SABBREVMONTHNAME1 equ 00000044h; abbreviated name for January

      LOCALE_SABBREVMONTHNAME2 equ 00000045h; abbreviated name for February

      LOCALE_SABBREVMONTHNAME3 equ 00000046h; abbreviated name for March

      LOCALE_SABBREVMONTHNAME4 equ 00000047h; abbreviated name for April

      LOCALE_SABBREVMONTHNAME5 equ 00000048h; abbreviated name for May

      LOCALE_SABBREVMONTHNAME6 equ 00000049h; abbreviated name for June

      LOCALE_SABBREVMONTHNAME7 equ 0000004Ah; abbreviated name for July

      LOCALE_SABBREVMONTHNAME8 equ 0000004Bh; abbreviated name for August

      LOCALE_SABBREVMONTHNAME9 equ 0000004Ch; abbreviated name for September

      LOCALE_SABBREVMONTHNAME10 equ 0000004Dh; abbreviated name for October

      LOCALE_SABBREVMONTHNAME11 equ 0000004Eh; abbreviated name for November

      LOCALE_SABBREVMONTHNAME12 equ 0000004Fh; abbreviated name for December

      LOCALE_SABBREVMONTHNAME13 equ 0000100Fh; abbreviated name for 13th month (if exists)

      LOCALE_SPOSITIVESIGN equ 00000050h; positive sign, eg ""

      LOCALE_SNEGATIVESIGN equ 00000051h; negative sign, eg "-"

      LOCALE_IPOSSIGNPOSN equ 00000052h; positive sign position (derived from INEGCURR)

      LOCALE_INEGSIGNPOSN equ 00000053h; negative sign position (derived from INEGCURR)

      LOCALE_IPOSSYMPRECEDES equ 00000054h; mon sym precedes pos amt (derived from ICURRENCY)

      LOCALE_IPOSSEPBYSPACE equ 00000055h; mon sym sep by space from pos amt (derived from ICURRENCY)

      LOCALE_INEGSYMPRECEDES equ 00000056h; mon sym precedes neg amt (derived from INEGCURR)

      LOCALE_INEGSEPBYSPACE equ 00000057h; mon sym sep by space from neg amt (derived from INEGCURR)

      if (WINVER ge 0400h)
        LOCALE_FONTSIGNATURE equ 00000058h; font signature

        LOCALE_SISO639LANGNAME equ 00000059h; ISO abbreviated language name, eg "en"

        LOCALE_SISO3166CTRYNAME equ 0000005Ah; ISO abbreviated country/region name, eg "US"

        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0500h)
        LOCALE_IPAPERSIZE equ 0000100Ah; 1 = letter, 5 = legal, 8 = a3, 9 = a4

        LOCALE_SENGCURRNAME equ 00001007h; english name of currency, eg "Euro"

        LOCALE_SNATIVECURRNAME equ 00001008h; native name of currency, eg "euro"

        LOCALE_SYEARMONTH equ 00001006h; year month format string, eg "MM/yyyy"

        LOCALE_SSORTNAME equ 00001013h; sort name, usually "", eg "Dictionary" in UI Language

        LOCALE_IDIGITSUBSTITUTION equ 00001014h; 0 = context, 1 = none, 2 = national

        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0600h)
        LOCALE_SNAME equ 0000005ch; locale name (ie: en-us)

        LOCALE_SDURATION equ 0000005dh; time duration format, eg "hh:mm:ss"

        LOCALE_SSHORTESTDAYNAME1 equ 00000060h; Shortest day name for Monday

        LOCALE_SSHORTESTDAYNAME2 equ 00000061h; Shortest day name for Tuesday

        LOCALE_SSHORTESTDAYNAME3 equ 00000062h; Shortest day name for Wednesday

        LOCALE_SSHORTESTDAYNAME4 equ 00000063h; Shortest day name for Thursday

        LOCALE_SSHORTESTDAYNAME5 equ 00000064h; Shortest day name for Friday

        LOCALE_SSHORTESTDAYNAME6 equ 00000065h; Shortest day name for Saturday

        LOCALE_SSHORTESTDAYNAME7 equ 00000066h; Shortest day name for Sunday

        LOCALE_SISO639LANGNAME2 equ 00000067h; 3 character ISO abbreviated language name, eg "eng"

        LOCALE_SISO3166CTRYNAME2 equ 00000068h; 3 character ISO country/region name, eg "USA"

        LOCALE_SNAN equ 00000069h; Not a Number, eg "NaN"

        LOCALE_SPOSINFINITY equ 0000006ah; + Infinity, eg "infinity"

        LOCALE_SNEGINFINITY equ 0000006bh; - Infinity, eg "-infinity"

        LOCALE_SSCRIPTS equ 0000006ch; Typical scripts in the locale: ; delimited script codes, eg "Latn;"

        LOCALE_SPARENT equ 0000006dh; Fallback name for resources, eg "en" for "en-US"

        LOCALE_SCONSOLEFALLBACKNAME equ 0000006eh; Fallback name for within the console for Unicode Only locales, eg "en" for bn-IN

      endif
      ;(WINVER >= 0x0600)
      if (WINVER ge _WIN32_WINNT_WIN7)
        LOCALE_IREADINGLAYOUT equ 00000070h; Returns one of the following 4 reading layout values:

        ; 0 - Left to right (eg en-US)
        ; 1 - Right to left (eg arabic locales)
        ; 2 - Vertical top to bottom with columns to the left and also left to right (ja-JP locales)
        ; 3 - Vertical top to bottom with columns proceeding to the right
        LOCALE_INEUTRAL equ 00000071h; Returns 0 for specific cultures, 1 for neutral cultures.

        LOCALE_INEGATIVEPERCENT equ 00000074h; Returns 0-11 for the negative percent format

        LOCALE_IPOSITIVEPERCENT equ 00000075h; Returns 0-3 for the positive percent formatIPOSITIVEPERCENT

        LOCALE_SPERCENT equ 00000076h; Returns the percent symbol

        LOCALE_SPERMILLE equ 00000077h; Returns the permille (U+2030) symbol

        LOCALE_SMONTHDAY equ 00000078h; Returns the preferred month/day format

        LOCALE_SSHORTTIME equ 00000079h; Returns the preferred short time format (ie: no seconds, just h:mm)

        LOCALE_SOPENTYPELANGUAGETAG equ 0000007ah; Open type language tag, eg: "latn" or "dflt"

        LOCALE_SSORTLOCALE equ 0000007bh; Name of locale to use for sorting/collation/casing behavior.

      endif
      ;(WINVER >= _WIN32_WINNT_WIN7)
      if (WINVER ge _WIN32_WINNT_WIN8)
        LOCALE_SRELATIVELONGDATE equ 0000007ch; Long date without year, day of week, month, date, eg: for lock screen

      endif
      if (WINVER ge _WIN32_WINNT_WINBLUE)
        LOCALE_ICONSTRUCTEDLOCALE equ 0000007dh; Flags if this locale is constructed.  Avoid using.

      endif
      if (WINVER ge _WIN32_WINNT_WIN10)
        LOCALE_SSHORTESTAM equ 0000007eh; Shortest AM designator, eg "A"

        LOCALE_SSHORTESTPM equ 0000007fh; Shortest PM designator, eg "P"

      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_MN)
        LOCALE_IUSEUTF8LEGACYACP equ 00000666h; default ansi code page (use of Unicode is recommended instead)

        LOCALE_IUSEUTF8LEGACYOEMCP equ 00000999h; default oem code page (use of Unicode is recommended instead)

      endif
      ; DEPRECATED LCTYPEs
      ; DEPRECATED LCTYPEs for Code Pages
      ; Applications are strongly encouraged to Use Unicode, such as UTF-16 (WCHAR type)
      ; or the CP_UTF8 Code Page.  Legacy encodings are unable to represent the full
      ; set of scripts/language and characters (& emoji!) available on modern computers.
      ; Use of legacy code pages (encodings) is a leading cause of data loss and corruption.
      LOCALE_IDEFAULTCODEPAGE equ 0000000Bh; default oem code page for locale (user may configure as UTF-8, use of Unicode is recommended instead)

      LOCALE_IDEFAULTANSICODEPAGE equ 00001004h; default ansi code page for locale (user may configure as UTF-8, use of Unicode is recommended instead)

      LOCALE_IDEFAULTMACCODEPAGE equ 00001011h; default mac code page for locale (user may configure as UTF-8, use of Unicode is recommended instead)

      if (WINVER ge 0500h)
        LOCALE_IDEFAULTEBCDICCODEPAGE equ 00001012h; default ebcdic code page for a locale (use of Unicode is recommended instead)

        ;* WINVER >= 0x0500 *
      endif
      ; LCTYPEs using out-of-date concepts
      LOCALE_ILANGUAGE equ 00000001h; DEPRECATED language id (LCID), LOCALE_SNAME preferred

      LOCALE_SABBREVLANGNAME equ 00000003h; DEPRECATED arbitrary abbreviated language name, LOCALE_SISO639LANGNAME instead.

      LOCALE_SABBREVCTRYNAME equ 00000007h; DEPRECATED arbitrary abbreviated country/region name, LOCALE_SISO3166CTRYNAME instead.

      LOCALE_IGEOID equ 0000005Bh; DEPRECATED geographical location id, use LOCALE_SISO3166CTRYNAME instead.

      LOCALE_IDEFAULTLANGUAGE equ 00000009h; DEPRECATED default language id, deprecated

      LOCALE_IDEFAULTCOUNTRY equ 0000000Ah; DEPRECATED default country/region code, deprecated

      LOCALE_IINTLCURRDIGITS equ 0000001Ah; DEPRECATED, use LOCALE_ICURRDIGITS # intl monetary digits, eg 2 for $1.00

      ; Derived legacy date & time values for compatibility only.
      ; Please use the appropriate date or time pattern instead.
      ; These can be misleading, for example a locale configured as 12h24m52s could have a time separator of "h".
      LOCALE_SDATE equ 0000001Dh; DEPRECATED date separator (derived from LOCALE_SSHORTDATE, use that instead)

      LOCALE_STIME equ 0000001Eh; DEPRECATED time separator (derived from LOCALE_STIMEFORMAT, use that instead)

      LOCALE_IDATE equ 00000021h; DEPRECATED short date format ordering (derived from LOCALE_SSHORTDATE, use that instead)

      LOCALE_ILDATE equ 00000022h; DEPRECATED long date format ordering (derived from LOCALE_SLONGDATE, use that instead)

      LOCALE_ITIME equ 00000023h; DEPRECATED time format specifier (derived from LOCALE_STIMEFORMAT, use that instead)

      LOCALE_ITIMEMARKPOSN equ 00001005h; DEPRECATED time marker position (derived from LOCALE_STIMEFORMAT, use that instead)

      LOCALE_ICENTURY equ 00000024h; DEPRECATED century format specifier (short date, LOCALE_SSHORTDATE is preferred)

      LOCALE_ITLZERO equ 00000025h; DEPRECATED leading zeros in time field (derived from LOCALE_STIMEFORMAT, use that instead)

      LOCALE_IDAYLZERO equ 00000026h; DEPRECATED leading zeros in day field (short date, LOCALE_SSHORTDATE is preferred)

      LOCALE_IMONLZERO equ 00000027h; DEPRECATED leading zeros in month field (short date, LOCALE_SSHORTDATE is preferred)

      if (WINVER ge 0600h)
        LOCALE_SKEYBOARDSTOINSTALL equ 0000005eh; Used internally, see GetKeyboardLayoutName() function

        ;* WINVER >= 0x0600 *
      endif
      ; LCTYPEs which have been renamed to enable more understandable source code.
      LOCALE_SLANGUAGE equ <LOCALE_SLOCALIZEDDISPLAYNAME>; DEPRECATED as new name is more readable.

      if (WINVER ge _WIN32_WINNT_VISTA)
        LOCALE_SLANGDISPLAYNAME equ <LOCALE_SLOCALIZEDLANGUAGENAME>; DEPRECATED as new name is more readable.

      endif
      ;(WINVER >= _WIN32_WINNT_VISTA)
      LOCALE_SENGLANGUAGE equ <LOCALE_SENGLISHLANGUAGENAME>; DEPRECATED as new name is more readable.

      LOCALE_SNATIVELANGNAME equ <LOCALE_SNATIVELANGUAGENAME>; DEPRECATED as new name is more readable.

      LOCALE_SCOUNTRY equ <LOCALE_SLOCALIZEDCOUNTRYNAME>; DEPRECATED as new name is more readable.

      LOCALE_SENGCOUNTRY equ <LOCALE_SENGLISHCOUNTRYNAME>; DEPRECATED as new name is more readable.

      LOCALE_SNATIVECTRYNAME equ <LOCALE_SNATIVECOUNTRYNAME>; DEPRECATED as new name is more readable.

      ; DEPRECATED: Use LOCALE_SISO3166CTRYNAME to query for a region identifier, LOCALE_ICOUNTRY is not a region identifier.
      LOCALE_ICOUNTRY equ <LOCALE_IDIALINGCODE>; Deprecated synonym for LOCALE_IDIALINGCODE

      LOCALE_S1159 equ <LOCALE_SAM>; DEPRECATED: Please use LOCALE_SAM, which is more readable.

      LOCALE_S2359 equ <LOCALE_SPM>; DEPRECATED: Please use LOCALE_SPM, which is more readable.

      ;  Time Flags for GetTimeFormat.
      TIME_NOMINUTESORSECONDS equ 00000001h; do not use minutes or seconds

      TIME_NOSECONDS equ 00000002h; do not use seconds

      TIME_NOTIMEMARKER equ 00000004h; do not use time marker

      TIME_FORCE24HOURFORMAT equ 00000008h; always use 24 hour format

      ;  Date Flags for GetDateFormat.
      DATE_SHORTDATE equ 00000001h; use short date picture

      DATE_LONGDATE equ 00000002h; use long date picture

      DATE_USE_ALT_CALENDAR equ 00000004h; use alternate calendar (if any)

      if (WINVER ge 0500h)
        DATE_YEARMONTH equ 00000008h; use year month picture

        DATE_LTRREADING equ 00000010h; add marks for left to right reading order layout

        DATE_RTLREADING equ 00000020h; add marks for right to left reading order layout

        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge _WIN32_WINNT_WIN7)
        DATE_AUTOLAYOUT equ 00000040h; add appropriate marks for left-to-right or right-to-left reading order layout

      endif
      ;(WINVER >= _WIN32_WINNT_WIN7)
      if (WINVER ge _WIN32_WINNT_WINTHRESHOLD)
        DATE_MONTHDAY equ 00000080h; include month day pictures

      endif
      ;(WINVER >= _WIN32_WINNT_WINTHRESHOLD)
      ;  Calendar Types.
      ;  These types are used for the EnumCalendarInfo and GetCalendarInfo
      ;  NLS API routines.
      ;  Some of these types are also used for the SetCalendarInfo NLS API
      ;  routine.
      ;  The following CalTypes may be used in combination with any other CalTypes.
      ;    CAL_NOUSEROVERRIDE
      ;    CAL_RETURN_NUMBER will return the result from GetCalendarInfo as a
      ;    number instead of a string.  This flag is only valid for the CalTypes
      ;    beginning with CAL_I.
      ;    DEPRECATED: CAL_USE_CP_ACP is used in many of the A (Ansi) apis that need
      ;                to do string translation.  Callers are encouraged to use the W
      ;                (WCHAR/Unicode) apis instead.
      if (WINVER ge 0500h)
        CAL_NOUSEROVERRIDE equ <LOCALE_NOUSEROVERRIDE>; Not Recommended - do not use user overrides

        CAL_USE_CP_ACP equ <LOCALE_USE_CP_ACP>; DEPRECATED, call Unicode APIs instead: use the system ACP

        CAL_RETURN_NUMBER equ <LOCALE_RETURN_NUMBER>; return number instead of string

        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge _WIN32_WINNT_WIN7)
        CAL_RETURN_GENITIVE_NAMES equ <LOCALE_RETURN_GENITIVE_NAMES>; return genitive forms of month names

      endif
      ; winver >= windows 7
      ;  The following CalTypes are mutually exclusive in that they may NOT
      ;  be used in combination with each other.
      CAL_ICALINTVALUE equ 00000001h; calendar type

      CAL_SCALNAME equ 00000002h; native name of calendar

      CAL_IYEAROFFSETRANGE equ 00000003h; starting years of eras

      CAL_SERASTRING equ 00000004h; era name for IYearOffsetRanges, eg A.D.

      CAL_SSHORTDATE equ 00000005h; short date format string

      CAL_SLONGDATE equ 00000006h; long date format string

      CAL_SDAYNAME1 equ 00000007h; native name for Monday

      CAL_SDAYNAME2 equ 00000008h; native name for Tuesday

      CAL_SDAYNAME3 equ 00000009h; native name for Wednesday

      CAL_SDAYNAME4 equ 0000000ah; native name for Thursday

      CAL_SDAYNAME5 equ 0000000bh; native name for Friday

      CAL_SDAYNAME6 equ 0000000ch; native name for Saturday

      CAL_SDAYNAME7 equ 0000000dh; native name for Sunday

      CAL_SABBREVDAYNAME1 equ 0000000eh; abbreviated name for Mon

      CAL_SABBREVDAYNAME2 equ 0000000fh; abbreviated name for Tue

      CAL_SABBREVDAYNAME3 equ 00000010h; abbreviated name for Wed

      CAL_SABBREVDAYNAME4 equ 00000011h; abbreviated name for Thu

      CAL_SABBREVDAYNAME5 equ 00000012h; abbreviated name for Fri

      CAL_SABBREVDAYNAME6 equ 00000013h; abbreviated name for Sat

      CAL_SABBREVDAYNAME7 equ 00000014h; abbreviated name for Sun

      ; Note that in the hebrew calendar the leap month name is always returned as the 7th month
      CAL_SMONTHNAME1 equ 00000015h; native name for January

      CAL_SMONTHNAME2 equ 00000016h; native name for February

      CAL_SMONTHNAME3 equ 00000017h; native name for March

      CAL_SMONTHNAME4 equ 00000018h; native name for April

      CAL_SMONTHNAME5 equ 00000019h; native name for May

      CAL_SMONTHNAME6 equ 0000001ah; native name for June

      CAL_SMONTHNAME7 equ 0000001bh; native name for July

      CAL_SMONTHNAME8 equ 0000001ch; native name for August

      CAL_SMONTHNAME9 equ 0000001dh; native name for September

      CAL_SMONTHNAME10 equ 0000001eh; native name for October

      CAL_SMONTHNAME11 equ 0000001fh; native name for November

      CAL_SMONTHNAME12 equ 00000020h; native name for December

      CAL_SMONTHNAME13 equ 00000021h; native name for 13th month (if any)

      CAL_SABBREVMONTHNAME1 equ 00000022h; abbreviated name for Jan

      CAL_SABBREVMONTHNAME2 equ 00000023h; abbreviated name for Feb

      CAL_SABBREVMONTHNAME3 equ 00000024h; abbreviated name for Mar

      CAL_SABBREVMONTHNAME4 equ 00000025h; abbreviated name for Apr

      CAL_SABBREVMONTHNAME5 equ 00000026h; abbreviated name for May

      CAL_SABBREVMONTHNAME6 equ 00000027h; abbreviated name for Jun

      CAL_SABBREVMONTHNAME7 equ 00000028h; abbreviated name for July

      CAL_SABBREVMONTHNAME8 equ 00000029h; abbreviated name for Aug

      CAL_SABBREVMONTHNAME9 equ 0000002ah; abbreviated name for Sep

      CAL_SABBREVMONTHNAME10 equ 0000002bh; abbreviated name for Oct

      CAL_SABBREVMONTHNAME11 equ 0000002ch; abbreviated name for Nov

      CAL_SABBREVMONTHNAME12 equ 0000002dh; abbreviated name for Dec

      CAL_SABBREVMONTHNAME13 equ 0000002eh; abbreviated name for 13th month (if any)

      if (WINVER ge 0500h)
        CAL_SYEARMONTH equ 0000002fh; year month format string

        CAL_ITWODIGITYEARMAX equ 00000030h; two digit year max

        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0600h)
        CAL_SSHORTESTDAYNAME1 equ 00000031h; Shortest day name for Mo

        CAL_SSHORTESTDAYNAME2 equ 00000032h; Shortest day name for Tu

        CAL_SSHORTESTDAYNAME3 equ 00000033h; Shortest day name for We

        CAL_SSHORTESTDAYNAME4 equ 00000034h; Shortest day name for Th

        CAL_SSHORTESTDAYNAME5 equ 00000035h; Shortest day name for Fr

        CAL_SSHORTESTDAYNAME6 equ 00000036h; Shortest day name for Sa

        CAL_SSHORTESTDAYNAME7 equ 00000037h; Shortest day name for Su

      endif
      ;(WINVER >= 0x0600)
      if (WINVER ge _WIN32_WINNT_WIN7)
        CAL_SMONTHDAY equ 00000038h; Month/day format

        CAL_SABBREVERASTRING equ 00000039h; Abbreviated era string (eg: AD)

      endif
      ; winver >= windows 7
      if (WINVER ge _WIN32_WINNT_WIN8)
        CAL_SRELATIVELONGDATE equ 0000003ah; Long date without year, day of week, month, date, eg: for lock screen

      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
        CAL_SENGLISHERANAME equ 0000003bh; Japanese calendar only: return the English era names for .Net compatibility

        CAL_SENGLISHABBREVERANAME equ 0000003ch; Japanese calendar only: return the English Abbreviated era names for .Net compatibility

      endif
      ; CAL_SJAPANESEERAFIRSTYEAR is only supported on machines with updates to support the "gannen" era first year behavior
      ; Machines without that update will return 0 and ERROR_INVALID_FLAGS, in which case ichinen is presumed.
      CAL_SJAPANESEERAFIRSTYEAR equ 0000003dh; Japanese calendar only: return ichinen or gannen first year

      ;  Calendar Enumeration Value.
      ENUM_ALL_CALENDARS equ 0ffffffffh; enumerate all calendars

      ;  Calendar ID Values.
      CAL_GREGORIAN equ 1; Gregorian (localized) calendar

      CAL_GREGORIAN_US equ 2; Gregorian (U.S.) calendar

      CAL_JAPAN equ 3; Japanese Emperor Era calendar

      CAL_TAIWAN equ 4; Taiwan calendar

      CAL_KOREA equ 5; Korean Tangun Era calendar

      CAL_HIJRI equ 6; Hijri (Arabic Lunar) calendar

      CAL_THAI equ 7; Thai calendar

      CAL_HEBREW equ 8; Hebrew (Lunar) calendar

      CAL_GREGORIAN_ME_FRENCH equ 9; Gregorian Middle East French calendar

      CAL_GREGORIAN_ARABIC equ 10; Gregorian Arabic calendar

      CAL_GREGORIAN_XLIT_ENGLISH equ 11; Gregorian Transliterated English calendar

      CAL_GREGORIAN_XLIT_FRENCH equ 12; Gregorian Transliterated French calendar

      CAL_PERSIAN equ 22; Persian (Solar Hijri) calendar

      CAL_UMALQURA equ 23; UmAlQura Hijri (Arabic Lunar) calendar

      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      ;  Language Group ID Values
      ; The "Language Group" concept is an obsolete concept.
      ; The groups returned are not well defined, arbitrary, inconsistent, inaccurate,
      ; no longer maintained, and no longer supported.
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      LGRPID_WESTERN_EUROPE equ 0001h; Western Europe & U.S.

      LGRPID_CENTRAL_EUROPE equ 0002h; Central Europe

      LGRPID_BALTIC equ 0003h; Baltic

      LGRPID_GREEK equ 0004h; Greek

      LGRPID_CYRILLIC equ 0005h; Cyrillic

      LGRPID_TURKIC equ 0006h; Turkic

      LGRPID_TURKISH equ 0006h; Turkish

      LGRPID_JAPANESE equ 0007h; Japanese

      LGRPID_KOREAN equ 0008h; Korean

      LGRPID_TRADITIONAL_CHINESE equ 0009h; Traditional Chinese

      LGRPID_SIMPLIFIED_CHINESE equ 000ah; Simplified Chinese

      LGRPID_THAI equ 000bh; Thai

      LGRPID_HEBREW equ 000ch; Hebrew

      LGRPID_ARABIC equ 000dh; Arabic

      LGRPID_VIETNAMESE equ 000eh; Vietnamese

      LGRPID_INDIC equ 000fh; Indic

      LGRPID_GEORGIAN equ 0010h; Georgian

      LGRPID_ARMENIAN equ 0011h; Armenian

      if (WINVER ge 0600h)
        ;  MUI function flag values
        MUI_LANGUAGE_ID equ 4h; Use traditional language ID convention

        MUI_LANGUAGE_NAME equ 8h; Use ISO language (culture) name convention

        MUI_MERGE_SYSTEM_FALLBACK equ 10h; GetThreadPreferredUILanguages merges in parent and base languages

        MUI_MERGE_USER_FALLBACK equ 20h; GetThreadPreferredUILanguages merges in user preferred languages

        MUI_UI_FALLBACK equ <MUI_MERGE_SYSTEM_FALLBACK or MUI_MERGE_USER_FALLBACK>
        MUI_THREAD_LANGUAGES equ 40h; GetThreadPreferredUILanguages merges in user preferred languages

        MUI_CONSOLE_FILTER equ 100h; SetThreadPreferredUILanguages takes on console specific behavior

        MUI_COMPLEX_SCRIPT_FILTER equ 200h; SetThreadPreferredUILanguages takes on complex script specific behavior

        MUI_RESET_FILTERS equ 001h; Reset MUI_CONSOLE_FILTER and MUI_COMPLEX_SCRIPT_FILTER

        MUI_USER_PREFERRED_UI_LANGUAGES equ 10h; GetFileMUIPath returns the MUI files for the languages in the fallback list

        MUI_USE_INSTALLED_LANGUAGES equ 20h; GetFileMUIPath returns all the MUI files installed in the machine

        MUI_USE_SEARCH_ALL_LANGUAGES equ 40h; GetFileMUIPath returns all the MUI files irrespective of whether language is installed

        MUI_LANG_NEUTRAL_PE_FILE equ 100h; GetFileMUIPath returns target file with .mui extension

        MUI_NON_LANG_NEUTRAL_FILE equ 200h; GetFileMUIPath returns target file with same name as source

        MUI_MACHINE_LANGUAGE_SETTINGS equ 400h
        MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL equ 001h; GetFileMUIInfo found a non-split resource file

        MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN equ 002h; GetFileMUIInfo found a LN main module resource file

        MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI equ 004h; GetFileMUIInfo found a LN MUI module resource file

        MUI_QUERY_TYPE equ 001h; GetFileMUIInfo will look for the type of the resource file

        MUI_QUERY_CHECKSUM equ 002h; GetFileMUIInfo will look for the checksum of the resource file

        MUI_QUERY_LANGUAGE_NAME equ 004h; GetFileMUIInfo will look for the culture of the resource file

        MUI_QUERY_RESOURCE_TYPES equ 008h; GetFileMUIInfo will look for the resource types of the resource file

        MUI_FILEINFO_VERSION equ 001h; Version of FILEMUIINFO structure used with GetFileMUIInfo

        MUI_FULL_LANGUAGE equ 01h
        MUI_PARTIAL_LANGUAGE equ 02h
        MUI_LIP_LANGUAGE equ 04h
        MUI_LANGUAGE_INSTALLED equ 20h
        MUI_LANGUAGE_LICENSED equ 40h
        ; MUI_CALLBACK_FLAG defines are duplicated in rtlmui.h
        MUI_CALLBACK_ALL_FLAGS equ <MUI_CALLBACK_FLAG_UPGRADED_INSTALLATION>; OR all other flags when defined.

        ; MUI_CALLBACK_ flags are duplicated in rtlmui.h
      endif
      ;//////////////////////////////////////////////////////////////////////////
      ;  Typedefs
      ;  Define all types for the NLS component here.
      ;//////////////////////////////////////////////////////////////////////////
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      ;  Language Group ID 
      ; The "Language Group" concept is an obsolete concept.
      ; The groups returned are not well defined, arbitrary, inconsistent, inaccurate,
      ; no longer maintained, and no longer supported.
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      LGRPID typedef DWORD
      ;  Locale type constant.
      LCTYPE typedef DWORD
      ;  Calendar type constant.
      CALTYPE typedef DWORD
      ;  Calendar ID.
      CALID typedef DWORD
      ;  CP Info.
      ; Deprecated.  Applications should use Unicode (WCHAR / UTF-16 or UTF-8)
      ; WARNING: These structures fail for some encodings, including UTF-8, which
      ;          do not fit into the assumptions of these APIs.
      CPINFO struct
        MaxCharSize DWORD ?
        ; max length (in bytes) of a char
        DefaultChar BYTE MAX_DEFAULTCHAR dup (?)
        ; default character
        LeadByte BYTE MAX_LEADBYTES dup (?)
        ; lead byte ranges
      CPINFO ends
      _cpinfo typedef CPINFO
      LPCPINFO typedef ptr CPINFO
      ;  GEO defines
      GEOTYPE typedef DWORD
      GEOCLASS typedef DWORD
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      ;  DEPRECATED: The GEOID  concept is deprecated, please use
      ;  Country/Region Names instead, eg: "US" instead of a GEOID like 244.
      ;  See the documentation for GetGeoInfoEx.
      ;  WARNING: These values are arbitrarily assigned values, please use
      ;           standard country/region names instead, such as "US".
      ; ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED ** DEPRECATED **
      GEOID typedef LONG
      GEOID_NOT_AVAILABLE equ -1
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CPINFOEXA struct
        MaxCharSize DWORD ?
        ; max length (in bytes) of a char
        DefaultChar BYTE MAX_DEFAULTCHAR dup (?)
        ; default character (MB)
        LeadByte BYTE MAX_LEADBYTES dup (?)
        ; lead byte ranges
        UnicodeDefaultChar WORD ?
        ; default character (Unicode)
        CodePage DWORD ?
        ; code page id
        CodePageName SBYTE MAX_PATH dup (?)
        ; code page name (Unicode)
      CPINFOEXA ends
      _cpinfoexA typedef CPINFOEXA
      LPCPINFOEXA typedef ptr CPINFOEXA
      CPINFOEXW struct
        MaxCharSize DWORD ?
        ; max length (in bytes) of a char
        DefaultChar BYTE MAX_DEFAULTCHAR dup (?)
        ; default character (MB)
        LeadByte BYTE MAX_LEADBYTES dup (?)
        ; lead byte ranges
        UnicodeDefaultChar WORD ?
        ; default character (Unicode)
        CodePage DWORD ?
        ; code page id
        CodePageName WORD MAX_PATH dup (?)
        ; code page name (Unicode)
      CPINFOEXW ends
      _cpinfoexW typedef CPINFOEXW
      LPCPINFOEXW typedef ptr CPINFOEXW
      ifdef UNICODE
        CPINFOEX typedef CPINFOEXW
        LPCPINFOEX typedef LPCPINFOEXW
      else
        CPINFOEX typedef CPINFOEXA
        LPCPINFOEX typedef LPCPINFOEXA
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;  Number format.
      NUMBERFMTA struct
        NumDigits DWORD ?
        ; number of decimal digits
        LeadingZero DWORD ?
        ; if leading zero in decimal fields
        Grouping DWORD ?
        ; group size left of decimal
        lpDecimalSep POINTER ?
        ; ptr to decimal separator string
        lpThousandSep POINTER ?
        ; ptr to thousand separator string
        NegativeOrder DWORD ?
        ; negative number ordering
      NUMBERFMTA ends
      _numberfmtA typedef NUMBERFMTA
      LPNUMBERFMTA typedef ptr NUMBERFMTA
      NUMBERFMTW struct
        NumDigits DWORD ?
        ; number of decimal digits
        LeadingZero DWORD ?
        ; if leading zero in decimal fields
        Grouping DWORD ?
        ; group size left of decimal
        lpDecimalSep POINTER ?
        ; ptr to decimal separator string
        lpThousandSep POINTER ?
        ; ptr to thousand separator string
        NegativeOrder DWORD ?
        ; negative number ordering
      NUMBERFMTW ends
      _numberfmtW typedef NUMBERFMTW
      LPNUMBERFMTW typedef ptr NUMBERFMTW
      ifdef UNICODE
        NUMBERFMT typedef NUMBERFMTW
        LPNUMBERFMT typedef LPNUMBERFMTW
      else
        NUMBERFMT typedef NUMBERFMTA
        LPNUMBERFMT typedef LPNUMBERFMTA
      endif
      ; UNICODE
      ;  Currency format.
      CURRENCYFMTA struct
        NumDigits DWORD ?
        ; number of decimal digits
        LeadingZero DWORD ?
        ; if leading zero in decimal fields
        Grouping DWORD ?
        ; group size left of decimal
        lpDecimalSep POINTER ?
        ; ptr to decimal separator string
        lpThousandSep POINTER ?
        ; ptr to thousand separator string
        NegativeOrder DWORD ?
        ; negative currency ordering
        PositiveOrder DWORD ?
        ; positive currency ordering
        lpCurrencySymbol POINTER ?
        ; ptr to currency symbol string
      CURRENCYFMTA ends
      _currencyfmtA typedef CURRENCYFMTA
      LPCURRENCYFMTA typedef ptr CURRENCYFMTA
      CURRENCYFMTW struct
        NumDigits DWORD ?
        ; number of decimal digits
        LeadingZero DWORD ?
        ; if leading zero in decimal fields
        Grouping DWORD ?
        ; group size left of decimal
        lpDecimalSep POINTER ?
        ; ptr to decimal separator string
        lpThousandSep POINTER ?
        ; ptr to thousand separator string
        NegativeOrder DWORD ?
        ; negative currency ordering
        PositiveOrder DWORD ?
        ; positive currency ordering
        lpCurrencySymbol POINTER ?
        ; ptr to currency symbol string
      CURRENCYFMTW ends
      _currencyfmtW typedef CURRENCYFMTW
      LPCURRENCYFMTW typedef ptr CURRENCYFMTW
      ifdef UNICODE
        CURRENCYFMT typedef CURRENCYFMTW
        LPCURRENCYFMT typedef LPCURRENCYFMTW
      else
        CURRENCYFMT typedef CURRENCYFMTA
        LPCURRENCYFMT typedef LPCURRENCYFMTA
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ;  NLS function capabilities
      SYSNLS_FUNCTION typedef SDWORD
      COMPARE_STRING equ 0001h
      ; Collation version for NLS

      NLS_FUNCTION typedef DWORD
      ;  NLS version structure.
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge _WIN32_WINNT_WIN8)
        ; New structures are the same
        ; The combination of dwNLSVersion, and guidCustomVersion
        ; identify specific sort behavior, persist those to ensure identical
        ; behavior in the future.
        NLSVERSIONINFO struct
          dwNLSVersionInfoSize DWORD ?
          ; sizeof(NLSVERSIONINFO) == 32 bytes
          dwNLSVersion DWORD ?
          dwDefinedVersion DWORD ?
          ; Deprecated, use dwNLSVersion instead
          dwEffectiveId DWORD ?
          ; Deprecated, use guidCustomVerison instead
          guidCustomVersion GUID <>
          ; Explicit sort version
        NLSVERSIONINFO ends
        _nlsversioninfo typedef NLSVERSIONINFO
        LPNLSVERSIONINFO typedef ptr NLSVERSIONINFO
      else
        ; 
        ; Windows 7 and below had different sizes
        ; This is to be deprecated, please use the NLSVERSIONINFOEX
        ; structure below in the future.  The difference is that
        ; guidCustomversion is required to uniquely identify a sort
        NLSVERSIONINFO struct
          ; Use NLSVERSIONINFOEX instead
          dwNLSVersionInfoSize DWORD ?
          ; 12 bytes
          dwNLSVersion DWORD ?
          dwDefinedVersion DWORD ?
          ; Deprecated, use dwNLSVersion instead
        NLSVERSIONINFO ends
        _nlsversioninfo typedef NLSVERSIONINFO
        LPNLSVERSIONINFO typedef ptr NLSVERSIONINFO
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; The combination of dwNLSVersion, and guidCustomVersion
      ; identify specific sort behavior, persist those to ensure identical
      ; behavior in the future.
      NLSVERSIONINFOEX struct
        dwNLSVersionInfoSize DWORD ?
        ; sizeof(NLSVERSIONINFOEX) == 32 bytes
        dwNLSVersion DWORD ?
        dwDefinedVersion DWORD ?
        ; Deprecated, use dwNLSVersion instead
        dwEffectiveId DWORD ?
        ; Deprecated, use guidCustomVerison instead
        guidCustomVersion GUID <>
        ; Explicit sort version
      NLSVERSIONINFOEX ends
      _nlsversioninfoex typedef NLSVERSIONINFOEX
      LPNLSVERSIONINFOEX typedef ptr NLSVERSIONINFOEX
      if (NTDDI_VERSION ge NTDDI_WIN10_MN)
        SORTING_PARADIGM_NLS equ 00000000h; NLS style sorting

        SORTING_PARADIGM_ICU equ 01000000h; ICU style sorting

      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        GEO_NAME_USER_DEFAULT equ <NULL>
      endif
      ;  GEO information types for clients to query
      ; Please use GetGeoInfoEx and query by country/region name instead of GEOID (eg: "US" instead of 244)
      SYSGEOTYPE typedef SDWORD
      GEO_NATION equ 0001h
      ; DEPRECATED Not used by name API
      GEO_LATITUDE equ 0002h
      GEO_LONGITUDE equ 0003h
      GEO_ISO2 equ 0004h
      GEO_ISO3 equ 0005h
      GEO_RFC1766 equ 0006h
      ; DEPRECATED and misleading, not used by name API
      GEO_LCID equ 0007h
      ; DEPRECATED Not used by name API
      GEO_FRIENDLYNAME equ 0008h
      GEO_OFFICIALNAME equ 0009h
      GEO_TIMEZONES equ 000Ah
      ; Not implemented
      GEO_OFFICIALLANGUAGES equ 000Bh
      ; Not implemented
      GEO_ISO_UN_NUMBER equ 000Ch
      GEO_PARENT equ 000Dh
      GEO_DIALINGCODE equ 000Eh
      GEO_CURRENCYCODE equ 000Fh
      ; eg: USD
      GEO_CURRENCYSYMBOL equ 0010h
      ; eg: $
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        GEO_NAME equ 0011h
        ; Name, eg: US or 001
        GEO_ID equ 0012h ; DEPRECATED - For compatibility, please avoid
      endif


      ;  More GEOCLASS defines will be listed here
      SYSGEOCLASS typedef SDWORD
      GEOCLASS_NATION equ 16
      GEOCLASS_REGION equ 14
      ; DEPRECATED - Never used
      GEOCLASS_ALL equ 0

      ifdef STRICT
        TYPE_LOCALE_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR
        LOCALE_ENUMPROCA typedef ptr TYPE_LOCALE_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_LOCALE_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR
        LOCALE_ENUMPROCW typedef ptr TYPE_LOCALE_ENUMPROCW

        ; DEPRECATED: please use LOCALE_ENUMPROCEX
      endif
      ; STRICT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (WINVER ge 0600h)
        ;  Normalization forms
        NORM_FORM typedef SDWORD
        NormalizationOther equ 0
        ; Not supported
        NormalizationC equ 1h
        ; Each base plus combining characters to the canonical precomposed equivalent.
        NormalizationD equ 2h
        ; Each precomposed character to its canonical decomposed equivalent.
        NormalizationKC equ 5h
        ; Each base plus combining characters to the canonical precomposed
        ;   equivalents and all compatibility characters to their equivalents.
        NormalizationKD equ 6h
        _NORM_FORM typedef NORM_FORM

        ;   and all compatibility characters to their equivalents.
        ; IDN (International Domain Name) Flags
        IDN_ALLOW_UNASSIGNED equ 01h; Allow unassigned "query" behavior per RFC 3454

        IDN_USE_STD3_ASCII_RULES equ 02h; Enforce STD3 ASCII restrictions for legal characters

        IDN_EMAIL_ADDRESS equ 04h; Enable EAI algorithmic fallback for email local parts behavior

        IDN_RAW_PUNYCODE equ 08h; Disable validation and mapping of punycode.   

        VS_ALLOW_LATIN equ 0001h; Allow Latin in test script even if not present in locale script

        GSS_ALLOW_INHERITED_COMMON equ 0001h; Output script ids for inherited and common character types if present

      endif
      ;(WINVER >= 0x0600)
      ;  Enumeration function constants.
      ifdef STRICT
        TYPE_LANGUAGEGROUP_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LGRPID, :LPSTR, :LPSTR, :DWORD, :LONG_PTR
        LANGUAGEGROUP_ENUMPROCA typedef ptr TYPE_LANGUAGEGROUP_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_LANGGROUPLOCALE_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LGRPID, :LCID, :LPSTR, :LONG_PTR
        LANGGROUPLOCALE_ENUMPROCA typedef ptr TYPE_LANGGROUPLOCALE_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_UILANGUAGE_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR, :LONG_PTR
        UILANGUAGE_ENUMPROCA typedef ptr TYPE_UILANGUAGE_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_CODEPAGE_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR
        CODEPAGE_ENUMPROCA typedef ptr TYPE_CODEPAGE_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_DATEFMT_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR
        DATEFMT_ENUMPROCA typedef ptr TYPE_DATEFMT_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_DATEFMT_ENUMPROCEXA typedef proto WIN_STD_CALL_CONV :LPSTR, :CALID
        DATEFMT_ENUMPROCEXA typedef ptr TYPE_DATEFMT_ENUMPROCEXA

        ; Deprecated, please use Unicode
        TYPE_TIMEFMT_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR
        TIMEFMT_ENUMPROCA typedef ptr TYPE_TIMEFMT_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_CALINFO_ENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR
        CALINFO_ENUMPROCA typedef ptr TYPE_CALINFO_ENUMPROCA

        ; Deprecated, please use Unicode
        TYPE_CALINFO_ENUMPROCEXA typedef proto WIN_STD_CALL_CONV :LPSTR, :CALID
        CALINFO_ENUMPROCEXA typedef ptr TYPE_CALINFO_ENUMPROCEXA

        ; Deprecated, please use Unicode
        TYPE_LANGUAGEGROUP_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LGRPID, :LPWSTR, :LPWSTR, :DWORD, :LONG_PTR
        LANGUAGEGROUP_ENUMPROCW typedef ptr TYPE_LANGUAGEGROUP_ENUMPROCW

        ; DEPRECATED: Language groups are no longer supported
        TYPE_LANGGROUPLOCALE_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LGRPID, :LCID, :LPWSTR, :LONG_PTR
        LANGGROUPLOCALE_ENUMPROCW typedef ptr TYPE_LANGGROUPLOCALE_ENUMPROCW

        ; DEPRECATED: Language groups are no longer supported
        TYPE_UILANGUAGE_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR, :LONG_PTR
        UILANGUAGE_ENUMPROCW typedef ptr TYPE_UILANGUAGE_ENUMPROCW

        TYPE_CODEPAGE_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR
        CODEPAGE_ENUMPROCW typedef ptr TYPE_CODEPAGE_ENUMPROCW

        ; Please use Unicode / UTF-8
        TYPE_DATEFMT_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR
        DATEFMT_ENUMPROCW typedef ptr TYPE_DATEFMT_ENUMPROCW

        TYPE_DATEFMT_ENUMPROCEXW typedef proto WIN_STD_CALL_CONV :LPWSTR, :CALID
        DATEFMT_ENUMPROCEXW typedef ptr TYPE_DATEFMT_ENUMPROCEXW

        TYPE_TIMEFMT_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR
        TIMEFMT_ENUMPROCW typedef ptr TYPE_TIMEFMT_ENUMPROCW

        TYPE_CALINFO_ENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR
        CALINFO_ENUMPROCW typedef ptr TYPE_CALINFO_ENUMPROCW

        TYPE_CALINFO_ENUMPROCEXW typedef proto WIN_STD_CALL_CONV :LPWSTR, :CALID
        CALINFO_ENUMPROCEXW typedef ptr TYPE_CALINFO_ENUMPROCEXW

        TYPE_GEO_ENUMPROC typedef proto WIN_STD_CALL_CONV :GEOID
        GEO_ENUMPROC typedef ptr TYPE_GEO_ENUMPROC

        ; DEPRECATED, use GEO_ENUMNAMEPROC instead
        if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
          TYPE_GEO_ENUMNAMEPROC typedef proto WIN_STD_CALL_CONV :PWSTR, :LPARAM
          GEO_ENUMNAMEPROC typedef ptr TYPE_GEO_ENUMNAMEPROC

        endif
      else
      ; !STRICT
        LANGUAGEGROUP_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        LANGGROUPLOCALE_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        UILANGUAGE_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        CODEPAGE_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        DATEFMT_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        DATEFMT_ENUMPROCEXA typedef FARPROC
        ; Deprecated, please use Unicode
        TIMEFMT_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        CALINFO_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        CALINFO_ENUMPROCEXA typedef FARPROC
        ; Deprecated, please use Unicode
        GEO_ENUMPROC typedef FARPROC
        ; DEPRECATED, use GEO_ENUMNAMEPROC instead
      endif
      ; !STRICT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ifndef STRICT
        LOCALE_ENUMPROCA typedef FARPROC
        ; Deprecated, please use Unicode
        LOCALE_ENUMPROCW typedef FARPROC
        ; DEPRECATED: please use LOCALE_ENUMPROCEX
      endif
      ; !STRICT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ifndef STRICT
        LANGUAGEGROUP_ENUMPROCW typedef FARPROC
        ; DEPRECATED: Language groups are no longer supported
        LANGGROUPLOCALE_ENUMPROCW typedef FARPROC
        ; DEPRECATED: Language groups are no longer supported
        UILANGUAGE_ENUMPROCW typedef FARPROC
        CODEPAGE_ENUMPROCW typedef FARPROC
        ; Please use Unicode / UTF-8
        DATEFMT_ENUMPROCW typedef FARPROC
        DATEFMT_ENUMPROCEXW typedef FARPROC
        TIMEFMT_ENUMPROCW typedef FARPROC
        CALINFO_ENUMPROCW typedef FARPROC
        CALINFO_ENUMPROCEXW typedef FARPROC
        if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
          GEO_ENUMNAMEPROC typedef FARPROC
        endif
      endif
      ; !STRICT
      ifdef UNICODE
        ; DEPRECATED("The Language Group concept is obsolete and no longer supported. Set DISABLE_NLS_DEPRECATION to disable this warning.")
        LANGUAGEGROUP_ENUMPROC equ <LANGUAGEGROUP_ENUMPROCW>
        ; DEPRECATED("The Language Group concept is obsolete and no longer supported. Set DISABLE_NLS_DEPRECATION to disable this warning.")
        LANGGROUPLOCALE_ENUMPROC equ <LANGGROUPLOCALE_ENUMPROCW>
        UILANGUAGE_ENUMPROC equ <UILANGUAGE_ENUMPROCW>
        CODEPAGE_ENUMPROC equ <CODEPAGE_ENUMPROCW>
        DATEFMT_ENUMPROC equ <DATEFMT_ENUMPROCW>
        DATEFMT_ENUMPROCEX equ <DATEFMT_ENUMPROCEXW>
        TIMEFMT_ENUMPROC equ <TIMEFMT_ENUMPROCW>
        CALINFO_ENUMPROC equ <CALINFO_ENUMPROCW>
        CALINFO_ENUMPROCEX equ <CALINFO_ENUMPROCEXW>
        LOCALE_ENUMPROC equ <LOCALE_ENUMPROCW>
      else
        ; DEPRECATED("The Language Group concept is obsolete and no longer supported. Set DISABLE_NLS_DEPRECATION to disable this warning.")
        LANGUAGEGROUP_ENUMPROC equ <LANGUAGEGROUP_ENUMPROCA>
        ; DEPRECATED("The Language Group concept is obsolete and no longer supported. Set DISABLE_NLS_DEPRECATION to disable this warning.")
        LANGGROUPLOCALE_ENUMPROC equ <LANGGROUPLOCALE_ENUMPROCA>
        UILANGUAGE_ENUMPROC equ <UILANGUAGE_ENUMPROCA>
        CODEPAGE_ENUMPROC equ <CODEPAGE_ENUMPROCA>
        DATEFMT_ENUMPROC equ <DATEFMT_ENUMPROCA>
        DATEFMT_ENUMPROCEX equ <DATEFMT_ENUMPROCEXA>
        TIMEFMT_ENUMPROC equ <TIMEFMT_ENUMPROCA>
        CALINFO_ENUMPROC equ <CALINFO_ENUMPROCA>
        CALINFO_ENUMPROCEX equ <CALINFO_ENUMPROCEXA>
        LOCALE_ENUMPROC equ <LOCALE_ENUMPROCA>
      endif
      ; !UNICODE
      ; Information about a MUI file, used as input/output in GetFileMUIInfo
      ; All offsets are relative to start of the structure. Offsets with value 0 mean empty field.
      FILEMUIINFO struct
        dwSize DWORD ?
        ; Size of the structure including buffer size [in]
        dwVersion DWORD ?
        ; Version of the structure [in]
        dwFileType DWORD ?
        ; Type of the file [out]
        pChecksum BYTE 16 dup (?)
        ; Checksum of the file [out]
        pServiceChecksum BYTE 16 dup (?)
        ; Checksum of the file [out]
        dwLanguageNameOffset DWORD ?
        ; Language name of the file [out]
        dwTypeIDMainSize DWORD ?
        ; Number of TypeIDs in main module [out]
        dwTypeIDMainOffset DWORD ?
        ; Array of TypeIDs (DWORD) in main module [out]
        dwTypeNameMainOffset DWORD ?
        ; Multistring array of TypeNames in main module [out]
        dwTypeIDMUISize DWORD ?
        ; Number of TypeIDs in MUI module [out]
        dwTypeIDMUIOffset DWORD ?
        ; Array of TypeIDs (DWORD) in MUI module [out]
        dwTypeNameMUIOffset DWORD ?
        ; Multistring array of TypeNames in MUI module [out]
        abBuffer BYTE 8 dup (?)
        ; Buffer for extra data [in] (Size 4 is for padding)
      FILEMUIINFO ends
      _FILEMUIINFO typedef FILEMUIINFO
      PFILEMUIINFO typedef ptr FILEMUIINFO
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ifndef NOAPISET
        include stringapiset.inc
        ; String APISET dependencies
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ;//////////////////////////////////////////////////////////////////////////
      ;  Macros
      ;  Define all macros for the NLS component here.
      ;//////////////////////////////////////////////////////////////////////////
      ;  Macros to determine whether a character is a high or low surrogate,
      ;  and whether two code points make up a surrogate pair (a high surrogate
      ;  and a low surrogate).
      IS_HIGH_SURROGATE macro wch
        exitm <(((wch) >= HIGH_SURROGATE_START) and ((wch) <= HIGH_SURROGATE_END))>
      endm
      IS_LOW_SURROGATE macro wch
        exitm <(((wch) >= LOW_SURROGATE_START) and ((wch) <= LOW_SURROGATE_END))>
      endm
      IS_SURROGATE_PAIR macro hs, ls
        exitm <(IS_HIGH_SURROGATE(hs) and IS_LOW_SURROGATE(ls))>
      endm
      ; ----------------------------------------------------------------------
      ; The following macros retrieve information from a MUIFILEINFO structure
      ; Gets the culture name (LPWSTR), NULL if not initialized
      FILEMUIINFO_GET_CULTURE macro pInfo
        exitm <(((pInfo - dwLanguageNameOffset > 0) ? (ULONG_PTR) pInfo + pInfo - dwLanguageNameOffset : NULL))>
      endm
      ; Gets the main module types array (DWORD[]), NULL if not initialized
      FILEMUIINFO_GET_MAIN_TYPEIDS macro pInfo
        exitm <(((pInfo - dwTypeIDMainOffset > 0) ? (ULONG_PTR) pInfo + pInfo - dwTypeIDMainOffset : NULL))>
      endm
      ; Gets the main module type array element iType (DWORD), the array is not initialized or index is out of bounds
      FILEMUIINFO_GET_MAIN_TYPEID macro pInfo, iType
        exitm <(((iType < pInfo - dwTypeIDMainSize) and (pInfo - dwTypeIDMainOffset > 0)) ? * ((pInfo + pInfo - dwTypeIDMainOffset) + iType) : 0)>
      endm
      ; Gets the main module names multistring array (LPWSTR), NULL if not initialized
      FILEMUIINFO_GET_MAIN_TYPENAMES macro pInfo
        exitm <(((pInfo - dwTypeNameMainOffset > 0) ? (ULONG_PTR) pInfo + pInfo - dwTypeNameMainOffset : NULL))>
      endm
      ; Gets the mui module types array (DWORD[]), NULL if not initialized
      FILEMUIINFO_GET_MUI_TYPEIDS macro pInfo
        exitm <(((pInfo - dwTypeIDMUIOffset > 0) ? (ULONG_PTR) pInfo + pInfo - dwTypeIDMUIOffset : NULL))>
      endm
      ; Gets the mui module type array element iType (DWORD), the array is not initialized or index is out of bounds
      FILEMUIINFO_GET_MUI_TYPEID macro pInfo, iType
        exitm <(((iType < pInfo - dwTypeIDMUISize) and (pInfo - dwTypeIDMUIOffset > 0)) ? * ((pInfo + pInfo - dwTypeIDMUIOffset) + iType) : 0)>
      endm
      ; Gets the mui module names multistring array (LPWSTR), NULL if not initialized
      FILEMUIINFO_GET_MUI_TYPENAMES macro pInfo
        exitm <(((pInfo - dwTypeNameMUIOffset > 0) ? (ULONG_PTR) pInfo + pInfo - dwTypeNameMUIOffset : NULL))>
      endm
      ; ------------------------------------------------------------------------
      ;//////////////////////////////////////////////////////////////////////////
      ;  Function Prototypes
      ;  Only prototypes for the NLS APIs should go here.
      ;//////////////////////////////////////////////////////////////////////////
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;  Code Page Dependent APIs.
      ;  Applications should use Unicode (WCHAR / UTF-16 &/or UTF-8)
      @DefProto DllImport, IsValidCodePage, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, GetACP, WIN_STD_CALL_CONV,, <>, 0
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, GetOEMCP, WIN_STD_CALL_CONV,, <>, 0
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetCPInfo, WIN_STD_CALL_CONV,, <:UINT, :LPCPINFO>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP |WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetCPInfoExA, WIN_STD_CALL_CONV,, <:UINT, :DWORD, :LPCPINFOEXA>, 12
      @DefProto DllImport, GetCPInfoExW, WIN_STD_CALL_CONV,, <:UINT, :DWORD, :LPCPINFOEXW>, 12
      ifdef UNICODE
        GetCPInfoEx equ <GetCPInfoExW>
      else
        GetCPInfoEx equ <GetCPInfoExA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP |WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    ;  Locale Dependent APIs.
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CompareStringA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :PCNZCH, :SDWORD, :PCNZCH, :SDWORD>, 24
      ifndef UNICODE
        CompareString equ <CompareStringA>
      endif
      ; !UNICODE
      if Defined(_M_CEE)
        ;[...]
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0600h)
        ; DEPRECATED: FindNLSStringEx is preferred
        @DefProto DllImport, FindNLSString, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCWSTR, :SDWORD, :LPCWSTR, :SDWORD, :LPINT>, 28
      endif
      ;(WINVER >= 0x0600)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; DEPRECATED: LCMapStringEx is preferred
      @DefProto DllImport, LCMapStringW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD>, 24
      ifdef UNICODE
        LCMapString equ <LCMapStringW>
      endif
      ; DEPRECATED: Use Unicode, LCMapStringEx is preferred
      @DefProto DllImport, LCMapStringA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCSTR, :SDWORD, :LPSTR, :SDWORD>, 24
      ifndef UNICODE
        LCMapString equ <LCMapStringA>
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; DEPRECATED: GetLocaleInfoEx is preferred
      @DefProto DllImport, GetLocaleInfoW, WIN_STD_CALL_CONV,, <:LCID, :LCTYPE, :LPWSTR, :SDWORD>, 16
      ifdef UNICODE
        GetLocaleInfo equ <GetLocaleInfoW>
      endif
      ; DEPRECATED: Use Unicode. GetLocaleInfoEx is preferred
      @DefProto DllImport, GetLocaleInfoA, WIN_STD_CALL_CONV,, <:LCID, :LCTYPE, :LPSTR, :SDWORD>, 16
      ifndef UNICODE
        GetLocaleInfo equ <GetLocaleInfoA>
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, SetLocaleInfoA, WIN_STD_CALL_CONV,, <:LCID, :LCTYPE, :LPCSTR>, 12
      @DefProto DllImport, SetLocaleInfoW, WIN_STD_CALL_CONV,, <:LCID, :LCTYPE, :LPCWSTR>, 12
      ifdef UNICODE
        SetLocaleInfo equ <SetLocaleInfoW>
      else
        SetLocaleInfo equ <SetLocaleInfoA>
      endif
      ; !UNICODE
      if (WINVER ge 040Ah)
        ; DEPRECATED: GetCalendarInfoEx is preferred
        @DefProto DllImport, GetCalendarInfoA, WIN_STD_CALL_CONV,, <:LCID, :CALID, :CALTYPE, :LPSTR, :SDWORD, :LPDWORD>, 24
        ; DEPRECATED: GetCalendarInfoEx is preferred
        @DefProto DllImport, GetCalendarInfoW, WIN_STD_CALL_CONV,, <:LCID, :CALID, :CALTYPE, :LPWSTR, :SDWORD, :LPDWORD>, 24
        ifdef UNICODE
          GetCalendarInfo equ <GetCalendarInfoW>
        else
          GetCalendarInfo equ <GetCalendarInfoA>
        endif
        ; !UNICODE
        @DefProto DllImport, SetCalendarInfoA, WIN_STD_CALL_CONV,, <:LCID, :CALID, :CALTYPE, :LPCSTR>, 16
        @DefProto DllImport, SetCalendarInfoW, WIN_STD_CALL_CONV,, <:LCID, :CALID, :CALTYPE, :LPCWSTR>, 16
        ifdef UNICODE
          SetCalendarInfo equ <SetCalendarInfoW>
        else
          SetCalendarInfo equ <SetCalendarInfoA>
        endif
        ; !UNICODE
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge _WIN32_WINNT_WIN7)
        ;                                        
        ; Flags used by LoadStringByReference    
        ;                                        
        MUI_FORMAT_REG_COMPAT equ 0001h
        MUI_FORMAT_INF_COMPAT equ 0002h
        MUI_VERIFY_FILE_EXISTS equ 0004h
        MUI_SKIP_STRING_CACHE equ 0008h
        MUI_IMMUTABLE_LOOKUP equ 0010h
        @DefProto DllImport, LoadStringByReference, WIN_STD_CALL_CONV,, <:DWORD, :PCWSTR, :PCWSTR, :PWSTR, :ULONG, :PCWSTR, :PULONG>, 28
      endif
      ; (WINVER >= _WIN32_WINNT_WIN7)	    
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, IsDBCSLeadByte, WIN_STD_CALL_CONV,, <:BYTE>, 4
      @DefProto DllImport, IsDBCSLeadByteEx, WIN_STD_CALL_CONV,, <:UINT, :BYTE>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0600h)
        ; Use of Locale Names is preferred, LCIDs are deprecated.
        ; This function is provided to enable compatibility with legacy data sets only.
        @DefProto DllImport, LocaleNameToLCID, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
        ; Use of Locale Names is preferred, LCIDs are deprecated.
        ; This function is provided to enable compatibility with legacy data sets only.
        @DefProto DllImport, LCIDToLocaleName, WIN_STD_CALL_CONV,, <:LCID, :LPWSTR, :SDWORD, :DWORD>, 16
      endif
      ; (WINVER >= 0x0600)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ; DEPRECATED: GetDurationFormatEx is preferred
      if (WINVER ge 0600h)
        @DefProto DllImport, GetDurationFormat, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :ptr SYSTEMTIME, :ULONGLONG, :LPCWSTR, :LPWSTR, :SDWORD>, 28
      endif
      ;(WINVER >= 0x0600)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; DEPRECATED: GetNumberFormatEx is preferred
      @DefProto DllImport, GetNumberFormatA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCSTR, :ptr NUMBERFMTA, :LPSTR, :SDWORD>, 24
      ; DEPRECATED: GetNumberFormatEx is preferred
      @DefProto DllImport, GetNumberFormatW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCWSTR, :ptr NUMBERFMTW, :LPWSTR, :SDWORD>, 24
      ifdef UNICODE
        GetNumberFormat equ <GetNumberFormatW>
      else
        GetNumberFormat equ <GetNumberFormatA>
      endif
      ; !UNICODE
      ; DEPRECATED: GetCurrencyFormatEx is preferred
      @DefProto DllImport, GetCurrencyFormatA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCSTR, :ptr CURRENCYFMTA, :LPSTR, :SDWORD>, 24
      ; DEPRECATED: GetCurrencyFormatEx is preferred
      @DefProto DllImport, GetCurrencyFormatW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCWSTR, :ptr CURRENCYFMTW, :LPWSTR, :SDWORD>, 24
      ifdef UNICODE
        GetCurrencyFormat equ <GetCurrencyFormatW>
      else
        GetCurrencyFormat equ <GetCurrencyFormatA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ; DEPRECATED: EnumCalendarInfoExEx is preferred
      @DefProto DllImport, EnumCalendarInfoA, WIN_STD_CALL_CONV,, <:CALINFO_ENUMPROCA, :LCID, :CALID, :CALTYPE>, 16
      ; DEPRECATED: EnumCalendarInfoExEx is preferred
      @DefProto DllImport, EnumCalendarInfoW, WIN_STD_CALL_CONV,, <:CALINFO_ENUMPROCW, :LCID, :CALID, :CALTYPE>, 16
      ifdef UNICODE
        EnumCalendarInfo equ <EnumCalendarInfoW>
      else
        EnumCalendarInfo equ <EnumCalendarInfoA>
      endif
      ; !UNICODE
      if (WINVER ge 0500h)
        ; DEPRECATED: EnumCalendarInfoExEx is preferred
        @DefProto DllImport, EnumCalendarInfoExA, WIN_STD_CALL_CONV,, <:CALINFO_ENUMPROCEXA, :LCID, :CALID, :CALTYPE>, 16
        ; DEPRECATED: EnumCalendarInfoExEx is preferred
        @DefProto DllImport, EnumCalendarInfoExW, WIN_STD_CALL_CONV,, <:CALINFO_ENUMPROCEXW, :LCID, :CALID, :CALTYPE>, 16
        ifdef UNICODE
          EnumCalendarInfoEx equ <EnumCalendarInfoExW>
        else
          EnumCalendarInfoEx equ <EnumCalendarInfoExA>
        endif
        ; !UNICODE
        ;* WINVER >= 0x0500 *
      endif
      ; DEPRECATED: EnumTimeFormatsEx is preferred
      @DefProto DllImport, EnumTimeFormatsA, WIN_STD_CALL_CONV,, <:TIMEFMT_ENUMPROCA, :LCID, :DWORD>, 12
      ; DEPRECATED: EnumTimeFormatsEx is preferred
      @DefProto DllImport, EnumTimeFormatsW, WIN_STD_CALL_CONV,, <:TIMEFMT_ENUMPROCW, :LCID, :DWORD>, 12
      ifdef UNICODE
        EnumTimeFormats equ <EnumTimeFormatsW>
      else
        EnumTimeFormats equ <EnumTimeFormatsA>
      endif
      ; !UNICODE
      ; DEPRECATED: EnumDateFormatsExEx is preferred
      @DefProto DllImport, EnumDateFormatsA, WIN_STD_CALL_CONV,, <:DATEFMT_ENUMPROCA, :LCID, :DWORD>, 12
      ; DEPRECATED: EnumDateFormatsExEx is preferred
      @DefProto DllImport, EnumDateFormatsW, WIN_STD_CALL_CONV,, <:DATEFMT_ENUMPROCW, :LCID, :DWORD>, 12
      ifdef UNICODE
        EnumDateFormats equ <EnumDateFormatsW>
      else
        EnumDateFormats equ <EnumDateFormatsA>
      endif
      ; !UNICODE
      if (WINVER ge 0500h)
        ; DEPRECATED: EnumDateFormatsExEx is preferred
        @DefProto DllImport, EnumDateFormatsExA, WIN_STD_CALL_CONV,, <:DATEFMT_ENUMPROCEXA, :LCID, :DWORD>, 12
        ; DEPRECATED: EnumDateFormatsExEx is preferred
        @DefProto DllImport, EnumDateFormatsExW, WIN_STD_CALL_CONV,, <:DATEFMT_ENUMPROCEXW, :LCID, :DWORD>, 12
        ifdef UNICODE
          EnumDateFormatsEx equ <EnumDateFormatsExW>
        else
          EnumDateFormatsEx equ <EnumDateFormatsExA>
        endif
        ; !UNICODE
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (WINVER ge 0500h)
        @DefProto DllImport, IsValidLanguageGroup, WIN_STD_CALL_CONV,, <:LGRPID, :DWORD>, 8
        ;* WINVER >= 0x0500 *
      endif
      ; DEPRECATED: GetNLSVersionEx is preferred
      @DefProto DllImport, GetNLSVersion, WIN_STD_CALL_CONV,, <:NLS_FUNCTION, :LCID, :LPNLSVERSIONINFO>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ; DEPRECATED: IsValidLocaleName is preferred
      @DefProto DllImport, IsValidLocale, WIN_STD_CALL_CONV,, <:LCID, :DWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; GetGeoInfoEx is preferred where available
      @DefProto DllImport, GetGeoInfoA, WIN_STD_CALL_CONV,, <:GEOID, :GEOTYPE, :LPSTR, :SDWORD, :LANGID>, 20
      ; GetGeoInfoEx is preferred where available
      @DefProto DllImport, GetGeoInfoW, WIN_STD_CALL_CONV,, <:GEOID, :GEOTYPE, :LPWSTR, :SDWORD, :LANGID>, 20
      ifdef UNICODE
        GetGeoInfo equ <GetGeoInfoW>
      else
        GetGeoInfo equ <GetGeoInfoA>
      endif
      ; !UNICODE
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        @DefProto DllImport, GetGeoInfoEx, WIN_STD_CALL_CONV,, <:PWSTR, :GEOTYPE, :PWSTR, :SDWORD>, 16
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
      ; EnumSystemGeoNames is preferred where available
      @DefProto DllImport, EnumSystemGeoID, WIN_STD_CALL_CONV,, <:GEOCLASS, :GEOID, :GEO_ENUMPROC>, 12
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        @DefProto DllImport, EnumSystemGeoNames, WIN_STD_CALL_CONV,, <:GEOCLASS, :GEO_ENUMNAMEPROC, :LPARAM>, 12
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ; GetUserDefaultGeoName is preferred where available
      @DefProto DllImport, GetUserGeoID, WIN_STD_CALL_CONV,, <:GEOCLASS>, 4
      ;**
      ;* Note: This API was added in the Windows 10 Fall Creators Update.
      ;* (Please use this API instead of calling GetUserGeoID.)
      ;*
      ;*
      @DefProto DllImport, GetUserDefaultGeoName, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ; GetUserDefaultGeoName is preferred where available
      ; Applications are recommended to not change user settings themselves.
      @DefProto DllImport, SetUserGeoID, WIN_STD_CALL_CONV,, <:GEOID>, 4
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        ; Applications are recommended to not change user settings themselves.
        @DefProto DllImport, SetUserGeoName, WIN_STD_CALL_CONV,, <:PWSTR>, 4
      endif
      ; DEPRECATED: Please use ResolveLocaleName
      @DefProto DllImport, ConvertDefaultLocale, WIN_STD_CALL_CONV,, <:LCID>, 4
      if (WINVER ge 0500h)
        ; DEPRECATED: Please use the user's language profile.
        @DefProto DllImport, GetSystemDefaultUILanguage, WIN_STD_CALL_CONV,, <>, 0
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0500h)
        @DefProto DllImport, GetThreadLocale, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, SetThreadLocale, WIN_STD_CALL_CONV,, <:LCID>, 4
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (WINVER ge 0500h)
        ; DEPRECATED: Please use the user's language profile.
        @DefProto DllImport, GetUserDefaultUILanguage, WIN_STD_CALL_CONV,, <>, 0
        ;* WINVER >= 0x0500 *
      endif
      ; DEPRECATED: Please use GetUserDefaultLocaleName
      @DefProto DllImport, GetUserDefaultLangID, WIN_STD_CALL_CONV,, <>, 0
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ; DEPRECATED: Please use GetUserDefaultLocaleName or the user's Language Profile
      @DefProto DllImport, GetSystemDefaultLangID, WIN_STD_CALL_CONV,, <>, 0
      ; DEPRECATED: Please use GetUserDefaultLocaleName or the user's Language Profile
      @DefProto DllImport, GetSystemDefaultLCID, WIN_STD_CALL_CONV,, <>, 0
      ; DEPRECATED: Please use GetUserDefaultLocaleName
      @DefProto DllImport, GetUserDefaultLCID, WIN_STD_CALL_CONV,, <>, 0
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, SetThreadUILanguage, WIN_STD_CALL_CONV,, <:LANGID>, 4
      if (WINVER ge 0600h)
        @DefProto DllImport, GetThreadUILanguage, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, GetProcessPreferredUILanguages, WIN_STD_CALL_CONV,, <:DWORD, :PULONG, :PZZWSTR, :PULONG>, 16
        @DefProto DllImport, SetProcessPreferredUILanguages, WIN_STD_CALL_CONV,, <:DWORD, :PCZZWSTR, :PULONG>, 12
        ;* WINVER >= 0x0600 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_PHONE_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0600h)
        @DefProto DllImport, GetUserPreferredUILanguages, WIN_STD_CALL_CONV,, <:DWORD, :PULONG, :PZZWSTR, :PULONG>, 16
        ;* WINVER >= 0x0600 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_PHONE_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (WINVER ge 0600h)
        @DefProto DllImport, GetSystemPreferredUILanguages, WIN_STD_CALL_CONV,, <:DWORD, :PULONG, :PZZWSTR, :PULONG>, 16
        @DefProto DllImport, GetThreadPreferredUILanguages, WIN_STD_CALL_CONV,, <:DWORD, :PULONG, :PZZWSTR, :PULONG>, 16
        @DefProto DllImport, SetThreadPreferredUILanguages, WIN_STD_CALL_CONV,, <:DWORD, :PCZZWSTR, :PULONG>, 12
        @DefProto DllImport, GetFileMUIInfo, WIN_STD_CALL_CONV,, <:DWORD, :PCWSTR, :PFILEMUIINFO, :ptr DWORD>, 16
        @DefProto DllImport, GetFileMUIPath, WIN_STD_CALL_CONV,, <:DWORD, :PCWSTR, :PWSTR, :PULONG, :PWSTR, :PULONG, :PULONGLONG>, 28
        @DefProto DllImport, GetUILanguageInfo, WIN_STD_CALL_CONV,, <:DWORD, :PCZZWSTR, :PZZWSTR, :PDWORD, :PDWORD>, 20
        ;* WINVER >= 0x0600 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if (NTDDI_VERSION ge NTDDI_WIN10_VB)
        DECLARE_HANDLE HSAVEDUILANGUAGES
        @DefProto DllImport, SetThreadPreferredUILanguages2, WIN_STD_CALL_CONV,, <:ULONG, :PCZZWSTR, :PULONG, :ptr HSAVEDUILANGUAGES>, 16
        @DefProto DllImport, RestoreThreadPreferredUILanguages, WIN_STD_CALL_CONV,, <:HSAVEDUILANGUAGES>, 4
        ;* NTDDI_VERSION >= NTDDI_WIN10_VB *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0600h)
        @DefProto DllImport, NotifyUILanguageChange, WIN_STD_CALL_CONV,, <:DWORD, :PCWSTR, :PCWSTR, :DWORD, :PDWORD>, 20
        ;* WINVER >= 0x0600 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;  Locale Independent APIs.
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetStringTypeExA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCSTR, :SDWORD, :LPWORD>, 20
      ifndef UNICODE
        GetStringTypeEx equ <GetStringTypeExA>
      endif
      ;  NOTE: The parameters for GetStringTypeA and GetStringTypeW are
      ;        NOT the same.  The W version was shipped in NT 3.1.  The
      ;        A version was then shipped in 16-bit OLE with the wrong
      ;        parameters (ported from Win95).  To be compatible, we
      ;        must break the relationship between the A and W versions
      ;        of GetStringType.  There will be NO function call for the
      ;        generic GetStringType.
      ;        GetStringTypeEx (above) should be used instead.
      @DefProto DllImport, GetStringTypeA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCSTR, :SDWORD, :LPWORD>, 20
      @DefProto DllImport, FoldStringA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :SDWORD, :LPSTR, :SDWORD>, 20
      ifndef UNICODE
        FoldString equ <FoldStringA>
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0500h)
        ; DEPRECATED, please use Locale Names and call EnumSystemLocalesEx
        @DefProto DllImport, EnumSystemLocalesA, WIN_STD_CALL_CONV,, <:LOCALE_ENUMPROCA, :DWORD>, 8
        ; DEPRECATED, please use Locale Names and call EnumSystemLocalesEx
        @DefProto DllImport, EnumSystemLocalesW, WIN_STD_CALL_CONV,, <:LOCALE_ENUMPROCW, :DWORD>, 8
        ifdef UNICODE
          EnumSystemLocales equ <EnumSystemLocalesW>
        else
          EnumSystemLocales equ <EnumSystemLocalesA>
        endif
        ; !UNICODE
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if (WINVER ge 0500h)
        @DefProto DllImport, EnumSystemLanguageGroupsA, WIN_STD_CALL_CONV,, <:LANGUAGEGROUP_ENUMPROCA, :DWORD, :LONG_PTR>, 12
        @DefProto DllImport, EnumSystemLanguageGroupsW, WIN_STD_CALL_CONV,, <:LANGUAGEGROUP_ENUMPROCW, :DWORD, :LONG_PTR>, 12
        ifdef UNICODE
          EnumSystemLanguageGroups equ <EnumSystemLanguageGroupsW>
        else
          EnumSystemLanguageGroups equ <EnumSystemLanguageGroupsA>
        endif
        ; !UNICODE
        @DefProto DllImport, EnumLanguageGroupLocalesA, WIN_STD_CALL_CONV,, <:LANGGROUPLOCALE_ENUMPROCA, :LGRPID, :DWORD, :LONG_PTR>, 16
        @DefProto DllImport, EnumLanguageGroupLocalesW, WIN_STD_CALL_CONV,, <:LANGGROUPLOCALE_ENUMPROCW, :LGRPID, :DWORD, :LONG_PTR>, 16
        ifdef UNICODE
          EnumLanguageGroupLocales equ <EnumLanguageGroupLocalesW>
        else
          EnumLanguageGroupLocales equ <EnumLanguageGroupLocalesA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        ; DEPRECATED: use the user language profile instead.
        @DefProto DllImport, EnumUILanguagesA, WIN_STD_CALL_CONV,, <:UILANGUAGE_ENUMPROCA, :DWORD, :LONG_PTR>, 12
        ; DEPRECATED: use the user language profile instead.
        @DefProto DllImport, EnumUILanguagesW, WIN_STD_CALL_CONV,, <:UILANGUAGE_ENUMPROCW, :DWORD, :LONG_PTR>, 12
        ifdef UNICODE
          EnumUILanguages equ <EnumUILanguagesW>
        else
          EnumUILanguages equ <EnumUILanguagesA>
        endif
        ; !UNICODE
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
      ; Please use Unicode instead.  Use of other code pages/encodings is discouraged.
      @DefProto DllImport, EnumSystemCodePagesA, WIN_STD_CALL_CONV,, <:CODEPAGE_ENUMPROCA, :DWORD>, 8
      ; Please use Unicode instead.  Use of other code pages/encodings is discouraged.
      @DefProto DllImport, EnumSystemCodePagesW, WIN_STD_CALL_CONV,, <:CODEPAGE_ENUMPROCW, :DWORD>, 8
      ifdef UNICODE
        EnumSystemCodePages equ <EnumSystemCodePagesW>
      else
        EnumSystemCodePages equ <EnumSystemCodePagesA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP  | WINAPI_PARTITION_SYSTEM) *
    endif
    ; Windows API Normalization Functions
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0600h)
        ; IDN (International Domain Name) Functions
        @DefProto DllImport, IdnToAscii, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD>, 20
        @DefProto DllImport, IdnToUnicode, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD>, 20
        @DefProto DllImport, IdnToNameprepUnicode, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD>, 20
      endif
      ;(WINVER >= 0x0600)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (WINVER ge 0600h)
        @DefProto DllImport, NormalizeString, WIN_STD_CALL_CONV,, <:NORM_FORM, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD>, 20
        @DefProto DllImport, IsNormalizedString, WIN_STD_CALL_CONV,, <:NORM_FORM, :LPCWSTR, :SDWORD>, 12
        @DefProto DllImport, VerifyScripts, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :SDWORD, :LPCWSTR, :SDWORD>, 20
        ; test scripts string
        ; size of test list string
        @DefProto DllImport, GetStringScripts, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD>, 20
        ; Script list output string
        ; size of output string
      endif
      ;(WINVER >= 0x0600)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if (WINVER ge 0600h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        ; String based NLS APIs
        LOCALE_NAME_USER_DEFAULT equ <NULL>
        LOCALE_NAME_INVARIANT equ <L()>
        LOCALE_NAME_SYSTEM_DEFAULT equ <L("!x-sys-default-locale")>
        @DefProto DllImport, GetLocaleInfoEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :LCTYPE, :LPWSTR, :SDWORD>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, GetCalendarInfoEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :CALID, :LPCWSTR, :CALTYPE, :LPWSTR, :SDWORD, :LPDWORD>, 28
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
        ifndef GetDurationFormatEx_DEFINED
          @DefProto DllImport, GetDurationFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :ULONGLONG, :LPCWSTR, :LPWSTR, :SDWORD>, 28
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, GetNumberFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWSTR, :ptr NUMBERFMTW, :LPWSTR, :SDWORD>, 24
        @DefProto DllImport, GetCurrencyFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWSTR, :ptr CURRENCYFMTW, :LPWSTR, :SDWORD>, 24
        @DefProto DllImport, GetUserDefaultLocaleName, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD>, 8
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, GetSystemDefaultLocaleName, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD>, 8
        @DefProto DllImport, IsNLSDefinedString, WIN_STD_CALL_CONV,, <:NLS_FUNCTION, :DWORD, :LPNLSVERSIONINFO, :LPCWSTR, :INT_>, 20
        @DefProto DllImport, GetNLSVersionEx, WIN_STD_CALL_CONV,, <:NLS_FUNCTION, :LPCWSTR, :LPNLSVERSIONINFOEX>, 12
        if (WINVER ge _WIN32_WINNT_WIN8)
          @DefProto DllImport, IsValidNLSVersion, WIN_STD_CALL_CONV,, <:NLS_FUNCTION, :LPCWSTR, :LPNLSVERSIONINFOEX>, 12
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, FindNLSStringEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWSTR, :SDWORD, :LPCWSTR, :SDWORD, :LPINT, :LPNLSVERSIONINFO, :LPVOID, :LPARAM>, 40
        if (WINVER ge _WIN32_WINNT_WIN8)
        else
        endif
        @DefProto DllImport, LCMapStringEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWSTR, :SDWORD, :LPWSTR, :SDWORD, :LPNLSVERSIONINFO, :LPVOID, :LPARAM>, 36
        @DefProto DllImport, IsValidLocaleName, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
        TYPE_CALINFO_ENUMPROCEXEX typedef proto WIN_STD_CALL_CONV :LPWSTR, :CALID, :LPWSTR, :LPARAM
        CALINFO_ENUMPROCEXEX typedef ptr TYPE_CALINFO_ENUMPROCEXEX

        @DefProto DllImport, EnumCalendarInfoExEx, WIN_STD_CALL_CONV,, <:CALINFO_ENUMPROCEXEX, :LPCWSTR, :CALID, :LPCWSTR, :CALTYPE, :LPARAM>, 24
        TYPE_DATEFMT_ENUMPROCEXEX typedef proto WIN_STD_CALL_CONV :LPWSTR, :CALID, :LPARAM
        DATEFMT_ENUMPROCEXEX typedef ptr TYPE_DATEFMT_ENUMPROCEXEX

        @DefProto DllImport, EnumDateFormatsExEx, WIN_STD_CALL_CONV,, <:DATEFMT_ENUMPROCEXEX, :LPCWSTR, :DWORD, :LPARAM>, 16
        TYPE_TIMEFMT_ENUMPROCEX typedef proto WIN_STD_CALL_CONV :LPWSTR, :LPARAM
        TIMEFMT_ENUMPROCEX typedef ptr TYPE_TIMEFMT_ENUMPROCEX

        @DefProto DllImport, EnumTimeFormatsEx, WIN_STD_CALL_CONV,, <:TIMEFMT_ENUMPROCEX, :LPCWSTR, :DWORD, :LPARAM>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        TYPE_LOCALE_ENUMPROCEX typedef proto WIN_STD_CALL_CONV :LPWSTR, :DWORD, :LPARAM
        LOCALE_ENUMPROCEX typedef ptr TYPE_LOCALE_ENUMPROCEX

        @DefProto DllImport, EnumSystemLocalesEx, WIN_STD_CALL_CONV,, <:LOCALE_ENUMPROCEX, :DWORD, :LPARAM, :LPVOID>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
    endif
    ;(WINVER >= 0x0600)
    if (WINVER ge _WIN32_WINNT_WIN7)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, ResolveLocaleName, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :SDWORD>, 12
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
    endif
    ; (WINVER >= _WIN32_WINNT_WIN7)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
  endif
  ; NONLS
  ; Restore the original value of the 'DEPRECATED' macro");
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _WINNLS_
