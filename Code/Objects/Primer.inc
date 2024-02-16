; ==================================================================================================
; Title:      Primer.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Primer objects.
; Notes:      Version C.1.1, October 2022
;               - ErrorSet and ErrorReport return the error value. Bug in ErrorReport corrected.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Primer
; Purpose:    This object is at the top of the inheritance tree and it defines the common properties
;             for all descendant objects in the ObjAsm object library.
; Notes:      The Done destructor MUST always be the first method in the virtual method table (VMT).

Object Primer, PrimerID
  VirtualMethod     Done                                ;Must be first virtual method!
  VirtualMethod     Init,           POINTER             ;-> Owner object.
  VirtualMethod     ErrorClear                          ;Reset dErrorCode
  VirtualMethod     ErrorReport,    POINTER, DWORD      ;-> Calling object, ErrorCode
  VirtualMethod     ErrorSet,       DWORD               ;ErrorCode

  DefineVariable    pOwner,         POINTER,    NULL    ;-> Owner object
  DefineVariable    dErrorCode,     DWORD,      OBJ_OK  ;No error
  DefineVariable    pErrorCaller,   POINTER,    NULL    ;-> Object that calls ErrorReport
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Primer.Done
; Purpose:    Minimal "Done" method.
; Arguments:  None.
; Return:     Nothing.
; Notes:      Since this destructor may be called automatically when the object is disposed, it is
;             not defined as abstract. This way, it is always present in the VMT in the first slot.

Method Primer.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Primer.ErrorClear
; Purpose:    Call recursively ErrorClear until the instance that reported the error was reached.
;             All dErrorCode(s) and pErrorObject(s) members were zeroed/nulled.
; Arguments:  None.
; Return:     Nothing.

Method Primer.ErrorClear, uses xsi
  SetObject xsi
  .if [xsi].pErrorCaller != NULL                        ;Stop recursion if caller = NULL
    .if [xsi].pErrorCaller != xsi                       ;  or if caller = pSelf
      OCall [xsi].pErrorCaller::Primer.ErrorClear
    .endif
    m2z [xsi].pErrorCaller
  .endif
  mov [xsi].dErrorCode, OBJ_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Primer.ErrorReport
; Purpose:    Error handling method. Sets dErrorCode member and propagates the error invoking the
;             ErrorSet method of the owner object. If it can take a corrective action, it must reset
;             the error condition using the ErrorClear method.
; Arguments:  Arg1: -> Instance that invokes the procedure (may be NULL).
;             Arg2: Error code.
; Return:     eax = Error code.
; Note:       The object that first reports an error must set pErrorCaller to pSelf or NULL!

Method Primer.ErrorReport, uses xsi, pErrorCaller:POINTER, dErrorCode:DWORD
  SetObject xsi
  OCall xsi.ErrorSet, dErrorCode                        ;On return, eax = Error code
  m2m [xsi].pErrorCaller, pErrorCaller, xcx
  .if [xsi].pOwner != NULL
    OCall [xsi].pOwner::Primer.ErrorReport, xsi, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Primer.ErrorSet
; Purpose:    Set the error code and takes no further action.
; Arguments:  Arg1: Error code.
; Return:     eax = Error code.
; Note:       If this method is compiled with the DEBUGGING switch enabled it emits error info.

if DEBUGGING

Method Primer.ErrorSet, uses xbx xdi xsi, dErrorCode:DWORD
  local Msg[1024]:CHR

  SetObject xsi
  m2m [xsi].dErrorCode, dErrorCode, eax
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    lea xbx, Msg
    invoke GetObjectID, xsi
    mov edi, eax

    ;Output Object ID
    invoke wsprintfA, xbx, $OfsCStrA("Object ID = %I32ut"), eax
    invoke DbgOutTextA, xbx, DbgColorError, DbgColorBackground, DBG_EFFECT_NORMAL, \
                        offset(szDbgObjErr)
    mov eax, edi

    ;Search the object name using the object ID (xax) and if found, output it
    mov xdi, pObjIDTableStart
    xor ecx, ecx
    .while ecx < dObjIDTableCount
      .if [xdi] == eax
        invoke wsprintfA, xbx, $OfsCStrA(" (%s)"), POINTER ptr [xdi + sizeof(DWORD)]
        invoke DbgOutTextA, xbx, DbgColorComment, DbgColorBackground, DBG_EFFECT_NORMAL, \
                            offset(szDbgObjErr)
        .break
      .endif
      add xdi, sizeof(DWORD) + sizeof(POINTER)          ;Object type ID + PSTRING
      inc ecx
    .endw

    ;Output the error code
    invoke wsprintfA, xbx, $OfsCStrA(", Error Code = %I32ut"), [xsi].dErrorCode
    invoke DbgOutTextA, xbx, DbgColorError, DbgColorBackground, DBG_EFFECT_NORMAL, \
                        offset(szDbgObjErr)

    ;Search the error code description and if found, output it
    mov xdi, pObjErrTableStart
    xor ecx, ecx
    mov eax, [xsi].dErrorCode
    .while ecx < dObjErrTableCount
      .if [xdi] == eax
        invoke wsprintfA, xbx, $OfsCStrA(" (%s)"), POINTER ptr [xdi + sizeof(DWORD)]
        invoke DbgOutTextA, xbx, DbgColorComment, DbgColorBackground, DBG_EFFECT_NORMAL, \
                            offset(szDbgObjErr)
        .break
      .endif
      add xdi, sizeof(DWORD) + sizeof(POINTER)          ;Object error ID + PSTRING
      inc ecx
    .endw

    invoke DbgOutTextA, offset(bCRLF), DbgColorForeground, DbgColorBackground, DBG_EFFECT_NORMAL, \
                        offset(szDbgObjErr)
  endif
  mov eax, dErrorCode
MethodEnd

else

Method Primer.ErrorSet,, dErrorCode:DWORD
  SetObject xcx
  mrm [xcx].dErrorCode, dErrorCode, eax
MethodEnd

endif

; —————————————————————————————————————————————————————————————————————————————————————————————————; Method:     Primer.Init
; Purpose:    Set the owner of the object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method Primer.Init,, pOwner:POINTER
  SetObject xcx
  m2m [xcx].pOwner, pOwner, xax
MethodEnd

endif
