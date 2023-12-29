; ==================================================================================================
; Title:      SharedMemoryObject.inc
; Author:     Homer
; Purpose:    ObjAsm support of SharedMemoryObject objects.
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


SMO_OPENED_NEW        equ 1
SMO_OPENED_EXISTING   equ 2

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     SharedMemoryObject
; Purpose:    Implement a fast way to communicate between processes.
; Links:      http://msdn.microsoft.com/en-us/library/aa366551(VS.85).aspx

Object SharedMemoryObject, SharedMemoryObjectID, Primer
  RedefineMethod  Done
  RedefineMethod  Init,       POINTER, POINTER, DWORD, DWORD

  DefineVariable  hMap,       HANDLE,       0
  DefineVariable  pMem,       POINTER,      NULL
ObjectEnd

; ==================================================================================================


if IMPLEMENT


; ==================================================================================================
;    SharedMemoryObject implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SharedMemoryObject.Done
; Purpose:    Finalize the SharedMemoryObject object.
; Arguments:  None.
; Return:     Nothing.

Method SharedMemoryObject.Done, uses xsi
  SetObject xsi
  invoke UnmapViewOfFile, [xsi].pMem                    ;Unmap the Shared Memory object
  invoke CloseHandle, [xsi].hMap                        ;Close the Shared Memory object HANDLE
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SharedMemoryObject.Init
; Purpose:    Initialize the SharedMemoryObject object and create a new SMO or open an
;             existing one.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Name.
;             Arg3: size in bytes.
;             Arg4: access rights (FILE_MAP_WRITE, FILE_MAP_READ, ... , FILE_MAP_ALL_ACCESS).
; Return:     eax = SMO_OPENED_EXISTING, SMO_OPENED_NEW or FALSE.

Method SharedMemoryObject.Init, uses xbx xsi, pOwner:POINTER, pName:POINTER, \
                                              dSize:DWORD, dAccess:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner

  invoke CreateFileMapping, INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, \
                            0, dSize, pName
  .if xax != NULL
    mov xbx, xax
    invoke GetLastError
    .if eax == 0
      mov [xsi].hMap, xbx                               ;Store HANDLE
      invoke MapViewOfFile, xbx, dAccess, 0, 0, 0
      .if xax != NULL
        mov [xsi].pMem, xax                             ;Store POINTER
        mov eax, SMO_OPENED_NEW
      .else
        OCall xsi.ErrorReport, NULL, SMO_MAPPING_ERROR
        xor eax, eax
      .endif
    .elseif eax == ERROR_ALREADY_EXISTS
      mov [xsi].hMap, xbx                               ;Store HANDLE
      invoke MapViewOfFile, xbx, dAccess, 0, 0, 0
      .if xax != NULL
        mov [xsi].pMem, xax                             ;Store POINTER
        mov eax, SMO_OPENED_EXISTING
      .else
        OCall xsi.ErrorReport, NULL, SMO_MAPPING_ERROR
        xor eax, eax
      .endif
    .else
      jmp @Error
    .endif
  .else
@Error:
    OCall xsi.ErrorReport, NULL, SMO_CREATE_ERROR
    xor eax, eax
  .endif
MethodEnd

endif
