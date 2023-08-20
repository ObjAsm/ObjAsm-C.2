; ==================================================================================================
; Title:      IAT_Hook.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm hooking support of the "Import Address Table".
; Notes:      Version C.1.0, August 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IAT_Hook
; Purpose: Implements a was to hook the Import Address Table.
; Link:    http://www.assembly-journal.com/viewarticle.php?id=157&layout=abstract

IAT_HookID  CatStr <IAT>, %TARGET_BITNESS, <HookID>

Object IAT_Hook, %IAT_HookID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, POINTER, POINTER, POINTER, DWORD

  DefineVariable    pEntry,         POINTER,      NULL
  DefineVariable    pImgThunkData,  POINTER,      NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IAT_Hook.Done
; Purpose:   Finalizes the IAT_Hook object and restores the previous address in the IAT.
; Arguments: None.
; Return:    Nothing.

Method IAT_Hook.Done, uses xsi
  local MBI:MEMORY_BASIC_INFORMATION, dPrvProtect:DWORD

  SetObject xsi
  mov xax, [xsi].pImgThunkData
  .if xax
    invoke VirtualQuery, [xsi].pImgThunkData, addr MBI, sizeof MBI
    .if eax
      invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, PAGE_READWRITE, addr MBI.Protect
      .if eax
        mov xcx, [xsi].pImgThunkData
        m2m [xcx].IMAGE_THUNK_DATA.u1.Function, [xsi].pEntry, xdx
        invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, MBI.Protect, addr dPrvProtect
        jmp @@Exit
      .endif
    .endif
    OCall xsi.ErrorReport, NULL, IHK_MEMWRITEERROR
  .endif

@@Exit:
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IAT_Hook.Init
; Purpose:   Initializes the IAT_Hook object & redirects an imported procedure to a specified addr.
; Arguments: Arg1: -> Owner.
;            Arg2: -> Module name.
;            Arg3: -> Procedure name to hook.
;            Arg4: -> New replacing procedure.
;            Arg5: Error report flag (TRUE / FALSE).
; Return:    Nothing.

Method IAT_Hook.Init, uses xbx xdi xsi, pOwner:POINTER, pModuleName:POINTER, pProcName:POINTER, \
                                        pNewProc:POINTER, dReportFailure:DWORD
  local MBI:MEMORY_BASIC_INFORMATION, dPrvProtect:DWORD
  local dSize:DWORD, pApiProc:POINTER, hModuleInstance:HANDLE

  SetObject xsi
  
  invoke GetProcAddress, $invoke(GetModuleHandle, pModuleName), pProcName
  .if xax
    mov pApiProc, xax
    mov hModuleInstance, $invoke(GetModuleHandle, NULL)
    lea eax, dSize
    invoke ImageDirectoryEntryToData, hModuleInstance, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, xax
    mov xbx, xax

    .while [xbx].IMAGE_IMPORT_DESCRIPTOR.Name_
      mov eax, [xbx].IMAGE_IMPORT_DESCRIPTOR.Name_
      add xax, hModuleInstance
      invoke StrIComp, pModuleName, xax
      .if eax == 0
        mov edi, [xbx].IMAGE_IMPORT_DESCRIPTOR.FirstThunk
        add xdi, hModuleInstance
        mov xax, pApiProc
        .while [xdi].IMAGE_THUNK_DATA.u1.Function
          .if xax == [xdi].IMAGE_THUNK_DATA.u1.Function
            jmp @@Found
          .endif
          add xdi, sizeof IMAGE_THUNK_DATA
        .endw
      .endif
      add xbx, sizeof IMAGE_IMPORT_DESCRIPTOR
    .endw

    .if dReportFailure
      OCall xsi.ErrorReport, NULL, IHK_PROCNOTFOUND
    .else
      mov [xsi].dErrorCode, IHK_PROCNOTFOUND
    .endif
    ExitMethod

@@Found:
    invoke VirtualQuery, xdi, addr MBI, sizeof MBI
    .if eax
      invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, PAGE_READWRITE, addr MBI.Protect
      .if eax
        mov [xsi].pImgThunkData, xdi
        lea xax, [xdi].IMAGE_THUNK_DATA.u1.Function
        m2m [xsi].pEntry, [xax], xdx
        m2m [xax], pNewProc, xcx
        invoke VirtualProtect, MBI.BaseAddress, MBI.RegionSize, MBI.Protect, addr dPrvProtect
        ExitMethod
      .endif
    .endif
    OCall xsi.ErrorReport, NULL, IHK_MEMWRITEERROR
  .else
    .if dReportFailure
      OCall xsi.ErrorReport, NULL, IHK_PROCNOTFOUND
    .else
      mov [xsi].dErrorCode, IHK_PROCNOTFOUND
    .endif
  .endif

MethodEnd

endif