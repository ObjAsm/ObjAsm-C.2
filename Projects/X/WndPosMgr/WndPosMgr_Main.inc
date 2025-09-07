; ==================================================================================================
; Title:      WndPosMgr_Main.inc
; Author:     G. Friedrich
; Version:    See WndPosMgr.asm
; ==================================================================================================


;WndPosMgr flags
WPM_TERMINATE   equ   BIT00
WPM_SHOW_USAGE  equ   BIT01
WPM_CAPTURE     equ   BIT02
WPM_DELETE      equ   BIT03

Object Application, ApplicationID, ConsoleApp
  StaticMethod      Apply
  StaticMethod      Capture
  StaticMethod      Delete
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    Run

  StaticMethod      ShowUsage

  DefineVariable    pProfileName,   PSTRING,  NULL
  DefineVariable    pArgList,       POINTER,  NULL
  DefineVariable    dFlags,         DWORD,    0
  
  Embed   Data,     Json
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Application.Apply
; Purpose:    Get a profile and apply this information to exiting windows.
; Arguments:  None.
; Return:     Nothing.

Method Application.Apply, uses xdi xsi
  local pProfiles:PJSON_PROPERTY, pProfile:PJSON_PROPERTY
  local pWindows:PJSON_PROPERTY, pWindow:PJSON_PROPERTY
  local pCaption:PSTRING, pClsName:PSTRING
  local sdX:SDWORD, sdY:SDWORD, dWidth:SDWORD, dHeight:SDWORD, dFlags:DWORD
  local hAppWnd:HWND, hLastWnd:HWND

  SetObject xsi
  OCall [xsi].Data::Json.GetProperty, addr [xsi].Data.RootProperty, offset szProfiles
  .if xax != NULL
    mov pProfiles, xax
    xor edi, edi                                        ;edi = Index
    .while TRUE
      OCall [xsi].Data::Json.GetArrayItem, pProfiles, edi
      .break .if xax == NULL
      mov pProfile, xax
      OCall [xsi].Data::Json.GetProperty, pProfile, offset szName
      .if [xsi].pProfileName == NULL
        xor eax, eax                                    ;Take the first profile
      .else
        invoke StrComp, [xax].JSON_PROPERTY.pValue, [xsi].pProfileName
      .endif
      .if eax == 0
        mov hLastWnd, 0
        OCall [xsi].Data::Json.GetProperty, pProfile, offset szWindows
        .if xax != NULL
          mov pWindows, xax
          xor edi, edi                                  ;edi = Index
          .while TRUE
            mov pCaption, NULL
            mov pClsName, NULL
          
            OCall [xsi].Data::Json.GetArrayItem, pWindows, edi
            .break .if xax == NULL
            mov pWindow, xax

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szCaption
            test xax, xax
            jz @@NextApp
            m2m pCaption, [xax].JSON_PROPERTY.pValue, xcx

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szClass
            .if xax != NULL
              m2m pClsName, [xax].JSON_PROPERTY.pValue, xcx
            .endif

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szLeft
            test xax, xax
            jz @@NextApp
            mov sdX, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szTop
            test xax, xax
            jz @@NextApp
            mov sdY, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szWidth
            test xax, xax
            jz @@NextApp
            mov dWidth, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szHeight
            test xax, xax
            jz @@NextApp
            mov dHeight, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall [xsi].Data::Json.GetProperty, pWindow, offset szFlags
            test xax, xax
            jz @@NextApp
            mov dFlags, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))
            
            invoke FindWindow, pClsName, pCaption
            .if xax != 0
              mov hAppWnd, xax
              invoke SetWindowPos, hAppWnd, hLastWnd, sdX, sdY, dWidth, dHeight, SWP_SHOWWINDOW
              m2m hLastWnd, hAppWnd, xcx
            .endif

    @@NextApp:
            inc edi
          .endw
        .endif
        .break
      .else
        inc edi
      .endif
    .endw
  .endif

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Capture
; Purpose:    Capture the data from visible windows and write it to a profile.
; Arguments:  None.
; Return:     Nothing.

EnumInfo struct
  pJson     POINTER         ?
  pWindows  PJSON_PROPERTY  ?
EnumInfo ends

