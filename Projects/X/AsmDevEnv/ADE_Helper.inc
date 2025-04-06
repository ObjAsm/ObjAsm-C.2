; ==================================================================================================
; Title:      ADE_Helper.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GetCharType
; Purpose:    Return the type (CHR_XXX) from a given character. 
; Arguments:  Arg1: Character in a 32 bit register.
;             Arg2: 32 bit register containing the character type.
; Return:     Arg2

GetCharType macro CharReg32:req, TypeReg32:req
  .if CharReg32 < CHAR_TABLE_ENTRIES
    lea $SubReg(TypeReg32, sizeof(XWORD)), CharTable
    ;Lookup char type
    movzx TypeReg32, BYTE ptr [$SubReg(TypeReg32, sizeof(XWORD)) + $SubReg(CharReg32, sizeof(XWORD))]
  .else
    mov TypeReg32, CHR_WORD                               ;All other characters are word chars
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LimitXXXXIndex
; Purpose:    Limit the horizontal/vertical caret index to the end of line/last line.
; Arguments:  Arg1: Horizontal index.
;             Arg2: Vertical Index.
; Return:     eax = new horizontal/vertical index.
; Note:       xsi -> EditorView.

LimitHorzIndex macro IndexX:req, IndexY:req
  OCall xsi.VertIndex2TextLine, IndexY
  .if xax != NULL
    mov edx, [xax].$Obj(EditorTextLine).dLength
    mov eax, IndexX
    sub edx, [xsi].d1stVisCharIndex
    cmp eax, edx
    cmova eax, edx
  .endif
endm

LimitVertIndex macro IndexY:req
  ;Limit the y position to the last visible EditorTextLine
  mov xax, [xsi].p1stVisLine
  xor edx, edx
  .while xax != NULL                                ;Search the last visible EditorTextLine
    mov xcx, xax
    GotoNextVisTextLine xax
    .break .if xax == NULL
    inc edx
  .endw
  mov eax, IndexY
  cmp eax, edx
  cmova eax, edx                                    ;On exit xcx -> last visible line
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GotoXXXVisLine
; Purpose:    Return the EditorTextLine pointer of the prev/next visible line.
; Arguments:  Arg1: -> Current EditorTextLine (Can not be NULL).
;             Arg2: (optional) Register containing the number of lines to skip. Can't be eax.
;             Arg3: (optional) Register returning the number of skipped lines. Can't be eax.
;             Arg4: (optional) Register returning the number of skipped visible lines. Can't be eax.
; Return:     xax -> Prev/Next EditorTextLine or NULL if the count could not be reached.
;             Arg3 = Number of lines skipped.
;             Arg4 = Number of visible lines skipped.

GotoNextVisTextLine macro CurrTextLineReg:req, CounterReg, SkippedLinesReg, SkippedVisLinesReg
ifnb <SkippedLinesReg>
  xor SkippedLinesReg, SkippedLinesReg
endif
ifnb <SkippedVisLinesReg>
  xor SkippedVisLinesReg, SkippedVisLinesReg
endif
ifdifi <CurrTextLineReg>, <xax>
  mov xax, CurrTextLineReg
endif
ifnb <CounterReg>
  cmp CounterReg, 0
  jz @F
endif
  mov xax, [xax].$Obj(EditorTextLine).Link.pLinkFwrd
  .While xax != NULL
ifnb <SkippedLinesReg>
    inc SkippedLinesReg
endif
    sub xax, offset $Obj(EditorTextLine).Link
    .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
ifnb <SkippedVisLinesReg>
      inc SkippedVisLinesReg
endif
ifb <CounterReg>
      .break
else
      dec CounterReg
      .break .if ZERO?
endif
    .endif
    mov xax, [xax].$Obj(EditorTextLine).Link.pLinkFwrd
  .endw
@@:
endm

GotoPrevVisTextLine macro CurrTextLineReg:req, CounterReg, SkippedLinesReg, SkippedVisLinesReg
ifnb <SkippedLinesReg>
  xor SkippedLinesReg, SkippedLinesReg
endif
ifnb <SkippedVisLinesReg>
  xor SkippedVisLinesReg, SkippedVisLinesReg
endif
ifdifi <CurrTextLineReg>, <xax>
  mov xax, CurrTextLineReg
endif
ifnb <CounterReg>
  cmp CounterReg, 0
  jz @F
