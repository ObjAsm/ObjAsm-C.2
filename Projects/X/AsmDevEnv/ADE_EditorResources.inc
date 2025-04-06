; ==================================================================================================
; Title:      ACE_EditorResources.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


;General Editor Options (EditorResources)
ERF_REVERSE_MOUSE_WHEEL_VERT  equ   BIT00     ;Reverse vertical mouse wheel rotation
ERF_REVERSE_MOUSE_WHEEL_HORZ  equ   BIT01     ;Reverse horizontal mouse wheel rotation
ERF_TAB_2_SPACES              equ   BIT02
ERF_SHOW_ALIGN_LINES          equ   BIT03
ERF_TAB_TO_SPACE              equ   BIT04

;Editor File Format
EFF_UNKNOWN                   equ   0
EFF_ANSI                      equ   1
EFF_UTF8                      equ   3         ;Without BOM
EFF_UTF8BOM                   equ   4         ;With BOM
EFF_UTF16BOM                  equ   5         ;With BOM

;Editor Line Termination
ELT_CRLF                      equ   0         ;Windows
ELT_LF                        equ   1         ;Unix
ELT_CR                        equ   2         ;Macintosh
ELT_NULL                      equ   3         ;


; ==================================================================================================
; EditorResources implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorResources.Done
; Purpose:    Finalize the EditorResources object.
; Arguments:  None.
; Return:     Nothing.

Method EditorResources.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].EditorBG.hBrush

  invoke DeleteDrawAttrResources, addr [xsi].EditorTextRegular
  invoke DeleteDrawAttrResources, addr [xsi].EditorTextSelect
  invoke DeleteDrawAttrResources, addr [xsi].EditorTextHighlight
  invoke DeleteDrawAttrResources, addr [xsi].EditorTextQuote
  invoke DeleteDrawAttrResources, addr [xsi].EditorTextComment
  invoke DeleteDrawAttrResources, addr [xsi].EditorTextNumber
  invoke DeleteDrawAttrResources, addr [xsi].EditorTextOperator

  invoke DeleteDrawAttrResources, addr [xsi].SelBarTextRegular
  invoke DeleteDrawAttrResources, addr [xsi].SelBarTextSelect
  invoke DeleteDrawAttrResources, addr [xsi].StatusPanelText

  ;Destroy Keywords and Groups
  OCall [xsi].KeywordGroups::KeywordGroupCollection.Done
  OCall [xsi].Keywords::KeywordCollection.Done
  OCall [xsi].FileFormats::FileFormatCollection.Done

  OCall [xsi].FoldingRules::DataCollection.Done
  OCall [xsi].AutocompleteRules::DataCollection.Done

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorResources.Init
; Purpose:    Initialize the EditorResources object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> IniFileName String.
;             Arg3: Section name prefix.
;             Arg4: HDC.
;             Arg5: -> EditorSharedResources.
; Return:     Nothing.