GetWndInfo proc uses xbx hWnd:HWND, pInfo:EnumInfo
  local dLen:DWORD, pCaption:PSTRING, WRect:RECT, cBuffer[40]:CHR, pWindow:PJSON_PROPERTY
  local cClassName[256]:CHR       ;Class names are limited to 256 chars (including the ZTC)

  mov pCaption, NULL

  invoke IsWindowVisible, hWnd
  test eax, eax
  jz @@NextWindow

  invoke GetWindowTextLength, hWnd
  test eax, eax
  jz @@NextWindow
  mov xbx, pInfo
  mov dLen, eax
  mov pCaption, $invoke(StrAlloc, eax)
  mov eax, dLen
  inc eax
  invoke GetWindowText, hWnd, pCaption, eax
  test eax, eax
  jz @@NextWindow
  invoke GetWindowRect, hWnd, addr WRect
  mov eax, WRect.right
  sub eax, WRect.left
  .if ZERO?
    mov ecx, WRect.bottom
    sub ecx, WRect.top
    jz @@NextWindow
  .endif

  OCall [xbx].EnumInfo.pJson::Json.AddObject, [xbx].EnumInfo.pWindows, NULL
  mov pWindow, xax
  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szCaption, JSON_TYPE_STRING, pCaption
  invoke GetClassName, hWnd, addr cClassName, lengthof(cClassName)
  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szClass, JSON_TYPE_STRING, addr cClassName

  invoke sdword2dec, addr cBuffer, WRect.left
  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szLeft, JSON_TYPE_NUMBER, addr cBuffer

  invoke sdword2dec, addr cBuffer, WRect.top
  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szTop, JSON_TYPE_NUMBER, addr cBuffer

  mov edx, WRect.right
  sub edx, WRect.left
  invoke dword2dec, addr cBuffer, edx
  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szWidth, JSON_TYPE_NUMBER, addr cBuffer

  mov edx, WRect.bottom
  sub edx, WRect.top
  invoke dword2dec, addr cBuffer, edx
  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szHeight, JSON_TYPE_NUMBER, addr cBuffer

  OCall [xbx].EnumInfo.pJson::Json.AddData, pWindow, offset szFlags, JSON_TYPE_NUMBER, $OfsCStr("0")

@@NextWindow:
  invoke StrDispose, pCaption
  mov eax, TRUE
  ret
GetWndInfo endp

Method Application.Capture, uses xsi
  local pProfiles:PJSON_PROPERTY, pProfile:PJSON_PROPERTY
  local Info:EnumInfo

  SetObject xsi

  mov [xsi].Data.RootProperty.dType, JSON_TYPE_OBJECT
  OCall [xsi].Data::Json.GetProperty, addr [xsi].Data.RootProperty, offset szProfiles
  .if xax == NULL
    OCall [xsi].Data::Json.AddArray, addr [xsi].Data.RootProperty, offset szProfiles
    mov pProfiles, xax
  .else
    mov pProfiles, xax
    ;Delete exiting profile with the same name
    OCall xsi.Delete
  .endif

  ;Create new profile
  OCall [xsi].Data::Json.AddObject, pProfiles, NULL
  mov pProfile, xax
  OCall [xsi].Data::Json.AddData, pProfile, offset szName, JSON_TYPE_STRING, [xsi].pProfileName

  ;Add windows information to this profile
  OCall [xsi].Data::Json.AddArray, pProfile, offset szWindows
  lea xcx, [xsi].Data
  mov Info.pJson, xcx
  mov Info.pWindows, xax
  invoke EnumWindows, addr GetWndInfo, addr Info
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Delete
; Purpose:    Delete a profile.
; Arguments:  None.
; Return:     Nothing.

