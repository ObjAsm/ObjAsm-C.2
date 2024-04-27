; ==================================================================================================
; Title:    h2inc+_MemoryHeap.inc
; Author:   G. Friedrich
; Version:  C.2.0
; Purpose:  ObjAsm support of h2inc+ MemoryHeap objects.
; Notes:    See h2inc+.asm
; ==================================================================================================


MPL_OUT_OF_MEMORY     equ   1
MPL_INVALID_ARGUMENT  equ   2

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   MemoryHeap
; Purpose:  Global memory heap for non-organized storage.

Object MemoryHeap, 0, Primer
  StaticMethod    AddBStrA,     PSTRINGA, DWORD
  StaticMethod    AddDword,     DWORD
  StaticMethod    AddStrA,      PSTRINGA
  StaticMethod    AddStrW,      PSTRINGW
  StaticMethod    Alloc,        DWORD
  RedefineMethod  Done
  RedefineMethod  Init,         POINTER, DWORD, DWORD
  StaticMethod    Reset
  StaticMethod    SetMemMax,    DWORD

  DefineVariable  pMemBlock,    POINTER,  NULL
  DefineVariable  pMemFree,     POINTER,  NULL
  DefineVariable  pMemMax,      POINTER,  NULL
  DefineVariable  dIncrement,   DWORD,    0
  DefineVariable  dMemSize,     DWORD,    0
ObjectEnd

if IMPLEMENT

DbgShowMemoryHeapStatus macro
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd "MemoryHeap"
    lea xbx, DebugMessage
    mov xcx, [xsi].pMemBlock
    mov xax, [xsi].pMemFree
    sub xax, xcx
    WriteF xbx, "¦UD of ", eax
    mov xax, [xsi].pMemMax
    mov xcx, [xsi].pMemBlock
    sub xax, xcx
    WriteF xbx, "¦UD", eax
    invoke DbgOutTextW, addr DebugMessage, DbgColorForeground, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.AddBStrA
; Purpose:   Add a BStrA into the MemoryHeap.
; Arguments: Arg1 -> Original string, must NOT be zero terminated.
;            Arg2: String length, not including the ZTC, if any.
; Return:    xax -> New string in MemoryHeap.

Method MemoryHeap.AddBStrA, uses xdi xsi, pStrA:PSTRINGA, dLength:DWORD
  SetObject xsi
@Retry:
  mov xdi, [xsi].pMemFree
  mov eax, dLength
  inc eax                                               ;Include ZTC
  lea xcx, [xdi + xax + sizeof(DWORD)]
  .if xcx > [xsi].pMemMax
    mov eax, [xsi].dMemSize
    add eax, [xsi].dIncrement
    OCall xsi.SetMemMax, eax
    test xax, xax
    jz @Retry                                           ;ZERO => OK
    xor eax, eax                                        ;Return NULL
    ret
  .endif
  stosd                                                 ;Save string size (incl ZTC)
  invoke MemClone, xdi, pStrA, dLength                  ;Copy string
  mov eax, dLength
  add xax, xdi
  m2z CHRA ptr [xax]                                    ;Set ZTC
  inc xax                                               ;Skip ZTC
  mov [xsi].pMemFree, xax                               ;Set Free-Pointer
  mov xax, xdi                                          ;Return -> allocated string
;  DbgShowMemoryHeapStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.AddDword
; Purpose:   Add a DWORD value into the MemoryHeap.
; Arguments: Arg1: DWORD value.
; Return:    xax -> Value in MemoryHeap buffer.

Method MemoryHeap.AddDword, uses xdi xsi, dValue:DWORD
  SetObject xsi
@Retry:
  mov xdi, [xsi].pMemFree
  lea xcx, [xdi + sizeof(DWORD)]
  .if xcx > [xsi].pMemMax
    mov eax, [xsi].dMemSize
    add eax, [xsi].dIncrement
    OCall xsi.SetMemMax, eax
    test xax, xax
    jz @Retry                       ;ZERO => OK
    xor eax, eax                    ;Return NULL
    ret
  .endif
  mov eax, dValue
  stosd                             ;Save string length
  mov [xsi].pMemFree, xdi           ;Set Free-Pointer
  mov xax, xdi                      ;Return -> allocated DWORD
;  DbgShowMemoryHeapStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.AddStrA
; Purpose:   Add an ANSI string into the MemoryHeap.
; Arguments: Arg1: -> ANSI String.
; Return:    xax -> String in MemoryHeap.

Method MemoryHeap.AddStrA, uses xdi xsi, pStrA:PSTRINGA
  local dSize:DWORD

  SetObject xsi
  invoke StrSizeA, pStrA
  mov dSize, eax
