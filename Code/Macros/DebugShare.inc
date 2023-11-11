; ==================================================================================================
; Title:      DebugShare.inc
; Author:     G. Friedrich
; Purpose:    ObjAsm debug shared definitions.
;             This file provides definitions used by the "application debug system" and DebugCenter.
; ==================================================================================================


;Exported symbols defined in Model.inc
externdef dDbgDev:DWORD
externdef dDbgOpt:DWORD
externdef hDbgDev:HANDLE

;Exported symbols defined in Debug.inc
externdef szDbgCtrCmd:CHRA
externdef szDbgSrc:CHRW
externdef szDbgErr:CHRW
externdef szDbgComErr:CHRW

;Exported symbols defined in Debug.inc
externdef szDbgElipsis:CHRA
externdef szDbgInvalid:CHRA
externdef szDbgPoint2:CHRA
externdef szDbgArrow:CHRA
externdef szDbgBracketLeft:CHRA
externdef szDbgBracketRight:CHRA
externdef szDbgColon:CHRA
externdef szDbgComma:CHRA

;Exported symbols defined in DebugShare.inc
externdef szDbgCtrCls:CHRW

;Exported symbols defined in DbgConstants.asm
externdef szDbgInvalidDevPtr:CHRW
externdef szDbgRegKey:CHRW

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DGB_MSG_ID                equ   58ADF9ACh     ;Random number that identifies these debug messages
DBG_MSG_HDR               equ   00
DBG_MSG_CMD               equ   01
DBG_MSG_STR               equ   02
DBG_MSG_BMP               equ   03

DBG_EFFECT_NORMAL         equ   00000000h     ;Regular text
DBG_EFFECT_BOLD           equ   00000001h     ;CFE_BOLD
DBG_EFFECT_ITALIC         equ   00000002h     ;CFE_ITALIC
DBG_EFFECT_UNDERLINE      equ   00000004h     ;CFE_UNDERLINE
DBG_EFFECT_STRIKEOUT      equ   00000008h     ;CFE_STRIKEOUT
DBG_EFFECT_NEWLINE        equ   00000100h

DBG_CHARTYPE_WIDE         equ   80000000h     ;if not set => ANSI (BIT31)

DBG_CMD_CLEAR_TXT         equ   00
DBG_CMD_CLEAR_BMP         equ   01
DBG_CMD_CLEAR_ALL         equ   02
DBG_CMD_CLOSE_TXT         equ   03
DBG_CMD_CLOSE_BMP         equ   04
DBG_CMD_CLOSE_ALL         equ   05
DBG_CMD_SINGLE_LINE       equ   06            ;char 2500 or 2014
DBG_CMD_DOUBLE_LINE       equ   07            ;Char 2550
DBG_CMD_FLASH_WINDOW      equ   08            ;Flags in dParam1, number of flashes in dParam2
DBG_CMD_FLASH_MENU        equ   09            ;Color in dParam1, number of flashes in dParam2
DBG_CMD_SET_BKGND_TXT     equ   10            ;Color in dParam1
DBG_CMD_SET_BKGND_BMP     equ   11            ;Color in dParam1
DBG_CMD_ZOOM_IN_TXT       equ   12
DBG_CMD_ZOOM_IN_BMP       equ   13
DBG_CMD_ZOOM_OUT_TXT      equ   14
DBG_CMD_ZOOM_OUT_BMP      equ   15
DBG_CMD_FRONT_TXT         equ   16
DBG_CMD_FRONT_BMP         equ   17
DBG_CMD_FRONT_WND         equ   18
DBG_CMD_CHILDREN_TILE_HOR equ   19
DBG_CMD_CHILDREN_TILE_VER equ   20
DBG_CMD_CHILDREN_CASCADE  equ   21
DBG_CMD_ICONS_ARRANGE     equ   22
DBG_CMD_PIN_WND           equ   23
DBG_CMD_CLOSE_WND         equ   24

SMTO_TIMEOUT              equ   5000          ;Timeout of a WM_COPYDATA message


IDM_DEBUG_CENTER_RESTORE  equ   0F6CAh        ;Random number

DBG_IP_PORT textequ <8080>                    ;Default value

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Info:
;   The message sent to the DebugCenter Server looks like:
;
;      ————————————————————————————————————————————————————————————————————————
;     | DBG_HEADER_INFO | Destination Window Name | DBG_XXX_INFO |   Payload   |
;      ————————————————————————————————————————————————————————————————————————
;       DBG_MSG_HDR                                 DBG_MSG_XXX


DBG_HEADER_INFO struc 1                       ;Size = 6t
  bBlockID    BYTE    DBG_MSG_HDR
  bInfo       BYTE    ?                       ;Not used
  dBlockLen   DWORD   ?                       ;Size of this structure + payload size
DBG_HEADER_INFO ends
;Destination WIDE string & ZTC follow this structure

DBG_STR_INFO struc 1                          ;Size = 18t = 12h
              DBG_HEADER_INFO {DBG_MSG_STR}
  dForeColor  DWORD   ?
  dBackColor  DWORD   ?
  dEffects    DWORD   ?                       ;Text effects & flags
DBG_STR_INFO ends
;String characters & ZTC (ANSI/WIDE string) follow this structure

if TARGET_PLATFORM eq PLATFORM_WINDOWS
  DBG_CMD_INFO struc 1                        ;Size = 14t = 0Eh
                DBG_HEADER_INFO {DBG_MSG_CMD}
    dParam1     DWORD   ?                     ;First parameter
    dParam2     DWORD   ?                     ;Second parameter
  DBG_CMD_INFO ends
  ;Additional data bytes may follow this structure

  DBG_BMP_INFO struc 1
                DBG_HEADER_INFO {DBG_MSG_BMP}
    dBackColor  DWORD   ?
    BmpHeader   BITMAPINFOHEADER  {}
  DBG_BMP_INFO ends
  ;Bitmap data follow this structure
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DEBUG_CENTER_CLASS  textequ  <"OAC_DebugCenter">
DEBUG_CENTER_REGKEY textequ  <"Software\DebugCenter">
