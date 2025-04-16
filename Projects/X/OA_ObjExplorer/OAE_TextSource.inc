; ==================================================================================================
; Title:      OAE_TextSource.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    TextSource implementation for OA_ObjExplorer.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:    TextSource
; Purpose:   Text reading managment.

Object TextSource,, Primer
  RedefineMethod    Done
  StaticMethod      GetPrevLine
  StaticMethod      GetNextArgument
  StaticMethod      GetNextLine
  StaticMethod      GetNextWord
  RedefineMethod    Init,           POINTER, PSTRING  ;-> Owner, -> FileName
  StaticMethod      Reset

  DefineVariable    hSource,        HANDLE,     NULL  ;File HANDLE
  DefineVariable    dTotalSize,     DWORD,      0     ;Total character count in text source
  DefineVariable    dLineNumber,    DWORD,      0     ;Current line number from text source
  DefineVariable    dFileLines,     DWORD,      0     ;# of lines retunred by GetFileLinesA
  DefineVariable    pFileLines,     POINTER,    0     ;Buffer retunred by GetFileLinesA
  DefineVariable    dFileOffset,    DWORD,      0     ;Current file cursor offset
  DefineVariable    bCommentChar,   CHRA,       0     ;Used internally by GetNextWord

  Embed   MemStream,  MemoryStream                    ;Local line buffer
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.Done
; Purpose:    Finalizes TextSource object.
; Arguments:  None.
; Return:     Nothing.

Method TextSource.Done, uses xsi
  SetObject xsi
  OCall [xsi].MemStream::MemoryStream.Done
  invoke CloseHandle, [xsi].hSource
  .if [xsi].pFileLines != NULL
    MemFree [xsi].pFileLines
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.Init
; Purpose:    (Constructor) Initializes TextSource object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> File Name string.
; Return:     Nothing.

Method TextSource.Init, uses xsi, pOwner:POINTER, pFileName:PSTRING
  SetObject xsi
;  DbgText "TextSource.Init"
;  DbgStr pFileName
  ACall xsi.Init, pOwner
  mov [xsi].dFileOffset, 0
  OCall [xsi].MemStream::MemoryStream.Init, xsi, 50*1024, 50*1024, -1
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, NULL, \
                                OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
  mov [xsi].hSource, xax
  invoke GetFileLinesA, xax
  mov [xsi].dFileLines, eax
  mov [xsi].pFileLines, xcx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.GetPrevLine
; Purpose:    Retrieves a new line from the text source into the object line buffer.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
;             ecx = Character offset.
;             edx = Character count.

Method TextSource.GetPrevLine, uses xbx xdi xsi
  local dBytesRead:DWORD

  SetObject xsi
  xor eax, eax
  mov [xsi].MemStream.dPosition, eax                    ;Position = 0
  mov [xsi].MemStream.dCurrSize, eax                    ;Fill level = 0

  ;The source is a file
  mov xcx, [xsi].pFileLines                             ;Array of line ending offsets
  .if [xsi].dLineNumber == 0
    xor eax, eax                                        ;Returns FALSE
  .else
    mov eax, [xsi].dLineNumber
    mov edi, [xcx + sizeof(DWORD)*xax]
    dec [xsi].dLineNumber
    mov eax, [xsi].dLineNumber
    .if ZERO?
      xor ebx, ebx
    .else
      mov ebx, [xcx + sizeof(DWORD)*xax]
    .endif
    sub edi, ebx
    lea edx, [edi + 1]                                  ;Space for ZTC
    .if edi > [xsi].MemStream.dLimit
      OCall [xsi].MemStream::MemoryStream.SetCapacity, edx
    .endif
    invoke SetFilePointer, [xsi].hSource, ebx, NULL, FILE_BEGIN
    invoke ReadFile, [xsi].hSource, [xsi].MemStream.pBuffer, edi, addr dBytesRead, NULL

    mov xax, [xsi].MemStream.pBuffer
    mov ecx, dBytesRead
    m2z CHRA ptr [xax + xcx]                            ;set ZTC

    mov eax, TRUE
    mov ecx, ebx                                        ;ecx = Char offset
    mov edx, edi                                        ;edx = Char count in this line
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.GetNextArgument
; Purpose:    Retrieves the next word from the object line buffer after a comma.
; Arguments:  None.
; Return:     eax -> Word or NULL if no more words exist.
;             ecx = Word length.
;             edx = Flags. 1 = line break

Method TextSource.GetNextArgument, uses xsi
  SetObject xsi
  OCall xsi.GetNextWord
  .while xax != NULL && dl != ','
    OCall xsi.GetNextWord
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.GetNextLine
; Purpose:    Retrieves a new line from the text source into the object line buffer.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method TextSource.GetNextLine, uses xbx xsi
  local dBytesRead:DWORD

  SetObject xsi
  xor eax, eax
  mov [xsi].MemStream.dPosition, eax
  mov [xsi].MemStream.dCurrSize, eax

  ;The source is a file; load next line into buffer
  mov xcx, [xsi].pFileLines
  mov eax, [xsi].dLineNumber
  .if eax >= [xsi].dFileLines
    xor eax, eax                                        ;Returns FALSE
  .else
    mov edx, [xcx + sizeof(DWORD)*xax]
    sub edx, [xsi].dFileOffset                          ;Get the line length
    mov ebx, edx
    inc edx                                             ;Room for ZTC
    .if edx > [xsi].MemStream.dLimit
      OCall [xsi].MemStream::MemoryStream.SetCapacity, edx
    .endif
    invoke SetFilePointer, [xsi].hSource, [xsi].dFileOffset, NULL, FILE_BEGIN

    invoke ReadFile, [xsi].hSource, [xsi].MemStream.pBuffer, ebx, addr dBytesRead, NULL

    mov edx, dBytesRead
    mov xax, [xsi].MemStream.pBuffer
    add xax, xdx
    ;check if we have a CRLF at the end of the line
    .if edx >= 2 && DCHRA ptr [xax - 2*sizeof(CHRA)] == 13 + 256*10
      sub xax, 2*sizeof(CHRA)
    .endif
    m2z CHRA ptr [xax]                                  ;Set ZTC

    add [xsi].dFileOffset, edx
    inc [xsi].dLineNumber

    mov eax, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.GetNextWord
