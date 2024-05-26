; ==================================================================================================
; Title:      RelocCode.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Include to simplify the development of applications that don't have an import section.
; Notes:      First written by Bryant Keller, 2005; modified by EvilHomer, 2005
;             Version C.1.0, November 2023
;               - First release.
;
;             The code relocation is based on the calculation of addresses on the fly.
;             For this purpose, the generated code calculates the address of any object as:
;
;                   OBJECT ADDRESS = CURRENT IP ADDRESS - STATIC OFFSET
;
;             To obtain the CURRENT IP ADDRESS, we use the command sequence call/pop.
;             The STATIC OFFSET is computed by the assembler as ($ - Was - 1). See macro "Delta".
;
; ==================================================================================================


;Disclosed PEB_LDR_DATA structure from
;https://www.geoffchappell.com/studies/windows/km/ntoskrnl/inc/api/ntpsapi_x/peb_ldr_data.htm
_PEB_LDR_DATA_ struct 4
  Length_ ULONG ?
  Initialized BOOLEAN ?
  SsHandle PVOID ?
  InLoadOrderModuleList LIST_ENTRY {}
  InMemoryOrderModuleList LIST_ENTRY {}
  InInitializationOrderModuleList LIST_ENTRY {}
  EntryInProgress PVOID ?
  ShutdownInProgress BOOLEAN ?
  ShutdownThreadId HANDLE ?
_PEB_LDR_DATA_ ends

;Disclosed LDR_DATA_TABLE_ENTRY structure from
;https://www.geoffchappell.com/studies/windows/km/ntoskrnl/inc/api/ntldr/ldr_data_table_entry.htm
_LDR_DATA_TABLE_ENTRY_ struct 4
  InLoadOrderLinks LIST_ENTRY {}
  InMemoryOrderLinks LIST_ENTRY {}
  InInitializationOrderLinks LIST_ENTRY {}
  union Links
    InInitializationOrderLinks LIST_ENTRY {}
    InProgressLinks LIST_ENTRY {}
  ends
  DllBase PVOID ?
  EntryPoint PVOID ?
  SizeOfImage ULONG ?
;  FullDllName UNICODE_STRING {}
;  BaseDllName UNICODE_STRING {}
  Flags ULONG ?
  union Flags_
    FlagGroup UCHAR 4 dup(?)
    Flags ULONG ?
  ends
  LoadCount USHORT ?
  ObsoleteLoadCount USHORT ?
  TlsIndex USHORT ?
  union Hash
    HashLinks LIST_ENTRY {}
    struct
      SectionPointer PVOID ?
      CheckSum ULONG ?
    ends
  ends
  HashLinks LIST_ENTRY {}
_LDR_DATA_TABLE_ENTRY_ ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GetDllBases
; Purpose:    Get NTDLL.dll and Kernel32.dll base addresses in memory and store them.
; Arguments:  Arg1: Storage variable name for the base address of NTDLL.dll.
;             Arg2: Storage variable name for the base address of Kernel32.dll.
; Return:     Nothing.
; Note:       Starting from the TEB, we gain access to the PEB and from there to the first two
;             initialised DLL images. On Windows NT systems, these are always NTDLL.dll and
;             Kernel32.dll in the same order.
;             The results are stored locally using the "SetDelta" macro.

GetDllBases macro pBaseNTDLL:req, pBaseK32:req
if TARGET_BITNESS eq 32
  assume fs:nothing                                     ;;fs -> TEB
  mov xax, fs:TEB.ProcessEnvironmentBlock               ;;xax -> PEB
else
  assume gs:nothing                                     ;;gs -> TEB
  mov xax, gs:TEB.ProcessEnvironmentBlock               ;;xax -> PEB
