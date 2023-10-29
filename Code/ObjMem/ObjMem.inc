; ==================================================================================================
; Title:    ObjMem.inc
; Author:   G. Friedrich
; Version:  C.1.0
; Purpose:  ObjAsm library procedures and definitions.
; Notes:    Version 1.0.0, October 2017
;             - First release.
; ==================================================================================================


;String constants
externdef bCRLF:CHRA
externdef wCRLF:CHRW
cCRLF textequ <szCRLF>
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  szCRLF textequ <bCRLF>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  szCRLF textequ <wCRLF>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

externdef bNULL:CHRA
externdef wNULL:CHRW
cNULL textequ <szNULL>
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  szNULL textequ <bNULL>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  szNULL textequ <wNULL>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

externdef bTAB:CHRA
externdef wTAB:CHRW
cTAB textequ <szTAB>
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  szTAB textequ <bTAB>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  szTAB textequ <wTAB>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

externdef bError:CHRA
externdef wError:CHRW
cError textequ <szError>
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  szError textequ <bError>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  szError textequ <wError>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif


;Memory management procedures
MemFillB proto :POINTER, :DWORD, :BYTE
MemFillW proto :POINTER, :DWORD, :WORD
MemClone proto :POINTER, :POINTER, :DWORD
MemComp proto :POINTER, :POINTER, :DWORD
MemShift proto :POINTER, :POINTER, :DWORD
MemSwap proto :POINTER, :POINTER, :DWORD
MemZero proto :POINTER, :DWORD


;String procedures
if TARGET_PLATFORM eq PLATFORM_WINDOWS
  BStrAlloc proto :DWORD
  StrAllocA proto :DWORD
  StrAllocW proto :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    StrAlloc textequ <StrAllocA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    StrAlloc textequ <StrAllocW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif
elseif TARGET_PLATFORM eq PLATFORM_UEFI
  StrAllocA_UEFI proto :DWORD
  StrAllocW_UEFI proto :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    StrAlloc textequ <StrAllocA_UEFI>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    StrAlloc textequ <StrAllocW_UEFI>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif
  StrAllocA textequ <StrAllocA_UEFI>
  StrAllocW textequ <StrAllocW_UEFI>
endif

if TARGET_PLATFORM eq PLATFORM_WINDOWS
  BStrNew proto :POINTER
  StrNewA proto :POINTER
  StrNewW proto :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    StrNew textequ <StrNewA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    StrNew textequ <StrNewW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif
elseif TARGET_PLATFORM eq PLATFORM_UEFI
  StrNewA_UEFI proto :POINTER
  StrNewW_UEFI proto :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    StrNew textequ <StrNewA_UEFI>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    StrNew textequ <StrNewW_UEFI>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif
  StrNewA textequ <StrNewA_UEFI>
  StrNewW textequ <StrNewW_UEFI>
endif

if TARGET_PLATFORM eq PLATFORM_WINDOWS
  BStrCNew proto :POINTER, :DWORD
  StrCNewA proto :POINTER, :DWORD
  StrCNewW proto :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    StrCNew textequ <StrCNewA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    StrCNew textequ <StrCNewW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif
elseif TARGET_PLATFORM eq PLATFORM_UEFI
  StrCNewA_UEFI proto :POINTER, :DWORD
  StrCNewW_UEFI proto :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    StrCNew textequ <StrCNewA_UEFI>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    StrCNew textequ <StrCNewW_UEFI>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif
  StrCNewA textequ <StrCNewA_UEFI>
  StrCNewW textequ <StrCNewW_UEFI>
endif

if TARGET_PLATFORM eq PLATFORM_WINDOWS
  BStrDispose proto :POINTER
  StrDispose proto :POINTER
  StrDisposeA textequ <StrDispose>
  StrDisposeW textequ <StrDispose>
elseif TARGET_PLATFORM eq PLATFORM_UEFI
  StrDispose_UEFI proto :POINTER
  StrDispose textequ <StrDispose_UEFI>
  StrDisposeA textequ <StrDispose_UEFI>
  StrDisposeW textequ <StrDispose_UEFI>
endif

BStrLength proto :POINTER
StrLengthA proto :POINTER
StrLengthW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrLength textequ <StrLengthA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrLength textequ <StrLengthW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrSize proto :POINTER
StrSizeA proto :POINTER
StrSizeW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrSize textequ <StrSizeA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrSize textequ <StrSizeW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