endif
  mov xax, [xax].$Obj(EditorTextLine).Link.pLinkBack
  .While xax != NULL
ifnb <SkippedLinesReg>
    inc SkippedLinesReg
endif
    sub xax, offset $Obj(EditorTextLine).Link
    .ifBitClr [xax].$Obj(EditorTextLine).dFlags, TLF_HIDDEN
ifnb <SkippedVisLinesReg>
      inc SkippedVisLinesReg
endif
ifb <CounterReg>
      .break
else
      dec CounterReg
      .break .if ZERO?
endif
    .endif
    mov xax, [xax].$Obj(EditorTextLine).Link.pLinkBack
  .endw
@@:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetColorFromString
; Purpose:    Return a color value from current string pointer.
; Arguments:  Arg1: -> String.
;             Arg2: Default color if no color is specified.
; Return:     eax = color value.
;             xcx -> Last processed char. If no more info is present, xcx = NULL.

align ALIGN_CODE
GetColorFromString proc uses xbx xsi pString:PSTRING, dDefaultColor:DWORD
  mov xsi, pString
  mov ebx, dDefaultColor
  RGB2BGR ebx
  mov xcx, xsi

  .while TRUE
    ;Search begin
    .while TRUE
      movzx eax, CHR ptr [xsi]
      .break .if ax >= '0' && ax <= '9' || ax == ':'
      .if ax == ','
        mov xcx, xsi
        jmp @Exit
      .elseif ax == CR || ax == 0
        xor ecx, ecx
        jmp @Exit
      .else
        jmp @Error
      .endif
      add xsi, sizeof(CHR)
    .endw
    mov xcx, xsi                                        ;xcx -> String begin

    ;Search end
    .while TRUE
      movzx eax, CHR ptr [xsi]
      .break .if ax == ':'
      .if ax == ','
        mov CHR ptr [xsi], 0
        jmp @Last
      .elseif ax == CR || ax == 0
        mov CHR ptr [xsi], 0
        xor esi, esi
        jmp @Last
      .else
        .if !(ax >= '0' && ax <= '9')
          jmp @Error
        .endif
      .endif
      add xsi, sizeof(CHR)
    .endw

    .if xcx != xsi
      mov CHR ptr [xsi], 0
      invoke dec2dword, xcx
      shl ebx, 8
      or ebx, eax
    .endif
    add xsi, sizeof(CHR)
  .endw

@Last:
  invoke dec2dword, xcx
  shl ebx, 8
  or eax, ebx
  and eax, 00FFFFFFh
  RGB2BGR eax
  mov xcx, xsi
  ret

@Error:
  xor eax, eax
  xor ecx, ecx
  ret

@Exit:
  mov eax, ebx
  and eax, 00FFFFFFh
  RGB2BGR eax
  ret
GetColorFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetStringFromString
; Purpose:    Return a string from current string pointer.
; Arguments:  Arg1: -> String.
; Return:     xax -> String.
;             xcx -> Last processed char. If no more info is present, xcx = NULL.
;             edx = String length.

align ALIGN_CODE
GetStringFromString proc uses xsi pString:PSTRING
  mov xsi, pString
  mov xcx, xsi

  ;Search begin
  .while TRUE
    movzx eax, CHR ptr [xsi]
    .break .if ax != ' '
    .if ax == ','
      mov xcx, xsi
      jmp @Exit
    .elseif ax == CR || ax == 0
      xor ecx, ecx
      jmp @Exit
    .endif
    add xsi, sizeof(CHR)
  .endw
  mov xcx, xsi                                        ;xcx -> String begin

  ;Search end
  .while TRUE
    movzx eax, CHR ptr [xsi]
    .if ax == ','
      mov xdx, xsi
      .break
    .elseif ax == CR || ax == 0
      mov xdx, xsi
      xor esi, esi
      .break
    .endif
    add xsi, sizeof(CHR)
  .endw
  
  ;From this point search back the first non blank char
  .while TRUE
    sub xdx, sizeof CHR
    .break .if CHR ptr [xdx] != ' '
  .endw
  mov CHR ptr [xdx + sizeof CHR], 0

  mov xax, xcx
  mov xcx, xsi
  sub xdx, xax
  add edx, sizeof CHR
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr edx, 1
  endif
  ret

@Exit:
  xor eax, eax
  xor edx, edx
  ret
GetStringFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetIntegerFromString
; Purpose:    Return a string from current string pointer.
; Arguments:  Arg1: -> String.
;             Arg2: Default Value.
; Return:     eax = SDWORD.
;             xcx -> Last processed char. If no more info is present, xcx = NULL.

align ALIGN_CODE
GetIntegerFromString proc uses xsi pString:PSTRING, sdDefaultValue:SDWORD
  invoke GetStringFromString, pString
  .if xax != NULL
    mov xsi, xcx
    invoke dec2dword, xax
    mov xcx, xsi
  .else
    mov eax, sdDefaultValue
  .endif
  ret
GetIntegerFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetFgBgAttrFromString
; Purpose:    Load FGBG_ATTR from current string pointer.
; Arguments:  Arg1: -> String.
;             Arg2: -> FGBG_ATTR.
;             Arg3: Default foreground color.
;             Arg4: Default background color.
;             xcx -> Last processed char. If no more info is present, xcx = NULL.

align ALIGN_CODE
GetFgBgAttrFromString proc uses xbx xdi pString:PSTRING, pFgBgAttr:PFGBG_ATTR, \
                                        DefFgColor:DWORD, DefBgColor:DWORD
  mov xax, pString
  mov xbx, pFgBgAttr
  invoke GetColorFromString, xax, DefFgColor
  mov xdi, xcx
  mov [xbx].FGBG_ATTR.ForeColor, eax
  .if xdi != NULL
    invoke GetColorFromString, addr [xdi + sizeof CHR], DefBgColor
    mov xdi, xcx 
    mov [xbx].FGBG_ATTR.Background.Color, eax
    mov [xbx].FGBG_ATTR.Background.hBrush, $invoke(CreateSolidBrush, eax)
  .else
    mrm [xbx].DRAW_ATTR.Background.Color, DefBgColor, eax
    mov [xbx].DRAW_ATTR.Background.hBrush, $invoke(CreateSolidBrush, eax)
  .endif

  mov xcx, xdi
  ret
GetFgBgAttrFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DeleteDrawAttrFont
; Purpose:    Delete the font contained in the DRAW_ATTR structure.
; Arguments:  Arg1: -> DRAW_ATTR.

align ALIGN_CODE
DeleteDrawAttrFont proc uses xbx pDrawAttr:PDRAW_ATTR
  mov xbx, pDrawAttr
  invoke DeleteObject, [xbx].DRAW_ATTR.hFont
  mov [xbx].DRAW_ATTR.hFont, 0
  ret
DeleteDrawAttrFont endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DeleteDrawAttrResources
; Purpose:    Delete the font and backgound brush contained in the in the DRAW_ATTR structure.
; Arguments:  Arg1: -> DRAW_ATTR.

align ALIGN_CODE
DeleteDrawAttrResources proc uses xbx pDrawAttr:PDRAW_ATTR
  mov xbx, pDrawAttr
  invoke DeleteObject, [xbx].DRAW_ATTR.Background.hBrush
  mov [xbx].DRAW_ATTR.Background.hBrush, 0
  invoke DeleteDrawAttrFont, xbx
  ret
DeleteDrawAttrResources endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreateDrawAttrFont
; Purpose:    Create the font specified in the DRAW_ATTR structure.
; Arguments:  Arg1: -> DRAW_ATTR.

align ALIGN_CODE
CreateDrawAttrFont proc uses xdi xbx pDrawAttr:PDRAW_ATTR
  local hPrevFont:HFONT, CharSize:POINT

  mov xbx, pDrawAttr

  ;Create font
  mov xdi, $invoke(GetDC, 0)
  invoke GetDeviceCaps, xdi, LOGPIXELSY
  invoke MulDiv, [xbx].DRAW_ATTR.dCurrPointSize, eax, -72
  mov [xbx].DRAW_ATTR.LogFont.lfHeight, eax
  invoke CreateFontIndirect, addr [xbx].DRAW_ATTR.LogFont
  mov [xbx].DRAW_ATTR.hFont, xax

  ;Test if the font is monospaced
  mov hPrevFont, $invoke(SelectObject, xdi, [xbx].DRAW_ATTR.hFont)
  invoke GetTextExtentPoint32, xdi, addr cMetricChar, 1, addr [xbx].DRAW_ATTR.FontMetric
  invoke GetTextExtentPoint32, xdi, $OfsCStr("."), 1, addr CharSize
  mov eax, [xbx].DRAW_ATTR.FontMetric.x
  .if eax == CharSize.x
    BitSet [xbx].DRAW_ATTR.dFlags, FONT_MONOSPACED
  .else
    BitClr [xbx].DRAW_ATTR.dFlags, FONT_MONOSPACED
  .endif

  invoke SelectObject, xdi, hPrevFont
  invoke ReleaseDC, 0, xdi
  ret
