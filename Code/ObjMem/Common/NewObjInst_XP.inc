; ==================================================================================================
; Title:      NewObjInst_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness and Platform independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NewObjInst / NewObjInst_UEFI 
; Purpose:    Create an object instance from an object ID.
; Arguments:  Arg1: Object ID.
; Return:     xax -> New object instance or NULL if failed.

.code
align ALIGN_CODE
ProcName proc uses xbx xdi xsi dObjectID:DWORD
  invoke GetObjectTemplate, dObjectID                   ;xax -> Template, ecx = Template size
  .if xax != NULL
    mov xsi, xax
    mov ebx, ecx
    MemAlloc ebx
    .if xax != NULL
      mov xdi, xax
      invoke MemClone, xax, xsi, ebx
      mov xax, xdi                                      ;xax -> new instance
    .endif
  .endif
  ret
ProcName endp