StrCLengthA proto :POINTER, :DWORD
StrCLengthW proto :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCLength textequ <StrCLengthA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCLength textequ <StrCLengthW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrEnd proto :POINTER
StrEndA proto :POINTER
StrEndW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrEnd textequ <StrEndA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrEnd textequ <StrEndW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrMove proto :POINTER, :POINTER, :DWORD
StrMoveA textequ <MemShift>
StrMoveW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrMove textequ <StrMoveA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrMove textequ <StrMoveW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCopy proto :POINTER, :POINTER
StrCopyA proto :POINTER, :POINTER
StrCopyW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCopy textequ <StrCopyA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCopy textequ <StrCopyW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrECopy proto :POINTER, :POINTER
StrECopyA proto :POINTER, :POINTER
StrECopyW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrECopy textequ <StrECopyA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrECopy textequ <StrECopyW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCECopy proto :POINTER, :POINTER, :DWORD
StrCECopyA proto :POINTER, :POINTER, :DWORD
StrCECopyW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCECopy textequ <StrCECopyA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCECopy textequ <StrCECopyW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCCopy textequ <BStrCECopy>
StrCCopyA proto :POINTER, :POINTER, :DWORD
StrCCopyW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCCopy textequ <StrCCopyA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCCopy textequ <StrCCopyW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCat proto :POINTER, :POINTER
StrCatA proto :POINTER, :POINTER
StrCatW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCat textequ <StrCatA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCat textequ <StrCatW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCatChar proto :POINTER, :CHRW
StrCatCharA proto :POINTER, :CHRA
StrCatCharW proto :POINTER, :CHRW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCatChar textequ <StrCatCharA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCatChar textequ <StrCatCharW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrECatChar proto :POINTER, :CHRW
StrECatCharA proto :POINTER, :CHRA
StrECatCharW proto :POINTER, :CHRW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrECatChar textequ <StrECatCharA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrECatChar textequ <StrECatCharW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCCatChar proto :POINTER, :CHRW, :DWORD
StrCCatCharA proto :POINTER, :CHRA, :DWORD
StrCCatCharW proto :POINTER, :CHRW, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCCatChar textequ <StrCCatCharA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCCatChar textequ <StrCCatCharW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrECat proto :POINTER, :POINTER
StrECatA proto :POINTER, :POINTER
StrECatW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrECat textequ <StrECatA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrECat textequ <StrECatW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCCat proto :POINTER, :POINTER, :DWORD
StrCCatA proto :POINTER, :POINTER, :DWORD
StrCCatW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCCat textequ <StrCCatA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCCat textequ <StrCCatW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCECat proto :POINTER, :POINTER, :DWORD
StrCECatA proto :POINTER, :POINTER, :DWORD
StrCECatW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCECat textequ <StrCECatA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCECat textequ <StrCECatW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrComp textequ <StrCompW>
StrCompA proto :POINTER, :POINTER
StrCompW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrComp textequ <StrCompA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrComp textequ <StrCompW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCComp textequ <StrCCompW>
StrCCompA proto :POINTER, :POINTER, :DWORD
StrCCompW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCComp textequ <StrCCompA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCComp textequ <StrCCompW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrIComp textequ <StrICompW>
StrICompA proto :POINTER, :POINTER
StrICompW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrIComp textequ <StrICompA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrIComp textequ <StrICompW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCIComp textequ <StrCICompW>
StrCICompA proto :POINTER, :POINTER, :DWORD
StrCICompW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCIComp textequ <StrCICompA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCIComp textequ <StrCICompW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrLScan textequ <StrLScanW>
StrLScanA proto :POINTER, :CHRA
StrLScanW proto :POINTER, :CHRW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrLScan textequ <StrLScanA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrLScan textequ <StrLScanW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrRScan textequ <StrRScanW>
StrRScanA proto :POINTER, :CHRA
StrRScanW proto :POINTER, :CHRW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrRScan textequ <StrRScanA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrRScan textequ <StrRScanW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCScan proto :POINTER, :DWORD, :CHRW
StrCScanA proto :POINTER, :DWORD, :CHRA
StrCScanW proto :POINTER, :DWORD, :CHRW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCScan textequ <StrCScanA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCScan textequ <StrCScanW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrPos textequ <StrPosW>
StrPosA proto :POINTER, :POINTER
StrPosW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrPos textequ <StrPosA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrPos textequ <StrPosW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrCPos textequ <StrCPosW>
StrCPosA proto :POINTER, :POINTER, :DWORD
StrCPosW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCPos textequ <StrCPosA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCPos textequ <StrCPosW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrFilter textequ <StrFilterW>
StrFilterA proto :POINTER, :POINTER
StrFilterW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrFilter textequ <StrFilterA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrFilter textequ <StrFilterW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrIFilter textequ <StrIFilterW>
StrIFilterA proto :POINTER, :POINTER
StrIFilterW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrIFilter textequ <StrIFilterA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrIFilter textequ <StrIFilterW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrLRTrim proto :POINTER, :POINTER
StrLRTrimA proto :POINTER, :POINTER
StrLRTrimW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrLRTrim textequ <StrLRTrimA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrLRTrim textequ <StrLRTrimW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrLTrim proto :POINTER, :POINTER
StrLTrimA proto :POINTER, :POINTER
StrLTrimW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrLTrim textequ <StrLTrimA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrLTrim textequ <StrLTrimW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrRTrim proto :POINTER, :POINTER
StrRTrimA proto :POINTER, :POINTER
StrRTrimW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrRTrim textequ <StrRTrimA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrRTrim textequ <StrRTrimW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrUpper textequ <StrUpperW>
StrUpperA proto :POINTER
StrUpperW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrUpper textequ <StrUpperA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrUpper textequ <StrUpperW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrLower textequ <StrLowerW>
StrLowerA proto :POINTER
StrLowerW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrLower textequ <StrLowerA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrLower textequ <StrLowerW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrMid proto :POINTER, :POINTER, :DWORD, :DWORD
StrMidA proto :POINTER, :POINTER, :DWORD, :DWORD
StrMidW proto :POINTER, :POINTER, :DWORD, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrMid textequ <StrMidA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrMid textequ <StrMidW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrLeft proto :POINTER, :POINTER, :DWORD
StrLeftA proto :POINTER, :POINTER, :DWORD
StrLeftW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrLeft textequ <StrLeftA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrLeft textequ <StrLeftW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrRight proto :POINTER, :POINTER, :DWORD
StrRightA proto :POINTER, :POINTER, :DWORD
StrRightW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrRight textequ <StrRightA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrRight textequ <StrRightW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrStartsWith proto :POINTER, :POINTER
StrStartsWithA proto :POINTER, :POINTER
StrStartsWithW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrStartsWith textequ <StrStartsWithA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrStartsWith textequ <StrStartsWithW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrEndsWith proto :POINTER, :POINTER
StrEndsWithA proto :POINTER, :POINTER
StrEndsWithW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrEndsWith textequ <StrEndsWithA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrEndsWith textequ <StrEndsWithW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

BStrRepChr proto :CHRW, :DWORD
StrRepChrA proto :CHRA, :DWORD
StrRepChrW proto :CHRW, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrRepChr textequ <StrRepChrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrRepChr textequ <StrRepChrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

StrW2StrA proto :POINTER, :POINTER
StrA2StrW proto :POINTER, :POINTER

BStr2StrA textequ <StrW2StrA>
BStr2StrW textequ <StrCopyW>
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  BStr2Str textequ <BStr2StrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  BStr2Str textequ <BStr2StrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

Str2BStrA proto :POINTER, :POINTER
Str2BStrW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  Str2BStr textequ <Str2BStrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  Str2BStr textequ <Str2BStrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

St0ToBStr proto :POINTER, :DWORD, :DWORD, :DWORD
St0ToStrA proto :POINTER, :DWORD, :DWORD, :DWORD
St0ToStrW proto :POINTER, :DWORD, :DWORD, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  St0ToStr textequ <St0ToStrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  St0ToStr textequ <St0ToStrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
ST0TOSTR_MAX_CHARS equ 35                               ;ZTC included

BStrToSt0 proto :POINTER
StrToSt0A proto :POINTER
StrToSt0W proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrToSt0 textequ <StrToSt0A>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrToSt0 textequ <StrToSt0W>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

