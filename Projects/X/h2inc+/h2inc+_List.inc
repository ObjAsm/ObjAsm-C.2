; ==================================================================================================
; Title:      h2inc+_List.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm support of h2inc+ List objects.
; Notes:      See h2inc+.asm
; ==================================================================================================


LST_OUT_OF_MEMORY   equ 124554
LST_OPEN_FILE_ERROR equ 125473

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     List
; Purpose:    Mantain a sorted list of items in the Memory Heap.

Object List, , SortedStrCollectionA
  RedefineMethod    Init,         POINTER, DWORD, DWORD, DWORD ;-> Owner, Count, Increment, Flags
  RedefineMethod    DestroyItem,  PSTRINGA
  StaticMethod      LoadFromFile, PSTRINGW
  StaticMethod      SaveToFile,   PSTRINGW

  DefineVariable    dFlags,       DWORD
ObjectEnd


; ==================================================================================================

if IMPLEMENT

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     List.DestroyItem
; Purpose:    Remove previous functionality.
; Arguments:  Arg1: -> ANSI string.
; Return:     Nothing.

Method List.DestroyItem,, pItem:PSTRINGA
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     List.Init
; Purpose:    Initialize the List with a limit (dLimit), an increasing step (dDelta) and flags.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: Flags.
; Return:     Nothing.

Method List.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dFlags:DWORD
  ACall Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
  SetObject xcx
  m2m [xcx].dFlags, dFlags, eax
MethodEnd
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     List.LoadFromFile
; Purpose:    Load list content from file.
; Arguments:  Arg1: -> WIDE Full File Name.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method List.LoadFromFile, uses xbx xdi xsi, pFullFileName:PSTRINGW
  local hFile:HANDLE, dBytesRead:DWORD
  local dFileSize:DWORD, dMemSize:DWORD, pMemBlock:POINTER, dLength:DWORD
  local dCount:DWORD, bChar:CHRA, pToken:PTOKEN, dCounter:DWORD

  SetObject xdi
  invoke CreateFileW, pFullFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    invoke GetFileSize, xax, NULL
    add eax, 3                                        ;CR + LF + Zero
    mov dFileSize, eax
    add eax, 1000h                                    ;Roundup to 4096
    and ax, 0F000h
    mov dMemSize, eax
    invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .if xax != NULL
      mov pMemBlock, xax
      invoke ReadFile, hFile, pMemBlock, dFileSize, addr dBytesRead, NULL
      mov eax, dBytesRead
      add xax, pMemBlock
      mov WORD ptr [xax], CR + 256*LF                 ;CR + LF
      mov CHRA ptr [xax + 2], 0                       ;ZTC
    .else
      DbgWriteF,, $OfsCStr("Out of memory reading ¦SU file", CRLF), pFileName
      mov [xdi].dErrorCode, LST_OUT_OF_MEMORY
      xor eax, eax
      mov pMemBlock, xax
      jmp @@EOM
    .endif
    invoke CloseHandle, hFile

    mov xbx, pMemBlock
    .if xbx != NULL
      mov xsi, xbx
      .while TRUE
        xor ecx, ecx
        .repeat
          lodsb
          inc ecx
        .until (al == CR) || (al == 0) || (al == "=")
        .break .if al == 0 || ecx == 1
        mov CHRA ptr [xsi - 1], 0                     ;Set ZTC, for StrCollection.Compare 
        .if al != "="
          inc xsi                                     ;Skip LF
        .endif
        dec ecx
        mov dCount, ecx
        mov bChar, al

        .ifBitSet [xdi].dFlags, CF_LCS
          invoke StrLowerA, xbx
        .endif

        .ifBitSet [xdi].dFlags, CF_ATR
          mov dLength, ecx
          mov al, bChar
          .if al == "="
            mov pToken, xsi
            .repeat
              lodsb
            .until (al == CR) || (al == 0)
            .break .if al == 0
            mov CHRA ptr [xsi - 1], 0                 ;Set ZTC
            inc xsi                                   ;Skip LF
            invoke dec2dwordA, pToken
          .else
            xor eax, eax                              ;Missing Attribute => assume 0
          .endif
          invoke InsertAttr, xdi, xbx, dLength, eax

        .elseIfBitSet [xdi].dFlags, CF_CNV
          mov dLength, ecx
          mov al, bChar
          .if al == "="
            mov pToken, xsi
            mov dCounter, 0
            .repeat
              lodsb
              inc dCounter
            .until (al == CR) || (al == 0)
            .break .if al == 0
            mov CHRA ptr [xsi - 1], 0                 ;Set ZTC
            inc xsi                                   ;Skip LF
            mov xax, pToken
          .else
            lea xax, szEmpty
            mov dCounter, 1
          .endif
          invoke InsertEqui, xdi, xbx, dLength, xax, dCounter

        .else                                         ;Single string
          invoke InsertStrg, xdi, xbx, dCount
          mov al, bChar
          .if al == "="                               ;Malformed input
            .repeat                                   ;Skip chars until CR or Zero
              lodsb
              inc ecx
            .until (al == CR) || (al == 0)
            .break .if al == 0
            mov CHRA ptr [xsi - 1], 0                 ;Set ZTC
            inc xsi                                   ;Skip LF
          .endif
        .endif

        mov xbx, xsi
      .endw
    .endif
    invoke VirtualFree, pMemBlock, 0, MEM_RELEASE
    mov eax, TRUE

  .else
    mov [xdi].dErrorCode, LST_OPEN_FILE_ERROR
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     List.SaveToFile
; Purpose:    Save list content to file.
; Arguments:  Arg1: -> WIDE Full FileName.
; Return:     Nothing.

Method List.SaveToFile, uses xbx xdi xsi, pFullFileName:PSTRINGW
  local hFile:HANDLE, cBuffer[1024]:CHRA, dBytesWritten:DWORD

  SetObject xsi
  invoke CreateFileW, pFullFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    .ifBitSet [xsi].dFlags, CF_CNV
      .ColForEach [xsi]
        mov edx, [xax - sizeof(DWORD)]                  ;Get the size
        lea xdi, cBuffer
        lea xbx, [xax + xdx + sizeof(DWORD)]            ;xbx -> next string
        WriteFA xdi, "¦SA=¦SA\n", xax, xbx
        lea xax, cBuffer
        mov xdx, xax
        sub xdi, xax
        invoke WriteFile, hFile, xdx, edi, addr dBytesWritten, NULL
      .ColNext
    .elseIfBitSet [xsi].dFlags, CF_ATR
      .ColForEach [xsi]
        mov edx, [xax - sizeof(DWORD)]                  ;Get the size
        lea xdi, cBuffer
        lea xbx, [xax + xdx]                            ;xbx -> value
        WriteFA xdi, "¦SA=¦UD\n", xax, DWORD ptr [xbx]
        lea xax, cBuffer
        mov xdx, xax
        sub xdi, xax
        invoke WriteFile, hFile, xdx, edi, addr dBytesWritten, NULL
      .ColNext
    .else
      .ColForEach [xsi]
        lea xdi, cBuffer
        WriteFA xdi, "¦SA\n", xax
        lea xax, cBuffer
        mov xdx, xax
        sub xdi, xax
        invoke WriteFile, hFile, xdx, edi, addr dBytesWritten, NULL
      .ColNext
    .endif
    invoke CloseHandle, hFile
  .endif
MethodEnd

endif
