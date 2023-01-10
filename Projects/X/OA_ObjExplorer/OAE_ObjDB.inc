; ==================================================================================================
; Title:      OAE_ObjDB.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    OA_ObjDB implementation for OA_ObjExplorer.
; ==================================================================================================


BASE_VERSION                equ   2
if TARGET_BITNESS eq 32
  DATABASE_VERSION          equ   BASE_VERSION
else 
  DATABASE_VERSION          equ   BASE_VERSION + BIT08
endif

FIF_STANDARD                equ   BIT00           ;It's a file from the standard folders
FIF_SCANNED                 equ   BIT01           ;File has been scanned in the current session

INF_INTERFACE               equ   BIT31           ;This Info is about a COM interface

CStr  cInfoFileName,        "InfoFile"
CStr  cDefaultInfoFileName, "OA_Info.stm"
CStr  cScanInclude,         "Include"
CStr  cScanExclude,         "Exclude"
CStr  cSetup,               "Setup"
CStr  cScanOn,              "ScanOn"
CStr  cSave,                "Save"
CStr  cStart,               "Start"
CStr  cYes,                 "Yes"

;Match from the beginning, skip initial blanks, capture ".xxx" patterns and skip blanks or ","
CStr  cREXP_ListItem,       "^(\.\w*)\s*,?\s*"

CStrA bComment,             "COMMENT"
CStrA bMethod,              "Method"
CStrA bMacro,               "macro"
CStrA bObject,              "Object"
CStrA bObjectEnd,           "ObjectEnd"
CStrA bVirtualMethod,       "VirtualMethod"
CStrA bStaticMethod,        "StaticMethod"
CStrA bDynamicMethod,       "DynamicMethod"
CStrA bInterfaceMethod,     "InterfaceMethod"
CStrA bInlineMethod,        "InlineMethod"
CStrA bVirtualAbstract,     "VirtualAbstract"
CStrA bDynamicAbstract,     "DynamicAbstract"
CStrA bInterfaceAbstract,   "InterfaceAbstract"
CStrA bObsoleteMethod,      "ObsoleteMethod"
CStrA bRedefineMethod,      "RedefineMethod"
CStrA bEvent,               "Event"
CStrA bDynamicEvent,        "DynamicEvent"
CStrA bVirtualEvent,        "VirtualEvent"
CStrA bDefineVariable,      "DefineVariable"
CStrA bRedefineVariable,    "RedefineVariable"
CStrA bEmbed,               "Embed"
CStrA bSetObject,           "SetObject"
CStrA bBeginInterface,      "BEGIN_INTERFACE"
CStrA bEndInterface,        "END_INTERFACE"
CStrA bStdMethod,           "STDMETHOD"
CStrA bDispMethod,          "DISPMETHOD"


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    OA_ObjDB
; Purpose:   Object database engine.

Object OA_ObjDB, OAE_ObjDBID, Primer
  StaticMethod      RemoveFileInfo,     PSTRING
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, $ObjPtr(IniFile)
  StaticMethod      Open,               PSTRING
  StaticMethod      Save,               PSTRING
  StaticMethod      ScanFile,           PSTRING, FILETIME, DWORD
  StaticMethod      ScanDBFiles
  StaticMethod      ScanDirFiles,       POINTER

  DefineVariable    ObjLock,            OBJECT_LOCK,  {}
  DefineVariable    cStmFileName,       CHR,          MAX_PATH dup(0)
  DefineVariable    dScanOn,            DWORD,        SCAN_OFF
  DefineVariable    dDoSave,            DWORD,        FALSE

  Embed             FilesColl,          FilesCollection
  Embed             InterfaceColl,      IntInfoCollection
  Embed             IntMethodColl,      IntMtdInfoCollection

  Embed             ObjectColl,         ObjInfoCollection
  Embed             ObjMethodColl,      ObjMtdInfoCollection
  Embed             ObjVariableColl,    ObjVarInfoCollection

  Embed             ImpMethodColl,      ImpMtdInfoCollection

% Embed             Parser,             RegEx

  Embed             ScanInclude,        DataCollection
  Embed             ScanExclude,        DataCollection
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;  OA_ObjDB
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.RemoveFileInfo
; Purpose:    Removes all entries in the info collections related to a specified FileName.
; Arguments:  Arg1: -> Filename.
; Return:     Nothing.

align ALIGN_CODE
DelMatchingObjVariable proc pItem:POBJVARINFORMATION, pFileInfo:PFILEINFORMATION, \
                            pColl:$ObjPtr(ObjVarInfoCollection)
  mov xax, pItem
  mov xcx, [xax].OBJVARINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ObjVarInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingObjVariable endp

align ALIGN_CODE
DelMatchingObjMethod proc pItem:POBJMTDINFORMATION, pFileInfo:PFILEINFORMATION, \
                          pColl:$ObjPtr(ObjMtdInfoCollection)
  mov xax, pItem
  mov xcx, [xax].OBJMTDINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ObjMtdInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingObjMethod endp

align ALIGN_CODE
DelMatchingObject proc pItem:POBJECTINFORMATION, pFileInfo:PFILEINFORMATION, \
                       pColl:$ObjPtr(ObjInfoCollection)
  mov xax, pItem
  mov xcx, [xax].OBJECTINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ObjInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingObject endp