GUID2BStr proto :POINTER, :POINTER
GUID2StrA proto :POINTER, :POINTER
GUID2StrW proto :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  GUID2Str textequ <GUID2StrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  GUID2Str textequ <GUID2StrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
GUID2STR_MAX_CHARS equ 37                               ;ZTC included

sdword2decA proto :POINTER, :SDWORD
sdword2decW proto :POINTER, :SDWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  sdword2dec textequ <sdword2decA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  sdword2dec textequ <sdword2decW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
SDWORD2DEC_MAX_CHARS equ 12                             ;ZTC included

udword2decA proto :POINTER, :DWORD
udword2decW proto :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  dword2dec textequ <udword2decA>
  udword2dec textequ <udword2decA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  dword2dec textequ <udword2decW>
  udword2dec textequ <udword2decW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
dword2decA textequ <udword2decA>                        ;Compatibility
dword2decW textequ <udword2decW>                        ;Compatibility
DWORD2DEC_MAX_CHARS equ 11                              ;ZTC included

sqword2decA proto :POINTER, :SQWORD
sqword2decW proto :POINTER, :SQWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  sqword2dec textequ <sqword2decA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  sqword2dec textequ <sqword2decW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
SQWORD2DEC_MAX_CHARS equ 21                             ;ZTC included

uqword2decA proto :POINTER, :QWORD
uqword2decW proto :POINTER, :QWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  qword2dec textequ <uqword2decA>
  uqword2dec textequ <uqword2decA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  qword2dec textequ <uqword2decW>
  uqword2dec textequ <uqword2decW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
qword2decA textequ <uqword2decA>                        ;Compatibility
qword2decW textequ <uqword2decW>                        ;Compatibility
QWORD2DEC_MAX_CHARS equ 21                              ;ZTC included

dword2binA proto :POINTER, :DWORD
dword2binW proto :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  dword2bin textequ <dword2binA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  dword2bin textequ <dword2binW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
DWORD2BIN_MAX_CHARS equ 33                              ;ZTC included

word2hexA proto :POINTER, :WORD
word2hexW proto :POINTER, :WORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  word2hex textequ <word2hexA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  word2hex textequ <word2hexW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
WORD2HEX_MAX_CHARS equ 5                                ;ZTC included

byte2hexA proto :POINTER, :BYTE
byte2hexW proto :POINTER, :BYTE
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  byte2hex textequ <byte2hexA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  byte2hex textequ <byte2hexW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
BYTE2HEX_MAX_CHARS equ 3                                ;ZTC included

dword2hexA proto :POINTER, :DWORD
dword2hexW proto :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  dword2hex textequ <dword2hexA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  dword2hex textequ <dword2hexW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
DWORD2HEX_MAX_CHARS equ 9                               ;ZTC included

dec2dwordA proto :POINTER
dec2dwordW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  dec2dword textequ <dec2dwordA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  dec2dword textequ <dec2dwordW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

bin2dwordA proto :POINTER
bin2dwordW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  bin2dword textequ <bin2dwordA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  bin2dword textequ <bin2dwordW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

bin2qwordA proto :POINTER
bin2qwordW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  bin2qword textequ <bin2qwordA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  bin2qword textequ <bin2qwordW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

qword2binA proto :POINTER, :QWORD
qword2binW proto :POINTER, :QWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  qword2bin textequ <qword2binA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  qword2bin textequ <qword2binW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
QWORD2BIN_MAX_CHARS equ 65                              ;ZTC included

qword2hexA proto :POINTER, :QWORD
qword2hexW proto :POINTER, :QWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  qword2hex textequ <qword2hexA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  qword2hex textequ <qword2hexW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif
QWORD2HEX_MAX_CHARS equ 17                              ;ZTC included

Mem2HexA proto :POINTER, :POINTER, :DWORD
Mem2HexW proto :POINTER, :POINTER, :DWORD
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  Mem2Hex textequ <Mem2HexA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  Mem2Hex textequ <Mem2HexW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

hex2dwordA proto :POINTER
hex2dwordW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  hex2dword textequ <hex2dwordA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  hex2dword textequ <hex2dwordW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

hex2qwordA proto :POINTER
hex2qwordW proto :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  hex2qword textequ <hex2qwordA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  hex2qword textequ <hex2qwordW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

RGB24To16ColorIndex proto :DWORD

if TARGET_BITNESS eq 32
  xword2hex textequ <dword2hex>
  hex2xword textequ <hex2dword>
  bin2xword textequ <bin2dword>
  xword2bin textequ <dword2bin>
  sxword2dec textequ <sdword2dec>
  uxword2dec textequ <udword2dec>

  xword2hexA textequ <dword2hexA>
  hex2xwordA textequ <hex2dwordA>
  bin2xwordA textequ <bin2dwordA>
  xword2binA textequ <dword2binA>
  sxword2decA textequ <sdword2decA>
  uxword2decA textequ <udword2decA>
  xword2decA textequ <udword2decA>

  xword2hexW textequ <dword2hexW>
  hex2xwordW textequ <hex2dwordW>
  bin2xwordW textequ <bin2dwordW>
  xword2binW textequ <dword2binW>
  sxword2decW textequ <sdword2decW>
  uxword2decW textequ <udword2decW>
  xword2decW textequ <udword2decW>

  XWORD2HEX_MAX_CHARS textequ <DWORD2HEX_MAX_CHARS>
  XWORD2BIN_MAX_CHARS textequ <DWORD2BIN_MAX_CHARS>
  XWORD2DEC_MAX_CHARS textequ <DWORD2DEC_MAX_CHARS>
  SXWORD2DEC_MAX_CHARS textequ <SDWORD2DEC_MAX_CHARS>

elseif TARGET_BITNESS eq 64
  xword2hex textequ <qword2hex>
  hex2xword textequ <hex2qword>
  bin2xword textequ <bin2qword>
  xword2bin textequ <qword2bin>
  sxword2dec textequ <sqword2dec>
  uxword2dec textequ <uqword2dec>

  xword2hexA textequ <qword2hexA>
  hex2xwordA textequ <hex2qwordA>
  bin2xwordA textequ <bin2qwordA>
  xword2binA textequ <qword2binA>
  sxword2decA textequ <sqword2decA>
  uxword2decA textequ <uqword2decA>
  xword2decA textequ <uqword2decA>

  xword2hexW textequ <qword2hexW>
  hex2xwordW textequ <hex2qwordW>
  bin2xwordW textequ <bin2qwordW>
  xword2binW textequ <qword2binW>
  sxword2decW textequ <sqword2decW>
  uxword2decW textequ <uqword2decW>
  xword2decW textequ <uqword2decW>

  XWORD2HEX_MAX_CHARS textequ <QWORD2HEX_MAX_CHARS>
  XWORD2BIN_MAX_CHARS textequ <QWORD2BIN_MAX_CHARS>
  XWORD2DEC_MAX_CHARS textequ <QWORD2DEC_MAX_CHARS>
  SXWORD2DEC_MAX_CHARS textequ <SQWORD2DEC_MAX_CHARS>
