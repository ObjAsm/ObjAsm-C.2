; ==================================================================================================
; Title:      SAPI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Sound API 5.1.
; Notes:      Version 1.0.0, October 2017
;               - First release. Generated using COMView (www.japheth.de), NaN's header files
;                 translated and edited manually.
; ==================================================================================================


sTLBID_SpeechLib                  textequ <C866CA3A-32F7-11D2-9602-00C04F8EE628>
_MajorVer_SpeechLib equ 5
_MinorVer_SpeechLib equ 0

LPUNKNOWN equ <LPIUNKNOWN>

sCLSID_SpNotifyTranslator         textequ <E2AE5372-5D40-11D2-960E-00C04F8EE628>
sCLSID_SpObjectTokenCategory      textequ <A910187F-0C7A-45AC-92CC-59EDAFB77B53>
sCLSID_SpObjectToken              textequ <EF411752-3736-4CB4-9C8C-8EF4CCB58EFE>
sCLSID_SpResourceManager          textequ <96749373-3391-11D2-9EE3-00C04F797396>
sCLSID_SpStreamFormatConverter    textequ <7013943A-E2EC-11D2-A086-00C04F8EF9B5>
sCLSID_SpMMAudioEnum              textequ <AB1890A0-E91F-11D2-BB91-00C04F8EE6C0>
sCLSID_SpMMAudioIn                textequ <CF3D2E50-53F2-11D2-960C-00C04F8EE628>
sCLSID_SpMMAudioOut               textequ <A8C680EB-3D32-11D2-9EE7-00C04F797396>
sCLSID_SpRecPlayAudio             textequ <FEE225FC-7AFD-45E9-95D0-5A318079D911>
sCLSID_SpStream                   textequ <715D9C59-4442-11D2-9605-00C04F8EE628>
sCLSID_SpVoice                    textequ <96749377-3391-11D2-9EE3-00C04F797396>
sCLSID_SpSharedRecoContext        textequ <47206204-5ECA-11D2-960F-00C04F8EE628>
sCLSID_SpInprocRecognizer         textequ <41B89B6B-9399-11D2-9623-00C04F8EE628>
sCLSID_SpSharedRecognizer         textequ <3BEE4890-4FE9-4A37-8C1E-5E7E12791C1F>
sCLSID_SpLexicon                  textequ <0655E396-25D0-11D3-9C26-00C04F8EF87C>
sCLSID_SpUnCompressedLexicon      textequ <C9E37C15-DF92-4727-85D6-72E5EEB6995A>
sCLSID_SpCompressedLexicon        textequ <90903716-2F42-11D3-9C26-00C04F8EF87C>
sCLSID_SpPhoneConverter           textequ <9185F743-1143-4C28-86B5-BFF14F20E5C8>
sCLSID_SpNullPhoneConverter       textequ <455F24E9-7396-4A16-9715-7C0FDBE3EFE3>
sCLSID_SpTextSelectionInformation textequ <0F92030A-CBFD-4AB8-A164-FF5985547FF6>
sCLSID_SpPhraseInfoBuilder        textequ <C23FC28D-C55F-4720-8B32-91F73C2BD5D1>
sCLSID_SpAudioFormat              textequ <9EF96870-E160-4792-820D-48CF0649E4EC>
sCLSID_SpWaveFormatEx             textequ <C79A574C-63BE-44B9-801F-283F87F898BE>
sCLSID_SpInProcRecoContext        textequ <73AD6842-ACE0-45E8-A4DD-8795881A2C2A>
sCLSID_SpCustomStream             textequ <8DBEF13F-1948-4AA8-8CF0-048EEBED95D8>
sCLSID_SpFileStream               textequ <947812B3-2AE1-4644-BA86-9E90DED7EC91>
sCLSID_SpMemoryStream             textequ <5FB7EF7D-DFF4-468A-B6B7-2FCBD188F994>


SPF_DEFAULT                 equ 0
SPF_ASYNC                   equ 1
SPF_PURGEBEFORESPEAK        equ 2
SPF_IS_FILENAME             equ 4
SPF_IS_XML                  equ 8
SPF_IS_NOT_XML              equ 16
SPF_PERSIST_XML             equ 32
SPF_NLP_SPEAK_PUNC          equ 64
SPF_NLP_MASK                equ SPF_NLP_SPEAK_PUNC
SPF_VOICE_MASK              equ SPF_ASYNC or SPF_PURGEBEFORESPEAK or SPF_IS_FILENAME or  \
                                SPF_IS_XML or SPF_IS_NOT_XML or SPF_NLP_MASK or SPF_PERSIST_XML
SPF_UNUSED_FLAGS            equ NOT SPF_VOICE_MASK

;User Interface WIDE strings (UNICODE)
SPDUI_EngineProperties                textequ <"EngineProperties">
SPDUI_AddRemoveWord                   textequ <"AddRemoveWord">
SPDUI_UserTraining                    textequ <"UserTraining">
SPDUI_MicTraining                     textequ <"MicTraining">
SPDUI_RecoProfileProperties           textequ <"RecoProfileProperties">
SPDUI_AudioProperties                 textequ <"AudioProperties">
SPDUI_AudioVolume                     textequ <"AudioVolume">

;SpeechStringConstants WIDE strings (UNICODE)
SpeechRegistryUserRoot                textequ <"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech">
SpeechRegistryLocalMachineRoot        textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech">
SpeechCategoryAudioOut                textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput">
SpeechCategoryAudioIn                 textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput">
SpeechCategoryVoices                  textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices">
SpeechCategoryRecognizers             textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Recognizers">
SpeechCategoryAppLexicons             textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AppLexicons">
SpeechCategoryPhoneConverters         textequ <"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\PhoneConverters">
SpeechCategoryRecoProfiles            textequ <"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\RecoProfiles">
SpeechTokenIdUserLexicon              textequ <"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserLexicon">
SpeechTokenValueCLSID                 textequ <"CLSID">
SpeechTokenKeyFiles                   textequ <"Files">
SpeechTokenKeyUI                      textequ <"UI">
SpeechTokenKeyAttributes              textequ <"Attributes">
SpeechVoiceCategoryTTSRate            textequ <"DefaultTTSRate">
SpeechPropertyResourceUsage           textequ <"ResourceUsage">
SpeechPropertyHighConfidenceThreshold textequ <"HighConfidenceThreshold">
SpeechPropertyNormalConfidenceThreshold textequ <"NormalConfidenceThreshold">
SpeechPropertyLowConfidenceThreshold  textequ <"LowConfidenceThreshold">
SpeechPropertyResponseSpeed           textequ <"ResponseSpeed">
SpeechPropertyComplexResponseSpeed    textequ <"ComplexResponseSpeed">
SpeechPropertyAdaptationOn            textequ <"AdaptationOn">
SpeechDictationTopicSpelling          textequ <"Spelling">
SpeechGrammarTagWildcard              textequ <"...">
SpeechGrammarTagDictation             textequ <"*">
SpeechGrammarTagUnlimitedDictation    textequ <"*+">
SpeechEngineProperties                textequ <"EngineProperties">
SpeechAddRemoveWord                   textequ <"AddRemoveWord">
SpeechUserTraining                    textequ <"UserTraining">
SpeechMicTraining                     textequ <"MicTraining">
SpeechRecoProfileProperties           textequ <"RecoProfileProperties">
SpeechAudioProperties                 textequ <"AudioProperties">
SpeechAudioVolume                     textequ <"AudioVolume">
SpeechVoiceSkipTypeSentence           textequ <"Sentence">
SpeechAudioFormatGUIDWave             textequ <"{C31ADBAE-527F-4ff5-A230-F62BB61FF70C}">
SpeechAudioFormatGUIDText             textequ <"{7CEEF9F9-3D13-11d2-9EE7-00C04F797396}">

;SpeechDataKeyLocation enumeration
SpeechDataKeyLocation typedef SDWORD
SDKLDefaultLocation         equ  0
SDKLCurrentUser             equ  1
SDKLLocalMachine            equ  2
SDKLCurrentConfig           equ  5

;SpeechTokenContext enumeration
SpeechTokenContext typedef SDWORD
STCInprocServer             equ  1
STCInprocHandler            equ  2
STCLocalServer              equ  4
STCRemoteServer             equ  16      ;=010h
STCAll                      equ  23      ;=017h

;SpeechTokenShellFolder enumeration
SpeechTokenShellFolder typedef SDWORD
STSF_AppData                equ  26      ;=01Ah
STSF_LocalAppData           equ  28      ;=01Ch
STSF_CommonAppData          equ  35      ;=023h
STSF_FlagCreate             equ  32768   ;=08000h

;SpeechAudioState enumeration
SpeechAudioState typedef SDWORD
SASClosed                   equ  0
SASStop                     equ  1
SASPause                    equ  2
SASRun                      equ  3

;SpeechAudioFormatType enumeration
SpeechAudioFormatType typedef SDWORD
SAFTDefault                 equ  -1
SAFTNoAssignedFormat        equ  0
SAFTText                    equ  1
SAFTNonStandardFormat       equ  2
SAFTExtendedAudioFormat     equ  3
SAFT8kHz8BitMono            equ  4
SAFT8kHz8BitStereo          equ  5
SAFT8kHz16BitMono           equ  6
SAFT8kHz16BitStereo         equ  7
SAFT11kHz8BitMono           equ  8
SAFT11kHz8BitStereo         equ  9
SAFT11kHz16BitMono          equ  10
SAFT11kHz16BitStereo        equ  11
SAFT12kHz8BitMono           equ  12
SAFT12kHz8BitStereo         equ  13
SAFT12kHz16BitMono          equ  14
SAFT12kHz16BitStereo        equ  15
SAFT16kHz8BitMono           equ  16      ;=010h
SAFT16kHz8BitStereo         equ  17      ;=011h
SAFT16kHz16BitMono          equ  18      ;=012h
SAFT16kHz16BitStereo        equ  19      ;=013h
SAFT22kHz8BitMono           equ  20      ;=014h
SAFT22kHz8BitStereo         equ  21      ;=015h
SAFT22kHz16BitMono          equ  22      ;=016h
SAFT22kHz16BitStereo        equ  23      ;=017h
SAFT24kHz8BitMono           equ  24      ;=018h
SAFT24kHz8BitStereo         equ  25      ;=019h
SAFT24kHz16BitMono          equ  26      ;=01Ah
SAFT24kHz16BitStereo        equ  27      ;=01Bh
SAFT32kHz8BitMono           equ  28      ;=01Ch
SAFT32kHz8BitStereo         equ  29      ;=01Dh
SAFT32kHz16BitMono          equ  30      ;=01Eh
SAFT32kHz16BitStereo        equ  31      ;=01Fh
SAFT44kHz8BitMono           equ  32      ;=020h
SAFT44kHz8BitStereo         equ  33      ;=021h
SAFT44kHz16BitMono          equ  34      ;=022h
SAFT44kHz16BitStereo        equ  35      ;=023h
SAFT48kHz8BitMono           equ  36      ;=024h
SAFT48kHz8BitStereo         equ  37      ;=025h
SAFT48kHz16BitMono          equ  38      ;=026h
SAFT48kHz16BitStereo        equ  39      ;=027h
SAFTTrueSpeech_8kHz1BitMono equ  40      ;=028h
SAFTCCITT_ALaw_8kHzMono     equ  41      ;=029h
SAFTCCITT_ALaw_8kHzStereo   equ  42      ;=02Ah
SAFTCCITT_ALaw_11kHzMono    equ  43      ;=02Bh
SAFTCCITT_ALaw_11kHzStereo  equ  44      ;=02Ch
SAFTCCITT_ALaw_22kHzMono    equ  45      ;=02Dh
SAFTCCITT_ALaw_22kHzStereo  equ  46      ;=02Eh
SAFTCCITT_ALaw_44kHzMono    equ  47      ;=02Fh
SAFTCCITT_ALaw_44kHzStereo  equ  48      ;=030h
SAFTCCITT_uLaw_8kHzMono     equ  49      ;=031h
SAFTCCITT_uLaw_8kHzStereo   equ  50      ;=032h
SAFTCCITT_uLaw_11kHzMono    equ  51      ;=033h
SAFTCCITT_uLaw_11kHzStereo  equ  52      ;=034h
SAFTCCITT_uLaw_22kHzMono    equ  53      ;=035h
SAFTCCITT_uLaw_22kHzStereo  equ  54      ;=036h
SAFTCCITT_uLaw_44kHzMono    equ  55      ;=037h
SAFTCCITT_uLaw_44kHzStereo  equ  56      ;=038h
SAFTADPCM_8kHzMono          equ  57      ;=039h
SAFTADPCM_8kHzStereo        equ  58      ;=03Ah
SAFTADPCM_11kHzMono         equ  59      ;=03Bh
SAFTADPCM_11kHzStereo       equ  60      ;=03Ch
SAFTADPCM_22kHzMono         equ  61      ;=03Dh
SAFTADPCM_22kHzStereo       equ  62      ;=03Eh
SAFTADPCM_44kHzMono         equ  63      ;=03Fh
SAFTADPCM_44kHzStereo       equ  64      ;=040h
SAFTGSM610_8kHzMono         equ  65      ;=041h
SAFTGSM610_11kHzMono        equ  66      ;=042h
SAFTGSM610_22kHzMono        equ  67      ;=043h
SAFTGSM610_44kHzMono        equ  68      ;=044h

;SpeechStreamSeekPositionType enumeration
SpeechStreamSeekPositionType typedef SDWORD
SSSPTRelativeToStart            equ  0
SSSPTRelativeToCurrentPosition  equ  1
SSSPTRelativeToEnd              equ  2

;SpeechStreamFileMode enumeration
SpeechStreamFileMode typedef SDWORD
SSFMOpenForRead             equ  0
SSFMOpenReadWrite           equ  1
SSFMCreate                  equ  2
SSFMCreateForWrite          equ  3

;SpeechRunState enumeration
SpeechRunState typedef SDWORD
SRSEDone                     equ  1
SRSEIsSpeaking               equ  2

;SpeechVoiceEvents enumeration
SpeechVoiceEvents typedef SDWORD
SVEStartInputStream         equ  2
SVEEndInputStream           equ  4
SVEVoiceChange              equ  8
SVEBookmark                 equ  16      ;=010h
SVEWordBoundary             equ  32      ;=020h
SVEPhoneme                  equ  64      ;=040h
SVESentenceBoundary         equ  128     ;=080h
SVEViseme                   equ  256     ;=0100h
SVEAudioLevel               equ  512     ;=0200h
SVEPrivate                  equ  32768   ;=08000h
SVEAllEvents                equ  33790   ;=083FEh

;SpeechVoicePriority enumeration
SpeechVoicePriority typedef SDWORD
SVPNormal                   equ  0
SVPAlert                    equ  1
SVPOver                     equ  2

;SpeechVoiceSpeakFlags enumeartion
SpeechVoiceSpeakFlags typedef SDWORD
SVSFDefault                 equ  0
SVSFlagsAsync               equ  1
SVSFPurgeBeforeSpeak        equ  2
SVSFIsFilename              equ  4
SVSFIsXML                   equ  8
SVSFIsNotXML                equ  16      ;=010h
SVSFPersistXML              equ  32      ;=020h
SVSFNLPSpeakPunc            equ  64      ;=040h
SVSFNLPMask                 equ  64      ;=040h
SVSFVoiceMask               equ  127     ;=07Fh
SVSFUnusedFlags             equ  -128    ;=0FFFFFF80h

;SpeechVisemeFeature enumeration
SpeechVisemeFeature typedef SDWORD
SVF_None                    equ  0
SVF_Stressed                equ  1
SVF_Emphasis                equ  2

;SpeechVisemeType enumeration
SpeechVisemeType typedef SDWORD
SVP_0                       equ  0
SVP_1                       equ  1
SVP_2                       equ  2
SVP_3                       equ  3
SVP_4                       equ  4
SVP_5                       equ  5
SVP_6                       equ  6
SVP_7                       equ  7
SVP_8                       equ  8
SVP_9                       equ  9
SVP_10                      equ  10
SVP_11                      equ  11
SVP_12                      equ  12
SVP_13                      equ  13
SVP_14                      equ  14
SVP_15                      equ  15
SVP_16                      equ  16      ;=010h
SVP_17                      equ  17      ;=011h
SVP_18                      equ  18      ;=012h
SVP_19                      equ  19      ;=013h
SVP_20                      equ  20      ;=014h
SVP_21                      equ  21      ;=015h

