; ==================================================================================================
; Title:      Debug.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm debug macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, October 2019
;               - Added more color and font customization by HSE.
;             Version C.1.2, October 2020
;               - DbgSaveContext modified to better handle references.
;               - DbgLoadContext simplified.
;               - DbgStr bug corrected.
;               - DbgTextF added.
;               - DbgClosexxx and DbgClearxxx do not open DbgCenter if it is closed.
;             Version C.1.3, August 2022
;               - DbgWrite & DbgWriteF added.
;               - DbgBkgnd, DbgBkgndTxt, DbgBkgndBmp
;               - DbgFlashWnd, DbgFlashMenu, DbgTileHor, DbgTileVer, DbgCascade, DbgArrange
;               - DbgZoomIn, DbgZoomInTxt, DbgZoomInBmp, DbgZoomOut, DbgZoomOutTxt, DbgZoomOutBmp
;               - DbgCloseWnd, DbgPinWnd, DbgFrontWnd, DbgFront, DbgFrontTxt, DbgFrontBmp added.
;               - Color variables introduced. Setup is done by SysInit.
;             Version C.2.0, January 2023
;               - Register restoration bug in DbgSaveContext (64 bit) corrected.
; ==================================================================================================

;Supported debugging macros:
;———————————————————————————
;  - DbgClose, DbgCloseAll, DbgCloseTxt, DbgCloseBmp
;  - DbgClear, DbgClearAll, DbgClearTxt, DbgClearBmp
;  - DbgLine, DbgLine2, DbgText, DbgTextF, DbgWarning
;  - DbgBkgnd, DbgBkgndTxt, DbgBkgndBmp, DbgFrontTxt, DbgFrontBmp, DbgFront
;  - DbgFlashWnd, DbgFlashMenu, DbgTileHor, DbgTileVer, DbgCascade, DbgArrange
;  - DbgZoomIn, DbgZoomInTxt, DbgZoomInBmp, DbgZoomOut, DbgZoomOutTxt, DbgZoomOutBmp
;  - DbgCloseWnd, DbgPinWnd, DbgFrontWnd, DbgFront, DbgFrontTxt, DbgFrontBmp
;  - DbgWrite, DbgWriteF
;  - DbgARGB
;  - DbgStr, DbgStrA, DbgStrW, DbgStrCA, DbgStrCW
;  - DbgBin, DbgDec, DbgHex, DbgFloat, DbgGUID
;  - DbgMem, DbgGlobalMemUsage, DbgFPU
;  - DbgBmp, DbgBmpFromDC
;  - DbgApiError, DbgComError, DbgMessage
;  - DbgObject, DbgTraceObject, DbgTraceShow
;  - ResGuard_Show, ResGuard_Start, ResGuard_Stop
;  - DbgIMT, DbgSMT
;  - DbgAttach, DbgBreak

;DEBUGGING  = TRUE / FALSE   ;Turns debugging output ON or OFF.
;TRACING    = TRUE / FALSE   ;Turns trace output ON or OFF.

; ==================================================================================================

;Debug coloring setup.
;Note: The colors displayed on the target device are determined only by the debuggee.
;      This is done when SysInit is executed.

ifndef DBG_DEVICE
  DBG_DEVICE textequ <WND>
endif

;Device: WND (Light Theme) or LOG
DBG_COLOR_FOREGROUND_WND_LIGHT  equ   $RGB(000,000,000)
DBG_COLOR_BACKGROUND_WND_LIGHT  equ   $RGB(255,255,255)
DBG_COLOR_COMMENT_WND_LIGHT     equ   $RGB(128,128,128)
DBG_COLOR_WARNING_WND_LIGHT     equ   $RGB(192,064,064)
DBG_COLOR_ERROR_WND_LIGHT       equ   $RGB(255,000,000)
DBG_COLOR_STRING_WND_LIGHT      equ   $RGB(000,000,255)
DBG_COLOR_MESSAGE_WND_LIGHT     equ   $RGB(064,064,160)
DBG_COLOR_OBJECT_WND_LIGHT      equ   $RGB(128,128,128)
DBG_COLOR_INTERFACE_WND_LIGHT   equ   $RGB(090,090,255)
DBG_COLOR_VMT_WND_LIGHT         equ   $RGB(063,063,255)
DBG_COLOR_FPU_WND_LIGHT         equ   $RGB(050,150,050)
DBG_COLOR_MEMORY_WND_LIGHT      equ   $RGB(100,100,200)
DBG_COLOR_DEFAULT_PRE_WND_LIGHT equ   $RGB(090,090,090)
DBG_COLOR_DEFAULT_VAR_WND_LIGHT equ   $RGB(130,130,255)
DBG_COLOR_LINE_WND_LIGHT        equ   $RGB(150,150,255)
DBG_COLOR_RED_WND_LIGHT         equ   $RGB(255,000,000)
DBG_COLOR_GREEN_WND_LIGHT       equ   $RGB(000,160,000)
DBG_COLOR_BLUE_WND_LIGHT        equ   $RGB(000,000,255)

;Device: WND (Dark Theme)
DBG_COLOR_FOREGROUND_WND_DARK   equ   $RGB(230,230,230)
DBG_COLOR_BACKGROUND_WND_DARK   equ   $RGB(000,000,000)
DBG_COLOR_COMMENT_WND_DARK      equ   $RGB(156,156,156)
DBG_COLOR_WARNING_WND_DARK      equ   $RGB(192,064,064)
DBG_COLOR_ERROR_WND_DARK        equ   $RGB(255,000,000)
DBG_COLOR_STRING_WND_DARK       equ   $RGB(000,000,255)
DBG_COLOR_MESSAGE_WND_DARK      equ   $RGB(100,100,200)
DBG_COLOR_OBJECT_WND_DARK       equ   $RGB(128,128,128)
DBG_COLOR_INTERFACE_WND_DARK    equ   $RGB(090,090,255)
DBG_COLOR_VMT_WND_DARK          equ   $RGB(063,063,255)
DBG_COLOR_FPU_WND_DARK          equ   $RGB(050,150,050)
DBG_COLOR_MEMORY_WND_DARK       equ   $RGB(100,100,200)
DBG_COLOR_DEFAULT_PRE_WND_DARK  equ   $RGB(165,165,165)
DBG_COLOR_DEFAULT_VAR_WND_DARK  equ   $RGB(130,130,255)
DBG_COLOR_LINE_WND_DARK         equ   $RGB(150,150,255)
DBG_COLOR_RED_WND_DARK          equ   $RGB(255,000,000)
DBG_COLOR_GREEN_WND_DARK        equ   $RGB(000,160,000)
DBG_COLOR_BLUE_WND_DARK         equ   $RGB(000,000,255)

;Device: WND in High Contrast
DBG_COLOR_FOREGROUND_HC         equ   $RGB(255,255,255)
DBG_COLOR_BACKGROUND_HC         equ   $RGB(000,000,000)
DBG_COLOR_COMMENT_HC            equ   $RGB(160,160,160)
DBG_COLOR_WARNING_HC            equ   $RGB(200,128,128)
DBG_COLOR_ERROR_HC              equ   $RGB(255,064,064)
DBG_COLOR_STRING_HC             equ   $RGB(000,255,255)
DBG_COLOR_MESSAGE_HC            equ   $RGB(160,160,255)
DBG_COLOR_OBJECT_HC             equ   $RGB(160,160,160)
DBG_COLOR_INTERFACE_HC          equ   $RGB(090,090,255)
DBG_COLOR_VMT_HC                equ   $RGB(063,063,255)
DBG_COLOR_FPU_HC                equ   $RGB(096,152,096)
DBG_COLOR_MEMORY_HC             equ   $RGB(128,128,200)
DBG_COLOR_DEFAULT_PRE_HC        equ   $RGB(160,160,160)
DBG_COLOR_DEFAULT_VAR_HC        equ   $RGB(160,160,255)
DBG_COLOR_LINE_HC               equ   $RGB(064,255,064)
DBG_COLOR_RED_HC                equ   $RGB(255,000,000)
DBG_COLOR_GREEN_HC              equ   $RGB(000,160,000)
DBG_COLOR_BLUE_HC               equ   $RGB(000,000,255)