CreateDrawAttrFont endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreateDrawAttrResources
; Purpose:    Create the font and background brush specified in the DRAW_ATTR structure.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: -> DRAW_ATTR.

align ALIGN_CODE
CreateDrawAttrResources proc uses xbx hDC:HDC, pDrawAttr:PDRAW_ATTR
  mov xbx, pDrawAttr
  ;Create the background brush
  invoke CreateSolidBrush, [xbx].DRAW_ATTR.Background.Color
  mov [xbx].DRAW_ATTR.Background.hBrush, xax
  ;Create the font
  invoke CreateDrawAttrFont, xbx
  ret
CreateDrawAttrResources endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetDrawAttrFromString
; Purpose:    Load DRAW_ATTR from current string pointer.
; Arguments:  Arg1: -> DRAW_ATTR.
;             Arg2: -> String.
;             Arg3: -> FONT_DEF.
;             Arg4: DC HANDLE.
;             Arg5: Default foreground color.
;             Arg6: Default background color.
;Return:      xcx -> Last processed char. If no more info is present, xcx = NULL.

align ALIGN_CODE
GetDrawAttrFromString proc uses xbx xdi xsi pDrawAttr:PDRAW_ATTR, pString:PSTRING, \
                                            pFontDef:PFONT_DEF, hDC:HDC, \
                                            DefFgColor:DWORD, DefBgColor:DWORD
  mov xbx, pDrawAttr

  ;Load FGBG_ATTR
  invoke GetFgBgAttrFromString, pString, xbx, DefFgColor, DefBgColor
  mov xdi, xcx                                          ;Save return value

  ;Copy the previously loaded font definition
  lea xcx, [xbx + sizeof(FGBG_ATTR)]                    ;xcx -> FONT_DEF
  invoke MemClone, xcx, pFontDef, sizeof FONT_DEF

  ;Update the font emphasis values
  .if xdi != NULL
    invoke GetStringFromString, addr [xdi + sizeof CHR]
    mov xdi, xcx 
    .if CHR ptr [xax] != 0
      mov xsi, xax
      invoke StrPos, xsi, $OfsCStr("ITALIC")
      .if xax != NULL
        mov [xbx].DRAW_ATTR.LogFont.lfItalic, TRUE
      .endif   
      invoke StrPos, xsi, $OfsCStr("UNDERLINE")
      .if xax != NULL
        mov [xbx].DRAW_ATTR.LogFont.lfUnderline, TRUE
      .endif   
      invoke StrPos, xsi, $OfsCStr("BOLD")
      .if xax != NULL
        mov [xbx].DRAW_ATTR.LogFont.lfWeight, FW_BOLD
      .endif
    .else
      m2z [xbx].DRAW_ATTR.LogFont.lfItalic
      m2z [xbx].DRAW_ATTR.LogFont.lfUnderline
      mov [xbx].DRAW_ATTR.LogFont.lfWeight, FW_REGULAR
    .endif
  .endif
  
  invoke CreateDrawAttrFont, xbx
  
  mov xcx, xdi
  ret
GetDrawAttrFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetFontDefFromString
; Purpose:    Load FONT_DEF from current string pointer.
; Arguments:  Arg1: -> FONT_DEF.
;             Arg2: -> String.
;             Arg3: Default Font Face.
;             Arg4: Default Font Point Size.
; Return:     Nothing.