align ALIGN_CODE
DelMatchingIntMethod proc pItem:PINTMTDINFORMATION, pFileInfo:PFILEINFORMATION, \
                          pColl:$ObjPtr(IntMtdInfoCollection)
  mov xax, pItem
  mov xcx, [xax].INTMTDINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::IntMtdInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingIntMethod endp

align ALIGN_CODE
DelMatchingInterface proc pItem:PINTERFACEINFORMATION, pFileInfo:PFILEINFORMATION, \
                          pColl:$ObjPtr(IntInfoCollection)
  mov xax, pItem
  mov xcx, [xax].INTERFACEINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::IntInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingInterface endp

align ALIGN_CODE
DelMatchingImpMethod proc pItem:PIMPMTDINFORMATION, pFileInfo:PFILEINFORMATION, \
                          pColl:$ObjPtr(ImpMtdInfoCollection)
  mov xax, pItem
  mov xcx, [xax].IMPMTDINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ImpMtdInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingImpMethod endp

Method OA_ObjDB.RemoveFileInfo, uses xbx xdi xsi, pFileName:PSTRING
  SetObject xsi
  OCall [xsi].FilesColl::FilesCollection.Search, pFileName
  .if eax != FALSE
    mov edi, ecx
    mov xbx, $OCall([xsi].FilesColl::FilesCollection.ItemAt, edi)
    lea xax, [xsi].ObjVariableColl
    OCall xax::ObjVarInfoCollection.ForEachRev, offset DelMatchingObjVariable, xbx, xax
    lea xax, [xsi].ObjMethodColl
    OCall xax::ObjMtdInfoCollection.ForEachRev, offset DelMatchingObjMethod, xbx, xax
    lea xax, [xsi].ObjectColl
    OCall xax::ObjInfoCollection.ForEachRev, offset DelMatchingObject, xbx, xax
    lea xax, [xsi].IntMethodColl
    OCall xax::IntMtdInfoCollection.ForEachRev, offset DelMatchingIntMethod, xbx, xax
    lea xax, [xsi].InterfaceColl
    OCall xax::IntInfoCollection.ForEachRev, offset DelMatchingInterface, xbx, xax
    lea xax, [xsi].ImpMethodColl
    OCall xax::ImpMtdInfoCollection.ForEachRev, offset DelMatchingImpMethod, xbx, xax
    OCall [xsi].FilesColl::FilesCollection.DisposeAt, edi
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Done
; Purpose:    Finalizes the object, freeing all allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method OA_ObjDB.Done, uses xsi
  SetObject xsi
  OCall [xsi].FilesColl::FilesCollection.Done
  OCall [xsi].ObjectColl::ObjInfoCollection.Done
  OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Done
  OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Done
  OCall [xsi].InterfaceColl::IntInfoCollection.Done
  OCall [xsi].IntMethodColl::IntMtdInfoCollection.Done
  OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Done

  OCall [xsi].ScanInclude::DataCollection.Done
  OCall [xsi].ScanExclude::DataCollection.Done

  %OCall [xsi].Parser::RegEx.Done

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RemoveUnusedInfo
; Purpose:    Remove unused structures from the Object database.
; Arguments:  Arg1: -> FILEINFORMATION
;             Arg2: -> Self.
;             Arg3: Dummy.
; Return:     Nothing.

RemoveUnusedInfo proc pFileInfo:PFILEINFORMATION, pSelf:POINTER, xDummy:XWORD
  ;Remove untagged files and related info from collections
  mov xax, pFileInfo
  .if [xax].FILEINFORMATION.dFlags == 0
    OCall pSelf::OA_ObjDB.RemoveFileInfo, [xax].FILEINFORMATION.pFileName
  .endif
  ret
RemoveUnusedInfo endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Init
; Purpose:    Initializes a OA_ObjDB object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> IniFile object.
; Return:     Nothing.

