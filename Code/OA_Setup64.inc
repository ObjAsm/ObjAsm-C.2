; ==================================================================================================
; Title:      OA_Setup64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Model Setup for 64 bit.
; Notes:      Version C.1.0, October 2017
;             - First release.
; ==================================================================================================


??StackBase equ <rsp>                                   ;Set default

option casemap:none                                     ;Case sensitive
option dotname                                          ;Enable dot names
option frame:auto                                       ;Generate exception handling pro- and epilogues
;option arch:AVX                                         ;Enable AVX instructions
option win64:8                                          ;See flags below (sets CallConv to fastcall)
option stackbase:??StackBase                            ;Default setting (DEBUGGING switches stackbase to rbp)

;W64F_SAVEREGPARAMS = 0x01, // 1=save register parameters in shadow space on proc entry (only when used)
;W64F_AUTOSTACKSP   = 0x02, // 1=calculate required stack space for arguments of INVOKE
;W64F_STACKALIGN16  = 0x04, // 1=stack variables are 16-byte aligned
;W64F_SMART         = 0x08, // 1=takes care of everything (HJWasm)

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
LibPath       CatStr    OA_PATH, <Code\Lib\64\>
ObjPath       CatStr    OA_PATH, <Code\Objects\>
MacPath       CatStr    OA_PATH, <Code\Macros\>
COMPath       CatStr    OA_PATH, <Code\Inc\COM\>
RadPath       CatStr    OA_PATH, <Code\RadASM\>
ObjMemPath    CatStr    OA_PATH, <Code\ObjMem\>
ResPath       CatStr    OA_PATH, <Resources\>
HelpPath      CatStr    OA_PATH, <Help\>
