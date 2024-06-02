; ==================================================================================================
; Title:      WinAsm.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    This file is designed for use with the translated header files of the h2inc+ project.
;             It must be included before the Windows.inc file.
;             This include file is *NOT* automatically generated.
; Notes:      Check "h2inc+_Manual_Changes.txt" 


ifndef _INC_WINASM
  _INC_WINASM equ <>

  option nokeyword:<this>
  option nokeyword:<name>

  ifdef __UASM__
  elseifdef __JWASM__
  elseifdef __ASMC__
  else
    SQWORD typedef QWORD    ;Ugly, but MASM 6.15 does not know about SQWORD
  endif

  void                      equ   <>
  TRUE                      equ   1                     ;Compatible with Windows_XX.inc
  FALSE                     equ   0
  NULL                      equ   0

  _WIN32_WINNT_NT4          equ   0400h                 ;Windows NT 4.0
  _WIN32_WINNT_WIN2K        equ   0500h                 ;Windows 2000
  _WIN32_WINNT_WINXP        equ   0501h                 ;Windows Server 2003, Windows XP
  _WIN32_WINNT_WS03         equ   0502h                 ;Windows Server 2003 with SP1, Windows XP with SP2
  _WIN32_WINNT_WIN6         equ   0600h                 ;Windows Vista
  _WIN32_WINNT_VISTA        equ   0600h                 ;Windows Vista
  _WIN32_WINNT_WS08         equ   0600h                 ;Windows Server 2008
  _WIN32_WINNT_LONGHORN     equ   0600h                 ;Windows Vista
  _WIN32_WINNT_WIN7         equ   0601h                 ;Windows 7
  _WIN32_WINNT_WIN8         equ   0602h                 ;Windows 8
  _WIN32_WINNT_WINBLUE      equ   0603h                 ;Windows 8.1
  _WIN32_WINNT_WINTHRESHOLD equ   0A00h                 ;Windows 10
  _WIN32_WINNT_WIN10        equ   0A00h                 ;Windows 10
  _WIN32_WINNT_WIN10_19H2   equ   0A00h

  _WIN32_IE_IE100           equ   0A00h                 ;Internet Explorer 10.0
  _WIN32_IE_IE90            equ   0900h                 ;Internet Explorer 9.0
  _WIN32_IE_IE80            equ   0800h                 ;Internet Explorer 8.0
  _WIN32_IE_IE70            equ   0700h                 ;Internet Explorer 7.0
  _WIN32_IE_IE60SP2         equ   0603h                 ;Internet Explorer 6.0 SP2
  _WIN32_IE_IE60SP1         equ   0601h                 ;Internet Explorer 6.0 SP1
  _WIN32_IE_IE60            equ   0600h                 ;Internet Explorer 6.0
  _WIN32_IE_IE55            equ   0550h                 ;Internet Explorer 5.5
  _WIN32_IE_IE501           equ   0501h                 ;Internet Explorer 5.01
  _WIN32_IE_IE50            equ   0500h                 ;Internet Explorer 5.0, 5.0a, 5.0b

  ;WIN32_LEAN_AND_MEAN       equ   1
  WINVER                    equ   _WIN32_WINNT_WIN10
  _WIN32_WINNT              equ   _WIN32_WINNT_WIN10
  _WIN32_IE                 equ   _WIN32_IE_IE100
  _M_HYBRID                 equ   0
  _WIN32_FUSION             equ   100h                  ;This causes activation context structs and APIs to be included.
  _INTEGRAL_MAX_BITS        equ   64                    ;Defined as the integer literal value 64, the maximum size (in bits) for a non-vector integral type. This macro is always defined.
  _WINSOCK_DEPRECATED_NO_WARNINGS equ <>

  ISOLATION_AWARE_ENABLED   equ   0
  OEMRESOURCE               equ   1                     ;Various resource system IDC_... , used by CommCtrl.inc

  NTDDI_WIN2K               equ   05000000h
  NTDDI_WIN2KSP1            equ   05000100h
  NTDDI_WIN2KSP2            equ   05000200h
  NTDDI_WIN2KSP3            equ   05000300h
  NTDDI_WIN2KSP4            equ   05000400h

  NTDDI_WINXP               equ   05010000h
  NTDDI_WINXPSP1            equ   05010100h
  NTDDI_WINXPSP2            equ   05010200h
  NTDDI_WINXPSP3            equ   05010300h
  NTDDI_WINXPSP4            equ   05010400h

  NTDDI_WS03                equ   05020000h
  NTDDI_WS03SP1             equ   05020100h
  NTDDI_WS03SP2             equ   05020200h
  NTDDI_WS03SP3             equ   05020300h
  NTDDI_WS03SP4             equ   05020400h

  NTDDI_WIN6                equ   06000000h
  NTDDI_WIN6SP1             equ   06000100h
  NTDDI_WIN6SP2             equ   06000200h
  NTDDI_WIN6SP3             equ   06000300h
  NTDDI_WIN6SP4             equ   06000400h

  NTDDI_VISTA               equ   DDI_WIN6
  NTDDI_VISTASP1            equ   DDI_WIN6SP1
  NTDDI_VISTASP2            equ   DDI_WIN6SP2
  NTDDI_VISTASP3            equ   DDI_WIN6SP3
  NTDDI_VISTASP4            equ   DDI_WIN6SP4

  NTDDI_WIN7                equ   06010000h
  NTDDI_WIN7SP1             equ   06010100h

  NTDDI_WS08                equ   DDI_WIN6SP1
  NTDDI_WS08SP2             equ   DDI_WIN6SP2
  NTDDI_WS08SP3             equ   DDI_WIN6SP3
  NTDDI_WS08SP4             equ   DDI_WIN6SP4

  NTDDI_LONGHORN            equ   NTDDI_VISTA
  NTDDI_WIN8                equ   06020000h
  NTDDI_WINBLUE             equ   06030000h
  NTDDI_WINTHRESHOLD        equ   0A000000h             ;ABRACADABRA_THRESHOLD
  NTDDI_WIN10               equ   0A000000h             ;ABRACADABRA_THRESHOLD
  NTDDI_WIN10_TH2           equ   0A000001h             ;ABRACADABRA_WIN10_TH2
  NTDDI_WIN10_RS1           equ   0A000002h             ;ABRACADABRA_WIN10_RS1
  NTDDI_WIN10_RS2           equ   0A000003h             ;ABRACADABRA_WIN10_RS2
  NTDDI_WIN10_RS3           equ   0A000004h             ;ABRACADABRA_WIN10_RS3
  NTDDI_WIN10_RS4           equ   0A000005h             ;ABRACADABRA_WIN10_RS4
  NTDDI_WIN10_RS5           equ   0A000006h             ;ABRACADABRA_WIN10_RS5
  NTDDI_WIN10_19H1          equ   0A000007h             ;ABRACADABRA_WIN10_19H1
  NTDDI_WIN10_VB            equ   0A000008h
  NTDDI_WIN10_MN            equ   0A000009h
  NTDDI_WIN10_FE            equ   0A00000Ah
  NTDDI_WIN10_CO            equ   0A00000Bh
  NTDDI_WIN10_NI            equ   0A00000Ch
  NTDDI_WIN10_CU            equ   0A00000Dh
  NTDDI_WIN11_ZN            equ   0A00000Eh
  NTDDI_WIN11_GA            equ   0A00000Fh
  NTDDI_WIN11_NI            equ   NTDDI_WIN10_NI
  NTDDI_WIN11_SV3           equ   0A0000010h            ;????

