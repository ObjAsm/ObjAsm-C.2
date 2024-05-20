;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sapi51.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:12

;* verify that the <rpcndr.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
;* verify that the <rpcsal.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
  ;* __RPCNDR_H_VERSION__ *
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
  ;*COM_NO_WINDOWS_H*
endif
ifndef __sapi51_h__
  __sapi51_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if Defined(_CONTROL_FLOW_GUARD_XFG)
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  ;* Forward Declarations *
  ifndef __ISpNotifySource_FWD_DEFINED__
    __ISpNotifySource_FWD_DEFINED__ equ <>
    ;* __ISpNotifySource_FWD_DEFINED__ *
  endif
  ifndef __ISpNotifySink_FWD_DEFINED__
    __ISpNotifySink_FWD_DEFINED__ equ <>
    ;* __ISpNotifySink_FWD_DEFINED__ *
  endif
  ifndef __ISpNotifyTranslator_FWD_DEFINED__
    __ISpNotifyTranslator_FWD_DEFINED__ equ <>
    ;* __ISpNotifyTranslator_FWD_DEFINED__ *
  endif
  ifndef __ISpDataKey_FWD_DEFINED__
    __ISpDataKey_FWD_DEFINED__ equ <>
    ;* __ISpDataKey_FWD_DEFINED__ *
  endif
  ifndef __ISpRegDataKey_FWD_DEFINED__
    __ISpRegDataKey_FWD_DEFINED__ equ <>
    ;* __ISpRegDataKey_FWD_DEFINED__ *
  endif
  ifndef __ISpObjectTokenCategory_FWD_DEFINED__
    __ISpObjectTokenCategory_FWD_DEFINED__ equ <>
    ;* __ISpObjectTokenCategory_FWD_DEFINED__ *
  endif
  ifndef __ISpObjectToken_FWD_DEFINED__
    __ISpObjectToken_FWD_DEFINED__ equ <>
    ;* __ISpObjectToken_FWD_DEFINED__ *
  endif
  ifndef __ISpObjectTokenInit_FWD_DEFINED__
    __ISpObjectTokenInit_FWD_DEFINED__ equ <>
    ;* __ISpObjectTokenInit_FWD_DEFINED__ *
  endif
  ifndef __IEnumSpObjectTokens_FWD_DEFINED__
    __IEnumSpObjectTokens_FWD_DEFINED__ equ <>
    ;* __IEnumSpObjectTokens_FWD_DEFINED__ *
  endif
  ifndef __ISpObjectWithToken_FWD_DEFINED__
    __ISpObjectWithToken_FWD_DEFINED__ equ <>
    ;* __ISpObjectWithToken_FWD_DEFINED__ *
  endif
  ifndef __ISpResourceManager_FWD_DEFINED__
    __ISpResourceManager_FWD_DEFINED__ equ <>
    ;* __ISpResourceManager_FWD_DEFINED__ *
  endif
  ifndef __ISpEventSource_FWD_DEFINED__
    __ISpEventSource_FWD_DEFINED__ equ <>
    ;* __ISpEventSource_FWD_DEFINED__ *
  endif
  ifndef __ISpEventSink_FWD_DEFINED__
    __ISpEventSink_FWD_DEFINED__ equ <>
    ;* __ISpEventSink_FWD_DEFINED__ *
  endif
  ifndef __ISpStreamFormat_FWD_DEFINED__
    __ISpStreamFormat_FWD_DEFINED__ equ <>
    ;* __ISpStreamFormat_FWD_DEFINED__ *
  endif
  ifndef __ISpStream_FWD_DEFINED__
    __ISpStream_FWD_DEFINED__ equ <>
    ;* __ISpStream_FWD_DEFINED__ *
  endif
  ifndef __ISpStreamFormatConverter_FWD_DEFINED__
    __ISpStreamFormatConverter_FWD_DEFINED__ equ <>
    ;* __ISpStreamFormatConverter_FWD_DEFINED__ *
  endif
  ifndef __ISpAudio_FWD_DEFINED__
    __ISpAudio_FWD_DEFINED__ equ <>
    ;* __ISpAudio_FWD_DEFINED__ *
  endif
  ifndef __ISpMMSysAudio_FWD_DEFINED__
    __ISpMMSysAudio_FWD_DEFINED__ equ <>
    ;* __ISpMMSysAudio_FWD_DEFINED__ *
  endif
  ifndef __ISpTranscript_FWD_DEFINED__
    __ISpTranscript_FWD_DEFINED__ equ <>
    ;* __ISpTranscript_FWD_DEFINED__ *
  endif
  ifndef __ISpLexicon_FWD_DEFINED__
    __ISpLexicon_FWD_DEFINED__ equ <>
    ;* __ISpLexicon_FWD_DEFINED__ *
  endif
  ifndef __ISpContainerLexicon_FWD_DEFINED__
    __ISpContainerLexicon_FWD_DEFINED__ equ <>
    ;* __ISpContainerLexicon_FWD_DEFINED__ *
  endif
  ifndef __ISpPhoneConverter_FWD_DEFINED__
    __ISpPhoneConverter_FWD_DEFINED__ equ <>
    ;* __ISpPhoneConverter_FWD_DEFINED__ *
  endif
  ifndef __ISpVoice_FWD_DEFINED__
    __ISpVoice_FWD_DEFINED__ equ <>
    ;* __ISpVoice_FWD_DEFINED__ *
  endif
  ifndef __ISpPhrase_FWD_DEFINED__
    __ISpPhrase_FWD_DEFINED__ equ <>
    ;* __ISpPhrase_FWD_DEFINED__ *
  endif
  ifndef __ISpPhraseAlt_FWD_DEFINED__
    __ISpPhraseAlt_FWD_DEFINED__ equ <>
    ;* __ISpPhraseAlt_FWD_DEFINED__ *
  endif
  ifndef __ISpRecoResult_FWD_DEFINED__
    __ISpRecoResult_FWD_DEFINED__ equ <>
    ;* __ISpRecoResult_FWD_DEFINED__ *
  endif
  ifndef __ISpGrammarBuilder_FWD_DEFINED__
    __ISpGrammarBuilder_FWD_DEFINED__ equ <>
    ;* __ISpGrammarBuilder_FWD_DEFINED__ *
  endif
  ifndef __ISpRecoGrammar_FWD_DEFINED__
    __ISpRecoGrammar_FWD_DEFINED__ equ <>
    ;* __ISpRecoGrammar_FWD_DEFINED__ *
  endif
  ifndef __ISpRecoContext_FWD_DEFINED__
    __ISpRecoContext_FWD_DEFINED__ equ <>
    ;* __ISpRecoContext_FWD_DEFINED__ *
  endif
  ifndef __ISpProperties_FWD_DEFINED__
    __ISpProperties_FWD_DEFINED__ equ <>
    ;* __ISpProperties_FWD_DEFINED__ *
  endif
  ifndef __ISpRecognizer_FWD_DEFINED__
    __ISpRecognizer_FWD_DEFINED__ equ <>
    ;* __ISpRecognizer_FWD_DEFINED__ *
  endif
  ifndef __ISpeechDataKey_FWD_DEFINED__
    __ISpeechDataKey_FWD_DEFINED__ equ <>
    ;* __ISpeechDataKey_FWD_DEFINED__ *
  endif
  ifndef __ISpeechObjectToken_FWD_DEFINED__
    __ISpeechObjectToken_FWD_DEFINED__ equ <>
    ;* __ISpeechObjectToken_FWD_DEFINED__ *
  endif
  ifndef __ISpeechObjectTokens_FWD_DEFINED__
    __ISpeechObjectTokens_FWD_DEFINED__ equ <>
    ;* __ISpeechObjectTokens_FWD_DEFINED__ *
  endif
  ifndef __ISpeechObjectTokenCategory_FWD_DEFINED__
    __ISpeechObjectTokenCategory_FWD_DEFINED__ equ <>
    ;* __ISpeechObjectTokenCategory_FWD_DEFINED__ *
  endif
  ifndef __ISpeechAudioBufferInfo_FWD_DEFINED__
    __ISpeechAudioBufferInfo_FWD_DEFINED__ equ <>
    ;* __ISpeechAudioBufferInfo_FWD_DEFINED__ *
  endif
  ifndef __ISpeechAudioStatus_FWD_DEFINED__
    __ISpeechAudioStatus_FWD_DEFINED__ equ <>
    ;* __ISpeechAudioStatus_FWD_DEFINED__ *
  endif
  ifndef __ISpeechAudioFormat_FWD_DEFINED__
    __ISpeechAudioFormat_FWD_DEFINED__ equ <>
    ;* __ISpeechAudioFormat_FWD_DEFINED__ *
  endif
  ifndef __ISpeechWaveFormatEx_FWD_DEFINED__
    __ISpeechWaveFormatEx_FWD_DEFINED__ equ <>
    ;* __ISpeechWaveFormatEx_FWD_DEFINED__ *
  endif
  ifndef __ISpeechBaseStream_FWD_DEFINED__
    __ISpeechBaseStream_FWD_DEFINED__ equ <>
    ;* __ISpeechBaseStream_FWD_DEFINED__ *
  endif
  ifndef __ISpeechFileStream_FWD_DEFINED__
    __ISpeechFileStream_FWD_DEFINED__ equ <>
    ;* __ISpeechFileStream_FWD_DEFINED__ *
  endif
  ifndef __ISpeechMemoryStream_FWD_DEFINED__
    __ISpeechMemoryStream_FWD_DEFINED__ equ <>
    ;* __ISpeechMemoryStream_FWD_DEFINED__ *
  endif
  ifndef __ISpeechCustomStream_FWD_DEFINED__
    __ISpeechCustomStream_FWD_DEFINED__ equ <>
    ;* __ISpeechCustomStream_FWD_DEFINED__ *
  endif
  ifndef __ISpeechAudio_FWD_DEFINED__
    __ISpeechAudio_FWD_DEFINED__ equ <>
    ;* __ISpeechAudio_FWD_DEFINED__ *
  endif
  ifndef __ISpeechMMSysAudio_FWD_DEFINED__
    __ISpeechMMSysAudio_FWD_DEFINED__ equ <>
    ;* __ISpeechMMSysAudio_FWD_DEFINED__ *
  endif
  ifndef __ISpeechVoice_FWD_DEFINED__
    __ISpeechVoice_FWD_DEFINED__ equ <>
    ;* __ISpeechVoice_FWD_DEFINED__ *
  endif
  ifndef __ISpeechVoiceStatus_FWD_DEFINED__
    __ISpeechVoiceStatus_FWD_DEFINED__ equ <>
    ;* __ISpeechVoiceStatus_FWD_DEFINED__ *
  endif
  ifndef ___ISpeechVoiceEvents_FWD_DEFINED__
    ___ISpeechVoiceEvents_FWD_DEFINED__ equ <>
    ;* ___ISpeechVoiceEvents_FWD_DEFINED__ *
  endif
  ifndef __ISpeechRecognizer_FWD_DEFINED__
    __ISpeechRecognizer_FWD_DEFINED__ equ <>
    ;* __ISpeechRecognizer_FWD_DEFINED__ *
  endif
  ifndef __ISpeechRecognizerStatus_FWD_DEFINED__
    __ISpeechRecognizerStatus_FWD_DEFINED__ equ <>
    ;* __ISpeechRecognizerStatus_FWD_DEFINED__ *
  endif
  ifndef __ISpeechRecoContext_FWD_DEFINED__
    __ISpeechRecoContext_FWD_DEFINED__ equ <>
    ;* __ISpeechRecoContext_FWD_DEFINED__ *
  endif
  ifndef __ISpeechRecoGrammar_FWD_DEFINED__
    __ISpeechRecoGrammar_FWD_DEFINED__ equ <>
    ;* __ISpeechRecoGrammar_FWD_DEFINED__ *
  endif
  ifndef ___ISpeechRecoContextEvents_FWD_DEFINED__
    ___ISpeechRecoContextEvents_FWD_DEFINED__ equ <>
    ;* ___ISpeechRecoContextEvents_FWD_DEFINED__ *
  endif
  ifndef __ISpeechGrammarRule_FWD_DEFINED__
    __ISpeechGrammarRule_FWD_DEFINED__ equ <>
    ;* __ISpeechGrammarRule_FWD_DEFINED__ *
  endif
  ifndef __ISpeechGrammarRules_FWD_DEFINED__
    __ISpeechGrammarRules_FWD_DEFINED__ equ <>
    ;* __ISpeechGrammarRules_FWD_DEFINED__ *
  endif
  ifndef __ISpeechGrammarRuleState_FWD_DEFINED__
    __ISpeechGrammarRuleState_FWD_DEFINED__ equ <>
    ;* __ISpeechGrammarRuleState_FWD_DEFINED__ *
  endif
  ifndef __ISpeechGrammarRuleStateTransition_FWD_DEFINED__
    __ISpeechGrammarRuleStateTransition_FWD_DEFINED__ equ <>
    ;* __ISpeechGrammarRuleStateTransition_FWD_DEFINED__ *
  endif
  ifndef __ISpeechGrammarRuleStateTransitions_FWD_DEFINED__
    __ISpeechGrammarRuleStateTransitions_FWD_DEFINED__ equ <>
    ;* __ISpeechGrammarRuleStateTransitions_FWD_DEFINED__ *
  endif
  ifndef __ISpeechTextSelectionInformation_FWD_DEFINED__
    __ISpeechTextSelectionInformation_FWD_DEFINED__ equ <>
    ;* __ISpeechTextSelectionInformation_FWD_DEFINED__ *
  endif
  ifndef __ISpeechRecoResult_FWD_DEFINED__
    __ISpeechRecoResult_FWD_DEFINED__ equ <>
    ;* __ISpeechRecoResult_FWD_DEFINED__ *
  endif
  ifndef __ISpeechRecoResultTimes_FWD_DEFINED__
    __ISpeechRecoResultTimes_FWD_DEFINED__ equ <>
    ;* __ISpeechRecoResultTimes_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseAlternate_FWD_DEFINED__
    __ISpeechPhraseAlternate_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseAlternate_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseAlternates_FWD_DEFINED__
    __ISpeechPhraseAlternates_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseAlternates_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseInfo_FWD_DEFINED__
    __ISpeechPhraseInfo_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseInfo_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseElement_FWD_DEFINED__
    __ISpeechPhraseElement_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseElement_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseElements_FWD_DEFINED__
    __ISpeechPhraseElements_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseElements_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseReplacement_FWD_DEFINED__
    __ISpeechPhraseReplacement_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseReplacement_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseReplacements_FWD_DEFINED__
    __ISpeechPhraseReplacements_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseReplacements_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseProperty_FWD_DEFINED__
    __ISpeechPhraseProperty_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseProperty_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseProperties_FWD_DEFINED__
    __ISpeechPhraseProperties_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseProperties_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseRule_FWD_DEFINED__
    __ISpeechPhraseRule_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseRule_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseRules_FWD_DEFINED__
    __ISpeechPhraseRules_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseRules_FWD_DEFINED__ *
  endif
  ifndef __ISpeechLexicon_FWD_DEFINED__
    __ISpeechLexicon_FWD_DEFINED__ equ <>
    ;* __ISpeechLexicon_FWD_DEFINED__ *
  endif
  ifndef __ISpeechLexiconWords_FWD_DEFINED__
    __ISpeechLexiconWords_FWD_DEFINED__ equ <>
    ;* __ISpeechLexiconWords_FWD_DEFINED__ *
  endif
  ifndef __ISpeechLexiconWord_FWD_DEFINED__
    __ISpeechLexiconWord_FWD_DEFINED__ equ <>
    ;* __ISpeechLexiconWord_FWD_DEFINED__ *
  endif
  ifndef __ISpeechLexiconPronunciations_FWD_DEFINED__
    __ISpeechLexiconPronunciations_FWD_DEFINED__ equ <>
    ;* __ISpeechLexiconPronunciations_FWD_DEFINED__ *
  endif
  ifndef __ISpeechLexiconPronunciation_FWD_DEFINED__
    __ISpeechLexiconPronunciation_FWD_DEFINED__ equ <>
    ;* __ISpeechLexiconPronunciation_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhraseInfoBuilder_FWD_DEFINED__
    __ISpeechPhraseInfoBuilder_FWD_DEFINED__ equ <>
    ;* __ISpeechPhraseInfoBuilder_FWD_DEFINED__ *
  endif
  ifndef __ISpeechPhoneConverter_FWD_DEFINED__
    __ISpeechPhoneConverter_FWD_DEFINED__ equ <>
    ;* __ISpeechPhoneConverter_FWD_DEFINED__ *
  endif
  ifndef __SpNotifyTranslator_FWD_DEFINED__
    __SpNotifyTranslator_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpNotifyTranslator_FWD_DEFINED__ *
  endif
  ifndef __SpObjectTokenCategory_FWD_DEFINED__
    __SpObjectTokenCategory_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpObjectTokenCategory_FWD_DEFINED__ *
  endif
  ifndef __SpObjectToken_FWD_DEFINED__
    __SpObjectToken_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpObjectToken_FWD_DEFINED__ *
  endif
  ifndef __SpResourceManager_FWD_DEFINED__
    __SpResourceManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpResourceManager_FWD_DEFINED__ *
  endif
  ifndef __SpStreamFormatConverter_FWD_DEFINED__
    __SpStreamFormatConverter_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpStreamFormatConverter_FWD_DEFINED__ *
  endif
  ifndef __SpMMAudioEnum_FWD_DEFINED__
    __SpMMAudioEnum_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpMMAudioEnum_FWD_DEFINED__ *
  endif
  ifndef __SpMMAudioIn_FWD_DEFINED__
    __SpMMAudioIn_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpMMAudioIn_FWD_DEFINED__ *
  endif
  ifndef __SpMMAudioOut_FWD_DEFINED__
    __SpMMAudioOut_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpMMAudioOut_FWD_DEFINED__ *
  endif
  ifndef __SpStream_FWD_DEFINED__
    __SpStream_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpStream_FWD_DEFINED__ *
  endif
  ifndef __SpVoice_FWD_DEFINED__
    __SpVoice_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpVoice_FWD_DEFINED__ *
  endif
  ifndef __SpSharedRecoContext_FWD_DEFINED__
    __SpSharedRecoContext_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpSharedRecoContext_FWD_DEFINED__ *
  endif
  ifndef __SpInprocRecognizer_FWD_DEFINED__
    __SpInprocRecognizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpInprocRecognizer_FWD_DEFINED__ *
  endif
  ifndef __SpSharedRecognizer_FWD_DEFINED__
    __SpSharedRecognizer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpSharedRecognizer_FWD_DEFINED__ *
  endif
  ifndef __SpLexicon_FWD_DEFINED__
    __SpLexicon_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpLexicon_FWD_DEFINED__ *
  endif
  ifndef __SpUnCompressedLexicon_FWD_DEFINED__
    __SpUnCompressedLexicon_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpUnCompressedLexicon_FWD_DEFINED__ *
  endif
  ifndef __SpCompressedLexicon_FWD_DEFINED__
    __SpCompressedLexicon_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpCompressedLexicon_FWD_DEFINED__ *
  endif
  ifndef __SpPhoneConverter_FWD_DEFINED__
    __SpPhoneConverter_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpPhoneConverter_FWD_DEFINED__ *
  endif
  ifndef __SpNullPhoneConverter_FWD_DEFINED__
    __SpNullPhoneConverter_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpNullPhoneConverter_FWD_DEFINED__ *
  endif
  ifndef __SpTextSelectionInformation_FWD_DEFINED__
    __SpTextSelectionInformation_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpTextSelectionInformation_FWD_DEFINED__ *
  endif
  ifndef __SpPhraseInfoBuilder_FWD_DEFINED__
    __SpPhraseInfoBuilder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpPhraseInfoBuilder_FWD_DEFINED__ *
  endif
  ifndef __SpAudioFormat_FWD_DEFINED__
    __SpAudioFormat_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpAudioFormat_FWD_DEFINED__ *
  endif
  ifndef __SpWaveFormatEx_FWD_DEFINED__
    __SpWaveFormatEx_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpWaveFormatEx_FWD_DEFINED__ *
  endif
  ifndef __SpInProcRecoContext_FWD_DEFINED__
    __SpInProcRecoContext_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpInProcRecoContext_FWD_DEFINED__ *
  endif
  ifndef __SpCustomStream_FWD_DEFINED__
    __SpCustomStream_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpCustomStream_FWD_DEFINED__ *
  endif
  ifndef __SpFileStream_FWD_DEFINED__
    __SpFileStream_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpFileStream_FWD_DEFINED__ *
  endif
  ifndef __SpMemoryStream_FWD_DEFINED__
    __SpMemoryStream_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpMemoryStream_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include oaidl.inc
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_sapi51_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; Allow nameless structs/unions
    if 0
      ;[...]
    else
      include mmsystem.inc
    endif
    ;* [hidden] *
    SPDATAKEYLOCATION typedef SDWORD
    SPDKL_DefaultLocation equ 0
    SPDKL_CurrentUser equ 1
    SPDKL_LocalMachine equ 2
    SPDKL_CurrentConfig equ 5

    SPDUI_EngineProperties equ <L("EngineProperties")>
    SPDUI_AddRemoveWord equ <L("AddRemoveWord")>
    SPDUI_UserTraining equ <L("UserTraining")>
    SPDUI_MicTraining equ <L("MicTraining")>
    SPDUI_RecoProfileProperties equ <L("RecoProfileProperties")>
    SPDUI_AudioProperties equ <L("AudioProperties")>
    SPDUI_AudioVolume equ <L("AudioVolume")>
    SPDUI_UserEnrollment equ <L("UserEnrollment")>
    SPDUI_ShareData equ <L("ShareData")>
    SPDUI_Tutorial equ <L("Tutorial")>
    ;* [hidden] *
    SPSTREAMFORMAT typedef SDWORD
    SPSF_Default equ -1
    SPSF_NoAssignedFormat equ 0
    SPSF_Text equ
    SPSF_NonStandardFormat equ
    SPSF_ExtendedAudioFormat equ
    SPSF_8kHz8BitMono equ
    SPSF_8kHz8BitStereo equ
    SPSF_8kHz16BitMono equ
    SPSF_8kHz16BitStereo equ
    SPSF_11kHz8BitMono equ
    SPSF_11kHz8BitStereo equ
    SPSF_11kHz16BitMono equ
    SPSF_11kHz16BitStereo equ
    SPSF_12kHz8BitMono equ
    SPSF_12kHz8BitStereo equ
    SPSF_12kHz16BitMono equ
    SPSF_12kHz16BitStereo equ
    SPSF_16kHz8BitMono equ
    SPSF_16kHz8BitStereo equ
    SPSF_16kHz16BitMono equ
    SPSF_16kHz16BitStereo equ
    SPSF_22kHz8BitMono equ
    SPSF_22kHz8BitStereo equ
    SPSF_22kHz16BitMono equ
    SPSF_22kHz16BitStereo equ
    SPSF_24kHz8BitMono equ
    SPSF_24kHz8BitStereo equ
    SPSF_24kHz16BitMono equ
    SPSF_24kHz16BitStereo equ
    SPSF_32kHz8BitMono equ
    SPSF_32kHz8BitStereo equ
    SPSF_32kHz16BitMono equ
    SPSF_32kHz16BitStereo equ
    SPSF_44kHz8BitMono equ
    SPSF_44kHz8BitStereo equ
    SPSF_44kHz16BitMono equ
    SPSF_44kHz16BitStereo equ
    SPSF_48kHz8BitMono equ
    SPSF_48kHz8BitStereo equ
    SPSF_48kHz16BitMono equ
    SPSF_48kHz16BitStereo equ
    SPSF_TrueSpeech_8kHz1BitMono equ
    SPSF_CCITT_ALaw_8kHzMono equ
    SPSF_CCITT_ALaw_8kHzStereo equ
    SPSF_CCITT_ALaw_11kHzMono equ
    SPSF_CCITT_ALaw_11kHzStereo equ
    SPSF_CCITT_ALaw_22kHzMono equ
    SPSF_CCITT_ALaw_22kHzStereo equ
    SPSF_CCITT_ALaw_44kHzMono equ
    SPSF_CCITT_ALaw_44kHzStereo equ
    SPSF_CCITT_uLaw_8kHzMono equ
    SPSF_CCITT_uLaw_8kHzStereo equ
    SPSF_CCITT_uLaw_11kHzMono equ
    SPSF_CCITT_uLaw_11kHzStereo equ
    SPSF_CCITT_uLaw_22kHzMono equ
    SPSF_CCITT_uLaw_22kHzStereo equ
    SPSF_CCITT_uLaw_44kHzMono equ
    SPSF_CCITT_uLaw_44kHzStereo equ
    SPSF_ADPCM_8kHzMono equ
    SPSF_ADPCM_8kHzStereo equ
    SPSF_ADPCM_11kHzMono equ
    SPSF_ADPCM_11kHzStereo equ
    SPSF_ADPCM_22kHzMono equ
    SPSF_ADPCM_22kHzStereo equ
    SPSF_ADPCM_44kHzMono equ
    SPSF_ADPCM_44kHzStereo equ
    SPSF_GSM610_8kHzMono equ
    SPSF_GSM610_11kHzMono equ
    SPSF_GSM610_22kHzMono equ
    SPSF_GSM610_44kHzMono equ
    SPSF_NUM_FORMATS equ

    externdef SPDFID_Text:GUID
    externdef SPDFID_WaveFormatEx:GUID
    SPREG_USER_ROOT equ <L("HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech")>
    SPREG_LOCAL_MACHINE_ROOT equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech")>
    SPCAT_AUDIOOUT equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput")>
    SPCAT_AUDIOIN equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput")>
    SPCAT_VOICES equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices")>
    SPCAT_RECOGNIZERS equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Recognizers")>
    SPCAT_APPLEXICONS equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AppLexicons")>
    SPCAT_PHONECONVERTERS equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\PhoneConverters")>
    SPCAT_TEXTNORMALIZERS equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\TextNormalizers")>
    SPCAT_RECOPROFILES equ <L("HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\RecoProfiles")>
    SPMMSYS_AUDIO_IN_TOKEN_ID equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput\TokenEnums\MMAudioIn\")>
    SPMMSYS_AUDIO_OUT_TOKEN_ID equ <L("HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput\TokenEnums\MMAudioOut\")>
    SPCURRENT_USER_LEXICON_TOKEN_ID equ <L("HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserLexicon")>
    SPTOKENVALUE_CLSID equ <L("CLSID")>
    SPTOKENKEY_FILES equ <L("Files")>
    SPTOKENKEY_UI equ <L("UI")>
    SPTOKENKEY_ATTRIBUTES equ <L("Attributes")>
    SPVOICECATEGORY_TTSRATE equ <L("DefaultTTSRate")>
    SPPROP_RESOURCE_USAGE equ <L("ResourceUsage")>
    SPPROP_HIGH_CONFIDENCE_THRESHOLD equ <L("HighConfidenceThreshold")>
    SPPROP_NORMAL_CONFIDENCE_THRESHOLD equ <L("NormalConfidenceThreshold")>
    SPPROP_LOW_CONFIDENCE_THRESHOLD equ <L("LowConfidenceThreshold")>
    SPPROP_RESPONSE_SPEED equ <L("ResponseSpeed")>
    SPPROP_COMPLEX_RESPONSE_SPEED equ <L("ComplexResponseSpeed")>
    SPPROP_ADAPTATION_ON equ <L("AdaptationOn")>
    SPPROP_PERSISTED_BACKGROUND_ADAPTATION equ <L("PersistedBackgroundAdaptation")>
    SPPROP_PERSISTED_LANGUAGE_MODEL_ADAPTATION equ <L("PersistedLanguageModelAdaptation")>
    SPPROP_UX_IS_LISTENING equ <L("UXIsListening")>
    SPTOPIC_SPELLING equ <L("Spelling")>
    SPWILDCARD equ <L("...")>
    SPDICTATION equ <L("*")>
    SPINFDICTATION equ <L("*+")>
    SP_LOW_CONFIDENCE equ (- 1)
    SP_NORMAL_CONFIDENCE equ (0)
    SP_HIGH_CONFIDENCE equ (+ 1)
    DEFAULT_WEIGHT equ (1)
    SP_MAX_WORD_LENGTH equ (128)
    SP_MAX_PRON_LENGTH equ (384)
    if Defined(__cplusplus)
      ;[...]
    else
      ISpNotifyCallback typedef ptr
    endif
    if 0
      ;[...]
    else
      SPNOTIFYCALLBACK typedef proto :WPARAM, :LPARAM
    endif
    externdef __MIDL_itf_sapi51_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpNotifySource_INTERFACE_DEFINED__
      __ISpNotifySource_INTERFACE_DEFINED__ equ <>
      ;* interface ISpNotifySource *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpNotifySource:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpNotifySourceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpNotifySourceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpNotifySource, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpNotifySource
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpNotifySource
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
          STD_METHOD SetNotifySink, :ptr ISpNotifySource, :ptr ISpNotifySink
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyWindowMessage, :ptr ISpNotifySource, :HWND, :UINT, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackFunction, :ptr ISpNotifySource, :ptr SPNOTIFYCALLBACK, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackInterface, :ptr ISpNotifySource, :ptr ISpNotifyCallback, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
          ;* [local] *
          STD_METHOD SetNotifyWin32Event, :ptr ISpNotifySource
          DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
          ;* [local] *
          STD_METHOD WaitForNotifyEvent, :ptr ISpNotifySource, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
          ;* [local] *
          STD_METHOD GetNotifyEventHandle, :ptr ISpNotifySource
          ??Interface equ <>
          END_INTERFACE
        ISpNotifySourceVtbl ends
        ISpNotifySource struct
          lpVtbl POINTER ?
        ISpNotifySource ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpNotifySource_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpNotifySink_INTERFACE_DEFINED__
      __ISpNotifySink_INTERFACE_DEFINED__ equ <>
      ;* interface ISpNotifySink *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpNotifySink:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpNotifySinkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpNotifySinkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpNotifySink, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpNotifySink
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpNotifySink
          DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
          STD_METHOD Notify, :ptr ISpNotifySink
          ??Interface equ <>
          END_INTERFACE
        ISpNotifySinkVtbl ends
        ISpNotifySink struct
          lpVtbl POINTER ?
        ISpNotifySink ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpNotifySink_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpNotifyTranslator_INTERFACE_DEFINED__
      __ISpNotifyTranslator_INTERFACE_DEFINED__ equ <>
      ;* interface ISpNotifyTranslator *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpNotifyTranslator:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpNotifyTranslatorVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpNotifyTranslatorVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpNotifyTranslator, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpNotifyTranslator
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpNotifyTranslator
          DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
          STD_METHOD Notify, :ptr ISpNotifyTranslator
          DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitWindowMessage)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD InitWindowMessage, :ptr ISpNotifyTranslator, :HWND, :UINT, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitCallback)
          ;* [in] *
          ;* [in] *
          STD_METHOD InitCallback, :ptr ISpNotifyTranslator, :ptr SPNOTIFYCALLBACK, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitSpNotifyCallback)
          ;* [in] *
          ;* [in] *
          STD_METHOD InitSpNotifyCallback, :ptr ISpNotifyTranslator, :ptr ISpNotifyCallback, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitWin32Event)
          ;* [in] *
          STD_METHOD InitWin32Event, :ptr ISpNotifyTranslator, :HANDLE, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifyTranslator, Wait)
          STD_METHOD Wait_, :ptr ISpNotifyTranslator, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifyTranslator, GetEventHandle)
          STD_METHOD GetEventHandle, :ptr ISpNotifyTranslator
          ??Interface equ <>
          END_INTERFACE
        ISpNotifyTranslatorVtbl ends
        ISpNotifyTranslator struct
          lpVtbl POINTER ?
        ISpNotifyTranslator ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpNotifyTranslator_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpDataKey_INTERFACE_DEFINED__
      __ISpDataKey_INTERFACE_DEFINED__ equ <>
      ;* interface ISpDataKey *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpDataKey:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpDataKeyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpDataKeyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpDataKey, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpDataKey
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, SetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetData, :ptr ISpDataKey, :LPCWSTR, :ULONG, :ptr BYTE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetData, :ptr ISpDataKey, :LPCWSTR, :ptr ULONG, :ptr BYTE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
          ;* [in][annotation] *
          STD_METHOD SetStringValue, :ptr ISpDataKey, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
          ;* [in][annotation] *
          ;* [out][annotation] *
          STD_METHOD GetStringValue, :ptr ISpDataKey, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
          ;* [in] *
          STD_METHOD SetDWORD, :ptr ISpDataKey, :LPCWSTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
          ;* [in] *
          STD_METHOD GetDWORD, :ptr ISpDataKey, :LPCWSTR, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD OpenKey, :ptr ISpDataKey, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD CreateKey, :ptr ISpDataKey, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
          STD_METHOD DeleteKey, :ptr ISpDataKey, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
          STD_METHOD DeleteValue, :ptr ISpDataKey, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumKeys, :ptr ISpDataKey, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumValues, :ptr ISpDataKey, :ULONG, :ptr LPWSTR
          ??Interface equ <>
          END_INTERFACE
        ISpDataKeyVtbl ends
        ISpDataKey struct
          lpVtbl POINTER ?
        ISpDataKey ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpDataKey_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpRegDataKey_INTERFACE_DEFINED__
      __ISpRegDataKey_INTERFACE_DEFINED__ equ <>
      ;* interface ISpRegDataKey *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpRegDataKey:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpRegDataKeyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpRegDataKeyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpRegDataKey, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpRegDataKey
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpRegDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, SetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetData, :ptr ISpRegDataKey, :LPCWSTR, :ULONG, :ptr BYTE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetData, :ptr ISpRegDataKey, :LPCWSTR, :ptr ULONG, :ptr BYTE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
          ;* [in][annotation] *
          STD_METHOD SetStringValue, :ptr ISpRegDataKey, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
          ;* [in][annotation] *
          ;* [out][annotation] *
          STD_METHOD GetStringValue, :ptr ISpRegDataKey, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
          ;* [in] *
          STD_METHOD SetDWORD, :ptr ISpRegDataKey, :LPCWSTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
          ;* [in] *
          STD_METHOD GetDWORD, :ptr ISpRegDataKey, :LPCWSTR, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD OpenKey, :ptr ISpRegDataKey, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD CreateKey, :ptr ISpRegDataKey, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
          STD_METHOD DeleteKey, :ptr ISpRegDataKey, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
          STD_METHOD DeleteValue, :ptr ISpRegDataKey, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumKeys, :ptr ISpRegDataKey, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumValues, :ptr ISpRegDataKey, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpRegDataKey, SetKey)
          ;* [local] *
          ;* [in] *
          STD_METHOD SetKey, :ptr ISpRegDataKey, :HKEY, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpRegDataKeyVtbl ends
        ISpRegDataKey struct
          lpVtbl POINTER ?
        ISpRegDataKey ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpRegDataKey_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpObjectTokenCategory_INTERFACE_DEFINED__
      __ISpObjectTokenCategory_INTERFACE_DEFINED__ equ <>
      ;* interface ISpObjectTokenCategory *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpObjectTokenCategory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpObjectTokenCategoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpObjectTokenCategoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpObjectTokenCategory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpObjectTokenCategory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpObjectTokenCategory
          DECLSPEC_XFGVIRT(ISpDataKey, SetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetData, :ptr ISpObjectTokenCategory, :LPCWSTR, :ULONG, :ptr BYTE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetData, :ptr ISpObjectTokenCategory, :LPCWSTR, :ptr ULONG, :ptr BYTE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
          ;* [in][annotation] *
          STD_METHOD SetStringValue, :ptr ISpObjectTokenCategory, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
          ;* [in][annotation] *
          ;* [out][annotation] *
          STD_METHOD GetStringValue, :ptr ISpObjectTokenCategory, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
          ;* [in] *
          STD_METHOD SetDWORD, :ptr ISpObjectTokenCategory, :LPCWSTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
          ;* [in] *
          STD_METHOD GetDWORD, :ptr ISpObjectTokenCategory, :LPCWSTR, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD OpenKey, :ptr ISpObjectTokenCategory, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD CreateKey, :ptr ISpObjectTokenCategory, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
          STD_METHOD DeleteKey, :ptr ISpObjectTokenCategory, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
          STD_METHOD DeleteValue, :ptr ISpObjectTokenCategory, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumKeys, :ptr ISpObjectTokenCategory, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumValues, :ptr ISpObjectTokenCategory, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectTokenCategory, SetId)
          ;* [in] *
          STD_METHOD SetId, :ptr ISpObjectTokenCategory, :LPCWSTR, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectTokenCategory, GetId)
          ;* [out][annotation] *
          STD_METHOD GetId, :ptr ISpObjectTokenCategory, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectTokenCategory, GetDataKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetDataKey, :ptr ISpObjectTokenCategory, :SPDATAKEYLOCATION, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpObjectTokenCategory, EnumTokens)
          ;* [string][in][annotation] *
          ;* [string][in][annotation] *
          STD_METHOD EnumTokens, :ptr ISpObjectTokenCategory, :LPCWSTR, :LPCWSTR, :ptr ptr IEnumSpObjectTokens
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpObjectTokenCategory, SetDefaultTokenId)
          STD_METHOD SetDefaultTokenId, :ptr ISpObjectTokenCategory, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectTokenCategory, GetDefaultTokenId)
          ;* [out][annotation] *
          STD_METHOD GetDefaultTokenId, :ptr ISpObjectTokenCategory, :ptr LPWSTR
          ??Interface equ <>
          END_INTERFACE
        ISpObjectTokenCategoryVtbl ends
        ISpObjectTokenCategory struct
          lpVtbl POINTER ?
        ISpObjectTokenCategory ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpObjectTokenCategory_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpObjectToken_INTERFACE_DEFINED__
      __ISpObjectToken_INTERFACE_DEFINED__ equ <>
      ;* interface ISpObjectToken *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpObjectToken:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpObjectTokenVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpObjectTokenVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpObjectToken, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpObjectToken
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpObjectToken
          DECLSPEC_XFGVIRT(ISpDataKey, SetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetData, :ptr ISpObjectToken, :LPCWSTR, :ULONG, :ptr BYTE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetData, :ptr ISpObjectToken, :LPCWSTR, :ptr ULONG, :ptr BYTE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
          ;* [in][annotation] *
          STD_METHOD SetStringValue, :ptr ISpObjectToken, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
          ;* [in][annotation] *
          ;* [out][annotation] *
          STD_METHOD GetStringValue, :ptr ISpObjectToken, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
          ;* [in] *
          STD_METHOD SetDWORD, :ptr ISpObjectToken, :LPCWSTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
          ;* [in] *
          STD_METHOD GetDWORD, :ptr ISpObjectToken, :LPCWSTR, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD OpenKey, :ptr ISpObjectToken, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD CreateKey, :ptr ISpObjectToken, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
          STD_METHOD DeleteKey, :ptr ISpObjectToken, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
          STD_METHOD DeleteValue, :ptr ISpObjectToken, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumKeys, :ptr ISpObjectToken, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumValues, :ptr ISpObjectToken, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectToken, SetId)
          ;* [annotation] *
          ;* [in] *
          STD_METHOD SetId, :ptr ISpObjectToken, :LPCWSTR, :LPCWSTR, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectToken, GetId)
          ;* [out][annotation] *
          STD_METHOD GetId, :ptr ISpObjectToken, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectToken, GetCategory)
          ;* [out][annotation] *
          STD_METHOD GetCategory, :ptr ISpObjectToken, :ptr ptr ISpObjectTokenCategory
          DECLSPEC_XFGVIRT(ISpObjectToken, CreateInstance)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateInstance, :ptr ISpObjectToken, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(ISpObjectToken, GetStorageFileName)
          ;* [in] *
          ;* [annotation][in] *
          ;* [string][in][annotation] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetStorageFileName, :ptr ISpObjectToken, :REFCLSID, :LPCWSTR, :LPCWSTR, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectToken, RemoveStorageFileName)
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD RemoveStorageFileName, :ptr ISpObjectToken, :REFCLSID, :LPCWSTR, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectToken, Remove)
          ;* [annotation] *
          STD_METHOD Remove, :ptr ISpObjectToken, :ptr CLSID
          DECLSPEC_XFGVIRT(ISpObjectToken, IsUISupported)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD IsUISupported, :ptr ISpObjectToken, :LPCWSTR, :ptr, :ULONG, :ptr IUnknown, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpObjectToken, DisplayUI)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DisplayUI, :ptr ISpObjectToken, :HWND, :LPCWSTR, :LPCWSTR, :ptr, :ULONG, :ptr IUnknown
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectToken, MatchesAttributes)
          ;* [in] *
          STD_METHOD MatchesAttributes, :ptr ISpObjectToken, :LPCWSTR, :ptr BOOL
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpObjectTokenVtbl ends
        ISpObjectToken struct
          lpVtbl POINTER ?
        ISpObjectToken ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpObjectToken_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpObjectTokenInit_INTERFACE_DEFINED__
      __ISpObjectTokenInit_INTERFACE_DEFINED__ equ <>
      ;* interface ISpObjectTokenInit *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpObjectTokenInit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpObjectTokenInitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpObjectTokenInitVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpObjectTokenInit, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpObjectTokenInit
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpObjectTokenInit
          DECLSPEC_XFGVIRT(ISpDataKey, SetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetData, :ptr ISpObjectTokenInit, :LPCWSTR, :ULONG, :ptr BYTE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetData, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr ULONG, :ptr BYTE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
          ;* [in][annotation] *
          STD_METHOD SetStringValue, :ptr ISpObjectTokenInit, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
          ;* [in][annotation] *
          ;* [out][annotation] *
          STD_METHOD GetStringValue, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
          ;* [in] *
          STD_METHOD SetDWORD, :ptr ISpObjectTokenInit, :LPCWSTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
          ;* [in] *
          STD_METHOD GetDWORD, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD OpenKey, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD CreateKey, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr ptr ISpDataKey
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
          STD_METHOD DeleteKey, :ptr ISpObjectTokenInit, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
          STD_METHOD DeleteValue, :ptr ISpObjectTokenInit, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumKeys, :ptr ISpObjectTokenInit, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD EnumValues, :ptr ISpObjectTokenInit, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectToken, SetId)
          ;* [annotation] *
          ;* [in] *
          STD_METHOD SetId, :ptr ISpObjectTokenInit, :LPCWSTR, :LPCWSTR, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectToken, GetId)
          ;* [out][annotation] *
          STD_METHOD GetId, :ptr ISpObjectTokenInit, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectToken, GetCategory)
          ;* [out][annotation] *
          STD_METHOD GetCategory, :ptr ISpObjectTokenInit, :ptr ptr ISpObjectTokenCategory
          DECLSPEC_XFGVIRT(ISpObjectToken, CreateInstance)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateInstance, :ptr ISpObjectTokenInit, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(ISpObjectToken, GetStorageFileName)
          ;* [in] *
          ;* [annotation][in] *
          ;* [string][in][annotation] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetStorageFileName, :ptr ISpObjectTokenInit, :REFCLSID, :LPCWSTR, :LPCWSTR, :ULONG, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpObjectToken, RemoveStorageFileName)
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD RemoveStorageFileName, :ptr ISpObjectTokenInit, :REFCLSID, :LPCWSTR, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectToken, Remove)
          ;* [annotation] *
          STD_METHOD Remove, :ptr ISpObjectTokenInit, :ptr CLSID
          DECLSPEC_XFGVIRT(ISpObjectToken, IsUISupported)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD IsUISupported, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr, :ULONG, :ptr IUnknown, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpObjectToken, DisplayUI)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DisplayUI, :ptr ISpObjectTokenInit, :HWND, :LPCWSTR, :LPCWSTR, :ptr, :ULONG, :ptr IUnknown
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectToken, MatchesAttributes)
          ;* [in] *
          STD_METHOD MatchesAttributes, :ptr ISpObjectTokenInit, :LPCWSTR, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpObjectTokenInit, InitFromDataKey)
          ;* [in] *
          ;* [in] *
          STD_METHOD InitFromDataKey, :ptr ISpObjectTokenInit, :LPCWSTR, :LPCWSTR, :ptr ISpDataKey
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpObjectTokenInitVtbl ends
        ISpObjectTokenInit struct
          lpVtbl POINTER ?
        ISpObjectTokenInit ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpObjectTokenInit_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumSpObjectTokens_INTERFACE_DEFINED__
      __IEnumSpObjectTokens_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumSpObjectTokens *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_IEnumSpObjectTokens:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumSpObjectTokensVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumSpObjectTokensVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumSpObjectTokens, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumSpObjectTokens
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumSpObjectTokens
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Next)
          ;* [in] *
          ;* [length_is][size_is][out] *
          ;* [out][annotation] *
          STD_METHOD Next, :ptr IEnumSpObjectTokens, :ULONG, :ptr ptr ISpObjectToken, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Skip)
          STD_METHOD Skip, :ptr IEnumSpObjectTokens, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Reset)
          STD_METHOD Reset, :ptr IEnumSpObjectTokens
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Clone)
          STD_METHOD Clone, :ptr IEnumSpObjectTokens, :ptr ptr IEnumSpObjectTokens
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Item)
          ;* [in] *
          STD_METHOD Item, :ptr IEnumSpObjectTokens, :ULONG, :ptr ptr ISpObjectToken
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, GetCount)
          STD_METHOD GetCount, :ptr IEnumSpObjectTokens, :ptr ULONG
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumSpObjectTokensVtbl ends
        IEnumSpObjectTokens struct
          lpVtbl POINTER ?
        IEnumSpObjectTokens ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IEnumSpObjectTokens_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpObjectWithToken_INTERFACE_DEFINED__
      __ISpObjectWithToken_INTERFACE_DEFINED__ equ <>
      ;* interface ISpObjectWithToken *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpObjectWithToken:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpObjectWithTokenVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpObjectWithTokenVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpObjectWithToken, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpObjectWithToken
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpObjectWithToken
          DECLSPEC_XFGVIRT(ISpObjectWithToken, SetObjectToken)
          STD_METHOD SetObjectToken, :ptr ISpObjectWithToken, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectWithToken, GetObjectToken)
          STD_METHOD GetObjectToken, :ptr ISpObjectWithToken, :ptr ptr ISpObjectToken
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpObjectWithTokenVtbl ends
        ISpObjectWithToken struct
          lpVtbl POINTER ?
        ISpObjectWithToken ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpObjectWithToken_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpResourceManager_INTERFACE_DEFINED__
      __ISpResourceManager_INTERFACE_DEFINED__ equ <>
      ;* interface ISpResourceManager *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpResourceManager:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpResourceManagerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpResourceManagerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpResourceManager, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpResourceManager
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpResourceManager
          DECLSPEC_XFGVIRT(IServiceProvider, QueryService)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD QueryService, :ptr ISpResourceManager, :REFGUID, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(ISpResourceManager, SetObject)
          ;* [in] *
          STD_METHOD SetObject_, :ptr ISpResourceManager, :REFGUID, :ptr IUnknown
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpResourceManager, GetObject)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetObject, :ptr ISpResourceManager, :REFGUID, :REFCLSID, :REFIID, :BOOL, :ptr ptr
          ;* [iid_is][out] *
          ??Interface equ <>
          END_INTERFACE
        ISpResourceManagerVtbl ends
        ISpResourceManager struct
          lpVtbl POINTER ?
        ISpResourceManager ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpResourceManager_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0011 *
    ;* [local] *
    ;* [hidden] *
    SPEVENTLPARAMTYPE typedef SDWORD
    SPET_LPARAM_IS_UNDEFINED equ 0
    SPET_LPARAM_IS_TOKEN equ
    SPET_LPARAM_IS_OBJECT equ
    SPET_LPARAM_IS_POINTER equ
    SPET_LPARAM_IS_STRING equ

    ;* [hidden] *
    SPEVENTENUM typedef SDWORD
    SPEI_UNDEFINED equ 0
    SPEI_START_INPUT_STREAM equ 1
    SPEI_END_INPUT_STREAM equ 2
    SPEI_VOICE_CHANGE equ 3
    SPEI_TTS_BOOKMARK equ 4
    SPEI_WORD_BOUNDARY equ 5
    SPEI_PHONEME equ 6
    SPEI_SENTENCE_BOUNDARY equ 7
    SPEI_VISEME equ 8
    SPEI_TTS_AUDIO_LEVEL equ 9
    SPEI_TTS_PRIVATE equ 15
    SPEI_MIN_TTS equ 1
    SPEI_MAX_TTS equ 15
    SPEI_END_SR_STREAM equ 34
    SPEI_SOUND_START equ 35
    SPEI_SOUND_END equ 36
    SPEI_PHRASE_START equ 37
    SPEI_RECOGNITION equ 38
    SPEI_HYPOTHESIS equ 39
    SPEI_SR_BOOKMARK equ 40
    SPEI_PROPERTY_NUM_CHANGE equ 41
    SPEI_PROPERTY_STRING_CHANGE equ 42
    SPEI_FALSE_RECOGNITION equ 43
    SPEI_INTERFERENCE equ 44
    SPEI_REQUEST_UI equ 45
    SPEI_RECO_STATE_CHANGE equ 46
    SPEI_ADAPTATION equ 47
    SPEI_START_SR_STREAM equ 48
    SPEI_RECO_OTHER_CONTEXT equ 49
    SPEI_SR_AUDIO_LEVEL equ 50
    SPEI_SR_PRIVATE equ 52
    SPEI_MIN_SR equ 34
    SPEI_MAX_SR equ 52
    SPEI_RESERVED1 equ 30
    SPEI_RESERVED2 equ 33
    SPEI_RESERVED3 equ 63

    SPFEI_FLAGCHECK equ ((1 shl SPEI_RESERVED1) or (1 shl SPEI_RESERVED2))
    SPFEI_ALL_TTS_EVENTS equ (000000000000FFFEh or SPFEI_FLAGCHECK)
    SPFEI_ALL_SR_EVENTS equ (003FFFFC00000000h or SPFEI_FLAGCHECK)
    SPFEI_ALL_EVENTS equ 0EFFFFFFFFFFFFFFFh
    SPFEI macro SPEI_ord
      exitm <((1 shl SPEI_ord) or SPFEI_FLAGCHECK)>
    endm
    if 0
      ;[...]
    else
      SPEVENT struct
        SPEVENT_REC record SPEVENT_REC_elParamType:16, SPEVENT_REC_eEventId:16
        SPEVENT_BITS SPEVENT_REC <>
        ulStreamNum DWORD ?
        ullAudioStreamOffset QWORD ?
        wParam WPARAM ?
        lParam LPARAM ?
      SPEVENT ends
      SPSERIALIZEDEVENT struct
        SPSERIALIZEDEVENT_REC record SPSERIALIZEDEVENT_REC_elParamType:16, SPSERIALIZEDEVENT_REC_eEventId:16
        SPSERIALIZEDEVENT_BITS SPSERIALIZEDEVENT_REC <>
        ulStreamNum DWORD ?
        ullAudioStreamOffset QWORD ?
        SerializedwParam DWORD ?
        SerializedlParam SDWORD ?
      SPSERIALIZEDEVENT ends
      SPSERIALIZEDEVENT64 struct
        SPSERIALIZEDEVENT64_REC record SPSERIALIZEDEVENT64_REC_elParamType:16, SPSERIALIZEDEVENT64_REC_eEventId:16
        SPSERIALIZEDEVENT64_BITS SPSERIALIZEDEVENT64_REC <>
        ulStreamNum DWORD ?
        ullAudioStreamOffset QWORD ?
        SerializedwParam QWORD ?
        SerializedlParam SQWORD ?
      SPSERIALIZEDEVENT64 ends
    endif
    ;* [hidden] *
    SPINTERFERENCE typedef SDWORD
    SPINTERFERENCE_NONE equ 0
    SPINTERFERENCE_NOISE equ
    SPINTERFERENCE_NOSIGNAL equ
    SPINTERFERENCE_TOOLOUD equ
    SPINTERFERENCE_TOOQUIET equ
    SPINTERFERENCE_TOOFAST equ
    SPINTERFERENCE_TOOSLOW equ
    SPINTERFERENCE_LATENCY_WARNING equ
    SPINTERFERENCE_LATENCY_TRUNCATE_BEGIN equ
    SPINTERFERENCE_LATENCY_TRUNCATE_END equ

    ;* [hidden] *
    SPENDSRSTREAMFLAGS typedef SDWORD
    SPESF_NONE equ 0
    SPESF_STREAM_RELEASED equ

    ;* [hidden] *
    SPVFEATURE typedef SDWORD
    SPVFEATURE_STRESSED equ
    SPVFEATURE_EMPHASIS equ

    ;* [hidden] *
    SPVISEMES typedef SDWORD
    SP_VISEME_0 equ 0
    SP_VISEME_1 equ
    SP_VISEME_2 equ
    SP_VISEME_3 equ
    SP_VISEME_4 equ
    SP_VISEME_5 equ
    SP_VISEME_6 equ
    SP_VISEME_7 equ
    SP_VISEME_8 equ
    SP_VISEME_9 equ
    SP_VISEME_10 equ
    SP_VISEME_11 equ
    SP_VISEME_12 equ
    SP_VISEME_13 equ
    SP_VISEME_14 equ
    SP_VISEME_15 equ
    SP_VISEME_16 equ
    SP_VISEME_17 equ
    SP_VISEME_18 equ
    SP_VISEME_19 equ
    SP_VISEME_20 equ
    SP_VISEME_21 equ

    ;* [hidden][restricted] *
    SPEVENTSOURCEINFO struct
      ullEventInterest QWORD ?
      ullQueuedInterest QWORD ?
      ulCount DWORD ?
    SPEVENTSOURCEINFO ends
    externdef __MIDL_itf_sapi51_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpEventSource_INTERFACE_DEFINED__
      __ISpEventSource_INTERFACE_DEFINED__ equ <>
      ;* interface ISpEventSource *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpEventSource:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpEventSourceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpEventSourceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpEventSource, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpEventSource
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpEventSource
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
          STD_METHOD SetNotifySink, :ptr ISpEventSource, :ptr ISpNotifySink
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyWindowMessage, :ptr ISpEventSource, :HWND, :UINT, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackFunction, :ptr ISpEventSource, :ptr SPNOTIFYCALLBACK, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackInterface, :ptr ISpEventSource, :ptr ISpNotifyCallback, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
          ;* [local] *
          STD_METHOD SetNotifyWin32Event, :ptr ISpEventSource
          DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
          ;* [local] *
          STD_METHOD WaitForNotifyEvent, :ptr ISpEventSource, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
          ;* [local] *
          STD_METHOD GetNotifyEventHandle, :ptr ISpEventSource
          DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
          ;* [in] *
          STD_METHOD SetInterest, :ptr ISpEventSource, :ULONGLONG, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
          ;* [in] *
          ;* [size_is][out] *
          STD_METHOD GetEvents, :ptr ISpEventSource, :ULONG, :ptr SPEVENT, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
          STD_METHOD GetInfo, :ptr ISpEventSource, :ptr SPEVENTSOURCEINFO
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpEventSourceVtbl ends
        ISpEventSource struct
          lpVtbl POINTER ?
        ISpEventSource ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpEventSource_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpEventSink_INTERFACE_DEFINED__
      __ISpEventSink_INTERFACE_DEFINED__ equ <>
      ;* interface ISpEventSink *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpEventSink:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpEventSinkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpEventSinkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpEventSink, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpEventSink
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpEventSink
          DECLSPEC_XFGVIRT(ISpEventSink, AddEvents)
          ;* [in] *
          STD_METHOD AddEvents, :ptr ISpEventSink, :ptr SPEVENT, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpEventSink, GetEventInterest)
          STD_METHOD GetEventInterest, :ptr ISpEventSink, :ptr ULONGLONG
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpEventSinkVtbl ends
        ISpEventSink struct
          lpVtbl POINTER ?
        ISpEventSink ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpEventSink_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpStreamFormat_INTERFACE_DEFINED__
      __ISpStreamFormat_INTERFACE_DEFINED__ equ <>
      ;* interface ISpStreamFormat *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpStreamFormat:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpStreamFormatVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpStreamFormatVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpStreamFormat, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpStreamFormat
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpStreamFormat
          DECLSPEC_XFGVIRT(ISequentialStream, Read)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Read, :ptr ISpStreamFormat, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ISequentialStream, Write)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Write, :ptr ISpStreamFormat, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IStream, Seek)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation] *
          STD_METHOD Seek, :ptr ISpStreamFormat, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, SetSize)
          STD_METHOD SetSize, :ptr ISpStreamFormat, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, CopyTo)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD CopyTo, :ptr ISpStreamFormat, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, Commit)
          STD_METHOD Commit, :ptr ISpStreamFormat, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Revert)
          STD_METHOD Revert, :ptr ISpStreamFormat
          DECLSPEC_XFGVIRT(IStream, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr ISpStreamFormat, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr ISpStreamFormat, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr ISpStreamFormat, :ptr STATSTG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Clone)
          STD_METHOD Clone, :ptr ISpStreamFormat, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
          ;* [in] *
          STD_METHOD GetFormat, :ptr ISpStreamFormat, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpStreamFormatVtbl ends
        ISpStreamFormat struct
          lpVtbl POINTER ?
        ISpStreamFormat ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpStreamFormat_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0014 *
    ;* [local] *
    ;* [hidden] *
    SPFILEMODE typedef SDWORD
    SPFM_OPEN_READONLY equ 0
    SPFM_OPEN_READWRITE equ
    SPFM_CREATE equ
    SPFM_CREATE_ALWAYS equ
    SPFM_NUM_MODES equ

    externdef __MIDL_itf_sapi51_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpStream_INTERFACE_DEFINED__
      __ISpStream_INTERFACE_DEFINED__ equ <>
      ;* interface ISpStream *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpStream:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpStreamVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpStreamVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpStream, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpStream
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpStream
          DECLSPEC_XFGVIRT(ISequentialStream, Read)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Read, :ptr ISpStream, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ISequentialStream, Write)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Write, :ptr ISpStream, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IStream, Seek)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation] *
          STD_METHOD Seek, :ptr ISpStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, SetSize)
          STD_METHOD SetSize, :ptr ISpStream, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, CopyTo)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD CopyTo, :ptr ISpStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, Commit)
          STD_METHOD Commit, :ptr ISpStream, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Revert)
          STD_METHOD Revert, :ptr ISpStream
          DECLSPEC_XFGVIRT(IStream, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr ISpStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr ISpStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr ISpStream, :ptr STATSTG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Clone)
          STD_METHOD Clone, :ptr ISpStream, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
          ;* [in] *
          STD_METHOD GetFormat, :ptr ISpStream, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStream, SetBaseStream)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetBaseStream, :ptr ISpStream, :ptr IStream, :REFGUID, :ptr WAVEFORMATEX
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpStream, GetBaseStream)
          ;* [out][annotation] *
          STD_METHOD GetBaseStream, :ptr ISpStream, :ptr ptr IStream
          DECLSPEC_XFGVIRT(ISpStream, BindToFile)
          ;* [in][annotation] *
          ;* [in] *
          ;* [in][annotation] *
          ;* [annotation] *
          STD_METHOD BindToFile, :ptr ISpStream, :LPCWSTR, :SPFILEMODE, :ptr GUID, :ptr WAVEFORMATEX, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpStream, Close)
          STD_METHOD Close, :ptr ISpStream
          ??Interface equ <>
          END_INTERFACE
        ISpStreamVtbl ends
        ISpStream struct
          lpVtbl POINTER ?
        ISpStream ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpStream_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpStreamFormatConverter_INTERFACE_DEFINED__
      __ISpStreamFormatConverter_INTERFACE_DEFINED__ equ <>
      ;* interface ISpStreamFormatConverter *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpStreamFormatConverter:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpStreamFormatConverterVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpStreamFormatConverterVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpStreamFormatConverter, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpStreamFormatConverter
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpStreamFormatConverter
          DECLSPEC_XFGVIRT(ISequentialStream, Read)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Read, :ptr ISpStreamFormatConverter, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ISequentialStream, Write)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Write, :ptr ISpStreamFormatConverter, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IStream, Seek)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation] *
          STD_METHOD Seek, :ptr ISpStreamFormatConverter, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, SetSize)
          STD_METHOD SetSize, :ptr ISpStreamFormatConverter, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, CopyTo)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD CopyTo, :ptr ISpStreamFormatConverter, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, Commit)
          STD_METHOD Commit, :ptr ISpStreamFormatConverter, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Revert)
          STD_METHOD Revert, :ptr ISpStreamFormatConverter
          DECLSPEC_XFGVIRT(IStream, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr ISpStreamFormatConverter, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr ISpStreamFormatConverter, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr ISpStreamFormatConverter, :ptr STATSTG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Clone)
          STD_METHOD Clone, :ptr ISpStreamFormatConverter, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
          ;* [in] *
          STD_METHOD GetFormat, :ptr ISpStreamFormatConverter, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormatConverter, SetBaseStream)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetBaseStream, :ptr ISpStreamFormatConverter, :ptr ISpStreamFormat, :BOOL, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpStreamFormatConverter, GetBaseStream)
          STD_METHOD GetBaseStream, :ptr ISpStreamFormatConverter, :ptr ptr ISpStreamFormat
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormatConverter, SetFormat)
          ;* [in] *
          STD_METHOD SetFormat, :ptr ISpStreamFormatConverter, :REFGUID, :ptr WAVEFORMATEX
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpStreamFormatConverter, ResetSeekPosition)
          STD_METHOD ResetSeekPosition, :ptr ISpStreamFormatConverter
          DECLSPEC_XFGVIRT(ISpStreamFormatConverter, ScaleConvertedToBaseOffset)
          ;* [in] *
          STD_METHOD ScaleConvertedToBaseOffset, :ptr ISpStreamFormatConverter, :ULONGLONG, :ptr ULONGLONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormatConverter, ScaleBaseToConvertedOffset)
          ;* [in] *
          STD_METHOD ScaleBaseToConvertedOffset, :ptr ISpStreamFormatConverter, :ULONGLONG, :ptr ULONGLONG
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpStreamFormatConverterVtbl ends
        ISpStreamFormatConverter struct
          lpVtbl POINTER ?
        ISpStreamFormatConverter ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpStreamFormatConverter_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0016 *
    ;* [local] *
    ;* [hidden] *
    SPAUDIOSTATE typedef SDWORD
    SPAS_CLOSED equ 0
    SPAS_STOP equ
    SPAS_PAUSE equ
    SPAS_RUN equ
    _SPAUDIOSTATE typedef SPAUDIOSTATE

    ;* [hidden][restricted] *
    SPAUDIOSTATUS struct
      cbFreeBuffSpace SDWORD ?
      cbNonBlockingIO DWORD ?
      State SPAUDIOSTATE ?
      CurSeekPos QWORD ?
      CurDevicePos QWORD ?
      dwAudioLevel DWORD ?
      dwReserved2 DWORD ?
    SPAUDIOSTATUS ends
    ;* [hidden][restricted] *
    SPAUDIOBUFFERINFO struct
      ulMsMinNotification DWORD ?
      ulMsBufferSize DWORD ?
      ulMsEventBias DWORD ?
    SPAUDIOBUFFERINFO ends
    externdef __MIDL_itf_sapi51_0000_0016_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0016_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpAudio_INTERFACE_DEFINED__
      __ISpAudio_INTERFACE_DEFINED__ equ <>
      ;* interface ISpAudio *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpAudio:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpAudioVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpAudioVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpAudio, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpAudio
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpAudio
          DECLSPEC_XFGVIRT(ISequentialStream, Read)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Read, :ptr ISpAudio, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ISequentialStream, Write)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Write, :ptr ISpAudio, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IStream, Seek)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation] *
          STD_METHOD Seek, :ptr ISpAudio, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, SetSize)
          STD_METHOD SetSize, :ptr ISpAudio, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, CopyTo)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD CopyTo, :ptr ISpAudio, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, Commit)
          STD_METHOD Commit, :ptr ISpAudio, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Revert)
          STD_METHOD Revert, :ptr ISpAudio
          DECLSPEC_XFGVIRT(IStream, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr ISpAudio, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr ISpAudio, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr ISpAudio, :ptr STATSTG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Clone)
          STD_METHOD Clone, :ptr ISpAudio, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
          ;* [in] *
          STD_METHOD GetFormat, :ptr ISpAudio, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetState)
          ;* [in] *
          STD_METHOD SetState, :ptr ISpAudio, :SPAUDIOSTATE, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, SetFormat)
          ;* [in] *
          STD_METHOD SetFormat, :ptr ISpAudio, :REFGUID, :ptr WAVEFORMATEX
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, GetStatus)
          STD_METHOD GetStatus, :ptr ISpAudio, :ptr SPAUDIOSTATUS
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetBufferInfo)
          STD_METHOD SetBufferInfo, :ptr ISpAudio, :ptr SPAUDIOBUFFERINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, GetBufferInfo)
          STD_METHOD GetBufferInfo, :ptr ISpAudio, :ptr SPAUDIOBUFFERINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, GetDefaultFormat)
          ;* [out] *
          STD_METHOD GetDefaultFormat, :ptr ISpAudio, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, EventHandle)
          STD_METHOD EventHandle, :ptr ISpAudio
          DECLSPEC_XFGVIRT(ISpAudio, GetVolumeLevel)
          STD_METHOD GetVolumeLevel, :ptr ISpAudio, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetVolumeLevel)
          STD_METHOD SetVolumeLevel, :ptr ISpAudio, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, GetBufferNotifySize)
          STD_METHOD GetBufferNotifySize, :ptr ISpAudio, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetBufferNotifySize)
          STD_METHOD SetBufferNotifySize, :ptr ISpAudio, :ULONG
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpAudioVtbl ends
        ISpAudio struct
          lpVtbl POINTER ?
        ISpAudio ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpAudio_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpMMSysAudio_INTERFACE_DEFINED__
      __ISpMMSysAudio_INTERFACE_DEFINED__ equ <>
      ;* interface ISpMMSysAudio *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpMMSysAudio:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpMMSysAudioVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpMMSysAudioVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpMMSysAudio, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpMMSysAudio
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpMMSysAudio
          DECLSPEC_XFGVIRT(ISequentialStream, Read)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Read, :ptr ISpMMSysAudio, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ISequentialStream, Write)
          ;* [local] *
          ;* [annotation] *
          ;* [annotation][in] *
          ;* [annotation] *
          STD_METHOD Write, :ptr ISpMMSysAudio, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IStream, Seek)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation] *
          STD_METHOD Seek, :ptr ISpMMSysAudio, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, SetSize)
          STD_METHOD SetSize, :ptr ISpMMSysAudio, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, CopyTo)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD CopyTo, :ptr ISpMMSysAudio, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
          DECLSPEC_XFGVIRT(IStream, Commit)
          STD_METHOD Commit, :ptr ISpMMSysAudio, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Revert)
          STD_METHOD Revert, :ptr ISpMMSysAudio
          DECLSPEC_XFGVIRT(IStream, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr ISpMMSysAudio, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr ISpMMSysAudio, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr ISpMMSysAudio, :ptr STATSTG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStream, Clone)
          STD_METHOD Clone, :ptr ISpMMSysAudio, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
          ;* [in] *
          STD_METHOD GetFormat, :ptr ISpMMSysAudio, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetState)
          ;* [in] *
          STD_METHOD SetState, :ptr ISpMMSysAudio, :SPAUDIOSTATE, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, SetFormat)
          ;* [in] *
          STD_METHOD SetFormat, :ptr ISpMMSysAudio, :REFGUID, :ptr WAVEFORMATEX
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, GetStatus)
          STD_METHOD GetStatus, :ptr ISpMMSysAudio, :ptr SPAUDIOSTATUS
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetBufferInfo)
          STD_METHOD SetBufferInfo, :ptr ISpMMSysAudio, :ptr SPAUDIOBUFFERINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, GetBufferInfo)
          STD_METHOD GetBufferInfo, :ptr ISpMMSysAudio, :ptr SPAUDIOBUFFERINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, GetDefaultFormat)
          ;* [out] *
          STD_METHOD GetDefaultFormat, :ptr ISpMMSysAudio, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, EventHandle)
          STD_METHOD EventHandle, :ptr ISpMMSysAudio
          DECLSPEC_XFGVIRT(ISpAudio, GetVolumeLevel)
          STD_METHOD GetVolumeLevel, :ptr ISpMMSysAudio, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetVolumeLevel)
          STD_METHOD SetVolumeLevel, :ptr ISpMMSysAudio, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpAudio, GetBufferNotifySize)
          STD_METHOD GetBufferNotifySize, :ptr ISpMMSysAudio, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpAudio, SetBufferNotifySize)
          STD_METHOD SetBufferNotifySize, :ptr ISpMMSysAudio, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpMMSysAudio, GetDeviceId)
          STD_METHOD GetDeviceId, :ptr ISpMMSysAudio, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpMMSysAudio, SetDeviceId)
          STD_METHOD SetDeviceId, :ptr ISpMMSysAudio, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpMMSysAudio, GetMMHandle)
          STD_METHOD GetMMHandle, :ptr ISpMMSysAudio, :ptr ptr
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpMMSysAudio, GetLineId)
          STD_METHOD GetLineId, :ptr ISpMMSysAudio, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpMMSysAudio, SetLineId)
          STD_METHOD SetLineId, :ptr ISpMMSysAudio, :UINT
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpMMSysAudioVtbl ends
        ISpMMSysAudio struct
          lpVtbl POINTER ?
        ISpMMSysAudio ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpMMSysAudio_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpTranscript_INTERFACE_DEFINED__
      __ISpTranscript_INTERFACE_DEFINED__ equ <>
      ;* interface ISpTranscript *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpTranscript:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpTranscriptVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpTranscriptVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpTranscript, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpTranscript
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpTranscript
          DECLSPEC_XFGVIRT(ISpTranscript, GetTranscript)
          STD_METHOD GetTranscript, :ptr ISpTranscript, :ptr LPWSTR
          ;* [string][out] *
          DECLSPEC_XFGVIRT(ISpTranscript, AppendTranscript)
          STD_METHOD AppendTranscript, :ptr ISpTranscript, :LPCWSTR
          ;* [string][in] *
          ??Interface equ <>
          END_INTERFACE
        ISpTranscriptVtbl ends
        ISpTranscript struct
          lpVtbl POINTER ?
        ISpTranscript ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpTranscript_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0019 *
    ;* [local] *
    ;* [hidden] *
    SPDISPLAYATTRIBUTES typedef SDWORD
    SPAF_ONE_TRAILING_SPACE equ 2h
    SPAF_TWO_TRAILING_SPACES equ 4h
    SPAF_CONSUME_LEADING_SPACES equ 8h
    SPAF_ALL equ 0fh
    SPDISPLYATTRIBUTES typedef SPDISPLAYATTRIBUTES

    SPPHONEID typedef WCHAR
    PSPPHONEID typedef LPWSTR
    PCSPPHONEID typedef LPCWSTR
    ;* [hidden][restricted] *
    SPPHRASEELEMENT struct
      ulAudioTimeOffset DWORD ?
      ulAudioSizeTime DWORD ?
      ulAudioStreamOffset DWORD ?
      ulAudioSizeBytes DWORD ?
      ulRetainedStreamOffset DWORD ?
      ulRetainedSizeBytes DWORD ?
      pszDisplayText =POINTER ?
      pszLexicalForm =POINTER ?
      pszPronunciation POINTER ?
      bDisplayAttributes BYTE ?
      RequiredConfidence SBYTE ?
      ActualConfidence SBYTE ?
      Reserved BYTE ?
      SREngineConfidence REAL4 ?
    SPPHRASEELEMENT ends
    ;* [hidden][restricted] *
    SPPHRASERULE struct
      pszName =POINTER ?
      ulId DWORD ?
      ulFirstElement DWORD ?
      ulCountOfElements DWORD ?
      pNextSibling POINTER ?
      pFirstChild POINTER ?
      SREngineConfidence REAL4 ?
      Confidence SBYTE ?
    SPPHRASERULE ends
    ;* [hidden][restricted] *
    ;* [hidden] *
    SPPHRASEPROPERTYUNIONTYPE typedef SDWORD
    SPPPUT_UNUSED equ 0
    SPPPUT_ARRAY_INDEX equ

    SPPHRASEPROPERTY struct
      pszName =POINTER ?
      union
        ulId DWORD ?
        struct
          bType byte ?
          bReserved byte ?
          usArrayIndex WORD ?
        ends
      ends
      pszValue =POINTER ?
      vValue VARIANT <>
      ulFirstElement DWORD ?
      ulCountOfElements DWORD ?
      pNextSibling POINTER ?
      pFirstChild POINTER ?
      SREngineConfidence REAL4 ?
      Confidence SBYTE ?
    SPPHRASEPROPERTY ends
    ;* [hidden][restricted] *
    SPPHRASEREPLACEMENT struct
      bDisplayAttributes BYTE ?
      pszReplacementText =POINTER ?
      ulFirstElement DWORD ?
      ulCountOfElements DWORD ?
    SPPHRASEREPLACEMENT ends
    ;* [hidden][restricted] *
    SPPHRASE struct
      cbSize DWORD ?
      LangID WORD ?
      wHomophoneGroupId WORD ?
      ullGrammarID QWORD ?
      ftStartTime QWORD ?
      ullAudioStreamPosition QWORD ?
      ulAudioSizeBytes DWORD ?
      ulRetainedSizeBytes DWORD ?
      ulAudioSizeTime DWORD ?
      Rule SPPHRASERULE <>
      pProperties POINTER ?
      pElements POINTER ?
      cReplacements DWORD ?
      pReplacements POINTER ?
      SREngineID GUID <>
      ulSREnginePrivateDataSize DWORD ?
      pSREnginePrivateData POINTER ?
    SPPHRASE ends
    ;* [hidden][restricted] *
    SPSERIALIZEDPHRASE struct
      ulSerializedSize DWORD ?
    SPSERIALIZEDPHRASE ends
    ;* [hidden] *
    SPVALUETYPE typedef SDWORD
    SPDF_PROPERTY equ 1h
    SPDF_REPLACEMENT equ 2h
    SPDF_RULE equ 4h
    SPDF_DISPLAYTEXT equ 8h
    SPDF_LEXICALFORM equ 10h
    SPDF_PRONUNCIATION equ 20h
    SPDF_AUDIO equ 40h
    SPDF_ALTERNATES equ 80h
    SPDF_ALL equ 0ffh

    ;* [hidden] *
    SPBINARYGRAMMAR struct
      ulTotalSerializedSize DWORD ?
    SPBINARYGRAMMAR ends
    ;* [hidden] *
    SPPHRASERNG typedef SDWORD
    SPPR_ALL_ELEMENTS equ -1

    SP_GETWHOLEPHRASE equ <SPPR_ALL_ELEMENTS>
    SPRR_ALL_ELEMENTS equ <SPPR_ALL_ELEMENTS>
    if 0
      ;[...]
    else
      DECLARE_HANDLE SPSTATEHANDLE
    endif
    ;* [hidden] *
    SPRECOEVENTFLAGS typedef SDWORD
    SPREF_AutoPause equ
    SPREF_Emulated equ

    ;* [hidden] *
    SPPARTOFSPEECH typedef SDWORD
    SPPS_NotOverriden equ -1
    SPPS_Unknown equ 0
    SPPS_Noun equ 1000h
    SPPS_Verb equ 2000h
    SPPS_Modifier equ 3000h
    SPPS_Function equ 4000h
    SPPS_Interjection equ 5000h

    ;* [hidden] *
    SPLEXICONTYPE typedef SDWORD
    eLEXTYPE_USER equ
    eLEXTYPE_APP equ
    eLEXTYPE_VENDORLEXICON equ
    eLEXTYPE_LETTERTOSOUND equ
    eLEXTYPE_MORPHOLOGY equ
    eLEXTYPE_RESERVED4 equ
    eLEXTYPE_USER_SHORTCUT equ
    eLEXTYPE_RESERVED6 equ
    eLEXTYPE_RESERVED7 equ
    eLEXTYPE_RESERVED8 equ
    eLEXTYPE_RESERVED9 equ
    eLEXTYPE_RESERVED10 equ
    eLEXTYPE_PRIVATE1 equ
    eLEXTYPE_PRIVATE2 equ
    eLEXTYPE_PRIVATE3 equ
    eLEXTYPE_PRIVATE4 equ
    eLEXTYPE_PRIVATE5 equ
    eLEXTYPE_PRIVATE6 equ
    eLEXTYPE_PRIVATE7 equ
    eLEXTYPE_PRIVATE8 equ
    eLEXTYPE_PRIVATE9 equ
    eLEXTYPE_PRIVATE10 equ
    eLEXTYPE_PRIVATE11 equ
    eLEXTYPE_PRIVATE12 equ
    eLEXTYPE_PRIVATE13 equ
    eLEXTYPE_PRIVATE14 equ
    eLEXTYPE_PRIVATE15 equ
    eLEXTYPE_PRIVATE16 equ
    eLEXTYPE_PRIVATE17 equ
    eLEXTYPE_PRIVATE18 equ
    eLEXTYPE_PRIVATE19 equ
    eLEXTYPE_PRIVATE20 equ

    ;* [hidden] *
    SPWORDTYPE typedef SDWORD
    eWORDTYPE_ADDED equ
    eWORDTYPE_DELETED equ

    ;* [hidden][restricted] *
    SPWORDPRONUNCIATION struct
      pNextWordPronunciation POINTER ?
      eLexiconType SPLEXICONTYPE ?
      LangID WORD ?
      wPronunciationFlags WORD ?
      ePartOfSpeech SPPARTOFSPEECH ?
      szPronunciation SPPHONEID 1 dup (?)
    SPWORDPRONUNCIATION ends
    ;* [hidden][restricted] *
    SPWORDPRONUNCIATIONLIST struct
      ulSize DWORD ?
      pvBuffer POINTER ?
      pFirstWordPronunciation POINTER ?
    SPWORDPRONUNCIATIONLIST ends
    ;* [hidden][restricted] *
    SPWORD struct
      pNextWord POINTER ?
      LangID WORD ?
      wReserved WORD ?
      eWordType SPWORDTYPE ?
      pszWord POINTER ?
      pFirstWordPronunciation POINTER ?
    SPWORD ends
    ;* [hidden][restricted] *
    SPWORDLIST struct
      ulSize DWORD ?
      pvBuffer POINTER ?
      pFirstWord POINTER ?
    SPWORDLIST ends
    externdef __MIDL_itf_sapi51_0000_0019_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0019_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpLexicon_INTERFACE_DEFINED__
      __ISpLexicon_INTERFACE_DEFINED__ equ <>
      ;* interface ISpLexicon *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpLexicon:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpLexiconVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpLexiconVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpLexicon, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpLexicon
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpLexicon
          DECLSPEC_XFGVIRT(ISpLexicon, GetPronunciations)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetPronunciations, :ptr ISpLexicon, :LPCWSTR, :WORD, :DWORD, :ptr SPWORDPRONUNCIATIONLIST
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ISpLexicon, AddPronunciation)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD AddPronunciation, :ptr ISpLexicon, :LPCWSTR, :WORD, :SPPARTOFSPEECH, :PCSPPHONEID
          DECLSPEC_XFGVIRT(ISpLexicon, RemovePronunciation)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD RemovePronunciation, :ptr ISpLexicon, :LPCWSTR, :WORD, :SPPARTOFSPEECH, :PCSPPHONEID
          DECLSPEC_XFGVIRT(ISpLexicon, GetGeneration)
          STD_METHOD GetGeneration, :ptr ISpLexicon, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpLexicon, GetGenerationChange)
          ;* [in] *
          ;* [out][in] *
          STD_METHOD GetGenerationChange, :ptr ISpLexicon, :DWORD, :ptr DWORD, :ptr SPWORDLIST
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ISpLexicon, GetWords)
          ;* [in] *
          ;* [out][in] *
          ;* [out][in][annotation] *
          STD_METHOD GetWords, :ptr ISpLexicon, :DWORD, :ptr DWORD, :ptr DWORD, :ptr SPWORDLIST
          ;* [out][in] *
          ??Interface equ <>
          END_INTERFACE
        ISpLexiconVtbl ends
        ISpLexicon struct
          lpVtbl POINTER ?
        ISpLexicon ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpLexicon_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpContainerLexicon_INTERFACE_DEFINED__
      __ISpContainerLexicon_INTERFACE_DEFINED__ equ <>
      ;* interface ISpContainerLexicon *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpContainerLexicon:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpContainerLexiconVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpContainerLexiconVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpContainerLexicon, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpContainerLexicon
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpContainerLexicon
          DECLSPEC_XFGVIRT(ISpLexicon, GetPronunciations)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetPronunciations, :ptr ISpContainerLexicon, :LPCWSTR, :WORD, :DWORD, :ptr SPWORDPRONUNCIATIONLIST
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ISpLexicon, AddPronunciation)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD AddPronunciation, :ptr ISpContainerLexicon, :LPCWSTR, :WORD, :SPPARTOFSPEECH, :PCSPPHONEID
          DECLSPEC_XFGVIRT(ISpLexicon, RemovePronunciation)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD RemovePronunciation, :ptr ISpContainerLexicon, :LPCWSTR, :WORD, :SPPARTOFSPEECH, :PCSPPHONEID
          DECLSPEC_XFGVIRT(ISpLexicon, GetGeneration)
          STD_METHOD GetGeneration, :ptr ISpContainerLexicon, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpLexicon, GetGenerationChange)
          ;* [in] *
          ;* [out][in] *
          STD_METHOD GetGenerationChange, :ptr ISpContainerLexicon, :DWORD, :ptr DWORD, :ptr SPWORDLIST
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ISpLexicon, GetWords)
          ;* [in] *
          ;* [out][in] *
          ;* [out][in][annotation] *
          STD_METHOD GetWords, :ptr ISpContainerLexicon, :DWORD, :ptr DWORD, :ptr DWORD, :ptr SPWORDLIST
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ISpContainerLexicon, AddLexicon)
          ;* [in] *
          STD_METHOD AddLexicon, :ptr ISpContainerLexicon, :ptr ISpLexicon, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpContainerLexiconVtbl ends
        ISpContainerLexicon struct
          lpVtbl POINTER ?
        ISpContainerLexicon ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpContainerLexicon_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpPhoneConverter_INTERFACE_DEFINED__
      __ISpPhoneConverter_INTERFACE_DEFINED__ equ <>
      ;* interface ISpPhoneConverter *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpPhoneConverter:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpPhoneConverterVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpPhoneConverterVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpPhoneConverter, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpPhoneConverter
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpPhoneConverter
          DECLSPEC_XFGVIRT(ISpObjectWithToken, SetObjectToken)
          STD_METHOD SetObjectToken, :ptr ISpPhoneConverter, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectWithToken, GetObjectToken)
          STD_METHOD GetObjectToken, :ptr ISpPhoneConverter, :ptr ptr ISpObjectToken
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpPhoneConverter, PhoneToId)
          ;* [in] *
          STD_METHOD PhoneToId, :ptr ISpPhoneConverter, :LPCWSTR, :ptr SPPHONEID
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpPhoneConverter, IdToPhone)
          ;* [in] *
          STD_METHOD IdToPhone, :ptr ISpPhoneConverter, :PCSPPHONEID, :ptr WCHAR
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpPhoneConverterVtbl ends
        ISpPhoneConverter struct
          lpVtbl POINTER ?
        ISpPhoneConverter ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpPhoneConverter_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0022 *
    ;* [local] *
    ;* [hidden][restricted] *
    SPVPITCH struct
      MiddleAdj SDWORD ?
      RangeAdj SDWORD ?
    SPVPITCH ends
    ;* [hidden] *
    SPVACTIONS typedef SDWORD
    SPVA_Speak equ 0
    SPVA_Silence equ
    SPVA_Pronounce equ
    SPVA_Bookmark equ
    SPVA_SpellOut equ
    SPVA_Section equ
    SPVA_ParseUnknownTag equ

    ;* [hidden][restricted] *
    SPVCONTEXT struct
      pCategory =POINTER ?
      pBefore =POINTER ?
      pAfter =POINTER ?
    SPVCONTEXT ends
    ;* [hidden][restricted] *
    SPVSTATE struct
      eAction SPVACTIONS ?
      LangID WORD ?
      wReserved WORD ?
      EmphAdj SDWORD ?
      RateAdj SDWORD ?
      Volume DWORD ?
      PitchAdj SPVPITCH <>
      SilenceMSecs DWORD ?
      pPhoneIds POINTER ?
      ePartOfSpeech SPPARTOFSPEECH ?
      Context SPVCONTEXT <>
    SPVSTATE ends
    ;* [hidden] *
    SPRUNSTATE typedef SDWORD
    SPRS_DONE equ
    SPRS_IS_SPEAKING equ

    ;* [hidden] *
    SPVLIMITS typedef SDWORD
    SPMIN_VOLUME equ 0
    SPMAX_VOLUME equ 100
    SPMIN_RATE equ -10
    SPMAX_RATE equ 10

    ;* [hidden] *
    SPVPRIORITY typedef SDWORD
    SPVPRI_NORMAL equ 0
    SPVPRI_ALERT equ
    SPVPRI_OVER equ

    ;* [hidden][restricted] *
    SPVOICESTATUS struct
      ulCurrentStream DWORD ?
      ulLastStreamQueued DWORD ?
      hrLastResult HRESULT ?
      dwRunningState DWORD ?
      ulInputWordPos DWORD ?
      ulInputWordLen DWORD ?
      ulInputSentPos DWORD ?
      ulInputSentLen DWORD ?
      lBookmarkId SDWORD ?
      PhonemeId SPPHONEID ?
      VisemeId SPVISEMES ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
    SPVOICESTATUS ends
    ;* [hidden] *
    SPEAKFLAGS typedef SDWORD
    SPF_DEFAULT equ 0
    SPF_ASYNC equ
    SPF_PURGEBEFORESPEAK equ
    SPF_IS_FILENAME equ
    SPF_IS_XML equ
    SPF_IS_NOT_XML equ
    SPF_PERSIST_XML equ
    SPF_NLP_SPEAK_PUNC equ
    SPF_NLP_MASK equ SPF_NLP_SPEAK_PUNC
    SPF_VOICE_MASK equ
    SPF_UNUSED_FLAGS equ not SPF_VOICE_MASK

    externdef __MIDL_itf_sapi51_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpVoice_INTERFACE_DEFINED__
      __ISpVoice_INTERFACE_DEFINED__ equ <>
      ;* interface ISpVoice *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpVoice:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpVoiceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpVoiceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpVoice, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpVoice
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpVoice
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
          STD_METHOD SetNotifySink, :ptr ISpVoice, :ptr ISpNotifySink
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyWindowMessage, :ptr ISpVoice, :HWND, :UINT, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackFunction, :ptr ISpVoice, :ptr SPNOTIFYCALLBACK, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackInterface, :ptr ISpVoice, :ptr ISpNotifyCallback, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
          ;* [local] *
          STD_METHOD SetNotifyWin32Event, :ptr ISpVoice
          DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
          ;* [local] *
          STD_METHOD WaitForNotifyEvent, :ptr ISpVoice, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
          ;* [local] *
          STD_METHOD GetNotifyEventHandle, :ptr ISpVoice
          DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
          ;* [in] *
          STD_METHOD SetInterest, :ptr ISpVoice, :ULONGLONG, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
          ;* [in] *
          ;* [size_is][out] *
          STD_METHOD GetEvents, :ptr ISpVoice, :ULONG, :ptr SPEVENT, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
          STD_METHOD GetInfo, :ptr ISpVoice, :ptr SPEVENTSOURCEINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, SetOutput)
          ;* [in] *
          STD_METHOD SetOutput, :ptr ISpVoice, :ptr IUnknown, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetOutputObjectToken)
          ;* [out][annotation] *
          STD_METHOD GetOutputObjectToken, :ptr ISpVoice, :ptr ptr ISpObjectToken
          DECLSPEC_XFGVIRT(ISpVoice, GetOutputStream)
          STD_METHOD GetOutputStream, :ptr ISpVoice, :ptr ptr ISpStreamFormat
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, Pause)
          STD_METHOD Pause, :ptr ISpVoice
          DECLSPEC_XFGVIRT(ISpVoice, Resume)
          STD_METHOD Resume, :ptr ISpVoice
          DECLSPEC_XFGVIRT(ISpVoice, SetVoice)
          STD_METHOD SetVoice, :ptr ISpVoice, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetVoice)
          ;* [out][annotation] *
          STD_METHOD GetVoice, :ptr ISpVoice, :ptr ptr ISpObjectToken
          DECLSPEC_XFGVIRT(ISpVoice, Speak)
          ;* [string][in][annotation] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD Speak, :ptr ISpVoice, :LPCWSTR, :DWORD, :ptr ULONG
          DECLSPEC_XFGVIRT(ISpVoice, SpeakStream)
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD SpeakStream, :ptr ISpVoice, :ptr IStream, :DWORD, :ptr ULONG
          DECLSPEC_XFGVIRT(ISpVoice, GetStatus)
          ;* [out] *
          ;* [out][annotation] *
          STD_METHOD GetStatus, :ptr ISpVoice, :ptr SPVOICESTATUS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpVoice, Skip)
          ;* [string][in] *
          ;* [in] *
          STD_METHOD Skip, :ptr ISpVoice, :LPCWSTR, :SDWORD, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, SetPriority)
          STD_METHOD SetPriority, :ptr ISpVoice, :SPVPRIORITY
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetPriority)
          STD_METHOD GetPriority, :ptr ISpVoice, :ptr SPVPRIORITY
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, SetAlertBoundary)
          STD_METHOD SetAlertBoundary, :ptr ISpVoice, :SPEVENTENUM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetAlertBoundary)
          STD_METHOD GetAlertBoundary, :ptr ISpVoice, :ptr SPEVENTENUM
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, SetRate)
          STD_METHOD SetRate, :ptr ISpVoice, :SDWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetRate)
          STD_METHOD GetRate, :ptr ISpVoice, :ptr SDWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, SetVolume)
          STD_METHOD SetVolume, :ptr ISpVoice, :USHORT
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetVolume)
          STD_METHOD GetVolume, :ptr ISpVoice, :ptr USHORT
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, WaitUntilDone)
          STD_METHOD WaitUntilDone, :ptr ISpVoice, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, SetSyncSpeakTimeout)
          STD_METHOD SetSyncSpeakTimeout, :ptr ISpVoice, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpVoice, GetSyncSpeakTimeout)
          STD_METHOD GetSyncSpeakTimeout, :ptr ISpVoice, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, SpeakCompleteEvent)
          ;* [local] *
          STD_METHOD SpeakCompleteEvent, :ptr ISpVoice
          DECLSPEC_XFGVIRT(ISpVoice, IsUISupported)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD IsUISupported, :ptr ISpVoice, :LPCWSTR, :ptr, :ULONG, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpVoice, DisplayUI)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DisplayUI, :ptr ISpVoice, :HWND, :LPCWSTR, :LPCWSTR, :ptr, :ULONG
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpVoiceVtbl ends
        ISpVoice struct
          lpVtbl POINTER ?
        ISpVoice ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpVoice_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpPhrase_INTERFACE_DEFINED__
      __ISpPhrase_INTERFACE_DEFINED__ equ <>
      ;* interface ISpPhrase *
      ;* [restricted][unique][helpstring][local][uuid][object] *
      externdef IID_ISpPhrase:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpPhraseVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpPhraseVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpPhrase, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpPhrase
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpPhrase
          DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
          ;* [out][annotation] *
          STD_METHOD GetPhrase, :ptr ISpPhrase, :ptr ptr SPPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
          ;* [out][annotation] *
          STD_METHOD GetSerializedPhrase, :ptr ISpPhrase, :ptr ptr SPSERIALIZEDPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetText)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          ;* [optional][out][annotation] *
          STD_METHOD GetText, :ptr ISpPhrase, :ULONG, :ULONG, :BOOL, :ptr LPWSTR, :ptr BYTE
          DECLSPEC_XFGVIRT(ISpPhrase, Discard)
          STD_METHOD Discard, :ptr ISpPhrase, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpPhraseVtbl ends
        ISpPhrase struct
          lpVtbl POINTER ?
        ISpPhrase ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpPhrase_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpPhraseAlt_INTERFACE_DEFINED__
      __ISpPhraseAlt_INTERFACE_DEFINED__ equ <>
      ;* interface ISpPhraseAlt *
      ;* [restricted][unique][helpstring][local][uuid][object] *
      externdef IID_ISpPhraseAlt:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpPhraseAltVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpPhraseAltVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpPhraseAlt, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpPhraseAlt
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpPhraseAlt
          DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
          ;* [out][annotation] *
          STD_METHOD GetPhrase, :ptr ISpPhraseAlt, :ptr ptr SPPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
          ;* [out][annotation] *
          STD_METHOD GetSerializedPhrase, :ptr ISpPhraseAlt, :ptr ptr SPSERIALIZEDPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetText)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          ;* [optional][out][annotation] *
          STD_METHOD GetText, :ptr ISpPhraseAlt, :ULONG, :ULONG, :BOOL, :ptr LPWSTR, :ptr BYTE
          DECLSPEC_XFGVIRT(ISpPhrase, Discard)
          STD_METHOD Discard, :ptr ISpPhraseAlt, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpPhraseAlt, GetAltInfo)
          ;* [out] *
          ;* [out] *
          ;* [out] *
          STD_METHOD GetAltInfo, :ptr ISpPhraseAlt, :ptr ptr ISpPhrase, :ptr ULONG, :ptr ULONG, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpPhraseAlt, Commit)
          STD_METHOD Commit, :ptr ISpPhraseAlt
          ??Interface equ <>
          END_INTERFACE
        ISpPhraseAltVtbl ends
        ISpPhraseAlt struct
          lpVtbl POINTER ?
        ISpPhraseAlt ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpPhraseAlt_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0025 *
    ;* [local] *
    ;* [hidden][restricted] *
    SPRECORESULTTIMES struct
      ftStreamTime FILETIME <>
      ullLength QWORD ?
      dwTickCount DWORD ?
      ullStart QWORD ?
    SPRECORESULTTIMES ends
    ;* [hidden] *
    SPSERIALIZEDRESULT struct
      ulSerializedSize DWORD ?
    SPSERIALIZEDRESULT ends
    externdef __MIDL_itf_sapi51_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpRecoResult_INTERFACE_DEFINED__
      __ISpRecoResult_INTERFACE_DEFINED__ equ <>
      ;* interface ISpRecoResult *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpRecoResult:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpRecoResultVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpRecoResultVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpRecoResult, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpRecoResult
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpRecoResult
          DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
          ;* [out][annotation] *
          STD_METHOD GetPhrase, :ptr ISpRecoResult, :ptr ptr SPPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
          ;* [out][annotation] *
          STD_METHOD GetSerializedPhrase, :ptr ISpRecoResult, :ptr ptr SPSERIALIZEDPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetText)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          ;* [optional][out][annotation] *
          STD_METHOD GetText, :ptr ISpRecoResult, :ULONG, :ULONG, :BOOL, :ptr LPWSTR, :ptr BYTE
          DECLSPEC_XFGVIRT(ISpPhrase, Discard)
          STD_METHOD Discard, :ptr ISpRecoResult, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoResult, GetResultTimes)
          STD_METHOD GetResultTimes, :ptr ISpRecoResult, :ptr SPRECORESULTTIMES
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoResult, GetAlternates)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetAlternates, :ptr ISpRecoResult, :ULONG, :ULONG, :ULONG, :ptr ptr ISpPhraseAlt, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoResult, GetAudio)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetAudio, :ptr ISpRecoResult, :ULONG, :ULONG, :ptr ptr ISpStreamFormat
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoResult, SpeakAudio)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SpeakAudio, :ptr ISpRecoResult, :ULONG, :ULONG, :DWORD, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoResult, Serialize)
          STD_METHOD Serialize, :ptr ISpRecoResult, :ptr ptr SPSERIALIZEDRESULT
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoResult, ScaleAudio)
          ;* [in] *
          STD_METHOD ScaleAudio, :ptr ISpRecoResult, :ptr GUID, :ptr WAVEFORMATEX
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoResult, GetRecoContext)
          STD_METHOD GetRecoContext, :ptr ISpRecoResult, :ptr ptr ISpRecoContext
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpRecoResultVtbl ends
        ISpRecoResult struct
          lpVtbl POINTER ?
        ISpRecoResult ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpRecoResult_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0026 *
    ;* [local] *
    ;* [hidden] *
    SPTEXTSELECTIONINFO struct
      ulStartActiveOffset DWORD ?
      cchActiveChars DWORD ?
      ulStartSelection DWORD ?
      cchSelection DWORD ?
    SPTEXTSELECTIONINFO ends
    tagSPTEXTSELECTIONINFO typedef SPTEXTSELECTIONINFO
    ;* [hidden] *
    SPWORDPRONOUNCEABLE typedef SDWORD
    SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE equ 0
    SPWP_UNKNOWN_WORD_PRONOUNCEABLE equ 1
    SPWP_KNOWN_WORD_PRONOUNCEABLE equ 2

    ;* [hidden] *
    SPGRAMMARSTATE typedef SDWORD
    SPGS_DISABLED equ 0
    SPGS_ENABLED equ 1
    SPGS_EXCLUSIVE equ 3

    ;* [hidden] *
    SPCONTEXTSTATE typedef SDWORD
    SPCS_DISABLED equ 0
    SPCS_ENABLED equ 1

    ;* [hidden] *
    SPRULESTATE typedef SDWORD
    SPRS_INACTIVE equ 0
    SPRS_ACTIVE equ 1
    SPRS_ACTIVE_WITH_AUTO_PAUSE equ 3

    SP_STREAMPOS_ASAP equ (0)
    SP_STREAMPOS_REALTIME equ (- 1)
    SPRULETRANS_TEXTBUFFER equ (SPSTATEHANDLE) (- 1)
    SPRULETRANS_WILDCARD equ (SPSTATEHANDLE) (- 2)
    SPRULETRANS_DICTATION equ (SPSTATEHANDLE) (- 3)
    ;* [hidden] *
    SPGRAMMARWORDTYPE typedef SDWORD
    SPWT_DISPLAY equ 0
    SPWT_LEXICAL equ
    SPWT_PRONUNCIATION equ

    ;* [hidden] *
    SPPROPERTYINFO struct
      pszName =POINTER ?
      ulId DWORD ?
      pszValue =POINTER ?
      vValue VARIANT <>
    SPPROPERTYINFO ends
    tagSPPROPERTYINFO typedef SPPROPERTYINFO
    ;* [hidden] *
    SPCFGRULEATTRIBUTES typedef SDWORD
    SPRAF_TopLevel equ
    SPRAF_Active equ
    SPRAF_Export equ
    SPRAF_Import equ
    SPRAF_Interpreter equ
    SPRAF_Dynamic equ
    SPRAF_AutoPause equ

    externdef __MIDL_itf_sapi51_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpGrammarBuilder_INTERFACE_DEFINED__
      __ISpGrammarBuilder_INTERFACE_DEFINED__ equ <>
      ;* interface ISpGrammarBuilder *
      ;* [local][restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpGrammarBuilder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpGrammarBuilderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpGrammarBuilderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpGrammarBuilder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpGrammarBuilder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpGrammarBuilder
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
          STD_METHOD ResetGrammar, :ptr ISpGrammarBuilder, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetRule, :ptr ISpGrammarBuilder, :LPCWSTR, :DWORD, :DWORD, :BOOL, :ptr SPSTATEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
          STD_METHOD ClearRule, :ptr ISpGrammarBuilder, :SPSTATEHANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
          ;* [in] *
          STD_METHOD CreateNewState, :ptr ISpGrammarBuilder, :SPSTATEHANDLE, :ptr SPSTATEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          ;* [in][annotation] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddWordTransition, :ptr ISpGrammarBuilder, :SPSTATEHANDLE, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR, :SPGRAMMARWORDTYPE, :REAL4, :ptr SPPROPERTYINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddRuleTransition, :ptr ISpGrammarBuilder, :SPSTATEHANDLE, :SPSTATEHANDLE, :SPSTATEHANDLE, :REAL4, :ptr SPPROPERTYINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD AddResource, :ptr ISpGrammarBuilder, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
          STD_METHOD Commit, :ptr ISpGrammarBuilder, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpGrammarBuilderVtbl ends
        ISpGrammarBuilder struct
          lpVtbl POINTER ?
        ISpGrammarBuilder ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpGrammarBuilder_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0027 *
    ;* [local] *
    ;* [hidden] *
    SPLOADOPTIONS typedef SDWORD
    SPLO_STATIC equ 0
    SPLO_DYNAMIC equ 1

    externdef __MIDL_itf_sapi51_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpRecoGrammar_INTERFACE_DEFINED__
      __ISpRecoGrammar_INTERFACE_DEFINED__ equ <>
      ;* interface ISpRecoGrammar *
      ;* [local][restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpRecoGrammar:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpRecoGrammarVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpRecoGrammarVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpRecoGrammar, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpRecoGrammar
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpRecoGrammar
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
          STD_METHOD ResetGrammar, :ptr ISpRecoGrammar, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetRule, :ptr ISpRecoGrammar, :LPCWSTR, :DWORD, :DWORD, :BOOL, :ptr SPSTATEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
          STD_METHOD ClearRule, :ptr ISpRecoGrammar, :SPSTATEHANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
          ;* [in] *
          STD_METHOD CreateNewState, :ptr ISpRecoGrammar, :SPSTATEHANDLE, :ptr SPSTATEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          ;* [in][annotation] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddWordTransition, :ptr ISpRecoGrammar, :SPSTATEHANDLE, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR, :SPGRAMMARWORDTYPE, :REAL4, :ptr SPPROPERTYINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddRuleTransition, :ptr ISpRecoGrammar, :SPSTATEHANDLE, :SPSTATEHANDLE, :SPSTATEHANDLE, :REAL4, :ptr SPPROPERTYINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD AddResource, :ptr ISpRecoGrammar, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
          STD_METHOD Commit, :ptr ISpRecoGrammar, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, GetGrammarId)
          STD_METHOD GetGrammarId, :ptr ISpRecoGrammar, :ptr ULONGLONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, GetRecoContext)
          ;* [out][annotation] *
          STD_METHOD GetRecoContext, :ptr ISpRecoGrammar, :ptr ptr ISpRecoContext
          DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromFile)
          ;* [string][in] *
          STD_METHOD LoadCmdFromFile, :ptr ISpRecoGrammar, :LPCWSTR, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromObject)
          ;* [in] *
          ;* [string][in] *
          STD_METHOD LoadCmdFromObject, :ptr ISpRecoGrammar, :REFCLSID, :LPCWSTR, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromResource)
          ;* [in] *
          ;* [string][in] *
          ;* [string][in] *
          ;* [in] *
          STD_METHOD LoadCmdFromResource, :ptr ISpRecoGrammar, :HMODULE, :LPCWSTR, :LPCWSTR, :WORD, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromMemory)
          ;* [in] *
          STD_METHOD LoadCmdFromMemory, :ptr ISpRecoGrammar, :ptr SPBINARYGRAMMAR, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromProprietaryGrammar)
          ;* [in] *
          ;* [string][in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD LoadCmdFromProprietaryGrammar, :ptr ISpRecoGrammar, :REFGUID, :LPCWSTR, :ptr, :ULONG, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SetRuleState)
          ;* [string][in][annotation] *
          ;* [in] *
          STD_METHOD SetRuleState, :ptr ISpRecoGrammar, :LPCWSTR, :ptr, :SPRULESTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SetRuleIdState)
          ;* [in] *
          STD_METHOD SetRuleIdState, :ptr ISpRecoGrammar, :ULONG, :SPRULESTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadDictation)
          ;* [string][in][annotation] *
          STD_METHOD LoadDictation, :ptr ISpRecoGrammar, :LPCWSTR, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, UnloadDictation)
          STD_METHOD UnloadDictation, :ptr ISpRecoGrammar
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SetDictationState)
          STD_METHOD SetDictationState, :ptr ISpRecoGrammar, :SPRULESTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SetWordSequenceData)
          ;* [in][annotation] *
          ;* [in] *
          STD_METHOD SetWordSequenceData, :ptr ISpRecoGrammar, :ptr WCHAR, :ULONG, :ptr SPTEXTSELECTIONINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SetTextSelection)
          STD_METHOD SetTextSelection, :ptr ISpRecoGrammar, :ptr SPTEXTSELECTIONINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, IsPronounceable)
          ;* [string][in] *
          STD_METHOD IsPronounceable, :ptr ISpRecoGrammar, :LPCWSTR, :ptr SPWORDPRONOUNCEABLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SetGrammarState)
          STD_METHOD SetGrammarState, :ptr ISpRecoGrammar, :SPGRAMMARSTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoGrammar, SaveCmd)
          ;* [in] *
          ;* [optional][out][annotation] *
          STD_METHOD SaveCmd, :ptr ISpRecoGrammar, :ptr IStream, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpRecoGrammar, GetGrammarState)
          STD_METHOD GetGrammarState, :ptr ISpRecoGrammar, :ptr SPGRAMMARSTATE
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpRecoGrammarVtbl ends
        ISpRecoGrammar struct
          lpVtbl POINTER ?
        ISpRecoGrammar ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpRecoGrammar_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0028 *
    ;* [local] *
    ;* [hidden][restricted] *
    SPRECOCONTEXTSTATUS struct
      eInterference SPINTERFERENCE ?
      szRequestTypeOfUI WORD 255 dup (?)
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
    SPRECOCONTEXTSTATUS ends
    ;* [hidden] *
    SPBOOKMARKOPTIONS typedef SDWORD
    SPBO_NONE equ 0
    SPBO_PAUSE equ

    ;* [hidden] *
    SPAUDIOOPTIONS typedef SDWORD
    SPAO_NONE equ 0
    SPAO_RETAIN_AUDIO equ

    externdef __MIDL_itf_sapi51_0000_0028_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0028_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpRecoContext_INTERFACE_DEFINED__
      __ISpRecoContext_INTERFACE_DEFINED__ equ <>
      ;* interface ISpRecoContext *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpRecoContext:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpRecoContextVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpRecoContextVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpRecoContext, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpRecoContext
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpRecoContext
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
          STD_METHOD SetNotifySink, :ptr ISpRecoContext, :ptr ISpNotifySink
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyWindowMessage, :ptr ISpRecoContext, :HWND, :UINT, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackFunction, :ptr ISpRecoContext, :ptr SPNOTIFYCALLBACK, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetNotifyCallbackInterface, :ptr ISpRecoContext, :ptr ISpNotifyCallback, :WPARAM, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
          ;* [local] *
          STD_METHOD SetNotifyWin32Event, :ptr ISpRecoContext
          DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
          ;* [local] *
          STD_METHOD WaitForNotifyEvent, :ptr ISpRecoContext, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
          ;* [local] *
          STD_METHOD GetNotifyEventHandle, :ptr ISpRecoContext
          DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
          ;* [in] *
          STD_METHOD SetInterest, :ptr ISpRecoContext, :ULONGLONG, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
          ;* [in] *
          ;* [size_is][out] *
          STD_METHOD GetEvents, :ptr ISpRecoContext, :ULONG, :ptr SPEVENT, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
          STD_METHOD GetInfo, :ptr ISpRecoContext, :ptr SPEVENTSOURCEINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetRecognizer)
          STD_METHOD GetRecognizer, :ptr ISpRecoContext, :ptr ptr ISpRecognizer
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, CreateGrammar)
          ;* [in] *
          STD_METHOD CreateGrammar, :ptr ISpRecoContext, :ULONGLONG, :ptr ptr ISpRecoGrammar
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetStatus)
          STD_METHOD GetStatus, :ptr ISpRecoContext, :ptr SPRECOCONTEXTSTATUS
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetMaxAlternates)
          STD_METHOD GetMaxAlternates, :ptr ISpRecoContext, :ptr ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, SetMaxAlternates)
          STD_METHOD SetMaxAlternates, :ptr ISpRecoContext, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, SetAudioOptions)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetAudioOptions, :ptr ISpRecoContext, :SPAUDIOOPTIONS, :ptr GUID, :ptr WAVEFORMATEX
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetAudioOptions)
          ;* [in] *
          ;* [out] *
          STD_METHOD GetAudioOptions, :ptr ISpRecoContext, :ptr SPAUDIOOPTIONS, :ptr GUID, :ptr ptr WAVEFORMATEX
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, DeserializeResult)
          ;* [in] *
          STD_METHOD DeserializeResult, :ptr ISpRecoContext, :ptr SPSERIALIZEDRESULT, :ptr ptr ISpRecoResult
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, Bookmark)
          ;* [in] *
          ;* [in] *
          STD_METHOD Bookmark, :ptr ISpRecoContext, :SPBOOKMARKOPTIONS, :ULONGLONG, :LPARAM
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, SetAdaptationData)
          ;* [string][in] *
          STD_METHOD SetAdaptationData, :ptr ISpRecoContext, :LPCWSTR, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, Pause)
          STD_METHOD Pause, :ptr ISpRecoContext, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, Resume)
          STD_METHOD Resume, :ptr ISpRecoContext, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, SetVoice)
          ;* [in] *
          STD_METHOD SetVoice, :ptr ISpRecoContext, :ptr ISpVoice, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetVoice)
          STD_METHOD GetVoice, :ptr ISpRecoContext, :ptr ptr ISpVoice
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, SetVoicePurgeEvent)
          STD_METHOD SetVoicePurgeEvent, :ptr ISpRecoContext, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetVoicePurgeEvent)
          STD_METHOD GetVoicePurgeEvent, :ptr ISpRecoContext, :ptr ULONGLONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecoContext, SetContextState)
          STD_METHOD SetContextState, :ptr ISpRecoContext, :SPCONTEXTSTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecoContext, GetContextState)
          STD_METHOD GetContextState, :ptr ISpRecoContext, :ptr SPCONTEXTSTATE
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpRecoContextVtbl ends
        ISpRecoContext struct
          lpVtbl POINTER ?
        ISpRecoContext ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpRecoContext_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpProperties_INTERFACE_DEFINED__
      __ISpProperties_INTERFACE_DEFINED__ equ <>
      ;* interface ISpProperties *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpProperties:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpPropertiesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpPropertiesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpProperties, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpProperties
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpProperties
          DECLSPEC_XFGVIRT(ISpProperties, SetPropertyNum)
          ;* [in] *
          STD_METHOD SetPropertyNum, :ptr ISpProperties, :LPCWSTR, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpProperties, GetPropertyNum)
          ;* [in] *
          STD_METHOD GetPropertyNum, :ptr ISpProperties, :LPCWSTR, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpProperties, SetPropertyString)
          ;* [in] *
          STD_METHOD SetPropertyString, :ptr ISpProperties, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpProperties, GetPropertyString)
          ;* [in] *
          ;* [string][out][annotation] *
          STD_METHOD GetPropertyString, :ptr ISpProperties, :LPCWSTR, :ptr LPWSTR
          ??Interface equ <>
          END_INTERFACE
        ISpPropertiesVtbl ends
        ISpProperties struct
          lpVtbl POINTER ?
        ISpProperties ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpProperties_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0030 *
    ;* [local] *
    SP_MAX_LANGIDS equ (20)
    ;* [hidden][restricted] *
    SPRECOGNIZERSTATUS struct
      AudioStatus SPAUDIOSTATUS <>
      ullRecognitionStreamPos QWORD ?
      ulStreamNumber DWORD ?
      ulNumActive DWORD ?
      clsidEngine CLSID <>
      cLangIDs DWORD ?
      aLangID WORD 20 dup (?)
      ullRecognitionStreamTime QWORD ?
    SPRECOGNIZERSTATUS ends
    ;* [hidden] *
    SPSTREAMFORMATTYPE typedef SDWORD
    SPWF_INPUT equ 0
    SPWF_SRENGINE equ
    SPWAVEFORMATTYPE typedef SPSTREAMFORMATTYPE

    ;* [hidden] *
    SPRECOSTATE typedef SDWORD
    SPRST_INACTIVE equ 0
    SPRST_ACTIVE equ
    SPRST_ACTIVE_ALWAYS equ
    SPRST_INACTIVE_WITH_PURGE equ
    SPRST_NUM_STATES equ

    externdef __MIDL_itf_sapi51_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapi51_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpRecognizer_INTERFACE_DEFINED__
      __ISpRecognizer_INTERFACE_DEFINED__ equ <>
      ;* interface ISpRecognizer *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpRecognizer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpRecognizerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpRecognizerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpRecognizer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpRecognizer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpRecognizer
          DECLSPEC_XFGVIRT(ISpProperties, SetPropertyNum)
          ;* [in] *
          STD_METHOD SetPropertyNum, :ptr ISpRecognizer, :LPCWSTR, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpProperties, GetPropertyNum)
          ;* [in] *
          STD_METHOD GetPropertyNum, :ptr ISpRecognizer, :LPCWSTR, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpProperties, SetPropertyString)
          ;* [in] *
          STD_METHOD SetPropertyString, :ptr ISpRecognizer, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpProperties, GetPropertyString)
          ;* [in] *
          ;* [string][out][annotation] *
          STD_METHOD GetPropertyString, :ptr ISpRecognizer, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpRecognizer, SetRecognizer)
          STD_METHOD SetRecognizer, :ptr ISpRecognizer, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecognizer, GetRecognizer)
          STD_METHOD GetRecognizer, :ptr ISpRecognizer, :ptr ptr ISpObjectToken
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecognizer, SetInput)
          ;* [in][annotation] *
          STD_METHOD SetInput, :ptr ISpRecognizer, :ptr IUnknown, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecognizer, GetInputObjectToken)
          ;* [out][annotation] *
          STD_METHOD GetInputObjectToken, :ptr ISpRecognizer, :ptr ptr ISpObjectToken
          DECLSPEC_XFGVIRT(ISpRecognizer, GetInputStream)
          ;* [out][annotation] *
          STD_METHOD GetInputStream, :ptr ISpRecognizer, :ptr ptr ISpStreamFormat
          DECLSPEC_XFGVIRT(ISpRecognizer, CreateRecoContext)
          ;* [out][annotation] *
          STD_METHOD CreateRecoContext, :ptr ISpRecognizer, :ptr ptr ISpRecoContext
          DECLSPEC_XFGVIRT(ISpRecognizer, GetRecoProfile)
          ;* [out][annotation] *
          STD_METHOD GetRecoProfile, :ptr ISpRecognizer, :ptr ptr ISpObjectToken
          DECLSPEC_XFGVIRT(ISpRecognizer, SetRecoProfile)
          STD_METHOD SetRecoProfile, :ptr ISpRecognizer, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecognizer, IsSharedInstance)
          STD_METHOD IsSharedInstance, :ptr ISpRecognizer
          DECLSPEC_XFGVIRT(ISpRecognizer, GetRecoState)
          STD_METHOD GetRecoState, :ptr ISpRecognizer, :ptr SPRECOSTATE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecognizer, SetRecoState)
          STD_METHOD SetRecoState, :ptr ISpRecognizer, :SPRECOSTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecognizer, GetStatus)
          STD_METHOD GetStatus, :ptr ISpRecognizer, :ptr SPRECOGNIZERSTATUS
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecognizer, GetFormat)
          ;* [in] *
          ;* [out] *
          ;* [out][annotation] *
          STD_METHOD GetFormat, :ptr ISpRecognizer, :SPSTREAMFORMATTYPE, :ptr GUID, :ptr ptr WAVEFORMATEX
          DECLSPEC_XFGVIRT(ISpRecognizer, IsUISupported)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD IsUISupported, :ptr ISpRecognizer, :LPCWSTR, :ptr, :ULONG, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpRecognizer, DisplayUI)
          ;* [local] *
          ;* [in] *
          ;* [in][annotation] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DisplayUI, :ptr ISpRecognizer, :HWND, :LPCWSTR, :LPCWSTR, :ptr, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpRecognizer, EmulateRecognition)
          STD_METHOD EmulateRecognition, :ptr ISpRecognizer, :ptr ISpPhrase
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpRecognizerVtbl ends
        ISpRecognizer struct
          lpVtbl POINTER ?
        ISpRecognizer ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpRecognizer_INTERFACE_DEFINED__ *
    endif
    ifndef __SpeechLib_LIBRARY_DEFINED__
      __SpeechLib_LIBRARY_DEFINED__ equ <>
      ;* library SpeechLib *
      ;* [version][uuid][helpstring] *
      include winapifamily.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        SpeechLanguageId typedef SDWORD
        __SpeechStringConstants_MODULE_DEFINED__ equ <>
        ;* [hidden] *
        DISPID_SpeechDataKey typedef SDWORD
        DISPID_SDKSetBinaryValue equ 1
        DISPID_SDKGetBinaryValue equ
        DISPID_SDKSetStringValue equ
        DISPID_SDKGetStringValue equ
        DISPID_SDKSetLongValue equ
        DISPID_SDKGetlongValue equ
        DISPID_SDKOpenKey equ
        DISPID_SDKCreateKey equ
        DISPID_SDKDeleteKey equ
        DISPID_SDKDeleteValue equ
        DISPID_SDKEnumKeys equ
        DISPID_SDKEnumValues equ

        ;* [hidden] *
        DISPID_SpeechObjectToken typedef SDWORD
        DISPID_SOTId equ 1
        DISPID_SOTDataKey equ
        DISPID_SOTCategory equ
        DISPID_SOTGetDescription equ
        DISPID_SOTSetId equ
        DISPID_SOTGetAttribute equ
        DISPID_SOTCreateInstance equ
        DISPID_SOTRemove equ
        DISPID_SOTGetStorageFileName equ
        DISPID_SOTRemoveStorageFileName equ
        DISPID_SOTIsUISupported equ
        DISPID_SOTDisplayUI equ
        DISPID_SOTMatchesAttributes equ

        SpeechDataKeyLocation typedef SDWORD
        SDKLDefaultLocation equ SPDKL_DefaultLocation
        SDKLCurrentUser equ SPDKL_CurrentUser
        SDKLLocalMachine equ SPDKL_LocalMachine
        SDKLCurrentConfig equ SPDKL_CurrentConfig

        SpeechTokenContext typedef SDWORD
        STCInprocServer equ CLSCTX_INPROC_SERVER
        STCInprocHandler equ CLSCTX_INPROC_HANDLER
        STCLocalServer equ CLSCTX_LOCAL_SERVER
        STCRemoteServer equ CLSCTX_REMOTE_SERVER
        STCAll equ

        SpeechTokenShellFolder typedef SDWORD
        STSF_AppData equ 1ah
        STSF_LocalAppData equ 1ch
        STSF_CommonAppData equ 23h
        STSF_FlagCreate equ 8000h

        ;* [hidden] *
        DISPID_SpeechObjectTokens typedef SDWORD
        DISPID_SOTsCount equ 1
        DISPID_SOTsItem equ DISPID_VALUE
        DISPID_SOTs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechObjectTokenCategory typedef SDWORD
        DISPID_SOTCId equ 1
        DISPID_SOTCDefault equ
        DISPID_SOTCSetId equ
        DISPID_SOTCGetDataKey equ
        DISPID_SOTCEnumerateTokens equ

        SpeechAudioFormatType typedef SDWORD
        SAFTDefault equ -1
        SAFTNoAssignedFormat equ 0
        SAFTText equ
        SAFTNonStandardFormat equ
        SAFTExtendedAudioFormat equ
        SAFT8kHz8BitMono equ
        SAFT8kHz8BitStereo equ
        SAFT8kHz16BitMono equ
        SAFT8kHz16BitStereo equ
        SAFT11kHz8BitMono equ
        SAFT11kHz8BitStereo equ
        SAFT11kHz16BitMono equ
        SAFT11kHz16BitStereo equ
        SAFT12kHz8BitMono equ
        SAFT12kHz8BitStereo equ
        SAFT12kHz16BitMono equ
        SAFT12kHz16BitStereo equ
        SAFT16kHz8BitMono equ
        SAFT16kHz8BitStereo equ
        SAFT16kHz16BitMono equ
        SAFT16kHz16BitStereo equ
        SAFT22kHz8BitMono equ
        SAFT22kHz8BitStereo equ
        SAFT22kHz16BitMono equ
        SAFT22kHz16BitStereo equ
        SAFT24kHz8BitMono equ
        SAFT24kHz8BitStereo equ
        SAFT24kHz16BitMono equ
        SAFT24kHz16BitStereo equ
        SAFT32kHz8BitMono equ
        SAFT32kHz8BitStereo equ
        SAFT32kHz16BitMono equ
        SAFT32kHz16BitStereo equ
        SAFT44kHz8BitMono equ
        SAFT44kHz8BitStereo equ
        SAFT44kHz16BitMono equ
        SAFT44kHz16BitStereo equ
        SAFT48kHz8BitMono equ
        SAFT48kHz8BitStereo equ
        SAFT48kHz16BitMono equ
        SAFT48kHz16BitStereo equ
        SAFTTrueSpeech_8kHz1BitMono equ
        SAFTCCITT_ALaw_8kHzMono equ
        SAFTCCITT_ALaw_8kHzStereo equ
        SAFTCCITT_ALaw_11kHzMono equ
        SAFTCCITT_ALaw_11kHzStereo equ
        SAFTCCITT_ALaw_22kHzMono equ
        SAFTCCITT_ALaw_22kHzStereo equ
        SAFTCCITT_ALaw_44kHzMono equ
        SAFTCCITT_ALaw_44kHzStereo equ
        SAFTCCITT_uLaw_8kHzMono equ
        SAFTCCITT_uLaw_8kHzStereo equ
        SAFTCCITT_uLaw_11kHzMono equ
        SAFTCCITT_uLaw_11kHzStereo equ
        SAFTCCITT_uLaw_22kHzMono equ
        SAFTCCITT_uLaw_22kHzStereo equ
        SAFTCCITT_uLaw_44kHzMono equ
        SAFTCCITT_uLaw_44kHzStereo equ
        SAFTADPCM_8kHzMono equ
        SAFTADPCM_8kHzStereo equ
        SAFTADPCM_11kHzMono equ
        SAFTADPCM_11kHzStereo equ
        SAFTADPCM_22kHzMono equ
        SAFTADPCM_22kHzStereo equ
        SAFTADPCM_44kHzMono equ
        SAFTADPCM_44kHzStereo equ
        SAFTGSM610_8kHzMono equ
        SAFTGSM610_11kHzMono equ
        SAFTGSM610_22kHzMono equ
        SAFTGSM610_44kHzMono equ

        ;* [hidden] *
        DISPID_SpeechAudioFormat typedef SDWORD
        DISPID_SAFType equ 1
        DISPID_SAFGuid equ
        DISPID_SAFGetWaveFormatEx equ
        DISPID_SAFSetWaveFormatEx equ

        ;* [hidden] *
        DISPID_SpeechBaseStream typedef SDWORD
        DISPID_SBSFormat equ 1
        DISPID_SBSRead equ
        DISPID_SBSWrite equ
        DISPID_SBSSeek equ

        SpeechStreamSeekPositionType typedef SDWORD
        SSSPTRelativeToStart equ STREAM_SEEK_SET
        SSSPTRelativeToCurrentPosition equ STREAM_SEEK_CUR
        SSSPTRelativeToEnd equ STREAM_SEEK_END

        ;* [hidden] *
        DISPID_SpeechAudio typedef SDWORD
        DISPID_SAStatus equ 200
        DISPID_SABufferInfo equ
        DISPID_SADefaultFormat equ
        DISPID_SAVolume equ
        DISPID_SABufferNotifySize equ
        DISPID_SAEventHandle equ
        DISPID_SASetState equ

        SpeechAudioState typedef SDWORD
        SASClosed equ SPAS_CLOSED
        SASStop equ SPAS_STOP
        SASPause equ SPAS_PAUSE
        SASRun equ SPAS_RUN

        ;* [hidden] *
        DISPID_SpeechMMSysAudio typedef SDWORD
        DISPID_SMSADeviceId equ 300
        DISPID_SMSALineId equ
        DISPID_SMSAMMHandle equ

        ;* [hidden] *
        DISPID_SpeechFileStream typedef SDWORD
        DISPID_SFSOpen equ 100
        DISPID_SFSClose equ

        SpeechStreamFileMode typedef SDWORD
        SSFMOpenForRead equ SPFM_OPEN_READONLY
        SSFMOpenReadWrite equ SPFM_OPEN_READWRITE
        SSFMCreate equ SPFM_CREATE
        SSFMCreateForWrite equ SPFM_CREATE_ALWAYS

        ;* [hidden] *
        DISPID_SpeechCustomStream typedef SDWORD
        DISPID_SCSBaseStream equ 100

        ;* [hidden] *
        DISPID_SpeechMemoryStream typedef SDWORD
        DISPID_SMSSetData equ 100
        DISPID_SMSGetData equ

        ;* [hidden] *
        DISPID_SpeechAudioStatus typedef SDWORD
        DISPID_SASFreeBufferSpace equ 1
        DISPID_SASNonBlockingIO equ
        DISPID_SASState equ
        DISPID_SASCurrentSeekPosition equ
        DISPID_SASCurrentDevicePosition equ

        ;* [hidden] *
        DISPID_SpeechAudioBufferInfo typedef SDWORD
        DISPID_SABIMinNotification equ 1
        DISPID_SABIBufferSize equ
        DISPID_SABIEventBias equ

        ;* [hidden] *
        DISPID_SpeechWaveFormatEx typedef SDWORD
        DISPID_SWFEFormatTag equ 1
        DISPID_SWFEChannels equ
        DISPID_SWFESamplesPerSec equ
        DISPID_SWFEAvgBytesPerSec equ
        DISPID_SWFEBlockAlign equ
        DISPID_SWFEBitsPerSample equ
        DISPID_SWFEExtraData equ

        ;* [hidden] *
        DISPID_SpeechVoice typedef SDWORD
        DISPID_SVStatus equ 1
        DISPID_SVVoice equ
        DISPID_SVAudioOutput equ
        DISPID_SVAudioOutputStream equ
        DISPID_SVRate equ
        DISPID_SVVolume equ
        DISPID_SVAllowAudioOuputFormatChangesOnNextSet equ
        DISPID_SVEventInterests equ
        DISPID_SVPriority equ
        DISPID_SVAlertBoundary equ
        DISPID_SVSyncronousSpeakTimeout equ
        DISPID_SVSpeak equ
        DISPID_SVSpeakStream equ
        DISPID_SVPause equ
        DISPID_SVResume equ
        DISPID_SVSkip equ
        DISPID_SVGetVoices equ
        DISPID_SVGetAudioOutputs equ
        DISPID_SVWaitUntilDone equ
        DISPID_SVSpeakCompleteEvent equ
        DISPID_SVIsUISupported equ
        DISPID_SVDisplayUI equ

        SpeechVoicePriority typedef SDWORD
        SVPNormal equ SPVPRI_NORMAL
        SVPAlert equ SPVPRI_ALERT
        SVPOver equ SPVPRI_OVER

        SpeechVoiceSpeakFlags typedef SDWORD
        SVSFDefault equ SPF_DEFAULT
        SVSFlagsAsync equ SPF_ASYNC
        SVSFPurgeBeforeSpeak equ SPF_PURGEBEFORESPEAK
        SVSFIsFilename equ SPF_IS_FILENAME
        SVSFIsXML equ SPF_IS_XML
        SVSFIsNotXML equ SPF_IS_NOT_XML
        SVSFPersistXML equ SPF_PERSIST_XML
        SVSFNLPSpeakPunc equ SPF_NLP_SPEAK_PUNC
        SVSFNLPMask equ SPF_NLP_MASK
        SVSFVoiceMask equ SPF_VOICE_MASK
        SVSFUnusedFlags equ SPF_UNUSED_FLAGS

        SpeechVoiceEvents typedef SDWORD
        SVEStartInputStream equ
        SVEEndInputStream equ
        SVEVoiceChange equ
        SVEBookmark equ
        SVEWordBoundary equ
        SVEPhoneme equ
        SVESentenceBoundary equ
        SVEViseme equ
        SVEAudioLevel equ
        SVEPrivate equ
        SVEAllEvents equ 83feh

        ;* [hidden] *
        DISPID_SpeechVoiceStatus typedef SDWORD
        DISPID_SVSCurrentStreamNumber equ 1
        DISPID_SVSLastStreamNumberQueued equ
        DISPID_SVSLastResult equ
        DISPID_SVSRunningState equ
        DISPID_SVSInputWordPosition equ
        DISPID_SVSInputWordLength equ
        DISPID_SVSInputSentencePosition equ
        DISPID_SVSInputSentenceLength equ
        DISPID_SVSLastBookmark equ
        DISPID_SVSLastBookmarkId equ
        DISPID_SVSPhonemeId equ
        DISPID_SVSVisemeId equ

        SpeechRunState typedef SDWORD
        SRSEDone equ SPRS_DONE
        SRSEIsSpeaking equ SPRS_IS_SPEAKING

        SpeechVisemeType typedef SDWORD
        SVP_0 equ 0
        SVP_1 equ
        SVP_2 equ
        SVP_3 equ
        SVP_4 equ
        SVP_5 equ
        SVP_6 equ
        SVP_7 equ
        SVP_8 equ
        SVP_9 equ
        SVP_10 equ
        SVP_11 equ
        SVP_12 equ
        SVP_13 equ
        SVP_14 equ
        SVP_15 equ
        SVP_16 equ
        SVP_17 equ
        SVP_18 equ
        SVP_19 equ
        SVP_20 equ
        SVP_21 equ

        SpeechVisemeFeature typedef SDWORD
        SVF_None equ 0
        SVF_Stressed equ SPVFEATURE_STRESSED
        SVF_Emphasis equ SPVFEATURE_EMPHASIS

        ;* [hidden] *
        DISPID_SpeechVoiceEvent typedef SDWORD
        DISPID_SVEStreamStart equ 1
        DISPID_SVEStreamEnd equ
        DISPID_SVEVoiceChange equ
        DISPID_SVEBookmark equ
        DISPID_SVEWord equ
        DISPID_SVEPhoneme equ
        DISPID_SVESentenceBoundary equ
        DISPID_SVEViseme equ
        DISPID_SVEAudioLevel equ
        DISPID_SVEEnginePrivate equ

        ;* [hidden] *
        DISPID_SpeechRecognizer typedef SDWORD
        DISPID_SRRecognizer equ 1
        DISPID_SRAllowAudioInputFormatChangesOnNextSet equ
        DISPID_SRAudioInput equ
        DISPID_SRAudioInputStream equ
        DISPID_SRIsShared equ
        DISPID_SRState equ
        DISPID_SRStatus equ
        DISPID_SRProfile equ
        DISPID_SREmulateRecognition equ
        DISPID_SRCreateRecoContext equ
        DISPID_SRGetFormat equ
        DISPID_SRSetPropertyNumber equ
        DISPID_SRGetPropertyNumber equ
        DISPID_SRSetPropertyString equ
        DISPID_SRGetPropertyString equ
        DISPID_SRIsUISupported equ
        DISPID_SRDisplayUI equ
        DISPID_SRGetRecognizers equ
        DISPID_SVGetAudioInputs equ
        DISPID_SVGetProfiles equ

        SpeechRecognizerState typedef SDWORD
        SRSInactive equ SPRST_INACTIVE
        SRSActive equ SPRST_ACTIVE
        SRSActiveAlways equ SPRST_ACTIVE_ALWAYS
        SRSInactiveWithPurge equ SPRST_INACTIVE_WITH_PURGE

        SpeechDisplayAttributes typedef SDWORD
        SDA_No_Trailing_Space equ 0
        SDA_One_Trailing_Space equ SPAF_ONE_TRAILING_SPACE
        SDA_Two_Trailing_Spaces equ SPAF_TWO_TRAILING_SPACES
        SDA_Consume_Leading_Spaces equ SPAF_CONSUME_LEADING_SPACES

        SpeechFormatType typedef SDWORD
        SFTInput equ SPWF_INPUT
        SFTSREngine equ SPWF_SRENGINE

        ;* [hidden] *
        DISPID_SpeechRecognizerStatus typedef SDWORD
        DISPID_SRSAudioStatus equ 1
        DISPID_SRSCurrentStreamPosition equ
        DISPID_SRSCurrentStreamNumber equ
        DISPID_SRSNumberOfActiveRules equ
        DISPID_SRSClsidEngine equ
        DISPID_SRSSupportedLanguages equ

        ;* [hidden] *
        DISPID_SpeechRecoContext typedef SDWORD
        DISPID_SRCRecognizer equ 1
        DISPID_SRCAudioInInterferenceStatus equ
        DISPID_SRCRequestedUIType equ
        DISPID_SRCVoice equ
        DISPID_SRAllowVoiceFormatMatchingOnNextSet equ
        DISPID_SRCVoicePurgeEvent equ
        DISPID_SRCEventInterests equ
        DISPID_SRCCmdMaxAlternates equ
        DISPID_SRCState equ
        DISPID_SRCRetainedAudio equ
        DISPID_SRCRetainedAudioFormat equ
        DISPID_SRCPause equ
        DISPID_SRCResume equ
        DISPID_SRCCreateGrammar equ
        DISPID_SRCCreateResultFromMemory equ
        DISPID_SRCBookmark equ
        DISPID_SRCSetAdaptationData equ

        SpeechRetainedAudioOptions typedef SDWORD
        SRAONone equ SPAO_NONE
        SRAORetainAudio equ SPAO_RETAIN_AUDIO

        SpeechBookmarkOptions typedef SDWORD
        SBONone equ SPBO_NONE
        SBOPause equ SPBO_PAUSE

        SpeechInterference typedef SDWORD
        SINone equ SPINTERFERENCE_NONE
        SINoise equ SPINTERFERENCE_NOISE
        SINoSignal equ SPINTERFERENCE_NOSIGNAL
        SITooLoud equ SPINTERFERENCE_TOOLOUD
        SITooQuiet equ SPINTERFERENCE_TOOQUIET
        SITooFast equ SPINTERFERENCE_TOOFAST
        SITooSlow equ SPINTERFERENCE_TOOSLOW

        SpeechRecoEvents typedef SDWORD
        SREStreamEnd equ
        SRESoundStart equ
        SRESoundEnd equ
        SREPhraseStart equ
        SRERecognition equ
        SREHypothesis equ
        SREBookmark equ
        SREPropertyNumChange equ
        SREPropertyStringChange equ
        SREFalseRecognition equ
        SREInterference equ
        SRERequestUI equ
        SREStateChange equ
        SREAdaptation equ
        SREStreamStart equ
        SRERecoOtherContext equ
        SREAudioLevel equ
        SREPrivate equ
        SREAllEvents equ 5ffffh

        SpeechRecoContextState typedef SDWORD
        SRCS_Disabled equ SPCS_DISABLED
        SRCS_Enabled equ SPCS_ENABLED

        ;* [hidden] *
        DISPIDSPRG typedef SDWORD
        DISPID_SRGId equ 1
        DISPID_SRGRecoContext equ
        DISPID_SRGState equ
        DISPID_SRGRules equ
        DISPID_SRGReset equ
        DISPID_SRGCommit equ
        DISPID_SRGCmdLoadFromFile equ
        DISPID_SRGCmdLoadFromObject equ
        DISPID_SRGCmdLoadFromResource equ
        DISPID_SRGCmdLoadFromMemory equ
        DISPID_SRGCmdLoadFromProprietaryGrammar equ
        DISPID_SRGCmdSetRuleState equ
        DISPID_SRGCmdSetRuleIdState equ
        DISPID_SRGDictationLoad equ
        DISPID_SRGDictationUnload equ
        DISPID_SRGDictationSetState equ
        DISPID_SRGSetWordSequenceData equ
        DISPID_SRGSetTextSelection equ
        DISPID_SRGIsPronounceable equ

        SpeechLoadOption typedef SDWORD
        SLOStatic equ SPLO_STATIC
        SLODynamic equ SPLO_DYNAMIC

        SpeechWordPronounceable typedef SDWORD
        SWPUnknownWordUnpronounceable equ SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE
        SWPUnknownWordPronounceable equ SPWP_UNKNOWN_WORD_PRONOUNCEABLE
        SWPKnownWordPronounceable equ SPWP_KNOWN_WORD_PRONOUNCEABLE

        SpeechGrammarState typedef SDWORD
        SGSEnabled equ SPGS_ENABLED
        SGSDisabled equ SPGS_DISABLED
        SGSExclusive equ SPGS_EXCLUSIVE

        SpeechRuleState typedef SDWORD
        SGDSInactive equ SPRS_INACTIVE
        SGDSActive equ SPRS_ACTIVE
        SGDSActiveWithAutoPause equ SPRS_ACTIVE_WITH_AUTO_PAUSE

        SpeechRuleAttributes typedef SDWORD
        SRATopLevel equ SPRAF_TopLevel
        SRADefaultToActive equ SPRAF_Active
        SRAExport equ SPRAF_Export
        SRAImport equ SPRAF_Import
        SRAInterpreter equ SPRAF_Interpreter
        SRADynamic equ SPRAF_Dynamic

        SpeechGrammarWordType typedef SDWORD
        SGDisplay equ SPWT_DISPLAY
        SGLexical equ SPWT_LEXICAL
        SGPronounciation equ SPWT_PRONUNCIATION

        ;* [hidden] *
        DISPID_SpeechRecoContextEvents typedef SDWORD
        DISPID_SRCEStartStream equ 1
        DISPID_SRCEEndStream equ
        DISPID_SRCEBookmark equ
        DISPID_SRCESoundStart equ
        DISPID_SRCESoundEnd equ
        DISPID_SRCEPhraseStart equ
        DISPID_SRCERecognition equ
        DISPID_SRCEHypothesis equ
        DISPID_SRCEPropertyNumberChange equ
        DISPID_SRCEPropertyStringChange equ
        DISPID_SRCEFalseRecognition equ
        DISPID_SRCEInterference equ
        DISPID_SRCERequestUI equ
        DISPID_SRCERecognizerStateChange equ
        DISPID_SRCEAdaptation equ
        DISPID_SRCERecognitionForOtherContext equ
        DISPID_SRCEAudioLevel equ
        DISPID_SRCEEnginePrivate equ

        SpeechRecognitionType typedef SDWORD
        SRTStandard equ 0
        SRTAutopause equ SPREF_AutoPause
        SRTEmulated equ SPREF_Emulated

        ;* [hidden] *
        DISPID_SpeechGrammarRule typedef SDWORD
        DISPID_SGRAttributes equ 1
        DISPID_SGRInitialState equ
        DISPID_SGRName equ
        DISPID_SGRId equ
        DISPID_SGRClear equ
        DISPID_SGRAddResource equ
        DISPID_SGRAddState equ

        ;* [hidden] *
        DISPID_SpeechGrammarRules typedef SDWORD
        DISPID_SGRsCount equ 1
        DISPID_SGRsDynamic equ
        DISPID_SGRsAdd equ
        DISPID_SGRsCommit equ
        DISPID_SGRsCommitAndSave equ
        DISPID_SGRsFindRule equ
        DISPID_SGRsItem equ DISPID_VALUE
        DISPID_SGRs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechGrammarRuleState typedef SDWORD
        DISPID_SGRSRule equ 1
        DISPID_SGRSTransitions equ
        DISPID_SGRSAddWordTransition equ
        DISPID_SGRSAddRuleTransition equ
        DISPID_SGRSAddSpecialTransition equ

        SpeechSpecialTransitionType typedef SDWORD
        SSTTWildcard equ 1
        SSTTDictation equ
        SSTTTextBuffer equ

        ;* [hidden] *
        DISPID_SpeechGrammarRuleStateTransitions typedef SDWORD
        DISPID_SGRSTsCount equ 1
        DISPID_SGRSTsItem equ DISPID_VALUE
        DISPID_SGRSTs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechGrammarRuleStateTransition typedef SDWORD
        DISPID_SGRSTType equ 1
        DISPID_SGRSTText equ
        DISPID_SGRSTRule equ
        DISPID_SGRSTWeight equ
        DISPID_SGRSTPropertyName equ
        DISPID_SGRSTPropertyId equ
        DISPID_SGRSTPropertyValue equ
        DISPID_SGRSTNextState equ

        SpeechGrammarRuleStateTransitionType typedef SDWORD
        SGRSTTEpsilon equ 0
        SGRSTTWord equ
        SGRSTTRule equ
        SGRSTTDictation equ
        SGRSTTWildcard equ
        SGRSTTTextBuffer equ

        ;* [hidden] *
        DISPIDSPTSI typedef SDWORD
        DISPIDSPTSI_ActiveOffset equ 1
        DISPIDSPTSI_ActiveLength equ
        DISPIDSPTSI_SelectionOffset equ
        DISPIDSPTSI_SelectionLength equ

        ;* [hidden] *
        DISPID_SpeechRecoResult typedef SDWORD
        DISPID_SRRRecoContext equ 1
        DISPID_SRRTimes equ
        DISPID_SRRAudioFormat equ
        DISPID_SRRPhraseInfo equ
        DISPID_SRRAlternates equ
        DISPID_SRRAudio equ
        DISPID_SRRSpeakAudio equ
        DISPID_SRRSaveToMemory equ
        DISPID_SRRDiscardResultInfo equ

        SpeechDiscardType typedef SDWORD
        SDTProperty equ SPDF_PROPERTY
        SDTReplacement equ SPDF_REPLACEMENT
        SDTRule equ SPDF_RULE
        SDTDisplayText equ SPDF_DISPLAYTEXT
        SDTLexicalForm equ SPDF_LEXICALFORM
        SDTPronunciation equ SPDF_PRONUNCIATION
        SDTAudio equ SPDF_AUDIO
        SDTAlternates equ SPDF_ALTERNATES
        SDTAll equ SPDF_ALL

        ;* [hidden] *
        DISPID_SpeechPhraseBuilder typedef SDWORD
        DISPID_SPPBRestorePhraseFromMemory equ 1

        ;* [hidden] *
        DISPID_SpeechRecoResultTimes typedef SDWORD
        DISPID_SRRTStreamTime equ 1
        DISPID_SRRTLength equ
        DISPID_SRRTTickCount equ
        DISPID_SRRTOffsetFromStart equ

        ;* [hidden] *
        DISPID_SpeechPhraseAlternate typedef SDWORD
        DISPID_SPARecoResult equ 1
        DISPID_SPAStartElementInResult equ
        DISPID_SPANumberOfElementsInResult equ
        DISPID_SPAPhraseInfo equ
        DISPID_SPACommit equ

        ;* [hidden] *
        DISPID_SpeechPhraseAlternates typedef SDWORD
        DISPID_SPAsCount equ 1
        DISPID_SPAsItem equ DISPID_VALUE
        DISPID_SPAs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechPhraseInfo typedef SDWORD
        DISPID_SPILanguageId equ 1
        DISPID_SPIGrammarId equ
        DISPID_SPIStartTime equ
        DISPID_SPIAudioStreamPosition equ
        DISPID_SPIAudioSizeBytes equ
        DISPID_SPIRetainedSizeBytes equ
        DISPID_SPIAudioSizeTime equ
        DISPID_SPIRule equ
        DISPID_SPIProperties equ
        DISPID_SPIElements equ
        DISPID_SPIReplacements equ
        DISPID_SPIEngineId equ
        DISPID_SPIEnginePrivateData equ
        DISPID_SPISaveToMemory equ
        DISPID_SPIGetText equ
        DISPID_SPIGetDisplayAttributes equ

        ;* [hidden] *
        DISPID_SpeechPhraseElement typedef SDWORD
        DISPID_SPEAudioTimeOffset equ 1
        DISPID_SPEAudioSizeTime equ
        DISPID_SPEAudioStreamOffset equ
        DISPID_SPEAudioSizeBytes equ
        DISPID_SPERetainedStreamOffset equ
        DISPID_SPERetainedSizeBytes equ
        DISPID_SPEDisplayText equ
        DISPID_SPELexicalForm equ
        DISPID_SPEPronunciation equ
        DISPID_SPEDisplayAttributes equ
        DISPID_SPERequiredConfidence equ
        DISPID_SPEActualConfidence equ
        DISPID_SPEEngineConfidence equ

        SpeechEngineConfidence typedef SDWORD
        SECLowConfidence equ -1
        SECNormalConfidence equ 0
        SECHighConfidence equ 1

        ;* [hidden] *
        DISPID_SpeechPhraseElements typedef SDWORD
        DISPID_SPEsCount equ 1
        DISPID_SPEsItem equ DISPID_VALUE
        DISPID_SPEs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechPhraseReplacement typedef SDWORD
        DISPID_SPRDisplayAttributes equ 1
        DISPID_SPRText equ
        DISPID_SPRFirstElement equ
        DISPID_SPRNumberOfElements equ

        ;* [hidden] *
        DISPID_SpeechPhraseReplacements typedef SDWORD
        DISPID_SPRsCount equ 1
        DISPID_SPRsItem equ DISPID_VALUE
        DISPID_SPRs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechPhraseProperty typedef SDWORD
        DISPID_SPPName equ 1
        DISPID_SPPId equ
        DISPID_SPPValue equ
        DISPID_SPPFirstElement equ
        DISPID_SPPNumberOfElements equ
        DISPID_SPPEngineConfidence equ
        DISPID_SPPConfidence equ
        DISPID_SPPParent equ
        DISPID_SPPChildren equ

        ;* [hidden] *
        DISPID_SpeechPhraseProperties typedef SDWORD
        DISPID_SPPsCount equ 1
        DISPID_SPPsItem equ DISPID_VALUE
        DISPID_SPPs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechPhraseRule typedef SDWORD
        DISPID_SPRuleName equ 1
        DISPID_SPRuleId equ
        DISPID_SPRuleFirstElement equ
        DISPID_SPRuleNumberOfElements equ
        DISPID_SPRuleParent equ
        DISPID_SPRuleChildren equ
        DISPID_SPRuleConfidence equ
        DISPID_SPRuleEngineConfidence equ

        ;* [hidden] *
        DISPID_SpeechPhraseRules typedef SDWORD
        DISPID_SPRulesCount equ 1
        DISPID_SPRulesItem equ DISPID_VALUE
        DISPID_SPRules_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechLexicon typedef SDWORD
        DISPID_SLGenerationId equ 1
        DISPID_SLGetWords equ
        DISPID_SLAddPronunciation equ
        DISPID_SLAddPronunciationByPhoneIds equ
        DISPID_SLRemovePronunciation equ
        DISPID_SLRemovePronunciationByPhoneIds equ
        DISPID_SLGetPronunciations equ
        DISPID_SLGetGenerationChange equ

        SpeechLexiconType typedef SDWORD
        SLTUser equ eLEXTYPE_USER
        SLTApp equ eLEXTYPE_APP

        SpeechPartOfSpeech typedef SDWORD
        SPSNotOverriden equ SPPS_NotOverriden
        SPSUnknown equ SPPS_Unknown
        SPSNoun equ SPPS_Noun
        SPSVerb equ SPPS_Verb
        SPSModifier equ SPPS_Modifier
        SPSFunction equ SPPS_Function
        SPSInterjection equ SPPS_Interjection

        ;* [hidden] *
        DISPID_SpeechLexiconWords typedef SDWORD
        DISPID_SLWsCount equ 1
        DISPID_SLWsItem equ DISPID_VALUE
        DISPID_SLWs_NewEnum equ DISPID_NEWENUM

        SpeechWordType typedef SDWORD
        SWTAdded equ eWORDTYPE_ADDED
        SWTDeleted equ eWORDTYPE_DELETED

        ;* [hidden] *
        DISPID_SpeechLexiconWord typedef SDWORD
        DISPID_SLWLangId equ 1
        DISPID_SLWType equ
        DISPID_SLWWord equ
        DISPID_SLWPronunciations equ

        ;* [hidden] *
        DISPID_SpeechLexiconProns typedef SDWORD
        DISPID_SLPsCount equ 1
        DISPID_SLPsItem equ DISPID_VALUE
        DISPID_SLPs_NewEnum equ DISPID_NEWENUM

        ;* [hidden] *
        DISPID_SpeechLexiconPronunciation typedef SDWORD
        DISPID_SLPType equ 1
        DISPID_SLPLangId equ
        DISPID_SLPPartOfSpeech equ
        DISPID_SLPPhoneIds equ
        DISPID_SLPSymbolic equ

        ;* [hidden] *
        DISPID_SpeechPhoneConverter typedef SDWORD
        DISPID_SPCLangId equ 1
        DISPID_SPCPhoneToId equ
        DISPID_SPCIdToPhone equ

        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      externdef LIBID_SpeechLib:IID
      ifndef __ISpeechDataKey_INTERFACE_DEFINED__
        __ISpeechDataKey_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechDataKey *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechDataKey:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechDataKeyVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechDataKeyVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechDataKey, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechDataKey
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechDataKey
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechDataKey, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechDataKey, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechDataKey, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechDataKey, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechDataKey, SetBinaryValue)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD SetBinaryValue, :ptr ISpeechDataKey, :BSTR, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, GetBinaryValue)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD GetBinaryValue, :ptr ISpeechDataKey, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, SetStringValue)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD SetStringValue, :ptr ISpeechDataKey, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, GetStringValue)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD GetStringValue, :ptr ISpeechDataKey, :BSTR, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, SetLongValue)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD SetLongValue, :ptr ISpeechDataKey, :BSTR, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, GetLongValue)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD GetLongValue, :ptr ISpeechDataKey, :BSTR, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, OpenKey)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD OpenKey, :ptr ISpeechDataKey, :BSTR, :ptr ptr ISpeechDataKey
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, CreateKey)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD CreateKey, :ptr ISpeechDataKey, :BSTR, :ptr ptr ISpeechDataKey
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, DeleteKey)
            ;* [id][helpstring] *
            STD_METHOD DeleteKey, :ptr ISpeechDataKey, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, DeleteValue)
            ;* [id][helpstring] *
            STD_METHOD DeleteValue, :ptr ISpeechDataKey, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, EnumKeys)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD EnumKeys, :ptr ISpeechDataKey, :SDWORD, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechDataKey, EnumValues)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD EnumValues, :ptr ISpeechDataKey, :SDWORD, :ptr BSTR
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechDataKeyVtbl ends
          ISpeechDataKey struct
            lpVtbl POINTER ?
          ISpeechDataKey ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechDataKey_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechObjectToken_INTERFACE_DEFINED__
        __ISpeechObjectToken_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechObjectToken *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechObjectToken:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechObjectTokenVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechObjectTokenVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechObjectToken, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechObjectToken
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechObjectToken
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechObjectToken, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechObjectToken, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechObjectToken, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechObjectToken, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechObjectToken, get_Id)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Id, :ptr ISpeechObjectToken, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, get_DataKey)
            ;* [hidden][id][helpstring][propget] *
            STD_METHOD get_DataKey, :ptr ISpeechObjectToken, :ptr ptr ISpeechDataKey
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, get_Category)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Category, :ptr ISpeechObjectToken, :ptr ptr ISpeechObjectTokenCategory
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, GetDescription)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            STD_METHOD GetDescription, :ptr ISpeechObjectToken, :SDWORD, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, SetId)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD SetId, :ptr ISpeechObjectToken, :BSTR, :BSTR, :VARIANT_BOOL
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, GetAttribute)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD GetAttribute, :ptr ISpeechObjectToken, :BSTR, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, CreateInstance)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD CreateInstance, :ptr ISpeechObjectToken, :ptr IUnknown, :SpeechTokenContext, :ptr ptr IUnknown
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, Remove)
            ;* [id][hidden][helpstring] *
            STD_METHOD Remove, :ptr ISpeechObjectToken, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, GetStorageFileName)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetStorageFileName, :ptr ISpeechObjectToken, :BSTR, :BSTR, :BSTR, :SpeechTokenShellFolder, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, RemoveStorageFileName)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD RemoveStorageFileName, :ptr ISpeechObjectToken, :BSTR, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, IsUISupported)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD IsUISupported, :ptr ISpeechObjectToken, :BSTR, :ptr VARIANT, :ptr IUnknown, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, DisplayUI)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD DisplayUI, :ptr ISpeechObjectToken, :SDWORD, :BSTR, :BSTR, :ptr VARIANT, :ptr IUnknown
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechObjectToken, MatchesAttributes)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD MatchesAttributes, :ptr ISpeechObjectToken, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechObjectTokenVtbl ends
          ISpeechObjectToken struct
            lpVtbl POINTER ?
          ISpeechObjectToken ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechObjectToken_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechObjectTokens_INTERFACE_DEFINED__
        __ISpeechObjectTokens_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechObjectTokens *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechObjectTokens:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechObjectTokensVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechObjectTokensVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechObjectTokens, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechObjectTokens
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechObjectTokens
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechObjectTokens, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechObjectTokens, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechObjectTokens, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechObjectTokens, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechObjectTokens, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechObjectTokens, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokens, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechObjectTokens, :SDWORD, :ptr ptr ISpeechObjectToken
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokens, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechObjectTokens, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechObjectTokensVtbl ends
          ISpeechObjectTokens struct
            lpVtbl POINTER ?
          ISpeechObjectTokens ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechObjectTokens_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechObjectTokenCategory_INTERFACE_DEFINED__
        __ISpeechObjectTokenCategory_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechObjectTokenCategory *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechObjectTokenCategory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechObjectTokenCategoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechObjectTokenCategoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechObjectTokenCategory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechObjectTokenCategory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechObjectTokenCategory
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechObjectTokenCategory, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechObjectTokenCategory, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechObjectTokenCategory, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechObjectTokenCategory, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechObjectTokenCategory, get_Id)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Id, :ptr ISpeechObjectTokenCategory, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokenCategory, put_Default)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Default, :ptr ISpeechObjectTokenCategory, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokenCategory, get_Default)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Default, :ptr ISpeechObjectTokenCategory, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokenCategory, SetId)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD SetId, :ptr ISpeechObjectTokenCategory, :BSTR, :VARIANT_BOOL
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokenCategory, GetDataKey)
            ;* [id][hidden][helpstring] *
            ;* [defaultvalue][in] *
            STD_METHOD GetDataKey, :ptr ISpeechObjectTokenCategory, :SpeechDataKeyLocation, :ptr ptr ISpeechDataKey
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechObjectTokenCategory, EnumerateTokens)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD EnumerateTokens, :ptr ISpeechObjectTokenCategory, :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechObjectTokenCategoryVtbl ends
          ISpeechObjectTokenCategory struct
            lpVtbl POINTER ?
          ISpeechObjectTokenCategory ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechObjectTokenCategory_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechAudioBufferInfo_INTERFACE_DEFINED__
        __ISpeechAudioBufferInfo_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechAudioBufferInfo *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechAudioBufferInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechAudioBufferInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechAudioBufferInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechAudioBufferInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechAudioBufferInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechAudioBufferInfo
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechAudioBufferInfo, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechAudioBufferInfo, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechAudioBufferInfo, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechAudioBufferInfo, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechAudioBufferInfo, get_MinNotification)
            ;* [id][helpstring][propget] *
            STD_METHOD get_MinNotification, :ptr ISpeechAudioBufferInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioBufferInfo, put_MinNotification)
            ;* [id][helpstring][propput] *
            STD_METHOD put_MinNotification, :ptr ISpeechAudioBufferInfo, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudioBufferInfo, get_BufferSize)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BufferSize, :ptr ISpeechAudioBufferInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioBufferInfo, put_BufferSize)
            ;* [id][helpstring][propput] *
            STD_METHOD put_BufferSize, :ptr ISpeechAudioBufferInfo, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudioBufferInfo, get_EventBias)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EventBias, :ptr ISpeechAudioBufferInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioBufferInfo, put_EventBias)
            ;* [id][helpstring][propput] *
            STD_METHOD put_EventBias, :ptr ISpeechAudioBufferInfo, :SDWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechAudioBufferInfoVtbl ends
          ISpeechAudioBufferInfo struct
            lpVtbl POINTER ?
          ISpeechAudioBufferInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechAudioBufferInfo_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechAudioStatus_INTERFACE_DEFINED__
        __ISpeechAudioStatus_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechAudioStatus *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechAudioStatus:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechAudioStatusVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechAudioStatusVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechAudioStatus, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechAudioStatus
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechAudioStatus
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechAudioStatus, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechAudioStatus, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechAudioStatus, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechAudioStatus, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechAudioStatus, get_FreeBufferSpace)
            ;* [id][helpstring][propget] *
            STD_METHOD get_FreeBufferSpace, :ptr ISpeechAudioStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioStatus, get_NonBlockingIO)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NonBlockingIO, :ptr ISpeechAudioStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioStatus, get_State)
            ;* [id][helpstring][propget] *
            STD_METHOD get_State, :ptr ISpeechAudioStatus, :ptr SpeechAudioState
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioStatus, get_CurrentSeekPosition)
            ;* [id][helpstring][propget] *
            STD_METHOD get_CurrentSeekPosition, :ptr ISpeechAudioStatus, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioStatus, get_CurrentDevicePosition)
            ;* [id][helpstring][propget] *
            STD_METHOD get_CurrentDevicePosition, :ptr ISpeechAudioStatus, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechAudioStatusVtbl ends
          ISpeechAudioStatus struct
            lpVtbl POINTER ?
          ISpeechAudioStatus ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechAudioStatus_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechAudioFormat_INTERFACE_DEFINED__
        __ISpeechAudioFormat_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechAudioFormat *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechAudioFormat:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechAudioFormatVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechAudioFormatVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechAudioFormat, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechAudioFormat
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechAudioFormat
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechAudioFormat, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechAudioFormat, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechAudioFormat, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechAudioFormat, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechAudioFormat, get_Type)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Type, :ptr ISpeechAudioFormat, :ptr SpeechAudioFormatType
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioFormat, put_Type)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Type, :ptr ISpeechAudioFormat, :SpeechAudioFormatType
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudioFormat, get_Guid)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_Guid, :ptr ISpeechAudioFormat, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioFormat, put_Guid)
            ;* [id][helpstring][hidden][propput] *
            STD_METHOD put_Guid, :ptr ISpeechAudioFormat, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudioFormat, GetWaveFormatEx)
            ;* [id][helpstring][hidden] *
            STD_METHOD GetWaveFormatEx, :ptr ISpeechAudioFormat, :ptr ptr ISpeechWaveFormatEx
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudioFormat, SetWaveFormatEx)
            ;* [id][helpstring][hidden] *
            STD_METHOD SetWaveFormatEx, :ptr ISpeechAudioFormat, :ptr ISpeechWaveFormatEx
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechAudioFormatVtbl ends
          ISpeechAudioFormat struct
            lpVtbl POINTER ?
          ISpeechAudioFormat ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechAudioFormat_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechWaveFormatEx_INTERFACE_DEFINED__
        __ISpeechWaveFormatEx_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechWaveFormatEx *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechWaveFormatEx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechWaveFormatExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechWaveFormatExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechWaveFormatEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechWaveFormatEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechWaveFormatEx
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechWaveFormatEx, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechWaveFormatEx, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechWaveFormatEx, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechWaveFormatEx, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_FormatTag)
            ;* [id][helpstring][propget] *
            STD_METHOD get_FormatTag, :ptr ISpeechWaveFormatEx, :ptr SWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_FormatTag)
            ;* [id][helpstring][propput] *
            STD_METHOD put_FormatTag, :ptr ISpeechWaveFormatEx, :SWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_Channels)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Channels, :ptr ISpeechWaveFormatEx, :ptr SWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_Channels)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Channels, :ptr ISpeechWaveFormatEx, :SWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_SamplesPerSec)
            ;* [id][helpstring][propget] *
            STD_METHOD get_SamplesPerSec, :ptr ISpeechWaveFormatEx, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_SamplesPerSec)
            ;* [id][helpstring][propput] *
            STD_METHOD put_SamplesPerSec, :ptr ISpeechWaveFormatEx, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_AvgBytesPerSec)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AvgBytesPerSec, :ptr ISpeechWaveFormatEx, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_AvgBytesPerSec)
            ;* [id][helpstring][propput] *
            STD_METHOD put_AvgBytesPerSec, :ptr ISpeechWaveFormatEx, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_BlockAlign)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BlockAlign, :ptr ISpeechWaveFormatEx, :ptr SWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_BlockAlign)
            ;* [id][helpstring][propput] *
            STD_METHOD put_BlockAlign, :ptr ISpeechWaveFormatEx, :SWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_BitsPerSample)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BitsPerSample, :ptr ISpeechWaveFormatEx, :ptr SWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_BitsPerSample)
            ;* [id][helpstring][propput] *
            STD_METHOD put_BitsPerSample, :ptr ISpeechWaveFormatEx, :SWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, get_ExtraData)
            ;* [id][helpstring][propget] *
            STD_METHOD get_ExtraData, :ptr ISpeechWaveFormatEx, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechWaveFormatEx, put_ExtraData)
            ;* [id][helpstring][propput] *
            STD_METHOD put_ExtraData, :ptr ISpeechWaveFormatEx, :VARIANT
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechWaveFormatExVtbl ends
          ISpeechWaveFormatEx struct
            lpVtbl POINTER ?
          ISpeechWaveFormatEx ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechWaveFormatEx_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechBaseStream_INTERFACE_DEFINED__
        __ISpeechBaseStream_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechBaseStream *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechBaseStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechBaseStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechBaseStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechBaseStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechBaseStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechBaseStream
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechBaseStream, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechBaseStream, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechBaseStream, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechBaseStream, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechBaseStream, get_Format)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Format, :ptr ISpeechBaseStream, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, putref_Format)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Format, :ptr ISpeechBaseStream, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Read)
            ;* [id][helpstring] *
            ;* [out] *
            ;* [in] *
            STD_METHOD Read, :ptr ISpeechBaseStream, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Write)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Write, :ptr ISpeechBaseStream, :VARIANT, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Seek)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Seek, :ptr ISpeechBaseStream, :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechBaseStreamVtbl ends
          ISpeechBaseStream struct
            lpVtbl POINTER ?
          ISpeechBaseStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechBaseStream_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechFileStream_INTERFACE_DEFINED__
        __ISpeechFileStream_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechFileStream *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechFileStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechFileStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechFileStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechFileStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechFileStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechFileStream
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechFileStream, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechFileStream, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechFileStream, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechFileStream, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechBaseStream, get_Format)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Format, :ptr ISpeechFileStream, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, putref_Format)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Format, :ptr ISpeechFileStream, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Read)
            ;* [id][helpstring] *
            ;* [out] *
            ;* [in] *
            STD_METHOD Read, :ptr ISpeechFileStream, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Write)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Write, :ptr ISpeechFileStream, :VARIANT, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Seek)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Seek, :ptr ISpeechFileStream, :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechFileStream, Open)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Open, :ptr ISpeechFileStream, :BSTR, :SpeechStreamFileMode, :VARIANT_BOOL
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechFileStream, Close)
            ;* [id][helpstring] *
            STD_METHOD Close, :ptr ISpeechFileStream
            ??Interface equ <>
            END_INTERFACE
          ISpeechFileStreamVtbl ends
          ISpeechFileStream struct
            lpVtbl POINTER ?
          ISpeechFileStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechFileStream_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechMemoryStream_INTERFACE_DEFINED__
        __ISpeechMemoryStream_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechMemoryStream *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechMemoryStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechMemoryStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechMemoryStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechMemoryStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechMemoryStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechMemoryStream
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechMemoryStream, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechMemoryStream, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechMemoryStream, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechMemoryStream, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechBaseStream, get_Format)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Format, :ptr ISpeechMemoryStream, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, putref_Format)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Format, :ptr ISpeechMemoryStream, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Read)
            ;* [id][helpstring] *
            ;* [out] *
            ;* [in] *
            STD_METHOD Read, :ptr ISpeechMemoryStream, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Write)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Write, :ptr ISpeechMemoryStream, :VARIANT, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Seek)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Seek, :ptr ISpeechMemoryStream, :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechMemoryStream, SetData)
            ;* [id][helpstring] *
            STD_METHOD SetData, :ptr ISpeechMemoryStream, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechMemoryStream, GetData)
            ;* [id][helpstring] *
            STD_METHOD GetData, :ptr ISpeechMemoryStream, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechMemoryStreamVtbl ends
          ISpeechMemoryStream struct
            lpVtbl POINTER ?
          ISpeechMemoryStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechMemoryStream_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechCustomStream_INTERFACE_DEFINED__
        __ISpeechCustomStream_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechCustomStream *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechCustomStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechCustomStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechCustomStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechCustomStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechCustomStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechCustomStream
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechCustomStream, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechCustomStream, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechCustomStream, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechCustomStream, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechBaseStream, get_Format)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Format, :ptr ISpeechCustomStream, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, putref_Format)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Format, :ptr ISpeechCustomStream, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Read)
            ;* [id][helpstring] *
            ;* [out] *
            ;* [in] *
            STD_METHOD Read, :ptr ISpeechCustomStream, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Write)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Write, :ptr ISpeechCustomStream, :VARIANT, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Seek)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Seek, :ptr ISpeechCustomStream, :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechCustomStream, get_BaseStream)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BaseStream, :ptr ISpeechCustomStream, :ptr ptr IUnknown
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechCustomStream, putref_BaseStream)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_BaseStream, :ptr ISpeechCustomStream, :ptr IUnknown
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechCustomStreamVtbl ends
          ISpeechCustomStream struct
            lpVtbl POINTER ?
          ISpeechCustomStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechCustomStream_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechAudio_INTERFACE_DEFINED__
        __ISpeechAudio_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechAudio *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechAudio:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechAudioVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechAudioVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechAudio, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechAudio
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechAudio
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechAudio, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechAudio, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechAudio, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechAudio, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechBaseStream, get_Format)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Format, :ptr ISpeechAudio, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, putref_Format)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Format, :ptr ISpeechAudio, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Read)
            ;* [id][helpstring] *
            ;* [out] *
            ;* [in] *
            STD_METHOD Read, :ptr ISpeechAudio, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Write)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Write, :ptr ISpeechAudio, :VARIANT, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Seek)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Seek, :ptr ISpeechAudio, :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_Status)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Status, :ptr ISpeechAudio, :ptr ptr ISpeechAudioStatus
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_BufferInfo)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BufferInfo, :ptr ISpeechAudio, :ptr ptr ISpeechAudioBufferInfo
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_DefaultFormat)
            ;* [id][helpstring][propget] *
            STD_METHOD get_DefaultFormat, :ptr ISpeechAudio, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_Volume)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Volume, :ptr ISpeechAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, put_Volume)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Volume, :ptr ISpeechAudio, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_BufferNotifySize)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BufferNotifySize, :ptr ISpeechAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, put_BufferNotifySize)
            ;* [id][helpstring][propput] *
            STD_METHOD put_BufferNotifySize, :ptr ISpeechAudio, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_EventHandle)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_EventHandle, :ptr ISpeechAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, SetState)
            ;* [hidden][id][helpstring] *
            STD_METHOD SetState, :ptr ISpeechAudio, :SpeechAudioState
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechAudioVtbl ends
          ISpeechAudio struct
            lpVtbl POINTER ?
          ISpeechAudio ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechAudio_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechMMSysAudio_INTERFACE_DEFINED__
        __ISpeechMMSysAudio_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechMMSysAudio *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechMMSysAudio:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechMMSysAudioVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechMMSysAudioVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechMMSysAudio, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechMMSysAudio
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechMMSysAudio
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechMMSysAudio, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechMMSysAudio, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechMMSysAudio, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechMMSysAudio, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechBaseStream, get_Format)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Format, :ptr ISpeechMMSysAudio, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, putref_Format)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Format, :ptr ISpeechMMSysAudio, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Read)
            ;* [id][helpstring] *
            ;* [out] *
            ;* [in] *
            STD_METHOD Read, :ptr ISpeechMMSysAudio, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Write)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Write, :ptr ISpeechMMSysAudio, :VARIANT, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechBaseStream, Seek)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Seek, :ptr ISpeechMMSysAudio, :VARIANT, :SpeechStreamSeekPositionType, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_Status)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Status, :ptr ISpeechMMSysAudio, :ptr ptr ISpeechAudioStatus
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_BufferInfo)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BufferInfo, :ptr ISpeechMMSysAudio, :ptr ptr ISpeechAudioBufferInfo
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_DefaultFormat)
            ;* [id][helpstring][propget] *
            STD_METHOD get_DefaultFormat, :ptr ISpeechMMSysAudio, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_Volume)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Volume, :ptr ISpeechMMSysAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, put_Volume)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Volume, :ptr ISpeechMMSysAudio, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_BufferNotifySize)
            ;* [id][helpstring][propget] *
            STD_METHOD get_BufferNotifySize, :ptr ISpeechMMSysAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, put_BufferNotifySize)
            ;* [id][helpstring][propput] *
            STD_METHOD put_BufferNotifySize, :ptr ISpeechMMSysAudio, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechAudio, get_EventHandle)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_EventHandle, :ptr ISpeechMMSysAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechAudio, SetState)
            ;* [hidden][id][helpstring] *
            STD_METHOD SetState, :ptr ISpeechMMSysAudio, :SpeechAudioState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechMMSysAudio, get_DeviceId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_DeviceId, :ptr ISpeechMMSysAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechMMSysAudio, put_DeviceId)
            ;* [id][helpstring][propput] *
            STD_METHOD put_DeviceId, :ptr ISpeechMMSysAudio, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechMMSysAudio, get_LineId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LineId, :ptr ISpeechMMSysAudio, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechMMSysAudio, put_LineId)
            ;* [id][helpstring][propput] *
            STD_METHOD put_LineId, :ptr ISpeechMMSysAudio, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechMMSysAudio, get_MMHandle)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_MMHandle, :ptr ISpeechMMSysAudio, :ptr SDWORD
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechMMSysAudioVtbl ends
          ISpeechMMSysAudio struct
            lpVtbl POINTER ?
          ISpeechMMSysAudio ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechMMSysAudio_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechVoice_INTERFACE_DEFINED__
        __ISpeechVoice_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechVoice *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechVoice:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechVoiceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechVoiceVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechVoice, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechVoice
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechVoice
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechVoice, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechVoice, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechVoice, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechVoice, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechVoice, get_Status)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Status, :ptr ISpeechVoice, :ptr ptr ISpeechVoiceStatus
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_Voice)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Voice, :ptr ISpeechVoice, :ptr ptr ISpeechObjectToken
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, putref_Voice)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Voice, :ptr ISpeechVoice, :ptr ISpeechObjectToken
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_AudioOutput)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioOutput, :ptr ISpeechVoice, :ptr ptr ISpeechObjectToken
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, putref_AudioOutput)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_AudioOutput, :ptr ISpeechVoice, :ptr ISpeechObjectToken
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_AudioOutputStream)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioOutputStream, :ptr ISpeechVoice, :ptr ptr ISpeechBaseStream
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, putref_AudioOutputStream)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_AudioOutputStream, :ptr ISpeechVoice, :ptr ISpeechBaseStream
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_Rate)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Rate, :ptr ISpeechVoice, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_Rate)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Rate, :ptr ISpeechVoice, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_Volume)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Volume, :ptr ISpeechVoice, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_Volume)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Volume, :ptr ISpeechVoice, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_AllowAudioOutputFormatChangesOnNextSet)
            ;* [id][helpstring][hidden][propput] *
            STD_METHOD put_AllowAudioOutputFormatChangesOnNextSet, :ptr ISpeechVoice, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_AllowAudioOutputFormatChangesOnNextSet)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_AllowAudioOutputFormatChangesOnNextSet, :ptr ISpeechVoice, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_EventInterests)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EventInterests, :ptr ISpeechVoice, :ptr SpeechVoiceEvents
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_EventInterests)
            ;* [id][helpstring][propput] *
            STD_METHOD put_EventInterests, :ptr ISpeechVoice, :SpeechVoiceEvents
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_Priority)
            ;* [id][helpstring][propput] *
            STD_METHOD put_Priority, :ptr ISpeechVoice, :SpeechVoicePriority
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_Priority)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Priority, :ptr ISpeechVoice, :ptr SpeechVoicePriority
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_AlertBoundary)
            ;* [id][helpstring][propput] *
            STD_METHOD put_AlertBoundary, :ptr ISpeechVoice, :SpeechVoiceEvents
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_AlertBoundary)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AlertBoundary, :ptr ISpeechVoice, :ptr SpeechVoiceEvents
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, put_SynchronousSpeakTimeout)
            ;* [id][helpstring][propput] *
            STD_METHOD put_SynchronousSpeakTimeout, :ptr ISpeechVoice, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechVoice, get_SynchronousSpeakTimeout)
            ;* [id][helpstring][propget] *
            STD_METHOD get_SynchronousSpeakTimeout, :ptr ISpeechVoice, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, Speak)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Speak, :ptr ISpeechVoice, :BSTR, :SpeechVoiceSpeakFlags, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, SpeakStream)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD SpeakStream, :ptr ISpeechVoice, :ptr ISpeechBaseStream, :SpeechVoiceSpeakFlags, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, Pause)
            ;* [id][helpstring] *
            STD_METHOD Pause, :ptr ISpeechVoice
            DECLSPEC_XFGVIRT(ISpeechVoice, Resume)
            ;* [id][helpstring] *
            STD_METHOD Resume, :ptr ISpeechVoice
            DECLSPEC_XFGVIRT(ISpeechVoice, Skip)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD Skip, :ptr ISpeechVoice, :BSTR, :SDWORD, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, GetVoices)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetVoices, :ptr ISpeechVoice, :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, GetAudioOutputs)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetAudioOutputs, :ptr ISpeechVoice, :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, WaitUntilDone)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD WaitUntilDone, :ptr ISpeechVoice, :SDWORD, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, SpeakCompleteEvent)
            ;* [id][hidden][helpstring] *
            STD_METHOD SpeakCompleteEvent, :ptr ISpeechVoice, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, IsUISupported)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD IsUISupported, :ptr ISpeechVoice, :BSTR, :ptr VARIANT, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoice, DisplayUI)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD DisplayUI, :ptr ISpeechVoice, :SDWORD, :BSTR, :BSTR, :ptr VARIANT
            ;* [defaultvalue][in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechVoiceVtbl ends
          ISpeechVoice struct
            lpVtbl POINTER ?
          ISpeechVoice ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechVoice_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechVoiceStatus_INTERFACE_DEFINED__
        __ISpeechVoiceStatus_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechVoiceStatus *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechVoiceStatus:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechVoiceStatusVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechVoiceStatusVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechVoiceStatus, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechVoiceStatus
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechVoiceStatus
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechVoiceStatus, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechVoiceStatus, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechVoiceStatus, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechVoiceStatus, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_CurrentStreamNumber)
            ;* [id][helpstring][propget] *
            STD_METHOD get_CurrentStreamNumber, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_LastStreamNumberQueued)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LastStreamNumberQueued, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_LastHResult)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LastHResult, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_RunningState)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RunningState, :ptr ISpeechVoiceStatus, :ptr SpeechRunState
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_InputWordPosition)
            ;* [id][helpstring][propget] *
            STD_METHOD get_InputWordPosition, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_InputWordLength)
            ;* [id][helpstring][propget] *
            STD_METHOD get_InputWordLength, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_InputSentencePosition)
            ;* [id][helpstring][propget] *
            STD_METHOD get_InputSentencePosition, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_InputSentenceLength)
            ;* [id][helpstring][propget] *
            STD_METHOD get_InputSentenceLength, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_LastBookmark)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LastBookmark, :ptr ISpeechVoiceStatus, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_LastBookmarkId)
            ;* [hidden][id][helpstring][propget] *
            STD_METHOD get_LastBookmarkId, :ptr ISpeechVoiceStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_PhonemeId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_PhonemeId, :ptr ISpeechVoiceStatus, :ptr SWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechVoiceStatus, get_VisemeId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_VisemeId, :ptr ISpeechVoiceStatus, :ptr SWORD
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechVoiceStatusVtbl ends
          ISpeechVoiceStatus struct
            lpVtbl POINTER ?
          ISpeechVoiceStatus ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechVoiceStatus_INTERFACE_DEFINED__ *
      endif
      ifndef ___ISpeechVoiceEvents_DISPINTERFACE_DEFINED__
        ___ISpeechVoiceEvents_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface _ISpeechVoiceEvents *
        ;* [uuid] *
        externdef DIID__ISpeechVoiceEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          _ISpeechVoiceEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <_ISpeechVoiceEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr _ISpeechVoiceEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr _ISpeechVoiceEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr _ISpeechVoiceEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr _ISpeechVoiceEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr _ISpeechVoiceEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr _ISpeechVoiceEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr _ISpeechVoiceEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          _ISpeechVoiceEventsVtbl ends
          _ISpeechVoiceEvents struct
            lpVtbl POINTER ?
          _ISpeechVoiceEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* ___ISpeechVoiceEvents_DISPINTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechRecognizer_INTERFACE_DEFINED__
        __ISpeechRecognizer_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechRecognizer *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechRecognizer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechRecognizerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechRecognizerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechRecognizer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechRecognizer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechRecognizer
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechRecognizer, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechRecognizer, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechRecognizer, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechRecognizer, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechRecognizer, putref_Recognizer)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Recognizer, :ptr ISpeechRecognizer, :ptr ISpeechObjectToken
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_Recognizer)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Recognizer, :ptr ISpeechRecognizer, :ptr ptr ISpeechObjectToken
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, put_AllowAudioInputFormatChangesOnNextSet)
            ;* [id][helpstring][hidden][propput] *
            STD_METHOD put_AllowAudioInputFormatChangesOnNextSet, :ptr ISpeechRecognizer, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_AllowAudioInputFormatChangesOnNextSet)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_AllowAudioInputFormatChangesOnNextSet, :ptr ISpeechRecognizer, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, putref_AudioInput)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_AudioInput, :ptr ISpeechRecognizer, :ptr ISpeechObjectToken
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_AudioInput)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioInput, :ptr ISpeechRecognizer, :ptr ptr ISpeechObjectToken
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, putref_AudioInputStream)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_AudioInputStream, :ptr ISpeechRecognizer, :ptr ISpeechBaseStream
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_AudioInputStream)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioInputStream, :ptr ISpeechRecognizer, :ptr ptr ISpeechBaseStream
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_IsShared)
            ;* [id][helpstring][propget] *
            STD_METHOD get_IsShared, :ptr ISpeechRecognizer, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, put_State)
            ;* [id][helpstring][propput] *
            STD_METHOD put_State, :ptr ISpeechRecognizer, :SpeechRecognizerState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_State)
            ;* [id][helpstring][propget] *
            STD_METHOD get_State, :ptr ISpeechRecognizer, :ptr SpeechRecognizerState
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_Status)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Status, :ptr ISpeechRecognizer, :ptr ptr ISpeechRecognizerStatus
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, putref_Profile)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Profile, :ptr ISpeechRecognizer, :ptr ISpeechObjectToken
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, get_Profile)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Profile, :ptr ISpeechRecognizer, :ptr ptr ISpeechObjectToken
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, EmulateRecognition)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD EmulateRecognition, :ptr ISpeechRecognizer, :VARIANT, :ptr VARIANT, :SDWORD
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, CreateRecoContext)
            ;* [id][helpstring] *
            STD_METHOD CreateRecoContext, :ptr ISpeechRecognizer, :ptr ptr ISpeechRecoContext
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, GetFormat)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD GetFormat, :ptr ISpeechRecognizer, :SpeechFormatType, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, SetPropertyNumber)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SetPropertyNumber, :ptr ISpeechRecognizer, :BSTR, :SDWORD, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, GetPropertyNumber)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [out][in] *
            STD_METHOD GetPropertyNumber, :ptr ISpeechRecognizer, :BSTR, :ptr SDWORD, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, SetPropertyString)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SetPropertyString, :ptr ISpeechRecognizer, :BSTR, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, GetPropertyString)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [out][in] *
            STD_METHOD GetPropertyString, :ptr ISpeechRecognizer, :BSTR, :ptr BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, IsUISupported)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD IsUISupported, :ptr ISpeechRecognizer, :BSTR, :ptr VARIANT, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, DisplayUI)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD DisplayUI, :ptr ISpeechRecognizer, :SDWORD, :BSTR, :BSTR, :ptr VARIANT
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, GetRecognizers)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetRecognizers, :ptr ISpeechRecognizer, :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, GetAudioInputs)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetAudioInputs, :ptr ISpeechRecognizer, :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizer, GetProfiles)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetProfiles, :ptr ISpeechRecognizer, :BSTR, :BSTR, :ptr ptr ISpeechObjectTokens
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechRecognizerVtbl ends
          ISpeechRecognizer struct
            lpVtbl POINTER ?
          ISpeechRecognizer ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechRecognizer_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechRecognizerStatus_INTERFACE_DEFINED__
        __ISpeechRecognizerStatus_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechRecognizerStatus *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechRecognizerStatus:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechRecognizerStatusVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechRecognizerStatusVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechRecognizerStatus, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechRecognizerStatus
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechRecognizerStatus
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechRecognizerStatus, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechRecognizerStatus, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechRecognizerStatus, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechRecognizerStatus, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechRecognizerStatus, get_AudioStatus)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioStatus, :ptr ISpeechRecognizerStatus, :ptr ptr ISpeechAudioStatus
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizerStatus, get_CurrentStreamPosition)
            ;* [id][helpstring][propget] *
            STD_METHOD get_CurrentStreamPosition, :ptr ISpeechRecognizerStatus, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizerStatus, get_CurrentStreamNumber)
            ;* [id][helpstring][propget] *
            STD_METHOD get_CurrentStreamNumber, :ptr ISpeechRecognizerStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizerStatus, get_NumberOfActiveRules)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NumberOfActiveRules, :ptr ISpeechRecognizerStatus, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizerStatus, get_ClsidEngine)
            ;* [id][helpstring][propget] *
            STD_METHOD get_ClsidEngine, :ptr ISpeechRecognizerStatus, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecognizerStatus, get_SupportedLanguages)
            ;* [id][helpstring][propget] *
            STD_METHOD get_SupportedLanguages, :ptr ISpeechRecognizerStatus, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechRecognizerStatusVtbl ends
          ISpeechRecognizerStatus struct
            lpVtbl POINTER ?
          ISpeechRecognizerStatus ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechRecognizerStatus_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechRecoContext_INTERFACE_DEFINED__
        __ISpeechRecoContext_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechRecoContext *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechRecoContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechRecoContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechRecoContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechRecoContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechRecoContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechRecoContext
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechRecoContext, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechRecoContext, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechRecoContext, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechRecoContext, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_Recognizer)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Recognizer, :ptr ISpeechRecoContext, :ptr ptr ISpeechRecognizer
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_AudioInputInterferenceStatus)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioInputInterferenceStatus, :ptr ISpeechRecoContext, :ptr SpeechInterference
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_RequestedUIType)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RequestedUIType, :ptr ISpeechRecoContext, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, putref_Voice)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_Voice, :ptr ISpeechRecoContext, :ptr ISpeechVoice
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_Voice)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Voice, :ptr ISpeechRecoContext, :ptr ptr ISpeechVoice
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, put_AllowVoiceFormatMatchingOnNextSet)
            ;* [id][helpstring][hidden][propput] *
            STD_METHOD put_AllowVoiceFormatMatchingOnNextSet, :ptr ISpeechRecoContext, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_AllowVoiceFormatMatchingOnNextSet)
            ;* [id][helpstring][hidden][propget] *
            STD_METHOD get_AllowVoiceFormatMatchingOnNextSet, :ptr ISpeechRecoContext, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, put_VoicePurgeEvent)
            ;* [id][helpstring][propput] *
            STD_METHOD put_VoicePurgeEvent, :ptr ISpeechRecoContext, :SpeechRecoEvents
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_VoicePurgeEvent)
            ;* [id][helpstring][propget] *
            STD_METHOD get_VoicePurgeEvent, :ptr ISpeechRecoContext, :ptr SpeechRecoEvents
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, put_EventInterests)
            ;* [id][helpstring][propput] *
            STD_METHOD put_EventInterests, :ptr ISpeechRecoContext, :SpeechRecoEvents
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_EventInterests)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EventInterests, :ptr ISpeechRecoContext, :ptr SpeechRecoEvents
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, put_CmdMaxAlternates)
            ;* [id][helpstring][propput] *
            STD_METHOD put_CmdMaxAlternates, :ptr ISpeechRecoContext, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_CmdMaxAlternates)
            ;* [id][helpstring][propget] *
            STD_METHOD get_CmdMaxAlternates, :ptr ISpeechRecoContext, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, put_State)
            ;* [id][helpstring][propput] *
            STD_METHOD put_State, :ptr ISpeechRecoContext, :SpeechRecoContextState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_State)
            ;* [id][helpstring][propget] *
            STD_METHOD get_State, :ptr ISpeechRecoContext, :ptr SpeechRecoContextState
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, put_RetainedAudio)
            ;* [id][helpstring][propput] *
            STD_METHOD put_RetainedAudio, :ptr ISpeechRecoContext, :SpeechRetainedAudioOptions
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_RetainedAudio)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RetainedAudio, :ptr ISpeechRecoContext, :ptr SpeechRetainedAudioOptions
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, putref_RetainedAudioFormat)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_RetainedAudioFormat, :ptr ISpeechRecoContext, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, get_RetainedAudioFormat)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RetainedAudioFormat, :ptr ISpeechRecoContext, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, Pause)
            ;* [id][helpstring] *
            STD_METHOD Pause, :ptr ISpeechRecoContext
            DECLSPEC_XFGVIRT(ISpeechRecoContext, Resume)
            ;* [id][helpstring] *
            STD_METHOD Resume, :ptr ISpeechRecoContext
            DECLSPEC_XFGVIRT(ISpeechRecoContext, CreateGrammar)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            STD_METHOD CreateGrammar, :ptr ISpeechRecoContext, :VARIANT, :ptr ptr ISpeechRecoGrammar
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, CreateResultFromMemory)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD CreateResultFromMemory, :ptr ISpeechRecoContext, :ptr VARIANT, :ptr ptr ISpeechRecoResult
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, Bookmark)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD Bookmark, :ptr ISpeechRecoContext, :SpeechBookmarkOptions, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoContext, SetAdaptationData)
            ;* [id][helpstring] *
            STD_METHOD SetAdaptationData, :ptr ISpeechRecoContext, :BSTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechRecoContextVtbl ends
          ISpeechRecoContext struct
            lpVtbl POINTER ?
          ISpeechRecoContext ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechRecoContext_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechRecoGrammar_INTERFACE_DEFINED__
        __ISpeechRecoGrammar_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechRecoGrammar *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechRecoGrammar:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechRecoGrammarVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechRecoGrammarVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechRecoGrammar, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechRecoGrammar
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechRecoGrammar
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechRecoGrammar, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechRecoGrammar, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechRecoGrammar, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechRecoGrammar, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, get_Id)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Id, :ptr ISpeechRecoGrammar, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, get_RecoContext)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RecoContext, :ptr ISpeechRecoGrammar, :ptr ptr ISpeechRecoContext
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, put_State)
            ;* [id][helpstring][propput] *
            STD_METHOD put_State, :ptr ISpeechRecoGrammar, :SpeechGrammarState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, get_State)
            ;* [id][helpstring][propget] *
            STD_METHOD get_State, :ptr ISpeechRecoGrammar, :ptr SpeechGrammarState
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, get_Rules)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Rules, :ptr ISpeechRecoGrammar, :ptr ptr ISpeechGrammarRules
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, Reset)
            ;* [id][helpstring] *
            STD_METHOD Reset, :ptr ISpeechRecoGrammar, :SpeechLanguageId
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdLoadFromFile)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD CmdLoadFromFile, :ptr ISpeechRecoGrammar, :BSTR, :SpeechLoadOption
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdLoadFromObject)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CmdLoadFromObject, :ptr ISpeechRecoGrammar, :BSTR, :BSTR, :SpeechLoadOption
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdLoadFromResource)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CmdLoadFromResource, :ptr ISpeechRecoGrammar, :SDWORD, :VARIANT, :VARIANT, :SpeechLanguageId, :SpeechLoadOption
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdLoadFromMemory)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD CmdLoadFromMemory, :ptr ISpeechRecoGrammar, :VARIANT, :SpeechLoadOption
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdLoadFromProprietaryGrammar)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CmdLoadFromProprietaryGrammar, :ptr ISpeechRecoGrammar, :BSTR, :BSTR, :VARIANT, :SpeechLoadOption
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdSetRuleState)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD CmdSetRuleState, :ptr ISpeechRecoGrammar, :BSTR, :SpeechRuleState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, CmdSetRuleIdState)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD CmdSetRuleIdState, :ptr ISpeechRecoGrammar, :SDWORD, :SpeechRuleState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, DictationLoad)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            STD_METHOD DictationLoad, :ptr ISpeechRecoGrammar, :BSTR, :SpeechLoadOption
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, DictationUnload)
            ;* [id][helpstring] *
            STD_METHOD DictationUnload, :ptr ISpeechRecoGrammar
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, DictationSetState)
            ;* [id][helpstring] *
            STD_METHOD DictationSetState, :ptr ISpeechRecoGrammar, :SpeechRuleState
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, SetWordSequenceData)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SetWordSequenceData, :ptr ISpeechRecoGrammar, :BSTR, :SDWORD, :ptr ISpeechTextSelectionInformation
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, SetTextSelection)
            ;* [id][helpstring] *
            STD_METHOD SetTextSelection, :ptr ISpeechRecoGrammar, :ptr ISpeechTextSelectionInformation
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoGrammar, IsPronounceable)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD IsPronounceable, :ptr ISpeechRecoGrammar, :BSTR, :ptr SpeechWordPronounceable
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechRecoGrammarVtbl ends
          ISpeechRecoGrammar struct
            lpVtbl POINTER ?
          ISpeechRecoGrammar ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechRecoGrammar_INTERFACE_DEFINED__ *
      endif
      ifndef ___ISpeechRecoContextEvents_DISPINTERFACE_DEFINED__
        ___ISpeechRecoContextEvents_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface _ISpeechRecoContextEvents *
        ;* [uuid] *
        externdef DIID__ISpeechRecoContextEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          _ISpeechRecoContextEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <_ISpeechRecoContextEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr _ISpeechRecoContextEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr _ISpeechRecoContextEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr _ISpeechRecoContextEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr _ISpeechRecoContextEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr _ISpeechRecoContextEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr _ISpeechRecoContextEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr _ISpeechRecoContextEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          _ISpeechRecoContextEventsVtbl ends
          _ISpeechRecoContextEvents struct
            lpVtbl POINTER ?
          _ISpeechRecoContextEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* ___ISpeechRecoContextEvents_DISPINTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechGrammarRule_INTERFACE_DEFINED__
        __ISpeechGrammarRule_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechGrammarRule *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechGrammarRule:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechGrammarRuleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechGrammarRuleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechGrammarRule, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechGrammarRule
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechGrammarRule
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechGrammarRule, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechGrammarRule, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechGrammarRule, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechGrammarRule, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, get_Attributes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Attributes, :ptr ISpeechGrammarRule, :ptr SpeechRuleAttributes
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, get_InitialState)
            ;* [id][helpstring][propget] *
            STD_METHOD get_InitialState, :ptr ISpeechGrammarRule, :ptr ptr ISpeechGrammarRuleState
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, get_Name)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Name, :ptr ISpeechGrammarRule, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, get_Id)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Id, :ptr ISpeechGrammarRule, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, Clear)
            ;* [id][helpstring] *
            STD_METHOD Clear, :ptr ISpeechGrammarRule
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, AddResource)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD AddResource, :ptr ISpeechGrammarRule, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRule, AddState)
            ;* [id][helpstring] *
            STD_METHOD AddState, :ptr ISpeechGrammarRule, :ptr ptr ISpeechGrammarRuleState
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechGrammarRuleVtbl ends
          ISpeechGrammarRule struct
            lpVtbl POINTER ?
          ISpeechGrammarRule ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechGrammarRule_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechGrammarRules_INTERFACE_DEFINED__
        __ISpeechGrammarRules_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechGrammarRules *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechGrammarRules:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechGrammarRulesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechGrammarRulesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechGrammarRules, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechGrammarRules
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechGrammarRules
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechGrammarRules, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechGrammarRules, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechGrammarRules, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechGrammarRules, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechGrammarRules, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, FindRule)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD FindRule, :ptr ISpeechGrammarRules, :VARIANT, :ptr ptr ISpeechGrammarRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, Item)
            ;* [helpstring][id] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechGrammarRules, :SDWORD, :ptr ptr ISpeechGrammarRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, get__NewEnum)
            ;* [restricted][helpstring][propget][id] *
            STD_METHOD get__NewEnum, :ptr ISpeechGrammarRules, :ptr ptr IUnknown
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, get_Dynamic)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Dynamic, :ptr ISpeechGrammarRules, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, Add)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD Add_, :ptr ISpeechGrammarRules, :BSTR, :SpeechRuleAttributes, :SDWORD, :ptr ptr ISpeechGrammarRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, Commit)
            ;* [id][helpstring] *
            STD_METHOD Commit, :ptr ISpeechGrammarRules
            DECLSPEC_XFGVIRT(ISpeechGrammarRules, CommitAndSave)
            ;* [id][helpstring] *
            ;* [out] *
            STD_METHOD CommitAndSave, :ptr ISpeechGrammarRules, :ptr BSTR, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechGrammarRulesVtbl ends
          ISpeechGrammarRules struct
            lpVtbl POINTER ?
          ISpeechGrammarRules ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechGrammarRules_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechGrammarRuleState_INTERFACE_DEFINED__
        __ISpeechGrammarRuleState_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechGrammarRuleState *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechGrammarRuleState:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechGrammarRuleStateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechGrammarRuleStateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechGrammarRuleState, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechGrammarRuleState
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechGrammarRuleState
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechGrammarRuleState, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechGrammarRuleState, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechGrammarRuleState, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechGrammarRuleState, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleState, get_Rule)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Rule, :ptr ISpeechGrammarRuleState, :ptr ptr ISpeechGrammarRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleState, get_Transitions)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Transitions, :ptr ISpeechGrammarRuleState, :ptr ptr ISpeechGrammarRuleStateTransitions
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleState, AddWordTransition)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD AddWordTransition, :ptr ISpeechGrammarRuleState, :ptr ISpeechGrammarRuleState, :BSTR, :BSTR, :SpeechGrammarWordType, :BSTR, :SDWORD, :ptr VARIANT, :REAL4
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleState, AddRuleTransition)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD AddRuleTransition, :ptr ISpeechGrammarRuleState, :ptr ISpeechGrammarRuleState, :ptr ISpeechGrammarRule, :BSTR, :SDWORD, :ptr VARIANT, :REAL4
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleState, AddSpecialTransition)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD AddSpecialTransition, :ptr ISpeechGrammarRuleState, :ptr ISpeechGrammarRuleState, :SpeechSpecialTransitionType, :BSTR, :SDWORD, :ptr VARIANT, :REAL4
            ;* [defaultvalue][in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechGrammarRuleStateVtbl ends
          ISpeechGrammarRuleState struct
            lpVtbl POINTER ?
          ISpeechGrammarRuleState ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechGrammarRuleState_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__
        __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechGrammarRuleStateTransition *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechGrammarRuleStateTransition:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechGrammarRuleStateTransitionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechGrammarRuleStateTransitionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechGrammarRuleStateTransition, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechGrammarRuleStateTransition
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechGrammarRuleStateTransition
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechGrammarRuleStateTransition, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechGrammarRuleStateTransition, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechGrammarRuleStateTransition, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechGrammarRuleStateTransition, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_Type)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Type, :ptr ISpeechGrammarRuleStateTransition, :ptr SpeechGrammarRuleStateTransitionType
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_Text)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Text, :ptr ISpeechGrammarRuleStateTransition, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_Rule)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Rule, :ptr ISpeechGrammarRuleStateTransition, :ptr ptr ISpeechGrammarRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_Weight)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Weight, :ptr ISpeechGrammarRuleStateTransition, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_PropertyName)
            ;* [id][helpstring][propget] *
            STD_METHOD get_PropertyName, :ptr ISpeechGrammarRuleStateTransition, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_PropertyId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_PropertyId, :ptr ISpeechGrammarRuleStateTransition, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_PropertyValue)
            ;* [id][helpstring][propget] *
            STD_METHOD get_PropertyValue, :ptr ISpeechGrammarRuleStateTransition, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransition, get_NextState)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NextState, :ptr ISpeechGrammarRuleStateTransition, :ptr ptr ISpeechGrammarRuleState
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechGrammarRuleStateTransitionVtbl ends
          ISpeechGrammarRuleStateTransition struct
            lpVtbl POINTER ?
          ISpeechGrammarRuleStateTransition ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__
        __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechGrammarRuleStateTransitions *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechGrammarRuleStateTransitions:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechGrammarRuleStateTransitionsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechGrammarRuleStateTransitionsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechGrammarRuleStateTransitions, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechGrammarRuleStateTransitions
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechGrammarRuleStateTransitions
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechGrammarRuleStateTransitions, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechGrammarRuleStateTransitions, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechGrammarRuleStateTransitions, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechGrammarRuleStateTransitions, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransitions, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechGrammarRuleStateTransitions, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransitions, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechGrammarRuleStateTransitions, :SDWORD, :ptr ptr ISpeechGrammarRuleStateTransition
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechGrammarRuleStateTransitions, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechGrammarRuleStateTransitions, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechGrammarRuleStateTransitionsVtbl ends
          ISpeechGrammarRuleStateTransitions struct
            lpVtbl POINTER ?
          ISpeechGrammarRuleStateTransitions ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechTextSelectionInformation_INTERFACE_DEFINED__
        __ISpeechTextSelectionInformation_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechTextSelectionInformation *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechTextSelectionInformation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechTextSelectionInformationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechTextSelectionInformationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechTextSelectionInformation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechTextSelectionInformation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechTextSelectionInformation
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechTextSelectionInformation, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechTextSelectionInformation, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechTextSelectionInformation, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechTextSelectionInformation, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, put_ActiveOffset)
            ;* [id][helpstring][propput] *
            STD_METHOD put_ActiveOffset, :ptr ISpeechTextSelectionInformation, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, get_ActiveOffset)
            ;* [id][helpstring][propget] *
            STD_METHOD get_ActiveOffset, :ptr ISpeechTextSelectionInformation, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, put_ActiveLength)
            ;* [id][helpstring][propput] *
            STD_METHOD put_ActiveLength, :ptr ISpeechTextSelectionInformation, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, get_ActiveLength)
            ;* [id][helpstring][propget] *
            STD_METHOD get_ActiveLength, :ptr ISpeechTextSelectionInformation, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, put_SelectionOffset)
            ;* [id][helpstring][propput] *
            STD_METHOD put_SelectionOffset, :ptr ISpeechTextSelectionInformation, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, get_SelectionOffset)
            ;* [id][helpstring][propget] *
            STD_METHOD get_SelectionOffset, :ptr ISpeechTextSelectionInformation, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, put_SelectionLength)
            ;* [id][helpstring][propput] *
            STD_METHOD put_SelectionLength, :ptr ISpeechTextSelectionInformation, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechTextSelectionInformation, get_SelectionLength)
            ;* [id][helpstring][propget] *
            STD_METHOD get_SelectionLength, :ptr ISpeechTextSelectionInformation, :ptr SDWORD
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechTextSelectionInformationVtbl ends
          ISpeechTextSelectionInformation struct
            lpVtbl POINTER ?
          ISpeechTextSelectionInformation ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechTextSelectionInformation_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechRecoResult_INTERFACE_DEFINED__
        __ISpeechRecoResult_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechRecoResult *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechRecoResult:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechRecoResultVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechRecoResultVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechRecoResult, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechRecoResult
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechRecoResult
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechRecoResult, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechRecoResult, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechRecoResult, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechRecoResult, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechRecoResult, get_RecoContext)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RecoContext, :ptr ISpeechRecoResult, :ptr ptr ISpeechRecoContext
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, get_Times)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Times, :ptr ISpeechRecoResult, :ptr ptr ISpeechRecoResultTimes
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, putref_AudioFormat)
            ;* [id][helpstring][propputref] *
            STD_METHOD putref_AudioFormat, :ptr ISpeechRecoResult, :ptr ISpeechAudioFormat
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, get_AudioFormat)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioFormat, :ptr ISpeechRecoResult, :ptr ptr ISpeechAudioFormat
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, get_PhraseInfo)
            ;* [id][helpstring][propget] *
            STD_METHOD get_PhraseInfo, :ptr ISpeechRecoResult, :ptr ptr ISpeechPhraseInfo
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, Alternates)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD Alternates, :ptr ISpeechRecoResult, :SDWORD, :SDWORD, :SDWORD, :ptr ptr ISpeechPhraseAlternates
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, Audio)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD Audio, :ptr ISpeechRecoResult, :SDWORD, :SDWORD, :ptr ptr ISpeechMemoryStream
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, SpeakAudio)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD SpeakAudio, :ptr ISpeechRecoResult, :SDWORD, :SDWORD, :SpeechVoiceSpeakFlags, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, SaveToMemory)
            ;* [id][helpstring] *
            STD_METHOD SaveToMemory, :ptr ISpeechRecoResult, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResult, DiscardResultInfo)
            ;* [id][helpstring] *
            STD_METHOD DiscardResultInfo, :ptr ISpeechRecoResult, :SpeechDiscardType
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechRecoResultVtbl ends
          ISpeechRecoResult struct
            lpVtbl POINTER ?
          ISpeechRecoResult ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechRecoResult_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechRecoResultTimes_INTERFACE_DEFINED__
        __ISpeechRecoResultTimes_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechRecoResultTimes *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechRecoResultTimes:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechRecoResultTimesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechRecoResultTimesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechRecoResultTimes, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechRecoResultTimes
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechRecoResultTimes
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechRecoResultTimes, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechRecoResultTimes, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechRecoResultTimes, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechRecoResultTimes, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechRecoResultTimes, get_StreamTime)
            ;* [id][helpstring][propget] *
            STD_METHOD get_StreamTime, :ptr ISpeechRecoResultTimes, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResultTimes, get_Length)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Length, :ptr ISpeechRecoResultTimes, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResultTimes, get_TickCount)
            ;* [id][helpstring][propget] *
            STD_METHOD get_TickCount, :ptr ISpeechRecoResultTimes, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechRecoResultTimes, get_OffsetFromStart)
            ;* [id][helpstring][propget] *
            STD_METHOD get_OffsetFromStart, :ptr ISpeechRecoResultTimes, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechRecoResultTimesVtbl ends
          ISpeechRecoResultTimes struct
            lpVtbl POINTER ?
          ISpeechRecoResultTimes ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechRecoResultTimes_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseAlternate_INTERFACE_DEFINED__
        __ISpeechPhraseAlternate_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseAlternate *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseAlternate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseAlternateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseAlternateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseAlternate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseAlternate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseAlternate
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseAlternate, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseAlternate, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseAlternate, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseAlternate, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternate, get_RecoResult)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RecoResult, :ptr ISpeechPhraseAlternate, :ptr ptr ISpeechRecoResult
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternate, get_StartElementInResult)
            ;* [id][helpstring][propget] *
            STD_METHOD get_StartElementInResult, :ptr ISpeechPhraseAlternate, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternate, get_NumberOfElementsInResult)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NumberOfElementsInResult, :ptr ISpeechPhraseAlternate, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternate, get_PhraseInfo)
            ;* [id][helpstring][propget] *
            STD_METHOD get_PhraseInfo, :ptr ISpeechPhraseAlternate, :ptr ptr ISpeechPhraseInfo
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternate, Commit)
            ;* [id][helpstring] *
            STD_METHOD Commit, :ptr ISpeechPhraseAlternate
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseAlternateVtbl ends
          ISpeechPhraseAlternate struct
            lpVtbl POINTER ?
          ISpeechPhraseAlternate ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseAlternate_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseAlternates_INTERFACE_DEFINED__
        __ISpeechPhraseAlternates_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseAlternates *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseAlternates:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseAlternatesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseAlternatesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseAlternates, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseAlternates
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseAlternates
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseAlternates, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseAlternates, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseAlternates, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseAlternates, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternates, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechPhraseAlternates, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternates, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechPhraseAlternates, :SDWORD, :ptr ptr ISpeechPhraseAlternate
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseAlternates, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechPhraseAlternates, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseAlternatesVtbl ends
          ISpeechPhraseAlternates struct
            lpVtbl POINTER ?
          ISpeechPhraseAlternates ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseAlternates_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseInfo_INTERFACE_DEFINED__
        __ISpeechPhraseInfo_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseInfo *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseInfo
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseInfo, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseInfo, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseInfo, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseInfo, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_LanguageId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LanguageId, :ptr ISpeechPhraseInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_GrammarId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_GrammarId, :ptr ISpeechPhraseInfo, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_StartTime)
            ;* [id][helpstring][propget] *
            STD_METHOD get_StartTime, :ptr ISpeechPhraseInfo, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_AudioStreamPosition)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioStreamPosition, :ptr ISpeechPhraseInfo, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_AudioSizeBytes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioSizeBytes, :ptr ISpeechPhraseInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_RetainedSizeBytes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RetainedSizeBytes, :ptr ISpeechPhraseInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_AudioSizeTime)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioSizeTime, :ptr ISpeechPhraseInfo, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_Rule)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Rule, :ptr ISpeechPhraseInfo, :ptr ptr ISpeechPhraseRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_Properties)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Properties, :ptr ISpeechPhraseInfo, :ptr ptr ISpeechPhraseProperties
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_Elements)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Elements, :ptr ISpeechPhraseInfo, :ptr ptr ISpeechPhraseElements
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_Replacements)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Replacements, :ptr ISpeechPhraseInfo, :ptr ptr ISpeechPhraseReplacements
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_EngineId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EngineId, :ptr ISpeechPhraseInfo, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, get_EnginePrivateData)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EnginePrivateData, :ptr ISpeechPhraseInfo, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, SaveToMemory)
            ;* [id][helpstring] *
            STD_METHOD SaveToMemory, :ptr ISpeechPhraseInfo, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, GetText)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetText, :ptr ISpeechPhraseInfo, :SDWORD, :SDWORD, :VARIANT_BOOL, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseInfo, GetDisplayAttributes)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetDisplayAttributes, :ptr ISpeechPhraseInfo, :SDWORD, :SDWORD, :VARIANT_BOOL, :ptr SpeechDisplayAttributes
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseInfoVtbl ends
          ISpeechPhraseInfo struct
            lpVtbl POINTER ?
          ISpeechPhraseInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseInfo_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseElement_INTERFACE_DEFINED__
        __ISpeechPhraseElement_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseElement *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseElement:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseElementVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseElementVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseElement, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseElement
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseElement
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseElement, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseElement, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseElement, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseElement, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_AudioTimeOffset)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioTimeOffset, :ptr ISpeechPhraseElement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_AudioSizeTime)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioSizeTime, :ptr ISpeechPhraseElement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_AudioStreamOffset)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioStreamOffset, :ptr ISpeechPhraseElement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_AudioSizeBytes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_AudioSizeBytes, :ptr ISpeechPhraseElement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_RetainedStreamOffset)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RetainedStreamOffset, :ptr ISpeechPhraseElement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_RetainedSizeBytes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RetainedSizeBytes, :ptr ISpeechPhraseElement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_DisplayText)
            ;* [id][helpstring][propget] *
            STD_METHOD get_DisplayText, :ptr ISpeechPhraseElement, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_LexicalForm)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LexicalForm, :ptr ISpeechPhraseElement, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_Pronunciation)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Pronunciation, :ptr ISpeechPhraseElement, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_DisplayAttributes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_DisplayAttributes, :ptr ISpeechPhraseElement, :ptr SpeechDisplayAttributes
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_RequiredConfidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_RequiredConfidence, :ptr ISpeechPhraseElement, :ptr SpeechEngineConfidence
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_ActualConfidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_ActualConfidence, :ptr ISpeechPhraseElement, :ptr SpeechEngineConfidence
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElement, get_EngineConfidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EngineConfidence, :ptr ISpeechPhraseElement, :ptr REAL4
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseElementVtbl ends
          ISpeechPhraseElement struct
            lpVtbl POINTER ?
          ISpeechPhraseElement ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseElement_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseElements_INTERFACE_DEFINED__
        __ISpeechPhraseElements_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseElements *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseElements:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseElementsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseElementsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseElements, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseElements
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseElements
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseElements, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseElements, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseElements, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseElements, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseElements, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechPhraseElements, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElements, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechPhraseElements, :SDWORD, :ptr ptr ISpeechPhraseElement
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseElements, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechPhraseElements, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseElementsVtbl ends
          ISpeechPhraseElements struct
            lpVtbl POINTER ?
          ISpeechPhraseElements ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseElements_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseReplacement_INTERFACE_DEFINED__
        __ISpeechPhraseReplacement_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseReplacement *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseReplacement:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseReplacementVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseReplacementVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseReplacement, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseReplacement
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseReplacement
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseReplacement, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseReplacement, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseReplacement, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseReplacement, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacement, get_DisplayAttributes)
            ;* [id][helpstring][propget] *
            STD_METHOD get_DisplayAttributes, :ptr ISpeechPhraseReplacement, :ptr SpeechDisplayAttributes
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacement, get_Text)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Text, :ptr ISpeechPhraseReplacement, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacement, get_FirstElement)
            ;* [id][helpstring][propget] *
            STD_METHOD get_FirstElement, :ptr ISpeechPhraseReplacement, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacement, get_NumberOfElements)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NumberOfElements, :ptr ISpeechPhraseReplacement, :ptr SDWORD
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseReplacementVtbl ends
          ISpeechPhraseReplacement struct
            lpVtbl POINTER ?
          ISpeechPhraseReplacement ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseReplacement_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseReplacements_INTERFACE_DEFINED__
        __ISpeechPhraseReplacements_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseReplacements *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseReplacements:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseReplacementsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseReplacementsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseReplacements, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseReplacements
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseReplacements
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseReplacements, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseReplacements, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseReplacements, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseReplacements, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacements, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechPhraseReplacements, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacements, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechPhraseReplacements, :SDWORD, :ptr ptr ISpeechPhraseReplacement
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseReplacements, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechPhraseReplacements, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseReplacementsVtbl ends
          ISpeechPhraseReplacements struct
            lpVtbl POINTER ?
          ISpeechPhraseReplacements ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseReplacements_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseProperty_INTERFACE_DEFINED__
        __ISpeechPhraseProperty_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseProperty *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseProperty:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhrasePropertyVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhrasePropertyVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseProperty, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseProperty
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseProperty
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseProperty, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseProperty, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseProperty, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseProperty, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_Name)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Name, :ptr ISpeechPhraseProperty, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_Id)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Id, :ptr ISpeechPhraseProperty, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_Value)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Value, :ptr ISpeechPhraseProperty, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_FirstElement)
            ;* [id][helpstring][propget] *
            STD_METHOD get_FirstElement, :ptr ISpeechPhraseProperty, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_NumberOfElements)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NumberOfElements, :ptr ISpeechPhraseProperty, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_EngineConfidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EngineConfidence, :ptr ISpeechPhraseProperty, :ptr REAL4
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_Confidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Confidence, :ptr ISpeechPhraseProperty, :ptr SpeechEngineConfidence
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_Parent)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Parent, :ptr ISpeechPhraseProperty, :ptr ptr ISpeechPhraseProperty
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperty, get_Children)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Children, :ptr ISpeechPhraseProperty, :ptr ptr ISpeechPhraseProperties
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhrasePropertyVtbl ends
          ISpeechPhraseProperty struct
            lpVtbl POINTER ?
          ISpeechPhraseProperty ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseProperty_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseProperties_INTERFACE_DEFINED__
        __ISpeechPhraseProperties_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseProperties *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseProperties:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhrasePropertiesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhrasePropertiesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseProperties, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseProperties
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseProperties
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseProperties, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseProperties, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseProperties, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseProperties, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseProperties, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechPhraseProperties, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperties, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechPhraseProperties, :SDWORD, :ptr ptr ISpeechPhraseProperty
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseProperties, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechPhraseProperties, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhrasePropertiesVtbl ends
          ISpeechPhraseProperties struct
            lpVtbl POINTER ?
          ISpeechPhraseProperties ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseProperties_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseRule_INTERFACE_DEFINED__
        __ISpeechPhraseRule_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseRule *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseRule:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseRuleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseRuleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseRule, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseRule
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseRule
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseRule, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseRule, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseRule, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseRule, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_Name)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Name, :ptr ISpeechPhraseRule, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_Id)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Id, :ptr ISpeechPhraseRule, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_FirstElement)
            ;* [id][helpstring][propget] *
            STD_METHOD get_FirstElement, :ptr ISpeechPhraseRule, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_NumberOfElements)
            ;* [id][helpstring][propget] *
            STD_METHOD get_NumberOfElements, :ptr ISpeechPhraseRule, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_Parent)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Parent, :ptr ISpeechPhraseRule, :ptr ptr ISpeechPhraseRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_Children)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Children, :ptr ISpeechPhraseRule, :ptr ptr ISpeechPhraseRules
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_Confidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Confidence, :ptr ISpeechPhraseRule, :ptr SpeechEngineConfidence
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRule, get_EngineConfidence)
            ;* [id][helpstring][propget] *
            STD_METHOD get_EngineConfidence, :ptr ISpeechPhraseRule, :ptr REAL4
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseRuleVtbl ends
          ISpeechPhraseRule struct
            lpVtbl POINTER ?
          ISpeechPhraseRule ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseRule_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseRules_INTERFACE_DEFINED__
        __ISpeechPhraseRules_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseRules *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseRules:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseRulesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseRulesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseRules, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseRules
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseRules
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseRules, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseRules, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseRules, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseRules, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseRules, get_Count)
            ;* [id][helpstring][propget] *
            STD_METHOD get_Count, :ptr ISpeechPhraseRules, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRules, Item)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechPhraseRules, :SDWORD, :ptr ptr ISpeechPhraseRule
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhraseRules, get__NewEnum)
            ;* [id][restricted][helpstring][propget] *
            STD_METHOD get__NewEnum, :ptr ISpeechPhraseRules, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseRulesVtbl ends
          ISpeechPhraseRules struct
            lpVtbl POINTER ?
          ISpeechPhraseRules ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseRules_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechLexicon_INTERFACE_DEFINED__
        __ISpeechLexicon_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechLexicon *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechLexicon:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechLexiconVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechLexiconVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechLexicon, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechLexicon
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechLexicon
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechLexicon, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechLexicon, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechLexicon, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechLexicon, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechLexicon, get_GenerationId)
            ;* [hidden][id][helpstring][propget] *
            STD_METHOD get_GenerationId, :ptr ISpeechLexicon, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, GetWords)
            ;* [id][helpstring] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][out] *
            STD_METHOD GetWords, :ptr ISpeechLexicon, :SpeechLexiconType, :ptr SDWORD, :ptr ptr ISpeechLexiconWords
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, AddPronunciation)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD AddPronunciation, :ptr ISpeechLexicon, :BSTR, :SpeechLanguageId, :SpeechPartOfSpeech, :BSTR
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, AddPronunciationByPhoneIds)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD AddPronunciationByPhoneIds, :ptr ISpeechLexicon, :BSTR, :SpeechLanguageId, :SpeechPartOfSpeech, :ptr VARIANT
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, RemovePronunciation)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD RemovePronunciation, :ptr ISpeechLexicon, :BSTR, :SpeechLanguageId, :SpeechPartOfSpeech, :BSTR
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, RemovePronunciationByPhoneIds)
            ;* [id][hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [defaultvalue][in] *
            STD_METHOD RemovePronunciationByPhoneIds, :ptr ISpeechLexicon, :BSTR, :SpeechLanguageId, :SpeechPartOfSpeech, :ptr VARIANT
            ;* [defaultvalue][in] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, GetPronunciations)
            ;* [id][helpstring] *
            ;* [in] *
            ;* [defaultvalue][in] *
            ;* [defaultvalue][in] *
            STD_METHOD GetPronunciations, :ptr ISpeechLexicon, :BSTR, :SpeechLanguageId, :SpeechLexiconType, :ptr ptr ISpeechLexiconPronunciations
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexicon, GetGenerationChange)
            ;* [hidden][id][helpstring] *
            ;* [out][in] *
            STD_METHOD GetGenerationChange, :ptr ISpeechLexicon, :ptr SDWORD, :ptr ptr ISpeechLexiconWords
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechLexiconVtbl ends
          ISpeechLexicon struct
            lpVtbl POINTER ?
          ISpeechLexicon ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechLexicon_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechLexiconWords_INTERFACE_DEFINED__
        __ISpeechLexiconWords_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechLexiconWords *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechLexiconWords:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechLexiconWordsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechLexiconWordsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechLexiconWords, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechLexiconWords
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechLexiconWords
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechLexiconWords, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechLexiconWords, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechLexiconWords, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechLexiconWords, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechLexiconWords, get_Count)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Count, :ptr ISpeechLexiconWords, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconWords, Item)
            ;* [helpstring][id] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechLexiconWords, :SDWORD, :ptr ptr ISpeechLexiconWord
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconWords, get__NewEnum)
            ;* [restricted][helpstring][propget][id] *
            STD_METHOD get__NewEnum, :ptr ISpeechLexiconWords, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechLexiconWordsVtbl ends
          ISpeechLexiconWords struct
            lpVtbl POINTER ?
          ISpeechLexiconWords ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechLexiconWords_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechLexiconWord_INTERFACE_DEFINED__
        __ISpeechLexiconWord_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechLexiconWord *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechLexiconWord:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechLexiconWordVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechLexiconWordVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechLexiconWord, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechLexiconWord
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechLexiconWord
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechLexiconWord, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechLexiconWord, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechLexiconWord, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechLexiconWord, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechLexiconWord, get_LangId)
            ;* [propget][id] *
            STD_METHOD get_LangId, :ptr ISpeechLexiconWord, :ptr SpeechLanguageId
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconWord, get_Type)
            ;* [propget][id] *
            STD_METHOD get_Type, :ptr ISpeechLexiconWord, :ptr SpeechWordType
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconWord, get_Word)
            ;* [propget][id] *
            STD_METHOD get_Word, :ptr ISpeechLexiconWord, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconWord, get_Pronunciations)
            ;* [propget][id] *
            STD_METHOD get_Pronunciations, :ptr ISpeechLexiconWord, :ptr ptr ISpeechLexiconPronunciations
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechLexiconWordVtbl ends
          ISpeechLexiconWord struct
            lpVtbl POINTER ?
          ISpeechLexiconWord ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechLexiconWord_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechLexiconPronunciations_INTERFACE_DEFINED__
        __ISpeechLexiconPronunciations_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechLexiconPronunciations *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechLexiconPronunciations:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechLexiconPronunciationsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechLexiconPronunciationsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechLexiconPronunciations, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechLexiconPronunciations
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechLexiconPronunciations
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechLexiconPronunciations, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechLexiconPronunciations, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechLexiconPronunciations, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechLexiconPronunciations, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciations, get_Count)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Count, :ptr ISpeechLexiconPronunciations, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciations, Item)
            ;* [helpstring][id] *
            ;* [in] *
            STD_METHOD Item, :ptr ISpeechLexiconPronunciations, :SDWORD, :ptr ptr ISpeechLexiconPronunciation
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciations, get__NewEnum)
            ;* [restricted][helpstring][propget][id] *
            STD_METHOD get__NewEnum, :ptr ISpeechLexiconPronunciations, :ptr ptr IUnknown
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechLexiconPronunciationsVtbl ends
          ISpeechLexiconPronunciations struct
            lpVtbl POINTER ?
          ISpeechLexiconPronunciations ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechLexiconPronunciations_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechLexiconPronunciation_INTERFACE_DEFINED__
        __ISpeechLexiconPronunciation_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechLexiconPronunciation *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechLexiconPronunciation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechLexiconPronunciationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechLexiconPronunciationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechLexiconPronunciation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechLexiconPronunciation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechLexiconPronunciation
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechLexiconPronunciation, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechLexiconPronunciation, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechLexiconPronunciation, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechLexiconPronunciation, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciation, get_Type)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Type, :ptr ISpeechLexiconPronunciation, :ptr SpeechLexiconType
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciation, get_LangId)
            ;* [helpstring][propget][id] *
            STD_METHOD get_LangId, :ptr ISpeechLexiconPronunciation, :ptr SpeechLanguageId
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciation, get_PartOfSpeech)
            ;* [helpstring][propget][id] *
            STD_METHOD get_PartOfSpeech, :ptr ISpeechLexiconPronunciation, :ptr SpeechPartOfSpeech
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciation, get_PhoneIds)
            ;* [helpstring][propget][id] *
            STD_METHOD get_PhoneIds, :ptr ISpeechLexiconPronunciation, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechLexiconPronunciation, get_Symbolic)
            ;* [helpstring][propget][id] *
            STD_METHOD get_Symbolic, :ptr ISpeechLexiconPronunciation, :ptr BSTR
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechLexiconPronunciationVtbl ends
          ISpeechLexiconPronunciation struct
            lpVtbl POINTER ?
          ISpeechLexiconPronunciation ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechLexiconPronunciation_INTERFACE_DEFINED__ *
      endif
      ifndef __SpeechStringConstants_MODULE_DEFINED__
        __SpeechStringConstants_MODULE_DEFINED__ equ <>
        ;* module SpeechStringConstants *
        ;* [uuid] *
        ;* __SpeechStringConstants_MODULE_DEFINED__ *
      endif
      ifndef __SpeechConstants_MODULE_DEFINED__
        __SpeechConstants_MODULE_DEFINED__ equ <>
        ;* module SpeechConstants *
        ;* [uuid] *
        ;* __SpeechConstants_MODULE_DEFINED__ *
      endif
      ifndef __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__
        __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhraseInfoBuilder *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhraseInfoBuilder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhraseInfoBuilderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhraseInfoBuilderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhraseInfoBuilder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhraseInfoBuilder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhraseInfoBuilder
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhraseInfoBuilder, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhraseInfoBuilder, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhraseInfoBuilder, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhraseInfoBuilder, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhraseInfoBuilder, RestorePhraseFromMemory)
            ;* [id][helpstring] *
            ;* [in] *
            STD_METHOD RestorePhraseFromMemory, :ptr ISpeechPhraseInfoBuilder, :ptr VARIANT, :ptr ptr ISpeechPhraseInfo
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhraseInfoBuilderVtbl ends
          ISpeechPhraseInfoBuilder struct
            lpVtbl POINTER ?
          ISpeechPhraseInfoBuilder ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__ *
      endif
      ifndef __ISpeechPhoneConverter_INTERFACE_DEFINED__
        __ISpeechPhoneConverter_INTERFACE_DEFINED__ equ <>
        ;* interface ISpeechPhoneConverter *
        ;* [unique][helpstring][dual][uuid][object] *
        externdef IID_ISpeechPhoneConverter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpeechPhoneConverterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpeechPhoneConverterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISpeechPhoneConverter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpeechPhoneConverter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpeechPhoneConverter
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr ISpeechPhoneConverter, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr ISpeechPhoneConverter, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr ISpeechPhoneConverter, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IDispatch, Invoke)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Invoke_, :ptr ISpeechPhoneConverter, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(ISpeechPhoneConverter, get_LanguageId)
            ;* [id][helpstring][propget] *
            STD_METHOD get_LanguageId, :ptr ISpeechPhoneConverter, :ptr SpeechLanguageId
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhoneConverter, put_LanguageId)
            ;* [id][helpstring][propput] *
            STD_METHOD put_LanguageId, :ptr ISpeechPhoneConverter, :SpeechLanguageId
            ;* [in] *
            DECLSPEC_XFGVIRT(ISpeechPhoneConverter, PhoneToId)
            ;* [helpstring][id] *
            ;* [in] *
            STD_METHOD PhoneToId, :ptr ISpeechPhoneConverter, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(ISpeechPhoneConverter, IdToPhone)
            ;* [helpstring][id] *
            ;* [in] *
            STD_METHOD IdToPhone, :ptr ISpeechPhoneConverter, :VARIANT, :ptr BSTR
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          ISpeechPhoneConverterVtbl ends
          ISpeechPhoneConverter struct
            lpVtbl POINTER ?
          ISpeechPhoneConverter ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISpeechPhoneConverter_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_SpNotifyTranslator:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpObjectTokenCategory:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpObjectToken:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpResourceManager:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpStreamFormatConverter:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpMMAudioEnum:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpMMAudioIn:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpMMAudioOut:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpStream:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpVoice:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpSharedRecoContext:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpInprocRecognizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpSharedRecognizer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpLexicon:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpUnCompressedLexicon:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpCompressedLexicon:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpPhoneConverter:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpNullPhoneConverter:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpTextSelectionInformation:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpPhraseInfoBuilder:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpAudioFormat:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpWaveFormatEx:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpInProcRecoContext:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpCustomStream:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpFileStream:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_SpMemoryStream:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ;* __SpeechLib_LIBRARY_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapi51_0000_0032 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_sapi51_0000_0032_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_sapi51_0000_0032_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