else
  %echo Warning: incompatible Bitness: $ToStr(%TARGET_BITNESS)
endif


if TARGET_PLATFORM eq PLATFORM_WINDOWS
; COM related procedures
  ComEventsAdvice proto :POINTER, :POINTER, :POINTER, :POINTER, :POINTER
  ComEventsUnadvice proto :POINTER, :DWORD
  ComPtrAssign proto :POINTER, :POINTER

  ComGetErrStrA proto :DWORD
  ComGetErrStrW proto :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    ComGetErrStr textequ <ComGetErrStrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    ComGetErrStr textequ <ComGetErrStrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

; DebugCenter procedures contained in DebugProcs.asm
  DbgOpenWnd proto
  DbgOpenCon proto
  DbgOpenLog proto
  DbgCloseDevice proto
  DbgOutCmd proto :BYTE, :DWORD, :DWORD, :POINTER
  DbgOutBitmap proto :HANDLE, :DWORD, :POINTER
  DbgOutApiErr proto :DWORD, :DWORD, :DWORD, :POINTER
  DbgOutComErr proto :DWORD, :DWORD, :DWORD, :POINTER
  DbgShowTraceMethod proto :POINTER, :DWORD, :POINTER, :DWORD, :DWORD, :POINTER

  DbgOutInterfaceName proto :ptr GUID, :DWORD, :DWORD, :POINTER
  DbgOutInterface proto :ptr GUID, :DWORD, :DWORD, :POINTER
  DbgOutComponentName proto :ptr GUID, :DWORD, :DWORD, :POINTER
  DbgOutComponent proto :ptr GUID, :DWORD, :DWORD, :POINTER

  DbgOutMsg proto :DWORD, :DWORD, :DWORD, :POINTER

elseif TARGET_PLATFORM eq PLATFORM_UEFI
  MemAlloc_UEFI proto :DWORD, :DWORD, :DWORD
  MemReAlloc_UEFI proto :POINTER, :DWORD, :DWORD, :DWORD
  MemFree_UEFI proto :POINTER

  UefiGetErrStrA proto :XWORD
  UefiGetErrStrW proto :XWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    UefiGetErrStr textequ <UefiGetErrStrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    UefiGetErrStr textequ <UefiGetErrStrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  DbgOutTextA textequ <DbgOutTextA_UEFI>
  DbgOutTextW textequ <DbgOutTextW_UEFI>
  DbgOutMem textequ <DbgOutMem_UEFI>
  DbgOutFPU textequ <DbgOutFPU_UEFI>
  DbgShowObjectHeader textequ <DbgShowObjectHeader_UEFI>
endif

DbgOutTextA proto :POINTER, :DWORD, :DWORD, :DWORD, :POINTER
DbgOutTextW proto :POINTER, :DWORD, :DWORD, :DWORD, :POINTER
DbgOutTextCA proto :POINTER, :DWORD, :DWORD, :DWORD, :DWORD, :POINTER
DbgOutTextCW proto :POINTER, :DWORD, :DWORD, :DWORD, :DWORD, :POINTER
DbgOutMem proto :POINTER, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :POINTER
DbgOutFPU proto :POINTER, :DWORD, :DWORD
DbgShowObjectHeader proto :POINTER, :POINTER, :DWORD, :DWORD, :POINTER

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DbgOutText textequ <DbgOutTextA>
  DbgOutTextC textequ <DbgOutTextCA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  DbgOutText textequ <DbgOutTextW>
  DbgOutTextC textequ <DbgOutTextCW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif


;OOP model procedures
GetObjectID proto :POINTER
GetAncestorID proto :DWORD
GetObjectTemplate proto :DWORD


