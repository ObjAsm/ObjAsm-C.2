; ==================================================================================================
; Title:      DB_Routines.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database general purpose routines.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


.const
dmSecPerDay   DWORD   86400000                          ;24*60*60*1000

CStrW wBlanks, $RepChr(< >, 256)
CStrA bBlanks, $RepChr(< >, 256)
CStrA bZeros,  $RepChr(0, 256)
CStrA bLogic,  "F"

.code

; --------------------------------------------------------------------------------------------------
; Procedure:  CreateTempFile
; Purpose:    Create a temporary file.
; Arguments:  None.
; Return:     xax = File HANDLE or INVALID_HANDLE_VALUE.

align ALIGN_CODE
CreateTempFile proc
  local cTmpFileName[MAX_PATH*sizeof(CHR)]:CHR, cTmpFilePath[(MAX_PATH + 1)*sizeof(CHR)]:CHR

  ;Get a temp path env string (no guarantee it's a valid path).
  invoke GetTempPath, MAX_PATH, addr cTmpFilePath
  .if eax > MAX_PATH || eax == 0
    mov xax, INVALID_HANDLE_VALUE
  .else
    invoke GetTempFileName, addr cTmpFilePath, $OfsCStr("DB_"), 0, addr cTmpFileName
    .if eax == 0
      mov xax, INVALID_HANDLE_VALUE
    .else
      invoke CreateFile, addr cTmpFileName, GENERIC_WRITE or GENERIC_READ, 0, NULL, CREATE_ALWAYS, \
                         FILE_ATTRIBUTE_TEMPORARY or FILE_FLAG_DELETE_ON_CLOSE, NULL
    .endif
  .endif
  ret
CreateTempFile endp

; --------------------------------------------------------------------------------------------------
; Procedure:  GetPhysicalSectorSize
; Purpose:    Obtain the physical sector size of a storage device.
; Arguments:  Arg1: -> Any path on the storage device.
; Return:     eax = Physical sector size in bytes.

align ALIGN_CODE
GetPhysicalSectorSize proc pPath:PSTRING
  local hDevice:HANDLE, dBytesReturned:DWORD
  local BufferIn:STORAGE_PROPERTY_QUERY, BufferOut:STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR
  local cDevicePath[7*sizeof(CHR)]:CHR
  local cFullFileNameBuffer[MAX_PATH*sizeof(CHR)]:CHR

  invoke GetFullPathName, pPath, lengthof(cFullFileNameBuffer), addr cFullFileNameBuffer, NULL
  invoke PathGetDriveNumber, addr cFullFileNameBuffer
  .if eax == -1
    xor eax, eax
  .else
    FillString cDevicePath, <\\.\_!:>                   ;_ is a placeholder for the drive letter
    add $SubReg(eax, sizeof(CHR)), "A"
    mov CHR ptr cDevicePath[4*sizeof(CHR)], $SubReg(eax, sizeof(CHR))
    mov BufferIn.PropertyId, StorageAccessAlignmentProperty
    mov BufferIn.QueryType, PropertyStandardQuery
    m2z BufferIn.AdditionalParameters
    mov BufferOut.Version, sizeof(STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR)
    mov BufferOut.Size_, sizeof(BufferOut)
    m2z BufferOut.BytesPerPhysicalSector
    mov hDevice, $invoke(CreateFile, addr cDevicePath, 0, \   ;dwDesiredAccess = 0 !!!
                         FILE_SHARE_READ or FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0)
    invoke DeviceIoControl, hDevice, IOCTL_STORAGE_QUERY_PROPERTY, \
                            addr BufferIn, sizeof(BufferIn), \
                            addr BufferOut, sizeof(BufferOut), \
                            addr dBytesReturned, NULL
    invoke CloseHandle, hDevice
    mov eax, BufferOut.BytesPerPhysicalSector
;    mov eax, DB_DEFAULT_SECTOR_SIZE                ;For test purposes only
  .endif
  ret
GetPhysicalSectorSize endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_GetStdFieldInfo
; Purpose:    Get information about standard field types, like the length of fix sized fields.
; Arguments:  Arg1: Field type.
; Return:     xax -> FieldInfo.

.const
align ALIGN_DATA
StdFieldLookupTable label STD_FIELD_INFO
;  STD_FIELD_INFO {FDT_BINARY,    10, KTM_BIN, SFF_MEMO or SFF_NO_VISUAL or SSF_NO_INDEX, \
;                  $OfsTStr("B: Binary"),      SFM_BLANKA,   0}

  STD_FIELD_INFO {FDT_CHAR_ANSI, 00, KTM_ANSI, 0, \
                  $OfsTStr("C: ANSI Char"),   SFM_BLANKA,   0}

  STD_FIELD_INFO {FDT_DATE,      08, KTM_ANSI, 0, \
                  $OfsTStr("D: Date"),        SFM_BLANKA,   10}

  STD_FIELD_INFO {FDT_REAL4,     04, KTM_REAL, 0, \
                  $OfsTStr("F: Float"),       SFM_ZERO,     36}

;  STD_FIELD_INFO {FDT_OLE,       10, KTM_NONE, SFF_MEMO or SFF_NO_VISUAL or SSF_NO_INDEX, \
;                  $OfsTStr("G: OLE"),         SFM_BLANKA,   0}

  STD_FIELD_INFO {FDT_SDWORD,    04, KTM_BIN,  0, \
                  $OfsTStr("I: Integer 32"),  SFM_ZERO,     36}

  STD_FIELD_INFO {FDT_BOOL,      01, KTM_ANSI, 0, \
                  $OfsTStr("L: Logical"),     SFM_LOGIC,    1}

;  STD_FIELD_INFO {FDT_MEMO_ANSI,  10, KTM_NONE, SFF_MEMO or SSF_NO_INDEX, \
;                  $OfsTStr("M: ANSI Memo"),   SFM_BLANKA,   0}

  STD_FIELD_INFO {FDT_NUMERIC,   00, KTM_ANSI, SFF_HAS_PARAM, \
                  $OfsTStr("N: Numeric"),     SFM_BLANKA,   0}

  STD_FIELD_INFO {FDT_REAL8,     08, KTM_REAL, 0, \
                  $OfsTStr("O: Double"),      SFM_ZERO,     36}

  STD_FIELD_INFO {FDT_REAL10,    10, KTM_REAL, 0, \
                  $OfsTStr("T: REAL10"),      SFM_ZERO,     36}

  STD_FIELD_INFO {FDT_CURRENCY,  08, KTM_REAL, 0, \
                  $OfsTStr("Y: Currency"),    SFM_ZERO,     36}

  STD_FIELD_INFO {FDT_CHAR_WIDE, 00, KTM_WIDE, 0, \
                  $OfsTStr("W: WIDE Char"),   SFM_BLANKW,   0}

  STD_FIELD_INFO {FDT_CHAR_UTF8, 00, KTM_UTF8, 0, \
                  $OfsTStr("8: UTF8 Char"),   SFM_BLANKA,   0}

  STD_FIELD_INFO {FDT_TIMESTAMP, 08, KTM_BIN,  SFF_READ_ONLY, \
                  $OfsTStr("@: Timestamp"),   SFM_NOW,      0}

  STD_FIELD_INFO {FDT_AUTOINC,   04, KTM_BIN,  SFF_HAS_PARAM or SFF_READ_ONLY or SFF_WRITE_SETUP, \
                  $OfsTStr("+: Autoinc"),     SFM_AUTOINC,  11}
  BYTE  0

.code
align ALIGN_CODE
DB_GetStdFieldInfo proc bType:BYTE
  mov cl, bType
  mov xax, offset StdFieldLookupTable
  .while TRUE
    mov dl, [xax].STD_FIELD_INFO.bType
    .break .if dl == cl || dl == 0
    add xax, sizeof(STD_FIELD_INFO)
  .endw
  ret
DB_GetStdFieldInfo endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_StrToNum
; Purpose:    Type converstion routine from string to FDT_NUMBER format.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Input string.
;             Arg3: Database number length.
;             Arg4: Database number decimals.
; Return:     eax: error code:
;                  0 = Success, BIT00: integer loss, BIT01: fractional loss, BIT02: wrong input
;                  In case of failure, the output is filled with spaces.

align ALIGN_CODE
DB_StrToNum proc uses xbx xdi xsi pDstNum:PSTRINGA, pSrcStr:PSTRING, dNumLen:DWORD, dDecimals:DWORD
  local pSeparator:POINTER, pLast:POINTER, pStrEnd:POINTER
  local xIntLen:XWORD, dStrLength:DWORD, dResult:DWORD

  .if pDstNum == NULL
    mov eax, BIT02
    ret
  .endif
  mov xdi, pSrcStr
  cmp xdi, NULL
  jz @@Error

  ;Check for Leading "+" or "-" and remove spaces
  CharReg equ $SubReg(ecx, sizeof(CHR))
  mov xdi, pSrcStr
  .while TRUE
    mov CharReg, [xdi]
    .if CharReg == "+"
      add xdi, sizeof(CHR)
      add pSrcStr, sizeof(CHR)
      .break
    .elseif CharReg == "-"
      add xdi, sizeof(CHR)
      .break
    .elseif CharReg == " " || CharReg == 9
      add xdi, sizeof(CHR)
      add pSrcStr, sizeof(CHR)
      .continue
    .else
      .break
    .endif
  .endw

  ;Check for alpha chars
  xor ebx, ebx
  .while TRUE
    mov CharReg, [xdi]
    .break .if CharReg == 0
    .if CharReg == "."
      inc ebx
    .else
      .if !$IsCharTypeA?(CharReg, CharTypeNumeric)
        jmp @@Error
      .endif
    .endif
    add xdi, sizeof(CHR)
  .endw
  .if ebx > 1
    jmp @@Error
  .endif

  ;Calculate the integer length.
  mov xdi, pSrcStr
  mov ecx, dNumLen
  mov eax, dDecimals
  .if eax != 0
    sub ecx, eax
    dec ecx                                             ;1 for the decimal point
  .endif
  mov xIntLen, xcx

  ;Get the length of the source string.
  mov ecx, -1
  xor eax, eax
  repne scasc
  not ecx
  dec ecx
  jz @@Error

  ;Set StrLength, StrEnd and locate the position of the decimal separator
  mov dStrLength, ecx
  sub xdi, sizeof(CHR)
  mov pStrEnd, xdi
  mov xdi, pSrcStr
  mov $SubReg(eax, sizeof(CHR)), "."
  repne scasc                                           ;ecx = length of source string
  mov xax, NULL                                         ;Dont't change flags!
  .if ZERO?
    lea xax, [xdi - sizeof(CHR)]
  .endif
  mov pSeparator, xax

  ;Process the integer part of the string.
  .if xax != NULL
    sub xax, pSrcStr
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      shr eax, 1
    endif
    .if eax <= DWORD ptr xIntLen
      mov dResult, 0
      ;Pad with spaces
      mov ecx, DWORD ptr xIntLen
      sub ecx, eax
      mov ebx, eax
      mov xdi, pDstNum
      lea xdx, [xdi + xcx*sizeof(CHRA)]
      mov al, " "
      rep stosb
      ;Copy the integer part
      mov ecx, ebx
      mov xdi, xdx
      mov xsi, pSrcStr
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        rep movsb
      else
        test ecx, ecx
        .while !ZERO?
          movsb
          inc xsi
          dec ecx
        .endw
      endif
    .else
      mov dResult, BIT00
      jmp @@Error
    .endif

    ;If there is no "0" in front of the decimal separator, then put it.
    .if CHRA ptr [xdi - sizeof(CHRA)] == " "
      mov CHRA ptr [xdi - sizeof(CHRA)], "0"
    .endif

    ;Process the fractional part of the string.
    .if dDecimals > 0
      mov al, "."
      stosb
      mov pLast, xdi
      mov xcx, pStrEnd
      sub xcx, pSeparator
      if TARGET_STR_TYPE eq STR_TYPE_WIDE
        shr ecx, 1
      endif
      dec ecx
      mov edx, dDecimals
      .if ecx < edx
        sub edx, ecx
        ;Copy fractional part and fill with "0".
        mov xsi, pSeparator
        add xsi, sizeof(CHR)
        mov xdi, pLast
        if TARGET_STR_TYPE eq STR_TYPE_ANSI
          rep movsb
        else
          test ecx, ecx
          .while !ZERO?
            movsb
            inc xsi
            dec ecx
          .endw
        endif
        mov ecx, edx
        mov al, "0"
        rep stosb
      .else
        ;Copy truncated fractional part.
        BitSet dResult, BIT01
        mov ecx, dDecimals
        mov xsi, pSeparator
        add xsi, sizeof(CHR)
        mov xdi, pLast
        if TARGET_STR_TYPE eq STR_TYPE_ANSI
          rep movsb
        else
          test ecx, ecx
          .while !ZERO?
            movsb
            inc xsi
            dec ecx
          .endw
        endif
      .endif
    .endif

  .else
    ;No decimal separator found.
    mov ecx, dStrLength
    .if ecx <= DWORD ptr xIntLen
      mov dResult, 0
      ;Pad with spaces
      sub ecx, DWORD ptr xIntLen
      neg ecx
      mov xdi, pDstNum
      lea xdx, [xdi + xcx*sizeof(CHR)]
      mov al, " "
      rep stosb
      ;Copy the integer part.
      mov ecx, dStrLength
      mov xsi, pSrcStr
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        rep movsb
      else
        test ecx, ecx
        .while !ZERO?
          movsb
          inc xsi
          dec ecx
        .endw
      endif
    .else
      mov dResult, BIT00
      jmp @@Error
    .endif
    .if CHRA ptr [xdi - sizeof(CHRA)] == " "
      mov CHRA ptr [xdi - sizeof(CHRA)], "0"
    .endif
    .if dDecimals > 0
      ;Set decimal separator and "0"s.
      mov al, "."
      stosb
      mov ecx, dDecimals
      mov al, "0"
      rep stosb
    .endif
  .endif
  mov eax, dResult
  ret

@@Error:
  mov xdi, pDstNum
  mov ecx, dNumLen
  mov edx, ecx
  mov eax, "    "
  shr ecx, 2
  rep stosd
  mov ecx, edx
  and ecx, 3
  rep stosb
  mov eax, BIT02
  ret
DB_StrToNum endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_NumToStr
; Purpose:    Type converstion routine from DB_NUM format to string.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: -> Source database number.
;             Arg3: Database number length.
; Return:     Nothing.

align ALIGN_CODE
DB_NumToStr proc uses xdi xsi pDstString:PSTRING, pSrcNumber:POINTER, dNumLen:DWORD
  mov xdi, pSrcNumber
  mov al, " "
  mov ecx, dNumLen
  repe scasb
  lea xsi, [xdi - 1]
  mov xdi, pDstString
  inc ecx
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    rep movsb
  else
    xor eax, eax
    test ecx, ecx
    .while !ZERO?
      lodsb
      stosw
      dec ecx
    .endw
  endif
  mov CHR ptr [xdi], 0
  ret
DB_NumToStr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_StrToDate
; Purpose:    Type converstion routine from string to FDT_DATE (YYYYMMDD).
; Arguments:  Arg1: -> Destination buffer (8 bytes).
;             Arg2: -> Source string.
;             Arg3: String format (FDF_xxx).
; Return:     eax = Error code. 0 = success, 1 = unknown format.

FDF_ENTRY struc 1
  bID           BYTE  ?
  bDayOffset    BYTE  ?
  bMonthOffset  BYTE  ?
  bYearOffset   BYTE  ?
  bYearLength   BYTE  ?
FDF_ENTRY ends

.const
align ALIGN_DATA
DBASE_DATE_FORMATS label FDF_ENTRY
FDF_ENTRY {FDF_DD?MM?YYYY, 0, 3, 6, 4}
FDF_ENTRY {FDF_DD?MM?YY,   0, 3, 6, 2}
FDF_ENTRY {FDF_MM?DD?YYYY, 3, 0, 6, 4}
FDF_ENTRY {FDF_MM?DD?YY,   3, 0, 6, 2}
FDF_ENTRY {FDF_YYYY?MM?DD, 8, 5, 0, 4}
FDF_ENTRY {FDF_YY?MM?DD,   6, 3, 0, 2}
BYTE FDF_END_OF_TABLE

.code
align ALIGN_CODE
DB_StrToDate proc uses xbx xdi xsi pDstDate:PSTRING, pSrcString:POINTER, bFormat:BYTE
  local LocalTime:SYSTEMTIME, bYear[10]:CHRA

  mov xbx, offset(DBASE_DATE_FORMATS)
  .repeat
    mov al, [xbx].FDF_ENTRY.bID
    .break .if al == FDF_END_OF_TABLE || al == bFormat
    add xbx, sizeof(FDF_ENTRY)
  .until FALSE
  .if al == FDF_END_OF_TABLE
    mov eax, 1
  .else
    mov xdi, pDstDate
    mov xsi, pSrcString
    ;Get the year
    .if [xbx].FDF_ENTRY.bYearLength == 2
      ;Complete with current century
      invoke GetLocalTime, addr LocalTime
      movzx eax, LocalTime.wYear
      and eax, 1FFFh
      invoke dword2decA, addr bYear, eax
      mov ax, WORD ptr [bYear]
      mov [xdi], ax
      add xdi, 2
      ;Copy the following 2 digits from year information
      movzx ecx, [xbx].FDF_ENTRY.bYearOffset
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        mov ax, [xsi + xcx]
      else
        mov eax, [xsi + xcx*sizeof(CHRW)]
        mov dl, al
        shr eax, 8
        mov al, dl
      endif
      mov [xdi], ax
      add xdi, 2
    .else
      movzx ecx, [xbx].FDF_ENTRY.bYearOffset
      mov xax, [xsi + xcx*sizeof(CHR)]
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        mov [xdi], eax
      else
        mov dl, al
        shr xax, 8
        mov al, dl
        mov [xdi], ax
        if TARGET_BITNESS eq 32
          mov eax, [esi + ecx + 4]
        else
          shr xax, 24
        endif
        mov dl, al
        shr xax, 8
        mov al, dl
        mov [xdi + 2], ax
      endif
      add xdi, 4
    .endif

    ;Get the month
    movzx ecx, [xbx].FDF_ENTRY.bMonthOffset
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov ax, [xsi + xcx]
      mov [xdi], ax
    else
      mov eax, [xsi + xcx*sizeof(CHRW)]
      mov dl, al
      shr eax, 8
      mov al, dl
      mov [xdi], ax
    endif
    add xdi, 2

    ;Get the day
    movzx ecx, [xbx].FDF_ENTRY.bDayOffset
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov ax, [xsi + xcx]
      mov [xdi], ax
    else
      mov eax, [xsi + xcx*sizeof(CHRW)]
      mov dl, al
      shr eax, 8
      mov al, dl
      mov [xdi], ax
    endif
  .endif
  ret
DB_StrToDate endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_DateToStr
; Purpose:    Type converstion routine from FDT_DATE to string.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: -> Source date.
;             Arg3: String format (FDF_xxx).
;             Arg4: Separator character.
; Return:     Error code. 0 = success, 1 = unknown format.

align ALIGN_CODE
DB_DateToStr proc uses xbx xdi xsi pDstString:PSTRING, pSrcDate:POINTER, bFormat:BYTE, cSeparator:CHR
  mov xbx, offset(DBASE_DATE_FORMATS)
  .repeat
    mov al, [xbx].FDF_ENTRY.bID
    .break .if al == FDF_END_OF_TABLE || al == bFormat
    add xbx, sizeof(FDF_ENTRY)
  .until FALSE
  .if al == FDF_END_OF_TABLE
    mov eax, 1
  .else
    ;Start with the year
    mov xsi, pSrcDate
    mov xdi, pDstString
    movzx ecx, [xbx].FDF_ENTRY.bYearOffset
    .if [xbx].FDF_ENTRY.bYearLength == 4
      mov eax, [xsi]
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        mov [xdi + xcx], eax
      else
        movzx dx, ah
        shl edx, 16
        movzx dx, al
        mov [xdi + xcx*sizeof(CHRW)], edx
        shr eax, 16
        movzx dx, ah
        shl edx, 16
        movzx dx, al
        mov [xdi + xcx*sizeof(CHRW) + 2*sizeof(CHRW)], edx
      endif
    .else
      mov ax, [xsi + 2]
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        mov [xdi + xcx], ax
      else
        movzx dx, ah
        shl edx, 16
        movzx dx, al
        mov [xdi + xcx*sizeof(CHRW)], edx
      endif
    .endif
    add xsi, 4

    ;Copy the month
    movzx ecx, [xbx].FDF_ENTRY.bMonthOffset
    mov ax, [xsi]
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov [xdi + xcx], ax
    else
      movzx dx, ah
      shl edx, 16
      movzx dx, al
      mov [xdi + xcx*sizeof(CHRW)], edx
    endif
    add xsi, 2

    ;Copy the day
    movzx ecx, [xbx].FDF_ENTRY.bDayOffset
    mov ax, [xsi]
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov [xdi + xcx], ax
    else
      movzx dx, ah
      shl edx, 16
      movzx dx, al
      mov [xdi + xcx*sizeof(CHRW)], edx
    endif

    ;Set the separator characters
    mov $SubReg(eax, sizeof(CHR)), cSeparator
    mov xdi, pDstString
    movzx ecx, [xbx].FDF_ENTRY.bDayOffset
    .if ecx != 0
      mov [xdi + xcx*sizeof(CHR) - sizeof(CHR)], $SubReg(eax, sizeof(CHR))
    .endif
    movzx ecx, [xbx].FDF_ENTRY.bMonthOffset
    .if ecx != 0
      mov [xdi + xcx*sizeof(CHR) - sizeof(CHR)], $SubReg(eax, sizeof(CHR))
    .endif
    movzx ecx, [xbx].FDF_ENTRY.bYearOffset
    .if ecx != 0
      mov [xdi + xcx*sizeof(CHR) - sizeof(CHR)], $SubReg(eax, sizeof(CHR))
    .endif

    ;Set ZTC
    xor eax, eax                                        ;eax = Return value = 0
    .if [xbx].FDF_ENTRY.bYearLength == 2
      mov [xdi + 8*sizeof(CHR)], $SubReg(eax, sizeof(CHR))
    .else
      mov [xdi + 10*sizeof(CHR)], $SubReg(eax, sizeof(CHR))
    .endif
  .endif
  ret
DB_DateToStr endp

align ALIGN_CODE
DB_DateToStrW proc uses xbx xdi xsi pDstString:PSTRING, pSrcDate:POINTER, bFormat:BYTE, cSeparator:CHR
  mov xbx, offset(DBASE_DATE_FORMATS)
  .repeat
    mov al, [xbx].FDF_ENTRY.bID
    .break .if al == FDF_END_OF_TABLE || al == bFormat
    add xbx, sizeof(FDF_ENTRY)
  .until FALSE
  .if al == FDF_END_OF_TABLE
    mov eax, 1
  .else
    ;Start with the year
    mov xsi, pSrcDate
    mov xdi, pDstString
    movzx ecx, [xbx].FDF_ENTRY.bYearOffset
    .if [xbx].FDF_ENTRY.bYearLength == 4
      mov eax, [xsi]
      movzx dx, ah
      shl edx, 16
      movzx dx, al
      mov [xdi + xcx*sizeof(CHRW)], edx
      shr eax, 16
      movzx dx, ah
      shl edx, 16
      movzx dx, al
      mov [xdi + xcx*sizeof(CHRW) + 2*sizeof(CHRW)], edx
    .else
      mov ax, [xsi + 2]
      movzx dx, ah
      shl edx, 16
      movzx dx, al
      mov [xdi + xcx*sizeof(CHRW)], edx
    .endif
    add xsi, 4

    ;Copy the month
    movzx ecx, [xbx].FDF_ENTRY.bMonthOffset
    mov ax, [xsi]
    movzx dx, ah
    shl edx, 16
    movzx dx, al
    mov [xdi + xcx*sizeof(CHRW)], edx
    add xsi, 2

    ;Copy the day
    movzx ecx, [xbx].FDF_ENTRY.bDayOffset
    mov ax, [xsi]
    movzx dx, ah
    shl edx, 16
    movzx dx, al
    mov [xdi + xcx*sizeof(CHRW)], edx

    ;Set the separator characters
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      movzx $SubReg(eax, sizeof(CHRW)), cSeparator
    else
      mov $SubReg(eax, sizeof(CHRW)), cSeparator
    endif
    mov xdi, pDstString
    movzx ecx, [xbx].FDF_ENTRY.bDayOffset
    .if ecx != 0
      mov [xdi + xcx*sizeof(CHRW) - sizeof(CHRW)], $SubReg(eax, sizeof(CHRW))
    .endif
    movzx ecx, [xbx].FDF_ENTRY.bMonthOffset
    .if ecx != 0
      mov [xdi + xcx*sizeof(CHRW) - sizeof(CHRW)], $SubReg(eax, sizeof(CHRW))
    .endif
    movzx ecx, [xbx].FDF_ENTRY.bYearOffset
    .if ecx != 0
      mov [xdi + xcx*sizeof(CHRW) - sizeof(CHRW)], $SubReg(eax, sizeof(CHRW))
    .endif

    ;Set ZTC
    xor eax, eax                                        ;eax = Return value = 0
    .if [xbx].FDF_ENTRY.bYearLength == 2
      mov [xdi + 8*sizeof(CHRW)], $SubReg(eax, sizeof(CHRW))
    .else
      mov [xdi + 10*sizeof(CHRW)], $SubReg(eax, sizeof(CHRW))
    .endif
  .endif
  ret
DB_DateToStrW endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_DateToJDN
; Purpose:    Converstion routine from Gregorian date to Julian Date Number.
; Arguments:  Arg1: Year.
;             Arg2: Month.
;             Arg3: Day.
; Return:     eax = Julian Day Number.
; Note:       Requires ConstDiv.inc
;
; 1. Express the date as Y M D, where Y is the year, M is the month number
;    (Jan = 1, Feb = 2, etc.), and D is the day in the month.
; 2. If the month is January or February, subtract 1 from the year to get a new Y, and add 12 to the
;    month to get a new M. (Thus, we are thinking of January and February as being the 13th and 14th
;    month of the previous year).
; 3. Dropping the fractional part of all results of all multiplications and divisions, let
;
;      A = Y/100
;      B = A/4
;      C = 2-A+B
;      E = 365.25x(Y+4716)
;      F = 30.6001x(M+1)
;      JD= C+D+E+F-1524

align ALIGN_CODE
DB_DateToJDN proc uses xbx dYear:DWORD, dMonth:DWORD, dDay:DWORD
  .if dMonth <= 2
    dec dYear
    add dMonth, 12
  .endif
  mov eax, dYear
  icdiv 100

  mov ebx, 2
  sub ebx, edx
  sar edx, 2
  add ebx, edx          ;ebx = C

  mov eax, dYear
  add eax, 4716
  mov ecx, 1461         ;4*365.25
  mul ecx
  shr eax, 2            ;/4
  add ebx, eax          ;ebx = C + E

  mov eax, dMonth
  inc eax
  mov ecx, 306001
  mul ecx
  cdiv 10000
  add ebx, edx          ;ebx = C + E + F

  mov eax, ebx
  add eax, dDay
  sub eax, 1524
  ret
DB_DateToJDN endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_JDNToDate
; Purpose:    Converstion routine from Julian Date Number to Gregorian date.
; Arguments:  Arg1: Julian Date Number.
; Return:     eax = Day.
;             edx = Month.
;             ecx = Year.
; Note:       Requires ConstDiv.inc
;
; This method will not give dates accurately on the Gregorian Proleptic Calendar, that is, the
; calendar you get by extending the Gregorian calendar backwards to years earlier than 1582 using
; the Gregorian leap year rules. In particular, this method fails if date < 01.03.0400
; (Julian Date Count < 1867217).
;
;      Z = JD
;      W = (Z - 1867216.25)/36524.25
;      X = W/4
;      A = Z+1+W-X
;      B = A+1524
;      C = (B-122.1)/365.25
;      D = 365.25xC
;      E = (B-D)/30.6001
;      F = 30.6001xE
;      Day of month = B-D-F
;      Month = E-1 or E-13 (must get number less than or equal to 12)
;      Year = C-4715 (if Month is January or February) or C-4716 (otherwise).

align ALIGN_CODE
DB_JDNToDate proc uses xbx xdi xsi dJDC:DWORD
  mov ebx, dJDC
  lea eax, [4*ebx - 7468865]
  cdiv 146097
  inc ebx
  add ebx, edx
  shr edx, 2
  sub ebx, edx
  add ebx, 1524       ;ebx = B

  mov eax, 40
  mul ebx
  sub eax, 4884
  cdiv 14610
  mov edi, edx        ;edi = C
  mov eax, 1461
  mul edi
  shr eax, 2
  sub ebx, eax        ;ebx = B - D
  mov eax, 10000
  mul ebx
  cdiv 306001
  mov esi, edx        ;esi = E

  mov eax, 306001
  mul edx
  cdiv 10000          ;edx = F
  mov eax, ebx
  sub eax, edx        ;eax = Day
  mov edx, esi
  dec edx
  .if edx > 12
    sub edx, 12       ;edx = Month
  .endif
  lea ecx, [edi - 4715]
  .if edx > 2
    dec ecx           ;ecx = Year
  .endif
  ret
DB_JDNToDate endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_Real4ToStr
; Purpose:    Type converstion routine from FDT_REAL4 to string.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: -> REAL4.
;             Arg3: Decimals.
; Return:     Error code (f_OK, f_ERROR, f_NAN, ...).

align ALIGN_CODE
DB_Real4ToStr proc pDstString:PSTRING, pSrcReal4:POINTER, dDecimals:DWORD
  ?mov xdx, pSrcReal4
  fld REAL4 ptr [xdx]
  ?mov xcx, pDstString
  invoke St0ToStr, xcx, 0, dDecimals, f_NOR
  fUnload
  .if eax != f_OK
    mov xcx, pDstString
    mov CHR ptr [xcx], 0
  .endif
  ret
DB_Real4ToStr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_StrToReal4
; Purpose:    Type converstion routine from a string to FDT_REAL4.
; Arguments:  Arg1: -> Destination REAL4 buffer (4 bytes).
;             Arg2: -> REAL4 string.
; Return:     Error code (f_OK, f_ERROR, f_NAN, ...).

align ALIGN_CODE
DB_StrToReal4 proc pDstReal4:POINTER, pSrcString:PSTRING
  invoke StrToSt0, pSrcString
  mov xcx, pDstReal4
  .if eax == f_OK
    fstp REAL4 ptr [xcx]
  .else
    fUnload
    if TARGET_BITNESS eq 32
      mov edx, "    "
      mov [ecx], edx
    else
      mov edx, "    "
      mov [rcx], edx
    endif
  .endif
  ret
DB_StrToReal4 endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_Real8ToStr
; Purpose:    Type converstion routine from FDT_REAL8 to string.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: -> REAL8.
;             Arg3: Decimals.
; Return:     Error code (f_OK, f_ERROR, f_NAN, ...).

align ALIGN_CODE
DB_Real8ToStr proc pDstString:PSTRING, pSrcReal8:POINTER, dDecimals:BYTE
  ?mov xdx, pSrcReal8
  fld REAL8 ptr [xdx]
  ?mov xcx, pDstString
  invoke St0ToStr, xcx, 0, dDecimals, f_NOR
  fUnload
  .if eax != f_OK
    mov xcx, pDstString
    mov CHR ptr [xcx], 0
  .endif
  ret
DB_Real8ToStr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_StrToReal8
; Purpose:    Type converstion routine from a string to FDT_REAL8.
; Arguments:  Arg1: -> Destination REAL8 buffer (8 bytes).
;             Arg2: -> Currency string.
; Return:     Error code (f_OK, f_ERROR, f_NAN, ...).

align ALIGN_CODE
DB_StrToReal8 proc pDstReal8:POINTER, pSrcString:PSTRING
  invoke StrToSt0, pSrcString
  mov xcx, pDstReal8
  .if eax == f_OK
    fstp REAL8 ptr [xcx]
  .else
    fUnload
    if TARGET_BITNESS eq 32
      mov edx, "    "
      mov [ecx], edx
      mov [ecx + 4], edx
    else
      mov rdx, "        "
      mov [rcx], rdx
    endif
  .endif
  ret
DB_StrToReal8 endp

DB_Currency2Str textequ <DB_Real8ToStr>
DB_Str2Currency textequ <DB_StrToReal8>

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_Real10ToStr
; Purpose:    Type converstion routine from FDT_REAL10 to string.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: -> REAL10.
;             Arg3: Decimals.
; Return:     Error code (f_OK, f_ERROR, f_NAN, ...).

align ALIGN_CODE
DB_Real10ToStr proc pDstString:PSTRING, pSrcReal10:POINTER, dDecimals:DWORD
  ?mov xdx, pSrcReal10
  fld REAL10 ptr [xdx]
  ?mov xcx, pDstString
  invoke St0ToStr, xcx, 0, dDecimals, f_NOR
  fUnload
  DbgStr pDstString
  DbgHex eax
  .if eax != f_OK
    mov xcx, pDstString
    mov CHR ptr [xcx], 0
  .endif
  ret
DB_Real10ToStr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_StrToReal10
; Purpose:    Type converstion routine from a string to FDT_REAL10.
; Arguments:  Arg1: -> Destination REAL10 buffer (10 bytes).
;             Arg2: -> REAL10 string.
; Return:     Error code (f_OK, f_ERROR, f_NAN, ...).

align ALIGN_CODE
DB_StrToReal10 proc pDstReal10:POINTER, pSrcString:PSTRING
  invoke StrToSt0, pSrcString
  mov xcx, pDstReal10
  .if eax == f_OK
    fstp REAL10 ptr [xcx]
  .else
    fUnload
    if TARGET_BITNESS eq 32
      mov edx, "    "
      mov [ecx], edx
      mov [ecx + 4], edx
      mov [ecx + 8], dx
    else
      mov rdx, "        "
      mov [rcx], rdx
      mov [ecx + 8], dx
    endif
  .endif
  ret
DB_StrToReal10 endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_LogicalToStr
; Purpose:    Type converstion routine from Logical to string.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: -> Logical.
; Return:     Error code.

align ALIGN_CODE
DB_LogicalToStr proc pDstString:PSTRING, pSrcLogical:POINTER
  ?mov xcx, pDstString
  ?mov xdx, pSrcLogical
  mov al, CHRA ptr [xdx]
  BitClr al, BIT05                                      ;Convert to uppercase
  .if al == "F"
    FillString [xcx], <FALSE>
  .elseif al == "T"
    FillString [xcx], <TRUE>
  .else
    m2z CHR ptr [xcx]
  .endif
  xor eax, eax
  ret
DB_LogicalToStr endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_StrToLogical
; Purpose:    Type converstion routine from string to Logical.
; Arguments:  Arg1: -> Logical.
;             Arg2: -> Source string.
; Return:     Error code.

align ALIGN_CODE
DB_StrToLogical proc uses xbx pDstLogical:PSTRING, pSrcString:PSTRING
  xor ebx, ebx
  invoke StrIComp, pSrcString, $OfsCStr("T")
  test eax, eax
  setz bl
  .if !ZERO?
    invoke StrIComp, pSrcString, $OfsCStr("TRUE")
    test eax, eax
    setz bl
    .if !ZERO?
      invoke StrIComp, pSrcString, $OfsCStr("Y")
      test eax, eax
      setz bl
      .if !ZERO?
        invoke StrIComp, pSrcString, $OfsCStr("YES")
        test eax, eax
        setz bl
        .if !ZERO?
          invoke StrIComp, pSrcString, $OfsCStr("F")
          test eax, eax
          setz bh
          .if !ZERO?
            invoke StrIComp, pSrcString, $OfsCStr("FALSE")
            test eax, eax
            setz bh
            .if !ZERO?
              invoke StrIComp, pSrcString, $OfsCStr("N")
              test eax, eax
              setz bh
              .if !ZERO?
                invoke StrIComp, pSrcString, $OfsCStr("NO")
                test eax, eax
                setz bh
              .endif
            .endif
          .endif
        .endif
      .endif
    .endif
  .endif

  mov xcx, pDstLogical
  .if bl != 0
    mov CHRA ptr [xcx], "T"
  .elseif bh != 0
    mov CHRA ptr [xcx], "F"
  .else
    mov CHRA ptr [xcx], " "
  .endif
  xor eax, eax
  ret
DB_StrToLogical endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_NowToTimestamp
; Purpose:    Stamp now UTC.
; Arguments:  Arg1: -> TimeStamp.
; Return:     Nothing.
; Note        Date = Julian Date Number.
;             Time = hours*3600000L + minutes*60000L + Seconds*1000L + Milliseconds.

align ALIGN_CODE
DB_NowToTimestamp proc uses xbx pTimeStamp:POINTER
  local SysTime:SYSTEMTIME

  invoke GetSystemTime, addr SysTime

  ;Encode Time
  movzx eax, SysTime.wHour
  mov ecx, 3600000
  mul ecx
  mov ebx, eax
  movzx eax, SysTime.wMinute
  mov ecx, 60000
  mul ecx
  add ebx, eax
  movzx eax, SysTime.wSecond
  mov ecx, 1000
  mul ecx
  add ebx, eax
  movzx eax, SysTime.wMilliseconds
  add ebx, eax

  ;Encode Date
  movzx ecx, SysTime.wYear
  movzx edx, SysTime.wMonth
  movzx eax, SysTime.wDay
  invoke DB_DateToJDN, ecx, edx, eax

  ;Store Date and Time
  mov xcx, pTimeStamp
  mov [xcx], eax
  mov [xcx + 4], ebx

  ret
DB_NowToTimestamp endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_TimeToMS
; Purpose:    Compute the input time to miliseconds.
; Arguments:  Arg1: Hours.
;             Arg2: Minutes.
;             Arg3: Seconds.
;             Arg4: Milliseconds.
; Return:     eax = Milliseconds
;             Time = hours*3600000L + minutes*60000L + Seconds*1000L + Milliseconds.

align ALIGN_CODE
DB_TimeToMS proc uses xbx dHours:DWORD, dMinutes:DWORD, dSeconds:DWORD, dMilliSecs:DWORD
  mov eax, dHours
  mov ecx, 3600000
  mul ecx
  mov ebx, eax
  mov eax, dMinutes
  mov ecx, 60000
  mul ecx
  add ebx, eax
  mov eax, dSeconds
  mov ecx, 1000
  mul ecx
  add ebx, eax
  mov eax, dMilliSecs
  add eax, ebx
  ret
DB_TimeToMS endp

; --------------------------------------------------------------------------------------------------
; Procedure:  DB_TimestampToStr
; Purpose:    Convert TimeStamp to string.
; Arguments:  Arg1: -> Destination string.
;             Arg2: -> TimeStamp.
; Return:     Nothing.
; Format:     YYYY/MM/DD HH:MM:SS.MMM
;             Time = hours*3600000L + minutes*60000L + Seconds*1000L + Miliseconds.

align ALIGN_CODE
DB_TimestampToStr proc pDstString:PSTRING, pTimeStamp:POINTER
  local dYear:DWORD, dMonth:DWORD, dDay:DWORD
  local dHours:DWORD, dMinutes:DWORD, dSeconds:DWORD, dMilliSeconds:DWORD

  ?mov xdx, pTimeStamp
  .if $DoesTextMatch?([xdx], !<        >)
    ?mov xcx, pDstString
    m2z CHR ptr [xcx]
  .else
    mov ecx, [xdx]
    mov eax, [xdx + 4]
    cDivMod 3600000
    mov dHours, eax
    mov eax, edx
    cDivMod 60000
    mov dMinutes, eax
    mov eax, edx
    cDivMod 1000
    mov dSeconds, eax
    mov dMilliSeconds, edx

    invoke DB_JDNToDate, ecx                            ;eax = Day, edx = Month, ecx = Year
    mov dDay, eax
    mov dMonth, edx
    mov dYear, ecx

    invoke wsprintf, pDstString, $OfsCStr("%04d/%02u/%02u %02u:%02u:%02u.%03u"), \
                     dYear, dMonth, dDay, dHours, dMinutes, dSeconds, dMilliSeconds
  .endif
  ret
DB_TimestampToStr endp


; --------------------------------------------------------------------------------------------------
; Procedure:  MUT_xxx
; Purpose:    Field mutation procedures called from DB_StructEditorDlg.Mutate.
; Arguments:  Arg1: -> Output buffer.
;             Arg2: -> Input buffer.
;             Arg3: -> FIELD_MUTATION data.
; Return:     eax = 0 if operation succeeded.
; Note:       In most cases, 2 procs are called (see MutationLUT). The first converts the source
;             field data to a common representation in a buffer or converts it to the FPU st(0).
;             The second procedure converts this middle representation or FPU-value to the
;             destination field type.

align ALIGN_CODE
MUT_CopyData proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  invoke MemClone, pOut, pIn, eax
  xor eax, eax
  ret
MUT_CopyData endp

align ALIGN_CODE
MUT_CopyDataFillA proc uses xdi xsi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx esi, [xcx].FIELD_MUTATION.bActLength
  movzx edi, [xcx].FIELD_MUTATION.bPrvLength
  cmp edi, esi
  cmovg edi, esi
  invoke MemClone, pOut, pIn, edi
  sub esi, edi
  .if !SIGN?
    mov al, " "
    mov ecx, esi
    add xdi, pOut
    rep stosb
  .endif
  xor eax, eax
  ret
MUT_CopyDataFillA endp

align ALIGN_CODE
MUT_CopyDataFillW proc uses xdi xsi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx esi, [xcx].FIELD_MUTATION.bActLength
  movzx edi, [xcx].FIELD_MUTATION.bPrvLength
  cmp edi, esi
  cmovg edi, esi
  invoke MemClone, pOut, pIn, edi
  sub esi, edi
  .if !SIGN?
    mov ax, " "
    mov ecx, esi
    inc ecx
    shr ecx, 1
    add xdi, pOut
    rep stosw
  .endif
  xor eax, eax
  ret
MUT_CopyDataFillW endp

align ALIGN_CODE
MUT_FillBlank proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bActLength
  invoke MemClone, pOut, offset(bBlanks), eax
  xor eax, eax
  ret
MUT_FillBlank endp

align ALIGN_CODE
MUT_DeleteMemo proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  ;Not implemented
  mov eax, -1
  ret
MUT_DeleteMemo endp


;In - procedures ---------------------------------------

align ALIGN_CODE
MUT_ChrAToBuf proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  invoke MultiByteToWideChar, CP_ACP, 0, pIn, eax, pOut, LOCAL_BUFFER_SIZE
  shl xax, 1
  add xax, pOut
  m2z CHRW ptr [xax]                                    ;Set ZTC
  xor eax, eax
  ret
MUT_ChrAToBuf endp

align ALIGN_CODE
MUT_ChrWToBuf proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  invoke StrCCopyW, pOut, pIn, eax
  xor eax, eax
  ret
align ALIGN_CODE
MUT_ChrWToBuf endp

align ALIGN_CODE
MUT_Chr8ToBuf proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  invoke MultiByteToWideChar, CP_UTF8, 0, pIn, eax, pOut, LOCAL_BUFFER_SIZE
  ;Return: eax = Chars written
  shl eax, 1                                            ;Convert to bytes
  add xax, pOut
  mov CHRW ptr [xax], 0
  xor eax, eax
  ret
MUT_Chr8ToBuf endp

align ALIGN_CODE
MUT_DateToBuf proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  mov xax, [xcx].FIELD_MUTATION.pAppSetup
  invoke DB_DateToStrW, pOut, pIn, [xax].APP_SETUP.bDateFormat, [xax].APP_SETUP.cDateSeparator
  ret
MUT_DateToBuf endp

align ALIGN_CODE
MUT_DateToFpu proc uses xbx pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  local bBuffer[100]:CHRA, dYear:DWORD, dMonth:DWORD, dDay:DWORD, dJDN:DWORD

  mov xbx, pIn
  .if $DoesTextMatchA?([xbx], !<        >)
    mov eax, -1
  .else
    mov eax, [xbx]
    mov DWORD ptr [bBuffer], eax
    mov CHRA ptr [bBuffer + 4], 0
    mov dYear, $32($invoke(dec2dwordA, addr bBuffer))
    add xbx, 4
    mov ax, [xbx]
    mov WORD ptr [bBuffer], ax
    mov CHRA ptr [bBuffer + 2], 0
    mov dMonth, $32($invoke(dec2dwordA, addr bBuffer))
    add xbx, 2
    mov ax, [xbx]
    mov WORD ptr [bBuffer], ax
    mov CHRA ptr [bBuffer + 2], 0
    mov dDay, $32($invoke(dec2dwordA, addr bBuffer))
    invoke DB_DateToJDN, dYear, dMonth, dDay
    mov dJDN, eax
    fild dJDN
    xor eax, eax
  .endif
  ret
MUT_DateToFpu endp

align ALIGN_CODE
MUT_NumToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  invoke DB_NumToStr, pOut, pIn, eax
  invoke StrRTrim, pOut, pOut
  invoke StrToSt0, pOut                                 ;ret eax = f_OK
  ret
MUT_NumToFpu endp

align ALIGN_CODE
MUT_NumToNum proc uses xbx xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xax, pMutInfo
  mov edx, [xax].FIELD_MUTATION.dPrvParam
  mov ebx, [xax].FIELD_MUTATION.dActParam
  sub xbx, xdx
  movzx edx, [xax].FIELD_MUTATION.bPrvLength
  movzx ecx, [xax].FIELD_MUTATION.bActLength
  mov eax, [xax].FIELD_MUTATION.dActParam
  sub eax, ecx
  inc eax
  .if SIGN?
    sub xcx, xdx
    sub xcx, xbx
    .if !SIGN?
      mov xdi, pOut
      add pOut, xcx
      mov al, " "
      rep stosb
    .else
      sub pIn, xcx
      add xdx, xcx
    .endif
    mov xax, pMutInfo
    .if SDWORD ptr ebx < 0
      add xdx, xbx
      .if [xax].FIELD_MUTATION.dActParam == 0       ;If = 0 => no decimal point needed
        mov xcx, pOut
        mov CHRA ptr [xcx], " "
        inc pOut
        dec xdx
      .endif
    .endif
    .if ebx > 0 && [xax].FIELD_MUTATION.dPrvParam == 0    ;If = 0 => decimal point needed
      inc pIn
      dec xdx
    .endif
    mov xdi, pOut
    add xdi, xdx
    mov eax, edx
    invoke MemClone, pOut, pIn, eax

    .if SDWORD ptr ebx > 0
      mov xax, pMutInfo
      .if [xax].FIELD_MUTATION.dPrvParam == 0       ;If = 0 => decimal point needed
        mov CHRA ptr [xdi], "."
        inc xdi
      .endif
      mov ecx, ebx
      mov al, "0"
      rep stosb
    .endif
    xor eax, eax
  .else
    mov eax, -1
  .endif
  ret
MUT_NumToNum endp

align ALIGN_CODE
MUT_R4ToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  .if $DoesTextMatchA?([xcx], !<    >)
    mov eax, -1
  .else
    fld REAL4 ptr [xcx]
    xor eax, eax
  .endif
  ret
MUT_R4ToFpu endp

align ALIGN_CODE
MUT_R8ToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  .if $DoesTextMatchA?([xcx], !<        >)
    mov eax, -1
  .else
    fld REAL8 ptr [xcx]
    xor eax, eax
  .endif
  ret
MUT_R8ToFpu endp

align ALIGN_CODE
MUT_R10ToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  .if $DoesTextMatchA?([xcx], !<          >)
    mov eax, -1
  .else
    fld REAL10 ptr [xcx]
    xor eax, eax
  .endif
  ret
MUT_R10ToFpu endp

align ALIGN_CODE
MUT_BoolToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  mov al, [xcx]
  .if al == " "
    mov eax, -1
  .else
    .if al == "T" || al == "t" || al == "Y" || al == "y" || al == "1"
      fld1
    .else
      fldz
    .endif
    xor eax, eax
  .endif
  ret
MUT_BoolToFpu endp

align ALIGN_CODE
MUT_Int32ToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  .if $DoesTextMatchA?([xcx], !<    >)
    mov eax, -1
  .else
    fild DWORD ptr [xcx]
    xor eax, eax
  .endif
  ret
MUT_Int32ToFpu endp

align ALIGN_CODE
MUT_UInt32ToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  .if $DoesTextMatchA?([xcx], !<    >)
    mov eax, -1
  .else
    fild DWORD ptr [xcx]
    xor eax, eax
  .endif
  ret
align ALIGN_CODE
MUT_UInt32ToFpu endp

align ALIGN_CODE
MUT_ChrAToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  mov xdx, pIn
  m2z CHRA ptr [xdx + xax]                              ;Set ZTC
  invoke StrLRTrimA, pIn, pIn
  invoke StrToSt0A, pIn                                 ;Ret eax = f_OK
  ret
MUT_ChrAToFpu endp

align ALIGN_CODE
MUT_ChrWToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  mov xdx, pIn
  m2z CHRW ptr [xdx + xax]                              ;Set ZTC
  invoke StrLRTrimW, pIn, pIn
  invoke StrToSt0W, pIn
  ret
MUT_ChrWToFpu endp

align ALIGN_CODE
MUT_Chr8ToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  mov xdx, pIn
  m2z CHRA ptr [xdx + xax]                              ;Set ZTC
  invoke StrLRTrimA, pIn, pIn
  invoke StrToSt0A, pIn
  ret
MUT_Chr8ToFpu endp

align ALIGN_CODE
MUT_TimestampToFpu proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pIn
  fild DWORD ptr [xcx + 4]
  fild dmSecPerDay
  fdivp st(1), st(0)
  fiadd DWORD ptr [xcx]
  ret
MUT_TimestampToFpu endp


;Out - procedures --------------------------------------

align ALIGN_CODE
MUT_BufToChrFillA proc uses xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx edi, [xcx].FIELD_MUTATION.bActLength
  invoke WideCharToMultiByte, CP_ACP, 0, pIn, edi, pOut, LOCAL_BUFFER_SIZE, NULL, NULL
  ;eax = Number of bytes written to the buffer
  .if eax < edi
    mov ecx, edi
    sub ecx, eax
    mov xdi, pOut
    add xdi, xax
    mov al, " "
    rep stosb
  .endif
  xor eax, eax
  ret
MUT_BufToChrFillA endp

align ALIGN_CODE
MUT_BufToChrFillW proc uses xbx xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx ebx, [xcx].FIELD_MUTATION.bPrvLength
  movzx edi, [xcx].FIELD_MUTATION.bActLength
  invoke MemClone, pOut, pIn, ebx
  .if ebx < edi
    mov ecx, edi
    sub ecx, ebx
    inc ecx                                             ;Round up
    shr ecx, 1
    mov xdi, pOut
    add xdi, xbx
    mov ax, " "
    rep stosw
  .endif
  xor eax, eax
  ret
MUT_BufToChrFillW endp

align ALIGN_CODE
MUT_BufToChr8 proc uses xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bPrvLength
  movzx edi, [xcx].FIELD_MUTATION.bActLength
  invoke WideCharToMultiByte, CP_UTF8, 0, pIn, eax, pOut, LOCAL_BUFFER_SIZE, NULL, NULL
  .if eax < edi
    mov ecx, edi
    sub ecx, eax
    mov xdi, pOut
    add xdi, xax
    mov al, " "
    rep stosb
  .endif
  xor eax, eax
  ret
MUT_BufToChr8 endp

align ALIGN_CODE
MUT_BufToMemo proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  ;Not implemented
  mov eax, -1
  ret
MUT_BufToMemo endp

align ALIGN_CODE
MUT_BufToBool proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  ?mov xcx, pOut
  ?mov xdx, pIn
  mov al, CHRA ptr [xdx]
  mov CHRA ptr [xcx], al
  xor eax, eax
  ret
MUT_BufToBool endp

align ALIGN_CODE
MUT_BufToNum proc uses xbx pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx ebx, [xcx].FIELD_MUTATION.bActLength
  mov eax, [xcx].FIELD_MUTATION.dActParam
  movzx ebx, [xcx].FIELD_MUTATION.bPrvLength
  invoke StrLRTrimW, pIn, pIn
  invoke DB_StrToNum, pOut, pIn, ebx, eax
  xor eax, eax
  ret
MUT_BufToNum endp

align ALIGN_CODE
MUT_BufToDate proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  mov xax, [xcx].FIELD_MUTATION.pAppSetup
  invoke DB_StrToDate, pOut, pIn, [xax].APP_SETUP.bDateFormat ;FDF_YYYY?MM?DD
  xor eax, eax
  ret
MUT_BufToDate endp


align ALIGN_CODE
MUT_FpuToChrA proc uses xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx edx, [xcx].FIELD_MUTATION.bActLength

  .if edx > 35
    mov ecx, edx
    sub ecx, 35
    mov al, " "
    mov xdi, pOut
    add pOut, xcx
    rep stosb
  .endif

  .if edx <= 15
    xor eax, eax
  .else
    sub edx, 15
    mov eax, edx
    mov edx, 15
  .endif
  invoke St0ToStrA, pOut, edx, eax, f_NOR
  fUnload
  xor eax, eax
  ret
MUT_FpuToChrA endp

align ALIGN_CODE
MUT_FpuToChrW proc uses xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pMutInfo
  movzx edx, [xcx].FIELD_MUTATION.bActLength

  .if edx > 35
    mov ecx, edx
    sub ecx, 35
    mov al, " "
    mov xdi, pOut
    add pOut, xcx
    rep stosb
  .endif

  .if edx <= 15
    xor eax, eax
  .else
    sub edx, 15
    mov eax, edx
    mov edx, 15
  .endif
  invoke St0ToStrW, pOut, edx, eax, f_NOR
  fUnload
  xor eax, eax
  ret
MUT_FpuToChrW endp

align ALIGN_CODE
MUT_FpuToInt32 proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fistp DWORD ptr [xcx]
  xor eax, eax
  ret
MUT_FpuToInt32 endp

align ALIGN_CODE
MUT_FpuToUInt32 proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fistp DWORD ptr [xcx]
  xor eax, eax
  ret
MUT_FpuToUInt32 endp

align ALIGN_CODE
MUT_FpuToNum proc uses xdi pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  invoke St0ToStr, pIn, 0, 15, f_NOR
  fUnload
  invoke StrLRTrim, pIn, pIn
  mov xcx, pMutInfo
  movzx eax, [xcx].FIELD_MUTATION.bActLength
  mov edi, [xcx].FIELD_MUTATION.dActParam
  invoke DB_StrToNum, pOut, pIn, eax, edi               ;Ret eax = 0: success
  xor eax, eax
  ret
MUT_FpuToNum endp

align ALIGN_CODE
MUT_FpuToR4 proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fstp REAL4 ptr [xcx]
  xor eax, eax
  ret
MUT_FpuToR4 endp

align ALIGN_CODE
MUT_FpuToR8 proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fstp REAL8 ptr [xcx]
  xor eax, eax
  ret
MUT_FpuToR8 endp

align ALIGN_CODE
MUT_FpuToR10 proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fstp REAL10 ptr [xcx]
  xor eax, eax
  ret
MUT_FpuToR10 endp

align ALIGN_CODE
MUT_FpuToTimestamp proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fist DWORD ptr [xcx]                                  ;JDC
  fFrac
  fild dmSecPerDay
  fmulp st(1), st(0)
  fistp DWORD ptr [xcx + 4]                             ;mSec
  xor eax, eax
  ret
MUT_FpuToTimestamp endp

align ALIGN_CODE
MUT_FpuToDate proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  local dJDC:DWORD, dMonth:DWORD, dYear:dWORD

  fistp dJDC
  invoke DB_JDNToDate, dJDC                             ;eax = Day, edx = Month, ecx = Year
  mov dMonth, edx
  mov dYear, ecx
  invoke wsprintfA, pOut, $OfsCStrA("%04u%02u%02u"), dYear, dMonth, eax
  xor eax, eax
  ret
MUT_FpuToDate endp

align ALIGN_CODE
MUT_FpuToBool proc pOut:POINTER, pIn:POINTER, pMutInfo:PFIELD_MUTATION
  mov xcx, pOut
  fldz
  fcomip st(0), st(1)
  fUnload
  .if ZERO?
    mov CHRA ptr [xcx], "F"
  .else
    mov CHRA ptr [xcx], "T"
  .endif
  xor eax, eax
  ret
MUT_FpuToBool endp


; --------------------------------------------------------------------------------------------------
; Procedure:  MemoPutBmp
; Purpose:    Store a bitmap in the memo file.
; Arguments:  Arg1: -> DB_Memo.
;             Arg2: Bitmap HANDLE.
; Return:     eax = Error code.
;             ecx: first BlockNo.

align ALIGN_CODE
MemoPutBmp proc uses xbx pMemo:$ObjPtr(DB_Memo), hBmp:HANDLE
  local hDC:HDC, BMI:BITMAPINFO, dSize:DWORD
  
  mov hDC, $invoke(GetDC, 0)

  ;Get the Bitmap attributes
  mov BMI.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)    ;No RGBQUAD array 
  m2z BMI.bmiHeader.biBitCount
  invoke GetDIBits, hDC, hBmp, 0, 1, NULL, addr BMI, DIB_RGB_COLORS   ;Fill only BITMAPINFO

  ;Get memory for bitmap bits and set DIB properties we want
  mov eax, BMI.bmiHeader.biWidth
  mul BMI.bmiHeader.biHeight
  shl eax, $Log2(sizeof(RGBQUAD))
  mov BMI.bmiHeader.biSizeImage, eax
  add eax, sizeof(BITMAPINFO)
  mov dSize, eax
  MemAlloc eax
  mov xbx, xax
  mov BMI.bmiHeader.biBitCount, 32
  mov BMI.bmiHeader.biCompression, BI_RGB
  s2s BITMAPINFO ptr [xbx], BMI, xax, xcx, xdx
  lea xax, [xbx + sizeof(BITMAPINFO)]
  invoke GetDIBits, hDC, hBmp, 0, BMI.bmiHeader.biHeight, xax, xbx, DIB_RGB_COLORS
  invoke ReleaseDC, 0, hDC

  ;Store the bitmap information
  OCall pMemo::DB_Memo.Put, xbx, dSize
  ret