;SpeechRecognizerState enumeration
SpeechRecognizerState typedef SDWORD
SRSInactive                 equ  0
SRSActive                   equ  1
SRSActiveAlways             equ  2
SRSInactiveWithPurge        equ  3

;SpeechInterference enumeration
SpeechInterference typedef SDWORD
SINone                      equ  0
SINoise                     equ  1
SINoSignal                  equ  2
SITooLoud                   equ  3
SITooQuiet                  equ  4
SITooFast                   equ  5
SITooSlow                   equ  6

;SpeechRecoEvents enumeration
SpeechRecoEvents typedef SDWORD
SREStreamEnd                equ  1
SRESoundStart               equ  2
SRESoundEnd                 equ  4
SREPhraseStart              equ  8
SRERecognition              equ  16      ;=010h
SREHypothesis               equ  32      ;=020h
SREBookmark                 equ  64      ;=040h
SREPropertyNumChange        equ  128     ;=080h
SREPropertyStringChange     equ  256     ;=0100h
SREFalseRecognition         equ  512     ;=0200h
SREInterference             equ  1024    ;=0400h
SRERequestUI                equ  2048    ;=0800h
SREStateChange              equ  4096    ;=01000h
SREAdaptation               equ  8192    ;=02000h
SREStreamStart              equ  16384   ;=04000h
SRERecoOtherContext         equ  32768   ;=08000h
SREAudioLevel               equ  65536   ;=010000h
SREPrivate                  equ  262144  ;=040000h
SREAllEvents                equ  393215  ;=05FFFFh

;SpeechRecoContextState enumeration
SpeechRecoContextState typedef SDWORD
SRCS_Disabled               equ  0
SRCS_Enabled                equ  1

;SpeechRetainedAudioOptions enumeration
SpeechRetainedAudioOptions typedef SDWORD
SRAONone                    equ  0
SRAORetainAudio             equ  1

;SpeechGrammarState enumeration
SpeechGrammarState typedef SDWORD
SGSEnabled                  equ  1
SGSDisabled                 equ  0
SGSExclusive                equ  3

;SpeechRuleAttributes enumeration

SpeechRuleAttributes typedef SDWORD
SRATopLevel                 equ  1
SRADefaultToActive          equ  2
SRAExport                   equ  4
SRAImport                   equ  8
SRAInterpreter              equ  16      ;=010h
SRADynamic                  equ  32      ;=020h

;SpeechGrammarRuleStateTransitionType enumeration
SpeechGrammarRuleStateTransitionType typedef SDWORD
SGRSTTEpsilon               equ  0
SGRSTTWord                  equ  1
SGRSTTRule                  equ  2
SGRSTTDictation             equ  3
SGRSTTWildcard              equ  4
SGRSTTTextBuffer            equ  5

;SpeechGrammarWordType enumeration
SpeechGrammarWordType typedef SDWORD
SGDisplay                   equ  0
SGLexical                   equ  1
SGPronounciation            equ  2

;SpeechSpecialTransitionType enumeration
SpeechSpecialTransitionType typedef SDWORD
SSTTWildcard                equ  1
SSTTDictation               equ  2
SSTTTextBuffer              equ  3

;SpeechLoadOption enumeration
SpeechLoadOption typedef SDWORD
SLOStatic                   equ  0
SLODynamic                  equ  1

;SpeechRuleState enumeration
SpeechRuleState typedef SDWORD
SGDSInactive                equ  0
SGDSActive                  equ  1
SGDSActiveWithAutoPause     equ  3

;SpeechWordPronounceable enumeration
SpeechWordPronounceable typedef SDWORD
SWPUnknownWordUnpronounceable equ  0
SWPUnknownWordPronounceable   equ  1
SWPKnownWordPronounceable     equ  2

;SpeechEngineConfidence enumeration
SpeechEngineConfidence typedef SDWORD
SECLowConfidence            equ  -1
SECNormalConfidence         equ  0
SECHighConfidence           equ  1

;SpeechDisplayAttributes enumeration
SpeechDisplayAttributes typedef SDWORD
SDA_No_Trailing_Space       equ  0
SDA_One_Trailing_Space      equ  2
SDA_Two_Trailing_Spaces     equ  4
SDA_Consume_Leading_Spaces  equ  8

;SpeechDiscardType enumeration
SpeechDiscardType typedef SDWORD
SDTProperty                 equ  1
SDTReplacement              equ  2
SDTRule                     equ  4
SDTDisplayText              equ  8
SDTLexicalForm              equ  16      ;=010h
SDTPronunciation            equ  32      ;=020h
SDTAudio                    equ  64      ;=040h
SDTAlternates               equ  128     ;=080h
SDTAll                      equ  255      ;=0FFh

;SpeechBookmarkOptions enumeration
SpeechBookmarkOptions typedef SDWORD
SBONone                     equ  0
SBOPause                    equ  1

;SpeechFormatType enumeration
SpeechFormatType typedef SDWORD
SFTInput                    equ  0
SFTSREngine                 equ  1

;SpeechRecognitionType enumeration
SpeechRecognitionType typedef SDWORD
SRTStandard                 equ  0
SRTAutopause                equ  1
SRTEmulated                 equ  2

;SpeechLexiconType enumeration
SpeechLexiconType typedef SDWORD
SLTUser                     equ  1
SLTApp                      equ  2

;SpeechWordType enumeration
SpeechWordType typedef SDWORD
SWTAdded                    equ  1
SWTDeleted                  equ  2

;SpeechPartOfSpeech enumeration
SpeechPartOfSpeech typedef SDWORD
SPSNotOverriden             equ  -1
SPSUnknown                  equ  0
SPSNoun                     equ  4096       ;=01000h
SPSVerb                     equ  8192       ;=02000h
SPSModifier                 equ  12288      ;=03000h
SPSFunction                 equ  16384      ;=04000h
SPSInterjection             equ  20480      ;=05000h


;SpeechConstants enumeration, GUID={F3E092B2-6BDC-410F-BCB2-4C5ED4424180}
Speech_Default_Weight       equ  1.065353E+09
Speech_Max_Word_Length      equ  128      ;=080h
Speech_Max_Pron_Length      equ  384      ;=0180h
Speech_StreamPos_Asap       equ  0
Speech_StreamPos_RealTime   equ  -1
SpeechAllElements           equ  -1

;DISPID_SpeechDataKey enumeration
DISPID_SpeechDataKey typedef SDWORD
DISPID_SDKSetBinaryValue    equ  1
DISPID_SDKGetBinaryValue    equ  2
DISPID_SDKSetStringValue    equ  3
DISPID_SDKGetStringValue    equ  4
DISPID_SDKSetLongValue      equ  5
DISPID_SDKGetlongValue      equ  6
DISPID_SDKOpenKey           equ  7
DISPID_SDKCreateKey         equ  8
DISPID_SDKDeleteKey         equ  9
DISPID_SDKDeleteValue       equ  10
DISPID_SDKEnumKeys          equ  11
DISPID_SDKEnumValues        equ  12

;DISPID_SpeechObjectToken enumeration
DISPID_SpeechObjectToken typedef SDWORD
DISPID_SOTId                equ  1
DISPID_SOTDataKey           equ  2
DISPID_SOTCategory          equ  3
DISPID_SOTGetDescription    equ  4
DISPID_SOTSetId             equ  5
DISPID_SOTGetAttribute      equ  6
DISPID_SOTCreateInstance    equ  7
DISPID_SOTRemove            equ  8
DISPID_SOTGetStorageFileName    equ  9
DISPID_SOTRemoveStorageFileName equ  10
DISPID_SOTIsUISupported     equ  11
DISPID_SOTDisplayUI         equ  12
DISPID_SOTMatchesAttributes equ  13

;DISPID_SpeechObjectTokens enumeration
DISPID_SpeechObjectTokens typedef SDWORD
DISPID_SOTsCount            equ  1
DISPID_SOTsItem             equ  0
DISPID_SOTs_NewEnum         equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechObjectTokenCategory enumeration
DISPID_SpeechObjectTokenCategory typedef SDWORD
DISPID_SOTCId               equ  1
DISPID_SOTCDefault          equ  2
DISPID_SOTCSetId            equ  3
DISPID_SOTCGetDataKey       equ  4
DISPID_SOTCEnumerateTokens  equ  5

;DISPID_SpeechAudioFormat enumeration
DISPID_SpeechAudioFormat typedef SDWORD
DISPID_SAFType              equ  1
DISPID_SAFGuid              equ  2
DISPID_SAFGetWaveFormatEx   equ  3
DISPID_SAFSetWaveFormatEx   equ  4

;DISPID_SpeechBaseStream enumeration
DISPID_SpeechBaseStream typedef SDWORD
DISPID_SBSFormat            equ  1
DISPID_SBSRead              equ  2
DISPID_SBSWrite             equ  3
DISPID_SBSSeek              equ  4

;DISPID_SpeechAudio enumeration
DISPID_SpeechAudio typedef SDWORD
DISPID_SAStatus             equ  200      ;=0C8h
DISPID_SABufferInfo         equ  201      ;=0C9h
DISPID_SADefaultFormat      equ  202      ;=0CAh
DISPID_SAVolume             equ  203      ;=0CBh
DISPID_SABufferNotifySize   equ  204      ;=0CCh
DISPID_SAEventHandle        equ  205      ;=0CDh
DISPID_SASetState           equ  206      ;=0CEh

;DISPID_SpeechMMSysAudio enumeration
DISPID_SpeechMMSysAudio typedef SDWORD
DISPID_SMSADeviceId         equ  300      ;=012Ch
DISPID_SMSALineId           equ  301      ;=012Dh
DISPID_SMSAMMHandle         equ  302      ;=012Eh

;DISPID_SpeechFileStream enumeration
DISPID_SpeechFileStream typedef SDWORD
DISPID_SFSOpen              equ  100      ;=064h
DISPID_SFSClose             equ  101      ;=065h

;DISPID_SpeechCustomStream enumeration
DISPID_SpeechCustomStream typedef SDWORD
DISPID_SCSBaseStream        equ  100      ;=064h

;DISPID_SpeechMemoryStream enumeration
DISPID_SpeechMemoryStream typedef SDWORD
DISPID_SMSSetData           equ  100      ;=064h
DISPID_SMSGetData           equ  101      ;=065h

;DISPID_SpeechAudioStatus enumeration
DISPID_SpeechAudioStatus typedef SDWORD
DISPID_SASFreeBufferSpace   equ  1
DISPID_SASNonBlockingIO     equ  2
DISPID_SASState             equ  3
DISPID_SASCurrentSeekPosition   equ  4
DISPID_SASCurrentDevicePosition equ  5

;DISPID_SpeechAudioBufferInfo enumeration
DISPID_SpeechAudioBufferInfo typedef SDWORD
DISPID_SABIMinNotification  equ  1
DISPID_SABIBufferSize       equ  2
DISPID_SABIEventBias        equ  3

;DISPID_SpeechWaveFormatEx enumeration
DISPID_SpeechWaveFormatEx typedef SDWORD
DISPID_SWFEFormatTag        equ  1
DISPID_SWFEChannels         equ  2
DISPID_SWFESamplesPerSec    equ  3
DISPID_SWFEAvgBytesPerSec   equ  4
DISPID_SWFEBlockAlign       equ  5
DISPID_SWFEBitsPerSample    equ  6
DISPID_SWFEExtraData        equ  7

;DISPID_SpeechVoice enumeration
DISPID_SpeechVoice typedef SDWORD
DISPID_SVStatus             equ  1
DISPID_SVVoice              equ  2
DISPID_SVAudioOutput        equ  3
DISPID_SVAudioOutputStream  equ  4
DISPID_SVRate               equ  5
DISPID_SVVolume             equ  6
DISPID_SVAllowAudioOuputFormatChangesOnNextSet  equ  7
DISPID_SVEventInterests     equ  8
DISPID_SVPriority           equ  9
DISPID_SVAlertBoundary      equ  10
DISPID_SVSyncronousSpeakTimeout  equ  11
DISPID_SVSpeak              equ  12
DISPID_SVSpeakStream        equ  13
DISPID_SVPause              equ  14
DISPID_SVResume             equ  15
DISPID_SVSkip               equ  16      ;=010h
DISPID_SVGetVoices          equ  17      ;=011h
DISPID_SVGetAudioOutputs    equ  18      ;=012h
DISPID_SVWaitUntilDone      equ  19      ;=013h
DISPID_SVSpeakCompleteEvent equ  20      ;=014h
DISPID_SVIsUISupported      equ  21      ;=015h
DISPID_SVDisplayUI          equ  22      ;=016h

;DISPID_SpeechVoiceStatus enumeration
DISPID_SpeechVoiceStatus typedef SDWORD
DISPID_SVSCurrentStreamNumber     equ  1
DISPID_SVSLastStreamNumberQueued  equ  2
DISPID_SVSLastResult              equ  3
DISPID_SVSRunningState            equ  4
DISPID_SVSInputWordPosition       equ  5
DISPID_SVSInputWordLength         equ  6
DISPID_SVSInputSentencePosition   equ  7
DISPID_SVSInputSentenceLength     equ  8
DISPID_SVSLastBookmark            equ  9
DISPID_SVSLastBookmarkId          equ  10
DISPID_SVSPhonemeId               equ  11
DISPID_SVSVisemeId                equ  12

;DISPID_SpeechVoiceEvent enumeration
DISPID_SpeechVoiceEvent typedef SDWORD
DISPID_SVEStreamStart       equ  1
DISPID_SVEStreamEnd         equ  2
DISPID_SVEVoiceChange       equ  3
DISPID_SVEBookmark          equ  4
DISPID_SVEWord              equ  5
DISPID_SVEPhoneme           equ  6
DISPID_SVESentenceBoundary  equ  7
DISPID_SVEViseme            equ  8
DISPID_SVEAudioLevel        equ  9
DISPID_SVEEnginePrivate     equ  10

;DISPID_SpeechRecognizer enumeration
DISPID_SpeechRecognizer typedef SDWORD
DISPID_SRRecognizer         equ  1
DISPID_SRAllowAudioInputFormatChangesOnNextSet  equ  2
DISPID_SRAudioInput         equ  3
DISPID_SRAudioInputStream   equ  4
DISPID_SRIsShared           equ  5
DISPID_SRState              equ  6
DISPID_SRStatus             equ  7
DISPID_SRProfile            equ  8
DISPID_SREmulateRecognition equ  9
DISPID_SRCreateRecoContext  equ  10
DISPID_SRGetFormat          equ  11
DISPID_SRSetPropertyNumber  equ  12
DISPID_SRGetPropertyNumber  equ  13
DISPID_SRSetPropertyString  equ  14
DISPID_SRGetPropertyString  equ  15
DISPID_SRIsUISupported      equ  16      ;=010h
DISPID_SRDisplayUI          equ  17      ;=011h
DISPID_SRGetRecognizers     equ  18      ;=012h
DISPID_SVGetAudioInputs     equ  19      ;=013h
DISPID_SVGetProfiles        equ  20      ;=014h

;DISPID_SpeechRecognizerStatus enumeration
DISPID_SpeechRecognizerStatus typedef SDWORD
DISPID_SRSAudioStatus           equ  1
DISPID_SRSCurrentStreamPosition equ  2
DISPID_SRSCurrentStreamNumber   equ  3
DISPID_SRSNumberOfActiveRules   equ  4
DISPID_SRSClsidEngine           equ  5
DISPID_SRSSupportedLanguages    equ  6

;DISPID_SpeechRecoContext enumeration
DISPID_SpeechRecoContext typedef SDWORD
DISPID_SRCRecognizer          equ  1
DISPID_SRCAudioInInterferenceStatus  equ  2
DISPID_SRCRequestedUIType     equ  3
DISPID_SRCVoice               equ  4
DISPID_SRAllowVoiceFormatMatchingOnNextSet  equ  5
DISPID_SRCVoicePurgeEvent     equ  6
DISPID_SRCEventInterests      equ  7
DISPID_SRCCmdMaxAlternates    equ  8
DISPID_SRCState               equ  9
DISPID_SRCRetainedAudio       equ  10
DISPID_SRCRetainedAudioFormat equ  11
DISPID_SRCPause               equ  12
DISPID_SRCResume              equ  13
DISPID_SRCCreateGrammar       equ  14
DISPID_SRCCreateResultFromMemory  equ  15
DISPID_SRCBookmark            equ  16      ;=010h
DISPID_SRCSetAdaptationData   equ  17      ;=011h