Method OA_ObjDB.Init, uses xbx xdi xsi, pOwner:POINTER, pIniFile:$ObjPtr(IniFile)
  local dHasChanged:DWORD
  local cBuffer[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner

  lea xbx, [xsi].FilesColl
  OCall xbx::FilesCollection.Init, xsi, 50, 25, COL_MAX_CAPACITY

  OCall [xsi].ObjectColl::ObjInfoCollection.Init, xsi, 50, 50, xbx
  OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Init, xsi, 100, 100, xbx
  OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Init, xsi, 100, 100, xbx

  OCall [xsi].InterfaceColl::IntInfoCollection.Init, xsi, 50, 50, xbx
  OCall [xsi].IntMethodColl::IntMtdInfoCollection.Init, xsi, 100, 100, xbx
  OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Init, xsi, 100, 100, xbx

  mov xbx, $OCall(pIniFile::IniFile.GetString, offset cSetup, offset cScanOn, offset cStart)
  invoke StrComp, xbx, offset cStart
  .if eax == 0
    mov [xsi].dScanOn, SCAN_ON_START
  .endif
  invoke StrDispose, xbx

  mov xbx, $OCall(pIniFile::IniFile.GetString, offset cSetup, offset cSave, offset cYes)
  invoke StrComp, xbx, offset cYes
  .if eax == 0
    mov [xsi].dDoSave, TRUE
  .endif
  invoke StrDispose, xbx

  OCall [xsi].ScanInclude::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  xor edi, edi
  .repeat
    invoke dword2dec, addr cBuffer, edi
    mov xbx, $OCall(pIniFile::IniFile.GetString, offset cScanInclude, addr cBuffer, offset szNULL)
    .if edi > 0 && CHR ptr [xax] == 0
      invoke StrDispose, xbx
      .break
    .endif
    invoke ExpandEnvironmentStrings, xbx, addr cBuffer, lengthof(cBuffer) - 1
    invoke StrDispose, xbx
    invoke StrNew, addr cBuffer
    OCall [xsi].ScanInclude::DataCollection.Insert, xax
    inc edi
  .until FALSE

  OCall [xsi].ScanExclude::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  xor edi, edi
  .repeat
    invoke dword2dec, addr cBuffer, edi
    mov xbx, $OCall(pIniFile::IniFile.GetString, offset cScanExclude, addr cBuffer, offset szNULL)
    .if edi > 0 && CHR ptr [xax] == 0
      invoke StrDispose, xbx
      .break
    .endif
    invoke ExpandEnvironmentStrings, xbx, addr cBuffer, lengthof(cBuffer) - 1
    invoke StrNew, addr cBuffer
    OCall [xsi].ScanExclude::DataCollection.Insert, xax
    inc edi
  .until FALSE

  lea xbx, [xsi].Parser
  %OCall xbx::RegEx.Init, xsi, offset cREXP_ListItem, 0
  %OCall xbx::RegEx.SetOutCount, -1
  %OCall xbx::RegEx.Study, 0

  ;Load data from .stm file
  mov xbx, $OCall(pIniFile::IniFile.GetString, offset cSetup, offset cInfoFileName, offset cDefaultInfoFileName)
  lea xdi, [xsi].cStmFileName
  invoke ExpandEnvironmentStrings, xbx, xdi, MAX_PATH
  invoke StrDispose, xbx
  .if $invoke(FileExist, xdi) != FALSE
    OCall xsi.Open, xdi
  .endif

  ;Check if something has changed in the following folders and rebuild if necessary
  mov dHasChanged, FALSE
  .ifBitSet [xsi].dScanOn, SCAN_ON_START
    mov ebx, 1
    .while ebx < [xsi].ScanInclude.dCount
      OCall [xsi].ScanInclude::DataCollection.ItemAt, ebx
      OCall xsi.ScanDirFiles, xax
      or dHasChanged, eax                               ;Update flag
      inc ebx
    .endw

    .if dHasChanged != FALSE
      ;Remove unused entries
      OCall [xsi].FilesColl::FilesCollection.ForEachRev, offset RemoveUnusedInfo, xsi, NULL
      ;Save to .stm file
      .if [xsi].dDoSave != FALSE
        OCall xsi.Save, xdi
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Open
; Purpose:    Reads the DB content from a binary file.
; Arguments:  Arg1: -> File name.
; Return:     Nothing.

Method OA_ObjDB.Open, uses xbx xdi xsi, pFileName:PSTRING
  local DskStm:$Obj(DiskStream), DLUT:$Obj(DesLUT), DeserInfo:DESER_INFO

  SetObject xsi
  mov xbx, $New(DskStm::DiskStream)
  OCall xbx::DiskStream.Init, xsi, pFileName, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
  OCall xbx::DiskStream.BinRead32                     ;Read file version
  .if eax == DATABASE_VERSION
    New DLUT::DesLUT
    mov DeserInfo.pDesLUT, xax
    lea xdi, DeserInfo
    OCall DLUT::DesLUT.Init, xsi, 100, 100, COL_MAX_CAPACITY
    DbgText "Reading Database..."
    OCall xbx::DiskStream.BinReadX
    DbgHex xax
    OCall DLUT::DesLUT.Insert, xax, xsi               ;Set Collection owner in the LUT
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].FilesColl::FilesCollection.Load, xbx, xdi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ObjectColl::ObjInfoCollection.Load, xbx, xdi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Load, xbx, xdi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Load, xbx, xdi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].InterfaceColl::IntInfoCollection.Load, xbx, xdi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].IntMethodColl::IntMtdInfoCollection.Load, xbx, xdi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Load, xbx, xdi
    OCall DLUT::DesLUT.Done
  .endif
  OCall xbx::DiskStream.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Save
; Purpose:    Saves the DB content to a binary file.
; Arguments:  Arg1: -> file name.
; Return:     Nothing.

Method OA_ObjDB.Save, uses xbx xsi, pFileName:PSTRING
  local DskStm:$Obj(DiskStream)

  SetObject xsi
;  DbgText "Saving Database..."
  mov xbx, $New(DskStm::DiskStream)
  OCall xbx::DiskStream.Init, xsi, pFileName, 0, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  OCall xbx::DiskStream.BinWrite32, DATABASE_VERSION
  OCall xbx::DiskStream.BinWriteX, xsi                  ;Store -> OA_ObjDB for later use
  OCall xbx::DiskStream.Put, addr [xsi].FilesColl
  OCall xbx::DiskStream.Put, addr [xsi].ObjectColl
  OCall xbx::DiskStream.Put, addr [xsi].ObjMethodColl
  OCall xbx::DiskStream.Put, addr [xsi].ObjVariableColl
  OCall xbx::DiskStream.Put, addr [xsi].InterfaceColl
  OCall xbx::DiskStream.Put, addr [xsi].IntMethodColl
  OCall xbx::DiskStream.Put, addr [xsi].ImpMethodColl
  OCall xbx::DiskStream.Truncate
  OCall xbx::DiskStream.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindHelpLines
; Purpose:    Scans a file from a defined linenumber backwards looking for consecutive outcommented
;             lines.
; Arguments:  Arg1: -> TextSource.
;             Arg2: -> INFORMATION.
; Return:     INFORMATION.pHelpData -> chain of [Ptr to next block, Help string].
;             INFORMATION.dHelpLineCount = Number of lines.

FindHelpLines proc uses xbx xdi xsi pTextSrc:$ObjPtr(TextSource), pInfo:PINFORMATION
;  local dHelpLineCount:DWORD, dLineNumber:DWORD
;
;  mov xbx, pTextSrc
;  xor edi, edi
;  mov dHelpLineCount, edi
;
;  m2m dLineNumber, [xbx].$Obj(TextSource).dLineNumber, eax  ;Save current line position
;
;  .repeat
;    OCall xbx::TextSource.GetPrevLine
;    ;eax = TRUE if succeeded, otherwise FALSE
;    ;ecx = Character offset.
;    ;edx = Character count.
;    .break .if eax == FALSE
;    mov xsi, [xbx].$Obj(TextSource).MemStream.pBuffer
;    ;Skip all initial spaces
;    .repeat
;      mov al, [xsi]
;      .break .if al != VK_SPACE && al != VK_TAB
;      inc xsi
;    .until FALSE                                        ;xsi -> 1st non blank character
;
;    .continue .if dHelpLineCount == 0 && al == 0
;    .break .if al != ";"                                ;Help lines end here
;
;    add xdx, [xbx].$Obj(TextSource).MemStream.pBuffer
;    sub xdx, xsi                                        ;edx = # of chars included ZTC
;
;    inc xsi                                             ;Move to next character
;    add edx, sizeof(POINTER)                            ;Room for block chaining POINTER
;    mov eax, edx
;    MemAlloc eax
;    mov xdi, xax
;    mov [xax], xdi                                      ;Store the POINTER
;    add xax, sizeof(POINTER)
;    invoke StrCopy, xax, xsi
;    inc dHelpLineCount
;  .until FALSE
;
;;  DbgDec dHelpLineCount
;  mov xax, pInfo
;  .if dHelpLineCount == 0
;    ;Save information
;    m2z [xax].INFORMATION.pHelpData
;    m2z [xax].INFORMATION.dHelpLineCount
;  .else
;    mov [xax].INFORMATION.pHelpData, xdi                ;Store the last block POINTER
;    m2m [xax].INFORMATION.dHelpLineCount, dHelpLineCount, edx
;  .endif
;
;  m2m [xbx].$Obj(TextSource).dLineNumber, dLineNumber, eax  ;Restore line position

; ////////////////////// temprary ////////////////////
  mov xax, pInfo
  m2z [xax].INFORMATION.pHelpData
  m2z [xax].INFORMATION.dHelpLineCount

  ret
FindHelpLines endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.ScanFile
; Purpose:    Scans a file in the ObjAsm\Code\Objects directory for object information.
; Arguments:  Arg1: -> File name.
;             Arg2: Last Write Time (FILETIME).
;             Arg3: Info Flags: OIF_xxx (INF_PRJ, etc.).
; Return:     xax -> FILEINFORMATION or NULL if the file was excluded of the scan.

CheckMthWord macro ThisWord, ThisFlag
  cmp dWordLength, lengthof ThisWord
  jnz @F
  invoke StrCCompA, pWord, offset ThisWord, dWordLength
  jnz @F
  mov dFlags, ThisFlag
  jmp @@AddNewMethod
@@:
endm

CheckVarWord macro ThisWord, ThisFlag
  cmp dWordLength, lengthof ThisWord
  jnz @F
  invoke StrCCompA, pWord, offset ThisWord, dWordLength
  jnz @F
  mov dFlags, ThisFlag
  jmp @@AddNewVariable
@@:
endm

FileNotListed proc pFileNameInCollection:PSTRING, pTestFileName:PSTRING, xDummy:XWORD
  invoke StrIComp, pFileNameInCollection, pTestFileName
  ret
FileNotListed endp

