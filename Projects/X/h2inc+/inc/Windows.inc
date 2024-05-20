;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\windows.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:18:30

include winapifamily.inc
;*++ BUILD Version: 0001    Increment this if a change has global effects
;Copyright (c) Microsoft Corporation. All rights reserved.
;Module Name:
;windows.h
;Abstract:
;Master include file for Windows applications.
;--*
ifndef _WINDOWS_
  _WINDOWS_ equ <>
  include sdkddkver.inc
  ifndef _INC_WINDOWS
    _INC_WINDOWS equ <>
    if Defined(_MSC_VER) and (_MSC_VER ge 1020)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;*  If defined, the following flags inhibit definition
      ;*     of the indicated items.
      ;*
      ;*  NOGDICAPMASKS     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
      ;*  NOVIRTUALKEYCODES - VK_*
      ;*  NOWINMESSAGES     - WM_*, EM_*, LB_*, CB_*
      ;*  NOWINSTYLES       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
      ;*  NOSYSMETRICS      - SM_*
      ;*  NOMENUS           - MF_*
      ;*  NOICONS           - IDI_*
      ;*  NOKEYSTATES       - MK_*
      ;*  NOSYSCOMMANDS     - SC_*
      ;*  NORASTEROPS       - Binary and Tertiary raster ops
      ;*  NOSHOWWINDOW      - SW_*
      ;*  OEMRESOURCE       - OEM Resource values
      ;*  NOATOM            - Atom Manager routines
      ;*  NOCLIPBOARD       - Clipboard routines
      ;*  NOCOLOR           - Screen colors
      ;*  NOCTLMGR          - Control and Dialog routines
      ;*  NODRAWTEXT        - DrawText() and DT_*
      ;*  NOGDI             - All GDI defines and routines
      ;*  NOKERNEL          - All KERNEL defines and routines
      ;*  NOUSER            - All USER defines and routines
      ;*  NONLS             - All NLS defines and routines
      ;*  NOMB              - MB_* and MessageBox()
      ;*  NOMEMMGR          - GMEM_*, LMEM_*, GHND, LHND, associated routines
      ;*  NOMETAFILE        - typedef METAFILEPICT
      ;*  NOMINMAX          - Macros min(a,b) and max(a,b)
      ;*  NOMSG             - typedef MSG and associated routines
      ;*  NOOPENFILE        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
      ;*  NOSCROLL          - SB_* and scrolling routines
      ;*  NOSERVICE         - All Service Controller routines, SERVICE_ equates, etc.
      ;*  NOSOUND           - Sound driver routines
      ;*  NOTEXTMETRIC      - typedef TEXTMETRIC and associated routines
      ;*  NOWH              - SetWindowsHook and WH_*
      ;*  NOWINOFFSETS      - GWL_*, GCL_*, associated routines
      ;*  NOCOMM            - COMM driver routines
      ;*  NOKANJI           - Kanji support stuff.
      ;*  NOHELP            - Help engine interface.
      ;*  NOPROFILER        - Profiler interface.
      ;*  NODEFERWINDOWPOS  - DeferWindowPos routines
      ;*  NOMCX             - Modem Configuration Extensions
      ;*
      if Defined(RC_INVOKED) and  not Defined(NOWINRES)
        ;[...]
      else
        if Defined(RC_INVOKED)
          ;[...]
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_IX86)
          _X86_ equ <>
          if  not Defined(_CHPE_X86_ARM64_) and Defined(_M_HYBRID)
            _CHPE_X86_ARM64_ equ <>
          endif
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and (Defined(_M_AMD64) or Defined(_M_ARM64EC))
          _AMD64_ equ <>
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_ARM)
          ;[...]
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_ARM64)
          ;[...]
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_ARM64EC)
          _ARM64EC_ equ <>
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_M68K)
          ;[...]
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_IA64_) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_MPPC)
          ;[...]
        endif
        if  not Defined(_68K_) and  not Defined(_MPPC_) and  not Defined(_X86_) and  not Defined(_M_IX86) and  not Defined(_AMD64_) and  not Defined(_ARM_) and  not Defined(_ARM64_) and  not Defined(_ARM64EC_) and Defined(_M_IA64)
          if  not Defined(_IA64_)
            _IA64_ equ <>
            ;* !_IA64_ *
          endif
        endif
        ifndef _MAC
          if Defined(_68K_) or Defined(_MPPC_)
            ;[...]
          endif
        endif
        if Defined(_MSC_VER)
          if (_MSC_VER ge 800)
            ifndef __cplusplus
              ;* TYPE_ALIGNMENT generates this - move it *
              ;* outside the warning push/pop scope. *
            endif
          endif
        endif
        ifndef RC_INVOKED
          if (_MSC_VER ge 800)
            ifndef __WINDOWS_DONT_DISABLE_PRAGMA_PACK_WARNING__
            endif
            if _MSC_VER ge 1200
            endif
          endif
          include excpt.inc
          include stdarg.inc
          ;* RC_INVOKED *
        endif
        include windef.inc
        include winbase.inc
        include wingdi.inc
        include winuser.inc
        if  not Defined(_MAC) or Defined(_WIN32NLS)
          include winnls.inc
        endif
        ifndef _MAC
          include wincon.inc
          include winver.inc
        endif
        if  not Defined(_MAC) or Defined(_WIN32REG)
          include winreg.inc
        endif
        ifndef _MAC
          include winnetwk.inc
        endif
        ifndef WIN32_LEAN_AND_MEAN
          include cderr.inc
          include dde.inc
          include ddeml.inc
          include dlgs.inc
          ifndef _MAC
            include lzexpand.inc
            include mmsystem.inc
            include nb30.inc
            include rpc.inc
          endif
          include shellapi.inc
          ifndef _MAC
            include winperf.inc
            include winsock.inc
          endif
          ifndef NOCRYPT
            include wincrypt.inc
            include winefs.inc
            include winscard.inc
          endif
          ifndef NOGDI
            ifndef _MAC
              include winspool.inc
              ifdef INC_OLE1
                include ole.inc
              else
                include ole2.inc
                ;* !INC_OLE1 *
              endif
              ;* !MAC *
            endif
            include commdlg.inc
            ;* !NOGDI *
          endif
          ;* WIN32_LEAN_AND_MEAN *
        endif
        include stralign.inc
        ifdef _MAC
          ;[...]
        endif
        ifdef INC_OLE2
          include ole2.inc
          ;* INC_OLE2 *
        endif
        ifndef _MAC
          ifndef NOSERVICE
            include winsvc.inc
          endif
          if (WINVER ge 0400h)
            ifndef NOMCX
              include mcx.inc
              ;* NOMCX *
            endif
            ifndef NOIME
              include imm.inc
            endif
            ;* WINVER >= 0x0400 *
          endif
        endif
        ifndef RC_INVOKED
          if (_MSC_VER ge 800)
            if _MSC_VER ge 1200
            else
              ;* Leave 4514 disabled.  It's an unneeded warning anyway. *
            endif
          endif
          ;* RC_INVOKED *
        endif
        ;* RC_INVOKED *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    ;* _INC_WINDOWS *
  endif
  ;* _WINDOWS_ *
endif
