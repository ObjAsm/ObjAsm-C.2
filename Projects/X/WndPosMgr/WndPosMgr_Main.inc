; ==================================================================================================
; Title:      WndPosMgr_Main.inc
; Author:     G. Friedrich
; Version:    See WndPosMgr.asm
; ==================================================================================================


Object Application, ApplicationID, ConsoleApp
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    Run

  StaticMethod      ProfileApply
  StaticMethod      ProfileCapture
  StaticMethod      ShowUsage

  DefineVariable    pProfileName,   PSTRING,  NULL
  DefineVariable    pArgList,       POINTER,  NULL
  DefineVariable    bCapture,       BYTE,     FALSE
  DefineVariable    bShowUsage,     BYTE,     FALSE
  DefineVariable    bTerminate,     BYTE,     FALSE
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xbx xsi
  SetObject xsi
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

  SetObject xsi
  ACall xsi.Init, NULL
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
        mov [xsi].bCapture, TRUE
      .endif

      invoke StrComp, [xdi], $OfsCStr("-h")
      .if eax == 0
        mov [xsi].bShowUsage, TRUE
      .endif
      invoke StrComp, [xdi], $OfsCStr("-?")
      .if eax == 0
        mov [xsi].bShowUsage, TRUE
      .endif

      inc ebx
      add xdi, sizeof(PSTRING)
    .endw

    m2m [xsi].pProfileName, PSTRING ptr [xdi], xax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Run
; Purpose:    Execute the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Run, uses xbx xsi
  SetObject xsi
  .if [xsi].bShowUsage != FALSE
    OCall xsi.ShowUsage
  .endif

  .if [xsi].bTerminate == FALSE
    .if [xsi].bCapture == FALSE
      OCall xsi.ProfileApply
    .else
      OCall xsi.ProfileCapture
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.ProfileApply
; Purpose:    Read a profile and apply this information to exiting windows.
; Arguments:  None.
; Return:     Nothing.

Method Application.ProfileApply, uses xbx xdi xsi
  local DskStream:$Obj(DiskStream)
  local pProfiles:PJSON_PROPERTY, pProfile:PJSON_PROPERTY, pApps:PJSON_PROPERTY, pApp:PJSON_PROPERTY
  local pAppName:PSTRING, pClsName:PSTRING
  local sdX:SDWORD, sdY:SDWORD, dWidth:SDWORD, dHeight:SDWORD, dFlags:DWORD
  local hAppWnd:HWND, hLastWnd:HWND

  SetObject xsi

  New DskStream::DiskStream
  OCall DskStream::DiskStream.Init, xsi, $OfsCStr("WndPosMgr.json"), GENERIC_READ or GENERIC_WRITE, \
                                    0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  mov xbx, $New(Json)
  OCall xbx::Json.Init, xsi
  OCall xbx::Json.Read, addr DskStream

  OCall xbx::Json.GetProperty, addr [xbx].$Obj(Json).RootProperty, $OfsCStr("Profiles")
  .if xax != NULL
    mov pProfiles, xax
    xor edi, edi                                        ;edi = Index
    .while TRUE
      OCall xbx::Json.GetArrayItem, pProfiles, edi
      .break .if xax == NULL
      mov pProfile, xax
      OCall xbx::Json.GetProperty, pProfile, $OfsCStr("Name")
      .if [xsi].pProfileName == NULL
        xor eax, eax                                    ;Take the first profile
      .else
        invoke StrComp, [xax].JSON_PROPERTY.pValue, [xsi].pProfileName
      .endif
      .if eax == 0
        mov hLastWnd, 0
        OCall xbx::Json.GetProperty, pProfile, $OfsCStr("Apps")
        .if xax != NULL
          mov pApps, xax
          xor edi, edi                                  ;edi = Index
          .while TRUE
            mov pAppName, NULL
            mov pClsName, NULL
          
            OCall xbx::Json.GetArrayItem, pApps, edi
            .break .if xax == NULL
            mov pApp, xax

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("Name")
            test xax, xax
            jz @@NextApp
            m2m pAppName, [xax].JSON_PROPERTY.pValue, xcx

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("Class")
            .if xax != NULL
              m2m pClsName, [xax].JSON_PROPERTY.pValue, xcx
            .endif

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("X")
            test xax, xax
            jz @@NextApp
            mov sdX, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("Y")
            test xax, xax
            jz @@NextApp
            mov sdY, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("W")
            test xax, xax
            jz @@NextApp
            mov dWidth, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("H")
            test xax, xax
            jz @@NextApp
            mov dHeight, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))

            OCall xbx::Json.GetProperty, pApp, $OfsCStr("Flags")
            test xax, xax
            jz @@NextApp
            mov dFlags, $32($invoke(dec2dword, [xax].JSON_PROPERTY.pValue))
            
            invoke FindWindow, pClsName, pAppName
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

  Destroy xbx
  OCall DskStream::DiskStream.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.ProfileCapture