MemoPutBmp endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MemoGetBmp
; Purpose:    Retrieve a bitmap from memo file.
; Arguments:  Arg1: -> DB_Memo.
;             Arg2: First BlockNo to start loading the bitmap.
; Return:     eax = Error code.
;             ecx = Bitmap HANDLE.

align ALIGN_CODE
MemoGetBmp proc uses xbx pMemo:$ObjPtr(DB_Memo), dBlockNo:DWORD
  local hDC:HDC, hBmp:HBITMAP

  mov hDC, $invoke(GetDC, 0)
  OCall pMemo::DB_Memo.GetFrom, dBlockNo
  .if eax == OBJ_OK
    mov xbx, xcx
    mov hBmp, $invoke(CreateCompatibleBitmap, hDC, [xbx].BITMAPINFO.bmiHeader.biWidth, \
                                                   [xbx].BITMAPINFO.bmiHeader.biHeight)  
    lea xax, [xbx + sizeof(BITMAPINFO)]
    invoke SetDIBits, hDC, hBmp, 0, [xbx].BITMAPINFO.bmiHeader.biHeight, xax, xbx, DIB_RGB_COLORS
    invoke ReleaseDC, 0, hDC
    MemFree xbx
    xor eax, eax
    mov xcx, hBmp
  .else
    xor ecx, ecx
  .endif
  ret
MemoGetBmp endp

;Example:
;  OCall [xsi].Img1::Image.Init, xsi
;  OCall [xsi].Img1::Image.LoadFromRes, $OfsCStr("IMG1")
;
;  OCall [xsi].Table.Memo::DB_Memo.Init, xsi
;  OCall [xsi].Table.Memo::DB_Memo.New, $OfsCStr("Memo.dbt"), DB_DEFAULT_MEMO_BLOCK_LEN, TRUE
;
;  mov hDC, $invoke(GetDC, [xsi].hWnd)
;  mov hBmp, $OCall([xsi].Img1::Image.GetCompatibleBmp, hDC)
;  invoke ReleaseDC, [xsi].hWnd, hDC
;  invoke MemoPutBmp, addr [xsi].Table.Memo, hBmp 
;  mov dBlockNo, ecx 
;  ...
;  invoke MemoGetBmp, addr [xsi].Table.Memo, dBlockNo
;  DbgBmp xcx
;  ...
;
;  OCall [xsi].Table.Memo::DB_Memo.Close
  



