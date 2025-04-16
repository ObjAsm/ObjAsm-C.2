; ==================================================================================================
; Title:      RadixSortI32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &ObjMemPath&Common\RadixSort32.inc            ;Helper macros

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

OPTION PROC:NONE

.code
align ALIGN_CODE
RadixSortI32 proc pArray:POINTER, dCount:DWORD, pWorkArea:POINTER
  push ebx
  mov ebx, [esp + 12]                                   ;dCount
  shl ebx, 2                                            ;ebx = Array size in BYTEs
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

      RadixPass32 0, edi, esi                           ;LSB
      RadixPass32 1, esi, edi
      RadixPass32 2, edi, esi

      ;Modified RadixPass32 3                           :MSB
      ResetRadixCounters
      CountRadixData32 3, edi
      GetRadixCountToIndexNegFirst
      SortRadixData32 3, esi, edi

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
RadixSortI32 endp

OPTION PROC:DEFAULT

end