Method Application.Delete, uses xdi xsi
  local pProfiles:PJSON_PROPERTY, pProfile:PJSON_PROPERTY

  SetObject xsi
  .if [xsi].pProfileName != NULL
    OCall [xsi].Data::Json.GetProperty, addr [xsi].Data.RootProperty, offset szProfiles
    .if xax != NULL
      mov pProfiles, xax
      xor edi, edi                                        ;edi = Index
      .while TRUE
        OCall [xsi].Data::Json.GetArrayItem, pProfiles, edi
        .break .if xax == NULL                            ;No more profiles
        mov pProfile, xax
        OCall [xsi].Data::Json.GetProperty, xax, offset szName
        .if xax != NULL                                   ;Name found
          invoke StrComp, [xax].JSON_PROPERTY.pValue, [xsi].pProfileName
          .if eax == 0
            OCall [xsi].Data::Json.DelProperty, pProfile  ;Children are deleted recursively
            .break                                        ;Done
          .endif
        .endif
        inc edi
      .endw
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  local DskStream:$Obj(DiskStream)

  SetObject xsi

  .ifBitSet [xsi].dFlags, WPM_CAPTURE or WPM_DELETE 
    New DskStream::DiskStream
    OCall DskStream::DiskStream.Init, xsi, offset szFileName, GENERIC_READ or GENERIC_WRITE, \
                                      0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
    OCall [xsi].Data::Json.Write, addr DskStream
    OCall DskStream::DiskStream.Done
  .endif

  OCall [xsi].Data::Json.Done
  MemFree [xsi].pArgList
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.
; CommandLine options:

Method Application.Init, uses xbx xdi xsi
  local dArgCount:DWORD
  local DskStream:$Obj(DiskStream)

  SetObject xsi
  ACall xsi.Init, NULL
  OCall [xsi].Data::Json.Init, xsi

  ;Get commandline arguments and analyse them
;  invoke ParseCmdLineArgs, $OfsDStrW('WndPosMgr.exe Profile1')
;  invoke ParseCmdLineArgs, $OfsDStrW('WndPosMgr.exe -c Profile1')
  invoke ParseCmdLineArgs, $invoke(GetCommandLine)

  .if xax != NULL
    mov [xsi].pArgList, xax                             ;List of PSTRINGW arguments
    mov dArgCount, ecx

    mov xdi, [xsi].pArgList                   
    add xdi, sizeof(PSTRING)                            ;Skip the application filespec
    mov ebx, 2                                          ;Scan up to the second-to-last argument

    .while ebx < dArgCount
      .break .if PSTRING ptr [xdi] == NULL
      invoke StrComp, [xdi], $OfsCStr("-c")
      .if eax == 0
        BitSet [xsi].dFlags, WPM_CAPTURE
      .endif

      invoke StrComp, [xdi], $OfsCStr("-d")
      .if eax == 0
        BitSet [xsi].dFlags, WPM_DELETE
      .endif

      invoke StrComp, [xdi], $OfsCStr("-h")
      .if eax == 0
        BitSet [xsi].dFlags, WPM_SHOW_USAGE
      .endif

      invoke StrComp, [xdi], $OfsCStr("-?")
      .if eax == 0
        BitSet [xsi].dFlags, WPM_SHOW_USAGE
      .endif

      inc ebx
      add xdi, sizeof(PSTRING)
    .endw

    m2m [xsi].pProfileName, PSTRING ptr [xdi], xax

    New DskStream::DiskStream
    OCall DskStream::DiskStream.Init, xsi, offset szFileName, GENERIC_READ or GENERIC_WRITE, \
                                      0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
    OCall [xsi].Data::Json.Read, addr DskStream
    OCall DskStream::DiskStream.Done
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Run
; Purpose:    Execute the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Run, uses xsi
  SetObject xsi
  .ifBitSet [xsi].dFlags, WPM_SHOW_USAGE
    OCall xsi.ShowUsage
  .endif

  .ifBitClr [xsi].dFlags, WPM_TERMINATE
    .ifBitSet [xsi].dFlags, WPM_CAPTURE
      OCall xsi.Capture
    .elseIfBitSet [xsi].dFlags, WPM_DELETE
      OCall xsi.Delete
    .else
      OCall xsi.Apply
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.ShowUsage
; Purpose:    Display usage.
; Arguments:  Nome.
; Return:     Nothing.

Method Application.ShowUsage, uses xsi
  SetObject xsi
  OCall xsi.SetColor, COLOR_HEADER
  OCall xsi.Print, addr szUsageHeader
  OCall xsi.SetColor, COLOR_REGULAR
  OCall xsi.Print, addr szUsageText
MethodEnd
