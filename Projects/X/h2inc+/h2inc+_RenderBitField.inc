; ==================================================================================================
; Title:      h2inc+_ParseRecord.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
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


;Strategy:
;1. Determine the size of the allocation unit (BYTE, WORD, DWORD, QWORD) that is the largest of
;   all field types (signed or unsigned).
;2. Fill the allocation unit with the fields in the reverse order in which they appear, until the
;   total size exceeds the size of the allocation unit. 
;3. Fill the rest of the allocation unit with a dummy filler. 
;4. Start a new allocation unit and repeat the process from step 2 to the first field.



.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetBitLength
; Purpose:    Get the bit length of a given type.
; Arguments:  Arg1: -> Type
; Return:     eax = bit length

GetBitLength proc pType:PSTRINGA
  OCall pTypeSize::List.Search, pType
  .if eax != FALSE
  	mov edx, ecx
    OCall pTypeSize::List.ItemAt, edx
    mov edx, [xax - sizeof(DWORD)]
    mov eax, [xax + xdx]
    shl eax, 3                                          ;*8
  .else
    mov eax, sizeof(BYTE)*8                             ;Default 8 bit
  .endif
  ret
GetBitLength endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderBitField
; Purpose:    Parse a BitField into a RECORD.
; Arguments:  Arg1: -> Container name
;             Arg2: -> First field type
;             Arg3: -> First field name
;             Arg4: -> Record Suffix
;             xbx -> IncFile
; Return:     xax -> Last token or NULL, ZF set.
; Note:       On entry, first ':' is consumed.

RenderBitField proc uses xdi xsi, pContainerName:PSTRINGA, pType:PSTRINGA, pToken:PTOKEN, pSuffix:PSTRINGA
  local dAllocUnitSize:DWORD, dCummulatedSize:DWORD, cLineBuffer[1024]:CHRA
  local pFieldStackList:POINTER, dAllocUnitCounter:DWORD, cRecName[1024]:CHRA
  local dIndexUpper:DWORD, dIndexLower:DWORD, bMultipleAllocUnits:BYTE

  ;Build the Record name
  lea xdi, cRecName
  .if pContainerName != NULL
    WriteFA xdi, "¦SA", pContainerName
  .endif
  WriteFA xdi, "¦SA", pSuffix

  ;Initialization
  mov bMultipleAllocUnits, FALSE
  mov pFieldStackList, $Create@Stacklist()
  invoke GetBitLength, pType
  mov dAllocUnitSize, eax                               ;First value

  ;Get all fields into the StackList
  .while TRUE
    Add@Stacklist pFieldStackList, pToken               ;First bitfield name
    OCall xbx::IncFile.GetNextTokenC                    ;BitField size
    jz @ErrorEoF
    cmp CHRA ptr [xax], '}'
    jz @ErrorSyntax
    invoke dec2dwordA, xax
    Add@Stacklist pFieldStackList, xax, xcx             ;Save eax (field length)
    OCall xbx::IncFile.GetNextTokenC                    ;";"
    jz @ErrorEoF
    mov cl, [xax]
    .if cl == ";" 
      OCall xbx::IncFile.GetNextTokenC
      jz @ErrorEoF 
      .if CHRA ptr [xax] == "}"                         ;End of block detected
        mov pToken, xax
        .break
      .endif
      invoke GetBitLength, xax                          ;Get the Type
      .if eax > dAllocUnitSize
        mov dAllocUnitSize, eax
      .endif
    .elseif cl != ","
      jmp @ErrorSyntax
    .endif
    OCall xbx::IncFile.GetNextTokenC                     ;New name
    jz @ErrorEoF
    mov pToken, xax
    OCall xbx::IncFile.GetNextTokenC                     ;Consume ":"
    jz @ErrorEoF
    cmp CHRA ptr [xax], ':'
    jnz @ErrorSyntax
  .endw

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
      WriteFA xdi, "¦SA:", xdx
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

  ;Declare the RECORD
  OCall xbx::IncFile.StmWrite, addr cLineBuffer 
  OCall xbx::IncFile.StmWriteComment
  OCall xbx::IncFile.StmWriteEOL
  DbgStrA cLineBuffer
  
  ;Declare the member
  lea xdi, cLineBuffer
  .if pContainerName == NULL
    WriteFA xdi, "¦SA \[\]", addr cRecName
  .else
    WriteFA xdi, "¦SA ¦SA \[\]", pContainerName, addr cRecName
  .endif
  OCall xbx::IncFile.StmWrite, addr cLineBuffer 
  OCall xbx::IncFile.StmWriteComment
  OCall xbx::IncFile.StmWriteEOL
  DbgStrA cLineBuffer

  Destroy@Stacklist pFieldStackList
  mov xax, pToken                                       ;xax -> '}'
  test xax, xax
  ret

@ErrorSyntax:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  invoke GotoClosingToken, '{', '}'
  jz @ErrorEoF
  Destroy@Stacklist pFieldStackList, xcx                ;Preserve xax and ZF
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  Destroy@Stacklist pFieldStackList
  xor xax, xax                                          ;xax = NULL and ZF set
  ret
RenderBitField endp
