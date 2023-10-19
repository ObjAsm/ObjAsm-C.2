; ==================================================================================================
; Title:      Array.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of array objects.
; Notes:      Version C.1.0, November 2017
;               - First release.
;             Version C.1.1 August 2021
;               - Indexing bug in 64 bit corrected.
;             Version C.1.2 September 2023
;               - DimResize bug corrected.
; ==================================================================================================


ARR_MEM_NO_ALLOC equ     BIT00     ;Don't allocate memory.
ARR_MEM_ZERO     equ     BIT01     ;Initialize all memory with zeros.
ARR_PRESERVE     equ     BIT02     ;Preserve data.

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   Array
; Purpose:  Implementation of a multidimensional data storage. The stored data should not exceed a
;           a runtime predefined size.
;
; Notes:    - The item storage place is accessed through zero based dimension indices in the range
;             [0..DimesionSize].
;           - Since this object is a descendant of Streamable, it is also capable of storing itself
;             on a stream.
;           - Array and all descendants are thread safe using the ObjAsm multithreading support.

Object Array, ArrayID, Streamable
  VirtualMethod     DimAppend,      DWORD, DWORD
  VirtualMethod     DimResize,      DWORD, DWORD, DWORD
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, DWORD
  VirtualMethod     ItemAt,         ?
  RedefineMethod    Load,           $ObjPtr(Stream)
  VirtualMethod     MemLoad,        POINTER
  VirtualMethod     MemStore,       POINTER
  RedefineMethod    Store,          $ObjPtr(Stream)
  Private
  VirtualMethod     CalcMemReq

  DefineVariable    pData,          POINTER,      NULL
  DefineVariable    dItemSize,      DWORD,        0
  DefineVariable    pDims,          POINTER,      NULL    ;-> Sequence of DWORDs
  DefineVariable    dDimCount,      DWORD,        0
  DefineVariable    ObjLock,        OBJECT_LOCK,  {}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.CalcMemReq
; Purpose:    Compute the memory requirement to store the array data.
; Arguments:  None.
; Return:     Nothing.

Method Array.CalcMemReq, uses xbx xsi
  SetObject xsi
  xor eax, eax
  .if [xsi].dDimCount > 0
    xor edx, edx
    inc eax
    mov xbx, [xsi].pDims
    xor ecx, ecx
    .while ecx < [xsi].dDimCount
      mul DWORD ptr [xbx]
      add xbx, sizeof(DWORD)
      inc ecx
    .endw
    mul [xsi].dItemSize
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.DimAppend
; Purpose:    Append a new dimension to the array object.
; Arguments:  Arg1: Dimension size (max. number of elements that fits in this dimension).
;             Arg2: Initialization flags. (Valid flags: ARR_MEM_NO_ALLOC, ARR_MEM_ZERO, ARR_PRESERVE)
; Return:     eax = Zero based index of the new dimension or -1 if failed.

Method Array.DimAppend, uses xbx xsi, dDimSize:DWORD, dFlags:DWORD
  local pNewMemBlock:POINTER

  SetObject xsi
  mov eax, [xsi].dDimCount
  inc eax
  shl eax, $Log2(sizeof(DWORD))
  mov pNewMemBlock, $MemAlloc(xax)
  mov eax, [xsi].dDimCount
  shl eax, $Log2(sizeof(DWORD))
  mov xbx, xax
  invoke MemClone, pNewMemBlock, [xsi].pDims, eax
  add xbx, pNewMemBlock
  m2m DWORD ptr [xbx], dDimSize, edx
  .if [xsi].pDims != NULL
    MemFree [xsi].pDims
  .endif
  m2m [xsi].pDims, pNewMemBlock, xdx
  inc [xsi].dDimCount

  .ifBitClr dFlags, ARR_MEM_NO_ALLOC
    OCall xsi.CalcMemReq
    .if eax == 0
      m2z pNewMemBlock
    .else
      mov xbx, xax
      .ifBitSet dFlags, ARR_MEM_ZERO
        mov pNewMemBlock, $MemAlloc(xax, MEM_INIT_ZERO)
      .else
        mov pNewMemBlock, $MemAlloc(xax)
      .endif
      mov xax, xbx
      .if pNewMemBlock == NULL
        OCall xsi.ErrorReport, NULL, ARR_OUT_OF_MEMORY
        xor eax, eax
        jmp @@Exit
      .else
        .if [xsi].pData != NULL
          .ifBitSet dFlags, ARR_PRESERVE
            invoke MemClone, pNewMemBlock, [xsi].pData, eax
          .endif
          MemFree [xsi].pData
        .endif
        m2m [xsi].pData, pNewMemBlock, xdx
      .endif
    .endif
  .endif

  mov eax, [xsi].dDimCount
@@Exit:
  dec eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.DimResize
; Purpose:    Resize an existing dimension of an array object.
; Arguments:  Arg1: Dimension index
;             Arg2: New dimension size.
;             Arg3: Initialization flags. (Valid flags: ARR_MEM_ZERO, ARR_PRESERVE)
; Return:     Nothing.

Method Array.DimResize, uses xbx xdi xsi, dIndex:DWORD, dNewWidth:DWORD, dFlags:DWORD
  local dOldWidth:DWORD, pNewMemBlock:POINTER, dNewMemSize:DWORD
  local dStepOld:DWORD, dStepNew:DWORD, dCopyWidth:DWORD, dSubDimStride:DWORD

  SetObject xsi
  mov eax, dIndex
  shl xax, $Log2(sizeof(DWORD))
  add xax, [xsi].pDims
  m2m dOldWidth, DWORD ptr [xax], edx
  m2m DWORD ptr [xax], dNewWidth, edx
  OCall xsi.CalcMemReq
  mov dNewMemSize, eax
  .ifBitSet dFlags, ARR_MEM_ZERO
    mov pNewMemBlock, $MemAlloc(eax, MEM_INIT_ZERO)
  .else
    mov pNewMemBlock, $MemAlloc(eax)
  .endif
  .if pNewMemBlock == NULL
    OCall xsi.ErrorReport, NULL, ARR_OUT_OF_MEMORY
  .else
    .if [xsi].pData != NULL
      .ifBitSet dFlags, ARR_PRESERVE