;General purpose procedures
if TARGET_PLATFORM eq PLATFORM_WINDOWS
  GetWinVersion proto :POINTER, :POINTER, :POINTER
  AppsUseLightTheme proto
  SystemUsesLightTheme proto
  LoadCommonControls proto :DWORD
  CenterForm proto :DWORD, :DWORD
  GetRawClientRect proto :HANDLE, :PRECT
  GetBottomWindow proto :HANDLE
  MoveWindowVisible proto :HANDLE, :SDWORD, :SDWORD
  WndFadeIn proto :HANDLE, :DWORD, :DWORD, :DWORD, :DWORD
  WndFadeOut proto :HANDLE, :DWORD, :DWORD, :DWORD, :DWORD
  DrawTransparentBitmap proto :HANDLE, :HANDLE, :DWORD, :DWORD, :DWORD
  CreateBitmapFromFileInMem proto :POINTER
  CreateBitmapFromCompressedFileInRes proto :HINSTANCE, :XWORD
  CreateIconFromCompressedFileInRes proto :HINSTANCE, :XWORD, :DWORD, :DWORD
  Bmp2Rgn proto :HANDLE, :DWORD
  AreVisualStylesEnabled proto
  SetClientSize proto :HANDLE, :DWORD, :DWORD
  SysShutdown proto :DWORD, :DWORD
  SysStandby proto
  WaitForProcess proto :DWORD, :DWORD
  IsProcessElevated proto :HANDLE
  IsWinNT proto
  IsAdmin proto
  GetLogProcCount proto :POINTER
  IsScrollBarVisible proto :HANDLE, :DWORD
  GetDlgBaseUnits proto :HANDLE
  SendChildrenMessage proto :HANDLE, :DWORD, :WPARAM, :LPARAM
  CompressMem proto :POINTER, :DWORD, :DWORD 
  CompressMemToFile proto :POINTER, :DWORD, :DWORD, :HANDLE
  DecompressFromFile proto :HANDLE
  DecompressMem proto :POINTER, :DWORD, :DWORD
  DecompressFileFromRes proto :HINSTANCE, :XWORD
  DecompressFileInMem proto :POINTER, :DWORD
  ErrorMessageBoxA proto :HANDLE, :POINTER, :WORD, :DWORD
  ErrorMessageBoxW proto :HANDLE, :POINTER, :WORD, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    ErrorMessageBox textequ <ErrorMessageBoxA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    ErrorMessageBox textequ <ErrorMessageBoxW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  SetPrivilegeTokenA proto :HANDLE, :POINTER, :DWORD
  SetPrivilegeTokenW proto :HANDLE, :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    SetPrivilegeToken textequ <SetPrivilegeTokenA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    SetPrivilegeToken textequ <SetPrivilegeTokenW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  ParseA proto :POINTER, :POINTER, :DWORD
  ParseW proto :POINTER, :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    Parse textequ <ParseA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    Parse textequ <ParseW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  ShortToLongPathNameA proto :POINTER
  ShortToLongPathNameW proto :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    ShortToLongPathName textequ <ShortToLongPathNameA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    ShortToLongPathName textequ <ShortToLongPathNameW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  FileExistA proto :POINTER
  FileExistW proto :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    FileExist textequ <FileExistA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    FileExist textequ <FileExistW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  FindFileA proto :POINTER, :POINTER, :POINTER
  FindFileW proto :POINTER, :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    FindFile textequ <FindFileA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    FindFile textequ <FindFileW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  CreatePathA proto :POINTER
  CreatePathW proto :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    CreatePath textequ <CreatePathA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    CreatePath textequ <CreatePathW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  GetPrevInstanceA proto :POINTER, :POINTER
  GetPrevInstanceW proto :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    GetPrevInstance textequ <GetPrevInstanceA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    GetPrevInstance textequ <GetPrevInstanceW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  ActivatePrevInstanceA proto :POINTER, :POINTER
  ActivatePrevInstanceW proto :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    ActivatePrevInstance textequ <ActivatePrevInstanceA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    ActivatePrevInstance textequ <ActivatePrevInstanceW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  FindModuleByAddrA proto :POINTER, :POINTER
  FindModuleByAddrW proto :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    FindModuleByAddr textequ <FindModuleByAddrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    FindModuleByAddr textequ <FindModuleByAddrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  FindModuleByAddr9xA proto :POINTER, :POINTER
  FindModuleByAddr9xW proto :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    FindModuleByAddr9x textequ <FindModuleByAddr9xA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    FindModuleByAddr9x textequ <FindModuleByAddr9xW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  SetExceptionMessageA proto :POINTER, :POINTER, :POINTER
  SetExceptionMessageW proto :POINTER, :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    SetExceptionMessage textequ <SetExceptionMessageA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    SetExceptionMessage textequ <SetExceptionMessageW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  GetFileLinesA proto :HANDLE
  GetFileLinesW proto :HANDLE
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    GetFileLines textequ <GetFileLinesA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    GetFileLines textequ <GetFileLinesW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  NetErr2StrA proto :DWORD, :POINTER, :DWORD
  NetErr2StrW proto :DWORD, :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    NetErr2Str textequ <NetErr2StrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    NetErr2Str textequ <NetErr2StrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  DllErr2StrA proto :DWORD, :POINTER, :DWORD, :POINTER
  DllErr2StrW proto :DWORD, :POINTER, :DWORD, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    DllErr2Str textequ <DllErr2StrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    DllErr2Str textequ <DllErr2StrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  Err2StrA proto :DWORD, :POINTER, :DWORD
  Err2StrW proto :DWORD, :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    Err2Str textequ <Err2StrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    Err2Str textequ <Err2StrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  GetExceptionStrA proto :DWORD
  GetExceptionStrW proto :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    GetExceptionStr textequ <GetExceptionStrA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    GetExceptionStr textequ <GetExceptionStrW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  LoadPngFromResourceA proto :PSTRING
  LoadPngFromResourceW proto :PSTRING
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    LoadPngFromResource textequ <LoadPngFromResourceA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    LoadPngFromResource textequ <LoadPngFromResourceW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  MsgBoxA proto :HANDLE, :POINTER, :POINTER, :DWORD
  MsgBoxW proto :HANDLE, :POINTER, :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    MsgBox textequ <MsgBoxA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    MsgBox textequ <MsgBoxW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

; File hash procedures
  GFH_MD2   equ   08001h
  GFH_MD4   equ   08002h
  GFH_MD5   equ   08003h
  GFH_SHA   equ   08004h
  GFH_SHA1  equ   08004h       ;Same as GFH_SHA
  GFH_MAC   equ   08005h

  GetFileHashA proto :POINTER, :POINTER, :DWORD
  GetFileHashW proto :POINTER, :POINTER, :DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    GetFileHash textequ <GetFileHashA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    GetFileHash textequ <GetFileHashW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