;  WDK_NTDDI_VERSION         equ   NTDDI_WIN10_19H1      ;ABRACADABRA_WIN10_19H1

  _NT_TARGET_VERSION_WIN10_RS4 equ <_WIN32_WINNT_WIN10> ;Compared with _WIN32_WINNT, missing

  _WIN32_WINNT_WIN10_TH1    equ   0A000000h             ;Threshold 1, Windows 10 version 1507
  _WIN32_WINNT_WIN10_TH2    equ   0A000001h             ;Threshold 2, Windows 10 version 1511 "November Update"
  _WIN32_WINNT_WIN10_RS1    equ   0A000002h             ;Redstone 1,  Windows 10 version 1607 "Anniversary Update"
  _WIN32_WINNT_WIN10_RS2    equ   0A000003h             ;Redstone 2,  Windows 10 version 1703 "Creators Update"
  _WIN32_WINNT_WIN10_RS3    equ   0A000004h             ;Redstone 3,  Windows 10 version 1709 "Fall Creators Update"
  _WIN32_WINNT_WIN10_RS4    equ   0A000005h             ;Redstone 4,  Windows 10 version 1803 "April 2018 Update"
  _WIN32_WINNT_WIN10_RS5    equ   0A000006h             ;Redstone 5,  Windows 10 version 1809 "October 2018 Update"
  _WIN32_WINNT_WIN10_19H1   equ   0A000007h             ;ABRACADABRA_WIN10_19H1
  _WIN32_WINNT_WIN10_VB     equ   0A000008h
  _WIN32_WINNT_WIN10_MN     equ   0A000009h
  _WIN32_WINNT_WIN10_FE     equ   0A00000Ah
  _WIN32_WINNT_WIN10_CO     equ   0A00000Bh
  _WIN32_WINNT_WIN10_NI     equ   0A00000Ch
  _WIN32_WINNT_WIN10_CU     equ   0A00000Dh
  _WIN32_WINNT_WIN11_ZN     equ   0A00000Eh
  _WIN32_WINNT_WIN11_GA     equ   0A00000Fh


  _WIN32_NTDDI_WIN10_19H1   equ   0A000007h             ;ABRACADABRA_WIN10_19H1
  _WIN32_NTDDI_WIN10_VB     equ   0A000008h
  _WIN32_NTDDI_WIN10_MN     equ   0A000009h
  _WIN32_NTDDI_WIN10_FE     equ   0A00000Ah
  _WIN32_NTDDI_WIN10_CO     equ   0A00000Bh
  _WIN32_NTDDI_WIN10_NI     equ   0A00000Ch
  _WIN32_NTDDI_WIN10_CU     equ   0A00000Dh
  _WIN32_NTDDI_WIN11_ZN     equ   0A00000Eh
  _WIN32_NTDDI_WIN11_GA     equ   0A00000Fh

  NTDDI_WIN10_RS1           equ   _WIN32_WINNT_WIN10_RS1
  NTDDI_WIN10_RS2           equ   _WIN32_WINNT_WIN10_RS2
  NTDDI_WIN10_RS3           equ   _WIN32_WINNT_WIN10_RS3
  NTDDI_WIN10_RS4           equ   _WIN32_WINNT_WIN10_RS4
  NTDDI_WIN10_RS5           equ   _WIN32_WINNT_WIN10_RS5
