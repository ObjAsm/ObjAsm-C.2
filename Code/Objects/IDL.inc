; ==================================================================================================
; Title:      IDL.inc
; Author:     G. Friedrich
; Vexsion:    C.1.0
; Purpose:    ObjAsm support of Shell Item-ID-List objects.
; Note:       Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     IDL
; Purpose:    Implement ID Lists.
; Note:       OleInitialize should be called to initialize the OLE library.
; Link:       http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/
;                    shell/programmersguide/shell_adv/namespaceextension/nse_impl.asp

Object IDL, IDLID, Streamable
  VirtualMethod     Assign,           POINTER
  VirtualMethod     Clone
  RedefineMethod    Done
  VirtualMethod     GetPath,          POINTER
  VirtualMethod     GetSizeIDL
  VirtualMethod     SetPath,          POINTER
  VirtualMethod     SetSpecialFolder, DWORD

  DefineVariable    pIDList,          POINTER,      NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    IDL implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IDL.Assign
; Purpose:    Assign a Shell PIDL to this object.
; Arguments:  Arg1: Shell PIDL.
; Return:     Nothing.

Method IDL.Assign, uses xsi, pIDList:POINTER
    SetObject xsi
    .if [xsi].pIDList != NULL
      invoke ILFree, [xsi].pIDList                      ;Free the old PIDL
    .endif
    m2m [xsi].pIDList, pIDList, xdx                     ;Get the new one
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDL.Clone
; Purpose:    Make a copy of the current object.
; Arguments:  None.
; Return:     xax -> clone or NULL if failed.


Method IDL.Clone, uses xbx xdi xsi
    local dSizeIDL:DWORD

    SetObject xsi
    OCall xsi.GetSizeIDL
    mov dSizeIDL, eax
    mov xdi, $invoke(CoTaskMemAlloc, eax)
    .if xax
      New IDL
      .if xax
        mov xbx, xax
        OCall xax::IDL.Init, [xsi].pOwner
        invoke MemClone, xdi, [xsi].pIDList, dSizeIDL
        OCall xbx::IDL.Assign, xdi
      .else
        OCall ErrorReport, NULL, IDL_OUT_OF_MEMORY
        xor eax, eax
      .endif
    .else
      OCall ErrorReport, NULL, IDL_OUT_OF_MEMORY
      xor eax, eax
    .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDL.Done
; Purpose:    Finalize the IDL object.
; Arguments:  None.
; Return:     Nothing.

Method IDL.Done, uses xsi
    SetObject xsi
    .if [xsi].pIDList != NULL
      invoke ILFree, [xsi].pIDList
    .endif
    ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDL.GetPath
; Purpose:    Return an ANSI string. The caller should dispose this string using StrDispose.
; Arguments:  Arg1: -> Buffer with at least MAX_PATH bytes.
; Return:     eax = Returns TRUE if successful or FALSE if an error occurs.

Method IDL.GetPath,, pBuffer:POINTER
    SetObject xcx
    .if [xcx].pIDList != NULL
      invoke SHGetPathFromIDList, [xcx].pIDList, pBuffer
    .else
      mov xcx, pBuffer
      .if xcx != NULL
        m2z CHR ptr [xcx]
      .endif
      xor eax, eax
    .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDL.GetSizeIDL
; Purpose:    Return the size of the IDL.
; Arguments:  None.
; Return:     Nothing.

Method IDL.GetSizeIDL
    SetObject xcx
    xor eax, eax
    mov xdx, [xcx].$Obj(IDL).pIDList
    xor xcx, xcx
    .while [xdx].SHITEMID.cb != 0                       ;Terminator SHITEMID reached?
      movzx ecx, [xdx].SHITEMID.cb
      add eax, ecx
      add xdx, xcx
    .endw
    add eax, 2                                          ;Size of terminator SHITEMID
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDL.SetPath
; Purpose:    Set the PIDL that corresponds to a specified string path.
; Arguments:  Arg1: -> Path string.
; Return:     xax = Returns the pIDList if successful or NULL if an error occurs.

Method IDL.SetPath, uses xsi, pPathString:POINTER
    local pIShellFolder:POINTER, pStr:PSTRINGW, pIDList:POINTER

    SetObject xsi
    m2z pIDList
    invoke SHGetDesktopFolder, addr pIShellFolder
    invoke StrLength, pPathString
    mov pStr, $invoke(StrAllocW, eax)
    invoke StrA2StrW, xax, pPathString
    ICall pIShellFolder::IShellFolder.ParseDisplayName, 0, NULL, pStr, NULL, addr pIDList, NULL
    ICall pIShellFolder::IShellFolder.Release
    invoke StrDisposeW, pStr
    .if pIDList != NULL
      .if [xsi].pIDList != NULL
        invoke ILFree, [xsi].pIDList                    ;Free the old PIDL
      .endif
      mrm [xsi].pIDList, pIDList, xax                   ;xax -> pIDList 
    .else
      xor eax, eax
    .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDL.SetSpecialFolder
; Purpose:    Set the folder IDL related CSIDL_XXX.
; Arguments:  Arg1: CSIDL_XXX
; Return:     eax = Returns the pIDList if successful or NULL if an error occurs.

Method IDL.SetSpecialFolder, uses xsi, dCSIDL:DWORD
    local pIDList:POINTER

    SetObject xsi
    invoke SHGetSpecialFolderLocation, 0, dCSIDL, addr pIDList
    .if SUCCEEDED(eax)
      .if [xsi].pIDList != NULL
        invoke ILFree, [xsi].pIDList                    ;Free the old PIDL
      .endif
      mrm [xsi].pIDList, pIDList, xax                   ;xax -> pIDList
    .else
      xor eax, eax
    .endif
MethodEnd

endif