Method OA_ObjDB.ScanFile, uses xbx xdi xsi, pFileName:PSTRING, LastWriteTime:FILETIME, \
                                            dInfoFlags:DWORD
  local pWord:PSTRINGA, dWordLength:DWORD
  local pName:POINTER, dNameLength:DWORD
  local dIncludeLength:DWORD, pExtension:PSTRING, dFlags:DWORD
  local pFileInfo:PFILEINFORMATION, TextSrc:$Obj(TextSource)

  ;DbgText "OA_ObjDB.ScanFile"
  ;DbgStr pFileName
  
  SetObject xsi
  m2z pFileInfo

  ;Check for included file types
  mov xdi, [xsi].Parser.pOutVector
  mov dNameLength, $32($invoke(StrLength, pFileName))
  mov pExtension, $invoke(PathFindExtension, pFileName)
  OCall [xsi].ScanInclude::DataCollection.ItemAt, 0     ;Get allowed file extensions
  .if xax != NULL && CHR ptr [xax] != 0                 ;Valid string?
    mov xbx, xax
    mov dIncludeLength, $32($invoke(StrLength, xbx))
    .while TRUE
      %OCall [xsi].Parser::RegEx.Exec, xbx, dIncludeLength, 0, 0  ;Extract extensions
      .if eax == 2                                      ;RegEx.Exec should return 2x PCRE_OUTDATA
        ;Get allowed extension length
        mov eax, [xdi + sizeof PCRE_OUTDATA].PCRE_OUTDATA.dEndIndex      ;CHR index
        mov ecx, [xdi + sizeof PCRE_OUTDATA].PCRE_OUTDATA.dBegIndex
        sub eax, ecx                                    ;eax = # of CHRs
        lea xdx, [xbx + sizeof(CHR)*xcx]
        invoke StrCIComp, pExtension, xdx, eax          ;Compare file with allowed extension
        .break .if eax == 0
        mov ecx, [xdi].PCRE_OUTDATA.dEndIndex
        lea xbx, [xbx + sizeof(CHR)*xcx]                ;Move to next extension
        sub dIncludeLength, ecx
      .else
        xor eax, eax                                    ;Set xax = NULL
        jmp @@EOM                                       ;Exit
      .endif
    .endw
  .endif

  ;Check if the file in not excluded
  OCall [xsi].ScanExclude::DataCollection.FirstThatNot, addr FileNotListed, pFileName, NULL
  .if xax != NULL
    xor eax, eax                                        ;Set xax = NULL
    jmp @@EOM                                           ;Exit
  .endif

  ;We create a file entry for EACH file in the directory!
  .if $OCall([xsi].FilesColl::FilesCollection.Search, pFileName) == FALSE
    mov xdi, $MemAlloc(sizeof(FILEINFORMATION))
    mov [xdi].FILEINFORMATION.pFileName, $invoke(StrNew, pFileName)
    m2m [xdi].FILEINFORMATION.LastWrite.dwLowDateTime, LastWriteTime.dwLowDateTime, edx
    m2m [xdi].FILEINFORMATION.LastWrite.dwHighDateTime, LastWriteTime.dwHighDateTime, edx
    mov [xdi].FILEINFORMATION.dFlags, FIF_SCANNED
    OCall [xsi].FilesColl::FilesCollection.Insert, xdi  ;xax -> FILEINFORMATION
  .else
    mov edx, ecx
    OCall [xsi].FilesColl::FilesCollection.ItemAt, edx  ;xax -> FILEINFORMATION
  .endif
  mov pFileInfo, xax

  New TextSrc::TextSource
  OCall TextSrc::TextSource.Init, xsi, pFileName
  OCall TextSrc::TextSource.Reset

  .repeat
    .if $OCall(TextSrc::TextSource.GetNextLine) == FALSE
      jmp @@Exit
    .endif
    OCall TextSrc::TextSource.GetNextWord
    .if ecx != 0
      mov pWord, xax
      mov dWordLength, ecx

      .if ecx == 6                                      ;lengthof(bObject) and lengthof(bMethod)
        invoke StrCCompA, pWord, offset bObject, dWordLength
        .if eax == 0
          OCall TextSrc::TextSource.GetNextWord         ;Get object name
          .if ecx != 0
            mov pWord, xax
            mov dWordLength, ecx
            .if ecx == lengthof bMacro
              invoke StrCICompA, offset bMacro, pWord, dWordLength  ;Check for "Object" macro
              .continue .if eax == 0                    ;Skip
            .endif

            ;Object name OK => create a new OBJECTINFORMATION entry in the object collection
            mov pName, $invoke(StrCNewA, pWord, dWordLength)
            mov xbx, $MemAlloc(sizeof(OBJECTINFORMATION))
            m2m [xbx].OBJECTINFORMATION.pName, pName, edx
            m2m [xbx].OBJECTINFORMATION.dLineNumber, TextSrc.dLineNumber, ecx
            m2m [xbx].OBJECTINFORMATION.dFlags, dInfoFlags, edx
            m2m [xbx].OBJECTINFORMATION.pFileInfo, pFileInfo, xcx
            m2z [xbx].OBJECTINFORMATION.pHelpData       ;Ignore this now
            m2z [xbx].OBJECTINFORMATION.dHelpLineCount
            OCall [xsi].ObjectColl::ObjInfoCollection.Insert, xbx

            OCall TextSrc::TextSource.GetNextWord       ;Skip object ID
            OCall TextSrc::TextSource.GetNextWord       ;Get object ancestor name
            .if ecx != 0
              mov edx, ecx
              invoke StrCNewA, xax, edx
            .else
              xor eax, eax
            .endif
            mov [xbx].OBJECTINFORMATION.pAncestorName, xax  ;Store ancestor name

