; ==================================================================================================
; Title:      RadixSortI32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

% include &ObjMemPath&Common\RadixSort64.inc            ;Helper macros

; --------------------------------------------------------------------------------------------------
; Procedure:  RadixSortI32
; Purpose:    Ascending sort of an array of SDWORDs using a modified "4 passes radix sort" algorithm.
; Arguments:  Arg1: -> Array of SDWORDs.
;             Arg2: Number of SDWORDs contained in the array.
;             Arg3: -> Memory used for the sorting process or NULL. The buffer size must be at least
;                   the size of the input array. If NULL, a memory chunk is allocated automatically.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Notes:      - Original code from r22.
;               http://www.asmcommunity.net/board/index.php?topic=24563.0
;             - For short arrays, the shadow array can be placed onto the stack, saving the
;               expensive memory allocation/deallocation API calls. To achieve this, the proc
;               must be modified and stack probing must be included.
; Links:      - http://www.codercorner.com/RadixSortRevisited.htm
;             - http://en.wikipedia.org/wiki/Radix_sort

.code
align ALIGN_CODE
RadixSortI32 proc uses rbx rdi rsi pArray:POINTER, dCount:DWORD, pWorkArea:POINTER
  ;rcx -> Array, edx = dCount, r8 -> WorkArea
  mov ebx, edx                                          ;dCount
  shl ebx, $Log2(sizeof(SDWORD))                        ;ebx = Array size in BYTEs
  .if ZERO?
    mov eax, TRUE
  .else
    mov rax, r8
    .if rax == NULL
      invoke VirtualAlloc, NULL, ebx, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .endif
    .if rax != NULL
      mov rsi, pArray                                   ;rsi -> Array
      mov rdi, rax                                      ;rdi -> Shadow array
      sub rsp, 256*sizeof(DWORD)                        ;Make room for the counter array

      RadixPass32 0, rdi, rsi                           ;LSB
      RadixPass32 1, rsi, rdi
      RadixPass32 2, rdi, rsi

      ;Modified RadixPass32 3                           :MSB
      ResetRadixCounters
      CountRadixData32 3, rdi
      GetRadixCountToIndexNegFirst
      SortRadixData32 3, rsi, rdi

      add rsp, 256*sizeof(DWORD)                        ;Release counter array
      .if r8 == NULL
        invoke VirtualFree, rdi, 0, MEM_RELEASE         ;Release shadow array, return value = TRUE
      .endif
      mov eax, TRUE
    .endif
  .endif
  ret
RadixSortI32 endp

end