;Device: CON
DBG_COLOR_FOREGROUND_CON        equ   $RGB(255,255,255)
DBG_COLOR_BACKGROUND_CON        equ   $RGB(000,000,000)
DBG_COLOR_COMMENT_CON           equ   $RGB(255,255,127)
DBG_COLOR_WARNING_CON           equ   $RGB(127,255,000)
DBG_COLOR_ERROR_CON             equ   $RGB(255,000,000)
DBG_COLOR_STRING_CON            equ   $RGB(000,000,255)
DBG_COLOR_MESSAGE_CON           equ   $RGB(127,255,255)
DBG_COLOR_OBJECT_CON            equ   $RGB(127,255,255)
DBG_COLOR_INTERFACE_CON         equ   $RGB(000,000,255)
DBG_COLOR_VMT_CON               equ   $RGB(000,000,255)
DBG_COLOR_FPU_CON               equ   $RGB(000,255,000)
DBG_COLOR_MEMORY_CON            equ   $RGB(000,127,255)
DBG_COLOR_DEFAULT_PRE_CON       equ   $RGB(255,255,127)
DBG_COLOR_DEFAULT_VAR_CON       equ   $RGB(255,255,255)
DBG_COLOR_LINE_CON              equ   $RGB(127,127,127)
DBG_COLOR_RED_CON               equ   $RGB(255,000,000)
DBG_COLOR_GREEN_CON             equ   $RGB(000,255,000)
DBG_COLOR_BLUE_CON              equ   $RGB(000,000,255)

;Debug font
DBG_FONT_TEXT             textequ <Courier New>
;DBG_FONT_TEXT             textequ <Fixedsys>

;Debug device
DBG_DEV_NUL               equ   00h
DBG_DEV_WIN_LOG           equ   01h
DBG_DEV_WIN_CON           equ   02h
DBG_DEV_WIN_DC            equ   03h       ;DebugCenter Windows application
DBG_DEV_UEFI_CON          equ   04h
;DBG_DEV_UEFI_LOG          equ   05h
;DBG_DEV_UEFI_HTTP         equ   06h       ;Remote connection via HTTP, not implemented

;Debug options
DBG_OPT_NONE              equ   00h
DBG_OPT_SHOWINFO          equ   01h

;Debug memory formats
DBG_MEM_NONE              equ   100       ;No representation output
DBG_MEM_STRA              equ   101       ;ANSI String
DBG_MEM_STRW              equ   102       ;WIDE String
DBG_MEM_UI8               equ   103       ;Unsigned BYTE Integer in decimal format
DBG_MEM_UI16              equ   104       ;Unsigned WORD Integer in decimal format
DBG_MEM_UI32              equ   105       ;Unsigned DWORD Integer in decimal format
DBG_MEM_UI64              equ   106       ;Unsigned QWORD Integer in decimal format
DBG_MEM_I8                equ   107       ;Signed BYTE Integer in decimal format
DBG_MEM_I16               equ   108       ;Signed WORD Integer in decimal format
DBG_MEM_I32               equ   109       ;Signed DWORD Integer in decimal format
DBG_MEM_I64               equ   110       ;Signed QWORD Integer in decimal format
DBG_MEM_R4                equ   111       ;REAL4 in decimal format
DBG_MEM_R8                equ   112       ;REAL8 in decimal format
DBG_MEM_H8                equ   113       ;BYTE Integer in hexadecimal format
DBG_MEM_H16               equ   114       ;WORD Integer in hexadecimal format
DBG_MEM_H32               equ   115       ;DWORD Integer in hexadecimal format
DBG_MEM_H64               equ   116       ;QWORD Integer in hexadecimal format

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DBG_MEM_STR equ DBG_MEM_STRA
else
  DBG_MEM_STR equ DBG_MEM_STRW
endif


DBG_FLOAT_RESOLUTION      equ   12
DBG_FLOAT_BUFFERSIZE      equ   32        ;(DBG_FLOAT_RESOLUTION + 9) to keep the stack
                                          ;aligned, roundup to the next 16 boundary
if DEBUGGING
  CStrW szDbgErr,         "Debug Error"
  CStrW szDbgObjErr,      "Object Error"
  CStrW szDbgComErr,      "DebugCenter communication failed due to low system resources"
  CStrW szLeakReport,     "Resource Leakage Report"

  externdef dDbgDev:DWORD                 ;Exports dDbgDev symbol, defined in SysSetup

  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    CStrA szDbgInvalid,     "????"
    CStrW szDbgCtrCls,      &DEBUG_CENTER_CLASS

    externdef hDbgDev:HANDLE
    .data?
    hDbgDev             HANDLE    ?
  endif

  .data?
    pObjIDTableStart    POINTER   ?
    dObjIDTableCount    DWORD     ?
    pObjErrTableStart   POINTER   ?
    dObjErrTableCount   DWORD     ?

    ;Initial value set by SysInit
    DbgColorForeground  DWORD     ?
    DbgColorBackground  DWORD     ?
    DbgColorComment     DWORD     ?
    DbgColorWarning     DWORD     ?
    DbgColorError       DWORD     ?
    DbgColorString      DWORD     ?
    DbgColorMessage     DWORD     ?
    DbgColorObject      DWORD     ?
    DbgColorInterface   DWORD     ?
    DbgColorVMT         DWORD     ?
    DbgColorFPU         DWORD     ?
    DbgColorMemory      DWORD     ?
    DbgColorDefaultPre  DWORD     ?
    DbgColorDefaultVar  DWORD     ?
    DbgColorLine        DWORD     ?
    DbgColorRed         DWORD     ?
    DbgColorGreen       DWORD     ?
    DbgColorBlue        DWORD     ?

    ifidn DBG_DEVICE, <WND>
      DbgHighContrast   HIGHCONTRAST  {}                ;Used by SysInit to get the High Contrast
    endif                                               ; activation status

  externdef DbgColorForeground :DWORD
  externdef DbgColorBackground :DWORD
  externdef DbgColorComment    :DWORD
  externdef DbgColorWarning    :DWORD
  externdef DbgColorError      :DWORD
  externdef DbgColorString     :DWORD
  externdef DbgColorMessage    :DWORD
  externdef DbgColorObject     :DWORD
  externdef DbgColorInterface  :DWORD
  externdef DbgColorVMT        :DWORD
  externdef DbgColorFPU        :DWORD
  externdef DbgColorMemory     :DWORD
  externdef DbgColorDefaultPre :DWORD
  externdef DbgColorDefaultVar :DWORD
  externdef DbgColorLine       :DWORD
  externdef DbgColorRed        :DWORD
  externdef DbgColorGreen      :DWORD
  externdef DbgColorBlue       :DWORD
endif


; ==================================================================================================
;    Helper macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgSaveContext
; Purpose:    Save CPU & FPU registers & flags onto stack and aligns it. This way, all subsequent
;             invocations have an aligned stack and a cleared direction flag. Additionally, a
;             Critacal Section is passed to avoid racing conditions.
; Arguments:  Arg1: Handle the passed argument as a Value (FALSE) or a reference (TRUE).
;             Arg2: Var to be saved in rbx/ebx/bx/bl or the address of Var in xbx.
; Return:     Nothing.
; Note:       On entry, the stack doesn't need to be aligned!

DbgSaveContext macro VarIsRef:=<FALSE>, Var
  pushcontext assumes
  pushfx                                                ;;Save CPU flags
  pushax
  ifnb <Var>
    ??Attributes = opattr(Var)
    if VarIsRef ne FALSE
      if ??Attributes and OAT_REGISTER                  ;;Is Var a register?
        %ifdifi <Var>, <xbx>                            ;;Skip if Var is xbx
          if type(Var) eq @WordSize                     ;;  Use xbx, because it is the only non
            mov xbx, Var                                ;;  volatile register that can be loaded
          else
            .err <DbgSaveContext - Reference error>
            exitm
          endif
        endif
      else
        lea xbx, Var
      endif
      ??VarXBX textequ <xbx>
    else
      if @InStr(1, RBX_SUBREGS, <$Upper(Var)>) eq 0
        if type(Var) eq 8
          mov rbx, Var
          ??VarXBX textequ <rbx>
        elseif type(Var) eq 4
          mov ebx, Var
          ??VarXBX textequ <ebx>
        elseif type(Var) eq 2
          mov bx, Var
          ??VarXBX textequ <bx>
        elseif type(Var) eq 1
          mov bl, Var
          ??VarXBX textequ <bl>
        else
          if (opattr Var) and OAT_IMMEDIATE
            mov xbx, Var
            ??VarXBX textequ <xbx>
          else
            .err <DbgSaveContext - Value error>
            exitm
          endif
        endif
      else
        ??VarXBX textequ Var
      endif
    endif
  endif

  cld                                                   ;;Reset direction flag for API calling!
  mov xdi, xsp                                          ;;Save current esp value in edi
  if TARGET_BITNESS eq 32
    and esp, 0FFFFFFF0h                                 ;;Align stack on a 16 byte boundary
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      invoke EnterCriticalSection, offset(DbgCritSect)  ;;This call don't change GetLastError
    endif
    sub esp, XMM_CONTEXT_SIZE
    fxsave [esp]                                        ;;This instruction reinitializes the XMM
    push esp                                            ;;Save FPU storage pointer
    push edi                                            ;;Save address to restore CPU registers
    ifb <Var>                                           ;;If not Var is supplied, restore regs
      mov eax, [edi +  7*sizeof(DWORD)]                 ;;Restore volatile registers that
      mov ecx, [edi +  6*sizeof(DWORD)]                 ;;  EnterCriticalSection may have changed
      mov edx, [edi +  5*sizeof(DWORD)]
      mov edi, [edi]                                    ;;Restore edi from pushed register values
    endif
  else
    and rsp, 0FFFFFFFFFFFFFFF0h                         ;;Align stack on a 16 byte boundary
    sub rsp, 20h
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      invoke EnterCriticalSection, offset(DbgCritSect)  ;;This call don't change GetLastError
    endif
    sub rsp, XMM_CONTEXT_SIZE - 20h
    fxsave [rsp]                                        ;;This instruction reinitializes the XMM
    push rsp                                            ;;Save FPU storage pointer
    push rdi                                            ;;Save address to restore CPU registers
    ifb <Var>                                           ;;If Var is not supplied, restore vol. regs
      mov rax, [rdi + 15*sizeof(QWORD)]                 ;;Restore volatile registers that
      mov rcx, [rdi + 14*sizeof(QWORD)]                 ;;  EnterCriticalSection may have changed
      mov rdx, [rdi + 13*sizeof(QWORD)]
      mov r8,  [rdi +  7*sizeof(QWORD)]
      mov r9,  [rdi +  6*sizeof(QWORD)]
      mov r10, [rdi +  5*sizeof(QWORD)]
      mov r11, [rdi +  4*sizeof(QWORD)]
      mov rdi, [rdi +  8*sizeof(QWORD)]                 ;;Restore rdi from pushed register values
    endif

    sub rsp, 40h                                        ;;Add a homing area and argument space
  endif                                                 ;; for the comming calls
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgLoadContext
; Purpose:    Load CPU & FPU registers & flags from stack and restores the original stack alignment.
; Arguments:  None.
; Return:     Nothing.

