; ==================================================================================================
; Title:      RadixSortPtrF32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

% include &ObjMemPath&Common\RadixSort64.inc            ;Helper macros

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RadixSortPtrF32
; Purpose:    Ascending sort of an array of POINTERs to structures containing a
;             single precision float (REAL4) key using a modified "4 passes radix sort" algorithm.
; Arguments:  Arg1: -> Array of POINTERs.
;             Arg2: Number of POINTERs contained in the array.
;             Arg3: offset of the REAL4 key within the hosting structure.
;             Arg4: -> Memory used for the sorting process or NULL. The buffer size must be at least
;                   the size of the input array. If NULL, a memory chunk is allocated automatically.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Notes:      - For short arrays, the shadow array can be placed onto the stack, saving the
;               expensive memory allocation/deallocation API calls. To achieve this, the proc
;               must be modified and stack probing must be included.
; Links:      - http://www.codercorner.com/RadixSortRevisited.htm
;             - http://en.wikipedia.org/wiki/Radix_sort
;.
;.
;.               array                          structures
;.
;.          ———————————————
;.         | addr Struc 1  | ———————————————————————————————————> —————————————  ——
;.         |———————————————|                                     |      ...    |   | Offset
;.         | addr Struc 2  | ————————————————————> ————————————— |—————————————| <—
;.         |———————————————|                      |      ...    || REAL4 Key 1 |
;.         |    ...        |                      |—————————————||—————————————|
;.         |———————————————|         ...          | REAL4 Key 2 ||      ...    |
;.         |               |                      |—————————————| —————————————
;.         |———————————————|                      |      ...    |
;.         | addr Struc N  | —————> —————————————  —————————————
;.          ———————————————        |      ...    |
;.                                 |—————————————|
;.                                 | REAL4 Key N |
;.                                 |—————————————|
;.                                 |      ...    |
;.                                  —————————————
;.

.code
align ALIGN_CODE
RadixSortPtrF32 proc uses rbx rdi rsi pArray:POINTER, dCount:DWORD, dOffset:DWORD, pWorkArea:POINTER
  ;rcx -> Array, edx = dCount, r8 = dOffset, r9 -> WorkArea
  mov ebx, edx                                          ;dCount
  shl ebx, $Log2(@WordSize)                             ;ebx = Array size in BYTEs
  .if ZERO?
    mov eax, TRUE
  .else
    mov rax, r9
    .if rax == NULL
      invoke VirtualAlloc, NULL, ebx, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .endif
    .if rax != NULL
      mov rsi, pArray                                   ;rsi -> Array
      mov rdi, rax                                      ;rdi -> Shadow array
      sub rsp, 256*sizeof(DWORD)                        ;Make room for the counter array

      RadixPassPtr 0, rdi, rsi                          ;LSB
      RadixPassPtr 1, rsi, rdi
      RadixPassPtr 2, rdi, rsi

      ;Modified RadixPassPtr 3                          :MSB
      ResetRadixCounters
      CountRadixPtr 3, rdi
      GetRadixCountToIndexNegFirst TRUE
      SortRadixPtr 3, rsi, rdi, TRUE                    ;Reverse order of negative floats

      add rsp, 256*sizeof(DWORD)                        ;Release counter array
      .if r9 == NULL
        invoke VirtualFree, rdi, 0, MEM_RELEASE         ;Release shadow array, return value = TRUE
      .endif
      mov eax, TRUE
    .endif
  .endif
  ret
RadixSortPtrF32 endp

end
