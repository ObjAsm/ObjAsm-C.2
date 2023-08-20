; ==================================================================================================
; Title:   MemLeak_Globals.inc
; Author:  G. Friedrich  @ March 2005
; Version: 1.0.0
; Purpose: Globals for Memory Leakage demonstration program.
; ==================================================================================================


CStr szAppTitle,  "MemLeak"
CStr szAboutText, "MemLeak Application", 13, 10, 13, 10, \
                  "Designed with ObjAsm32", 13, 10, \
                  "using Microsoft's MASM", 13, 10, 13, 10, \
                  "Copyright © G.Friedrich   March 2005"

IDC_TEXT_ABOUT    equ     100

;Menu IDs
IDM_FILE_NEW      equ     50
IDM_FILE_OPEN     equ     51
IDM_FILE_SAVE     equ     52
IDM_FILE_SAVEAS   equ     53

IDM_EDIT_CUT      equ     54
IDM_EDIT_COPY     equ     55
IDM_EDIT_PASTE    equ     56

IDM_HELLO         equ     1000
IDM_EXIT          equ     1001
IDM_ABOUT         equ     1999

;Bitmap IDs
IDB_FILE_NEW      equ     00
IDB_FILE_OPEN     equ     01
IDB_FILE_SAVE     equ     02
IDB_FILE_SAVEAS   equ     03
IDB_FILE_RCV      equ     07
IDB_FILE_SND      equ     08

IDB_EDIT_CUT      equ     04
IDB_EDIT_COPY     equ     05
IDB_EDIT_PASTE    equ     06

;Control IDs
IDC_TOOLBARFILE   equ     100
IDC_TOOLBAREDIT   equ     101
IDC_STATUSBAR     equ     102