align ALIGN_CODE
GetFontDefFromString proc uses xbx xdi xsi pFontDef:PFONT_DEF, pString:PSTRING, \
                                           pDefFontFace:PSTRING, dDefFontPointSize:DWORD
  mov xax, pString
  mov xbx, pFontDef

  ;Fill some default font information
  mov [xbx].FONT_DEF.LogFont.lfWidth, 0
  mov [xbx].FONT_DEF.LogFont.lfEscapement, 0
  mov [xbx].FONT_DEF.LogFont.lfOrientation, 0
  mov [xbx].FONT_DEF.LogFont.lfWeight, FW_NORMAL
  mov [xbx].FONT_DEF.LogFont.lfItalic, FALSE
  mov [xbx].FONT_DEF.LogFont.lfUnderline, FALSE
  mov [xbx].FONT_DEF.LogFont.lfStrikeOut, FALSE
  mov [xbx].FONT_DEF.LogFont.lfCharSet, DEFAULT_CHARSET
  mov [xbx].FONT_DEF.LogFont.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov [xbx].FONT_DEF.LogFont.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov [xbx].FONT_DEF.LogFont.lfQuality, CLEARTYPE_QUALITY
  mov [xbx].FONT_DEF.LogFont.lfPitchAndFamily, FIXED_PITCH
  .if CHR ptr [xax] == 0
    mov xax, pDefFontFace
    xor ecx, ecx
  .else
    invoke GetStringFromString, xax
    .if CHR ptr [xax] == 0
      mov xax, pDefFontFace
    .endif
  .endif
  mov xdi, xcx 
  lea xcx, [xbx].FONT_DEF.LogFont.lfFaceName
  invoke StrCCopy, xcx, xax, LF_FACESIZE
  mov esi, eax
  .if xdi != NULL
    invoke GetIntegerFromString, addr [xdi + sizeof CHR], dDefFontPointSize 
  .else
    mov eax, dDefFontPointSize
  .endif
  mov [xbx].FONT_DEF.dInitPointSize, eax
  mov [xbx].FONT_DEF.dCurrPointSize, eax
  ret
GetFontDefFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetVersionFromString
; Purpose:    Return the main and subversion numbers.
; Arguments:  Arg1: -> String, e.g. "1.0"
; Return:     eax = Main veriosn number.
;             ecx = Subversion number.

align ALIGN_CODE
GetVersionFromString proc uses xbx pString:PSTRING
  invoke StrLScan, pString, '.'
  xor ecx, ecx
  .if xax != 0
    mov xbx, xax
    mov CHR ptr [xbx], 0
    add xbx, sizeof CHR
    invoke dec2dword, xbx
    mov ebx, eax
    invoke dec2dword, pString
    mov ecx, ebx
  .endif
  ret
GetVersionFromString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsBinNumber
; Purpose:    Check if the given string is a binaray number.
; Arguments:  Arg1: -> String
;             Arg2: Character count.
; Return:     eax = TRUE if the string is a binaray number, otherwise FALSE.

align ALIGN_CODE
IsBinNumber proc uses xbx xsi pStart:PSTRING, dCount:DWORD
  mov xsi, pStart
  xor ebx, ebx
  xor eax, eax
  movzx edx, CHR ptr [xsi]
  .if edx == "+" || edx == '-'                          ;Check for heading sign
    inc ebx
  .endif

  .if ebx < dCount
    .repeat
      movzx edx, CHR ptr [xsi + sizeof(CHR)*xbx]
      GetCharType edx, ecx
      test ecx, CHR_BIN
      .break .if ZERO?
      inc ebx
    .until ebx == dCount

    .if ebx != 0
      inc ebx
      .if ebx == dCount && (edx == 'y' || edx == 'Y' || edx == 'b' || edx == 'B')
        mov eax, TRUE
      .endif
    .endif
  .endif

@@Exit:
  ret
IsBinNumber endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsDecNumber
; Purpose:    Check if the given string is a decimal number.
; Arguments:  Arg1: -> String
;             Arg2: Character count.
; Return:     eax = TRUE if the string is a decimal number, otherwise FALSE.

align ALIGN_CODE
IsDecNumber proc uses xbx xsi pStart:PSTRING, dCount:DWORD
  mov xsi, pStart
  xor ebx, ebx
  xor eax, eax
  movzx edx, CHR ptr [xsi]
  .if edx == "+" || edx == '-'                          ;Check for heading sign
    inc ebx
  .endif
  .if ebx < dCount
    .repeat
      movzx edx, CHR ptr [xsi + sizeof(CHR)*xbx]
      GetCharType edx, ecx
      test ecx, CHR_DEC
      .break .if ZERO?
      inc ebx
    .until ebx == dCount

    .if ebx != 0
      .if ebx == dCount
        mov eax, TRUE
      .else
        inc ebx
        .if ebx == dCount && (edx == 'd' || edx == 'D' || edx == 't' || edx == 'T')
          mov eax, TRUE
        .endif
      .endif
    .endif
  .endif

  ret