;-------- Preservation algorythm ----------------------
        xor eax, eax
        xor ecx, ecx
        inc eax
        mov xbx, [xsi].pDims
        xor edx, edx
        .while ecx < dIndex
          mul DWORD ptr [xbx]
          inc ecx
        .endw
        mov dSubDimStride, eax
        mul dNewWidth
        mul [xsi].dItemSize
        mov dStepNew, eax
        mov eax, dSubDimStride
        mul dOldWidth
        mul [xsi].dItemSize
        mov dStepOld, eax
        mov dCopyWidth, $uMin(eax, dStepNew)
        mov xbx, [xsi].pData                            ;Source
        mov xdi, pNewMemBlock                           ;Destination
        mov ecx, dNewMemSize
        add xcx, xdi                                    ;Last byte
        .while xdi < xcx
          invoke MemClone, xdi, xbx, dCopyWidth
          add ebx, dStepOld
          add edi, dStepNew
        .endw
;------------------------------------------------------
      .endif
    .endif
    .if [xsi].pData != NULL
      MemFree [xsi].pData
    .endif
    m2m [xsi].pData, pNewMemBlock, xdx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.Done
; Purpose:    Finalize the array object and frees allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method Array.Done, uses xsi
  SetObject xsi
  .if [xsi].pData != NULL
    MemFree [xsi].pData
  .endif
  .if [xsi].pDims != NULL
    MemFree [xsi].pDims
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.Init
; Purpose:    Initialize the array object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Size of item in bytes.
; Return:     Nothing.

Method Array.Init,, pOwner:POINTER, dItemSize:DWORD
  SetObject xcx
  xor eax, eax
  mov [xcx].pData, xax
  mov [xcx].pDims, xax
  mov [xcx].dDimCount, eax
  m2m [xcx].dItemSize, dItemSize, edx
  ACall xcx.Init, pOwner
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.ItemAt
; Purpose:    Compute the pointer of an array item.
; Arguments:  Arg1..n: Indexes of the array item.
; Return:     xax -> Item or NULL if failed.

Method Array.ItemAt, uses xbx xdi xsi, dIndex:VARARG
  local xOffset:XWORD

  SetObject xsi
  mov edi, 1                                            ;edi: multiplicator, initially = 1
  xor ebx, ebx
  mov xOffset, xbx

  .while ebx < [xsi].dDimCount
    mov xcx, xbx
    lea xdx, dIndex                                     ;Get pointer to Indexes
    shl xcx, $Log2(sizeof(XWORD))                       ;Arguments are XWORD aligned
    add xdx, xcx
    if TARGET_BITNESS eq 64
      shr ecx, 1
    endif
    add xcx, [xsi].pDims
    mov eax, DWORD ptr [xdx]
    .if eax < DWORD ptr [xcx]                           ;Check index range
      xor edx, edx
      mul edi
      add xOffset, xax
      mov eax, edi
      mul DWORD ptr [xcx]
      mov edi, eax
    .else
      OCall xsi::Array.ErrorReport, NULL, ARR_INDEX_OUT_OF_RANGE
      xor eax, eax
      jmp @@EOM
    .endif
    inc ebx
  .endw

  xor edx, edx
  mov xax, xOffset
  mul [xsi].dItemSize
  add xax, [xsi].pData
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.Load
; Purpose:    Load the array object's data from a stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Array.Load, uses xbx xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall pStream::Stream.BinRead, addr [xsi].dItemSize, sizeof(DWORD)
  OCall pStream::Stream.BinRead, addr [xsi].dDimCount, sizeof(DWORD)
  mov eax, [xsi].dDimCount
  shl xax, $Log2(sizeof(DWORD))
  mov xbx, xax
  mov [xsi].pDims, $MemAlloc(xax)
  OCall pStream::Stream.BinRead, [xsi].pDims, ebx

  OCall xsi.CalcMemReq
  mov xbx, xax
  mov [xsi].pData, $MemAlloc(xax)
  OCall pStream::Stream.BinRead, [xsi].pData, ebx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.MemLoad
; Purpose:    Load the array object's data from memory.
; Arguments:  Arg1: -> Memory buffer.
; Return:     Nothing.

Method Array.MemLoad, uses xsi, pBuffer:POINTER
  SetObject xsi
  OCall xsi.CalcMemReq
  invoke MemClone, [xsi].pData, pBuffer, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.MemStore
; Purpose:    Store the array object's data to memory.
; Arguments:  Arg1: -> Memory buffer.
; Return:     Nothing.

Method Array.MemStore, uses xsi, pBuffer:POINTER
  SetObject xsi
  OCall xsi.CalcMemReq
  invoke MemClone, pBuffer, [xsi].pData, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Array.Store
; Purpose:    Store the array object's data to a stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Array.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall pStream::Stream.BinWrite, addr [xsi].dItemSize, sizeof(DWORD)
  OCall pStream::Stream.BinWrite, addr [xsi].dDimCount, sizeof(DWORD)
  mov eax, [xsi].dDimCount
  shl eax, $Log2(sizeof(DWORD))
  OCall pStream::Stream.BinWrite, [xsi].pDims, eax
  OCall xsi.CalcMemReq
  OCall pStream::Stream.BinWrite, [xsi].pData, eax
MethodEnd

endif
