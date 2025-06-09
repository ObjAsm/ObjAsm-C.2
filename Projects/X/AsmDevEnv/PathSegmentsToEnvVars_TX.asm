; ==================================================================================================
; Title:      PathSegmentsToEnvVars_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2025
;               - First release.
; ==================================================================================================


EnvVarInfo struct 4
  pName      PSTRING  ?
  pValue     PSTRING  ?
  dNameLen   DWORD    ?
  dValueLen  DWORD    ?
EnvVarInfo ends

Method EnVarSortedDataCollection.Compare,, xKey1:XWORD, xKey2:XWORD
  mov eax, DWORD ptr xKey2
  sub eax, DWORD ptr xKey1                              ;Long EnvVar Values first
MethodEnd

Method EnVarSortedDataCollection.KeyOf,, pItem:POINTER
  ?mov xdx, pItem
  mov eax, [xdx].EnvVarInfo.dValueLen
MethodEnd                                            

; --------------------------------------------------------------------------------------------------
; Procedure:  PathSegmentsToEnvVars
; Purpose:    Replace path segments matching environment variable values in the source string with
;             their environment variable names.
; Arguments:  Arg1: -> Source string.
; Return:     xax -> New replaced string. Should be disposed using StrDispose when no longer needed.
; Note:       Only EnvVar values containing a '\' are taken. 

.code
align ALIGN_CODE
PathSegmentsToEnvVars proc uses xdi xsi pSrcString:PSTRING
  local EnvVarInfos:$Obj(SortedDataCollection), pEnvVarBlock:PSTRING
  local cInpBuffer[1024]:CHR, cOutBuffer[1024]:CHR, cEnvValue[1024]:CHR
  local pInp:PSTRING, pOut:PSTRING, pSrc:PSTRING, LocalEnvVarInfo:EnvVarInfo
      
  ;Read all the environment variables and sort them by value length, from longest to shortest.  
  New EnvVarInfos::SortedDataCollection
  Override EnvVarInfos::SortedDataCollection.Compare, EnVarSortedDataCollection.Compare 
  Override EnvVarInfos::SortedDataCollection.KeyOf, EnVarSortedDataCollection.KeyOf 
  OCall EnvVarInfos::SortedDataCollection.Init, NULL, 50, 25, COL_MAX_CAPACITY
  mov EnvVarInfos.$Obj(SortedDataCollection).dDuplicates, TRUE
  mov pEnvVarBlock, $invoke(GetEnvironmentStrings)
  
  mov xsi, xax
  .while CHR ptr [xsi] != 0
    invoke StrLScan, xsi, '='
    .break .if xax == NULL
    mov LocalEnvVarInfo.pName, xsi                     ;Store -> Name
    mov xcx, xax
    sub xcx, xsi
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr ecx, 1
  endif
    mov LocalEnvVarInfo.dNameLen, ecx                  ;Store name length
    lea xsi, [xax + sizeof(CHR)]                       ;Skip '='
    mov LocalEnvVarInfo.pValue, xsi                    ;Store -> Value
    invoke StrLength, xsi
    mov LocalEnvVarInfo.dValueLen, eax                 ;Store value length
    lea xsi, [xsi + sizeof(CHR)*xax + sizeof(CHR)]     ;Move to next variable
    invoke StrLScan, LocalEnvVarInfo.pValue, '\'
    .if xax != NULL
      MemAlloc sizeof(EnvVarInfo)
      .break .if xax == NULL
      s2s EnvVarInfo ptr [xax], LocalEnvVarInfo, xcx, xdx
      OCall EnvVarInfos::SortedDataCollection.Insert, xax
    .endif
  .endw    
  
  ;Check using each EnvVar and replace if found
  invoke StrCopy, addr cInpBuffer, pSrcString
  invoke StrUpper, addr cInpBuffer
  lea xax, cOutBuffer
  mov CHR ptr [xax], 0                                  ;Set ZTC
  mov pOut, xax
  lea xcx, cInpBuffer
  mov pInp, xcx
  m2m pSrc, pSrcString, xax
  .ColForEach EnvVarInfos
    mov xdi, xax
    invoke StrCCopy, addr cEnvValue, [xdi].EnvVarInfo.pValue, [xdi].EnvVarInfo.dValueLen
    invoke StrUpper, addr cEnvValue
    
    @@:
    invoke StrPos, pInp, addr cEnvValue
    .if xax != NULL
      .if xax != pInp
        sub xax, pInp
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
        shr eax, 1
  endif
        mov esi, eax
        invoke StrCECopy, pOut, pSrc, eax
      .else
        mov xax, pOut
        xor esi, esi
      .endif
      ;Replace with EncVar Name 
      mov CHR ptr [xax], '%'
      invoke StrCECopy, addr [xax + sizeof(CHR)], [xdi].EnvVarInfo.pName, [xdi].EnvVarInfo.dNameLen
      mov DCHR ptr [xax], '%'
      add xax, sizeof(CHR)
      mov pOut, xax
      add esi, [xdi].EnvVarInfo.dValueLen
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
      shl esi, 1
  endif
      add pSrc, xsi
      add pInp, xsi
      jmp @B                                            ;Try again with the rest of the string
    .endif
  .ColNext
  invoke StrCopy, pOut, pSrc                            ;Copy the rest of the src string

  ;Housekeeping
  invoke FreeEnvironmentStrings, pEnvVarBlock
  OCall EnvVarInfos::SortedDataCollection.Done
  invoke StrNew, addr cOutBuffer
  ret    
PathSegmentsToEnvVars endp