;            invoke FindHelpLines, addr TextSrc, xbx     ;Get the help lines now

            ;Scan now for object members
            .repeat
              .if $OCall(TextSrc::TextSource.GetNextLine) == FALSE
                jmp @@Exit
              .endif
              OCall TextSrc::TextSource.GetNextWord
              .if ecx != 0
                mov pWord, xax
                mov dWordLength, ecx
                .if ecx == lengthof bObjectEnd
                  invoke StrCCompA, pWord, offset bObjectEnd, dWordLength
                  .break .if eax == 0                   ;We are done
                .endif

                CheckMthWord bVirtualMethod,    METHODTYPE_VIRTUAL
                CheckMthWord bStaticMethod,     METHODTYPE_STATIC
                CheckMthWord bDynamicMethod,    METHODTYPE_DYNAMIC
                CheckMthWord bInterfaceMethod,  METHODTYPE_INTERFACE
                CheckMthWord bInlineMethod,     METHODTYPE_INLINE

                CheckMthWord bVirtualEvent,     METHODTYPE_VIRTUAL_EVENT
                CheckMthWord bDynamicEvent,     METHODTYPE_DYNAMIC_EVENT

                CheckMthWord bVirtualAbstract,  METHODTYPE_VIRTUAL_ABSTRACT
                CheckMthWord bDynamicAbstract,  METHODTYPE_DYNAMIC_ABSTRACT

                CheckMthWord bRedefineMethod,   METHODTYPE_REDEFINED

                CheckVarWord bDefineVariable,   VARIABLETYPE_REGULAR
                CheckVarWord bRedefineVariable, VARIABLETYPE_REDEFINED
                CheckVarWord bEmbed,            VARIABLETYPE_OBJECT

              .endif
              .continue                                 ;Check next line

          @@AddNewMethod:
              OCall TextSrc::TextSource.GetNextWord     ;Get method name
              .if ecx != 0
                mov edx, ecx
                mov xbx, $invoke(StrCNewA, xax, edx)
                MemAlloc sizeof(OBJMTDINFORMATION)
                mov [xax].OBJMTDINFORMATION.pName, xbx
                mov xbx, xax
                mov [xbx].OBJMTDINFORMATION.pObjectName, $invoke(StrNewA, pName)
                m2m [xbx].OBJMTDINFORMATION.dLineNumber, TextSrc.dLineNumber, ecx
                m2m [xbx].OBJMTDINFORMATION.pFileInfo, pFileInfo, xdx   ;From FilesCollection
                m2m [xbx].OBJMTDINFORMATION.dFlags, dFlags, ecx
                m2z [xbx].OBJMTDINFORMATION.pHelpData                   ;Ignore this now
                m2z [xbx].OBJMTDINFORMATION.dHelpLineCount

                mov pWord, $OCall(TextSrc::TextSource.GetNextWord)      ;xax -> parameters
                .if xax != NULL
                  invoke StrRScanA, xax, ';'            ;Look for a remark at the end of line
                  .if xax != NULL
                    m2z CHRA ptr [xax]                  ;Set ZTC to ignore the remark
                    invoke StrRTrimA, pWord, pWord
                  .endif
                .endif
                .if dFlags == METHODTYPE_VIRTUAL_EVENT || dFlags == METHODTYPE_DYNAMIC_EVENT
                  mov [xbx].OBJMTDINFORMATION.pArguments, $invoke(StrNewA, $OfsCStr("wParam, lParam"))
                .else
                  mov [xbx].OBJMTDINFORMATION.pArguments, $invoke(StrNewA, pWord)
                .endif
                OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Insert, xbx

                invoke FindHelpLines, addr TextSrc, xbx ;Get the help lines now

              .endif
              .continue

          @@AddNewVariable:
              OCall TextSrc::TextSource.GetNextWord     ;Get variable name
              .if ecx != 0
                mov edx, ecx
                mov xbx, $invoke(StrCNewA, xax, edx)
                MemAlloc sizeof(OBJVARINFORMATION)
                mov [xax].OBJVARINFORMATION.pName, xbx
                mov xbx, xax
                mov [xbx].OBJVARINFORMATION.pObjectName, $invoke(StrNewA, pName)
                m2m [xbx].OBJVARINFORMATION.dLineNumber, TextSrc.dLineNumber, ecx
                m2m [xbx].OBJVARINFORMATION.pFileInfo, pFileInfo, xdx  ;From FilesCollection
                m2m [xbx].OBJVARINFORMATION.dFlags, dFlags, ecx
                m2z [xbx].OBJVARINFORMATION.pHelpData   ;Ignore this now
                m2z [xbx].OBJVARINFORMATION.dHelpLineCount
                mov pWord, $OCall(TextSrc::TextSource.GetNextWord)
                .if xax != NULL
                  invoke StrRScanA, xax, ';'            ;Look for a remark at the end of line
                  .if xax != NULL
                    m2z CHRA ptr [xax]                  ;Set ZTC to ignore the remark
                    invoke StrRTrimA, pWord, pWord
                  .endif
                .endif
                mov [xbx].OBJVARINFORMATION.pArgType, $invoke(StrNewA, pWord)
                OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Insert, xbx
              .endif

              invoke FindHelpLines, addr TextSrc, xbx   ;Get the help lines now

            .until FALSE
          .endif
        .else
          ;-- Method implementation --------------------------------------------------
          invoke StrCCompA, pWord, offset bMethod, dWordLength
          .if eax == 0
            OCall TextSrc::TextSource.GetNextWord       ;Get object/interface name
            mov pWord, xax
            mov dWordLength, ecx
            .if ecx == lengthof(bMacro)
              invoke StrCICompA, offset bMacro, pWord, dWordLength
              .continue .if eax == 0
            .endif
            ;Get the interface/object name
            mov xbx, $MemAlloc(sizeof(IMPMTDINFORMATION))
            invoke StrCNew, pWord, dWordLength
            mov [xbx].IMPMTDINFORMATION.pObjectName, xax
            m2m [xbx].IMPMTDINFORMATION.pFileInfo, pFileInfo, xdx ;From FilesCollection
            m2m [xbx].IMPMTDINFORMATION.dLineNumber, TextSrc.dLineNumber, ecx
            m2z [xbx].IMPMTDINFORMATION.dFlags
            m2z [xbx].IMPMTDINFORMATION.pArguments
            m2z [xbx].IMPMTDINFORMATION.pHelpData       ;Ignore this now
            m2z [xbx].IMPMTDINFORMATION.dHelpLineCount

            ;Get the method name
            OCall TextSrc::TextSource.GetNextWord       ;xax -> parameters
            mov pWord, xax
            mov dWordLength, ecx
            add pWord, xcx
            mov [xbx].IMPMTDINFORMATION.pName, $invoke(StrCNewA, xax, dWordLength)
            invoke StrLScanA, pWord, ","
            .if xax != NULL
              invoke StrLScanA, xax, ","
              .if xax != NULL
                add xax, sizeof(CHR)
                mov [xbx].IMPMTDINFORMATION.pArguments, $invoke(StrNewA, xax)
              .endif
            .endif

            OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Insert, xbx