;  NTDDI_VERSION             equ   NTDDI_WIN10_RS5


  _MSC_VER                  equ   1900                  ;Major & minor number of C compiler's version number
  _MSC_FULL_VER             equ   190024210
  __STDC__                  equ   0                     ;1 only when compiled as std C, otherwise 0.
  _FORCENAMELESSUNION       equ   -1                    ;required for VARIANT definition

  WINAPI_PARTITION_PHONE_RESTRICTED   equ   -1          ;Missing
  
  _USE_ATTRIBUTES_FOR_SAL   equ   FALSE
  _MSVC_LANG                equ   202401

  ;Some basic type definitions
  POINTER               typedef     ptr
  HANDLE                typedef     ptr
  wchar_t               typedef     WORD


  ;Required for some forward definitions in WinNT.inc
  _TP_CALLBACK_INSTANCE typedef     POINTER
  _TP_POOL              typedef     DWORD
  _TP_WORK              typedef     DWORD
  _TP_CLEANUP_GROUP     typedef     DWORD
  _TP_TIMER             typedef     DWORD
  _TP_WAIT              typedef     DWORD
  _TP_IO                typedef     DWORD


  ifndef Defined
    Defined macro x
      ifdef x
        exitm <-1>                                      ;-1 to be able to use the 'NOT' operator.
      else                                              ;Not(-1) = 0 (FALSE)
        exitm <0>
      endif
    endm
  endif

  ifndef @Align
    @align equ <>
  endif

  ifndef _WIN64                                         ;"type(near)" returns in 16-bit 0FF02h,
    if type(near) eq 0ff08h   ;64-bit enabled?          ;in 32-bit 0FF04h and in 64-bit 0FF08h.
      _WIN64 equ 1
    endif
  endif

  ifdef _WIN64
    XWORD               typedef   QWORD
    SXWORD              typedef   SQWORD
    size_t              typedef   QWORD
    __w64               typedef   QWORD
    _M_X64              equ   1
    _M_AMD64            equ   1
    _AMD64_             equ   1
    _WIN32              equ   1
  else
    XWORD               typedef   DWORD
    SXWORD              typedef   SDWORD
    size_t              typedef   DWORD
    __w64               typedef   DWORD
    _M_IX86             equ   1
    _X86_               equ   1
    _WIN32              equ   1
  endif

  if not Defined(_WIN64) and not Defined(_M_IX86)
    _M_IX86 equ 300
  endif

  ifndef _WIN32_WINNT
    ifndef WINVER
      _WIN32_WINNT    equ 400h        ;Windows NT 4.0 - minimum
    else
      _WIN32_WINNT    equ WINVER
    endif
  endif

  ifndef _WIN32_WINDOWS
    ifndef WINVER
      _WIN32_WINDOWS  equ 400h        ;Windows NT 4.0 - minimum
    else
      _WIN32_WINDOWS  equ WINVER
    endif
  endif


  ;Macro to define a prototype, either using an indirect call or an IAT thunk
  ;Link: https://msdn.microsoft.com/en-us/library/56h2zst2.aspx
  ;      https://msdn.microsoft.com/en-us/library/zxk0tw93.aspx
  ;      https://msdn.microsoft.com/en-us/library/zkwh89ks.aspx
  ;Note: in Windows x64, the only calling Convention is 'fastcall' or its extension 'vectorcall',
  ;      whereas in x86, we can find 'c', 'pascal', 'stdcall', 'thiscall', etc.

  ifdef _WIN64
    WIN_STD_CALL_CONV equ <fastcall>
    @DefProto macro ApiQual, ProcName, CallConv, NameSuffix, Params, DecorSuffix
      ifdif <CallConv>, <vectorcall>
        ??CallConv equ <fastcall>
      else
        ??CallConv equ <&CallConv>
      endif

      %ifidn <ApiQual>, <DllImport>                     ;;Call [IAT], a bit faster
        TYPE_&ProcName typedef proto ??CallConv Params
        externdef __imp_&ProcName: ptr TYPE_&ProcName
        ProcName&NameSuffix equ <__imp_&ProcName>
      else
        ProcName&NameSuffix proto ??CallConv Params     ;;Call thunk (jmp [IAT])
      endif
    endm

  else
    WIN_STD_CALL_CONV equ <stdcall>
    @DefProto macro ApiQual, ProcName, CallConv, NameSuffix, Params, DecorSuffix

      %ifidn <ApiQual>, <DllImport>                     ;;Call [IAT], a bit faster
        TYPE_&ProcName typedef proto CallConv Params
        ifnb <DecorSuffix>
          externdef CallConv _imp__&ProcName&@&DecorSuffix: ptr TYPE_&ProcName
          ProcName&NameSuffix equ <_imp__&ProcName&@&DecorSuffix>
        else
          externdef c _imp__&ProcName: ptr TYPE_&ProcName
          ProcName&NameSuffix equ <_imp__&ProcName>
        endif
      else
        ProcName&NameSuffix proto CallConv Params       ;;Call thunk (jmp [IAT])
      endif
    endm
  endif


  ;ifdef COBJMACROS
  ; ——————————————————————————————————————————————————————————————————————————————————————————————————
  ; vf() is used to call a virtual method.
  ; it is intended to be used internally. MIDL will create C helper
  ; macros to access virtual methods with the following syntax:
  ;   #define Interface_Method() (This)->lpVtbl->Method(This,...)
  ; h2incX will translate this to:
  ;   Interface_Method macro This, ...
  ;   exitm <vf(This, Interface, Method), ...>
  ;   endm
  ; ——————————————————————————————————————————————————————————————————————————————————————————————————
  ; edx/r11 is used, so it cannot be used as a parameter!
  ; and global textequate ??ThisReg is used
  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  vf macro @This:req, Interface, Func:req
    ifdef _WIN64
      ifidni <@This>, <r11>
        ??ThisReg equ <r10>
      else
        ??ThisReg equ <r11>
      endif
    else
      ifidni <@This>, <edx>
        ??ThisReg equ <ecx>
      else
        ??ThisReg equ <edx>
      endif
    endif
    mov ??ThisReg, @This
    mov ??ThisReg, [??ThisReg].Interface.lpVtbl
    exitm <[??ThisReg].&Interface&Vtbl.&Func&, @This>
  endm


  ; ——————————————————————————————————————————————————————————————————————————————————————————————————
  ; L() macro function to define a WIDE string
  ; examples: L("abc"), L("abc",10,"def")
  ; terminating 0 is *not* appended!
  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  L macro Params:vararg
    local wStr

    wStr textequ <>
    for Param, <Params>
      ifidn <">, @SubStr(Param, 1, 1)