DbgLoadContext macro
  if TARGET_BITNESS eq 32
    pop ebp
    pop ebx
    fxrstor [ebx]                                       ;;Read XMM content back
  else
    add rsp, 40h                                        ;;Remove homing area and argument space
    pop rbp
    pop rbx
    fxrstor [rbx]                                       ;;Read XMM content back
    sub rsp, 20h
  endif
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    invoke LeaveCriticalSection, offset(DbgCritSect)
  endif
  mov xsp, xbp                                          ;;Restore rsp
  popax                                                 ;;Restore CPU registers
  popfx                                                 ;;Direction flag is restored here too
  popcontext assumes
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgSetDestWnd
; Purpose:    Set the global symbol ??DbgDstWnd.
; Arguments:  Arg1: Name of the child window of the Debug Center MDI target to which the information
;                   is directed.
; Return:     Nothing.

DbgSetDestWnd macro DestWnd
  local ??DestWnd                                       ;;Must be local

  ifb <DestWnd>
    ??DbgDstWnd textequ <offset(szDbgSrc)>
  else
    ifidni @SubStr(DestWnd, 1, 1), <">
      CStrW ??DestWnd, DestWnd                          ;;Create only 1 instance of the window name.
      ??DbgDstWnd textequ <offset(??DestWnd)>
    else
      ??DbgDstWnd textequ <DestWnd>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgShowSrcInfo
; Purpose:    Output source line info on the debug device.
; Arguments:  Arg1: Optional destination Window name.
; Return:     Nothing.

DbgShowSrcInfo macro Dest:req
  ??DbgIndex = 0
  ??DbgPos = 0
  %forc ??DbgChar, @FileCur                             ;;Search last "\" and return string position
    ??DbgIndex = ??DbgIndex + 1
    ifidni <&??DbgChar>, <\>
      ??DbgPos = ??DbgIndex
    endif
  endm

  .ifBitSet dDbgOpt, DBG_OPT_SHOWINFO
    invoke DbgOutTextA, \
              $OfsCStrA(@CatStr(<!" [>, @SubStr(%@FileCur, ??DbgPos + 1), <, >, %@Line, <]!">)), \
              DbgColorComment, DbgColorBackground, DBG_EFFECT_NEWLINE, Dest
  .else
    invoke DbgOutTextA, offset(bNULL), DbgColorForeground, DbgColorBackground, DBG_EFFECT_NEWLINE, \
                        Dest
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgShowTxtInfo
; Purpose:    Output additional text info on the debug device.
; Arguments:  Arg1: Text.
;             Arg2: Optional destination Window name.
; Return:     Nothing.

DbgShowTxtInfo macro Text, Dest
  ifnb <&Text>
    invoke DbgOutTextA, $OfsCStrA(<", ", &Text>), DbgColorForeground, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, Dest
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgOutHex
; Purpose:    Output a number in hexadecimal on the debug output device.
; Arguments:  Arg1: Text displayed befor the value.
;             Arg2: Output color of PreText (defaut is black).
;             Arg3: Symbol. Value or address must be stored in rbx/ebx/bx/bl.
;             Arg4: Output color (default = black).
;             Arg5: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgHexHex DWORD ptr [rcx]
;             THIS MACRO TRASHES XDI & XSI!

OutHexAux macro
  if ??DbgDataSize ge 2*sizeof(QWORD)
    invoke qword2hexA, xdi, QWORD ptr [xbx + 8]
    add xdi, QWORD2HEX_MAX_CHARS - 1
    invoke qword2hexA, xdi, QWORD ptr [xbx]
    H_Offset = QWORD2HEX_MAX_CHARS - 1
    if ??DbgDataSize ne 16
      add xdi, H_Offset
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  elseif ??DbgDataSize ge sizeof(QWORD)
    invoke qword2hexA, xdi, QWORD ptr [xbx]
    H_Offset = QWORD2HEX_MAX_CHARS - 1
    if ??DbgDataSize ne 8
      add xdi, H_Offset
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  elseif ??DbgDataSize ge sizeof(DWORD)
    invoke dword2hexA, xdi, DWORD ptr [xbx]
    H_Offset = DWORD2HEX_MAX_CHARS - 1
    if ??DbgDataSize ne 4
      add xdi, H_Offset
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  elseif ??DbgDataSize ge sizeof(WORD)
    invoke word2hexA, xdi, WORD ptr [xbx]
    H_Offset = WORD2HEX_MAX_CHARS - 1
    if ??DbgDataSize ne 2
      add xdi, H_Offset
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  else
    invoke byte2hexA, xdi, BYTE ptr [xbx]
    H_Offset = BYTE2HEX_MAX_CHARS - 1
  endif
  mov DCHRA ptr [xdi + H_Offset], "h"                   ;Include ZTC
endm

DbgOutHex macro PreText:=<>, PreColor:=<DbgColorDefaultPre>, Var:req, \
                VarColor:=<DbgColorDefaultVar>, Dest:req
  ??DbgDataSize = type(Var)
  if TARGET_BITNESS eq 32
    ;;Reserve stack = 4*8 chars + "h" + ZTC = 22h => 28h
    sub esp, 28h
    ifnb <PreText>
      invoke DbgOutTextA, $OfsCStrA($Esc("&PreText&")), PreColor, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
    endif
    if (opattr Var) and OAT_REGISTER                    ;;Is Var a register?
      mov esi, esp                                      ;;+ 2 padding bytes = 0Ch
      invoke dword2hexA, esi, ebx
      mov DCHRA ptr [esi + DWORD2HEX_MAX_CHARS - 1], "h";;Set "h" + ZTC
      if ??DbgDataSize lt sizeof(DWORD)
        add esi, 2*(sizeof(DWORD) - ??DbgDataSize)      ;;Skip unnecessary zeros
      endif
    else
      if TARGET_PLATFORM eq PLATFORM_WINDOWS
        invoke IsBadReadPtr, ebx, DWORD ptr ??DbgDataSize
        .if eax != 0
          mov esi, offset(szDbgInvalid)
        .else
          mov edi, esp
          mov esi, edi
          OutHexAux
        .endif
      else
        mov edi, esp
        mov esi, edi
        OutHexAux
      endif
    endif
    invoke DbgOutTextA, esi, VarColor, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
    add esp, 28h                                        ;;Restore stack
  else
    ;;Reserve stack = 2*16 chars + "h" + ZTC + 14 padding bytes + homing space = 60h
    sub rsp, 60h
    ifnb <PreText>
      invoke DbgOutTextA, $OfsCStrA($Esc("&PreText&")), PreColor, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
    endif
    if (opattr Var) and OAT_REGISTER                    ;;Is Var a register?
      lea rsi, [rsp + 28h]
      invoke qword2hexA, rsi, rbx
      mov DCHRA ptr [rsi + QWORD2HEX_MAX_CHARS - 1], "h";;Set "h" + ZTC
      if ??DbgDataSize lt sizeof(QWORD)
        add rsi, 2*(sizeof(QWORD) - ??DbgDataSize)      ;;Skip unnecessary zeros
      endif
    else
      if TARGET_PLATFORM eq PLATFORM_WINDOWS
        invoke IsBadReadPtr, rbx, DWORD ptr ??DbgDataSize
        .if rax != 0
          mov rsi, offset(szDbgInvalid)
        .else
          lea rdi, [rsp + 28h]
          mov rsi, rdi
          OutHexAux
        .endif
      else
        lea rdi, [rsp + 28h]
        mov rsi, rdi
        OutHexAux
      endif
    endif
    invoke DbgOutTextA, rsi, VarColor, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
    add rsp, 60h                                        ;;Restore stack
  endif