;DISPIDSPRG enumeration
DISPIDSPRG typedef SDWORD
DISPID_SRGId                  equ  1
DISPID_SRGRecoContext         equ  2
DISPID_SRGState               equ  3
DISPID_SRGRules               equ  4
DISPID_SRGReset               equ  5
DISPID_SRGCommit              equ  6
DISPID_SRGCmdLoadFromFile     equ  7
DISPID_SRGCmdLoadFromObject   equ  8
DISPID_SRGCmdLoadFromResource equ  9
DISPID_SRGCmdLoadFromMemory   equ  10
DISPID_SRGCmdLoadFromProprietaryGrammar  equ  11
DISPID_SRGCmdSetRuleState     equ  12
DISPID_SRGCmdSetRuleIdState   equ  13
DISPID_SRGDictationLoad       equ  14
DISPID_SRGDictationUnload     equ  15
DISPID_SRGDictationSetState   equ  16      ;=010h
DISPID_SRGSetWordSequenceData equ  17      ;=011h
DISPID_SRGSetTextSelection    equ  18      ;=012h
DISPID_SRGIsPronounceable     equ  19      ;=013h

;DISPID_SpeechRecoContextEvents enumeration
DISPID_SpeechRecoContextEvents typedef SDWORD
DISPID_SRCEStartStream        equ  1
DISPID_SRCEEndStream          equ  2
DISPID_SRCEBookmark           equ  3
DISPID_SRCESoundStart         equ  4
DISPID_SRCESoundEnd           equ  5
DISPID_SRCEPhraseStart        equ  6
DISPID_SRCERecognition        equ  7
DISPID_SRCEHypothesis         equ  8
DISPID_SRCEPropertyNumberChange   equ  9
DISPID_SRCEPropertyStringChange   equ  10
DISPID_SRCEFalseRecognition   equ  11
DISPID_SRCEInterference       equ  12
DISPID_SRCERequestUI          equ  13
DISPID_SRCERecognizerStateChange  equ  14
DISPID_SRCEAdaptation         equ  15
DISPID_SRCERecognitionForOtherContext equ  16      ;=010h
DISPID_SRCEAudioLevel         equ  17      ;=011h
DISPID_SRCEEnginePrivate      equ  18      ;=012h

;DISPID_SpeechGrammarRule enumeration
DISPID_SpeechGrammarRule typedef SDWORD
DISPID_SGRAttributes          equ  1
DISPID_SGRInitialState        equ  2
DISPID_SGRName                equ  3
DISPID_SGRId                  equ  4
DISPID_SGRClear               equ  5
DISPID_SGRAddResource         equ  6
DISPID_SGRAddState            equ  7

;DISPID_SpeechGrammarRules enumeration
DISPID_SpeechGrammarRules typedef SDWORD
DISPID_SGRsCount              equ  1
DISPID_SGRsDynamic            equ  2
DISPID_SGRsAdd                equ  3
DISPID_SGRsCommit             equ  4
DISPID_SGRsCommitAndSave      equ  5
DISPID_SGRsFindRule           equ  6
DISPID_SGRsItem               equ  0
DISPID_SGRs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechGrammarRuleState enumeration
DISPID_SpeechGrammarRuleState typedef SDWORD
DISPID_SGRSRule               equ  1
DISPID_SGRSTransitions        equ  2
DISPID_SGRSAddWordTransition  equ  3
DISPID_SGRSAddRuleTransition  equ  4
DISPID_SGRSAddSpecialTransition  equ  5

;DISPID_SpeechGrammarRuleStateTransitions enumeration
DISPID_SpeechGrammarRuleStateTransitions typedef SDWORD
DISPID_SGRSTsCount            equ  1
DISPID_SGRSTsItem             equ  0
DISPID_SGRSTs_NewEnum         equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechGrammarRuleStateTransition enumeration
DISPID_SpeechGrammarRuleStateTransition typedef SDWORD
DISPID_SGRSTType              equ  1
DISPID_SGRSTText              equ  2
DISPID_SGRSTRule              equ  3
DISPID_SGRSTWeight            equ  4
DISPID_SGRSTPropertyName      equ  5
DISPID_SGRSTPropertyId        equ  6
DISPID_SGRSTPropertyValue     equ  7
DISPID_SGRSTNextState         equ  8

;DISPIDSPTSI enumeration
DISPIDSPTSI typedef SDWORD
DISPIDSPTSI_ActiveOffset      equ  1
DISPIDSPTSI_ActiveLength      equ  2
DISPIDSPTSI_SelectionOffset   equ  3
DISPIDSPTSI_SelectionLength   equ  4

;DISPID_SpeechRecoResult enumeration
DISPID_SpeechRecoResult typedef SDWORD
DISPID_SRRRecoContext         equ  1
DISPID_SRRTimes               equ  2
DISPID_SRRAudioFormat         equ  3
DISPID_SRRPhraseInfo          equ  4
DISPID_SRRAlternates          equ  5
DISPID_SRRAudio               equ  6
DISPID_SRRSpeakAudio          equ  7
DISPID_SRRSaveToMemory        equ  8
DISPID_SRRDiscardResultInfo   equ  9

;DISPID_SpeechPhraseBuilder enumeration
DISPID_SpeechPhraseBuilder typedef SDWORD
DISPID_SPPBRestorePhraseFromMemory  equ  1

;DISPID_SpeechRecoResultTimes enumeration
DISPID_SpeechRecoResultTimes typedef SDWORD
DISPID_SRRTStreamTime         equ  1
DISPID_SRRTLength             equ  2
DISPID_SRRTTickCount          equ  3
DISPID_SRRTOffsetFromStart    equ  4

;DISPID_SpeechPhraseAlternate enumeration
DISPID_SpeechPhraseAlternate typedef SDWORD
DISPID_SPARecoResult                equ  1
DISPID_SPAStartElementInResult      equ  2
DISPID_SPANumberOfElementsInResult  equ  3
DISPID_SPAPhraseInfo                equ  4
DISPID_SPACommit                    equ  5

;DISPID_SpeechPhraseAlternates enumeration
DISPID_SpeechPhraseAlternates typedef SDWORD
DISPID_SPAsCount              equ  1
DISPID_SPAsItem               equ  0
DISPID_SPAs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechPhraseInfo enumeration
DISPID_SpeechPhraseInfo typedef SDWORD
DISPID_SPILanguageId          equ  1
DISPID_SPIGrammarId           equ  2
DISPID_SPIStartTime           equ  3
DISPID_SPIAudioStreamPosition equ  4
DISPID_SPIAudioSizeBytes      equ  5
DISPID_SPIRetainedSizeBytes   equ  6
DISPID_SPIAudioSizeTime       equ  7
DISPID_SPIRule                equ  8
DISPID_SPIProperties          equ  9
DISPID_SPIElements            equ  10
DISPID_SPIReplacements        equ  11
DISPID_SPIEngineId            equ  12
DISPID_SPIEnginePrivateData   equ  13
DISPID_SPISaveToMemory        equ  14
DISPID_SPIGetText             equ  15
DISPID_SPIGetDisplayAttributes  equ  16      ;=010h

;DISPID_SpeechPhraseElement enumeration
DISPID_SpeechPhraseElement typedef SDWORD
DISPID_SPEAudioTimeOffset     equ  1
DISPID_SPEAudioSizeTime       equ  2
DISPID_SPEAudioStreamOffset   equ  3
DISPID_SPEAudioSizeBytes      equ  4
DISPID_SPERetainedStreamOffset  equ  5
DISPID_SPERetainedSizeBytes   equ  6
DISPID_SPEDisplayText         equ  7
DISPID_SPELexicalForm         equ  8
DISPID_SPEPronunciation       equ  9
DISPID_SPEDisplayAttributes   equ  10
DISPID_SPERequiredConfidence  equ  11
DISPID_SPEActualConfidence    equ  12
DISPID_SPEEngineConfidence    equ  13

;DISPID_SpeechPhraseElements enumeration
DISPID_SpeechPhraseElements typedef SDWORD
DISPID_SPEsCount              equ  1
DISPID_SPEsItem               equ  0
DISPID_SPEs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechPhraseReplacement enumeration
DISPID_SpeechPhraseReplacement typedef SDWORD
DISPID_SPRDisplayAttributes   equ  1
DISPID_SPRText                equ  2
DISPID_SPRFirstElement        equ  3
DISPID_SPRNumberOfElements    equ  4

;DISPID_SpeechPhraseReplacements enumeration
DISPID_SpeechPhraseReplacements typedef SDWORD
DISPID_SPRsCount              equ  1
DISPID_SPRsItem               equ  0
DISPID_SPRs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechPhraseProperty enumeration
DISPID_SpeechPhraseProperty typedef SDWORD
DISPID_SPPName                equ  1
DISPID_SPPId                  equ  2
DISPID_SPPValue               equ  3
DISPID_SPPFirstElement        equ  4
DISPID_SPPNumberOfElements    equ  5
DISPID_SPPEngineConfidence    equ  6
DISPID_SPPConfidence          equ  7
DISPID_SPPParent              equ  8
DISPID_SPPChildren            equ  9

;DISPID_SpeechPhraseProperties enumeration
DISPID_SpeechPhraseProperties typedef SDWORD
DISPID_SPPsCount              equ  1
DISPID_SPPsItem               equ  0
DISPID_SPPs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechPhraseRule enumeration
DISPID_SpeechPhraseRule typedef SDWORD
DISPID_SPRuleName             equ  1
DISPID_SPRuleId               equ  2
DISPID_SPRuleFirstElement     equ  3
DISPID_SPRuleNumberOfElements equ  4
DISPID_SPRuleParent           equ  5
DISPID_SPRuleChildren         equ  6
DISPID_SPRuleConfidence       equ  7
DISPID_SPRuleEngineConfidence equ  8

;DISPID_SpeechPhraseRules enumeration
DISPID_SpeechPhraseRules typedef SDWORD
DISPID_SPRulesCount           equ  1
DISPID_SPRulesItem            equ  0
DISPID_SPRules_NewEnum        equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechLexicon enumeration
DISPID_SpeechLexicon typedef SDWORD
DISPID_SLGenerationId         equ  1
DISPID_SLGetWords             equ  2
DISPID_SLAddPronunciation     equ  3
DISPID_SLAddPronunciationByPhoneIds  equ  4
DISPID_SLRemovePronunciation  equ  5
DISPID_SLRemovePronunciationByPhoneIds  equ  6
DISPID_SLGetPronunciations    equ  7
DISPID_SLGetGenerationChange  equ  8

;DISPID_SpeechLexiconWords enumeration
DISPID_SpeechLexiconWords typedef SDWORD
DISPID_SLWsCount              equ  1
DISPID_SLWsItem               equ  0
DISPID_SLWs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechLexiconWord enumeration
DISPID_SpeechLexiconWord typedef SDWORD
DISPID_SLWLangId              equ  1
DISPID_SLWType                equ  2
DISPID_SLWWord                equ  3
DISPID_SLWPronunciations      equ  4

;DISPID_SpeechLexiconProns enumeration

DISPID_SpeechLexiconProns typedef SDWORD
DISPID_SLPsCount              equ  1
DISPID_SLPsItem               equ  0
DISPID_SLPs_NewEnum           equ  -4      ;=0FFFFFFFCh

;DISPID_SpeechLexiconPronunciation enumeration
DISPID_SpeechLexiconPronunciation typedef SDWORD
DISPID_SLPType                equ  1
DISPID_SLPLangId              equ  2
DISPID_SLPPartOfSpeech        equ  3
DISPID_SLPPhoneIds            equ  4
DISPID_SLPSymbolic            equ  5

;DISPID_SpeechPhoneConverter enumeration
DISPID_SpeechPhoneConverter typedef SDWORD
DISPID_SPCLangId              equ  1
DISPID_SPCPhoneToId           equ  2
DISPID_SPCIdToPhone           equ  3

;SPDATAKEYLOCATION enumeration
SPDATAKEYLOCATION typedef SDWORD
SPDKL_DefaultLocation         equ  0
SPDKL_CurrentUser             equ  1
SPDKL_LocalMachine            equ  2
SPDKL_CurrentConfig           equ  5

;SPAUDIOSTATE enumeration
SPAUDIOSTATE typedef SDWORD
SPAS_CLOSED                   equ  0
SPAS_STOP                     equ  1
SPAS_PAUSE                    equ  2
SPAS_RUN                      equ  3

;SPFILEMODE enumeration
SPFILEMODE typedef SDWORD
SPFM_OPEN_READONLY            equ  0
SPFM_OPEN_READWRITE           equ  1
SPFM_CREATE                   equ  2
SPFM_CREATE_ALWAYS            equ  3
SPFM_NUM_MODES                equ  4

;END_SR_STREAM event (in WPARAM) enumeration
SPESF_NONE                    equ 0
SPESF_STREAM_RELEASED         equ 1

;Viseme features
SPVFEATURE_STRESSED           equ 1
SPVFEATURE_EMPHASIS           equ 2

;SPVISEMES enumeration
SPVISEMES typedef SDWORD
SP_VISEME_0                   equ  0
SP_VISEME_1                   equ  1
SP_VISEME_2                   equ  2
SP_VISEME_3                   equ  3
SP_VISEME_4                   equ  4
SP_VISEME_5                   equ  5
SP_VISEME_6                   equ  6
SP_VISEME_7                   equ  7
SP_VISEME_8                   equ  8
SP_VISEME_9                   equ  9
SP_VISEME_10                  equ  10
SP_VISEME_11                  equ  11
SP_VISEME_12                  equ  12
SP_VISEME_13                  equ  13
SP_VISEME_14                  equ  14
SP_VISEME_15                  equ  15
SP_VISEME_16                  equ  16      ;=010h
SP_VISEME_17                  equ  17      ;=011h
SP_VISEME_18                  equ  18      ;=012h
SP_VISEME_19                  equ  19      ;=013h
SP_VISEME_20                  equ  20      ;=014h
SP_VISEME_21                  equ  21      ;=015h

;SPVPRIORITY enumeration
SPVPRIORITY typedef SDWORD
SPVPRI_NORMAL                 equ  0
SPVPRI_ALERT                  equ  1
SPVPRI_OVER                   equ  2

;SPEVENTLPARAMTYPE enumeration
SPET_LPARAM_IS_UNDEFINED      equ  0
SPET_LPARAM_IS_TOKEN          equ  1
SPET_LPARAM_IS_OBJECT         equ  2
SPET_LPARAM_IS_POINTER        equ  3
SPET_LPARAM_IS_STRING         equ  4

;SPEVENTENUM enumeration
SPEVENTENUM typedef SDWORD
SPEI_UNDEFINED                equ  0
;TTS engine
SPEI_START_INPUT_STREAM       equ  1
SPEI_END_INPUT_STREAM         equ  2
SPEI_VOICE_CHANGE             equ  3
SPEI_TTS_BOOKMARK             equ  4
SPEI_WORD_BOUNDARY            equ  5
SPEI_PHONEME                  equ  6
SPEI_SENTENCE_BOUNDARY        equ  7
SPEI_VISEME                   equ  8
SPEI_TTS_AUDIO_LEVEL          equ  9
;Engine vendors use these reserved bits
SPEI_TTS_PRIVATE              equ  15
SPEI_MIN_TTS                  equ  1
SPEI_MAX_TTS                  equ  15
;Speech Recognition
SPEI_END_SR_STREAM            equ  34      ;=022h
SPEI_SOUND_START              equ  35      ;=023h
SPEI_SOUND_END                equ  36      ;=024h
SPEI_PHRASE_START             equ  37      ;=025h
SPEI_RECOGNITION              equ  38      ;=026h
SPEI_HYPOTHESIS               equ  39      ;=027h
SPEI_SR_BOOKMARK              equ  40      ;=028h
SPEI_PROPERTY_NUM_CHANGE      equ  41      ;=029h
SPEI_PROPERTY_STRING_CHANGE   equ  42      ;=02Ah
SPEI_FALSE_RECOGNITION        equ  43      ;=02Bh
SPEI_INTERFERENCE             equ  44      ;=02Ch
SPEI_REQUEST_UI               equ  45      ;=02Dh
SPEI_RECO_STATE_CHANGE        equ  46      ;=02Eh
SPEI_ADAPTATION               equ  47      ;=02Fh
SPEI_START_SR_STREAM          equ  48      ;=030h
SPEI_RECO_OTHER_CONTEXT       equ  49      ;=031h
SPEI_SR_AUDIO_LEVEL           equ  50      ;=032h
SPEI_SR_PRIVATE               equ  52      ;=034h
SPEI_MIN_SR                   equ  34      ;=022h
SPEI_MAX_SR                   equ  52      ;=034h
SPEI_RESERVED1                equ  30      ;=01Eh
SPEI_RESERVED2                equ  33      ;=021h
SPEI_RESERVED3                equ  63      ;=03Fh