@Retry:
  mov xdi, [xsi].pMemFree
  mov eax, dSize
  lea xcx, [xdi + xax]
  .if xcx > [xsi].pMemMax
    mov eax, [xsi].dMemSize
    add eax, [xsi].dIncrement
    OCall xsi.SetMemMax, eax
    test xax, xax
    jz @Retry                       ;ZERO => OK
    xor eax, eax                    ;Return NULL
    ret
  .endif

  invoke StrECopyA, xdi, pStrA      ;Copy string
  inc xax
  mov [xsi].pMemFree, xax           ;Set Free-Pointer
  mov xax, xdi                      ;Return -> allocated string
;  DbgShowMemoryHeapStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.AddStrW
; Purpose:   Add an WIDE string into the MemoryHeap.
; Arguments: Arg1: -> WIDE String.
; Return:    xax -> String in MemoryHeap.

Method MemoryHeap.AddStrW, uses xdi xsi, pStrW:PSTRINGW
  local dSize:DWORD

  SetObject xsi
  invoke StrSizeW, pStrW
  mov dSize, eax
@Retry:
  mov xdi, [xsi].pMemFree
  mov eax, dSize
  lea xcx, [xdi + xax]
  .if xcx > [xsi].pMemMax
    mov eax, [xsi].dMemSize
    add eax, [xsi].dIncrement
    OCall xsi.SetMemMax, eax
    test xax, xax
    jz @Retry                       ;ZERO => OK
    xor eax, eax                    ;Return NULL
    ret
  .endif

  invoke StrECopyW, xdi, pStrW      ;Copy string
  inc xax
  mov [xsi].pMemFree, xax           ;Set Free-Pointer
  mov xax, xdi                      ;Return -> allocated string
;  DbgShowMemoryHeapStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.Alloc
; Purpose:   Allocate memory block in MemoryHeap
; Arguments: Arg1: memory block size.
; Return:    xax -> Allocated memory block or NULL if failed.

Method MemoryHeap.Alloc, uses xbx xsi, dMemSize:DWORD
  SetObject xsi
  mov xax, [xsi].pMemFree
  mov ebx, dMemSize
  add xbx, xax
  mov xdx, [xsi].pMemMax
  .if xbx > xdx
    mov xax, xdx
    mov ecx, [xsi].dIncrement
    .repeat
      add xax, xcx
    .until xax >= xbx
    OCall xsi.SetMemMax, eax
  .endif
  mov [xsi].pMemFree, xbx           ;Set Free-Pointer
;  DbgShowMemoryHeapStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.Done
; Purpose:   Allocate memory block
; Arguments: None.
; Return:    Nothing.

Method MemoryHeap.Done, uses xsi
  SetObject xsi
  OCall xsi.SetMemMax, 0
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.Init
; Purpose:   Allocate memory block.
; Arguments: Arg1: -> Owner
;            Arg2: Initial block size in bytes.
;            Arg3: Increment size in bytes.
; Return:    eax = Error code.

Method MemoryHeap.Init, uses xsi, pOwner:POINTER, dMemSize:DWORD, dIncrement:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].dIncrement, dIncrement, eax
  OCall xsi.SetMemMax, dMemSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.Reset
; Purpose:   Resets the content of the MemoryHeap.
; Arguments: None.
; Return:    Nothing.

Method MemoryHeap.Reset
  SetObject xcx
  m2m [xcx].pMemFree, [xcx].pMemBlock, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemoryHeap.SetMemMax
; Purpose:   Set the MemoryHeap limit, allocating the necessary memory on the process heap.
; Arguments: Arg1: New memory size.
; Return:    eax = Error code.

Method MemoryHeap.SetMemMax, uses xsi, dNewMemMax:DWORD
  SetObject xsi
  mov eax, dNewMemMax
  .if [xsi].pMemBlock == NULL
    MemAlloc eax
    mov [xsi].pMemBlock, xax
    mov [xsi].pMemFree, xax
    mrm [xsi].dMemSize, dNewMemMax, ecx
    add xcx, xax
    mov [xsi].pMemMax, xcx
    xor eax, eax
  .else
    .if eax == 0
      MemFree [xsi].pMemBlock, MEM_SAFE_FREE
      xor eax, eax                                    ;eax = OBJ_OK
      mov [xsi].pMemBlock, xax                        ;NULL
      mov [xsi].pMemFree, xax                         ;NULL
      mov [xsi].pMemMax, xax                          ;NULL
      mov [xsi].dMemSize, eax
    .else
      mov ecx, [xsi].dMemSize
      .if ecx < eax
        MemReAlloc [xsi].pMemBlock, eax, HEAP_NO_SERIALIZE or HEAP_REALLOC_IN_PLACE_ONLY
        .if xax != NULL
          mov [xsi].pMemBlock, xax
          mov [xsi].pMemFree, xax
          mrm [xsi].dMemSize, dNewMemMax, ecx
          add xcx, xax
          mov [xsi].pMemMax, xcx
          xor eax, eax
        .else
          DbgWarning "MemoryHeap.SetMemMax failed"
          mov eax, MPL_OUT_OF_MEMORY                  ;Return value
        .endif
      .else
        mov eax, MPL_INVALID_ARGUMENT                 ;Return value
      .endif
    .endif
  .endif
MethodEnd

endif