endm

; ==================================================================================================
;   String debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgLine
; Purpose:    Draw a single line on the debug device.
; Arguments:  Arg1: Optional destination Window name.

DbgLine macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifidn DBG_DEVICE, <WND>
      invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, DbgColorLine, DbgColorBackground, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA("-------------------------------------------------------"), \
                          DbgColorLine, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgLine2
; Purpose:    Draw a double line on the debug device.
; Arguments:  Arg1: Optional destination Window name.

DbgLine2 macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifidn DBG_DEVICE, <WND>
      invoke DbgOutCmd, DBG_CMD_DOUBLE_LINE, DbgColorLine, DbgColorBackground, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA("======================================================="), \
                          DbgColorLine, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgText
; Purpose:    Output a text on the debug device.
; Arguments:  Arg1: Text.
;             Arg2: Optional destination Window name.

DbgText macro Var, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifb <&Var>
      invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">,<%@FileCur>,<!">)), \
                          DbgColorForeground, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA($Esc(<&Var>)), \
                          DbgColorForeground, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    endif
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgTextF
; Purpose:    Output formated a text on the debug device.
; Arguments:  Arg1: Optinal text color.
;             Arg2: Optional destination Window name.
;             Arg3: Quoted format string.
;             Arg 4..n: optional arguments.
; Example:    DbgTextF "Output", $RGB(000,000,000), "Data = '%s'", xax

DbgTextF macro Color:=<DbgColorForeground>, Dest, Message:req, Args:vararg
  local DebugTextBuffer

  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      DbgSetDestWnd Dest
      ifnb <Args>
        bss segment
          DebugTextBuffer CHRA 1024 dup(?)
        bss ends

        invoke wsprintf, offset DebugTextBuffer, $OfsCStrA($Esc(Message)), Args
        invoke DbgOutText, offset DebugTextBuffer, Color, DbgColorBackground, \
                           DBG_EFFECT_NEWLINE, ??DbgDstWnd
      else
        invoke DbgOutText, $OfsCStrA($Esc(Message)), Color, DbgColorBackground, \
                           DBG_EFFECT_NEWLINE, ??DbgDstWnd
      endif
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgWarning
; Purpose:    Output a text on the debug device on red color.
; Arguments:  Arg1: Text.
;             Arg2: Optional destination Window name.

DbgWarning macro DispText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifb <&Var>
      invoke DbgOutTextA, $OfsCStrA($Esc("WARNING\:")), \
                          DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA($Esc(<DispText>)), \
                          DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    endif
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ==================================================================================================
;   Window Management macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBkgndTxt
; Purpose:    Set the text window background color.
; Arguments:  Arg1: New background color.
;             Arg2: Optional destination Window name.

DbgBkgndTxt macro NewBackColor:=<DbgColorBackground>, Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_SET_BKGND_TXT, NewBackColor, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBkgndBmp
; Purpose:    Set the bitmap window background color.
; Arguments:  Arg1: New background color.
;             Arg2: Optional destination Window name.

DbgBkgndBmp macro NewBackColor:=<DbgColorBackground>, Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_SET_BKGND_BMP, NewBackColor, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBkgnd
; Purpose:    Set the window background color.
; Arguments:  Arg1: New background color.
;             Arg2: Optional destination Window name.

DbgBkgnd macro NewBackColor:=<DbgColorBackground>, Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_SET_BKGND_TXT, NewBackColor, 0, ??DbgDstWnd
      invoke DbgOutCmd, DBG_CMD_SET_BKGND_BMP, NewBackColor, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFlashWnd
; Purpose:    Flash the DebugCenter menu bar.
; Arguments:  Arg1: Flashing flags, e.g. FLASHW_CAPTION
;             Arg2: Number of flashes.

DbgFlashWnd macro Flags, Reps
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_FLASH_WINDOW, Flags, Reps, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFlashMenu
; Purpose:    Flash the DebugCenter menu bar.
; Arguments:  Arg1: Menu flash RGB color.
;             Arg2: Number of flashes.

DbgFlashMenu macro MenuColor, Reps, Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_FLASH_MENU, MenuColor, Reps, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgTileHor
; Purpose:    Tile the output windows horizontally.
; Arguments:  None.

DbgTileHor macro
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_CHILDREN_TILE_HOR, 0, 0, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgTileVer
; Purpose:    Tile the output windows vertically.
; Arguments:  None.

DbgTileVer macro
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_CHILDREN_TILE_VER, 0, 0, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCascade
; Purpose:    Arrange output windows in a cascade.
; Arguments:  None.

DbgCascade macro
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_CHILDREN_CASCADE, 0, 0, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgArrange
; Purpose:    Arrange iconized output windows.
; Arguments:  None.

DbgArrange macro
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_ICONS_ARRANGE, 0, 0, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgZoomInTxt
; Purpose:    Zoom In a specified text output window.
; Arguments:  Arg1: Destination Window name.

DbgZoomInTxt macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_ZOOM_IN_TXT, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgZoomInBmp
; Purpose:    Zoom In a specified bitmap output window.
; Arguments:  Arg1: Destination Window name.

DbgZoomInBmp macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_ZOOM_IN_BMP, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgZoomIn
; Purpose:    Zoom In specified output windows.
; Arguments:  Arg1: Destination Window name.

DbgZoomIn macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_ZOOM_IN_TXT, 0, 0, ??DbgDstWnd
      invoke DbgOutCmd, DBG_CMD_ZOOM_IN_BMP, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgZoomOutTxt
; Purpose:    Zoom Out a specified text output window.
; Arguments:  Arg1: Destination Window name.

DbgZoomOutTxt macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_ZOOM_OUT_TXT, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgZoomOutBmp
; Purpose:    Zoom Out a specified bitmap output window.
; Arguments:  Arg1: Destination Window name.

DbgZoomOutBmp macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_ZOOM_OUT_BMP, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgZoomOut
; Purpose:    Zoom Out specified output windows.
; Arguments:  Arg1: Destination Window name.

DbgZoomOut macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_ZOOM_OUT_TXT, 0, 0, ??DbgDstWnd
      invoke DbgOutCmd, DBG_CMD_ZOOM_OUT_BMP, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFrontTxt
; Purpose:    Bring a specified text output window to front.
; Arguments:  Arg1: Destination Window name.

DbgFrontTxt macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_FRONT_TXT, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFrontBmp
; Purpose:    Bring a specified output bitmap window to front.
; Arguments:  Arg1: Destination Window name.

DbgFrontBmp macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_FRONT_BMP, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFront
; Purpose:    Bring specified output windows to front.
; Arguments:  Arg1: Destination Window name.

DbgFront macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_FRONT_BMP, 0, 0, ??DbgDstWnd
      invoke DbgOutCmd, DBG_CMD_FRONT_TXT, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseWnd
; Purpose:    Close Debug Center.
; Arguments:  None.

DbgCloseWnd macro Arg:=<TRUE>
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_CLOSE_WND, 0, 0, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgPinWnd
; Purpose:    Set TOPMOST flag.
; Arguments:  Arg1: TRUE or FALSE.

DbgPinWnd macro Arg:=<TRUE>
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      invoke DbgOutCmd, DBG_CMD_PIN_WND, Arg, 0, NULL
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFrontWnd
; Purpose:    Bring specified output windows to front.
; Arguments:  Arg1: Destination Window name.

DbgFrontWnd macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_FRONT_WND, 0, 0, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DbgWrite textequ <DbgWriteA>
else
  DbgWrite textequ <DbgWriteW>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgWriteA
; Purpose:    Output a string on the debug device.
; Arguments:  Arg1: -> ANSI String.
;             Arg2: Optional destination Window name.

DbgWriteA macro Var, Color:=<DbgColorForeground>, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
    else
      DbgSaveContext TRUE, Var                          ;;Pass Var as a reference
    endif
    DbgSetDestWnd Dest
    invoke DbgOutTextA, ??VarXBX, Color, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgWriteW
; Purpose:    Output a string on the debug device.
; Arguments:  Arg1: -> WIDE String.
;             Arg2: Optional destination Window name.

DbgWriteW macro Var, Color:=<DbgColorForeground>, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
    else
      DbgSaveContext TRUE, Var                          ;;Pass Var as a reference
    endif
    DbgSetDestWnd Dest
    invoke DbgOutTextW, ??VarXBX, Color, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgWrite
; Purpose:    Output a string on the debug device.
; Arguments:  Arg1: Optinal text color.
;             Arg2: Optional destination Window name.
;             Arg3: Quoted format string.
;             Arg 4..n: optional arguments.
; Note:       All registers are allowed as parameters, even indirect references of the form
;             [xbx].POINT.x

DbgWriteF macro Color:=<DbgColorForeground>, Dest, Format, Args:vararg
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest

    ;;Replace register arguments with their memory equivalents
    $$sz2 textequ <>                                    ;;Clear new argument list
    ifnb <Args>
      for $$Arg, <Args>
        $$Attributes = opattr($$Arg)
        ;;%echo $ToStr(%$$Attributes)

        if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE))    ;;E.g. [xax]
          $$sz1 textequ GetMemBSS(type(XWORD))
          push XWORD ptr $$Arg                          ;;Avoid using a register
          pop XWORD ptr $$sz1                           ;;$$sz1 is not SS-Relative
        elseif ($$Attributes eq (OAT_NO_ERROR or OAT_REGISTER))   ;;Register
          $$sz1 textequ GetMemBSS(type($$Arg))
          mov $$sz1, $$Arg
        else
          $$sz1 textequ <$$Arg>                         ;;Set default value
        endif

        ;;Build new argument list
        ifb $$sz2
          $$sz2 textequ $$sz1                           ;;Start the argument list
        else
          $$sz2 catstr $$sz2, <!,>, $$sz1               ;;Extend the argument list
        endif
      endm
    endif

    $$sz1 textequ GetMemBSS(1024*sizeof(CHR))           ;;Get a buffer to write the string
    mov xbx, offset $$sz1
    %WriteF xbx, Format, $$sz2
    invoke DbgOutText, offset $$sz1, Color, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DbgStr textequ <DbgStrA>
else
  DbgStr textequ <DbgStrW>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrA
; Purpose:    Output a specified string on the debug device.
; Arguments:  Arg1: ANSI String.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgStrA macro Var:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DbgColorDefaultPre, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrA - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextA, ??VarXBX, DbgColorString, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrW
; Purpose:    Output a specified WIDE string on the debug device.
; Arguments:  Arg1: WIDE string.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgStrW macro Var:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DbgColorDefaultPre, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrW - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextW, ??VarXBX, DbgColorString, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrCA
; Purpose:    Output a limited ANSI string on the debug device.
; Arguments:  Arg1: ANSI string.
;             Arg2: Character count (fix number, like 8).
;             Arg3: Additional information.
;             Arg4: Optional destination Window name.

DbgStrCA macro Var:req, StrLen:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DbgColorDefaultPre, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrCA - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextCA, ??VarXBX, StrLen, DbgColorString, DbgColorBackground, \
                         DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrCW
; Purpose:    Output a limited WIDE string on the debug device.
; Arguments:  Arg1: WIDE string.
;             Arg2: Character count.
;             Arg3: Additional information.
;             Arg4: Optional destination Window name.

DbgStrCW macro Var:req, StrLen:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DbgColorDefaultPre, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrCW - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextCW, ??VarXBX, StrLen, DbgColorString, DbgColorBackground, \
                         DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DbgStrC textequ <DbgStrCA>
else
  DbgStrC textequ <DbgStrCW>
endif


; ==================================================================================================
;   Number debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgHex
; Purpose:    Display a number in hexadecimal format on the debug device.
; Arguments:  Arg1: Number (register or symbol).
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgHex DWORD ptr [rcx]

DbgHex macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    DbgOutHex <Var = >,, ??VarXBX,, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBin
; Purpose:    Output a number in binary format on the debug device.
; Arguments:  Arg1: Number (register or symbol). Max 32 bits.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgBin DWORD ptr [rcx]

DbgBin macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("&Var = "), DbgColorDefaultPre, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    if TARGET_BITNESS eq 32
      $$Buffersize = 24h                                ;;32 + "y" + ZTC + Padding(2) = 24h
      sub esp, $$Buffersize                             ;;Reserve a buffer on the stack.
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      $$Buffersize = 70h                                ;;64 + "y" + ZTC + Padding(6) + Homing = 70h
      sub rsp, $$Buffersize                             ;;Reserve a buffer on the stack.
      lea rdi, [rsp + 28h]                              ;;Get a POINTER to the output buffer
    endif
    mov xsi, xdi                                        ;;Save it
    mov xcx, 8*type(Var)
    if @WordSize ne type(Var)
      rcl xbx, 8*(@WordSize - type(Var))                ;;Skip unused bits in rbx
    endif
  @@:
    rcl xbx, 1                                          ;;Set bit in carry flag
    setc al
    add al, "0"
    stosb
    loop @B
    mov DCHRA ptr [xdi], "y"                            ;;Set "y" specifier and ZTC
    invoke DbgOutTextA, xsi, DbgColorDefaultVar, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    add xsp, $$Buffersize                               ;;Restore stack
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgDec
; Purpose:    Output a number in signed decimal format on the debug device.
; Arguments:  Arg1: Number (register or symbol).
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgDec DWORD ptr [rcx]