; Purpose:    Retrieves the next word from the object line buffer.
; Arguments:  None.
; Return:     xax -> Word or NULL if no more words are available.
;             ecx = Word length
;             edx = Flags. Bit00 = line break, Bit01 = Comment
; Notes:      dInWord: 0 = at the beginning, 1 = in Word, 2 = at the end

Method TextSource.GetNextWord, uses xbx xdi xsi
  local dInWord:DWORD, dInString:DWORD, bStrDelimiter:BYTE, dFlags:DWORD

  SetObject xsi
  xor ecx, ecx                                          ;Reset ecx
  mov dInWord, ecx                                      ;  and use it to initialize
  mov dInString, ecx                                    ;  local variables
  mov ebx, [xsi].MemStream.dPosition
  add xbx, [xsi].MemStream.pBuffer                      ;xbx -> current CHRA

  .if [xsi].bCommentChar != 0
    invoke StrLScan, xbx, [xsi].bCommentChar
    .if eax == 0
      xor ecx, ecx
      xor edx, edx
      ExitMethod
    .else
      xor eax, eax
      xor ecx, ecx
      xor edx, edx
      mov [xsi].bCommentChar, al                        ;Reset CommentChar
    .endif
  .endif
  mov xdi, xbx                                          ;Word beginning pointer

  xor edx, edx
  .if xdi > [xsi].MemStream.pBuffer
    mov dl, CHRA ptr [xdi - sizeof CHRA]
    mov dFlags, edx
  .endif

  .if [xsi].MemStream.dPosition == 0
    BitSet dFlags, BIT17                                ;First word
  .endif

  .repeat
    mov al, [xbx]
    .if dInString == 1
      .if al == 0                                       ;Unexpected end of string
        xor eax, eax
        xor ecx, ecx
        jmp @@Exit
      .else
        inc xbx
        .if al == bStrDelimiter
          and dInString, 0
          mov xdi, xbx
        .endif
      .endif
    .else
      .if (al == "'") || (al == '"')
        mov dInString, 1
        mov bStrDelimiter, al
        inc xbx
      .else
        .if al == 0 || al == ";"
          .if dInWord == 0
            xor eax, eax
            xor ecx, ecx
          .else
            mov xax, xdi
          .endif
          jmp @@Exit
        .else
          .if al == " " || al ==  9
            .if dInWord == 0
              inc xdi
            .elseif dInWord == 1
              mov dInWord, 2
            .endif
            inc xbx
          .elseif al == "," || al == "." || \
              al == "+" || al == "-" || al == "*" || al == "/" || \
              al == "=" || al == "!" || al == "<" || al == ">" || \
              al == "[" || al == "]" || \
              al == "(" || al == ")" || \
              al == "{" || al == "}"                    ;":" is excluded to allow the
            mov xax, xdi                                ;addtion of NameSpaces
            inc xbx
            jmp @@Exit
          .elseif al == "\"                             ;Line break
            mov xax, xdi
            inc xbx
            BitSet dFlags, BIT16
            jmp @@Exit
          .else
            .if dInWord == 0
              mov dInWord, 1
              inc xbx
              inc ecx
            .elseif dInWord == 1
              inc xbx
              inc ecx
            .else
              mov xax, xdi
              jmp @@Exit
            .endif
          .endif
        .endif
      .endif
    .endif
  .until FALSE

@@Exit:
  sub xbx, [xsi].MemStream.pBuffer
  mov [xsi].MemStream.dPosition, ebx

  .if xax != NULL && ecx != 0
    .ifBitSet dFlags, BIT17
      .if ecx == lengthof bComment
        mov xbx, xax
        mov edi, ecx
        invoke StrCIComp, offset bComment, xbx, edi
        .if ZERO?
          add xdi, xbx
          inc xdi
          .repeat                                       ;find the comment marker
            mov al, CHRA ptr [xdi]
            .if al == VK_SPACE || al == VK_TAB
              inc xdi
            .else
              .break
            .endif
          .until FALSE
          mov [xsi].bCommentChar, al
          xor eax, eax
          xor ecx, ecx
        .else
          mov ecx, edi
          mov xax, xbx
        .endif
      .endif
    .endif
  .endif
  mov edx, dFlags
;  DbgStr xax
;  DbgDec [xsi].dLineNumber
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextSource.Reset
; Purpose:    Resets the stream position to zero.
; Arguments:  None.
; Return:     Nothing.

Method TextSource.Reset, uses xsi
  SetObject xsi
  xor eax, eax
  mov [xsi].MemStream.dPosition, eax                    ;Position = 0
  mov [xsi].MemStream.dCurrSize, eax                    ;Fill level = 0
  mov [xsi].dLineNumber, eax

  OCall [xsi].MemStream::Stream.Seek, QWORD ptr 0, STM_BEGIN
MethodEnd

endif