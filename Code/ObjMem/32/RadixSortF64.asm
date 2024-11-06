; ==================================================================================================
; Title:      RadixSortF64.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &ObjMemPath&Common\RadixSort32.inc          ;Helper macros

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RadixSortF64
; Purpose:    Ascending sort of an array of double precision floats (REAL8) using a modified
;             "8 passes radix sort" algorithm.
; Arguments:  Arg1: -> Array of double precision floats (REAL8).
;             Arg2: Number of double precision floats contained in the array.
;             Arg3: -> Memory used for the sorting process or NULL. The buffer size must be at least
;                   the size of the input array. If NULL, a memory chunk is allocated automatically.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Notes:      - For short arrays, the shadow array can be placed onto the stack, saving the
;               expensive memory allocation/deallocation API calls. To achieve this, the proc
;               must be modified and stack probing must be included.
; Links:      - http://www.codercorner.com/RadixSortRevisited.htm
;             - http://en.wikipedia.org/wiki/Radix_sort

OPTION PROC:NONE

.code
align ALIGN_CODE
RadixSortF64 proc pArray:POINTER, dCount:dword, pWorkArea:POINTER
  push ebx
  mov ebx, [esp + 12]                                   ;dCount
  shl ebx, 3                                            ;ebx = Array size in BYTEs
  .if ZERO?
    mov eax, TRUE
  .else
    mov eax, [esp + 16]
    .if eax == NULL
      invoke VirtualAlloc, NULL, ebx, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .endif
    .if eax != NULL
      push esi
      push edi
      mov esi, [esp + 16]                               ;esi -> Array
      mov edi, eax                                      ;edi -> Shadow array
      sub esp, 256*4                                    ;Make room for the counter array

      RadixPass64 0, edi, esi                           ;LSB
      RadixPass64 1, esi, edi
      RadixPass64 2, edi, esi
      RadixPass64 3, esi, edi
      RadixPass64 4, edi, esi
      RadixPass64 5, esi, edi
      RadixPass64 6, edi, esi

      ;Modified RadixPass64 7                           :MSB
      ResetRadixCounters
      CountRadixData64 7, edi
      GetRadixCountToIndexNegFirst TRUE
      SortRadixData64 7, esi, edi, TRUE                 ;Reverse order of negative floats

      add esp, 256*4                                    ;Release counter array
     .if POINTER ptr [esp + 24] == NULL
        invoke VirtualFree, edi, 0, MEM_RELEASE         ;Release shadow array, return value = TRUE
      .endif
      mov eax, TRUE
      pop edi
      pop esi
    .endif
  .endif
  pop ebx
  ret 8
RadixSortF64 endp

OPTION PROC:DEFAULT

end
