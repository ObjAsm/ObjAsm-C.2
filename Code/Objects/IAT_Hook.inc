; ==================================================================================================
; Title:      IAT_Hook.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm hooking support of the "Import Address Table".
; Notes:      Version C.1.0, August 2023
;               - Initial release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  IAT_Hook
; Purpose: Implements a was to hook the Import Address Table.
; Link:    http://www.assembly-journal.com/viewarticle.php?id=157&layout=abstract

IAT_HookID  CatStr <IAT>, %TARGET_BITNESS, <HookID>

Object IAT_Hook, %IAT_HookID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, PSTRINGA, PSTRINGA, POINTER, DWORD

  DefineVariable    pEntry,         POINTER,            NULL    ; Original FuncPtr from the IAT
  DefineVariable    pImgThunkData,  PIMAGE_THUNK_DATA,  NULL    ; -> patched IAT slot
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:    IAT_Hook.Done
; Purpose:   Finalizes the IAT_Hook object and restores the previous address in the IAT.
; Arguments: None.
; Return:    Nothing.

Method IAT_Hook.Done, uses xsi
  local MBI:MEMORY_BASIC_INFORMATION, dPrvProtect:DWORD

  SetObject xsi
  mov xax, [xsi].pImgThunkData
  .if xax                                               ; Only unhook if patched
    invoke VirtualQuery, [xsi].pImgThunkData, addr MBI, sizeof MBI
    .if eax
      invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, PAGE_READWRITE, addr MBI.Protect
      .if eax
        mov xcx, [xsi].pImgThunkData
        m2m [xcx].IMAGE_THUNK_DATA.u1.Function, [xsi].pEntry, xdx
                                                        ; Write back the original Function
        invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, MBI.Protect, addr dPrvProtect
                                                        ; Restore old page protection
        jmp @@Exit
      .endif
    .endif
    OCall xsi.ErrorReport, NULL, IHK_MEMWRITEERROR      ; VirtualQuery/VirtualProtect failed
  .endif

@@Exit:
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    IAT_Hook.Init
; Purpose:   Initializes the IAT_Hook object & redirects an imported procedure to a specified addr.
; Arguments: Arg1: -> Owner.
;            Arg2: -> ANSI string module name.
;            Arg3: -> ANSI string procedure name to hook.
;            Arg4: -> New replacing procedure.
;            Arg5: Error report flag (TRUE / FALSE).
; Return:    Nothing.

Method IAT_Hook.Init, uses xbx xdi xsi, pOwner:POINTER, pModuleNameA:PSTRINGA, pProcNameA:PSTRINGA,\
                                        pNewProc:POINTER, dReportFailure:DWORD
  local MBI:MEMORY_BASIC_INFORMATION, dPrvProtect:DWORD
  local dSize:DWORD, pApiProc:POINTER, hModuleInstance:HANDLE

  SetObject xsi

  ; Resolve the real target address
  invoke GetProcAddress, $invoke(GetModuleHandleA, pModuleNameA), pProcNameA
  .if xax
    mov pApiProc, xax
    mov hModuleInstance, $invoke(GetModuleHandle, NULL) ; Base of the calling (host) module
                                                        ; RVAs below are relative to it
    invoke ImageDirectoryEntryToData, hModuleInstance, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, addr dSize
                                                        ; -> first IMAGE_IMPORT_DESCRIPTOR
    .if eax != NULL
      mov xbx, xax
      .while [xbx].IMAGE_IMPORT_DESCRIPTOR.Name_        ; Iterate import descriptors (one per DLL)
                                                        ; Name_ == 0 marks the end
        mov eax, [xbx].IMAGE_IMPORT_DESCRIPTOR.Name_
        add xax, hModuleInstance                        ; xax -> ANSI module name!
        invoke StrICompA, pModuleNameA, xax
        .if eax == 0                                    ; Matched the requested module name
                                                        ; -> scan its IAT
          mov edi, [xbx].IMAGE_IMPORT_DESCRIPTOR.FirstThunk
          add xdi, hModuleInstance
          mov xax, pApiProc
          .while [xdi].IMAGE_THUNK_DATA.u1.Function     ; Walk thunks until the NULL terminator
            .if xax == [xdi].IMAGE_THUNK_DATA.u1.Function ; Thunk's resolved Function ptr matches
                                                        ;   the proc we're hooking
              jmp @@Found
            .endif
            add xdi, sizeof IMAGE_THUNK_DATA
          .endw
        .endif
        add xbx, sizeof IMAGE_IMPORT_DESCRIPTOR
      .endw
    .endif

    .if dReportFailure                                  ; Fell through both loops without
                                                        ; finding the IAT slot
      OCall xsi.ErrorReport, NULL, IHK_PROCNOTFOUND
    .else
      mov [xsi].dErrorCode, IHK_PROCNOTFOUND
    .endif
    ExitMethod

@@Found:
    invoke VirtualQuery, xdi, addr MBI, sizeof MBI      ; xdi -> the IAT slot to patch
                                                        ; query its page for protection info
    .if eax
      invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, PAGE_READWRITE, addr MBI.Protect
                                                        ; IAT page is normally read-only
      .if eax
        mov [xsi].pImgThunkData, xdi                    ; Remember slot location for Done
                                                        ;   to restore later
        lea xax, [xdi].IMAGE_THUNK_DATA.u1.Function
        m2m [xsi].pEntry, [xax], xdx                    ; Save original Function ptr
        m2m [xax], pNewProc, xcx                        ; Install the hook (overwrite IAT slot)
        invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, MBI.Protect, addr dPrvProtect
                                                        ; Reinstate original protection
        ExitMethod
      .endif
    .endif
    OCall xsi.ErrorReport, NULL, IHK_MEMWRITEERROR      ; Couldn't make the IAT page writable
  .else                                                 ; GetProcAddress failed
    .if dReportFailure
      OCall xsi.ErrorReport, NULL, IHK_PROCNOTFOUND
    .else
      mov [xsi].dErrorCode, IHK_PROCNOTFOUND
    .endif
  .endif

MethodEnd

endif
