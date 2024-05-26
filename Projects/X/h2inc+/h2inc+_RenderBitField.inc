; ==================================================================================================
; Title:      h2inc+_RenderBitField.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================

;Example 1:
;typedef struct DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
;{
;    union
;    {
;        struct
;        {
;            UINT32  friendlyNameFromEdid : 1;
;            UINT32  friendlyNameForced : 1;
;            UINT32  edidIdsValid : 1;
;            UINT32  reserved : 29;
;        } DUMMYSTRUCTNAME;
;        UINT32  value;
;    } DUMMYUNIONNAME;
;} DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS;

;Example 2:
;typedef struct {
;  unsigned short bAppReturnCode:8,
;                 reserved:6,
;                 fBusy:1,
;                 fAck:1;
;} DDEACK;
;
;Example 3:
;typedef struct {
;#ifndef _MAC
;  unsigned short reserved:14,
;                 fDeferUpd:1,
;		              fAckReq:1;
;#else
;  unsigned short usFlags;
;#endif
;	short     cfFormat;
;} DDEADVISE;
;
;Example 4:
;typedef struct _COMSTAT {
;    DWORD fCtsHold : 1;
;    DWORD fDsrHold : 1;
;    DWORD fRlsdHold : 1;
;    DWORD fXoffHold : 1;
;    DWORD fXoffSent : 1;
;    DWORD fEof : 1;
;    DWORD fTxim : 1;
;    DWORD fReserved : 25;
;    DWORD cbInQue;
;    DWORD cbOutQue;
;} COMSTAT, *LPCOMSTAT;



;Strategy:
;1. Determine the size of the allocation unit (BYTE, WORD, DWORD, QWORD) that is the largest of
;   all field types (signed or unsigned).
;2. Fill the allocation unit with the fields in the reverse order in which they appear, until the
;   total size exceeds the size of the allocation unit.
;3. Fill the rest of the allocation unit with a dummy filler.
;4. Start a new allocation unit and repeat the process from step 2 to the first field.



.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderBitField
; Purpose:    Parse a BitField into a RECORD.
; Arguments:  Arg1: -> Container name
;             Arg2: -> First field type
;             Arg3: -> First field name
;             Arg4: -> Record Suffix
;             xbx -> IncFile
; Return:     xax -> Last token or NULL.
; Note:       On entry, first ':' is consumed.


