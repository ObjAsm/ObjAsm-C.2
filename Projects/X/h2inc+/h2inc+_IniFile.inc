; ==================================================================================================
; Title:    h2incX_IniFile.inc
; Author:   G. Friedrich
; Version:  C.1.0
; Purpose:  ObjAsm support of h2inc IniFiles.
; Notes:    Version 1.0.0, April 2018
;             - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ReadIniFile
; Purpose:   Reads h2incX.ini from the current directory to memory.
; Arguments: None.
; Return:    eax -> Memory buffer.
;            edx: Buffer size in bytes.

ReadIniFile proc uses ebx esi
    local dSize:DWORD, dBytesRead:DWORD
    local szName[MAX_PATH]:BYTE

    invoke GetModuleFileNameA, NULL, addr szName, sizeof szName  ;eax = string char count, not including ZTC
    xor esi, esi
    lea ecx, szName
    lea eax, [ecx + eax]
    .while eax > ecx
      .break .if (BYTE ptr [eax - 1] == '\') || (BYTE ptr [eax - 1] == '/') || (BYTE ptr [eax - 1] == ':')
      dec eax
    .endw
    invoke StrCopyA, eax, $OfsCStr("h2incX.ini")
    invoke CreateFile, addr szName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
    .if eax != INVALID_HANDLE_VALUE
      mov ebx, eax
      invoke GetFileSize, ebx, NULL
      mov dSize, eax
      add eax, 1000h        ;Roundup to 4096 boundary
      and ax, 0F000h
      invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
      .if eax != NULL
        mov esi, eax
        invoke ReadFile, ebx, esi, dSize, addr dBytesRead, NULL
        mov eax, dBytesRead
        m2z BYTE ptr [esi + eax]
        mov dSize, eax
      .else
        invoke printf, $OfsCStr("Out of memory reading profile file", lf)
      .endif
      invoke CloseHandle, ebx
    .else
      invoke printf, $OfsCStr("Profile file %s not found, using defaults!", lf), addr szName
    .endif
    mov eax, esi
    mov edx, dSize
    ret
ReadIniFile endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: FindIniSection
; Purpose:   Scans h2incX.ini for a given section.
; Arguments: Arg1: -> Memory buffer.
;            Arg2: -> Section name.
;            Arg3: Buffer size.
; Return:    eax -> Memory location or NULL if not found

FindIniSection proc uses esi edi ebx pBuffer:POINTER, pSection:PSTRINGA, dSize:DWORD
    local dStrLen:DWORD

    mov dStrLen, $invoke(StrLengthA, pSection)
    mov esi, pBuffer
    mov ebx, dSize
    mov al, lf
    or ebx, ebx
    .while !ZERO?
      mov ah, al
      lodsb
      .if (ax == 0A00h + '[')
        mov edi, pSection
        mov ecx, dStrLen
        mov edx, esi
        repz cmpsb
        .if ZERO?
          lodsb
          .if al == ']'
            .repeat
              lodsb
            .until (al == lf) || (al == 0)
            .if al == lf
              mov eax, esi
              jmp @Exit
            .endif
          .endif
        .endif
        mov esi, edx
      .endif
      dec ebx
    .endw
    xor eax, eax
@Exit:
    dprintf <"FindIniSection(%s) at character %u">, pSection, eax
    ret
FindIniSection endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: LoadTableStrings
; Purpose:   Load strings from memory buffer into destination table.
; Arguments: Arg1: -> Memory buffer.
;            Arg2: -> Destination table.
; Return:    eax = string count.

LoadTableStrings proc uses esi edi pBuffer:POINTER, pTable:POINTER
    mov esi, pBuffer
    mov edi, pTable
    xor ecx, ecx
    .while TRUE
      mov al, [esi]
      .break .if (al == 0) || (al == '[')
      .if (al <= ' ') || (al == ';')
        .repeat
          lodsb
        .until (al == 0) || (al == lf)
        .break .if al == 0
      .else
        mov dl, '='
        call @AddStr
        .if al == '='
          mov dl, 0
          call @AddStr
        .endif
        .break .if al == 0
      .endif
    .endw
    mov eax, ecx
    dprintf <"LoadTableStrings()=%u strings">, eax
    ret

@AddStr:
    .if edi != NULL
      mov [edi], esi
      add edi, sizeof(POINTER)
    .endif
    inc ecx
    .repeat
      lodsb
    .until (al == 0) || (al == lf) || (al == dl)
    .if edi != NULL
      .if BYTE ptr [esi - 2] == cr
        m2z BYTE ptr [esi - 2]
      .else
        m2z BYTE ptr [esi - 1]
      .endif
    .endif
    retn
LoadTableStrings endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: LoadTablesFromProfile
; Purpose:   Load all tables from memory buffer.
; Arguments: Arg1: -> Memory Buffer.
;            Arg2: -> Buffer size.
; Return:    Nothing.

LoadTablesFromProfile proc uses esi ebx pBuffer:POINTER, dSize:DWORD
    mov ebx, offset g_ConvTable
    .while [ebx].CONV_TAB_ENTRY.pSectionName != NULL
      xor eax, eax
      .if pBuffer != NULL
        invoke FindIniSection, pBuffer, [ebx].CONV_TAB_ENTRY.pSectionName, dSize
      .endif
      .if eax != NULL
        mov esi, eax
        invoke LoadTableStrings, esi, 0                   ;Get necessary buffer size
        inc eax
        shl eax, 2
        .if eax != 0
          invoke LocalAlloc, LMEM_FIXED or LMEM_ZEROINIT, eax
          mov ecx, [ebx].CONV_TAB_ENTRY.pList
          mov [ecx], eax
          .if eax != NULL
            invoke LoadTableStrings, esi, eax             ;Read into buffer
          .endif
        .endif
      .else
        mov ecx, [ebx].CONV_TAB_ENTRY.pList
        m2m [ecx], [ebx].CONV_TAB_ENTRY.pDefault, eax     ;Assign default values
      .endif
      add ebx, sizeof CONV_TAB_ENTRY
    .endw
    ret
LoadTablesFromProfile endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ConvertTables
; Purpose:   Some tables contain strings expected to be numerical values. Convert them.
; Arguments: None.
; Return:    Nothing.

ConvertTables proc uses esi edi ebx
    assume esi:PCONV_TAB_ENTRY

    mov esi, offset g_ConvTable
    .while [esi].pSectionName
      .if [esi].dFlags & CF_ATTR
        mov ecx, [esi].pList
        mov ecx, [ecx]
        .if ecx != [esi].pDefault
          mov edi, ecx
          .while POINTER ptr [edi] != NULL
            mov eax, [edi + sizeof(NAME_ITEM)]
            .if eax != 0
              invoke atol, eax
              mov [edi + sizeof(DWORD)], eax
            .endif
            add edi, sizeof(PROPERTY_ITEM)
          .endw
        .endif
      .endif
      .if [esi].dFlags & CF_ATTR
        mov ebx, sizeof(PROPERTY_ITEM)
      .else
        mov ebx, sizeof(NAME_ITEM)
      .endif
;----------------------------- convert string to lower case
      .if [esi].dFlags & CF_CASE
        mov edi, [esi].pList
        mov edi, [edi]
        .while POINTER ptr [edi] != NULL
          invoke StrLowerA, POINTER ptr [edi]
          add edi, ebx
        .endw
      .endif
;----------------------------- sort string table
      .if [esi].dFlags & CF_SORT
        mov edi, [esi].pList
        mov edi, [edi].SORTARRAY.pItems
        push edi
        xor ecx, ecx
        .while POINTER ptr [edi] != NULL
          add edi, ebx
          inc ecx
        .endw
        pop edi
        mov edx, [esi].pList
        mov [edx].SORTARRAY.dItemCount, ecx
        invoke qsort, edi, ecx, ebx, offset CmpProc
      .endif
      add esi, sizeof(CONV_TAB_ENTRY)
    .endw
    ret
    assume esi:nothing
ConvertTables endp
