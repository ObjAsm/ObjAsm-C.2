; ==================================================================================================
; Title:      D3VectronCollection.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm D3VectronCollection implementation.
; ==================================================================================================



; ==================================================================================================
;    D3VectronCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  VectronCompare
; Purpose:    Compare the Vo vector of two D3Vectron structures.
; Arguments:  Arg1: -> First D3Vectron data structure.
;             Arg2: -> Second D3Vectron data structure.
; Return:     eax = TRUE or FALSE.

VectronCompare proc pVectron1:PD3Vectron, pVectron2:PD3Vectron, xUnused:XWORD
  if TARGET_BITNESS eq 32
    mov ecx, pVectron1
    mov edx, pVectron2
    mov eax, REAL4 ptr [ecx]
    sub eax, REAL4 ptr [edx]
    jnz @F
    mov eax, REAL4 ptr [ecx + 4]
    sub eax, REAL4 ptr [edx + 4]
  else
    mov rax, QWORD ptr [rcx]                              ;Compare first and second REAL4
    cmp rax, QWORD ptr [rdx]                              ; at the same time
  endif
  jnz @F
  mov eax, REAL4 ptr [xcx + 8]
  cmp eax, REAL4 ptr [xdx + 8]
  jnz @F
  inc eax
  ret
@@:
  xor eax, eax
  ret
VectronCompare endp

; --------------------------------------------------------------------------------------------------
; Method:     D3VectronCollection.Append
; Purpose:    Load a D3Vectron data structure from a stream object.
; Arguments:  Arg1: -> D3Vector data structure.
; Return:     eax = Index into the D3VectronCollection.

Method D3VectronCollection.Append, uses xbx xsi, pVector:PD3Vector
  SetObject xsi
  OCall xsi::D3VectronCollection.LastThat, offset VectronCompare, pVector, NULL
  .if xax == NULL
    mov xbx, $MemAlloc(sizeof(D3Vectron))
    invoke MemClone, xbx, pVector, sizeof(D3Vector)     ;pVector, Vo
    mov xcx, xbx
    add xcx, sizeof(D3Vector)
    invoke MemClone, xcx, pVector, sizeof(D3Vector)     ;pVector, Vt
    OCall xsi::D3VectronCollection.Insert, xbx          ;Returns item POINTER
  .endif
  OCall xsi::D3VectronCollection.IndexOf, xax           ;Get item index
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3VectronCollection.GetItem
; Purpose:    Load a D3Vectron data structure from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO
; Return:     xax -> Item.

Method D3VectronCollection.GetItem, uses xbx, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  MemAlloc sizeof(D3Vectron)
  mov xbx, xax
  OCall pStream::Stream.BinRead, xax, sizeof(D3Vectron)
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     D3VectronCollection.PutItem
; Purpose:    Store a D3Vectron data structure in a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Item.
; Return:     Nothing.

Method D3VectronCollection.PutItem,, pStream:$ObjPtr(Stream), pVectron:PD3Vectron
  OCall pStream::Stream.BinWrite, pVectron, sizeof(D3Vectron)
MethodEnd