RenderBitField proc uses xdi xsi, pContainerName:PSTRINGA, pType:PSTRINGA, pToken:PTOKEN, pSuffix:PSTRINGA
  local dAllocUnitSize:DWORD, dCummulatedSize:DWORD, cLineBuffer[1024]:CHRA
  local pFieldStackList:POINTER, dAllocUnitCounter:DWORD, cRecName[1024]:CHRA
  local dIndexUpper:DWORD, dIndexLower:DWORD, bMultipleAllocUnits:BYTE
  local cSeparator:CHRA, InpStat:INP_STAT, dAnonymousFieldCounter:DWORD

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderBitField")
  ;Build the RECORD name ----------------------------------------------------------------
  lea xdi, cRecName
  .if pContainerName != NULL
    WriteFA xdi, "¦SA", pContainerName
  .endif
  WriteFA xdi, "¦SA", pSuffix

  ;Initialization -----------------------------------------------------------------------
  mov dAnonymousFieldCounter, 0
  mov cSeparator, ';'
  mov bMultipleAllocUnits, FALSE
  mov pFieldStackList, $Create@Stacklist()
  mov xax, pType
  invoke GetTypeSize, pType
  shl eax, 3                                            ;Convert to bit size
  .if eax == 0
    OCall xbx::IncFile.ShowWarning, WARNING_MAYOR, $OfsCStr("Unknown type '%hs' in bitfield"), pType
    mov eax, sizeof(DWORD)*8                            ;Default 32 bit
  .endif
  mov dAllocUnitSize, eax                               ;First value

  ;Gatter field informaton into the StackList -------------------------------------------
  .while TRUE
    Add@Stacklist pFieldStackList, pToken               ;First bitfield name
    OCall xbx::IncFile.GetNextTokenC                    ;BitField size
    test xax, xax
    jz @ErrorEoF
    invoke dec2dwordA, xax
    Add@Stacklist pFieldStackList, xax, xcx             ;Save eax (field length)
    OCall xbx::IncFile.GetNextTokenC                    ;';' or ','
    test xax, xax
    jz @ErrorEoF
    mov cl, [xax]
    .if cl == ';'
      mov pToken, xax                                   ;Save token for exit
      .break .if cSeparator == ','
      OCall xbx::IncFile.PeekNextTokenLogicC
      test xax, xax
      jz @ErrorEoF
      .break .if CHRA ptr [xax] == '}'                  ;End of block detected
      OCall xbx::IncFile.InputStatusSave, addr InpStat
      OCall xbx::IncFile.GetNextTokenC
      test xax, xax
      jz @ErrorEoF
      .if $DoesStringMatchA?([xax], <unsigned>)         ;Skip it
        OCall xbx::IncFile.GetNextTokenC
        test xax, xax
        jz @ErrorEoF
      .endif
      invoke TranslateType, xax
      invoke GetTypeSize, xax                           ;Get the Type (CASE UNSENSITIVE !!!!!!!!!!) int not found
      shl eax, 3                                        ;Convert to bit size
      .if eax > dAllocUnitSize
        mov dAllocUnitSize, eax
      .endif
    .elseif cl == ','
      mov cSeparator, cl
    .else
      jmp @ErrorSyntax
    .endif
    OCall xbx::IncFile.GetNextTokenC                    ;New name
    test xax, xax
    jz @ErrorEoF
    .if CHRA ptr [xax] == ':'                           ;Anonymous fieldname
      mov pToken, NULL
    .else
      mov pToken, xax
      OCall xbx::IncFile.GetNextTokenC                  ;Consume ':'
      test xax, xax
      jz @ErrorEoF
      .if CHRA ptr [xax] != ':'
        OCall xbx::IncFile.InputStatusLoad, addr InpStat
        .break
      .endif
    .endif
  .endw

  ;Create the RECORD in memory ----------------------------------------------------------

  lea xdi, cLineBuffer
  WriteFA xdi, "¦SA record ", addr cRecName

  ;Start finding how to fill the allocation unit
  mov esi, $GetCount@Stacklist(pFieldStackList)
  mov dIndexUpper, esi
  mov dAllocUnitCounter, 0

  .repeat
    mov esi, dIndexUpper
    mov dCummulatedSize, 0
    .while esi != 0
      dec esi
      mov xdx, $GetItem@Stacklist(pFieldStackList, esi) ;Get the field length
      add edx, dCummulatedSize
      .if edx > dAllocUnitSize
        inc esi
        .break
      .endif
      mov dCummulatedSize, edx
      dec esi                                           ;Skip the field name
    .endw
    mov dIndexLower, esi
    .if esi != 0
      mov bMultipleAllocUnits, TRUE                     ;If we are not at the end then more
    .endif                                              ;   Allocation Units must exist

    ;Process the filler
    mov esi, dAllocUnitSize
    sub esi, dCummulatedSize
    .if !ZERO?                                          ;Filler needed?
      .if bMultipleAllocUnits
        WriteFA xdi, "¦SA_Filler¦UD:¦UD, ", addr cRecName, dAllocUnitCounter, esi
      .else
        WriteFA xdi, "¦SA_Filler:¦UD, ", addr cRecName, esi
      .endif
    .endif

    mov esi, dIndexUpper
    .while esi != dIndexLower
      WriteFA xdi, "¦SA_", addr cRecName
      dec esi
      dec esi
      mov xdx, $GetItem@Stacklist(pFieldStackList, esi)
      .if xdx == NULL
        WriteFA xdi, "FLD¦UD:", dAnonymousFieldCounter
        inc dAnonymousFieldCounter
      .else  
        WriteFA xdi, "¦SA:", xdx
      .endif
      inc esi
      mov xdx, $GetItem@Stacklist(pFieldStackList, esi)
      dec esi
      WriteFA xdi, "¦UD, ", edx
    .endw

    inc dAllocUnitCounter
    mov eax, dIndexLower
    mov dIndexUpper, eax
  .until eax == 0
  mov DCHRA ptr [xdi - 2*sizeof(CHRA)], 0               ;Delete last comma and SPC

  ;Declare the RECORD -------------------------------------------------------------------
  OCall xbx::IncFile.StmWrite, addr cLineBuffer
  OCall xbx::IncFile.StmWriteComment
  OCall xbx::IncFile.StmWriteEoL

  ;Declare the member
  lea xdi, cLineBuffer
  .if pContainerName == NULL
    WriteFA xdi, "¦SA \[\]", addr cRecName
  .else
    WriteFA xdi, "¦SA_BITS ¦SA \[\]", pContainerName, addr cRecName
  .endif
  OCall xbx::IncFile.StmWrite, addr cLineBuffer
  OCall xbx::IncFile.StmWriteComment
  OCall xbx::IncFile.StmWriteEoL

  ;Exit ---------------------------------------------------------------------------------
  Destroy@Stacklist pFieldStackList
  mov xax, pToken                                       ;xax -> '}'
  test xax, xax
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderBitField")
  OCall xbx::IncFile.StmWriteError
  Destroy@Stacklist pFieldStackList, xcx                ;Preserve xax and ZF
  invoke GotoClosingToken, '{', '}'
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  Destroy@Stacklist pFieldStackList
  xor xax, xax                                          ;xax = NULL and ZF set
  ret
RenderBitField endp
