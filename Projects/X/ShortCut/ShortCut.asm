; ==================================================================================================
; Title:      ShortCut.asm
; Author:     G. Friedrich & Jaymeson Trudgen (NaN)
; Version:    1.0.0
; Purpose:    ObjAsm Shortcut Application.
;             (Source is a direct transcription from Ernest Murphy's origional COM examples)
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects


% include &COMPath&COM.inc                                  ;COM basic support
% include &IncPath&Windows\shobjidl_core.inc
% include &IncPath&Windows\sGUID.inc

% includelib &LibPath&Windows\Ole32.lib

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IDispatch, %sIID_IDispatch
DefGUID IID_IPersistFile, %sIID_IPersistFile
DefGUID CLSID_ShellLink, <00021401-0000-0000-C000-000000000046>
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DefGUID IID_IShellLink, <000214EE-0000-0000-C000-000000000046>    ;%sIID_IShellLinkA
  IShellLink equ IShellLinkA
else
  DefGUID IID_IShellLink, <000214F9-0000-0000-C000-000000000046>    ;%sIID_IShellLinkW
  IShellLink equ IShellLinkW
endif

CoCreateLink proto :PSTRING, :PSTRING

.data?
cBuffer1  CHR   MAX_PATH dup(?)
cBuffer2  CHR   MAX_PATH dup(?)


; ==================================================================================================
.code
start proc
  SysInit

  ;Build a new output file name based on current file path
  invoke GetModuleFileName, NULL, offset cBuffer1, MAX_PATH
  invoke StrCopy,  offset cBuffer2, offset cBuffer1
  invoke StrRScan, offset cBuffer1, '\'
  .if xax
    add xax, sizeof CHR
    m2z CHR ptr [xax]
  .endif
  invoke StrCat, offset cBuffer1, $OfsCStr("ShortCut.lnk")

  ;Do COM calls to make a ShortCut
  invoke CoInitialize, NULL
  invoke MessageBox, 0, $OfsCStr("Let's try out CreateLink."), $OfsCStr("Create Link Example"), MB_OK
  invoke CoCreateLink, offset cBuffer2, offset cBuffer1
  invoke MessageBox, 0, $OfsCStr("Thats all folks!"), $OfsCStr("Create Link Example"), MB_OK
  invoke CoUninitialize

  SysDone
  invoke ExitProcess, 0
start endp


; Function to create short cuts by using IShellLink
;---------------------------------------------------------------------
CoCreateLink proc pPathObj:PSTRING, pPathLink:PSTRING
  local pIPersistFile:POINTER
  local pIShellLink:POINTER
  local dResult:DWORD
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    local pStrW:PSTRINGW
  endif

  mov dResult, $32($invoke(CoCreateInstance, offset CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, offset IID_IShellLink, addr pIShellLink))
  .if SUCCEEDED(eax)
    mov dResult, $32($ICall(pIShellLink::IShellLink.QueryInterface, offset IID_IPersistFile, addr pIPersistFile))
    .if SUCCEEDED(eax)
      mov dResult, $32($ICall(pIShellLink::IShellLink.SetPath, pPathObj))
      mov dResult, $32($ICall(pIShellLink::IShellLink.SetIconLocation, pPathObj, 0))
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        mov pStrW, $invoke(StrAllocW, MAX_PATH)       ;Make a wide string buffer for MAX_PATH chars
        invoke MultiByteToWideChar, CP_ACP, 0, pPathLink, -1, pStrW, MAX_PATH
        mov dResult, $32($ICall(pIPersistFile::IPersistFile.Save, pStrW, TRUE))
        invoke StrDisposeW, pStrW
      else
        mov dResult, $32($ICall(pIPersistFile::IPersistFile.Save, pPathLink, TRUE))
      endif
      mov dResult, $32($ICall(pIPersistFile::IPersistFile.Release))
    .endif
    mov dResult, $32($ICall(pIShellLink::IShellLink.Release))
  .endif

  ret
CoCreateLink endp

end