IsDecNumber endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsHexNumber
; Purpose:    Check if the given string is a hexadecimal number.
; Arguments:  Arg1: -> String
;             Arg2: Character count.
; Return:     eax = TRUE if the string is a hexadecimal number, otherwise FALSE.

align ALIGN_CODE
IsHexNumber proc uses xbx xsi pStart:PSTRING, dCount:DWORD
  mov xsi, pStart
  xor ebx, ebx
  xor eax, eax
  movzx edx, CHR ptr [xsi]
  .if edx == "+" || edx == '-'                          ;Check for heading sign
    inc ebx
  .endif

  .if ebx < dCount                                      ;Next char must be decimal
    movzx edx, CHR ptr [xsi]
    GetCharType edx, ecx
    test ecx, CHR_DEC
    jz @@Exit
    inc ebx
  .endif

  .if ebx < dCount
    .repeat
      movzx edx, CHR ptr [xsi + sizeof(CHR)*xbx]
      GetCharType edx, ecx
      test ecx, CHR_HEX
      .break .if ZERO?
      inc ebx
    .until ebx == dCount

    .if ebx != 0
      inc ebx
      .if ebx == dCount && (edx == 'h' || edx == 'H')
        mov eax, TRUE
      .endif
    .endif
  .endif

@@Exit:
  ret
IsHexNumber endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsOctNumber
; Purpose:    Check if the given string is a octal number.
; Arguments:  Arg1: -> String
;             Arg2: Character count.
; Return:     eax = TRUE if the string is a octal number, otherwise FALSE.

align ALIGN_CODE
IsOctNumber proc uses xbx xsi pStart:PSTRING, dCount:DWORD
  mov xsi, pStart
  xor ebx, ebx
  xor eax, eax
  movzx edx, CHR ptr [xsi]
  .if edx == "+" || edx == '-'                          ;Check for heading sign
    inc ebx
  .endif

  .if ebx < dCount
    .repeat
      movzx edx, CHR ptr [xsi + sizeof(CHR)*xbx]
      GetCharType edx, ecx
      test ecx, CHR_OCT
      .break .if ZERO?
      inc ebx
    .until ebx == dCount

    .if ebx != 0
      inc ebx
      .if ebx == dCount && (edx == 'o' || edx == 'O' || edx == 'q' || edx == 'Q')
        mov eax, TRUE
      .endif
    .endif
  .endif

@@Exit:
  ret
IsOctNumber endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrScanCharA
; Purpose:    Scan for a char.
; Arguments:  Arg1: -> StringA
;             Arg2: Character count.
;             Arg3: Searched Char.
; Return:     xax -> CHRA occurence.

align ALIGN_CODE
StrScanCharA proc uses xdi pStringA:PSTRINGA, dCharCount:DWORD, bChar:CHRA
  mov xdi, pStringA
  mov ecx, dCharCount                                   ;rcx (counter) = length
  mov al, bChar                                         ;Search for bCharA
  repne scasb
  mov xax, NULL                                         ;Dont't change flags!
  jne @F
  lea xax, [xdi - sizeof(CHRA)]
@@:
  ret
StrScanCharA endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrScanCharW
; Purpose:    Scan for a char.
; Arguments:  Arg1: -> StringW
;             Arg2: Character count.
;             Arg3: Searched Char.
; Return:     xax -> CHRW occurence.

align ALIGN_CODE
StrScanCharW proc uses xdi pStringW:PSTRINGW, dCharCount:DWORD, wChar:CHRW
  mov xdi, pStringW
  mov ecx, dCharCount                                   ;rcx (counter) = length
  mov ax, wChar                                         ;Search for bCharA
  repne scasw
  mov xax, NULL                                         ;Dont't change flags!
  jne @F
  lea xax, [xdi - sizeof(CHRW)]
@@:
  ret
StrScanCharW endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowKeywords

align ALIGN_CODE
ShowKeywords proc uses xbx xdi pCKW:$ObjPtr(KeywordCollection)
  mov xbx, pCKW
  .ColForEach [xbx], edi
    DbgStr [xax].KEYWORD.pString
  .ColNext
  ret
ShowKeywords endp