; ROP operators
;
; Reverse Polish notation
;
; Operand Meaning:                             Operator Meaning:
; D Destination bitmap                         a Bitwise AND
; P Selected brush (also called pattern)       n Bitwise NOT (inverse)
; S Source bitmap                              o Bitwise OR
;                                              x Bitwise exclusive OR (XOR)

  ROP_0           equ   00000042h   ;BLACKNESS
  ROP_DPSoon      equ   00010289h
  ROP_DPSona      equ   00020C89h
  ROP_PSon        equ   000300AAh
  ROP_SDPona      equ   00040C88h
  ROP_DPon        equ   000500A9h
  ROP_PDSxnon     equ   00060865h
  ROP_PDSaon      equ   000702C5h
  ROP_SDPnaa      equ   00080F08h
  ROP_PDSxon      equ   00090245h
  ROP_DPna        equ   000A0329h
  ROP_PSDnaon     equ   000B0B2Ah
  ROP_SPna        equ   000C0324h
  ROP_PDSnaon     equ   000D0B25h
  ROP_PDSonon     equ   000E08A5h
  ROP_Pn          equ   000F0001h
  ROP_PDSona      equ   00100C85h
  ROP_DSon        equ   001100A6h   ;NOTSRCERASE
  ROP_SDPxnon     equ   00120868h
  ROP_SDPaon      equ   001302C8h
  ROP_DPSxnon     equ   00140869h
  ROP_DPSaon      equ   001502C9h
  ROP_PSDPSanaxx  equ   00165CCAh
  ROP_SSPxDSxaxn  equ   00171D54h
  ROP_SPxPDxa     equ   00180D59h
  ROP_SDPSanaxn   equ   00191CC8h
  ROP_PDSPaox     equ   001A06C5h
  ROP_SDPSxaxn    equ   001B0768h
  ROP_PSDPaox     equ   001C06CAh
  ROP_DSPDxaxn    equ   001D0766h
  ROP_PDSox       equ   001E01A5h
  ROP_PDSoan      equ   001F0385h
  ROP_DPSnaa      equ   00200F09h
  ROP_SDPxon      equ   00210248h
  ROP_DSna        equ   00220326h
  ROP_SPDnaon     equ   00230B24h
  ROP_SPxDSxa     equ   00240D55h
  ROP_PDSPanaxn   equ   00251CC5h
  ROP_SDPSaox     equ   002606C8h
  ROP_SDPSxnox    equ   00271868h
  ROP_DPSxa       equ   00280369h
  ROP_PSDPSaoxxn  equ   002916CAh
  ROP_DPSana      equ   002A0CC9h
  ROP_SSPxPDxaxn  equ   002B1D58h
  ROP_SPDSoax     equ   002C0784h
  ROP_PSDnox      equ   002D060Ah
  ROP_PSDPxox     equ   002E064Ah
  ROP_PSDnoan     equ   002F0E2Ah
  ROP_PSna        equ   0030032Ah
  ROP_SDPnaon     equ   00310B28h
  ROP_SDPSoox     equ   00320688h
  ROP_Sn          equ   00330008h   ;NOTSRCCOPY
  ROP_SPDSaox     equ   003406C4h
  ROP_SPDSxnox    equ   00351864h
  ROP_SDPox       equ   003601A8h
  ROP_SDPoan      equ   00370388h
  ROP_PSDPoax     equ   0038078Ah
  ROP_SPDnox      equ   00390604h
  ROP_SPDSxox     equ   003A0644h
  ROP_SPDnoan     equ   003B0E24h
  ROP_PSx         equ   003C004Ah
  ROP_SPDSonox    equ   003D18A4h
  ROP_SPDSnaox    equ   003E1B24h
  ROP_PSan        equ   003F00EAh
  ROP_PSDnaa      equ   00400F0Ah
  ROP_DPSxon      equ   00410249h
  ROP_SDxPDxa     equ   00420D5Dh
  ROP_SPDSanaxn   equ   00431CC4h
  ROP_SDna        equ   00440328h   ;SRCERASE
  ROP_DPSnaon     equ   00450B29h
  ROP_DSPDaox     equ   004606C6h
  ROP_PSDPxaxn    equ   0047076Ah
  ROP_SDPxa       equ   00480368h
  ROP_PDSPDaoxxn  equ   004916C5h
  ROP_DPSDoax     equ   004A0789h
  ROP_PDSnox      equ   004B0605h
  ROP_SDPana      equ   004C0CC8h
  ROP_SSPxDSxoxn  equ   004D1954h
  ROP_PDSPxox     equ   004E0645h
  ROP_PDSnoan     equ   004F0E25h
  ROP_PDna        equ   00500325h
  ROP_DSPnaon     equ   00510B26h
  ROP_DPSDaox     equ   005206C9h
  ROP_SPDSxaxn    equ   00530764h
  ROP_DPSonon     equ   005408A9h
  ROP_Dn          equ   00550009h   ;DSTINVERT
  ROP_DPSox       equ   005601A9h
  ROP_DPSoan      equ   00570389h
  ROP_PDSPoax     equ   00580785h
  ROP_DPSnox      equ   00590609h
  ROP_DPx         equ   005A0049h   ;PATINVERT
  ROP_DPSDonox    equ   005B18A9h
  ROP_DPSDxox     equ   005C0649h
  ROP_DPSnoan     equ   005D0E29h
  ROP_DPSDnaox    equ   005E1B29h
  ROP_DPan        equ   005F00E9h
  ROP_PDSxa       equ   00600365h
  ROP_DSPDSaoxxn  equ   006116C6h
  ROP_DSPDoax     equ   00620786h
  ROP_SDPnox      equ   00630608h
  ROP_SDPSoax     equ   00640788h
  ROP_DSPnox      equ   00650606h
  ROP_DSx         equ   00660046h   ;SRCINVERT
  ROP_SDPSonox    equ   006718A8h
  ROP_DSPDSonoxxn equ   006858A6h
  ROP_PDSxxn      equ   00690145h
  ROP_DPSax       equ   006A01E9h
  ROP_PSDPSoaxxn  equ   006B178Ah
  ROP_SDPax       equ   006C01E8h
  ROP_PDSPDoaxxn  equ   006D1785h
  ROP_SDPSnoax    equ   006E1E28h
  ROP_PDSxnan     equ   006F0C65h
  ROP_PDSana      equ   00700CC5h
  ROP_SSDxPDxaxn  equ   00711D5Ch
  ROP_SDPSxox     equ   00720648h
  ROP_SDPnoan     equ   00730E28h
  ROP_DSPDxox     equ   00740646h
  ROP_DSPnoan     equ   00750E26h
  ROP_SDPSnaox    equ   00761B28h
  ROP_DSan        equ   007700E6h
  ROP_PDSax       equ   007801E5h
  ROP_DSPDSoaxxn  equ   00791786h
  ROP_DPSDnoax    equ   007A1E29h
  ROP_SDPxnan     equ   007B0C68h
  ROP_SPDSnoax    equ   007C1E24h
  ROP_DPSxnan     equ   007D0C69h
  ROP_SPxDSxo     equ   007E0955h
  ROP_DPSaan      equ   007F03C9h
  ROP_DPSaa       equ   008003E9h
  ROP_SPxDSxon    equ   00810975h
  ROP_DPSxna      equ   00820C49h
  ROP_SPDSnoaxn   equ   00831E04h
  ROP_SDPxna      equ   00840C48h
  ROP_PDSPnoaxn   equ   00851E05h
  ROP_DSPDSoaxx   equ   008617A6h
  ROP_PDSaxn      equ   008701C5h
  ROP_DSa         equ   008800C6h   ;SRCAND
  ROP_SDPSnaoxn   equ   00891B08h
  ROP_DSPnoa      equ   008A0E06h
  ROP_DSPDxoxn    equ   008B0666h
  ROP_SDPnoa      equ   008C0E08h
  ROP_SDPSxoxn    equ   008D0668h
  ROP_SSDxPDxax   equ   008E1D7Ch
  ROP_PDSanan     equ   008F0CE5h
  ROP_PDSxna      equ   00900C45h
  ROP_SDPSnoaxn   equ   00911E08h
  ROP_DPSDPoaxx   equ   009217A9h
  ROP_SPDaxn      equ   009301C4h
  ROP_PSDPSoaxx   equ   009417AAh
  ROP_DPSaxn      equ   009501C9h
  ROP_DPSxx       equ   00960169h
  ROP_PSDPSonoxx  equ   0097588Ah
  ROP_SDPSonoxn   equ   00981888h
  ROP_DSxn        equ   00990066h
  ROP_DPSnax      equ   009A0709h
  ROP_SDPSoaxn    equ   009B07A8h
  ROP_SPDnax      equ   009C0704h
  ROP_DSPDoaxn    equ   009D07A6h
  ROP_DSPDSaoxx   equ   009E16E6h
  ROP_PDSxan      equ   009F0345h
  ROP_DPa         equ   00A000C9h
  ROP_PDSPnaoxn   equ   00A11B05h
  ROP_DPSnoa      equ   00A20E09h
  ROP_DPSDxoxn    equ   00A30669h
  ROP_PDSPonoxn   equ   00A41885h
  ROP_PDxn        equ   00A50065h
  ROP_DSPnax      equ   00A60706h
  ROP_PDSPoaxn    equ   00A707A5h
  ROP_DPSoa       equ   00A803A9h
  ROP_DPSoxn      equ   00A90189h
  ROP_D           equ   00AA0029h
  ROP_DPSono      equ   00AB0889h
  ROP_SPDSxax     equ   00AC0744h
  ROP_DPSDaoxn    equ   00AD06E9h
  ROP_DSPnao      equ   00AE0B06h
  ROP_DPno        equ   00AF0229h
  ROP_PDSnoa      equ   00B00E05h
  ROP_PDSPxoxn    equ   00B10665h
  ROP_SSPxDSxox   equ   00B21974h
  ROP_SDPanan     equ   00B30CE8h
  ROP_PSDnax      equ   00B4070Ah
  ROP_DPSDoaxn    equ   00B507A9h
  ROP_DPSDPaoxx   equ   00B616E9h
  ROP_SDPxan      equ   00B70348h
  ROP_PSDPxax     equ   00B8074Ah   ;MAGICROP => Halftone
  ROP_DSPDaoxn    equ   00B906E6h
  ROP_DPSnao      equ   00BA0B09h
  ROP_DSno        equ   00BB0226h   ;MERGEPAINT
  ROP_SPDSanax    equ   00BC1CE4h
  ROP_SDxPDxan    equ   00BD0D7Dh
  ROP_DPSxo       equ   00BE0269h
  ROP_DPSano      equ   00BF08C9h
  ROP_PSa         equ   00C000CAh   ;MERGECOPY
  ROP_SPDSnaoxn   equ   00C11B04h
  ROP_SPDSonoxn   equ   00C21884h
  ROP_PSxn        equ   00C3006Ah
  ROP_SPDnoa      equ   00C40E04h
  ROP_SPDSxoxn    equ   00C50664h
  ROP_SDPnax      equ   00C60708h
  ROP_PSDPoaxn    equ   00C707AAh
  ROP_SDPoa       equ   00C803A8h
  ROP_SPDoxn      equ   00C90184h
  ROP_DPSDxax     equ   00CA0749h
  ROP_SPDSaoxn    equ   00CB06E4h
  ROP_S           equ   00CC0020h   ;SRCCOPY
  ROP_SDPono      equ   00CD0888h
  ROP_SDPnao      equ   00CE0B08h
  ROP_SPno        equ   00CF0224h
  ROP_PSDnoa      equ   00D00E0Ah
  ROP_PSDPxoxn    equ   00D1066Ah
  ROP_PDSnax      equ   00D20705h
  ROP_SPDSoaxn    equ   00D307A4h
  ROP_SSPxPDxax   equ   00D41D78h
  ROP_DPSanan     equ   00D50CE9h
  ROP_PSDPSaoxx   equ   00D616EAh
  ROP_DPSxan      equ   00D70349h
  ROP_PDSPxax     equ   00D80745h
  ROP_SDPSaoxn    equ   00D906E8h
  ROP_DPSDanax    equ   00DA1CE9h
  ROP_SPxDSxan    equ   00DB0D75h
  ROP_SPDnao      equ   00DC0B04h
  ROP_SDno        equ   00DD0228h
  ROP_SDPxo       equ   00DE0268h
  ROP_SDPano      equ   00DF08C8h
  ROP_PDSoa       equ   00E003A5h
  ROP_PDSoxn      equ   00E10185h
  ROP_DSPDxax     equ   00E20746h   ;MAGICROP_2
  ROP_PSDPaoxn    equ   00E306EAh
  ROP_SDPSxax     equ   00E40748h
  ROP_PDSPaoxn    equ   00E506E5h
  ROP_SDPSanax    equ   00E61CE8h
  ROP_SPxPDxan    equ   00E70D79h
  ROP_SSPxDSxax   equ   00E81D74h
  ROP_DSPDSanaxxn equ   00E95CE6h
  ROP_DPSao       equ   00EA02E9h
  ROP_DPSxno      equ   00EB0849h
  ROP_SDPao       equ   00EC02E8h
  ROP_SDPxno      equ   00ED0848h
  ROP_DSo         equ   00EE0086h   ;SRCPAINT
  ROP_SDPnoo      equ   00EF0A08h
  ROP_P           equ   00F00021h   ;PATCOPY
  ROP_PDSono      equ   00F10885h
  ROP_PDSnao      equ   00F20B05h
  ROP_PSno        equ   00F3022Ah
  ROP_PSDnao      equ   00F40B0Ah
  ROP_PDno        equ   00F50225h
  ROP_PDSxo       equ   00F60265h
  ROP_PDSano      equ   00F708C5h
  ROP_PDSao       equ   00F802E5h
  ROP_PDSxno      equ   00F90845h
  ROP_DPo         equ   00FA0089h
  ROP_DPSnoo      equ   00FB0A09h   ;PATPAINT
  ROP_PSo         equ   00FC008Ah
  ROP_PSDnoo      equ   00FD0A0Ah
  ROP_DPSoo       equ   00FE02A9h
  ROP_1           equ   00FF0062h   ;WHITENESS

  SetShellAssociationA proto :DWORD, :POINTER, :POINTER, :POINTER, :POINTER
  SetShellAssociationW proto :DWORD, :POINTER, :POINTER, :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    SetShellAssociation textequ <SetShellAssociationA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    SetShellAssociation textequ <SetShellAssociationW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  SetShellPerceivedTypeA proto :DWORD, :POINTER, :POINTER
  SetShellPerceivedTypeW proto :DWORD, :POINTER, :POINTER
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    SetShellPerceivedType textequ <SetShellPerceivedTypeA>
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    SetShellPerceivedType textequ <SetShellPerceivedTypeW>
  else
    echo Warning: incompatible TARGET_STR_TYPE
  endif

  EHandler proto :POINTER, :POINTER, :POINTER, :POINTER
