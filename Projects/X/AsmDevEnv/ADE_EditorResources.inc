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
EFF_UTF8                      equ   2         ;Without BOM
EFF_UTF8BOM                   equ   3         ;With BOM
EFF_UTF16BOM                  equ   4         ;With BOM

;Editor Content Type
ECT_TXT                       equ   0
ECT_ASM                       equ   1
ECT_RES                       equ   2

;Editor Line Termination
ELT_CRLF                      equ   0         ;Windows
ELT_LF                        equ   1         ;Unix
ELT_CR                        equ   2         ;Macintosh
ELT_NULL                      equ   3         ;


; ==================================================================================================
; EditorResources implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     EditorResources.ConfigLoad
; Purpose:    Load configuration and create matching resources.
; Arguments:  Arg1: -> Ini-File Name.
;             Arg2: -> Ini-File Section Prefix.
;             Arg3: hDC used to create resources.
; Return:     Nothing.

Method EditorResources.ConfigLoad, uses xdi xsi, pIniFullFileName:PSTRING, pSectionPrefix:PSTRING, hDC:HDC
  local DrawAttr:DRAW_ATTR, FontDef:FONT_DEF
  local pDescription:PSTRING, dIndex:DWORD, pGroup:PKEYWORDGROUP
  local pLastChar:PCHR, dLength:DWORD, dFlags:DWORD
  local cSectionName[50]:CHR, cItemName[20]:CHR, cItemBuffer[4096]:CHR

  SetObject xsi
  
  invoke GetPrivateProfileString, addr szIdentification, addr szVersion, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName

  ;Load element attributes
  ;Code Selection Bar Section
  lea xdi, cSectionName
  WriteF xdi, "¦ST Selection Bar", pSectionPrefix
  invoke GetPrivateProfileString, addr cSectionName, addr szFont, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetFontDefFromString, addr FontDef, addr cItemBuffer, \
                      addr szDefaultSelBarFontFace, DefaultSelBarFontPointSize

  invoke GetPrivateProfileString, addr cSectionName, addr szRegular, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].SelBarTextRegular, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultSelBarTextRegFG, DefaultSelBarTextRegBG

  invoke GetPrivateProfileString, addr cSectionName, addr szSelect, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].SelBarTextSelect, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultSelBarTextSelFG, DefaultSelBarTextSelBG

  ;Code Status Panel Section
  lea xdi, cSectionName
  WriteF xdi, "¦ST Status Panel", pSectionPrefix
  invoke GetPrivateProfileString, addr cSectionName, addr szFont, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetFontDefFromString, addr FontDef, addr cItemBuffer, \
                      addr szDefaultStatusFontFace, DefaultStatusTextPointSize

  invoke GetPrivateProfileString, addr cSectionName, addr szRegular, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].StatusPanelText, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultStatusPanelTextFG, DefaultStatusPanelTextBG

  ;Code Editor Section
  lea xdi, cSectionName
  WriteF xdi, "¦ST Editor", pSectionPrefix
  invoke GetPrivateProfileString, addr cSectionName, addr szFont, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetFontDefFromString, addr FontDef, addr cItemBuffer, \
                      addr szDefaultEditorFontFace, DefaultEditorFontPointSize

  invoke GetPrivateProfileString, addr cSectionName, addr szBackground, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetColorFromString, addr cItemBuffer, DefaultEditorBG
  mov [xsi].EditorBG.Color, eax
  mov [xsi].EditorBG.hBrush, $invoke(CreateSolidBrush, [xsi].EditorBG.Color)

  invoke GetPrivateProfileString, addr cSectionName, addr szRegular, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextRegular, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextRegularFG, [xsi].EditorBG.Color

  invoke GetPrivateProfileString, addr cSectionName, addr szSelect, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextSelect, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextSelectFG, DefaultEditorTextSelectBG

  invoke GetPrivateProfileString, addr cSectionName, addr szHighlight, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextHighlight, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextHilightFG, DefaultEditorTextHilightBG

  invoke GetPrivateProfileString, addr cSectionName, addr szQuote, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextQuote, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextQuoteFG, DefaultEditorTextQuoteBG

  invoke GetPrivateProfileString, addr cSectionName, addr szComment, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextComment, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextCommentFG, DefaultEditorTextCommentBG

  invoke GetPrivateProfileString, addr cSectionName, addr szNumber, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextNumber, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextNumberFG, DefaultEditorTextNumberBG

  invoke GetPrivateProfileString, addr cSectionName, addr szOperator, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke GetDrawAttrFromString, addr [xsi].EditorTextOperator, addr cItemBuffer, \
                      addr FontDef, hDC, DefaultEditorTextOperatorFG, DefaultEditorTextOperatorBG

  invoke GetPrivateProfileString, addr cSectionName, addr szLineSpace, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  mov [xsi].dCodeLineSpace, $32($invoke(GetIntegerFromString, addr cItemBuffer, DefaultLineSpace))

  invoke GetPrivateProfileString, addr cSectionName, addr szTabWidth, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  mov [xsi].dTabWidth, $32($invoke(GetIntegerFromString, addr cItemBuffer, DefaultTabWidth))

  invoke GetPrivateProfileString, addr cSectionName, addr szTab2Spaces, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke StrIComp, addr cItemBuffer, addr szON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_TAB_2_SPACES
  .endif

  invoke GetPrivateProfileString, addr cSectionName, addr szAlignLines, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke StrIComp, addr cItemBuffer, addr szON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_SHOW_ALIGN_LINES
  .endif

  invoke GetPrivateProfileString, addr cSectionName, addr szRevHorzMouseWheelRot, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke StrIComp, addr cItemBuffer, addr szON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_REVERSE_MOUSE_WHEEL_HORZ
  .endif

  invoke GetPrivateProfileString, addr cSectionName, addr szRevVertMouseWheelRot, NULL, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke StrIComp, addr cItemBuffer, addr szON
  .if eax == 0
    BitSet [xsi].dFlags, ERF_REVERSE_MOUSE_WHEEL_VERT
  .endif

  mov [xsi].dLineTermination, ELT_CRLF
  invoke GetPrivateProfileString, addr cSectionName, addr szLineTermination, addr szStrCRLF, \
                      addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
  invoke StrIComp, addr cItemBuffer, addr szStrLF
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
                        addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
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
                            addr cItemBuffer, lengthof cItemBuffer, pIniFullFileName
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
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorResources.ConfigSave
; Purpose:    Save configuration values.
; Arguments:  None.
; Return:     Nothing.

Method EditorResources.ConfigSave
MethodEnd

; --------------------------------------------------------------------------------------------------
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

  OCall [xsi].FoldingRules::DataCollection.Done
  OCall [xsi].AutocompleteRules::DataCollection.Done

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorResources.Init
; Purpose:    Initialize the EditorResources object.
; Arguments:  Arg1: -> Owner object.
;             Arg5: -> EditorSharedResources.
; Return:     Nothing.

Method EditorResources.Init, uses xbx xsi, pOwner:POINTER, pEditorSharedResources:$ObjPtr(EditorSharedResources)
  SetObject xsi

  ACall xsi.Init, pOwner
  OCall [xsi].KeywordGroups::KeywordGroupCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY
  OCall [xsi].Keywords::KeywordCollection.Init, xsi, 1500, 500, COL_MAX_CAPACITY

  OCall [xsi].FoldingRules::DataCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY
  OCall [xsi].AutocompleteRules::DataCollection.Init, xsi, 20, 10, COL_MAX_CAPACITY

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
MethodEnd

; --------------------------------------------------------------------------------------------------
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
    mov [xsi].dLineHeight, eax
    mov eax, TRUE
  .endif
MethodEnd