SPFEI_FLAGCHECK               equ (1 SHL SPEI_RESERVED1) or (1 SHL SPEI_RESERVED2)
SPFEI_ALL_TTS_EVENTS          equ 000000000000FFFEh or SPFEI_FLAGCHECK
SPFEI_ALL_SR_EVENTS           equ 001FFFFC00000000h or SPFEI_FLAGCHECK
SPFEI_ALL_EVENTS              equ 0EFFFFFFFFFFFFFFFh


; --------------------------------------------------------------------------------------------------
; Macro:     SPFEI
; Purpose:   Create a QWORD in edx::eax that identifies the event interest.
; Arguments: Arg1: Interest flag.

SPFEI macro SPEI_Flag:req
  if SPEI_Flag gt 31
    mov eax, 40000000h
    if SPEI_Flag gt 32
      mov edx, (1 shl (SPEI_Flag - 32)) or 00000002h
    else
      mov edx, 00000002h
    endif
  else
    mov eax, (1 shl SPEI_Flag) or 40000000h
    mov edx, 00000002h
  endif
endm


;SPRECOSTATE enumeration
SPRECOSTATE typedef SDWORD
SPRST_INACTIVE                equ  0
SPRST_ACTIVE                  equ  1
SPRST_ACTIVE_ALWAYS           equ  2
SPRST_INACTIVE_WITH_PURGE     equ  3
SPRST_NUM_STATES              equ  4

;SPWAVEFORMATTYPE enumeration
SPWAVEFORMATTYPE typedef SDWORD
SPWF_INPUT                    equ  0
SPWF_SRENGINE                 equ  1

;SPGRAMMARWORDTYPE enumeration
SPGRAMMARWORDTYPE typedef SDWORD
SPWT_DISPLAY                  equ  0
SPWT_LEXICAL                  equ  1
SPWT_PRONUNCIATION            equ  2

;SPLOADOPTIONS enumeration
SPLOADOPTIONS typedef SDWORD
SPLO_STATIC                   equ  0
SPLO_DYNAMIC                  equ  1

;SPRULESTATE enumeration
SPRULESTATE typedef SDWORD
SPRS_INACTIVE                 equ  0
SPRS_ACTIVE                   equ  1
SPRS_ACTIVE_WITH_AUTO_PAUSE   equ  3

;SPWORDPRONOUNCEABLE enumeration
SPWORDPRONOUNCEABLE typedef SDWORD
SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE equ  0
SPWP_UNKNOWN_WORD_PRONOUNCEABLE   equ  1
SPWP_KNOWN_WORD_PRONOUNCEABLE     equ  2

;SPGRAMMARSTATE enumeration
SPGRAMMARSTATE typedef SDWORD
SPGS_DISABLED                 equ  0
SPGS_ENABLED                  equ  1
SPGS_EXCLUSIVE                equ  3

;SPINTERFERENCE enumeration
SPINTERFERENCE typedef SDWORD
SPINTERFERENCE_NONE           equ  0
SPINTERFERENCE_NOISE          equ  1
SPINTERFERENCE_NOSIGNAL       equ  2
SPINTERFERENCE_TOOLOUD        equ  3
SPINTERFERENCE_TOOQUIET       equ  4
SPINTERFERENCE_TOOFAST        equ  5
SPINTERFERENCE_TOOSLOW        equ  6

;SPAUDIOOPTIONS enumeration
SPAUDIOOPTIONS typedef SDWORD
SPAO_NONE                     equ  0
SPAO_RETAIN_AUDIO             equ  1

;SPBOOKMARKOPTIONS enumeration
SPBOOKMARKOPTIONS typedef SDWORD
SPBO_NONE                     equ  0
SPBO_PAUSE                    equ  1

;SPCONTEXTSTATE enumeration
SPCONTEXTSTATE typedef SDWORD
SPCS_DISABLED                 equ  0
SPCS_ENABLED                  equ  1

;SPLEXICONTYPE enumeration
SPLEXICONTYPE typedef SDWORD
eLEXTYPE_USER                 equ 00000001h
eLEXTYPE_APP                  equ 00000002h
eLEXTYPE_RESERVED1            equ 00000004h
eLEXTYPE_RESERVED2            equ 00000008h
eLEXTYPE_RESERVED3            equ 00000010h
eLEXTYPE_RESERVED4            equ 00000020h
eLEXTYPE_RESERVED5            equ 00000040h
eLEXTYPE_RESERVED6            equ 00000080h
eLEXTYPE_RESERVED7            equ 00000100h
eLEXTYPE_RESERVED8            equ 00000200h
eLEXTYPE_RESERVED9            equ 00000400h
eLEXTYPE_RESERVED10           equ 00000800h
eLEXTYPE_PRIVATE1             equ 00001000h
eLEXTYPE_PRIVATE2             equ 00002000h
eLEXTYPE_PRIVATE3             equ 00004000h
eLEXTYPE_PRIVATE4             equ 00008000h
eLEXTYPE_PRIVATE5             equ 00010000h
eLEXTYPE_PRIVATE6             equ 00020000h
eLEXTYPE_PRIVATE7             equ 00040000h
eLEXTYPE_PRIVATE8             equ 00080000h
eLEXTYPE_PRIVATE9             equ 00100000h
eLEXTYPE_PRIVATE10            equ 00200000h
eLEXTYPE_PRIVATE11            equ 00400000h
eLEXTYPE_PRIVATE12            equ 00800000h
eLEXTYPE_PRIVATE13            equ 01000000h
eLEXTYPE_PRIVATE14            equ 02000000h
eLEXTYPE_PRIVATE15            equ 04000000h
eLEXTYPE_PRIVATE16            equ 08000000h
eLEXTYPE_PRIVATE17            equ 10000000h
eLEXTYPE_PRIVATE18            equ 20000000h
eLEXTYPE_PRIVATE19            equ 40000000h
eLEXTYPE_PRIVATE20            equ 80000000h

;SPPARTOFSPEECH enumeration
SPPARTOFSPEECH typedef SDWORD
SPPS_NotOverriden             equ  -1
SPPS_Unknown                  equ  0
SPPS_Noun                     equ  4096           ;=01000h
SPPS_Verb                     equ  8192           ;=02000h
SPPS_Modifier                 equ  12288          ;=03000h
SPPS_Function                 equ  16384          ;=04000h
SPPS_Interjection             equ  20480          ;=05000h

;SPWORDTYPE enumeration
SPWORDTYPE typedef SDWORD
eWORDTYPE_ADDED               equ  1
eWORDTYPE_DELETED             equ  2


SPPR_ALL_ELEMENTS             equ -1

SPREF_AutoPause               equ 1
SPREF_Emulated                equ 2

SPPS_NotOverriden             equ -1
SPPS_Unknown                  equ  0
SPPS_Noun                     equ 1000h
SPPS_Verb                     equ 2000h
SPPS_Modifier                 equ 3000h
SPPS_Function                 equ 4000h
SPPS_Interjection             equ 5000h

WORDTYPE_ADDED                equ 1
eWORDTYPE_DELETED             equ 2

SP_GETWHOLEPHRASE             equ SPPR_ALL_ELEMENTS
SPRR_ALL_ELEMENTS             equ SPPR_ALL_ELEMENTS

GID_DICTATION                 equ 0    ;ID for the dictation grammar
GID_DICTATIONCC               equ 1    ;ID for the C&C grammar that's active during dictation
GID_CC                        equ 2    ;ID for the C&C grammar that's active when dictation is no

SPWF_INPUT                    equ 0
SPWF_SRENGINE                 equ 1
SPRST_INACTIVE                equ 0
SPRST_ACTIVE                  equ 1
SPRST_ACTIVE_ALWAYS           equ 2
SPRST_INACTIVE_WITH_PURGE     equ 3
SPRST_NUM_STATES              equ 4

SPRAF_TopLevel                equ 1
SPRAF_Active                  equ 2
SPRAF_Export                  equ 4
SPRAF_Import                  equ 8
SPRAF_Interpreter             equ 16
SPRAF_Dynamic                 equ 32
SPRAF_AutoPause               equ 65536

SPWT_DISPLAY                  equ 0
SPWT_LEXICAL                  equ 1
SPWT_PRONUNCIATION            equ 2

SPRS_DONE                     equ 1
SPRS_IS_SPEAKING              equ 2

SPMIN_VOLUME                  equ 0
SPMAX_VOLUME                  equ 100
SPMIN_RATE                    equ -10
SPMAX_RATE                    equ 10

SPVPRI_NORMAL                 equ  0
SPVPRI_ALERT                  equ  1
SPVPRI_OVER                   equ  2

SPVA_Speak                    equ 0
SPVA_Silence                  equ 1
SPVA_Pronounce                equ 2
SPVA_Bookmark                 equ 3
SPVA_SpellOut                 equ 4
SPVA_Section                  equ 5
SPVA_ParseUnknownTag          equ 6

SPAF_ONE_TRAILING_SPACE       equ 02h
SPAF_TWO_TRAILING_SPACES      equ 04h
SPAF_CONSUME_LEADING_SPACES   equ 08h
SPAF_ALL                      equ 0fh

SPDF_PROPERTY                 equ 1
SPDF_REPLACEMENT              equ 2
SPDF_RULE                     equ 4
SPDF_DISPLAYTEXT              equ 8
SPDF_LEXICALFORM              equ 10h
SPDF_PRONUNCIATION            equ 20h
SPDF_AUDIO                    equ 40h
SPDF_ALTERNATES               equ 80h
SPDF_ALL                      equ 0ffh

SP_STREAMPOS_ASAP             equ 0
SP_STREAMPOS_REALTIME         equ -1

SP_MAX_LANGIDS                equ 20


SPPHRASEELEMENT struc 4
  ulAudioTimeOffset       DWORD     ?
  ulAudioSizeTime         DWORD     ?
  ulAudioStreamOffset     DWORD     ?
  ulAudioSizeBytes        DWORD     ?
  ulRetainedStreamOffset  DWORD     ?
  ulRetainedSizeBytes     DWORD     ?
  pszDisplayText          POINTER   ?
  pszLexicalForm          POINTER   ?
  pszPronunciation        POINTER   ?
  bDisplayAttributes      BYTE      ?
  RequiredConfidence      SBYTE     ?
  ActualConfidence        SBYTE     ?
  reserved                BYTE      ?
  SREngineConfidence      REAL4     ?
SPPHRASEELEMENT ends


SPPHRASEREPLACEMENT struc 4
  bDisplayAttributes      BYTE      ?
  pszReplacementText      POINTER   ?
  ulFirstElement          DWORD     ?
  ulCountOfElements       DWORD     ?
SPPHRASEREPLACEMENT ends


SPSERIALIZEDPHRASE struc 4
  ulSerializedSize        DWORD     ?
SPSERIALIZEDPHRASE ends


_RemotableHandle struc 4
  fContext                SDWORD    ?
  u                       DWORD     ?
_RemotableHandle ends


SPPROPERTYINFO struc 8
  pszName                 POINTER   ?
  ulId                    DWORD     ?
  pszValue                POINTER   ?
  vValue                  VARIANT   <?>
SPPROPERTYINFO ends


SPAUDIOSTATUS struc 8
  cbFreeBuffSpace         SDWORD    ?
  cbNonBlockingIO         DWORD     ?
  State                   SPAUDIOSTATE  ?
  CurSeekPos              QWORD     ?
  CurDevicePos            QWORD     ?
  dwReserved1             DWORD     ?
  dwReserved2             DWORD     ?
SPAUDIOSTATUS ends


SPBINARYGRAMMAR struc 4
  ulTotalSerializedSize   DWORD     ?
SPBINARYGRAMMAR ends


SPAUDIOBUFFERINFO struc 4
  ulMsMinNotification     DWORD     ?
  ulMsBufferSize          DWORD     ?
  ulMsEventBias           DWORD     ?
SPAUDIOBUFFERINFO ends


SPTEXTSELECTIONINFO struc 4
  ulStartActiveOffset     DWORD     ?
  cchActiveChars          DWORD     ?
  ulStartSelection        DWORD     ?
  cchSelection            DWORD     ?
SPTEXTSELECTIONINFO ends


SPVOICESTATUS struc 4
  ulCurrentStream         DWORD     ?
  ulLastStreamQueued      DWORD     ?
  hrLastResult            HRESULT   ?
  dwRunningState          DWORD     ?
  ulInputWordPos          DWORD     ?
  ulInputWordLen          DWORD     ?
  ulInputSentPos          DWORD     ?
  ulInputSentLen          DWORD     ?
  lBookmarkId             SDWORD    ?
  PhonemeId               WORD      ?
  VisemeId                SPVISEMES ?
  dwReserved1             DWORD     ?
  dwReserved2             DWORD     ?
SPVOICESTATUS ends


SPRECOCONTEXTSTATUS struc 4
  eInterference           SPINTERFERENCE  ?
  szRequestTypeOfUI       WORD 255 dup (?)
  dwReserved1             DWORD     ?
  dwReserved2             DWORD     ?
SPRECOCONTEXTSTATUS ends


SPSERIALIZEDRESULT struc 4
  ulSerializedSize        DWORD     ?
SPSERIALIZEDRESULT ends


WaveFormatEx struc 4
  wFormatTag              WORD      ?
  nChannels               WORD      ?
  nSamplesPerSec          DWORD     ?
  nAvgBytesPerSec         DWORD     ?
  nBlockAlign             WORD      ?
  wBitsPerSample          WORD      ?
  cbSize                  WORD      ?
WaveFormatEx ends


SPEVENT struc 8
  eEventId                WORD      ?
  elParamType             WORD      ?
  ulStreamNum             DWORD     ?
  ullAudioStreamOffset    QWORD     ?
  wParam                  POINTER   ?
  lParam                  POINTER   ?
SPEVENT ends

SPSERIALIZEDEVENT textequ <SPEVENT>


SPSERIALIZEDEVENT64 struc
  eEventId                WORD      ?
  elParamType             WORD      ?
  ulStreamNum             DWORD     ?
  ullAudioStreamOffset    QWORD     ?
  SerializedwParam        QWORD     ?
  SerializedlParam        QWORD     ?
SPSERIALIZEDEVENT64 ends



SPWORDPRONUNCIATIONLIST struc 4
  ulSize                  DWORD     ?
  pvBuffer                POINTER   ?
  pFirstWordPronunciation POINTER   ?
SPWORDPRONUNCIATIONLIST ends


SPWORDPRONUNCIATION struc 4
  pNextWordPronunciation  POINTER   ?
  eLexiconType            SPLEXICONTYPE   ?
  LangId                  WORD      ?
  wReserved               WORD      ?
  ePartOfSpeech           SPPARTOFSPEECH  ?
  szPronunciation         WORD 1 dup (?)
SPWORDPRONUNCIATION ends


SPEVENTSOURCEINFO struc 8
  ullEventInterest        QWORD     ?
  ullQueuedInterest       QWORD     ?
  ulCount                 DWORD     ?
SPEVENTSOURCEINFO ends


SPPHRASERULE struc 4
  pszName                 POINTER   ?
  ulId                    DWORD     ?
  ulFirstElement          DWORD     ?
  ulCountOfElements       DWORD     ?
  pNextSibling            POINTER   ?
  pFirstChild             POINTER   ?
  SREngineConfidence      REAL4     ?
  Confidence              SBYTE     ?
SPPHRASERULE ends


