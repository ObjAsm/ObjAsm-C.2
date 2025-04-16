; ==================================================================================================
; Title:      ADE_IniFileReader.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm IniFile reader implementation.
; ==================================================================================================


IFR_OUT_OF_MEMORY       equ   180001
IFR_OUT_OF_SYM_SPACE    equ   180002
IFR_FILE_NOT_FOUND      equ   180003
IFR_SECTION_NOT_FOUND   equ   180004


; ==================================================================================================
; IniFileReader implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IniFileReader.Done
; Purpose:    Finalizes the object.
; Arguments:  None.
; Return:     Nothing.

Method IniFileReader.Done, uses xsi
  SetObject xsi
  .if [xsi].pMemBlock != NULL
    invoke VirtualFree, [xsi].pMemBlock, 0, MEM_RELEASE
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFileReader.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner.
;             Arg2: -> MemoryHeap.
; Return:     eax = BYTEs read.

Method IniFileReader.Init, uses xbx xdi xsi, pOwner:POINTER, pMemHeap:$ObjPtr(MemoryHeap)
  local hFile:HANDLE, dBytesRead:DWORD, cName[MAX_PATH]:CHR, dFileSize:DWORD, cMessage[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].pMemHeap, pMemHeap, xax
  invoke GetModuleFileName, NULL, addr cName, lengthof(cName)  ;eax = char count, not including ZTC
  lea xdx, cName
  lea xcx, [xdx + sizeof(CHR)*xax - sizeof(CHR)]
  .while xcx >= xdx
    .break .if (CHR ptr [xcx] == "\") || (CHR ptr [xcx] == "/") || (CHR ptr [xcx] == ':')
    sub xcx, sizeof(CHR)
  .endw
  add xcx, sizeof(CHR)
  invoke StrCopy, xcx, addr szIniFileName
  invoke CreateFileW, addr cName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, \
                     FILE_ATTRIBUTE_ARCHIVE, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    invoke GetFileSize, xax, NULL
    mov dFileSize, eax
    add eax, 1000h                    ;Roundup to 4096
    and ax, 0F000h
    mov [xsi].dMemSize, eax
    invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .if xax != NULL
      mov [xsi].pMemBlock, xax
      invoke ReadFile, hFile, [xsi].pMemBlock, dFileSize, addr dBytesRead, NULL
      mov eax, dBytesRead
      add xax, [xsi].pMemBlock
      mov CHRA ptr [xax], 0           ;ZTC
    .else
      mov xbx, [xsi].pOwner
      OCall xbx::Application.ShowError, $OfsCStr("out of memory reading the ini-file")
      mov [xbx].$Obj(Application).bTerminate, TRUE
      mov [xsi].dErrorCode, IFR_OUT_OF_MEMORY
      xor eax, eax
    .endif
    invoke CloseHandle, hFile
  .else
    lea xdi, cMessage
    WriteF xdi, "ini-file \`¦SU\` not found, using application defaults...", addr cName
    OCall [xsi].pOwner::Application.ShowWarning, WARNING_SEVERE, addr cMessage
    mov [xsi].dErrorCode, IFR_FILE_NOT_FOUND
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IniFileReader.LoadList
; Purpose:    Scans h2inc+.ini for a given section.
; Arguments:  Arg1: -> LIST_SETUP of that list.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IniFileReader.LoadList, uses xbx xdi xsi, pListSetup:PLIST_SETUP
  local pMemHeap:$ObjPtr(MemoryHeap), pSectionName:PSTRINGA, dStrLen:DWORD
  local pWord:POINTER, dCharCount:DWORD, cLastChar:CHRA, cMessage[1024]:CHR

  SetObject xcx
  m2m pMemHeap, [xcx].pMemHeap, xax                   ;Get a local copy

  ;Find section
  mov xax, pListSetup
  mrm pSectionName, [xax].LIST_SETUP.pSectionName, xdx
  mov eax, DWORD ptr [xdx - sizeof(DWORD)]            ;Get string size
  dec eax                                             ;Calculate the length discarding the ZTC
  mov dStrLen, eax

  ;Search for a LF and opening square bracket
  mov xsi, [xcx].pMemBlock
  mov ebx, [xcx].dMemSize

  ReleaseObject 
  mov al, LF
  test ebx, ebx
  .while !ZERO?
    mov ah, al
    lodsb
    .if ax == LF*256 + '['
      mov xdi, pSectionName
      mov ecx, dStrLen
      mov xdx, xsi
      repz cmpsb
      .if ZERO?
        lodsb
        .if al == ']'
          .repeat
            lodsb
          .until (al == LF) || (al == 0)
          .if al == LF
            jmp @SectionFound
          .endif
        .endif
      .endif
      mov xsi, xdx
    .endif
    dec ebx
  .endw

;Section not found
  mov xdi, pListSetup
  lea xbx, cMessage
  WriteF xbx, "ini-file section \´¦SA\´ not found, using application defaults...", [xdi].LIST_SETUP.pSectionName
  OCall $ObjTmpl(Application)::Application.ShowWarning, WARNING_MAYOR, addr cMessage
  mov xsi, [xdi].LIST_SETUP.pDefault
  .while POINTER ptr [xsi] != NULL
    mov xbx, [xsi]
    OCall pMemHeap::MemoryHeap.AddBStrA, POINTER ptr [xsi], DWORD ptr [xbx - sizeof(DWORD)]
    mov pWord, xax
    .ifBitSet [xdi].LIST_SETUP.dFlags, CF_LCS
      invoke StrLowerA, xax
    .endif
    OCall [xdi].LIST_SETUP.pList::List.Insert, xax
    .if xax != NULL
      add xsi, sizeof(POINTER)
      .ifBitSet [xdi].LIST_SETUP.dFlags, CF_ATR
        OCall pMemHeap::MemoryHeap.AddDword, DWORD ptr [xsi]
        add xsi, sizeof(DWORD)
      .elseIfBitSet [xdi].LIST_SETUP.dFlags, CF_CNV
        mov xbx, [xsi]
        OCall pMemHeap::MemoryHeap.AddBStrA, POINTER ptr [xsi], DWORD ptr [xbx - sizeof(DWORD)]
        add xsi, sizeof(POINTER)
      .endif
    .else
      lea xbx, cMessage
      WriteF xbx, "inserting \´¦SA\´ from default application section \´¦SA\´ failed", pWord, [xdi].LIST_SETUP.pSectionName
      OCall $ObjTmpl(Application)::Application.ShowWarning, WARNING_MAYOR, addr cMessage
    .endif
  .endw
  mov eax, TRUE
  jmp @@EOM

@SectionFound:
  ;Load strings into List
  mov xdi, pListSetup
  lea xbx, cMessage
  WriteF xbx, "Ini-file section \´¦SA\´ found in memory at ¦HXh", [xdi].LIST_SETUP.pSectionName, xsi
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, addr cMessage
  xor ecx, ecx
  .while TRUE
    mov al, [xsi]
    .break .if (al == 0) || (al == '[')
    .if (al <= SPC) || (al == ';')
      .repeat
        lodsb
      .until (al == 0) || (al == CR)
      .break .if al == 0
    .else
      mov pWord, xsi
      xor ecx, ecx
      .repeat
        lodsb
        inc ecx
      .until (al == 0) || (al == CR) || (al == "=")
      mov dCharCount, ecx
      dec dCharCount
      mov cLastChar, al                               ;Remember last character
      m2z CHRA ptr [xsi - 1]                          ;Set ZTC
      OCall [xdi].LIST_SETUP.pList::List.Search, pWord
      .if eax != FALSE                                ;Duplicate found =>
        .if cLastChar == "="                          ; if "=" found => skip second string
          .repeat
            lodsb
          .until (al == 0) || (al == CR)              ;Stop on CR! xsi -> LF
        .endif
        inc xsi                                       ;In any case move from LF to the next char
        .continue
      .endif

      OCall pMemHeap::MemoryHeap.AddBStrA, pWord, dCharCount
      .if xax != NULL
        .ifBitSet [xdi].LIST_SETUP.dFlags, CF_LCS
          invoke StrLowerA, xax                       ;In place                     
        .endif
        OCall [xdi].LIST_SETUP.pList::List.Insert, xax
        .if xax != NULL
          .if cLastChar == "="
            mov pWord, xsi
            xor ecx, ecx
            .repeat
              lodsb
              inc ecx
            .until (al == 0) || (al == CR)
            .ifBitSet [xdi].LIST_SETUP.dFlags, CF_ATR
              mov CHRA ptr [xsi - 1], 0
              invoke dec2dwordA, pWord
              OCall pMemHeap::MemoryHeap.AddDword, eax
            .elseIfBitSet [xdi].LIST_SETUP.dFlags, CF_CNV
              mov eax, ecx
              dec eax
              OCall pMemHeap::MemoryHeap.AddBStrA, pWord, eax
            .endif
          .endif
          inc xsi                                     ;In any case move from LF to the next char
          .continue
        .else
          mov xdi, pListSetup
          lea xbx, cMessage
          WriteF xbx, "inserting \´¦SA\´ from file list \´¦SA\´ failed", pWord, [xdi].LIST_SETUP.pFileName
          OCall $ObjTmpl(Application)::Application.ShowWarning, WARNING_MAYOR, addr cMessage
        .endif
      .endif

      SetObject xcx
      mov [xcx].dErrorCode, IFR_OUT_OF_SYM_SPACE
      ReleaseObject
      xor eax, eax                                    ;Return FALSE
      jmp @@EOM
    .endif
  .endw
  mov eax, TRUE
MethodEnd
