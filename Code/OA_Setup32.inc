; ==================================================================================================
; Title:      OA_Setup32.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Model Setup for 32 bit.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


.686p                                                   ;Use 686 protected mode
.mmx                                                    ;Enable MMX instructions
.xmm                                                    ;Enables assembly of SIMD instructions
option casemap:none                                     ;Case sensitive
option dotname                                          ;Enable dot names
;option ARCH:AVX
.model flat, stdcall                                    ;Memory model = flat, use StdCall as default

PAGESIZE          equ   4096
PLATFORM_NONE     equ   1
PLATFORM_UEFI     equ   2
PLATFORM_WINDOWS  equ   3
PLATFORM_OTHER    equ   4

STR_TYPE_ANSI     equ   1
STR_TYPE_WIDE     equ   2
__NO_NOISE__      equ   1                               ;Supress Windows.inc babbling (MASM32 only)

;Paths used to locate objects, libraries, resources, etc. They are statically linked!

OA_PATH       CatStr    @Environ(OBJASM_PATH), <\>      ;Stored in HKEY_CURRENT_USER\Environment

IncPath       CatStr    OA_PATH, <Code\Inc\>
LibPath       CatStr    OA_PATH, <Code\Lib\32\>
ObjPath       CatStr    OA_PATH, <Code\Objects\>
MacPath       CatStr    OA_PATH, <Code\Macros\>
COMPath       CatStr    OA_PATH, <Code\Inc\COM\>
RadPath       CatStr    OA_PATH, <Code\RadASM\>
ObjMemPath    CatStr    OA_PATH, <Code\ObjMem\>
ResPath       CatStr    OA_PATH, <Resources\>
HelpPath      CatStr    OA_PATH, <Help\>
