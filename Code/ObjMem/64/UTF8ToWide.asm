; ==================================================================================================
; Title:      UTF8ToWide.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, February 2020
;               - First release.
; Links:      https://en.wikipedia.org/wiki/UTF-8
;             https://en.wikipedia.org/wiki/UTF-16
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UTF8ToWide
; Purpose:    Convert an UTF8 byte stream to a WIDE (UTF16) string.
; Arguments:  Arg1: -> Destination WIDE buffer.
;             Arg2: -> Source UTF8 BYTE stream. Must be zero terminated.
;             Arg3: Destination buffer size in BYTEs.
; Return:     eax = Number of BYTEs written.
;             ecx = 0: succeeded
;                   1: buffer full
;                   2: conversion error
; Notes:      - The destination WIDE string is always terminated with a ZTC
;               (only if buffer size >= 2).

% include &ObjMemPath&Common\UTF8ToWide_XP.inc

end