; Purpose:    Capture the data from visible windows and write it to a profile.
; Arguments:  None.
; Return:     Nothing.

EnumInfo struct
  pJson   POINTER   ?
  pApps   PJSON_PROPERTY  ?
EnumInfo ends

GetWndInfo proc uses xbx hWnd:HWND, pInfo:EnumInfo
  local dLen:DWORD, pCaption:PSTRING, WRect:RECT, cBuffer[40]:CHR, pApp:PJSON_PROPERTY
  local cClassName[256 + 1]:CHR     ;Class names are limited to 256 chars

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

  OCall [xbx].EnumInfo.pJson::Json.AddObject, [xbx].EnumInfo.pApps, NULL
  mov pApp, xax
  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("Name"), JSON_TYPE_STRING, pCaption
  invoke GetClassName, hWnd, addr cClassName, lengthof(cClassName)
  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("Class"), JSON_TYPE_STRING, addr cClassName

  invoke sdword2dec, addr cBuffer, WRect.left
  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("X"), JSON_TYPE_NUMBER, addr cBuffer

  invoke sdword2dec, addr cBuffer, WRect.top
  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("Y"), JSON_TYPE_NUMBER, addr cBuffer

  mov edx, WRect.right
  sub edx, WRect.left
  invoke dword2dec, addr cBuffer, edx
  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("W"), JSON_TYPE_NUMBER, addr cBuffer

  mov edx, WRect.bottom
  sub edx, WRect.top
  invoke dword2dec, addr cBuffer, edx
  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("H"), JSON_TYPE_NUMBER, addr cBuffer

  OCall [xbx].EnumInfo.pJson::Json.AddData, pApp, $OfsCStr("Flags"), JSON_TYPE_NUMBER, $OfsCStr("0")

@@NextWindow:
  invoke StrDispose, pCaption
  mov eax, TRUE
  ret
GetWndInfo endp

Method Application.ProfileCapture, uses xbx xdi xsi
  local DskStream:$Obj(DiskStream)
  local pProfiles:PJSON_PROPERTY, pProfile:PJSON_PROPERTY
  local Info:EnumInfo

  SetObject xsi

  New DskStream::DiskStream
  OCall DskStream::DiskStream.Init, xsi, $OfsCStr("WndPosMgr.json"), GENERIC_READ or GENERIC_WRITE, \
                                    0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  mov xbx, $New(Json)
  OCall xbx::Json.Init, xsi

  mov [xbx].$Obj(Json).RootProperty.dType, JSON_TYPE_OBJECT
  OCall xbx::Json.AddArray, addr [xbx].$Obj(Json).RootProperty, $OfsCStr("Profiles")
  mov pProfiles, xax

  OCall xbx::Json.AddObject, pProfiles, NULL
  mov pProfile, xax
  OCall xbx::Json.AddData, pProfile, $OfsCStr("Name"), JSON_TYPE_STRING, [xsi].pProfileName
  OCall xbx::Json.AddArray, pProfile, $OfsCStr("Apps")
  mov Info.pJson, xbx
  mov Info.pApps, xax
  invoke EnumWindows, addr GetWndInfo, addr Info

  OCall xbx::Json.Write, addr DskStream
  Destroy xbx
  OCall DskStream::DiskStream.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.ShowUsage
; Purpose:    Display usage.
; Arguments:  Nome.
; Return:     Nothing.

Method Application.ShowUsage, uses xbx xdi xsi
  SetObject xsi
  OCall xsi.SetColor, COLOR_HEADER
  OCall xsi.Print, addr cUsageHeader
  OCall xsi.SetColor, COLOR_REGULAR
  OCall xsi.Print, addr cUsageText
MethodEnd
