; ==================================================================================================
; Title:      ADE_EditorLine.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


;Don't use DT_NOCLIP, since the text must be confined into a given RECT
ELN_DRAW_TEXT_FLAGS         equ   DT_NOPREFIX or DT_SINGLELINE or DT_EXPANDTABS or DT_VCENTER
ELN_GRANULARITY             equ   32        ;Must be a power of 2, in characters

;EditorLine Error
ELE_OUTOFMEMORY             equ   10000

;EditorLine flags
ELF_DIRTY_LINE_PREV         equ   BIT00     ;Previous line has changed
ELF_DIRTY_LINE_CURR         equ   BIT01     ;Current line has changed
ELF_DIRTY_LINE_NEXT         equ   BIT02     ;Next line has changed
ELF_SAVED_LINE_PREV         equ   BIT03     ;Previous line has been saved
ELF_SAVED_LINE_CURR         equ   BIT04     ;Current line has been saved
ELF_SAVED_LINE_NEXT         equ   BIT05     ;Next line has been saved
ELF_HIDDEN                  equ   BIT06     ;Current line is hidden
ELF_ERROR_MARKED            equ   BIT07     ;Current line shows an error marker
ELF_BOOK_MARKED             equ   BIT08     ;Current line shows a book marker
;ELF_EOL_MARKED              equ   BIT09     ;Current line shows an EOL marker
ELF_HAS_EXPAND_SYMBOL       equ   BIT10
ELF_HAS_COLLAPSE_SYMBOL     equ   BIT11


