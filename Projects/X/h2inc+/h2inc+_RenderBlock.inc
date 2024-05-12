; ==================================================================================================
; Title:      h2inc+_RenderBlock.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderBlock
; Purpose:    Get members of a block (structures, unions, enums) in between {...}.
; Arguments:  Arg1 -> Block name.
;             Arg2: Block type: RBT_CONTAINER (struct/union), RBT_EXTERN or RBT_ENUM
;             xbx -> IncFile.
; Return:     xax -> Last Token or NULL if failed.

RenderBlock proc uses xsi pBlockName:PSTRINGA, dBlockType:DWORD
  local wIf:WORD, pPrevToken:PTOKEN

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderBlock")
  movzx eax, [xbx].$Obj(IncFile).bCondIfLevel
  mov ah, [xbx].$Obj(IncFile).bCondElseLevel[xax - 1]
  mov wIf, ax

  mov esi, 1                                            ;Block nesting level = 1
  .repeat
    OCall xbx::IncFile.GetNextTokenC                    ;xax -> First token after '{'
    test xax, xax
    jz @ErrorEoF
    invoke SkipAnnotations, xax
    test xax, xax
    jz @ErrorEoF

    movzx ecx, [xbx].$Obj(IncFile).bCondIfLevel         ;PP #if nesting level
    mov ch, [xbx].$Obj(IncFile).bCondElseLevel[xcx - 1]
    .if (cl == BYTE ptr wIf) && (ch != BYTE ptr wIf + 1)  ;Has changed?
      mov [xbx].$Obj(IncFile).pPrevToken, xax
      mov [xbx].$Obj(IncFile).bUsePrevToken, TRUE
      xor xax, xax                                      ;Set NULL and ZF
      jmp @Exit
    .endif

    .if CHRA ptr [xax] == '}'
      dec esi                                           ;dec block nesting level

    .elseif CHRA ptr [xax] == '{'
      inc esi                                           ;inc block nesting level
      .continue

    .else
      .if dBlockType == RBT_CONTAINER
        invoke RenderContainerMember, xax, pBlockName
      .elseif dBlockType == RBT_ENUM
        invoke RenderEnumMember, xax
      .else
        invoke RenderExternMember, xax
      .endif
      test xax, xax
      jz @ErrorEoF
      .if CHRA ptr [xax] == '}'
        dec esi                                         ;dec block nesting level
      .endif
    .endif
  .until esi == 0                                       ;Exit if block nesting level = 0

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  xor xax, xax                                          ;Return NULL, ZF set
  ret
RenderBlock endp