SPWORDLIST struc 4
  ulSize                  DWORD     ?
  pvBuffer                POINTER   ?
  pFirstWord              POINTER   ?
SPWORDLIST ends


SPWORD struc 4
  pNextWord               POINTER   ?
  LangId                  WORD      ?
  wReserved               WORD      ?
  eWordType               SPWORDTYPE ?
  pszWord                 POINTER   ?
  pFirstWordPronunciation POINTER   ?
SPWORD ends


SPPHRASEPROPERTY struc 8
  pszName                 POINTER   ?
  ulId                    DWORD     ?
  pszValue                POINTER   ?
  vValue                  VARIANT   <?>
  ulFirstElement          DWORD     ?
  ulCountOfElements       DWORD     ?
  pNextSibling            POINTER   ?
  pFirstChild             POINTER   ?
  SREngineConfidence      REAL4     ?
  Confidence              SBYTE     ?
SPPHRASEPROPERTY ends


SPRECOGNIZERSTATUS struc 8
  AudioStatus             SPAUDIOSTATUS  <>
  ullRecognitionStreamPos QWORD     ?
  ulStreamNumber          DWORD     ?
  ulNumActive             DWORD     ?
  ClsidEngine             GUID      <>
  cLangIDs                DWORD     ?
  aLangID                 WORD 20 dup  (?)
  dwReserved1             DWORD     ?
  dwReserved2             DWORD     ?
SPRECOGNIZERSTATUS ends


tagSTATSTG struc 8
  pwcsName                LPWSTR    ?
  dType                   DWORD     ?
  cbSize                  QWORD     ?
  mtime                   FILETIME  <>
  ctime                   FILETIME  <>
  atime                   FILETIME  <>
  grfMode                 DWORD     ?
  grfLocksSupported       DWORD     ?
  clsid                   GUID      <>
  grfStateBits            DWORD     ?
  reserved                DWORD     ?
tagSTATSTG ends


SPRECORESULTTIMES struc 8
  ftStreamTime            FILETIME  <>
  ullLength               QWORD     ?
  dwTickCount             DWORD     ?
  ullStart                QWORD     ?
SPRECORESULTTIMES ends


SPPHRASE struc 8
  cbSize                  DWORD     ?
  LangId                  WORD      ?
  wReserved               WORD      ?
  ullGrammarID            QWORD     ?
  ftStartTime             QWORD     ?
  ullAudioStreamPosition  QWORD     ?
  ulAudioSizeBytes        DWORD     ?
  ulRetainedSizeBytes     DWORD     ?
  ulAudioSizeTime         DWORD     ?
  Rule                    SPPHRASERULE  <>
  pProperties             POINTER   ?
  pElements               POINTER   ?
  cReplacements           DWORD     ?
  pReplacements           POINTER   ?
  SREngineID              GUID      <>
  ulSREnginePrivateDataSize DWORD   ?
  pSREnginePrivateData    POINTER   ?
SPPHRASE ends


__MIDL_IWinTypes_0009 union 4
  hInproc                 SDWORD    ?
  hRemote                 SDWORD    ?
__MIDL_IWinTypes_0009 ends


SPVPITCH struc
  MiddleAdj               SDWORD    ?
  RangeAdj                SDWORD    ?
SPVPITCH ends


SPVCONTEXT struc
  pCategory               POINTER   ?
  pBefore                 POINTER   ?
  pAfter                  POINTER   ?
SPVCONTEXT  ends


SPVSTATE struc
  eAction                 DWORD     ?
  LangID                  WORD      ?
  wReserved               WORD      ?
  EmphAdj                 SDWORD    ?
  RateAdj                 SDWORD    ?
  Volume                  DWORD     ?
  PitchAdj                SPVPITCH  <>
  SilenceMSecs            DWORD     ?
  pPhoneIds               POINTER   ?
  ePartOfSpeech           DWORD     ?
  Context                 SPVCONTEXT <>
SPVSTATE ends


SPSTREAMFORMATTYPE  typedef SPWAVEFORMATTYPE

COM_INTERFACE_BEG IEnumSpObjectTokens, IUnknown, <06B64F9E-7FDA-11D2-B4F2-00C04F797396>
  COM_STD_METHOD  Next,                        :DWORD, :ptr ptr ISpObjectToken, :ptr DWORD
  COM_STD_METHOD  Skip,                        :DWORD
  COM_STD_METHOD  Reset
  COM_STD_METHOD  Clone,                       :ptr ptr IEnumSpObjectTokens
  COM_STD_METHOD  Item,                        :DWORD, :ptr ptr ISpObjectToken
  COM_STD_METHOD  GetCount,                    :ptr DWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISpDataKey, IUnknown, <14056581-E16C-11D2-BB90-00C04F8EE6C0>
  COM_STD_METHOD  SetData,                     :ptr WORD, :DWORD, :ptr BYTE
  COM_STD_METHOD  GetData,                     :ptr WORD, :ptr DWORD, :ptr BYTE
  COM_STD_METHOD  SetStringValue,              :ptr WORD, :ptr WORD
  COM_STD_METHOD  GetStringValue,              :ptr WORD, :ptr ptr WORD
  COM_STD_METHOD  SetDWORD,                    :ptr WORD, :DWORD
  COM_STD_METHOD  GetDWORD,                    :ptr WORD, :ptr DWORD
  COM_STD_METHOD  OpenKey,                     :ptr WORD, :ptr ptr ISpDataKey
  COM_STD_METHOD  CreateKey,                   :ptr WORD, :ptr ptr ISpDataKey
  COM_STD_METHOD  DeleteKey,                   :ptr WORD
  COM_STD_METHOD  DeleteValue,                 :ptr WORD
  COM_STD_METHOD  EnumKeys,                    :DWORD, :ptr ptr WORD
  COM_STD_METHOD  EnumValues,                  :DWORD, :ptr ptr WORD
COM_INTERFACE_END


;COM_INTERFACE_BEG IServiceProvider, IUnknown, <6D5140C1-7436-11CE-8034-00AA006009FA>
;  COM_STD_METHOD  RemoteQueryService,          :ptr GUID, :ptr GUID, :ptr LPUNKNOWN
;COM_INTERFACE_END


COM_INTERFACE_BEG ISpResourceManager, IServiceProvider, <93384E18-5014-43D5-ADBB-A78E055926BD>
  COM_STD_METHOD  SetObj,                      :ptr GUID, :LPUNKNOWN
  COM_STD_METHOD  GetObj,                      :ptr GUID, :ptr GUID, :ptr GUID, :SDWORD, :ptr ptr
COM_INTERFACE_END


COM_INTERFACE_BEG ISpStreamFormat, IStream, <BED530BE-2606-4F4D-A1C0-54C5CDA5566F>
  COM_STD_METHOD  GetFormat,                   :ptr GUID, :ptr ptr WaveFormatEx
COM_INTERFACE_END


COM_INTERFACE_BEG ISpStreamFormatConverter, ISpStreamFormat, <678A932C-EA71-4446-9B41-78FDA6280A29>
  COM_STD_METHOD  SetBaseStream,               :ptr ISpStreamFormat, :SDWORD, :SDWORD
  COM_STD_METHOD  GetBaseStream,               :ptr ptr ISpStreamFormat
  COM_STD_METHOD  SetFormat,                   :ptr GUID, :ptr WaveFormatEx
  COM_STD_METHOD  ResetSeekPosition
  COM_STD_METHOD  ScaleConvertedToBaseOffset,  :QWORD, :ptr QWORD
  COM_STD_METHOD  ScaleBaseToConvertedOffset,  :QWORD, :ptr QWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechVoiceStatus, IDispatch, <8BE47B07-57F6-11D2-9EEE-00C04F797396>
  COM_STD_METHOD  get_CurrentStreamNumber,     :ptr SDWORD
  COM_STD_METHOD  get_LastStreamNumberQueued,  :ptr SDWORD
  COM_STD_METHOD  get_LastHResult,             :ptr SDWORD
  COM_STD_METHOD  get_RunningState,            :ptr SpeechRunState
  COM_STD_METHOD  get_InputWordPosition,       :ptr SDWORD
  COM_STD_METHOD  get_InputWordLength,         :ptr SDWORD
  COM_STD_METHOD  get_InputSentencePosition,   :ptr SDWORD
  COM_STD_METHOD  get_InputSentenceLength,     :ptr SDWORD
  COM_STD_METHOD  get_LastBookmark,            :ptr BSTR
  COM_STD_METHOD  get_LastBookmarkId,          :ptr SDWORD
  COM_STD_METHOD  get_PhonemeId,               :ptr SWORD
  COM_STD_METHOD  get_VisemeId,                :ptr SWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechAudioBufferInfo, IDispatch, <11B103D8-1142-4EDF-A093-82FB3915F8CC>
  COM_STD_METHOD  get_MinNotification,         :ptr SDWORD
  COM_STD_METHOD  put_MinNotification,         :SDWORD
  COM_STD_METHOD  get_BufferSize,              :ptr SDWORD
  COM_STD_METHOD  put_BufferSize,              :SDWORD
  COM_STD_METHOD  get_EventBias,               :ptr SDWORD
  COM_STD_METHOD  put_EventBias,               :SDWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechAudioStatus, IDispatch, <C62D9C91-7458-47F6-862D-1EF86FB0B278>
  COM_STD_METHOD  get_FreeBufferSpace,         :ptr SDWORD
  COM_STD_METHOD  get_NonBlockingIO,           :ptr SDWORD
  COM_STD_METHOD  get_State,                   :ptr SpeechAudioState
  COM_STD_METHOD  get_CurrentSeekPosition,     :ptr VARIANT
  COM_STD_METHOD  get_CurrentDevicePosition,   :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechTextSelectionInformation, IDispatch, <3B9C7E7A-6EEE-4DED-9092-11657279ADBE>
  COM_STD_METHOD  put_ActiveOffset,            :SDWORD
  COM_STD_METHOD  get_ActiveOffset,            :ptr SDWORD
  COM_STD_METHOD  put_ActiveLength,            :SDWORD
  COM_STD_METHOD  get_ActiveLength,            :ptr SDWORD
  COM_STD_METHOD  put_SelectionOffset,         :SDWORD
  COM_STD_METHOD  get_SelectionOffset,         :ptr SDWORD
  COM_STD_METHOD  put_SelectionLength,         :SDWORD
  COM_STD_METHOD  get_SelectionLength,         :ptr SDWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechDataKey, IDispatch, <CE17C09B-4EFA-44D5-A4C9-59D9585AB0CD>
  COM_STD_METHOD  SetBinaryValue,              :BSTR, :VARIANT
  COM_STD_METHOD  GetBinaryValue,              :BSTR, :ptr VARIANT
  COM_STD_METHOD  SetStringValue,              :BSTR, :BSTR
  COM_STD_METHOD  GetStringValue,              :BSTR, :ptr BSTR
  COM_STD_METHOD  SetLongValue,                :BSTR, :SDWORD
  COM_STD_METHOD  GetLongValue,                :BSTR, :ptr SDWORD
  COM_STD_METHOD  OpenKey,                     :BSTR, :ptr ptr ISpeechDataKey
  COM_STD_METHOD  CreateKey,                   :BSTR, :ptr ptr ISpeechDataKey
  COM_STD_METHOD  DeleteKey,                   :BSTR
  COM_STD_METHOD  DeleteValue,                 :BSTR
  COM_STD_METHOD  EnumKeys,                    :SDWORD, :ptr BSTR
  COM_STD_METHOD  EnumValues,                  :SDWORD, :ptr BSTR
COM_INTERFACE_END


COM_INTERFACE_BEG ISpNotifySource, IUnknown, <5EFF4AEF-8487-11D2-961C-00C04F8EE628>
  COM_STD_METHOD  SetNotifySink,               :ptr ISpNotifySink
  COM_STD_METHOD  SetNotifyWindowMessage,      :HWND, :DWORD, :DWORD, :SDWORD
  COM_STD_METHOD  SetNotifyCallbackFunction,   :ptr ptr , :DWORD, :SDWORD
  COM_STD_METHOD  SetNotifyCallbackInterface,  :ptr ptr , :DWORD, :SDWORD
  COM_STD_METHOD  SetNotifyWin32Event
  COM_STD_METHOD  WaitForNotifyEvent,          :DWORD
  COM_STD_METHOD  GetNotifyEventHandle
COM_INTERFACE_END


COM_INTERFACE_BEG ISpEventSource, ISpNotifySource, <BE7A9CCE-5F9E-11D2-960F-00C04F8EE628>
  COM_STD_METHOD  SetInterest,                 :QWORD, :QWORD
  COM_STD_METHOD  GetEvents,                   :DWORD, :ptr SPEVENT, :ptr DWORD
  COM_STD_METHOD  GetInfo,                     :ptr SPEVENTSOURCEINFO
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechRecoResult, IDispatch, <ED2879CF-CED9-4EE6-A534-DE0191D5468D>
  COM_STD_METHOD  get_RecoContext,             :ptr ptr ISpeechRecoContext
  COM_STD_METHOD  get_Times,                   :ptr ptr ISpeechRecoResultTimes
  COM_STD_METHOD  putref_AudioFormat,          :ptr ISpeechAudioFormat
  COM_STD_METHOD  get_AudioFormat,             :ptr ptr ISpeechAudioFormat
  COM_STD_METHOD  get_PhraseInfo,              :ptr ptr ISpeechPhraseInfo
  COM_STD_METHOD  Alternates,                  :SDWORD, :SDWORD, :SDWORD, :ptr ptr ISpeechPhraseAlternates
  COM_STD_METHOD  Audio,                       :SDWORD, :SDWORD, :ptr ptr ISpeechMemoryStream
  COM_STD_METHOD  SpeakAudio,                  :SDWORD, :SDWORD, :SpeechVoiceSpeakFlags, :ptr SDWORD
  COM_STD_METHOD  SaveToMemory,                :ptr VARIANT
  COM_STD_METHOD  DiscardResultInfo,           :SpeechDiscardType
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechRecoResultTimes, IDispatch, <62B3B8FB-F6E7-41BE-BDCB-056B1C29EFC0>
  COM_STD_METHOD  get_StreamTime,              :ptr VARIANT
  COM_STD_METHOD  get_Length,                  :ptr VARIANT
  COM_STD_METHOD  get_TickCount,               :ptr SDWORD
  COM_STD_METHOD  get_OffsetFromStart,         :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpEventSink, IUnknown, <BE7A9CC9-5F9E-11D2-960F-00C04F8EE628>
  COM_STD_METHOD  AddEvents,                   :ptr SPEVENT, :DWORD
  COM_STD_METHOD  GetEventInterest,            :ptr QWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpObjectWithToken, IUnknown, <5B559F40-E952-11D2-BB91-00C04F8EE6C0>
  COM_STD_METHOD  SetObjectToken,              :ptr ISpObjectToken
  COM_STD_METHOD  GetObjectToken,              :ptr ptr ISpObjectToken
COM_INTERFACE_END