endif
  mov xdx, [xax].PEB.Ldr                                ;;xax -> PEB_LDR_DATA
  mov xax, [xdx]._PEB_LDR_DATA_.InInitializationOrderModuleList.LIST_ENTRY.Flink
  mov xcx, [xax - offset _LDR_DATA_TABLE_ENTRY_.InInitializationOrderLinks].LDR_DATA_TABLE_ENTRY.DllBase
  ;xcx -> NTDLL ImageBase (always 1st Entry)
  SetDelta pBaseNTDLL, xcx, xdx                         ;;xax is preserved
  mov xdx, [xax].LIST_ENTRY.Flink                       ;;xdx -> Next Entry
  mov xcx, [xdx - offset _LDR_DATA_TABLE_ENTRY_.InInitializationOrderLinks].LDR_DATA_TABLE_ENTRY.DllBase
  ;xcx -> Kernel32 ImageBase (always 2nd Entry)
  SetDelta pBaseK32, xcx, xdx                           ;;xax is preserved
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      USE_API
; Purpose:    Define storage for the API information in the current segment.
; Arguments:  Arg1: API function name.
; Return:     Nothing.

USE_API macro FuncName:req
  $$Pos InStr 1, FuncName, <@>                          
  if $$Pos eq 0                                         ;;C call?
    $$Pos = @SizeStr(%FuncName) + 1
  endif

  @CatStr(@SubStr(%FuncName, 7, $$Pos - 7), <_StrA CHRA !">, @SubStr(%FuncName, 7, $$Pos - 7), <!", 0>)
  @CatStr(@SubStr(%FuncName, 7, $$Pos - 7), <_Addr>)   POINTER   NULL
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LoadApi
; Purpose:    If API address was not previously loaded, compute its address in the DLL image.
; Arguments:  Arg1: Library name.
;             Arg2: API function name.
; Return:     Nothing.
; Note:       xbx is TRASHED!

LoadApi macro LibName:req, FuncName:req
  $$Pos InStr 1, FuncName, <@>                          
  if $$Pos eq 0                                         ;;C call?
    $$Pos = @SizeStr(%FuncName) + 1
  endif

  Delta xbx, @CatStr(@SubStr(%FuncName, 7, $$Pos - 7), <_Addr>)
  .if POINTER ptr [xbx] == 0
    Delta xdx, @CatStr(@SubStr(%FuncName, 7, $$Pos - 7), <_StrA>)
    Delta xcx, LibName
    invoke GetProcAddr, POINTER ptr [xcx], xdx          ;;Use our own version
    mov [xbx], xax
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Delta
; Purpose:    Compute relative offset to a given label (What).
; Arguments:  Arg1: Register to store the result.
;             Arg2: Reference.
; Return:     Nothing.

Delta macro IntoReg:req, What:req
  call $ + 5                                            ;;Push eip and jump to the next instruction
  pop IntoReg                                           ;;Get the call return address
  sub IntoReg, $ - What - 1                             ;;Subtract relative offset to the object
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Delta
; Purpose:    Compute relative offset to a given label (What).
; Arguments:  Arg1: Register to store the result.
;             Arg2: Reference.
; Return:     Register specified as Arg1.
; Note:       Variant of "Delta" macro, suitable for use within an ApiRelCall expression
;             Loads given register with relative offset of given label
;             e.g. ApiRelCall MessageBox, 0, $Delta(xax, szStr1), $Delta(xbx, szStr2), MB_OK

$Delta macro IntoReg:req, What:req
  Delta IntoReg, What
  exitm <IntoReg>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SetDelta
; Purpose:    Uses the "Delta" macro to store a register to a code or data label, and is totally
;             relocatable.
; Arguments:  Arg1: Label.
;             Arg2: Value.
;             Arg3: Optional auxiliary register that is TRASHED.
; Return:     Nothing.

SetDelta macro Where:req, What:req, AuxReg
  ifb <AuxReg>
    push xdx
    mov [$Delta(xdx, Where)], What
    pop xdx
  else
    mov [$Delta(AuxReg, Where)], What
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ApiRelCall
; Purpose:    This macro uses the "Delta" macro to perform relative calls on API functions via
;             function-pointers, which were previously stored at a given label using the
;             "LoadApi" macro.
; Arguments:  Arg1: New API name.
;             Arg2-n: API arguments.
; Return:     API return value.