;            invoke FindHelpLines, addr TextSrc, xbx
          .endif
        .endif

      ;-- Interface definition --------------------------------------------------
      .elseif ecx == lengthof bBeginInterface
        invoke StrCCompA, pWord, offset bBeginInterface, dWordLength
        .if eax == 0
          OCall TextSrc::TextSource.GetNextWord         ;Get interface name
          mov pWord, xax
          mov dWordLength, ecx
          .if ecx != 0
            .if ecx == lengthof bMacro
              invoke StrCICompA, offset bMacro, pWord, dWordLength
              .continue .if eax == 0
            .endif
            ;Interface name OK => create a new entry in the interface collection
            invoke StrCNewA, pWord, dWordLength
            mov pName, xax
            mov xbx, $MemAlloc(sizeof(INTERFACEINFORMATION))
            m2m [xbx].INTERFACEINFORMATION.pName, pName, xdx
            mov edx, dInfoFlags
            or edx, INF_INTERFACE
            mov [xbx].INTERFACEINFORMATION.dFlags, edx
            m2m [xbx].INTERFACEINFORMATION.pFileInfo, pFileInfo, xax
            m2m [xbx].INTERFACEINFORMATION.dLineNumber, TextSrc.dLineNumber, ecx
            m2z [xbx].INTERFACEINFORMATION.pHelpData
            m2z [xbx].INTERFACEINFORMATION.dHelpLineCount

            OCall TextSrc::TextSource.GetNextWord       ;Get interface ancestor
            mov pWord, xax
            mov dWordLength, ecx
            .if ecx != 0
              invoke StrCNewA, pWord, dWordLength
            .else
              xor eax, eax
            .endif
            mov [xbx].INTERFACEINFORMATION.pAncestorName, xax
            DbgStr xax

            OCall [xsi].InterfaceColl::IntInfoCollection.Insert, xbx

            invoke FindHelpLines, addr TextSrc, xbx

            ;Scan now for standart/dispatch interface methods
            .repeat
              .if $OCall(TextSrc::TextSource.GetNextLine) == FALSE
                jmp @@Exit
              .endif
              OCall TextSrc::TextSource.GetNextWord
              .if ecx != 0
                mov pWord, xax
                mov dWordLength, ecx
                .if dWordLength == lengthof bEndInterface
                  invoke StrCCompA, pWord, offset bEndInterface, dWordLength
                  .break .if eax == 0
                .endif

                .if dWordLength == lengthof bStdMethod
                  invoke StrCCompA, pWord, offset bStdMethod, dWordLength
                  mov dFlags, METHODTYPE_STANDARD
                .elseif dWordLength == lengthof bDispMethod
                  invoke StrCCompA, pWord, offset bDispMethod, dWordLength
                  mov dFlags, METHODTYPE_DISPATCH
                .endif

                .if eax == 0
                  OCall TextSrc::TextSource.GetNextWord    ;Get method name
                  .if ecx != 0
                    mov edx, ecx
                    mov xbx, $invoke(StrCNewA, xax, edx)
                    MemAlloc sizeof(INTMTDINFORMATION)
                    mov [xax].INTMTDINFORMATION.pName, xbx
                    mov xbx, xax
                    mov [xbx].INTMTDINFORMATION.pInterfaceName, $invoke(StrNewA, pName)
                    m2m [xbx].INTMTDINFORMATION.dFlags, dFlags, edx
                    m2m [xbx].INTMTDINFORMATION.pFileInfo, pFileInfo, xdx  ;From FilesCollection
                    m2z [xbx].INTMTDINFORMATION.pHelpData   ;Ignore this now
                    m2z [xbx].INTMTDINFORMATION.dHelpLineCount

                    OCall TextSrc::TextSource.GetNextWord
                    mov pWord, xax
                    mov dWordLength, ecx
                    .if xax != NULL
                      invoke StrRScanA, xax, ';'  ;Look for a remark at the end of line
                      .if xax != NULL
                        m2z CHRA ptr [xax]        ;Set ZTC to ignore the remark
                        invoke StrRTrimA, pWord, pWord
                      .endif
                    .endif
                    mov [xbx].INTMTDINFORMATION.pArguments, $invoke(StrNewA, xax)
                    OCall [xsi].IntMethodColl::IntMtdInfoCollection.Insert, xbx

                    invoke FindHelpLines, addr TextSrc, xbx     ;Get the help lines now

                  .endif
                .endif
              .endif
            .until FALSE
          .endif
        .endif
      .endif
    .endif
  .until FALSE