COM_INTERFACE_BEG ISpAudio, ISpStreamFormat, <C05C768F-FAE8-4EC2-8E07-338321C12452>
  COM_STD_METHOD  SetState,                    :SPAUDIOSTATE, :QWORD
  COM_STD_METHOD  SetFormat,                   :ptr GUID, :ptr WaveFormatEx
  COM_STD_METHOD  GetStatus,                   :ptr SPAUDIOSTATUS
  COM_STD_METHOD  SetBufferInfo,               :ptr SPAUDIOBUFFERINFO
  COM_STD_METHOD  GetBufferInfo,               :ptr SPAUDIOBUFFERINFO
  COM_STD_METHOD  GetDefaultFormat,            :ptr GUID, :ptr ptr WaveFormatEx
  COM_STD_METHOD  EventHandle
  COM_STD_METHOD  GetVolumeLevel,              :ptr DWORD
  COM_STD_METHOD  SetVolumeLevel,              :DWORD
  COM_STD_METHOD  GetBufferNotifySize,         :ptr DWORD
  COM_STD_METHOD  SetBufferNotifySize,         :DWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpMMSysAudio, ISpAudio, <15806F6E-1D70-4B48-98E6-3B1A007509AB>
  COM_STD_METHOD  GetDeviceId,                 :ptr DWORD
  COM_STD_METHOD  SetDeviceId,                 :DWORD
  COM_STD_METHOD  GetMMHandle,                 :ptr ptr
  COM_STD_METHOD  GetLineId,                   :ptr DWORD
  COM_STD_METHOD  SetLineId,                   :DWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseInfo, IDispatch, <961559CF-4E67-4662-8BF0-D93F1FCD61B3>
  COM_STD_METHOD  get_LanguageId,              :ptr SDWORD
  COM_STD_METHOD  get_GrammarId,               :ptr VARIANT
  COM_STD_METHOD  get_StartTime,               :ptr VARIANT
  COM_STD_METHOD  get_AudioStreamPosition,     :ptr VARIANT
  COM_STD_METHOD  get_AudioSizeBytes,          :ptr SDWORD
  COM_STD_METHOD  get_RetainedSizeBytes,       :ptr SDWORD
  COM_STD_METHOD  get_AudioSizeTime,           :ptr SDWORD
  COM_STD_METHOD  get_Rule,                    :ptr ptr ISpeechPhraseRule
  COM_STD_METHOD  get_Properties,              :ptr ptr ISpeechPhraseProperties
  COM_STD_METHOD  get_Elements,                :ptr ptr ISpeechPhraseElements
  COM_STD_METHOD  get_Replacements,            :ptr ptr ISpeechPhraseReplacements
  COM_STD_METHOD  get_EngineId,                :ptr BSTR
  COM_STD_METHOD  get_EnginePrivateData,       :ptr VARIANT
  COM_STD_METHOD  SaveToMemory,                :ptr VARIANT
  COM_STD_METHOD  GetText,                     :SDWORD, :SDWORD, :BOOL, :ptr BSTR
  COM_STD_METHOD  GetDisplayAttributes,        :SDWORD, :SDWORD, :BOOL, :ptr SpeechDisplayAttributes
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseRule, IDispatch, <A7BFE112-A4A0-48D9-B602-C313843F6964>
  COM_STD_METHOD  get_Name,                    :ptr BSTR
  COM_STD_METHOD  get_Id,                      :ptr SDWORD
  COM_STD_METHOD  get_FirstElement,            :ptr SDWORD
  COM_STD_METHOD  get_NumberOfElements,        :ptr SDWORD
  COM_STD_METHOD  get_Parent,                  :ptr ptr ISpeechPhraseRule
  COM_STD_METHOD  get_Children,                :ptr ptr ISpeechPhraseRules
  COM_STD_METHOD  get_Confidence,              :ptr SpeechEngineConfidence
  COM_STD_METHOD  get_EngineConfidence,        :ptr REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseRules, IDispatch, <9047D593-01DD-4B72-81A3-E4A0CA69F407>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechPhraseRule
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechAudioFormat, IDispatch, <E6E9C590-3E18-40E3-8299-061F98BDE7C7>
  COM_STD_METHOD  get_Type,                    :ptr SpeechAudioFormatType
  COM_STD_METHOD  put_Type,                    :SpeechAudioFormatType
  COM_STD_METHOD  get_Guid,                    :ptr BSTR
  COM_STD_METHOD  put_Guid,                    :BSTR
  COM_STD_METHOD  GetWaveFormatEx,             :ptr ptr ISpeechWaveFormatEx
  COM_STD_METHOD  SetWaveFormatEx,             :ptr ISpeechWaveFormatEx
COM_INTERFACE_END


COM_INTERFACE_BEG ISpStream, ISpStreamFormat, <12E3CCA9-7518-44C5-A5E7-BA5A79CB929E>
  COM_STD_METHOD  SetBaseStream,               :ptr IStream, :ptr GUID, :ptr WaveFormatEx
  COM_STD_METHOD  GetBaseStream,               :ptr ptr IStream
  COM_STD_METHOD  BindToFile,                  :ptr WORD, :SPFILEMODE, :ptr GUID, :ptr WaveFormatEx, :QWORD
  COM_STD_METHOD  Close
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseProperties, IDispatch, <08166B47-102E-4B23-A599-BDB98DBFD1F4>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechPhraseProperty
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpVoice, ISpEventSource, <6C44DF74-72B9-4992-A1EC-EF996E0422D4>
  COM_STD_METHOD  SetOutput,                   :LPUNKNOWN, :SDWORD
  COM_STD_METHOD  GetOutputObjectToken,        :ptr ptr ISpObjectToken
  COM_STD_METHOD  GetOutputStream,             :ptr ptr ISpStreamFormat
  COM_STD_METHOD  Pause_
  COM_STD_METHOD  Resume
  COM_STD_METHOD  SetVoice,                    :ptr ISpObjectToken
  COM_STD_METHOD  GetVoice,                    :ptr ptr ISpObjectToken
  COM_STD_METHOD  Speak,                       :LPWSTR, :DWORD, :ptr DWORD
  COM_STD_METHOD  SpeakStream,                 :ptr IStream, :DWORD, :ptr DWORD
  COM_STD_METHOD  GetStatus,                   :ptr SPVOICESTATUS, :ptr LPWSTR
  COM_STD_METHOD  Skip,                        :LPWSTR, :SDWORD, :ptr DWORD
  COM_STD_METHOD  SetPriority,                 :SPVPRIORITY
  COM_STD_METHOD  GetPriority,                 :ptr SPVPRIORITY
  COM_STD_METHOD  SetAlertBoundary,            :SPEVENTENUM
  COM_STD_METHOD  GetAlertBoundary,            :ptr SPEVENTENUM
  COM_STD_METHOD  SetRate,                     :SDWORD
  COM_STD_METHOD  GetRate,                     :ptr SDWORD
  COM_STD_METHOD  SetVolume,                   :WORD
  COM_STD_METHOD  GetVolume,                   :ptr WORD
  COM_STD_METHOD  WaitUntilDone,               :DWORD
  COM_STD_METHOD  SetSyncSpeakTimeout,         :DWORD
  COM_STD_METHOD  GetSyncSpeakTimeout,         :ptr DWORD
  COM_STD_METHOD  SpeakCompleteEvent
  COM_STD_METHOD  IsUISupported,               :ptr WORD, :ptr , :DWORD, :ptr SDWORD
  COM_STD_METHOD  DisplayUI,                   :HANDLE, :ptr WORD, :ptr WORD, :ptr , :DWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseProperty, IDispatch, <CE563D48-961E-4732-A2E1-378A42B430BE>
  COM_STD_METHOD  get_Name,                    :ptr BSTR
  COM_STD_METHOD  get_Id,                      :ptr SDWORD
  COM_STD_METHOD  get_Value,                   :ptr VARIANT
  COM_STD_METHOD  get_FirstElement,            :ptr SDWORD
  COM_STD_METHOD  get_NumberOfElements,        :ptr SDWORD
  COM_STD_METHOD  get_EngineConfidence,        :ptr REAL4
  COM_STD_METHOD  get_Confidence,              :ptr SpeechEngineConfidence
  COM_STD_METHOD  get_Parent,                  :ptr ptr ISpeechPhraseProperty
  COM_STD_METHOD  get_Children,                :ptr ptr ISpeechPhraseProperties
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseElements, IDispatch, <0626B328-3478-467D-A0B3-D0853B93DDA3>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechPhraseElement
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseElement, IDispatch, <E6176F96-E373-4801-B223-3B62C068C0B4>
  COM_STD_METHOD  get_AudioTimeOffset,         :ptr SDWORD
  COM_STD_METHOD  get_AudioSizeTime,           :ptr SDWORD
  COM_STD_METHOD  get_AudioStreamOffset,       :ptr SDWORD
  COM_STD_METHOD  get_AudioSizeBytes,          :ptr SDWORD
  COM_STD_METHOD  get_RetainedStreamOffset,    :ptr SDWORD
  COM_STD_METHOD  get_RetainedSizeBytes,       :ptr SDWORD
  COM_STD_METHOD  get_DisplayText,             :ptr BSTR
  COM_STD_METHOD  get_LexicalForm,             :ptr BSTR
  COM_STD_METHOD  get_Pronunciation,           :ptr VARIANT
  COM_STD_METHOD  get_DisplayAttributes,       :ptr SpeechDisplayAttributes
  COM_STD_METHOD  get_RequiredConfidence,      :ptr SpeechEngineConfidence
  COM_STD_METHOD  get_ActualConfidence,        :ptr SpeechEngineConfidence
  COM_STD_METHOD  get_EngineConfidence,        :ptr REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechObjectTokens, IDispatch, <9285B776-2E7B-4BC0-B53E-580EB6FA967F>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechObjectToken
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpRecoContext, ISpEventSource, <F740A62F-7C15-489E-8234-940A33D9272D>
  COM_STD_METHOD  GetRecognizer,               :ptr ptr ISpRecognizer
  COM_STD_METHOD  CreateGrammar,               :QWORD, :ptr ptr ISpRecoGrammar
  COM_STD_METHOD  GetStatus,                   :ptr SPRECOCONTEXTSTATUS
  COM_STD_METHOD  GetMaxAlternates,            :ptr DWORD
  COM_STD_METHOD  SetMaxAlternates,            :DWORD
  COM_STD_METHOD  SetAudioOptions,             :SPAUDIOOPTIONS, :ptr GUID, :ptr WaveFormatEx
  COM_STD_METHOD  GetAudioOptions,             :ptr SPAUDIOOPTIONS, :ptr GUID, :ptr ptr WaveFormatEx
  COM_STD_METHOD  DeserializeResult,           :ptr SPSERIALIZEDRESULT, :ptr ptr ISpRecoResult
  COM_STD_METHOD  Bookmark,                    :SPBOOKMARKOPTIONS, :QWORD, :SDWORD
  COM_STD_METHOD  SetAdaptationData,           :LPWSTR, :DWORD
  COM_STD_METHOD  Pause_,                       :DWORD
  COM_STD_METHOD  Resume,                      :DWORD
  COM_STD_METHOD  SetVoice,                    :ptr ISpVoice, :SDWORD
  COM_STD_METHOD  GetVoice,                    :ptr ptr ISpVoice
  COM_STD_METHOD  SetVoicePurgeEvent,          :QWORD
  COM_STD_METHOD  GetVoicePurgeEvent,          :ptr QWORD
  COM_STD_METHOD  SetContextState,             :SPCONTEXTSTATE
  COM_STD_METHOD  GetContextState,             :ptr SPCONTEXTSTATE
COM_INTERFACE_END


COM_INTERFACE_BEG ISpProperties, IUnknown, <5B4FB971-B115-4DE1-AD97-E482E3BF6EE4>
  COM_STD_METHOD  SetPropertyNum,              :ptr WORD, :SDWORD
  COM_STD_METHOD  GetPropertyNum,              :ptr WORD, :ptr SDWORD
  COM_STD_METHOD  SetPropertyString,           :ptr WORD, :ptr WORD
  COM_STD_METHOD  GetPropertyString,           :ptr WORD, :ptr ptr WORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpRecognizer, ISpProperties, <C2B5F241-DAA0-4507-9E16-5A1EAA2B7A5C>
  COM_STD_METHOD  SetRecognizer,               :ptr ISpObjectToken
  COM_STD_METHOD  GetRecognizer,               :ptr ptr ISpObjectToken
  COM_STD_METHOD  SetInput,                    :LPUNKNOWN, :SDWORD
  COM_STD_METHOD  GetInputObjectToken,         :ptr ptr ISpObjectToken
  COM_STD_METHOD  GetInputStream,              :ptr ptr ISpStreamFormat
  COM_STD_METHOD  CreateRecoContext,           :ptr ptr ISpRecoContext
  COM_STD_METHOD  GetRecoProfile,              :ptr ptr ISpObjectToken
  COM_STD_METHOD  SetRecoProfile,              :ptr ISpObjectToken
  COM_STD_METHOD  IsSharedInstance
  COM_STD_METHOD  GetRecoState,                :ptr SPRECOSTATE
  COM_STD_METHOD  SetRecoState,                :SPRECOSTATE
  COM_STD_METHOD  GetStatus,                   :ptr SPRECOGNIZERSTATUS
  COM_STD_METHOD  GetFormat,                   :SPSTREAMFORMATTYPE, :ptr GUID, :ptr ptr WaveFormatEx
  COM_STD_METHOD  IsUISupported,               :ptr WORD, :ptr , :DWORD, :ptr SDWORD
  COM_STD_METHOD  DisplayUI,                   :HANDLE, :ptr WORD, :ptr WORD, :ptr , :DWORD
  COM_STD_METHOD  EmulateRecognition,          :ptr ISpPhrase
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseReplacements, IDispatch, <38BC662F-2257-4525-959E-2069D2596C05>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechPhraseReplacement
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseReplacement, IDispatch, <2890A410-53A7-4FB5-94EC-06D4998E3D02>
  COM_STD_METHOD  get_DisplayAttributes,       :ptr SpeechDisplayAttributes
  COM_STD_METHOD  get_Text,                    :ptr BSTR
  COM_STD_METHOD  get_FirstElement,            :ptr SDWORD
  COM_STD_METHOD  get_NumberOfElements,        :ptr SDWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseAlternates, IDispatch, <B238B6D5-F276-4C3D-A6C1-2974801C3CC2>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechPhraseAlternate
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseAlternate, IDispatch, <27864A2A-2B9F-4CB8-92D3-0D2722FD1E73>
  COM_STD_METHOD  get_RecoResult,              :ptr ptr ISpeechRecoResult
  COM_STD_METHOD  get_StartElementInResult,    :ptr SDWORD
  COM_STD_METHOD  get_NumberOfElementsInResult, :ptr SDWORD
  COM_STD_METHOD  get_PhraseInfo,              :ptr ptr ISpeechPhraseInfo
  COM_STD_METHOD  Commit
COM_INTERFACE_END