DbgDec macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("&Var = "), DbgColorDefaultPre, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    if TARGET_BITNESS eq 32
      $$Buffersize = 0Ch                                ;;10 + "t" + ZTC + Padding(0) = 0Ch
      sub esp, $$Buffersize                             ;;Reserve a buffer on the stack.
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      $$Buffersize = 44h                                ;;20 + "y" + ZTC + Padding(4) + Homing(28h)
      sub rsp, $$Buffersize                             ;;Reserve a buffer on the stack.
      lea rdi, [rsp + 28h]                              ;;Get a POINTER to the output buffer
    endif
    if ??DbgDataSize eq 1
      movsx ebx, ??VarXBX
      invoke sdword2decA, xdi, ebx
      mov edx, DbgColorDefaultVar
    elseif ??DbgDataSize eq 2
      movsx ebx, ??VarXBX
      invoke sdword2decA, xdi, ebx
      mov edx, DbgColorDefaultVar
    elseif ??DbgDataSize eq 4
      invoke sdword2decA, xdi, ??VarXBX
      mov edx, DbgColorDefaultVar
    elseif ??DbgDataSize eq 8
      invoke sqword2decA, xdi, ??VarXBX
      mov edx, DbgColorDefaultVar
    else
      mov xdi, $OfsCStrA("invalid argument")
      mov edx, DbgColorError
    endif
    invoke DbgOutTextA, xdi, edx, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    add xsp, $$Buffersize                               ;;Restore stack
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFloat
; Purpose:    Display a floating point number in decimal format on the debug device.
; Arguments:  Arg1: Floating point number (REAL4 or REAL8)
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgFloat macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    if (??DbgDataSize ne 4) and (??DbgDataSize ne 8) and (??DbgDataSize ne 10)
      .err <DbgFloat - wrong argument type>
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgFloat - invalid parameter>
      else
        DbgSaveContext TRUE, Var
        DbgSetDestWnd Dest
        fInit
        if ??DbgDataSize eq 4
          fld REAL4 ptr [xbx]
        elseif ??DbgDataSize eq 8
          fld REAL8 ptr [xbx]
        else
          fld REAL10 ptr [xbx]
        endif
        mov xdi, xsp
        sub xsp, DBG_FLOAT_BUFFERSIZE + 28h             ;;Reserve a buffer for the number
        lea xsi, [xsp + 28h]                            ;; Keep stack aligned!
        invoke DbgOutTextA, $OfsCStrA("&Var = "), DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
        invoke St0ToStrA, xsi, 0, DBG_FLOAT_RESOLUTION, 1
        invoke DbgOutTextA, xsi, DbgColorFPU, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
        add xsp, DBG_FLOAT_BUFFERSIZE + 28h             ;;Restore stack
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgGUID
; Purpose:    Output the a GUID on the debug device.
; Arguments:  Arg1: GUID.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgGUID macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    if (??DbgDataSize ne @WordSize) and (??DbgDataSize ne type(GUID))
      .err <DbgGUID - wrong argument type>
    else
      DbgSaveContext TRUE, Var
      DbgSetDestWnd Dest
      if TARGET_BITNESS eq 32
        $$Buffersize = 28h                              ;;36 + ZTC + Padding(3) = 28Ch
        sub esp, $$Buffersize                           ;;Reserve a buffer on the stack.
        mov edi, esp                                    ;;Get a pointer to the buffer
      else
        $$Buffersize = 48h                              ;;36 + ZTC + Padding(3) + Homing = 48h
        sub rsp, $$Buffersize                           ;;Reserve a buffer on the stack.
        lea rdi, [rsp + 20h]                            ;;Get a POINTER to the output buffer
      endif
      invoke GUID2StrA, xdi, ??VarXBX
      if ??DbgDataSize eq @WordSize
        invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), \
                            DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      else
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), \
                            DbgColorDefaultPre, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
      invoke DbgOutTextA, xdi, DbgColorDefaultVar, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
      add xsp, $$Buffersize                             ;;Restore stack
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgARGB
; Purpose:    Output the an ARGB color on the debug device.
; Arguments:  Arg1: ARGB DWORD color value.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgARGB macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    if type(Var) ne type(DWORD)
      .err <DbgARGB - invalid argument.>
    endif
    mov edi, ebx
    shr ebx, 24
    DbgOutHex <Var = [A:>, DbgColorDefaultPre, al, DbgColorForeground, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA(", "), DbgColorForeground, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    mov ebx, edi
    DbgOutHex <R:>, DBG_COLOR_RED, al, DBG_COLOR_RED, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA(", "), DbgColorForeground, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    mov ebx, edi
    shr ebx, 8
    DbgOutHex <G:>, DBG_COLOR_GREEN, al, DBG_COLOR_GREEN, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA(", "), DbgColorForeground, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    mov ebx, edi
    shr ebx, 16
    DbgOutHex <B:>, DBG_COLOR_BLUE, al, DBG_COLOR_BLUE, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA("]"), DbgColorForeground, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd

    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm


; ==================================================================================================
;   Bitmap debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBmp
; Purpose:    Output a specified bitmap on the debug device.
; Arguments:  Arg1: Bitmap HANDLE.
;             Arg2: Optional destination Window name.

DbgBmp macro hBmp:req, Dest
  if DEBUGGING
    DbgSaveContext FALSE, hBmp
    DbgSetDestWnd Dest
    ifidn DBG_DEVICE, <WND>
      .if ??VarXBX != 0
        invoke DbgOutBitmap, ??VarXBX, DbgColorBackground, ??DbgDstWnd
      .else
        invoke DbgOutTextA, $OfsCStrA("Invalid bitmap HANDLE"), \
                            DbgColorError, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
      .endif
    else
      invoke DbgOutTextA, $OfsCStrA("Bitmap can not be shown on this device"), \
                          DbgColorError, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBmpFromDC
; Purpose:    Output a specified bitmap on the debug device.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Optional destination Window name.

DbgBmpFromDC macro hDC:req, Dest
  if DEBUGGING
    DbgSaveContext FALSE, hDC
    DbgSetDestWnd Dest
    ifidn DBG_DEVICE, <WND>
      invoke GetCurrentObject, hDC, OBJ_BITMAP
      invoke DbgOutBitmap, xax, DbgColorBackground, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA("Bitmap can not be shown on this device..."), \
                          DbgColorError, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm


; ==================================================================================================
;   Memory debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgMem
; Purpose:    Output a memory block on the debug device.
; Arguments:  Arg1: -> memory block.
;             Arg2: Size of memory block.
;             Arg3: Output format (DBG_MEM_STR, DBG_MEM_[U]I??, DBG_MEM_R?, DBG_MEM_H??).
;             Arg4: Additional information.
;             Arg5: Optional destination Window name.

DbgMem macro pData:req, DataSize:req, OutputFormat:=<DBG_MEM_NONE>, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, pData                          ;;Pass pData as a value
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("MEMORY DUMP of &pData"), DbgColorMemory, DbgColorBackground, \
                        DBG_EFFECT_BOLD, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    invoke DbgOutMem, ??VarXBX, DataSize, OutputFormat, DbgColorMemory, \
                      DbgColorForeground, DbgColorBackground, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgGlobalMemUsage
; Purpose:    Display global memory usage on the debug window.
; Arguments:  Arg1: Additional information.
;             Arg2: Optional destination Window name.

DbgGlobalMemUsage macro InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    mov xbx, xsp                                        ;;Save stack pointer
    sub xsp, 96                                         ;;Keep stack aligned!
    mov xsi, xsp
    sub xsp, sizeof(MEMORYSTATUS)                       ;;Keep stack aligned!
    mov xdi, xsp
    assume xdi:ptr MEMORYSTATUS
    if TARGET_BITNESS eq 64
      sub xsp, 20h                                      ;;Homing area
    endif
    invoke GlobalMemoryStatus, xdi                      ;;No need to set MEMORYSTATUS.dwLength

    invoke wsprintfA, xsi, $OfsCStrA("Memory load: %lu%%"), [xdi].MEMORYSTATUS.dwMemoryLoad
    invoke DbgOutTextA, xsi, DbgColorMemory, DbgColorBackground, DBG_EFFECT_BOLD, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd

    invoke wsprintfA, xsi, $OfsCStrA(" - Physical: %lu of %lu bytes."), \
                      [xdi].dwAvailPhys, [xdi].dwTotalPhys
    invoke DbgOutTextA, xsi, DbgColorMemory, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    invoke wsprintfA, xsi, $OfsCStrA(" - PageFile: %lu of %lu bytes."), \
                      [xdi].dwAvailPageFile, [xdi].dwTotalPageFile
    invoke DbgOutTextA, xsi, DbgColorMemory, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    invoke wsprintfA, xsi, $OfsCStrA(" - Virtual : %lu of %lu bytes."), \
                      [xdi].dwAvailVirtual, [xdi].dwTotalVirtual
    invoke DbgOutTextA, xsi, DbgColorMemory, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    mov xsp, xbx
    DbgLoadContext
  endif
endm




; ==================================================================================================
;   Hardware debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFPU
; Purpose:    Output the content of the FPU registers on the debug device.
; Arguments:  Arg1: Additional information.
;             Arg2: Optional destination Window name.

DbgFPU macro InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("FPU DUMP"), DbgColorFPU, DbgColorBackground, \
                        DBG_EFFECT_BOLD, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    invoke DbgOutFPU, ??DbgDstWnd, DbgColorFPU, DbgColorBackground
    DbgLoadContext
  endif
endm

; ==================================================================================================
;   OS debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgMessage
; Purpose:    Translate a windows message to a string and output it to the debug device.
; Arguments:  Arg1: Windows message.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgMessage macro Var:req, InfoText, Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext FALSE, Var
      DbgSetDestWnd Dest
      invoke DbgOutMsg, ebx, DbgColorMessage, DbgColorBackground, ??DbgDstWnd
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgApiError
; Purpose:    Translate an API error to a string and output it to the debug device.
; Arguments:  Arg1: Additional information.
;             Arg2: Optional destination Window name.

DbgApiError macro InfoText, Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke GetLastError
      invoke DbgOutApiErr, eax, DbgColorError, DbgColorBackground, ??DbgDstWnd
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgComError
; Purpose:    Translate a COM error to a string and output it to the debug device.
; Arguments:  Arg1: COM error code.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgComError macro Var:req, InfoText, Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext FALSE, Var
      DbgSetDestWnd Dest
      invoke DbgOutComErr, ebx, DbgColorError, DbgColorBackground, ??DbgDstWnd
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm


; ==================================================================================================
;   Object debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgObject
; Purpose:    Output object variables to the debug device.
; Arguments:  Arg1: Instance::ClassName.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Return:     Nothing.
; Note:       ebp is assumed to nothing!

DbgObject macro Expression, InfoText, Dest
  if DEBUGGING
    PreParseExpr Expression
    if $ParseInstExpr(Expression) eq FALSE or ??Pos3 ne 0
      .err <DbgObject - invalid syntax: Expression>
    else
      %ifndef ??ObjExpr
        %.err <DbgObject - unknown object: ??ObjExpr>
      else
        DbgSaveContext TRUE, ??InsExpr
        DbgSetDestWnd Dest
        invoke DbgShowObjectHeader, $OfsCStrA(<!"%??ObjExpr!">), xbx, \
                                    DbgColorObject, DbgColorBackground, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        mov xdi, xbx

        %for ??TestObject, @CatStr(<!<>, %??ObjExpr, <_InherFrwPath!>>)
          $$ACount = 0
          %repeat @CatStr(<??TestObject>, <_VCount>)
            $$ACount = $$ACount + 1
            $$sz1 textequ @CatStr(<??TestObject>, <_VarName_>, %$$ACount)
            $$sz2 textequ @CatStr(<??TestObject>, <_VarType_>, %$$ACount)
            if @InStr(1, <%$$sz2>, <??>) eq 1
              $$Pos2 InStr 3, $$sz2, <_Init>
              if $$Pos2 gt 3
                $$sz2 CatStr @SubStr(<%$$sz2>, 3, $$Pos2 - 3)
              endif
            endif
            lea xbx, @CatStr(<[xdi].>, <??TestObject>, <.>, %$$sz1)
            push xdi
            %DbgOutHex < - &$$sz1 = >, DbgColorObject, \
                       @CatStr(<[xdi].>, <??TestObject>, <.>, %$$sz1),, ??DbgDstWnd
            pop xdi
            %ifidn <??TestObject>, <??ObjExpr>
              invoke DbgOutTextA, $OfsCStrA(<!" (%$$sz2)!">), \
                                   DbgColorObject, DbgColorBackground, \
                                   DBG_EFFECT_NEWLINE, ??DbgDstWnd
            else
              invoke DbgOutTextA, $OfsCStrA(<!" (%$$sz2 from &??TestObject)!">), \
                                   DbgColorObject, DbgColorBackground, \
                                   DBG_EFFECT_NEWLINE, ??DbgDstWnd
            endif
          endm
        endm
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgVMT
; Purpose:    Output offsets contained in a VMT.
; Arguments:  Arg1: Instance::ClassName.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Return:     Nothing.
; Note:       ebp is assumed to nothing!

DbgVMT macro Expression, InfoText, Dest
  if DEBUGGING
    PreParseExpr Expression
    if $ParseInstExpr(Expression) eq FALSE or ??Pos3 ne 0
      .err <DbgVMT - invalid syntax: Expression>
    else
      %ifndef ??ObjExpr
        %.err <DbgVMT - unknown object: ??ObjExpr>
      else
        DbgSaveContext TRUE, ??InsExpr
        DbgSetDestWnd Dest
        invoke DbgShowObjectHeader, $OfsCStrA(<!"%??ObjExpr!">), xbx, \
                                    DbgColorObject, DbgColorBackground, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        mov xdi, [xbx]                                  ;;xbx -> VMT
        DbgOutHex < Virtual Method Table @ >, DbgColorVMT, xbx, DbgColorForeground, ??DbgDstWnd
        invoke DbgOutTextA, offset(bCRLF), DbgColorForeground, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
        %for ??TestObject, @CatStr(<!<>, %??ObjExpr, <_InherFrwPath!>>)
          $$ACount = 0
          %repeat @CatStr(<??TestObject>, <_VtlMtdCount>)
            $$ACount = $$ACount + 1
            $$sz1 CatStr <??TestObject>, <_VtlMethodName_>, %$$ACount
            %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!" - >, @SubStr(%$$sz1, ??MtdPfxOfs), \
                                 < method @ !">)), \
                                 DbgColorVMT, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
            DbgOutHex,, @CatStr(<[xdi - sizeof(??>, ??TestObject, <_VMT) - @WordSize].??>, \
                                ??TestObject, <_VMT.>, %$$sz1), 0, ??DbgDstWnd
            invoke DbgOutTextA, offset(bCRLF), \
                                DbgColorForeground, DbgColorBackground, \
                                DBG_EFFECT_NORMAL, ??DbgDstWnd
          endm
        endm
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgIMT
; Purpose:    Output offsets contained in a IMT.
; Arguments:  Arg1: Instance::ClassName.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Return:     Nothing.
; Note:       ebp is assumed to nothing!