%       forc Char$, <@SubStr(Param, 2, @SizeStr(Param) - 2)>
          ifnb wStr
            wStr CatStr wStr, <,>
          endif
          wStr CatStr wStr, <'&Char$'>
        endm
      else
        ifnb wStr
          wStr CatStr wStr, <,>
        endif
        wStr CatStr wStr, <Param>
      endif
    endm
    exitm <wStr>
  endm


  ; ——————————————————————————————————————————————————————————————————————————————————————————————————
  ; SNDMSG is mainly used in COMMCTRL.INC and WINDOWSX.INC
  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  SNDMSG macro hWnd, Message, wParam, lParam
    exitm <SendMessage, hWnd, Message, wParam, lParam>
  endm


  ; ——————————————————————————————————————————————————————————————————————————————————————————————————
  ; COM helper macros
  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  ; ——————————————————————————————————————————————————————————————————————————————————————————————————
  ; Macro:     STD_METHOD
  ; Purpose:   Define a method in the interface definition.
  ; Arguments: Arg1: Method name.
  ;            Arg2: Method arguments (with or without colons & pSelf (or This) is passed explicitly).

  STD_METHOD macro MtdName:req, Args:vararg
    @CatStr(%??Interface, <_>, MtdName, <_Args>) textequ <&Args>
    if TARGET_BITNESS eq 32
      %@CatStr(%??Interface, <_>, MtdName) proto stdcall, Args      ;;First argument is pSelf
      %@CatStr(<TYPE_>, %??Interface, <_>, MtdName) typedef proto stdcall, Args
    else
      %@CatStr(%??Interface, <_>, MtdName) proto fastcall, Args     ;;First argument is pSelf
      %@CatStr(<TYPE_>, %??Interface, <_>, MtdName) typedef proto fastcall, Args
    endif
    @CatStr(<_>, MtdName) POINTER ?                     ;;Make an entry in the structure
  endm

  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  DECLARE_INTERFACE_ macro Params:vararg
  endm
  END_DECLARE_INTERFACE_ macro
  endm

  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  DECLARE_INTERFACE_IID_ macro IName:req, AName:=<>, sIID
    ifnb <sIID>
      sIID_&IName textequ <sIID>                        ;;Create symbolic IID
    endif

    ??InterfaceName equ <IName>
    ??Interface CatStr <IName>, <Vtbl>

    ??Interface struct
      AName&Vtbl {}                                     ;;Create ancerstor methods
  endm

  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  DECLARE_INTERFACE_IID__END macro
    ;;Terminate structure definition
    ??Interface ends
  endm

  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  DECLARE_INTERFACE macro Params:vararg
  endm
  DECLARE_INTERFACE_END macro
  endm

  ; ——————————————————————————————————————————————————————————————————————————————————————————————————

  DECLARE_INTERFACE_IID macro Params:vararg
  endm
  DECLARE_INTERFACE_IID_END macro
  endm

endif