endif

IsPntInRect proto :POINTER, :POINTER
Random32 proto :DWORD
IsGUIDEqual proto :POINTER, :POINTER
IsHardwareFeaturePresent proto :BYTE
NewObjInst proto :DWORD
UTF8ToWide proto :POINTER, :POINTER, :DWORD
WideToUTF8 proto :POINTER, :POINTER, :DWORD
Real4ToHalf proto :REAL4


;Radix Sort procedures
RadixSortI32 proto :POINTER, :DWORD, :POINTER
RadixSortPtrI32 proto :POINTER, :DWORD, :DWORD, :POINTER
RadixSortUI32 proto :POINTER, :DWORD, :POINTER
RadixSortPtrUI32 proto :POINTER, :DWORD, :DWORD, :POINTER
RadixSortF32 proto :POINTER, :DWORD, :POINTER
RadixSortPtrF32 proto :POINTER, :DWORD, :DWORD, :POINTER
RadixSortF64 proto :POINTER, :DWORD, :POINTER
RadixSortPtrF64 proto :POINTER, :DWORD, :DWORD, :POINTER


;CRC32 procedures
aCRC32C proto :POINTER, :DWORD
uCRC32C proto :POINTER, :DWORD

;PDF View
PdfViewA proto :HANDLE, :POINTER, :POINTER
PdfViewW proto :HANDLE, :POINTER, :POINTER
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  PdfView textequ <PdfViewA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  PdfView textequ <PdfViewW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

