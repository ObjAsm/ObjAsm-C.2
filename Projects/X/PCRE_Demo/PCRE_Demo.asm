; =================================================================================================
; Title:      PCRE_Demo.asm
; Author:     G. Friedrich
; Version:    1.1.0
; Purpose:    ObjAsm RegEx Application.
; Notes:      Version 1.0.0, October 2017
;               - Initial release.
;             Version 1.1.0, December 2020
;               - Updated to PCRE 8.44.
; =================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

.code

% include &IncPath&PCRE\PCRE844S.inc
% includelib &LibPath&PCRE\PCRE844S&TARGET_STR_AFFIX&.lib
% includelib &LibPath&Windows\MSVCRT.lib
% includelib &LibPath&Windows\UUID.lib

MakeObjects Primer, Stream, RegEx

HELP_NONE           equ   0
HELP_XCALL          equ   1
HELP_OBJ_VARIABLE   equ   2
HELP_DESTROY        equ   3
HELP_KILL           equ   4
HELP_NEW            equ   5
HELP_XOBJECTS       equ   6
HELP_EMBED          equ   7

;                    aaaaaaaaaaaaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx yyyyyyyyyyyyyyyyyyyyyyyy zzzzzzzzzzzzzzzzzzz
CStr REXP_XCall,    "(\bx?([OADTI])Call[ \t]+|\B\$x?([OADTI])Call[ \t]*\([ \t]*)((\w+)[ \t]*::[ \t]*(\w*)(|[ \t]*\.[ \t]*(\w*))|(\w+)[ \t]*\.[ \t]*(\w*)|[ \t]*\.[ \t]*(\w*))$"
CStr REXP_ObjVar,   "\[[ \t]*(rax|rbx|rcx|rdx|rdi|rsi|rbx|rsp)[ \t]*\][ \t]*\.[ \t]*(\w*)$"
CStr REXP_Destroy,  "[ \t]*\bDestroy[ \t]+((\w+)[ \t]*::[ \t]*(\w*)(|\.[ \t]*(\w*))|(\w+)[ \t]*\.[ \t]*(\w*)|[ \t]*\.[ \t]*(\w*))$"
CStr REXP_Kill,     "[ \t]*\bKill[ \t]+((\w+)[ \t]*::[ \t]*(\w*)(|\.[ \t]*(\w*))|(\w+)[ \t]*\.[ \t]*(\w*)|[ \t]*\.[ \t]*(\w*))$"
CStr REXP_New,      "(\bNew[ \t]+|\B\$New[ \t]*\([ \t]*)(\w*)$"
CStr REXP_XObjects, "\b(Make|Load|Virtual)Objects[ \t]+(\w+[ \t]*,[ \t]*)*(\w*)$"
CStr REXP_Embed,    "\bEmbed[ \t]+(\w*)$", 0

;CStr cSubject, " $xOCall ( iii::ooo.mmm"
CStr cSubject, " xOCall iii::ooo.mmm"
;CStr cSubject, " xOCall iii::ooo"
;CStr cSubject, " xOCall .mmm"
;CStr cSubject, " xOCall iii.mmm"
;CStr cSubject, " [rsi].mmm"
;CStr cSubject, " Destroy .Mthd"
;CStr cSubject, "mov eax, $New  ( ddd"
;CStr cSubject, " MakeObjects Primer, Triangle, Rectangle, Circle, aaa"
;CStr cSubject, " Embed Primer"

.data
REX_XCall     $ObjInst(%RegEx)
REX_ObjVar    $ObjInst(%RegEx)
REX_Destroy   $ObjInst(%RegEx)
REX_Kill      $ObjInst(%RegEx)
REX_New       $ObjInst(%RegEx)
REX_XObjects  $ObjInst(%RegEx)
REX_Embed     $ObjInst(%RegEx)

.code