COM_INTERFACE_BEG ISpPhrase, IUnknown, <1A5C0354-B621-4B5A-8791-D306ED379E53>
  COM_STD_METHOD  GetPhrase,                   :ptr ptr SPPHRASE
  COM_STD_METHOD  GetSerializedPhrase,         :ptr ptr SPSERIALIZEDPHRASE
  COM_STD_METHOD  GetText,                     :DWORD, :DWORD, :SDWORD, :ptr ptr WORD, :ptr BYTE
  COM_STD_METHOD  Discard,                     :DWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhraseInfoBuilder, IDispatch, <3B151836-DF3A-4E0A-846C-D2ADC9334333>
  COM_STD_METHOD  RestorePhraseFromMemory,     :ptr VARIANT, :ptr ptr ISpeechPhraseInfo
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechWaveFormatEx, IDispatch, <7A1EF0D5-1581-4741-88E4-209A49F11A10>
  COM_STD_METHOD  get_FormatTag,               :ptr SWORD
  COM_STD_METHOD  put_FormatTag,               :SWORD
  COM_STD_METHOD  get_Channels,                :ptr SWORD
  COM_STD_METHOD  put_Channels,                :SWORD
  COM_STD_METHOD  get_SamplesPerSec,           :ptr SDWORD
  COM_STD_METHOD  put_SamplesPerSec,           :SDWORD
  COM_STD_METHOD  get_AvgBytesPerSec,          :ptr SDWORD
  COM_STD_METHOD  put_AvgBytesPerSec,          :SDWORD
  COM_STD_METHOD  get_BlockAlign,              :ptr SWORD
  COM_STD_METHOD  put_BlockAlign,              :SWORD
  COM_STD_METHOD  get_BitsPerSample,           :ptr SWORD
  COM_STD_METHOD  put_BitsPerSample,           :SWORD
  COM_STD_METHOD  get_ExtraData,               :ptr VARIANT
  COM_STD_METHOD  put_ExtraData,               :VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechRecognizer, IDispatch, <2D5F1C0C-BD75-4B08-9478-3B11FEA2586C>
  COM_STD_METHOD  putref_Recognizer,           :ptr ISpeechObjectToken
  COM_STD_METHOD  get_Recognizer,              :ptr ptr ISpeechObjectToken
  COM_STD_METHOD  put_AllowAudioInputFormatChangesOnNextSet, BOOL
  COM_STD_METHOD  get_AllowAudioInputFormatChangesOnNextSet, :ptr BOOL
  COM_STD_METHOD  putref_AudioInput,           :ptr ISpeechObjectToken
  COM_STD_METHOD  get_AudioInput,              :ptr ptr ISpeechObjectToken
  COM_STD_METHOD  putref_AudioInputStream,     :ptr ISpeechBaseStream
  COM_STD_METHOD  get_AudioInputStream,        :ptr ptr ISpeechBaseStream
  COM_STD_METHOD  get_IsShared,                :ptr BOOL
  COM_STD_METHOD  put_State,                   :SpeechRecognizerState
  COM_STD_METHOD  get_State,                   :ptr SpeechRecognizerState
  COM_STD_METHOD  get_Status,                  :ptr ptr ISpeechRecognizerStatus
  COM_STD_METHOD  putref_Profile,              :ptr ISpeechObjectToken
  COM_STD_METHOD  get_Profile,                 :ptr ptr ISpeechObjectToken
  COM_STD_METHOD  EmulateRecognition,          :VARIANT, :ptr VARIANT, :SDWORD
  COM_STD_METHOD  CreateRecoContext,           :ptr ptr ISpeechRecoContext
  COM_STD_METHOD  GetFormat,                   :SpeechFormatType, :ptr ptr ISpeechAudioFormat
  COM_STD_METHOD  SetPropertyNumber,           :BSTR, :SDWORD, :ptr BOOL
  COM_STD_METHOD  GetPropertyNumber,           :BSTR, :ptr SDWORD, :ptr BOOL
  COM_STD_METHOD  SetPropertyString,           :BSTR, :BSTR, :ptr BOOL
  COM_STD_METHOD  GetPropertyString,           :BSTR, :ptr BSTR, :ptr BOOL
  COM_STD_METHOD  IsUISupported,               :BSTR, :ptr VARIANT, :ptr BOOL
  COM_STD_METHOD  DisplayUI,                   :SDWORD, :BSTR, :BSTR, :ptr VARIANT
  COM_STD_METHOD  GetRecognizers,              :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
  COM_STD_METHOD  GetAudioInputs,              :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
  COM_STD_METHOD  GetProfiles,                 :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechBaseStream, IDispatch, <6450336F-7D49-4CED-8097-49D6DEE37294>
  COM_STD_METHOD  get_Format,                  :ptr ptr ISpeechAudioFormat
  COM_STD_METHOD  putref_Format,               :ptr ISpeechAudioFormat
  COM_STD_METHOD  Read,                        :ptr VARIANT, :SDWORD, :ptr SDWORD
  COM_STD_METHOD  Write,                       :VARIANT, :ptr SDWORD
  COM_STD_METHOD  Seek,                        :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechRecognizerStatus, IDispatch, <BFF9E781-53EC-484E-BB8A-0E1B5551E35C>
  COM_STD_METHOD  get_AudioStatus,             :ptr ptr ISpeechAudioStatus
  COM_STD_METHOD  get_CurrentStreamPosition,   :ptr VARIANT
  COM_STD_METHOD  get_CurrentStreamNumber,     :ptr SDWORD
  COM_STD_METHOD  get_NumberOfActiveRules,     :ptr SDWORD
  COM_STD_METHOD  get_ClsidEngine,             :ptr BSTR
  COM_STD_METHOD  get_SupportedLanguages,      :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechLexicon, IDispatch, <3DA7627A-C7AE-4B23-8708-638C50362C25>
  COM_STD_METHOD  get_GenerationId,            :ptr SDWORD
  COM_STD_METHOD  GetWords,                    :SpeechLexiconType, :ptr SDWORD, :ptr ptr ISpeechLexiconWords
  COM_STD_METHOD  AddPronunciation,            :BSTR, :SDWORD, :SpeechPartOfSpeech, :BSTR
  COM_STD_METHOD  AddPronunciationByPhoneIds,  :BSTR, :SDWORD, :SpeechPartOfSpeech, :ptr VARIANT
  COM_STD_METHOD  RemovePronunciation,         :BSTR, :SDWORD, :SpeechPartOfSpeech, :BSTR
  COM_STD_METHOD  RemovePronunciationByPhoneIds, :BSTR, :SDWORD, :SpeechPartOfSpeech, :ptr VARIANT
  COM_STD_METHOD  GetPronunciations,           :BSTR, :SDWORD, :SpeechLexiconType, :ptr ptr ISpeechLexiconPronunciations
  COM_STD_METHOD  GetGenerationChange,         :ptr SDWORD, :ptr ptr ISpeechLexiconWords
COM_INTERFACE_END


COM_INTERFACE_BEG ISpGrammarBuilder, IUnknown, <8137828F-591A-4A42-BE58-49EA7EBAAC68>
  COM_STD_METHOD  ResetGrammar,                :WORD
  COM_STD_METHOD  GetRule,                     :ptr WORD, :DWORD, :DWORD, :SDWORD, :ptr ptr
  COM_STD_METHOD  ClearRule,                   :ptr
  COM_STD_METHOD  CreateNewState,              :ptr , :ptr ptr
  COM_STD_METHOD  AddWordTransition,           :ptr , :ptr , :ptr WORD, :ptr WORD, :SPGRAMMARWORDTYPE, :REAL4, :ptr SPPROPERTYINFO
  COM_STD_METHOD  AddRuleTransition,           :ptr , :ptr , :ptr , :REAL4, :ptr SPPROPERTYINFO
  COM_STD_METHOD  AddResource,                 :ptr , :ptr WORD, :ptr WORD
  COM_STD_METHOD  Commit,                      :DWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpRecoGrammar, ISpGrammarBuilder, <2177DB29-7F45-47D0-8554-067E91C80502>
  COM_STD_METHOD  GetGrammarId,                :ptr QWORD
  COM_STD_METHOD  GetRecoContext,              :ptr ptr ISpRecoContext
  COM_STD_METHOD  LoadCmdFromFile,             :LPWSTR, :SPLOADOPTIONS
  COM_STD_METHOD  LoadCmdFromObject,           :ptr GUID, :LPWSTR, :SPLOADOPTIONS
  COM_STD_METHOD  LoadCmdFromResource,         :ptr , :LPWSTR, :LPWSTR, :WORD, :SPLOADOPTIONS
  COM_STD_METHOD  LoadCmdFromMemory,           :ptr SPBINARYGRAMMAR, :SPLOADOPTIONS
  COM_STD_METHOD  LoadCmdFromProprietaryGrammar, :ptr GUID, :LPWSTR, :ptr , :DWORD, :SPLOADOPTIONS
  COM_STD_METHOD  SetRuleState,                :LPWSTR, :ptr , :SPRULESTATE
  COM_STD_METHOD  SetRuleIdState,              :DWORD, :SPRULESTATE
  COM_STD_METHOD  LoadDictation,               :LPWSTR, :SPLOADOPTIONS
  COM_STD_METHOD  UnloadDictation
  COM_STD_METHOD  SetDictationState,           :SPRULESTATE
  COM_STD_METHOD  SetWordSequenceData,         :ptr WORD, :DWORD, :ptr SPTEXTSELECTIONINFO
  COM_STD_METHOD  SetTextSelection,            :ptr SPTEXTSELECTIONINFO
  COM_STD_METHOD  IsPronounceable,             :LPWSTR, :ptr SPWORDPRONOUNCEABLE
  COM_STD_METHOD  SetGrammarState,             :SPGRAMMARSTATE
  COM_STD_METHOD  SaveCmd,                     :ptr IStream, :ptr ptr WORD
  COM_STD_METHOD  GetGrammarState,             :ptr SPGRAMMARSTATE
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechRecoContext, IDispatch, <580AA49D-7E1E-4809-B8E2-57DA806104B8>
  COM_STD_METHOD  get_Recognizer,              :ptr ptr ISpeechRecognizer
  COM_STD_METHOD  get_AudioInputInterferenceStatus,  :ptr SpeechInterference
  COM_STD_METHOD  get_RequestedUIType,         :ptr BSTR
  COM_STD_METHOD  putref_Voice,                :ptr ISpeechVoice
  COM_STD_METHOD  get_Voice,                   :ptr ptr ISpeechVoice
  COM_STD_METHOD  put_AllowVoiceFormatMatchingOnNextSet, :BOOL
  COM_STD_METHOD  get_AllowVoiceFormatMatchingOnNextSet, :ptr BOOL
  COM_STD_METHOD  put_VoicePurgeEvent,         :SpeechRecoEvents
  COM_STD_METHOD  get_VoicePurgeEvent,         :ptr SpeechRecoEvents
  COM_STD_METHOD  put_EventInterests,          :SpeechRecoEvents
  COM_STD_METHOD  get_EventInterests,          :ptr SpeechRecoEvents
  COM_STD_METHOD  put_CmdMaxAlternates,        :SDWORD
  COM_STD_METHOD  get_CmdMaxAlternates,        :ptr SDWORD
  COM_STD_METHOD  put_State,                   :SpeechRecoContextState
  COM_STD_METHOD  get_State,                   :ptr SpeechRecoContextState
  COM_STD_METHOD  put_RetainedAudio,           :SpeechRetainedAudioOptions
  COM_STD_METHOD  get_RetainedAudio,           :ptr SpeechRetainedAudioOptions
  COM_STD_METHOD  putref_RetainedAudioFormat,  :ptr ISpeechAudioFormat
  COM_STD_METHOD  get_RetainedAudioFormat,     :ptr ptr ISpeechAudioFormat
  COM_STD_METHOD  Pause_
  COM_STD_METHOD  Resume
  COM_STD_METHOD  CreateGrammar,               :VARIANT, :ptr ptr ISpeechRecoGrammar
  COM_STD_METHOD  CreateResultFromMemory,      :ptr VARIANT, :ptr ptr ISpeechRecoResult
  COM_STD_METHOD  Bookmark,                    :SpeechBookmarkOptions, :VARIANT, :VARIANT
  COM_STD_METHOD  SetAdaptationData,           :BSTR
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechLexiconWords, IDispatch, <8D199862-415E-47D5-AC4F-FAA608B424E6>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechLexiconWord
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechLexiconWord, IDispatch, <4E5B933C-C9BE-48ED-8842-1EE51BB1D4FF>
  COM_STD_METHOD  get_LangId,                  :ptr SDWORD
  COM_STD_METHOD  get_Type,                    :ptr SpeechWordType
  COM_STD_METHOD  get_Word,                    :ptr BSTR
  COM_STD_METHOD  get_Pronunciations,          :ptr ptr ISpeechLexiconPronunciations
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechObjectToken, IDispatch, <C74A3ADC-B727-4500-A84A-B526721C8B8C>
  COM_STD_METHOD  get_Id,                      :ptr BSTR
  COM_STD_METHOD  get_DataKey,                 :ptr ptr ISpeechDataKey
  COM_STD_METHOD  get_Category,                :ptr ptr ISpeechObjectTokenCategory
  COM_STD_METHOD  GetDescription,              :SDWORD, :ptr BSTR
  COM_STD_METHOD  SetId,                       :BSTR, :BSTR, :BOOL
  COM_STD_METHOD  GetAttribute,                :BSTR, :ptr BSTR
  COM_STD_METHOD  CreateInstance,              :LPUNKNOWN, :SpeechTokenContext, :ptr LPUNKNOWN
  COM_STD_METHOD  Remove,                      :BSTR
  COM_STD_METHOD  GetStorageFileName,          :BSTR, :BSTR, :BSTR, :SpeechTokenShellFolder, :ptr BSTR
  COM_STD_METHOD  RemoveStorageFileName,       :BSTR, :BSTR, :BOOL
  COM_STD_METHOD  IsUISupported,               :BSTR, :ptr VARIANT, :LPUNKNOWN, :ptr BOOL
  COM_STD_METHOD  DisplayUI,                   :SDWORD, :BSTR, :BSTR, :ptr VARIANT, :LPUNKNOWN
  COM_STD_METHOD  MatchesAttributes,           :BSTR, :ptr BOOL
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechLexiconPronunciations, IDispatch, <72829128-5682-4704-A0D4-3E2BB6F2EAD3>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechLexiconPronunciation
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechLexiconPronunciation, IDispatch, <95252C5D-9E43-4F4A-9899-48EE73352F9F>
  COM_STD_METHOD  get_Type,                    :ptr SpeechLexiconType
  COM_STD_METHOD  get_LangId,                  :ptr SDWORD
  COM_STD_METHOD  get_PartOfSpeech,            :ptr SpeechPartOfSpeech
  COM_STD_METHOD  get_PhoneIds,                :ptr VARIANT
  COM_STD_METHOD  get_Symbolic,                :ptr BSTR
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechAudio, ISpeechBaseStream, <CFF8E175-019E-11D3-A08E-00C04F8EF9B5>
  COM_STD_METHOD  get_Status,                  :ptr ptr ISpeechAudioStatus
  COM_STD_METHOD  get_BufferInfo,              :ptr ptr ISpeechAudioBufferInfo
  COM_STD_METHOD  get_DefaultFormat,           :ptr ptr ISpeechAudioFormat
  COM_STD_METHOD  get_Volume,                  :ptr SDWORD
  COM_STD_METHOD  put_Volume,                  :SDWORD
  COM_STD_METHOD  get_BufferNotifySize,        :ptr SDWORD
  COM_STD_METHOD  put_BufferNotifySize,        :SDWORD
  COM_STD_METHOD  get_EventHandle,             :ptr SDWORD
  COM_STD_METHOD  SetState,                    :SpeechAudioState
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechObjectTokenCategory, IDispatch, <CA7EAC50-2D01-4145-86D4-5AE7D70F4469>
  COM_STD_METHOD  get_Id,                      :ptr BSTR
  COM_STD_METHOD  put_Default,                 :BSTR
  COM_STD_METHOD  get_Default,                 :ptr BSTR
  COM_STD_METHOD  SetId,                       :BSTR, :BOOL
  COM_STD_METHOD  GetDataKey,                  :SpeechDataKeyLocation, :ptr ptr ISpeechDataKey
  COM_STD_METHOD  EnumerateTokens,             :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechFileStream, ISpeechBaseStream, <AF67F125-AB39-4E93-B4A2-CC2E66E182A7>
  COM_STD_METHOD  Open,                        :BSTR, :SpeechStreamFileMode, :BOOL
  COM_STD_METHOD  Close
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechRecoGrammar, IDispatch, <B6D6F79F-2158-4E50-B5BC-9A9CCD852A09>
  COM_STD_METHOD  get_Id,                      :ptr VARIANT
  COM_STD_METHOD  get_RecoContext,             :ptr ptr ISpeechRecoContext
  COM_STD_METHOD  put_State,                   :SpeechGrammarState
  COM_STD_METHOD  get_State,                   :ptr SpeechGrammarState
  COM_STD_METHOD  get_Rules,                   :ptr ptr ISpeechGrammarRules
  COM_STD_METHOD  Reset,                       :SDWORD
  COM_STD_METHOD  CmdLoadFromFile,             :BSTR, :SpeechLoadOption
  COM_STD_METHOD  CmdLoadFromObject,           :BSTR, :BSTR, :SpeechLoadOption
  COM_STD_METHOD  CmdLoadFromResource,         :SDWORD, :VARIANT, :VARIANT, :SDWORD, :SpeechLoadOption
  COM_STD_METHOD  CmdLoadFromMemory,           :VARIANT, :SpeechLoadOption
  COM_STD_METHOD  CmdLoadFromProprietaryGrammar, :BSTR, :BSTR, :VARIANT, :SpeechLoadOption
  COM_STD_METHOD  CmdSetRuleState,             :BSTR, :SpeechRuleState
  COM_STD_METHOD  CmdSetRuleIdState,           :SDWORD, :SpeechRuleState
  COM_STD_METHOD  DictationLoad,               :BSTR, :SpeechLoadOption
  COM_STD_METHOD  DictationUnload
  COM_STD_METHOD  DictationSetState,           :SpeechRuleState
  COM_STD_METHOD  SetWordSequenceData,         :BSTR, :SDWORD, :ptr ISpeechTextSelectionInformation
  COM_STD_METHOD  SetTextSelection,            :ptr ISpeechTextSelectionInformation
  COM_STD_METHOD  IsPronounceable,             :BSTR, :ptr SpeechWordPronounceable
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechMemoryStream, ISpeechBaseStream, <EEB14B68-808B-4ABE-A5EA-B51DA7588008>
  COM_STD_METHOD  SetData,                     :VARIANT
  COM_STD_METHOD  GetData,                     :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechGrammarRules, IDispatch, <6FFA3B44-FC2D-40D1-8AFC-32911C7F1AD1>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  FindRule,                    :VARIANT, :ptr ptr ISpeechGrammarRule
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechGrammarRule
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
  COM_STD_METHOD  get_Dynamic,                 :ptr BOOL
  COM_STD_METHOD  Add_,                        :BSTR, :SpeechRuleAttributes, :SDWORD, :ptr ptr ISpeechGrammarRule
  COM_STD_METHOD  Commit
  COM_STD_METHOD  CommitAndSave,               :ptr BSTR, :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechGrammarRule, IDispatch, <AFE719CF-5DD1-44F2-999C-7A399F1CFCCC>
  COM_STD_METHOD  get_Attributes,              :ptr SpeechRuleAttributes
  COM_STD_METHOD  get_InitialState,            :ptr ptr ISpeechGrammarRuleState
  COM_STD_METHOD  get_Name,                    :ptr BSTR
  COM_STD_METHOD  get_Id,                      :ptr SDWORD
  COM_STD_METHOD  Clear
  COM_STD_METHOD  AddResource,                 :BSTR, :BSTR
  COM_STD_METHOD  AddState,                    :ptr ptr ISpeechGrammarRuleState
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechPhoneConverter, IDispatch, <C3E4F353-433F-43D6-89A1-6A62A7054C3D>
  COM_STD_METHOD  get_LanguageId,              :ptr SDWORD
  COM_STD_METHOD  put_LanguageId,              :SDWORD
  COM_STD_METHOD  PhoneToId,                   :BSTR, :ptr VARIANT
  COM_STD_METHOD  IdToPhone,                   :VARIANT, :ptr BSTR