;EditorLine char table flags
CHR_ALPHA                   equ   BIT00
CHR_BLANK                   equ   BIT01
CHR_OPERATOR                equ   BIT02
CHR_DEC                     equ   BIT03
CHR_HEX                     equ   BIT04
CHR_BIN                     equ   BIT05
CHR_OCT                     equ   BIT06
CHR_QUOTE                   equ   BIT07     ;Character starts or ends a string sequence ("')

CHR_WORD                    equ   CHR_ALPHA or CHR_DEC

.const
CharTable label BYTE
  ;NULL
  db 0
  ;SOH
  db 0
  ;STX
  db 0
  ;ETX
  db 0
  ;EDT
  db 0
  ;ENQ
  db 0
  ;ACK
  db 0
  ;BEL
  db 0
  ;BS
  db 0
  ;TAB
  db CHR_BLANK
  ;Line Feed
  db 0
  ;Vertical tab
  db 0
  ;FF
  db 0
  ;Carriage return
  db 0
  ;SO
  db 0
  ;SI
  db 0

  ;DLE
  db 0
  ;DC1
  db 0
  ;DC2
  db 0
  ;DC3
  db 0
  ;DC4
  db 0
  ;NAK
  db 0
  ;SYN
  db 0
  ;ETB
  db 0
  ;CAN
  db 0
  ;BM
  db 0
  ;SUB
  db 0
  ;Escape
  db 0
  ;FS
  db 0
  ;GS
  db 0
  ;RS
  db 0
  ;US
  db 0

  ;Space
  db CHR_BLANK
  ;!
  db CHR_OPERATOR
  ;"
  db CHR_QUOTE
  ;#
  db 0
  ;$
  db CHR_ALPHA
  ;%
  db CHR_OPERATOR
  ;&
  db CHR_OPERATOR
  ;'
  db CHR_QUOTE
  ;(
  db CHR_OPERATOR
  ;)
  db CHR_OPERATOR
  ;*
  db CHR_OPERATOR
  ;+
  db CHR_OPERATOR
  ;,
  db CHR_OPERATOR
  ;-
  db CHR_OPERATOR
  ;.
  db CHR_OPERATOR                                       ;If it is the 1st char then it is an CHR_ALPHA
  ;/
  db CHR_OPERATOR

  ;0
  db CHR_HEX or CHR_DEC or CHR_OCT or CHR_BIN
  ;1
  db CHR_HEX or CHR_DEC or CHR_OCT or CHR_BIN
  ;2
  db CHR_HEX or CHR_DEC or CHR_OCT
  ;3
  db CHR_HEX or CHR_DEC or CHR_OCT
  ;4
  db CHR_HEX or CHR_DEC or CHR_OCT
  ;5
  db CHR_HEX or CHR_DEC or CHR_OCT
  ;6
  db CHR_HEX or CHR_DEC or CHR_OCT
  ;7
  db CHR_HEX or CHR_DEC or CHR_OCT
  ;8
  db CHR_HEX or CHR_DEC
  ;9
  db CHR_HEX or CHR_DEC
  ;:
  db CHR_OPERATOR
  ;;
  db CHR_OPERATOR
  ;<
  db CHR_OPERATOR
  ;=
  db CHR_OPERATOR
  ;>
  db CHR_OPERATOR
  ;?
  db CHR_ALPHA

  ;@
  db CHR_ALPHA
  ;A
  db CHR_ALPHA or CHR_HEX
  ;B
  db CHR_ALPHA or CHR_HEX
  ;C
  db CHR_ALPHA or CHR_HEX
  ;D
  db CHR_ALPHA or CHR_HEX
  ;E
  db CHR_ALPHA or CHR_HEX
  ;F
  db CHR_ALPHA or CHR_HEX
  ;G
  db CHR_ALPHA
  ;H
  db CHR_ALPHA
  ;I
  db CHR_ALPHA
  ;J
  db CHR_ALPHA
  ;K
  db CHR_ALPHA
  ;L
  db CHR_ALPHA
  ;M
  db CHR_ALPHA
  ;N
  db CHR_ALPHA
  ;O
  db CHR_ALPHA

  ;P
  db CHR_ALPHA
  ;Q
  db CHR_ALPHA
  ;R
  db CHR_ALPHA
  ;S
  db CHR_ALPHA
  ;T
  db CHR_ALPHA
  ;U
  db CHR_ALPHA
  ;V
  db CHR_ALPHA
  ;W
  db CHR_ALPHA
  ;X
  db CHR_ALPHA
  ;Y
  db CHR_ALPHA
  ;Z
  db CHR_ALPHA
  ;[
  db CHR_OPERATOR
  ;\
  db CHR_OPERATOR
  ;]
  db CHR_OPERATOR
  ;^
  db CHR_OPERATOR
  ;_
  db CHR_ALPHA

  ;`
  db 0
  ;a
  db CHR_ALPHA or CHR_HEX
  ;b
  db CHR_ALPHA or CHR_HEX
  ;c
  db CHR_ALPHA or CHR_HEX
  ;d
  db CHR_ALPHA or CHR_HEX
  ;e
  db CHR_ALPHA or CHR_HEX
  ;f
  db CHR_ALPHA or CHR_HEX
  ;g
  db CHR_ALPHA
  ;h
  db CHR_ALPHA
  ;i
  db CHR_ALPHA
  ;j
  db CHR_ALPHA
  ;k
  db CHR_ALPHA
  ;l
  db CHR_ALPHA
  ;m
  db CHR_ALPHA
  ;n
  db CHR_ALPHA
  ;o
  db CHR_ALPHA
  ;p
  db CHR_ALPHA
  ;q
  db CHR_ALPHA
  ;r
  db CHR_ALPHA
  ;s
  db CHR_ALPHA
  ;t
  db CHR_ALPHA
  ;u
  db CHR_ALPHA
  ;v
  db CHR_ALPHA
  ;w
  db CHR_ALPHA
  ;x
  db CHR_ALPHA
  ;y
  db CHR_ALPHA
  ;z
  db CHR_ALPHA
  ;{
  db CHR_OPERATOR
  ;|
  db CHR_OPERATOR
  ;}
  db CHR_OPERATOR
  ;~
  db CHR_OPERATOR
  ;
  db CHR_ALPHA
CHAR_TABLE_ENTRIES = ($ - offset CharTable)/sizeof(BYTE)

.code
; ==================================================================================================
; EditorLine implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.BufferResize
; Purpose:    Get more memory to allocate the char buffer.
; Arguments:  Arg1: New char capacity not including the ZTC.
; Return:     xax -> Character buffer or NULL if failed.

Method EditorLine.BufferResize, uses xbx xsi, dNewCapacity:DWORD
  SetObject xsi
  mov xcx, [xsi].pOwner

  mov ebx, dNewCapacity
  .if ebx > [xcx].$Obj(Editor).dMaxLineCharCount
    mov [xcx].$Obj(Editor).dMaxLineCharCount, ebx    ;Keep tack of the max line length
  .endif

  .if ebx != [xsi].dCharCapacity || [xsi].pBuffer == NULL
    ;Calc requested size that matches the given granularity
    inc ebx                                             ;Always add size for the ZTC
    add ebx, ELN_GRANULARITY - 1
    and ebx, DWORD ptr not(ELN_GRANULARITY - 1)
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      add ebx, ebx
    endif

    mov ecx, ebx
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      shr ecx, 1
    endif
    dec ecx
    .if ecx != [xsi].dCharCapacity                      ;check if the capacity has changed
      ;Capacity has changed
      .if [xsi].pBuffer != NULL
        MemReAlloc [xsi].pBuffer, ebx
      .else
        MemAlloc ebx
        .if xax != NULL
          m2z CHR ptr [xax]                             ;Set ZTC
        .endif
      .endif
      .if xax != NULL
        mov [xsi].pBuffer, xax
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          shr ebx, 1
        endif
        dec ebx
        mov [xsi].dCharCapacity, ebx                    ;In characters not including the ZTC
      .else
        OCall xsi.ErrorReport, NULL, ELE_OUTOFMEMORY
        .if [xsi].dErrorCode != OBJ_OK
          mov xcx, [xsi].pOwner                         ;xcx -> Editor
          mov xdx, [xcx].$Obj(Editor).pOwner
          mov xax, [xdx].$Obj(ClientWnd).pOwner
          invoke MessageBox, [xax].$Obj(Application).hWnd, \
                             $OfsCStr("Out of memory expanding a line."), addr cError, MB_OK or MB_ICONERROR
          xor eax, eax                                  ;Failed
        .else
          mov xax, [xsi].pBuffer                        ;If we recovered from failure
        .endif
      .endif
    .else
      mov xax, [xsi].pBuffer
    .endif
  .else
    mov xax, [xsi].pBuffer
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.CharDelete
; Purpose:    Delete chars at a given position.
; Arguments:  Arg1: Position where to start deleting.
;             Arg2: Number of chars to delete. May be more than the buffer lenght.
;             Arg3: Line Index.
;             Arg4: ActionGroup. If 0, no ACTION will be logged.
; Return:     eax = Number of deleted chars or 0 if failed.

Method EditorLine.CharDelete, uses xbx xdi xsi, dDelIndex:DWORD, dCharCount:DWORD, dLineIndex:DWORD, dActionGroup:DWORD
  local dMoveSize:DWORD, pChars:PSTRING

  SetObject xsi
  xor eax, eax
  mov eax, dDelIndex
  mov edx, [xsi].dLength
  .if eax < edx && dCharCount != 0
    mov ecx, eax
    add ecx, dCharCount
    .if ecx > edx || dCharCount == -1
      ;Delete up to EOL
      mov xcx, [xsi].pBuffer
      lea xdx, [xcx + sizeof(CHR)*xax]
      mov pChars, xdx
      mov edi, [xsi].dLength
      sub edi, eax
      mov [xsi].dLength, eax

      ;Keep track of the change
      .if dActionGroup != 0
        MemAlloc sizeof(ACTION)
        .if xax != NULL
          mov xbx, xax
          mov [xbx].ACTION.dAction, AAT_DELETECHARS
          m2m [xbx].ACTION.dGroup, dActionGroup, ecx
          mov [xbx].ACTION.pEditorLine, xsi
          m2m [xbx].ACTION.dLineIndex, dLineIndex, edx
          m2m [xbx].ACTION.dPosIndex, dDelIndex, eax
          mov [xbx].ACTION.dChrCount, edi
          mov [xbx].ACTION.pChars, $invoke(StrCNew, pChars, edi)
          mov xcx, pChars
          mov CHR ptr [xcx], 0
          mov xdx, [xsi].pOwner
          OCall [xdx].$Obj(Editor).Actions::ActionCollection.Insert, xbx
        .endif
      .endif

    .else
      ;Delete inside the buffer => move remaining chars
      ;Keep track of the change
      .if dActionGroup != 0
        MemAlloc sizeof(ACTION)
        .if xax != NULL
          mov xbx, xax
          mov [xbx].ACTION.dAction, AAT_DELETECHARS
          m2m [xbx].ACTION.dGroup, dActionGroup, ecx
          mov [xbx].ACTION.pEditorLine, xsi
          m2m [xbx].ACTION.dLineIndex, dLineIndex, ecx
          m2m [xbx].ACTION.dPosIndex, dDelIndex, eax
          m2m [xbx].ACTION.dChrCount, dCharCount, edx
          mov ecx, dDelIndex
          mov xax, [xsi].pBuffer
          lea xcx, [xax + sizeof(CHR)*xcx]
          mov [xbx].ACTION.pChars, $invoke(StrCNew, xcx, edx)
          mov xdx, [xsi].pOwner 
          OCall [xdx].$Obj(Editor).Actions::ActionCollection.Insert, xbx
        .endif
      .endif

      mov edx, [xsi].dLength
      sub edx, dDelIndex
      lea edx, [sizeof(CHR)*edx + sizeof(CHR)]          ;Include the ZTC
      mov dMoveSize, edx
      mov edx, dDelIndex
      mov xax, [xsi].pBuffer
      lea xcx, [xax + sizeof(CHR)*xdx]
      mov edi, dCharCount
      if sizeof(CHR) eq 2
        add edi, edi
      endif
      lea xbx, [xcx + xdi]
      invoke MemShift, xcx, xbx, dMoveSize
      mov eax, [xsi].dLength
      sub eax, dCharCount
      mov [xsi].dLength, eax
    .endif
    OCall xsi.BufferResize, [xsi].dLength               ;Shrink Buffer if possible

    ;Manage the selection after deletion
    mov eax, [xsi].Selection.dBegIndex
    mov ecx, [xsi].Selection.dEndIndex
    sub eax, dDelIndex
    .if !SIGN? && !ZERO?
      sub [xsi].Selection.dBegIndex, eax
    .endif
    sub ecx, dDelIndex
    .if !SIGN? && !ZERO?
      dec ecx
      sub [xsi].Selection.dEndIndex, ecx
    .endif

    ;Housekeeping
    BitSet [xsi].dFlags, ELF_DIRTY_LINE_CURR
    OCall xsi.SetDirty

    mov eax, dCharCount

  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.CharInsert
; Purpose:    Insert chars at a given position.
; Arguments:  Arg1: Position where to start to insert.
;             Arg2: Number of chars to insert. -1 indicates to copy up the end of string.
;             Arg3: -> Chars to insert. If NULL, nothing is inserted.
;             Arg4: Line Index.
;             Arg5: ActionGroup. If 0, no ACTION will be logged.
; Return:     eax = Number of inserted chars or 0 if failed.

Method EditorLine.CharInsert, uses xbx xdi xsi, dInsIndex:DWORD, dCharCount:DWORD, pChars:POINTER, dLineIndex:DWORD, dActionGroup:DWORD
  local dMoveSize:DWORD

  SetObject xsi
  xor eax, eax
  .if pChars != NULL
    mov eax, dCharCount
    ;Handle special case of dCharCount -1
    .if eax == -1
      invoke StrLength, pChars
      mov dCharCount, eax
    .endif

    .if eax != 0
      ;If necessary get more memory
      add eax, [xsi].dLength
      .if eax >= [xsi].dCharCapacity
        OCall xsi.BufferResize, eax
        test xax, xax                                   ;Check pBuffer, if NULL, allocation failed
        jz @@EOM                                        ;Allocation failed
      .endif

      ;Make room to insert the new chars
      mov edx, [xsi].dLength
      sub edx, dInsIndex
      lea edx, [sizeof(CHR)*edx + sizeof(CHR)]          ;Include the ZTC
      mov dMoveSize, edx
      mov edx, dInsIndex
      mov xax, [xsi].pBuffer
      lea xbx, [xax + sizeof(CHR)*xdx]
      mov edi, dCharCount
      add [xsi].dLength, edi
      if sizeof(CHR) eq 2
        add edi, edi
      endif
      lea xcx, [xbx + xdi]
      invoke MemShift, xcx, xbx, dMoveSize

      ;Copy the source characters
      invoke MemClone, xbx, pChars, edi

      ;Keep track of the change
      .if dActionGroup != 0
        MemAlloc sizeof(ACTION)
        .if xax != NULL
          mov xbx, xax
          mov [xbx].ACTION.dAction, AAT_INSERTCHARS
          m2m [xbx].ACTION.dGroup, dActionGroup, ecx
          mov [xbx].ACTION.pEditorLine, xsi
          m2m [xbx].ACTION.dLineIndex, dLineIndex, ecx
          m2m [xbx].ACTION.dPosIndex, dInsIndex, eax
          m2m [xbx].ACTION.dChrCount, dCharCount, eax
          mov [xbx].ACTION.pChars, $invoke(StrCNew, pChars, dCharCount)
          mov xdx, [xsi].pOwner 
          OCall [xdx].$Obj(Editor).Actions::ActionCollection.Insert, xbx
        .endif
      .endif

      ;Manage the selection after insertion
      mov eax, [xsi].Selection.RANGE.dBegIndex
      mov ecx, [xsi].Selection.RANGE.dEndIndex
      mov edx, dCharCount
      .if dInsIndex <= eax
        add [xsi].Selection.RANGE.dBegIndex, edx
      .endif
      .if dInsIndex < ecx
        add [xsi].Selection.RANGE.dEndIndex, edx
      .endif

      ;Housekeeping
      OCall xsi.SetDirty

      mov eax, dCharCount
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.CharReplace
; Purpose:    Replace chars at a given position.
; Arguments:  Arg1: Position where to start to insert.
;             Arg2: Number of chars to insert. -1 indicates to copy up the end of string.
;             Arg3: -> Chars to insert. If NULL, nothing is inserted.
;             Arg4: Line Index.
;             Arg5: ActionGroup. If 0, no ACTION will be logged.
; Return:     eax = Number of inserted chars or 0 if failed.

Method EditorLine.CharReplace, uses xbx xsi, dRplIndex:DWORD, dCharCount:DWORD, pChars:POINTER, dLineIndex:DWORD, dActionGroup:DWORD
  SetObject xsi
  mov eax, dCharCount
  xor eax, eax
  .if pChars != NULL
    ;Handle special case of dCharCount -1
    mov eax, dCharCount
    .if eax == -1
      invoke StrLength, pChars
      mov dCharCount, eax
    .endif

    .if eax != 0
      add eax, dRplIndex

      .if eax > [xsi].dCharCapacity
        OCall xsi.BufferResize, eax
      .endif

      ;Keep track of the change
      .if dActionGroup != 0
        ;Make a copy of the original chars
        MemAlloc sizeof(ACTION)
        .if xax != NULL
          mov xbx, xax
          mov [xbx].ACTION.dAction, AAT_DELETECHARS
          m2m [xbx].ACTION.dGroup, dActionGroup, edx
          mov [xbx].ACTION.pEditorLine, xsi
          m2m [xbx].ACTION.dLineIndex, dLineIndex, ecx
          mrm [xbx].ACTION.dPosIndex, dRplIndex, edx
          m2m [xbx].ACTION.dChrCount, dCharCount, ecx
          mov xax, [xsi].pBuffer
          mov [xbx].ACTION.pChars, $invoke(StrCNew, addr [xax + xdx*sizeof(CHR)], dCharCount)
          mov xdx, [xsi].pOwner 
          OCall [xdx].$Obj(Editor).Actions::ActionCollection.Insert, xbx
        .endif
      .endif

      ;Copy the source characters
      mov xax, [xsi].pBuffer
      mov edx, dRplIndex
      lea xcx, [xax + sizeof(CHR)*xdx]
      mov eax, dCharCount
      add edx, eax
      .if edx > [xsi].dLength
        invoke StrCCopy, xcx, pChars, eax
      .else
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          add eax, eax
        endif
        invoke MemClone, xcx, pChars, eax
      .endif

      ;Keep track of the change
      .if dActionGroup != 0
        MemAlloc sizeof(ACTION)
        .if xax != NULL
          mov xbx, xax
          mov [xbx].ACTION.dAction, AAT_INSERTCHARS
          m2m [xbx].ACTION.dGroup, dActionGroup, ecx
          mov [xbx].ACTION.pEditorLine, xsi
          m2m [xbx].ACTION.dLineIndex, dLineIndex, ecx
          m2m [xbx].ACTION.dPosIndex, dRplIndex, eax
          m2m [xbx].ACTION.dChrCount, dCharCount, eax
          mov [xbx].ACTION.pChars, $invoke(StrCNew, pChars, dCharCount)
          mov xdx, [xsi].pOwner 
          OCall [xdx].$Obj(Editor).Actions::ActionCollection.Insert, xbx
        .endif
      .endif

      ;Housekeeping
      OCall xsi.SetDirty

      mov eax, dCharCount
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Done
; Purpose:    Finalize the EditorLine object.
; Arguments:  None.
; Return:     Nothing.

Method EditorLine.Done, uses xsi
;  DbgText "EditorLine.Done"
  SetObject xsi
  MemFree [xsi].pBuffer, MEM_SAFE_FREE
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Draw
; Purpose:    Draw the content of a EditorLine.
; Arguments:  Arg1: -> EditorView.
;             Arg2: -> Output RECT.
;             Arg3: Character that exits a multiline Comment.
; Return:     eax = Character that exits a multiline Comment, otherwise zero.

if TARGET_BITNESS eq 64
  option stackbase:rbp                                  ;Required for the use of subroutines
endif

Method EditorLine.Draw, uses xbx xdi xsi, pEditorView:POINTER, pLineRect:PRECT, \
                                              dMultilineCommentExitChar:DWORD
  local hDC:HDC, CalcRect:RECT, DrawRect:RECT, pWord:POINTER
  local pCKW:$ObjPtr(KeywordCollection), pCKG:$ObjPtr(KeywordGroupCollection)
  local dInWord:DWORD, dQuoteChar:DWORD, dInComment:DWORD, dInMultilineComment:DWORD
  local CharWidth:DWORD, KW:KEYWORD, pDrawAttr:PDRAW_ATTR, dDontDraw:DWORD
  local dFirstCharIndex:DWORD, dLastCharIndex:DWORD, dSelEndIndex:DWORD
  local pEditorResources:$ObjPtr(EditorResources)

  SetObject xsi
  ?mov xdx, pEditorView
  m2m hDC, [xdx].$Obj(EditorView).hTextDC, xcx
  mov xax, [xsi].pOwner                                 ;xax -> Editor
  mov xdx, [xax].$Obj(Editor).pResources                ;xdx -> EditorResources
  mov pEditorResources, xdx

  ;Get some info from resources
  lea xax, [xdx].$Obj(EditorResources).Keywords
  mov pCKW, xax
  lea xax, [xdx].$Obj(EditorResources).KeywordGroups
  mov pCKG, xax
  m2m CharWidth, [xdx].$Obj(EditorResources).EditorTextRegular.FontMetric.x, xcx

  ;Setup RECTs
  mov xdx, pEditorView                                  ;xdx -> EditorView
  mov eax, [xdx].$Obj(EditorView).FirstVisChar.dCharIndex
  mul CharWidth

  mov xcx, pLineRect
  mov edx, [xcx].RECT.left
  sub edx, eax
  mov DrawRect.left, edx
  m2m DrawRect.top, [xcx].RECT.top, eax
  mov DrawRect.right, edx
  m2m DrawRect.bottom, [xcx].RECT.bottom, eax

  m2z CalcRect.left
  m2z CalcRect.top

  ;Reset all flags
  m2z dInWord
  m2z dDontDraw
  m2z dQuoteChar
  m2z dInComment
  m2z dInMultilineComment
  .if dMultilineCommentExitChar != 0                    ;A previous line triggered the ML c_omment
    mov dInMultilineComment, TRUE
  .endif

  ;Adjust dSelEndIndex to show an EOL selection marker
  mov xcx, [xsi].pOwner
  mov eax, [xsi].Selection.dEndIndex
  .ifBitClr [xcx].$Obj(Editor).dFlags, EDF_BLOCK_MODE
    .if eax == -1
      mov eax, [xsi].dLength
      inc eax
    .endif
  .endif
  mov dSelEndIndex, eax

  ;Start building words
  mov xdi, [xsi].pBuffer                                ;xdi -> Word begin
  .if xdi == NULL
    mov dLastCharIndex, 0                               ;Required for Subroutine DrawRestOfLine
    call DrawRestOfLine                                 ;Fill the rest
    mov eax, dMultilineCommentExitChar
    ret
  .endif
  xor ebx, ebx                                          ;Char count in Word
  .repeat                                               ;Start looping trough all chars in the line
    movzx eax, CHR ptr [xdi + sizeof(CHR)*xbx]          ;Fetch a char from buffer
    ;EOL handler
    .if eax == 0
      .if dInComment == FALSE
        call GetWordAttr                                ;Analyse what we have so on
      .else
        call CheckHilitedText
      .endif
      call DrawString                                   ;Draw it
      call DrawRestOfLine                               ;and fill the rest
      mov eax, dMultilineCommentExitChar
      ret
    .endif

    ;Multiline c_omment handler
    .if dInMultilineComment != FALSE
      mov xdx, pEditorResources
      lea xax, [xdx].$Obj(EditorResources).EditorTextComment
      mov pDrawAttr, xax
      .while TRUE                                       ;Loop through the rest of the line
        movzx eax, CHR ptr [xdi + sizeof(CHR)*xbx]      ;Fetch a char from buffer
        .break .if eax == 0
        .if dMultilineCommentExitChar == 0
          .if eax < CHAR_TABLE_ENTRIES
            lea xcx, CharTable
            .ifBitClr BYTE ptr [xcx + xax], CHR_BLANK   ;Lookup char type
              mov dMultilineCommentExitChar, eax        ;Get exit trigger char
              inc ebx
              .continue
            .endif
          .endif
        .endif
        .if dMultilineCommentExitChar == eax            ;End of c_omment detected
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
          mov ebx, [xsi].dLength                        ;Prepare fast exit
          add xbx, [xsi].pBuffer
          sub xbx, xdi                                  ;ebx = number of remaining chars in the line
      else
          mov ebx, [xsi].dLength                        ;Prepare fast exit
          mov xax, xdi
          sub xax, [xsi].pBuffer
          shr eax, 1
          sub ebx, eax                                  ;ebx = number of remaining chars in the line
      endif
          call DrawString                               ;Draw the rest of the line
          call DrawRestOfLine                           ;and fill the rest
          xor eax, eax                                  ;Disable multiline c_omment
          ret
        .endif
        inc ebx                                         ;Continue gattering chars
      .endw
      call DrawString                                   ;Draw the rest of the line
      call DrawRestOfLine                               ;and fill the rest
      mov eax, dMultilineCommentExitChar
      ret
    .endif

    ;Get Char type from lookup CharTable
    GetCharType eax, ecx

    ;Comment handler
    .if dInComment != FALSE                             ;We start with the c_omment loop, not the detection    
      .if dInWord == FALSE                              ;Check first char of a word
        .if (ecx & CHR_WORD) || (eax == '.')            ;If any bit set or the first char is a dot
          mov xdx, pEditorResources
          lea xax, [xdx].$Obj(EditorResources).EditorTextComment  ;Restore regular comment attr
          mov pDrawAttr, xax
          call DrawString                               ;Draw what we have so on
          mov dInWord, TRUE
        .endif
      .else
        .ifAllBitsClr ecx, CHR_WORD
          ;Check for hilited text
          call CheckHilitedText
          call DrawString
          mov xdx, pEditorResources
          lea xax, [xdx].$Obj(EditorResources).EditorTextComment  ;Restore regular comment attr
          mov pDrawAttr, xax
          mov dInWord, FALSE
        .endif
      .endif
      inc ebx
      .continue
    .endif

    .if eax == ";"                                      ;C_omment detection code
      call GetWordAttr                                  ;Analyse what we have so on
      call DrawString                                   ;Draw it
      mov dInComment, TRUE
      mov dInWord, FALSE
      mov xdx, pEditorResources
      lea xax, [xdx].$Obj(EditorResources).EditorTextComment
      mov pDrawAttr, xax
      inc ebx
      .continue
    .endif

    ;String handler
    .ifBitSet ecx, CHR_QUOTE                            ;Single or double quotes
      mov dQuoteChar, eax                               ;Store the trigger char
      inc ebx                                           ;Don't include the quote char => draw the quote
      mov xdx, pEditorResources
      lea xax, [xdx].$Obj(EditorResources).EditorTextRegular
      mov pDrawAttr, xax
      call DrawString
      mov xdx, pEditorResources
      lea xax, [xdx].$Obj(EditorResources).EditorTextQuote
      mov pDrawAttr, xax
      .while TRUE                                       ;Loop until a quote char is found
        movzx eax, CHR ptr [xdi + sizeof(CHR)*xbx]      ;Fetch a char from buffer
        .if eax == 0
          call DrawString
          call DrawRestOfLine                           ;and fill the rest
          mov eax, dMultilineCommentExitChar
          ret
        .elseif eax == dQuoteChar
          call DrawString
          inc ebx
          .break
        .endif
        inc ebx
      .endw
      .continue
    .endif

    ;Default handler
    .if dInWord == FALSE                                ;Check first char of a word
      .if (ecx & CHR_WORD) || (eax == '.')              ;If any bit set or the first char is a dot
        mov xdx, pEditorResources
        lea xax, [xdx].$Obj(EditorResources).EditorTextRegular
        mov pDrawAttr, xax                              ;white space attr
        call DrawString
        mov dInWord, TRUE
      .else
        inc ebx
        .continue                                       ;Build up the rest of the word
      .endif
    .else
      .ifAllBitsClr ecx, CHR_WORD
        ;Check if a multiline c_omment is started with the "comment" keyword
        .if ebx == 7
          invoke StrCIComp, xdi, $OfsCStr("COMMENT"), ebx
          .if eax == 0
            mov dInMultilineComment, TRUE
          .endif
        .endif
        call GetWordAttr
        call DrawString
        mov dInWord, FALSE
      .else
        inc ebx
        .continue                                       ;Build up the rest of the word
      .endif
    .endif

    inc ebx
  .until FALSE

Subroutine CheckHilitedText
  mov xcx, [xsi].pOwner
  .if [xcx].$Obj(Editor).dHilitedLen == ebx
    lea xax, [sizeof(CHR)*xbx]
    invoke MemComp, [xcx].$Obj(Editor).pHilitedWord, xdi, eax
    mov xdx, pEditorResources
    .if eax == 0
      lea xax, [xdx].$Obj(EditorResources).EditorTextHighlight
    .else
      lea xax, [xdx].$Obj(EditorResources).EditorTextComment
    .endif
    mov pDrawAttr, xax
  .endif
ExitSub

Subroutine GetWordAttr
  cmp ebx, 0
  .if ZERO?
    ExitSub
  .endif
  
  invoke IsDecNumber, xdi, ebx
  .if eax != FALSE
    mov xdx, pEditorResources
    lea xax, [xdx].$Obj(EditorResources).EditorTextNumber
    mov pDrawAttr, xax
    ExitSub
  .endif

  invoke IsHexNumber, xdi, ebx
  .if eax != FALSE
    mov xdx, pEditorResources
    lea xax, [xdx].$Obj(EditorResources).EditorTextNumber
    mov pDrawAttr, xax
    ExitSub
  .endif

  invoke IsBinNumber, xdi, ebx
  .if eax != FALSE
    mov xdx, pEditorResources
    lea xax, [xdx].$Obj(EditorResources).EditorTextNumber
    mov pDrawAttr, xax
    ExitSub
  .endif

  invoke IsOctNumber, xdi, ebx
  .if eax != FALSE
    mov xdx, pEditorResources
    lea xax, [xdx].$Obj(EditorResources).EditorTextNumber
    mov pDrawAttr, xax
    ExitSub
  .endif

  mov KW.pString, xdi                                   ;Fill a KEYWORD structure
  mov KW.dLength, ebx

  ;Check for hilited text
  mov xcx, [xsi].pOwner
  .if [xcx].$Obj(Editor).dHilitedLen == ebx
    lea xax, [sizeof(CHR)*xbx]
    invoke MemComp, [xcx].$Obj(Editor).pHilitedWord, xdi, eax
    .if eax == 0
      mov xdx, pEditorResources
      lea xax, [xdx].$Obj(EditorResources).EditorTextHighlight
      mov pDrawAttr, xax
      ExitSub
    .endif
  .endif

  ;Check for keywords
  OCall pCKW::KeywordCollection.Search, addr KW
  .if eax != FALSE
    ;It is a keyword
    mov edx, ecx
    OCall pCKW::KeywordCollection.ItemAt, edx           ;xax -> KEYWORD
    mov xcx, [xax].KEYWORD.pGroup                       ;Get keyword group
    lea xax, [xcx].KEYWORDGROUP                         ;xax -> DRAW_ATTR
  .else
    ;It is plain text => get plain text DRAW_ATTR
    mov xdx, pEditorResources
    lea xax, [xdx].$Obj(EditorResources).EditorTextRegular
  .endif
  mov pDrawAttr, xax
ExitSub


Subroutine DrawString
  ;Enter here with:
  ;  pDrawAttr -> DRAW_ATTR
  ;  xdi -> String start
  ;  ebx = String character count
  test ebx, ebx
  .if ZERO?
    mov dLastCharIndex, 0                               ;Required for Subroutine DrawRestOfLine
    ExitSub
  .endif
  mov pWord, xdi
  mov xcx, xdi
  sub xcx, [xsi].pBuffer
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr ecx, 1
  endif
  mov dFirstCharIndex, ecx
  lea edx, [ecx + ebx]
  mov dLastCharIndex, edx

  .if ecx >= dSelEndIndex || edx <= [xsi].Selection.dBegIndex
    ;Case 1: nothing selected, all regular text
    m2z CalcRect.right                                  ;Reset in case of a zero length string
    m2z CalcRect.bottom
    mov xdi, pDrawAttr
    invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
    invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
    mov eax, CalcRect.right
    add DrawRect.right, eax
    .if dDontDraw == FALSE
      invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
      invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
      invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
    .endif

  .else
    .if ecx >= [xsi].Selection.dBegIndex
      .if edx <= dSelEndIndex
        ;Case 2: all selected text
        ;Draw select text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov xax, pEditorResources
        lea xdi, [xax].$Obj(EditorResources).EditorTextSelect
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif

      .else
        ;Case 3: selected-regular text
        ;Draw select text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, dSelEndIndex
        sub ebx, dFirstCharIndex
        mov xax, pEditorResources
        lea xdi, [xax].$Obj(EditorResources).EditorTextSelect
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif
        m2m DrawRect.left, DrawRect.right, eax
        mov xdi, pWord
        lea xdi, [xdi + sizeof(CHR)*xbx]                ;Set new begin
        mov pWord, xdi

        ;Draw regular text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, dLastCharIndex
        sub ebx, dSelEndIndex
        mov xdi, pDrawAttr
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif

      .endif
    .else
      .if edx <= dSelEndIndex
        ;Case 4: regular-selected text
        ;Draw regular text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, [xsi].Selection.dBegIndex
        sub ebx, dFirstCharIndex
        mov xdi, pDrawAttr
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif
        m2m DrawRect.left, DrawRect.right, eax
        mov xdi, pWord
        lea xdi, [xdi + sizeof(CHR)*xbx]                ;Set new begin
        mov pWord, xdi

        ;Draw selected text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, dLastCharIndex
        sub ebx, [xsi].Selection.dBegIndex
        mov xax, pEditorResources
        lea xdi, [xax].$Obj(EditorResources).EditorTextSelect
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif

      .else
        ;Case 5: regular-selected-regular text
        ;Draw regular text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, [xsi].Selection.dBegIndex
        sub ebx, dFirstCharIndex
        mov xdi, pDrawAttr
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif
        m2m DrawRect.left, DrawRect.right, eax
        mov xdi, pWord
        lea xdi, [xdi + sizeof(CHR)*xbx]                ;Set new begin
        mov pWord, xdi

        ;Draw selected text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, dSelEndIndex
        sub ebx, [xsi].Selection.dBegIndex
        mov xax, pEditorResources
        lea xdi, [xax].$Obj(EditorResources).EditorTextSelect
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif
        m2m DrawRect.left, DrawRect.right, eax
        mov xdi, pWord
        lea xdi, [xdi + sizeof(CHR)*xbx]                ;Set new begin
        mov pWord, xdi

        ;Draw regular text
        m2z CalcRect.right                              ;Reset in case of a zero length string
        m2z CalcRect.bottom
        mov ebx, dLastCharIndex
        sub ebx, dSelEndIndex
        mov xdi, pDrawAttr
        invoke SelectObject, hDC, [xdi].DRAW_ATTR.hFont
        invoke DrawText, hDC, pWord, ebx, addr CalcRect, ELN_DRAW_TEXT_FLAGS or DT_CALCRECT
        mov eax, CalcRect.right
        add DrawRect.right, eax
        .if dDontDraw == FALSE
          invoke SetTextColor, hDC, [xdi].DRAW_ATTR.ForeColor
          invoke FillRect, hDC, addr DrawRect, [xdi].DRAW_ATTR.Background.hBrush
          invoke DrawText, hDC, pWord, ebx, addr DrawRect, ELN_DRAW_TEXT_FLAGS
        .endif
      .endif
    .endif
  .endif
  m2m DrawRect.left, DrawRect.right, eax                ;Adjust DrawRect

  mov xax, pWord
  lea xdi, [xax + sizeof(CHR)*xbx]                      ;Set new begin
  xor ebx, ebx                                          ;Reset char count

  mov eax, DrawRect.left
  mov xdx, pLineRect
  .if eax > [xdx].RECT.right
    mov dDontDraw, TRUE
  .endif
ExitSub


Subroutine DrawRestOfLine
  ;If necessary, fill the rest of the line with the proper background color
  .if dDontDraw == FALSE
    mov xbx, pEditorResources
    mov eax, DrawRect.right
    mov xcx, pLineRect
    .if eax < [xcx].RECT.right                          ;Check if filling is necessary
      mov eax, dSelEndIndex
      mov edx, dLastCharIndex
      .if eax > edx                                     ;Sel. EndIndex is at the right of the Last Char
        .if edx < [xsi].Selection.dBegIndex             ;Sel. BegIndex is at the right of the Last Char
          ;Draw regular background
          m2m DrawRect.left, DrawRect.right, edx
          mov eax, [xsi].Selection.dBegIndex
          sub eax, dLastCharIndex
          mul CharWidth
          add DrawRect.right, eax
          invoke FillRect, hDC, addr DrawRect, [xbx].$Obj(EditorResources).EditorBG.hBrush
          m2m dLastCharIndex, [xsi].Selection.dBegIndex, edx
        .endif
        m2m DrawRect.left, DrawRect.right, edx
        mov eax, dSelEndIndex
        sub eax, dLastCharIndex
        mul CharWidth
        add DrawRect.right, eax
        invoke FillRect, hDC, addr DrawRect, [xbx].$Obj(EditorResources).EditorTextSelect.Background.hBrush
      .endif
      ;Fill the rest up to the line end
      mov xcx, pLineRect
      m2m DrawRect.left, DrawRect.right, eax
      m2m DrawRect.right, [xcx].RECT.right, edx
      invoke FillRect, hDC, addr DrawRect, [xbx].$Obj(EditorResources).EditorBG.hBrush
    .endif
  .endif
ExitSub


MethodEnd

if TARGET_BITNESS eq 64
  option stackbase:??StackBase
endif

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Init
; Purpose:    Initialize the EditorLine object.
; Arguments:  Arg1: -> Owner object (Editor).
; Return:     Nothing.

Method EditorLine.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].dFlags, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.LineBreak
; Purpose:    Break the line into 2 lines. The new line is inserted after the current line.
; Arguments:  Arg1: Position where to break the line.
;             Arg2: Line index of this line.
;             Arg3: ActionGroup. If 0, no ACTION will be logged.
; Return:     xax -> New inserted line or NULL if failed.

Method EditorLine.LineBreak, uses xbx xdi xsi, dBreakIndex:DWORD, dLineIndex:DWORD, dActionGroup:DWORD
  local pNewEditorLine:$ObjPtr(EditorLine)

  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Editor

  New EditorLine
  .if xax != NULL
    mov pNewEditorLine, xax

    ;Insert the new EditorLine
    inc dLineIndex
    OCall [xbx].$Obj(Editor).Lines::Collection.InsertAt, dLineIndex, xax

    ;Initialize the new EditorLine
    OCall pNewEditorLine::EditorLine.Init, xbx

    ;Keep track of the change
    .if dActionGroup != 0
      MemAlloc sizeof(ACTION)
      .if xax != NULL
        mov [xax].ACTION.dAction, AAT_INSERTLINE
        m2m [xax].ACTION.dGroup, dActionGroup, edx
        m2m [xax].ACTION.pEditorLine, pNewEditorLine, xdx
        m2m [xax].ACTION.dLineIndex, dLineIndex, ecx
        OCall [xbx].$Obj(Editor).Actions::ActionCollection.Insert, xax
      .endif
    .endif

    ;Copy broken off chars
    mov ecx, dBreakIndex
    mov xax, [xsi].pBuffer
    lea xdi, [xax + sizeof(CHR)*xcx]
    mov eax, [xsi].dLength
    .if SDWORD ptr ecx < eax
      sub eax, ecx
      OCall pNewEditorLine::EditorLine.CharInsert, 0, eax, xdi, dLineIndex, dActionGroup
      OCall xsi::EditorLine.CharDelete, dBreakIndex, -1, dLineIndex, dActionGroup
      OCall xsi.SetDirty                                ;Set dirty only if chars are moved
    .endif

    ;Housekeeping
    OCall xbx::Editor.InformInsertionOf, dLineIndex
    .ifBitClr [xsi].dFlags, ELF_HIDDEN
      inc [xbx].$Obj(Editor).dVisLineCount
    .endif

    mov xax, pNewEditorLine
    BitSet [xax].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_CURR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.LineDelete
; Purpose:    Remove this EditorLine instance from the Linked List.
; Arguments:  Arg1: Line index of this line.
;             Arg2: ActionGroup. If 0, no ACTION will be logged.
; Return:     xax -> Deleted EditorLine or NULL if failed.
; Note:       To destroy the EditorLine call Destroy the returned value.

Method EditorLine.LineDelete, uses xbx xsi, dLineIndex:DWORD, dActionGroup:DWORD
  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Editor
  OCall xbx::Editor.InformDeletionOf, dLineIndex
  .ifBitClr [xsi].dFlags, ELF_HIDDEN
    dec [xbx].$Obj(Editor).dVisLineCount
  .endif
  OCall xsi.SetDirty

  ;Set Dirty marker on previous line
  mov edx, dLineIndex
  dec edx
  .if !SIGN?
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
    .if xax != NULL
      BitSet [xax].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_NEXT
      BitClr [xax].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_NEXT
    .endif
  .endif

  ;Set Dirty marker on next line
  mov edx, dLineIndex
  inc edx
  .if edx != [xbx].$Obj(Editor).Lines.dCount 
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
    .if xax != NULL
      BitSet [xax].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_PREV
      BitClr [xax].$Obj(EditorLine).dFlags, ELF_SAVED_LINE_PREV
    .endif
  .endif

  ;Do deletion
  OCall [xbx].$Obj(Editor).Lines::Collection.DeleteAt, dLineIndex

  ;Keep track of the change
  .if dActionGroup != 0
    MemAlloc sizeof(ACTION)
    .if xax != NULL
      mov [xax].ACTION.dAction, AAT_DELETELINE
      m2m [xax].ACTION.dGroup, dActionGroup, ecx
      mov [xax].ACTION.pEditorLine, xsi
      m2m [xax].ACTION.dLineIndex, dLineIndex, ecx
      OCall [xbx].$Obj(Editor).Actions::ActionCollection.Insert, xax
    .endif
  .endif

  mov xax, xsi                                          ;Return pSelf
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.LineJoinNext
; Purpose:    Join the current with the next EditorLine.
; Arguments:  Arg1: Line index of this EditorLine.
;             Arg2: ActionGroup. If 0, no ACTION will be logged.
; Return:     Nothing.

Method EditorLine.LineJoinNext, uses xbx xdi xsi, dLineIndex:DWORD, dActionGroup:DWORD
  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Editor

  ;Goto next EditorLine
  mov edi, dLineIndex
  inc edi                                               ;Index from next EditorLine
  .if edi < [xbx].$Obj(Editor).Lines.dCount
    OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edi ;Get next line
    mov xbx, xax
    OCall xsi.CharInsert, [xsi].dLength, [xbx].$Obj(EditorLine).dLength, \
                          [xbx].$Obj(EditorLine).pBuffer, dLineIndex, dActionGroup
    OCall xbx::EditorLine.LineDelete, edi, dActionGroup
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.LineJoinPrev
; Purpose:    Join the current with the previous EditorLine.
; Arguments:  Arg1: Line Number of this EditorLine.
;             Arg2: ActionGroup. If 0, no ACTION will be logged.
; Return:     Nothing.

Method EditorLine.LineJoinPrev, uses xbx xsi, dLineIndex:DWORD, dActionGroup:DWORD
  SetObject xsi
  ;Goto previous EditorLine
  dec dLineIndex                                      ;Index from next EditorLine
  mov xbx, [xsi].pOwner
  OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, dLineIndex ;Get pev line
  .if xax != NULL
    mov xbx, xax
    BitSet [xbx].$Obj(EditorLine).dFlags, ELF_DIRTY_LINE_CURR
    OCall xbx::EditorLine.CharInsert, [xbx].$Obj(EditorLine).dLength, [xsi].dLength, [xsi].pBuffer, dLineIndex, dActionGroup
    inc dLineIndex
    OCall xsi.LineDelete, dLineIndex, dActionGroup
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.LineReinsert
; Purpose:    Reinsert an exiting line
; Arguments:  Arg1: Line index of this EditorLine.
;             Arg2: ActionGroup. If 0, no ACTION will be logged.
; Return:     Nothing.

Method EditorLine.LineReinsert, uses xbx xsi, dLineIndex:DWORD, dActionGroup:DWORD
  SetObject xsi
  mov xbx, [xsi].pOwner
  OCall [xbx].$Obj(Editor).Lines::Collection.InsertAt, dLineIndex, xsi 
  OCall xbx::Editor.InformInsertionOf, dLineIndex
  inc [xbx].$Obj(Editor).dVisLineCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Redo
; Purpose:    Restore the last undo action.
; Arguments:  Arg1: -> ACTION
; Return:     Nothing.

Method EditorLine.Redo, uses xbx xsi, pAction:POINTER
  SetObject xsi
  mov xbx, pAction
  .if [xbx].ACTION.dAction == AAT_DELETECHARS
    OCall xsi.CharDelete, [xbx].ACTION.dPosIndex, [xbx].ACTION.dChrCount, [xbx].ACTION.dLineIndex, 0
;    mov [xsi].Selection.dBegIndex, 0
;    mov [xsi].Selection.dEndIndex, 0

  .elseif [xbx].ACTION.dAction == AAT_INSERTCHARS
    OCall xsi.CharInsert, [xbx].ACTION.dPosIndex, [xbx].ACTION.dChrCount, [xbx].ACTION.pChars, [xbx].ACTION.dLineIndex, 0
;    mov [xsi].Selection.dBegIndex, 0
;    mov [xsi].Selection.dEndIndex, 0

  .elseif [xbx].ACTION.dAction == AAT_DELETELINE
    OCall xsi.LineDelete, [xbx].ACTION.dLineIndex, 0

  .elseif [xbx].ACTION.dAction == AAT_INSERTLINE
    OCall xsi.LineReinsert, [xbx].ACTION.dLineIndex, 0

  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.SelectionReset
; Purpose:    Reset the selected text from this line.
; Arguments:  None.
; Return:     eax = TRUE if the change has a visual impact, otherwise FALSE.

Method EditorLine.SelectionReset
  SetObject xcx
  mov eax, eax
  mov edx, [xcx].Selection.dBegIndex
  cmp edx, [xcx].Selection.dEndIndex
  setne al
  mov [xcx].Selection.dBegIndex, 0
  mov [xcx].Selection.dEndIndex, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.SetDirty
; Purpose:    Set the dirty flag and inform its owner.
; Arguments:  None.
; Return:     Nothing.

Method EditorLine.SetDirty, uses xsi
  SetObject xsi
  BitSet [xsi].dFlags, ELF_DIRTY_LINE_CURR
  BitClr [xsi].dFlags, ELF_SAVED_LINE_CURR

  OCall [xsi].pOwner::Editor.SetDirty, TRUE           ;Propagate the information
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.SpaceFill
; Purpose:    Fill the at the buffer end n spaces.
; Arguments:  Arg1: Number of spaces to fill up.
;             Arg2: Line Index.
;             Arg3: ActionGroup. If 0, no ACTION will be logged.
; Return:     Nothing.

Method EditorLine.SpaceFill, uses xbx xsi, dSpaceCount:DWORD, dLineIndex:DWORD, dActionGroup:DWORD
  local cChar:CHR
  
  SetObject xsi
  mov CHR ptr cChar, ' '
  mov ebx, dSpaceCount
  test ebx, ebx
  .while !ZERO?
    OCall xsi.CharInsert, [xsi].dLength, 1, addr cChar, dLineIndex, dActionGroup
    dec ebx
  .endw 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     EditorLine.Undo
; Purpose:    Undo the last action.
; Arguments:  Arg1: -> ACTION
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method EditorLine.Undo, uses xbx xsi, pAction:POINTER
  SetObject xsi
  mov xbx, pAction
  .if [xbx].ACTION.dAction == AAT_DELETECHARS
    OCall xsi.CharInsert, [xbx].ACTION.dPosIndex, [xbx].ACTION.dChrCount, [xbx].ACTION.pChars, [xbx].ACTION.dLineIndex, 0
;    mov [xsi].Selection.dBegIndex, 0
;    mov [xsi].Selection.dEndIndex, 0

  .elseif [xbx].ACTION.dAction == AAT_INSERTCHARS
    OCall xsi.CharDelete, [xbx].ACTION.dPosIndex, [xbx].ACTION.dChrCount, [xbx].ACTION.dLineIndex, 0
;    mov [xsi].Selection.dBegIndex, 0
;    mov [xsi].Selection.dEndIndex, 0

  .elseif [xbx].ACTION.dAction == AAT_DELETELINE
    OCall xsi.LineReinsert, [xbx].ACTION.dLineIndex, 0

  .elseif [xbx].ACTION.dAction == AAT_INSERTLINE
    OCall xsi.LineDelete, [xbx].ACTION.dLineIndex, 0

  .else
    xor eax, eax
  .endif
MethodEnd