Method EditorResources.Init, uses xbx xdi xsi, pOwner:POINTER, pIniFileName:PSTRING, \
                                               pSectionPrefix:PSTRING, hDC:HDC, \
                                               pEditorSharedResources:$ObjPtr(EditorSharedResources)
  local DrawAttr:DRAW_ATTR, FontDef:FONT_DEF, dIniFilePresent:DWORD
  local pDescription:PSTRING, dIndex:DWORD, pGroup:PKEYWORDGROUP
  local pLastChar:PCHR, dLength:DWORD, dFlags:DWORD
  local cFileName[1024]:CHR, cSectionName[50]:CHR, cItemName[20]:CHR, cItemBuffer[4096]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner
  invoke GetFullPathName, pIniFileName, lengthof cFileName - 1, addr cFileName, NULL
  invoke FileExist, addr cFileName
  mov dIniFilePresent, eax
  .if eax == FALSE
    invoke MsgBox, 0, addr cWarnNoIni, addr cWarning, MB_OK or MB_ICONWARNING
  .endif

  OCall [xsi].KeywordGroups::KeywordGroupCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY
  OCall [xsi].Keywords::KeywordCollection.Init, xsi, 1500, 500, COL_MAX_CAPACITY
  OCall [xsi].FileFormats::FileFormatCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY

  OCall [xsi].FoldingRules::DataCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY
  OCall [xsi].AutocompleteRules::DataCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY

  invoke GetPrivateProfileString, addr cIniSectIdentification, addr cVersion, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  .if dIniFilePresent != FALSE
    ;Check Version
    invoke GetVersionFromString, addr cItemBuffer
    .if eax != [xsi].dReqMainVersion || ecx < [xsi].dMinSubVersion
      invoke MsgBox, 0, addr cWarnOldIni, addr cWarning, MB_OK or MB_ICONWARNING
    .endif
  .endif

  ;Load element attributes
  ;Code Selection Bar Section
  lea xdi, cSectionName
  WriteF xdi, "¦ST Selection Bar", pSectionPrefix
  invoke GetPrivateProfileString, addr cSectionName, addr cFont, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetFontDefFromString, addr FontDef, addr cItemBuffer, \
                      addr cDefaultSelBarFontFace, DefaultSelBarFontPointSize

  invoke GetPrivateProfileString, addr cSectionName, addr cRegular, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].SelBarTextRegular, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultSelBarTextRegFG, DefaultSelBarTextRegBG

  invoke GetPrivateProfileString, addr cSectionName, addr cSelect, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].SelBarTextSelect, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultSelBarTextSelFG, DefaultSelBarTextSelBG

  ;Code Status Panel Section
  lea xdi, cSectionName
  WriteF xdi, "¦ST Status Panel", pSectionPrefix
  invoke GetPrivateProfileString, addr cSectionName, addr cFont, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetFontDefFromString, addr FontDef, addr cItemBuffer, \
                      addr cDefaultStatusFontFace, DefaultStatusTextPointSize

  invoke GetPrivateProfileString, addr cSectionName, addr cRegular, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].StatusPanelText, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultStatusPanelTextFG, DefaultStatusPanelTextBG

  ;Code Editor Section
  lea xdi, cSectionName
  WriteF xdi, "¦ST Editor", pSectionPrefix
  invoke GetPrivateProfileString, addr cSectionName, addr cFont, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetFontDefFromString, addr FontDef, addr cItemBuffer, \
                      addr cDefaultEditorFontFace, DefaultEditorFontPointSize

  invoke GetPrivateProfileString, addr cSectionName, addr cBackground, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetColorFromString, addr cItemBuffer, DefaultEditorBG
  mov [xsi].EditorBG.Color, eax
  mov [xsi].EditorBG.hBrush, $invoke(CreateSolidBrush, [xsi].EditorBG.Color)

  invoke GetPrivateProfileString, addr cSectionName, addr cRegular, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextRegular, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextRegularFG, [xsi].EditorBG.Color

  invoke GetPrivateProfileString, addr cSectionName, addr cSelect, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextSelect, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextSelectFG, DefaultEditorTextSelectBG

  invoke GetPrivateProfileString, addr cSectionName, addr cHighlight, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextHighlight, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextHilightFG, DefaultEditorTextHilightBG

  invoke GetPrivateProfileString, addr cSectionName, addr cQuote, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextQuote, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextQuoteFG, DefaultEditorTextQuoteBG

  invoke GetPrivateProfileString, addr cSectionName, addr cComment, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextComment, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextCommentFG, DefaultEditorTextCommentBG

  invoke GetPrivateProfileString, addr cSectionName, addr cNumber, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextNumber, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextNumberFG, DefaultEditorTextNumberBG

  invoke GetPrivateProfileString, addr cSectionName, addr cOperator, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextOperator, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextOperatorFG, DefaultEditorTextOperatorBG

  invoke GetPrivateProfileString, addr cSectionName, addr cLineSpace, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  mov [xsi].dCodeLineSpace, $32($invoke(GetIntegerFromString, addr cItemBuffer, DefaultLineSpace))

  invoke GetPrivateProfileString, addr cSectionName, addr cTabWidth, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  mov [xsi].dTabWidth, $32($invoke(GetIntegerFromString, addr cItemBuffer, DefaultTabWidth))

  invoke GetPrivateProfileString, addr cSectionName, addr cTab2Spaces, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke StrIComp, addr cItemBuffer, addr cON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_TAB_2_SPACES
  .endif

  invoke GetPrivateProfileString, addr cSectionName, addr cAlignLines, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke StrIComp, addr cItemBuffer, addr cON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_SHOW_ALIGN_LINES
  .endif

  invoke GetPrivateProfileString, addr cSectionName, addr cRevHorzMouseWheelRot, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke StrIComp, addr cItemBuffer, addr cON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_REVERSE_MOUSE_WHEEL_HORZ
  .endif

  invoke GetPrivateProfileString, addr cSectionName, addr cRevVertMouseWheelRot, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke StrIComp, addr cItemBuffer, addr cON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_REVERSE_MOUSE_WHEEL_VERT
  .endif

  mov [xsi].dLineTermination, ELT_CRLF
  invoke GetPrivateProfileString, addr cSectionName, addr cLineTermination, addr cStrCRLF, \
                      addr cItemBuffer, lengthof cItemBuffer, addr cFileName
  invoke StrIComp, addr cItemBuffer, addr cStrLF
  .if eax == 0
    mov [xsi].dLineTermination, ELT_LF
  .else
    invoke StrIComp, addr cItemBuffer, addr cNULL
    .if eax == 0
      mov [xsi].dLineTermination, ELT_NULL
    .endif
  .endif

  ;Load Keywords and Groups
  lea xdi, cSectionName
  WriteF xdi, "¦ST Keywords", pSectionPrefix
  mov dIndex, 0
  .while TRUE
    lea xdi, cItemName
    WriteF xdi, "KWG¦UD_ATTR", dIndex
    invoke GetPrivateProfileString, addr cSectionName, addr cItemName, NULL, \
                        addr cItemBuffer, lengthof cItemBuffer, addr cFileName
    .break .if eax == 0
    invoke GetDrawAttrFromString, addr DrawAttr, addr cItemBuffer, addr FontDef, hDC, \
                                  DefaultEditorTextRegularBG, [xsi].EditorBG.Color
    .if xcx != NULL
      lea xdi, [xcx + sizeof(CHR)]
      MemAlloc sizeof(KEYWORDGROUP)
      .if xax != NULL
        mov pGroup, $OCall([xsi].KeywordGroups::DataCollection.Insert, xax)
        invoke GetStringFromString, xdi                       ;xax -> String, edx = length
        mov pDescription, xax
        mov xdi, pGroup
        mov [xdi].KEYWORDGROUP.dDescLength, edx
        mov [xdi].KEYWORDGROUP.pDescription, $invoke(StrAlloc, edx)
        invoke StrCCopy, xax, pDescription, [xdi].KEYWORDGROUP.dDescLength
        s2s DRAW_ATTR ptr [xdi], DrawAttr, xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xax

        lea xdi, cItemName
        WriteF xdi, "KWG¦UD_CONT", dIndex
        invoke GetPrivateProfileString, addr cSectionName, addr cItemName, NULL, \
                            addr cItemBuffer, lengthof cItemBuffer, addr cFileName
        .if eax != 0
          invoke StrNew, addr cItemBuffer
          mov xcx, pGroup
          mov [xcx].KEYWORDGROUP.pKeyWords, xax                 ;Ownership passed to KEYWORDGROUP
          .while TRUE
            invoke GetStringFromString, xax
            mov pLastChar, xcx
            mov dLength, edx
            mov dFlags, 0
            .if CHR ptr [xax] != 0
              .if CHR ptr [xax] == '^'
                BitSet dFlags, KWF_CASE_SENSITIVE
                add xax, sizeof CHR
                dec dLength
              .elseif CHR ptr [xax] == '~'
                BitSet dFlags, KWF_CASE_CONVERT
                add xax, sizeof CHR
                dec dLength
              .endif
              OCall [xsi].Keywords::KeywordCollection.Insert, pGroup, dFlags, dLength, xax
            .endif
            mov xax, pLastChar
            .break .if xax == NULL
            add xax, sizeof(CHR)
          .endw
        .else
          mov xcx, pGroup
          mov [xcx].KEYWORDGROUP.pKeyWords, NULL
        .endif
      .endif
    .endif
    inc dIndex
  .endw

  ;Load file formats
  xor ebx, ebx
  .while TRUE
    inc ebx
    lea xdi, cItemName
    WriteF xdi, "FF¦UD", ebx
    invoke GetPrivateProfileString, $OfsCStr("File Format"), addr cItemName, NULL, \
                                    addr cItemBuffer, lengthof cItemBuffer, addr cFileName
    .break .if eax == 0
    invoke StrLScan, addr cItemBuffer, ','
    xor edi, edi
    .if xax != NULL
      lea xdi, [xax + sizeof(CHR)]
      m2z CHR ptr [xax]
    .endif
    .if xdi != NULL
      DoesStringMatch? [xdi], <ANSI>
      .if ZERO?
        mov edi, EFF_ANSI
      .else
        DoesStringMatch? [xdi], <UTF8>
        .if ZERO?
          mov edi, EFF_UTF8
        .else
          DoesStringMatch? [xdi], <UTF8BOM>
          .if ZERO?
            mov edi, EFF_UTF8BOM
          .else
            DoesStringMatch? [xdi], <UTF16BOM>
            .if ZERO?
              mov edi, EFF_UTF16BOM
            .else
              mov edi, EFF_UNKNOWN
            .endif
          .endif
        .endif
      .endif
    .endif
    .if xdi != 0
      OCall [xsi].FileFormats::FileFormatCollection.Insert, addr cItemBuffer, edi
    .endif
  .endw

  ;Copy shared resource HANDLEs
  mov xbx, pEditorSharedResources
  ;Load cursors
  m2m [xsi].hCursorArrow,       [xbx].$Obj(EditorSharedResources).hCursorArrow, xax
  m2m [xsi].hCursorIBeam,       [xbx].$Obj(EditorSharedResources).hCursorIBeam, xax
  m2m [xsi].hCursorSelect,      [xbx].$Obj(EditorSharedResources).hCursorSelect, xax
  m2m [xsi].hCursorHand,        [xbx].$Obj(EditorSharedResources).hCursorHand, xax

  ;Load bitmaps
  m2m [xsi].hBmpStatusIndRed,   [xbx].$Obj(EditorSharedResources).hBmpStatusIndRed, xax
  m2m [xsi].hBmpStatusIndYellow,[xbx].$Obj(EditorSharedResources).hBmpStatusIndYellow, xax
  m2m [xsi].hBmpStatusIndGreen, [xbx].$Obj(EditorSharedResources).hBmpStatusIndGreen, xax

  ;Load Brushes
  m2m [xsi].hBrushLineIndRed,   [xbx].$Obj(EditorSharedResources).hBrushLineIndRed, xax
  m2m [xsi].hBrushLineIndYellow,[xbx].$Obj(EditorSharedResources).hBrushLineIndYellow, xax
  m2m [xsi].hBrushLineIndGreen, [xbx].$Obj(EditorSharedResources).hBrushLineIndGreen, xax