COM_INTERFACE_END


COM_INTERFACE_BEG ISpRecoResult, ISpPhrase, <20B053BE-E235-43CD-9A2A-8D17A48B7842>
  COM_STD_METHOD  GetResultTimes,              :ptr SPRECORESULTTIMES
  COM_STD_METHOD  GetAlternates,               :DWORD, :DWORD, :DWORD, :ptr ptr ISpPhraseAlt, :ptr DWORD
  COM_STD_METHOD  GetAudio,                    :DWORD, :DWORD, :ptr ptr ISpStreamFormat
  COM_STD_METHOD  SpeakAudio,                  :DWORD, :DWORD, :DWORD, :ptr DWORD
  COM_STD_METHOD  Serialize,                   :ptr ptr SPSERIALIZEDRESULT
  COM_STD_METHOD  ScaleAudio,                  :ptr GUID, :ptr WaveFormatEx
  COM_STD_METHOD  GetRecoContext,              :ptr ptr ISpRecoContext
COM_INTERFACE_END


COM_INTERFACE_BEG ISpNotifySink, IUnknown, <259684DC-37C3-11D2-9603-00C04F8EE628>
  COM_STD_METHOD  Notify
COM_INTERFACE_END


COM_INTERFACE_BEG ISpPhraseAlt, ISpPhrase, <8FCEBC98-4E49-4067-9C6C-D86A0E092E3D>
  COM_STD_METHOD  GetAltInfo,                  :ptr ptr ISpPhrase, :ptr DWORD, :ptr DWORD, :ptr DWORD
  COM_STD_METHOD  Commit
COM_INTERFACE_END


COM_INTERFACE_BEG ISpNotifyTranslator, ISpNotifySink, <ACA16614-5D3D-11D2-960E-00C04F8EE628>
  COM_STD_METHOD  InitWindowMessage,           :HANDLE, :DWORD, :DWORD, :SDWORD
  COM_STD_METHOD  InitCallback,                :ptr ptr , :DWORD, :SDWORD
  COM_STD_METHOD  InitSpNotifyCallback,        :ptr ptr , :DWORD, :SDWORD
  COM_STD_METHOD  InitWin32Event,              :ptr , :SDWORD
  COM_STD_METHOD  Wait_,                       :DWORD
  COM_STD_METHOD  GetEventHandle
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechCustomStream, ISpeechBaseStream, <1A9E9F4F-104F-4DB8-A115-EFD7FD0C97AE>
  COM_STD_METHOD  get_BaseStream,              :ptr LPUNKNOWN
  COM_STD_METHOD  putref_BaseStream,           :LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpLexicon, IUnknown, <DA41A7C2-5383-4DB2-916B-6C1719E3DB58>
  COM_STD_METHOD  GetPronunciations,           :ptr WORD, :WORD, :DWORD, :ptr SPWORDPRONUNCIATIONLIST
  COM_STD_METHOD  AddPronunciation,            :ptr WORD, :WORD, :SPPARTOFSPEECH, :ptr WORD
  COM_STD_METHOD  RemovePronunciation,         :ptr WORD, :WORD, :SPPARTOFSPEECH, :ptr WORD
  COM_STD_METHOD  GetGeneration,               :ptr DWORD
  COM_STD_METHOD  GetGenerationChange,         :DWORD, :ptr DWORD, :ptr SPWORDLIST
  COM_STD_METHOD  GetWords,                    :DWORD, :ptr DWORD, :ptr DWORD, :ptr SPWORDLIST
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechGrammarRuleState, IDispatch, <D4286F2C-EE67-45AE-B928-28D695362EDA>
  COM_STD_METHOD  get_Rule,                    :ptr ptr ISpeechGrammarRule
  COM_STD_METHOD  get_Transitions,             :ptr ptr ISpeechGrammarRuleStateTransitions
  COM_STD_METHOD  AddWordTransition,           :ptr ISpeechGrammarRuleState, :BSTR, :BSTR, :SpeechGrammarWordType, :BSTR, :SDWORD, :ptr VARIANT, :REAL4
  COM_STD_METHOD  AddRuleTransition,           :ptr ISpeechGrammarRuleState, :ptr ISpeechGrammarRule, :BSTR, :SDWORD, :ptr VARIANT, :REAL4
  COM_STD_METHOD  AddSpecialTransition,        :ptr ISpeechGrammarRuleState, :SpeechSpecialTransitionType, :BSTR, :SDWORD, :ptr VARIANT, :REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechGrammarRuleStateTransitions, IDispatch, <EABCE657-75BC-44A2-AA7F-C56476742963>
  COM_STD_METHOD  get_Count,                   :ptr SDWORD
  COM_STD_METHOD  Item,                        :SDWORD, :ptr ptr ISpeechGrammarRuleStateTransition
  COM_STD_METHOD  get__NewEnum,                :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechGrammarRuleStateTransition, IDispatch, <CAFD1DB1-41D1-4A06-9863-E2E81DA17A9A>
  COM_STD_METHOD  get_Type,                    :ptr SpeechGrammarRuleStateTransitionType
  COM_STD_METHOD  get_Text,                    :ptr BSTR
  COM_STD_METHOD  get_Rule,                    :ptr ptr ISpeechGrammarRule
  COM_STD_METHOD  get_Weight,                  :ptr VARIANT
  COM_STD_METHOD  get_PropertyName,            :ptr BSTR
  COM_STD_METHOD  get_PropertyId,              :ptr SDWORD
  COM_STD_METHOD  get_PropertyValue,           :ptr VARIANT
  COM_STD_METHOD  get_NextState,               :ptr ptr ISpeechGrammarRuleState
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechMMSysAudio, ISpeechAudio, <3C76AF6D-1FD7-4831-81D1-3B71D5A13C44>
  COM_STD_METHOD  get_DeviceId,                :ptr SDWORD
  COM_STD_METHOD  put_DeviceId,                :SDWORD
  COM_STD_METHOD  get_LineId,                  :ptr SDWORD
  COM_STD_METHOD  put_LineId,                  :SDWORD
  COM_STD_METHOD  get_MMHandle,                :ptr SDWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpObjectTokenCategory, ISpDataKey, <2D3D3845-39AF-4850-BBF9-40B49780011D>
  COM_STD_METHOD  SetId,                       :ptr WORD, :SDWORD
  COM_STD_METHOD  GetId,                       :ptr ptr WORD
  COM_STD_METHOD  GetDataKey,                  :SPDATAKEYLOCATION, :ptr ptr ISpDataKey
  COM_STD_METHOD  EnumTokens,                  :LPWSTR, :LPWSTR, :ptr ptr IEnumSpObjectTokens
  COM_STD_METHOD  SetDefaultTokenId,           :ptr WORD
  COM_STD_METHOD  GetDefaultTokenId,           :ptr ptr WORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpObjectToken, ISpDataKey, <14056589-E16C-11D2-BB90-00C04F8EE6C0>
  COM_STD_METHOD  SetId,                       :ptr WORD, :ptr WORD, :SDWORD
  COM_STD_METHOD  GetId,                       :ptr ptr WORD
  COM_STD_METHOD  GetCategory,                 :ptr ptr ISpObjectTokenCategory
  COM_STD_METHOD  CreateInstance,              :LPUNKNOWN, :DWORD, :ptr GUID, :ptr ptr
  COM_STD_METHOD  GetStorageFileName,          :ptr GUID, :ptr WORD, :ptr WORD, :DWORD, :ptr ptr WORD
  COM_STD_METHOD  RemoveStorageFileName,       :ptr GUID, :ptr WORD, :SDWORD
  COM_STD_METHOD  Remove,                      :ptr GUID
  COM_STD_METHOD  IsUISupported,               :ptr WORD, :ptr , :DWORD, :LPUNKNOWN, :ptr SDWORD
  COM_STD_METHOD  DisplayUI,                   :HANDLE, :ptr WORD, :ptr WORD, :ptr , :DWORD, :LPUNKNOWN
  COM_STD_METHOD  MatchesAttributes,           :ptr WORD, :ptr SDWORD
COM_INTERFACE_END


COM_INTERFACE_BEG ISpeechVoice, IDispatch, <269316D8-57BD-11D2-9EEE-00C04F797396>
  COM_STD_METHOD  get_Status,                  :ptr ptr ISpeechVoiceStatus
  COM_STD_METHOD  get_Voice,                   :ptr ptr ISpeechObjectToken
  COM_STD_METHOD  putref_Voice,                :ptr ISpeechObjectToken
  COM_STD_METHOD  get_AudioOutput,             :ptr ptr ISpeechObjectToken
  COM_STD_METHOD  putref_AudioOutput,          :ptr ISpeechObjectToken
  COM_STD_METHOD  get_AudioOutputStream,       :ptr ptr ISpeechBaseStream
  COM_STD_METHOD  putref_AudioOutputStream,    :ptr ISpeechBaseStream
  COM_STD_METHOD  get_Rate,                    :ptr SDWORD
  COM_STD_METHOD  put_Rate,                    :SDWORD
  COM_STD_METHOD  get_Volume,                  :ptr SDWORD
  COM_STD_METHOD  put_Volume,                  :SDWORD
  COM_STD_METHOD  put_AllowAudioOutputFormatChangesOnNextSet,  :BOOL
  COM_STD_METHOD  get_AllowAudioOutputFormatChangesOnNextSet,  :ptr BOOL
  COM_STD_METHOD  get_EventInterests,          :ptr SpeechVoiceEvents
  COM_STD_METHOD  put_EventInterests,          :SpeechVoiceEvents
  COM_STD_METHOD  put_Priority,                :SpeechVoicePriority
  COM_STD_METHOD  get_Priority,                :ptr SpeechVoicePriority
  COM_STD_METHOD  put_AlertBoundary,           :SpeechVoiceEvents
  COM_STD_METHOD  get_AlertBoundary,           :ptr SpeechVoiceEvents
  COM_STD_METHOD  put_SynchronousSpeakTimeout, :SDWORD
  COM_STD_METHOD  get_SynchronousSpeakTimeout, :ptr SDWORD
  COM_STD_METHOD  Speak,                       :BSTR, :SpeechVoiceSpeakFlags, :ptr SDWORD
  COM_STD_METHOD  SpeakStream,                 :ptr ISpeechBaseStream, :SpeechVoiceSpeakFlags, :ptr SDWORD
  COM_STD_METHOD  Pause_
  COM_STD_METHOD  Resume
  COM_STD_METHOD  Skip,                        :BSTR, :SDWORD, :ptr SDWORD
  COM_STD_METHOD  GetVoices,                   :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
  COM_STD_METHOD  GetAudioOutputs,             :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
  COM_STD_METHOD  WaitUntilDone,               :SDWORD, :ptr BOOL
  COM_STD_METHOD  SpeakCompleteEvent,          :ptr SDWORD
  COM_STD_METHOD  IsUISupported,               :BSTR, :ptr VARIANT, :ptr BOOL
  COM_STD_METHOD  DisplayUI,                   :SDWORD, :BSTR, :BSTR, :ptr VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG ISpPhoneConverter, ISpObjectWithToken, <8445C581-0CAC-4A38-ABFE-9B2CE2826455>
  COM_STD_METHOD  PhoneToId,                   :ptr WORD, :ptr WORD
  COM_STD_METHOD  IdToPhone,                   :ptr WORD, :ptr WORD
COM_INTERFACE_END


COM_INTERFACE_BEG _ISpeechRecoContextEvents, IDispatch, <7B8FCB42-0E9D-4F00-A048-7B04D6179D3D>
  COM_DISP_METHOD  StartStream,                :SDWORD, :VARIANT
  COM_DISP_METHOD  EndStream,                  :SDWORD, :VARIANT, :BOOL
  COM_DISP_METHOD  Bookmark,                   :SDWORD, :VARIANT, :VARIANT, :SpeechBookmarkOptions
  COM_DISP_METHOD  SoundStart,                 :SDWORD, :VARIANT
  COM_DISP_METHOD  SoundEnd,                   :SDWORD, :VARIANT
  COM_DISP_METHOD  PhraseStart,                :SDWORD, :VARIANT
  COM_DISP_METHOD  Recognition,                :SDWORD, :VARIANT, :SpeechRecognitionType, :ptr ISpeechRecoResult
  COM_DISP_METHOD  Hypothesis,                 :SDWORD, :VARIANT, :ptr ISpeechRecoResult
  COM_DISP_METHOD  PropertyNumberChange,       :SDWORD, :VARIANT, :BSTR, :SDWORD
  COM_DISP_METHOD  PropertyStringChange,       :SDWORD, :VARIANT, :BSTR, :BSTR
  COM_DISP_METHOD  FalseRecognition,           :SDWORD, :VARIANT, :ptr ISpeechRecoResult
  COM_DISP_METHOD  Interference,               :SDWORD, :VARIANT, :SpeechInterference
  COM_DISP_METHOD  RequestUI,                  :SDWORD, :VARIANT, :BSTR
  COM_DISP_METHOD  RecognizerStateChange,      :SDWORD, :VARIANT, :SpeechRecognizerState
  COM_DISP_METHOD  Adaptation,                 :SDWORD, :VARIANT
  COM_DISP_METHOD  RecognitionForOtherContext, :SDWORD, :VARIANT
  COM_DISP_METHOD  AudioLevel,                 :SDWORD, :VARIANT, :SDWORD
  COM_DISP_METHOD  EnginePrivate,              :SDWORD, :VARIANT, :VARIANT
COM_INTERFACE_END


COM_INTERFACE_BEG _ISpeechVoiceEvents, IDispatch, <A372ACD1-3BEF-4BBD-8FFB-CB3E2B416AF8>
  COM_DISP_METHOD  StartStream,                :SDWORD, :VARIANT
  COM_DISP_METHOD  EndStream,                  :SDWORD, :VARIANT
  COM_DISP_METHOD  VoiceChange,                :SDWORD, :VARIANT, :ptr ISpeechObjectToken
  COM_DISP_METHOD  Bookmark,                   :SDWORD, :VARIANT, :BSTR, :SDWORD
  COM_DISP_METHOD  _Word,                      :SDWORD, :VARIANT, :SDWORD, :SDWORD
  COM_DISP_METHOD  Sentence,                   :SDWORD, :VARIANT, :SDWORD, :SDWORD
  COM_DISP_METHOD  Phoneme,                    :SDWORD, :VARIANT, :SDWORD, :SWORD, :SpeechVisemeFeature, :SWORD
  COM_DISP_METHOD  Viseme,                     :SDWORD, :VARIANT, :SDWORD, :SpeechVisemeType, :SpeechVisemeFeature, :SpeechVisemeType
  COM_DISP_METHOD  AudioLevel,                 :SDWORD, :VARIANT, :SDWORD
  COM_DISP_METHOD  EnginePrivate,              :SDWORD, :SDWORD, :VARIANT
COM_INTERFACE_END