;Simple Linear Regression
SLR_DATA struc
  pData       POINTER   ?   ;In
  xCount      XWORD     ?   ;In
  r8Slope     REAL8     ?   ;Out
  r8Intercept REAL8     ?   ;Out
  r8MSE       REAL8     ?   ;Out
  r8X         REAL8     ?   ;Internal use
  r8X2        REAL8     ?   ;Internal use
  r8Q         REAL8     ?   ;Internal use
SLR_DATA ends
PSLR_DATA typedef ptr SLR_DATA

SLR_Init            proto :PSLR_DATA
SLR_Calc_AB_DW      proto :PSLR_DATA
SLR_Calc_AB_QW      proto :PSLR_DATA
SLR_Calc_AB_R4      proto :PSLR_DATA
SLR_Calc_AB_R8      proto :PSLR_DATA
SLR_Calc_AB_MSE_DW  proto :PSLR_DATA
SLR_Calc_AB_MSE_QW  proto :PSLR_DATA
SLR_Calc_AB_MSE_R4  proto :PSLR_DATA
SLR_Calc_AB_MSE_R8  proto :PSLR_DATA

CalcVarianceDW    proto :POINTER, :XWORD, :POINTER
CalcVarianceQW    proto :POINTER, :XWORD, :POINTER
CalcVarianceR4    proto :POINTER, :XWORD, :POINTER
CalcVarianceR8    proto :POINTER, :XWORD, :POINTER


_chkstk proto c
_alloca_probe_8 proto c
_alloca_probe_16 proto c
_alloca_8  equ _alloca_probe_8
_alloca_16 equ _alloca_probe_16


;IsHardwareFeaturePresent equates
IHFP_FPU    equ   00    ;FP coprocessor
IHFP_VME    equ   01    ;Virtual 8086 Enhancements
IHFP_DE     equ   02    ;Debugging Extensions
IHFP_PSE    equ   03    ;Page Size Extension
IHFP_TSC    equ   04    ;Availability of RDTSC instruction
IHFP_MSR    equ   05    ;Availability of RDMSR and WRMSR instructions
IHFP_PAE    equ   06    ;Physical Address Extension
IHFP_MCE    equ   07    ;Machine Check Exception
IHFP_CX8    equ   08    ;Availability of CMPXCH8B instruction
IHFP_APIC   equ   09    ;Advanced Programmable Interrupt Controller present
;Reserved   equ   10    ;Reserved for Intel CPUs
IHFP_SEP    equ   11    ;Availability of SYSENTER and SYSEXIT instructions
IHFP_MTTR   equ   12    ;Memory type range registers present
IHFP_PGE    equ   13    ;PTE Global Bits present
IHFP_MCA    equ   14    ;Machine Check Architecture present
IHFP_CMOV   equ   15    ;Availability of CMOVxx instructions
IHFP_PAT    equ   16    ;Page Attribute Table present
IHFP_PSE36  equ   17    ;Extended 4MB page size
IHFP_PSN    equ   18    ;Processor Serial Number (96 bit)
IHFP_CLFSH  equ   19    ;Availability of CLFLUSH instruction
;Reserved   equ   20    ;Reserved for Intel CPUs
IHFP_DS     equ   21    ;Debug Store present
IHFP_ACPI   equ   22    ;The processor has MSRs to monitor its temperaure
IHFP_MMX    equ   23    ;Availability of MMX technology
IHFP_FXSR   equ   24    ;Availability of FXSAVE anf FXSTOR instructions
IHFP_SSE    equ   25    ;Availability of SSE technology
IHFP_SSE2   equ   26    ;Availability of SSE2 technology
IHFP_SS     equ   27    ;Self Snoop
IHFP_HT     equ   28    ;Availability of HyperThreading
IHFP_TM     equ   29    ;Thermal monitor present
;Reserved   equ   30    ;Reserved for Intel CPUs
IHFP_3DNOW2 equ   30    ;Extended 3DNow technology only for AMD processors
IHFP_PBE    equ   31    ;Pending Break Enable for Intel CPUs
IHFP_3DNOW  equ   31    ;3DNow technology only for AMD processors for AMD CPUs
IHFP_SSE3   equ   32    ;Availability of SSE3 technology


;Objects
if TARGET_BITNESS eq 64
  XWordVector equ QWordVector
  XVEC_MAX_CAPACITY equ VEC64_MAX_CAPACITY
else
  XWordVector equ DWordVector
  XVEC_MAX_CAPACITY equ VEC32_MAX_CAPACITY
endif