DbgIMT macro Expression, InfoText, Dest
  if DEBUGGING
    PreParseExpr Expression
    if $ParseInstExpr(Expression) eq FALSE or ??Pos3 ne 0
     .err <DbgIMT - invalid syntax: Expression>
    else
      %ifndef ??ObjExpr
        %.err <DbgIMT - unknown object: ??ObjExpr>
      else
        DbgSaveContext TRUE, ??InsExpr
        DbgSetDestWnd Dest
        invoke DbgShowObjectHeader, $OfsCStrA(<!"%??ObjExpr!">), xbx, \
                                    DbgColorObject, DbgColorBackground, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        mov xdi, [xbx]                                  ;;xbx -> VMT
        DbgOutHex < Interface Method Table @ >, DbgColorVMT, xbx, DbgColorForeground, ??DbgDstWnd
        invoke DbgOutTextA, offset(bCRLF), DbgColorForeground, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
        %for ??TestObject, @CatStr(<!<>, %??ObjExpr, <_InherFrwPath!>>)
          $$ACount = 0
          %repeat @CatStr(<??TestObject>, <_IfcMtdCount>)
            $$ACount = $$ACount + 1
            $$sz1 CatStr <??TestObject>, <_IfcMethodName_>, %$$ACount
            %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!" - >, @SubStr(%$$sz1, ??MtdPfxOfs, \
                                 < method @ !">)), \
                                 DbgColorVMT, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
            DbgOutHex,, @CatStr(<[xdi - sizeof(??>, ??TestObject, <_IMT) - @WordSize].??>, \
                                 ??TestObject, <_VMT.>, %$$sz1), 0, ??DbgDstWnd
            invoke DbgOutTextA, offset(bCRLF), \
                                DbgColorForeground, DbgColorBackground, \
                                DBG_EFFECT_NORMAL, ??DbgDstWnd
          endm
        endm
        DbgLoadContext
      endif
    endif
  endif
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      DbgTraceObject
;; Purpose:    Start tracing of an object instance.
;; Arguments:  Arg1: Instance POINTER.
;
;DbgTraceObject macro IName:req
;  if DEBUGGING
;    if TRACING
;      DbgSaveContext TRUE, IName
;      if type(IName) eq @WordSize             ;;If true, then it's not an Object instance!
;        if (opattr IName) and OAT_REGISTER    ;;Is ??DbgIName a register?
;          mov ??pDbgTraceInstance, IName
;        else
;          mrm ??pDbgTraceInstance, IName, xax
;        endif
;      else
;        ??Attributes = opattr(IName)
;        if ??Attributes eq 00100010y or ??Attributes eq 01100010y
;          lea xcx, IName
;          mov ??pDbgTraceInstance, xcx
;        else
;          mov ??pDbgTraceInstance, offset(IName)
;        endif
;      endif
;      DbgLoadContext
;    else
;      %echo @CatStr(<WARNING: TRACE debug option is not active (>, %@FileCur, <, >, %@Line, <).>)
;    endif
;  endif
;endm
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      DbgTraceShow
;; Purpose:    Display gattered trace information.
;; Arguments:  Arg1: Object name.
;;             Arg2: Additional information.
;;             Arg2: Optional destination Window name.
;
;DbgTraceShow macro OName:req, InfoText, Dest
;  if DEBUGGING
;    if TRACING
;      DbgSaveContext
;      DbgSetDestWnd Dest
;      invoke DbgShowObjectHeader, $OfsCStrA("&OName"), ??pDbgTraceInstance, \
;                                  DbgColorObject, DbgColorBackground, ??DbgDstWnd
;      DbgShowTxtInfo InfoText, ??DbgDstWnd
;      DbgShowSrcInfo ??DbgDstWnd
;      %DbgShowTraceResult OName, ??DbgDstWnd          ;;Begin recursive display of results
;      DbgLoadContext
;    else
;      %echo @CatStr(<WARNING: TRACE debug option is not active (>, %@FileCur, <, >, %@Line, <).>)
;    endif
;  endif
;endm
;
;DbgShowTraceResult macro OName:req, Dest
;% for ??TestObject, <&OName&_InherFrwPath>
;
;    ;; --------- Virtual methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_VtlMtdCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_VtlMethod_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %ifidn <$$sz1>, <WndProc>
;          ;;WndProc can't be traced due to pSelf is set after the prologue!
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                               DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                               DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;          invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                              DbgColorWarning, DbgColorBackground, \
;                              DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;        else
;          %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                           ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;        endif
;      else                                                ;;It is an abstract method!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                             DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                            DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;;        %echo @CatStr(OName, <_VtlMethod_Proc_>, %$$ACount)
;        invoke DbgOutTextA, $OfsCStrA("Unable to trace this method (abstract, precompiled, etc.)."), \
;                            DbgColorWarning, DbgColorBackground, \
;                            DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;      endif
;    endm
;
;    ;; --------- Interface methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_IfcMtdCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_IfcMethod_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                         ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;      else                                                ;;It is an abstract method!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                            DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                            DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;;        %echo @CatStr(OName, <_VtlMethod_Proc_>, %$$ACount)
;        invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                            DbgColorWarning, DbgColorBackground, \
;                            DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;      endif
;    endm
;
;    ;; --------- Static methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_StcMtdCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_StcMethod_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %ifidn <$$sz1>, <WndProc>
;          ;;WndProc can't be traced due to pSelf is set after the prologue!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                             DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                             DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;          invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                              DbgColorWarning, DbgColorBackground, \
;                              DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;        else
;          %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                           ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;        endif
;      else                                                ;;It is an abstract method!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                            DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                            DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;;        %echo @CatStr(OName, <_VtlMethod_Proc_>, %$$ACount)
;        invoke DbgOutTextA, $OfsCStrA("Unable to trace this method (abstract, precompiled, etc.)."), \
;                            DbgColorWarning, DbgColorBackground, \
;                            DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;      endif
;    endm
;
;    ;; --------- Overwritten methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_OMCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_OvrMtd_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %ifidn <$$sz1>, <WndProc>
;          ;;WndProc can't be traced due to pSelf is stablished after the prologue!
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                              DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                              DbgColorObject, DbgColorBackground, DBG_EFFECT_NORMAL, Dest
;          invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                              DbgColorWarning, DbgColorBackground, \
;                              DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;        else
;          %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                           ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;        endif
;      endif
;    endm
;  endm
;endm
;
;DbgShowTraceVar macro MName:req, Count:req, Ticks:req, Dest
;  mov xax, @SizeStr(MName) + 1                          ;;Include ZTC
;  MemAlloc xax
;  push xax
;  push xax
;  FillStringA [xax], &MName
;  pop xcx
;  invoke DbgShowTraceMethod, xcx, Count, offset(Ticks), Dest
;  pop xax
;  MemFree xax
;endm
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgAttach
; Purpose:    Break execution and attaches the system debugger. If already loaded, nothing is done.
; Arguments:  None.