if DEBUGGING
  GetHelpCode proc pLineBuffer:POINTER, dCursorPos:DWORD
    .if dCursorPos > 0
      OCall REX_XCall::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_XCall
        mov eax, HELP_XCALL
        ;XCall Inst::Objt         08 => 2|3:X / 5:Inst / 6:Objt
        ;XCall Inst::Objt.Mthd    09 => 2|3:X / 5:Inst / 6:Objt / 8:Mthd
        ;XCall Inst.Mthd          11 => 2|3:X / 9:Inst /10:Mthd
        ;XCall .Mthd              12 => 2|3:X /11:Mthd
        jmp @@Exit
      .endif
      OCall REX_ObjVar::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_ObjVar
        mov eax, HELP_OBJ_VARIABLE
        ;[register].Method        1:register / 2:Method
        jmp @@Exit
      .endif
      OCall REX_Destroy::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_Destroy
        mov eax, HELP_DESTROY
        ;Destroy Inst::Objt       2:Inst / 3:Objt
        ;Destroy Inst::Objt.Mthd  2:Inst / 3:Objt / 5:Mthd
        ;Destroy Inst.Mthd        6:Inst / 7:Mthd
        ;Destroy Inst.Mthd        8:Mthd
        jmp @@Exit
      .endif
      OCall REX_Kill::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_Kill
        mov eax, HELP_KILL
        ;Kill Inst::Objt          2:Inst / 3:Objt
        ;Kill Inst::Objt.Mthd     2:Inst / 3:Objt / 5:Mthd
        ;Kill Inst.Mthd           6:Inst / 7:Mthd
        ;Kill Inst.Mthd           8:Mthd
        jmp @@Exit
      .endif
      OCall REX_New::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_New
        mov eax, HELP_NEW
        ;New Objt / $New(Objt     2:Objt
        jmp @@Exit
      .endif
      OCall REX_XObjects::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_XObjects
        mov eax, HELP_XOBJECTS    ;04 => 1:Make / 3:last object
        jmp @@Exit
      .endif
      OCall REX_Embed::%RegEx.Exec, pLineBuffer, dCursorPos, 0, 0
      .if sdword ptr eax >= 0
        mov xcx, offset REX_Embed
        mov eax, HELP_EMBED       ;02 => 1:object
        jmp @@Exit
      .endif
      xor eax, eax
      xor ecx, ecx
    .else
      xor eax, eax
      xor ecx, ecx
    .endif
  @@Exit:
    ret
  GetHelpCode endp

  ShowVec proc uses xbx xdi xsi pSubject:POINTER, dHelp:DWORD, pREX:POINTER
    local cBuffer[100]:CHR

    DbgSaveContext
    DbgLine
;    DbgDec dHelp
    .if dHelp != 0
      mov xsi, pREX
      mov xbx, [xsi].$Obj(%RegEx).pOutVector
      mov edi, [xsi].$Obj(%RegEx).dMatchCount
;      DbgDec [xsi].RegEx.dMatchCount
      test edi, edi
      .while !ZERO?
        mov eax, [xbx].PCRE_OUTDATA.dEndIndex
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          shl eax, 1
        endif
        mov edx, [xbx].PCRE_OUTDATA.dBegIndex
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          shl edx, 1
        endif
        sub eax, edx
        add xdx, pSubject
        lea xcx, cBuffer
        m2z CHR ptr [xcx + xax]
        invoke MemClone, xcx, xdx, eax
        DbgStr cBuffer
        add xbx, sizeof(PCRE_OUTDATA)                   ;Move to next PCRE_OUTDATA
        dec edi                                         ;Decrement edi counter
      .endw
    .endif
    DbgLoadContext
    ret
  ShowVec endp
endif

start proc uses xbx
  SysInit

  DbgClearAll

;  invoke pcre_version
;  DbgStrA xax

  OCall REX_XCall::%RegEx.Init, NULL, offset REXP_XCall, 0
  OCall REX_XCall::%RegEx.SetOutCount, -1
  OCall REX_XCall::%RegEx.Study, 0

  OCall REX_ObjVar::%RegEx.Init, NULL, offset REXP_ObjVar, 0
  OCall REX_ObjVar::%RegEx.SetOutCount, -1
  OCall REX_ObjVar::%RegEx.Study, 0

  OCall REX_Destroy::%RegEx.Init, NULL, offset REXP_Destroy, 0
  OCall REX_Destroy::%RegEx.SetOutCount, -1
  OCall REX_Destroy::%RegEx.Study, 0

  OCall REX_Kill::%RegEx.Init, NULL, offset REXP_Kill, 0
  OCall REX_Kill::%RegEx.SetOutCount, -1
  OCall REX_Kill::%RegEx.Study, 0

  OCall REX_New::%RegEx.Init, NULL, offset REXP_New, 0
  OCall REX_New::%RegEx.SetOutCount, -1
  OCall REX_New::%RegEx.Study, 0

  OCall REX_XObjects::%RegEx.Init, NULL, offset REXP_XObjects, 0
  OCall REX_XObjects::%RegEx.SetOutCount, -1
  OCall REX_XObjects::%RegEx.Study, 0

  OCall REX_Embed::%RegEx.Init, NULL, offset REXP_Embed, 0
  OCall REX_Embed::%RegEx.SetOutCount, -1
  OCall REX_Embed::%RegEx.Study, 0

  if DEBUGGING
    invoke StrLength, addr cSubject
    invoke GetHelpCode, addr cSubject, eax
    mov xbx, xcx
    invoke ShowVec, addr cSubject, eax, xbx
  endif

  OCall REX_XCall::%RegEx.Done
  OCall REX_ObjVar::%RegEx.Done
  OCall REX_Destroy::%RegEx.Done
  OCall REX_Kill::%RegEx.Done
  OCall REX_New::%RegEx.Done
  OCall REX_XObjects::%RegEx.Done
  OCall REX_Embed::%RegEx.Done

  SysDone

  invoke ExitProcess, 0
start endp

end