ApiRelCall macro FuncName:req, Args:vararg
  $$Attr = opattr(FuncName)

  $$Pos InStr 1, FuncName, <@>                          
  if $$Pos eq 0                                         ;;C call?
    $$Pos = @SizeStr(%FuncName) + 1
  endif

  ;;Use procedure type defined by "@DefProto" macro and remove the import prefix (7 chars)
  ifb <Args>
    %invoke @CatStr(<TYPE_>, @SubStr(%FuncName, 7, $$Pos - 7), < ptr [0]>) 
  else
    %invoke @CatStr(<TYPE_>, @SubStr(%FuncName, 7, $$Pos - 7), < ptr [0], Args>)
  endif
  if ($$Attr and OAT_LANGUAGE) eq OAT_LANG_C
    org $ - 10                                          ;;Discard call inst. and stack correction
  else
    org $ - 7                                           ;;Discard call instruction [FF142500000000]
  endif

  Delta xax, @CatStr(@SubStr(%FuncName, 7, $$Pos - 7), <_Addr>)
  call POINTER ptr [xax]

  if ($$Attr and OAT_LANGUAGE) eq OAT_LANG_C            ;;Exist only in 32 bit
    ifnb <Args>
      $$Count = 0
      for $$Arg, <Args>
        $$Count = $$Count + 1
      endm
      add esp, $$Count*sizeof(DWORD)
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetProcAddr
; Purpose:    GetProcAddress replacement.
;             Parses the Export Address Table of a given DLL for a given API name.
; Arguments:  Arg1: -> DLL Image Base Address.
;             Arg2: Original DLL API name.
; Return:     xax = API address or NULL if failed.
; Links:      https://learn.microsoft.com/en-us/windows/win32/debug/imagehlp-structures
;             https://upload.wikimedia.org/wikipedia/commons/1/1b/Portable_Executable_32_bit_Structure_in_SVG_fixed.svg

.code
align ALIGN_CODE
GetProcAddr proc uses xbx xdi xsi, pLib:POINTER, pApiName:PSTRINGA
  mov xsi, pLib                                         ;xsi -> Image Base Address
  cmp word ptr [xsi], 'ZM'                              ;Check the DosHeader signature (MZ)
  jnz @@Error

  mov eax, [xsi + 03Ch]                                 ;DWORD offset
  lea xbx, [xsi + xax]                                  ;xbx -> COFF-Header = IMAGE_NT_HEADERS(32/64)
  cmp [xbx].IMAGE_NT_HEADERS.Signature, 'EP'            ;Check the PE signature
  jnz @@Error

  ;Obtain the length of the API name
  mov xdi, pApiName
  mov ecx, -1
  xor eax, eax
  repnz scasb
  mov xcx, xdi
  sub xcx, pApiName                                     ;ecx = strlen(pApiName)

  mov ebx, [xbx].IMAGE_NT_HEADERS.OptionalHeader.DataDirectory.VirtualAddress
  add xbx, xsi                                          ;xdx -> Export Table

  mov edx, [xbx].IMAGE_EXPORT_DIRECTORY.AddressOfNames  ;ebx = RVA to API names
  add xdx, xsi                                          ;xbx = AddressOfNames
  xor eax, eax                                          ;eax = AddressOfNames index

  ;Search the API name
  .repeat
    mov edi, [xdx]
    add xdi, pLib                                       ;xdi -> Exported API names
    mov xsi, pApiName
    push xcx
    repz cmpsb                                          ;Save the API string length
    pop xcx
    .break .if ZERO?
    add xdx, sizeof(DWORD)                              ;Next offset
    inc eax                                             ;Increment index
  .until eax == [xbx].IMAGE_EXPORT_DIRECTORY.NumberOfNames

  cmp eax, [xbx].IMAGE_EXPORT_DIRECTORY.NumberOfNames   ;Did we find string?
  je @@Error

  mov xsi, pLib
  ;Find the corresponding ordinal
  mov edi, [xbx].IMAGE_EXPORT_DIRECTORY.AddressOfNameOrdinals ;RVA
  add xdi, xsi
  movzx ecx, WORD ptr [xdi + sizeof(WORD)*xax]          ;ecx = API ordinal

  ;Get the address of the API
  mov edx, [xbx].IMAGE_EXPORT_DIRECTORY.AddressOfFunctions    ;RVA
  add xdx, xsi
  mov eax, [xdx + sizeof(DWORD)*xcx]                    ;RVA = DWORD
  add xax, xsi                                          ;xax -> API
  jmp @F

@@Error:
  xor eax, eax                                          ;Return NULL on error
@@:
  ret
GetProcAddr endp