DbgAttach macro
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      .if $invoke(IsDebuggerPresent) == FALSE
        @CatStr(<int >, <3>)
      .endif
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBreak
; Purpose:    Break execution.
; Arguments:  None.

DbgBreak macro
  if DEBUGGING
    @CatStr(<int >, <3>)                                ;;Written this way to disable int3 search
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseAll
; Purpose:    Close all child windows of the Debug window.
; Arguments:  None.

DbgCloseAll macro
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        invoke DbgOutCmd, DBG_CMD_CLOSE_ALL, 0, 0, NULL
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClose
; Purpose:    Close a specific child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgClose macro Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        DbgSetDestWnd Dest
        invoke DbgOutCmd, DBG_CMD_CLOSE_TXT, 0, 0, ??DbgDstWnd
        invoke DbgOutCmd, DBG_CMD_CLOSE_BMP, 0, 0, ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseTxt
; Purpose:    Close specific text child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgCloseTxt macro Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        DbgSetDestWnd Dest
        invoke DbgOutCmd, DBG_CMD_CLOSE_TXT, 0, 0, ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseBmp
; Purpose:    Close specific bitmap child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgCloseBmp macro Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        DbgSetDestWnd Dest
        invoke DbgOutCmd, DBG_CMD_CLOSE_BMP, 0, 0, ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClearAll
; Purpose:    Clear the content of all child windows of the Debug window.
; Arguments:  None.

DbgClearAll macro
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      ifidn DBG_DEVICE, <WND>
        invoke DbgOutCmd, DBG_CMD_CLEAR_ALL, DbgColorBackground, 0, NULL
      elseifidn DBG_DEVICE, <CON>
        ;... cls
      elseifidn DBG_DEVICE, <LOG>
        ;... close and delete file
      endif
      DbgLoadContext
    elseif TARGET_PLATFORM eq PLATFORM_UEFI
      mov xcx, pConsoleOut
      invoke [xcx].ConOut.ClearScreen, xcx
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClear
; Purpose:    Clear the content of a specific child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgClear macro Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        DbgSetDestWnd Dest
        invoke DbgOutCmd, DBG_CMD_CLEAR_TXT, DbgColorBackground, 0, ??DbgDstWnd
        invoke DbgOutCmd, DBG_CMD_CLEAR_BMP, DbgColorBackground, 0, ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClearTxt
; Purpose:    Clear the content of a specific text child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgClearTxt macro Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        DbgSetDestWnd Dest
        invoke DbgOutCmd, DBG_CMD_CLEAR_TXT, DbgColorBackground, 0, ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClearBmp
; Purpose:    Clear the content of a specific bitmap child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgClearBmp macro Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ifidn DBG_DEVICE, <WND>
        DbgSaveContext
        DbgSetDestWnd Dest
        invoke DbgOutCmd, DBG_CMD_CLEAR_BMP, DbgColorBackground, 0, ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Fix
; Purpose:    Reminder text echoed at compile time.
; Arguments:  Arg1: (optional) Text.

Fix macro Txt:=<Fix this later>
% echo @CatStr(<Fix: >, %@FileCur, < (>, %@Line, <) - >, <&Txt>)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ASSERT
; Purpose:    Display a message if an argument value is FALSE.
; Arguments:  Arg1: Value.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       ! acts as escape character, use !!= as unequality comparison.

ASSERT macro Expression:req, InfoText, Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      pushcontext assumes
      pushfx                                            ;;Save CPU flags
      pushax
      .if Expression                                    ;Evaluate expression
        mov ebx, TRUE
      .else
        xor ebx, ebx
      .endif
      DbgSetDestWnd Dest
      cld                                               ;;Reset direction flag for API calling!
      mov xdi, xsp                                      ;;Save current esp value in xdi
      if TARGET_BITNESS eq 32
        and xsp, 0FFFFFFF0h                             ;;Align stack on a 16 byte boundary
      else
        and xsp, 0FFFFFFFFFFFFFFF0h                     ;;Align stack on a 16 byte boundary
      endif
      sub xsp, 20h
      invoke EnterCriticalSection, offset(DbgCritSect)  ;;This call don't change GetLastError
      .if ebx == FALSE
        invoke DbgOutTextA, $OfsCStrA("Assertion failed"), \
                            DbgColorWarning, DbgColorBackground, DBG_EFFECT_BOLD, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
      .endif
      invoke LeaveCriticalSection, offset(DbgCritSect)
      mov xsp, xdi                                      ;;Restore rsp
      popax                                             ;;Restore CPU registers
      popfx                                             ;;Direction flag is restored here too
      popcontext assumes
    endif
  endif
endm


; ==================================================================================================
;   ResGuard macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ResGuard_Show
; Purpose:    Show the result of ResGuard system activity.
; Arguments:  None.

ResGuard_Show macro
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      invoke DbgOutTextA, $OfsCStrA("Report  "), \
                          DbgColorForeground, DbgColorBackground, \
                          DBG_EFFECT_BOLD, offset(szLeakReport)
      DbgShowSrcInfo offset(szLeakReport)
      invoke ResGuardShow
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ResGuard_Start
; Purpose:    Start activity of the ResGuard system.
; Arguments:  None.

ResGuard_Start macro
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      invoke DbgOutTextA, $OfsCStrA("Started "), \
                          DbgColorForeground, DbgColorBackground, \
                          DBG_EFFECT_BOLD, offset(szLeakReport)
      DbgShowSrcInfo offset(szLeakReport)
      invoke ResGuardStart
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ResGuard_Stop
; Purpose:    Stop activity of the ResGuard system.
; Arguments:  None.

ResGuard_Stop macro
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      DbgSaveContext
      invoke DbgOutTextA, $OfsCStrA("Stopped "), \
                          DbgColorForeground, DbgColorBackground, \
                          DBG_EFFECT_BOLD, offset(szLeakReport)
      DbgShowSrcInfo offset(szLeakReport)
      invoke ResGuardStop
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgComponent
; Purpose:    Output Componet information on the debug device.
; Arguments:  Arg1: GUID.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgComponent macro Var:req, InfoText, Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ??DbgDataSize = type(Var)
      if (??DbgDataSize ne @WordSize) and (??DbgDataSize ne sizeof(GUID))  ;??!!
        .err <DbgComponent - wrong argument.>
      else
        DbgSaveContext TRUE, Var
        DbgSetDestWnd Dest
        invoke DbgOutComponent, ??VarXBX, \
                                DbgColorObject, DbgColorBackground, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgInterface
; Purpose:    Output Interface information on the debug device.
; Arguments:  Arg1: IID.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgInterface macro Var:req, InfoText, Dest
  if DEBUGGING
    if TARGET_PLATFORM eq PLATFORM_WINDOWS
      ??DbgDataSize = type(Var)
      if (??DbgDataSize ne @WordSize) and (??DbgDataSize ne sizeof(GUID))
        .err <DbgInterface - wrong argument.>
      else
        DbgSaveContext TRUE, Var
        DbgSetDestWnd Dest
        invoke DbgOutInterface, ??VarXBX, DbgColorInterface, DbgColorBackground, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm
