; ==================================================================================================
; Title:      OA_Tools_Globals.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================


include OA_Tools_Shared.inc

%CStr szAppTitle,             "&APP_TITLE"
%CStr szAboutVersion,         "&VER_PRODUCTVERSION_STR"
%CStr szAboutCopyright,       "© &COPYRIGHT ", 10, 13, \
                               @CatStr(<!">, %BUILD_DATE_STR, \
                               <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                               %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)
                              
CStr szRegKey,                "Software\OA_Tools"

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  CStr szRichEdit20,          "RichEdit20A"
else
  CStr szRichEdit20,          "RichEdit20W"
endif

CStr szWinState,              "Window.State"
CStr szWinLeft,               "Window.Left"
CStr szWinTop,                "Window.Top"
CStr szWinRight,              "Window.Right"
CStr szWinBottom,             "Window.Bottom"
CStrW szWinWorkDirectoryW,    "Window.WorkDirectory"
CStr szMainLanguage,          "Main.Language"
CStr szMainCloseIfNoFinding,  "Main.CloseIfNoFinding"
CStr szMainUseAnnotations,    "Main.UseAnnotations"
CStr szMainTestBitness,       "Main.TestBitness"
CStr szMainZoomfactor,        "Main.Zoomfactor"
CStr szMainLineTerminator,    "Main.LineTerminator"
CStr szMainFontSize,          "Main.FontSize"
CStr szMainFontFaceName,      "Main.FontFaceName"
CStr szMainExternalEditor,    "Main.ExternalEditor"
CStr szTool0Name,             "Tool0.Name"
CStr szTool0Cmd,              "Tool0.Cmd"
CStr szTool1Name,             "Tool1.Name"
CStr szTool1Cmd,              "Tool1.Cmd"
CStr szTool2Name,             "Tool2.Name"
CStr szTool2Cmd,              "Tool2.Cmd"
CStr szTool3Name,             "Tool3.Name"
CStr szTool3Cmd,              "Tool3.Cmd"
CStr szTool4Name,             "Tool4.Name"
CStr szTool4Cmd,              "Tool4.Cmd"
CStr szTool5Name,             "Tool5.Name"
CStr szTool5Cmd,              "Tool5.Cmd"
CStr szTool6Name,             "Tool6.Name"
CStr szTool6Cmd,              "Tool6.Cmd"
CStr szTool7Name,             "Tool7.Name"
CStr szTool7Cmd,              "Tool7.Cmd"
CStr szTool8Name,             "Tool8.Name"
CStr szTool8Cmd,              "Tool9.Cmd"
CStr szTool9Name,             "Tool9.Name"
CStr szTool9Cmd,              "Tool9.Cmd"
CStr szColorNotification,     "Color.Notification"
CStr szColorInformation,      "Color.Information"
CStr szColorRegError,         "Color.RegError"
CStr szColorRegWarning,       "Color.RegWarning"
CStr szColorArgWarning,       "Color.ArgWarning"
CStr szColorLocWarning,       "Color.LocWarning"
CStr szColorFailure,          "Color.Failure"
CStr szColorBkground,         "Color.Background"
                              
CStr szOAT_Child,             "OAC_OAToolChild"
CStr szOAT_App,               "OAC_OAToolApplication"
CStr szPropEditIptor,         "OAP_OATEditIptor"
CStr szOpen,                  "open"
                              
CStrA szMethod,               "Method"
CStrA szMethodEnd,            "MethodEnd"
CStrA szProc,                 "proc"
CStrA szEndp,                 "endp"
CStrA szMacro,                "macro"
CStrA szEndm,                 "endm"
CStrA szUses,                 "uses"
CStrA szLocal,                "local"
                              
CStrA szComment,              "Comment"
CStrA szANNOTATION,           "ANNOTATION"
CStrA szUse,                  "use"
CStrA szPrv,                  "prv"
CStrA szUsing,                "using"
                              
CStrA szDot,                  "."
                              
;Control ID                   
RICHEDITID                    equ   250
                              
ZOOM_BASE                     equ   64
ZOOM_MIN                      equ   1
ZOOM_MAX                      equ   320                 ;Max reachable value using the mousewheel
ZOOM_DEFAULT                  equ   64
ZOOM_STEP                     equ   8
                              
;Object IDs                   
OAT_APP_ID                    equ   100000
OAT_CLIENT_ID                 equ   100001
OAT_CHILD_ID                  equ   100002
REDIT_IPTOR_ID                equ   100003
                              
;Default colors               
OAT_COLOR_NOTIFICATION        equ   $RGB(000,000,000)
OAT_COLOR_INFORMATION         equ   $RGB(128,128,128)
OAT_COLOR_REG_ERROR           equ   $RGB(255,000,000)
OAT_COLOR_REG_WARNING         equ   $RGB(192,128,255)
OAT_COLOR_ARG_WARNING         equ   $RGB(128,128,255)
OAT_COLOR_LOC_WARNING         equ   $RGB(000,128,255)
OAT_COLOR_FAILURE             equ   $RGB(255,128,064)
OAT_COLOR_BKGROUND            equ   $RGB(255,255,255)
OAT_COLOR_APP_LOCK            equ   $RGB(255,128,000)

.const
ProcAttrList label PSTRINGA                             ;Sorted by appearance probability
PSTRINGA $OfsTStrA("PRIVATE")
PSTRINGA $OfsTStrA("PUBLIC")
PSTRINGA $OfsTStrA("EXPORT")
PSTRINGA $OfsTStrA("STDCALL")
PSTRINGA $OfsTStrA("SYSCALL")
PSTRINGA $OfsTStrA("FASTCALL")
PSTRINGA $OfsTStrA("VECTORCALL")
PSTRINGA $OfsTStrA("C")
PSTRINGA $OfsTStrA("BASIC")
PSTRINGA $OfsTStrA("FORTRAN")
PSTRINGA $OfsTStrA("PASCAL")
PSTRINGA $OfsTStrA("NEAR")
PSTRINGA $OfsTStrA("FAR")
PSTRINGA NULL

MacroBlockList label PSTRINGA                           ;Sorted by appearance probability
PSTRINGA $OfsTStrA("REPEAT")
PSTRINGA $OfsTStrA("WHILE")
PSTRINGA $OfsTStrA("FOR")
PSTRINGA $OfsTStrA("FORC")
PSTRINGA $OfsTStrA("REPT")
PSTRINGA $OfsTStrA("IRP")
PSTRINGA $OfsTStrA("IRPC")
PSTRINGA NULL
