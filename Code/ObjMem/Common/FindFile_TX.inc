; ==================================================================================================
; Title:      FindFile_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2020.
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


.code
align ALIGN_CODE
??SearchInDir proc uses xbx xdi xsi pFindFileParams:POINTER, pPosStr:POINTER
  local cPosStr[MAX_PATH]:CHR
  local hFindFile:HANDLE, FindFileData:WIN32_FIND_DATA
  local pNextSlash:PSTRING, pStrEnd:PSTRING

  lea xbx, FindFileData
  .if pPosStr != NULL
    mov xax, pFindFileParams
    mov xsi, $invoke(StrEnd, addr [xax].FIND_FILE_PARAMS.cPreStr)
    invoke StrLScan, pPosStr, "*"
    mov xdi, xax
    invoke StrLScan, pPosStr, "?"
    mov xcx, xax
    or xcx, xdi
    .if !ZERO?                                          ;Check if both are NULL
      .if xax == NULL
        mov xax, xdi
      .elseif xdi != NULL
        uMin xax, xdi                                   ;xax = Min(xax, xdi)
      .endif

      ;There is a wildcard => we have to recurse
      invoke StrLScan, xax, "\"
      mov pNextSlash, xax
      .if xax == NULL
        invoke StrCat, xsi, pPosStr                     ;PreStr + PosStr
      .else
        sub xax, pPosStr
        invoke StrCCat, xsi, pPosStr, eax               ;PreStr + PosStr up to "\"
      .endif

      mov xax, pFindFileParams
      lea xsi, [xax].FIND_FILE_PARAMS.cPreStr
      invoke StrRScan, xsi, "\"
      .if xax != NULL
        mov xsi, xax
        add xsi, sizeof(CHR)
      .endif

      mov xax, pFindFileParams
      invoke FindFirstFileEx, addr [xax].FIND_FILE_PARAMS.cPreStr, FindExInfoStandard, xbx, 0, \
                              NULL, FIND_FIRST_EX_LARGE_FETCH
      .if eax != INVALID_HANDLE_VALUE
        mov hFindFile, xax

        .repeat
          .ifBitSet [xbx].WIN32_FIND_DATA.dwFileAttributes, FILE_ATTRIBUTE_DIRECTORY  ;Directory?
            ;Skip ".." (parent directory)
            DoesStringMatch? [xbx].WIN32_FIND_DATA.cFileName, <..>
            .if !ZERO?
              ;If "." then search in the current directory
              DoesStringMatch? [xbx].WIN32_FIND_DATA.cFileName, <.>
              .if ZERO?
                .if xsi != NULL
                  m2z CHR ptr [xsi]                     ;Truncate if necessary
                .endif
                invoke ??SearchInDir, pFindFileParams, pNextSlash
                .break .if eax != 0
              .else
                invoke StrECopy, xsi, addr [xbx].WIN32_FIND_DATA.cFileName  ;Add dir name to PreStr
                mov pStrEnd, xax

                ;First search localy
                invoke ??SearchInDir, pFindFileParams, pNextSlash
                .break .if eax != 0
                mov xdx, pStrEnd
                m2z CHR ptr [xdx]                       ;Restore PreStr

                ;Then search recursively into subfolders => we create a new PosStr = "\*"
                lea xcx, cPosStr
                FillString [xcx], <\*>
                .if pNextSlash != NULL
                  add xcx, 2*sizeof(CHR)
                  invoke StrCopy, xcx, pNextSlash
                .endif
                invoke ??SearchInDir, pFindFileParams, addr cPosStr
                .break .if eax != 0
              .endif
            .endif
          .endif
          invoke FindNextFile, hFindFile, xbx
        .until eax == 0

        mov xbx, xax
        invoke FindClose, hFindFile
        mov xax, xbx
      .else
        xor eax, eax
      .endif
    .else
      invoke StrCopy, xsi, pPosStr
      invoke ??SearchInDir, pFindFileParams, NULL
    .endif

  .else
    ;Check that the path matches the filter and that the file exists
    mov xdi, pFindFileParams
    invoke StrIFilter, addr [xdi].FIND_FILE_PARAMS.cPreStr, [xdi].FIND_FILE_PARAMS.pFilter
    .if eax != FALSE
      mov xsi, $invoke(StrEnd, addr [xdi].FIND_FILE_PARAMS.cPreStr)
      mov CHR ptr [xsi], "\"
      add xsi, sizeof(CHR)
      invoke StrCopyA, xsi, [xdi].FIND_FILE_PARAMS.pFileName
      invoke FindFirstFile, addr [xdi].FIND_FILE_PARAMS.cPreStr, xbx
      .if xax == INVALID_HANDLE_VALUE
        m2z CHR ptr [xsi - sizeof(CHR)]                 ;Restore PreStr
        xor eax, eax                                    ;Return FALSE
      .else
        invoke FindClose, xax
        invoke GetFullPathName, addr [xdi].FIND_FILE_PARAMS.cPreStr, MAX_PATH, \
                                [xdi].FIND_FILE_PARAMS.pRetBuffer, NULL
      .endif
    .endif
  .endif
  ret
??SearchInDir endp

; --------------------------------------------------------------------------------------------------
; Procedure:  FindFile
; Purpose:    Search for a file in a list of paths.
; Arguments:  Arg1: -> File name.
;             Arg2: -> List of path strings. The end of the list is indicated with a ZTC.
;             Arg3: -> Buffer containing the full path and file name in which the file was found.
;                      Buffer length = MAX_PATH.
; Return:     eax = Number of chars copied to the destination buffer. 0 if the file was not found.
; Example:    invoke FindFile, $OfsCStr("free.inc"), $OfsCStr("\Here*",0), addr cBuf
;               Search free.inc in all \Here and suddirectories.

align ALIGN_CODE
ProcName proc uses xbx, pFileName:POINTER, pPaths:POINTER, pRetBuffer:POINTER
  local FindFileParams:FIND_FILE_PARAMS

  mov xcx, pRetBuffer
  .if xcx != NULL
    m2z CHR ptr [xcx]                                   ;In case pPaths -> CHR ptr 0
    ;Sanity check: all ptrs must be != NULL
    .if pFileName != NULL
      mov xbx, pPaths
      .if xbx != NULL
        mov FindFileParams.pRetBuffer, xcx
        m2m FindFileParams.pFileName, pFileName, xax
        ;Loop through the paths strings
        .while CHR ptr [xbx] != 0
          m2z FindFileParams.cPreStr                    ;Reset PreStr
          mov FindFileParams.pFilter, xbx               ;pFilter -> curr search path with wildcards
          invoke ??SearchInDir, addr FindFileParams, xbx
          test eax, eax
          jnz @F
          invoke StrSize, xbx
          add xbx, xax
        .endw
        xor eax, eax                                    ;No success
        mov xcx, pRetBuffer
        m2z CHR ptr [xcx]
      .endif
    .endif
  .endif
  xor eax, eax
@@:
  ret
ProcName endp