;  invoke ShowKeywords, addr [xsi].Keywords
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorResources.Zoom
; Purpose:    Manipulate the editor fonts to create the illusion of zooming in and out.
; Arguments:  Arg1: ZoomFactor.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

ZoomFont macro DrawAttr
  ;Compute the new Font PointSize
  mov eax, &DrawAttr&.DRAW_ATTR.dInitPointSize
  mul edi                                               ;edi = dZoomFactor
  cdiv ZOOM_FACTOR_INIT
  .if edx != &DrawAttr&.DRAW_ATTR.dCurrPointSize        ;Check if the PointSize has really changed
    mov &DrawAttr&.DRAW_ATTR.dCurrPointSize, edx
    ;Recreate  the font
    invoke DeleteDrawAttrFont, addr &DrawAttr
    invoke CreateDrawAttrFont, addr &DrawAttr
  .endif
endm

Method EditorResources.Zoom, uses xbx xdi xsi, dZoomFactor:DWORD
  SetObject xsi
  mov edi, dZoomFactor
  xor eax, eax
  .if SDWORD ptr edi >= ZOOM_FACTOR_MIN && SDWORD ptr edi <= ZOOM_FACTOR_MAX ;Check bounds
    mov [xsi].dZoomFactor, edi
    
    ;Update the fonts
    ZoomFont [xsi].EditorTextRegular
    ZoomFont [xsi].EditorTextSelect
    ZoomFont [xsi].EditorTextHighlight
    ZoomFont [xsi].EditorTextQuote
    ZoomFont [xsi].EditorTextComment
    ZoomFont [xsi].EditorTextNumber
    ZoomFont [xsi].EditorTextOperator
    ZoomFont [xsi].SelBarTextRegular
    ZoomFont [xsi].SelBarTextSelect
    .ColForEach [xsi].KeywordGroups
      lea xbx, [xax].KEYWORDGROUP
      ZoomFont [xbx]
    .ColNext
  
    ;Compute the new line height
    mov eax, [xsi].dCodeLineSpace
    add eax, [xsi].EditorTextRegular.FontMetric.y
    mov [xsi].dTextLineHeight, eax
    mov eax, TRUE
  .endif
MethodEnd
