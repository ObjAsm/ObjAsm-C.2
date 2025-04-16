; ==================================================================================================
; Title:      RadixSortPtrUI32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &ObjMemPath&Common\RadixSort32.inc            ;Helper macros

; --------------------------------------------------------------------------------------------------
; Procedure:  RadixSortPtrUI32
; Purpose:    Ascending sort of a POINTER array to structures containing a DWORD key using the
;             "4 passes radix sort" algorithm.
; Arguments:  Arg1: -> Array of POINTERs.
;             Arg2: Number of POINTERs contained in the array.
;             Arg3: offset of the DWORD key within the hosting structure.
;             Arg4: -> Memory used for the sorting process or NULL. The buffer size must be at least
;                   the size of the input array. If NULL, a memory chunk is allocated automatically.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Notes:      - Original code from r22.
;               http://www.asmcommunity.net/board/index.php?topic=24563.0
;             - For short arrays, the shadow array can be placed onto the stack, saving the
;               expensive memory allocation/deallocation API calls. To achieve this, the proc
;               must be modified and stack probing must be included.
; Links:      - http://www.codercorner.com/RadixSortRevisited.htm
;             - http://en.wikipedia.org/wiki/Radix_sort
;.
;.
;.               array                          structures
;.
;.          ---------------
;.         | addr Struc 1  | -----------------------------------> -------------  --
;.         |---------------|                                     |      ...    |   | Offset
;.         | addr Struc 2  | --------------------> ------------- |-------------| <-
;.         |---------------|                      |      ...    || DWORD Key 1 |
;.         |    ...        |                      |-------------||-------------|
;.         |---------------|       ...            | DWORD Key 2 ||      ...    |
;.         |               |                      |-------------| -------------
;.         |---------------|                      |      ...    |
;.         | addr Struc N  | -----> -------------  -------------
;.          ---------------        |      ...    |
;.                                 |-------------|
;.                                 | DWORD Key N |
;.                                 |-------------|
;.                                 |      ...    |
;.                                  -------------
;.

OPTION PROC:NONE

.code
align ALIGN_CODE
RadixSortPtrUI32 proc pArray:POINTER, dCount:DWORD, dOffset:DWORD, pWorkArea:POINTER
  push ebx
  mov ebx, [esp + 12]                                   ;dCount
  shl ebx, 2                                            ;ebx = Array size in BYTEs
  .if ZERO?
    mov eax, TRUE
  .else
    mov eax, [esp + 20]
    .if eax == NULL
      invoke VirtualAlloc, NULL, ebx, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .endif
    .if eax != NULL
      push esi
      push edi
      push ebp
      mov esi, [esp + 20]                               ;esi -> Array
      mov edi, eax                                      ;edi -> Shadow array
      mov ebp, [esp + 28]                               ;ebp = offset
      sub esp, 256*4                                    ;Make room for the counter array

      RadixPassPtr 0, edi, esi                          ;LSB
      RadixPassPtr 1, esi, edi
      RadixPassPtr 2, edi, esi
      RadixPassPtr 3, esi, edi

      add esp, 256*4                                    ;Release counter array
      .if POINTER ptr [esp + 32] == NULL
        invoke VirtualFree, edi, 0, MEM_RELEASE         ;Release shadow array, return value = TRUE
      .endif
      mov eax, TRUE
      pop ebp
      pop edi
      pop esi
    .endif
  .endif
  pop ebx
  ret 12
RadixSortPtrUI32 endp

OPTION PROC:DEFAULT

end