@@Exit:
  OCall TextSrc::TextSource.Done
  mov xax, pFileInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.ScanDBFiles
; Purpose:    Checks all files in the FilesCollection.
; Arguments:  None.
; Return:     eax = TRUE if something has changed in the database, otherwise FALSE.

Method OA_ObjDB.ScanDBFiles, uses xbx xdi xsi
  local FD:WIN32_FIND_DATA, dHasChanged:DWORD
  local cBuffer[MAX_PATH]:CHR, pFileInfo:PFILEINFORMATION

  SetObject xsi
  m2z dHasChanged
  xor ebx, ebx
  .while ebx < [xsi].FilesColl.dCount
    mov pFileInfo, $OCall([xsi].FilesColl::FilesCollection.ItemAt, ebx)
    mov xdi, [xax].FILEINFORMATION.pFileName
    lea xdx, FD
    invoke FindFirstFile, xdi, xdx
    .if eax == INVALID_HANDLE_VALUE
      DbgWarning "File deleted = "
      mov xax, pFileInfo
      DbgStr [xax].FILEINFORMATION.pFileName
      OCall xsi.RemoveFileInfo, xdi
    .else
      invoke FindClose, xax
      mov xax, pFileInfo
      mov ecx, [xax].FILEINFORMATION.LastWrite.dwHighDateTime
      .if ecx == FD.ftLastWriteTime.dwHighDateTime
        mov ecx, [xax].FILEINFORMATION.LastWrite.dwLowDateTime
        .if ecx == FD.ftLastWriteTime.dwLowDateTime
          jmp @@NextFile
        .endif
      .endif
      ;Save FileName on cBuffer
      invoke StrCCopy, addr cBuffer, xdi, lengthof(cBuffer) - 1
      OCall xsi.RemoveFileInfo, xdi
      OCall xsi.ScanFile, addr cBuffer, FD.ftLastWriteTime, 0   ;Ret -> FILEINFORMATION
      .if xax != NULL
        or dHasChanged, TRUE
      .endif
    .endif
@@NextFile:
    inc ebx
  .endw
  mov eax, dHasChanged
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.ScanDirFiles
; Purpose:    Checks all files of a specified folder.
; Arguments:  Arg1: -> Path.
; Return:     eax = TRUE if something has changed in the specified folder, else FALSE.

Method OA_ObjDB.ScanDirFiles, uses xbx xdi xsi, pPath:POINTER
  local FD:WIN32_FIND_DATA, xRemaining:XWORD, dHasChanged:DWORD
  local cBuffer[MAX_PATH]:CHR, pBuffer:POINTER

  ;DbgText "OA_ObjDB.ScanDirFiles"
  ;DbgStrA pPath
  SetObject xsi
  m2z dHasChanged
  lea xbx, cBuffer
  mov pBuffer, xbx
  mov xRemaining, xbx
  mov xdi, $invoke(StrECopy, xbx, pPath)
  sub xRemaining, xax
  add xRemaining, lengthof(cBuffer) - 1
  invoke StrCCopy, xdi, $OfsCStr("*.*"), DWORD ptr xRemaining
  mov xbx, $invoke(FindFirstFile, xbx, addr FD)
  .if xbx != INVALID_HANDLE_VALUE
    .repeat
      .if FD.nFileSizeLow != 0 || FD.nFileSizeHigh != 0
        invoke StrCCopy, xdi, addr FD.cFileName, DWORD ptr xRemaining
        .if $OCall([xsi].FilesColl::FilesCollection.Search, pBuffer) != FALSE
          mov edx, ecx
          OCall [xsi].FilesColl::FilesCollection.ItemAt, edx  ;xax -> FILEINFORMATION 
          mov ecx, FD.ftLastWriteTime.dwHighDateTime
          mov ecx, [xax].FILEINFORMATION.LastWrite.dwHighDateTime
          .if ecx == FD.ftLastWriteTime.dwHighDateTime
            mov ecx, FD.ftLastWriteTime.dwLowDateTime
            mov ecx, [xax].FILEINFORMATION.LastWrite.dwLowDateTime
            .if ecx == FD.ftLastWriteTime.dwLowDateTime
              mov [xax].FILEINFORMATION.dFlags, FIF_STANDARD
              jmp @F
            .endif
          .endif
          OCall xsi.RemoveFileInfo, pBuffer
        .endif
        OCall xsi.ScanFile, pBuffer, FD.ftLastWriteTime, 0    ;Ret -> FILEINFORMATION
        .if xax != NULL
          mov [xax].FILEINFORMATION.dFlags, FIF_STANDARD
          or dHasChanged, TRUE
        .endif
      .endif
    @@:
      invoke FindNextFile, xbx, addr FD
    .until eax == FALSE
    invoke FindClose, xbx
  .endif
  mov eax, dHasChanged
MethodEnd

endif